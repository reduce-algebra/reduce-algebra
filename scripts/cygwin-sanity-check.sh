#! /usr/bin/env bash
# Only used from cygwin so I can assume bash is available.

# This little script is intended to check if all the cygwin
# packages that you need in order to build the CSL version of
# Reduce are present. The list of packages here is short
# because many others will automatically be selected by the cygwin
# setup program as prerequisites for these ones. The list here was
# prepared and checked in  October 2014. Changes in cygwin could make
# it obsolete at some stage, but even then it should help to provide
# a starting point. Hah this is now being updated in 2023!
#
# As of 2023 there is now no pretence of supporting 32-bit Windows.
# Using the 64-bit world as the main one was proper back in 2016.
#
# This script detects which cygwin version it is run under and proposes
# packages to install such that when their dependencies are also installed
# things should be OK. The set of packages here will suffice for the
# default versions of Reduce. The "--with-wx" experimental/development
# option would require more. Some users wil also wish to install the
# editor of their choice and other convenience tools, and those who wish
# to re-build the manual will need LaTeX... To prepare for that I will
# check for at least some of those too.

# [Reviewed May 2016, October 2023]

pneed=""
need=""

fordistrib="texlive-collection-latexrecommended \
  texlive-collection-latexextra \
  texlive-collection-fontsrecommended \
  texlive-collection-fontsextra \
  texlive-collection-formatsextra \
  texlive-collection-plaingeneric \
  rsync"

case `uname -m` in
i686)
    printf "32-bit systems no longer supported\n"
    exit
    ;;
x86_64)
    width="x86_64"
    printf "Checking 64-bit cygwin environment...\n"
    for m in automake bc bison ccache \
        gcc-g++ libffi-devel libgtk2.0-devel \
        libncurses-devel libpng-devel libtool libXext-devel libXft-devel \
        make mingw64-x86_64-gcc-g++ \
        mingw64-x86_64-zlib openssh subversion texinfo time wget gcab \
        $fordistrib
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

