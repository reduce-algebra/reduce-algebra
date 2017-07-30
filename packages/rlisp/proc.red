module proc;   % Procedure statement.

% Author: Anthony C. Hearn.

% Copyright (c) 1991 RAND.  All rights reserved.

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


fluid '(!*argnochk !*noinlines !*loginlines !*redeflg!* fname!* ftype!*
        !*strict_argcount !*comp ifl!* curline!*);

% !*loginlines will cause a compile-time report of patterns of inline usage.
!*loginlines := t;

global '(!*lose !*micro!-version cursym!* curescaped!* erfg!*
         ftypes!*);

fluid '(!*defn new_inline_definitions);

new_inline_definitions := nil;

!*lose := t;

ftypes!* := '(expr fexpr macro);

% If foo(a,b) is already a defined function than when you go
%    symbolic emb procedure foo(u,v);
%      <new body ... foo(u', v') ... >;
% the function is redefined, but the inner call within it refers to the
% existing definition. So this can wrap new stuff around an existing
% procedure body. It is ONLY intended for debugging and I suggest that
% functions that have been embedded should not be written out in
% fasl files or saved on heap images (for instance it is not always going
% to be certain that the proper identity of the gensym used here will
% survive serialization). This may however be useful for debugging as
% a more flexible alternative to use of "tr foo;". In reduce4 mode this was
% wired into the parser, aned there is a commented out autoload directive
% for the "embfn" function in PSL, so I avoided clashing with that name
% here.

