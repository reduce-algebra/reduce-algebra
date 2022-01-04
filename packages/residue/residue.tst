% test file for residue package

residue(x/(x^2-2),x,sqrt(2));
poleorder(x/(x^2-2),x,sqrt(2));
residue(sin(x)/(x^2-2),x,sqrt(2));
poleorder(sin(x)/(x^2-2),x,sqrt(2));
residue(1/(x-1)^m/(x-2)^2,x,2);
poleorder(1/(x-1)/(x-2)^2,x,2);
residue(sin(x)/x^2,x,0);
poleorder(sin(x)/x^2,x,0);
residue((1+x^2)/(1-x^2),x,1);
poleorder((1+x^2)/(1-x^2),x,1);
residue((1+x^2)/(1-x^2),x,-1);
poleorder((1+x^2)/(1-x^2),x,-1);
residue(tan(x),x,pi/2);
poleorder(tan(x),x,pi/2);
residue((x^n-y^n)/(x-y),x,y);
poleorder((x^n-y^n)/(x-y),x,y);
residue((x^n-y^n)/(x-y)^2,x,y);
poleorder((x^n-y^n)/(x-y)^2,x,y);
residue(tan(x)/sec(x-pi/2)+1/cos(x),x,pi/2);
poleorder(tan(x)/sec(x-pi/2)+1/cos(x),x,pi/2);
for k:=1:2 sum residue((a+b*x+c*x^2)/(d+e*x+f*x^2),x,
    part(part(solve(d+e*x+f*x^2,x),k),2));
residue(sin(x)/x^6,x,0);
residue((1-cos(x))/x^5,x,0);
residue(exp(1/x),x,0);
% not implemented
residue((a*x+b*x^2+c)/(d*x+e),x,-e/d);
residue(tan(x),x,pi/2);
residue(sec(x),x,pi/2);
residue(gamma(x),x,-1);
residue(psi(x),x,-1);
residue(factorial(x),x,0);
% ***** not yet implemented 
residue(x^3/sin(1/x)^2,x,infinity);
poleorder(x^3/sin(1/x)^2,x,infinity);
residue(x^3*sin(1/x)^2,x,infinity);
poleorder(x^3*sin(1/x)^2,x,infinity);
on fullroots;
for k:=1:3 sum 
 residue((a+b*x+c*x^2+d*x^3)/(e+f*x+g*x^2+h*x^3),x, 
 part(part(solve(e+f*x+g*x^2+h*x^3,x),k),2)); 
end;
