lisp;
on echo, comp, pgwd, time;

symbolic procedure f1 a;
  << print list("arg is", a);
     'value >>;

bytecoded c1;
  (c1 f1 one)
  (loadlit2
   call1 1
   exit);

c1();
jit!-c1();

quit;
