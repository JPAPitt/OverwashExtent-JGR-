close all;
clear all;

%Load in the coefficient matrices
load('../Outputs/Data/RefTransTables/RefTran_LB_AN_T1.mat');

%Height tolerance ensuring overwash is significantly above the plate
HeightTol = 0.001;

%Draught ratio - Archimedes
DRat = ParamCons.DRat;

%Periods and frequencies at which coefficients are given
TpS = fliplr(reshape(P_Mat(1,1,2:end),1,[]));
FFs = 1./TpS;

%Frequency tolerance on overwash
TolFac = 20;

%Jonswap spectra defining properties - peak period, and significant wave
%height
TpTarg = 8;
HsTarg =2;

df = 0.01;
Mod_FFS = df:df:5;
JSSpec_Init = jonswapIEE(Mod_FFS,TpTarg,HsTarg);