#! /bin/sh

# This script is to create a set of "fat binaries" for use on Windows.
# It must be invoked in a directory where reduce.img, bootstrapreduce.img,
# csl.img, reduce.fonts and reduce.resources are present, as well as
# cslc32.exe, cslw32.exe, cslw32.com cslc64.exe, cslw64.exe, cslw64.com
# reducec32.exe, reducew32.exe, reducew32.com reducec64.exe,
#      reducew64.exe, reducew64.com
# bootstrapreducec32.exe, bootstrapreducew32.exe, bootstrapreducew32.com
#      bootstrapreducec64.exe, bootstrapreducew64.exe, bootstrapreducew64.com
# as all the possible interesting executables.

# If any of the above are missing it may fall over in untidy manners.
   
srcdir="$0";while test -L "$srcdir";do srcdir=`ls -ld "$srcdir" | sed 's/.*-> //'`;done
srcdir=`dirname "$srcdir"`
srcdir=`cd "$srcdir"; pwd -P`

# Build or rebuild all possible Windows versions of Reduce. For this to work
# you must be in a sub-directory ocslbuild where the Reduce binaries live,
# for instance t...trunk/cslbuild/x86_64-pc-windows/csl

w=`pwd`
case $w in
*/cslbuild/*-*-*/csl)
  ;;
*)
  printf "%s does not look like a proper directory to call this script from\n" $w
  printf "I expect something like ..../cslbuild/Cpu-Vendor-OS[-options]/csl\n"
  printf "e.g. reduce-algebra/cslbuild/x86_64-pc-linux-debug/csl\n"
  exit 1
  ;;
esac

