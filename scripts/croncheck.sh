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

# If the last set of snapshots are less than (about) a week old
# I will not do anything just now.
if test $now -lt $req
then
  left=$((($req - $now + 3599) / 3600))
  prevlog=`tail -1 $here/croncheck.log`
  if test $left -lt 4
  then
    newmsg="About $left hours before next snapshot"
  elif test $left -lt 12
  then
    newmsg="Less than 12 hours until next snapshot"
  elif test $left -lt 24
  then
    newmsg="Less than a day until next snapshot"
  else
    daysleft=$(($left / 24))
    newmsg="About $daysleft days until next snapshot"
  fi
  if test "$newmsg" = "$prevlog"
  then
    exit 0
  fi
# I will keep an old version of the log, but then preserve just the last 30
# lines from it.
  mv $here/croncheck.log $here/croncheck.log.old
  tail -30 $here/croncheck.log.old > $here/croncheck.log
  printf "$newmsg\n" >> $here/croncheck.log
  exit 0
fi
printf "Starting snapshot build at %s\n" "`date`" >> $here/croncheck.log

# Arrange that the next attempt to build will not happen for another week.
next=$(($now + 600000))
printf "$next" > $here/croncheck.dat
nextdate=`date -j -f %s $next`
printf "Next build scheduled for $nextdate\n" >> $here/croncheck.log

# I do the bulk of the work in a separate file croncheck1.sh and keep
# a log of all the output it creates. Note that this is run on a Macintosh
# hence the exact order of arguments passed to the "script" command.

script $here/croncheck1.log bash -v $here/croncheck1.sh

exit 0
