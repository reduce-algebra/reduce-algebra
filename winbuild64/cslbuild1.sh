#! /bin/bash -v 

# Configure and build CSL version from scratch. This takes arguments
# that indicate the version of Reduce to be built.
#
#   cslbuild1.sh [cyg64/win64]

here=`cygpath -a .`
here=${here%/}
reduce="${here}/C"

case $1 in
win64)
  host="--host=x86_64-w64-mingw32"
  extras=""
  cygopt=""
  prefix="x86_64-w64-mingw32-"
  ;;
cyg64)
  host=""
  extras="--with-xft --with-xim"
  cygopt="--with-cygwin"
  prefix=""
  ;;
*)
  printf "\n+++ bad option $1 to cslbuild1.sh\n"
  exit 1
;;
esac

rm -rf csl$1
mkdir csl$1
pushd csl$1

printf "#! /bin/bash\nccache ${prefix}gcc \"\$@\"\n" > cachecc.sh
printf "#! /bin/bash\nccache ${prefix}g++ \"\$@\"\n" > cachecxx.sh
chmod +x cachecc.sh cachecxx.sh

here1=`pwd`
here1=`cygpath -a "$here1"`
CC="$here1/cachecc.sh"
CXX="$here1/cachecxx.sh"

pc1="CC=$CC"
pc2="CXX=$CXX"

mkdir libedit
pushd libedit
$reduce/libraries/libedit-20140620-3.1/configure --prefix=$here/csl$1
make install
popd

ln -s $reduce/libraries/wineditline .

mkdir redfront
pushd redfront
$reduce/generic/newfront/configure
make
popd

mkdir crlibm
pushd crlibm
$reduce/libraries/crlibm/configure "$pc1" "$pc2" $host --prefix=$here/csl$1
make install
popd

mkdir libffi
pushd libffi
$reduce/libraries/libffi/configure "$pc1" "$pc2" $host --prefix=$here/csl$1
make install
popd

mkdir softfloat
pushd softfloat
$reduce/libraries/SoftFloat-3a/source/configure "$pc1" "$pc2" $host --prefix=$here/csl$1
make install
popd

mkdir fox
pushd fox
foxflags="--enable-release --with-opengl=no \
          --disable-jpeg --disable-zlib --disable-bz2lib \
          --disable-png --disable-tiff"
$reduce/csl/fox/configure "$pc1" "$pc2" $host \
    --prefix=$here/csl$1 $foxflags $extras
make install
popd

mkdir csl
pushd csl
$reduce/csl/cslbase/configure "$pc1" "$pc2" $host --prefix=$here/csl$1 \
    $cygopt --with-fox=$here/csl$1 --with-fox-pending \
    --without-wx
make
make bootstrapreduce.img
ls -lh reduce.exe reduce.img \
       bootstrapreduce.exe bootstrapreduce.img \
       csl.exe csl.img
popd

popd

# end of script
