% ----------------------------------------------------------------------
% $Id: pasfsism.red,v 1.31 2008/03/13 14:10:17 lasaruk Exp $
% ----------------------------------------------------------------------
% Copyright (c) 2003 Andreas Dolzmann and Andreas Seidl
% ----------------------------------------------------------------------
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

% $Log: pasfsism.red,v $
% Revision 1.31  2008/03/13 14:10:17  lasaruk
% Changes
%
% Revision 1.30  2007/07/10 09:13:36  lasaruk
% Bug in substitution procedure in pasfmisc corrected.
%
% Revision 1.29  2007/06/21 18:43:49  lasaruk
% Factorization of atomic formulas, smart substitution
%
% Revision 1.28  2007/03/22 17:45:35  lasaruk
% rlint bug reports corrected
%
% Revision 1.27  2006/11/06 19:07:52  lasaruk
% eq's replaced by eqn's in integer comparisons
%
% Revision 1.26  2006/06/02 07:37:56  lasaruk
% bugs found by cref eliminated
%
% Revision 1.25  2005/08/04 11:03:58  lasaruk
% Uniform comments
%
% Revision 1.24  2005/07/17 20:42:29  lasaruk
% New comments
%
% Revision 1.23  2005/04/29 12:17:16  lasaruk
% Debugging code removed
%
% Revision 1.22  2005/04/27 19:39:23  lasaruk
% Version the tests for diplomarbeit ran on
%
% Revision 1.21  2005/01/24 16:02:08  lasaruk
% Uniform Presburger Arithmetic is now implemented. Elimination code rewritten,
% so no elimination normal form is explicitly computed.
%
% Revision 1.20  2005/01/22 20:23:40  lasaruk
% Uniform Presburger Arithmetic introduced
%
% Revision 1.19  2005/01/15 20:28:27  lasaruk
% Quantifier elimination with answers experimental version
%
% Revision 1.18  2004/11/05 19:51:43  lasaruk
% calls to pasf_simplat1 corrected globally
%
% Revision 1.17  2004/08/29 20:42:13  lasaruk
% Simplification of atomic formulas rewritten without the term
% normal form. Administration details switches and other
% stuff put into some order and are commented now. Floor and
% ceil procedures corrected to fit the semantics. pasf_susidec
% moved to pasf_dec. pasf_deci for integer decomposition added.
% In QE the simplification is done at the last stage even if
% rlpasfsimplify is turned off. All sutable rl_mkn's are turned
% to rl_smkn. In pasfsiat.red order reduction has been added.
% In pasfsism.red substitution and simplification goals have
% been revisited. Configuration tested on more than 3*10^5
% formulas with different structure.
%
% Revision 1.16  2004/08/11 15:17:08  lasaruk
% New comments done. Now automatic procedure documentation possible. 
% Some code rewritten.
%
% Revision 1.15  2004/08/06 15:35:17  lasaruk
% Congruence simplification added. Some errors corrected.
%
% Revision 1.14  2004/06/09 06:38:09  lasaruk
% Smart simplification improoved. Transitive simplification added
% (without modifications on clsimpl not functional)
%
% Revision 1.13  2004/06/01 16:49:35  lasaruk
% Errors corrected
%
% Revision 1.12  2004/06/01 15:25:15  lasaruk
% simple gauss simplification added, transitive simplification
% with switches temporary removed, additive simplification
% filled with some minor cases
%
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
      "$Id: pasfsism.red,v 1.31 2008/03/13 14:10:17 lasaruk Exp $";
   pasf_sism_copyright!* :=
      "Copyright (c) 2003 by A. Dolzmann. A. Seidl and T. Sturm"
>>;


module pasfsism;
% Presburger arithmetic standard form smart simplification. Submodule of PASF.

procedure pasf_smwupdknowl(op,atl,knowl,n);
   % Presburger arithmetic standard form update knowledge. [op] is an
   % operator; [atl] is the list of atomic formulas to add to the knowledge;
   % [knowl] is a knowledge; [n] is the level. Returns modified knowledge.
   if !*rlsusi then
      cl_susiupdknowl(op,atl,knowl,n)
   else
      cl_smupdknowl(op,atl,knowl,n);

