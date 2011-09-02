% ----------------------------------------------------------------------
% $Id: pasfqe.red,v 1.57 2004/02/22 21:08:15 lasaruk Exp $
% ----------------------------------------------------------------------
% Copyright (c) 2001 A. Dolzmann, A. Seidl, and T. Sturm
% ----------------------------------------------------------------------
% $Log: pasfqe.red,v $
% Revision 1.57  2004/02/22 21:08:15  lasaruk
% Added switch rlsusisubst for substitution of equalities. Substitution
% results in smaller formulas or formulas with less free variables.
% Up to 80% length reduction. Switch rlsusitr should not be used yet.
%
% Revision 1.56  2003/12/16 07:45:34  lasaruk
% Redlog normal form in the simplifier.
%
% Revision 1.55  2003/12/11 10:51:19  lasaruk
% Smart simplification improoved.
%
% Revision 1.54  2003/12/02 15:27:13  sturm
% Introduced ioto_nterpri to avoid ugly linebreaks in verbosity output.
%
% Revision 1.53  2003/12/02 15:00:57  sturm
% Removed a call to cl_simpl in pasf_qeex (superfluous checking for truth
% values).
% Do a more general check on variable not occurring.
%
% Revision 1.52  2003/12/02 14:37:07  sturm
% Rewritten pasf_qeexblock and added canonical verbose output.
%
% Revision 1.51  2003/11/05 13:27:14  lasaruk
% Some major redlog programming rules applied to the code.
% Formulas are made positive acc. to the current kernel order.
%
% Revision 1.50  2003/10/28 10:02:03  dolzmann
% Added correct content of fluids pasf_siat_rcsid!* and
% pasf_siat_copyright!*.
%
% Revision 1.49  2003/10/16 16:17:38  lasaruk
% Compiler error messages partially removed. All others are due
% to the noncompleteness of packet.
%
% Revision 1.48  2003/10/12 15:18:11  sturm
% pasf_qe requires second (theo, dummy for now) argument. This became visible
% under CSL.
%
% Revision 1.47  2003/08/28 15:30:40  lasaruk
% Simplification verbose output done better. QE-Bug with truth values
% corrected (will be done more effitient). Some fancy examples added.
%
% Revision 1.46  2003/07/16 12:58:50  lasaruk
% Error in QE removed.
%
% Revision 1.45  2003/07/16 12:51:35  lasaruk
% Tipp error.
%
% Revision 1.44  2003/07/16 12:48:33  lasaruk
% See message below.
%
% Revision 1.43  2003/07/15 12:40:41  seidl
% Renamed pasf_iv2qff to pasf_ivl2qff and pasf_qff2iv to pasf_qff2ivl.
% Provided algebraic mode access to simplb, ivl2qff, qdd2ivl. Changed
% pasf_mkrng so intervals with same upper and lower bound result in an
% equation. Fixed serious bug in pasf_prepat. Added cvs header to
% pasf.tst. Todo Lasaruk: pasf_ivl2qff crashes with empty interval as
% argument, see testfile.
%
% Revision 1.42  2003/06/04 12:33:40  lasaruk
% Some smaller modifications.
%
% Revision 1.41  2003/05/28 20:37:51  lasaruk
% Expansion done better.
%
% Revision 1.40  2003/05/26 20:50:57  lasaruk
% Range expansion with congruences
%
% Revision 1.39  2003/05/22 22:00:58  lasaruk
% DNF added.
%
% Revision 1.38  2003/05/17 17:04:16  lasaruk
% bugs removed
%
% Revision 1.37  2003/05/17 16:27:56  lasaruk
% Pasf simplification added. Some errors corrected.
%
% Revision 1.36  2003/05/15 23:34:47  lasaruk
% Interval expansion added
%
% Revision 1.35  2003/04/20 12:04:04  lasaruk
% Completely removed any reference to range predicates (in input
% also). PNF made shorter.
%
% Revision 1.34  2003/04/14 10:11:39  lasaruk
% Changes to work with bounded quantifieres added . Simplification bug
% (content) removed. Range predicates removed.
%
% Revision 1.33  2003/03/26 11:19:23  lasaruk
% Formula runthrough rewritten as cl_atnum. True/false in rlexpabnd bug
% removed. Some services added.
%
% Revision 1.32  2003/03/04 09:33:23  lasaruk
% Advanced simplification. PNF code attached but not used yet. Some code
% migration. Documentation debugged.
%
% Revision 1.31  2003/02/24 19:50:19  lasaruk
% Congruences without x removed.
%
% Revision 1.30  2003/02/18 12:45:03  lasaruk
% Better code for some methods.
%
% Revision 1.29  2003/02/17 14:44:55  lasaruk
% Debug messages removed.
%
% Revision 1.28  2003/02/17 10:55:40  lasaruk
% Stable full featured version
%
% Revision 1.27  2003/02/03 13:41:04  lasaruk
% Experimental version with full functionality. A bit buggy.
%
% Revision 1.26  2003/02/02 17:33:44  lasaruk
% Internal representation of data is converted completely into SF's
% except the representation of moduli.
%
% Revision 1.25  2003/02/01 08:42:50  lasaruk
% Stack container implemented.
%
% Revision 1.24  2003/02/01 07:38:33  lasaruk
% Recursive range expansion.
%
% Revision 1.23  2003/01/31 14:25:06  lasaruk
% Bug fixed.
%
% Revision 1.22  2003/01/31 14:18:48  lasaruk
% Found better method for impoding.
%
% Revision 1.21  2003/01/31 14:09:58  lasaruk
% New variable method added. K is no loger fixed, but a new variable.
%
% Revision 1.20  2003/01/29 16:07:46  lasaruk
% Better limits.
%
% Revision 1.19  2003/01/29 15:24:47  sturm
% Added service rlexpand for context pasf. Had to split pasf_exprng for this.
%
% Revision 1.18  2003/01/27 17:40:02  lasaruk
% Switches renamed. Bugs in docu fixed.
%
% Revision 1.17  2003/01/26 18:31:49  lasaruk
% Simplification position altered.
%
% Revision 1.16  2003/01/26 17:49:37  lasaruk
% Null congruence error added. Terms without quant. varl. stay
% untouched. Bugs fixed.
%
% Revision 1.15  2003/01/21 17:39:14  lasaruk
% Switch rlsiatadv turned off. Bugs fixed.
%
% Revision 1.14  2003/01/21 10:44:14  lasaruk
% Congruence substitution added. Bugs fixed.
%
% Revision 1.13  2003/01/20 10:36:51  lasaruk
% First trial to work with congruences. Bugs fixed.
%
% Revision 1.12  2003/01/06 18:20:32  lasaruk
% Bugs fixed
%
% Revision 1.11  2003/01/06 17:33:27  lasaruk
% Some simplifier bugs fixed. Alternating quantifier elimination attached.
%
% Revision 1.10  2003/01/05 15:55:05  lasaruk
% Simplification improoved. Expansion of range predicates added.
%
% Revision 1.9  2002/12/31 13:57:49  lasaruk
% Simplifier bugs fixed.
%
% Revision 1.8  2002/12/31 13:33:34  lasaruk
% Standard simplifier attached. Standard simplification of expressions
% attached.
%
% Revision 1.7  2002/12/23 07:41:19  lasaruk
% Simplifier turned off temporary
%
% Revision 1.6  2002/12/23 07:07:05  lasaruk
% Elimination code completely rewritten
%
% Revision 1.5  2002/12/10 08:49:41  lasaruk
% Correct elimination of an exist. quantifier call added.
% Procedures debugged.
%
% Revision 1.3  2002/12/02 12:53:37  lasaruk
% Elimination of one variable in front of an ex quantifier. Not really
% worth looking at.
%
% Revision 1.2  2002/11/15 12:00:48  seidl
% Head added.
%
% ----------------------------------------------------------------------
lisp <<
   fluid '(pasf_qe_rcsid!* pasf_qe_copyright!*);
   pasf_qe_rcsid!* :=
      "$Id";
   pasf_qe_copyright!* :=
      "Copyright (c) 2003 A. Dolzmann, A. Seidl, and T. Sturm"
