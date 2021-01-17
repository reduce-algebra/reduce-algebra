#! /bin/sh

# Test a package
#
#    scripts/test1.sh [options] package_name
#    scripts/test1.sh [options] regressions testname
#
# The available options are
#
#  VERSIONS TO TEST:
#     --csl       run tests using CSL
#                 [can also use eg --csl-debug, --csl-nothrow etc]
#     --cslboot   run tests using CSL "bootstrapreduce"
#                 [can also use --cslboot-debug etc]
#     --psl       run tests using PSL
#     --jlisp     run tests using Jlisp
#     --jlispboot run tests using Jlisp "bootstrapreduce.jar"
#
#  GENERAL OPTIONS:
#     --keep      preserve raw intermediate files at end of test, eg for
#                 debugging.
#     --install   copy CSL results back into the main source tree as
#                 a fresh set of reference log files
#     --uncached  run tests with symbolic(!*uncached := t);
#     --skip-missing-rlg
#                 do not run test when the .rlg file is missing
#
# For --csl and --cslboot the end of the name can be some subset of
# CSL variant builds. As of early 2021 this is some of the following
# in the order shown
#     -m32-m64-nogui-fox-wx-test-arithlib-conservative-nothrow-debug
# but of these -m32 and -m64 are historical relics, -wx a stalled potential
# development and -arithlib, -conservative and -nothrow are to varying extents
# incomplete and experimental. This feature is present for sensible reasons
# like comparing results and timing for a release vs. a debug build and
# while testing those incomplete experiments to see how close to running the
# full set of tests they get. And what impact they have on timings.
# If any such suffix is given a relevent built version must be present in
#     cslbuild/$host_triple$suffix/csl
# [eg cslbuild/x86_64-pc-cygwin-test-debug/cslor whatever].
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
here=`dirname "$here"`
here=`cd "$here"; pwd -P`
here=`dirname "$here"`

diffBw() {
    case `diff -v` in
    *GNU\ diffutils*)
      diff -B -w $1 $2
      ;;
    *)
# if "diff" is not the GNU version it may not support the "-B" or "-w"
# options that ignore whitespace, so here I use sed to get rid of it
# before running diff.
      sed 's/[[:space:]]//g; /^[[:space:]]*$/d' < $1 > $name-times/temp1.tmp
      sed 's/[[:space:]]//g; /^[[:space:]]*$/d' < $2 > $name-times/temp2.tmp
      diff $name-times/temp1.tmp $name-times/temp2.tmp
      rm $name-times/temp1.tmp $name-times/temp2.tmp
      ;;
    esac
}

# platforms is a list of the cases to be tested
platforms=""

install="no"
keep="no"
slow="no"
uncached=""
skipmissingrlg=""

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
    --csl | --csl-*)
      platforms="$platforms ${1#--}"
      shift
      ;;
    --cslboot | --cslboot-*)
      slow="yes"
      platforms="$platforms ${1#--}"
      shift
      ;;
    --jlisp)
      slow="yes"
      platforms="$platforms jlisp"
      shift
      ;;
    --jlispboot)
      slow="yes"
      platforms="$platforms jlispboot"
      shift
      ;;
    --psl)
      platforms="$platforms psl"
      shift
      ;;
    --uncached)
      uncached='symbolic (!*uncached := t);'
      shift
      ;;
    --skip-missing-rlg)
      skipmissingrlg="yes"
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
if test "$platforms" = ""
then
  platforms=" csl psl"
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

# If I can I will limit the time that each test script can possibly use.
# I would like to make the limit such that everything has a decent chance of
# running to completion but that tests that get stuck do not delay me
# unduly. The most extreme test at the time of writing this is stoolls which
# uses up to 90 seconds on a decent speed desktop machine. So a limit
# at 600 seconds seems tolerably safe for most machine. It is sufficient for
# if the Raspberry Pi 3, where the sstools and qsum take a fair proportion
# of that. Well I will qualify that the bootstrap version -- especially if
# built with debug options enabled - can be much slower, so if one of the
# tests is for that I will increase the limit significantly.

if test "x$timeoutcmd" != "x"
then
  if test "x$slow" = "xyes"
  then
    timeoutcmd="$timeoutcmd 2400"
  else
    timeoutcmd="$timeoutcmd 600"
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
# test was run... mc ends up as (probably!) the host-triple used in the
# cslbuild directory. There is perhaps one oddity in that if that comes
# out as x86_64-pc-windows than x86_64-pc-cygwin may also be relevant!

mc=`$here/config.guess`
mc=`$here/scripts/findhost.sh $mc`

# 
# Use /dev/null if the .rlg file doesn't exist

if test -f $here/packages/$d/$p.rlg
then
  rlgfile=$here/packages/$d/$p.rlg
elif test "x$skipmissingrlg" != "x"
then
  echo "Missing log file $here/packages/$d/$p.rlg - skipping test!"
  exit 1
