#! /bin/bash -v

# Uses existing main.s and dmain.s that may have been hand edited.


gcc -c -ggdb main.s
gcc -c -ggdb dmain.s

rm -f bpsl

gcc -ggdb -O0 \
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
   main.o \
   dmain.o \
   -lm  -ldl -lpthread \
   -o bpsl


./bpsl -td 1000 <<EOF
(setq loaddirectories* '("" "fasl"))
(on verboseload)
(load init-file)
(load debug useful common)
(load numeric-ops)
(savesystem "New PSL" "psl" nil)
(exitlisp)
EOF