>>;

module pasfqe;
% Presburger arithmetic standard form quantifier
% elimination. Submodule of [pasf].

procedure elimdata_new(repr,n,m,min_si,max_si,ats);
   % Elimination data constructor. [repr] is a list of canonical
   % representants, [n] is the lcm of all leading coeficients of the
   % left hand side of the elimination normal form, [m] is the lcm of
   % all moduli, [min_si] and [max_si] are the minimal constant values
   % among all atomic formulas and [ats] is the list of (atf_j,min_sj,
   % max_sj) where [atf] is an atomic formula containing the
   % quantified variable and [min_si] and [max_si] are the minimal and
   % maximal constant value of atf's right hand side. Returns the
   % elimination data in the elimdata datastructure format.
   {repr,n,m,min_si,max_si,ats};

procedure elimdata_repr(elimdata);
   % Elimination data canonical representants accessor. [elimdata] is
   % the elimination data. Returns the canonical representants.
   car elimdata;

procedure elimdata_n(elimdata);
   % Elimination data n accessor. [elimdata] is the elimination
   % data. Returns n.
   cadr elimdata;

procedure elimdata_m(elimdata);
   % Elimination data m accessor. [elimdata] is the elimination
   % data. Returns m.
   caddr elimdata;

procedure elimdata_min_si(elimdata);
   % Elimination data min_si accessor. [elimdata] is the elimination
   % data. Returns min_si.
   cadddr elimdata;

