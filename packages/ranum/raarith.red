% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% Copyright (c) 2014 T. Sturm
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

module raarith;

asserted procedure ra_refine!$(u: list): ra;
   begin
      scalar x;
      integer n;
      x := numr simp car u;
      n := if cdr u then reval cadr u else 1;
      return mk!*sq !*f2q ra_refine(x, n)
   end;

put('refine, 'psopfn, 'ra_refine!$);

asserted procedure ra_refine0(x: ra, n: integer): ra;
   % Refine [x] [n] times.
   begin scalar f, iv, l, u;
      f := ra_f x;
      iv := ra_iv x;
      l . u := ra_refine1(f, riv_l iv, riv_u iv, n);
      return ra_qmk(f, l, u)
   end;

ra_wrap(ra_refine0, ra_refine, 2);

asserted procedure ra_refine1(f: sf, l: sq, u: sq, n: integer): dottedpair;
   begin scalar c;
      for j := 1:n do <<
	 c := sfto_avgq(l,u);
	 if null numr sfto_qsub1(f, {ra_x() . c}) then
	    l := sfto_avgq(l, c)
	 else if eqn(ra_budancount(f, l, c), 1) then
	    u := c
	 else <<
	    assert eqn(ra_budancount(f, c, u), 1);
	    l := c
	 >>
      >>;
      return l . u
   end;

asserted procedure ra_normalize0(x: ra): ra;
   % Normaize [x]. That is, return [nil] if [x] represents 0, else refine [x]
   % such that its interval does not contain zero.
   begin scalar f, l, u;
      if null x then
	 return x;
      f := ra_f x;
      l := ra_l x;
      u := ra_u x;
      assert(not null numr sfto_qsub1f, {ra_x() . l});
      assert(not null numr sfto_qsub1(f, {ra_x() . u}));
      if null numr u or minusf numr u or null numr l or minusf negf numr l then
	 return x;
      % We now know l < 0 < u.
      if null sfto_abssummand f then
	 return ra_zero();
      % We now know x <> 0.
      if eqn(ra_budancount(f, l, nil ./ 1), 1) then
	 return ra_qmk(f, l, nil ./ 1);
      assert(eqn(ra_budancount(f, nil ./ 1, u), 1));
      return ra_qmk(f, nil ./ 1, u)
   end;

ra_wrap(ra_normalize0, ra_normalize, 1);

asserted procedure ra_diff(f: sf): sf;
   numr difff(f, ra_x());

asserted procedure ra_plus0(x: ra, y: ra): ra;
   begin scalar ff, gg, h, lx, ux, ly, uy, l, u;
      if null x then
 	 return y;
      if null y then
	 return x;
      ff := ra_plustransform ra_f x;
      gg := sfto_renamef(ra_f y, ra_x(), ra_y());
      h := ra_resf0(ff, gg, ra_y());
      lx := riv_l ra_iv x;
      ux := riv_u ra_iv x;
      ly := riv_l ra_iv y;
      uy := riv_u ra_iv y;
      l := addsq(lx, ly);
      u := addsq(ux, uy);
      while not eqn(ra_budancount(h, l, u), 1) do <<
	 lx . ux := ra_refine1(ra_f x, lx, ux, 1);
	 ly . uy := ra_refine1(ra_f y, ly, uy, 1);
      	 l := addsq(lx, ly);
      	 u := addsq(ux, uy)
      >>;
      return ra_simpl0 ra_normalize0 ra_qmk(h, l, u)
   end;

ra_wrap(ra_plus0, ra_plus, 2);

asserted procedure ra_plustransform(f: sf): sf;
   % Transform f(x) into f(x-y). TODO
   sfto_fsub1(f, {ra_x() . addf(!*k2f ra_x(), negf !*k2f ra_y())});

asserted procedure ra_difference1(x: ra, y: ra): ra;
   ra_plus0(x, ra_minus0 y);

ra_wrap(ra_difference0, ra_difference, 2);

asserted procedure ra_minus0(x: ra): ra;
   if ra_zerop x then
      x
   else
      ra_simpl0 ra_mk(ra_mirror ra_f x, riv_minus ra_iv x);

ra_wrap(ra_minus0, ra_minus, 1);

asserted procedure ra_minusp0(x: ra): boolean;
   % [x] must ne normalized.
   begin scalar l;
      if null x then
 	 return nil;
      l := ra_l x;
      return sfto_lessq(l, nil ./ nil)
   end;

ra_wrap(ra_minusp0, ra_minusp, 1);

asserted procedure ra_times0(x: ra, y: ra): ra;
   begin scalar ff, gg, h, lx, ux, ly, uy, ll, l, u;
      if null x or null y then
	 return nil;
      ff := ra_timestransform ra_f x;
      gg := sfto_renamef(ra_f y, ra_x(), ra_y());
      h := ra_resf0(ff, gg, ra_y());
      lx := riv_l ra_iv x;
      ux := riv_u ra_iv x;
      ly := riv_l ra_iv y;
      uy := riv_u ra_iv y;
      ll := {multsq(lx, ly), multsq(lx, uy), multsq(ux, ly), multsq(ux, uy)};
      l := sfto_minql ll;
      u := sfto_maxql ll;
      while not eqn(ra_budancount(h, l, u), 1) do <<
	 lx . ux := ra_refine1(ra_f x, lx, ux, 1);
	 ly . uy := ra_refine1(ra_f y, ly, uy, 1);
      	 ll := {multsq(lx, ly), multsq(lx, uy), multsq(ux, ly), multsq(ux, uy)};
      	 l := sfto_minql ll;
      	 u := sfto_maxql ll
      >>;
      return ra_simpl0 ra_normalize0 ra_qmk(h, l, u)
   end;

ra_wrap(ra_times0, ra_times, 2);

asserted procedure ra_timestransform(f: sf): sf;
   % Transform f(x) into y^d * f(x/y). TODO
   numr sfto_qsub1(
      multf(f, ra_y() .** ldeg f .* 1 .+ nil),
      {ra_x() . (!*k2f ra_x() ./ !*k2f ra_y())});

asserted procedure ra_quotient0(x: ra, y: ra): ra;
   ra_times0(x, ra_inverse0 y);

ra_wrap(ra_quotient0, ra_quotient, 2);

asserted procedure ra_inverse0(x: ra): ra;
   begin scalar f, l, u, newl, newu;
      f := ra_f x;
      l := riv_l ra_iv x;
      u := riv_u ra_iv x;
      newl := if numr u then denr u ./ numr u else negsq sfto_lmq ra_mirror f;
      newu := if numr l then denr l ./ numr l else sfto_lmq f;
      return ra_simpl0 ra_qmk(ra_invtransform f, newl, newu)
   end;

ra_wrap(ra_inverse0, ra_inverse, 1);

asserted procedure ra_invtransform(f: sf): sf;
   % Transform f(x) into x^d * f(1/x). TODO
   numr sfto_qsub1(
      multf(f, ra_x() .** ldeg f .* 1 .+ nil),
      {ra_x() . (1 ./ !*k2f ra_x())});

asserted procedure ra_resf0(f: sf, g: sf, x: kernel): sf;
   sfto_dprpartf sfto_sqfpartf sfto_resf(f, g, x);

asserted procedure ra_simpl0(x: ra): ra;
   begin scalar w;
      if not !*rasimpl then
	 return x;
      x := ra_sifac0 x;
      w := ra_intequiv x;
      if fixp w then
	 return ra_i2ra w;
      return x
   end;

ra_wrap(ra_simpl0, ra_simpl, 1);

asserted procedure ra_sifac0(x: ra): ra;
   begin scalar facl, f, l, u, c;
      if not !*rasifac then
	 return x;
      l := riv_l ra_iv x;
      u := riv_u ra_iv x;
      facl := for each pr in cdr fctrf ra_f x collect car pr;
      c := t; while c and facl do <<
	 f := pop facl;
	 if eqn(ra_budancount(f, l, u), 1) then
	    c := nil
      >>;
      assert(not c);
      return ra_qmk(f, l, u)
   end;

ra_wrap(ra_sifac0, ra_sifac, 1);

endmodule;

end;
