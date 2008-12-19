#! /bin/sh

#
# Configure the following 3 entries if you need to.
#

VERSION="0.4"
DEST=/usr/local/libtool-cache
BINDIR=/usr/local/bin

case `uname -s` in
*CYGWIN*)
  ;;
*)
  if test "x$LIBTOOLCACHE" != "xyes"
  then
    echo The utility libtoolcache is probably not needed for
    echo platforms other than cygwin, and has certainly not
    echo been tested fully for them. So if you want to run this
    echo install script you must set a shell variable LIBTOOLCACHE
    echo to the string "yes" before running it. This provision is
    echo intended to protect you from inadvertantly installing the
    echo code when you did not need to or want to.
    exit 1
  fi
esac

original=`pwd`

echo This script will try to build and install a command "libtoolcacheize"
echo for you. This can speed up compilation of large packages that use
echo libtool by a very large amount. See http://libtool-cache.sourceforge.net/
echo for more details and in particular to read the disclaimers and instructions
echo that in case of any problem you should so a clean rebuild of your package
echo WITHOUT use of libtoolcache before asking maintainers for any help.

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

if ! test -f $here/libtool-cache-$VERSION.tar.gz
then
  echo File $here/libtool-cache-$VERSION.tar.gz not present.
  exit 1
fi


echo " "
echo I install this in a fixed location for cygwin...
echo See $BINDIR/libtoolcacheize and $DEST

mkdir -p $DEST
cd $DEST

tar xvfz $here/libtool-cache-$VERSION.tar.gz
mv libtool-cache-$VERSION/* .

gcc libtool-wrapper.c -o libtool-wrapper.exe

Z=LTCINSTALLDIR
sed -e \
  "/Edit this script/d;/${Z}=/s+.*+${Z}=${DEST}+" \
  < libtoolcacheize > $BINDIR/libtoolcacheize
chmod +x $BINDIR/libtoolcacheize

cd $original
