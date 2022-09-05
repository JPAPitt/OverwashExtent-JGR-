function [Ef,Beta,Tp] = fn_gJS(f,Hs,Tp,U10,gamma,n)

g = 9.81;

if isempty(Tp)
    
   % NonDimEnergy  = g^2*ETot / U10^4;
   % NonDimPer = fp* U10 / g;
   %Donelan 1985 relationship
%    NonDimEnergy  = 6.365e-6 * (NonDimPer).^(-3.3)

    Coeff = 16* 6.365e-6 * U10^0.7 * g^(1.3);
    Tp = ( (1 / Coeff) * Hs^2 ) ^ (1/3.3);
    
end


%Using  Donelan - 1985. Young shows some differences, in his fits. But
%agreement is decent,

g = 9.81;
% InvWaveAge = U10 / Cp;
% Beta = 0.006*InvWaveAge^0.55;
% n = -4;
% gamma = 1.7;


ETot = (Hs / 4) ^2;
fp = 1./ Tp;





Coeff_T1 = g^2*(2*pi)^(-4) *fp^(-(5 + n));

sigma       = (f <= fp) * 0.07 + (f > fp) * 0.09;

GammaTerm = gamma.^exp(- (f - fp).^2 / (2*sigma.^2 * fp.^2));


Ef = Coeff_T1 .* (f.^n) .* exp(n/4 * (f./fp).^(-4))  .* GammaTerm;

NormInt = trapz(f,Ef);

Ef = (Ef/NormInt)*ETot; 

Beta = ETot / NormInt;

end



