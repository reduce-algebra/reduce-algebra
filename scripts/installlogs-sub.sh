#! /bin/sh

# Install a single log file with the ".new" suffix

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

echo Installing log $1 into $2

if test -f $here/../logs/$1.rlg
then
  cp $here/../logs/$1.rlg $here/../packages/$2/$1.rlg.new
else
  echo "File $here/../logs/$1.rlg does not exist"
  exit 1
fi

