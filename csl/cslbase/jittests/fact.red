
on time, echo;
lisp;
enable!-errorset(3,3);

on comp, pgwd, time;    % Observe the bytecodes.
!*r2i := nil;           % Supress recursion to iteration optimisation

symbolic procedure fact n;
  if n<2 then 1
  else n*fact sub1 n;


symbol!-fn!-cell 'fact;
fact 20;          % Try while running bytecoded.

make!-jit 'fact;          % Next use should JIT-compile it.
symbol!-fn!-cell 'fact;   % Observe function cell change to confirm.

fact 20;          % Faster??
fact 20;          % The first use did the JIT compilation.

quit;
