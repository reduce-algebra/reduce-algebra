% Testing rlcad
% Consistency

rlset reals;

con := ex({z,x,y},x**2+y**2+z**2<1 and x**2+(y+z-2)**2<1)$

rlqepcad con;

end;
