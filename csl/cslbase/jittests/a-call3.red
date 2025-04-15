lisp;
on echo, comp, pgwd, time;

symbolic procedure f1(a, b, c);
  << print list("args are", a, b, c);
     'value >>;

bytecoded c1;
  (c1 one two three f1)
  (loadlit1
   push
   loadlit2
   loadlit3
   call3 4
   nilexit);

c1();
jit!-c1();

symbolic procedure c2();
  << "haha";
     f1('one, 'two, 'three);
     >>;


c2();
make!-jit 'c2;
c2();

quit;
