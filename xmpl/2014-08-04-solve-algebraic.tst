% Several test cases for algebraic solver


% Single Solution: x=arbcomplex(1), y=0
solve(e^x*y,{x,y});


% Solution 1: x=arbcomplex(1), y=0
% Solution 2: x=pi*arbint(1), y=arbcomplex(2)

solve(sin(x)*y,{x,y});


% Solution 1: x=arbcomplex(1), y=0
% Solution 2: x=1, y=arbcomplex(2)

solve(y*log x,{x,y});


% Solution 1: x=arbcomplex(1), y=0
% Solution 2: x=sqrt(2*pi*i*arbint(1)), y=arbcomplex(1)

solve(y*(e^(x^2)-1));


% Border case: solve returns same roots twice:

solve(cos x + 1);

end;
