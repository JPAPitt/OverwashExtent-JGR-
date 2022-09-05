% clear all;
close all;
% colormap(Col3)

Lats =[-63,-61];
Lons =[29 ,31];

TimeLoc = 49;

load('../Outputs/Data/Agulhas/AgulhasPlot_Fin.mat');

IndexList = 1:size(Lon_Mat,1);

fg1 = figure();
Levels = [0:0.01:1];
Col_Map =  parula(length(Levels)); %Col4; %linspecer(length(Levels));

contourf(lox,lay,sii,[0:0.01:1],'LineColor','none');
colormap(Col_Map)
hold on;

LonEdgeList = zeros(size(IndexList));
LatEdgeList = zeros(size(IndexList));

for i1 = IndexList
LonEdgeList(i1) = Lon_Mat(i1,OWIndices(i1));
LatEdgeList(i1) = Lat_Mat(i1,OWIndices(i1));
plot(Lon_Mat(i1,1:OWIndices(i1)),Lat_Mat(i1,1:OWIndices(i1)),'--k','LineWidth',2)
end

pp = cscvn([LonEdgeList;LatEdgeList]);
bsp = fn2fm(pp, 'B-');
x = linspace(1,length(LonEdgeList),2000);
Points = fnval(pp,x);

caxis([0 1])
cb = colorbar('Location','EastOutside');
cb.Label.String = 'i_c';
plot(Pos_Mat(:,1),Pos_Mat(:,2),'-r','linewidth',2)
plot(Pos_Mat(TimeLoc,1),Pos_Mat(TimeLoc,2),'.g','MarkerSize',10)
plot(Points(1,:),Points(2,:),'--r','linewidth',2)


xlim(Lons), ylim(Lats), grid on
xlabel('Longtitude')
ylabel('Latitude')


fileID = fopen(['../Outputs/Plots/AgulhasPlot.dat','w');
for  i = 1:size(lox,1)
    PrintLin = [lox(i,:); lay(i,:) ; sii(i,:)];
    fprintf(fileID,'%12.8f %12.8f %12.8f\n',PrintLin);
    fprintf(fileID,'\n',[]);
end
fclose(fileID);
% 
cleanfigure;
matlab2tikz('../Outputs/Plots/Agulhas_Fin.tex'); 
