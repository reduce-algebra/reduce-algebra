@echo off

pushd  %pnkl%
%pxk%\bpsl.exe < %pdist%\make-bare-psl.dat > %plogs%\make-bare-psl.blg
rem copy /b %psys%\bpsl.exe %psys%\bare-psl.exe
popd
