#! /bin/bash -v

# Create a distribution archive for the material in this directory.

pushd ..

tar cvfj reduce2/reduce2.tar.bz2 \
    reduce2/README \
    reduce2/REDUCE.RED \
    reduce2/reduce.red.patched \
    reduce2/reduce.lsp.initial \
    reduce2/reduce.lsp \
    reduce2/tolisp.sh \
    reduce2/build2.sh \
    reduce2/test1.sh \
    reduce2/test2.sh \
    reduce2/vsl/vsl.c \
    reduce2/vsl/vsl.lsp \
    reduce2/buildvsl.sh \
    reduce2/testvsl.sh \
    reduce2/maketar.sh

popd
