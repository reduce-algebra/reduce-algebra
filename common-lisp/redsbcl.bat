@echo off
rem Start Windows SBCL REDUCE.
rem See "help call" for expansion of batch script argument references.
sbcl --noinform --core %~dp0fasl.sbcl\reduce.img %*
rem Useful command-line arguments:
rem   --control-stack-size megabytes
rem     Size of control stack reserved for each thread in megabytes.
rem     Default value is 2
rem   --dynamic-space-size megabytes
rem     Size of the dynamic space reserved on startup in megabytes.
rem     Default value is platform dependent.
