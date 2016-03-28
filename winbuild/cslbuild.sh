#! /bin/bash

# First verify that I have as much of cygwin installed as I am liable to need

../scripts/cygwin-sanity-check.sh

# Ha ha ha - there are a whole range of configurations where you may launch
# this script. I will mostly test the one that applies to me, but I will
# document the rest here and may try to support more of them:
#
# (1) You are using a 64-bit version of Windows, are launching this
#     from a 32-bit cygwin shell but you also have cygwin64 installed. This
#     is the situation I view as most satisfactory. It will build a
#     cygwin32 Reduce natively and win32 and win64 using i686-w64-mingw32 and
#     x86_64-w64-mingw32. To build a cygwin64 version it will temporarily
#     divert into cygwin64 so that that is performed a a native build there.
#     By doing the temporary diversion into cygwin64 I do not end up trying to
#     rely of cygwin 32-to-64 cross compilation, but I do use a very curious
#     little program to "change gear" from 32 to 64-bit cygwin!
#
# (2) ##You are either using a 32-bit version of Windows or you are launching
#     ##this script from cygwin32 and you do not have cygwin64 installed. The
#     ##cygwin64 binaries will be created using a cross-build via the toolchain
#     ##x86_64-pc-cygwin. This is expected to work but I also generally believe
#     ##that the cross-toolchain will be less well tested and supported than
#     ##the native 64-bit one, and that is why I prefer (1) despite the odd
#     ##nature of the gear-change fronm 32 to 64-bit cygwin worlds.
#### This capability has to be withdrawn because cygwin have withdrawn many
#### of the cygwin64-* libraries from their 32-bit product.
#
# (3) This script is launched from a cygwin64 shell but 32-bit cygwin is
#     also installed. Here the cygwin32 binaries can NOT be built (easily)
#     using i686-pc-cygwin cross compilation because (at the time of writing)
#     cygwin does not provide all the libraries needed (eg Xft and fontconfig).
#     Thus there will be temporary diversion into cygwin32 for building that
#     version. This context switch into 32-bit cygwin is now officially the
#     best that cygwin will support.
#
# In cases the x86_64-pc-windows versions should create 64-bit image files
# and I will use those. In case 2 I will use the image file made for
# i686-pc-windows. Which image file is used ought not to matter too much
# since CSL should be able to reload any image file on any platform, but
# I expect that reloading an image file that uses the same wordlength as
# your system will be marginally faster, so on 64-bit machines I will
# prefer the 64-bit ones.

# Detect if we have been launched from 32 or 64-bit cygwin

cygwin="none"
case `uname -m` in
i686)
  cygwin=32
  ;;
x86_64)
  cygwin=64
  ;;
*)
  echo Unknown architecture `uname -m`
  exit 1;
esac

# Attempt to make the utility programs that can switch me between
# 32 and 64-bit cygwin environments.
# This REQUIRES the two cygwin installations to be in c:\cygwin and
# c:\cygwin64.

./make-cygalt.sh

# Now identify which build case applies.
case $cygwin in
32)
  if test -f /cygdrive/c/cygwin64/bin/cygwin1.dll
  then
    buildcase=1
  else
    buildcase=2
    printf "\n++++ Building on a 32-bit host is no longer supported ++++\n"
    printf "cygwin do not provide cygwin64-* libraries in that world\n"
    exit 1
  fi
  ;;
64)
  if test -f /cygdrive/c/cygwin/bin/cygwin1.dll
  then
    buildcase=3
  else
    echo You are running under cygwin64 but do not seem to have cygwin32 installed.
    echo Please install it and then try again.
    exit 1
  fi
  ;;
esac

# Sometimes I will need the "other" cygwin installed as well. Detect that
# case and check that all will be well...

case buildcase in
1 | 3)
  ./cygalt ../scripts/cygwin-sanity-check.sh
  ;;
esac


# Configure and build CSL version from scratch

# (1) a native-style win32 version. Always done the same way

# I build this one first and it will include re-creation of the C code
# that optimises Reduce. This is done this way because a 32-bit windows
# variant is the version I can be certain should behave regardless of
# the build platform.
#

./cslwin32.sh

# (2) a cygwin32 version. This uses native compilation in cases 1 and 2
#     and temporary version flipping in case 3

case $buildcase in
1 | 2)
  ./cslcyg32.sh
  ;;
3)
  ../cslcyg32x.sh
  ;;
esac

# (3) a native-style win64 version. Always done the same way. If you have a
#     32-bit version of Widnows this will not create reduce.img - it will copy
#     a version of that from somewhere that may not be useful for this
#     build.

./cslwin64.sh

# (4) a cygwin64 version

case $buildcase in
1 | 2)
  ./cslcyg64x.sh
  ;;
3)
  ./cslcyg64.sh
  ;;
esac

# Now all versions should be built. Check sizes.

ls -lh csl*/csl/csl.exe csl*/csl/csl.com csl*/csl/csl.img
ls -lh csl*/csl/reduce.exe csl*/csl/reduce.com csl*/csl/reduce.img

# Now assemble the various executables that I made in the cslwin32, cslwin64,
# cslcyg32 and cslcyg64 directories, together with two small helper programs
# to make "fat" binaries that are expected to run in all cirmumstances. Of
# these reduce.exe will be a console-mode application and it will run in
# either a 32 or 64-bit environment either under native Windows or when
# invoked from an xterm or mintty terminal under cygwin. The other is
# winreduce.exe and that is linked as a Windows application so it is
# suitable for double clicking on. It will run in 32-bit mode on a 32-bit
# machine or escalate to 64-bit on a 64-bit version of Windows. Both of
# these (and in all circumstances) use the same single reduce.img image file.

rm -rf cslbuild
mkdir -p cslbuild

./fatbinary.sh $buildcase

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


