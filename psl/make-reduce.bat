set MACHINE=mingw-w64


echo

echo "PSL REDUCE is made for " mingw-w64
echo

cd ..\pslbuild

mkdir %MACHINE%
cd %MACHINE%
mkdir psl

mkdir red

mkdir buildlogs

copy  ..\%host%\Makefile .
copy ..\..\psl\dist\nonkernel\%MACHINE%\lap\* psl

copy ..\..\psl\dist\lap\%MACHINE%\* psl

copy ..\..\psl\dist\kernel\%MACHINE%\bpsl.exe psl\


pause

touch ..\..\psl/mkreduce

copy psl\nbig32.b psl\zbig.b

delete psl\*rlisp*.b

rem make

pause