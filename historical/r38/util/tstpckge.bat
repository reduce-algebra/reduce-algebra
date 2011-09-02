rem test --- Run a REDUCE test file.

rem Author: Anthony C. Hearn.

set package=%1

if %lisp% == psl goto psl

if not %MACHINE% == cygwin32 goto l2
if not "%Cygroot%" == "" goto l1
set Cygroot=c:\cygwin
echo *** Using %Cygroot% as Cygroot value
:l1
set opath=%path%
set path=%Cygroot%\bin;%PATH%
:l2
start /wait /min %reduce%\lisp\csl\%MACHINE%\csl -i %reduce%\lisp\csl\reduce.img %reduce%\util\tstpckge.dat -- %reduce%\log\%1.rlg

goto ret

:psl

if not "%pslsize%" == "" goto cont

set pslsize=12000000

:cont

start /wait /min %reduce%\lisp\psl\%MACHINE%\psl\bpsl -td %pslsize% -f %reduce%\lisp\psl\%MACHINE%\red\reduce.img -i %reduce%\util\tstpckge.dat -o %reduce%\log\%1.rlg

:ret

set package=

if not "%opath%" == "" set path=%opath%
set opath=

