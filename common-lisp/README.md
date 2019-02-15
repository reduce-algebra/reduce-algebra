REDUCE on Common Lisp
=====================

Francis Wright, February 2019

**This code is currently experimental!**

The files in this directory are intended to build and run the current
distributed version of REDUCE on Common Lisp.  Some details depend on
the implementation of Common Lisp but I try to keep these to a
minimum.  At present, I support explicitly only the native Windows
port of SBCL (Steel Bank Common Lisp), but in the longer term I plan
to support also Ubuntu Linux and a couple of other implementations of
Common Lisp.

Building REDUCE
---------------

Create a build directory somewhere convenient.  If you download the
whole [REDUCE
trunk](https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/)
then you can use the common-lisp directory as your build directory if
you want.

**You need the following software and files:**

An appropriate version of [SBCL](http://www.sbcl.org/).

A minimal Unix-like environment including `bash` and `grep`; I use
[Cygwin](https://cygwin.com/).  (The `grep` command is used only for
reporting an error summary, which could be commented out without
affecting the build process.)

The build directory must contain the following files from the
common-lisp directory:

* `sl-on-cl.lisp`
* `clprolo.red`
* `clrend.red`
* `build.red`
* `remake.red`
* `bootstrap.sh`
* `build.sh`

The build directory must also contain a link to or copy of the file
[psl/boot.sl](https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/psl/boot.sl),
which is included in the [REDUCE
trunk](https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/)
but not in binary distributions.  (The way to create a link in Windows
is with the `mklink` command at a Windows command prompt; I use a
symbolic link for `boot.sl`.  A Windows shortcut created using the
File Explorer GUI will probably not work!)

The `packages` directory of the version of REDUCE you want to build
must be available and the environment variable `$reduce` must be set
to the directory containing this directory.  The `packages` directory
is installed as part of a binary distribution so, for example, if you
have a default REDUCE installation on Windows then an appropriate
value for `$reduce` would be `"C:\Program Files\Reduce"` (in Windows
format).  You can also use a recent download from the [Subversion
repository](https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/).
If not set then `$reduce` defaults to the build directory, which is
useful if you include a link to the `packages` directory you want to
use.

Run `bash` and make your chosen build directory current.  Set the
`$reduce` environment variable.  For example, execute the `bash`
command

	export reduce='C:/Program Files/Reduce'

Run the build script by executing the `bash` command

	./build.sh

The build process should create two sub-directories in the build
directory called `fasl` and `log`.  The whole `log` directory and the
`*.lisp`, `*.dat` and `bootstrap.img` files in the `fasl` directory
could be deleted after the build; only the files `fasl/reduce.img` and
`fasl/*.fasl` are required to run REDUCE.  (I will probably delete
superfluous files automatically at some later date, but for now they
are useful for debugging.)

Running REDUCE
--------------

REDUCE can be run by double-clicking the file `reduce.bat`, or from a
Windows command prompt with the build directory current by executing
the command

	reduce

At present, the current directory when REDUCE is run must be the build
directory, but I will remove that restriction at some later date.

(Don't try to run Windows SBCL interactively under `bash` because
you'll probably find that input editing doesn't work as you would
wish; fortunately, it runs fine in batch mode under `bash`.)

Interrupting REDUCE (with Control-C) invokes the SBCL debugger and
aborting that enters Lisp, which is very useful for low-level
debugging!  Evaluate `(begin)` to get back into REDUCE.

Current status
--------------

The process described above should build all of REDUCE without any
obvious errors.  I have tested all the core packages (that have a test
file, including Rlisp88) but none of the noncore packages.  (Given the
temporary hacks I used to build some of the noncore packages I'm
pretty sure they won't run correctly!)  So far, I have avoided the
need to customise the main REDUCE source code.

All core test files run to completion and are consistent with the
reference logs except for the following:

`arith.tst` runs correctly in my view and displays less numerical
error than `arith.rlg`.

`int.tst` shows no significant differences compared to PSL/CSL,
although `int.rlg` is different.

`rlisp88.tst` shows no significant differences compared to PSL/CSL,
although `rlisp88.rlg` is different.

`algint.tst` shows minor differences compared to PSL/CSL, although
`algint.rlg` is different.  The CL REDUCE results are slightly better
than the PSL/CSL results (but I don't know why!) and PSL currently
crashes for me towards the end of the test file.

`assist.tst` shows insignificant differences from the reference log
due to implementation differences.

Timings
-------

I estimate that SBCL REDUCE is about 3 times slower than PSL/CSL
REDUCE, but note that it is currently built for comfort (of debugging)
rather than speed!

Operation                           | Time
------------------------------------|--------------
Build bootstrap REDUCE image        | 3.8 secs
Build final REDUCE image            | 0.5 secs
Run (and check) all core test files | 2 min 35 secs

Most of the time building REDUCE goes in compiling the packages, which
takes a couple of minutes, but I don't currently have any precise
timings for this.

Known bugs
----------

By default, with `on defn` all output (including strings) will be
lower case.  If you set `off printlower` then string case will be
correct but all identifiers will be upper case.  This bug is a
consequence of the fact that SL-on-CL is currently an upper-case lisp
internally, whereas REDUCE assumes a lower-case lisp.  Input is
up-cased when it is read and down-cased when it is printed, except for
strings, for which character case is preserved.  However, in a few
situations, strings are printed as a sequence of single-character
identifiers, which are down-cased by default.  I have not found a
solution to this bug, but it's essentially cosmetic and I don't
suppose "on defn" is used a great deal.

To do
-----

In `rlisp/inter.red`, `*gc-hook*` is undefined.  It's called
`sb-ext:*after-gc-hooks*` in SBCL, so this needs sorting out later.

In `alg/intro.red`, `outputhandler*` is undefined. Should be declared
fluid. Done temporarily in `clrend`.

In `rlisp/io.red`, `in` uses `mkfil*` but `out` and `shut` use
`mkfil`; why the inconsistency?  [Not currently a problem for me as
far as I'm aware.]

In `rlisp/proc.red`, check that the switch `*loginlines` does what it
claims.

Make faslout/faslend more robust by using a single function that calls
begin internally (cf. infile) and make faslend generate a throw.  (See
also the old mkfasl code?)

Turn on use of smacro/inline declarations in REDUCE (which I turned
off to avoid a problem that is now fixed) and optimise SL-on-CL to
improve its speed.

Test the noncore packages.

A better trace facility (that does not display the `STANDARD-LISP::`
package prefix) -- use the `rtrace` package?

Better error handling.

Implement a proper Lisp init function and dump an executable file.

Replace shell scripts with Common Lisp code to build REDUCE portably?

Make SL-on-CL lower case and stop downcasing in the print functions.
(Internal functions could remain upper case.)  This would solve the
problem that prettyprinted strings are downcased and avoid the need
for a couple of ugly print-case related hacks.  With SBCL, this will
probably cause problems with a few key symbols, such as NIL, T,
LAMBDA, QUOTE, as it does with Emacs Lisp, so I'm not too eager to try
it.  (Could translate nil to '().)  However, this should be
straightforward with CLISP, which provides a lower-case "modern"
version of Common Lisp.
