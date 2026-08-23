module igamma;                          % part of SFGAMMA package

% Author : Daniel Hobbs , University of Bath, 1995 - 1996
%
% Incomplete beta code revised by FJW, August 2026
%
%--------------------------------------------------------------------------
%
%  The incomplete gamma function.
%
%  igamma!:iter!:series(a,x,iter,sum,last_term) - iteratively computes the
%               value of an approximation to an infinite series used in
%                igamma (for x<=1 or x<a).
%
%  igamma!:cont!:frac(a,x,iter,iter_max) - iteratively computes the value of
%       the continuous fraction used in igamma (for other values of x).
%
%  igamma!:eval(a,x) - returns the value at point x of the
%               incomplete gamma function of order ord.
%
%  The incomplete beta function.
%
%  ibeta!:eval(a,b,x) - returns the approximate value of the
%               incomplete beta function with parameters a and b at
%               point x, computed using a continued fraction.
%
%--------------------------------------------------------------------------

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

% --------------------------- global variables ----------------------------

fluid '(!:sfiterations);

% See the definitions of iGamma and iBeta in "alg/spcfnint.red".

% Set the maximum number of iterations for the continued fraction used
% in ibeta!:eval:

share ibeta!:max!:iter;  ibeta!:max!:iter := 100;

% %%%%%%%%%%%%%%%%%%%%%%%%%
% Incomplete gamma function
% %%%%%%%%%%%%%%%%%%%%%%%%%

% Function igamma!:iter!:series:   --  cum_gamma_iter        x^i
%                                  \                       -------------
%                                  /                       (a+1)...(a+i)
%                                  --  i=1
% Uses Battacharjee's method (1970) (computed recursively).

algebraic procedure igamma!:iter!:series(a,x,iter,sum,last_term);
begin
 scalar value,this_term;

 if (last_term < 10^-(precision(0)+3)) then
  value := sum
 else
 <<
  this_term := (last_term * x / (a+iter));
  value := igamma!:iter!:series(a,x,iter+1,sum+this_term,this_term)
 >>;

 return value;
end;


% Function igamma!:cont!:frac           1   1-a   1   2-a   2
%                                      ---  ---  ---  ---  ---  ...
%                                      x +  1 +  x +  1 +  x +
% Recursively computes fraction using
% Abramowitz and Stegun's method (1964), formula 6.5.31
% see also DLMF, http://dlmf.nist.gov/8.9.E2

algebraic procedure igamma!:cont!:frac(a,x,iter,iter_max);
begin
 scalar value;

 if (iter>iter_max) then
  value := 0
 else
  value := (iter - a)/
              (1 +      (iter/
                    (x + igamma!:cont!:frac(a,x,iter + 1,iter_max))));

 return value;
end;


% Function igamma!:eval returns the value at point x of the
% incomplete gamma function with order ord.

algebraic procedure igamma!:eval(a,x);
begin
 scalar arg,frac,last!:frac,acc,value;

 % Decide whether to use a series expansion or a continued fraction.
 if (x<=1 or x<a+2) then
 <<
  value := (exp(-x) * x^a) * (1 + igamma!:iter!:series(a,x,1,0,1)) /
             gamma(a + 1)
 >>
 else
 <<
  % Set required accuracy to be 3 decimal places more than
  % current precision.
  acc := 10 ^ -(precision(0)+3);
  % Obtain a starting value.
  frac := igamma!:cont!:frac(a,x,1,1);
  !:sfiterations := 1;
  % Repeat loop until successive results of continued fraction converge.
  repeat
  <<
   !:sfiterations := !:sfiterations + 1;
   last!:frac := frac;
   frac := igamma!:cont!:frac(a,x,1,!:sfiterations)
  >>
  until (last!:frac - frac) < acc;

  arg := exp(-x) * x^a / gamma(a);
  value := 1 - arg / (x + frac)
 >>;

 return value;
end;

% %%%%%%%%%%%%%%%%%%%%%%%%
% Incomplete beta function
% %%%%%%%%%%%%%%%%%%%%%%%%

algebraic procedure ibeta!:eval(a, b, x);
   % Return a numerical approximation to I_x(a,b) = ibeta(a,b,x).
   % Assume a,b,x real, a>0, b>0, 0<x<1; ensured by let rules.
   % Algorithm follows https://dlmf.nist.gov/8.17.  See also
   % https://en.wikipedia.org/wiki/Beta_function#Incomplete_beta_function.
   begin scalar ab2 := a + b + 2.0;
      return if x > (a+1.0)/ab2 or 1.0-x < (b+1.0)/ab2 then
         1.0 - ibeta!:eval1(b, a, 1.0-x)
      else
         ibeta!:eval1(a, b, x);
   end;

% At the default precision of 12, the following procedure appears
% always to require fewer than 10 iteration.

algebraic procedure ibeta!:eval1(a, b, x);
   % Return I = ibeta(a,b,x) = x^a*(1-x)^b/a*B(a,b) * (1/(1+CF)),
   % where B(a,b) = Gamma(a)*Gamma(b)/Gamma(a+b)
   % and CF = d_1 / (1 + d_2 / (1 + d_3 / 1 + ... )).
   % The convergents for even m are less than I, and the convergents
   % for odd m are greater than I, so their difference provides a
   % reliable error bound.  The absolute error in CF is approximately
   % equal to the relative error in I.
   begin scalar epsilon := 10^-precision(0), % absolute CF error
         const := x^a * (1.0-x)^b * gamma(a+b) / (a * gamma(a) * gamma(b)),
      CFold, CF := 0, dlist;        % dlist = {d_2iter, ..., d_2, d_1}
      integer m;
      % Compute coefficients d_m FORWARDS for m = 1, 2, ..., 2n-1, 2n
      % and push them onto the list dlist.  Compute CF using
      % coefficients d_m BACKWARDS for m = 2n, 2n-1, ..., 2, 1.
      repeat
      begin scalar am1, a2m, a2m1,
            d2m, d2m1;               % d_{2m}, d_{2m-1}, m = 1,2,3,...
            % NB: d2m1 = d_{2m-1} = d_{2(m-1)+1}, NOT d_{2m+1}.
            m := m + 1;
            am1 := a+(m-1);  a2m := a+2.0*m;  a2m1 := a2m-1.0;
            d2m := m*(b-m)*x / a2m1 / a2m;
            d2m1 := -am1*(am1+b)*x / (a2m-2.0) / a2m1;
            symbolic (dlist := d2m . d2m1 . dlist);
            CFold := CF;  CF := 0;
            symbolic for each d_m in dlist do
               algebraic (CF := d_m / (1.0 + CF));
      end
         until abs(CF - CFold) < epsilon or m >= ibeta!:max!:iter;
      % write m_max := m, "  ", CF_abserr := abs(CF - CFold);
      if m >= ibeta!:max!:iter then symbolic lprim
         {"ibeta max iteration limit", ibeta!:max!:iter,
            "exceeded; result may not be accurate"};
      return const / (1.0 + CF);
   end;

endmodule;

end;
