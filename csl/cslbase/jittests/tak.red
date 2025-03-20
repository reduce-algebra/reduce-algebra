% This is the "tak" function, widely used as a benchmark back in the days
% when small-case benchmarks were useful. Back then it was normally
% called with arguments (18, 12, 6) and that computed for some while
% before returning. With faster machines I have given if (3, 2, 1)
% which now takes long enough to feel interesting.

% This is set up as a test or demonstration of the experimental JIT
% compiler - which at present can not complete the process of turning
% the bytecodes for tak into real machine code. But by putting thhis file
% here I set that as a target.

on time, echo;
lisp;
enable!-errorset(3,3);

on comp, pgwd, time;    % Observe the bytecodes.

symbolic procedure mylessp(a, b);
 << print list("<", a, b, (a<b));
    flush();
    a<b >>;

symbolic procedure mysub1 a;
 << print list("1-", a, sub1 a);
    flush();
    sub1 a >>;

symbolic procedure myprint z;
  print list("result", z);

symbolic procedure tak(x, y, z);
  if mylessp(y, x) then tak(tak(mysub1 x, y, z),
                            tak(mysub1 y, z, x),
                            tak(mysub1 z, x, y))
  else << myprint z; z >>;

symbol!-fn!-cell 'tak;
tak(3, 2, 1);          % Try while running bytecoded.

make!-jit 'tak;          % Next use should JIT-compile it.
symbol!-fn!-cell 'tak;   % Observe function cell change to confirm.

tak(3, 2, 1);          % Faster??
tak(3, 2, 1);          % The first use did the JIT compilation.

% If JIT compilation fails (as it will for some while yet!) the
% function is reset to use just the bytecoded version.

quit;
