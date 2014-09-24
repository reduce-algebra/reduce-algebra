#! /bin/bash -v

# Configure and build CSL version from scratch. This makes a 64-bit cygwin
# version. Note it needs my "cyg64" utility to arrange that it runs under
# 64-bit cygwin...

# It is important here that the current directory was preserved during the
# change-over made by the "cyg64" utility...

reduce=`cygpath -a ..`
reduce="${reduce%/}"
echo $reduce

# For this to work you MUST have a 64-bit version of cygwin installed in
# a directory like /cygdrive/c/cygwin64 or /cygdrive/d/cygwin64

./make-cyg64.sh

rm -rf cslcyg64
mkdir cslcyg64
pushd cslcyg64

mkdir crlibm
pushd crlibm
../../cyg64 $reduce/csl/cslbase/crlibm/configure \
    --prefix=$reduce/winbuild/cslcyg64
../../cyg64 make install
popd

mkdir fox
pushd fox
foxflags="--enable-release --with-opengl=no \
          --disable-jpeg --disable-zlib --disable-bz2lib \
          --disable-png --disable-tiff"
extras="--with-xft --with-xim"
../../cyg64 $reduce/csl/fox/configure \
    --prefix=$reduce/winbuild/cslcyg64 $foxflags $extras
../../cyg64 make install
popd

mkdir csl
pushd csl
../../cyg64 $reduce/csl/cslbase/configure --prefix=$reduce/winbuild/cslcyg64 \
    --with-cygwin --with-fox=$reduce/winbuild/cslcyg64 --with-fox-pending \
    --without-wx
../../cyg64 make
ls -lh reduce.exe reduce.img csl.exe csl.img
popd

popd

