

%Do this way, for validation AND comparison to Gaussian wave exceedance
%probabilities, assuming Gaussian distro. 
close all;
clear all;
FFs = linspace(1e-2,1,1e3);
ws = 2*pi*FFs;
TpS = 1./FFs;


%Mean of both seasons - Youngs
HsTarg = 2;

% JSpec = jonswapIEE(FFs,TpTarg,HsTarg)/ (2*pi);

%Middle between the summer and winter means - Youngs work
U10 = 12;
gamma=3.3;
n = -5;

%demarcation
% InvWaveAge = 0.83;
[gJSpec,Beta,Tp] = fn_gJS(FFs,HsTarg,[],U10,gamma,n);
InvWaveAge = (Beta/  0.006)^(1/0.55);
gJSpec = gJSpec ./  (2*pi);


%Want to show distribution of spectra given FSD
load('../Outputs/Data/CoefficientMatrices/Predictions.mat');
DRat = ParamCons.DRat;
LB_Out = {TA_Mat_All,RA_Mat_All, kS_Mat_All,LPE_Mat_All,RPE_Mat_All};

ThickS = reshape(FT_Mat(1,:,1),1,[]);
DiamS = reshape(FD_Mat(:,1,1),1,[]);



Conc = 0.6;

i1 = 4;
i2 = 1;
Dmin = 0.25;
gamma1 = 1.1;
gamma2 = 9.4;

[Pers,TA,RA,LPE,RPE,FT]= fn_Get_Response_AllDiams(P_Mat,LB_Out,FT_Mat,i2);
FB = DRat*FT;

Dt = 3.15;

[Weights,ExtAvg] = fn_Get_FloeSample_Wght(DiamS,Dmin,Dt,gamma1,gamma2);

XDist = [1e3,1e4];
% XDist = [1e4];

Num = round(XDist *Conc /  ExtAvg);


% 1 - first
SampleNum = 1;
% LongAttn = false;
LongAttn = true;



Trans_Wght_All = zeros(SampleNum , size(Pers,2));
EdgesIndex = [[1:size(Weights,2)]-0.5,size(Weights,2)+ 0.5];
 for i = 1:SampleNum
    FloeSample_Ind = randsample([1:size(Weights,2)],Num(1),true,Weights);
    
    [Counts_Ind,~] = histcounts(FloeSample_Ind,EdgesIndex);
    
    [Trans_Wght]  =  fn_FSD_Transmission_X(Pers,Counts_Ind./Num(1),Conc,ExtAvg,TA,LongAttn);
    
    Trans_Wght_All(i,:) = Trans_Wght(:);
    
    if i == 1
        FloeNumSample  = Counts_Ind;
        FloeSampleTrans = Trans_Wght;
    end
    
 end
 
 sum(FloeNumSample .* DiamS)
 
Mean_Trans = mean(Trans_Wght_All,1);
STD_Trans = std(Trans_Wght_All,1,1);

[Trans_Wght]  = fn_FSD_Transmission_X(Pers,Weights,Conc,ExtAvg,TA,LongAttn);
[Trans_Wght_FSD]  = fn_FSD_Transmission_X(Pers,Weights,Conc,ExtAvg,TA,false);
[Trans_Wght_Disp]  = fn_FSD_Transmission_X(Pers,0*Weights,Conc,ExtAvg,TA,LongAttn);

FloeSampleTrans_1  = interp1(Pers,FloeSampleTrans,1 ./FFs);
Trans_Wght_1 = interp1(Pers,Trans_Wght, 1 ./FFs);
Trans_Wght_FSD_1 = interp1(Pers,Trans_Wght_FSD, 1 ./FFs);
Trans_Wght_Disp_1 = interp1(Pers,Trans_Wght_Disp, 1 ./FFs);


figure('DefaultAxesFontSize',18);
loglog(DiamS,Weights.*XDist(1)*Conc/ExtAvg  ,'--k')
hold on;
loglog(DiamS,FloeNumSample,'.b');
xlim([0.1,1e2])
ylim([1,1e4])
xlabel('Length')
ylabel('Count')
cleanfigure;
matlab2tikz('../Outputs/Plots/Fig6aInset.tex'); 


figure('DefaultAxesFontSize',18);
hold on;

S_I = gJSpec;