procedure elimdata_max_si(elimdata);
   % Elimination data max_si accessor. [elimdata] is the elimination
   % data. Returns max_si.
   car cddddr elimdata;

procedure elimdata_ats(elimdata);
   % Elimination data atomic formula list accessor. [elimdata] is the
   % elimination data. Returns the atomic formula list.
   cadr cddddr elimdata;

procedure elimdata_join(elimdatalst);
   % Elimination data join a list of elimination data information.
   % [elimdatalst] is a list of elimdata. Returns the common
   % elimination information of all list elements.
   begin scalar rep,n,m,min_si,max_si;
      rep :={};
      n := 1;
      m := 1;
      min_si := nil;
      max_si := nil;
      if elimdatalst then <<
	 max_si := elimdata_max_si car elimdatalst;
	 min_si := elimdata_min_si car elimdatalst;
      	 for each elimdata in elimdatalst do <<
	    % Just joning the list of canonic representants
	    rep := append(rep,elimdata_repr elimdata);
	    % LCM of all n,m
	    n := *lcm(n,elimdata_n elimdata);
	    m := *lcm(m,elimdata_m elimdata);
	    % max_si and min_si computation
	    if minusf addf(max_si,negf elimdata_max_si elimdata) then
	       max_si := elimdata_min_si elimdata;
	    if minusf addf(min_si,negf elimdata_min_si elimdata) then
	       min_si := elimdata_max_si elimdata
      	 >>
      >>;
      return elimdata_new(rep,n,m,min_si,max_si,nil)
   end;

procedure pasf_qe(phi,theo);
   % Presburger arithmetic standard form compute a quantifier free
   % formula equivalent to psi. [psi] is a formula. Returns a
   % quantifier free formula equivalent to $\psi()$.
   begin scalar split,rslt,phi_prime;
      if !*rlverbose then
	 ioto_tprin2 "++++ Entering pasf_qe";
      phi_prime := rl_pnf phi;
      split := cl_splt phi_prime;
      % Performing DNF on the matrix
      rslt := rl_dnf cadr split;
      for each block in car split do
	 rslt := pasf_qeblock(car block,cdr block,rslt);
      return if !*rlpasfsimplify then
	 cl_simpl(rslt,nil,-1)
      else
	 rslt;
   end;

