module brsltnt_bmap.red;


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

% $Id: $
% Author: Eberhard Schruefer                          Copyright (c) 2019

% Resultant via Bezout's matrix construction. The calulation of the determinant
% is done via exterior multiplaction. The datastructure used are distributed 
% polynmials where the 'lpow' part is an integer in which a bit is set for each
% exterior base element. With this the following operations can be done very
% efficiently:
% i) Multiplication of exterior base elements is simply logor
% ii) Checking if two products have common elements amounts to logand
% iii) Calculating the sign for multiplying a 1-form base to an arbitray base 
% form is accomplished by logcount.

fluid '(!*bezout_try_fac !*bezout_try_gcd);

inline procedure bb!:ordexp(u, v); u > v;

symbolic procedure bb!:bezout_resultant(u, v, w);
   % U and v are standard forms. Result is resultant of u and v
   % w.r.t. kernel w. Method is Bezout's determinant using exterior
   % multiplication for its calculation.
   begin integer n, nm; scalar ep, cuh, cvh, cx, cxf, uh, ut, vh, vt, x;
     if domainp u or null(mvar u eq w)
        then return if not domainp v and mvar v eq w
                       then exptf(u, ldeg v)
                     else 1
      else if domainp v or null(mvar v eq w)
        then return if mvar u eq w then exptf(v, ldeg u) else 1;
     n := ldeg v - ldeg u;
     if n < 0 then return multd((-1)**(ldeg u*ldeg v),
                                bb!:bezout_resultant(v, u, w));
     nm := ldeg v;
     uh := lc u;
     vh := lc v;
     ut := if n neq 0 then multpf(w to n, red u) else red u;
     vt := red v;
     cuh := uh;
     cvh := vh;
     cxf := '(1);
     if !*bezout_try_gcd and ((cx := gcdf!*(uh, vh)) neq 1) 
        then <<cxf := bb!:fac!-merge(cx, cxf);
               uh := quotf1(uh, cx);
               vh := quotf1(vh, cx)>>;
     ep := !*sf2exbb(addf(multf(uh, vt), negf multf(vh, ut)), w);
     if cdr cxf then bb!:try_previous_factors(ep, cdr cxf);

     for j := (nm - 1) step -1 until (n + 1) do
        <<if degr(ut, w) = j then
             <<uh := addf(lc ut, multf(!*k2f w, uh));
               if !*bezout_try_gcd and null(cuh = 1 or cvh = 1) 
                  then cuh := gcdf!*(lc ut, cuh);
               ut := red ut>>
           else uh := multf(!*k2f w, uh);
          if degr(vt, w) = j then
             <<vh := addf(lc vt, multf(!*k2f w, vh));
               if !*bezout_try_gcd and null(cuh = 1 or cvh = 1) 
                  then cvh := gcdf!*(lc vt, cvh);
               vt := red vt>>
           else vh := multf(!*k2f w, vh);

          if !*bezout_try_gcd and ((cx := gcdf!*(cuh, cvh)) neq 1)
             then <<cxf := bb!:fac!-merge(cx, cxf);
                    uh := quotf1(uh, cx);
                    vh := quotf1(vh, cx)>>;
          x := !*sf2exbb(addf(multf(uh, vt), negf multf(vh, ut)), w);
          if cdr cxf then bb!:try_previous_factors(x, cdr cxf);
          cxf := bb!:normalize(x, cxf);
          ep := bb!:extmult(x, ep);
          if cdr cxf then bb!:try_previous_factors(ep, cdr cxf);
          if j neq 1 then cxf := bb!:normalize(ep, cxf)>>;

      if n neq 0
         then <<x := !*sf2exbb(u, w);
                cxf := bb!:normalize(x, cxf);
                ep := bb!:extmult(x, ep);
                cxf := bb!:normalize(ep, cxf);
                for j := 1:(n - 1) do
                  <<x := !*sf2exbb(multpf(w to j, u), w);
                    cxf := bb!:normalize(x, cxf);
                    ep := bb!:extmult(x, ep);
                    cxf := bb!:normalize(ep, cxf)
                    >> >>; 
      if ep then <<x := multf(lc ep, car cxf);
                   for each j in cdr cxf do 
                       x := multf(x, exptf(car j, cdr j))>>;
      return if null ep then nil else x
   end;

symbolic procedure !*sf2exbb(u, v);
   %distributes s.f. u with respect to powers in v.
   if null u then nil
    else if degr(u, v) = 0 then 1 .* u .+ nil
    else lshift(1, ldeg u) .* lc u .+ !*sf2exbb(red u, v);

symbolic procedure bb!:extmult_ (u, v);
   % u is a 1-form, v an arbitrary form.
   begin scalar eptr, r, res, v0, x, y, z;
     r := nil . nil;
     res := nil . nil;
     a0: rplacd(r, nil);
         eptr := r;
         v0 := v;
         x := lpow u;
     a: y := lpow v0;
        if land(x, y) = 0 
           then <<z := if evenp logcount land(y, sub1 x) 
                          then lc u else negf lc u;
                  z := multf(z, lc v0);
                  eptr := cdr rplacd(eptr, lor(x, y) .* z .+ nil)>>;
        if v0 := red v0 then go to a;
        bb!:extaddip(res, cdr r); 
        if u := red u then go to a0;
      return cdr res
    end;

