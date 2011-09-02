module pm;   % The PM Pattern Matcher.

% Author: Kevin McIsaac.

% create!-package('(pm pmpatches formgen pattdefn pmintrfc pattperm
%                   unify),
%                 '(contrib pm));

remflag('(i),'reserved);  % This package uses I as a global index!!

Comment This is a fairly basic set of definitions for Ap, Map and Ar.
        It needs some work. The routine Ar is particularly bad;

% Pattern directed application.

symbolic operator ap;

symbolic procedure ap(f,v);
   if car v neq 'list then typerr(v,'ap)
   else if not genexp f then 
      if atom f then f . cdr v
      else append(f,cdr v)
   else 
   begin scalar nv;
      nv := idsort union(findnewvars f,nil);
      v  := cdr v;
      f := sublis(npair(nv, v), f);
      if length nv < length v then f := append(f,pnth(v,length nv +1));
      return f
    end;

symbolic procedure npair(u, v);
   % Forms list of pairs from unequal length list. Terminates at end of
   % shortest list.
   if u and v then (car u . car v) . npair(cdr u, cdr v) else nil;

%Pattern directed MAP

put('map,'psopfn,'map0);

symbolic procedure map0 arg;
   if length arg < 2 then nil
   else map1(car arg,cadr arg,if length arg >= 3 then caddr arg else 1);

symbolic procedure map1(fn,v,dep);
   if dep>0 then car v . for each j in cdr v collect map1(fn,j,dep-1)
   else ap(fn,if atom v or car v neq 'list then list('list, v) else v);

put('ar, 'psopfn, 'ar0);

% ARange of ARray statement.

symbolic procedure ar0 arg;
   if length arg <= 1 then nil
    else ar1(car arg, if length arg >= 2 then cadr arg else 'list);

symbolic procedure ar1(arg,fn);
if fixp arg then ar4(list(list(1,arg,1)),fn)
else if atom arg or car arg neq 'list then typerr(arg,'ar)
else ar4(for each j in cdr arg collect aarg(j), fn);

symbolic procedure aarg(arg);
   revlis(
   if fixp arg or genp(arg) then list(1, arg, 1)
   else if atom arg  or car arg neq 'list then typerr(arg,'ar)
   else begin scalar l;
      arg := cdr arg;
      l := length arg;
      return if l eq 1 then list(1, car arg, 1)
              else if l eq 2 then list(car arg, cadr arg, 1)
              else if l eq 3 then list(car arg, cadr arg, caddr arg)
              else typerr(arg,"Ar")
     end);

symbolic procedure ar4(lst,fn);
   begin scalar s, u, v, w;
      u := caar lst; v := cadar lst; w := caddar lst; lst := cdr lst;
      while u <= v do
      << s := append(s,list u);
         u := u + w>>;
         return if length(lst) eq 0 then
            if fn eq 'list then 'list . s
            else  map1(fn, 'list . s, 1)
         else 'list . for each j in cdr map1(list(lst, fn),'list . s, 1)
                         collect ar4(car j, cdr j);
   end;

