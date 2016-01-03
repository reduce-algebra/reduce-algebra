#!/bin/bash
s=`basename $0`
[ "x$1" == x ] && echo "Usage: $s foo.red" && exit 2
r=/home/vitolo/Reduce/reduce-algebra/trunk/bin/redcsl
f=`basename $1 .red`
n=`grep "total_order:=[0-9]*" $1 |grep --only-matching "[0-9]*"`
while true; do
l=`echo $f-$n`.log
$r $1 > $l &
r_pid=$!
while ! grep "^***** presence of letop, jetspace too small\!" $l > /dev/null 2>&1 ; do
  sleep 5
  ps --pid $r_pid > /dev/null 2>&1 || exit 0
done
kill $r_pid > /dev/null 2>&1
wait $r_pid 2>/dev/null
n=$[n+1]
sed -i -e "s/total_order:=\([0-9]*\)/total_order:=$n/" $1
done

