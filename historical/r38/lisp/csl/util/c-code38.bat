REM c-code38.bat.   generate C code...
REM Optionally limit how many functions to compile

if "x%1"=="x" (set srcdir=../cslbase) else set srcdir=%1

start /wait .\slowr38 -Dno_init_file %srcdir%/../util/c-code38.red -D@srcdir=%srcdir% -Dhow_many=%2 -- log/c-code38.log


