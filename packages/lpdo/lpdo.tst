% Test only multipliation:
easy1 := (x1+1*x2)*(x1-1*x2);
easy2 := (a()*partial(x1)+b())*(c()*partial(x1)+d());

% Domain for the next factorizations:
lpdoset lpdoweyl(1,x1,x2);

% Not really binomial but caused problems at some point:
b3 := (a-partial(x1))*(a+partial(x1));
lpdofactorize b3;

% Differential binomial formulas:
bin1 := (a()+partial(x1))*(a()+partial(x1));
lpdofactorize bin1;
bin2 := (a()-partial(x1))*(a()-partial(x1));
lpdofactorize bin2;
bin3 := (a()-partial(x1))*(a()+partial(x1));
lpdofactorize bin3;

% Beals-Kartashova 2005, Section 5.3, special case
bkf := (partial(x1)+partial(x2)+(a10-a01)/2) *
   (partial(x1)-partial(x2)+(a10+a01)/2);
lpdofactorize bkf;

% Ad hoc example:
sth := (partial(x1)+partial(x2)+(a10+a01)) *
   (partial(x1)-partial(x2)+(a10+a01));
lpdofactorize sth;

% Blumberg 1912:
p := partial(x1)+x1*partial(x2);
q := partial(x1)+1;
r := partial(x1)^2+x1*partial(x1)*partial(x2)+partial(x1)+
   (2+x1)*partial(x2);
d := partial(x1)^3+x1*partial(x1)^2*partial(x2)+2*partial(x1)^2+
   2*(x1+1)*partial(x1)*partial(x2)+(x1+2)*partial(x2)+partial(x1);
d - q*q*p;
d - r*q;
lpdofactorize(d,a()*partial(x1)+b());

end;
