#! /bin/sh
# makeall

# re-builds absolutely everything, inclusing doing a re-profile
# of REDUCE to select what should be compiled into C. This should only
# be required after MAJOR changes in the source.

# Note that you will need to have made a suitable Makefile available,
# eg by going something like
#    ln -s ../util/Makefile.xxx Makefile
# for xxx matching the computer you are using.

# This script may be passed a directory as arg1, but if not it expects
# to find my source files in "../cslbase"

if test -n "$1"
then srcdir="$1"
else srcdir=../cslbase
fi


make slowr38
$srcdir/../util/boot38.sh $srcdir
$srcdir/../util/profile.sh $srcdir
cp profile.dat $srcdir/../csl-c
rm profile.dat
$srcdir/../util/c-code38.sh $srcdir
make r38

# the bits from here down are cheaper and are all that is usually needed
$srcdir/../util/full38.sh $srcdir

$srcdir/../util/testall.sh $srcdir
$srcdir/../util/checkall.sh $srcdir

# log/checkall.log and log/times.log should now be up to date.


