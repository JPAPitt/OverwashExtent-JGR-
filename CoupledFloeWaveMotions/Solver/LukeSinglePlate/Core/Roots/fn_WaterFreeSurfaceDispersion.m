% ------------------------
%     fn_WaterFreeSurfaceDispersion
% ------------------------
% Authored by Jordan Pitt 5/7/21
%
% Wiki Waves function dispersion_free_surface - https://wikiwaves.org/Dispersion_Relation_for_a_Free_Surface
% wrapped with a validation, and with common physical and model variables.
% 
% This wiki waves function solves the free-surface dispersion relationship
% Which has two forms to keep in mind:
% -alpha = k tan( k h) for positive imaginary k, and then infinite real k solutions
% alpha = k tanh(k*h) for positive real k, and then inifinite imaginary k solutions
% the mapping is k -> ik between these two.

function mroots = fn_WaterFreeSurfaceDispersion(PhysVars,ModelVars,N,ValidateFlag)
if ~exist('ValidateFlag','var')  ValidateFlag=false; end

if ~ValidateFlag
    alpha = PhysVars.omega^2 / PhysVars.g;
    mroots = dispersion_free_surface(alpha,PhysVars.h,N,ModelVars.RootFindThreshold);
else
  
  %known answer - check result matches the known answer  (simple parameters)
  TestInformation{1}.name = 'fn_WaterFreeSurfaceDispersion - Simple Parameter Test - Provided Answer';
  TestInformation{1}.metric = @(x) x(1) - 1i;
  TestInformation{1}.function = @dispersion_free_surface;
  TestInformation{1}.tolerance = 10^-12;
  TestInformation{1}.inputs = {((-1 + exp(2))/(1 + exp(2))),1,0,10^-12};

  %known answer - check result satisfies equation
  TestInformation{2}.name = 'fn_WaterFreeSurfaceDispersion - Simple Parameter Test - Solution Check';
  TestInformation{2}.function = @dispersion_free_surface;
  TestInformation{2}.tolerance = 10^-12;
  TestInformation{2}.inputs = {((-1 + exp(2))/(1 + exp(2))),1,0,10^-12};
  TestInformation{2}.metric = @(x) (-1 + exp(2))/(1 + exp(2)) - (x(1)/1i)*1*tanh((x(1)/1i)*1);
  
  %known answer - check result matches the known answer  (parameters match PRSA experiments)
  TestInformation{3}.name = 'fn_WaterFreeSurfaceDispersion - Typical Parameter Test  - Provided Answer';
  TestInformation{3}.metric = @(x) abs(x(1) - 4.45906i);
  TestInformation{3}.function = @dispersion_free_surface;
  TestInformation{3}.tolerance = 10^-5;
  TestInformation{3}.inputs = {(2*pi/0.95)^2/9.81,3.1,0,10^-12};
  
  %known answer - check result satisfies equation (parameters match PRSA experiments)
  TestInformation{4}.name = 'fn_WaterFreeSurfaceDispersion - Typical Parameter Test  - Solution Check';
  TestInformation{4}.function = @dispersion_free_surface;
  TestInformation{4}.tolerance = 10^-12;
  TestInformation{4}.inputs = {(2*pi/0.95)^2/9.81,3.1,0,10^-12};
  TestInformation{4}.metric = @(x) (2*pi/0.95)^2 - (x(1)/1i)*9.81*tanh((x(1)/1i)*3.1);
  
  ntest = 1000;
  TestInformation{5}.name = 'fn_WaterFreeSurfaceDispersion - Typical Parameter Test - Multiple Roots  - Solution Check';
  % rewrote the -alpha = ki*tan(ki*h) to be alpha = k*tanh(k*h) just to
  % demonstrate that it does solve the same equation
  TestInformation{5}.function = @dispersion_free_surface;
  TestInformation{5}.tolerance = ntest*10^-10;
  TestInformation{5}.inputs = {(2*pi/0.95)^2/9.81,3.1,ntest,10^-12};
  TestInformation{5}.metric = @(x) sum((2*pi/0.95).^2 - (x/1i).*9.81.*tanh((x/1i).*3.1));
   
  Valid = fn_Validation(TestInformation);
  if Valid
      
    mroots = 1;
  else
    mroots = NaN;
  end
  
