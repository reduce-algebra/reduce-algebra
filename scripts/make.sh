#! /bin/sh

# This is what "make" invokes. It gets passed as arguments
#      make-targets

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
# configured.

# The "--sequential" flag, if given, must be the very first argument to
# this script. It causes all the build steps to get performed one at a time.
# This can be useful while debugging, because it keeps the output from
# each stage separate... With the normal parallel build the output from
# building each variant gets interleaved.

if test "x$1" = "x--sequential"
then
  sequential="yes"
  shift
else
  sequential="no"
fi

printf "MFLAGS=<%s> MKFLAGS=<%s> MAKECMDGOALS=<%s> args=<%s>\n" \
       "$MFLAGS"    "$MKFLAGS"   "$MAKECMDGOALS"   "$*"

args=""
flags=""
buildcsl="no"
buildpsl="no"

for a in $*
do
  if test "$a" = "csl"
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

# The following arranges that if you go "make csl.exe" or
# "make bootstrapreduce.img" (etc) that the system does not try (in vain)
# to build a PSL version.

case $args in
*csl* | *bootstrap* | *reduce.img* | *c-code* | *.com | *.exe)
  buildpsl="no"
  ;;
esac

# config.guess fails on Solaris if SHELL is /bin/bash.
if test -x /bin/sh
then
  SHELL=/bin/sh
  export SHELL
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

# I expect directories with two "-" characters in their names in the
# cslbuild or pslbuild directories to be named as host triples. But
# even then I will only try to build in them if there is a "Makefile"
# present.

procids=""

rc=0

list=""
if test "$buildcsl" = "yes"
then
# If I am in a 64-bit cygwin shell I can make not just the 64-bit cygwin
# version but also both 32 and 64-bit (native, mingw) Windows variants.
# The last time I checked the 64-bit cygwin world did not have quite enough
# libraries available for installation to make it possible for me to
# cross-build a set of 32-bit cygwin executables here. Every so often I
# should check and update re that.
#
# NOTE that these directories MUST ONLY have "make" run in them when running
# using the version of cygwin used to configure them, so mixing use of
# 32 and 64-bit cygwin is delicate!
    list="cslbuild/i686-pc-cygwin* cslbuild/*-windows*"
  if test "x$cyg64" = "xyes"
  then
    list="cslbuild/x86_64-pc-cygwin* cslbuild/*-windows*"
  elif test "x$cyg32" = "xyes"
  then
    list="cslbuild/i686-pc-cygwin* cslbuild/x86_64-pc-cygwin* cslbuild/*-windows*"
  else
# If I am not running on windows my default behaviour will be to build
# just versions that use the operating system I am running on. Anybody
# who does cross compilation will needs to use "make" directly in the
# subdirectory of cslbuild relevent to them.
    list="cslbuild/*-${os}*"
  fi
fi

firstcsl=""
if test "x$list" != "x"
then
  for x in $list
  do
    if test "x$firstcsl" = "x" && test -f "$x/csl/Makefile"
    then
      firstcsl="$x"
    fi
  done
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

# I will - now - always try building all possible versions in parallel,
# except that I will ensure that I re-create the generated C++ stuff first
# if that needs doing.
case $args in
# If I am making bootstrapreduce or bootstrapreduce.img or csl or csl.img or
# one of the demo programs I do not need the generated C code...
*bootstrap* | *csl* | *demo*)
  first="no"
  ;;
*)
  first="yes"
  ;;
esac
for l in $list
do
  if test -f ${l}/Makefile
  then
    h=`pwd`
    cd ${l}
    if test "$first" = "yes"
    then
      $MAKE c-code
      first="no"
    fi
    if test "$sequential" = "yes"
    then
      $MAKE $flags $args MYFLAGS="$flags" --no-print-directory
    else
      $MAKE $flags $args MYFLAGS="$flags" --no-print-directory &
      procids="$procids $!"
    fi
    cd "$h"
  fi
done

wait $procids
printf "\nReduce has now been remade\n"

exit $rc
