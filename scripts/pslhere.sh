#! /bin/sh
# I want this script to be one I can launch from anywhere, but it
# needs to know where it lives so it can chain down to a file that is
# at a location relative to it.
here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`cd \`dirname "$here"\` ; pwd -P`

STORE=16000000
if test -f $here/psl/psl/64
then
  STORE=1000
fi
export fasl="$here/psl/red"
export reduce="$here"
if ! ulimit -s unlimited 2> /dev/null
then
  if ! ulimit -s 65000 2> /dev/null
  then
    if ! ulimit -s 32000 2> /dev/null
    then
      ulimit -s 16000 2> /dev/null
    fi
  fi
fi
exec $here/psl/psl/bpsl -td $STORE -f $here/psl/red/reduce.img $*
