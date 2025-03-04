
on time, echo;
lisp;
enable!-errorset(3,3);

on comp, pgwd, time;    % Observe the bytecodes.

symbolic procedure lll(x, y);
<<  "string"; x < y >>;

symbol!-fn!-cell 'lll;
lll(27, 18);          % Try while running bytecoded.

make!-jit 'lll;          % Next use should JIT-compile it.
symbol!-fn!-cell 'lll;   % Observe function cell change to confirm.

lll(27, 18);
lll(18, 27);
lll(19, 19);

lll(100000000000000000000027, 100000000000000000000018);
lll(100000000000000000000018, 100000000000000000000027);
lll(100000000000000000000019, 100000000000000000000019);

lll('a, 'b);

quit;
gn
