#! /bin/sh
# This is used to run the CSL version of Reduce given that
# this script is placed adjacent to the reduce.app bundle.
here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`cd \`dirname "$here"\` ; pwd -P`
exec "$here/reduce.app/Contents/MacOS/reduce" $*
