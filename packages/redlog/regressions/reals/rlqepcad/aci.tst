% An arithmetic component in an expert system
% Cut without undercutting

rlset reals;

load_package qepcad;

rlrndseed 1;

rlqepcadn(100*10^6);
rlqepcadl(200*10^3);

aci := ex({x,y},0<x and y<0 and x*r-x*tt+tt=x*q-x*s+s and x*b-x*d+d=y*a-y*c+c)$

aciqf := rlqepcad aci;

end;
