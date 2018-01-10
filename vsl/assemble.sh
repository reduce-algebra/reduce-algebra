#! /bin/bash -v

# Here I will use the pre-built assembly code for the target
# identified in PXX, but my own single version of the C code
# now held in the directory K (aka kernel).

PXX=../psl/dist/kernel/AMD64_ext

K=kernel

printf "Use ${CC:-gcc} as the C compiler\n"

${CC:-gcc} -Wall \
    -O3 \
    -pthread \
    -DBPSSIZE=20500000 \
    -DLINUX \
     $K/bpsheap.c \
     $K/echo.c \
     $K/file-status.c \
     $K/float.c \
     $K/os-hooks.c \
     $K/pslextras.c \
     $K/pslsocket.c \
     $K/pwd-fn.c \
     $K/sigs.c \
     $K/unix-io.c \
     $K/creloc.c \
     $K/formlink2.c \
     $K/sysdep.c \
     $PXX/main.s \
     $K/bps.c \
     $PXX/dmain.s \
     -lm -ldl -lpthread \
    -o bpsl

