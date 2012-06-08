#! /bin/sh

# Test a package
# An option "--csl" or "--psl" can specify that only that one Lisp
# is to be used.

#    scripts/test1.sh [--keep] [--csl or --psl] package_name 
# OR scripts/test1.sh [--keep] [--csl or --psl] regressions testname

keep="no"

csl="yes"
psl="yes"
case $1 in
--csl)
  csl="yes"
  psl="no"
  shift
  ;;
--psl)
  csl="no"
  psl="yes"
  shift
  ;;
--keep)
  keep="yes"
  shift
  ;;
*)
  ;;
esac
case $1 in
--csl)
  csl="yes"
  psl="no"
  shift
  ;;
--psl)
  csl="no"
  psl="yes"
  shift
  ;;
--keep)
  keep="yes"
  shift
  ;;
*)
  ;;
esac

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

loader=""

# If no argument is provided then this runs alg.tst
p=${1:-alg}
# WARNING - the "-n" option to echo is not portable.
if test "x$p" = "xregressions"
then
  r=${2:-aug-29-2011}
  echo -n "Regression test $r: "
  p="$r"
  d="regressions"
else
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
  d=${w%\"*}
  d=${d#*\"}
  p=${2:-$p}
fi


# If I am running on Windows I need to have the file name in
# (close to) native windows form. I can usefully retain "/" rather than
# "\", but eg it will be in the form "d:/directory/file.ext"

f="$here/packages/$d/$p.tst"
if test -f /usr/bin/cygpath
then
  f=`cygpath -m $f`
fi

# I will annotate the strict with the identity of the machine on which the
# test was run...

mc=`$here/config.guess`
mc=`$here/scripts/findhost.sh $mc`

# There is one reall mess about the above identification of platform. On
# a 64-bit windows the default behaviour is that a 64-bit version will be
# built and used if possible. But possibility will depend on the availability
# if build-tools etc. So I try tests here that will probably work...
# In unusual cases it may mis-report but unless you are going to install
# all the log files built here that is not very important!

if test "x$mc" = "xi686-pc-windows" && test -d cslbuild/x86_64-w64-windows
then
  mc="x86_64-w64-windows"
fi

# Each individual test should only take a few seconds. On my computer the
# slowest ones may take almost 15 seconds. The idea behind applying a
# ulimit here is to avoid trouble when and if a test script loops.
 
ulimit -c 60

if test "$csl" = "yes"
then

mkdir -p csl-times

time sh -c "$here/bin/redcsl -w > csl-times/$p.rlg.tmp" <<XXX 2>howlong.tmp
off int;
symbolic linelength 80;
symbolic(!*redeflg!* := nil);
%off pwrds;
on errcont;
$loader
lisp random_new_seed 1;
resettime1;
write "START OF REDUCE TEST RUN ON $mc"$ in "$f"; write "END OF REDUCE TEST RUN"$
showtime1$
quit$
XXX
cat howlong.tmp >> csl-times/$p.rlg.tmp
echo -n CSL...
sed -e "/^Tested on /,//d" <$here/packages/$d/$p.rlg |
  sed -e '/^Total time taken:/d; /^Number of garbage/d' \
      -e '/^Time: /d; /^CRACK needed :/d; /^time for init/d' \
      -e '/^+++ levelt compiled/d; /^\*\*\* (levelt): base/d' \
      -e '/^Request to set constant bitsperword/d' \
      -e '/^time to formulate/d; /\*\*\* turned off switch/d' \
       >csl-times/$p.rlg.orig
sed -e "1,/START OF REDUCE TEST RUN/d" -e "/END OF REDUCE TEST RUN/,//d" \
    -e "/OMIT/,/TIMO/d" <csl-times/$p.rlg.tmp | \
  sed -e "1s/^1: //" | sed -e '$s/^1: //' | \
  sed -e '/^Total time taken:/d; /^Number of garbage/d' \
      -e '/^Time: /d; /^CRACK needed :/d; /^time for init/d' \
      -e '/^+++ levelt compiled/d; /^\*\*\* (levelt): base/d' \
      -e '/^Request to set constant bitsperword/d' \
      -e '/^time to formulate/d; /\*\*\* turned off switch/d' \
       >csl-times/$p.rlg
diff -B -w csl-times/$p.rlg.orig csl-times/$p.rlg >csl-times/$p.rlg.diff
if test "$psl" = "yes"
then
  n="-n"
else
  n=""
fi
if test -s csl-times/$p.rlg.diff
  then echo $n "Diff is in csl-times/$p.rlg.diff "
  else echo $n "OK! " ; rm csl-times/$p.rlg.diff csl-times/$p.rlg.orig
fi
echo "Tested on $mc CSL" > csl-times/$p.time
sed -e "1,/END OF REDUCE TEST RUN/d"  <csl-times/$p.rlg.tmp | \
  sed -e '/^1: /d;' >>csl-times/$p.time
if test "x$keep" = "xno"
then
  rm csl-times/$p.rlg.tmp
fi

fi # CSL case

if test "$psl" = "yes"
then

mkdir -p psl-times

time sh -c "$here/bin/redpsl > psl-times/$p.rlg.tmp" <<XXX 2>howlong.tmp
off int;
symbolic linelength 80;
symbolic(!*redefmsg := nil);
symbolic(!*redeflg!* := nil);
%off pwrds;
on errcont;
$loader
lisp random_new_seed 1;
resettime1;
write "START OF REDUCE TEST RUN on $mc"$ in "$f"; write "END OF REDUCE TEST RUN"$
showtime1$
quit$
XXX
cat howlong.tmp >> psl-times/$p.rlg.tmp
echo -n "PSL..."
sed -e "/^Tested on /,//d" <$here/packages/$d/$p.rlg | \
  sed -e '/^Total time taken:/d; /^Number of garbage/d' \
      -e '/^Time: /d; /^CRACK needed :/d; /^time for init/d' \
      -e '/^+++ levelt compiled/d; /^\*\*\* (levelt): base/d' \
      -e '/^Request to set constant bitsperword/d' \
      -e '/^time to formulate/d; /\*\*\* turned off switch/d' \
     >psl-times/$p.rlg.orig
sed -e "1,/START OF REDUCE TEST RUN/d" -e "/END OF REDUCE TEST RUN/,//d" \
    -e "/OMIT/,/TIMO/d" <psl-times/$p.rlg.tmp | \
  sed -e "1s/^1: //" | sed -e '$s/^1: //' | \
  sed -e '/^Total time taken:/d; /^Number of garbage/d' \
      -e '/^Time: /d; /^CRACK needed :/d; /^time for init/d' \
      -e '/^+++ levelt compiled/d; /^\*\*\* (levelt): base/d' \
      -e '/^Request to set constant bitsperword/d' \
      -e '/^time to formulate/d; /\*\*\* turned off switch/d' \
     >psl-times/$p.rlg
diff -B -w psl-times/$p.rlg.orig psl-times/$p.rlg >psl-times/$p.rlg.diff
if test -s psl-times/$p.rlg.diff
  then echo "diff is in psl-times/$p.rlg.diff"
  else echo "OK! " ; rm psl-times/$p.rlg.diff psl-times/$p.rlg.orig
fi
echo "Tested on $mc PSL" > psl-times/$p.time
sed -e "1,/END OF REDUCE TEST RUN/d"  <psl-times/$p.rlg.tmp | \
  sed -e '/^1: /d;' >psl-times/$p.time
if test "x$keep" = "xno"
then
  rm  psl-times/$p.rlg.tmp
fi

fi # PSL case

if test "$csl" = "yes" && test "$psl" = "yes"
then
  mkdir -p csl-psl-times-comparison
  diff -B -w csl-times/$p.rlg psl-times/$p.rlg >csl-psl-times-comparison/$p.rlg.diff
  if test -s csl-psl-times-comparison/$p.rlg.diff
    then echo "CSL and PSL test logs differ!"
    else rm csl-psl-times-comparison/$p.rlg.diff
  fi
fi

rm -f howlong.tmp

# end of test
