cd %pxnk%\lap
%pxk%\bpsl -td 8000000 < %pxk%\mkbare.dat > %pxk%\mkbare.lst 
copy %pxnk%\lap\bpsl.img %psys%
rem %%%copy %pxnk%\lap\bpsl.img d:\redu35\bin\winnt
del %pxnk%\lap\bpsl.img
copy %pxk%\bpsl.exe %psys%
rem copy %pxk%\bpsl.exe d:\redu35\bin\winnt
cd %pxk%
