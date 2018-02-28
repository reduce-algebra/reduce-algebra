#! /bin/bash -v

# For Cygwin I must use the Windows version of main.s and dmain.s because
# Cygwin uses the Microsoft register and calling conventions.

rm -f bpsl

gcc -ggdb -O0 \
   -Wa,--defsym,__CYGWIN__=1 \
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
   win-main.s \
   win-dmain.s \
   acn.s \
   acn1.c \
   -lm  -ldl -lpthread \
   -o bpsl


./try-bpsl.sh

# end of script
