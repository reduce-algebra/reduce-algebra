module smacro;  % Support for SMACRO expansion

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


%
% This function expands an  invocation of a SMACRO.
%
% Getting this right in all cases seems to be harder than I had expected!
% One simple interpretation of what an SMACRO is is that it represents
% a simple textual expansion, so after
%   smacro procedure f(a,b) E;
% any instance of f(A,B) is expanded to E|a=>A,b=>B using textual
% substitution.
% A different intent for SMACRO is that it marks a procedure to be
% compiled/expanded in-line for performance reasons. The code in Reduce
% up to 3.8 implemented something that was part way between those!
%
% Here are some of the critical cases:
%    smacro procedure f a; ... a ... a...;
%    f(A)  ->   ... A ... A ...                               (a)
%      OR  ->   ((lambda (a) ... a ... a ...) A)              (b)
% The first is what textual expansion suggests, but if the argument A
% is either an expensive-to-evaluate form or has side-effects then
% letting it appear several times within the expansion may be bad either
% for semantics or performance or both. A variation on this arises if the
% formal parameter a does not occur at all within the body of the smacro,
% or is guarded there by an IF, and the actual argument has side-effects.
% Then one version of the expansion WILL evaluate the argument while the
% other will or may not.
%
% Reduce 3.8 uses expansion (a) if either the formal a occurs at most
% once in the body OR (b) the actual argument is one of a limited number
% of sorts of form that can be seen to be side-effect free. For smacros
% with two or more arguments it can lambda-lift just some of the parameters.
%
% Here are some cases where this may cause trouble:
%    smacro procedure f a; 'nothing;
%    ... f(print x) ...                   The print does not happen.
%                                         Maybe that was expected!
%    smacro procedure f a; << if nil then a; if nil then a; nil >>;
%    ... f(print x) ...
% Reduce 3.8 uses expansion (b) and so the print DOES happen.
%
% In these examples I will be using PRINT to stand for something arbitrary
% that may have side effects, might yield different results when called twice
% (including GENSYM and CONS) or might be an expensive computation.
%
%    smacro procedure f(a, b); b . a;
%    ... f(print x, print y) ...
% uses expansion (a) and the prints happen in an order that may be
% unexpected.
%    smacro procedure f(a, b); list(a, b, b);
%    ... f(print x, print y) ...
% uses a lambda at least for b, so y only gets printed once, but probably
% before x.
%
%    smacro procedure set_cdr(a, b); << rplacd(a, b); b >>;
%    ... set_cdr(x, cons(p, q)) ...
%    ... set_cdr(x, cddr x) ...
% if CONS is tagged as side-effect free this does TWO conses and the
% results are almost certainly not what is wanted. And simple inline
% expansion in the second case returns a "wrong" value.
%
%    smacro procedure f(a, b); << a := 1; print b; a := 2; print b >>;
%    ... f(v, v+3) ...
% Oh dear: v+3 is probably not tagged as side-effect free and both a and b
% are used twice in the function body. But there seems to be a clear
% expectation that the first argument will be textually substituted so that
% the assignments take full effect.
%
%    smacro procedure f a; ... a ... (lambda (a) ...) ...;
% This might arise if a previous smacro used (b) expansion leading to the
% embedded lambda expression, and the names used for formal in the two
% smacros happened to match. If then textual substitution is performed it
% needs to understand the scope rules of nested lambdas and progs. It
% may also need to know that a symbol at the top level of a prog names a
% label not a variable (and ditto (GO x)).
%
%   smacro procedure f x; while a do print (a := cdr a);
%   x := '(1 2 3); f x; print x;
% Depending on expansion style this prints different values at the end.
%
%   smacro procedure increment a; a := a + 1;
% This illustrates a case where it is clear that a direct textual expansion
% is expected. However despite "car x := car x + 1" being accepted syntax the
% order in which things are done means that "increment (car x)" expands to
% and illegal (setq (car x) (plus (car x) 1)) in Reduce 3.8. And
% increment (getv(x, 2)) becomes ((lambda (a) (setq a (plus a 1))) (getv x 2)).
% because while CAR is tagged as side-effect free GETV is not.
%
% Now by and large these are cases that do not arise too often when smacros
% are used for really simple things and and manually created by people who
% understand what is going on. Well the special treatment in Reduce 3.8 as
% regards how many times a formal is used in the body of the smacro and
% whether the actual argument has side effects suggests that there have been
% problems in individual cases before! But if I try to use the smacro
% mechanism as a generic way of getting in-line compilation I may scan the
% whole source of Reduce and convert small procedures into smacros. And
% then the sorts of issue discussed here bite repeatedly!

