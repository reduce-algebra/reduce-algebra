#! /bin/bash -v

# Configure and build CSL version from scratch. This makes a 64-bit cygwin
# version and is launched from a cygwin32 shell. It changes gear into
# the 64-bit world using by "cygalt" utility.

if test  "x`uname -m`" != "xi686"
then
  printf "This script needs to be run in a 32-bit cygwin environment\n"
  printf "You seem not to be in one, so I am giving up\n"
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
../cygalt $reduce/libraries/crlibm/configure --prefix=$here/cslcyg64
../cygalt make install
popd

mkdir softfloat
pushd softfloat
../cygalt $reduce/libraries/SoftFloat-3a/configure --prefix=$here/cslcyg64
../cygalt make install
popd

mkdir fox
pushd fox
foxflags="--enable-release --with-opengl=no \
          --disable-jpeg --disable-zlib --disable-bz2lib \
          --disable-png --disable-tiff"
extras="--with-xft --with-xim"
../cygalt $reduce/csl/fox/configure --prefix=$here/cslcyg64 $foxflags $extras
../cygalt make install
popd

mkdir csl
pushd csl
../cygalt $reduce/csl/cslbase/configure --prefix=$here/cslcyg64 \
    --with-cygwin --with-fox=$here/cslcyg64 --with-fox-pending \
    --without-wx
../cygalt make standard-c-code
../cygalt make
ls -lh reduce.exe reduce.img csl.exe csl.img
popd

popd

# end of script
