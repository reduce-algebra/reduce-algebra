rem mkreduce script

if exist %reduce%\log\mkreduce.log del %reduce%\log\mkreduce.log

cd %reduce%\lisp\%lisp%\%MACHINE%

if %lisp% == psl goto psl

start /wait /min csl -k8000 -v -z -i ..\reduce.img -o ..\reduce.img %reduce%\packages\support\mkredcsl.sl -- %reduce%\log\mkreduce.log

goto ret

:psl

cd psl

start /wait /min bpsl -td 12000000 -i %reduce%\util\mkredpsl.dat -o %reduce%\log\mkreduce.log

:ret

cd %reduce%
