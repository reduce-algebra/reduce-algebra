#! /bin/sh

MYDIR=`dirname $0`
CSLBUILDDIR=`realpath $MYDIR/../lib/reduce/cslbuild`
exec $CSLBUILDDIR/csl/reduce $*

