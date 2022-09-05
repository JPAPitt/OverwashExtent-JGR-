% ------------------------
%       Fig8
% ------------------------
%
%  Authored by Jordan Pitt 20/10/21
%
% Uses matrices - T(w,h,d) , R(w,h,d) , \zeta(w,-L,h,d), \zeta(w,L,h,d)
% to produce a transmission model in an FSD + predict overwash extent based
% on floe geometry
%
% The initial spectra is Jonswap - with fixed Hs, Tp

%Plots overwash extent as functions of incoming waves (Hs and Tp)

close all;
clear all;

load('../Outputs/Data/CoefficientMatrices/Predictions.mat');
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


%parameters - for the FSD (split power law - Meylan )
% large Floes - Meylan
rho = 1e3;
Dmin = 2;

%Fragmented Toyota
gamma1 = 1.39;
gamma2 = 5.18;

i1 = 26;
i2 = 50;




%Pancake - Akberto
% i1 = 4;
% i2 = 21;
% Dmin = 0.25;
% gamma1 = 1.1;
% gamma2 = 9.4;

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


%Wave properties to invesitgate maximum overwash extent for
% NumRes = 500;
NumRes = 500;
H0 = 0;
H1 = 14;
HsTargs = linspace(H0,H1,NumRes) ;

T0 = 0;
T1 = 20;
TpTargs = linspace(T0,T1,NumRes) ;

%mesh grid for plot
[Tp_Mat,Hs_Mat] = meshgrid(TpTargs,HsTargs);

%maximum overwash extent for plotting
OWE_Mat = zeros(size(Tp_Mat));

%Number of floes encountered - to be tested by overwash model 
Dists = [0,1e-6,1:1:1e1,2e1:1e1:1e2,2e2:1e2:1e3,2e3:1e3:1e4,2e4:1e4:1e5,2e5:1e5:1e6,2e6:1e6:1e7];
NumList = Dists *Conc / ExtAvg;

%parameter to include/ not include long wave attenuation in the
%transmission model
LongAttn = true;

%Transmission model - T(w,N) - gives the spectral response after N disks
%like so S(w,N) = T(w).^N * S(w) 
[Trans_Wght]  =  fn_FSD_Transmission_X(Pers,Weights,Conc,ExtAvg,TA,LongAttn);

%Incoming Spectra
FFs = 1./ Pers;
FFs(end) =  2./ (Pers(end-1) + Pers(end)); 
U10 = 12;
g = 9.81;
gamma = 3.3;
n=-5;


%Loop over Lengths of interest
 for i = 1:size(OWE_Mat,1)   
    for j = 1:size(OWE_Mat,2) 
        Tp = Tp_Mat(i,j);
        Hs = Hs_Mat(i,j);
        [S_I,Beta,Tp] = fn_gJS(FFs,Hs,Tp,U10,gamma,n);
        X_Dist = fn_OWEx_WaveProps_SI(FFs,Trans_Wght,TA,RA,LPE,RPE,PlateCond,TolFac,Dists,i1,S_I);
        OWE_Mat(i,j)= X_Dist;
    end

 end
 
Coeff = 16* 6.365e-6 * U10^0.7 * g^(1.3);


%Levels for coloring
DistScale = [0,1e-6,1,1e1,1e2,1e3,1e4,1e5,1e6];
%Produce indexed NDC_LB_Mat - giving the color for each entry
ColInd = discretize( OWE_Mat,DistScale);

%String of distances to plot at (remove facetious boundaries required by discretize)
StrDist = [DistScale(1),DistScale(3:end-1)];

%Produce colors for each index in 'color' matrix
ColNum=length(StrDist);
% Col_List = linspecer(ColNum);
Col_List = parula(ColNum);

%resize it - so that matlab2tikz doesn't produce a weirdly scaled png -
%which becomes blurry in paper/presentation
Num = 2*NumRes;
ResizedMat = imresize(ColInd,[Num,Num],'nearest');

%produce plot
figure('DefaultAxesFontSize',18);
hold on;
image('XData',[T0,T1],'YData',[H0,H1],'CData',ResizedMat)
% plot(HsTargs,( (1 / Coeff) * HsTargs.^2 ).^ (1/3.3) ,'-k');
plot(TpTargs, sqrt(Coeff* TpTargs.^(3.3)),'--k','LineWidth',3);
colormap(Col_List);
ylabel('Hs [m]')
xlabel('Tp [m]')
title(['Maximum Overwash Distance - FSD - Particular Floe - FT= ',num2str(FT), ' FD = ', num2str(FD)]);
c1 = colorbar();
caxis([1,length(StrDist)+1])
xlim([T0 ,T1])
ylim([H0 ,H1])
c1.Label.String = 'Maximum Overwash Distance in FSD Field [m]';

c1.Ticks = 1.5 :1: length(StrDist)+0.5;


St1 = string(StrDist(2:end-2));
St2 = string(StrDist(3:end-1) - 1);
St3 = St1 + '-' + St2;
StrBeg = ['<',num2str(StrDist(2))];
StrEnd = ['>=',num2str(StrDist(end-1))];

c1.TickLabels = ['None',StrBeg,St3,StrEnd]; 
 
cleanfigure;
matlab2tikz('../Outputs/Plots/Fig8b.tex'); 


