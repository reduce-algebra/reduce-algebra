#! /bin/sh
here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`dirname "$here"`
export reduce=`cygpath -a -m "$here/.."`
"$reduce/lib/csl/bootstrapreduce.exe" $*
