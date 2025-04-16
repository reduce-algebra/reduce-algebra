% This is the "tak" function, widely used as a benchmark back in the days
% when small-case benchmarks were useful. Back then it was normally
% called with arguments (18, 12, 6) and that computed for some while
% before returning. However these days I need a yet larger set of argument
% values to get the timing above mere milliseconds.

% This is set up as a test or demonstration of the experimental JIT
% compiler.

on time, echo;
lisp;
on comp, pgwd;    % Observe the bytecodes.


symbolic procedure tak(x, y, z);
  if lessp(y, x) then tak(tak(sub1 x, y, z),
                          tak(sub1 y, z, x),
                          tak(sub1 z, x, y))
  else z;

symbol!-fn!-cell 'tak;
tak(27, 18, 9);          % Try while running bytecoded.

make!-jit 'tak;          % Next use should JIT-compile it.
symbol!-fn!-cell 'tak;   % Observe function cell change to confirm.

tak(27, 18, 9);          % Faster??
tak(27, 18, 9);          % The first use did the JIT compilation.

quit;
