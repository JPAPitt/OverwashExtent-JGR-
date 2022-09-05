clear all;
close all;

load('./RefTransTables/RefTran_LB_AN_T1.mat');
HeightTol = 0.001;
TolFac = 20;

ThickS = reshape(FT_Mat(1,:,1),1,[]);
DiamS = reshape(FD_Mat(:,1,1),1,[]);
DiamS_D = (DiamS(2) - DiamS(1))/2;
DiamSh = DiamS(1:end-1) + DiamS_D;

i1T = 3;

HsTarg = 2;
TpTarg = 8;

TpS = fliplr(reshape(P_Mat(1,1,2:end),1,[]));
FFs = 1./TpS;
JSSpec_Init = jonswapIEE(FFs,TpTarg,HsTarg);
JSSpec_Init = [JSSpec_Init,0];


[Pers,TA,RA,LPE,RPE,FT]= fn_Get_Response_AllDiams(P_Mat,LB_Out,FT_Mat,i1T);

rho = 1e3;
Dmin = 0.1;
gamma1 = 1.15;
gamma2 = 2.5;

figure();


% Num = 5e2;
Num = 1e3;
Dt = ((pi^4*ParamCons.E*FT^3) / (48*rho*ParamCons.g*(1 - ParamCons.nu^2)))^0.25;
[FloesI,Floes,FloeCS] = fn_Get_FloeSample(DiamS,Dmin,Dt,gamma1,gamma2,Num);

FB = ParamCons.DRat*FT;
PlateCond = FB + HeightTol;
% [Freq_List,S_c_n] = fn_Overwash_Spectra_Floes(Pers,TA,RA,LPE,RPE,JSSpec_Init,PlateCond,TolFac,FloesI,Floes,FloeCS,DiamS,'Irreg');

Conc = 0.6;
IceArea = FloeCS(end);
TotalArea = IceArea / Conc;
WaterArea = (1-Conc)*TotalArea;
FloeCSConc = FloeCS + [0:(size(Floes,2)-1)]*WaterArea/size(Floes,2);

% subplot(iNum,1,i);
hold on;
b = -2*FT;
x = [0,IceArea,IceArea,0];
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
xlim([0,100])
ylim([b,1])
ylabel('z(m)')
xlabel('x(m)')
title('Floe Size Distribution')
matlab2tikz('FSD_Ex.tex'); 

% sgtitle(['Jonswap Spectra - Induced Overwash Tp=',num2str(TpTarg),' Hs=',num2str(HsTarg),' FT=',num2str(FT)])