procedure pasf_smwrmknowl(knowl,v);
   % Presburger arithmetic standard form remove variable from the
   % knowledge. [knowl] is a knowledge; [v] is the variable to remove. Returns
   % modified knowledge.
   if !*rlsusi then
      pasf_susirmknowl(knowl,v)
   else
      cl_smrmknowl(knowl,v);

procedure pasf_smwcpknowl(knowl);
   % Presburger arithmetic standard form copy knowledge. [knowl] is a
   % knowledge. Returns a copy of the knowledge.
   if !*rlsusi then
      cl_susicpknowl(knowl)
   else
      cl_smcpknowl(knowl);

procedure pasf_smwmkatl(op,knowl,newknowl,n);
   % Presburger arithmetic standard form make atomic formula list. [op] is an
   % operator; [knowl] is a knowledge; [newknowl] is a knowledge; [n] is the
   % current level. Returns an atomic formula list. For detailed documentation
   % refer to clsimpl.red.
   if !*rlsusi then
      cl_susimkatl(op,knowl,newknowl,n)
   else
      cl_smmkatl(op,knowl,newknowl,n);

procedure pasf_susirmknowl(knowl,v);
   % Presburger arithmetic standard form remove knowledge. [knowl] is a
   % knowledge; [v] is a variable. Returns a knowledge. Removes all
   % information about [v] from [knowl].
   for each p in knowl join
      if v memq pasf_varlat car p then nil else {p};

procedure pasf_susibin(old,new);
   % Presburger arithmetic standard form susi binary smart
   % simplification. [old] is a LAT; [new] is a LAT. Returns 'false or a
   % SUSIPROG.
   pasf_susibinad(old,new);
   
procedure pasf_susibinad(old,new);
   % Presburger standard form additive smart simplification. [old] is the old
   % atomic formula in the theory; [new] is the new atomic formula
   % found. Returns a SUSIPROG that simplifies the formula.
   begin scalar od,nd,level,olevel,kn,ko;
      level := cl_susiminlevel(cdr old,cdr new);
      olevel := cdr old;
      old := car old;
      new := car new;
      % Check for truth value of the level formula
      if rl_tvalp new then
	 (if new eq 'false then
	    return 'false
	 else
	    return {'(delete . T)});
      % Equal left handsides simplification
      if pasf_arg2l old = pasf_arg2l new then
	 return pasf_susibineq(pasf_arg2l old,pasf_op old,pasf_op new,level);
      % Decomposing both atomic formulas for additive simplification
      od := pasf_dec pasf_arg2l old;
      nd := pasf_dec pasf_arg2l new;
      if car od = car nd then 
	 % Equal parametric parts
	 return pasf_susibinord(
	    pasf_op old,car od,if cdr od then cdr od else 0,
	    pasf_op new,car nd,if cdr nd then cdr nd else 0,level);
      ko := kernels car od;
      kn := kernels car nd;
      % Integer substitution
      if pasf_op old eq 'equal and null cdr ko 
	 and car ko memq kn then
	  return {'(delete . T), ('add .
		(pasf_simplat1(pasf_subfof1(new,car ko,negf cdr od),nil)
		   . level))}
      else if pasf_op new eq 'equal and null cdr kn 
	 and car kn memq ko then
	    return {'(delete . nil), ('add .
	       (pasf_simplat1(pasf_subfof1(old,car kn,negf cdr nd),nil)
		  . level))};
      return nil
   end;

