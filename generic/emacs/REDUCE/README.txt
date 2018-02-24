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
I keep lambda, nil and t lower-case.

I have defined a few additional functions that are assumed by REDUCE
but not defined in Standard LISP at the end of sl.el.

sl.el and boot.el now compile cleanly and seem to run.  (However, to
use the uncompiled boot.el file, I need to increase
max-lisp-eval-depth to 2000 and max-specpdl-size to 2500 to handle
module slfns.)

Moreover, setting *COMP non-nil now causes REDUCE procedures to be
compiled as they are read, which causes REDUCE syntax to input *very
much* faster!

To build the main modules of REDUCE 3.3 in the current Emacs session
and run it, proceed as follows:

1. Compile sl.el and boot.el, then load boot.elc (which loads sl.elc
if necessary).

2. Run M-x STANDARD-LISP

3. Evaluate (DSKIN "dbuild.el") via the minibuffer.

This build process runs without complaints and completes with the
appropriate output in the *Standard LISP* buffer, namely

REDUCE 3.3, 20-Feb-2018 ...

1: <read and echo input from the minibuffer>

<output 1>

2: <read and echo input from the minibuffer>

<output 2>

etc.

n: bye;

This interaction model with output to a normal buffer and input via
the minibuffer seems to work and is a fairly painless way to make
Emacs wait for input.

Now

in "alg.tst"

will correctly process most of "alg.tst".

It is possible to re-enter REDUCE after stopping it with bye; as follows:

1. Run M-x STANDARD-LISP

2. Evaluate (BEGIN) via the minibuffer.

It's very useful to be able to go in and out of a REDUCE session,
although I currently have no way to start a new REDUCE session without
killing and restarting Emacs!
