#! /bin/bash

# This tries to configure, compile and then run a teeny windowed
# program. If this FAILS then it is probable that any attempt to compile
# the full CSL version of Reduce will also give trouble.


# I want this script to be one I can launch from anywhere, but at least
# some of its sub-scripts will not be so generous. So find out where it
# lives so that other locations can be found relative to that.

a=$0
c=unknown
case $a in
/* )
  c=$a  
  ;;
*/* )
  case $a in
  ./* )
    a=${a#./}
    ;;
  esac
  c=`pwd`/$a
  ;;
* ) 
  for d in $PATH
  do
    if test -x $d/$a
    then
      c=$d/$a
    fi
  done
  if test $c = "unknown" ;then
    echo "Unable to find full path for script. Please re-try"
    echo "launching it using a fully rooted path."
    exit 1
  fi
  ;;
esac

here=${c%/*}

# Now I try to check that libtoolize is available and that its version
# is at least 2.2.4. This is done by rejecting versions that seem to have
# lower version numbers.

libtoolok="no"
if which libtoolize >/dev/null 2>&1 
then
  ltv=`libtoolize --version | head -1`
  case ${ltv##* } in
  0.* | 1.* | 2.0.* | 2.1.* | 2.2.1 | 2.2.2 | 2.2.3)
    libtoolok="no"
    ;;
  *)
    libtoolok="yes"
    ;;
  esac 
fi

if test "libtoolok" = "yes" && autoconf -o /dev/null $here/configver.ac >/dev/null 2>&1
then
  echo "autoconf and libtool seem OK"
else
  echo "Your version of automake of libtool is older than I like."
  echo "I can try to build but you might like to consider upgrading"
  echo "At present I like autoconf 2.61 and libtool 2.2.4 or newer"
# Here I will explicitly touch files that otherwise could cause use of
# autoconf, automake or libtool so that the versions checked out from
# subversion are used.
  touch $here/../csl/aclocal.m4
  sleep 1
  touch $here/../csl/Makefile.in
  touch $here/../csl/config.h.in
  touch $here/../csl/configure
fi


here=${here%/*}

if ! test -d $here/cslbuild
then
  mkdir -p $here/cslbuild
fi

cd $here/cslbuild
../csl/configure && make clean && make && exec ./testprogram

