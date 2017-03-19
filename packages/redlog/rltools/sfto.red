module sfto;  % Standard form tools.

revision('sfto, "$Id$");

copyright('sfto, "(c) 1995-2009 A. Dolzmann, T. Sturm, 2010-2017 T. Sturm");

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

fluid '(!*ezgcd !*gcd !*rldavgcd !*rational);

switch sfto_yun,sfto_tobey,sfto_musser;
!*sfto_yun := t;

put('sqfpart,'polyfn,'sfto_sqfpartf);
put('dprpart,'polyfn,'sfto_dprpartf);
put('tsqsum,'psopfn,'sfto_tsqsum!$);
put('sqfdec,'psopfn,'sfto_sqfdec!$);
put('pdec,'psopfn,'sfto_pdec!$);
put('sfto_yun,'simpfg,'((t (setq !*sfto_tobey nil) (setq !*sfto_musser nil))));
put('sfto_tobey,'simpfg,'((t (setq !*sfto_yun nil) (setq !*sfto_musser nil))));
put('sfto_musser,'simpfg,'((t (setq !*sfto_tobey nil) (setq !*sfto_yun nil))));

operator exteuc;
operator degree;
operator coefficients;

struct AmList asserted by am_listp;
struct AmPoly asserted by am_polyp;

procedure am_listp(x);
   t;

procedure am_polyp(x);
   t;

declare addf: (SF,SF) -> SF;
declare multf: (SF,SF) -> SF;
declare negf: (NoOrdSF) -> NoOrdSF;

#if (memq 'csl lispsystem!*)

copyd('sfto_lcmn, 'lcmn);

#else

asserted procedure sfto_lcmn(a: Integer, b: Integer): Integer;
   if eqn(a,1) then
      b
   else if eqn(b,1) then
      a
   else
      a * (b / gcdn(a,b));

#endif

asserted procedure sfto_dcontentf(u: SF): Domain;
   % Domain content standard form. Returns the (non-negative) content of [u]
   % considered as a multivariate polynomial over the current domain.
   sfto_dcontentf1(u,nil);

asserted procedure sfto_dcontentf1(u: SF, g: Domain): Domain;
   % Domain content standard form subroutine. Returns the gcd of the content of
   % [u] considered as a multivariate polynomial and [g].
   if g = 1 then
      g
   else if domainp u then
      sfto_gcdf(absf u,g)
   else
      sfto_dcontentf1(red u,sfto_dcontentf1(lc u,g));

asserted procedure sfto_dprpartf(u: SF): SF;
   % Domain primitive part standard form. Returns the primitive part of [u] as a
   % multivariate polynomial over the current domain. The sign of the head
   % coefficient in this primitive part is positive.
   sfto_dprpartf1(u,sfto_dcontentf u);

asserted procedure sfto_dprpartksf(u: SF): SF;
   % Domain primitive part standard form keep sign. Returns the primitive part
   % of [u] as a multivariate polynomial over the current domain. The sign of
   % the head coefficient in this primitive part is that of [u].
   quotf(u,sfto_dcontentf u);

asserted procedure sfto_dprpartf1(u: SF, c: SF): SF;
   % Domain primitive part standard form subroutine. Returns the primitive part
   % of [u] considered as a multivariate polynomial over the current domain.
   (if minusf w then negf w else w) where w = quotf(u,c);

asserted procedure sfto_sqfpartf(u: SF!*): SF!*;
   % Square-free part. Returns the square-free part of [u] as a multivariate
   % polynomial. The (domain) content is dropped.
   begin scalar c,pp;
      if domainp u then return 1;
      c := sfto_ucontentf u;
      pp := quotf(u,c);
      return multf(sfto_sqfpartf(c),quotf(pp,sfto_gcdf!*(pp,diff(pp,mvar u))))
   end;

asserted procedure sfto_ucontentf(u: SF): SF;
   % Univariate content standard form. Returns the content of [u] considered as
   % a univariate polynomial in its [mvar] over the polynomial ring in all other
   % contained variables.
   if domainp u then u else sfto_ucontentf1(u,mvar u);

asserted procedure sfto_ucontentf1(u: SF, v: Kernel): SF;
   % Univariate content standard form subroutine. We assume [mvar u = v].
   % Returns the content of [u] as an univariate polynomial in [v] over the
   % polynomial ring in all other contained variables.
   if domainp u or mvar u neq v then u else
      sfto_gcdf!*(lc u,sfto_ucontentf1(red u,v));

asserted procedure sfto_uprpartf(u: SF): SF;
   % Univariate primitive part. Returns the primitive part of [u] as a
   % univariate polynomial in its [mvar] over the polynomial ring in all other
   % contained variables.
   quotf(u,sfto_ucontentf u);

asserted procedure sfto_tsqsumf(u: SF): Id;
   % Trivial square sum standard form. Returns one of [nil], ['stsq], or ['tsq].
   % ['stsq] means that in the sparse distributive representation of [u] all
   % exponents are even and all coefficients are positive. ['tsq] means that all
   % exponents are even and all coefficients are positive except for that there
   % is no absolute summand.
   if domainp u then
      (if null u then 'tsq else if not minusf u then 'stsq)
   else
      evenp ldeg u and sfto_tsqsumf lc u and sfto_tsqsumf red u;

asserted procedure sfto_tsqsum!$(argl: List): Id;
   sfto_tsqsumf(numr simp car argl);

asserted procedure sfto_sqfdecf(u: SF): Alist;
   % Multivariate square-free decomposition standard form. Returns a (dense)
   % list $((q_1 . 1),(q_2 . 2),...,(q_n . n))$ such that $\prod q_i^i = u$ with
   % the $q_i$ square-free and pairwise relatively prime. The (integer) content
   % of u is dropped. Decomposition is performed by merging univariate
   % decompositions. The univariate decomposition method is selected by turning
   % on one of the switches [sfto_yun] (default), [sfto_tobey], or
   % [sfto_musser].
   begin scalar c,pp;
      if domainp u then return {1 . 1};
      c := sfto_ucontentf u;
      pp := quotf(u,c);
      return sfto_sqdmerge(sfto_sqfdecf(c),sfto_usqfdecf(pp))
   end;

asserted procedure sfto_sqfdec!$(argl: List): AmList;
   % Square free decomposition. [argl] is an argument list. Returns an AM list
   % of AM lists of the form $(p_i,m_i)$, where the $p_i$ are polynomials
   % represented as a Lisp prefix form and the $m_i$ are integers.
   begin scalar w;
      return 'list . for each x in sfto_sqfdecf numr simp car argl join
      	 if (w := prepf car x) neq 1 then {{'list,w,cdr x}}
   end;

asserted procedure sfto_usqfdecf(u: SF): Alist;
   if !*sfto_yun then
      sfto_yun!-usqfdecf u
   else if !*sfto_musser then
      sfto_musser!-usqfdecf u
   else if !*sfto_tobey then
      sfto_tobey!-usqfdecf u
   else
      rederr {"sfto_usqfdecf: select a decomposition method"};

asserted procedure sfto_yun!-usqfdecf(p: SF): Alist;
   % Univariate square-free decomposition after Yun. [p] is treated as a
   % univariate Polynomial in its [mvar] over the polynomial ring in all other
   % variables; in this sense, [p] must be primitive. Returns the square-free
   % decomposition of [p] as a (dense) list $((q_1 . 1),(q_2 . 2),...,(q_n .
   % n))$ such that $\prod q_i^i = u$ with the $q_i$ square-free and pairwise
   % relatively prime.
   begin scalar !*gcd,x,g,c,d,w,l; integer n;
      !*gcd := t;
      x := mvar p;
      g := sfto_gcdf(p,w := diff(p,x));
      c := quotf(p,g);
      d := addf(quotf(w,g),negf(diff(c,x)));
      repeat <<
	 p := sfto_gcdf(c,d);
	 l := (p . (n := n+1)) . l;
	 c := quotf(c,p);
	 d := addf(quotf(d,p),negf(diff(c,x)))
      >> until domainp c;
      return reversip l
   end;

asserted procedure sfto_musser!-usqfdecf(u: SF): Alist;
   % Univariate square-free decomposition after Musser. [u] is treated as a
   % univariate Polynomial in its [mvar] over the polynomial ring in all other
   % variables; in this sense, [p] must be primitive. Returns the square-free
   % decomposition of [p] as a (dense) list $((q_1 . 1),(q_2 . 2),...,(q_n .
   % n))$ such that $\prod q_i^i = u$ with the $q_i$ square-free and pairwise
   % relatively prime.
   begin scalar !*gcd,v,u1,sqfp,sqfp1,l; integer n;
      !*gcd := t;
      v := mvar u;
      u1 := sfto_gcdf(u,diff(u,v));
      sqfp := quotf(u,u1);
      while degr(u1,v)>0 do <<
	 sqfp1 := sfto_gcdf(sqfp,u1);
	 l := (quotf(sqfp,sqfp1) . (n := n+1)) . l;
	 u1 := quotf(u1,sqfp1);
	 sqfp := sqfp1
      >>;
      l := (sqfp . (n := n+1)) . l;
      return reversip l
   end;

asserted procedure sfto_tobey!-usqfdecf(u: SF): Alist;
   % Univariate square-free decomposition after Tobey and Horowitz. [u] is
   % treated as a univariate Polynomial in its [mvar] over the polynomial ring
   % in all other variables; in this sense, [p] must be primitive. Returns the
   % square-free decomposition of [p] as a (dense) list $((q_1 . 1),(q_2 .
   % 2),...,(q_n . n))$ such that $\prod q_i^i = u$ with the $q_i$ square-free
   % and pairwise relatively prime.
   begin scalar !*gcd,v,h,q1,q2,l; integer n;
      !*gcd := t;
      v := mvar u;
      h := sfto_gcdf(u,diff(u,v));
      q2 := quotf(u,h);
      while degr(u,v)>0 do <<
	 u := h;
	 q1 := q2;
	 h := sfto_gcdf(u,diff(u,v));
	 q2 := quotf(u,h);
	 l := (quotf(q1,q2) . (n := n+1)) . l
      >>;
      return reversip l
   end;

asserted procedure sfto_sqdmerge(l1: Alist,l2: Alist): Alist;
   % Square-free decomposition merge.
   begin scalar l;
      l := l1;
      while l1 and l2 do <<
	 caar l1 := multf(caar l1,caar l2);
      	 l1 := cdr l1;
	 l2 := cdr l2
      >>;
      if l2 then l := nconc(l,l2);
      return l
   end;

asserted procedure sfto_pdecf(u: SF): DottedPair;
   % Multivariate parity decomposition. Returns $a . d$ such that $a$ is the
   % product of all square-free factors with an odd multiplicity in [u] and $d$
   % is that of the even multiplicity square-free factors. The (integer) content
   % of u is dropped. Decomposition is performed by merging univariate
   % decompositions. The univariate decomposition method is selected by turning
   % on one of the switches [sfto_yun] (default), [sfto_musser].
   begin scalar c,dpdc,dpdpp;
      if domainp u then return 1 . 1;
      c := sfto_ucontentf u;
      dpdc := sfto_pdecf c;
      dpdpp := sfto_updecf quotf(u,c);
      return multf(car dpdc,car dpdpp) . multf(cdr dpdc,cdr dpdpp)
   end;

asserted procedure sfto_updecf(u: SF): DottedPair;
   % Univeriate parity decomposition.
   if !*sfto_yun then
      sfto_yun!-updecf u
   else if !*sfto_musser then
      sfto_musser!-updecf u
   else
      rederr {"sfto_updecf: select a decomposition method"};

asserted procedure sfto_yun!-updecf(p: SF): DottedPair;
   % Univeriate parity decomposition after Yun..
   begin scalar !*gcd,x,g,c,d,w,l,od;
      !*gcd := t;
      l := 1 . 1;
      x := mvar p;
      g := sfto_gcdf(p,w := diff(p,x));
      c := quotf(p,g);
      d := addf(quotf(w,g),negf(diff(c,x)));
      repeat <<
	 od := not od;
	 p := sfto_gcdf(c,d);
	 if od then car l := multf(car l,p) else cdr l := multf(cdr l,p);
	 c := quotf(c,p);
	 d := addf(quotf(d,p),negf(diff(c,x)))
      >> until domainp c;
      return l
   end;

asserted procedure sfto_musser!-updecf(u: SF): DottedPair;
   % Univariate parity decomposition after Musser.
   begin scalar !*gcd,od,v,u1,sqfp,sqfp1,l;
      !*gcd := t;
      od := t;
      l := 1 . 1;
      v := mvar u;
      u1 := sfto_gcdf(u,diff(u,v));
      sqfp := quotf(u,u1);
      while degr(u1,v)>0 do <<
	 sqfp1 := sfto_gcdf(sqfp,u1);
	 if od then
 	    car l := multf(car l,quotf(sqfp,sqfp1))
	 else
	    cdr l := multf(cdr l,quotf(sqfp,sqfp1));
	 u1 := quotf(u1,sqfp1);
	 sqfp := sqfp1;
	 od := not od
      >>;
      if od then
	 car l := multf(car l,sqfp)
      else
	 cdr l := multf(cdr l,sqfp);
      return l
   end;

asserted procedure sfto_pdec!$(argl: List): AmList;
   % Parity decomposition. AM interface.
   {'list,prepf car w,prepf cdr w}
      where w=sfto_pdecf numr simp car argl;

asserted procedure sfto_decdegf(u: SF, k: Kernel, n: Integer): SF;
   % Decrement degree standard form. Replace each occurence of $[k]^d$ by
   % $k^(d/n)$.
   begin scalar sal,hit,newkk;
      if !*rlbrkcxk then <<
	 for each kk in kernels u do
	    if pairp kk then <<
	       hit . newkk := sfto_decdegcxk(kk,k,n,nil);
	       if hit then
	       	  sal := (kk . newkk) . sal
	    >>;
	 u := numr subf(u,sal)
      >>;
      u := reorder sfto_decdegf1(sfto_reorder(u,k),k,n);
      return u
   end;

asserted procedure sfto_decdegcxk(kk: Kernel, k: Kernel, n: Integer, hit: Boolean): DottedPair;
   % Decrement degree complex kernel. Returns $h . l$, where $h$ is boolean and
   % $l$ is lisp prefix. $l$ is obtained by replacing in [kk] each occurrence of
   % $[k]^d$ by $k^(d/n)$; $h$ is [t] iff $h$ is not equal to [kk].
   begin scalar w,argl;
      if not pairp kk then
	 return hit . kk;
      if car kk eq 'expt and cadr kk eq k then
	 return t . {'expt,k,caddr kk / n};
      for each arg in cdr kk do <<
	 hit . w := sfto_decdegcxk(arg,k,n,hit);
	 argl := w . argl
      >>;
      return hit . (car kk . reversip argl)
   end;

asserted procedure sfto_decdegf1(u, k: Kernel, n: Integer);
   % Decrement degree standard form. [u] is an SF with main variable [k]; [k] is
   % a variable; [n] is an integer. Returns an SF. Replace each occurence of
   % $[k]^d$ by $k^(d/n)$.
   if degr(u,k)=0 then
      u
   else
      mvar u .** (ldeg u / n) .* lc u .+ sfto_decdegf1(red u,k,n);

asserted procedure sfto_reorder(u: SF, v: Kernel);
   % Reorder. Returns [u] reorderd wrt. [{v}] without modifiying the current
   % kernel order.
   begin scalar w;
      w := setkorder {v};
      u := reorder u;
      setkorder w;
      return u
   end;

asserted procedure sfto_lreorder(u: SF, vl: List);
   % List reorder. Returns [u] reorderd wrt. [vl] without modifiying the current
   % kernel order.
   begin scalar w;
      w := setkorder vl;
      u := reorder u;
      setkorder w;
      return u
   end;

asserted procedure sfto_groebnerf(l: List): List;
   % Groebner calculation standard form. [l] is a list of SF's. Returns a list
   % of SF's. The returned list is the reduced Groebner basis of [l] wrt. the
   % current term order.
   begin scalar w;
      if null l then return nil;
      w := groebnereval {'list . for each sf in l collect prepf sf};
      return for each x in cdr w collect
	 numr simp x
   end;

asserted procedure sfto_preducef(f: SF, gl: List): SF;
   % Polynomial reduction standard form. [gl] is a list of SF's. Returns the
   % numerator of [f] reduced modulo [gl].
   if null gl then
      f
   else if (null cdr gl) and (domainp car gl) then
      nil
   else
      numr simp preduceeval {prepf f,'list . for each sf in gl collect prepf sf};

asserted procedure sfto_greducef(f: SF, gl: List): SF;
   % Polynomial reduction standard form. [gl] is a list of SF's. Returns [f]
   % reduced modulo a Groebner basis of [gl].
   if null gl then
      f
   else if (null cdr gl) and (domainp car gl) then
      nil
   else
      numr simp greduceeval {prepf f,'list . for each sf in gl collect prepf sf};

asserted procedure sfto_gcdf!*(f: SF, g: SF): SF;
   % Greatest common divisor of standard forms. Returns the GCD of [f] and [g].
   % Compute the GCD of [f] and [g] via [gcdf!*] or [ezgcdf] according to
   % Davenport's criterion: If, in one polynomial, the number of variables of a
   % degree greater than 2 is greater than 1, then use [ezgcd].
   sfto_gcdf(f,g) where !*gcd=t;

asserted procedure sfto_gcdf(f: SF, g: SF): SF;
   % Greatest common divisor of standard forms. Returns the GCD of [f] and [g]
   % computed via [gcdf!*] or [ezgcdf] according to Davenport's criterion: If,
   % in one polynomial, the number of variables of a degree greater than 2 is
   % greater than 1, then use [ezgcd]. For computing the real gcd of [f] ang [g]
   % this asserted procedures require, that [!*gcd] is set to [T].
   if null !*rldavgcd then
      gcdf(f,g)
   else if sfto_davp(f,nil) or sfto_davp(g,nil) then
      gcdf(f,g) where !*ezgcd=nil
   else
      ezgcdf(f,g);

asserted procedure sfto_davp(f: SF, badv: ExtraBoolean): Boolean;
   % Davenport predicate. [v] is a kernel or [nil]. Returns [t] if [gcdf] if
   % heuristically considered more efficient than [ezgcdf].
   if domainp f then
      t
   else if ldeg f > 2 then
      if badv and mvar f neq badv then
	 nil
      else
	 sfto_davp(lc f,mvar f) and sfto_davp(red f,mvar f)
   else
      sfto_davp(lc f,badv) and sfto_davp(red f,badv);

asserted procedure sfto_sqrtf(f: SF): ExtraBoolean;
   % Square root standard form. Returns [nil] or an SF $g$, such that $g^2=[f]$.
   begin scalar a,c,w,sd,result;
      c := sfto_dcontentf(f);
      result := isqrt c;
      if result**2 neq c then
	 return nil;
      sd := sfto_sqfdecf(f);
      w := sd;
      while sd do <<
	 a := car sd;
      	 sd := cdr sd;
	 if not(evenp cdr a) and car a neq 1 then <<
 	    sd := nil;
	    a := 'break
	 >> else
	    result := multf(result,exptf(car a,cdr a / 2 ))
      >>;
      if a neq 'break and exptf(result,2) = f then
	 return result
   end;

asserted procedure sfto_monfp(sf: SF): Boolean;
   % Monomial predicate. Check if [sf] is of the form $a x_1 \dots x_n$ for a
   % domain element $a$ and kernels $x_i$.
   domainp sf or (null red sf and sfto_monfp lc sf);

asserted procedure sfto_sqfpartz(z: Integer): Integer;
   % Square free part of an integer. [z] is an integer with prime decomposition
   % $p_1^{e_1}\cdots p_n^{e_n}$. Returns $\prod \{p_i\}$.
   sfto_zdgen(z,0);

asserted procedure sfto_zdeqn(z: Integer, n: Integer): Integer;
   % Z decomposition equal n. [z] is an integer with prime decomposition
   % $p_1^{e_1}\cdots p_m^{e_m}$; [n] is a positive integer. Returns $\prod
   % \{p_i:e_i=n\}$.
   for each x in zfactor z product
      if cdr x = n then car x else 1;

asserted procedure sfto_zdgtn(z: Integer, n: Integer): Integer;
   % Z decomposition greater than n. [z] is an integer with prime decomposition
   % $p_1^{e_1}\cdots p_n^{e_n}$; [n] is a positive integer. Returns $\prod
   % \{p_i:e_i>n\}$.
   for each x in zfactor z product
      if cdr x > n then car x else 1;

asserted procedure sfto_zdgen(z: Integer, n: Integer): Integer;
   % Z decomposition greater than or equal to n. [z] is an integer with prime
   % decomposition $p_1^{e_1}\cdots p_n^{e_n}$; [n] is a positive integer.
   % Returns $\prod \{p_i:e_i\geq n\}$.
   for each x in zfactor z product
      if cdr x >= n then car x else 1;

asserted procedure sfto_exteucf(a: SF, b: SF): List3;
   % Extended Euclidean Algorithm for polynomials. [a], [b] are univariate
   % polynomials both in the same variable. Returns a list $(g,s,t)$ of SQ such
   % that $\gcd([a],[b])=g=s[a]+t[b]$. If the GCD $g$ is a domain element, then
   % it is normalized to $1$.
   begin scalar w,s,tt,u,v,s1,t1,!*rational;
      on1 'rational;
      s := numr simp 1;
      tt := numr simp 0;
      u := numr simp 0;
      v := numr simp 1;
      while not null b do <<
	 w := qremf(a,b);
	 a := b;
	 b := cdr w;
	 s1 := s;
	 t1 := tt;
	 s := u;
	 tt := v;
	 u := addf(s1,negf multf(car w,u));
	 v := addf(t1,negf multf(car w,v))
      >>;
      if domainp a then <<
	 s := quotf(s,a);
	 tt := quotf(tt,a);
	 a := 1
      >>;
      off1 'rational;
      return {resimp !*f2q a,resimp !*f2q s,resimp !*f2q tt}
   end;

asserted procedure exteuc(a: AmPoly, b: AmPoly): AmList;
   begin scalar af,bf,ka,kb;
      af := numr simp a;
      bf := numr simp b;
      if domainp af and domainp bf then
	 return 'list . sfto_exteucd(a,b);
      ka := kernels af;
      if (ka and cdr ka) or (kb and cdr kb) then
	 rederr "non-univariate input polynomial";
      return 'list . for each x in sfto_exteucf(af,bf) collect prepsq x
   end;

asserted procedure sfto_exteucd(a: Integer, b: Integer): List3;
   % Extended Euclidean Algorithm for domain elements (integers). Returns a list
   % $(g,s,t)$ of numbers such that $g>=0$ and $\gcd([a],[b])=g=s[a]+t[b]$.
   begin integer s,tt,u,v,s1,t1,q,r;
      s := 1;
      v :=  1;
      while not eqn(b,0) do <<
	 q := a / b;
	 r := remainder(a,b);
	 a := b;
	 b := r;
	 s1 := s;
	 t1 := tt;
	 s := u;
	 tt := v;
	 u := s1 - q * u;
	 v := t1 - q * v
      >>;
      if a < 0 then <<
	 s := -s;
	 tt := -tt;
	 a := -a
      >>;
      return {a,s,tt}
   end;

asserted procedure sfto_linp(f: SF, vl: List): ExtraBoolean;
   % Linear predicate. [vl] is a list of variables. Returns [T] iff [f] is
   % linear in [vl].
   sfto_linp1(f,vl,nil);

asserted procedure sfto_linp1(f: SF, vl: List, oc: List): ExtraBoolean;
   domainp f or
      (not(mvar f memq vl) and not(mvar f memq oc) and
	 sfto_linp1(lc f,vl,oc) and sfto_linp1(red f,vl,oc)) or
      (mvar f memq vl and not(mvar f memq oc) and ldeg f = 1 and
	 sfto_linp1(lc f,vl,mvar f . oc) and sfto_linp1(red f,vl,oc));

asserted procedure sfto_linwpp(f: SF, vl: List): Boolean;
   % Linear and weakly parametric predicate. [vl] is a list of variables.
   % Returns [t] iff [f] is linear and weakly parametric in [vl].
   domainp f or
      (not(mvar f memq vl) and null intersection(kernels lc f,vl) and
	 sfto_linwpp(red f,vl)) or
      (mvar f memq vl and ldeg f = 1 and domainp lc f and
	 sfto_linwpp(red f,vl));

asserted procedure sfto_varf(f: SF): ExtraBoolean;
   % Variable form. If [f] is a variable then return the corresponding kernel
   % else return [nil]. In contrast to sfto_idvarf, this function rerturn also
   % non-atomic kernels.
   if not domainp f and null red f and eqn(lc f,1) and eqn(ldeg f,1) then
      mvar f;

asserted procedure sfto_idvarf(f: SF): ExtraBoolean;
   % Identifier variable form. If [f] is an atomic variable then return the
   % corresponding identifier else return [nil].
   if not domainp f and
      null red f and eqn(lc f,1) and eqn(ldeg f,1) and idp mvar f
   then
      mvar f;

asserted procedure sfto_lmultf(fl: List): SF;
   % Ordered field standard form list multf. [fl] is a list of SF. Returns the
   % product of the SFs in [fl].
   if null fl then 1 else multf(car fl,sfto_lmultf cdr fl);

asserted procedure degree(u: AmPoly): Integer;
   sfto_tdegf numr simp u;

asserted procedure sfto_tdegf(f: SF): Integer;
   % Ordered field standard form total degree standard form. Returns the total
   % degree of [f].
   begin scalar w,x; integer td;
      if domainp f then
      	 return 0;
      x := mvar f;
      while not domainp f and mvar f eq x do <<
	 w := sfto_tdegf lc f + ldeg f;
	 if w > td then
	    td := w;
	 f := red f
      >>;
      w := sfto_tdegf f;
      if  w > td then
	 return w;
      return td
   end;

asserted procedure coefficients(f: AmPoly, vl: AmList): AmList;
   'list . for each c in sfto_allcoeffs(numr simp f,cdr vl) collect
      prepf c;

asserted procedure sfto_allcoeffs(f: SF, vl: List): List;
   sfto_allcoeffs1({f},vl);

asserted procedure sfto_allcoeffs1(l: List, vl: List): List;
   if null vl then
      l
   else
      sfto_allcoeffs1(for each f in l join
	 sfto_coefs(sfto_reorder(f,car vl),car vl),cdr vl);

asserted procedure sfto_coefs(f: SF, v: Kernel): List;
   if not domainp f and mvar f eq v then coeffs f else {f};

asserted procedure sfto_abssummand(f: SF): Integer;
   if domainp f then f else sfto_abssummand red f;

asserted procedure sfto_kernelp(u: Any): ExtraBoolean;
   begin scalar w;
      if idp u then
 	 return t;
      if not pairp u then
 	 return nil;
      if get(car u,'fkernfn) then
	 return t;
      w := if atom car u then get(car u,'klist) else exlist!*;
      return atsoc(u,w)
   end;

asserted procedure sfto_varp(f: SF): ExtraBoolean;
   % Returns [k] if $[f] = 1*[k]^1+nil$, return [nil] else.
   if not domainp f and null red f and eqn(lc f,1) and eqn(ldeg f,1) then
      mvar f;

asserted procedure sfto_varIsNumP(f: SF): ExtraBoolean;
   % Returns [k] if $[f] = d1*[k]^1+d2$ for domain elements [d1], [d2], return
   % [nil] else.
   if not domainp f and domainp lc f and domainp red f and eqn(ldeg f,1) then
      mvar f;

asserted procedure sfto_fctrf(f: SF): List;
   begin scalar w;
      w := errorset({'fctrf, mkquote f}, t, !*backtrace);
      if errorp w then
	 return {1, f . 1};
      return car w
   end;

asserted procedure sfto_int2sf(n: Integer): SF;
   if n neq 0 then n;

asserted procedure sfto_sf2int(n: Integer): SF;
   n or 0;

asserted procedure sfto_sf2monl(f: SF): DottedPair;
   begin scalar vl;
      vl := sort(kernels f, 'ordop);
      return vl . sfto_sf2monl1(f, vl)
   end;

asserted procedure sfto_sf2monl1(f: SF, vl: List): List;
   begin scalar rl, ll;
      if null f then
	 return nil;
      if domainp f then
	 return {(for each v in vl collect 0) . f};
      if not eqcar(vl, mvar f) then
	 return for each pr in sfto_sf2monl1(f, cdr vl) collect
	    (0 . car pr) . cdr pr;
      ll := for each pr in sfto_sf2monl1(lc f, cdr vl) collect
 	 (ldeg f . car pr) . cdr pr;
      rl := sfto_sf2monl1(red f, vl);
      return append(ll, rl)
   end;

asserted procedure sfto_sf2monlip(f: SF): DottedPair;
   begin scalar vl;
      vl := sort(kernels f, 'ordop);
      return vl . sfto_sf2monlip1(f, vl)
   end;

asserted procedure sfto_sf2monlip1(f: SF, vl: List): List;
   begin scalar monl, rmonl;
      if null f then
	 return nil;
      if domainp f then
	 return {(for each v in vl collect 0) . f};
      if not eqcar(vl, mvar f) then <<
	 monl := sfto_sf2monlip1(f, cdr vl);
	 for each pr in monl do
	    car pr := 0 . car pr;
	 return monl
      >>;
      monl := sfto_sf2monlip1(lc f, cdr vl);
      for each pr in monl do
 	 car pr := ldeg f . car pr;
      rmonl := sfto_sf2monlip1(red f, vl);
      return nconc(monl, rmonl)
   end;

asserted procedure sfto_mvartest(f: SF, x: Kernel): Boolean;
   % Main variable test. Returns [t] iff [x] is the main variable of [f].
   not domainp f and mvar f eq x;

asserted procedure sfto_mvarx(f: SF): SF;
   % Main variable, extended version. Returns the mvar of [f]. If [f] is a
   % domain element (integer), [f] is returned.
   if domainp f then nil else mvar f;

asserted procedure sfto_ldegx(f: SF): Integer;
   % Leading degree, extended version. Returns the leading coeffcient of [f]. If
   % [f] represents zero, -1 is returned. If [f] represents a domain element
   % (integer), 0 is returned.
   if null f then
      -1
   else if domainp f then
      0
   else
      ldeg f;

asserted procedure sfto_lcx(f: SF): SF;
   % Leading coefficient, extended version. Returns the leading coefficient of
   % [f]. If [f] is a domain element (integer), [f] is returned.
   if domainp f then f else lc f;

asserted procedure sfto_redx(f: SF): SF;
   % Reductum, extended version. Returns the reductum of [f]. If [f] is a domain
   % element (integer) [f] is returned.
   if domainp f then nil else red f;

asserted procedure sfto_vardeg(f: SF, x: Kernel): Integer;
   % Degree of a variable. Returns the degree of [x] in [f] provided that [x] is
   % the main variable of [f].
   if sfto_mvartest(f, x) then ldeg f else if null f then -1 else 0;

asserted procedure sfto_univarp(f: SF): Boolean;
   % Univariate predicate. Returns [t] iff [f] contains at most one variable.
   domainp f or (domainp lc f and sfto_univarp1(red f, mvar f));

asserted procedure sfto_univarp1(f: SF, x: Kernel): Boolean;
   domainp f or (domainp lc f and mvar f eq x and sfto_univarp1(red f, x));

asserted procedure sfto_kmemberf(x: Kernel, f: SF): ExtraBoolean;
   not domainp f and (mvar f eq x or sfto_kmemberf(x, lc f) or sfto_kmemberf(x, red f));

asserted procedure sfto_renamef(f: SF, vold: Kernel, vnew: Kernel): SF;
   begin scalar mv, recurse;
      if domainp f then
	 return f;
      mv := mvar f;
      if mv eq vold then <<
	 mv := vnew;
	 recurse := nil
      >> else
      	 recurse := t;
      return addf(multf(exptf(!*k2f mv, ldeg f),
	 if recurse then sfto_renamef(lc f, vold, vnew) else lc f),
	 sfto_renamef(red f, vold, vnew))
   end;

asserted procedure sfto_renamealf(f: SF, al: Alist): SF;
   % TODO: More efficient with sorted [al].
   begin scalar mv, w, al1;
      if domainp f then
	 return f;
      mv := mvar f;
      if (w := atsoc(mv, al)) then <<
	 mv := cdr w;
	 al1 := lto_delq(w, al)
      >> else
	 al1 := al;
      return addf(multf(exptf(!*k2f mv, ldeg f), sfto_renamealf(lc f, al1)),
	 sfto_renamealf(red f, al))
   end;

asserted procedure sfto_cauchyf(f: SF, v: Kernel): SQ;
   % The Cauchy bound of [f] with respect to [v]. We assume that [f] is
   % univariate in [v] and [mvar f eq v], in particular [f] is not a domain
   % element.
   begin scalar sumq, an, d, one;
      sumq := nil ./ 1;
      an := !*f2q absf lc f;
      while not domainp f do <<
	 f := red f;
	 d := !*f2q absf if domainp f then f else lc f;
	 sumq := addsq(sumq, quotsq(d, an))
      >>;
      one := 1 ./ 1;
      if sfto_greaterq(one, sumq) then
	 return one;
      return sumq
   end;

asserted procedure sfto_lmq(f: SF): SQ;
   begin
      scalar cl, c, cmin, sccl1, sccl2, cc, trp, ttrp, ctrp, bnd, cmax;
      integer d, m, dd, mm;
      assert(not null f);
      if domainp f then
	 return 0;
      f := absf f;
      cl := sfto_lmqcoeffs f;
      cmax := nil ./ 1;
      sccl1 := cdr cl;
      while sccl1 do <<
	 {c, d, m} := trp := pop sccl1;
	 if numr c < 0 then <<
   	    cmin := 'pinf;
	    sccl2 := cl;
	    repeat <<
	       {cc, dd, mm} := ttrp := pop sccl2;
	       if numr cc > 0 then <<
		  bnd := sfto_lmqrootq(multsq(!*f2q(2^mm), quotsq(negsq c, cc)), dd - d);
		  if cmin eq 'pinf or sfto_lessq(bnd, cmin) then <<
		     cmin := bnd;
		     ctrp := ttrp
		  >>
	       >>
	    >> until car sccl2 eq trp;
	    caddr ctrp := caddr ctrp + 1;  % We could actually choose.
	    if sfto_greaterq(cmin, cmax) then
	       cmax := cmin
	 >>
      >>;
      return cmax
   end;

asserted procedure sfto_lmqcoeffs(f: SF): List;
   % [f] is a univariate SF.
   if domainp f then
      {{!*f2q f, 0, 1}}
   else
      {!*f2q lc f, ldeg f, 1} . sfto_lmqcoeffs red f;

asserted procedure sfto_lmqrootq(q: SQ, n: Integer): SQ;
   % [q] is a non-negative number; [n] is positive.
   begin scalar rnum, rden;
      assert(null car q or (numberp car q and car q >= 1));
      assert(numberp cdr q);
      assert(n > 0);
      if eqn(n, 1) or null numr q then
 	 return q;
      rnum := if eqn(numr q, 1) then numr q else irootn(numr q or 0, n) + 1;
      if eqn(denr q, 1) then
	 return rnum ./ 1;
      rden := irootn(denr q, n) - 1;
      if rden > 1 then rden := rden - 1;
      return quotsq(rnum ./ 1, rden ./ 1)
   end;

asserted procedure sfto_lmqroot(q: SQ, n: Integer): Integer;
   begin scalar w, p;
      w := numr sfto_ceilq q or 0;
      p := length explode w + 1;
      return numr sfto_ceilq sfto_rootq(q, n, p)
   end;

asserted procedure sfto_mirror(f: SF): SF;
   if domainp f then
      f
   else
      sfto_fsub1(f, {mvar f . negf !*k2f mvar f});

asserted procedure sfto_qsub(f: SF, al: Alist): SQ;
   sfto_qsub1(f, sort(al, function ordopcar));

asserted procedure sfto_qsub1(f: SF, al: Alist): SQ;
   begin scalar mv, nredq, nlcq, nhtq;
      if domainp f then
	 return !*f2q f;
      mv := mvar f;
      while al and caar al neq mv and ordop(caar al, mv) do
	 al := cdr al;
      if null al then
	 return !*f2q f;
      nredq := sfto_qsub1(red f, al);
      if caar al eq mv then <<
	 nlcq := sfto_qsub1(lc f, cdr al);
	 nhtq := exptsq(cdar al, ldeg f);
	 return addsq(multsq(nlcq, nhtq), nredq)
      >>;
      nlcq := sfto_qsub1(lc f, al);
      nhtq := !*f2q(mvar f .** ldeg f .* 1 .+ nil);
      return addsq(multsq(nlcq, nhtq), nredq)
   end;

asserted procedure sfto_fsub(f: SF, al: Alist): SF;
   sfto_fsub1(f, sort(al, function(lambda(x,y); ordop(car x, car y))));

asserted procedure sfto_fsub1(f: SF, al: Alist): SF;
   begin scalar mv, nred, nlc, nht;
      if domainp f then
	 return f;
      mv := mvar f;
      while al and caar al neq mv and ordop(caar al, mv) do
	 al := cdr al;
      if null al then
	 return f;
      nred := sfto_fsub1(red f, al);
      if caar al eq mv then <<
	 nlc := sfto_fsub1(lc f, cdr al);
	 nht := exptf(cdar al, ldeg f);
	 return addf(multf(nlc, nht), nred)
      >>;
      nlc := sfto_fsub1(lc f, al);
      nht := mvar f .** ldeg f .* 1 .+ nil;
      return addf(multf(nlc, nht), nred)
   end;

asserted procedure sfto_qsubhor(f: SF, x: Kernel, q: SQ): SQ;
   % Substitute a rational number by Horner's scheme. Correctness is guaranteed
   % iff [x] is geq than [mvar f] under the current kernel ordering, i.e., [x]
   % occurs in [f] iff it is [mvar f].
   begin scalar coeffl, res;
      if not sfto_mvartest(f, x) then
	 return !*f2q f;
      coeffl := coeffs f;
      res := !*f2q car coeffl;
      for each coeff in cdr coeffl do
	 res := addsq(!*f2q coeff, multsq(res, q));
      return res
   end;

asserted procedure sfto_qsubhor1(f: SF, x: Kernel, q: SQ): SQ;
   % Substitute a rational number by Horner's scheme. The result is exact up to
   % multiplication by a positive rational number. Correctness is guaranteed iff
   % [x] is geq than [mvar f] under the current kernel ordering, i.e., [x]
   % occurs in [f] iff it is [mvar f].
   begin scalar coeffl, res; integer n, d, dd;
      if not sfto_mvartest(f, x) then
   	 return !*f2q f;
      n := numr q;
      d := denr q;
      dd := 1;
      coeffl := coeffs f;
      res := car coeffl;
      for each coeff in cdr coeffl do <<
	 dd := dd * d;
	 res := addf(multf(coeff, dd), multf(res, n))
      >>;
      return !*f2q sfto_dprpartksf res
   end;

asserted procedure sfto_floatsub(f: SF, subl: Alist): Floating;
   % All kernels in f must be bound to a lisp float in subl.
   if domainp f then
      f or 0.0
   else
      cdr atsoc(mvar f, subl)^ldeg f * sfto_floatsub(lc f, subl) + sfto_floatsub(red f, subl);

asserted procedure sfto_norm1(f: SF): Integer;
   % [f] is univariate. Sum of the absolute values of the coefficients of [f].
   if domainp f then absf f else addf(absf lc f, sfto_norm1 red f);

asserted procedure sfto_norminf(f: SF): Integer;
   % [f] is univariate. Maximum of the absolute values of the coefficients of
   % [f].
   if domainp f then absf f else max(absf lc f, sfto_norminf red f);

asserted procedure sfto_sturmchain(f: SF, g: SF): List;
   % [f] and [g] are univariate with integer coefficients. We compute the
   % suppressed standard Sturm chain over the rationals and then drop the
   % positive principal denominators so that the result is a list of univariate
   % SF.
   begin scalar !*rational, w, rresl, resl;
      on1 'rational;
      rresl := {g, f};
      while not null g do <<
	 w := remf(f, g);
	 f := g;
	 g := negf w;
	 if g then rresl := g . rresl
      >>;
      for each p in rresl do
	 resl := quotf(p, g) . resl;
      off1 'rational;
      resl := for each p in resl collect numr resimp !*f2q p . resl;
      return resl
   end;

asserted procedure sfto_sturmcount(sc: List, l: SQ, u: SQ): Integer;
   % [l] and [u] are numbers or one of +/- infinity
   sfto_varsign(sc, l) - sfto_varsign(sc, u);

asserted procedure sfto_varsign(sc: List, bound: SQ): Integer;
   % Sturm chain sign variations. The Sturm chain [sc] is a list of univariate
   % SFs. [bound] is a number or one of +/- infinity.
   begin integer h, sign, cursign, signchanges;
      while sc do <<
	 repeat <<
	    h := numr sfto_iqsub(pop sc, mvar h, bound);
	    sign := if null h then 0 else if minusf h then -1 else 1;
	 >> until null sc or not eqn(sign, 0);
	 if sign * cursign < 0 then
	    signchanges := signchanges + 1;
	 cursign := sign
      >>;
      return signchanges
   end;

asserted procedure sfto_iqsub(f: SF, x: Kernel, q: SQ): SQ;
   begin scalar g, hc;
      g := numr q;
      if domainp g then
	 return sfto_qsub1(f, {x . q});
      if domainp f then
	 return !*f2q f;
      assert(mvar g eq 'infinity);
      if evenp ldeg f and minusf lc g then
	 q := negsq q;
      if minusf lc f then
	 q := negsq q;
      return q
   end;


% SQ functions:

asserted procedure sfto_absq(q: SQ);
   absf numr q ./ denr q;

asserted procedure sfto_greaterq(q1: SQ, q2: SQ): ExtraBoolean;
   minusf numr subtrsq(q2, q1);

asserted procedure sfto_lessq(q1: SQ, q2: SQ): ExtraBoolean;
   minusf numr subtrsq(q1, q2);

asserted procedure sfto_geqq(q1: SQ, q2: SQ): ExtraBoolean;
   (null w or minusf numr w) where w=subtrsq(q2, q1);

asserted procedure sfto_leqq(q1: SQ, q2: SQ): ExtraBoolean;
   (null w or minusf numr w) where w=subtrsq(q1, q2);

asserted procedure sfto_maxq(q1: SQ, q2: SQ): SQ;
   if sfto_greaterq(q1, q2) then q1 else q2;

asserted procedure sfto_minq(q1: SQ, q2: SQ): SQ;
   if sfto_lessq(q1, q2) then q1 else q2;

asserted procedure sfto_maxql(l: List): SQ;
   % [l] is a nonempty list.
   begin scalar m;
      assert(l);
      m := car l;
      for each q in cdr l do
	 if sfto_greaterq(q, m) then
	    m := q;
      return m
   end;

asserted procedure sfto_minql(l: List): SQ;
   % [l] is a nonempty list.
   begin scalar m;
      assert(l);
      m := car l;
      for each q in cdr l do
	 if sfto_lessq(q, m) then
	    m := q;
      return m
   end;

asserted procedure sfto_ceilq(q: SQ): SQ;
   if eqn(denr q, 1) then
      q
   else if minusf numr q then
      !*f2q sfto_int2sf(numr q / denr q)
   else
      !*f2q sfto_int2sf(numr q / denr q + 1);

asserted procedure sfto_floorq(q: SQ): SQ;
   if null numr q then
      q
   else if minusf numr q then
      !*f2q sfto_int2sf(numr q / denr q - 1)
   else
      !*f2q sfto_int2sf(numr q / denr q);

asserted procedure sfto_truncq(q: SQ, d: Integer): SQ;
   begin scalar shiftq;
      shiftq := 10 ^ d ./ 1;
      return quotsq(sfto_floorq multsq(q, shiftq), shiftq)
   end;

asserted procedure sfto_multlq(sql: List): SQ;
   if null sql then
      1 ./ 1
   else
      multsq(car sql, sfto_multlq cdr sql);

asserted procedure sfto_avgq(q1: SQ, q2: SQ): SQ;
   quotsq(addsq(q1, q2), 2 ./ 1);

asserted procedure sfto_expq(q: SQ, n: Integer): SQ;
   % Non-negative power of SQ.
   if eqn(n, 0) then
      1 ./ 1
   else
      multsq(q, sfto_expq(q, n - 1));

asserted procedure sfto_mkpowq(k: Kernel, pow: Integer): SQ;
   if eqn(pow, 0) then
      1 ./ 1
   else if pow > 0 then
      (((k .** pow) .* 1) .+ nil) ./ 1
   else
      1 ./ (((k .** -pow) .* 1) .+ nil);

asserted procedure sfto_rootq(x: SQ, n: Integer, p: Integer): SQ;
   % n-th root of [x] with precision [p].
   begin scalar op, w;
      op := precision p;
      w := simp evalnum0 {{'expt, prepsq x, {'quotient, 1, n}}};
      precision op;
      return w
   end;

asserted procedure sfto_fsubq(x: SQ, al: Alist): SQ;
   % Substitute SFs into SQ to obtain SQ.
   quotsq(!*f2q sfto_fsub(numr x, al), !*f2q sfto_fsub(denr x, al));

asserted procedure sfto_qsubq(x: SQ, al: Alist): SQ;
   % Substitute SQs into SQ to obtain SQ.
   quotsq(sfto_qsub(numr x, al), sfto_qsub(denr x, al));

endmodule;  % [sfto]

end;  % of file
