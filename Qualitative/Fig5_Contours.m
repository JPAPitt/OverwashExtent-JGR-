% ------------------------
%       IrrOW_FSD_WaveProps_Wghts_Gen
% ------------------------
%
%  Authored by Jordan Pitt 08/09/22
%
% Uses matrices - T(w,L,d) , R(w,L,d) , \zeta(w,0,L,d), \zeta(w,L,L,d)
% to produce a transmission model in an FSD + predict overwash of specific
% floe geometry based on wave properties
%
% The initial spectra is Jonswap - with fixed Hs, Tp
%
% generates plot of ensemble average overwash frequency f_o as function of
% Hs and Tp

close all;
clear all;

%Load in the coefficient matrices
load('../Outputs/Data/CoefficientMatrices/Fig4_Qual/Omega_Dep.mat');

%Height tolerance ensuring overwash is significantly above the plate
HeightTol = 0.001;

%Draught ratio - Archimedes
DRat = ParamCons.DRat;

%Frequency tolerance on overwash
TolFac = 20;

%The thicknesses and diameters the cofficients are calcluated at
ThickS = reshape(FT_Mat(1,:,1),1,[]);
DiamS = reshape(FD_Mat(:,1,1),1,[]);

%Floe propertys to investigate overwash for - as index - diameter is
i1 = 1;
i2 = 1;

%Load matrices giving coefficients as functions of Diameter and w/T
[Pers,TA,RA,LPE,RPE,FT]= fn_Get_Response_AllDiams(P_Mat,LB_Out,FT_Mat,i2);
FD = DiamS(i1);
FB = DRat*FT;
PlateCond = FB + HeightTol;

TA = TA(i1,:);
RA = RA(i1,:);
LPE = LPE(i1,:);
RPE = RPE(i1,:);

FFs = 1./ Pers;
FFs(end) =  2./ (Pers(end-1) + Pers(end)); 

FFs_Mod = 0.005:0.005:3;
TA_Mod = interp1(FFs,TA,FFs_Mod);
RA_Mod = interp1(FFs,RA,FFs_Mod);
LPE_Mod = interp1(FFs,LPE,FFs_Mod);
RPE_Mod = interp1(FFs,RPE,FFs_Mod);

%Wave properties to invesitgate maximum overwash extent for
NumRes = 600;
T0 = 6;
T1 = 20;
TpTargs = linspace(T0,T1,NumRes); 
H0 = 0;
H1 = 10;
HsTargs = linspace(H0,H1,NumRes) ;

%mesh grid for plot
[Tp_Mat,Hs_Mat] = meshgrid(TpTargs,HsTargs);

%overwash for plotting
OW_Mat = zeros(size(Tp_Mat));
OR_Mat = zeros(size(Tp_Mat));

%loop over peak period and Hs
% for each generate overwash frequency - using the coefficients from
% coefficient matrix
for i = 1:size(Tp_Mat,1)
    for j = 1: size(Tp_Mat,2)
       
        Hs = Hs_Mat(i,j);
        Tp = Tp_Mat(i,j);
        
       %incoming spectra 
        U10 = 12;
        gamma=3.3;
        n = -5;
        [S_I,Beta,Tp] = fn_gJS(FFs_Mod,Hs,Tp,U10,gamma,n);
        
        %zero and second moments for incoming spectra
        M0_Inc =trapz(FFs_Mod ,S_I);
        M2_Inc = trapz(FFs_Mod ,(FFs_Mod.^2) .*S_I);

        %mean period for incoming
        AvgMeanT_Inc = sqrt(M0_Inc/ M2_Inc);

        %left spectra (Sl)
        LE0_Spectrum = (abs(1 + RA_Mod - LPE_Mod ).^2).*S_I;

        %zero and second moments for left plate spectra
        M0_LE =trapz(FFs_Mod,LE0_Spectrum);
        M2_LE = trapz(FFs_Mod,(FFs_Mod.^2) .*LE0_Spectrum);
        
        AT_LE = sqrt(M0_LE ./ M2_LE)./ exp(-PlateCond^2 ./ (2.*M0_LE));
        
        %right spectra (Sr)
        RE0_Spectrum = (abs(TA_Mod - RPE_Mod ).^2).*S_I;
        
        %zero and second moments for left plate spectra
        M0_RE =trapz(FFs_Mod,RE0_Spectrum);
        M2_RE = trapz(FFs_Mod,(FFs_Mod.^2) .*RE0_Spectrum);
        
        AT_RE = sqrt(M0_RE ./ M2_RE)./ exp(-PlateCond^2 ./ (2.*M0_RE));

        AT_M_List = min(AT_LE,AT_RE);
        
        %overwash frequency
        OR = AvgMeanT_Inc / AT_M_List;
        
   
        OR_Mat(i,j) = OR;
        
        if isnan(OR)
           OR = 0; 
        end
       
    end
end

%from the overwash frequencty for each Hs and Tp, generate contours in
%Level1
OR_Mat = fillmissing(OR_Mat,'constant',0);
Level1 = [0,0.05,0.1,0.5,1,2,3,4,100];

Col_List = parula(8);
ColInd = discretize( OR_Mat,Level1);

figure();
image('XData',[T0,T1],'YData',[H0,H1],'CData', ColInd )
colormap(Col_List);
c1 = colorbar();
caxis([1,length(Col_List)+1])
c1.Ticks = [1:1:9];
c1.TickLabels = [string(Level1(1:end-1))," "]; 
ylabel('Hs [m]')
xlabel('Tp [s]')
xlim([T0 ,T1])
ylim([H0 ,H1])

matlab2tikz('../Outputs/Plots/Fig5_Contours.tex'); 

