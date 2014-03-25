#! /bin/bash -v

# This starts off my making fresh binaries of the variations of Reduce
# that are relevant to me here... In each case I should leave a log
# recording the build.

# If given arguments will build those versions. If no arguments will
# build all.

for x in $*
do
  case $x in
  cyg32)
    cyg32="yes"
    ;;
  cyg64)
    cyg64="yes"
    ;;
  win32)
    win32="yes"
    ;;
  win64)
    win64="yes"
    ;;
  *)
    echo Unknown argument $x
    ;;
  esac
done

if test "x$cyg32$cyg64$win32$win64" = "x"
then
  cyg32="yes"
  cyg64="yes"
  win32="yes"
  win64="yes"
fi

here=`cygpath -a .`
here=${here%/}
echo here = $here

if test "x$cyg32" = "xyes"
then
  script cyg32.log -c "./makebin.sh cyg32 i686-pc-cygwin --with-cygwin"
fi

if test "x$cyg64" = "xyes"
then
  script cyg64.log -c "./cyg64.sh ./makebin.sh cyg64 x86_64-pc-cygwin \
    --with-cygwin"
fi

if test "x$win32" = "xyes"
then
  script win32.log -c "./makebin.sh win32 i686-w64-mingw32 \
    --with-cygbuild=$here/cyg32 --with-cygbuild64=$here/cyg64"
fi

if test "x$win64" = "xyes"
then
  script win64.log -c "./makebin.sh win64 x86_64-w64-mingw32 \
    --with-cygbuild=$here/cyg32 --with-cygbuild64=$here/cyg64"
fi

echo All binaries should now be made
ls -l */csl/reduce.exe

make all


