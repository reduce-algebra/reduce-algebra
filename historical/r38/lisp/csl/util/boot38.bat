rem boot38.bat --- Build REDUCE 3.8 under Windows using CSL.

rem Author: Arthur C Norman

REM this takes around 4 minutes on a P6-400 and much less on
REM a more modern computer.

if "x%1"=="x" (set srcdir=../cslbase) else set srcdir=%1

set reduce=

start /wait .\slowr38 -v -z -Dno_init_file -D@srcdir=%srcdir% %srcdir%/../util/build38.lsp -- log/boot38.log


