lisp;
on echo, comp, pgwd, time;

symbolic procedure f1(a, b);
  << print list("args are", a, b);
     'value >>;

bytecoded c1;
  (c1 f1 one two)
  (loadlit2
   loadlit3
   call2 1
   exit);

c1();
jit!-c1();

quit;
