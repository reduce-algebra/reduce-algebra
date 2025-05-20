module rstyle;  % The Standard LISP to REDUCE pretty-printer.

% Author: Anthony C. Hearn.
% Modifications by: Francis J. Wright.

% This file represents rework by Eberhard Schruefer in 2025 to
% enhance the layout generated. It should be viewed as fragile and
% experimental for now. When it is fully stable it is liable to
% become a replacement for the rprint module and so this file will
% vanish.

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

create!-package('(rstyle),'(util));

fluid '(!*lower !*raise !*n buffp combuff!* curmark curpos orig rs!:pretop
        rs!:pretoprinf rmar rprifn!* rterfn!* rs!:rstyle_indentation);

% After "on rstyle_lower;" identifiers printed here will be converted to
% lower case.
switch rstyle_lower;
!*rstyle_lower := t;

%-----------------------------------------------------
rs!:rstyle_indentation := 2;
% The above sets the indentation of code sections. E.g. the number of blanks on a new line
% after 'begin'. It was hard coded to be 3 in the original rs!:rstyle code. I like 2 better.

% The numeric formatting marks can now have an optional third argument 'b signaling to
% the printing code that here a linebreak should always occur.

% If code that contains mode-functions should be styled, the flag modefn has to be
% removed from them, e.g. by remflag('(algebraic symbolic), 'modefn).

%-----------------------------------------------------

COMMENT RPRIFN!* allows output from RPRINT to be handled differently,
        RTERFN!* allows end of lines to be handled differently;

rs!:pretop := 'op; rs!:pretoprinf := 'rs!:oprinf;

symbolic procedure rstyle u;
   begin integer !*n; scalar buff,buffp,curmark,rmar,x;
      curmark := 0;
      buff := buffp := list list(0,0);
      rmar := linelength nil;
