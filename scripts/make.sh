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

printf "MFLAGS=<%s> MKFLAGS=<%s> MAKECMDGOALS=<%s> args=<%s>\n" \
       "$MFLAGS"    "$MKFLAGS"   "$MAKECMDGOALS"   "$*"

args=""
flags=""
buildcsl="no"
buildpsl="no"
sequential="no"

# "make sequential" or "make csl sequential" does a sequential rather
# then a parallel build.

for a in $*
do
  if test "$a" = "csl"
  then buildcsl="yes"
  elif test "$a" = "psl"
  then buildpsl="yes"
  elif test "$a" = "sequential"
  then sequential="yes"
  else args="$args $a"
  fi  
done

# if neither csl or psl are given, build both
if test "$buildcsl" = "no" -a "$buildpsl" = "no"
then
  buildcsl="yes"
  buildpsl="yes"
fi

if ! test -d cslbuild
then
  buildcsl="no"
fi
if ! test -d pslbuild
then
  buildpsl="no"
fi
if test "$buildpsl$buildcsl" = "nono"
then
  printf "Neither CSL nor PSL seems configured and selected here.\n"
  printf "Nothing to do. Stopping.\n"
  exit 1
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
  case "$os" in
  *cygwin* | *windows*)
    list="cslbuild/*-cygwin* cslbuild/*-windows*"
    ;;
  *)
    list="cslbuild/*${host}*"
    ;;
  esac
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
  case "$os" in
  *cygwin* | *windows*)
    list="$list pslbuild/*-cygwin* pslbuild/*-windows*"
    ;;
  *)
    list="$list pslbuild/*${host}*"
    ;;
  esac
fi

# I will - now - always try building all possible versions in parallel,
# except that I will ensure that I re-create the generated C++ stuff first
# if that needs doing.
case $args in
# If I am making bootstrapreduce or bootstrapreduce.img or csl or csl.img or
# one of the demo programs I do not need the generated C code...
*bootstrap* | *csl* | *demo* | *psl*)
  firstcsl=""
  ;;
esac

for l in $list
do
  if test -f ${l}/Makefile
  then
    h=`pwd`
    cd ${l}
    if test "x$firstcsl" != "x"
    then
      $MAKE c-code
      firstcsl=""
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
