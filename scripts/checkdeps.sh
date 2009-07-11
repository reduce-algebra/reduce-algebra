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
    a=`echo $a | sed -e s+./++`
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

here=`echo $c | sed -e 's+/[^/]*$++'`

cd $here/..


# Step 1: aclocal.m4 must be later than configure.ac

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


# Step 2: Makefile.in must be newer than aclocal.m4.
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

# Step 3: As step 2, but in cases where aclocal.m4 lives in a parent
#         directory.

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
