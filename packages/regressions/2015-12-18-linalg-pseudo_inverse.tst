load linalg;

A := mat((1,2,3),(4,5,6),(7,8,9))$

B:= pseudo_inverse(A);

on rounded;

B;

A*B*A;

B*A*B;

end;
