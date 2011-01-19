================================================================================
# build
# -----
e:\opt\psl\0594\dist\psl-names.bat 
e:\opt\psl\0594\dist\show-psl-names.bat

%pxdist%\make-kernel.bat
%pxdist%\make-bare-psl.bat
%pxdist%\make-psl.bat
%pxdist%\make-pslcomp.bat
================================================================================
# debug
# -----
pushd  %pnkl%
gdb %psys%\bpsl-g.exe
dir e:/opt/psl/0594/dist/kernel/mingw-w64
--------------------------------------------------------------------------------
pushd %psys%

gdb bpsl-g.exe

set args -f bare-psl.exe.img
set args -f psl.exe.img
set args -f pslcomp.exe.img

dir e:/opt/psl/0594/dist/kernel/mingw-w64

b external_time
b external_timc
