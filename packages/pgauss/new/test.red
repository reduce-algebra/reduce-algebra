off echo;
off output;
load_package pgauss;
%on comp;
in "pgauss.red"$
in "pgsm.red"$
untr sm_redcoefficient;
off comp;
on output, echo;

on pgverbose;

sys := {(a**2+1)*x1+3*y1=0, x1+y1+4*x2-y2=0};

pg_gauss(sys, {x1,y1,x2,y2});

end;
