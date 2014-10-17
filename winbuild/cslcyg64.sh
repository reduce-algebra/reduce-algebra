#! /bin/bash -v

# Configure and build CSL version from scratch. This makes a 64-bit cygwin
# version and is launched froma cygwin64 shell.

reduce=`cygpath -a ./clean-tree`
reduce="${reduce%/}"
echo $reduce

here=`cygpath -a .`

rm -rf cslcyg64
mkdir cslcyg64
pushd cslcyg64

mkdir crlibm
pushd crlibm
$reduce/csl/cslbase/crlibm/configure --prefix=$here/cslcyg64
make install
popd

mkdir fox
pushd fox
foxflags="--enable-release --with-opengl=no \
          --disable-jpeg --disable-zlib --disable-bz2lib \
          --disable-png --disable-tiff"
extras="--with-xft --with-xim"
$reduce/csl/fox/configure --prefix=$here/cslcyg64 $foxflags $extras
make install
popd

mkdir csl
pushd csl
$reduce/csl/cslbase/configure --prefix=$here/cslcyg64 \
    --with-cygwin --with-fox=$here/cslcyg64 --with-fox-pending \
    --without-wx
make standard-c-code
make
ls -lh reduce.exe reduce.img csl.exe csl.img
popd

popd

# end of script
