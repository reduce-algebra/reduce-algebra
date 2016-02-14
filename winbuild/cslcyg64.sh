#! /bin/bash -v

# Configure and build CSL version from scratch. This makes a 64-bit cygwin
# version and is launched from a cygwin64 shell. That can include the
# case of the use of cygalt.exe to move into a 64-bit cygwin world from
# a 32-bit one.

if test  "x`uname -m`" != "xx86_64"
then
  printf "This script needs to be run in a 64-bit cygwin environment\n"
  printf "You seem bot to be in one, so I am giving up\n"
  exit 1
fi

reduce=`cygpath -a ./C`
reduce="${reduce%/}"
echo $reduce

here=`cygpath -a .`
here="${here%/}"

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
