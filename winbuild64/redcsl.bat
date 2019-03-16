@echo off
set h=%~dp0
set reduce=%h%..
"%reduce%\lib\csl\reduce.exe" %*
