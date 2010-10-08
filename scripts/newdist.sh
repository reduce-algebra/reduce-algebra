#! /bin/sh

# make a distribution archive - a replacement for dist.sh

#  newdist.sh         Create full distribution



# I want a "working" version of "sed" but can not guarantee that
# there is one on the standard path, so I look in plausible places...

if test "x$SED" = "x"
then
  if test -x /opt/sfw/bin/gsed
  then SED=/opt/sfw/bin/gsed
  elif test -x /usr/local/bin/gsed
  then SED=/usr/local/bin/gsed
  elif test -x /usr/bin/gsed
  then SED=/usr/bin/gsed
  else SED=sed
  fi
fi


# Find the location this script lived in.

a=$0
c=unknown
case $a in
/* )
  c=$a  
  ;;
*/* )
  case $a in
  ./* )
    a=`echo $a | $SED -e s+./++`
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

here=`echo $c | $SED -e 's+/[^/]*$++'`

# I will tag full archives with today's date
d=`date +%Y%m%d`

f="reduce-algebra-$d"
fbase="reduce-algebra"

$here/resetall.sh

here0=`pwd`
cd $here/..

rm -rf $f
svn export . $f
ls -lRh $f > MANIFEST

echo Now create the .tar.bz2 file

tar cf - $f | bzip2 > $f.tar.bz2
rm -rf $f

ln -sf $f.tar.bz2 reduce-algebra.tar.bz2

ls -lhd ${fbase}*.tar.bz2

cd $here0

exit 0


