% ----------------------------------------------------------------------
% $Id: pasfsism.red,v 1.11 2004/02/22 21:08:15 lasaruk Exp $
% ----------------------------------------------------------------------
% Copyright (c) 2003 Andreas Dolzmann and Andreas Seidl
% ----------------------------------------------------------------------
% $Log: pasfsism.red,v $
% Revision 1.11  2004/02/22 21:08:15  lasaruk
% Added switch rlsusisubst for substitution of equalities. Substitution
% results in smaller formulas or formulas with less free variables.
% Up to 80% length reduction. Switch rlsusitr should not be used yet.
%
% Revision 1.10  2003/12/16 10:19:58  dolzmann
% Removed wrong return values of pasf_susibinad. Added code for
% substituting equations into atomic formulas occuring in the theory.
%
% Revision 1.9  2003/12/16 07:45:34  lasaruk
% Redlog normal form in the simplifier.
%
% Revision 1.8  2003/12/11 10:51:19  lasaruk
% Smart simplification improoved.
%
% Revision 1.7  2003/12/02 09:04:06  dolzmann
% Removed parser error.
%
% Revision 1.6  2003/12/02 07:43:08  lasaruk
% Additive smart simplification added.
%
% Revision 1.5  2003/11/28 09:36:54  sturm
% Fixes in pasf_susibineq: do nothing for congrunces with different moduli.
% Exchanged T with nil at two points.
%
% Revision 1.4  2003/11/28 09:11:11  dolzmann
% Inserted a linebreak after rcsid!*.
%
% Revision 1.3  2003/11/27 19:30:40  lasaruk
% Smart simplification added
%
% Revision 1.2  2003/11/05 13:27:14  lasaruk
% Some major redlog programming rules applied to the code.
% Formulas are made positive acc. to the current kernel order.
%
% Revision 1.1  2003/07/22 12:42:59  seidl
% Smart simplification with theory based on susi started.
%
% ----------------------------------------------------------------------
lisp <<
   fluid '(pasf_sism_rcsid!* pasf_sism_copyright!*);
   pasf_sism_rcsid!* :=
      "$Id: pasfsism.red,v 1.11 2004/02/22 21:08:15 lasaruk Exp $";
   pasf_sism_copyright!* :=
      "Copyright (c) 2003 by A. Dolzmann. A. Seidl and T. Sturm"
>>;

module pasfsism;
% PASF smart simplification. Submodule of [pasf].

procedure pasf_smwupdknowl(op,atl,knowl,n);
   % Presburger arithmetic standard form update knowledge.  [op] is an
   % operator; [atl] is the list of atomic formulas to add to the
   % knowledge; [knowl] is a knowledge; [n] is the level. Returns
   % modified knowledge.
   if !*rlsusi then
      cl_susiupdknowl(op,atl,knowl,n)
   else
      cl_smupdknowl(op,atl,knowl,n);

procedure pasf_smwrmknowl(knowl,v);
   % Presburger arithmetic standard form remove variable from the
   % knowledge. [knowl] is a knowledge; [v] is the variable to
   % remove. Returns modified knowledge.
   if !*rlsusi then
      pasf_susirmknowl(knowl,v)
   else
      cl_smrmknowl(knowl,v);

procedure pasf_smwcpknowl(knowl);
   % Presburger arithmetic standard form copy knowledge.  [knowl] is a
   % knowledge. Returns a copy of the knowledge.
   if !*rlsusi then
      cl_susicpknowl(knowl)
   else
      cl_smcpknowl(knowl);

procedure pasf_smwmkatl(op,knowl,newknowl,n);
   % Presburger arithmetic standard form ...?
   if !*rlsusi then
      cl_susimkatl(op,knowl,newknowl,n)
   else
      cl_smmkatl(op,knowl,newknowl,n);

procedure pasf_susirmknowl(knowl,v);
   % Presburger arithmetic standard form remove knowledge. [knowl] is
   % a KNOWL; [v] is a variable. Returns a KNOWL. Remove all
   % information about [v] from [knowl].
   for each p in knowl join
      if v memq pasf_varlat car p then nil else {p};

