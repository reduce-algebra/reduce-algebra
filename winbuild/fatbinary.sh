#! /bin/sh

# Assemble some of the built files & directories  I will want, putting them
# in the current directory where I can see them.

case ${1:-2} in
1 | 3)
  ver=cslwin64
  ;;
2)
  ver=cslwin32
  ;;
*)
  echo argument $1 invalid: should ba 1, 2 or 3
  exit 1
  ;;
esac

mkdir -p cslbuild

cp $ver/csl/reduce.img cslbuild/reduce.img
cp $ver/csl/bootstrapreduce.img cslbuild/bootstrapreduce.img
cp $ver/csl/csl.img cslbuild/csl.img
cp -r $ver/csl/reduce.fonts cslbuild/reduce.fonts
cp -r $ver/csl/reduce.resources cslbuild/reduce.resources

# Create the utility program that will compress executables and
# tag the commpressed data onto the end of an existing file. I will
# build thus using i686-w64-mingw32-gcc since then the executable should
# run on all possible platforms.

i686-w64-mingw32-gcc addresources.c -static -lz -oaddresources.exe

# I will need two helper programs that have been built so as to run
# under cygwin32 and cygwin64. Here I build them...
# The code tries to launch these to determine whether cygwin is active, and
# if it is whether stdin and stdout are linked directly to a cygwin console.

case `uname -m` in
i686)
  gcc -O2 cygwin-isatty.c -o cygwin32-isatty.exe
  strip cygwin32-isatty.exe

  x86_64-pc-cygwin-gcc -O2 cygwin-isatty.c -o cygwin64-isatty.exe
  x86_64-pc-cygwin-strip cygwin64-isatty.exe
  ;;
x86_64)
  i686-pc-cygwin-gcc -O2 cygwin-isatty.c -o cygwin32-isatty.exe
  i686-pc-cygwin-strip cygwin32-isatty.exe

  gcc -O2 cygwin-isatty.c -o cygwin64-isatty.exe
  strip cygwin64-isatty.exe
  ;;
*)
  echo unknown architecture `uname -n`
  exit 1
  ;;
esac

# stub.c is a stub program that tests the environment it is launched from
# and chains to a suitable version of the code... But I want the stub to
# be able to recover reasonably if not enough cygwin components have been
# installed so I will first sort out just which DLLs the reduce binaries
# rely on.

case `uname -m`
in
i686)
  objdump -p cslcyg32/csl/reduce.exe | grep DLL | sed '1d;s#\tDLL Name: #    \"#; s#$#\",#' | sort > dll32.c
  x86_64-pc-cygwin-objdump -p cslcyg64/csl/reduce.exe | grep DLL | sed '1d;s#\tDLL Name: #    \"#; s#$#\",#' | sort > dll64.c
  ;;
x86_64)
  i686-pc-cygwin-objdump -p cslcyg32/csl/reduce.exe | grep DLL | sed '1d;s#\tDLL Name: #    \"#; s#$#\",#' | sort > dll32.c
  objdump -p cslcyg64/csl/reduce.exe | grep DLL | sed '1d;s#\tDLL Name: #    \"#; s#$#\",#' | sort > dll64.c
  ;;
*)
  echo Unknown machine `uname -m`
  ;;
esac


i686-w64-mingw32-gcc -DFAT64 -O2 stub.c \
	--static -lz -o cslbuild/reduce.exe
i686-w64-mingw32-strip cslbuild/reduce.exe

# Now I create the real version of a "reduce.exe" that will be launchable
# from a console (either Windows or 32 or 64-bit cygwin) by packing
# stuff on the end of the stub.

./addresources cslbuild/reduce.exe \
	cygwin32-isatty.exe \
	cygwin64-isatty.exe \
	cslwin32/csl/reduce.com \
	cslwin64/csl/reduce.com \
	cslcyg32/csl/reduce.exe \
	cslcyg64/csl/reduce.exe

# Now a rather similar process except that it will be linked as a windows
# not a console binary. As such it will not be useful in a cygwin world,
# but it will be the correct thing to double click on.

i686-w64-mingw32-gcc -DFATWIN -O2 stub.c \
	-Wl,--subsystem,windows --static -lz -o cslbuild/winreduce.exe
i686-w64-mingw32-strip cslbuild/winreduce.exe

# Add the relevant things to this... Observe that actually the only thing
# it has to do that is at all clever is to decide whether it is running
# on a 32 or 64-bit machine. Yes you could make the installer decide whether
# to install a 32 or 64-bit binary, but this way a single binary will be
# good for everybody.

./addresources cslbuild/winreduce.exe \
	cslwin32/csl/reduce.exe \
	cslwin64/csl/reduce.exe

i686-w64-mingw32-gcc -DFAT64 -O2 stub.c \
	--static -lz -o cslbuild/bootstrapreduce.exe
i686-w64-mingw32-strip cslbuild/bootstrapreduce.exe

# Also the real version of a "bootstrapreduce.exe" that will be launchable
# from a console (either Windows or 32 or 64-bit cygwin) by packing
# stuff on the end of the stub.

./addresources cslbuild/bootstrapreduce.exe \
	cygwin32-isatty.exe \
	cygwin64-isatty.exe \
	cslwin32/csl/bootstrapreduce.exe \
	cslwin64/csl/bootstrapreduce.exe \
	cslcyg32/csl/bootstrapreduce.exe \
	cslcyg64/csl/bootstrapreduce.exe

i686-w64-mingw32-gcc -DFAT64 -O2 stub.c \
	--static -lz -o cslbuild/csl.exe
i686-w64-mingw32-strip cslbuild/csl.exe

# Finally create the real version of a "csl.exe" that will be launchable
# from a console (either Windows or 32 or 64-bit cygwin) by packing
# stuff on the end of the stub.

./addresources cslbuild/csl.exe \
	cygwin32-isatty.exe \
	cygwin64-isatty.exe \
	cslwin32/csl/csl.com \
	cslwin64/csl/csl.com \
	cslcyg32/csl/csl.exe \
	cslcyg64/csl/csl.exe

# Now a rather similar process except that it will be linked as a windows
# not a console binary. As such it will not be useful in a cygwin world,
# but it will be the correct thing to double click on.

i686-w64-mingw32-gcc -DFATWIN -O2 stub.c \
	-Wl,--subsystem,windows --static -lz -o cslbuild/wincsl.exe
i686-w64-mingw32-strip cslbuild/wincsl.exe

# Add the relevant things to this... Observe that actually the only thing
# it has to do that is at all clever is to decide whether it is running
# on a 32 or 64-bit machine. Yes you could make the installer decide whether
# to install a 32 or 64-bit binary, but this way a single binary will be
# good for everybody.

./addresources cslbuild/wincsl.exe \
	cslwin32/csl/csl.exe \
	cslwin64/csl/csl.exe

# Inspect the files created.

ls -lhd cslbuild

# Tidy up the the helper apps

rm cygwin32-isatty.exe cygwin64-isatty.exe

echo all versions built
