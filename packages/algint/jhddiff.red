module jhddiff;

% Author: James H. Davenport.

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


% Differentiation routines for algebraic expressions;
symbolic procedure !*diffsq(u,v);
   %U is a standard quotient, V a kernel.
   %Value is the standard quotient derivative of U wrt V.
   %Algorithm: df(x/y,z)= (x'-(x/y)*y')/y;
   !*multsq(!*addsq(!*difff(numr u,v),
                    negsq !*multsq(u,!*difff(denr u,v))),
          1 ./ denr u);

symbolic procedure !*difff(u,v);
   %U is a standard form, V a kernel.
   %Value is the standard quotient derivative of U wrt V;
   if domainp u then nil ./ 1
    else !*addsq(!*addsq(multpq(lpow u,!*difff(lc u,v)),
                        !*multsq(lc u ./ 1,!*diffp(lpow u,v))),
               !*difff(red u,v));

symbolic procedure !*diffp(u,v);
%  Special treatment of SQRT's (JHD is not sure why,
%  but it seems to be necessary);
if atom (car u) then diffp(u,v)
  else if not(caar u eq 'sqrt) then diffp(u,v)
    else begin
           scalar w,dw;
           w:=simp argof car u;
           dw:= !*diffsq(w,v);
           if null numr dw then return dw;
           return !*multsq(!*multsq(dw,invsq w),
                           !*multf(cdr u,mksp(car u,1) .* 1 .+ nil)./ 2)
           end;

endmodule;

end;

