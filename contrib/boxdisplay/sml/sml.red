% sml.red                                    Copyright A C Norman, June 2016

% **************************************************************************
% * Copyright (C) 2016, Codemist.                         A C Norman       *
% *                                                                        *
% * Redistribution and use in source and binary forms, with or without     *
% * modification, are permitted provided that the following conditions are *
% * met:                                                                   *
% *                                                                        *
% *     * Redistributions of source code must retain the relevant          *
% *       copyright notice, this list of conditions and the following      *
% *       disclaimer.                                                      *
% *     * Redistributions in binary form must reproduce the above          *
% *       copyright notice, this list of conditions and the following      *
% *       disclaimer in the documentation and/or other materials provided  *
% *       with the distribution.                                           *
% *                                                                        *
% * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
% * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
% * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
% * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
% * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
% * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
% * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
% * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
% * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
% * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
% * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
% * DAMAGE.                                                                *
% **************************************************************************

% $Id: $

% The code here parses (a subset of) SML and generates a Lisp
% tree from it. If the SML code is sufficiently simple this Lisp can
% be output as Rlisp code. It may be in more restricted cases, but
% sometimes it may be feasible to generate C or C++ code instead. The
% idea for this is that SML can be used as a prototyping language where its
% flexibility and strong type-checking keep eveything safe, and via
% this code it can ba mapped onto something that will run in more restricted
% contexts.

% This is also a first serious use of the Reduce LALR parser-generator.


on echo;
lisp;
load_package lalr;
on comp;

% When running using CSL arrange that errorset can never hide backtraces.
if getd 'enable!-errorset then enable!-errorset(3,3);

prec := '(
  !:left  "op"
  !:left  (!:infix9)
  !:right (!:infixr9)
  !:left  (!:infix8)
  !:right (!:infixr8)
  !:left  (!:infix7)
  !:left  ("*")       % because * is used in types too
  !:right (!:infixr7)
  !:left  (!:infix6)
  !:right (!:infixr6)
  !:left  (!:infix5)
  !:right (!:infixr5)
  !:left  ("=")       % because = used in many places as well as infix
  !:left  (!:infix4)
  !:right (!:infixr4)
  !:left  (!:infix3)
  !:right (!:infixr3)
  !:left  (!:infix2)
  !:right (!:infixr2)
  !:left  (!:infix1)
  !:right (!:infixr1)
  !:left  (!:infix0)
  !:right (!:infixr0)
  !:left  (":")
          ("->")
          ("andalso")
          ("orelse")
          ("handle")
          ("raise")
          ("else")
          ("do")
          ("of")
          ("fn")
          ("|")
          ("=>")
          ("as")
  )$

