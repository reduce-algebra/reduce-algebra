@echo off

%pxk%\bpsl.exe -f %psys%\bare-psl.img < %pdist%\make-psl.dat > %plogs%\make-psl.blg
rem copy /b %psys%\bpsl.exe %psys%\psl.exe
popd
