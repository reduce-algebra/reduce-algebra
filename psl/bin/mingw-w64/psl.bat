@echo off

call ..\..\dist\psl-names-mingw-w64.bat
call  %pxk%\bpsl.exe -td 600 -f %psys%\psl.img

