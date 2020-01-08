
% Test file for bug #115: integrator fails with combineexpt on.
%  https://sourceforge.net/p/reduce-algebra/bugs/115/

int(sqrt(x^2+9)/x^4,x);

int(sqrt(x^2+9)/x^4,x,1,2);

on combineexpt;

int(sqrt(x^2+9)/x^4,x);

int(sqrt(x^2+9)/x^4,x,1,2);

end;
