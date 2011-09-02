% ----------------------------------------------------------------------
% $Id: pasfnf.red,v 1.15 2003/11/05 13:27:14 lasaruk Exp $
% ----------------------------------------------------------------------
% Copyright (c) 2001 A. Dolzmann, A. Lasaruk, A. Seidl, and T. Sturm
% ----------------------------------------------------------------------
% $Log: pasfnf.red,v $
% Revision 1.15  2003/11/05 13:27:14  lasaruk
% Some major redlog programming rules applied to the code.
% Formulas are made positive acc. to the current kernel order.
%
% Revision 1.14  2003/07/16 13:50:47  lasaruk
% Debug messages removed. Bug in printing congurences removed.
% Testfile adjusted to changes (working cases).
%
% Revision 1.13  2003/07/14 12:37:58  lasaruk
% Common utilities attached and tested (see the testfile).
%
% Revision 1.12  2003/05/31 14:41:50  lasaruk
% PNF corrected. examples added.
%
% Revision 1.11  2003/04/20 12:04:04  lasaruk
% Completely removed any reference to range predicates (in input
% also). PNF made shorter.
%
% Revision 1.10  2003/04/14 10:11:39  lasaruk
% Changes to work with bounded quantifieres added . Simplification bug
% (content) removed. Range predicates removed.
%
% Revision 1.9  2003/03/26 11:19:23  lasaruk
% Formula runthrough rewritten as cl_atnum. True/false in rlexpabnd bug
% removed. Some services added.
%
% Revision 1.8  2003/03/16 22:31:45  lasaruk
% PNF-bug removed.
%
% Revision 1.7  2003/03/11 12:30:36  lasaruk
% Bug in normal form computation fixed.
%
% Revision 1.6  2003/03/11 00:41:29  lasaruk
% Prenex normal form with correct range predicate handling added. Documentation
% extended. Todo section added.
%
% Revision 1.5  2003/03/04 09:33:23  lasaruk
% Advanced simplification. PNF code attached but not used yet. Some code
% migration. Documentation debugged.
%
% Revision 1.4  2003/02/28 11:55:40  lasaruk
% Simplifier congruence bug removed. Switch siatadv now actively used.
%
% Revision 1.3  2003/02/18 16:02:12  seidl
% Header for CVS added.
%
% ----------------------------------------------------------------------

lisp <<
   fluid '(pasf_nf_rcsid!* pasf_nf_copyright!*);
   pasf_misc_rcsid!* := "$Id: pasfnf.red,v 1.15 2003/11/05 13:27:14 lasaruk Exp $";
   pasf_nf_copyright!* :=
      "Copyright (c) 1995-2002 by A. Dolzmann, A. Lasaruk, A. Seidl, and T. Sturm"
>>;

% Pasf normal forms. Submodule of pasf.
module pasfnf;

