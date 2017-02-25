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
        !*strict_argcount !*comp);

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
#if (memq 'csl lispsystem!*)
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
#if (memq 'csl lispsystem!*)
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

% Another function with quite a few labels and gotos...

symbolic procedure procstat1 mode;
   begin scalar bool,u,type,x,y,z, file, line;
      if ifl!* then file := car ifl!* else file = "-";
      line := curline!*;
      bool := erfg!*;
      if fname!* then << bool := t; go to a5 >>
       else if cursym!* eq 'procedure then type := 'expr
       else << type := cursym!*; scan() >>;
      if not(cursym!* eq 'procedure) then go to a5;
      if !*reduce4 then go to a1;
      x := errorset!*('(xread (quote proc)),nil);
      if errorp x then go to a3
       else if atom (x := car x) then x := list x;   % No arguments.
      fname!* := car x;   % Function name.
      if idp fname!*
        then if null fname!* or fname!* eq 't
               then << rsverr fname!*; go to a3 >>
              else if (z := gettype fname!*)
                       and null(z memq '(procedure operator))
               then << typerr(list(z,fname!*),"procedure"); go to a3 >>;
      put(fname!*, 'defined!-in!-file, file);
      put(fname!*, 'defined!-on!-line, line);
      u := cdr x;
      y := u;   % Variable list.
      if idlistp y then x := car x . y
       else lprie list(y,"invalid as parameter list");
      go to a2;
  a1: fname!* := scan();
      if not idp fname!*
        then << typerr(fname!*,"procedure name"); go to a3 >>;
      put(fname!*, 'defined!-in!-file, file);
      put(fname!*, 'defined!-on!-line, line);
      scan();
      y := errorset!*(list('read_param_list,mkquote mode),nil);
      if errorp y then go to a3;
      y := car y;
      if cursym!* eq '!*colon!* then mode := read_type();
  a2: if idp fname!* and not getd fname!* then flag(list fname!*,'fnc);
         % To prevent invalid use of function name in body.
  a3: if eof!*>0 then
        << cursym!* := '!*semicol!*; curescaped!* := nil; go to a4 >>;
      z := errorset!*('(xread t),nil);
      if not errorp z then z := car z;
%     if not atom z and eqcar(car z,'!*comment!*) then z := cadr z;
      if null erfg!*
        then z :=
           list('procedure,if null !*reduce4 then car x else fname!*,
                mode,type,y,z);
  a4: remflag(list fname!*,'fnc);
      fname!* := nil;
      if erfg!* then << z := nil; if not bool then error1() >>;
      return z;
  a5: errorset!*('(symerr (quote procedure) t),nil);
      go to a3
   end;

symbolic procedure procstat; procstat1 nil;

deflist ('((procedure procstat) (expr procstat) (fexpr procstat)
           (emb procstat) (macro procstat) (inline procstat)
           (smacro procstat)),
        'stat);

% Next line refers to bootstrapping process.

if get('symbolic,'stat) eq 'procstat then remprop('symbolic,'stat);

deflist('((lisp symbolic)),'newnam);

endmodule;

end;
