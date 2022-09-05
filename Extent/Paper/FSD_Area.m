% ------------------------
%       IrrOW_FSD_WaveProps_Wghts_Gen
% ------------------------
%
%  Authored by Jordan Pitt 20/10/21
%
% Uses matrices - T(w,h,d) , R(w,h,d) , \zeta(w,-L,h,d), \zeta(w,L,h,d)
% to produce a transmission model in an FSD + predict overwash of specific
% floe geometry based on wave properties
%
% The initial spectra is Jonswap - with fixed Hs, Tp

close all;
clear all;

%Load in the coefficient matrices
% load('../Outputs/Data/RefTransTables/RefTran_LB_AN_T1.mat');

load('../Outputs/Data/RefTransTables/BreakDown/RefTran_IceProps_BD_full.mat');

LB_Out = {TA_Mat_All,RA_Mat_All, kS_Mat_All,LPE_Mat_All,RPE_Mat_All};

%Height tolerance ensuring overwash is significantly above the plate
HeightTol = 0.001;

%Draught ratio - Archimedes
DRat = ParamCons.DRat;


%Frequency tolerance on overwash
TolFac = 20;

%The thicknesses and diameters the cofficients are calcluated at
ThickS = reshape(FT_Mat(1,:,1),1,[]);
DiamS = reshape(FD_Mat(:,1,1),1,[]);

%For larger floe 1m is 4, 10m 31 , 100m is 300


%parameters - for the FSD (split power law - Meylan )
% large Floes - Meylan
rho = 1e3;

%Pancake - Akberto
% i1 = 4;
% i2 = 21;
% Dmin = 0.25;
% gamma1 = 1.1;
% gamma2 = 9.4;

%Floe Toyota
i2 = 46;
i1 = 26;
Dmin =  2;
gamma1 = 1.39;
gamma2 = 5.18;

%Concentration of the Floes - scales extents
Conc = 0.6;


%Load matrices giving coefficients as functions of Diameter and w/T
[Pers,TA,RA,LPE,RPE,FT]= fn_Get_Response_AllDiams(P_Mat,LB_Out,FT_Mat,i2);
FD = DiamS(i1);
FB = DRat*FT;
PlateCond = FB + HeightTol;
     
% Critical power law transition in FSD - breaking criteria (depends on thickness)
Dt = ((pi^4*ParamCons.E*FT^3) / (48*rho*ParamCons.g*(1 - ParamCons.nu^2)))^0.25;

%Critical power law transition in FSD - Pancake floes (Alberto)
% Dt = 3.15; %middle of the 2.3 - 4 range, Alberto has for pancake ice

%Get the weights for floe diameters, and average floe diameter
[Weights,ExtAvg] = fn_Get_FloeSample_Wght(DiamS,Dmin,Dt,gamma1,gamma2);

AreaS = 2*pi*(DiamS.^2);

AreaWeights = (Weights.*AreaS) ./ sum(AreaS);

[~,j1] = max(AreaWeights);

DiamSMaxArea = DiamS(j1);

figure();
plot(DiamS,AreaWeights)


