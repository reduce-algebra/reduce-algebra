@echo off
rem Start SBCL REDUCE on Windows.
rem Author: Francis J. Wright <https://sourceforge.net/u/fjwright>
rem Time-stamp: <2026-03-31 17:46:16 franc>

setlocal
:loop
if "%1" equ "" goto done
if "%1" equ "-h" goto help
if "%1" equ "--help" goto help
if "%1" equ "--no-rcfile" (
  set norcfile=--no-rcfile
) else (
  set args=%args% %1
)
shift
goto loop
:done
set args=%args% %norcfile%
goto doit

:help
echo Start SBCL REDUCE on Windows.
echo Usage: redsbcl ^<options^>
echo Useful options:
echo   --help                      Print this message and exit.
echo   --version                   Print SBCL version information and exit.
echo   --control-stack-size ^<MiB^>  Size of reserved control stack; default 2.
echo   --dynamic-space-size ^<MiB^>  Size of reserved dynamic space.
echo   --no-rcfile                 Inhibit REDUCE startup file.
exit /b

:doit
rem See "help call" for expansion of batch script argument references.
sbcl --noinform --core %~dp0fasl.sbcl\reduce.img %args%

rem SBCL runtime options should all work but not SBCL toplevel options,
rem which are replaced by REDUCE options.  These are currently only
rem --no-rcfile, which must appear after any runtime options.
