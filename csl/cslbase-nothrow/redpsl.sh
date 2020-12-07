#! /bin/bash
here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`dirname "$here"`
here=`cd "$here"; pwd -P`
here=`cygpath -m "$here"`
case `uname -m` in
i686)
  exec $here/psl32/psl/bpsl -td 16000000 -f $here/psl32/red/reduce.img $*
  ;;
*)
  exec $here/psl64/psl/bpsl -td 1000 -f $here/psl64/red/reduce.img $*
  ;;
esac
