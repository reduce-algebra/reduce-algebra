(begin)

a := (3*x^2 + 2*x - 1);
b := (x^3 - 7*x + 2);
g := (x^2 + 3*x - 11);

p := a*g;
q := b*g;

% By default Reduce does not reduce rational functions to
% lowest terms.

p/q;

% However if !*gcd is set on it will - but for larger examples
% this will be very slow.

lisp (!*gcd := t);

p/q;

end;
