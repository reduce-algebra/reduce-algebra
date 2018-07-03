
load numeric;

depend(x,t);

num_odesolve(df(x,t)=x, x=0, t=(0 .. pi));

end;
