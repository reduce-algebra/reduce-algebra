% This used to be buglist/bug39

% Trying to access a matrix element beyong the end of the matrix
% resulted in an error message from the underlying lisp fucntions
% nth or pnth.
% Error messages differ between systems, better generate the error
% at the Reduce level.

matrix m(10,10);

for i:=1:10 do for j:=1:10 do m(i,j) := random(10^50);

m(11,11);

m(11,11) := 5;

% The sparse package didn't check for the row and column indices
% being positive integers.

sparse mm(10,10);

for i:=1:10 do for j:=1:10 do mm(i,j) := random(10^50);

mm(11,11);

mm(11,11) := 5;

% Invalid row or column index:
mm(0,10);
mm(-1,10);
mm(0,0);
mm(10,0);
mm(-1,0);

mm(0,10) := 5;
mm(-1,10) := 5;
mm(0,0) := 5;
mm(10,0) := 5;
mm(-1,0) := 5;

end;
