#!/bin/bash 

if test $# = 3; then
    root=$1
    date=$2
    rootedp=$3
else
    echo "rltest1.sh root date context/service/test.tst"
    exit 1
fi

export qe=/CW/local/QE/qepcad/qesource
export PATH=$PATH:$qe/bin

timings=$root/$date/timings
trunk=$root/$date/trunk
regressions=$trunk/packages/redlog/regressions
d=$(dirname $rootedp)
p=$(basename $rootedp .tst)

export timecmd="/usr/bin/time -p"

f="$regressions/$d/$p.tst"

pslargs="-td $($trunk/generic/redlogtest/pslmem64.sh)"

# The idea behind applying a ulimit here is to avoid trouble when and if a test
# script loops.
ulimit -c 1800

mkdir -p $timings/csl-times/$d
mkdir -p $timings/psl-times/$d

( howlong=$timings/csl-times/$d/$p.howlong.tmp
  $timecmd sh -c "$trunk/bin/redcsl -w > $timings/csl-times/$d/$p.rlg.tmp" <<EOF 2>$howlong
off int;
symbolic linelength 80;
symbolic(!*redeflg!* := nil);
on errcont;
resettime1;
write "START OF REDUCE TEST RUN"$ in "$f"; write "END OF REDUCE TEST RUN"$
showtime1$
quit$
EOF
  cat $howlong >> $timings/csl-times/$d/$p.rlg.tmp
  rm -f $howlong ) &
( howlong=$timings/psl-times/$d/$p.howlong.tmp
  $timecmd sh -c "$trunk/bin/redpsl $pslargs > $timings/psl-times/$d/$p.rlg.tmp" <<EOF 2>$howlong
off int;
symbolic linelength 80;
symbolic(!*redefmsg := nil);
symbolic(!*redeflg!* := nil);
on errcont;
lisp random_new_seed 1;
resettime1;
write "START OF REDUCE TEST RUN"$ in "$f"; write "END OF REDUCE TEST RUN"$
showtime1$
quit$	
EOF
  cat $howlong >> $timings/psl-times/$d/$p.rlg.tmp
  rm -f $howlong ) &
wait

for lisp in csl psl; do
    sed -e "/^Tested on /,//d" <$regressions/$d/$p.rlg |
	sed -e '/^Total time taken:/d; /^Number of garbage/d' \
	    -e '/^Time: /d; /^CRACK needed :/d; /^time for init/d' \
	    -e '/^+++ levelt compiled/d; /^\*\*\* (levelt): base/d' \
	    -e '/^Request to set constant bitsperword/d' \
	    -e '/^time to formulate/d; /\*\*\* turned off switch/d' \
	    >$timings/${lisp}-times/$d/$p.rlg.orig

    sed -e "1,/START OF REDUCE TEST RUN/d" -e "/END OF REDUCE TEST RUN/,//d" \
	-e "/OMIT/,/TIMO/d" <$timings/${lisp}-times/$d/$p.rlg.tmp | \
	sed -e "1s/^1: //" | sed -e '$s/^1: //' | \
	sed -e '/^Total time taken:/d; /^Number of garbage/d' \
	    -e '/^Time: /d; /^CRACK needed :/d; /^time for init/d' \
	    -e '/^+++ levelt compiled/d; /^\*\*\* (levelt): base/d' \
	    -e '/^Request to set constant bitsperword/d' \
	    -e '/^time to formulate/d; /\*\*\* turned off switch/d' \
	    >$timings/${lisp}-times/$d/$p.rlg

    diff -B -w $timings/${lisp}-times/$d/$p.rlg.orig $timings/${lisp}-times/$d/$p.rlg \
	 >$timings/${lisp}-times/$d/$p.rlg.diff

    echo "Tested on $mc ${lisp}" > $timings/${lisp}-times/$d/$p.time

    sed -e "1,/END OF REDUCE TEST RUN/d"  <$timings/${lisp}-times/$d/$p.rlg.tmp | \
	sed -e '/^1: *$/d;' >>$timings/${lisp}-times/$d/$p.time

    rm -f $timings/${lisp}-times/$d/$p.rlg.tmp
done

if test -s $timings/csl-times/$d/$p.rlg.diff; then
    cslresult="failed"
else
    cslresult="ok"
    rm -f $timings/csl-times/$d/$p.rlg.diff $timings/csl-times/$d/$p.rlg.orig
fi

if test -s $timings/psl-times/$d/$p.rlg.diff; then
    pslresult="failed"
else
    pslresult="ok"
    rm -f $timings/psl-times/$d/$p.rlg.diff $timings/psl-times/$d/$p.rlg.orig
fi

mkdir -p $timings/csl-psl-times-comparison/$d

diff -B -w $timings/csl-times/$d/$p.rlg $timings/psl-times/$d/$p.rlg \
     > $timings/csl-psl-times-comparison/$d/$p.rlg.diff

if test -s $timings/csl-psl-times-comparison/$d/$p.rlg.diff; then
    resultlispdiff=", CSL and PSL test logs differ"
else
    resultlispdiff=""
    rm -f $timings/csl-psl-times-comparison/$d/$p.rlg.diff
fi

if [ "$cslresult" = failed ] || [ "$pslresult" = failed ]; then
    printf "test %-70s CSL %s, PSL %s\n" "$d/$p:" "$cslresult" "$pslresult"
else
    csltime=$(grep ^Time $timings/csl-times/$d/$p.time | awk '{print $4}')
    psltime=$(grep ^Time $timings/psl-times/$d/$p.time | awk '{print $4}')
    if [ $psltime -ne 0 ]; then
        let ratio=100*$csltime/$psltime
        ratioresult="${ratio}%"
    else
        ratioresult="NaN"
    fi
    printf "test %-70s CSL %s, PSL %s, CSL/PSL = %4s %s\n" "$d/$p:" \
	   "$cslresult" "$pslresult" "$ratioresult" "$resultlispdiff"
fi
