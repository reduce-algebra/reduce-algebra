REM profile all modules

REM results go to "profile.dat"

REM Note: on a 400 MHz Pentium II this uses around 1 hour of CPU time.

if "x%1"=="x" (set srcdir=../cslbase) else set srcdir=%1

start /wait .\slowr38 -v -Dno_init_file %srcdir%/../util/profile.red -D@srcdir=%srcdir% -- log/profile.log


