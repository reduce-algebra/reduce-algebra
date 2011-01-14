@echo off

pushd  %pnkl%
%psys%\bare-psl.exe < %pxdist%\make-pslcomp.dat > %plogs%\make-pslcomp.blg
copy /b %psys%\bpsl.exe %psys%\pslcomp.exe
popd
