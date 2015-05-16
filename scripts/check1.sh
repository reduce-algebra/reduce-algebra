#! /bin/sh

# Check a package
#
#    scripts/test1.sh [options] package_name
#    scripts/test1.sh [options] regressions testname
#
# The available options are
#
#     --csl       run tests using CSL
#     --psl       run tests using PSL
#     --jlisp     run tests using Jlisp
#     --cslboot   run tests using CSL "bootstrapreduce"
#     --jlispboot run tests using Jlisp "bootstrapreduce.jar"
#
# This assumes that test1.sh has been run (recently) and just does the
# checking of the logs that will have been left behind.

# I want this script to be one I can launch from anywhere, so
# to access files etc I need to know where it lives.

here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`cd \`dirname "$here"\` ; pwd -P`
here=`dirname "$here"`

platform=""

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

p=${1:-alg}

loader=""

# Make sure that all messages are in English
LANG=C ; export LANG


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

# Show some speed ratios
  printf "Speeds: "
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
        printf "***** $base and $sys Test logs differ!\n"
      else rm -f $base-$sys-times-comparison/$p.rlg.diff
      fi
    fi
  done

else
# Only one system being tested.
  printf "\n"
fi

exit 0

# end of test

