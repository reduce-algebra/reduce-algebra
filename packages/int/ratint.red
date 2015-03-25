module ratint;   % Support for direct rational integration.

% Authors: Mary Ann Moore and Arthur C. Norman.

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


SYMBOLic procedure rationalintegrate(x,var);
    begin     scalar n,d;
      n:=numr x; d:=denr x;
      if not(var member varsinsf(d,nil)) then
            return !*multsq(polynomialintegrate(n,var),1 ./ d);
      rederr "Rational integration not coded yet"
    end;

symbolic procedure polynomialintegrate(x,v);
% Integrate standard form. result is standard quotient.
    if null x then nil ./ 1
    else if atom x then ((mksp(v,1) .* 1) .+ nil) ./ 1
    else begin    scalar r;
      r:=polynomialintegrate(red x,v); % deal with reductum
      if v=mvar x then begin    scalar degree,newlt;
         degree:=1+tdeg lt x;
         newlt:=((mksp(v,degree) .* lc x) .+ nil) ./ 1; % up exponent
         r:=addsq(!*multsq(newlt,1 ./ degree),r)
         end
      else begin        scalar newterm;
        newterm:=(((lpow x) .* 1) .+ nil) ./ 1;
        newterm:=!*multsq(newterm,polynomialintegrate(lc x,v));
        r:=addsq(r,newterm)
        end;
      return r
    end;

endmodule;

end;

