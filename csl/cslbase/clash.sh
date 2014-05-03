#! /bin/sh -v

# Look for name-clashes in REDUCE

# This script may be passed a directory as arg1, but if not it expects
# to find my source files in the current directory. Note that this is to be
# the CSL source directory as in ../trunk/csl/cslbase
#
# Furthermore it seems that this has to be run from within the directory where
# the bootstrapreduce.img file is. Since this is just a private utility I
# will not worry baout improving on that just at present.

if test -n "$1"
then srcdir="$1"
else srcdir=.
fi

$O/bin/bootstrapreduce -v -w -Dno_init_file $srcdir/clash.red \
	-D@srcdir=$srcdir -l clash.log


