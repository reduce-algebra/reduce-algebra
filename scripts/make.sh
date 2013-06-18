#! /bin/sh 

# This is what "make" invokes. It gets passed as arguments
#      make-flags
#      @@@
#      make-targets
# and I HOPE that "@@@" as a literal will never clash with a make FLAG.
# Well it should not since the flags should all start with "-"?

# The purpose of this script is to re-invoke "make" in any and all
# sub-directories suitable for the architecture of the current machine.
# This means it will not be very good if you try to set up
# cross-compilation! In that case you must select the relevant directory
# to run the cross build for yourself.

# Note that this tries to identify all potentially relevent build
# directories that contain a "Makefile", that being used as a signature
# that they have been configured. It allows for suffixes "-m32" "-m64"
# and "-debug" as in scripts/findhost.sh.

# It also tries to build both CSL and PSL setups when they have been
# configured. No doubt the bit of script relating to PSL will need
# adjusting sometime.

args=""
flags=""
doingflags="yes"
buildcsl="no"
buildpsl="no"

for a in $*
do
  if test "x$a" = "x@@@"
  then doingflags="no"
  elif test $doingflags = "yes"
  then flags="$flags $a"
  elif test "$a" = "csl"
  then buildcsl="yes"
  elif test "$a" = "psl"
  then buildpsl="yes"
  else args="$args $a"
  fi  
done

# if neither csl or psl are given, build both
if test "$buildcsl" = "no" -a "$buildpsl" = "no"
then
  buildcsl=yes
  buildpsl=yes
fi

# config.guess fails on Solaris if SHELL is /bin/bash.
if test -x /bin/sh
then
  SHELL=/bin/sh
  export SHELL
fi

host=`./config.guess`
host=`scripts/findhost.sh $host`
os=`scripts/findos.sh`

case `uname -m -o` in
*i686*Cygwin*)
  cyg32="yes"
  ;;
*x86_64*Cygwin*)
  cyg64="yes"
  ;;
esac

echo Current machine tag is $host

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

# I expect directories with two "-" characters in their names in the
# cslbuild or pslbuild directories to be named as host triples. But
# even then I will only try to build in them if there is a "Makefile"
# present.

echo host=${host} os=${os}

rc=0

list=""
if test "$buildcsl" = "yes"
then
# If I am running in a 64-bit cygwin shell then I will only even try to
# build 64-bit cygwin versions. At some later stage when the 64-bit
# cygwin environment is fully stable I should be able to build any of the
# windows variants there, but at the time of writing things are not yet
# ready for that.
  if test "x$cyg64" = "xyes"
  then
    list="cslbuild/x86_64-pc-cygwin*"
  elif test "x$cyg32" = "xyes"
  then
# If I am in a 32-bit cygwin shell I can make not just the 32-bit cygwin
# version but also both 32 and 64-bit (native, mingw) Windows variants.
    list="cslbuild/i686-pc-cygwin* cslbuild/*-windows*"
  else
# If I am not running on windows my default behaviour will be to build
# just versions that use the operating system I am running on. Anybody
# who does cross compilation will needs to use "make" directly in the
# subdirectory of cslbuild relevent to them.
    list="cslbuild/*-${os}*"
  fi
fi

if test "$buildpsl" = "yes"
then
  if test "x$os" = "xwindows"
  then
    list="$list pslbuild/*-${os}*"
  else
    list="$list pslbuild/*${host}*"
  fi
fi

for l in $list
do
   if test -f ${l}/Makefile
   then
     echo About to build in ${l}
     cd ${l}
     echo $MAKE $flags $args MYFLAGS="$flags" --no-print-directory
     $MAKE $flags $args MYFLAGS="$flags" --no-print-directory
     test $? -gt $rc && rc=$?
     cd ../..
   fi
done

exit $rc
