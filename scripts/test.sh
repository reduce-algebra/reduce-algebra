#! /bin/bash

if test "$#" = 0 || test "$1" = "--help"
then
P() {
printf "%s\n" "$1"
}

# The intent is that this documentation should be readable here as well
# a being text displayed when "--help" is used or when no arguments at all
# are provided.

P "Test a package or a number of packages"
P "   scripts/test1.sh [options] [versions to test] [package_names]"
P ""
P " OPTIONS:"
P "    --help              Display this message and stop."
P "    --just-time         Do not run tests, just report times from logs.\n"
P "    --keep              Preserve temporary files. Good while debugging."
P "    --install           Copy new logs into the main source tree."
P "    --skip-missing-rlg  Still run a test even if there is no reference log."
P "    --fast              The default timeout is 600. secs. Make it 80."
P "    --slow              Make timeout 2400 secs for slow hosts."
P "    --no-timeout        Make timeout 86400 secs = 1 day for very slow hosts."
P "    --rr                Run tests with the "rr" record/replay debug"
P "                        too if possible."
P " [Note that I may add extras when I find them useful in debugging"
P "  or testing]."
P ""
P " VERSIONS TO TEST:"
P "    --psl [variants]"
P "    --csl [variants]"
P "    --bootstrapreduce [variants]"
P "    --jlisp"
P "    --jlispboot"
P " I can imagine adding others for e.g. a Common Lisp hosted version."
P ""
P " VARIANTS"
P "    optionally the main name of a system to test can be followed with"
P "    some further options:"
P "       --with-XXX     )"
P "       --without=XXX  ) These should select a version which had been"
P "       --enable-XXX   ) built with the speified options passed to"
P "       --disable-XXX  ) the "configure" script. Eg --enable-debug."
P "       --host=MMM     )"
P "       --pkgmap=FILE    Normally the file packages/package.map is used"
P "                        to sort out which sub-directories of packages"
P "                        hold which part of the code. With this option"
P "                        another file (in packages) can be used, and"
P "                        packages/FILE.map will be it."
P "       --with-buildver=DIR"
P "                        Use a version from cslbuild/DIR or pslbuild/DIR."
P "       --with-logs=DIR  Place logs in the named directory rather than in"
P "                        somewhere like csl-times or psl-times."
P " The full set of arguments handed to test1.sh should start with any"
P " of the 'options' listed above. Then there can be one or more 'versions',"
P " each of which can be followed by one or more 'variant specifiers' which"
P " are either of the form '--WORD' or '--WORD=VALUE'. The list of variants"
P " end either with the next version name (from the above list) of when an"
P " item is encountered not starting with '--'. The text of version specifiers"
P " is intended to relate to configure-time options, and so the permitted"
P " material will be in one of the forms"
P "     --with-*, --without-*, --enable-*, --disable-*, --host=*"
P ""
P "PACKAGES TO TEST:"
P "      NAME NAME NAME ..."
P "where NAME can be either the name of a Reduce packages (eg alg, poly,...)"
P "or the root part of the name of a regression test in the directory"
P "packages/regressions (eg 2011-08-29-fleps ...2025-04-04-issue-with-num_min)"
P " or the word 'all' which stands for all the packages, or 'regressions'"
P "which stands for all the regression test cases in the packages/regressions"
P "directory."
P "In no names are given the packages to test defaults to 'alg'. "
P "When 'all' is specified the list of packages tested will be all those"
P "in the package.map file that have the tag 'test' shows. If --pkgmap"
P "is used to set up several files each serving as a list of packages then"
P "'all' selects those packages present in all of those, i.e. the intersection"
P "of the sets that each map file offers."
exit 1
fi

# Make sure that all messages are in English
LANG=C ; export LANG

# For debugging this script I can pass it a first argument "--debug" and
# then use "optprintf". I do not mention this in the --help message because
# it just here for while this script itself is being developed and tested
# and ordinary users should not need it.

if test "$1" = "--debug"
then
  DEBUG=yes
  shift
else
  DEBUG="no"
fi

optprintf() {
  if test "$DEBUG" = "yes"
  then
    printf "$1"
  fi
}


#  I want this script to be one I can launch from anywhere, so
#  to access files etc I need to know where it lives. Note that the
#  possibly expensive used os "ls" and "sed" only arises if the path
#  to the current script is a symbolic link.

here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`dirname "$here"`
here=`cd "$here"; pwd -P`
scripthere="$here"
here=`dirname "$here"`

