% ------------------------
%      Fig4a
% ------------------------
%
%  Authored by Jordan Pitt 08/09/22
%
%   Plot matrices - T(w,L,d) , R(w,L,d) , \zeta(w,0,L,d), \zeta(w,L,L,d)
% as function of w

close all;
clear all;

%Load in the coefficient matrices
load('../Outputs/Data/CoefficientMatrices/Fig4_Qual/Omega_Dep.mat');

%Height tolerance ensuring overwash is significantly above the plate
HeightTol = 0.001;

Pers = fliplr(reshape(P_Mat(1,1,:),1,[]));

TA = fliplr(reshape(LB_Out{1}(1,1,:),1,size(Pers,2)));
RA= fliplr(reshape(LB_Out{2}(1,1,:),1,size(Pers,2)));
k= fliplr(reshape(LB_Out{3}(1,1,:),1,size(Pers,2)));
LPE = fliplr(reshape(LB_Out{4}(1,1,:),1,size(Pers,2)));
RPE = fliplr(reshape(LB_Out{5}(1,1,:),1,size(Pers,2))); 


FFs = 1./ Pers;
FFs(end) =  2./ (Pers(end-1) + Pers(end)); 

Omega =2*pi./Pers; 
Omega(1) = 0;
Wavelength = 2*pi ./ k;

ShortInd = find(abs(LPE) < 0.99,1,'first');
LongInd = find(abs(LPE) < 0.01,1,'first');

Linecols = parula(4);


figure('DefaultAxesFontSize',18);
hold on;
plot([Omega(ShortInd ),Omega(ShortInd )],[0,3],'--k', 'LineWidth',3,'DisplayName', [num2str(Wavelength(ShortInd )) , 'long wave cut off']  )
plot([Omega(LongInd),Omega(LongInd)],[0,3],'--b', 'LineWidth',3,'DisplayName', [num2str(Wavelength(LongInd )), 'short wave cut off']   )

plot(Omega,abs(LPE),'-','Color',Linecols(1,:),'DisplayName', 'Left Wave To Edge Coefficient' , 'LineWidth',3 )
plot(Omega,abs(RPE),'-','Color',Linecols(2,:),'DisplayName', 'Right Wave To Edge Coefficient' , 'LineWidth',3 )
plot(Omega,abs(TA),'-','Color',Linecols(3,:),'DisplayName', 'Transmission Coefficient', 'LineWidth',3  )
plot(Omega,abs(RA),'-','Color',Linecols(4,:),'DisplayName', 'Reflection Coefficient', 'LineWidth',3  )

xlim([0,8])
ylim([0,3])
xticks([0,2,4,6,8])
yticks([0,0.5,1,1.5,2,2.5,3])
xlabel('omega (s)')
ylabel('Coefficient ')

legend();
cleanfigure;
matlab2tikz('../Outputs/Plots/Fig4a.tex'); 

