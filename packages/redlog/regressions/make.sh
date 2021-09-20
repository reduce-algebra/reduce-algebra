#!/usr/bin/env bash

shopt -s globstar nullglob

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
here=`echo $here | sed -e 's+/[^/]*$++'`

if [ $# -eq 1 -a "$1" == "-n" ]; then
  dryrun=1
  shift
else
  dryrun=0
fi

if [ $# -ne 0 ]; then
  echo "usage: $0 [-n]" > /dev/stderr
  exit 1
fi

newrlg=""

for p in **/*.tst; do
  base=$(dirname $p)/$(basename $p .tst)
  rlg=$base.rlg
  csltime=$base.csltime
  psltime=$base.psltime
  if [ ! -f "$rlg" -o ! -f "$csltime" -o ! -f "$psltime" ]; then
    echo -n "$base: installing ... "
    if [ $dryrun -eq 0 ]; then
      hide=$RANDOM
      mv -f $here/scripts/pslmem64.sh $here/scripts/pslmem64.sh-$hide
      cp $here/generic/redlogtest/pslmem64.sh $here/scripts
      $here/generic/redlogtest/rltest-install.sh  $base &> /dev/null
      mv -f $here/scripts/pslmem64.sh-$hide $here/scripts/pslmem64.sh
    fi
    echo "done"
    newrlg="$newrlg $rlg"
  else
    echo "$rlg: ok"
  fi
done

if [ "$newrlg" != "" ]; then
  echo "Please, check the content of the following newly installed files: $newrlg"
fi
