% This is the "tak" function, widely used as a benchmark back in the days
% when small-case benchmarks were useful. Back then it was normally
% called with arguments (18, 12, 6) and that computed for some while
% before returning. With faster machines I have given if (27, 18, 9)
% which now takes long enough to feel interesting.

% This is set up as a test or demonstration of the experimental JIT
% compiler - which at present can not complete the process of turning
% the bytecodes for tak into real machine code. But by putting thhis file
% here I set that as a target.

on time, echo;
lisp;
enable!-errorset(3,3);

on comp, pgwd, time;    % Observe the bytecodes.

symbolic procedure tak(x, y, z);
  if y < x then tak(tak(x-1, y, z),
                    tak(y-1, z, x),
                    tak(z-1, x, y))
  else z;

symbol!-fn!-cell 'tak;
tak(27, 18, 9);          % Try while running bytecoded.

make!-jit 'tak;          % Next use should JIT-compile it.
symbol!-fn!-cell 'tak;   % Observe function cell change to confirm.

tak(27, 18, 9);          % Faster??
tak(27, 18, 9);          % The first use did the JIT compilation.

% If JIT compilation fails (as it will for some while yet!) the
% function is reset to use just the bytecoded version.

quit;
