#! /bin/sh

# Assemble some of the built files & directories  I will want, putting them
# in the current directory where I can see them.

cp cslwin64/csl/reduce.img reduce.img
cp -r cslwin64/csl/reduce.fonts reduce.fonts
cp -r cslwin64/csl/reduce.resources reduce.resources

# Create the utility program that will compress executables and
# tag the commpressed data onto the end of an existing file.

gcc addresources.c -lz -oaddresources.exe

# I will need two helper programs that have been built so as to run
# under cygwin32 and cygwin64. Here I build them...
# The code tries to launch thes eto determine whether cygwin is active, and
# if it is whether stdin and stdout are linked directly to a cygwin console.

gcc -O2 cygwin-isatty.c -o cygwin32-isatty.exe
strip cygwin32-isatty.exe

x86_64-pc-cygwin-gcc -O2 cygwin-isatty.c -o cygwin64-isatty.exe
x86_64-pc-cygwin-strip cygwin64-isatty.exe

# stub.c is a stub program that tests the environment it is launched from
# and chains to a suitable version of the code...

i686-w64-mingw32-gcc -DFAT64 -O2 stub.c \
	--static -lz -o reduce.exe
i686-w64-mingw32-strip reduce.exe

# Now I create the real version of a "reduce.exe" that will be launchable
# from a console (either Windows or 32 or 64-bit cygwin) by packing
# stuff on the end of the stub.

./addresources reduce.exe \
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
	-Wl,--subsystem,windows --static -lz -o winreduce.exe
i686-w64-mingw32-strip winreduce.exe

# Add the relevant things to this... Observe that actually the only thing
# it has to do that is at all clever is to decide whether it is running
# on a 32 or 64-bit machine. Yes you could make the installer decide whether
# to install a 32 or 64-bit binary, but this way a single binary will be
# good for everybody.

./addresources winreduce.exe \
	cslwin32/csl/reduce.exe \
	cslwin64/csl/reduce.exe

# Inspect the files created.

ls -lhd reduce.exe winreduce.exe reduce.img reduce.fonts reduce.resources

echo all versions built
