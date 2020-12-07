#! /bin/sh

# check the log files for all modules

# main log files go in $srcdir/../../../log/*.rlg,
# reference ones are in $srcdir/../../../packages/XXX/XXX.rlg

# This script may be passed a directory as arg1, but if not it expects
# to find my source files in "../cslbase"

if test -n "$1"
then srcdir="$1"
else srcdir=../cslbase
fi

./r38 -Dno_init_file $srcdir/../util/checkall.red -D@srcdir=$srcdir -Dwhich_module=$2 -- log/checkall.log


