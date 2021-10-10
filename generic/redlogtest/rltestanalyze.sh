#!/usr/bin/env bash

shopt -s globstar


usage() {
    echo "Usage: $(basename $0) [-h] [-o <format>] <regressions-dir> <timings-dir>"
    echo "       -h: print help and exit"
    echo "       -o: choose output format among 'csv', 'html', 'txt' (default)"
}

output=txt

while getopts :ho: opt; do
    case $opt in
        h) usage
           exit 0
           ;;
        o) if [ $OPTARG = csv -o $OPTARG = html -o $OPTARG = txt ]; then
                output=$OPTARG
            else
                usage > /dev/stderr
                exit 1
            fi
            ;;
        ?) echo "$(basename $0): bad option '$OPTARG'" > /dev/stderr
           usage > /dev/stderr
           exit 1
           ;;
    esac
done

shift $((OPTIND-1))

if [ $# -ne 2 ]; then
    echo "$(basename $0): bad number of arguments"
    usage > /dev/stderr
    exit 1
fi

if [ ! -d "$1" ]; then
    echo "$(basename $0): $1 is not a directory"
    usage > /dev/stderr
    exit 1
fi

if [ ! -d "$2" ]; then
    echo "$(basename $0): $2 is not a directory"
    usage > /dev/stderr
    exit 1
fi

pushd $1 > /dev/null
regressions=$(pwd)
popd > /dev/null

pushd $2 > /dev/null
timings=$(pwd)
popd > /dev/null

date=$(date +%Y-%m-%d)

alarmone=2000
alarmtwo=4000
alarmthree=8000
alarmfour=16000

legend="Detailed Timings (All Times in ms).  Delta Markers: * $alarmone ms, ** $alarmtwo ms, *** $alarmthree ms, **** $alarmfour ms"

if [ $output = txt ]; then
    dline=$(printf "%173s" | tr " " =)
    line=$(printf "%173s" | tr " " -)
    fmt="%-70s %-6s %12s %12s %12s %8s %12s %12s %12s %8s  %-4s\n"
fi
columns=(Date Lisp Benchmark Status RefCpu Cpu DeltaCpu RefGc Gc DeltaGc "")
ncolumns=${#columns[*]}

if [ $output == csv ]; then
    # With csv the heading comes here because it is printed only once for CSL and PSL
    for ((i=0; i<$((ncolumns - 1)); i++)); do
        echo -n "${columns[i]};"
    done
    echo "${columns[-1]}"
fi

if [ $output == html ]; then
    echo "<html>"
    echo "<head>"
    echo '<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">'
    echo "</head>"
    echo "<body>"
    echo '<table class="table table-bordered table-striped">'
    echo "<caption>$legend</caption>"
    echo "<thead>"
    echo -n "<tr>"
    echo -n "<th style=\"text-align:left;\">Benchmark</th>"
    for w in CSL PSL Average; do
        echo -n "<th style=\"text-align:center;\" colspan=4>$w</th>"
    done
    echo -n "<th></th>"
    echo "</tr>"
    echo -n "<tr>"
    echo -n "<th></th>"
    for x in CSL PSL Average; do
        echo -n "<th style=\"text-align: right;\">CPU<sub>ref</sub></th>"
        echo -n "<th style=\"text-align: right;\">CPU</th>"
        echo -n "<th style=\"text-align: right;\">&Delta;<sub>abs</sub></th>"
        echo -n "<th style=\"text-align: right;\">&Delta;<sub>rel</sub></th>"
    done
    echo -n "<th></th>"
    echo "</tr>"
    echo "</thead>"
    echo "<tbody>"
elif [ $output == txt ]; then
    echo "$dline"
    echo "$legend"
    echo "$dline"
fi

count[3]=0
refcpu[3]=0
cpu[3]=0
deltacpu[3]=0
pcpu[3]=0
count[4]=0
refcpu[4]=0
cpu[4]=0
deltacpu[4]=0
pcpu[4]=0
count[5]=0
refcpu[5]=0
cpu[5]=0
deltacpu[5]=0
pcpu[5]=0

cd $regressions
for a in **/*.tst; do
    p=$(dirname $a)/$(basename $a .tst)

    for lisp in csl psl; do
        if [ $lisp == csl ]; then l=0; else l=1; fi

        if [ -f $timings/$lisp-times/$p.rlg.diff ]; then
            status[l]=failed
        else
            status[l]=ok
        fi

        read -ra tmparr <<< $(fgrep Time $p.${lisp}time)
        refcpu[l]=${tmparr[3]}

        read -ra tmparr <<< $(fgrep Time $timings/$lisp-times/$p.time)
        cpu[l]=${tmparr[3]}

        if [ -n "$cpu[l]" ]; then
            deltacpu[l]=$((${cpu[l]}+-${refcpu[l]}))

            if [ ${refcpu[l]} -eq 0 ] && [ ${cpu[l]} -eq 0 ]; then
                pcpu[l]="100%"
            elif [ ${refcpu[l]} -eq 0 ]; then
                pcpu[l]="NaN"
            else
                pcpu[l]=$((100*${cpu[l]}/${refcpu[l]}))%
            fi

            if [ ${deltacpu[l]} -gt 0 ]; then
                deltacpu[l]=+${deltacpu[l]}
            fi
            refcpu[$((l+3))]=$(( ${refcpu[l+3]} + ${refcpu[l]} ))
            cpu[$((l+3))]=$(( ${cpu[l+3]} + ${cpu[l]} ))
            count[l+3]=$(( ${count[l+3]} + 1 ))
        else
            deltacpu[l]=""
            pcpu[l]=""
            significant[l]=""
        fi
    done

    if [ ${status[0]} == ok -a ${status[1]} == ok ]; then
        refcpu[2]=$(( (${refcpu[0]} + ${refcpu[1]}) / 2 ))

        cpu[2]=$(( (${cpu[0]} + ${cpu[1]}) / 2 ))

        deltacpu[2]=$((${cpu[2]}+-${refcpu[2]}))

        if [ ${refcpu[2]} -eq 0 ] && [ ${cpu[2]} -eq 0 ]; then
            pcpu[2]="100%"
        elif [ ${refcpu[2]} -eq 0 ]; then
            pcpu[2]="NaN"
        else
            pcpu[2]=$((100*${cpu[2]}/${refcpu[2]}))%
        fi

        delta=${deltacpu[2]}
        if [ ${deltacpu[2]} -gt 0 ]; then
            deltacpu[2]=+${deltacpu[2]}
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
    fi

    if [ $output == txt ]; then
        printf "$fmt" "$p" "$status" "$refcpu" "$cpu" "$deltacpu" "$pcpu" "$refgc" "$gc" "$deltagc" "$pgc" "$significant"
    elif [ $output == html ]; then
        echo -n "<tr>"
        for w in "$p"; do
            echo -n "<td align=\"left\">$w</td>"
        done
        for l in 0 1 2; do
            for w in "${refcpu[l]}" "${cpu[l]}" "${deltacpu[l]}" "${pcpu[l]}"; do
                echo -n "<td align=\"right\">$w</td>"
            done
        done
        echo -n "<td align=\"left\">$significant</td>"
        echo "</tr>"
    elif [ $output == csv ]; then
        echo "$date;$lisp;$p;$status;$refcpu;$cpu;$deltacpu;$refgc;$gc;$deltagc"
    fi
done

if [ $output == txt ]; then
    echo $line
    echo
elif [ $output == html ]; then
    for l in 3 4; do
        refcpu[$l]=$((${refcpu[$l]}/count[$l]))
        cpu[$l]=$((${cpu[$l]}/count[$l]))
    done
    refcpu[5]=$(( (${refcpu[3]} + ${refcpu[4]}) / 2 ))
    cpu[5]=$(( (${cpu[3]} + ${cpu[4]}) / 2 ))

    for l in 3 4 5; do
        deltacpu[$l]=$((${cpu[$l]}-${refcpu[$l]}))
        delta[$l]=${deltacpu[$l]}
        if [ ${deltacpu[$l]} -gt 0 ]; then
            deltacpu[$l]=+${deltacpu[$l]}
        fi
        if [ ${refcpu[$l]} -eq 0 ] && [ ${cpu[$l]} -eq 0 ]; then
            pcpu[$l]="100%"
        elif [ ${refcpu[$l]} -eq 0 ]; then
            pcpu[$l]="NaN"
        else
            pcpu[$l]=$((100*${cpu[$l]}/${refcpu[$l]}))%
        fi
    done

    if [ ${delta[3]} -gt 0 -a ${delta[4]} -gt 0 ]; then
        bg="table-danger"
    elif [ ${delta[3]} -lt 0 -a ${delta[4]} -lt 0 ]; then
        bg="table-success"
    else
        bg="table-warning"
    fi

    echo "</tbody>"
    echo "<tfoot>"
    echo -n "<tr class=\"$bg\">"
    echo -n "<td>Average</td>"
    for l in 3 4 5; do
        echo -n "<td align=\"right\">${refcpu[$l]}</td><td align=\"right\">${cpu[$l]}</td><td align=\"right\">${deltacpu[$l]}</td><td align=\"right\">${pcpu[$l]}</td>"
    done
    echo "<td></td>"
    echo "</tr>"
    echo "</tfoot>"
    echo "</table>"
    echo '<table class="table table-sm table-striped">'
    echo "<caption>$legend</caption>"
fi

for lisp in csl psl; do
    Lisp=${lisp^^}

    if [ $output == html ]; then
        echo "<thead>"
        echo -n "<tr>"
        for w in "$Lisp Benchmark" Status; do
            echo -n "<th align=\"left\">$w</th>"
        done
        for w in "CPU<sub>ref</sub>" "CPU" "" "&Delta;CPU" "GC<sub>ref</sub>" "GC" "" "&Delta;GC" ""; do
            echo -n "<th style=\"text-align: right;\">$w</th>"
        done
        echo "</tr>"
        echo "</thead>"
        echo "<tbody>"
    elif [ $output == txt ]; then
        echo $line
        printf "$fmt" "$Lisp Benchmark" Status RefCPU CPU "" DeltaCPU RefGC GC "" DeltaGC ""
        echo $line
    fi

    cd $regressions
    for a in **/*.tst; do
        p=$(dirname $a)/$(basename $a .tst)

        if [ -f $timings/$lisp-times/$p.rlg.diff ]; then
            status=failed
        else
            status=ok
        fi

        read -ra tmparr <<< $(fgrep Time $timings/$lisp-times/$p.time)
        cpu=${tmparr[3]}
        gc=${tmparr[8]}
        if [ -z "$gc" ]; then gc=0; fi

        read -ra tmparr <<< $(fgrep Time $p.${lisp}time)
        refcpu=${tmparr[3]}
        refgc=${tmparr[8]}
        if [ -z "$refgc" ]; then refgc=0; fi

        if [ -n "$cpu" ]; then
            deltacpu=$(($cpu+-$refcpu))
            deltagc=$(($gc+-$refgc))

            if [ $refcpu -eq 0 ] && [ $cpu -eq 0 ]; then
                pcpu="100%"
            elif [ $refcpu -eq 0 ]; then
                pcpu="NaN"
            else
                pcpu=$((100*$cpu/$refcpu))%
            fi

            if [ $refgc -eq 0 ] && [ $gc -eq 0 ]; then
                pgc="100%"
            elif [ $refgc -eq 0 ]; then
                pgc="NaN"
            else
                pgc=$((100*$gc/$refgc))%
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

        if [ $output == txt ]; then
            printf "$fmt" "$p" "$status" "$refcpu" "$cpu" "$deltacpu" "$pcpu" "$refgc" "$gc" "$deltagc" "$pgc" "$significant"
        elif [ $output == html ]; then
            echo -n "<tr>"
            for w in "$p" "$status"; do
                echo -n "<td align=\"left\">$w</td>"
            done
            for w in "$refcpu" "$cpu" "$deltacpu" "$pcpu" "$refgc" "$gc" "$deltagc" "$pgc"; do
                echo -n "<td align=\"right\">$w</td>"
            done
            echo -n "<td align=\"left\">$significant</td>"
            echo "</tr>"
        elif [ $output == csv ]; then
            echo "$date;$lisp;$p;$status;$refcpu;$cpu;$deltacpu;$refgc;$gc;$deltagc"
        fi
    done
    if [ $output == txt ]; then
        echo $line
        echo
    elif [ $output == html ]; then
        echo "</tbody>"
    fi
done

if [ $output == html ]; then
    echo "</table>"
    echo '<script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.10.2/dist/umd/popper.min.js" integrity="sha384-7+zCNj/IqJ95wo16oMtfsKbZ9ccEh31eOz1HGyDuCQ6wgnyJNSYdrPa03rtR1zdB" crossorigin="anonymous"></script>'
    echo '<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.min.js" integrity="sha384-QJHtvGhmr9XOIpI6YVutG+2QOK9T+ZnN4kzFN1RtK3zEFEIsxhlmWl5/YESvpZ13" crossorigin="anonymous"></script>'
    echo "</body>"
    echo "</html>"
fi

exit 0
