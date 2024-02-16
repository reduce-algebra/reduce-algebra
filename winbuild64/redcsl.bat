@echo off
set h=%~dp0
set reduce=%h%..
if "%~1"=="-nocd" goto nocd
if not exist %USERPROFILE%\Documents goto nowindir
pushd %USERPROFILE%\Documents
"%reduce%\lib\csl\reduce.exe" %*
popd
goto :eof
:nocd
"%reduce%\lib\csl\reduce.exe" %2 %3 %4 %5 %6
goto :eof
:nowindir
"%reduce%\lib\csl\reduce.exe" %*
