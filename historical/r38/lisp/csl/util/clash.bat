REM Look for name-clashes in REDUCE

if "x%1"=="x" (set srcdir=../cslbase) else set srcdir=%1

start /wait .\slowr38 -v -Dno_init_file %srcdir%/../util/clash.red -D@srcdir=%srcdir% -- log/clash.log