w=${w%/csl}
w=${w##*-}
w=${w##*-}
w1=${w##*-}
if test "x$w" = "x$w1"
then
  suffix=""
else
  suffix="-$w1"
fi

pushd ../../i686-pc-windows$suffix/csl
make
make forinstall
popd

pushd ../../x86_64-pc-windows$suffix/csl
make
make forinstall
popd

pushd ../../i686-pc-cygwin$suffix/csl
make
make forinstall
popd

pushd ../../x86_64-pc-cygwin$suffix/csl
make
make forinstall
popd

cp -r ../../i686-pc-windows$suffix/csl/reduce.fonts .
cp -r ../../i686-pc-windows$suffix/csl/reduce.resources .
cp ../../i686-pc-windows$suffix/csl/cygwin-isatty.exe .
cp ../../i686-pc-windows$suffix/csl/cygwin64-isatty.exe .

cp ../../i686-pc-windows$suffix/csl/csl.exe cslw32.exe
cp ../../i686-pc-windows$suffix/csl/reduce.exe reducew32.exe
cp ../../i686-pc-windows$suffix/csl/bootstrapreduce.exe bootstrapreducew32.exe
cp ../../i686-pc-windows$suffix/csl/csl.com cslw32.com
cp ../../i686-pc-windows$suffix/csl/reduce.com reducew32.com

cp ../../x86_64-pc-windows$suffix/csl/csl.exe cslw64.exe
cp ../../x86_64-pc-windows$suffix/csl/reduce.exe reducew64.exe
cp ../../x86_64-pc-windows$suffix/csl/bootstrapreduce.exe bootstrapreducew64.exe
cp ../../x86_64-pc-windows$suffix/csl/csl.com cslw64.com
cp ../../x86_64-pc-windows$suffix/csl/reduce.com reducew64.com

cp ../../i686-pc-cygwin$suffix/csl/csl.exe cslc32.exe
cp ../../i686-pc-cygwin$suffix/csl/reduce.exe reducec32.exe
cp ../../i686-pc-cygwin$suffix/csl/bootstrapreduce.exe bootstrapreducec32.exe

cp ../../x86_64-pc-cygwin$suffix/csl/csl.exe cslc64.exe
cp ../../x86_64-pc-cygwin$suffix/csl/reduce.exe reducec64.exe
cp ../../x86_64-pc-cygwin$suffix/csl/bootstrapreduce.exe bootstrapreducec64.exe


# Assemble some of the built files & directories  I will want, putting them
# in the current directory where I can see them.

DEST=builtfiles
rm -rf $DEST
mkdir -p $DEST

cp reduce.img $DEST/reduce.img
cp bootstrapreduce.img $DEST/bootstrapreduce.img
cp csl.img $DEST/csl.img
cp -r reduce.fonts $DEST/reduce.fonts
cp -r reduce.resources $DEST/reduce.resources

# Create the utility program that will compress executables and
# tag the commpressed data onto the end of an existing file. I will
# build thus using i686-w64-mingw32-gcc since then the executable should
# run on all possible platforms.

i686-w64-mingw32-g++ $srcdir/addresources.cpp -O3 -static -lz -oaddresources.exe

# I will need two helper programs that have been built so as to run
# under cygwin32 and cygwin64. Here I build them...
# The code tries to launch these to determine whether cygwin is active, and
# if it is whether stdin and stdout are linked directly to a cygwin console.

i686-w64-mingw32-g++ -DFORCE32 -O3 $srcdir/other-cygwin.cpp -o cyg32
i686-w64-mingw32-g++ -DFORCE64 -O3 $srcdir/other-cygwin.cpp -o cyg64

./cyg32 g++ -O3 $srcdir/cygwin-isatty.cpp -o cygwin32-isatty.exe
./cyg32 strip cygwin32-isatty.exe
./cyg64 gcc -O3 $srcdir/cygwin-isatty.cpp -o cygwin64-isatty.exe
./cyg64 strip cygwin64-isatty.exe

# stub.cpp is a stub program that tests the environment it is launched from
# and chains to a suitable version of the code... But I want the stub to
# be able to recover reasonably if not enough cygwin components have been
# installed so I will first sort out just which DLLs the reduce binaries
# rely on.

# Well if I am running under cygwin64 then the version of objdump that I
# have can cope with 32-bit cygwin binaries. But if I am under cygwin32 then
# cygwin64 binaries are rejected. In fact I find that the list of DLLs uses
# seems to be the same in each case, so perhaps this cautious test is
# not really needed?

./cyg32 objdump -p reducec32.exe | grep DLL | sed '1d;s#\tDLL Name: #    \"#; s#$#\",#' | sort > dll32.cpp
./cyg64 objdump -p reducec64.exe | grep DLL | sed '1d;s#\tDLL Name: #    \"#; s#$#\",#' | sort > dll64.cpp

if test "x$2" = "xDEBUG"
then
  debugflag="-DDEBUG=1"
else
  debugflag=
fi

i686-w64-mingw32-g++ -DFAT64 $debugflag -O3 $srcdir/stub.cpp \
	--static -lz -o $DEST/reduce.exe
i686-w64-mingw32-strip $DEST/reduce.exe

# Now I create the real version of a "reduce.exe" that will be launchable
# from a console (either Windows or 32 or 64-bit cygwin) by packing
# stuff on the end of the stub.

./addresources $DEST/reduce.exe \
	cygwin32-isatty.exe \
	cygwin64-isatty.exe \
	reducew32.com \
	reducew64.com \
	reducec32.exe \
	reducec64.exe

# Now a rather similar process except that it will be linked as a windows
# not a console binary. As such it will not be useful in a cygwin world,
# but it will be the correct thing to double click on.

i686-w64-mingw32-g++ -DFATWIN $debugflag -O3 $srcdir/stub.cpp \
	-Wl,--subsystem,windows --static -lz -o $DEST/winreduce.exe
i686-w64-mingw32-strip $DEST/winreduce.exe

# Add the relevant things to this... Observe that actually the only thing
# it has to do that is at all clever is to decide whether it is running
# on a 32 or 64-bit machine. Yes you could make the installer decide whether
# to install a 32 or 64-bit binary, but this way a single binary will be
# good for everybody.

./addresources $DEST/winreduce.exe \
	reducew32.exe \
	reducew64.exe

i686-w64-mingw32-g++ -DFAT64 $debugflag -O3 $srcdir/stub.cpp \
	--static -lz -o $DEST/bootstrapreduce.exe
i686-w64-mingw32-strip $DEST/bootstrapreduce.exe

# Also the real version of a "bootstrapreduce.exe" that will be launchable
# from a console (either Windows or 32 or 64-bit cygwin) by packing
# stuff on the end of the stub.

./addresources $DEST/bootstrapreduce.exe \
	cygwin32-isatty.exe \
	cygwin64-isatty.exe \
	bootstrapreducew32.exe \
	bootstrapreducew64.exe \
	bootstrapreducec32.exe \
	bootstrapreducec64.exe

i686-w64-mingw32-g++ -DFAT64 $debugflag -O3 $srcdir/stub.cpp \
	--static -lz -o $DEST/csl.exe
i686-w64-mingw32-strip $DEST/csl.exe

# Finally create the real version of a "csl.exe" that will be launchable
# from a console (either Windows or 32 or 64-bit cygwin) by packing
# stuff on the end of the stub.

./addresources $DEST/csl.exe \
	cygwin32-isatty.exe \
	cygwin64-isatty.exe \
	cslw32.com \
	cslw64.com \
	cslc32.exe \
	cslc64.exe

# Now a rather similar process except that it will be linked as a windows
# not a console binary. As such it will not be useful in a cygwin world,
# but it will be the correct thing to double click on.

i686-w64-mingw32-g++ -DFATWIN $debugflag -O3 $srcdir/stub.cpp \
	-Wl,--subsystem,windows --static -lz -o $DEST/wincsl.exe
i686-w64-mingw32-strip $DEST/wincsl.exe

# Add the relevant things to this... Observe that actually the only thing
# it has to do that is at all clever is to decide whether it is running
# on a 32 or 64-bit machine. Yes you could make the installer decide whether
# to install a 32 or 64-bit binary, but this way a single binary will be
# good for everybody.

./addresources $DEST/wincsl.exe \
	cslw32.exe \
	cslw64.exe

# Inspect the files created.

ls -lh $DEST

echo all versions built
