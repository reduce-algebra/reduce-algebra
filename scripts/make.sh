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
# configured. No doubt the bit of script relating to PSL will need
# adjusting sometime.

printf "MFLAGS=<%s> MKFLAGS=<%s> MAKECMDGOALS=<%s> args=<%s>\n" \
       "$MFLAGS"    "$MKFLAGS"   "$MAKECMDGOALS"   "$*"

args=""
flags=""
buildcsl="no"
buildpsl="no"
parallel="no"
PSLMFLAGS=""

for a in $MFLAGS
do
  case $a in
  -j | --jobserver-fds=*)
    parallel="yes"
    ;;
  *)
    PSLMFLAGS="$PSLMFLAGS '$a'"
    ;;
  esac
done

printf "par=%s PSLMFLAGS=<%s>\n" "$parallel" "$PSLMFLAGS"

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
# If I am in a 32-bit cygwin shell I can make not just the 32-bit cygwin
# version but also both 32 and 64-bit (native, mingw) Windows variants.
# These days I can also (cross) build a 64-bit cygwin version...
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

# Now I will do things in different ways depending on whether a parallel
# build has been requested. The main reason for this is so that in the
# simple non-parallel case I just use the reasonably simple code that I
# have had for some time - the more delicate and messy version will
# only be called for if the user had specified "-j" to the top level
# invocation of "make". I hope this will help keep simple cases comprehensible
# and reliable...

if test "x$parallel" = "xno"
then

  for l in $list
  do
     if test -f ${l}/Makefile
     then
       echo About to build in ${l}
       cd ${l}
       echo $MAKE $flags $args MYFLAGS="$flags" --no-print-directory
       $MAKE $flags $args MYFLAGS="$flags" --no-print-directory
       r=$?
# This version exits if any of the attempts to build fails
       if test $r != 0
       then
         echo Building failed with return code $r for version ${l}
         exit $r
       fi
# What I had before kept going if one build failed but recorded the
# highest return code from all versions.
       test $r -gt $rc && rc=$?
       cd ../..
     fi
  done

  exit $rc


else
# Now I have the parallel version. This works by dynamically creating a new
# Makefile (called Makefile.tmp) and using a recursive call to make to
# process the targets that have been set up within it.

  printf "# Temporary Makefile...\n\n" > Makefile.tmp

  printf ".PHONY:\t" >> Makefile.tmp
  for l in $list
  do
    if test -f ${l}/Makefile
    then
      printf "%s " x_${l} >> Makefile.tmp
    fi
  done
  printf "\n\n" >> Makefile.tmp

  printf "everything:\t" >> Makefile.tmp
  for l in $list
  do
    if test -f ${l}/Makefile
    then
      printf "%s " x_${l} >> Makefile.tmp
    fi
  done
  printf "\n\n" >> Makefile.tmp

  for l in $list
  do
    if test -f ${l}/Makefile
    then
      case ${l} in
      pslbuild*)
        extras="MFLAGS=\"$PSLMFLAGS\""
        ;;
      *)
        extras=""
        ;;
      esac
      printf "%s:\n" x_${l} >> Makefile.tmp
      printf "\tcd %s; %s %s %s %s MYFLAGS=\"%s\" --no-print-directory\n\n" \
        "${l}" "$MAKE" "$extras" "$flags" "$args" "$flags" >> Makefile.tmp
    fi
  done
  printf "\n" >> Makefile.tmp

  printf "\n\n# End of temporary Makefile\n" >> Makefile.tmp

  if test "x$firstcsl" != "x"
  then
    cd $firstcsl/csl
    $MAKE c-code
    cd ../../..
  fi

  $MAKE -f Makefile.tmp $args

fi

exit $rc
