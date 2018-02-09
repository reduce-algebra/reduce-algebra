						  ESL REDUCE README
						  =================

Version 2: ESL as an upper-case Lisp

To keep things as simple as possible, work with the files in

https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/historical/r33/

Having got boot.sl to work, then I can try to build REDUCE 3.3!

dbuild.sl orchestrates building REDUCE. It inputs boot.sl, prolog.red,
rlisp.red, rend.red (in that order) to build RLISP, then continues to
build REDUCE. I don't currently use prolog.red.

I have edited boot.sl as boot.el to use upper case, replaced % with ;
and ! with \ where necessary so that Emacs Lisp can read it. However,
I keep lambda lower case by giving it newnam and quotenewnam
properties. (Both are needed.)

I have defined a few additional functions that are assumed by REDUCE
but not defined in Standard LISP at the end of sl.el.

sl.el and boot.el now compile cleanly and seem to run.

(However, to use the uncompiled boot.el file, I need to increase
max-lisp-eval-depth to 2000 and max-specpdl-size to 2500 to handle
module slfns.)


I can now build RLISP 3.3 in the current Emacs session and run it as
follows:

1. Load sl.elc and boot.elc.

2. Run M-x STANDARD-LISP

3. After the appropriate prompt in the minibuffer, enter each of the
following lines of input. The Lisp syntax is read as Emacs Lisp using
(read) and the REDUCE syntax is read using READCH.

(BEGIN2)
rds open("rlisp.red",'input);
(BEGIN2)
rds open("rend.red",'input);
(INITREDUCE)

This gives the appropriate output in the *Standard LISP* buffer, namely

REDUCE 3.3, 25-Jan-2018 ...

1: <read input from the minibuffer>

<output 1>

2: <read input from the minibuffer>

<output 2>

etc.

n: quit;

This interaction model with output to a normal buffer and input from
the minibuffer is not very elegant, but it seems to work and is a
fairly painless way to make Emacs wait for input.

The RLISP foreach and lambda statements now work. (They both rely on
lambda, which I think nor works reliably.)

However, the output ends up the *Messages* buffer, which I still need
to fix reliably.

(BEGIN2)
rds open("arith.red",'input);

seems to work, albeit rather slowly, but REDUCE code is still
interpreted and I need to think about trying to compile it!
