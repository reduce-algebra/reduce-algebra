#! /bin/sh

# make a distribution archive

# This script can exist in copies with various different names, and
# use of different names leads to slight differences in its behaviour!
#
#  dist.sh         Create full distribution
#  manifest.sh     create MANIFEST.new and compare with main MANIFEST


# I want a "working" version of "sed" but can not guarantee that
# there is one on the standard path, so I look in plausible places...

if test "x$SED" = "x"
then
  if test -x /opt/sfw/bin/gsed
  then SED=/opt/sfw/bin/gsed
  elif test -x /usr/local/bin/gsed
  then SED=/usr/local/bin/gsed
  elif test -x /usr/bin/gsed
  then SED=/usr/bin/gsed
  else SED=sed
  fi
fi

# Find the location this script lived in.

a=$0
c=unknown
case $a in
/* )
  c=$a  
  ;;
*/* )
  case $a in
  ./* )
    a=`echo $a | $SED -e s+./++`
    ;;
  esac
  c=`pwd`/$a
  ;;
* ) 
  for d in $PATH
  do
    if test -x $d/$a
    then
      c=$d/$a
    fi
  done
  if test $c = "unknown" ;then
    echo "Unable to find full path for script. Please re-try"
    echo "launching it using a fully rooted path."
    exit 1
  fi
  ;;
esac

here=`echo $c | $SED -e 's+/[^/]*$++'`

manifest="no"

case $0 in
*manifest*)
  manifest="yes"
  ;;
esac

# I will tag full archives with today's date
d=`date +%Y%m%d`

f="reduce-algebra-$d"
fbase="reduce-algebra"

# Note that in general "find" does not have to support a "-wholename"
# feature, so when I need to filter on the whole rooted path here I
# drop back to use of "-exec" and a small shell script. By only activating
# this of the "-name" test applies the overall burden is rather small.

$here/resetall.sh

gcc $here/nsort.c -o $here/nsort

here0=`pwd`
cd $here/..

find . \
       -name .svn -prune -o             \
       -name cslbuild -prune -o         \
       -name pslbuild -prune -o         \
       -name csllogs -prune -o          \
       -name psllogs -prune -o          \
       -name libedit-20070831-2.10 -prune -o \
       -name build -prune -o            \
       -name packages-pre-BSD -prune -o \
       -name \*.old -prune -o           \
       \( -name cygwin32                \
          -exec $here/reject.sh ./psl/cygwin32 {} \; \) -prune -o \
       \( -name csl                \
          -exec $here/reject.sh ./generic/redfront/csl {} \; \) -prune -o \
       \( -name psl                \
          -exec $here/reject.sh ./generic/redfront/psl {} \; \) -prune -o \
       \( -name configure                \
          -exec $here/reject.sh ./generic/redfront/configure {} \; \) -prune -o \
       \( -name config.h.in                \
          -exec $here/reject.sh ./generic/redfront/config.h.in {} \; \) -prune -o \
       \( -name autom4te.cache                \
          -exec $here/reject.sh ./generic/redfront/autom4te.cache {} \; \) -prune -o \
       \( -name configure                \
          -exec $here/reject.sh ./generic/libreduce/configure {} \; \) -prune -o \
       \( -name config.h.in                \
          -exec $here/reject.sh ./generic/libreduce/config.h.in {} \; \) -prune -o \
       \( -name autom4te.cache                \
          -exec $here/reject.sh ./generic/libreduce/autom4te.cache {} \; \) -prune -o \
       -name i686-\* -prune -o \
       -name i386-\* -prune -o \
       -name x86_64-\* -prune -o \
       -name powerpc-\* -prune -o \
       -name libedit -prune -o \
       -name libedit-20090111-3.0 -prune -o \
       -name reduce-algebra-\* -prune -o    \
       -name autom4te.cache -prune -o   \
       \( \! \( -name \*.bak -o         \
                -name \*~ -o            \
                -name \*.aux -o         \
                -name \*.dvi -o         \
                -name \*.tmp\* -o       \
                -name \*.old -o         \
                -name rebuild.log -o    \
                -name libreadline\* -o  \
                -name log.log -o        \
                -name csl.log -o        \
                -name xport.chk -o      \
                -name xport.inc -o      \
                -name xport.tm\* -o     \
                -name xport -o          \
                -name nsort -o          \
                -name nsort.exe -o      \
                -name untab -o          \
                -name untab.exe -o      \
                -name reduce-algebra.tar.bz2 -o \
                -name .htaccess -o      \
                -name MANIFEST.new      \
       \) -print \) | $here/nsort > MANIFEST.new


rm -f $here/nsort $here/nsort.exe

if test "$manifest" = "no"
then

  rm -rf $f
  mkdir -p $f

# Doing the copying as here using a shell script is quite painfully
# slow, especially on Windows/cygwin, but I will argue that one does
# not manufacture a new distribution archive so often that this is
# a big problem.

  for x in `cat MANIFEST`
  do
    x0=`echo $x | sed -e 's+./++'`
    if test -d $x0
    then
       if  test "$x0" != "."
       then
          echo Creating $f/$x0
          mkdir -p $f/$x0
       fi
    else
       x1=`echo $x0 | sed -e 's+/[^/]*$++'`
#      echo Copy $x0 to $f/$x1
# Note that the "-p" flag preserves timestamps (and user info and
# access permissions). The timestamps matter for the autoconf-generated
# files.
       cp -p $x0 $f/$x1
    fi
  done

  echo Now create the .tar.bz2 file

  tar cf - $f | bzip2 > $f.tar.bz2
  rm -rf $f

  ln -sf $f.tar.bz2 reduce-algebra.tar.bz2

  ls -lhd ${fbase}*.tar.bz2

fi

if diff MANIFEST MANIFEST.new > /dev/null
then
  echo Files are in step with MANIFEST
  rm -f MANIFEST.new
else
  echo The following files are new or lost:
  diff MANIFEST MANIFEST.new
  echo review MANIFEST please
fi

cd $here0

exit 0


