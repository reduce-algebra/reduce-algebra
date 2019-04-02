module pade;  % Pade' Approximations.

% Author: Lisa Temme

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


% Date: 15/6/95.
% General code tidy-up by Alan Barnes, march 2019

algebraic;

load taylor;
% not much advantage in using tps here as expansion order n+d is fixed

load solve;

%**************
%% Include a boolean function to check for taylor expression
procedure taylorp(x);
   lisp eqcar(x,'taylor);



%% The Pade Function

procedure pade(f, x, h, n, d);
  % f is function to be approximated
  % x is function variable
  % h is point at which approximation is evaluated
  % n is the required degree of the numerator in the rational approximation
  % d is the required degree of the denominator in the rational approximation
begin scalar y, g, a, b, numer, denom, variable_list, coeff_list,
             tay_expsn, solns, count, answer;

  % check to see if input is rational
  % if so larger degrees of n & d will return the input f
  if type_ratpoly(f, x) and deg(num f, x) <= n and deg(den f, x) <= d then
     return f
  else <<
     y := lisp gensym();            % declare y as local variable
     lisp(a:=  gensym());           % declare a and b as local operators
     lisp(b:=  gensym());                  
     lisp eval list('operator, mkquote list a);
     lisp eval list('operator, mkquote list b);

     numer :=  for k := 0 : n sum a(k)*y^k;
     denom :=  for j := 0 : d sum b(j)*y^j;
     variable_list := append(for k := 0 : n collect a(k),
	                      for j := 0 : d collect b(j));

     g := sub(x=y+h, f);     % rewrite f in terms of y at 0
     tay_expsn := taylortostandard(taylor(g, y, 0, n+d));
     if not(freeof(tay_expsn, df)) then rederr "not yet implemented"
          % Some Taylor Expansions do not exist at present.
     else <<
         coeff_list :=
	   coeff(denom*num(tay_expsn) - numer*den(tay_expsn), y);
	
        % Only consider first n+d+1 coefficients at most.
        if n+d+1 <= length(coeff_list) then
           coeff_list := for k := 1 : n+d+1 collect part(coeff_list, k);

        solns := solve(coeff_list, variable_list);
        count :=0;
        for each r in
            (for each q in
                 (for p := n+2 : n+d+2 collect part(first solns, p))
              collect part(q, 2))
          do if r = 0 then count := count+1;

        % if all the coefficients of the denominator are zero
        if count = d+1 then
           rederr "Pade Approximation of this order does not exist"

        else <<
           answer:= sub(solns, numer/denom);
           % if Pade would be returned as a Taylor expansion
           if taylorp answer then
              rederr "no Pade Approximation exists"
           else
	      return sub(y = x, answer)
        >>;
     >>;
  >>;
end;

endmodule;

end;
