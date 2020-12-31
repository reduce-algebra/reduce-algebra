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

for x in $l
do
  if ! test -f cslbuild/$x/csl/config.status
  then
    pushd cslbuild/$x
    ./config.status --recheck
    popd
  fi
done

for x in $l
do
  printf "$x:\n\techo Building for $x\n" >> $m
  printf "\t\$(MAKE) -C cslbuild/$x/csl > $x.log 2>&1\n" >> $m
  printf "\t\$(MAKE) -C cslbuild/$x/csl bootstrapreduce.img > $x.log 2>&1\n\n" >> $m
done

time make -j `nproc` -f $m

for x in $l
do
  if ! test -f cslbuild/$x/csl/reduce.img
  then
    printf "Issue with cslbuild/$x/csl/reduce.img\n"
  fi
  if ! test -f cslbuild/$x/csl/bootstrapreduce.img
  then
    printf "Issue with cslbuild/$x/csl/bootstrapreduce.img\n"
  fi
done

