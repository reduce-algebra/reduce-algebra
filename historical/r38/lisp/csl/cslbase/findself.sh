#! /bin/sh

# This script fragment sets "here" to the directory it is in. If is
# kept in this form for information - the body of it has been copied into
# a number of the other scripts used here. The intent is so that they
# can be launched from anywhere, with no need to make this directory
# current first.  I might have preferred to keep just one copy of this
# script, but then I would have no obvious way to find it until its own
# purpose and action had been fulfilled!

# Anybody who wants may use or re-use this script for any purpose they like.
#
#    Arthur Norman, August 2006

a=$0; c="unknown"; case $a in
/* ) c=$a ;  ;;
*/* ) case $a in ./* ) a=`echo $a | sed -e 's/\.\///'`; ;; esac
c=`pwd`/$a; ;;
* ) for d in $PATH; do if test -x $d/$a; then c=$d/$a; fi; done
if test $c = "unknown";then
echo "Unable to find full path for script. Please re-try"
echo "launching it using a fully rooted path."
exit 1
fi; ;; esac
here=`echo $c | sed -e 's/\/[^/]*$//'`

# Demonstrate result
echo $here
