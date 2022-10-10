
COMMENT Bug report:
        https://sourceforge.net/p/reduce-algebra/bugs/147/

        After loading the defint package a call to solve leads to a zero divisor

        ;

% This works
solve(x^(1/3)=i,x);

int(x,x,0,1);

% But this led to a zero divisor error
solve(x^(1/3)=i,x);

end;
