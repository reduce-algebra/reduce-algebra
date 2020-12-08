#! /bin/sh

# Test a package
#
#    scripts/test1.sh [options] package_name
#    scripts/test1.sh [options] regressions testname
#
# I want this script to be one I can launch from anywhere, so
# to access files etc I need to know where it lives.

redtop="$0";while test -L "$redtop";do redtop=`ls -ld "$redtop" | sed 's/.*-> //'`;done
redtop=`dirname "$redtop"`
redtop=`cd "$redtop"; pwd -P`
redtop=`dirname "$redtop"`
redtop=`cd "$redtop"; pwd -P`
redtop=`dirname "$redtop"`
redtop=`cd "$redtop"; pwd -P`
redtop=`dirname "$redtop"`

diffBw() {
# if "diff" is not the GNU version it may not support the "-B" or "-w"
# options that ignore whitespace, so redtop I use sed to get rid of it
# before running diff.
    sed 's/[[:space:]]//g; /^[[:space:]]*$/d' < $1 > $name-times/temp1.tmp
    sed 's/[[:space:]]//g; /^[[:space:]]*$/d' < $2 > $name-times/temp2.tmp
    diff $name-times/temp1.tmp $name-times/temp2.tmp
    rm $name-times/temp1.tmp $name-times/temp2.tmp
}

platform="js"

platform="jscsl"

loader=""

# Make sure that all messages are in English
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
  if test "x$2" = "x"
  then
    printf "Testing $p: "
  else
    printf "Testing $p/$2: "
  fi
  w=`grep " test " $redtop/packages/package.map | grep "($p "`
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
  timeoutcmd=`type -P timeout`
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
  testfortimeout=`type timeout 2>&1 | grep -v "not found"`
  if test -n "$testfortimeout"
  then
    set -- $testfortimeout
    # remove all but last parameter
    shift `expr $# - 1`
    timeoutcmd="$1"
  else
    timeoutcmd=""
  fi
fi

if test "x$timeoutcmd" != "x"
then
  timeoutcmd="$timeoutcmd 6000"
fi

f="$redtop/packages/$d/$p.tst"
if test -f /usr/bin/cygpath
then
  f=`cygpath -m $f`
fi

dd="$redtop/packages/$d"
if test -f /usr/bin/cygpath
then
  dd=`cygpath -m $dd`
fi

# I will annotate the script with the identity of the machine on which the
# test was run...

mc="js"

# 
# Use /dev/null if the .rlg file doesn't exist

if test -f $redtop/packages/$d/$p.rlg
then
  rlgfile=$redtop/packages/$d/$p.rlg
else
  rlgfile=/dev/null
fi

# 
# Each individual test should only take a few seconds. On my computer the
# slowest ones may take almost 15 seconds. The idea behind applying a
# ulimit redtop is to avoid trouble when and if a test script loops.
 
ulimit -c 600 2>/dev/null

# There are a number of "sed" operations I use to tidy up logs files
# so that comparisons do not show up frivolous differences. I put the
# scripts redtop so that if they need extending I have them in one neat place.

SED1='/^Total time taken:/d;
      /^Number of garbage/d;
      /^Time: /d;
      /^Realtime: /d;
      / cpu time :/d;
      /^CRACK needed :/d;
      /^time for init/d;
      /^+++ levelt compiled/d;
      /^\*\*\* (levelt): base/d;
      /^Request to set constant bitsperword/d;
      /^Step /d;
      /^time to formulate/d;
      /\*\*\* turned off switch/d;
      /^>> accum\. cpu time :/d
      /^max_gc_int :/d;
      /^max_gc_fac :/d'

# To be able to replace full pathnames I generate a version of the path with 
# directory separators / and \ escaped:

ESCAPED_DIR=`echo $dd | sed -e 's/[\/\\\\]/\\\\&/g'`

#######################################################################
# CSL testing
#######################################################################

# For CSL the normal and bootstrap versions will be processed almost
# identically, so I wrap up the recipe in a function

csltest() {
name=$1
command=$2
showname=$3

fullcommand="$command $CSLFLAGS"

mkdir -p $name-times

$timeoutcmd $timecmd sh -c "$fullcommand $extras -v -w $otherflags > $name-times/$p.rlg.tmp" <<XXX 2>$p.howlong.tmp
off int;
symbolic linelength 80;
symbolic(!*redeflg!* := nil);
$uncached
on errcont;
$loader
lisp (testdirectory:="$dd");
lisp random_new_seed 1;
resettime1;
write "START OF REDUCE TEST RUN ON $mc"$ in "$f"; write "END OF REDUCE TEST RUN"$
showtime1$
quit$
XXX
cat $p.howlong.tmp >> $name-times/$p.rlg.tmp
printf $showname...
sed -e "/^Tested on /,//d" <$rlgfile |
  sed -e "$SED1" >$name-times/$p.rlg.orig
sed -e "1,/START OF REDUCE TEST RUN/d" -e "/END OF REDUCE TEST RUN/,//d" \
    -e "/OMIT/,/TIMO/d" <$name-times/$p.rlg.tmp | \
  sed -e "1s/^1: //" | sed -e '$s/^1: //' | \
  sed -e "s/${ESCAPED_DIR}.//" | \
  sed -e "$SED1" >$name-times/$p.rlg
diffBw $name-times/$p.rlg.orig $name-times/$p.rlg >$name-times/$p.rlg.diff
if test -s $name-times/$p.rlg.diff
  then printf "Diff is in $name-times/$p.rlg.diff "
  else printf "OK " ; rm -f $name-times/$p.rlg.diff $name-times/$p.rlg.orig
fi
echo "Tested on $mc CSL" > $name-times/$p.time
sed -e "1,/END OF REDUCE TEST RUN/d"  <$name-times/$p.rlg.tmp | \
  sed -e '/^1: *$/d;' >>$name-times/$p.time
if test "x$keep" = "xno"
then
  rm -f $name-times/$p.rlg.tmp
fi

}

csltest "jscsl" "node bootstrapreduce.js" "JSCSL" "$v"


#######################################################################
# End of code that runs the tests.
#######################################################################


  printf "\n"

rm -f $p.howlong.tmp
exit 0

# end of test

