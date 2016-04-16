#! /bin/sh

# This tries to configure, compile and then run a teeny windowed
# program. If this FAILS then it is probable that any attempt to compile
# the full CSL version of Reduce will also give trouble.


# I want this script to be one I can launch from anywhere, but at least
# some of its sub-scripts will not be so generous. So find out where it
# lives so that other locations can be found relative to that.

here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`cd \`dirname "$here"\` ; pwd -P`

autoreconf -f -i -v
if autoconf -o /dev/null >/dev/null 2>&1
then
  echo "autoconf and automake seems OK"
else
  echo "Either you do not have autoconf & automake installed"
  echo "or your version of autoconf/automake is older than I like."
  echo " "
  echo "please install autoconf version at least 2.61 and automake"
  echo "at least 1.13, and a respectably recent libtool, then try again"
  exit 1
fi

if ! which libtool > /dev/null
then
  echo "You need libtool installed, please"
  echo "(note that on some Linux systems the package is called libtool-bin)"
  exit 1
fi

here=`dirname "$here"`

cd $here/csl
autoreconf -f -i -v

if test -d $here/cslbuild
then :
else
  mkdir -p $here/cslbuild
fi

cd $here/cslbuild
../csl/configure && make clean && make && exec ./testprogram

