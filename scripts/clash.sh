#! /bin/sh -v

# I want this script to be one I can launch from anywhere, so
# to access files etc I need to know where it lives.

here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`dirname "$here"`
here=`cd "$here"; pwd -P`
here=`dirname "$here"`


# Look for name-clashes in REDUCE

# Please ensure that bootstrapreduce is fully up to date before running
# this, e.g. by going "make bootstrapreduce.img" from the trunk directory.

$here/bin/bootstrapreduce -I- -v -w -Dno_init_file $here/scripts/clash.red \
	-D@srcdir=$here -l clash.log


