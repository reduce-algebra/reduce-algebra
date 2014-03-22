@echo off

set h=%~dp0
set n=%~n0

if exist %h%..\cslbuild\x86_64-pc-windows\csl\%n%.com       goto :x64
if exist %h%..\cslbuild\i686-pc-windows\csl\%n%.com         goto :x86
if exist %h%..\cslbuild\x86_64-pc-windows-debug\csl\%n%.com goto :x64d
if exist %h%..\cslbuild\i686-pc-windows-debug\csl\%n%.com   goto x86d

echo +++ No ready-compiled %n% available
echo Go "./configure --with-csl; make" in a cygwin shell please
goto :done

:x64
%h%..\cslbuild\x86_64-pc-windows\csl\%n%.com %*
goto :done

:x86
%h%..\cslbuild\i686-pc-windows\csl\%n%.com %*
goto :done

:x64d
%h%..\cslbuild\x86_64-pc-windows-debug\csl\%n%.com %*
goto :done

:x86d
%h%..\cslbuild\i686-pc-windows-debug\csl\%n%.com %*
goto :done

:done



