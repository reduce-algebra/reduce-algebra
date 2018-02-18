#! /bin/bash -v

K=kernel

gcc -c main.s
gcc -c dmain.s

cc  -m64 -o bpsl -DBPSSIZE=20500000 \
   $K/bps.c \
   $K/bpsheap.c \
   $K/echo.c \
   $K/file-status.c \
   float.c \
   $K/os-hooks.c \
   $K/pslextras.c \
   pslsocket.c \
   $K/pwd-fn.c \
   $K/sigs.c \
   $K/unix-io.c \
   $K/creloc.c \
   $K/formlink2.c \
   -DLINUX main.o dmain.o -lm  -ldl -lpthread

