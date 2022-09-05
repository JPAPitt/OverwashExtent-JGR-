% ------------------------
%       Regular
% ------------------------
%
%  Authored by Jordan Pitt 20/10/21
%
% Use matrices of T(w), R(w), zeta(w,0),zeta(w,L) - using floe parameters
% from Bennetts and Williams 2015 
%
% Calculate overwash of these floes, with regular waves

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
        
%Regular wave properties
TpS = [0.3:0.01:2.1];
Amps = [0:0.005:1];


%Coefficients
Pers =Model_Pers;

TA = interp1(Pers,LB_Out{1},TpS);
RA = interp1(Pers,LB_Out{2},TpS);
LPE = interp1(Pers,LB_Out{4},TpS);
RPE = interp1(Pers,LB_Out{5},TpS);

DiskCounts = [0:3];
AsCritS = zeros(length(DiskCounts),size(TpS,2));

LPE_Cond = PlateCond./abs(1 +RA-LPE);
RPE_Cond = PlateCond./abs(TA-RPE);

CritAEither = min(LPE_Cond,RPE_Cond);

for i2 = 1:size(DiskCounts,2)
    CritAEDisk = CritAEither ./ (abs(TA).^DiskCounts(i2)) ;
    AsCritS(i2,:) = CritAEDisk;
end



AMat = repmat(Amps,size(TpS,2),1);
TpMat = repmat(TpS.',1,size(Amps,2));
DiskCountMat = zeros(size(AMat));

for i1 = 1:size(TpMat,1)
    for i2 = 1:size(TpMat,2)
        Tp = TpMat(i1,i2);
        As = AMat(i1,i2);
        
        IndexLB = find(As > AsCritS(:,i1),1,'last');
        
        if isempty(IndexLB)
            DiskCountMat(i1,i2) = 0;
        else 
            if IndexLB == length(DiskCounts)
                DiskCountMat(i1,i2) = DiskCounts(end);
            else
                DiskCountMat(i1,i2) = DiskCounts(IndexLB+1);
            end
        end
    end
end

%Experimental data
ExpD0Amp = [0.015,0.02 ,0.02,0.02];
ExpD0Tp = [0.95,1.25,1.55,1.85];
ExpD1Amp = [0.01];
ExpD1Tp = [0.65];
ExpD2Amp = [];
ExpD2Tp = [];
ExpD3Amp = [0.03,0.04];
ExpD3Tp = [0.95,1.25];


MA = max(Amps);

Cols =parula(length(DiskCounts));

figure('DefaultAxesFontSize',18);
for i2 = 1:size(DiskCounts,2)
    ListA = AsCritS(i2,:);
    ListA(ListA > MA) = MA;

    if i2 ==1
        TpSFill = [TpS, fliplr(TpS)];
        inBetweenFill  = [ListA, fliplr(0.*ListA)];
        fill(TpSFill, inBetweenFill, Cols(i2,:),'LineStyle','none');
        hold on;
    else
        TpSFill = [TpS, fliplr(TpS)];
        inBetweenFill  = [ ListA, fliplr(ListAM)];
        fill(TpSFill, inBetweenFill, Cols(i2,:),'LineStyle','none');
    end
    
    ListAM = ListA;
        
end
TpSFill = [TpS, fliplr(TpS)];
inBetweenFill  = [ListA, fliplr(1.1*max(Amps)+ 0*ListA)];
fill(TpSFill, inBetweenFill, Cols(end,:),'LineStyle','none');

scatter(ExpD0Tp,ExpD0Amp,200,'MarkerEdgeColor',[0 0 0],'MarkerFaceColor',Cols(1,:),'LineWidth',2)
scatter(ExpD1Tp,ExpD1Amp,200,'MarkerEdgeColor',[0 0 0],'MarkerFaceColor',Cols(2,:),'LineWidth',2)
scatter(ExpD3Tp,ExpD3Amp,200,'MarkerEdgeColor',[0 0 0],'MarkerFaceColor',Cols(4,:),'LineWidth',2)

xlim([0.3,2.1])
ylim([0.0,0.1])

cb = colorbar();
colormap(Cols);
caxis([DiskCounts(1), DiskCounts(end)+1]);
cb.Ticks = 1:3;
cb.TickLabels = ["1","2","3"]; 

cb.Label.String = 'Overwash Extent (# Floes)';
xlabel('\tau_p (s)')
ylabel('A (m)')
title('Regular Waves Number of Disks Overwashed')
colormap(Cols)


matlab2tikz('../Outputs/Plots/Figure7b.tex'); 
    

