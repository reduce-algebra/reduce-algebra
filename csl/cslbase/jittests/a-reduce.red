
on time, echo;
lisp;
on comp, pgwd;    % Observe the bytecodes.
enable!-errorset(3,3);

% Gosh this ia ambitious!
for each v in oblist() do make!-jit v;


algebraic;
in "$O/packages/alg/alg.tst";

quit;
