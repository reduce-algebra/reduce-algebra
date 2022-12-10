% The economise_series operator takes a power-series representation of
% a function over some (finite) interval and attempts to generate a lower
% degree polynomial that will give an accurate approximation to it.
% It achieves this by succesively eliminating the highest degree term in
% the series using a Chebyshev polynomial. The Chebyshev polynomial that
% is subtracted will lead to a good approximation to a minimax overall
% approximation.


% The next two cases generate coefficients suitable for computing sine
% and cosine in the range -pi/4 to +pi/4 such that the result will
% be accurate enough for IEEE-style 128-bit floating point.

% $Id$

on rounded; precision 100;
r := economise_series(taylor((sin x - x)/x^3, x, 0, 60),
                      x = (-pi/4 .. pi/4), 20, even_terms)$
precision 40; r;

precision 100;
r := economise_series(taylor((cos x - 1)/x^2, x, 0, 60),
                      x = (-pi/4 .. pi/4), 20, even_terms)$
precision 40; r;
off rounded;

% The calculations do nnot need to be performed in rounded mode...
% and by default the range concerned will be -1 .. 1

economise_series(1 - x^3/factorial 4 + x^5/factorial 5 - x^7/factorial 7,
                 x, 3);

economise_series(taylor((sin x - x)/x^3, x, 0, 15),
                      x = (-pi/4 .. pi/4), 5, even_terms);

end;
