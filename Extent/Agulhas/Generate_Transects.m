%% large wave

clear all
close all

Lats =[-63,-60];
Lons =[29 ,31];

%ice concentration
si = ncread('../Inputs/Ant_20170704_res3.125_pyres.nc','sea_ice_concentration');
sila = ncread('../Inputs/Ant_20170704_res3.125_pyres.nc','latitude');
silo = ncread('../Inputs/Ant_20170704_res3.125_pyres.nc','longitude');
si = reshape(si,1,[]);
sila = reshape(sila,1,[]);
silo = reshape(silo,1,[]);
F = scatteredInterpolant(silo',sila',si');
[lox,lay] = meshgrid(Lons(1):0.05:Lons(2),Lats(1):0.05:Lats(2));
sii = F(lox,lay);


%% nc
ncdisp('../Inputs/era5_wave20170704.nc');

la = ncread('../Inputs/era5_wave20170704.nc','latitude');
lo = ncread('../Inputs/era5_wave20170704.nc','longitude');
hs_t = ncread('../Inputs/era5_wave20170704.nc','swh');
tm_t = ncread('../Inputs/era5_wave20170704.nc','mwp');
di_t = ncread('../Inputs/era5_wave20170704.nc','mwd');
time_t = ncread('../Inputs/era5_wave20170704.nc','time');


%Ship track
tll = load('../Inputs/pos.txt');
%dt = 10; %min, ll(:,1) -- hr, ll(:,1) -- min
ll = tll(:,end-1:end);
ll = ll/100;
lams = [floor(ll(:,1)), 100*(ll(:,1)-floor(ll(:,1)))];
loms = [floor(ll(:,2)), 100*(ll(:,2)-floor(ll(:,2)))];
las = dm2degrees(lams);
los = dm2degrees(loms);
ll = [los,-las];
tt0 = [2017 7 4 0 0 0];
tt0 = datenum(tt0);
%
ttv = tt0 + 10/60/24*[0:length(ll)-1];

i8to14am = find(ttv>=datenum([2017 7 4 8 0 0]) & ttv<=datenum([2017 7 4 13 0 0]));  


TimesToFind1 = find(ttv==datenum([2017 7 4 8 0 0]));
TimesToFind2 = find(ttv==datenum([2017 7 4 8 30 0])) ;


%% pl
TransRes = 100;
LatTarg = -61;
LonLBTarg = 27;
LonUBTarg = 31;
LonTargRes = linspace(LonLBTarg,LonUBTarg,TransRes);

LonLBInd_ERA = find(abs(lo - LonLBTarg) < 10^-5);
LonUBInd_ERA = find(abs(lo - LonUBTarg) < 10^-5);

LatInd_ERA = find(abs(la - LatTarg) < 10^-5);

TimeInd = 9;


%peak periods, signficiant wave heights
%Extract I_c along transects
hs_t_time = hs_t(:,LatInd_ERA,TimeInd)';
tp_t_time = tm_t(:,LatInd_ERA,TimeInd)';

Hs_List = interp1(lo,hs_t_time,LonTargRes);
Tp_List = interp1(lo,tp_t_time,LonTargRes);

%Lon - Lat
Lons_SI = LonTargRes.';
Lats_SI = la(LatInd_ERA);

LatLen = 2.5;
Res = 5e3;

Lon_Mat = zeros([size(Lons_SI,1),Res]);
Lat_Mat = zeros([size(Lons_SI,1),Res]);
Dist_Mat = zeros([size(Lons_SI,1),Res]);
IC_Mat = zeros([size(Lons_SI,1),Res]);

%get transects , need to f

MeanWD_Angle = mean(di_t(LonLBInd_ERA:LonUBInd_ERA ,LatInd_ERA,TimeInd));

for i = 1:size(Lons_SI,1)
    Lon_Mat(i,:) = Lons_SI(i) +  linspace(0,LatLen,Res)*cosd(MeanWD_Angle);
    Lat_Mat(i,:) = Lats_SI + linspace(0,LatLen,Res)*sind(MeanWD_Angle);
    Dist_Mat(i,:) = 10^3*deg2km(distance(Lats_SI,Lons_SI(i),Lat_Mat(i,:),Lon_Mat(i,:)));
    IC_Mat(i,:) =  F(Lon_Mat(i,:),Lat_Mat(i,:)) / 100.0;
end

Pos_Mat = ll;
TimeLoc = [TimesToFind1,TimesToFind2];

sii = sii./100;

% contourf(lox,lay,sii, [0:0.1:1],'LineColor','none');
figure();
[lox1,lay1] = meshgrid(lo,la);
contourf(lox1,lay1, hs_t(:,:,TimeInd)','LineColor','none');
hold on;
for i = 1:size(Lon_Mat,1)
    plot(Lon_Mat(i,:),Lat_Mat(i,:),'--k')
end
% plot(Lon_Mat(10,:),Lat_Mat(10,:),'--k')

% caxis([0 1])
cb = colorbar('Location','EastOutside');
cb.Label.String = 'Hs';
plot(ll(:,1),ll(:,2),'-r','linewidth',2)
plot(ll(TimeLoc,1),ll(TimeLoc,2),'.k','linewidth',2)
xlim(Lons), ylim(Lats), grid on
xlabel('Longtitude')
ylabel('Latitude')

MatFile_NM = strcat('../Outputs/Data/Agulhas/AgulDataStore.mat');
save(MatFile_NM,'Lon_Mat','Lat_Mat','Dist_Mat','IC_Mat','Pos_Mat','Hs_List','TimeLoc','Tp_List','lox','lay','sii');