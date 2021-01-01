#! /bin/bash

l=""
for x in cslbuild/*/csl/Makefile
do
  x="${x%%/csl/Makefile}"
  x="${x##*/}"
  l="$l $x"
done

m="/tmp/parmake"
printf "# Makefile for Reduce\n" > $m
printf "all:\t$l\n\n" >> $m

# I have seen cases where Makefile exists but config.status has got lost
# so in such cases I will try to recreate it.

first=""
second=""
for x in $l
do
  if ! test -f cslbuild/$x/csl/config.status
  then
    pushd cslbuild/$x
    ./config.status --recheck
    popd
  fi
  case $x in
  *conservative* | *arithlib*)
# Do *NOT* build these at present since they will not yet work!
    ;;
  *-*-*-*)
    if test "$second" = ""
    then
      second="$x"
    fi
    ;;
  *)
    if test "$first" = ""
    then
      first="$x"
    fi
  esac
done

if test "$first" = ""
then
  first="$second"
fi

if test "$first" = ""
then
  exit 0
fi

if test "`uname -s`" = "Darwin"
then
  GNU_MAKE=gmake
  RED=reduce.app/Contents/MacOS/reduce.img
  BOOT=bootstrapreduce.app/Contents/MacOS/bootstrapreduce.img
else
  GNU_MAKE=make
  RED=reduce.img
  BOOT=bootstrapreduce.img
fi

# I need to ensure that if the generated C++ code needs rebuilding that
# that is done once (sequentially). I will use the first build target that
# does not have any suffices.

$GNU_MAKE cslbuild/$first/csl/reduce-u01.o

for x in $l
do
  printf "$x:\n\techo Building for $x\n" >> $m
  printf "\t\$(MAKE) -C cslbuild/$x/csl > $x.log 2>&1\n" >> $m
  printf "\t\$(MAKE) -C cslbuild/$x/csl $BOOT > $x.log 2>&1\n\n" >> $m
done

if test "`which nproc`" != "" && test "$?" = "0"
then
  N=`nproc`
else
  if test "`which sysctl`" != "" && test "$?" = "0"
  then
    N=`sysctl -n hw.ncpu`
  else
    N=2
  fi
fi

time $GNU_MAKE -j $N -f $m

for x in $l
do
  if ! test -f cslbuild/$x/csl/$RED
  then
    printf "Issue with cslbuild/$x/csl/$RED\n"
  fi
  if ! test -f cslbuild/$x/csl/$BOOT
  then
    printf "Issue with cslbuild/$x/csl/$BOOT\n"
  fi
done

