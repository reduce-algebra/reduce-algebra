
Comment Test a limit that returns spurious log(-1) terms;

z := int(log(1/x)^2,x);

on factor,complex;

z1 := z;

z2 := limit!-(z1,x,1);

off complex,factor;

z2;

end;