else
  rlgfile=/dev/null
fi

# 
# Each individual test should only take a few seconds. The idea behind
# applying a ulimit here is to avoid trouble when or if a test script loops.
 
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

# To be able to replace full pathnames I generate a version of the path with 
# directory separators / and \ escaped:

ESCAPED_DIR=`echo $dd | sed -e 's/[\/\\\\]/\\\\&/g'`

#######################################################################
# CSL testing
#######################################################################

# For CSL the normal and bootstrap versions will be processed almost
# identically, so I wrap up the recipe in a function.

csltest() {
  name=$1
  command=$2
  showname=$3
  variant="$4"

  if test "$variant" = ""
  then
    fullcommand="$here/bin/$command $CSLFLAGS"
  else
    exename="$here/cslbuild/$mc-$variant/csl/$command"
    if ! test -x "$exename"
    then
      printf "\n+++ Unable to use $exename\n";
      exit 1
    fi
    fullcommand="$exename $CSLFLAGS"
  fi

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
% What follows is in Lisp to avoid parsing issues if some packages are loaded!
symbolic eval '
  (prog (cpu_time gc_time o)
    (setq cpu_time  (difference (time) otime1!*))
    (setq gc_time   (difference (gctime) ogctime1!*))
    (cond
      ((memq 'psl lispsystem!*)
       (setq cpu_time (difference cpu_time gc_time))))
    (wrs (setq o (open "$name-times/$p.showtime" 'output)))
    (print (list "$p" cpu_time gc_time))
    (wrs nil)
    (prin2 "Time: ") (prin2 "$p")
    (prin2 "  ") (prin2 cpu_time)
    (prin2 "  ") (prin2 gc_time)
    (terpri))$
end$
quit$
XXX
  if test -f $name-times/$p.showtime
  then
    cat $name-times/$p.showtime >> $name-times/showtimes
  fi
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

#######################################################################
# Jlisp testing
# This may be similar enough to the CSL case that it should be merged?
#######################################################################

jlisptest() {
  name=$1
  command=$2
  showname=$3

  mkdir -p $name-times

  wh="$here"
  if test -f /usr/bin/cygpath
  then
    wh=`cygpath -m $wh`
  fi

  $timeoutcmd $timecmd sh -c "java -jar $wh/jlisp/$command -v -w $otherflags > $name-times/$p.rlg.tmp" <<XXX 2>$p.howlong.tmp
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
% What follows is in Lisp to avoid parsing issues if some packages are loaded!
symbolic eval '
  (prog (cpu_time gc_time o)
    (setq cpu_time  (difference (time) otime1!*))
    (setq gc_time   (difference (gctime) ogctime1!*))
    (cond
      ((memq 'psl lispsystem!*)
       (setq cpu_time (difference cpu_time gc_time))))
    (wrs (setq o (open "$name-times/$p.showtime" 'output)))
    (print (list "$p" cpu_time gc_time))
    (wrs nil)
    (prin2 "Time: ") (prin2 "$p")
    (prin2 "  ") (prin2 cpu_time)
    (prin2 "  ") (prin2 gc_time)
    (terpri))$
end$
quit$
XXX
  if test -f $name-times/$p.showtime
  then
    cat $name-times/$p.showtime >> $name-times/showtimes
  fi
  cat $p.howlong.tmp >> $name-times/$p.rlg.tmp
  printf $showname...
  sed -e "/^Tested on /,//d" <$rlgfile |
    sed -e "$SED1" >$name-times/$p.rlg.orig
  sed -e "1,/START OF REDUCE TEST RUN/d" -e "/END OF REDUCE TEST RUN/,//d" \
      -e "/OMIT/,/TIMO/d" <$name-times/$p.rlg.tmp | \
    sed -e "1s/^1: //" | sed -e '$s/^1: //' | \
    sed -e "$SED1" >$name-times/$p.rlg
  diffBw $name-times/$p.rlg.orig $name-times/$p.rlg >$name-times/$p.rlg.diff
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

#######################################################################
# PSL testing
#######################################################################

psltest() {
  name=psl
  mkdir -p $name-times

  $timeoutcmd $timecmd sh -c "$here/bin/redpsl > psl-times/$p.rlg.tmp" <<XXX 2>$p.howlong.tmp
off int;
symbolic linelength 80;
symbolic(!*redefmsg := nil);
symbolic(!*redeflg!* := nil);
%off pwrds;
$uncached
on errcont;
$loader
lisp (testdirectory:="$dd");
lisp random_new_seed 1;
resettime1;
write "START OF REDUCE TEST RUN on $mc"$ in "$f"; write "END OF REDUCE TEST RUN"$
% What follows is in Lisp to avoid parsing issues if some packages are loaded!
symbolic eval '
  (prog (cpu_time gc_time o)
    (setq cpu_time  (difference (time) otime1!*))
    (setq gc_time   (difference (gctime) ogctime1!*))
    (cond
      ((memq 'psl lispsystem!*)
       (setq cpu_time (difference cpu_time gc_time))))
    (wrs (setq o (open "$name-times/$p.showtime" 'output)))
    (print (list "$p" cpu_time gc_time))
    (wrs nil)
    (prin2 "Time: ") (prin2 "$p")
    (prin2 "  ") (prin2 cpu_time)
    (prin2 "  ") (prin2 gc_time)
    (terpri))$
quit$
XXX
  if test -f $name-times/$p.showtime
  then
    cat $name-times/$p.showtime >> $name-times/showtimes
  fi
  cat $p.howlong.tmp >> psl-times/$p.rlg.tmp
  printf "PSL..."
  sed -e "/^Tested on /,//d" <$rlgfile | \
    sed -e "$SED1" >psl-times/$p.rlg.orig
  sed -e "1,/START OF REDUCE TEST RUN/d" -e "/END OF REDUCE TEST RUN/,//d" \
      -e "/OMIT/,/TIMO/d" <psl-times/$p.rlg.tmp | \
    sed -e "1s/^1: //" | sed -e '$s/^1: //' | \
    sed -e "s/${ESCAPED_DIR}.//" | \
    sed -e "$SED1" >psl-times/$p.rlg
  diffBw psl-times/$p.rlg.orig psl-times/$p.rlg >psl-times/$p.rlg.diff
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
}

for pp in $platforms
do
  case $pp in
  csl)
    csltest "$pp" "redcsl" "CSL"
# If the test cases include simple "--csl" and "--install" is specified
# the log files will be installed in the main tree.
    if test "$install" = "yes"
    then
      cat $here/packages/$d/$p.tst > $here/xmpl/$p.tst
      cat csl-times/$p.rlg csl-times/$p.time > $here/xmpl/$p.rlg
      cat csl-times/$p.rlg csl-times/$p.time > $here/packages/$d/$p.rlg
    fi
    ;;
  csl-*)
    csltest "$pp" "reduce" "CSL${pp#csl}" "${pp#csl-}"
    ;;
  cslboot)
    csltest "$pp" "bootstrapreduce" "BootstrapCSL"
    ;;
  cslboot-*)
    csltest "$pp" "bootstrapreduce" "BootstrapCSL${pp#cslboot}" "${pp#cslboot-}"
    ;;
  jlisp)
    jlisptest "jlisp" "reduce.jar" "Jlisp"
    ;;
  jlispboot)
    jlisptest "jlispboot" "bootstrapreduce.jar" "JlispBootstrap"
    ;;
  psl)
    psltest
    ;;
  *)
    printf "\n+++ Platform $pp not recognized\n"
    exit 1
  esac
done

#######################################################################
# End of code that runs the tests. Now report on results.
#######################################################################


# I will show speed ratios. The first specified platform will be used
# as defining the base-line. Thus for instance
#   test1.sh --csl --psl            uses CSL as the base
#   test1.sh --psl --csl --jlisp    uses PSL as the base
# There is no merit in trying to do comparisons if only one system
# had been tested, so I will detect and filter that case...

first=""
more="no"
for x in $platforms
do
  if test "$first" = ""
  then
    first="$x"
  else
    more="yes"
  fi
done

if test "$more" = "yes"
then

#== This does not work with my adjusted time reporting! I will come back and
#== fix it later, but often the ratios it displays are pretty uncertain
#== because of jitter in timings.
#==
#== # Append on the end of the output line a list of speed ratios.
#==   base=""
#==   for sys in $platforms
#==   do
#==     tt=`grep ^Time $sys-times/$p.time | \
#==         sed -e 's/.*(counter 1): //; s/ms.*//'`
#== # base gets set to the time recorded for the first platform in the list.
#==     if test "x$base" = "x"
#==     then
#== # If the recorded time is zero (which at least sometimes comes out
#== # as the string "0 " here) I will set a base-time of 1 so that I
#== # avoid division by zero later on.
#==       if test "x$tt" = "x" || test "x$tt" = "x0" || test "x$tt" = "x0 "
#==       then
#==         base="1"
#==       else
#==         base="$tt"
#==       fi
#==     fi
#== # If "dc" is not available then the following line leaves ratio empty.
#==     ratio=`printf "1k $tt 100 * $base / pq" | dc 2> /dev/null`
#==     if test "x$ratio" = "x"
#==     then
#==       ratio="?"
#==     fi
#==     printf "$sys:${ratio}%% "
#==   done
  printf "\n"

# Now if any test logs disagree (using the first platform to define
# a reference) print messages that explain that fact.
  base=""
  for sys in $platforms
  do
    if test "x$base" = "x"
    then
      base="$sys"
    else
      mkdir -p $base-$sys-times-comparison
      diffBw $base-times/$p.rlg $sys-times/$p.rlg >$base-$sys-times-comparison/$p.rlg.diff
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

