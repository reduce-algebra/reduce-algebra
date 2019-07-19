@echo off
set h=%~dp0
set reduce=%h%..
if "%~1"=="-nocd" goto nowindir
if not exist %USERPROFILE%\Documents goto nowindir
pushd %USERPROFILE%\Documents
"%reduce%\lib\csl\reduce.exe" %*
popd
goto :eof
:nowindir
"%reduce%\lib\csl\reduce.exe" %*
