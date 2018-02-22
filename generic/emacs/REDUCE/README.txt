						  ESL REDUCE README
						  =================

Version 2: ESL as an upper-case Lisp

To keep things as simple as possible, work with the files in

https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/historical/r33/

Having got boot.sl to work, I can now try to build REDUCE 3.3!

dbuild.sl orchestrates building REDUCE. It inputs boot.sl, prolog.red,
rlisp.red, rend.red (in that order) to build RLISP, then continues to
build REDUCE. I don't currently use prolog.red.

I have edited boot.sl as boot.el to use upper case, replaced % with ;
and ! with \ where necessary so that Emacs Lisp can read it. However,
I keep lambda lower-case by giving LAMBDA newnam and quotenewnam
properties. (Both are needed.) I do the same for NIL and T, although
neither seems to be strictly necessary.

I have defined a few additional functions that are assumed by REDUCE
but not defined in Standard LISP at the end of sl.el.

sl.el and boot.el now compile cleanly and seem to run.  (However, to
use the uncompiled boot.el file, I need to increase
max-lisp-eval-depth to 2000 and max-specpdl-size to 2500 to handle
module slfns.)

Moreover, setting *COMP non-nil now causes REDUCE procedures to be
compiled as they are read, which causes REDUCE syntax to input *very
much* faster!

I can now build the main modules of REDUCE 3.3 in the current Emacs
session and run it as follows:

1. Load sl.elc and boot.elc.

2. Run M-x STANDARD-LISP

3. After the appropriate prompt in the minibuffer, enter each of the
following lines of input separately. The Lisp syntax is read as Emacs
Lisp using (read) and the REDUCE syntax is read using READCH.

(BEGIN2)
!*comp := t; rds open("rlisp.red",'input);
(BEGIN2)
rds open("rend.red",'input);
(INITREDUCE)

This runs without complaints and gives the appropriate output in the
*Standard LISP* buffer, namely

REDUCE 3.3, 20-Feb-2018 ...

1: <read and echo input from the minibuffer>

<output 1>

2: <read and echo input from the minibuffer>

<output 2>

etc.

n: bye;

This interaction model with output to a normal buffer and input from
the minibuffer is not very elegant, but it seems to work and is a
fairly painless way to make Emacs wait for input.

Can then input and compile the basic packages as follows to build a
mini-REDUCE:

in "arith.red", "mathlib.red", "alg1.red", "alg2.red"$
in "matr.red", "hephys.red"$
algebraic;

Now

in "alg.tst"

will correctly process most of "alg.tst".
