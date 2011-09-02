% Create bytes.h out of opcodes.red

symbolic;

global '(s!:opcodelist);

off lower;
in "../cslbase/opcodes.red"$
on lower;

begin
    scalar o, oo, n;
    o := open("../cslbase/bytes.h", 'output);
    oo := wrs o;

    printc "/* bytes.h                             Copyright (C) Codemist 1993-99 */";
    terpri();
    printc "/* Signature: 38cd8141 31-Mar-1993 */";
    terpri();
    printc "/*";
    printc " *   Bytecode interpreter support.";
    printc " *";
    printc " *   April 1993";
    printc " */";
    terpri();
    printc "#define JUMP_BACK               0x01 /* select direction of jump  */";
    printc "#define JUMP_LONG               0x02 /* select 16 vs 8 bit offset */";
    terpri();
    n := 0;
    for each v in s!:opcodelist do <<
      princ "#define OP_";
      princ v;
      ttab 32;
      princ "0x";
      if n < 16 then princ "0";
      prinhex n;
      terpri();
      n := n + 1 >>;
    terpri();
    printc "/* end of bytes.h */";
    terpri();
    wrs oo;
    close o;
    o := open("../cslbase/opnames.c", 'output);
    oo := wrs o;
    printc "/* opnames.c                           Copyright (C) Codemist 1993-99 */";
    terpri();
    printc "/* Signature: 38cd8141 31-Mar-1993 */";
    terpri();
    terpri();
    printc "static char *opnames[256] =";
    printc "{";
    n := 0;
    for each v in s!:opcodelist do <<
      princ "   "; princ '!";
      princ v; princ '!";
      princ ",";
      ttab 32;
      princ "/* 0x";
      if n < 16 then princ "0";
      prinhex n;
      printc " */";
      n := n + 1 >>;
    while n < 256 do <<
      princ "   "; princ '!"; princ "xxxx"; princ '!";
      if n neq 255 then princ ",";
      ttab 32;
      princ "/* 0x";
      if n < 16 then princ "0";
      prinhex n;
      printc " */";
      n := n + 1 >>;
    printc "};";
    terpri();
    wrs oo;
    close o;
    return "bytes.h and opcodes.c made"
end;


bye;
