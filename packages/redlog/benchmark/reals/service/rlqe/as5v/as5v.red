% Testing rlcad
% Convexity of unit square

off rlabout;

rlset reals;

as5v := all({x1,y1,x2,y2},(0<x1<1 and 0<y1<1 and 0<x2<1 and 0<y2<1) impl
all(l, (0<l and l<1) impl (0<x1+l*(-x1+x2)<1 and 0<y1+l*(-y1+y2)<1)))$

rlqe as5v;

end;
