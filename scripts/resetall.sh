#! /bin/sh

# Reset all entries in the "bin" directory to a generic state

a=$0
c=unknown
case $a in
/* )
  c=$a  
  ;;
*/* )
  case $a in
  ./* )
    a=${a#./}
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

here=${c%/*}


rm -rf $here/../bin/*

$here/reset.sh csl
$here/reset.sh reduce
$here/reset.sh fwindemo
$here/reset.sh fontdemo
$here/reset.sh showmathdemo
$here/reset.sh bootstrapreduce

# end of script
