
Comment Test a limit that returns spurious log(-1) terms when factor is on.

What happens is that a term

  log(1-eps^2) 

is expanded to

  log(((-1)*(eps - 1) * (eps + 1))  -->   log(-1) + log(eps - 1) * log(eps + 1)

when precise is off and expandlogs is on.

As eps goes to 0, the original term is log(1)=0, but the expanded term is

  2*log(-1) = 2*i*pi

;


z := int(log(1/x)^2,x);

z2 := limit!-(z,x,1);

on factor;

z1 := z;

z2 := limit!-(z1,x,1);

off factor;

z2;

Comment The underlying reason is this behaviour;

off precise;
on expandlogs;
on factor;

log(eps*(1-eps^2))-log(eps);
sub(eps=0,ws);

end;

