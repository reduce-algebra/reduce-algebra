@echo off

echo compiling %2 from %1
set srcd=%1
set srcn=%2
pushd %1
%psys%\pslcomp.exe < %pxdist%\make-lap.dat > %plogs%\%2.blg
popd
set srcd=
set srcn=
