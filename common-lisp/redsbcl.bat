@echo off
rem Start the Windows SBCL REDUCE image
rem See "help call" for expansion of batch script argument references.
sbcl --noinform  --core %~dp0fasl.sbcl\reduce.img
