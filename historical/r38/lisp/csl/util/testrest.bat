REM test all modules whose logs are not already up to date

REM main log files go in $srcdir/../../../log/*.rlg

if "x%1"=="x" (set srcdir=../cslbase) else set srcdir=%1

start /wait .\r38 -v %srcdir%/../util/testrest.red -Dno_init_file -D@srcdir=%srcdir% -Dwhich_module=%2 -- log/testrest.log


