#! /bin/sh

# profile all modules

# results go to "profile.dat"

# Note: on a 400 MHz Pentium II this uses around 1 hour of CPU time.
#       and on faster machines MUCH less!

# This script may be passed a directory as arg1, but if not it expects
# to find my source files in "../cslbase"

if test -n "$1"
then srcdir="$1"
else srcdir=../cslbase
fi

rm profile.dat

./slowr38 -v -i slowr38.img -Dno_init_file $srcdir/../util/profile.red -D@srcdir=$srcdir -- log/profile.log


