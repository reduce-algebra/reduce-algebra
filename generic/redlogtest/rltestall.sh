#!/bin/bash

if test $# = 3; then
    root=$1
    date=$2
    cores=$3
else
    echo "rltestall.sh root date number_of_cores"
    exit 1
fi

qe=/CW/local/QE/qepcad/qesource
PATH=$PATH:$qe/bin

timings=$root/$date/timings
trunk=$root/$date/trunk
regressions=$trunk/packages/redlog/regressions

rm -rf $timings/csl-times $timings/psl-times $timings/csl-psl-times-comparison

cd $regressions

tests=(*/*/*.tst)

parallel -j$cores -u $trunk/generic/redlogtest/rltest1.sh $root $date {} ::: ${tests[@]}

printf "\ntotal number of tests:\n ${#tests[@]}\n"

printf "\ntotal test time:\n"

exit 0
