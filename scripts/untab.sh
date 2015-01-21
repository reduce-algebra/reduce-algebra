#! /bin/sh

# Expand tabs in all REDUCE source files

here=`dirname "$0"`
here=`cd "$here" ; pwd`

cd $here

gcc untab.c -o untab

cd ../packages

for x in `find . -name \*.red`
do
  echo expand any tabs in $x
  ../scripts/untab $x
done

cd $here
rm -f untab
