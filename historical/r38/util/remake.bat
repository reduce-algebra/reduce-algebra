rem remake.bat -- build fasl versions of any updated source files.

rem Author: Anthony C. Hearn.

cd %reduce%

rem Build core system.

call util\remake2

rem Build packages in "packages" directory.

call %reduce%\upackage.bat

for %%p in %upackages% do call util\mkpckge %%p

if not exist lisp\%lisp%\%MACHINE%\mkreduce goto step

del lisp\%lisp%\%MACHINE%\mkreduce

call util\mkreduce

:step

for %%p in %upackages2% do call util\mkpckge %%p

for %%p in %upackages3% do call util\mkpckge %%p

set upackages=

set upackages2=

set upackages3=



