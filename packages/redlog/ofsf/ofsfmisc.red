% ----------------------------------------------------------------------
% $Id: ofsfmisc.red,v 1.16 2008/08/24 05:28:13 sturm Exp $
% ----------------------------------------------------------------------
% Copyright (c) 1995-1999 Andreas Dolzmann and Thomas Sturm
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

% $Log: ofsfmisc.red,v $
% Revision 1.16  2008/08/24 05:28:13  sturm
% Admit substitution of parametric denominators.
%
% Revision 1.15  2006/08/02 08:12:38  sturm
% Added module clresolv.
%
% Revision 1.14  2002/08/23 08:44:40  dolzmann
% Minor code cosmetic.
%
% Revision 1.13  1999/04/01 11:25:56  dolzmann
% Added and corrected comments.
%
% Revision 1.12  1999/03/23 07:41:38  dolzmann
% Changed copyright information.
%
% Revision 1.11  1997/08/24 16:18:51  sturm
% Added service rl_surep with black box rl_multsurep.
% Added service rl_siaddatl.
%
% Revision 1.10  1996/10/23 11:17:45  dolzmann
% Corrected comments.
%
% Revision 1.9  1996/10/07 12:03:26  sturm
% Added fluids for CVS and copyright information.
%
% Revision 1.8  1996/10/03 16:06:09  sturm
% Fixed a bug in ofsf_structat.
%
% Revision 1.7  1996/10/01 10:25:08  reiske
% Introduced new service rltnf and related code.
%
% Revision 1.6  1996/09/30 16:55:59  sturm
% Cleaned up the use of several (conditional) negate-relation procedures.
%
% Revision 1.5  1996/09/05 11:15:19  dolzmann
% Added implementation for black boxes rl_structat, rl_ifstructat, and
% rl_termmlat.
%
% Revision 1.4  1996/08/01 11:45:48  reiske
% Added implementation for black boxes rl_a2cdl and rl_getineq.
%
% Revision 1.3  1996/07/07 14:39:50  sturm
% Added implementation for black box ofsf_eqnrhskernels.
%
% Revision 1.2  1996/05/21 17:14:19  sturm
% Added procedures ofsf_subat and ofsf_subalchk.
%
% Revision 1.1  1996/03/22 12:14:11  sturm
% Moved and split.
%
% ----------------------------------------------------------------------
lisp <<
   fluid '(ofsf_misc_rcsid!* ofsf_misc_copyright!*);
   ofsf_misc_rcsid!* := "$Id: ofsfmisc.red,v 1.16 2008/08/24 05:28:13 sturm Exp $";
   ofsf_misc_copyright!* :=
      "Copyright (c) 1995-1999 by A. Dolzmann and T. Sturm"
>>;

module ofsfmisc;
% Ordered field standard form miscellaneous. Submodule of [ofsf].

procedure ofsf_termprint(u);
   % Ordered field standard form term print term. [u] is a SF. The
   % return value is not specified. Prints [u] AM-like.
   <<
      sqprint !*f2q u where !*nat=nil;
      ioto_prin2 nil
   >>;

procedure ofsf_canegrel(r,flg);
   % Ordered field standard form conditionally algberaically negate
   % relation. [r] is a relation. Returns a relation $R$. If [flg] is
   % non-[nil], then $[R]=[r]$. If [flg] is [nil], then [R] is a
   % relation, such that $R(-t,0)$ is equivalent to $[r](t,0)$ for
   % every term $t$.
   if flg then r else ofsf_anegrel r;

procedure ofsf_anegrel(r);
   % Ordered field standard form algebraically negate relation. [r] is
   % a relation. Returns a relation $R$ such that $R(-t,0)$ is
   % equivalent to $[r](t,0)$ for a term $t$.
   cdr atsoc(r,'((equal . equal) (neq . neq) (leq . geq) (geq . leq)
      (lessp . greaterp) (greaterp . lessp)))
	 or rederr {"ofsf_anegrel: unknown operator ",r};

procedure ofsf_clnegrel(r,flg);
   % Ordered field standard form conditionally logically negate
   % relation. [r] is a relation; [flg] is bool. Return a relation
   % $R$. If [flg] is non-[nil] [r] is returned. Othewise a relation
   % $R$ is returned such that for terms $t_1$, $t_2$ we have
   % $R(t_1,t_2)$ equivalent to $\lnot [r](t_1,t_2)$.
   if flg then r else ofsf_lnegrel r;

