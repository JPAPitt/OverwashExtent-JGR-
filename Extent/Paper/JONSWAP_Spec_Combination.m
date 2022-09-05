

%Do this way, for validation AND comparison to Gaussian wave exceedance
%probabilities, assuming Gaussian distro. 
close all;
clear all;

FFsSmooth = linspace(1e-3,10,1e4);
WSSmooth = 2*pi*FFsSmooth;

df = 0.05;
FFs = df:df:8;
WS = 2*pi*FFs;

PlotIndex = [15:5:35];

% FFs = linspace(1e-3,10,1e4);
% WS = 2*pi*FFs;

TpS = 1./FFs;

TpTarg = 0.8;
HsTarg = 0.02;

JSpecSmooth = jonswapIEE(FFsSmooth,TpTarg,HsTarg);
JSpec = jonswapIEE(FFs,TpTarg,HsTarg);

m0 = trapz(FFs,JSpec);
Hsc = 4*sqrt(m0);

figure('DefaultAxesFontSize',18);
hold on;
plot(WSSmooth,JSpecSmooth,'-b');
plot(WS,JSpec,'.b');
plot(WS(PlotIndex),JSpec(PlotIndex),'.r');
plot([2*pi/TpTarg,2*pi/TpTarg],[0,7e-5],'--k')
text(14,6e-5,'Hs = 0.02[m]')
text(14,5.5e-5,'\tau_p = 0.8[s]')
xlim([4,16])
ylim([0,7e-5])
xlabel('\omega [s^-1]')
ylabel('S(\omega) [m^2 s]')
matlab2tikz('Spec_Exp_Spec.tex'); 

%Get components
Aspec = sqrt(2*JSpec*df);
Phi = 2*pi*rand(size(JSpec));

Time = 0:0.01:20;

WaveComps = zeros(size(Aspec,2),size(Time,2));
% WaveComps = Aspec.*exp(1i*WS*Time + Phi);

for i = 1:size(WaveComps,1)
    WaveComps(i,:) =  Aspec(i).*exp(1i*(WS(i)*Time + Phi(i)));
end

n =length(PlotIndex) ;
figure('DefaultAxesFontSize',18);
for i = 1 : n
    subplot(n,1,i);
    plot(Time,real(WaveComps(PlotIndex(i),:)),'-b');
    xlim([0,20])
    ylim([-0.003,0.003])
    xlabel('t [s]')
    ylabel('A_n exp(i (w_n t + phi))')
end
matlab2tikz('Spec_Exp_Comp.tex'); 


figure('DefaultAxesFontSize',18);
hold on;
plot(Time,real(sum(WaveComps,1)),'-b');
plot([0,20],[-HsTarg/2,-HsTarg/2],'--k')
plot([0,20],[HsTarg/2,HsTarg/2],'--k')
xlim([0,20])
ylim([-0.015,0.015])
xlabel('t [s]')
ylabel('\eta ')
matlab2tikz('Spec_Exp_All.tex'); 
% subplot(1,5,1);
% plot(WSSmooth,JSpecSmooth,'-b');






% matlab2tikz('Jonswap_Spec_1.tex'); 