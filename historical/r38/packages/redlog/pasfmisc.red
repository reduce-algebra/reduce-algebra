% ----------------------------------------------------------------------
% $Id: pasfmisc.red,v 1.43 2003/12/11 10:51:19 lasaruk Exp $
% ----------------------------------------------------------------------
% Copyright (c) 2002 A. Dolzmann, A. Seidl, and T. Sturm
% ----------------------------------------------------------------------
% $Log: pasfmisc.red,v $
% Revision 1.43  2003/12/11 10:51:19  lasaruk
% Smart simplification improoved.
%
% Revision 1.42  2003/12/03 13:39:17  dolzmann
% Fixed wrong calling of pasf_qff2ivl in pasf_bsatp.
%
% Revision 1.41  2003/12/02 07:43:08  lasaruk
% Additive smart simplification added.
%
% Revision 1.40  2003/11/28 06:30:11  lasaruk
% spaces removed. bsatp function added.
%
% Revision 1.39  2003/11/12 08:00:30  dolzmann
% Changed a rl_mkn into rl_smkn correting a wrong construction of a or
% containing only one argument.
%
% Revision 1.38  2003/11/11 15:05:59  sturm
% (Temporarily?) removed special treatment for 'and in pasf_b2atl.
%
% Revision 1.37  2003/11/11 14:56:50  sturm
% Fixed a bug in iv_merge.
%
% Revision 1.36  2003/10/28 09:55:42  dolzmann
% Removed trailing spaces.
%
% Revision 1.35  2003/10/16 16:17:38  lasaruk
% Compiler error messages partially removed. All others are due
% to the noncompleteness of packet.
%
% Revision 1.34  2003/08/12 19:51:17  lasaruk
% Bug in pasf_atf2ivl corrected
%
% Revision 1.33  2003/08/05 08:57:17  seidl
% Intermediate check-in.
%
% Revision 1.32  2003/07/22 10:06:33  lasaruk
% Serious bug in atf2ivl and pasf_ceil and pasf_floor removed.
%
% Revision 1.31  2003/07/21 21:57:41  seidl
% Intermediate check-in. Part of advanced smart simplification works
% already.
%
% Revision 1.30  2003/07/16 13:50:47  lasaruk
% Debug messages removed. Bug in printing congurences removed.
% Testfile adjusted to changes (working cases).
%
% Revision 1.29  2003/07/16 12:43:44  lasaruk
% conflicts resolved. pasf_simpl removed. implementation of
% pasf_simplb and pasf_b2terml added and tested.
% temporary method for pasf_b2terml in algebraic mode added.
% empty list bug in pasf_ivl2qff removed.
% expansion method uses now pasf_b2terml. some comments done
% better.
%
% Revision 1.28  2003/07/15 12:40:41  seidl
% Renamed pasf_iv2qff to pasf_ivl2qff and pasf_qff2iv to pasf_qff2ivl.
% Provided algebraic mode access to simplb, ivl2qff, qdd2ivl. Changed
% pasf_mkrng so intervals with same upper and lower bound result in an
% equation. Fixed serious bug in pasf_prepat. Added cvs header to
% pasf.tst. Todo Lasaruk: pasf_ivl2qff crashes with empty interval as
% argument, see testfile.
%
% Revision 1.27  2003/07/14 12:37:58  lasaruk
% Common utilities attached and tested (see the testfile).
%
% Revision 1.26  2003/06/12 20:54:51  lasaruk
% Testcases added. Small bug in merging fixed. true and false cases added.
%
% Revision 1.25  2003/06/04 12:33:40  lasaruk
% Some smaller modifications.
%
% Revision 1.24  2003/05/31 14:41:50  lasaruk
% PNF corrected. examples added.
%
% Revision 1.23  2003/05/28 20:37:51  lasaruk
% Expansion done better.
%
% Revision 1.22  2003/05/26 20:50:57  lasaruk
% Range expansion with congruences
%
% Revision 1.21  2003/05/22 22:00:58  lasaruk
% DNF added.
%
% Revision 1.20  2003/05/17 17:04:16  lasaruk
% bugs removed
%
% Revision 1.19  2003/05/17 16:27:56  lasaruk
% Pasf simplification added. Some errors corrected.
%
% Revision 1.18  2003/05/15 23:34:47  lasaruk
% Interval expansion added
%
% Revision 1.17  2003/04/20 12:04:04  lasaruk
% Completely removed any reference to range predicates (in input
% also). PNF made shorter.
%
% Revision 1.16  2003/04/14 10:11:39  lasaruk
% Changes to work with bounded quantifieres added . Simplification bug
% (content) removed. Range predicates removed.
%
% Revision 1.15  2003/03/16 22:31:45  lasaruk
% PNF-bug removed.
%
% Revision 1.14  2003/03/04 09:33:23  lasaruk
% Advanced simplification. PNF code attached but not used yet. Some code
% migration. Documentation debugged.
%
% Revision 1.13  2003/02/24 12:50:37  lasaruk
% Bug caused congruence error fixed.
%
% Revision 1.12  2003/02/17 10:55:40  lasaruk
% Stable full featured version
%
% Revision 1.11  2003/02/03 13:41:04  lasaruk
% Experimental version with full functionality. A bit buggy.
%
% Revision 1.10  2002/12/23 07:05:59  lasaruk
% Operator pasf_op replaced by pasf_opn
%
% Revision 1.9  2002/12/02 12:53:37  lasaruk
% Elimination of one variable in front of an ex quantifier. Not really
% worth looking at.
%
% Revision 1.8  2002/10/10 09:09:20  lasaruk
% Range predicate implemented. Todo: logical negation of range predicate
%
% Revision 1.7  2002/10/02 14:31:19  lasaruk
% Initial check in. Only dummy methods for advanced simplification first.
%
% Revision 1.6  2002/09/26 14:54:55  lasaruk
% Errors corrected. Negation form implemented.
%
% Revision 1.5  2002/09/26 10:47:31  lasaruk
% Prenex normal form functionality added. Tests follow.
%
% Revision 1.4  2002/09/19 08:49:42  lasaruk
% All operators are binary. Before printing modulus of cong and ncong is
% put directly after the operator. Ordering corrected.
%
% Revision 1.3  2002/08/26 11:57:14  lasaruk
% Added implementation of black box rl_ordatp
%
% Revision 1.2  2002/08/23 12:32:53  dolzmann
% Added neccessary end; at the end of the file.
%
% Revision 1.1  2002/08/23 08:07:19  seidl
% Added service rl_atl with trival black box rl_ordatp.
% Created module pasfmisc for this.
%
% ----------------------------------------------------------------------
lisp <<
   fluid '(pasf_misc_rcsid!* pasf_misc_copyright!*);
   pasf_misc_rcsid!* := "$Id: pasfmisc.red,v 1.43 2003/12/11 10:51:19 lasaruk Exp $";
   pasf_misc_copyright!* :=
      "Copyright (c) 1995-2002 by A. Dolzmann, A. Seidl, and T. Sturm"
