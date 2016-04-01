#! /bin/bash

# This arranges that a fresh distribution shapshot will be created fairly
# soon. It is to be us3ed with croncheck.sh and crontab.entry.
#
# The idea is that croncheck.dat holds a date-stemp for the next time that
# a snapshot should be generated.

touch mac-dummy.stamp
rm mac*.stamp
echo `date +%s` > croncheck.dat
