% ----------------------------------------------------------------------
% $Id: clmisc.red,v 1.15 1999/04/13 13:10:57 sturm Exp $
% ----------------------------------------------------------------------
% Copyright (c) 1995-1999 Andreas Dolzmann and Thomas Sturm
% ----------------------------------------------------------------------
% $Log: clmisc.red,v $
% Revision 1.15  1999/04/13 13:10:57  sturm
% Updated comments for exported procedures.
%
% Revision 1.14  1999/03/22 17:08:06  dolzmann
% Changed copyright information.
%
% Revision 1.13  1999/03/21 13:34:24  dolzmann
% Removed unused procedure cl_varmem.
% Corrected comments.
%
% Revision 1.12  1999/01/17 16:02:30  dolzmann
% Added and corrected comments.
%
% Revision 1.11  1997/10/01 11:11:42  dolzmann
% Added procedure cl_splt.
%
% Revision 1.10  1997/08/24 16:18:48  sturm
% Added service rl_surep with black box rl_multsurep.
% Added service rl_siaddatl.
%
% Revision 1.9  1997/04/08 14:33:17  sturm
% Fixed a bug in cl_subfof: sub(y=z,ex(x,x+y=0)) did unnecessarily rename x.
%
% Revision 1.8  1996/10/23 14:28:55  sturm
% sub(a=0,ex(x,true)) crashed due to the truth value within the
% quantifier scope.
%
% Revision 1.7  1996/10/17 13:54:07  sturm
% Renamed cl_varl to cl_varl1.
% Rename cl_fvarl to cl_subfvarl and removed redundant parameter there.
% Same for cl_fvarl1.
%
% Revision 1.6  1996/10/07 11:45:50  sturm
% Added fluids for CVS and copyright information.
%
% Revision 1.5  1996/09/05 11:11:51  dolzmann
% Added procedure cl_f2ml. Procedure cl_atml1 now uses cl_f2ml.
% New procedures for determing multiplicity lists and sets of terms or
% irreducible factors.
% Added procedures cl_struct and cl_ifstruct and related code.
%
% Revision 1.4  1996/07/07 14:35:16  sturm
% Introduced new black box rl_eqnrhskernels.
%
% Revision 1.3  1996/06/05 15:08:42  sturm
% Second argument of cl_subfof is a formula now.
% Added renaming to cl_subfof.
%
% Revision 1.2  1996/05/21 17:13:19  sturm
% Added service implementation cl_subfof.
%
% Revision 1.1  1996/03/22 10:31:28  sturm
% Moved and split.
%
% ----------------------------------------------------------------------
lisp <<
   fluid '(cl_misc_rcsid!* cl_misc_copyright!*);
   cl_misc_rcsid!* := "$Id: clmisc.red,v 1.15 1999/04/13 13:10:57 sturm Exp $";
   cl_misc_copyright!* := "(c) 1995-1999 by A. Dolzmann and T. Sturm"
>>;

module clmisc;
% Common logic miscellaneous algorithms. Submodule of [cl].

procedure cl_apply2ats(f,client);
   % Common logic apply to atomic formulas. [f] is formula; [client]
   % is a function that maps atomic formulas to formulas. Returns a
   % formula derived from [f] by replacing each atomic formula
   % $\alpha$ by $[client](\alpha)$.
   cl_apply2ats1(f,client,nil);

procedure cl_apply2ats1(f,client,clpl);
   % Common logic apply to atomic formulas variant. [f] is formula;
   % [client] is a function $[client](a,p_1,...,p_n)$; [clpl] is a
   % list $(s_1,...,s_n)$; the first argument $a$ of [clpl] is an
   % atomic formula, the specifications of the remaining arguments
   % $p_1,...,p_n$ are met by the entries $s_1,...,s_n$ of [clpl]; the
   % return value of [client] is an atomic formula. Returns a formula
   % derived from [f] by replacing each atomic formula $\alpha$ by
   % $[client](\alpha,s_1,...,s_n)$.
   begin scalar op;
      op := rl_op f;
      if rl_tvalp op then return f;
      if rl_quap op then
    	 return rl_mkq(op,rl_var f,cl_apply2ats1(
      	    rl_mat f,client,clpl));
      if rl_boolp op then
    	 return rl_mkn(op,for each subf in rl_argn f collect
	    cl_apply2ats1(subf,client,clpl));
      % [f] is an atomic formula.
      return apply(client,f . clpl)
   end;

