#! /bin/bash -v

# Here I will use the pre-built assembly code for the target
# identified in PXX, but my own single version of the C code
# now held in the directory K (aka kernel).

PXX=../psl/dist/kernel/AMD64_ext

K=kernel

printf "Use ${CC:-gcc} as the C compiler\n"

${CC:-gcc} -Wall \
    -Wl,--disable-large-address-aware \
    -O3 \
    -pthread \
    -DBPSSIZE=20500000 \
    -DLINUX \
     showaddr.c \
     main.s \
     $K/bps.c \
     dmain.s \
     -lm -ldl -lpthread \
    -o showaddr

