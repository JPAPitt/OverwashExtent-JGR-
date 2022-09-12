% ------------------------
%       CreatePaths_Mac
% ------------------------
%
% Authored by Jordan Pitt 20/10/21
%
% link all the relevant directories

function CreatePaths_Mac

path(pathdef)

%Main files
path(path,'..')
path(path,'../Main')
path(path,'../CommonFunctions')
path(path,'../CommonFunctions/Mat2Tikzsrc')

%Qualitative Plots
path(path,'../Qualitative/')

%Extent
path(path,'../Extent/Validation/')
path(path,'../Extent/Core/')
path(path,'../Extent/Maximum_Extent_Individual_Floe/')
path(path,'../Extent/Expected_Overwash_Frequency/')
path(path,'../Extent/Agulhas/')

%Overwash Simulations
path(path,'../Simulation/FirstOrderSlope-SWWE')
path(path,'../Simulation/FirstOrderSlope-SWWE/Core')


return
