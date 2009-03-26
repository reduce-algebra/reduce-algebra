@echo off
set h=%~dp0
set p=%1
set i=%2
set n=%3
shift
shift
shift
echo %p% -td 16000000 -f %i% %%* > %h%\..\bin\%n%.bat
%p% -td 16000000 -f %i% %*
