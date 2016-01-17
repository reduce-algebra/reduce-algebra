#! /bin/sh
# This is used to run the PSL version of Reduce given that
# this script is placed where there are sub-directories called psl
# and red that contain the relevant binaries.
here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`cd \`dirname "$here"\` ; pwd -P`
# For Maintosh we are always 64-bit so this amount of store makes sense
STORE=1000
export fasl="$here/red"
exec "$here/psl/bpsl" -td $STORE -f "$here/red/reduce.img" $*
