rem @echo off

%pxk%\bpsl.exe -td 600 -f %psys%\bare-psl.img < %pdist%\make-pslcomp.dat > %plogs%\make-pslcomp.blg
rem copy /b %psys%\bpsl.exe %psys%\pslcomp.exe
popd
