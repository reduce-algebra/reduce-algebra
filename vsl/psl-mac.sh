#! /bin/bash -v


gcc -c -g main.s
gcc -c -g dmain.s

rm -f bpsl

# The Macintosh compiler is very noisy in its complaints about uses of
# deprecated functions - in this case sbrk. So at least for a while I
# will set a compiler flag to stop it from bothering me about things that
# amd well aware of.

gcc -g -O0 \
   -DMACINTOSH \
   -Wno-deprecated-declarations \
   -DBPSSIZE=20500000 \
   bps.c \
   bpsheap.c \
   echo.c \
   file-status.c \
   float.c \
   os-hooks.c \
   pslextras.c \
   pslsocket.c \
   pwd-fn.c \
   sigs.c \
   unix-io.c \
   creloc.c \
   formlink2.c \
   pslstubs.c \
   main.o \
   dmain.o \
   -lm  -ldl -lpthread \
   -o bpsl


./try-bpsl.sh

# end of script

