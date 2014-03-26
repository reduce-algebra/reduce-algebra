#! /bin/bash

# Remake a "fat binary" reduce.
#
# Arguments
#    clean        build the basic binaries fully from scratch
#    remake       recompile some of the basic binaries
#    cyg32, cyg64, win32, win64
#                 specify which binaries "remake" or "clean" apply to. If
#                 none are specified then remake or clean them all


# This script runs for around 20 minutes on my machine (i7-4770K) if
# given the "clean" option. But that ought to create a nice clean
# fresh set of everything. Using just "remake" will be a lot faster.
# With neither clean nor remake this will merely re-pack existing
# binaries. Well if the binaries appear not to be available it will
# recreate them.

echo Initial sanity checks...

case `uname` in
*WOW64*)
  echo Can build both 32 and 64-bit versions of Reduce
  ;;
*)
  case `uname -m` in
  i686)
    echo Building on a 32-bit only system
    ONLY32="yes"
    ;;
  *)
    echo you are probably using cygwin64. This script will only
    echo work when run using the 32-bit cygwin environment
    exit 1
    ;;
  esac
  ;;
esac

# From time to time cygwin may change the organisation or name of its
# packages. However here is a basic sanity check - the idea is that if
# these packages are installed then these plus their dependencies
# probably mean you have enough to work with.

for m in subversion openssh automake make mingw64-i686-gcc-g++ \
         mingw64-x86_64-gcc-g++ libncurses-devel gcc-g++ \
         cygwin64-gcc-core libXft-devel libX11-devel \
         libXext-devel time
do
  if cygcheck -c -d $m | grep $m > /dev/null
  then
    :
  else
    echo "To build Reduce you may need to install install $m"
  fi
done

if test "x$ONLY32" != "xyes"
then

# Now I do the same sort of thing for the cygwin64 environment. Note the
# curious little helper script cyg64.sh that I use so that I can run
# cygwin64 applications from a cygwin32 shell.

  for m in subversion openssh automake make mingw64-i686-gcc-g++ \
           mingw64-x86_64-gcc-g++ gcc-g++ libXft-devel \
           libX11-devel libXext-devel time
  do
    if ./cyg64.sh cygcheck -c -d $m | grep $m > /dev/null
    then
      :
    else
      echo "To build Reduce you may need to install install $m for cygwin64"
    fi
  done
fi

for x in $*
do
  case $x in
  clean)
    clean="yes"
    ;;
  remake)
    remake="yes"
    ;;
  cyg32)
    cyg32="yes"
    ;;
  cyg64)
    cyg64="yes"
    ;;
  win32)
    win32="yes"
    ;;
  win64)
    win64="yes"
    ;;
  help | --help)
    echo "Usage: ./makereduce.sh [clean/remake/] [cyg32/cyg64/win32/win64]"
    echo "  Makes some of reduce.exe, reduce32.exe, winreduce.exe, winreduce32.exe"
    echo "  where 'win' signals a version that will only support windowed mode"
    echo "  while without 'win' either windowed or console mode under either"
    echo "  native windows or cygwin is possible. '32' marks versions that will"
    echo "  only run in 32-bit mode: otherwise the code will automatically use"
    echo "  64 or 32-bit mode. All variants use the same file reduce.img and"
    echo "  the same directory reduce.fonts."
    exit 0
    ;;
  *)
    echo Unknown argument $x
    ;;
  esac
done

if test "x$cyg32$cyg64$win32$win64" = "x"
then
  cyg32="yes"
  cyg64="yes"
  win32="yes"
  win64="yes"
fi

# If any version has not already been built I will force the issue

if ! test -f cyg32/csl/reduce.img
then
  clean="yes"
  cyg32="yes"
fi

if test "x$ONLY32" != "xyes"
then
  if ! test -f cyg64/csl/reduce.img
  then
    clean="yes"
    cyg64="yes"
  fi
fi

if ! test -f win32/csl/reduce.img
then
  clean="yes"
  win32="yes"
fi

if test "x$ONLY32" != "xyes"
then
  if ! test -f win64/csl/reduce.img
  then
    clean="yes"
    win64="yes"
  fi
fi

here=`cygpath -a .`
here=${here%/}
echo here = $here

if test "x$clean$remake" != "x"
then
  if test "x$clean" != "xyes"
  then
    clean="no"
  fi

  if test "x$cyg32" = "xyes"
  then
    echo Remake cygwin32 version: see cyg32.log
    script cyg32.log -c "./makebin.sh $clean cyg32 i686-pc-cygwin --with-cygwin"
  fi

  if test "x$cyg64" = "xyes" && test "x$ONLY32" != "xyes"
  then
    echo Remake cygwin64 version: see cyg64.log
    script cyg64.log -c "./cyg64.sh ./makebin.sh $clean cyg64 x86_64-pc-cygwin \
      --with-cygwin"
  fi

  if test "x$win32" = "xyes"
  then
    echo Remake win32 version: see win32.log
    script win32.log -c "./makebin.sh $clean win32 i686-w64-mingw32 \
      --with-cygbuild=$here/cyg32 --with-cygbuild64=$here/cyg64"
  fi

  if test "x$win64" = "xyes" && test "x$ONLY32" != "xyes"
  then
    echo Remake win64 version: see win64.log
    script win64.log -c "./makebin.sh $clean win64 x86_64-w64-mingw32 \
      --with-cygbuild=$here/cyg32 --with-cygbuild64=$here/cyg64"
  fi

fi

echo All binaries should now be as up to date as needed
echo Reduce raw binaries...
ls -l */csl/reduce.exe

# Now I can just use my local Makefile to finish the job. I clear away my
# local copies of the fonts and image so I can be confident that they
# get re-copied.

rm -rf reduce.img reduce.fonts

echo remake and pack

if test "x$ONLY32" = "xyes"
then
  male all32
else
  make all64
fi

echo Final results...
ls -lhd reduce32.exe reduce.exe winreduce.exe \
        winreduce32.exe reduce.img reduce.fonts

exit 0
