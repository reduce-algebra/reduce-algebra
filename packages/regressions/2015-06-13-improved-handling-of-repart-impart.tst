
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
repart(log(-5));
repart(log(x));
repart(log(y));
off precise;
repart(log(5));
repart(log(-5));
repart(log(x));
repart(log(y));

end;
