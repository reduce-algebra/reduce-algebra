#!/bin/bash

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

newrlg=""

for p in */*/*.tst; do
    base=$(dirname $p)/$(basename $p .tst)
    rlg=$base.rlg
    csltime=$base.csltime
    psltime=$base.psltime
    if [ "$rlg" -ot "$p" ] || [ "$csltime" -ot "$p" ] || [ "$psltime" -ot "$p" ]; then
	echo -n "$base: installing ... "
	$here/generic/redlogtest/rltest-install.sh  $base &> /dev/null
	echo "done"
	newrlg="$newrlg $rlg"
    else
	echo "$rlg: ok"
    fi
done

if [ "$newrlg" != "" ]; then
    echo "Please, check the content of the following newly installed files: $newrlg"
fi
