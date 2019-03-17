@echo off
set h=%~dp0
set reduce=%h%..
IF NOT EXISTS %USERPROFILE%\Documents\ GOTO NOWINDIR
cd %USERPROFILE%\Documents
:NOWINDIR
"%reduce%\lib\csl\reduce.exe" %*
