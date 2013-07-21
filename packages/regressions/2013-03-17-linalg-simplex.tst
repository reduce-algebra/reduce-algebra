load_package linalg;

hu := {
   - n2 <= -1,
   - n1 - n2 <= 0,
   2*n1 + n2 <= 0,
   5*n1 + 2*n2 <= 0,
   5*n1 - n2 <= 0}$

simplex(min, 0, hu);
simplex(max, n1, hu);

end;
