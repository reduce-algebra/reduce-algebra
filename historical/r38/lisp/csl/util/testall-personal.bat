REM test all modules

REM main log files go in log/*.rlg

.\r38 -v util/testall.red -Dno_init_file -Dwhich_module=%1 -- log/testall.log


