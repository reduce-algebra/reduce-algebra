
%
% Test against a bug in nested rule application
%

operator f;

let { f(~x,~x) => x when ((ratnump rp and rp>1) where rp => repart(x*x)) };

f(cos(a+sqrt(3)/2*pi),cos(a+sqrt(3)/2*pi));


end;
