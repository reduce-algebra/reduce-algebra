% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% Copyright (c) 2004-2009 Andreas Dolzmann and Thomas Sturm
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
   fluid '(dcfsfqe_rcsid!* dcfsfqe_copyright!*);
   dcfsf_qe_rcsid!* :=
      "$Id$";
   dcfsf_qe_copyright!* := "Copyright (c) 2004-2009 A. Dolzmann and T. Sturm"
>>;

module dcfsfqe;
% Diferentially closed field standard form quantifier elimination.

procedure dcfsf_orddegf(f,v);
   % Diferentially closed field standard form order and degree. [f] is
   % a standard form; [v] is a variable. Returns a pair of numbers.
   % The [car] is the order and the [cdr] is the degree wrt. [v].
   dcfsf_orddegf1(f,v,(-1) . (-1));
   
procedure dcfsf_orddegf1(f,v,od);
   % Diferentially closed field standard form order and degree
   % subroutine. [f] is a standard form; [v] is a variable; [od] is a
   % pair of numbers. Returns a pair of numbers. The [car] is the
   % order and the [cdr] is the degree wrt. [v].
   begin scalar mv,r; integer lord;
      if domainp f then
 	 return od;
      mv := mvar f;
      lord := if mv eq v then
	 0
      else if pairp mv and cadr mv eq v then
	 caddr mv
      else
	 -2;
      if lord > car od then
	 od := lord . ldeg f
      else if lord = car od then
	 od := lord . max(cdr od,ldeg f);
      r := f;
      while not domainp r and mvar r eq mv do
	 r := red r;
      return dcfsf_orddegf1(lc f,v,dcfsf_orddegf1(r,v,od))
   end;

procedure dcfsf_ordf(f,v);
   % Diferentially closed field standard form order. [f] is a standard
   % form with kernel order [{...,(d v 2),(d v 1),v}]; [v] is a
   % variable. Returns a number, the order of [f] wrt. [v].
   if domainp f then
      -1
   else if mvar f eq v then
      0
   else if pairp mvar f and cadr mvar f eq v then
      caddr mvar f
   else
      -1;

procedure dcfsf_degf(f,v);
   % Diferentially closed field standard form order. [f] is a standard
   % form with kernel order [{...,(d v 2),(d v 1),v}]; [v] is a
   % variable. Returns a number, the order of [f] wrt. [v].
   if domainp f then
      0
   else if mvar f eq v or pairp mvar f and cadr mvar f eq v then
      ldeg f
   else
      0;

procedure dcfsf_df(f,x);
   % Diferentially closed field standard form derivative. [f] is a
   % standard form; [x] is a possibly composite kernel. Returns a
   % standard form. Computes the partial derivative of [f] wrt. [x].
   begin scalar oldorder,w;
      oldorder := setkorder {x};
      w := dcfsf_df1(reorder f,x);
      setkorder oldorder;
      return reorder w
   end;

procedure dcfsf_df1(f,x);
   % Diferentially closed field standard form derivative subroutine.
   % [f] is a standard form; [x] is a possibly composite kernel that
   % is largest wrt. the current kernel order. Returns a standard
   % form. Computes the partial derivative of [f] wrt. [x].
   if domainp f or mvar f neq x then
      nil
   else if eqn(ldeg f,1) then
      lc f
   else
      x .** (ldeg f - 1) .* multf(ldeg f,lc f) .+ dcfsf_df1(red f,x);

procedure dcfsf_derivationnf(f,n,theo);
   begin scalar r;
      r := f;
      for i := 1 : n do
	 r := dcfsf_derivationf(r,theo);
      return r
   end;

procedure dcfsf_derivationf(f,theo);
   % Diferentially closed field standard form derivation. [f] is a
   % standard form; [theo] is a theory. Returns a standard form.
   % Computes the  derivative of [f].
   begin scalar res;
      for each v in kernels f do
	 res := addf(res,multf(dcfsf_df(f,v),dcfsf_derivationk(v,theo)));
      return res
   end;

