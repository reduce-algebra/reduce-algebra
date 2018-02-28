#! /bin/bash -v


rm -f bpsl

x86_64-w64-mingw32-gcc -ggdb -O0 \
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
   win-main.s \
   win-dmain.s \
   -lm  -ldl -lpthread \
   -o bpsl


./try-bpsl.sh

# end of script
