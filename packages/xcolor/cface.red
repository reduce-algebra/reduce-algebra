module cface;
  imports color0$
  exports simpqg,simpg3,simpcgparh$
%----------------------------------------------------------------------
% Purpose:   Interface between REDUCE and xColor module.
% Author:    A.Kryukov
% E-address: kryukov@npi.msu.su
% Vertion:   1.5.1
% Release:   Dec. 17, 1993
%----------------------------------------------------------------------
% Revision: 13/03/91  SUdim
%           15/03/91  simpCGraph
%           15/03/91  simCGraph1
%----------------------------------------------------------------------

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


%------------------------ Global/Fluid --------------------------------

global '(SU_order Spur_TT n!*!*2!-1)$

SU_order := '(3 . 1)$        % default value
Spur_TT  := '(1 . 2)$        % default value
n!*!*2!-1:= '(8 . 1)$        % default value

%----------------------------------------------------------------------

symbolic procedure sudim u$
  %--------------------------------------------------------------------
  % Set order of SU group.
  %--------------------------------------------------------------------
  << SU_order := simp car u$
     n!*!*2!-1 := addsq(multsq(SU_order,SU_order),('-1 ./ 1))$
  >>$

symbolic procedure sptt u$
  %--------------------------------------------------------------------
  % Set value of A: Sp(TiTj) = A*Delta(i,j).
  %--------------------------------------------------------------------
  << Spur_TT := simp car u$ >>$

rlistat '(sudim sptt)$

%--------------- Set simpFunction for QG and G3 operators -------------

symbolic procedure simpqg u$ simpcv(u,'qg)$
symbolic procedure simpg3 u$ simpcv(u,'g3)$

put('qg,'simpfn,'simpqg)$
put('g3,'simpfn,'simpg3)$

symbolic procedure simpcv(u,x)$
  %--------------------------------------------------------------------
  % u is a kernel.
  % Add to mul!* simpCGraph function.
  % return u (s.q.)
  %--------------------------------------------------------------------
  if length u neq 3 then
    cerror list("Invalid number of edges in vertex",u)
  else << if not ('simpcgraph memq mul!*) then
            mul!* := aconc!*(mul!*,'simpcgraph)$
          !*k2q(x . u)
       >>$

symbolic procedure simpcgraph u$
  %--------------------------------------------------------------------
  % u is a s.q..
  % Simplified u and return one (s.q.).
  %--------------------------------------------------------------------
  if null numr u or numberp numr u or red numr u then u
  else begin
         SU_order := simp list('!*sq,SU_order,nil)$
         n!*!*2!-1 := addsq(multsq(SU_order,SU_order),('-1 ./ 1))$
         Spur_TT := simp list('!*sq,Spur_TT,nil)$
         return quotsq(simpcgraph1(numr u,nil,1),!*f2q denr u)$
       end$ % simpCGraph

symbolic procedure simpcgraph1(u,v,w)$
  %--------------------------------------------------------------------
  % u is a s.f..
  % Seperate u on two part:
  %   1) v is a list of QG and G3 oerators$
  %   2) w is other (s.f.).
  % Return <color factorof v>*w  (s.q.).
  %--------------------------------------------------------------------
  if numberp u or red u then
    if v then multsq(color0 v,multf(u,w) ./ 1) else multf(u,w) ./ 1
  else if null atom mvar u and car mvar u eq 'qg then
         if ldeg u = 1 then simpcgraph1(lc u,mvar u . v,w)
         else cerror list("Vertex",list('!*sq,u ./ 1,t)
                         ,"can not be multiply by itself."
                         )
  else if null atom mvar u and car mvar u eq 'g3 then
         if ldeg u = 1 then simpcgraph1(lc u,mvar u . v,w)
         else if ldeg u = 2 then simpcgraph1(lc u,mvar u . mvar u . v,w)
         else cerror list("Vertex",list('!*sq,u ./ 1,t),
                      "can not be multiplied by itself more then twice."
                         )
  else simpcgraph1(lc u,v,multf(!*p2f lpow u,w))$

%----------------------------------------------------------------------
endmodule;

end;
