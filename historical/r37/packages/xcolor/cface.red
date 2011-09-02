module CFace;
  imports Color0$
  exports simpQG,simpG3,simpCGparh$
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

%------------------------ Global/Fluid --------------------------------

global '(SU_order Spur_TT n!*!*2!-1)$

SU_order := '(3 . 1)$        % default value
Spur_TT  := '(1 . 2)$        % default value
n!*!*2!-1:= '(8 . 1)$        % default value

%----------------------------------------------------------------------

symbolic procedure SUdim u$
  %--------------------------------------------------------------------
  % Set order of SU group.
  %--------------------------------------------------------------------
  << SU_order := simp car u$
     n!*!*2!-1 := AddSQ(MultSQ(SU_order,SU_order),('-1 ./ 1))$
  >>$

symbolic procedure SpTT u$
  %--------------------------------------------------------------------
  % Set value of A: Sp(TiTj) = A*Delta(i,j).
  %--------------------------------------------------------------------
  << Spur_TT := simp car u$ >>$

rlistat '(SUdim SpTT)$

%--------------- Set simpFunction for QG and G3 operators -------------

symbolic procedure simpQG u$ simpCV(u,'QG)$
symbolic procedure simpG3 u$ simpCV(u,'G3)$

put('QG,'simpfn,'simpQG)$
put('G3,'simpfn,'simpG3)$

symbolic procedure simpCV(u,x)$
  %--------------------------------------------------------------------
  % u is a kernel.
  % Add to mul!* simpCGraph function.
  % return u (s.q.)
  %--------------------------------------------------------------------
  if length u neq 3 then 
    CError list("Invalid number of edges in vertex",u)
  else << if not ('simpCGraph memq mul!*) then
            mul!* := aconc!*(mul!*,'simpCGraph)$
          !*k2q(x . u)
       >>$

symbolic procedure simpCGraph u$
  %--------------------------------------------------------------------
  % u is a s.q..
  % Simplified u and return one (s.q.).
  %--------------------------------------------------------------------
  if null numr u or numberp numr u or red numr u then u
  else begin
         SU_order := simp list('!*SQ,SU_order,nil)$
         n!*!*2!-1 := AddSQ(MultSQ(SU_order,SU_order),('-1 ./ 1))$
         Spur_TT := simp list('!*SQ,Spur_TT,nil)$
         return QuotSQ(simpCGraph1(numr u,nil,1),!*f2q denr u)$
       end$ % simpCGraph

symbolic procedure simpCGraph1(u,v,w)$
  %--------------------------------------------------------------------
  % u is a s.f..
  % Seperate u on two part:
  %   1) v is a list of QG and G3 oerators$
  %   2) w is other (s.f.).
  % Return <color factorof v>*w  (s.q.).
  %--------------------------------------------------------------------
  if numberp u or red u then
    if v then MultSQ(Color0 v,MultF(u,w) ./ 1) else MultF(u,w) ./ 1
  else if null atom mvar u and car mvar u eq 'QG then
         if ldeg u = 1 then simpCGraph1(lc u,mvar u . v,w)
         else CError list("Vertex",list('!*SQ,u ./ 1,t)
                         ,"can not be multiply by itself."
                         )
  else if null atom mvar u and car mvar u eq 'G3 then
         if ldeg u = 1 then simpCGraph1(lc u,mvar u . v,w)
         else if ldeg u = 2 then simpCGraph1(lc u,mvar u . mvar u . v,w)
	 else CError list("Vertex",list('!*SQ,u ./ 1,t),
		      "can not be multiplied by itself more then twice."
                         )
  else simpCGraph1(lc u,v,MultF(!*p2f lpow u,w))$

%----------------------------------------------------------------------
endmodule;

end;
