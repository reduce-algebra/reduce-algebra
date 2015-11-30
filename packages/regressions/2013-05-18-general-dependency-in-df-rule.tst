%
% Test for general dependency in df rule
%  Tony Roberts May 2013
%

let df(pp,x(~j))=>pp(j);
thisisok:=df(pp^2,x(1));
shouldbezero:=df(pp^2,t);

for j:=1:2 do depend pp,x(j);

thisisok:=df(pp^2,x(1));
shouldbezero:=df(pp^2,t);

end;
