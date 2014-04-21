#! /bin/bash

# This little script is intended to check if all the cygwin
# packages that you need in order to build the CSL version of
# Reduce are present. The list of packages here is short
# because many others will automatically be selected by the cygwin
# setup program as prerequisites for these ones. The list here was
# prepared and checked in January 2013. Changes in cygwin could make
# it obsolete at some stage, but even then it should help to provide
# a starting point.
#

for m in subversion openssh automake make mingw64-i686-gcc-g++ \
         mingw64-x86_64-gcc-g++ libncurses-devel gcc-g++ \
         libXft-devel libX11-devel libXext-devel time
do
  if cygcheck -c -d $m | grep $m > /dev/null
  then
    echo "Good: $m is installed"
  else
    echo "To build Reduce you should install $m"
  fi
done

