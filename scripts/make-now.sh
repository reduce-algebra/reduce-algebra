#! /bin/bash

# This arranges that a fresh distribution shapshot will be created fairly
# soon. It is to be used with croncheck.sh and crontab.entry.
#
# The idea is that croncheck.dat holds a date-stemp for the next time that
# a snapshot should be generated.

here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`cd \`dirname "$here"\` ; pwd -P`

printf "make-now.sh invoked at %s\n", "`date`" >> $here/croncheck.log

touch $here/mac-dummy.stamp
rm $here/mac*.stamp
echo `date +%s` > $here/croncheck.dat
