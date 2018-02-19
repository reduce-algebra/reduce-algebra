#! /bin/bash -v

# Assumes main.s and dmain.s have already been assembled.

rm -f bpsl

gcc ${PIE:--no-pie} -o bpsl -DBPSSIZE=20500000 \
   ../psl/dist/kernel/AMD64_ext/bps.c \
   ../psl/dist/kernel/AMD64_ext/bpsheap.c \
   ../psl/dist/kernel/AMD64_ext/echo.c \
   ../psl/dist/kernel/AMD64_ext/file-status.c \
   float.c \
   ../psl/dist/kernel/AMD64_ext/os-hooks.c \
   pslextras.c \
   pslsocket.c \
   ../psl/dist/kernel/AMD64_ext/pwd-fn.c \
   ../psl/dist/kernel/AMD64_ext/sigs.c \
   ../psl/dist/kernel/AMD64_ext/unix-io.c \
   ../psl/dist/kernel/AMD64_ext/creloc.c \
   ../psl/dist/kernel/AMD64_ext/formlink2.c \
   pslstubs.o \
   -DLINUX main.o dmain.o -lm  -ldl -lpthread


./bpsl
