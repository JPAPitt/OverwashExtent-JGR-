% ------------------------
%       Figure5_Sim_Overwash
% ------------------------
%
%  Authored by Jordan Pitt 08/09/22
%
% Uses matrices - T(w,L,d) , R(w,L,d) , \zeta(w,0,L,d), \zeta(w,L,L,d)
% to produce a transmission model in an FSD + predict overwash of specific
% floe geometry based on wave properties
%
% The initial spectra is Jonswap - with fixed Hs, Tp
%
% generates overwash simulation for a realisation of the incoming spectra
% this example is overwash occuring

close all;
clear all;

%Load in the coefficient matrices
load('../Outputs/Data/CoefficientMatrices/Fig4_Qual/Omega_Dep.mat');

%Height tolerance ensuring overwash is significantly above the plate
HeightTol = 0.001;

%Draught ratio - Archimedes
DRat = ParamCons.DRat;

%Frequency tolerance on overwash
TolFac = 20;

%The thicknesses and diameters the cofficients are calcluated at
ThickS = reshape(FT_Mat(1,:,1),1,[]);
DiamS = reshape(FD_Mat(:,1,1),1,[]);

%Floe propertys to investigate overwash for - as index - diameter is
%FD_Mat(i1,:), thickness is FT_Mat(i2,:)
i1 = 1;
i2 = 1;

%Load matrices giving coefficients as functions of Diameter and w/T
[Pers,TA,RA,LPE,RPE,FT]= fn_Get_Response_AllDiams(P_Mat,LB_Out,FT_Mat,i2);
FD = DiamS(i1);
FB = DRat*FT;
plateabove = FB;
PlateCond = FB + HeightTol;

TA = TA(i1,:);
RA = RA(i1,:);
LPE = LPE(i1,:);
RPE = RPE(i1,:);

FFs = 1./ Pers;
FFs(end) =  2./ (Pers(end-1) + Pers(end)); 

df = 0.002;
ModelFreq = df:df:1.1;


TNs = interp1(FFs,TA,ModelFreq);
RNs = interp1(FFs,RA,ModelFreq);
Model_LPE = interp1(FFs,LPE,ModelFreq);
Model_RPE = interp1(FFs,RPE,ModelFreq);


kFS = fliplr(reshape(LB_Out{3}(i1,i2,:),1,size(Pers,2)));
ks = interp1(FFs,kFS,ModelFreq);

%incoming spectra
Tp = 10;
Hs = 5;
U10 = 12;
gamma=3.3;
n = -5;
[S_I,Beta,Tp] = fn_gJS(ModelFreq,Hs,Tp,U10,gamma,n);


%Overwash frequency 
M0_Inc =trapz(ModelFreq,S_I );
M2_Inc = trapz(ModelFreq,(ModelFreq.^2) .*S_I );
AvgMeanT_Inc = sqrt(M0_Inc/ M2_Inc);

LE0_Spectrum = (abs(1 + RNs - Model_LPE ).^2).*S_I;

M0_LE =trapz(ModelFreq,LE0_Spectrum);
M2_LE = trapz(ModelFreq,(ModelFreq.^2) .*LE0_Spectrum);

AT_LE = sqrt(M0_LE ./ M2_LE)./ exp(-PlateCond^2 ./ (2.*M0_LE));

RE0_Spectrum = (abs(TNs - Model_RPE ).^2).*S_I;

%zero and second moments for left plate spectra
M0_RE =trapz(ModelFreq,RE0_Spectrum);
M2_RE = trapz(ModelFreq,(ModelFreq.^2) .*RE0_Spectrum);

AT_RE = sqrt(M0_RE ./ M2_RE)./ exp(-PlateCond^2 ./ (2.*M0_RE));

AT_M_List = min(AT_LE,AT_RE);
OR = AT_M_List /AvgMeanT_Inc;

OverwashCond = OR <= TolFac;


%Generate realisation of spectra
S_I_w = S_I / (2*pi) ;

AmpSpec = sqrt(2*S_I_w*(2*pi*df));
Omega_n = 2*pi*ModelFreq;
Phi_n = 2*pi*rand(1,length(ModelFreq));

L = FD /2;
dx=L/50;
x_plate =[-L:dx:L]; 
g = 9.81;

