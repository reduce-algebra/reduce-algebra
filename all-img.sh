#! /usr/bin/env bash -v

REDUCE_EXE="no"

for x in cslbuild/*/csl
do
  pushd $x
  if test "x$REDUCE_EXE" != "xyes"
  then
# This bit is in case the generated C++ files u01.cpp to u60.cpp need
# updating.
    make -j8 bootstrapreduce
    make -j8 reduce
    REDUCE_EXE="yes"
  fi
  make csl.img &
  make bootstrapreduce.img &
  make reduce.img &
  popd
done

# I want all rebuilding to finish before I report success!
wait

printf "All image files rebuilt.\n"
