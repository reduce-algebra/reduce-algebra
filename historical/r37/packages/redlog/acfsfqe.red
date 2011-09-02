% ----------------------------------------------------------------------
% $Id: acfsfqe.red,v 1.10 1999/04/12 09:25:59 sturm Exp $
% ----------------------------------------------------------------------
% Copyright (c) 1995-1999 Andreas Dolzmann and Thomas Sturm
% ----------------------------------------------------------------------
% $Log: acfsfqe.red,v $
% Revision 1.10  1999/04/12 09:25:59  sturm
% Updated comments for exported procedures.
%
% Revision 1.9  1999/04/11 11:35:30  dolzmann
% Use the new standard form interface cgb_cgbf which provides also a
% wrapper to the gb package.
%
% Revision 1.8  1999/04/11 09:53:24  dolzmann
% Adapted the procedure acfsf_qeblk2 to the new SF interface of the cgb
% package.
% Procedure acfsf_qefl uses dip's instead of vdp's.
%
% Revision 1.7  1999/04/04 19:03:23  sturm
% Removed acfsf_cgbf and use new interface cgb_cgbf provided by cgb.
% Encapsulated sfto_groebnerf call into torder local setting.
%
% Revision 1.6  1999/03/23 08:21:01  dolzmann
% Changed copyright information.
% Corrected comments for extracting with exc.
%
% Revision 1.5  1999/03/21 13:33:45  dolzmann
% Added implementation of the service rlthsimpl.
% Corrected comments.
%
% Revision 1.4  1997/11/14 05:37:25  dolzmann
% Fixed a bug acfsf_qe1.
%
% Revision 1.3  1997/10/02 13:49:51  dolzmann
% In procedure acfsf_qe1: Remove atomic formulas containing bound variables
% from the theory.
%
% Revision 1.2  1997/10/02 13:14:41  sturm
% The CGB switches have been renamed from gcgb... to cgb...
%
% Revision 1.1  1997/10/01 11:13:06  dolzmann
% Initial check-in.
%
% ----------------------------------------------------------------------
lisp <<
   fluid '(acfsf_qe_rcsid!* acfsf_qe_copyright!*);
   acfsf_qe_rcsid!* :=
      "$Id: acfsfqe.red,v 1.10 1999/04/12 09:25:59 sturm Exp $";
   acfsf_qe_copyright!* := "Copyright (c) 1995-1999 A. Dolzmann and T. Sturm"
>>;

module acfsfqe;
% Algebraically closed field standard form quantifier elimination.
% Submodule of [acfsf].

procedure acfsf_gqe(f,theo,xbvl);
   % Algebraically closed field generic quantifier elimination. [f] is
   % a formula; [theo] is a theory; [xbvl] is a list of variables.
   begin scalar !*cgbgen,!*cgbreal;
      !*cgbgen := T;
      return acfsf_qe1(f,theo,xbvl)
   end;

procedure acfsf_qe(f,theo);
   % Algebraically closed field quantifier elimination. [f] is a
   % formula; [theo] is a theory. Returns a quantifier-free formula
   % equivalent to [f] wrt. [theo].
   begin scalar !*cgbgen,!*cgbreal;
      !*cgbgen := nil;
      return acfsf_qe1(f,theo,nil)
   end;

procedure acfsf_qe1(f,theo,xbvl);
   % Algebraically closed field standard form quantifier elimination.
   % [f] is a formula; [theo] is a theory; [xbvl] is a list of
   % variables. Returns a formula equivalent to [f].
   begin scalar w,qblkl,qff,bvl;
      f := rl_simpl(rl_pnf f,theo,-1);
      w := cl_splt f;
      qblkl := car w;
      if null qblkl then
	 return f;
      qff := cadr w;
      bvl := caddr w;
      theo := for each atf in theo join
	 if null intersection(rl_varlat atf,bvl) then {atf};
      xbvl := nconc(bvl,xbvl);
      if !*rlqegen then
	 if cdr qblkl then
	    rederr "acfsf_qe: gqe supported only for one block of quantifiers"
	 else if xbvl then
	    rederr "acfsf_qe: does not accept a xbvl";
      for each qblk in qblkl do
	 qff := acfsf_qeblk(qblk,qff,theo,xbvl);
      return qff
   end;

