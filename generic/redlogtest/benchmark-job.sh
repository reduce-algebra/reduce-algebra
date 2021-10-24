#!/usr/bin/env bash

ulimit -c 1800

if [ $# = 0 ]; then
    echo "$0: too few arguments provided" > /dev/stderr
    exit 1
fi

if [ "$1" = -q ]; then
    quiet=0
    shift
fi

if [ $# -lt 5 ]; then
    echo "$0: too few arguments provided" > /dev/stderr
    exit 1
fi

if [ $# -gt 5 ]; then
    echo "$0: too many arguments provided" > /dev/stderr
    exit 1
fi

reduce="$1"
psl_heapsize="$2"
now="$3"
rel_benchmark="$4"
ref="$5"

dir=$(dirname "$now/$rel_benchmark")

cd $dir

if [ ! $? ]; then
    echo "$0: cd $dir failed, exiting"
    exit 1
fi

lisp=$(sed 's/red//' <<< $(basename "$reduce"))

if [ "$lisp" = "psl" ]; then
    pslheap_file="$(basename $rel_benchmark .red).pslheap"
    if [ -f "$pslheap_file" ]; then
        psl_heapsize=$(cat "$pslheap_file")
    fi
    reduce_args="-td $psl_heapsize"
    echo $psl_heapsize > heapsize_psl.txt
else
    reduce_args="-w"
fi

date -R > start_$lisp.txt

/usr/bin/time -p sh -c "$reduce $reduce_args > rlg_$lisp.raw" <<EOF 2> /dev/null
off int;
symbolic linelength 80;
symbolic(!*redefmsg!* := nil);
symbolic(!*redeflg!* := nil);
on errcont;
lisp random_new_seed 1;
resettime1;
write "START OF REDUCE TEST RUN"$ in "$(basename $rel_benchmark)"; write "END OF REDUCE TEST RUN"$
showtime1$
quit$
EOF

read -ra tmparr <<< $(fgrep 'Time (counter 1):' rlg_$lisp.raw)
cpu=${tmparr[3]}
gc=${tmparr[8]}
if [ -z "$gc" ]; then
    gc=0
fi
echo $cpu > cpu_$lisp.txt
echo $gc > gc_$lisp.txt

sed -e '1,/START OF REDUCE TEST RUN/d'           \
    -e '/END OF REDUCE TEST RUN/,//d'            \
    -e '/OMIT/,/TIMO/d'                          \
    -e '1s/^1: //'                               \
    -e '$s/^1: //'                               \
    -e '/^Total time taken:/d'                   \
    -e '/^Number of garbage/d'                   \
    -e '/^Time: /d'                              \
    -e '/^CRACK needed :/d'                      \
    -e '/^time for init/d'                       \
    -e '/^+++ levelt compiled/d'                 \
    -e '/^\*\*\* (levelt): base/d'               \
    -e '/^Request to set constant bitsperword/d' \
    -e '/^time to formulate/d'                   \
    -e '/\*\*\* turned off switch/d'             \
    rlg_$lisp.raw > rlg_$lisp.txt
if [ $? ]; then
    rm -f rlg_$lisp.raw
fi

refrlg=$(dirname $ref/$rel_benchmark)/rlg_$lisp.txt

if [ -r $refrlg ]; then
    if [ -z "$(diff -Bqw $refrlg rlg_$lisp.txt)" ]; then
        valid="True"
    else
        valid="False"
    fi
else
    valid="None"
fi

if [ ! $quiet ]; then
    printf "%3s %-11s %s\n" $lisp valid=$valid $dir
fi

echo $valid > valid_$lisp.txt

date -R > end_$lisp.txt
