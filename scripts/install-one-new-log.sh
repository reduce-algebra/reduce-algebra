#! /bin/bash

# Update a single log file


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


p=${1:-alg}

w=`grep " test " $here/packages/package.map | grep "($p "`

case $w in
*$p*)
  d=${w%\"*}
  d=${d#*\"}
  ;;
*)
  echo "Package $p not identified in packages/package.map"
  echo "Assuming it to be a regression test"
  d="regressions"
  ;;
esac


echo "Install $p.rlg as packages/$d/$p.rlg"

cp $1.rlg $here/packages/$d/$p.rlg
if test -f $1.time
then
  cat $1.time >> $here/packages/$d/$p.rlg
fi

# end of test



