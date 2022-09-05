%Example of linear part of overwash model

close all;
clear all;

% Tp = 0.95;
% 
% Amps = 0.005:0.005:0.04;
% % Facs = 1:-0.1:0;

Tp = 0.9;

Amps = 0.005:0.005:0.05;
plateaboveFac = 1;

StrFile = strcat('T',num2str(round(10*Tp),'%02d'),'tsm_noblack.fig');
uiopen(StrFile,1)

NEWT = zeros(length(Amps),20) ;
TimeRecs = zeros(length(Amps),20,2);
Freeboards = zeros(length(Amps),20,3);


IndexL1 = 1;
% for  plateaboveFac  = Facs
    
    IndexL2 = 1;
for Amp = Amps
    
    abovefacname = num2str(round(plateaboveFac,6));
    ampname = num2str(round(Amp,6));
    periodname = num2str(round(Tp,6));
    
    MatFile_NM = strcat('/Volumes/Storage/OW-Analysis/Depth/DavidTrans/OW_',ampname,'_',periodname,'.mat');
    
    Mat = load(MatFile_NM); 

    
    T = Mat.T;
    NEWT(IndexL2) = min(Mat.NewTrans1);
    k = Mat.k;

    
    IndexL2 = IndexL2 + 1;
end



Kamps = k.*Amps;
LW = 3;


hold on;
clear PlotNames;
PlotNames = {'','','','',''};

plot(Kamps,(T^0.5).*Kamps,'--k','LineWidth',LW);
pname = 'Linear Model';
PlotNames{end +1} = pname;


plot(Kamps,((NEWT.^0.5).').*Kamps,'-','LineWidth',LW);
pname = ['NEw'];
PlotNames{end +1} = pname;



xlabel('ka in');
ylabel('ka out');
title(['Tp = ',num2str(Tp),' Transmission Curves - With Dynamic Freeboard']);
legend(PlotNames);




