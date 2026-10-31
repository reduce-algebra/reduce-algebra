% function analysis

f:=3*x^3-7*x^2;
fp:=df (f, x);
fpp:=df (fp, x);

% zeroes
solve (f, x);
% extremes
solve (fp, x);
% reversal points
solve (fpp, x);

% integration of 2nd derivative
f1:=int (fpp, x);
% integration of 1st derivative
f0:=int (f1, x);
f0:=int (fp, x);

end;