% I hope these comments will help anybody writing their own smacros. I
% have introduced a new keyword
%   inline procedure f(x); ...;
% with unambiguous call-by-value semantics, but meanwhile in any automatic
% conversion from procedure to smacro the issues here need to be thought
% about.    ACN September 2010.

% The flag !*loginlines enables reports that may help identify places where
% some of the above issues arise.  ACN March 2013.

fluid '(!*defn inlineinfo);

symbolic procedure applsmacro(u,vals,name);
   % U is smacro body of form (lambda <varlist> <body>), VALS is
   % argument list, NAME is name of smacro.
   begin scalar body,remvars,varlist,w,inlineinfo;
      varlist := cadr u;
      body := caddr u;
      inlineinfo := list(name, varlist, body);
      if length varlist neq length vals
        then rerror(rlisp,15,list("Argument mismatch for SMACRO",name));
      if !*loginlines then log_inlines(varlist, body, vals);
      if no!-side!-effect!-listp vals or one!-entry!-listp(varlist,body)
        then return subla!-q(pair(varlist,vals),body)
       else if length varlist>1
        then <<w := for each x in varlist collect (x . gensym());
               body := subla!-q(w,body);
               varlist := for each x in w collect cdr x>>;
      for each x in vals do
         <<if no!-side!-effectp x or one!-entryp(car varlist,body)
             then body := subla!-q(list(car varlist . x),body)
            else remvars := aconc(remvars,car varlist . x);
           varlist := cdr varlist>>;
      if null remvars then return body
       else <<w := list('lambda,
                         for each x in remvars collect car x,
                         body) .
                    for each x in remvars collect cdr x;
