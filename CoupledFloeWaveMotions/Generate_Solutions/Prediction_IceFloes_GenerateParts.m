% ------------------------
%      Prediction_IceFloes_GenerateParts
% ------------------------
%
%  Authored by Jordan Pitt 20/10/21
%
% Produce matrices to use in the overwash model - T(w,L,d) , R(w,L,d) , \zeta(w,-L,L,d), \zeta(w,L,L,d)
% these wil be used by the overwash + transmission model to predict extents
%
% In this example we choose floe parameters consistent with ice.

close all;
clear all;

%Suppress warning
warning('off','all')

%PartsBlock - Takes ~ 14 hours est. on my mac - MacBook Pro (13-inch, 2020, Four Thunderbolt 3 ports)
PartsToRun = 20;
PartLen = 25;


NumResPhys = 500;
Parts = NumResPhys / PartLen;

for Parti = 1:PartsToRun

%Floe properties - h and d to solve coefficients for
Floe_Diams_All = linspace(0.1,100,NumResPhys);
Floe_Thicknesses_All =linspace(0.1,10,NumResPhys);


Dir1  = '../Outputs/Data/CoefficientMatrices/Prediction_Segments/';
FilesStruct =  dir(Dir1);
FileNames = string({FilesStruct.name});

if length(FileNames) < 4
   CurrPart = 1;
else
   FileNames = FileNames(4:end);
   StrExtFunc = @(x) (extractBetween(x,'_p','.mat'));
   FileNamesMatch = arrayfun(StrExtFunc, FileNames);
   Nums = arrayfun(@str2num, FileNamesMatch);
   
   if max(Nums) == PartsToRun
       cprintf('_green',  'All parts present \n');
       break
   end
   CurrPart = max(Nums) + 1;
end

PartLen_B = PartLen*(CurrPart-1)+1;
PartLen_E = min(PartLen*CurrPart,NumResPhys);
% 
Floe_Diams = Floe_Diams_All(:);
Floe_Thicknesses = Floe_Thicknesses_All(PartLen_B:PartLen_E);

%Periods T to use as the angular frequency w = 2*pi/T, to solve the
%coefficients for
CC = 30;
HR = 470;

MaxP = 40;
HighRes = linspace(0,20,HR);
LowRes = linspace(HighRes(end) + HighRes(2),MaxP,CC);

Model_Pers_All(1,1,:) = [HighRes,LowRes];


%Generate matrices of these values - FD for floe diameter -d, Ft for floe
%thickness - h, and P for periods for each
FD_Mat = repmat(Floe_Diams,1,size(Floe_Thicknesses,2),size(Model_Pers_All,3));
FT_Mat = repmat(Floe_Thicknesses,size(FD_Mat,1),1,size(FD_Mat,3));
P_Mat = repmat(Model_Pers_All,size(FD_Mat,1),size(FD_Mat,2),1);

%Coefficient matrices at each of the h,d and T/w
Ta_LB_Mat = zeros(size(P_Mat));
Ra_LB_Mat = zeros(size(P_Mat));
kS_LB_Mat = zeros(size(P_Mat));
LPE_LB_Mat = zeros(size(P_Mat));
RPE_LB_Mat = zeros(size(Model_Pers_All));


%Model parameters - using Luke's model
th_res=100;
SURGE=0;
% SURGE = 1;
terms_grn=100;
extra_pts=[];     
rigid = 4; 
n=10; %number of eigenvalues

%Physical parameters
Param = ParamDef_Oceanide(rigid); 
Param = ModParam_def(Param,1,n,extra_pts,terms_grn,th_res); 


%Physical Parameters - using Luke's model
Param.E = 6e9;
Param.nu = 0.3;
Param.bed = 1000;
Param.rho_0 = 1025;

%Save the Parameter values 
ParamCons.IceRho = 920;
ParamCons.VolFrac = 1;
ParamCons.PCRho = ParamCons.VolFrac*ParamCons.IceRho;
Param.rho = ParamCons.PCRho;
ParamCons.E = Param.E;
ParamCons.bed = Param.bed;
ParamCons.g = Param.g;
ParamCons.nu = Param.nu;
ParamCons.DRat = (1-Param.rho/Param.rho_0);


