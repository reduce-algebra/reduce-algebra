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
%  ibeta!:cont!:frac(iter,a,b,x) - recursively computes
%               the value of the continuous fraction used to
%               approximate the incomplete beta function.
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

%% operator igamma , igamma!:eval, ibeta;

% Set the maximum number of iterations for the continued fraction
% used in ibeta to be 200.

algebraic (ibeta!:max!:iter := 200);

% See the let rules for iGamma and iBeta in "alg/spcfnint.red".


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


% Function ibeta!:cont!:frac: calculates  1   c(2)  c(3)
%                                        ---  ----  ----  ...
%                                        1 +  1  +  1  +
% where
%        c(2i) =  - (a + i - 1) (b - i)   *   x
%                ---------------------------------
%                (a + 2i - 2) (a + 2i - 1) (1 - x)
% and
%      c(2i+1) =  i (a + b + i - 1)   *   x
%                -----------------------------
%                (a + 2i - 1) (a + 2i) (1 - x)

%expr procedure ibeta!:cont!:frac(iter,iter_max,a,b,x);
%begin
% scalar value,c_odd,c_even;
%
% if not (fixp(iter) and fixp(iter_max) and numberp(x)) then
%  rederr("ibeta!:cont!:frac called illegally");
%
% if (iter>iter_max) then
%  value := 0
% else
% <<
%  c_even := -(a+iter-1)*(b-iter)*x / ((a+2*iter-2)*(a+2*iter-1)*(1-x));
%  c_odd := iter*(a+b+iter-1)*x / ((a+2*iter-1)*(a+2*iter)*(1-x));
%  value := c_even /
%               (1 + (c_odd /
%                       (1 + ibeta!:cont!:frac(iter+1,iter_max,a,b,x))))
% >>;
%
% return value;
%end;

% The above version recurses to a depth of iter_max which may be reasonably
% large. I now provide an alternative version that does the calculation
% from the inside out and hence avoids that nesting.

algebraic procedure ibeta!:cont!:frac(iter, a, b, x);
   begin scalar value := 0;
      % Note that iter is an integer; try to keep integer computations
      % separate from real computations.
      while iter >= 1 do
      begin scalar iter1 := iter - 1, !2iter := 2*iter, !2iter1 := !2iter - 1,
            x1 := 1.0 - x, c_even, c_odd;
         c_even := -(a+iter1)*(b-iter)*x / ((a+(!2iter-2))*(a+!2iter1)*x1);
         c_odd := iter*(a+b+iter1)*x / ((a+!2iter1)*(a+!2iter)*x1);
         value := c_even /
                    (1 + (c_odd /
                            (1 + value)));
         iter := iter - 1;
      end;
      return value;
   end;

% Function ibeta!:eval: returns the value of the incomplete beta
% function with parameters a and b at point x. Method due to Muller (1931).

algebraic procedure ibeta!:eval(a, b, x);
   % Return a numerical approximation to I_x(a,b) = ibeta(a,b,x).
   % Assume a, b, x real, a>0, b>0, and 0<x<1; ensured by let rules.
   % See https://dlmf.nist.gov/8.17 and
   % https://en.wikipedia.org/wiki/Beta_function#Incomplete_beta_function.
   begin scalar ab2 := a + b + 2.0;
      return if x > (a+1.0)/ab2 or 1.0-x < (b+1.0)/ab2 then
         1.0 - ibeta!:eval1(b, a, 1.0-x)
      else
         ibeta!:eval1(a, b, x);
   end;

algebraic procedure ibeta!:eval1(a, b, x);
   begin scalar last_value, value, arg, iter,
         epsilon := 10^-(precision(0)+3);
      arg := gamma(a+b) * x^a * (1.0-x)^(b-1.0) / (a * gamma(a) * gamma(b));
      % A starting point of 30 levels of continued fraction.
      iter := 30;
      % Starting value that will force calculation a second time at least.
      value := -1;
      repeat <<
         last_value := value;
         value := arg / (1.0 + ibeta!:cont!:frac(iter, a, b, x));
         iter := iter + 10
      >> until abs(value - last_value) < epsilon
         or iter > ibeta!:max!:iter;
      % Error condition should not occur, but in case it does...
      if iter > ibeta!:max!:iter then symbolic lprim
         "ibeta max iteration limit exceeded; result may not be accurate";
      return value;
   end;

endmodule;

end;
