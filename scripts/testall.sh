#! /bin/sh

# Test all package

# Usage:
#   scripts/testall.sh [options] [systems-to-test] [[a few package names]]
# Options:             --noregressions --install --keep
#                      --just-time --skip-missing-rlg --no-timeout
# Systems-to-test:     --csl --bootstrapreduce
#                      --csl=XXX --bootstrapreduce=XXX
#                      --jlisp jlispboot
#                      --psl --psl=XXX
# See explanation in scripts/test1.sh regarding valid "XXX" but the
# most common and general use will be if it is a directory name within
# cslbuild or pslbuild.
#
# --noregressions: Arrange that the large number of small regressions tests
#    are not run.
# --install: Install test in the main tree after they are generated.
# --keep: Preserve temporary files used while running the tests, parhaps
#    to help with debugging the test framework.
# --just-time: Do not re-run all the tests but report on timings
#    collected on the last occasion testall.sh was run.
# --skip-missing-rlg: Skip any .tst files that don't have a corresponding
#    .rlg file. Ideally the Reduce tree should not have any cases of this,
#    but when a new package is added sometimes there is a delay before the
#    log file for its test is put in place.
# --no-timeout places no restrictions on the runtime of the tests. This
#    may be especially useful when running tests of cross-build versions
#    via an emulator, since without this option the CPU or wallclock time
#    for each test is capped.
# In normal use one will not give "a few package names" and the script
# will run tests on all packages. An explicit list will especially be
# useful while testing this script so that it does not take the time involved
# in working through everything!

# I want this script to be one I can launch from anywhere, so
# to access files etc I need to know where it lives. The logs directories
# csl-times, psl-times etc are created as sub-directories of the directory
# current when this script was invoked.

here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`dirname "$here"`
here=`cd "$here"; pwd -P`
scripthere="$here"
here=`dirname "$here"`

#######################################################################
# Procedures that sort out directory names for me
#######################################################################

. "$scripthere/getplatform.sh"

# Well I want to tidy up files relating to platforms being tested so I
# do need to scan the argument list and collect them

noregressions="no"
just_time="no"
args_for_test1=""
platforms=""
basecase=""

while test $# != 0
do
  case $1
  in
  --install | --keep | --skip-missing-rlg | --no-timeout)
    args_for_test1="$args_for_test1 $1"
    shift
    ;;
  --noregressions)
    noregressions="yes"
    shift
    ;;
  --just-time)
    just_time="yes"
    shift
    ;;
  --csl* | --bootstrapreduce* | --psl* | --jlisp | --jlispboot)
    platforms="$platforms $1"
    if test "$basecase" = ""
    then
      basecase="$1"
    fi
    shift
    ;;
  *)
    break
    ;;
  esac
done

# Apply default if no platforms specified
if test "$platforms" = ""
then
  platforms="--csl --psl"
  basecase="--csl"
fi

# If the user has explicitly listed some packages to test then do not
# include the regrssions.

if test $# != 0
then
  noregressions="yes"
fi

baseplat=`getplatform $basecase`
baselogdir=`getlogdir $baseplat`

if test "$just_time" = "no"
then

#
# Remove old log files
#
  for pp in $platforms
  do
    pp=`getplatform $pp`
    logdir=`getlogdir $pp`
    rm -f $logdir/*.rlg* $logdir/showtimes
    rm -f ${baselogdir%-times}-${logdir%-times}-comparison/*.rlg.diff
    mkdir -p $logdir
    echo "showtimes := '(" > $logdir/showtimes
  done

  if test $# != 0
  then
    packages=$*
  else
    packages=`sed -e '/^\%/d' $here/packages/package.map | \
              grep ' test ' | \
              sed -e 's/(//; s/".*//'`
  fi

  for pkg in $packages
  do
    $scripthere/test1.sh $args_for_test1 $platforms $pkg
  done

  if test "$noregressions" = "no"
  then
    for pkg in $here/packages/regressions/*.tst
    do
      pkg=${pkg%.tst}
      pkg=${pkg##*/}
      $scripthere/test1.sh $args_for_test1 $platforms regressions $pkg
    done
  fi

  for pp in $platforms
  do
    pp=`getplatform $pp`
    logdir=`getlogdir $pp`
    echo ")\$ end\$" >> $logdir/showtimes
  done
fi

printf "\nSummary of test runs\n"

if test "$just_time" = "no"
then
  for pp in $platforms
  do
    pp=`getplatform $pp`
    logdir=`getlogdir $pp`
    d=`cd $logdir; echo *.rlg.diff`
    if test "$d" != '*.rlg.diff'
    then
      printf "\nDifferences for ${logdir%-times}: `echo $d | sed -e 's/\.rlg\.diff//g'`\n"
    fi
  done

  for pp in $platforms
  do
    pp=`getplatform $pp`
    logdir=`getlogdir $pp`
    if test "$logdir" != "$baselogdir"
    then
      d=`cd ${baselogdir%-times}-${logdir%-times}-comparison; echo *.rlg.diff`
      if test "$d" != '*.rlg.diff'
      then
        printf "\nDifferences between ${baselogdir%-times} and ${logdir%-times}: `echo $d | sed -e 's/\.rlg\.diff//g'`\n"
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

for pp in $platforms
do
  pp=`getplatform $pp`
  logdir=`getlogdir $pp`
  reporttime ${logdir%-times} $logdir
done

# end of script
