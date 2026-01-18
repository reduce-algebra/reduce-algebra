@echo off
rem Start Windows CLISP REDUCE.
clisp -ansi -norc -E utf-8 -M %~dp0fasl.clisp\reduce.mem %*
