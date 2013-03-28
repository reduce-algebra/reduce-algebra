@off echo

set proot=%psl%
set psys=%proot%\bin\mingw-w64
rem # All PSL executables go here.
set pl=%psl%\dist\lap\mingw-w64
rem # Loadable files

set pk=%psl%\dist\kernel
rem # Machine-independent kernel sources
set pxk=%psl%\dist\kernel\mingw-w64
rem # Machine specific kernel sources

set pnk=%psl%\dist\nonkernel
rem # Machine-independent non-kernel
set pxnk=%psl%\dist\nonkernel\mingw-w64
rem # Machine specific non-kernel
set pnkl=%psl%\dist\nonkernel\mingw-w64\lap
rem # Non-Kernel binaries

set pc=%psl%\dist\comp
rem # Machine-independent compiler sources
set pxc=%psl%\dist\comp\mingw-w64
rem # Machine specific compiler sources

set pu=%psl%\dist\util
rem # Machine-independent utility programs
set pxu=%psl%\dist\util\mingw-w64
rem # Machine specific utility program sources

set pdist=%psl%\dist\distrib
rem # Distribution support

