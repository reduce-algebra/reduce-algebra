
lisp;

<< delete!-module 'compiler;
   delete!-module 'ccomp;
   remd 'compile;
   remd 'faslout;
   !*comp := nil;
   initreduce();
   algebraic;
   preserve('begin, "Personal REDUCE 3.6...") >>;

