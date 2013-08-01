#!/bin/bash

if test $# = 1; then
    p=$(basename "$1" .tst)
else
    echo "rltest-install.sh package"
    exit 1
fi

# I want this script to be one I can launch from anywhere, so
# to access files etc I need to know where it lives.

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

here=`echo $c | sed -e 's+/[^/]*$++'`
here=`echo $here | sed -e 's+/[^/]*$++'`
here=`echo $here | sed -e 's+/[^/]*$++'`

regdir=$here/packages/redlog/regressions

tmpdir="/tmp/rltest-install-$RANDOM"

mkdir $tmpdir
cd $tmpdir

$here/generic/redlogtest/rltest1.sh $p

cat csl-times/$p.rlg csl-times/$p.time > $regdir/$p.rlg
cp csl-times/$p.time $regdir/$p.csltime
cp psl-times/$p.time $regdir/$p.psltime

rm -rf "$tmpdir"
