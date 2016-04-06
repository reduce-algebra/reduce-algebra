#! /bin/bash
# This script will be run roughly every 10 minutes while my computer
# is switched on. It will arrange that about once per week it will
# regenerate snapshots of Reduce. See crontab.entry

# I want this script to be one I can launch from anywhere, but at least
# some of its sub-scripts will not be so generous. So find out where it
# lives so that other locations can be found relative to that.
here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`cd \`dirname "$here"\` ; pwd -P`

# Find what the time is now and when the next snapshot is due...

req=`cat $here/croncheck.dat 2>/dev/null`
now=`date +%s`
if test "x$req" = "x"
then
  req=0
fi

# If either the last set of snapshots are less than (about) a week old
# or if it is 10pm or later I will not do anything just now. The limitation
# on late-night processing is so that the creation of snapshots will
# tend not to happen over the time when the clock moves from one day to
# the next. And perhaps because there seems more of a risk that I will switch
# my computer off as the evening wears on.
if test $now -lt $req || \
   test `date %H` -gt 21
then
  left=$((($req - $now) / 3600))
# I will keep an old version of the logf, but then preserve just the last 20
# lines from it.
  mv $here/croncheck.log $here/croncheck.log.old
  tail -20 $here/croncheck.log.old > $here/croncheck.log
  printf "Time %s (%d hours to go)\n" "`date`" $left >> $here/croncheck.log
# printf "Nothing needs doing right now (%s:%s:%s)\n" `whoami` `pwd` $USER >> croncheck.log
  exit 0
fi
printf "Time %s run croncheck task (%s:%s:%s)\n" "`date`" `whoami` `pwd` $USER >> $here/croncheck.log

# Arrange that the next attempt to build will not happen for another week.
next=$(($now + 600000))
printf "$next" > $here/croncheck.dat

# I do the bulk of the work in a separate file croncheck1.sh and keep
# a log of all the output it creates. Note that this is run on a Macintosh
# hence the exact order of arguments passed to the "script" command.

script $here/croncheck1.log bash -v $here/croncheck1.sh

exit 0