symbolic procedure bb!:extaddip(u, v);
   % Accumulates in u destructively.
   begin scalar x, ru;
     a:  ru := red u;
         if null v then return
         else if null ru
           then return rplacd(u, v)
         else if lpow ru = lpow v 
           then <<if x := addf(lc ru, lc v)
                     then <<rplacd(lt ru, x); u := ru>>
                   else rplacd(u, red ru);
                  v := red v>>
         else if bb!:ordexp(lpow v, lpow ru)
           then <<rplaca(rplacd(ru, lt ru . red ru), lt v);
                  v := red v;
                  u := ru>>
         else u := ru;
        go to a
   end;

symbolic procedure bb!:extmult(u, v);
   % u is a 1-form, v an arbitrary form.
   % rf is a finger to the position where we have to start to accumulate.
   begin scalar lc1, res, rf, rrp, rp, x, y, z;
     res := rp := nil . nil;
     x := lpow u;
     lc1 := lc u;

     for each q on v do
       if land(x, y := lpow q) = 0
          then rp := cdr rplacd(rp, lor(x, y) .* 
                                    multf(if evenp logcount land(y, sub1 x) 
                                             then lc1 else negf lc1, lc q)
                                    .+ nil);

     rf := if land(x, lpow v) = 0 then cdr res else res;

     for each p on red u do
        <<x := lpow p;
          lc1 := lc p;
          rp := rf;
          if land(x, y := lpow v) = 0 then
             begin
               z := multf(if evenp logcount land(y, sub1 x) 
                             then lc1 else negf lc1, lc v);
               a: rrp := red rp;
                  if null rrp 
                     then rp := red rplacd(rp, lor(x, y) .* z .+ nil)
                   else if lor(x, y) = lpow rrp
                     then if z := addf(lc rrp, z)
                             then <<rplacd(lt rrp, z); rp := rrp>>
                           else rplacd(rp, red rrp)
                   else if bb!:ordexp(lor(x, y), lpow rrp)
                     then rp := rplaca(rplacd(rrp, lt rrp . red rrp),
                                       lor(x, y) .* z)
                   else <<rp := rrp; go to a>>;
             end;

          rf := rp;

          for each q on red v do
             if land(x, y := lpow q) = 0 then
                begin
                  z := multf(if evenp logcount land(y, sub1 x) 
                                then lc1 else negf lc1, lc q);
                  a: rrp := red rp;
                     if null rrp 
                        then rp := red rplacd(rp, lor(x, y) .* z .+ nil)
                      else if lor(x, y) = lpow rrp
                        then if z := addf(lc rrp, z)
                                then <<rplacd(lt rrp, z); rp := rrp>>
                              else rplacd(rp, red rrp)
                      else if bb!:ordexp(lor(x, y), lpow rrp)
                        then rp := rplaca(rplacd(rrp, lt rrp . red rrp),
                                          lor(x, y) .* z)
                      else <<rp := rrp; go to a>>;
                end>>;
     return cdr res
    end;
 
symbolic procedure bb!:comfac u;
   begin scalar !*ezgcd,x;
     !*ezgcd := t;
     if null u then return 1;
     x := gcdf!*(lc u, nil);
     a: u := red u;
        if null u then return x;
        x := gcdf!*(lc u, x);
        go to a
   end;

symbolic procedure bb!:cquot(u,v);
   for each x on u do rplacd(lt x, quotf1(lc x, v));

symbolic procedure bb!:ctrialdiv(u,v); 
   begin
     while u and quotf1(lc u, v) do u := red u;
     return null u
   end;

symbolic procedure bb!:try_previous_factors(u, v);
   begin scalar b;
     a: if b := bb!:ctrialdiv(u, caar v) 
           then for each x on u do rplacd(lt x, quotf1(lc x, caar v));
        if null b then if v := cdr v then go to a else return;
        rplacd(car v, cdar v + 1);
        go to a;
   end;

symbolic procedure bb!:fac!-merge(u, v);
   begin scalar x;
     x := if !*bezout_try_fac then fctrf u else {1, u . 1};
     return if null cdr v then multf(car x, car v) . cdr x
             else multf(car x, car v) . bb!:fac!-merge2(cdr x, cdr v)
   end;

symbolic procedure bb!:fac!-merge2(u, v);
   begin scalar x,y,r;
     if null u then return v;
     c: x := car u;
        y := v;
     b: if car x = caar y 
           then <<rplacd(car y, cdar y + cdr x);
                  go to a>>;
        y := cdr y;
        if y then go to b;
        r := x . r;
     a: u := cdr u;
        if null u then return append(v, r);
        go to c;
   end;

symbolic procedure bb!:normalize(u, v);
   begin scalar cx;
     if null !*bezout_try_gcd or ((cx := bb!:comfac u) = 1) 
        then return v;
     v := bb!:fac!-merge(cx, v);
     bb!:cquot(u, cx);
     return v
   end;

endmodule;

end;



