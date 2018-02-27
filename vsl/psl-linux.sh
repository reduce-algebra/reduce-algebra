#! /bin/bash -v

# Uses existing main.s and dmain.s that may have been hand edited.


gcc -c -Wall -ggdb main.s
gcc -c -Wall -ggdb dmain.s

rm -f bpsl

gcc -ggdb -O0 \
   -Wall \
   -DLINUX \
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
   acn.s \
   acn1.c \
   -lm  -ldl -lpthread \
   -o bpsl


./try-bpsl.sh

# end of script
