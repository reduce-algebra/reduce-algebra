#! /bin/bash -v

# Configure and build CSL version from scratch. This makes a 64-bit cygwin
# version but is launched from a cygwin32 shell. It uses traditional
# cross compilation.

if test  "x`uname -m`" != "xi686"
then
  printf "This script needs to be run in a 64-bit cygwin environment\n"
  printf "You seem bot to be in one, so I am giving up\n"
  exit 1
fi

reduce=`cygpath -a ./C`
reduce="${reduce%/}"
echo $reduce

rm -rf cslcyg64
mkdir cslcyg64
pushd cslcyg64

mkdir crlibm
pushd crlibm
$reduce/csl/cslbase/crlibm/configure --host=x86_64-pc-cygwin \
    --prefix=$reduce/winbuild/cslcyg64
make install
popd

mkdir fox
pushd fox
foxflags="--enable-release --with-opengl=no \
          --disable-jpeg --disable-zlib --disable-bz2lib \
          --disable-png --disable-tiff"
extras="--with-xft --with-xim"
$reduce/csl/fox/configure --host=x86_64-pc-cygwin \
    --prefix=$reduce/winbuild/cslcyg64 $foxflags $extras
make install
popd

mkdir csl
pushd csl
$reduce/csl/cslbase/configure --host=x86_64-pc-cygwin \
    --prefix=$reduce/winbuild/cslcyg64 \
    --with-cygwin --with-fox=$reduce/winbuild/cslcyg64 --with-fox-pending \
    --without-wx
make
ls -lh reduce.exe reduce.img csl.exe csl.img
popd

popd

# end of script
