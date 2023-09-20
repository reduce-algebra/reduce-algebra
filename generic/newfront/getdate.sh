#! /bin/bash

# This finds the most recent checkin date from among all the
# C header and source files.

for f in ${1:-.}/*.h ${1:-.}/*.c
do
  for x in `grep '$Id:' $f`
  do
    case $x in
    *-*-*)
      d=$x
      ;;
    esac
  done
  echo \"$d\"
done | sort | tail -1
