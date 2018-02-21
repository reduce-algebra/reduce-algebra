#! /bin/bash -v

# Uses existing main.s and dmain.s that may have been hand edited.


gcc -c main.s
gcc -c dmain.s

rm -f bpsl

gcc ${PIE:--no-pie} -o bpsl -DBPSSIZE=20500000 \
   ../psl/dist/kernel/AMD64_ext/bps.c \
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
   -DLINUX main.o dmain.o -lm  -ldl -lpthread


./bpsl