% The code does not always manage to adhere to the right margin, so I
% will give it a bit in hand...
      linelength(rmar+64);
      x := get('!*semicol!*,rs!:pretop);
      !*n := 0;
      rs!:mprino1(u,list(caar x,cadar x));
      rs!:prin2ox ";";
      rs!:omarko curmark;
      rs!:prinos buff;
      linelength rmar
   end;

symbolic procedure rs!:rprin1 u;
   begin scalar buff,buffp,curmark,x;
      curmark := 0;
      buff := buffp := list list(0,0);
      x := get('!*semicol!*,rs!:pretop);
      rs!:mprino1(u,list(caar x,cadar x));
      rs!:omarko curmark;
      rs!:prinos buff
   end;

symbolic procedure rs!:mprino u; rs!:mprino1(u,list(0,0));

symbolic procedure rs!:mprino1(u,v);
   begin scalar x;
        if x := atsoc(u,combuff!*)
          then <<for each y in cdr x do rs!:comprox y;
                 combuff!* := delete(x,combuff!*)>>;
      if numberp u and u<0 and (x := get('difference,rs!:pretop))
        then return begin scalar p;
        x := car x;
        p := not(car x>cadr v) or not(cadr x>car v);
        if p then rs!:prin2ox "(";
        rs!:prinox u;
        if p then rs!:prin2ox ")"
       end
       else if atom u then return rs!:prinox u
      else if not atom car u and (x:=rs!:strangeop u)
          then return rs!:mprino1(x,v)
      else if not atom car u
           then <<curmark := curmark+1;
          rs!:prin2ox "("; rs!:mprino car u; rs!:prin2ox ")";
          rs!:omark list(curmark,rs!:rstyle_indentation); curmark := curmark - 1>>
       else if x := get(car u,rs!:pretoprinf)
        then return begin scalar p;
           p := car v>0
                 and not(car u memq
                           '(list procedure prog quote rblock string));
           if p then rs!:prin2ox "(";
           apply1(x,cdr u);
           if p then rs!:prin2ox ")"
         end
       else if x := get(car u,rs!:pretop)
        then return if car x then rs!:inrs!:prinox(u,car x,v)
                     else if null cadr x then rs!:inrs!:prinox(u,list(100,1),v)
                     else rs!:inrs!:prinox(u,list(100,cadr x),v)
       else if %flagp(car u,'modefn) and
               cdr u and eqcar(cadr u,'procedure)
        then return rs!:proceox(cadadr u . car u . cdr cddadr u)
       else rs!:prinox car u;
      if rs!:rlistatp car u then return rs!:rlpri cdr u;
      u := cdr u;
      if null u then rs!:prin2ox "()"
      else rs!:mprargs(u,v)
   end;

symbolic procedure rs!:strangeop u;
  % U is a non-atomic operator; try to find a better print form for it.
  % The commented definition doesn't check the complexity of the
  % argument, and so can lead to more computation.
% if caar u='lambda and length cadar u=1 then
%   subst(cadr u,car cadar u,car cddar u);
   nil;

symbolic procedure rs!:mprargs(u,v);
   if null cdr u then <<rs!:prin2ox " "; rs!:mprino1(car u,list(100,100))>>
    else <<rs!:prin2ox "("; rs!:omark '(m u);
           curmark := curmark+2;
           rs!:mprino1(car u, list(0,0));
           u := cdr u;
           while u do
             <<rs!:prin2ox ", "; rs!:omarko curmark;
               rs!:mprino1(car u,list(0,0));
               u := cdr u>>;
           rs!:prin2ox ")"; rs!:omark '(m d);
           curmark := curmark - 2>>;


symbolic procedure rs!:inrs!:prinox(u,x,v);
   begin scalar p;
      p := not(car x>cadr v) or not(cadr x>car v);
      if p then rs!:prin2ox "("; rs!:omark '(m u);
      rs!:inprino(car u,x,cdr u);
      if p then rs!:prin2ox ")"; rs!:omark '(m d)
   end;

symbolic procedure rs!:inprino(opr,v,l);
   begin scalar flg,x;
      curmark := curmark+2;
      x := get(opr,rs!:pretop);
      if x and car x
        then <<rs!:mprino1(car l,list(car v,0)); l := cdr l; flg := t>>;
      while l do
        <<if opr eq '!*comma!* then <<rs!:prin2ox ","; rs!:omarko curmark>>
           else if opr eq 'setq
            then <<rs!:prin2ox " := "; rs!:omark list(curmark,1)>>
        else if atom car l or not(opr eq get(caar l,'alt))
        then <<rs!:omark list(curmark,1); rs!:oprino(opr,flg); flg := t>>;
      rs!:mprino1(car l,list(if null cdr l then 0 else car v,
                         if null flg then 0 else cadr v));
         l := cdr l>>;
      curmark := curmark - 2
   end;

symbolic procedure rs!:oprino(opr,b);
   (lambda x; if null x
                 then <<if b then rs!:prin2ox " "; rs!:prinox opr; rs!:prin2ox " ">>
               else <<if y then rs!:prin2ox " "; rs!:prin2ox x;
                      if y then rs!:prin2ox " ">>
                     where y = flagp(opr,'spaced))
   get(opr,'prtch);

flag('(cons),'spaced);

flag('(add mult over to),'spaced);  % So that we don't have 1./1 etc.

symbolic procedure rs!:prin2ox u;
   <<rplacd(buffp,rs!:explodex u);
     while cdr buffp do buffp := cdr buffp>>;

symbolic procedure rs!:explodex u;
   % "Explodes" atom U without including escape characters.
   if numberp u then explode u
    else if stringp u then reversip cdr reversip cdr explode u
    else rs!:explodex1 explode u;

symbolic procedure rs!:explodex1 u;
   if null u then nil
    else if car u eq '!! then cadr u . rs!:explodex1 cddr u
    else rs!:check!-downcase car u . rs!:explodex1 cdr u;

symbolic procedure rs!:explodey u;
   begin scalar v;
      v := explode u;
% This will map all identifiers into lower case. I arrange that this
% is not done if the user has reset !*rstyle_lower to nil.
      if idp u and !*rstyle_lower then
         v := for each x in v collect rs!:check!-downcase x;
      return v
   end;

symbolic procedure rs!:check!-downcase u;
   begin scalar z;
      return if liter u
                and (z := atsoc(u,
                     '((!A . !a) (!B . !b) (!C . !c) (!D . !d) (!E . !e)
                       (!F . !f) (!G . !g) (!H . !h) (!I . !i) (!J . !j)
                       (!K . !k) (!L . !l) (!M . !m) (!N . !n) (!O . !o)
                       (!P . !p) (!Q . !q) (!R . !r) (!S . !s) (!T . !t)
                       (!U . !u) (!V . !v) (!W . !w) (!X . !x) (!Y . !y)
                       (!Z . !z))))
               then cdr z
              else u
   end;

symbolic procedure rs!:prinox u;
   <<if x then u := x;
     rplacd(buffp,rs!:explodey u);
     while cdr buffp do buffp := cdr buffp>>
    where x = get(u,'oldnam);

symbolic procedure rs!:omark u;
   <<rplacd(buffp,list u); buffp := cdr buffp>>;

symbolic procedure rs!:omarko u; rs!:omark list(u,0);

symbolic procedure rs!:comprox u;
   begin scalar x;
        if car buffp = '(0 0)
          then return <<for each j in u do rs!:prin2ox j;
                        rs!:omark '(0 0)>>;
        x := car buffp;
        rplaca(buffp,list(curmark+1,rs!:rstyle_indentation));
        for each j in u do rs!:prin2ox j;
        rs!:omark x
   end;

symbolic procedure rs!:rlistatp u;
   get(u,'stat) member '(endstat rlis);

symbolic procedure rs!:rlpri u;
   if null u then nil
    else begin
      rs!:prin2ox " ";
      rs!:omark '(m u);
      rs!:inprino('!*comma!*,list(0,0),u);
      rs!:omark '(m d)
   end;

symbolic procedure rs!:condox u;
   begin scalar x;
      rs!:omark '(m u);
      curmark := curmark+2;
      while u do
        <<rs!:prin2ox "if "; rs!:mprino caar u;
          rs!:prin2ox " then "; rs!:omark list(curmark,rs!:rstyle_indentation+1);
          if cddar u then u := list(caar u, 'progn . cdar u) . cdr u;  
          if cdr u and eqcar(cadar u,'cond)
                 and not eqcar(car reverse cadar u,'t)
           then <<x := t; rs!:prin2ox "(">>;
          rs!:mprino cadar u;
          if x then rs!:prin2ox ")";
          u := cdr u;
          if u then <<rs!:omark list(curmark - 1, 1,'b); rs!:prin2ox "else ">>;
          if u and null cdr u and caar u eq 't
            then <<rs!:mprino (if cddar u then 'progn . cdar u else cadar u);
                   u := nil>>>>;
      curmark := curmark - 2;
      rs!:omark '(m d)
   end;

put('cond,rs!:pretoprinf,'rs!:condox);

symbolic procedure rs!:ifox u;
  begin
% Common Lisp stype IF.
    scalar p, a, b;
    p := car u;
    u := cdr u;
    if u then << a := car u; u := cdr u >>;
    if u then << b := car u; u := cdr u >>;
% (if b X nil) can be treated as just (cond (b X)) and does not need to be
% the full (cond (b X) (t nil)).
    if null b then rs!:condox list(list(p, a))
    else rs!:condox list(list(p, a), list(t, b))
  end;

put('if,rs!:pretoprinf,'rs!:ifox);

symbolic procedure rs!:blockox u;
   begin
      rs!:omark '(m u);
      curmark := curmark+2;
      rs!:prin2ox "begin ";
      if car u then rs!:varprx car u;
      u := rs!:labchk cdr u;
      rs!:omark list(curmark,
                 if eqcar(car u,'!*label)
                    then 1
                   else rs!:rstyle_indentation, 'b);
      while u do
        <<rs!:mprino car u;
        if not eqcar(car u,'!*label) and cdr u then rs!:prin2ox "; ";
        u := cdr u;
        if u
          then rs!:omark list(curmark,
                          if eqcar(car u,'!*label)
                             then 1
                           else rs!:rstyle_indentation, 'b)>>;
      rs!:omark list(curmark - 1,-1,'b);
      rs!:prin2ox " end";
      curmark := curmark - 2;
      rs!:omark '(m d)
   end;

symbolic procedure rs!:retox u;
   begin
      rs!:omark '(m u);
      curmark := curmark+2;
      rs!:prin2ox "return ";
      rs!:omark '(m u);
      rs!:mprino car u;
      curmark := curmark - 2;
      rs!:omark '(m d);
      rs!:omark '(m d)
   end;

put('return,rs!:pretoprinf,'rs!:retox);

symbolic procedure rs!:varprx u;
   begin scalar typ;
       while u do
        <<if cdar u eq typ
            then <<rs!:prin2ox ", "; rs!:omarko(curmark+1); rs!:prinox caar u>>
           else <<if typ then <<rs!:prin2ox "; "; rs!:omark '(m d)>>;
                rs!:omark list(curmark,rs!:rstyle_indentation,'b);
                rs!:prinox (typ := cdar u);
                  rs!:prin2ox " "; rs!:omark '(m u); rs!:prinox caar u>>;
           u := cdr u>>;
      rs!:prin2ox "; ";
      rs!:omark '(m d)
   end;

put('rblock,rs!:pretoprinf,'rs!:blockox);

symbolic procedure rs!:prors!:gox u;
%  The reverse in the following seems wrong.
%  rs!:blockox((for each j in reverse car u collect j . 'scalar) . cdr u);
   rs!:blockox((for each j in car u collect j . 'scalar) . cdr u);

symbolic procedure rs!:labchk u;
   begin scalar x;
      for each z in u do if atom z
        then x := list('!*label,z) . x else x := z . x;
       return reversip x
   end;

put('prog,rs!:pretoprinf,'rs!:prors!:gox);

symbolic procedure rs!:gox u;
   <<rs!:prin2ox "go to "; rs!:prinox car u>>;

put('go,rs!:pretoprinf,'rs!:gox);

symbolic procedure rs!:labox u;
   <<rs!:prinox car u; rs!:prin2ox ": ">>;

put('!*label,rs!:pretoprinf,'rs!:labox);

symbolic procedure rs!:quotoxx u;
   begin
      if stringp u then return rs!:prinox u;
      rs!:prin2ox "'";
      u := car u;
      if atom u then return rs!:prinox u;
      curmark := curmark+1;
      rs!:prin2ox "(";
      rs!:omark '(m u);
  a:  if atom u then <<rs!:prin2ox " . "; rs!:prinox u; u := nil>>
       else <<rs!:mprino car u; u := cdr u;
              if u then <<rs!:prin2ox blank; rs!:omarko curmark>>>>;
      if u then go to a;
      rs!:omark '(m d);
      rs!:prin2ox ")";
      curmark := curmark - 1
   end;

symbolic procedure rs!:quotox u;
   if stringp u then rs!:prinox u else <<rs!:prin2ox "'"; rs!:prinsox car u>>;

symbolic procedure rs!:prinsox u;
   if atom u then rs!:prinox u
    else <<curmark := curmark+1;
           rs!:prin2ox "(";
           rs!:omark '(m u);
           while u do <<rs!:prinsox car u;
                        u := cdr u;
                        if u then <<rs!:omark list(curmark,-1);
                        if atom u
                          then <<rs!:prin2ox " . "; rs!:prinsox u; u := nil>>
                         else rs!:prin2ox " ">>>>;
           rs!:omark '(m d);
           rs!:prin2ox ")";
           curmark := curmark - 1>>;

put('quote,rs!:pretoprinf,'rs!:quotox);

symbolic procedure rs!:prognox u;
   begin
      curmark := curmark+1;
      rs!:prin2ox "<<";
      rs!:omark '(m u);
      while u do <<rs!:mprino car u; u := cdr u;
                if u then <<rs!:prin2ox "; "; rs!:omark list(curmark,0,'b)>>>>;
      rs!:omark '(m d);
      rs!:prin2ox ">>";
      curmark := curmark - 1
   end;

put('prog2,rs!:pretoprinf,'rs!:prognox);

put('progn,rs!:pretoprinf,'rs!:prognox);

symbolic procedure rs!:listox u;
   begin
      curmark := curmark+1;
      rs!:prin2ox "{";
      rs!:omark '(m u);
      while u do <<rs!:mprino car u; u := cdr u;
               if u then <<rs!:prin2ox ", "; rs!:omarko curmark>>>>;
%                if u then <<rs!:prin2ox ","; rs!:omarko curmark>>>>;
      rs!:omark '(m d);
      rs!:prin2ox "}";
      curmark := curmark - 1
   end;

put('list,rs!:pretoprinf,'rs!:listox);

symbolic procedure rs!:repeatox u;
   begin
      curmark := curmark+1;
      rs!:omark '(m u);
      rs!:prin2ox "repeat ";
      rs!:mprino car u;
      rs!:prin2ox " until ";
      rs!:omark list(curmark,rs!:rstyle_indentation,'b);
      rs!:mprino cadr u;
      rs!:omark '(m d);
      curmark := curmark - 1
   end;

put('repeat,rs!:pretoprinf,'rs!:repeatox);

symbolic procedure rs!:whileox u;
   begin
      curmark := curmark+1;
     rs!:omark '(m u);
      rs!:prin2ox "while ";
      rs!:mprino car u;
      rs!:prin2ox " do ";
      rs!:omark list(curmark,rs!:rstyle_indentation,'b);
      rs!:mprino cadr u;
      rs!:omark '(m d);
      curmark := curmark - 1
   end;

put('while,rs!:pretoprinf,'rs!:whileox);

symbolic procedure rs!:procox u;
   begin
      rs!:omark '(m u);
      curmark := curmark+1;
      if cadddr cdr u then <<rs!:mprino cadddr cdr u; rs!:prin2ox " ">>;
      rs!:prin2ox "procedure ";
      rs!:procox1(car u,cadr u,caddr u)
   end;

symbolic procedure rs!:procox1(u,v,w);
   begin
      rs!:prinox u;
      if v then rs!:mprargs(v,list(0,0));
      rs!:prin2ox "; ";
      rs!:omark list(curmark,rs!:rstyle_indentation,'b);
      rs!:mprino w;
      curmark := curmark - 1;
      rs!:omark '(m d)
   end;

put('proc,rs!:pretoprinf,'rs!:procox);

symbolic procedure rs!:proceox u;
   begin
      rs!:omark '(m u);
      curmark := curmark+1;
 %     if flagp(car u, 'opfn) then rs!:prin2ox "algebraic "
 %      else rs!:prin2ox "symbolic ";
      if cadr u then <<rs!:mprino cadr u; rs!:prin2ox " ">>;
      if not(caddr u eq 'expr) then <<rs!:mprino caddr u; rs!:prin2ox " ">>;
      rs!:prin2ox "procedure ";
      rs!:proceox1(car u,cadddr u,car cddddr u)
   end;

symbolic procedure rs!:proceox1(u,v,w);
   % Prettyprint the procedure's argument list, any active annotation,
   % and its body.
   begin scalar annot;
      rs!:prinox u;
      if v
        then <<if not atom car v then v := mapovercar v;
               %allows for typing to be included with proc arguments;
               rs!:mprargs(v,list(0,0))>>;
      rs!:prin2ox "; ";
      if annot := get(u,'active!-annotation) then
            <<rs!:omark list(curmark,rs!:rstyle_indentation);
              rs!:prin2ox "/* ";
              rs!:princom car annot;
              rs!:prin2ox " */";
              rs!:omark '(m d)>>;
      rs!:omark list(curmark,rs!:rstyle_indentation,'b);
      rs!:mprino w;
      curmark := curmark - 1;
      rs!:omark '(m d)
   end;

put('procedure,rs!:pretoprinf,'rs!:proceox);

symbolic procedure rs!:proceox0(u,v,w,x);
   rs!:proceox list(u,'symbolic,v,for each j in w collect j . 'symbolic,x);

symbolic procedure rs!:deox u;
   rs!:proceox0(car u,'expr,cadr u,
      (if cdddr u then 'progn . cddr u else caddr u));

put('de,rs!:pretoprinf,'rs!:deox);

% symbolic procedure dfox u;
%   rs!:proceox0(car u,'fexpr,cadr u,caddr u);

%put('df,rs!:pretoprinf,'dfox);  % Commented out because of confusion with
                             % differentiation.  We also want to
                             % discourage use of fexpr in REDUCE.

symbolic procedure rs!:dsox u;
   rs!:proceox0(car u,'smacro,cadr u,caddr u);

put('ds,rs!:pretoprinf,'rs!:dsox);

symbolic procedure strinrs!:gox u;
   <<rs!:prin2ox '!"; rs!:prin2ox car u; rs!:prin2ox '!">>;

put('string,rs!:pretoprinf,'strinrs!:gox);

symbolic procedure rs!:lambdox u;
   begin
      rs!:omark '(m u);
      curmark := curmark+1;
      rs!:procox1('lambda,car u,cadr u)
   end;

put('lambda,rs!:pretoprinf,'rs!:lambdox);

symbolic procedure rs!:eachox u;
   begin
     curmark := curmark + 1;
     rs!:omark '(m u);
     rs!:prin2ox "for each ";
     while cdr u do <<rs!:mprino car u; rs!:prin2ox " "; u := cdr u>>;
     rs!:omark list(curmark,rs!:rstyle_indentation,'b);
     rs!:mprino car u;
     curmark := curmark - 1;
     rs!:omark '(m d)
   end;

put('foreach,rs!:pretoprinf,'rs!:eachox);

symbolic procedure rs!:forox u;
   begin
      curmark := curmark+1;
      rs!:omark '(m u);
      rs!:prin2ox "for ";
      rs!:mprino car u;
      rs!:prin2ox " := ";
      rs!:mprino caadr u;
      if cadr cadr u neq 1
        then <<rs!:prin2ox " step "; rs!:mprino cadr cadr u; rs!:prin2ox " until ">>
       else rs!:prin2ox ":";
      rs!:mprino caddr cadr u;
      rs!:prin2ox " ";
      rs!:mprino caddr u;
      rs!:prin2ox " ";
      rs!:omark list(curmark,rs!:rstyle_indentation);
      rs!:mprino cadddr u;
      rs!:omark '(m d);
      curmark := curmark - 1
   end;

put('for,rs!:pretoprinf,'rs!:forox);

symbolic procedure rs!:forallox u;
   begin
      curmark := curmark+1;
      rs!:omark '(m u);
      rs!:prin2ox "for all ";
      rs!:inprino('!*comma!*,list(0,0),car u);
      if cadr u
        then <<rs!:omark list(curmark,rs!:rstyle_indentation);
               rs!:prin2ox " such that ";
               rs!:mprino cadr u>>;
      rs!:prin2ox " ";
      rs!:omark list(curmark,rs!:rstyle_indentation);
      rs!:mprino caddr u;
      rs!:omark '(m d);
      curmark := curmark - 1
   end;

put('forall,rs!:pretoprinf,'rs!:forallox);

symbolic procedure rs!:commentox u;
   begin
      curmark := curmark+2;
      rs!:omark '(m u);
      rs!:prin2ox car u;
      rs!:omark list(curmark,0,'b);
      for each x in cdr u do <<
         rs!:prin2ox "% ";
         rs!:mprino x;
         rs!:omark list(curmark,0,'b);
         nil >>;
      curmark := curmark - 2;
      rs!:omark '(m d)
   end;

%put('!%,rs!:pretoprinf,'rs!:commentox);

COMMENT Support for printing algebraic mode code;

put('aeval!*,rs!:pretoprinf,'rs!:aevalox);

put('aeval,rs!:pretoprinf,'rs!:aevalox);

put('revalx,rs!:pretoprinf,'rs!:aevalox);       % FJW.

symbolic procedure rs!:aevalox(u);
      rs!:mprino rs!:aevalox1 car u;

symbolic procedure rs!:aevalox1 u;
  % unquote and listify.
  if eqcar(u,'quote) then cadr u else
  if eqcar(u,'list) then
    for each q in u collect rs!:aevalox1 q else u;

symbolic procedure rs!:minuspox u;
  if eqcar(car u,'difference) then
     rs!:mprino('lessp.cdar u) else rs!:mprino('lessp.car u.'(0));

put('minusp,rs!:pretoprinf,'rs!:minuspox);
put('aminusp!:,rs!:pretoprinf,'rs!:minuspox);
put('evalequal,rs!:pretoprinf,function (lambda u;rs!:mprino('equal.u)));
put('evalgreaterp,rs!:pretoprinf,function (lambda u;rs!:mprino('greaterp.u)));
put('evalgeq,rs!:pretoprinf,function (lambda u;rs!:mprino('geq.u)));
put('evallessp,rs!:pretoprinf,function (lambda u;rs!:mprino('lessp.u)));
put('evalleq,rs!:pretoprinf,function (lambda u;rs!:mprino('leq.u)));
put('evalneq,rs!:pretoprinf,function (lambda u;rs!:mprino('neq.u)));
put('!:dn!:,rs!:pretoprinf,function (lambda u;
                rs!:mprino(float car u*expt(float 10,cdr u))));
put('!:rd!:,rs!:pretoprinf,function (lambda u;
                rs!:mprino(if atom u then u else
                        float car u*expt(float 2,cdr u))));
put('plus2,rs!:pretoprinf,function(lambda u;rs!:mprino('plus.u)));


COMMENT Declarations needed by old parser;

if null get('!*semicol!*,'op)
  then <<put('!*semicol!*,'op,'((-1 0)));
         put('!*comma!*,'op,'((5 6)))>>;

% Code for printing active comments.

symbolic procedure rs!:princom u;
   % Print an active comment.
   begin scalar w,x,y,z; integer n;
      x := explode2 u;
      % Process first line.
      while car x eq blank do x := cdr x;
      while x and car x neq !$eol!$ do <<y := car x . y; x := cdr x>>;
      while y and car y eq blank do y := cdr y;
      w := reversip!* y;    % Header line.
      % Process remaining lines.
      while x and (x := cdr x) do
       <<y := nil;
         n := 0;
         while car x eq blank do <<x := cdr x; n := n+1>>;
         while x and car x neq !$eol!$ do <<y := car x . y; x:= cdr x>>;
         while y and car y eq blank do y := cdr y;
         z := (n . reversip!* y) . z>>;
      % Find line with least blanks.
      y := z;
      if y
        then <<n := caar y; while (y := cdr y) do n := min(n,caar y)>>;
      while z do <<y := rs!:addblanks(cdar z,caar z - n) . y; z := cdr z>>;
      % Now merge lines where possible.
      while y do
       <<z := car y;
         if not(car z eq blank ) and not(car w eq blank)
           then <<z := blank . z; w := nconc!*(w,z)>>
          else <<x := w . x; w := z>>;
         y := cdr y>>;
      x := w . x;
      % Final processing.
      x := reversip!* x;
      while x do <<rs!:addmarks car x; x := cdr x;
                   if x then rs!:omark list(curmark,rs!:rstyle_indentation)>>
   end;

symbolic procedure rs!:addblanks(u,n);
   if n=0 then u else blank . rs!:addblanks(u,n - 1);

symbolic procedure rs!:addmarks u;
   begin scalar bool,x;
      while u do
         <<if car u eq blank then (if null bool
                then <<bool := t; x := {'m,'l} . x>>)
               else bool := nil;
           x := car u . x; u := cdr u>>;
      rplacd(buffp,reversip!* x);
      while cdr buffp do buffp := cdr buffp
   end;


COMMENT RPRINT MODULE, Part 2;

fluid '(orig curpos);

symbolic procedure rs!:prinos u;
   begin
      integer curpos;
      scalar !*lower,orig;
      orig := list posn();
      curpos := car orig;
      rs!:prinoy(u,0);
      rs!:terpri0x()
   end;

symbolic procedure rs!:prinoy(u,n);
   begin scalar x;
      if car(x := rs!:spaceleft(u,n)) then return rs!:prinom(u,n)
       else if null cdr x then return if car orig<10 then rs!:prinom(u,n)
       else <<orig := 9 . cdr orig;
                rs!:terpri0x();
                rs!:spaces20x(curpos := 9+cadar u);
                rs!:prinoy(u,n)>>
      else begin
        a: u := rs!:prinoy(u,n+1);
           if null cdr u or caar u<=n then return;
           rs!:terpri0x();
           rs!:spaces20x(curpos := car orig+cadar u);
           go to a end;
      return u
   end;

symbolic procedure rs!:spaceleft(u,mark);
   %U is an expanded buffer of characters delimited by non-atom marks
   %of the form: '(M ...) or '(INT INT))
   %MARK is an integer;
   begin integer n; scalar flg,mflg;
      n := rmar - curpos;
      u := cdr u;   %move over the first mark;
      while u and not flg and n>=0 do
        <<if atom car u then n := n - 1
           else if caar u eq 'm then nil
           else if mark>=caar u then <<flg := t; u := nil . u>>
           else mflg := t;
          u := cdr u>>;
      return ((n>=0) . mflg)
   end;

symbolic procedure rs!:prinom(u,mark);
   begin integer n; scalar flg,x;
      n := curpos;
      u := cdr u;
      while u and not flg do
        <<if atom car u then <<x := rs!:prin20x car u; n := n+1>>
          else if caar u eq 'm   % a non numeric marking
           then if cadar u eq 'u then orig := n . orig % push orig onto the stack
                 else if cadar u eq 'l
                  then (if rs!:chars2 cdr u > (rmar - posn())
                          then <<rs!:terpri0x(); rs!:spaces20x(curmark+5)>>)
                 else orig := cdr orig  % implicit d. Pop the orig stack.
           % Check for long thin lists.
           else if (mark>=caar u
              and not(x memq '(!,) % '(!, ! )
                       and rmar - n - 6>rs!:charspace(u,x,mark)))
            then <<flg := t; u := nil . u>>
           else if eqcar(cddar u, 'b)
            then <<rs!:terpri0x(); rs!:spaces20x(n := car orig + cadar u)>>;
          u := cdr u>>;
      curpos := n;
        if mark=0 and cdr u
          then <<rs!:terpri0x();
%                rs!:terpri0x();
                 orig := list 0; curpos := 0; rs!:prinoy(u,mark)>>;
          %must be a top level constant;
      return u
   end;

symbolic procedure rs!:chars2 u; rs!:chars21(u,0);

symbolic procedure rs!:chars21(u,n);
   if eqcar(car u,'m) then n else rs!:chars21(cdr u,n+1);

symbolic procedure rs!:charspace(u,char,mark);
   % Determines if there is space until the next character CHAR.
   begin integer n;
      n := 0;
      while u do
        <<if car u = char then u := list nil
           else if atom car u then n := n+1
           else if car u='(m u) then <<n := 1000; u := list nil>>
           else if numberp caar u and caar u<mark then u := list nil;
          u := cdr u>>;
      return n
   end;

symbolic procedure rs!:spaces20x n;
   %for i := 1:n do rs!:prin20x blank;
   while n>0 do <<rs!:prin20x blank; n := n - 1>>;

symbolic procedure rs!:prin2rox u;
   begin integer m,n; scalar x,y;
      m := rmar - 12;
      n := rmar - 1;
      while u do
        if car u eq '!"
          then <<if not rs!:stringspace(cdr u,n - !*n)
                   then <<rs!:terpri0x(); !*n := 0>>
                  else nil;
                 rs!:prin20x '!";
                 u := cdr u;
                 while not(car u eq '!") do
                   <<rs!:prin20x car u; u := cdr u; !*n := !*n+1>>;
                 rs!:prin20x '!";
                 u := cdr u;
                 !*n := !*n+2;
                 x := y := nil>>
         else if atom car u and not(car u eq blank and (!*n=0 or null x
              or cdr u and rs!:breakp cadr u or rs!:breakp x and not(y eq '!!)))
          then <<y := x; rs!:prin20x(x := car u); !*n := !*n+1;
         u := cdr u;
         if !*n=n or !*n>m and not rs!:breakp car u and rs!:nospace(u,n - !*n)
          then <<rs!:terpri0x(); x := y := nil>> else nil>>
         else u := cdr u
   end;

symbolic procedure rs!:nospace(u,n);
   if n<1 then t
    else if null u then nil
    else if not atom car u then rs!:nospace(cdr u,n)
    else if not(car u eq '!!) and (cadr u eq blank or rs!:breakp cadr u)
     then nil
    else rs!:nospace(cdr u,n - 1);

symbolic procedure rs!:breakp u;
   u member '(!< !> !; !: != !) !+ !- !, !' !");

symbolic procedure rs!:stringspace(u,n);
   if n<1 then nil else car u eq '!" or rs!:stringspace(cdr u,n - 1);


COMMENT Some interfaces needed;

symbolic procedure rs!:prin20x u;
   if rprifn!* then apply1(rprifn!*,u) else prin2 u;

symbolic procedure rs!:terpri0x;
   if rterfn!* then lispeval {rterfn!*} else terpri();

endmodule;

end;

%%%%%%%%%%%%%%%%%%%%
% remflag('(algebraic symbolic), 'modefn);
% remprop('write, 'stat);
%%%%%%%%%%%%%%%%%%%%

