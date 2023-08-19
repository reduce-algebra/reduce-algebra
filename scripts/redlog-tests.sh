#! /bin/bash

# This is a simple script to use some test examples as regression tests
# for Reduce as a whole so that their behaviour can be confirmed when CSL,
# PSL or parts of Reduce other than redlog change.
#
# The redlog/benchmark directory contains a number of tests where the
# redlog developers have schemes to use these for benchmarking - see
# the generic/rbench directory.
#
# Note that these test scripts are constrained by a restrictive
# license rather than the BSD license used for the bulk of Reduce. They
# may be redistributed, but "derivatives" may not be redistributed and
# the files may not be used for commercial purposes.
# Well the files themselves are not being distributed in any way beyond their
# existing publication within the Reduce tree - but because of the license
# constraints it is not possible to provide reference output files
# to accompany them - those would be "derivative material". So anybody
# wishing to use this may need to create their own set of logs by going
#    scripts/redlog-tests.sh install
# but of course then they do not have a simple way of verifying that things
# have run correctly. But they can then re-run the tests later after
# altering some other part of Reduce and see if anything has changed.
# 

# At present a number of the tests fail at least when run on Windows
# because of whitespace in the path to the installed version of Reduce
# leading to issues when the code tries to invoke "awk". I view this as
# an issue that should be for redlog to address. There are further
# problems when files from SUPPORT are included, and as will be the case
# for most others I do not have a wayo to convince myself that things are
# otherwise OK. But this as is can be a start that can maybe be improved on
# in the future!

# The first checkin will just support CSL, but adaptation to provide
# --csl and --psl flags so that PSL can also be exercised can come later.

# Timeout setting that limits each individual test. This should prevent
# things from getting stuck!
TIME=60

here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`dirname "$here"`
here=`cd "$here"; pwd -P`
scripthere="$here"
here=`dirname "$here"`

case $* in
*install*)
  install=true
  ;;
esac

if test -f /usr/bin/cygpath
then
  winhere=`cygpath -m "$here"`
else
  winhere="$here"
fi

if ! test -d $here/redlog-tests/redlog-tests
then
  mkdir -p $here/redlog-tests/redlog-tests
fi

if ! test -d $here/SUPPORT
then
# Must be moved here by user and should probably not be distributed in
# this location without full care over eg "a link to the license" and
# confirmation that the files have not been changed.
  cp -r $here/packages/redlog/benchmark/reals/doi/10.1007/s11786-020-00479-9/SUPPORT .
fi

pushd $here/redlog-tests/redlog-tests > /dev/null
tests=`find "$here/packages/redlog/benchmark" -name \*.red`

echo "+++ Redlog tests +++"
count=1
for x in $tests
do
  logdir="$count-`basename ${x%red}log`"
  echo Test ${logdir%.log}
# Use an installed versiun of Reduce. Note that I have a symbolic
# link to make scripting this simple for me:
# /usr/local/bin/redcsl -> /cygdrive/C/Program Files/Reduce/lib/csl/reduce.exe
  echo "on echo;" > /tmp/test.red
  cat $x >> /tmp/test.red
  timeout $TIME redcsl -w /tmp/test.red -- "$logdir" > /dev/null
  sed -i -e "1d" "$logdir"
  if test "$install" = "true"
  then
    mv $logdir ${logdir%log}rlg 
  else
    if ! diff $logdir ${logdir%log}rlg > /tmp/diffs
    then
      mv /tmp/diffs ${logdir%log}diff
      echo Difference in $logdir
    fi
  fi
  if test "$count" = "$1"
  then
    break
  fi
  let count=$count+1
done

popd > /dev/null
