#! /usr/bin/env bash

# I want this script to be one I can launch from anywhere, but at least
# some of its sub-scripts will not be so generous. So find out where it
# lives so that other locations can be found relative to that.
curr=`pwd`
here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`dirname "$here"`
here=`cd "$here"; pwd -P`
here=`dirname "$here"`


printf "MFLAGS=<%s> MKFLAGS=<%s> MAKECMDGOALS=<%s> args=<%s> here=<%s>\n" \
       "$MFLAGS"    "$MKFLAGS"   "$MAKECMDGOALS"   "$*"  "$here"

args=""
flags=""
installflag=""
installcsl="no"
installpsl="no"
parallel="no"
PSLMFLAGS=""

for a in $*
do
  if test "$a" = "install"
  then installflag="yes"
  elif test "$a" = "csl"
  then installcsl="yes"
  elif test "$a" = "psl"
  then installpsl="yes"
  else args="$args $a"
  fi  
done

# if neither csl or psl are given, uninstall both
if test "$installcsl" = "no" -a "$installpsl" = "no"
then
  installcsl=yes
  installpsl=yes
fi

host=`./config.guess`
host=`scripts/findhost.sh $host`
os=`scripts/findos.sh`

case `uname -s` in
*CYGWIN*)
  case `uname -m -o` in
  *i686*Cygwin*)
    cyg32="yes"
    ;;
  *x86_64*Cygwin*)
    cyg64="yes"
    ;;
  esac
  ;;
esac

printf "Current machine tag is %s\n" "$host"

# I REALLY want to use GNU make, so here is some stuff to try to
# find a version. The "/usr/sfw" location is used on Solaris, while
# "/usr/local" is a plausible place to look in case a user has built and
# installed it for themselves. Some BSD variants will build imported
# packages in /pkg/bin so I look there too...

if test "x$MAKE" = "x"
then
  if test -x /usr/sfw/bin/gmake
  then MAKE=/usr/sfw/bin/gmake
  elif test -x /usr/pkg/bin/gmake
  then MAKE=/usr/pkg/bin/gmake
  elif test -x /usr/local/bin/gmake
  then MAKE=/usr/local/bin/gmake
  elif test -x /usr/bin/gmake
  then MAKE=/usr/bin/gmake
  else MAKE=make
  fi
  export MAKE
fi

printf "installcsl=$installcsl installpsl=$installpsl\n"

if test "$installcsl" = "yes"
then
  cslversions=""
  if test -f $here/cslbuild/$host/csl/Makefile
  then
    cslversions="$here/cslbuild/$host"
  else
    for x in "$here/cslbuild"
    do
      if test -f $x/csl/Makefile
      then
        cslversions="$x"
        break
      fi
    done
  fi

  if test "x$cslversions" = "x"
  then
    printf "No version for CSL configured?\n"
    exit 1
  else
    cd $cslversions/csl
    $MAKE uninstall
    cd $curr
  fi
fi

if test "$installpsl" = "yes"
then
  pslversions=""
  if test -f $here/pslbuild/$host/Makefile
  then
    pslversions="$here/pslbuild/$host"
  else
    for x in "$here/pslbuild"
    do
      if test -f $x/Makefile
      then
        pslversions="$x"
        break
      fi
    done
  fi
  if test "x$pslversions" = "x"
  then
    printf "No version for PSL configured?\n"
    exit 1
  else
    cd $pslversions
    $MAKE uninstall
    cd $curr
  fi
fi

# end of uninstall script...
