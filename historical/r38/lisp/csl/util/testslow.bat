REM test all modules, but using the bootstrap (slow) version of REDUCE

REM main log files go in ../../../log/*.rlg

if "x%1"=="x" (set srcdir=../cslbase) else set srcdir=%1

start /wait .\slowr38 -v -Dno_init_file -Dwhich_module=%2 -D@srcdir=%srcdir% %srcdir%/../util/testall.red -- log/testslow.log





