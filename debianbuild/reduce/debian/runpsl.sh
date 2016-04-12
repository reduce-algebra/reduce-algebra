#! /bin/sh

case `uname -m` in
i*)
      STORE=16000000
      ;;
x86_64)
      STORE=1000
      ;;
esac

MYDIR=`dirname $0`
PSLBUILDDIR=`readlink -m $MYDIR/../lib/reduce/pslbuild`
bin="$PSLBUILDDIR/psl/bpsl"
img="$PSLBUILDDIR/red/reduce.img"

exec $bin -td $STORE -f $img $*