procedure pasf_qeblock(omega,varl,psi);
   % Presburger erithmetic standrd form eliminate a block of
   % quantifiers. [omega] if the quantifier type, varl is a list of
   % the block bounded variables and [psi] is the matrix of the
   % formula.
   begin integer dpth,vlv;
      if !*rlverbose then <<
	 ioto_tprin2 {"---- ",omega . reverse varl};
	 dpth := length varl;
      	 if !*rlqedfs then <<  % should not happen by now
	    vlv :=  dpth / 4;
	    ioto_prin2t {" [DFS: depth ",dpth,", watching ",dpth - vlv,"]"}
      	 >> else
	    ioto_prin2t {" [BFS: depth ",dpth,"]"}
      >>;
      if omega eq 'ex then
      	 return pasf_qeexblock(varl,psi,dpth,vlv);
      % [op eq 'all]
      return cl_nnfnot pasf_qeexblock(varl,cl_nnfnot psi,dpth,vlv)
   end;

procedure pasf_qeexblock(varl,psi,dpth,vlv);
   % Presburger erithmetic standrd form eliminate a block of
   % existential quantifiers. [varl] are the bounded variables, [psi]
   % is the matrix of the formula. Returns a quantifier free formula
   % equivalent to $\exists varl \psi()$.
   begin scalar co,cvl,w,coe,f,newj,v; integer c,delc,oldcol,count;
      cvl := varl;
      if rl_op psi eq 'or then
	 for each x in rl_argn psi do
	    co := cl_save(co,{cl_mkcoel(cvl,x,nil,nil)})
      else
      	 co := cl_save(co,{cl_mkcoel(cvl,psi,nil,nil)});
      while co do <<
	 w := cl_get co;
	 co := cdr w;
	 coe := car w;
    	 cvl := cl_covl coe;
	 f := cl_cof coe;
	 count := count + 1;
	 if !*rlverbose then
	    if !*rlqedfs then <<
	       if vlv = length cvl then
	       	  ioto_tprin2t {"-- crossing: ",dpth - vlv};
	       ioto_prin2 {"[",dpth - length cvl}
	    >> else <<
	       if c=0 then <<
	       	  ioto_tprin2t {"-- left: ",length cvl};
		  c := cl_colength co + 1
	       >>;
	       ioto_nterpri(length explode c + 4);
	       ioto_prin2 {"[",c};
	       c := c - 1
	    >>;
	 v := car cvl;
	 cvl := cdr cvl;
	 f := pasf_qeex(f,v);
	 if !*rlpasfsimplify then
	    f := cl_simpl(f,nil,-1);
	 if f eq 'true then <<
	    co := nil;
	    newj := '(true)
	 >> else if null cvl then
	    newj := adjoin(f,newj)
	 else
	    if rl_op f eq 'or then <<
	       if !*rlverbose then oldcol := cl_colength co;
	       for each x in rl_argn f do
	       	  co := cl_save(co,{cl_mkcoel(cvl,x,nil,nil)});
	       if !*rlverbose then
	       	  delc := delc + oldcol + length rl_argn f - cl_colength co
      	    >> else <<
	       if !*rlverbose then oldcol := cl_colength(co);
      	       co := cl_save(co,{cl_mkcoel(cvl,f,nil,nil)});
	       if !*rlverbose then
	       	  delc := delc + oldcol + 1 - cl_colength(co)
	    >>;
	 if !*rlverbose then <<
	    ioto_prin2 "] ";
	    if !*rlqedfs and null cvl then ioto_prin2 ". "
	 >>
      >>;
      if !*rlverbose then ioto_prin2{"[DEL:",delc,"/",count,"]"};
      return rl_smkn('or,newj)
   end;

procedure pasf_qeex(psi,x);
   % Presburger arithmetic standard form eliminate an existential
   % quantifier in front of a quantifier free formula. [psi] is a
   % formula, [x] is the quantified variable. Returns a quantifier
   % free formula equivalent to $\exists x \psi()$.
   begin scalar simpl,normpsi,elimdata;
      % Debug output
      if pasf_verbosep() then <<
	 prin2 "Eliminating subformula: ";
	 print psi;
	 prin2 "Elimination variable: ";
	 print x
      >>;
      % Trivial case check
      %
      % /TODO bad solution
      if not (x memq cl_fvarl1 psi) then <<
	 if !*rlverbose then ioto_prin2 "*";
	 return psi
      >>;
      if !*rlverbose then ioto_prin2 "e";
      % Computing the elimination normal form
      normpsi := pasf_elimnf(psi,x);
      % Getting the elimination data of psi
      elimdata := pasf_canrep normpsi;
      % Computing the quantifier free equivalent
      simpl := pasf_rednf if null elimdata_repr elimdata then
	 pasf_substfc(normpsi,elimdata)
      else
      	 pasf_substf(normpsi,elimdata);
      return simpl
   end;

procedure pasf_canrep(f);
   % Presburger arithmetic standard form search for canonical
   % representants. [f] a formula in elimination normal form with only
   % range predicates. Returns the elimindation data structure
   % elimdata.
   elimdata_join pasf_canrep1(f,nil);

procedure pasf_canrep1(f,bvar);
   % Presburger arithmetic standard form search for canonical
   % representants subroutine. [f] a formula in elimination normal
   % form with only range predicates, [bvar] is the list of bounded
   % variables. Returns the elimindation data structure elimdata.
   if rl_quap rl_op f then
      % Formula should be pnf'ed first
      rederr{"pasf_canrep : Quantifier inside a formula matrix"}
   else
      if rl_bquap rl_op f then
      % Removing bounded quantifiers and adding new bounded
      % variable to the variable list.
      pasf_canrep1(rl_mat f,(rl_var f) . bvar)
   else
      if rl_boolp rl_op f then
	 for each subf in rl_argn f join
	    pasf_canrep1(subf,bvar)
      else
	 % We are now sure to have no nested range predicates
      	 {pasf_compeld(f,bvar)};

procedure pasf_compeld(atf,bvar);
   % Presburger arithmetic standard form compute elimination
   % data. [atf] is an atomic formula, [bvar] is the list of bounded
   % variables by range predicates. Returns the elimination data.
   begin scalar op,n,m,max_s,min_s,repr,a_i;
      % Avoiding formulas with no quantified variable inside
      if null pasf_leadc atf then
	 return elimdata_new(nil,1,1,nil,nil,nil);
      % Getting the operator
      op := pasf_opn atf;
      n := 1;
      m := 1;
      max_s := nil;
      min_s := nil;
      repr := nil;
      if op memq '(cong ncong) then
	 m := lcm(m,pasf_m atf)
      else if op memq '(equal neq leq geq lessp greaterp) then <<
	 n := lcm(n,pasf_leadc atf);
	 a_i := pasf_arg2r atf;
	 % Substituting k's into a_i
	 for each var in bvar do
	    a_i := numr subf(a_i,{(var . nil)});
	 % Debug output
	 if pasf_verbosep() then <<
	    prin2 "s_i = ";
	    print pasf_const a_i
	 >>;
	 max_s := pasf_const a_i;
	 min_s := pasf_const a_i;
	 repr := {pasf_mk2(pasf_op atf,pasf_arg2l atf,a_i)}
      >>;
      % Debug output
      if pasf_verbosep() then <<
	 prin2 "lcm(n_i) = ";
	 print n;
	 prin2 "lcm(m_i) = ";
	 print m;
	 prin2 "max_s = ";
	 print max_s;
	 prin2 "min_s = ";
	 print min_s
      >>;
      return elimdata_new(repr,n,m,max_s,min_s,nil)
   end;

procedure pasf_consteln(atf);
   % Presburger arithmetic standard form constant part of an atomic
   % formula in elimination normal form. [atf] is an atomic formula in
   % elimination normal form. Returns the constant part of [atf].
   pasf_const pasf_arg2r atf;

procedure pasf_substfc(psi,elimdata);
   % Presburger arithmetic standard form subsitute formula with only
   % congruences. [psi] is the formula in elimination normal form,
   % [elimdata] is the elimiation data. Returns a quantifier free
   % formula equivalent to $ex(x,psi)$.
   begin scalar m;
      m := addf(elimdata_m elimdata,negf 1);
      % Debug output
      if pasf_verbosep() then <<
	 prin2 "m = ";
	 print m
      >>;
      return pasf_exprng pasf_substfc1(m,psi)
   end;

procedure pasf_substfc1(m,psi);
   % Presburger arithmetic standard form subsitute formula with only
   % congruences subprocedure. [m] is the upper range for the range
   % predicate (SF), [psi] is the formula in elimination normal
   % form. Returns a range predicate bounded formula.
   begin scalar subs,rng,k;
      k := pasf_newvar psi;
      % Debug output
      if pasf_verbosep() then <<
	 prin2 "Creating new variable ";
	 print k;
	 prin2 "m = ";
	 print m
      >>;
      subs := cl_apply2ats1(psi,'pasf_substf2,{k,1,nil});
      rng := pasf_mkrng(k,0,if m then m else 0);
      if m then
      	 return rl_mkbq('bex,k,rng,rl_mkn('and,{subs}))
      else
	 return subs
   end;

procedure pasf_substf(psi,elimdata);
   % Presburger arithmetic standard form subsitute formula. [psi] is
   % the formula in elimination normal form and [elimdata] is the
   % elimination data. Returns a quantifier free formula equivalent to
   % $ex(x,psi)$.
   begin scalar n_prime,s,m;
      s := pasf_ceil(addf(elimdata_min_si elimdata,
	 negf elimdata_min_si elimdata),2);
      % Debug output
      if pasf_verbosep() then <<
	 prin2 "s = ";
	 print s
      >>;
      n_prime := elimdata_n elimdata;
      % Debug output
      if pasf_verbosep() then <<
 	 prin2 "n' = ";
	 print n_prime
      >>;
      m := elimdata_m elimdata;
      % Debug output
      if pasf_verbosep() then <<
	 prin2 "m = ";
	 print m
      >>;
      % For each canonical representant in psi
      return pasf_rednf rl_mkn('or,
	 for each atf in elimdata_repr elimdata collect
	    pasf_exprng
	       if null pasf_arg2l atf then
	       	  pasf_substf1(0,psi,atf)
	       else
	       	  pasf_substf1(multf(pasf_leadc atf,
		     addf(s,*lcm(n_prime,m))),psi,atf));
   end;

procedure pasf_substf1(t_j,psi,atf);
   % Presburger arithmetic standard form subsitute formula
   % subprocedure. [t_j] is the range for the range predicate, [psi]
   % is the formula in elimination normal form and [atf] is of one of
   % the canonical representants of [psi]. Returns a bounded formula.
   begin scalar cong,subs,rng,leadc,k;
      k := pasf_newvar psi;
      % Debug output
      if pasf_verbosep() then <<
	 prin2 "Creating new variable ";
	 print k
      >>;
      % Debug output
      if pasf_verbosep() then <<
	 prin2 "t_j = ";
	 print t_j
      >>;
      leadc := pasf_leadc atf;
      cong := pasf_mk2(pasf_mkop('cong,leadc),
	 addf(pasf_arg2r atf,numr simp k),nil);
      subs := cl_apply2ats1(psi,'pasf_substf2,
	 {k,leadc,pasf_arg2r atf});
      if null t_j then
	 rederr{"pasf_substf1 : t_j is 0"}
      else
 	 rng := pasf_mkrng(k,-t_j,t_j);
      return rl_mkbq('bex,k,rng,rl_mkn('and,subs . {cong}))
    end;

procedure pasf_substf2(atf,k,n_j,a_j);
   % Presburger arithmetic standard form subsitute formula
   % subprocedure. [psi] is an atomic formula in elimination normal
   % form, [k] is the range variable, [n_j] and [a_j] are the
   % substitution parameters. Returns the substituted atomic formula.
   begin scalar n_i,a_i;
      n_i := pasf_leadc atf;
      % Returning unchanged formula if no quantified variable in the
      % formula.
      if null n_i then return atf;
      a_i := pasf_arg2r atf;
      return if pasf_opn(atf) memq '(cong ncong) then
      	 pasf_mk2(pasf_mkop(pasf_opn atf,multf(pasf_m atf,n_j)),
	    addf(multf(n_i,a_j),multf(n_i,numr simp k)),
	    multf(n_j,a_i))
      else
	 pasf_mk2(pasf_mkop(pasf_opn atf,0),
	    addf(multf(n_i,a_j),multf(n_i,numr simp k)),
	    multf(n_j,a_i));
   end;

procedure pasf_leadc(atf);
   % Presburger arithmetic standard form leading coeficient of a
   % elimination normal form. [atf] is an atomic formula in
   % elimination normal form. Returns the leading coeficient.
   if domainp pasf_arg2l atf then
      % /FIXME Warning, could be a trap, because only nil possible
      pasf_arg2l atf
   else
      lc pasf_arg2l atf;

procedure pasf_expand(f);
   % Presburger arithmetic standard form expand a formula with range
   % predicates. [f] is a formula with range predicates. Returns an
   % equivalent formula without range predicates.
   cl_simpl(pasf_exprng1 f,nil,-1);

procedure pasf_exprng(f);
   % Presburger arithmetic standard form expand range predicate. [f]
   % is a formula bounded by a range quantifier. Returns an equivalent
   % quantifier free formula.
   if !*rlpasfrangeexpand then
      % Redlog normal form needed here because this function is called
      % inside the QE process, where the formulas are not neccesary in
      % redlog normal form.
      pasf_expand pasf_rednf f
   else
      f;

procedure pasf_exprng1(f);
   % Presburger arithmetic standard form expand bounded
   % quantifier. [f] is a formula bounded only by bounded
   % quantifiers. Returns an equivalent quantifier free formula.
   if rl_bquap rl_op f then
      pasf_exprng2 rl_mkbq(rl_op f,rl_var f,rl_b f,
	 cl_simpl(pasf_exprng1 rl_mat f,nil,-1))
   else
      if rl_boolp rl_op f then
	 rl_mkn(rl_op f,for each subf in rl_argn f collect
	    cl_simpl(pasf_exprng1 subf,nil,-1))
      else
	 f;

procedure pasf_exprng2(f);
   % Presburger arithmetic standard form expand bounded
   % quantifier. [f] is a formula bounded only by one bounded
   % quantifier. Returns an equivalent quantifier free formula.
   begin scalar evaltype,terml;
      % Long or or long and check
      if rl_op f eq 'bex then
	 evaltype := 'or
      else if rl_op f eq 'ball then
	 evaltype := 'and
      else
	 % Unknown operator
	 rederr{"pasf_expand : unknown or illegal quantifier",rl_op f};
      % Building the interval to substitute into
      terml := pasf_b2terml(rl_b f,rl_var f);
      return rl_mkn(evaltype,
	 for each j in terml collect
	    pasf_subfof(rl_var f,j,rl_mat f));
   end;

procedure pasf_subfof(var,ex,f);
   % Presburger arithmetic standard form substitute into a formula.
   % [var] is the variable to substitute, [ex] is the expression to
   % substitute and [f] is the formula. Returns the formula where
   % every occurence of [var] is substituted by [ex].
   cl_apply2ats1(f,'pasf_subfof1,{var,ex});

procedure pasf_subfof1(atf,var,ex);
   % Presburger arithmetic standard form substitute into a formula
   % subroutinue. [atf] is an atomic formula, [var] is the variable to
   % substitute and [ex] is the expression to substitute. Returns an
   % atomic formula where every occurence of [var] is substituted by
   % [ex].
   pasf_mk2(pasf_op atf,
      numr subf(pasf_arg2l atf,{(var . ex)}),
      numr subf(pasf_arg2r atf,{(var . ex)}));

procedure pasf_newvar(f);
   % Presburger arithmetic standard form new variable generation. [f]
   % is a formula. Returns a new variable which is not present in [f].
   intern gensym();

procedure pasf_newvar1(f);
   % Presburger arithmetic standard form new variable generation. [f]
   % is a formula. Returns a new variable which is not present in [f].
   begin scalar varl,varv,expld,l;
      varl := cl_varl pasf_rednf f;
      varv := 0;
      % Checking only the whole varlist
      for each var in append(car varl,cdr varl) do <<
	 expld := explode var;
	 % Looking for k variables
	 if car expld eq 'k then <<
	    l := implode cdr expld;
	    if l >= varv then
	       varv := l+1
	 >>
      >>;
      return implode('k . explode(varv))
   end;

endmodule;

end;
