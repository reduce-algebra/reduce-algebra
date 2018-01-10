#! /bin/bash -v

# First I will build the PSL cross compiler...

make clean
make psl OPT="-O0 -g"
script -c "./vsl psl-compiler.lsp -opslcomp.img" psl-compiler.log

export PXX=../psl/dist/kernel/AMD64_ext

export MACHINE=AMD64_ext

export PXK=../psl/dist/kernel/AMD64_ext
export PK=../psl/dist/kernel
export USERSLFILES=""

export SLFILES="\
        $PXK/main-start.sl \
        $PXK/io.sl \
        $PXK/intern.sl \
        $PXK/faslin.sl \
        $PXK/alloc.sl \
        $PK/support.sl \
        $PXK/sys-support.sl \
        $PXK/externals.sl \
        $PXK/pthread.sl \
        $PXK/dl-support.sl \
        $USERSLFILES"

# First make main.s
rm -f $MACHINE.sym

export PC=../psl/dist/comp

cp $PC/bare-psl.sym $MACHINE.sym

cat >tmp.sl <<EOF
(setq *echo t)
(off usermode)
(off immediatequote)

(put 'intern 'lose t)

% I THINK that this is only called for on 32-bit targets? And anyway this
% looks like a hacked up patch.
(when (getd 'bitmask)
  (copyd 'bitma 'bitmask)
  (de bitmask (x y) (cond ((and (eq x 2) (eq y 30))  16#3fffffff)
                          ((and (eq x 2) (eq y 14))  16#3fff0000)
                          (t (bitma x y)))))

(setf *writingasmfile t)

(off pcmac)
(off usermode)
(on verboseload)
(asmout "main")
(dskin "$PK/firstkernel.sl")

EOF

printf "(dskin \"%s\")\n" $SLFILES >> tmp.sl

cat >>tmp.sl <<EOF

(dskin "$PK/lastkernel.sl")
(asmend)
(exitlisp)
EOF

# The idea of the \$DEBUG here is that one can set the shell variable
# using "export DEBUG='cgdb --args'" so as to run vsl under a debugger.
script -c "$DEBUG ./vsl -ipslcomp.img tmp.sl" makemain.log

# compile it to make main.o

# A MISERY here is that the option "sed -i" is not supported in
# a consistent way as between Linux and MacOS. So to keep to POSIX
# portability I avoid that nice option.

sed -f $PXK/main.linux.sed main.s > main.s.temp
mv main.s.temp main.s

gcc -c main.s -o main.o

# compile the data part to make dmain.o

sed -f $PXK/dmain.linux.sed dmain.s > dmain.s.temp
mv dmain.s.temp dmain.s

gcc -c dmain.s -o dmain.o

# Finally I can compile the C-coded support and link stuff together to make
# a bpsl executable.

gcc -o bpsl \
    -DBPSSIZE=20500000 -pthread -w \
    -DLINUX \
     $PXX/bps.c \
     $PXX/bpsheap.c \
     $PXX/echo.c \
     $PXX/file-status.c \
     $PXX/float.c \
     $PXX/os-hooks.c \
     $PXX/pslextras.c \
     $PXX/pslsocket.c \
     $PXX/pwd-fn.c \
     $PXX/sigs.c \
     $PXX/unix-io.c \
     $PXX/creloc.c \
     $PXX/formlink2.c \
     main.o dmain.o -lm -ldl


