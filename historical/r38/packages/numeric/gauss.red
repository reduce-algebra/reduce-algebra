module gauss;  % Solve linear system.

% Author: H. Melenk, ZIB, Berlin

% Copyright (c): ZIB Berlin 1994, all rights resrved

fluid '(!*noequiv accuracy!* !*exptexpand);
global '(iterations!* !*trnumeric erfg!*);

put('igetv,'setqfn,'(lambda (v i x) (iputv v i x)));

smacro procedure s(i,j); igetv(igetv(m,i),j);

symbolic procedure rdsolvelin (u,b);
     % U is a n*n matrix with numbers;
     % b is a righthand side. Result is a vector of solutions.
     % Gaussian elimination with partial pivoting.
  begin integer n,n1,k; scalar m,w,r,x,y,err;
    n:=length b; n1:=n#+1;
      % establish system matrix.
    m:=mkvect(n#+1); r:=mkvect(n#+1);
    for i:=1:n do 
    <<w:=mkvect(n#+2);
      for j:=1:n do iputv(w,j,nth(nth(u,i),j));
      iputv(w,n1,nth(b,i));
      iputv(m,i,w);
    >>;
      % elimination loop.
    for i:=1:n-1 do if not err then
    << % pivot search
      x:=dm!: abs s(i,i); k:=i;
      for j:=i+1:n do dm!:
      dm!: if (y:=abs s(j,i))>x then <<x:=y; k:=j>>;
      if i neq k then 
      <<y:=igetv(m,i); iputv(m,i,igetv(m,k)); iputv(m,k,y)>>;
        % row elimination
      if null s(i,i) then err:=t 
      else
      <<x:=dm!: (1/s(i,i));
        for j:=i+1:n do
        <<y:=dm!:(s(j,i)*x);
          for k:=i:n1 do s(j,k):=dm!:(s(j,k) - y*s(i,k));
      >>>>;
     >>;

      % backsubstitution.
     for i:=n step -1 until 1 do if not err then
     <<w:=s(i,n1);
       for j:=i#+1 : n do
        dm!:(w:=w-s(i,j)*igetv(r,j));
       if null s(i,i) then err :=t else
         iputv(r,i,dm!:(w/s(i,i)));
     >>;

     return if err then nil else for i:=1:n collect igetv(r,i);
   end;

remprop('s,'smacro);
remprop('s,'number!-of!-args);

endmodule;

end;
