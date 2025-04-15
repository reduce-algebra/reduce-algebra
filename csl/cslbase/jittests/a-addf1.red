
on time, echo;
lisp;
on comp, pgwd;    % Observe the bytecodes.
enable!-errorset(3,3);

make!-jit 'addf;

algebraic;
in "$O/packages/alg/alg.tst";

quit;
