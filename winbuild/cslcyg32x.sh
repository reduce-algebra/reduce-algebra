#! /bin/bash -v

# Configure and build CSL version from scratch. This makes a 32-bit cygwin
# version, but will be launched from a cygwin64 shell. Note it needs my
# "cygalt" utility to arrange that building happens under 32-bit cygwin...


# For this to work you MUST have a 32-bit version of cygwin installed.

reduce=`./cygalt cygpath -a ..`
reduce="${reduce%/}"
echo $reduce

rm -rf cslcyg32
mkdir cslcyg32
pushd cslcyg32

mkdir crlibm
pushd crlibm
../../cygalt $reduce/libraries/crlibm/configure \
    --prefix=$reduce/winbuild/cslcyg32
../../cygalt make install
popd

mkdir softfloat
pushd softfloat
../../cygalt $reduce/libraries/SoftFloat-3a/configure \
    --prefix=$reduce/winbuild/cslcyg32
../../cygalt make install
popd

mkdir fox
pushd fox
foxflags="--enable-release --with-opengl=no \
          --disable-jpeg --disable-zlib --disable-bz2lib \
          --disable-png --disable-tiff"
extras="--with-xft --with-xim"
../../cygalt $reduce/csl/fox/configure \
    --prefix=$reduce/winbuild/cslcyg32 $foxflags $extras
../../cygalt make install
popd

mkdir csl
pushd csl
../../cygalt $reduce/csl/cslbase/configure --prefix=$reduce/winbuild/cslcyg32 \
    --with-cygwin --with-fox=$reduce/winbuild/cslcyg32 --with-fox-pending \
    --without-wx
../../cygalt make
ls -lh reduce.exe reduce.img csl.exe csl.img
popd

popd

# end of script
