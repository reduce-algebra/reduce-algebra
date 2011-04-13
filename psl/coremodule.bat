echo build core module %1 for architecture %2

set current=%cd%
set here=%cd%\..\pslbuild\winx64\psl
cd %here%
set fasl=red
set reduce=%current%\..
bpsl -td 600 -f red/bootstrap.img X < %current%\coremodule.dat > ..\buildlogs/%1.blg
