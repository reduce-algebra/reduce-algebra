%%
%% Regression test files for improved trigonometric simplication
%%
% new rules for atan2
{atan2(1,0), atan2(-1,0), atan2(0, 1), atan2(0, -1)};
{atan2(1,1), atan2(1,-1), atan2(-1, 1), atan2(-1, -1)};

{atan2(i, 0), atan2(-2i, 0), atan2(0, 2+i), atan2(0, -3+i)};
r1:={atan2(2+i, 3+5i),atan2(-2-i, 3+5i),atan2(-2+i, 3+5i),atan2(-2+i, -3-5i)}; 

on complex, rounded;
r1;
{atan2(2+i, 3+5i), atan2(-2-i, 3+5i), atan2(-2+i, 3+5i), atan2(-2+i, -3-5i)}; 
off complex, rounded;

realvalued x,y;
atan2(y^2, -x^2);  

atan2(x^2, 2i*x^2);

% so re/impart of log useful 
{repart log(x+i*y), impart log(x+i*y)};
{repart log(x^2+i*y^2), impart log(x^2+i*y^2)};
{repart log(-1), impart log(-1)};
{repart log(i), impart log i, impart log(-i)};
{repart log(1+i), impart log(1+i), repart log(-1-i), impart log(-1-i)};

% new rules involving atan
r1:= sin(atan x/2);
r2:= cos(atan x/2);
r1^2+r2^2;

sin(atan(4/3)/2);
cos(atan(4/3)/2);

end;