procedure ofsf_lnegrel(r);
   % Ordered field standard form logically negate relation. [r] is a
   % relation. Returns a relation $R$ such that for terms $t_1$, $t_2$
   % we have $R(t_1,t_2)$ equivalent to $\lnot [r](t_1,t_2)$.
   if r eq 'equal then 'neq
   else if r eq 'neq then 'equal
   else if r eq 'leq then 'greaterp
   else if r eq 'lessp then 'geq
   else if r eq 'geq then 'lessp
   else if r eq 'greaterp then 'leq
   else rederr {"ofsf_lnegrel: unknown operator ",r};

procedure ofsf_fctrat(atf);
   % Ordered field standard form factorize atomic formula. [atf] is an
   % atomic formula $l \mathrel{\varrho} 0$. Returns a list $(...,(f_i
   % . d_i),...)$, where $f$ is an irreducible SF and $d$ is a
   % positive integer. We have $l=c \prod_i g_i^{d_i}$ for an integer
   % $c$.
   cdr fctrf ofsf_arg2l atf;

procedure ofsf_negateat(f);
   % Ordered field standard form negate atomic formula. [f] is an
   % atomic formula. Returns an atomic formula equivalent to $\lnot
   % [f]$.
   ofsf_mkn(ofsf_lnegrel ofsf_op f,ofsf_argn f);

procedure ofsf_varlat(atform);
   % Ordered field standard form atomic formula list of variables.
   % [atform] is an atomic formula. Returns the variables contained in
   % [atform] as a list.
   kernels ofsf_arg2l atform;

procedure ofsf_varsubstat(atf,new,old);
   % Ordered field standard form substitute variable for variable in
   % atomic formula. [atf] is an atomic formula; [new] and [old] are
   % variables. Returns an atomic formula equivalent to [atf] where
   % [old] is substituted with [new].
   ofsf_0mk2(ofsf_op atf,numr subf(ofsf_arg2l atf,{old . new}));

procedure ofsf_ordatp(a1,a2);
   % Ordered field standard form atomic formula predicate. [a1] and
   % [a2] are atomic formulas. Returns [t] iff [a1] is less than [a2].
   begin scalar lhs1,lhs2;
      lhs1 := ofsf_arg2l a1;
      lhs2 := ofsf_arg2l a2;
      if lhs1 neq lhs2 then return ordp(lhs1,lhs2);
      return ofsf_ordrelp(ofsf_op a1,ofsf_op a2)
   end;

