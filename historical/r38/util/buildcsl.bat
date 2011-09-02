@echo off

rem buildcsl.bat --- Build CSL REDUCE under Windows.

rem Author: Anthony C. Hearn.

set lisp=csl

cd %reduce%\lisp\csl\%MACHINE%

if "%MACHINE%" == "win32vc" goto visualc

if "%MACHINE%" == "cygwin32" goto cygnus

rem Watcom case

wmake csl.exe -f ..\cslsrc\Makefile.w32 reduce=%reduce%

goto cont

:visualc

if not "%MSVCDir%" == "" goto visualc2

set MSVCDir=c:\progra~1\DevStudio\VC

echo *** Using %MSVCDir% as MSCVCDir value

:visualc2

call %MSVCDir%\bin\Vcvars32 

nmake csl.exe -f ..\cslsrc\Makefile.vc reduce=%reduce%

goto cont

:cygnus

if not "%Cygroot%" == "" goto cygnus3

set Cygroot=c:\cygwin

echo *** Using %Cygroot% as Cygroot value

:cygnus3

set make_mode=unix

set opath=%path%

set path=%Cygroot%\bin;%path%

make csl.exe -f ..\cslsrc\Makefile.cyg

:cont

rem copy csl.exe reduce.exe

@echo on

if exist ..\reduce.img goto cont2

rem if exist ..\reduce.exe.img goto cont2

start /wait /min csl -k8000 -v -z -i ..\reduce.img -o ..\reduce.img %reduce%\packages\support\dbuild.lsp -- %reduce%\log\csldbld.log

:cont2

%reduce%\util\remake

:ret

if not "%opath%" == "" set path=%opath%
set opath=

cd %reduce%
