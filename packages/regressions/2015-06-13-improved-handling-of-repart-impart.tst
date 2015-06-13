
repart(log(5));
impart(log(5));

log(2+3i);
repart(log(2+3i));
impart(log(2+3i));
% This used to return incorrect value 0
on complex;
impart(log(2+3i));

off complex;

realvalued y;

repart(log(5));
impart(log(5));
repart(log(-5));
impart(log(-5));
repart(log(5i));
impart(log(5i));
repart(log(-5i));
impart(log(-5i));
repart(log(x));
impart(log(x));
repart(log(i*x));
impart(log(i*x));
repart(log(y));
impart(log(y));
repart(log(i*y));
impart(log(i*y));
off precise;
repart(log(5));
impart(log(5));
repart(log(-5));
impart(log(-5));
repart(log(5i));
impart(log(5i));
repart(log(-5i));
impart(log(-5i));
repart(log(x));
impart(log(x));
repart(log(i*x));
impart(log(i*x));
repart(log(y));
impart(log(y));
repart(log(i*y));
impart(log(i*y));

on rational;

repart log(-3/2);
repart log (-3*i/2);

off rational;

repart(log10(-5));
impart(log10(-5));

repart(logb(-5,6));
impart(logb(-5,6));

on rounded;

repart(log10(-5));
impart(log10(-5));

repart(logb(-5,6));
impart(logb(-5,6));

end;
