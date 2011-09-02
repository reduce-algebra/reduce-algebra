REM test all modules

REM main log files go in ../../../log/*.rlg

if "x%1"=="x" (set srcdir=../cslbase) else set srcdir=%1

start /wait .\r38 -v %srcdir%/../util/testall.red -Dno_init_file -D@srcdir=%srcdir% -Dwhich_module=%2 -- log/testall.log


