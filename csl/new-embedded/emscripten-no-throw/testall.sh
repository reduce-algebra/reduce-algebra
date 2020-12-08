#! /bin/sh

# Test all package

# Usage:
#   scripts/testall.sh 
#

here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`dirname "$here"`
here=`cd "$here"; pwd -P`
here=`dirname "$here"`
here=`cd "$here"; pwd -P`
here=`dirname "$here"`

# Well I want to tidy up files relating to platforms being tested so I
# do need to scan the argument list and collect them

noregressions="no"
if test "x$1" = "x--noregressions"
then
  noregressions="yes"
  shift
fi

#
# Remove old log files
#
rm -f jscsl-times/*.rlg*

packages=`sed -e '/^\%/d' $here/../packages/package.map | \
          grep ' test ' | \
          sed -e 's/(//; s/".*//'`

for p in $packages
do
  echo "Test package $p"
  ./test1.sh $p
done

if test "$noregressions" = "no"
then
  for p1 in $here/../packages/regressions/*.tst
  do
    p=${p1%.tst}
    p=${p##*/}
    echo "Test regression case $p"
    ./test1.sh regressions $p
  done
fi

printf "\nSummary of test runs for jscsl\n\n"

d=`cd jscsl-times; echo *.rlg.diff`
if test "$d" != "*.rlg.diff"
then
  printf "\nDifferences for jscsl: `echo $d | sed -e 's/\.rlg\.diff//g'`\n"
fi

printf "\n"

reporttime() {
  name=$1
  dir=$2
  total="0"
  for x in $dir/*.time
  do
    val=`grep ^Time $x | sed -e 's/.*(counter 1): //; s/ms.*//'`
# The apparently spurious "0" here is in case $val ends up as empty.
    total=`printf "1k 0 $val $total + pq" | dc`
  done
  total=`printf "2k $total 1000 / pq" | dc`
  printf "$name total = $total (seconds)\n"
}

if test "x`which dc`" != "x"
then
  reporttime "JSCSL" "jscsl-times"
fi

# end of script

