#! /bin/bash

# Build the program "make-cygwin-symlink" that can be called as
#   ./make-cygwin-symlink "full windows name" short-linux-name
#
# The effect of this is roughly as if cygwin had been active and
# one had gone
#   ln -s `cygpath "full windows name"` /usr/local/bin/short-linux-name
# for each installation of cygwin found.

i686-w64-mingw32-gcc make-cygwin-symlink.c -o cslbuild/make-cygwin-symlink