procedure ofsf_ordrelp(r1,r2);
   % Ordered field standard form relation order predicate.
   % [r1] and [r2] are ofsf-relations. Returns a [T] iff $[r1] < [r2]$.
   not not (r2 memq (r1 memq '(equal neq leq lessp geq greaterp)));

procedure ofsf_a2cdl(atml);
   % Ordered field standard form atomic to case distinction list.
   % [atml] is a list of atomic formulas with multiplicity, the right
   % hand side of which is always zero. Returns a list, each
   % containing a list of case distinction w.r.t. the term $t$, i.e.
   % ${t<0,t=0,t>0}$ resp. ${t=0,t neq 0}$.
   begin scalar atf,terml,flag;
      while atml do <<
         atf := caar atml;
      	 atml := cdr atml;
      	 terml := ofsf_arg2l atf . terml;
	 if not(ofsf_op atf memq '(equal neq)) then flag := T
      >>;
      return for each x in terml collect
	 if flag then
	    {ofsf_0mk2('lessp,x),ofsf_0mk2('equal,x),ofsf_0mk2('greaterp,x)}
	 else
	    {ofsf_0mk2('equal,x),ofsf_0mk2('neq,x)}
   end;

procedure ofsf_t2cdl(term);
   % Ordered field standard form term to case distinction list. [term]
   % is a term. Returns a list of full case distinctions w.r.t. the
   % term, i.e. ${[term]<0,[term]=0,[term]>0}$.
   {ofsf_0mk2('lessp,term),ofsf_0mk2('equal,term),ofsf_0mk2('greaterp,term)};

procedure ofsf_subat(al,f);
   ofsf_simpat {ofsf_op f,ofsf_suba(al,prepf ofsf_arg2l f),0};

procedure ofsf_suba(al,f);
   % Substitute algebraically. [f] is Lisp prefix. Returns Lisp
   % prefix.
   if atom f then
      lto_catsoc(f,al) or f
   else
      car f . for each arg in cdr f collect ofsf_suba(al,arg);

procedure ofsf_subalchk(al);
   % Formerly cheked for parametric denominators, but: We correctly
   % handle them in ofsf_subat now. Also, a rederr here causes and
   % error message "***** sub", probably due to some errorset in
   % subeval.
   if not !*rlnzden and not !*rlposden then
      for each pr in al do
      	 if not domainp denr simp cdr pr then
	    rederr "parametric denominator in substituted expression";

procedure ofsf_eqnrhskernels(x);
   nconc(kernels numr w,kernels denr w) where w=simp cdr x;

procedure ofsf_getineq(f,bvl);
   % Generate theory get inequalities. [f] is a formula, the right
   % hand side is always zero; [bvl] is a list of variables. Returns
   % the list of all inequalities occuring in [f] not containing any
   % variables from [bvl].
   begin scalar atml,atf,cdl;
      atml := cl_atml f;
      while atml do <<
         atf := caar atml;
         atml := cdr atml;
	 if ofsf_op atf memq '(neq) and
	    null intersection(bvl, kernels ofsf_arg2l atf) then
	    cdl := atf . cdl
      >>;
      return cdl
   end;

procedure ofsf_structat(at,al);
   % Orederd field standard form structure of an atomic formula. [at]
   % is an atomic formula $([op],l,0)$; [al] is an ALIST. Returns an
   % atomic formula. [al] is of the form $(...,(f_i . v_i),...)$ where
   % $f_i$ is an SF and $v_i$ is a variable. The left hand side of
   % [at] occurs as a key in [al]. Returns the atomic formula
   % $[op](v_i,0)$, provided $l=f_i$.
   begin scalar lhs;
      lhs := ofsf_arg2l at;
      if domainp lhs then
	 return at;
      return ofsf_0mk2(ofsf_op at, numr simp cdr assoc(lhs,al))
   end;

procedure ofsf_ifstructat(at,al);
   begin scalar w,r;
      w := fctrf ofsf_arg2l at;
      r := car w;
      for each x in cdr w do
	 r := multf(r,expf(numr simp cdr assoc(car x,al),cdr x));
      return ofsf_0mk2(ofsf_op at,r)
   end;

procedure ofsf_termmlat(at);
   % Ordered field standard form term multiplicity list of atomic
   % formula. [at] is an atomic formula. Returns the multiplicity list
   % off all non-zero terms in [at].
   if ofsf_arg2l at then
      {(ofsf_arg2l at . 1)};

procedure ofsf_multsurep(at,atl);
   if ofsf_op at eq 'equal then
      ofsf_multsurep!-equal(at,atl)
   else
      ofsf_multsurep!-neq(at,atl);

procedure ofsf_multsurep!-equal(at,atl);
   begin scalar c,a;
      c := ofsf_arg2l at;
      while atl do <<
	 a := car atl;
	 atl := cdr atl;
	 if ofsf_op a eq 'equal and quotf(c,ofsf_arg2l a) then <<
	    a := 'found;
	    atl := nil
	 >>
      >>;
      return a eq 'found
   end;

procedure ofsf_multsurep!-neq(at,atl);
   begin scalar c,a;
      c := ofsf_arg2l at;
      while atl do <<
	 a := car atl;
	 atl := cdr atl;
	 if ofsf_op a eq 'neq and quotf(ofsf_arg2l a,c) then <<
	    a := 'found;
	    atl := nil
	 >>
      >>;
      return a eq 'found
   end;

procedure ofsf_rxffn(op);
   if op eq 'max then
      'cl_rxffn!-max
   else if op eq 'min then
      'cl_rxffn!-max
   else if op eq 'abs then
      'cl_rxffn!-abs
   else if op eq 'sign then
      'cl_rxffn!-sign
   else if op eq 'sqrt then
      'cl_rxffn!-sqrt
   else
      nil;
   
endmodule;  % [ofsfmisc]

end;  % of file
