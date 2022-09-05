
%I verified analytic solutions for flat bed, with both dam break (dry and wet)

function [nQ,dt,EFlux_Left,EFlux_Right] = O1_Slope_Fast(Q,QL,QR,bx,g,dx,CFL,dtmin,dtmax)

    %Calculate fluxes
    [QFluxO,QFluxI, MaxA,EFlux_Left,EFlux_Right] = FluxCalc(Q,QL,QR,g);
    
    %Body source term - gh_ibx
    QSource = zeros(size(Q));
    QSource(2,:) = -g*bx*Q(1,:);
    
    
    %evolve dt
    
    dt = dx*(CFL/MaxA );
%     if isinf(dt)
%         dt = dtmin;
%     end
    dt = min(max(dt,dtmin),dtmax);
    
    %time step
    nQ =  Q - dt/dx*(QFluxO - QFluxI) + dt*QSource;
    EFlux_Left= dt*EFlux_Left;
    EFlux_Right = dt*EFlux_Right;
    nQ(1,:) = max(nQ(1,:),0);
    nQ(2,nQ(1,:) <= 0) = 0; 
   
    
    
end


%Flux calculation
function [QFluxO,QFluxI, MaxA,EFlux_Left,EFlux_Right] = FluxCalc(Q,QL,QR,g)

% n1 = size(Q,1);
n2 = size(Q,2);

REQ_bc = ReconstructO1(Q,QL,QR);

%u recontruction - modified to allow dry beds
uEQ_bc = (REQ_bc(2,:).*REQ_bc(1,:)) ./ (REQ_bc(1,:).^2 + eps) ;

%Naive flux
FluxHjm_bc =  REQ_bc(2,:);
FluxUHjm_bc =  uEQ_bc(1,:).*REQ_bc(2,:) + g/2.*(REQ_bc(1,:)).^2;

Ejm_Left = 0.5*(uEQ_bc(1,1:2).*REQ_bc(2,1:2) + g.*REQ_bc(1,1:2).^2 );
Ejm_Right = 0.5*(uEQ_bc(1,end-1:end).*REQ_bc(2,end-1:end) + g.*REQ_bc(1,end-1:end).^2 );

FluxEjm_Left = 0.5*(uEQ_bc(1,1:2).^2).*REQ_bc(2,1:2) + g.*REQ_bc(2,1:2).*REQ_bc(1,1:2);
FluxEjm_Right = 0.5*(uEQ_bc(1,end-1:end).^2).*REQ_bc(2,end-1:end) + g.*REQ_bc(2,end-1:end).*REQ_bc(1,end-1:end);

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

EFlux_Left = Ajhp_bc(1).*FluxEjm_Left(1) - Ajhm_bc(1).*FluxEjm_Left(2) + Ajhp_bc(1).*Ajhm_bc(1).*(Ejm_Left(2) - Ejm_Left(1));
EFlux_Left = FluxCoeff(1).*EFlux_Left;



EFlux_Right = Ajhp_bc(end).*FluxEjm_Right(end-1) - Ajhm_bc(end).*FluxEjm_Right(end) + Ajhp_bc(end).*Ajhm_bc(end).*(Ejm_Right(end) - Ejm_Right(end-1));
EFlux_Right = FluxCoeff(end).*EFlux_Right;
% EFlux_Right = 

%Flux in and out
QFluxI = [FluxH(1:end-1);FluxUH(1:end-1)];
QFluxO = [FluxH(2:end);FluxUH(2:end)];

% if ~isreal(QFluxI)
%      x = 1
% end
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