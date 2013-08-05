#! /bin/sh 

# Test a package
# An option "--csl" or "--psl" can specify that only that one Lisp
# is to be used.

#    scripts/rltest1.sh [--keep] [--csl or --psl] root date rooted_test_file 

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

loader=""

# Make sure that all messages are in english
LANG=C ; export LANG

root=$1
date=$2
rootedp=$3

timings=$root/$date/timings
trunk=$root/$date/trunk
regressions=$trunk/packages/redlog/regressions
d=$(dirname $rootedp)
p=$(basename $rootedp .tst)

mc="$(uname -n) running $(uname -srm)"

# Tricky logic to always use the external time command, even if
# the shell has a time builtin, or not collecting times if no external
# time command can be found
if test "x$BASH_VERSION" != "x"
then
  # do a search for time in $PATH
  timecmd=`type -P time`
  if test "x$timecmd" != "x"
  then
    timecmd="$timecmd -p"
  fi
else
  testfortime=`type time 2>&1 | grep -v "not found"`
  if test -n "$testfortime"
  then
    set -- $testfortime
    # remove all but last parameter
    shift `expr $# - 1`
    timecmd="$1 -p"
  else
    timecmd=""
  fi
fi

f="$regressions/$d/$p.tst"
dd="$d"

# If I am running on Windows I need to have the file name in
# (close to) native windows form. I can usefully retain "/" rather than
# "\", but eg it will be in the form "d:/directory/file.ext"

# The idea behind applying a ulimit here is to avoid trouble when and if a test
# script loops.
ulimit -c 1800

if test "$csl" = "yes"
then

mkdir -p $timings/csl-times/$d

howlong=$timings/$p.howlong.tmp

$timecmd sh -c "$trunk/bin/redcsl -w > $timings/csl-times/$d/$p.rlg.tmp" <<XXX 2>$howlong
off int;
symbolic linelength 80;
symbolic(!*redeflg!* := nil);
%off pwrds;
on errcont;
$loader
lisp (testdirectory:="$dd");
lisp random_new_seed 1;
resettime1;
write "START OF REDUCE TEST RUN ON $mc"$ in "$f"; write "END OF REDUCE TEST RUN"$
showtime1$
quit$
XXX
cat $howlong >> $timings/csl-times/$d/$p.rlg.tmp
#printf CSL...
sed -e "/^Tested on /,//d" <$regressions/$d/$p.rlg |
  sed -e '/^Total time taken:/d; /^Number of garbage/d' \
      -e '/^Time: /d; /^CRACK needed :/d; /^time for init/d' \
      -e '/^+++ levelt compiled/d; /^\*\*\* (levelt): base/d' \
      -e '/^Request to set constant bitsperword/d' \
      -e '/^time to formulate/d; /\*\*\* turned off switch/d' \
       >$timings/csl-times/$d/$p.rlg.orig
sed -e "1,/START OF REDUCE TEST RUN/d" -e "/END OF REDUCE TEST RUN/,//d" \
    -e "/OMIT/,/TIMO/d" <$timings/csl-times/$d/$p.rlg.tmp | \
  sed -e "1s/^1: //" | sed -e '$s/^1: //' | \
  sed -e '/^Total time taken:/d; /^Number of garbage/d' \
      -e '/^Time: /d; /^CRACK needed :/d; /^time for init/d' \
      -e '/^+++ levelt compiled/d; /^\*\*\* (levelt): base/d' \
      -e '/^Request to set constant bitsperword/d' \
      -e '/^time to formulate/d; /\*\*\* turned off switch/d' \
       >$timings/csl-times/$d/$p.rlg
diff -B -w $timings/csl-times/$d/$p.rlg.orig $timings/csl-times/$d/$p.rlg >$timings/csl-times/$d/$p.rlg.diff

if test -s $timings/csl-times/$d/$p.rlg.diff; then
#    cslresult="CSL failed (diff is in $timings/csl-times/$d/$p.rlg.diff)"
    cslresult="failed"
else
    cslresult="ok"
    rm -f $timings/csl-times/$d/$p.rlg.diff $timings/csl-times/$d/$p.rlg.orig
fi

echo "Tested on $mc CSL" > $timings/csl-times/$d/$p.time
sed -e "1,/END OF REDUCE TEST RUN/d"  <$timings/csl-times/$d/$p.rlg.tmp | \
  sed -e '/^1: *$/d;' >>$timings/csl-times/$d/$p.time
if test "x$keep" = "xno"
then
  rm -f $timings/csl-times/$d/$p.rlg.tmp
fi

fi # CSL case

if test "$psl" = "yes"
then

mkdir -p $timings/psl-times/$d

