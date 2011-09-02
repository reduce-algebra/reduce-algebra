% Create demobyte.h out of opcodes.red

symbolic;

if not boundp 'demo_key or
   not stringp demo_key then <<
   fluid '(demo_key);
% The following line looks WIERD but its purpose is to delay this job for
% a while and cause lots of garbage collections (typically a couple of dozen,
% taking around 30 seconds on my reference computer). This gives time for
% the random number generator in CSL to seed itself a bit better. The user
% might like to run other applications, move the CSL window and otherwise
% generate events while this is going on! As an alternative the user can
% provide an explicit initial key via -Ddemo_key=nnn+mmm and take full
% personal responsibility.
   for i := 1:10000000 do cons(nil, nil);
   demo_key := list!-to!-string
      append(explodec random!-fixnum(), '!+ . explodec random!-fixnum()) >>$

demo_key := compress('!( . append(explodec demo_key, '(!))));

demo_key := car demo_key . cadr demo_key$

global '(s!:opcodelist);

off lower;
in "../cslbase/opcodes.red"$
on lower;

begin
    scalar o, oo, n;
    o := open("../cslbase/demobyte.h", 'output);
    oo := wrs o;

    printc "/* demobyte.h                             Copyright (C) Codemist 1999 */";
    terpri();
    printc "/* Signature: 38cd8141 31-Mar-1993 */";
    terpri();
    printc "/*";
    printc " *   Bytecode interpreter support.";
    printc " *";
    printc " *   March 1999";
    printc " *   Confidential file: do not distribute EVER";
    printc " */";
    terpri();
    princ "int32 demo_key1 = "; prin car demo_key;
    princ ", demo_key2 = "; princ cdr demo_key; printc ";";
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
    printc "/* end of demobyte.h */";
    terpri();
    wrs oo;
    close o;
    return "demobyte.h made"
end;


bye;
