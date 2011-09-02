% ----------------------------------------------------------------------
% $Id: clsimpl.red,v 1.22 2003/08/19 09:29:04 seidl Exp $
% ----------------------------------------------------------------------
% Copyright (c) 1995-1999 Andreas Dolzmann and Thomas Sturm
% ----------------------------------------------------------------------
% $Log: clsimpl.red,v $
% Revision 1.22  2003/08/19 09:29:04  seidl
% Restructured and partly rewritten simplification of bounded
% quantifiers by identifying rules (TV), (EQ), (SB), (SM), (STRB).
% Removed a hack by introducing blackbox "bsatp".
%
% Revision 1.21  2003/08/14 21:44:05  seidl
% Simplification of bounded quantifiers looks quite good now. A hack has
% to be cured by a blackbox bsatp (bound sat. predicate). rlsism can be
% savely turned on now in pasf, but there is a problem with susi and
% congruences.
%
% Revision 1.20  2003/08/14 16:45:04  seidl
% Improved simplification of bounded quantifiers. If the bound or the
% matrix is a truth value, then the result will be a truth value.
%
% Revision 1.19  2003/08/05 08:58:34  seidl
% Intermediate check-in.
%
% Revision 1.18  2003/07/22 07:21:10  seidl
% Simplification is aware of bounds that are equations now. Found bug in
% b2terml, TODO Lasaruk.
%
% Revision 1.17  2003/07/22 06:17:50  seidl
% Intermediate check-in. Part of advanced smart simplification works
% already.
%
% Revision 1.16  2003/07/14 12:39:48  lasaruk
% some cl-methods corrected to work with bounded quantifiers
%
% Revision 1.15  2003/06/01 21:01:56  seidl
% Moved code for simplifying bounded quantifiers to a procedure. Resolved a
% bug there. Added further simplifications there.
%
% Revision 1.14  2003/04/09 18:31:02  seidl
% Augmented cl_simpl1 and added cl_strb, so the standard simplifier can
% deal now with bounded quantifiers. If possible, the bound condition is
% strengthened.
%
% Revision 1.13  2003/01/31 08:44:40  sturm
% Fixed a bug in cl_smsimpl!-imprep!-atprem and cl_smsimpl!-imprep!-atconcl.
%
% Revision 1.12  1999/09/22 13:00:18  dolzmann
% Added procedure cl_susiminlevel for the ofsf part of susi.
%
% Revision 1.11  1999/04/13 13:11:01  sturm
% Updated comments for exported procedures.
%
% Revision 1.10  1999/03/22 17:06:43  dolzmann
% Changed copyright information.
% Added and reformatted comments.
%
% Revision 1.9  1999/03/21 13:34:45  dolzmann
% Added the cl-part of the super simplifier susi.
%
% Revision 1.8  1999/01/17 15:36:43  dolzmann
% Corrected some typos in the comments.
%
% Revision 1.7  1997/08/24 16:14:56  sturm
% Added procedure cl_sitheo using fluid !*rlsithok.
% Added service rl_surep with black box rl_multsurep.
% Added service rl_siaddatl.
%
% Revision 1.6  1996/10/07 11:45:55  sturm
% Added fluids for CVS and copyright information.
%
% Revision 1.5  1996/09/05 11:50:11  dolzmann
% Minor changes in procedure cl_simplat.
%
% Revision 1.4  1996/09/05 11:14:20  dolzmann
% Fixed a bug in cl_simplat: atomic formulas are always simplified.
%
% Revision 1.3  1996/07/13 11:01:59  dolzmann
% Fixed a bug in cl_simpl.
% Introduced new black box rl_smcpknowl.
% Removed procedure cl_cpknowl.
% Added context independent black box implementations cl_smcpknowl,
% cl_smrmknowl, cl_smupdknowl, cl_smmkatl, cl_smsimpl!-impl, and
% cl_smsimpl!-equiv1.
%
% Revision 1.2  1996/03/25 08:50:55  sturm
% Fixed a bug in procedure cl_simpl.
%
% Revision 1.1  1996/03/22 10:31:32  sturm
% Moved and split.
%
% ----------------------------------------------------------------------
lisp <<
   fluid '(cl_simpl_rcsid!* cl_simpl_copyright!*);
   cl_simpl_rcsid!* := "$Id: clsimpl.red,v 1.22 2003/08/19 09:29:04 seidl Exp $";
   cl_simpl_copyright!* := "(c) 1995-1999 by A. Dolzmann and T. Sturm"
>>;

module clsimpl;
% Common logic simplification routines. Submodule of [cl]. Here the
% standard simplifier is implemented.

%DS
% <theory> ::= (<atomic_formula>,...)

