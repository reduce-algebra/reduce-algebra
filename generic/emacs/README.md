# GNU Emacs REDUCE Integrated Development Environment

## Major modes for editing and running REDUCE source code

**[Francis Wright](https://sites.google.com/site/fjwcentaur)**

Version 1.13, December 2024

REDUCE IDE is a package that provides an Integrated Development Environment for the [REDUCE computer algebra system](https://reduce-algebra.sourceforge.io/) within the GNU Emacs editor. Its two major components are Emacs Lisp libraries that provide major modes for editing REDUCE source code and running a _command-line version_ of REDUCE in an Emacs window. It assumes that Emacs is running under a GUI such as Microsoft Windows or the X Window System under some flavour of UNIX or Linux, and displays Unicode character sets correctly. REDUCE IDE does not include REDUCE, which is available separately from [SourceForge](https://sourceforge.net/projects/reduce-algebra/). You don't need to install REDUCE in order to edit REDUCE source code using REDUCE IDE, but if you want to run REDUCE in REDUCE IDE then you do need to install REDUCE.

REDUCE IDE now requires GNU Emacs version 29 or later and I support only Microsoft Windows and Linux.

## Installation

I recommend that you install the latest complete package, which includes the manual in Info format, by following the instructions on the [REDUCE IDE home page](https://reduce-algebra.sourceforge.io/reduce-ide/). Alternatively, you can download a package file (see [_Repositories and Releases_](#repositories-and-releases) below) to any convenient directory and run the Emacs command `package-install-file` on it. For further details, see [_Packages_ in the Emacs manual](https://www.gnu.org/software/emacs/manual/html_node/emacs/Packages.html).

## Documentation

The REDUCE IDE manual should be available as an Info document in Emacs, normally at the top of the Info directory, once you have installed the REDUCE IDE package. It is also available as a PDF document and a multi-page HTML document via the [REDUCE IDE home page](https://reduce-algebra.sourceforge.io/reduce-ide/).

You can also generate the manual yourself in various formats, including `info`, `HTML` and `PDF`, from `reduce-ide.texinfo`, but you need the [GNU Texinfo package](https://www.gnu.org/software/texinfo/). The commands I used to generate the formats that I provide are listed at the end of the file `reduce-ide.texinfo`. For further details, please see sections 20 to 22 of the [Texinfo manual](https://www.gnu.org/software/texinfo/manual/texinfo/) or this [quick summary](https://en.wikipedia.org/wiki/Texinfo).

## Repositories and Releases

The primary repository is [GitHub](https://github.com/fjwright/REDUCE-IDE). The main source files (only, see below) for release versions are also available from [SourceForge](https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/generic/emacs/). Releases as Emacs package (`.tar`) files are available from [GitHub](https://github.com/fjwright/REDUCE-IDE/releases) and in a more convenient form that is recognised by the Emacs package manager via the [REDUCE IDE home page](https://reduce-algebra.sourceforge.io/reduce-ide/).

## Main Source Files

Required:

- `reduce-mode.el` &ndash; REDUCE source code editing mode

Optional:

- `reduce-font-lock.el` &ndash; support syntactic highlighting
- `reduce-delim.el` &ndash; highlight matching group or block delimiters
- `reduce-run.el` &ndash; run REDUCE in an Emacs buffer
- `reduce-extra.el` &ndash; experimental optional extra functionality
- `reduce-ide.texinfo` &ndash; texinfo manual

## To Do

- Check relation between standard and REDUCE mode key bindings.
- Check switch-to-reduce and related commands.
- Resolve REDUCE Run mode fontification clash with Comint mode.
- On Microsoft Windows, make REDUCE interruptible.
- Version 2 (maybe): use treesitter for parsing.

## Main Updates since REDUCE IDE 1.12

- Add `reduce-extra.el`, which currently is loaded via `reduce-mode-load-hook` and provides experimental optional extra functionality. Since it is experimental it may be subject to incompatible changes and may not be documented in the REDUCE IDE manual. Currently, `reduce-extra.el` adds optional identifier motion functionality via the minor mode `reduce-identifier-mode`, which is turned on automatically via `reduce-mode-hook`, and functionality to quickly select a block or group. Please see `reduce-extra.el` for details.
- Require Emacs 29 or later. Updates to accommodate Emacs 30.
- If no input, send a newline to REDUCE to support `on demo`.
- Replace the REDUCE Mode Run menu stub with a version of the full REDUCE Mode Run menu that autoloads REDUCE Run.
- Add a `Minor Modes` submenu to the major mode menu and move `Show Current Proc` into it.
- Better support for multiple REDUCE installations. Allow a root directory to be specified separately for each REDUCE command so that configuring multiple installations is easier and more consistent. Use this local root as the value for both the shortcut `$reduce` and the `reduce` environment variable. Also use it to find the `packages` directory. This requires small changes to the details of the options `reduce-root-dir-file-name` and `reduce-run-commands`. The option `reduce-packages-directory` is now obsolete. Validate that REDUCE root directories are accessible and automatically convert them to absolute directory file names.

<!-- Local Variables: -->
<!-- fill-column: 1000 -->
<!-- eval: (auto-fill-mode -1) -->
<!-- eval: (visual-line-mode 1) -->
<!-- eval: (visual-wrap-prefix-mode 1) -->
<!-- End: -->
