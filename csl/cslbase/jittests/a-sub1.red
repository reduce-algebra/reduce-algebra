lisp;
on echo, comp, pgwd, time;

symbolic procedure f1 a;
  << print list("arg is", a);
     'value >>;

bytecoded c1 n;
  (c1 f1)
  (loadloc 0
   sub1
   call1 1
   exit);

c1 100;
jit!-c1 100;

c1 10000000000000000000000000000;
jit!-c1 10000000000000000000000000000;

quit;