>>;

module pasfmisc;

procedure iv_new(lb,rb);
   % Interval datastructure constructor. [lb] is the lower bound and
   % [rb] is the upper bound. Returns a new interval $[lb,rb]$
   % (including the bounds).
   {((if lb then lb else 0) . (if rb then rb else 0))};

procedure iv_newcong(op,class);
   % Interval datastructure congruence constructor. [op] is the
   % congruence operator (cong . modulo) or (ncong . modulo) and class
   % is a representant of the congruence class. Returns the (non
   % trivial) datastructure representation for $var op class$.
   {(op . if class then class else 0)};

procedure iv_congp(ivl);
   % Interval datastructure new interval congruence predicate.  [ivl]
   % is an interval list. Returns t if and only if [ivl] contains a
   % congruence.
   if ivl then pairp caar ivl or iv_congp cdr ivl;

procedure iv_empty(ivl);
   % Interval datastructure empty attribut. [ivl] is a an interval
   % list. Returns t if the list is empty.
   not ivl;

procedure iv_congsplitl(ivl);
   % Interval datastructure congruence split of a interval list. [ivl]
   % is an interval list.  Returns a pair (iv1 . iv2) where ivl1 is a
   % list of intervals without congruences and iv2 are all the
   % congruences.
   begin scalar split,rest;
      % Termination of the recursion
      if ivl then return (nil . nil);
      % Splitting the first list
      split := iv_congsplit car ivl;
      rest := iv_congsplitl cdr ivl;
      return ((car split . car rest) . (cdr split . cdr rest));
   end;

