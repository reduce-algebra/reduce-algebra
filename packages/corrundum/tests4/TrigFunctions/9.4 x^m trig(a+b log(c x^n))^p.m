(* ::Package:: *)

(* ::Title:: *)
(*Problems for integrands of the form x^m trig(a+b log(c x^n))^p*)


(* ::Section::Closed:: *)
(*Integrands of the form x^m Sin[a+b Log[c x^n]]^p*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{x^m*Sin[a + b*Log[c*x^n]], x, 1, -((b*n*x^(1 + m)*Cos[a + b*Log[c*x^n]])/((1 + m)^2 + b^2*n^2)) + ((1 + m)*x^(1 + m)*Sin[a + b*Log[c*x^n]])/((1 + m)^2 + b^2*n^2)}

{x^2*Sin[a + b*Log[c*x^n]], x, 1, -((b*n*x^3*Cos[a + b*Log[c*x^n]])/(9 + b^2*n^2)) + (3*x^3*Sin[a + b*Log[c*x^n]])/(9 + b^2*n^2)}
{x^1*Sin[a + b*Log[c*x^n]], x, 1, -((b*n*x^2*Cos[a + b*Log[c*x^n]])/(4 + b^2*n^2)) + (2*x^2*Sin[a + b*Log[c*x^n]])/(4 + b^2*n^2)}
{x^0*Sin[a + b*Log[c*x^n]], x, 1, -((b*n*x*Cos[a + b*Log[c*x^n]])/(1 + b^2*n^2)) + (x*Sin[a + b*Log[c*x^n]])/(1 + b^2*n^2)}
{Sin[a + b*Log[c*x^n]]/x^1, x, 2, -(Cos[a + b*Log[c*x^n]]/(b*n))}
{Sin[a + b*Log[c*x^n]]/x^2, x, 1, -((b*n*Cos[a + b*Log[c*x^n]])/((1 + b^2*n^2)*x)) - Sin[a + b*Log[c*x^n]]/((1 + b^2*n^2)*x)}
{Sin[a + b*Log[c*x^n]]/x^3, x, 1, -((b*n*Cos[a + b*Log[c*x^n]])/((4 + b^2*n^2)*x^2)) - (2*Sin[a + b*Log[c*x^n]])/((4 + b^2*n^2)*x^2)}


{x^m*Sin[a + b*Log[c*x^n]]^2, x, 2, (2*b^2*n^2*x^(1 + m))/((1 + m)*((1 + m)^2 + 4*b^2*n^2)) - (2*b*n*x^(1 + m)*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/((1 + m)^2 + 4*b^2*n^2) + ((1 + m)*x^(1 + m)*Sin[a + b*Log[c*x^n]]^2)/((1 + m)^2 + 4*b^2*n^2)}

{x^2*Sin[a + b*Log[c*x^n]]^2, x, 2, (2*b^2*n^2*x^3)/(3*(9 + 4*b^2*n^2)) - (2*b*n*x^3*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/(9 + 4*b^2*n^2) + (3*x^3*Sin[a + b*Log[c*x^n]]^2)/(9 + 4*b^2*n^2)}
{x^1*Sin[a + b*Log[c*x^n]]^2, x, 2, (b^2*n^2*x^2)/(4*(1 + b^2*n^2)) - (b*n*x^2*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/(2*(1 + b^2*n^2)) + (x^2*Sin[a + b*Log[c*x^n]]^2)/(2*(1 + b^2*n^2))}
{x^0*Sin[a + b*Log[c*x^n]]^2, x, 2, (2*b^2*n^2*x)/(1 + 4*b^2*n^2) - (2*b*n*x*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/(1 + 4*b^2*n^2) + (x*Sin[a + b*Log[c*x^n]]^2)/(1 + 4*b^2*n^2)}
{Sin[a + b*Log[c*x^n]]^2/x^1, x, 2, Log[c*x^n]/(2*n) - (Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/(2*b*n)}
{Sin[a + b*Log[c*x^n]]^2/x^2, x, 2, -((2*b^2*n^2)/((1 + 4*b^2*n^2)*x)) - (2*b*n*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/((1 + 4*b^2*n^2)*x) - Sin[a + b*Log[c*x^n]]^2/((1 + 4*b^2*n^2)*x)}
{Sin[a + b*Log[c*x^n]]^2/x^3, x, 2, -((b^2*n^2)/(4*(1 + b^2*n^2)*x^2)) - (b*n*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/(2*(1 + b^2*n^2)*x^2) - Sin[a + b*Log[c*x^n]]^2/(2*(1 + b^2*n^2)*x^2)}


{x^m*Sin[a + b*Log[c*x^n]]^3, x, 2, -((6*b^3*n^3*x^(1 + m)*Cos[a + b*Log[c*x^n]])/(((1 + m)^2 + b^2*n^2)*((1 + m)^2 + 9*b^2*n^2))) + (6*b^2*(1 + m)*n^2*x^(1 + m)*Sin[a + b*Log[c*x^n]])/(((1 + m)^2 + b^2*n^2)*((1 + m)^2 + 9*b^2*n^2)) - (3*b*n*x^(1 + m)*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]]^2)/((1 + m)^2 + 9*b^2*n^2) + ((1 + m)*x^(1 + m)*Sin[a + b*Log[c*x^n]]^3)/((1 + m)^2 + 9*b^2*n^2)}

{x^2*Sin[a + b*Log[c*x^n]]^3, x, 2, -((2*b^3*n^3*x^3*Cos[a + b*Log[c*x^n]])/(3*(9 + 10*b^2*n^2 + b^4*n^4))) + (2*b^2*n^2*x^3*Sin[a + b*Log[c*x^n]])/(9 + 10*b^2*n^2 + b^4*n^4) - (b*n*x^3*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]]^2)/(3*(1 + b^2*n^2)) + (x^3*Sin[a + b*Log[c*x^n]]^3)/(3*(1 + b^2*n^2))}
{x^1*Sin[a + b*Log[c*x^n]]^3, x, 2, -((6*b^3*n^3*x^2*Cos[a + b*Log[c*x^n]])/(16 + 40*b^2*n^2 + 9*b^4*n^4)) + (12*b^2*n^2*x^2*Sin[a + b*Log[c*x^n]])/(16 + 40*b^2*n^2 + 9*b^4*n^4) - (3*b*n*x^2*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]]^2)/(4 + 9*b^2*n^2) + (2*x^2*Sin[a + b*Log[c*x^n]]^3)/(4 + 9*b^2*n^2)}
{x^0*Sin[a + b*Log[c*x^n]]^3, x, 2, -((6*b^3*n^3*x*Cos[a + b*Log[c*x^n]])/(1 + 10*b^2*n^2 + 9*b^4*n^4)) + (6*b^2*n^2*x*Sin[a + b*Log[c*x^n]])/(1 + 10*b^2*n^2 + 9*b^4*n^4) - (3*b*n*x*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]]^2)/(1 + 9*b^2*n^2) + (x*Sin[a + b*Log[c*x^n]]^3)/(1 + 9*b^2*n^2)}
{Sin[a + b*Log[c*x^n]]^3/x^1, x, 3, -(Cos[a + b*Log[c*x^n]]/(b*n)) + Cos[a + b*Log[c*x^n]]^3/(3*b*n)}
{Sin[a + b*Log[c*x^n]]^3/x^2, x, 2, -((6*b^3*n^3*Cos[a + b*Log[c*x^n]])/((1 + 10*b^2*n^2 + 9*b^4*n^4)*x)) - (6*b^2*n^2*Sin[a + b*Log[c*x^n]])/((1 + 10*b^2*n^2 + 9*b^4*n^4)*x) - (3*b*n*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]]^2)/((1 + 9*b^2*n^2)*x) - Sin[a + b*Log[c*x^n]]^3/((1 + 9*b^2*n^2)*x)}
{Sin[a + b*Log[c*x^n]]^3/x^3, x, 2, -((6*b^3*n^3*Cos[a + b*Log[c*x^n]])/((16 + 40*b^2*n^2 + 9*b^4*n^4)*x^2)) - (12*b^2*n^2*Sin[a + b*Log[c*x^n]])/((16 + 40*b^2*n^2 + 9*b^4*n^4)*x^2) - (3*b*n*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]]^2)/((4 + 9*b^2*n^2)*x^2) - (2*Sin[a + b*Log[c*x^n]]^3)/((4 + 9*b^2*n^2)*x^2)}


{x^m*Sin[a + b*Log[c*x^n]]^4, x, 3, (24*b^4*n^4*x^(1 + m))/((1 + m)*((1 + m)^2 + 4*b^2*n^2)*((1 + m)^2 + 16*b^2*n^2)) - (24*b^3*n^3*x^(1 + m)*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/(((1 + m)^2 + 4*b^2*n^2)*((1 + m)^2 + 16*b^2*n^2)) + (12*b^2*(1 + m)*n^2*x^(1 + m)*Sin[a + b*Log[c*x^n]]^2)/(((1 + m)^2 + 4*b^2*n^2)*((1 + m)^2 + 16*b^2*n^2)) - (4*b*n*x^(1 + m)*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]]^3)/((1 + m)^2 + 16*b^2*n^2) + ((1 + m)*x^(1 + m)*Sin[a + b*Log[c*x^n]]^4)/((1 + m)^2 + 16*b^2*n^2)}

{x^2*Sin[a + b*Log[c*x^n]]^4, x, 3, (8*b^4*n^4*x^3)/(81 + 180*b^2*n^2 + 64*b^4*n^4) - (24*b^3*n^3*x^3*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/(81 + 180*b^2*n^2 + 64*b^4*n^4) + (36*b^2*n^2*x^3*Sin[a + b*Log[c*x^n]]^2)/(81 + 180*b^2*n^2 + 64*b^4*n^4) - (4*b*n*x^3*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]]^3)/(9 + 16*b^2*n^2) + (3*x^3*Sin[a + b*Log[c*x^n]]^4)/(9 + 16*b^2*n^2)}
{x^1*Sin[a + b*Log[c*x^n]]^4, x, 3, (3*b^4*n^4*x^2)/(4*(1 + 5*b^2*n^2 + 4*b^4*n^4)) - (3*b^3*n^3*x^2*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/(2*(1 + 5*b^2*n^2 + 4*b^4*n^4)) + (3*b^2*n^2*x^2*Sin[a + b*Log[c*x^n]]^2)/(2*(1 + 5*b^2*n^2 + 4*b^4*n^4)) - (b*n*x^2*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]]^3)/(1 + 4*b^2*n^2) + (x^2*Sin[a + b*Log[c*x^n]]^4)/(2*(1 + 4*b^2*n^2))}
{x^0*Sin[a + b*Log[c*x^n]]^4, x, 3, (24*b^4*n^4*x)/(1 + 20*b^2*n^2 + 64*b^4*n^4) - (24*b^3*n^3*x*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/(1 + 20*b^2*n^2 + 64*b^4*n^4) + (12*b^2*n^2*x*Sin[a + b*Log[c*x^n]]^2)/(1 + 20*b^2*n^2 + 64*b^4*n^4) - (4*b*n*x*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]]^3)/(1 + 16*b^2*n^2) + (x*Sin[a + b*Log[c*x^n]]^4)/(1 + 16*b^2*n^2)}
{Sin[a + b*Log[c*x^n]]^4/x^1, x, 3, (3*Log[c*x^n])/(8*n) - (3*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/(8*b*n) - (Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]]^3)/(4*b*n)}
{Sin[a + b*Log[c*x^n]]^4/x^2, x, 3, -((24*b^4*n^4)/((1 + 20*b^2*n^2 + 64*b^4*n^4)*x)) - (24*b^3*n^3*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/((1 + 20*b^2*n^2 + 64*b^4*n^4)*x) - (12*b^2*n^2*Sin[a + b*Log[c*x^n]]^2)/((1 + 20*b^2*n^2 + 64*b^4*n^4)*x) - (4*b*n*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]]^3)/((1 + 16*b^2*n^2)*x) - Sin[a + b*Log[c*x^n]]^4/((1 + 16*b^2*n^2)*x)}
{Sin[a + b*Log[c*x^n]]^4/x^3, x, 3, -((3*b^4*n^4)/(4*(1 + 5*b^2*n^2 + 4*b^4*n^4)*x^2)) - (3*b^3*n^3*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/(2*(1 + 5*b^2*n^2 + 4*b^4*n^4)*x^2) - (3*b^2*n^2*Sin[a + b*Log[c*x^n]]^2)/(2*(1 + 5*b^2*n^2 + 4*b^4*n^4)*x^2) - (b*n*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]]^3)/((1 + 4*b^2*n^2)*x^2) - Sin[a + b*Log[c*x^n]]^4/(2*(1 + 4*b^2*n^2)*x^2)}


{1/(x*(1 + Sin[Log[x]])), x, 2, -(Cos[Log[x]]/(1 + Sin[Log[x]]))}
{Sin[Log[a + b*x]], x, 2, -(((a + b*x)*Cos[Log[a + b*x]])/(2*b)) + ((a + b*x)*Sin[Log[a + b*x]])/(2*b)}


(* ::Subsubsection::Closed:: *)
(*p>0 when b^2 n^2 p^2+(m+1)^2=0*)


{x^m*Sin[a + Sqrt[-(m+1)^2/(1^2*n^2)]*Log[c*x^n]]^1, x, 7, (E^((a*(1 + m))/(Sqrt[-((1 + m)^2/n^2)]*n))*Sqrt[-((1 + m)^2/n^2)]*n*x^(1 + m)*(c*x^n)^((1 + m)/n))/(4*(1 + m)^2) + (E^((a*Sqrt[-((1 + m)^2/n^2)]*n)/(1 + m))*(1 + m)*x^(1 + m)*Log[x])/((c*x^n)^((1 + m)/n)*(2*Sqrt[-((1 + m)^2/n^2)]*n))}

{x^2*Sin[a + Sqrt[-(2+1)^2/(1^2*n^2)]*Log[c*x^n]]^1, x, 6, ((1/12)*Sqrt[-(1/n^2)]*n*x^3*(c*x^n)^(3/n))/E^(a*Sqrt[-(1/n^2)]*n) - ((1/2)*E^(a*Sqrt[-(1/n^2)]*n)*Sqrt[-(1/n^2)]*n*x^3*Log[x])/(c*x^n)^(3/n)}
{x^1*Sin[a + Sqrt[-(1+1)^2/(1^2*n^2)]*Log[c*x^n]]^1, x, 6, ((1/8)*Sqrt[-(1/n^2)]*n*x^2*(c*x^n)^(2/n))/E^(a*Sqrt[-(1/n^2)]*n) - ((1/2)*E^(a*Sqrt[-(1/n^2)]*n)*Sqrt[-(1/n^2)]*n*x^2*Log[x])/(c*x^n)^(2/n)}
{x^0*Sin[a + Sqrt[-(0+1)^2/(1^2*n^2)]*Log[c*x^n]]^1, x, 6, ((1/4)*Sqrt[-(1/n^2)]*n*x*(c*x^n)^(1/n))/E^(a*Sqrt[-(1/n^2)]*n) - ((1/2)*E^(a*Sqrt[-(1/n^2)]*n)*Sqrt[-(1/n^2)]*n*x*Log[x])/(c*x^n)^n^(-1)}
{Sin[a + Sqrt[-(-1+1)^2/(1^2*n^2)]*Log[c*x^n]]^1/x^1, x, 2, Log[x]*Sin[a]}
{Sin[a + Sqrt[-(-2+1)^2/(1^2*n^2)]*Log[c*x^n]]^1/x^2, x, 6, (E^(a*Sqrt[-(1/n^2)]*n)*Sqrt[-(1/n^2)]*n)/((c*x^n)^n^(-1)*(4*x)) + (Sqrt[-(1/n^2)]*n*(c*x^n)^(1/n)*Log[x])/(E^(a*Sqrt[-(1/n^2)]*n)*(2*x))}
{Sin[a + Sqrt[-(-3+1)^2/(1^2*n^2)]*Log[c*x^n]]^1/x^3, x, 6, (E^(a*Sqrt[-(1/n^2)]*n)*Sqrt[-(1/n^2)]*n)/((c*x^n)^(2/n)*(8*x^2)) + (Sqrt[-(1/n^2)]*n*(c*x^n)^(2/n)*Log[x])/(E^(a*Sqrt[-(1/n^2)]*n)*(2*x^2))}


