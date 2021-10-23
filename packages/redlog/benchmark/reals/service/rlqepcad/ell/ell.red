% x-axis ellipse problem

off rlabout;

rlset reals;

ell := all({x,y},b**2*(x-c)**2+a**2*y**2-a**2*b**2=0 impl x**2+y**2-1 <=0);

rlqepcad ell;

end;
