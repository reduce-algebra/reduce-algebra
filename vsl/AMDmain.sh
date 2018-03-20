#! /bin/bash -v

# First I will build the PSL cross compiler...

./AMDasm.sh

# Now I use the cross-compiler to make the kernel of the kernel, ie
# the two files main.s and dmain.s. Those get assembled and linked with
# some fairly minimal C code to create a bpsl executable. To make that
# usable further parts of the kernel have to be compiled into FASL formed
# and passed through bpsl to create an initial image file.

# Here I specialise what I am doing to build JUST the AMD64_ext versions
# of main.s and dmain.s, but I believe that there is not a great deal of
# cause for these to differ from any other versions used on x86_64 targets
# (well the C-coded parts of the kernel can deal with the variations in
8 system support, and the stuff here can abstract over variety or encompass
# all possibilities). It is plausible that this will be pretty close to
# adequate for other 64-bit targets, and may not be too far from usable on
# 32-bit ones too.

export MACHINE=AMD64_ext

export PXK=../psl/dist/kernel/AMD64_ext
export PK=../psl/dist/kernel

cp $PC/bare-psl.sym $MACHINE.sym

cat >tmp.sl <<EOF

(setq *echo t)
(off usermode)
(off immediatequote)

(put 'intern 'lose t)

(setf *writingasmfile t)

(off pcmac)
(off usermode)
(on verboseload)
(asmout "main")

(dskin "$PK/firstkernel.sl")

(dskin "$PXK/main-start.sl")
(dskin "$PXK/io.sl")
(dskin "$PXK/intern.sl")
(dskin "$PXK/faslin.sl")
(dskin "$PXK/alloc.sl")
(dskin "$PK/support.sl")
(dskin "$PXK/sys-support.sl")
(dskin "$PXK/externals.sl")
(dskin "$PXK/pthread.sl")      % Will obviously not be very useful
                               % as such on Windows! But the general
                               % concept of threads and mutexes is still
                               % viable.
(dskin "$PXK/dl-support.sl")

(dskin "$PK/lastkernel.sl")

(asmend)
(exitlisp)

EOF

script -c "./vsl -i AMDasm.img tmp.sl" AMDmain.log

# end of script

