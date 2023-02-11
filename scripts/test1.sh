#! /bin/bash

# Test a package
#
#    scripts/test1.sh [options] [versions to test] package_name
#    scripts/test1.sh [options] [versions to test] REGRESSIONS testname
#
#
#  OPTIONS:
#     --keep      preserve raw intermediate files at end of test, eg for
#                 debugging.
#     --install   copy CSL results back into the main source tree as
#                 a fresh set of reference log files
#     --skip-missing-rlg
#                 do not run test when the .rlg file is missing
#     --no-timeout
#                 do not limit the time for test runs
#
#
#
#  VERSIONS TO TEST:
# Several versions can be specified. If none are listed testing is
# performed as of "--csl --psl" had been indicated.
#
#     --csl=VARIANT
#                 Use executable ...cslbuild/VARIANT/csl/reduce
#                 so eg "--csl=x86_64-pc-cygwin-debug" is a way to
#                 test and report on a debug-build.
#     --bootstrapreduce=VARIANT
#                 similarly but use bootstrapreduce
# There are a collection of abbreviations that can be used for VARIANT
# so that plausibly common cases are less cumbersome to use:
#      --csl, --bootstrapreduce, --psl: Use the default build within
#           the build tree. Note these are without a "=" sign.
#      --X=installed: Use a version from the system $PATH rather than
#           one in the current tree.
#      --X=debug: For CSL based versions use the debug build.
#      {--X-debug: temporary synonym for --X=debug for backwards compatibility} 
#      --X=windows, =cygwin, =windows, =native, =universal, =cygwin-debug,
#           =windows-debug, =native-debug, =universal-debuf: On Windows
#           for CSL based versions this allows selection as between a native
#           windows version and a cygwin one. On the Macintosh between
#           a native (only) build and an universal one. 
#
#     --psl=VARIANT
#                 Use a PSL Reduce from .../pslbuild/VARIANT.
#
# Jlisp is not very much supported, but these will parhaps be of use to
# anyone trying to use it again. 
#     --jlisp     Run tests using Jlisp.
#     --jlispboot Run tests using Jlisp "bootstrapreduce.jar".
#
#
# PACKAGE or REGRESSION
# After all the other options there is either an (optional) package
# name - which defaults to "alg", or the word "regressions" followed by
# the name of one of the tests in the packages/regressions directory.


# I want this script to be one I can launch from anywhere, so
# to access files etc I need to know where it lives.

here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`dirname "$here"`
here=`cd "$here"; pwd -P`
scripthere="$here"
here=`dirname "$here"`

# Procedures to help me sort out file names etc.

. "$scripthere/getplatform.sh"

#######################################################################
# Start of main action
#######################################################################

diffBw() {
# If gdiff is present I will expect it to be the GNU diff program from
# "port install diffutils". If that is not available but the plain diff
# command is the GNU one I will use that. Otherwise I have to work a
# bit harder.
    if which gdiff 1>/dev/null 2>/dev/null
    then
      gdiff -B -w $1 $2
    else
      case `diff -v 2> /dev/null` in
      *GNU\ diffutils*)
        diff -B -w $1 $2
        ;;
      *)
# if "diff" is not the GNU version it may not support the "-B" or "-w"
# options that ignore whitespace, so here I use sed to get rid of it
# before running diff.
        sed 's/[[:space:]]//g; /^[[:space:]]*$/d' < $1 > $logdir/temp1.tmp
        sed 's/[[:space:]]//g; /^[[:space:]]*$/d' < $2 > $logdir/temp2.tmp
        diff $logdir/temp1.tmp $logdir/temp2.tmp
        rm $logdir/temp1.tmp $logdir/temp2.tmp
        ;;
      esac
    fi
}


install="no"
keep="no"
skip_missing_rlg="no"
no_timeout="no"

# I allow any number of the keyword arguments in any order. I will pick
# off and process arguments for so long as any are available. This will
# stop if I either utterly run put of arguments (detected when $# = 0) or
# if $1 fails to match one of the keywords.

