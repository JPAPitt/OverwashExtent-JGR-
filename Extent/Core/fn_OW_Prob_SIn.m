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

function [ProbDists]  =  fn_OW_Prob_SIn(FFs,Trans_Wght,Ta,Ra,LPE,RPE,PlateCond,NumList,Weights,S_In)

    %Frequencies - account for period of 0
    
    ProbDists = zeros(size(NumList));

    for i = 1 : size(NumList,2)
    
        Num = NumList(i);
        
        %Spectra at each Num (x distance)
        S_I = Trans_Wght.^Num .*S_In;
    

        %Moments of incoming spectra
        M0_I =trapz(FFs, S_I);
        M2_I = trapz(FFs,(FFs.^2) .* S_I);

        %Mean period of incoming spectra
        AT_I = sqrt(M0_I ./ M2_I);
        
        
        %have to do all now - all lengths
    
        %matrix of spectra of left and right edges - Diameter x Period
        LPE_S = (abs(1 + Ra - LPE ).^2).*S_I;
        RPE_S = (abs(Ta - RPE ).^2).*S_I;
    
        %Zero and second moments of spectra around left edge of plate at
        M0_L_List =trapz(FFs,LPE_S,2);
        M2_L_List = trapz(FFs,(FFs.^2).*LPE_S,2);
    
        %Mean period of spectra around left edge above the plate condition
        %level (overwash)
        AT_L_List = sqrt(M0_L_List ./ M2_L_List)./ exp(-PlateCond^2 ./ (2.*M0_L_List));
    
        %Zero and second moments of spectra around right edge of plate at
        %each NumListCol 
        M0_R_List =trapz(FFs,RPE_S,2);
        M2_R_List = trapz(FFs,(FFs.^2).*RPE_S,2);
    
        %Mean period of spectra around right edge above the plate condition
        %level (overwash)
        AT_R_List = sqrt(M0_R_List ./ M2_R_List)./ exp(-PlateCond^2 ./ (2.*M0_R_List));
    
        %minimum of the two mean periods of overwash (left and right edge)
        AT_M_List = min([AT_L_List,AT_R_List],[],2);
    
        %Compare relative frequency of overwash vs incoming wave for each NumListCol 
%         Freq_List = min(AT_I./AT_M_List,1);
        Freq_List = AT_I./AT_M_List;
        
        %OverallProb
        %Freq_List - Overwash Frequency
        %Weights - probability of floe in FSD
        
        ProbDists(i) = sum(Weights.*(Freq_List.'));
        
    end


        

end