%Loop over thickness and diameter
for i1 = 1:size(FD_Mat,1)
    for i2 = 1:size(FD_Mat,2)
        
        %update physical parameters - using floe thickness and diameter
        Param.thickness = FT_Mat(i1,i2,1);
        Param.floe_diam = FD_Mat(i1,i2,1);
        L = Param.floe_diam/2;
        plateabove=Param.thickness*(1-Param.rho/Param.rho_0);
        Param.draft = Param.thickness.*Param.rho./Param.rho_0; 
        Param.D = Param.E.*Param.thickness.^3./(12*(1-Param.nu.^2));
        Param.beta = Param.D./(Param.g.*Param.rho_0);

        %vectors of coefficients
        Ta_LB = zeros(1,size(FD_Mat,3));
        Ra_LB = zeros(1,size(FD_Mat,3));
        LPE_LB = zeros(1,size(FD_Mat,3));
        RPE_LB = zeros(1,size(FD_Mat,3));
        kS_LB = zeros(1,size(FD_Mat,3));

        %limit values as T -> 0 (w -> Inf)
        Ta_LB(1) = 0;
        Ra_LB(1) = 1;
        LPE_LB(1) = 0;
        RPE_LB(1) = 0;
        kS_LB(1) = Inf;

        %limit values as T -> Inf (w -> 0)
        Ta_LB(end) = 1;
        Ra_LB(end) = 0;
        LPE_LB(end) = 1;
        RPE_LB(end) = 1;
        kS_LB(end) = 0;


        %Loop over periods
        for i3 = 2:size(FD_Mat,3)-1

            Freq = 1./P_Mat(i1,i2,i3);

            try
                out = fn_ElasticRaft2d('freq', Freq,Param,'disk',SURGE,0,0,1,0,'r',[-L,L]);
                TN = (out(1).value);
                RN = (out(2).value);
                Plate = out(3).value;
                k = out(4).value;

            catch
                TN = NaN;
                RN = NaN;
                Plate = [NaN,NaN];
                k = NaN;
            end

            Ta_LB(i3) = TN;
            Ra_LB(i3) = RN;
            kS_LB(i3) = k;
            LPE_LB(i3) = Plate(1);
            RPE_LB(i3) = Plate(2);

        end
        Model_Pers = reshape(P_Mat(1,1,:),1,[]);


        %Model has issues when T is small (w is large) - we replace this
        %with the full reflection limit (T -> 0)
        %The periods this effects are much smaller than the ones of
        %interest for swell waves
        Ta_LB(isnan(Ta_LB)) = Ta_LB(1) ;
        Ra_LB(isnan(Ra_LB)) = Ra_LB(1);
        kS_LB(isnan(kS_LB)) = interp1(Model_Pers(~isnan(kS_LB)),kS_LB(~isnan(kS_LB)),Model_Pers(isnan(kS_LB))) ;
        LPE_LB(isnan(LPE_LB)) = LPE_LB(1) ;
        RPE_LB(isnan(RPE_LB)) = RPE_LB(1) ;

        %Fill relevant matrices with the vector
        Ta_LB_Mat(i1,i2,:) = Ta_LB(:);
        Ra_LB_Mat(i1,i2,:) = Ra_LB(:);
        kS_LB_Mat(i1,i2,:) = kS_LB(:);
        LPE_LB_Mat(i1,i2,:) = LPE_LB(:);
        RPE_LB_Mat(i1,i2,:) = RPE_LB(:);

    end
end


%Combine Matrices into a common structure
LB_Out = {Ta_LB_Mat,Ra_LB_Mat,kS_LB_Mat,LPE_LB_Mat,RPE_LB_Mat};


%Write the matrix out
File_Nm = [Dir1,'Validation_Coeff_Mat_p',num2str(CurrPart),'.mat'];
MatFile_NM = strcat(File_Nm);
save(MatFile_NM,'FD_Mat','FT_Mat','P_Mat','LB_Out','ParamCons');
end

