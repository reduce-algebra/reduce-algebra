#! /bin/sh

# package --- Recompile just one package of REDUCE

# Author: Arthur C Norman

# This script may be passed a directory as arg1, but if not it expects
# to find my source files in "../cslbase"

if test -n "$1"
then srcdir="$1"
else srcdir=../cslbase
fi

./r38 -Dno_init_file -Dtarget=$1 $srcdir/../util/package.red -D@srcdir=$srcdir -- log/$1.log


