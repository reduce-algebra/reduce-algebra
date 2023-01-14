#! /bin/bash

# This is what "make" invokes. It gets passed as arguments
#      make-targets

# The purpose of this script is to re-invoke "make" in any and all
# sub-directories suitable for the architecture of the current machine.
# This means it will not be very good if you try to set up
# cross-compilation! In that case you must select the relevant directory
# to run the cross build for yourself.

# Note that this tries to identify all potentially relevent build
# directories that contain a "Makefile", that being used as a signature
# that they have been configured. It allows for suffixes such as
# "-debug" as in scripts/findhost.sh.

# It also tries to build both CSL and PSL setups when they have been
# configured.

# To help with a migration to a new scheme here I will arrange that
# if the user has gone "export NEW=NEW" then Makefile.new will be activated

if test "$NEW" = "NEW"
then
  printf "+++ Using Makefile.new +++\n"
  make -f Makefile.new $*
  exit $!
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

# config.guess fails on Solaris if SHELL is /usr/bin/env bash.
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

if test "$MAKE" = ""
then
  if test -x /usr/sfw/bin/gmake
  then MAKE=/usr/sfw/bin/gmake
  elif test -x /usr/pkg/bin/gmake
  then MAKE=/usr/pkg/bin/gmake
  elif test -x /opt/local/bin/gmake
  then MAKE=/opt/local/bin/gmake
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

list=""
if test "$buildcsl" = "yes"
then
  case "$os" in
  *cygwin* | *windows*)
    list="cslbuild/*-cygwin*/csl cslbuild/*-windows*/csl"
    ;;
  mac_*)
    host1=${host/aarch64/universal}
    host1=${host1/x86_64/universal}
    list="cslbuild/*${host}*/csl cslbuild/*${host1}*/csl"
    ;;
  *)
    list="cslbuild/*${host}*/csl"
    ;;
  esac
fi

firstcsl=${list%% *}
if ! test -f "$firstcsl/Makefile"
then
  firstcsl=""
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

case $args in
# If I am making bootstrapreduce or bootstrapreduce.img or csl or csl.img or
# one of the demo programs I do not need the generated C code...
*bootstrap* | *csl* | *demo* | *psl*)
  firstcsl=""
  ;;
esac

printf "Will build for\n";
for dd in $list
do
  printf "  $dd\n"
done

if test "$firstcsl" != ""
then
  $MAKE -C "$firstcsl" c-code MYFLAGS="$flags"
  rc=$?
else
  rc=0
fi

for dd in $list
do
  if test -f $dd/Makefile
  then
    printf "++ Build in directory $dd\n"
    $MAKE -C $dd $flags $args MYFLAGS="$flags"
    rc1=$?
    rc=$(($rc1 > $rc ? $rc1 : $rc)) 
  fi
done

if test "$rc" = "0"
then
  printf "\nReduce build tasks finished.\n"
else
  printf "\nReduce build tasks finished: Highest return code $rc\n"
fi

exit $rc
