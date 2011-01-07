@call d:\psl\distrib\mkpnknt d:\psl\nonkern\winnt sys-extras 
@if errorlevel 1 goto ende
@echo " System dependent files built. " 
@if errorlevel 1 goto ende
:ende

