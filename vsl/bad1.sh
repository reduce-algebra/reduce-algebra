#! /bin/bash -v

# This version used symval+NNN(%rip) everywhere. If this is what is wanted
# I obviously hope tha the compiler that generates mai.s will stick the
# extra annotation in there!


sed 's/symval+[0-9]*/&(%rip)/g; s/symfnc+[0-9]*/&(%rip)/g; s/mov l[0-9]*/&(%rip)/g; s/cmp l[0-9]*/&(%rip)/g' < ../psl/dist/kernel/AMD64_ext/main.s  > main.s
cp ../psl/dist/kernel/AMD64_ext/dmain.s dmain.s

gcc -c main.s
gcc -c dmain.s

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
   pslstubs.c \
   -DLINUX main.o dmain.o -lm  -ldl -lpthread


./bpsl
