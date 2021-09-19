#!/bin/bash

shopt -s globstar

alarmone=250
alarmtwo=1000
alarmthree=4000
alarmfour=16000

if test $# = 3; then
    root="$1"
    date="$2"
    globallog="$3"
else
    echo "rltestanalyze.sh root date global_log_dir"
    exit 1
fi

base=$root/$date
log=$base/log
timings=$base/timings
regressions=$base/trunk/packages/redlog/regressions
timefile=$globallog/regression-times.csv

rm -f $log/regression-times.csv
echo "date;lisp;test;refcpu;cpu;deltacpu;refgc;gc;deltagc" > $log/regression-times.csv

if [ ! -f $timefile ]; then
    echo "date;lisp;test;refcpu;cpu;deltacpu;refgc;gc;deltagc" > $timefile
fi

dline=$(printf "%173s" | tr " " =)
line=$(printf "%173s" | tr " " -)
fmt="%-70s %-6s %12s %12s %12s %8s %12s %12s %12s %8s  %-4s\n"

echo $dline
echo "Detailed Timings (All Times in ms).  Delta Markers: * $alarmone ms, ** $alarmtwo ms, *** $alarmthree ms, **** $alarmfour ms"
echo $dline

for lisp in csl psl; do
    if [ $lisp == "csl" ]; then
	Lisp=CSL
    else
	Lisp=PSL
    fi
    echo $line
    printf "$fmt" "$Lisp Test" Status RefCPU CPU "" DeltaCPU RefGC GC "" DeltaGC ""
    echo $line

    cd $regressions
    for a in **/*.tst; do
	p=$(dirname $a)/$(basename $a .tst)

	if [ -f $timings/$lisp-times/$p.rlg.diff ]; then
	    status=failed
	else
	    status=ok
	fi
	
	cpu=$(fgrep Time $timings/$lisp-times/$p.time | awk '{if (NF >= 4) print $4; else print ""}')
	gc=$(fgrep Time $timings/$lisp-times/$p.time | awk '{if (NF >= 9) print $9; else print 0}')

	refcpu=$(fgrep Time $p.${lisp}time | awk '{if (NF >= 4) print $4; else print ""}')
	refgc=$(fgrep Time $p.${lisp}time | awk '{if (NF >= 9) print $9; else print 0}')

	if [ -n "$cpu" ] && [ -n "$gc" ]; then
	    let deltacpu=$cpu+-$refcpu
	    let deltagc=$gc+-$refgc

	    if [ $refcpu -eq 0 ] && [ $cpu -eq 0 ]; then
		pcpu="100%"
	    elif [ $refcpu -eq 0 ]; then
		pcpu="oo"
	    else
		let pcpu=100*$cpu/$refcpu
		pcpu=${pcpu}%
	    fi

	    if [ $refgc -eq 0 ] && [ $gc -eq 0 ]; then
		pgc="100%"
	    elif [ $refgc -eq 0 ]; then
		pgc="oo"
	    else
		let pgc=100*$gc/$refgc
		pgc=${pgc}%
	    fi

	    delta=$deltacpu
	    if [ $deltacpu -gt 0 ]; then
		deltacpu=+$deltacpu
	    fi
	    
	    if [ $deltagc -gt 0 ]; then
		deltagc=+$deltagc
	    fi

	    if [ $delta -gt $alarmfour ]; then
		significant="****"
	    elif [ $delta -gt $alarmthree ]; then
		significant="***"
	    elif [ $delta -gt $alarmtwo ]; then
		significant="**"
	    elif [ $delta -gt $alarmone ]; then
		significant="*"
	    else
		significant=""
	    fi
	else
	    deltacpu=""
	    pcpu=""
	    deltagc=""
	    pgc=""
	    significant=""
	fi
	printf "$fmt" "$p" "$status" "$refcpu" "$cpu" "$deltacpu" "$pcpu" "$refgc" "$gc" "$deltagc" "$pgc" "$significant"

	echo "$date;$lisp;$p;$status;$refcpu;$cpu;$deltacpu;$refgc;$gc;$deltagc" >> $log/regression-times.csv
    done
    echo $line
    echo
done

tail -n +2 $log/regression-times.csv >> $timefile

exit 0

echo $dline
echo "Significant Changes (All Times in ms)"
echo $dline

for lisp in csl psl; do
    if [ $lisp == "csl" ]; then
	Lisp=CSL
    else
	Lisp=PSL
    fi
    echo $line
    printf "$fmt" "$Lisp Test" RefCPU CPU "" DeltaCPU RefGC GC "" DeltaGC
    echo $line

    cd $regressions
    for a in */*/*.tst; do
	p=$(dirname $a)/$(basename $a .tst)
	
	cpu=$(fgrep Time $timings/$lisp-times/$p.time | awk '{print $4}')
	gc=$(fgrep Time $timings/$lisp-times/$p.time | awk '{if (NF >= 9) print $9; else print 0}')

	refcpu=$(fgrep Time $p.${lisp}time | awk '{print $4}')
	refgc=$(fgrep Time $p.${lisp}time | awk '{if (NF >= 9) print $9; else print 0}')

	let cpu=($cpu+500)/1000
	let gc=($gc+500)/1000

	let refcpu=($refcpu+500)/1000
	let refgc=($refgc+500)/1000

	let deltacpu=$cpu+-$refcpu
	let deltagc=$gc+-$refgc

	if [ $refcpu -ne $cpu ] || [ $refgc -ne $gc ]; then
	    if [ $refcpu -eq 0 ] && [ $cpu -eq 0 ]; then
		pcpu="100%"
	    elif [ $refcpu -eq 0 ]; then
		pcpu="oo"
	    else
		let pcpu=100*$cpu/$refcpu
		pcpu=${pcpu}%
	    fi

	    if [ $refgc -eq 0 ] && [ $gc -eq 0 ]; then
		pgc="100%"
	    elif [ $refgc -eq 0 ]; then
		pgc="oo"
	    else
		let pgc=100*$gc/$refgc
		pgc=${pgc}%
	    fi

	    if [ $deltacpu -gt 0 ]; then
		deltacpu=+$deltacpu
	    fi
	
	    if [ $deltagc -gt 0 ]; then
		deltagc=+$deltagc
	    fi

	    printf "$fmt" $p $refcpu $cpu $deltacpu $pcpu $refgc $gc $deltagc $pgc
	fi
    done
    echo $significant
    echo $line
    echo
done
