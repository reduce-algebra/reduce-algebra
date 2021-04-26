#! /bin/bash -v

csl -v -i reduce2.img -l test1.log <<'XX'

(setq !*echo t)
(begin)

df((alpha + beta)**3, beta);


XX
