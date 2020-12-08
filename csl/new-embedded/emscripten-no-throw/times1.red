on echo;
on time;

lisp;

a := 1;

k:=13^1200;
m := 3^3000;

for i := 1:70000 do
   a := remainder(a*k, m);

end;
