rem remake2.bat -- compile a single package set.

rem Author: Anthony C. Hearn.

cd %reduce%\lisp\%lisp%\%MACHINE%

if %lisp% == psl goto psl

start /wait /min csl -i ..\reduce.img -o ..\reduce.img %reduce%\util\remake2.dat -- %reduce%\log\remake.log

goto ret

:psl

start /wait /min psl\bpsl -td 12000000 -f red\reduce.img -i %reduce%\util\remake2.dat -o log\remake%1.log

:ret

cd %reduce%

