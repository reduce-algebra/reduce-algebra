# Emacs REDUCE
**The REDUCE Computer Algebra System running on Emacs Lisp in an Emacs buffer**

**[Francis Wright](https://sites.google.com/site/fjwcentaur)**, December 2022

---

Somewhat to my amazement, the Emacs REDUCE that I built in October 2018 using whatever was the current release of Emacs still appears to run on Emacs 28 in December 2022 without any modification!

---

## Introduction

**This project is strictly for amusement only!  It may crash Emacs and I strongly recommend running it alone in an instance of Emacs that you are not also using for anything important.**

For simplicity and stability during initial development, I am currently using the [REDUCE 3.8 source files](https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/historical/r38).

[REDUCE](https://reduce-algebra.sourceforge.io/) is a Computer Algebra System written in Standard Lisp that normally runs on PSL (Portable Standard Lisp) or CSL (Codemist Standard Lisp).  Both PSL and CSL were essentially developed to run REDUCE.

The aim of this project is to provide an emulation of Standard Lisp and modified versions of some of the files in the REDUCE source directories `util` and `packages/support` in order to build REDUCE in Emacs, running on Emacs Lisp.  The file `esl.el` provides a partial emulation of Standard Lisp (enough to run REDUCE) and forms the main interface between REDUCE and Emacs.  I refer to this emulation as Emacs Standard Lisp or ESL.  To avoid name clashes between Emacs Lisp and Standard Lisp, ESL uses primarily upper-case, although this is invisible to normal REDUCE users because the REDUCE UI translates case as necessary.

The file `boot.el` is the ESL version of the REDUCE file `boot.sl`, which I have edited to use upper case and replace `%` with `;` and `!`  with `\` where necessary so that Emacs Lisp can read it.  However, it retains `lambda`, `nil`, `quote` and `t` as lower-case symbols.

Files with names of the form `eslxxxx.red` are ESL versions of the REDUCE files `cslxxxx.red`, `pslxxxx.red` or `xxxx.red`.  Currently Emacs REDUCE assumes that all required Emacs Lisp (`.el`) and REDUCE (`.red`) files and directories are in the current directory.

## Building Emacs REDUCE

The primary repository for this project is on [GitHub](https://github.com/fjwright/Emacs-REDUCE) but every so often I will upload what I regard as a reasonably stable and usefully improved snapshot to the secondary repository on [SourceForge](https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/generic/emacs/REDUCE).

Download the files in this repository (or clone it) to some directory, which I will call `REDUCE`, but its name is not significant.  Download the directory

https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/historical/r38/packages

and the file

https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/historical/r38/package.red

to `REDUCE`.  Alternatively, download

https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/historical/r38

somewhere and regard this directory as the directory `REDUCE` (which will then include a lot of files that are not required for this build), or link the directory `packages` and/or file `package.red` to `REDUCE`.

Open a (Unix-style) command shell and execute

```sh
. build-core-reduce.sh
```
and then

```sh
. remake-all-packages.sh
```

This build should take about 10 minutes.

## Running Emacs REDUCE

To run Emacs REDUCE for the first time in an Emacs session, load the file `reduce.el` (or compile it first and load `reduce.elc`).  This should give you a fairly standard REDUCE session with input via the minibuffer.  Emacs REDUCE accepts input in either lower or upper case and currently outputs in lower case by default (except that strings retain their input case).

If you terminate Emacs REDUCE (or it is terminated by Emacs), it is really only suspended unless you terminate Emacs and you can re-enter where you left it by running the Emacs command `M-x esl-reduce` (unless REDUCE was terminated by a catastrophic error).  Don't reload `reduce.el(c)`.  You can exit (i.e. suspend) Emacs REDUCE in the conventional way (using the REDUCE command bye or quit) or you can use the Emacs keyboard-quit signal `C-g`.

Closing Emacs is the only reliably way to completely stop Emacs REDUCE, so the only way to restart it cleanly is to restart Emacs!

You can interact with an Emacs REDUCE session using normal Emacs Lisp facilities (in ways that are not possible or convenient using conventional REDUCE facilities), but it is normally best to suspend REDUCE first.  Otherwise, Emacs will probably suspend REDUCE; for example, if you do something that needs to use the minibuffer.

When interacting with an Emacs REDUCE session via Emacs Lisp, remember that ESL is an upper-case Lisp and that you are using Emacs Lisp syntax, so omit any `!` escapes that would be required in REDUCE or Standard LISP.  For example, the REDUCE symbolic-mode input

`foo!-bar x;`  [or `foo!-bar(x);`]

would be (assuming `foo!-bar` has no special processing rules)

```lisp
(FOO-BAR X)
```

in Emacs Lisp.

### Print output

The ESL print functions support the Standard LISP escape convention and down-casing of identifiers (when `!*LOWER` is non-nil).

## Current status of Emacs REDUCE

The build process builds (almost) all REDUCE 3.8 packages, apparently successfully.

### Test files

Emacs REDUCE currently runs all of `alg/alg.tst` correctly but about 20 times slower than the time shown in `alg.rlg`.

#### Poly package

`poly/polydiv.tst` now runs correctly.

`poly/poly.tst` now also runs correctly provided I replace the `d` in the products in the gcd tests with `<<d>>` to force an extra evaluation.  I can't find the cause of this problem.

#### Arith package

The REDUCE 3.8 file `smlbflot.red` contains are error that must be corrected as in later REDUCE versions.  The file `rdelem.red` uses the smacro `incprec!:` defined in `smlbflot.red`, but it is not being applied.  I have added

```text
load!-package 'smlbflot;
```

which seems to fix the problem.  I think either this change, or perhaps better moving the smacro definitions for `incprec!:` and `decprec!:` into `arith.red`, should probably be applied to the generic source code if this has not already been done post REDUCE 3.8.

With the above two changes, `arith/arith.tst` appears to run correctly.  There are a lot of rounding differences, but nothing serious and sometimes Emacs REDUCE is more accurate!  Probably OK for now.  Eventually, I should probably use the Elisp transcendental functions, which are implemented in C, rather than those in `arith/math.red`.

#### Factor package

`factor/factor.tst` runs completely correctly, although it's a bit slow.  There is probably scope for optimizing the ESL arithmetic used in the factorizer.

#### Int package

`int/int.tst` runs to completion, but it's about 20 times slower than the time shown in `int.rlg` (which is consistent with running `alg.tst`).  However, at one point Emacs appears to be about to enter the debugger but then it doesn't and `int(x**7/(x**12+1),x)` evaluates only on a later subsequent attempt.  The problem appears to be that it involves extremely large numbers.  The Calc functions used to process them (in particular, `math-div-bignum-big`) are written recursively and they run out of stack space, but only by a small margin.  This triggers the debugger, which increases the stack space by enough that Emacs can continue and the integral can later be evaluated, although the error seems to change the sort order of the result.  Increasing `max-specpdl-size` from the default of 1300 to 2000 before running the test file allows it to complete correctly.  However, the best solution might be to re-implement big integers taking care to avoid recursion, which is in hand!

### Known problems

* `tmprint` build: too Lisp-specific and irrelevant at present
* `atensor`, `ncpoly` and `xcolor` tests: variable binding depth
* `crack` suite test: various obscure problems
* The sort order in the `cali` and `fide` tests differs from the reference `.rlg` files, but not from the results of running the tests in PSL REDUCE, so I think these differences can be ignored as quirks in REDUCE 3.8.
* `rlfi` clears the raise switch, which mangles Emacs REDUCE, and in batch mode the test file reads `EOF` ad infinitum!
* The `specfn` test uses too much resource at present, probably due to recursive functions and the recursive code in the Calc package.
* The `cgb`, `eds`, `mathml`, `mathmlom`, `redlog`, `susy2` tests all display errors.

## To do

* Optimization.
* Better support for big integers: revert from using Calc to native integers and require Emacs 27 or later; see `NEWS.27`.
* Better user interface.
* Switch to the current version of REDUCE.
* Use lexical binding for REDUCE where possible.  This **appears** to work for the `rlisp` package without any modification to the REDUCE source code, but it needs to be automated and tested more generally.  Free (undeclared) variables **appear** to be bound appropriately.  Need to save the compile logs when generating fasl files.
* The Lisp `READ` function is used in a few places in REDUCE and so needs to be implemented better than at present.
* Investigate rounding of floats, which seems to differ from the exemplary test logs.  This may just be because the REDUCE 3.8 logs are nearly 20 years old.  If current Lisps all use essentially the same C libraries then the rounding should be the same in all REDUCE implementations (maybe).
* Native compilation; requires Emacs 28 or later.
