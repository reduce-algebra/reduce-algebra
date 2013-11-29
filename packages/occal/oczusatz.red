module oczusatz;

% Author: Rainer Schöpf 

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


comment Redefinitions and additions for REDUCE 3.5;

comment redefinition of rnfactor!: -- not needed in future versions;

symbolic procedure rnfactor!: u;
   begin scalar x,y,dmode!*; integer m,n;
     x := subf(u,nil);
     y := fctrf numr x;
     n := car y;
     dmode!* := '!:rn!:;
     y := for each j in cdr y collect
           <<n := !:times(n,(m := !:expt(lnc ckrn car j,cdr j)));
             quotfd(car j,m) . cdr j>>;
     return (if atom n then int!-equiv!-chk mkrn(n,denr x)
              else !:quotient(n,denr x)) . y
   end;


comment Some enhancements to the solve module;

fluid '(!*solve!-deferred!-kernels!* !*backtrace !*nonlnr vars!*);

remflag ('(solvesys), 'lose);

symbolic procedure solvesys(exlist,varlis);
   % exlist is a list of standard forms, varlis a list of kernels.  If
   % the elements of varlis are linear in the elements of exlist, and
   % further the system of linear eqns so defined is non-singular, then
   % SOLVESYS returns a list of a list of standard quotients which are
   % solutions of the system, ordered as in varlis.  Otherwise an error
   % results.
   begin scalar !*solve!-deferred!-kernels!*,vl;
      exlist := transform!-variables (exlist, varlis);
      vl := cdr exlist; exlist := car exlist;
      exlist := errorset({'solvesys0,mkquote exlist,mkquote vl},t,
                         !*backtrace);
      if errorp exlist then error1 ();
      exlist := car exlist;
      if car exlist eq 't and not null !*solve!-deferred!-kernels!*
        then return 't . solve!-wrt!-deferred!-kernels(
                        cdr exlist,!*solve!-deferred!-kernels!*,varlis)
       else return exlist
   end;



