close all;
clear all;

Tp = 0.95;
Tp = 5;
Amp = 0.1;

th_res=100;
SURGE=0;
terms_grn=100;
extra_pts=[];     
rigid = 4; 
n=100; %number of eigenvalues
Param = ParamDef_Oceanide(rigid); 
Param = ModParam_def(Param,1,n,extra_pts,terms_grn,th_res); 

L = (Param.floe_diam/2);
dxL = L/100;
x_plate = -L:dxL:L;


plateabove=Param.thickness*(1-Param.rho/Param.rho_0);

out = fn_ElasticRaft2d('freq',1/Tp,Param,'disk',SURGE,0,1,1,0,'r',x_plate);
TN = (out(1).value);
RN = (out(2).value);
EtaOut = out(3).value;
k = out(4).value;
% xxOut = out(4).value;
[abs(RN), abs(TN)]

omega = 2*pi/Tp;
ki = k*1i;
I = Amp;
g = Param.g;
leftwave=@(x,t) I*real( (exp(ki*(x +L)) + RN*exp(-ki*(x+L)))*exp(-1i*omega*t));
incwave=@(x,t) I*real( exp(ki*(x+L))*exp(-1i*omega*t));
rightwave=@(x,t)I*real(TN*exp(ki*(x-L))*exp(-1i*omega*t));
Plate=@(j,t) I*real( EtaOut(j)*exp(-1i*omega*t))+plateabove;

leftvel=@(x,t) I*real(g*k/(omega)*( (exp(ki*(x+L)) + RN*exp(-ki*(x+L)))*exp(-1i*omega*t)  )) ;
rightvel=@(x,t) I*real(g*k/(omega)*(TN*exp(ki*(x-L))*exp(-1i*omega*t)));
incvel=@(x,t) I*real(g*k/(omega)*( (exp(ki*(x+L)))*exp(-1i*omega*t) ));



factor = 2;
Lamb = 2*pi/ k;
dt = Tp/100;
dx = Lamb/100;
x_left = -factor*Lamb:dx:-L;
x_right = L:dx:factor*Lamb;
xwhole = [x_left,x_plate,x_right];
time = 0;
finaltime = 10*pi/(omega);
figure('DefaultAxesFontSize',18);
while time<finaltime
    subplot(2,1,1)
    hold off
    plot(xwhole,incwave(xwhole,time),'--k','LineWidth',2)
    hold on
    plot(x_left,leftwave(x_left,time),'-b','LineWidth',2)
%     plot(Surge0(time),0,'xr', 'MarkerSize',13)
%     plot(0,Heave0(time),'ob', 'MarkerSize',13)
%     plot(0,Pitch0(time),'og', 'MarkerSize',13)
    plot(x_plate,Plate(1:length(x_plate),time),'-g','LineWidth',2)
    plot(x_plate,Plate(1:length(x_plate),time) - Param.thickness,'-g','LineWidth',2)
    plot(x_right,rightwave(x_right,time),'-r','LineWidth',2)
    xlabel('x(m)')
    ylabel('z(m)')
    title('Locations')
     axis([5*min(x_plate),5*max(x_plate),-2*I,2*I])
%     pause(0.01)
    
    subplot(2,1,2)
    hold off
    plot(xwhole,incvel(xwhole,time),'--k','LineWidth',2)
    hold on
    plot(x_left,leftvel(x_left,time),'-b','LineWidth',2)
    plot(x_right,rightvel(x_right,time),'-r','LineWidth',2)
    axis([5*min(x_plate),5*max(x_plate),-2*g*k/(omega)*I,2*g*k/(omega)*I])
    xlabel('x(m)')
    ylabel('u(m/s)')
    title('Velocity')
    pause(0.01)

    time = time + dt;
end
