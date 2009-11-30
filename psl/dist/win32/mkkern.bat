copy %psl%\comp\bare-psl.sym sun386.sym
%psl%\bin\win32\bpsl -f %psl%\bin\win32\pslcomp.img -td 8000000 < mkkern.sl  > mkkern.lst
