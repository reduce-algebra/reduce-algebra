@echo off
call %psl%\distrib\psl-names
pushd  %pnkl%
echo (setq loaddirectories* '("" "%pl%\"))             >%temp%\job
echo (savesystem "bare-psl" "%psys%\bpsl" 'nil)        >>%temp%\job
echo (quit)                                            >>%temp%\job
%pxk%\bpsl < %temp%\job
popd
