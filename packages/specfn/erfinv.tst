load_package specfn;

erf(-x);
erf(0);
erfinv 1;
erfinv(-1);
erfinv erf x;
erf erfinv x;
solve(erf x = y, x);
solve(erfinv x = y, x);

on rounded;

erf(1.0);
erfinv(ws);

erf(-1.0);
erfinv(ws);

for i := 0 : 9 do
   begin scalar x := 0.1*i, y := erfinv x;
      write "erfinv ", x, " = ", y, " : ",
         if erf y = x then "accurate" else "inaccurate"
   end;

for i := 2 : 12 do
   begin scalar x := 1.0 - 0.1^i, y := erfinv x;
      write "erfinv ", x, " = ", y, " : ",
         if erf y = x then "accurate" else "inaccurate"
   end;

;end;
