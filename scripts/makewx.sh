#! /bin/sh
a=$0
c=unknown
case $a in
/* )
  c=$a  
  ;;
*/* )
  case $a in
  ./* )
    a=`echo $a | sed -e s+./++`
    ;;
  esac
  c=`pwd`/$a
  ;;
* ) 
  for d in $PATH
  do
    if test -x $d/$a
    then
      c=$d/$a
    fi
  done
  if test $c = "unknown" ;then
    echo "Unable to find full path for script. Please re-try"
    echo "launching it using a fully rooted path."
    exit 1
  fi
  ;;
esac
while test -h "$c"; do
  lt=`ls -l "$c" | sed 's/.*->[ ][ ]*//'`
  if echo "$lt" | grep -q '^/'; then
    c="$lt"
  else
    dir=`dirname "$c"`
    c="$dir/$lt"
  fi
done
here=`echo $c | sed -e 's+/[^/]*$++;s+/[^/]*$++'`

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
  cd $here
done
