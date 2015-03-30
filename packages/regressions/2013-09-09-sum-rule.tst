%
% error in sum operator, reported by Petrov Alexander
%
 
operator h,k,x;
h := sum( (1/2)*k(i)*x(i)**2, i, -infinity,infinity);
r1 := {df(sum( ~f, ~i, ~i1,~i2),~x) => sum( df(f, x),i,i1,i2)};
(df(h,x(i)) where r1);

end;