if test -f /usr/bin/cygpath
then
  winhere=`cygpath -m "$here"`
else
  winhere="$here"
fi

. $scripthere/finddirs.sh

getguess
findos

# These next line are for debugging..
optprintf "guessed=$guessed\n"
optprintf "osname=$osname\n"

just_times="no"
TIME=600
keep="no"
install="no"
skip_missing_rlg="no"
no_timeout="no"
rr="no"

while test $# != 0
do
  case $1 in
    --keep)
      keep="yes"
      shift
      ;;
    --install)
      install="yes"
      shift
      ;;
    --skip-missing-rlg)
      skip_missing_rlg="yes"
      shift
      ;;
    --fast)
      TIME=80;
      shift
      ;;
    --slow)
      TIME=2400;
      shift
      ;;
    --no-timeout)
      no_timeout="yes"
      TIME=86400;
      shift
      ;;
    --rr)
      rr="yes"
      shift
      ;;
    --just-times)
      just_times="yes"
      shift
      ;;
    *)
      break
      ;;
  esac
done

# Now I will want to make a list of the versions to be tested.
# For each such I will need two bits of informstion:
#  (1) The path to the Reduce executable to be used
#  (2) The name of the directory where log information will get put.
#
# So I will extract all the parameters that define a target system
# and sort out those two bits of info from them...

lispsystems=""
platforms=""
logdirs=""
packagefiles=""

thistarget=""
firsttarget=""

while test $# != 0
do
  case $1 in
  --psl | --csl | --bootstrapreduce | --jlisp | --jlispboot)
    lispsystem=${1#--}
    thistarget=$1
    shift
    while test $# != 0
    do
      case $1 in
        --psl | --csl | --bootstrapreduce | --jlisp | --jlispboot)
        gettarget $thistarget
        if test "$firsttarget" = ""
        then
          firsttarget="$target"
        fi
        platforms="$platforms $target"
        packagefiles="$packagefiles $packagefile"
        logdirs="$logdirs $logdir"
        thistarget=""
        break
       ;;
      --with-* | --without-* | \
      --enable-* | --disable-* | \
      --pkgmap=* | --host=*)
optprintf "keyword=$\n"
        thistarget="$thistarget $1"
        shift
        ;;
      *)
        gettarget $thistarget
        if test "$firsttarget" = ""
        then
          firsttarget="$target"
        fi
        platforms="$platforms $target"
        packagefiles="$packagefiles $packagefile"
        logdirs="$logdirs $logdir"
        thistarget=""
        break
        ;;
      esac
    done
    if test "$thistarget" != ""
    then
      gettarget $thistarget
      if test "$firsttarget" = ""
      then
        firsttarget="$target"
      fi
      platforms="$platforms $target"
      packagefiles="$packagefiles $packagefile"
      logdirs="$logdirs $logdir"
      thistarget=""
    fi
    lispsystems="$lispsystems $lispsystem"
    ;;
  *)
    break
    ;;
  esac
done

# If no platforms were given then assume "--csl --psl".

if test "$platforms" = ""
then
      gettarget "--csl"
      if test "$firsttarget" = ""
      then
        firsttarget="$target"
      fi
      platforms="$platforms $target"
      packagefiles="$packagefiles $packagefile"
      logdirs="$logdirs $logdir"
      thistarget=""
      gettarget "--csl"
      if test "$firsttarget" = ""
      then
        firsttarget="$target"
      fi
      platforms="$platforms $target"
      packagefiles="$packagefiles $packagefile"
      logdirs="$logdirs $logdir"
      thistarget=""
      lispsystems="csl psl"
fi

# The remaining arguments are the names of packages to test, with
# the words "all" and "regressions" having special meaning.

testcases=""
regressioncases=""

# list all the testable packages named in a package.map file.
# This sets testable to a string that names all packages in the
# form "@alg@ @poly@ @arith@ @factor@ @int@ @matrix@ ... @f5@"

findpackages() {
  testable=""
  for x in `sed -e '/^\%/d' $here/packages/${1:-package.map} | \
            grep ' test ' | \
            sed -e 's/(//; s/".*//'`
  do
    testable="$testable @$x@"
  done
}

# Set tidied to the argument but with duplicates removed and sorted and
# "@" characters removed