%define the functions from the realisations
leftwave=@(x,t) sum(AmpSpec(:).*real( (exp(1i.*ks(:).*(x +L)) + RNs(:).*exp(-1i.*ks(:).*(x+L))).*exp(-1i.*Omega_n(:).*t + 1i*Phi_n(:))));
rightwave=@(x,t) sum(AmpSpec(:).*real(TNs(:).*exp(1i.*ks(:).*(x-L)).*exp(-1i.*Omega_n(:).*t + 1i*Phi_n(:) )));
PlateLeft =@(t) sum(AmpSpec(:).*real( Model_LPE(:).*exp(-1i.*Omega_n(:).*t + 1i*Phi_n(:))))+plateabove;
PlateRight =@(t) sum(AmpSpec(:).*real( Model_RPE(:).*exp(-1i.*Omega_n(:).*t + 1i*Phi_n(:))))+plateabove;

Plate=@(x,t) x.*(PlateRight(t) - PlateLeft(t))/FD + (PlateLeft(t) + PlateRight(t))/2;

leftvel=@(x,t) sum(AmpSpec(:).*real(g.*ks(:)./(Omega_n(:)).*( (exp(1i.*ks(:).*(x+L)) + RNs(:).*exp(-1i.*ks(:).*(x+L))).*exp(-1i.*Omega_n(:).*t + 1i*Phi_n(:))  ))) ;
rightvel=@(x,t) sum(AmpSpec(:).*real(g.*ks(:)./(Omega_n(:)).*(TNs(:).*exp(1i.*ks(:).*(x-L)).*exp(-1i.*Omega_n(:).*t + 1i*Phi_n(:)))));


%SWWE

%CFL condition
CFL = 0.4;
dt=CFL*dx;

%Start time
time=0;

%min water depth
fakemin=0.00001;

%initial conserved quantities
u=zeros(2,length(x_plate));

%initial conserved quantities
uL = [0;0];
uR = [0;0];

SWWEn = length(x_plate);
dtmin =0.00005;

k = (2*pi / Tp).^2 /9.81;
factor = 2;
Lamb = 2*pi/ k;
dt = Tp/100;

XLeft = max(-1,-Lamb);
XRight = min(1,Lamb);

XBot = -7.5; 
XTop = 7.5;

x_left = fliplr([-L:-dx:XLeft,XLeft]);
x_right = [L:dx:XRight,XRight];
xwhole = [x_left,x_plate,x_right];

dx_O = 0.05;
XLeft_Out = -500;
XRight_Out = 500;
x_left_Out = fliplr([-L:-dx_O:XLeft_Out,XLeft_Out]);
x_right_Out = [L:dx_O:XRight_Out,XRight_Out];
xwhole_Out = [x_left_Out,x_plate,x_right_Out];

time = 0;
finaltime = 100;

% Create & open video writer
vw = VideoWriter('../Outputs/Plots/Simulation/NoOverwash/Animation.avi');
vw.Quality = 100;
vw.FrameRate = 60;
open(vw);

iplot = 1;
plottimes = linspace(time,finaltime,vw.FrameRate*20);
lastt = -10;

%The figures of the time series at left and right edges
figure('DefaultAxesFontSize',18);
hold on;
plot(plottimes,leftwave(-L,plottimes) - (PlateLeft(plottimes) +HeightTol)  ,'-b')
plot([plottimes(1),plottimes(end)],[0,0],'--k')
xlim([0,100]);
xlabel('t [s]')
ylabel('\psi_L [m]')
title('Psi_L and Psi_R')

[val,val_ind] = max(leftwave(-L,plottimes) - (PlateLeft(plottimes) +HeightTol));

plot(plottimes(val_ind),leftwave(-L,plottimes(val_ind)) - (PlateLeft(plottimes(val_ind)) +HeightTol) ,'.r');
cleanfigure;
StrName = ['../Outputs/Plots/Simulation/NoOverwash/LeftTimeSeries.tex'];
matlab2tikz(StrName); 

figure('DefaultAxesFontSize',18);
hold on;
plot(plottimes,rightwave(L,plottimes) - (PlateRight(plottimes) +HeightTol)  ,'-b')
plot([plottimes(1),plottimes(end)],[0,0],'--k')
xlim([0,100]);
xlabel('t [s]')
ylabel('\psi_R [m]')
title('Psi_L and Psi_R')

[val,val_ind] = max(leftwave(-L,plottimes) - (PlateLeft(plottimes) +HeightTol));

plot(plottimes(val_ind),rightwave(L,plottimes(val_ind)) - (PlateRight(plottimes(val_ind)) +HeightTol) ,'.r');
cleanfigure;
StrName = ['../Outputs/Plots/Simulation/NoOverwash/RightTimeSeries.tex'];
matlab2tikz(StrName); 

