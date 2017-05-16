#! /bin/sh
# This is used to run the CSL version of BootstrapReduce given that
# this script is placed adjacent to the bootstrapreduce.app bundle.
here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`cd \`dirname "$here"\` ; pwd -P`
exec "$here/bootstrapreduce.app/Contents/MacOS/bootstrapreduce" $*
