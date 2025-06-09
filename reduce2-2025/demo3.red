(begin)

% Generate the power series for tan(x)

array tan(14);
tan(0) := 0;
tan(1) := 1;
for i := 2:15 do
   write tan(i) := (for j:=0:i-1 sum (tan(j)*tan(i-j-1)))/i;

end;