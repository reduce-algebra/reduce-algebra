% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% Copyright (c) 2013 M. Kosta, T. Sturm
% ----------------------------------------------------------------------
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions
% are met:
%
%    * Redistributions of source code must retain the relevant
%      copyright notice, this list of conditions and the following
%      disclaimer.
%    * Redistributions in binary form must reproduce the above
%      copyright notice, this list of conditions and the following
%      disclaimer in the documentation and/or other materials provided
%      with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
% "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
% LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
% A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
% OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
% SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
% LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
% DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
% THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
% (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
% OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
%

lisp <<
   fluid '(sftoresultant_rcsid!* sftoresultant_copyright!*);
   sftoresultant_rcsid!* := "$Id$";
   sftoresultant_copyright!* := "(c) 2013 M. Kosta, T. Sturm"
>>;

module sftoresultant;
% Standard form resultant.

% WARNING: Polynomials in lists returned by the following functions are NOT
% necessarily irreducible. Factorization is therefore needed afterwards!

switch fastresexpand;
on1 'fastresexpand;

switch fastresvb;

operator fastresultant;

asserted procedure fastresultant(f: Any, g: Any, x: Kernel): Any;
   begin scalar w, res;
      if not idp x then
	 rederr "third argument must be a variable";
      w := sfto_resf(numr simp f, numr simp g, x);
      if not !*fastresexpand then
      	 return 'list . for each pr in w collect
	    {'list, mk!*sq !*f2q car pr, cadr pr};
      return mk!*sq !*f2q w
   end;

asserted procedure sfto_resf(f: SF, g: SF, x: Kernel): List;
   begin scalar oo, w, res;
      oo := setkorder(x . kord!*);
      f := reorder f;
      g := reorder g;
      w := errorset({'sfto_resf2, mkquote f, mkquote g, mkquote x},
	 nil, !*backtrace);
      setkorder oo;
      if errorp w then
	 rederr emsg!*;
      if not !*fastresexpand then
      	 return for each pr in car w collect
	    {reorder car pr, cadr pr};
      res := 1;
      for each pr in car w do
	 res := multf(res, exptf(reorder car pr, cadr pr));
      return res
   end;

asserted procedure sfto_resf2(f: SF, g: SF, x: Kernel): List;
   % We assume that: 1) [f] and [g] are ordered correctly, i.e. if [x] occurs in
   % [f] or [g] then it is mvar. Returns a list of polynomial factors of res(f,
   % g, x) with multiplicities.
   begin scalar w;
      if null f or null g or zerop f or zerop g then
	 return {{0, 1}};
      if domainp f or null(mvar f eq x) then
      	 return if not domainp g and mvar g eq x then
      	    {{f, ldeg g}}
      	 else
      	    {{1, 1}};
      if domainp g or null(mvar g eq x) then
      	 return if mvar f eq x then
      	    {{g, ldeg f}}
      	 else
      	    {{1, 1}};
      w := sfto_gcdf(f, g);
      if not domainp w then
	 return {{0, 1}};
      return sfto_resf3(quotfx(f, w), quotfx(g, w), x)
   end;

asserted procedure sfto_resf3(f: SF, g: SF, x: Kernel): List;
   % We assume that: 1) [f] and [g] are ordered correctly and of positive degree
   % in [x]. 2) [f] and [g] are coprime, i.e. the resultant is not identically
   % zero. Returns a list of polynomial factors of res(f, g, x) with
   % multiplicities.
   begin scalar cnt, varl, degal; integer l;
      % We don't want to factor out the integer content.
      % f := quotfx(f, sfto_dcontentf f);
      % g := quotfx(g, sfto_dcontentf g);
      cnt := sfto_ucontentf f;
      if cnt neq 1 then
	 return {cnt, ldeg g} . sfto_resf2(quotfx(f, cnt), g, x);
      cnt := sfto_ucontentf g;
      if cnt neq 1 then
	 return {cnt, ldeg f} . sfto_resf2(f, quotfx(g, cnt), x);

      l := sfto_mindeg1(f, x); % Later use sfto_mindeg
      if l > 0 then
	 return {sfto_tc(g, x), l} .
	    sfto_resf2(quotfx(f, exptf(!*k2f x, l)), g, x);
      l := sfto_mindeg1(g, x); % Later use sfto_mindeg
      if l > 0 then
	 return {sfto_tc(f, x), l} .
	    sfto_resf2(f, quotfx(g, exptf(!*k2f x, l)), x);

      degal := sfto_deggcd(f, g, {x});
      if not null degal then
	 return sfto_raisel(
	    sfto_resf2(sfto_subfwd(f, degal), sfto_subfwd(g, degal), x),
	    cdr atsoc(x, degal));

      varl := setdiff(union(kernels f, kernels g), {x});
      degal := sfto_deggcd(f, g, varl);
      if not null degal then <<
	 return sfto_subbckl(
	    sfto_bezout_resultant_fac(
	       sfto_subfwd(f, degal), sfto_subfwd(g, degal), x),
	    degal);
      >>;
      return sfto_bezout_resultant_fac(f, g, x)
   end;


