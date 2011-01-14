@echo off

pushd  %pnkl%
%psys%\bare-psl.exe < %pxdist%\make-psl.dat > %plogs%\make-psl.blg
copy /b %psys%\bpsl.exe %psys%\psl.exe
popd
