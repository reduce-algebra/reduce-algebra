% Hoon Hong, talk at the University of Passau, 20 Dec 2005.

rlset reals;

hong := all(x,ex(y,x**2+x*y+b>0 and x+a*y**2+b<=0))$

rlqe hong;

end;
