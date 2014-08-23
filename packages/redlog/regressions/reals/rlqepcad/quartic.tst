% Testing rlcad
% Condition on quartic polynomial being positive semidefinite.

rlset reals;

load_package qepcad;

rlrndseed 13;

quartic := all(x,x**4+p*x**2+q*x+r>=0)$

rlqepcad quartic;

end;
