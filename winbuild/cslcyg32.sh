#! /bin/bash -v

# Configure and build CSL version from scratch. This makes a 32-bit cygwin
# version

reduce=`pwd`/..

rm -rf cslcyg32
mkdir cslcyg32
pushd cslcyg32

mkdir crlibm
pushd crlibm
$reduce/csl/cslbase/crlibm/configure --prefix=$reduce/winbuild/cslcyg32
make install
popd

mkdir fox
pushd fox
foxflags="--enable-release --with-opengl=no \
          --disable-jpeg --disable-zlib --disable-bz2lib \
          --disable-png --disable-tiff"
extras="--with-xft --with-xim"
$reduce/csl/fox/configure --prefix=$reduce/winbuild/cslcyg32 $foxflags $extras
make install
popd

mkdir csl
pushd csl
$reduce/csl/cslbase/configure --prefix=$reduce/winbuild/cslcyg32 \
    --with-cygwin --with-fox=$reduce/winbuild/cslcyg32 --with-fox-pending \
    --without-wx
make full-code
make
ls -lh reduce.exe reduce.img csl.exe csl.img
popd

popd


