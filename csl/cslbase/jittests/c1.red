lisp;
on echo, comp, pgwd, time;

symbolic procedure f1 a;
  print list("result", a);

symbolic procedure c1;
   << f1 'one; 'two >>;

c1();

make!-jit 'c1;

c1();
c1();

quit;
