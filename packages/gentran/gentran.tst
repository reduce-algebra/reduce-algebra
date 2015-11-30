matrix m(3,3)$
m(1,1) := 18*cos(q3)*cos(q2)*m30*p**2 - 9*sin(q3)**2*p**2*m30
	  - sin(q3)**2*j30y + sin(q3)**2*j30z + p**2*m10
	  + 18*p**2*m30 + j10y + j30y;
m(2,1) :=
m(1,2) := 9*cos(q3)*cos(q2)*m30*p**2 - sin(q3)**2*j30y +
	  sin(q3)**2*j30z - 9*sin(q3)**2*m30*p**2 + j30y +
	  9*m30*p**2;
m(3,1) :=
m(1,3) := -9*sin(q3)*sin(q2)*m30*p**2;
m(2,2) := -sin(q3)**2*j30y + sin(q3)**2*j30z - 9*sin(q3)**2
	   *m30*p**2 + j30y + 9*m30*p**2;
m(3,2) :=
m(2,3) := 0;
m(3,3) := 9*m30*p**2 + j30x;

gentranlang!* := 'fortran$
fortlinelen!* := 72$

gentran literal "C", cr!*,
		"C", tab!*, "*** COMPUTE VALUES FOR MATRIX M ***", cr!*,
		"C", cr!*$

for j:=1:3 do
    for k:=j:3 do
	 gentran m(j,k) ::=: m(j,k)$

gentran literal "C", cr!*,
		"C", tab!*, "*** COMPUTE VALUES FOR INVERSE MATRIX ***",
		     cr!*,
		"C", cr!*$

share var$
for j:=1:3 do
    for k:=j:3 do
	if m(j,k) neq 0 then
	<<
	    var := tempvar nil;
	    markvar var;
	    m(j,k) := var;
	    m(k,j) := var;
	    gentran
		eval(var) := m(eval(j),eval(k))
        >>$

COMMENT -- Contents of Matrix M: --$
m := m;

matrix mxinv(3,3)$
mxinv := m**(-1)$

for j:=1:3 do
    for k:=j:3 do
	gentran mxinv(j,k) ::=: mxinv(j,k)$

gentran
   for j:=1:3 do
       for k:=j+1:3 do
       <<
	   m(k,j) := m(j,k);
	   mxinv(k,j) := mxinv(j,k)
        >>$

end$
