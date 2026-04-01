@echo off
rem Start CLISP REDUCE on Windows.
rem Author: Francis J. Wright <https://sourceforge.net/u/fjwright>
rem Time-stamp: <2026-03-31 17:56:48 franc>

setlocal
:loop
if "%1" equ "" goto done
if "%1" equ "-h" goto help
if "%1" equ "--help" goto help
if "%1" equ "--no-rcfile" (
  set norcfile=-- --no-rcfile
) else (
  set args=%args% %1
)
shift
goto loop
:done
set args=%args% %norcfile%
goto doit

:help
echo Start CLISP REDUCE on Windows.
echo Usage: redclisp ^<options^>
echo Useful options:
echo   -h, --help   Print this message and exit.
echo   -m ^<size^>    Set memory size ^(^<size^> = nB or nKB or nMB^).
echo   --no-rcfile  Inhibit REDUCE startup file.
exit /b

:doit
clisp -ansi -norc -E utf-8 -M %~dp0fasl.clisp\reduce.mem %args%

rem CLISP REDUCE options (currently only --no-rcfile) must appear after
rem any CLISP options and *must* follow the option separator --.
