REM-------------------------------------------------------------
REM
REM  Compile REDUCE help info for GNU info format
REM
REM-------------------------------------------------------------

start /w r36 mkinfo.red -v -l mkinfo.log

start /w r36 sed.red -v -l sed.log

del redhelp.x

makeinfo  --no-split -o redhelp.inf redhelp.y

del redhelp.y

REM To use the resulting redhelp.info, you need the Gnu "info" program.
REM Say "info -f redhelp.inf".

