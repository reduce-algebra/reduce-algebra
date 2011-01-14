rem @echo off

set bpssize=67108864
pushd  %pxk%

as -g -o dmain-g.o dmain.s
as -g -o main-g.o main.s
gcc -m64 -g -o bpsl-g.exe -DBPSSIZE=%bpssize% bps.c bpsheap.c  echo.c file-status.c float.c os-hooks.c  pslextras.c pslsocket.c pwd-fn.c sigs.c  unix-io.c creloc.c  main-g.o dmain-g.o -lm -lwsock32

as  -o dmain.o dmain.s
as  -o main.o main.s
gcc -m64  -o bpsl.exe -DBPSSIZE=%bpssize% bps.c bpsheap.c  echo.c file-status.c float.c os-hooks.c  pslextras.c pslsocket.c pwd-fn.c sigs.c  unix-io.c creloc.c  main.o dmain.o -lm -lwsock32

copy /b *.exe %psys%\
popd
