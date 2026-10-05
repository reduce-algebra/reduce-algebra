on time;

% Exact polynomial values for a,b positive integers:

for a := 1:5 do for b := 1:5 do write ibeta(a,b,x) := ibeta(a,b,x);



% All numerical results agree to 12 digits with Mathematica using
% https://functions.wolfram.com/GammaBetaErf/BetaRegularized/ except
% that Mathematica gives ibeta(0.5, 0.5, 0.99999999) = 0.999936338022
% which differs by 1 in the last decimal place.

% In Mathematica, the domain appears to be the whole complex plane!

on rounded;

a := 0.5$
b := 0.5$

for i := 0 : 10 do write ibeta(a, b, 0.1*i) := ibeta(a, b, 0.1*i);

for i := 1 : 10 do
   begin scalar x := 1.0 - 10.0^(-i);
      write ibeta(a, b, x) := ibeta(a, b, x);
   end;

a := 0.25$
b := 0.75$

for i := 0 : 10 do write ibeta(a, b, 0.1*i) := ibeta(a, b, 0.1*i);

for i := 1 : 10 do
   begin scalar x := 1.0 - 10.0^(-i);
      write ibeta(a, b, x) := ibeta(a, b, x);
   end;

% The following values should all be 1:
for i := 0 : 10 collect
   ibeta(a, b, 0.1*i) + ibeta(b, a, 1.0-0.1*i);



% ibeta(a,b,x) with x real but outside the range 0 <= x <= 1, for
% which some results are complex.

% Not necessary, but makes complex numbers display better:
on complex;

ibeta(1, 1, 2);
ibeta(1, 1, 3);
ibeta(2, 1, 2);
ibeta(2, 1, 3);
ibeta(1, 2, 2);
ibeta(1, 2, 3);
ibeta(0.5, 1, 2);
ibeta(0.5, 1, 3);
ibeta(1, 0.5, 2);
ibeta(1, 0.5, 3);

a := 0.5$
b := 0.5$

for i := -5 : 5 do write ibeta(a, b, i) := ibeta(a, b, i);

end;
