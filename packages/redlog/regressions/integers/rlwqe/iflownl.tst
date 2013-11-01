% Information Flow Control, Nonlinear Variant

rlset z;

phi := ex(n,
   (a < b and cong(a+b,0,2) and 2*n = a+b and
      ((a<b and b-a=n^2) or (a >= b and a-b = n^2))) or
   (a < b and ncong(a+b,0,2) and 2*n = a+b+1 and
      ((a < b and b-a = n^2) or (a >= b and a-b = n^2))))$

rlwqe phi;

end;
