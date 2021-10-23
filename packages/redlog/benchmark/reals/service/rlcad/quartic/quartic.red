% Testing rlcad
% Condition on quartic polynomial being positive semidefinite.

off rlabout;

rlset reals;

quartic := all(x,x**4+p*x**2+q*x+r>=0)$

rlcad quartic;

end;
