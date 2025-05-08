@call c:\psl\distrib\make-lap c:\psl\util\dos386 defmacro 
@if errorlevel 1 goto ende
@call c:\psl\distrib\make-lap c:\psl\util\dos386 arith387 
@if errorlevel 1 goto ende
@echo " UTIL frisch " 
@if errorlevel 1 goto ende
:ende

