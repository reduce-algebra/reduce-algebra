#! /bin/sh

# Look for name-clashes in REDUCE

# This script may be passed a directory as arg1, but if not it expects
# to find my source files in "../cslbase"

if test -n "$1"
then srcdir="$1"
else srcdir=../cslbase
fi

./slowr38 -v -Dno_init_file $srcdir/../util/clash.red -D@srcdir=$srcdir -- log/clash.log


