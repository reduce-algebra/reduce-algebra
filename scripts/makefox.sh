#! /bin/sh
# I want this script to be one I can launch from anywhere, but at least
# some of its sub-scripts will not be so generous. So find out where it
# lives so that other locations can be found relative to that.
here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`cd \`dirname "$here"\` ; pwd -P`
echo `dirname "$here"`

for x in $here/cslbuild/*/fox
do
  echo "Rebuild in $x"
  cd $x
  ./config.status --recheck
  ./config.status
  make `$here/scripts/joption.sh` install
done
