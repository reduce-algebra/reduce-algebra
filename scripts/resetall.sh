#! /bin/sh

# Reset all entries in the "bin" directory to a generic state

here=`dirname "$0"`
here=`cd "$here" ; pwd`

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
