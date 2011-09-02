@echo off
rem Run Windows CSL REDUCE.
set reduce=reducevar
if "%1" == "" goto l5
if not %1 == cygnus goto l3
:l1
set platform=cygwin32
if not "%Cygroot%" == "" goto l2
set Cygroot=c:\cygwin
echo *** Using %Cygroot% as Cygroot value
:l2
set path=%Cygroot%\bin;%PATH%
%reduce%\lisp\csl\%platform%\csl -i %reduce%\lisp\csl\reduce.img -o %reduce%\lisp\csl\reduce.img
goto ret
:l3
if %1 == visualc set platform=win32vc
if %1 == watcom set platform=win32
if not "%platform%" == "" goto cont
:l4
echo Please call redcsl with argument cygnus, visualc, or watcom
goto ret
:l5
if "%MACHINE%" == "" goto l4
if "%MACHINE%" == "cygwin32" goto l1
set platform=%MACHINE%
:cont
start %reduce%\lisp\csl\%platform%\csl -i %reduce%\lisp\csl\reduce.img -o %reduce%\lisp\csl\reduce.img
:ret
set platform=

