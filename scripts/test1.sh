#! /bin/bash

# Test a package


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

echo $here


p=${1:-alg}
echo "Package to test is $p"

w=`grep " test " $here/packages/package.map | grep "($p "`

case $w in
*$p*) ;;
*)    echo "Package $p does not exist for testing purposes"
      exit 1
      ;;
esac

case $w in
" core ") loader=""
          ;;
*)        loader="load $p;"
          ;;
esac

# This is bash-specific. If anybody really wanted this could
# be redone using sed then this script could use plain /bin/sh.
d=${w%\"*}
d=${d#*\"}

f="$here/packages/$d/$p.tst"
if test -f /usr/bin/cygpath
then
  f=`cygpath -m $f`
fi

mkdir -p csl-times

ulimit -c 30

time ($here/bin/redcsl -w <<XXX > csl-times/$p.rlg) 2>howlong.tmp
off int;
$loader
showtime;
in "$f";
showtime;
quit;
XXX
cat howlong.tmp >> csl-times/$p.rlg
echo "+++ CSL for package $p +++"
diff -w $here/packages/$d/$p.rlg csl-times/$p.rlg

mkdir -p psl-times

time ($here/bin/redpsl <<XXX > psl-times/$p.rlg) 2>howlong.tmp
off int;
$loader
showtime;
in "$f";
showtime;
quit;
XXX
cat howlong.tmp >> psl-times/$p.rlg
echo "+++ PSL for package $p +++"
diff -w $here/packages/$d/$p.rlg psl-times/$p.rlg

rm howlong.tmp

# end of test