procedure cl_apply2ats2(f,client,clpl,sop);
   % Common logic apply to atomic formulas variant. [f] is formula;
   % [client] is a function $[client](a,r,p_1,...,p_n)$; [clpl] is a
   % list $(s_1,...,s_n)$; the first argument $a$ of [clpl] is an
   % atomic formula, the second argument $r$ is a non-atomic formula
   % operator, the specifications of the remaining arguments
   % $p_1,...,p_n$ are met by the entries $s_1,...,s_n$ of [clpl]; the
   % return value of [client] is an atomic formula; [sop] is an
   % operator. Returns a formula derived from [f] by replacing each
   % atomic formula $\alpha$ by $[client](\alpha,r_0,s_1,...,s_n)$,
   % where $r_0$ is the operator of the complex subformula in which
   % $\alpha$ occurs.
   begin scalar op;
      op := rl_op f;
      if rl_tvalp op then return f;
      if rl_quap op then
    	 return rl_mkq(op,rl_var f,cl_apply2ats2(
      	    rl_mat f,client,clpl,op));
      if rl_boolp op then
    	 return rl_mkn(op,for each subf in rl_argn f collect
	    cl_apply2ats2(subf,client,clpl,op));
      % [f] is an atomic formula.
      return apply(client,f . sop . clpl)
   end;

procedure cl_atnum(f);
   % Common logic atomic formula nummber. [f] is a formula. Returns
   % the number of atomic formulas in [f] counting multiplicities.
   begin scalar op;
      op := rl_op f;
      if rl_boolp op then
 	 return for each subf in rl_argn f sum
    	    cl_atnum(subf);
      if rl_quap op then
    	 return cl_atnum(rl_mat f);
      if rl_tvalp op then return 0;
      % [f] is an atomic formula.
      return 1
   end;

%DS
% <MULTIPLICITY LIST> ::= (..., (<S-EXPRESSION> . <OCCURRENCES>), ...)
% <OCCURRENCES> ::= <INTEGER>