procedure iv_congsplit(iv);
   % Interval datastructure congruence split. [iv] is an interval.
   % Returns a pair (iv1 . iv2) where iv1 all intervals without
   % congruences and iv2 are all the congruences.
   if iv then
      if iv_congp({car iv}) then
	 (car iv_congsplit cdr iv . (car iv . cdr iv_congsplit cdr iv))
      else
	 ((car iv . car iv_congsplit cdr iv) . cdr iv_congsplit cdr iv)
   else
      (nil . nil);

procedure iv_cutn(ivl);
   % Interval datastructure multiple interval cut. [ivl] is a list of
   % intervals. Returns interval $\cap ivl$.
   if cdr ivl then
      iv_cut(car ivl,iv_cutn cdr ivl)
   else
      car ivl;

procedure iv_cut(iv1,iv2);
   % Interval datastructure cut. [iv1] and [iv2] are congruence free
   % intervals. Returns interval $iv_1 \cap iv_2$.
   begin scalar curr,lower,res;
      % If one of the intervals is empty returning nil
      if iv_empty iv1 or iv_empty iv2 then
	 return nil;
      % Until all lists are empty
      while not(iv_empty iv1 and iv_empty iv2) do <<
	 % Choosing the interval with the smallest lower bound.  If
	 % one of those is empty then we take the lower bound from the
	 % over one.
	 if iv_empty iv2 or
	    (not iv_empty iv1 and pasf_leqp(caar iv1,caar iv2)) then <<
	       lower := car iv1;
	       iv1 := cdr iv1
	    >> else <<
	       lower := car iv2;
	       iv2 := cdr iv2
	    >>;
	 % Initialization of a new result interval
	 if null curr then
	    curr := lower
	 else
	    if pasf_leq(cdr curr,car lower) then
	       % The limit of the next smallest interval is bigger
	       % than the end of the current
	       curr := lower
	    else
	       if pasf_leqp(cdr curr,cdr lower) then <<
		  res := (car lower . cdr curr) . res;
		  curr := lower
	       >> else
		  res := lower . res;
      >>;
      return reverse res
   end;

procedure iv_cutcongs(ivl,congs);
   % Interval datastructure congruence processing. [ivl] is
   % a congruence free interval list; [congs] is a list of
   % congruences. Returns $congs \cup ivl$.
   begin scalar curr,res;
      if not congs then return ivl;
      while not iv_empty ivl do <<
	 for i := caar ivl : cdar ivl do <<
	    iv_cutcongs1(i,congs);
	    if iv_cutcongs1(i,congs) then
	       if curr then
		  curr := (car curr . i)
	       else
		  curr := (i . i)
	    else
	       if curr then <<
		  res := curr . res;
		  curr := nil
	       >>
	 >>;
	 % Joining the last interval limit
	 if null cdr ivl and curr then
	    res := (car curr . cdar ivl) . res;
	 ivl := cdr ivl
      >>;
      return reverse res
   end;

procedure iv_cutcongs1(val,congs);
   % Interval datastructure congruence processing. [val] is
   % a value; [congs] is a list of congruences. Returns
   % t if and only if [val] satisfies all congruences.
   if congs then
      iv_cutcongs2(val,car congs) and iv_cutcongs1(val,cdr congs)
   else
      't;

procedure iv_cutcongs2(val,cong);
   % Interval datastructure congruence processing. [val] is a value;
   % [congs] is a congruence. Returns t if and only if [val] satisfies
   % [cong].
   if caar cong eq 'cong then
      remainder(cdr cong - val,cdar cong) = 0
   else
      remainder(cdr cong - val,cdar cong) <> 0;

