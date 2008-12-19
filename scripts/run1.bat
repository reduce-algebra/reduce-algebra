@echo off
set h=%~dp0
set p=%1
set n=%2
shift
shift
echo %p% %%* > %h%\..\bin\%n%.bat
%p% %1 %2 %3 %4 %5 %6 %7 %8 %9
