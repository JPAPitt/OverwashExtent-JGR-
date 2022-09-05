% ------------------------
%    fn_Get_Response_AllDiams
%
%
%   Inputs:
%       P_Mat - matrix of periods
%       LB_Out - structure of coefficients (as function of period, diameter, thickness)
%       T_Mat - thickness matrix
%       i2 - thickness index of interest (to pull out)
% 
%   Outputs:
%         Pers - vector of periods
%         TA - T(w,d,h) where h is fixed (thickness fixed) transmission
%         coefficient as function of period/angular frequency and diameter
%         RA - R(w,d,h) - reflection coefficientds
%         LPE - \zeta(w,-L,d,h) - left plate edge coefficient
%         RPE - \zeta(w,L,d,h) - right plate edge coefficient
%         FT - thickness
% 
%  Authored by Jordan Pitt 20/10/21
% ------------------------

function [Pers,TA,RA,LPE,RPE,FT]= fn_Get_Response_AllDiams(P_Mat,LB_Out,T_Mat,i2)

    
    Pers = fliplr(reshape(P_Mat(1,i2,:),1,[]));
        
    TA = fliplr(reshape(LB_Out{1}(:,i2,:),size(T_Mat,1),size(Pers,2)));
    RA= fliplr(reshape(LB_Out{2}(:,i2,:),size(T_Mat,1),size(Pers,2)));
    LPE = fliplr(reshape(LB_Out{4}(:,i2,:),size(T_Mat,1),size(Pers,2)));
    RPE = fliplr(reshape(LB_Out{5}(:,i2,:),size(T_Mat,1),size(Pers,2))); 
    
    FT = T_Mat(1,i2);
        

end