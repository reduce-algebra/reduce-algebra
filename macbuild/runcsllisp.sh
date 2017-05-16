#! /bin/sh
# This is used to run the CSL lisp system given that
# this script is placed adjacent to the csl.app bundle.
here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`cd \`dirname "$here"\` ; pwd -P`
exec "$here/csl.app/Contents/MacOS/csl" $*
