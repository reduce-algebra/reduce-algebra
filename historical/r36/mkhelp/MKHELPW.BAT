
REM -------------------------------------------------------------
REM 
REM   Compile REDUCE help info for Microsoft help compiler format
REM 
REM -------------------------------------------------------------

start /w r36 mkhelpw.red -Dpackage=redhelp -v -l mkhelpw.log

hc31 r36.hpj

