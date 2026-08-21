on rounded, time;

a := 0.5$
b := 0.5$

% Next 11 results checked to 6 sf against Mathematica using
% https://functions.wolfram.com/webMathematica/Evaluated.jsp?name=BetaRegularized
for i := 0 : 10 do write ibeta(a, b, 0.1*i) := ibeta(a, b, 0.1*i);

for i := 1 : 10 do
   begin scalar x := 1.0 - 10.0^(-i);
      write ibeta(a, b, x) := ibeta(a, b, x);
   end;

a := 0.25$
b := 0.75$

% Next 11 results checked to 6 sf against Mathematica using
% https://functions.wolfram.com/webMathematica/Evaluated.jsp?name=BetaRegularized
for i := 0 : 10 do write ibeta(a, b, 0.1*i) := ibeta(a, b, 0.1*i);

for i := 1 : 10 do
   begin scalar x := 1.0 - 10.0^(-i);
      write ibeta(a, b, x) := ibeta(a, b, x);
   end;

% The following values should all be 1:
for i := 0 : 10 collect
   ibeta(a, b, 0.1*i) + ibeta(b, a, 1.0-0.1*i);

end;