procedure cl_f2ml(f,client);
   % Common logic formula to multiplicity list. [f] is a formula;
   % [client] is a procedure that maps an atomic formula to a
   % MULTIPLICITY LIST. Retuns a MULTIPLICITY LIST. [client] is
   % applied to all atomic formulas in [f], and the resulting
   % MULTIPLICITY LIST are merged.
   begin scalar op;
      op := rl_op f;
      if rl_tvalp f then
 	 return nil;
      if rl_boolp op then
 	 return lto_almerge(
	    for each subf in rl_argn f collect cl_f2ml(subf,client),'plus2);
      if rl_quap op then
    	 return cl_f2ml(rl_mat f,client);
      % [f] is an atomic formula.
      return apply(client,{f})
   end;

procedure cl_atml(f);
   % Common logic atomic formula multiplicity list. [f] is a formula.
   % Returns a MULTYPLICITY LIST of the atomic formulas occurring in
   % [f]. The result is sorted wrt. [rl_ordatp].
   sort(cl_atml1 f,function(lambda(x,y); rl_ordatp(car x,car y)));

procedure cl_atml1(f);
   % Common logic atomic formula multiplicity list subroutine. [f] is
   % a formula. Returns a MULTYPLICITY LIST of the atomic formulas
   % occurring in [f].
   cl_f2ml(f,'cl_atmlc);

procedure cl_atmlc(atf);
   {atf . 1};

procedure cl_atl(f);
   % Common logic atomic formula list. Returns the set of atomic
   % formulas contained in [f] as a list. The result is sorted wrt.
   % [rl_ordatp].
   sort(cl_atl1 f,'rl_ordatp);

procedure cl_atl1(f);
   % Common logic atomic formula list. Returns the set of atomic
   % formulas contained in [f] as a list.
   for each x in cl_atml1 f collect car x;

procedure cl_identifyonoff(b);
   % Common logic identify on off. [b] is bool. This is the [simpfg]
   % of the switch [rlidentify]. Clears fluid [cl_identify!-atl!*].
   cl_identify!-atl!* := nil;

procedure cl_ifacml(f);
   % Common logic irreducible factors multiplicity list. [f] is a
   % formula. Returns the MULTIPLICITY LIST of all irreducible
   % non-unit factors of the terms occurring in [f]. The result is
   % sorted wrt. [rl_tordp].
   sort(cl_ifacml1 f,function(lambda(x,y); rl_tordp(car x,car y)));

procedure cl_ifacml1(f);
   % Common logic irreducible factors multiplicity list subroutine.
   % [f] is a formula. Returns the MULTIPLICITY LIST of all
   % irreducible non-unit factors of the terms occurring in [f].
   cl_f2ml(f,'rl_fctrat);

procedure cl_ifacl(f);
   % Common logic irreducible factors list. [f] is a formula. Returns
   % the set of all irreducible non-unit factors of the terms
   % occurring in [f] as a list. The result is sorted wrt. [rl_tordp].
   sort(cl_ifacl1 f,'rl_tordp);

procedure cl_ifacl1(f);
   % Common logic irreducible factors list subroutine. [f] is a
   % formula. Returns the set of all irreducible non-unit factors of
   % the terms occurring in [f] as a list.
   for each x in cl_ifacml1 f collect car x;

procedure cl_matrix(f);
   % Common logic formula matrix. [f] is a formula. Returns a formula.
   % Remove all leading quantifiers from [f].
   if rl_quap rl_op f then cl_matrix rl_mat f else f;

procedure cl_closure(q,f,nl);
   % Common logig closure. [q] is one of the quantifers [ex], [all];
   % [f] is a formula; [nl] is a list of variables. Returns the
   % formula $[q] v_1 ... [q] v_n ([f])$ where the $v_i$ are all free
   % variables of [f] that are not in [nl].
   begin scalar freevarl,result;
      % Create a list of all free variables.
      freevarl := car cl_varl1 f;
      % Remove the variables of the negative list.
      for each v in nl do
 	 freevarl := delqip(v,freevarl);
      % [q]-quantify with the remaining variables.
      result := f;
      for each x in freevarl do
 	 result := rl_mkq(q,x,result);
      return result
   end;

procedure cl_all(f,nl);
   % Common logic [all]-quantify; universal closure. [f] is a formula;
   % [nl] is a list of variables. Returns the formula $\forall v_1 ...
   % \forall v_n ([f])$, where the $v_i$ are all free variables of [f]
   % that are not in [nl].
   cl_closure('all,f,nl);

procedure cl_ex(f,nl);
   % Common logic [ex]-quantify; existential closure. [f] is a
   % formula; [nl] is a list of variables. Returns the formula
   % $\exists v_1 ... \exists v_n ([f])$ where the $v_i$ are all free
   % variables of [f] that are not in [nl].
   cl_closure('ex,f,nl);

procedure cl_flip(op);
   % Common logic flip. [op] is one of the operators [and], [or],
   % [all], [ex], [true], [false]. Returns an operator. Maps [and] to
   % [or], [all] to [ex], [true] to [false], and vice versa.
   if op eq 'and then 'or
   else if op eq 'or then 'and
   else if op eq 'all then 'ex
   else if op eq 'ex then 'all
   else if op eq 'true then 'false
   else if op eq 'false then 'true
   else rederr {"cl_flip(): don't know",op};

procedure cl_cflip(op,flag);
   % Common logic conditionally flip. [op] is one of the operators
   % [and], [or], [all], [ex], [true], [false]; [flag] is bool.
   % Returns an operator. Returns [op] if [flag] is [true], and
   % [cl_flip op] else.
   if flag then op else cl_flip op;

procedure cl_subfof(al,f);
   % Common logic substitute into first-order formula. [al] is an
   % ALIST $(..., (v_i . p_i), ...)$, where $v_i$ are variables and
   % $p_i$ are Lisp prefix forms; [f] is a formula. Returns a formula.
   % In the retuned formula, all occurrences of the $v_i$ are replaced
   % by the $p_i$. If the $p_i$ contain parametric denominators then
   % an error is raised.
   begin scalar asgal,w,allvl;
      rl_subalchk al;
      for each x in al do <<
	 w := rl_eqnrhskernels(x);
	 asgal := lto_alunion {{car x . w},asgal};
	 allvl := car x . append(w,allvl)
      >>;
      w := cl_varl1 f;
      allvl := lto_nconcn {allvl,car w,cdr w};
      return cl_subfof1(al,f,asgal,allvl)
   end;

procedure cl_subfof1(al,f,asgal,allvl);
   % Common logic substitute first-order formula. [al] is an ALIST;
   % [f] is a formula; [asgal] is an ALIST; [allvl] is a list of
   % variables. Returns a formula. [al] is of the form $(...,(v_i .
   % p_i),...)$, where $v_i$ are variables and $p_i$ are Lisp-prefix
   % forms. In the retuned formula all occurences of the $v_i$ are
   % replaced by the $p_i$. If the $p_i$ contain parametric
   % denominators an error is raised.
   begin scalar op,v,newv,m;
      op := rl_op f;
      if rl_tvalp op then
      	 return f;
      if rl_quap op then <<
	 v := rl_var f;
	 m := rl_mat f;
	 al := for each x in al join if not eqcar(x,v) then {x};
	 asgal := for each x in asgal join if not eqcar(x,v) then {x};
	 newv := cl_newv(v,m,asgal,allvl);
	 if newv neq v then <<
	    allvl := newv . allvl;
	    m := cl_subvarsubstat(newv,v,m)
	 >>;
	 return rl_mkq(op,newv,cl_subfof1(al,m,asgal,allvl))
      >>;
      if rl_boolp op then
 	 return rl_mkn(op,for each x in rl_argn f collect
 	    cl_subfof1(al,x,asgal,allvl));
      % [f] is atomic.
      return rl_subat(al,f)
   end;

procedure cl_newv(v,m,asgal,allvl);
   % Common logic new v. Returns a variable. Rename [v] if necessary.
   begin scalar a,fvl,w,newv; integer n;
      newv := v;
      fvl := cl_subfvarl m;
      while fvl do <<
	 a := car fvl;
	 fvl := cdr fvl;
	 if (w := atsoc(a,asgal)) and v memq w then <<
	    % There is a substitution of [v] for a free variable.
	    repeat <<
               newv := mkid(v,n);
	       n := n + 1
            >> until not (newv memq allvl or get(v,'avalue));
	    fvl := nil
	 >>
      >>;
      return newv
   end;

procedure cl_subvarsubstat(newv,oldv,f);
   begin scalar op;
      op := rl_op f;
      if rl_quap op then
	 if rl_var f eq oldv then
	    return rl_mkq(op,newv,cl_subvarsubstat(newv,oldv,rl_mat f))
	 else
	    return rl_mkq(op,rl_var f,cl_subvarsubstat(newv,oldv,rl_mat f));
      if rl_boolp op then
	 return rl_mkn(op,for each x in rl_argn f collect
 	    cl_subvarsubstat(newv,oldv,x));
      return rl_varsubstat(f,newv,oldv)
   end;

procedure cl_subfvarl(m);
   cl_subfvarl1(m,nil);

procedure cl_subfvarl1(f,cbvl);
   begin scalar op;
      op := rl_op f;
      if rl_quap op then
	 return cl_subfvarl1(rl_mat f,rl_var f . cbvl);
      if rl_boolp op then
	 return for each x in rl_argn f join cl_subfvarl1(x,cbvl);
      if rl_tvalp op then
	 return nil;
      return for each x in rl_varlat f join if not (x memq cbvl) then {x}
   end;

procedure cl_termml(f);
   % Common logic term multiplicity list. [f] is a formula. Returns
   % the MULTIPLICITY LIST of all non-zero terms occurring in
   % [f]. The result is sorted wrt. [rl_tordp].
   sort(cl_termml1 f,function(lambda(x,y); rl_tordp(car x,car y)));

procedure cl_termml1(f);
   % Common logic term multiplicity list subroutine. [f] is a formula.
   % Returns the MULTIPLICITY LIST of all non-zero terms occurring in
   % [f].
   cl_f2ml(f,'rl_termmlat);

procedure cl_terml(f);
   % Common logic term list. [f] is a formula. Returns the set of all
   % non-zero terms occurring in [f] as a list. The result is sorted wrt.
   % [rl_tordp].
   sort(cl_terml1 f,'rl_tordp);

procedure cl_terml1(f);
   % Common logic term list subroutine. [f] is a formula. Returns the
   % set of all non-zero terms occurring in [f] as a list.
   for each x in cl_termml1 f collect car x;

procedure cl_struct(f,v);
   % Common logic structure of a formula. [f] is a formula; [v] is a
   % kernel. Returns a pair $(\phi . (..., (v_i . t_i), ...))$. The
   % $v_i$ are the kernels $[v] \circ i$ with $i = 1, 2, ...$; the
   % $t_i$ are the terms occurring in [f]. $\phi$ is a formula
   % obtained from [f] by replacing each term $t_i$ with $v_i$.
   begin scalar w; integer j;
      w := cl_terml(f);
      w := for each s in w collect
	 (s . mkid(v,j := j+1));
      return cl_struct1(f,w) . w;
   end;

procedure cl_struct1(f,al);
   cl_apply2ats1(f,'rl_structat,{al});

procedure cl_ifstruct(f,v);
   % Common logic irreducible factor structure of a formula. [f] is a
   % formula; [v] is a kernel. Returns a pair $(\phi . (..., (v_i .
   % s_i), ...))$. The $v_i$ are the kernels $[v] \circ i$ with $i =
   % 1, 2, ...$; the $s_i$ are the irreducible non-unit factors of the
   % terms occurring in [f]. $\phi$ is a formula obtained from [f] by
   % replacing within the terms each factor $s_i$ with $v_i$. That is,
   % the terms of $\phi$ are products of kernels $[v] \circ i$, $i =
   % 1, 2, ...$.
   begin scalar w; integer j;
      w := cl_ifacl(f);
      w := for each s in w collect
	 (s . mkid(v,j := j+1));
      return cl_ifstruct1(f,w) . w;
   end;

procedure cl_ifstruct1(f,al);
   cl_apply2ats1(f,'rl_ifstructat,{al});

procedure cl_surep(at,atl);
   % Common logic sure predicate. [at] is an atomic formula; [atl] is
   % a THEORY. Returns bool. Heurictically check whether [at] follows
   % from [atl].
   if !*rlspgs then
      rl_gsd(at,atl) eq 'true or rl_multsurep(at,atl)
   else
      rl_simpl(at,atl,-1) eq 'true or rl_multsurep(at,atl);

%DS
% <QBLK> ::= (<QUANTIFIER> . <VARLIST>)
% <QUANTIFIER> ::= ['ex] | ['all]
% <VARLIST> ::= (...,<VARIABLE>,...)

procedure cl_splt(f);
   % Common logic split. [f] is a formula in prenex normal form.
   % Returns a list $(\Gamma,\phi,\Lambda)$, where $\Gamma$ is a list
   % of QBLK's, $\phi$ is the quantifier-free matrix formula of [f],
   % and $\Lambda$ is the list of all bound variables. $\Gamma$
   % contains the quantifier blocks of [f] in reverse order.
   begin scalar w,q,vl,qblkl,bvl,v;
      q := rl_op f;
      if not(q memq '(ex all)) then
	 return {nil,f,nil};
      while (w := rl_op f) memq '(ex all) do <<
	 v := rl_var f;
	 bvl := v . bvl;
	 if w eq q then
	    vl := v . vl
	 else <<
	    qblkl := (q . vl) . qblkl;
	    q := w;
	    vl := {v}
	 >>;
	 f := rl_mat f
      >>;
      qblkl := (q . vl) . qblkl;
      return {qblkl,f,bvl}
   end;

endmodule;  % [clmisc]

end;  % of file