put('!*,   'lisp_name, 'times);
put('!/,   'lisp_name, 'quotient);
put('!%,   'lisp_name, 'remainder);
put('div,  'lisp_name, 'quotient);
put('mod,  'lisp_name, 'remainder);

put('!+,   'lisp_name, 'plus);
put('!-,   'lisp_name, 'difference);

put('!:!:, 'lisp_name, 'cons);

put('!>,   'lisp_name, 'greaterp);
put('!<,   'lisp_name, 'lessp);
put('!>!=, 'lisp_name, 'geq);
put('!<!=, 'lisp_name, 'leq);
%put('!=,   'lisp_name, 'equal);
put('!<!>, 'lisp_name, 'neq);

put('!:!=, 'lisp_name, 'set);

fluid '(filestack);

symbolic procedure process u;
  begin
    scalar v;
    terpri();
    princ "Input: ";
    if u = !$eof!$ then printc "<EndOfFile>" else prettyprint u;
    if u = !$eof!$ then <<
      if null filestack then error(1, "Unexpected end of file");
      close rds car filestack;
      printc "End of file - returning to previous file";
      filestack := cdr filestack;
% Almost unreasonably I MUST sort of fake in a semicolon where I
% switch files... 
      lex_char := '!;;
      lex_peek_char := nil >>
    else if eqcar(u, 'use) then <<
      u := cadr u;
      v := open(u, 'input);
      if null v then error(1, list("file", u, "could not be opened"));
      princ "+++ Reading from file "; print u;
      which_line := 1;
      if_depth := 0;
      for i := 0:63 do putv(last64, i, nil);
      last64p := 0;
      lex_char := '!;;
      lex_peek_char := nil;
      filestack := rds v . filestack >>
  end;

% The grammar used here is derived from one found at
%    https://www.mpi-sws.org/~rossberg/sml.html

% I am re-working the original grammar that I had here using information
% fron "The Definition of Standard ML (Revised)", 1997. At least that will
% be definitive! I hope it will let me get rid of syntactic ambiguity.

grammar := '(

 (toplevel ((progs "EOF")))

 (progs    ((prog) (process !$1))
           ((exp) (process !$1))
           ((progs prog) (process !$2))
           ((progs !:eof) (process !$eof!$)))

% Constants for SML should be
%     int      [~]<digits>
%              [~]0x<hexdigits>
%     float    [~]<digits>.<digits>[e[~]<digits>]
%     word     0w<digits>
%              0wx<hexdigits>
%     string   "<chars>"        may use "\" based escape sequence
%     char     #"<1-char>"

 (con    ((!:number))      % Note that lexer deals with "~1" for negative
         (("#" !:string))  % character literal
         ((!:string)))

 (digit  ((!:number)))

% I have changed the lexer so that aaa.bbb.ccc lexes as a single symbol.
% that means that I do not have any concept of "long id" here. That
% may simplify some matters, but if I implemented a full module system I
% would then need to dive inside ids that happened to be long to extract
% information about them.

 (lab    ((!:symbol))
         ((!:number)))

 (tupletail
         ((exp ")") nil)
         ((exp "," tupletail) (cons !$1 !$3)))

 (listtail
         ((exp "]") (list !$1))
         ((exp "," listtail) (cons !$1 !$3)))

 (seqtail
         ((exp ")") nil)
         ((exp ";" seqtail) (cons !$1 !$3)))

 (id_with_op
         ((!:symbol) !$1)
         (("op" opname) !$2))

% The words accepted in INFIX and INFIXR directives  should probably include
% things that have already been declared with an infix property. I want
% the identifier itself as my result...
% Also all sorts of other tokens will have been given special lexer codes but
% they should still be things that COULD be made infix... So I list the ones
% that I can think of here! This is really odd in that if (say) "->" is
% a single token then in the process of that case being noted as a dipthong
% the initial "-" will also be given its own lexer code... so I need to
% list initial substrings of any dipthong here. In most cases the token
% will start off as amere !:symbol items, but ones that I will map onto
% custom Lisp names are best noted explicitly here I think.

 (opname  ((!:symbol))
          (("*"))
          (("/"))
          (("%"))
          (("+"))
          (("-"))
          ((":"))
          (("::"))
          (("="))
          (("<"))
          (("<="))
          ((">"))
          ((">="))
          (("<>"))
          ((":="))
          ((!:infix0))
          ((!:infix1))
          ((!:infix2))
          ((!:infix3))
          ((!:infix4))
          ((!:infix5))
          ((!:infix6))
          ((!:infix7))
          ((!:infix8))
          ((!:infix9))
          ((!:infixr0))
          ((!:infixr1))
          ((!:infixr2))
          ((!:infixr3))
          ((!:infixr4))
          ((!:infixr5))
          ((!:infixr6))
          ((!:infixr7))
          ((!:infixr8))
          ((!:infixr9)))

 (opnames (((plus opname))))

 (emptylist (("[" "]")))

 (unit   (("(" ")")))

 (atexp  ((con))
         ((id_with_op) !$1)
         (("{" exprow "}"))
         (("#" lab))
         ((unit))                            % Unit
         (("(" exp "," tupletail))           % A tuple
         ((emptylist) 'empty_list)           % Empty list
         (("[" exp "]") (list 'list !$2))    % List of length 1
         (("[" exp "," listtail))            % Longer list
         (("(" exp ";" seqtail))             % Sequence
         ((letid dec "in" seqexps endid))
         (("(" exp ")") !$2))                % Mere parentheses

 (appexp ((atexp))
         ((appexp atexp)))

 (infexp ((appexp))
         ((infexp !:infix0 infexp) (list (get !$2 'lisp_name) !$1 !$3))
         ((infexp !:infix1 infexp) (list (get !$2 'lisp_name) !$1 !$3))
         ((infexp !:infix2 infexp) (list (get !$2 'lisp_name) !$1 !$3))
         ((infexp !:infix3 infexp) (list (get !$2 'lisp_name) !$1 !$3))
         ((infexp !:infix4 infexp) (list (get !$2 'lisp_name) !$1 !$3))
         ((infexp "=" infexp) (list 'equal !$1 !$3))
         ((infexp !:infix5 infexp) (list (get !$2 'lisp_name) !$1 !$3))
         ((infexp !:infix6 infexp) (list (get !$2 'lisp_name) !$1 !$3))
         ((infexp !:infix7 infexp) (list (get !$2 'lisp_name) !$1 !$3))
         ((infexp "*" infexp) (list 'times !$1 !$3))
         ((infexp !:infix8 infexp) (list (get !$2 'lisp_name) !$1 !$3))
         ((infexp !:infix9 infexp) (list (get !$2 'lisp_name) !$1 !$3))
         ((infexp !:infixr0 infexp) (list (get !$2 'lisp_name) !$1 !$3))
         ((infexp !:infixr1 infexp) (list (get !$2 'lisp_name) !$1 !$3))
         ((infexp !:infixr2 infexp) (list (get !$2 'lisp_name) !$1 !$3))
         ((infexp !:infixr3 infexp) (list (get !$2 'lisp_name) !$1 !$3))
         ((infexp !:infixr4 infexp) (list (get !$2 'lisp_name) !$1 !$3))
         ((infexp !:infixr5 infexp) (list (get !$2 'lisp_name) !$1 !$3))
         ((infexp !:infixr6 infexp) (list (get !$2 'lisp_name) !$1 !$3))
         ((infexp !:infixr7 infexp) (list (get !$2 'lisp_name) !$1 !$3))
         ((infexp !:infixr8 infexp) (list (get !$2 'lisp_name) !$1 !$3))
         ((infexp !:infixr9 infexp) (list (get !$2 'lisp_name) !$1 !$3))
         )


% I first look at the grammar as given in the specification, and note
% two particular messy cases which have to be reolved by a from of
% precedence.
%     if A then B else C handle ...
% must lead to a shift rather than a reduce. This case can be covered to
% giving HANDLE and ELSE precedence settings. Indeed I hope that by
% giving most of the keywords used here precedence values the apparent
% ambiguities can all be resolved.

 (exp    ((infexp))
         ((exp ":" typ))
         ((exp "andalso" exp) (list 'and !$1 !$3))
         ((exp "orelse" exp) (list 'or !$1 !$3))
         ((exp "handle" match))
         (("raise" exp))
         (("if" exp "then" exp "else" exp)
             (list 'cond
                (list !$2 !$4)
                (list t !$6)))
         (("while" exp "do" exp)) 
         (("case" exp "of" match))
         (("fn" match))
         )

 (localid
         (("local") (startcontext)))
 (letid  (("let") (printc "+++ LET detected")
                  (startcontext)))
 (endid  (("end") (endcontext)))

 (seqexps((exp))
         ((seqexps ";" exp)))

 (exprow ((lab "=" exp))
         ((lab "=" exp "," exprow)))

 (match  ((onematch) !$1)
         ((onematch "|" match)))

 (tracedpat ((pat) !$1))

 (onematch ((tracedpat "=>" exp)))

 (pat1   ((atpat))
         ((id_with_op atpat))
         ((pat1 !:infix0 pat1) (list (get !$2 'lisp_name) !$1 !$3))
         ((pat1 !:infix1 pat1) (list (get !$2 'lisp_name) !$1 !$3))
         ((pat1 !:infix2 pat1) (list (get !$2 'lisp_name) !$1 !$3))
         ((pat1 !:infix3 pat1) (list (get !$2 'lisp_name) !$1 !$3))
         ((pat1 !:infix4 pat1) (list (get !$2 'lisp_name) !$1 !$3))
% The rules of ML are that "=" may not be re-bound, and hence it can
% not end up as a constructor. Specifically that means it can not end
% up in use as as infix constructor in a patten.
% I will leave the syntax rule in here but commented out mostly so that
%  divergence between the rules here for patterns and the mostly matching
%  ones for expressions can be compared.
%        ((pat1 "=" pat1) (list 'equal !$1 !$3))
         ((pat1 !:infix5 pat1) (list (get !$2 'lisp_name) !$1 !$3))
         ((pat1 !:infix6 pat1) (list (get !$2 'lisp_name) !$1 !$3))
         ((pat1 !:infix7 pat1) (list (get !$2 'lisp_name) !$1 !$3))
         ((pat1 "*" pat1) (list 'times !$1 !$3))
         ((pat1 !:infix8 pat1) (list (get !$2 'lisp_name) !$1 !$3))
         ((pat1 !:infix9 pat1) (list (get !$2 'lisp_name) !$1 !$3))
         ((pat1 !:infixr0 pat1) (list (get !$2 'lisp_name) !$1 !$3))
         ((pat1 !:infixr1 pat1) (list (get !$2 'lisp_name) !$1 !$3))
         ((pat1 !:infixr2 pat1) (list (get !$2 'lisp_name) !$1 !$3))
         ((pat1 !:infixr3 pat1) (list (get !$2 'lisp_name) !$1 !$3))
         ((pat1 !:infixr4 pat1) (list (get !$2 'lisp_name) !$1 !$3))
         ((pat1 !:infixr5 pat1) (list (get !$2 'lisp_name) !$1 !$3))
         ((pat1 !:infixr6 pat1) (list (get !$2 'lisp_name) !$1 !$3))
         ((pat1 !:infixr7 pat1) (list (get !$2 'lisp_name) !$1 !$3))
         ((pat1 !:infixr8 pat1) (list (get !$2 'lisp_name) !$1 !$3))
         ((pat1 !:infixr9 pat1) (list (get !$2 'lisp_name) !$1 !$3))
         ((id_with_op "as" pat1))
         )

 (pat    ((pat1))
         ((pat ":" typ))
% This rule is over-generous, in that the only case actually allowed
% is '["op"] id ":" typ "as" pat1' but then if you see an identifier x
% followed by a colon you know you next have to read a type, but until
% you have looked way forward to see if the word "as" is coming you can not
% be certain if the identifier should be reduced all the way to pat before
% having the type attached.

         ((pat ":" typ "as" pat1))
         )

 (opttyp (())
         ((":" typ)))

 (atpat  ((con) !$1)
         (("_"))
         ((id_with_op) !$1)
         (("{" patrow "}"))
         ((unit))
         ((emptylist))
         (("[" patseq "]"))
         (("(" patseq ")")))

 (patseq ((pat))
         ((patseq "," pat)))

 (patrow (("..."))
         ((lab "=" pat optmorepatrow))
         ((!:symbol opttyp (opt "as" pat) optmorepatrow)))

 (optmorepatrow (())
         (("," patrow)))

 (tyseq  ((typ))
         ((typ "," tyseq)))

 (attyp  ((!:typename))
         (("{" typrow "}"))
         (("(" typ ")"))
         ((!:symbol)))

 (typ1   ((attyp))
         ((typ1 !:symbol))
         (("(" typ "," tyseq ")" !:symbol))
         )

 (typ2   ((typ1))
         ((typ2 "*" typ1))
         )

 (typ3   ((typ2))
         ((typ2 "->" typ3)))

 (typ    ((typ3))
         )

 (labtyp ((lab ":" typ)))

 (typrow ((labtyp))
         ((typrow "," labtyp)))

 (tyvarseq
         ((!:typename))
         (("(" tvs2 ")")))

 (tvs2   ((!:typename))
         ((tvs2 "," !:typename)))

 (dec1   (("val" valbind))
         (("val" tyvarseq valbind))
         (("fun" fvalbind))
         (("fun" tyvarseq fvalbind))
         (("type" typbind))
         (("datatype" datbind))
         (("datatype" datbind "withtype" typbind))
         (("datatype" !:symbol "=" "datatype" !:symbol))
         (("abstype" datbind "with" dec "end"))
         (("abstype" datbind "withtype" typbind "with" dec "end"))
         (("exception" exnbind))
%        (("structure" strbind))
         ((localid dec "in" dec endid))
%        (("open" !:symbol))   % Could have multiple ids here
         (("nonfix" opnames) (makeinfix !$2 0 'none))
         (("infix" opnames) (makeinfix !$2 0 'left))
         (("infix" digit opnames) (makeinfix !$3 !$2 'left))
         (("infixr" opnames) (makeinfix !$2 0 'right))
         (("infixr" digit opnames) (makeinfix !$3 !$2 'right))
         )

 (dec    ((dec1))
         ((dec dec1))
         ((dec ";" dec1)))


 (valbind
           (("rec" pat "=" exp "and" valbind))
           (("rec" pat "=" exp))
           ((pat "=" exp "and" valbind))
           ((pat "=" exp))
           )

 (fvalbind ((nfvalbindings (opt "and" fvalbind))))

 (nfvalbindings ((onefvalbinding))
           ((nfvalbindings "|" onefvalbinding)))

 (onefvalbinding
          ((id_with_op (plus atpat) opttyp "=" exp)))

 (typbind  ((!:symbol "=" typ (opt "and" typbind)))
           ((tyvarseq !:symbol "=" typ (opt "and" typbind))))

 (datbind  ((!:symbol "=" conbind (opt "and" datbind)))
           ((tyvarseq !:symbol "=" conbind (opt "and" datbind))))

 (optoftyp (())
           (("of" typ)))

 (conbind  ((id_with_op optoftyp (opt "|" conbind))))

 (optandexnbind
           (())
           (("and" exnbind)))

 (exnbind  ((id_with_op optoftyp optandexnbind))
           ((id_with_op "=" !:symbol optandexnbind)))

% (str)
% (strbind)
% (sig)
% (typrefin)
% (spec)
% (valdesc)
% (typdesc)
% (detdesc)
% (condest)
% (exndesc)
% (strdesc)

% The syntax that I started from did not include the possibility of an
% expression here. That sort of makes sense because consider
%   fun foo f = f
%   22;
% which could (potentially) either parse as a function definition followed
% by an expression or as a function definition with RHS "f 22". To try to
% avoid this ambiguity I am going to insist that there be (at least one)
% semicolon ahead of any expression to separate it from the previous
% input.
% This is much like the need for a semicolon if one wrote
%   1+2
%   3+4;
% to avoid that being parse as something that wanted to use 2 as a function
% applied to the argument 3. I rather hope that all declarations start with
% keywords and so the issue of where one endsd and the next starts will
% not be a severe problem.

(prog     ((dec1))
          ((";" exp) !$2)
          ((";") nil)
%         (("functor" fctbind))
%         (("signature" sigbind))
          )

% (fctbind)
% (sigbind)
%
  )$

fluid '(lexer_context context_stack);

global '(infix_lookup);
infix_lookup := mkhash(30, 2, 1.5)$

<< puthash('(0 . none), infix_lookup, get('!:symbol, 'lex_fixed_code));
   puthash('(1 . none), infix_lookup, get('!:symbol, 'lex_fixed_code));
   puthash('(2 . none), infix_lookup, get('!:symbol, 'lex_fixed_code));
   puthash('(3 . none), infix_lookup, get('!:symbol, 'lex_fixed_code));
   puthash('(4 . none), infix_lookup, get('!:symbol, 'lex_fixed_code));
   puthash('(5 . none), infix_lookup, get('!:symbol, 'lex_fixed_code));
   puthash('(6 . none), infix_lookup, get('!:symbol, 'lex_fixed_code));
   puthash('(7 . none), infix_lookup, get('!:symbol, 'lex_fixed_code));
   puthash('(8 . none), infix_lookup, get('!:symbol, 'lex_fixed_code));
   puthash('(9 . none), infix_lookup, get('!:symbol, 'lex_fixed_code));
   puthash('(0 . left), infix_lookup, get('!:infix0, 'lex_fixed_code));
   puthash('(1 . left), infix_lookup, get('!:infix1, 'lex_fixed_code));
   puthash('(2 . left), infix_lookup, get('!:infix2, 'lex_fixed_code));
   puthash('(3 . left), infix_lookup, get('!:infix3, 'lex_fixed_code));
   puthash('(4 . left), infix_lookup, get('!:infix4, 'lex_fixed_code));
   puthash('(5 . left), infix_lookup, get('!:infix5, 'lex_fixed_code));
   puthash('(6 . left), infix_lookup, get('!:infix6, 'lex_fixed_code));
   puthash('(7 . left), infix_lookup, get('!:infix7, 'lex_fixed_code));
   puthash('(8 . left), infix_lookup, get('!:infix8, 'lex_fixed_code));
   puthash('(9 . left), infix_lookup, get('!:infix9, 'lex_fixed_code));
   puthash('(0 . right), infix_lookup, get('!:infixr0, 'lex_fixed_code));
   puthash('(1 . right), infix_lookup, get('!:infixr1, 'lex_fixed_code));
   puthash('(2 . right), infix_lookup, get('!:infixr2, 'lex_fixed_code));
   puthash('(3 . right), infix_lookup, get('!:infixr3, 'lex_fixed_code));
   puthash('(4 . right), infix_lookup, get('!:infixr4, 'lex_fixed_code));
   puthash('(5 . right), infix_lookup, get('!:infixr5, 'lex_fixed_code));
   puthash('(6 . right), infix_lookup, get('!:infixr6, 'lex_fixed_code));
   puthash('(7 . right), infix_lookup, get('!:infixr7, 'lex_fixed_code));
   puthash('(8 . right), infix_lookup, get('!:infixr8, 'lex_fixed_code));
   puthash('(9 . right), infix_lookup, get('!:infixr9, 'lex_fixed_code));
   nil >>;

symbolic procedure makeinfix(id, prec, dirn);
  begin
% Allow for multiple declarations in one.
    if not atom id then <<
      for each x in id do makeinfix(x, prec, dirn);
      return nil >>;
    if not zerop posn() then terpri();
    princ "@@@ Identifier "; princ id; princ " is now an operator: ";
    princ prec; princ "  "; printc dirn;
    lexer_context := list('type, id, get(id, 'lex_code)) . lexer_context;
    put(id, 'lex_code, gethash(prec . dirn, infix_lookup));
    return nil
  end;

symbolic procedure startcontext();
  begin
    context_stack := lexer_context . context_stack;
    lexer_context := nil;
    if not zerop posn() then terpri();
    printc "Starting a nested context";
  end;

symbolic procedure endcontext();
  begin
    if not zerop posn() then terpri();
    printc "Ending a nested context";
% I now need to unwind any local type and infix declarations...
    for each p in lexer_context do
      if eqcar(p, 'infix) then put(cadr p, 'lex_code, cddr p)
      else printf("+++ Unknown context save: %p%n", p);
    lexer_context := car context_stack;
    context_stack := cdr context_stack;
  end;

% While debugging it may be helpful to see the grammar diplayed with
% indentation normalised...
%
% << terpri(); prettyprint grammar; nil >>;

% This will tend to lead to a LOT of output - much of which will be hard to
% decode. But while debugging the grammar it may be necessary.
% on lalr_verbose;

pp := lalr_create_parser(prec, grammar)$

lexer_style!* := lexer_style_sml + 0x40; % Support #if and #eval too!

% If parsing the SML code fails I will just exit from Reduce. Otherwise
% it is likely that I will be faced with a mess of further silly messages
% as Reduce tries to make sense if SML input itself.
% I think I may need an option within lalr for parsing from a file, such
% that errors merely close that file and return to using Reduce on
% an outer file... ie so that parsed and regular Reduce stuff are kept
% more separate.

on parse_errors_fatal;

begin
   scalar !*raise, !*lower;
   lex_init();
   yyparse pp
end;

use "Library_Reduce.sml";

(* I will often put test fragments of code here to see if I can
   parse them - and then later on so I can adjust the generated parse trees
   until they are reasonably Lisp-like. *)

  fun getList size file  =
    let val _  =  TextIO.inputLine file
        val (info, eof)  =  getInfo size file
    in
      if eof then [info]
      else info :: getList size file
    end

;

(*
 This is the Dutch version of TeX Maths Layout coded in SML, adjusted so
 it only uses a subset of SML. It also has some extensions that add support
 for accents and delimiters, and the aim is that eventually it should
 cover all maths. The stuff here reads in all the source files in an order
 which is safe.
*)

use "General.sml";
use "Powers2.sml";
use "BasicTypes.sml";
use "Distance.sml";
use "Size.sml";
use "FontTypes.sml";
use "LoadFont.sml";
use "FontVector.sml";
use "CharInfo.sml";
use "CharFunctions.sml";
use "Const.sml";
use "FontParams.sml";
use "StyleParams.sml";
use "BoxTypes.sml";
use "BasicBox.sml";
use "NodeDim.sml";
use "NodeListDim.sml";
use "GlueCalculation.sml";
use "HListGlue.sml";
use "BoxPack.sml";
use "MakeVBox.sml";
use "AxisCenter.sml";
use "ChangeStyle.sml";
use "Radical.sml";
use "BasicChar.sml";
use "MakeChar.sml";
use "Accent.sml";
use "MakeLine.sml";
use "MakeAtop.sml";
use "MakeFract.sml";
use "Delimiter.sml";
use "GenFraction.sml";
use "MakeLimOp.sml";
use "MakeScripts.sml";
use "MathTypes.sml";
use "Kind.sml";
use "MathSpace.sml";
use "MathGlue.sml";
use "Spacing.sml";
use "IListTypes.sml";
use "IListDim.sml";
use "ChangeKind.sml";
use "MathPenalty.sml";
use "Boundaries.sml";
use "IListTranslate.sml";
use "MathTranslate.sml";
use "Formula.sml";
use "Out.sml";
use "OutHigh.sml";
use "OutDvi.sml";
use "DviState.sml";
use "DviCmd.sml";
use "SetNode.sml";
use "SetBox.sml";
use "ShipOut.sml";
use "Input.sml";
use "test.sml";

(* End of everything *)
EOF
;
quit;
