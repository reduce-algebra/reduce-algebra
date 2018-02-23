#! /bin/bash -v

# Uses existing main.s and dmain.s that may have been hand edited.


x86_64-w64-mingw32-gcc -c -g main.s
x86_64-w64-mingw32-gcc -c -g dmain.s

rm -f bpsl

x86_64-w64-mingw32-gcc -g -O1 \
   -DWINDOWS \
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


./bpsl
