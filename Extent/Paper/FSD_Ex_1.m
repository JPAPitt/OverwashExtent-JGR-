clear all;
close all;

ParamCons.DRat = 18/33;
FT = 0.33;
FD = 0.99;


conc = 0.39;
TotalArea = 5;
IceArea = conc*TotalArea;

Floes = [FD,FD,FD];
FloeCS = cumsum(Floes);
FloeCSConc = [2,5-0.99,0];



% subplot(iNum,1,i);
hold on;
b = -0.5;
x = [0,TotalArea,TotalArea,0];
y = [0,0,b,b];
fill(x,y,'b','LineStyle','none')
for i = 1:size(Floes,2)
    
        if i ==1
            Base = 0;
            x = [Base,Base+Floes(i),Base+Floes(i),Base];
            y = [ParamCons.DRat*FT,ParamCons.DRat*FT,-(1-ParamCons.DRat)*FT,-(1-ParamCons.DRat)*FT];
            fill(x,y,'b','LineStyle','none')
%             if Freq_List(i) < TolFac
%                 plot([Base,Base+Floes(i)],[0.1,0.1],'-r','LineWidth',8)
%             end
            fill(x,y,'k','LineStyle','none')
        else
            Base =FloeCSConc(i-1);
            x = [Base,Base+Floes(i),Base+Floes(i),Base];
            y = [ParamCons.DRat*FT,ParamCons.DRat*FT,-(1-ParamCons.DRat)*FT,-(1-ParamCons.DRat)*FT];
%             if Freq_List(i) < TolFac
%                 plot([Base,Base+Floes(i)],[0.1,0.1],'-r','LineWidth',8)
%             end
            fill(x,y,'k','LineStyle','none')
        end
end
xlim([0,5])
ylim([b,0.5])
ylabel('z(m)')
xlabel('x(m)')
title('Floe Example')
matlab2tikz('FSD_Ex_1.tex'); 

% sgtitle(['Jonswap Spectra - Induced Overwash Tp=',num2str(TpTarg),' Hs=',num2str(HsTarg),' FT=',num2str(FT)])


