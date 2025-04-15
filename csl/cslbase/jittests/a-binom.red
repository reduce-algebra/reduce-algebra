lisp;
on echo, comp, pgwd, time;
!*r2i := nil;

symbolic procedure bbb(n, r);
  if r eq 0 or r eq n then 1
  else bbb(n-1, r) + bbb(n-1, r-1);

bbb(5, 3);

make!-jit 'bbb;

bbb(5, 3);
bbb(5, 3);

quit;