%run simulation
figure('DefaultAxesFontSize',18);
while time<finaltime
    if time > plottimes(iplot)
        hold off
        xList = [x_left,fliplr(x_left)];
        yList = [leftwave(x_left,time) , XBot*ones(1,length(x_left))];
        fill(xList,yList,'b','EdgeColor','none','FaceAlpha',0.3)
        hold on
        xList = [x_plate,fliplr(x_plate)];
        yList = [Plate(x_plate,time) , fliplr(Plate(x_plate,time) - FT)];
        fill(xList,yList,'c','EdgeColor','none','FaceAlpha',0.3)
        xList = [x_plate,fliplr(x_plate)];
        yList = [Plate(x_plate,time) + u(1,:) , fliplr(Plate(x_plate,time))];
        fill(xList,yList,'b','EdgeColor','none','FaceAlpha',0.3)
        xList = [x_plate,fliplr(x_plate)];
        yList = [Plate(x_plate,time) - FT , XBot*ones(1,length(x_plate))];
        fill(xList,yList,'b','EdgeColor','none','FaceAlpha',0.3)
        xList = [x_right,fliplr(x_right)];
        yList = [rightwave(x_right,time) , XBot*ones(1,length(x_right))];
        fill(xList,yList,'b','EdgeColor','none','FaceAlpha',0.3)

        plot(x_left,leftwave(x_left,time),'-b','LineWidth',3)
        plot(x_plate,Plate(x_plate,time) + u(1,:),'-b','LineWidth',3)
        plot(x_right,rightwave(x_right,time),'-b','LineWidth',3)
        plot(x_plate,Plate(x_plate,time),'-c','LineWidth',3)
        plot(x_plate,Plate(x_plate,time) - FT,'-c','LineWidth',3)
        plot([x_plate(1),x_plate(1)],[Plate(-L,time),Plate(-L,time) - FT],'-c','LineWidth',3)
        plot([x_plate(end),x_plate(end)],[Plate(L,time),Plate(L,time) - FT],'-c','LineWidth',3)

        xlabel('x [m]','Interpreter','latex', 'FontSize', 16)
        ylabel('z [m]','Interpreter','latex', 'FontSize', 16)
        strtitp1 = sprintf('$h=%5.2f[$m$], d=%5.2f[$m$]$', round(FT),round(FD)) ;
        strtitp2 = sprintf('$\\tau_p=%5.2f[$s$] , H_s = %5.2f[$m$]$',Tp,Hs) ;
        strtit = {'Floe Response ',[strtitp1,', ',strtitp2]};
        title(strtit,'Interpreter','latex', 'FontSize', 20)
        str1 = ['t = ', sprintf('%5.2f', time) , ' [s]'];
        text(0.75*XLeft, 0.75*XTop ,str1,'Interpreter','latex', 'FontSize', 16)
        if OverwashCond
           str2 = sprintf('Overwash Predicted $O_r = %3.1f$',OR);
           text(0.3*XLeft, 0.75*XTop ,str2,'Interpreter','latex', 'FontSize', 16)
        else
           str2 = sprintf('Overwash Not Predicted $O_r = %3.1f$',OR);
           text(0.3*XLeft, 0.75*XTop ,str2,'Interpreter','latex', 'FontSize', 16)           
        end
        axis([XLeft,XRight,XBot,XTop])
        
        if (time > plottimes(val_ind) -10 && time < plottimes(val_ind) +10)
            cleanfigure;
            StrName = ['../Outputs/Plots/Simulation/NoOverwash/TimeIndex_',num2str(iplot),'.tex'];
            matlab2tikz(StrName); 
            lastt = time;
            
        end
        
        frame = getframe(gcf);
        writeVideo(vw, frame);

        pause(0.01)
        
        iplot = iplot + 1;
 
    end
    bx = (Plate(L,time) - Plate(-L,time)) / FD;
    [u,dt,ELeft,ERight] = O1_Slope_Fast_mex(u,uL,uR,bx,g,dx,CFL,dtmin,Tp/100);
    

    hL = leftwave( [-L],time) - Plate(-L,time);
    if hL >= 5*fakemin
        uL = [hL;hL*leftvel([-L],time)];

    else
        uL =[0;0];
    end

    hR = rightwave([L],time) - Plate(L,time);
    if hR >= 5*fakemin
        uR = [hR;hR*rightvel([L],time)];

    else
        uR =[0;0];
    end
    


    time = time + dt;
end
close(vw);

