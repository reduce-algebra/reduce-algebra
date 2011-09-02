#! /bin/sh

# This script re-links all the code for Windows. This assumes that
# the Cygwin tool-chain is in installed and that the MingW32 option
# for that is present. As written here it supposes that FOX-1.6 has
# already been built and that (static) libraries for it are in
# ../fox/lib.  I also permit the libraries to be in the
# current directory

# Note that for Windows I link in some Windows libraries and I create
# both .com and .exe files, one with subsystem:console and the other
# for subsystem:windows

LIBS="-lpthread  -lcomctl32 -lgdi32 -lws2_32 -lwsock32 -lwinspool -lmpr"

g++ -o csl.com -L../fox/lib -L. -mno-cygwin -L/mingw/lib \
	-e _mainCRTStartup arith01.o arith02.o arith03.o arith04.o arith05.o \
	arith06.o arith07.o arith08.o arith09.o arith10.o arith11.o \
	arith12.o char.o csl.o cslmpi.o eval1.o eval2.o eval3.o eval4.o \
	fasl.o fns1.o fns2.o fns3.o gc.o preserve.o print.o cslread.o \
	restart.o sysfwin.o fwin.o FXTerminal.o FXWorker.o \
	FXDCNativePrinter.o FXPostscriptFont.o termed.o bytes.o \
	stubs.o fwin-csl.o -lFOX-1.6 $LIBS

g++ -o csl.exe -L../fox/lib -L. -mno-cygwin -L/mingw/lib \
	-e _mainCRTStartup -Wl,--subsystem,windows arith01.o arith02.o \
	arith03.o arith04.o arith05.o arith06.o arith07.o arith08.o \
	arith09.o arith10.o arith11.o arith12.o char.o csl.o cslmpi.o \
	eval1.o eval2.o eval3.o eval4.o fasl.o fns1.o fns2.o fns3.o \
	gc.o preserve.o print.o cslread.o restart.o sysfwin.o fwin.o \
	FXTerminal.o FXWorker.o FXDCNativePrinter.o FXPostscriptFont.o \
	termed.o bytes.o stubs.o fwin-csl.o -lFOX-1.6 $LIBS

g++ -o r38.com -L../fox/lib -L. -mno-cygwin -L/mingw/lib \
	-e _mainCRTStartup arith01.o arith02.o arith03.o arith04.o arith05.o \
	arith06.o arith07.o arith08.o arith09.o arith10.o arith11.o \
	arith12.o char.o csl.o cslmpi.o eval1.o eval2.o eval3.o eval4.o \
	fasl.o fns1.o fns2.o fns3.o gc.o preserve.o print.o cslread.o \
	restart.o sysfwin.o fwin.o FXTerminal.o FXWorker.o \
	FXDCNativePrinter.o FXPostscriptFont.o termed.o bytes.o u01.o \
	u02.o u03.o u04.o u05.o u06.o u07.o u08.o u09.o u10.o u11.o u12.o \
	fwin-r38.o -lFOX-1.6 $LIBS

g++ -o r38.exe -L../fox/lib -L. -mno-cygwin -L/mingw/lib -e \
	_mainCRTStartup -Wl,--subsystem,windows arith01.o arith02.o \
	arith03.o arith04.o arith05.o arith06.o arith07.o arith08.o \
	arith09.o arith10.o arith11.o arith12.o char.o csl.o cslmpi.o \
	eval1.o eval2.o eval3.o eval4.o fasl.o fns1.o fns2.o fns3.o \
	gc.o preserve.o print.o cslread.o restart.o sysfwin.o fwin.o \
	FXTerminal.o FXWorker.o FXDCNativePrinter.o FXPostscriptFont.o \
	termed.o bytes.o u01.o u02.o u03.o u04.o u05.o u06.o u07.o u08.o \
	u09.o u10.o u11.o u12.o fwin-r38.o -lFOX-1.6 $LIBS

g++ -o slowr38.com -L../fox/lib -L. -mno-cygwin -L/mingw/lib \
	-e _mainCRTStartup arith01.o arith02.o arith03.o arith04.o \
	arith05.o arith06.o arith07.o arith08.o arith09.o arith10.o \
	arith11.o arith12.o char.o csl.o cslmpi.o eval1.o eval2.o \
	eval3.o eval4.o fasl.o fns1.o fns2.o fns3.o gc.o preserve.o \
	print.o cslread.o restart.o sysfwin.o fwin.o FXTerminal.o \
	FXWorker.o FXDCNativePrinter.o FXPostscriptFont.o termed.o \
	bytes1.o stubs.o fwin-r38.o -lFOX-1.6 $LIBS

g++ -o slowr38.exe -L../fox/lib -L. -mno-cygwin -L/mingw/lib \
	-e _mainCRTStartup -Wl,--subsystem,windows arith01.o arith02.o \
	arith03.o arith04.o arith05.o arith06.o arith07.o arith08.o \
	arith09.o arith10.o arith11.o arith12.o char.o csl.o cslmpi.o \
	eval1.o eval2.o eval3.o eval4.o fasl.o fns1.o fns2.o fns3.o \
	gc.o preserve.o print.o cslread.o restart.o sysfwin.o fwin.o \
	FXTerminal.o FXWorker.o FXDCNativePrinter.o FXPostscriptFont.o \
	termed.o bytes1.o stubs.o fwin-r38.o -lFOX-1.6 $LIBS

g++ -o fwindemo.com -L../fox/lib -L. -mno-cygwin -L/mingw/lib \
	-e _mainCRTStartup fwindemo.o fwin.o FXTerminal.o FXWorker.o \
	FXDCNativePrinter.o FXPostscriptFont.o termed.o -lFOX-1.6 $LIBS

g++ -o fwindemo.exe -L../fox/lib -L. -mno-cygwin -L/mingw/lib \
	-e _mainCRTStartup -Wl,--subsystem,windows fwindemo.o fwin.o \
	FXTerminal.o FXWorker.o FXDCNativePrinter.o FXPostscriptFont.o \
	termed.o -lFOX-1.6 $LIBS

gcc -o termdemo.exe -mno-cygwin -L/mingw/lib -e _mainCRTStartup \
	termdemo.o termed.o $LIBS

# end of script