procedure iv_mergen(ivl);
   % Interval datastructure multiple intervals merge. [ivl] is an
   % interval list. Returns interval $\cup ivl$.
   if cdr ivl then
      iv_merge(car ivl,iv_mergen cdr ivl)
   else
      car ivl;

procedure iv_merge(iv1,iv2);
   % Interval datastructure merge. [iv1] and [iv2] are intervals.
   % Returns interval $iv_1 \cup iv_2$.
   begin scalar curr,lower,res;
      % Test for congruences in the intervals
      if iv_congp iv1 or iv_congp iv2 then
	 rederr{"iv_merge : merging a congruence not possible }"};
      % Test for empty input lists
      if iv_empty iv1 and iv_empty iv2 then
	 return nil;
      % Until all lists are empty
      while not(iv_empty iv1 and iv_empty iv2) do <<
	 % Choosing the interval with the smallest lower bound.  If
	 % one of those is empty then we take the lower bound from the
	 % over one.
      	 if iv_empty iv2 or
	    (not iv_empty iv1 and pasf_leqp(caar iv1,caar iv2)) then <<
	    lower := car iv1;
	    iv1 := cdr iv1
	 >> else <<
	    lower := car iv2;
	    iv2 := cdr iv2
	 >>;
	 % Initialization of a new result interval
	 if not curr then
	    curr := lower
	 else
	    if pasf_leq(cdr curr,car lower) then <<
	       % The limit of the next smallest interval is bigger
	       % than the end of the current
	       res := curr . res;
	       curr := lower
	    >> else
	       if pasf_leqp(cdr curr,cdr lower) then
		  % A new limit must be set for the current
		  % interval
		  curr := (car curr . cdr lower);
      >>;
      return reverse (curr . res)
   end;

