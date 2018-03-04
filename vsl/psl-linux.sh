#! /bin/bash -v

rm -f bpsl

gcc -ggdb -O0 \
   -no-pie \
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
   linux-main.s \
   linux-dmain.s \
   acn.s \
   acn1.c \
   -lm  -ldl -lpthread \
   -o bpsl


./try-bpsl.sh

# end of script
