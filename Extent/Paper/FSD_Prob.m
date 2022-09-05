clear all;
close all;

HeightTol = 0.001;
TolFac = 20;

DiamS = linspace(0.001,100,1e3);


% [Pers,TA,RA,LPE,RPE,FT]= fn_Get_Response_AllDiams(P_Mat,LB_Out,FT_Mat,i1T);

rho = 1e3;
Dmin = 0.1;
gamma1 = 1.15;
gamma2 = 2.5;
Dt = 13.5;


betap1 = 1 ./(Dmin^(-gamma1) - Dt^(-gamma1));
betap2 = 1 ./(Dt^(-gamma2) );    

% % Williams - 2013 split probability

%Create intervals over which to find probability
DiamS_D = (DiamS(2) - DiamS(1))/2;

%ensure both the first and second fits, line up
P1end = betap1 ./ (Dt.^(gamma1 +1)); 
P2beg = betap2 ./ (Dt.^(gamma2 +1));
P0 = P1end/P2beg;

%Exceedance probability for Diams < Dmin, Dmin<Diams< Dt and Diams > Dt
Pp1 = (1)+0*DiamS(DiamS <= Dmin);
Pp2 = (1-P0)*betap1.*(DiamS(and(DiamS > Dmin,DiamS <=Dt)).^(-gamma1));
Pp3 = P0*betap2.*(DiamS(DiamS > Dt).^(-gamma2));

CDF = [Pp1,Pp2,Pp3];


figure('DefaultAxesFontSize',18);
loglog(DiamS,CDF,'-r')
% subplot(iNum,1,i);
hold on;

% xlim([0,100])
% ylim([b,1])
% ylabel('z(m)')
% xlabel('x(m)')
title('Floe Size Distribution')
% matlab2tikz('FSD_Ex.tex'); 



