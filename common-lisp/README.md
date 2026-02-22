# REDUCE on Common Lisp

**[Francis Wright](https://sites.google.com/site/fjwcentaur)**<br/>
Time-stamp: <2026-02-21 16:05:48 franc>

* [Building REDUCE](#building-reduce)
* [Running REDUCE](#running-reduce)
* [Alternative builds](#alternative-builds)
* [Required version of `bash`](#required-version-of-bash)
* [Implementation-specific functionality](#implementation-specific-functionality)
* [Status](#status)
* [Known limitations](#known-limitations)
* [To do](#to-do)

From the introductory chapter of [*Common Lisp the Language, 2nd edition*, by Guy L. Steele Jr.](https://www.cs.cmu.edu/Groups/AI/html/cltl/cltl2.html):

> The goals of Common Lisp are thus very close to those of Standard Lisp and Portable Standard Lisp. Common Lisp differs from Standard Lisp primarily in incorporating more features, including a richer and more complicated set of data types and more complex control structures.

**This code is currently experimental!**

The files in this directory are intended to build and run recent versions of REDUCE on ANSI Common Lisp.  Some details depend on the implementation of Common Lisp but I try to keep these to a minimum.  At present, I support [Steel Bank Common Lisp](http://www.sbcl.org/) (SBCL), [CLISP](https://clisp.sourceforge.io/) and [Clozure Common Lisp](https://ccl.clozure.com/) (CCL) on MS Windows 11 and Ubuntu 24.  I understand that REDUCE builds and runs on SBCL, CLISP and CCL on macOS, although I don't run macOS myself.  The support for CCL is based on code provided by Marco Ferraris.  See [Status](#status) below for build and test details.

I recommend SBCL because in my experience it is the fastest, it is easy to install and set up, binary distributions are readily available, and it is well maintained and frequently updated.  CLISP is slow, and I find CCL tricky to install and set up.


## Building REDUCE

I recommend that you either use [Subversion](https://en.wikipedia.org/wiki/Apache_Subversion) (`svn`) to install from SourceForge and maintain a copy of the whole [REDUCE trunk](https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/), or download and unzip the latest source snapshot from SourceForge by using the _Download Snapshot_ link towards the top of the [REDUCE trunk](https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/) page.  If you use the `common-lisp` sub-directory as your build directory then the build process should [determine the REDUCE revision](#determining-the-reduce-revision) automatically.

You need to obtain, build if necessary and install the version(s) of Common Lisp that you intend to use (see links above), support for which is not part of this project.  Most are available as pre-built binary distributions.  On Linux, possibly out-of-date versions of SBCL and CLISP should be available via a package manager such as Synaptic (but not via a software installer for windowed applications).  To use CCL you need to create a command called either `ccl` or `ccl64`, as explained in the CCL documentation.  My build and run scripts use whichever is available, preferring `ccl64`.  (I have only tested 64-bit CCL and I call the command to run it `ccl`.)  The build and run scripts expect to find the commands `sbcl`, `clisp`, `ccl` and/or `ccl64` on your command search path.

You need to use a minimal Unix-like environment including [**fairly recent** versions of `bash`](#required-version-of-bash) and `grep`; on MS Windows I use [Cygwin](https://cygwin.com/).  (The `grep` command is used only for reporting an error summary, which could be commented out without affecting the build process.)

Make the `common-lisp` directory current and run then the build script by executing the `bash` command

```sh
./build.sh <lisp>
```

where `<lisp>` is the version of Common Lisp to use: `sbcl`, `clisp` or `ccl`.

The build process should create two sub-directories in the build directory called `fasl.<lisp>` and `log.<lisp>`.  The whole `log.*` directory and the `*.lisp`, `*.dat` and `bootstrap.*` files in the `fasl.*` directory could be deleted after the build since they are not required to run REDUCE.  (I will probably delete superfluous files automatically at some later date, but for now they are useful for debugging.)  Note that the builds for different Lisps are completely independent since they use different sub-directories.

The build script supports some optional flags: `-c` provides a clean build, by first deleting all the files that get built; `-f` forces all REDUCE packages to be recompiled, even if they appear to be up to date; `-b` builds only bootstrap REDUCE; `-h` displays help.  To rebuild using an updated version of Common Lisp, you should always do a clean build, i.e.

```sh
./build.sh -c <lisp>
```


## Running REDUCE

The general convention is that REDUCE on `<lisp>` is run by executing a shell script file named `red<lisp>`, where `<lisp>` is `sbcl`, `clisp` or `ccl`.

On MS Windows, SBCL or CCL REDUCE can be run by double-clicking the file `red<lisp>.bat`, or from a Windows command prompt with the build directory current by executing the command

```sh
red<lisp>
```

On Linux or Cygwin, open a terminal window with the build directory current and execute the command

```sh
./red<lisp>
```

Beware that input editing may not work using the shell interface; possible solutions are to use [Run-REDUCE](https://fjwright.github.io/Run-REDUCE/) or [REDUCE IDE](https://reduce-algebra.sourceforge.io/reduce-ide/).

REDUCE should run from any directory and the command to start it can be specified by using either an absolute or a relative file path.  **But note that neither a hard nor a symbolic link will work!**  Alternatively, you can add the `common-lisp` directory to your command search path and then run REDUCE via the appropriate command from any directory.

Interrupting REDUCE (with Control-C) invokes a Lisp break loop and aborting that should return you to REDUCE.  Within the break loop you can run arbitrary Lisp code, but remember that you are running Common Lisp and in particular Lisp output uses Common Lisp syntax, although you are initially in the Standard Lisp package.  However, package prefixes are recognised (which they are not from within REDUCE) so you can access most of Common Lisp, but beware that you might break REDUCE so that you cannot return to it!  Evaluating the Lisp expression `(exit)` from a Lisp break loop should completely terminate REDUCE.


## Alternative builds

The build directory must contain the following files from the `common-lisp` directory:

* `sl-on-cl.lisp`
* `trace.lisp`
* `bootstrap.lisp`
* `clprolo.red`
* `clrend.red`
* `remake.red`
* `build.sh`
* `gnuintfc.red`
* `red<lisp>`, `red<lisp>.bat` as required

If you do not build within the REDUCE Subversion file tree then the following two additional steps are necessary:

* The build directory must contain a link to, or copy of, the file [psl/boot.sl](https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/psl/boot.sl).  (The way to create a link in Windows is with `mklink` at a Windows command prompt running as Administrator, which you can open by holding the Windows key and typing `x`.  A Windows shortcut created using the File Explorer GUI will probably not work!)

* The `packages` directory for the version of REDUCE you want to build must be available.  This could be the `packages` directory installed as part of a binary distribution or a recent download from the [Subversion repository](https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/).  It is easiest to add the `packages` directory as a symbolic link in either the `common-lisp` directory or its parent.  (On Windows I recommend a directory symbolic link created using `mklink /d`.)  Alternatively, you can set the environment variable `reduce` to the directory containing the `packages` directory (with or without a trailing directory separator).  On Windows you can use either `\` or `/` as the directory separator.

Open a window running `bash` and make your chosen build directory current.  If you need to set the `reduce` environment variable, you can do it like this.  For example, to use the `packages` directory from a _default_ REDUCE installation to build SBCL REDUCE on MS Windows, execute the `bash` command

```sh
export reduce='C:/Program Files/Reduce'
```

or to build CLISP REDUCE on Cygwin, execute the `bash` command

```sh
export reduce='/cygdrive/c/Program Files/Reduce'
```

On Linux, use something like the following for all versions of Common Lisp:

```sh
export reduce='/usr/share/reduce'
```

### Determining the REDUCE revision

If you used Subversion to download or update a copy of the REDUCE distribution files from [SourceForge](https://sourceforge.net/projects/reduce-algebra/) then the build process should correctly determine the REDUCE revision from the `packages` directory, which contains all the REDUCE source code.  This determination uses the programs [`svnversion`](https://svnbook.red-bean.com/en/1.7/svn.ref.svnversion.re.html) and [`readlink`](https://www.gnu.org/software/coreutils/manual/html_node/readlink-invocation.html) (if available).  If that fails, the build script tries to parse a number out of the root directory, which should work if you downloaded a source snapshot from SourceForge (and did not change the root directory name).

Otherwise, or to override the default mechanisms described above, you can always specify the REDUCE revision by using the `-r` option to `build.sh`, e.g.

```sh
./build.sh -r <revision> -c <lisp>
```

The order of precedence of the mechanisms for determining the REDUCE revision is first the `-r` option, then `svnversion`, then the root directory.  **Note that the file `packages/support/revision.red` is no longer used.**

### Using unsupported versions of Common Lisp

There is some preliminary support for the Java-based [Armed Bear Common Lisp (ABCL)](https://abcl.org/) thanks to Rainer Schöpf, but it is not yet possible to preserve Lisp images so the ABCL version is not yet usable, and I am working on support for [Embeddable Common Lisp (ECL)](https://ecl.common-lisp.dev/).  But these need a different build script that I do not currently distribute.  To use ABCL, you need to ensure that you have a suitable Java runtime environment installed; the build and run scripts expect to find the command `java` on your search path.  You also need to download [abcl-bin-1.8.0.zip](https://abcl.org/releases/1.8.0/abcl-bin-1.8.0.zip) and unzip it (or build and install it) so that `abcl-bin-1.8.0/abcl.jar` exists in the `common-lisp` directory.


## Required version of `bash`

If you get `bash` errors then it is probably because you are running too old a version, so I recommend that you update it.  Alternatively, if you have a recent version of `bash` available but it is not run by default, you could run any of the commands described here using
```sh
/path/to/alternative/bash command
```
instead of
```sh
./command
```


## Implementation-specific functionality

On MS Windows, you can use either `\` or `/` to input directory separators; `\` is converted to `/` internally, so all output will use `/`.

REDUCE on Common Lisp tries to enable interactive Lisp debugging when it is run interactively and to disable it otherwise, but the mechanisms for doing this depend on the version of Common Lisp and are currently experimental.  Interactively, an interrupt signal generated by _Control-C_ should start a break loop that facilitates interactive debugging using Common Lisp syntax, initially in the `standard-lisp` package.  This could be useful to debug REDUCE code at the Lisp level.

The following facilities are modelled on those provided by PSL; please see the PSL manual for further details.

Lisp-level function tracing is provided by the commands `tr` and `trst`, which are available in both algebraic and symbolic modes.  A command of the form `tr fn1, fn2, ...;` (without any quotes) turns on tracing of the argument and return values of each of the functions `fn1`, `fn2`, etc.; if no functions are specified, i.e. `tr();` (or `tr nil;`), it lists all traced functions.  The command `trst` is similar but also traces assignments, which works for functions that have been compiled using `faslout` provided the appropriate Lisp file is still available in the `fasl` directory.  The commands `untr` and `untrst` (which is just a synonym for `untr`) turns off tracing; if no functions are specified they turn off tracing for all traced functions.  Input of function names uses Standard Lisp (i.e. REDUCE) syntax but output uses Common Lisp syntax, although it does not include any package prefixes, which can make Common Lisp tracing output from REDUCE look a little strange.  If a REDUCE algebraic-mode operator that is implemented by a Lisp function with a different name is traced, then the underlying Lisp function is automatically traced instead.

The tracing commands described above are independent of the Common Lisp `trace` and `untrace` macros, which are also made available (in symbolic mode only) via the names `cltrace` and `cluntrace` (to avoid clashing with the matrix trace operator).

Preliminary implementations of the `system`, `pipe-open` and `channelflush` functions are provided.  The functions `getenv`, `setenv` and `getpid` provide access to environment variables and the REDUCE process identifier, and should be portable across operating systems.

The commands `pwd()` or `cd "<directory>"` respectively return or change (and return) the current working directory.  The name `chdir` is an alias for `cd`.

Environment variables and dots (`.` or `..`) in filenames are expanded by `cd/chdir` and `open` relative to the current working directory of the REDUCE process.

The identifiers `common!-lisp` and `sl!-on!-cl` are always included in the list assigned to the standard REDUCE symbolic-mode variable `lispsystem!*` and the identifiers `sbcl`, `clisp`, `ccl` and `win32`, `cygwin`, `unix`, etc. are included as appropriate.  These identifiers indicate the Lisp and operating system on which REDUCE was built and can be used to customise the behaviour of REDUCE, as is done in some of the REDUCE files in this directory (but not at present in any other files).  The identifier `win32` means Microsoft Windows in general and appears for both 32 and 64-bit builds.  The identifier `unix` appears for Linux builds, and both `cygwin` and `unix` appear for Cygwin builds.

For Cygwin CLISP REDUCE (on MS Windows), the REDUCE `gnuplot` package tries to run Cygwin gnuplot if it is available and if not then it tries to run native MS Windows gnuplot (which is included in REDUCE binary distributions for MS Windows).  Cygwin gnuplot produces graphical output if REDUCE is run under the X Window System and text output otherwise.  For CLISP REDUCE on Linux and SBCL REDUCE on both MS Windows and Linux, gnuplot produces graphical output.


## Status

There are no build errors (unless specifically indicated to the contrary below).

I performed all testing on the same computer using Windows 11, a recent version of Cygwin and Ubuntu 24.04.3 LTS (GNU/Linux 6.6.87.2-microsoft-standard-WSL2 x86_64).  I tested production (i.e. non-debugging) builds using the standard REDUCE test framework by running commands of the form

```sh
../scripts/testall.sh --csl --psl --sbcl --clisp --ccl
```

"LispMath" below means the floating-point math (elementary transcendental) functions provided by Common Lisp, which I use if they appear to work well.  This is the case for SBCL and CCL, but not for CLISP.

### Windows

Lisp  | Total CPU Time (s) | Total GC Time (s)
------|--------------------|------------------
csl   | 85                 | 2
psl   | 196                | 1
sbcl  | 206                | 8
clisp | 1820               | 832
ccl   | 1129               | 345

#### Generic Regression Test Issues

Regression Test               | Comment / To Do
------------------------------|----------------
2011-08-31-linelength         | CSL and PSL printing overflows visibly; SL-on-CL printing designed not to!
2014-03-17-utf8-in-list       | Needs more work.  (PSL also differs.)  Might be fixable.
2019-07-30-sub-with-df        | Generic REDUCE issue?
2023-05-27-lambda-expressions | Algebraic lambda mostly works but freestanding lambda expressions not handled correctly.  Might be fixable.

#### Steel Bank Common Lisp (SBCL)

REDUCE 7298 on native Windows SBCL 2.6.1 (using LispMath)

Package Test | Comment / To Do
-------------|----------------
gf2          | Missing final backtrace.
numeric      | Expected numerical discrepancies.

Regression Test                    | Comment / To Do
-----------------------------------|----------------
2013-06-30-rounding                | Expected numerical discrepancies, but only for sin and in the lowest-order bit.
2014-11-09-accuracy-elementary-fns | Expected numerical discrepancies, but only in the lowest-order bit.

#### GNU CLISP

REDUCE 7298 on Cygwin CLISP 2.49 (**not** using LispMath)

Package Test | Comment / To Do
-------------|----------------
arith        | Expected numerical discrepancies.
economise    | Output truncated; presumably timed out.
gf2          | `+++ Error in call to gf2_groeb`
ibalp        | `*** - Program stack overflow. RESET`
numeric      | Expected numerical discrepancies.

Regression Test                    | Comment / To Do
-----------------------------------|----------------
2013-06-30-rounding                | Expected numerical discrepancies for pi, sin and sqrt(2).
2014-11-09-accuracy-elementary-fns | Expected numerical discrepancies; 2 large arguments invalid for sin.
2024-02-23-error-in-matrix-svd-computation | Expected numerical discrepancies.

#### Clozure Common Lisp (CCL)

REDUCE 7298 on native Windows CCL 1.13 (using LispMath)

Package Test | Comment / To Do
-------------|----------------
gf2          | `+++ Error in call to gf2_groeb`
lalr         | Compiled functions instead of lambdas (because CCL always compiles).
numeric      | Expected numerical discrepancies.
ofsf         | Output truncated; presumably timed out!

Regression test results as for SBCL.

### Ubuntu 24 (on WSL)

Lisp  | Total CPU Time (s) | Total GC Time (s)
------|--------------------|------------------
csl   | 121                | 2
psl   | 116                | 1
sbcl  | 188                | 4
clisp | 1384               | 401
ccl   | 1197               | 31

#### Steel Bank Common Lisp (SBCL)

REDUCE 7299 on SBCL 2.6.1 (using LispMath)

All test results very similar to those for Windows, except no differences for numeric package or 2013-06-30-rounding regression test.

### GNU CLISP

REDUCE 7299 on CLISP 2.49 (**not** using LispMath)

All test results very similar to those for Windows.

#### Clozure Common Lisp (CCL)

REDUCE 7299 on CCL 1.13 (using LispMath)

All test results very similar to those for Windows, except no differences for numeric package or 2013-06-30-rounding regression test.


## Known limitations

I cannot see any way to support the facilities for restricting execution time on CLISP or CCL.  In more detail: the file `rlisp/inter.red` defines procedures `with!-timeout` and similar that use garbage collection to provide an interrupt by assigning a function to the variable `!*gc!-hook!*`, but no garbage collection hooks exist in CLISP or CCL.  The procedures `with!-timeout` and similar just run without any restriction so don't use CLISP or CCL REDUCE is you need this facility!  It works on SBCL.


## To do

* Re-implement the sparse package to use hash tables as a test?
* Command-line option to suppress reading the REDUCE Startup File.
* Revise interaction between SL-on-CL `readch` and RLISP `readch1`.
* Check that command-line options to redsbcl etc. work; the preserved REDUCE executable may not handle them!
* Review my hacked version of `gnuintfc.red` for Common Lisp.

* Make faslout/faslend more robust by using a single function that calls begin internally (cf. infile) and make faslend generate a throw.  (See also the old mkfasl code?)
* Implement a genuinely lower-case Standard Lisp, perhaps using case-inversion for a few special symbols such as `lambda`, `nil`, `t`?

<!-- Local Variables: -->
<!-- fill-column: 1000 -->
<!-- eval: (auto-fill-mode -1) -->
<!-- eval: (visual-line-mode 1) -->
<!-- eval: (visual-wrap-prefix-mode 1) -->
<!-- End: -->
