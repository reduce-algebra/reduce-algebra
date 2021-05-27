#! /bin/bash -v

$pxk/bpsl -td 1000 -f redpsl2.img <<'XX' | tee testpsl1.log

(setq !*echo t)
(begin)

df((alpha + beta)**3, beta);


XX
