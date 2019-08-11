#! /bin/sh

# Assemble some of the built files & directories  I will want, putting them
# in the current directory where I can see them.

ver=cslwin64

rm -rf cslbuild
mkdir -p cslbuild
mkdir -p cslbuild/reduce.resources
mkdir -p cslbuild/reduce.fonts

cp $ver/csl/reduce.img cslbuild/reduce.img
cp $ver/csl/bootstrapreduce.img cslbuild/bootstrapreduce.img
cp $ver/csl/csl.img cslbuild/csl.img
cp -r $ver/csl/reduce.fonts/* cslbuild/reduce.fonts
cp -r $ver/csl/reduce.resources/* cslbuild/reduce.resources

# I will need two helper programs that have been built so as to run
# under cygwin. Here I build them...
# The code tries to launch these to determine whether cygwin is active, and
# if it is whether stdin and stdout are linked directly to a cygwin console.

gcc -O2 cygwin-isatty.c -o cygwin64-isatty.exe
strip cygwin64-isatty.exe

# stub.c is a stub program that tests the environment it is launched from
# and chains to a suitable version of the code... But I want the stub to
# be able to recover reasonably if not enough cygwin components have been
# installed so I will first sort out just which DLLs the reduce binaries
# rely on.

objdump -p cslcyg64/csl/reduce.exe | grep DLL | sed '1d;s#\tDLL Name: #    \"#; s#$#\",#' | sort > dll64.c

i686-w64-mingw32-gcc -DFAT64 -DNAME=red $debugflag -O3 newstub.c \
	--static -lz -o cslbuild/reduce.exe
i686-w64-mingw32-strip cslbuild/reduce.exe

cp	cygwin64-isatty.exe      cslbuild/reduce.resources/isatty64.exe
cp	cslwin64/csl/reduce.com  cslbuild/reduce.resources/redwin64.exe
cp	cslcyg64/csl/reduce.exe  cslbuild/reduce.resources/redcyg64.exe

# Now a rather similar process except that it will be linked as a windows
# not a console binary. As such it will not be useful in a cygwin world,
# but it will be the correct thing to double click on.

i686-w64-mingw32-gcc -DFATWIN -DNAME=wred $debugflag -O3 newstub.c \
	-Wl,--subsystem,windows --static -lz -o cslbuild/winreduce.exe
i686-w64-mingw32-strip cslbuild/winreduce.exe

cp	cslwin64/csl/reduce.exe  cslbuild/reduce.resources/wredwin64.exe

i686-w64-mingw32-gcc -DFAT64 -DNAME=boot $debugflag -O3 newstub.c \
	--static -lz -o cslbuild/bootstrapreduce.exe
i686-w64-mingw32-strip cslbuild/bootstrapreduce.exe

cp	cygwin64-isatty.exe              cslbuild/reduce.resources/isatty64.exe
cp	cslwin64/csl/bootstrapreduce.exe cslbuild/reduce.resources/bootwin64.exe
cp	cslcyg64/csl/bootstrapreduce.exe cslbuild/reduce.resources/bootcyg64.exe

i686-w64-mingw32-gcc -DFAT64 -DNAME=csl $debugflag -O3 newstub.c \
	--static -lz -o cslbuild/csl.exe
i686-w64-mingw32-strip cslbuild/csl.exe

cp	cygwin64-isatty.exe  cslbuild/reduce.resources/isatty64.exe
cp	cslwin64/csl/csl.com cslbuild/reduce.resources/cslwin64.exe
cp	cslcyg64/csl/csl.exe cslbuild/reduce.resources/cslcyg64.exe

# Now a rather similar process except that it will be linked as a windows
# not a console binary. As such it will not be useful in a cygwin world,
# but it will be the correct thing to double click on.

i686-w64-mingw32-gcc -DFATWIN -DNAME=wcsl $debugflag -O3 newstub.c \
	-Wl,--subsystem,windows --static -lz -o cslbuild/wincsl.exe
i686-w64-mingw32-strip cslbuild/wincsl.exe

cp	cslwin64/csl/csl.exe cslbuild/reduce.resources/wcslwin64.exe

# Inspect the files created.

ls -lhR cslbuild

# Tidy up the the helper apps

rm cygwin64-isatty.exe

echo all versions built
