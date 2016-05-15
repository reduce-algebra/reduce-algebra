#! /bin/sh
here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`cd \`dirname "$here"\` ; pwd -P`
export reduce="$here/.."
"$reduce/lib/psl/psl/bpsl.exe" -td 1000 -f "$reduce/lib/psl/red/reduce.img" $*
