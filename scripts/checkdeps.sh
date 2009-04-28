#! /bin/sh

# The following MESS is here to check whether the autoconf-related files
# are all up to date.

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

cd $here/..


# Step 1: aclocal.m4 must be later than configure.ac in directories where
#         libtool is not involved.

srcdir="."

ok="All files seem OK"

for d in . csl csl/cslbase csl/foxtests csl/fox psl psl/support-packages/xport-2.05
do
  c=configure.ac
  if test "$d" = "csl/fox"; then c=configure.in; fi
  if test $srcdir/$d/aclocal.m4 -ot $srcdir/$d/$c
  then
    echo $d/aclocal.m4 is older than $d/$c
    ok=$d/aclocal.m4
  fi
done

# Step 2: aclocal.m4 must be newer that both configure.ac and the
#         libtool-related things in the m4 directory when they
#         exist. In the csl/fox directory the name configure.in is
#         used for historical reasons.

lt="m4/libtool.m4 m4/ltoptions.m4 m4/ltsugar.m4 m4/ltversion.m4 m4/lt~obsolete.m4"

for d in csl csl/fox
do
  for x in $lt
  do
    if test $srcdir/$d/aclocal.m4 -ot $srcdir/$d/$x
    then
      echo "$d/aclocal.m4 was older than $d/$x"
      ok=$d/aclocal.m4
    fi
  done
done


# Step 3: Makefile.in must be newer than aclocal.m4, and that will lead
#         to it being newer than any of the libtool-related m4 files.
#         It must also be newer than Makefile.am.

for d in . csl csl/cslbase csl/foxtests psl psl/support-packages/xport-2.05
do
  if test $srcdir/$d/Makefile.in -ot $srcdir/$d/aclocal.m4
  then
    echo $d/Makefile.in is older than $d/aclocal.m4
    ok=$d/Makefile.in
  fi
  if test $srcdir/$d/Makefile.in -ot $srcdir/$d/Makefile.am
  then
    echo $d/Makefile.in is older than $d/Makefile.am
    ok=$d/Makefile.in
  fi
done

# Step 3a: As step 3, but in cases where aclocal.m4 lives in a parent
#          directory.

for d in csl/fox csl/fox/doc csl/fox/doc/art csl/fox/doc/screenshots csl/fox/include csl/fox/src csl/fox/utils
do
  if test $srcdir/$d/Makefile.in -ot $srcdir/csl/fox/aclocal.m4
  then
    echo $d/Makefile.in is older than csl/fox/aclocal.m4
    ok=$d/Makefile.in
  fi
  if test $srcdir/$d/Makefile.in -ot $srcdir/$d/Makefile.am
  then
    echo $d/Makefile.in is older than $d/Makefile.am
    ok=$d/Makefile.in
  fi
done

# Step 4: config.h.in must be newer than aclocal.m4

for d in csl csl/cslbase
do
  if test $srcdir/$d/config.h.in -ot $srcdir/$d/aclocal.m4
  then
    echo $d/config.h.in is older than $d/aclocal.m4
    ok=$d/config.h.in
  fi
done

# Step 5: configure must be newer than aclocal.m4

for d in . csl csl/cslbase csl/fox csl/foxtests psl psl/support-packages/xport-2.05
do
  if test $srcdir/$d/configure -ot $srcdir/$d/aclocal.m4
  then
    echo $d/configure is older than $d/aclocal.m4
    ok=$d/configure
  fi
done

echo $ok
