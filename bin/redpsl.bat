@echo off

set h=%~dp0
set n=%~n0

if exist %h%..\pslbuild\x86_64-pc-windows\psl\bpsl.exe goto :x64_x86
if exist %h%..\pslbuild\x86_64-w64-windows\psl\bpsl.exe goto :x64
if exist %h%..\pslbuild\i686-pc-windows\psl\bpsl.exe goto :x86

echo +++ No ready-compiled %n% available
echo Go "./configure --with-psl; make" in a cygwin shell please
goto :done

:x64_x86
start %h%..\pslbuild\x86_64-pc-windows\psl\bpsl.exe -td 1000 -f  %h%..\pslbuild\x86_64-pc-windows\red\reduce.img %*
goto :done

:x64
start %h%..\pslbuild\x86_64-w64-windows\psl\bpsl.exe -td 1000 -f  %h%..\pslbuild\x86_64-w64-windows\red\reduce.img %*
goto :done

:x86
start %h%..\pslbuild\i686-pc-windows\psl\bpsl.exe -td 16000000 -f %h%..\pslbuild\i686-pc-windows\red\reduce.img %*

:done


