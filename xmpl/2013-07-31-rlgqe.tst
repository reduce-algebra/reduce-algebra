% When using fallback QE with rlgqe the generic variant of ofsf_cad is is used.
% However, the code did not care about theories for fallback QE at all, which
% became apparent with this example.

rlset r;

phi := all(x, ex(y, x^2 + x*y + b > 0 and x + a*y^2 + b <= 0));

rlgqe phi;

end;
