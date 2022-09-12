% ------------------------
%      Fig4c
% ------------------------
%
%  Authored by Jordan Pitt 08/09/22
%
%   Plot matrices - T(w,L,d) , R(w,L,d) , \zeta(w,0,L,d), \zeta(w,L,L,d)
% as function of L

close all;
clear all;

%Load in the coefficient matrices
load('../Outputs/Data/CoefficientMatrices/Fig4_Qual/Length_Dep.mat');

Pers = (reshape(P_Mat(1,1,:),1,[]));

TA = (LB_Out{1}(:,1));
RA= (LB_Out{2}(:,1));
k= (LB_Out{3}(:,1));
LPE = (LB_Out{4}(:,1));
RPE = (LB_Out{5}(:,1)); 


FT = FT_Mat(1,1);
FD = FD_Mat;


Omega =2*pi./Pers; 
Omega(1) = 0;
Wavelength = 2*pi ./ k;

Linecols = parula(4);


figure('DefaultAxesFontSize',18);
hold on;

plot(FD,abs(LPE),'-','Color',Linecols(1,:),'DisplayName', 'Left Wave To Edge Coefficient' , 'LineWidth',3 )
plot(FD,abs(RPE),'-','Color',Linecols(2,:),'DisplayName', 'Right Wave To Edge Coefficient' , 'LineWidth',3 )
plot(FD,abs(TA),'-','Color',Linecols(3,:),'DisplayName', 'Transmission Coefficient', 'LineWidth',3  )
plot(FD,abs(RA),'-','Color',Linecols(4,:),'DisplayName', 'Reflection Coefficient', 'LineWidth',3  )


xlabel('Length (m)')
ylabel('Coefficient ')

legend();
cleanfigure;
matlab2tikz('../Outputs/Plots/Fig4c.tex'); 

