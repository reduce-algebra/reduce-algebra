Emacs REDUCE
============

Francis Wright, October 2018

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
nil, quote and t as lower-case symbols.

Files with names of the form "eslxxxx.red" are ESL versions of the
REDUCE files "cslxxxx.red", "pslxxxx.red" or "xxxx.red".  The current
Emacs REDUCE build process assumes that all required Emacs Lisp (.el)
and REDUCE (.red) files and directories are in the current directory.

To build Emacs REDUCE
---------------------

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
REDUCE.

Open a (Unix-style) command shell and execute

. build-core-reduce.sh

and then

. remake-all-packages.sh

This build should take about 10 minutes.

To run Emacs REDUCE
-------------------

To run Emacs REDUCE for the first time in an Emacs session, load the
file "reduce.el" (or compile it first and load "reduce.elc").  This
should give you a fairly standard running REDUCE session, but remember
that input is currently via the minibuffer.  Emacs REDUCE accepts
input in either lower or upper case and currently outputs in lower
case by default (except that strings retain their input case).

If you terminate Emacs REDUCE (or it is terminated by Emacs), it is
really only suspended unless you terminate Emacs, so you can re-enter
where you left it by running the Emacs command `M-x esl-reduce'
(unless REDUCE was terminated by a catastrophic error).  Don't reload
"reduce.el(c)".  You can exit (i.e. suspend) Emacs REDUCE in the
conventional way (using the REDUCE command bye or quit) or you can use
the Emacs keyboard-quit signal `C-g'.

Closing Emacs is the only reliably way to completely stop and unload
Emacs REDUCE, so the only way to restart it cleanly is to restart
Emacs!

You can interact with an Emacs REDUCE session using normal Emacs Lisp
facilities (in ways that are not possible or convenient using
conventional REDUCE facilities), but it is normally best to suspend
REDUCE first.  Otherwise, Emacs will probably suspend REDUCE; for
example, if you do something that needs to use the minibuffer.

When interacting with an Emacs REDUCE session via Emacs Lisp, remember
that ESL is an upper-case Lisp and that you are using Emacs Lisp
syntax, so omit any ! escapes that would be required in REDUCE or
Standard LISP.  For example, the REDUCE symbolic-mode input

foo!-bar X;  [or foo!-bar(X);]

would be (assuming foo!-bar has no special processing rules)

(FOO-BAR X)

in Emacs Lisp.

Print output
------------

The ESL print functions support the Standard Lisp escape convention
and down-casing of identifiers (when !*LOWER is non-nil).

Current status of Emacs REDUCE
------------------------------

The build process builds (almost) all packages, apparently
successfully.

Test files
----------

Emacs REDUCE currently runs all of "alg/alg.tst" correctly but about
20 times slower than the time shown in "alg.rlg".

Poly package

"poly/polydiv.tst" now runs correctly.

"poly/poly.tst" now also runs correctly provided I replace the `d' in
the products in the gcd tests with <<d>> to force an extra evaluation.
I can't find the cause of this problem.

Arith package

The REDUCE 3.8 file smlbflot.red contains are error that must be
corrected as in later REDUCE versions.  The file "rdelem.red" uses the
smacro incprec!: defined in "smlbflot.red", but it is not being
applied.  I have added

load!-package 'smlbflot;

which seems to fix the problem.  I think either this change, or
perhaps better moving the smacro definitions for incprec!: and
decprec!: into "arith.red", should probably be applied to the generic
source code if this has not already been done post 3.8.

With the above two changes, "arith/arith.tst" appears to run
correctly. There are a lot of rounding differences, but nothing
serious and sometimes Emacs REDUCE is more accurate!  Probably OK for
now.  Eventually, I should probably use the Elisp transcendental
functions, which are implemented in C, rather than those in
"arith/math.red".

Factor package

"factor/factor.tst" runs completely correctly, although it's a bit
slow.  There is probably scope for optimizing the arithmetic used in
the factorizer.

Int package

"int/int.tst" runs to completion, but it's about 20 times slower than
the time shown in "int.rlg" (which is consistent with running
"alg.tst").  However, at one point Emacs appears to be about to enter
the debugger but then it doesn't and int(x**7/(x**12+1),x) evaluates
only on a later subsequent attempt.  The problem appears to be that it
involves extremely large numbers.  The Calc functions used to process
them (in particular, `math-div-bignum-big') are written recursively
and they run out of stack space, but only by a small margin.  This
triggers the debugger, which increases the stack space by enough that
Emacs can continue and the integral can later be evaluated, although
the error seems to change the sort order of the result.  Increasing
`max-specpdl-size' from the default of 1300 to 2000 before running the
test file allows it to complete fully correctly.  However, the best
solution might be to re-implement big integers taking care to avoid
recursion, which is in hand!

To do
-----

Batch-mode testing; run the full test suite.
Better support for big integers.
Better user interface.

Known problems
--------------

tmprint build: too Lisp-specific and irrelevant at present

atensor test: variable binding depth

cali test: ***** Wrong type argument: listp, PROG.  This is caused
entirely by using u as a variable in symbolic mode.  The variable u
and a few other behave oddly in ESL.  The sort order is wrong,
probably because t is mishandled.

crack suite test: various obscure problems

fide test: sort order
