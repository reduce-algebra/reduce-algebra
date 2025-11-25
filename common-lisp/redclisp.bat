@echo off
rem Start Windows CLISP REDUCE.
clisp -M %~dp0fasl.clisp\reduce.mem %*
