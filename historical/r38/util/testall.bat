rem Run all REDUCE Test Files

call %reduce%\xpackage.bat

for %%p in %xpackages% do call %reduce%\util\tstpckge %%p

for %%p in %xpackages2% do call %reduce%\util\tstpckge %%p

for %%p in %xpackages3% do call %reduce%\util\tstpckge %%p

set xpackages=

set xpackages2=

set xpackages3=
