module taygamma;

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

%*****************************************************************
%
%       Simplification functions for gamma function and derivatives
%
%*****************************************************************


exports taysimpGamma, taysimpPsi, taysimpPolyGamma;

imports

% from the REDUCE kernel:
        !*f2q, !*k2q, denr, eqcar, mk!*sq, mksq, mvar, nfactorial, numr, over,
        simp!*,

% from the header module:
        cst!-taylor!*, make!-cst!-powerlist, prune!-coefflist,
        set!-tayorig, taycfpl, taycoefflist, taylor!-kernel!-sq!-p, TayOrig,
        taytemplate,

% from the module Tayintro:
        confusion,
        taylor!-error,

% from the module Tayutils:
        get!-cst!-coeff, is!-neg!-pl,

% from the module Taybasic:
        addtaylor, invtaylor, multtaylorsq, negtaylor,
        quottaylor,

% from the module TayExpnd:
        taylorexpand!-diff,

% from the module Taysimp:
        expttayrat, taysimpsq;


fluid '(!*taylorkeeporiginal !*!*taylor!-epsilon!*!* frlis!*);



COMMENT The Gamma function of a Taylor kernel are calculated by
        differentation, except when a pole occurs, i.e. the constant
	term of Gamma's argument is a non-negative integer.
	In the latter case, the relation

             x * Gamma(x) = Gamma(x + 1)

        is used to shift the argument to a regular point.

        For psi(x) = Gamma'(x)/Gamma(x) the shift formula

             1/x + psi(x) = psi(x+1)

        is used,and for the polygamma functions the formula

             (-1)^n*n!/x^(n+1) + polygamma(n,x) = polygamma(n,x+1)

        follows;