procedure pasf_atf2iv(atf);
   % Presburger arithmetic standard form atomic formula to interval.
   % [atf] is an atomic formula. Returns an interval.
   begin scalar elimnf,nom,den,floor,ceil;
      elimnf := pasf_elimnf(pasf_simplat1 atf,car rl_fvarl atf);
      nom := pasf_arg2r elimnf;
      den := pasf_leadc elimnf;
      floor := pasf_floor(nom,den);
      ceil := pasf_ceil(nom,den);
      if pasf_op elimnf eq 'equal then
	 % Check if the equality solution is integer
	 if den eq 1 then
	    % Floor and ceil are the same
	    return iv_new(floor,floor)
	 else
	    return {};
      if pasf_op elimnf eq 'leq then
	 return iv_new('ninf,floor);
      if pasf_op elimnf eq 'lessp then
	 return iv_new('ninf,addf(ceil,negf 1));
      if pasf_op elimnf eq 'geq then
	 return iv_new(ceil,'pinf);
      if pasf_op elimnf eq 'greaterp then
	 return iv_new(addf(floor,1),'pinf);
      if pasf_op elimnf eq 'neq then
	 return iv_merge(iv_new('ninf,addf(ceil,negf 1)),
	    iv_new(addf(floor,1),'pinf));
      if pasf_opn elimnf memq '(cong ncong) then
	 % Check if the equality solution is integer
	 if den eq 1 then
	    % Floor and ceil are the same
	    return iv_newcong(pasf_op elimnf,floor)
	 else
	    return {};
     rederr{"pasf_atf2iv: illegal operator ",pasf_op atf}
   end;

procedure pasf_qff2ivl(f);
   % Presburger arithmetic standard form positive quantifier free
   % formula to interval. [f] is a quantifier free formula. Returns an
   % interval.   
   pasf_qff2ivl1 rl_dnf f;
      
procedure pasf_qff2ivl1(f);
   % Presburger arithmetic standard form positive quantifier free
   % formula to interval subprocedure . [f] is a quantifier free
   % formula. Returns an interval.
   begin scalar fs,cng;
      if rl_tvalp f then
	 % True or false
	 if f eq 'true then
	    rederr{"pasf_qff2ivl1 : true as a bound is invalid"}
	 else
	    return nil;
      if rl_op f eq 'and then <<
      	 % Using the fact the formula is in DNF. Than an AND is the end
      	 % node of the formula's evaluation tree.
      	 for each pf in rl_argn f do
	    % Only atomic formulas
	    if pasf_cong pf then
	       cng := append(pasf_atf2iv pf,cng)
	    else
	       fs := (pasf_atf2iv pf) . fs;
	 return iv_cutcongs(iv_cutn fs,cng)
      >> else
      	 if rl_op f eq 'or then
      	    return iv_mergen for each pf in rl_argn f collect
	       pasf_qff2ivl1 pf;
      % This case can only occur if one of the DNF conjunctions
      % contains only one atomic formula ( e.g. x = 0 or x = 10). This
      % leads to a correct expansion only if this atomic formula is an
      % equality and represent so a finit set. In other cases the
      % original input formula has already represented an infinit set
      % and was illegal for expansion.
      if pasf_opn f eq 'equal then return pasf_atf2iv f;
      % Something is wrong (mainly an error in DNF computation or
      % a formula with infinit satisfiability set in input)
      rederr{"pasf_qff2ivl1 : infinit bound in input",f}
   end;

procedure pasf_ivl2qff(ivl,var);
   % Presburger arithmetic standard form interval list to quantifier
   % free formula. [ivl] is an interval list; [var] is a free
   % variable. Returns a quantifier free formula with [var] as single
   % free valiable with [ivl] as satisfaction interval.
   if not iv_empty ivl then
      rl_smkn('or,for each iv in ivl collect
      	 pasf_mkrng(var,numr simp car iv,numr simp cdr iv))
   else
      'false;

procedure pasf_bsatp(f,var);
   % Presburger arithmetic standard form bound satisfiability.  [f] is
   % a bound; [var] is the bound variable. Returns nil iff the bound
   % is not satifiable.
   pasf_qff2ivl f;
%   begin scalar atl;
%      atl := rl_atl f;
%      return pasf_qff2ivl(f,var);  	
%   end;

procedure pasf_bsatp1(f,var,atf);
   % Presburger arithmetic standard form bound satisfiability
   % subroutine. [f] is a bount; [var] is the bound variable; [atf] is
   % an atomic formula contained in f. Returns 't iff the limits of
   % the interval defined by the formula satisfies f.
   nil;
	 
procedure pasf_ivl2atl(ivl,k);
   % Bound to list of atoms. [ivl] is a list of ascending intervals,
   % [k] is an ID. Returns a list of atoms such the conjunction
   % thereof is equivalent to the bound.
   begin scalar atl,r1;
      if null ivl then return nil;
      if null cdr ivl and caar ivl = cdar ivl then
	 return {pasf_0mk2('equal,addf(numr simp k,negf numr simp caar ivl))};
      atl := pasf_0mk2('geq,addf(numr simp k,negf numr simp caar ivl)) . atl;
      r1 := cdar ivl;
      ivl := cdr ivl;
      while ivl do <<
	 for i := r1+1 : (caar ivl)-1 do
	    atl := pasf_0mk2('neq,addf(numr simp k,negf numr simp i)) . atl;
	 r1 := cdar ivl;
	 ivl := cdr ivl
      >>;
      atl := pasf_0mk2('leq,addf(numr simp k,negf numr simp r1)) . atl;
      return atl
   end;

procedure pasf_b2atl(b,k); % could become cl function with bb qff2atl
   % Bound to list of atoms.
   if cl_atfp b then
      {b}
%   else if rl_op b eq 'and then
%      rl_argn b
   else if rl_tvalp b then
      (if b eq 'false then {} else rederr "pasf_b2atl: infinite bound")
   else
      pasf_ivl2atl(pasf_qff2ivl b,k);

procedure pasf_simplb(f,var);
   % Presburger arithmetic standard form simplify formulas' bound.
   % [f] is a bound of some bounded formula (a quantifier free formula
   % in one variable having a finite satisfiability set); [var] is the
   % bounded variable. Returns an f-equivalent simplified formula
   % (flat simlified DNF of f).
   pasf_ivl2qff(pasf_qff2ivl f,var);

procedure pasf_b2terml(b,var);
   % Presburger arithmetic standard form bound to termist.
   % [b] is a bound of some bounded formula (a quantifier free formula
   % in one variable having a finite satisfiability set); [var] is the
   % bounded variable. Returns the satisfiability set as a list
   % of satisfying terms (e.g. {1,2,3,10}).
   begin scalar ivl;
      ivl := pasf_qff2ivl b;
      return for each iv in ivl join
	 if (numberp car iv) and (numberp cdr iv) then
	    for i := car iv : cdr iv collect
	       i
     	 else
	    rederr{"pasf_b2terml : trying to expand infinit bound"}
   end;

procedure pasf_ordatp(a1,a2);
   % Presburger arithmetic standard form atomic formula
   % predicate. [a1] and [a2] are atomic formulas. Returns [t] iff
   % [a1] is less than [a2].
   begin scalar lhs1,lhs2;
      lhs1 := pasf_arg2l a1;
      lhs2 := pasf_arg2l a2;
      if lhs1 neq lhs2 then return ordp(lhs1,lhs2);
      return pasf_ordrelp(pasf_opn a1,pasf_opn a2)
   end;

procedure pasf_ordrelp(r1,r2);
   % Presburger arithmetic standard form relation order predicate.
   % [r1] and [r2] are pasf-relations. Returns a [T] iff $[r1] <
   % [r2]$.
   not not (r2 memq (r1 memq '(equal neq
      leq lessp geq greaterp cong ncong)));

procedure pasf_leqp(c1,c2);
   % Presburger arithmetic less or equal predicate on constant
   % expressions $\mathbb{Z} \cup \{ \infty,-\infty \}$. [c1] and [c2]
   % are two constant expressions. Returns [T] if [c1] is less or
   % equal than [c2].
   if (c1 eq 'ninf) or (c2 eq 'pinf) or
      (c1 neq 'pinf and c2 neq 'pinf and c2 neq 'ninf and c1 <= c2) then
	 t;

procedure pasf_leq(c1,c2);
   % Presburger arithmetic less predicate on constant expressions
   % $\mathbb{Z} \cup \{ \infty,-\infty \}$. [c1] and [c2] are two
   % constant expressions. Returns [T] if [c1] is less than [c2].
   if (c1 eq 'ninf) or (c2 eq 'pinf) or
      (c1 neq 'pinf and c2 neq 'pinf and c2 neq 'ninf and c1 < c2) then
	 t;

procedure pasf_varlat(atform);
   % Presburger arithmetic standard form atomic formula list of
   % variables.  [atform] is an atomic formula. Returns the variables
   % contained in [atform] as a list.
   kernels pasf_arg2l atform;

procedure pasf_varsubstat(atf,new,old);
   % Presburger arithmetic standard form substitute variable for
   % variable in atomic formula. [atf] is an atomic formula; [new] and
   % [old] are variables. Returns an atomic formula equivalent to
   % [atf] where [old] is substituted with [new].
   pasf_0mk2(pasf_op atf,numr subf(pasf_arg2l atf,{old . new}));

procedure pasf_negateat(atf);
   % Presburger arithmetic standard form negate atomic formula. [atf]
   % is an atomic formula. Returns an atomic formula equivalent to
   % $\lnot [atf]$.
   if (pasf_opn atf) memq '(cong ncong) then
      pasf_mkn(pasf_mkop(pasf_lnegrel pasf_opn atf,pasf_m atf),
	 pasf_argn atf)
   else
      pasf_mkn(pasf_lnegrel pasf_opn atf,pasf_argn atf);

procedure pasf_lnegrel(r);
   % Presburger arithmetic standard form logically negate
   % relation. [r] is a relation. Returns a relation $R$ such that for
   % terms $t_1$, $t_2$ we have $R(t_1,t_2)$ equivalent to $\lnot
   % [r](t_1,t_2)$.
   if r eq 'equal then 'neq
   else if r eq 'neq then 'equal
   else if r eq 'leq then 'greaterp
   else if r eq 'lessp then 'geq
   else if r eq 'geq then 'lessp
   else if r eq 'greaterp then 'leq
   else if r eq 'cong then 'ncong
   else if r eq 'ncong then 'cong
   else rederr {"pasf_lnegrel: unknown operator",r};

procedure pasf_anegateat(atf);
   % Presburger arithmetic standard form negate atomic formula
   % algebraically. [atf] is an atomic formula. Returns an atomic
   % formula equivalent to $-[atf]$.
   if (pasf_opn atf) memq '(cong ncong) then
      pasf_mk2(pasf_mkop(pasf_anegrel pasf_opn atf,pasf_m atf),
	 negf pasf_arg2l atf,negf pasf_arg2r atf)
   else
      pasf_mk2(pasf_anegrel pasf_opn atf,
	 negf pasf_arg2l atf,negf pasf_arg2r atf);

procedure pasf_anegrel(r);
   % Presburger arithmetic standard form algebraically negate
   % relation. [r] is a relation. Returns a relation $R$ such that
   % $R(-t,0)$ is equivalent to $[r](t,0)$ for a term $t$.
   cdr atsoc(r,'((equal . equal) (neq . neq) (leq . geq) (geq . leq)
      (lessp . greaterp) (greaterp . lessp) (cong . cong) (ncong . ncong)))
	 or rederr {"pasf_anegrel: unknown operator ",r};

procedure pasf_subat(al,f);
   begin scalar nlhs;
      nlhs := subf(pasf_arg2l f,al);
      if not domainp denr nlhs then
	 rederr "pasf_subat: parametric denominator after substitution";
      return pasf_0mk2(pasf_op f,numr nlhs)
   end;

procedure pasf_subalchk(al);
   for each x in al do
      if not domainp denr simp cdr x then
	 rederr "pasf_subalchk: parametric denominator in substituted term";

procedure pasf_eqnrhskernels(x);
   nconc(kernels numr w,kernels denr w) where w=simp cdr x;

procedure pasf_floor(nom,den);
   % Presburer arithmetic standard form floor of two domain valued
   % standard forms. [nom] is the nominator SF, [den] is the
   % denominator SF. Returns the floor of [nom]/[den].
   if domainp nom and domainp den then
      if null nom then
	 nil
      else
      	 if remainder(nom,den) = 0 then
      	    if nom / den = 0 then nil else nom / den
	 else
	    % The value is not negative
	    if nom*den > 0 then
	       	  nom / den
	    else
	       nom / den - 1
   else
      rederr{"pasf_floor: not a domain valued sf as input"};

procedure pasf_ceil(nom,den);
   % Presburer arithmetic standard form ceil of two domain valued
   % standard forms. [nom] is the nominator SF, [den] is the
   % denominator SF. Returns the ceil of [nom]/[den].
   if domainp nom and domainp den then
      if null nom then
	 nil
      else
      	 if remainder(nom,den) = 0 then
      	    if nom / den = 0 then nil else nom / den
	 else
	    % The value is not negative
	    if nom*den > 0 then
	       nom / den + 1
	    else
	       nom / den
   else
      rederr{"pasf_floor: not a domain valued sf as input"};

procedure pasf_content(ex);
   % Presburger arithmetic standard form content. [ex] is a linear
   % expression. Returns the common divisor of all coefficients.
   if domainp ex then
      abs ex
   else
      !:gcd(abs lc ex,pasf_content red ex);

procedure pasf_const(ex);
   % Presburger arithmetic standard form constant part of an expresion
   % computation. [expr] is an expression. Returns the constant part
   % of [expr].
   if domainp ex then
      ex
   else
      pasf_const red ex;

procedure pasf_termmlat(at);
   % Presburger arithmetic standard form term multiplicity list of
   % atomic formula. [at] is an atomic formula. Returns the
   % multiplicity list off all non-zero terms in [at].
   if pasf_arg2l pasf_rednf at then
      {(pasf_arg2l pasf_rednf at . 1)};

endmodule;  % pasfmisc

end;  % of file
