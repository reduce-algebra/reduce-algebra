on div;
r1:=a*int(exp(-a*t)-exp(-a*(r+y)),y,t-r,t);
r2:=a*int(exp(-a*t),y,t-r,t)-a*int(exp(-a*(r+y)),y,t-r,t);
if r1 neq r2 then write "failed";

r1:=a*int(exp(-a*z),z,t,y+x);
r2:=a*int(r1,y,t-x,t);
r3:=a*exp(-a*t)*int(1,y,t-x,t)-a*exp(-a*x)*int(exp(-a*y),y,t-x,t);
if r2 neq r3 then write "failed";

r1:=a*int(exp(-a*x),x,0,s-y);
r2:=a*int(r1*exp(-a*y),y,0,s);
r3:=1-(1+a*s)*exp(-a*s);
if r2 neq r3 then write "failed";

r1:=a*int(exp(-a*x),x,0,s-y);
r2:= a*int(r1*exp(-a*y),y,0,s);
r1*exp(-a*y);
r3:= a*int(ws,y,0,s);
if r2 neq r3 then write "failed";

end;
