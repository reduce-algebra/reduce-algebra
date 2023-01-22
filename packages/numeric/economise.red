module economise;  % Economise series approximations via Chebyshev.

% Author: Arthur Norman

% Copyright (c) 2022 Arthur Norman

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

% Usage:
%   economise_series(series, variable[and range], accuracy, ?evenodd);
%
% The function may be given either as a polynomial (including ones
% with symbolic or fractional coefficients(, such as
%     1 + pi*x/2 - 3*x^3/77
% OR it can the output from "taylor" as in
%     taylor((sin x - x)/x^3, x, 0, 10)
% OR it can have been generated using the "tps" package, as in
%     psexplim 20;
%     ps((cos x - 1)/x^2, x, 0);
% but note that the series expansions generated using either taylor or
% tps are expected to be about zero.
%
% The variable can be given as just a variable, in which case the
% economisation will be across the range -1 .. 1. Or it can be in
% a form like
%     x = (0 .. pi/4)
% or  x = (100 .. 101)
% In such cases the output will still be a straightforward polynomial,
% but it will be expected that the user is only interested in evaluating it
% over the specified range. Note that if the range is not symmetric about
% zero or at least has zero at one end of it then the polynomaial may have
% large coefficients which tend to cancel when evaluated in the range
% requested - that may have adverse effects as regards numerical stability.
%
% The accuracy is specified using a value which must be numeric. If this
% value is greater than 1 then (the integer part of) it specifies a limit
% to the degree of the polynomial that will be returned. In that case it
% is up to the user to consider whether this meets any particular target
% for precision. If its value is less then 1 then the input series must
% have coefficients that can be evaluated to numeric values. The series
% is then converted to one such that the terms discarded should always
% have absolute value less than the accuracy parameter over the specified
% range.

% The final parameter "evenodd" is optional. If it is present it should
% be one of the words "even_terms" or "odd_terms" and when present it
% expects the output series to have alternate entries zero, and it filters
% them out.

% In each case the economisation proceeds by repeatedly looking at the
% highest degree terms in the input series. If that is C*x^n then
% the polynomial C*T_n(x)/2^n is subtracted, where T_n is the nth Chebyshev
% polynomial (scaled and shifted if necessary) so that T_n(x)/2^n has values
% in the range -1 .. 1 over the interval.  In the case that an absolute
% precision target is sought economisation will proceed so long as |C/2^n|
% is less than that target. Note that this is arranging a minimax style
% approximation.

% If "on rounded" is set then all coefficients will be processed in
% floating point. Otherwise the polynonial will be processed exactly,
% although if an absolute precision target is set then the test of C/2^n
% against it will be performed in a temporarily-set rounded mode.

% Example:
%    on rounded; precision 60;
%    r := economise_series(taylor((sin x - 1)/x^3, x, 0, 50),
%                          x = (-pi/4 .. pi/4), 1.0e-40);
%    precision 40; coeff(r, x);

create!-package('(economise),'(numeric));

% First I have a little bit of code that can retrieve the nth Chebyshev
% polynomial. This stores alread-calculated oned in an a-list and uses
% the recurrence formula when it needs a new one. I could have used a hash
% table and I could have taken steps to ensure that the code never recursed
% deeply, but I do not think either of those are necessary here. Return
% as an SF.

fluid '(chebyshev_polynomials);

chebyshev_polynomials := list(
   (0 . 1),
   (1 . ((mksp('x, 1) .* 1) .+ nil)));

symbolic procedure get_cheb n;
  begin
    scalar w := assoc(n, chebyshev_polynomials);
    if null w then begin
      scalar a, b;
      a := get_cheb(n-2);
      b := get_cheb(n-1);
      w := n . addf(multf((mksp('x, 1) .* 2) .+ nil, b), negf a);
      chebyshev_polynomials := w . chebyshev_polynomials
    end;
    return cdr w
  end;

% Now get a polynomial that oscillates between +1 and -1 over the
% range lo .. hi. Return as a list of coefficients each of which is
% in prefix form.

symbolic procedure get_shifted_cheb(n, lo, hi);
  begin
    scalar p := (get_cheb n ./ 1), newx, w;
% lo and hi will be standard quotients
    newx := quotsq(subtrsq(((mksp('x, 1) .* 2) .+ nil) ./ 1, addsq(lo, hi)),
                   subtrsq(hi, lo));
% The second arrgument to subsq is in the form  ((x . prefix_form))
    p := subsq(p, list('x . prepsq newx));
% Now convert into a list of coefficients, each in prefix form.
    w := denr p;
    p := cdr coeff1(mk!*sq(numr p ./ 1), 'x, nil);
    if w neq 1 then <<
      w := prepf w;
      p := for each c in p collect
         prepsq simp list('quotient, c, w) >>;
    return p;
  end;

symbolic procedure lose_trailing_zeroes l;
  begin
    scalar r := reverse l;
    while eqcar(r, 0) do
       r := cdr r;
    return reverse r
  end;

symbolic procedure subtract_multiple(ser, c, ti);
  if null ser then nil
  else prepsq simp list('difference, car ser, list('times, c, car ti)) .
    subtract_multiple(cdr ser, c, cdr ti);

% Many interesting series are either even or odd, so alternate terms in
% them are missing. This allows me to avoid handing back all those
% boring zeros.

symbolic procedure collect_evens u;
  if null u then nil
  else if null cdr u then list car u
  else if not zerop cadr u then
    rederr "series does not have alternate terms zero"
  else car u . collect_evens cddr u;

% The main entrypoint.
% Usage:
%    ecomomise_series(series, variable(and range), degree/error limit,
%                     ?indication is results is an odd or ecen series);

fluid '(ps!:exp!-lim);

symbolic procedure economise_series u;
  begin
    scalar ser, var, lo, hi, eps, nterms, stop,
           evenodd, w, w1, deg, ti, err, olderr;
    terpri();
    if length u < 3 then rederr "economise_series(series, var, precision)";
    ser := simp car u;
    lo := (-1) ./ 1;
    hi := 1 ./ 1;
    var := cadr u;
    if eqcar(var, 'equal) and eqcar(caddr var, '!*interval!*) then <<
       w := caddr var;
       var := cadr var;
       lo := simp cadr w;
       hi := simp caddr w >>;
    var := simp var;
    w1 := !*rounded;
    if not w1 then on rounded;
    w := precision1(6, nil);
    eps := prepsq simp caddr u;
    precision1(w, nil);
    if not w1 then off rounded;
    if eqcar(eps, '!:rd!:) then eps := cdr eps;
    if eps > 1.0 then <<
       nterms := fix eps;
       eps := nil >>
    else nterms := 1;
    u := cdddr u;
    if eqcar(u, 'even_terms) or eqcar(u, 'odd_terms) then evenodd := car u;
% If the series is output from taylor() I am liable to get ser as
%        ((((T .** 1) .* 1) .+ nil) ./ 1)
% where T is of the form
%   (taylor* coeffList xPoint stuff stuff)
% with coefflist in the form of a list with SQ coefficients c0, c1... :
%    ((((0) . c0)   (((1) . c1) ...)
% and xPoint is something like
%    (((var) _ _ _)
% I will want to insist that the variable named there matches the one
% I am asking to economise in.
%
% For tps the input will have simplified to
%    (psObject ./ 1)
% where psObject is a domain element presenting as
%    (!:ps!: ...)
% and the coefficients will need to be extracted from that object because
% it only computes them when asked to. But it is possible to extract
% them as standard quotients, and one should do so as far as psexplim
% suggests.
   w := numr ser;
% If I was presented with the output from taylor() then use taylortostandard
% to turn it into a polynomial.
    if null red w and onep ldeg w and eqcar(mvar w, 'taylor!*) then <<   
      w1 := simp taylortostandard(mvar w);
      ser := multsq(w1, lc w ./ denr ser) >>;
    if eqcar(w, '!:ps!:) then <<
      w1 := prep!:ps(w, ps!:exp!-lim);
      ser := simp w1 >>;
    w := denr ser;
    ser := cdr coeff1(mk!*sq(numr ser ./ 1), mk!*sq var, nil);
    if w neq 1 then <<
      w := prepf w;
      ser := for each c in ser collect
        prepsq simp list('quotient, c, w) >>;
    ser := lose_trailing_zeroes ser;
% Now my input polynomial has been turned into a list of prefix forms. I
% can start the economisation process...
    olderr := 0.0;
    while (deg := length ser - 1) > nterms and not stop do <<
      ti := get_shifted_cheb(deg, lo, hi);
      err := list('quotient, car lastpair ser, 2^(deg-1));
      w1 := !*rounded;
      if not w1 then on rounded;
      w := precision1(6, nil);
      err := prepsq simp err;
      precision1(w, nil);
      if not w1 then off rounded;
      if eqcar(err, 'minus) then err := cadr err;
      if eqcar(err, '!:rd!:) then err := abs cdr err;
      if not numberp err or not numberp eps or err < eps then <<
        olderr := err;
        w := list('quotient, car lastpair ser, car lastpair ti);
        ser := subtract_multiple(ser, w, ti);
        ser := lose_trailing_zeroes ser >>
      else stop := t >>;
% If I stop because the user specified the number of terms wanted
% I will display my estimate of the error in the approximation. Provided
% I have a numeric estimate available.
    if not stop and numberp olderr then <<
      terpri(); prin2 "Error estimate: "; print olderr >>;
% Having economised I will tidy up in the cases where the series
% is expected to be even or odd.
    if evenodd = 'even_terms then
      ser := collect_evens ser
    else if evenodd = 'odd_terms then <<
      if not zerop car ser then
         rederr "series was supposed to be odd but has a constant term";
      ser := collect_evens cdr ser >>;
    return 'list . ser;
  end;

put('economise_series, 'psopfn, 'economise_series);

% The purpose of this code is to generate rational functions that
% interpolate to give an approximation to a function. By spreading the
% interpolation knots across a range from u to v there is a good
% prospect that the rational function found will be a good approimation
% to the specified function across that range. This is a useful thing
% to do because for many functions approximations via polynomials need
% quite large numbers of terms while rational approximations can deliver
% accuracy much more economically.
% Well ideally one would like minimax rational approximations but the
% scheme here is easier to implement! Also I force my rational function to
% match the target function perfectly as a sequence of evenly spaced
% abscissa, and it is very probable that one could get better approximations
% (ie the same accuracy but with fewer terms) by some other spacing.

% This is going to work with rational functions expressed as generalised
% continued fractions that are set up such that they are functions of x
% and their values can be predicted at a series of points x_1.

% Consider
%    a function f(x) that has valued f_i at points x_i for i = 0,2,...,N-1
% I will set up a sequnce of approximations R_i based on coefficients a_i
% that I will want to find and a sequence
%    R_0 =   a_0;
%    R_1 =   a_0 + (x - x_0)/ a_1
%    R_2 =   a_0 + (x - x_0)/(a_1 + (x - x_1)/ a_2)
%    R_3 =   a_0 + (x - x_0)/(a_1 + (x - x_1)/(a_2 + (x - x_2)/a_3))
%    ...
%
% I solve the first of these for a_0 to make R_0(x_0) = f_0. Then because of
% the factor (x - x_0) all the subsequence R_i also have that value at x_0.
%
% Next I solve the second for a_1 so that R_1(x_1) = f_1. And so on.
% I will find that R_N(x) = f for x in {x_0, x_1, ... x_N-1}. Ie I have found
% an interpolating approximation for f through those N points. It will be a
% rational function with about the same degree numerator as denominator.
%
% Now I write P_0 = a_0, Q_0 = 1
%         and P_1 = a_0*a_1 + x-x_0, Q_2 = a_1
% then
%     P_i = a_i*P_i-1 + (x - x_i-1)*P_i-2
%     Q_i = a_i*Q_i-1 + (x - x_i-1)*Q_i-2
%
% Now at stage k I will want to find a_k to get a value to match at x_k.
% So I want P_k(x_k)/Q_k(x_k) - f(x_k)
%    a_k*P_k-1 + (x - x_k-1)*P_k-2 = f(x_k)*(a_k*Q_k-1 + (x - x_k-1)*Q_k-2)
% and if I separate out a_k I get
%    a_k*(P_k-1 - f(x_k)*Q_k-1) = (x_k-x_k-1)*(f(x_k)*Q_k-2 - P_k-2)
% so it is very easy to evaluate a_k. Well there is one caveat. If any of the
% knot-points x_i were repeated then that equation would lead to a division
% 0/0. Well in that case it would need to be evaluated as the limit as x
% approached x_k and arranging that just involved a bit of differentiation.
                                     
% I limit myself to a maximum of 100 points here...
array !~pade_xx(100), !~pade_a(100), !~pade_p(100), !~pade_q(100);

fluid '(save_precision save_rounded);

% If accuracy > 1 then it is treated as a request for exactly that
% many points to be used in the interpolation. Otherwise it is a
% target for the absolute error in the approximation. 

algebraic procedure multipoint_pade(f, u, v, accuracy);
  begin
    scalar N, Nlimit, targetErr, stopOnErr, worst, err, res;
    if accuracy > 1 then <<
       N := fix accuracy;
       if N > 100 then rederr "multipoint_pade precision must be at most 100";
       stopOnErr := 0 >>
    else <<
       N := 2;
       targetErr := accuracy;
       worst := targetErr + 1;
       stopOnErr := 1 >>;
    if n > 50 then return "N too large, sorry";
    lisp (save_rounded := !*rounded);
    lisp (save_precision := precision (2*precision 0));
    on rounded;
    while (stopOnErr=0 and N<=fix accuracy) or
          (stopOnErr=1 and worst>targetErr and N<100) do <<

      for i:=0:N-1 do
        !~pade_xx(i) := u + i*(v-u)/(N-1);

      !~pade_a(0) := f(!~pade_xx(0));
      !~pade_a(1) := (!~pade_xx(1)-!~pade_xx(0))/(f(!~pade_xx(1)) - !~pade_a(0));

      !~pade_p(0) := !~pade_a 0;
      !~pade_q(0) := 1;
      !~pade_p(1) := !~pade_a 0 * !~pade_a 1 + (x - !~pade_xx 0);
      !~pade_q(1) := !~pade_a 1;

      for i := 2:N-1 do <<
        !~pade_a(i) := (!~pade_xx(i)-!~pade_xx(i-1))*(f(!~pade_xx(i))*sub(x=!~pade_xx(i),!~pade_q(i-2)) -
                                          sub(x=!~pade_xx(i),!~pade_p(i-2))) /
                (sub(x=!~pade_xx(i),!~pade_p(i-1)) - f(!~pade_xx(i))*sub(x=!~pade_xx(i),!~pade_q(i-1)));

        !~pade_p(i) := !~pade_a i * !~pade_p(i-1) + (x - !~pade_xx(i-1))*!~pade_p(i-2);
        !~pade_q(i) := !~pade_a i * !~pade_q(i-1) + (x - !~pade_xx(i-1))*!~pade_q(i-2);
        worst := 0;
        for j := 0 : 50*N do <<
          z := u + j*(v-u)/(50*N);
          err := abs(f(z) - sub(x=z, !~pade_p(i))/sub(x=z, !~pade_q(i)));
          if err > worst then worst := err >> >>;

      if stopOnErr = 1 then <<
         precision 6;
         lisp assgnpri("With N=", nil, nil);
         lisp assgnpri(N, nil, nil);
         lisp assgnpri(" error = ", nil, nil);
         lisp assgnpri(worst, nil, nil);
         lisp terpri!* nil;
         lisp precision (2*save_precision) >>;
      N := N+1 >>;
    precision 6;
    write "Order ", N-1, "  Worst error = ", worst;
    lisp precision save_precision;
    lead := sub(x=0, !~pade_q(N-2));
    res := {coeff(!~pade_p(N-2)/lead, x),
            coeff(!~pade_q(N-2)/lead, x)};
    lisp if not save_rounded then off rounded;
    return res;
  end;

% r should be the output from multipoint_pade. This evaluates it at
% x which can be symbolic or numeric.
% Very typically evaluate_pade will return an ugly result where numerator
% and denominator will have been normalised more based on the highest
% degree terms rather than the constant terms (which will oftent start off
% with values close to 1). So separating out numerator and denominator
% separately using num_pade and den_pade may often feel more useful.

algebraic procedure evaluate_pade(r, x);
  begin
    scalar p:=0, q:=0;
    foreach v in reverse first r do p := p*x + v;
    foreach v in reverse second r do q := q*x + v;
    return p/q;
  end;

algebraic procedure num_pade(r, x);
  begin
    scalar p:=0;
    foreach v in reverse first r do p := p*x + v;
    return p;
  end;

algebraic procedure den_pade(r, x);
  begin
    scalar q:=0;
    foreach v in reverse second r do q := q*x + v;
    return q;
  end;

% One of the uses of the above will be to generate C or C++ code for
% the avaluation of special functions. From C99 onwards and from C++17
% it has been possible to write floating point literals in hexadecimal
% format with a guarantee that they end up in the eventual code properly
% rounded. Here is some stuff to format the output as a sequence of
% floats in hex notation, and then the same for "double-double" and
% "triple double" format.

% This function aprinhex is present to ensure that this code is
% valid under PSL as well as CSL (CSL has a built in "prinhex" function.
% psl has outputbase!*, but rather than having code that is conditional
% to select between the two scheme I just do things explicitly and
% not terribly efficiently here. 

symbolic procedure aprinhex x;
  if not fixp x then rederr "aprinhex only handles integer arguments"
  else if x < 0 then << prin2 "-"; aprinhex(-x) >>
  else if x < 10 then prin2 x
  else if x < 16 then prin2 nth('(a b c d e f), x-9)
  else << aprinhex (x/16);
          aprinhex remainder(x, 16) >>;

flag('(aprinhex), 'opfn); 

% Display a real value in hex floating point notation and return
% any residual error.

% The notation required will be 0x1NNNNNNNNNNNNNpXX with exactly 13 hex
% digits (NN.NN) and a leading 1 bit. The (optionally signed) exponent
% the indicates the power of 2 that the 53-bit integer as written must be
% scaled by to get the value that is wanted. Note that this is not the
% value stored in the exponent field of the representation  if the float
% in memory. I will avoid thinking about sub-normal numbers, NaNs and
% infinities, but 0.0 will be a special case.

% This function switches "on rounded" on a temporary basis while it works.
% It is up to the user to ensure that "precision N" has been suitably set.
% The function should only be passed numeric arguments. But it should
% be happy with integers or fractions as well as floats. You need to
% set "precision" to suit your needs.

algebraic procedure prinhexlit !~pade_xx;
  begin
    scalar x, bx, hi, lo, ix, err, save_rounded;
    lisp (save_rounded := !*rounded);
    on rounded;
    if !~pade_xx = 0.0 then lisp prin2 "0.0"
    else <<
      bx := 0;
      hi := 2.0^53;
      lo := 2.0^52;
      x := !~pade_xx;
      if x < 0 then <<
         lisp prin2 "-";
         x := -x >>;
      while x < lo do <<
        x := x+x;
        bx := bx-1 >>;
      while x >= hi do <<
        x := x/2;
        bx := bx+1 >>;
      ix := fix x;
      err := x - ix;
      if err >= 0.5 then ix := ix+1
      else if err < -0.5 then ix := ix-1;
      lisp prin2 "0x";
      aprinhex ix;
      lisp prin2 "p";
      lisp prin2 bx;
      if !~pade_xx < 0 then ix := -ix;
      !~pade_xx := !~pade_xx - ix*2.0^bx;
      lisp if not save_rounded then off rounded >>;
    return !~pade_xx;
  end;

algebraic procedure prinhexlitlist l;
  begin
     lisp terpri();
     lisp prin2 "{";
     while length l neq 0 do <<
        lisp ttab 4;
        prinhexlit first l;
        if length l neq 1 then lisp prin2 ",";
        l := rest l;
        lisp terpri() >>;
     lisp prin2 "}";
     lisp terpri()
  end;

algebraic procedure prinhexlitlist2 l;
  begin
     scalar w;
     lisp terpri();
     lisp prin2 "{";
     while length l neq 0 do <<
        lisp ttab 4;
        lisp prin2 "{";
        w := prinhexlit first l;
        lisp prin2 ", ";
        prinhexlit w;
        lisp prin2 "}";
        if length l neq 1 then lisp prin2 ",";
        l := rest l;
        lisp terpri() >>;
     lisp prin2 "}";
     lisp terpri()
  end;

algebraic procedure prinhexlitlist3 l;
  begin
     scalar w;
     lisp terpri();
     lisp prin2 "{";
     while length l neq 0 do <<
        lisp ttab 4;
        lisp prin2 "{";
        w := prinhexlit first l;
        lisp prin2 ", ";
        w := prinhexlit w;
        lisp prin2 ", ";
        prinhexlit w;
        lisp prin2 "}";
        if length l neq 1 then lisp prin2 ",";
        l := rest l;
        lisp terpri() >>;
     lisp prin2 "}";
     lisp terpri()
  end;

endmodule;

end;
