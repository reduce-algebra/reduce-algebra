#! /bin/bash

# trydyn.sh
#
# Usage:
#     foreign.sh VERSION
# where VERSION is
#    cygwin, w32, w64 or linux/unix/mac/bsd

case x$1 in
*cygwin*)
  CC="gcc"
  STRIP="strip"
  DLLCFLAGS="-shared"
  DLL="so"
  EXE=".exe"
  ;;
*w32*)
  CC="i686-w64-mingw32-gcc"
  STRIP="i686-w64-mingw32-strip"
  DLLCFLAGS="-shared"
  DLL="dll"
  EXE=".com"
  ;;
*w64*)
  CC="x86_64-w64-mingw32-gcc"
  STRIP="x86_64-w64-mingw32-strip"
  DLLCFLAGS="-shared"
  DLL="dll"
  EXE=".com"
  ;;
*linux* | *unix* | *mac* | *bsd*)
  CC="gcc"
  STRIP="strip"
  DLLCFLAGS="-shared -fPIC"
  DLL="so"
  EXE=""
  ;;
*)
  echo Unknown target $1. Use cygwin, w32, w64, linux, unix, mac or bsd please
  exit 1
  ;;
esac

rm -f *.o *.so *.dll *.exe *.a

$CC $DLLCFLAGS foreign.c -o foreign.$DLL

echo $CC $DLLCFLAGS foreign.c -o foreign.$DLL
$STRIP foreign.$DLL
ls -l foreign.$DLL

./csl$EXE -w foreign.lsp -l foreign.log


# end of script