end


end

function mroots = dispersion_free_surface(alpha,h,N,threshold)
% mroots = dispersion_free_surface(alpha,N,h)
% calculates the positive imaginary and N first positive real solutions of -alpha = k*tan(k h)
% -alpha = ki*tan(ki*h) the solution for ki gives the solution alpha^2 = k*tanh (kh)
% for complex alpha. It uses three methods - homotopy for
% starting with alpha =1, guess with linear expansion
% and a linear expansion.
% The first roots is positive imaginary and the next are the first N positive real
% ordered from smallest. 
%
% If the value for h is not given the default value is h = 1;
% This homotopy method can't be non-dimensionalised - relies on known
% solution to simple parameter configuration

% it would be easy to write a much faster program for only real alpha


if nargin == 2
    h = 1;
else
    alpha = h*alpha; % scaling for the solution 
end

%first of all we calculate the root for alpha = 1;
mroots = zeros(1,N+1);

if N ==0 % the N = 0 case does not involve any of the special methods and is treated separately.
    count = 0;
    mroots(count+1) = homotopy(alpha,count,threshold);
else
    
count = 0;
mroots(count+1) = homotopy(alpha,count,threshold);
  count = count + 1;
while 0 <= 1
  %first of all we calculate the root for alpha = 1;
  
  mroots(count+1) = homotopy(alpha,count,threshold);
 if  abs(mroots(count + 1) - (1i*count*pi + alpha/(1i*count*pi))) < 0.01
   %sprintf('Now we can use the close guess')
     while 0 <=1
        mroots(count + 1) = oneroot(alpha,1i*count*pi + alpha/(1i*count*pi),threshold);
        %abs(mroots(count + 1) - (i*count*pi + alpha/(i*count*pi)))
        if abs(mroots(count + 1) - (1i*count*pi + alpha/(1i*count*pi))) < threshold
          % sprintf('Now we can work the rest out easily')
           mroots(count+1:N+1) = 1i*(count:N)*pi + alpha./(1i*(count:N)*pi);
           count = N;
           break
        end
        if count ==N
           break
        end
        count = count + 1;
     end
  end
  
  if count == N
     break
  end
  count = count +1;

end

end

mroots = -1i/h*mroots;mroots(1) = -mroots(1);
end

function mroot = homotopy(alpha,N,threshold)
%calculates the Nth root using the homotopy method

if N == 0
   mroot = oneroot(1,1,threshold);
else
   mroot = oneroot(1,1i*N*pi,threshold);
end

step =0.043;
if abs(alpha) < 1
    alphastep = ([1:-step:abs(alpha),abs(alpha)]);
else
    alphastep = ([1:step:abs(alpha),abs(alpha)]);
end

for k=2:length(alphastep)
        mroot = oneroot(alphastep(k),mroot,threshold);
end


if angle(alpha) > 0
    alphastep = abs(alpha)*exp(1i*[0:pi/30:angle(alpha),angle(alpha)]);
else
    alphastep = abs(alpha)*exp(1i*[0:-pi/30:angle(alpha),angle(alpha)]);
end


for k=2:length(alphastep)
   mroot = oneroot(alphastep(k),mroot,threshold);
end
end
  

function out = oneroot(alpha,guess,threshold)
%calculates the root nearest the root guess.
ans1 = guess+1;
out = guess;
while abs(ans1 - out) > threshold
    ans1 = out;
    out = ans1 - f(ans1,alpha)/difff(ans1);
end
end

function out = f(z,alpha)
out = z*tanh(z) - alpha;
end

function out = difff(z)
out = tanh(z) + z*sech(z).^2;
end



