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

rm -rf $here/../bin/*
cp $here/README-BIN $here/../bin/README

$here/reset.sh csl
$here/reset.sh redcsl
$here/reset.sh redpsl
$here/reset.sh fwindemo
$here/reset.sh fontdemo
$here/reset.sh showmathdemo
$here/reset.sh bootstrapreduce

# This last one will be removed soon... at present it is like redcsl.
$here/reset.sh reduce


# end of script
