@echo off
rem Start the Windows CCL REDUCE image
rem See "help call" for expansion of batch script argument references.
ccl -I %~dp0fasl.ccl\reduce.image
