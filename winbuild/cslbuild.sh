#! /bin/bash -v

# If you just checked out a copy of Reduce it seems best to reset a load
# of time-stamps hers since subversion may have left them in a mess. Doing
# this is expected to avoid any use of autoreconf during the builds.

../scripts/stamp.sh

# Configure and build CSL version from scratch

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

# I want a program that can establish cygwin symlinks but that is a regular
# Windows program This is for calling from an installer

./set-up-symlinks.sh

# The files that I list here are the ones that are the "results" from
# this script.

ls -lhd reduce.exe winreduce.exe reduce.img reduce.fonts \
	reduce.resources make-cygwin-symlink.exe

# I hope that the installer will include a copy of make-cygwin-symlink
# (which will not be required beyond install time) and will go something
# rather like
#   ./make-cygwin-symlink "c:\Program Files\reduce\csl-reduce\reduce.exe" \
#                         redcsl
# which should put a symlink called redcsl in /usr/local/bin of any cygwin
# installation that my code manages to find. After that a cygwin user
# will be able to gu just "redcsl" to pop up a windows Reduce or
# "redcsl -w" for a console mode one.


# end of build script




