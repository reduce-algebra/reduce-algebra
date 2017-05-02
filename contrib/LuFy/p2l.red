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

% $Id: p2l.red 3979 2017-03-26 14:36:41Z arthurcnorman $


% Part of the Pascal to Lisp conversion code. This file will read in
% lufy.tmp and create lufy.red

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
  a := open("lufy.tmp", 'input);
  a := rds a;
  input_data := read();
  close rds a
end;

% A function that prints an S-expression truncating the output so it
% will fit on one line.

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

% This next function does the work.

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

% I might - while I am about it - track when a variable name refers to a
% procedure, integer or read typed value. I might not use that to start with
% if I am translating into Lisp, but if I ever translated into some other
% stricter language I could use that information.

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
    if not zerop posn() then terpri();
    long := 68;
    if w := assoc(car x, pending) then rplacd(w, add1 cdr w)
    else <<
      pending := (car x . 1) . pending;
      long := 400 >>;
    princ "%?: ";  % Unknown leading operator.
    mediumprint(x, long);
    return '!?
  end;

% Ignore the name that is given for the program

symbolic procedure tidyprogram u;
  tidy cadr u;      

put('program, 'tidyfn, 'tidyprogram);

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

symbolic procedure tidyblock u;
  begin
    scalar labs, consts, types, vars, procs, stmts;
    labs := car u; u := cdr u;
    consts := car u; u := cdr u;
    types := car u; u := cdr u;
    vars := car u; u := cdr u;
    procs := car u; u := cdr u;
    stmts := car u;
    return mkprogn6(
      tidy labs,
      tidy consts,
      tidy types,
      tidy vars,
      tidy procs,
      list('de, 'texmain, nil, tidy stmts))
  end where typedefs=typedecs, vardecs = vardecs;

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
  mkprogn2(
    list('global, mkquote list car u),
    list('setq, car u, cadr u));

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
  printc "% $Id: $";
  terpri();
  seqprint tidy input_data;
  terpri();
  printf "% End of lufy.red";
  close wrs a;
  terpri();
  print "lufy.red created";
  for each x in reverse sort(pending, function lesspcdr) do <<
     prin car x;
     ttab 30;
     print cdr x >>
end;

end;