removeduplicates() {
  tidied=""
  tp=($1)
  for p in ${tp[@]}
  do
    if ! [[ "$tidied" =~ "$p" ]]
    then
      tidied="$tidied $p"
    fi
  done
  tidied=`echo $tidied | tr ' ' '\n' | sort | tr '\n@' '  '`
}

# To see what to test I must check every package map file and make a list
# of the package names common to all. This is set in $testable
# If any specific packages have been listed before "all" then they will
# be forgotten since "all" ought to include anything useful.

testall() {
  first="yes"
  seenpackagefile=""
  for x in $packagefiles
  do
# I will only scan a package file once. So ignore if already seen.
    if [[ "$seenpackagefiles" =~ "@$x@" ]]
    then
      continue
    fi
    seenpackagefile="$seenpackagefiles @$x@"
    if test "$first" = "yes"
    then
      findpackages "$x"
      first="no"
    else
      existing="$testable"
      findpackages "$x"
      newer="$testable"
      testable=""
      for p in $newer
      do
        if [[ "$existing" =~ "$p" ]]
        then
          testable="$testable $p"
        fi
      done
    fi
  done
}

# Find all the relevant names in the regressions directory.

testallregressions() {
  for x in $here/packages/regressions/*.tst
  do
    xx=`basename "$x"`
    regressioncases="$regressioncases ${xx%.tst}"
  done
}

if test "$#" = 0
then
  testable="alg"
else
  while test "$#" != 0
  do
    if test "$1" = "all"
    then
      testall
    elif test "$1" = "regressions"
    then
      testallregressions
    elif test -f "$here/packages/regressions/$1.tst"
    then
      regressioncases="$regressioncases $1"
    else
      testable="$testable @$1@"
    fi
    shift
  done
fi

# Now there could be some duplicated names - remove them and while at
# it sort the list of packages that are to be tested.

removeduplicates "$testable";
testable="$tidied"
removeduplicates "$regressioncases";
regressioncases="$tidied"

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

# I make the within-Lisp timeout occur 20 seconds before the system imposed
# one. So on a "--fast" setting this is 60 second left. 
TIME1=$((1000 * $TIME - 20000))

# Here pkg is the name of the package I am testing, dir is the directory
# that $pkg.tst will be in and $loader is a Reduce command that
# loads the relevant package ahead of testing it.

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
# Note that under Cygwin it only checks the time DIRECTLY in the
# command that is launched, not in any sub-processes. So perhaps
# unexpectedly 'limittime "time ./expensiveCommand"' does not manage
# to time-out even if 'limittime ./expensiveCommand' might.

  if test "$notimeout" = "yes"
  then
    $timecmd $*
    exit $?
  else
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

# I may need to test several versions so I have bash functions that
# handle each case. They need to be called with arguments that
# give the command to execute to launch Reduce and the directory
# to put log files in.

#######################################################################
# CSL testing
#######################################################################

# For CSL the normal and bootstrap versions will be processed almost
# identically, so I wrap up the recipe in a function.

csltest() {
optprintf "CSLTEST: $*\n"
  command=$1
  logdir=$2
  export PACKAGE="$pkg"

  fullcommand="$command $CSLFLAGS"
# "rr" is the "record and replay" system for supporting debugging and is
# often available on Linux but subject to the precise CPU that you have -
# since it relies on low level facilities such as performance counters.
# To allow it to work you typically have to reset some security options to
# be less paranoid. But when it has recorded a trace of a running program
# (typically a run that crashes) one can use gdb to replay that and run
# the execution either forwards or backwards to home in on the exact source
# of trouble.
  if test "$rr" = "yes"
  then
    rm -rf rr-files
    RR="rr record -o rr-files"
    printf "Will run under rr putting logs in rr-files\n"
  else
    RR=""
  fi
  if test "$jit" = "yes"
  then
    export do_jit="-Djit=t"
  else
    export do_jit=""
  fi
  mkdir -p $logdir
  ( limittime $RR $fullcommand $do_jit $extras -v -w $otherflags ) > \
    $logdir/$pkg.rlg.tmp <<XXX 2>$pkg.howlong.tmp
off int;
symbolic linelength 80;
symbolic(!*redeflg!* := nil);
$uncached
on errcont;
$loader
lisp (testdirectory:="$dir");
lisp random_new_seed 1;
lisp if memq('bytecounts, lispsystem!*) then mapstore 4;
resettime1;
write "START OF REDUCE TEST RUN ON $mc"\$ \
lisp begin with!-timeout($TIME1, << semic!* := '!;; in "$testfile">>) end\$ \
write "END OF REDUCE TEST RUN"\$
% What follows is in Lisp to avoid parsing issues because some packages,
% when loaded for testing, change input syntax and so on.
symbolic eval '
  (prog (cpu_time gc_time o w tot)
    (setq cpu_time  (difference (time) otime1!*))
    (setq gc_time   (difference (gctime) ogctime1!*))
    (cond ((memq 'bytecounts lispsystem!*)
           (setq w (mapstore 2))))
    (cond
      ((memq 'psl lispsystem!*)
       (setq cpu_time (difference cpu_time gc_time))))
    (wrs (setq o (open "$logdir/$pkg.showtime" 'output)))
    (print (list "$pkg" cpu_time gc_time))
    (wrs nil)
    (cond ((memq 'bytecounts lispsystem!*)
           (wrs (setq o (open "$logdir/$pkg.profile" 'output)))
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
    (prin2 "Time: ") (prin2 "$pkg")
    (prin2 "  ") (prin2 cpu_time)
    (prin2 "  ") (prin2 gc_time)
    (terpri))\$
end\$
quit\$
XXX
  if test "$jit" = "yes"
  then
    grep "JIT generated" $logdir/$pkg.rlg.tmp > $logdir/$pkg.jitsize
  else
    rm -f $logdir/$pkg.jitsize
  fi
  if test -f $logdir/$pkg.showtime
  then
    cat $logdir/$pkg.showtime >> $logdir/showtimes
  fi
  cat $pkg.howlong.tmp >> $logdir/$pkg.rlg.tmp
  printf ${logdir%-times}..
  sed -e "/^Tested on /,//d" <$rlgfile |
    sed -e "$SED1" >$logdir/$pkg.rlg.orig
  sed -e "1,/START OF REDUCE TEST RUN/d" -e "/END OF REDUCE TEST RUN/,//d" \
      -e "/OMIT/,/TIMO/d" <$logdir/$pkg.rlg.tmp | \
    sed -e "1s/^1: //" | sed -e '$s/^1: //' | \
    sed -e "s/${ESCAPED_DIR}.//" | \
    sed -e "$SED1" >$logdir/$pkg.rlg
  diffBw $logdir/$pkg.rlg.orig $logdir/$pkg.rlg >$logdir/$pkg.rlg.diff
  if test -s $logdir/$pkg.rlg.diff
    then printf "Diffs: $logdir/$pkg.rlg.diff "
    else printf "OK " ; rm -f $logdir/$pkg.rlg.diff $logdir/$pkg.rlg.orig
  fi
  printf "Tested on $mc CSL\n" > $logdir/$pkg.time
  sed -e "1,/END OF REDUCE TEST RUN/d"  <$logdir/$pkg.rlg.tmp | \
    sed -e '/^1: *$/d;' >>$logdir/$pkg.time
  if test "$keep" = "no"
  then
    rm -f $logdir/$pkg.rlg.tmp
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

  wh="$winhere"

  ( limittime java -jar $wh/jlisp/$command -v -w $otherflags ) > $logdir/$pkg.rlg.tmp <<XXX 2>$pkg.howlong.tmp
off int;
symbolic linelength 80;
symbolic(!*redeflg!* := nil);
$uncached
on errcont;
$loader
lisp (testdirectory:="$dir");
lisp random_new_seed 1;
resettime1;
write "START OF REDUCE TEST RUN ON $mc"\$ \
lisp begin with!-timeout($TIME1, << semic!* := '!;; in "$testfile">>) end\$ \
write "END OF REDUCE TEST RUN"\$
symbolic eval '
  (prog (cpu_time gc_time o)
    (setq cpu_time  (difference (time) otime1!*))
    (setq gc_time   (difference (gctime) ogctime1!*))
    (cond
      ((memq 'psl lispsystem!*)
       (setq cpu_time (difference cpu_time gc_time))))
    (wrs (setq o (open "$logdir/$pkg.showtime" 'output)))
    (print (list "$pkg" cpu_time gc_time))
    (wrs nil)
    (prin2 "Time: ") (prin2 "$pkg")
    (prin2 "  ") (prin2 cpu_time)
    (prin2 "  ") (prin2 gc_time)
    (terpri))\$
end\$
quit\$
XXX
  if test -f $logdir/$pkg.showtime
  then
    cat $logdir/$pkg.showtime >> $logdir/showtimes
  fi
  cat $pkg.howlong.tmp >> $logdir/$pkg.rlg.tmp
  printf $showname..
  sed -e "/^Tested on /,//d" <$rlgfile |
    sed -e "$SED1" >$logdir/$pkg.rlg.orig
  sed -e "1,/START OF REDUCE TEST RUN/d" -e "/END OF REDUCE TEST RUN/,//d" \
      -e "/OMIT/,/TIMO/d" <$logdir/$pkg.rlg.tmp | \
    sed -e "1s/^1: //" | sed -e '$s/^1: //' | \
    sed -e "$SED1" >$logdir/$pkg.rlg
  diffBw $logdir/$pkg.rlg.orig $logdir/$pkg.rlg >$logdir/$pkg.rlg.diff
  if test -s $logdir/$pkg.rlg.diff
    then printf "Diff is in $logdir/$pkg.rlg.diff "
    else printf "OK " ; rm -f $logdir/$pkg.rlg.diff $logdir/$pkg.rlg.orig
  fi
  printf "Tested on $mc Jlisp\n" > $logdir/$pkg.time
  sed -e "1,/END OF REDUCE TEST RUN/d"  <$logdir/$pkg.rlg.tmp | \
    sed -e '/^1: *$/d;' >>$logdir/$pkg.time
  if test "$keep" = "no"
  then
    rm -f $logdir/$pkg.rlg.tmp
  fi
}

#######################################################################
# PSL testing
#######################################################################

psltest() {
  cmd="$1"
  logdir="$2"
  mkdir -p "$logdir"
  ( limittime $cmd > $logdir/$pkg.rlg.tmp ) <<XXX 2>$pkg.howlong.tmp
off int;
symbolic linelength 80;
symbolic(!*redefmsg := nil);
symbolic(!*redeflg!* := nil);
%off pwrds;
$uncached
on errcont;
$loader
lisp (testdirectory:="$dir");
lisp random_new_seed 1;
resettime1;
write "START OF REDUCE TEST RUN on $mc"\$ \
lisp begin with!-timeout($TIME1, << semic!* := '!;; in "$testfile">>) end\$ \
write "END OF REDUCE TEST RUN"\$
symbolic eval '
  (prog (cpu_time gc_time o)
    (setq cpu_time  (difference (time) otime1!*))
    (setq gc_time   (difference (gctime) ogctime1!*))
    (cond
      ((memq 'psl lispsystem!*)
       (setq cpu_time (difference cpu_time gc_time))))
    (wrs (setq o (open "$logdir/$pkg.showtime" 'output)))
    (print (list "$pkg" cpu_time gc_time))
    (wrs nil)
    (prin2 "Time: ") (prin2 "$pkg")
    (prin2 "  ") (prin2 cpu_time)
    (prin2 "  ") (prin2 gc_time)
    (terpri))\$
end\$
(exitlisp)
XXX
  if test -f $logdir/$pkg.showtime
  then
    cat $logdir/$pkg.showtime >> $logdir/showtimes
  fi
  cat $pkg.howlong.tmp >> $logdir/$pkg.rlg.tmp
  printf "${logdir%-times}.."
  sed -e "/^Tested on /,//d" <$rlgfile | \
    sed -e "$SED1" >$logdir/$pkg.rlg.orig
  sed -e "1,/START OF REDUCE TEST RUN/d" -e "/END OF REDUCE TEST RUN/,//d" \
      -e "/OMIT/,/TIMO/d" <$logdir/$pkg.rlg.tmp | \
    sed -e "1s/^1: //" | sed -e '$s/^1: //' | \
    sed -e "s/${ESCAPED_DIR}.//" | \
    sed -e "$SED1" >$logdir/$pkg.rlg
  diffBw $logdir/$pkg.rlg.orig $logdir/$pkg.rlg >$logdir/$pkg.rlg.diff
  if test -s $logdir/$pkg.rlg.diff
    then printf "diff is in $logdir/$pkg.rlg.diff\n"
    else printf "OK " ; rm -f $logdir/$pkg.rlg.diff $logdir/$pkg.rlg.orig
  fi
  printf "Tested on $mc PSL\n" > $logdir/$pkg.time
  sed -e "1,/END OF REDUCE TEST RUN/d"  <$logdir/$pkg.rlg.tmp | \
    sed -e '/^1: /d;' >>$logdir/$pkg.time
  if test "$keep" = "no"
  then
    rm -f $logdir/$pkg.rlg.tmp
  fi
}

# Here I have three variables:
#   platforms
#   logdirs
#   packagefiles
# turn them into arrays

lispsystemsarray=($lispsystems)
platformsarray=($platforms)
logdirsarray=($logdirs)
packagefilesarray=($packagefiles)
count=${#platformsarray[@]}
let count=$count-1

firstlogdir=""

runthetest() {
# If I am just reporting timings from previous runs I do not want to do
# the actual testing.
  if test "$just_times" = "yes"
  then
    return
  fi
# Now for each platform I will test the package I am dealing with.
  pkg1="$pkg"
  for i in `seq 0 $count`
  do
    lispsystem=${lispsystemsarray[$i]}
    platform=${platformsarray[$i]}
    logdir=${logdirsarray[$i]}
    packagefile=${packagefilesarray[$i]}
    if test "$pkg1" = "regressions"
    then
      loader=""
      dir="regressions"
      pkg=$reg
    else
      w=`grep " test " $here/packages/$packagefile | grep "($pkg "`
      case $w in
      *$pkg* | *$pkg1*)
        ;;
      *)
# Note that if the user has specified a custom package.map file this
# can happen in one case even if not in others.
        printf "Package $pkg does not exist for testing purposes\n"
        exit 1
        ;;
      esac
# "core" packages do not need to be pre-loaded. Ideally all others
# would autoload, but I am not going to count on that.
      case $w in
      " core ")
        loader=""
        ;;
      *)
        loader="load $pkg;"
        ;;
      esac
# Now the line in package.map will have a string that is the directory
# within .../reduce-algebra/packages that this package will be stored
# in. Again note that --pkgmap means this could not have been
# sorted out earlier.
      dir=${w%\"*}
      dir=${dir#*\"}
    fi

# If I am running on Windows I need to have the file name in
# (close to) native windows form. I can usefully retain "/" rather than
# "\", but eg it will be in the form "d:/directory/file.ext"

    dd="$winhere/packages/$dir"
    testfile="$dd/$pkg.tst"
    optprintf "dir=$dir testfile=$testfile\n"
# To be able to replace full pathnames I generate a version of the path with 
# directory separators / and \ escaped:
    ESCAPED_DIR=`echo $dd | sed -e 's/[\/\\\\]/\\\\&/g'`

# Use /dev/null if the .rlg file doesn't exist
    if test -f "$here/packages/$dir/$pkg.rlg"
    then
      rlgfile="$here/packages/$dir/$pkg.rlg"
    elif test "$skipmissingrlg" != ""
    then
      printf "Missing log file $here/packages/$dir/$pkg.rlg - skipping test!\n"
      exit 1
    else
      rlgfile=/dev/null
    fi

    optprintf "now use $lispsystem in $platform\n"
    optprintf "to test package $pkg from directory $dir sending output to $logdir\n"

    if test "$firstlogdir" = ""
    then
      firstlogdir="$logdir"
    else
      rm -rf  ${firstlogdir%-times}-${logdir%-times}-comparison/*.rlg.diff
    fi
    case $lispsystem in
    csl)
      csltest "$here/$platform/csl/reduce" "$logdir"
# If the command specified "--install" and "--csl" then the log files
# will be installed in the main tree.
      if test "$install" = "yes"
      then
        cat $here/packages/$dir/$pkg.tst > $here/xmpl/$pkg.tst
        cat $logdir/$pkg.rlg $logdir/$pkg.time > $here/xmpl/$pkg.rlg
        cat $logdir/$pkg.rlg $logdir/$pkg.time > $here/packages/$dir/$pkg.rlg
      fi
      ;;
    bootstrapreduce)
      csltest "$here/$platform/csl/bootstrapreduce" "$logdir"
      ;;
    psl)
# At present I do not make use of any options following "--psl" but
# if cross-building etc became "a thing" I could.
      psltest "$here/bin/redpsl" "$logdir"
      ;;

    jlisp)
      jlisptest "reduce.jar" "$logdir"
      ;;
    jlispboot)
      jlisptest "jlispboot" "bootstrapreduce.jar" "$logdir"
      ;;
    *)
      printf "\n+++ Platform $lispsystem not recognized\n"
      exit 1
    esac
  done

# I will show speed ratios. The first specified platform will be used
# as defining the base-line. Thus for instance
#   test1.sh --csl --psl            uses CSL as the base
#   test1.sh --psl --csl --jlisp    uses PSL as the base
# There is no merit in trying to do comparisons if only one system
# had been tested, so I will detect and filter that case...
# If the base absolute time was under 300ms I will not print the time ratio
# as I view it as being potentially unreliable.

# For each test I have run I just need the identity of the log directory,
# but that info is %in logdirectories.

  first=""
  more="no"
  for x in $logdirs
  do
    if test "$first" = ""
    then
      first="$x"
    else
      more="yes"
    fi
  done

# If there is only one test then comparisons are not interesting.

  if test "$more" = "yes"
  then

# Append on the end of the output line a list of speed ratios.
    base=""
    none="yes"
    for logdir in $logdirs
    do
# Each file packageName.showtime will contain just one line of the form
#       ("packageName" cputime gctime)
# where the times are recorded in milliseconds.
      tt=`cat $logdir/$pkg.showtime | \
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
      if test "$ratio" != "" && test "$base" -ge 300 && test "$none" = "no"
      then
        printf "${logdir%-times}:%8s " "$ratio%"
      fi
      none="no"
    done
    printf "\n"

# Now if any test logs disagree (using the first platform to define
# a reference) print messages that explain that fact.
    basedir=""
    for logdir in $logdirs
    do
      if test "$basedir" = ""
      then
        basedir="$logdir"
      else
        mkdir -p ${basedir%-times}-${logdir%-times}-comparison
        diffBw $basedir/$pkg.rlg $logdir/$pkg.rlg > ${basedir%-times}-${logdir%-times}-comparison/$pkg.rlg.diff
        if test -s ${basedir%-times}-${logdir%-times}-comparison/$pkg.rlg.diff
        then
          printf "***** ${basedir%--times} and ${logdir%-times} test logs differ!\n"
        else
          rm -f ${basedir%-times}-${logdir%-times}-comparison/$pkg.rlg.diff
        fi
      fi
    done
  else
# Only one system being tested.
    printf "\n"
  fi
}

if test "$just_times" = "no"
then
  mkdir -p $logdir
  rm -rf $logdir/*.rlg $logdir/showtimes
  echo "showtimes := '(" > $logdir/showtimes
fi

for pkg in $testable
do
  printf "Test %-11s " "$pkg:"
  runthetest
done

for reg in $regressioncases
do
  pkg="regressions"
  printf "Regression test $reg:\n                 "
  runthetest
done

if test "$just_times" = "no"
then
  printf ")\$\nend;\n\n" >> $logdir/showtimes
fi

#######################################################################
# End of code that runs the tests. Now report on results.
#######################################################################

if test "just_times" = "no"
then
  for logdir in $logdirs
  do
    d=`cd $logdir; echo *.rlg.diff`
    if test "$d" != '*.rlg.diff'
    then
      printf "\nDifferences for ${logdir%-times}: `echo $d | sed -e 's/\.rlg\.diff//g'`\n"
    fi
  done

  first=""
  for logdir in $logdirs
  do
    if test "$first" = ""
    then
      first="$logdir"
    else
      d=`cd ${first%-times}-${logdir%-times}-comparison; echo *.rlg.diff`
      if test "$d" != '*.rlg.diff'
      then
        printf "\nDifferences between ${first%-times} and ${logdir%-times}: `echo $d | sed -e 's/\.rlg\.diff//g'`\n"
      fi
    fi
  done

  printf "\n"
fi

reporttime() {
  name=$1
  dir=$2
  total="0"
  opt=""
  if test "`which redcsl 2> /dev/null`" != ""
  then
    red="redcsl"
    opt="-w"
  elif test "`which redpsl 2> /dev/null`" != ""
  then
    red="redpsl"
  else
    red="$here/bin/redcsl"
    opt="-w"
  fi
  "$red" "$opt" <<XXX | grep "^$name"
    symbolic <<
    in "$dir/showtimes"$
    total := for each r in showtimes sum cadr r;
    gctotal := for each r in showtimes sum caddr r;
    terpri();
    prin2 "$name";
    prin2 " ";
    while posn() < 20 do prin2 " ";
    prin2 total; prin2 " ms CPU ";
    while posn() < 40 do prin2 " ";
    prin2 gctotal; prin2 " ms GC";
    terpri();
    quit; >>$
XXX
}

printf "\nSummary of test runs\n"

for logdir in $logdirs
do
  reporttime ${logdir%-times} $logdir
done

exit 0

# end of script
