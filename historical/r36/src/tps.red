module tps; % Truncated Power Series.

% Authors: Julian Padget & Alan Barnes <barnesa@aston.ac.uk>.
% Version 1.31 March 1993.
%
% Revisions:
%
% 20 Mar 93.  Bug in PS!:EXPT!-CRULE corrected.
%             ps!:order!-limit increased to 100.
%
% 16 Sep 90.  Bugs in PS!:EXPT!-CRULE, PS!:EXPT!-ERULE corrected.
%             Treatment of expt generally improved.
%             PSREVERSE now only takes one argument: the series to be
%             inverted.  PSCHANGEVAR added for those who feel the
%             need to change the expansion variable.
%             Code for pscompose and psreverse generalised to handle
%             the point at infinity correctly and to deal with series
%             with a negative order correctly.
%             Code for simppssum improved to detect non-
%             strictly increasing exponents.
%
%  6 Sep 90   PSSUM added to allow definition of series whose
%             general term is known.
%
%  8 Aug 90.  FUNCTION changed to QUOTE to avoid FUNARG problem when
%             interpreting code on SLISP based systems. Need to be
%             careful with quoted lambdas!
%
% 26 Jul 90.  JHD's smacro's ps!:numberp and ps!:atom added to improve
%             behaviour of system after ON BIGFLOAT.
%             Still dicky with NUMVAL ON. Need to REMPROP properties
%             !:bf!:, !:ft!: etc. from !:ps!: ?  (AB)

% 25 Jul 90.  Global declaration of s added in ps:unknown-crule. Needed
%             in UOLISP, avoids warning messages in some other Lisps.
%             simp:ps1 tidied up (now uses selectors to access terms)

% 24 Jan 90.  Ps:evaluate corrected (missing assignment for next).

%  7 Jul 89.  Explicit compilation and evaluation rules for SQRT and
%             EXPT have been added.  This avoids the infinite loops that
%             could sometimes occur when ps!: unknown!-crule was used to
%             generate recurrence relations for rational powers of a
%             power series.
%             A few bugs have been fixed notably one in difff and the
%             efficiency of code has been improved in several places.
%             Experimental code has been added to allow the domain mode
%             to be set to TPS by typing ON TPS.  With this switch on,
%             quotients of power series are expanded automatically as
%             are (when NUMVAL is on) expressions such as sin a, where a
%             is a power series.

%  3 Mar 89.  Addition of code for reversion of series.  Modification
%             of internal form to avoid circular lists as arguments.
%             Minor bug fixes.

% A power series object is a tagged tuple of the following form:
%
% (:ps: . [<order>,
%          <last-term>,
%          <variable>,
%          <expansion-point>,
%          <value>,
%          <terms>,
%          <ps-expression])
%
% <order> is the exponent of the first term of the series and is also
%          used to modify the index when accessing components of the
%          series which are addressed by power
%
% <last-term> the power of the last term generated in the series
%          largely for the benefit of the printing routine
%
% <variable> is the dependent variable of this expansion, needed, in
%          particular, for printing and when combining two series
%
% <expansion!-point> is self-explanatory except that
%          ps!:inf denotes expansion about infinity
%
% <value>  is the originating prefix form which is needed to allow for
%          power series variables appearing inside other power series
%          expressions
%
% <terms>  is an alist containing the terms of the series computed so
%          far, access is controlled using <order> as an index base.
%
% <ps-expression> is a power series object corresponding to the prefix
%          form of which the expansion was requested, the first element
%          of which is the ps!:operator and the rest of which are the
%          ps!:operands which may themselves be pso's
%
% In addition we have the following degenerate forms of power series
% object:
%        (!:ps!: . <identifier>)  the value of <identifier> is a vector
%        as above(used in automatically generated recurrence relations)
%        <number>
%        <identifier>   2nd argument of DF, INT

create!-package('(tps tpscomp tpseval tpsdom tpsrev tpsfns tpselfns
                  tpssum),
                '(contrib tps));

fluid '(ps!:exp!-lim  knownps ps!:max!-order);

flag('(!:ps!:),'noconvert);

% Some structure selectors and referencers.

symbolic smacro procedure rands e;
  cdr e;

symbolic smacro procedure rand1 e;
   cadr e;

symbolic smacro procedure rand2 e;
   caddr e;

symbolic smacro procedure rator e;
  car e;

symbolic smacro procedure ps!:domainp u;
   atom u or (car u neq '!:ps!:) and not listp u;

symbolic smacro procedure constantpsp u;
   null ps!:depvar u;

symbolic smacro procedure ps!:p u;
  pairp u and (car u = '!:ps!:);

symbolic smacro procedure ps!:atom u;
  atom u or (car u neq '!:ps!: and get(car u,'dname));

symbolic smacro procedure ps!:numberp u;
  numberp u or (car u neq '!:ps!: and get(car u,'dname));

