# GNU Emacs REDUCE Integrated Development Environment #

## Major modes for editing and running REDUCE source code ##

### [Francis Wright](https://sites.google.com/site/fjwcentaur) ###

Version 1.14, April 2025

REDUCE IDE is a package that provides an Integrated Development Environment for the [REDUCE computer algebra system](https://reduce-algebra.sourceforge.io/) within the GNU Emacs editor.  Its two major components are Emacs Lisp libraries that provide major modes for editing REDUCE source code and running a *command-line version* of REDUCE in an Emacs window.  It assumes that Emacs is running under a GUI such as Microsoft Windows or the X Window System under some flavour of UNIX or Linux, and displays Unicode character sets correctly.  REDUCE IDE does not include REDUCE, which is available separately from [SourceForge](https://sourceforge.net/projects/reduce-algebra/).  You don't need to install REDUCE in order to edit REDUCE source code using REDUCE IDE, but if you want to run REDUCE in REDUCE IDE then you do need to install REDUCE.

REDUCE IDE now requires GNU Emacs version 29 or later and I support only Microsoft Windows and Linux.

## Installation ##

I recommend that you install the latest complete package, which includes the manual in Info format, by following the instructions on the [REDUCE IDE home page](https://reduce-algebra.sourceforge.io/reduce-ide/).  Alternatively, you can download a package file (see [*Repositories and Releases*](#repositories-and-releases) below) to any convenient directory and run the Emacs command `package-install-file` on it.  For further details, see [*Packages* in the Emacs manual](https://www.gnu.org/software/emacs/manual/html_node/emacs/Packages.html).

## Documentation ##

The REDUCE IDE manual should be available as an Info document in Emacs, normally at the top of the Info directory, once you have installed the REDUCE IDE package.  It is also available as a PDF document and a multi-page HTML document via the [REDUCE IDE home page](https://reduce-algebra.sourceforge.io/reduce-ide/).

You can also generate the manual yourself in various formats, including `info`, `HTML` and `PDF`, from `reduce-ide.texinfo`, but you need the [GNU Texinfo package](https://www.gnu.org/software/texinfo/).  The commands I used to generate the formats that I provide are listed at the end of the file `reduce-ide.texinfo`.  For further details, please see sections 20 to 22 of the [Texinfo manual](https://www.gnu.org/software/texinfo/manual/texinfo/) or this [quick summary](https://en.wikipedia.org/wiki/Texinfo).

## Repositories and Releases ##

The primary repository is [GitHub](https://github.com/fjwright/REDUCE-IDE).  The main source files (only, see below) for release versions are also available from [SourceForge](https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/generic/emacs/).  Releases as Emacs package (`.tar`) files are available from [GitHub](https://github.com/fjwright/REDUCE-IDE/releases) and in a more convenient form that is recognised by the Emacs package manager via the [REDUCE IDE home page](https://reduce-algebra.sourceforge.io/reduce-ide/).

## Main Source Files ##

Required:

* `reduce-mode.el`  &ndash;  REDUCE source code editing mode

Optional:

* `reduce-font-lock.el`  &ndash;  support syntactic highlighting
* `reduce-delim.el`  &ndash;  highlight matching group or block delimiters
* `reduce-run.el`  &ndash;  run REDUCE in an Emacs buffer
* `reduce-extra.el`  &ndash;  experimental optional extra functionality
* `reduce-ide.texinfo`  &ndash;  texinfo manual

## To Do ##

* Check relation between standard and REDUCE mode key bindings.
* Check switch-to-reduce and related commands.
* Resolve REDUCE Run mode fontification clash with Comint mode.
* On Microsoft Windows, make REDUCE interruptible.
* Version 2 (maybe): use treesitter for parsing.
* Make double-click select a group or block, as for brackets.

## Main Updates since REDUCE IDE 1.13 ##

* Repair the `rerun-reduce` command.
* Declare the `reduce-run-buffer` command to autoload.
* Implement `reduce-forward-word` and `reduce-backward-word` to replace `reduce-forward-identifier` and `reduce-backward-identifier`.  The aim is to move by a number or identifier, more like `forward-word` etc., which should improve mouse double-click selection.
* Rename `reduce-identifier-mode` to `reduce-word-mode` and the _Minor Modes / Identifier Mode_ menu option to _Minor Modes / Word Mode_.
* Hide the `Add "Index" Menu` menu item if it has already been added, and rename it to `Add Index Menu`.
* Fix REDUCE mode _Run REDUCE_ menu, and hence _Run Buffer_ etc.: only autoload functions not already autoloaded.
* Improve some keyboard shortcuts in the _REDUCE_ menu.
* Fix _Command Mini Help_ menu item to show only commands intended for user access.
* Rename REDUCE Run mode menu from _Run REDUCE_ to _REDUCE_, and REDUCE mode Run menu from _Run REDUCE_ to _Run-REDUCE_.
* Fix key mapping for `run-reduce`.
* Fix `reduce-run--wait-for-prompt`.  Sending code to REDUCE before it is running should now work better.
* Do not treat `!'` as a quote for syntax highlighting.
* Introduce new option `reduce-etags-regexps` to allow customization of tagging.  Tag `put(‘name, ‘psopfn, …)` and `put(‘name, ‘simpfn, …)` as declarations of operator names, and `operator` declarations with up to 5 names, making it easier to track algebraic-mode operators.
* Allow REDUCE to be run from a buffer running or having run a different version of REDUCE (with a different root directory).
* Improve indentation and spacing for insert block and group commands.
* Change the default directory for `reduce-tagify-dir-recursively` to the _parent_ of the current directory.

<!-- Local Variables: -->
<!-- fill-column: 1000 -->
<!-- eval: (auto-fill-mode -1) -->
<!-- eval: (visual-line-mode 1) -->
<!-- eval: (visual-wrap-prefix-mode 1) -->
<!-- End: -->
