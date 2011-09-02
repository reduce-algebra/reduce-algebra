#! /bin/sh
# full38 --- Build REDUCE 3.8 under Windows using CSL.

# Author: Arthur C Norman

# This script may be passed a directory as arg1, but if not it expects
# to find my source files in "../cslbase"

if test -n "$1"
then srcdir="$1"
else srcdir=../cslbase
fi

unset reduce

./r38 -w -z -Dno_init_file $srcdir/../util/build38.lsp -D@srcdir=$srcdir -- log/full38.log


