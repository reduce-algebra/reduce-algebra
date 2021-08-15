#!/bin/bash

if test $# = 3; then
    root="$1"
    cores="$2"
    save="$3"
    break=""
elif test $# = 4; then
    root="$1"
    cores="$2"
    save="$3"
    break="$4"
else
    echo "rltest.sh root number_of_cores global_log_dir"
    exit 1
fi

function log() {
   echo $(date +"%Y-%m-%d %H:%M:%S") [$(pwd)] "$1"
}

log "$0 starting"

date=$(date +%Y-%m-%d)

bin=$HOME/bin
base=$root/$date
log=$base/log
timings=$base/timings
trunk=$base/trunk
regressions=$trunk/packages/redlog/regressions

log "bin         = $bin"
log "root        = $root"
log "base        = $base"
log "log         = $log"
log "timings     = $timings"
log "trunk       = $trunk"
log "regressions = $regressions"
log "save        = $save"
log "cores       = $cores"
log "break       = $break"

mkdir -p $base
mkdir -p $log 
mkdir -p $timings

cd $base

log "starting svn co"
svn checkout svn://svn.code.sf.net/p/reduce-algebra/code/trunk trunk &> $log/svn-co.log
#log "svn co finished"

if [ -d $trunk ]; then
    cd $trunk
    log "svn revision is $(svn info | awk '/^Revision/ {print $2}')" 
else
    log "$trunk does not exist, svn co appears to have failed, exiting"
    exit 1
fi    

samplefile=./packages/redlog/rl/redlog.red
if [ ! -f $samplefile ]; then
    log "$samplefile does not exist, svn co appears to have failed, exiting"
    exit 1
fi

log "correcting time stamps"
./scripts/stamp.sh &> /dev/null
if [ $? -ne 0 ]; then
    log "stamp.sh failed, exiting"
    exit 1
fi

log "starting configure"
(./configure --with-csl --without-gui &> $log/configure-csl.log) &
(./configure --with-psl &> $log/configure-psl.log) &
wait
if [ $? -ne 0 ]; then
    log "configure failed, exiting"
    exit 1
fi
#log "configure csl finished"

# log "starting configure csl"
# ./configure --with-csl --without-gui &> $log/configure-csl.log
# if [ $? -ne 0 ]; then
#     log "configure csl failed, exiting"
#     exit 1
# fi
# #log "configure csl finished"

pushd cslbuild &> /dev/null
log "creating symlink without '-nogui' postfix"
ln -s *-nogui $(basename *-nogui -nogui)
if [ $? -ne 0 ]; then
    log "symlink failed, exiting"
    exit 1
fi
#log "configure csl finished"
popd &> /dev/null

pushd cslbuild/*/csl &> /dev/null
log "skipping csl profiling"
#make profile &> $log/csl-profiling.log
#if [ $? -ne 0 ]; then
#log "csl profiling, exiting"
#exit 1
#fi
popd &> /dev/null

# log "starting configure psl"
# ./configure --with-psl &> $log/configure-psl.log
# if [ $? -ne 0 ]; then
#     log "configure psl failed, exiting"
#     exit 1
# fi
# #log "configure psl finished"

log "starting make"
#arch=$(./scripts/findhost.sh $(./config.guess))
(let cslcores=$cores-1; make csl &> $log/make-csl.log) &
(make psl &> $log/make-psl.log) &
wait
# make &> $log/make.log
if [ $? -ne 0 ]; then
    log "make failed, exiting"
    exit 1
fi
#log "make finished"

log "patching pslmem64.sh"
hide=$RANDOM
mv -f ./scripts/pslmem64.sh ./scripts/pslmem64.sh-$hide
cp ./generic/redlogtest/pslmem64.sh ./scripts
#log "patch pslmem64.sh finished"

cd $timings

log "starting rltestall.sh"
\time -p $bin/rltestall.sh $root $date $cores &> $log/rltestall.log
#log "rltestall.sh finished"

log "starting rltestanalyze.sh"
$bin/rltestanalyze.sh $root $date $save &> $log/rltestanalyze.log
#log "rltestanalyze.sh finished"

if test "$break" = "break"; then
    log "exiting on 'break' for debugging - please delete $base later"
    exit 1
fi

cd $base

if [ -e "./trunk" ]; then
    log "deleting ./trunk"
    \rm -rf "./trunk"
#    log "deleting ./trunk finished"
fi

cd $root

log "compressing and saving ./$date to $save/$date.tgz"
tar czf $save/$date.tgz ./$date 
#log "finished compressing and saving ./$date"


if [ -e "./$date" ]; then
    log "deleting ./$date"
    \rm -rf "./$date"
#    log "deleting ./$date finished"
fi

cd $save

log "dumping logs from ./${date}.tgz"

echo

tar xvOf $date.tgz ./$date/log/rltestall.log

echo

tar xvOf $date.tgz ./$date/log/rltestanalyze.log

log "rltest.sh finished"
