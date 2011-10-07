#! /bin/sh

case `uname -p` in
i*)
      STORE=16000000
      ;;
x86_64)
      STORE=1000
      ;;
esac

bin="$TOPDIR/usr/lib/reduce/pslbuild/psl/bpsl"
img="$TOPDIR/usr/lib/reduce/pslbuild/red/reduce.img"

exec $bin -td $STORE -f $img $*
exit 0

