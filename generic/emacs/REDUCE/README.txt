						  ESL REDUCE README
						  =================

							Francis Wright

For stability during development, I am currently using the REDUCE 3.8
files at

https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/historical/r38

The aim of this project is to provide modified versions of some of the
files in the REDUCE directories "util" and "packages/support" in order
to build REDUCE in Emacs, running on Emacs Lisp.  The file "esl.el"
provides a partial emulation of Standard LISP (enough to run REDUCE)
and forms the main interface between REDUCE and Emacs.  I refer to
this emulation as Emacs Standard LISP or ESL.

The file "boot.el" is the ESL version of the REDUCE file "boot.sl"
edited to use upper case, and replace % with ; and ! with \ where
necessary so that Emacs Lisp can read it.  However, it retains lambda,
nil and t as lower-case symbols.

Files with names of the form "eslxxxx.red" are ESL versions of the
REDUCE files "cslxxxx.red", "pslxxxx.red" or "xxxx.red".  The current
ESL REDUCE build process does not use any shell scripts and assumes
that all required Emacs Lisp (.el) and REDUCE (.red) files and
directories are in the current directory.

To build ESL REDUCE
===================

Download the current ESL file set to some directory, which I will call
REDUCE, but its name is not significant.  Download the directory 

https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/historical/r38/packages

to REDUCE, and download the file

https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/historical/r38/package.red

to REDUCE.  Alternatively, download

https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/historical/r38

somewhere and regard this directory as the directory REDUCE (which
will then include a lot of files that are not required for this
build), or link the directory "packages" and file "package.red" to
REDUCE.  Open a directory listing of REDUCE in Emacs (C-x d).

1. Compile "esl.el" and "boot.el" (B in Emacs dired mode), then load
"boot.elc" (L in Emacs dired mode), which loads "esl.elc".

2. Run M-x STANDARD-LISP

3. Evaluate

(DSKIN "dbuild.el")

via the minibuffer to build a basic version of REDUCE in the current
Emacs session.  This build step should take about 10 seconds.

4. Run

symbolic infile "eslremakeall.red";

via the minibuffer to remake all ESL REDUCE fasl files.  This build
step should take a few minutes.  (To really build all of REDUCE,
remove the premature end statement, which currently stops the build
after the most important third of the packages.)

I recommend now closing Emacs and then re-opening it.  This is the
only way to cleanly restart ESL REDUCE.

To run ESL REDUCE
=================

To run ESL REDUCE for the first time in an Emacs session, load the
file "reduce.el" (or compile it first and load "reduce.elc").  This
should give you a fairly standard running REDUCE process, but remember
that input is currently via the minibuffer.  ESL REDUCE accepts input
in either lower or upper case but currently outputs in upper case only
(except that strings retain their input case).

If you terminate ESL REDUCE (or it is terminated by Emacs), it is
really only suspended unless you terminate Emacs and you can re-enter
ESL REDUCE where you left it by running the Emacs command `M-x reduce'
(unless REDUCE was terminated by a catastrophic error).  Don't reload
"reduce.el(c)".  You can terminate (suspend) ESL REDUCE in the
conventional way (using the REDUCE command bye or quit) or you can use
the Emacs keyboard-quit signal `C-g'.

You can interact with REDUCE using all normal Emacs Lisp facilities,
but it is normally best to terminate REDUCE first.  Otherwise, Emacs
will probably terminate REDUCE, for example, if you do something that
needs to use the minibuffer.

When interacting with ESL REDUCE via Emacs Lisp, remember that ESL is
an upper-case Lisp and that you are using Emacs Lisp syntax, so omit
any ! escapes that would be required in REDUCE or Standard LISP.  For
example, the REDUCE symbolic-mode input

foo!-bar X;  [or foo!-bar(X);]

would be (assuming foo!-bar has no special processing rules)

(FOO-BAR X)

in Emacs Lisp.

Current status of ESL REDUCE
============================

ESL REDUCE now runs all of "alg.tst" about 20 times slower than the
time shown in "alg.rlg" and with upper-case output.  Apart from the
output case, the output for the Fourier, Compton and second physics
examples differs from that shown in "alg.rlg". This may be partly just
a different term ordering.

There is still a lot more work to do!
