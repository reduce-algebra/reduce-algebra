module coeff2;

%======================================================
%
%       coeff2 package
%
%   Author : F. Kako
%   Modification by :  M. Ito
%   revised April 2, 2009
%
%   Copyright (C) 2020
%   by Fujio Kako and Masaaki Ito, all rights reserved.
%
%======================================================;
%
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
%======================================================;
% $Id: $
% following functions are available in algebraic mode.
%------------------------------------------------------
% coeff2(F,X1,X2,...,XN):  
%        collects the coefficients of variables X1,X2,...,Xn
%        in F, and replaces each coefficient by special 
%        variables #1,#2....
%        F: polynomial
%        X1,X2,...,Xn: kernel
%
% nm(N): retrieves the value of #N.
%        N: integer
%
% eval2(F): evaluates an expression F with #1,#2,...
%           F: polynomial
%
% reset(): resets the special variables #1,#2,...
%
%======================================================;

create!-package('(coeff2),'(contrib misc));

off echo;

symbolic procedure simp!-coeff2 u;
	begin scalar x,v,klst;
		if !*factor then rederr
		  "Use COEFF2 after turning off the FACTOR switch";
		if null u then return (nil ./ 1);
		v := simp!* car u;
		if null cdr u then return v;
		klst := foreach y in cdr u collect !*a2k y;
		x := setkorder klst;
		v := coeff2!-f(reorder numr v, klst) ./
		     coeff2!-f(reorder denr v, klst);
		setkorder x;
		return (reorder numr v ./ reorder denr v)
	end$

symbolic procedure coeff2!-f(u,klst);
	if domainp u then u
	  else if not(mvar u memq klst) then
		begin scalar x;
			x := coeff!-mkid2();
			put(x,'myvalue,u);
			return list((x .** 1) . 1)
		end
	else addf(multf(coeff2!-f(lc u, klst), !*p2f lpow u),
		       coeff2!-f(red u, klst))$

put('coeff2, 'simpfn, 'simp!-coeff2)$

symbolic procedure eval2 u;
	mk!*sq eval2!-sq simp!* u$

symbolic procedure nm n;
	mk!*sq subf1(reorder get(coeff!-mkid0(n),'myvalue), nil)$

flag('(nm,eval2), 'opfn)$
flag('(nm,eval2), 'noval)$
global '(symcount)$
lisp (symcount := 0)$

symbolic procedure coeff!-mkid2();
	<<symcount := symcount + 1;
		intern compress nconc(explode '!#, explode symcount)>>$

symbolic procedure eval2!-sq u;
	cancel resimp(eval2!-f numr u  ./ eval2!-f denr u )$

symbolic procedure eval2!-f u;
	if domainp u then u
	  else addf(multf(eval2!-p lpow u, eval2!-f lc u),
                 eval2!-f red u)$

symbolic procedure eval2!-p u;
	begin scalar n,v,w;
		n := cdr u;
		v := car u;
		if atom v then
			if (w := get(v,'myvalue)) then
				return exptf(reorder w,n);
		return !*p2f u
	end$

symbolic procedure reset();
	while (symcount > 0) do
		<< remprop(coeff!-mkid0(symcount), 'myvalue);
		    symcount := symcount -1>>$

symbolic procedure coeff!-mkid0(n);
	intern compress nconc(explode '!#, explode n)$

flag('(reset),'opfn)$

endmodule;

end$
