% p2l.red                                     Copyright (c) 2017 A C Norman


% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%

% $Id$


% Part of the Pascal to Lisp conversion code. This file will read in
% lufy.raw and create lufy.red

lisp;
on echo;
on backtrace;
on comp;

load_package rprint;
off rprint_lower;

% Start by reading in the source file

global '(input_data);

begin
  scalar a, !*echo, !*raise, !*lower;
  a := open("lufy.raw", 'input);
  a := rds a;
  input_data := read();
  close rds a
end;

% A function that prints an S-expression truncating the output so it
% will fit on one line. This is for debugging and logging purposes.

symbolic procedure mediumprint(u, n);
  begin
    scalar w;
    w := explode u;
    for i := 1:n do
      if w then << princ car w; w := cdr w >>;
    if w then princ "...";
    terpri();
    return u
  end;

symbolic procedure shortprint u;
  mediumprint(u, 68);

% This function "tidy" does the main work.

global '(pending);
pending := nil;

% I need to propagate type information through my translation.
% Whenever I see the declaration of a new record type I must put
% details onto typedecs. Any variable whose type is a record type has to
% go in vardecs. That means that both parameter lists as well as local
% and global variable declarations will need to be scanned and recorded.
% To cope with scope issue, typedecs and vardecs must be rebound as I
% start to process any BEGIN..END block or equivalent region of code
% that defines a local scope.

% When I see a reference to a field selection "V.f" I need to look up the
% record type associated with V and identify the selector f based on that. I
% think this will mean I want to record the return types from functions
% so that "F(x).f" can be interpreted properly.

fluid '(typedecs vardecs);

symbolic procedure tidy x;
  begin
    scalar w, long;
    if atom x then return x
    else if idp car x and (w := get(car x, 'tidyfn)) then
      return apply1(w, cdr x);
% All the parse tree itsms that I know what to do with have "tidyfn" tags
% so get handled above. During development there will be some that I have
% not (yet) implemented, and I form those into a record of pending clauses.
% When I first find an instance of a tag that I do not recognise I will
% print it. I then count how many of each such occur, and at the end I can
% dump those counts so that I have an idea of which of the not-handled cases
% are most frequently used and hence perhaps deserve first attention.
    if not zerop posn() then terpri();
    long := 68;
    if w := assoc(car x, pending) then rplacd(w, add1 cdr w)
    else <<
      pending := (car x . 1) . pending;
      long := 400 >>;
    princ "%?: ";  % Unknown leading operator.
    mediumprint(x, long);
    return concat("???", symbol!-name car x)
  end;

symbolic procedure tidytypedeflist u;
 << tidy car u;
    tidy cadr u;
    nil >>;

put('typedeflist, 'tidyfn, 'tidytypedeflist);

symbolic procedure tidytypedef u;
  begin
    typedecs := (car u . tidy cadr u) . typedecs;
    printf("Define type %p = %p%n", caar typedecs, cdar typedecs);
    return nil
  end;

put('typedef, 'tidyfn, 'tidytypedef);

symbolic procedure tidysubrangetype u;
   list('subrange, tidy car u, tidy cadr u);

put('subrangetype, 'tidyfn, 'tidysubrangetype);

symbolic procedure tidyenumeratedtype u;
   list('enumerated, tidy car u);

put('enumeratedtype, 'tidyfn, 'tidyenumeratedtype);

% If I have a record type it will have a list of selectors that can be
% used with it

symbolic procedure tidyrecseclist u;
  append(tidy car u, list tidy cadr u);

put('recseclist, 'tidyfn, 'tidyrecseclist);

symbolic procedure tidyrecsec u;
  begin
    scalar w;
    w := tidy cadr u;
    return for each n in tidy car u collect list(n, w) 
  end;

put('recsec, 'tidyfn, 'tidyrecsec);

symbolic procedure tidyrecordtype u;
   list('record, tidy car u, tidy cadr u); 

put('recordtype, 'tidyfn, 'tidyrecordtype);





% I think that the easiest path for me to take here is to suppose that
% the word "packed" has no impact. I think that when I have variant
% records I will need all their components to be packed against the
% prospect of deliberate aliasing between them (see the memoryword type
% and reading and writing dump files in this regard) but I rather hope
% that apart from the variant issue the issue of packed vs not packed is
% going to be purely one of a speed/space tradeoff and is not actually
% something I need to worry about too much these days.

symbolic procedure tidypackedtype u;
  tidy car u;

put('packedtype, 'tidyfn, 'tidypackedtype);


% A Pascal program starts off "program Name" or "program Name(id-list)"
% and I use the name as the name of a function to run it. I ignore any list
% of identifiers that appears after the name!
% At present I also do not support "module".

% I want all procedure definitions to end up lifted to the outer level, so
% while expanding code I collect them in "procdefs" and I tage that onto my
% result at the end. Sort of similarly for top-level variables and constants,
% using vardefs.

fluid '(vardefs procdefs within_procedure);

symbolic procedure tidyprogram u;
  begin
    scalar vardefs, procdefs, w, within_procedure;
    w := list('de,
              intern concat(symbol!-name cadr car u, "entrypoint"), nil,
              tidy cadr u);
    return mkprogn3(vardefs, w, procdefs)
  end;

put('program, 'tidyfn, 'tidyprogram);

% There are a number of places where I wish to generate sequences of
% operations, and in the generated Lisp those will be represented using
% PROGN. Here I arrange to avoid generating unnecessary nested uses of
% PROGN, so I exploit associativity and set up for instance (progn a b c d)
% rather than (progn (progn a b) (progn c d)).

symbolic procedure mkprogn2(u, v);
  if null u then v
  else if null v then u
  else if eqcar(u, 'progn) then <<
    if eqcar(v, 'progn) then append(u, cdr v)
    else append(u, list v) >>
  else if eqcar(v, 'progn) then 'progn . u . cdr v
  else list('progn, u, v);

symbolic procedure mkprogn3(u, v, w);
  mkprogn2(u, mkprogn2(v, w));

symbolic procedure mkprogn4(u, v, w, x);
  mkprogn2(u, mkprogn2(v, mkprogn2(w, x)));

symbolic procedure mkprogn5(u, v, w, x, y);
  mkprogn2(u, mkprogn2(v, mkprogn2(w, mkprogn2(x, y))));

symbolic procedure mkprogn6(u, v, w, x, y, z);
  mkprogn2(u, mkprogn2(v, mkprogn2(w, mkprogn2(x, mkprogn2(y, z)))));

% A Pascal block is parser with six sorts of stuff in it, starting with
% level declarations and ending in the list of statements to be obeyed.
% I need to arrange that the declarations that are introduced are recorded
% as in scope for the later parts of the block.

symbolic procedure tidyblock u;
  begin
    scalar labs, consts, types, vars, procs, stmts;
    labs := car u; u := cdr u;
    consts := car u; u := cdr u;
    types := car u; u := cdr u;
    vars := car u; u := cdr u;
    procs := car u; u := cdr u;
    stmts := car u;
% When I have forms that can introduce declarations I will let the TIDYFN
% update the variables typedecs and vardecs. In places like this I have
% set up new bindings for these so that they get retored once processing the
% block is complete. This behaviour means that I need to tidy the
% declarations in the correct order. The "block" construct can arise as the
% main contents of a whole file or as the body of a procedure or function.
    labs := tidy labs;
    consts := tidy consts;
    types := tidy types;
    vars := tidy vars;
    procs := tidy procs;
    stmts := tidy stmts;
    procdefs := mkprogn2(procdefs, procs);
    return mkprogn5(
% label, constant and type declarations are made here and I rather hope that
% none of those expand into executable code. The declaraction effect of them
% will have been made available to procedures defined in their scope. Well
% this slightly concerns me as regards contant declarations - if I replace
% names by the associated values at this language conversion time I will get
% correct behaviour but I will lose some clarity. Hmmm that may need further
% though.
      labs,
      consts,
      types,
% Variables are declared before procedures, so the variables may be expected
% to be accessible within those procedures. To achive that the processing
% of a variable declaration can stick something that establishes a global
% variable onto procdefs. 
      vars,
      stmts)
  end
% If a way that seems truly ugly, if I put the "where" on the same line as
% the "end" Reduce would moan, because once upon a time in the distant past
% you could put comments after the word "end".
  where typedefs=typedecs, vardecs = vardecs;

put('block, 'tidyfn, 'tidyblock);

symbolic procedure tidyprocdeflist u;
  if null car u then tidy cadr u
  else mkprogn2(tidy car u, tidy cadr u);

put('procdeflist, 'tidyfn, 'tidyprocdeflist);

symbolic procedure tidylablistappend u;
  if u then nil
  else mkprogn2(tidy car u, tidy cadr u);

put('lablistappend, 'tidyfn, 'tidylablistappend);

symbolic procedure tidyconstlist_append u;
  if null car u then tidy cadr u
  else mkprogn2(tidy car u, tidy cadr u);

put('constlist_append, 'tidyfn, 'tidyconstlist_append);

symbolic procedure tidylablist_append u;
  if null car u then list tidy cadr u
  else append(tidy car u, list tidy cadr u);

put('lablist_append, 'tidyfn, 'tidylablist_append);

symbolic procedure tidyidlist_append u;
  if null car u then list tidy cadr u
  else append(tidy car u, list tidy cadr u);

put('idlist_append, 'tidyfn, 'tidyidlist_append);

symbolic procedure tidylabeldec u;
  list('declarelabels, mkquote tidy car u);

put('labeldec, 'tidyfn, 'tidylabeldec);

symbolic procedure tidyconstdef u;
  <<vardefs := mkprogn3(vardefs,
      list('global, mkquote list car u),
      list('setq, car u, cadr u));
    nil>>;

put('constdef, 'tidyfn, 'tidyconstdef);

% procdecdir is for FORWARD or EXTERNAL declarations

symbolic procedure tidyprocdecdir u;
  nil;

put('procdecdir, 'tidyfn, 'tidyprocdecdir);

% Main procedure definition scheme.

symbolic procedure tidyprocdecblock u;
  begin
    scalar h, b, n, a;
    h := car u;
    b := cadr u;
    if not eqcar(h, 'prochead) then rederr "prochead expected";
princ "### prochead: "; print h;
    n := cadr h;
    if not eqcar(n, 'procid) then rederr "procid expected";
    a := caddr h;
    return list('de, cadr n, tidy a, tidy b)
  end;

put('procdecblock, 'tidyfn, 'tidyprocdecblock);

procedure tidyformallist a;
  if null car a then list tidy cadr a
  else append(tidy car a, list tidy cadr a);

put('formallist, 'tidyfn, 'tidyformallist);

symbolic procedure tidyargsec u;
  if eqcar(u, 'valparam) then tidyidlist cadr u
  else if eqcar(u, 'varparam) then <<
    princ "@@@ call by reference rather than value: ";
    print u;
    tidyidlist cadr u >>
  else <<
    princ "@@@ procedure argument: ";
    print u;
    '(procedure_type_argument) >>;

symbolic procedure tidyidlist u;
  if null u then nil
  else mkprogn2(tidy cadr u, tidy caddr u);
  
symbolic procedure tidystatementsequence u;
  if null u then nil
  else mkprogn2(tidy car u, tidy cadr u);
  
put('statementsequence, 'tidyfn, 'tidystatementsequence);

symbolic procedure tidysetq u;
  if atom car u then list('setq, car u, tidy cadr u)
  else if eqcar(car u, 'fielddesignator) then
    list('setf, append(tidy cadar u, list tidy caddar u), tidy cadr u)
  else if eqcar(car u, 'indexed) then
    list('putv, tidy cadar u, tidy caddar u, tidy cadr u)
  else list('!@!@!@setq, u);
  
put('setq, 'tidyfn, 'tidysetq);

symbolic procedure tidyfielddesignator u;
  if atom car u then list(car u, tidy cadr u)
  else append(tidy car u, list tidy cadr u);
  
put('fielddesignator, 'tidyfn, 'tidyfielddesignator);

symbolic procedure tidyif u;
  if caddr u then
    list('cond, list(tidy car u, tidy cadr u),
                list(t, tidy caddr u))
  else list('cond, list(tidy car u, tidy cadr u));
  
put('if, 'tidyfn, 'tidyif);

symbolic procedure tidyprocstat u;
  tidy car u . tidy cadr u;
  
put('procstat, 'tidyfn, 'tidyprocstat);

symbolic procedure tidyparamlist u;
  if null car u then list tidy cadr u
  else append(tidy car u, list tidy cadr u);
  
put('paramlist, 'tidyfn, 'tidyparamlist);

symbolic procedure tidyindexed u;
  if null car u then list tidy cadr u
  else append(tidy car u, list tidy cadr u);
  
put('indexed, 'tidyfn, 'tidyindexed);

symbolic procedure tidyrelop u;
  car u . for each a in cdr u collect tidy a;
  
put('relop, 'tidyfn, 'tidyrelop);

symbolic procedure tidyaddop u;
  car u . for each a in cdr u collect tidy a;
  
put('addop, 'tidyfn, 'tidyaddop);

symbolic procedure tidyterm u;
  car u . for each a in cdr u collect tidy a;
  
put('term, 'tidyfn, 'tidyterm);

symbolic procedure tidyfactor u;
  if eqcar(u, 'plus) then tidy cadr u
  else list(car u, tidy cadr u);
  
put('factor, 'tidyfn, 'tidyfactor);

symbolic procedure tidyvalparam u;
  tidy car u;
  
put('valparam, 'tidyfn, 'tidyvalparam);



symbolic procedure seqprint u;
  if null u then nil
  else if eqcar(u, 'progn) then
     for each x in cdr u do seqprint x
  else <<
    terpri();
% During initial debugging I wanted to see some of the generated code
% in raw Lisp form, but now I will just look at the rlisp version.
%   princ "% ";
%   shortprint u;
    rprint u >>;

begin
  scalar a;
  a := open("lufy.red", 'output);
  a := wrs a;
  printc "% lufy.red    Generated automatically from tex.web";
  terpri();
  printc "% See README.lufy for a discussion of license issues";
  terpri();
  princ "% $"; printc "Id: $";
  terpri();
  seqprint tidy input_data;
  terpri();
  printf "% End of lufy.red%n%n";
  close wrs a;
  terpri();
  print "lufy.red created";
  for each x in reverse sort(pending, function lesspcdr) do <<
     prin car x;
     ttab 30;
     print cdr x >>
end;

end;
