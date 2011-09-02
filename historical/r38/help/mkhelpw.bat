
REM -------------------------------------------------------------
REM 
REM   Compile REDUCE help info for Microsoft help compiler format
REM 
REM -------------------------------------------------------------

REM 

..\lisp\csl\win32\r38 mkhelpw.red -D@reduce=".." -Dpackage=redhelp -v -l mkhelpw.log

hcp reduce.hpj
