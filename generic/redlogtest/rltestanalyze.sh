#!/bin/bash

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

echo "=============================================================================================================================="
echo "Detailed Timings (All Times in ms).  Delta Markers: * $alarmone ms, ** $alarmtwo ms, *** $alarmthree ms, **** $alarmfour ms"
echo "=============================================================================================================================="

for lisp in csl psl; do
    if [ $lisp == "csl" ]; then
	Lisp=CSL
    else
	Lisp=PSL
    fi
echo "------------------------------------------------------------------------------------------------------------------------------"
    printf "%-30s %12s %12s %12s %8s %12s %12s %12s %8s  %-4s\n" "$Lisp Test" RefCPU CPU "" DeltaCPU RefGC GC "" DeltaGC ""
echo "------------------------------------------------------------------------------------------------------------------------------"

    cd $regressions
    for a in */*/*.tst; do
	p=$(dirname $a)/$(basename $a .tst)
	
	cpu=$(fgrep Time $timings/$lisp-times/$p.time | awk '{print $4}')
	gc=$(fgrep Time $timings/$lisp-times/$p.time | awk '{if (NF >= 9) print $9; else print 0}')

	refcpu=$(fgrep Time $p.${lisp}time | awk '{print $4}')
	refgc=$(fgrep Time $p.${lisp}time | awk '{if (NF >= 9) print $9; else print 0}')
	
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

	printf "%-30s %12d %12s %12s %8s %12s %12d %12s %8s  %-4s\n" $p $refcpu $cpu $deltacpu $pcpu $refgc $gc $deltagc $pgc "$significant"

	echo "$date;$lisp;$p;$refcpu;$cpu;$deltacpu;$refgc;$gc;$deltagc" >> $log/regression-times.csv
    done
echo "------------------------------------------------------------------------------------------------------------------------------"
    echo
done

# echo "=============================================================================================================================="
# echo "Significant Changes (All Times in ms)"
# echo "=============================================================================================================================="

# for lisp in csl psl; do
#     if [ $lisp == "csl" ]; then
# 	Lisp=CSL
#     else
# 	Lisp=PSL
#     fi
# echo "------------------------------------------------------------------------------------------------------------------------------"
#     printf "%-30s %12s %12s %12s %8s %12s %12s %12s %8s\n" "$Lisp Test" RefCPU CPU "" DeltaCPU RefGC GC "" DeltaGC
# echo "------------------------------------------------------------------------------------------------------------------------------"

#     cd $regressions
#     for a in */*/*.tst; do
# 	p=$(dirname $a)/$(basename $a .tst)
	
# 	cpu=$(fgrep Time $timings/$lisp-times/$p.time | awk '{print $4}')
# 	gc=$(fgrep Time $timings/$lisp-times/$p.time | awk '{if (NF >= 9) print $9; else print 0}')

# 	refcpu=$(fgrep Time $p.${lisp}time | awk '{print $4}')
# 	refgc=$(fgrep Time $p.${lisp}time | awk '{if (NF >= 9) print $9; else print 0}')

# 	let cpu=($cpu+500)/1000
# 	let gc=($gc+500)/1000

# 	let refcpu=($refcpu+500)/1000
# 	let refgc=($refgc+500)/1000

# 	let deltacpu=$cpu+-$refcpu
# 	let deltagc=$gc+-$refgc

# 	if [ $refcpu -ne $cpu ] || [ $refgc -ne $gc ]; then
# 	    if [ $refcpu -eq 0 ] && [ $cpu -eq 0 ]; then
# 		pcpu="100%"
# 	    elif [ $refcpu -eq 0 ]; then
# 		pcpu="oo"
# 	    else
# 		let pcpu=100*$cpu/$refcpu
# 		pcpu=${pcpu}%
# 	    fi

# 	    if [ $refgc -eq 0 ] && [ $gc -eq 0 ]; then
# 		pgc="100%"
# 	    elif [ $refgc -eq 0 ]; then
# 		pgc="oo"
# 	    else
# 		let pgc=100*$gc/$refgc
# 		pgc=${pgc}%
# 	    fi

# 	    if [ $deltacpu -gt 0 ]; then
# 		deltacpu=+$deltacpu
# 	    fi
	
# 	    if [ $deltagc -gt 0 ]; then
# 		deltagc=+$deltagc
# 	    fi

# 	    printf "%-30s %12d %12s %12s %8s %12s %12d %12s %8s\n" $p $refcpu $cpu $deltacpu $pcpu $refgc $gc $deltagc $pgc
	    
# 	    echo "$date;$lisp;$p;$refcpu;$cpu;$deltacpu;$refgc;$gc;$deltagc" >> $log/regression-times.csv
# 	fi
#     done
# echo $significant
# echo "------------------------------------------------------------------------------------------------------------------------------"
#     echo
# done

tail -n +2 $log/regression-times.csv >> $timefile
