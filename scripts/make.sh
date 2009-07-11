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

for a in $*
do
  if test "x$a" = "x@@@"
  then doingflags="no"
  elif test $doingflags = "yes"
  then flags="$flags $a"
  else args="$args $a"
  fi  
done

# config.guess fails on Solaris if SHELL is /bin/bash.
if test -x /bin/sh
then
  SHELL=/bin/sh
  export SHELL
fi

host=`./config.guess`
host=`scripts/findhost.sh $host`

echo Current machine tag is $host

# As a special concession I will see if we have a 64-bit (cross) compiler
# installed and called x86_64-pc-mingw32-gcc. If so I will consider all
# the possible cross-builds using it for 64-bit windows as well as all
# the normal builds native on this platform.

if { x86_64-pc-mingw32-gcc scripts/hello.c -o hello.exe ; } 2> /dev/null
then
  host="$host x86_64-pc-windows"
fi

rm -f hello.exe

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

for l in csl psl
do
  for h in $host
  do
    for hx in $h $h-debug $h-m32 $h-m32-debug $h-m64 $h-m64-debug
    do
      if test -f ${l}build/$hx/Makefile
      then
        echo About to build in ${l}build/$hx
        cd ${l}build/$hx
        $MAKE $flags $args MYFLAGS="$flags" --no-print-directory
        cd ../..
      fi
    done
  done
done

exit 0

