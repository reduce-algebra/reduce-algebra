module tayfront;

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


%*****************************************************************
%
%          User interface
%
%*****************************************************************


exports taylorcombine, taylororiginal, taylorprintorder,
        taylorseriesp, taylortemplate, taylortostandard;

imports

% from the REDUCE kernel:
        eqcar, mk!*sq, mvar, numr, prepsq, simp!*, typerr,

% from the header module:
        taylor!-kernel!-sq!-p, tayorig, taytemplate, taytpelorder,
        taytpelpoint, taytpelvars,

% from module Tayintro:
        taylor!-error,

% from module Taysimp:
        taysimpsq;


symbolic procedure taylorseriesp u;
  (taylor!-kernel!-sq!-p sq)
      where sq := simp!* u;

symbolic procedure taylorcombine u;
  mk!*sq taysimpsq simp!* u;

symbolic procedure taylortostandard u;
  (prepsq if not eqcar (u, '!*sq) then simp!* u else cadr u)
          where convert!-taylor!* := t;

symbolic procedure taylororiginal u;
  (if not taylor!-kernel!-sq!-p sq
     then typerr (u, "Taylor kernel")
    else (if tayorig tay then mk!*sq tayorig tay
        else taylor!-error ('no!-original, 'taylororiginal))
           where tay := mvar numr sq)
     where sq := simp!* u;

symbolic procedure taylortemplate u;
  (if not taylor!-kernel!-sq!-p sq
     then typerr (u, "Taylor kernel")
    else 'list . for each quartet in taytemplate mvar numr sq collect
              {'list,
               if null cdr taytpelvars quartet
                 then car taytpelvars quartet
                else 'list . taytpelvars quartet,
               taytpelpoint quartet,
               taytpelorder quartet})
     where sq := simp!* u;

flag ('(taylorseriesp taylorcombine taylortostandard taylororiginal
        taylortemplate),
      'opfn);

flag ('(taylorseriesp), 'boolean);

endmodule;

end;
