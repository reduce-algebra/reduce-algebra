@echo off

set h=%~dp0
set reduce=%h%..

%reduce%\lib\psl\psl\bpslw.exe -td 16000000 -f %reduce%\lib\psl\red\reduce.img %*
