% Tests of work over GF(2)

load_package gf2;

on echo;
lisp if !*csl then force!-output!-radix 16
else if 'psl memq lispsystem!* then outputbase!* := 16
else if 'common!-lisp memq lispsystem!* then !*print!-base!* := 16$
% FJW: *psl is currently true in REDUCE on Common Lisp so that readch1
% works correctly, therefore it is safest to avoid it in tests like
% that above!

operator vv;
gf2_vars {x, y, z};
d := prefix_to_gf2 (x^2*y + y^2 + z);
%   ( ((0 . 3) (1 . 2) (2 . 1))
%     ((0 . 2) (2 . 2))
%     ((0 . 1) (3 . 1)) )

gf2_to_prefix d;

off gf2_sparse;

% For this test I will set the width of each field to just 4 bits. This
% then uses just one hex digit per exponent.
lisp (gf2_degree_bits := 3);

gf2_vars {x, y, z};
d := prefix_to_gf2 (x^2*y + y^2 + z);
%   ( 0x003002001000  0x002000002000 0x001000000001)
%       tot  x  y  z    tot  x  y  z   tot  x  y  z
% Except that here it will be (0x3210 0x2020 0x1001) because of the
% narrow fields.

gf2_to_prefix d;

on gf2_sparse;

% I (ACN) do not know any really sensible examples to try here, so here
% are some starting points and maybe somebody who knows what they are doing
% can replace these with something better.

gf2_vars {x, y};
gf2_groeb{x^2 + y,
          x^3 + x};

gf2_vars {p, s, b, z, t, w};

gf2_groeb{p + s + b,
          p + t + s,
          w + p*s + b**2,
          w + p*t,
          w*p + *b**3,
          w + b*s + b**2};

end;
