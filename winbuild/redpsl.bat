@echo off
set h=%~dp0
set reduce=%h%..
"%reduce%\lib\psl\psl\bpsl.exe" -td 16000000 -f "%reduce%\lib\psl\red\reduce.img" %*
