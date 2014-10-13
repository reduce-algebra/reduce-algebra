#! /bin/bash -v

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
#
# (2) You are either using a 32-bit version of Windows or you are launching
#     this script from cygwin32 and you do not have cygwin64 installed. The
#     cygwin64 binaries will be created using a cross-build via the toolchain
#     x86_64-pc-cygwin. This is expected to work but I also generally believe
#     that the cross-toolchain will be less well tested and supported than
#     the native 64-bit one, and that is why I prefer (1) despite the odd
#     nature of the gear-change fronm 32 to 64-bit cygwin worlds.
#
# (3) This script is launched from a cygwin64 shell but 32-bit cygwin is
#     also installed. Here the cygwin32 binaries can NOT be built (easily)
#     using i686-pc-cygwin cross compilation because (at the time of writing)
#     cygwin does not provide all the libraries needed (eg Xft and fontconfig).
#     Thus there will be temporary diversion into cygwin32 for building that
#     version.
#
# In cases the x86_64-pc-windows versions should create 64-bit image files
# and I will use those. In case 2 I will use the image file made for
# i686-pc-windows. Which image file is used ought not to matter too much
# since CSL should be able to reload any image file on any platform, but
# I expect that reloading an image file that uses the same wordlength as
# your system will be marginally faster, so on 64-bit machines I will
# prefer the 64-bit ones.


# If you just checked out a copy of Reduce it seems best to reset a load
# of time-stamps hers since subversion may have left them in a mess. Doing
# this is expected to avoid any use of autoreconf during the builds.

pushd ..
scripts/stamp.sh
popd

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
# 32 and 64-bit cygwin environments. This involves a search for a
# directory containing both cygwin1.dll and bash.exe and any such
# directory that is found is expected to be part of a proper cygwin
# installation. This is at least sort of reasonable in that cygwin
# issue guidelines to the effect that having multiple copies of cygwin1.dll
# can cause confusion, so in a well set up configuration I can count on
# that being a signature of the cygwin installation directory.
#
# The script here creates executable cyg32.exe and cyg64.exe if it can,
# so the presence of these signals its success. For instance in case (2)
# it ought not to create a cyg64.exe but in case (3) it will need to
# create a cyg32.exe if I am to survive.

./make-cyg64.sh

# Now identify which build case applies.

case $cygwin in
32)
  if test -x ./cyg64.exe
  then
    buildcase=1
  else
    buildcase=2
  fi
  ;;
64)
  if test -x ./cyg32.exe
  then
    buildcase=3
  else
    echo You are running undet cygwin64 but do not seem to have cygwin32 installed.
    echo Please install it and then try again.
    exit 1
  fi
  ;;
esac

# Configure and build CSL version from scratch

# (1) a cygwin32 version. This uses native compilation in cases a and 2
#     and temporary version flipping in case 3

case $buildcase in
1 | 2)
  ./cslcyg32.sh
  ;;
3)
  ../cslcyg32x.sh
  ;;
esac

# (2) a native-style win32 version. Always done the same way

./cslwin32.sh

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

# Now all versions should be built. Check sizes again

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

./fatbinary.sh $buildcase

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
# will be able to gu just "redcsl" to pop up a Windows Reduce or
# "redcsl -w" for a console mode one.


# end of build script

