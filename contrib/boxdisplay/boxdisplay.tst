linelength 72;

in "boxdisplay.red"$

lisp;

on backtrace$

PrintPrefixForm '(plus a b)$

PrintPrefixForm '(expt (plus a b) 2)$

PrintPrefixForm '(quotient (expt (plus a b) 2) (expt (plus a c) 2))$

PrintPrefixForm '(quotient (minus (expt (plus a b) 2)) (plus a c))$

PrintPrefixForm '(expt (plus (expt a 2) (expt b 2)) 3)$

PrintPrefixForm
  '(int (quotient 1 (sqrt (difference (expt a 2) (expt x 2)))) x)$


share w$

algebraic(
  w := x**2*y**7*a + x**2*y**3*(b + 5) + x*(7*c - 1) + y*(d - 9) + p + 123)$

factor x,y$

PrintPrefixForm prepsq cadr w$

PrintPrefixForm prepsq!* cadr w$



algebraic (w := (a+b)**10);

PrintPrefixForm prepsq cadr w$

PrintPrefixForm list('setq,'w,prepsq cadr w);


algebraic;

vector p1,p2,p3,p4,p5,p6;

w := g(l,p1,p2,p3,p4,p5,p6);

lisp (PrintPrefixForm prepsq cadr w)$

end;
