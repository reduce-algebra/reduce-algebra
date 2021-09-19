#!/bin/bash

if [ $# -ne 1 ]; then
	echo usage: $0 date.tgz
	exit 1
fi

date=$(basename "$1" .tgz)

if [ ${date}.tgz != "$1" ]; then
	echo usage: $0 date.tgz
	exit 1
fi

here=$(pwd)

tarfile=$(pwd)/"$1"

cd /tmp

tar xf $tarfile

if [ ! -d $date/timings/csl-times ]; then
	echo "no csl-times directory at the expected position - exiting"
	exit 1
elif [ ! -d $date/timings/psl-times ]; then
	echo "no psl-times directory at the expected position - exiting"
	exit 1
fi

timeupdate=$here/timeupdate-${date}.tar

if [ -e $timeupdate ]; then
	echo "found existing file $timeupdate - exiting"
	exit 1
fi

echo "packing CSL times"

cd /tmp/$date/timings

ln -s csl-times regressions

for timefile in $(find -H ./regressions -name "*.time"); do
	csltimefile=$(echo $timefile | sed 's/time/csltime/')
	cp $timefile $csltimefile
	tar rf $timeupdate $csltimefile
done

echo "packing PSL times"

rm regressions

ln -s psl-times regressions

for timefile in $(find -H ./regressions -name "*.time"); do
	psltimefile=$(echo $timefile | sed 's/time/psltime/')
	cp $timefile $psltimefile
	tar rf $timeupdate $psltimefile
done

echo "compressing and cleaning up"

gzip $timeupdate

cd /tmp

rm -rf /tmp/$date
