#! /bin/bash -v

# This tries to make a PSL compiler that will generate FASL files, ie
# it should support the idiom
#   (faslout 'foo) (dskin "file") (faslend)
# and create a file called "foo.b".

# It has the same configuration as make-psl-compiler-asm.sh

make psl OPT="-O0 -g"

script -c "./vsl psl-compiler-fasl.lsp -o pslcomp-fasl.img" pslcomp-fasl.log

