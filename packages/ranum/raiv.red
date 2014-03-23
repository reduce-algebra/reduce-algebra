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

asserted procedure iv_mk(l: SQ, u: SQ): IV;
   % [l] and [u] are numbers.
   {'iv, l, u};

asserted procedure iv_l(i: IV): SQ;
   % Lower bound.
   cadr i;

asserted procedure iv_u(i: IV): SQ;
   % Upper bound.
   caddr i;

asserted procedure iv_plus(i1: IV, i2: IV): IV;
   % ]l1, u1[ + ]l2, u2[ = ]l1 + l2, u1 + u2[
   iv_mk(addsq(iv_l i1, iv_l i2), addsq(iv_u i1, iv_u i2));

asserted procedure iv_minus(i: IV): IV;
   % - ]l, u[ = ]-u, -l[
   iv_mk(negsq iv_u i, negsq iv_l i);

asserted procedure iv_contains(i: IV, q: SQ): Boolean;
   sfto_lessq(iv_l i, q) and sfto_lessq(q, iv_u i);

put('iv, 'prifn, 'iv_print);

asserted procedure iv_print(i: IV);
   <<
      prin2!* "]";
      if ra_precision!* geq 0 then
      	 prin2!* iv_rat2float(iv_l i, ra_precision!*)
      else
	 maprin prepsq iv_l i;
      prin2!* ", ";
      if ra_precision!* geq 0 then
      	 prin2!* iv_rat2float(iv_u i, ra_precision!*)
      else
	 maprin prepsq iv_u i;
      prin2!* "["
   >>;

asserted procedure iv_rat2float(q: SQ, prec: Integer): Floating;
   begin scalar w, sh;
      sh := 10 ^ prec;
      w := (float(numr q or 0) / float denr q);
      return float fix(w * sh) / sh
   end;

endmodule;

end;