symbolic procedure solvesys0(exlis,varlis);
   % exlis: list of sf, varlis: list of kernel
   % -> solvesys: tagged solution list
   % The expressions in exlis are reordered wrt the kernels in varlis,
   % and solved. For some switch settings, the internal
   % solve procedure may produce an error, leaving the kernel order
   % disturbed, so an errorset is used here.
   begin scalar oldkord,oldvars;
        % The standard methods for linear and polynomial system
        % don't work for non-prime modulus.
      if !*modular then
        <<load!-package 'modsr; return msolvesys(exlis,varlis,t)>>;
      oldvars := vars!*; % Protect this from change in sub-problems.
      oldkord := setkorder varlis;
      exlis := for each j in exlis collect reorder j;
      exlis := errorset!*({'solvemixedsys,mkquote exlis,mkquote varlis},
     t);
      setkorder oldkord;
      vars!* := oldvars;
      if errorp exlis then error1();
      return car exlis;
   end;

flag('(solvesys),'lose);


symbolic procedure solve!-wrt!-deferred!-kernels(sols,defkrnls,varlis);
  for each set in sols join
    if null cadr set then set
     else begin scalar soll,varlis1,mlt,varlis2,pairlis,x,soll2,y;
        soll := car set;
        varlis1 := cadr set;
        mlt := caddr set;
        %
        % first step: substitute back all deferred kernels
        %             that are members of varlis
        %
        for each var in varlis do <<
          x := atsoc (var, defkrnls);
          if not null x and cdr x member varlis then y := x . y >>;
        varlis1 := sublis (y, varlis1);
        soll := sublis (y, soll);
        %
        % second step: add extra relations given by deferred kernels
        %
        pairlis := pair (varlis1, soll);
        for each pair in pairlis do <<
          x := atsoc (car pair, defkrnls);
          if not null x then <<
            x := cdr x;
            if car x eq 'expt and cadr x memq varlis and
               freeofl (caddr x, varlis)
              then pair := cadr x . simp {'expt, mk!*sq cdr pair,
                                          {'recip, caddr x}}
             else if get (car x, 'inverse) and cadr x memq varlis
              then pair := cadr x . simp {get (car x, 'solve!-inverse),
                                          mk!*sq cdr pair}
             else pair := x . cdr pair >>;
          soll2 := cdr pair . soll2; varlis2 := car pair . varlis2 >>;
        x := for each pp in reversip pair (soll2, varlis2) collect
               numr subtrsq (simp cdr pp, car pp);
        x := errorset({'solvesys0, mkquote x, mkquote varlis}, nil,
                       !*backtrace);
        if not errorp x then return cdr car x
%        return list (reversip soll2, reversip varlis2, mlt)
      end;


comment
deflist ('((log exp)
           (exp log)
           (sin asin)
           (asin sin)
           (cos acos)
           (acos cos)
           (tan atan)
           (atan tan)
           (cot acot)
           (acot cot)
           (sec asec)
           (asec sec)
           (csc acsc)
           (acsc csc)
           (sinh asinh)
           (asinh sinh)
           (cosh acosh)
           (acosh cosh)
           (tanh atanh)
           (atanh tanh)
           (coth acoth)
           (acoth coth)
           (sech asech)
           (asech sech)
           (csch acsch)
           (acsch csch)),
         'solve!-inverse);

symbolic procedure all!-kernels exlis;
  if null exlis then nil
   else union (kernels car exlis, all!-kernels cdr exlis);

symbolic procedure kernels!-in!-sq sq;
  union (kernels numr sq, kernels denr sq);

symbolic procedure transform!-variables (exlis, varlis);
  begin scalar u, w, x, y, z;
    %
    % get all kernels that depend on one of the kernels in varlis
    %
    x := dependent!-kernels (all!-kernels exlis, varlis);
    %
    % if a variable in varlis appears also in a more complicated way,
    % i.e. inside of another kernel, delete them from x
    %
    for each el in varlis do
      if el member x then
        for each z in u do if not (z freeof el)
          then << y := z . y; x := delete (z, x) >>;
    %
    % Look through the argument list of every kernel in x:
    %  if it depends on more than one kernel, delete it from x
    %
    for each el in x do
      if not atom el then begin scalar w;
        for each z in cdr el do
          for each z1 in kernels!-in!-sq simp!* z do
            if z1 = w then nil
             else if not null w then x := delete (el, x)
             else w := z1
      end;
    %
    % delete the kernels from varlis that depend on a kernel in x
    %
    for each el in varlis do
      for each w in x do
        if not (w freeof el) then if not (el member y) then y := el . y;
    for each el in y do varlis := delete (el, varlis);
    return union (varlis, x)
  end;

symbolic procedure transform!-variables (exlis, varlis);
  begin scalar x, z;
    %
    % get all kernels that depend on one of the kernels in varlis
    %
    x := dependent!-kernels (all!-kernels exlis, varlis);
    for each krnl in x do
      if not idp krnl then
        !*solve!-deferred!-kernels!* :=
            (gensym () . krnl) . !*solve!-deferred!-kernels!*;      
    z := for each ex in exlis collect
           !*q2f subf (ex,
                 for each el in !*solve!-deferred!-kernels!* collect
                     (cdr el . car el));
    z := append (z,generate!-algebraic!-relations
                      !*solve!-deferred!-kernels!*);
    for each el in varlis do
      if z freeof el then varlis := delete (el, varlis);
    return (z . append(varlis,for each x in !*solve!-deferred!-kernels!*
                                collect car x))
  end;

%symbolic procedure freeoflist (u, v);
%  if null v then T
%   else freeof (u, car v) and freeoflist (u, cdr v);

symbolic procedure dependent!-kernels (kl, varlis);
  %
  % kl and varlis are lists of kernels.
  % Returns a list of those kernels in kl
  % that depend on one or more kernels in varlis.
  %
  begin scalar result;
    for each u in kl do
      if not freeofl (u, varlis)
        then result := u . result;
    return result
  end;


symbolic procedure generate!-algebraic!-relations kl;
  %
  % kl is a list of pairs (gensym . kernel),
  % result is a list of non-trivial algebraic relations
  % between them.
  %
  begin scalar logs, expts, trigs, hyperbs, roots;
    for each x in kl do
      if not atom cdr x then
        if car cdr x memq '(log log10)
          then logs := x . logs
         else if car cdr x memq '(sin cos tan cot sec csc)
          then trigs := x . trigs
         else if car cdr x memq '(sinh cosh tanh coth sech csch)
          then hyperbs := x . hyperbs
         else if car cdr x eq 'expt
          then if rational!-number!-p caddr cdr x
                 then roots := x . roots
                else expts := x . expts;
    return
      append (generate!-trig!-relations trigs,
        append (generate!-trig!-relations hyperbs,
          append (generate!-root!-relations roots,
            append (generate!-log!-relations logs,
                    generate!-exponential!-relations expts))))
  end;


symbolic procedure rational!-number!-p u;
  eqcar(u, 'quotient) and fixp cadr u and fixp caddr u
  or eqcar(u,'!:rn!:);


symbolic procedure generate!-trig!-relations kl;
  %
  % kl is a list of (gensym . kernel) with a trigonometric function
  %  as top-level operator
  % result is a list of relations between them.
  %
  begin scalar arglists;
    arglists := separate!-arguments kl;
    return for each x in arglists join
      if null cdr cdr x then nil  % only one kernel
       else for each y on cdr x join
              for each y1 in cdr y join
                generate!-one!-trig!-relation(car cdr car y,car cdr y1,
                                              car x,car car y,car y1)
  end;

symbolic procedure separate!-arguments kl;
  %
  % kl is a list of (gensym . kernel)
  % result is a list of pairs (arg . krnl-list)
  %  where arg is the first argument of all kernels
  %  in krnl-list.
  %
  begin scalar arglists, z;
    for each x in kl do <<
      z := assoc (cadr cdr x, arglists);
      if null z
	then arglists := (cadr cdr x . list x) . arglists
       else rplacd (z, x . cdr z) >>;
    return arglists
  end;

symbolic procedure generate!-one!-trig!-relation(op1,op2,arg,s1,s2);
  %
  % op1 and op2 are trigonometric operators,
  %  arg their common argument,
  % s1 and s2 are ids representing the kernels
  % result is a expression that is equivalent to zero
  %
  begin scalar rel;
    rel := get (op1, 'trig!-relations);
    rel := assoc (op2, rel);
    if null rel then return nil;
    rel := cadr rel;
    rel := !*a2f sublis (list ('!%1 . s1, '!%2 . s2), rel);
    return if null rel then nil else list rel
  end;

put('sin,'trig!-relations,
    '((cos (plus (expt !%1 2) (expt !%2 2) (minus 1)))
      (tan (difference (times (expt !%1 2) (plus 1 (expt !%2 2)))
                       (expt !%2 2)))
      (cot (difference (times (expt !%1 2) (plus 1 (expt !%2 2))) 1))
      (sec (plus (times (expt !%1 2) (plus (minus 1) (expt !%2 2))) 1))
      (csc (difference (times !%1 !%2) 1))));

put('cos,'trig!-relations,
    '((sin (plus (expt !%1 2) (expt !%2 2) (minus 1)))
      (tan (difference (times (expt !%1 2) (plus 1 (expt !%2 2))) 1))
      (sec (difference (times !%1 !%2) 1))));

put('sinh,'trig!-relations,
    '((cosh (plus (expt !%2 2) (minus (expt !%1 2)) (minus 1)))
      (csch (difference (times !%1 !%2) 1))));

put('cosh,'trig!-relations,
    '((sinh (plus (expt !%1 2) (minus (expt !%2 2)) (minus 1)))
      (sech (difference (times !%1 !%2) 1))));


symbolic procedure generate!-root!-relations kl;
  %
  % kl is a list of (id . kernel) with expt
  %  as top-level operator and a rational exponent,
  % result is a list of relations between them.
  %
  for each pp in kl collect 
    << !*solve!-deferred!-kernels!* :=
          delete (pp, !*solve!-deferred!-kernels!*);
       generate!-one!-root!-relation(car kl,cadr cdr kl,caddr cdr kl)>>;


symbolic procedure generate!-one!-root!-relation (id, rad, expo);
  %
  % generate a polynomial relation for id = rad**expo
  %  where expo = z/n, i.e. generate id**n=rad**z.
  %
  begin integer z,n;
    if car expo eq 'quotient
      then << z := cadr expo; n := caddr expo >>
     else << z := cadr expo; n := cddr expo >>;
    return reval list ('difference,
                       list ('expt, id, n),
                       list ('expt, rad, z))
  end;


symbolic procedure generate!-log!-relations kl;
  %
  % kl is a list of kernels with log or log10
  %  as top-level operator and a rational exponent,
  % result is a list of relations between them.
  %
  begin scalar logs, log10s;
    for each x in kl do
      if car cdr x eq 'log then logs := x . logs
       else log10s := x . log10s;
    return append (generate!-log!-relations1 logs,
                   generate!-log!-relations1 log10s)
  end;



symbolic procedure generate!-log!-relations1 kl;
  for each x on kl join
    for each y on cdr x join
      for each z in cdr y join
        try!-log!-relations (car x, car y, z);


symbolic procedure try!-log!-relations (krnl1, krnl2, krnl3);
  %
  % Checks whether there is an relation of the form
  %   krnl1 + krnl2 = krnl3
  %  (or any permutation)
  % Result is (relation) or nil.
  %
  begin scalar arg1, arg2, arg3, s1, s2, s3, result;
    s1 := car krnl1;
    krnl1 := cdr krnl1;
    arg1 := cadr krnl1;
    s2 := car krnl2;
    krnl2 := cdr krnl2;
    arg2 := cadr krnl2;
    s3 := car krnl3;
    krnl3 := cdr krnl3;
    arg3 := cadr krnl3;
    result := if null numr simp!* {'difference, {'times, arg1, arg2},
                                   arg3}
      then !*a2f list ('difference, list ('plus, s1, s2), s3)
     else if null numr simp!* {'difference, {'times, arg2, arg3}, arg1}
      then !*a2f list ('difference, list('plus, s2, s3), s1)
     else if null numr simp!* {'difference, {'times, arg3, arg1}, arg2}
      then !*a2f list ('difference, list('plus, s3, s1), s2)
     else 0;
    return if result = 0 then nil else list result
  end;



symbolic procedure generate!-exponential!-relations kl;
  nil; % not much for now

comment some additions/corrections for the gentran package;

global '(irena!-constants !*lisparithexpops!* !*lisplogexpops!*
         !*c!-functions!* pascfuncname!*);

%remflag('(lispcodeexp cexp1 mkfpascprocdec string2id),'lose);

symbolic procedure lispcodeexp(form, fp);
% (RECIP exp) ==> (QUOTIENT 1.0 exp)                   %
% (DIFFERENCE exp1 exp2) ==> (PLUS exp1 (MINUS exp2))  %
% integer ==> floating point  iff  PERIOD flag is ON & %
%                                  not exponent &      %
%                                  not subscript &     %
%                                  not loop index      %
% The above is a little simplistic. We have problems
% With expressions like x**(1/2) 
% Now believed fixed. JHD 14.5.88
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% mcd 16-11-88.  Added code to spot certain variables which irena
% needs to generate values for.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
begin
return if numberp form then
    if fp then
        float form
    else
        form
% Substitute (EXP 1) for e - mcd 29/4/88 %
else if form eq 'e then
    lispcodeexp(list('exp,1.0),fp)
else if atom form or car form memq '( !:rd!: !:cr!: !:crn!: !:gi!: )then
<<
    if irena!-constants and form and not stringp form then
        check!-for!-irena!-constants form;
    form
>>
else if car form eq 'expt then
    % Changes (EXPT E X) to (EXP X). mcd 29/4/88 %
    if cadr form eq 'e then
         lispcodeexp(list('exp,caddr form),fp)
     else if caddr form = '(quotient 1 2)               %%% RmS
      then lispcodeexp(list('sqrt, cadr form),fp)       %%% RmS
    else
      list('expt, lispcodeexp(cadr form, fp),
           if floatp caddr form                         %%% RmS
             then (list ('quotient, car r, cdr r)       %%% RmS
                      where r := realrat caddr form)    %%% RmS
            else
                 lispcodeexp (caddr form, nil))
else if car form eq 'quotient then % re-instate periods if necessary
                                   %e.g. in expressions like **(1/2)
        list('quotient, lispcodeexp(cadr form, t),
                        lispcodeexp(caddr form, t))
else if car form eq 'recip then
    if !*period then % test this not FP, for same reason as above
        list('quotient, 1.0, lispcodeexp(cadr form, fp))
    else
        list('quotient, 1, lispcodeexp(cadr form, fp))
else if car form eq 'difference then
    list('plus, lispcodeexp(cadr form, fp),
                list('minus, lispcodeexp(caddr form, fp)))
else if not(car form memq !*lisparithexpops!*) and
        not(car form memq !*lisplogexpops!*) then
    for each elt in form collect lispcodeexp(elt, nil)
else
    for each elt in form collect lispcodeexp(elt, fp);
end;


% symbolic procedure cexp1(exp, wtin);
% if atom exp then
%     list cname exp
% else
%     if onep length exp then
%         append(cname exp, insertparens(()))
%     else if car exp eq 'expt then
% %%% RmS
%         if caddr exp = 2
%           then cexp1 (list('times, cadr exp, cadr exp), wtin)
%          else if caddr exp = 3
%           then cexp1 (list('times, cadr exp, cadr exp, cadr exp), wtin)
%          else if caddr exp = 4
%           then cexp1 (list('times, cadr exp, cadr exp, cadr exp, cadr exp), wtin)
%          else if caddr exp = '(quotient 1 2)
%           then cexp1 (list('sqrt, cadr exp), wtin)
%          else
% %%% RmS
%         %'!p!o!w . insertparens append(cexp1(cadr exp, 0),
%         %                              '!, . cexp1(caddr exp, 0))
%         cexp1 ('pow . cdr exp,wtin)
%     else if optype car exp then
%         begin
%         scalar wt, op, res;
%         wt := cprecedence car exp;
%         op := cop car exp;
%         exp := cdr exp;
%         if onep length exp then
%             res := op . cexp1(car exp, wt)
%         else
%         <<
%             res := cexp1(car exp, wt);
%             if op eq '!+ then
%                 while exp := cdr exp do
%                 <<
%                     if atom car exp or caar exp neq 'minus then
%                         res := append(res, list op);
%                     res := append(res, cexp1(car exp, wt))
%                 >>
%             else
%                 while exp := cdr exp do
%                     res := append(append(res, list op),
%                                   cexp1(car exp, wt))
%         >>;
%         if wtin >= wt then res := insertparens res;
%         return res
%         end
%     else if car exp eq 'literal then
%         cliteral exp
%     else if car exp eq 'range then
%         if cadr exp = 0 then cexp caddr exp
%            else gentranerr('e,exp,
%                    "C does not support non-zero lower bounds",nil)
%     else if car exp eq '!:rd!: then
%         if smallfloatp cdr exp then
%             list cdr exp
%         else
%         begin scalar mt; % Print bigfloats more naturally.
%             mt  := cddr exp;
%             exp := explode cadr exp;

%             mt  := mt + (length exp) - 1;
%             exp := list('literal, 
%                         compress ( (car exp) . '!. . (cdr exp) ));
%             if null (mt = 0) then
%                 exp := append(exp,
%                               list('!e,mt));
%             return cliteral exp;
%         end
%     else if car exp memq '(!:cr!: !:crn!: !:gi!:) then
%         gentranerr('e,exp,"C doesn't support complex data type",nil)
%     else if arrayeltp exp then
%         cname car exp . foreach s in cdr exp conc
%                                 insertbrackets cexp1(s, 0)
%     else if memq(car exp,!*c!-functions!*) then
%         begin scalar op,res,dblp;
%         dblp := not get(car exp,'!*int!-args!*);
%         op := cname car exp;
%         res := '!( . list op ;
%         while exp := cdr exp do
%         <<
%            op := cexp1(car exp, 0);
%            if dblp and not
%                 (is!-c!-float(op) or is!-c!-float(car exp)) then
%              op := if null cdr op and fixp car op then
%                  list float car op
%              else
%                  append(list('!(,'!d!o!u!b!l!e,'!),'!(),append(op,list '!)));
%            res := if cdr exp then
%              append('!, . reversip op,res)
%            else
%              append(reversip op,res);
%         >>;
%         return reversip ( '!) . res )
%         end
%     else if cfunctcallp exp then
%         begin
%         scalar op, res;
%         op := cname car exp;
%         exp := cdr exp;
%         res := '!( . cexp1(car exp, 0);
%         while exp := cdr exp do
%             res := append(res, '!, . cexp1(car exp, 0));
%         return op . append(res, list('!)) )
%         end
%     else
%         begin
%         scalar op, res;
%         op := cname car exp;
%         exp := cdr exp;
%         res := append( '![ . cexp1(car exp, 0),'( !]) );
% 	% Changed to generate proper C arrays - mcd 25/9/89
%         while exp := cdr exp do
%             res := append(res, append('![ . cexp1(car exp, 0)
%                                       ,'( !]) ) );
%         return op . res
%         end;
%
%
%put('c,'boolean!-type,'!i!n!t);  %% RmS generate proper case
%
% symbolic procedure mkfpascprocdec(type, name, params, paramtypes);
% <<  pascfuncname!* := name;
%     params := append('!( . cdr for each p in params
%                               conc '!, . pascdum(p, paramtypes),
%                      list '!));
%     if type then
%         append(mkpasctab() . 'function . '!  . pascexp name,
%                append(params,list( '!:, type,  '!;, mkpascterpri())))
%     else
%         append(mkpasctab() . 'procedure . '!  . pascexp name,
%                append(params, list('!;, mkpascterpri())))
% >>;
% 
%
%symbolic procedure string2id u; intern u;

flag('(lispcodeexp cexp1 mkfpascprocdec string2id),'lose);


endmodule;

end;
