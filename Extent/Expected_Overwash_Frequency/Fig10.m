% ------------------------
%       Fig10a
% ------------------------
%
%  Authored by Jordan Pitt 20/10/21
%
% Uses matrices - T(w,h,d) , R(w,h,d) , \zeta(w,-L,h,d), \zeta(w,L,h,d)
% to produce a transmission model in an FSD + predict expected overwash
% frequency over length
%
% The initial spectra is Jonswap - with fixed Hs, Tp

close all;
clear all;

load('../Outputs/Data/CoefficientMatrices/Predictions.mat');
LB_Out = {TA_Mat_All,RA_Mat_All, kS_Mat_All,LPE_Mat_All,RPE_Mat_All};

%Height tolerance ensuring overwash is significantly above the plate
HeightTol = 0.001;

%Draught ratio - Archimedes
DRat = ParamCons.DRat;

%Periods and frequencies at which coefficients are given

%Frequency tolerance on overwash
TolFac = 20;

%The thicknesses and diameters the cofficients are calcluated at
ThickS = reshape(FT_Mat(1,:,1),1,[]);
DiamS = reshape(FD_Mat(:,1,1),1,[]);




rho = 1e3;

%Toyota - Fragmented Floe
% i2 = 50;
% Dmin = 0.1;
% gamma1 = 1.15;
% gamma2 = 2.5;

%Alberto - Pancake Floe
i2 = 21;
Dmin = 0.25;
gamma1 = 1.1;
gamma2 = 9.4;


%Concentration of the Floes - scales extents
Conc = 0.6;


%Load matrices giving coefficients as functions of Diameter and w/T
[Pers,TA,RA,LPE,RPE,FT]= fn_Get_Response_AllDiams(P_Mat,LB_Out,FT_Mat,i2);
FB = DRat*FT;
PlateCond = FB + HeightTol;

%Critical power law transition in FSD - Pancake floes (Alberto)
Dt = 3.15; %middle of the 2.3 - 4 range, Alberto has for pancake ice

%Get the weights for floe diameters, and average floe diameter
[Weights,ExtAvg] = fn_Get_FloeSample_Wght(DiamS,Dmin,Dt,gamma1,gamma2);

%Xdistance to plot probability at
XDists = [0,1:0.1:1e1,1.1e1:0.1e1:1e2,1.1e2:0.1e2:1e3,1.1e3:0.1e3:1e4];

HsS = 2:2:14;

U10 = 12;
gamma=3.3;
n = -5;

%parameter to include/ not include long wave attenuation in the
%transmission model
LongAttn = true;

%Transmission model - T(w,N) - gives the spectral response after N disks
%like so S(w,N) = T(w).^N * S(w) 
%where S(w) is incoming spectra
 [Trans_Wght]  =  fn_FSD_Transmission_X(Pers,Weights,Conc,ExtAvg,TA,LongAttn);

%Incoming Spectra
FFs = 1./ Pers;
FFs(end) =  2./ (Pers(end-1) + Pers(end)); 

Extents = zeros(size(HsS));
ExtentsHs = zeros(size(HsS));

ftol = 0.05;

figure('DefaultAxesFontSize',18);
for i = 1:length(HsS)
   
    Hs = HsS(i);
    [S_I,Beta,Tp] = fn_gJS(FFs,Hs,[],U10,gamma,n);

    ProbDists = fn_OW_Prob_SIn(FFs,Trans_Wght,TA,RA,LPE,RPE,PlateCond,XDists,Weights,S_I);
    loglog(XDists,ProbDists,'DisplayName',['Tp= ',num2str(Tp), ' Hs = ',num2str(Hs)]);
    hold on;
    
    Xi = find(ProbDists > ftol,1,'last');
    Extents(i) = XDists(Xi);
    
    S_I_X = Trans_Wght.^XDists(Xi) .*S_I;
    M0_I =trapz(FFs,  S_I_X );
    ExtentsHs(i) = 4*sqrt(M0_I);
    

end
legend();
plot([1,1e4],[0.05,0.05],'--k')
xlim([1,1e4])
ylim([1e-5,10])
% FSDStr = ' Medium Size Floes (Toyota)';
FSDStr = ' Pancake Floes (Alberto)';
title({'log-log plot E(Overwash Freq) ', FSDStr , ['Concentration = 0.6']})
ylabel('Expected Relative Overwash Frequency')
xlabel('Distance (m)')

matlab2tikz('../Outputs/Plots/Fig10a.tex'); 



