#! /bin/sh
here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`dirname "$here"`
export reduce=`cygpath -a -m "$here/.."`
"$reduce/lib/psl/psl/bpsl.exe" -td 16000000 -f "$reduce/lib/psl/red/reduce.img" $*
