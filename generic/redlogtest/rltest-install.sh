#!/bin/bash

if test $# = 1; then
    d=$(dirname $1)
    p=$(basename "$1" .tst)
else
    echo "rltest-install.sh regressions test"
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

regressions=$here/packages/redlog/regressions

tmpdir="/tmp/rltest-install-$RANDOM"
timings=$tmpdir/timings

mkdir $tmpdir
cd $tmpdir
ln -s $here .

$here/generic/redlogtest/rltest1.sh $tmpdir "" $d/$p

cat $timings/csl-times/$d/$p.rlg $timings/csl-times/$d/$p.time > $regressions/$d/$p.rlg
cp $timings/csl-times/$d/$p.time $regressions/$d/$p.csltime
cp $timings/psl-times/$d/$p.time $regressions/$d/$p.psltime

rm -rf "$tmpdir"
