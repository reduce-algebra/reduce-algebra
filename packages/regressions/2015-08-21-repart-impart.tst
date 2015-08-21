
% Testing repart/impart

repart exp x;

repart(5^x);

repart(i^i);
impart((-1)^i);

{repart sqrt(3+4i), impart sqrt(3+4i)};
{repart sqrt(3+2i), impart sqrt(3+2i)};

{repart((2+i)^(3+i)), impart((2+i)^(3+i))};
{repart((-2+i)^(3+i)), impart((-2+i)^(3+i))};

realvalued u,v;
z:={repart((u+i*v)^(1/3)), impart((u+i*v)^(1/3))}$
z where u=>-8, v=>0;
{repart((-8)^(1/3)), impart((-8)^(1/3))};

impart(log(5));

repart sinh x;
impart sinh x;
repart cosh x;
impart cosh x;

repart tanh(u+i*v);
impart tan(u+i*v);
repart asech(2+i);
impart acsc(3+4i);

repart asin(u+i*v);
impart atanh(u+i*v);

{repart asinh(2+3i), impart asinh(2+3i)};
{repart acosh(1/2), impart acosh(1/2), repart acosh(-1/2), impart acosh(-1/2)};
{repart atanh(2), impart atanh(2)};
{repart atan(3+4i), impart atan(3+4i)};

end;