put('emb, 'procfn, 'portable!-embfn);

symbolic procedure portable!-embfn(name, args, body);
  begin
    scalar g;
    if not eqcar(getd name, 'expr) then
      rederr "Trying to embed around undefined function, or a fexpr or macro";
    g := gensym();
    return list('progn,
      list('copyd, mkquote g, mkquote name),
      list('de, name, args, ssubst(g, name, body)))
% I replace name by the gensym except within quotes. This will have
% untoward effects if name is also the the name of a fluid variable...
% but since this is JUST for debugging I will ignore that issue just
% for now. Another case where this scheme will fail is if there is a
% use of (eg) apply('name, ...) or an errorset that wants to call the
% function and so creates a structure with its name in it. So you
% see that overall this is a marginal and dodgy bit of code - but it can
% still be really useful when used in SIMPLE ways.
  end;

symbolic procedure mkprogn(u,v);
   if eqcar(v,'progn) then 'progn . u . cdr v else list('progn,u,v);

symbolic procedure formproc(u,vars,mode);
   begin scalar obody,body,fname!*,name,type,varlis,x,y,fl,n;
        u := cdr u;
        name := fname!* := car u;
        if cadr u then mode := cadr u;   % overwrite previous mode
        u := cddr u;
        type := ftype!* := car u;
        if flagp(name,'lose) and (!*lose or null !*defn)
          then return << lprim list(name,
                            "not defined (LOSE flag)");
                        '(quote nil) >>
         else if !*redeflg!* and getd name
          then lprim list(name,"redefined");
        varlis := cadr u;
        while varlis do <<
           if null car varlis or car varlis eq 't then rsverr car varlis;
           varlis := cdr varlis >>;
        varlis := cadr u;
% For the benefit of CSL - and also perhaps for source analysis tools - if
% a fluid variable is bound I will insert a (DECLARE...) form at the
% head of the function. The justification for this is that the status of
% the variable as fluid is being checked at parse time. With CSL I capture
% the Lisp versions of function definitions and translate them into C++
% at a later stage, and when I do that the fluid declarations are in general
% not still around. But with the adjustment that is made here I have a local
% fluid declaration to guide me. I test for DECLARE being defined (it should
% be a special form not a regular function) rather than looking at the
% identity of the Lisp system.
#if (getd 'declare)
        while varlis do <<
           if fluidp car varlis or globalp car varlis then
              fl := car varlis . fl;
           varlis := cdr varlis >>;
        varlis := cadr u;
#endif
        body := caddr u;
        x := if eqcar(body,'rblock) then cadr body else nil;
        y := pairxvars(varlis,x,vars,mode);
        if x then body := car body . rplaca!*(cdr body,cdr y);
%        body:= form1(body,car y,mode);   % FORMC here would add REVAL.
        body := if flagp(name,'formc) then formc(body,car y,mode)
                 else form1(body,car y,mode);
% !*noinlines being set causes every inline that is defined to be downgraded
% to a regular procedure.
        if !*noinlines and type eq 'inline then type := 'expr;
#if (getd 'declare)
% Note the non-Common way in which the DECLARE sits within a PROGN here.
% Furthermore I only insert DECLARE for sort-of ordinary functions.
% Specifically this will not include "inline procedure"... but a consequence
% of this will be that it will be a mistake to introduce an inline function
% that attempts to bind a fluid... because the variable concerned might not be
% declared fluid at the point where the inline definition is used.
        if fl and type memq '(expr fexpr macro) then
         body:=list('progn,
                    list('declare, 'special . fl),
                    body);
#endif
        obody:=body;
        if type = 'inline then begin
           scalar dd;
           dd := list('lambda,varlis,body);
           if not (dd = get(name, 'inline)) then <<
              if not zerop posn() then terpri();
              prin2 "+++ Record new inline definition:";
              terpri();
% I had been minded to use prettyprint here, however with PSL the file that
% contains the code for prettyprint sets up some inline definitions and it
% appears that an attempt to use prettyprint will fail there. What is worse
% is that I tried "if getd 'prettyprint then prettyprint else print" but that
% also crashed when PSL tried to build the prettyprint module.
              print list('de,name,varlis,body);
              new_inline_definitions := (name . dd) . new_inline_definitions >>
           end;
        if (not(type eq 'inline) and get(name,'inline)) or
           (not(type eq 'smacro) and get(name,'smacro))
          then lprim list("SMACRO/INLINE",name,"redefined");
% the next line generates warnings if any arguments are not used (in symbolic
% mode, and not counting arguments that are fluid).
        symbvarlst(varlis,body,mode);
        if type eq 'expr then body := list('de,name,varlis,body)
         else if type eq 'fexpr then body := list('df,name,varlis,body)
         else if type eq 'macro then body := list('dm,name,varlis,body)
         else if (x := get(type,'procfn))
          then return apply3(x,name,varlis,body)
         else body := list('putc,
                           mkquote name,
                           mkquote type,
                           mkquote list('lambda,varlis,body));
        if not(mode eq 'symbolic)
          then body :=
              mkprogn(list('flag,mkquote list name,mkquote 'opfn),body);
        if !*argnochk and type memq '(expr inline smacro)
          then <<
              if (n:=get(name, 'number!-of!-args)) and
                 not flagp(name, 'variadic) and
                 n neq length varlis then <<
                if !*strict_argcount then
                  lprie list ("Definition of", name,
                      "different count from args previously called with")
                else lprim list(name, "defined with", length varlis,
                    "but previously called with",n,"arguments") >>;
           body := mkprogn(list('put,mkquote name,
                                    mkquote 'number!-of!-args,
                                    length varlis),
                               body) >>;
        if !*defn and type memq '(fexpr macro inline smacro)
          then lispeval body;
% "inline" procedures define a regular procedure as well as saving the
% definition so it can be expanded in place elsewhere.
        if type = 'inline then
           body := print mkprogn(list('de,name,varlis,obody), body);
        return if !*micro!-version and type memq '(fexpr macro smacro)
                 then nil
                else body
   end;

put('procedure,'formfn,'formproc);

symbolic procedure formde(u, vars, mode);
  formproc(
     list('procedure, cadr u, 'symbolic, 'expr, caddr u,
                      if null cddddr u then cadddr u else 'progn . cdddr u),
     vars,
     mode);

put('de,'formfn,'formde);

symbolic procedure pairxvars(u,v,vars,mode);
   %Pairs procedure variables and their modes, taking into account
   %the convention which allows a top level prog to change the mode
   %of such a variable;
   begin scalar x,y;
      while u do <<
         if (y := atsoc(car u,v)) then <<
            v := delete(y,v);
            if not(cdr y eq 'scalar) then x := (car u . cdr y) . x
            else x := (car u . mode) . x >>
         else if null idp car u or get(car u,'infix) or get(car u,'stat)
             then symerr(list("Invalid parameter:",car u),nil)
         else x := (car u . mode) . x;
         u := cdr u >>;
      return append(reversip!* x,vars) . v
   end;

symbolic procedure starts!-with(a, b);
  if null b then t
  else if null a then nil
  else if eqcar(a, car b) or
     (eqcar(a,'!\) and eqcar(b, '!/)) then starts!-with(cdr a, cdr b)
  else nil;

symbolic procedure simplify!-filename s;
  begin
    scalar a, b;
% The issue that I am concerned with here is that the full version of
% a file-name may be very long, and including all of it in messages can be
% unhelpful. To cope with files-names that are within the Reduce source
% tree I will apply what is perhaps a hack, and I will remove any initial
% part of a path that ends in "/packages/". Thus (for instance) one of the
% more basic test files will end up just names as "alg/alg.tst" rather than
% anything longer.
    a := explode2 s;
    b := explode2 "/packages/";
    while a and not starts!-with(a, b) do a := cdr a;
    if null a then return s;
    a := cddddr cddddr cddr a;
    return list2string a;
  end;

!#if (or (null (getd 'mkhash)) (flagp 'mkhash 'rlisp))

% I need to simulate hash tables, which PSL does not appear to provide.
% Well I will provide a minimal functional (but not performance)
% replacement here for use in any Lisp that does not heva a function
% called "mkhash" defined.

% The type is 0 for EQ hashes and all other cases are treated as EQUAL
% ones here. Since I am simulating "hash" tables in PSL using just simple
% association lists I do not have any use for a concept of initial size or
% the factor by which tables expand once they become full.

% I think a nicer implementation would be to use genuine hashed tables with
% PSL providing a function that hashed items. For EQ hashing that could be
% based on the machine representation of the (reference to) an item, while
% for equal it could traverse lists but use the address for symbols. The key
% issue there is that garbage collection moves things around! The neatest idea
% I have about that is to have each hash table record in its header the
% sequence number of garbage collection with respect to which it is valid.
% puthash and gethash would then check that on entry and perform a rehash
% operation if out of date. If one can be confident that garbage collection
% will not be triggered while performing gethash, and if puthash and rehash
% record the garbage collection number when they start and check if items are
% already present first using gethash (and if rehash re0runs itself if it
% finds that a GC happened while it was active). I think all is not too
% messy. But because hash tables are not very heavily used this is not a high
% priority!

symbolic procedure mkhash(size, type, expansion);
  type . nil;

symbolic procedure clrhash u;
  rplacd(u, nil);

symbolic procedure gethash(key, table);
  begin
% Of course use of assoc/atsoc here is not good for performance if you
% end up with many items stored...
    table := (if car table = 0 then atsoc(key, cdr table)
            else assoc(key, cdr table));
    if null table then return nil
    else return cdr table
  end;

symbolic procedure puthash(key, table, val);
  begin
    scalar w;
    w := (if car table = 0 then atsoc(key, cdr table)
          else assoc(key, cdr table));
    if w then <<
      rplacd(w, val);
      return val >>;
    rplacd(table, (key . val) . cdr table);
    return val
  end;

symbolic procedure hashcontents table;
  cdr table;

flag('(mkhash), 'rlisp);

!#endif

% Now stuff that I will use when recording the names of files associated
% with procedure definitions...

global '(string!-table!*);

% I want a hash tables where keys are compared using EQUAL, or at
% least something that treats string that have the same letters in them as
% the same. The numeric code "3" here is a messy CSL oddity on that
% respect.

string!-table!* := mkhash(10, 3, 2.0);

% Note that I will have installed a placeholder version of
% make!-string!-unique that is just the identity function (ie that
% does not impose uniquene4ss at all!) to hold the fort during
% bootstrapping. The version here will replace it when it can.

symbolic procedure make!-string!-unique s;
  begin
    scalar w;
    if w := gethash(s, string!-table!*) then return w;
    puthash(s, string!-table!*, s);
    return s
  end;    

% In an earlier version of this code a procedure specification could use
% an infix expression or a non-atomic function name. Such generality is not
% described in the manual, and ACN hopes that withdrawing it will not cause
% pain.

%symbolic procedure read_signature();
%  xread 'proc;

% At present this code only allows single token type specifiers. This is
% far from enough, but may still do as a placeholder while I implement
% more of the infrastructure.

% read_type() reads a description of a type.

symbolic procedure read_type();
  begin
    scalar x;
    x := cursym!*;
    scan();
    return x;
  end;

% read_typed_name will read either "name" or "name : type", and if the
% explicit typs is not given it defaults to "general".

symbolic procedure read_typed_name();
  begin
    scalar a;
    a := cursym!*;
    scan();
    if not (cursym!* = '!*colon!*) then return (a . 'general);
    scan();
    return (a . read_type())
  end;

% read_namelist knows that there is at least one name - so it reads
% a sequence of typed names connected to "," tokens. It stops as soon
% as the tyken following a typed name is not a comma.

symbolic procedure read_namelist();
  begin
    scalar a;
    if not valid_as_variable cursym!* then return nil;
    a := read_typed_name();
    if not (cursym!* = '!*comma!*) then return list al
    scan();
    return a . read_namelist()
  end;    

% valid_as_variable is a function that exists because the Rlisp tokenization
% code does not make a clear distinction between reserved words and ordinary
% identifiers.

symbolic procedure valid_as_variable u;
  idp u and
  not flagp(u, 'invalid_as_variable);

flag('(nil t !*comma!* !*lpar!* !*rpar!* !*colon!* !*semicol!*),
     'invalid_as_variable);

% read_signature is used for procedure headers. The syntax it accepts
% should be as shown here (where the final ";" tells parsing when to stop).
%     name ;
%     name : type ;
%     name() ;
%     name() : type ;
%     name( arg1:type1, ...) ;
%     name( arg1:type1, ...) : type ;

symbolic procedure read_signature();
  begin
    scalar x;
    x := cursym!*;
    if not valid_as_variable x then
      rerror('rlisp, 7, list(x, "invalid as formal parameter name"));
    scan();
    if cursym!* = '!*colon!* or cursym!* = '!*semicol!* then x := list x
    else if cursym!* = '!*lpar!* then <<
      scan();
      if cursym!* = '!*rpar!* then x := list x
      else <<
        x := x . read_namelist();
        if not (cursym!* = '!*rpar!*) then rerror('rlisp, 8,
          list(cursym!*, "found where right parenthesis expected")) >>;
      scan() >>
    else x := list(x, read_typed_name());
    if cursym!* = '!*colon!* then <<
      scan();
      return list(x, read_type()) >>
    else return list(x, 'general)
  end;

fluid '(!*acn);  % So that I can test things!

symbolic procedure procstat1 mode;
   begin scalar bool,u,type,x,y,z, file, line;
% Note the file and line that this procedure is in. This will be the
% location that the procedure statement starts on.
      if ifl!* then file := car ifl!* else file = "-";
      line := curline!*;
% I think that erfl!* will be set if we have already suffered an error, so
% we may be parsing in a sort of recovery mode.
      bool := erfg!*;
% fname!* is set to the name of a procedure while we are parsing the body
% of that procedure, so if it is set here then we have an illegal attempt at
% a procedure definition nested within another. This will most typically
% occur if a previous procedure fails to have enough ">>" or "end" tokens.
      if fname!* then <<
         bool := t;
         errorset!*('(symerr (quote procedure) t),nil) >>
      else <<
% Here we allow for "procedure", "symbolic procedure", "algebraic procedure"
% or "maud procedure" with (in that case) "maud" ending up in the variable
% "type". If the word "procedure" is not found we will complain.
         if cursym!* eq 'procedure then type := 'expr
         else << type := cursym!*; scan() >>;
         if not(cursym!* eq 'procedure) then <<
            errorset!*('(symerr (quote procedure) t),nil) >>
         else <<
% Reduce 4 differs from previous versions... it allows type specifiers.
            if !*reduce4 then <<
% Name of the procedure comes next
               fname!* := scan();
               if not idp fname!* then typerr(fname!*,"procedure name")
               else <<
                  scan();
% Move past the procedure name and read the list of parameters.
                  y := errorset!*(list('read_param_list,mkquote mode),nil);
                  if not errorp y then <<
% If parameters were read happily and the next token is a colon then there
% will be a type given after it.
                     y := car y;
                     if cursym!* eq '!*colon!* then mode := read_type() >> >> >>
            else if !*acn then <<
               scan();
               x := read_signature();
% The result of read_signature is
%    ((fname (arg1 . type1) ...) result_type)
               prin2 "TRACE:"; print x;
               x := car x;
               x := car x . for each a in cdr x collect car a;
               prin2 "TRACE:"; print x;
               fname!* := car x;
               y := cdr x >>
            else <<
% In the old world we read the function name and arguments with one call to
% xread. The result might be atomic in "procedure maud;" or it might be a list
% of the form (maud arg1 .. argn). Note that because of the use of xread
% this can handle infix operators, so
%   infix maud; procedure u maud v; ...
% will be legal. Also one can have [extra] parentheses around formal arguments
% and possibly other really odd things based aroudn Reduce special syntax.
               x := errorset!*('(xread (quote proc)),nil);
               if errorp x then errorset!*('(symerr (quote procedure) t),nil)
               else <<
                  if atom (x := car x) then x := list x;   % No arguments.
                  fname!* := car x;   % Function name.
% ensure that the name of the procedure that is being defined seems reasonable.
                  if null idp fname!* then % Function name should be an identifier
                     errorset!*('(symerr (quote procedure) t),nil)
                  else if null fname!* or fname!* eq 't then rsverr fname!*
                  else if (z := gettype fname!*) and
                          null(z memq '(procedure operator)) then
                     typerr(list(z,fname!*),"procedure")
                  else <<
                     u := cdr x;
                     y := u;   % Variable list.
% Now although xread had been generous and you could have had almost anything
% written as a formal argument, a check is made here so that only identifiers
% are allowed through.
                     if idlistp y then x := car x . y
                     else lprie list(y,"invalid as parameter list") >> >> >>;
            if idp fname!* and not getd fname!* then
               flag(list fname!*,'fnc) >> >>;
% Recover a bit of there was an end of file encountered while reading the
% procedure heading.
      if eof!*>0 then <<
         cursym!* := '!*semicol!*;
         curescaped!* := nil >>
      else <<
% Now read the procedure body. It is quite reasonable to use xread here.
         z := errorset!*('(xread t),nil);
         if not errorp z then z := car z;
         if null erfg!* then
            z := list('procedure,
                      if null !*reduce4 then car x else fname!*,
                      mode,type,y,z) >>;
% Parsing is complete. So now just tidy up.
      remflag(list fname!*,'fnc);
      fname!* := nil;
      if erfg!* then <<
         z := nil;
% What seems to be going on here is that most errors spotted during parsing
% get deferred to here. I rather believe that this is so that the state of
% Reduce is not messed up too much by a parse failure, and so that lines
% of input beyond an error get skipped past in a reasonable way.
         if not bool then error1() >>;
% In sensible cases the value of z here will be something like
%  (de maud (arg1 ... argn) body)
% so cadr z will be the name of the procedure that is being defined.
% I can tag it with the file name and line where it was defined, and that
% may be really helpful in some debugging contextx.
      if ifl!* and not atom z and not atom cdr z and idp cadr z then
         z := list('progn,
            list('put, mkquote cadr z,
                 ''defined!-in!-file,
                 list('make!-string!-unique, simplify!-filename file)),
            list('put, mkquote cadr z, ''defined!-on!-line, line),
            z);
      return z
   end;

symbolic procedure procstat;
  procstat1 nil;

deflist ('((procedure procstat) (expr procstat) (fexpr procstat)
           (emb procstat) (macro procstat) (inline procstat)
           (smacro procstat)),
        'stat);

% Next line refers to bootstrapping process.

if get('symbolic,'stat) eq 'procstat then remprop('symbolic,'stat);

deflist('((lisp symbolic)),'newnam);

endmodule;

end;
