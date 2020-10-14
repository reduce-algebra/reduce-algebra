
% Catastrophic error during numeric integration
% car of atom with on complex

on factor;

u := 1/(sqrt(sin(x))+sqrt(cos(x)))^4;

load_package numeric;

num_int(u,x=(0.0 .. pi/2.0));

on complex;

num_int(u,x=(0.0 .. pi/2.0));

end;
