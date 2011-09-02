REM makeall.bat

REM re-builds absolutely everything, inclusing doing a re-profile
REM of REDUCE to select what should be compiled into C. This should only
REM be required after MAJOR changes in the source.

REM Note that when using Windows the "make" utility that you are
REM provided with may well be called "wmake" or "nmake". You need to adjust
REM this script or arrange to make a copy of the relevant utility under the
REM simple name "make.exe".  You also need to have copies the correct
REM makefile (typically Makefile.vc or Makefile.w32) into the current
REM directory.

if "x%1"=="x" (set srcdir=../cslbase) else set srcdir=%1

make slowr38.exe
call %srcdir:/=\%\..\util\boot38 %srcdir%
call %srcdir:/=\%\..\util\profile %srcdir%
copy profile.dat %srcdir:/=\%\..\csl-c
del profile.dat
call %srcdir:/=\%\..\util\c-code38 %srcdir%
make r38.exe

REM the bits from here down are cheaper and are all that is usually needed
call %srcdir:/=\%\..\util\full38 %srcdir%

call %srcdir:/=\%\..\util\testall %srcdir%
call %srcdir:/=\%\..\util\checkall %srcdir%

REM log\checkall.log and log\times.log should now be up to date.

