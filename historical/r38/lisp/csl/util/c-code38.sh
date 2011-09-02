#! /bin/sh

# c-code38.   generate C code... optionally limit number of fns to compile.

# This script may be passed a directory as arg1, but if not it expects
# to find my source files in "../cslbase"

if test -n "$1"
then srcdir="$1"
else srcdir=../cslbase
fi

./slowr38 -w -Dno_init_file $srcdir/../util/c-code38.red -D@srcdir=$srcdir -Dhow_many=$1 -- log/c-code38.log


