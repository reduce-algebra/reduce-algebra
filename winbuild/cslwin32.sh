#! /bin/bash -v

# Configure and build CSL version from scratch. This is a native version
# for Windows in 32-bit mode.

reduce=`cygpath -a ./clean-tree`
reduce="${reduce%/}"
echo $reduce

here=`cygpath -a .`

rm -rf cslwin32
mkdir cslwin32
pushd cslwin32

mkdir crlibm
pushd crlibm
$reduce/csl/cslbase/crlibm/configure --prefix=$here/cslwin32 \
    --host=i686-w64-mingw32
# This script is invoked on its own ahead of the other builds of Reduce
# versions and so I feel entitled to use "-j4" for parallel building.
# I argue that even on a single processor machine (now increasingly rare)
# this will not be a calamity, and on a multicore machine it will really help.
make -j4 install
popd

mkdir fox
pushd fox
foxflags="--enable-release --with-opengl=no \
          --disable-jpeg --disable-zlib --disable-bz2lib \
          --disable-png --disable-tiff"
$reduce/csl/fox/configure --prefix=$here/cslwin32 $foxflags \
    --host=i686-w64-mingw32
make -j4 install
popd

mkdir csl
pushd csl
$reduce/csl/cslbase/configure --prefix=$here/cslwin32 \
    --host=i686-w64-mingw32 --with-fox=$here/cslwin32 \
    --with-fox-pending --without-wx
make -j4 standard-c-code
make -j4
ls -lh reduce.exe reduce.com reduce.img csl.exe csl.img
popd

popd

# end of script
