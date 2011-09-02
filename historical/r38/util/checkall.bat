rem checkall --- Check all REDUCE Test Files against Exemplary logs.

rem Author: Anthony C. Hearn.

del %reduce%\log\checkall.log

set dif=fc

call %reduce%\xpackage.bat

for %%x in %xpackages% do call perl %reduce%\util\chckallp.pl %%x

for %%x in %xpackages2% do call perl %reduce%\util\chckallp.pl %%x

for %%x in %xpackages3% do call perl %reduce%\util\chckallp.pl %%x

set dif=

set xpackages=

set xpackages2=

set xpackages3=
