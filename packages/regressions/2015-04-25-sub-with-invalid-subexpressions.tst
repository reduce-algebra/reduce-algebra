
y := x^2*e^(1/x^2);

sub(x=0,y);

z := exp(2*x)/x^2;

limit(z,x,infinity);

end;
