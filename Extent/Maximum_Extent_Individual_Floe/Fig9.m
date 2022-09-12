% ------------------------
%       Fig9
% ------------------------
%
%  Authored by Jordan Pitt 20/10/21
%
% Uses matrices - T(w,h,d) , R(w,h,d) , \zeta(w,-L,h,d), \zeta(w,L,h,d)
% to produce a transmission model in an FSD + predict overwash extent based
% on floe geometry
%
% The initial spectra is Jonswap - with fixed Hs, Tp

%Plots overwash extent as functions of floe geometery (length and thickness)


close all;
clear all;

%Load in the coefficient matrices
% load('../Outputs/Data/RefTransTables/RefTran_LB_AN_T1.mat');

load('../Outputs/Data/CoefficientMatrices/Predictions.mat');


LB_Out = {TA_Mat_All,RA_Mat_All, kS_Mat_All,LPE_Mat_All,RPE_Mat_All};

%Height tolerance ensuring overwash is significantly above the plate
HeightTol = 0.001;

%Draught ratio - Archimedes
DRat = ParamCons.DRat;


Pers = fliplr(reshape(P_Mat(1,1,:),1,[]));
FFs = 1./ Pers;
FFs(end) =  2./ (Pers(end-1) + Pers(end)); 

%Frequency tolerance on overwash
TolFac = 20;

%Jonswap spectra defining properties - peak period, and significant wave
%height
HsTarg = 2;

%Concentration of the Floes - scales extents
Conc = 0.6;

%The thicknesses and diameters the cofficients are calcluated at
ThickS = reshape(FT_Mat(1,:,1),1,[]);
DiamS = reshape(FD_Mat(:,1,1),1,[]);

%produce 2-dim matrices of thicknesses and diameters - for plotting
[NT_Mat,ND_Mat] = meshgrid(ThickS,DiamS);

%Number of disks overwashed
OWE_Mat = zeros(size(NT_Mat));

U10 = 12;
g = 9.81;
gamma = 3.3;
n=-5;
[S_I,Beta,TpTarg] = fn_gJS(FFs,HsTarg,[],U10,gamma,n);


%parameters - for the FSD (split power law - Meylan )
%This is the general FSD from wide data
rho = 1e3;
Dmin = 2;
gamma1 = 1.15;
gamma2 = 2.5;


%parameter to include/ not include long wave attenuation in the
%transmission mode
LongAttn = true;

%Number of floes encountered - to be tested by overwash model 
Dists = [0,1e-6,1:1:1e1,2e1:1e1:1e2,2e2:1e2:1e3,2e3:1e3:1e4,2e4:1e4:1e5,2e5:1e5:1e6,2e6:1e6:1e7];

%For each thickness generate an FSD, find maximum distance floes are
%overwashed by the transmitted waves, and record it in the output matrix - OWE_Mat
for i2 = 1:size(NT_Mat,2)
    
     %get 2 dim arrays of coefficients - as functions of omega, and
     %diameter
    [Pers,TA,RA,LPE,RPE,FT]= fn_Get_Response_AllDiams(P_Mat,LB_Out,FT_Mat,i2);
    
     FB = DRat*FT;
     PlateCond = FB + HeightTol;
     
     %Dt = ((pi^4*ParamCons.E*FT^3) / (48*rho*ParamCons.g*(1 - ParamCons.nu^2)))^0.25;
     Dt = 30;
     [Weights,ExtAvg] = fn_Get_FloeSample_Wght(DiamS,Dmin,Dt,gamma1,gamma2);
     
    [Trans_Wght]  =  fn_FSD_Transmission_X(Pers,Weights,Conc,ExtAvg,TA,LongAttn);
     
     X_Dists = fn_OWEx_IceProps(Pers,Trans_Wght,TA,RA,LPE,RPE,S_I,PlateCond,TolFac,DiamS,Dists);
     
     OWE_Mat(:,i2)  = X_Dists;
     
end

%Levels for coloring
DistScale = [0,1e-6,1,1e1,1e2,1e3,1e4,1e5,1e6];
%Produce indexed OWE_Mat - giving the color for each entry
ColInd = discretize( OWE_Mat,DistScale);

%String of distances to plot at (remove facetious boundaries required by discretize)
StrDist = [DistScale(1),DistScale(3:end-1)];

%Produce colors for each index in 'color' matrix
ColNum=length(StrDist);
Col_List = parula(ColNum);

%resize it - so that matlab2tikz doesn't produce a weirdly scaled png -
%which becomes blurry in paper/presentation
Num = 2*length(NT_Mat);
ResizedMat = imresize(ColInd,[Num,Num],'nearest');


%produce the figures of maximum overwash distance VS Floe properties
figure('DefaultAxesFontSize',18);
image('XData',[ThickS(1),ThickS(end)],'YData',[DiamS(1),DiamS(end)],'CData',ResizedMat)
colormap(Col_List);
ylabel('d [m]')
xlabel('F_b [m]')
title(['Maximum Overwash Distance - FSD - Irregular Wave Tp= ',num2str(TpTarg), ' Hs = ', num2str(HsTarg)]);
c1 = colorbar();
caxis([1,length(StrDist)+1])
c1.Label.String = 'Maximum Overwash Distance in FSD Field [m]';

c1.Ticks = 1.5 :1: length(StrDist)+0.5;

St1 = string(StrDist(2:end-2));
St2 = string(StrDist(3:end-1) - 1);
St3 = St1 + '-' + St2;
StrBeg = ['<',num2str(StrDist(2))];
StrEnd = ['>=',num2str(StrDist(end-1))];

c1.TickLabels = ['None',StrBeg,St3,StrEnd]; 

xlim([ThickS(1),ThickS(end)])
ylim([DiamS(1),DiamS(end)])


matlab2tikz('../Outputs/Plots/Fig9a.tex'); 




