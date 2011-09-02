module interpol; % polynomial interpolation (Aitken & Neville).
 
% Author: Herbert Melenk <melenk@sc.zib-berlin.de>.

symbolic procedure interpol(fc,x,pts);
   % find a polynomial f(x) such that holds:
   %   f(part(pts,i)) = part(fc,i)  for all i <= lenth pts.
   % The Aitken-Neville schema is used; it is stable for
   % symbolic and numeric values.
 begin scalar d,q,s,p1,p2,x1,x2,f1,f2,fnew;
    if not eqcar(fc,'list) or not eqcar(pts,'list) 
       or not(length fc=length pts)
      then rerror(poly,19,"Illegal parameters for interpol");
   s:=for each p in pair(cdr fc,cdr pts) collect
       simp car p . simp cdr p . simp cdr p;
   x:= simp x;
       % outer loop as long as there is more than 1 element.
   while cdr s do
   <<q:= nil;
       % inner loop for all adjacent pairs of polynomials.
     while cdr s do
     <<p1:=car s; s:=cdr s; p2:=car s;
       f1:=car p1; f2:=car p2; x1:=cadr p1; x2:=cddr p2;
       d:=subtrsq(x1,x2);
       if null numr d then rerror(poly,20,
	 "Interpolation impossible if two points are equal");
       fnew:=
         quotsq(
          subtrsq(multsq(subtrsq(x,x2),f1),
                  multsq(subtrsq(x,x1),f2)),
          d);
       q:=(fnew.x1.x2).q;
     >>;
      s:=reversip q;
   >>;
   return prepsq caar s;
 end;

% We can't do following for bootstrapping reasons.

% symbolic operator interpol;

flag('(interpol),'opfn);

endmodule;

end;
