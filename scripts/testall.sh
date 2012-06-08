#! /bin/sh

# Test all package

# Usage:
#    scripts/testall.sh         test everything
#    scripts/testall.sh --csl   test just the CSL version
#    scripts/testall.sh --psl   test just the PSL version

# The flags are mostly handled by being passed down to the test1.sh script

if test $# = 0
then
  csl="yes"
  psl="yes"
else
  if test $# = 1
  then
    case $1 in
    --csl)
      csl="yes"
      psl="no"
      ;;
    --psl)
      csl="no"
      psl="yes"
      ;;
    *)
      echo "scripts/testall.sh [--csl or --psl]"
      exit 1
      ;;
    esac
  else
    echo "scripts/testall.sh [--csl or --psl]"
    exit 1
  fi
fi

# I want this script to be one I can launch from anywhere, so
# to access files etc I need to know where it lives.

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
here=`echo $here | sed -e 's+/[^/]*$++'`

packages=`sed -e '/^\%/d' $here/packages/package.map | \
          grep ' test ' | \
          sed -e 's/(//; s/".*//'`
for p in $packages
do
  echo "Test package $p"
  $here/scripts/test1.sh $* $p
done

for p1 in $here/packages/regressions/*.tst
do
  p=${p1%.tst}
  p=${p##*/}
  echo "Test regression case $p"
  $here/scripts/test1.sh $* regressions $p
done

if test "$csl" = "yes"
then
  csldiffs=`cd csl-times ; echo *.rlg.diff`
fi
if test "$psl" = "yes"
then
  psldiffs=`cd psl-times ; echo *.rlg.diff`
fi
if test "$csl" = "yes" && test "$psl" = "yes"
then
  cslpsldiffs=`cd csl-psl-times-comparison ; echo *.rlg.diff`
fi

echo
if test "$csl" = "yes"
then
  if test "$psl" = "yes"
  then
    echo "Summary of CSL and PSL test runs"
    echo "================================"
    echo
    test "$csldiffs" != "*.rlg.diff" && echo "Differences for CSL:" ${csldiffs//.rlg.diff}
    echo
    test "$psldiffs" != "*.rlg.diff" && echo "Differences for PSL:" ${psldiffs//.rlg.diff}
    echo
    test "$cslpsldiffs" != "*.rlg.diff" && echo "Differences between CSL and PSL :" ${cslpsldiffs//.rlg.diff}
  else
    echo "Summary of CSL test runs"
    echo "========================"
    echo
    test "$csldiffs" != "*.rlg.diff" && echo "Differences for CSL:" ${csldiffs//.rlg.diff}
  fi
else
  echo "Summary of PSL test runs"
  echo "========================"
    test "$psldiffs" != "*.rlg.diff" && echo "Differences for PSL:" ${psldiffs//.rlg.diff}
    echo
fi
echo

# end of script