asserted procedure sfto_mindeg(f: SF, x: Kernel): Integer;
   % Wrapper procedure for sfto_mindeg1.
   nil;

asserted procedure sfto_mindeg1(f: SF, x: Kernel): Integer;
   % Lowest degree of [x] in [f]. We assume that [x] is mvar in [f].
   if domainp f or mvar f neq x then
      0
   else if red f then
      sfto_mindeg1(red f, x)
   else
      ldeg f;

asserted procedure sfto_tc(f: SF, x: Kernel): SF;
   % Trailing coefficient of [x] in [f]. We assume that [x] is mvar in [f].
   if domainp f then
      f
   else
      if mvar f eq x then
	 if red f eq nil then
	    lc f
	 else
	    sfto_tc(red f, x)
      else
	 f;

asserted procedure sfto_deggcd(f: SF, g: SF, varl: List): List;
   % Gcd of degrees of variables.
   begin scalar var, res; integer c;
      while varl do <<
	 var := pop varl;
	 c := sfto_deggcd1(f, var);
	 if c neq 1 then <<
	    c := gcdn(c, sfto_deggcd1(g, var));
	    if c neq 1 then
	       res := (var . c) . res
	 >>
      >>;
      return res
   end;

asserted procedure sfto_deggcd1(f: SF, x: Kernel): Integer;
   % Gcd of degrees of a variable.
   begin scalar c; integer res;
      c := t;
      while c and res neq 1 do
	 if domainp f then
	    c := nil
	 else <<
	    if mvar f eq x then
	       res := gcdn(res, ldeg f)
	    else
	       res := gcdn(res, sfto_deggcd1(lc f, x));
	    f := red f
	 >>;
      return res
   end;

asserted procedure sfto_raisel(polyl: List, c: Integer): List;
   for each pr in polyl collect
      {car pr, cadr pr * c};

asserted procedure sfto_subfwd(poly: SF, degal: AList): SF;
   begin scalar w; integer d;
      if domainp poly then
      	 return poly;
      w := atsoc(mvar poly, degal);
      d := if w then ldeg poly / cdr w else ldeg poly;
      return ((mvar poly .** d) .* sfto_subfwd(lc poly, degal)) .+
	 sfto_subfwd(red poly, degal)
   end;

