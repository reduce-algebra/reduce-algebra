
echo build noncore module %1 for architecture %2

set current=%cd%^M
set here=%cd%\..\pslbuild\winx64\psl^M
cd %here%^M
bpsl.exe  -td 600 < %current%\noncoremodule.dat >  ..\buildlogs\%1%.blg ^M