{x^m*Sin[a + Sqrt[-(m+1)^2/(2^2*n^2)]*Log[c*x^n]]^2, x, 7, x^(1 + m)/(2*(1 + m)) - (x^(1 + m)*(c*x^n)^((1 + m)/n))/(E^((2*a*Sqrt[-((1 + m)^2/n^2)]*n)/(1 + m))*(8*(1 + m))) - ((1/4)*E^((2*a*Sqrt[-((1 + m)^2/n^2)]*n)/(1 + m))*x^(1 + m)*Log[x])/(c*x^n)^((1 + m)/n)}

{x^2*Sin[a + Sqrt[-(2+1)^2/(2^2*n^2)]*Log[c*x^n]]^2, x, 6, x^3/6 - ((1/24)*x^3*(c*x^n)^(3/n))/E^(2*a*Sqrt[-(1/n^2)]*n) - ((1/4)*E^(2*a*Sqrt[-(1/n^2)]*n)*x^3*Log[x])/(c*x^n)^(3/n)}
{x^1*Sin[a + Sqrt[-(1+1)^2/(2^2*n^2)]*Log[c*x^n]]^2, x, 6, x^2/4 - ((1/16)*x^2*(c*x^n)^(2/n))/E^(2*a*Sqrt[-(1/n^2)]*n) - ((1/4)*E^(2*a*Sqrt[-(1/n^2)]*n)*x^2*Log[x])/(c*x^n)^(2/n)}
{x^0*Sin[a + Sqrt[-(0+1)^2/(2^2*n^2)]*Log[c*x^n]]^2, x, 6, x/2 - ((1/8)*x*(c*x^n)^(1/n))/E^(2*a*Sqrt[-(1/n^2)]*n) - ((1/4)*E^(2*a*Sqrt[-(1/n^2)]*n)*x*Log[x])/(c*x^n)^n^(-1)}
{Sin[a + Sqrt[-(-1+1)^2/(2^2*n^2)]*Log[c*x^n]]^2/x^1, x, 2, Log[x]*Sin[a]^2}
{Sin[a + Sqrt[-(-2+1)^2/(2^2*n^2)]*Log[c*x^n]]^2/x^2, x, 6, -(1/(2*x)) + E^(2*a*Sqrt[-(1/n^2)]*n)/((c*x^n)^n^(-1)*(8*x)) - ((c*x^n)^(1/n)*Log[x])/(E^(2*a*Sqrt[-(1/n^2)]*n)*(4*x))}
{Sin[a + Sqrt[-(-3+1)^2/(2^2*n^2)]*Log[c*x^n]]^2/x^3, x, 6, -(1/(4*x^2)) + E^(2*a*Sqrt[-(1/n^2)]*n)/((c*x^n)^(2/n)*(16*x^2)) - ((c*x^n)^(2/n)*Log[x])/(E^(2*a*Sqrt[-(1/n^2)]*n)*(4*x^2))}


{x^m*Sin[a + Sqrt[-(m+1)^2/(2^2*n^2)]*Log[c*x^n]]^3, x, 2, -((4*Sqrt[-((1 + m)^2/n^2)]*n*x^(1 + m)*Cos[a + (1/2)*Sqrt[-((1 + m)^2/n^2)]*Log[c*x^n]])/(5*(1 + m)^2)) + (8*x^(1 + m)*Sin[a + (1/2)*Sqrt[-((1 + m)^2/n^2)]*Log[c*x^n]])/(5*(1 + m)) + (6*Sqrt[-((1 + m)^2/n^2)]*n*x^(1 + m)*Cos[a + (1/2)*Sqrt[-((1 + m)^2/n^2)]*Log[c*x^n]]*Sin[a + (1/2)*Sqrt[-((1 + m)^2/n^2)]*Log[c*x^n]]^2)/(5*(1 + m)^2) - (4*x^(1 + m)*Sin[a + (1/2)*Sqrt[-((1 + m)^2/n^2)]*Log[c*x^n]]^3)/(5*(1 + m))}

{x^2*Sin[a + Sqrt[-(2+1)^2/(3^2*n^2)]*Log[c*x^n]]^3, x, 10, ((-(3/16))*E^(a*Sqrt[-(1/n^2)]*n)*Sqrt[-(1/n^2)]*n*x^3)/(c*x^n)^n^(-1) + ((3/32)*Sqrt[-(1/n^2)]*n*x^3*(c*x^n)^(1/n))/E^(a*Sqrt[-(1/n^2)]*n) - ((1/48)*Sqrt[-(1/n^2)]*n*x^3*(c*x^n)^(3/n))/E^(3*a*Sqrt[-(1/n^2)]*n) + ((1/8)*E^(3*a*Sqrt[-(1/n^2)]*n)*Sqrt[-(1/n^2)]*n*x^3*Log[x])/(c*x^n)^(3/n)}
{x^1*Sin[a + Sqrt[-(1+1)^2/(3^2*n^2)]*Log[c*x^n]]^3, x, 10, ((-(9/32))*E^(a*Sqrt[-(1/n^2)]*n)*Sqrt[-(1/n^2)]*n*x^2)/(c*x^n)^(2/(3*n)) + ((9/64)*Sqrt[-(1/n^2)]*n*x^2*(c*x^n)^(2/(3*n)))/E^(a*Sqrt[-(1/n^2)]*n) - ((1/32)*Sqrt[-(1/n^2)]*n*x^2*(c*x^n)^(2/n))/E^(3*a*Sqrt[-(1/n^2)]*n) + ((1/8)*E^(3*a*Sqrt[-(1/n^2)]*n)*Sqrt[-(1/n^2)]*n*x^2*Log[x])/(c*x^n)^(2/n)}
{x^0*Sin[a + Sqrt[-(0+1)^2/(3^2*n^2)]*Log[c*x^n]]^3, x, 10, ((-(9/16))*E^(a*Sqrt[-(1/n^2)]*n)*Sqrt[-(1/n^2)]*n*x)/(c*x^n)^(1/(3*n)) + ((9/32)*Sqrt[-(1/n^2)]*n*x*(c*x^n)^(1/(3*n)))/E^(a*Sqrt[-(1/n^2)]*n) - ((1/16)*Sqrt[-(1/n^2)]*n*x*(c*x^n)^(1/n))/E^(3*a*Sqrt[-(1/n^2)]*n) + ((1/8)*E^(3*a*Sqrt[-(1/n^2)]*n)*Sqrt[-(1/n^2)]*n*x*Log[x])/(c*x^n)^n^(-1)}
{Sin[a + Sqrt[-(-1+1)^2/(3^2*n^2)]*Log[c*x^n]]^3/x^1, x, 2, Log[x]*Sin[a]^3}
{Sin[a + Sqrt[-(-2+1)^2/(3^2*n^2)]*Log[c*x^n]]^3/x^2, x, 10, -((E^(3*a*Sqrt[-(1/n^2)]*n)*Sqrt[-(1/n^2)]*n)/((c*x^n)^n^(-1)*(16*x))) + (9*E^(a*Sqrt[-(1/n^2)]*n)*Sqrt[-(1/n^2)]*n)/((c*x^n)^(1/(3*n))*(32*x)) - (9*Sqrt[-(1/n^2)]*n*(c*x^n)^(1/(3*n)))/(E^(a*Sqrt[-(1/n^2)]*n)*(16*x)) - (Sqrt[-(1/n^2)]*n*(c*x^n)^(1/n)*Log[x])/(E^(3*a*Sqrt[-(1/n^2)]*n)*(8*x))}
{Sin[a + Sqrt[-(-3+1)^2/(3^2*n^2)]*Log[c*x^n]]^3/x^3, x, 10, -((E^(3*a*Sqrt[-(1/n^2)]*n)*Sqrt[-(1/n^2)]*n)/((c*x^n)^(2/n)*(32*x^2))) + (9*E^(a*Sqrt[-(1/n^2)]*n)*Sqrt[-(1/n^2)]*n)/((c*x^n)^(2/(3*n))*(64*x^2)) - (9*Sqrt[-(1/n^2)]*n*(c*x^n)^(2/(3*n)))/(E^(a*Sqrt[-(1/n^2)]*n)*(32*x^2)) - (Sqrt[-(1/n^2)]*n*(c*x^n)^(2/n)*Log[x])/(E^(3*a*Sqrt[-(1/n^2)]*n)*(8*x^2))}


{x^m*Sin[a + Sqrt[-(m+1)^2/(1^2*2^2)]*Log[c*x^2]]^1, x, 7, -((E^((a*(1 + m))/Sqrt[-(1 + m)^2])*x^(1 + m)*(c*x^2)^((1 + m)/2))/(4*Sqrt[-(1 + m)^2])) + (E^((a*Sqrt[-(1 + m)^2])/(1 + m))*(1 + m)*x^(1 + m)*(c*x^2)^((1/2)*(-1 - m))*Log[x])/(2*Sqrt[-(1 + m)^2])}

{x^0*Sin[a + Sqrt[-(0+1)^2/(1^2*2^2)]*Log[c*x^2]]^1, x, 6, ((1/4)*I*x*Sqrt[c*x^2])/E^(I*a) - (I*E^(I*a)*x*Log[x])/(2*Sqrt[c*x^2])}


{x^m*Sin[a + Sqrt[-(m+1)^2/(2^2*2^2)]*Log[c*x^2]]^2, x, 7, x^(1 + m)/(2*(1 + m)) - (E^((2*a*(1 + m))/Sqrt[-(1 + m)^2])*x^(1 + m)*(c*x^2)^((1 + m)/2))/(8*(1 + m)) - ((1/4)*x^(1 + m)*(c*x^2)^((1/2)*(-1 - m))*Log[x])/E^((2*a*(1 + m))/Sqrt[-(1 + m)^2])}

{x^0*Sin[a + Sqrt[-(0+1)^2/(2^2*2^2)]*Log[c*x^2]]^2, x, 6, x/2 - ((1/8)*x*Sqrt[c*x^2])/E^(2*I*a) - (E^(2*I*a)*x*Log[x])/(4*Sqrt[c*x^2])}


{x^m*Sin[a + Sqrt[-(m+1)^2/(3^2*2^2)]*Log[c*x^2]]^3, x, 11, (9*E^((a*Sqrt[-(1 + m)^2])/(1 + m))*x^(1 + m)*(c*x^2)^((1/6)*(-1 - m)))/(16*Sqrt[-(1 + m)^2]) - (9*E^((a*(1 + m))/Sqrt[-(1 + m)^2])*x^(1 + m)*(c*x^2)^((1 + m)/6))/(32*Sqrt[-(1 + m)^2]) + (E^((3*a*(1 + m))/Sqrt[-(1 + m)^2])*x^(1 + m)*(c*x^2)^((1 + m)/2))/(16*Sqrt[-(1 + m)^2]) + (Sqrt[-(1 + m)^2]*x^(1 + m)*(c*x^2)^((1/2)*(-1 - m))*Log[x])/(E^((3*a*(1 + m))/Sqrt[-(1 + m)^2])*(8*(1 + m)))}

{x^0*Sin[a + Sqrt[-(0+1)^2/(3^2*2^2)]*Log[c*x^2]]^3, x, 10, -((9*I*E^(I*a)*x)/(16*(c*x^2)^(1/6))) + ((9/32)*I*x*(c*x^2)^(1/6))/E^(I*a) - ((1/16)*I*x*Sqrt[c*x^2])/E^(3*I*a) + (I*E^(3*I*a)*x*Log[x])/(8*Sqrt[c*x^2])}


(* ::Subsubsection::Closed:: *)
(*p/2>0*)


