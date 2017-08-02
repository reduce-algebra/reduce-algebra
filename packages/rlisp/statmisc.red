module write;  % Miscellaneous statement definitions.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

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

% ***** DEFINE STATEMENT *****

remprop('define,'stat);

symbolic procedure define u;
   for each x in u do
      if not eqcar(x,'equal) or not idp cadr x
        then typerr(x,"DEFINE declaration")
       else put(cadr x,'newnam,caddr x);

deflist('((define rlis)),'stat);

flag('(define),'eval);

% ***** WRITE STATEMENT *****

symbolic procedure formwrite(u,vars,mode);
   begin scalar bool1,bool2,x,y,z;
      u := cdr u;
      bool1 := mode = 'symbolic;
      while u do
        <<x := formc(car u,vars,mode);
          y := getsetvars x;
          z := (if bool1 then list('prin2,x)
                 else list('assgnpri,x,if y then 'list . y else nil,
          if not cdr u then if not bool2 then ''only else ''last
           else if not bool2 then ''first else nil)) .
                             z;
          bool2 := t;
          u := cdr u>>;
        if bool1 then z := nil . z;  % Since PRIN2 returns its value.
        return if null z then nil
                else if null cdr z then car z
                else 'progn . reversip!* z
   end;

put('write,'stat,'rlis);

put('write,'formfn,'formwrite);


% ECHOPR is similar to WRITE but, if switch TESTECHO is on, it echos an
% offline print onto the screen, in either algebraic or symbolic mode.

% Switch is not yet defined.

flag('(testecho),'switch);

put('echopr,'stat,'rlis);

put('echopr,'formfn,'formechopr);

symbolic procedure formechopr(u,vars,mode);
   (lambda x; list ('progn,x,
      list ('cond,list ('(and !*testecho ofl!*),
         list (list ('lambda,'(n),
            list ('progn,x,'(wrs n),nil)),'(wrs nil) ))) ))
       formwrite(u,vars,mode);

% PUSH and POP

%
% I want something that is broadly equivalent to
%
% smacro procedure push(a, b); car (b := a . b);
% smacro procedure pop(b); prog1(car b, b := cdr b);
% but ideally I would avoid repeated evaluation of v in those cases where
% v is messy. Eg as in "pop(car BIGEXPRESSION)" I would want BIGEXPRESSION
% to be evaluated just once. To achieve that I will use a macro rather
% than an smacro... The function cheaptoevaluate will be used to judge
% whether an expression is "big".

% I originally thought to use regular macros for the expansion here, but that
% make it hard to get "form" called properly on all relevant sub-parts. So
% I use formfns.

% When these "macros" are expanded I want the expansions to be deterministic
% both as a matter of general tidiness and because that will interact better
% with the CSL scheme that compiles some code into C. Specifically I want
% any procedure that uses any of these to expand into EXACTLY the same
% stuff each time it is parsed. This means I can not afford to use regular
% gensyms, since their identity will depend on history. But I still want some
% names that will not clash with anthing else present in the code being
% looked at...

fluid '(all!-new!-symbols current!-new!-symbols new!-symbol!-counter);

all!-new!-symbols := nil;
new!-symbol!-counter := 0;

% Find a symbol that is distint from all those in the
% tree structure "env" and that is neither fluid nor global.

symbolic procedure local!-symbol(env);
  begin
    scalar r;
  tryagain:
    if null current!-new!-symbols then <<
      new!-symbol!-counter := new!-symbol!-counter + 1;
      r := intern list2string append('(w), explode new!-symbol!-counter);
      all!-new!-symbols := append(all!-new!-symbols, list r) >>
    else <<
      r := car current!-new!-symbols;
      current!-new!-symbols := cdr current!-new!-symbols >>;
% Note that smember is defined in alg/general.red and so this code is
% unsafe during bootstrapping until that has been compiled. At present this
% only limits use of PUSH and POP until then.
    if fluidp r or globalp r or get(r, 'constant!?) or
      smember(r, env) then go to tryagain;
    return r
  end;

symbolic procedure cheaptoevaluate u;
    atom u or eqcar(u, 'quote);

symbolic procedure allcheaptoevaluate l;
  null l or
  (cheaptoevaluate car l and allcheaptoevaluate cdr l);

symbolic procedure pushpop!-locals(l, r, w, g1, u);
  if null l then r . (w . g1)
  else if cheaptoevaluate car l then pushpop!-locals(cdr l, r, car l . w, g1, u)
  else begin
    scalar g;
    g := local!-symbol u;
    return pushpop!-locals(cdr l, list('setq, g, car l) . r, g . w, g . g1, u)
  end; 

symbolic procedure formpush(u, vars, mode);
  begin
    scalar a, b, g, g1, r, w;
    current!-new!-symbols := all!-new!-symbols;
    u := cdr u;
    if (g := length u) neq 2 then
      rederr list("push called with", g, "arguments instead of 2");
    a := car u;
    b := cadr u;
% I will expand into simple code in cases when that is safe, specifically
% if b is not a big expression and even more so if a is too.
    if atom b or allcheaptoevaluate cdr b then <<
      if cheaptoevaluate a then <<
        if a = b then
          return formc(list('prog1, a, list('setq, b, list('cons, a, b))),
                       vars, mode)
        else return formc(list('progn, list('setq, b, list('cons, a, b)), a),
                          vars, mode) >>;
      g := local!-symbol(u); 
      return formc(list('prog, list g,
          list('setq, g, a),
          list('setq, b, list('cons, g, b)),
          list('return, g)), vars, mode) >>;
% If b is messy I will introduce new local variable for arguments of b.
    r := pushpop!-locals(cdr b, nil, nil, nil, u);
    g1 := cddr r;
    w := car b . reverse cadr r;
    r := reverse car r;    
    return formc('prog . g1 .
      append(r, list(
        list('return, list('car,
          list('setq, w, list('cons, a, w)))))), vars, mode)
  end;

put('push, 'formfn, 'formpush);

symbolic procedure formpop(u, vars, mode);
  begin
    scalar g, g1, a, r, w;
    current!-new!-symbols := all!-new!-symbols;
    u := cdr u;
    if (g := length u) neq 1 then
      rederr list("pop called with", g, "arguments instead of 1");
    a := car u;
    if atom a or allcheaptoevaluate cdr a then
      return formc(list('prog1, list('car, a), list('setq, a, list('cdr, a))),
                   vars, mode);
    r := pushpop!-locals(cdr a, nil, nil, nil, u);
    g1 := (g := local!-symbol u) . cddr r;
    w := car a . reverse cadr r;
    r := reverse car r;    
    return formc('prog . g1 .
      append(r, list(
       list('setq, g, list('car, w)),
       list('setq, w, list('cdr, w)),
       list('return, g))), vars, mode)
  end;

put('pop, 'formfn, 'formpop);

endmodule;

end;
