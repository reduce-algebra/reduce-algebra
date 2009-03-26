@echo off

set h=%~dp0
set n=%~n0

if exist %h%..\cslbuild\x86_64-pc-windows\csl\reduce.com       goto :x64
if exist %h%..\cslbuild\i686-pc-windows\csl\reduce.com         goto :x86
if exist %h%..\cslbuild\x86_64-pc-windows-debug\csl\reduce.com goto :x64d
if exist %h%..\cslbuild\i686-pc-windows-debug\csl\reduce.com   goto :x86d

echo +++ No ready-compiled reduce available
echo Go "./configure --with-csl; make" in a cygwin shell please
goto :done

:x64
%h%..\scripts\run1 %h%..\cslbuild\x86_64-pc-windows\csl\reduce.com redcsl %*

:x86
%h%..\scripts\run1 %h%..\cslbuild\i686-pc-windows\csl\reduce.com redcsl %*

:x64d
%h%..\scripts\run1 %h%..\cslbuild\x86_64-pc-windows-debug\csl\reduce.com redcsl %*

:x86d
%h%..\scripts\run1 %h%..\cslbuild\i686-pc-windows-debug\csl\reduce.com redcsl %*

:done