procedure pasf_susibin(old,new);
   % Presburger arithmetic standard form susi binary smart
   % simplification. [old] and [new] are LAT's. Returns ['false] or a
   % SUSIPRG. We assume that [old] is a part of a already existence
   % KNOWL and new has to be added to this KNOWL.
   begin scalar x,rm;
      % Do not make conclusion simplification
      if cdr old eq 'ignore and cdr new eq 'ignore then
	 return nil;
      x := pasf_susibinad(old,new);
%      print "-----------------------";
%      mathprint rl_mk!*fof car old;
%      print cdr old;
%      mathprint rl_mk!*fof car new;
%      print cdr old;
%      print "sisibin->ouput";
%      print x;
      if x and listp x and
	 (cdr new eq 'ignore or cdr old eq 'ignore) and
	 not cdr x and caar x eq 'delete then <<
	    print x;
	 % Abort replacing theory with conclusions
	 return nil
	 >>
      else
      	 return x
   end;

procedure pasf_susibinad(old,new);
   % Presburger standard form additive smart simplification. [old] is
   % the old atomic formula in the theory; [new] is the new atomic
   % formula found. Returns a susiprog that simplifies the formula.
   begin scalar od,nd,level,atf,olevel,res;
      level := cl_susiminlevel(cdr old,cdr new);
      olevel := cdr old;
      old := car old;   
      new := car new;
      % Check for possible substitution
      if !*rlsusisubst and
	 (pasf_opn old eq 'equal or pasf_opn new eq 'equal) then <<
	 res := pasf_susibinsubst(old,new,level);
	 if res then
	    return res
      >>;
      % Equal lefthand sides simplification
      if pasf_arg2l old = pasf_arg2l new then
	 return pasf_susibineq(pasf_arg2l old,pasf_op old,pasf_op new,level);
      % Decomposing both atomic formulas for additive simplification
      od := pasf_susidec(pasf_arg2l old);
      nd := pasf_susidec(pasf_arg2l new);
      if car od = car nd then
	 % Equal parametric parts
	 return pasf_susibinord(pasf_op old,pasf_arg2l old,cdr od,
	    pasf_op new,pasf_arg2l new,cdr nd,level);
      % Transitive simplification
      if !*rlsusitr then
	 return pasf_susibintr(old,new,level)
      else
	 return nil;
   end;