plot(2*pi*FFs,(Trans_Wght_1.^XDist(1)).*S_I,'-b');
plot(2*pi*FFs,(Trans_Wght_FSD_1.^XDist(1)).*S_I,'-g');
plot(2*pi*FFs,(Trans_Wght_Disp_1.^XDist(1)).*S_I,'-y');
plot(2*pi*FFs, (FloeSampleTrans_1.^XDist(1)).*S_I,':r')
plot(2*pi*FFs,S_I,'-k');
xlim([0.4,3])
ylim([0,2.5])
xlabel('\omega [s^-1]')
ylabel('S(\omega) [m^2 s]')
title('Spectral Evolution')
cleanfigure;
matlab2tikz('../Outputs/Plots/Fig6a.tex'); 

S_N_1km = (Trans_Wght_1.^XDist(1)).*S_I;
S_N_1km(isnan(S_N_1km)) = 1;
M0_0 = trapz(FFs,2*pi*S_I);
Hs_0 = 4*sqrt(M0_0);
M0_1 = trapz(FFs,2*pi*S_N_1km);
Hs_1 = 4*sqrt(M0_1);


% 
% % 2 - second

SampleNum = 11;
LongAttn = true;

Trans_Wght_All = zeros(SampleNum , size(Pers,2));
EdgesIndex = [[1:size(Weights,2)]-0.5,size(Weights,2)+ 0.5];
 for i = 1:SampleNum
    FloeSample_Ind = randsample([1:size(Weights,2)],Num(2),true,Weights);
    
    [Counts_Ind,~] = histcounts(FloeSample_Ind,EdgesIndex);
    
    [Trans_Wght]  =  fn_FSD_Transmission_X(Pers,Counts_Ind./Num(2),Conc,ExtAvg,TA,LongAttn);
    
    Trans_Wght_All(i,:) = Trans_Wght(:);
    
    if i == 1
        FloeNumSample = Counts_Ind;
        FloeSampleTrans = Trans_Wght;
    end
    
 end
 
 sum(FloeNumSample .* DiamS)
 
Mean_Trans = mean(Trans_Wght_All,1);
STD_Trans = std(Trans_Wght_All,1,1);


[Trans_Wght]  = fn_FSD_Transmission_X(Pers,Weights,Conc,ExtAvg,TA,LongAttn);
[Trans_Wght_FSD]  = fn_FSD_Transmission_X(Pers,Weights,Conc,ExtAvg,TA,false);
[Trans_Wght_Disp]  = fn_FSD_Transmission_X(Pers,0*Weights,Conc,ExtAvg,TA,LongAttn);

FloeSampleTrans_1  = interp1(Pers,FloeSampleTrans,1 ./FFs);
Trans_Wght_1 = interp1(Pers,Trans_Wght, 1 ./FFs);
Trans_Wght_FSD_1 = interp1(Pers,Trans_Wght_FSD, 1 ./FFs);
Trans_Wght_Disp_1 = interp1(Pers,Trans_Wght_Disp, 1 ./FFs);


figure('DefaultAxesFontSize',18);
loglog(DiamS,Weights.*XDist(2)*Conc/ExtAvg  ,'--k')
hold on;
loglog(DiamS,FloeNumSample,'.b');
xlim([0.1,1e2])
ylim([1,1e4])
xlabel('Length')
ylabel('Count')
cleanfigure;
matlab2tikz('../Outputs/Plots/Fig6bInset.tex'); 


figure('DefaultAxesFontSize',18);
hold on;

S_I = gJSpec;

plot(2*pi*FFs,(Trans_Wght_1.^XDist(2)).*S_I,'-b');
plot(2*pi*FFs,(Trans_Wght_FSD_1.^XDist(2)).*S_I,'-g');
plot(2*pi*FFs,(Trans_Wght_Disp_1.^XDist(2)).*S_I,'-y');
plot(2*pi*FFs, (FloeSampleTrans_1.^XDist(2)).*S_I,':r')
plot(2*pi*FFs,S_I,'-k');
xlim([0.4,3])
ylim([0,2.5])
xlabel('\omega [s^-1]')
ylabel('S(\omega) [m^2 s]')
title('Spectral Evolution')
cleanfigure;
matlab2tikz('../Outputs/Plots/Fig6b.tex'); 

S_N_10km = (Trans_Wght_1.^XDist(2)).*S_I;
S_N_10km(isnan(S_N_10km)) = 1;
M0_2 = trapz(FFs,2*pi*S_N_10km);
Hs_2 = 4*sqrt(M0_2);


