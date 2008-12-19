module form;  % Performs a mode analysis of parsed forms.

% Author: Anthony C. Hearn.

% Modifications by: Jed Marti, Arthur C. Norman.

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


fluid '(!*!*a2sfn !*cref !*defn !*mode !*reduce4 !*rlisp88
        current!-modulus fname!* ftype!*);

global '(!*argnochk !*comp !*composites !*force !*micro!-version
         !*vars!* cursym!*);

!*!*a2sfn := 'aeval;

flag('(algebraic symbolic),'modefn);

symbolic procedure formcond(u,vars,mode);
   'cond . formcond1(cdr u,vars,mode);

symbolic procedure formcond1(u,vars,mode);
   if null u then nil
    else list(formbool(caar u,vars,mode),formc(cadar u,vars,mode))
       % FORM1 here leaves out top level REVAL.
              . formcond1(cdr u,vars,mode);

put('cond,'formfn,'formcond);

symbolic procedure formlamb(u,vars,mode);
   list('lambda,cadr u,form1(caddr u,pairvars(cadr u,vars,mode),mode));

put('lambda,'formfn,'formlamb);

symbolic procedure formprogn(u,vars,mode);
   'progn . formclis(cdr u,vars,mode);

put('progn,'formfn,'formprogn);

symbolic procedure expdrmacro u;
   % Returns the macro form for U if expansion is permitted.
   begin scalar x;
      if null(x := getrmacro u) or flagp(u,'noexpand) then return nil
%      else if null(null !*cref and (null !*defn or car x eq 'smacro)
%         or flagp(u,'expand) or !*force)
       else if !*cref and null flagp(u,'expand) and null !*force
        then return nil
       else return x
   end;

symbolic procedure getrmacro u;
   %returns a Reduce macro definition for U, if one exists,
   %in GETD format;
   begin scalar x;
      return if not idp u then nil
       else if (x := getd u) and car x eq 'macro then x
       else if (x := get(u,'smacro)) then 'smacro . x
       else nil
   end;

symbolic procedure applmacro(u,v,w); apply1(u,w . v);

put('macro,'macrofn,'applmacro);

flag('(ed go quote),'noform);

symbolic procedure set!-global!-mode u;
   begin
      !*mode := u;
      return list('null,list('setq,'!*mode,mkquote u))
   end;

symbolic procedure form1(u,vars,mode);
   begin scalar x,y;
      if atom u
        then return if not idp u then u
                     else if u eq 'ed then list u
                     else if flagp(u,'modefn) then set!-global!-mode u
                     else if x:= get(mode,'idfn)
                      then apply2(x,u,vars)
                     else u
       else if not atom car u then return form2(u,vars,mode)
       else if not idp car u then typerr(car u,"operator")
       else if car u eq 'comment
        then return form1(car lastpair u,vars,mode)
       else if flagp(car u,'noform) then return u
       else if arrayp car u
%         and (mode eq 'symbolic or intexprlisp(cdr u,vars))
          and mode eq 'symbolic
        then return list('getel,intargfn(u,vars,mode))
       else if cdr u and (get(car u,'rtype) eq 'vector
             or vectorp cadr u or flagpcar(cadr u,'vecfn))
        then return getvect(u,vars,mode)
       else if flagp(car u,'modefn)
        then return convertmode(cadr u,vars,mode,car u)
       else if (x := get(car u,'formfn))
        then return macrochk(apply3(x,u,vars,mode),mode)
       else if get(car u,'stat) eq 'rlis
        then return macrochk(formrlis(u,vars,mode),mode)
%      else if (x := getd car u) and eqcar(x, 'macro) and
%              not(mode eq 'algebraic) then
%            return <<x := apply3(cdr x,u,vars,mode);
%                     formc(x,vars,mode) >>
%      else if flagp(car u,'type) then blocktyperr car u
       else if car u eq '!*comma!*
        then if not atom cadr u and atom caddr u
                 and flagp(caadr u,'type)
%                and(get(caddr u,'stat) eq 'decstat)
               then blocktyperr caadr u
              else rerror('rlisp,10,
                          list("Syntax error: , invalid after",cadr u));
      % Exclude algebraic operator with same name as symbolic function.
      if mode eq 'symbolic or flagp(car u,'opfn)
        then argnochk u;
      x := formlis(cdr u,vars,mode);
      y := if x=cdr u then u else car u . x;
      return if mode eq 'symbolic
              or get(car u,'stat)
              or cdr u and eqcar(cadr u,'quote)
                       and null(!*micro!-version and null !*defn)
              or intexprnp(y,vars) and null !*composites
                 and current!-modulus=1
               then macrochk(y,mode)
              else if not(mode eq 'algebraic)
               then convertmode(y,vars,mode,'algebraic)
              else ('list . algid(car u,vars) . x)
   end;

symbolic procedure form2(u,vars,mode);
   begin scalar x;
      if x := get(caar u,'form2fn) then return apply3(x,u,vars,mode)
        else typerr(car u,"operator")
   end;

put('lambda,'form2fn,'formlis);

symbolic procedure argnochk u;
   begin scalar x;
      if null !*argnochk then return u
       else if (x := argsofopr car u) and x neq length cdr u
          %% and null get(car u,'simpfn)
          and null (get(car u,'simpfn) or get(car u,'psopfn)) % FJW ?????
        then rerror('rlisp,11,list(car u,"called with",
                                   length cdr u,
                                   if length cdr u=1 then "argument"
                                    else "arguments",
                                   "instead of",x))
      else return u
   end;

symbolic procedure argsofopr u;
   % This function may be optimizable in various implementations.
   get(u,'number!-of!-args);

symbolic procedure intexprnp(u,vars);
   %determines if U is an integer expression;
    if atom u then if numberp u then fixp u
                   else if (u := atsoc(u,vars)) then cdr u eq 'integer
                   else nil
     else idp car u and flagp(car u,'intfn) and intexprlisp(cdr u,vars);

symbolic procedure intexprlisp(u,vars);
   null u or intexprnp(car u,vars) and intexprlisp(cdr u,vars);

flag('(difference minus plus times),'intfn);
   % EXPT is not included in this list, because a negative exponent can
   % cause problems (i.e., result can be rational);

symbolic procedure formlis(u,vars,mode);
   begin scalar x;
   a: if null u then return reversip!* x;
      x := form1(car u,vars,mode) . x;
      u := cdr u;
      go to a
   end;

symbolic procedure formclis(u,vars,mode);
   begin scalar x;
   a: if null u then return reversip!* x;
      x := formc(car u,vars,mode) . x;
      u := cdr u;
      go to a
   end;

symbolic procedure form u;
   if null atom u and flagp(car u,'always_nform)
     then n_form u   % REDUCE 4.
    else if null !*rlisp88 then form1(u,!*vars!*,!*mode)
    else if null(!*mode eq 'symbolic)
        or flagp(u,'modefn) and null(u eq 'symbolic)
        or flagpcar(u,'modefn) and null(car u eq 'symbolic)
     then typerr("algebraic expression","Rlisp88 form")
    else form1(u,!*vars!*,!*mode);

symbolic procedure macrochk(u,mode);
   begin scalar y;
      % Expands U if CAR U is a macro and expansion allowed.
      % This model has the problem that nested macros are not expanded
      % at this point (but they will be in the compiler).
      if atom u then return u
       else if (y := expdrmacro car u)
        and (mode eq 'symbolic or idp car u and flagp(car u,'opfn))
        then return apply3(get(car y,'macrofn),cdr y,cdr u,car u)
       else return u
   end;

put('symbolic,'idfn,'symbid);

symbolic procedure symbid(u,vars);
   <<if fname!* and null(ftype!* memq '(macro smacro))
       and not(atsoc(u,vars) or fluidp u or globalp u
        or null u or u eq t or flagp(u,'share) or !*comp or !*cref
        or get(u,'constant!?))
       then lprim list("nonlocal use of undeclared variable",u,
                       "in procedure",fname!*);
     u>>;

put('algebraic,'idfn,'algid);

symbolic procedure algid(u,vars);
   if atsoc(u,vars) or flagp(u,'share) then u else mkquote u;

put('integer,'idfn,'intid);

symbolic procedure intid(u,vars);
   begin scalar x,y;
      return if (x := atsoc(u,vars))
        then if cdr x eq 'integer then u
               else if y := get(cdr x,'integer)
                then apply2(y,u,vars)
               else if cdr x eq 'scalar then !*!*a2i(u,vars)
               else rerror('rlisp,12,
                           list(cdr x,"not convertable to INTEGER"))
      else !*!*a2i(mkquote u,vars)
   end;

symbolic procedure convertmode(exprn,vars,target,source);
   convertmode1(form1(exprn,vars,source),vars,target,source);

symbolic procedure convertmode1(exprn,vars,target,source);
   begin scalar x;
      if source eq 'real then source := 'algebraic;
      if target eq 'real then target := 'algebraic;
      if target eq source then return exprn
       else if idp exprn and (x := atsoc(exprn,vars))
          and not(cdr x memq '(integer scalar real))
          and not(cdr x eq source)
        then return convertmode(exprn,vars,target,cdr x)
       else if not (x := get(source,target))
        then typerr(source,target)
       else return apply2(x,exprn,vars)
   end;

put('algebraic,'symbolic,'!*!*a2s);

put('symbolic,'algebraic,'!*!*s2a);

symbolic procedure !*!*a2s(u,vars);
   % It would be nice if we could include the ATSOC(U,VARS) line,
   % since in many cases that would save recomputation. However,
   % in any sequential process, assignments or substitution rules
   % can change the value of a variable, so we have to check its
   % value again.  More comprehensive analysis could certainly
   % optimize this.  We could also avoid wrapping an integer, thus
   % making a mode change only occur within an expression.
   if null u then rederr "tell Hearn!!"
%   else if constantp u and null fixp u
%     or intexprnp(u,vars) and null !*composites
%                and null current!-modulus
    else if flagpcar(u,'nochange) and not(car u eq 'getel)
     then u
    % Expressions involving "random" cannot be cached.
    % We need smember rather than smemq in case the "random" is
    % in a quoted expression.
    else if smember('random,u) then
     list(list('lambda,'(!*uncached),list(!*!*a2sfn,u)),t)
    else list(!*!*a2sfn,u);

symbolic procedure !*!*s2a(u,vars); u;

symbolic procedure formc(u,vars,mode);
   %this needs to be generalized;
   if !*rlisp88 and flagpcar(u,'modefn) and null(car u eq 'symbolic)
     then typerr("algebraic expression","Rlisp88 form")
    else if mode eq 'algebraic and intexprnp(u,vars) then u
    else convertmode(u,vars,'symbolic,mode);

symbolic procedure intargfn(u,vars,mode);
   % transforms array element U into expression with integer arguments.
   % Array name is treated as an algebraic variable;
   begin scalar x,y;
      y := cdr u;
   a: if y then progn(x := convertmode(car y,vars,'integer,mode) . x,
                      y := cdr y,
                      go to a);
      return 'list . form1(car u,vars,'algebraic) . reversip!* x
   end;

put('algebraic,'integer,'!*!*a2i);

symbolic procedure !*!*a2i(u,vars);
   if intexprnp(u,vars) then u else list('ieval,u);

symbolic procedure ieval u; !*s2i reval u;

flag('(ieval),'opfn);   % To make it a symbolic operator.

flag('(ieval),'nochange);

put('symbolic,'integer,'!*!*s2i);

symbolic procedure !*!*s2i(u,vars);
   if fixp u then u else list('!*s2i,u);

symbolic procedure !*s2i u;
   if fixp u then u else typerr(u,"integer");

put('integer,'symbolic,'identity);

symbolic procedure identity(u,vars); u;

symbolic procedure formbool(u,vars,mode);
   if mode eq 'symbolic then formc(u,vars,mode)
    else if atom u then if u eq 't then u
           else if not idp u or atsoc(u,vars)
           then list('boolvalue!*,u)
          else list('boolvalue!*,formc!*(u,vars,mode))
    else if intexprlisp(cdr u,vars) and get(car u,'boolfn) then u
    else if idp car u and get(car u,'boolfn)
     then get(car u,'boolfn) . formclis(cdr u,vars,mode)
    else if idp car u and flagp(car u,'boolean)
        then car u . formboollis(cdr u,vars,mode,flagp(car u,'boolargs))
    else if car u eq 'boolvalue!* then rederr("Too many formbools")
    else if car u eq 'where
     then list('boolvalue!*,
           formc!*(list('where,
                   mkquote list('bool!-eval,formbool(cadr u,vars,mode)),
                   caddr u),
                   vars,mode))
    else list('boolvalue!*,formc!*(u,vars,mode));

symbolic procedure formboollis(u,vars,mode,bool);
   begin scalar x;
   a: if null u then return reversip!* x
       else if bool then x := formbool(car u,vars,mode) . x
       else x := formc!*(car u,vars,mode) . x;
      u := cdr u;
      go to a
   end;

symbolic procedure bool!-eval u; lispeval u;

flag('(bool!-eval),'noform);

flag('(bool!-eval),'opfn);  % symbolic operator bool!-eval.

flag('(bool!-eval),'noval);

symbolic procedure boolvalue!* u; u and null(u = 0);

symbolic procedure formc!*(u,vars,mode);
   begin scalar !*!*a2sfn;
      !*!*a2sfn := 'revalx;
      return formc(u,vars,mode)
   end;

symbolic procedure revalx u;
   % Defined this way to handle standard form kernels in pattern
   % matching.
   reval if not atom u and not atom car u then prepf u else u;

% Functions with side effects must be handled carefully in this model,
% otherwise they are not always evaluated within blocks.

symbolic procedure formrerror(u,vars,mode);
   begin scalar x;
      argnochk u;
      if not fixp caddr u then typerr(caddr u,"RERROR argument");
      x := formc!*(cadddr u,vars,mode);
      if idp cadr u then return list('rerror,mkquote cadr u,caddr u,x)
       else if eqcar(cadr u,'quote) and idp cadadr u
        then return list('rerror,cadr u,caddr u,x)
       else typerr(cadr u,"RERROR argument")
   end;

deflist('((rerror formrerror)),'formfn);   % For bootstrapping.

symbolic procedure formrederr(u,vars,mode);
   list('rederr,formc!*(cadr u,vars,mode));

put('rederr,'formfn,'formrederr);

symbolic procedure formreturn(u,vars,mode);
%  begin scalar x;
%     x := form1(cadr u,vars,mode);  % FORMC here would add REVAL
%     if not(mode memq '(symbolic integer real))
%        and eqcar(x,'setq)             % Should this be more general?
%       then x := list(!*!*a2sfn,x);
%     return list('return,x)
%  end;
   list('return,formc(cadr u,vars,mode));

put('return,'formfn,'formreturn);

symbolic procedure rsverr x;
   rerror('rlisp,13,list (x,"is a reserved identifier"));

symbolic procedure mksetshare(u,v);
   mksetq(u,list('progn,'(setq alglist!* (cons nil nil)),v));

symbolic procedure formsetq(u,vars,mode);
   begin scalar x,y,z;
     if idp(z := car(u := cdr u)) then y := atsoc(z,vars);
     if eqcar(cadr u,'quote) then mode := 'symbolic;
      % Make target always SYMBOLIC so that algebraic expressions
      % are evaluated before being stored.
      x := convertmode(cadr u,vars,'symbolic,mode);
      return if not atom z
        then if not idp car z then typerr(z,"assignment")
          else if null atom(z := macrochk(z,mode)) and arrayp car z
           then list('setel,intargfn(z,vars,mode),x)
          else if null atom z
               and cdr z and (get(car z,'rtype) eq 'vector
                              or vectorp cadr z
                              or flagpcar(cadr z,'vecfn))
           then putvect(u,vars,mode)
          else if eqcar(z,'part)
           then aconc('list .
                      mkquote 'setpart!* . formlis(cdr z,vars,mode),x)
          else if null atom z and (y := get(car z,'setqfn))
           then form1(applsmacro(y,append(cdr z,cdr u),nil),vars,mode)
          else if mode eq 'symbolic
             and (!*rlisp88 or eqcar(z,'structfetch))
          % Allow for Rlisp '88 records in general Rlisp.
           then list('rsetf,form1(z,vars,mode),x)
          else list('setk,form1(z,vars,'algebraic),x)
             % algebraic needed above, since SETK expects it.
    else if not idp z then typerr(z,"assignment")
    else if flagp(z,'reserved) and null atsoc(z,vars) then rsverr z
    else if flagp(z,'share) then mksetshare(symbid(z,vars),x)
    else if mode eq 'symbolic or y or eqcar(x,'quote)
     then mksetq(symbid(z,vars),x)
    else if vectorp cadr u or flagpcar(cadr u,'vecfn)
     then list('setv,mkquote z,cadr u)
    else list('setk,mkquote z,x)
   end;

put('setq,'formfn,'formsetq);

% Table of SETQFNs.

symbolic procedure setcar(a,b); progn(rplaca(a,b),b);

symbolic procedure setcdr(a,b); progn(rplacd(a,b),b);

put('car,'setqfn,'(lambda (u v) (setcar u v)));

put('cdr,'setqfn,'(lambda (u v) (setcdr u v)));

put('caar,'setqfn,'(lambda (u v) (setcar (car u) v)));

put('cadr,'setqfn,'(lambda (u v) (setcar (cdr u) v)));

put('cdar,'setqfn,'(lambda (u v) (setcdr (car u) v)));

put('cddr,'setqfn,'(lambda (u v) (setcdr (cdr u) v)));

put('caaar,'setqfn,'(lambda (u v) (setcar (caar u) v)));

put('caadr,'setqfn,'(lambda (u v) (setcar (cadr u) v)));

put('cadar,'setqfn,'(lambda (u v) (setcar (cdar u) v)));

put('caddr,'setqfn,'(lambda (u v) (setcar (cddr u) v)));

put('cdaar,'setqfn,'(lambda (u v) (setcdr (caar u) v)));

put('cdadr,'setqfn,'(lambda (u v) (setcdr (cadr u) v)));

put('cddar,'setqfn,'(lambda (u v) (setcdr (cdar u) v)));

put('cdddr,'setqfn,'(lambda (u v) (setcdr (cddr u) v)));

put('caaaar,'setqfn,'(lambda (u v) (setcar (caaar u) v)));

put('caaadr,'setqfn,'(lambda (u v) (setcar (caadr u) v)));

put('caadar,'setqfn,'(lambda (u v) (setcar (cadar u) v)));

put('caaddr,'setqfn,'(lambda (u v) (setcar (caddr u) v)));

put('cadaar,'setqfn,'(lambda (u v) (setcar (cdaar u) v)));

put('cadadr,'setqfn,'(lambda (u v) (setcar (cdadr u) v)));

put('caddar,'setqfn,'(lambda (u v) (setcar (cddar u) v)));

put('cadddr,'setqfn,'(lambda (u v) (setcar (cdddr u) v)));

put('cdaaar,'setqfn,'(lambda (u v) (setcdr (caaar u) v)));

put('cdaadr,'setqfn,'(lambda (u v) (setcdr (caadr u) v)));

put('cdadar,'setqfn,'(lambda (u v) (setcdr (cadar u) v)));

put('cdaddr,'setqfn,'(lambda (u v) (setcdr (caddr u) v)));

put('cddaar,'setqfn,'(lambda (u v) (setcdr (cdaar u) v)));

put('cddadr,'setqfn,'(lambda (u v) (setcdr (cdadr u) v)));

put('cdddar,'setqfn,'(lambda (u v) (setcdr (cddar u) v)));

put('cddddr,'setqfn,'(lambda (u v) (setcdr (cdddr u) v)));

put('nth,'setqfn,'(lambda (l i x) (setcar (pnth l i) x)));

put('getv,'setqfn,'(lambda (v i x) (putv v i x)));

put('igetv,'setqfn,'(lambda (v i x) (iputv v i x)));

symbolic procedure formfunc(u,vars,mode);
   if idp cadr u then if getrmacro cadr u
     then rerror('rlisp,14,list("Macro",cadr u,"Used as Function"))
        else list('function,cadr u)
    else list('function,form1(cadr u,vars,mode));

put('function,'formfn,'formfunc);

% RLIS is a parser function that reads a list of arguments and returns
% this list as one argument.  It needs to be defined in this module for
% bootstrapping purposes since this definition only works with its form
% function.

symbolic procedure rlis;
   begin scalar x;
        x := cursym!*;
        return if flagp(scan(),'delim) then list(x,nil)
                else if !*reduce4
                 then list(x,'list . remcomma xread1 'lambda)
                else x . remcomma xread1 'lambda
   end;

symbolic procedure flagop u; begin flag(u,'flagop); rlistat u end;

symbolic procedure rlistat u;
   begin
    a:  if null u then return nil;
        put(car u,'stat,'rlis);
        u := cdr u;
        go to a
   end;

rlistat '(flagop);

symbolic procedure formrlis(u,vars,mode);
   if not flagp(car u,'flagop)
     then list(car u,'list .
                  if car u eq 'share
                    then (begin scalar x,y;
                             y := cdr u;
                          a: if null y then return reversip!* x;
                             x := mkquote car y . x;
                             y := cdr y;
                             go to a
                         end)
                   else formlis(cdr u,vars,'algebraic))
    else if not idlistp cdr u
     then typerr('!*comma!* . cdr u,"identifier list")
    else list('flag,
              'list . formlis(cdr u,vars,'algebraic),mkquote car u);

symbolic procedure mkarg(u,vars);
   % Returns the "unevaled" form of U.
   if null u or constantp u then u
    else if atom u then if atsoc(u,vars) then u else mkquote u
    else if car u memq '(quote !:dn!: !:int!:) then mkquote u
    else begin scalar x;
         a: if null u then return 'list . reversip!* x;
            x := mkarg(car u,vars) . x;
            u := cdr u;
            go to a
         end;

% Form functions needed for number input.

put('!:dn!:,'formfn,'dnform);

% symbolic procedure dnform(u,vars,mode);
%    if mode eq 'symbolic
%      then compress nconc!*(explode cadr u,'!. . 'e . explode cddr u)
%     else progn(if !*adjprec then precmsg length explode abs cadr u,
%                mkquote(quote !:rd!: . cdr u));

symbolic procedure dnform(u,vars,mode);
   if mode eq 'symbolic
     then compress nconc!*(explode cadr u,'!. . 'e . explode cddr u)
    else progn(if !*adjprec then precmsg length explode abs cadr u,
               mkquote if cddr u >= 0
                         then decimal2internal(cadr u,cddr u)
                        else u);

put('!:int!:,'formfn,'intform);

symbolic procedure intform(u,vars,mode);
   if mode eq 'symbolic then mkquote cadr u
   else progn(precmsg length explode abs cadr u, mkquote cadr u);

endmodule;

end;
