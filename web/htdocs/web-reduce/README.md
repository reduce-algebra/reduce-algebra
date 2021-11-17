Web REDUCE
==========

Francis Wright, November 2021
-----------------------------

**This project is highly experimental!**

It aims to provide an alternative user interface for the [WebAssembly](https://webassembly.org/) (Wasm) version of REDUCE by Arthur Norman and Avery Laird, which is CSL REDUCE compiled to WebAssembly using [Emscripten](https://emscripten.org/).  See [https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/csl/new-embedded/for-emscripten/](https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/csl/new-embedded/for-emscripten/) for details of how to build the WebAssembly version of REDUCE, which consists of two files, `reduce.web.js` and `reduce.web.wasm`.  Alternatively, you can download the 16-Feb-2021 versions of these two files from Arthur Norman's web site at http://acn1.atwebpages.com/.  They need to be in the same location as the HTML file that loads them, which **must** be accessed via a web server.  I find that the Python web server does not work with Firefox on Windows, causing it to complain about a MIME error, but other web servers seems to work fine.

The Web REDUCE GUI is modelled on the [Run-REDUCE](https://fjwright.github.io/Run-REDUCE/) GUI for conventional REDUCE.

Web REDUCE is available online as [https://reduce-algebra.sourceforge.io/web-reduce/](https://reduce-algebra.sourceforge.io/web-reduce/).  See [About Web REDUCE](https://reduce-algebra.sourceforge.io/web-reduce/about.html) for further details, including limitations of the WebAssembly version of REDUCE that I am aware of so far.  (But, once downloaded, it's surprisingly fast!)

TO DO
=====

* Arrange to wait for an asynchronous load_package to have happened before sending further input to REDUCE. This would be easy except that the next input needs to wait for REDUCE to respond to the previous input.

* Load package and switch menu items?  Could use loadable!-packages!* and switches!* defined in "packages/support/cslrend.red".
