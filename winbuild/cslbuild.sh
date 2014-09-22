#! /bin/bash -v

# Configure and build CSL version from scratch

reduce=`pwd`/..

# (1) a cygwin32 version

./cslcyg32.sh

# (2) a native-style win32 version

./cslwin32.sh

# (3) a native-style win64 version

./cslwin64.sh


# (4) a cygwin64 version

./cslcyg64.sh

# Now all versions should be built. Check sizes again

ls -lh csl*/csl/csl.exe csl*/csl/csl.com csl*/csl/csl.img
ls -lh csl*/csl/reduce.exe csl*/csl/reduce.com csl*/csl/reduce.img

# Assemble some of the built files & directories  I will want, putting them
# in the current directory where I can see them.

cp cslwin64/csl/reduce.img reduce.img
cp -r cslwin64/csl/reduce.fonts reduce.fonts
cp -r cslwin64/csl/reduce.resources reduce.resources

# Now assemble the various executables that I made in the cslwin32, cslwin64,
# cslcyg32 and cslcyg64 directories, together with two small helper programs
# to make "fat" binaries that are expected to run in all cirmumstances. Of
# these reduce.exe will be a console-mode application and it will run in
# either a 32 or 64-bit environment either under native windows or when
# invoked from an xterm or mintty terminal under cygwin. The other is
# winreduce.exe and that is linked as a windows application so it is
# suitable for double clicking on. It will run in 32-bit mode ona 32-bit
# machine or escalate to 64-bit on a 64-bit version of Windows. Both of
# these (and in all circumstances) use the same single reduce.img image file.

./fatbinary.sh

# The files that I list here are the ones that are the "results" from
# this script.

ls -lhd reduce.exe winreduce.exe reduce.img reduce.fonts reduce.resources


# end of build script