$timecmd sh -c "$trunk/bin/redpsl > $timings/psl-times/$d/$p.rlg.tmp" <<XXX 2>$howlong
off int;
symbolic linelength 80;
symbolic(!*redefmsg := nil);
symbolic(!*redeflg!* := nil);
%off pwrds;
on errcont;
$loader
lisp (testdirectory:="$dd");
lisp random_new_seed 1;
resettime1;
write "START OF REDUCE TEST RUN on $mc"$ in "$f"; write "END OF REDUCE TEST RUN"$
showtime1$
quit$
XXX
cat $howlong >> $timings/psl-times/$d/$p.rlg.tmp
#printf "PSL..."
sed -e "/^Tested on /,//d" <$regressions/$d/$p.rlg | \
  sed -e '/^Total time taken:/d; /^Number of garbage/d' \
      -e '/^Time: /d; /^CRACK needed :/d; /^time for init/d' \
      -e '/^+++ levelt compiled/d; /^\*\*\* (levelt): base/d' \
      -e '/^Request to set constant bitsperword/d' \
      -e '/^time to formulate/d; /\*\*\* turned off switch/d' \
     >$timings/psl-times/$d/$p.rlg.orig
sed -e "1,/START OF REDUCE TEST RUN/d" -e "/END OF REDUCE TEST RUN/,//d" \
    -e "/OMIT/,/TIMO/d" <$timings/psl-times/$d/$p.rlg.tmp | \
  sed -e "1s/^1: //" | sed -e '$s/^1: //' | \
  sed -e '/^Total time taken:/d; /^Number of garbage/d' \
      -e '/^Time: /d; /^CRACK needed :/d; /^time for init/d' \
      -e '/^+++ levelt compiled/d; /^\*\*\* (levelt): base/d' \
      -e '/^Request to set constant bitsperword/d' \
      -e '/^time to formulate/d; /\*\*\* turned off switch/d' \
     >$timings/psl-times/$d/$p.rlg
diff -B -w $timings/psl-times/$d/$p.rlg.orig $timings/psl-times/$d/$p.rlg >$timings/psl-times/$d/$p.rlg.diff

if test -s $timings/psl-times/$d/$p.rlg.diff; then
    pslresult="failed"
#    pslresult="PSL failed (diff is in $timings/psl-times/$d/$p.rlg.diff)"
else
    pslresult="ok"
    rm -f $timings/psl-times/$d/$p.rlg.diff $timings/psl-times/$d/$p.rlg.orig
fi

echo "Tested on $mc PSL" > $timings/psl-times/$d/$p.time
sed -e "1,/END OF REDUCE TEST RUN/d"  <$timings/psl-times/$d/$p.rlg.tmp | \
  sed -e '/^1: /d;' >>$timings/psl-times/$d/$p.time
if test "x$keep" = "xno"
then
  rm -f $timings/psl-times/$d/$p.rlg.tmp
fi

fi # PSL case

if test "$csl" = "yes" && test "$psl" = "yes"
then
  echo "0k " > $timings/$p.timer.tmp
  grep ^Time $timings/csl-times/$d/$p.time | \
   sed -e 's/.*(counter 1): //; s/ms.*//' >> $timings/$p.timer.tmp
  echo " 100 * " >> $timings/$p.timer.tmp
  grep ^Time $timings/psl-times/$d/$p.time | \
   sed -e 's/.*(counter 1): //; s/ms.*//' >> $timings/$p.timer.tmp
  echo " / pq" >> $timings/$p.timer.tmp
# If "dc" is not available then the following line leaves ratio empty.
  ratio=`dc < $timings/$p.timer.tmp 2>/dev/null`
  if test "x$ratio" != "x" && test "x$ratio" != "x0"
  then 
    ratioresult="${ratio}%"
  else
    ratioresult="unknown"
  fi
  rm $timings/$p.timer.tmp
  mkdir -p $timings/csl-psl-times-comparison/$d
  diff -B -w $timings/csl-times/$d/$p.rlg $timings/psl-times/$d/$p.rlg >$timings/csl-psl-times-comparison/$d/$p.rlg.diff
  if test -s $timings/csl-psl-times-comparison/$d/$p.rlg.diff
  then
      resultlispdiff=", CSL and PSL test logs differ"
  else resultlispdiff=""; rm -f $timings/csl-psl-times-comparison/$d/$p.rlg.diff
  fi
fi

rm -f $howlong

if [ $cslresult = failed ] || [ $pslresult = failed ]; then
    printf "test %-35s CSL %s, PSL %s\n" "$d/$p:" "$cslresult" "$pslresult"
elif [ $ratioresult = unknown ]; then
    printf "test %-35s CSL %s, PSL %s %s\n" "$d/$p:" "$cslresult" "$pslresult" "$resultlispdiff"
else
    printf "test %-35s CSL %s, PSL %s, CSL/PSL = %4s %s\n" "$d/$p:" "$cslresult" "$pslresult" "$ratioresult" "$resultlispdiff"
fi

# end of test