{x^m*Sqrt[Sin[a + b*Log[c*x^n]]], x, 1, (Sqrt[2]*x^(1 + m)*Sqrt[I/(E^(I*a)*(c*x^n)^(I*b)) - I*E^(I*a)*(c*x^n)^(I*b)]*Hypergeometric2F1[-(1/2), -((2*I + 2*I*m + b*n)/(4*b*n)), -((2*I + 2*I*m - 3*b*n)/(4*b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/((2 + 2*m - I*b*n)*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)])}

{x^2*Sqrt[Sin[a + b*Log[c*x^n]]], x, 1, (I*Sqrt[2]*x^3*Sqrt[I/(E^(I*a)*(c*x^n)^(I*b)) - I*E^(I*a)*(c*x^n)^(I*b)]*Hypergeometric2F1[-(1/2), -((6*I + b*n)/(4*b*n)), (3/4)*(1 - (2*I)/(b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/((6*I + b*n)*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)])}
{x^1*Sqrt[Sin[a + b*Log[c*x^n]]], x, 1, (I*Sqrt[2]*x^2*Sqrt[I/(E^(I*a)*(c*x^n)^(I*b)) - I*E^(I*a)*(c*x^n)^(I*b)]*Hypergeometric2F1[-(1/2), (1/4)*(-1 - (4*I)/(b*n)), (1/4)*(3 - (4*I)/(b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/((4*I + b*n)*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)])}
{x^0*Sqrt[Sin[a + b*Log[c*x^n]]], x, 1, (I*Sqrt[2]*x*Sqrt[I/(E^(I*a)*(c*x^n)^(I*b)) - I*E^(I*a)*(c*x^n)^(I*b)]*Hypergeometric2F1[-(1/2), -((2*I + b*n)/(4*b*n)), (1/4)*(3 - (2*I)/(b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/((2*I + b*n)*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)])}
{Sqrt[Sin[a + b*Log[c*x^n]]]/x^1, x, 2, -((2*EllipticE[Pi/4 + (1/2)*(-a - b*Log[c*x^n]), 2])/(b*n))}
{Sqrt[Sin[a + b*Log[c*x^n]]]/x^2, x, 1, -((Sqrt[2]*Sqrt[I/(E^(I*a)*(c*x^n)^(I*b)) - I*E^(I*a)*(c*x^n)^(I*b)]*Hypergeometric2F1[-(1/2), (1/4)*(-1 + (2*I)/(b*n)), (1/4)*(3 + (2*I)/(b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/((2 + I*b*n)*x*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)]))}
{Sqrt[Sin[a + b*Log[c*x^n]]]/x^3, x, 1, -((Sqrt[2]*Sqrt[I/(E^(I*a)*(c*x^n)^(I*b)) - I*E^(I*a)*(c*x^n)^(I*b)]*Hypergeometric2F1[-(1/2), (1/4)*(-1 + (4*I)/(b*n)), (1/4)*(3 + (4*I)/(b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/((4 + I*b*n)*x^2*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)]))}


{x^m*Sin[a + b*Log[c*x^n]]^(3/2), x, 2, (6*Sqrt[2]*b^2*n^2*x^(1 + m)*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)]*Hypergeometric2F1[1/2, -((2*I + 2*I*m - b*n)/(4*b*n)), -((2*I + 2*I*m - 5*b*n)/(4*b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/((2 + 2*m + I*b*n)*(4*(1 + m)^2 + 9*b^2*n^2)*Sqrt[I/(E^(I*a)*(c*x^n)^(I*b)) - I*E^(I*a)*(c*x^n)^(I*b)]) - (6*b*n*x^(1 + m)*Cos[a + b*Log[c*x^n]]*Sqrt[Sin[a + b*Log[c*x^n]]])/(4*(1 + m)^2 + 9*b^2*n^2) + (4*(1 + m)*x^(1 + m)*Sin[a + b*Log[c*x^n]]^(3/2))/(4*(1 + m)^2 + 9*b^2*n^2)}

{x^2*Sin[a + b*Log[c*x^n]]^(3/2), x, 2, (2*Sqrt[2]*b^2*n^2*x^3*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)]*Hypergeometric2F1[1/2, (1/4)*(1 - (6*I)/(b*n)), (1/4)*(5 - (6*I)/(b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/(3*(6 + I*b*n)*(4 + b^2*n^2)*Sqrt[I/(E^(I*a)*(c*x^n)^(I*b)) - I*E^(I*a)*(c*x^n)^(I*b)]) - (2*b*n*x^3*Cos[a + b*Log[c*x^n]]*Sqrt[Sin[a + b*Log[c*x^n]]])/(3*(4 + b^2*n^2)) + (4*x^3*Sin[a + b*Log[c*x^n]]^(3/2))/(3*(4 + b^2*n^2))}
{x^1*Sin[a + b*Log[c*x^n]]^(3/2), x, 2, (6*Sqrt[2]*b^2*n^2*x^2*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)]*Hypergeometric2F1[1/2, (1/4)*(1 - (4*I)/(b*n)), (1/4)*(5 - (4*I)/(b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/((4 + I*b*n)*(16 + 9*b^2*n^2)*Sqrt[I/(E^(I*a)*(c*x^n)^(I*b)) - I*E^(I*a)*(c*x^n)^(I*b)]) - (6*b*n*x^2*Cos[a + b*Log[c*x^n]]*Sqrt[Sin[a + b*Log[c*x^n]]])/(16 + 9*b^2*n^2) + (8*x^2*Sin[a + b*Log[c*x^n]]^(3/2))/(16 + 9*b^2*n^2)}
{x^0*Sin[a + b*Log[c*x^n]]^(3/2), x, 2, (6*Sqrt[2]*b^2*n^2*x*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)]*Hypergeometric2F1[1/2, (1/4)*(1 - (2*I)/(b*n)), (1/4)*(5 - (2*I)/(b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/((2 + I*b*n)*(4 + 9*b^2*n^2)*Sqrt[I/(E^(I*a)*(c*x^n)^(I*b)) - I*E^(I*a)*(c*x^n)^(I*b)]) - (6*b*n*x*Cos[a + b*Log[c*x^n]]*Sqrt[Sin[a + b*Log[c*x^n]]])/(4 + 9*b^2*n^2) + (4*x*Sin[a + b*Log[c*x^n]]^(3/2))/(4 + 9*b^2*n^2)}
{Sin[a + b*Log[c*x^n]]^(3/2)/x^1, x, 3, -((2*EllipticF[Pi/4 + (1/2)*(-a - b*Log[c*x^n]), 2])/(3*b*n)) - (2*Cos[a + b*Log[c*x^n]]*Sqrt[Sin[a + b*Log[c*x^n]]])/(3*b*n)}
{Sin[a + b*Log[c*x^n]]^(3/2)/x^2, x, 2, -((6*I*Sqrt[2]*b^2*n^2*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)]*Hypergeometric2F1[1/2, (1/4)*(1 + (2*I)/(b*n)), (1/4)*(5 + (2*I)/(b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/((2*I + b*n)*(4 + 9*b^2*n^2)*x*Sqrt[I/(E^(I*a)*(c*x^n)^(I*b)) - I*E^(I*a)*(c*x^n)^(I*b)])) - (6*b*n*Cos[a + b*Log[c*x^n]]*Sqrt[Sin[a + b*Log[c*x^n]]])/((4 + 9*b^2*n^2)*x) - (4*Sin[a + b*Log[c*x^n]]^(3/2))/((4 + 9*b^2*n^2)*x)}
{Sin[a + b*Log[c*x^n]]^(3/2)/x^3, x, 2, -((6*I*Sqrt[2]*b^2*n^2*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)]*Hypergeometric2F1[1/2, (1/4)*(1 + (4*I)/(b*n)), (1/4)*(5 + (4*I)/(b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/((4*I + b*n)*(16 + 9*b^2*n^2)*x^2*Sqrt[I/(E^(I*a)*(c*x^n)^(I*b)) - I*E^(I*a)*(c*x^n)^(I*b)])) - (6*b*n*Cos[a + b*Log[c*x^n]]*Sqrt[Sin[a + b*Log[c*x^n]]])/((16 + 9*b^2*n^2)*x^2) - (8*Sin[a + b*Log[c*x^n]]^(3/2))/((16 + 9*b^2*n^2)*x^2)}


{x^m*Sin[a + b*Log[c*x^n]]^(5/2), x, 2, (15*Sqrt[2]*b^2*n^2*x^(1 + m)*Sqrt[I/(E^(I*a)*(c*x^n)^(I*b)) - I*E^(I*a)*(c*x^n)^(I*b)]*Hypergeometric2F1[-(1/2), -((2*I + 2*I*m + b*n)/(4*b*n)), -((2*I + 2*I*m - 3*b*n)/(4*b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/((2 + 2*m - I*b*n)*(4*(1 + m)^2 + 25*b^2*n^2)*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)]) - (10*b*n*x^(1 + m)*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]]^(3/2))/(4*(1 + m)^2 + 25*b^2*n^2) + (4*(1 + m)*x^(1 + m)*Sin[a + b*Log[c*x^n]]^(5/2))/(4*(1 + m)^2 + 25*b^2*n^2)}

{x^2*Sin[a + b*Log[c*x^n]]^(5/2), x, 2, (15*I*Sqrt[2]*b^2*n^2*x^3*Sqrt[I/(E^(I*a)*(c*x^n)^(I*b)) - I*E^(I*a)*(c*x^n)^(I*b)]*Hypergeometric2F1[-(1/2), -((6*I + b*n)/(4*b*n)), (3/4)*(1 - (2*I)/(b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/((6*I + b*n)*(36 + 25*b^2*n^2)*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)]) - (10*b*n*x^3*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]]^(3/2))/(36 + 25*b^2*n^2) + (12*x^3*Sin[a + b*Log[c*x^n]]^(5/2))/(36 + 25*b^2*n^2)}
{x^1*Sin[a + b*Log[c*x^n]]^(5/2), x, 2, (15*I*Sqrt[2]*b^2*n^2*x^2*Sqrt[I/(E^(I*a)*(c*x^n)^(I*b)) - I*E^(I*a)*(c*x^n)^(I*b)]*Hypergeometric2F1[-(1/2), (1/4)*(-1 - (4*I)/(b*n)), (1/4)*(3 - (4*I)/(b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/((4*I + b*n)*(16 + 25*b^2*n^2)*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)]) - (10*b*n*x^2*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]]^(3/2))/(16 + 25*b^2*n^2) + (8*x^2*Sin[a + b*Log[c*x^n]]^(5/2))/(16 + 25*b^2*n^2)}
{x^0*Sin[a + b*Log[c*x^n]]^(5/2), x, 2, (15*I*Sqrt[2]*b^2*n^2*x*Sqrt[I/(E^(I*a)*(c*x^n)^(I*b)) - I*E^(I*a)*(c*x^n)^(I*b)]*Hypergeometric2F1[-(1/2), -((2*I + b*n)/(4*b*n)), (1/4)*(3 - (2*I)/(b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/((2*I + b*n)*(4 + 25*b^2*n^2)*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)]) - (10*b*n*x*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]]^(3/2))/(4 + 25*b^2*n^2) + (4*x*Sin[a + b*Log[c*x^n]]^(5/2))/(4 + 25*b^2*n^2)}
{Sin[a + b*Log[c*x^n]]^(5/2)/x^1, x, 3, -((6*EllipticE[Pi/4 + (1/2)*(-a - b*Log[c*x^n]), 2])/(5*b*n)) - (2*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]]^(3/2))/(5*b*n)}
{Sin[a + b*Log[c*x^n]]^(5/2)/x^2, x, 2, -((15*Sqrt[2]*b^2*n^2*Sqrt[I/(E^(I*a)*(c*x^n)^(I*b)) - I*E^(I*a)*(c*x^n)^(I*b)]*Hypergeometric2F1[-(1/2), (1/4)*(-1 + (2*I)/(b*n)), (1/4)*(3 + (2*I)/(b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/((2 + I*b*n)*(4 + 25*b^2*n^2)*x*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)])) - (10*b*n*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]]^(3/2))/((4 + 25*b^2*n^2)*x) - (4*Sin[a + b*Log[c*x^n]]^(5/2))/((4 + 25*b^2*n^2)*x)}
{Sin[a + b*Log[c*x^n]]^(5/2)/x^3, x, 2, -((15*Sqrt[2]*b^2*n^2*Sqrt[I/(E^(I*a)*(c*x^n)^(I*b)) - I*E^(I*a)*(c*x^n)^(I*b)]*Hypergeometric2F1[-(1/2), (1/4)*(-1 + (4*I)/(b*n)), (1/4)*(3 + (4*I)/(b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/((4 + I*b*n)*(16 + 25*b^2*n^2)*x^2*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)])) - (10*b*n*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]]^(3/2))/((16 + 25*b^2*n^2)*x^2) - (8*Sin[a + b*Log[c*x^n]]^(5/2))/((16 + 25*b^2*n^2)*x^2)}


(* ::Subsubsection::Closed:: *)
(*p/2<0*)


{x^m/Sqrt[Sin[a + b*Log[c*x^n]]], x, 1, (2*Sqrt[2]*x^(1 + m)*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)]*Hypergeometric2F1[1/2, -((2*I + 2*I*m - b*n)/(4*b*n)), -((2*I + 2*I*m - 5*b*n)/(4*b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/((2 + 2*m + I*b*n)*Sqrt[I/(E^(I*a)*(c*x^n)^(I*b)) - I*E^(I*a)*(c*x^n)^(I*b)])}

{x^0/Sqrt[Sin[a + b*Log[c*x^n]]], x, 1, (2*Sqrt[2]*x*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)]*Hypergeometric2F1[1/2, (1/4)*(1 - (2*I)/(b*n)), (1/4)*(5 - (2*I)/(b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/((2 + I*b*n)*Sqrt[I/(E^(I*a)*(c*x^n)^(I*b)) - I*E^(I*a)*(c*x^n)^(I*b)])}
{1/(x^1*Sqrt[Sin[a + b*Log[c*x^n]]]), x, 2, -((2*EllipticF[Pi/4 + (1/2)*(-a - b*Log[c*x^n]), 2])/(b*n))}


{x^m/Sin[a + b*Log[c*x^n]]^(3/2), x, 2, -((Sqrt[2]*(2 + 2*m + I*b*n)*x^(1 + m)*Sqrt[I/(E^(I*a)*(c*x^n)^(I*b)) - I*E^(I*a)*(c*x^n)^(I*b)]*Hypergeometric2F1[-(1/2), -((2*I + 2*I*m + b*n)/(4*b*n)), -((2*I + 2*I*m - 3*b*n)/(4*b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/(b^2*n^2*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)])) - (2*x^(1 + m)*Cos[a + b*Log[c*x^n]])/(b*n*Sqrt[Sin[a + b*Log[c*x^n]]]) + (4*(1 + m)*x^(1 + m)*Sqrt[Sin[a + b*Log[c*x^n]]])/(b^2*n^2)}

{x^0/Sin[a + b*Log[c*x^n]]^(3/2), x, 2, -((Sqrt[2]*(2 + I*b*n)*x*Sqrt[I/(E^(I*a)*(c*x^n)^(I*b)) - I*E^(I*a)*(c*x^n)^(I*b)]*Hypergeometric2F1[-(1/2), -((2*I + b*n)/(4*b*n)), (1/4)*(3 - (2*I)/(b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/(b^2*n^2*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)])) - (2*x*Cos[a + b*Log[c*x^n]])/(b*n*Sqrt[Sin[a + b*Log[c*x^n]]]) + (4*x*Sqrt[Sin[a + b*Log[c*x^n]]])/(b^2*n^2)}
{1/(x*Sin[a + b*Log[c*x^n]]^(3/2)), x, 3, (2*EllipticE[Pi/4 + (1/2)*(-a - b*Log[c*x^n]), 2])/(b*n) - (2*Cos[a + b*Log[c*x^n]])/(b*n*Sqrt[Sin[a + b*Log[c*x^n]]])}


{x^m/Sin[a + b*Log[c*x^n]]^(5/2), x, 2, (2*Sqrt[2]*(2 + 2*m - I*b*n)*x^(1 + m)*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)]*Hypergeometric2F1[1/2, -((2*I + 2*I*m - b*n)/(4*b*n)), -((2*I + 2*I*m - 5*b*n)/(4*b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/(3*b^2*n^2*Sqrt[I/(E^(I*a)*(c*x^n)^(I*b)) - I*E^(I*a)*(c*x^n)^(I*b)]) - (2*x^(1 + m)*Cos[a + b*Log[c*x^n]])/(3*b*n*Sin[a + b*Log[c*x^n]]^(3/2)) - (4*(1 + m)*x^(1 + m))/(3*b^2*n^2*Sqrt[Sin[a + b*Log[c*x^n]]])}

{x^0/Sin[a + b*Log[c*x^n]]^(5/2), x, 2, (2*Sqrt[2]*(2 - I*b*n)*x*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)]*Hypergeometric2F1[1/2, (1/4)*(1 - (2*I)/(b*n)), (1/4)*(5 - (2*I)/(b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/(3*b^2*n^2*Sqrt[I/(E^(I*a)*(c*x^n)^(I*b)) - I*E^(I*a)*(c*x^n)^(I*b)]) - (2*x*Cos[a + b*Log[c*x^n]])/(3*b*n*Sin[a + b*Log[c*x^n]]^(3/2)) - (4*x)/(3*b^2*n^2*Sqrt[Sin[a + b*Log[c*x^n]]])}
{1/(x*Sin[a + b*Log[c*x^n]]^(5/2)), x, 3, -((2*EllipticF[Pi/4 + (1/2)*(-a - b*Log[c*x^n]), 2])/(3*b*n)) - (2*Cos[a + b*Log[c*x^n]])/(3*b*n*Sin[a + b*Log[c*x^n]]^(3/2))}


{1/Sin[a - 2*I*Log[c*x]]^(3/2), x, 1, -((I*x*Cos[a - 2*I*Log[c*x]])/Sqrt[Sin[a - 2*I*Log[c*x]]]) - x*Sqrt[Sin[a - 2*I*Log[c*x]]]}


(* ::Subsubsection::Closed:: *)
(*p symbolic*)


{x^m*Sin[a + b*Log[c*x^n]]^p, x, 1, (x^(1 + m)*(I/(E^(I*a)*(c*x^n)^(I*b)) - I*E^(I*a)*(c*x^n)^(I*b))^p*Hypergeometric2F1[-p, -((I*(1 + m - I*b*n*p))/(2*b*n)), (1/2)*(2 - (I*(1 + m))/(b*n) - p), E^(2*I*a)*(c*x^n)^(2*I*b)])/((2 - 2*E^(2*I*a)*(c*x^n)^(2*I*b))^p*(1 + m - I*b*n*p))}

{x^2*Sin[a + b*Log[c*x^n]]^p, x, 1, (x^3*(I/(E^(I*a)*(c*x^n)^(I*b)) - I*E^(I*a)*(c*x^n)^(I*b))^p*Hypergeometric2F1[-p, -((3*I + b*n*p)/(2*b*n)), (1/2)*(2 - (3*I)/(b*n) - p), E^(2*I*a)*(c*x^n)^(2*I*b)])/((2 - 2*E^(2*I*a)*(c*x^n)^(2*I*b))^p*(3 - I*b*n*p))}
{x^1*Sin[a + b*Log[c*x^n]]^p, x, 1, (x^2*(I/(E^(I*a)*(c*x^n)^(I*b)) - I*E^(I*a)*(c*x^n)^(I*b))^p*Hypergeometric2F1[(1/2)*(-((2*I)/(b*n)) - p), -p, (1/2)*(2 - (2*I)/(b*n) - p), E^(2*I*a)*(c*x^n)^(2*I*b)])/((2 - 2*E^(2*I*a)*(c*x^n)^(2*I*b))^p*(2 - I*b*n*p))}
{x^0*Sin[a + b*Log[c*x^n]]^p, x, 1, (x*(I/(E^(I*a)*(c*x^n)^(I*b)) - I*E^(I*a)*(c*x^n)^(I*b))^p*Hypergeometric2F1[-p, -((I + b*n*p)/(2*b*n)), (1/2)*(2 - I/(b*n) - p), E^(2*I*a)*(c*x^n)^(2*I*b)])/((2 - 2*E^(2*I*a)*(c*x^n)^(2*I*b))^p*(1 - I*b*n*p))}
{Sin[a + b*Log[c*x^n]]^p/x^1, x, 2, -((Cos[a + b*Log[c*x^n]]*Hypergeometric2F1[1/2, (1 - p)/2, 3/2, Cos[a + b*Log[c*x^n]]^2]*Sin[a + b*Log[c*x^n]]^(1 + p)*(Sin[a + b*Log[c*x^n]]^2)^((1/2)*(-1 - p)))/(b*n))}
{Sin[a + b*Log[c*x^n]]^p/x^2, x, 1, -(((I/(E^(I*a)*(c*x^n)^(I*b)) - I*E^(I*a)*(c*x^n)^(I*b))^p*Hypergeometric2F1[(1/2)*(I/(b*n) - p), -p, (1/2)*(2 + I/(b*n) - p), E^(2*I*a)*(c*x^n)^(2*I*b)])/((2 - 2*E^(2*I*a)*(c*x^n)^(2*I*b))^p*((1 + I*b*n*p)*x)))}
{Sin[a + b*Log[c*x^n]]^p/x^3, x, 1, -(((I/(E^(I*a)*(c*x^n)^(I*b)) - I*E^(I*a)*(c*x^n)^(I*b))^p*Hypergeometric2F1[(1/2)*((2*I)/(b*n) - p), -p, (1/2)*(2 + (2*I)/(b*n) - p), E^(2*I*a)*(c*x^n)^(2*I*b)])/((2 - 2*E^(2*I*a)*(c*x^n)^(2*I*b))^p*((2 + I*b*n*p)*x^2)))}


(* ::Section::Closed:: *)
(*Integrands of the form x^m Cos[a+b Log[c x^n]]^p*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{x^m*Cos[a + b*Log[c*x^n]], x, 1, ((1 + m)*x^(1 + m)*Cos[a + b*Log[c*x^n]])/((1 + m)^2 + b^2*n^2) + (b*n*x^(1 + m)*Sin[a + b*Log[c*x^n]])/((1 + m)^2 + b^2*n^2)}

{x^2*Cos[a + b*Log[c*x^n]], x, 1, (3*x^3*Cos[a + b*Log[c*x^n]])/(9 + b^2*n^2) + (b*n*x^3*Sin[a + b*Log[c*x^n]])/(9 + b^2*n^2)}
{x^1*Cos[a + b*Log[c*x^n]], x, 1, (2*x^2*Cos[a + b*Log[c*x^n]])/(4 + b^2*n^2) + (b*n*x^2*Sin[a + b*Log[c*x^n]])/(4 + b^2*n^2)}
{x^0*Cos[a + b*Log[c*x^n]], x, 1, (x*Cos[a + b*Log[c*x^n]])/(1 + b^2*n^2) + (b*n*x*Sin[a + b*Log[c*x^n]])/(1 + b^2*n^2)}
{Cos[a + b*Log[c*x^n]]/x^1, x, 2, Sin[a + b*Log[c*x^n]]/(b*n)}
{Cos[a + b*Log[c*x^n]]/x^2, x, 1, -(Cos[a + b*Log[c*x^n]]/((1 + b^2*n^2)*x)) + (b*n*Sin[a + b*Log[c*x^n]])/((1 + b^2*n^2)*x)}


{x^m*Cos[a + b*Log[c*x^n]]^2, x, 2, (2*b^2*n^2*x^(1 + m))/((1 + m)*((1 + m)^2 + 4*b^2*n^2)) + ((1 + m)*x^(1 + m)*Cos[a + b*Log[c*x^n]]^2)/((1 + m)^2 + 4*b^2*n^2) + (2*b*n*x^(1 + m)*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/((1 + m)^2 + 4*b^2*n^2)}

{x^2*Cos[a + b*Log[c*x^n]]^2, x, 2, (2*b^2*n^2*x^3)/(3*(9 + 4*b^2*n^2)) + (3*x^3*Cos[a + b*Log[c*x^n]]^2)/(9 + 4*b^2*n^2) + (2*b*n*x^3*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/(9 + 4*b^2*n^2)}
{x^1*Cos[a + b*Log[c*x^n]]^2, x, 2, (b^2*n^2*x^2)/(4*(1 + b^2*n^2)) + (x^2*Cos[a + b*Log[c*x^n]]^2)/(2*(1 + b^2*n^2)) + (b*n*x^2*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/(2*(1 + b^2*n^2))}
{x^0*Cos[a + b*Log[c*x^n]]^2, x, 2, (2*b^2*n^2*x)/(1 + 4*b^2*n^2) + (x*Cos[a + b*Log[c*x^n]]^2)/(1 + 4*b^2*n^2) + (2*b*n*x*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/(1 + 4*b^2*n^2)}
{Cos[a + b*Log[c*x^n]]^2/x^1, x, 2, Log[c*x^n]/(2*n) + (Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/(2*b*n)}
{Cos[a + b*Log[c*x^n]]^2/x^2, x, 2, -((2*b^2*n^2)/((1 + 4*b^2*n^2)*x)) - Cos[a + b*Log[c*x^n]]^2/((1 + 4*b^2*n^2)*x) + (2*b*n*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/((1 + 4*b^2*n^2)*x)}


{x^m*Cos[a + b*Log[c*x^n]]^3, x, 2, (6*b^2*(1 + m)*n^2*x^(1 + m)*Cos[a + b*Log[c*x^n]])/(((1 + m)^2 + b^2*n^2)*((1 + m)^2 + 9*b^2*n^2)) + ((1 + m)*x^(1 + m)*Cos[a + b*Log[c*x^n]]^3)/((1 + m)^2 + 9*b^2*n^2) + (6*b^3*n^3*x^(1 + m)*Sin[a + b*Log[c*x^n]])/(((1 + m)^2 + b^2*n^2)*((1 + m)^2 + 9*b^2*n^2)) + (3*b*n*x^(1 + m)*Cos[a + b*Log[c*x^n]]^2*Sin[a + b*Log[c*x^n]])/((1 + m)^2 + 9*b^2*n^2)}

{x^2*Cos[a + b*Log[c*x^n]]^3, x, 2, (2*b^2*n^2*x^3*Cos[a + b*Log[c*x^n]])/(9 + 10*b^2*n^2 + b^4*n^4) + (x^3*Cos[a + b*Log[c*x^n]]^3)/(3*(1 + b^2*n^2)) + (2*b^3*n^3*x^3*Sin[a + b*Log[c*x^n]])/(3*(9 + 10*b^2*n^2 + b^4*n^4)) + (b*n*x^3*Cos[a + b*Log[c*x^n]]^2*Sin[a + b*Log[c*x^n]])/(3*(1 + b^2*n^2))}
{x^1*Cos[a + b*Log[c*x^n]]^3, x, 2, (12*b^2*n^2*x^2*Cos[a + b*Log[c*x^n]])/(16 + 40*b^2*n^2 + 9*b^4*n^4) + (2*x^2*Cos[a + b*Log[c*x^n]]^3)/(4 + 9*b^2*n^2) + (6*b^3*n^3*x^2*Sin[a + b*Log[c*x^n]])/(16 + 40*b^2*n^2 + 9*b^4*n^4) + (3*b*n*x^2*Cos[a + b*Log[c*x^n]]^2*Sin[a + b*Log[c*x^n]])/(4 + 9*b^2*n^2)}
{x^0*Cos[a + b*Log[c*x^n]]^3, x, 2, (6*b^2*n^2*x*Cos[a + b*Log[c*x^n]])/(1 + 10*b^2*n^2 + 9*b^4*n^4) + (x*Cos[a + b*Log[c*x^n]]^3)/(1 + 9*b^2*n^2) + (6*b^3*n^3*x*Sin[a + b*Log[c*x^n]])/(1 + 10*b^2*n^2 + 9*b^4*n^4) + (3*b*n*x*Cos[a + b*Log[c*x^n]]^2*Sin[a + b*Log[c*x^n]])/(1 + 9*b^2*n^2)}
{Cos[a + b*Log[c*x^n]]^3/x^1, x, 3, Sin[a + b*Log[c*x^n]]/(b*n) - Sin[a + b*Log[c*x^n]]^3/(3*b*n)}
{Cos[a + b*Log[c*x^n]]^3/x^2, x, 2, -((6*b^2*n^2*Cos[a + b*Log[c*x^n]])/((1 + 10*b^2*n^2 + 9*b^4*n^4)*x)) - Cos[a + b*Log[c*x^n]]^3/((1 + 9*b^2*n^2)*x) + (6*b^3*n^3*Sin[a + b*Log[c*x^n]])/((1 + 10*b^2*n^2 + 9*b^4*n^4)*x) + (3*b*n*Cos[a + b*Log[c*x^n]]^2*Sin[a + b*Log[c*x^n]])/((1 + 9*b^2*n^2)*x)}


{x^m*Cos[a + b*Log[c*x^n]]^4, x, 3, (24*b^4*n^4*x^(1 + m))/((1 + m)*((1 + m)^2 + 4*b^2*n^2)*((1 + m)^2 + 16*b^2*n^2)) + (12*b^2*(1 + m)*n^2*x^(1 + m)*Cos[a + b*Log[c*x^n]]^2)/(((1 + m)^2 + 4*b^2*n^2)*((1 + m)^2 + 16*b^2*n^2)) + ((1 + m)*x^(1 + m)*Cos[a + b*Log[c*x^n]]^4)/((1 + m)^2 + 16*b^2*n^2) + (24*b^3*n^3*x^(1 + m)*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/(((1 + m)^2 + 4*b^2*n^2)*((1 + m)^2 + 16*b^2*n^2)) + (4*b*n*x^(1 + m)*Cos[a + b*Log[c*x^n]]^3*Sin[a + b*Log[c*x^n]])/((1 + m)^2 + 16*b^2*n^2)}

{x^0*Cos[a + b*Log[c*x^n]]^4, x, 3, (24*b^4*n^4*x)/(1 + 20*b^2*n^2 + 64*b^4*n^4) + (12*b^2*n^2*x*Cos[a + b*Log[c*x^n]]^2)/(1 + 20*b^2*n^2 + 64*b^4*n^4) + (x*Cos[a + b*Log[c*x^n]]^4)/(1 + 16*b^2*n^2) + (24*b^3*n^3*x*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/(1 + 20*b^2*n^2 + 64*b^4*n^4) + (4*b*n*x*Cos[a + b*Log[c*x^n]]^3*Sin[a + b*Log[c*x^n]])/(1 + 16*b^2*n^2)}
{Cos[a + b*Log[c*x^n]]^4/x^1, x, 3, (3*Log[c*x^n])/(8*n) + (3*Cos[a + b*Log[c*x^n]]*Sin[a + b*Log[c*x^n]])/(8*b*n) + (Cos[a + b*Log[c*x^n]]^3*Sin[a + b*Log[c*x^n]])/(4*b*n)}


{Cos[Log[6 + 3*x]], x, 2, (1/2)*(2 + x)*Cos[Log[6 + 3*x]] + (1/2)*(2 + x)*Sin[Log[6 + 3*x]]}


(* ::Subsubsection::Closed:: *)
(*p>0 when b^2 n^2 p^2+(m+1)^2=0*)


{x^m*Sin[a + Sqrt[-(m+1)^2/(1^2*n^2)]*Log[c*x^n]]^1, x, 7, (E^((a*(1 + m))/(Sqrt[-((1 + m)^2/n^2)]*n))*Sqrt[-((1 + m)^2/n^2)]*n*x^(1 + m)*(c*x^n)^((1 + m)/n))/(4*(1 + m)^2) + (E^((a*Sqrt[-((1 + m)^2/n^2)]*n)/(1 + m))*(1 + m)*x^(1 + m)*Log[x])/((c*x^n)^((1 + m)/n)*(2*Sqrt[-((1 + m)^2/n^2)]*n))}

{x^0*Sin[a + Sqrt[-(0+1)^2/(1^2*n^2)]*Log[c*x^n]]^1, x, 6, ((1/4)*Sqrt[-(1/n^2)]*n*x*(c*x^n)^(1/n))/E^(a*Sqrt[-(1/n^2)]*n) - ((1/2)*E^(a*Sqrt[-(1/n^2)]*n)*Sqrt[-(1/n^2)]*n*x*Log[x])/(c*x^n)^n^(-1)}


{x^m*Sin[a + Sqrt[-(m+1)^2/(2^2*n^2)]*Log[c*x^n]]^2, x, 7, x^(1 + m)/(2*(1 + m)) - (x^(1 + m)*(c*x^n)^((1 + m)/n))/(E^((2*a*Sqrt[-((1 + m)^2/n^2)]*n)/(1 + m))*(8*(1 + m))) - ((1/4)*E^((2*a*Sqrt[-((1 + m)^2/n^2)]*n)/(1 + m))*x^(1 + m)*Log[x])/(c*x^n)^((1 + m)/n)}

{x^0*Sin[a + Sqrt[-(0+1)^2/(2^2*n^2)]*Log[c*x^n]]^2, x, 6, x/2 - ((1/8)*x*(c*x^n)^(1/n))/E^(2*a*Sqrt[-(1/n^2)]*n) - ((1/4)*E^(2*a*Sqrt[-(1/n^2)]*n)*x*Log[x])/(c*x^n)^n^(-1)}


{x^m*Sin[a + Sqrt[-(m+1)^2/(2^2*n^2)]*Log[c*x^n]]^3, x, 2, -((4*Sqrt[-((1 + m)^2/n^2)]*n*x^(1 + m)*Cos[a + (1/2)*Sqrt[-((1 + m)^2/n^2)]*Log[c*x^n]])/(5*(1 + m)^2)) + (8*x^(1 + m)*Sin[a + (1/2)*Sqrt[-((1 + m)^2/n^2)]*Log[c*x^n]])/(5*(1 + m)) + (6*Sqrt[-((1 + m)^2/n^2)]*n*x^(1 + m)*Cos[a + (1/2)*Sqrt[-((1 + m)^2/n^2)]*Log[c*x^n]]*Sin[a + (1/2)*Sqrt[-((1 + m)^2/n^2)]*Log[c*x^n]]^2)/(5*(1 + m)^2) - (4*x^(1 + m)*Sin[a + (1/2)*Sqrt[-((1 + m)^2/n^2)]*Log[c*x^n]]^3)/(5*(1 + m))}

{x^0*Sin[a + Sqrt[-(0+1)^2/(3^2*n^2)]*Log[c*x^n]]^3, x, 10, ((-(9/16))*E^(a*Sqrt[-(1/n^2)]*n)*Sqrt[-(1/n^2)]*n*x)/(c*x^n)^(1/(3*n)) + ((9/32)*Sqrt[-(1/n^2)]*n*x*(c*x^n)^(1/(3*n)))/E^(a*Sqrt[-(1/n^2)]*n) - ((1/16)*Sqrt[-(1/n^2)]*n*x*(c*x^n)^(1/n))/E^(3*a*Sqrt[-(1/n^2)]*n) + ((1/8)*E^(3*a*Sqrt[-(1/n^2)]*n)*Sqrt[-(1/n^2)]*n*x*Log[x])/(c*x^n)^n^(-1)}


(* ::Subsubsection::Closed:: *)
(*p/2>0*)


{x^m*Sqrt[Cos[a + b*Log[c*x^n]]], x, 1, (Sqrt[2]*x^(1 + m)*Sqrt[1/(E^(I*a)*(c*x^n)^(I*b)) + E^(I*a)*(c*x^n)^(I*b)]*Hypergeometric2F1[-(1/2), -((2*I + 2*I*m + b*n)/(4*b*n)), -((2*I + 2*I*m - 3*b*n)/(4*b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/((2 + 2*m - I*b*n)*Sqrt[1 + E^(2*I*a)*(c*x^n)^(2*I*b)])}

{x^0*Sqrt[Cos[a + b*Log[c*x^n]]], x, 1, (I*Sqrt[2]*x*Sqrt[1/(E^(I*a)*(c*x^n)^(I*b)) + E^(I*a)*(c*x^n)^(I*b)]*Hypergeometric2F1[-(1/2), -((2*I + b*n)/(4*b*n)), (1/4)*(3 - (2*I)/(b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/((2*I + b*n)*Sqrt[1 + E^(2*I*a)*(c*x^n)^(2*I*b)])}
{Sqrt[Cos[a + b*Log[c*x^n]]]/x^1, x, 2, (2*EllipticE[(a + b*Log[c*x^n])/2, 2])/(b*n)}


{x^m*Cos[a + b*Log[c*x^n]]^(3/2), x, 2, (4*(1 + m)*x^(1 + m)*Cos[a + b*Log[c*x^n]]^(3/2))/(4*(1 + m)^2 + 9*b^2*n^2) + (6*Sqrt[2]*b^2*n^2*x^(1 + m)*Sqrt[1 + E^(2*I*a)*(c*x^n)^(2*I*b)]*Hypergeometric2F1[1/2, -((2*I + 2*I*m - b*n)/(4*b*n)), -((2*I + 2*I*m - 5*b*n)/(4*b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/((2 + 2*m + I*b*n)*(4*(1 + m)^2 + 9*b^2*n^2)*Sqrt[1/(E^(I*a)*(c*x^n)^(I*b)) + E^(I*a)*(c*x^n)^(I*b)]) + (6*b*n*x^(1 + m)*Sqrt[Cos[a + b*Log[c*x^n]]]*Sin[a + b*Log[c*x^n]])/(4*(1 + m)^2 + 9*b^2*n^2)}

{x^0*Cos[a + b*Log[c*x^n]]^(3/2), x, 2, (4*x*Cos[a + b*Log[c*x^n]]^(3/2))/(4 + 9*b^2*n^2) + (6*Sqrt[2]*b^2*n^2*x*Sqrt[1 + E^(2*I*a)*(c*x^n)^(2*I*b)]*Hypergeometric2F1[1/2, (1/4)*(1 - (2*I)/(b*n)), (1/4)*(5 - (2*I)/(b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/((2 + I*b*n)*(4 + 9*b^2*n^2)*Sqrt[1/(E^(I*a)*(c*x^n)^(I*b)) + E^(I*a)*(c*x^n)^(I*b)]) + (6*b*n*x*Sqrt[Cos[a + b*Log[c*x^n]]]*Sin[a + b*Log[c*x^n]])/(4 + 9*b^2*n^2)}
{Cos[a + b*Log[c*x^n]]^(3/2)/x^1, x, 3, (2*EllipticF[(1/2)*(a + b*Log[c*x^n]), 2])/(3*b*n) + (2*Sqrt[Cos[a + b*Log[c*x^n]]]*Sin[a + b*Log[c*x^n]])/(3*b*n)}


{x^m*Cos[a + b*Log[c*x^n]]^(5/2), x, 2, (4*(1 + m)*x^(1 + m)*Cos[a + b*Log[c*x^n]]^(5/2))/(4*(1 + m)^2 + 25*b^2*n^2) + (15*Sqrt[2]*b^2*n^2*x^(1 + m)*Sqrt[1/(E^(I*a)*(c*x^n)^(I*b)) + E^(I*a)*(c*x^n)^(I*b)]*Hypergeometric2F1[-(1/2), -((2*I + 2*I*m + b*n)/(4*b*n)), -((2*I + 2*I*m - 3*b*n)/(4*b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/((2 + 2*m - I*b*n)*(4*(1 + m)^2 + 25*b^2*n^2)*Sqrt[1 + E^(2*I*a)*(c*x^n)^(2*I*b)]) + (10*b*n*x^(1 + m)*Cos[a + b*Log[c*x^n]]^(3/2)*Sin[a + b*Log[c*x^n]])/(4*(1 + m)^2 + 25*b^2*n^2)}

{x^0*Cos[a + b*Log[c*x^n]]^(5/2), x, 2, (4*x*Cos[a + b*Log[c*x^n]]^(5/2))/(4 + 25*b^2*n^2) + (15*I*Sqrt[2]*b^2*n^2*x*Sqrt[1/(E^(I*a)*(c*x^n)^(I*b)) + E^(I*a)*(c*x^n)^(I*b)]*Hypergeometric2F1[-(1/2), -((2*I + b*n)/(4*b*n)), (1/4)*(3 - (2*I)/(b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/((2*I + b*n)*(4 + 25*b^2*n^2)*Sqrt[1 + E^(2*I*a)*(c*x^n)^(2*I*b)]) + (10*b*n*x*Cos[a + b*Log[c*x^n]]^(3/2)*Sin[a + b*Log[c*x^n]])/(4 + 25*b^2*n^2)}
{Cos[a + b*Log[c*x^n]]^(5/2)/x^1, x, 3, (6*EllipticE[(1/2)*(a + b*Log[c*x^n]), 2])/(5*b*n) + (2*Cos[a + b*Log[c*x^n]]^(3/2)*Sin[a + b*Log[c*x^n]])/(5*b*n)}


(* ::Subsubsection::Closed:: *)
(*p/2<0*)


{x^m/Sqrt[Cos[a + b*Log[c*x^n]]], x, 1, (2*Sqrt[2]*x^(1 + m)*Sqrt[1 + E^(2*I*a)*(c*x^n)^(2*I*b)]*Hypergeometric2F1[1/2, -((2*I + 2*I*m - b*n)/(4*b*n)), -((2*I + 2*I*m - 5*b*n)/(4*b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/((2 + 2*m + I*b*n)*Sqrt[1/(E^(I*a)*(c*x^n)^(I*b)) + E^(I*a)*(c*x^n)^(I*b)])}

{x^0/Sqrt[Cos[a + b*Log[c*x^n]]], x, 1, (2*Sqrt[2]*x*Sqrt[1 + E^(2*I*a)*(c*x^n)^(2*I*b)]*Hypergeometric2F1[1/2, (1/4)*(1 - (2*I)/(b*n)), (1/4)*(5 - (2*I)/(b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/((2 + I*b*n)*Sqrt[1/(E^(I*a)*(c*x^n)^(I*b)) + E^(I*a)*(c*x^n)^(I*b)])}
{1/(x^1*Sqrt[Cos[a + b*Log[c*x^n]]]), x, 2, (2*EllipticF[(a + b*Log[c*x^n])/2, 2])/(b*n)}


{x^m/Cos[a + b*Log[c*x^n]]^(3/2), x, 2, (4*(1 + m)*x^(1 + m)*Sqrt[Cos[a + b*Log[c*x^n]]])/(b^2*n^2) - (Sqrt[2]*(2 + 2*m + I*b*n)*x^(1 + m)*Sqrt[1/(E^(I*a)*(c*x^n)^(I*b)) + E^(I*a)*(c*x^n)^(I*b)]*Hypergeometric2F1[-(1/2), -((2*I + 2*I*m + b*n)/(4*b*n)), -((2*I + 2*I*m - 3*b*n)/(4*b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/(b^2*n^2*Sqrt[1 + E^(2*I*a)*(c*x^n)^(2*I*b)]) + (2*x^(1 + m)*Sin[a + b*Log[c*x^n]])/(b*n*Sqrt[Cos[a + b*Log[c*x^n]]])}

{x^0/Cos[a + b*Log[c*x^n]]^(3/2), x, 2, (4*x*Sqrt[Cos[a + b*Log[c*x^n]]])/(b^2*n^2) - (Sqrt[2]*(2 + I*b*n)*x*Sqrt[1/(E^(I*a)*(c*x^n)^(I*b)) + E^(I*a)*(c*x^n)^(I*b)]*Hypergeometric2F1[-(1/2), -((2*I + b*n)/(4*b*n)), (1/4)*(3 - (2*I)/(b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/(b^2*n^2*Sqrt[1 + E^(2*I*a)*(c*x^n)^(2*I*b)]) + (2*x*Sin[a + b*Log[c*x^n]])/(b*n*Sqrt[Cos[a + b*Log[c*x^n]]])}
{1/(x*Cos[a + b*Log[c*x^n]]^(3/2)), x, 3, -((2*EllipticE[(1/2)*(a + b*Log[c*x^n]), 2])/(b*n)) + (2*Sin[a + b*Log[c*x^n]])/(b*n*Sqrt[Cos[a + b*Log[c*x^n]]])}


{x^m/Cos[a + b*Log[c*x^n]]^(5/2), x, 2, -((4*(1 + m)*x^(1 + m))/(3*b^2*n^2*Sqrt[Cos[a + b*Log[c*x^n]]])) + (2*Sqrt[2]*(2 + 2*m - I*b*n)*x^(1 + m)*Sqrt[1 + E^(2*I*a)*(c*x^n)^(2*I*b)]*Hypergeometric2F1[1/2, -((2*I + 2*I*m - b*n)/(4*b*n)), -((2*I + 2*I*m - 5*b*n)/(4*b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/(3*b^2*n^2*Sqrt[1/(E^(I*a)*(c*x^n)^(I*b)) + E^(I*a)*(c*x^n)^(I*b)]) + (2*x^(1 + m)*Sin[a + b*Log[c*x^n]])/(3*b*n*Cos[a + b*Log[c*x^n]]^(3/2))}

{x^0/Cos[a + b*Log[c*x^n]]^(5/2), x, 2, -((4*x)/(3*b^2*n^2*Sqrt[Cos[a + b*Log[c*x^n]]])) + (2*Sqrt[2]*(2 - I*b*n)*x*Sqrt[1 + E^(2*I*a)*(c*x^n)^(2*I*b)]*Hypergeometric2F1[1/2, (1/4)*(1 - (2*I)/(b*n)), (1/4)*(5 - (2*I)/(b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/(3*b^2*n^2*Sqrt[1/(E^(I*a)*(c*x^n)^(I*b)) + E^(I*a)*(c*x^n)^(I*b)]) + (2*x*Sin[a + b*Log[c*x^n]])/(3*b*n*Cos[a + b*Log[c*x^n]]^(3/2))}
{1/(x*Cos[a + b*Log[c*x^n]]^(5/2)), x, 3, (2*EllipticF[(1/2)*(a + b*Log[c*x^n]), 2])/(3*b*n) + (2*Sin[a + b*Log[c*x^n]])/(3*b*n*Cos[a + b*Log[c*x^n]]^(3/2))}


{1/Cos[a - 2*I*Log[c*x]]^(3/2), x, 1, (-x)*Sqrt[Cos[a - 2*I*Log[c*x]]] + (I*x*Sin[a - 2*I*Log[c*x]])/Sqrt[Cos[a - 2*I*Log[c*x]]]}


(* ::Subsubsection::Closed:: *)
(*p symbolic*)


{x^m*Cos[a + b*Log[c*x^n]]^p, x, 1, (x^(1 + m)*(1/(E^(I*a)*(c*x^n)^(I*b)) + E^(I*a)*(c*x^n)^(I*b))^p*Hypergeometric2F1[-p, -((I*(1 + m - I*b*n*p))/(2*b*n)), (1/2)*(2 - (I*(1 + m))/(b*n) - p), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/((2 + 2*E^(2*I*a)*(c*x^n)^(2*I*b))^p*(1 + m - I*b*n*p))}

{x^1*Cos[a + b*Log[c*x^n]]^p, x, 1, (x^2*(1/(E^(I*a)*(c*x^n)^(I*b)) + E^(I*a)*(c*x^n)^(I*b))^p*Hypergeometric2F1[(1/2)*(-((2*I)/(b*n)) - p), -p, (1/2)*(2 - (2*I)/(b*n) - p), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/((2 + 2*E^(2*I*a)*(c*x^n)^(2*I*b))^p*(2 - I*b*n*p))}
{x^0*Cos[a + b*Log[c*x^n]]^p, x, 1, (x*(1/(E^(I*a)*(c*x^n)^(I*b)) + E^(I*a)*(c*x^n)^(I*b))^p*Hypergeometric2F1[-p, -((I + b*n*p)/(2*b*n)), (1/2)*(2 - I/(b*n) - p), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/((2 + 2*E^(2*I*a)*(c*x^n)^(2*I*b))^p*(1 - I*b*n*p))}


(* ::Section::Closed:: *)
(*Integrands of the form x^m Tan[a+b Log[c x^n]]^p*)


(* ::Subsubsection::Closed:: *)
(*p*)


{Tan[a + b*Log[c*x^n]]/x, x, 2, -(Log[Cos[a + b*Log[c*x^n]]]/(b*n))}
{Tan[a + b*Log[c*x^n]]^2/x, x, 3, -(Log[c*x^n]/n) + Tan[a + b*Log[c*x^n]]/(b*n)}
{Tan[a + b*Log[c*x^n]]^3/x, x, 3, Log[Cos[a + b*Log[c*x^n]]]/(b*n) + Tan[a + b*Log[c*x^n]]^2/(2*b*n)}
{Tan[a + b*Log[c*x^n]]^4/x, x, 4, Log[c*x^n]/n - Tan[a + b*Log[c*x^n]]/(b*n) + Tan[a + b*Log[c*x^n]]^3/(3*b*n)}
{Tan[a + b*Log[c*x^n]]^5/x, x, 4, -(Log[Cos[a + b*Log[c*x^n]]]/(b*n)) - Tan[a + b*Log[c*x^n]]^2/(2*b*n) + Tan[a + b*Log[c*x^n]]^4/(4*b*n)}


(* ::Subsubsection::Closed:: *)
(*p/2*)


{Tan[a + b*Log[c*x^n]]^(5/2)/x, x, 10, ArcTan[1 - Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) - ArcTan[1 + Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) - Log[1 - Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]] + Tan[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n) + Log[1 + Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]] + Tan[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n) + (2*Tan[a + b*Log[c*x^n]]^(3/2))/(3*b*n)}
{Tan[a + b*Log[c*x^n]]^(3/2)/x, x, 10, ArcTan[1 - Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) - ArcTan[1 + Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) + Log[1 - Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]] + Tan[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n) - Log[1 + Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]] + Tan[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n) + (2*Sqrt[Tan[a + b*Log[c*x^n]]])/(b*n)}
{Sqrt[Tan[a + b*Log[c*x^n]]]/x, x, 9, -(ArcTan[1 - Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n)) + ArcTan[1 + Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) + Log[1 - Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]] + Tan[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n) - Log[1 + Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]] + Tan[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n)}
{1/(x*Sqrt[Tan[a + b*Log[c*x^n]]]), x, 9, -(ArcTan[1 - Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n)) + ArcTan[1 + Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) - Log[1 - Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]] + Tan[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n) + Log[1 + Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]] + Tan[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n)}
{1/(x*Tan[a + b*Log[c*x^n]]^(3/2)), x, 10, ArcTan[1 - Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) - ArcTan[1 + Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) - Log[1 - Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]] + Tan[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n) + Log[1 + Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]] + Tan[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n) - 2/(b*n*Sqrt[Tan[a + b*Log[c*x^n]]])}
{1/(x*Tan[a + b*Log[c*x^n]]^(5/2)), x, 10, ArcTan[1 - Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) - ArcTan[1 + Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) + Log[1 - Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]] + Tan[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n) - Log[1 + Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]] + Tan[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n) - 2/(3*b*n*Tan[a + b*Log[c*x^n]]^(3/2))}


(* ::Section::Closed:: *)
(*Integrands of the form x^m Cot[a+b Log[c x^n]]^p*)


(* ::Subsubsection::Closed:: *)
(*p*)


{Cot[a + b*Log[c*x^n]]/x, x, 2, Log[Sin[a + b*Log[c*x^n]]]/(b*n)}
{Cot[a + b*Log[c*x^n]]^2/x, x, 3, -(Cot[a + b*Log[c*x^n]]/(b*n)) - Log[c*x^n]/n}
{Cot[a + b*Log[c*x^n]]^3/x, x, 3, -(Cot[a + b*Log[c*x^n]]^2/(2*b*n)) - Log[Sin[a + b*Log[c*x^n]]]/(b*n)}
{Cot[a + b*Log[c*x^n]]^4/x, x, 4, Cot[a + b*Log[c*x^n]]/(b*n) - Cot[a + b*Log[c*x^n]]^3/(3*b*n) + Log[c*x^n]/n}
{Cot[a + b*Log[c*x^n]]^5/x, x, 4, Cot[a + b*Log[c*x^n]]^2/(2*b*n) - Cot[a + b*Log[c*x^n]]^4/(4*b*n) + Log[Sin[a + b*Log[c*x^n]]]/(b*n)}


(* ::Subsubsection::Closed:: *)
(*p/2*)


{Cot[a + b*Log[c*x^n]]^(5/2)/x, x, 10, -(ArcTan[1 - Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n)) + ArcTan[1 + Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) - (2*Cot[a + b*Log[c*x^n]]^(3/2))/(3*b*n) + Log[1 - Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]] + Cot[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n) - Log[1 + Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]] + Cot[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n)}
{Cot[a + b*Log[c*x^n]]^(3/2)/x, x, 10, -(ArcTan[1 - Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n)) + ArcTan[1 + Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) - (2*Sqrt[Cot[a + b*Log[c*x^n]]])/(b*n) - Log[1 - Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]] + Cot[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n) + Log[1 + Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]] + Cot[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n)}
{Sqrt[Cot[a + b*Log[c*x^n]]]/x, x, 9, ArcTan[1 - Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) - ArcTan[1 + Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) - Log[1 - Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]] + Cot[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n) + Log[1 + Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]] + Cot[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n)}
{1/(x*Sqrt[Cot[a + b*Log[c*x^n]]]), x, 9, ArcTan[1 - Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) - ArcTan[1 + Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) + Log[1 - Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]] + Cot[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n) - Log[1 + Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]] + Cot[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n)}
{1/(x*Cot[a + b*Log[c*x^n]]^(3/2)), x, 10, -(ArcTan[1 - Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n)) + ArcTan[1 + Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) + 2/(b*n*Sqrt[Cot[a + b*Log[c*x^n]]]) + Log[1 - Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]] + Cot[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n) - Log[1 + Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]] + Cot[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n)}
{1/(x*Cot[a + b*Log[c*x^n]]^(5/2)), x, 10, -(ArcTan[1 - Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n)) + ArcTan[1 + Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) + 2/(3*b*n*Cot[a + b*Log[c*x^n]]^(3/2)) - Log[1 - Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]] + Cot[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n) + Log[1 + Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]] + Cot[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n)}


(* ::Section::Closed:: *)
(*Integrands of the form x^m Sec[a+b Log[c x^n]]^p*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{x^m*Sec[a + b*Log[c*x^n]], x, 1, (2*E^(I*a)*x^(1 + m)*(c*x^n)^(I*b)*Hypergeometric2F1[1, -((I*(1 + m + I*b*n))/(2*b*n)), -((I*(1 + m + 3*I*b*n))/(2*b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/(1 + m + I*b*n)}

{x^2*Sec[a + b*Log[c*x^n]], x, 1, (2*E^(I*a)*x^3*(c*x^n)^(I*b)*Hypergeometric2F1[1, (1/2)*(1 - (3*I)/(b*n)), (3/2)*(1 - I/(b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/(3 + I*b*n)}
{x^1*Sec[a + b*Log[c*x^n]], x, 1, (2*E^(I*a)*x^2*(c*x^n)^(I*b)*Hypergeometric2F1[1, (1/2)*(1 - (2*I)/(b*n)), (1/2)*(3 - (2*I)/(b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/(2 + I*b*n)}
{x^0*Sec[a + b*Log[c*x^n]], x, 1, (2*E^(I*a)*x*(c*x^n)^(I*b)*Hypergeometric2F1[1, (1/2)*(1 - I/(b*n)), (1/2)*(3 - I/(b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/(1 + I*b*n)}
{Sec[a + b*Log[c*x^n]]/x^1, x, 2, ArcTanh[Sin[a + b*Log[c*x^n]]]/(b*n)}
{Sec[a + b*Log[c*x^n]]/x^2, x, 1, -((2*E^(I*a)*(c*x^n)^(I*b)*Hypergeometric2F1[1, (1/2)*(1 + I/(b*n)), (1/2)*(3 + I/(b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/((1 - I*b*n)*x))}
{Sec[a + b*Log[c*x^n]]/x^3, x, 1, -((2*E^(I*a)*(c*x^n)^(I*b)*Hypergeometric2F1[1, (1/2)*(1 + (2*I)/(b*n)), (1/2)*(3 + (2*I)/(b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/((2 - I*b*n)*x^2))}


{x^m*Sec[a + b*Log[c*x^n]]^2, x, 1, (4*E^(2*I*a)*x^(1 + m)*(c*x^n)^(2*I*b)*Hypergeometric2F1[2, -((I*(1 + m + 2*I*b*n))/(2*b*n)), -((I*(1 + m + 4*I*b*n))/(2*b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/(1 + m + 2*I*b*n)}

{x^2*Sec[a + b*Log[c*x^n]]^2, x, 1, (4*E^(2*I*a)*x^3*(c*x^n)^(2*I*b)*Hypergeometric2F1[2, (1/2)*(2 - (3*I)/(b*n)), (1/2)*(4 - (3*I)/(b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/(3 + 2*I*b*n)}
{x^1*Sec[a + b*Log[c*x^n]]^2, x, 1, (2*E^(2*I*a)*x^2*(c*x^n)^(2*I*b)*Hypergeometric2F1[2, 1 - I/(b*n), 2 - I/(b*n), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/(1 + I*b*n)}
{x^0*Sec[a + b*Log[c*x^n]]^2, x, 1, (4*E^(2*I*a)*x*(c*x^n)^(2*I*b)*Hypergeometric2F1[2, (1/2)*(2 - I/(b*n)), (1/2)*(4 - I/(b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/(1 + 2*I*b*n)}
{Sec[a + b*Log[c*x^n]]^2/x^1, x, 2, Tan[a + b*Log[c*x^n]]/(b*n)}
{Sec[a + b*Log[c*x^n]]^2/x^2, x, 1, -((4*E^(2*I*a)*(c*x^n)^(2*I*b)*Hypergeometric2F1[2, (1/2)*(2 + I/(b*n)), (1/2)*(4 + I/(b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/((1 - 2*I*b*n)*x))}
{Sec[a + b*Log[c*x^n]]^2/x^3, x, 1, -((2*E^(2*I*a)*(c*x^n)^(2*I*b)*Hypergeometric2F1[2, 1 + I/(b*n), 2 + I/(b*n), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/((1 - I*b*n)*x^2))}


{x^m*Sec[a + b*Log[c*x^n]]^3, x, 2, (E^(I*a)*(1 + m - I*b*n)*x^(1 + m)*(c*x^n)^(I*b)*Hypergeometric2F1[1, -((I*(1 + m + I*b*n))/(2*b*n)), -((I*(1 + m + 3*I*b*n))/(2*b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/(b^2*n^2) - ((1 + m)*x^(1 + m)*Sec[a + b*Log[c*x^n]])/(2*b^2*n^2) + (x^(1 + m)*Sec[a + b*Log[c*x^n]]*Tan[a + b*Log[c*x^n]])/(2*b*n)}

{x^2*Sec[a + b*Log[c*x^n]]^3, x, 2, (E^(I*a)*(3 - I*b*n)*x^3*(c*x^n)^(I*b)*Hypergeometric2F1[1, (1/2)*(1 - (3*I)/(b*n)), (3/2)*(1 - I/(b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/(b^2*n^2) - (3*x^3*Sec[a + b*Log[c*x^n]])/(2*b^2*n^2) + (x^3*Sec[a + b*Log[c*x^n]]*Tan[a + b*Log[c*x^n]])/(2*b*n)}
{x^1*Sec[a + b*Log[c*x^n]]^3, x, 2, (E^(I*a)*(2 - I*b*n)*x^2*(c*x^n)^(I*b)*Hypergeometric2F1[1, (1/2)*(1 - (2*I)/(b*n)), (1/2)*(3 - (2*I)/(b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/(b^2*n^2) - (x^2*Sec[a + b*Log[c*x^n]])/(b^2*n^2) + (x^2*Sec[a + b*Log[c*x^n]]*Tan[a + b*Log[c*x^n]])/(2*b*n)}
{x^0*Sec[a + b*Log[c*x^n]]^3, x, 2, (E^(I*a)*(1 - I*b*n)*x*(c*x^n)^(I*b)*Hypergeometric2F1[1, (1/2)*(1 - I/(b*n)), (1/2)*(3 - I/(b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/(b^2*n^2) - (x*Sec[a + b*Log[c*x^n]])/(2*b^2*n^2) + (x*Sec[a + b*Log[c*x^n]]*Tan[a + b*Log[c*x^n]])/(2*b*n)}
{Sec[a + b*Log[c*x^n]]^3/x^1, x, 3, ArcTanh[Sin[a + b*Log[c*x^n]]]/(2*b*n) + (Sec[a + b*Log[c*x^n]]*Tan[a + b*Log[c*x^n]])/(2*b*n)}
{Sec[a + b*Log[c*x^n]]^3/x^2, x, 2, -((E^(I*a)*(1 + I*b*n)*(c*x^n)^(I*b)*Hypergeometric2F1[1, (1/2)*(1 + I/(b*n)), (1/2)*(3 + I/(b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/(b^2*n^2*x)) + Sec[a + b*Log[c*x^n]]/(2*b^2*n^2*x) + (Sec[a + b*Log[c*x^n]]*Tan[a + b*Log[c*x^n]])/(2*b*n*x)}
{Sec[a + b*Log[c*x^n]]^3/x^3, x, 2, -((E^(I*a)*(2 + I*b*n)*(c*x^n)^(I*b)*Hypergeometric2F1[1, (1/2)*(1 + (2*I)/(b*n)), (1/2)*(3 + (2*I)/(b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/(b^2*n^2*x^2)) + Sec[a + b*Log[c*x^n]]/(b^2*n^2*x^2) + (Sec[a + b*Log[c*x^n]]*Tan[a + b*Log[c*x^n]])/(2*b*n*x^2)}


{x^m*Sec[a + b*Log[c*x^n]]^4, x, 2, (2*E^(2*I*a)*(1 + m - 2*I*b*n)*x^(1 + m)*(c*x^n)^(2*I*b)*Hypergeometric2F1[2, -((I*(1 + m + 2*I*b*n))/(2*b*n)), -((I*(1 + m + 4*I*b*n))/(2*b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/(3*b^2*n^2) - ((1 + m)*x^(1 + m)*Sec[a + b*Log[c*x^n]]^2)/(6*b^2*n^2) + (x^(1 + m)*Sec[a + b*Log[c*x^n]]^2*Tan[a + b*Log[c*x^n]])/(3*b*n)}

{x^2*Sec[a + b*Log[c*x^n]]^4, x, 2, (2*E^(2*I*a)*(3 - 2*I*b*n)*x^3*(c*x^n)^(2*I*b)*Hypergeometric2F1[2, (1/2)*(2 - (3*I)/(b*n)), (1/2)*(4 - (3*I)/(b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/(3*b^2*n^2) - (x^3*Sec[a + b*Log[c*x^n]]^2)/(2*b^2*n^2) + (x^3*Sec[a + b*Log[c*x^n]]^2*Tan[a + b*Log[c*x^n]])/(3*b*n)}
{x^1*Sec[a + b*Log[c*x^n]]^4, x, 2, (4*E^(2*I*a)*(1 - I*b*n)*x^2*(c*x^n)^(2*I*b)*Hypergeometric2F1[2, 1 - I/(b*n), 2 - I/(b*n), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/(3*b^2*n^2) - (x^2*Sec[a + b*Log[c*x^n]]^2)/(3*b^2*n^2) + (x^2*Sec[a + b*Log[c*x^n]]^2*Tan[a + b*Log[c*x^n]])/(3*b*n)}
{x^0*Sec[a + b*Log[c*x^n]]^4, x, 2, (2*E^(2*I*a)*(1 - 2*I*b*n)*x*(c*x^n)^(2*I*b)*Hypergeometric2F1[2, (1/2)*(2 - I/(b*n)), (1/2)*(4 - I/(b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/(3*b^2*n^2) - (x*Sec[a + b*Log[c*x^n]]^2)/(6*b^2*n^2) + (x*Sec[a + b*Log[c*x^n]]^2*Tan[a + b*Log[c*x^n]])/(3*b*n)}
{Sec[a + b*Log[c*x^n]]^4/x^1, x, 3, Tan[a + b*Log[c*x^n]]/(b*n) + Tan[a + b*Log[c*x^n]]^3/(3*b*n)}
{Sec[a + b*Log[c*x^n]]^4/x^2, x, 2, -((2*E^(2*I*a)*(1 + 2*I*b*n)*(c*x^n)^(2*I*b)*Hypergeometric2F1[2, (1/2)*(2 + I/(b*n)), (1/2)*(4 + I/(b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/(3*b^2*n^2*x)) + Sec[a + b*Log[c*x^n]]^2/(6*b^2*n^2*x) + (Sec[a + b*Log[c*x^n]]^2*Tan[a + b*Log[c*x^n]])/(3*b*n*x)}
{Sec[a + b*Log[c*x^n]]^4/x^3, x, 2, -((4*E^(2*I*a)*(1 + I*b*n)*(c*x^n)^(2*I*b)*Hypergeometric2F1[2, 1 + I/(b*n), 2 + I/(b*n), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/(3*b^2*n^2*x^2)) + Sec[a + b*Log[c*x^n]]^2/(3*b^2*n^2*x^2) + (Sec[a + b*Log[c*x^n]]^2*Tan[a + b*Log[c*x^n]])/(3*b*n*x^2)}


{2*b^2*n^2*Sec[a + b*Log[c*x^n]]^3 - (1 + b^2*n^2)*Sec[a + b*Log[c*x^n]], x, 0, (-x)*Sec[a + b*Log[c*x^n]] + b*n*x*Sec[a + b*Log[c*x^n]]*Tan[a + b*Log[c*x^n]]}


(* ::Subsubsection::Closed:: *)
(*p>0 when b^2 n^2 (p-2)^2+(m+1)^2=0*)


{x^m*Sec[a + 2*Log[c*x^(Sqrt[-(1 + m)^2]/2)]]^3, x, 1, (x^(1 + m)*Sec[a + 2*Log[c*x^((1/2)*Sqrt[-(1 + m)^2])]])/(2*(1 + m)) + (x^(1 + m)*Sec[a + 2*Log[c*x^((1/2)*Sqrt[-(1 + m)^2])]]*Tan[a + 2*Log[c*x^((1/2)*Sqrt[-(1 + m)^2])]])/(2*Sqrt[-(1 + m)^2])}

{x^1*Sec[a + 2*Log[c*x^I]]^3, x, 1, (1/4)*x^2*Sec[a + 2*Log[c*x^I]] - (1/4)*I*x^2*Sec[a + 2*Log[c*x^I]]*Tan[a + 2*Log[c*x^I]]}
{x^0*Sec[a + 2*Log[c*x^(I/2)]]^3, x, 1, (1/2)*x*Sec[a + 2*Log[c*x^(I/2)]] - (1/2)*I*x*Sec[a + 2*Log[c*x^(I/2)]]*Tan[a + 2*Log[c*x^(I/2)]]}


{Sec[a + 2*Log[c/x^(I/2)]]^3, x, 1, (1/2)*x*Sec[a + 2*Log[c/x^(I/2)]] + (1/2)*I*x*Sec[a + 2*Log[c/x^(I/2)]]*Tan[a + 2*Log[c/x^(I/2)]]}


{Sec[a + I/(n*(-2 + p))*Log[c*x^n]]^p, x, 1, ((2 - p)*x*Sec[a - (I*Log[c*x^n])/(n*(2 - p))]^(-2 + p))/(1 - p) - (I*(2 - p)*x*Sec[a - (I*Log[c*x^n])/(n*(2 - p))]^(-1 + p)*Sin[a - (I*Log[c*x^n])/(n*(2 - p))])/(1 - p)}
{Sec[a - I/(n*(-2 + p))*Log[c*x^n]]^p, x, 1, ((2 - p)*x*Sec[a + (I*Log[c*x^n])/(n*(2 - p))]^(-2 + p))/(1 - p) + (I*(2 - p)*x*Sec[a + (I*Log[c*x^n])/(n*(2 - p))]^(-1 + p)*Sin[a + (I*Log[c*x^n])/(n*(2 - p))])/(1 - p)}


(* ::Subsubsection::Closed:: *)
(*p/2>0*)


{x^m*Sqrt[Sec[a + b*Log[c*x^n]]], x, 1, (2*Sqrt[2]*x^(1 + m)*Sqrt[(E^(I*a)*(c*x^n)^(I*b))/(1 + E^(2*I*a)*(c*x^n)^(2*I*b))]*Sqrt[1 + E^(2*I*a)*(c*x^n)^(2*I*b)]*Hypergeometric2F1[1/2, -((2*I + 2*I*m - b*n)/(4*b*n)), -((2*I + 2*I*m - 5*b*n)/(4*b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/(2 + 2*m + I*b*n)}

{x^0*Sqrt[Sec[a + b*Log[c*x^n]]], x, 1, (2*Sqrt[2]*x*Sqrt[(E^(I*a)*(c*x^n)^(I*b))/(1 + E^(2*I*a)*(c*x^n)^(2*I*b))]*Sqrt[1 + E^(2*I*a)*(c*x^n)^(2*I*b)]*Hypergeometric2F1[1/2, (1/4)*(1 - (2*I)/(b*n)), (1/4)*(5 - (2*I)/(b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/(2 + I*b*n)}
{Sqrt[Sec[a + b*Log[c*x^n]]]/x^1, x, 3, (2*Sqrt[Cos[a + b*Log[c*x^n]]]*EllipticF[(a + b*Log[c*x^n])/2, 2]*Sqrt[Sec[a + b*Log[c*x^n]]])/(b*n)}


{x^m*Sec[a + b*Log[c*x^n]]^(3/2), x, 2, -((Sqrt[2]*(2 + 2*m + I*b*n)*x^(1 + m)*Hypergeometric2F1[-(1/2), -((2*I + 2*I*m + b*n)/(4*b*n)), -((2*I + 2*I*m - 3*b*n)/(4*b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/(b^2*n^2*Sqrt[(E^(I*a)*(c*x^n)^(I*b))/(1 + E^(2*I*a)*(c*x^n)^(2*I*b))]*Sqrt[1 + E^(2*I*a)*(c*x^n)^(2*I*b)])) + (4*(1 + m)*x^(1 + m))/(b^2*n^2*Sqrt[Sec[a + b*Log[c*x^n]]]) + (2*x^(1 + m)*Sqrt[Sec[a + b*Log[c*x^n]]]*Sin[a + b*Log[c*x^n]])/(b*n)}

{x^0*Sec[a + b*Log[c*x^n]]^(3/2), x, 2, -((Sqrt[2]*(2 + I*b*n)*x*Hypergeometric2F1[-(1/2), -((2*I + b*n)/(4*b*n)), (1/4)*(3 - (2*I)/(b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/(b^2*n^2*Sqrt[(E^(I*a)*(c*x^n)^(I*b))/(1 + E^(2*I*a)*(c*x^n)^(2*I*b))]*Sqrt[1 + E^(2*I*a)*(c*x^n)^(2*I*b)])) + (4*x)/(b^2*n^2*Sqrt[Sec[a + b*Log[c*x^n]]]) + (2*x*Sqrt[Sec[a + b*Log[c*x^n]]]*Sin[a + b*Log[c*x^n]])/(b*n)}
{Sec[a + b*Log[c*x^n]]^(3/2)/x^1, x, 4, -((2*Sqrt[Cos[a + b*Log[c*x^n]]]*EllipticE[(1/2)*(a + b*Log[c*x^n]), 2]*Sqrt[Sec[a + b*Log[c*x^n]]])/(b*n)) + (2*Sqrt[Sec[a + b*Log[c*x^n]]]*Sin[a + b*Log[c*x^n]])/(b*n)}


{x^m*Sec[a + b*Log[c*x^n]]^(5/2), x, 2, (2*Sqrt[2]*(2 + 2*m - I*b*n)*x^(1 + m)*Sqrt[(E^(I*a)*(c*x^n)^(I*b))/(1 + E^(2*I*a)*(c*x^n)^(2*I*b))]*Sqrt[1 + E^(2*I*a)*(c*x^n)^(2*I*b)]*Hypergeometric2F1[1/2, -((2*I + 2*I*m - b*n)/(4*b*n)), -((2*I + 2*I*m - 5*b*n)/(4*b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/(3*b^2*n^2) - (4*(1 + m)*x^(1 + m)*Sqrt[Sec[a + b*Log[c*x^n]]])/(3*b^2*n^2) + (2*x^(1 + m)*Sec[a + b*Log[c*x^n]]^(3/2)*Sin[a + b*Log[c*x^n]])/(3*b*n)}

{x^0*Sec[a + b*Log[c*x^n]]^(5/2), x, 2, (2*Sqrt[2]*(2 - I*b*n)*x*Sqrt[(E^(I*a)*(c*x^n)^(I*b))/(1 + E^(2*I*a)*(c*x^n)^(2*I*b))]*Sqrt[1 + E^(2*I*a)*(c*x^n)^(2*I*b)]*Hypergeometric2F1[1/2, (1/4)*(1 - (2*I)/(b*n)), (1/4)*(5 - (2*I)/(b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/(3*b^2*n^2) - (4*x*Sqrt[Sec[a + b*Log[c*x^n]]])/(3*b^2*n^2) + (2*x*Sec[a + b*Log[c*x^n]]^(3/2)*Sin[a + b*Log[c*x^n]])/(3*b*n)}
{Sec[a + b*Log[c*x^n]]^(5/2)/x^1, x, 4, (2*Sqrt[Cos[a + b*Log[c*x^n]]]*EllipticF[(1/2)*(a + b*Log[c*x^n]), 2]*Sqrt[Sec[a + b*Log[c*x^n]]])/(3*b*n) + (2*Sec[a + b*Log[c*x^n]]^(3/2)*Sin[a + b*Log[c*x^n]])/(3*b*n)}


(* ::Subsubsection::Closed:: *)
(*p/2<0*)


{x^m/Sqrt[Sec[a + b*Log[c*x^n]]], x, 1, (Sqrt[2]*x^(1 + m)*Hypergeometric2F1[-(1/2), -((2*I + 2*I*m + b*n)/(4*b*n)), -((2*I + 2*I*m - 3*b*n)/(4*b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/((2 + 2*m - I*b*n)*Sqrt[(E^(I*a)*(c*x^n)^(I*b))/(1 + E^(2*I*a)*(c*x^n)^(2*I*b))]*Sqrt[1 + E^(2*I*a)*(c*x^n)^(2*I*b)])}

{x^0/Sqrt[Sec[a + b*Log[c*x^n]]], x, 1, (I*Sqrt[2]*x*Hypergeometric2F1[-(1/2), -((2*I + b*n)/(4*b*n)), (1/4)*(3 - (2*I)/(b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/((2*I + b*n)*Sqrt[(E^(I*a)*(c*x^n)^(I*b))/(1 + E^(2*I*a)*(c*x^n)^(2*I*b))]*Sqrt[1 + E^(2*I*a)*(c*x^n)^(2*I*b)])}
{1/(x*Sqrt[Sec[a + b*Log[c*x^n]]]), x, 3, (2*Sqrt[Cos[a + b*Log[c*x^n]]]*EllipticE[(a + b*Log[c*x^n])/2, 2]*Sqrt[Sec[a + b*Log[c*x^n]]])/(b*n)}


{x^m/Sec[a + b*Log[c*x^n]]^(3/2), x, 2, (6*Sqrt[2]*b^2*n^2*x^(1 + m)*Sqrt[(E^(I*a)*(c*x^n)^(I*b))/(1 + E^(2*I*a)*(c*x^n)^(2*I*b))]*Sqrt[1 + E^(2*I*a)*(c*x^n)^(2*I*b)]*Hypergeometric2F1[1/2, -((2*I + 2*I*m - b*n)/(4*b*n)), -((2*I + 2*I*m - 5*b*n)/(4*b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/((2 + 2*m + I*b*n)*(4*(1 + m)^2 + 9*b^2*n^2)) + (4*(1 + m)*x^(1 + m))/((4*(1 + m)^2 + 9*b^2*n^2)*Sec[a + b*Log[c*x^n]]^(3/2)) + (6*b*n*x^(1 + m)*Sin[a + b*Log[c*x^n]])/((4*(1 + m)^2 + 9*b^2*n^2)*Sqrt[Sec[a + b*Log[c*x^n]]])}

{x^0/Sec[a + b*Log[c*x^n]]^(3/2), x, 2, (6*Sqrt[2]*b^2*n^2*x*Sqrt[(E^(I*a)*(c*x^n)^(I*b))/(1 + E^(2*I*a)*(c*x^n)^(2*I*b))]*Sqrt[1 + E^(2*I*a)*(c*x^n)^(2*I*b)]*Hypergeometric2F1[1/2, (1/4)*(1 - (2*I)/(b*n)), (1/4)*(5 - (2*I)/(b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/((2 + I*b*n)*(4 + 9*b^2*n^2)) + (4*x)/((4 + 9*b^2*n^2)*Sec[a + b*Log[c*x^n]]^(3/2)) + (6*b*n*x*Sin[a + b*Log[c*x^n]])/((4 + 9*b^2*n^2)*Sqrt[Sec[a + b*Log[c*x^n]]])}
{1/(x*Sec[a + b*Log[c*x^n]]^(3/2)), x, 4, (2*Sqrt[Cos[a + b*Log[c*x^n]]]*EllipticF[(1/2)*(a + b*Log[c*x^n]), 2]*Sqrt[Sec[a + b*Log[c*x^n]]])/(3*b*n) + (2*Sin[a + b*Log[c*x^n]])/(3*b*n*Sqrt[Sec[a + b*Log[c*x^n]]])}


{x^m/Sec[a + b*Log[c*x^n]]^(5/2), x, 2, (15*Sqrt[2]*b^2*n^2*x^(1 + m)*Hypergeometric2F1[-(1/2), -((2*I + 2*I*m + b*n)/(4*b*n)), -((2*I + 2*I*m - 3*b*n)/(4*b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/((2 + 2*m - I*b*n)*(4*(1 + m)^2 + 25*b^2*n^2)*Sqrt[(E^(I*a)*(c*x^n)^(I*b))/(1 + E^(2*I*a)*(c*x^n)^(2*I*b))]*Sqrt[1 + E^(2*I*a)*(c*x^n)^(2*I*b)]) + (4*(1 + m)*x^(1 + m))/((4*(1 + m)^2 + 25*b^2*n^2)*Sec[a + b*Log[c*x^n]]^(5/2)) + (10*b*n*x^(1 + m)*Sin[a + b*Log[c*x^n]])/((4*(1 + m)^2 + 25*b^2*n^2)*Sec[a + b*Log[c*x^n]]^(3/2))}

{x^0/Sec[a + b*Log[c*x^n]]^(5/2), x, 2, (15*I*Sqrt[2]*b^2*n^2*x*Hypergeometric2F1[-(1/2), -((2*I + b*n)/(4*b*n)), (1/4)*(3 - (2*I)/(b*n)), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/((2*I + b*n)*(4 + 25*b^2*n^2)*Sqrt[(E^(I*a)*(c*x^n)^(I*b))/(1 + E^(2*I*a)*(c*x^n)^(2*I*b))]*Sqrt[1 + E^(2*I*a)*(c*x^n)^(2*I*b)]) + (4*x)/((4 + 25*b^2*n^2)*Sec[a + b*Log[c*x^n]]^(5/2)) + (10*b*n*x*Sin[a + b*Log[c*x^n]])/((4 + 25*b^2*n^2)*Sec[a + b*Log[c*x^n]]^(3/2))}
{1/(x*Sec[a + b*Log[c*x^n]]^(5/2)), x, 4, (6*Sqrt[Cos[a + b*Log[c*x^n]]]*EllipticE[(1/2)*(a + b*Log[c*x^n]), 2]*Sqrt[Sec[a + b*Log[c*x^n]]])/(5*b*n) + (2*Sin[a + b*Log[c*x^n]])/(5*b*n*Sec[a + b*Log[c*x^n]]^(3/2))}


(* ::Subsubsection::Closed:: *)
(*p symbolic*)


{x^m*Sec[a + b*Log[c*x^n]]^p, x, 1, (x^(1 + m)*((E^(I*a)*(c*x^n)^(I*b))/(1 + E^(2*I*a)*(c*x^n)^(2*I*b)))^p*(2 + 2*E^(2*I*a)*(c*x^n)^(2*I*b))^p*Hypergeometric2F1[p, -((I*(1 + m + I*b*n*p))/(2*b*n)), (1/2)*(2 - (I*(1 + m))/(b*n) + p), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/(1 + m + I*b*n*p)}

{x^1*Sec[a + b*Log[c*x^n]]^p, x, 1, (x^2*((E^(I*a)*(c*x^n)^(I*b))/(1 + E^(2*I*a)*(c*x^n)^(2*I*b)))^p*(2 + 2*E^(2*I*a)*(c*x^n)^(2*I*b))^p*Hypergeometric2F1[p, (1/2)*(-((2*I)/(b*n)) + p), (1/2)*(2 - (2*I)/(b*n) + p), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/(2 + I*b*n*p)}
{x^0*Sec[a + b*Log[c*x^n]]^p, x, 1, (x*((E^(I*a)*(c*x^n)^(I*b))/(1 + E^(2*I*a)*(c*x^n)^(2*I*b)))^p*(2 + 2*E^(2*I*a)*(c*x^n)^(2*I*b))^p*Hypergeometric2F1[p, -((I - b*n*p)/(2*b*n)), (1/2)*(2 - I/(b*n) + p), (-E^(2*I*a))*(c*x^n)^(2*I*b)])/(1 + I*b*n*p)}


(* ::Section::Closed:: *)
(*Integrands of the form x^m Csc[a+b Log[c x^n]]^p*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{x^m*Csc[a + b*Log[c*x^n]], x, 1, -((2*I*E^(I*a)*x^(1 + m)*(c*x^n)^(I*b)*Hypergeometric2F1[1, -((I*(1 + m + I*b*n))/(2*b*n)), -((I*(1 + m + 3*I*b*n))/(2*b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/(1 + m + I*b*n))}

{x^3*Csc[a + b*Log[c*x^n]], x, 1, (2*E^(I*a)*x^4*(c*x^n)^(I*b)*Hypergeometric2F1[1, (1/2)*(1 - (4*I)/(b*n)), (1/2)*(3 - (4*I)/(b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/(4*I - b*n)}
{x^2*Csc[a + b*Log[c*x^n]], x, 1, (2*E^(I*a)*x^3*(c*x^n)^(I*b)*Hypergeometric2F1[1, (1/2)*(1 - (3*I)/(b*n)), (3/2)*(1 - I/(b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/(3*I - b*n)}
{x^1*Csc[a + b*Log[c*x^n]], x, 1, (2*E^(I*a)*x^2*(c*x^n)^(I*b)*Hypergeometric2F1[1, (1/2)*(1 - (2*I)/(b*n)), (1/2)*(3 - (2*I)/(b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/(2*I - b*n)}
{x^0*Csc[a + b*Log[c*x^n]], x, 1, (2*E^(I*a)*x*(c*x^n)^(I*b)*Hypergeometric2F1[1, (1/2)*(1 - I/(b*n)), (1/2)*(3 - I/(b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/(I - b*n)}
{Csc[a + b*Log[c*x^n]]/x^1, x, 2, -(ArcTanh[Cos[a + b*Log[c*x^n]]]/(b*n))}
{Csc[a + b*Log[c*x^n]]/x^2, x, 1, -((2*E^(I*a)*(c*x^n)^(I*b)*Hypergeometric2F1[1, (1/2)*(1 + I/(b*n)), (1/2)*(3 + I/(b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/((I + b*n)*x))}
{Csc[a + b*Log[c*x^n]]/x^3, x, 1, -((2*E^(I*a)*(c*x^n)^(I*b)*Hypergeometric2F1[1, (1/2)*(1 + (2*I)/(b*n)), (1/2)*(3 + (2*I)/(b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/((2*I + b*n)*x^2))}


{x^m*Csc[a + b*Log[c*x^n]]^2, x, 1, -((4*E^(2*I*a)*x^(1 + m)*(c*x^n)^(2*I*b)*Hypergeometric2F1[2, -((I*(1 + m + 2*I*b*n))/(2*b*n)), -((I*(1 + m + 4*I*b*n))/(2*b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/(1 + m + 2*I*b*n))}

{x^0*Csc[a + b*Log[c*x^n]]^2, x, 1, -((4*E^(2*I*a)*x*(c*x^n)^(2*I*b)*Hypergeometric2F1[2, (1/2)*(2 - I/(b*n)), (1/2)*(4 - I/(b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/(1 + 2*I*b*n))}
{Csc[a + b*Log[c*x^n]]^2/x^1, x, 2, -(Cot[a + b*Log[c*x^n]]/(b*n))}


{x^m*Csc[a + b*Log[c*x^n]]^3, x, 2, -(((1 + m)*x^(1 + m)*Csc[a + b*Log[c*x^n]])/(2*b^2*n^2)) - (x^(1 + m)*Cot[a + b*Log[c*x^n]]*Csc[a + b*Log[c*x^n]])/(2*b*n) - (E^(I*a)*(I + I*m + b*n)*x^(1 + m)*(c*x^n)^(I*b)*Hypergeometric2F1[1, -((I*(1 + m + I*b*n))/(2*b*n)), -((I*(1 + m + 3*I*b*n))/(2*b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/(b^2*n^2)}

{x^0*Csc[a + b*Log[c*x^n]]^3, x, 2, -((x*Csc[a + b*Log[c*x^n]])/(2*b^2*n^2)) - (x*Cot[a + b*Log[c*x^n]]*Csc[a + b*Log[c*x^n]])/(2*b*n) - (E^(I*a)*(I + b*n)*x*(c*x^n)^(I*b)*Hypergeometric2F1[1, (1/2)*(1 - I/(b*n)), (1/2)*(3 - I/(b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/(b^2*n^2)}
{Csc[a + b*Log[c*x^n]]^3/x^1, x, 3, -(ArcTanh[Cos[a + b*Log[c*x^n]]]/(2*b*n)) - (Cot[a + b*Log[c*x^n]]*Csc[a + b*Log[c*x^n]])/(2*b*n)}


{x^m*Csc[a + b*Log[c*x^n]]^4, x, 2, -(((1 + m)*x^(1 + m)*Csc[a + b*Log[c*x^n]]^2)/(6*b^2*n^2)) - (x^(1 + m)*Cot[a + b*Log[c*x^n]]*Csc[a + b*Log[c*x^n]]^2)/(3*b*n) - (2*E^(2*I*a)*(1 + m - 2*I*b*n)*x^(1 + m)*(c*x^n)^(2*I*b)*Hypergeometric2F1[2, -((I*(1 + m + 2*I*b*n))/(2*b*n)), -((I*(1 + m + 4*I*b*n))/(2*b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/(3*b^2*n^2)}

{x^0*Csc[a + b*Log[c*x^n]]^4, x, 2, -((x*Csc[a + b*Log[c*x^n]]^2)/(6*b^2*n^2)) - (x*Cot[a + b*Log[c*x^n]]*Csc[a + b*Log[c*x^n]]^2)/(3*b*n) - (2*E^(2*I*a)*(1 - 2*I*b*n)*x*(c*x^n)^(2*I*b)*Hypergeometric2F1[2, (1/2)*(2 - I/(b*n)), (1/2)*(4 - I/(b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/(3*b^2*n^2)}
{Csc[a + b*Log[c*x^n]]^4/x^1, x, 3, -(Cot[a + b*Log[c*x^n]]/(b*n)) - Cot[a + b*Log[c*x^n]]^3/(3*b*n)}


{2*b^2*n^2*Csc[a + b*Log[c*x^n]]^3 - (1 + b^2*n^2)*Csc[a + b*Log[c*x^n]], x, 4, (-x)*Csc[a + b*Log[c*x^n]] - b*n*x*Cot[a + b*Log[c*x^n]]*Csc[a + b*Log[c*x^n]]}


(* ::Subsubsection::Closed:: *)
(*p>0 when b^2 n^2 (p-2)^2+(m+1)^2=0*)


{x^m*Csc[a + 2*Log[c*x^(Sqrt[-(1 + m)^2]/2)]]^3, x, 1, (x^(1 + m)*Csc[a + 2*Log[c*x^((1/2)*Sqrt[-(1 + m)^2])]])/(2*(1 + m)) - (x^(1 + m)*Cot[a + 2*Log[c*x^((1/2)*Sqrt[-(1 + m)^2])]]*Csc[a + 2*Log[c*x^((1/2)*Sqrt[-(1 + m)^2])]])/(2*Sqrt[-(1 + m)^2])}

{x^1*Csc[a + 2*Log[c*x^I]]^3, x, 1, (1/4)*x^2*Csc[a + 2*Log[c*x^I]] + (1/4)*I*x^2*Cot[a + 2*Log[c*x^I]]*Csc[a + 2*Log[c*x^I]]}
{Csc[a + 2*Log[c*x^(I/2)]]^3, x, 1, (1/2)*x*Csc[a + 2*Log[c*x^(I/2)]] + (1/2)*I*x*Cot[a + 2*Log[c*x^(I/2)]]*Csc[a + 2*Log[c*x^(I/2)]]}


{Csc[a + 2*Log[c/x^(I/2)]]^3, x, 1, (1/2)*x*Csc[a + 2*Log[c/x^(I/2)]] - (1/2)*I*x*Cot[a + 2*Log[c/x^(I/2)]]*Csc[a + 2*Log[c/x^(I/2)]]}


{Csc[a + I/(n*(-2 + p))*Log[c*x^n]]^p, x, 1, ((2 - p)*x*Csc[a - (I*Log[c*x^n])/(n*(2 - p))]^(-2 + p))/(1 - p) + (I*(2 - p)*x*Cos[a - (I*Log[c*x^n])/(n*(2 - p))]*Csc[a - (I*Log[c*x^n])/(n*(2 - p))]^(-1 + p))/(1 - p)}
{Csc[a - I/(n*(-2 + p))*Log[c*x^n]]^p, x, 1, ((2 - p)*x*Csc[a + (I*Log[c*x^n])/(n*(2 - p))]^(-2 + p))/(1 - p) - (I*(2 - p)*x*Cos[a + (I*Log[c*x^n])/(n*(2 - p))]*Csc[a + (I*Log[c*x^n])/(n*(2 - p))]^(-1 + p))/(1 - p)}


(* ::Subsubsection::Closed:: *)
(*p/2>0*)


{x^m*Sqrt[Csc[a + b*Log[c*x^n]]], x, 1, (2*Sqrt[2]*x^(1 + m)*Sqrt[-((I*E^(I*a)*(c*x^n)^(I*b))/(1 - E^(2*I*a)*(c*x^n)^(2*I*b)))]*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)]*Hypergeometric2F1[1/2, -((2*I + 2*I*m - b*n)/(4*b*n)), -((2*I + 2*I*m - 5*b*n)/(4*b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/(2 + 2*m + I*b*n)}

{x^0*Sqrt[Csc[a + b*Log[c*x^n]]], x, 1, (2*Sqrt[2]*x*Sqrt[-((I*E^(I*a)*(c*x^n)^(I*b))/(1 - E^(2*I*a)*(c*x^n)^(2*I*b)))]*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)]*Hypergeometric2F1[1/2, (1/4)*(1 - (2*I)/(b*n)), (1/4)*(5 - (2*I)/(b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/(2 + I*b*n)}
{Sqrt[Csc[a + b*Log[c*x^n]]]/x, x, 3, -((2*Sqrt[Csc[a + b*Log[c*x^n]]]*EllipticF[Pi/4 + (1/2)*(-a - b*Log[c*x^n]), 2]*Sqrt[Sin[a + b*Log[c*x^n]]])/(b*n))}


{x^m*Csc[a + b*Log[c*x^n]]^(3/2), x, 2, (4*(1 + m)*x^(1 + m))/(b^2*n^2*Sqrt[Csc[a + b*Log[c*x^n]]]) - (2*x^(1 + m)*Cos[a + b*Log[c*x^n]]*Sqrt[Csc[a + b*Log[c*x^n]]])/(b*n) - (Sqrt[2]*(2 + 2*m + I*b*n)*x^(1 + m)*Hypergeometric2F1[-(1/2), -((2*I + 2*I*m + b*n)/(4*b*n)), -((2*I + 2*I*m - 3*b*n)/(4*b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/(b^2*n^2*Sqrt[-((I*E^(I*a)*(c*x^n)^(I*b))/(1 - E^(2*I*a)*(c*x^n)^(2*I*b)))]*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)])}

{x^0*Csc[a + b*Log[c*x^n]]^(3/2), x, 2, (4*x)/(b^2*n^2*Sqrt[Csc[a + b*Log[c*x^n]]]) - (2*x*Cos[a + b*Log[c*x^n]]*Sqrt[Csc[a + b*Log[c*x^n]]])/(b*n) - (Sqrt[2]*(2 + I*b*n)*x*Hypergeometric2F1[-(1/2), -((2*I + b*n)/(4*b*n)), (1/4)*(3 - (2*I)/(b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/(b^2*n^2*Sqrt[-((I*E^(I*a)*(c*x^n)^(I*b))/(1 - E^(2*I*a)*(c*x^n)^(2*I*b)))]*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)])}
{Csc[a + b*Log[c*x^n]]^(3/2)/x, x, 4, -((2*Cos[a + b*Log[c*x^n]]*Sqrt[Csc[a + b*Log[c*x^n]]])/(b*n)) + (2*Sqrt[Csc[a + b*Log[c*x^n]]]*EllipticE[Pi/4 + (1/2)*(-a - b*Log[c*x^n]), 2]*Sqrt[Sin[a + b*Log[c*x^n]]])/(b*n)}


{x^m*Csc[a + b*Log[c*x^n]]^(5/2), x, 2, -((4*(1 + m)*x^(1 + m)*Sqrt[Csc[a + b*Log[c*x^n]]])/(3*b^2*n^2)) - (2*x^(1 + m)*Cos[a + b*Log[c*x^n]]*Csc[a + b*Log[c*x^n]]^(3/2))/(3*b*n) + (2*Sqrt[2]*(2 + 2*m - I*b*n)*x^(1 + m)*Sqrt[-((I*E^(I*a)*(c*x^n)^(I*b))/(1 - E^(2*I*a)*(c*x^n)^(2*I*b)))]*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)]*Hypergeometric2F1[1/2, -((2*I + 2*I*m - b*n)/(4*b*n)), -((2*I + 2*I*m - 5*b*n)/(4*b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/(3*b^2*n^2)}

{x^0*Csc[a + b*Log[c*x^n]]^(5/2), x, 2, -((4*x*Sqrt[Csc[a + b*Log[c*x^n]]])/(3*b^2*n^2)) - (2*x*Cos[a + b*Log[c*x^n]]*Csc[a + b*Log[c*x^n]]^(3/2))/(3*b*n) + (2*Sqrt[2]*(2 - I*b*n)*x*Sqrt[-((I*E^(I*a)*(c*x^n)^(I*b))/(1 - E^(2*I*a)*(c*x^n)^(2*I*b)))]*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)]*Hypergeometric2F1[1/2, (1/4)*(1 - (2*I)/(b*n)), (1/4)*(5 - (2*I)/(b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/(3*b^2*n^2)}
{Csc[a + b*Log[c*x^n]]^(5/2)/x, x, 4, -((2*Cos[a + b*Log[c*x^n]]*Csc[a + b*Log[c*x^n]]^(3/2))/(3*b*n)) - (2*Sqrt[Csc[a + b*Log[c*x^n]]]*EllipticF[Pi/4 + (1/2)*(-a - b*Log[c*x^n]), 2]*Sqrt[Sin[a + b*Log[c*x^n]]])/(3*b*n)}


(* ::Subsubsection::Closed:: *)
(*p/2<0*)


{x^m/Sqrt[Csc[a + b*Log[c*x^n]]], x, 1, (Sqrt[2]*x^(1 + m)*Hypergeometric2F1[-(1/2), -((2*I + 2*I*m + b*n)/(4*b*n)), -((2*I + 2*I*m - 3*b*n)/(4*b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/((2 + 2*m - I*b*n)*Sqrt[-((I*E^(I*a)*(c*x^n)^(I*b))/(1 - E^(2*I*a)*(c*x^n)^(2*I*b)))]*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)])}

{x^0/Sqrt[Csc[a + b*Log[c*x^n]]], x, 1, (I*Sqrt[2]*x*Hypergeometric2F1[-(1/2), -((2*I + b*n)/(4*b*n)), (1/4)*(3 - (2*I)/(b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/((2*I + b*n)*Sqrt[-((I*E^(I*a)*(c*x^n)^(I*b))/(1 - E^(2*I*a)*(c*x^n)^(2*I*b)))]*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)])}
{1/(x*Sqrt[Csc[a + b*Log[c*x^n]]]), x, 3, -((2*Sqrt[Csc[a + b*Log[c*x^n]]]*EllipticE[Pi/4 + (1/2)*(-a - b*Log[c*x^n]), 2]*Sqrt[Sin[a + b*Log[c*x^n]]])/(b*n))}


{x^m/Csc[a + b*Log[c*x^n]]^(3/2), x, 2, (4*(1 + m)*x^(1 + m))/((4*(1 + m)^2 + 9*b^2*n^2)*Csc[a + b*Log[c*x^n]]^(3/2)) - (6*b*n*x^(1 + m)*Cos[a + b*Log[c*x^n]])/((4*(1 + m)^2 + 9*b^2*n^2)*Sqrt[Csc[a + b*Log[c*x^n]]]) + (6*Sqrt[2]*b^2*n^2*x^(1 + m)*Sqrt[-((I*E^(I*a)*(c*x^n)^(I*b))/(1 - E^(2*I*a)*(c*x^n)^(2*I*b)))]*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)]*Hypergeometric2F1[1/2, -((2*I + 2*I*m - b*n)/(4*b*n)), -((2*I + 2*I*m - 5*b*n)/(4*b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/((2 + 2*m + I*b*n)*(4*(1 + m)^2 + 9*b^2*n^2))}

{x^0/Csc[a + b*Log[c*x^n]]^(3/2), x, 2, (4*x)/((4 + 9*b^2*n^2)*Csc[a + b*Log[c*x^n]]^(3/2)) - (6*b*n*x*Cos[a + b*Log[c*x^n]])/((4 + 9*b^2*n^2)*Sqrt[Csc[a + b*Log[c*x^n]]]) + (6*Sqrt[2]*b^2*n^2*x*Sqrt[-((I*E^(I*a)*(c*x^n)^(I*b))/(1 - E^(2*I*a)*(c*x^n)^(2*I*b)))]*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)]*Hypergeometric2F1[1/2, (1/4)*(1 - (2*I)/(b*n)), (1/4)*(5 - (2*I)/(b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/((2 + I*b*n)*(4 + 9*b^2*n^2))}
{1/(x*Csc[a + b*Log[c*x^n]]^(3/2)), x, 4, -((2*Cos[a + b*Log[c*x^n]])/(3*b*n*Sqrt[Csc[a + b*Log[c*x^n]]])) - (2*Sqrt[Csc[a + b*Log[c*x^n]]]*EllipticF[Pi/4 + (1/2)*(-a - b*Log[c*x^n]), 2]*Sqrt[Sin[a + b*Log[c*x^n]]])/(3*b*n)}


{x^m/Csc[a + b*Log[c*x^n]]^(5/2), x, 2, (4*(1 + m)*x^(1 + m))/((4*(1 + m)^2 + 25*b^2*n^2)*Csc[a + b*Log[c*x^n]]^(5/2)) - (10*b*n*x^(1 + m)*Cos[a + b*Log[c*x^n]])/((4*(1 + m)^2 + 25*b^2*n^2)*Csc[a + b*Log[c*x^n]]^(3/2)) + (15*Sqrt[2]*b^2*n^2*x^(1 + m)*Hypergeometric2F1[-(1/2), -((2*I + 2*I*m + b*n)/(4*b*n)), -((2*I + 2*I*m - 3*b*n)/(4*b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/((2 + 2*m - I*b*n)*(4*(1 + m)^2 + 25*b^2*n^2)*Sqrt[-((I*E^(I*a)*(c*x^n)^(I*b))/(1 - E^(2*I*a)*(c*x^n)^(2*I*b)))]*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)])}

{x^0/Csc[a + b*Log[c*x^n]]^(5/2), x, 2, (4*x)/((4 + 25*b^2*n^2)*Csc[a + b*Log[c*x^n]]^(5/2)) - (10*b*n*x*Cos[a + b*Log[c*x^n]])/((4 + 25*b^2*n^2)*Csc[a + b*Log[c*x^n]]^(3/2)) + (15*I*Sqrt[2]*b^2*n^2*x*Hypergeometric2F1[-(1/2), -((2*I + b*n)/(4*b*n)), (1/4)*(3 - (2*I)/(b*n)), E^(2*I*a)*(c*x^n)^(2*I*b)])/((2*I + b*n)*(4 + 25*b^2*n^2)*Sqrt[-((I*E^(I*a)*(c*x^n)^(I*b))/(1 - E^(2*I*a)*(c*x^n)^(2*I*b)))]*Sqrt[1 - E^(2*I*a)*(c*x^n)^(2*I*b)])}
{1/(x*Csc[a + b*Log[c*x^n]]^(5/2)), x, 4, -((2*Cos[a + b*Log[c*x^n]])/(5*b*n*Csc[a + b*Log[c*x^n]]^(3/2))) - (6*Sqrt[Csc[a + b*Log[c*x^n]]]*EllipticE[Pi/4 + (1/2)*(-a - b*Log[c*x^n]), 2]*Sqrt[Sin[a + b*Log[c*x^n]]])/(5*b*n)}


(* ::Subsubsection::Closed:: *)
(*p symbolic*)


{x^m*Csc[a + b*Log[c*x^n]]^p, x, 1, (x^(1 + m)*(2 - 2*E^(2*I*a)*(c*x^n)^(2*I*b))^p*(-((I*E^(I*a)*(c*x^n)^(I*b))/(1 - E^(2*I*a)*(c*x^n)^(2*I*b))))^p*Hypergeometric2F1[p, -((I*(1 + m + I*b*n*p))/(2*b*n)), (1/2)*(2 - (I*(1 + m))/(b*n) + p), E^(2*I*a)*(c*x^n)^(2*I*b)])/(1 + m + I*b*n*p)}

{x^1*Csc[a + b*Log[c*x^n]]^p, x, 1, (x^2*(2 - 2*E^(2*I*a)*(c*x^n)^(2*I*b))^p*(-((I*E^(I*a)*(c*x^n)^(I*b))/(1 - E^(2*I*a)*(c*x^n)^(2*I*b))))^p*Hypergeometric2F1[p, (1/2)*(-((2*I)/(b*n)) + p), (1/2)*(2 - (2*I)/(b*n) + p), E^(2*I*a)*(c*x^n)^(2*I*b)])/(2 + I*b*n*p)}
{x^0*Csc[a + b*Log[c*x^n]]^p, x, 1, (x*(2 - 2*E^(2*I*a)*(c*x^n)^(2*I*b))^p*(-((I*E^(I*a)*(c*x^n)^(I*b))/(1 - E^(2*I*a)*(c*x^n)^(2*I*b))))^p*Hypergeometric2F1[p, -((I - b*n*p)/(2*b*n)), (1/2)*(2 - I/(b*n) + p), E^(2*I*a)*(c*x^n)^(2*I*b)])/(1 + I*b*n*p)}
