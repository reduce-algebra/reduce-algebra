module assume;

% Author: Rainer Schöpf 

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


symbolic procedure assume!-fact u;
  for each x in u do assume1 x;

put ('assume, 'psopfn, 'assume!-fact);


symbolic procedure assume1 u;
  if atom u then nil
   else if flagp (car u, 'boolean)
    then assume2 u;

symbolic procedure assume2 u;
  if car u memq '(greaterp geq)
    then if numberp cadr u and cadr u >= 0
           then reval {'sign_assert, caddr u, -1}
          else if numberp caddr u and caddr u >= 0
           then reval {'sign_assert, cadr u, +1}
          else nil
   else if car u memq '(lessp leq)
    then if numberp cadr u and cadr u >= 0
           then reval {'sign_assert, caddr u, +1}
          else if numberp caddr u and caddr u >= 0
           then reval {'sign_assert, cadr u, -1}
          else nil
   else if car u eq 'equal
    then !*oc!-relations!* := u . !*oc!-relations!*
   else nil;


endmodule;

end;
