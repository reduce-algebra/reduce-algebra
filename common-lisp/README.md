REDUCE on Common Lisp
=====================

**Francis Wright, April 2022**

From the introductory chapter of [*Common Lisp the Language, 2nd edition*, by Guy L. Steele Jr.](https://www.cs.cmu.edu/Groups/AI/html/cltl/cltl2.html):

> The goals of Common Lisp are thus very close to those of Standard Lisp and Portable Standard Lisp. Common Lisp differs from Standard Lisp primarily in incorporating more features, including a richer and more complicated set of data types and more complex control structures.

**This code is currently experimental!**

The files in this directory are intended to build and run the current distributed version of REDUCE on ANSI Common Lisp.  Some details depend on the implementation of Common Lisp but I try to keep these to a minimum.  At present, I support [Steel Bank Common Lisp](http://www.sbcl.org/) (SBCL), [CLISP](https://clisp.sourceforge.io/) and [Clozure Common Lisp](https://ccl.clozure.com/) (CCL) on MS Windows and Linux, where, "Linux" means the current or recent versions of Ubuntu and Fedora.  There is also some code to support macOS and I understand that REDUCE builds and runs on SBCL and CCL, but not CLISP, on macOS, although I don't run macOS myself.

I have recently built REDUCE using SBCL 2.2.4, Cygwin GNU CLISP 2.49+ and CCL 1.12.1 on Windows, and SBCL 2.2.3, GNU CLISP 2.49.92 and CCL 1.12.1 on Ubuntu 20.04.4 LTS.  In all cases, REDUCE runs simple test input correctly, but I have not done any careful testing recently.

The support for CCL is based on code provided by Marco Ferraris.  There is also some preliminary support for the Java-based [Armed Bear Common Lisp (ABCL)](https://abcl.org/) thanks to Rainer Schöpf, but it is not yet possible to preserve Lisp images so this version is not yet usable.

Building REDUCE
---------------

Create a build directory somewhere convenient.  If you download the whole [REDUCE trunk](https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/) then you can use the `common-lisp` directory as your build directory with no additions.

You need an appropriate version of SBCL, CLISP, CCL and/or ABCL (see links above).  Possibly out-of-date versions of SBCL and CLISP on Linux should be available via a Linux package manager such as Synaptic (but not via a software installer for windowed applications).

To use CCL you need to create a command called either `ccl` or `ccl64`, as explained in the CCL documentation.  The build and run scripts use whichever is available, preferring `ccl64`.  I have only tested 64-bit CCL and I call the command to run it `ccl`.

To use ABCL, you need to ensure that you have a suitable Java runtime environment installed, and you need to download [abcl-bin-1.8.0.zip](https://abcl.org/releases/1.8.0/abcl-bin-1.8.0.zip) and unzip it (or build and install it) so that `abcl-bin-1.8.0/abcl.jar` exists in the `common-lisp` directory.  The build scripts expect to find the commands `sbcl`, `clisp`, `ccl`, `ccl64`, and/or `java` on your search path.

You need to use a minimal Unix-like environment including `bash` and `grep`; on MS Windows I use [Cygwin](https://cygwin.com/).  (The `grep` command is used only for reporting an error summary, which could be commented out without affecting the build process.)

The build directory must contain the following files from the common-lisp directory:

* `sl-on-cl.lisp`
* `trace.lisp`
* `bootstrap.lisp`
* `clprolo.red`
* `clrend.red`
* `remake.red`
* `build.sh`
* `gnuintfc.red`

If you do not build within the REDUCE Subversion file tree then the following two additional steps are necessary:

* The build directory must contain a link to, or copy of, the file [psl/boot.sl](https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/psl/boot.sl).  (The way to create a link in Windows is with `mklink` at a Windows command prompt running as Administrator, which you can open by holding the Windows key and typing `x`; I use a symbolic link for `boot.sl`.  A Windows shortcut created using the File Explorer GUI will probably not work!)

* The `packages` directory for the version of REDUCE you want to build must be available.  This could be the `packages` directory installed as part of a binary distribution or a recent download from the [Subversion repository](https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/).  It is easiest to add the `packages` directory as a symbolic link in either the `common-lisp` directory or its parent.  (On Windows I use a directory symbolic link created using `mklink /d`.)  Alternatively, you can set the environment variable `$reduce` to the directory containing the `packages` directory (without a trailing directory separator).

Open a window running `bash` and make your chosen build directory current.  If you need to set the `$reduce` environment variable, you can do it like this.  For example, to use the `packages` directory from a _default_ REDUCE installation to build SBCL REDUCE on MS Windows, execute the `bash` command

    export reduce='C:/Program Files/Reduce'

or to build CLISP REDUCE on Cygwin, execute the `bash` command

    export reduce='/cygdrive/c/Program Files/Reduce'

On Linux, use something like the following for all versions of Common Lisp:

    export reduce='/usr/share/reduce'

Then run the build script by executing the `bash` command

    ./build.sh -l <lisp>

where `<lisp>` is either `sbcl`, `clisp`, `ccl` or `abcl`.

The build process should create two sub-directories in the build directory called `fasl.<lisp>` and `log.<lisp>`.  The whole `log.*` directory and the `*.lisp`, `*.dat` and `bootstrap.*` files in the `fasl.*` directory could be deleted after the build; they are not required to run REDUCE.  (I will probably delete superfluous files automatically at some later date, but for now they are useful for debugging.)  Note that the builds for different Lisps are completely independent since they use different compiled (fasl) file extensions and sub-directories.

The build script supports some optional flags: `-c` provides a clean build, by first deleting all the files that get built; `-f` forces all REDUCE packages to be recompiled, even if they appear to be up to date; `-b` builds only bootstrap REDUCE; `-h` displays help.  To build using an updated version of Common Lisp, you should do a clean build, i.e.

    ./build.sh -l <lisp> -c


Running REDUCE
--------------

The general convention is that REDUCE on `<lisp>` is run by executing a shell script file named `red<lisp>`, where `<lisp>` is either `sbcl`, `clisp` or `ccl`.

On MS Windows, SBCL or CCL REDUCE can be run by double-clicking the file `red<lisp>.bat`, or from a Windows command prompt with the build directory current by executing the command

    red<lisp>

On Linux or Cygwin, open a terminal window with the build directory current and execute the command

    ./red<lisp>

Beware that input editing may not work using the shell interface; one solution is to use [Run-REDUCE](https://fjwright.github.io/Run-REDUCE/).

REDUCE can be run from any directory provided the command to start it is specified suitably, such as by using an absolute file path or a symbolic link.  Alternatively, you can add the `common-lisp` directory to your path and then run REDUCE via the appropriate command from any directory on both Windows and Linux.

Interrupting REDUCE (with Control-C) invokes a Lisp break loop and aborting that should return you to REDUCE.  Within the break loop you can run arbitrary Lisp code, but remember that you are running Common Lisp and in particular Lisp output uses Common Lisp syntax, although you are initially in the Standard Lisp package.  However, package prefixes are recognised (which they are not from within REDUCE) so you can access most of Common Lisp, but beware that you might break REDUCE so that you cannot return to it!  Evaluating the Lisp expression `(exit)` from a Lisp break loop should completely terminate REDUCE.

Implementation-specific functionality
-------------------------------------

The following facilities are modelled on those provided by PSL; please see the PSL manual for further details.

Lisp-level function tracing is provided by the commands `tr` and `trst`.  A command of the form `tr fn1, fn2, ...;` (without any quotes) enables tracing of the argument and return values of each of the functions `fn1`, `fn2`, etc.; if no functions are specified it lists all traced functions.  The command `trst` is similarly but also traces assignments, which works for functions that have been compiled using `faslout` provided the appropriate Lisp file is still available in the `fasl` directory.  The commands `untr` and `untrst` (which is just a synonym for `untr`) disable tracing; if no functions are specified they untrace all traced functions.  These tracing commands are independent of the Common Lisp `trace` and `untrace` macros.  Input of function names uses Standard Lisp (i.e. REDUCE) syntax but output uses Common Lisp syntax, although it does not include any package prefixes, which can make Common Lisp tracing output of REDUCE incomprehensible!

Preliminary implementations of the `system`, `pipe-open` and `channelflush` functions are provided.  The functions `getenv` and `getpid` respectively provide access to environment variables and the REDUCE process identifier, and should be portable across operating systems.

The commands `pwd()` or `cd "<directory>"` respectively return or change (and return) the current working directory.  The name `chdir` is an alias for `cd`.

Environment variables and dots ("." or "..") in filenames are expanded by `cd/chdir` and `open` relative to the current working directory of the REDUCE process.

The identifier `common-lisp` is always included in the list assigned to the standard REDUCE fluid variable `lispsystem!*` and the identifiers `sbcl`, `clisp`, `win32`, `cygwin`, `unix` are included as appropriate.  These identifiers indicate the Lisp and operating system on which REDUCE was built and can be used to customise the behaviour of REDUCE, as is done in some of the REDUCE files in this directory (but not at present in any other files).  The identifier `win32` means Microsoft Windows in general and appears for both 32 and 64-bit builds.  The identifier `unix` appears for Linux builds, and both `cygwin` and `unix` appear for Cygwin builds.

For Cygwin CLISP REDUCE (on MS Windows), the REDUCE `gnuplot` package tries to run Cygwin gnuplot if it is available and if not then it tries to run native MS Windows gnuplot (which is included in REDUCE binary distributions for MS Windows).  Cygwin gnuplot produces graphical output if REDUCE is run under the X Window System and text output otherwise.  For CLISP REDUCE on Linux and SBCL REDUCE on both MS Windows and Linux, gnuplot produces graphical output.

Status (July 2019)
------------------

The process described above should build all of REDUCE without any obvious errors.  So far, I have avoided the need to customise the main REDUCE source code (apart from the file `gnuintfc.red`).

All available test files produce output that agrees with CSL REDUCE apart for timings and minor numerical and/or implementation differences, except for the following:

* The `reduce4` test fails in a similar way to the way it fails on CSL &ndash; excluded from regular testing.
* The `ibalp` test fails on CLISP with a program stack overflow error; it just stops abruptly on SBCL &ndash; excluded from regular testing.
* The `pasf` test output appears to be mathematically correct but is ordered differently on CLISP, whereas it agrees on SBCL (and appears to run twice as fast as on CSL!).
* The `lalr` test output appears to be correct apart from two issues causing minor cosmetic differences.
* The `rubi_red` test is very slow, generates very much output, and timeouts can't work on CLISP (see below), but otherwise the early part of the test file appears to run correctly &ndash; excluded from regular testing.  On SBCL, the first error is similar to that shown on CSL, but SBCL REDUCE does not recover after this error, probably due to the currently crude general error handling.
* The `xcolor` test only runs to completion on SBCL with `(declaim (optimize speed))`. I think this is because it involves a highly recursive procedure (color1), which runs out of stack on the most complicated examples at the end of the test file unless optimized for maximum speed.

Timings (July 2019)
-------------------

New timing methodology uses the bash time command.  "Best" means the fastest previous time.  Numbers in parentheses are times relative to the CSL times.

**Timing on Microsoft Windows** (on a fairly recent Intel Core i5 processor):

Operation                               | CSL Time  | Best SBCL | This SBCL       | Best CLISP | This CLISP
----------------------------------------|-----------|-----------|-----------------|------------|-----------------
Run (and check) all core test files     |  34 secs  |  47 secs  |  45 secs  (1.3) |  3 m 23 s  |  3 m 52 s  (6.8)
Run (and check) most noncore test files |  4 m 39 s | 15 m 14 s | 14 m 52 s (3.2) | 67 m 27 s  | 85 m 10 s (18.3)

**Timing on Ubuntu Linux** (on a fairly old Intel Core Duo processor):

Operation                               | CSL Time  | Best SBCL | This SBCL       | Best CLISP | This CLISP
----------------------------------------|-----------|-----------|-----------------|------------|-----------------
Run (and check) all core test files     |  23 secs  |           |  56 secs  (2.4) |            |  5 m 30 s (14.3)
Run (and check) most noncore test files |  7 m 09 s |           | 26 m 02 s (3.6) |            |119 m 43 s (16.7)

The CSL test times do not include checking, which involves running `diff`.  The times for the noncore tests do not include `reduce4`, `ibalp` or `rubi_red` as explained above. The `gnuplot` and `turtle` tests are excluded because they need to be run interactively, but they seems to work OK on both MS Windows and Linux.

Known limitations
-----------------

I cannot see any way to support the facilities for restricting execution time on CLISP.  In more detail: the file "rlisp/inter.red" defines procedures `with!-timeout` and similar that use garbage collection to provide an interrupt by assigning a function to the variable `!*gc!-hook!*`, but no garbage collection hooks exist in CLISP.  The procedures `with!-timeout` and similar just run without any restriction so don't use CLISP REDUCE is you need this facility!  This affects `rubi_red` and possibly other packages.  It works on SBCL!

To do
-----

* Optimise SL-on-CL to improve its speed.
* Better error handling.
* Make faslout/faslend more robust by using a single function that calls begin internally (cf. infile) and make faslend generate a throw.  (See also the old mkfasl code?)
* Implement a genuinely lower-case Standard Lisp, perhaps using case-inversion for a few special symbols such as `lambda`, `nil`, `t`?
* Hide the implementation details within an implementation package and only export required functions to the STANDARD-LISP package?
