% ------------------------
%       Irregular Wave Result
% ------------------------
%
%  Authored by Jordan Pitt 08/09/22
%
% Uses matrices - T(w,L,d) , R(w,L,d) , \zeta(w,0,L,d), \zeta(w,L,L,d)
% to predict overwash extent for irregular wave experiment in Bennetts and Williams 2015 
%Since the disks are the same, can actually calculate the amplitude
%required to overwash a number of disks, which is what we do here (to analytically get the contours)


%Load in matrices
close all;
clear all;
load('../Outputs/Data/CoefficientMatrices/Validation.mat');


%Height tolerance ensuring overwash is significantly above the plate
HeightTol = 0.001;
plateabove = ParamCons.DRat*ParamCons.FT;
PlateCond = plateabove + HeightTol;


%Overwash frequency
TolFac = 20;
        
%Coefficients
Pers = fliplr(Model_Pers);

%account for 1/0
FFs = 1./Pers;
FFs(end) = 2./(Pers(end) + Pers(end-1));

TA = fliplr(LB_Out{1});
RA = fliplr(LB_Out{2});
kS = fliplr(LB_Out{3});
LPE = fliplr(LB_Out{4});
RPE = fliplr(LB_Out{5});

%Wave Properties to try
TpTargs = [0.3:0.02:2.2];
HsTargs = [0:0.001:0.23].';

%Number of disks to transmit through
DiskCounts = [0:3];
HsCritS = zeros(length(DiskCounts),size(TpTargs,2));

%For each peak period, find scaling parameter Hs to ensure that the  disk
%number is overwashed
for i1 = 1:size(TpTargs,2)

    %generate normalised spectra for that peak period.
    TpTarg = TpTargs(i1);
    JSSpec_Init_Normalised = jonswapIEE(FFs,TpTarg,4 );

    %For each disk number
    for i2 = 1:size(HsCritS,1)
        
        %Update disk count
        DiskCount = DiskCounts(i2);
        
        %calculate transmitted spectra for disk count
        JSspec = ((abs(TA).^2).^DiskCount).*JSSpec_Init_Normalised; 
        
        %zero and second moments for incoming spectra
        M0_Inc =trapz(FFs,JSspec);
        M2_Inc = trapz(FFs,(FFs.^2) .*JSspec);

        %mean period for incoming
        AvgMeanT_Inc = sqrt(M0_Inc/ M2_Inc);

        %left spectra - only because  abs(1 + Tp_RA - Tp_LPE ).^2 > abs(Tp_TA - Tp_RPE )
        %want to calculate this Hs crit, so we need just one
        LE0_Spectrum = (abs(1 + RA - LPE ).^2).*JSspec;

        %zero and second moments for left plate spectra
        M0_LE =trapz(FFs,LE0_Spectrum);
        M2_LE = trapz(FFs,(FFs.^2) .*LE0_Spectrum);

        %mean period for wave passing above PlateCond - overwashing
%         AvgPlateT_LE = sqrt(M0_LE/ M2_LE)/ exp(-PlateCond^2 / (2*M0_LE))
        logt1 = log(TolFac*AvgMeanT_Inc / (sqrt(M0_LE/ M2_LE)));
        
        %Amplitude needed to ensure overwash after diskcount disks -
        %conversion to Hs
        AS = (PlateCond^2 / (2*M0_LE)) / logt1;
        HsCritS(i2,i1) = sqrt(16*AS);
    end
    

end


%Experimental values - D1 is experiments with 1 disk regularly overwashing
% D3 is experiments with all 3 disks overwashing regularly
ExpD1Hs = [0.02,0.04];
ExpD1Tp = [0.8,1.4];
ExpD3Hs = [0.08];
ExpD3Tp = [1.4];

MA = max(HsTargs);

Cols =parula(length(DiskCounts));

%Produce plot - fill areas between the Hs/ critical contours
figure('DefaultAxesFontSize',18);
for i2 = 1:size(DiskCounts,2)
    ListA = HsCritS(i2,:)/2;
    ListA(ListA > MA) = MA;

    if i2 ==1
        TpSFill = [TpTargs, fliplr(TpTargs)];
        inBetweenFill  = [ListA, fliplr(0.*ListA)];
        fill(TpSFill, inBetweenFill, Cols(i2,:),'LineStyle','none');
        hold on;
    else
        TpSFill = [TpTargs, fliplr(TpTargs)];
        inBetweenFill  = [ ListA, fliplr(ListAM)];
        fill(TpSFill, inBetweenFill, Cols(i2,:),'LineStyle','none');
    end
    
    ListAM = ListA;
        
end
TpSFill = [TpTargs, fliplr(TpTargs)];
inBetweenFill  = [ListA, fliplr(2*MA+ 0*ListA)];
fill(TpSFill, inBetweenFill, Cols(end,:),'LineStyle','none');
xlim([0.3,2.1])
ylim([0,0.1])

cb = colorbar();
colormap(Cols);


caxis([DiskCounts(1), DiskCounts(end)]);
labelstring = [string(DiskCounts(1:end)),''];
Ticks = linspace(DiskCounts(1), DiskCounts(end),length(labelstring));
cb.Ticks = Ticks;
cb.TickLabels = labelstring; 

% scatter(ExpD1Tp,ExpD1Hs,200,'k','filled','s')
% scatter(ExpD3Tp,ExpD3Hs,200,'k','filled','^')

scatter(ExpD1Tp,ExpD1Hs/2,200,'MarkerEdgeColor',[0 0 0],'MarkerFaceColor',Cols(2,:),'LineWidth',2)
scatter(ExpD3Tp,ExpD3Hs/2,200,'MarkerEdgeColor',[0 0 0],'MarkerFaceColor',Cols(4,:),'LineWidth',2)

cb.Label.String = 'Overwash Extent (# Floes)';
xlabel('\tau_p (s)')
ylabel('H_{s} / 2 (m)')
title('Irregular Waves - PRSA - Number of Disks Overwashed')
colormap(Cols)

matlab2tikz('../Outputs/Plots/Figure7c.tex');
