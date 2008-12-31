#! /bin/sh

# make a distribution archive

# This script can exist in copies with various different names, and
# use of different names leads to slight differences in its behaviour!
#
#  dist.sh         Create full distribution
#  lgpldist.sh     Create archive of "minimal sources etc" required to
#                  satisfy obligations under the Lesser GNU Public License
#                  version 2.1
#  manifest.sh     create MANIFEST.new and compare with main MANIFEST
#  lgplmanifest.sh create LGPLMANIFEST.new and compare with LGPLMANIFEST


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
    a=${a#./}
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

here=${c%/*}

manifest="no"

case $0 in
*manifest*)
  manifest="yes"
  ;;
esac

lgpl="no"
# I will tag full archives with today's date
d=`date +%Y%m%d`
LGPL=""

f="openreduce-$d"
fbase="openreduce"

case $0 in
*lgpl*)
  lgpl="yes"
  f="lgplfiles"
  fbase="lgplfiles"
  LGPL="LGPL"
  ;;
esac

# Note that in general "find" does not have to support a "-wholename"
# feature, so when I need to filter on the whole rooted path here I
# drop back to use of "-exec" and a small shell script. By only activating
# this of the "-name" test applies the overall burden is rather small.

if test "$lgpl" = "yes"
then
# The following lines characterise material that I will omit when
# creating the "minimal" version of the sources.
  omit1="-name packages -prune -o \
         -name gabriel -prune -o \
         -name libedit -prune -o \
         -name doc -prune -o \
         -name reduce.doc -prune -o \
         -name reduce.fonts -prune -o \
         -name support-packages -prune -o \
         -name bin -prune -o \
         -name fonts -prune -o \
         -name psl -prune -o \
         -name texmacs-plugin -prune -o \
         ( -name foxtests \
           -exec $here/reject.sh ./csl/foxtests {} ; ) -prune -o \
         ( -name doc \
           -exec $here/reject.sh ./csl/fox/doc {} ; ) -prune -o"
  omit2="-name configure -o -name texmacs-plugin.tar.gz -o \
         -name csl.tex -o"
else
  omit1=
  omit2=
  $here/resetall.sh
fi

gcc $here/nsort.c -o $here/nsort

here0=`pwd`
cd $here/..

find . \
       -name .svn -prune -o             \
       -name cslbuild -prune -o         \
       -name pslbuild -prune -o         \
       -name csllogs -prune -o          \
       -name psllogs -prune -o          \
       -name packages-pre-BSD -prune -o \
       -name \*.old -prune -o           \
       \( -name cygwin32                \
          -exec $here/reject.sh ./psl/cygwin32 {} \; \) -prune -o \
       -name openreduce-\* -prune -o    \
       -name lgplfiles\* -prune -o      \
       $omit1                           \
       -name autom4te.cache -prune -o   \
       \( \! \( -name \*.bak -o         \
                -name \*~ -o            \
                -name LGPLMANIFEST.dep -o \
                -name \*.aux -o         \
                -name \*.dvi -o         \
                -name \*.tmp\* -o $omit2 \
                -name \*.old -o         \
                -name rebuild.log -o    \
                -name libreadline\* -o  \
                -name log.log -o        \
                -name csl.log -o        \
                -name xport\* -o        \
                -name nsort -o          \
                -name nsort.exe -o      \
                -name untab -o          \
                -name untab.exe -o      \
                -name openreduce.tar.bz2 -o \
                -name .htaccess -o      \
                -name MANIFEST.new -o   \
                -name LGPLMANIFEST.new  \
       \) -print \) | $here/nsort > ${LGPL}MANIFEST.new


rm -f $here/nsort $here/nsort.exe

if test "$lgpl" = "yes"
then
   $SED -e 's,^\.$,\$(R)/lgplfiles.tar.bz2:,;s,^./,	\$(R)/,;s,$, \\,' < LGPLMANIFEST > LGPLMANIFEST.dep
   echo "" >> LGPLMANIFEST.dep
   echo "# End of dependencies" >> LGPLMANIFEST.dep
fi

if test "$manifest" = "no"
then

  rm -rf $f
  mkdir -p $f

# Doing the copying as here using a shell script is quite painfully
# slow, especially on Windows/cygwin, but I will argue that one does
# not manufacture a new distribution archive so often that this is
# a big problem.

  for x in `cat ${LGPL}MANIFEST`
  do
    x0=${x#./}
    if test -d $x0
    then
       if  test "$x0" != "."
       then
          echo Creating $f/$x0
          mkdir -p $f/$x0
       fi
    else
       x1=${x0%/*}
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

  if test "$lgpl" = "no"
  then
    ln -sf $f.tar.bz2 openreduce.tar.bz2
  fi

  ls -lhd ${fbase}*.tar.bz2

fi

if diff ${LGPL}MANIFEST ${LGPL}MANIFEST.new > /dev/null
then
  echo Files are in step with ${LGPL}MANIFEST
  rm -f ${LGPL}MANIFEST.new
else
  echo The following files are new or lost:
  diff ${LGPL}MANIFEST ${LGPL}MANIFEST.new
  echo review ${LGPL}MANIFEST please
fi

cd $here0

exit 0


