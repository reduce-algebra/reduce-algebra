#! /bin/sh
here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`cd \`dirname "$here"\` ; pwd -P`
export reduce="$here/.."
"$reduce/lib/csl/reduce.exe" $*
