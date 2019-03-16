#! /bin/bash

# This must be run from a cygwin64 shell.

C/scripts/cygwin-sanity-check.sh

# Configure and build CSL version from scratch

#     a native-style win64 version. Always done the same way.

./cslbuild1.sh win64

#     a cygwin64 version.

./cslbuild1.sh cyg64

# Now all versions should be built. Check sizes.

ls -lh csl*/csl/csl.exe csl*/csl/csl.com csl*/csl/csl.img
ls -lh csl*/csl/reduce.exe csl*/csl/reduce.com csl*/csl/reduce.img
ls -lh csl*/csl/bootstrapreduce.exe csl*/csl/bootstrapreduce.img

# Now assemble the various executables that I made in the cslwin64 and
# cslcyg64 directories, together with two small helper programs
# to make "fat" binaries that are expected to run in all cirmumstances. Of
# these reduce.exe will be a console-mode application and it will run in
# either a 64-bit environment either under native Windows or when
# invoked from an xterm or mintty terminal under cygwin. The other is
# winreduce.exe and that is linked as a Windows application so it is
# suitable for double clicking on. It will run 64-bit mode. Both of
# these (and in all circumstances) use the same single reduce.img image file.

rm -rf cslbuild
mkdir -p cslbuild

./fatbinary.sh

# I want a program that can establish cygwin symlinks but that is a regular
# Windows program. This is for calling from an installer.

./set-up-symlinks.sh

# The files that I list here are the ones that are the "results" from
# this script.

ls -lh cslbuild

# I hope that the installer will include a copy of make-cygwin-symlink
# (which will not be required beyond install time) and will go something
# rather like
#   ./make-cygwin-symlink "c:\Program Files\reduce\csl-reduce\reduce.exe" \
#                         redcsl
# which should put a symlink called redcsl in /usr/local/bin of any cygwin
# installation that my code manages to find. After that a cygwin user
# will be able to gu just "redcsl" to pop up a Windows Reduce or
# "redcsl -w" for a console mode one.


# Reduce built in the cslbuild directory
