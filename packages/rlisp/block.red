module block;   % Block statement and related operators.

% Author: Anthony C. Hearn.

% Copyright (c) 1993 RAND.  All rights reserved.

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


fluid '(!*blockp !*novarmsg !*rlisp88);

global '(!*vars!* cursym!* nxtsym!*);

flag('(novarmsg),'switch);

% ***** GO statement *****

symbolic procedure gostat;
   begin scalar var;
        var := if eq(scan(),'to) then scan() else cursym!*;
        scan();
        return list('go,var)
   end;

put('go,'stat,'gostat);

put('goto,'newnam,'go);


% ***** Declaration Statement *****

% This is called from two locations. It is called with argument "t"
% at the head of a block, so there it deals with things like
% "begin scalar v1,v2,v3; ...". Then decstat could call it with argument nil
% and that arises when the xread encounters INTEGER, REAL or SCALAR.

symbolic procedure read_parameter_list();
% This version should only be used for declaring local variables. It
% allows types and intialization, so the syntax will allow for things like
%    scalar a,          % original style
%           b:typeb,    % with type specifier
%           c:=initc,   % initialize as you go
%           d:td:=id,   % type and initializer
%           e;
%
% It returns a list of items each of which is (name type initial_value).
%
   begin scalar x,xt,xv,y,z;
      repeat <<
        if cursym!* = '!*comma!* then scan();
        x := cursym!*;
        if not idp x then typerr(x,"variable name");
        y := scan();
        if y = '!*colon!* then <<
          scan();
          xt := read_type();
          y := cursym!* >>
        else xt := 'general;
        if y = 'setq then <<
          scan();
          xv := xread1 t;
          y := cursym!* >>
        else xv := nil;
        z := list(x, xt, xv) . z
      >> until not (y = '!*comma!*);
      return reversip z
   end;

% This now returns a list of variables and a list of declaration
% information.

symbolic procedure collect_decls(u, w);
  if null u then nil
  else (caar u . w) . collect_decls(cdr u, w);

symbolic procedure decl();
   begin scalar varlis,w,pl,typelist;
   a: while cursym!* = '!*semicol!* do scan();
      if cursym!* = 'local and !*reduce4 then nil
      else if not flagp(cursym!*,'type) then return (varlis . typelist)
      else if !*reduce4 then typerr(cursym!*,"local declaration");
      w := cursym!*;
      scan();
      if !*reduce4 then varlis := append(varlis,read_param_list nil)
      else if cursym!* = '!*semicol!* then <<
        lprim list("Empty variable list in",w,"declaration");
        return (nil . nil) >>
      else <<
        pl := read_parameter_list();
        typelist := append(typelist, pl);
        varlis := append(varlis, collect_decls(pl, w)) >>;
      if not(cursym!* = '!*semicol!*) then symerr(nil,t);
      scan();
      go to a
   end;

put('integer,'initvalue!*,0);

symbolic procedure decstat;
% Called following a word like "scalar" or "integer" or "real"
% other than at the start of a block. The only valid case is when the
% next word is "procedure" and even this is an archaic thow-back to
% "mode Reduce".
  begin scalar x;
     if !*blockp then symerr('block,t);
     x := cursym!*;
     if nxtsym!* neq 'procedure
       then rerror('rlisp,7,list(x,"invalid outside block"));
     scan();
     return procstat1 x
  end;

flag('(integer real scalar),'type);

symbolic procedure blocktyperr u;
   % Type declaration found at wrong position.
   rerror('rlisp,8,list(u,"invalid except at head of block"));


% ***** Block Statement *****

symbolic procedure mapovercar u;
   begin scalar x;
   while u do <<
      x := caar u . x;
      u := cdr u >>;
   return reversip!* x
   end;

% If you annotate the declaration of local variable (at a block-head)
% with type information then the block will end up starting with
% a quoted expression of the types...
%
%     begin scalar a:type1:=val1, b:type2, c:=val3; ...
% =>  (prog (a b) (quote ((a type1 val1) (b type2 nil) (c general val3))) ...
%
% I will want to migrate the initialization material into executable
% code soon.

% The information I have on the local variable is in a list structured
% as ((name type initial_value) ...)

% At the head of the block I will put a quoted expression that has just
% ((name . type) ...) info in it, and that omits any cases where the type
% is given as just 'general.

symbolic procedure extract_types vl;
  if null vl then nil
  else if cadar vl = 'general then extract_types cdr vl
  else (caar vl . cadar vl) . extract_types cdr vl;

% Where there are non-nil initializers stick them on the front of the
% body code.

symbolic procedure add_initializers(vl, b);
  if null vl then b
  else if null caddar vl then add_initializers(cdr vl, b)
  else list('setq, caar vl, caddar vl) . add_initializers(cdr vl, b);

symbolic procedure add_varinfo(vl, b);
  begin
    scalar tt;
    tt := extract_types vl;
    b := add_initializers(vl, b);
% Only put the (quote (name . type) ...) info if there is some present.
    if tt then b := mkquote tt . b;
    return b
  end;

symbolic procedure blockstat;
   begin scalar hold,varlis,x,!*blockp;
        !*blockp := t;
        scan();
        if cursym!* memq '(nil !*rpar!*)
          then rerror('rlisp, 9, "BEGIN invalid");
        varlis := decl();
    a:  if cursym!* = 'end and not(nxtsym!* = '!:) then <<
           comm1 'end;
           return mkblock(car varlis, add_varinfo(cdr varlis, hold)) >>;
        x := xread1 nil;
        if eqcar(x, 'end) then
           return mkblock(car varlis, add_varinfo(cdr varlis, hold));
        if not(cursym!* = 'end) then scan();
        if x then <<
           (if eqcar(x, 'equal) then
               lprim list("top level", cadr x, "= ... in block"));
           hold := aconc!*(hold, x) >>;
        go to a;
   end;

symbolic procedure mkblock(u,v); 'rblock . (u . v);

putd('rblock,'macro,
   '(lambda (u) (cons 'prog (cons (mapovercar (cadr u)) (cddr u)))));

symbolic procedure symbvarlst(vars,body,mode);
   begin scalar x,y;
      if not (mode = 'symbolic) then return nil;
      y := vars;
      while y do <<
         x := if pairp car y then caar y else car y;
         if not fluidp x and
            not globalp x and
            not smemq(x,body) and
            not !*novarmsg then
            lprim list("local variable",x,"in procedure", fname!*,"not used");
         y := cdr y >>;
   end;

symbolic procedure make_prog_declares(v, b);
   begin
#if (getd 'declare)
% This detects any bound variables that are fluid (or global) at the
% time I process this code and adds in a DECLARE to remind us about
% that fact. I should put in an explanation for the benefit of those who
% do not expect this. In CSL some definitions are extracted from the body
% of the source for compilation into C (and similar issues could potentially
% arise with in-lining of function definitions). The consequence of this is
% that the code concerned is compiled at a stage that is NOT when it has
% just been read from its source file. If the function binds and fluid
% variables then the fluid declaration MUST be visible at the time it is
% compiled, and the only way to achieve this is for the declaration to be
% included as part of the code. I use the Common Lisp notation for this
% with "declare special" stuck in as a first item in the procedure body.
% This is not actually very CSL specific... if one built a system using any
% Lisp with everything initially interpreted then there is no good guarantee
% that fluid declarations for eveything will be in force at run-time - and so
% attempts to compile parts of the code incrementally at that late stage
% could cause disaster. Well there would be further issues in that case
% depending on whether the interpreter treated variable bindings as lexical
% or fluid in the absence of declarations.
     scalar w, r;
     w := v;
     while w do <<
        if fluidp car w or globalp car w then r := car w . r;
        w := cdr w >>;
     if r then b := list('declare, 'special . r) . b;
#endif
     return ('prog . v . b)
   end;

symbolic procedure formblock(u,vars,mode);
   begin scalar w;
     symbvarlst(cadr u,cddr u,mode); % Merely report on any unused vars
     w := initprogvars cadr u;
     return make_prog_declares(car w,
                      append(cdr w,
                             formprog1(cddr u,append(cadr u,vars),mode)));
   end;

symbolic procedure initprogvars u;
   begin scalar x,y,z;
      while u do <<
         if null caar u or caar u = 't then rsverr caar u
         else if (z := get(caar u,'initvalue!*)) or
                 (z := get(cdar u,'initvalue!*)) then
            y := mksetq(caar u,z) . y;
         x := caar u . x;
         u := cdr u >>;
      return (reversip!* x . reversip!* y)
   end;

symbolic procedure formprog(u,vars,mode);
   make_prog_declares(cadr u,
                      formprog1(cddr u,pairvars(cadr u,vars,mode),mode));


symbolic procedure formprog1(u,vars,mode);
   if null u then nil
    else if null car u then formprog1(cdr u,vars,mode)
        % remove spurious NILs, probably generated by FOR statements.
    else if atom car u then car u . formprog1(cdr u,vars,mode)
    else if eqcar(car u, 'quote) and not (mode = 'symbolic) then
       formprog1(cdr u,vars,mode)
    else if idp caar u and flagp(caar u,'modefn)
           then if !*rlisp88 and null(caar u = 'symbolic)
                  then typerr("algebraic expression","Rlisp88 form")
          else formc(cadar u,vars,caar u) . formprog1(cdr u,vars,mode)
    else formc(car u,vars,mode) . formprog1(cdr u,vars,mode);

put('rblock,'formfn,'formblock);

put('prog,'formfn,'formprog);

put('begin,'stat,'blockstat);

flag('(declare), 'noform);

% ***** Return Statement *****

symbolic procedure retstat;
   if not !*blockp then symerr(nil,t)
    else begin scalar !*blockp;  % To prevent RETURN within a RETURN.
            return list('return,
                if flagp(scan(),'delim) then nil else xread1 t)
      end;

put('return,'stat,'retstat);

endmodule;

end;
