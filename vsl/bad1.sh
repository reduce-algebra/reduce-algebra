#! /bin/bash -v

# This version used symval+NNN(%rip) everywhere. If this is what is wanted
# I obviously hope tha the compiler that generates mai.s will stick the
# extra annotation in there!

# Let me comment on these edits. Well firstly if all these work out I
# hope that the compiler can be persuaded to generate the version that
# these turn stuff into!

# References to "symval+nnn" turn into "symval+nnn(%rip)" so as to use
# pc relative addressing and make the code relocatable.
# Ditto symfnc, and property list access would need the same if used.
#
# Comments are introduced by "#" not "/" which makes the code treat them
# as comments on both a PC and a Mac
#
# "cmp lnnn" which compares against a local location turns into
# "cmp lnnn(%rip)" to use pc-relative addressing.
#
# "cmp" turns into "cmpq" in a bunch of places where the Mac assembler
# failed to deduce the appropriate width of operand.
#
# ".quad [a+b]" turns into ".quad (a+b)" and friends again for pc/Mac
# compatibility.

sed -e 's/symval+[0-9]*/&(%rip)/g' \
    -e 's/symfnc+[0-9]*/&(%rip)/g' \
    -e 's/mov l[0-9]*/&(%rip)/g'   \
    -e 's+^/+#+g'                  \
    -e 's/cmp l[0-9]*/&(%rip)/g'   \
    -e 's/cmp \$/cmpq $/g'         \
    -e 's/\[/(/g'                  \
    -e 's/\]/)/g'                  \
    < ../psl/dist/kernel/AMD64_ext/main.s > main.s

# dmain.s is simpler and it is just the [] => () change that I need.

sed -e 's/\[/(/g'                  \
    -e 's/\]/)/g'                  \
    < ../psl/dist/kernel/AMD64_ext/dmain.s > dmain.s

case `uname` in
*Darwin*)
# On the Mac we find that names tends to need an explicit underscore, while
# on cygwin and Linmux they do not. There are two sorts of case. One is
# all the "call foo" instructions in main.s. I spot cases where the operand
# to call starts with a letter: internal calls are written with a "*"
# there.
  sed -e 's/call [a-z]/call _&/g; s/_call /_/g'      \
      -e 's/symval/_symval/g'                        \
      -e 's/psl_main/_psl_main/g'                    \
      -i bak main.s
# A modest number of symbols defined in dmain.s need underscores. I list
# them all explicitly.
  sed -e 's/bpslowerbound/_bpslowerbound/g'          \
      -e 's/hashtable/_hashtable/g'                  \
      -e 's/heaplast/_heaplast/g'                    \
      -e 's/heaplowerbound/_heaplowerbound/g'        \
      -e 's/heaptrapbound/_heaptrapbound/g'          \
      -e 's/heapupperbound/_heapupperbound/g'        \
      -e 's/lastbps/_lastbps/g'                      \
      -e 's/nextbps/_nextbps/g'                      \
      -e 's/old_heaplast/_oldheaplast/g'             \
      -e 's/old_heaplowerbound/_oldheaplowerbound/g' \
      -e 's/old_heaptrapbound/_oldheaptrapbound/g'   \
      -e 's/old_heapupperbound/_oldheapupperbound/g' \
      -e 's/symval/_symval/g'                        \
      -e 's/psl_main/_psl_main/g'                    \
      -i bak dmain.s
  ;;
esac

gcc -c main.s
gcc -c dmain.s

rm -f bpsl

gcc -o bpsl \
    -DLINUX -DBPSSIZE=20500000 \
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
    main.o dmain.o -lm -ldl -lpthread

ls -l bpsl

./bpsl
