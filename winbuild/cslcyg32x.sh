#! /bin/bash -v

# Configure and build CSL version from scratch. This makes a 32-bit cygwin
# version, but will be launched from a cygwin64 shell. Note it needs my "cyg32"
# utility to arrange that building happens under 32-bit cygwin...


# For this to work you MUST have a 32-bit version of cygwin installed.

reduce=`./cyg32 cygpath -a ..`
reduce="${reduce%/}"
echo $reduce

rm -rf cslcyg32
mkdir cslcyg32
pushd cslcyg32

mkdir crlibm
pushd crlibm
../../cyg32 $reduce/csl/cslbase/crlibm/configure \
    --prefix=$reduce/winbuild/cslcyg32
../../cyg32 make install
popd

mkdir fox
pushd fox
foxflags="--enable-release --with-opengl=no \
          --disable-jpeg --disable-zlib --disable-bz2lib \
          --disable-png --disable-tiff"
extras="--with-xft --with-xim"
../../cyg32 $reduce/csl/fox/configure \
    --prefix=$reduce/winbuild/cslcyg32 $foxflags $extras
../../cyg32 make install
popd

mkdir csl
pushd csl
../../cyg32 $reduce/csl/cslbase/configure --prefix=$reduce/winbuild/cslcyg32 \
    --with-cygwin --with-fox=$reduce/winbuild/cslcyg32 --with-fox-pending \
    --without-wx
../../cyg32 make
ls -lh reduce.exe reduce.img csl.exe csl.img
popd

popd

# end of script
