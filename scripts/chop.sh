#! /usr/bin/env bash

# Usage scripts/chop.sh Nlow Nhigh

# $ Id: $

# This is a little script I have developed to help me debug some horrid
# things. You put another script called bad1.sh where this can find it,
# sunce that bad1.sh will run and report either success or failure in its
# return code. bad1.sh should take a single numeric argument. Used via this
# a binary chop is applied between Nlow and NHigh to identify a critical
# value for that argument.
#
# I have used this technique by hand before where the argument has been a
# revision number and the script goes basically
#     svn -R revert .; svn -r $1 update; rm -rf cslbuild
#     ./configure --with-csl; make; <run some particular test>
#     exec grep Error <the test log file>
# And one needs in that case to take some care with revisions that
# represented transitory states where the system fails to compile.
#
# CSL also has a (now) command-line option --gc-trigger=NNNN that can force
# exactly where a (typically first) garbage collection is triggered, and for
# chasing storage management issues searching for a critical value of that
# may sometimes help.
#
# Of course the two initial calues Nlow and Nhigh must span a change, so that
# bad1.sh will fail for one and succed for the other. This script makes its
# own test to see which way round that is, so you do not have to worry too
# much about the sense of the GO/noGO test.


a=${1:-100000}
b=${2:-3100000}

if ./bad1.sh $a
then
  aok="yes"
else
  aok="no"
fi

if ./bad1.sh $b
then
  bok="yes"
else
  bok="no"
fi

case "$aok$bok"
in
  yesno)
    up="yes"
    ;;
  noyes)
    up="no"
    ;;
  *)
    echo "Results at both starting and ending point match"
    echo "Thus no binary chop possible"
    ;;
esac

echo "Search from $a to $b" > chop.log

while [ $a -ne $b ]
do
  (( c = ($a + $b)/2 ))
  echo probe at $c

  printf "probe at $c " >> chop.log

  if test "$up" = "yes"
  then
    if ./bad1.sh $c
    then
      printf "script succeeds\n" >> chop.log
      (( a = $c + 1 ))
    else
      printf "script fails\n" >> chop.log
      (( b = $c ))
    fi
  else
    if ! ./bad1.sh $c
    then
      printf "script fails\n" >> chop.log
      (( a = $c + 1 ))
    else
      printf "script succeeds\n" >> chop.log
      (( b = $c ))
    fi
  fi

done