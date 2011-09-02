#! /bin/sh

# Relink everything for Linux.
#
# This supposes that FOX has already been built and its library
# is in $HOME/support/lib, or possibly for a case where the library has
# been distributed in binary form (as well as in source) in the current
# directory

# Note that the exact set of libraries that need to be listed here
# can vary between Linux distributions and releases. In particular
# some NEED Xcursor and Xrender while others must not list those libraries
# since they do not exist.

# The trial and error script here feels terribly ugly. What it does is to
# try linking with every combination of the libraries that I have seen
# delicacies about!  If this does not work you should probably change the
# linker diagnostic redirection so it does not to to /dev/null and work out
# just what is not being found.

rm -f /tmp/linker.log

for FOXLIB in "-L../fox/lib" "-L/usr/local/lib"; do
for LDFLAGS in "-L/usr/X11R6/lib" "-L/usr/X11R6/lib64"; do
echo "trying with $FOXLIB $LDFLAGS"
for thread in "-lpthread" ""; do
for dl in "-ldl" ""; do
for curses in "-lncurses" "-lcurses" ""; do
for render in "-lXrender" ""; do
for cursor in "-lXcursor" ""; do
    
LIBS="$cursor $render $curses -lXext -lX11 $thread $dl"

if g++ -o fwindemo  $FOXLIB $LDFLAGS fwindemo.o fwin.o \
	FXTerminal.o FXWorker.o FXDCNativePrinter.o FXPostscriptFont.o \
	termed.o  -lFOX-1.6 $LIBS 2>>/tmp/linker.log &&
   g++ -o csl       $FOXLIB $LDFLAGS arith01.o arith02.o \
	arith03.o arith04.o arith05.o arith06.o arith07.o arith08.o arith09.o \
	arith10.o arith11.o arith12.o char.o csl.o cslmpi.o eval1.o eval2.o \
	eval3.o eval4.o fasl.o fns1.o fns2.o fns3.o gc.o preserve.o print.o \
	cslread.o restart.o sysfwin.o fwin.o FXTerminal.o FXWorker.o \
	FXDCNativePrinter.o FXPostscriptFont.o termed.o bytes.o stubs.o \
	-lFOX-1.6 $LIBS 2>> /tmp/linker.log &&
   g++ -o r38       $FOXLIB $LDFLAGS arith01.o arith02.o \
	arith03.o arith04.o arith05.o arith06.o arith07.o arith08.o arith09.o \
	arith10.o arith11.o arith12.o char.o csl.o cslmpi.o eval1.o eval2.o \
	eval3.o eval4.o fasl.o fns1.o fns2.o fns3.o gc.o preserve.o print.o \
	cslread.o restart.o sysfwin.o fwin.o FXTerminal.o FXWorker.o \
	FXDCNativePrinter.o FXPostscriptFont.o termed.o bytes.o u01.o u02.o \
	u03.o u04.o u05.o u06.o u07.o u08.o u09.o u10.o u11.o u12.o \
	-lFOX-1.6 $LIBS 2>> /tmp/linker.log &&
   g++ -o slowr38   $FOXLIB $LDFLAGS arith01.o arith02.o \
	arith03.o arith04.o arith05.o arith06.o arith07.o arith08.o arith09.o \
	arith10.o arith11.o arith12.o char.o csl.o cslmpi.o eval1.o eval2.o \
	eval3.o eval4.o fasl.o fns1.o fns2.o fns3.o gc.o preserve.o print.o \
	cslread.o restart.o sysfwin.o fwin.o FXTerminal.o FXWorker.o \
	FXDCNativePrinter.o FXPostscriptFont.o termed.o bytes1.o stubs.o \
	-lFOX-1.6 $LIBS 2>> /tmp/linker.log &&
   gcc -o termdemo  $FOXLIB $LDFLAGS termdemo.o termed.o \
	-lFOX-1.6 $LIBS 2>> /tmp/linker.log; then 
      echo "Relinking complete"
      echo "used LDFLAGS=$FOXLIB $LDFLAGS"
      echo "used LIBS=$LIBS"
      exit 0
      fi

done
done
done
done
done
done
done

echo "Linking failed! You will need to find a set of libraries by hand"

exit 1