while test "$#" != 0
do
  case "$1" in
  --install)
    install="yes"
    shift
    ;;
  --keep)
    keep="yes"
    shift
    ;;
  --skip-missing-rlg)
    skip_missing_rlg="yes"
    shift
    ;;
  --no-timeout)
    no_timeout="yes"
    shift
    ;;
  --noregressions)
# This is not a useful option here so it is ignored, but doing so
# simplifies things for testall.sh. 
    shift
    ;;
  *)
    break;
  esac
done

# platforms is a list of the cases to be tested
platforms=""

while test "$#" != 0
do
  pp=`getplatform "$1"`
  if test "$pp" = ""
  then
    break
  else
    platforms="$platforms $1"
    shift
  fi
done

# If no specific choice of platform was made I use a default...
if test "$platforms" = ""
then
  platforms=" --csl --psl"
fi

loader=""

# Make sure that all messages are in English
LANG=C ; export LANG

# If no argument is provided then this runs alg.tst
p=${1:-alg}

if test "$p" = "regressions"
then
  r=${2:-aug-29-2011}
  printf "Regression test %s\n                 " "$r:"
  p="$r"
  d="regressions"
else
  printf "Test %-11s " "$p:"
  w=`grep " test " $here/packages/package.map | grep "($p "`
  case $w in
  *$p*) ;;
  *)    printf "Package $p does not exist for testing purposes\n"
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
if test "$BASH_VERSION" != ""
then
  # do a search for time in $PATH
  timecmd=`type -P time`
  if test "$timecmd" != ""
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

# If I can I will limit the time that each test script can possibly use,
# except when the --notimeout switch is set.
# I would like to make the limit such that everything has a decent chance of
# running to completion but that tests that get stuck do not delay me
# unduly. The most extreme test at the time of writing this is stools which
# uses up to 90 seconds on a decent speed desktop machine. So a limit
# at 600 seconds seems tolerably safe for most machine. It is sufficient for
# if the Raspberry Pi 3, where the sstools and qsum take a fair proportion
# of that. Well I will qualify that the bootstrap version -- especially if
# built with debug options enabled - can be much slower, so if one of the
# tests is for that I will increase the limit significantly.

limittime() {
# This is intended to run a command for a limited amount of CPU time.
# Note that ounder Cygwin it only checks the time DIRECTLY in the
# command that is launched, not in any sub-processes. So perhaps
# unexpectedly 'limittime "time ./expensiveCommand"' does not manage
# to time-out even if 'limittime ./expensiveCommand' might.

if test "$notimeout" = "yes"
then
  $timecmd $*
  exit $?
else
  if test "$slow" = "yes"
  then
    TIME=2400
  else
    TIME=600
  fi
  case `uname -s` in

  *CYGWIN*)
echo Cygwin special
for x in $*
do
  echo $x
done
    $* &
    PID=$!

    tick=`getconf CLK_TCK`

    while true
    do
       d=`cat /proc/$PID/stat 2>/dev/null`
       if test "$d" = ""
       then
         break
       fi
       user_time=$((`echo $d | cut -d' ' -f16` / $tick))
       if [ $user_time -ge $TIME ]
       then
         kill -9 $PID
         break
       fi
       sleep 1
    done

    wait $PID 2>/dev/null
    exit $?
    ;;

  *)
    ulimit -t $TIME
    $timecmd $*
    exit $?
    ;;

  esac
fi
}


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

# 
# Use /dev/null if the .rlg file doesn't exist

if test -f $here/packages/$d/$p.rlg
then
  rlgfile=$here/packages/$d/$p.rlg
elif test "$skipmissingrlg" != ""
then
  printf "Missing log file $here/packages/$d/$p.rlg - skipping test!\n"
  exit 1
else
  rlgfile=/dev/null
fi

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
      /^>> accum\. cpu time :/d;
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
  command=$1
  logdir=$2

  fullcommand="$command $CSLFLAGS"

  mkdir -p $logdir
  ( limittime $fullcommand $extras -v -w $otherflags ) > \
    $logdir/$p.rlg.tmp <<XXX 2>$p.howlong.tmp
