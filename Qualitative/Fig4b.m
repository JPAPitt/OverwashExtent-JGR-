% ------------------------
%      Fig4a
% ------------------------
%
%  Authored by Jordan Pitt 08/09/22
%
%   Plot matrices - T(w,L,d) , R(w,L,d) , \zeta(w,0,L,d), \zeta(w,L,L,d)
% as function of d

close all;
clear all;

%Load in the coefficient matrices
load('../Outputs/Data/CoefficientMatrices/Fig4_Qual/Thick_Dep.mat');

Pers = (reshape(P_Mat(1,1,:),1,[]));

TA = (LB_Out{1}(1,:));
RA= (LB_Out{2}(1,:));
k= (LB_Out{3}(1,:));
LPE = (LB_Out{4}(1,:));
RPE = (LB_Out{5}(1,:)); 


FTs = FT_Mat;
FD = FD_Mat(1,1);

Omega =2*pi./Pers; 
Omega(1) = 0;
Wavelength = 2*pi ./ k;


Linecols = parula(4);


figure('DefaultAxesFontSize',18);
hold on;
plot([0.7,0.7],[0,3],'--k', 'LineWidth',3,'DisplayName', "d=0.7"  )

plot(FTs,abs(LPE),'-','Color',Linecols(1,:),'DisplayName', 'Left Wave To Edge Coefficient' , 'LineWidth',3 )
plot(FTs,abs(RPE),'-','Color',Linecols(2,:),'DisplayName', 'Right Wave To Edge Coefficient' , 'LineWidth',3 )
plot(FTs,abs(TA),'-','Color',Linecols(3,:),'DisplayName', 'Transmission Coefficient', 'LineWidth',3  )
plot(FTs,abs(RA),'-','Color',Linecols(4,:),'DisplayName', 'Reflection Coefficient', 'LineWidth',3  )

ylim([0,3])
xlabel('Thickness (m)')
ylabel('Coefficient ')

legend();
cleanfigure;
matlab2tikz('../Outputs/Plots/Fig4b.tex'); 

