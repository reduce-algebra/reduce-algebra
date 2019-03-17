@echo off

set h=%~dp0
set reduce=%h%..

"%reduce%\lib\psl\psl\bpslw.exe" -td 1000 -f "%reduce%\lib\psl\red\reduce.img" %*
