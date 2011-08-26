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
echo -n "Package to test is $p: "

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

# Note that resettime1/showtime1 is a new timing feature in Reduce
# intended to support this and avoid any other timings taken within
# test scripts from hurting.

time ($here/bin/redcsl -w <<XXX > csl-times/$p.rlg.tmp) 2>howlong.tmp
off int;
symbolic(!*redeflg!* := nil);
%off pwrds;
on errcont;
$loader
resettime1;
write "START OF REDUCE TEST RUN"$
in "$f";
write "END OF REDUCE TEST RUN"$
showtime1;
quit;
XXX
cat howlong.tmp >> csl-times/$p.rlg.tmp
echo -n CSL...
sed -e "1d" -e "/^Time for test:/,//d" <$here/packages/$d/$p.rlg | sed -e '/^Total time taken:/d; /^Number of garbage/d; /^Time: /d; /^CRACK needed :/d; /^time for init/d; /^time to formulate/d' >csl-times/$p.rlg.orig
sed -e "1,/START OF REDUCE TEST RUN/d" -e "/END OF REDUCE TEST RUN/,//d" -e "/OMIT/,/TIMO/d" <csl-times/$p.rlg.tmp | sed -e "1s/^1: //" | sed -e '$s/^1: //' | sed -e '/^Total time taken:/d; /^Number of garbage/d; /^Time: /d; /^CRACK needed :/d; /^time for init/d; /^time to formulate/d' >csl-times/$p.rlg
diff -B -w csl-times/$p.rlg.orig csl-times/$p.rlg >csl-times/$p.rlg.diff
if test -s csl-times/$p.rlg.diff
  then echo -n "Diff is in csl-times/$p.rlg.diff "
  else echo -n "OK! " ; rm csl-times/$p.rlg.diff csl-times/$p.rlg.orig
fi
sed -e "1,/END OF REDUCE TEST RUN/d"  <csl-times/$p.rlg.tmp | sed -e '/^1: /d;' >csl-times/$p.time
rm csl-times/$p.rlg.tmp

mkdir -p psl-times

time ($here/bin/redpsl <<XXX > psl-times/$p.rlg.tmp) 2>howlong.tmp
off int;
symbolic(!*redefmsg := nil);
symbolic(!*redeflg!* := nil);
%off pwrds;
on errcont;
$loader
resettime1;
write "START OF REDUCE TEST RUN"$
in "$f";
write "END OF REDUCE TEST RUN"$
showtime1;
quit;
XXX
cat howlong.tmp >> psl-times/$p.rlg.tmp
echo -n "PSL..."
sed -e "1d" -e "/^Time for test:/,//d" <$here/packages/$d/$p.rlg | sed -e '/^Total time taken:/d; /^Number of garbage/d; /^Time: /d; /^CRACK needed :/d; /^time for init/d; /^time to formulate/d' >psl-times/$p.rlg.orig
sed -e "1,/START OF REDUCE TEST RUN/d" -e "/END OF REDUCE TEST RUN/,//d" -e "/OMIT/,/TIMO/d" <psl-times/$p.rlg.tmp | sed -e "1s/^1: //" | sed -e '$s/^1: //' | sed -e '/^Total time taken:/d; /^Number of garbage/d; /^Time: /d; /^CRACK needed :/d; /^time for init/d; /^time to formulate/d' >psl-times/$p.rlg
diff -B -w psl-times/$p.rlg.orig psl-times/$p.rlg >psl-times/$p.rlg.diff
if test -s psl-times/$p.rlg.diff
  then echo "diff is in psl-times/$p.rlg.diff"
  else echo "OK! " ; rm psl-times/$p.rlg.diff psl-times/$p.rlg.orig
fi
sed -e "1,/END OF REDUCE TEST RUN/d"  <psl-times/$p.rlg.tmp | sed -e '/^1: /d;' >psl-times/$p.time
rm  psl-times/$p.rlg.tmp

mkdir -p csl-psl-times-comparison
diff -B -w csl-times/$p.rlg psl-times/$p.rlg >csl-psl-times-comparison/$p.rlg.diff
if test -s csl-psl-times-comparison/$p.rlg.diff
  then echo "CSL and PSL test logs differ!"
  else rm csl-psl-times-comparison/$p.rlg.diff
fi

rm howlong.tmp

# end of test



