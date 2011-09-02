#! /bin/bash

dest=${r38_archive:-acn1@codemist.dyndns.org:/d/r38}
echo "Save object files to $dest [use r38_archive to override]"

# Create a set of .o files and pack them up ready for use
# in a distribution.

case `pwd` in
 *win32 | *win64)   EXEEXT=".exe"
           ;;
 *)        EXEEXT=""
           ;;
esac

case `pwd` in
 *demo*win64)
    rm fasl.obj gc.obj preserve.obj
    make r38$EXEEXT
    tar cfz objs.tgz *.obj -C ../fox64/lib libFOX-1.6.lib
    ;;
 *demo*)
    rm fasl.o gc.o preserve.o
    make r38$EXEEXT
    tar cfz objs.tgz *.o -C ../fox/lib libFOX-1.6.a libFOX-1.6.la
    ;;
 *win64)
    make r38$EXEEXT
    make slowr38$EXEEXT
    make csl$EXEEXT
    make fwindemo$EXEEXT
    make termdemo$EXEEXT
    tar cfz objs.tgz *.obj -C ../fox64/lib libFOX-1.6.lib
    ;;
 *)
    make r38$EXEEXT
    make slowr38$EXEEXT
    make csl$EXEEXT
    make fwindemo$EXEEXT
    make termdemo$EXEEXT
    tar cfz objs.tgz *.o -C ../fox/lib libFOX-1.6.a libFOX-1.6.la
    ;;
esac


here=`pwd`
here=${here##*/}
here=${here#local-}

# Note that demo versions will end up as demo-win32 (eg) while the
# regular releases will just end up as win32 (eg).

echo Destination: $here

scp objs.tgz $dest/objects/${here}.tgz

echo Object files for `pwd` saved

