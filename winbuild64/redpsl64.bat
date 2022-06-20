@echo off
set h=%~dp0
for %%i in ("%h%..") do set "reduce=%%~fi"
"%reduce%\lib\psl\psl\bpsl.exe" -td 1000 -f "%reduce%\lib\psl\red\reduce.img" %*
