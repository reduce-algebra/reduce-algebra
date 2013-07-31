#!/bin/bash
echo $(date): rltest.sh starting
date=$(date +%Y-%m-%d)
root=$HOME/redlogtest
base=$root/$date
log=$base/log
timings=$base/timings
trunk=$base/trunk
bin=$trunk/generic/redlogtest
mkdir $base $log $timings
cd $base
svn checkout svn://svn.code.sf.net/p/reduce-algebra/code/trunk trunk &> svn-co.log
echo $(date): svn co finished
cd $trunk
./configure --with-csl --without-gui &> $log/configure-csl.log
echo $(date): configure csl finished
./configure --with-psl &> $log/configure-psl.log
echo $(date): configure psl finished
make &> $log/make.log
echo $(date): make finished
cd $timings
$bin/rltestall.sh 4  &> $log/rltestall.log
echo $(date): rltestall finished
mail -s "Redlog Test $date" sturm@mpi-inf.mpg.de < $log/rltestall.log
echo $(date): mail sent - rltest.sh finished
