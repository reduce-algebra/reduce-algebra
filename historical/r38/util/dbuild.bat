rem dbuild.bat -- Build a PSL-based REDUCE "in core".

rem Authors: Anthony C. Hearn, H. Melenk.

if not "%pslsize%" == "" goto cont

set pslsize=12000000

:cont

if exist %reduce%\log\dbuild.log del %reduce%\log\dbuild.log

cd %reduce%\lisp\psl\win32\psl

start /wait /min bpsl -td %pslsize% -i %reduce%\util\dbuild.dat -o %reduce%\log\dbuild.log

cd %reduce%
