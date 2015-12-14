#! /bin/bash

# trydyn.sh
#
# Usage:
#     trydyn.sh VERSION
# where VERSION is
#    cygwin, w32, w64 or linux/unix/mac/bsd

case x$1 in
*cygwin*)
  CC="g++"
  STRIP="strip"
  CFLAGS="dyndemo.def"
  LIBS="-ldl"
  IMPLIB="libdyndemo.a"
  IMPORTS="dlltool --def dyndemo.def --output-lib libdyndemo.a"
  DLLCFLAGS="-shared"
  DLL="so"
  ;;
*w32*)
  CC="i686-w64-mingw32-g++"
  STRIP="i686-w64-mingw32-strip"
  CFLAGS="-DWIN32=1 dyndemo.def"
  LIBS=
  IMPLIB="libdyndemo.a"
  IMPORTS="i686-w64-mingw32-dlltool --def dyndemo.def --output-lib libdyndemo.a"
  DLLCFLAGS="-shared"
  DLL="dll"
  ;;
*w64*)
  CC="x86_64-w64-mingw32-g++"
  STRIP="x86_64-w64-mingw32-strip"
  CFLAGS="-DWIN32=1 dyndemo.def"
  LIBS=
  IMPLIB="libdyndemo.a"
  IMPORTS="x86_64-w64-mingw32-dlltool --def dyndemo.def --output-lib libdyndemo.a"
  DLLCFLAGS="-shared"
  DLL="dll"
  ;;
*linux* | *unix* | *mac* | *bsd*)
  CC="g++"
  STRIP="strip"
  CFLAGS="-rdynamic"
  LIBS="-ldl"
  IMPLIB=
  IMPORTS=
  DLLCFLAGS="-shared -fPIC"
  DLL="so"
  ;;
*)
  echo Unknown target $1. Use cygwin, w32, w64, linux, unix, mac or bsd please
  exit 1
  ;;
esac

CFLAGS="$CFLAGS -O2 -Wall"

rm -f *.o *.so *.dll *.exe *.a

$CC $CFLAGS dyndemo.cpp $LIBS -o dyndemo
$IMPORTS
$CC $DLLCFLAGS dynmodule.cpp $IMPLIB -o dynmodule.$DLL

echo $CC $CFLAGS dyndemo.cpp $LIBS -o dyndemo
echo $IMPORTS " "
echo $CC $DLLCFLAGS dynmodule.cpp $IMPLIB -o dynmodule.$DLL
$STRIP dyndemo dynmodule.$DLL
ls -l dyndemo dynmodule.$DLL

./dyndemo

