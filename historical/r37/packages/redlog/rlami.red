% ----------------------------------------------------------------------
% $Id: rlami.red,v 1.18 1999/03/23 09:23:55 dolzmann Exp $
% ----------------------------------------------------------------------
% Copyright (c) 1995-1999 Andreas Dolzmann and Thomas Sturm
% ----------------------------------------------------------------------
% $Log: rlami.red,v $
% Revision 1.18  1999/03/23 09:23:55  dolzmann
% Changed copyright information.
%
% Revision 1.17  1999/03/22 08:07:56  sturm
% Turned error message "select a language" in into "select a context".
%
% Revision 1.16  1999/03/21 13:39:44  dolzmann
% Modified procedure rl_qvarchk: Reserved identifiers are not allowed
% as quantified variables.
%
% Revision 1.15  1997/08/14 10:10:46  sturm
% Renamed rldecdeg to rldecdeg1.
% Added service rldecdeg.
%
% Revision 1.14  1997/08/13 12:45:46  dolzmann
% Added procedure rl_s2a!-decdeg.
%
% Revision 1.13  1997/08/12 17:03:54  sturm
% Fixed fancy printing for Xr and PC versions.
%
% Revision 1.12  1996/10/17 13:52:23  sturm
% Introduced services rlvarl, rlfvarl, and rlbvarl. Renamed cl_varl to
% cl_varl1 for this.
%
% Revision 1.11  1996/10/07 12:03:54  sturm
% Added fluids for CVS and copyright information.
%
% Revision 1.10  1996/10/03 16:07:04  sturm
% Modified error message in rl_s2a!-struct.
%
% Revision 1.9  1996/10/01 10:25:18  reiske
% Introduced new service rltnf and related code.
%
% Revision 1.8  1996/09/29 14:21:28  sturm
% Removed switch rlqeans. Introduced service rlqea instead.
% Also introduced corresponding service rlgqea.
%
% Revision 1.7  1996/09/26 11:51:09  dolzmann
% Do not use T as formal parameter.
%
% Revision 1.6  1996/09/05 11:16:48  dolzmann
% Added procedures rl_cleanup, rl_a2s!-id, rl_s2a!-term, and rl_s2a!-struct.
% Renamed procedure rl_a2s!-terml to rl_s2a!-struct.
%
% Revision 1.5  1996/07/02 15:12:28  sturm
% Fixed a bug in length computation.
%
% Revision 1.4  1996/06/05 15:11:25  sturm
% Added procedure rl_sub!*fof.
%
% Revision 1.3  1996/05/21 17:12:34  sturm
% Removed rl_subfof. Substitution code has moved to cl.
%
% Revision 1.2  1996/05/12 08:28:23  sturm
% Added procedures rl_s2a!-gqe and rl_s2a!-atl.
%
% Revision 1.1  1996/03/22 12:18:27  sturm
% Moved and split.
%
% ----------------------------------------------------------------------
lisp <<
   fluid '(rl_ami_rcsid!* rl_ami_copyright!*);
   rl_ami_rcsid!* :=
      "$Id: rlami.red,v 1.18 1999/03/23 09:23:55 dolzmann Exp $";
   rl_ami_copyright!* := "Copyright (c) 1995-1999 by A. Dolzmann and T. Sturm"
>>;

module rlami;
% Reduce logic component algebraic mode interface. Submodule of [redlog].

procedure rl_mk!*fof(u);
   % Reduce logic make tagged form of first-order formula. [u] is a
   % first-order formula. Returns pseudo Lisp prefix of [u]. This is
   % analogous to [mk!*sq] in [alg.red].
   rl_mk!*fof1 rl_csimpl u;

