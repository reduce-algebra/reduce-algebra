% Create bytes.h out of opcodes.red
%
% Run ONCE when opcodes.red is created and then leave as documentation!
% Also after generating bytes.h you need to go
%    filesign -u bytes.h
% to get its signature correct.



%%
%% Copyright (C) 2014, A C Norman, Codemist Ltd.                          *
%%                                                                        *
%% Redistribution and use in source and binary forms, with or without     *
%% modification, are permitted provided that the following conditions are *
%% met:                                                                   *
%%                                                                        *
%%     * Redistributions of source code must retain the relevant          *
%%       copyright notice, this list of conditions and the following      *
%%       disclaimer.                                                      *
%%     * Redistributions in binary form must reproduce the above          *
%%       copyright notice, this list of conditions and the following      *
%%       disclaimer in the documentation and/or other materials provided  *
%%       with the distribution.                                           *
%%                                                                        *
%% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
%% "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
%% LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
%% FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
%% COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
%% INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
%% BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
%% OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
%% ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
%% TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
%% THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
%% DAMAGE.                                                                *
%%

% $Id$

symbolic;

global '(s!:opcodelist);

if not boundp '!@cslbase then !@cslbase := "../cslbase";

off lower;
in "$cslbase/opcodes.red"$
on lower;

begin
    scalar o, oo, n;
    o := open("$cslbase/bytes.h", 'output);
    oo := wrs o;

    printc "/* bytes.h                             Copyright (C) Codemist 1993-2004 */";
    terpri();
    printc "/* Signature: 38cd8141 31-Mar-2004 */";
    terpri();
    printc "/*";
    printc " *   Bytecode interpreter support.";
    printc " *";
    printc " *   April 1993";
    printc " */";
    terpri();
%   printc "#define JUMP_BACK               0x01 /* select direction of jump  */";
%   printc "#define JUMP_LONG               0x02 /* select 16 vs 8 bit offset */";
%   terpri();
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
    o := open("$cslbase/opnames.c", 'output);
    oo := wrs o;
    printc "/* opnames.c                           Copyright (C) Codemist 1993-2004 */";
    terpri();
    printc "/* Signature: 38cd8141 31-Mar-2002 */";
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
