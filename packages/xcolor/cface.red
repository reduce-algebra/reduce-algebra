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

% $Id$

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

%symbolic procedure simpqg u$ simpcv(u,'qg)$
%symbolic procedure simpg3 u$ simpcv(u,'g3)$

put('qg,'simpfn,'simpcv)$
put('g3,'simpfn,'simpcv)$
flag('(qg g3),'full);

symbolic procedure simpcv u$
  %--------------------------------------------------------------------
  % u is a kernel.
  % Add to mul!* simpCGraph function.
  % return u (s.q.)
  %--------------------------------------------------------------------
  if length u neq 4 then
    cerror {"Invalid number of edges in vertex",u}
  else << if not ('simpcgraph memq mul!*) then
            mul!* := aconc!*(mul!*,'simpcgraph)$
          !*k2q u
       >>$

symbolic procedure simpcgraph u$
  %--------------------------------------------------------------------
  % u is a s.q..
  % Simplifies u and returns one (s.q.).
  %--------------------------------------------------------------------
  if null numr u or domainp numr u then u
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
  %   1) v is a list of QG and G3 operators$
  %   2) w is other (s.f.).
  % Return <color factor of v>*w  (s.q.).
  %--------------------------------------------------------------------
  if domainp u then
    (if null v then coef else multsq(color0 v,coef)) where coef:=!*f2q multf(u,w)
  else if not null red u then
       addsq(simpcgraph1(!*t2f lt u,v,w),simpcgraph1(red u,v,w)) 
  else if sfp mvar u then %cerror{"SFP",prepf mvar u}
       simpcgraph1((!*q2f simp prepf u where !*factor=nil,!*exp=t),v,w)
  else if eqcar(mvar u,'qg) then
         if ldeg u = 1 then simpcgraph1(lc u,mvar u . v,w)
         else cerror {"Vertex",mvar u,"cannot be multiplied by itself."}
  else if eqcar(mvar u,'g3) then
         if ldeg u = 1 then simpcgraph1(lc u,mvar u . v,w)
         else if ldeg u = 2 then simpcgraph1(lc u,mvar u . mvar u . v,w)
         else cerror {"Vertex",mvar u,"cannot be multiplied by itself more then twice."}
  else simpcgraph1(lc u,v,multf(!*p2f lpow u,w))$

%----------------------------------------------------------------------
endmodule;

end;