symbolic procedure taysimpGamma u;
  if not eqcar(u,'Gamma) or cddr u
    then confusion 'taysimpGamma
   else begin scalar l,l0,c0,tay,tp;
     tay := taysimpsq simp!* cadr u;
     if not taylor!-kernel!-sq!-p tay
       then return mksq({car u,mk!*sq tay},1);
     tay := mvar numr tay; % Gamma's argument
     tp := taytemplate tay;
     l0 := make!-cst!-powerlist tp;
     %
     % First we get rid of possible zero coefficients.
     %
     l := prune!-coefflist taycoefflist tay;
     if null l then return taysimpGamma!*(tay,1);
     %
     % The following relies on the standard ordering of the
     % TayCoeffList.
     %
     if is!-neg!-pl taycfpl car l
       then taylor!-error('essential!-singularity,car u);
     c0 := get!-cst!-coeff tay;
     if denr c0 = 1 and (null numr c0 or fixp numr c0 and numr c0 < 0)
       then return taysimpGamma!*(tay,if null numr c0 then 1 else 1-numr c0)
      else return taylorexpand!-diff(u,tp,t);
  end;


symbolic procedure taysimpGamma!*(tay,count);
   begin scalar tay1,tay2,tp;
     tp := taytemplate tay;
     %
     % Apply the relation Gamma(x) = Gamma(x+1)/x count times,
     %  i.e., compute Gamma(x+count) and do count divisions
     %
     tay1 := addtaylor(tay,
                       cst!-taylor!*(!*f2q count,tp));
     tay1 := taysimpGamma {'Gamma,tay1};
     if not Taylor!-kernel!-sq!-p tay1 then confusion 'taysimpGamma;
     tay1 := mvar numr tay1;
     tay2 := tay;
     for i:=1:count do <<
       tay1 := quottaylor(tay1,tay2);
       tay2 := addtaylor(tay2,cst!-taylor!*(1 ./ 1,tp));
     >>;
     if !*taylorkeeporiginal and TayOrig tay
       then set!-tayorig(tay1,{'Gamma,TayOrig tay});
     return !*k2q tay1;
   end;

put('Gamma,'taylorsimpfn,'taysimpGamma);

symbolic procedure taysimpPsi u;
  if not eqcar(u,'Psi) or cddr u
    then confusion 'taysimpPsi
   else begin scalar l,l0,c0,tay,tp;
     tay := taysimpsq simp!* cadr u;
     if not taylor!-kernel!-sq!-p tay
       then return mksq({car u,mk!*sq tay},1);
     tay := mvar numr tay; % Psi's argument
     tp := taytemplate tay;
     l0 := make!-cst!-powerlist tp;
     %
     % First we get rid of possible zero coefficients.
     %
     l := prune!-coefflist taycoefflist tay;
     if null l then return taysimpPsi!*(tay,1);
     %
     % The following relies on the standard ordering of the
     % TayCoeffList.
     %
     if is!-neg!-pl taycfpl car l
       then taylor!-error('essential!-singularity,car u);
     c0 := get!-cst!-coeff tay;
     if denr c0 = 1 and (null numr c0 or fixp numr c0 and numr c0 < 0)
       then return taysimpPsi!*(tay,if null numr c0 then 1 else 1-numr c0)
      else return taylorexpand!-diff(u,tp,t);
  end;


symbolic procedure taysimpPsi!*(tay,count);
   begin scalar tay1,tay2,tp;
     tp := taytemplate tay;
     %
     % Apply the relation Psi(x) = Psi(x+1) - 1/x count times,
     %  i.e., compute Psi(x+count) and do count subtractions.
     %
     tay1 := addtaylor(tay,
                       cst!-taylor!*(!*f2q count,tp));
     tay1 := taysimpPsi {'Psi,tay1};
     if not Taylor!-kernel!-sq!-p tay1 then confusion 'taysimpPsi;
     tay1 := mvar numr tay1;
     tay2 := negtaylor tay;   % this is -x
     for i:=1:count do <<
       tay1 := addtaylor(tay1,invtaylor tay2);
       tay2 := addtaylor(tay2,cst!-taylor!*(-1 ./ 1,tp));
     >>;
     if !*taylorkeeporiginal and TayOrig tay
       then set!-tayorig(tay1,{'Psi,TayOrig tay});
     return !*k2q tay1;
   end;

put('Psi,'taylorsimpfn,'taysimpPsi);

symbolic procedure taysimpPolyGamma u;
  if not eqcar(u,'PolyGamma) or not fixp cadr u or cadr u < 1 or cdddr u
    then confusion 'taysimpPolyGamma
   else begin scalar l,l0,c0,tay,tp;
     tay := taysimpsq simp!* caddr u;
     if not taylor!-kernel!-sq!-p tay
       then return mksq({car u,mk!*sq tay},1);
     tay := mvar numr tay; % PolyGamma's argument
     tp := taytemplate tay;
     l0 := make!-cst!-powerlist tp;
     %
     % First we get rid of possible zero coefficients.
     %
     l := prune!-coefflist taycoefflist tay;
     if null l then return taysimpPolyGamma!*(tay,cadr u,1);
     %
     % The following relies on the standard ordering of the
     % TayCoeffList.
     %
     if is!-neg!-pl taycfpl car l
       then taylor!-error('essential!-singularity,car u);
     c0 := get!-cst!-coeff tay;
     if denr c0 = 1 and (null numr c0 or fixp numr c0 and numr c0 < 0)
       then return taysimpPolyGamma!*(tay,cadr u,if null numr c0 then 1 else 1-numr c0)
      else return taylorexpand!-diff(u,tp,t);
  end;


symbolic procedure taysimpPolyGamma!*(tay,n,count);
   begin scalar tay1,tay2,tp,fct;
     tp := taytemplate tay;
     %
     % Apply the relation PolyGamma(n,x) = PolyGamma(n,x+1) - (-1)^n*n!/x^(n+1) count times,
     %  i.e., compute PolyGamma(x+count) and do count subtractions.
     %
     tay1 := addtaylor(tay,
                       cst!-taylor!*(!*f2q count,tp));
     tay1 := taysimpPolyGamma {'PolyGamma,n,tay1};
     if not Taylor!-kernel!-sq!-p tay1 then confusion 'taysimpPolyGamma;
     tay1 := mvar numr tay1;
     tay2 := negtaylor tay;   % again, -x
     fct := simp!* nfactorial n;
     for i:=1:count do <<
       tay1 := addtaylor(tay1,multtaylorsq(invtaylor expttayrat(tay2,(n+1) ./ 1),fct));
       tay2 := addtaylor(tay2,cst!-taylor!*(-1 ./ 1,tp));
     >>;
     if !*taylorkeeporiginal and TayOrig tay
       then set!-tayorig(tay1,{'PolyGamma,n,TayOrig tay});
     return !*k2q tay1;
   end;

put('PolyGamma,'taylorsimpfn,'taysimpPolyGamma);


endmodule;

end;
