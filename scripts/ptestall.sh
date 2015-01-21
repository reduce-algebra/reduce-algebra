#! /bin/bash

# Test all package

# Usage:
#    scripts/testall.sh         test everything
#    scripts/testall.sh --csl   test just the CSL version
#    scripts/testall.sh --psl   test just the PSL version

# The flags are mostly handled by being passed down to the test1.sh script

if test $# = 1; then
    cores="$1"
    csl="yes"
    psl="yes"
else
    echo "scripts/ptestall.sh number_of_cores"
    exit 1
fi

# I want this script to be one I can launch from anywhere, so
# to access files etc I need to know where it lives.

here=`dirname "$0"`
here=`cd "$here" ; pwd`
here=`dirname "$here"`

export here

# if test $# = 0
# then
#   csl="yes"
#   psl="yes"
# else
#   if test $# = 1
#   then
#     case $1 in
#     --csl)
#       csl="yes"
#       psl="no"
#       ;;
#     --psl)
#       csl="no"
#       psl="yes"
#       ;;
#     *)
#       echo "scripts/testall.sh [--csl or --psl]"
#       exit 1
#       ;;
#     esac
#   else
#     echo "scripts/testall.sh [--csl or --psl]"
#     exit 1
#   fi
# fi


#
# Remove old log files
#
rm -f csl-times/*.rlg* psl-times/*.rlg* csl-psl-times-comparison/*.rlg.diff

packages=`sed -e '/^\%/d' $here/packages/package.map | \
          grep ' test ' | \
          sed -e 's/(//; s/".*//'`

# for p in $packages
# do
#   echo "Test package $p"
#   $here/scripts/test1.sh $* $p
# done

function runtest() {
    echo "Test package $1"
    $here/scripts/ptest1.sh $1
}

export -f runtest

parallel -j$cores runtest {} ::: $packages

# for p1 in $here/packages/regressions/*.tst
# do
#   p=${p1%.tst}
#   p=${p##*/}
#   echo "Test regression case $p"
#   $here/scripts/test1.sh $* regressions $p
# done

function runregression() {
    p1=$1
    p=${p1%.tst}
    p=${p##*/}
    echo "Test regression case $p"
    $here/scripts/ptest1.sh regressions $p
}

export -f runregression

parallel -j$cores runregression {} ::: $here/packages/regressions/*.tst

if test "$csl" = "yes"
then
  csldiffs=`cd csl-times ; echo *.rlg.diff`
fi
if test "$psl" = "yes"
then
  psldiffs=`cd psl-times ; echo *.rlg.diff`
fi
if test "$csl" = "yes" && test "$psl" = "yes"
then
  cslpsldiffs=`cd csl-psl-times-comparison ; echo *.rlg.diff`
fi

echo
if test "$csl" = "yes"
then
  if test "$psl" = "yes"
  then
    echo "Summary of CSL and PSL test runs"
    echo "================================"
    echo
    test "$csldiffs" != "*.rlg.diff" && echo "Differences for CSL:" `echo $csldiffs | sed -e 's/\.rlg\.diff//g'`
    echo
    test "$psldiffs" != "*.rlg.diff" && echo "Differences for PSL:" `echo $psldiffs | sed -e 's/\.rlg\.diff//g'`
    echo
    test "$cslpsldiffs" != "*.rlg.diff" && echo "Differences between CSL and PSL :" `echo $cslpsldiffs | sed -e 's/\.rlg\.diff//g'`
  else
    echo "Summary of CSL test runs"
    echo "========================"
    echo
    test "$csldiffs" != "*.rlg.diff" && echo "Differences for CSL:" `echo $csldiffs | sed -e 's/\.rlg\.diff//g'`
  fi
else
  echo "Summary of PSL test runs"
  echo "========================"
    test "$psldiffs" != "*.rlg.diff" && echo "Differences for PSL:" `echo $psldiffs | sed -e 's/\.rlg\.diff//g'`
    echo
fi
echo

# end of script




