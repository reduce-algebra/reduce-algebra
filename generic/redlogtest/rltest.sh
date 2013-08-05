#!/bin/bash

if test $# = 3; then
    root="$1"
    cores="$2"
    globallog="$3"
else
    echo "rltest.sh root number_of_cores global_log_dir"
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
regressions=$trunk/packages/redlog/regressions
bin=$HOME/bin

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
\time -p $bin/rltestall.sh $root $date $cores &> $log/rltestall.log
log "rltestall.sh finished"

log "rltestanalyze.sh starting"
$bin/rltestanalyze.sh $root $date $globallog &>$log/rltestanalyze.log
log "rltestanalyze.sh finished"

echo

cat $log/rltestall.log

echo

cat $log/rltestanalyze.log

log "rltest.sh finished"
