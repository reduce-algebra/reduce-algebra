							  ESL README
							  ==========

Version 2: ESL as an upper-case Lisp
====================================

To keep things as simple as possible, work with the files in

https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/historical/r33/

Try to get boot.sl to work first. Then I can try to build REDUCE 3.3!

dbuild.sl orchestrates building REDUCE. It inputs boot.sl, prolog.red,
rlisp.red, rend.red (in that order) to build RLISP, then continues to
build REDUCE.

I have edited boot.sl as boot.el to use upper case, replaced % with ;
and ! with \ where necessary so that Emacs Lisp can read it.

I have defined a few additional functions that are assumed by REDUCE
but not defined in Standard LISP at the end of sl.el.

sl.el and boot.el now compile cleanly and seem to run.

Provided I increase max-lisp-eval-depth to 2000 and max-specpdl-size
to 2500 to handle module slfns, I can read the original REDUCE 3.3
version of "rlisp.red", and I can also read a version of "rend.red"
revised for ESL, by evaluating:

(load-file "boot.elc")
(BEGIN2)
rds open("rlisp.red",'input);
(BEGIN2)
rds open("rend.red",'input);
(INITREDUCE)

The above interactive input produces the output

REDUCE 3.3, 22-Jan-2018 ...

1: 
1: 
1: 
1: 
1: Entering LISP ... 

and re-evaluating (INITREDUCE) reliably produces the output

REDUCE 3.3, 22-Jan-2018 ...

1: Entering LISP ... 

