
COMMENT Infinite recursion in integration triggered by error in num_int,
        see https://sourceforge.net/p/reduce-algebra/discussion/899364/thread/33f6aac3a2/ ;

x^s;
showrules expt;
load_package numeric;
showrules expt;
on trnumeric; num_int(x**s, x=(0.0 .. 1.0));
showrules expt;

lisp dmode!*;
load_package defint;
off rounded;

int(x**s, x, 0, 1);
on rounded;
int(x**s, x, 0, 1);

end;
