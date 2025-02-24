% Prototype file for testing JIT compilation. Run using eg sitting in the
% directory where Reduce binaries are built and going
%    ./bootstrapreduce -w jittest.red -l jittest.log
% where jittest.red is a (typically modified) copy of this file.

% I set some options that make any error messages more verbose and
% that cause compilation into bytecode to show the bytes involved.
on echo; lisp; enable!-errorset(3,3); on comp, pgwd;

% Define a test function. The one here is a 6 argument function that
% merely returns its fifth argument. But in testing one will put in
% gradually more exciting things.
symbolic procedure testfn(a, b, c, d, e, f);
  e;

% Call the test function which at this point is bytecoded so that
% its result can be seen and checked.
testfn(1, 2, 3, 4, 5, 6);

% Instruct the system that the next time testfn is called it should
% be JIT compiled.
make!-jit 'testfn;

% This should attempt JIT compilation. If that fails the function drops
% back to being bytecoded.
testfn(1, 2, 3, 4, 5, 6);

% Inspect the "function calls" for testfn. One should report "unknown"
% since it will be JIT-generated code. At some point I may seek a way to
% identify that situation and make the report say "jitcoded-function" or
% some such.
symbol!-fn!-cell 'testfn;

quit;
