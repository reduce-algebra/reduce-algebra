#! /bin/sh

# test all modules but using the bootstrap (slow) version of REDUCE

# main log files go in $srcdir/../../../log/*.rlg

# This script may be passed a directory as arg1, but if not it expects
# to find my source files in "../cslbase"

if test -n "$1"
then srcdir="$1"
else srcdir=../cslbase
fi

./slowr38 -v $srcdir/../util/testall.red -Dno_init_file -D@srcdir=$srcdir -Dwhich_module=$2 -- log/testslow.log


