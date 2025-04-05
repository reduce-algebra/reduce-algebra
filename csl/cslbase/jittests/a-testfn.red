% Maybe the start of a proper scheme for checking JIT compilation

lisp;

% A single test case will be presented in the following form:
%     testjit(fname arg1 arg2 ...)
%
% The test procedure will create two versions of a function as in
%    (de testcaseA () "string" (fname arg1 arg2 ...))
% such that each gets trned into bytecodes. The "string" is there to
% prevent the regular CSL comnpiler making testcaseA/B merely a synonym
% for fname. Then one of those will be passed to make!-jit.
%
% Now each function is called. If the results agree with each other then
% all is well. Otherwise a discrepancy has been identified.

on echo;
on comp;
off pwrds;
!*argnochk := nil;

fluid '(failcount);
failcount := 0;

symbolic macro procedure testjit u;
   begin
     scalar ra, rb, vars;
     for each x in cddr u do vars := gensym() . vars;
     on pgwd;
     eval list('de, 'testcaseA, vars, "string", cadr u . vars);
     off pgwd;
     eval list('de, 'testcaseB, vars, "string", cadr u . vars);
     make!-jit 'testcaseB;
     ra := errorset('testcaseA . evlis cddr u, t, t);
     rb := errorset('testcaseB . evlis cddr u, t, t);
     if ra = rb then <<
       princ "Success:";
       print cdr u;
       return nil >>;
     terpri();
     printc "*** Failure ***";
     print cdr u;
     princ "reference: "; print ra;
     princ "with JIT : "; print rb;
     if (failcount := add1 failcount) > 3 then stop 1
  end;

testjit(plus, 1, 1);

testjit(plus, 1, 1);

testjit(sub1, 0);

testjit(plus, 1, 1);

testjit(sub1, 10000000000000000000000);
testjit(sub1, -10000000000000000000000);
testjit(sub1, -10000000000000000000000);
testjit(sub1, "nonnumeric-argument");

testjit(plus, 1, 1);

%testjit(plus, 100000000000000000000, 1);
%testjit(plus, 1, 100000000000000000000);
%testjit(plus, 100000000000000000000, 100000000000000000000);

end;
