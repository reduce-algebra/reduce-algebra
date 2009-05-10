#! /bin/sh

# This is used to re-run autoconf, automake etc and then restart
# a call to "configure"

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

saved=`pwd`
cd $here

# Oh dear! On some (but not all) Macintosh installations there will be
# a program called libtool present that is nothing to do with GNU libtool.
# In some (but probably not all!) such cases the GNU version of libtool
# may be present with a "g" in front of its name, ie "glibtoolize" may
# exist. I try to test for these messy cases here and refuse to try to
# regenerate stuff unless I think I can see at least some variant on
# GNU libtool(ize) available.

ltv="none"
( ltv=`libtoolize -- version` ) 1>/dev/null 2>%1
gltv="none"
( gltv=`glibtoolize -- version` ) 1>/dev/null 2>%1
ltavail="no"
case $ltv in
*GNU libtool*)
  ltavail="yes"
  ;;
*)
  case $gltv in
  *GNU libtool*)
    ltavail="yes"
    ;;
  esac
  ;;
esac

if test "$ltavail" = "yes" && autoconf -o /dev/null >/dev/null 2>&1
then
# If looks as if we have autoconf installed and it is at least version
# 2.61, which is what I seem to need at the moment.
# The configure.ac file here arranges to check the automake
# version too. But it seems hard to make it check the libtool version -
# the most I can do there (easily) is to verify that libtool is available. 
  if ! $here/../autogen.sh
  then
    echo "The autoconf/automake/libtoolize process seems to have failed"
    echo "Please check you have up to date versions of all those installed"
    exit 1
  fi
else
# Here I do NOT have an up to date version of autoconf available. So as
# a fall-back and with some trepidation I will merely re-set date-stamps
# on the files that are involved.
  echo "About to touch aclocal.m4"
  find $here/.. -name aclocal.m4 -print | xargs touch
  sleep 1
  echo "About to touch Makefile.in, config.h.in and configure"
  find $here/.. \( -name Makefile.in -o -name config.h.in -o -name configure \) -print | xargs touch
  echo "datestamps should now be in the right order"
  echo " "
fi

cd $saved

exec $here/../configure $*
