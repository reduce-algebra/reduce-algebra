
% Regression test file for bug report #103:
%  https://sourceforge.net/p/reduce-algebra/bugs/103/
  
f12 := (alpha**2 - 2*alpha*omega + omega**2)/mu;

f22 := ( - alpha**2*beta1 + alpha**2*mu + 2*alpha*beta1*omega + beta1*mu - beta1*omega**2)/mu**2;

eqa := 2*( - alpha*f1**2 - alpha*f2**2 + f2**2*omega);

q3 := ( eqa where { f1 => sqrt(f12), f2 => sqrt(f22) } );

%q3 := ( eqa where { f1 => sqrt(f12)} );

%q3 := ( q3 where { f2 => sqrt(f22) } );

end;
