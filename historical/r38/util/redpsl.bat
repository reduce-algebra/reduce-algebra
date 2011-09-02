@echo off
rem Run Windows PSL REDUCE.
set reduce=reducevar
set gnuplot=%reduce%\wutil\win32
set helpdir=%reduce%\help
start %reduce%\lisp\psl\win32\psl\bpslw -td 12000000 -f %reduce%\lisp\psl\win32\red\reduce.img
