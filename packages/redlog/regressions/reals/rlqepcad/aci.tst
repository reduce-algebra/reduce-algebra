% An arithmetic component in an expert system
% Cut without undercutting

off rlabout;

rlset reals;

aci := ex({x,y},0<x and y<0 and x*r-x*tt+tt=x*q-x*s+s and x*b-x*d+d=y*a-y*c+c)$

aciqf := rlqepcad aci;

end;
