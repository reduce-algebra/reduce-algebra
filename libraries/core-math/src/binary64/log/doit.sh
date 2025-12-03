#!/bin/bash
# script to check the error bound of the binary64 cr_log fast path (log.c)
# r is the entry in the _INVERSE[] table
r=$1
# l1 and l2 and the entries in _LOG_INV[]
l1=$2
l2=$3
# y0 is the i index (362 <= i <= 724)
y0=$4
# y1 = i+1
y1=`echo $y0 + 1 | bc -q`
# rnd is the rounding mode (ne for nearest, zr for towards zero, up for upwards, and dn for downwards)
rnd=$5
sed "s/TEMPR/$r/g" log1_template.g | sed "s/TEMPL1/$l1/g" | sed "s/TEMPL2/$l2/g"| sed "s/Y0/${y0}b-9/g" | sed "s/Y1/${y1}b-9/g" | sed "s/RND/$rnd/g" > /tmp/log1.g
gappa /tmp/log1.g >& /tmp/log1.out
