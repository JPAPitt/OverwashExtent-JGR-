% function fn_halfscreen(hd)
%
% sets the figure to full screen

function fn_halfscreen(hd)

if ~exist('hd','var')
 set(gcf,'Units', 'Normalized', 'OuterPosition', [.15 .15 .7 .7]);
else
 for lp=1:length(hd)
  set(hd(lp),'Units', 'Normalized', 'OuterPosition', [.15 .15 .7 .7]);
 end 
end

return