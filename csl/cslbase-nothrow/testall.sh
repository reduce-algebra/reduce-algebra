#! /bin/sh

# test all modules whose logs are not already up to date

# main log files go in $srcdir/../../../log/*.rlg

# This script may be passed a directory as arg1, but if not it expects
# to find my source files in "../cslbase"

if test -n "$1"
then srcdir="$1"
else srcdir=../cslbase
fi

./r38 -v $srcdir/../util/testall.red -Dno_init_file -D@srcdir=$srcdir -Dwhich_module=$2 -- log/testall.log


