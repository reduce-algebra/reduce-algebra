#! /bin/sh

# Reset all entries in the "bin" directory to a generic state

here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`cd \`dirname "$here"\` ; pwd`

#rm -rf $here/../bin/*
cp $here/README-BIN $here/../bin/README

$here/reset.sh csl
$here/reset.sh redcsl
$here/reset.sh redpsl
$here/reset.sh fwindemo
$here/reset.sh fontdemo
$here/reset.sh showmathdemo
$here/reset.sh bootstrapreduce

# This last one will be removed soon... at present it is like redcsl.
$here/reset.sh reduce

# end of script
