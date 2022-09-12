function [y] = jonswapIEE(f,Tp,Hs)


alpha=0.0081; %parameter alfa
beta=1.25; %parameter beta
gamma=3.3; %parameter gamma
g=9.81; %[m/s2]

xa = f*Tp;

sigma       = (xa < 1) * 0.07 + (xa >= 1) * 0.09;

fac1        = alpha*g^2*(2*pi)^-4*f.^(-5);
fac2        = exp (-beta*(xa.^(-4)));

fac3a  = (gamma * ones(size(xa)));
fac3b   = (exp(-0.5.*((xa -1)./sigma).^2));



y = fac1 .* fac2 .* (fac3a.^fac3b);

if ~isempty(Hs)
    y = (y/trapz(f,y))*Hs^2/16; 
end


end