put('cat, 'psopfn, 'catx);

symbolic procedure catx u;
   % Concatenate two lists.
   (if not eqcar(x,'list) then typerr(car u,"list")
     else if not eqcar(y,'list) then typerr(cadr u,"list")
     else 'list . append(cdr x,cdr y))
   where x=reval car u, y=reval cadr u;


%Relational operators.

symbolic procedure simpeq(arg);
   begin scalar x;
      if length arg < 2 then typerr('equal . arg,"relation");
      arg := reval('difference . arg);
      arg := if numberp arg then reval(arg = 0)
              else <<arg := list('equal,arg, 0);
                     if x := opmtch(arg) then x else arg>>;
      return mksq(arg,1)
   end;

symbolic procedure simpgt(arg);
   begin scalar x;
      if length arg < 2 then typerr('greaterp . arg,"relation");
      arg := reval('difference . arg);
      arg := if numberp arg then reval(arg > 0)
              else <<arg := list('greaterp,arg, 0);
                     if x := opmtch(arg) then x else arg>>;
      return mksq(arg,1)
   end;

symbolic procedure simpge(arg);
   begin scalar x;
      if length arg < 2 then typerr('geq . arg,"relation");
      arg := reval('difference . arg);
      arg := if numberp arg then reval(arg >= 0)
              else <<arg :=  list('geq,arg, 0);
                     if x := opmtch(arg) then x else arg>>;
      return mksq(arg,1)
   end;

symbolic procedure simplt(arg);
   simpgt(list(cadr arg,car arg));

symbolic procedure simple(arg);
   simpge(list(cadr arg,car arg));

put('equal, 'simpfn, 'simpeq);

put('greaterp, 'simpfn, 'simpgt);

put('geq, 'simpfn, 'simpge);

put('lessp, 'simpfn, 'simplt);

put('leq, 'simpfn, 'simple);

endmodule;


module pmpatches; % Patches to make pattern matcher run in REDUCE 3.4.

% Author: Kevin McIsaac.
% Changes by Rainer M .Schoepf

% remflag('(evenp),'opfn);

% remprop('list,'evfn);

% remprop('list,'rtypefn);

% Redefine LISTEVAL so that the arguments are always returned in prefix
% form.

global '(simpcount!* simplimit!*);

symbolic procedure listeval(u,v);
   <<if (simpcount!* := simpcount!*+1)>simplimit!*
       then <<simpcount!* := 0;
              rederr "Simplification recursion too deep">>;
     u := if atom u
            then listeval(if flagp(u,'share) then eval u
                           else cadr get(u,'avalue),v)
           else car u . for each x in cdr u collect reval1(x,t);
     simpcount!* := simpcount!*-1;
     u>>;


% Allow EXPR as a keyword in patterns.

% remprop('expr,'stat);

% Make REVAL of an equation return a simplified value.

fluid '(substitution);

symbolic procedure equalreval u;
  if null substitution then 'equal . car u . list reval cadr u
   else if evalequal(car u,cadr u) then t
   else 0;

% Define function to prevent simplification of arguments of symbolic
% operators.
% If the i'th element of `list' is `nil' then the i'th argument of `fn'
% is left unsimplified by simp.  If `list' is longer that the argument
% list of `fn' then the extra indicators are ignored.  If `list' is
% shorter than the argument list of `fn' then the remaining arguments
% are simplified, eq nosimp(cat,'(nil T nil)) will cause the 1 and third
% arguments of the functions `cat' to be left un simplified.

symbolic procedure nosimp(fn,list);
  <<put(fn, 'nosimp, list);>>;

symbolic operator nosimp;

flag('(nosimp), 'noval);

symbolic procedure fnreval(u,v,mode);
   % Simplify list u according to list v. If mode is NIL use AEVAL
   % else use REVAL.
   if null u then nil
    else if v eq t then u
    else if null v then for each j in u collect reval1(j ,mode)
    else ((if car v then car u
           else reval1(car u, mode)) . fnreval(cdr u,cdr v,mode));

% Next two routines are changes to module SIMP to add NOSIMP code.

symbolic procedure opfneval u;
   lispeval(car u . for each j in 
                  (if flagp(car u,'noval) then cdr u 
                  else fnreval(cdr u,get(car u,'nosimp),t))
                            collect mkquote j);

global '(ncmp!* subfg!*);

symbolic procedure simpiden u;
   % Convert the operator expression U to a standard quotient.
   % Note: we must use PREPSQXX and not PREPSQ* here, since the REVOP1
   % in SUBS3T uses PREPSQXX, and terms must be consistent to prevent a
   % loop in the pattern matcher.
   begin scalar bool,fn,x,y,z,n;
    fn := car u; u := cdr u;
    if x := valuechk(fn,u) then return x;
    if not null u and eqcar(car u,'list)
      then return mksq(list(fn,aeval car u),1);
    % *** Following line added to add nosimp code.
    x := fnreval(u, get(fn, 'nosimp),nil);
%    x := for each j in cdr u collect aeval j;
    u := for each j in x collect
              if eqcar(j,'!*sq) then prepsqxx cadr j
               else if numberp j then j
               else <<bool := t; j>>;
    if u and car u=0
       and flagp(fn,'odd) and not flagp(fn,'nonzero)
      then return nil ./ 1;
    u := fn . u;
    if flagp(fn,'noncom) then ncmp!* := t;
    if null subfg!* then go to c
     else if flagp(fn,'linear) and (z := formlnr u) neq u
      then return simp z
     else if z := opmtch u then return simp z
     else if z := get(car u,'opvalfn) then return apply1(z,u);
 %    else if null bool and (z := domainvalchk(fn,
 %                for each j in x collect simp j))
 %     then return z;
    c:  if flagp(fn,'symmetric) then u := fn . ordn cdr u
         else if flagp(fn,'antisymmetric)
          then <<if repeats cdr u then return (nil ./ 1)
              else if not permp(z:= ordn cdr u,cdr u) then y := t;
        % The following patch was contributed by E. Schruefer.
        fn := car u . z;
        if z neq cdr u and (z := opmtch fn)
          then return if y then negsq simp z else simp z;
        u := fn>>;
    if (flagp(fn,'even) or flagp(fn,'odd))
       and x and minusf numr(x := simp car x)
     then <<if flagp(fn,'odd) then y := not y;
        u := fn . prepsqxx negsq x . cddr u;
        if z := opmtch u
          then return if y then negsq simp z else simp z>>;
    u := mksq(u,1);
    return if y then negsq u else u
   end;

endmodule;


module formgen; % Form function for !?.

% Author: Kevin McIsaac.

put('!?,'formfn,'formgen)$

symbolic procedure formgen(u,vars,mode);
   begin scalar x;
     u := cadr u;
     if atom u
       then if u eq '!?
             then <<u := intern '!?!?;
                    x := list(mkquote u,mkquote 'mgen,t)>>
             else <<u := intern compress('!! . '!? . explode u);
                    x := list(mkquote u,mkquote 'gen,t)>>
     else if car u neq '!?
      then <<u := intern compress('!! . '!? . explode car u) . cdr u;
             x := list(mkquote car u,mkquote 'gen,t)>>
     else if car u eq '!? and atom cadr u
      then <<u := intern compress('!! . '!? . '!! . '!?
                                      . explode cadr u);
             x := list(mkquote u,mkquote 'mgen,t)>>
     else
     <<u := cadr u;
       u := intern compress('!! . '!? . '!! . '!? . explode car u)
               . cdr u;
       x := list(mkquote car u,mkquote 'gen,t)>>;
      return list('progn,'put . x,form1(u,vars,mode))
   end;

endmodule;


module pattdefn; %Notational conveniences and low level routines for the
                 % UNIFY code.

% Author: Kevin McIsaac.
% Changes by Rainer M. Schoepf 1991.

fluid('(freevars op r p i upb
        identity expand acontract mcontract comb count symm ))$

% Binding routines.  These would be more efficient with a more direct
% mechanism.

symbolic procedure bind(u, v);         %push the value of v onto the
   put(u,'binding,v.get(u,'binding))$   %binding stack of u

symbolic procedure binding(u);              %Top most binding on stack
   (lambda x; if x then car x) get(u,'binding)$

symbolic procedure unbind(u);                  %pop binding off stack
   put(u,'binding, cdr get(u,'binding))$

symbolic procedure newenv(u);           % Mark a new environment.
   bind(u, 'unbound)$                   % Give UNIFY lexical scoping.

symbolic procedure restorenv(u);        % Should include error checks?
   unbind(u)$

symbolic procedure pm!:free(u);       % Is u a pm unbound free variable?
   binding(u) eq 'unbound$

symbolic procedure bound(u);           % Is u a pm bound free variable?
   (lambda x;  x and (x neq 'unbound)) binding u;

symbolic procedure meq(u,v);
 (lambda x; 
%    (if (x and (x neq 'unbound)) then x else u) eq meval v )
     (if (x and (x neq 'unbound)) then x else u) = v)
          binding u; 

% This has been fixed.
% symbolic procedure meval(u);
%    if eqcar(u,'minus) and numberp cadr u then -cadr u else u;


% Currently Mval does nothing.  It should be defined so that nosimp
% functions are handled properly.  By leaving it out the PM will not
% dynamically change pattern it is working on.  I.e.,
% m(f(1,2,3+c),f(?a,?b,?a+?b+?c)) will now return True.  If the code
% commented out is restored then this will give the expected result.
% However m(f(1_=natp 1),f(?a_=natp ?a)), where natp(?x) :- t, will not
% work.

symbolic procedure mval(u); u;
%===>   if not atom u then (reval bsubs(car u)) . cdr u
%===>   else bsubs u;

symbolic procedure bsubs(u);
   % Replaces free atoms by their bindings.  Would be nice to mark
   % expressions that no longer contain bunbound free variables
   if null u then u
   else if atom u then if bound(u) then binding u else u
   else for each j in u collect bsubs j;

symbolic procedure ident(op);
get(op,'identity)$

symbolic procedure genp(u);
   atom u and (get(u,'gen) or mgenp(u))$
   
symbolic procedure mgenp(u);
   atom u and get(u,'mgen)$

symbolic procedure suchp u;             %Is this a such that condition?
   not atom u and car u eq 'such!-that$

% False if any SUCH conditions are in wich all free variable are bound
% does not simplify to T.  Should we return free expressions partially
% simplified?

symbolic procedure chk u;
null u or u eq t or
(lambda x;
   if freexp(x) then 
      (lambda y; if null y then nil
                 else if y eq t then list x
                 else x.y) chk(cdr u)
   else if reval(x) eq t then chk(cdr u) else nil) bsubs car u$

symbolic procedure findnewvars u;
   if atom u then if genp u then list u else nil
    else for each j in u conc findnewvars j;

symbolic procedure freexp u;
   if atom u then pm!:free u else freexp car u or freexp cdr u;

symbolic procedure genexp u;
   if atom u then genp u else genexp car u or genexp cdr u;

endmodule;


module pmintrfc;  % Interface for pattern matcher.

% Author: Kevin McIsaac.
% Changes by Rainer M. Schoepf 1991.

% For some reason, this doesn't like being compiled as a module.

% REDUCE syntax for pattern matching.
%
% ?a
%   This is an ordinary pattern matching variable. It can any value.
%   
% ??a
%   This is a segment pattern variable. I can take any value as does ?a
%   or a set of values.
%
% ?a_=cond
%   ?a can only be matched is the condition does not evaluate to false
%
% exp1 -> exp2 
%   exp1 is replaced by exp2
%
% exp1 --> exp2 
%   exp1 is replaced by exp2, RHS is quoted. exp2 is simplified after
%   replacement
%
% M(exp,pat) 
%   Returns a list of replacements for pm variables in pat such that pat
%   and exp are equal. Where defined the properties of symmetry, assoc-
%   iativity and the identity element are used to match the expressions.
%
% S(exp,rep,rpt:1,depth:Inf) or S(exp,{rep1,rep2,...},rpt:1,depth:Inf)
%  The lhs of rep is matched against exp and subexpressions of exp.
%  When a match is found the replacements for pm variables in rhs are
%  substituted into the lhs and the resultant expression is used as a
%  replacement.  This is done to a maximum (tree) depth of dept, with a
%  maximum number of repeats rpt, to a (tree) depth of dept.

% S(exp,rep,depth:Inf) or S(exp,{rep1,rep2,...},depth:Inf)
%   Shorthand notation for S with Inf number of rpt's
%
% exp1 :- exp2
%   exp1 is  added  to a  global  list of  automatic  replacements. Most
%   specific  rules are ordered  before less specific  rules.  If a rule
%   already exists the the rule is replaced unless exp2 is null in which
%   case the rule is deleted.
%
% exp1 ::- exp2
%   as above except the RHS is quoted.
%
global '(subfg!*);

fluid '(!*trpm rpt substitution varstack!*);

switch trpm;

put('m,'psopfn,'mx);

symbolic procedure mx u; m1(reval car u,reval cadr u);

symbolic procedure m1(exp, temp);
   begin scalar substitution, mmatch, count, freevars;
      count := 0;
      freevars := idsort union(findnewvars temp,nil);
      substitution := if freevars then freevars else t;
      for each j in freevars do newenv j;
      mmatch := amatch(temp, exp, t, nil);
      for each j in freevars do restorenv j;
      if mmatch then return
         if freevars then 'list . for each j in pair(freevars, mmatch)
                                      collect list('rep, car j, cdr j)
         else t
   end;

symbolic procedure fixreplist(repset);
   % Check that repset is properly formed and add multi-generic
   % variables to assoc functions.
   begin scalar replist;
      if car(repset) memq '(rep repd) then replist := list(repset)
       else replist := cdr repset;
      replist := for each rep in replist collect fixrep(rep);
      return replist
   end;

Comment It is necessary to replace all free variables by unique ones
        in order to avoid confusion during the superset operation.
        To this end we generate replace them by special gensyms
        before putting them in the rules database.  This is not
        visible to the user;

fluid '(pm!:gensym!-count!*);

symbolic (pm!:gensym!-count!* := 0);

symbolic procedure pm!:gensym;
  compress ('!? . '!_ .
    explode (pm!:gensym!-count!* := pm!:gensym!-count!* + 1));

fluid '(freevarlist!*);

symbolic procedure make!-unique!-freevars form;
  if atom form then
    if get(form,'gen) then begin scalar x;
      x := atsoc (form, freevarlist!*);
      if null x then << x := (form . pm!:gensym());
                        put (cdr x, 'gen, t);
                        freevarlist!* := x .  freevarlist!*>>;
      return cdr x
     end
     else form
    else for each x in form collect make!-unique!-freevars x;

symbolic procedure fixrep(repl);
   << (repl := make!-unique!-freevars repl) where freevarlist!* := nil;
   % Should check if the extra multi-generic variables are required.
   if flagp(caadr repl,'assoc) then 
      if flagp(caadr repl,'symmetric) then
         list(car repl,append(cadr repl,list('!?!?!;)), 
            list(caadr repl,caddr repl,'!?!?!;))
      else 
         list(car repl,caadr(repl) .
              ('!?!?!^ . append(cdadr repl,list('!?!?!;))),
            list(caadr repl,'!?!?!^,caddr repl,'!?!?!;))
   else repl >>;


put('s,'psopfn,'sx);

symbolic procedure sx arg;
   % Fill in args for s0. Default: repeat 1, depth Inf.
   reval 
      s0(reval car arg, reval cadr arg,
            if cddr arg then reval caddr arg  else 1,
            if cddr arg and cdddr arg then reval car cdddr arg
             else 'inf);

put('si,'psopfn,'si!-x);

symbolic procedure si!-x arg;
   % Fill in args for s0. Default: repeat Inf, depth Inf.
   reval
      s0(reval car arg,reval cadr arg, 'inf,
            if cddr arg then reval caddr arg  else 'inf);

symbolic procedure s0(exp, repset,rpt,depth);
   % Breadth first search.  Rpt is passed as a fluid.
   if length repset <= 1 or not memq(car repset,'(rep repd list))
     then exp
    else if (depth neq 'inf and depth < 0)
          or (rpt neq 'inf and rpt <=0)  or atom(exp) then exp
    else sbreadth(exp,fixreplist repset,depth) ;

symbolic procedure sbreadth(exp,replist,depth);
   % Substitute a set of replacements into  the root expression until
   % expression stops changing, then recurse on all the sub expressions.
   <<exp:= sroot(exp,replist);
     if (depth neq 'inf and depth <= 0)
        or (rpt neq 'inf and rpt <=0)  or atom(exp) then exp
      else ssbreadth(exp,replist,
                     if depth neq 'inf then depth-1 else depth)>>;

symbolic procedure ssbreadth(exp,replist,depth);
   begin scalar newexp, new,  reps;
      if (depth neq 'inf and depth < 0)
          or (rpt neq 'inf and rpt <= 0)  or atom(exp) then return exp;
      repeat
      begin
         new := nil;
         reps := replist;
       a:   exp := reval for each subexp in exp collect
               << newexp := sroot1(subexp,car reps) ;
                  new := new or (subexp neq newexp);
                  newexp
               >>;
         if not (new or null(reps := cdr reps)) then go to a;
      end
      until(atom exp or not new);
      return
         if (depth neq 'inf and depth <= 0)
             or (rpt neq 'inf and rpt <= 0)  or atom(exp) then exp
         else for each subexp in exp collect
               ssbreadth(subexp,replist,
                         if depth neq 'inf then depth-1 else depth)
   end;


put('sd,'psopfn,'sdx);

symbolic procedure sdx arg;
   % Fill in args for sd0. Default: repeat 1, depth inf.
   reval
      sd0(reval car arg,reval  cadr arg,
            if cddr arg then reval caddr arg  else 1,
            if cddr arg and cdddr arg then reval car cdddr arg
             else 'inf);

put('sdi,'psopfn,'sdi);

symbolic procedure sdi arg;
   % Fill in args for sd0. Default: repeat Inf, depth Inf.
   reval
      sd0(reval car arg,reval  cadr arg, 'inf,
            if cddr arg then reval caddr arg  else 'inf);

symbolic procedure sd0(exp, repset,rpt,depth);
   % Depth first search.
   if length repset <= 1 or not memq(car repset,'(rep repd list))
     then exp
    else if (depth neq 'inf and depth < 0)
       or (rpt neq 'inf and rpt <= 0)  or atom(exp) then exp
    else sdepth(exp,fixreplist repset,depth) ;

symbolic procedure sdepth(exp,replist,depth);
   <<exp:= sroot(exp,replist);
     if (depth neq 'inf and depth <= 0)
        or (rpt neq 'inf and rpt <= 0)  or atom(exp) then exp
      else car(exp) . for each subterm in cdr exp collect
                sdepth(subterm,replist,
                       if depth neq 'inf then depth-1 else depth)>>;

symbolic procedure sroot(exp,replist);
   % Substitute a set of replacements into a root expression until the
   % expression stops changing.  When a replacement succeeds the
   % substitution process restarts on the new expression at the
   % beginning of the replacement list.
   begin scalar oldexp, reps;
      if  (rpt neq 'inf and rpt <=0)  or atom(exp) then return exp;
      repeat
       begin
         oldexp := exp;
         reps := replist;
       a:   exp := sroot1(exp,car reps);
         if not(exp neq oldexp or null(reps := cdr reps)) then go to a;
         if exp neq oldexp then exp := reval exp
       end
      until(atom exp or exp eq oldexp);
      return exp;
   end;

symbolic procedure sroot1(exp,rep);
   % Try to substitute a single replacement into a root expression once
   % only.
   begin scalar freevars,substitution,mmatch;
      if (rpt neq 'inf and rpt <=0)  or
           atom(exp) or (car(exp) neq caadr(rep)) then return exp;
      freevars := union(findnewvars cadr rep,nil);
      substitution := caddr rep;
      for each j in freevars do newenv j;
      if !*trpm then <<write("Trying rule  "); rprint(rep);
                       write("against      "); rprint(exp)>>;
      mmatch := amatch(cadr rep, exp, t,nil);
      if !*trpm
        then <<if mmatch then <<write("producing    ");
                              rprint(mmatch := embed!-null!-fn mmatch)>>
                else <<write("failed"); terpri()>>;
               terpri()>>;
      for each j in freevars do restorenv j;
      return if mmatch then
             << if (rpt neq 'inf) then rpt := rpt - 1;
                embed!-null!-fn mmatch>>
             else exp
   end;

symbolic procedure embed!-null!-fn u;
   if atom u then u
    else for each j in u conc
       if atom j then list(j)
        else if car j eq 'null!-fn then embed!-null!-fn cdr j
        else list(embed!-null!-fn j);

algebraic operator null!-fn;

% Code for printing null-fn(a,b,...) as [a,b,...]. Modeled on LIST code.

put('null!-fn,'prifn,'null!-fn!-pri);

fluid '(orig!* posn!*);

symbolic procedure null!-fn!-pri l;
   % This definition is basically that of INPRINT, except that it
   % decides when to split at the comma by looking at the size of
   % the argument.
   (begin scalar split,u;
      u := l;
      l := cdr l;
      prin2!* "[";
      orig!* := if posn!*<18 then posn!* else orig!*+3;
      if null l then go to b;
      split := treesizep(l,40);   % 40 is arbitrary choice.
   a: maprint(negnumberchk car l,0);
      l := cdr l;
      if null l then go to b;
      oprin '!*comma!*;
      if split then terpri!* t;
      go to a;
   b: prin2!* "]";
      return u
   end)
    where orig!* := orig!*;

% Assignments and automatic replacements.

symbolic operator rset;

symbolic procedure rset(temp,exp);
   % Add new rule to rule list. If RHS is null then delete rule.
   if atom temp then setk(temp,exp)
    else begin scalar oldsubfg!*,varstack!*;
             %rebind subfg. Don't do this do that(yuck..lisp..)
             % rebind varstack!* since the template is simplified again 
      oldsubfg!* := subfg!*; subfg!* := nil;
      temp := reval temp;
      put(car temp,'opmtch,
          rinsert(fixrep('rset . list(temp,exp)),
                  get(car temp,'opmtch)));
      subfg!* := oldsubfg!*;
      return exp
    end;

symbolic operator rsetd;

symbolic procedure rsetd(temp,exp);
   % Delayed version.
   if atom temp then 'hold . setk(temp,exp)
    else 'hold . list
      begin scalar oldsubfg!*,varstack!*;
           %rebind subfg. Don't do this do that(yuck..lisp..)
         oldsubfg!* := subfg!*; subfg!* := nil;
         temp := reval temp;
         put(car temp,'opmtch,
             rinsert(fixrep('rsetd . list(temp,exp)),
                     get(car temp,'opmtch)));
         subfg!* := oldsubfg!*;
         return exp
      end;

symbolic procedure rinsert(rule,rulelist);
% Insert rule in rule list so that most specific rules are found first.
% Use super-set idea, due to Grief.  If an equivalent rule exits then
% replace with new rule.  A new rule will be placed as far down the rule
% list as possible If the RHS of rule is nil then delete the rule.

if null rulelist or not atom caar rulelist then rule . rulelist
   else
     (lambda ss;
       if ss eq 'equal then
          if cadr rule then rule . cdr(rulelist)
          else cdr(rulelist)
       else if ss eq 't then rule . rulelist
       else car(rulelist) . rinsert(rule,cdr rulelist))
     superset(cadar rulelist,cadr rule);

symbolic procedure superset(temp1,temp2);
   begin scalar mmatch;
      mmatch := m1(temp2,temp1);
      return(
         if null mmatch then nil
         else if mmatch eq 't then 'equal
         else if not bound2gen(cdr mmatch) then t
         else if null (mmatch := m1(temp1,temp1)) then  t
         else 'equal)
   end;

symbolic procedure bound2gen(replist);
   % True if all Generic variables are bound to generic variables.
   null replist or (genp(caddar replist) and bound2gen(cdr replist));

symbolic operator arep;

symbolic procedure arep(replist);
   % Add the replacements in replist to the list of automatically
   % applied replacements.
   if atom replist then replist
    else if car replist eq 'rep
     then list('rset ,cadr replist,caddr replist)
    else if car replist eq 'repd
     then list('rsetd,cadr replist,caddr replist)
    else if car replist eq 'list then
%    '!*set!* . for each rep in cdr replist collect arep(rep)
     'list . for each rep in cdr replist collect arep(rep)
    else nil;

symbolic operator drep;

symbolic procedure drep(replist);
   % Delete the replacements in replist from the list of automatically
   % applied replacements.
   if atom replist then replist
    else if car replist eq 'rep  then list('rset ,cadr replist,nil)
    else if car replist eq 'repd then list('rsetd,cadr replist,nil)
    else if car replist eq 'list then
%     '!*set!*.for each rep in cdr replist collect Drep(rep)
     'list . for each rep in cdr replist collect drep(rep)
    else nil;

symbolic procedure opmtch(exp);
   begin scalar oldexp, replist, rpt;
      rpt := 'inf;
      replist := get(car exp, 'opmtch);
      if null(replist) or null subfg!* then return nil;
      oldexp := exp;
      repeat
      exp := if (atom caar replist) then sroot1(exp, car replist)
             else oldmtch(exp,car replist)
      until (exp neq oldexp or null(replist := cdr replist));
      return if exp eq oldexp then nil else exp
   end;

symbolic procedure oldmtch(exp,rule);
   begin scalar x, y;
      y := mcharg(cdr exp, car rule,car exp);
      while (y and null x) do
      <<x := if eval subla(car y,cdadr rule)
               then subla(car y,caddr rule);
        y := cdr y>>;
      return if x then x else exp
   end;

put('!?,'gen,t);

put('!?!?!;,'mgen,t);

put('!?!?!$,'mgen,t);

put('!?!?!^,'mgen,t);

symbolic operator prop!-alg;

newtok '((!_) prop!-alg);

symbolic procedure prop!-alg(f);
   begin scalar x;
      x := prop f;
      while x do <<prin2(car x); prin2("  "); print(cadr x); print(" ");
                   x := cddr x>>
   end;

symbolic operator preceq;

symbolic procedure preceq(u,v);
   % Give u same precedence as v.
   <<put(u,'op,get(v,'op));
     put(u,'infix,get(v,'infix));>>;

newtok '((!: !- )    rset);
newtok '((!: !: !- ) rsetd);
newtok '((!- !>)    rep);
newtok '((!- !- !>) repd);
newtok '((!_ !=) such!-that);

flag ('(such!-that), 'spaced);  % _ adjacent to symbols causes problems.

Comment I hate to do it that way, but otherwise the mode is symbolic
        when the module is loaded which messes up the infix statement;


symbolic (!*mode := 'algebraic);

algebraic;

infix :-;
nosimp(:-,'(t nil));
%precedence :-,:=;  %can't do this

infix ::-;
nosimp(::-,'(t t));
precedence rsetd,rset;

infix ->;
precedence ->,rsetd;

infix -->;
nosimp(-->,'(nil t));
precedence -->,->;

infix _=;
nosimp(_=,'(nil t));
precedence _=,-->;

operator hold;
nosimp(hold,t);
flag('(rset rsetd rep repd such!-that), 'right);
preceq(rsetd,rset);
preceq(-->,->);

flag('(plus times expt),'assoc);

endmodule;


module pattperm;   % Rest of unify --- argument permutation, etc.

% Author: Kevin McIsaac.

% When sym!-assoc is off, PM does not force normal generic variables to
% take more than one argument if a multi-generic symbol is present. This
% makes the patterns much more efficient but not fully searched. Sane
% patterns do not require this.  For example
% m(a+b+c,?a+??c) will return {?a -> a, ??c -> null!-fn(b,c)} but not
% {?a -> a+b, ??c -> c} or {?a -> a+b+c, ??c -> null!-fn()}

global('(!*sym!-assoc))$  

global('(!*udebug))$      %print out next information

symbolic procedure first0(u,n);
   if n>0 then car u . first0(cdr u,n-1) else nil;

symbolic procedure last0(u,n);
   if n<1 then u else last0(cdr u,n-1);

symbolic procedure list!-mgen u;
   % Count the number of top level mgen atoms.
   begin integer i;
      for each j in u do if atom j and mgenp(j) then i := i+1;
      return i
   end;

symbolic procedure initarg(u);
   begin scalar  assoc, mgen, flex, filler; integer n, lmgen;
      symm := flagp(op,'symmetric);
      n := length(p) - length(r) + 1;
      identity := ident(op);
      mgen  := mgenp(car r);
      lmgen := list!-mgen(cdr r);
      assoc := flagp(op,'assoc)
                  and not(symm and(lmgen > 0) and not !*sym!-assoc);
      flex :=  (length(r)>1) and (assoc or lmgen);
      filler:= n > 1 or (identity and length p > 0);
      %
      mcontract := mgen and filler;
      acontract := assoc and filler and not mgen;
      expand := identity and (n < 1 or flex);
      %
      i := if flex or n < 1 then
              if mgen then 0
              else 1
           else n;
      upb := if identity then length p else n + lmgen;
      if symm then comb := initcomb u
   end;

symbolic procedure nextarg u;
   if symm then s!-nextarg u else o!-nextarg u;

symbolic procedure o!-nextarg u;
   begin scalar args;
      if !*udebug then uprint(nil);
      args :=
         if (i = 1)   and (i <= upb) then u
         else if (i = 0)   and (i <= upb) then '(null!-fn).u
         else if acontract and (i <= upb)
          then mval((op . first0(u,i)) . last0(u,i))
         else if mcontract and (i <= upb)
          then ('null!-fn . first0(u,i)) . last0(u,i)
         else if expand then <<expand := nil; identity . u>>;
      i := i + 1;
      return args
   end;
 
symbolic procedure s!-nextarg u;
   begin scalar v, args;
      if !*udebug then uprint(nil);
           if null comb then<< i := i + 1; comb := initcomb u>>;
      args :=
      if (v := getcomb(u,comb) ) then
         if (i = 1)   and (i <= upb) then caar v . cdr v
         else if (i = 0)   and (i <= upb) then '(null!-fn).u
         else if acontract and (i <= upb) then mval((op.car(v)).cdr v)
         else if mcontract and (i <= upb) then ('null!-fn.car(v)).cdr v
         else if expand then <<expand := nil; identity . u>>
         else nil
       else if (i = 0)   and (i <= upb) then '(null!-fn).u
       else if expand then <<expand := nil; identity.u>>;
      return args
   end;

symbolic procedure getcomb(u,v);
   begin scalar group;
      comb :=  nextcomb(v,i);
      group := car comb;
      comb := cdr comb;
      return if group then group . setdiff(u,group) else nil
   end$

symbolic procedure uprint(u);
   <<if expand then <<prin2('expand);prin2(" ")>>;
     if mcontract then <<prin2('mcontract);prin2(" ")>>;
     if acontract then <<prin2('acontract);prin2("  ")>>;
        prin2(" upb = ");prin2(upb); prin2(" i = ");prin2(i);
     if symm then <<prin2('symmetric);prin2(comb)>>;
     terpri()>>$


symbolic procedure initcomb(u); u.nil$

symbolic procedure nextcomb(env,n);
   % Env is of the form args . env, where args is a list of arguments.
   % Value is list of all combinations of n elements from the list u.
   begin scalar args, nenv, v; integer i;
      args := car env; nenv := cdr env;
      return
         if n=0 then nil.nil
         else if (i:=length(args) - n)<0 then list(nil)
         else if i = 0 then args.nil
         else if nenv then <<v := nextcomb(nenv,n - 1);
                             (car(args) . car(v)) .
                                (if cdr v then args . cdr v
                                  else list cdr(args))>>
         else <<v := nextcomb(initcomb(cdr args),n - 1);
                (car(args) . car(v)) . (if cdr v then args . cdr v
                                        else list cdr(args))>>
   end;

endmodule;


module unify;   % Main part of unify code.

% Author: Kevin McIsaac.
% Changes by Rainer M. Schoepf 1991.

% The switch semantic, default on, controls use of semantic matching.

fluid '(!*semantic substitution);

switch semantic;

!*semantic := t;

symbolic procedure amatch(r,p,suchl,pmstack);
   if atom r then unify(nil,mval list r,list p,suchl, pmstack)
    else if not(atom p or (car r neq car p)) then
            unify(car r,mval  cdr r, cdr p, suchl, pmstack)
    else if suchp r then amatch(cadr r, p, caddr r . suchl, pmstack)
    else if !*semantic then resume(list('equal,r,p).suchl, pmstack);

symbolic procedure suspend(op,r,p,suchl, pmstack);
   % Process the interrupting operator.
   amatch(car r, car p,suchl,list(op.cdr r,op.cdr p ). pmstack);

symbolic procedure resume(suchl,pmstack);
   % Resume interrupted operator.
   if pmstack then amatch(caar pmstack,cadar pmstack,suchl,cdr pmstack)
    else if chk(suchl) eq t then bsubs substitution;

symbolic procedure unify(op,r,p,suchl,pmstack);
   if null r and null p then resume(suchl,pmstack) % Bottom of arg list.
    else if null(r) then
        <<prin2("UNIFY:pattern over-run for function ");print(op);nil>>
    else if null(p) and not (ident(op ) or mgenp(car r)) then
%       <<prin2("UNIFY:rule over-run for function ");print(op);NIL>>
        nil
    else
      begin scalar mmatch, st, arg, symm, comb, identity,
             mcontract, acontract, expand; integer i, upb;
         if pm!:free(car r) then  suchl := genp(car r).suchl;
         initarg(p);
         while (not(mmatch) and (arg := nextarg(p))) do
            begin
               if not atom(car r)
                 then mmatch := suspend(op,r,arg,suchl, pmstack)
               else if (pm!:free(car r)) then
               begin
                  bind(car r, car arg);
                     if (st := chk suchl) then
                        mmatch := unify(op,mval cdr r,cdr arg,st,
                                        pmstack);
                  unbind(car r);
               end
               else if meq(car r, car arg)
                then mmatch := unify(op,mval cdr r,cdr arg,suchl,
                                     pmstack)
            end;
         return mmatch
       end;

endmodule;


end;