%             if not eqcar(cadr w,'setq)
%               then <<prin2 "*** inline: "; print cdr w>>;
              return w>>
   end;

% In my analysis here I am going to be slightly sloppy in my traversal
% of code - I will not expand further macros and I may ignore special
% features of some special forms. Since this is just to generate a report
% I think that perfection is not necessary!

symbolic procedure log_inlines(varlist, body, vals);
  begin
% (1) Are there assignments to any of the variable in varlist within body?
%     If so conversion from a macro to a procedure would change the
%     behaviour.
    if log_assignment(varlist, body) then return nil;
% (2) Does body use any variables that are free in it but not fluid or
%     global? If so they may be local variables in the context that the
%     inline is used, and conversion to a procedure would change semantics.
    if log_freevars(varlist, body) then return nil;
% (3) Are any items in varlist used more than once in circumstances where
%     the corresponding actual argument is something other than a simple
%     variable or constant? If so there is a risk of wasted multiple
%     evaluation -- or if the actual parameter involves side-effects even
%     worse.
% (4) [I am not at all certain how well I can check this!]. I want to
%     detect cases where it is important that the substituted argument
%     gets evaluated just and only where shown in the inline. Current thoughts
%     are (4.1) to detect cases where an argument is only used in a context
%     where its value is ignored, as in "inline procedure f u; << A ; u; B>>;"
%     and (4.2) to detect cases where an argument is used within a branch
%     of a conditional. Note that if I have already filtered on (3) this means
%     that the single use is conditional.
  end;

symbolic procedure log_assignment(varlist, u);
  if atom u or eqcar(u, 'quote) or eqcar(u, 'function) then nil
  else if eqcar(u, 'setq) then <<
    if member(cadr u, varlist) then <<
      if not zerop posn() then terpri();
      prin2 "+++ Assignment to parameter of inline: ";
      print u;
      prin2 "+++ Macro was: ";
      print inlineinfo;
      t>>
    else log_assignment(varlist, caddr u) >>
  else if eqcar(u, 'cond) then log_assignment_list_list(varlist, cdr u)
  else log_assignment_list(varlist, u);

symbolic procedure log_assignment_list_list(varlist, u);
  if atom u then nil
  else if log_assignment_list(varlist, car u) then t
  else log_assignment_list_list(varlist, cdr u);

symbolic procedure log_assignment_list(varlist, u);
  if atom u then nil
  else if log_assignment(varlist, car u) then t
  else log_assignment_list(varlist, cdr u);

symbolic procedure log_freevars(varlist, u);
  if atom u then <<
% Note that in PSL at least NIL and T are not tagged as either fluid
% or global - they are special cases! Well it seems that they have a
% property 'constant!? that is true that marke them. I will still check for
% t and nil specially as well.
    if not idp u or member(u, varlist) or
       globalp u or fluidp u or
       get(u, 'constant!?) or
       u = nil or u = t then nil
    else <<
      if not zerop posn() then terpri();
      prin2 "+++ Use of free variable in smacro/inline body: ";
      print u;
      prin2 "+++ Macro was: ";
      print inlineinfo;
      t >> >>
  else if eqcar(u, 'quote) or
    (eqcar(u, 'function) and atom cadr u) or
    eqcar(u, 'go) then nil
  else if eqcar(u, 'prog) then
    log_freevars_list(append(cadr u, varlist), cdr u, t)
  else if eqcar(u, 'lambda) then
    log_freevars_list(append(cadr u, varlist), cdr u, nil)
  else if eqcar(u, 'cond) then log_freevars_list_list(varlist, cdr u)
  else if atom car u then log_freevars_list(varlist, cdr u, nil)
  else log_freevars_list(varlist, u, nil);

symbolic procedure log_freevars_list_list(varlist, u);
  if atom u then nil
  else if log_freevars_list(varlist, car u, nil) then t
  else log_freevars_list_list(varlist, cdr u);

symbolic procedure log_freevars_list(varlist, u, isprog);
  if atom u then nil
  else if isprog and atom car u then log_freevars_list(varlist, cdr u, t)
  else if log_freevars(varlist, car u) then t
  else log_freevars_list(varlist, cdr u, isprog);

symbolic procedure no!-side!-effectp u;
   if atom u then numberp u or (idp u and not(fluidp u or globalp u))
    else if car u = 'quote then t
    else if flagp(car u,'nosideeffects)
     then no!-side!-effect!-listp cdr u
    else nil;

symbolic procedure no!-side!-effect!-listp u;
   null u or no!-side!-effectp car u and no!-side!-effect!-listp cdr u;

% This list USED to have CONS in it, which would grant expansion of
% inlines the right to duplicate expressions with CONS in them - and
% firstly that would waste memory, and (worse) it causes bugs when
% in the presence of RPLACA and RPLACD.  (ACN, Sept 2010)

flag('(car cdr
       caar cadr cdar cddr
% The expansion code is willing to duplicate expressions that use things
% flagged as side-effect free. I am not certain whether the following
% are sensible to duplicate calls of...
       caaar caadr cadar caddr cdaar cdadr cddar cdddr
       ),'nosideeffects);

% Here are some more things that do not have side effects.

flag('(not null atom eq numberp fixp floatp eqcar),'nosideeffects);

symbolic procedure one!-entryp(u,v);
   % determines if id U occurs less than twice in V.
   if atom v then t
    else if smemq(u,car v)
     then if smemq(u,cdr v) then nil else one!-entryp(u,car v)
    else one!-entryp(u,cdr v);

symbolic procedure one!-entry!-listp(u,v);
   null u or one!-entryp(car u,v) and one!-entry!-listp(cdr u,v);

symbolic procedure delasc(u,v);
  begin scalar w;
     while v do
      <<if atom car v or u neq caar v then w := car v . w; v := cdr v>>;
     return reversip w
  end;

% I have updated subla!-q to let it cope better with nested scoped. At
% present I have not allowed for name clashed between parameters and the
% names of PROG labels,

symbolic procedure subla!-q(u,v);
% u is an association list of substitutions, as in
%     ((name1 . value1) (name2 . value2) ...)
% and v is a bit of Lisp code. Perform the substitutions throughout
% the code, but NOT within quoted items (QUOTE literal) and NOT in
% a manner that messes up embedded bindings. This latter is
% an enhancement to the code as of September 2010 to resolve issues
% that arose when trying to use many more inlines then before.
   begin scalar x;
        if null u or null v then return v
         else if atom v
                 then return if x:= atsoc(v,u) then cdr x else v
         else if car v = 'quote or car v = 'go then return v
         else if (eqcar(v, 'lambda) or eqcar(v, 'prog)) and
                 not atom cdr v then <<
            x := cadr v;  % (LAMBDA x . body) or (PROG x . body)
% Now the key line - discard the bindings that get hidden.
% Right now there is a residual bug in that labels in a PROG are subject
% to substitution when they should not be! I will worry about that at some
% later stage - maybe.
            for each xx in x do u := delasc(xx, u);
            x := (subla!-q(u,car v) . subla!-q(u,cdr v));
            return x >>
         else return (subla!-q(u,car v) . subla!-q(u,cdr v))
   end;


put('inline,'macrofn,'applsmacro);
put('smacro,'macrofn,'applsmacro);

%
% Now I would rather like to retire smacros completely because of the
% delicacies documented above. But one use for them is to provide constructors
% and accessors for data-structures. A special challange there is that "form"
% process inlines that are seen on the left hand side of assignments. Thus
% if I ever replace inlines with simple functions (even ones that an optimising
% compiler can in-line) I need to do something more about that.
%
% So here I propose syntax that describes new data types. I will illustrate
% it with how it will be used to define the shape of polynomials in the
% file poly/poly.red
%
%    accessors lc . red;
%    accessors (lpow . lc) . !_;
%    accessors ((mvar . ldeg) . !_) . !_;
%    accessors tpow . tc, (tvar . tdeg) . !_;
%    accessors numr . denr;
%
% BEWARE. I have written "!_" here for a plain unadorned underscore even
% though mostly in Reduce you can just write "_". However excalc makes a
% new token "_|" for innerprod and after that an underscore not followed
% by a vertical bar seems to cause a crash in rlisp/tok.red:scan!
%
% The constructors need to be written out by hand as in
%    inline procedure u .+ v; u . v;
% if only because although they deliver cons cells they may do more than that
% (eg at one stage at least it was arranged that powers were stored uniquely).
% The underscore is used for fields that are not to be named. Note that
% several sets of accessors can be defined on one line.
%
% The effect of such a definition will be illustrated here by looking at
% what "accessors (tvar . tdeg) . !_;" corresponds to:
%   << inline procedure tvar u; caar u;
%      inline procedure tdeg u; cdar u;
%      inline procedure set_tvar(u, v); setcar(car u, v);
%      inline procedure set_tdeg(u, v); setcdr(car u, v);
%      put('tvar, 'setqfn, '(lambda (u b) (setcar (car u) v)));
%      put('tdeg, 'setqfn, '(lambda (u b) (setcdr (car u) v))) >>;
% and if !*noinlines is true then the "inline procedure" becomes "symbolic
% procedure" instead. The provision of explicit setter functions is because
% I then wish to consider replacing any "tvar u := v;" with "set_tvar(u, v);"
% which avoids needing having the setqfn information loaded at parse time.
% When (and if) that is ever completed then the 'setqfn stuff can go away.

% I wish to optimise (eg) "car cdr car x" into "cadar x" and this code
% achieves that for me.

symbolic procedure makecarcdr(path, x);
  if null path then x
  else if null cdr path then list(car path, x)
  else if null cddr path then list(
    cdr assoc(car path . cadr path,
             '(((car . car) . caar)
               ((car . cdr) . cadr)
               ((cdr . car) . cdar)
               ((cdr . cdr) . cddr))), x)
  else list(
    cdr assoc(car path . cadr path . caddr path,
             '(((car car . car) . caaar)
               ((car car . cdr) . caadr)
               ((car cdr . car) . cadar)
               ((car cdr . cdr) . caddr)
               ((cdr car . car) . cdaar)
               ((cdr car . cdr) . cdadr)
               ((cdr cdr . car) . cddar)
               ((cdr cdr . cdr) . cdddr))),
    makecarcdr(cdddr path, x));

put('car, 'mutator, 'setcar);
put('cdr, 'mutator, 'setcdr);

symbolic procedure expand_accessor(u, path, r);
  if u = '!_ then r
  else if eqcar(u, 'cons) then
    expand_accessor(cadr u, 'car . path,
      expand_accessor(caddr u, 'cdr . path, r))
  else if u = nil or not idp u then typerr(u, "illegal as accessor")
  else <<
    r := list('put, mkquote u, ''number!-of!-args, 1) . r;
    if not !*noinlines then
	begin scalar p;
       p := list('putc, mkquote u, ''inline,
                 mkquote list('lambda, '(u), makecarcdr(path, 'u)));
	   if !*defn then eval p;
	   r := p . r
	end
    else <<
       r := list('de, u, '(u), makecarcdr(path, 'u)) . r;
       r := list('put, mkquote u, ''setqfn,
          mkquote list('lambda, '(u v),
                         list(get(car path, 'mutator),
                              makecarcdr(cdr path, 'u),
                              'v))) . r >>;
    u := intern list2string append('(s e t !_), explode2 u);
    r := list('put, mkquote u, ''number!-of!-args, 2) . r;
    if not !*noinlines then
	begin scalar p;
       p := list('putc, mkquote u, ''inline,
          	 	 mkquote list('lambda, '(u v),
                         list(get(car path, 'mutator),
                              makecarcdr(cdr path, 'u),
                              'v)));
	   if !*defn then eval p;
	   r := p . r
	end
    else r := list('de, u, '(u v),
                   list(get(car path, 'mutator),
                        makecarcdr(cdr path, 'u),
                        'v)) . r;
    r >>;

flag('(putc), 'eval);

symbolic macro procedure accessors u;
  begin
    scalar r;
    u := eval cadr u;
% u will now be a list of forms representing the structure and with
% explicit "cons" operators, as in
%     (   (cons (cons tvar tdeg) _)    )
    for each c in u do r := expand_accessor(c, nil, r);
    return 'progn . append(reverse r, '(nil));
  end;

put('accessors, 'stat, 'rlis);

endmodule;

end;
