#! /bin/bash -v

# Configure and build CSL version from scratch. This takes arguments
# that indicate the version of Reduce to be built and whether it is
# necessary to flip into the other (32 vs 64-bit) version of cygwin to
# perform the build.
#
#   cslbuild1.sh [cyg32/win32/cyg64/win64] [cygalt/]

here=`cygpath -a .`
reduce="$here/C"

case $1 in
win32)
  host="--host=i686-w64-mingw32"
  extras=""
  cygopt=""
  ;;
win64)
  host="--host=x86_64-w64-mingw32"
  extras=""
  cygopt=""
  ;;
cyg32 | cyg64)
  host=""
  extras="--with-xft --with-xim"
  cygopt="--with-cygwin"
  ;;
*)
  printf "\n+++ bad option $1 to cslbuild1.sh\n"
  exit 1
;;
esac

if test "x$2" = "x"
then
  cygalt=""
else
  cygalt="../../cygalt.exe"
fi

rm -rf csl$1
mkdir csl$1
pushd csl$1

mkdir crlibm
pushd crlibm
$cygalt $reduce/libraries/crlibm/configure $host --prefix=$here/csl$1
$cygalt make install
popd

mkdir softfloat
pushd softfloat
$cygalt $reduce/libraries/SoftFloat-3a/source/configure $host --prefix=$here/csl$1
$cygalt make install
popd

mkdir fox
pushd fox
foxflags="--enable-release --with-opengl=no \
          --disable-jpeg --disable-zlib --disable-bz2lib \
          --disable-png --disable-tiff"
$cygalt $reduce/csl/fox/configure $host --prefix=$here/csl$1 $foxflags $extras
$cygalt make install
popd

mkdir csl
pushd csl
$cygalt $reduce/csl/cslbase/configure $host --prefix=$here/csl$1 \
    $cygopt --with-fox=$here/csl$1 --with-fox-pending \
    --without-wx
$cygalt make
ls -lh reduce.exe reduce.img csl.exe csl.img
popd

popd

# end of script
