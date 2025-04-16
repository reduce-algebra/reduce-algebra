lisp;
on echo, comp, pgwd, time;
enable!-errorset(3,3);

symbolic procedure f1(a, b, c);
  print list("result", a, b, c);

symbolic procedure c3;
   << f1('one, 'two, 'three); 'value >>;

c3();

make!-jit 'c3;

c3();
c3();

quit;
