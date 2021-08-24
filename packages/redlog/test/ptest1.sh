#! /bin/sh

# Test a package
# An option "--csl" or "--psl" can specify that only that one Lisp
# is to be used.

#    scripts/test1.sh [--keep] [--csl or --psl] package_name 
# OR scripts/test1.sh [--keep] [--csl or --psl] regressions testname

# I want this script to be one I can launch from anywhere, so
# to access files etc I need to know where it lives.

here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`dirname "$here"`
here=`cd "$here"; cd ../..; pwd -P`
here=`dirname "$here"`

csl="yes"
psl="yes"
keep="no"

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

# If no argument is provided then this runs alg.tst
p=${1:-alg}
# WARNING - the "-n" option to echo is not portable. So I use printf
# which should be available in all Posix systems.
if test "x$p" = "xregressions"
then
  r=${2:-aug-29-2011}
  printf "Regression test $r: "
  p="$r"
  d="regressions"
else
  printf "%-40s" "Testing $p: "
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

# If I am running on Windows I need to have the file name in
# (close to) native windows form. I can usefully retain "/" rather than
# "\", but eg it will be in the form "d:/directory/file.ext"

f="$here/packages/$d/$p.tst"
if test -f /usr/bin/cygpath
then
  f=`cygpath -m $f`
fi

dd="$here/packages/$d"
if test -f /usr/bin/cygpath
then
  dd=`cygpath -m $dd`
fi

# I will annotate the script with the identity of the machine on which the
# test was run...

mc=`$here/config.guess`
mc=`$here/scripts/findhost.sh $mc`

# There is one reall mess about the above identification of platform. On
# a 64-bit windows the default behaviour is that a 64-bit version will be
# built and used if possible. But possibility will depend on the availability
# if build-tools etc. So I try tests here that will probably work...
# In unusual cases it may mis-report but unless you are going to install
# all the log files built here that is not very important!

if test "x$mc" = "xi686-pc-windows" && test -d cslbuild/x86_64-pc-windows
then
  mc="x86_64-pc-windows"
fi

# Each individual test should only take a few seconds. On my computer the
# slowest ones may take almost 15 seconds. The idea behind applying a
# ulimit here is to avoid trouble when and if a test script loops.
 
ulimit -c 60

howlong=$p.howlong.tmp

if test "$csl" = "yes"
then

mkdir -p csl-times

$timecmd sh -c "$here/bin/redcsl -w > csl-times/$p.rlg.tmp" <<XXX 2>$howlong
off int;
symbolic linelength 80;
symbolic(!*redeflg!* := nil);
%off pwrds;
on errcont;
$loader
lisp testdirectory:="$dd";
lisp random_new_seed 1;
resettime1;
write "START OF REDUCE TEST RUN ON $mc"$ in "$f"; write "END OF REDUCE TEST RUN"$
showtime1$
quit$
XXX
cat $howlong >> csl-times/$p.rlg.tmp
printf CSL...
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
if test -s csl-times/$p.rlg.diff
  then printf "Diff is in csl-times/$p.rlg.diff "
  else printf "OK " ; rm -f csl-times/$p.rlg.diff csl-times/$p.rlg.orig
fi
echo "Tested on $mc CSL" > csl-times/$p.time
sed -e "1,/END OF REDUCE TEST RUN/d"  <csl-times/$p.rlg.tmp | \
  sed -e '/^1: *$/d;' >>csl-times/$p.time
if test "x$keep" = "xno"
then
  rm -f csl-times/$p.rlg.tmp
fi

fi # CSL case

if test "$psl" = "yes"
then

mkdir -p psl-times

$timecmd sh -c "$here/bin/redpsl > psl-times/$p.rlg.tmp" <<XXX 2>$howlong
off int;
symbolic linelength 80;
symbolic(!*redefmsg := nil);
symbolic(!*redeflg!* := nil);
%off pwrds;
on errcont;
$loader
lisp testdirectory:="$dd";
lisp random_new_seed 1;
resettime1;
write "START OF REDUCE TEST RUN on $mc"$ in "$f"; write "END OF REDUCE TEST RUN"$
showtime1$
quit$
XXX
cat $howlong >> psl-times/$p.rlg.tmp
printf "PSL..."
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
  then printf "diff is in psl-times/$p.rlg.diff"
  else printf "OK " ; rm -f psl-times/$p.rlg.diff psl-times/$p.rlg.orig
fi
echo "Tested on $mc PSL" > psl-times/$p.time
sed -e "1,/END OF REDUCE TEST RUN/d"  <psl-times/$p.rlg.tmp | \
  sed -e '/^1: /d;' >>psl-times/$p.time
if test "x$keep" = "xno"
then
  rm -f psl-times/$p.rlg.tmp
fi

fi # PSL case

if test "$csl" = "yes" && test "$psl" = "yes"
then
  echo "1k " > $p.timer.tmp
  grep ^Time csl-times/$p.time | \
   sed -e 's/.*(counter 1): //; s/ms.*//' >> $p.timer.tmp
  echo " 100 * " >> $p.timer.tmp
  grep ^Time psl-times/$p.time | \
   sed -e 's/.*(counter 1): //; s/ms.*//' >> $p.timer.tmp
  echo " / pq" >> $p.timer.tmp
# If "dc" is not available then the following line leaves ratio empty.
  ratio=`dc < $p.timer.tmp 2>/dev/null`
  # if test "x$ratio" != "x" && test "x$ratio" != "x0"
  # then 
    # printf "CSL/PSL:${ratio}%%"
  # fi
  rm $p.timer.tmp
  mkdir -p csl-psl-times-comparison
  diff -B -w csl-times/$p.rlg psl-times/$p.rlg >csl-psl-times-comparison/$p.rlg.diff
  if test -s csl-psl-times-comparison/$p.rlg.diff
    then
      echo " "
      printf "CSL and PSL test logs differ!"
    else rm -f csl-psl-times-comparison/$p.rlg.diff
  fi
fi

echo " "

rm -f $howlong

# end of test
