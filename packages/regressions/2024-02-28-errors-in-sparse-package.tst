%
% Printing errors
%

sparse emptymat(2,2);

m := emptymat;

sparse mymat(2,2);
mymat(1,1) := -3;
mymat(1,2) := 5;
mymat(2,1) := 6;

l := {mymat};

sparse aa;

lisp getrtype 'aa;

%This was previously resetting the rtype to matrix
aa;

% so that this used to return matrix
lisp getrtype 'aa;

% This caused a segfault
aa(1,2):=-1;

sparse aa(2,2);

aa(1,1) := 2; aa(2,2) :=4;

aa;

on fort;
aa;
off fort;

%
% Handling errors
%

spsvd(emptymat);

mat01 := mat((12,1,0,0,0),
   (1,9,1,0,0),
   (0,1,6,1,0),
   (0,0,1,3,1),
   (0,0,0,1,0));

spmat01 := mat01$ transmat spmat01$

spsvd01 := spsvd(spmat01);

diag2 := second(spsvd01);

det(diag2);

det(second(spsvd01));

end;

