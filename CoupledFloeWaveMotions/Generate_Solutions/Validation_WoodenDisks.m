% ------------------------
%       Validation_WoodenDisks
% ------------------------
%
%  Authored by Jordan Pitt 20/10/21
%
% Produce matrices to use in the overwash model - T(w,L,d) , R(w,L,d) , \zeta(w,0,L,d), \zeta(w,L,L,d)
% these wil be used by the overwash + transmission model to predict extents
%
% In this example we choose floe parameters consistent with Bennetts and
% Williams 2015 

close all;
clear all;


%Periods T to use as the angular frequency w = 2*pi/T, to solve the
%coefficients for
Model_Pers = 0.3:0.02:15;

%Model parameters - using Luke's model
th_res=100;
SURGE=1;
terms_grn=100;
extra_pts=[];     
rigid = 4; 
n=100; %number of eigenvalues

%Physical parameters
Param = ParamDef_Oceanide(rigid); 
Param = ModParam_def(Param,1,n,extra_pts,terms_grn,th_res); 

PhysVars.g = Param.g;
PhysVars.h = Param.bed;

plateabove=Param.thickness*(1-Param.rho/Param.rho_0);

ModelVars.RootFindThreshold = 10^-12; 
ModelVars.nWaterTerms = 20; 
ModelVars.RootFindMaxIteration = 100;

L = Param.floe_diam/2;

ParamCons.IceRho = Param.rho;
ParamCons.E = Param.E;
ParamCons.bed = Param.bed;
ParamCons.FD = 2*L;
ParamCons.FT = Param.thickness;
ParamCons.g = Param.g;
ParamCons.nu = Param.nu;
ParamCons.DRat = (1-Param.rho/Param.rho_0);

Ta = [];
Ra = [];
LPE = [];
RPE = [];
kS = [];

%Loop over periods and solve for the coefficients
for Model_Per = Model_Pers
    

    out = fn_ElasticRaft2d('freq',1./Model_Per,Param,'disk',SURGE,0,0,1,0,'r',[-L,L]);
    TN = (out(1).value);
    RN = (out(2).value);
    Plate = out(3).value;
    k = out(4).value;
    
    
    Ta = [Ta,TN];
    Ra = [Ra,RN];
    kS = [kS,k];
    LPE = [LPE,Plate(1)];
    RPE = [RPE,Plate(2)];
    

end

PhysVars.omega = 2*pi/100;
klong = fn_WaterFreeSurfaceDispersion(PhysVars,ModelVars,0);

%Add limit values for small and large periods
Model_Pers = [0,Model_Pers,100];
Ta = [0,Ta,1];
Ra = [1,Ra,0];
LPE = [0,LPE,1];
RPE = [0,RPE,1];
kS = [Inf,kS,klong/1i];



%Write matrices out
LB_Out = {Ta,Ra,kS,LPE,RPE};

MatFile_NM = strcat('../Outputs/Data/CoefficientMatrices/Validation.mat');
save(MatFile_NM,'Model_Pers','LB_Out','ParamCons');

