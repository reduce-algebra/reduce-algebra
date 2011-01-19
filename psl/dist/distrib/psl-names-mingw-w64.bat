@echo off

set machine=mingw-w64
set proot=c:\users\winfried\Desktop\reduce-algebra-winx64\trunk\psl\

set plogs=%proot%\logs

rem Top of PSL tree.
set psl=%proot%\dist

rem Top of PCLS tree.
set cl=%proot%\pclsdist

rem All PSL executables go here.
set psys=%proot%\bin\%machine%

rem Loadable files
set pl=%proot%\dist\lap\%machine%
rem Non-Kernel binaries
set pnkl=%pnk%\%machine%\lap
rem Lap directory for local stuff.
set pll=%proot%\llap
rem Lap directory for local stuff.
set pnkll=%proot%\llapnk

rem Put site specific source files here.
set plcl=%proot%\local

rem Machine-independent kernel sources
set pk=%psl%\kernel
rem Machine specific kernel sources
set pxk=%psl%\kernel\%machine%

rem Machine-independent non-kernel
set pnk=%psl%\nonkernel
rem Machine specific non-kernel
set pxnk=%psl%\nonkernel\%machine%

rem Machine-independent compiler sources
set pc=%psl%\comp
rem Machine specific compiler sources
set pxc=%psl%\comp\%machine%

rem Machine-independent utility programs
set pu=%psl%\util
rem Machine specific utility program sources
set pxu=%psl%\util\%machine%

rem Distribution support
set pdist=%psl%\distrib
rem Distribution support, Machine specific
set pxdist=%psl%\distrib\%machine%
