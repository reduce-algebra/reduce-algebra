@echo off
rem Start CCL REDUCE on Windows.
rem Author: Francis J. Wright <https://sourceforge.net/u/fjwright>
rem Time-stamp: <2026-04-01 12:50:11 franc>

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
echo Start CCL REDUCE on Windows.
echo Usage: redccl ^<options^>
echo Useful options:
echo   -h, --help            Print this message and exit.
echo   -S, --stack-size n    Set initial control stack to n bytes.
echo   -R, --heap-reserve n  Reserves n bytes for heap expansion.
echo   --no-rcfile           Inhibit REDUCE startup file.
exit /b

:doit
rem See "help call" for expansion of batch script argument references.
WHERE ccl64 /Q
IF ERRORLEVEL 1 (
   ccl -I %~dp0fasl.ccl\reduce.image %args%
) ELSE (
   ccl64 -I %~dp0fasl.ccl\reduce.image %args%
)

rem CCL REDUCE options (currently only --no-rcfile) must appear after
rem any CCL options and *must* follow the option separator --.
