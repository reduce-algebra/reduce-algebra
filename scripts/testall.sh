#! /bin/bash

# Test all package


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

echo $here



packages=`sed -e '/^\%/d' $here/packages/package.map | \
          grep ' test ' | \
          sed -e 's/(//; s/".*//'`
for p in $packages
do
echo "Test package $p"
$here/scripts/test1.sh $p
done

csldiffs=`cd csl-times ; echo *.rlg.diff`
psldiffs=`cd psl-times ; echo *.rlg.diff`

test "$csldiffs" != "*.rlg.diff" && echo "Differences for CSL:" ${csldiffs//.rlg.diff}
test "$psldiffs" != "*.rlg.diff" && echo "Differences for PSL:" ${psldiffs//.rlg.diff}

# end of script




