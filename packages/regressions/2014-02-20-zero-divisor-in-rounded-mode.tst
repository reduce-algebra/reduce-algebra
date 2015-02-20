
on rounded;

f:=pv+pmt*(1+s*r)*(1-(1+r)^-n)/r+fv*(1+r)^-n;

n:=240;
pv:=56000;
pmt:=-440;
fv:=0;
s:=0;

df(f,r);

end;