procedure pasf_rednf(f);
   % Presburger arithmetic standard form compute the redlog normal
   % form $a rel b \equiv a - b rel 0$ for each atomic formula in
   % [f]. [f] is a formula. Returns an [f] equivalent formula in
   % redlog normal form.
   cl_apply2ats1(f,'pasf_rednf1, nil);

procedure pasf_rednf1(atf);
   % Presburger arithmetic standard form compute the redlog normal
   % form $a rel b \equiv a - b rel 0$ for an atomic formula. [atf] is
   % a formula. Returns an [atf] equivalent atomic formula in redlog
   % normal form.
   pasf_mk2(pasf_op atf, addf(pasf_arg2l atf, negf pasf_arg2r atf), nil);

procedure pasf_elimnf(psi, x);
   % Presburger arithmetic standard form elimination normal
   % form. [psi] is a matrix of the original formula, [x] is a
   % quantified variable. Returns [psi] in elimination normal form for
   % the quantified variable.
   cl_apply2ats1(psi,'pasf_elimnf1, {x});

procedure pasf_elimnf1(atf, x);
   % Presburger arithmetic standard form elimination normal form
   % subprocedure. [atf] is an atomic formula. Returns [atf] in
   % elimination normal form according to the quantified variable.
   begin scalar op,ex,oldkorder,leadc,reduct,exr;
      op := pasf_op atf;
      ex := addf(pasf_arg2l(atf),negf pasf_arg2r(atf));
      if x memq kernels ex then <<
      	 oldkorder := setkorder {x};
      	 exr := reorder ex;
      	 leadc := lc exr;
      	 reduct := red exr;
      	 setkorder oldkorder;
      	 reorder ex;
	 if minusf leadc then
	    return pasf_anegateat pasf_mk2(op,multf(leadc,numr simp x),
	       negf reduct)
      	 else
	    return pasf_mk2(op,multf(leadc,numr simp x),negf reduct);
      >> else
	 return pasf_mk2(op,nil,negf ex);
   end;

procedure pasf_pnf(phi);
   % Presburger arithmetic standard form prenex normal form. [phi] is
   % a formula. Returns a prenex formula equivalent to [phi]. The
   % number of quantifier changes in the result is minimal among all
   % formulas that can be obtained from [phi] by moving quantifiers to
   % the outside.
   pasf_pnf1 rl_nnf phi;

procedure pasf_pnf1(phi);
   % Presburger arithmetic standard form prenex normal form
   % subroutine. [phi] is a positive formula that does not contain any
   % extended boolean operator.  Returns a prenex formula equivalent
   % to [phi]. The number of quantifier changes in the result is
   % minimal among all formulas that can be obtained from [phi] by
   % moving quantifiers to the outside.
   <<
      if null cdr erg or pasf_qb car erg < pasf_qb cadr erg then
 	 car erg
      else
 	 cadr erg
   >> where erg=pasf_pnf2(cl_rename!-vars phi);

procedure pasf_pnf2(phi);
   begin scalar op;
      op := rl_op phi;
      if rl_quap op then
 	 return pasf_pnf2!-quantifier(phi);
      if rl_junctp op or rl_bquap op then
 	 return pasf_pnf2!-junctor(phi);
      if rl_tvalp op then
 	 return {phi};
      if rl_cxp op then
 	 rederr{"pasf_pnf2():",op,"invalid as operator"};
      return {phi}
   end;

procedure pasf_pnf2!-quantifier(phi);
   <<
      if (null cdr e) or (rl_op phi eq rl_op car e) then
 	 {rl_mkq(rl_op phi,rl_var phi,car e)}
      else
 	 {rl_mkq(rl_op phi,rl_var phi,cadr e)}
   >> where e=pasf_pnf2 rl_mat phi;

procedure pasf_pnf2!-junctor(phi);
   begin scalar args,bv,bound,junctor,e,l1,l2,onlyex,onlyall,phi1,phi2;
      integer m,qb;
      junctor := rl_op phi;
      if rl_bquap junctor then <<
	 bv := rl_var phi;
	 bound := rl_b phi;
	 args := {rl_mat phi};
      >> else
	 args := rl_argn phi;
      e := for each f in args collect pasf_pnf2(f);
      onlyex := T; onlyall := T;
      for each ej in e do <<
    	 qb := pasf_qb car ej;
    	 if qb > m then <<
 	    m := qb; onlyex := T; onlyall := T
 	 >>;
    	 if cdr ej then <<
 	    l1 := (car ej) . l1;
 	    l2 := (cadr ej) . l2
 	 >> else <<
 	    l1 := (car ej) . l1;
 	    l2 := (car ej) . l2
 	 >>;
    	 if eqn(m,qb) then <<
      	    if rl_op car l1 eq 'all then onlyex := nil;
      	    if rl_op car l2 eq 'ex then onlyall := nil
    	 >>;
      >>;
      l1 := reversip l1;
      l2 := reversip l2;
      if eqn(m,0) then return {phi};
      if onlyex neq onlyall then
    	 if onlyex then
 	    return {pasf_interchange(l1,junctor,'ex,bv,bound)}
    	 else  % [onlyall]
 	    return {pasf_interchange(l2,junctor,'all,bv,bound)};
      phi1 := pasf_interchange(l1,junctor,'ex,bv,bound);
      phi2 := pasf_interchange(l2,junctor,'all,bv,bound);
      if car phi1 eq car phi2 then
 	 return {phi1}
      else
 	 return {phi1,phi2}
   end;

procedure pasf_qb(phi);
   begin scalar q,scan!-q; integer qb;
      while rl_quap(scan!-q := rl_op phi) do <<
    	 if scan!-q neq q then <<
      	    qb := qb + 1;
      	    q := scan!-q
    	 >>;
    	 phi := rl_mat phi
      >>;
      return qb
   end;

procedure pasf_interchange(l,junctor,a,bv,bound);
   begin scalar ql,b,result;
      while pasf_contains!-quantifier(l) do <<
    	 l := for each f in l collect <<
      	    while rl_op f eq a do <<
               b := (rl_var f) . b;
               f := rl_mat f
      	    >>;
      	    f
    	 >>;
    	 ql := b . ql;
    	 b := nil;
    	 a := cl_flip a
      >>;
      a := cl_flip a;
      result := if rl_bquap junctor then
	 % In case of a bounded quantifier the list of
	 % arguments of a matrix is of length 1
	 rl_mkbq(junctor,bv,bound,car l)
      else
	 rl_mkn(junctor,l);
      for each b in ql do <<
    	 for each v in b do result := rl_mkq(a,v,result);
    	 a := cl_flip a
      >>;
      return result
   end;

procedure pasf_contains!-quantifier(l);
   l and (rl_quap rl_op car l or pasf_contains!-quantifier cdr l);

endmodule; % pasfnf

end;
