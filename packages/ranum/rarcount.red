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

module raiv;

asserted procedure ra_isolate0(f: SF): List;
   begin scalar lb, ub, ivl;
      f := sfto_dprpartf sfto_sqfpartf f;
      ub := sfto_lmq f;
      lb := negsq sfto_lmq ra_mirror f;
      ivl := ra_vca(f, lb , ub);
      return for each iv in ivl collect ra_qmk(f, car iv, cdr iv)
   end;

ra_wrap(ra_isolate0, ra_isolate, 1);

procedure ra_isolate!$(argl);
   'list . for each x in ra_isolate(numr simp car argl) collect
      mk!*sq !*f2q int!-equiv!-chk x;

put('isolate, 'psopfn, 'ra_isolate!$);

asserted procedure ra_mirror(f: SF): SF;
   <<
      f := sfto_fsub1(f, {ra_x() . negf !*k2f ra_x()});
      if minusf f then negf f else f
   >>;

asserted procedure ra_help(ivl: List): List;
   for each pr in ivl collect
      {float(caar pr or 0) / float(cdar pr), float(cadr pr or 0)/float(cddr pr)};

asserted procedure ra_vca(f: SF, l: SQ, u: SQ): List;
   ra_vca1(ra_transform(f, l, u), l, u);

asserted procedure ra_transform(f: SF, l: SQ, u: SQ): SQ;
   % Transform [f] such that the interval (l, u) is mapped to (0, 1).
   numr sfto_qsub1(f, {ra_x() . addsq(multsq(subtrsq(u, l), !*k2q ra_x()), l)});

asserted procedure ra_vca1(f: SF, a: SQ, b: SQ): List;
   begin
      scalar ff, fff, c, resl;
      integer sv;
      sv := ra_budan!-0!-1 f;
      if eqn(sv, 0) then
	 return nil;
      if eqn(sv, 1) then
	 return {a . b};
      c := quotsq(addsq(a, b), !*f2q 2);
      ff . fff := ra_vcatransform1 f;
      resl := ra_vca1(ff, a, c);
      if null numr sfto_qsub1(f, {ra_x() . (1 ./ 2)}) then
	 resl := append(resl, {c . c});
      resl := append(resl, ra_vca1(fff, c, b));
      return resl
   end;

asserted procedure ra_vcatransform1(f: SF): DottedPair;
   % Compute [ff . fff], where [ff = 2^n * f(x/2)] and [fff = 2^n * f((x+1)/2) =
   % ff(x+1)]. For [fff] a Horner scheme is used.
   begin
      scalar xp1, ff, fff;
      integer c, d, cc;
      assert(not domainp f);
      xp1 := addf(!*k2f ra_x(), 1);
      c := 1;
      d := ldeg f;
      ff := ra_x() .** d .* lc f .+ nil;
      fff := lc f;
      f := red f;
      while not domainp f do <<
	 c := c * 2 ^ (d - ldeg f);
	 cc := c * lc f;
	 ff := addf(ff, ra_x() .** ldeg f .* cc .+ nil);
	 fff := addf(multf(fff, exptf(xp1, d - ldeg f)), cc);
      	 d := ldeg f;
	 f := red f
      >>;
      c := c * 2 ^ d;
      cc := c * f;
      ff := addf(ff, cc);
      fff := addf(multf(fff, exptf(xp1, d)), cc);
      return ff . fff
   end;

asserted procedure ra_budan!-0!-1(f: SF): Integer;
   begin
      scalar ff, c;
      integer sign, cursign, signchanges;
      ff := ra_budan!-transform f;
      while ff do <<
	 if domainp ff then <<
	    c := ff;
	    ff := nil
	 >> else <<
	    c := lc ff;
	    ff := red ff
	 >>;
	 sign := if minusf c then -1 else 1;
	 if sign * cursign < 0 then
	    signchanges := signchanges + 1;
	 cursign := sign;
      >>;
      return signchanges
   end;

asserted procedure ra_budan!-transform(f: SF): SF;
   % Compute (x+1)^d * f(1/(x+1)) using a Horner scheme.
   begin scalar xp1, ff, rd;
      xp1 := addf(!*k2f ra_x(), 1);
      if domainp f then
	 return f;
      ff := ra_budan!-transform red f;
      rd := if domainp red f then 0 else ldeg red f;
      return addf(lc f, multf(exptf(xp1, ldeg f - rd), ff))
   end;

asserted procedure ra_budancount(f: SF, l: SQ, u: SQ): Integer;
   ra_budan!-0!-1(ra_transform(f, l, u));

asserted procedure ra_budan!-0!-1_old(f: SF): Integer;
   % Naively compute (x+1)^d * f(1/(x+1)). This is an old and slow version,
   % which demonstrates PSL problems with unefficient arithmetic.
   begin
      scalar xp1, ff, c;
      integer sign, cursign, signchanges;
      xp1 := addf(!*k2f ra_x(), 1);
      ff := sfto_qsub1(f, {ra_x() . (1 ./ xp1)});
      ff := multsq(!*f2q exptf(xp1, ldeg f), ff);
      ff := numr ff;
      while ff do <<
	 if domainp ff then <<
	    c := ff;
	    ff := nil
	 >> else <<
	    c := lc ff;
	    ff := red ff
	 >>;
	 sign := if minusf c then -1 else 1;
	 if sign * cursign < 0 then
	    signchanges := signchanges + 1;
	 cursign := sign;
      >>;
      return signchanges
   end;

endmodule;

end;
