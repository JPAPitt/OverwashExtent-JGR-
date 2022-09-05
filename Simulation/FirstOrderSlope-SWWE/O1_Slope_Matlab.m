
%I verified analytic solutions for flat bed, with both dam break (dry and wet)

% 
% function Fluxes = FluxValues(uE_bc,hE_bc,g)
% 
%     Ajmh(:) = max(0,uE_bc(:) - )
% 
% 
% end
close all;
clear all;

n = 1e3;%1e2;%10e3;
eps = 1e-10;
g= 9.81;
CFL = 0.5;

Xs = -50;
Xe = 50;
dx = (Xe - Xs)/ (n-1);
x = Xs: dx:Xe;

dtmin = dx*1e-4;

Ts = 0;
Te = 10.0;
Time = Ts;

Q = zeros(2,n);

bx = 0.01;
h0 = 1;
h1 = 0;%1e-4;
Q(1,1:round(n/2)) = h0*ones(1,round(n/2));
Q(1,round(n/2)+1:n) = h1*ones(1,n - (round(n/2)));%round(n/2)+1:n;

Q(2,1:round(n/2)) = zeros(1,(n/2));
Q(2,round(n/2)+1:n) = zeros(1,n - (round(n/2)));

QL = Q(:,1) ;
QR = Q(:,end);

% [h2, u2,S2] = DBShock(h1,h0,g);

LW = 3;

figure('DefaultAxesFontSize',18);

while Time  < Te%Ts + 1e-8%Te
    

%     [hT,uT] = DambreakSol(x,Time,g,h0,h1,h2,u2,S2);

    [hT,uT] = DambreakSolDry(x,Time,g,h0,h1);
    
%     subplot(2,1,1)
    hold off
    plot(x,Q(1,:) + bx*x,'-b','LineWidth',LW);
    hold on
    plot(x,hT,'--k','LineWidth',LW);
    plot(x,bx*x,'-g','LineWidth',LW);
    xlabel('x (m)');
    ylabel('z (m)');
    title(['SWWE']);
    axis([Xs Xe -3 3])
    
%     subplot(2,1,2)
%     hold off
%     plot(x,Q(2,:),'-r','LineWidth',LW);
%     hold on
%     plot(x,uT.*hT,'--k','LineWidth',LW);
%     xlabel('x (m)');
%     ylabel('u (m/s)');
%     title(['SWWE']);
%     axis([Xs Xe -3 3])%u2*h2*1.1])
    
%     [nQ,dt] = EvolveOneStep(Q,QL,QR,g,dx,CFL);
    [Q,dt] = EvolveOneStep(Q,QL,QR,bx,g,dx,CFL,dtmin);
    
    

 
    
    pause(0.01)
    
    Time = Time + dt;
    
    
end

function [h2, u2,S2] = DBShock(h1,h0,g)

    h2Func = @(x) x - h0/2*(sqrt(1 + 8*(((2*x)/(x-h0))*(sqrt(g*h1) - sqrt(g*x))/sqrt(g*h0))^2 )  -1);

    h2 = fzero(h2Func,0.5*(h1+h0));
    u2 = 2*(sqrt(g*h0) - sqrt(g*h2));
    S2 = 2*h2/(h2- h1)*(sqrt(g*h0) - sqrt(g*h2));

end

function [hT,uT] = DambreakSol(x,t,g,h0,h1,h2,u2,S2)

    hT = zeros(size(x));
    uT = zeros(size(x));
    
    for i = 1:length(x)
        if (x(i) < -t*sqrt(g*h0))
            hT(i) = h0;
            uT(i) = 0;
        elseif and(-t*sqrt(g*h0) <= x(i), x(i) < t*(u2 - sqrt(g*h2)))
            hT(i) = 4/(9*g)*(sqrt(g*h0) - x(i)/(2*t))^2;
            uT(i) = 2/3*(sqrt(g*h0) + x(i)/(t));
          
        elseif and(t*(u2 - sqrt(g*h2)) <= x(i), x(i) < t*S2)
            hT(i) = h2;
            uT(i) = u2;           
        else
            hT(i) = h1;
            uT(i) = 0;
        end
    end


end

