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
off errcont;


% First I will have a rather simple lambda-calculus interpreter. I do this
% so it can cope with lexical scoping, higher order functions and the other
% proper things that Standard Lisp is a bit shoddy about.

% Well at present if this code evaluates a name that is not visible in its
% environment it looks up a static calue (with the 'smlvalue property tag).
% This is incorrect as it stands. But leter on I can fix it by using some
% alpha-conversion on the input. I will need to make a transformation
% broadly along the lines
%     ORIGINAL                 REWRITTEN
%    val x = 1;               val x = 1;
%    val x = 2;               val x' = 2;
%    val x = 3;               val x'' = 3;
% and then as I parse material I need to map the simple name "x" onto
% whichever of x, x' or x'' is appropriate. If I do that I can keep top-
% level values stored statically, which is something I expect to be good
% for performance. This issue only matters if the source code will have
% cases where top-level definitions are shadowed by replacements. I hope
% that does not happen in the code I have at present, and so I can delay
% implementing the renaming scheme. The "yagni" principle applies here...

flag('(funcall), 'variadic);

symbolic procedure smleval(u, env);
  begin
    scalar w;
    if atom u then
      if idp u then <<
        w := atsoc(u, env);
        if w then return cdr w
        else return get(u, 'smlvalue) >>
      else return u
    else if eqcar(u, 'lambda) then
      return list('funarg, cadr u, caddr u, env)
    else if (w := get(car u, 'smlspecial)) then
      return funcall(w, cdr u, env)
    else if (w := get(car u, 'smlprimitive)) then
      return funcall(w, smleval(cadr u, env))
    else <<
      w := smleval(car u, env);
      if not eqcar(w, 'funarg) then
        rederr bldmsg("%r is not a known function", car u);
      return smlapply(w, smleval(cadr u, env)) >>
  end;

symbolic procedure smlapply(ff, arg);
  begin
    scalar bvl, body, env;
    bvl := car (ff := cdr ff);  
    body := car (ff := cdr ff);  
    env := cadr ff;  
    env := smlpair(bvl, arg, env);
    return smleval(body, env)
  end;

symbolic procedure smltuple(u, env);
  for each x in u collect smleval(x, env);

put('smltuple, 'smlspecial, 'smltuple);

symbolic procedure smllist(u, env);
  for each x in u collect smleval(x, env);

put('smllist, 'smlspecial, 'smllist);

symbolic procedure smltimes u;
  car u * cadr u;

put('times, 'smlprimitive, 'smltimes);

symbolic procedure smlquotient u;
  car u / cadr u;

put('quotient, 'smlprimitive, 'smlquotient);

symbolic procedure smlremainder u;
% Well I may want MODULUS not REMAINDER here...
  remainder(car u, cadr u);

put('remainder, 'smlprimitive, 'smlremainder);

symbolic procedure smlplus u;
  car u + cadr u;

put('plus, 'smlprimitive, 'smlplus);

symbolic procedure smldifference u;
  car u - cadr u;

put('difference, 'smlprimitive, 'smldifference);

symbolic procedure smlstringconcat u;
  concat(car u, cadr u);

put('stringconcat, 'smlprimitive, 'smlstringconcat);

symbolic procedure smlstringcons u;
  car u . cadr u;

put('stringcons, 'smlprimitive, 'smlstringcons);

symbolic procedure smlappend u;
  append(car u, cadr u);

put('append, 'smlprimitive, 'smlappend);

symbolic procedure smlgreaterp u;
  car u > cadr u;

put('greaterp, 'smlprimitive, 'greaterp);

symbolic procedure smllessp u;
  car u < cadr u;

put('lessp, 'smlprimitive, 'smllessp);

symbolic procedure smlgeq u;
  car u >= cadr u;

put('geq, 'smlprimitive, 'smlgeq);

symbolic procedure smlleq u;
  car u <= cadr u;

put('leq, 'smlprimitive, 'smlleq);

symbolic procedure smlequal u;
  car u = cadr u;

put('equal, 'smlprimitive, 'smlequal);

symbolic procedure smlneq u;
  car u neq cadr u;

put('neq, 'smlprimitive, 'smlneq);

symbolic procedure smlset u;
  rplaca(car u, cadr u);

put('set, 'smlprimitive, 'smlset);

symbolic procedure smlcompose u;
  rederr "function composition operator not implemented yet";

put('compose, 'smlprimitive, 'smlneq);



symbolic procedure smland(u, env);
  if smleval(car u, env) then smleval(cadr u, env)
  else nil;

put('and, 'smlspecial, 'smland);

symbolic procedure smlor(u, env);
   if smleval(car u, env) then t
   else smleval(cadr u, env);

put('or, 'smlspecial, 'smlor);

symbolic procedure smlif(u, env);
   if smleval(car u, env) then smleval(cadr u, env)
   else smleval(caddr u, env);

put('if, 'smlspecial, 'smlif);


% If smleval is handed a declaration it can return an updated environment.
% At top level I need to transcribe that into static storage.

symbolic procedure smltoplevel u;
  begin
    scalar w;
    w := smleval(u, nil);
    if eqcar(w, '!:newenv!:) then
      for each b in reverse cdr w do <<
        printf("%f%q = %q%n", car b, cdr b);
        put(car b, 'smlvalue, cdr b) >>
    else printf("%fValue: %q%n", w);
  end;

% Now for me to think about argument de-structuring I need to decide
% how this code will represent SML composite items. A basic premis will be
% that types are all correct and so I do not need type tags anywhere.
% however when I hava a datatype that uses multiple constructors I
% will need the record which is in use.
%
%     SML                       Lisp
%      1                         1
%      #"x"                      x
%      "xyz"                     "xyz"
%      (a,b,c) (tuple)           (a' b' c')
%      ()      (unit)            nil
%      [a,b,c] (list)            (a' b' c')
%      []      (empty list)      nil
%      { t1=v1, ... } (records)  ((t1 . v1) ...)
%      datatype f=x|y|z          x, y or z
%      datatype f = A of ..      (A ...)
%
% Patterns need to be more explicit, so patterns will be
%
%     SML                       Lisp
%      1                         1
%      #"x"                      numeric code for x
%      "xyz"                     "xyz"
%      (a,b,c) (tuple)           (a' b' c')
%      ()      (unit)            nil
%      [a,b,c] (list)            (:: a' (:: b' (:: c' nil)))
%      []      (empty list)      nil
%      { t1=v1, ... } (records)  ??? (smlrecord ...) ???
%      datatype f=x|y|z          x, y or z
%      datatype f = A of ..      (A ...)
% where A is flagged to mark is as a constructor. Note that :: is
% a special case because I expect it to be especially common.

% This function either returns an augmented environment or the symbil
% 'fail. The latter case is there because I will use it with SML
% matches where I have clausal definitions of functions.

symbolic procedure smlpair(bvl, arg, env);
  if idp bvl then (bvl . arg) . env   % A simple identifier
  else if atom bvl then               % Number, character, string, nil, unit
    if bvl = arg then env
    else 'fail
  else if eqcar(bvl, '!:!:) then      % Special case of lists
    if atom arg then 'fail
    else <<
      env := smlpair(cadr bvl, car arg, env);
      if env = 'fail then 'fail
      else smlpair(caddr bvl, cdr arg, env) >>
% The pattern for a tuple has "smltuple" at the start, but the stored
% representation of the tuple does not have any special tag on the front.
  else if eqcar(bvl, 'smltuple) then smlpairlist(cdr bvl, arg, env)
% I probably need to deal with records here, where matching is especially
% messy because ordering ot components is not rigidly fixed.
  else if eqcar(bvl, 'smlrecord) then
    rederr "destructuring records not coded yet"
  else if flagp(car bvl, 'smlconstructor) then % General constructor
    if eqcar(arg, car bvl) then smlpairlist(cdr bvl, cdr arg, env)
    else 'fail
  else <<                             % tuples
    env := smlpair(car bvl, car arg, env);
    if env = 'fail then 'fail
    else smlpair(cdr bvl, cdr arg, env) >>;

symbolic procedure smlpairlist(pl, vl, env);
  if null pl then
    if null vl then env
    else rederr "tuple is bigger than wanted"
  else if null vl then rederr "tuple does not have enough components"
  else <<
    env := smlpair(car pl, car vl, env);
    if env = 'fail then 'fail
    else smlpairlist(cdr pl, cdr vl, env) >>;

% When I process a "val" statement I return an updated environment.

symbolic procedure smlval(u, env);
  begin
    printf("%fsmlval %r%n", u);
    for each b in u do <<
% b will be of form (val pattern expr) or (valrec pattern expr).
      if eqcar(b, 'valrec) then
         env := smlrecpaireval(cadr b, caddr b, env)
      else env := smlpair(cadr b, smleval(caddr b, env), env);
      if env = 'fail then rederr "pattern patching failed in VAL" >>;
    printf("smlval result: %p%n", env);
    return '!:newenv!: . env
  end;

% This is a bit like smlpair except that it does not have an argument to
% process. I sticks items on the front of env that pair each name from
% the match with a temporary value !?.

symbolic procedure smldummypair(bvl, env);
  if idp bvl then (bvl . '!?) . env   % A simple identifier
  else if atom bvl then env           % Number, character, string, nil, unit
  else if eqcar(bvl, '!:!:) then <<   % Special case of lists
      env := smldummypair(cadr bvl, env);
      smldummypair(caddr bvl, env) >>
% I probably need to deal with records here, where matching is especially
% messy because ordering of components is not rigidly fixed.
  else if eqcar(bvl, 'smlrecord) then
    rederr "destructuring records not coded yet"
  else if flagp(car bvl, 'smlconstructor) then % General constructor
    smldummypairlist(cdr bvl, env)
  else <<                             % tuples
    env := smldummypair(car bvl, env);
    smldummypair(cdr bvl, env) >>;

symbolic procedure smldummypairlist(pl, env);
  if null pl then env
  else <<
    env := smldummypair(car pl, env);
    smldummypairlist(cdr pl, env) >>;

% The syntax allows
%    val (a, b) = ...
%    and rec (c, d) = ...
%    and (e, f) = ...
% and until I need to read the semantics to understand the exact implication
% of "rec" and "and".
%
% What I implement at present only supports "rec" in the case that just one
% binding is being introduced. This is wrong. I also go to some trouble
% to support "val rec (a,b,c) = ..." with de-structuring and that is
% not allowed by SML - because the RHS must be a simple lambda-expression and
% that could never de-structure... @@@@@. 


symbolic procedure smlrecpaireval(bvl, exp, env);
  begin
    scalar env1, env2;
% I start by binding each new variable to a dummy value "?"
    env1 := smldummypair(bvl, env);
% Now I can evaluate the right hand side using this extended environment.
% If it tries to use the value of a new variable then I am in trouble (rather
% reasonably!) but the key magic is that function closures here will capture
% the extended environment.
    exp := smleval(exp, env1);
% Once that is done I can do the real pattern matching... I make that put
% new bindings on top of the original environment. They will pair names with
% the proper required values, but the bindings are not where they need to
% end up.
    env2 := smlpair(bvl, exp, env);
    if env2 = 'fail then return 'fail;
% So now I copy across values from the new bindings into where I need them.
    bvl := env1;
% The collection of new bindings I had added using smldummypair should
% be an exact match in order and number to the ones created using smlpair,
% so I transcribe across data from the latter. The former is where the
% information must end up because it was the environment against which the
% right-hand size was evaluated.
    while env2 neq env do <<
      rplacd(car bvl, cdar env2);
      env2 := cdr env2 >>;
    return env1
  end;

put('valbinds, 'smlspecial, 'smlval);

% Now for function definitions. These are always to be processed
% as recursive, and as with "val" there can be multiple definitions
% made at once (using "and"). As a simplification the function name
% is always just a simple symbol, but as a complication the definition
% may be clausal with variants linked with "|".

% (fvalbinds                         introduction
%      (   ((f nil) nil)             list for clausal definition
%          ((f (!:!: a b)) ...)   )  list of several functions co-defined
%      (   (((g a) b) ...)        )
% )
%
% I want to turn this into
%    env' = ((f . (funarg F env'))
%            (g . (funarg G env')) .
%            old-env)
% where F = (clausal (lambda nil nil)
%                    (lambda (!:!: a b) ...))
% and   G = (lambda b (lambda a ...))
% and I then return env'. Note that if a function has only one clause
% it is specified directly, if it has several it is wrapped up usiing
% a "clkausal" list.



symbolic procedure smlfval(u, env);
  begin
    scalar v, w, x;
    printf("%fsmlfval %r%n", u);
% first collect a list of function names.
    v := for each d in u collect <<
% d is a list of clausal options (  ((f x) E) ... ).
      w := caar d;
% w is the left hand side of the first (posisbly only) definition.
      while not atom w do w := car w;
% now w is the name of the function. I collect pairs ready to add
% to my environment.
      (w . '!?) >>;
    v := env := append(v, env);
% Now the environment has been extended wiith ((f . !?) (g . !?) ...) on
% the front. So I will now scan the definitions again replacing the "?"
% with function closures that refer to the extended environment. Beware that
% while I do that I naturally create re-entrant data-structures and so
% simple Lisp functions (including printing) can have trouble...
    for each d in u do <<
      if null cdr d then << % Simple single component of the definition
        d := car d;
        w := car d;     % left hand side of definition
        d := cadr d;    % body of function
% Convert ((f a) b) = E to f = (lambda b (lambda a E)) 
        while not atom w do <<
          d := list('lambda, cadr w, d);
          w := car w >>;
% Rewrite the top lambda as a funarg. 
        d := list('funarg, cadr d, caddr d, env);
        rplacd(car v, d); % Store definition where it need to go.
        v := cdr v >>
      else <<
        rederr "clausal definitions not handled yet" >> >>;
    return '!:newenv!: . env
  end;

put('fvalbinds, 'smlspecial, 'smlfval);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

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
          ("|")
          ("of")
          ("fn")
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
put('!^,   'lisp_name, 'stringconcat);

put('!:!:, 'lisp_name, 'cons);
put('!@,   'lisp_name, 'append);

put('!>,   'lisp_name, 'greaterp);
put('!<,   'lisp_name, 'lessp);
put('!>!=, 'lisp_name, 'geq);
put('!<!=, 'lisp_name, 'leq);
%put('!=,   'lisp_name, 'equal);
put('!<!>, 'lisp_name, 'neq);

put('!:!=, 'lisp_name, 'set);
put('o,    'lisp_name, 'compose_functions);

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
    else smltoplevel u
  end;

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

symbolic procedure makeflhs(name, args);
   begin
     printf("%fmakeflhs %r %r%n", name, args);
     for each x in args do name := list(name, x);
     printf("=> %r%n", name);
     return name
  end;

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

% If parsing the SML code fails I will just exit from Reduce. Otherwise
% it is likely that I will be faced with a mess of further silly messages
% as Reduce tries to make sense if SML input itself.
% I think I may need an option within lalr for parsing from a file, such
% that errors merely close that file and return to using Reduce on
% an outer file... ie so that parsed and regular Reduce stuff are kept
% more separate.

on parse_errors_fatal;

% The grammar used here was originally derived from one found at
%    https://www.mpi-sws.org/~rossberg/sml.html
% but I re-worked it significantly using information fron "The Definition
% of Standard ML (Revised)", 1997. At least that will be definitive!
% I hope it will let me get rid of syntactic ambiguity.

<< terpri(); lpri list("grammar has", length (grammar := '(

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
         ((exp ")") (list !$1))
         ((exp "," tupletail) (cons !$1 !$3)))

 (listtail
         ((exp "]") (list !$1))
         ((exp "," listtail) (cons !$1 !$3)))

 (seqtail
         ((exp ")") (list !$1))
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
% will start off as a mere !:symbol items, but ones that I will map onto
% custom Lisp names are best noted explicitly here I think.

 (opname  ((!:symbol))
          (("*"))
          (("-"))
          (("-="))
          (("->"))
          (("="))
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
         ((unit) nil)                           % Unit
         (("(" exp "," tupletail) (cons 'smltuple (cons !$2 !$4))) % Tuple
         ((emptylist) nil)                      % Empty list
         (("[" exp "]") (list 'smllist !$2))    % List of length 1
         (("[" exp "," listtail) (cons 'smllist (cons !$2 !$4))) % Longer list
         (("(" exp ";" seqtail) (cons 'smlseq (cons !$2 !$4)))   % Sequence
         ((letid dec "in" seqexps endid))
         (("(" exp ")") !$2))                   % Mere parentheses

 (appexp ((atexp))
         ((appexp atexp)))

% Note that infix operators turn into function calls using tupled arguments,
% and here I represent a 2-tuple as just a list of length 2.
 (infexp ((appexp))
         ((infexp !:infix0 infexp) (list (get !$2 'lisp_name) (list 'smltuple !$1 !$3)))
         ((infexp !:infix1 infexp) (list (get !$2 'lisp_name) (list 'smltuple !$1 !$3)))
         ((infexp !:infix2 infexp) (list (get !$2 'lisp_name) (list 'smltuple !$1 !$3)))
         ((infexp !:infix3 infexp) (list (get !$2 'lisp_name) (list 'smltuple !$1 !$3)))
         ((infexp !:infix4 infexp) (list (get !$2 'lisp_name) (list 'smltuple !$1 !$3)))
         ((infexp "=" infexp) (list 'equal (list 'smltuple !$1 !$3)))
         ((infexp !:infix5 infexp) (list (get !$2 'lisp_name) (list 'smltuple !$1 !$3)))
         ((infexp !:infix6 infexp) (list (get !$2 'lisp_name) (list 'smltuple !$1 !$3)))
         ((infexp !:infix7 infexp) (list (get !$2 'lisp_name) (list 'smltuple !$1 !$3)))
         ((infexp "*" infexp) (list 'times (list 'smltuple !$1 !$3)))
         ((infexp !:infix8 infexp) (list (get !$2 'lisp_name) (list 'smltuple !$1 !$3)))
         ((infexp !:infix9 infexp) (list (get !$2 'lisp_name) (list 'smltuple !$1 !$3)))
         ((infexp !:infixr0 infexp) (list (get !$2 'lisp_name) (list 'smltuple !$1 !$3)))
         ((infexp !:infixr1 infexp) (list (get !$2 'lisp_name) (list 'smltuple !$1 !$3)))
         ((infexp !:infixr2 infexp) (list (get !$2 'lisp_name) (list 'smltuple !$1 !$3)))
         ((infexp !:infixr3 infexp) (list (get !$2 'lisp_name) (list 'smltuple !$1 !$3)))
         ((infexp !:infixr4 infexp) (list (get !$2 'lisp_name) (list 'smltuple !$1 !$3)))
         ((infexp !:infixr5 infexp) (list (get !$2 'lisp_name) (list 'smltuple !$1 !$3)))
         ((infexp !:infixr6 infexp) (list (get !$2 'lisp_name) (list 'smltuple !$1 !$3)))
         ((infexp !:infixr7 infexp) (list (get !$2 'lisp_name) (list 'smltuple !$1 !$3)))
         ((infexp !:infixr8 infexp) (list (get !$2 'lisp_name) (list 'smltuple !$1 !$3)))
         ((infexp !:infixr9 infexp) (list (get !$2 'lisp_name) (list 'smltuple !$1 !$3)))
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
             (list 'if !$2 !$4 !$6))
         (("while" exp "do" exp)) 
         (("case" exp "of" match))
         (("fn" match))
         )

 (localid
         (("local") (startcontext)))
 (letid  (("let") (startcontext)))
 (endid  (("end") (endcontext)))

 (seqexps((exp))
         ((seqexps ";" exp)))

 (exprow ((lab "=" exp))
         ((lab "=" exp "," exprow)))

 (match  ((onematch) !$1)
         ((match "|" onematch)))

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

 (pat    ((pat1)         !$1)
         ((pat ":" typ)  !$1)
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
         (("_") 'smlwildcard)
         ((id_with_op) !$1)
         (("{" patrow "}"))
         ((unit) nil)
         ((emptylist) nil)
         (("[" patseq "]") (cond ((null (cdr !$2)) (car !$2))
                                 (t (cons '!smllist !$2))))
         (("(" patseq ")") (cond ((null (cdr !$2)) (car !$2))
                                 (t (cons '!smltuple !$2)))))

 (patseq ((pat) (list !$1))
         ((patseq "," pat) (append !$1 (list !$3))))

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

% In my conversion here I will be assuming that somebody else somewhere else
% has already ensured that everything is type-safe. As a result I will not
% need to put type information of any real sort into my parse tree.
 (tyvarseq
         ((!:typename)              (list !$1))
         (("(" tvs2 ")")            !$2))

 (tvs2   ((!:typename)              (list !$1))
         ((tvs2 "," !:typename)     (append !$1 (list !$3))))

 (symbols ((!:symbol)               (list !$1))
         ((symbols !:symbol)        (append !$1 (list !$2))))

 (dec1   (("val" valbind)           !$2)
         (("val" tyvarseq valbind)  !$3)  % Ignore type variables.
         (("fun" fvalbind)          !$2)
         (("fun" tyvarseq fvalbind) !$3)
         (("type" typbind))
         (("datatype" datbind))
         (("datatype" datbind "withtype" typbind))
         (("datatype" !:symbol "-=-" "datatype" !:symbol))
         (("abstype" datbind "with" dec "end"))
         (("abstype" datbind "withtype" typbind "with" dec "end"))
         (("exception" exnbind))
         ((localid dec "in" dec endid))
         (("open" symbols))
         (("structure" strbind))
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
           (("rec" pat "=" exp "and" valbind)
                                (cons 'valbinds
                                  (cons (list 'valrec !$2 !$4) (cdr !$6))))
           (("rec" pat "=" exp) (list 'valbinds
                                  (list 'valrec !2 !$4)))
           ((pat "=" exp "and" valbind)
                                (cons 'valbinds
                                  (cons (list 'val !$1 !$3) (cdr !$5))))
           ((pat "=" exp)       (list 'valbinds
                                  (list 'val !$1 !$3)))
           )

 (fvalbind ((nfvalbindings)     (list 'fvalbinds !$1))
           ((nfvalbindings "and" fvalbind)
                                (cons 'fvalbinds (cons !$1 (cdr !$3)))))

 (nfvalbindings ((onefvalbinding)              (list !$1))
           ((nfvalbindings "|" onefvalbinding) (cons !$1 !$3)))

 (onefvalbinding
          ((id_with_op (plus atpat) opttyp "=" exp)
              (list (makeflhs !$1 !$2) !$5)))

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

 (onestrbind ((!:symbol "=" strexp))
           ((!:symbol ":" sigexp "=" strexp))
           ((!:symbol ":>" sigexp "=" strexp))
           )

 (strbind  ((onestrbind))
           ((strbind "and" onestrbind)))


 (strexp   ((structid dec endid))
           ((!:symbol))
           ((strexp ":" sigexp))
           ((strexp ":>" sigexp))
           ((!:symbol "(" strexp ")"))
           ((!:symbol "(" dec ")"))
           ((letid dec "in" strexp endid))
           )

 (structid (("struct") (startcontext)))

 (sigexp  ((sigid spec endid))
          ((!:symbol))
          ((sigexp "where" "type" !:symbol "=" typ))
          ((sigexp "where" "type" tyvarseq !:symbol "=" typ))
          )

 (sigid   (("sig") (startcontext)))

 (sigdec  (("signature" sigbind)))

 (sigbind ((!:symbol "=" sigexp (opt "and" sigbind))))

 (onespec (("val" valdesc))
          (("type" typdesc))
          (("eqtype" typdesc))
          (("datatype" datdesc))
          (("datatype" !:symbol "-=-" "datatype" !:symbol))
          (("exception" exdesc))
          (("structure" strdesc))
          (("include" sigexp))
          )

 (spec    ((onespec))
          ((spec ";" onespec))
          ((spec onespec))
          ((spec "sharing" "type" !:symbol eqsymlist))
          )

 (fundec  (("functor" funbind)))

 (onefunbind ((!:symbol "(" !:symbol ":" sigexp ")" "=" strexp))
          ((!:symbol "(" !:symbol ":" sigexp ")" ":" sigexp "=" strexp))
          ((!:symbol "(" !:symbol ":" sigexp ")" ":>" sigexp "=" strexp))
          ((!:symbol "(" spec ")" ":" sigexp "=" strexp))
          ((!:symbol "(" spec ")" ":>" sigexp "=" strexp))
          )

 (funbind  ((onefunbind))
           ((funbind "and" onefunbind)))

 (eqsymlist (("=" !:symbol))
          ((eqsymlist "=" !:symbol)))

 (valdesc ((!:symbol ":" typ (opt "and" valdesc))))

 (onetypdesc ((!:symbol))
          ((tyvarseq !:symbol)))

 (typdesc ((onetypdesc))
          ((typdesc "and" onetypdesc))
          )

 (onedatdesc ((!:symbol "=" condesc))
          ((tyvarseq !:symbol "=" condesc)))

 (datdesc ((onedatdesc))
          ((datdesc "and" onedatdesc)))

 (condesc ((!:symbol (opt "of" typ) (opt "|" condesc))))

 (exdesc  ((!:symbol (opt "of" typ) (opt "and" exdesc))))

 (strdesc ((!:symbol ":" sigexp))
          ((!:symbol ":" sigexp "and" strdesc)))

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
          ((fundec))
          ((sigdec))
          )

  )), "clauses") >>;


% While debugging it may be helpful to see the grammar diplayed with
% indentation normalised...
%
% << terpri(); prettyprint grammar; nil >>;

% This will tend to lead to a LOT of output - much of which will be hard to
% decode. But while debugging the grammar it may be necessary.
% on lalr_verbose;

%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

pp := lalr_create_parser(prec, grammar)$


%lexer_style!* := lexer_style_SML;
lexer_style!* := lexer_style_SML + 0x40; % Support #if and #eval too!

%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

begin
   scalar !*raise, !*lower;
   lex_init();
   yyparse pp
end;

use "Library_Reduce.sml";

(* I now have a succession of cases that I wish to get working via Reduce *)

val gg = 3;

gg*gg + 1;

val a = 1 and b = 2 and c = 3;

a;
b;
c;

(1);
(1,2);
(1,2,3);
[];
[1];
[1,2];
[1,2,3];

fun fact n =
  if n = 0 then 1
  else n * (fact (n-1));

fact 6;

fun bin(n, r) =
  if r = 0 orelse n = r then 1
  else bin(n-1, r-1) + bin(n-1, r);

bin(10, 4);

fun fact1 0 = 1
  | fact1 n = n * (fact1 (n-1));

fact1 6;

fun app [] y = y
  | app (x :: xs) y = x :: app xs y;

app [1,2,3] [4,5,6];

(* End of everything *)
EOF
;
quit;
