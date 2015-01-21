#! /bin/sh
here=`dirname "$0"`
here=`cd "$here" ; pwd`

for x in $here/../cslbuild/*/fox
do
  echo "Rebuild in $x"
  cd $x
  ./config.status --recheck
  ./config.status
  make `$here/scripts/joption.sh` install
  cd $here
done
