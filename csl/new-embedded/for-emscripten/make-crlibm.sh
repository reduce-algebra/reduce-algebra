#! /bin/bash

rm -rf crlibm include lib
mkdir -p crlibm
cd crlibm

. ../emflags.sh

CC="emcc"

../../../../libraries/crlibm/configure \
  CC="$CC" \
  CFLAGS="$EMFLAGS -D__INTEL_COMPILER=1 -O3" \
  AR=emar \
  RANLIB=emranlib \
  --prefix=`pwd`/..
make clean
make
make install

cd ..
exit 0