procedure pasf_susibineq(u,oop,nop,level);
   % Presburger arithmetic standard form smart simplification with equal left
   % handside terms. [u] is the (common) left handside term; [oop] is the old
   % operator in the theory; [nop] is the new operator in the found atomic
   % formula; [level] is the recursion level of the new found atomic
   % formula. Returns a SUSIPROG that simplifies the formula.
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
      else if eqn(car w,1) then
	 % Remove new atomic formula from the level
 	 return {'(delete . T)}
      else if eqn(car w,2) then
 	 % Remove old atomic formula from the theory, add new atomic
 	 % formula to the knowledge
	 return {'(delete . nil)}
      else if eqn(car w,3) then
	 % Remove old atomic formula from the theory, remove new
	 % atomic formula from the level, add modified atomic formula to
	 % the level
	 return {'(delete . nil), '(delete . T),
	    ('add . (pasf_0mk2(cdr w, u) . level))}
      else if eqn(car w,4) then
	 % Remove new atomic formula from the level, add modified
	 % atomic formula to the level
	 return {'(delete . T),
	    ('add . (pasf_0mk2(cdr w, u) . level))}
      else
	 % Remove old atomic formula from the theory, add modified
	 % atomic formula to the level
	 return {'(delete . nil),
	    ('add . (pasf_0mk2(cdr w, u) . level))}
   end;

procedure pasf_susibineqcong(u,oop,nop,level);
   % Presburger arithmetic standard form smart equal simplification with equal
   % left handside terms in congruences with different moduli. [u] is the
   % (common) left handside term; [oop] is the old operator in the theory;
   % [nop] is the new operator in the found atomic formula; [level] is the
   % recursion level of the new found atomic formula. Returns a SUSIPROG that
   % simplifies the formula.
   begin scalar n,m,mo,atf;
      n := cdr oop;
      m := cdr nop;
      % For parametric moduli nothing yet
      if null domainp n or null domainp m then return nil;
      % Both formulas are congruences
      if car oop eq 'cong and car nop eq 'cong then
	 return{'(delete . nil),'(delete . T),
	    ('add . (pasf_0mk2(pasf_mkop('cong,lcm(m,n)),u) . level))};
      % Old formula is a congruence and new is a incongruence
      if car oop eq 'cong and car nop eq 'ncong then <<
	 if m = 2*n then
	    return{'(delete . T),('delete . nil),('add .
	       (pasf_0mk2(pasf_mkop('ncong,m),addf(u,negf n)) . level))}
	 else <<
	    % Making sure changes are really applied
	    mo := pasf_susibineqcong1(m,n);
	    if mo neq m then <<
	       atf := pasf_simplat1(pasf_0mk2(pasf_mkop('ncong,mo),u),nil);
	       if atf eq 'false then
		  return atf
	       else if atf eq 'true then
		  return nil
	       else
	       	  return{'(delete . T),('add . (atf . level))}
	    >> else
	       return nil
	 >>
      >>;	    
      % Old formula is an incongruence and new is a congurence
      if car oop eq 'ncong and car nop eq 'cong then <<
	 if n = 2*m then
	    return{'(delete . nil),'(delete . T),('add .
	       (pasf_0mk2(pasf_mkop('ncong,n),addf(u,negf m)) . level))}
	 else <<
	    % Making sure changes are really applied
	    mo := pasf_susibineqcong1(n,m);
	    if mo neq m then <<
	       atf := pasf_simplat1(pasf_0mk2(pasf_mkop('ncong,mo),u),nil);
	       if atf eq 'false then
		  return atf
	       else if atf eq 'true then
		  return nil
	       else	       		       
	       	  return{'(delete . nil), ('add . (atf . level))}
	    >> else
	       return nil	    
	 >>
      >>;
      % Both formulas are incongruences
      if remainder(m,n) = 0 then
	 return {'(delete . T)}
      else if remainder(n,m) = 0 then
	 return {'(delete . nil)}
      else
	 return nil
   end;

procedure pasf_susibineqcong1(m,n);
   % Presburger arithmetic standard form smart equal simplification with equal
   % left handside terms in congruences with different moduli subprocedure.
   % [m] is the modulus of the incongruence; [n] is the modulus of the
   % congruence. Returns the reduced modulus (see the diplom thesis of lasaruk
   % for details).
   begin scalar p;
      % For parametric moduli nothing yet
      if null domainp n or null domainp m then return nil;
      % ASSERTION: m,n are greater than 1 (due to atomic formula normal form)
      if (m <= 1 or n <= 1) then
	 rederr{"pasf_susibineqcong1: wrong modulus in input"};
      p := zfactor(n);
      for each f in p do
	 % Factor is present in m with minor power
	 if remainder(m,car f) = 0 and
	 remainder(m,(car f)^(cdr f)) neq 0 then
	    while (remainder(m,car f) = 0) do
	       m := m / car f;	 
      return m
   end;
   
procedure pasf_susibinord(oop,ot,oabs,nop,nt,nabs,level);
   % Presburger arithmetic standard form additive simplification. [oop] is the
   % old relation operator; [nop] is the new relation operator; [ot] is the
   % left handside of the old formula; [nt] is the left handside of the new
   % formula; [oabs] is the constant part of the old formula; [nabs] is the
   % constant parts of the new formula; [level] is the recursion
   % level. Returns a SUSIPROG that simplifies the two atomic formulas.
   begin scalar w,oabsv,nabsv;
      % Congruences are treated differently
      if pairp oop and pairp nop then
	 if cdr oop = cdr nop then
	    return pasf_susibinordcongeq(oop,nop)
	 else
	    return pasf_susibinordcong(oop,ot,oabs,nop,nt,nabs,level);
      % Nothing to do for congruences times order relations
      if pairp oop or pairp nop then
	 return nil;
      % Special cases
      oabsv := if null oabs then 0 else oabs;
      nabsv := if null nabs then 0 else nabs;
      % Special case: strict inequalities with an emptyset gap
      if (oop eq 'lessp and nop eq 'greaterp and oabsv + 1 = nabsv) or	
       	 (nop eq 'lessp and oop eq 'greaterp and nabsv + 1 = oabsv) then
	    return 'false;
      % Special case: inequalities with single point satisfaction set
      if oop eq 'geq and nop eq 'lessp and nabsv + 1 = oabsv then
	 return {'(delete . T), '(delete . nil),
	    ('add . (pasf_0mk2('equal, addf(ot,numr simp oabs)) . level))};
      if nop eq 'geq and oop eq 'lessp and oabsv + 1 = nabsv then
	 return {'(delete . T), '(delete . nil),
	    ('add . (pasf_0mk2('equal, addf(ot,numr simp nabs)) . level))};
      if oop eq 'leq and nop eq 'greaterp and oabsv + 1 = nabsv then
	 return {'(delete . T), '(delete . nil),
	    ('add . (pasf_0mk2('equal, addf(ot,numr simp oabs)) . level))};
      if nop eq 'leq and oop eq 'greaterp and nabsv + 1 = oabsv then
	 return {'(delete . T), '(delete . nil),
	    ('add . (pasf_0mk2('equal, addf(ot,numr simp nabs)) . level))};
      w := pasf_smordtable(oop,nop,oabs,nabs);
      if car w eq nil then
     	 % Nothing can be done
	 return nil	    
      else if car w eq 'false then
      	 % Contradiction found
	 return 'false
      else if eqn(car w,1) then
	 % Remove new atomic formula from the level
 	 return {'(delete . T)}
      else if eqn(car w,2) then
 	 % Remove old atomic formula from the theory, add new atomic formula
 	 % to the knowledge
       	 return {'(delete . nil)};
      reutrn nil
   end;

procedure pasf_susibinordcongeq(oop,nop);
   % Presburger arithmetic standard form smart additive simplification with
   % equal left handside terms in congruences with equai moduli. [oop] is the
   % old relation operator; [nop] is the new relation operator. Returns a
   % SUSIPROG that simplifies the formula.
   begin scalar n,m;
      n := cdr oop;
      m := cdr nop;
      % For parametric moduli nothing yet
      if null domainp n or null domainp m then return nil;
      % Both formulas are congruences
      if car oop eq 'cong and car nop eq 'cong then
	 return 'false;
      % Old formula is a congruence and new is an incongruence
      if car oop eq 'cong and car nop eq 'ncong then
	 return {'(delete . T)};
      % Old formula is an incongruence and new is a congurence
      if car oop eq 'ncong and car nop eq 'cong then
	 return {'(delete . nil)};
      % Both formulas are incongruences
      return nil
   end;

procedure pasf_susibinordcong(oop,ot,oabs,nop,nt,nabs,level);
   % Presburger arithmetic standard form additive simplification. [oop] is the
   % old relation operator; [nop] is the new relation operator; [ot] is the
   % left handside of the old formula; [nt] is the left handside of the new
   % formula; [oabs] is the constant part of the old formula; [nabs] is the
   % constant part of the new formula; [level] is the recursion
   % level. Returns a SUSIPROG that simplifies the two atomic formulas.
   begin scalar n,m,eucd;
      n := cdr oop;
      m := cdr nop;
      % For parametric moduli nothing yet
      if null domainp n or null domainp m then return nil;
      if car oop eq 'cong and car nop eq 'cong and gcdf(n,m) = 1 then <<
	 eucd := sfto_exteucd(n,m);
	 return {'(delete . T), '(delete . nil),
	    ('add . (pasf_simplat1(pasf_0mk2(pasf_mkop('cong,numr simp (n*m)),
	       addf(ot, 
		  numr simp(n*(cadr eucd)*nabs + 
		  m*(caddr eucd)*oabs))),nil) . level))}
      	 >>;
      return nil
   end;

procedure pasf_susipost(atl,knowl);
   % Presburger arithmetic standad form susi post simplification. [atl] is a
   % list of atomic formulas; [knowl] is a knowledge. Returns a list $\lambda$
   % of atomic formulas, such that $\bigwedge [knowl] \land \bigwedge \lambda$
   % is equivalent to $\bigwedge [knowl] \land \bigwedge [atl]$.
   atl;

procedure pasf_susitf(at,knowl);
   % Presburger arithmetic standard form susi transform. [at] is an atomic
   % formula; [knowl] is a knowledge. Returns an atomic formula $\alpha$ such
   % that $\alpha \land \bigwedge [knowl]$ is equivalent to $[at] \land
   % \bigwedge [knowl]$ ($\alpha$ has possibly a more convenient relation than
   % [at]).
   at;

procedure pasf_smeqtable(r_1,r_2);
   % Presburger arithmetic standard form smart simplify equal absolute
   % summands table. [r_1] is a relation; [r_2] is a relation. Returns 'false
   % or a relation $r$ such that $r(t,0)$ is equivalent to $[r_1](t,0) \land
   % [r_2](t,0)$.
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
	     (ncong . (false . nil))))
	 (ncong .
	    ((equal . (false . nil))
	     (neq . (1 . nil))
	     (geq . (4 . greaterp))
             (leq . (4 . lessp))
	     (greaterp . (nil . nil))
	     (lessp . (nil . nil))
	     (cong . (false . nil))
	     (ncong . (1 . nil)))));
      return cdr (atsoc(r_2,atsoc(r_1,al)))
   end;

procedure pasf_smordtable(r1,r2,s,tt);
   % Presburger arithmetic standard form smart simplify ordered absolute
   % summands. [r1] is a relation; [r2] is a relation; [s] is the constant
   % part of [r1]; [t] is the constant part of [r2]. Returns '(nil . nil) if
   % no simplification is possible; '(false . nil) if contradiction was found;
   % '(1 . nil) if the new formula does not bring any knowledge and can be so
   % removed from the actual level; '(2 . nil) if the old formula should be
   % removed and the new added.
   if s < tt then
      pasf_smordtable2(r1,r2)
   else if s > tt then
      pasf_smordtable1(r1,r2)
   else
      rederr {"abused smordtable"};
   
procedure pasf_smordtable1(r1,r2);
   % Presburger arithmetic standard form smart simplify ordered absolute
   % summands table if absoulte summand of $r1$ is less as the one of $r2$.
   % [r1] is a relaton; [r2] is a relation. Returns '(nil . nil) if no
   % simplification is possible; '(false . nil) if contradiction was found;
   % '(1 . nil) if the new formula does not bring any knowledge and can be so
   % removed from the actual level; '(2 . nil) if the old formula should be
   % removed and the new added.
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
    	     (ncong . (nil . nil)))));
      return cdr (atsoc(r2,atsoc(r1,al)))
   end;

procedure pasf_smordtable2(r1,r2);
   % Presburger arithmetic standard form smart simplify ordered absolute
   % summands table if absoulte summand of $r1$ is less as the one of $r2$.
   % [r1] is a relaton; [r2] is a relation. Returns '(nil . nil) if no
   % simplification is possible; '(false . nil) if contradiction was found;
   % '(1 . nil) if the new formula does not bring any knowledge and can be so
   % removed from the actual level; '(2 . nil) if the old formula should be
   % removed and the new added.
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
    	     (ncong . (nil . nil)))));
      return cdr (atsoc(r2,atsoc(r1,al)))
   end;

endmodule; % [pasfsism]

end; % of file
