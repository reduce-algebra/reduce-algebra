% Author: Alan Barnes <Alan.Barnes45678@gmail.com>

psexplim 8;
% expand as far as 8th power (default is 6)

cos!-series:=ps(cos x,x,0);
sin!-series:=ps(sin x,x,0);
atan!-series:=ps(atan x,x,0);
tan!-series:=ps(tan x,x,0);

cos!-series*tan!-series;        % should series for sin(x)
df(cos!-series,x);              % series for sin(x) again

cos!-series/atan!-series;       % should be expanded


tmp:=ps(1/(1+x^2),x,infinity);
df(tmp,x);
ps(df(1/(1+x^2),x),x,infinity);

tmp*x;  % not expanded as a single power series
ps(tmp*x,x,infinity);   % now expanded

ps(1/(a*x-b*x^2),x,a/b);   % pole at expansion point

ps(cos!-series*x,x,2);

tmp:=ps(x/atan!-series,x,0);
tmp1:=ps(atan!-series/x,x,0);
tmp*tmp1;               % should be 1, of course


cos!-sin!-series:=ps(cos sin!-series,x,0);
% cos(sin(x))
tmp:=cos!-sin!-series^2;
tmp1:=ps((sin(sin!-series))^2,x,0);
tmp+tmp1;               % sin^2 + cos^2
psfunction tmp1;
% function represented by power series tmp1

tmp:=tan!-series^2;
psdepvar tmp;
% in case we have forgotten the dependent variable
psexpansionpt tmp;      % .... or the expansion point
psterm(tmp,6);  % select 6th term
psterm(tmp,10); % select 10th term (series extended automtically)

tmp1:=ps(1/(cos x)^2,x,0);
tmp1-tmp;       % sec^2-tan^2

ps(int(e^(x^2),x),x,0); % integrator not called
tmp:=ps(1/(y+x),x,0);
ps(int(tmp,y),x,0);     % integrator called on each coefficient

pscompose(cos!-series,sin!-series);
% power series composition cos(sin(x)) again
cos!-sin!-series;
% should be same as previous result
psfunction cos!-sin!-series;

tmp:=ps(log x,x,1);
tmp1:=pscompose(tmp, cos!-series);
% power series composition of log(cos(x))
df(tmp1,x);     % series for -tan x

psreverse tan!-series;
% should be series for atan x
atan!-series;
tmp:=ps(e^x,x,0);
psreverse tmp;
% NB expansion of log x  in powers of (x-1)

pschangevar(tan!-series,y);

% original series altered by pschangevar (list surgery)
tan!-series; 

tmp := pscopy(cos!-sin!-series); % deep copy
pschangevar(tmp, z);
cos!-sin!-series;

psexplim 20;
 % Produces the power series summation for n=0 to infinity of x**(n*n).
sum!-series1  := pssum(n=0,1,x,0,n*n);
df(sum!-series1,x);
ps(sin(sum!-series1-1) , x, 0);

% Produces the power series expansion of atan(y-1) about y=1.
sum!-series2 := pssum(m=1,(-1)**(m-1)/(2m-1),y,1,2m-1);
ps(tan sum!-series2, y, 1);
ps(int(sum!-series2, y), y, 1);

psexplim 6;
% test new compilation rules for gamma and friends
ps(gamma x,x,1);
ps(psi x,x,1);
ps(gamma x,x,0);
ps(psi,x,-1);
ps(polygamma(3,x),x,0);
ps(gamma(1+x),x,0);
ps(psi(3+x),x,-3);
ps(psi(sin x),x,0);
ps(gamma(-cos x),x,0);

% test new taylor function
pstaylor(tan x,x,0);

% some limited functionality of abs(ps)
abs(sin!-series^2);
abs(cos!-series);

% incorrect/incomplete results were obtained with many of the following inputs
% but now corrected

% bug in abs
abs(cos!-series*sin!-series^2);

% bug in fancy printing of constant power series in big O term
ps(cos x^2+sin x^2, x, 1);

psexplim 3;
tmp := ps(sin(a*x),x,a);
% correct in both versions
tmp1 := df(tmp,a);
psfunction tmp1;

% incomplete/incorrect results obtained with int with variable expansion pt
tmp := ps(int(tmp,a),x,a);
psfunction tmp;

tmp:=ps(sin a*sin x,x,a^3);
% incorrect in previous version
tmp := ps(int(tmp,a),x,a^3);
psfunction tmp;

end;
