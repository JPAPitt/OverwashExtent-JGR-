% ------------------------
%    fn_OWEx_WaveProps
%   Inputs:
%             Per -vector of periods
%             Weights - Probability that diameter turns up in sample FSD
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
%             LongAttn - long wave attenuation flag
% 
%   Outputs:
%         MaxDistFloeSize - The maximum number of floes after which the floe of interest was overwashed for each incoming significant
%         wave height
% 
%  Authored by Jordan Pitt 20/10/21
% ------------------------

function [Trans_Wght]  =  fn_FSD_Transmission(Per,Weights,Conc,Davg,Ta,LongAttn)
    WeightCol = reshape(Weights,length(Weights),1);
    
    %Produce Transmission Model - based on FSD
    % In this one we take T_FSD(w) = prod_i (abs(T(w,Diams(i))).^2).^(Probability of Diams(i) in FSD)
    TransPow = (abs(Ta).^2).^repmat(WeightCol, 1, size(Ta,2));
    Trans_Wght = prod(TransPow,1);
    Trans_Wght = Trans_Wght.^(Conc/Davg);


    %Add long wave attenuation to Trans_Wght
    if LongAttn
        
        %Coefficients of long wave attenuation Mike Meylan
        c1 =2.12*10e-3;
        c2 = 4.59*10e-2;
        Alpha = -log(Trans_Wght);
        AlphaLong = c1.*(Per).^(-2) + c2.*(Per).^(-4)  ;
        Intersection = log(Alpha) - log(AlphaLong);
        
        Trans_Wght = Trans_Wght.*exp(-AlphaLong);
        IntIndx = find(Intersection > 0,1,'first');
        if isempty(IntIndx)
            Trans_WghtO = exp(-Alpha);
        else
            Trans_WghtO = [exp(-AlphaLong(1: IntIndx)),Trans_Wght( IntIndx+1:end)];
        end
        
        figure()
        loglog(Per,Alpha,'-k')
        hold on;
        loglog(Per,AlphaLong,'-b')
        loglog(Per,-log(Trans_Wght),'-r')
         loglog(Per,-log(Trans_WghtO),'-g')
         
        figure()
        plot(Per,exp(-Alpha),'-k')
        hold on;
        plot(Per,exp(-AlphaLong),'-b')
        plot(Per,Trans_Wght,'-r')
         plot(Per,Trans_WghtO,'-g')
%
        
%         figure()
%         loglog(Per,Alpha)
%         hold on;
%         loglog(Per,AlphaLong)

        
%         %Does the scattering model FSD transmission intersect with long
%         %wave?
     
        if isempty(IntIndx)
            Trans_Wght = exp(-Alpha);
            
            figure()
            loglog(Per,Alpha,'-k')
            hold on;
            loglog(Per,AlphaLong,'-b')
            loglog(Per,-log(Trans_Wght),'-r')
            loglog(Per,Alpha + AlphaLong,'-g')
        else
            %If both interesect, just use long wave attenuation after
            %intersection
            Indx = IntIndx;
            Trans_Wght = [exp(-AlphaLong(1:Indx)),Trans_Wght(Indx+1:end).^(Conc/Davg)];
            
            figure()
            loglog(Per,Alpha,'-k')
            hold on;
            loglog(Per,AlphaLong,'-b')
            loglog(Per,-log(Trans_Wght),'-r')
            loglog(Per,Alpha + AlphaLong,'-g')
%             
%             figure()
%             plot(Per,Trans_Wght)
        end
    end

           
        

end