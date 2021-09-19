#!/bin/bash

shopt -s globstar nullglob

if test $# = 3; then
    root=$1
    date=$2
    cores=$3
else
    echo "rltestall.sh root date number_of_cores"
    exit 1
fi

timings=$root/$date/timings
redlogtest=$root/$date/trunk/generic/redlogtest
regressions=$root/$date/trunk/packages/redlog/regressions

rm -rf $timings/csl-times $timings/psl-times $timings/csl-psl-times-comparison

cd $regressions

tests=( **/*.tst )

parallel --linebuffer -j$cores $redlogtest/rltest1.sh $root $date {} ::: ${tests[@]}

printf "\ntotal number of tests:\n ${#tests[@]}\n"

printf "\ntotal test time:\n"

exit 0
