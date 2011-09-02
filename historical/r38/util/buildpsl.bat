rem Bootstrap REDUCE from scratch, building a minimal REDUCE plus
rem a full set of fasl files from a PSL system and REDUCE sources only.

set lisp=psl

cd %reduce%

if exist lisp\psl\%MACHINE%\red\reduce.img goto step2

call util\dbuild

:step2

call util\remake
