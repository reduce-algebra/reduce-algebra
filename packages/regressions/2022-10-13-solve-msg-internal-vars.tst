
COMMENT Bug report #148 Stange output(!solvevar0001) in solve (part 2)
        https://sourceforge.net/p/reduce-algebra/bugs/148/

        Internal call to solve0 without variable list causes a messagei
        "Unknown: !!solveevar0001" to be printed
        ;

a:=solve({xx^(5/7) = 216}, {xx});
on complex;
a;

end;
