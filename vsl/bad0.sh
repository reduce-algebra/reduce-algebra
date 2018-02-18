#! /bin/bash -v

# This version used just the original symval+NNN everywhere.

cp ../psl/dist/kernel/AMD64_ext/main.s main.s
cp ../psl/dist/kernel/AMD64_ext/dmain.s dmain.s

head -15 main.s

gcc -c main.s
gcc -c dmain.s

diff float.c ../psl/dist/kernel/AMD64_ext
diff pslsocket.c ../psl/dist/kernel/AMD64_ext

rm -f bpsl

gcc -no-pie -o bpsl -DBPSSIZE=20500000 \
   ../psl/dist/kernel/AMD64_ext/bps.c \
   ../psl/dist/kernel/AMD64_ext/bpsheap.c \
   ../psl/dist/kernel/AMD64_ext/echo.c \
   ../psl/dist/kernel/AMD64_ext/file-status.c \
   float.c \
   ../psl/dist/kernel/AMD64_ext/os-hooks.c \
   ../psl/dist/kernel/AMD64_ext/pslextras.c \
   pslsocket.c \
   ../psl/dist/kernel/AMD64_ext/pwd-fn.c \
   ../psl/dist/kernel/AMD64_ext/sigs.c \
   ../psl/dist/kernel/AMD64_ext/unix-io.c \
   ../psl/dist/kernel/AMD64_ext/creloc.c \
   ../psl/dist/kernel/AMD64_ext/formlink2.c \
   -DLINUX main.o dmain.o -lm  -ldl -lpthread


./bpsl