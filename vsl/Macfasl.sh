#! /bin/bash -v

# This tries to make a PSL compiler that will generate FASL files, ie
# it should support the idiom
#   (faslout 'foo) (dskin "file") (faslend)
# and create a file called "foo.b".

make psl OPT="-O0 -g"

script Macfasl.log <<XXX
./vsl xxxfasl.lsp -Dmachine=macintel64 -o Macfasl.img
XXX
