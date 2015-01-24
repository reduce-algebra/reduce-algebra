#! /bin/sh

# This tries to configure, compile and then run a teeny windowed
# program. If this FAILS then it is probable that any attempt to compile
# the full CSL version of Reduce will also give trouble.


# I want this script to be one I can launch from anywhere, but at least
# some of its sub-scripts will not be so generous. So find out where it
# lives so that other locations can be found relative to that.

here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
cd `dirname "$here"`

if autoconf -o /dev/null >/dev/null 2>&1
then
  echo "autoconf and automake seems OK"
else
  echo "Either you do not have autoconf & automake installed"
  echo "or your version of autoconf/automake is older than I like."
  echo " "
  echo "I can try to build but you might like to consider upgrading"
  echo " "
  echo "At present I like autoconf 2.61 or newer"
# Here I will explicitly touch files that otherwise could cause use of
# autoconf or automake so that the versions checked out from
# subversion are used.
  touch $here/../csl/aclocal.m4
  sleep 1
  touch $here/../csl/Makefile.in
  touch $here/../csl/config.h.in
  touch $here/../csl/configure
fi

here=`dirname "$here"`

if test -d $here/cslbuild
then :
else
  mkdir -p $here/cslbuild
fi

cd $here/cslbuild
../csl/configure && make clean && make && exec ./testprogram

