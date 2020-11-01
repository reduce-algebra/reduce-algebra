#! /bin/bash

# This re-creates the file "regressions.list" that is a list of all the
# test cases in the packages/regressions directory.

echo "% Sometimes the list-directory function may not be available or may be" > regressions.list
echo "% unsafe. This is a list of regression test files to avoid its use. See" >> regressions.list
echo "% about line 720 of buildreduce.lsp. Every so often this should be updated!" >> regressions.list
echo "" >> regressions.list
echo "% \$Id: \$" >> regressions.list
echo "" >> regressions.list
echo "(setq reduce_regression_tests '(" >> regressions.list

for x in `cd ../../packages/regressions && ls *.tst`
do
  echo "   \"$x\"" >> regressions.list
done

echo "   ))" >> regressions.list



