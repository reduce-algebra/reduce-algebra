#! /bin/bash
# Only used from cygwin so I can assume bash is available.

# This little script is intended to check if all the cygwin
# packages that you need in order to build the CSL version of
# Reduce are present. The list of packages here is short
# because many others will automatically be selected by the cygwin
# setup program as prerequisites for these ones. The list here was
# prepared and checked in  October 2014. Changes in cygwin could make
# it obsolete at some stage, but even then it should help to provide
# a starting point.
#
# In January 2015 I believe that if I run under cygwin32 I can build
# binaries for i686-pc-cygwin, i686-pc-windows, XXXx86_64-pc-cygwinXXX
# and x86_64-pc-windows. If I am running on top of a 64-bit version of
# Windows I can create the Reduce image files using any of these apart
# from x86_64-pc-cygwin. If I am running on a 32-bit release of Windows
# then (obviously) I can only create 32-bit image files - however those
# should be directly usable with the 64-bit binaries.
#
# If I am under cygwin64 then I can build for i686-pc-windows,
# x86_64-pc-cygwin and x86_64-pc-windows, but cygwin64 does not (at the
# date mentioned) provide libXft-dev or fontconfig-dev packages in a
# form that supports cross compilation to cygwin32. The effect of that is
# that I can not build the i686-pc-cygwin version there. It would potentially
# be possible to build and install private versions of those libraries, but
# that feels excessive. It is probably better to work on the basis that
# cross compilation between the 32- and 64-bit cygwin environments is
# sufficiently infrequently done in the general cygwin community that it
# is not likely to be a high support priority there... so even when it
# is possible to cross-build it will be safer to install both the 32- and
# 64-bit systems and use each for building its own version of Reduce.
#
# March 2016: cygwin are withdrawing cygwin64-* libraries etc as things that
# users can exploit to cross-build 64-bit cygwin applicatiosn on aq 32-bit
# playform.
#
# This script detects which cygwin version it is run under and proposes
# packages to install such that when their dependencies are also installed
# things should be OK. The set of packages here will suffice for the
# default versions of Reduce. The "--with-wx" experimental/development
# option would require more. Some users wil also wish to install the
# editor of their choice and other convenience tools, and those who wish
# to re-build the manual will need LaTeX... To prepare for that I will
# check for at least some of those too. Note that at the time of checking
# libgtk2.0 is not provided in versions for cross building between 32 and
# 64-bit versions of cygwin.

# [Reviewed March 2016]

pneed=""
need=""

case `uname -m` in
i686)
    width="x86"
    for m in automake bc bison cygwin64-gcc-g++ \
        gcc-g++ libgtk2.0-devel libncurses-devel \
        libpng-devel libtool libXext-devel libXft-devel make \
        mingw64-i686-gcc-g++ mingw64-i686-zlib mingw64-x86_64-gcc-g++ \
        mingw64-x86_64-zlib openssh subversion time wget
    do
      if cygcheck -c -d $m | grep $m > /dev/null
      then
        echo "Good: $m is installed"
      else
        echo "To build Reduce you should install $m"
        if test "x$need" = "x"
        then
          need="$m"
        elif test ${#need} -gt 50
        then
          pneed="$pneed$need,\\\\\\n"
          need="$m"
        else
          need="$need,$m"
        fi
      fi
    done
    ;;
x86_64)
    width="x86_64"
    for m in automake bc bison cygwin32-gcc-g++ \
        gcc-g++ libgtk2.0-devel \
        libncurses-devel libpng-devel libtool libXext-devel libXft-devel \
        make mingw64-i686-gcc-g++ mingw64-i686-zlib mingw64-x86_64-gcc-g++ \
        mingw64-x86_64-zlib openssh subversion time wget
    do
      if cygcheck -c -d $m | grep $m > /dev/null
      then
        echo "Good: $m is installed"
      else
        echo "To build Reduce you should install $m"
        if test "x$need" = "x"
        then
          need="$m"
        elif test ${#need} -gt 50
        then
          pneed="$pneed$need,\\\\\\n"
          need="$m"
        else
          need="$need,$m"
        fi
      fi
    done
    ;;
*)
    echo Architecture `uname -m` not recognised
    ;;
esac

if test "x$need" != "x"
then
  printf "\nPerhaps try the following command:\n"
  printf "wget -N http://cygwin.com/setup-$width.exe\n"
  printf "./setup-$width.exe --no-desktop --no-shortcuts \\\\\\n"
  printf "  --no-startmenu --quiet-mode \\\\\\n"
  printf "  -P \"$pneed$need\"\n"
  printf "To do this you will need the cygwin version of wget installed\n"
fi

