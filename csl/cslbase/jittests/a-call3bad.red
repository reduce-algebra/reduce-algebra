lisp;
on echo, comp, pgwd, time;

symbolic procedure f1(a, b, c);
  << print list("args are", a, b, c);
     'value >>;

bytecoded c1;
  (c1 f1 one two three four)
  (loadlit4
   push
   loadlit3
   loadlit2
   call3 1
   exit);

c1();
jit!-c1();

symbolic procedure c2();
  << "haha";
     f1('one, 'two, 'three);
     >>;

symbol!-env 'c2;

c2();
make!-jit 'c2;
c2();

quit;
