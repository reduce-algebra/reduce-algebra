#! /bin/bash

rm -rf crlibm include lib
mkdir -p crlibm
cd crlibm

../../../../libraries/crlibm/configure \
  CC=emcc \
  CFLAGS='-s STACK_OVERFLOW_CHECK=2 -s MALLOC=dlmalloc -s SAFE_HEAP=1 -D__INTEL_COMPILER=1' \
  AR=emar \
  RANLIB=emranlib \
  --prefix=`pwd`/..
make install-libLIBRARIES
make install-includeHEADERS
cd ..

exit 0

