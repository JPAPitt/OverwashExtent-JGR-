clear all;
close all;

Lats =[-63,-61];
Lons =[29 ,31];

MatFile_NM = strcat('../Outputs/Data/Agulhas/AgulDataStore.mat');
load(MatFile_NM);

load('../Outputs/Data/CoefficientMatrices/Predictions.mat');
LB_Out = {TA_Mat_All,RA_Mat_All, kS_Mat_All,LPE_Mat_All,RPE_Mat_All};


% 
% Get Trans Propertes

LatList = zeros(1,size(Dist_Mat,1));
LonList = zeros(1,size(Dist_Mat,1));
IndexList = 1:size(Dist_Mat,1);
OWIndices = zeros(size(Dist_Mat,1),1);

MeanFo = zeros(size(IndexList));

for i1 =IndexList 
        
LatSIInd = i1;
IndexConcZero = find(IC_Mat(LatSIInd,:) > 0,1,'first');
IndexConcZero = IndexConcZero - 2;

%Shorten length, since tranmission is 1
CummDistLine =  Dist_Mat(LatSIInd,IndexConcZero:end);
ConcLine =  IC_Mat(LatSIInd,IndexConcZero:end);

% %FSD Properties
Dmin = 0.25;
gamma1 = 1.1;
gamma2 = 9.4;
Dt = 3.15;

%Samples
% load('../Outputs/Data/RefTransTables/RefTran_LB_AN_T1.mat');

DiamS = reshape(FD_Mat(:,1,1),1,[]);
[Weights,ExtAvg] = fn_Get_FloeSample_Wght(DiamS,Dmin,Dt,gamma1,gamma2);

% %floe Props
HeightTol = 0.001;
DRat = ParamCons.DRat;
i2 = 21;
[Pers,TA,RA,LPE,RPE,FT]= fn_Get_Response_AllDiams(P_Mat,LB_Out,FT_Mat,i2);
FB = DRat*FT;
PlateCond = FB + HeightTol;

U10 = 12;
Hs = Hs_List(LatSIInd);
Tp = Tp_List(LatSIInd);

FFs = 1./ Pers;
FFs(end) =  2./ (Pers(end-1) + Pers(end)); 

% [S_I_In,Beta,Tp] = fn_gJS(FFs,Hs,Tp,U10);

gamma=3.3;
n = -5;

[S_I_In,Beta,Tp] = fn_gJS(FFs,Hs,Tp,U10,gamma,n);

ProbDists_All = [];
XDists_All = [];
S_I_All = [];
S_I = S_I_In;

FloeCount = 0;

for i = 1:length(ConcLine)
    Conc = ConcLine(i) ;
    
    
    if i == 1
        Dist = 0;
    else
         Dist = CummDistLine(i) - CummDistLine(i-1);
    end
    
    
    %For each cell, can calculate
    if Conc > 0.1
        LongAttn = true;
    else
        LongAttn = false;
    end
    %for each entry in dist
    
    [Trans_Wght]  =  fn_FSD_Transmission_X(Pers,Weights,Conc,ExtAvg,TA,LongAttn);

    ProbDists = fn_OW_Prob_SIn(FFs,Trans_Wght,TA,RA,LPE,RPE,PlateCond,0,Weights,S_I);
    
    S_I = (Trans_Wght.^Dist).*S_I;

    if ProbDists < 0.05
        break;
    end

    ProbDists_All = [ProbDists_All, ProbDists];

end

LastInd = i-1;
OWIndices(i1) = IndexConcZero + LastInd;

LatList(i1) = Lat_Mat(LatSIInd,OWIndices(i1));
LonList(i1) = Lon_Mat(LatSIInd,OWIndices(i1));

BotInd = find(ConcLine  >  0.01,1, 'first');
MeanFo(i1) = mean(ProbDists_All(BotInd:end));

end



fg1 = figure();

contourf(lox,lay,sii,[0:0.01:1],'LineColor','none');
hold on;

for i1 = IndexList
plot(Lon_Mat(i1,1:OWIndices(i1)),Lat_Mat(i1,1:OWIndices(i1)),'--k')
end

caxis([0 1])
cb = colorbar('Location','EastOutside');
cb.Label.String = 'i_c';
plot(Pos_Mat(:,1),Pos_Mat(:,2),'-r','linewidth',2)
plot(Pos_Mat(TimeLoc,1),Pos_Mat(TimeLoc,2),'.k')
xlim(Lons), ylim(Lats), grid on
xlabel('Longtitude')
ylabel('Latitude')

save('../Outputs/Data/Agulhas/AgulhasPlot_Fin.mat','lox','lay','sii','Lon_Mat','Lat_Mat','OWIndices','Pos_Mat','TimeLoc');

