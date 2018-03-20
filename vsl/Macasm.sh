#! /bin/bash -v

# This makes Macasm.img, which contains a version of the
# PSL compiler set up to generate textual assembly code.

# At present this FAILS because it tried to do a binary write operation.
# I will investigate at s0ome later stage... the AMD version is more usable
# at present.

make psl OPT="-O0 -g"

script -c "./vsl Macasm.lsp -o Macasm.img" Macasm.log