procedure dcfsf_derivationk(k,theo);
   % Diferentially closed field kernel derivation. [k] is a kernel;
   % [theo] is a theory. Returns a standard form. Computes the
   % derivative of [k], which is possibly specified in [theo].
   begin scalar oldorder,kpf,kp,a,cnt;
      kp := dcfsf_derivationk1 k;
      kpf := kp .** 1 .* 1 .+ nil;
      oldorder := setkorder {kp};
      cnt := t;
      while cnt and theo do <<
	 a := car theo;
	 theo := cdr theo;
	 if dcfsf_op a eq 'equal then <<
	    a := dcfsf_arg2l a;
	    if mvar a eq kp and lc a = 1 then <<
	       cnt := nil;
	       kpf := negf red a
	    >>
	 >>
      >>;
      setkorder oldorder;
      return reorder kpf
   end;

procedure dcfsf_derivationk1(k);
   % Diferentially closed field kernel derivation subroutine. [k] is a
   % kernel. Returns a kernel. Computes the derivative of [k].
   if atom k then
      !*a2k {'d,k,1} 
   else
      !*a2k {'d,cadr k,caddr k + 1};
      
	    
procedure dcfsf_qe!-kacem(f,theo);
   begin scalar w;
      f := rl_prepfof f;
      f := cl_pnf f;
      w := dqe_start1 f;
      if w eq t then
	 w := 'true
      else if null w then
	 w := 'false;
      w := rl_simp w;
      return w
   end;

switch kacem;

procedure dcfsf_qe(f,theo);   
   if !*kacem then
      dcfsf_qe!-kacem(f,theo)
   else
      dcfsf_qe0(f,theo);

procedure dcfsf_qe0(f,theo);
   begin scalar w,bl;
      f := cl_simpl(cl_pnf cl_nnf f,theo,-1);
      w := cl_splt f;
      bl := car w;
      f := cadr w;
      for each blk in bl do
	 f := cl_simpl(dcfsf_qeblk(f,blk,theo),nil,-1);
      return f
   end;

procedure dcfsf_qeblk(f,blk,theo);
   if car blk eq 'all then
      rl_nnfnot dcfsf_qeblk1(rl_nnfnot f,blk,theo)
   else
      dcfsf_qeblk1(f,blk,theo);

procedure dcfsf_qeblk1(f,blk,theo);
   <<
      if !*rlverbose then
	 ioto_tprin2t {"Eliminating ",blk};
      for each v in cdr blk do
      	 f := dcfsf_qevar(f,v,theo);
      f
   >>;

procedure dcfsf_qevar(f,v,theo);
   begin scalar rl;
      if !*rlverbose then
	 ioto_tprin2t {"Eliminating ",v};
      f := cl_dnf f;
      rl := if rl_op f eq 'or then 
      	 for each ff in rl_argn f collect
	    dcfsf_qevar1(ff,v,theo)
      else
	 {dcfsf_qevar1(f,v,theo)};
      return rl_smkn('or,rl)
   end;

procedure dcfsf_qevar1(f,v,theo);
   begin scalar r,w;
      if rl_tvalp f then
	 return f;
      w := dcfsf_nf(f,v);
      r := dcfsf_qevar2(car w,cadr w,v,theo);
      r := rl_mkn('and,{rl_smkn('and,caddr w),r});
      return r
   end;

procedure dcfsf_nf(f,v);
      if rl_op f eq 'and then 
	 dcfsf_nf1(rl_argn f,v)
      else
	 dcfsf_nf1({f},v);

procedure dcfsf_nf1(f,v);
   begin scalar e,n,s;
      n := numr simp 1;
      for each at in f do
	 if not(v memq dcfsf_varlat at) then
	    s := at . s
	 else if dcfsf_op at eq 'equal then
	    e := dcfsf_arg2l(at) . e
	 else 
	    n := multf(dcfsf_arg2l at,n);	       
      return {e,n,s}
   end;


procedure dcfsf_qevar2(fl,g,v,theo);
   % Special case on page 5.
   begin scalar oo,kl,r;      
      kl := dcfsf_mkkl(v,dcfsf_maxorder(g . fl,v));
      oo := setkorder kl;
      fl := for each f in fl collect reorder f;
      g := reorder g;
      r := dcfsf_qesc5(fl,g,v,theo);
      setkorder oo;
      return cl_apply2ats(r,'dcfsf_reorderat)
   end;

procedure dcfsf_reorderat(a);
   if rl_tvalp a then
      a
   else
      dcfsf_0mk2(dcfsf_op a,reorder dcfsf_arg2l a);
      
procedure dcfsf_maxorder(fl,v);
   begin scalar w; integer m;
      for each f in fl do <<
	 w := dcfsf_orddegf(f,v);
	 if car w > m then
	    m := car w
      >>;
      return m
   end;

procedure dcfsf_mkkl(v,m);
   reversip(v . for i := 1 : m collect !*a2k {'d,v,i});

procedure dcfsf_qesc5(fl,g,v,theo);
   % Special case on page 5.
   <<
      fl := sort(fl,'dcfsf_qeordp);
      if !*rlverbose then
	 ioto_prin2 {"[",length fl,dcfsf_orddegf(lastcar fl,v),"] "};
      if null fl then
	 dcfsf_qesc1(g,v,theo)
      else if null cdr fl then
	 if g = 1 then
	    dcfsf_qesc2(car fl,v,theo)
	 else 
	    dcfsf_qebasis(car fl,g,v,theo)
      else
      	 dcfsf_qesc5r(fl,g,v,theo)
   >>;

procedure dcfsf_qesc50(fl,g,v,theo);
   begin scalar nfl,r,f,pl;
      if null g then
	 return 'false;
      if domainp g then
	 g := 1;
      while fl do <<
	 f := car fl;
	 fl := cdr fl;
	 if domainp f then <<
	    if f then <<
	       r := 'false;
	       fl := nil
	    >>
	 >> else if not(v memq dcfsf_varlat1 kernels f) then
	    pl := dcfsf_0mk2('equal,f) . pl
	 else
	    nfl := f . nfl;
      >>;
      if r eq 'false then
	 return 'false;
      r := dcfsf_qesc5(nfl,g,v,theo);
      r := rl_mkn('and,{rl_smkn('and,pl),r});
      return r
   end;

procedure dcfsf_qeordp(f1,f2);
   begin scalar p1,p2,v;
      v := dcfsf_mvar f1;
      p1 := dcfsf_orddegf(f1,v);
      p2 := dcfsf_orddegf(f2,v);
      return car p1 > car p2 or car p1 = car p2 and cdr p1 > cdr p2
   end;

procedure dcfsf_qebasis(f1,g,v,theo);
   if null g then
      'false
   else if domainp g then
      dcfsf_qesc2(f1,v,theo)
   else if dcfsf_ordf(g,v) leq dcfsf_ordf(f1,v) then
      dcfsf_qebasis1(f1,g,v,theo)
   else
      dcfsf_qebasis2(f1,g,v,theo);

switch dzopt;

procedure dcfsf_qebasis1(f1,g,v,theo);
   begin scalar phi1p,phi2p;
      if !*dzopt and null cdr qremf(g,lc f1) then <<
	 phi1p := 'false;
	 phi2p := dcfsf_qesc(f1,lc f1,g,v,theo);
      >> else <<
      	 phi1p := dcfsf_qesc50({red f1,lc f1},g,v,theo);
	 phi1p := cl_simpl(phi1p,theo,-1);
      	 if phi1p eq 'true then
	    return 'true;
      	 phi2p := dcfsf_qesc(f1,lc f1,g,v,theo);
      >>;
      return cl_simpl(rl_mkn('or,{phi1p,phi2p}),theo,-1);
   end;

procedure dcfsf_qebasis2(f1,g,v,theo);
   begin scalar psi,sp,s1,sf1,if1,qr,r,dp,phi1p,phi3p,r;
      if1 := lc f1;
      sp := dcfsf_ordf(g,v);
      s1 := dcfsf_ordf(f1,v);
      sf1 := dcfsf_separant f1;
      dp := dcfsf_degf(g,v);
      qr := qremf(multf(exptf(sf1,dp),g),dcfsf_dn(f1,sp-s1,v,theo));
      r := cdr qr;      
      if !*dzopt and null cdr qremf(g,lc f1) then <<
	 if1 := 1;
	 phi1p := 'false;
      >> else 
      	 phi1p := dcfsf_qesc50({red f1,lc f1},g,v,theo);      
      phi1p := cl_simpl(phi1p,theo,-1); 
      if phi1p eq 'true then
	 return 'true;      
      if dcfsf_degf(f1,v) > 1 then << 
      	 psi := dcfsf_qebasis(f1,multf(multf(sf1,if1),r),v,theo);	 
      	 phi3p := dcfsf_qesc50({f1,sf1},g,v,theo);
	 r := rl_mkn('or,{phi1p,psi,phi3p});
      >> else <<
      	 psi := dcfsf_qebasis(f1,multf(if1,r),v,theo);
	 r := rl_mkn('or,{phi1p,psi})
      >>;
      return r
   end;

procedure dcfsf_mvar(f);
   if domainp f then
      nil
   else if pairp mvar f and car f eq 'd then
      cadr mvar f
   else
      mvar f;

procedure dcfsf_separant(f);
   dcfsf_df(f,mvar f);

procedure dcfsf_qesc5r(fl,g,v,theo);
   begin scalar phi1p,phi2p,fm,ffl;
      ffl := reverse fl;
      fm := car ffl;
      if !*dzopt and null cdr qremf(g,lc fm) then
	 phi1p := 'false
      else
      	 phi1p := dcfsf_qesc50(red fm . lc fm . cdr ffl,g,v,theo);
      phi2p := dcfsf_qesc5r2(fl,g,v,theo);
      return rl_mkn('or,{phi1p,phi2p})
   end;

procedure dcfsf_qesc5r2(fl,g,v,theo);
   begin scalar ffl,fm,fm1;
      ffl := reverse fl;
      fm := car ffl;
      ffl := cdr ffl;
      fm1 := car ffl;
      ffl := cdr ffl;
      if dcfsf_ordf(fm,v) = dcfsf_ordf(fm1,v) then
	 return dcfsf_qesc5r2u1(fm,fm1,ffl,g,v,theo);
      return dcfsf_qesc5r2u2(fm,fm1,ffl,g,v,theo)
   end;

procedure dcfsf_qesc5r2u1(fm,fm1,ffl,g,v,theo);
   begin scalar dm1,ifm,qr,r,psip;
      dm1 := dcfsf_degf(fm1,v);
      ifm := lc fm;
      qr := qremf(multf(exptf(ifm,dm1),fm1),fm);
      r := cdr qr;
      if !*dzopt and null cdr qremf(g,lc fm) then
	 psip := dcfsf_qesc50(fm . r . ffl,g,v,theo)
      else
      	 psip := dcfsf_qesc50(fm . r . ffl,multf(ifm,g),v,theo);
      return psip
   end;

procedure dcfsf_qesc5r2u2(fm,fm1,ffl,g,v,theo);
   begin scalar sfm,dm1,qr,r,sm,sm1,psip,ifm;
      sfm := dcfsf_separant fm;
      dm1 := dcfsf_degf(fm1,v);
      sm := dcfsf_ordf(fm,v);
      sm1 := dcfsf_ordf(fm1,v);
      ifm := lc fm;
      qr := qremf(multf(exptf(sfm,dm1),fm1),
	 dcfsf_dn(fm,sm1-sm,v,theo));
      r := cdr qr;
      if !*dzopt and null cdr qremf(g,lc fm) then
      	 psip := dcfsf_qesc50(fm . r . ffl,g,v,theo)
      else
      	 psip := dcfsf_qesc50(fm . r . ffl,multf(ifm,g),v,theo);	    
      return psip
   end;


procedure dcfsf_dn(f,n,v,theo);
   begin scalar r,s,m;
      m := if kord!* and pairp car kord!* and car car kord!* eq 'd then
	 caddr car kord!* else 0;
      s := car dcfsf_orddegf(f,v);
      m := max(m,s+n);
      setkorder dcfsf_mkkl(v,m);
      r := reorder f;
      for i := 1 : n do
      	 r := dcfsf_derivationf(r,theo);
      return reorder r;
   end;

procedure dcfsf_qesc1(g,v,theo);
   rl_smkn('or,for each gt in dcfsf_cl(g,v) collect dcfsf_0mk2('neq,gt));

procedure dcfsf_cl(f,v);
   if domainp f or not(v memq dcfsf_varlat1 kernels f) then
      {f}
   else
      nconc(dcfsf_cl(lc f,v),dcfsf_cl(red f,v));

procedure dcfsf_cl1(f,v);
   dcfsf_cl2(f,v,T);
   
procedure dcfsf_cl2(f,v,flg);
   begin scalar w;
      if domainp f or not(v memq dcfsf_varlat1 kernels f) then
      	 return if flg then
	    nil . f
      	 else
      	    {f} . nil
      else <<
	 w := dcfsf_cl2(red f,v,T);
      	 return nconc(car dcfsf_cl2(lc f,v,nil),car w) . cdr w
      >>
   end;

procedure dcfsf_qesc(f1,if1,g,v,theo);
   begin    
      if null g or null if1 then
      	 return 'false;
      if domainp if1 then
      	 if1 := 1;
      if g = 1 and not(v memq dcfsf_varlat1 kernels if1) then	 
      	 return rl_mkn('and,{dcfsf_0mk2('neq,if1),dcfsf_qesc2(f1,v,theo)});
      if dcfsf_ordf(g,v) < dcfsf_ordf(f1,v) then
      	 return dcfsf_qesc3(f1,g,if1,v,theo);
      return dcfsf_qesc4(f1,g,if1,v,theo);
   end;

procedure dcfsf_qesc2(f,v,theo);
   begin scalar w,ftl,f1;      
      w := dcfsf_cl1(f,v);
      f1 := cdr w;
      ftl := car w;
      return rl_smkn('or,dcfsf_0mk2('equal,f1) .
	 for each gt in ftl collect dcfsf_0mk2('neq,gt))
   end;

procedure dcfsf_qesc3(f,g,iff,v,theo);
   begin scalar iff,w1,w2;
      w1 := for each gt in dcfsf_cl(g,v) collect
	 dcfsf_0mk2('neq,gt);
      w2 := for each ct in dcfsf_cl(lc f,v) collect
	 dcfsf_0mk2('neq,ct);            
      return rl_mkn('and,{rl_smkn('or,w1),rl_smkn('or,w2)})
   end;

procedure dcfsf_qesc4(f,g,iff,v,theo);
   begin scalar qr,dd,dp,w1,w2,r,s;
      dd := dcfsf_degf(f,v);
      dp := dcfsf_degf(g,v);
      s := dcfsf_ordf(f,v);
      qr := qremf(multf(exptf(lc f,dd*dp),exptf(g,dd)),f);
      r := cdr qr;
      w1 := for each ct in dcfsf_cl(lc f,v) collect
	 dcfsf_0mk2('neq,ct);
      w2 := for each rt in dcfsf_cl(r,v) collect
	 dcfsf_0mk2('neq,rt);            
      return rl_mkn('and,{rl_smkn('or,w1),rl_smkn('or,w2)})
   end;
      
endmodule;  % [dcfsfqe]

end;  % of file
