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
% be one of the words "even_terms" or "odd)terms" and when present it
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

endmodule;

end;