procedure pasf_atf2susiprog(atf,level,act);
   % Presburger arithmetic standard form atomic formula to susiprog
   % conversion. [atf] is an atomic formula; [level] is the level of
   % [atf] in the formula; [act] is the action to do with old or new
   % formula. Returns $'false$ if [atf] is a contradiction, {(delete
   % . T)} if [atf] is a tautology and {'(delete . [act]),('add . (atf
   % . level)} else.
   if atf eq 'true then
      % New formula is always true under theory conditions
      {('delete . act)}
   else if atf eq 'false then
      % Contradiction
      'false
   else
      {('delete . act),('add . (atf .  level))};

procedure pasf_susibinsubst(old,new,level);
   % Presburger arithmetic standard form smart substitution
   % simplification. [old] and [new] are atomic formulas; [level] is
   % the recursion level. Returns a susiprog.
   begin scalar res,subst,into,atf,flag;
      % Determining what formula is substituted
      if pasf_opn old eq 'equal and pasf_opn new eq 'equal then 
 	 % If both atomic formulas are equalities the result atomic formula
 	 % should contain less free variables as the input formula with the
 	 % biggest amount of free variables to avoid cyclic
 	 % substitutions. Substituted is the formula with smallest amount of
 	 % free variables.
	 if length rl_fvarl old < length rl_fvarl new then <<
	    % Substituting old into the new
	    subst := old;
	    into := new;
	    flag := T
	 >> else <<
	    % Substituting new into the old
	    subst := new;
	    into := old;
	    flag := nil
	 >>      
      else if pasf_opn old eq 'equal then <<
	 % Substituting old into the new
	 subst := old;
	 into := new;
	 flag := T	    
      >> else <<
	 % Substituting new into the old
	 subst := new;
	 into := old;
	 flag := nil
      >>;
      % Testing the substitution condition
      atf := pasf_simplat1 pasf_0mk2(pasf_op into,
	 addf(pasf_arg2l into,negf pasf_arg2l subst));
      if length rl_fvarl atf < length rl_fvarl into and not rl_tvalp atf then
	 return {('delete . flag), ('add . (atf . level))};
      atf := pasf_simplat1 pasf_0mk2(pasf_op into,
	 addf(pasf_arg2l into,pasf_arg2l subst));
      if length rl_fvarl atf < length rl_fvarl into and not rl_tvalp atf then
	 return {('delete . flag), ('add . (atf . level))};
      % Nothing could be done
      return nil;
   end;

procedure pasf_susibintr(old,new,level);
   % Presburger arithmetic standard form smart transitive
   % simplification. [old] and [new] are atomic formulas; [level] is
   % the recursion level. Returns a susiprog.
   begin scalar res,sw;
      % First testing if simplification works in the order new into old
      res := pasf_susibintr1(old,new,level);
      if not res then <<
	 % Simplification in the order old into new
	 res := pasf_susibintr1(new,old,level);
	 sw := 't;
      >>;      
      if res eq 'false then
	 return res;
      return res;
   end;
   
procedure pasf_susibintr1(old,new,level);
   % Presburger arithmetic standard form smart transitive
   % simplification subprocedure. [old] and [new] are atomic formulas;
   % [level] is the recursion level. Returns a susiprog.
   begin scalar atf,rel,cold,aw;
      rel := pasf_smtrtable(pasf_opn old,pasf_opn new);    
      % No simplification in this direction is possible
      if not rel then
	 return nil;
      atf := pasf_simplat1
	 pasf_0mk2(rel,addf(pasf_arg2l old,negf pasf_arg2l new));
      % Amount of free variables in both atomic formulas
      cold := length rl_fvarl pasf_mkn('and,{old,new});
      % Amount of free variables that are eliminated
      aw := cold - length rl_fvarl atf;
      % Only simplify if the amount of free variables goes down
      if aw > 0 then <<
	 % Transitive simplification turns out to be an equivalence
	 % operation if the substituted atomic formula is an equality.    
	 if pasf_opn old eq 'equal or pasf_opn new eq 'equal then <<
	    % Under this assumptions a real contradiction is found
	    if atf eq 'false then
	       return 'false;
	    if atf eq 'true then
	       rederr {"True in transitive simplification shound not occur"};
	    return {('add . (atf . level))}
	 >>;
	 % Drawing an implicative conclusion
	 return {('add . (atf . 'ignore))}	 
      >>;
      return nil
   end;

procedure pasf_susibineq(u,oop,nop,level);
   % Presburger arithmetic standard form smart simplification be equal
   % lefthand terms. [u] is the (common) lefthand term; [oop] is the
   % old operator in the theory; [nop] is the new operator in the
   % found atomic formula; [level] is the recursion level of the new
   % found atomic formula. Returns a susiprog that simplifies the
   % formula.
   begin scalar w;
      % Congruences with different moduli
      if pairp oop and pairp nop and cdr oop neq cdr nop then
	 return pasf_susibineqcong(u,oop,nop,level);
      % ASSUMPTION: A congruence is never in the output of pasf_smeqtable
      w := pasf_smeqtable(
	 if pairp oop then car oop else oop,
	 if pairp nop then car nop else nop);
      if car w eq nil then
     	 % Nothing can be done
	 return nil	    
      else if car w eq 'false then
      	 % Contradiction found
	 return 'false
      else if car w eq 1 then
	 % Remove new atomic formula from the level
 	 return {'(delete . T)}
      else if car w eq 2 then
 	 % Remove old atomic formula from the theory, add new atomic
 	 % formula to the knowledge
	 return {'(delete . nil)}
      else if car w eq 3 then
	 % Remove old atomic formula from the theory, remove new
	 % atomic formula from the level, add modified atomic formula to
	 % the level
	 return {'(delete . nil), '(delete . T),
	    ('add . (pasf_0mk2(cdr w, u) . level))}
      else if car w eq 4 then
	 % Remove new atomic formula from the level, add modified
	 % atomic formula to the level
	 return {'(delete . T),
	    ('add . (pasf_0mk2(cdr w, u) . level))}
      else
	 % Remove old atomic formula from the theory, add modified
	 % atomic formula to the level
	 return {'(delete . nil),
	    ('add . (pasf_0mk2(cdr w, u) . level))};
   end;

procedure pasf_susidec(u);
   % Presburger arithmetic standard form decompose atomic
   % fqormula. [u] is a SF. Returns a pair $(p . a)$, where $p$ and
   % $a$ are SF's. $p$ is the parametric part of [u] and
   % $a$ is the absolut part of [u].
   begin scalar par,absv,c;      
      absv := u;
      while not domainp absv do
	 absv := red absv;  
      return (addf(u,negf absv) . absv)
   end;

procedure pasf_susibineqcong(u,oop,nop,level);
   % Presburger arithmetic standard form smart equal simplification
   % with equal lefthand terms in congruences with different
   % moduli. [u] is the (common) lefthand term; [oop] is the old
   % operator in the theory; [nop] is the new operator in the found
   % atomic formula; [level] is the recursion level of the new found
   % atomic formula. Returns a susiprog that simplifies the formula.
   begin
      scalar n,m;     
      n := cdr oop;
      m := cdr nop;
      % Both formulas are congruences
      if car oop eq 'cong and car nop eq 'cong then
	 return{'(delete . nil),'(delete . T),
	    ('add . (pasf_0mk2(pasf_mkop('cong,lcm(m,n)),u) . level))};
      % Old formula is a congruence and new is a incongruence
      if car oop eq 'cong and car nop eq 'ncong then
	 if remainder(n,m) = 0 then
	    return 'false
	 else
	    return nil;
      % Old formula is an incongruence and new is a congurence
      if car oop eq 'ncong and car nop eq 'cong then
	 if remainder(m,n) = 0 then
	    return 'false
	 else
	    return nil;
      % Both formulas are incongruences
      if remainder(m,n) = 0 then
	 return {'(delete . T)}
      else if remainder(n,m) = 0 then
	 return {'(delete . nil)}
      else
	 return nil;
   end;

procedure pasf_susibinord(oop,ot,oabs,nop,nt,nabs,level);
   % Presburger arithmetic standard form additive simplification.
   % [oop] and [nop] are the old and the new relation operators; [ot]
   % and [nt] are the corresponding lefthand sides of the terms;
   % [oabs] and [nabs] are the corresponding constant parts; [level]
   % is the recursion level. Returns a suseproc that simplifies the
   % two atomic formulas.
   begin scalar w;
      % Congruences are treated differently      
      if pairp oop and pairp nop then
	 if cdr oop = cdr nop then
	    return pasf_susibinordcongeq(oop,nop)
	 else
	    return pasf_susibinordcong(oop,ot,oabs,nop,nt,nabs,level);
      % Nothing to do for congruences times order relations
      if pairp oop or pairp nop then
	 return nil;
      w := pasf_smordtable(if pairp oop then car oop else oop,
	 if pairp nop then car nop else nop,oabs,nabs);
      if car w eq nil then
     	 % Nothing can be done
	 return nil	    
      else if car w eq 'false then
      	 % Contradiction found
	 return 'false
      else if car w eq 1 then
	 % Remove new atomic formula from the level
 	 return {'(delete . T)}
      else if car w eq 2 then
 	 % Remove old atomic formula from the theory, add new atomic
 	 % formula to the knowledge
       	 return {'(delete . nil)}
   end;

procedure pasf_susibinordcongeq(oop,nop);
   % Presburger arithmetic standard form smart additive simplification
   % be equal lefthand terms in congruences with equai moduli.[oop]
   % and [nop] are the old and the new relation operators; [ot] and
   % [nt] are the corresponding lefthand sides of the terms; [oabs]
   % and [nabs] are the corresponding constant parts; [level] is the
   % recursion level. Returns a susiprog that simplifies the formula.
   begin
      scalar n,m;     
      n := cdr oop;
      m := cdr nop;
      % Both formulas are congruences
      if car oop eq 'cong and car nop eq 'cong then
	 return 'false;
      % Old formula is a congruence and new is a incongruence
      if car oop eq 'cong and car nop eq 'ncong then
	 return {'(delete . T)};
      % Old formula is an incongruence and new is a congurence
      if car oop eq 'ncong and car nop eq 'cong then
	 return {'(delete . nil)};
      % Both formulas are incongruences
      return nil;
   end;

procedure pasf_susibinordcong(oop,ot,oabs,nop,nt,nabs,level);
   % Presburger arithmetic standard form smart additive simplification
   % be equal lefthand terms in congruences with different
   % moduli. [oop] and [nop] are the old and the new relation
   % operators; [ot] and [nt] are the corresponding lefthand sides of
   % the terms; [oabs] and [nabs] are the corresponding constant
   % parts; [level] is the recursion level. Returns a susiprog that
   % simplifies the formula.
   begin
      scalar n,m;     
      n := cdr oop;
      m := cdr nop;
      % Both formulas are congruences
      if car oop eq 'cong and car nop eq 'cong then
	 return nil;
      return nil;
   end;

procedure pasf_susipost(atl,knowl);
   % Presburger arithmetic standad form susi post
   % simplification. [atl] is a list of atomic formulas. [knowl] is a
   % KNOWL. Returns a list $\lambda$ of atomic formulas, such that
   % $\bigwedge[knowl]\land\bigwedge\lambda$ is equivalent to
   % $\bigwedge[knowl]\and\bigwedge[atl]$
   atl;

procedure pasf_susitf(at,knowl);
   % Presburger arithmetic standard form susi transform. [at] is an
   % atomic formula, [knowl] is a knowledge. Returns an atomic formula
   % $\alpha$ such that $\alpha\land\bigwedge[knowl]$ is equivalent to
   % $[at]\land\bigwedge[knowl]$. $\alpha$ has possibly a more
   % convenient relation than [at].
   at;

procedure pasf_smeqtable(r1,r2);
   % Presburger arithmetic standard form smart simplify equal absolute
   % summands table. [r1], [r2] are relations. Returns [false] or a
   % relation $R$ such that $R(f+a,0)$ is equivalent to $[r1](f+a,0)
   % \land [r2](f+a,0)$.
   begin scalar al;
      al := '(
	 (equal .
	    ((equal . (1 . nil))
	     (neq . (false . nil))
	     (geq . (1 . nil))
             (leq . (1 . nil))
	     (greaterp . (false . nil))
	     (lessp . (false . nil))
	     (cong . (1 . nil))
	     (ncong . (false . nil))))
         (neq .
	    ((equal . (false . nil))
	     (neq . (1 . nil))
	     (geq . (3 . greaterp))
             (leq . (3 . lessp))
	     (greaterp . (2 . nil))
	     (lessp . (2 . nil))
	     (cong . (nil . nil))
	     (ncong . (2 . nil))))		  
         (geq .
	    ((equal . (2 . nil))
	     (neq . (3 . greaterp))
	     (geq . (1 . nil))
             (leq . (3 . equal))
	     (greaterp . (2 . nil))
	     (lessp . (false . nil))
	     (cong . (nil . nil))
	     (ncong . (5 . greaterp))))		      
         (leq .
	    ((equal . (2 . nil))
	     (neq . (3 . lessp))
	     (geq . (3 . equal))
             (leq . (1 . nil))
	     (greaterp . (false . nil))
	     (lessp . (2 . nil))
	     (cong . (nil . nil))
	     (ncong . (5 . lessp))))	   
         (greaterp .
 	    ((equal . (false . nil))
	     (neq . (1 . nil))
	     (geq . (1 . nil))
             (leq . (false . nil))
	     (greaterp . (1 . nil))
	     (lessp . (false . nil))
	     (cong . (nil . nil))
	     (ncong . (nil . nil))))	   
         (lessp .
	     ((equal . (false . nil))
	     (neq . (1 . nil))
	     (geq . (false . nil))
             (leq . (1 . nil))
	     (greaterp . (false . nil))
	     (lessp . (1 . nil))
	     (cong . (nil . nil))
	     (ncong . (nil . nil))))	   
	 (cong .
	    ((equal . (2 . nil))
	     (neq . (nil . nil))
	     (geq . (nil . nil))
             (leq . (nil . nil))
	     (greaterp . (nil . nil))
	     (lessp . (nil . nil))
	     (cong . (1 . nil))
	     (ncong . (nil . nil))))
	 (ncong .
	    ((equal . (false . nil))
	     (neq . (1 . nil))
	     (geq . (4 . greaterp))
             (leq . (4 . lessp))
	     (greaterp . (nil . nil))
	     (lessp . (nil . nil))
	     (cong . (false . nil))
	     (ncong . (1 . nil)))));
      return cdr (atsoc(r2,atsoc(r1,al)))
   end;

procedure pasf_smordtable(r1,r2,s,tt);
   % Presburger arithmetic standard form smart simplify ordered
   % absolute summands. [r1], [r2] are relations, [s] is the constant
   % part of [r1], [t] is the one of [r2]. Returns $(nil . nil)$ if no
   % simplification is possible; $(false . nil)$ if contradiction was
   % found; $(1 . nil)$ if the new formula does not bring any
   % knowledge and can be so removed from the actual level; $(2
   % . nil)$ if the old formula should be removed and the new added.
   if minusf addf(s, negf tt) then
      % -s < -t  =>  s > t
      pasf_smordtable2(r1,r2)
   else
      % -s > -t  =>  s < t
      pasf_smordtable1(r1,r2);
   
procedure pasf_smordtable1(r1,r2);
   % Presburger arithmetic standard form smart simplify ordered
   % absolute summands table if absoulte summand of [r1] is less as
   % the one of [r2].
   begin scalar al;     
      al := '(
	 (lessp .
	    ((lessp . (1 . nil))
             (leq . (1 . nil))
	     (equal . (false . nil))
   	     (neq . (1 . nil))
	     (geq . (false . nil))
	     (greaterp . (false . nil))
	     (cong . (nil . nil))
	     (ncong . (nil . nil))))
	 (leq .
	    ((lessp . (1 . nil))
             (leq . (1 . nil))
	     (equal . (false . nil))
   	     (neq . (1 . nil))
	     (geq . (false . nil))
	     (greaterp . (false . nil))
             (cong . (nil . nil))
	     (ncong . (nil . nil))))
	 (equal .
	    ((lessp . (1 . nil))
             (leq . (1 . nil))
	     (equal . (false . nil))
   	     (neq . (1 . nil))
	     (geq . (false . nil))
	     (greaterp . (false . nil))
	     (cong . (nil . nil))
	     (ncong . (nil . nil))))
	 (neq .
	    ((lessp . (nil . nil))
             (leq . (nil . nil))
	     (equal . (2 . nil))
   	     (neq . (nil . nil))
	     (geq . (2 . nil))
	     (greaterp . (2 . nil))
	     (cong . (nil . nil))
	     (ncong . (nil . nil))))
	 (geq .
	    ((lessp . (nil . nil))
             (leq . (nil . nil))
	     (equal . (2 . nil))
   	     (neq . (nil . nil))
	     (geq . (2 . nil))
	     (greaterp . (2 . nil))
	     (cong . (nil . nil))
	     (ncong . (nil . nil))))
	 (greaterp .
	    ((lessp . (nil . nil))
             (leq . (nil . nil))
	     (equal . (2 . nil))
   	     (neq . (nil . nil))
	     (geq . (2 . nil))
	     (greaterp . (2 . nil))
	     (cong . (nil . nil))
    	     (ncong . (nil . nil))))
	 (cong .
	    ((lessp . (nil . nil))
             (leq . (nil . nil))
	     (equal . (2 . nil))
   	     (neq . (nil . nil))
	     (geq . (2 . nil))
	     (greaterp . (2 . nil))
	     (cong . (nil . nil))
	     (ncong . (nil . nil))))
	 (ncong .
	    ((lessp . (nil . nil))
             (leq . (nil . nil))
	     (equal . (nil . nil))
   	     (neq . (nil . nil))
	     (geq . (nil . nil))
	     (greaterp . (nil . nil))
	     (cong . (nil . nil))
	     (ncong . (nil . nil)))));
      return cdr (atsoc(r2,atsoc(r1,al)))
   end;

procedure pasf_smordtable2(r1,r2);
   % Presburger arithmetic standard form smart simplify ordered
   % absolute summands table if absoulte summand of [r1] is less as
   % the one of [r2].
   begin scalar al;
      al := '(
	 (lessp .
	    ((lessp . (2 . nil))
             (leq . (2 . nil))
	     (equal . (2 . nil))
   	     (neq . (nil . nil))
	     (geq . (nil . nil))
	     (greaterp . (nil . nil))
	     (cong . (nil . nil))
	     (ncong . (nil . nil))))
	 (leq .
	    ((lessp . (2 . nil))
             (leq . (2 . nil))
	     (equal . (2 . nil))
   	     (neq . (nil . nil))
	     (geq . (nil . nil))
	     (greaterp . (nil . nil))
             (cong . (nil . nil))
	     (ncong . (nil . nil))))
	 (equal .
	    ((lessp . (false . nil))
             (leq . (false . nil))
	     (equal . (false . nil))
   	     (neq . (1 . nil))
	     (geq . (1 . nil))
	     (greaterp . (1 . nil))
	     (cong . (nil . nil))
	     (ncong . (nil . nil))))
	 (neq .
	    ((lessp . (2 . nil))
             (leq . (2 . nil))
	     (equal . (2 . nil))
   	     (neq . (nil . nil))
	     (geq . (nil . nil))
	     (greaterp . (nil . nil))
	     (cong . (nil . nil))
	     (ncong . (nil . nil))))
	 (geq .
	    ((lessp . (false . nil))
             (leq . (false . nil))
	     (equal . (false . nil))
   	     (neq . (1 . nil))
	     (geq . (1 . nil))
	     (greaterp . (1 . nil))
	     (cong . (nil . nil))
	     (ncong . (nil . nil))))
	 (greaterp .
	    ((lessp . (false . nil))
             (leq . (false . nil))
	     (equal . (false . nil))
   	     (neq . (1 . nil))
	     (geq . (1 . nil))
	     (greaterp . (1 . nil))
	     (cong . (nil . nil))
    	     (ncong . (nil . nil))))
	 (cong .
	    ((lessp . (nil . nil))
             (leq . (nil . nil))
	     (equal . (nil . nil))
   	     (neq . (nil . nil))
	     (geq . (nil . nil))
	     (greaterp . (nil . nil))
	     (cong . (nil . nil))
	     (ncong . (nil . nil))))
	 (ncong .
	    ((lessp . (nil . nil))
             (leq . (nil . nil))
	     (equal . (nil . nil))
   	     (neq . (nil . nil))
	     (geq . (nil . nil))
	     (greaterp . (nil . nil))
	     (cong . (nil . nil))
	     (ncong . (nil . nil)))));
      return cdr (atsoc(r2,atsoc(r1,al)))
   end;

procedure pasf_smtrtable(r1,r2);
   % Presburger arithmetic standard form smart transitive
   % simplification table. [r1] is the theory relation; [r2] is the
   % new level relation. Returns a new transitive concluded relation
   % or nil if no conclusion can be done.
   begin scalar al;
      % For these operations no transitive simplification is done
      if r1 memq '(neq greaterp cong ncong) then
	 return nil;    
      al := '(
	 (equal .
	    ((equal . equal)
             (greaterp . lessp)
	     (geq . leq)
	     (leq . nil)
	     (lessp . nil)
	     (neq . nil)
	     (cong . nil)
	     (ncong . nil)))
	 (lessp .
	    ((equal . lessp)
             (greaterp . lessp)
	     (geq . lessp)
	     (leq . nil)
	     (lessp . nil)
	     (neq . nil)
	     (cong . nil)
	     (ncong . nil)))
	 (geq .
	    ((equal . nil)
             (greaterp . nil)
	     (geq . nil)
	     (leq . nil)
	     (lessp . nil)
	     (neq . nil)
	     (cong . nil)
	     (ncong . nil)))
	 (leq .
	    ((equal . leq)
             (greaterp . lessp)
	     (geq . leq)
	     (leq . nil)
	     (lessp . nil)
	     (neq . nil)
	     (cong . nil)
	     (ncong . nil))));		  
      return cdr (atsoc(r2,atsoc(r1,al)))
   end;
   
endmodule;  % [pasfsism]

end;  % of file
