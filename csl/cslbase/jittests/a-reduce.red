%
% A general strategy for testing for the next week or so:
%   Start by running Reduce with every function marked for JIT compilation.
%   Expect a crash! Note tha last function that was processed by the JIT
%   before that.
%   Set up a script that instead of compiling everything compiles just the
%   functions processed up to and including that one. By carving out subsets
%   of that try to identify a single functions whose compilation causes
%   trouble. Put its sourcecode here so that the bytestream it turns into
%   is better displayed. Adjust it to insert print statements that show
%   progress and internal values. Hope that that makes it possible or even
%   easy to narrow down the precise issue...
%   Rinse and repeat.
%


on time, echo;
lisp;
on comp, pgwd;    % Observe the bytecodes.
enable!-errorset(3,3);

global '(blacklist);
blacklist := '();

% Gosh this is ambitious!
for each v in oblist() do
   if not member(v, blacklist) then make!-jit v;


algebraic;
in "$O/packages/alg/alg.tst";

quit;
