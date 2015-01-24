#! /bin/sh

# I want this script to be one I can launch from anywhere, but at least
# some of its sub-scripts will not be so generous. So find out where it
# lives so that other locations can be found relative to that.
here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`cd \`dirname "$here"\` ; pwd -P`
echo `dirname "$here"`

# Unpack a new version of wxWidgets

cd $here/csl/support-packages
a=`echo wxWidgets-v*.tar.bz2`
a=${a##* }
b=${a%.tar.bz2}
cd ..
rm -rf wxWidgets
echo About to unpack wxWidgets from $a
tar xfj support-packages/$a
chmod -R +rw $b
mv $b wxWidgets
echo wxWidgets unpacked from archive $a
cd $here

# Rebuild all currently configured versions that use wxWidgets

for x in $here/cslbuild/*/wxWidgets
do
  echo "Rebuild in $x"
  cd $x
  rm -rf ../bin ../include ../lib ../share
  ./config.status --recheck
  ./config.status
  make `$here/scripts/joption.sh` install
done
