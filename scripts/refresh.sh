#! /bin/sh

loc="$1"
if test "x$loc" = "x"
then
  case `uname -a` in
  *panamint*)
    loc="gauguin"
    ;;
  *gauguin*)
    loc="panamint"
    ;;
  *)
    echo "Usage scripts/refresh.sh <hostname>"
    exit 1
    ;;
  esac
fi

echo About to refresh sources from the server on $loc

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

cd $here/..
xport -fetch=$loc
$here/stamp.sh
cd $here

rm -f lgpldist.sh manifest.sh lgplmanifest.sh

# There are some files that are kept in two places. This script re-makes
# symbolic links. Hmmm - how well will subversion cope with this?

ln -s dist.sh lgpldist.sh
ln -s dist.sh manifest.sh
ln -s dist.sh lgplmanifest.sh

cd ../csl/fox/include
rm termed.h; ln -s ../../cslbase/termed.h .
rm fwin.h;   ln -s ../../cslbase/fwin.h   .
cd ../src
rm termed.c; ln -s ../../cslbase/termed.c .
rm fwin.c;   ln -s ../../cslbase/fwin.c   .
cd $here

echo Local files now up to date


