#! /bin/bash

# This script is here to bring all currently configured copies of the
# CSL versuion of Reduce up to date using parallel builds that try to
# exploit all available CPU cores. It works by creating a temporary
# Makefile in /tmp/makeall and using it with "-j N" where N is the number
# of available processor cores. One step in a rebuild can involve remaking
# bootstrapreduce and using it to compile selected parts of the main Reduce
# source into C++ code in cslbuild/generated-c/u*.cpp. This should be
# done on just one architecture before others try to use the results. The
# selected architecture for this will be the one in the alphabetically first
# build directory within cslbuild. Under windows this will typically be
# cslbuild/x86_64-pc-cygwin which is a reasonable choice.
#
# If configuration or building in any directory failed or fails here then
# this parallel attempt may lead to diagnostics interleaved with other
# more successful output, so trying again with "make" in a failed directory
# may be a good plan.

printf "SUBDIRS = \\" > /tmp/makeall
printf "\n" >> /tmp/makeall
first=""
for x in `ls -d cslbuild/*/csl`
do
  if test "$first" = ""
  then
echo setting first = $x
    first=$x
  fi
  printf "\t$x \\" >> /tmp/makeall
  printf "\n" >> /tmp/makeall
# rm -f $x/reduce.img $x/reduce-u01.o
done
printf "\n\n" >> /tmp/makeall
printf "default:\tall\n\n" >> /tmp/makeall
printf "\$(SUBDIRS)::\n\t\$(MAKE) -C \$@ \$(MAKECMDGOALS)\n\n" >> /tmp/makeall
printf "all clean :\t\$(SUBDIRS)\n" >> /tmp/makeall

echo first = $first
if test "$first" = ""
then
  printf "\n+++ You need to run ./configure --with-csl .. before this\n"
  exit 1
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

# This initial use of "make" is to ensure that the generatd C++ code
# in cslbuild/generated-c is up to date.

time $GNU_MAKE -j $N -C $first reduce-u01.o

if test $? != 0
then
  printf "Rebuilding generated-c seems to have failed\n"
  exit 1
fi

time $GNU_MAKE -j $N -f /tmp/makeall

# As a small check for success I will look for a "reduce.img" in each
# directory considered

err=0
for x in `ls -d cslbuild/*/csl`
do
  y=${x#cslbuild/}
  y=${y%/csl}
  s=`stat -c%s $x/reduce.img 2>/dev/null`
  if test $? != 0 || test "$s" = ""
  then  
    printf "$y failed\n"
    err=1
  else
    d=`stat -c%y $x/reduce.img`
    d=${d%.*}
    printf "$y size=$s date=$d\n"
  fi
done

exit $err

