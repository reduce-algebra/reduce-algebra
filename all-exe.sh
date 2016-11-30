#! /bin/sh -v

for x in cslbuild/*/csl
do
  pushd $x
  make -j8 csl
  make -j8 bootstrapreduce
  make -j8 reduce
  popd
done

printf "All C++ code recompiled.\n"
