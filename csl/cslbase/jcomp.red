% "jcomp.red"                 Copyright 1991-2016,  Codemist
%
% Compiler that turns Lisp code into Java in a way that fits in
% with the conventions used with Jlisp
%
%                                                        A C Norman
%

% This starts off as a mere copy of ccomp.red but will be migrated to
% generate Java over time.

%%
%% Copyright (C) 2016, following the master REDUCE source files.          *
%%                                                                        *
%% Redistribution and use in source and binary forms, with or without     *
%% modification, are permitted provided that the following conditions are *
%% met:                                                                   *
%%                                                                        *
%%     * Redistributions of source code must retain the relevant          *
%%       copyright notice, this list of conditions and the following      *
%%       disclaimer.                                                      *
%%     * Redistributions in binary form must reproduce the above          *
%%       copyright notice, this list of conditions and the following      *
%%       disclaimer in the documentation and/or other materials provided  *
%%       with the distribution.                                           *
%%                                                                        *
%% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
%% "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
%% LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
%% FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
%% COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
%% INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
%% BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
%% OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
%% ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
%% TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
%% THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
%% DAMAGE.                                                                *
%%

% $Id$

symbolic;

global '(!*fastvector !*unsafecar);
flag('(fastvector unsafecar), 'switch);

%
% I start with some utility functions that provide something
% related to a FORMAT or PRINTF facility
%

fluid '(J_file L_file O_file L_contents Setup_name File_name);

symbolic macro procedure j!:printf(u,!&optional,env);
% inspired by the C printf function, but much less general.
% This macro is to provide the illusion that printf can take an
% arbitrary number of arguments.
  list('j!:printf1, cadr u, 'list . cddr u);

