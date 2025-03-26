
COMMENT

   https://sourceforge.net/p/reduce-algebra/bugs/177/
   
   A strange case a polynomial simplication that returns a denominator
      when an asymptotic rule is in effect;

P := (a^3 -
a^2*d +
a*d^2 -
d^3)/a^4;
Q := -d^4/a^5;

P-Q;

% The following returned 1/(a+d)

let d^5=>0;
P-Q;

end;