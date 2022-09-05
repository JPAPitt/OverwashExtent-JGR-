% ------------------------
%       Prediction_IceFloes_CombineParts
% ------------------------
%
%  Authored by Jordan Pitt 20/10/21
%
%Combines the parts to produce a single matrix for use in the overwash
%model - T(w,h,d) , R(w,h,d) , \zeta(w,-L,h,d), \zeta(w,L,h,d)

%does no checking, so it will just combine everything matching the format.

close all;
clear all;

%Suppress warning
warning('off','all')

Dir1  = '../Outputs/Data/CoefficientMatrices/Prediction_Segments/';
FilesStruct =  dir(Dir1);
FileNames = string({FilesStruct.name});

FileNames = FileNames(4:end);
StrExtFunc = @(x) (extractBetween(x,'_p','.mat'));
FileNamesMatch = arrayfun(StrExtFunc, FileNames);
Nums = arrayfun(@str2num, FileNamesMatch);

Nums = sort(Nums);

Ta0 = 0;
Ra0 = 1;
LPE0 = 0;
RPE0 = 0;

for i = 1:length(Nums)
    Num = Nums(i);
    File_Nm = [Dir1,'Validation_Coeff_Mat_p',num2str(Num),'.mat'];
    
    load(File_Nm);
    
    Ta_LB = LB_Out{1} ;
    Ra_LB = LB_Out{2};
    kS_LB = LB_Out{3};
    LPE_LB = LB_Out{4} ;
    RPE_LB = LB_Out{5};
    
    
    Ta_LB_n = zeros(size( Ta_LB));
    Ra_LB_n = zeros(size( Ta_LB));
    LPE_LB_n = zeros(size( Ta_LB));
    RPE_LB_n = zeros(size( Ta_LB));
    
    for i1 = 1:size(P_Mat,1)
        for i2 = 1:size(P_Mat,2)
            Pers = reshape(P_Mat(i1,i2,:),[],1);
            TAN =   reshape(Ta_LB(i1,i2,:),[],1);
            RAN =   reshape(Ra_LB(i1,i2,:),[],1);
            LPEN =   reshape(LPE_LB(i1,i2,:),[],1);
            RPEN =   reshape(RPE_LB(i1,i2,:),[],1);
            
            TAN(TAN  == TAN(1)) = NaN;
            TAN(1) = Ta0;
            TAN(isnan(TAN)) = interp1(Pers(~isnan(TAN)),TAN(~isnan(TAN)),Pers(isnan(TAN)));
            
            Ta_LB_n(i1,i2,:) = TAN(:);
            
            RAN(RAN  == RAN(1)) = NaN;
            RAN(1) = Ra0;
            RAN(isnan(RAN)) = interp1(Pers(~isnan(RAN)),RAN(~isnan(RAN)),Pers(isnan(RAN)));      
            Ra_LB_n(i1,i2,:) = RAN(:);
            
            
            LPEN(LPEN  == LPEN(1)) = NaN;
            LPEN(1) = LPE0;
            LPEN(isnan(LPEN)) = interp1(Pers(~isnan(LPEN)),LPEN(~isnan(LPEN)),Pers(isnan(LPEN)));      
            LPE_LB_n(i1,i2,:) = LPEN(:);

            RPEN(RPEN  == RPEN(1)) = NaN;
            RPEN(1) = RPE0;
            RPEN(isnan(RPEN)) = interp1(Pers(~isnan(RPEN)),RPEN(~isnan(RPEN)),Pers(isnan(RPEN)));      
            RPE_LB_n(i1,i2,:) = RPEN(:);
        end
    end
    
    if i == 1
       FD_Mat_All = FD_Mat;
       FT_Mat_All = FT_Mat;
       P_Mat_All = P_Mat; 
       
       
       TA_Mat_All = Ta_LB_n; 
       RA_Mat_All = Ra_LB_n; 
       kS_Mat_All = kS_LB; 
       LPE_Mat_All = LPE_LB_n;
       RPE_Mat_All = RPE_LB_n; 
       
    else
       FD_Mat_All = cat(2,FD_Mat_All,FD_Mat);
       FT_Mat_All = cat(2,FT_Mat_All,FT_Mat);
       P_Mat_All = cat(2,P_Mat_All,P_Mat);
       
       TA_Mat_All = cat(2, TA_Mat_All ,Ta_LB_n);
       RA_Mat_All = cat(2, RA_Mat_All ,Ra_LB_n);
       kS_Mat_All = cat(2, kS_Mat_All ,kS_LB);
       LPE_Mat_All = cat(2, LPE_Mat_All ,LPE_LB_n);
       RPE_Mat_All = cat(2, RPE_Mat_All ,RPE_LB_n);

    end
    
end

FD_Mat = FD_Mat_All;
FT_Mat = FT_Mat_All;
P_Mat  = P_Mat_All;

LB_Out = {TA_Mat_All,RA_Mat_All, kS_Mat_All,LPE_Mat_All,RPE_Mat_All};


File_Nm = [Dir1,'Validation_Coeff_Mat_full.mat'];
MatFile_NM = strcat(File_Nm);
save(MatFile_NM,'FD_Mat','FT_Mat','P_Mat','TA_Mat_All','RA_Mat_All', 'kS_Mat_All','LPE_Mat_All','RPE_Mat_All','ParamCons');

