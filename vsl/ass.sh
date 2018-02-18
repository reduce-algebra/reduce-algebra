#! /bin/bash -v

# Here I will use the pre-built assembly code for the target
# identified in PXX, but my own single version of the C code
# now held in the directory K (aka kernel).

PXX=../psl/dist/kernel/AMD64_ext

K=kernel

printf "Use ${CC:-gcc} as the C compiler\n"

as main.s
as dmain.s

${CC:-gcc} -Wall \
    -O3 \
    -DBPSSIZE=20500000 \
    -DLINUX \
     showaddr.c \
     main.o \
     $K/bps.c \
     dmain.o \
    -o showaddr

