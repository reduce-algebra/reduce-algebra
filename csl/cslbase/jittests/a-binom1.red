lisp;
on echo, comp, pgwd, time;
!*r2i := nil;
!*notailcall := t;

symbolic procedure mysub1 u;
 << optterpri(); princ "sub1 "; print u;
    sub1 u >>;

symbolic procedure myplus2(a, b);
 << optterpri(); princ "plus2 "; prin a; princ " "; print b;
    a+b >>;

symbolic procedure bbb(n, r);
  if r eq 0 or r eq n then 1
  else myplus2(bbb(mysub1 n, r), bbb(mysub1 n, mysub1 r));

bbb(5, 3);

make!-jit 'bbb;

bbb(5, 3);
bbb(5, 3);

quit;
