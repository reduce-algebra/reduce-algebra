#! /bin/sh

echo "======================================================"
echo " This builds a version of the FOX library that runs   "
echo " linked with cygwin1.dll and that needs and X server  "
echo " active for it to be useful. It is NOT the one that   "
echo " most people will want.  See build-all.sh for the     "
echo " version that I really expect you to use on both Unix "
echo " and Windows styles of platform.                      "
echo "======================================================"
#
# File: "build-fox-debug-cygwin-1.6.sh"   THIS BUILDS FOR CYGWIN IN A WAY THAT
# REQUIRES AN X SERVER AND LINKS IN GPL LIBRARIES. THE RESULTING
# BINARIES MAY NOT BE DISTRIBUTED BUT THIS MAY NEVERTHELESS BE USEFUL
# FOR SOME DEBUGGING.
#

# This script fragment sets "here" to the directory it is in
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

/bin/sh $here/build-fox-1.6.sh --enable-debug --with-cygwin

# done
