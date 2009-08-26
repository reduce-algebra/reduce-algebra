@echo off

set h=%~dp0
set n=%~n0

if exist %h%..\pslbuild\i686-pc-windows\psl\bpsl.exe goto :x86

echo +++ No ready-compiled %n% available
echo Go "./configure --with-psl; make" in a cygwin shell please
goto :done

:x86
%h%..\pslbuild\i686-pc-windows\psl\bpsl.exe -td 16000000 -f %h%..\pslbuild\i686-pc-windows\red\reduce.img %*

:done


