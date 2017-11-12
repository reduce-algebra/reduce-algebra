#! /bin/bash

# This runs the type-analysis code in whatever state it is in....

# For now I need to access an image file created via "make noinlines.img"
# and I do not expect that to be generally present, so I will specify a
# directory where it has been created. This line will need to be adjusted
# by anybody else experimenting with the code here. At some later stage if
# this becomes stable or more generally useful I will try to integrate
# everything into the main tree in a smoother way.

BINDIR=$O/cslbuild/x*cyg*nogui*/csl

$BINDIR/bootstrapreduce -i $BINDIR/noinlines.img \
    -w -g types.red -l types.log

# end of types.sh
