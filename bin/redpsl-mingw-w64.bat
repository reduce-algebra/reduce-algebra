@echo off

set h=%~dp0
set n=%~n0

if exist %h%..\pslbuild\mingw-w64\psl\bpsl.exe goto :x86

echo +++ No ready-compiled %n% available
echo Go "./configure --with-psl; make" in a cygwin shell please
goto :done

:x86
start %h%..\pslbuild\mingw-w64\psl\bpsl.exe -td 16000000 -f %h%..\pslbuild\mingw-w64\red\reduce.img %*

:done