procedure acfsf_qeblk(qblk,f,theo,bvl);
   % Algebraically closed field standard form quantifier elimination.
   % [qblk] is a QBLK; [f] is a quantifier-free formula; [theo] is a
   % theory; [bvl] is a list of variables. Returns a formula
   % equivalent to [f].
   if car qblk eq 'ex then
      acfsf_qeblk1(cdr qblk,f,theo,bvl)
   else
      cl_nnfnot acfsf_qeblk1(cdr qblk,cl_nnfnot f,theo,bvl);

procedure acfsf_qeblk1(vl,f,theo,bvl);
   % Algebraically closed field standard form quantifier elimination.
   % [vl] is a list of variables; [f] is a conjunction of atomic
   % formulas, an atomic formula or a truth value; [theo] is a theory;
   % [bvl] is a list of variables. Returns a formula.
   begin scalar w,fl;
      f := rl_dnf f;
      fl := if rl_op f eq 'or then rl_argn f else {f};
      w := for each c in fl collect
      	 acfsf_qeblk2(vl,c,theo,bvl);
      return rl_simpl(rl_smkn('or,reversip w),theo,-1)
   end;

procedure acfsf_qeblk2(vl,f,theo,bvl);
   % Algebraically closed field standard form quantifier elimination.
   % [qblkl] is a list of QBLK's; [f] is a conjunction of atomic
   % formulas, an atomic formula, or a truth value; [theo] is a
   % theory; [bvl] is a list of variables. Returns a formula which is
   % equivalent to ex(vl,f) wrt. [theo].
   begin scalar w,atl,eqtl,itheo,cgb;
      if rl_tvalp f then
	 return f;
      atl := cl_atl1 f;
      w := acfsf_spltcj(atl,vl);
      atl := car w;
      itheo := cdr w;
      w := acfsf_eqtl atl;
      eqtl := car w;
      vl := nconc(cdr w,vl);
      cgb := cgb_cgbf(eqtl,vl,'revgradlex,nil) where !*gbverbose=nil;
      return rl_smkn('and,acfsf_qefl(cgb,vl) . itheo)
   end;

procedure acfsf_spltcj(atl,vl);
   % Algebraically closed field standard form quantifier elimination
   % split conjunction. [atl] is a list of atomic formulas considered
   % conjunctive; [vl] is a list of variables. Returns a pair $(\alpha
   % . \beta)$, where $\alpha$ and $\beta$ are list of atomic
   % formulas. The union of $\alpha$ and $beta$ is equal to [atl]. No
   % variables from [vl] occurs in the atomic formulas in $\beta$.
   begin scalar natl,itheo;
      for each x in atl do
	 if intersection(acfsf_varlat x,vl) then
	    natl := x . natl
	 else
	    itheo := x . itheo;
      return natl . itheo
   end;

procedure acfsf_eqtl(atl);
   % Algebraically closed field standard form equation term list.
   % [atl] is a list of atomic formulas. Returns a pair $(\lambda .
   % \tau)$, where $\lambda$ is a list of terms considered as
   % equations and $\tau$ is a list of variables. $\bigwedge([atl])$
   % is equivalent to $\exists(\tau,\lambda)$.
   begin scalar eqtl,neqtl,w;
      for each at in atl do
	 if acfsf_op at eq 'equal then
	    eqtl := acfsf_arg2l at . eqtl
	 else
	    neqtl := acfsf_arg2l at . neqtl;
      w := acfsf_rmneqtl neqtl;
      eqtl := nconc(car w,eqtl);
      return eqtl . cdr w
   end;

procedure acfsf_rmneqtl(neqtl);
   % Algebraically closed field standard form remove neq term list.
   % [neqtl] is a list of terms considered as inequalities. Returns a
   % pair $(\lambda . \tau)$, where $\lambda$ is a list of terms
   % considered as equations and $\tau$ is a list of variables.
   % $\bigwedge([neqtl])$ is equivalent to $\exists(\tau,\lambda)$.
   begin scalar p,v;
      if null neqtl then
	 return nil . nil;
      p := 1;
      for each u in neqtl do
	 p := multf(p,u);
      v := acfsf_tagvar();
      p := addf(multf(p,numr simp v),negf 1);
      return {p} . {v}
   end;

procedure acfsf_tagvar();
   % Algebraically closed field standard form tag variable. Returns a
   % tag variable.
   intern gensym();

procedure acfsf_qefl(ul,vl);
   % Algebraically closed field standard form quantifier elimination
   % formula from form-list. [ul] is a list of SF's; [vl] is a list of
   % variables. Returns a quantifier-free formula.
   begin scalar fl,oenv;
      if null ul then return 'true;
      oenv := dip_init(vl,'revgradlex,nil);
      fl := for each u in ul collect
	 acfsf_qefl1 dip_f2dip u;
      dip_cleanup(oenv);
      return rl_smkn('and,fl)
   end;

procedure acfsf_qefl1(p);
   % Algebraically closed field standard form quantifier elimination
   % formula from form subroutine. [p] is a DIP. Returns a
   % quantifier-free formula.
   begin scalar p,fl,cl,lev,lc;
      while p do <<
 	 cl := dip_lbc p . cl;
	 lev := dip_evlmon p;
      	 p := dip_mred p;
      >>;
      if ev_zero!? lev then <<
	 lc := car cl;
	 cl := cdr cl
      >> else
	 lc := simp 0;
      fl := for each c in cl collect
	 acfsf_0mk2('neq,acfsf_bc2f c);
      fl := acfsf_0mk2('equal,acfsf_bc2f lc) . fl;
      return rl_smkn('or,fl)
   end;

procedure acfsf_bc2f(c);
   % Algebraically closed field standard form base coefficient to
   % form. [c] is a base coefficient as defined in dipoly. Returns a
   % SF.
   numr bc_2sq c;

procedure acfsf_thsimpl(atl);
   % Algebraically closed field theory simplification. [atl] is a
   % theory. Returns an equivalent theory. The returned theory is
   % simpler than the original one.
   begin scalar !*rlsiexpla,!*rlsipo;
      !*rlsiexpla := T;
      return sort(acfsf_thregen cl_simpl(rl_smkn('and,atl),nil,-1),'rl_ordatp)
   end;

procedure acfsf_thregen(f);
   % Algebraically closed field standard form re-generate theory. [f]
   % is a formula. Returns a possibly empty list of atomic formulas
   % equivalent to [f] or the list [{'false}] if [f] is recognized as
   % a contradiction.
   begin scalar op;
      op := rl_op f;
      if op = 'and then
 	 return for each x in rl_argn f collect acfsf_thregen!-or x;
      if op = 'or then
	 return {acfsf_thregen!-or f};
      if op = 'true then
	 return nil;
      if op = 'false then
	 {'false};
      % [f] is atomic.
      return {f}
   end;

procedure acfsf_thregen!-or(f);
   % Algebraically closed field standard form re-generate theory
   % disjunction case. [f] is a disjunction of equations. Returns an
   % equation equivalent to [f].
   begin scalar w;
      if cl_atfp f then
	 return f;
      w := numr simp 1;
      for each equ in rl_argn f do <<
      	 if rl_op equ neq 'equal then
	    rederr "Bug in acfsf_thregen!-or";
	 w := multf(w,rl_arg2l equ)
      >>;
      return acfsf_0mk2('equal,w)
   end;

endmodule;  % [acfsfqe]

end;  % of file
