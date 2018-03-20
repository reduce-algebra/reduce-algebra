#! /bin/bash -v

# This makes AMDasm.img, which contains a version of the
# PSL compiler set up to generate textual assembly code.

make psl OPT="-O0 -g"

script -c "./vsl AMDasm.lsp -o AMDasm.img" AMD-asm.log

