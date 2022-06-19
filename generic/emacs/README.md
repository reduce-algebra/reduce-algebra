GNU Emacs REDUCE Integrated Development Environment
===================================================
Major modes for editing and running REDUCE source code
------------------------------------------------------

**[Francis Wright](https://sourceforge.net/u/fjwright)**

Version 1.6, June 2022

REDUCE IDE is a package that provides an Integrated Development Environment for the REDUCE computer algebra system within the GNU Emacs editor.  Its two major components are Emacs Lisp libraries that provide major modes for respectively editing REDUCE source code and running a *command-line version* of REDUCE in an Emacs window.  However, many of the facilities require that Emacs is running under a GUI such as Microsoft Windows or the X Window System under some flavour of UNIX or Linux.

I currently use GNU Emacs 28 (on Microsoft Windows) for development and testing, and REDUCE IDE may not work correctly with older versions.

Source files
------------

Required:

* `reduce-mode.el`  &ndash;  REDUCE source code editing mode

Optional:

* `reduce-font-lock.el`  &ndash;  support syntactic highlighting
* `reduce-delim.el`  &ndash;  highlight matching group or block delimiters
* `reduce-run.el`  &ndash;  run REDUCE in an Emacs buffer
* `reduce-ide.texinfo`  &ndash;  texinfo documentation

Installation
------------

Provided you are using GNU Emacs 24 or later, I recommend that you install the complete package, including documentation in info format, by following the instructions on the [REDUCE IDE home page](https://reduce-algebra.sourceforge.io/reduce-ide/).  Alternatively, download `reduce-mode.el` and any other required `.el` files from [SourceForge](https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/generic/emacs/) to any convenient directory and run the Emacs command `package-install-file` on `reduce-mode.el` and then optionally on the other `.el` files.  *Note that `reduce-mode.el` must be installed first*.  For further details, see *Packages* in the Emacs manual.

For brief manual installation instructions see the comments after *Usage* in the `.el` files.

Documentation
-------------

The user's guide, generated from `reduce-ide.texinfo`, is available as a 32-page PDF document or a multi-page HTML document via the [REDUCE IDE home page](https://reduce-algebra.sourceforge.io/reduce-ide/).

You can also generate documentation yourself in various formats, including `info`, `HTML` and `PDF`, from `reduce-ide.texinfo`, but you need the [GNU Texinfo package](https://www.gnu.org/software/texinfo/).  The commands I used to generate the formats that I provide are listed at the end of `reduce-ide.texinfo`.  For further details, please read sections 20 to 22 of the [Texinfo manual](https://www.gnu.org/software/texinfo/manual/texinfo/) or this [quick summary](https://en.wikipedia.org/wiki/Texinfo).

To Do
-----

* Support C-style comments.
* Further rationalise and perhaps simplify the font-lock support.
* Maybe highlight nested function calls without ().
