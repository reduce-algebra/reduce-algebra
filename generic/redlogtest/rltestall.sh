#!/bin/bash

# The flags are mostly handled by being passed down to the test1.sh script

if test $# = 3; then
    root=$1
    date=$2
    cores=$3
else
    echo "rltestall.sh [--csl or --psl] root date number_of_cores"
    exit 1
fi

export root
export date
export regressions

timings=$root/$date/timings
trunk=$root/$date/trunk
regressions=$trunk/packages/redlog/regressions

# if test $# = 0
# then
csl="yes"
psl="yes"
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
#       echo "rltestall.sh [--csl or --psl] root date number_of_cores"
#       exit 1
#       ;;
#     esac
#   else
#     echo "rltestall.sh [--csl or --psl] root date number_of_cores"
#     exit 1
#   fi
# fi

#
# Remove old log files
#
rm -rf $timings/csl-times $timings/psl-times $timings/csl-psl-times-comparison

function runregression() {
    p=$1
#    echo "Test regression case $p"
    rltest1.sh $root $date $p
}

export -f runregression

cd $regressions

parallel -j$cores -u runregression {} ::: */*/*.tst

printf "\ntotal test time:\n"
exit

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
