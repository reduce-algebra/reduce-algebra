GNU Emacs REDUCE Integrated Development Environment
===================================================
Major modes for editing and running REDUCE source code
------------------------------------------------------

**[Francis Wright](https://sites.google.com/site/fjwcentaur)**

Version 1.7, September 2022

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

* Full font-lock support for C-style comments (which currently prevent some other font locking).
* Further rationalise and perhaps simplify the font-lock support.
* Maybe highlight nested function calls without ().
* Check switch-to-reduce and related commands.
* Check that sexp commands skip comments and add a kill sexp command.

Main Updates since REDUCE IDE 1.6 (see the manual for details)
--------------------------------------------------------------

* **INCOMPATIBLE CHANGE:** The command `run-reduce` is now the only way to run REDUCE.  It prompts for the REDUCE command name to run, defaulting to the last one used.
* The commands `run-csl-reduce` and `run-psl-reduce` have been removed; use `run-reduce` and select the appropriate command name instead.
* The customizable option `reduce-run-commands` now accepts arbitrary key strings and an arbitrary number of REDUCE versions.
* Improved access to the `comint` customization group (since REDUCE Run mode inherits from comint).
* `<RET>` in REDUCE Run mode now adds a `;` statement terminator automatically as appropriate (whereas `S-<RET>` never adds a terminator).
* REDUCE mode now inherits from `prog-mode`, so it runs `prog-mode-hook` and some `prog-mode` customizations are relevant.
* Initial support for C-style `/**/` comments: they are now highlighted as comments and movement commands should skip them.
* **INCOMPATIBLE CHANGE:** The command `reduce-eval-line` is now bound to the key sequence `C-c C-e` instead of `C-c C-n`, which was already bound to `reduce-forward-statement`.
* Improved code relating to all the commands that move by statements and expressions.
* **INCOMPATIBLE CHANGE:** The customizable option `reduce-max-up-tries` is now called `reduce-max-escape-tries`.