procedure rl_mk!*fof1(u);
   % Reduce logic make tagged form of first-order formula subroutine.
   % [u] is a first-order formula. Returns pseudo Lisp prefix of [u].
   % This is analogous to [mk!*sq] in [alg.red].
   if u eq 'true or u eq 'false then
      mk!*sq simp u
   else if eqcar(u,'equal) then
      rl_prepfof1 u
   else
      '!*fof . rl_cid!* . u . if !*resubs then !*sqvar!* else {nil};

procedure rl_reval(u,v);
   % Reduce logic [reval]. [u] is a formula in some mixed pseudo Lisp
   % prefix form where [car u] is either ['!*fof] or a first-order
   % operator; [v] is bool. Returns Lisp prefix of [u] in case [v] is
   % non-[nil], and pseudo Lisp prefix of [u] else.
   if v then rl_prepfof rl_simp1 u else rl_mk!*fof rl_simp1 u;

procedure rl_csimpl(u);
   % Conditional simplify.
   if !*rlsimpl and getd 'rl_simpl then %???
      rl_simpl(u,{},-1)
   else
      u;

procedure rl_prepfof(f);
   % [prep] first-order formula.
   rl_prepfof1 rl_csimpl f;

procedure rl_prepfof1(f);
   % [prep] first-order formula subroutine.
   begin scalar op;
      op := rl_op f;
      if rl_tvalp op then
 	 return op;
      if rl_quap op then
	 return {op,rl_var f,rl_prepfof1 rl_mat f};
      if rl_cxp op then
	 return op . for each x in rl_argn f collect rl_prepfof1 x;
      % [f] is atomic.
      return apply(get(rl_cid!*,'rl_prepat),{f})
   end;

procedure rl_cleanup(u,v);
   reval1(u,v);

procedure rl_simp(u);
   % [simp] first-order formula.
   rl_csimpl rl_simp1 u;

procedure rl_simp1(u);
   % Reduce logic [simp]. [u] is (pseudo) Lisp prefix of a formula.
   % Returns the formula encoded by [u].
   begin scalar w;
      if null rl_cid!* then rederr {"select a context"};
      if atom u then
 	 return rl_simpatom u;
      argnochk u;
      if (w := get(car u,'rl_simpfn)) then
 	 return if flagp(w,'full) then apply(w,{u}) else apply(w,{cdr u});
      if (w := get(car u,get(rl_cid!*,'simpfnname))) then
	 return if flagp(w,'full) then apply(w,{u}) else apply(w,{cdr u});
      if (w := get(car u,'psopfn)) then
 	 return rl_simp1 apply1(w,cdr u);
      if flagp(car u,'opfn) then
	 return rl_simp1 apply(car u,for each x in cdr u collect reval x);
      if (w := get(car u,'prepfn2)) then
 	 return rl_simp1 apply(w,{u});
      rl_redmsg(car u,"predicate");
      put(car u,get(rl_cid!*,'simpfnname),get(rl_cid!*,'simpdefault));
      return rl_simp1(u)
   end;

procedure rl_simpatom(u);
   % Reduce logic simp atom. [u] is an atom.
   begin scalar w;
      if null u then typerr("nil","logical");
      if numberp u then typerr({"number",u},"logical");
      if stringp u then typerr({"string",u},"logical");
      if (w := rl_gettype(u)) then <<
	 if w eq 'logical or w eq 'equation or w eq 'scalar then
	    return rl_simp1 cadr get(u,'avalue);
	 typerr({w,u},"logical")
      >>;
      % [u] algebraically unbound.
      if rl_tvalp u then return u;
      if boundp u then return rl_simp1 eval u;
      typerr({"unbound id",u},"logical")
   end;

procedure rl_simpbop(f);
   % Reduce logic simp boolean operator.
   rl_mkn(car f,for each x in cdr f collect rl_simp1 x);

procedure rl_simpq(f);
   % Reduce logic simp quantifier.
   begin scalar vl,w;
      vl := reval cadr f;
      if eqcar(vl,'list) then
	 vl := cdr vl
      else
	 vl := {vl};
      w := rl_simp1 caddr f;
      for each x in reverse vl do <<
      	 rl_qvarchk x;
	 w := rl_mkq(car f,x,w)
      >>;
      flag(vl,'used!*);
      return w
   end;

procedure rl_qvarchk(v);
   % Syntax-check quantified variable.
   if null v then
      typerr("nil","quantified variable")
   else if numberp v then
      typerr({"number",v},"quantified variable")
   else if stringp v then
      typerr({"string",v},"quantified variable")
   else if pairp v then
      typerr({"complex expression",v},"quantified variable")
   else if idp v and flagp(v,'reserved) then
      typerr({"reserved identifier",v},"quantified variable");

procedure rl_simp!*fof(u);
   % Reduce logic simp [!*fof] operator. [u] is of the form
   % $([tag],f,[!*sqvar!*])$ where [tag] is a context tag and $f$ is a
   % formula.
   begin scalar tag,f,w;
      if caddr u then return cadr u;  % [!*sqvar!*=T]
      tag := car u;
      f := cadr u;
      if tag neq rl_cid!* then <<
	 w := rl_set {tag} where !*msg=nil;
	 f := rl_prepfof f;
	 rl_set w where !*msg=nil;
	 return rl_simp f
      >>;
      return rl_resimp f
   end;

procedure rl_resimp(u);
   % Reduce logic resimp. [u] is a formula.
   begin scalar op,w;
      op := rl_op u;
      if rl_tvalp op then
	 return u;
      if rl_quap op then <<
      	 if (w := rl_gettype(rl_var u)) then
 	    typerr({w,rl_var u},"quantified variable");
      	 return rl_mkq(op,rl_var u,rl_resimp rl_mat u)
      >>;
      if rl_cxp op then
	 return rl_mkn(op,for each x in rl_argn u collect rl_resimp x);
      return apply(get(rl_cid!*,'rl_resimpat),{u})
   end;

procedure rl_gettype(v);
   % Get type. Return type information if present. Handle scalars
   % properly.
   (if w then car w else get(v,'rtype)) where w = get(v,'avalue);

procedure rl_redmsg(u,v);
   % Reduce msg. [u] is an identifier, [v] is a category which must be
   % "predicate". Ask for declaring [u] predicate.
   if null !*msg or v neq "predicate" then
      nil  % :-)
   else if terminalp() then
      yesp list("Declare",u,v,"?") or error1()
   else
      lprim list(u,"declared",v);

procedure rl_lengthlogical(u);
   rl_lengthfof rl_simp u;

procedure rl_lengthfof(f);
   % First order formula length. [u] is a formula. Returns the number
   % of top-level constituents of [u].
   begin scalar op;
      op := rl_op f;
      if rl_tvalp op then
	 return 1;
      if rl_quap op then
	 return 2;
      if rl_cxp op then
	 return length rl_argn f;
      % [f] is atomic.
      return apply(get(rl_cid!*,'rl_lengthat),{f})
   end;

procedure rl_sub!*fof(al,f);
   rl_mk!*fof rl_subfof(al,rl_simp f);

procedure rl_print!*fof(u);
   maprin reval u;

procedure rl_priq(qf);
   begin scalar m;
      if null !*nat then return 'failed;
      maprin car qf;
      prin2!* " ";
      maprin cadr qf;
      prin2!* " ";
      if pairp(m := caddr qf) and car m memq '(ex all) then
	 maprin m
      else <<
	 prin2!* "(";
 	 maprin m;
 	 prin2!* ")"
      >>
   end;

procedure rl_ppriop(f,n);
   if null !*nat or null !*rlbrop or eqn(n,0) then
      'failed
   else <<
      prin2!* "(";
      inprint(car f,get(car f,'infix),cdr f);
      prin2!* ")"
   >>;

procedure rl_fancy!-ppriop(f,n);
   if null !*nat or null !*rlbrop or eqn(n,0) then
      'failed
   else <<
      fancy!-prin2 "(";
      fancy!-inprint(car f,get(car f,'infix),cdr f);
      fancy!-prin2 ")"
   >>;

procedure rl_fancy!-priq(qf);
   begin scalar m;
      if null !*nat then return 'failed;
      fancy!-prefix!-operator car qf;
      fancy!-prin2 " ";
      maprin cadr qf;
      fancy!-prin2 " ";
      if pairp(m := caddr qf) and car m memq '(ex all) then
	 maprin m
      else <<
	 fancy!-prin2 "(";
 	 maprin m;
 	 fancy!-prin2 ")"
      >>
   end;

procedure rl_interf1(fname,evalfnl,oevalfnl,odefl,resconv,argl);
   begin integer l1,l2,l3; scalar w;
      if null eval intern compress nconc(explode fname,'(!! !*)) then
	 rederr {"service",fname,"not implemented in context",rl_cid!*};
      l1 := length argl;
      l2 := length evalfnl;
      l3 := length oevalfnl;
      if l1 < l2 or l1 > l2 + l3 then
      	 rederr {fname,"called with",l1,"arguments instead of",l2,"-",l2+l3};
      argl := for each x in append(evalfnl,oevalfnl) collect <<
	 if argl then <<
	    w := car argl;
	    argl := cdr argl
	 >> else
	    w := car odefl;
	 if l2 = 0 then  % evaluation of optional parameters
	    odefl := cdr odefl
	 else
	    l2 := l2 - 1;
	 apply(x,{w})
      >>;
      if !*rlrealtime then ioto_realtime();
      w := apply(resconv,{apply(fname,argl)});
      if !*rlrealtime then ioto_tprin2t {"Realtime: ",ioto_realtime()," s"};
      return w
   end;

procedure rl_a2s!-decdeg1(u);
   if u eq 'fvarl then 'fvarl else rl_a2s!-varl u;

procedure rl_a2s!-varl(l);
   begin scalar w;
      w := reval l;
      if not eqcar(w,'list) then typerr(w,"list");
      w := cdr w;
      for each x in w do
	 if not idp x then typerr(x,"variable");
      return w
   end;

procedure rl_a2s!-number(n);
   % Algebraic to symbolic number.
   begin
      n := reval n;
      if not numberp n then typerr(n,"number");
      return n
   end;

procedure rl_a2s!-id(k);
   % Algebraic to symbolic identifier
   begin
      k := reval k;
      if not idp k then typerr(k,"identifier");
      return k
   end;

procedure rl_a2s!-atl(l);
   % Algebraic to symbolic atomic formula list.
   begin scalar w,!*rlsimpl;
      l := reval l;
      if not eqcar(l,'list) then
 	 typerr(l,"list");
      return for each x in cdr l collect <<
	 if rl_cxp rl_op (w := rl_simp x) then
	    typerr(x,"atomic formula");
      	 w
      >>
   end;

procedure rl_a2s!-posf(f);
   % Algebraic to symbolic positive formula.
   rl_nnf rl_simp f;

procedure rl_s2a!-simpl(f);
   if f eq 'inctheo then rederr "inconsistent theory" else rl_mk!*fof f;

procedure rl_s2a!-gqe(res);
   if res eq 'inctheo then
      rederr "inconsistent theory"
   else
      {'list,rl_s2a!-atl car res,rl_mk!*fof cdr res};

procedure rl_s2a!-gqea(res);
   if res eq 'inctheo then
      rederr "inconsistent theory"
   else
      {'list,rl_s2a!-atl car res,rl_s2a!-qea cdr res};

procedure rl_s2a!-qea(res);
   if res eq 'inctheo then
      rederr "inconsistent theory"
   else
      'list . for each x in res collect
 	 {'list,rl_mk!*fof car x,'list . cadr x};

procedure rl_s2a!-opt(res);
   if res eq 'infeasible then
      'infeasible
   else
      {'list,mk!*sq car res,'list . for each x in cadr res collect 'list . x};

procedure rl_s2a!-atl(l);
   'list . for each x in l collect rl_mk!*fof x;

procedure rl_s2a!-ml(ml,s2acar);
   'list . for each p in ml collect {'list,apply(s2acar,{car p}),cdr p};

procedure rl_s2a!-term(u);
   apply(get(rl_cid!*,'rl_prepterm),{u});

procedure rl_s2a!-decdeg1(p);
   begin scalar w;
      w := if cdr p then
	 for each x in cdr p collect {'list,car x,cdr x}
      else
	 nil;
      return {'list,rl_mk!*fof car p,'list . w}
   end;

procedure rl_a2s!-targfn(x);
   begin scalar w;
      w := simp x;
      if not domainp denr w then
      	 rederr {"variable in target function denominator"};
      return w
   end;

procedure rl_a2s!-terml(l);
   begin scalar w;
      w := reval l;
      if not eqcar(w,'list) then
         typerr(l,"list");
      return for each x in cdr w collect
         apply(get(rl_cid!*,'rl_simpterm),{x})
   end;

procedure rl_s2a!-terml(l);
   'list . for each u in l collect apply(get(rl_cid!*,'rl_prepterm),{u});

procedure rl_a2s!-term(l);
   apply(get(rl_cid!*,'rl_simpterm),{l});

procedure rl_s2a!-varl(pr);
   {'list,'list . car pr,'list . cdr pr};

procedure rl_s2a!-fbvarl(l);
   'list . l;

procedure rl_s2a!-struct(l);
   <<
      for each x in cdr l do
	 if get(cdr x,'avalue) then
	    rederr {"identifier",cdr x,"has an avalue"};
      {'list, rl_mk!*fof car l,
      	 'list . for each x in cdr l collect
      	    {'equal,cdr x,prepf car x}}
   >>;

foractions!* := 'mkand . 'mkor . foractions!*;
deflist('((mkand rlmkand) (mkor rlmkor)),'bin);
deflist('((mkand (quote true)) (mkor (quote false))),'initval);

symbolic operator rlmkor,rlmkand;

procedure rlmkor(a,b);
   if !*mode eq 'symbolic then
      rederr "`mkor' invalid in symbolic mode"
   else <<
      if null a then a := 'false;
      if null b then b := 'false;
      a := if eqcar(a,'or) then cdr a else {a};
      b := if eqcar(b,'or) then cdr b else {b};
      'or . nconc(b,a)
   >>;

procedure rlmkand(a,b);
   if !*mode eq 'symbolic then
      rederr "`mkand' invalid in symbolic mode"
   else <<
      if null a then a := 'true;
      if null b then b := 'true;
      a := if eqcar(a,'and) then cdr a else {a};
      b := if eqcar(b,'and) then cdr b else {b};
      'and . nconc(b,a)
   >>;

endmodule;  % [rlami]

end;  % of file
