@echo off
rem Start Windows CCL REDUCE.
rem See "help call" for expansion of batch script argument references.
WHERE ccl64 /Q
IF ERRORLEVEL 1 (
   ccl -I %~dp0fasl.ccl\reduce.image
) ELSE (
   ccl64 -I %~dp0fasl.ccl\reduce.image
)
