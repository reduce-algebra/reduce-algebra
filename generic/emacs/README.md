GNU Emacs REDUCE Integrated Development Environment
===================================================
Major modes for editing and running REDUCE source code
------------------------------------------------------

**[Francis Wright](https://sites.google.com/site/fjwcentaur)**

Version 1.8, October 2022

REDUCE IDE is a package that provides an Integrated Development Environment for the REDUCE computer algebra system within the GNU Emacs editor.  Its two major components are Emacs Lisp libraries that provide major modes for editing REDUCE source code and running a *command-line version* of REDUCE in an Emacs window.  It assumes that Emacs is running under a GUI such as Microsoft Windows or the X Window System under some flavour of UNIX or Linux, and displays Unicode character sets correctly.

I currently use GNU Emacs 28 (on Microsoft Windows) for development and testing, and REDUCE IDE may not work correctly with older versions.

Installation
------------

I recommend that you install the latest complete package, which includes the manual in Info format, by following the instructions on the [REDUCE IDE home page](https://reduce-algebra.sourceforge.io/reduce-ide/).  Alternatively, you can download a package file (see Releases below) to any convenient directory and run the Emacs command `package-install-file` on it.  For further details, see *Packages* in the Emacs manual.

Documentation
-------------

The REDUCE IDE manual is available as an Info document in Emacs, normally at the top of the Info directory, once you have installed the REDUCE IDE package.  It is also available as a PDF document and a multi-page HTML document via the [REDUCE IDE home page](https://reduce-algebra.sourceforge.io/reduce-ide/).

You can also generate the manual yourself in various formats, including `info`, `HTML` and `PDF`, from `reduce-ide.texinfo`, but you need the [GNU Texinfo package](https://www.gnu.org/software/texinfo/).  The commands I used to generate the formats that I provide are listed at the end of the file `reduce-ide.texinfo`.  For further details, please see sections 20 to 22 of the [Texinfo manual](https://www.gnu.org/software/texinfo/manual/texinfo/) or this [quick summary](https://en.wikipedia.org/wiki/Texinfo).

Repositories and Releases
-------------------------

The primary repository is [GitHub](https://github.com/fjwright/REDUCE-IDE).  The main source files (only, see below) for release versions are also available from [SourceForge](https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/generic/emacs/).  Releases as Emacs package (`.tar`) files are available from [GitHub](https://github.com/fjwright/REDUCE-IDE/releases) and in a more convenient form that is recognised by the Emacs package manager via the [REDUCE IDE home page](https://reduce-algebra.sourceforge.io/reduce-ide/).

Main Source Files
-----------------

Required:

* `reduce-mode.el`  &ndash;  REDUCE source code editing mode

Optional:

* `reduce-font-lock.el`  &ndash;  support syntactic highlighting
* `reduce-delim.el`  &ndash;  highlight matching group or block delimiters
* `reduce-run.el`  &ndash;  run REDUCE in an Emacs buffer
* `reduce-ide.texinfo`  &ndash;  texinfo manual

To Do
-----

* Check switch-to-reduce and related commands.

Main Updates since REDUCE IDE 1.7 (see the manual for details)
--------------------------------------------------------------

* Use lexical scoping, which might be a little faster.
* **INCOMPATIBLE CHANGE:** The commands `reduce-forward-sexp` and `reduce-backward-sexp` no longer accept an argument and now skip any comments or white space, but **not terminators**, between point and the "balanced expression".
* Add the command `reduce-kill-sexp` to kill one "balanced expression" either forwards or, with any argument, backwards, bound to `C-M-k`.
* Reliably disregard ! as an escape character at the end of a string, which would otherwise mask the end of the string.
* Treat the escape character (!) as part of a word for motion commands.
* Use Emacs parsing in preference to heuristics to detect whether point is in a string or (% or /**/) comment.
* The command `reduce-kill-procedure` now accepts an argument.
* Operations based on procedures now support `matrixproc`, `listproc`, and procedure type declarations.  They report a user error if they fail.
* Syntax Highlighting:
  * More robust highlighting of comment statements.
  * There are now three strictly inclusive levels: “Symbolic” includes “Algebraic” includes “Basic”.
  * Highlight group delimiters the same as block delimiters.
  * Highlight named constants such as Catalan.
  * Highlight symbolic-mode functions such as get and put as builtin functions.
  * Highlight lambda arguments the same as procedure arguments.
  * Fix some errors.  Should be more robust and possibly slightly faster.
