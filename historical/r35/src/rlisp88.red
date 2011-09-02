module rlisp88;   % Support for the RLISP88 superset.

% Author:  Anthony C. Hearn.

fluid '(!*minusliter !*mode !*oldminusliter !*rlisp88 forbinops!*
        oldmode!*);

switch rlisp88;

create!-package('(rlisp88 for88 loops88 bquote Comment rvector mstruct
                  records inspector),
                '(rlisp));

symbolic procedure rlisp88_on;
   begin
      if !*rlisp88 then return nil;
      !*rlisp88 := t;
      !*oldminusliter := !*minusliter;
      !*minusliter := t;
      deflist('((module formmodule) (global formglobalfluid)
                (fluid formglobalfluid) (procedure nformproc)),
              'formfn);
      remprop('join,'newnam);
      put('conc,'newnam,'join);
      put('oldwhen,'infix,get('when,'infix));
      remprop('when,'infix);
      flag('(for),'nochange);   % Check on this.
      deflist(forbinops!*,'bin);
      deflist('((for forstat88) (repeat repeatstat88)
                (while whilstat88)),'stat);
      deflist('((for formfor88) (repeat formrepeat88)
                (while formwhile88)),'formfn);
      copyd('for,'for88);
      copyd('oldrepeat!*,'repeat);
      remd 'repeat;
      copyd('repeat,'repeat88);
      copyd('oldwhile!*,'while);
      remd 'while;   % To avoid messages.
      copyd('while,'while88);
      if not(!*mode eq 'symbolic)
        then <<oldmode!* := !*mode;  !*mode := 'symbolic>>;
      % The following statements, and their colloraries in rlisp88_off,
      % reveal problems with the current REDUCE model; it cannot specify
      % attributes in algebraic mode that do not apply in symbolic mode.
      % The following are representative, and by no means exhaustive.
      remprop('array,'stat);
      remprop('index,'stat);
      remprop('def,'stat);
      remprop('array,'formfn);
      remprop('add,'number!-of!-args);
      remprop('add,'smacro)
   end;

symbolic procedure rlisp88_off;
   begin
      if null !*rlisp88 then return nil
       else if null getd 'oldrepeat!*
        then rederr "Rlisp88 mode not set";
      !*minusliter := !*oldminusliter;
      remprop('module,'formfn);
      remprop('global,'formfn);
      remprop('fluid,'formfn);
      put('procedure,'formfn,'formproc);
      remprop('conc,'newnam);
      put('join,'newnam,'conc);
      put('when,'infix,get('oldwhen,'infix));
      remflag('(for),'nochange);
      for each x in '(append collect count join maximize minimize)
          do remprop(x,'bin);
      deflist('((product times2) (sum plus2)),'bin);
      deflist('((for forstat) (repeat repeatstat) (while whilstat)),
                'stat);
      deflist('((for formfor) (repeat formrepeat) (while formwhile)),
                'formfn);
      remd 'for;
      remd 'repeat;
      remd 'while;
      copyd('repeat,'oldrepeat!*);
      copyd('while,'oldwhile!*);
      remd 'oldrepeat!*;
      remd 'oldwhile!*;
      if oldmode!* then <<!*mode := oldmode!*; oldmode!* := nil>>;
      deflist('((array rlis) (def rlis) (index rlis)),'stat);
      put('array,'formfn,'formarray);
      put('add,'number!-of!-args,2);
      put('add,'smacro,'(lambda (u v) (cons u v)))
   end;

put('rlisp88,'simpfg,'((t (rlisp88_on)) (nil (rlisp88_off))));

endmodule;


module for88;   % Definition of Rlisp88 FOR statement.

% Author: Anthony C. Hearn.

fluid '(!*fastfor binops!* loopdelimslist!*);

global '(forkeywords!*);

flag('(fastfor),'switch);     % Since switch may not yet be defined.

Comment The FOR statement defined here has a very rich syntax with many
different options. The parsing and macro expansion are under the control
of keywords that are activated during parsing once FOR has been read.
The keywords are deactivated at the end of the FOR statement, enabling
them to be used as regular ID's in other parts of the program.

The next ID after FOR may define a different type of FOR loop. Such
different loops are indicated by the presence of the ID in the list
forloops!*;

deflist('((all forallstat)),'forloops!*);

Comment
Keywords are defined by their presence in the global list FORKEYWORDS!*.
For each keyword, a parsing construct is also defined under the
indicator FOR-KEYWORD.

The parsing phase of the analysis returns a form:

(FOR (<keyword> . <expression>) ... (<keyword> . <expression>));

forkeywords!* := '(collect count do each every finally in initially
                   join on product returns some step sum unless until
                   when with maximize minimize);

% Note: append used to be on the above list, but was removed since it
%       couldn't be distinguished from the function "append".

remflag(forkeywords!*,'delim);    % For bootstrapping purposes.

Comment some of the keywords denote actions (e.g., PRODUCT, SUM) with
which a binary function is associated. To associate such a function with
an action, one says;

forbinops!* := '((append append) (collect cons) (count plus2)
                 (join nconc) (maximize max2!*) (minimize min2!*)
                 (product times2) (sum plus2));

% NB:  We need to reset FOR and LET delims if an error occurs.  It's
% probably best to do this in the begin1 loop.

symbolic procedure forstat88;
   begin scalar !*blockp,x;
      if x := get(scan(),'forloops!*) then return lispapply(x,nil);
      loopdelimslist!* := forkeywords!* . loopdelimslist!*;
      flag(forkeywords!*,'delim);
      return 'for . if cursym!* neq 'each
                      then progn(x := forfrag(), x . fortail())
                     else fortail()
   end;

symbolic procedure forfrag;
   begin scalar incr,var,x;
      x := erroreval '(xread1 'for);
      if not eqcar(x,'setq) or not idp(var := cadr x)
        then symerr('for,t);
      x := caddr x;
      if cursym!* eq 'step
        then <<incr := erroreval '(xread t);
               if not cursym!* eq 'until then symerr('for,t)>>
       else if cursym!* eq '!*colon!* then incr := 1
       else symerr('for,t);
      return list('incr,var,x,erroreval '(xread t),incr)
%     if numberp incr and incr>0
%       then incr := list('from,var,x,erroreval '(xread t),incr)
%      else if eqcar(incr,'minus) and numberp cadr incr and cadr incr>0
%       then incr := list('down,var,x,erroreval '(xread t),cadr incr)
%      else rederr list("Increment",incr,"not supported");
%     return incr
   end;

symbolic procedure erroreval u;
   begin scalar x;
      x := errorset!*(u,t);
      if errorp x then error1() else return car x
   end;

symbolic procedure eachfrag;
   begin scalar x,y;
        if not idp(x := scan()) or not (y := scan()) memq '(in on)
          then symerr("For each",t);
        return list(y,x,erroreval '(xread t));
   end;

symbolic procedure fortail;
   begin scalar x,y,z,z1;
   a:   z1 := cursym!*;
        if z1 eq 'each
          then if not idp(x := scan())
                   or not (y := scan()) memq '(in on)
                 then symerr("FOR EACH",t)
                else <<z := list(y,x,erroreval '(xread t)) . z;
                       go to a>>
         else if z1 eq 'with
          then z := (z1 . erroreval '(xread 'lambda)) . z
         else if z1 eq '!*semicol!* then symerr("FOR EACH",t)
         else z := (z1 . erroreval '(xread t)) . z;
        if cursym!* memq forkeywords!* then go to a;
        remflag(car loopdelimslist!*,'delim);
        loopdelimslist!* := cdr loopdelimslist!*;
        if loopdelimslist!* then flag(car loopdelimslist!*,'delim);
        return reversip z
   end;

symbolic procedure formfor88(u,vars,mode);
   begin scalar x,z;
      u := z := cdr u;
      % First check for local vars.
   a: if null z then go to b;
      x := car z;
      if car x memq '(down from incr in on)
        then vars := (cadr x . 'scalar) . vars
       else if car x eq 'with
        then vars := nconc(mapcar(remcomma cdr x,
                                  function (lambda j; j . 'scalar)),
                           vars);
      z := cdr z;
      go to a;
      % Now do actual analysis.
   b: if null u then return 'for . reversip z;
      x := car u;
      if car x memq '(down from incr)
        % We could optimize this by recognizing integers.
        then z := (car x . cadr x . formclis(cddr x,vars,mode)) . z
       else if car x eq 'with then z := (car x . remcomma cdr x) . z
       else if car x memq '(in on)
        then z := (car x . list(cadr x,formc(caddr x,vars,mode))) . z
       else z := (car x . formc(cdr x,vars,mode)) . z;
      u := cdr u;
      go to b
   end;

symbolic macro procedure for88 x;
   begin scalar lvars,init,init2,final,body,!$cond,rets,cur,!$when,
                !*maxminflag,next,!$label2,!$while,cx,iv,action,curvar,
                valuevar,y;
      x := cdr x;
      action := caar x;
      !$label2 := gensym();
   loop:
      if null x
        then <<final := mkfn(final,'progn);
               next := mkfn(next,'progn);
               !$cond := mkfn(!$cond,'or);
               cur := mkfn(cur,'progn);
               body := mkfn(body,'progn);
               if !$while
                 then !$while := forcond
                                   sublis(pair('(!$while final rets),
                                             list(mkfn(!$while,'or),
                                                  final,rets)),
                                                '(!$while final
                                                  (return rets)));
               if !$when
                 then body := forcond list(!$when,body);
               if !*maxminflag then rets := list('null2zero,rets);
               return forprog(lvars .
                          nconc(init,
                                nconc(init2,
                      sublis(pair('(final body !$cond rets cur next
                                    !$label !$label2 !$while),
                                  list(final,body,!$cond,rets,cur,next,
                                       gensym(),!$label2,!$while)),
                               if final then
                                '(!$label
                                     (cond (!$cond
                                           (progn final (return rets))))
                                     cur
                                     !$while
                                     body
                                  !$label2
                                     next
                                     (go !$label))
                               else
                                '(!$label
                                     (cond (!$cond (return rets)))
                                     cur
                                     !$while
                                     body
                                  !$label2
                                     next
                                     (go !$label))))))>>;
      cx := car x;
      if atom cx then rederr list(cx,"invalid in FOR form")
      % WITH tacks its variables onto the !$LVARS list
       else if car cx eq 'with
        then lvars := append(lvars,cdr cx)
      % INITIALLY takes its expressions and tacks them onto the list of
      % INIT.  This will later be built into a PROGN.
       else if car cx eq 'initially
        then init := aconc(init,cdr cx)
      % FINALLY puts its expressions on the list of FINAL.
      % This becomes a PROGN that is created just before the RETURN.
       else if car cx eq 'finally
        then final := aconc(final,cdr cx)
      % ON
       else if car cx eq 'on
        then <<valuevar := cadr cx;
               lvars := valuevar . lvars;
               !$cond := list('null,valuevar) . !$cond;
               init := list('setq,valuevar,caddr cx) . init;
               if cdddr cx
                 then next := list('setq,valuevar,cadddr x) . next
                else next := list('setq, valuevar,list('cdr,valuevar))
                                  . next>>
      % IN
       else if car cx eq 'in
        then <<valuevar := gensym();
               iv := cadr cx;
               lvars := valuevar . iv . lvars;
               init := list('setq,valuevar,caddr cx) . init;
               !$cond := list('null,valuevar) . !$cond;
               cur := list('setq,iv,list('car,valuevar)) . cur;
               if cdddr cx
                 then next := list('setq,valuevar,list cadddr cx) . next
                else next := list('setq,valuevar,list('cdr,valuevar))
                                . next>>
       % INCR
       else if car cx eq 'incr
        then begin scalar incr,incrvar;
                valuevar := cadr cx;
                cx := cddr cx;
                lvars := valuevar . lvars;
                init := list('setq,valuevar,car cx) . init;
                incr := caddr cx;
                if numberp incr then nil             % Assume positive?
                 else if eqcar(incr,'minus) and numberp cadr incr
                  then incr := - cadr incr
                 else <<incrvar := gensym();
                        lvars := incrvar . lvars;
                        init := list('setq,incrvar,incr) . init;
                        incr := incrvar>>;
                !$cond :=
                   (if incrvar
                      then list('cond,list(list('minusp,incr),
                                         list('lessp,valuevar,cadr cx)),
                                        list('t,list('greaterp,valuevar,
                                                     cadr cx)))
                     else if minusp incr
                      then if !*fastfor
                             then list('ilessp,valuevar,cadr cx)
                            else list('lessp,valuevar,cadr cx)
                     else if !*fastfor
                      then list('igreaterp,valuevar,cadr cx)
                     else list('greaterp,valuevar,cadr cx))
                    . !$cond;
                next := list('setq,valuevar,
                             list(if incrvar or not !*fastfor
                                    then 'plus
                                   else 'iplus,
                                  valuevar,incr)) . next
              end
      % SUM, PRODUCT etc.
       else if car cx memq '(sum product append join count collect
                             maximize minimize)
        then <<curvar := gensym();
               lvars := curvar . lvars;
               % Set up initial value for loop.
               if car cx eq 'product
                 then init := aconc!*(init,list('setq,curvar,1))
                else if car cx memq '(count sum)
                 then init := aconc!*(init,list('setq,curvar,0))
                else if car cx memq '(maximize minimize)
                 then <<!*maxminflag := t;
                        %y := list(list('setq,curvar,cdr cx),
                        %            list('go,!$label2));
                        if action eq 'in
                          then y :=
                              list('setq,iv,list('car,valuevar)); % . y;
                        if action memq '(in on)
                         then y :=
                                 list('cond,list(list('null,valuevar),
                                      '(return 0)))
                               . y;
                       nconc!*(init,y)>>;
               if car cx eq 'collect
                 then rets := list('reversip,curvar)
                else rets := curvar;
               body := list('setq,curvar,
                            list(get(car cx,'bin),
                if car cx memq '(append count join) then curvar
                 else cdr cx,
                if car cx memq '(append join) then cdr cx
                 else if car cx eq 'count
                  then list('cond,list(cdr cx,1),'(t 0))
                 else curvar))
                       . body>>
      % RETURNS
       else if car cx eq 'returns then rets := cdr cx
      % DO
       else if car cx eq 'do then body := aconc(body,cdr cx)
      % WHEN
       else if car cx eq 'when
        then if !$when
               then symerr("Redundant WHEN or UNLESS in FOR statement",
                           nil)
              else !$when := cdr cx
      % UNLESS
       else if car cx eq 'unless
        then if !$when
               then symerr("Redundant WHEN or UNLESS in FOR statement",
                           nil)
              else !$when := list('not,cdr cx)
      % WHILE
%      else if car cx eq 'while
%       then !$while := append(!$while,list list('not,cdr cx))
      % UNTIL
       else if car cx eq 'until
        then !$while := append(!$while,list cdr cx)
      % SOME
       else if car cx eq 'some
        then cur := append(cur,
                          list list('cond,list(cdr cx,list('return,t))))
      % EVERY
       else if car cx eq 'every
        then <<if not rets then rets := t;
               cur := append(cur,
                             list list('cond,list(list('null,cdr cx),
                                                  list('return,nil))))>>
       else rederr list(car cx,"invalid in FOR form");
      x := cdr x;
      go to loop
   end;

symbolic procedure forcond u;
   list('cond,list(car u,if cddr u then 'progn . cdr u else cadr u));

symbolic procedure forprog u;
   'prog . fornilchk u;

symbolic procedure fornilchk u;
   if null u then nil
    else if null car u then fornilchk cdr u
    else car u . fornilchk cdr u;

symbolic procedure max2!*(u,v); if null v then u else max2(u,v);

symbolic procedure min2!*(u,v); if null v then u else min2(u,v);

symbolic procedure null2zero u; if null u then 0 else u;

symbolic procedure mkfn(x,fn);
  if atom x then x else if length x>1 then fn . x else car x;

endmodule;


module loops88;  % Rlisp88 looping forms other than the FOR statement.

% Author: Anthony C. Hearn.

fluid '(!*blockp loopdelimslist!*);

global '(cursym!* repeatkeywords!* whilekeywords!*);


% ***** REPEAT STATEMENT *****

repeatkeywords!* := '(finally initially returns until with);

symbolic procedure repeatstat88;
  begin scalar body,!*blockp,x,y,z;
      loopdelimslist!* := repeatkeywords!* . loopdelimslist!*;
      flag(repeatkeywords!*,'delim);
      body := erroreval '(xread t);
      if not (cursym!* memq repeatkeywords!*) then symerr('repeat,t);
  a:  x := cursym!*;
      y := erroreval if x eq 'with then '(xread 'lambda)
                      else '(xread t);
      z := (x . y) . z;
      if cursym!* memq repeatkeywords!* then go to a;
      remflag(car loopdelimslist!*,'delim);
      loopdelimslist!* := cdr loopdelimslist!*;
      if loopdelimslist!* then flag(car loopdelimslist!*,'delim);
      return 'repeat . body . reversip z
   end;

symbolic macro procedure repeat88 u;
   begin scalar body,lab,xwith;
        body := cadr u; u := cddr u;
        xwith := atsoc('with,u);
        return sublis(pair('(!$locals !$do !$rets !$inits !$fins !$bool
                             !$label),
                           list(if xwith then cdr xwith else nil,
                                body,
                                x!-car x!-cdr atsoc('returns,u),
                                mkfn(x!-cdr atsoc('initially,u),'progn),
                                mkfn(x!-cdr atsoc('finally,u),'progn),
                                x!-car x!-cdr atsoc('until,u),
                                gensym())),
                      '(prog !$locals
                             !$inits
                        !$label !$do
                             (cond (!$bool !$fins (return !$rets)))
                             (go !$label)))
   end;

symbolic procedure remcomma!* u; if null u then nil else remcomma cdr u;

symbolic procedure x!-car u; if atom u then u else car u;

symbolic procedure x!-cdr u; if null u then nil else list cdr u;

% flag('(repeat),'nochange);

symbolic procedure formrepeat88(u,vars,mode);
   begin scalar y,z;
      for each x in cddr u do
         if car x eq 'with
           then <<y := remcomma cdr x;
                  vars := nconc(mapcar(y,function (lambda j;
                                                 j . 'scalar))
                                ,vars);
                  z := (car x . y) . z>>
%         else if car x eq 'until
%          then z := (car x . formbool(cdr x,vars,mode)) . z
          else z := (car x . formc(cdr x,vars,mode)) . z;
      return 'repeat . formc(cadr u,vars,mode) . reversip z
   end;


% ***** WHILE STATEMENT *****

whilekeywords!* := '(collect do finally initially returns with);

symbolic procedure whilstat88;
   begin scalar !*blockp,bool1,x,y,z;
      loopdelimslist!* := whilekeywords!* . loopdelimslist!*;
      flag(whilekeywords!*,'delim);
      bool1 := erroreval '(xread t);
      if not (cursym!* memq whilekeywords!*) then symerr('while,t);
  a:  x := cursym!*;
      y := erroreval if x eq 'with then '(xread 'lambda)
                      else '(xread t);
      z := (x . y) . z;
      if cursym!* memq whilekeywords!* then go to a;
      remflag(car loopdelimslist!*,'delim);
      loopdelimslist!* := cdr loopdelimslist!*;
      if loopdelimslist!* then flag(car loopdelimslist!*,'delim);
      return 'while . bool1 . reversip z
   end;

symbolic macro procedure while88 u;
   begin scalar body,bool,lab,rets,vars;
      bool := cadr u; u := cddr u;
      rets := x!-car x!-cdr atsoc('returns,u);
      vars := x!-car x!-cdr atsoc('with,u);
      if body := atsoc('collect,u)
        then <<vars := gensym() . vars;
               body := list('setq,
                            car vars,
                            list('cons,cdr body,car vars));
               if rets then rederr "While loop value conflict";
               rets := list('reversip,car vars)>>
       else if body := atsoc('do,u) then body := cdr body
       else rederr "Missing body in WHILE statement";
      return sublis(pair('(!$locals !$do !$rets !$inits !$fins !$bool
                           !$label),
                         list(vars,
                              body,
                              rets,
                              mkfn(x!-cdr atsoc('initially,u),'progn),
                              mkfn(x!-cdr atsoc('finally,u),'progn),
                              bool,
                              gensym())),
                    '(prog !$locals
                           !$inits
                      !$label
                           (cond ((not !$bool) !$fins (return !$rets)))
                           !$do
                           (go !$label)))
   end;

% flag('(while),'nochange);

symbolic procedure formwhile88(u,vars,mode);
   begin scalar y,z;
      for each x in cddr u do
         if car x eq 'with
           then <<y := remcomma cdr x;
                  vars := nconc(mapcar(y,function
                                            (lambda j; j . 'scalar)),
                                vars);
                  z := (car x . y) . z>>
          else z := (car x . formc(cdr x,vars,mode)) . z;
      return 'while . formc(cadr u,vars,mode) . reversip z
   end;

endmodule;


module bquote;   % Support for backquote.

% Author:  Anthony C. Hearn.

% Copyright (c) 1993 The RAND Corporation.  All rights reserved.

% Lisp parsing case.

symbolic procedure tokbquote;
   begin
     crchar!* := readch1();
      nxtsym!* := list('backq,rread());
      ttype!* := 3;
      return nxtsym!*
   end;

put('!`,'tokprop,'tokbquote);

put('backq,'formfn,'formbquote);

symbolic procedure formbquote(u,vars,mode); mkbquote cadr u;

symbolic procedure mkbquote u;
   % Returns the "unevaled" form of u.
   if null u or constantp u then u
    else if atom u then mkquote u
    else if car u eq 'quote
     then if cadr u eq '!# then rederr "Invalid use of # after '"
           else mkquote u
    else if car u eq 'listify then mkbquote cdr u
    else if car u eq '!#
     then if eqcar(cdr u,'!@)
            then if null cdddr u then caddr u
                  else list('append,caddr u,mkbquote cdddr u)
           else list('cons,cadr u,mkbquote cddr u)
    else if car u eq '!@ then rederr "Invalid use of @"
    else list('cons,mkbquote car u,mkbquote cdr u);


% Rlisp parsing case.

put('backquote,'stat,'bquotstat);

symbolic procedure bquotstat; list('backquote,rl2l cadr rlis());

symbolic procedure rl2l u;
   if atom u then u
    else if atom car u then car u . rl2l cdr u
    else if caar u eq 'hash or caar u eq '!#
     then if eqcar(cadar u,'!@)
            then '!# . '!@ . cadr cadar u . rl2l cdr u
           else '!# . cadar u . rl2l cdr u
    else rl2l car u . rl2l cdr u;

put('backquote,'formfn,'formbquote);

endmodule;


module Comment;   % Routines for handling active comments.

% Author:  Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

% This module supports the concept of active comments. Such comments are
% delimited by the comment brackets /* and */.  Everything read between
% those brackets is converted to a string (including eol), and the
% expression returned as the list (*comment* <comment string>).

symbolic procedure read!-Comment;
   begin scalar raise,x,y,z;
      raise := !*raise;
      !*raise := nil;
      z := list(crchar!*,'!");
   a: if (x := readch()) eq '!*
        then if (y := readch()) eq '!/ then go to b
              else z := y . x . z
       else if x = !$eof!$
        then <<!*raise := raise; rederr "EOF encountered in comment">>
       else z := x . z;
      go to a;
   b:
      !*raise := raise;
      crchar!* := readch();
      z := '!" . z;
      return list('!*Comment!*,mkstrng compress reversip z)
   end;

newtok '((!/ !*) !*Comment!*);

endmodule;


module rvector; % Definition of RLISP vectors and operations on them.

% Author: Anthony C. Hearn.

% Copyright (c) 1990 The RAND Corporation.  All rights reserved.

fluid '(!*fastvector);

global '(cursym!*);

switch fastvector;

% Add to system table.

flag('(vec!*),'vecfn);

% Parsing interface.

symbolic procedure xreadvec;
   % Expects a list of expressions enclosed by [, ].
   begin scalar cursym,delim,lst;
        if scan() eq '!*rsqb!* then <<scan(); return list 'list>>;
    a:  lst := aconc(lst,xread1 'group);
        cursym := cursym!*;
        scan();
        if cursym eq '!*rsqb!*
          then return if delim eq '!*semicol!* then 'progn . lst
                       else list('vec!*,'list . lst)
         else if null delim then delim := cursym
         else if not(delim eq cursym)
          then symerr("Syntax error: mixed , and ; in vector",nil);
        go to a
   end;

put('!*lsqb!*,'stat,'xreadvec);

newtok '((![) !*lsqb!*);

newtok '((!]) !*rsqb!*);

flag('(!*rsqb!*),'delim);

flag('(!*rsqb!*),'nodel);

symbolic procedure vec!* u;
   % Make a vector out of elements of u.
   begin scalar n,x;
      n := length u - 1;
      x := mkvect n;
      for i:= 0:n do <<putv(x,i,car u); u := cdr u>>;
      return x
   end;

% Evaluation interface.

% symbolic procedure setv(u,v);
%   <<set(u,v); put(u,'rtype,'vector); v>>;


% Length interface.


% Printing interface.


% Definitions of operations on vectors.

symbolic procedure getvect(u,vars,mode);
   expandgetv(car u,formlis(evalvecarg cdr u,vars,mode));

symbolic procedure expandgetv(u,v);
   if null v then u
    else expandgetv(list(if !*fastvector then 'igetv else 'getv,
                         u,car v),
                    cdr v);

symbolic procedure putvect(u,vars,mode);
   expandputv(caar u,formlis(evalvecarg cdar u,vars,mode),
              form1(cadr u,vars,mode));

symbolic procedure expandputv(u,v,w);
   if null cdr v
     then list(if !*fastvector then 'iputv else 'putv,u,car v,w)
    else expandputv(list(if !*fastvector then 'igetv else 'getv,
                         u,car v),
                    cdr v,w);

symbolic procedure evalvecarg u;
%   if u and null cdr u and vectorp car u
%     then for i:=0:upbv car u collect getv(car u,i) else
   if u and null cdr u and eqcar(car u,'vec!*)
       and eqcar(cadar u,'list)
     then cdadar u
    else u;

% Support for arrays defined in terms of vectors.

symbolic procedure mkar1 u;
   begin scalar x;
      x := mkvect car u;
      if cdr u then for i:= 0:upbv x do putv(x,i,mkar1 cdr u);
      return x
   end;

symbolic macro procedure array u;
   % Create an array from the elements in u.
   list('vec!*,'list . cdr u);

endmodule;


module mstruct;  % A tiny structure package for Standard Lisp.

% Author: Bruce A. Florman

% Copyright (c) 1989, The RAND Corporation.  All rights reserved.

Comment

 DESCRIPTION

  (defstruct <structspec> [ <slotspec>... ] )

   The <structspec> may be either the name of the structure, or a list
  containing the name followed by zero or more options.  Each <slotspec>
  may be either a list containing the slot name and its default value,
  or simply the slot name, in which case the default value is NIL.

   Each option in the <structspec> may be either an option name, or a
  list containing the option name and a specified value.  If only the
  option name is given, then the default value for the given option is
  used.  If NIL is the specified value in an option, then the option is
  not used at all (in general a NIL value is the same as not having that
  option in the list at all).  If the same option appears more than once
  with different values, the last one in the <structspec> takes
  precedence.

 These are the valid options:

  PREDICATE
    Makes the zeroth element of the structure contain the structure name
    and creates a predicate macro to test if a given item is an instance
    of this structure.  The specified value is the name of the predicate
    macro.  The default value is the structure name followed by a `P'.

  CONSTRUCTOR
    By default the name of the constructor macro is `MAKE-' followed by
    the structure name.  You may provide a different constructor name
    with this option.  If there is no constructor option in the
    <structspec> the default constructor will still be generated.  The
    only way to completely suppress the generation of a constructor
    macro is to have a (CONSTRUCTOR NIL) option.

  The flag !*FAST-STRUCTS controls how the accessor macros expand.
  If it is NIL, they expand as GETVs, otherwise they expand as
  IGETVs.

 NOTE: see records.tst for a level 0 test file.

 REVISION HISTORY
  07/19/85 BAF -- File created.
  01/26/89 BAF -- Added predicate and constructor macros so that
      this code can replace the RLISP record code.
      Changed  GetR to StructFetch, and !*FAST-RECORDS
      to !*FAST-STRUCTS.  Added code to check the
      validity of the options.  Also added this file
      header.
  01/30/89 BAF -- Added CONC-NAME as a synonym for SLOT-PREFIX and
      the ExplodeId function for compatability with
      existing programs (eg. ernie).
  Wed Apr 21 14:22:18 1993 - JBM Convert to RLISP '88, remove prefix
      stuff.
  Tue May 11 09:03:20 1993 - JBM Remove tconc and fix evaluator bug.
  Mon May 17 15:36:54 1993 - JBM Add RSETF function.
  Tue May 18 11:09:07 1993 - JBM add qputv for CSL to RSETF;

flag('(defstruct), 'eval);

fluid '(!*fast!-structs);

switch fast!-structs;

macro procedure defstruct u;
begin integer indx;
      scalar options,slot_forms,name,predicate,constructor,functions;
  options := get_defstruct_options cadr u;
  if cdr u
    then slot_forms := for each slot in cddr u
                          collect if idp slot then {slot,nil} else slot;
  name := car options;
  predicate := atsoc('predicate,cdr options);
  if predicate then predicate := cdr predicate;
  constructor := atsoc('constructor,cdr options);
  if constructor then constructor := cdr constructor;
  functions := nil;
  if constructor then
   functions := build_defstruct_constructor_macro(name,
                                                  constructor,
                                                  slot_forms,
                                                  predicate)
                   . functions;
  if predicate then
     functions :=
       build_defstruct_predicate_function(name, predicate) . functions;
  indx := if predicate then 1 else 0;
  for each slot in slot_forms do
     <<functions :=
            build_defstruct_accessor_macro(car slot, indx) . functions;
       indx := indx + 1>>;
  functions :=  mkquote name . functions;
  return 'progn  . reverse functions
end;

expr procedure get_defstruct_options u;
begin scalar name, options, predicate, constructor;
  if pairp u then << name := car u; options := cdr u >>
     else << name := u; options := nil >>;
  if  not idp name then error(0, {"bad defstruct name:", name});
  for each entry in options
      do if  entry eq 'predicate then
            predicate := intern compress append(explode name, '(p))
         else if eqcar(entry, 'predicate) then predicate := cadr entry
         else if entry eq 'constructor then
               constructor := intern compress append('(m a k e !! !-),
                                                    explode name)
         else if eqcar(entry,'constructor)
          then constructor := cadr entry
         else error(0, {"bad defstruct option:", entry});
  if null constructor then
    constructor := intern compress append('(m a k e !! !-),
                                          explode name);
  return {name, 'predicate . predicate, 'constructor . constructor}
end;

expr procedure explodeid x;
% EXPLODEID(X) - Explode whatever x is and make sure the result can
% be compressed back into an id no matter what it is.
if idp x then explode x
  else for each elt in explode2 x join {'!!, elt};

expr procedure build_defstruct_constructor_macro
   (name,macro_name,slot_forms,has_predicate);
begin scalar dflts;
  dflts := for each x in slot_forms collect
     {'cons, mkquote car x, cadr x};
   % I deal with the name field by inserting it as an extra slot, with
   % slot-name made by a gensym so that the user will not get to
   % override the default value ever.  As coded here if the default
   % value of a slot depends on a variable called !$!$!$ then scope
   % issues will lead to silly results being generated.
  if has_predicate
    then dflts := {'cons, '(gensym), mkquote name} . dflts;
  return {'putd,
           mkquote macro_name,
           ''macro,
           mkquote {'lambda, '(!$!$!$),
                      {'list, ''defstructvector,
                         {'mklist, {'defstruct_constructor,
                            '(cdr !$!$!$),
                            'list . dflts}}}}}
   end;

symbolic procedure mklist x; 'list . x;

expr procedure defstruct_constructor(u, dflts);
  for each d in dflts collect find_struct_key(car d, u, cdr d);

expr procedure find_struct_key(key, u, dflt);
  if null u then mkquote dflt
  else if car u eq key then
    if null cdr u then nil else cadr u
  else find_struct_key(key, cddr u, dflt);

expr procedure defstructvector l;
% DEFSTRUCTVECTOR(L) - Create a vector and store the list L into it.
% This is a portable substitute for PSL's list2vector.
begin integer i; scalar v,lv;
  v := mkvect sub1 length l;
  i := 0;
  for each vl in l do <<putv(v,i,vl); i := i+1>>;
  return v
end;

expr procedure build_defstruct_predicate_function(name, fnname);
% BUILD_DEFSTRUCT_PREDICATE_FUNCTION(NAME, FNNAME) - Builds a defstruct
% predicate to return as a function.
{'de, fnname, '(x),
  {'and, '(vectorp x), {'eq, mkquote name, '(igetv x 0)}}};

expr procedure build_defstruct_accessor_macro(slot_name,indx);
{'dm, slot_name, '(u), {'list, '(quote structfetch), '(cadr u), indx}};

macro procedure structfetch u;
  if !*fast!-structs  then 'igetv . cdr u else 'getv . cdr u;


%-----------------------------------------------------------------------
%                         SETF for RLISP88
%-----------------------------------------------------------------------

macro procedure rsetf u; expandrsetf(cadr u, caddr u);

expr procedure expandrsetf(lhs, rhs);
 if atom lhs then {'setq, lhs, rhs}
    else if eqcar(lhs, '!&variable_fetch) then
        '!&variable_store . append(cdr lhs, {rhs})
    else if get(car lhs, 'assign_op) then
         get(car lhs, 'assign_op) . append(cdr lhs, {rhs})
    else if getd car lhs and eqcar(getd car lhs, 'macro) then
        expandrsetf(apply(cdr getd car lhs, {lhs}), rhs)
    else error(0, {lhs, "bad RSETF form"});

deflist('((getv putv) (igetv putv) (car rplaca) (cdr rplacd)),
        'assign_op);

% This is CSL specific but shouldn't hurt anybody.
put('qgetv, 'assign_op, 'qputv);

endmodule;


module records; % A record package for RLISP using MSTRUCT.

% Author:  Bruce Florman.

% Copyright:  (c) 1989 The RAND Corporation.  All rights reserved.

% Revision History:
%  01/26/89 BAF -- Added this file header.
%       Sat Apr 24 12:38:32 1993 - Remove non-RLISP'88 functions (first,
%           etc.).

% BothTimes Load MSTRUCT;

%-----------------------------------------------------------------------
%      RECORD Declaration
%-----------------------------------------------------------------------

expr procedure recordstat();
% RECORD <struct-name>
%  { /* <annotation> */ }
%  { WITH <field> := <expression> { , <field> := <expression> }... }
%  { HAS <option> { , <option> }... } ;
   begin scalar f, stat;
      f := flagp('has,'delim);
      flag('(has),'delim);
      stat := errorset('(recordstat1),nil,nil);
      if not f then remflag('(has),'delim);
      if errorp stat then while cursym!* neq '!*semicol!* do scan()
       else return car stat
   end;

expr procedure recordstat1();
   begin scalar structname, annotation, fields, options;
      structname := scan();
      if not idp structname then symerr('record, t);
      if eqcar(scan(), '!*Comment!*) then
         <<annotation := cadr cursym!*; scan()>>;
       if cursym!* eq 'with then fields := remcomma xread nil;
       if cursym!* eq 'has then options := remcomma xread nil;
       if cursym!* eq '!*semicol!* then
         return {'record, structname, annotation, fields, options}
       else symerr('record, t)
   end;

put('record,'stat,'recordstat);

expr procedure formrecord(u, vars, mode);
apply(form_function, cdr u)
where form_function =
  function(lambda(record_name, annotation, fields, options);
     begin scalar structspec, fieldspecs, constructor, form;
       structspec := form_structure_specification(record_name, options);
       fieldspecs := form_field_specifications(fields);
       constructor := cdr atsoc('constructor,
                                get_defstruct_options structspec);
       form := {nil};
       tconc(form, 'progn);
      if constructor then
         << tconc(form,
                  {'put, mkquote constructor,
                         '(quote formfn),
                         '(quote form_record_constructor)});
             put(constructor, 'formfn, 'form_record_constructor) >>;
      if annotation then
         tconc(form, {'put, mkquote record_name,
                            '(quote annotation),
                            annotation});
      tconc(form, 'defstruct . structspec . fieldspecs);
      return car form
      end);

put('record, 'formfn, 'formrecord);

expr procedure tconc(ptr,elem);
   % ACONC with pointer to end of list.  Ptr is (list . last CDR of
   % list).  Returns updated Ptr.  Ptr should be initialized to
   % (NIL . NIL) before calling the first time.
   <<elem := list elem;
     if not pairp ptr then elem . elem
      else if null cdr ptr then rplaca(rplacd(ptr,elem),elem)
      else <<rplacd(cdr ptr,elem); rplacd(ptr,elem)>>>>;

expr procedure form_structure_specification(record_name, options);
append(defaults,
       for each entry in options
            collect if atom entry then entry
                    else if eqcar(entry, 'no) and length entry=2 then
                         {cadr entry, nil}
                    else if car entry eq 'equal and length entry=3 then
                         {cadr entry, caddr entry}
                    else error(0, {"Bad RECORD option:", entry}))
     where defaults = {record_name,{'constructor, record_name},
                       'predicate};

expr procedure form_field_specifications field_list;
for each entry in field_list
    join
       if eqcar(entry, 'setq)
         then {{cadr(entry), form1(caddr entry, nil, 'symbolic)}}
        else nil;

expr procedure form_record_constructor(u, vars, mode);
begin scalar constructor, arglist;
  constructor := car u;
  arglist := {nil};
  for each arg in cdr u
    do if eqcar(arg, 'setq) then
           << tconc(arglist, cadr arg);
              tconc(arglist, form1(caddr arg, vars, mode)) >>
       else rederr {arg, "is not a proper initialization form for",
                    constructor};
  return constructor . car arglist;
end;

endmodule;


module inspector;   % Rlisp88 Code inspector.

%  Author: Jed Marti.

%  Description: Formats and displays the active annotation associated
%   with various RLISP data structures.
%  Notes: Things left to work on:
%    DEFINE constants.
%    SWITCH
%    CLASS, instances, scripts, etc.
%    The line numbers are pretty much the input expression numbers
%    (where comments are counted). Fixing this would require a
%    modification to the RLISP lexical scanner.
%  Dependencies:
%  Revision History: (Created Fri Jan  3 08:40:29 1992)
%    Wed Feb 26 09:39:28 1992 Add file/line numbers to functions.
%          Upgrade comments.
%    Sun Mar  1 11:09:30 1992 Try GLOBAL and FLUID declarations. Also
%          clear COMMENT!* after each use.
%    Fri Mar 13 17:28:41 1992 Add the comment reformatting routine
%          fmtcmt.
%    Fri Oct  8 12:06:00 1993 Fix use if ifl!*, remove printf's. Make
%      work with old RLISP syntax first.  No active comments in this
%      code.

expr procedure describe x;
   % DESCRIBE(X) -- Inspect any data structure X. This main routine
   % farms out the work accordingly.
   if pairp x then << prin2t "A dotted-pair or list"; nil >>
    else if vectorp x then
     if i!&recordinstp x then i!&recordinst x
      else  <<prin2 "A vector with "; prin1 add1 upbv x;
              prin2t " elements"; nil>>
   else if codep x then <<prin2t "A code-pointer"; nil>>
   else if numberp x then
      if fixp x then <<prin2t "A fixed number"; nil>>
      else if floatp x then <<prin2t "A floating-point number"; nil>>
      else <<prin2t "An unknown type of number"; nil>>
   else if stringp x then <<prin2t "A string"; nil>>
   else if idp x then
     if i!&recordp x then i!&record x
     else if i!&functionp x then i!&function x
     else if i!&constantp x then i!&constant x
     else if i!&modulep x then i!&module x
     else if get(x, 'newnam) then i!&idnewnam x
     else i!&id x
   else <<prin2t "Can't inspect data structures of this type";nil>>;

expr procedure i!&idnewnam x;
   % I!&IDNEWNAM(X) - This is the result of a define.
   <<prin1 x;
     prin2 " is a constant defined as ";
     print get(x,'newnam);
     if x := get(x,'active!-annotation) then
        if pairp x then i!&dump car x else i!&dump x>>;

expr procedure i!&recordp x;
   % I!&RECORDP(X) -- X is an id. Returns T if this looks like an RLISP
   % record.
   get(x,'formfn) eq 'form!_record!_constructor;

expr procedure i!&record x;
% I!&RECORD(X) -- X is an id and the name of a record constructor. Try
%  and display as much about the record as possible. Note that record
%  instances are handled by the vector case temporarily.
<< prin1 x; prin2t " is a record constructor with the following fields";
   prin2t "** not implemented. **";
   nil >>;

expr procedure i!&recordinstp x;
% I!&RECORDINSTP(X) -- Returns T if X (a vector) looks like a record
% instance.
begin scalar tmp;
  if not idp getv(x,0) then return nil;
  if not (tmp :=  getd getv(x,0)) then return nil;
  if not eqcar(getd getv(x,0),'macro) then return nil;
  if atom (tmp := errorset({getv(x,0)},nil,nil)) then return nil;
  if upbv x neq upbv car tmp then return nil;
  return t
end;

expr procedure i!&recordinst x;
% x is identified as a record.
<< prin2 "A "; prin1 getv(x,0); prin2t " record with ";
   for i:=1:upbv x
       do << prin2 "   "; prin1 i; prin2 ": "; print getv(x,i)>>;
   nil >>;

expr procedure i!&functionp x;
% I!&FUNCTIONP(X) -- X is an id. Returns T if it is also the name of a
%  function or SMACRO.
get(x, 'smacro) or getd x;

expr procedure i!&function x;
% I!&FUNCTION(X) - X is a function or SMACRO name. Farm out the
%  description based on its type.
if get(x, 'smacro) then i!&function!-smacro x
 else (if eqcar(w, 'macro) then i!&function!-macro(x, cdr w)
       else if eqcar(w, 'expr) then i!&function!-expr(x, cdr w)
       else if eqcar(w, 'fexpr) then i!&function!-fexpr(x, cdr w)
       else i!&function!-unknown(x, w)) where w := getd x;

expr procedure i!&function!-smacro x;
% I!&FUNCTION!-SMACRO(X) -- X is the name of an SMACRO. Display what we
%  know about it.
begin scalar tmp, d;
  d := get(x, 'smacro);
  prin1 x; prin2 " is an SMACRO with ";
  if not (tmp := get(x, 'number!-of!-args)) then
   if eqcar(d, 'lambda) and cdr d then tmp := length cadr d
   else tmp := nil;
  if onep tmp then prin2t "one argument"
    else if not tmp then prin2t "an unknown number of arguments"
    else << prin1 tmp; prin2t " arguments" >>;
  if tmp := get(x, 'active!-annotation) then
     << i!&whereis tmp; i!&dump if pairp tmp then car tmp else tmp>>
end;


expr procedure i!&function!-expr(x, d);
%  I!&FUNCTION!-EXPR(X, D) -- X is the name of an EXPR type function and
%  D is it's definition. Display what we know about it.
begin scalar tmp;
  prin1 x; prin2 " is an EXPR with ";
  if not (tmp := get(x, 'number!-of!-args)) then
   if eqcar(d, 'lambda) and cdr d then tmp := length cadr d
   else tmp := nil;
  if onep tmp then prin2t "one argument"
    else if not tmp then prin2t "an unknown number of arguments"
    else << prin1 tmp; prin2t " arguments" >>;
  if tmp := get(x, 'active!-annotation) then
     << i!&whereis tmp; i!&dump if pairp tmp then car tmp else tmp >>
end;


expr procedure i!&function!-fexpr(x, d);
%  I!&FUNCTION!-FEXPR(X, D) -- X is the name of an FEXPR type function
%  and D is its definition. Display what we know about it.
begin scalar tmp;
  prin1 x; prin2t " is an FEXPR";
  if tmp := get(x, 'active!-annotation) then
     << i!&whereis tmp; i!&dump if pairp tmp then car tmp else tmp >>
end;


expr procedure i!&function!-macro(x, d);
% I!&FUNCTION!-MACRO(X, D) -- X is the name of a MACRO type function and
%  D its definition. Display what we know.
begin scalar tmp;
  prin1 x; prin2t " is a MACRO";
  if tmp := get(x, 'active!-annotation) then
     << i!&whereis tmp; i!&dump if pairp tmp then car tmp else tmp >>
end;


expr procedure i!&whereis x;
% I!&WHEREIS(X) -- We might have a (comment line-number file). If so,
%  display this information.
if length x = 3 then
  << prin2 "Function ends on line "; prin1 cadr x;
     prin2 " in file "; prin2t caddr x >>;


expr procedure i!&constantp x;
% I!&CONSTANTP(X) - Returns T if X is a constant.
  constantp x;

expr procedure i!&id x;
% I!&ID(X) -- X is an id see if we can find out anything about it.
if globalp x then i!&id1(x, 'global)
 else if fluidp x then i!&id1(x, 'fluid)
 else << prin2 "Don't know anything about "; print x; nil >>;

expr procedure i!&id1(x, ty);
% I!&ID1(X, TY) -- X is TY (global or fluid). Print out what we know
%  about this id.
begin scalar a;
  prin2 "Identifier '"; prin1 x; prin2 "' is "; prin2 ty;
  if a := get(x, 'active!-annotation) then
    if length a = 3 then
       << prin2 " defined line "; prin1 cadr a;
          prin2 " in file "; prin2t caddr a;
          i!&dump car a >>
    else i!&dump a
  else terpri()
end;

expr procedure i!&constant x;
% I!&CONSTANT(X) - X is some sort of constant. Not much we can say about
% it.
   <<prin1 x; prin2t " is a constant">>;

expr procedure i!&modulep x;
% I!&MODULEP(X) - Returns T if x looks like a module.
flagp(x, 'module);

expr procedure i!&module x;
% I!&MODULE(X) - Display the facts about a module.
(if filep r88 then  i!&module1(x, i!&moduleb x, r88)
  else if filep rd then i!&module1(x, i!&moduleb x, rd)
  else i!&module2 x)
where r88 := string!-downcase
                compress nconc('!" . explode2 x, '(!. !r !8 !8 !")),
      rd := string!-downcase
                compress nconc('!" . explode2 x, '(!. !r !e !d !"));


expr procedure i!&module1(mname, bfile, sfile);
% I!&MODULE(MNAME, BFILE, SFILE) - Display data about module MNAME
%  with object file BFILE, source file SFILE. PSL/UNIX specific.
begin scalar sfs, bfs;
  if sfile then sfs := filestatus sfile;
  if bfile then bfs := filestatus bfile;
  if sfile then
     if bfile then
      << prin2 "Module ";
         prin1 mname;
         prin2 " source file ";
         prin2 sfile;
         prin2 " fasl file ";
         prin2 bfile;
         prin2 " and is ";
         print i!&dcomp(sfs, bfs) >>
     else
      << prin2 "Module ";
         prin1 mname;
         prin2 " has source file ";
         prin2 sfile;
         prin2 " written ";
         prin2t i!&sdt sfs >>
  else if bfile then
     << prin2 "Module ";
        prin1 mname;
        prin2 " has fasl file ";
        prin2 bfile;
        prin2 " written ";
        prin2t i!&sdt bfs >>
  else
   << prin2 "Module ";
      prin1 mname;
      prin2t ", can't find any files." >>;
  if sfs := get(mname, 'active!-annotation) then
    if pairp sfs then i!&dump car sfs else i!&dump sfs;
end;


expr procedure i!&module2 mname;
% I!&MODULE2(MNAME) - called when we don't know much about a module.
<< prin2 "Can't find source or fasl file for module ";
   print mname;
   if sfs then if pairp sfs then i!&dump car sfs else i!&dump sfs >>
        where sfs := get(mname, 'active!-annotation);


expr procedure i!&dcomp(s1, s2);
% I!&DCOMP(S1, S2) -- two PSL file statuses. Compare the WRITETIMES
%  and return " OUT OF DATE." or " UP TO DATE.".
if i!&dt s1 > i!&dt s2 then " out of date." else " up to date.";

expr procedure i!&dt x;
(if w then cddr w else 0) where w := atsoc('writetime, x);

expr procedure i!&sdt x;
(if w then cadr w else "no date") where w := atsoc('writetime, x);

expr procedure i!&moduleb x;
% I!&MODULEB(X) - Find which directory LOADDIRECTORIES!* the .b file
%  is and return the file name.
begin scalar fs, fn;
  fs := loaddirectories!*
  while pairp fs
   do << fn := string!-downcase
                nconc('!" . explode2 car fs,
                      nconc(explode2 x, '(!. !b !")));
         if filep fn then fs := fn
           else fs := cdr fs >>;
  return fs
end;


%-----------------------------------------------------------------------
% Basic active comment formatting. Remove the leading blank from the
% first line, all blanks at start of each subsequent line, but only
% of the shortest line.

expr procedure i!&dump x;
% I!&DUMP(X) - X is a string or something. Display its characters but
%  dump blanks at the beginning of each line as appropriate.
begin scalar lnes, minsp, v;
  lnes := reversip i!&makelines(explode2 x, {nil});
  minsp := 5000;
  for each x in cdr lnes do
      if (v:= i!&spcount x) < minsp then minsp := v;
  i!&prn i!&delspace(5000, car lnes);
  for each l in cdr lnes do i!&prn i!&delspace(minsp, l)
end;

expr procedure i!&makelines(x, l);
%  I!&MAKELINES(X, L) -- Remove EOL's form x and convert to a list of
% sentences. L is used to build this list, call this with L = NIL.
  if null x then reversip car l . cdr l
   else if eqcar(x, !$eol!$) then
        i!&makelines(cdr x, nil . (reversip car l . cdr l))
   else << car l := car x . car l; i!&makelines(cdr x, l) >>;

expr procedure i!&spcount l;
% I!&SPCOUNT(l) -- Count spaces in front of line l and return.
if null l then 0
  else if eqcar(l, '! ) then add1 i!&spcount cdr l
  else 0;

expr procedure i!&delspace(n, l);
%  I!&DELSPACE(N, L) -- Delete n spaces from the front of line L and
%  return a new list. Quit if the list is short or runs into some
%  non-blank character.
if null l then nil
  else if zerop n then l
  else if eqcar(l, '! ) then i!&delspace(n - 1, cdr l)
  else l;

expr procedure i!&prn x;
% I!&PRN(x) -- Display the characters of list x and then terminate the
%  line.
<< for each c in x do prin2 c;
   terpri() >>;


%-----------------------------------------------------------------------
% Hacks to make active comments work.

fluid '(!*saveactives);
switch saveactives;


expr procedure i!&makeComment;
% I!&MAKECOMMENT() - returns (comment line file) for packing active
%  annotation data away.
mkquote {cadr Comment!*, curline!*,
         if ifl!* then car ifl!* else "unknown"};


expr procedure nformproc(a, b, c);
% NFORMPROC(A, B, C) -- Temporary wrapper for FORMPROC to save the
%  function active annotation if the SAVEACTIVES switch is on. Also
%  put the file name and current line out there.
begin scalar v;
  v := if !*saveactives and Comment!* then
      {'progn,
        {'cond, {'!*saveactives,
                 {'put, mkquote cadr a, mkquote 'active!-annotation,
                        i!&makecomment()}}},
        formproc(a, b, c)}
   else formproc(a, b, c);
  Comment!* := nil;
  return v
end;

% put('procedure,'formfn,'nformproc);


expr procedure formmodule(u, vars, mode);
% FORMMODULE(U,VARS,MODE) - Save any active annotation on the property
%  of the module. Clear comment after use.
begin scalar x;
  x := if !*saveactives and Comment!* then
     {'progn, {'cond, {'!*saveactives,
                       {'put, mkquote cadr u,
                         mkquote 'active!-annotation,
                         i!&makecomment()}}},
              {'flag, mkquote {cadr u}, mkquote 'MODULE},
              {'module, mkquote{cdr u}}}
  else {'module, mkquote cdr u};
  Comment!* := nil;
  return x
end;

% put('module, 'formfn, 'formmodule);


expr procedure formglobalfluid(u, vars, mode);
% FORMGLOBALFLUID(U, VARS, MODE) -- Attach active annotation to the
%  variables declared.
if !*saveactives and Comment!* then
 {{'lambda, {'!$v!$},
     {'progn,
       {'cond, {'!*saveactives,
                {'mapcar, '!$v!$,
                   {'function,
                     {'lambda, {'!$u!$}, {'put, '!$u!$,
                                           mkquote 'active!-annotation,
                                           i!&makeComment()}}}}}},
       {car u, '!$v!$}}}, formc(cadr u, vars, mode)}
 else {car u, formc(cadr u, vars, mode)};

% put('global, 'formfn, 'formglobalfluid);

% put('fluid, 'formfn, 'formglobalfluid);


expr procedure fmtcmt(ano, ind, rm);
begin scalar la, ind3, tcs, c, coll, colle, curbl, cbl;
  la := explode2 ano;
  if (ind3 := ind + 3) > (rm - 10) then error(0, "margins too small");
  tcs := rm - ind3;

  % Remove extra blanks from front.
%  la := deblank la;

  % STATE 1: Now scan the lines dumping tokens to the output.
  spaces ind;
  prin2 "/* ";
loop: if null la then return prin2 " */";
  if c := fmtfulllineof(car la, la) then
     << la := fmtremoveline la;
        for i:=1:tcs do prin2 c;
        terpri();
        spaces ind3;
        go to loop >>
  else if fmtblankline la then
     << if posn() > ind3 then terpri();
        terpri();
        spaces ind3;
        la := fmtremoveline la;
        go to loop >>
  else if eqcar(la, !$eol!$) then
     << terpri(); spaces ind3;go to loop >>
  else if eqcar(la, '! ) then go to state4;

  % STATE 2: Collect characters to EOL, blank, or NIL.
state2: coll := colle := {car la};
  la := cdr la;

state2a: if null la then
       << fmtdumptok(coll, ind3, rm);
          go to loop >>
    else if eqcar(la, !$eol!$) then
       << fmtdumptok(coll, ind3, rm);
          la := cdr la;
          go to loop >>
    else if eqcar(la, '! ) then
       << fmtdumptok(coll, ind3, rm);
          go to state3 >>;
    cdr colle := {car la};
    colle := cdr colle;
    la := cdr la;
    go to state2a;

  % STATE 3: Skip blanks to NIL, EOL, or next token.
state3: if null la then go to loop
     else if eqcar(la, !$eol!$) then << la := cdr la; go to loop >>
     else if eqcar(la, '! ) then << la := cdr la; go to state3 >>
     else go to state2;


  % STATE 4: We've got a line that starts with a blank. Dump it to the
  % output line.
state4: curbl := 0; cbl := t;
state4a: prin2 car la;
  if cbl and eqcar(la, '! ) then curbl := add1 curbl else cbl := nil;
  la := cdr la;
  if null la then go to loop;
  if eqcar(la, !$eol!$) then
    << terpri(); spaces ind3;la := cdr la; go to loop >>;
  if posn() >= rm then << terpri(); spaces(1 + ind3 + curbl) >>;
  go to state4a
end;



expr procedure fmtblankline l;
% FMTBLANKLINE(L) -- returns T if the rest of the current line is
%  all blanks.
if null l or eqcar(l, !$eol!$) then t
  else if eqcar(l, '! ) then fmtblankline cdr l;


expr procedure fmtfulllineof(c, la);
% FMTFULLLINEOF(C, LA) -- Returns C if LA up to the end or !$EOL!$ is
%  all one character.
if null la then c
  else if eqcar(la, c) then fmtfulllineof(c, cdr la)
  else if eqcar(la, !$eol!$) then c
  else nil;



expr procedure fmtremoveline la;
% FMTREMOVELINE(LA) -- returns the remainder of LA up to the end or the
%  first !$EOL!$.
if la and not eqcar(la, !$eol!$) then fmtremoveline cdr la else cdr la;


expr procedure fmtdumptok(l, ind, rm);
if (length l + posn()) > rm then
  << terpri(); spaces ind; for each x in l do prin2 x; prin2 " " >>
else << for each x in l do prin2 x;
        if posn() <= rm then prin2 " " >>;

endmodule;


end;
