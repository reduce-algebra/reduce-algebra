#! /bin/bash -v

# Configure and build CSL version from scratch. This makes a 32-bit cygwin
# version and is launched from a cygwin32 shell.

reduce=`cygpath -a ./C`
reduce="${reduce%/}"
echo $reduce

here=`cygpath -a .`
here="${here%/}"

rm -rf cslcyg32
mkdir cslcyg32
pushd cslcyg32

mkdir crlibm
pushd crlibm
$reduce/libraries/crlibm/configure --prefix=$here/cslcyg32
make install
popd

mkdir softfloat
pushd softfloat
$reduce/libraries/SoftFloat-3a/configure --prefix=$here/cslcyg32
make install
popd

mkdir fox
pushd fox
foxflags="--enable-release --with-opengl=no \
          --disable-jpeg --disable-zlib --disable-bz2lib \
          --disable-png --disable-tiff"
extras="--with-xft --with-xim"
$reduce/csl/fox/configure --prefix=$here/cslcyg32 $foxflags $extras
make install
popd

mkdir csl
pushd csl
$reduce/csl/cslbase/configure --prefix=$here/cslcyg32 \
    --with-cygwin --with-fox=$here/cslcyg32 --with-fox-pending \
    --without-wx
make
ls -lh reduce.exe reduce.img csl.exe csl.img
popd

popd

# end of script
