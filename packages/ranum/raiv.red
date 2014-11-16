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

asserted procedure riv_mk(l: SQ, u: SQ): IV;
   % [l] and [u] are numbers.
   {'iv, l, u};

asserted procedure riv_l(i: IV): SQ;
   % Lower bound.
   cadr i;

asserted procedure riv_u(i: IV): SQ;
   % Upper bound.
   caddr i;

asserted procedure riv_plus(i1: IV, i2: IV): IV;
   % ]l1, u1[ + ]l2, u2[ = ]l1 + l2, u1 + u2[
   riv_mk(addsq(riv_l i1, riv_l i2), addsq(riv_u i1, riv_u i2));

asserted procedure riv_minus(i: IV): IV;
   % - ]l, u[ = ]-u, -l[
   riv_mk(negsq riv_u i, negsq riv_l i);

asserted procedure riv_contains(i: IV, q: SQ): Boolean;
   sfto_lessq(riv_l i, q) and sfto_lessq(q, riv_u i);

put('iv, 'prifn, 'riv_print);

asserted procedure riv_print0(i: IV);
   begin scalar w1, w2;
      prin2!* "]";
      if !*rarat then <<
	 maprin prepsq riv_l i;
      	 prin2!* ", ";
	 maprin prepsq riv_u i
      >> else <<
	 w1 := sfto_truncq(riv_l i, precision 0);
	 w2 := sfto_truncq(riv_u i, precision 0);
	 on1 'rounded;
	 maprin reval prepsq w1;
      	 prin2!* ", ";
	 maprin reval prepsq w2;
	 off1 'rounded
      >>;
      prin2!* "["
   end;

ra_wrap(riv_print0, riv_print, 1);

asserted procedure riv_rat2float(q: SQ, prec: Integer): Floating;
   begin scalar w, sh;
      sh := 10 ^ prec;
      w := (float(numr q or 0) / float denr q);
      return float fix(w * sh) / sh
   end;

endmodule;

end;
