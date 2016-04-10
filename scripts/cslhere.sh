#! /bin/sh
# I want this script to be one I can launch from anywhere, but it
# needs to know where it lives so it can chain down to a file that is
# at a location relative to it.
here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`cd \`dirname "$here"\` ; pwd -P`
exec $here/csl/reduce $*