function [hT,uT] = DambreakSolDry(x,t,g,h0,h1)

    hT = zeros(size(x));
    uT = zeros(size(x));
    
    for i = 1:length(x)
        if (x(i) < -t*sqrt(g*h0))
            hT(i) = h0;
            uT(i) = 0;
        elseif and(-t*sqrt(g*h0) <= x(i), x(i) < 2*t*sqrt(g*h0))
            hT(i) = 4/(9*g)*(sqrt(g*h0) - x(i)/(2*t))^2;
            uT(i) = 2/3*(sqrt(g*h0) + x(i)/(t));       
        else
            hT(i) = h1;
            uT(i) = 0;
        end
    end


end


%Evolve Step
function [nQ,dt] = EvolveOneStep(Q,QL,QR,bx,g,dx,CFL,dtmin)

    %Calculate fluxes
    [QFluxO,QFluxI, MaxA] = FluxCalc(Q,QL,QR,g);
    
    %Body source term - gh_ibx
    QSource = zeros(size(Q));
    QSource(2,:) = -g*bx*Q(1,:);
    
    
    %evolve dt
    dt = dx*(CFL/MaxA );
    dt = max(dt,dtmin);
    
    %time step
    nQ =  Q - dt/dx*(QFluxO - QFluxI) + dt*QSource;
end


%Flux calculation
function [QFluxO,QFluxI, MaxA] = FluxCalc(Q,QL,QR,g)

n1 = size(Q,1);
n2 = size(Q,2);

REQ_bc = ReconstructO1(Q,QL,QR);

%u recontruction - modified to allow dry beds
uEQ_bc = (REQ_bc(2,:).*REQ_bc(1,:)) ./ (REQ_bc(1,:).^2 + eps) ;

%Naive flux
FluxHjm_bc =  REQ_bc(2,:);
FluxUHjm_bc =  uEQ_bc(1,:).*REQ_bc(2,:) + g/2.*(REQ_bc(1,:)).^2;

%Riemann charachteristics
Ajhm_bc = min(0,min(uEQ_bc(1,1:2:2*(n2+ 1)) - sqrt(g*REQ_bc(1,1:2:2*(n2+ 1))), uEQ_bc(1,2:2:2*(n2+ 1)) - sqrt(g*REQ_bc(1,2:2:2*(n2+ 1)))));
Ajhp_bc = max(0,max(uEQ_bc(1,1:2:2*(n2+ 1)) + sqrt(g*REQ_bc(1,1:2:2*(n2+ 1))), uEQ_bc(1,2:2:2*(n2+ 1)) + sqrt(g*REQ_bc(1,2:2:2*(n2+ 1)))));

% dt = CFL * dx / ( max(max(abs(Ajhm_bc )),max(abs(Ajhp_bc ))));
MaxA = ( max(max(abs(Ajhm_bc )),max(abs(Ajhp_bc ))));

%Kurganov Flux

%Coefficient
FluxCoeff = 1./(Ajhp_bc(1,:) - Ajhm_bc(1,:));
FluxCoeff(isinf(FluxCoeff)) = 0;

%Fluxes h, uh
FluxH = (Ajhp_bc(1,:).*FluxHjm_bc(1:2:2*(n2+ 1)) - Ajhm_bc(1,:).*FluxHjm_bc(2:2:2*(n2+ 1))) + Ajhp_bc(1,:).*Ajhm_bc(1,:).*(REQ_bc(1,2:2:2*(n2+ 1)) - REQ_bc(1,1:2:2*(n2+ 1)));
FluxH = FluxCoeff.*FluxH;

FluxUH = Ajhp_bc(1,:).*FluxUHjm_bc(1:2:2*(n2+ 1)) - Ajhm_bc(1,:).*FluxUHjm_bc(2:2:2*(n2+ 1)) + Ajhp_bc(1,:).*Ajhm_bc(1,:).*(REQ_bc(2,2:2:2*(n2+ 1)) - REQ_bc(2,1:2:2*(n2+ 1)));
FluxUH = FluxCoeff.*FluxUH;

%Flux in and out
QFluxI = [FluxH(1:end-1);FluxUH(1:end-1)];
QFluxO = [FluxH(2:end);FluxUH(2:end)];

end


%Reconstruct first order
function RE_bc = ReconstructO1(Q,QL,QR)

n1 = size(Q,1);
n2 = size(Q,2);

RE_bc = zeros(n1,2*(n2+1));
% 
RE_bc(:,1) = QL;
RE_bc(:,2:2:2*n2) =  Q(:,1:n2);
RE_bc(:,2+1:2:2*n2+1) =  Q(:,1:n2);
RE_bc(:,2*(n2+1)) = QR;

end