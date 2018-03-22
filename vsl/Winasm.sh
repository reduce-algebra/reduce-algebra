#! /bin/bash -v

# This makes Winasm.img, which contains a version of the
# PSL compiler set up to generate textual assembly code.

make psl OPT="-O0 -g"

script -c "./vsl Winasm.lsp -o Winasm.img" Winasm.log