procedure cl_simpl(f,atl,n);
   % Common logic simplify. [f] is a formula; [atl] is a list of
   % atomic formulas, which are considered to describe a theory; [n]
   % is an integer. Depends on switches [!*rlsism], [!*rlsichk],
   % [!*rlsiso], [!*rlsiidem]. Returns the identifier [inctheo] or a
   % formula. [inctheo] means that [atl] is inconsistent. Else the
   % result is [f], simplified (wrt. [atl]). For non-negative [n],
   % simplification stops at level [n].
   begin scalar w;
      if null !*rlsism then
 	 return cl_simpl1(f,nil,n,nil);
      atl := cl_sitheo atl;
      if atl eq 'inctheo then
	 return 'inctheo;
      w := rl_smupdknowl('and,atl,nil,n+1);
      if w eq 'false then return 'inctheo;
      return cl_simpl1(f,w,n,nil)
   end;

procedure cl_sitheo(atl);
   % Common logic simplify theory. [atl] is a THEORY. Returns either a
   % list $l$ of atomic formulas, or the identifier [inctheo]. In the
   % first case the conjunction over $l$ is equivalent to the
   % conjuction over [atl], and $l$ contains only simplified atomic
   % formulas. The return value [inctheo] means that the conjunction
   % over [atl] is equivalent to [false]. Accesses the fluid
   % [rlsithok], and returns [atl] in case that [rlsithok] is
   % non-[nil].
   begin scalar atf,w,natl,!*rlsiexpla;
      if !*rlsithok then
	 return atl;
      while atl do <<
	 atf := car atl;
	 atl := cdr atl;
	 w := cl_simplat(atf,nil);
	 if w eq 'false then <<
	    atf := 'inctheo;
	    atl := nil
	 >> else if w neq 'true then
	    natl := w . natl
      >>;
      if atf eq 'inctheo then
	 return 'inctheo;
      return natl
   end;

procedure cl_simpl1(f,knowl,n,sop);
   % Common logic simplify. [f] is a formula; [knowl] is an IRL; [n]
   % is an integer; [sop] is a CL operator. Depends on switches
   % [!*rlsism], [!*rlsichk], [!*rlsiso], [!*rlsiidem]. Returns a
   % formula. Simplifies [f] recursively using [knowl].
   begin scalar op,result,w,newknowl;
      if eqn(n,0) then return f;
      op := rl_op f;
      if rl_tvalp op then return f;
      if rl_junctp op then
	 return rl_smkn(op,cl_smsimpl!-junct(op,rl_argn f,knowl,n));
      if op eq 'not then <<
    	 result := cl_simpl1(rl_arg1 f,knowl,n-1,'not);
    	 if rl_tvalp result then return cl_flip result;
	 if cl_atfp result then return rl_negateat result;
    	 return cl_negate!-invol(result)
      >>;
      if rl_quap op then <<
	 if !*rlsism then knowl := rl_smrmknowl(knowl,rl_var f);
    	 result := cl_simpl1(rl_mat f,knowl,n-1,op);
    	 if rl_tvalp result then return result;
    	 return rl_mkq(op,rl_var f,result)
      >>;
      if rl_bquap op then return cl_simpl!-bqua(f,knowl,n,sop);
      if op eq 'impl then
	 return cl_smsimpl!-imprep(rl_arg2l f,rl_arg2r f,knowl,n);
      if op eq 'repl then
	 return cl_smsimpl!-imprep(rl_arg2r f,rl_arg2l f,knowl,n);
      if op eq 'equiv then
	 return cl_smsimpl!-equiv(rl_arg2l f,rl_arg2r f,knowl,n);
      w := cl_simplat(f,sop);
      if !*rlsism then <<
	 op := rl_op w;
	 if rl_junctp op then
	    return rl_smkn(op,cl_smsimpl!-junct(op,rl_argn w,knowl,n));
	 if rl_tvalp op then
 	    return w;
	 % [w] is atomic.
	 newknowl := rl_smupdknowl('and,{w},rl_smcpknowl knowl,n);
	 if newknowl eq 'false then return 'false;
	 w := rl_smmkatl('and,knowl,newknowl,n);
	 return rl_smkn('and,w)
      >>;
      if w then return w;
      rederr {"cl_simpl1(): unknown operator",op}
   end;

procedure cl_simpl!-bqua(f,knowl,n,sop);
   % Simplify bounded quantifier. Needs blackbox b2atl. Additional
   % idea: flag cl_simpl!-bqua1, such that the maybe expensive sat.
   % test is not performed the first time.
   begin scalar b,bl,w,m,newknowl;
      % [TV] [EQ]
      (if w then return w) where w=cl_simpl!-bqua!-tveq(f,knowl,n); 
      % [SB]
      b := rl_simpl(rl_b f,nil,-1);
      bl := rl_b2atl(b,rl_var f);
      if !*rlsiverbose then ioto_prin2 "[SB] ";
      % [SM]
      if !*rlsism then <<
	 newknowl := rl_smrmknowl(knowl,rl_var f);
	 newknowl := rl_smupdknowl('and,bl,newknowl,n);
      >> else newknowl := knowl;
      m := cl_simpl1(rl_mat f,newknowl,n-1,rl_op f);
      f := rl_mkbq(rl_op f,rl_var f,b,m);
      if !*rlsiverbose then ioto_prin2 "[SM] ";
      % [TV] [EQ]
      (if w then return w) where w=cl_simpl!-bqua!-tveq(f,knowl,n); 
      % [STRB]
      w := cl_simpl!-bqua!-strb(f,bl);
      if null w then return f;
      f := w;
      % [TV] [EQ]
      (if w then return w) where w=cl_simpl!-bqua!-tveq(f,knowl,n); 
      return f
   end;

procedure cl_simpl!-bqua!-tveq(f,knowl,n);
   begin scalar w;
      % [TV]
      (if w then return cl_simpl1(w,knowl,n-1,rl_op f))
	 where w=cl_simpl!-bqua!-tv f; 
      % [EQ]
      (if w then return cl_simpl1(w,knowl,n-1,rl_op f))
	 where w=cl_simpl!-bqua!-eq f;
      return nil
   end;

procedure cl_simpl!-bqua!-eq(f);
   % Simplification of bounded quantifiers, bound is an equation. [f]
   % is a bounded quantified fof. Returns a fof simpler than f (a
   % truth value or a formula in need of further simplificatio), or
   % nil (if no simplification was possible). Needs blackbox b2terml.
   begin scalar op,k,b,m,terml,satl;
      op := rl_op f;
      k := rl_var f;
      b := rl_b f;
      m := rl_mat f;
      % case the bound is an equation. (simplification later on) 
      if rl_op b eq 'equal then <<
	 terml := rl_b2terml(b,k);
	 if not null terml then <<
	    if !*rlsiverbose then ioto_prin2 {"[EQ:",car terml,"] "};
	    return cl_subfof({k . car terml },m)
	 >> else if null terml then << % atomic bound was not simplified
	    if !*rlsiverbose then ioto_prin2 {"[EQ->TV] "};
	    return cl_simpl!-bqua!-tv rl_mkbq(op,k,'false,m)
	 >> else
	    rederr "cl_simpl!-bqua!-eq: terml of length >= 2"
      >>;
      if !*rlsiverbose then ioto_prin2 {"[eq] "};
      return nil
   end;

procedure cl_simpl!-bqua!-tv(f);
   % Simplification of bounded quantifiers, cases where bound or
   % matrix is a truth value. [f] is a bounded quantified fof. Returns
   % a truth value or nil. Here we treat cases where we can get rid of
   % the bqua trivially.
   begin scalar op,x,bresult,result,satl,res;
      op := rl_op f; x := rl_var f; bresult := rl_b f; result := rl_mat f;
      % both result and bresult are truth values
      if op eq 'ball and (bresult eq 'false or result eq 'true) then
	 res := 'true
      else if op eq 'ball and (bresult eq 'true and result eq 'false) then
	 res := 'false
      else if op eq 'bex and (bresult eq 'true and result eq 'true) then
	 res := 'true
      else if op eq 'bex and (bresult eq 'false or result eq 'false) then
	 res := 'false
      % bresult is a truth value, but result isn't
      % further optimization for (*): occur check (maybe not wanted)
      else if op eq 'ball and bresult eq 'true then
	 res := rl_mkq('all,x,result) % (*)
      else if op eq 'ball and bresult eq 'false then
	 res := 'true % already considered
      else if op eq 'bex and bresult eq 'true then
	 res := rl_mkq('ex,x,result) % (*)
      else if op eq 'bex and bresult eq 'false then
	 res := 'false % already considered
      % result is a truth value, but bresult isn't
      % cases (**) are univariate QE problems maybe conservative check?
      else if op eq 'ball and result eq 'true then
	 res := 'true % already considered	       
      else if op eq 'ball and result eq 'false then
	 res := if rl_bsatp bresult then 'false else 'true 
      else if op eq 'bex and result eq 'true then 
	 res := if rl_bsatp bresult then 'true else 'false
      else if op eq 'bex and bresult eq 'false then
	 res := 'false; % already considered
      if res then << if !*rlsiverbose then ioto_prin2 "[TV] "; return res >>;
      % possibly remaining cases
      if !*rlsiverbose then ioto_prin2 "[tv] "; return nil
   end;   

procedure cl_simpl!-bqua!-strb(f,bl); %(b,fl,x,op);
   % Common logic strengthen bound. [f] is a b-q. fof, [bl] is a list
   % of atomic fof with $free(bl)={x}$ or an identifier $'unknown$.
   % Returns a fof or nil.
   begin scalar b,fl,x,op,cl,ncl,result,op2; % condition list
      b := rl_b f; x := rl_var f; op := rl_op f; result := rl_mat f;
      if bl eq 'unknown then bl := rl_b2atl(b,x);
      % [strengthen bound, part 1: if adequate, find op2 and fl]
      if rl_junctp rl_op result then op2 := rl_op result;
      if op2 and ((op eq 'bex and op2 eq 'and) or
      	 (op eq 'ball and op2 eq 'or)) then
	    fl := rl_argn result
      else
	 if cl_atfp result then fl := {result};
      % [strengthen bound, part 2: possibly redefine bresult and result]
      if fl then <<
      	 % split list into conditions and non-conditions for the bound
      	 for each a in fl do
	    if cl_atfp a and cl_fvarl a equal {x} then
	       cl := (if op eq 'bex then a else rl_negateat a) . cl
	    else
	       ncl := a . ncl;
	 %cl_ncl := cl_strb('dummy,fl,rl_var f,op);
	 result := if op2 then rl_smkn(op2,ncl)
	 else if ncl then car ncl
	 else (if op eq 'bex then 'true else 'false);
	 b := cl_simpl(cl_atl2b append(cl,bl),nil,-1);
      >>;
      if !*rlsiverbose then
	 if cl then ioto_prin2 "[STRB] " else ioto_prin2 "[strb] ";
      return if cl then rl_mkbq(op,x,b,result) else nil
   end;

procedure cl_negate!-invol(f);
   % Common logic negate applying the law of involutivity. [f] is a
   % formula. Returns $\phi$ if [f] is of the form $\lnot \phi$,
   % $\lnot [f]$ else.
   if rl_op f eq 'not then rl_arg1 f else rl_mk1('not,f);

procedure cl_gand!-col(fl,n,gand,knowl);
   % Common logic generic ['and] collect. [fl] is a list of formulas;
   % [n] is an integer; [gand] is one of ['and], ['or]; [knowl] is an
   % IRL. Depends on switch [!*rlsichk]. Returns a list $l$ of
   % simplified formulas such that $[gand](l)$ is equivalent to
   % $[gand]([fl])$. With [!*rlsichk] on, $l$ does not contain any
   % double entries. Moreover there are no truth values in $l$, and no
   % element of $l$ has [gand] as its top-level operator.
   begin scalar result,a,gtrue,gfalse;
      gtrue := cl_cflip('true,gand eq 'and);
      gfalse := cl_flip(gtrue);
      while fl do <<
	 a := cl_simpl1(car fl,knowl,n-1,gand);
	 fl := cdr fl;
	 if a eq gfalse then <<
	    result := {gfalse};
	    fl := nil
	 >> else if a neq gtrue then
	    if rl_op a eq gand then <<
	       if !*rlsichk then
		  for each subf in rl_argn a do
		     (if not (subf member result) then
			result := subf . result)
	       else
		  for each subf in rl_argn a do
		     result := subf . result
	    >> else
	       if not (!*rlsichk and a member result) then
		  result := a . result;
      >>;
      return if result then reversip result else {gtrue}
   end;

procedure cl_smsimpl!-junct(op,junct,knowl,n);
   % Common logic smart simplify. [op] is one of [and], [or]; [junct]
   % is a list of formulas; [knowl] is an IRL; [n] is an integer.
   % Returns a list of formulas. Accesses the switch [!*rlsism]. With
   % [!*rlsism] on sophisticated simplifications are applied to
   % [junct].
   begin scalar break,w,atl,col,newknowl;
      if not !*rlsism then
	 return cl_gand!-col(junct,n,op,nil);
      newknowl := rl_smcpknowl knowl;
      break := cl_cflip('false,op eq 'and);
      for each subf in junct do <<
	 w := if cl_atfp subf then cl_simplat(subf,op) else subf;
	 if cl_atfp w then atl := w . atl else col := w . col
      >>;
      newknowl := rl_smupdknowl(op,atl,newknowl,n);
      if newknowl eq 'false then return {break};
      return cl_smsimpl!-junct1(op,atl,reversip col,knowl,newknowl,n,break)
   end;

procedure cl_smsimpl!-junct1(op,atl,col,knowl,newknowl,n,break);
   % Common logic smart simplify. [op] is one of [and], [or]; [atl] is
   % a list of atomic formulas; [col] is a list of complex formulas;
   % [knowl] and [newknowl] are IRL's; [n] is an integer; [break] is
   % one of [true], [false] corresponding to [op]. Returns a list of
   % formulas.
   begin scalar a,w,wop,argl,sicol,natl;
      while col do <<
	 a := car col;
	 col := cdr col;
	 w := cl_simpl1(a,newknowl,n-1,op);
	 wop := rl_op w;
	 if wop eq break then <<
	    a := break;
	    col := nil
	 >> else if wop eq op then <<
	    argl := rl_argn w;
	    while argl and cl_atfp car argl do <<
	       natl := car argl . natl;
	       argl := cdr argl
	    >>;
	    if !*rlsiidem and natl then <<
	       col := nconc(reversip sicol,col);
	       sicol := nil
	    >>;
	    sicol := nconc(sicol,reverse argl)  % necessarily constructive!
	 >> else if rl_cxp wop then
	    (if wop neq cl_flip break then sicol := w . sicol)
	 else <<  % [w] is atomic.
	    if !*rlsiidem then <<
	       col := nconc(reversip sicol,col);
	       sicol := nil
	    >>;
	    natl := {w}
	 >>;
	 if natl then <<
	    newknowl := rl_smupdknowl(op,natl,newknowl,n);
	    if newknowl eq 'false then <<
	       a := break;
	       col := nil
	    >>;
	    natl := nil
	 >>
      >>;
      if a eq break then return {break};
      return cl_smsimpl!-junct2(op,sicol,knowl,newknowl,n,break)
   end;

procedure cl_smsimpl!-junct2(op,sicol,knowl,newknowl,n,break);
   % Common logic smart simplify. [op] is one of [and], [or]; [col] is
   % a list of complex formulas; [knowl] and [newknowl] are IRL's; [n]
   % is an integer; [break] is one of [true], [false] corresponding to
   % [op]. Returns a list of formulas.
   begin scalar atl,w;
      atl := rl_smmkatl(op,knowl,newknowl,n);
      if !*rlsichk then <<
      	 w := sicol;
	 sicol := nil;
	 for each x in w do sicol := lto_insert(x,sicol)
      >> else
	 sicol := reversip sicol;
      if !*rlsiso then atl := sort(atl,'rl_ordatp);
      w := nconc(atl,sicol);
      if w then return w;
      return {cl_flip break}
   end;

procedure cl_smsimpl!-imprep(prem,concl,knowl,n);
   % Common logic smart simplify implication/replication. [prem] and
   % [concl] are formulas; [knowl] is an IRL; [n] is an integer.
   % Returns a formula equivalent to [prem impl concl] assuming
   % [knowl].
   begin
      if not !*rlsism then
	 return cl_imprep!-col(prem,concl,knowl,n);
      if cl_atfp prem then
 	 prem := cl_simplat(prem,'prem);
      if cl_atfp concl then
 	 concl := cl_simplat(concl,'concl);
      if prem eq 'false or concl eq 'true then
      	 return 'true;
      return cl_smsimpl!-imprep1(prem,concl,knowl,n)
   end;

procedure cl_imprep!-col(prem,concl,knowl,n);
   begin scalar w;
      prem := cl_simpl1(prem,knowl,n-1,'prem);
      concl := cl_simpl1(concl,knowl,n-1,'concl);
      if w := cl_smtvchk!-impl(prem,concl) then
	 return w;
      if prem = concl then return 'true;
      return rl_mk2('impl,prem,concl)
   end;

procedure cl_smsimpl!-imprep1(prem,concl,knowl,n);
   % Common logic smart simplify implication/replication. [prem] and
   % [concl] are formulas; [knowl] is an IRL; [n] is an integer.
   % Returns a formula equivalent to [prem impl concl] assuming
   % [knowl].
   begin scalar w;
      if cl_atfp prem then
 	 return cl_smsimpl!-imprep!-atprem(prem,concl,knowl,n);
      if cl_atfp concl then
 	 return cl_smsimpl!-imprep!-atconcl(prem,concl,knowl,n);
      prem := cl_simpl1(prem,knowl,n-1,'prem);
      concl := cl_simpl1(concl,knowl,n-1,'concl);
      if w := cl_smtvchk!-impl(prem,concl) then
	 return w;
      if cl_cxfp prem and cl_cxfp concl then <<
	 if !*rlsichk and prem = concl then
	    return 'true;
	 return rl_mk2('impl,prem,concl)
      >>;
      return cl_smsimpl!-imprep1(prem,concl,knowl,n)
   end;

procedure cl_smtvchk!-impl(prem,concl);
   if prem eq 'true then
      concl
   else if concl eq 'false then
      cl_simpl(rl_mk1('not,prem),nil,1)
   else if prem eq 'false or concl eq 'true then
      'true;

procedure cl_smsimpl!-imprep!-atprem(atprem,concl,knowl,n);
   begin scalar w,newknowl;
      newknowl := rl_smcpknowl knowl;
      if cl_atfp concl then
	 return rl_smsimpl!-impl(atprem,concl,knowl,newknowl,n);
      newknowl := rl_smupdknowl('and,{atprem},newknowl,n);
      if newknowl eq 'false then
	 return 'true;
      concl := cl_simpl1(concl,newknowl,n-1,'concl);
      if w := cl_smtvchk!-impl(atprem,concl) then
	 return w;
      if cl_atfp concl then
	 return rl_smsimpl!-impl(atprem,concl,knowl,newknowl,n);
      return rl_mk2('impl,atprem,concl)
   end;

procedure cl_smsimpl!-imprep!-atconcl(prem,atconcl,knowl,n);
   % CL smart simplify implication/replication with atomic formula
   % conclusion. [prem] is a complex formula; [atconcl] is a
   % simplified atomic formula; [knowl] is an IRL; [n] is an integer.
   % Returns a formula.
   begin scalar w,newknowl;
      newknowl := rl_smupdknowl('or,{atconcl},rl_smcpknowl knowl,n);
      if newknowl eq 'false then
	 return 'true;
      prem := cl_simpl1(prem,newknowl,n-1,'prem);
      if w := cl_smtvchk!-impl(prem,atconcl) then
	 return w;
      if cl_atfp prem then
	 return rl_smsimpl!-impl(prem,atconcl,knowl,newknowl,n);
      return rl_mk2('impl,prem,atconcl)
   end;

procedure cl_smtvchk!-equiv(lhs,rhs);
   if lhs eq 'true then
      rhs
   else if rhs eq 'true then
      lhs
   else if lhs eq 'false then
      cl_simpl(rl_mk1('not,rhs),nil,1)
   else if rhs eq 'false then
      cl_simpl(rl_mk1('not,lhs),nil,1);

procedure cl_smsimpl!-equiv(lhs,rhs,knowl,n);
   begin scalar w,newknowl;
      lhs := cl_simpl1(lhs,knowl,n-1,'equiv);
      rhs := cl_simpl1(rhs,knowl,n-1,'equiv);
      if w := cl_smtvchk!-equiv(lhs,rhs) then
	 return w;
      if !*rlsichk and lhs = rhs then
 	 return 'true;
      if null !*rlsism or cl_cxfp lhs or cl_cxfp rhs then <<
      	 if cl_ordp(lhs,rhs) then
 	    return rl_mk2('equiv,lhs,rhs);
      	 return rl_mk2('equiv,rhs,lhs)
      >>;
      newknowl := rl_smcpknowl(knowl);
      return rl_smsimpl!-equiv1(lhs,rhs,knowl,newknowl,n)
   end;

procedure cl_ordp(f1,f2);
   % Common logic order predicate. [f1] and [f2] are formulas. Returns
   % [T] or [nil]. [nil] is returned if [f1] and [f2] are atomic
   % formulas and [f1] is less than [f2] wrt. [rl_ordatp].
   cl_cxfp f2 or (cl_atfp f1 and rl_ordatp(f1,f2));

procedure cl_simplat(atf,sop);
   % Common logic simplify atomic formula. [atf] is an atomic formula;
   % [sop] is a CL operator. Returns a quantifier-free formula
   % equivalent to [atf].
   if not !*rlidentify then
      rl_simplat1(atf,sop)
   else
      cl_apply2ats(rl_simplat1(atf,sop),'cl_identifyat);

procedure cl_identifyat(atf);
   % Common logic identify atomic formula. [atf] is an atomic formula.
   % Returns an atomic formula equal to [atf].
   begin scalar w;
      if rl_tvalp atf then return atf;
      if (w := atf member cl_identify!-atl!*) then return car w;
      cl_identify!-atl!* := atf . cl_identify!-atl!*;
      return atf
   end;

% The following code implements a "generic smart simplification". All
% black boxes for the smart simplification are implemented generically
% using only a non generic black box rl_negateat. rl_negateat must
% return an atomic formula.

procedure cl_smcpknowl(knowl);
   % Common logic smart simplifier copy knowledge. [knowl] is a
   % knowledge base. Returns a toplevel copy of [knowl].
   for each p in knowl collect p;

procedure cl_smrmknowl(knowl,v);
   % Common logic smart simplifier remove knowledge. [knowl] is a
   % knowledge base; [v] is a variable. Returns a knowledge base.
   % Removes all knowledge involving [v] from the knowledge base.
   nil;

procedure cl_smupdknowl(op,atl,knowl,n);
   % Common logic smart simplifier update knowledge. [op] is one of
   % the operators [and], [or]; [atl] is a list of atomic formulas;
   % [knowl] is knowledge base; [n] is an integer. Returns a knowledge
   % base. If [op] is [and], then all knowledge in [atl] is added to
   % the [knowl] with the tag [n]. If [op] is [or], then the negation
   % of all knowledge in [atl] is added to [knowl].
   begin scalar at;
      while atl do <<
	 at := car atl;
	 atl := cdr atl;
      	 knowl := cl_smupdknowl1(op,at,knowl,n);
	 if knowl eq 'false then <<
	    atl := nil;
	    at := 'break
	 >>
      >>;
      if at eq 'break then
	 return 'false
      else
      	 return knowl
   end;

procedure cl_smupdknowl1(op,at,knowl,n);
   begin scalar ent,contra;
      if op eq 'or then <<
      	 ent := rl_negateat at;
      	 contra := at
      >> else <<
      	 ent := at;
      	 contra := rl_negateat at
      >>;
      if assoc(contra,knowl) then
	 return 'false;
      if assoc(ent,knowl) then
	 return knowl;
      return knowl := (ent . n) . knowl
   end;

procedure cl_smmkatl(op,knowl,newknowl,n);
   % Common logic smart simplifier make atomic formula list. [op] is
   % one of the operators [and], [or]; [knowl], [newknowl] are
   % knowledge bases; [n] is an integer. Returns a list of atomic
   % formulas. All knowledge tagged with [n] is extraced from
   % [newknowl] and returned as a list of atomic formulas.
   begin scalar res;
      res := for each pair in newknowl join
	 if cdr pair = n then {car pair};
      if op eq 'or then
      	 res := for each at in res collect rl_negateat at;
      return res
   end;

procedure cl_smsimpl!-impl(atprem,atconcl,oldknowl,newknowl,n);
   % Common logic smart simplifier simplify implication. [atprem] and
   % [atconcl] are atomic formulas; [oldknowl] and [newknowl] are
   % knowledge bases; [n] is an integer. Returns a formula.
   begin scalar w;
      w := cl_simpl1(rl_nnf rl_mk2('impl,atprem,atconcl),oldknowl,n,nil);
      if rl_tvalp w or cl_atfp w then
 	 return w;
      atprem := cl_simpl1(atprem,oldknowl,n,'prem);
      atconcl := cl_simpl1(atconcl,oldknowl,n,'concl);
      return rl_mk2('impl,atprem,atconcl)
   end;

procedure cl_smsimpl!-equiv1(lhs,rhs,oldknowl,newknowl,n);
   % Common logic smart simplifier simplify equivalence. [lhs] and
   % [rhs] are atomic formulas; [oldknowl] and [newknowl] are
   % knowledge bases; [n] is an integer. Returns a formula.
   begin scalar w,x;
      w := cl_simpl1(rl_nnf rl_mk2('equiv,lhs,rhs),oldknowl,n,nil);
      if rl_tvalp w or cl_atfp w then
 	 return w;
      x := rl_argn w;
      if cl_atfp car x and cl_atfp cadr x and null cddr x then
	 return w;
      lhs := cl_simpl1(lhs,oldknowl,n,'equiv);
      rhs := cl_simpl1(rhs,oldknowl,n,'equiv);
      if cl_ordp(lhs,rhs) then
	 return rl_mk2('equiv,lhs,rhs);
      return rl_mk2('equiv,rhs,lhs)
   end;

procedure cl_siaddatl(atl,c);
   % Common logic simplifying add atomic formula list. [atl] is a list
   % of atomic formulas; [c] is [true], a simplified atomic formula,
   % or a simplified conjunction of atomic formulas. Returns [true],
   % [false], a simplified atomic formula, or a simplified conjunction
   % of atomic formulas. The result is equivalent to $\bigwedge [atl]
   % \land [c]$.
   begin scalar w,sicd;
      atl := cl_sitheo atl;
      if atl eq 'inctheo then
	 return 'false;
      sicd := if c eq 'true then
 	 nil
      else if cl_cxfp c then
 	 rl_argn c
      else
	 {c};
      w := rl_smupdknowl('and,nconc(atl,sicd),nil,1);
      if w eq 'false then
 	 return 'false;
      w := rl_smmkatl('and,nil,w,1);
      if !*rlsiso then w := sort(w,'rl_ordatp);
      return rl_smkn('and,w)
   end;

%DS
% <KNOWL> ::= (...,<LAT>,...)
% <LAT> ::= (<ATOMIC FORMULA> . <LABEL>)
% <LABEL> ::= <INTEGER> | ['ignore]

procedure cl_susimkatl(op,knowl,newknowl,n);
   % Common logic susi make atomic formula list. [op] is one of the
   % operators [and], [or]; [knowl], [newknowl] are KNOWL's; [n] is an
   % integer. Returns an list $L$ of atomic formulas. All knowledge
   % tagged with [n] is extraced from [newknowl] into $L$.
   begin scalar res;
      res := for each pair in newknowl join
	 if cdr pair = n then {car pair};
      if null res then return nil;
      res := rl_susipost(res,knowl);  % TRUE | FALSE | INCTHEO | atl
      if rl_tvalp res then
	 return {cl_cflip(res,op eq 'and)};
      if res eq 'inctheo then 	              % Das hatte man auch frueher
	 return cl_cflip('false,op eq 'and);  % wissen koennen.
      if op eq 'or then
      	 res := for each at in res collect rl_negateat at;
      res := for each at in res collect rl_susitf(at,knowl);
      return res
   end;

procedure cl_susicpknowl(knowl);
   % Common logic susi copy knowledge. [knowl] is a KNOWL. Returns a
   % KNOWL. Copies the toplevel and the LAT's of [knowl].
   for each p in knowl collect (car p . cdr p);

procedure cl_susiupdknowl(op,atl,knowl,n);
   % Common logic susi update knowledge. [op] is one of the operators
   % [and], [or]; [atl] is a list of (simplified) atomic formulas;
   % [knowl] is a KNOWL; [n] is the current level. Returns a KNOWL.
   % Destructively updates [knowl] wrt. the [atl] information.
   begin scalar at;
      while atl do <<
	 at := car atl;
	 atl := cdr atl;
      	 knowl := cl_susiupdknowl1(op,at,knowl,n);
	 if knowl eq 'false then <<
	    atl := nil;
	    at := 'break
	 >>
      >>;
      if at eq 'break then
	 return 'false
      else
      	 return knowl
   end;

procedure cl_susiupdknowl1(op,at,knowl,n);
   % Common logic susi update knowledge subroutine. [op] is one of
   % [and], [or]; [at] is a (simplified) atomic formula; [knowl] is a
   % KNOWL; [n] is the current level. Returns a KNOWL. Destructively
   % updates [knowl] wrt. [at].
   if op eq 'and then
      cl_susiupdknowl2((at . n),knowl,n)
   else % We know [op eq 'or]
      cl_susiupdknowl2(((rl_negateat at) . n),knowl,n); 

procedure cl_susiupdknowl2(lat,knowl,n);
   % Common logic susi update knowledge subroutine. [lat] is a LAT;
   % [knowl] is a KNOWL; [n] is the current level. Returns a KNOWL.
   % Destructively updates [knowl] wrt. [lat].
   begin scalar a,w,sck,ignflg,delflg,addl;
      sck := knowl;
      while sck do <<
	 a := car sck;
	 sck := cdr sck;
	 w := rl_susibin(a,lat); % 'true | 'false | nil | {commands,...}
	 if w eq 'false then  % What happens with atoms neq false ???
	    sck := nil
	 else <<
	    w := cl_susiinter(w,knowl,a);
	    addl := nconc(addl,cadr w);
	    knowl := car w;
	    if caddr w then
	       ignflg := T;
	    if cadddr w then <<
	       delflg := T;
	       sck := nil
	    >>
	 >>
      >>;
      if w eq 'false then return 'false;
      if null delflg then <<
	 if ignflg then cdr lat := 'ignore;
	 knowl := lat . knowl
      >>;
      while addl do <<
	 knowl := cl_susiupdknowl2(car addl,knowl,n);
	 if knowl eq 'false then
	    addl := nil
	 else
	    addl := cdr addl
      >>;
      return knowl;
   end;

procedure cl_susiinter(prg,knowl,a);
   % Common logic susi interpreter. [prg] is a SUSIPRG; [knowl] is a
   % KNOWL; [a] is a LAT. Returns a list
   % $(\kappa,\alpha,\iota,\delta)$, where $\kappa$ and $\alpha$ are
   % KNOWL's; $\iota$ and $\delta$ are flags.
   begin scalar addl,ignflg,delflg;
      for each p in prg do
	 if car p eq 'delete or car p eq 'ignore then
%      	 if car p eq 'ignore then   % We ignore ['ignore]!
%	    if cdr p then
%	       ignflg := T
%	    else
%	       cdr a := 'ignore
%      	 else if car p eq 'delete then
	    if cdr p then
	       delflg := T
	    else
	       knowl := delqip(a,knowl)
      	 else if car p eq 'add then
	    addl := cdr p . addl;
     return {knowl,addl,ignflg,delflg}
   end;

procedure cl_susiminlevel(l1,l2);
   if l1 eq 'ignore then l2 else if l2 eq 'ignore then l1 else min(l1,l2);

endmodule;  % [clsimpl]

end;  % of file
