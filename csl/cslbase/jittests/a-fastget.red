lisp;
on echo, comp, pgwd, time;

symbol!-make!-fastget('binding, 13);


put('fenris, 'binding, 'glypnir);
v := symbol!-fastgets 'fenris;

bytecoded gg x;
  (gg binding)
  (loadloc0
   fastget 13
   exit);

gg 'fenris;;
jit!-gg 'fenris;

bytecoded gg x;
  (gg binding)
  (loadloc0
   fastget 77
   exit);

gg 'fenris;;
jit!-gg 'fenris;

bytecoded gg x;
  (gg binding)
  (loadloc0
   fastget 141
   exit);

gg 'fenris;;
jit!-gg 'fenris;

bytecoded gg x;
  (gg binding)
  (loadloc0
   fastget 205
   exit);

gg 'fenris;;
jit!-gg 'fenris;

quit;

