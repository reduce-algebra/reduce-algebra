#
# multi-target packed executable for Reduce
#

# Note that it is vital that when resources are added here that they are
# added in the order shown.

# Reduce for 32-bit machines, suitable for Windowed or console use
reduce32.exe:	addresources.exe stub.c cygwin32_isatty.exe w32.exe cyg32.exe
	i686-w64-mingw32-gcc -DFAT32 -O2 stub.c --static -lz -o reduce32.exe
	i686-w64-mingw32-strip reduce32.exe
	./addresources reduce32.exe cygwin32_isatty.exe w32.exe cyg32.exe

# Reduce for 32 or 64-bit machines, Windowed or console use
reduce64.exe:	addresources.exe stub.c cygwin32_isatty.exe cygwin64_isatty.exe w32.exe w64.exe cyg32.exe cyg64.exe
	i686-w64-mingw32-gcc -DFAT64 -O2 stub.c --static -lz -o reduce64.exe
	i686-w64-mingw32-strip reduce64.exe
	./addresources reduce64.exe cygwin32_isatty.exe cygwin64_isatty.exe w32.exe w64.exe cyg32.exe cyg64.exe

# Reduce for 32 or 64 bit machines for launching by double-clicking
winreduce.exe:	addresources.exe stub.c winw32.exe winw64.exe
	i686-w64-mingw32-gcc -DFATWIN -O2 stub.c -Wl,--subsystem,windows --static -lz -o winreduce.exe
	i686-w64-mingw32-strip winreduce.exe
	./addresources winreduce.exe winw32.exe winw64.exe


#stub.exe:	stub.c w32.c w64.c cyg32.c cyg64.c cygwin32_isatty.c cygwin64_isatty.c
#	i686-w64-mingw32-gcc -O2 stub.c -o stub.exe
#	i686-w64-mingw32-strip stub.exe

addresources.exe:	addresources.c
	gcc addresources.c -lz -oaddresources.exe

#hexify.exe:	hexify.c
#	gcc -O2 hexify.c -o hexify.exe

cygwin32_isatty.c:	cygwin32_isatty.exe
	./hexify cygwin32_isatty

cygwin64_isatty.c:	cygwin64_isatty.exe
	./hexify cygwin64_isatty

#w32.c:	hexify.exe w32.exe
#	./hexify w32
#
#w64.c:	hexify.exe w64.exe
#	./hexify w64
#
#cyg32.c:	hexify.exe cyg32.exe
#	./hexify cyg32
#
#cyg64.c:	hexify.exe cyg64.exe
#	./hexify cyg64

cygwin32_isatty.exe:	cygwin_isatty.c
	gcc -O2 cygwin_isatty.c -o cygwin32_isatty.exe
	strip cygwin32_isatty.exe

cygwin64_isatty.exe:	cygwin_isatty.c
	x86_64-pc-cygwin-gcc -O2 cygwin_isatty.c -o cygwin64_isatty.exe
	x86_64-pc-cygwin-strip cygwin64_isatty.exe

# End of Makefile

