% x-axis ellipse problem

rlset reals;

load_package qepcad;

rlrndseed 7;

rlqepcadn(100*10^6);
rlqepcadl(200*10^3);

ell := all({x,y},b**2*(x-c)**2+a**2*y**2-a**2*b**2=0 impl x**2+y**2-1 <=0);

rlqepcad ell;

end;
