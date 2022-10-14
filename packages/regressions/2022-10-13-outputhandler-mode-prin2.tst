
COMMENT Bug report #148 Stange output(!solvevar0001) in solve
        https://sourceforge.net/p/reduce-algebra/bugs/148/

        Caused by commit 3006 which introduced calls to outputhandler!* with prin2!* as mode
        ;

#if (and (not (member 'tmprint loaded!-packages!*)) (not (getd 'linelength!-orig)))
%#if (not (member 'tmprint loaded!-packages!*))
load_package tmprint$
linelength 5000$
#endif

on fancy;

solve(x^2-1);

off fancy;

load fmprint;

on fancy;

solve(x^2-1);

off fancy;

end;
