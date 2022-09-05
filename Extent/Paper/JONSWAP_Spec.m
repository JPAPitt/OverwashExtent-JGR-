

%Do this way, for validation AND comparison to Gaussian wave exceedance
%probabilities, assuming Gaussian distro. 
close all;
clear all;
FFs = linspace(1e-3,10,1e4);
TpS = 1./FFs;

TpTarg = 0.8;
HsTarg = 0.02;

JSpec = jonswapIEE(FFs,TpTarg,HsTarg);

m0 = trapz(FFs,JSpec);
Hsc = 4*sqrt(m0);

figure('DefaultAxesFontSize',18);
hold on;
plot(2*pi*FFs,JSpec);
plot([2*pi/TpTarg,2*pi/TpTarg],[0,7e-5],'--k')
text(14,6e-5,'Hs = 0.02[m]')
text(14,5.5e-5,'\tau_p = 0.8[s]')
xlim([4,16])
ylim([0,7e-5])
xlabel('\omega [s^-1]')
ylabel('S(\omega) [m^2 s]')
matlab2tikz('Jonswap_Spec_1.tex'); 


TransCurves = load('./RefTransTables/RefTran_PRSA.mat');
Tp_TA = interp1(TransCurves.Model_Pers,TransCurves.Ta,TpS);

figure('DefaultAxesFontSize',18);
hold on;
plot(2*pi*FFs,abs(Tp_TA).^2.*JSpec);
plot([2*pi/TpTarg,2*pi/TpTarg],[0,7e-5],'--k')
xlim([4,16])
ylim([0,7e-5])
xlabel('\omega [s^-1]')
ylabel('S(\omega) [m^2 s]')
matlab2tikz('Jonswap_Spec_2.tex'); 

figure('DefaultAxesFontSize',18);
hold on;
plot(2*pi*FFs,(abs(Tp_TA).^2).^2.*JSpec);
plot([2*pi/TpTarg,2*pi/TpTarg],[0,7e-5],'--k')
xlim([4,16])
ylim([0,7e-5])
xlabel('\omega [s^-1]')
ylabel('S(\omega) [m^2 s]')
matlab2tikz('Jonswap_Spec_3.tex'); 



% matlab2tikz('Jonswap_Spec_1.tex'); 