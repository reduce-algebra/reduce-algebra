% Testing CAD
% Solotareff's problem (cubic) [Ho92] (in [CJ98], p. 211)

rlset reals;

load_package qepcad;

solo2 := ex({x,y},1<=4*a<=7 and -3<=4*b<=3 and -1<=x<=0 and 0<=y<=1 and
   3*x**2-2*x-a=0 and x**3-x**2-a*x=2*b-a+2 and 3*y**2-2*y-a=0 and
      y**3-y**2-a*y=a-2)$

rlqepcad solo2;

end;
