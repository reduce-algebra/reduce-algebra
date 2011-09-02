#! /bin/sh

# boot38 --- Build REDUCE 3.8 under Linux/Unix etc using CSL.

# Author: Arthur C Norman

# This takes around 4 minutes on a P6-400 or 30 secs on an Athlon64 3200+

# This script may be passed a directory as arg1, but if not it expects
# to find my source files in "../cslbase"

if test -n "$1"
then srcdir="$1"
else srcdir=../cslbase
fi

unset reduce

./slowr38 -w -z -g -Dno_init_file $srcdir/../util/build38.lsp -D@srcdir=$srcdir -- log/boot38.log

# end of script
