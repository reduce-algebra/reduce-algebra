# Web REDUCE

## Francis Wright, July 2021 - April 2024

**This project is highly experimental!**

This project aims to provide via the REDUCE web site a public user interface for the [WebAssembly](https://webassembly.org/) (Wasm) version of REDUCE by Arthur Norman and Avery Laird, which is CSL REDUCE compiled to WebAssembly using [Emscripten](https://emscripten.org/).
The Web REDUCE GUI is modelled on the [Run-REDUCE](https://fjwright.github.io/Run-REDUCE/) GUI for conventional REDUCE.

I use [TypeScript](https://www.typescriptlang.org/) to generate JavaScript files in the directory `generated` from the TypeScript files in the `typescript` directory by running the command `tsc` in the root directory (`web-reduce`). This assumes that TypeScript is installed globally using `npm install -g typescript` (which requires [Node.js](https://nodejs.org/en/)).
The `typescript` directory is not used to run Web REDUCE.

The WebAssembly version of REDUCE is built in the directory `csl/new-embedded/for-emscripten/`. Run `make webreduce` and then copy the two files `reduce.web.js` and `reduce.web.wasm` to the directory `web/htdocs/web-reduce/generated/`. Check that the file `for-emscripten/package.map` is appropriate, run `make mini-webreduce` and then copy the two files `reduce.web.js` and `reduce.web.wasm` to the directory `web/htdocs/web-reduce/mobile/`.

15 April 2024: The version currently on the REDUCE web site is the latest revision of REDUCE built using Emscripten 2.0.34, because I have had problems using later Emscripten versions. The main version of Web REDUCE is currently built without the "pre-js" code included via Emscripten, because to facilitate development this code is temporarily provided separately as the file `generated/reduce.pre.js`, which imports `generated/reduce.web.js`.

Web REDUCE is available online as [https://reduce-algebra.sourceforge.io/web-reduce/](https://reduce-algebra.sourceforge.io/web-reduce/). See [About Web REDUCE](https://reduce-algebra.sourceforge.io/web-reduce/about.html) for further details, including limitations of the WebAssembly version of REDUCE that I am aware of so far. (But, once downloaded, it's surprisingly fast!)

## TO DO

- Arrange to wait for an asynchronous load_package to have happened before sending further input to REDUCE. (Fixed for input via the menus.)
- Load package and switch menu items? Could use loadable!-packages!_ and switches!_ defined in "packages/support/cslrend.red".

## Web Gnuplot, April 2024

This addition is based on https://github.com/CD3/gnuplot-in-the-browser by
C.D. Clark III. However, I have revised the recipe a little to use `make` to
build the last stable version of Gnuplot, namely 5.4.10, and avoid as many
redundant components and build warnings as possible.

I build Gnuplot using Emscripten to generate the main WASM and JS
files in the subdirectory `gnuplot` and JS files to support the
canvas terminal in the subdirectory `gnuplot/termjs`. Note that
this build needs to be done on Linux; Cygwin doesn't work because
using Emscripten under Cygwin is too awkward. Gnuplot makes essential
use of GNU `configure` and `make`, which don't work on native
Windows. However, building on Ubuntu 22.04 under Windows Subsystem
for Linux on Windows 11 seems to work well once `make` and a few
libraries are installed.

This project was suggested by Hermans Rolfes and
use [his code](https://github.com/kungfooman/WebREDUCE/) as a guide to how to
call Gnuplot from REDUCE.

[Gnuplot 6.0 Terminals](http://gnuplot.info/docs_6.0/Terminals.html)
describes the [canvas](http://gnuplot.info/docs_6.0/loc19528.html) terminal type.

## TO DO

- Upgrade to Gnuplot 6.0.0 (maybe).
- Support multiple plots.
- Fix some bugs, e.g. why does `plot(cos x)` cause an error whereas `plot (cos x)` doesn't?
