@echo off

pushd  %pnkl%
%psys%\bpsl.exe < %pxdist%\make-bare-psl.dat > %plogs%\make-bare-psl.blg
copy /b %psys%\bpsl.exe %psys%\bare-psl.exe
popd
