Comment Do not allow to use the same identifier for an algebraic procedure and an operator,
        and vice versa;

algebraic procedure fn1(x);
    "1";
algebraic operator fn1;

fn1 a;

get('fn1,'simpfn);
flagp('fn1,'opfn);

clear fn1;

algebraic operator fn1;

fn1 a;

end;

% Vice versa case needs more thinking.....


operator op1;

algebraic procedure op1; 1;

op1 x;

get('op1,'simpfn);
flagp('op1,'opfn);

end;
