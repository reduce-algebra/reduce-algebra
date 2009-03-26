setlocal
@echo off
if "%1%"=="" goto syntax

rem Look at what has been 'save'd by gnuplot, write out only differencies.
rem Written by Petr Mikulik

rem How does this work:
rem 1. save default settings to a temporary file
rem 2. run diff + grep/sed over the temporary and input file
rem 3. delete temporary file

rem Requirements: GNU diff, grep, sed

set GP_TMP_SAVE=%TMP%\$gp$save$.gp
echo save '%GP_TMP_SAVE%' | gnuplot
diff -w %GP_TMP_SAVE% %1 | grep ">" | sed "s/^> //"
del %GP_TMP_SAVE%
goto exit

:syntax
echo Look at what has been 'save'd by gnuplot, write out only differencies.
echo Syntax: gpsavediff FILE.gp
echo (output is written on stdout)

endlocal
:exit
