% function analysis
% Function f (x) is defined ?
if (freeof(f,x)) then << write "first define function f(x)"; end; >>

fp:=df (f, x);
fpp:=df (fp, x);

% zeroes
xz:=solve (f, x);

% extremes
xe:=solve (fp, x);

% reversal points
xr:=solve (fpp, x);

% extreme values
x1:=first (xe);
y1:=sub (x1, f);
y2:=sub (x1, fpp);

on rounded;

if numberp(y2) then
if y2<0 then write "local maximum" else
if y2=0 then write "reversal point"
else write "local minimum";

off rounded;

% integration of 2nd derivative
f1:=int (fpp, x);
% integration of 1st derivative
f0:=int (f1, x);
f0:=int (fp, x);

end;
