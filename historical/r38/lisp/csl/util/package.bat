rem package.bat --- Recompile just one module of REDUCE

rem Author: Arthur C Norman

if "x%1"=="x" (set srcdir=../cslbase) else set srcdir=%1

start /wait .\r38 -Dno_init_file -Dtarget=%2 %srcdir%/../util/package.red -D@srcdir=%srcdir% -- log/%1.log


