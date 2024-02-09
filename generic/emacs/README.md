GNU Emacs REDUCE Integrated Development Environment
===================================================
Major modes for editing and running REDUCE source code
------------------------------------------------------

**[Francis Wright](https://sites.google.com/site/fjwcentaur)**

Version 1.11, February 2024

REDUCE IDE is a package that provides an Integrated Development Environment for the [REDUCE computer algebra system](https://reduce-algebra.sourceforge.io/) within the GNU Emacs editor.  Its two major components are Emacs Lisp libraries that provide major modes for editing REDUCE source code and running a *command-line version* of REDUCE in an Emacs window.  It assumes that Emacs is running under a GUI such as Microsoft Windows or the X Window System under some flavour of UNIX or Linux, and displays Unicode character sets correctly.  REDUCE IDE does not include REDUCE, which is available separately from [SourceForge](https://sourceforge.net/projects/reduce-algebra/).  You don't need to install REDUCE in order to edit REDUCE source code using REDUCE IDE, but if you want to run REDUCE in REDUCE IDE then you do need to install REDUCE.

REDUCE IDE now formally requires GNU Emacs version 27 at least although I support only GNU Emacs 29 on Microsoft Windows and Linux.

Installation
------------

I recommend that you install the latest complete package, which includes the manual in Info format, by following the instructions on the [REDUCE IDE home page](https://reduce-algebra.sourceforge.io/reduce-ide/).  Alternatively, you can download a package file (see [*Repositories and Releases*](#repositories-and-releases) below) to any convenient directory and run the Emacs command `package-install-file` on it.  For further details, see [*Packages* in the Emacs manual](https://www.gnu.org/software/emacs/manual/html_node/emacs/Packages.html).

Documentation
-------------

The REDUCE IDE manual should be available as an Info document in Emacs, normally at the top of the Info directory, once you have installed the REDUCE IDE package.  It is also available as a PDF document and a multi-page HTML document via the [REDUCE IDE home page](https://reduce-algebra.sourceforge.io/reduce-ide/).

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

* Check relation between standard and REDUCE mode key bindings.
* Check switch-to-reduce and related commands.

Main Updates since REDUCE IDE 1.10
----------------------------------

* Define key `Meta-R` in the REDUCE mode key map to run REDUCE.
* Revise detection of end-of-file marker, which must now be at start of line.
* Repair `re-run-reduce` to support general REDUCE command names and no name (i.e. an explicit command), rename it to `rerun-reduce` and revise the wording of the menu item to (Re)Run REDUCE.
* Correct highlighting of fluid variables in a vertical list, such as at start of `int/driver.red`.
* Repair `reduce-comment-procedure` and `reduce-reposition-window`.
* Revise manual and move customization of REDUCE Run mode into the chapter on general customization of REDUCE IDE.
* Remove `require-reduce-run`, and run `reduce-mode-load-hook` before requiring `reduce-run`.
* Revise manual and move Run Keys section into other Run mode sections.
* Improve Run REDUCE menu.
* Remove redundant Package-Version headers; keep only in `reduce-mode.el`.
* Correct `reduce-run-file` and revise `reduce--wait-for-prompt`.
* Remove `reduce-run-buffer` key bindings from REDUCE Run mode.
* Make `reduce-fasl-file` an alias for `reduce-compile-file`, rather than vice versa.
* Add REDUCE mode font lock support to the previous output font lock support in run mode.
* Add REDUCE show delim support to run mode.
* Add minimal font-lock level, which is syntactic plus the old font-lock support in run mode, and syntactic-only in edit mode.
* Revise `reduce-run-file` and `reduce-run-buffer` to prompt for the REDUCE command (via `run-reduce`).
* Add option `reduce-run-command-name-default` to specify the default REDUCE command name, which defaults to the first command name in `reduce-run-commands`.
* Replace `...` with Unicode horizontal ellipsis `…`.
* Add *Customize…* item to REDUCE mode Run REDUCE menu.
* Simplify `run-reduce` and no longer use a pop-up window, which was overkill.  Now, a null command name aborts the run.  I think these changes finally repair `reduce-run-file`, which calls `run-reduce`.
* Improve Imenu support to handle REDUCE syntax.
* Repair and update Show Proc code.  Turn it on by default.  Add support for mouse menu, cf. which-function-mode.
* Replace reduce-show-proc-delay with idle-update-delay.
* Make Show Proc a proper buffer-local minor mode turned on automatically if the new option `reduce-show-proc-mode-on` is non-nil.
* Fix a minor font-lock bug causing a transient error message.
* Add links to the manual to all customizable options.
* Rename `autoload-reduce-run` to `reduce-run-autoload`.
* Add menu item to read the REDUCE IDE manual.
* Comment out obsolete menu item to add a change log entry.
* Make Auto Indent a proper buffer-local minor mode turned on automatically if the new option `reduce-auto-indent-mode-on` is non-nil.  Revise `reduce-auto-indent-regexp` to allow arbitrary text between the trigger and point, which seems to work much better.
* Make Show Delim a proper buffer-local minor mode.  Replace `reduce-show-delim-delay` with `show-paren-delay`.
* Add Show Version item to end of main run menu.
* Remove choice menu from `reduce-run-commands` customization.
* New option `reduce-run-terminal` to specify value of TERM to use on Unix-like platforms so that CSL REDUCE responds appropriately to interrupts, which with a dumb terminal it does not.  It defaults to nil on MS Windows and to `Eterm` on all other platforms.
* Only remove `ansi-color-process-output` on MS Windows; it is necessary for CSL REDUCE on Linux and probably redundant on MS Windows.
* **Incompatible key binding changes**: `reduce-input-file` is now bound to `C-c C-f`, `reduce-compile-file` to `C-c C-M-c`, `reduce-eval-line` to `C-c C-M-e`, and `reduce-load-package` to `C-c C-M-l` to avoid conflicts with other bindings.  Vector key definitions replaced with strings where possible.
