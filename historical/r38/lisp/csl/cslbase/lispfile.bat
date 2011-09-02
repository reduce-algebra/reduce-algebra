REM first ensure that r2l.exe is built
REM      byacc -o r2l.c r2l.y
REM      wcl386 r2l.c
REM or equivalent under Unix!

r2l -rights extras.red extras.lsp
r2l -rights compiler.red compiler.lsp
r2l -rights ccomp.red ccomp.lsp

REM end
