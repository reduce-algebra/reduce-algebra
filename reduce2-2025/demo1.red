(begin)

% Legendre Polynomials

procedure factorial n;
  for i := 1:n product i;

for k := 0:10 do
  write df((x^2-1)^k, x, k)/2^k/factorial k;

end;
