% Testing rlcad
% Consistency

rlset reals;

load_package qepcad;

rlrndseed 5;

con := ex({z,x,y},x**2+y**2+z**2<1 and x**2+(y+z-2)**2<1)$

rlqepcad con;

end;
