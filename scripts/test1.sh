#! /bin/sh

# Test a package
#
#    scripts/test1.sh [options] package_name
#    scripts/test1.sh [options] regressions testname
#
# The available options are
#
#     --keep      preserve raw intermediate files at end of test, eg for
#                 debugging.
#     --install   copy CSL results back into the main source tree as
#                 a fresh set of reference log files
#
#     --debug     pass "-g" flags to CSL and Jlisp to help debugging
#     --csl       run tests using CSL
#     --psl       run tests using PSL
#     --jlisp     run tests using Jlisp
#     --cslboot   run tests using CSL "bootstrapreduce"
#     --jlispboot run tests using Jlisp "bootstrapreduce.jar"
#
# It is legal and reasonable and proper to specify multiple Lisp variants to
# be tested. If none are explicitly mentioned the code will default to
# behaving as if "--csl --psl" has been specified. Note that this means that
# if you specify ANY platform explitly then only listed platforms will be
# tested.
#

# I want this script to be one I can launch from anywhere, so
# to access files etc I need to know where it lives.

here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`cd \`dirname "$here"\` ; pwd -P`
here=`dirname "$here"`

install="no"
keep="no"
platform=""
debug="no"

csl="no"
cslboot="no"
jlisp="no"
jlispboot="no"
psl="no"

# I allow any number of the keyword arguments in any order. I will pick
# off and process arguments for so long as any are available. This will
# stop if I either upperly run put of arguments (detected when $# = 0) or
# if $1 fails to match one of the keywords.

stop="no"
until test "$stop" = "yes"
do
  if test "$#" = "0"
  then
    stop="yes"
  else
    case $1 in
    --install)
      if test "$install" = "yes"
      then
        printf "You should only specify --install once. Stopping.\n"
        exit 1
      fi
      install="yes";
      shift
      ;;
    --keep)
      if test "$keep" = "yes"
      then
        printf "You should only specify --keep once. Stopping.\n"
        exit 1
      fi
      keep="yes";
      shift
      ;;
    --debug)
      debug="yes"
      shift
      ;;
    --csl)
      if test "$csl" = "yes"
      then
        printf "You should only specify --csl once. Stopping.\n"
        exit 1
      fi
      csl="yes"
      platform="$platform csl"
      shift
      ;;
    --cslboot)
      if test "$cslboot" = "yes"
      then
        printf "You should only specify --cslboot once. Stopping.\n"
        exit 1
      fi
      cslboot="yes"
      platform="$platform cslboot"
      shift
      ;;
    --jlisp)
      if test "$jlisp" = "yes"
      then
        printf "You should only specify --jlisp once. Stopping.\n"
        exit 1
      fi
      jlisp="yes"
      platform="$platform jlisp"
      shift
      ;;
    --jlispboot)
      if test "$jlispboot" = "yes"
      then
        printf "You should only specify --jlispboot once. Stopping.\n"
        exit 1
      fi
      jlispboot="yes"
      platform="$platform jlispboot"
      shift
      ;;
    --psl)
      if test "$psl" = "yes"
      then
        printf "You should only specify --psl once. Stopping.\n"
        exit 1
      fi
      psl="yes"
      platform="$platform psl"
      shift
      ;;
    -*)
      printf "\"$1\" looks like an option but is not recognized.\n"
      printf "Stopping.\n"
      exit 1
      ;;
    *)
      stop="yes"
      ;;
    esac
  fi
done

# If no specific choice of platform was made I use a default...
if test "$platform" = ""
then
  csl="yes"
  psl="yes"
  platform=" csl psl"
fi

if test "$debug" = "yes"
then
  gflag="-g"
else
  gflag=""
fi

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

if test "x$mc" = "xi686-pc-windows"
then
  if test -d cslbuild/x86_64-pc-windows
  then
    mc="x86_64-pc-windows"
  fi
fi

# 
# Use /dev/null if the .rlg file doesn't exist

if test -f $here/packages/$d/$p.rlg
then
  rlgfile=$here/packages/$d/$p.rlg
else
  rlgfile=/dev/null
fi

# 
# Each individual test should only take a few seconds. On my computer the
# slowest ones may take almost 15 seconds. The idea behind applying a
# ulimit here is to avoid trouble when and if a test script loops.
 
ulimit -c 60 2>/dev/null

# There are a number of "sed" operations I use to tidy up logs files
# so that comparisons do not show up frivolous differences. I put the
# scripts here so that if they need extending I have them in one neat place.

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

#######################################################################
# CSL testing
#######################################################################

if test "$csl" = "yes" || test "$cslboot" = "yes"
then

# For CSL the normal and bootstrap versions will be processed almost
# identically, so I wrap up the recipe in a function

