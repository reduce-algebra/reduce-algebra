# newlogs.sh

# This expects a full set of log files to have been created locally, and it
# copies them all into the packages directory with a ".new" suffix. This
# is expected to be a foundation for installing a full new set of logs
# in the source tree when a major release is made.

# It is also an illustration that the packages.map file can be processed using
# shell scripts as well as Lisp code is that is useful.

here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`dirname "$here"`
here=`cd "$here"; pwd -P`
here=`dirname "$here"`

grep csl $here/packages/package.map | grep test | \
  sed -e 's,(,$here/scripts/installlogs-sub.sh ,;s,csl,,;s,psl,,;s,test,,;s,),,;;s,core,,;s,         , ,;s,  , ,' > $here/scripts/installlogs.sh

. $here/scripts/installlogs.sh
