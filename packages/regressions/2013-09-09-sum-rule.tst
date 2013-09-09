%
% error in sum operator, reported by Petrov Alexander
%
 
operator H,k,x;
H := sum( (1/2)*k(i)*x(i)**2, i, -infinity,infinity);
r1 := {df(sum( ~f, ~i, ~i1,~i2),~x) => sum( df(f, x),i,i1,i2)};
(df(H,x(i)) where r1);

end;
