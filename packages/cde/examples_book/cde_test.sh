#!/bin/bash
# Lecce, 22 February 2015
# This is a script for regenerating result and debug files for the
# enclosed examples of CDE computations.
# Its main use is as a suite of regression tests, i.e.
# checking that new versions of the systems are computing in the right way.
#
# logs output and errors in the file cdiff.log
exec 1>cde_test.log 2>&1
mkdir -p resultsnew
mkdir -p statenew
mkdir -p diff_out
for elm in *.red; do
    if [ $elm != cde.red ]; then
       redcsl -w $elm
       filename=${elm%.*}
       mv $(echo $filename)_state.red statenew 2> /dev/null
       mv $(echo $filename)_res.red resultsnew 2> /dev/null
    fi
done
if [ -d ./results ]; then
   for elm in *.red; do
      if [ $elm != cde.red ]; then
         filename=${elm%.*}
         diff ./resultsnew/$(echo $filename)_res.red \
              ./results/$(echo $filename)_res.red \
              > $(echo $filename)_res.diff
      fi
   done
fi
if [ -d ./state ]; then
   for elm in *.red; do
      if [ $elm != cde.red ]; then
         filename=${elm%.*}
         diff ./statenew/$(echo $filename)_state.red \
              ./state/$(echo $filename)_state.red \
              > $(echo $filename)_state.diff
      fi
   done
fi
mv *.diff diff_out
exit

