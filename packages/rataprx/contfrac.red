module contfrac;  % Continued fractions.

% Author: Lisa Temme

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


% Date:   August 1995.
% Substantial revisions and additions by Alan Barnes, March 2019.

% Code to check for rational polynomials.

% polynomials and rational functions
% by Winfried Neun

symbolic procedure polynomqqq (x);

(if fixp xx then 1 else
 if not onep denr (xx := cadr xx) then nil
 else begin scalar kerns,kern,aa,var,fform,mvv,degg;

 fform := sfp  mvar  numr xx;
 var := reval cadr x;
 if fform then << xx := numr xx;
    while (xx neq 1) do
     << mvv :=  mvar  xx;
        degg := ldeg  xx;
        xx   := lc  xx;
        if domainp mvv then <<if not freeof(mvv,var) then
                << xx := 1 ; kerns := list list('sin,var) >> >> else
        kerns := append ( append (kernels mvv,kernels degg),kerns) >> >>
   else kerns := kernels !*q2f xx;

 aa: if null kerns then return 1;
     kern := first kerns;
     kerns := cdr kerns;
     if not(eq (kern, var)) and depends(kern,var)
                then return nil else go aa;
end) where xx = aeval(car x);

put('polynomqq,'psopfn,'polynomqqq);

symbolic procedure ttttype_ratpoly(u);
  ( if fixp xx then 1 else
        if not eqcar (xx , '!*sq) then nil
          else and(polynomqqq(list(mk!*sq (numr cadr xx ./ 1),
                   reval cadr u)),
                  polynomqqq(list(mk!*sq (denr cadr xx ./ 1),
                   reval cadr u)))
 ) where xx = aeval(car u);

flag ('(type_ratpoly),'boolean);

put('type_ratpoly,'psopfn,'ttttype_ratpoly);

symbolic procedure type_ratpoly(f,z);
    ttttype_ratpoly list(f,z);


%% To combine number, rational and non-rational approaches
%% (including truncated versions) include the following
%% boolean returns and the cfracrules rulelist.

flag ('(vari),'boolean);

symbolic procedure vari(x);
   idp x;

procedure polynomialp(u,x);
  if den u = 1 and (freeof (u,x) or deg(u,x) >= 1 ) then t else nil;

flag ('(polynomialp),'boolean);

switch cf_taylor;
put('cf_taylor, 'simpfg, '((t (on1 'taylorautoexpand))));
% taylorautoexpand needed if the first arg to cfrac has a pole at the origin

algebraic;

operator cfrac;

procedure a_constant (x);
  lisp constant_exprp (x);

cfracrules :=
{ cfrac (~x) => continued_fraction(x)
                  when a_constant(x),

  cfrac (~x,~s) => continued_fraction(x, 0, s)
                     when a_constant(x) and numberp s,

  cfrac (~x,~s) =>
     (begin scalar cf, pt2, res, pt2r;
         cf  := cfracall(x, s);
         pt2 := part(cf, 2);
         res :=
	    if type_ratpoly(x, s) then
               for r := 2 : length pt2 collect {1, part(pt2, r)}
            else
               for r := 2 : length pt2 collect <<
	          pt2r := part(pt2, r); {num pt2r, den pt2r}
               >>;
         return contfrac(x, part(cf, 1), part(pt2, 1) . res);
     end)
        when not numberp x and vari s,

  cfrac(~a,~b,~c) =>
     (begin scalar cf, pt2, res;
         cf  := cfrac_ratpoly(a, b, c);
         pt2 := part(cf, 2);
         res :=
            for q := 2: length pt2 collect {1, part(pt2, q)};

         return contfrac(a, part(cf, 1), part(pt2, 1) . res);
      end)
         when numberp c and vari b and type_ratpoly(a, b),

  cfrac(~a,~b,~c) =>
     (begin scalar cf, pt2, pt2r, res;
         cf  := cfrac_nonratpoly(a,b,c);
         pt2 := part(cf, 2);
         res :=
            for r := 2 : length pt2 collect <<
	        pt2r := part(pt2, r); {num pt2r, den pt2r}
            >>;
         return contfrac(a, part(cf, 1), part(pt2, 1) . res);
       end)
          when numberp c and vari b and not type_ratpoly(a, b)
};

let cfracrules;

% Load TPS & Taylor packages for non-rational functions

load_package taylor;   
load_package tps;

procedure longdiv(poly1, poly2,x);
  begin
    scalar numer, denom, div, div_list, rem, answer;
    numer := poly1;
    denom := poly2;
    div_list := {};
    div := 0;
    rem := 1;
    answer := 0;

    if   longdivdeg(numer, x) < longdivdeg(denom, x) then
      rem := numer
    else <<
       while (longdivdeg(numer,x) >= longdivdeg(denom,x)) and rem neq 0 do <<
          if longdivlterm(numer,x) = 0 then <<
             div := numer/denom;
             rem := 0;
          >>
          else <<
             div := longdivlterm(numer,x)/longdivlterm(denom,x);
             numer := numer - denom*div;
             rem := numer;
          >>;
          div_list := div.div_list;
       >>;
       answer := for each elmt in div_list sum elmt;
    >>;
    return list(answer,rem)
  end;

procedure longdivdeg(i_p,i_p_var);
  begin scalar a;
    a:= if   numberp(den(i_p))
        then deg(i_p*den(i_p),i_p_var);
    return a
  end;

procedure longdivlterm(i_p,i_p_var);
  begin scalar b;
    b := if   numberp(den(i_p))
         then lterm(den(i_p)*i_p,i_p_var)/den(i_p);
    return b
 end;

procedure cfracall(rat_poly,var);
  begin
    scalar top_poly, bot_poly, euclidslist, ld_return;

    if type_ratpoly(rat_poly,var) then <<
         top_poly := num rat_poly;
         bot_poly := den rat_poly;
         euclidslist := {};

         ld_return := longdiv(top_poly, bot_poly, var);
         while part(ld_return, 2) neq 0 do <<
            top_poly := bot_poly;
            bot_poly := part(ld_return,2);
            euclidslist := part(ld_return,1).euclidslist;
	    ld_return := longdiv(top_poly, bot_poly, var);
         >>;
         euclidslist := part(ld_return, 1) . euclidslist;
	 euclidslist := reverse euclidslist;
         return list(inv_cfracall(euclidslist), euclidslist);
      >>
    else
        return cfrac_nonratpoly(rat_poly, var, 5);
  end;

procedure cfrac_ratpoly(rat_poly, var, number);
  begin
    scalar top_poly, bot_poly, euclidslist, ld_return, k;

    if type_ratpoly(rat_poly,var) then
      << top_poly := num rat_poly;
         bot_poly := den rat_poly;
         euclidslist := {};

         k:= number;
	 ld_return := longdiv(top_poly, bot_poly, var);
         while part(ld_return, 2) neq 0 and k neq 0 do <<
            top_poly := bot_poly;
            bot_poly := part(ld_return,2);
            euclidslist := part(ld_return,1).euclidslist;
	    ld_return := longdiv(top_poly, bot_poly, var);
            k := k-1;
         >>;
         euclidslist := part(ld_return, 1) . euclidslist;
	 euclidslist := reverse euclidslist;
         return list(inv_cfracall(euclidslist), euclidslist);
      >>
    else
      return cfrac_nonratpoly(rat_poly, var, number);
  end;

procedure cfrac_nonratpoly(nonrat,x,n);
  if (lisp !*cf_taylor) then
     cfrac_nonratpoly_tay(nonrat,x,n)
  else
     cfrac_nonratpoly_tps(nonrat,x,n);
     
procedure cfrac_nonratpoly_tps(nonrat,x,n);
  begin
    scalar g, a_0, a, coeff_list, k, h, search_lim, psord;

    g := ps(nonrat,x,0);
    k := n;
    psord := psorder g;

    if psord <0 then <<
       a_0 := psterm(g, psord)*x^psord;
       h := psord >>
    else <<
       a_0 := psterm(g, 0);
       h := 0 >>;
       
    coeff_list := {a_0};    
    while (g neq 0 and k > 0) do <<
       a := 0;
       search_lim := h + psordlim();
       % find first non-zero term in power series after the first
       while a = 0 and h <= search_lim do  <<
	  h := h+1;
	  a := psterm(g, h);
	>>;       
        if a neq 0 then <<
           coeff_list := (a*x^h) . coeff_list;
           g := ps(a*x^h/(g-a_0), x, 0);
	   a_0 := psterm(g, 0);
	   h := 0;
        >>
	else
	   % no non-zero term after a_0 in the power series expansion
	   % to this order
	   g := 0; 
        k := k-1;
     >>;
    coeff_list := adaptcfrac(reverse(coeff_list));
    return list(inv_cfrac_nonratpoly2(coeff_list), coeff_list);
  end;

procedure cfrac_nonratpoly_tay(nonrat,x,n);
  begin
    scalar g, gg, a_0, a, clist, coeff_list, k, h, degd;

    g := taylor(nonrat,x,0,2*n);
    k := n;
    gg := taylortostandard g;    
    if taylorp(gg) then rederr "not yet implemented";

    if not type_ratpoly(gg, x) then
        rederr "not yet implemented"
    else <<
       degd := deg(den gg, x);
       gg := gg*x^degd
    >>;
       
    clist := coeff(gg, x);
    a_0 := (first clist)/x^degd;
    clist := rest  clist;
    coeff_list := {a_0};    
    while (g neq 0 and k > 0) do <<
       a := 0;
       h := -degd;
       % find first non-zero term in power series after the first
       while a = 0 and length clist >= 1 do  <<
	  a := first clist;
          clist := rest clist;
	  h := h+1;
	>>;       
        if a neq 0 then <<
           coeff_list := (a*x^h) . coeff_list;
           g := taylorcombine(taylor(a*x^h, x, 0, 2*n)/(g - a_0));
           gg := taylortostandard g;
	   clist := coeff(gg, x);
% the following if's are redundant, the expansion should now always succeed
% and the series should always have a order zero with unit constant term
%	   if taylorp(gg) then rederr "not yet implemented";
%          if not type_ratpoly(gg, x) or not(freeof(den(gg),x)) then
%               rederr "not yet implemented"
           a_0 := first clist;
           clist := rest  clist;
	   degd := 0
        >>
	else
	   % no non-zero term after a_0 in the taylor expansion
	   % to this expansion order
	   g := 0; 
        k := k-1;
     >>;
    coeff_list := adaptcfrac(reverse(coeff_list));
    return list(inv_cfrac_nonratpoly2(coeff_list), coeff_list);
  end;

algebraic procedure adaptcfrac(l_list);
  begin scalar h, l, k, n, m, new_list;

    new_list := {};
    if length l_list < 3 then
      return l_list
    else
      << h := first l_list;
         l := second l_list;
         k := 2;
         while length l_list >= k do <<
            n := num l;
            d := den l;
            new_list := (n/d) . new_list;
            k := k+1;
            if length l_list >= k then <<
               l := part(l_list, k);
               l := d*l
            >>;
         >>;
      >>;
    return h . reverse(new_list);
  end;

algebraic procedure inv_cfrac_nonratpoly1(c_list);
  begin scalar n, j, expan;

    j := length c_list;
    if j < 3 then 
        return for each m in c_list sum m
    else <<
        for k := j step -1 until 2 do <<
	   n := part(c_list, k);
	   if k=j then 
              expan := n
           else
	      expan := n / (1 + expan);
            >>;
         return part(c_list, 1) + expan;
     >>;
  end;

algebraic procedure inv_cfrac_nonratpoly2(c_list);
  begin scalar n, j, expan;

    j := length c_list;
    if j < 3 then
       return for each m in c_list sum m
    else <<
       for k:=j step -1 until 2 do <<
           n := part(c_list, k);
           if k=j then
	      expan := n
           else
	      expan := num(n) / (den(n) + expan);
            >>;
       return part(c_list,1) + expan;
    >>;
  end;

algebraic procedure inv_cfracall(c_list);
   begin scalar ans, j;
      j := length c_list;
      if j=0 then
         return {}
      else 
         if j=1 then
            ans := part(c_list,1)
         else <<
            ans := part(c_list,j);
            for k:=j-1 step -1 until 1 do
               ans := part(c_list,k) + 1/ans;
         >>;
     return ans
   end;

endmodule;

end;

