#! /bin/bash -v

# Configure and build CSL version from scratch. This takes arguments
# that indicate the version of Reduce to be built and whether it is
# necessary to flip into the other (32 vs 64-bit) version of cygwin to
# perform the build.
#
#   cslbuild1.sh [cyg32/win32/cyg64/win64] [cygalt/]

# There is a mess in some of what I do because cygwin32 and cygwin64 will
# each have their own separate root file-systems and home directories. The
# consequence is that paths such as /something, /home/username/something and
# /usr/bin/something can refer to Windows paths c:\cygwin\something or
# c:\cygwin64\something (etc) depending on which is in use. To avoid
# any confusion when I use my "cygalt" program and pass paths to scripts
# I want to construct very plain explicit absolute paths. I start with
# "cygpath -a ." which may deliver something like "/cygdrive/path1/path2/"
# and which leaves a "/" on the end of its result. I remove the trailing "/",
# then convert to a "mixed" path, which may be "C:/cygwin/path1/path2", but
# is now a proper absolute path regardless of any mounted cygwin folders such
# as "/usr/bin" and "home". To get that back to be suitable for use as a
# cygwin path I put "/cygpath" on the start and remove the ":". I do not
# seem to be able to use cygpath, since for instance that maps "C:\cygwin\home"
# to just "/home" on 32-bit cygwin but "C:\cygwin64\home" to "/home" in the
# 64-bit world.  

here=`cygpath -a .`
here=${here%/}
here=`cygpath -m $here`
here=`echo /cygdrive/$here | sed -e 's/://'`
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
