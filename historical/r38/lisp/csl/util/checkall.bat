REM check log files for all modules

REM main log files go in $srcdir/../../../log/*.rlg
REM reference logs are in $srcdir/../../../packages/XXX/xxx.rlg

if "x%1"=="x" (set srcdir=../cslbase) else set srcdir=%1

start /wait .\r38 -Dno_init_file %srcdir%/../util/checkall.red -D@srcdir=%srcdir% -Dwhich_module=%2 -- log/checkall.log



