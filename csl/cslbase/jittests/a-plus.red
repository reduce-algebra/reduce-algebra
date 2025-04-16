lisp;
on echo, comp, pgwd, time;


bytecoded c1;
  (c1 1)
  (loadlit1
   loadlit1
   plus2
   exit);

c1();
jit!-c1();

procedure ff(a, b);
  << "aa"; a+b >>;

ff(1,1);
make!-jit 'ff;
ff(1,1);

quit;
