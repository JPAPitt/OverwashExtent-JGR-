% ------------------------
%    fn_OWEx_WaveProps
%   Inputs:
%             Per -vector of periods
%             Trans_Wght- T_FSD(w) - gives the spectral response after N
%             disks like so S(w,N) = T_FSD(w).^N * S(w) 
%             Ta - Transmission coefficient (function of period(Per) and diameter)
%             Ra - Reflection coefficient (function of period(Per) and diameter)
%             LPE - Left plate edge coefficient (function of period(Per) and diameter)
%             RPE - Right plate edge coefficient (function of period(Per) and diameter)
%             PlateCond - height waves have to cross to be overwashing
%             TolFac - tolerance on frequency to be considered overwashing
%             NumList - list of number of floes (beloning to FSD) to use to test if disk
%             overwashes 
%             iD1 - diameter of interest for overwash
%             Tp - peak period of interest
%             HsTargs - list of significant wave heights to investigatr
% 
%   Outputs:
%         MaxDistFloeSize - The maximum number of floes after which the floe of interest was overwashed for each incoming significant
%         wave height
% 
%  Authored by Jordan Pitt 20/10/21
% ------------------------

function [MaxDistFloeSize]  =  fn_OWEx_WaveProps_SI(FFs,Trans_Wght,Ta,Ra,LPE,RPE,PlateCond,TolFac,NumList,iD1,S_I)


%     %zero output
%     MaxDistFloeSize = zeros(1,size(HsTargs,2));
    
    %Make sure things are right shape to produce correct results
    NumListCol = reshape(NumList,length(NumList),1);
    
    %loop over significant wave heights of incoming spectra
%     for iH = 1:size(HsTargs,2)
        
%         %Spectra at each NumListCol
% %         S_I = jonswapIEE(FFs,Tp,HsTargs(iH));
%         U10 = 11;
% 
%         [S_I,Beta,Tp] = fn_gJS(FFs,HsTargs(iH),[],U10);

        S_c_mat = Trans_Wght.^repmat(NumListCol, 1, size(Trans_Wght,2)).*S_I;
        
        
        %Overwash Model
        
        %Moments of incoming spectra at each NumListCol
        M0_I_List =trapz(FFs,S_c_mat,2);
        M2_I_List = trapz(FFs,(FFs.^2) .*S_c_mat,2);
    
        %Mean period of incoming spectra at each NumListCol
        AT_I_List = sqrt(M0_I_List./ M2_I_List);
    
        % Spectra around left and right edge of plates at each NumListCol 
        LPE_S_c_n = (abs(1 + Ra(iD1,:) - LPE(iD1,:) ).^2).*S_c_mat;
        RPE_S_c_n = (abs(Ta(iD1,:) - RPE(iD1,:) ).^2).*S_c_mat;
    
        %Zero and second moments of spectra around left edge of plate at
        %each NumListCol 
        M0_L_List =trapz(FFs,LPE_S_c_n,2);
        M2_L_List = trapz(FFs,(FFs.^2).*LPE_S_c_n,2);
    
        %Mean period of spectra around left edge above the plate condition
        %level (overwash)
        AT_L_List = sqrt(M0_L_List ./ M2_L_List)./ exp(-PlateCond^2 ./ (2.*M0_L_List));
    
        %Zero and second moments of spectra around right edge of plate at
        %each NumListCol 
        M0_R_List =trapz(FFs,RPE_S_c_n,2);
        M2_R_List = trapz(FFs,(FFs.^2).*RPE_S_c_n,2);
    
        %Mean period of spectra around right edge above the plate condition
        %level (overwash)
        AT_R_List = sqrt(M0_R_List ./ M2_R_List)./ exp(-PlateCond^2 ./ (2.*M0_R_List));
    
        %minimum of the two mean periods of overwash (left and right edge)
        AT_M_List = min([AT_L_List,AT_R_List],[],2);
    
        %Compare relative frequency of overwash vs incoming wave for each NumListCol 
        Freq_List = AT_M_List./ AT_I_List;
        
        %Find maximum number of disks transmitted through in FSD which results in
        %overwash of the floe of interest
        Ind=  find(Freq_List < TolFac ,1,'last');
        
        if isempty(Ind)
            Ind =1;
        end
         
        MaxDistFloeSize = NumList(Ind);
        
        
%     end


        

end