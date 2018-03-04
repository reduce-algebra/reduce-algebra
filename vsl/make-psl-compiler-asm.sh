#! /bin/bash -v

# This makes psl-compile-asm.img, which contains a version of the
# PSL compiler set up to generate textual assembly code.

# At present this compiler uses the AMD64_ext back-end and configuration
# and then process the resulting main.s and dmain.s files. But note horribly
# well that Linux and the Macintosh use one "standard" set of registar
# conventions and calling standards and Windows (including Cygwin) another,
# while the native parts of PSL at present use yet a third. And that is
# before considerations of relocatability, the presense (or not) of initial
# undercores in names and other little issues!



make psl OPT="-O0 -g"

script -c "./vsl psl-compiler-asm.lsp -o pslcomp-asm.img" pslcomp-asm.log

