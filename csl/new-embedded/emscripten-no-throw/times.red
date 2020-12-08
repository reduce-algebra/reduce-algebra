on echo;
on time;

lisp;

a := 1;

k:=13^80;
m := 3^200;

for i := 1:1000000 do
   a := remainder(a*k, m);

end;
