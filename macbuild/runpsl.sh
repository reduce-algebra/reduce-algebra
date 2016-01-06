#! /bin/sh

# This is used to try to run the PSL version of Reduce given that
# this script is placed wheer there are sub-directories called psl
# and red that contain the relevant binaries.

# First find the directory that this script lives in.
here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`cd \`dirname "$here"\` ; pwd -P`

# All 1 Gbyte of heap.
STORE=1000
bin="$here/psl/bpsl"
export fasl="$here/red"
exec $bin -td $STORE -f $here/red/reduce.img $*
