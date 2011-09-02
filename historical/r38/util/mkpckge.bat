rem mkpckge.bat -- compile a single package.

set package=%1

if %lisp% == psl goto psl

cd %reduce%\lisp\csl\%MACHINE%
if not %MACHINE% == cygwin32 goto l2
if not "%Cygroot%" == "" goto l1
set Cygroot=c:\cygwin
echo *** Using %Cygroot% as Cygroot value
:l1
set opath=%path%
set path=%Cygroot%\bin;%PATH%
:l2
start /wait /min csl -k6000 -v -i ..\reduce.img -o ..\reduce.img %reduce%\util\mkpckge.dat -- %reduce%\log\%package%.blg
goto ret

:psl

if not "%pslsize%" == "" goto cont

set pslsize=12000000

:cont

cd %reduce%

start /wait /min lisp\psl\%MACHINE%\psl\bpsl -td %pslsize% -f lisp\psl\%MACHINE%\red\reduce.img -i util\mkpckge.dat -o log\%1.blg

:ret

cd %reduce%

set package=

if not "%opath%" == "" set path=%opath%
set opath=
