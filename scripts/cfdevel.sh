#! /bin/sh

# This is a PRIVATE script that may have a limited life. Its job is to compare
# files in the development tree for REDUCE in teh form that predated this
# subversion-organised code and look for changes.

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

case x$HOSTNAME in
*gauguin*)
   DEVRED=/home/acn1/devred/packages
   ;;
*panamint*)
   DEVRED=/e/devred/packages
   ;;
*)
   echo "can not find development system on this machine"
   exit 1
   ;;
esac

OPENRED=$here/../packages

gcc $here/addlicense.c -o /tmp/addlicense

for f in `find $OPENRED -name \*.red -print`
do
g=`echo $f | sed s+$OPENRED+$DEVRED+`
h=`echo $f | sed s+$OPENRED++`
/tmp/addlicense $g $f
if ! test -f $g.fixed
then
   echo +++++ $h not present in development tree
   echo "File $h not present in development tree" > $f.new
else
if diff -b $g.fixed $f > /tmp/diffs
then
rm /tmp/diffs
else
echo +++++ $h differs
cat /tmp/diffs
cp $g.fixed $f.new
echo +++++ Version from devred copied to $h.new here
echo " "
fi
fi
rm -f $g.fixed > /dev/null
done

