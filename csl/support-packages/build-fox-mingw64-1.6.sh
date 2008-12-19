#! /bin/sh

#
# File: "Build-fox-win64-1.6.sh"           A C Norman, Codemist Ltd, 2006
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

/bin/sh $here/build-fox-1.6.sh --with-mingw64

# done