% Avoid calls to subf in this procedure as well.
% asserted procedure sfto_subbckl(polyl: List, degl: AList): List;
%    begin scalar w, subl, poly, res;
%       while degl do <<
% 	 w := car degl;
% 	 subl := (car w . {'expt, car w, cdr w}) . subl;
% 	 degl := cdr degl
%       >>;
%       while polyl do <<
% 	 poly := car polyl;
% 	 res := {numr subf(car poly, subl), cadr poly} . res;
% 	 polyl := cdr polyl
%       >>;
%       return res
%    end;

asserted procedure sfto_subbckl(polyl: List, degal: AList): List;
   for each pr in polyl collect
      {sfto_subbck(car pr, degal), cadr pr};

asserted procedure sfto_subbck(poly: SF, degal: AList): SF;
   begin scalar w; integer d;
      if domainp poly then
      	 return poly;
      w := atsoc(mvar poly, degal);
      d := if w then ldeg poly * cdr w else ldeg poly;
      return ((mvar poly .** d) .* sfto_subbck(lc poly, degal)) .+
	 sfto_subbck(red poly, degal)
   end;

% BEGIN: Code taken from file crdec.red. Changes done: sfto_bezout_resultant_fac
% returns a list containing standard forms instead of lisp prefix.

asserted procedure sfto_bezout_resultant_fac(u: SF, v: SF, w: Kernel): List;
   % U and v are standard forms. Result is resultant of u and v w.r.t. kernel w.
   % Method is Bezout's determinant using exterior multiplication for its
   % calculation.
   begin integer n,nm; scalar ap,ep,uh,ut,vh,vt,x,cx,cxf,cep,cuh,cvh;
      if !*fastresvb then
      	 write "entering bezout.";
      terpri();
      !*exp := t;
      if domainp u or null(mvar u eq w) then
      	 return if not domainp v and mvar v eq w then
      	    {{u, ldeg v}}
      	 else
      	    {{1, 1}}
      else if domainp v or null(mvar v eq w) then
      	 return if mvar u eq w then
      	    {{v, ldeg u}}
      	 else
      	    {{1, 1}};
      n := ldeg v - ldeg u;
      cxf := '(1);
      if n < 0 then <<
	 x := u;
	 u := v;
	 v := x;
	 cxf := '(-1);
	 n := -n
      >>;
      ep := 1;
      nm := ldeg v;
      uh := lc u;
      vh := lc v;
      ut := if n neq 0 then
	 multpf(w to n,red u)
      else red u;
      vt := red v;
      cx := 1;
      cuh := uh;
      cvh := vh;
      cx := gcdf!*(uh,vh);
      if cx = 1 then <<
	 if !*fastresvb then <<
	    write "Found trivial factor from headpolys only. ";
	    terpri()
	 >>
      >> else <<
	 if !*fastresvb then <<
	    write "Found factor from headpolys with ",termsf cx," terms.";
	    terpri();
	 >>;
	 cxf := fctrf cx
      >>;
      ap := addf(multf(quotf1(uh,cx),vt),negf multf(quotf1(vh,cx),ut));
      x := sfto_!*sf2exb(ap,w);
      if cdr cxf then
	 x := sfto_b!:try_previous_factors(x,cdr cxf);
      cx := sfto_b!:comfac x;
      if cx neq 1 then <<
	 cxf := sfto_bfac!-merge(fctrf cx,cxf);
	 if !*fastresvb then <<
	    write "commom factor cx found. ",tmsf cx," terms.";
	    terpri()
	 >>
      >>;
      x := sfto_b!:cquot(x,cx);
      ep := sfto_b!:extmult(x,ep);
      ep := sfto_b!:try_previous_factors(ep,cdr cxf);
      for j := (nm - 1) step -1 until (n + 1) do <<
	 if degr(ut,w) = j then <<
	    uh := addf(lc ut,multf(!*k2f w,uh));
	    if null(cuh = 1 or cvh = 1) then
	       cuh := gcdf!*(lc ut,cuh);
	    ut := red ut
	 >> else
	    uh := multf(!*k2f w,uh);
	 if degr(vt,w) = j then <<
	    vh := addf(lc vt,multf(!*k2f w,vh));
	    if null(cuh = 1 or cvh = 1) then
	       cvh := gcdf!*(lc vt,cvh);
	    vt := red vt
	 >> else
	    vh := multf(!*k2f w,vh);
	 cx := 1;
	 cx := gcdf!*(cuh,cvh);
	 if cx = 1 then <<
	    if !*fastresvb then <<
	       write "Found trivial factor from headpolys only. ";
	       terpri()
	    >>
	 >> else <<
	    if !*fastresvb then <<
	       write "Found factor from headpolys with ",termsf cx," terms.";
	       terpri()
	    >>;
	    cxf := sfto_bfac!-merge(fctrf cx,cxf)
	 >>;
	 x := sfto_!*sf2exb(addf(multf(quotf1(uh,cx),vt),
	    negf multf(quotf1(vh,cx),ut)),w);
	 x := sfto_b!:try_previous_factors(x,cdr cxf);
	 cx := sfto_b!:comfac x;
	 if cx neq 1 then <<
	    if !*fastresvb then <<
	       write "commom factor cx found. ",tmsf cx," terms.";
	       terpri()
	    >>;
	    cxf := sfto_bfac!-merge(fctrf cx,cxf)
	 >>;
	 x := sfto_b!:cquot(x,cx);
	 ep := sfto_b!:extmult(x,ep);
	 ep := sfto_b!:try_previous_factors(ep,cdr cxf);
	 if j neq 1 then <<
	    cep := sfto_b!:comfac ep;
	    if cep neq 1 then <<
	       cxf := sfto_bfac!-merge(fctrf cep,cxf);
	       if !*fastresvb then <<
	       	  write "commom factor cep found. ",tmsf cep," terms.";
	       	  terpri()
	       >>
	    >>;
	    ep := sfto_b!:cquot(ep,cep)
	 >>
      >>;
      if n neq 0 then <<
	 x := sfto_!*sf2exb(u,w);
	 cx := sfto_b!:comfac x;
	 if cx neq 1 then <<
	    if !*fastresvb then <<
	       write "commom factor cx found.",tmsf cx," terms";
	       terpri()
	    >>;
	    cxf := sfto_bfac!-merge(fctrf cx,cxf)
	 >>;
	 x := sfto_b!:cquot(x,cx);
	 ep := sfto_b!:extmult(x,ep);
	 cep := sfto_b!:comfac ep;
	 if cep neq 1 then <<
	    if !*fastresvb then <<
	       write "commom factor cep found. ",tmsf cep," terms.";
	       terpri()
	    >>;
	    cxf := sfto_bfac!-merge(fctrf cep,cxf)
	 >>;
	 ep := sfto_b!:cquot(ep,cep);
	 for j := 1:(n-1) do <<
	    x := sfto_!*sf2exb(multpf(w to j,u),w);
	    cx := sfto_b!:comfac x;
	    if cx neq 1 then <<
	       if !*fastresvb then <<
		  write "commom factor cx found. ",tmsf cx," terms.";
	       	  terpri()
	       >>;
	       cxf := sfto_bfac!-merge(fctrf cx,cxf)
	    >>;
	    x := sfto_b!:cquot(x,cx);
	    ep := sfto_b!:extmult(x,ep);
	    cep := sfto_b!:comfac ep;
	    if cep neq 1 then <<
	       cxf := sfto_bfac!-merge(fctrf cep,cxf);
	       if !*fastresvb then <<
	       	  write "commom factor cep found. ",tmsf cep," terms.";
	       	  terpri()
	       >>
	    >>;
	    ep := sfto_b!:cquot(ep,cep);
	 >>
      >>;
      return if null ep then
      	 {{0, 1}}
      else if domainp lc ep then
      	 {multf(car cxf, lc ep), 1} .
      	    for each j in cdr cxf collect
      	       {car j, cdr j}
      else
      	 {car cxf, 1} . ({lc ep, 1} .
      	    for each j in cdr cxf collect
      	       {car j, cdr j})
   end;

procedure sfto_!*sf2exb(u,v);
   %distributes s.f. u with respect to powers in v.
   if degr(u,v)=0 then
      if null u then
	 nil
      else
	 list 0 .* u .+ nil
   else
      list ldeg u .* lc u .+ sfto_!*sf2exb(red u,v);

%**** Support for exterior multiplication ****
% Data structure is lpow ::= list of degrees in exterior product
%                   lc   ::= standard form

procedure sfto_b!:extmult(u,v);
   %Special exterior multiplication routine. Degree of form v is
   %arbitrary, u is a one-form.
   if null u or null v then
      nil
   else if v = 1 then
      u
   else
      (if x then cdr x .* (if car x then negf multf(lc u,lc v)
      else multf(lc u,lc v))
      	 .+ sfto_b!:extadd(sfto_b!:extmult(!*t2f lt u,red v),
	    sfto_b!:extmult(red u,v))
      else sfto_b!:extadd(sfto_b!:extmult(red u,v),
      	 sfto_b!:extmult(!*t2f lt u,red v)))
      	    where x = sfto_b!:ordexn(car lpow u,lpow v);

procedure sfto_b!:extadd(u,v);
   if null u then
      v
   else if null v then
      u
   else if lpow u = lpow v then
      (lambda x,y; if null x then y else lpow u .* x .+ y)
         (addf(lc u,lc v),sfto_b!:extadd(red u,red v))
   else if sfto_b!:ordexp(lpow u,lpow v) then
      lt u .+ sfto_b!:extadd(red u,v)
   else lt v .+ sfto_b!:extadd(u,red v);

procedure sfto_b!:ordexp(u,v);
   if null u then
      t
   else if car u > car v then
      t
   else if car u = car v then
      sfto_b!:ordexp(cdr u,cdr v)
   else
      nil;

procedure sfto_b!:ordexn(u,v);
   %u is a single integer, v a list. Returns nil if u is a member
   %of v or a dotted pair of a permutation indicator and the ordered
   %list of u merged into v.
   begin scalar s,x;
   a: if null v then
	 return(s . reverse(u . x))
   else if u = car v then
      return nil
   else if u and u > car v then
      return (s . append(reverse(u . x),v))
   else <<
      x := car v . x;
      v := cdr v;
      s := not s
   >>;
      go to a
   end;

procedure sfto_b!:comfac(u);
   begin scalar !*ezgcd,x;
      if !*fastresvb then <<
      	 write "entered comfac.";
      	 terpri()
      >>;
      !*ezgcd := t;
      if null u then
	 return 1;
      x := lc u;
   a: u := red u;
      if null u then <<
	 if !*fastresvb then <<
	    write "left comfac.";
	    terpri()
	 >>;
	 return x
      >>;
      x := gcdf!*(lc u,x);
      go to a
   end;

procedure sfto_b!:cquot(u,v);
   if null u then
      nil
   else
      lpow u .* quotf1(lc u,v) .+ sfto_b!:cquot(red u,v);

procedure sfto_b!:try_previous_factors(u,v);
   begin scalar x;
      if null v then
	 return u;
   b: x := sfto_b!:ctrialdiv(u,caar v);
      if null x then
	 go to a;
      if !*fastresvb then <<
	 write "successful trial div. ";
	 terpri()
      >>;
      u := x;
      rplacd(car v,cdar v + 1);
      go to b;
   a: v := cdr v;
      if null v then
	 return u;
      go to b
   end;

procedure sfto_b!:ctrialdiv(u,v);
   begin scalar res,w,x;
      if domainp u then
	 return quotf1(u,v);
      if x := quotf1(lc u,v) then
	 res := w := lpow u .* x .+ nil
      else
	 return nil;
   a: u := red u;
      if null u then
	 return res;
      if domainp u then
	 if x := quotf1(u,v) then <<
	    rplacd(w,x);
	    return res
	 >> else
	    return nil;
      if x := quotf1(lc u,v) then
	 rplacd(w,lpow u .* x .+ nil)
      else
	 return nil;
      w := red w;
      go to a;
   end;

procedure sfto_bfac!-merge(u,v);
   if null cdr v then
      multf(car u,car v) . cdr u
   else
      multf(car u,car v) . sfto_bfac!-merge2(cdr u,cdr v);

procedure sfto_bfac!-merge2(u,v);
   begin scalar x,y,r;
      if null u then
	 return v;
   c: x := car u;
      y := v;
   b: if car x = caar y then <<
	 rplacd(car y,cdar y + cdr x);
      	 go to a
      >>;
      y := cdr y;
      if y then
	 go to b;
      r := x . r;
   a: u := cdr u;
      if null u then
	 return append(v,r);
      go to c;
   end;

% END: Code taken from file crdec.red.

endmodule;  % [sftoresultant]

end;  % of file
