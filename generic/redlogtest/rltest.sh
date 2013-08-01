#!/bin/bash

if test $# = 2; then
    root="$1"
    cores="$2"
else
    echo "rltest.sh root number_of_cores"
    exit 1
fi

function log() {
   echo $(date +"%Y-%m-%d %H:%M:%S") [$(pwd)] "$1"
}

log "$0 starting"

date=$(date +%Y-%m-%d)

base=$root/$date
log=$base/log
timings=$base/timings
trunk=$base/trunk
bin=$trunk/generic/redlogtest

log "base    = $base"
log "log     = $log"
log "timings = $timings"
log "trunk   = $trunk"
log "bin     = $bin"

mkdir -p $base
mkdir -p $log 
mkdir -p $timings

cd $base

log "svn co starting"
svn checkout svn://svn.code.sf.net/p/reduce-algebra/code/trunk trunk &> $log/svn-co.log
log "svn co finished"

cd $trunk

log "configure csl starting"
./configure --with-csl --without-gui &> $log/configure-csl.log
log "configure csl finished"

log "configure psl starting"
./configure --with-psl &> $log/configure-psl.log
log "configure psl finished"

log "make starting"
make &> $log/make.log
log "make finished"

cd $timings

log "rltestall.sh starting"
$bin/rltestall.sh $cores &> $log/rltestall.log
log "rltestall.sh finished"

echo

cat $log/rltestall.log

log "rltest.sh finished"