csltest() {
name=$1
command=$2
showname=$3
gflag=$4

mkdir -p $name-times

$timecmd sh -c "$here/bin/$command -v -w $gflag > $name-times/$p.rlg.tmp" <<XXX 2>$p.howlong.tmp
off int;
symbolic linelength 80;
symbolic(!*redeflg!* := nil);
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
  sed -e "$SED1" >$name-times/$p.rlg
diff -B -w $name-times/$p.rlg.orig $name-times/$p.rlg >$name-times/$p.rlg.diff
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

if test "$csl" = "yes"
then
  csltest "csl" "redcsl" "CSL" "$gflag"

  if test "$install" = "yes"
  then
    cat $here/packages/$d/$p.tst > $here/xmpl/$p.tst
    cat csl-times/$p.rlg csl-times/$p.time > $here/xmpl/$p.rlg
    cat csl-times/$p.rlg csl-times/$p.time > $here/packages/$d/$p.rlg
  fi
fi

if test "$cslboot" = "yes"
then
  csltest "cslboot" "bootstrapreduce" "BootstrapCSL"
fi

fi # CSL case

if test "$psl" = "yes"
then

#######################################################################
# PSL testing
#######################################################################

mkdir -p psl-times

$timecmd sh -c "$here/bin/redpsl > psl-times/$p.rlg.tmp" <<XXX 2>$p.howlong.tmp
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
cat $p.howlong.tmp >> psl-times/$p.rlg.tmp
printf "PSL..."
sed -e "/^Tested on /,//d" <$rlgfile | \
  sed -e "$SED1" >psl-times/$p.rlg.orig
sed -e "1,/START OF REDUCE TEST RUN/d" -e "/END OF REDUCE TEST RUN/,//d" \
    -e "/OMIT/,/TIMO/d" <psl-times/$p.rlg.tmp | \
  sed -e "1s/^1: //" | sed -e '$s/^1: //' | \
  sed -e "$SED1" >psl-times/$p.rlg
diff -B -w psl-times/$p.rlg.orig psl-times/$p.rlg >psl-times/$p.rlg.diff
if test -s psl-times/$p.rlg.diff
  then echo "diff is in psl-times/$p.rlg.diff"
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

#######################################################################
# Jlisp testing
# This may be similar enough to the CSL case that it should be merged?
#######################################################################

if test "$jlisp" = "yes" || test "$jlispboot" = "yes"
then

jlisptest() {
name=$1
command=$2
showname=$3
gflag=$4

mkdir -p $name-times

wh="$here"
if test -f /usr/bin/cygpath
then
  wh=`cygpath -m $wh`
fi

$timecmd sh -c "java -jar $wh/jlisp/$command -v -w $gflag > $name-times/$p.rlg.tmp" <<XXX 2>$p.howlong.tmp
off int;
symbolic linelength 80;
symbolic(!*redeflg!* := nil);
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
  sed -e "$SED1" >$name-times/$p.rlg
diff -B -w $name-times/$p.rlg.orig $name-times/$p.rlg >$name-times/$p.rlg.diff
if test -s $name-times/$p.rlg.diff
  then printf "Diff is in $name-times/$p.rlg.diff "
  else printf "OK " ; rm -f $name-times/$p.rlg.diff $name-times/$p.rlg.orig
fi
echo "Tested on $mc Jlisp" > $name-times/$p.time
sed -e "1,/END OF REDUCE TEST RUN/d"  <$name-times/$p.rlg.tmp | \
  sed -e '/^1: *$/d;' >>$name-times/$p.time
if test "x$keep" = "xno"
then
  rm -f $name-times/$p.rlg.tmp
fi
}

if test "$jlisp" = "yes"
then
  jlisptest "jlisp" "reduce.jar" "Jlisp" "$gflag"
fi

if test "$jlispboot" = "yes"
then
  jlisptest "jlispboot" "bootstrapreduce.jar" "JlispBootstrap"
fi

fi # Jlisp case

#######################################################################
# End of code that runs the tests.
#######################################################################


# Now I will show speed ratios. The first specified platform will be used
# as defining the base-line. Thus for instance
#   test1.sh --csl --psl            uses CSL as the base
#   test1.sh --psl --csl --jlisp    uses PSL as the base
# There is no merit in trying to do comparisons if only one system
# had been tested, so I will detect and filter that case...

counter=""
for x in $platform
do
  counter="x$counter"
done

if test "$counter" != "x"
then

# Append on the end of the output line a list of speed ratios.
  base=""
  for sys in $platform
  do
    tt=`grep ^Time $sys-times/$p.time | \
        sed -e 's/.*(counter 1): //; s/ms.*//'`
    if test "x$base" = "x"
    then
# If the recorded time is zero (which at least sometimes comes out
# as the string "0 " here) I will set a base-time of 1 so that I
# avoid division by zero later on.
      if test "x$tt" = "x" || test "x$tt" = "x0" || test "x$tt" = "x0 "
      then
        base="1"
      else
        base="$tt"
      fi
    fi
# If "dc" is not available then the following line leaves ratio empty.
    ratio=`printf "1k $tt 100 * $base / pq" | dc 2> /dev/null`
    if test "x$ratio" = "x"
    then
      ratio="?"
    fi
    printf "$sys:${ratio}%% "
  done
  printf "\n"

# Now if any test logs disagree (using the first platform to define
# a reference) print messages that explain that fact.
  base=""
  for sys in $platform
  do
    if test "x$base" = "x"
    then
      base="$sys"
    else
      mkdir -p $base-$sys-times-comparison
      diff -B -w $base-times/$p.rlg $sys-times/$p.rlg >$base-$sys-times-comparison/$p.rlg.diff
      if test -s $base-$sys-times-comparison/$p.rlg.diff
      then
        printf "***** $base and $sys test logs differ!\n"
      else rm -f $base-$sys-times-comparison/$p.rlg.diff
      fi
    fi
  done

else
# Only one system being tested.
  printf "\n"
fi

rm -f $p.howlong.tmp
exit 0

# end of test