symbolic procedure ps!:getv(ps,i);
   if eqcar(ps,'!:ps!:) then
        if idp cdr ps then getv(eval cdr ps,i)
         else getv(cdr ps,i)
   else rerror(tps,1,list("PS:GETV: not a ps",ps));

symbolic procedure ps!:putv(ps,i,v);
     if eqcar(ps,'!:ps!:) then
        if idp cdr ps then putv(eval cdr ps,i,v)
         else putv(cdr ps,i,v)
     else rerror(tps,2,list("PS:PUTV: not a ps",ps));

symbolic procedure ps!:order ps;
 if ps!:atom ps then 0
  else ps!:getv(ps,0);

symbolic smacro procedure ps!:set!-order(ps,n);
   ps!:putv(ps,0,n);

symbolic procedure ps!:last!-term ps;
  if ps!:atom ps then ps!:max!-order
  else  ps!:getv(ps,1);

symbolic (ps!:max!-order:= 2147483647);
% symbolic here seems to be essential in Cambridge Lisp systems

symbolic smacro procedure ps!:set!-last!-term (ps,n);
   ps!:putv(ps,1,n);

symbolic procedure ps!:depvar ps;
  if ps!:atom ps then nil
  else ps!:getv(ps,2);


symbolic smacro procedure ps!:set!-depvar(ps,x);
   ps!:putv(ps,2,x);

symbolic procedure ps!:expansion!-point ps;
  if ps!:atom ps then nil
  else ps!:getv(ps,3);

symbolic smacro procedure ps!:set!-expansion!-point(ps,x);
   ps!:putv(ps,3,x);

symbolic procedure ps!:value ps;
 if ps!:atom ps then if ps then ps else 0
  else ps!:getv(ps,4);


symbolic smacro procedure ps!:set!-value(ps,x);
   ps!:putv(ps,4,x);

symbolic smacro procedure ps!:terms ps;
  if ps!:atom ps then list (0 . ( ps . 1))
   else ps!:getv(ps,5);

symbolic smacro procedure ps!:set!-terms(ps,x);
   ps!:putv(ps,5,x);

symbolic procedure ps!:expression ps;
   if ps!:atom ps then ps
     else ps!:getv(ps,6);

symbolic smacro procedure ps!:set!-expression(ps,x);
   ps!:putv(ps,6,x);

symbolic smacro procedure ps!:operator ps;
   car ps!:getv(ps,6);

symbolic smacro procedure ps!:operands ps;
   cdr ps!:getv(ps,6);

symbolic procedure ps!:get!-term(ps,i);
   (lambda(psorder,pslast);
        if null psorder or null pslast then nil
          else if i<psorder then nil ./ 1
          else if i>pslast then nil
          else begin scalar term;
                 term:=assoc(i-psorder, ps!:terms ps);
                 return if term then cdr term
                         else nil ./ 1;
               end)
        (ps!:order ps,ps!:last!-term ps);

symbolic procedure ps!:term(ps,i);
   begin scalar term;
      term:=ps!:get!-term (ps,i);
      if term then return term;
      for j:=ps!:last!-term(ps)+1:i do
        term:= ps!:evaluate(ps,j);
      return term
   end;

symbolic procedure ps!:set!-term(ps,n,x);
   (lambda (psorder,terms);
    <<if null psorder then psorder:=ps!:find!-order ps;
      if n < psorder then
                rerror(tps,3,list (n, "less than the order of ", ps))
      else (lambda term;
            <<if (n=psorder and x = '(nil . 1)) then
                        ps!:set!-order(ps,n+1);
              if term then rplacd(term,x)
              else if atom x or (numr x neq nil) then
                if terms then nconc(terms,list((n-psorder).x))
                  else  ps!:set!-terms(ps,list((n-psorder).x))
      >>)
        assoc(n-psorder,terms)>>)
   (ps!:order ps,ps!:terms ps);

put('psexplim, 'simpfn, 'simppsexplim);

symbolic (ps!:exp!-lim := 6); % default depth of expansion
% symbolic here seems to be essential in Cambridge Lisp systems

symbolic procedure simppsexplim u;
 begin integer n;
   n:=ps!:exp!-lim;
   if u then ps!:exp!-lim := ieval carx(u,'psexplim);
  return (if n=0 then nil ./ 1 else n ./ 1);
 end;

symbolic procedure simpps a;
        if length a =3 then apply('simpps1,a)
        else rerror(tps,4,
          "Args should be <FORM>,<depvar>, and <point>:  simpps");

put('ps,'simpfn,'simpps);

symbolic procedure simpps1(form,depvar,about);
  if form=nil then
    rerror(tps,5,"Args should be <FORM>,<depvar>, and <point>: simpps")
   else if not kernp simp!* depvar then
         typerr(depvar, "kernel:  simpps")
       else if  smember(depvar,(about:=prepsq simp!* about)) then
          rerror(tps,6,"Expansion point depends on depvar:  simpps")
       else begin scalar knownps;
             return ps!:compile(ps!:presimp form,
                                depvar,
                                if about='infinity then 'ps!:inf
                                  else about)
                    ./ 1
            end;

put('psterm,'simpfn,'simppsterm);

symbolic procedure simppsterm a;
  if length a=2 then apply('simppsterm1,a)
   else rerror(tps,7,
        "Args should be of form <power series>,<term>: simppsterm");

symbolic procedure simppsterm1(p,n);
 << n := ieval n;
    p:=prepsq simp!* p;
    if ps!:numberp p then
         if n neq 0 or p=0 then nil ./ 1 else p ./ 1
    else if ps!:p p then
            << ps!:find!-order p; ps!:term(p,n)>>
         else typerr(p,"power series:  simppsterm1")
 >>;

put('psorder,'simpfn,'simppsorder);
put('pssetorder,'simpfn,'simppssetorder);

symbolic procedure simppsorder u;
  << u:=prepsq simp!* carx(u,'psorder);
     if ps!:numberp u then if u=0 then 'undefined else nil
     else if ps!:p u then ps!:find!-order u
          else typerr(u,"power series:  simppsorder")
  >> ./ 1;

symbolic procedure simppssetorder u;
  (lambda (psord,ps);
    if not ps!:p ps then typerr(ps,"power series: simppssetorder")
    else if not fixp psord then
             typerr(psord, "integer: simppssetorder")
         else <<u:=ps!:order ps;
                ps!:set!-order(ps,psord);
                (if u=0 then nil else u) ./ 1>>)
  (prepsq simp!* carx(cdr u,'pssetorder),prepsq simp!* car u);

put('psexpansionpt,'simpfn,'simppsexpansionpt);

symbolic procedure simppsexpansionpt u;
  << u:=prepsq simp!* carx(u,'psexpansionpt);
     if ps!:numberp u then 'undefined ./ 1
     else if ps!:p u then
                (lambda about;
                if about neq 'ps!:inf then
                     simp!* about else 'infinity ./ 1)
                (ps!:expansion!-point u)
          else typerr(u,"power series:  simppsexpansionpt")
  >>;

put('psdepvar,'simpfn,'simppsdepvar);

symbolic procedure simppsdepvar u;
  << u:=prepsq simp!* carx(u,'psdepvar);
     if ps!:numberp u then 'undefined
     else if ps!:p u then ps!:depvar u
          else typerr(u,"power series:  simppsdepvar")
  >> ./ 1;

put('psfunction,'simpfn,'simppsfunction);

symbolic procedure simppsfunction u;
  << u:=prepsq simp!* carx(u,'psfunction);
     if ps!:numberp u then u ./ 1
     else if ps!:p u then simp!* ps!:value u
          else typerr(u,"power series:  simppsfunction")
  >>;

symbolic procedure ps!:presimp form;
 if (pairp form) and
    ((rator form = 'expt) or (rator form = 'int)) then
        list(rator form, prepsort rand1 form, prepsort rand2 form)
 else prepsort form;

symbolic procedure prepsort u;
  % Improves log handling if logsort is defined.  S.L. Kameny.
   if getd 'logsort then logsort u else prepsq simp!* u;

% symbolic procedure tag!-if!-float n;
%   if floatp n then int!-equiv!-chk mkfloat n else n;

symbolic procedure !*pre2dp u;
 begin scalar x;
  u:=simp!* u;
  return  if fixp denr u
%           then if denr u = 1 and domainp(x:= tag!-if!-float numr u)
%                  then x
            then if denr u = 1 and domainp(x:= numr u) then x
             else if fixp numr u then mkrn(numr u, denr u)
end;

flag('(!:ps!:),'full);

put('!:ps!:,'simpfn,'simp!:ps!:);

symbolic procedure simp!:ps!: ps; simp!:ps1 ps ./1;

symbolic procedure simp!:ps1 ps;
     if ps!:atom ps or idp cdr ps  then ps
      else
        <<if not atom ps!:expression ps then
             begin scalar i, term, simpfn;
               if (ps!:operator ps ='psgen) then
                    simpfn:= 'simp!:ps1
               else simpfn:= 'resimp;
               i:=ps!:order ps;
               while term:=ps!:get!-term(ps,i) do
                 << ps!:set!-term(ps,i,apply1(simpfn,term)); i:=i+1>>
             end;
          if atom ps!:expression ps
              or null ps!:depvar ps or (ps!:operator ps ='ps!:summation)
            then nil
          else<<ps!:set!-expression(ps,
                  (ps!:operator ps) .
                     for each j in ps!:operands ps collect simp!:ps1 j);
                ps!:set!-value(ps,prepsq simp!* ps!:value ps)>>;
          ps>>;

% symbolic procedure simp!:ps1 ps;
%      if ps!:atom ps or idp cdr ps  then ps
%       else
%         <<if not atom ps!:expression ps then
%              begin scalar i, term, simpfn;
%                if (ps!:operator ps ='psgen) then
%                     simpfn:= 'simp!:ps1
%                else simpfn:= 'resimp;
%                i:=ps!:order ps;
%                while term:=ps!:get!-term(ps,i) do
%                  << ps!:set!-term(ps,i,apply1(simpfn,term)); i:=i+1>>
%              end;
%           if atom ps!:expression ps or null ps!:depvar ps then nil
%           else<<ps!:set!-expression(ps,
%                   (ps!:operator ps) . mapcar(ps!:operands ps,
%                                              'simp!:ps1));
%                 ps!:set!-value(ps,prepsq simp!* ps!:value ps)>>;
%           ps>>;

put('!:ps!:,'domain!-diff!-fn,'ps!:diff!:);

put('pschangevar,'simpfn,'simppschangevar);

symbolic procedure simppschangevar u;
  (lambda (newvar,ps, oldvar);
    if not ps!:p ps then typerr(ps,"power series: simppschangevar")
    else if not kernp newvar then
             typerr(prepsq newvar, "kernel: simppschangevar")
    else <<oldvar:=ps!:depvar ps; newvar:=prepsq newvar;
           if smember(newvar,ps!:value ps) and newvar neq oldvar then
               rerror(tps,8,"Series depends on new variable")
    else if oldvar then <<
             ps!:set!-depvar(ps,newvar);
             ps!:set!-value(ps,subst(newvar,oldvar,ps!:value ps));
             ps ./ 1>>
    else rerror(tps,9,"Can't change variable of constant series")>>)
   (simp!* carx(cdr u,'pschangevar),prepsq simp!* car u,nil);

endmodule;


module tpscomp; % Compile prefix expression into network of
                % communicating power series.

% Authors: Julian Padget & Alan Barnes

% The compiler is rule driven by looking for a compilation rule (crule)
% property on the property list of the operator.  If a rule does not
% exist the expression is differentiated to get an expression which is
% amenable to compilation but the process takes care to check for the
% existence of cycles in the derivatives e.g. sine and cosine.
%
% The result is an power series object which can be evaluated by the
% power series evaluator.

fluid '(unknowns  !*exp  psintconst knownps ps!:max!-order);

symbolic procedure ps!:compile(form,depvar,about);
  if idp form then
          make!-ps!-id(form,depvar,about)
   else  if ps!:numberp form  then form
   else if ps!:p form then
     if((ps!:expansion!-point form=about)and(ps!:depvar form=depvar))
        then form
     else ps!:compile(ps!:value form,depvar,about)
   else if get(car form,'ps!:crule) then
      apply(get(car form,'ps!:crule),list(form,depvar,about))
  else (if tmp then '!:ps!:  .  cdr tmp    % ******was eval cdr tmp
%       get(cdr tmp,'!:ps!:)
   else ps!:unknown!-crule((car form) . foreach arg in cdr form collect
                                         ps!:compile(arg,depvar,about),
                            depvar,about))
         where tmp = assoc(form,knownps);

symbolic procedure make!-ps!-id(id,depvar,about);
  begin scalar ps;
  ps:=make!-ps(id,id,depvar,about);
  if about neq 'ps!:inf then
      <<ps!:set!-term(ps,0,ps!:identifier!-erule(id,depvar,0,about));
        ps!:set!-term(ps,1,ps!:identifier!-erule(id,depvar,1,about))>>
  else    % expansion about infinity
      <<ps!:set!-order(ps,-1);
        ps!:set!-term(ps,-1,
                ps!:identifier!-erule(id,depvar,-1,about))>>;
  ps!:set!-last!-term(ps,ps!:max!-order);
  return ps
 end;

symbolic procedure make!-ps(form,exp,depvar,about);
% if f is a trivial expression (it can only ever be a number,
% an identifier or a ps) then it is a 'constant' and stands for
% itself, otherwise a larger ps is composed from it
   begin scalar ps;
      ps:=get('tps,'tag) . mkvect 6;
      ps!:set!-order(ps,0);
      ps!:set!-expression(ps,form);
      ps!:set!-value(ps,exp);
      ps!:set!-depvar(ps,depvar);
      ps!:set!-expansion!-point(ps,about);
      ps!:set!-last!-term(ps,-1);
     return ps
   end;


%symbolic procedure ps!:plus!-crule(a,d,n);
%    if atom cdddr a then
%      make!-ps('plus . list(ps!:compile(rand1 a,d,n),
%                            ps!:compile(rand2 a,d,n)),
%               ps!:arg!-values a,d,n)
%   else
%      make!-ps('plus . list(ps!:compile(rand1 a,d,n),
%                            ps!:plus!-crule('plus . cddr a,d,n)),
%               ps!:arg!-values a,d,n);

% put('plus,'ps!:crule,'ps!:plus!-crule);
put('plus,'ps!:crule,'ps!:nary!-crule);


% symbolic procedure ps!:minus!-crule(a,d,n);
%    make!-ps(list('minus,ps!:compile(rand1 a,d,n)),
%                 'minus . ps!:arg!-values a,d,n);

% put('minus,'ps!:crule, 'ps!:minus!-crule);

symbolic procedure ps!:unary!-crule(a,d,n);
   make!-ps(list(rator a,ps!:compile(rand1 a,d,n)),
                  ps!:arg!-values a,d,n);

put('minus,'ps!:crule, 'ps!:unary!-crule);


symbolic procedure ps!:binary!-crule(a,d,n);
   make!-ps((rator a) . list(ps!:compile(rand1 a,d,n),
                               ps!:compile(rand2 a,d,n)),
            ps!:arg!-values a,d,n);

put('difference,'ps!:crule,'ps!:binary!-crule);


symbolic procedure ps!:nary!-crule(a,d,n);
   if null cdddr a then
      make!-ps((rator a) . list(ps!:compile(rand1 a,d,n),
                             ps!:compile(rand2 a,d,n)),
               ps!:arg!-values a,d,n)
   else
      make!-ps((rator a) . list(ps!:compile(rand1 a,d,n),
                             ps!:nary!-crule((rator a) . cddr a,d,n)),
               ps!:arg!-values a,d,n);

put('times,'ps!:crule,'ps!:nary!-crule);
% put('times,'ps!:crule,'ps!:times!-crule);


symbolic procedure ps!:quotient!-crule(a,d,n);
% forms such as (quotient (expt <x> <y>) (expt <x> <z>)) are
% detected here and transformed into (expt <x>(difference <y> <z>)) to
% help avoid certain essential singularities
   if eqcar(rand1 a,'expt) and eqcar(rand2 a,'expt) and
      ((rand1 rand1 a)=(rand1 rand2 a)) then
         ps!:compile(list('expt,
                          rand1 rand1 a,
                          list('difference, rand2 rand1 a,
                                            rand2 rand2 a)),d,n)
   else ps!:binary!-crule(a,d,n);
%      make!-ps('quotient . list(ps!:compile(rand1 a,d,n),
%                                ps!:compile(rand2 a,d,n)),
%               ps!:arg!-values a,d,n);

put('quotient,'ps!:crule,'ps!:quotient!-crule);

flag('(psintconst), 'share);
algebraic (psintconst:= 0 );

symbolic procedure ps!:int!-crule(a,d,n);
 begin scalar r,arg1, psord;
  if not idp rand2 a then
        typerr(rand2 a, "kernel: ps!:int!-crule");
  if rand2 a=d and smember(d,prepsq simp!* psintconst) then
        rerror(tps,10,list("psintconst depends on depvar: ",d));
  arg1:=ps!:compile(prepsq simp!* rand1 a,d,n);
  r:= make!-ps(list('int,arg1,rand2 a),ps!:arg!-values a,d,n);
  psord:= ps!:find!-order arg1;
  if d=rand2 a then
     if ps!:expansion!-point(arg1) neq 'ps!:inf then
       if (psord < 0) and (ps!:term(arg1,-1) neq (nil ./ 1)) then
         rerror(tps,11,"Logarithmic Singularity")
       else <<ps!:set!-term(r,0,simp!* psintconst);
              ps!:find!-order r>>
     else   % expansion about infinity
       if (psord < 2) and (ps!:term(arg1,1) neq (nil ./ 1)) then
         rerror(tps,12,"Logarithmic Singularity")
       else <<ps!:set!-term(r,0,simp!* psintconst);
              ps!:find!-order r>>
  else <<ps!:set!-term(r,0,
                simpint list(prepsq ps!:term(arg1,0),
                             rand2 a));
         ps!:find!-order r>>;
  return r;
end;

put('int,'ps!:crule,'ps!:int!-crule);

symbolic procedure ps!:arg!-values funct;
  (rator funct) . (foreach arg in rands funct collect
                     if ps!:atom arg then arg
                     else if ps!:p arg then ps!:value arg
                     else ps!:arg!-values arg);

symbolic procedure ps!:unknown!-crule(a,d,n);
% unknowns is an alist structure, the CAR of which is the
% form which was differentiated and the CDR is a dotted pair whose
% CDR is a gensym'ed identifier which is used to build
% the cyclic structures used to represent a recurrence relation.
% Minor improvements by Stan Kameny, July 1990.
   (lambda (dfdx,unknowns,tmp);
     if (tmp:=assoc(caar unknowns,cdr unknowns)) then cdr tmp
      else
           (lambda(r,s); <<
              tmp:=ps!:arg!-values a;
              ps!:set!-value(r,tmp);
%              intern s;  % apparently not needed, useful for debugging.
              global list s;  % This is definitely needed in UOLISP.
              set(s,cdr r);
              knownps:=(tmp . s) . knownps;
              ps!:set!-order(r,0); % screws up if order is negative
              if n= 'ps!:inf then n:=0; % expansion about infinity
              a:=(rator a).(foreach arg in rands a collect
                           if ps!:p arg then
                                 if ps!:find!-order arg < 0
                                   then rerror(tps,13,
                                               "Essential Singularity")
                                 else prepsq ps!:term(arg,0)
                           else subst(n,d,arg));
              ps!:set!-term(r,0,simp!* a);
              ps!:set!-last!-term(r,0);
              r
            >> )
            (make!-ps(list('int, ps!:compile(dfdx,d,n),d),a,d,n),
               cddar unknowns)
   )
    (ps!:differentiate(a,d),(a . ('!:ps!: . gensym())) . unknowns,nil);

symbolic procedure ps!:differentiate(a,v);
% note the binding of !*factor to t; this ensures the result of the
% differentiation will be factored, which prevents us looping
% infinitely because we can't see the cycle in the derivative.
% *********not necessary so removed March 1989 AB
   (lambda x;
      if eqcar(x,'df) then
         rerror(tps,14,
                list("ps:differentiate:  cannot differentiate ",a))
      else
         x)
% the default method catches forms which are  defined by patterns
% (eg Bessel functions)
%   ((lambda (!*factor,!*exp);
   ((lambda (!*exp);
       if get(car a,'dfn) then prepsq diffsq(simp!* a,v)
        else prepsq simp!* list ('df,a,v))
%     (t,nil));
     (nil));

endmodule;


module tpseval; % Evaluator for truncated power series.

% Authors: Julian Padget & Alan Barnes

% The evaluator interprets the results of the compilation phase and
% is also rule driven until I get round to getting the compilation
% phase to produce directly executable code

% The evaluation functions live on the erule property of the name.

fluid '(ps psintconst ps!:order!-limit);

%symbolic (orig!*:= 0);
% % symbolic here seems to be essential in Cambridge Lisp systems

symbolic procedure ps!:prin!: p;
 (lambda (first,u,delta,symbolic!-exp!-pt,about,atinf);
  <<  if !*nat and posn!*<20 then orig!*:=posn!*;
      atinf:=(about='ps!:inf);
      ps!:find!-order p;
      delta:=prepf((ps!:depvar p) .** 1 .*1 .+
              (negf  if atinf then nil
                      % expansion about infinity
                      else if idp about then !*k2f about
                      else if ps!:numberp about then !*n2f about
                      else if (u:=!*pre2dp about) then !*n2f u
                      else !*k2f(symbolic!-exp!-pt:= compress
                         append(explode ps!:depvar p, explode '0))));
      if symbolic!-exp!-pt then prin2!* "[";
      prin2!* "{";
      for i:=(ps!:order p): ps!:exp!-lim do
        << u:=ps!:term(p,i);
           if not null numr u then
              <<if minusf numr u then <<u:=negsq u; prin2!* " - ">>
                  else if not first then prin2!* " + ";
                first := nil;
                if posn!*>55 then <<terpri!* nil;prin2!* "  ">>;
                if denr u neq 1 then prin2!* "(";
                if u neq '(1 . 1) then
                        maprint(prepsq u,get('times,'infix))
                  else if i=0 then prin2!* 1;
                if denr u neq 1 then prin2!* ")";
                if i neq 0 and u neq '(1 . 1) then prin2!* "*";
                if i neq 0 then
                xprinf(!*p2f mksp(delta,
                       if atinf then -i else i),nil,nil)
              >>
       >>;
      if first then prin2!* "0";
      if posn!*>55 then terpri!* nil;
      u:=ps!:exp!-lim +1;
      if (u=1) and not atinf and (about neq 0) then
            prin2!* " + O"
      else prin2!* " + O(";
      xprinf(!*p2f mksp(delta,if atinf then -u else u),nil,nil);
      if (u=1) and not atinf and (about neq 0) then
              prin2!* "}"
         else prin2!* ")}";
      if symbolic!-exp!-pt then
        << if posn!*>45 then terpri!* nil;
           prin2!* "  where ";
           prin2!* symbolic!-exp!-pt;
           prin2!* " = ";
           maprin about;
           prin2!* "]"
        >>;
      terpri!* nil;
 >>)
 (t,nil,nil,nil,ps!:expansion!-point p,nil);

symbolic procedure ps!:id!-order ps;
  (lambda u;
          if numberp u then u
          else rerror(tps,15,
                      list("Can't find the order of ",ps!:value ps)))
   ps!:order ps;


symbolic procedure ps!:find!-order ps;
  if null ps then 0
  else if idp ps then ps  % second arg of DF etc are identifiers
  else if numberp ps then 0
  else if eqcar(ps,'!:ps!:) then <<
     if idp cdr ps then ps!:id!-order ps
     else if atom ps!:expression ps or null ps!:depvar ps then
         ps!:order ps
     else ps!:find!-order1(ps) >>
  else if get(car ps,'dname) then 0
  else rerror(tps,16,"Unexpected form in ps!:find!-order");

symbolic procedure ps!:find!-order1(ps);
   begin scalar psoperator,psord,pslast;
      psoperator:=ps!:operator ps;
      psord:=ps!:order ps;
      pslast:=ps!:last!-term ps;
      if psord leq pslast then
        if psoperator neq 'int then return psord
        else if (psord neq 0) or (pslast neq 0) then return psord;
      psord:=apply(get(psoperator,'ps!:order!-fn),
                       for each j in ps!:operands ps
                           collect ps!:find!-order j);
      ps!:set!-order(ps,psord);
      if psoperator= 'int and psord=0 then nil
        else ps!:set!-last!-term(ps,psord-1);
      if ps!:value ps =0 then
              <<psord:=0;ps!:set!-last!-term(ps,1000000)>>
% prevents infinite loop if we have exact cancellation
       else while ps!:evaluate(ps,psord)=(nil ./ 1 ) do
% in case we have finite # of cancellations in a sum or difference
                 <<psord:=psord+1;
                   if psord > ps!:order!-limit then
                   rerror(tps,17,list("Expression ",ps!:value ps,
                               " has zero expansion to order ",
                               psord))
% We may not always be able to recognise zero.
% Anyway give up after 15 iterations.
                  >>;
      return psord
  end;

symbolic (ps!:order!-limit:=100);

% symbolic here seems to be essential in Cambridge Lisp systems

put('psordlim, 'simpfn, 'simppsordlim);

symbolic procedure simppsordlim u;
 begin integer n;
   n:=ps!:order!-limit;
   if u then ps!:order!-limit := ieval carx(u,'psordlim);
  return (if n=0 then nil ./ 1 else n ./ 1);
 end;

put('times,'ps!:order!-fn, 'plus2);
put('quotient,'ps!:order!-fn, 'difference);
put('plus,'ps!:order!-fn, 'min2);
put('difference,'ps!:order!-fn, 'min2);
put('minus,'ps!:order!-fn, '(lambda (u) u));
put('int,'ps!:order!-fn,'ps!:int!-orderfn);
put('df,'ps!:order!-fn,'ps!:df!-orderfn);


symbolic procedure ps!:int!-orderfn(u,v);
if (ps!:order ps=0) and (u geq 0) then 0
 else if v=ps!:depvar ps then
         if ps!:expansion!-point ps neq 'ps!:inf then
            if u=-1 then rerror(tps,18,"Logarithmic Singularity")
            else u+1
         else   % expansion about infinity
            if u=1 then rerror(tps,19,"Logarithmic Singularity")
            else u-1
      else u;

symbolic procedure ps!:df!-orderfn (u,v);
 if v=ps!:depvar ps then
   if ps!:expansion!-point ps neq 'ps!:inf then
        if u=0 then 0 else u-1
   else if u=0 then 2 else u+1  % expansion about infinity
 else u;

symbolic procedure ps!:number!-erule(n,i);
% << n:=(if numberp n then tag!-if!-float n else cdr n);
   <<n := if numberp n then n else cdr n;
     if i =0 and n neq 0 then n ./ 1 else nil ./ 1>>;

symbolic procedure ps!:identifier!-erule(v,d,n,about);
   if v=d then
      if about='ps!:inf  then if n=-1 then 1 ./ 1 else nil ./ 1
              % expansion about infinity
      else if n=0 then
        if idp about then !*k2q about
%       else  if ps!:numberp about then !*n2f tag!-if!-float about ./ 1
        else  if ps!:numberp about then !*n2f about ./ 1
              else simp!* about
        else if n=1 then
           1 ./ 1
        else
         nil ./ 1
   else
      if n=0 then
          !*k2q v
      else
         nil ./ 1;

symbolic procedure ps!:evaluate(ps,n);
% ps can come in two flavours (one of which is degenerate):
% (i) a number
% (ii) a power series object
% in the last case the appropriate evaluation rule for the operator
% in the ps is selected and invoked
   if n leq ps!:last!-term ps then
      ps!:get!-term(ps,n)
   else (lambda next; <<
           if n < ps!:order ps then  nil
           else <<
              ps!:set!-term(ps,n,next:=simp!* prepsq next);
              ps!:set!-last!-term(ps,n)
           >>;
           next>>)
         apply(get(ps!:operator ps,'ps!:erule),
               list(ps!:expression ps,n));

symbolic procedure ps!:plus!-erule(a,n);
   addsq(ps!:evaluate(rand1 a,n),
          ps!:evaluate(rand2 a,n));

put('plus,'ps!:erule,'ps!:plus!-erule);

symbolic procedure ps!:minus!-erule(a,n);
   negsq ps!:evaluate(rand1 a,n);

put('minus,'ps!:erule,'ps!:minus!-erule);

symbolic procedure ps!:difference!-erule(a,n);
   addsq(ps!:evaluate(rand1 a,n),
         negsq ps!:evaluate(rand2 a,n));

put('difference,'ps!:erule,'ps!:difference!-erule);

symbolic procedure ps!:times!-erule(a,n);
  begin scalar aa,b,x,y,y1,z;
   aa:=rand1 a; b:= rand2 a; z:= nil ./ 1;
   x:=ps!:order(aa);
   y:=ps!:order(ps);    % order of product ps
   y1 := ps!:order b;
   % Next "if" suggested by A.C. Norman to avoid different tan df rule
   % The problem with tan was in fact due to ps!:find!-order! -  AB
   for i := 0:n-y do if n-x-i>=y1 then
     z:= addsq(z,multsq(ps!:evaluate(aa,i+x),
                        ps!:evaluate(b,n-x-i)));
   return z
  end;

put('times,'ps!:erule,'ps!:times!-erule);

symbolic procedure ps!:quotient!-erule(a,n);
 begin scalar aa,b,x,y,z;
  aa:=rand1 a; b:=rand2 a; z:= nil ./ 1;
  y:=ps!:order(b);
  x:=ps!:order(ps);   %order of quotient ps
  for i:=1:n-x do
    z:=addsq(z,multsq(ps!:evaluate(b,i+y),
                      ps!:evaluate(ps,n-i)));
  return quotsq(addsq(ps!:evaluate(aa,n+y),negsq z),
                      ps!:evaluate(b,y))
 end;

put('quotient,'ps!:erule,'ps!:quotient!-erule);

symbolic procedure ps!:differentiate!-erule(a,n);
  if rand2 a =ps!:depvar rand1 a then
     if ps!:expansion!-point rand1 a neq 'ps!:inf then
          multsq((n+1) ./ 1,ps!:evaluate(rand1 a,n+1))
     else multsq((1-n) ./ 1,ps!:evaluate(rand1 a,n-1))
   else diffsq(ps!:evaluate(rand1 a,n),rand2 a);

put('df,'ps!:erule,'ps!:differentiate!-erule);

symbolic procedure ps!:int!-erule(a,n);
 if rand2 a=ps!:depvar ps then
  if n=0 then simp!* psintconst
  else if ps!:expansion!-point ps neq 'ps!:inf then
                    quotsq(ps!:evaluate(rand1 a,n-1),n ./ 1)
             else quotsq(ps!:evaluate(rand1 a,n+1),-n ./ 1)
 else simpint list(prepsq ps!:evaluate(rand1 a,n),rand2 a);

put('int,'ps!:erule,'ps!:int!-erule);

endmodule;


module tpsdom; % Domain definitions for truncated power series.

% Authors: Julian Padget & Alan Barnes.

fluid '(ps!:exp!-lim ps!:max!-order);
global '(domainlist!*);

symbolic (domainlist!*:=union('(!:ps!:),domainlist!*));
% symbolic here seems to be essential in Cambridge Lisp systems

put('tps,'tag,'!:ps!:);
put('!:ps!:,'dname,'tps);
flag('(!:ps!:),'field);
put('!:ps!:,'i2d,'i2ps);
put('!:ps!:,'minusp,'ps!:minusp!:);
put('!:ps!:,'plus,'ps!:plus!:);
put('!:ps!:,'times,'ps!:times!:);
put('!:ps!:,'difference,'ps!:difference!:);
put('!:ps!:,'quotient,'ps!:quotient!:);
put('!:ps!:,'zerop,'ps!:zerop!:);
put('!:ps!:,'onep,'ps!:onep!:);
put('!:ps!:,'prepfn,'ps!:prepfn!:);
put('!:ps!:,'specprn,'ps!:prin!:);
put('!:ps!:,'prifn,'ps!:prin!:);
put('!:ps!:,'intequivfn,'psintequiv!:);
% conversion functions

put('!:ps!:,'!:mod!:,mkdmoderr('!:ps!:,'!:mod!:));
% put('!:ps!:,'!:gi!:,mkdmoderr('!:ps!:,'!:gi!:));
% put('!:ps!:,'!:rn!:,mkdmoderr('!:ps!:,'!:rn!:));
put('!:rn!:,'!:ps!:,'!*d2ps);
put('!:ft!:,'!:ps!:,'cdr);
put('!:gi!:,'!:ps!:,'!*d2ps);
put('!:gf!:,'!:ps!:,'!*d2ps);

symbolic procedure psintequiv!: u;
  if idp cdr u or ps!:depvar u or length (u:=ps!:expression u)>2
    then nil
    else int!-equiv!-chk rand1 u;

symbolic procedure i2ps u;
  if dmode!*='!:ps!: then !*d2ps u else u;

symbolic procedure !*d2ps u;
  begin scalar ps;
      ps:=get('tps,'tag) . mkvect 6;
      ps!:set!-order(ps,0);
      ps!:set!-expression(ps,list ('psconstant,u));
      ps!:set!-value(ps,prepsq( u ./ 1));
      ps!:set!-last!-term(ps,ps!:max!-order);
      ps!:set!-terms(ps,list ( 0 . ( u ./ 1)));
     return ps
   end;

%symbolic procedure ps!:compatiblep(u,v);
% if (constantpsp u or constantpsp v ) then t
% else  if (ps!:depvar u) neq (ps!:depvar v) then nil
%       then nil
%       else if (ps!:expansion!-point u) neq (ps!:expansion!-point v)
%            else t;

symbolic procedure ps!:minusp!: u;
   nil;

symbolic procedure ps!:plus!:(u,v);
   ps!:operator!:('plus,u,v);

symbolic procedure ps!:difference!:(u,v);
   ps!:operator!:('difference,u,v);

symbolic procedure ps!:times!:(u,v);
   ps!:operator!:('times,u,v);

symbolic procedure ps!:quotient!:(u,v);
   ps!:operator!:('quotient,u,v);


symbolic procedure ps!:diff!:(u,v);
  (( if idp deriv then
        ps!:compile (deriv,ps!:depvar u,ps!:expansion!-point u)
      else if numberp deriv then
              if zerop deriv then nil
              else deriv
      else make!-ps(list('df,u,v), deriv,
                     ps!:depvar u,ps!:expansion!-point u))
  ./ 1)
   where (deriv = prepsq simp!* list('df, ps!:value u,v));

symbolic procedure ps!:operator!:(op,u,v);
   begin scalar value,x,x0,y;
      x:=ps!:depvar u;
      y:=ps!:depvar v;
      if null x then
        if null y then
           return << if ps!:p u then u:=rand1 ps!:expression u;
                     if ps!:p v then v:=rand1 ps!:expression v;
                     if op='quotient and atom u and atom v then
                      if null u then nil
                      else
                        <<op:=gcdn(u,v);u:=u/op;v:=v/op;
                          if v=1 then u else '!:rn!: . (u . v)>>
                    else dcombine!*(u,v,op)>>
        else << x:= y; x0:=ps!:expansion!-point v>>
      else if null y then
              x0:=ps!:expansion!-point u
      else if ((x0:=ps!:expansion!-point u) neq ps!:expansion!-point v)
               or (x neq y) then
             rerror(tps,20,
                    list("ps!:operator:  incompatible power series in ",
                         op));
      value:= simp!* list(op,ps!:value u,ps!:value v);
      if denr value=1 and domainp numr value then return numr value;
      return make!-ps(list(op,u,v), prepsq value,x,x0)
  end;

symbolic procedure ps!:zerop!: u;
  (numberp v and zerop v) where v=ps!:value u;

symbolic procedure ps!:onep!: u;
  onep ps!:value u;

symbolic procedure ps!:prepfn!: u;
   u;

initdmode 'tps;

endmodule;


module tpsrev; % Power Series Reversion & Composition

% Author: Alan Barnes   November 1988
%
% If y is a power series in x then psreverse expresses x as a power
% series in y-y0 where y0 is zero order term of y.
% This is known as power series reversion (functional inverse)
% pscompose functionally composes two power series
%
%Two new prefix operators are introduced PSREV and PSCOMP.
%These appear in the expression part of the power series objects
%generated by calls to psreverse and pscompose respectively.
%The  argument of PSREV is the 'generating  series' of the
%series (PS1 say) to be inverted. This is a generalised power series
%object  which looks like a standard power series object except that
%each of its terms is itself a power series (rather than a standard
%quotient), the  nth term being the power series of the nth power of
%PS1. The expression part of the generating series is (PSGEN <PS1>).
%
%When power series PS1 and PS2 are composed (i.e. PS2 is substituted
%for the expansion variable of PS1 and the result expressed as a power
%series in the expansion variable of PS2), the expression part of
%the power series object generated is
%              (PSCOMP <PS1> <generating-series of PS2>)
%The generating series should only appear inside the operators PSREV
%and PSGEN and not at 'top level'. It cannot sensibly be printed with
%the power series print function. Special functions are needed to
%access and modify terms of the generating series, although these
%are simply defined in terms of the functions for manipulating
%standard power series objects.
%% The algorithms used are based on those described in
%Feldmar E & Kolbig K S, Computer Physics Commun.  39, 267-284 (1986).

fluid '(ps);

put('psreverse, 'simpfn, 'simppsrev);

symbolic procedure simppsrev a;
 if length a=1 then apply('simppsrev1,a)
 else rerror(tps,21,"Wrong number of arguments to PSREVERSE");

symbolic procedure simppsrev1(series);
 begin scalar rev,psord, depvar,about;
%    if not kernp simp!* revvar then
%         typerr(revvar,"kernel:  simppsrev");
   series:=prepsq simp!* series;
   if not ps!:p series then
      rerror(tps,22,
           "Argument should be a <POWER SERIES>: simppsrev");
   ps!:find!-order series;
   depvar:=ps!:depvar series;
   if (psord:=ps!:order series)=1 then
        about:=0
    else if (psord=0) and (ps!:term(series,1) neq (nil ./ 1)) then
        about := prepsq ps!:get!-term(series,0)
    else if psord =-1 then about:='ps!:inf
    else rerror(tps,23,"Series cannot be inverted:  simppsrev");
   rev:=ps!:compile(list('psrev,series),depvar,about);
   if ps!:expansion!-point series = 'ps!:inf then
      return make!-ps(list('quotient,1,rev),
                      ps!:value rev,depvar,about) ./ 1
   else return rev ./ 1
 end;

symbolic procedure ps!:generating!-series(a,psord,inverted);
 begin scalar ps, depvar,point;
   depvar:=ps!:depvar a;
   point:= ps!:expansion!-point a;
   ps:=make!-ps(list('psgen, a,inverted),ps!:value a,
                      depvar, point);
   ps!:set!-order(ps,psord);
   ps!:set!-last!-term(ps,psord);
   a:=ps!:compile(list('expt,a,if inverted then -psord else psord),
                  depvar,point);
   ps!:find!-order a;
   ps!:set!-term(ps,psord,a);
   return ps
 end;

symbolic smacro procedure ps!:get!-rthpow(genseries,r);
 ps!:get!-term(genseries,r);

symbolic procedure ps!:set!-rthpow(genseries,r);
 begin scalar rthpow, series, power;
    series:=ps!:expression genseries;
    power:= if rand2 series then -r else r;
    series:=rand1 series;
    rthpow:=ps!:compile(list('expt,series,power),
                     ps!:depvar series,ps!:expansion!-point series);
    ps!:find!-order rthpow;
    ps!:set!-term(genseries,r,rthpow);
    return rthpow
 end;

symbolic procedure ps!:term!-rthpow(genseries,r,n);
 begin scalar term,series;
  series:= ps!:get!-rthpow(genseries,r);
  if null series then <<for i:=ps!:last!-term genseries +1:r do
                        series:=ps!:set!-rthpow(genseries,i);
                        ps!:set!-last!-term(genseries,r)>>;
  term:=ps!:get!-term(series,n);
  if null term then for j:=ps!:last!-term(series)+1:n do
                        term:=  ps!:evaluate(series,j);
  return term
 end;

put('psrev,'ps!:crule,'ps!:rev!-crule);

symbolic procedure ps!:rev!-crule(a,d,n);
  begin scalar series;
    series :=rand1 a;
    if (n neq 'ps!:inf) and (n neq 0) then
      series:=ps!:remove!-constant series;
    return
      make!-ps(list('psrev,
                     ps!:generating!-series(series,1,
                                             if n='ps!:inf then t
                                             else nil)),
               list('psrev,ps!:value rand1 a),d,n)
  end;

symbolic procedure ps!:remove!-constant(ps);
 << ps:=ps!:compile(list('difference,ps,prepsq  ps!:term(ps,0)),
                ps!:depvar ps,
                ps!:expansion!-point ps);
    ps!:find!-order ps;
    ps >>;

% symbolic procedure ps!:reciprocal(ps);
%  << ps:=ps!:compile(list('quotient,1,ps),
%                 ps!:depvar ps,
%                 ps!:expansion!-point ps);
%     ps!:find!-order ps;
%     ps >>;

put('psrev,'ps!:erule,'ps!:rev!-erule);
put('psrev,'ps!:order!-fn,'ps!:rev!-orderfn);

symbolic procedure ps!:rev!-orderfn u;
         if (u:=ps!:expansion!-point
                    ps!:get!-rthpow(rand1 ps!:expression ps,1))=0
          then 1
          else if u = 'ps!:inf then 1
          else 0;

symbolic procedure ps!:rev!-erule(a,n);
 begin scalar genseries,x,z;
  z:=nil ./ 1; genseries:=rand1 a;
  if n=0 then
    if (x:=ps!:expansion!-point ps!:get!-rthpow(genseries,1))='ps!:inf
     then return (nil ./ 1)
     else return simp!* x;
  if n=1 then
      return invsq ps!:term!-rthpow(genseries,1,1);
  for i:=1:n-1 do
        z:=addsq(z,multsq(ps!:evaluate(ps,i),
                          ps!:term!-rthpow(genseries,i,n)));
  return quotsq(negsq z,ps!:term!-rthpow(genseries,n,n))
 end;

put('pscomp,'ps!:crule,'ps!:comp!-crule);
put('pscomp,'ps!:erule,'ps!:comp!-erule);
put('pscomp,'ps!:order!-fn,'ps!:comp!-orderfn);

symbolic procedure ps!:comp!-orderfn(u,v);
  if u=0 then 0
   else ps!:find!-order(ps!:get!-rthpow(rand2 ps!:expression ps,u));

symbolic procedure ps!:comp!-crule(a,d,n);
  begin scalar series1,series2,n1;
     series1:=rand1 a; series2:=rand2 a;
     n1 := ps!:expansion!-point series1;
     if (n1 neq 0) and (n1 neq 'ps!:inf) then
        series2:=ps!:remove!-constant series2;
     return
       make!-ps(list('pscomp,series1,
                     ps!:generating!-series(series2,
                                            ps!:order series1,
                                            if n1='ps!:inf then t
                                              else nil)),
                ps!:arg!-values a,d,n)
  end;

symbolic procedure ps!:comp!-erule(a,n);
 begin scalar aa,genseries,z,psord1;
  z:=nil ./ 1; aa:=rand1 a; genseries:=rand2 a;
  psord1:=ps!:order aa;
%  if n=0 then return ps!:term(aa,0);
  for i:=psord1:n do
        z:=addsq(z,multsq(ps!:evaluate(aa,i),
                          ps!:term!-rthpow(genseries,i,n)));
   return z
 end;


put('pscompose, 'simpfn, 'simppscomp);

symbolic procedure simppscomp a;
  if length a=2 then  apply('simppscomp1,a)
   else rerror(tps,24,
     "Args should be <POWER SERIES>,<POWER SERIES>:  simppscomp");

symbolic procedure simppscomp1(ps1,ps2);
  begin scalar x,d,n1,n;
    ps1:=prepsq simp!* ps1;
    if ps!:numberp ps1 then
      return ((if zerop ps1 then nil else ps1) ./ 1);
    if not ps!:p ps1 or not ps!:p(ps2:=prepsq simp!* ps2) then
      rerror(tps,25,
      "Args should be <POWER SERIES>,<POWER SERIES>:  simppscomp");
    ps!:find!-order ps1;
    x:=ps!:find!-order ps2;
    d:= ps!:depvar ps2;
    n1:= ps!:expansion!-point ps1;
    n:= ps!:expansion!-point ps2;
    if (x >0 and n1 = 0) or
       (x <0 and n1 = 'ps!:inf) or
       (x=0 and n1=prepsq ps!:term(ps2,0))
     then  return ps!:compile(list('pscomp,ps1,ps2),d,n) ./ 1
     else rerror(tps,26,"Series cannot be composed:  simppscomp");
 end;

algebraic operator psrev,pscomp;

endmodule;


module tpsfns;
% Expansion of elementary functions as power series using DOMAINVALCHK
% TPS & NUMVAL must be on for these functions to be invoked
% Example sin a where a is a power series will now be expanded

% Author: Alan Barnes, March 1989


fluid '(!*numval);

put('exp, '!:ps!:, 'ps!:exp!:);
put('log, '!:ps!:, 'ps!:log!:);

put('sin, '!:ps!:, 'ps!:sin!:);
put('cos, '!:ps!:, 'ps!:cos!:);
put('tan, '!:ps!:, 'ps!:tan!:);

put('asin, '!:ps!:, 'ps!:asin!:);
put('acos, '!:ps!:, 'ps!:acos!:);
put('atan, '!:ps!:, 'ps!:atan!:);

put('sinh, '!:ps!:, 'ps!:sinh!:);
put('cosh, '!:ps!:, 'ps!:cosh!:);
put('tanh, '!:ps!:, 'ps!:tanh!:);

put('asinh, '!:ps!:, 'ps!:asinh!:);
put('acosh, '!:ps!:, 'ps!:acosh!:);
put('atanh, '!:ps!:, 'ps!:atanh!:);

put('expt, '!:ps!:, 'ps!:expt!:);

% the above is grotty but necessary as unfortunately DOMAINVALCHK
% passes arglist of sin (rather than sin . arglist) to ps!:sin!: etc

symbolic procedure ps!:expt!:(base,exp);
 begin scalar !*numval,depvar,about;
  % NB binding of !*numval avoids infinite loop
   depvar:= ps!:depvar base;
   if null depvar then <<
       depvar:=ps!:depvar exp;
       about:= ps!:expansion!-point exp>>
   else about:= ps!:expansion!-point base;
   if null depvar then error(999,"constantps**constantps formed");
   return ps!:compile(list('expt, base,exp),depvar,about)
 end;

symbolic procedure ps!:unary!:fn(fn, arg);
 begin scalar !*numval; % NB binding of !*numval avoids infinite loop
   return ps!:compile(list(fn, arg),
                      ps!:depvar arg,
                      ps!:expansion!-point arg)
 end;

symbolic procedure ps!:cos!: arg;
  ps!:unary!:fn('cos,arg);

symbolic procedure ps!:sin!: arg;
  ps!:unary!:fn('sin,arg);

symbolic procedure ps!:tan!: arg;
  ps!:unary!:fn('tan,arg);

symbolic procedure ps!:log!: arg;
  ps!:unary!:fn('log,arg);

symbolic procedure ps!:exp!: arg;
  ps!:unary!:fn('exp,arg);

symbolic procedure ps!:cosh!: arg;
  ps!:unary!:fn('cosh,arg);

symbolic procedure ps!:sinh!: arg;
  ps!:unary!:fn('sinh,arg);

symbolic procedure ps!:tanh!: arg;
  ps!:unary!:fn('tanh,arg);

symbolic procedure ps!:asin!: arg;
  ps!:unary!:fn('asin,arg);

symbolic procedure ps!:acos!: arg;
  ps!:unary!:fn('acos,arg);

symbolic procedure ps!:atan!: arg;
  ps!:unary!:fn('atan,arg);

symbolic procedure ps!:asinh!: arg;
  ps!:unary!:fn('asinh,arg);

symbolic procedure ps!:acosh!: arg;
  ps!:unary!:fn('acosh,arg);

symbolic procedure ps!:atanh!: arg;
  ps!:unary!:fn('atanh,arg);

endmodule;


module tpselfns;
% Specific compilation and evaluation rules for elementary functions
% Automatically generated recurrence relations can sometimes lead to
% infinite loops.
% Also helps in the detection of branch point singularities
% Author: Alan Barnes.      March 1989

fluid '(ps!:max!-order ps);

put('sqrt,'ps!:crule,'ps!:unary!-crule);
put('sqrt,'ps!:order!-fn,'ps!:sqrt!-orderfn);
put('sqrt,'ps!:erule,'ps!:sqrt!-erule);

symbolic procedure ps!:sqrt!-orderfn u;
  (if v*2=u then v else rerror(tps,27,"Branch Point in Sqrt"))
   where v=u/2;

symbolic procedure ps!:sqrt!-erule(a,n);
 begin scalar aa,x,y,z;
  aa:=rand1 a;  z:= nil ./ 1;
  y:=ps!:order aa;
  x:=ps!:order(ps);   %order of sqrt ps
  if n=x then return simpexpt(list(prepsq ps!:evaluate(aa,y),
                                   '(quotient 1 2)));
  for k:=1:n-x do
              z:=addsq(z,
                    multsq(((lambda y; if y=0 then nil else y)
                             (k*3-2*n+y)) ./ 1,
                          multsq(ps!:evaluate(aa,k+y),
                               ps!:evaluate(ps,n-k))));
            return quotsq(z,multsq(2*(n-x) ./ 1,ps!:evaluate(aa,y)))
  end;

%  alternative algorithm (for order 0 only)
%  for i:=1:n-1 do
%    z:=addsq(z,multsq(multsq( i ./ 1,ps!:evaluate(ps,i)),
%                      ps!:evaluate(ps,n-i)));
%    z:=multsq(z, 1 ./ (n+1));
%  return quotsq(addsq(ps!:evaluate(aa,n),negsq z),
%                multsq(2 ./ 1,ps!:evaluate(b,x)))


symbolic procedure ps!:expt!-erule(a,n);
  begin scalar base,exp,x,y,z,p,q;
   base:= rand1 a;
   if length a=3 then
        <<exp:=rand2 a;p:=exp;q:=1>>
   else <<
    p:=rand2 a; q:=cadddr a;
    exp:=list('quotient,p,q)>>;
%   exp:=ps!:value rand2 a;
   % exponent is always p or (QUOTIENT p q) with p,q integers
   x:= nil ./ 1;
   y:=ps!:order(base);
   z:= ps!:order ps;         % order of exponential
   if n=z then
         return simpexpt(list(prepsq ps!:evaluate(base,y),exp))
    else <<for k:=1:n-z do
              x:=addsq(x,
                    multsq(((lambda num; if num=0 then nil else num)
                             (k*p+q*(k-n+z))) ./ q,
                          multsq(ps!:evaluate(base,k+y),
                               ps!:evaluate(ps,n-k))));
            return quotsq(x,multsq((n-z) ./ 1,ps!:evaluate(base,y)))
          >>;
  end;

put('expt,'ps!:erule, 'ps!:expt!-erule);
put('expt,'ps!:crule,'ps!:expt!-crule);
put('expt,'ps!:order!-fn,'ps!:expt!-orderfn);

symbolic procedure ps!:expt!-crule(a,d,n);
% we will assume that forms like (expt (expt <x> <y>) <z>) will
% continue to be transformed by SIMP!* into (expt <x> (times <y> <z>))
% this is very important for the avoidance of essential singularities
 begin scalar exp0,eflg,exp1,exp2,b,ps,psvalue,dmode,!*msg;
   dmode := dmode!*;
   exp0:=rand1 a;
   eflg := evalequal(exp0,prepsq simp!* aeval 'e);
   if dmode then onoff(get(dmode,'dname),nil);
   exp1:=rand2 a;
   if (ps!:p exp1 and constantpsp exp1) then exp1:=ps!:value exp1;
   begin scalar alglist!*;
        exp2:=simp!* exp1;
        exp1:=prepsq exp2
   end;
   if (atom numr exp2 and atom denr exp2) then
        <<exp1:=numr exp2; exp2:=denr exp2>>
    else return
      <<ps:=ps!:unknown!-crule(list('expt, 'e,
                         ps!:compile(if eflg then exp1
                                            else list('times, exp1,
                                                 list('log,exp0)),
                                            d,n)),
                           d,n);
        if dmode then onoff(get(dmode,'dname),t); ps>>;
  b:=ps!:compile(exp0,d,n);
  if dmode then onoff(get(dmode,'dname),t);
  psvalue:=ps!:arg!-values a;
  if exp2=1 then
    if exp1=nil then
      return if ps!:zerop!: b
               then rerror(tps,28,"0**0 formed: ps:expt-crule")
             else 1
     else if exp1=1 then return b
     else if exp1=2 then
        return make!-ps(list('times,b,b),psvalue,d,n)
     else if exp1 = -1 then
          return make!-ps(list('quotient,1,b),psvalue,d,n)
     else return make!-ps(list('expt,b,exp1),psvalue,d,n)
  else return make!-ps(list('exp3,b,exp1,exp2),psvalue,d,n);
 end;

symbolic procedure ps!:expt!-orderfn(u,v);
    u*rand2 ps!:expression ps;

symbolic procedure ps!:exp3!-orderfn(u,v,w);
 begin scalar expres;
   expres:=ps!:expression ps;
   v:= rand2 expres; w:=cadddr expres;
    if cdr(v:=divide(u * v,w))=0 then
         return car v
   else rerror(tps,29,"Branch Point in EXPT")
end;

put('exp3,'ps!:order!-fn,'ps!:exp3!-orderfn);
put('exp3,'ps!:erule,'ps!:expt!-erule);

endmodule;


module tpssum;

% Written by Alan Barnes.  September 1990
% Allows power series whose general term is given to be manipulated.
%
%   pssum(<sumvar>=<lowlim>, <coeff>, <depvar>, <about>, <power>);
%
%     <sumvar>    summation variable                  (a kernel)
%     <lowlim>    lower limit of summation            (an integer)
%     <coeff>     general coefficient of power series (algebraic)
%     <depvar>    expansion variable of series        (a kernel)
%     <about>     expansion point of series           (algebraic)
%     <power>     general exponent of power series    (algebraic)
% <power> must be a strictly increasing function of <sumvar>
%         this is now partially checked by the system


symbolic procedure ps!:summation!-erule(a,n);
 begin scalar power, coeff,sumvar,current!-index,last!-exp,current!-exp;
   current!-index:= rand2 a;
   sumvar:= rand1 a; coeff := cdddr a;
   power:= cadr coeff; coeff:=car coeff;
   last!-exp:= ieval reval subst(current!-index,sumvar,power);
   repeat <<
     current!-index:=current!-index+1;
     current!-exp:= ieval reval subst(current!-index,sumvar,power);
     if current!-exp leq last!-exp then
       rerror(tps,30,"Exponent not strictly increasing: ps:summation");
     if  current!-exp < n then <<
         ps!:set!-term(ps,current!-exp,
                        simp!* subst(current!-index,sumvar,coeff));
         ps!:set!-last!-term(ps,current!-exp);
         rplaca(cddr a,current!-index)>>;
     last!-exp:=current!-exp>>
   until current!-exp geq n;
   return if current!-exp = n then <<
              rplaca(cddr a,current!-index);
              simp!* subst(current!-index,sumvar,coeff) >>
          else (nil ./ 1)
 end;

put('ps!:summation, 'ps!:erule, 'ps!:summation!-erule);
put('ps!:summation, 'simpfn, 'simpiden);
put('pssum, 'simpfn, 'simppssum);

symbolic procedure simppssum a;
 begin scalar !*nosubs,from,sumvar,lowlim,coeff,
              power,depvar,about,psord,term;
   if length a neq 5 then rerror(tps,31,
   "Args should be <FROM>,<coeff>,<depvar>,<point>,<power>: simppssum");
   !*nosubs := t;  % We don't want left side of eqns to change.
   from := reval car a;
   !*nosubs := nil;
   if not eqexpr from then
      errpri2(car a,t)
   else <<sumvar:= cadr from;
          if not kernp simp!* sumvar then
              typerr(sumvar, "kernel:  simppssum");
          lowlim:= ieval caddr from >>;
   coeff:= prepsq simp!* cadr a;
   a:= cddr a;
   depvar := car a; about:=prepsq simp!* cadr a;
   if about = 'infinity then about := 'ps!:inf;
   power:= prepsq simp!* caddr a;
   if not kernp simp!* depvar then
        typerr(depvar, "kernel:  simppssum")
   else if depvar=sumvar then  rerror(tps,32,
           "Summation and expansion variables are the same:  simppssum")
   else if  smember(depvar,about) then
        rerror(tps,33,"Expansion point depends on depvar:  simppssum")
   else if  smember(sumvar,about) then rerror(tps,34,
            "Expansion point depends on summation var:  simppssum")
   else if not smember(sumvar,power) then rerror(tps,35,
         "Exponent does not depend on summation variable: simppssum");
   lowlim:=lowlim-1;
   repeat <<
     lowlim:=lowlim+1;
     psord:= ieval reval subst(lowlim,sumvar,power)>>
   until (term:=simp!* subst(lowlim,sumvar,coeff)) neq '(nil . 1);
   ps:=make!-ps(list('ps!:summation,sumvar,lowlim,coeff,power),
                list('ps!:summation,from,coeff,depvar,about,power),
                depvar, about);
   ps!:set!-order(ps,psord);
   ps!:set!-term(ps,psord, term);
   ps!:set!-last!-term(ps,psord);
   return (ps ./ 1)
 end;

endmodule;


end;
