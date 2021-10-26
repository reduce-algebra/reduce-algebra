#! /bin/sh

# This script can be run to re-create several things:
#
#    extras.lsp, compiler.lsp, ccomp.lsp
#         these are made from the corresponding .red files
#
#    c-headers.lsp
#         made from c-headers.h (and hence a variety of other
#         header files)
#
# It is NOT expected that the general public ever need to use this script,
# in that the files that it generates are included in this directory
# and distributed. Hence I will not worry overmuch about portability...
# I will suppose I build on a system that has gcc. But the steps are simple
# enough that they can be done by hand if you need...

if which bison 2> /dev/null; then 
Y=bison
else
if which byacc 2> /dev/null; then
Y=byacc
else
echo "Neither bison nor byacc found"
exit 1
fi
fi

# These dats bison tends to tell me to specify -Wcounterexamples so that it
# can explain conflicts to me. Well I know about the traditional
# "if A then if B then C else D" ambiguity (the "dangling else") so I do
# not need verbose illustrations of if. The option might be really useful
# while developing a grammar, but I have been using this one for some
# years now...
$Y -o r2l.c r2l.y

gcc r2l.c -o r2l

./r2l -rights extras.red extras.lsp
./r2l -rights compiler.red compiler.lsp

# rm -f r2l r2l.exe r2l.c

echo "done"
