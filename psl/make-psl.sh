#! /bin/sh 
#   Makes PSL in the reduce-algebra tree
#   uses config-guess   and the position in the file tree (PROOT)
#   the MACHINE variable ist set according to the old PSL
#   names derived fron the config-guess.

export PROOT=`pwd`

guess=`../config.guess`


case "guess:$guess" in

  guess:x86_64-unknown-linux-gnu )
        MACHINE=AMD64
        ;;

  guess:i686-pc-linux-gnu )
	MACHINE=linux
	;;

  guess:i386-apple-darwin10.4.0 )
	MACHINE=macintel
	;;

  guess:x86_64-apple-darwin10.4.0 | guess:x86_64-apple-darwin10.5.0 )
	MACHINE=macintel64
	;;

  x86_64-unknown-freebsd8.* )
	MACHINE=freeBSD64
	;;

  i386-unknown-freebsd8.* )
	MACHINE=freeBSD
	;;

esac

export MACHINE

pdist=$PROOT/dist/distrib

if test "$1" != ""
   then
        export MACHINE=$1
fi

sed -e "s,\(export.*proot\)=.*,\1=$PROOT," $PROOT/dist/psl-names.bash > newnames
mv -f newnames $PROOT/dist/psl-names.bash

. $PROOT/dist/psl-names.bash

echo "make for PSL in "$PROOT/dist " for MACHINE " $MACHINE
echo "please add " $PROOT/bin/$MACHINE " to your PATH "

export psys=$PROOT/bin/$MACHINE
export pxk=$PROOT/dist/kernel/$MACHINE
export pl=$PROOT/dist/lap/$MACHINE
export pnkl=$PROOT/dist/nonkernel/$MACHINE/lap
export pll=$PROOT/dist/local/$MACHINE/lap

cd dist
# we have to make sure that bpsl is healthy and compatible with the
# operating system. So we better rebuild it.
cd $pxk
###gzip -f bpsl
###./asm
###./cclnk             
# can't say make already, because we may not have a pslcomp. Sigh
$pdist/make-bare-psl
$pdist/make-pslcomp
cd $pdist/..
make

