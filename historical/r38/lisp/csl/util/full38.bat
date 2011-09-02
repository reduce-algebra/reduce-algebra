rem full38.bat --- Build REDUCE 3.8 under Windows using CSL.

rem Author: Arthur C Norman

if "x%1"=="x" (set srcdir=../cslbase) else set srcdir=%1

set reduce=

start /wait .\r38 -v -z -Dno_init_file %srcdir%/../util/build38.lsp -D@srcdir=%srcdir% -- log/full38.log


