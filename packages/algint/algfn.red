module algfn;

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


% Check if an expression is in a pure algebraic extension of
% Q(all "constants")(var).


exports algfnpl,algebraicsf;

imports simp,interr,dependsp,dependspl;

symbolic procedure algfnp(pf,var);
   if atom pf then t
    else if not atom car pf then interr "Not prefix form"
    else if car pf eq '!*sq then algfnsq(cadr pf,var)
      else if car pf eq 'expt
       then if not algint!-ratnump caddr pf
              then (not dependsp(cadr pf,var))
                and (not dependsp(caddr pf,var))
             else algfnp(cadr pf,var)
    else if not memq(car pf,'(minus plus times quotient sqrt))
           % JPff fiddle
     then not dependspl(cdr pf,var)
    else algfnpl(cdr pf,var);

symbolic procedure algfnpl(p!-list,var);
   null p!-list or algfnp(car p!-list,var) and algfnpl(cdr p!-list,var);

symbolic procedure algfnsq(sq,var);
   algfnsf(numr sq,var) and algfnsf(denr sq,var);

symbolic procedure algfnsf(sf,var);
   atom sf
 or algfnp(mvar sf,var) and algfnsf(lc sf,var) and algfnsf(red sf,var);

symbolic procedure algint!-ratnump q;
   if atom q then numberp q
    else car q eq 'quotient and (numberp cadr q) and (numberp caddr q);

symbolic procedure algebraicsf u;
   if atom u then nil
    else algebraicp mvar u or algebraicsf lc u or algebraicsf red u;

symbolic procedure algebraicp u;
   if atom u then nil
    else if car u eq 'expt then 1 neq denr simp caddr u
    else car u eq 'sqrt;

endmodule;

end;

