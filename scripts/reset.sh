#! /bin/sh

# Reset a file in "bin" to its generic state

if test "x$1" = "x"
then
   echo "Usage: scripts/reset.sh appname"
   echo "resets that application to a generic state"
   exit 1
fi

# I want this script to be one I can launch from anywhere, but at least
# some of its sub-scripts will not be so generous. So find out where it
# lives so that other locations can be found relative to that.

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

mkdir -p $here/../bin

rm -f $here/../bin/$1
cp $here/here0.sh $here/../bin/$1

echo "exec \$here/../scripts/run.sh $1 \$*" >> $here/../bin/$1

chmod +x $here/../bin/$1

case $1 in
redpsl)
  rm -f $here/../bin/redpsl.bat $here/../bin/redpslw.bat
  cp $here/redpsl.bat $here/../bin
  cp $here/redpslw.bat $here/../bin
  ;;
redcsl)
  rm -f $here/../bin/redcsl.bat
  cp $here/redcsl.bat $here/../bin
  ;;
*)
  rm -f $here/../bin/$1.bat
  cp $here/run.bat $here/../bin/$1.bat
  ;;
esac

exit 0

