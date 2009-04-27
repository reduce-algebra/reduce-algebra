#! /bin/sh

# This is used to re-run autoconf, automake etc and then restart
# a call to "configure"

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

if ! $here/../autogen.sh
then
  echo "The autoconf/automake/libtoolize process seems to have failed"
  echo "Please check you have up to date versions of all those installed"
  exit 1
fi

exec $here/../configure $*
