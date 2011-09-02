%
% "ndotest.red"
%     This runs one of the REDUCE test files and collects the output in a
%     log file with timing information appended. It is for use with CSL-based
%     versions of REDUCE and should be invoked as
%         r36 -b ndotest.red -Dname=xxx -Dloadup=yyy -- xxx.log
%     where xxx is the name of the test file, and yyy a package to be
%     loaded first. The "-Dloadup=yyy" should be omitted if the module to be
%     tested forms part of the code of REDUCE.  Almost always this script
%     will be invoked from either the "makefile" or an equivalent batch file.
%

on errcont$   % So that computation continues after an error.

symbolic <<
   if boundp 'loadup then
       errorset(list('load!-package, mkquote compress explodec loadup),
                nil, nil);
   !*mode := 'algebraic;
   test!-time := time();
   test!-gctime := gctime();
   errorset(list('in1, mkquote format(nil, "../xmpl/~a.tst", name), t),
            t, t);
   test!-time := difference(time(), test!-time);
   test!-gctime := difference(gctime(), test!-gctime);
% first the time exclusive of GC overheads, then inclusive
   prin2t list("TIME: ", name, test!-time, test!-time+test!-gctime);
   if member('record_get, lispsystem!*) then bytecounts()
>>;

bye;

