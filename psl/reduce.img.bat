
set current=%cd%
set here=%cd%\..\pslbuild\winx64\psl
cd %here%
bpsl.exe  -td 600 < %current%\reduce.img.dat.bat >  ..\buildlogs\reduce.img.blg


