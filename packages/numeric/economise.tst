% The economise_series operator takes a power-series representation of
% a function over some (finite) interval and attempts to generate a lower
% degree polynomial that will give an accurate approximation to it.
% It achieves this by succesively eliminating the highest degree term in
% the series using a Chebyshev polynomial. The Chebyshev polynomial that
% is subtracted will lead to a good approximation to a minimax overall
% approximation.

% This first example starts with a simple explicit polynomial of
% degree 5 and trims it down to one of degree 4 where values should
% match reasonably well on the interval -0.5 to +0.5

economise_series(1 - x + x^2 - x^3 + x^4 - x^5 + x^6,
                 x = (-1/2 .. 1/2), 4);

% The next two cases generate coefficients suitable for computing sine
% and cosine in the range -pi/4 to +pi/4 such that the result will
% be accurate enough for IEEE-style 128-bit floating point. One illustrates
% use of taylor() to generate the series, while the other uses the tps
% package.

on rounded; precision 100;
r := economise_series(taylor((sin x - x)/x^3, x, 0, 60),
                      x = (-pi/4 .. pi/4), 20, even_terms)$
precision 40; r;

precision 100;
psexplim 60;
r := economise_series(ps((cos x - 1)/x^2, x, 0),
                      x = (-pi/4 .. pi/4), 2^(-113), even_terms)$
precision 40; r;
off rounded;

% The calculations do not need to be performed in rounded mode...
% and by default the range concerned will be -1 .. 1

economise_series(1 - x^3/factorial 4 + x^5/factorial 5 - x^7/factorial 7,
                 x, 3);

economise_series(taylor((sin x - x)/x^3, x, 0, 15),
                      x = (-pi/4 .. pi/4), 5, even_terms);

% You could even do a totally general case! But then you need to specify
% the desired degree of the result since there is no basis for guessing
% numerical accuracy.

economise_series(a0 + a1*x + a2*x^2 + a3*x^3 + a4*x^4 + a5*x^5,
                 x = (u .. v), 4);

on rounded;

% Now I will find a rational function that interpolates to approximate
% exp x taking exact values at around 20 points across the range 0 ..
% log 2, which should be a range where the value runs from 1 to 2.

precision 40;

multipoint_pade(exp, 0, log 2, 1.0e-35);

% Now similarly for log(1+x)/x

procedure ll x; if x = 0 then 1 else log(1+x)/x;
r := multipoint_pade(ll, 1/1.03125-1, 1.03125-1, 1.0e-35);

% I now illutrate display of the output in the form of hexadecimal
% double precision floats and "double-double".

prinhexlitlist first r;
prinhexlitlist2 second r;


end;
