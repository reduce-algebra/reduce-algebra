
on time, echo;
lisp;
on comp, pgwd;    % Observe the bytecodes.
enable!-errorset(3,3);

global '(blacklist);
blacklist := '();

% Gosh this ia ambitious!
%for each v in oblist() do
%   if not member(v, blacklist) then make!-jit v;


%make!-jit 'errorp;
%make!-jit 'add2resultbuf;
%make!-jit 'errorset*;
%make!-jit 'process-one-reduce-statement;
%make!-jit 'terminalp;
%make!-jit 'add2buflis;
%make!-jit 'update_prompt;
%make!-jit 'tm_setpchar-csl;
%make!-jit 'showtime;
make!-jit 'sinitl;


algebraic;
in "$O/packages/alg/alg.tst";

quit;