off int;
symbolic linelength 80;
symbolic(!*redeflg!* := nil);
$uncached
on errcont;
$loader
lisp (testdirectory:="$dd");
lisp random_new_seed 1;
lisp if memq('bytecounts, lispsystem!*) then mapstore $profilemode;
resettime1;
write "START OF REDUCE TEST RUN ON $mc"$ in "$f"; write "END OF REDUCE TEST RUN"$
% What follows is in Lisp to avoid parsing issues if some packages are loaded!
symbolic eval '
  (prog (cpu_time gc_time o w tot)
    (setq cpu_time  (difference (time) otime1!*))
    (setq gc_time   (difference (gctime) ogctime1!*))
    (cond ((memq 'bytecounts lispsystem!*)
           (setq w (mapstore $profilemode1))))
    (cond
      ((memq 'psl lispsystem!*)
       (setq cpu_time (difference cpu_time gc_time))))
    (wrs (setq o (open "$logdir/$p.showtime" 'output)))
    (print (list "$p" cpu_time gc_time))
    (wrs nil)
    (cond ((memq 'bytecounts lispsystem!*)
           (wrs (setq o (open "$logdir/$p.$profilename" 'output)))
           (setq tot 0)
           (dolist (a w) (setq tot (plus tot (caddr a))))
           (set!-print!-precision 3)
% Display code size, bytes in this function and pecentage of total
           (dolist (a (sort w 'greaterpcaddr))
              (prin1 (car a)) (ttab 40) (prin1 (cadr a))
              (ttab 50) (prin1 (caddr a))
              (ttab 64) (prin1 (quotient (times 100.0 (caddr a)) tot))
              (prin2 "%") (terpri))
           (wrs nil)))
    (terpri)
    (prin2 "Time: ") (prin2 "$p")
    (prin2 "  ") (prin2 cpu_time)
    (prin2 "  ") (prin2 gc_time)
    (terpri))$
end$
quit$
XXX
  if test -f $logdir/$p.showtime
  then
    cat $logdir/$p.showtime >> $logdir/showtimes
  fi
  cat $p.howlong.tmp >> $logdir/$p.rlg.tmp
  printf ${logdir%-times}..
  sed -e "/^Tested on /,//d" <$rlgfile |
    sed -e "$SED1" >$logdir/$p.rlg.orig
  sed -e "1,/START OF REDUCE TEST RUN/d" -e "/END OF REDUCE TEST RUN/,//d" \
      -e "/OMIT/,/TIMO/d" <$logdir/$p.rlg.tmp | \
    sed -e "1s/^1: //" | sed -e '$s/^1: //' | \
    sed -e "s/${ESCAPED_DIR}.//" | \
    sed -e "$SED1" >$logdir/$p.rlg
  diffBw $logdir/$p.rlg.orig $logdir/$p.rlg >$logdir/$p.rlg.diff
  if test -s $logdir/$p.rlg.diff
    then printf "Diffs: $logdir/$p.rlg.diff "
    else printf "OK " ; rm -f $logdir/$p.rlg.diff $logdir/$p.rlg.orig
  fi
  printf "Tested on $mc CSL\n" > $logdir/$p.time
  sed -e "1,/END OF REDUCE TEST RUN/d"  <$logdir/$p.rlg.tmp | \
    sed -e '/^1: *$/d;' >>$logdir/$p.time
  if test "$keep" = "no"
  then
    rm -f $logdir/$p.rlg.tmp
  fi
}

#######################################################################
# Jlisp testing
# This may be similar enough to the CSL case that it should be merged?
#######################################################################

jlisptest() {
  command=$1
  logdir=$2

  mkdir -p $logdir

  wh="$here"
  if test -f /usr/bin/cygpath
  then
    wh=`cygpath -m $wh`
  fi

  ( limittime java -jar $wh/jlisp/$command -v -w $otherflags ) > $logdir/$p.rlg.tmp <<XXX 2>$p.howlong.tmp
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
    (wrs (setq o (open "$logdir/$p.showtime" 'output)))
    (print (list "$p" cpu_time gc_time))
    (wrs nil)
    (prin2 "Time: ") (prin2 "$p")
    (prin2 "  ") (prin2 cpu_time)
    (prin2 "  ") (prin2 gc_time)
    (terpri))$
end$
quit$
XXX
  if test -f $logdir/$p.showtime
  then
    cat $logdir/$p.showtime >> $logdir/showtimes
  fi
  cat $p.howlong.tmp >> $logdir/$p.rlg.tmp
  printf $showname..
  sed -e "/^Tested on /,//d" <$rlgfile |
    sed -e "$SED1" >$logdir/$p.rlg.orig
  sed -e "1,/START OF REDUCE TEST RUN/d" -e "/END OF REDUCE TEST RUN/,//d" \
      -e "/OMIT/,/TIMO/d" <$logdir/$p.rlg.tmp | \
    sed -e "1s/^1: //" | sed -e '$s/^1: //' | \
    sed -e "$SED1" >$logdir/$p.rlg
  diffBw $logdir/$p.rlg.orig $logdir/$p.rlg >$logdir/$p.rlg.diff
  if test -s $logdir/$p.rlg.diff
    then printf "Diff is in $logdir/$p.rlg.diff "
    else printf "OK " ; rm -f $logdir/$p.rlg.diff $logdir/$p.rlg.orig
  fi
  printf "Tested on $mc Jlisp\n" > $logdir/$p.time
  sed -e "1,/END OF REDUCE TEST RUN/d"  <$logdir/$p.rlg.tmp | \
    sed -e '/^1: *$/d;' >>$logdir/$p.time
  if test "$keep" = "no"
  then
    rm -f $logdir/$p.rlg.tmp
  fi
}

#######################################################################
# PSL testing
#######################################################################

psltest() {
  cmd="$1"
  logdir="$2"

  mkdir -p "$logdir"
  ( limittime $cmd > $logdir/$p.rlg.tmp ) <<XXX 2>$p.howlong.tmp
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
    (wrs (setq o (open "$logdir/$p.showtime" 'output)))
    (print (list "$p" cpu_time gc_time))
    (wrs nil)
    (prin2 "Time: ") (prin2 "$p")
    (prin2 "  ") (prin2 cpu_time)
    (prin2 "  ") (prin2 gc_time)
    (terpri))$
quit$
XXX
  if test -f $logdir/$p.showtime
  then
    cat $logdir/$p.showtime >> $logdir/showtimes
  fi
  cat $p.howlong.tmp >> $logdir/$p.rlg.tmp
  printf "${logdir%-times}.."
  sed -e "/^Tested on /,//d" <$rlgfile | \
    sed -e "$SED1" >$logdir/$p.rlg.orig
  sed -e "1,/START OF REDUCE TEST RUN/d" -e "/END OF REDUCE TEST RUN/,//d" \
      -e "/OMIT/,/TIMO/d" <$logdir/$p.rlg.tmp | \
    sed -e "1s/^1: //" | sed -e '$s/^1: //' | \
    sed -e "s/${ESCAPED_DIR}.//" | \
    sed -e "$SED1" >$logdir/$p.rlg
  diffBw $logdir/$p.rlg.orig $logdir/$p.rlg >$logdir/$p.rlg.diff
  if test -s $logdir/$p.rlg.diff
    then printf "diff is in $logdir/$p.rlg.diff\n"
    else printf "OK " ; rm -f $logdir/$p.rlg.diff $logdir/$p.rlg.orig
  fi
  printf "Tested on $mc PSL\n" > $logdir/$p.time
  sed -e "1,/END OF REDUCE TEST RUN/d"  <$logdir/$p.rlg.tmp | \
    sed -e '/^1: /d;' >>$logdir/$p.time
  if test "$keep" = "no"
  then
    rm -f $logdir/$p.rlg.tmp
  fi
}

for pp in $platforms
do
  pp=`getplatform "$pp"`
  logdir=`getlogdir "$pp"`

  case $pp in
  csl)
    csltest "$here/bin/redcsl" "$logdir"
# If the command specified "--install" and "--csl" then the log files
# will be installed in the main tree.
    if test "$install" = "yes"
    then
      cat $here/packages/$d/$p.tst > $here/xmpl/$p.tst
      cat $logdir/$p.rlg $logdir/$p.time > $here/xmpl/$p.rlg
      cat $logdir/$p.rlg $logdir/$p.time > $here/packages/$d/$p.rlg
    fi
    ;;
  csl=installed)
    csltest "redcsl" "$logdir"
    ;;
  bootstrapreduce)
    csltest "$here/bin/bootstrapreduce" "$logdir"
    ;;
  bootstrapreduce=installed)
    csltest "bootstrapreduce" "$logdir"
    ;;
  csl=*)
    csltest "$here/cslbuild/${pp#csl=}/csl/reduce" "$logdir"
    ;;
  bootstrapreduce=*)
    csltest "$here/cslbuild/${pp#csl=}/csl/bootstrapreduce" "$logdir"
    ;;
  psl)
    psltest "$here/bin/redpsl" "$logdir"
    ;;
  installed-psl)
    psltest "redpsl" "$logdir"
    ;;
  psl=*)
    psltest "$here/pslbuild/${pp#psl=}/psl/bpsl -t 1000 \
             -f $here/pslbuild/${pp#psl=}/red/reduce.img" \
            "$logdir"
    ;;

  jlisp)
    jlisptest "reduce.jar" "$logdir"
    ;;
  jlispboot)
    jlisptest "jlispboot" "bootstrapreduce.jar" "$logdir"
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
# If the base absolute time was under 500ms I will tag the ratio with
# a "?" as potentially unreliable.

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

# Append on the end of the output line a list of speed ratios.
  base=""
  none="yes"
  for pp in $platforms
  do
    pp=`getplatform "$pp"`
    logdir=`getlogdir $pp`
# Each file packageName.showtime will contain just one line of the form
#       ("packageName" cputime gctime)
# where the times are recorded in milliseconds.
    tt=`cat $logdir/$p.showtime | \
        sed -e 's/[^ ]* //; s/ .*//'`
# base gets set to the time recorded for the first platform in the list.
    
    if test "$none" = "yes"
    then
# If the recorded time is zero (which at least sometimes comes out
# as the string "0 " here) I will set a base-time of 1 so that I
# avoid division by zero later on.
      if test "$tt" = "" || test "$tt" = "0" || test "$tt" = "0 "
      then
        base="1"
      else
        base="$tt"
      fi
    fi
# If "dc" is not available then the following line leaves ratio empty.
    ratio=`printf "1k $tt 100 * $base / pq" | dc 2> /dev/null`
    if test "$ratio" = ""
    then
      ratio="?"
    fi
    reliable=""
    if test "$base" -lt 500
    then
      reliable="?"
    fi
    if test "$none" = "no"
    then
      printf "${logdir%-times}:%8s " "$reliable$ratio%"
    fi
    none="no"
  done
  printf "\n"

# Now if any test logs disagree (using the first platform to define
# a reference) print messages that explain that fact.
  basedir=""
  for pp in $platforms
  do
    pp=`getplatform $pp`
    logdir=`getlogdir $pp`
    if test "$basedir" = ""
    then
      basedir="$logdir"
    else
      mkdir -p ${basedir%-times}-${logdir%-times}-comparison
      diffBw $basedir/$p.rlg $logdir/$p.rlg > ${basedir%-times}-${logdir%-times}-comparison/$p.rlg.diff
      if test -s ${basedir%-times}-${logdir%-times}-comparison/$p.rlg.diff
      then
        printf "***** ${basedir%--times} and ${logdir%-times} test logs differ!\n"
      else
        rm -f ${basedir%-times}-${logdir%-times}-comparison/$p.rlg.diff
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
