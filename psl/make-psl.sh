#! /bin/sh -x
#   Makes PSL in the reduce-algebra tree
#   uses config-guess   and the position in the file tree (PROOT)
#   the MACHINE variable ist set according to the old PSL
#   names derived fron the config-guess.

export PROOT=`pwd`

guess=`../config.guess`


if test $guess = "x86_64-unknown-linux-gnu"
 then
	export MACHINE=AMD64
fi

echo "make for PSL in "$PROOT/dist " for MACHINE " $MACHINE
echo "pleaase add " $PROOT/bin/$MACHINE " to your PATH "

psys=$PROOT/bin/$MACHINE
pxk=$PROOT/dist/kernel/$MACHINE
pl=$PROOT/dist/lap/$MACHINE
pnkl=$PROOT/dist/nonkernel/$MACHINE/lap

cd dist
make