symbolic procedure j!:printf1(fmt, args);
% this is the inner works of print formatting.
% the special sequences that can occur in format strings are
%               %s       use princ (to print a name?)
%               %d       use princ (to print a number?)
%               %a       use prin
%               %c       as prin, but do not generate the sequence
%                        "*/" as part of the output (!)
%               %t       do a ttab()
%               %<       ensure at least 2 free chars on line
%               %v       print a variable.... magic for this compiler
%               \n       do a terpri()
%               \q       princ '!" to display quote marks
  begin
    scalar a, c;
    fmt := explode2 fmt;
    while fmt do <<
      c := car fmt;
      fmt := cdr fmt;
      if c = '!\ and (car fmt = '!n or car fmt = '!N) then <<
         terpri();
         fmt := cdr fmt >>
      else if c = '!\ and (car fmt = '!q or car fmt = '!Q) then <<
         princ '!";
         fmt := cdr fmt >>
      else if c = '!% then <<
         c := car fmt;
         if null args then a := 'missing_arg
         else a := car args;
         if c = '!v or c = '!V then
            if flagp(a, 'j!:live_across_call) then <<
               princ "stack[";
               princ(-get(a, 'j!:location));
               princ "]" >>
            else princ a
         else if c = '!c or c = '!C then j!:safeprin a
         else if c = '!a or c = '!A then prin a
         else if c = '!t or c = '!T then ttab a
         else if c = '!< then <<
            args := nil . args; % dummy so in effect no arg is used.
            if posn() > 70 then terpri() >>
         else princ a;
         if args then args := cdr args;
         fmt := cdr fmt >>
      else princ c >>
  end;

% The following yukky code is for use in displaying C comments. I want to be
% able to annotate my code as in
%     ... /* load the literal "something" */
% where the literal is displayed. But if the literal were to be a string
% with the character sequence "*/" within it I would get into trouble...

symbolic procedure j!:safeprin x;
  begin
    scalar a, b;
    a := explode x;
    while a do <<
       if eqcar(a, '!/) and b then princ " ";
       princ car a;
       b := eqcar(a, '!*);
       a := cdr a >>;
  end;

symbolic procedure j!:valid_fndef(args, body);
   if ('!&optional memq args) or ('!&rest memq args) then nil
   else j!:valid_list body;

symbolic procedure j!:valid_list x;
   if null x then t
   else if atom x then nil
   else if not j!:valid_expr car x then nil
   else j!:valid_list cdr x;

symbolic procedure j!:valid_expr x;
   if atom x then t
   else if not atom car x then <<
      if not j!:valid_list cdr x then nil
      else if not eqcar(car x, 'lambda) then nil
      else if atom cdar x then nil
      else j!:valid_fndef(cadar x, cddar x) >>
   else if not idp car x then nil
   else if eqcar(x, 'quote) then t
   else begin
      scalar h;
      h := get(car x, 'j!:valid);
      if null h then return j!:valid_list cdr x;
      return funcall(h, cdr x)
   end;

% This establishes a default handler for each special form so that
% any that I forget to treat more directly will cause a tidy error
% if found in compiled code.

symbolic procedure j!:cspecform(x, env);
   error(0, list("special form", x));

symbolic procedure j!:valid_specform x;
   nil;

<< put('and,                    'j!:code, function j!:cspecform);
!#if common!-lisp!-mode
   put('block,                  'j!:code, function j!:cspecform);
!#endif
   put('catch,                  'j!:code, function j!:cspecform);
   put('compiler!-let,          'j!:code, function j!:cspecform);
   put('cond,                   'j!:code, function j!:cspecform);
   put('declare,                'j!:code, function j!:cspecform);
   put('de,                     'j!:code, function j!:cspecform);
!#if common!-lisp!-mode
   put('defun,                  'j!:code, function j!:cspecform);
!#endif
   put('eval!-when,             'j!:code, function j!:cspecform);
   put('flet,                   'j!:code, function j!:cspecform);
   put('function,               'j!:code, function j!:cspecform);
   put('go,                     'j!:code, function j!:cspecform);
   put('if,                     'j!:code, function j!:cspecform);
   put('labels,                 'j!:code, function j!:cspecform);
!#if common!-lisp!-mode
   put('let,                    'j!:code, function j!:cspecform);
!#else
   put('!~let,                  'j!:code, function j!:cspecform);
!#endif
   put('let!*,                  'j!:code, function j!:cspecform);
   put('list,                   'j!:code, function j!:cspecform);
   put('list!*,                 'j!:code, function j!:cspecform);
   put('macrolet,               'j!:code, function j!:cspecform);
   put('multiple!-value!-call,  'j!:code, function j!:cspecform);
   put('multiple!-value!-prog1, 'j!:code, function j!:cspecform);
   put('or,                     'j!:code, function j!:cspecform);
   put('prog,                   'j!:code, function j!:cspecform);
   put('prog!*,                 'j!:code, function j!:cspecform);
   put('prog1,                  'j!:code, function j!:cspecform);
   put('prog2,                  'j!:code, function j!:cspecform);
   put('progn,                  'j!:code, function j!:cspecform);
   put('progv,                  'j!:code, function j!:cspecform);
   put('quote,                  'j!:code, function j!:cspecform);
   put('return,                 'j!:code, function j!:cspecform);
   put('return!-from,           'j!:code, function j!:cspecform);
   put('setq,                   'j!:code, function j!:cspecform);
   put('tagbody,                'j!:code, function j!:cspecform);
   put('the,                    'j!:code, function j!:cspecform);
   put('throw,                  'j!:code, function j!:cspecform);
   put('unless,                 'j!:code, function j!:cspecform);
   put('unwind!-protect,        'j!:code, function j!:cspecform);
   put('when,                   'j!:code, function j!:cspecform) ;

% I comment out lines here when (a) the special form involved is
% supported by my compilation into C and (b) its syntax is such that
% I can analyse it as if it was an ordinary function. Eg (AND a b c)
%
% Cases like PROG are left in because the syntax (PROG (v1 v2) ...) needs
% special treatment.
%
% Cases like UNWIND-PROTECT are left in because at the time of writing this
% comment they are not supported.


%  put('and,                    'j!:valid, function j!:valid_specform);
!#if common!-lisp!-mode
%  put('block,                  'j!:valid, function j!:valid_specform);
!#endif
   put('catch,                  'j!:valid, function j!:valid_specform);
   put('compiler!-let,          'j!:valid, function j!:valid_specform);
   put('cond,                   'j!:valid, function j!:valid_specform);
   put('declare,                'j!:valid, function j!:valid_specform);
   put('de,                     'j!:valid, function j!:valid_specform);
!#if common!-lisp!-mode
   put('defun,                  'j!:valid, function j!:valid_specform);
!#endif
   put('eval!-when,             'j!:valid, function j!:valid_specform);
   put('flet,                   'j!:valid, function j!:valid_specform);
   put('function,               'j!:valid, function j!:valid_specform);
%  put('go,                     'j!:valid, function j!:valid_specform);
%  put('if,                     'j!:valid, function j!:valid_specform);
   put('labels,                 'j!:valid, function j!:valid_specform);
!#if common!-lisp!-mode
   put('let,                    'j!:valid, function j!:valid_specform);
!#else
   put('!~let,                  'j!:valid, function j!:valid_specform);
!#endif
   put('let!*,                  'j!:valid, function j!:valid_specform);
%  put('list,                   'j!:valid, function j!:valid_specform);
%  put('list!*,                 'j!:valid, function j!:valid_specform);
   put('macrolet,               'j!:valid, function j!:valid_specform);
   put('multiple!-value!-call,  'j!:valid, function j!:valid_specform);
   put('multiple!-value!-prog1, 'j!:valid, function j!:valid_specform);
%  put('or,                     'j!:valid, function j!:valid_specform);
   put('prog,                   'j!:valid, function j!:valid_specform);
   put('prog!*,                 'j!:valid, function j!:valid_specform);
%  put('prog1,                  'j!:valid, function j!:valid_specform);
%  put('prog2,                  'j!:valid, function j!:valid_specform);
%  put('progn,                  'j!:valid, function j!:valid_specform);
   put('progv,                  'j!:valid, function j!:valid_specform);
   put('quote,                  'j!:valid, function j!:valid_specform);
%  put('return,                 'j!:valid, function j!:valid_specform);
%  put('return!-from,           'j!:valid, function j!:valid_specform);
%  put('setq,                   'j!:valid, function j!:valid_specform);
%  put('tagbody,                'j!:valid, function j!:valid_specform);
   put('the,                    'j!:valid, function j!:valid_specform);
   put('throw,                  'j!:valid, function j!:valid_specform);
%  put('unless,                 'j!:valid, function j!:valid_specform);
   put('unwind!-protect,        'j!:valid, function j!:valid_specform);
%  put('when,                   'j!:valid, function j!:valid_specform) 
   >>;

fluid '(j!:current_procedure j!:current_args j!:current_block j!:current_contents
        j!:all_blocks j!:registers j!:stacklocs);

fluid '(j!:available j!:used);

j!:available := j!:used := nil;

symbolic procedure j!:reset_gensyms();
 << remflag(j!:used, 'j!:live_across_call);
    remflag(j!:used, 'j!:visited);
    while j!:used do <<
      remprop(car j!:used, 'j!:contents);
      remprop(car j!:used, 'j!:why);
      remprop(car j!:used, 'j!:where_to);
      remprop(car j!:used, 'j!:count);
      remprop(car j!:used, 'j!:live);
      remprop(car j!:used, 'j!:clash);
      remprop(car j!:used, 'j!:chosen);
      remprop(car j!:used, 'j!:location);
      if plist car j!:used then begin
         scalar o; o := wrs nil;
         princ "+++++ "; prin car j!:used; princ " ";
         prin plist car j!:used; terpri();
         wrs o end;
      j!:available := car j!:used . j!:available;
      j!:used := cdr j!:used >> >>;

!#if common!-lisp!-mode

fluid '(my_gensym_counter);
my_gensym_counter := 0;

!#endif

symbolic procedure j!:my_gensym();
  begin
    scalar w;
    if j!:available then << w := car j!:available; j!:available := cdr j!:available >>
!#if common!-lisp!-mode
    else w := compress1
       ('!v . explodec (my_gensym_counter := my_gensym_counter + 1));
!#else
    else w := gensym1 "v";
!#endif
    j!:used := w . j!:used;
    if plist w then << princ "????? "; prin w; princ " => "; prin plist w; terpri() >>;
    return w
  end;

symbolic procedure j!:newreg();
  begin
    scalar r;
    r := j!:my_gensym();
    j!:registers := r . j!:registers;
    return r
  end;

symbolic procedure j!:startblock s;
 << j!:current_block := s;
    j!:current_contents := nil
 >>;

symbolic procedure j!:outop(a,b,c,d);
  if j!:current_block then
     j!:current_contents := list(a,b,c,d) . j!:current_contents;

symbolic procedure j!:endblock(why, where_to);
  if j!:current_block then <<
% Note that the operations within a block are in reversed order.
    put(j!:current_block, 'j!:contents, j!:current_contents);
    put(j!:current_block, 'j!:why, why);
    put(j!:current_block, 'j!:where_to, where_to);
    j!:all_blocks := j!:current_block . j!:all_blocks;
    j!:current_contents := nil;
    j!:current_block := nil >>;

%
% Now for a general driver for compilation
%

symbolic procedure j!:cval_inner(x, env);
  begin
    scalar helper;
% NB use the "improve" function from the regular compiler here...
    x := s!:improve x;
% atoms and embedded lambda expressions need their own treatment.
    if atom x then return j!:catom(x, env)
    else if eqcar(car x, 'lambda) then
       return j!:clambda(cadar x, cddar x, cdr x, env)
% a j!:code property gives direct control over compilation
    else if helper := get(car x, 'j!:code) then
       return funcall(helper, x, env)
% compiler-macros take precedence over regular macros, so that I can
% make special expansions in the context of compilation. Only used if the
% expansion is non-nil
    else if (helper := get(car x, 'j!:compile_macro)) and
            (helper := funcall(helper, x)) then
       return j!:cval(helper, env)
% regular Lisp macros get expanded
    else if idp car x and (helper := macro!-function car x) then
       return j!:cval(funcall(helper, x), env)
% anything not recognised as special will be turned into a
% function call, but there will still be special cases, such as
% calls to the current function, calls into the C-coded kernel, etc.
    else return j!:ccall(car x, cdr x, env)
  end;

symbolic procedure j!:cval(x, env);
  begin
     scalar r;
     r := j!:cval_inner(x, env);
     if r and not member!*!*(r, j!:registers) then
        error(0, list(r, "not a register", x));
     return r
  end;

symbolic procedure j!:clambda(bvl, body, args, env);
% This is for ((lambda bvl body) args) and it will need to deal with
% local declarations at the head of body. On this call body is a list of
% forms.
  begin
    scalar w, w1, fluids, env1, decs;
    env1 := car env;
    w := for each a in args collect j!:cval(a, env);
    w1 := s!:find_local_decs(body, nil);
    localdecs := car w1 . localdecs;
    w1 := cdr w1;
% Tidy up so that body is a single expression.
    if null w1 then body := nil
    else if null cdr w1 then body := car w1
    else body := 'progn . w1;
    for each x in bvl do
       if not fluidp x and not globalp x and
          j!:local_fluidp(x, localdecs) then <<
          make!-special x;
          decs := x . decs >>;
    for each v in bvl do <<
       if globalp v then begin scalar oo;
           oo := wrs nil;
           princ "+++++ "; prin v;
           princ " converted from GLOBAL to FLUID"; terpri();
           wrs oo;
           unglobal list v;
           fluid list v end;
       if fluidp v then <<
          fluids := (v . j!:newreg()) . fluids;
          flag(list cdar fluids, 'j!:live_across_call); % silly if not
          env1 := ('j!:dummy!:name . cdar fluids) . env1;
          j!:outop('ldrglob, cdar fluids, v, j!:find_literal v);
          j!:outop('strglob, car w, v, j!:find_literal v) >>
       else <<
          env1 := (v . j!:newreg()) . env1;
          j!:outop('movr, cdar env1, nil, car w) >>;
       w := cdr w >>;
    if fluids then j!:outop('fluidbind, nil, nil, fluids);
    env := env1 . append(fluids, cdr env);
    w := j!:cval(body, env);
    for each v in fluids do
       j!:outop('strglob, cdr v, car v, j!:find_literal car v);
    unfluid decs;
    localdecs := cdr localdecs;
    return w
  end;

symbolic procedure j!:locally_bound(x, env);
   atsoc(x, car env);

flag('(nil t), 'j!:constant);

fluid '(literal_vector);

symbolic procedure j!:find_literal x;
  begin
    scalar n, w;
    w := literal_vector;
    n := 0;
    while w and not (car w = x) do <<
      n := n + 1;
      w := cdr w >>;
    if null w then literal_vector := append(literal_vector, list x);
    return n
  end;

symbolic procedure j!:catom(x, env);
  begin
    scalar v, w;
    v := j!:newreg();
% I may need to think harder here about things that are both locally
% bound AND fluid. But when I bind a fluid I put a dummy name onto env
% and use that as a place to save the old value of the fluid, so I believe
% I may be safe. Well not quite I guess. How about
%     (prog (a)                              % a local variable
%        (prog (a) (declare (special a))  % hah this one os fluid!
%              reference "a" here...
% and related messes. So note that the outer binding means that a is
% locally bound but the inner binding means that a fluid binding must
% be used.
    if idp x and (fluidp x or globalp x) then
        j!:outop('ldrglob, v, x, j!:find_literal x)
    else if idp x and (w := j!:locally_bound(x, env)) then
       j!:outop('movr, v, nil, cdr w)
    else if null x or x = 't or j!:small_number x then
       j!:outop('movk1, v, nil, x)
    else if not idp x or flagp(x, 'j!:constant) then
       j!:outop('movk, v, x, j!:find_literal x)
% If a variable that is referenced is not locally bound then it is treated
% as being fluid/global without comment.
    else j!:outop('ldrglob, v, x, j!:find_literal x);
    return v
  end;

symbolic procedure j!:cjumpif(x, env, d1, d2);
  begin
    scalar helper, r;
    x := s!:improve x;
    if atom x and (not idp x or
         (flagp(x, 'j!:constant) and not j!:locally_bound(x, env))) then
       j!:endblock('goto, list (if x then d1 else d2))
    else if not atom x and (helper := get(car x, 'j!:ctest)) then
       return funcall(helper, x, env, d1, d2)
    else <<
       r := j!:cval(x, env);
       j!:endblock(list('ifnull, r), list(d2, d1)) >>
  end;

fluid '(j!:current);

symbolic procedure j!:ccall(fn, args, env);
  j!:ccall1(fn, args, env);

fluid '(j!:visited);

symbolic procedure j!:has_calls(a, b);
  begin
    scalar j!:visited;
    return j!:has_calls_1(a, b)
  end;

symbolic procedure j!:has_calls_1(a, b);
% true if there is a path from node a to node b that has a call instruction
% on the way.
  if a = b or not atom a or memq(a, j!:visited) then nil
  else begin
    scalar has_call;
    j!:visited := a . j!:visited;
    for each z in get(a, 'j!:contents) do
       if eqcar(z, 'call) then has_call := t;
    if has_call then return
       begin scalar j!:visited;
       return j!:can_reach(a, b) end;
    for each d in get(a, 'j!:where_to) do
       if j!:has_calls_1(d, b) then has_call := t;
    return has_call
  end;

symbolic procedure j!:can_reach(a, b);
  if a = b then t
  else if not atom a or memq(a, j!:visited) then nil
  else <<
    j!:visited := a . j!:visited;
    j!:any_can_reach(get(a, 'j!:where_to), b) >>;

symbolic procedure j!:any_can_reach(l, b);
  if null l then nil
  else if j!:can_reach(car l, b) then t
  else j!:any_can_reach(cdr l, b);
    
symbolic procedure j!:pareval(args, env);
  begin
    scalar tasks, tasks1, merge, split, r;
    tasks := for each a in args collect (j!:my_gensym() . j!:my_gensym());
    split := j!:my_gensym();
    j!:endblock('goto, list split);
    for each a in args do begin
      scalar s;
% I evaluate each arg as what is (at this stage) a separate task
      s := car tasks;
      tasks := cdr tasks;
      j!:startblock car s;
      r := j!:cval(a, env) . r;
      j!:endblock('goto, list cdr s);
% If the task did no procedure calls (or only tail calls) then it can be
% executed sequentially with the other args without need for stacking
% anything.  Otherwise it more care will be needed.  Put the hard
% cases onto tasks1.
!#if common!-lisp!-mode
      tasks1 := s . tasks1
!#else
% The "t or" here is to try to FORCE left to right evaluation, even though
% doing so may hurt performance. It at present looks as if some parts
% of REDUCE have been coded making assumptions about this.
      if t or j!:has_calls(car s, cdr s) then tasks1 := s . tasks1
      else merge := s . merge
!#endif
    end;
%-- % if there are zero or one items in tasks1 then again it is easy -
%-- % otherwise I flag the problem with a notionally parallel construction.
%--     if tasks1 then <<
%--        if null cdr tasks1 then merge := car tasks1 . merge
%--        else <<
%--           j!:startblock split;
%--           printc "***** ParEval needed parallel block here...";
%--           j!:endblock('par, for each v in tasks1 collect car v);
%--           split := j!:my_gensym();
%--           for each v in tasks1 do <<
%--              j!:startblock cdr v;
%--              j!:endblock('goto, list split) >> >> >>;
    for each z in tasks1 do merge := z . merge; % do sequentially
%--
%--
% Finally string end-to-end all the bits of sequential code I have left over.
    for each v in merge do <<
      j!:startblock split;
      j!:endblock('goto, list car v);
      split := cdr v >>;
    j!:startblock split;
    return reversip r
  end;

symbolic procedure j!:ccall1(fn, args, env);
  begin
    scalar tasks, merge, r, val;
    fn := list(fn, cdr env);
    val := j!:newreg();
    if null args then j!:outop('call, val, nil, fn)
    else if null cdr args then
      j!:outop('call, val, list j!:cval(car args, env), fn)
    else <<
      r := j!:pareval(args, env);
      j!:outop('call, val, r, fn) >>;
    j!:outop('reloadenv, 'env, nil, nil);
    return val
  end;
      
fluid '(restart_label reloadenv does_call j!:current_c_name);

% Reminder: s!:find_local_decs(body, isprog) returns (L . B') where
% L is a list of local declarations and B' is the body with any
% initial DECLARE and string-comments removed. The body passed in and
% the result returned are both lists of forms.


symbolic procedure j!:local_fluidp1(v, decs);
  decs and ((eqcar(car decs, 'special) and memq(v, cdar decs)) or
            j!:local_fluidp1(v, cdr decs));

symbolic procedure j!:local_fluidp(v, decs);
  decs and (j!:local_fluidp1(v, car decs) or
            j!:local_fluidp(v, cdr decs));

%
% The "proper" recipe here arranges that functions that expect over 2 args use
% the "va_arg" mechanism to pick up ALL their args.  This would be pretty
% heavy-handed, and at least on a lot of machines it does not seem to
% be necessary.  I will duck it for a while more at least. BUT NOTE THAT THE
% CODE I GENERATE HERE IS AT LEAST OFFICIALLY INCORRECT. If at some stage I
% find a computer where the implementation of va_args is truly incompatible
% with that for known numbers of arguments I will need to adjust things
% here. Yuk.
%
% Just so I know, the code at presently generated tends to go
%
%  Lisp_Object f(Lisp_Object env, int nargs, Lisp_Object a1, Lisp_Object a2,
%                Lisp_Object a3, ...)
%  { // use a1, a2 and a3 as arguments
% and note that it does put the "..." there!
%
% What it maybe ought to be is
%
%  Lisp_Object f(Lisp_Object env, int nargs, ...)
%  {   Lisp_Object a1, a2, a3;
%      va_list aa;
%      va_start(aa, nargs);
%      argcheck(nargs, 3, "f");
%      a1 = va_arg(aa, Lisp_Object);
%      a2 = va_arg(aa, Lisp_Object);
%      a3 = va_arg(aa, Lisp_Object);
%     va_end(aa);
%
% Hmm that is not actually that hard to arrange! Remind me to do it some time!

fluid '(proglabs blockstack localdecs);

symbolic procedure j!:cfndef(j!:current_procedure,
                             j!:current_c_name, argsbody, checksum);
  begin
    scalar env, n, w, j!:current_args, j!:current_block, restart_label,
           j!:current_contents, j!:all_blocks, entrypoint, exitpoint, args1,
           j!:registers, j!:stacklocs, literal_vector, reloadenv, does_call,
           blockstack, proglabs, args, body, localdecs;
    args := car argsbody;
    body := cdr argsbody;
% If there is a (DECLARE (SPECIAL ...)) extract it here, aned leave a body
% that is without it.
    w := s!:find_local_decs(body, nil);
    body := cdr w;
    if atom body then body := nil
    else if atom cdr body then body := car body
    else body := 'progn . body;
    localdecs := list car w;
% I expect localdecs to be a list a bit like
%  ( ((special a b) (special c d) ...) ...)
% and hypothetically it could have entries that were not tagged as
% SPECIAL in it.
%
% The next line prints it to check.
%   if localdecs then << princ "localdecs = "; print localdecs >>; % @@@
%
% Normally comment out the next line... It just shows what I am having to
% compile and may be useful when debugging.
%   print list(j!:current_procedure, j!:current_c_name, args, body);
    j!:reset_gensyms();
    wrs J_file;
    linelength 200;
    j!:printf("\n\n/* Code for %a %<*/\n\n", j!:current_procedure);

    j!:find_literal j!:current_procedure; % For benefit of backtraces
%
% cope with fluid vars in an argument list by expanding the definition
%    (de f (a B C d) body)     B and C fluid
% into
%    (de f (a x y c) (prog (B C) (setq B x) (setq C y) (return body)))
% so that the fluids get bound by PROG.
%
    j!:current_args := args;
    for each v in args do
       if v = '!&optional or v = '!&rest then
          error(0, "&optional and &rest not supported by this compiler (yet)")
       else if globalp v then begin scalar oo;
          oo := wrs nil;
          princ "+++++ "; prin v;
          princ " converted from GLOBAL to FLUID"; terpri();
          wrs oo;
          unglobal list v;
          fluid list v;
          n := (v . j!:my_gensym()) . n end
       else if fluidp v or j!:local_fluidp(v, localdecs) then
          n := (v . j!:my_gensym()) . n;
    if !*r2i then body := s!:r2i(j!:current_procedure, args, body);
    restart_label := j!:my_gensym();
    body := list('j!:private_tagbody, restart_label, body);
% This bit sets up the PROG block for binding fluid arguments. 
    if n then <<
       body := list list('return, body);
       args := subla(n, args);
       for each v in n do
         body := list('setq, car v, cdr v) . body;
       body := 'prog . (for each v in reverse n collect car v) . body >>;
    j!:printf "static Lisp_Object ";
    if null args or length args >= 3 then j!:printf("MS_CDECL ");
    j!:printf("%s(Lisp_Object env", j!:current_c_name);
    if null args or length args >= 3 then j!:printf(", int nargs");
    n := t;
    env := nil;

% Hah - here is where I will change things to use va_args for >= 3 args.
    for each x in args do begin
       scalar aa;
       j!:printf ",";
       if n then << j!:printf "\n                        "; n := nil >>
       else n := t;
       aa := j!:my_gensym();
       env := (x . aa) . env;
       j!:registers := aa . j!:registers;
       args1 := aa . args1;
       j!:printf(" Lisp_Object %s", aa) end;
    if null args or length args >= 3 then j!:printf(", ...");
    j!:printf(")\n{\n");

% Now I would need to do va_arg calls to declare the args and init them...
% Except that I must do that within optimise_flowgraph after all possible
% declarations have been generated.

    j!:startblock (entrypoint := j!:my_gensym());
    exitpoint := j!:current_block;
    j!:endblock('goto, list list j!:cval(body, env . nil));

    j!:optimise_flowgraph(entrypoint, j!:all_blocks, env,
                        length args . j!:current_procedure, args1);

    j!:printf("}\n\n");
    wrs O_file;

    L_contents := (j!:current_procedure . literal_vector . checksum) .
                  L_contents;
    return nil
  end;

% j!:ccompile1 directs the compilation of a single function, and bind all the
% major fluids used by the compilation process

flag('(rds deflist flag fluid global
       remprop remflag unfluid
       unglobal dm carcheck J!-end), 'eval);

flag('(rds), 'ignore);

fluid '(!*backtrace);

symbolic procedure j!:ccompilesupervisor;
  begin
    scalar u, w;
top:u := errorset('(read), t, !*backtrace);
    if atom u then return;      % failed, or maybe EOF
    u := car u;
    if u = !$eof!$ then return; % end of file
    if atom u then go to top
% the apply('J!-end, nil) is here because J!-end has a "stat"
% property and so it will mis-parse if I just write "J!-end()".  Yuk.
    else if eqcar(u, 'J!-end) then return apply('J!-end, nil)
    else if eqcar(u, 'rdf) then <<
!#if common!-lisp!-mode
       w := open(u := eval cadr u, !:direction, !:input,
                 !:if!-does!-not!-exist, nil);
!#else
       w := open(u := eval cadr u, 'input);
!#endif
       if w then <<
          terpri();
          princ "Reading file "; print u;
          w := rds w;
          j!:ccompilesupervisor();
          princ "End of file "; print u;
          close rds w >>
       else << princ "Failed to open file "; print u >> >>
    else j!:ccmpout1 u;
    go to top
  end;

global '(j!:char_mappings);

j!:char_mappings := '(
  (!  . !A)  (!! . !B)  (!# . !C)  (!$ . !D)
  (!% . !E)  (!^ . !F)  (!& . !G)  (!* . !H)
  (!( . !I)  (!) . !J)  (!- . !K)  (!+ . !L)
  (!= . !M)  (!\ . !N)  (!| . !O)  (!, . !P)
  (!. . !Q)  (!< . !R)  (!> . !S)  (!: . !T)
  (!; . !U)  (!/ . !V)  (!? . !W)  (!~ . !X)
  (!` . !Y));

fluid '(j!:names_so_far);

symbolic procedure j!:inv_name n;
  begin
    scalar r, w;
% The next bit ararnges that if there are several definitions of the
% same function in the same module that they get different C names.
% Specifically they will be called CC_f, CC1_f, CC2_c, CC3_f, ...
    if (w := assoc(n, j!:names_so_far)) then w := cdr w + 1
    else w := 0;
    j!:names_so_far := (n . w) . j!:names_so_far;
    r := '(!C !C !");
    if not zerop w then r := append(reverse explodec w, r);    
    r := '!_ . r;
!#if common!-lisp!-mode
    for each c in explode2 package!-name symbol!-package n do <<
      if c = '_ then r := '_ . r
      else if alpha!-char!-p c or digit c then r := c . r
      else if w := atsoc(c, j!:char_mappings) then r := cdr w . r
      else r := '!Z . r >>;
    r := '!_ . '!_ . r;
!#endif
    for each c in explode2 n do <<
      if c = '_ then r := '_ . r
!#if common!-lisp!-mode
      else if alpha!-char!-p c or digit c then r := c . r
!#else
      else if liter c or digit c then r := c . r
!#endif
      else if w := atsoc(c, j!:char_mappings) then r := cdr w . r
      else r := '!Z . r >>;
    r := '!" . r;
!#if common!-lisp!-mode
    return compress1 reverse r
!#else
    return compress reverse r
!#endif
  end;

fluid '(j!:defnames pending_functions);

symbolic procedure j!:ccmpout1 u;
  begin
    scalar pending_functions;
    pending_functions := list u;
    while pending_functions do <<
       u := car pending_functions;
       pending_functions := cdr pending_functions;
       j!:ccmpout1a u >>
  end;

symbolic procedure j!:ccmpout1a u;
  begin
    scalar w, checksum;
    if atom u then return nil
    else if eqcar(u, 'progn) then <<
       for each v in cdr u do j!:ccmpout1a v;
       return nil >>
    else if eqcar(u, 'J!-end) then nil
    else if flagp(car u, 'eval) or
          (car u = 'setq and not atom caddr u and flagp(caaddr u, 'eval)) then
       errorset(u, t, !*backtrace);
    if eqcar(u, 'rdf) then begin
!#if common!-lisp!-mode
       w := open(u := eval cadr u, !:direction, !:input,
                 !:if!-does!_not!-exist, nil);
!#else
       w := open(u := eval cadr u, 'input);
!#endif
       if w then <<
          princ "Reading file "; print u;
          w := rds w;
          j!:ccompilesupervisor();
          princ "End of file "; print u;
          close rds w >>
       else << princ "Failed to open file "; print u >> end
!#if common!-lisp!-mode
    else if eqcar(u, 'defun) then return j!:ccmpout1a macroexpand u
!#endif
    else if eqcar(u, 'de) then <<
        u := cdr u;
        checksum := md60 u;
!#if common!-lisp!-mode
        w := compress1 ('!" . append(explodec package!-name
                                       symbol!-package car u,
                        '!@ . '!@ . append(explodec symbol!-name car u,
                        append(explodec "@@Builtin", '(!")))));
        w := intern w;
        j!:defnames := list(car u, j!:inv_name car u, length cadr u, w, checksum) . j!:defnames;
!#else
        j!:defnames := list(car u, j!:inv_name car u, length cadr u, checksum) . j!:defnames;
!#endif
%       if posn() neq 0 then terpri();
        princ "Compiling "; prin caar j!:defnames; princ " ... ";
        j!:cfndef(caar j!:defnames, cadar j!:defnames, cdr u, checksum);
!#if common!-lisp!-mode
        L_contents := (w . car L_contents) . cdr L_contents;
!#endif
        terpri() >>
  end;

fluid '(!*defn dfprint!* dfprintsave);

!#if common!-lisp!-mode
symbolic procedure j!:concat(a, b);
   compress1('!" . append(explode2 a, append(explode2 b, '(!"))));
!#else
symbolic procedure j!:concat(a, b);
   compress('!" . append(explode2 a, append(explode2 b, '(!"))));
!#endif

symbolic procedure j!:ccompilestart(name, setupname, dir);
  begin
    scalar o, d, w;
    reset!-gensym 0;   % Makes output more consistent
!#if common!-lisp!-mode
    my_gensym_counter := 0;
!#endif
    j!:registers := j!:available := j!:used := nil;
    File_name := list2string explode2 name; % So name may be string or symbol
    Setup_name := explodec setupname;
% I REALLY want the user to give me a module name that is a valid Java
% identifier, but in REDUCE I find just one case where a name has an embedded
% "-", so I will just map that onto "_". When loading modules I will need to
% take care to be aware of this! Also if any idiot tried to have two modules
% called a-b and a_b they would now clash with one another.
    Setup_name := subst('!_, '!-, Setup_name);
    Setup_name := list2string Setup_name;
    if dir then <<
       if 'win32 memq lispsystem!* then
          name := j!:concat(dir, j!:concat("\", name))
       else name := j!:concat(dir, j!:concat("/", name)) >>;
princ "C file = "; print name;
!#if common!-lisp!-mode
    J_file := open(j!:concat(name, ".java"), !:direction, !:output);
!#else
    J_file := open(j!:concat(name, ".java"), 'output);
!#endif
    L_file := j!:concat(name, ".lsp");
    L_contents := nil;
    j!:names_so_far := nil;
% Here I turn a date into a form like "12-Oct-1993" as expected by the
% file signature mechanism that I use. This seems a pretty ugly process.
    o := reverse explode date!-and!-time();
    for i := 1:5 do << d := car o . d; o := cdr o >>;
    d := '!- . d;
    o := cdddr cdddr cddddr o;
    w := o;
    o := cdddr o;
    d := caddr o . cadr o . car o . d;
!#if common!-lisp!-mode
    d := compress1('!" . cadr w . car w . '!- . d);
!#else
    d := compress('!" . cadr w . car w . '!- . d);
!#endif
    O_file := wrs J_file;
    j!:defnames := nil;
    j!:printf("\n/* %s.java %tMachine generated Java code %<*/\n\n", name, 25);
    print!-init();
    wrs O_file;
    return nil
  end;

symbolic procedure j!:print!-init();
  <<
   j!:printf "\n";
   j!:printf "package uk.co.codemist.jlisp.core;\n";
   j!:printf "\n";
   j!:printf "//\n";
   j!:printf "// This file is part of the Jlisp implementation of Standard Lisp\n";
   j!:printf "// Copyright \u00a9 (C) Codemist, 1998-2016.\n";
   j!:printf "//\n";
   j!:printf "\n";
   j!:printf "/**************************************************************************\n";
   j!:printf " * Copyright (C) 1998-2013, Codemist.                          A C Norman *\n";
   j!:printf " *                            also contributions from Vijay Chauhan, 2002 *\n";
   j!:printf " * Derived from the main Reduce source files, so also rights from there.  *\n";
   j!:printf " *                                                                        *\n";
   j!:printf " * Redistribution and use in source and binary forms, with or without     *\n";
   j!:printf " * modification, are permitted provided that the following conditions are *\n";
   j!:printf " * met:                                                                   *\n";
   j!:printf " *                                                                        *\n";
   j!:printf " *     * Redistributions of source code must retain the relevant          *\n";
   j!:printf " *       copyright notice, this list of conditions and the following      *\n";
   j!:printf " *       disclaimer.                                                      *\n";
   j!:printf " *     * Redistributions in binary form must reproduce the above          *\n";
   j!:printf " *       copyright notice, this list of conditions and the following      *\n";
   j!:printf " *       disclaimer in the documentation and/or other materials provided  *\n";
   j!:printf " *       with the distribution.                                           *\n";
   j!:printf " *                                                                        *\n";
   j!:printf " * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *\n";
   j!:printf " * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *\n";
   j!:printf " * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *\n";
   j!:printf " * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *\n";
   j!:printf " * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *\n";
   j!:printf " * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *\n";
   j!:printf " * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *\n";
   j!:printf " * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *\n";
   j!:printf " * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *\n";
   j!:printf " * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *\n";
   j!:printf " * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *\n";
   j!:printf " * DAMAGE.                                                                *\n";
   j!:printf " *************************************************************************/\n";
   j!:printf "\n";
   j!:printf "// U01.java\n";
   j!:printf "\n";
   j!:printf "// Each built-in function is created wrapped in a class\n";
   j!:printf "// that is derived from BuiltinFunction.\n";
   j!:printf "\n";
   j!:printf "import java.io.*;\n";
   j!:printf "import java.util.*;\n";
   j!:printf "import java.text.*;\n";
   j!:printf "import java.math.BigInteger;\n";
   j!:printf "\n";
   j!:printf "class U01\n";
   j!:printf "{\n";
   j!:printf "    Object [][] builtins = \n";
   j!:printf "    {\n";
   j!:printf "        {\qu01_sample\q,                  new U01_sampleFn()},\n";
   j!:printf "    };\n";
   j!:printf "\n";
   j!:printf "\n";
   j!:printf "class U01_sampleFn extends BuiltinFunction\n";
   j!:printf "{\n";
   j!:printf "    public LispObject op0()\n";
   j!:printf "    {\n";
   j!:printf "        return Jlisp.nil;\n";
   j!:printf "    }\n";
   j!:printf "    public LispObject op1(LispObject arg1)\n";
   j!:printf "    {\n";
   j!:printf "        return arg1;\n";
   j!:printf "    }\n";
   j!:printf "    public LispObject op2(LispObject arg1, LispObject arg2) throws ResourceException\n";
   j!:printf "    {\n";
   j!:printf "        return arg1;\n";
   j!:printf "    }\n";
   j!:printf "    public LispObject opn(LispObject [] args) throws ResourceException\n";
   j!:printf "    {\n";
   j!:printf "        int n = args.length;\n";
   j!:printf "        if (n == 0) return Jlisp.nil;\n";
   j!:printf "        else return args[0];\n";
   j!:printf "    }\n";
   j!:printf "}\n";
   j!:printf "\n"
  >>;

symbolic procedure J!-end;
  J!-end1 t;

procedure J!-end1 create_lfile;
  begin
    scalar checksum, c1, c2, c3;
    wrs J_file;
    if create_lfile then
       j!:printf("\n\nsetup_type const %s_setup[] =\n{\n", Setup_name)
    else j!:printf("\n\nsetup_type_1 const %s_setup[] =\n{\n", Setup_name);
    j!:defnames := reverse j!:defnames;
    while j!:defnames do begin
       scalar name, nargs, f1, f2, cast, fn;
!#if common!-lisp!-mode
       name := cadddr car j!:defnames;
       checksum := cadddr cdar j!:defnames;
!#else
       name := caar j!:defnames;
       checksum := cadddr car j!:defnames;
!#endif
       f1 := cadar j!:defnames;
       nargs := caddar j!:defnames;
       cast := "(n_args *)";
       if nargs = 1 then <<
          f2 := '!t!o!o_!m!a!n!y_1; cast := ""; fn := '!w!r!o!n!g_!n!o_1 >>
       else if nargs = 2 then <<
          f2 := f1; f1 := '!t!o!o_!f!e!w_2; cast := "";
          fn := '!w!r!o!n!g_!n!o_2 >>
       else << fn := f1; f1 := '!w!r!o!n!g_!n!o_!n!a;
               f2 := '!w!r!o!n!g_!n!o_!n!b >>;
       if create_lfile then j!:printf("    {\q%s\q,%t%s,%t%s,%t%s%s},\n",
                                      name, 32, f1, 48, f2, 63, cast, fn)
       else
       begin
          scalar c1, c2;
          c1 := divide(checksum, expt(2, 31));
          c2 := cdr c1;
          c1 := car c1;
          j!:printf("    {\q%s\q, %t%s, %t%s, %t%s%s, %t%s, %t%s},\n",
                    name, 24, f1, 40, f2, 52, cast, fn, 64, c1, 76, c2)
       end;
       j!:defnames := cdr j!:defnames end;
    c3 := checksum := md60 L_contents;
    c1 := remainder(c3, 10000000);
    c3 := c3 / 10000000;
    c2 := remainder(c3, 10000000);
    c3 := c3 / 10000000;
    checksum := list2string append(explodec c3,
                     '!  . append(explodec c2, '!  . explodec c1));
    j!:printf("    {NULL, (one_args *)%a, (two_args *)%a, 0}\n};\n\n",
              Setup_name, checksum);
    j!:printf "%</* end of generated code %<*/\n";
    close J_file;
    if create_lfile then <<
!#if common!-lisp!-mode
       L_file := open(L_file, !:direction, !:output);
!#else
       L_file := open(L_file, 'output);
!#endif
       wrs L_file;
       linelength 72;
       terpri();
!#if common!-lisp!-mode
       princ ";;;  "; 
!#else
       princ "% ";
!#endif
       princ Setup_name;
       princ ".lsp"; ttab 20;
       princ "Machine generated Lisp";
%      princ "  "; princ date();  % I omit the date now because it makes
                                  % file comparisons messier
       terpri(); terpri();
!#if common!-lisp!-mode
       princ "(in-package lisp)"; terpri(); terpri();
       princ "(c::install ";
!#else
       princ "(j!:install ";
!#endif
       princ '!"; princ Setup_name; princ '!";
       princ " "; princ checksum; printc ")";
       terpri();
       for each x in reverse L_contents do <<
!#if common!-lisp!-mode
          princ "(c::install '";
          prin car x;
          princ " '";
          x := cdr x;
!#else
          princ "(j!:install '";
!#endif
          prin car x;
          princ " '";
          prin cadr x;
!#if (not common!-lisp!-mode)
          princ " ";
          prin cddr x;
!#endif
          princ ")";
          terpri(); terpri() >>;
       terpri();
!#if common!-lisp!-mode
       princ ";;; End of generated Lisp code";
!#else
       princ "% End of generated Lisp code";
!#endif
       terpri(); terpri();
       L_contents := nil;
       wrs O_file;
       close L_file;
       !*defn := nil;
       dfprint!* := dfprintsave >>
    else <<
       checksum := checksum . reverse L_contents;
       L_contents := nil;
       return checksum >>
  end;

put('J!-end, 'stat, 'endstat);

symbolic procedure J!-compile u;
  begin
    terpri();
    princ "J!-COMPILE ";
    prin u; princ ": IN files;  or type in expressions"; terpri();
    princ "When all done, execute J!-END;"; terpri();
    verbos nil;
    j!:ccompilestart(car u, car u, nil, nil);
    dfprintsave := dfprint!*;
    dfprint!* := 'j!:ccmpout1;
    !*defn := t;
    if getd 'begin then return nil;
    j!:ccompilesupervisor();
  end;

put('J!-compile, 'stat, 'rlis);

%
% Global treatment of a flow-graph...
%

symbolic procedure j!:print_opcode(s, depth);
  begin
    scalar op, r1, r2, r3, helper;
    op := car s; r1 := cadr s; r2 := caddr s; r3 := cadddr s;
    helper := get(op, 'j!:opcode_printer);
    if helper then funcall(helper, op, r1, r2, r3, depth)
    else << prin s; terpri() >>
  end;

symbolic procedure j!:print_exit_condition(why, where_to, depth);
  begin
    scalar helper, lab1, drop1, lab2, drop2, negate;
% An exit condition is one of
%     goto          (lab)
%     goto          ((return-register))
%     (ifnull v)    (lab1 lab2)    ) etc, where v is a register and
%     (ifatom v)    (lab1 lab2)    ) lab1, lab2 are labels for true & false
%     (ifeq v1 v2)  (lab1 lab2)    ) and various predicates are supported
%     ((call fn) a1 a2) ()         tail-call to given function
%
    if why = 'goto then <<
       where_to := car where_to;
       if atom where_to then <<
          j!:printf("    goto %s;\n", where_to);
          j!:display_flowgraph(where_to, depth, t) >>
       else << j!:printf "    "; j!:pgoto(where_to, depth) >>;
       return nil >>
    else if eqcar(car why, 'call) then return begin
       scalar args, locs, g, w;
       if w := get(cadar why, 'j!:direct_entrypoint) then <<
          for each a in cdr why do
            if flagp(a, 'j!:live_across_call) then <<
               if null g then j!:printf "    {\n";
               g := j!:my_gensym();
               j!:printf("        Lisp_Object %s = %v;\n", g, a);
               args := g . args >>
            else args := a . args;
          if depth neq 0 then <<
              if g then j!:printf "    ";
              j!:printf("    popv(%s);\n", depth) >>;
          if g then j!:printf "    ";
!#if common!-lisp!-mode
          j!:printf("    { Lisp_Object retVal = %s(", cdr w);
!#else
          j!:printf("    return %s(", cdr w);
!#endif
          args := reversip args;
          if args then <<
             j!:printf("%v", car args);
             for each a in cdr args do j!:printf(", %v", a) >>;
          j!:printf(");\n");
!#if common!-lisp!-mode
          if g then j!:printf "    ";
          j!:printf("    errexit();\n");
          if g then j!:printf "    ";
          j!:printf("    return onevalue(retVal); }\n");
!#endif
          if g then j!:printf "    }\n" >>
       else if w := get(cadar why, 'j!:c_entrypoint) then <<
% I think there may be an issue here with functions that can accept variable
% numbers of args. I seem to support just ONE C entrypoint which I will
% call in all circumstances... Yes there ARE such issues, and the one
% I recently fall across was "error" which in my implementation can take
% any number of arguments. So I have removed it from the list of things
% that can be called as direct C code...
          for each a in cdr why do
            if flagp(a, 'j!:live_across_call) then <<
               if null g then j!:printf "    {\n";
               g := j!:my_gensym();
               j!:printf("        Lisp_Object %s = %v;\n", g, a);
               args := g . args >>
            else args := a . args;
          if depth neq 0 then j!:printf("        popv(%s);\n", depth);
          j!:printf("        return %s(nil", w);
          if null args or length args >= 3 then j!:printf(", %s", length args);
          for each a in reversip args do j!:printf(", %v", a);
          j!:printf(");\n");
          if g then j!:printf "    }\n" >>
       else begin
          scalar nargs;
          nargs := length cdr why;
          j!:printf "    {\n";
          for each a in cdr why do
            if flagp(a, 'j!:live_across_call) then <<
               g := j!:my_gensym();
               j!:printf("        Lisp_Object %s = %v;\n", g, a);
               args := g . args >>
            else args := a . args;
          if depth neq 0 then j!:printf("        popv(%s);\n", depth);
          j!:printf("        fn = elt(env, %s); %</* %c %<*/\n",
                    j!:find_literal cadar why, cadar why);
          if nargs = 1 then j!:printf("        return (*qfn1(fn))(qenv(fn)")
          else if nargs = 2 then j!:printf("        return (*qfn2(fn))(qenv(fn)")
          else j!:printf("        return (*qfnn(fn))(qenv(fn), %s", nargs);
          for each a in reversip args do j!:printf(", %s", a);
          j!:printf(");\n    }\n") end;
       return nil end;
    lab1 := car where_to;
    drop1 := atom lab1 and not flagp(lab1, 'j!:visited);
    lab2 := cadr where_to;
    drop2 := atom lab2 and not flagp(drop2, 'j!:visited);
    if drop2 and get(lab2, 'j!:count) = 1 then <<
       where_to := list(lab2, lab1);
       drop1 := t >>
    else if drop1 then negate := t;
    helper := get(car why, 'j!:exit_helper);
    if null helper then error(0, list("Bad exit condition", why));
    j!:printf("    if (");
    if negate then <<
       j!:printf("!(");
       funcall(helper, cdr why, depth);
       j!:printf(")") >>
    else funcall(helper, cdr why, depth);
    j!:printf(") ");
    if not drop1 then <<
       j!:pgoto(car where_to, depth);
       j!:printf("    else ") >>;
    j!:pgoto(cadr where_to, depth);
    if atom car where_to then j!:display_flowgraph(car where_to, depth, drop1);
    if atom cadr where_to then j!:display_flowgraph(cadr where_to, depth, nil)
  end;

symbolic procedure j!:pmovr(op, r1, r2, r3, depth);
   j!:printf("    %v = %v;\n", r1, r3);

put('movr, 'j!:opcode_printer, function j!:pmovr);

symbolic procedure j!:pmovk(op, r1, r2, r3, depth);
   j!:printf("    %v = elt(env, %s); %</* %c %<*/\n", r1, r3, r2);

put('movk, 'j!:opcode_printer, function j!:pmovk);

symbolic procedure j!:pmovk1(op, r1, r2, r3, depth);
   if null r3 then j!:printf("    %v = nil;\n", r1)
   else if r3 = 't then j!:printf("    %v = lisp_true;\n", r1)
   else j!:printf("    %v = (Lisp_Object)%s; %</* %c %<*/\n", r1, 16*r3+1, r3);

put('movk1, 'j!:opcode_printer, function j!:pmovk1);
flag('(movk1), 'j!:uses_nil);  % Well it does SOMETIMES

symbolic procedure j!:preloadenv(op, r1, r2, r3, depth);
% will not be encountered unless reloadenv variable has been set up.
   j!:printf("    env = stack[%s];\n", -reloadenv);

put('reloadenv, 'j!:opcode_printer, function j!:preloadenv);

symbolic procedure j!:pldrglob(op, r1, r2, r3, depth);
   j!:printf("    %v = qvalue(elt(env, %s)); %</* %c %<*/\n", r1, r3, r2);

put('ldrglob, 'j!:opcode_printer, function j!:pldrglob);

symbolic procedure j!:pstrglob(op, r1, r2, r3, depth);
   j!:printf("    qvalue(elt(env, %s)) = %v; %</* %c %<*/\n", r3, r1, r2);

put('strglob, 'j!:opcode_printer, function j!:pstrglob);

symbolic procedure j!:pnilglob(op, r1, r2, r3, depth);
   j!:printf("    qvalue(elt(env, %s)) = nil; %</* %c %<*/\n", r3, r2);

put('nilglob, 'j!:opcode_printer, function j!:pnilglob);
flag('(nilglob), 'j!:uses_nil);

symbolic procedure j!:pnull(op, r1, r2, r3, depth);
   j!:printf("    %v = (%v == nil ? lisp_true : nil);\n", r1, r3);

put('null, 'j!:opcode_printer, function j!:pnull);
put('not,  'j!:opcode_printer, function j!:pnull);
flag('(null not), 'j!:uses_nil);

symbolic procedure j!:pfastget(op, r1, r2, r3, depth);
 <<
   j!:printf("    if (!symbolp(%v)) %v = nil;\n", r2, r1);
   j!:printf("    else { %v = qfastgets(%v);\n", r1, r2);
   j!:printf("           if (%v != nil) { %v = elt(%v, %s); %</* %c %<*/\n",
                                       r1, r1, r1, car r3, cdr r3);
   j!:printf("#ifdef RECORD_GET\n");
   j!:printf("             if (%v != SPID_NOPROP)\n", r1);
   j!:printf("                record_get(elt(fastget_names, %s), 1);\n", car r3);
   j!:printf("             else record_get(elt(fastget_names, %s), 0),\n", car r3);
   j!:printf("                %v = nil; }\n", r1);
   j!:printf("           else record_get(elt(fastget_names, %s), 0); }\n", car r3);
   j!:printf("#else\n");
   j!:printf("             if (%v == SPID_NOPROP) %v = nil; }}\n", r1, r1);
   j!:printf("#endif\n");
  >>;

put('fastget, 'j!:opcode_printer, function j!:pfastget);
flag('(fastget), 'j!:uses_nil);

symbolic procedure j!:pfastflag(op, r1, r2, r3, depth);
 <<
   j!:printf("    if (!symbolp(%v)) %v = nil;\n", r2, r1);
   j!:printf("    else { %v = qfastgets(%v);\n", r1, r2);
   j!:printf("           if (%v != nil) { %v = elt(%v, %s); %</* %c %<*/\n",
                                       r1, r1, r1, car r3, cdr r3);
   j!:printf("#ifdef RECORD_GET\n");
   j!:printf("             if (%v == SPID_NOPROP)\n", r1);
   j!:printf("                record_get(elt(fastget_names, %s), 0),\n", car r3);
   j!:printf("                %v = nil;\n", r1);
   j!:printf("             else record_get(elt(fastget_names, %s), 1),\n", car r3);
   j!:printf("                %v = lisp_true; }\n", r1);
   j!:printf("           else record_get(elt(fastget_names, %s), 0); }\n", car r3);
   j!:printf("#else\n");
   j!:printf("             if (%v == SPID_NOPROP) %v = nil; else %v = lisp_true; }}\n", r1, r1, r1);
   j!:printf("#endif\n");
  >>;

put('fastflag, 'j!:opcode_printer, function j!:pfastflag);
flag('(fastflag), 'j!:uses_nil);

symbolic procedure j!:pcar(op, r1, r2, r3, depth);
  begin
    if not !*unsafecar then <<
        j!:printf("    if (!car_legal(%v)) ", r3);
        j!:pgoto(j!:find_error_label(list('car, r3), r2, depth), depth) >>;
    j!:printf("    %v = qcar(%v);\n", r1, r3)
  end;

put('car, 'j!:opcode_printer, function j!:pcar);

symbolic procedure j!:pcdr(op, r1, r2, r3, depth);
  begin
    if not !*unsafecar then <<
        j!:printf("    if (!car_legal(%v)) ", r3);
        j!:pgoto(j!:find_error_label(list('cdr, r3), r2, depth), depth) >>;
    j!:printf("    %v = qcdr(%v);\n", r1, r3)
  end;

put('cdr, 'j!:opcode_printer, function j!:pcdr);

symbolic procedure j!:pqcar(op, r1, r2, r3, depth);
    j!:printf("    %v = qcar(%v);\n", r1, r3);

put('qcar, 'j!:opcode_printer, function j!:pqcar);

symbolic procedure j!:pqcdr(op, r1, r2, r3, depth);
    j!:printf("    %v = qcdr(%v);\n", r1, r3);

put('qcdr, 'j!:opcode_printer, function j!:pqcdr);

symbolic procedure j!:patom(op, r1, r2, r3, depth);
   j!:printf("    %v = (consp(%v) ? nil : lisp_true);\n", r1, r3);

put('atom, 'j!:opcode_printer, function j!:patom);
flag('(atom), 'j!:uses_nil);

symbolic procedure j!:pnumberp(op, r1, r2, r3, depth);
   j!:printf("    %v = (is_number(%v) ? lisp_true : nil);\n", r1, r3);

put('numberp, 'j!:opcode_printer, function j!:pnumberp);
flag('(numberp), 'j!:uses_nil);

symbolic procedure j!:pfixp(op, r1, r2, r3, depth);
   j!:printf("    %v = integerp(%v);\n", r1, r3);

put('fixp, 'j!:opcode_printer, function j!:pfixp);
flag('(fixp), 'j!:uses_nil);

symbolic procedure j!:piminusp(op, r1, r2, r3, depth);
   j!:printf("    %v = ((intptr_t)(%v) < 0 ? lisp_true : nil);\n", r1, r3);

put('iminusp, 'j!:opcode_printer, function j!:piminusp);
flag('(iminusp), 'j!:uses_nil);

symbolic procedure j!:pilessp(op, r1, r2, r3, depth);
   j!:printf("    %v = ((intptr_t)%v < (intptr_t)%v) ? lisp_true : nil;\n",
             r1, r2, r3);

put('ilessp, 'j!:opcode_printer, function j!:pilessp);
flag('(ilessp), 'j!:uses_nil);

symbolic procedure j!:pigreaterp(op, r1, r2, r3, depth);
   j!:printf("    %v = ((intptr_t)%v > (intptr_t)%v) ? lisp_true : nil;\n",
             r1, r2, r3);

put('igreaterp, 'j!:opcode_printer, function j!:pigreaterp);
flag('(igreaterp), 'j!:uses_nil);

% The "intptr_t" here is deliberate, and ensures that if the intereg-mode
% arithmetic strays outside 32-bits that truncation is done at that
% level even on 64-bit architectures.

symbolic procedure j!:piminus(op, r1, r2, r3, depth);
   j!:printf("    %v = (Lisp_Object)(2-((intptr_t)(%v)));\n", r1, r3);

put('iminus, 'j!:opcode_printer, function j!:piminus);

symbolic procedure j!:piadd1(op, r1, r2, r3, depth);
   j!:printf("    %v = (Lisp_Object)((intptr_t)(%v) + 0x10);\n", r1, r3);

put('iadd1, 'j!:opcode_printer, function j!:piadd1);

symbolic procedure j!:pisub1(op, r1, r2, r3, depth);
   j!:printf("    %v = (Lisp_Object)((intptr_t)(%v) - 0x10);\n", r1, r3);

put('isub1, 'j!:opcode_printer, function j!:pisub1);

symbolic procedure j!:piplus2(op, r1, r2, r3, depth);
 << j!:printf("    %v = (Lisp_Object)(intptr_t)((intptr_t)%v +", r1, r2);
    j!:printf(" (intptr_t)%v - TAG_FIXNUM);\n", r3) >>;

put('iplus2, 'j!:opcode_printer, function j!:piplus2);

symbolic procedure j!:pidifference(op, r1, r2, r3, depth);
 << j!:printf("    %v = (Lisp_Object)(intptr_t)((intptr_t)%v - (intptr_t)%v", r1, r2, r3);
    j!:printf(" + TAG_FIXNUM);\n") >>;

put('idifference, 'j!:opcode_printer, function j!:pidifference);

symbolic procedure j!:pitimes2(op, r1, r2, r3, depth);
 << j!:printf("    %v = fixnum_of_int((intptr_t)(int_of_fixnum(%v) *", r1, r2);
    j!:printf(" int_of_fixnum(%v)));\n", r3) >>;

put('itimes2, 'j!:opcode_printer, function j!:pitimes2);

symbolic procedure j!:pmodular_plus(op, r1, r2, r3, depth);
 <<
    j!:printf("    {   intptr_t w = int_of_fixnum(%v) + int_of_fixnum(%v);\n",
                    r2, r3);
    j!:printf("        if (w >= current_modulus) w -= current_modulus;\n");
    j!:printf("        %v = fixnum_of_int(w);\n", r1);
    j!:printf("    }\n")
 >>;

put('modular!-plus, 'j!:opcode_printer, function j!:pmodular_plus);

symbolic procedure j!:pmodular_difference(op, r1, r2, r3, depth);
 <<
    j!:printf("    {   intptr_t w = int_of_fixnum(%v) - int_of_fixnum(%v);\n",
                    r2, r3);
    j!:printf("        if (w < 0) w += current_modulus;\n");
    j!:printf("        %v = fixnum_of_int(w);\n", r1);
    j!:printf("    }\n")
 >>;

put('modular!-difference, 'j!:opcode_printer, function j!:pmodular_difference);

symbolic procedure j!:pmodular_minus(op, r1, r2, r3, depth);
 <<
    j!:printf("    {   intptr_t w = int_of_fixnum(%v);\n", r3);
    j!:printf("        if (w != 0) w = current_modulus - w;\n");
    j!:printf("        %v = fixnum_of_int(w);\n", r1);
    j!:printf("    }\n")
 >>;

put('modular!-minus, 'j!:opcode_printer, function j!:pmodular_minus);

!#if (not common!-lisp!-mode)

symbolic procedure j!:passoc(op, r1, r2, r3, depth);
   j!:printf("    %v = Lassoc(nil, %v, %v);\n", r1, r2, r3);

put('assoc, 'j!:opcode_printer, function j!:passoc);
flag('(assoc), 'j!:uses_nil);

!#endif

symbolic procedure j!:patsoc(op, r1, r2, r3, depth);
   j!:printf("    %v = Latsoc(nil, %v, %v);\n", r1, r2, r3);

put('atsoc, 'j!:opcode_printer, function j!:patsoc);
flag('(atsoc), 'j!:uses_nil);

!#if (not common!-lisp!-mode)

symbolic procedure j!:pmember(op, r1, r2, r3, depth);
   j!:printf("    %v = Lmember(nil, %v, %v);\n", r1, r2, r3);

put('member, 'j!:opcode_printer, function j!:pmember);
flag('(member), 'j!:uses_nil);

!#endif

symbolic procedure j!:pmemq(op, r1, r2, r3, depth);
   j!:printf("    %v = Lmemq(nil, %v, %v);\n", r1, r2, r3);

put('memq, 'j!:opcode_printer, function j!:pmemq);
flag('(memq), 'j!:uses_nil);

!#if common!-lisp!-mode

symbolic procedure j!:pget(op, r1, r2, r3, depth);
   j!:printf("    %v = get(%v, %v, nil);\n", r1, r2, r3);

flag('(get), 'j!:uses_nil);
!#else

symbolic procedure j!:pget(op, r1, r2, r3, depth);
   j!:printf("    %v = get(%v, %v);\n", r1, r2, r3);

!#endif

put('get, 'j!:opcode_printer, function j!:pget);

symbolic procedure j!:pqgetv(op, r1, r2, r3, depth);
 << j!:printf("    %v = *(Lisp_Object *)((char *)%v + (CELL-TAG_VECTOR) +",
              r1, r2);
    j!:printf(" ((intptr_t)%v/(16/CELL)));\n", r3) >>;

put('qgetv, 'j!:opcode_printer, function j!:pqgetv);

symbolic procedure j!:pqputv(op, r1, r2, r3, depth);
 <<
  j!:printf("    *(Lisp_Object *)((char *)%v + (CELL-TAG_VECTOR) +", r2);
  j!:printf(" ((intptr_t)%v/(16/CELL))) = %v;\n", r3, r1) >>;

put('qputv, 'j!:opcode_printer, function j!:pqputv);

symbolic procedure j!:peq(op, r1, r2, r3, depth);
   j!:printf("    %v = (%v == %v ? lisp_true : nil);\n", r1, r2, r3);

put('eq, 'j!:opcode_printer, function j!:peq);
flag('(eq), 'j!:uses_nil);

!#if common!-lisp!-mode
symbolic procedure j!:pequal(op, r1, r2, r3, depth);
   j!:printf("    %v = (cl_equal(%v, %v) ? lisp_true : nil);\n",
      r1, r2, r3, r2, r3);
!#else
symbolic procedure j!:pequal(op, r1, r2, r3, depth);
   j!:printf("    %v = (equal(%v, %v) ? lisp_true : nil);\n",
      r1, r2, r3, r2, r3);
!#endif

put('equal, 'j!:opcode_printer, function j!:pequal);
flag('(equal), 'j!:uses_nil);

symbolic procedure j!:pfluidbind(op, r1, r2, r3, depth);
   nil;

put('fluidbind, 'j!:opcode_printer, function j!:pfluidbind);

symbolic procedure j!:pcall(op, r1, r2, r3, depth);
  begin
% r3 is (name <fluids to unbind on error>)
    scalar w, boolfn;
    if w := get(car r3, 'j!:direct_entrypoint) then <<
       j!:printf("    %v = %s(", r1, cdr w);
       if r2 then <<
          j!:printf("%v", car r2);
          for each a in cdr r2 do j!:printf(", %v", a) >>;
       j!:printf(");\n") >>
    else if w := get(car r3, 'j!:direct_predicate) then <<
       boolfn := t;
       j!:printf("    %v = (Lisp_Object)%s(", r1, cdr w);
       if r2 then <<
          j!:printf("%v", car r2);
          for each a in cdr r2 do j!:printf(", %v", a) >>;
       j!:printf(");\n") >>
    else if car r3 = j!:current_procedure then <<
% Things could go sour here if a function tried to call itself but with the
% wrong number of args. And this happens at one place in the REDUCE source
% code (I hope it will be fixed soon!). I will patch things up here by
% discarding any excess args or padding with NIL if not enough had been
% written.
       r2 := j!:fix_nargs(r2, j!:current_args);
       j!:printf("    %v = %s(env", r1, j!:current_c_name);
       if null r2 or length r2 >= 3 then j!:printf(", %s", length r2);
       for each a in r2 do j!:printf(", %v", a);
       j!:printf(");\n") >>
    else if w := get(car r3, 'j!:c_entrypoint) then <<
       j!:printf("    %v = %s(nil", r1, w);
       if null r2 or length r2 >= 3 then j!:printf(", %s", length r2);
       for each a in r2 do j!:printf(", %v", a);
       j!:printf(");\n") >>
    else begin
       scalar nargs;
       nargs := length r2;
       j!:printf("    fn = elt(env, %s); %</* %c %<*/\n",
              j!:find_literal car r3, car r3);
       if nargs = 1 then j!:printf("    %v = (*qfn1(fn))(qenv(fn)", r1)
       else if nargs = 2 then j!:printf("    %v = (*qfn2(fn))(qenv(fn)", r1)
       else j!:printf("    %v = (*qfnn(fn))(qenv(fn), %s", r1, nargs);
       for each a in r2 do j!:printf(", %v", a);
       j!:printf(");\n") end;
    if not flagp(car r3, 'j!:no_errors) then <<
       if null cadr r3 and depth = 0 then j!:printf("    errexit();\n")
       else <<
           j!:printf("    if (exception_pending()) ");
           j!:pgoto(j!:find_error_label(nil, cadr r3, depth) , depth) >> >>;
    if boolfn then j!:printf("    %v = %v ? lisp_true : nil;\n", r1, r1);
  end;

symbolic procedure j!:fix_nargs(r2, act);
   if null act then nil
   else if null r2 then nil . j!:fix_nargs(nil, cdr act)
   else car r2 . j!:fix_nargs(cdr r2, cdr act);

put('call, 'j!:opcode_printer, function j!:pcall);

symbolic procedure j!:pgoto(lab, depth);
  begin
    if atom lab then return j!:printf("goto %s;\n", lab);
    lab := get(car lab, 'j!:chosen);
    if zerop depth then j!:printf("return onevalue(%v);\n", lab)
    else if flagp(lab, 'j!:live_across_call) then
      j!:printf("{ Lisp_Object res = %v; popv(%s); return onevalue(res); }\n", lab, depth)
    else j!:printf("{ popv(%s); return onevalue(%v); }\n", depth, lab)
  end;

symbolic procedure j!:pifnull(s, depth);
  j!:printf("%v == nil", car s);

put('ifnull, 'j!:exit_helper, function j!:pifnull);

symbolic procedure j!:pifatom(s, depth);
  j!:printf("!consp(%v)", car s);

put('ifatom, 'j!:exit_helper, function j!:pifatom);

symbolic procedure j!:pifsymbol(s, depth);
  j!:printf("symbolp(%v)", car s);

put('ifsymbol, 'j!:exit_helper, function j!:pifsymbol);

symbolic procedure j!:pifnumber(s, depth);
  j!:printf("is_number(%v)", car s);

put('ifnumber, 'j!:exit_helper, function j!:pifnumber);

symbolic procedure j!:pifizerop(s, depth);
  j!:printf("(%v) == 1", car s);

put('ifizerop, 'j!:exit_helper, function j!:pifizerop);

symbolic procedure j!:pifeq(s, depth);
  j!:printf("%v == %v", car s, cadr s);

put('ifeq, 'j!:exit_helper, function j!:pifeq);

!#if common!-lisp!-mode
symbolic procedure j!:pifequal(s, depth);
  j!:printf("cl_equal(%v, %v)",
           car s, cadr s, car s, cadr s);
!#else
symbolic procedure j!:pifequal(s, depth);
  j!:printf("equal(%v, %v)",
           car s, cadr s, car s, cadr s);
!#endif

put('ifequal, 'j!:exit_helper, function j!:pifequal);

symbolic procedure j!:pifilessp(s, depth);
  j!:printf("((intptr_t)(%v)) < ((intptr_t)(%v))", car s, cadr s);

put('ifilessp, 'j!:exit_helper, function j!:pifilessp);

symbolic procedure j!:pifigreaterp(s, depth);
  j!:printf("((intptr_t)(%v)) > ((intptr_t)(%v))", car s, cadr s);

put('ifigreaterp, 'j!:exit_helper, function j!:pifigreaterp);

symbolic procedure j!:display_flowgraph(s, depth, dropping_through);
  if not atom s then <<
    j!:printf "    ";
    j!:pgoto(s, depth) >>
  else if not flagp(s, 'j!:visited) then begin
    scalar why, where_to;
    flag(list s, 'j!:visited);
    if not dropping_through or not (get(s, 'j!:count) = 1) then
        j!:printf("\n%s:\n", s);
    for each k in reverse get(s, 'j!:contents) do j!:print_opcode(k, depth);
    why := get(s, 'j!:why);
    where_to := get(s, 'j!:where_to);
    if why = 'goto and (not atom car where_to or
                        (not flagp(car where_to, 'j!:visited) and
                         get(car where_to, 'j!:count) = 1)) then
       j!:display_flowgraph(car where_to, depth, t)
    else j!:print_exit_condition(why, where_to, depth);
  end;

fluid '(j!:startpoint);

symbolic procedure j!:branch_chain(s, count);
  begin
    scalar contents, why, where_to, n;
% do nothing to blocks already visted or return blocks.
    if not atom s then return s
    else if flagp(s, 'j!:visited) then <<
       n := get(s, 'j!:count);
       if null n then n := 1 else n := n + 1;
       put(s, 'j!:count, n);
       return s >>;
    flag(list s, 'j!:visited);
    contents := get(s, 'j!:contents);
    why := get(s, 'j!:why);
    where_to := for each z in get(s, 'j!:where_to) collect
                    j!:branch_chain(z, count);
% Turn movr a,b; return a; into return b;
    while contents and eqcar(car contents, 'movr) and
        why = 'goto and not atom car where_to and
        caar where_to = cadr car contents do <<
      where_to := list list cadddr car contents;
      contents := cdr contents >>;
    put(s, 'j!:contents, contents);
    put(s, 'j!:where_to, where_to);
% discard empty blocks
    if null contents and why = 'goto then <<
       remflag(list s, 'j!:visited);
       return car where_to >>;
    if count then <<
      n := get(s, 'j!:count);
      if null n then n := 1
      else n := n + 1;
      put(s, 'j!:count, n) >>;
    return s
  end;

symbolic procedure j!:one_operand op;
 << flag(list op, 'j!:set_r1);
    flag(list op, 'j!:read_r3);
    put(op, 'j!:code, function j!:builtin_one) >>;

symbolic procedure j!:two_operands op;
 << flag(list op, 'j!:set_r1);
    flag(list op, 'j!:read_r2);
    flag(list op, 'j!:read_r3);
    put(op, 'j!:code, function j!:builtin_two) >>;

for each n in '(car cdr qcar qcdr null not atom numberp fixp iminusp
                iminus iadd1 isub1 modular!-minus) do j!:one_operand n;
!#if common!-lisp!-mode
for each n in '(eq equal atsoc memq iplus2 idifference
                itimes2 ilessp igreaterp qgetv get
                modular!-plus modular!-difference
                ) do j!:two_operands n;
!#else
for each n in '(eq equal atsoc memq iplus2 idifference
                assoc member
                itimes2 ilessp igreaterp qgetv get
                modular!-plus modular!-difference
                ) do j!:two_operands n;
!#endif


flag('(movr movk movk1 ldrglob call reloadenv fastget fastflag), 'j!:set_r1);
flag('(strglob qputv), 'j!:read_r1);
flag('(qputv fastget fastflag), 'j!:read_r2);
flag('(movr qputv), 'j!:read_r3);
flag('(ldrglob strglob nilglob movk call), 'j!:read_env);
% special opcodes:
%   call fluidbind

fluid '(fn_used nil_used nilbase_used);

symbolic procedure j!:live_variable_analysis j!:all_blocks;
  begin
    scalar changed, z;
    repeat <<
      changed := nil;
      for each b in j!:all_blocks do
        begin
          scalar w, live;
          for each x in get(b, 'j!:where_to) do
             if atom x then live := union(live, get(x, 'j!:live))
             else live := union(live, x);
          w := get(b, 'j!:why);
          if not atom w then <<
             if eqcar(w, 'ifnull) or eqcar(w, 'ifequal) then nil_used := t;
             live := union(live, cdr w);
             if eqcar(car w, 'call) and
                (flagp(cadar w, 'j!:direct_predicate) or
                 (flagp(cadar w, 'j!:c_entrypoint) and
                  not flagp(cadar w, 'j!:direct_entrypoint))) then
                 nil_used := t;
             if eqcar(car w, 'call) and
                not (cadar w = j!:current_procedure) and
                not get(cadar w, 'j!:direct_entrypoint) and
                not get(cadar w, 'j!:c_entrypoint) then <<
                    fn_used := t; live := union('(env), live) >> >>;
          for each s in get(b, 'j!:contents) do
            begin % backwards over contents
              scalar op, r1, r2, r3;
              op := car s; r1 := cadr s; r2 := caddr s; r3 := cadddr s;
              if op = 'movk1 then <<
                  if r3 = nil then nil_used := t
                  else if r3 = 't then nilbase_used := t >>
              else if atom op and flagp(op, 'j!:uses_nil) then nil_used := t;
              if flagp(op, 'j!:set_r1) then
!#if common!-lisp!-mode
                 if memq(r1, live) then live := remove(r1, live)
!#else
                 if memq(r1, live) then live := delete(r1, live)
!#endif
                 else if op = 'call then nil % Always needed
                 else op := 'nop;
              if flagp(op, 'j!:read_r1) then live := union(live, list r1);
              if flagp(op, 'j!:read_r2) then live := union(live, list r2);
              if flagp(op, 'j!:read_r3) then live := union(live, list r3);
              if op = 'call then <<
                 if not flagp(car r3, 'j!:no_errors) or
                    flagp(car r3, 'j!:c_entrypoint) or
                    get(car r3, 'j!:direct_predicate) then nil_used := t;
                 does_call := t;
                 if not eqcar(r3, j!:current_procedure) and
                    not get(car r3, 'j!:direct_entrypoint) and
                    not get(car r3, 'j!:c_entrypoint) then fn_used := t;
                 if not flagp(car r3, 'j!:no_errors) then
                     flag(live, 'j!:live_across_call);
                 live := union(live, r2) >>;
              if flagp(op, 'j!:read_env) then live := union(live, '(env))
            end;
!#if common!-lisp!-mode
          live := append(live, nil); % because CL sort is destructive!
!#endif
          live := sort(live, function orderp);
          if not (live = get(b, 'j!:live)) then <<
            put(b, 'j!:live, live);
            changed := t >>
        end
    >> until not changed;
    z := j!:registers;
    j!:registers := j!:stacklocs := nil;
    for each r in z do
       if flagp(r, 'j!:live_across_call) then j!:stacklocs := r . j!:stacklocs
       else j!:registers := r . j!:registers
  end;

symbolic procedure j!:insert1(a, b);
  if memq(a, b) then b
  else a . b;

symbolic procedure j!:clash(a, b);
  if flagp(a, 'j!:live_across_call) = flagp(b, 'j!:live_across_call) then <<   
    put(a, 'j!:clash, j!:insert1(b, get(a, 'j!:clash)));
    put(b, 'j!:clash, j!:insert1(a, get(b, 'j!:clash))) >>;

symbolic procedure j!:build_clash_matrix j!:all_blocks;
  begin
    for each b in j!:all_blocks do
      begin
        scalar live, w;
        for each x in get(b, 'j!:where_to) do
           if atom x then live := union(live, get(x, 'j!:live))
           else live := union(live, x);
        w := get(b, 'j!:why);
        if not atom w then <<
           live := union(live, cdr w);
           if eqcar(car w, 'call) and
                not get(cadar w, 'j!:direct_entrypoint) and
                not get(cadar w, 'j!:c_entrypoint) then
              live := union('(env), live) >>;
        for each s in get(b, 'j!:contents) do
          begin
            scalar op, r1, r2, r3;
            op := car s; r1 := cadr s; r2 := caddr s; r3 := cadddr s;
            if flagp(op, 'j!:set_r1) then
               if memq(r1, live) then <<
!#if common!-lisp!-mode
                  live := remove(r1, live);
!#else
                  live := delete(r1, live);
!#endif
                  if op = 'reloadenv then reloadenv := t;
                  for each v in live do j!:clash(r1, v) >>
               else if op = 'call then nil
               else <<
                  op := 'nop;
                  rplacd(s, car s . cdr s); % Leaves original instrn visible
                  rplaca(s, op) >>;
            if flagp(op, 'j!:read_r1) then live := union(live, list r1);
            if flagp(op, 'j!:read_r2) then live := union(live, list r2);
            if flagp(op, 'j!:read_r3) then live := union(live, list r3);
% Maybe CALL should be a little more selective about need for "env"?
            if op = 'call then live := union(live, r2);
            if flagp(op, 'j!:read_env) then live := union(live, '(env))
          end
      end;
% The next few lines are for debugging...
%%-    j!:printf "Scratch registers:\n";
%%-    for each r in j!:registers do
%%-        j!:printf("%s clashes: %s\n", r, get(r, 'j!:clash));
%%-    j!:printf "Stack items:\n";
%%-    for each r in j!:stacklocs do
%%-        j!:printf("%s clashes: %s\n", r, get(r, 'j!:clash));
    return nil
  end;

symbolic procedure j!:allocate_registers rl;
  begin
    scalar schedule, neighbours, allocation;
    neighbours := 0;
    while rl do begin
      scalar w, x;
      w := rl;
      while w and length (x := get(car w, 'j!:clash)) > neighbours do
        w := cdr w;
      if w then <<
        schedule := car w . schedule;
        rl := deleq(car w, rl);
        for each r in x do put(r, 'j!:clash, deleq(car w, get(r, 'j!:clash))) >>
      else neighbours := neighbours + 1
    end;
    for each r in schedule do begin
      scalar poss;
      poss := allocation;
      for each x in get(r, 'j!:clash) do
        poss := deleq(get(x, 'j!:chosen), poss);
      if null poss then <<
         poss := j!:my_gensym();
         allocation := append(allocation, list poss) >>
      else poss := car poss;
%     j!:printf("%</* Allocate %s to %s, to miss %s %<*/\n",
%               r, poss, get(r, 'j!:clash));
      put(r, 'j!:chosen, poss)
    end;
    return allocation
  end;
        
symbolic procedure j!:remove_nops j!:all_blocks;
% Remove no-operation instructions, and map registers to reflect allocation
  for each b in j!:all_blocks do
    begin
      scalar r;
      for each s in get(b, 'j!:contents) do
        if not eqcar(s, 'nop) then
          begin
            scalar op, r1, r2, r3;
            op := car s; r1 := cadr s; r2 := caddr s; r3 := cadddr s;
            if flagp(op, 'j!:set_r1) or flagp(op, 'j!:read_r1) then
               r1 := get(r1, 'j!:chosen);
            if flagp(op, 'j!:read_r2) then r2 := get(r2, 'j!:chosen);
            if flagp(op, 'j!:read_r3) then r3 := get(r3, 'j!:chosen);
            if op = 'call then
               r2 := for each v in r2 collect get(v, 'j!:chosen);
            if not (op = 'movr and r1 = r3) then
               r := list(op, r1, r2, r3) . r
          end;
      put(b, 'j!:contents, reversip r);
      r := get(b, 'j!:why);
      if not atom r then
         put(b, 'j!:why, 
                car r . for each v in cdr r collect get(v, 'j!:chosen))
    end;

fluid '(j!:error_labels);

symbolic procedure j!:find_error_label(why, env, depth);
  begin
    scalar w, z;
    z := list(why, env, depth);
    w := assoc!*!*(z, j!:error_labels);
    if null w then <<
       w := z . j!:my_gensym();
       j!:error_labels := w . j!:error_labels >>;
    return cdr w
  end;

symbolic procedure j!:assign(u, v, c);
  if flagp(u, 'fluid) then list('strglob, v, u, j!:find_literal u) . c
  else list('movr, u, nil, v) . c;

symbolic procedure j!:insert_tailcall b;
  begin
    scalar why, dest, contents, fcall, res, w;
    why := get(b, 'j!:why);
    dest := get(b, 'j!:where_to);
    contents := get(b, 'j!:contents);
    while contents and not eqcar(car contents, 'call) do <<
      w := car contents . w;
      contents := cdr contents >>;
    if null contents then return nil;
    fcall := car contents;
    contents := cdr contents;
    res := cadr fcall;
    while w do <<
      if eqcar(car w, 'reloadenv) then w := cdr w
      else if eqcar(car w, 'movr) and cadddr car w = res then <<
        res := cadr car w;
        w := cdr w >>
      else res := w := nil >>;
    if null res then return nil;
    if j!:does_return(res, why, dest) then
       if car cadddr fcall = j!:current_procedure then <<
          for each p in pair(j!:current_args, caddr fcall) do
             contents := j!:assign(car p, cdr p, contents);
          put(b, 'j!:contents, contents);
          put(b, 'j!:why, 'goto);
          put(b, 'j!:where_to, list restart_label) >>
       else <<
          nil_used := t;
          put(b, 'j!:contents, contents);
          put(b, 'j!:why, list('call, car cadddr fcall) . caddr fcall);
          put(b, 'j!:where_to, nil) >>
  end;

symbolic procedure j!:does_return(res, why, where_to);
  if not (why = 'goto) then nil
  else if not atom car where_to then res = caar where_to
  else begin
    scalar contents;
    where_to := car where_to;
    contents := reverse get(where_to, 'j!:contents);
    why := get(where_to, 'j!:why);
    where_to := get(where_to, 'j!:where_to);
    while contents do
      if eqcar(car contents, 'reloadenv) then contents := cdr contents
      else if eqcar(car contents, 'movr) and cadddr car contents = res then <<
        res := cadr car contents;
        contents := cdr contents >>
      else res := contents := nil;
    if null res then return nil
    else return j!:does_return(res, why, where_to)
  end;

symbolic procedure j!:pushpop(op, v);
%  for each x in v do j!:printf("        %s(%s);\n", op, x);
  begin
    scalar n, w;
    if null v then return nil;
    n := length v;
    while n > 0 do <<
       w := n;
       if w > 6 then w := 6;
       n := n-w;
       if w = 1 then j!:printf("        %s(%s);\n", op, car v)
       else <<
          j!:printf("        %s%d(%s", op, w, car v);
          v := cdr v;
          for i := 2:w do <<
             j!:printf(",%s", car v);
             v := cdr v >>;
          j!:printf(");\n") >> >>
  end;

symbolic procedure j!:optimise_flowgraph(j!:startpoint, j!:all_blocks,
                                          env, argch, args);
  begin
    scalar w, n, locs, stacks, j!:error_labels, fn_used, nil_used, nilbase_used;
!#if common!-lisp!-mode
    nilbase_used := t;  % For onevalue(xxx) at least 
!#endif
    for each b in j!:all_blocks do j!:insert_tailcall b;
    j!:startpoint := j!:branch_chain(j!:startpoint, nil);
    remflag(j!:all_blocks, 'j!:visited);
    j!:live_variable_analysis j!:all_blocks;
    j!:build_clash_matrix j!:all_blocks;
    if j!:error_labels and env then reloadenv := t;
    for each u in env do
      for each v in env do j!:clash(cdr u, cdr v); % keep all args distinct
    locs := j!:allocate_registers j!:registers;
    stacks := j!:allocate_registers j!:stacklocs;
    flag(stacks, 'j!:live_across_call);
    j!:remove_nops j!:all_blocks;
    j!:startpoint := j!:branch_chain(j!:startpoint, nil); % after tailcall insertion
    remflag(j!:all_blocks, 'j!:visited);
    j!:startpoint := j!:branch_chain(j!:startpoint, t); % ... AGAIN to tidy up
    remflag(j!:all_blocks, 'j!:visited);
    if does_call then nil_used := t;
    if locs then <<
      j!:printf("    Lisp_Object %s", car locs);
      for each v in cdr locs do j!:printf(", %s", v);
      j!:printf ";\n" >>;
    if fn_used then j!:printf "    Lisp_Object fn;\n";
    if nil_used then
       j!:printf("    CSL_IGNORE(nil);\n")
    else if nilbase_used then <<
       j!:printf("#ifndef NILSEG_EXTERNS\n");
       j!:printf("    CSL_IGNORE(nil);\n");
       j!:printf("#endif\n") >>;
    if car argch = 0 or car argch >= 3 then
       j!:printf("    argcheck(nargs, %s, \q%s\q);\n", car argch, cdr argch);
    j!:printf("#ifdef DEBUG\n");
    j!:printf("    if (check_env(env)) return aerror(\qenv for %s\q);\n",
              cdr argch);
    j!:printf("#endif\n");
    j!:printf("#ifdef CHECK_STACK\n");
    j!:printf("    if_check_stack;\n");
    j!:printf("#endif\n");
% I will not do a stack check if I have a leaf procedure, and I hope
% that this policy will speed up code a bit.
    if does_call then <<
       j!:printf "    if (stack >= stacklimit)\n";
       j!:printf "    {\n";
% This is slightly clumsy code to save all args on the stack across the
% call to reclaim(), but it is not executed often...
       j!:pushpop('push, args);
       j!:printf "        env = reclaim(env, \qstack\q, GC_STACK, 0);\n";
       j!:pushpop('pop, reverse args);
       j!:printf "        if (exception_pending()) return nil;\n";
       j!:printf "    }\n" >>;
    if reloadenv then j!:printf("    push(env);\n")
    else j!:printf("    CSL_IGNORE(env);\n");
    n := 0;
    if stacks then <<
       j!:printf "%</* space for vars preserved across procedure calls %<*/\n";
       for each v in stacks do <<
          put(v, 'j!:location, n);
          n := n+1 >>;
       w := n;
       while w >= 5 do <<
          j!:printf "    push5(nil, nil, nil, nil, nil);\n";
          w := w - 5 >>;
       if w neq 0 then <<
          if w = 1 then j!:printf "    push(nil);\n"
          else <<
             j!:printf("    push%s(nil", w);
             for i := 2:w do j!:printf ", nil";
             j!:printf ");\n" >> >> >>;
    if reloadenv then <<
       reloadenv := n;
       n := n + 1 >>;
    if env then j!:printf "%</* copy arguments values to proper place %<*/\n";
    for each v in env do
      if flagp(cdr v, 'j!:live_across_call) then
         j!:printf("    stack[%s] = %s;\n",
               -get(get(cdr v, 'j!:chosen), 'j!:location), cdr v)
      else j!:printf("    %s = %s;\n", get(cdr v, 'j!:chosen), cdr v);
    j!:printf "%</* end of prologue %<*/\n";
    j!:display_flowgraph(j!:startpoint, n, t);
    if j!:error_labels then <<
       j!:printf "%</* error exit handlers %<*/\n";
       for each x in j!:error_labels do <<
          j!:printf("%s:\n", cdr x);
          j!:print_error_return(caar x, cadar x, caddar x) >> >>;
    remflag(j!:all_blocks, 'j!:visited);
  end;

symbolic procedure j!:print_error_return(why, env, depth);
  begin
    if reloadenv and env then
       j!:printf("    env = stack[%s];\n", -reloadenv);
    if null why then <<
% One could imagine generating backtrace entries here...
       for each v in env do
          j!:printf("    qvalue(elt(env, %s)) = %v; %</* %c %<*/\n",
                 j!:find_literal car v, get(cdr v, 'j!:chosen), car v);
       if depth neq 0 then j!:printf("    popv(%s);\n", depth);
       j!:printf "    return nil;\n" >>
    else if flagp(cadr why, 'j!:live_across_call) then <<
       j!:printf("    {   Lisp_Object res = %v;\n", cadr why);
       for each v in env do
          j!:printf("        qvalue(elt(env, %s)) = %v;\n",
                 j!:find_literal car v, get(cdr v, 'j!:chosen));
       if depth neq 0 then j!:printf("        popv(%s);\n", depth);
       j!:printf("        return error(1, %s, res); }\n",
          if eqcar(why, 'car) then "err_bad_car"
          else if eqcar(why, 'cdr) then "err_bad_cdr"
          else error(0, list(why, "unknown_error"))) >>
    else <<
       for each v in env do
          j!:printf("    qvalue(elt(env, %s)) = %v;\n",
                 j!:find_literal car v, get(cdr v, 'j!:chosen));
       if depth neq 0 then j!:printf("    popv(%s);\n", depth);
       j!:printf("    return error(1, %s, %v);\n",
          (if eqcar(why, 'car) then "err_bad_car"
           else if eqcar(why, 'cdr) then "err_bad_cdr"
           else error(0, list(why, "unknown_error"))),
          cadr why) >>
  end;


%
% Now I have a series of separable sections each of which gives a special
% recipe that implements or optimises compilation of some specific Lisp
% form.
%

symbolic procedure j!:cand(u, env);
  begin
    scalar w, r;
    w := reverse cdr u;
    if null w then return j!:cval(nil, env);
    r := list(list('t, car w));
    w := cdr w;
    for each z in w do
       r := list(list('null, z), nil) . r;
    r := 'cond . r;
    return j!:cval(r, env)
  end;
%--    scalar next, done, v, r;
%--    v := j!:newreg();
%--    done := j!:my_gensym();
%--    u := cdr u;
%--    while cdr u do <<
%--      next := j!:my_gensym();
%--      j!:outop('movr, v, nil, j!:cval(car u, env));
%--      u := cdr u;
%--      j!:endblock(list('ifnull, v), list(done, next));
%--      j!:startblock next >>;
%--    j!:outop('movr, v, nil, j!:cval(car u, env));
%--    j!:endblock('goto, list done);
%--    j!:startblock done;
%--    return v
%--  end;

put('and, 'j!:code, function j!:cand);

!#if common!-lisp!-mode

symbolic procedure j!:cblock(u, env);
  begin
    scalar progret, progexit, r;
    progret := j!:newreg();
    progexit := j!:my_gensym();
    blockstack := (cadr u . progret . progexit) . blockstack;
    u := cddr u;
    for each a in u do r := j!:cval(a, env);
    j!:outop('movr, progret, nil, r);
    j!:endblock('goto, list progexit);
    j!:startblock progexit;
    blockstack := cdr blockstack;
    return progret
  end;


put('block, 'j!:code, function j!:cblock);

!#endif

symbolic procedure j!:ccatch(u, env);
   error(0, "catch");

put('catch, 'j!:code, function j!:ccatch);

symbolic procedure j!:ccompile_let(u, env);
   error(0, "compiler-let");

put('compiler!-let, 'j!:code, function j!:ccompiler_let);

symbolic procedure j!:ccond(u, env);
  begin
    scalar v, join;
    v := j!:newreg();
    join := j!:my_gensym();
    for each c in cdr u do begin
      scalar l1, l2;
      l1 := j!:my_gensym(); l2 := j!:my_gensym();
      if atom cdr c then <<
         j!:outop('movr, v, nil, j!:cval(car c, env));
         j!:endblock(list('ifnull, v), list(l2, join)) >>
      else <<
         j!:cjumpif(car c, env, l1, l2);
         j!:startblock l1;    % if the condition is true
         j!:outop('movr, v, nil, j!:cval('progn . cdr c, env));
         j!:endblock('goto, list join) >>;
      j!:startblock l2 end;
    j!:outop('movk1, v, nil, nil);
    j!:endblock('goto, list join);
    j!:startblock join;
    return v
  end;

put('cond, 'j!:code, function j!:ccond);

symbolic procedure j!:valid_cond x;
  if null x then t
  else if not j!:valid_list car x then nil
  else j!:valid_cond cdr x;

put('cond, 'j!:valid, function j!:valid_cond);

symbolic procedure j!:cdeclare(u, env);
   error(0, "declare");

put('declare, 'j!:code, function j!:cdeclare);

symbolic procedure j!:cde(u, env);
   error(0, "de");

put('de, 'j!:code, function j!:cde);

symbolic procedure j!:cdefun(u, env);
   error(0, "defun");

put('!~defun, 'j!:code, function j!:cdefun);

symbolic procedure j!:ceval_when(u, env);
   error(0, "eval-when");

put('eval!-when, 'j!:code, function j!:ceval_when);

symbolic procedure j!:cflet(u, env);
   error(0, "flet");

put('flet, 'j!:code, function j!:cflet);


symbolic procedure j!:cfunction(u, env);
  begin
    scalar v;
    u := cadr u;
    if not atom u then <<
       if not eqcar(u, 'lambda) then 
           error(0, list("lambda expression needed", u));
       v := dated!-name 'lambda;
       pending_functions :=
          ('de . v . cdr u) . pending_functions;
       u := v >>;
    v := j!:newreg();
    j!:outop('movk, v, u, j!:find_literal u);
    return v;
  end;

symbolic procedure j!:valid_function x;
   if atom x then nil
   else if not null cdr x then nil
   else if idp car x then t
   else if atom car x then nil
   else if not eqcar(car x, 'lambda) then nil
   else if atom cdar x then nil
   else j!:valid_fndef(cadar x, cddar x);

put('function, 'j!:code, function j!:cfunction);
put('function, 'j!:valid, function j!:valid_function);

symbolic procedure j!:cgo(u, env);
  begin
    scalar w, w1;
    w1 := proglabs;
    while null w and w1 do <<
       w := assoc!*!*(cadr u, car w1);
       w1 := cdr w1 >>;
    if null w then error(0, list(u, "label not set"));
    j!:endblock('goto, list cadr w);
    return nil      % value should not be used
  end;

put('go, 'j!:code, function j!:cgo);
put('go, 'j!:valid, function j!:valid_quote);

symbolic procedure j!:cif(u, env);
  begin
    scalar v, join, l1, l2, w;
    v := j!:newreg();
    join := j!:my_gensym();
    l1 := j!:my_gensym();
    l2 := j!:my_gensym();
    j!:cjumpif(car (u := cdr u), env, l1, l2);
    j!:startblock l1;
    j!:outop('movr, v, nil, j!:cval(car (u := cdr u), env));
    j!:endblock('goto, list join);
    j!:startblock l2;
    u := cdr u;
    if u then u := car u; % permit 2-arg version...
    j!:outop('movr, v, nil, j!:cval(u, env));
    j!:endblock('goto, list join);
    j!:startblock join;
    return v
  end;

put('if, 'j!:code, function j!:cif);

symbolic procedure j!:clabels(u, env);
   error(0, "labels");

put('labels, 'j!:code, function j!:clabels);

symbolic procedure j!:expand!-let(vl, b);
  if null vl then 'progn . b
  else if null cdr vl then j!:expand!-let!*(vl, b)
  else begin scalar vars, vals;
    for each v in vl do
      if atom v then << vars := v . vars; vals := nil . vals >>
      else if atom cdr v then << vars := car v . vars; vals := nil . vals >>
      else << vars := car v . vars; vals := cadr v . vals >>;
% if there is any DECLARE it will be at the start of b and the code that
% deals with LAMBDA will cope with it.
    return ('lambda . vars . b) . vals
  end;

symbolic procedure j!:clet(x, env);
   j!:cval(j!:expand!-let(cadr x, cddr x), env);

symbolic procedure j!:valid_let x;
  if null x then t
  else if not j!:valid_cond car x then nil
  else j!:valid_list cdr x;


!#if common!-lisp!-mode
put('let, 'j!:code, function j!:clet);
put('let, 'j!:valid, function j!:valid_let);
!#else
put('!~let, 'j!:code, function j!:clet);
put('!~let, 'j!:valid, function j!:valid_let);
!#endif

symbolic procedure j!:expand!-let!*(vl, b);
  if null vl then 'progn . b
  else begin scalar var, val;
    var := car vl;
    if not atom var then <<
       val := cdr var;
       var := car var;
       if not atom val then val := car val >>;
    b := list list('return, j!:expand!-let!*(cdr vl, b));
    if val then b := list('setq, var, val) . b;
    return 'prog . list var . b
  end;

symbolic procedure j!:clet!*(x, env);
   j!:cval(j!:expand!-let!*(cadr x, cddr x), env);

put('let!*, 'j!:code, function j!:clet!*);
put('let!*, 'j!:valid, function j!:valid_let);

symbolic procedure j!:clist(u, env);
  if null cdr u then j!:cval(nil, env)
  else if null cddr u then j!:cval('ncons . cdr u, env)
  else if eqcar(cadr u, 'cons) then
    j!:cval(list('acons, cadr cadr u, caddr cadr u, 'list . cddr u), env)
  else if null cdddr u then j!:cval('list2 . cdr u, env)
  else if null cddddr u then j!:cval('list3 . cdr u, env)
  else if null cdr cddddr u then j!:cval('list4 . cdr u, env)
  else j!:cval(list('list3!*, cadr u, caddr u,
                    cadddr u, 'list . cddddr u), env);

put('list, 'j!:code, function j!:clist);

symbolic procedure j!:clist!*(u, env);
  begin
    scalar v;
    u := reverse cdr u;
    v := car u;
    for each a in cdr u do
      v := list('cons, a, v);
    return j!:cval(v, env)
  end;    

put('list!*, 'j!:code, function j!:clist!*);

symbolic procedure j!:ccons(u, env);
  begin
    scalar a1, a2;
    a1 := s!:improve cadr u;
    a2 := s!:improve caddr u;
    if a2 = nil or a2 = '(quote nil) or a2 = '(list) then
       return j!:cval(list('ncons, a1), env);
    if eqcar(a1, 'cons) then
       return j!:cval(list('acons, cadr a1, caddr a1, a2), env);
    if eqcar(a2, 'cons) then
       return j!:cval(list('list2!*, a1, cadr a2, caddr a2), env);
    if eqcar(a2, 'list) then
       return j!:cval(list('cons, a1,
                     list('cons, cadr a2, 'list . cddr a2)), env);
    return j!:ccall(car u, cdr u, env)
  end;

put('cons, 'j!:code, function j!:ccons);

symbolic procedure j!:cget(u, env);
  begin
    scalar a1, a2, w, r, r1;
    a1 := s!:improve cadr u;
    a2 := s!:improve caddr u;
    if eqcar(a2, 'quote) and idp(w := cadr a2) and
       (w := symbol!-make!-fastget(w, nil)) then <<
        r := j!:newreg();
        j!:outop('fastget, r, j!:cval(a1, env), w . cadr a2);
        return r >>
    else return j!:ccall(car u, cdr u, env)
  end;

put('get, 'j!:code, function j!:cget);

symbolic procedure j!:cflag(u, env);
  begin
    scalar a1, a2, w, r, r1;
    a1 := s!:improve cadr u;
    a2 := s!:improve caddr u;
    if eqcar(a2, 'quote) and idp(w := cadr a2) and
       (w := symbol!-make!-fastget(w, nil)) then <<
        r := j!:newreg();
        j!:outop('fastflag, r, j!:cval(a1, env), w . cadr a2);
        return r >>
    else return j!:ccall(car u, cdr u, env)
  end;

put('flagp, 'j!:code, function j!:cflag);

symbolic procedure j!:cgetv(u, env);
  if not !*fastvector then j!:ccall(car u, cdr u, env)
  else j!:cval('qgetv . cdr u, env);

put('getv, 'j!:code, function j!:cgetv);
!#if common!-lisp!-mode
put('svref, 'j!:code, function j!:cgetv);
!#endif

symbolic procedure j!:cputv(u, env);
  if not !*fastvector then j!:ccall(car u, cdr u, env)
  else j!:cval('qputv . cdr u, env);

put('putv, 'j!:code, function j!:cputv);

symbolic procedure j!:cqputv(x, env);
  begin
    scalar rr;
    rr := j!:pareval(cdr x, env);
    j!:outop('qputv, caddr rr, car rr, cadr rr);
    return caddr rr
  end;

put('qputv, 'j!:code, function j!:cqputv);

symbolic procedure j!:cmacrolet(u, env);
   error(0, "macrolet");

put('macrolet, 'j!:code, function j!:cmacrolet);

symbolic procedure j!:cmultiple_value_call(u, env);
   error(0, "multiple_value_call");

put('multiple!-value!-call, 'j!:code, function j!:cmultiple_value_call);

symbolic procedure j!:cmultiple_value_prog1(u, env);
   error(0, "multiple_value_prog1");

put('multiple!-value!-prog1, 'j!:code, function j!:cmultiple_value_prog1);

symbolic procedure j!:cor(u, env);
  begin
    scalar next, done, v, r;
    v := j!:newreg();
    done := j!:my_gensym();
    u := cdr u;
    while cdr u do <<
      next := j!:my_gensym();
      j!:outop('movr, v, nil, j!:cval(car u, env));
      u := cdr u;
      j!:endblock(list('ifnull, v), list(next, done));
      j!:startblock next >>;
    j!:outop('movr, v, nil, j!:cval(car u, env));
    j!:endblock('goto, list done);
    j!:startblock done;
    return v
  end;

put('or, 'j!:code, function j!:cor);

symbolic procedure j!:cprog(u, env);
  begin
    scalar w, w1, bvl, local_proglabs, progret, progexit,
           fluids, env1, body, decs;
    env1 := car env;
    bvl := cadr u;
    w := s!:find_local_decs(cddr u, t);
    body := cdr w;
    localdecs := car w . localdecs;
% Anything DECLAREd special that is not already fluid or global
% gets uprated now. decs ends up a list of things that had their status
% changed.
    for each v in bvl do <<
       if not globalp v and not fluidp v and
          j!:local_fluidp(v, localdecs) then <<
          make!-special v;
          decs := v . decs >> >>;
    for each v in bvl do <<
       if globalp v then begin scalar oo;
          oo := wrs nil;
          princ "+++++ "; prin v;
          princ " converted from GLOBAL to FLUID"; terpri();
          wrs oo;
          unglobal list v;
          fluid list v end;
% Note I need to update local_decs
       if fluidp v then <<
          fluids := (v . j!:newreg()) . fluids;
          flag(list cdar fluids, 'j!:live_across_call); % silly if not
          env1 := ('j!:dummy!:name . cdar fluids) . env1;
          j!:outop('ldrglob, cdar fluids, v, j!:find_literal v);
          j!:outop('nilglob, nil, v, j!:find_literal v) >>
       else <<
          env1 := (v . j!:newreg()) . env1;
          j!:outop('movk1, cdar env1, nil, nil) >> >>;
    if fluids then j!:outop('fluidbind, nil, nil, fluids);
    env := env1 . append(fluids, cdr env);
    u := body;
    progret := j!:newreg();
    progexit := j!:my_gensym();
    blockstack := (nil . progret . progexit) . blockstack;
    for each a in u do if atom a then
       if atsoc(a, local_proglabs) then <<
          if not null a then <<
             w := wrs nil;
             princ "+++++ multiply defined label: "; prin a; terpri(); wrs w >> >>
       else local_proglabs := list(a, j!:my_gensym()) . local_proglabs;
    proglabs := local_proglabs . proglabs;
    for each a in u do
      if atom a then <<
        w := cdr(assoc!*!*(a, local_proglabs));
        if null cdr w then <<
           rplacd(w, t);
           j!:endblock('goto, list car w);
           j!:startblock car w >> >>
      else j!:cval(a, env);
    j!:outop('movk1, progret, nil, nil);
    j!:endblock('goto, list progexit);
    j!:startblock progexit;
    for each v in fluids do
      j!:outop('strglob, cdr v, car v, j!:find_literal car v);
    blockstack := cdr blockstack;
    proglabs := cdr proglabs;
    unfluid decs;               % reset effect of DECLARE
    localdecs := cdr localdecs;
    return progret
  end;

put('prog, 'j!:code, function j!:cprog);

symbolic procedure j!:valid_prog x;
  j!:valid_list cdr x;

put('prog, 'j!:valid, function j!:valid_prog);

symbolic procedure j!:cprog!*(u, env);
   error(0, "prog*");

put('prog!*, 'j!:code, function j!:cprog!*);

symbolic procedure j!:cprog1(u, env);
  begin
    scalar g;
    g := j!:my_gensym();
    g := list('prog, list g,
              list('setq, g, cadr u),
              'progn . cddr u,
              list('return, g));
    return j!:cval(g, env)
  end;

put('prog1, 'j!:code, function j!:cprog1);

symbolic procedure j!:cprog2(u, env);
  begin
    scalar g;
    u := cdr u;
    g := j!:my_gensym();
    g := list('prog, list g,
              list('setq, g, cadr u),
              'progn . cddr u,
              list('return, g));
    g := list('progn, car u, g);
    return j!:cval(g, env)
  end;

put('prog2, 'j!:code, function j!:cprog2);

symbolic procedure j!:cprogn(u, env);
  begin
    scalar r;
    u := cdr u;
    if u = nil then u := '(nil);
    for each s in u do r := j!:cval(s, env);
    return r
  end;

put('progn, 'j!:code, function j!:cprogn);

symbolic procedure j!:cprogv(u, env);
   error(0, "progv");

put('progv, 'j!:code, function j!:cprogv);

symbolic procedure j!:cquote(u, env);
  begin
    scalar v;
    u := cadr u;
    v := j!:newreg();
    if null u or u = 't or j!:small_number u then
         j!:outop('movk1, v, nil, u)
    else j!:outop('movk, v, u, j!:find_literal u);
    return v;
  end;

symbolic procedure j!:valid_quote x;
   t;

put('quote, 'j!:code, function j!:cquote);
put('quote, 'j!:valid, function j!:valid_quote);

symbolic procedure j!:creturn(u, env);
  begin
    scalar w;
    w := assoc!*!*(nil, blockstack);
    if null w then error(0, "RETURN out of context");
    j!:outop('movr, cadr w, nil, j!:cval(cadr u, env));
    j!:endblock('goto, list cddr w);
    return nil      % value should not be used
  end;

put('return, 'j!:code, function j!:creturn);

!#if common!-lisp!-mode

symbolic procedure j!:creturn_from(u, env);
  begin
    scalar w;
    w := assoc!*!*(cadr u, blockstack);
    if null w then error(0, "RETURN-FROM out of context");
    j!:outop('movr, cadr w, nil, j!:cval(caddr u, env));
    j!:endblock('goto, list cddr w);
    return nil      % value should not be used
  end;

!#endif

put('return!-from, 'j!:code, function j!:creturn_from);

symbolic procedure j!:csetq(u, env);
  begin
    scalar v, w;
    v := j!:cval(caddr u, env);
    u := cadr u;
    if not idp u then error(0, list(u, "bad variable in setq"))
    else if (w := j!:locally_bound(u, env)) then
       j!:outop('movr, cdr w, nil, v)
    else if flagp(u, 'j!:constant) then
       error(0, list(u, "attempt to use setq on a constant"))
    else j!:outop('strglob, v, u, j!:find_literal u);
    return v
  end;

put('setq, 'j!:code, function j!:csetq);
put('noisy!-setq, 'j!:code, function j!:csetq);

!#if common!-lisp!-mode

symbolic procedure j!:ctagbody(u, env);
  begin
    scalar w, bvl, local_proglabs, res;
    u := cdr u;
    for each a in u do if atom a then
       if atsoc(a, local_proglabs) then <<
          if not null a then <<
             w := wrs nil;
             princ "+++++ multiply defined label: "; prin a; terpri(); wrs w >> >>
       else local_proglabs := list(a, j!:my_gensym()) . local_proglabs;
    proglabs := local_proglabs . proglabs;
    for each a in u do
      if atom a then <<
        w := cdr(assoc!*!*(a, local_proglabs));
        if null cdr w then <<
           rplacd(w, t);
           j!:endblock('goto, list car w);
           j!:startblock car w >> >>
      else res := j!:cval(a, env);
    if null res then res := j!:cval(nil, env);
    proglabs := cdr proglabs;
    return res
  end;

put('tagbody, 'j!:code, function j!:ctagbody);

!#endif

symbolic procedure j!:cprivate_tagbody(u, env);
% This sets a label for use for tail-call to self.
  begin
    u := cdr u;
    j!:endblock('goto, list car u);
    j!:startblock car u;
% This seems to be the proper place to capture the internal names associated
% with argument-vars that must be reset if a tail-call is mapped into a loop.
    j!:current_args := for each v in j!:current_args collect begin
       scalar z;
       z := assoc!*!*(v, car env);
       return if z then cdr z else v end;
    return j!:cval(cadr u, env)
  end;

put('j!:private_tagbody, 'j!:code, function j!:cprivate_tagbody);

symbolic procedure j!:cthe(u, env);
   j!:cval(caddr u, env);

put('the, 'j!:code, function j!:cthe);

symbolic procedure j!:cthrow(u, env);
   error(0, "throw");

put('throw, 'j!:code, function j!:cthrow);

symbolic procedure j!:cunless(u, env);
  begin
    scalar v, join, l1, l2;
    v := j!:newreg();
    join := j!:my_gensym();
    l1 := j!:my_gensym();
    l2 := j!:my_gensym();
    j!:cjumpif(cadr u, env, l2, l1);
    j!:startblock l1;
    j!:outop('movr, v, nil, j!:cval('progn . cddr u, env));
    j!:endblock('goto, list join);
    j!:startblock l2;
    j!:outop('movk1, v, nil, nil);
    j!:endblock('goto, list join);
    j!:startblock join;
    return v
  end;

put('unless, 'j!:code, function j!:cunless);

symbolic procedure j!:cunwind_protect(u, env);
   error(0, "unwind_protect");

put('unwind!-protect, 'j!:code, function j!:cunwind_protect);

symbolic procedure j!:cwhen(u, env);
  begin
    scalar v, join, l1, l2;
    v := j!:newreg();
    join := j!:my_gensym();
    l1 := j!:my_gensym();
    l2 := j!:my_gensym();
    j!:cjumpif(cadr u, env, l1, l2);
    j!:startblock l1;
    j!:outop('movr, v, nil, j!:cval('progn . cddr u, env));
    j!:endblock('goto, list join);
    j!:startblock l2;
    j!:outop('movk1, v, nil, nil);
    j!:endblock('goto, list join);
    j!:startblock join;
    return v
  end;

put('when, 'j!:code, function j!:cwhen);

%
% End of code to handle special forms - what comes from here on is
% more concerned with performance than with speed.
%

!#if (not common!-lisp!-mode)

% mapcar etc are compiled specially as a fudge to achieve an effect as
% if proper environment-capture was implemented for the functional
% argument (which I do not support at present).

symbolic procedure j!:expand_map(fnargs);
  begin
    scalar carp, fn, fn1, args, var, avar, moveon, l1, r, s, closed;
    fn := car fnargs;
% if the value of a mapping function is not needed I demote from mapcar to
% mapc or from maplist to map.
%   if context > 1 then <<
%      if fn = 'mapcar then fn := 'mapc
%      else if fn = 'maplist then fn := 'map >>;
    if fn = 'mapc or fn = 'mapcar or fn = 'mapcan then carp := t;
    fnargs := cdr fnargs;
    if atom fnargs then error(0,"bad arguments to map function");
    fn1 := cadr fnargs;
    while eqcar(fn1, 'function) or
          (eqcar(fn1, 'quote) and eqcar(cadr fn1, 'lambda)) do <<
       fn1 := cadr fn1;
       closed := t >>;
% if closed is false I will insert FUNCALL since I am invoking a function
% stored in a variable - NB this means that the word FUNCTION becomes
% essential when using mapping operators - this is because I have built
% a 2-Lisp rather than a 1-Lisp.
    args := car fnargs;
    l1 := j!:my_gensym();
    r := j!:my_gensym();
    s := j!:my_gensym();
    var := j!:my_gensym();
    avar := var;
    if carp then avar := list('car, avar);
    if closed then fn1 := list(fn1, avar)
    else fn1 := list('apply1, fn1, avar);
    moveon := list('setq, var, list('cdr, var));
    if fn = 'map or fn = 'mapc then fn := sublis(
       list('l1 . l1, 'var . var,
            'fn . fn1, 'args . args, 'moveon . moveon),
       '(prog (var)
             (setq var args)
       l1    (cond
                ((not var) (return nil)))
             fn
             moveon
             (go l1)))
    else if fn = 'maplist or fn = 'mapcar then fn := sublis(
       list('l1 . l1, 'var . var,
            'fn . fn1, 'args . args, 'moveon . moveon, 'r . r),
       '(prog (var r)
             (setq var args)
       l1    (cond
                ((not var) (return (reversip r))))
             (setq r (cons fn r))
             moveon
             (go l1)))
    else fn := sublis(
       list('l1 . l1, 'l2 . j!:my_gensym(), 'var . var,
            'fn . fn1, 'args . args, 'moveon . moveon,
            'r . j!:my_gensym(), 's . j!:my_gensym()),
       '(prog (var r s)
             (setq var args)
             (setq r (setq s (list nil)))
       l1    (cond
                ((not var) (return (cdr r))))
             (rplacd s fn)
       l2    (cond
                ((not (atom (cdr s))) (setq s (cdr s)) (go l2)))
             moveon
             (go l1)));
    return fn
  end;


put('map,     'j!:compile_macro, function j!:expand_map);
put('maplist, 'j!:compile_macro, function j!:expand_map);
put('mapc,    'j!:compile_macro, function j!:expand_map);
put('mapcar,  'j!:compile_macro, function j!:expand_map);
put('mapcon,  'j!:compile_macro, function j!:expand_map);
put('mapcan,  'j!:compile_macro, function j!:expand_map);

!#endif

% caaar to cddddr get expanded into compositions of
% car, cdr which are compiled in-line

symbolic procedure j!:expand_carcdr(x);
  begin
    scalar name;
    name := cdr reverse cdr explode2 car x;
    x := cadr x;
    for each v in name do
        x := list(if v = 'a then 'car else 'cdr, x);
    return x
  end;

<< put('caar, 'j!:compile_macro, function j!:expand_carcdr);
   put('cadr, 'j!:compile_macro, function j!:expand_carcdr);
   put('cdar, 'j!:compile_macro, function j!:expand_carcdr);
   put('cddr, 'j!:compile_macro, function j!:expand_carcdr);
   put('caaar, 'j!:compile_macro, function j!:expand_carcdr);
   put('caadr, 'j!:compile_macro, function j!:expand_carcdr);
   put('cadar, 'j!:compile_macro, function j!:expand_carcdr);
   put('caddr, 'j!:compile_macro, function j!:expand_carcdr);
   put('cdaar, 'j!:compile_macro, function j!:expand_carcdr);
   put('cdadr, 'j!:compile_macro, function j!:expand_carcdr);
   put('cddar, 'j!:compile_macro, function j!:expand_carcdr);
   put('cdddr, 'j!:compile_macro, function j!:expand_carcdr);
   put('caaaar, 'j!:compile_macro, function j!:expand_carcdr);
   put('caaadr, 'j!:compile_macro, function j!:expand_carcdr);
   put('caadar, 'j!:compile_macro, function j!:expand_carcdr);
   put('caaddr, 'j!:compile_macro, function j!:expand_carcdr);
   put('cadaar, 'j!:compile_macro, function j!:expand_carcdr);
   put('cadadr, 'j!:compile_macro, function j!:expand_carcdr);
   put('caddar, 'j!:compile_macro, function j!:expand_carcdr);
   put('cadddr, 'j!:compile_macro, function j!:expand_carcdr);
   put('cdaaar, 'j!:compile_macro, function j!:expand_carcdr);
   put('cdaadr, 'j!:compile_macro, function j!:expand_carcdr);
   put('cdadar, 'j!:compile_macro, function j!:expand_carcdr);
   put('cdaddr, 'j!:compile_macro, function j!:expand_carcdr);
   put('cddaar, 'j!:compile_macro, function j!:expand_carcdr);
   put('cddadr, 'j!:compile_macro, function j!:expand_carcdr);
   put('cdddar, 'j!:compile_macro, function j!:expand_carcdr);
   put('cddddr, 'j!:compile_macro, function j!:expand_carcdr) >>;

symbolic procedure j!:builtin_one(x, env);
  begin
    scalar r1, r2;
    r1 := j!:cval(cadr x, env);
    j!:outop(car x, r2:=j!:newreg(), cdr env, r1);
    return r2
  end;

symbolic procedure j!:builtin_two(x, env);
  begin
    scalar a1, a2, r, rr;
    a1 := cadr x;
    a2 := caddr x;
    rr := j!:pareval(list(a1, a2), env);
    j!:outop(car x, r:=j!:newreg(), car rr, cadr rr);
    return r
  end;

symbolic procedure j!:narg(x, env);
  j!:cval(expand(cdr x, get(car x, 'j!:binary_version)), env);

for each n in
   '((plus plus2)
     (times times2)
     (iplus iplus2)
     (itimes itimes2)) do <<
        put(car n, 'j!:binary_version, cadr n);
        put(car n, 'j!:code, function j!:narg) >>;

!#if common!-lisp!-mode
for each n in
   '((!+ plus2)
     (!* times2)) do <<
        put(car n, 'j!:binary_version, cadr n);
        put(car n, 'j!:code, function j!:narg) >>;
!#endif

symbolic procedure j!:cplus2(u, env);
  begin
    scalar a, b;
    a := s!:improve cadr u;
    b := s!:improve caddr u;
    return if numberp a and numberp b then j!:cval(a+b, env)
       else if a = 0 then j!:cval(b, env)
       else if a = 1 then j!:cval(list('add1, b), env)
       else if b = 0 then j!:cval(a, env)
       else if b = 1 then j!:cval(list('add1, a), env)
       else if b = -1 then j!:cval(list('sub1, a), env)
       else j!:ccall(car u, cdr u, env)
  end;

put('plus2, 'j!:code, function j!:cplus2);

symbolic procedure j!:ciplus2(u, env);
  begin
    scalar a, b;
    a := s!:improve cadr u;
    b := s!:improve caddr u;
    return if numberp a and numberp b then j!:cval(a+b, env)
       else if a = 0 then j!:cval(b, env)
       else if a = 1 then j!:cval(list('iadd1, b), env)
       else if b = 0 then j!:cval(a, env)
       else if b = 1 then j!:cval(list('iadd1, a), env)
       else if b = -1 then j!:cval(list('isub1, a), env)
       else j!:builtin_two(u, env)
  end;

put('iplus2, 'j!:code, function j!:ciplus2);

symbolic procedure j!:cdifference(u, env);
  begin
    scalar a, b;
    a := s!:improve cadr u;
    b := s!:improve caddr u;
    return if numberp a and numberp b then j!:cval(a-b, env)
       else if a = 0 then j!:cval(list('minus, b), env)
       else if b = 0 then j!:cval(a, env)
       else if b = 1 then j!:cval(list('sub1, a), env)
       else if b = -1 then j!:cval(list('add1, a), env)
       else j!:ccall(car u, cdr u, env)
  end;

put('difference, 'j!:code, function j!:cdifference);

symbolic procedure j!:cidifference(u, env);
  begin
    scalar a, b;
    a := s!:improve cadr u;
    b := s!:improve caddr u;
    return if numberp a and numberp b then j!:cval(a-b, env)
       else if a = 0 then j!:cval(list('iminus, b), env)
       else if b = 0 then j!:cval(a, env)
       else if b = 1 then j!:cval(list('isub1, a), env)
       else if b = -1 then j!:cval(list('iadd1, a), env)
       else j!:builtin_two(u, env)
  end;

put('idifference, 'j!:code, function j!:cidifference);

symbolic procedure j!:ctimes2(u, env);
  begin
    scalar a, b;
    a := s!:improve cadr u;
    b := s!:improve caddr u;
    return if numberp a and numberp b then j!:cval(a*b, env)
       else if a = 0 or b = 0 then j!:cval(0, env)
       else if a = 1 then j!:cval(b, env)
       else if b = 1 then j!:cval(a, env)
       else if a = -1 then j!:cval(list('minus, b), env)
       else if b = -1 then j!:cval(list('minus, a), env)
       else j!:ccall(car u, cdr u, env)
  end;

put('times2, 'j!:code, function j!:ctimes2);

symbolic procedure j!:citimes2(u, env);
  begin
    scalar a, b;
    a := s!:improve cadr u;
    b := s!:improve caddr u;
    return if numberp a and numberp b then j!:cval(a*b, env)
       else if a = 0 or b = 0 then j!:cval(0, env)
       else if a = 1 then j!:cval(b, env)
       else if b = 1 then j!:cval(a, env)
       else if a = -1 then j!:cval(list('iminus, b), env)
       else if b = -1 then j!:cval(list('iminus, a), env)
       else j!:builtin_two(u, env)
  end;

put('itimes2, 'j!:code, function j!:citimes2);

symbolic procedure j!:cminus(u, env);
  begin
    scalar a, b;
    a := s!:improve cadr u;
    return if numberp a then j!:cval(-a, env)
       else if eqcar(a, 'minus) then j!:cval(cadr a, env)
       else j!:ccall(car u, cdr u, env)
  end;

put('minus, 'j!:code, function j!:cminus);

symbolic procedure j!:ceq(x, env);
  begin
    scalar a1, a2, r, rr;
    a1 := s!:improve cadr x;
    a2 := s!:improve caddr x;
    if a1 = nil then return j!:cval(list('null, a2), env)
    else if a2 = nil then return j!:cval(list('null, a1), env);
    rr := j!:pareval(list(a1, a2), env);
    j!:outop('eq, r:=j!:newreg(), car rr, cadr rr);
    return r
  end;

put('eq, 'j!:code, function j!:ceq);

symbolic procedure j!:cequal(x, env);
  begin
    scalar a1, a2, r, rr;
    a1 := s!:improve cadr x;
    a2 := s!:improve caddr x;
    if a1 = nil then return j!:cval(list('null, a2), env)
    else if a2 = nil then return j!:cval(list('null, a1), env);
    rr := j!:pareval(list(a1, a2), env);
    j!:outop((if j!:eqvalid a1 or j!:eqvalid a2 then 'eq else 'equal),
          r:=j!:newreg(), car rr, cadr rr);
    return r
  end;

put('equal, 'j!:code, function j!:cequal);


%
% The next few cases are concerned with demoting functions that use
% equal tests into ones that use eq instead

symbolic procedure j!:is_fixnum x;
   fixp x and x >= -134217728 and x <= 134217727;

symbolic procedure j!:certainlyatom x;
   null x or x=t or j!:is_fixnum x or
   (eqcar(x, 'quote) and (symbolp cadr x or j!:is_fixnum cadr x));

symbolic procedure j!:atomlist1 u;
  atom u or
  ((symbolp car u or j!:is_fixnum car u) and j!:atomlist1 cdr u);

symbolic procedure j!:atomlist x;
  null x or
  (eqcar(x, 'quote) and j!:atomlist1 cadr x) or
  (eqcar(x, 'list) and
   (null cdr x or
    (j!:certainlyatom cadr x and
     j!:atomlist ('list . cddr x)))) or
  (eqcar(x, 'cons) and
   j!:certainlyatom cadr x and
   j!:atomlist caddr x);

symbolic procedure j!:atomcar x;
  (eqcar(x, 'cons) or eqcar(x, 'list)) and
  not null cdr x and
  j!:certainlyatom cadr x;

symbolic procedure j!:atomkeys1 u;
  atom u or
  (not atom car u and
   (symbolp caar u or j!:is_fixnum caar u) and 
   j!:atomlist1 cdr u);

symbolic procedure j!:atomkeys x;
  null x or
  (eqcar(x, 'quote) and j!:atomkeys1 cadr x) or
  (eqcar(x, 'list) and
   (null cdr x or
    (j!:atomcar cadr x and
     j!:atomkeys ('list . cddr x)))) or
  (eqcar(x, 'cons) and
   j!:atomcar cadr x and
   j!:atomkeys caddr x);

!#if (not common!-lisp!-mode)

symbolic procedure j!:comsublis x;
   if j!:atomkeys cadr x then 'subla . cdr x
   else nil;

put('sublis, 'j!:compile_macro, function j!:comsublis);

symbolic procedure j!:comassoc x;
   if j!:certainlyatom cadr x or j!:atomkeys caddr x then 'atsoc . cdr x
   else nil;

put('assoc, 'j!:compile_macro, function j!:comassoc);
put('assoc!*!*, 'j!:compile_macro, function j!:comassoc);

symbolic procedure j!:commember x;
   if j!:certainlyatom cadr x or j!:atomlist caddr x then 'memq . cdr x
   else nil;

put('member, 'j!:compile_macro, function j!:commember);

symbolic procedure j!:comdelete x;
   if j!:certainlyatom cadr x or j!:atomlist caddr x then 'deleq . cdr x
   else nil;

put('delete, 'j!:compile_macro, function j!:comdelete);

!#endif

symbolic procedure j!:ctestif(x, env, d1, d2);
  begin
    scalar l1, l2;
    l1 := j!:my_gensym();
    l2 := j!:my_gensym();
    j!:jumpif(cadr x, l1, l2);
    x := cddr x;
    j!:startblock l1;
    j!:jumpif(car x, d1, d2);
    j!:startblock l2;
    j!:jumpif(cadr x, d1, d2)
  end;

put('if, 'j!:ctest, function j!:ctestif);

symbolic procedure j!:ctestnull(x, env, d1, d2);
  j!:cjumpif(cadr x, env, d2, d1);

put('null, 'j!:ctest, function j!:ctestnull);
put('not, 'j!:ctest, function j!:ctestnull);

symbolic procedure j!:ctestatom(x, env, d1, d2);
  begin
    x := j!:cval(cadr x, env);
    j!:endblock(list('ifatom, x), list(d1, d2))
  end;

put('atom, 'j!:ctest, function j!:ctestatom);

symbolic procedure j!:ctestconsp(x, env, d1, d2);
  begin
    x := j!:cval(cadr x, env);
    j!:endblock(list('ifatom, x), list(d2, d1))
  end;

put('consp, 'j!:ctest, function j!:ctestconsp);

symbolic procedure j!:ctestsymbol(x, env, d1, d2);
  begin
    x := j!:cval(cadr x, env);
    j!:endblock(list('ifsymbol, x), list(d1, d2))
  end;

put('idp, 'j!:ctest, function j!:ctestsymbol);

symbolic procedure j!:ctestnumberp(x, env, d1, d2);
  begin
    x := j!:cval(cadr x, env);
    j!:endblock(list('ifnumber, x), list(d1, d2))
  end;

put('numberp, 'j!:ctest, function j!:ctestnumberp);

symbolic procedure j!:ctestizerop(x, env, d1, d2);
  begin
    x := j!:cval(cadr x, env);
    j!:endblock(list('ifizerop, x), list(d1, d2))
  end;

put('izerop, 'j!:ctest, function j!:ctestizerop);

symbolic procedure j!:ctesteq(x, env, d1, d2);
  begin
    scalar a1, a2, r;
    a1 := cadr x;
    a2 := caddr x;
    if a1 = nil then return j!:cjumpif(a2, env, d2, d1)
    else if a2 = nil then return j!:cjumpif(a1, env, d2, d1);
    r := j!:pareval(list(a1, a2), env);
    j!:endblock('ifeq . r, list(d1, d2))
  end;

put('eq, 'j!:ctest, function j!:ctesteq);

symbolic procedure j!:ctesteqcar(x, env, d1, d2);
  begin
    scalar a1, a2, r, d3;
    a1 := cadr x;
    a2 := caddr x;
    d3 := j!:my_gensym();
    r := j!:pareval(list(a1, a2), env);
    j!:endblock(list('ifatom, car r), list(d2, d3));
    j!:startblock d3;
    j!:outop('qcar, car r, nil, car r);
    j!:endblock('ifeq . r, list(d1, d2))
  end;

put('eqcar, 'j!:ctest, function j!:ctesteqcar);

global '(least_fixnum greatest_fixnum);

least_fixnum := -expt(2, 27);
greatest_fixnum := expt(2, 27) - 1;

symbolic procedure j!:small_number x;
  fixp x and x >= least_fixnum and x <= greatest_fixnum;

symbolic procedure j!:eqvalid x;
  if atom x then j!:small_number x
  else if flagp(car x, 'j!:fixnum_fn) then t
  else car x = 'quote and (idp cadr x or j!:small_number cadr x);

flag('(iplus iplus2 idifference iminus itimes itimes2), 'j!:fixnum_fn);

symbolic procedure j!:ctestequal(x, env, d1, d2);
  begin
    scalar a1, a2, r;
    a1 := s!:improve cadr x;
    a2 := s!:improve caddr x;
    if a1 = nil then return j!:cjumpif(a2, env, d2, d1)
    else if a2 = nil then return j!:cjumpif(a1, env, d2, d1);
    r := j!:pareval(list(a1, a2), env);
    j!:endblock((if j!:eqvalid a1 or j!:eqvalid a2 then 'ifeq else 'ifequal) .
                  r, list(d1, d2))
  end;

put('equal, 'j!:ctest, function j!:ctestequal);

symbolic procedure j!:ctestneq(x, env, d1, d2);
  begin
    scalar a1, a2, r;
    a1 := s!:improve cadr x;
    a2 := s!:improve caddr x;
    if a1 = nil then return j!:cjumpif(a2, env, d1, d2)
    else if a2 = nil then return j!:cjumpif(a1, env, d1, d2);
    r := j!:pareval(list(a1, a2), env);
    j!:endblock((if j!:eqvalid a1 or j!:eqvalid a2 then 'ifeq else 'ifequal) .
                  r, list(d2, d1))
  end;

put('neq, 'j!:ctest, function j!:ctestneq);

symbolic procedure j!:ctestilessp(x, env, d1, d2);
  begin
    scalar r;
    r := j!:pareval(list(cadr x, caddr x), env);
    j!:endblock('ifilessp . r, list(d1, d2))
  end;

put('ilessp, 'j!:ctest, function j!:ctestilessp);

symbolic procedure j!:ctestigreaterp(x, env, d1, d2);
  begin
    scalar r;
    r := j!:pareval(list(cadr x, caddr x), env);
    j!:endblock('ifigreaterp . r, list(d1, d2))
  end;

put('igreaterp, 'j!:ctest, function j!:ctestigreaterp);

symbolic procedure j!:ctestand(x, env, d1, d2);
  begin
    scalar next;
    for each a in cdr x do <<
      next := j!:my_gensym();
      j!:cjumpif(a, env, next, d2);
      j!:startblock next >>;
    j!:endblock('goto, list d1)
  end;

put('and, 'j!:ctest, function j!:ctestand);

symbolic procedure j!:ctestor(x, env, d1, d2);
  begin
    scalar next;
    for each a in cdr x do <<
      next := j!:my_gensym();
      j!:cjumpif(a, env, d1, next);
      j!:startblock next >>;
    j!:endblock('goto, list d2)
  end;

put('or, 'j!:ctest, function j!:ctestor);

% Here are some of the things that are built into the Lisp kernel
% and that I am happy to allow the compiler to generate direct calls to.
% But NOTE that if any of these were callable with eg either 1 or 2 args
% I would need DIFFERENT C entrypoints for each such case. To that effect
% I need to change this to have
%      j!:c_entrypoint1, j!:c_entrypoint2 and j!:c_entrypointn
% rather than a single property name.

fluid '(j!:c_entrypoint_list);

null (j!:c_entrypoint_list := '(
   (abs                    j!:c_entrypoint "Labsval")
%  (acons                  j!:c_entrypoint "Lacons")
%  (add1                   j!:c_entrypoint "Ladd1")
%  (apply                  j!:c_entrypoint "Lapply")
   (apply0                 j!:c_entrypoint "Lapply0")
   (apply1                 j!:c_entrypoint "Lapply1")
   (apply2                 j!:c_entrypoint "Lapply2")
   (apply3                 j!:c_entrypoint "Lapply3")
%  (ash                    j!:c_entrypoint "Lash")
   (ash1                   j!:c_entrypoint "Lash1")
   (atan                   j!:c_entrypoint "Latan")
   (atom                   j!:c_entrypoint "Latom")
   (atsoc                  j!:c_entrypoint "Latsoc")
   (batchp                 j!:c_entrypoint "Lbatchp")
   (boundp                 j!:c_entrypoint "Lboundp")
   (bps!-putv              j!:c_entrypoint "Lbpsputv")
   (caaaar                 j!:c_entrypoint "Lcaaaar")
   (caaadr                 j!:c_entrypoint "Lcaaadr")
   (caaar                  j!:c_entrypoint "Lcaaar")
   (caadar                 j!:c_entrypoint "Lcaadar")
   (caaddr                 j!:c_entrypoint "Lcaaddr")
   (caadr                  j!:c_entrypoint "Lcaadr")
   (caar                   j!:c_entrypoint "Lcaar")
   (cadaar                 j!:c_entrypoint "Lcadaar")
   (cadadr                 j!:c_entrypoint "Lcadadr")
   (cadar                  j!:c_entrypoint "Lcadar")
   (caddar                 j!:c_entrypoint "Lcaddar")
   (cadddr                 j!:c_entrypoint "Lcadddr")
   (caddr                  j!:c_entrypoint "Lcaddr")
   (cadr                   j!:c_entrypoint "Lcadr")
   (car                    j!:c_entrypoint "Lcar")
   (cdaaar                 j!:c_entrypoint "Lcdaaar")
   (cdaadr                 j!:c_entrypoint "Lcdaadr")
   (cdaar                  j!:c_entrypoint "Lcdaar")
   (cdadar                 j!:c_entrypoint "Lcdadar")
   (cdaddr                 j!:c_entrypoint "Lcdaddr")
   (cdadr                  j!:c_entrypoint "Lcdadr")
   (cdar                   j!:c_entrypoint "Lcdar")
   (cddaar                 j!:c_entrypoint "Lcddaar")
   (cddadr                 j!:c_entrypoint "Lcddadr")
   (cddar                  j!:c_entrypoint "Lcddar")
   (cdddar                 j!:c_entrypoint "Lcdddar")
   (cddddr                 j!:c_entrypoint "Lcddddr")
   (cdddr                  j!:c_entrypoint "Lcdddr")
   (cddr                   j!:c_entrypoint "Lcddr")
   (cdr                    j!:c_entrypoint "Lcdr")
   (char!-code             j!:c_entrypoint "Lchar_code")
   (close                  j!:c_entrypoint "Lclose")
   (codep                  j!:c_entrypoint "Lcodep")
   (constantp              j!:c_entrypoint "Lconstantp")
%  (cons                   j!:c_entrypoint "Lcons")
   (date                   j!:c_entrypoint "Ldate")
   (deleq                  j!:c_entrypoint "Ldeleq")
%  (difference             j!:c_entrypoint "Ldifference2")
   (digit                  j!:c_entrypoint "Ldigitp")
   (eject                  j!:c_entrypoint "Leject")
   (endp                   j!:c_entrypoint "Lendp")
   (eq                     j!:c_entrypoint "Leq")
   (eqcar                  j!:c_entrypoint "Leqcar")
   (eql                    j!:c_entrypoint "Leql")
   (eqn                    j!:c_entrypoint "Leqn")
%  (error                  j!:c_entrypoint "Lerror")
   (error1                 j!:c_entrypoint "Lerror0")   % !!!
%  (errorset               j!:c_entrypoint "Lerrorset")
   (evenp                  j!:c_entrypoint "Levenp")
   (evlis                  j!:c_entrypoint "Levlis")
   (explode                j!:c_entrypoint "Lexplode")
   (explode2               j!:c_entrypoint "Lexplodec")
   (explodec               j!:c_entrypoint "Lexplodec")
   (expt                   j!:c_entrypoint "Lexpt")
   (fix                    j!:c_entrypoint "Ltruncate")
   (fixp                   j!:c_entrypoint "Lfixp")
   (flag                   j!:c_entrypoint "Lflag")
   (flagp!*!*              j!:c_entrypoint "Lflagp")
   (flagp                  j!:c_entrypoint "Lflagp")
   (flagpcar               j!:c_entrypoint "Lflagpcar")
   (float                  j!:c_entrypoint "Lfloat")
   (floatp                 j!:c_entrypoint "Lfloatp")
   (fluidp                 j!:c_entrypoint "Lsymbol_specialp")
   (gcdn                   j!:c_entrypoint "Lgcd")
   (gctime                 j!:c_entrypoint "Lgctime")
   (gensym                 j!:c_entrypoint "Lgensym")
   (gensym1                j!:c_entrypoint "Lgensym1")
   (geq                    j!:c_entrypoint "Lgeq")
   (get!*                  j!:c_entrypoint "Lget")
%  (get                    j!:c_entrypoint "Lget")
   (getenv                 j!:c_entrypoint "Lgetenv")
   (getv                   j!:c_entrypoint "Lgetv")
   (svref                  j!:c_entrypoint "Lgetv")
   (globalp                j!:c_entrypoint "Lsymbol_globalp")
   (greaterp               j!:c_entrypoint "Lgreaterp")
   (iadd1                  j!:c_entrypoint "Liadd1")
   (idifference            j!:c_entrypoint "Lidifference")
   (idp                    j!:c_entrypoint "Lsymbolp")
   (igreaterp              j!:c_entrypoint "Ligreaterp")
   (ilessp                 j!:c_entrypoint "Lilessp")
   (iminus                 j!:c_entrypoint "Liminus")
   (iminusp                j!:c_entrypoint "Liminusp")
   (indirect               j!:c_entrypoint "Lindirect")
   (integerp               j!:c_entrypoint "Lintegerp")
   (iplus2                 j!:c_entrypoint "Liplus2")
   (iquotient              j!:c_entrypoint "Liquotient")
   (iremainder             j!:c_entrypoint "Liremainder")
   (irightshift            j!:c_entrypoint "Lirightshift")
   (isub1                  j!:c_entrypoint "Lisub1")
   (itimes2                j!:c_entrypoint "Litimes2")
%  (lcm                    j!:c_entrypoint "Llcm")
   (length                 j!:c_entrypoint "Llength")
   (lengthc                j!:c_entrypoint "Llengthc")
   (leq                    j!:c_entrypoint "Lleq")
   (lessp                  j!:c_entrypoint "Llessp")
   (linelength             j!:c_entrypoint "Llinelength")
%  (list2!*                j!:c_entrypoint "Llist2star")
%  (list2                  j!:c_entrypoint "Llist2")
%  (list3                  j!:c_entrypoint "Llist3")
   (load!-module           j!:c_entrypoint "Lload_module")
%  (lognot                 j!:c_entrypoint "Llognot")
   (lposn                  j!:c_entrypoint "Llposn")
   (macro!-function        j!:c_entrypoint "Lmacro_function")
   (macroexpand!-1         j!:c_entrypoint "Lmacroexpand_1")
   (macroexpand            j!:c_entrypoint "Lmacroexpand")
   (make!-bps              j!:c_entrypoint "Lget_bps")
   (make!-global           j!:c_entrypoint "Lmake_global")
   (make!-simple!-string   j!:c_entrypoint "Lsmkvect")
   (make!-special          j!:c_entrypoint "Lmake_special")
   (mapstore               j!:c_entrypoint "Lmapstore")
   (max2                   j!:c_entrypoint "Lmax2")
   (memq                   j!:c_entrypoint "Lmemq")
   (min2                   j!:c_entrypoint "Lmin2")
   (minus                  j!:c_entrypoint "Lminus")
   (minusp                 j!:c_entrypoint "Lminusp")
   (mkquote                j!:c_entrypoint "Lmkquote")
   (mkvect                 j!:c_entrypoint "Lmkvect")
   (mod                    j!:c_entrypoint "Lmod")
   (modular!-difference    j!:c_entrypoint "Lmodular_difference")
   (modular!-expt          j!:c_entrypoint "Lmodular_expt")
   (modular!-minus         j!:c_entrypoint "Lmodular_minus")
   (modular!-number        j!:c_entrypoint "Lmodular_number")
   (modular!-plus          j!:c_entrypoint "Lmodular_plus")
   (modular!-quotient      j!:c_entrypoint "Lmodular_quotient")
   (modular!-reciprocal    j!:c_entrypoint "Lmodular_reciprocal")
   (modular!-times         j!:c_entrypoint "Lmodular_times")
   (nconc                  j!:c_entrypoint "Lnconc")
%  (ncons                  j!:c_entrypoint "Lncons")
   (neq                    j!:c_entrypoint "Lneq")
%  (next!-random!-number   j!:c_entrypoint "Lnext_random")
   (not                    j!:c_entrypoint "Lnull")
   (null                   j!:c_entrypoint "Lnull")
   (numberp                j!:c_entrypoint "Lnumberp")
   (oddp                   j!:c_entrypoint "Loddp")
   (onep                   j!:c_entrypoint "Lonep")
   (orderp                 j!:c_entrypoint "Lorderp")
%  (ordp                   j!:c_entrypoint "Lorderp")
   (pagelength             j!:c_entrypoint "Lpagelength")
   (pairp                  j!:c_entrypoint "Lconsp")
   (plist                  j!:c_entrypoint "Lplist")
%  (plus2                  j!:c_entrypoint "Lplus2")
   (plusp                  j!:c_entrypoint "Lplusp")
   (posn                   j!:c_entrypoint "Lposn")
   (put                    j!:c_entrypoint "Lputprop")
   (putv!-char             j!:c_entrypoint "Lsputv")
   (putv                   j!:c_entrypoint "Lputv")
   (qcaar                  j!:c_entrypoint "Lcaar")
   (qcadr                  j!:c_entrypoint "Lcadr")
   (qcar                   j!:c_entrypoint "Lcar")
   (qcdar                  j!:c_entrypoint "Lcdar")
   (qcddr                  j!:c_entrypoint "Lcddr")
   (qcdr                   j!:c_entrypoint "Lcdr")
   (qgetv                  j!:c_entrypoint "Lgetv")
%  (quotient               j!:c_entrypoint "Lquotient")
%  (random                 j!:c_entrypoint "Lrandom")
%  (rational               j!:c_entrypoint "Lrational")
   (rds                    j!:c_entrypoint "Lrds")
   (reclaim                j!:c_entrypoint "Lgc")
%  (remainder              j!:c_entrypoint "Lrem")
   (remd                   j!:c_entrypoint "Lremd")
   (remflag                j!:c_entrypoint "Lremflag")
   (remob                  j!:c_entrypoint "Lunintern")
   (remprop                j!:c_entrypoint "Lremprop")
   (reverse                j!:c_entrypoint "Lreverse")
   (reversip               j!:c_entrypoint "Lnreverse")
   (rplaca                 j!:c_entrypoint "Lrplaca")
   (rplacd                 j!:c_entrypoint "Lrplacd")
   (schar                  j!:c_entrypoint "Lsgetv")
   (seprp                  j!:c_entrypoint "Lwhitespace_char_p")
   (set!-small!-modulus    j!:c_entrypoint "Lset_small_modulus")
   (set                    j!:c_entrypoint "Lset")
   (smemq                  j!:c_entrypoint "Lsmemq")
   (spaces                 j!:c_entrypoint "Lxtab")
   (special!-char          j!:c_entrypoint "Lspecial_char")
   (special!-form!-p       j!:c_entrypoint "Lspecial_form_p")
   (spool                  j!:c_entrypoint "Lspool")
   (stop                   j!:c_entrypoint "Lstop")
   (stringp                j!:c_entrypoint "Lstringp")
%  (sub1                   j!:c_entrypoint "Lsub1")
   (subla                  j!:c_entrypoint "Lsubla")
   (subst                  j!:c_entrypoint "Lsubst")
   (symbol!-env            j!:c_entrypoint "Lsymbol_env")
   (symbol!-function       j!:c_entrypoint "Lsymbol_function")
   (symbol!-name           j!:c_entrypoint "Lsymbol_name")
   (symbol!-set!-definition j!:c_entrypoint "Lsymbol_set_definition")
   (symbol!-set!-env       j!:c_entrypoint "Lsymbol_set_env")
   (symbol!-value          j!:c_entrypoint "Lsymbol_value")
   (system                 j!:c_entrypoint "Lsystem")
   (terpri                 j!:c_entrypoint "Lterpri")
   (threevectorp           j!:c_entrypoint "Lthreevectorp")
   (time                   j!:c_entrypoint "Ltime")
%  (times2                 j!:c_entrypoint "Ltimes2")
   (ttab                   j!:c_entrypoint "Lttab")
   (tyo                    j!:c_entrypoint "Ltyo")
   (unmake!-global         j!:c_entrypoint "Lunmake_global")
   (unmake!-special        j!:c_entrypoint "Lunmake_special")
   (upbv                   j!:c_entrypoint "Lupbv")
   (verbos                 j!:c_entrypoint "Lverbos")
   (wrs                    j!:c_entrypoint "Lwrs")
   (xcons                  j!:c_entrypoint "Lxcons")
   (xtab                   j!:c_entrypoint "Lxtab")
%  (orderp                 j!:c_entrypoint "Lorderp") being retired.
   (zerop                  j!:c_entrypoint "Lzerop")

% The following can be called without having to provide an environment
% or arg-count.  The compiler should check the number of args being
% passed matches the expected number.

   (cons                   j!:direct_entrypoint (2 . "cons"))
   (ncons                  j!:direct_entrypoint (1 . "ncons"))
   (list2                  j!:direct_entrypoint (2 . "list2"))
   (list2!*                j!:direct_entrypoint (3 . "list2star"))
   (acons                  j!:direct_entrypoint (3 . "acons"))
   (list3                  j!:direct_entrypoint (3 . "list3"))
   (list3!*                j!:direct_entrypoint (4 . "list3star"))
   (list4                  j!:direct_entrypoint (4 . "list4"))
   (plus2                  j!:direct_entrypoint (2 . "plus2"))
   (difference             j!:direct_entrypoint (2 . "difference2"))
   (add1                   j!:direct_entrypoint (1 . "add1"))
   (sub1                   j!:direct_entrypoint (1 . "sub1"))
   (lognot                 j!:direct_entrypoint (1 . "lognot"))
   (ash                    j!:direct_entrypoint (2 . "ash"))
   (quotient               j!:direct_entrypoint (2 . "quot2"))
   (remainder              j!:direct_entrypoint (2 . "Cremainder"))
   (times2                 j!:direct_entrypoint (2 . "times2"))
   (minus                  j!:direct_entrypoint (1 . "negate"))
%  (rational               j!:direct_entrypoint (1 . "rational"))
   (lessp                  j!:direct_predicate (2 . "lessp2"))
   (leq                    j!:direct_predicate (2 . "lesseq2"))
   (greaterp               j!:direct_predicate (2 . "greaterp2"))
   (geq                    j!:direct_predicate (2 . "geq2"))
   (zerop                  j!:direct_predicate (1 . "zerop"))
   ))$

!#if common!-lisp!-mode
null (j!:c_entrypoint_list := append(j!:c_entrypoint_list, '(
   (!1!+                   j!:c_entrypoint "Ladd1")
   (equal                  j!:c_entrypoint "Lcl_equal")
   (!1!-                   j!:c_entrypoint "Lsub1")
   (vectorp                j!:c_entrypoint "Lvectorp"))))$
!#endif

!#if (not common!-lisp!-mode)
null (j!:c_entrypoint_list := append(j!:c_entrypoint_list, '(
   (append                 j!:c_entrypoint "Lappend")
   (assoc                  j!:c_entrypoint "Lassoc")
   (compress               j!:c_entrypoint "Lcompress")
   (delete                 j!:c_entrypoint "Ldelete")
   (divide                 j!:c_entrypoint "Ldivide")
   (equal                  j!:c_entrypoint "Lequal")
   (intern                 j!:c_entrypoint "Lintern")
   (liter                  j!:c_entrypoint "Lalpha_char_p")
   (member                 j!:c_entrypoint "Lmember")
   (prin                   j!:c_entrypoint "Lprin")
   (prin1                  j!:c_entrypoint "Lprin")
   (prin2                  j!:c_entrypoint "Lprinc")
   (princ                  j!:c_entrypoint "Lprinc")
   (print                  j!:c_entrypoint "Lprint")
   (printc                 j!:c_entrypoint "Lprintc")
   (read                   j!:c_entrypoint "Lread")
   (readch                 j!:c_entrypoint "Lreadch")
   (sublis                 j!:c_entrypoint "Lsublis")
   (vectorp                j!:c_entrypoint "Lsimple_vectorp")
   (get                    j!:direct_entrypoint (2 . "get")))))$
!#endif

for each x in j!:c_entrypoint_list do put(car x, cadr x, caddr x)$

flag(
 '(atom atsoc codep constantp deleq digit endp eq eqcar evenp
   eql fixp flagp flagpcar floatp get globalp iadd1 idifference idp
   igreaterp ilessp iminus iminusp indirect integerp iplus2 irightshift
   isub1 itimes2 liter memq minusp modular!-difference modular!-expt
   modular!-minus modular!-number modular!-plus modular!-times not
   null numberp onep pairp plusp qcaar qcadr qcar qcdar qcddr
   qcdr remflag remprop reversip seprp special!-form!-p stringp
   symbol!-env symbol!-name symbol!-value threevectorp vectorp zerop),
 'j!:no_errors);

end;

% End of jcomp.red

