
on time, echo;
lisp;
enable!-errorset(3,3);

on comp, pgwd, time;    % Observe the bytecodes.

symbolic procedure mysub1 x;
<<  "string"; sub1 x  >>;

symbol!-fn!-cell 'mysub1;
mysub1 18;

make!-jit 'mysub1;          % Next use should JIT-compile it.
symbol!-fn!-cell 'mysub1;   % Observe function cell change to confirm.

mysub1 18;

mysub1 100000000000000000000018;

mysub1 'b;

quit;

