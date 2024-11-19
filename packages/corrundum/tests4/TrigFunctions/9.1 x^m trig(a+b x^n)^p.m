(* ::Package:: *)

(* ::Title:: *)
(*Integration problems of the form x^m Sin[a+b x^n]^p*)


(* ::Section::Closed:: *)
(*Integrands of the form x^m Sin[a+b x]^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Sin[a+b x]^p*)


{x^3*Sin[a + b*x], x, 4, (6*x*Cos[a + b*x])/b^3 - (x^3*Cos[a + b*x])/b - (6*Sin[a + b*x])/b^4 + (3*x^2*Sin[a + b*x])/b^2}
{x^2*Sin[a + b*x], x, 3, (2*Cos[a + b*x])/b^3 - (x^2*Cos[a + b*x])/b + (2*x*Sin[a + b*x])/b^2}
{x^1*Sin[a + b*x], x, 2, -((x*Cos[a + b*x])/b) + Sin[a + b*x]/b^2}
{x^0*Sin[a + b*x], x, 1, -(Cos[a + b*x]/b)}
{Sin[a + b*x]/x^1, x, 3, CosIntegral[b*x]*Sin[a] + Cos[a]*SinIntegral[b*x]}
{Sin[a + b*x]/x^2, x, 4, b*Cos[a]*CosIntegral[b*x] - Sin[a + b*x]/x - b*Sin[a]*SinIntegral[b*x]}
{Sin[a + b*x]/x^3, x, 5, -((b*Cos[a + b*x])/(2*x)) - (1/2)*b^2*CosIntegral[b*x]*Sin[a] - Sin[a + b*x]/(2*x^2) - (1/2)*b^2*Cos[a]*SinIntegral[b*x]}


{x^3*Sin[a + b*x]^2, x, 4, -((3*x^2)/(8*b^2)) + x^4/8 + (3*x*Cos[a + b*x]*Sin[a + b*x])/(4*b^3) - (x^3*Cos[a + b*x]*Sin[a + b*x])/(2*b) - (3*Sin[a + b*x]^2)/(8*b^4) + (3*x^2*Sin[a + b*x]^2)/(4*b^2)}
{x^2*Sin[a + b*x]^2, x, 3, -(x/(4*b^2)) + x^3/6 + (Cos[a + b*x]*Sin[a + b*x])/(4*b^3) - (x^2*Cos[a + b*x]*Sin[a + b*x])/(2*b) + (x*Sin[a + b*x]^2)/(2*b^2)}
{x^1*Sin[a + b*x]^2, x, 2, x^2/4 - (x*Cos[a + b*x]*Sin[a + b*x])/(2*b) + Sin[a + b*x]^2/(4*b^2)}
{x^0*Sin[a + b*x]^2, x, 1, x/2 - (Cos[a + b*x]*Sin[a + b*x])/(2*b)}
{Sin[a + b*x]^2/x^1, x, 5, (-(1/2))*Cos[2*a]*CosIntegral[2*b*x] + Log[x]/2 + (1/2)*Sin[2*a]*SinIntegral[2*b*x]}
{Sin[a + b*x]^2/x^2, x, 5, b*CosIntegral[2*b*x]*Sin[2*a] - Sin[a + b*x]^2/x + b*Cos[2*a]*SinIntegral[2*b*x]}
{Sin[a + b*x]^2/x^3, x, 7, b^2*Cos[2*a]*CosIntegral[2*b*x] - (b*Cos[a + b*x]*Sin[a + b*x])/x - Sin[a + b*x]^2/(2*x^2) - b^2*Sin[2*a]*SinIntegral[2*b*x]}


{x^3*Sin[a + b*x]^3, x, 8, (40*x*Cos[a + b*x])/(9*b^3) - (2*x^3*Cos[a + b*x])/(3*b) - (40*Sin[a + b*x])/(9*b^4) + (2*x^2*Sin[a + b*x])/b^2 + (2*x*Cos[a + b*x]*Sin[a + b*x]^2)/(9*b^3) - (x^3*Cos[a + b*x]*Sin[a + b*x]^2)/(3*b) - (2*Sin[a + b*x]^3)/(27*b^4) + (x^2*Sin[a + b*x]^3)/(3*b^2)}
{x^2*Sin[a + b*x]^3, x, 6, (14*Cos[a + b*x])/(9*b^3) - (2*x^2*Cos[a + b*x])/(3*b) - (2*Cos[a + b*x]^3)/(27*b^3) + (4*x*Sin[a + b*x])/(3*b^2) - (x^2*Cos[a + b*x]*Sin[a + b*x]^2)/(3*b) + (2*x*Sin[a + b*x]^3)/(9*b^2)}
{x^1*Sin[a + b*x]^3, x, 3, -((2*x*Cos[a + b*x])/(3*b)) + (2*Sin[a + b*x])/(3*b^2) - (x*Cos[a + b*x]*Sin[a + b*x]^2)/(3*b) + Sin[a + b*x]^3/(9*b^2)}
{x^0*Sin[a + b*x]^3, x, 2, -(Cos[a + b*x]/b) + Cos[a + b*x]^3/(3*b)}
{Sin[a + b*x]^3/x^1, x, 8, (3/4)*CosIntegral[b*x]*Sin[a] - (1/4)*CosIntegral[3*b*x]*Sin[3*a] + (3/4)*Cos[a]*SinIntegral[b*x] - (1/4)*Cos[3*a]*SinIntegral[3*b*x]}
{Sin[a + b*x]^3/x^2, x, 8, (3/4)*b*Cos[a]*CosIntegral[b*x] - (3/4)*b*Cos[3*a]*CosIntegral[3*b*x] - Sin[a + b*x]^3/x - (3/4)*b*Sin[a]*SinIntegral[b*x] + (3/4)*b*Sin[3*a]*SinIntegral[3*b*x]}
{Sin[a + b*x]^3/x^3, x, 12, (-(3/8))*b^2*CosIntegral[b*x]*Sin[a] + (9/8)*b^2*CosIntegral[3*b*x]*Sin[3*a] - (3*b*Cos[a + b*x]*Sin[a + b*x]^2)/(2*x) - Sin[a + b*x]^3/(2*x^2) - (3/8)*b^2*Cos[a]*SinIntegral[b*x] + (9/8)*b^2*Cos[3*a]*SinIntegral[3*b*x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Sin[a+b x]^(p/2)*)


{Sin[x]^(3/2)/x^3, x, 1, (3/8)*Int[1/(x*Sqrt[Sin[x]]), x] - (9/8)*Int[Sin[x]^(3/2)/x, x] - (3*Cos[x]*Sqrt[Sin[x]])/(4*x) - Sin[x]^(3/2)/(2*x^2)}


{x/Sin[x]^(3/2) + x*Sqrt[Sin[x]], x, 2, -((2*x*Cos[x])/Sqrt[Sin[x]]) + 4*Sqrt[Sin[x]]}
{x/Sin[x]^(5/2) - x/(3*Sqrt[Sin[x]]), x, 2, -((2*x*Cos[x])/(3*Sin[x]^(3/2))) - 4/(3*Sqrt[Sin[x]])}
{x/Sin[x]^(7/2) + (3/5)*x*Sqrt[Sin[x]], x, 3, -((2*x*Cos[x])/(5*Sin[x]^(5/2))) - 4/(15*Sin[x]^(3/2)) - (6*x*Cos[x])/(5*Sqrt[Sin[x]]) + (12*Sqrt[Sin[x]])/5}
{x^2/Sin[x]^(3/2) + x^2*Sqrt[Sin[x]], x, 3, 16*EllipticE[Pi/4 - x/2, 2] - (2*x^2*Cos[x])/Sqrt[Sin[x]] + 8*x*Sqrt[Sin[x]]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^(m/2) Sin[a+b x]^p*)


{Sin[x]/Sqrt[x], x, 2, Sqrt[2*Pi]*FresnelS[Sqrt[2/Pi]*Sqrt[x]]}
{Sqrt[x]*Sin[x], x, 3, -(Sqrt[x]*Cos[x]) + Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[x]]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^(m+n) Sin[a+b x]^p with m symbolic*)


{x^(m + 3)*Sin[a + b*x], x, 3, -((E^(I*a)*x^(3 + m)*((-I)*b*x)^(-3 - m)*Gamma[4 + m, (-I)*b*x])/(2*b)) - (x^(3 + m)*(I*b*x)^(-3 - m)*Gamma[4 + m, I*b*x])/(E^(I*a)*(2*b))}
{x^(m + 2)*Sin[a + b*x], x, 3, -((E^(I*a)*x^(2 + m)*((-I)*b*x)^(-2 - m)*Gamma[3 + m, (-I)*b*x])/(2*b)) - (x^(2 + m)*(I*b*x)^(-2 - m)*Gamma[3 + m, I*b*x])/(E^(I*a)*(2*b))}
{x^(m + 1)*Sin[a + b*x], x, 3, -((E^(I*a)*x^(1 + m)*((-I)*b*x)^(-1 - m)*Gamma[2 + m, (-I)*b*x])/(2*b)) - (x^(1 + m)*(I*b*x)^(-1 - m)*Gamma[2 + m, I*b*x])/(E^(I*a)*(2*b))}
{x^(m + 0)*Sin[a + b*x], x, 3, -((E^(I*a)*x^m*Gamma[1 + m, (-I)*b*x])/(((-I)*b*x)^m*(2*b))) - (x^m*Gamma[1 + m, I*b*x])/(E^(I*a)*(I*b*x)^m*(2*b))}
{x^(m - 1)*Sin[a + b*x], x, 3, ((1/2)*I*E^(I*a)*x^m*Gamma[m, (-I)*b*x])/((-I)*b*x)^m - ((1/2)*I*x^m*Gamma[m, I*b*x])/(E^(I*a)*(I*b*x)^m)}
{x^(m - 2)*Sin[a + b*x], x, 3, (1/2)*I*E^(I*a)*x^(-1 + m)*((-I)*b*x)^(1 - m)*Gamma[-1 + m, (-I)*b*x] - ((1/2)*I*x^(-1 + m)*(I*b*x)^(1 - m)*Gamma[-1 + m, I*b*x])/E^(I*a)}
{x^(m - 3)*Sin[a + b*x], x, 3, (1/2)*I*E^(I*a)*x^(-2 + m)*((-I)*b*x)^(2 - m)*Gamma[-2 + m, (-I)*b*x] - ((1/2)*I*x^(-2 + m)*(I*b*x)^(2 - m)*Gamma[-2 + m, I*b*x])/E^(I*a)}


{x^(m + 3)*Sin[a + b*x]^2, x, 5, x^(4 + m)/(2*(4 + m)) + (I*2^(-6 - m)*E^(2*I*a)*x^(3 + m)*((-I)*b*x)^(-3 - m)*Gamma[4 + m, -2*I*b*x])/b - (I*2^(-6 - m)*x^(3 + m)*(I*b*x)^(-3 - m)*Gamma[4 + m, 2*I*b*x])/(E^(2*I*a)*b)}
{x^(m + 2)*Sin[a + b*x]^2, x, 5, x^(3 + m)/(2*(3 + m)) + (I*2^(-5 - m)*E^(2*I*a)*x^(2 + m)*((-I)*b*x)^(-2 - m)*Gamma[3 + m, -2*I*b*x])/b - (I*2^(-5 - m)*x^(2 + m)*(I*b*x)^(-2 - m)*Gamma[3 + m, 2*I*b*x])/(E^(2*I*a)*b)}
{x^(m + 1)*Sin[a + b*x]^2, x, 5, x^(2 + m)/(2*(2 + m)) + (I*2^(-4 - m)*E^(2*I*a)*x^(1 + m)*((-I)*b*x)^(-1 - m)*Gamma[2 + m, -2*I*b*x])/b - (I*2^(-4 - m)*x^(1 + m)*(I*b*x)^(-1 - m)*Gamma[2 + m, 2*I*b*x])/(E^(2*I*a)*b)}
{x^(m + 0)*Sin[a + b*x]^2, x, 5, x^(1 + m)/(2*(1 + m)) + (I*2^(-3 - m)*E^(2*I*a)*x^m*Gamma[1 + m, -2*I*b*x])/(((-I)*b*x)^m*b) - (I*2^(-3 - m)*x^m*Gamma[1 + m, 2*I*b*x])/(E^(2*I*a)*(I*b*x)^m*b)}
{x^(m - 1)*Sin[a + b*x]^2, x, 5, x^m/(2*m) + (2^(-2 - m)*E^(2*I*a)*x^m*Gamma[m, -2*I*b*x])/((-I)*b*x)^m + (2^(-2 - m)*x^m*Gamma[m, 2*I*b*x])/(E^(2*I*a)*(I*b*x)^m)}
{x^(m - 2)*Sin[a + b*x]^2, x, 5, -(x^(-1 + m)/(2*(1 - m))) + 2^(-1 - m)*E^(2*I*a)*x^(-1 + m)*((-I)*b*x)^(1 - m)*Gamma[-1 + m, -2*I*b*x] + (2^(-1 - m)*x^(-1 + m)*(I*b*x)^(1 - m)*Gamma[-1 + m, 2*I*b*x])/E^(2*I*a)}
{x^(m - 3)*Sin[a + b*x]^2, x, 5, -(x^(-2 + m)/(2*(2 - m))) + (E^(2*I*a)*x^(-2 + m)*((-I)*b*x)^(2 - m)*Gamma[-2 + m, -2*I*b*x])/2^m + (x^(-2 + m)*(I*b*x)^(2 - m)*Gamma[-2 + m, 2*I*b*x])/(2^m*E^(2*I*a))}


(* ::Section::Closed:: *)
(*Integrands of the form (c+d x)^m Sin[a+b x]^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (c+d x)^m Sin[a+b x]^p*)


{Sin[a + b*x]*(c + d*x)^m, x, 3, (I*E^(I*(a - (b*c)/d))*(c + d*x)^(1 + m)*(-((I*b*(c + d*x))/d))^(-1 - m)*Gamma[1 + m, -((I*b*(c + d*x))/d)])/(2*d) - (I*(c + d*x)^(1 + m)*((I*b*(c + d*x))/d)^(-1 - m)*Gamma[1 + m, (I*b*(c + d*x))/d])/(E^(I*(a - (b*c)/d))*(2*d))}

{Sin[a + b*x]*(c + d*x)^4, x, 5, -((24*d^4*Cos[a + b*x])/b^5) + (12*d^2*(c + d*x)^2*Cos[a + b*x])/b^3 - ((c + d*x)^4*Cos[a + b*x])/b - (24*d^3*(c + d*x)*Sin[a + b*x])/b^4 + (4*d*(c + d*x)^3*Sin[a + b*x])/b^2}
{Sin[a + b*x]*(c + d*x)^3, x, 4, (6*d^2*(c + d*x)*Cos[a + b*x])/b^3 - ((c + d*x)^3*Cos[a + b*x])/b - (6*d^3*Sin[a + b*x])/b^4 + (3*d*(c + d*x)^2*Sin[a + b*x])/b^2}
{Sin[a + b*x]*(c + d*x)^2, x, 3, (2*d^2*Cos[a + b*x])/b^3 - ((c + d*x)^2*Cos[a + b*x])/b + (2*d*(c + d*x)*Sin[a + b*x])/b^2}
{Sin[a + b*x]*(c + d*x)^1, x, 2, -(((c + d*x)*Cos[a + b*x])/b) + (d*Sin[a + b*x])/b^2}
{Sin[a + b*x]*(c + d*x)^0, x, 1, -(Cos[a + b*x]/b)}
{Sin[a + b*x]/(c + d*x)^1, x, 3, (CosIntegral[(b*c)/d + b*x]*Sin[a - (b*c)/d])/d + (Cos[a - (b*c)/d]*SinIntegral[(b*c)/d + b*x])/d}
{Sin[a + b*x]/(c + d*x)^2, x, 4, (b*Cos[a - (b*c)/d]*CosIntegral[(b*c)/d + b*x])/d^2 - Sin[a + b*x]/(d*(c + d*x)) - (b*Sin[a - (b*c)/d]*SinIntegral[(b*c)/d + b*x])/d^2}
{Sin[a + b*x]/(c + d*x)^3, x, 5, -((b*Cos[a + b*x])/(2*d^2*(c + d*x))) - (b^2*CosIntegral[(b*c)/d + b*x]*Sin[a - (b*c)/d])/(2*d^3) - Sin[a + b*x]/(2*d*(c + d*x)^2) - (b^2*Cos[a - (b*c)/d]*SinIntegral[(b*c)/d + b*x])/(2*d^3)}


{Sin[a + b*x]^2*(c + d*x)^m, x, 5, (c + d*x)^(1 + m)/(2*d*(1 + m)) + (2^(-3 - m)*E^(2*I*(a - (b*c)/d))*(c + d*x)^(1 + m)*(-((I*b*(c + d*x))/d))^(-1 - m)*Gamma[1 + m, -((2*I*b*(c + d*x))/d)])/d + (2^(-3 - m)*(c + d*x)^(1 + m)*((I*b*(c + d*x))/d)^(-1 - m)*Gamma[1 + m, (2*I*b*(c + d*x))/d])/(E^(2*I*(a - (b*c)/d))*d)}

{Sin[a + b*x]^2*(c + d*x)^4, x, 5, (3*d^4*x)/(4*b^4) - (d*(c + d*x)^3)/(2*b^2) + (c + d*x)^5/(10*d) - (3*d^4*Cos[a + b*x]*Sin[a + b*x])/(4*b^5) + (3*d^2*(c + d*x)^2*Cos[a + b*x]*Sin[a + b*x])/(2*b^3) - ((c + d*x)^4*Cos[a + b*x]*Sin[a + b*x])/(2*b) - (3*d^3*(c + d*x)*Sin[a + b*x]^2)/(2*b^4) + (d*(c + d*x)^3*Sin[a + b*x]^2)/b^2}
{Sin[a + b*x]^2*(c + d*x)^3, x, 4, -((3*c*d^2*x)/(4*b^2)) - (3*d^3*x^2)/(8*b^2) + (c + d*x)^4/(8*d) + (3*d^2*(c + d*x)*Cos[a + b*x]*Sin[a + b*x])/(4*b^3) - ((c + d*x)^3*Cos[a + b*x]*Sin[a + b*x])/(2*b) - (3*d^3*Sin[a + b*x]^2)/(8*b^4) + (3*d*(c + d*x)^2*Sin[a + b*x]^2)/(4*b^2)}
{Sin[a + b*x]^2*(c + d*x)^2, x, 3, -((d^2*x)/(4*b^2)) + (c + d*x)^3/(6*d) + (d^2*Cos[a + b*x]*Sin[a + b*x])/(4*b^3) - ((c + d*x)^2*Cos[a + b*x]*Sin[a + b*x])/(2*b) + (d*(c + d*x)*Sin[a + b*x]^2)/(2*b^2)}
{Sin[a + b*x]^2*(c + d*x)^1, x, 2, (c*x)/2 + (d*x^2)/4 - ((c + d*x)*Cos[a + b*x]*Sin[a + b*x])/(2*b) + (d*Sin[a + b*x]^2)/(4*b^2)}
{Sin[a + b*x]^2*(c + d*x)^0, x, 1, x/2 - (Cos[a + b*x]*Sin[a + b*x])/(2*b)}
{Sin[a + b*x]^2/(c + d*x)^1, x, 5, -((Cos[2*a - (2*b*c)/d]*CosIntegral[(2*b*c)/d + 2*b*x])/(2*d)) + Log[c + d*x]/(2*d) + (Sin[2*a - (2*b*c)/d]*SinIntegral[(2*b*c)/d + 2*b*x])/(2*d)}
{Sin[a + b*x]^2/(c + d*x)^2, x, 5, (b*CosIntegral[(2*b*c)/d + 2*b*x]*Sin[2*a - (2*b*c)/d])/d^2 - Sin[a + b*x]^2/(d*(c + d*x)) + (b*Cos[2*a - (2*b*c)/d]*SinIntegral[(2*b*c)/d + 2*b*x])/d^2}
{Sin[a + b*x]^2/(c + d*x)^3, x, 7, (b^2*Cos[2*a - (2*b*c)/d]*CosIntegral[(2*b*c)/d + 2*b*x])/d^3 - (b*Cos[a + b*x]*Sin[a + b*x])/(d^2*(c + d*x)) - Sin[a + b*x]^2/(2*d*(c + d*x)^2) - (b^2*Sin[2*a - (2*b*c)/d]*SinIntegral[(2*b*c)/d + 2*b*x])/d^3}


{Sin[a + b*x]^3*(c + d*x)^m, x, 8, (3*I*E^(I*(a - (b*c)/d))*(c + d*x)^(1 + m)*(-((I*b*(c + d*x))/d))^(-1 - m)*Gamma[1 + m, -((I*b*(c + d*x))/d)])/(8*d) - (3*I*(c + d*x)^(1 + m)*((I*b*(c + d*x))/d)^(-1 - m)*Gamma[1 + m, (I*b*(c + d*x))/d])/(E^(I*(a - (b*c)/d))*(8*d)) - (I*3^(-1 - m)*E^(3*I*(a - (b*c)/d))*(c + d*x)^(1 + m)*(-((I*b*(c + d*x))/d))^(-1 - m)*Gamma[1 + m, -((3*I*b*(c + d*x))/d)])/(8*d) + (I*3^(-1 - m)*(c + d*x)^(1 + m)*((I*b*(c + d*x))/d)^(-1 - m)*Gamma[1 + m, (3*I*b*(c + d*x))/d])/(E^(3*I*(a - (b*c)/d))*(8*d))}

{Sin[a + b*x]^3*(c + d*x)^4, x, 12, -((488*d^4*Cos[a + b*x])/(27*b^5)) + (80*d^2*(c + d*x)^2*Cos[a + b*x])/(9*b^3) - (2*(c + d*x)^4*Cos[a + b*x])/(3*b) + (8*d^4*Cos[a + b*x]^3)/(81*b^5) - (160*d^3*(c + d*x)*Sin[a + b*x])/(9*b^4) + (8*d*(c + d*x)^3*Sin[a + b*x])/(3*b^2) + (4*d^2*(c + d*x)^2*Cos[a + b*x]*Sin[a + b*x]^2)/(9*b^3) - ((c + d*x)^4*Cos[a + b*x]*Sin[a + b*x]^2)/(3*b) - (8*d^3*(c + d*x)*Sin[a + b*x]^3)/(27*b^4) + (4*d*(c + d*x)^3*Sin[a + b*x]^3)/(9*b^2)}
{Sin[a + b*x]^3*(c + d*x)^3, x, 8, (40*d^2*(c + d*x)*Cos[a + b*x])/(9*b^3) - (2*(c + d*x)^3*Cos[a + b*x])/(3*b) - (40*d^3*Sin[a + b*x])/(9*b^4) + (2*d*(c + d*x)^2*Sin[a + b*x])/b^2 + (2*d^2*(c + d*x)*Cos[a + b*x]*Sin[a + b*x]^2)/(9*b^3) - ((c + d*x)^3*Cos[a + b*x]*Sin[a + b*x]^2)/(3*b) - (2*d^3*Sin[a + b*x]^3)/(27*b^4) + (d*(c + d*x)^2*Sin[a + b*x]^3)/(3*b^2)}
{Sin[a + b*x]^3*(c + d*x)^2, x, 6, (14*d^2*Cos[a + b*x])/(9*b^3) - (2*(c + d*x)^2*Cos[a + b*x])/(3*b) - (2*d^2*Cos[a + b*x]^3)/(27*b^3) + (4*d*(c + d*x)*Sin[a + b*x])/(3*b^2) - ((c + d*x)^2*Cos[a + b*x]*Sin[a + b*x]^2)/(3*b) + (2*d*(c + d*x)*Sin[a + b*x]^3)/(9*b^2)}
{Sin[a + b*x]^3*(c + d*x)^1, x, 3, -((2*(c + d*x)*Cos[a + b*x])/(3*b)) + (2*d*Sin[a + b*x])/(3*b^2) - ((c + d*x)*Cos[a + b*x]*Sin[a + b*x]^2)/(3*b) + (d*Sin[a + b*x]^3)/(9*b^2)}
{Sin[a + b*x]^3*(c + d*x)^0, x, 2, -(Cos[a + b*x]/b) + Cos[a + b*x]^3/(3*b)}
{Sin[a + b*x]^3/(c + d*x)^1, x, 8, -((CosIntegral[(3*b*c)/d + 3*b*x]*Sin[3*a - (3*b*c)/d])/(4*d)) + (3*CosIntegral[(b*c)/d + b*x]*Sin[a - (b*c)/d])/(4*d) + (3*Cos[a - (b*c)/d]*SinIntegral[(b*c)/d + b*x])/(4*d) - (Cos[3*a - (3*b*c)/d]*SinIntegral[(3*b*c)/d + 3*b*x])/(4*d)}
{Sin[a + b*x]^3/(c + d*x)^2, x, 8, (3*b*Cos[a - (b*c)/d]*CosIntegral[(b*c)/d + b*x])/(4*d^2) - (3*b*Cos[3*a - (3*b*c)/d]*CosIntegral[(3*b*c)/d + 3*b*x])/(4*d^2) - Sin[a + b*x]^3/(d*(c + d*x)) - (3*b*Sin[a - (b*c)/d]*SinIntegral[(b*c)/d + b*x])/(4*d^2) + (3*b*Sin[3*a - (3*b*c)/d]*SinIntegral[(3*b*c)/d + 3*b*x])/(4*d^2)}
{Sin[a + b*x]^3/(c + d*x)^3, x, 12, (9*b^2*CosIntegral[(3*b*c)/d + 3*b*x]*Sin[3*a - (3*b*c)/d])/(8*d^3) - (3*b^2*CosIntegral[(b*c)/d + b*x]*Sin[a - (b*c)/d])/(8*d^3) - (3*b*Cos[a + b*x]*Sin[a + b*x]^2)/(2*d^2*(c + d*x)) - Sin[a + b*x]^3/(2*d*(c + d*x)^2) - (3*b^2*Cos[a - (b*c)/d]*SinIntegral[(b*c)/d + b*x])/(8*d^3) + (9*b^2*Cos[3*a - (3*b*c)/d]*SinIntegral[(3*b*c)/d + 3*b*x])/(8*d^3)}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c+d x)^(m/2) Sin[a+b x]^p*)


{Sin[a + b*x]*(c + d*x)^(5/2), x, 8, (15*d^2*Sqrt[c + d*x]*Cos[a + b*x])/(4*b^3) - ((c + d*x)^(5/2)*Cos[a + b*x])/b - (15*d^(5/2)*Sqrt[Pi/2]*Cos[a - (b*c)/d]*FresnelC[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]])/(4*b^(7/2)) + (15*d^(5/2)*Sqrt[Pi/2]*FresnelS[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]]*Sin[a - (b*c)/d])/(4*b^(7/2)) + (5*d*(c + d*x)^(3/2)*Sin[a + b*x])/(2*b^2)}
{Sin[a + b*x]*(c + d*x)^(3/2), x, 7, -(((c + d*x)^(3/2)*Cos[a + b*x])/b) - (3*d^(3/2)*Sqrt[Pi/2]*Cos[a - (b*c)/d]*FresnelS[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]])/(2*b^(5/2)) - (3*d^(3/2)*Sqrt[Pi/2]*FresnelC[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]]*Sin[a - (b*c)/d])/(2*b^(5/2)) + (3*d*Sqrt[c + d*x]*Sin[a + b*x])/(2*b^2)}
{Sin[a + b*x]*(c + d*x)^(1/2), x, 6, -((Sqrt[c + d*x]*Cos[a + b*x])/b) + (Sqrt[d]*Sqrt[Pi/2]*Cos[a - (b*c)/d]*FresnelC[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]])/b^(3/2) - (Sqrt[d]*Sqrt[Pi/2]*FresnelS[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]]*Sin[a - (b*c)/d])/b^(3/2)}
{Sin[a + b*x]/(c + d*x)^(1/2), x, 5, (Sqrt[2*Pi]*Cos[a - (b*c)/d]*FresnelS[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]])/(Sqrt[b]*Sqrt[d]) + (Sqrt[2*Pi]*FresnelC[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]]*Sin[a - (b*c)/d])/(Sqrt[b]*Sqrt[d])}
{Sin[a + b*x]/(c + d*x)^(3/2), x, 6, (2*Sqrt[b]*Sqrt[2*Pi]*Cos[a - (b*c)/d]*FresnelC[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]])/d^(3/2) - (2*Sqrt[b]*Sqrt[2*Pi]*FresnelS[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]]*Sin[a - (b*c)/d])/d^(3/2) - (2*Sin[a + b*x])/(d*Sqrt[c + d*x])}
{Sin[a + b*x]/(c + d*x)^(5/2), x, 7, -((4*b*Cos[a + b*x])/(3*d^2*Sqrt[c + d*x])) - (4*b^(3/2)*Sqrt[2*Pi]*Cos[a - (b*c)/d]*FresnelS[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]])/(3*d^(5/2)) - (4*b^(3/2)*Sqrt[2*Pi]*FresnelC[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]]*Sin[a - (b*c)/d])/(3*d^(5/2)) - (2*Sin[a + b*x])/(3*d*(c + d*x)^(3/2))}
{Sin[a + b*x]/(c + d*x)^(7/2), x, 8, -((4*b*Cos[a + b*x])/(15*d^2*(c + d*x)^(3/2))) - (8*b^(5/2)*Sqrt[2*Pi]*Cos[a - (b*c)/d]*FresnelC[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]])/(15*d^(7/2)) + (8*b^(5/2)*Sqrt[2*Pi]*FresnelS[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]]*Sin[a - (b*c)/d])/(15*d^(7/2)) - (2*Sin[a + b*x])/(5*d*(c + d*x)^(5/2)) + (8*b^2*Sin[a + b*x])/(15*d^3*Sqrt[c + d*x])}


{Sin[a + b*x]^2*(c + d*x)^(5/2), x, 10, -((5*d*(c + d*x)^(3/2))/(16*b^2)) + (c + d*x)^(7/2)/(7*d) - (15*d^(5/2)*Sqrt[Pi]*Cos[2*a - (2*b*c)/d]*FresnelS[(2*Sqrt[b]*Sqrt[c + d*x])/(Sqrt[d]*Sqrt[Pi])])/(128*b^(7/2)) - (15*d^(5/2)*Sqrt[Pi]*FresnelC[(2*Sqrt[b]*Sqrt[c + d*x])/(Sqrt[d]*Sqrt[Pi])]*Sin[2*a - (2*b*c)/d])/(128*b^(7/2)) - ((c + d*x)^(5/2)*Cos[a + b*x]*Sin[a + b*x])/(2*b) + (5*d*(c + d*x)^(3/2)*Sin[a + b*x]^2)/(8*b^2) + (15*d^2*Sqrt[c + d*x]*Sin[2*a + 2*b*x])/(64*b^3)}
{Sin[a + b*x]^2*(c + d*x)^(3/2), x, 9, -((3*d*Sqrt[c + d*x])/(16*b^2)) + (c + d*x)^(5/2)/(5*d) + (3*d^(3/2)*Sqrt[Pi]*Cos[2*a - (2*b*c)/d]*FresnelC[(2*Sqrt[b]*Sqrt[c + d*x])/(Sqrt[d]*Sqrt[Pi])])/(32*b^(5/2)) - (3*d^(3/2)*Sqrt[Pi]*FresnelS[(2*Sqrt[b]*Sqrt[c + d*x])/(Sqrt[d]*Sqrt[Pi])]*Sin[2*a - (2*b*c)/d])/(32*b^(5/2)) - ((c + d*x)^(3/2)*Cos[a + b*x]*Sin[a + b*x])/(2*b) + (3*d*Sqrt[c + d*x]*Sin[a + b*x]^2)/(8*b^2)}
{Sin[a + b*x]^2*(c + d*x)^(1/2), x, 8, (c + d*x)^(3/2)/(3*d) + (Sqrt[d]*Sqrt[Pi]*Cos[2*a - (2*b*c)/d]*FresnelS[(2*Sqrt[b]*Sqrt[c + d*x])/(Sqrt[d]*Sqrt[Pi])])/(8*b^(3/2)) + (Sqrt[d]*Sqrt[Pi]*FresnelC[(2*Sqrt[b]*Sqrt[c + d*x])/(Sqrt[d]*Sqrt[Pi])]*Sin[2*a - (2*b*c)/d])/(8*b^(3/2)) - (Sqrt[c + d*x]*Sin[2*a + 2*b*x])/(4*b)}
{Sin[a + b*x]^2/(c + d*x)^(1/2), x, 7, Sqrt[c + d*x]/d - (Sqrt[Pi]*Cos[2*a - (2*b*c)/d]*FresnelC[(2*Sqrt[b]*Sqrt[c + d*x])/(Sqrt[d]*Sqrt[Pi])])/(2*Sqrt[b]*Sqrt[d]) + (Sqrt[Pi]*FresnelS[(2*Sqrt[b]*Sqrt[c + d*x])/(Sqrt[d]*Sqrt[Pi])]*Sin[2*a - (2*b*c)/d])/(2*Sqrt[b]*Sqrt[d])}
{Sin[a + b*x]^2/(c + d*x)^(3/2), x, 7, (2*Sqrt[b]*Sqrt[Pi]*Cos[2*a - (2*b*c)/d]*FresnelS[(2*Sqrt[b]*Sqrt[c + d*x])/(Sqrt[d]*Sqrt[Pi])])/d^(3/2) + (2*Sqrt[b]*Sqrt[Pi]*FresnelC[(2*Sqrt[b]*Sqrt[c + d*x])/(Sqrt[d]*Sqrt[Pi])]*Sin[2*a - (2*b*c)/d])/d^(3/2) - (2*Sin[a + b*x]^2)/(d*Sqrt[c + d*x])}
{Sin[a + b*x]^2/(c + d*x)^(5/2), x, 9, (8*b^(3/2)*Sqrt[Pi]*Cos[2*a - (2*b*c)/d]*FresnelC[(2*Sqrt[b]*Sqrt[c + d*x])/(Sqrt[d]*Sqrt[Pi])])/(3*d^(5/2)) - (8*b^(3/2)*Sqrt[Pi]*FresnelS[(2*Sqrt[b]*Sqrt[c + d*x])/(Sqrt[d]*Sqrt[Pi])]*Sin[2*a - (2*b*c)/d])/(3*d^(5/2)) - (8*b*Cos[a + b*x]*Sin[a + b*x])/(3*d^2*Sqrt[c + d*x]) - (2*Sin[a + b*x]^2)/(3*d*(c + d*x)^(3/2))}
{Sin[a + b*x]^2/(c + d*x)^(7/2), x, 9, -((16*b^2)/(15*d^3*Sqrt[c + d*x])) - (32*b^(5/2)*Sqrt[Pi]*Cos[2*a - (2*b*c)/d]*FresnelS[(2*Sqrt[b]*Sqrt[c + d*x])/(Sqrt[d]*Sqrt[Pi])])/(15*d^(7/2)) - (32*b^(5/2)*Sqrt[Pi]*FresnelC[(2*Sqrt[b]*Sqrt[c + d*x])/(Sqrt[d]*Sqrt[Pi])]*Sin[2*a - (2*b*c)/d])/(15*d^(7/2)) - (8*b*Cos[a + b*x]*Sin[a + b*x])/(15*d^2*(c + d*x)^(3/2)) - (2*Sin[a + b*x]^2)/(5*d*(c + d*x)^(5/2)) + (32*b^2*Sin[a + b*x]^2)/(15*d^3*Sqrt[c + d*x])}
{Sin[a + b*x]^2/(c + d*x)^(9/2), x, 11, -((16*b^2)/(105*d^3*(c + d*x)^(3/2))) - (128*b^(7/2)*Sqrt[Pi]*Cos[2*a - (2*b*c)/d]*FresnelC[(2*Sqrt[b]*Sqrt[c + d*x])/(Sqrt[d]*Sqrt[Pi])])/(105*d^(9/2)) + (128*b^(7/2)*Sqrt[Pi]*FresnelS[(2*Sqrt[b]*Sqrt[c + d*x])/(Sqrt[d]*Sqrt[Pi])]*Sin[2*a - (2*b*c)/d])/(105*d^(9/2)) - (8*b*Cos[a + b*x]*Sin[a + b*x])/(35*d^2*(c + d*x)^(5/2)) + (128*b^3*Cos[a + b*x]*Sin[a + b*x])/(105*d^4*Sqrt[c + d*x]) - (2*Sin[a + b*x]^2)/(7*d*(c + d*x)^(7/2)) + (32*b^2*Sin[a + b*x]^2)/(105*d^3*(c + d*x)^(3/2))}


{Sin[a + b*x]^3*(c + d*x)^(5/2), x, 23, (45*d^2*Sqrt[c + d*x]*Cos[a + b*x])/(16*b^3) - (2*(c + d*x)^(5/2)*Cos[a + b*x])/(3*b) - (5*d^2*Sqrt[c + d*x]*Cos[3*a + 3*b*x])/(144*b^3) - (45*d^(5/2)*Sqrt[Pi/2]*Cos[a - (b*c)/d]*FresnelC[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]])/(16*b^(7/2)) + (5*d^(5/2)*Sqrt[Pi/6]*Cos[3*a - (3*b*c)/d]*FresnelC[(Sqrt[b]*Sqrt[6/Pi]*Sqrt[c + d*x])/Sqrt[d]])/(144*b^(7/2)) - (5*d^(5/2)*Sqrt[Pi/6]*FresnelS[(Sqrt[b]*Sqrt[6/Pi]*Sqrt[c + d*x])/Sqrt[d]]*Sin[3*a - (3*b*c)/d])/(144*b^(7/2)) + (45*d^(5/2)*Sqrt[Pi/2]*FresnelS[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]]*Sin[a - (b*c)/d])/(16*b^(7/2)) + (5*d*(c + d*x)^(3/2)*Sin[a + b*x])/(3*b^2) - ((c + d*x)^(5/2)*Cos[a + b*x]*Sin[a + b*x]^2)/(3*b) + (5*d*(c + d*x)^(3/2)*Sin[a + b*x]^3)/(18*b^2)}
{Sin[a + b*x]^3*(c + d*x)^(3/2), x, 20, -((2*(c + d*x)^(3/2)*Cos[a + b*x])/(3*b)) - (9*d^(3/2)*Sqrt[Pi/2]*Cos[a - (b*c)/d]*FresnelS[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]])/(8*b^(5/2)) + (d^(3/2)*Sqrt[Pi/6]*Cos[3*a - (3*b*c)/d]*FresnelS[(Sqrt[b]*Sqrt[6/Pi]*Sqrt[c + d*x])/Sqrt[d]])/(24*b^(5/2)) + (d^(3/2)*Sqrt[Pi/6]*FresnelC[(Sqrt[b]*Sqrt[6/Pi]*Sqrt[c + d*x])/Sqrt[d]]*Sin[3*a - (3*b*c)/d])/(24*b^(5/2)) - (9*d^(3/2)*Sqrt[Pi/2]*FresnelC[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]]*Sin[a - (b*c)/d])/(8*b^(5/2)) + (d*Sqrt[c + d*x]*Sin[a + b*x])/b^2 - ((c + d*x)^(3/2)*Cos[a + b*x]*Sin[a + b*x]^2)/(3*b) + (d*Sqrt[c + d*x]*Sin[a + b*x]^3)/(6*b^2)}
{Sin[a + b*x]^3*(c + d*x)^(1/2), x, 14, -((3*Sqrt[c + d*x]*Cos[a + b*x])/(4*b)) + (Sqrt[c + d*x]*Cos[3*a + 3*b*x])/(12*b) + (3*Sqrt[d]*Sqrt[Pi/2]*Cos[a - (b*c)/d]*FresnelC[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]])/(4*b^(3/2)) - (Sqrt[d]*Sqrt[Pi/6]*Cos[3*a - (3*b*c)/d]*FresnelC[(Sqrt[b]*Sqrt[6/Pi]*Sqrt[c + d*x])/Sqrt[d]])/(12*b^(3/2)) + (Sqrt[d]*Sqrt[Pi/6]*FresnelS[(Sqrt[b]*Sqrt[6/Pi]*Sqrt[c + d*x])/Sqrt[d]]*Sin[3*a - (3*b*c)/d])/(12*b^(3/2)) - (3*Sqrt[d]*Sqrt[Pi/2]*FresnelS[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]]*Sin[a - (b*c)/d])/(4*b^(3/2))}
{Sin[a + b*x]^3/(c + d*x)^(1/2), x, 12, (3*Sqrt[Pi/2]*Cos[a - (b*c)/d]*FresnelS[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]])/(2*Sqrt[b]*Sqrt[d]) - (Sqrt[Pi/6]*Cos[3*a - (3*b*c)/d]*FresnelS[(Sqrt[b]*Sqrt[6/Pi]*Sqrt[c + d*x])/Sqrt[d]])/(2*Sqrt[b]*Sqrt[d]) - (Sqrt[Pi/6]*FresnelC[(Sqrt[b]*Sqrt[6/Pi]*Sqrt[c + d*x])/Sqrt[d]]*Sin[3*a - (3*b*c)/d])/(2*Sqrt[b]*Sqrt[d]) + (3*Sqrt[Pi/2]*FresnelC[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]]*Sin[a - (b*c)/d])/(2*Sqrt[b]*Sqrt[d])}
{Sin[a + b*x]^3/(c + d*x)^(3/2), x, 12, (3*Sqrt[b]*Sqrt[Pi/2]*Cos[a - (b*c)/d]*FresnelC[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]])/d^(3/2) - (Sqrt[b]*Sqrt[(3*Pi)/2]*Cos[3*a - (3*b*c)/d]*FresnelC[(Sqrt[b]*Sqrt[6/Pi]*Sqrt[c + d*x])/Sqrt[d]])/d^(3/2) + (Sqrt[b]*Sqrt[(3*Pi)/2]*FresnelS[(Sqrt[b]*Sqrt[6/Pi]*Sqrt[c + d*x])/Sqrt[d]]*Sin[3*a - (3*b*c)/d])/d^(3/2) - (3*Sqrt[b]*Sqrt[Pi/2]*FresnelS[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]]*Sin[a - (b*c)/d])/d^(3/2) - (2*Sin[a + b*x]^3)/(d*Sqrt[c + d*x])}
{Sin[a + b*x]^3/(c + d*x)^(5/2), x, 18, -((b^(3/2)*Sqrt[2*Pi]*Cos[a - (b*c)/d]*FresnelS[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]])/d^(5/2)) + (b^(3/2)*Sqrt[6*Pi]*Cos[3*a - (3*b*c)/d]*FresnelS[(Sqrt[b]*Sqrt[6/Pi]*Sqrt[c + d*x])/Sqrt[d]])/d^(5/2) + (b^(3/2)*Sqrt[6*Pi]*FresnelC[(Sqrt[b]*Sqrt[6/Pi]*Sqrt[c + d*x])/Sqrt[d]]*Sin[3*a - (3*b*c)/d])/d^(5/2) - (b^(3/2)*Sqrt[2*Pi]*FresnelC[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]]*Sin[a - (b*c)/d])/d^(5/2) - (4*b*Cos[a + b*x]*Sin[a + b*x]^2)/(d^2*Sqrt[c + d*x]) - (2*Sin[a + b*x]^3)/(3*d*(c + d*x)^(3/2))}
{Sin[a + b*x]^3/(c + d*x)^(7/2), x, 19, -((2*b^(5/2)*Sqrt[2*Pi]*Cos[a - (b*c)/d]*FresnelC[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]])/(5*d^(7/2))) + (6*b^(5/2)*Sqrt[6*Pi]*Cos[3*a - (3*b*c)/d]*FresnelC[(Sqrt[b]*Sqrt[6/Pi]*Sqrt[c + d*x])/Sqrt[d]])/(5*d^(7/2)) - (6*b^(5/2)*Sqrt[6*Pi]*FresnelS[(Sqrt[b]*Sqrt[6/Pi]*Sqrt[c + d*x])/Sqrt[d]]*Sin[3*a - (3*b*c)/d])/(5*d^(7/2)) + (2*b^(5/2)*Sqrt[2*Pi]*FresnelS[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]]*Sin[a - (b*c)/d])/(5*d^(7/2)) - (16*b^2*Sin[a + b*x])/(5*d^3*Sqrt[c + d*x]) - (4*b*Cos[a + b*x]*Sin[a + b*x]^2)/(5*d^2*(c + d*x)^(3/2)) - (2*Sin[a + b*x]^3)/(5*d*(c + d*x)^(5/2)) + (24*b^2*Sin[a + b*x]^3)/(5*d^3*Sqrt[c + d*x])}


(* ::Section::Closed:: *)
(*Integrands of the form x^m Sin[a+b x^2]^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Sin[a+b x^2]^p*)


{x^3*Sin[a + b*x^2], x, 2, -((x^2*Cos[a + b*x^2])/(2*b)) + Sin[a + b*x^2]/(2*b^2)}
{x^2*Sin[a + b*x^2], x, 4, -((x*Cos[a + b*x^2])/(2*b)) + (Sqrt[Pi/2]*Cos[a]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*x])/(2*b^(3/2)) - (Sqrt[Pi/2]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*x]*Sin[a])/(2*b^(3/2))}
{x^1*Sin[a + b*x^2], x, 1, -(Cos[a + b*x^2]/(2*b))}
{x^0*Sin[a + b*x^2], x, 3, (Sqrt[Pi/2]*Cos[a]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*x])/Sqrt[b] + (Sqrt[Pi/2]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*x]*Sin[a])/Sqrt[b]}
{Sin[a + b*x^2]/x^1, x, 3, (1/2)*CosIntegral[b*x^2]*Sin[a] + (1/2)*Cos[a]*SinIntegral[b*x^2]}
{Sin[a + b*x^2]/x^2, x, 4, Sqrt[b]*Sqrt[2*Pi]*Cos[a]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*x] - Sqrt[b]*Sqrt[2*Pi]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*x]*Sin[a] - Sin[a + b*x^2]/x}
{Sin[a + b*x^2]/x^3, x, 4, (1/2)*b*Cos[a]*CosIntegral[b*x^2] - Sin[a + b*x^2]/(2*x^2) - (1/2)*b*Sin[a]*SinIntegral[b*x^2]}


{x^3*Sin[a + b*x^2]^2, x, 2, x^4/8 - (x^2*Cos[a + b*x^2]*Sin[a + b*x^2])/(4*b) + Sin[a + b*x^2]^2/(8*b^2)}
{x^2*Sin[a + b*x^2]^2, x, 6, x^3/6 + (Sqrt[Pi]*Cos[2*a]*FresnelS[(2*Sqrt[b]*x)/Sqrt[Pi]])/(16*b^(3/2)) + (Sqrt[Pi]*FresnelC[(2*Sqrt[b]*x)/Sqrt[Pi]]*Sin[2*a])/(16*b^(3/2)) - (x*Sin[2*a + 2*b*x^2])/(8*b)}
{x^1*Sin[a + b*x^2]^2, x, 2, x^2/4 - (Cos[a + b*x^2]*Sin[a + b*x^2])/(4*b)}
{x^0*Sin[a + b*x^2]^2, x, 5, x/2 - (Sqrt[Pi]*Cos[2*a]*FresnelC[(2*Sqrt[b]*x)/Sqrt[Pi]])/(4*Sqrt[b]) + (Sqrt[Pi]*FresnelS[(2*Sqrt[b]*x)/Sqrt[Pi]]*Sin[2*a])/(4*Sqrt[b])}
{Sin[a + b*x^2]^2/x^1, x, 5, (-(1/4))*Cos[2*a]*CosIntegral[2*b*x^2] + Log[x]/2 + (1/4)*Sin[2*a]*SinIntegral[2*b*x^2]}
{Sin[a + b*x^2]^2/x^2, x, 5, -(Sin[a + b*x^2]^2/x) + Sqrt[b]*Sqrt[Pi]*Cos[2*a]*FresnelS[(2*Sqrt[b]*x)/Sqrt[Pi]] + Sqrt[b]*Sqrt[Pi]*FresnelC[(2*Sqrt[b]*x)/Sqrt[Pi]]*Sin[2*a]}
{Sin[a + b*x^2]^2/x^3, x, 6, -(1/(4*x^2)) + Cos[2*a + 2*b*x^2]/(4*x^2) + (1/2)*b*CosIntegral[2*b*x^2]*Sin[2*a] + (1/2)*b*Cos[2*a]*SinIntegral[2*b*x^2]}


{x^3*Sin[a + b*x^2]^3, x, 3, -((x^2*Cos[a + b*x^2])/(3*b)) + Sin[a + b*x^2]/(3*b^2) - (x^2*Cos[a + b*x^2]*Sin[a + b*x^2]^2)/(6*b) + Sin[a + b*x^2]^3/(18*b^2)}
{x^2*Sin[a + b*x^2]^3, x, 10, -((3*x*Cos[a + b*x^2])/(8*b)) + (x*Cos[3*a + 3*b*x^2])/(24*b) + (3*Sqrt[Pi/2]*Cos[a]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*x])/(8*b^(3/2)) - (Sqrt[Pi/6]*Cos[3*a]*FresnelC[Sqrt[b]*Sqrt[6/Pi]*x])/(24*b^(3/2)) - (3*Sqrt[Pi/2]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*x]*Sin[a])/(8*b^(3/2)) + (Sqrt[Pi/6]*FresnelS[Sqrt[b]*Sqrt[6/Pi]*x]*Sin[3*a])/(24*b^(3/2))}
{x^1*Sin[a + b*x^2]^3, x, 3, -(Cos[a + b*x^2]/(2*b)) + Cos[a + b*x^2]^3/(6*b)}
{x^0*Sin[a + b*x^2]^3, x, 8, (3*Sqrt[Pi/2]*Cos[a]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*x])/(4*Sqrt[b]) - (Sqrt[Pi/6]*Cos[3*a]*FresnelS[Sqrt[b]*Sqrt[6/Pi]*x])/(4*Sqrt[b]) + (3*Sqrt[Pi/2]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*x]*Sin[a])/(4*Sqrt[b]) - (Sqrt[Pi/6]*FresnelC[Sqrt[b]*Sqrt[6/Pi]*x]*Sin[3*a])/(4*Sqrt[b])}
{Sin[a + b*x^2]^3/x^1, x, 8, (3/8)*CosIntegral[b*x^2]*Sin[a] - (1/8)*CosIntegral[3*b*x^2]*Sin[3*a] + (3/8)*Cos[a]*SinIntegral[b*x^2] - (1/8)*Cos[3*a]*SinIntegral[3*b*x^2]}
{Sin[a + b*x^2]^3/x^2, x, 9, (3/2)*Sqrt[b]*Sqrt[Pi/2]*Cos[a]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*x] - (1/2)*Sqrt[b]*Sqrt[(3*Pi)/2]*Cos[3*a]*FresnelC[Sqrt[b]*Sqrt[6/Pi]*x] - (3/2)*Sqrt[b]*Sqrt[Pi/2]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*x]*Sin[a] + (1/2)*Sqrt[b]*Sqrt[(3*Pi)/2]*FresnelS[Sqrt[b]*Sqrt[6/Pi]*x]*Sin[3*a] - Sin[a + b*x^2]^3/x}
{Sin[a + b*x^2]^3/x^3, x, 10, (3/8)*b*Cos[a]*CosIntegral[b*x^2] - (3/8)*b*Cos[3*a]*CosIntegral[3*b*x^2] - (3*Sin[a + b*x^2])/(8*x^2) + Sin[3*a + 3*b*x^2]/(8*x^2) - (3/8)*b*Sin[a]*SinIntegral[b*x^2] + (3/8)*b*Sin[3*a]*SinIntegral[3*b*x^2]}


{x^2*Sin[x^2]^3, x, 6, (-(1/2))*x*Cos[x^2] + (1/6)*x*Cos[x^2]^3 + (3/8)*Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*x] - (1/24)*Sqrt[Pi/6]*FresnelC[Sqrt[6/Pi]*x], (-(3/8))*x*Cos[x^2] + (1/24)*x*Cos[3*x^2] + (3/8)*Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*x] - (1/24)*Sqrt[Pi/6]*FresnelC[Sqrt[6/Pi]*x]}
{x^4*Cos[x^2]*Sin[x^2]^2, x, 7, (1/4)*x*Cos[x^2] - (1/12)*x*Cos[x^2]^3 - (3/16)*Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*x] + (1/48)*Sqrt[Pi/6]*FresnelC[Sqrt[6/Pi]*x] + (1/6)*x^3*Sin[x^2]^3, (3/16)*x*Cos[x^2] - (1/48)*x*Cos[3*x^2] - (3/16)*Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*x] + (1/48)*Sqrt[Pi/6]*FresnelC[Sqrt[6/Pi]*x] + (1/6)*x^3*Sin[x^2]^3}


{x*Sin[a + b*x^2]^7, x, 3, -(Cos[a + b*x^2]/(2*b)) + Cos[a + b*x^2]^3/(2*b) - (3*Cos[a + b*x^2]^5)/(10*b) + Cos[a + b*x^2]^7/(14*b)}


(* ::Subsection:: *)
(*Integrands of the form x^m Sin[a+b x^2]^(p/2)*)


(* ::Subsection:: *)
(*Integrands of the form x^(m/2) Sin[a+b x^2]^p*)


(* ::Subsection:: *)
(*Integrands of the form x^(m/2) Sin[a+b x^2]^(p/2)*)


(* ::Section::Closed:: *)
(*Integrands of the form x^m Sin[a+b / x^n]^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Sin[a+b / x]^p*)


{Sin[a + b/x], x, 5, (-b)*Cos[a]*CosIntegral[b/x] + x*Sin[a + b/x] + b*Sin[a]*SinIntegral[b/x]}
{Sin[a + b/x]/x, x, 3, (-CosIntegral[b/x])*Sin[a] - Cos[a]*SinIntegral[b/x]}
{Sin[a + b/x]/x^2, x, 1, Cos[a + b/x]/b}
{Sin[a + b/x]/x^3, x, 2, Cos[a + b/x]/(b*x) - Sin[a + b/x]/b^2}
{Sin[a + b/x]/x^4, x, 3, -((2*Cos[a + b/x])/b^3) + Cos[a + b/x]/(b*x^2) - (2*Sin[a + b/x])/(b^2*x)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Sin[a+b / x^2]^p*)


{Sin[a + b/x^2], x, 5, (-Sqrt[b])*Sqrt[2*Pi]*Cos[a]*FresnelC[(Sqrt[b]*Sqrt[2/Pi])/x] + Sqrt[b]*Sqrt[2*Pi]*FresnelS[(Sqrt[b]*Sqrt[2/Pi])/x]*Sin[a] + x*Sin[a + b/x^2]}
{Sin[a + b/x^2]/x, x, 3, (-(1/2))*CosIntegral[b/x^2]*Sin[a] - (1/2)*Cos[a]*SinIntegral[b/x^2]}
{Sin[a + b/x^2]/x^2, x, 4, -((Sqrt[Pi/2]*Cos[a]*FresnelS[(Sqrt[b]*Sqrt[2/Pi])/x])/Sqrt[b]) - (Sqrt[Pi/2]*FresnelC[(Sqrt[b]*Sqrt[2/Pi])/x]*Sin[a])/Sqrt[b]}
{Sin[a + b/x^2]/x^3, x, 1, Cos[a + b/x^2]/(2*b)}
{Sin[a + b/x^2]/x^4, x, 5, Cos[a + b/x^2]/(2*b*x) - (Sqrt[Pi/2]*Cos[a]*FresnelC[(Sqrt[b]*Sqrt[2/Pi])/x])/(2*b^(3/2)) + (Sqrt[Pi/2]*FresnelS[(Sqrt[b]*Sqrt[2/Pi])/x]*Sin[a])/(2*b^(3/2))}


(* ::Section::Closed:: *)
(*Integrands of the form x^m Sin[a+b x^n]^p*)


{Sin[a + b*x^n]/x, x, 3, (CosIntegral[b*x^n]*Sin[a])/n + (Cos[a]*SinIntegral[b*x^n])/n}
{Sin[a + b*x^n]^2/x, x, 5, -((Cos[2*a]*CosIntegral[2*b*x^n])/(2*n)) + Log[x]/2 + (Sin[2*a]*SinIntegral[2*b*x^n])/(2*n)}
{Sin[a + b*x^n]^3/x, x, 8, (3*CosIntegral[b*x^n]*Sin[a])/(4*n) - (CosIntegral[3*b*x^n]*Sin[3*a])/(4*n) + (3*Cos[a]*SinIntegral[b*x^n])/(4*n) - (Cos[3*a]*SinIntegral[3*b*x^n])/(4*n)}
{Sin[a + b*x^n]^4/x, x, 8, -((Cos[2*a]*CosIntegral[2*b*x^n])/(2*n)) + (Cos[4*a]*CosIntegral[4*b*x^n])/(8*n) + (3*Log[x])/8 + (Sin[2*a]*SinIntegral[2*b*x^n])/(2*n) - (Sin[4*a]*SinIntegral[4*b*x^n])/(8*n)}


{Sin[Sqrt[x]]/Sqrt[x], x, 1, -2*Cos[Sqrt[x]]}
{Sin[Sqrt[x]]^3/Sqrt[x], x, 3, -2*Cos[Sqrt[x]] + (2/3)*Cos[Sqrt[x]]^3}
{Sin[Sqrt[x]], x, 3, -2*Sqrt[x]*Cos[Sqrt[x]] + 2*Sin[Sqrt[x]]}


{Sin[x^(1/3)]^2, x, 4, -((3*x^(1/3))/4) + x/2 + (3/4)*Cos[x^(1/3)]*Sin[x^(1/3)] - (3/2)*x^(2/3)*Cos[x^(1/3)]*Sin[x^(1/3)] + (3/2)*x^(1/3)*Sin[x^(1/3)]^2}
{Sin[x^(1/3)]^3, x, 7, (14/3)*Cos[x^(1/3)] - 2*x^(2/3)*Cos[x^(1/3)] - (2/9)*Cos[x^(1/3)]^3 + 4*x^(1/3)*Sin[x^(1/3)] - x^(2/3)*Cos[x^(1/3)]*Sin[x^(1/3)]^2 + (2/3)*x^(1/3)*Sin[x^(1/3)]^3}


{Sin[a + b*x^n], x, 3, (I*E^(I*a)*x*Gamma[1/n, (-I)*b*x^n])/(((-I)*b*x^n)^n^(-1)*(2*n)) - (I*x*Gamma[1/n, I*b*x^n])/(E^(I*a)*(I*b*x^n)^n^(-1)*(2*n))}
{Sin[a + b*x^n]^2, x, 5, x/2 + (2^(-2 - 1/n)*E^(2*I*a)*x*Gamma[1/n, -2*I*b*x^n])/(((-I)*b*x^n)^n^(-1)*n) + (2^(-2 - 1/n)*x*Gamma[1/n, 2*I*b*x^n])/(E^(2*I*a)*(I*b*x^n)^n^(-1)*n)}
{Sin[a + b*x^n]^3, x, 8, (3*I*E^(I*a)*x*Gamma[1/n, (-I)*b*x^n])/(((-I)*b*x^n)^n^(-1)*(8*n)) - (3*I*x*Gamma[1/n, I*b*x^n])/(E^(I*a)*(I*b*x^n)^n^(-1)*(8*n)) - (I*E^(3*I*a)*x*Gamma[1/n, -3*I*b*x^n])/(3^n^(-1)*((-I)*b*x^n)^n^(-1)*(8*n)) + (I*x*Gamma[1/n, 3*I*b*x^n])/(3^n^(-1)*E^(3*I*a)*(I*b*x^n)^n^(-1)*(8*n))}

{x^m*Sin[a + b*x^n], x, 3, (I*E^(I*a)*x^(1 + m)*Gamma[(1 + m)/n, (-I)*b*x^n])/(((-I)*b*x^n)^((1 + m)/n)*(2*n)) - (I*x^(1 + m)*Gamma[(1 + m)/n, I*b*x^n])/(E^(I*a)*(I*b*x^n)^((1 + m)/n)*(2*n))}
{x^m*Sin[a + b*x^n]^2, x, 5, x^(1 + m)/(2*(1 + m)) + (E^(2*I*a)*x^(1 + m)*Gamma[(1 + m)/n, -2*I*b*x^n])/(2^((1 + m + 2*n)/n)*((-I)*b*x^n)^((1 + m)/n)*n) + (x^(1 + m)*Gamma[(1 + m)/n, 2*I*b*x^n])/(2^((1 + m + 2*n)/n)*E^(2*I*a)*(I*b*x^n)^((1 + m)/n)*n)}
{x^m*Sin[a + b*x^n]^3, x, 8, (3*I*E^(I*a)*x^(1 + m)*Gamma[(1 + m)/n, (-I)*b*x^n])/(((-I)*b*x^n)^((1 + m)/n)*(8*n)) - (3*I*x^(1 + m)*Gamma[(1 + m)/n, I*b*x^n])/(E^(I*a)*(I*b*x^n)^((1 + m)/n)*(8*n)) - (I*E^(3*I*a)*x^(1 + m)*Gamma[(1 + m)/n, -3*I*b*x^n])/(3^((1 + m)/n)*((-I)*b*x^n)^((1 + m)/n)*(8*n)) + (I*x^(1 + m)*Gamma[(1 + m)/n, 3*I*b*x^n])/(3^((1 + m)/n)*E^(3*I*a)*(I*b*x^n)^((1 + m)/n)*(8*n))}


{x^(2*n - 1)*Sin[a + b*x^n], x, 2, -((x^n*Cos[a + b*x^n])/(b*n)) + Sin[a + b*x^n]/(b^2*n)}
{x^(2*n - 1)*Cos[a + b*x^n], x, 2, Cos[a + b*x^n]/(b^2*n) + (x^n*Sin[a + b*x^n])/(b*n)}


{Sin[a + b*x^n]/x^(n + 1), x, 4, (b*Cos[a]*CosIntegral[b*x^n])/n - Sin[a + b*x^n]/(x^n*n) - (b*Sin[a]*SinIntegral[b*x^n])/n}
{Sin[a + b*x^n]^2/x^(n + 1), x, 6, -(1/(x^n*(2*n))) + Cos[2*a + 2*b*x^n]/(x^n*(2*n)) + (b*CosIntegral[2*b*x^n]*Sin[2*a])/n + (b*Cos[2*a]*SinIntegral[2*b*x^n])/n}
{Sin[a + b*x^n]^3/x^(n + 1), x, 10, (3*b*Cos[a]*CosIntegral[b*x^n])/(4*n) - (3*b*Cos[3*a]*CosIntegral[3*b*x^n])/(4*n) - (3*Sin[a + b*x^n])/(x^n*(4*n)) + Sin[3*a + 3*b*x^n]/(x^n*(4*n)) - (3*b*Sin[a]*SinIntegral[b*x^n])/(4*n) + (3*b*Sin[3*a]*SinIntegral[3*b*x^n])/(4*n)}

{Sin[a + b*x^n]/x^(2*n + 1), x, 5, -((b*Cos[a + b*x^n])/(x^n*(2*n))) - (b^2*CosIntegral[b*x^n]*Sin[a])/(2*n) - Sin[a + b*x^n]/(x^(2*n)*(2*n)) - (b^2*Cos[a]*SinIntegral[b*x^n])/(2*n)}
{Sin[a + b*x^n]^2/x^(2*n + 1), x, 7, -(1/(x^(2*n)*(4*n))) + Cos[2*a + 2*b*x^n]/(x^(2*n)*(4*n)) + (b^2*Cos[2*a]*CosIntegral[2*b*x^n])/n - (b*Sin[2*a + 2*b*x^n])/(x^n*(2*n)) - (b^2*Sin[2*a]*SinIntegral[2*b*x^n])/n}
{Sin[a + b*x^n]^3/x^(2*n + 1), x, 12, -((3*b*Cos[a + b*x^n])/(x^n*(8*n))) + (3*b*Cos[3*a + 3*b*x^n])/(x^n*(8*n)) - (3*b^2*CosIntegral[b*x^n]*Sin[a])/(8*n) + (9*b^2*CosIntegral[3*b*x^n]*Sin[3*a])/(8*n) - (3*Sin[a + b*x^n])/(x^(2*n)*(8*n)) + Sin[3*a + 3*b*x^n]/(x^(2*n)*(8*n)) - (3*b^2*Cos[a]*SinIntegral[b*x^n])/(8*n) + (9*b^2*Cos[3*a]*SinIntegral[3*b*x^n])/(8*n)}


(* ::Title:: *)
(*Integration problems of the form x^m Cos[a+b x^n]^p*)


(* ::Section::Closed:: *)
(*Integrands of the form x^m Cos[a+b x]^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Cos[a+b x]^p*)


{x^4*Cos[a + b*x], x, 5, -((24*x*Cos[a + b*x])/b^4) + (4*x^3*Cos[a + b*x])/b^2 + (24*Sin[a + b*x])/b^5 - (12*x^2*Sin[a + b*x])/b^3 + (x^4*Sin[a + b*x])/b}
{x^3*Cos[a + b*x], x, 4, -((6*Cos[a + b*x])/b^4) + (3*x^2*Cos[a + b*x])/b^2 - (6*x*Sin[a + b*x])/b^3 + (x^3*Sin[a + b*x])/b}
{x^2*Cos[a + b*x], x, 3, (2*x*Cos[a + b*x])/b^2 - (2*Sin[a + b*x])/b^3 + (x^2*Sin[a + b*x])/b}
{x^1*Cos[a + b*x], x, 2, Cos[a + b*x]/b^2 + (x*Sin[a + b*x])/b}
{x^0*Cos[a + b*x], x, 1, Sin[a + b*x]/b}
{Cos[a + b*x]/x^1, x, 3, Cos[a]*CosIntegral[b*x] - Sin[a]*SinIntegral[b*x]}
{Cos[a + b*x]/x^2, x, 4, -(Cos[a + b*x]/x) - b*CosIntegral[b*x]*Sin[a] - b*Cos[a]*SinIntegral[b*x]}
{Cos[a + b*x]/x^3, x, 5, -(Cos[a + b*x]/(2*x^2)) - (1/2)*b^2*Cos[a]*CosIntegral[b*x] + (b*Sin[a + b*x])/(2*x) + (1/2)*b^2*Sin[a]*SinIntegral[b*x]}
{Cos[a + b*x]/x^4, x, 6, -(Cos[a + b*x]/(3*x^3)) + (b^2*Cos[a + b*x])/(6*x) + (1/6)*b^3*CosIntegral[b*x]*Sin[a] + (b*Sin[a + b*x])/(6*x^2) + (1/6)*b^3*Cos[a]*SinIntegral[b*x]}


{x^3*Cos[a + b*x]^2, x, 4, -((3*x^2)/(8*b^2)) + x^4/8 - (3*Cos[a + b*x]^2)/(8*b^4) + (3*x^2*Cos[a + b*x]^2)/(4*b^2) - (3*x*Cos[a + b*x]*Sin[a + b*x])/(4*b^3) + (x^3*Cos[a + b*x]*Sin[a + b*x])/(2*b)}
{x^2*Cos[a + b*x]^2, x, 3, -(x/(4*b^2)) + x^3/6 + (x*Cos[a + b*x]^2)/(2*b^2) - (Cos[a + b*x]*Sin[a + b*x])/(4*b^3) + (x^2*Cos[a + b*x]*Sin[a + b*x])/(2*b)}
{x^1*Cos[a + b*x]^2, x, 2, x^2/4 + Cos[a + b*x]^2/(4*b^2) + (x*Cos[a + b*x]*Sin[a + b*x])/(2*b)}
{x^0*Cos[a + b*x]^2, x, 1, x/2 + (Cos[a + b*x]*Sin[a + b*x])/(2*b)}
{Cos[a + b*x]^2/x^1, x, 5, (1/2)*Cos[2*a]*CosIntegral[2*b*x] + Log[x]/2 - (1/2)*Sin[2*a]*SinIntegral[2*b*x]}
{Cos[a + b*x]^2/x^2, x, 5, -(Cos[a + b*x]^2/x) - b*CosIntegral[2*b*x]*Sin[2*a] - b*Cos[2*a]*SinIntegral[2*b*x]}
{Cos[a + b*x]^2/x^3, x, 7, -(Cos[a + b*x]^2/(2*x^2)) - b^2*Cos[2*a]*CosIntegral[2*b*x] + (b*Cos[a + b*x]*Sin[a + b*x])/x + b^2*Sin[2*a]*SinIntegral[2*b*x]}


{x^3*Cos[a + b*x]^3, x, 8, -((40*Cos[a + b*x])/(9*b^4)) + (2*x^2*Cos[a + b*x])/b^2 - (2*Cos[a + b*x]^3)/(27*b^4) + (x^2*Cos[a + b*x]^3)/(3*b^2) - (40*x*Sin[a + b*x])/(9*b^3) + (2*x^3*Sin[a + b*x])/(3*b) - (2*x*Cos[a + b*x]^2*Sin[a + b*x])/(9*b^3) + (x^3*Cos[a + b*x]^2*Sin[a + b*x])/(3*b)}
{x^2*Cos[a + b*x]^3, x, 6, (4*x*Cos[a + b*x])/(3*b^2) + (2*x*Cos[a + b*x]^3)/(9*b^2) - (14*Sin[a + b*x])/(9*b^3) + (2*x^2*Sin[a + b*x])/(3*b) + (x^2*Cos[a + b*x]^2*Sin[a + b*x])/(3*b) + (2*Sin[a + b*x]^3)/(27*b^3)}
{x^1*Cos[a + b*x]^3, x, 3, (2*Cos[a + b*x])/(3*b^2) + Cos[a + b*x]^3/(9*b^2) + (2*x*Sin[a + b*x])/(3*b) + (x*Cos[a + b*x]^2*Sin[a + b*x])/(3*b)}
{x^0*Cos[a + b*x]^3, x, 2, Sin[a + b*x]/b - Sin[a + b*x]^3/(3*b)}
{Cos[a + b*x]^3/x^1, x, 8, (3/4)*Cos[a]*CosIntegral[b*x] + (1/4)*Cos[3*a]*CosIntegral[3*b*x] - (3/4)*Sin[a]*SinIntegral[b*x] - (1/4)*Sin[3*a]*SinIntegral[3*b*x]}
{Cos[a + b*x]^3/x^2, x, 8, -(Cos[a + b*x]^3/x) - (3/4)*b*CosIntegral[b*x]*Sin[a] - (3/4)*b*CosIntegral[3*b*x]*Sin[3*a] - (3/4)*b*Cos[a]*SinIntegral[b*x] - (3/4)*b*Cos[3*a]*SinIntegral[3*b*x]}
{Cos[a + b*x]^3/x^3, x, 12, -(Cos[a + b*x]^3/(2*x^2)) - (3/8)*b^2*Cos[a]*CosIntegral[b*x] - (9/8)*b^2*Cos[3*a]*CosIntegral[3*b*x] + (3*b*Cos[a + b*x]^2*Sin[a + b*x])/(2*x) + (3/8)*b^2*Sin[a]*SinIntegral[b*x] + (9/8)*b^2*Sin[3*a]*SinIntegral[3*b*x]}


{x^3*Cos[a + b*x]^4, x, 8, -((45*x^2)/(128*b^2)) + (3*x^4)/32 - (45*Cos[a + b*x]^2)/(128*b^4) + (9*x^2*Cos[a + b*x]^2)/(16*b^2) - (3*Cos[a + b*x]^4)/(128*b^4) + (3*x^2*Cos[a + b*x]^4)/(16*b^2) - (45*x*Cos[a + b*x]*Sin[a + b*x])/(64*b^3) + (3*x^3*Cos[a + b*x]*Sin[a + b*x])/(8*b) - (3*x*Cos[a + b*x]^3*Sin[a + b*x])/(32*b^3) + (x^3*Cos[a + b*x]^3*Sin[a + b*x])/(4*b)}
{x^2*Cos[a + b*x]^4, x, 6, -((15*x)/(64*b^2)) + x^3/8 + (3*x*Cos[a + b*x]^2)/(8*b^2) + (x*Cos[a + b*x]^4)/(8*b^2) - (15*Cos[a + b*x]*Sin[a + b*x])/(64*b^3) + (3*x^2*Cos[a + b*x]*Sin[a + b*x])/(8*b) - (Cos[a + b*x]^3*Sin[a + b*x])/(32*b^3) + (x^2*Cos[a + b*x]^3*Sin[a + b*x])/(4*b)}
{x^1*Cos[a + b*x]^4, x, 3, (3*x^2)/16 + (3*Cos[a + b*x]^2)/(16*b^2) + Cos[a + b*x]^4/(16*b^2) + (3*x*Cos[a + b*x]*Sin[a + b*x])/(8*b) + (x*Cos[a + b*x]^3*Sin[a + b*x])/(4*b)}
{x^0*Cos[a + b*x]^4, x, 2, (3*x)/8 + (3*Cos[a + b*x]*Sin[a + b*x])/(8*b) + (Cos[a + b*x]^3*Sin[a + b*x])/(4*b)}
{Cos[a + b*x]^4/x^1, x, 8, (1/2)*Cos[2*a]*CosIntegral[2*b*x] + (1/8)*Cos[4*a]*CosIntegral[4*b*x] + (3*Log[x])/8 - (1/2)*Sin[2*a]*SinIntegral[2*b*x] - (1/8)*Sin[4*a]*SinIntegral[4*b*x]}
{Cos[a + b*x]^4/x^2, x, 8, -(Cos[a + b*x]^4/x) - b*CosIntegral[2*b*x]*Sin[2*a] - (1/2)*b*CosIntegral[4*b*x]*Sin[4*a] - b*Cos[2*a]*SinIntegral[2*b*x] - (1/2)*b*Cos[4*a]*SinIntegral[4*b*x]}
{Cos[a + b*x]^4/x^3, x, 14, -(Cos[a + b*x]^4/(2*x^2)) - b^2*Cos[2*a]*CosIntegral[2*b*x] - b^2*Cos[4*a]*CosIntegral[4*b*x] + (2*b*Cos[a + b*x]^3*Sin[a + b*x])/x + b^2*Sin[2*a]*SinIntegral[2*b*x] + b^2*Sin[4*a]*SinIntegral[4*b*x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Cos[a+b x]^(p/2)*)


{x^1*Cos[a + b*x]^(1/2), x, 0, Int[x*Sqrt[Cos[a + b*x]], x]}
{x^0*Cos[a + b*x]^(1/2), x, 1, (2*EllipticE[(1/2)*(a + b*x), 2])/b}
{Cos[a + b*x]^(1/2)/x^1, x, 0, Int[Sqrt[Cos[a + b*x]]/x, x]}


{x^1*Cos[a + b*x]^(3/2), x, 1, (4*Cos[a + b*x]^(3/2))/(9*b^2) + (1/3)*Int[x/Sqrt[Cos[a + b*x]], x] + (2*x*Sqrt[Cos[a + b*x]]*Sin[a + b*x])/(3*b)}
{x^0*Cos[a + b*x]^(3/2), x, 2, (2*EllipticF[(1/2)*(a + b*x), 2])/(3*b) + (2*Sqrt[Cos[a + b*x]]*Sin[a + b*x])/(3*b)}
{Cos[a + b*x]^(3/2)/x^1, x, 0, Int[Cos[a + b*x]^(3/2)/x, x]}

{x^1*Cos[a + b*x]^(3/2) - x/(3*Sqrt[Cos[a + b*x]]), x, 2, (4*Cos[a + b*x]^(3/2))/(9*b^2) + (2*x*Sqrt[Cos[a + b*x]]*Sin[a + b*x])/(3*b)}


{Cos[x]^(3/2)/x^3, x, 1, -(Cos[x]^(3/2)/(2*x^2)) + (3/8)*Int[1/(x*Sqrt[Cos[x]]), x] - (9/8)*Int[Cos[x]^(3/2)/x, x] + (3*Sqrt[Cos[x]]*Sin[x])/(4*x)}


{x^1/Cos[a + b*x]^(1/2), x, 0, Int[x/Sqrt[Cos[a + b*x]], x]}
{x^0/Cos[a + b*x]^(1/2), x, 1, (2*EllipticF[(1/2)*(a + b*x), 2])/b}
{1/(x^1*Cos[a + b*x]^(1/2)), x, 0, Int[1/(x*Sqrt[Cos[a + b*x]]), x]}


{x^1/Cos[a + b*x]^(3/2), x, 1, (4*Sqrt[Cos[a + b*x]])/b^2 + (2*x*Sin[a + b*x])/(b*Sqrt[Cos[a + b*x]]) - Int[x*Sqrt[Cos[a + b*x]], x]}
{x^0/Cos[a + b*x]^(3/2), x, 2, -((2*EllipticE[(1/2)*(a + b*x), 2])/b) + (2*Sin[a + b*x])/(b*Sqrt[Cos[a + b*x]])}
{1/(x^1*Cos[a + b*x]^(3/2)), x, 0, Int[1/(x*Cos[a + b*x]^(3/2)), x]}

{x^1/Cos[a + b*x]^(3/2) + x*Sqrt[Cos[a + b*x]], x, 2, (4*Sqrt[Cos[a + b*x]])/b^2 + (2*x*Sin[a + b*x])/(b*Sqrt[Cos[a + b*x]])}


{x/Cos[x]^(3/2) + x*Sqrt[Cos[x]], x, 2, 4*Sqrt[Cos[x]] + (2*x*Sin[x])/Sqrt[Cos[x]]}
{x/Cos[x]^(5/2) - x/(3*Sqrt[Cos[x]]), x, 2, -(4/(3*Sqrt[Cos[x]])) + (2*x*Sin[x])/(3*Cos[x]^(3/2))}
{x/Cos[x]^(7/2) + (3/5)*x*Sqrt[Cos[x]], x, 3, -(4/(15*Cos[x]^(3/2))) + (12*Sqrt[Cos[x]])/5 + (2*x*Sin[x])/(5*Cos[x]^(5/2)) + (6*x*Sin[x])/(5*Sqrt[Cos[x]])}
{x^2/Cos[x]^(3/2) + x^2*Sqrt[Cos[x]], x, 3, 8*x*Sqrt[Cos[x]] - 16*EllipticE[x/2, 2] + (2*x^2*Sin[x])/Sqrt[Cos[x]]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^(m/2) Cos[a+b x]^p*)


{x^(5/2)*Cos[a + b*x], x, 8, (5*x^(3/2)*Cos[a + b*x])/(2*b^2) + (15*Sqrt[Pi/2]*Cos[a]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*Sqrt[x]])/(4*b^(7/2)) + (15*Sqrt[Pi/2]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*Sqrt[x]]*Sin[a])/(4*b^(7/2)) - (15*Sqrt[x]*Sin[a + b*x])/(4*b^3) + (x^(5/2)*Sin[a + b*x])/b}
{x^(3/2)*Cos[a + b*x], x, 7, (3*Sqrt[x]*Cos[a + b*x])/(2*b^2) - (3*Sqrt[Pi/2]*Cos[a]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*Sqrt[x]])/(2*b^(5/2)) + (3*Sqrt[Pi/2]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*Sqrt[x]]*Sin[a])/(2*b^(5/2)) + (x^(3/2)*Sin[a + b*x])/b}
{x^(1/2)*Cos[a + b*x], x, 6, -((Sqrt[Pi/2]*Cos[a]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*Sqrt[x]])/b^(3/2)) - (Sqrt[Pi/2]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*Sqrt[x]]*Sin[a])/b^(3/2) + (Sqrt[x]*Sin[a + b*x])/b}
{Cos[a + b*x]/x^(1/2), x, 5, (Sqrt[2*Pi]*Cos[a]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*Sqrt[x]])/Sqrt[b] - (Sqrt[2*Pi]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*Sqrt[x]]*Sin[a])/Sqrt[b]}
{Cos[a + b*x]/x^(3/2), x, 6, -((2*Cos[a + b*x])/Sqrt[x]) - 2*Sqrt[b]*Sqrt[2*Pi]*Cos[a]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*Sqrt[x]] - 2*Sqrt[b]*Sqrt[2*Pi]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*Sqrt[x]]*Sin[a]}
{Cos[a + b*x]/x^(5/2), x, 7, -((2*Cos[a + b*x])/(3*x^(3/2))) - (4/3)*b^(3/2)*Sqrt[2*Pi]*Cos[a]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*Sqrt[x]] + (4/3)*b^(3/2)*Sqrt[2*Pi]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*Sqrt[x]]*Sin[a] + (4*b*Sin[a + b*x])/(3*Sqrt[x])}


{x^(5/2)*Cos[a + b*x]^2, x, 10, -((5*x^(3/2))/(16*b^2)) + x^(7/2)/7 + (5*x^(3/2)*Cos[a + b*x]^2)/(8*b^2) + (15*Sqrt[Pi]*Cos[2*a]*FresnelS[(2*Sqrt[b]*Sqrt[x])/Sqrt[Pi]])/(128*b^(7/2)) + (15*Sqrt[Pi]*FresnelC[(2*Sqrt[b]*Sqrt[x])/Sqrt[Pi]]*Sin[2*a])/(128*b^(7/2)) + (x^(5/2)*Cos[a + b*x]*Sin[a + b*x])/(2*b) - (15*Sqrt[x]*Sin[2*a + 2*b*x])/(64*b^3)}
{x^(3/2)*Cos[a + b*x]^2, x, 9, -((3*Sqrt[x])/(16*b^2)) + x^(5/2)/5 + (3*Sqrt[x]*Cos[a + b*x]^2)/(8*b^2) - (3*Sqrt[Pi]*Cos[2*a]*FresnelC[(2*Sqrt[b]*Sqrt[x])/Sqrt[Pi]])/(32*b^(5/2)) + (3*Sqrt[Pi]*FresnelS[(2*Sqrt[b]*Sqrt[x])/Sqrt[Pi]]*Sin[2*a])/(32*b^(5/2)) + (x^(3/2)*Cos[a + b*x]*Sin[a + b*x])/(2*b)}
{x^(1/2)*Cos[a + b*x]^2, x, 8, x^(3/2)/3 - (Sqrt[Pi]*Cos[2*a]*FresnelS[(2*Sqrt[b]*Sqrt[x])/Sqrt[Pi]])/(8*b^(3/2)) - (Sqrt[Pi]*FresnelC[(2*Sqrt[b]*Sqrt[x])/Sqrt[Pi]]*Sin[2*a])/(8*b^(3/2)) + (Sqrt[x]*Sin[2*a + 2*b*x])/(4*b)}
{Cos[a + b*x]^2/x^(1/2), x, 7, Sqrt[x] + (Sqrt[Pi]*Cos[2*a]*FresnelC[(2*Sqrt[b]*Sqrt[x])/Sqrt[Pi]])/(2*Sqrt[b]) - (Sqrt[Pi]*FresnelS[(2*Sqrt[b]*Sqrt[x])/Sqrt[Pi]]*Sin[2*a])/(2*Sqrt[b])}
{Cos[a + b*x]^2/x^(3/2), x, 7, -((2*Cos[a + b*x]^2)/Sqrt[x]) - 2*Sqrt[b]*Sqrt[Pi]*Cos[2*a]*FresnelS[(2*Sqrt[b]*Sqrt[x])/Sqrt[Pi]] - 2*Sqrt[b]*Sqrt[Pi]*FresnelC[(2*Sqrt[b]*Sqrt[x])/Sqrt[Pi]]*Sin[2*a]}
{Cos[a + b*x]^2/x^(5/2), x, 9, -((2*Cos[a + b*x]^2)/(3*x^(3/2))) - (8/3)*b^(3/2)*Sqrt[Pi]*Cos[2*a]*FresnelC[(2*Sqrt[b]*Sqrt[x])/Sqrt[Pi]] + (8/3)*b^(3/2)*Sqrt[Pi]*FresnelS[(2*Sqrt[b]*Sqrt[x])/Sqrt[Pi]]*Sin[2*a] + (8*b*Cos[a + b*x]*Sin[a + b*x])/(3*Sqrt[x])}
{Cos[a + b*x]^2/x^(7/2), x, 9, -((16*b^2)/(15*Sqrt[x])) - (2*Cos[a + b*x]^2)/(5*x^(5/2)) + (32*b^2*Cos[a + b*x]^2)/(15*Sqrt[x]) + (32/15)*b^(5/2)*Sqrt[Pi]*Cos[2*a]*FresnelS[(2*Sqrt[b]*Sqrt[x])/Sqrt[Pi]] + (32/15)*b^(5/2)*Sqrt[Pi]*FresnelC[(2*Sqrt[b]*Sqrt[x])/Sqrt[Pi]]*Sin[2*a] + (8*b*Cos[a + b*x]*Sin[a + b*x])/(15*x^(3/2))}


{x^(3/2)*Cos[x], x, 4, (3/2)*Sqrt[x]*Cos[x] - (3/2)*Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[x]] + x^(3/2)*Sin[x]}
{x^(1/2)*Cos[x], x, 3, (-Sqrt[Pi/2])*FresnelS[Sqrt[2/Pi]*Sqrt[x]] + Sqrt[x]*Sin[x]}
{Cos[x]/x^(1/2), x, 2, Sqrt[2*Pi]*FresnelC[Sqrt[2/Pi]*Sqrt[x]]}
{Cos[x]/x^(3/2), x, 3, -((2*Cos[x])/Sqrt[x]) - 2*Sqrt[2*Pi]*FresnelS[Sqrt[2/Pi]*Sqrt[x]]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^(m+n) Cos[a+b x]^p with m symbolic*)


{x^(m + 3)*Cos[a + b*x], x, 3, -((I*E^(I*a)*x^(3 + m)*((-I)*b*x)^(-3 - m)*Gamma[4 + m, (-I)*b*x])/(2*b)) + (I*x^(3 + m)*(I*b*x)^(-3 - m)*Gamma[4 + m, I*b*x])/(E^(I*a)*(2*b))}
{x^(m + 2)*Cos[a + b*x], x, 3, -((I*E^(I*a)*x^(2 + m)*((-I)*b*x)^(-2 - m)*Gamma[3 + m, (-I)*b*x])/(2*b)) + (I*x^(2 + m)*(I*b*x)^(-2 - m)*Gamma[3 + m, I*b*x])/(E^(I*a)*(2*b))}
{x^(m + 1)*Cos[a + b*x], x, 3, -((I*E^(I*a)*x^(1 + m)*((-I)*b*x)^(-1 - m)*Gamma[2 + m, (-I)*b*x])/(2*b)) + (I*x^(1 + m)*(I*b*x)^(-1 - m)*Gamma[2 + m, I*b*x])/(E^(I*a)*(2*b))}
{x^(m + 0)*Cos[a + b*x], x, 3, -((I*E^(I*a)*x^m*Gamma[1 + m, (-I)*b*x])/(((-I)*b*x)^m*(2*b))) + (I*x^m*Gamma[1 + m, I*b*x])/(E^(I*a)*(I*b*x)^m*(2*b))}
{x^(m - 1)*Cos[a + b*x], x, 3, ((-(1/2))*E^(I*a)*x^m*Gamma[m, (-I)*b*x])/((-I)*b*x)^m - ((1/2)*x^m*Gamma[m, I*b*x])/(E^(I*a)*(I*b*x)^m)}
{x^(m - 2)*Cos[a + b*x], x, 3, (-(1/2))*E^(I*a)*x^(-1 + m)*((-I)*b*x)^(1 - m)*Gamma[-1 + m, (-I)*b*x] - ((1/2)*x^(-1 + m)*(I*b*x)^(1 - m)*Gamma[-1 + m, I*b*x])/E^(I*a)}
{x^(m - 3)*Cos[a + b*x], x, 3, (-(1/2))*E^(I*a)*x^(-2 + m)*((-I)*b*x)^(2 - m)*Gamma[-2 + m, (-I)*b*x] - ((1/2)*x^(-2 + m)*(I*b*x)^(2 - m)*Gamma[-2 + m, I*b*x])/E^(I*a)}


{x^(m + 3)*Cos[a + b*x]^2, x, 5, x^(4 + m)/(2*(4 + m)) - (I*2^(-6 - m)*E^(2*I*a)*x^(3 + m)*((-I)*b*x)^(-3 - m)*Gamma[4 + m, -2*I*b*x])/b + (I*2^(-6 - m)*x^(3 + m)*(I*b*x)^(-3 - m)*Gamma[4 + m, 2*I*b*x])/(E^(2*I*a)*b)}
{x^(m + 2)*Cos[a + b*x]^2, x, 5, x^(3 + m)/(2*(3 + m)) - (I*2^(-5 - m)*E^(2*I*a)*x^(2 + m)*((-I)*b*x)^(-2 - m)*Gamma[3 + m, -2*I*b*x])/b + (I*2^(-5 - m)*x^(2 + m)*(I*b*x)^(-2 - m)*Gamma[3 + m, 2*I*b*x])/(E^(2*I*a)*b)}
{x^(m + 1)*Cos[a + b*x]^2, x, 5, x^(2 + m)/(2*(2 + m)) - (I*2^(-4 - m)*E^(2*I*a)*x^(1 + m)*((-I)*b*x)^(-1 - m)*Gamma[2 + m, -2*I*b*x])/b + (I*2^(-4 - m)*x^(1 + m)*(I*b*x)^(-1 - m)*Gamma[2 + m, 2*I*b*x])/(E^(2*I*a)*b)}
{x^(m + 0)*Cos[a + b*x]^2, x, 5, x^(1 + m)/(2*(1 + m)) - (I*2^(-3 - m)*E^(2*I*a)*x^m*Gamma[1 + m, -2*I*b*x])/(((-I)*b*x)^m*b) + (I*2^(-3 - m)*x^m*Gamma[1 + m, 2*I*b*x])/(E^(2*I*a)*(I*b*x)^m*b)}
{x^(m - 1)*Cos[a + b*x]^2, x, 5, x^m/(2*m) - (2^(-2 - m)*E^(2*I*a)*x^m*Gamma[m, -2*I*b*x])/((-I)*b*x)^m - (2^(-2 - m)*x^m*Gamma[m, 2*I*b*x])/(E^(2*I*a)*(I*b*x)^m)}
{x^(m - 2)*Cos[a + b*x]^2, x, 5, -(x^(-1 + m)/(2*(1 - m))) - 2^(-1 - m)*E^(2*I*a)*x^(-1 + m)*((-I)*b*x)^(1 - m)*Gamma[-1 + m, -2*I*b*x] - (2^(-1 - m)*x^(-1 + m)*(I*b*x)^(1 - m)*Gamma[-1 + m, 2*I*b*x])/E^(2*I*a)}
{x^(m - 3)*Cos[a + b*x]^2, x, 5, -(x^(-2 + m)/(2*(2 - m))) - (E^(2*I*a)*x^(-2 + m)*((-I)*b*x)^(2 - m)*Gamma[-2 + m, -2*I*b*x])/2^m - (x^(-2 + m)*(I*b*x)^(2 - m)*Gamma[-2 + m, 2*I*b*x])/(2^m*E^(2*I*a))}


(* ::Section::Closed:: *)
(*Integrands of the form (c+d x)^m Cos[a+b x]^p*)


(* ::Subsection:: *)
(*Integrands of the form (c+d x)^m Cos[a+b x]^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (c+d x)^(m/2) Cos[a+b x]^p*)


{Cos[a + b*x]*Sqrt[c + d*x], x, 6, -((Sqrt[d]*Sqrt[Pi/2]*Cos[a - (b*c)/d]*FresnelS[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]])/b^(3/2)) - (Sqrt[d]*Sqrt[Pi/2]*FresnelC[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]]*Sin[a - (b*c)/d])/b^(3/2) + (Sqrt[c + d*x]*Sin[a + b*x])/b}
{Cos[a + b*x]/Sqrt[c + d*x], x, 5, (Sqrt[2*Pi]*Cos[a - (b*c)/d]*FresnelC[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]])/(Sqrt[b]*Sqrt[d]) - (Sqrt[2*Pi]*FresnelS[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]]*Sin[a - (b*c)/d])/(Sqrt[b]*Sqrt[d])}
{Cos[a + b*x]/(c + d*x)^(3/2), x, 6, -((2*Cos[a + b*x])/(d*Sqrt[c + d*x])) - (2*Sqrt[b]*Sqrt[2*Pi]*Cos[a - (b*c)/d]*FresnelS[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]])/d^(3/2) - (2*Sqrt[b]*Sqrt[2*Pi]*FresnelC[(Sqrt[b]*Sqrt[2/Pi]*Sqrt[c + d*x])/Sqrt[d]]*Sin[a - (b*c)/d])/d^(3/2)}


{Cos[a + b*x]^2*Sqrt[c + d*x], x, 8, (c + d*x)^(3/2)/(3*d) - (Sqrt[d]*Sqrt[Pi]*Cos[2*a - (2*b*c)/d]*FresnelS[(2*Sqrt[b]*Sqrt[c + d*x])/(Sqrt[d]*Sqrt[Pi])])/(8*b^(3/2)) - (Sqrt[d]*Sqrt[Pi]*FresnelC[(2*Sqrt[b]*Sqrt[c + d*x])/(Sqrt[d]*Sqrt[Pi])]*Sin[2*a - (2*b*c)/d])/(8*b^(3/2)) + (Sqrt[c + d*x]*Sin[2*a + 2*b*x])/(4*b)}
{Cos[a + b*x]^2/Sqrt[c + d*x], x, 7, Sqrt[c + d*x]/d + (Sqrt[Pi]*Cos[2*a - (2*b*c)/d]*FresnelC[(2*Sqrt[b]*Sqrt[c + d*x])/(Sqrt[d]*Sqrt[Pi])])/(2*Sqrt[b]*Sqrt[d]) - (Sqrt[Pi]*FresnelS[(2*Sqrt[b]*Sqrt[c + d*x])/(Sqrt[d]*Sqrt[Pi])]*Sin[2*a - (2*b*c)/d])/(2*Sqrt[b]*Sqrt[d])}
{Cos[a + b*x]^2/(c + d*x)^(3/2), x, 7, -((2*Cos[a + b*x]^2)/(d*Sqrt[c + d*x])) - (2*Sqrt[b]*Sqrt[Pi]*Cos[2*a - (2*b*c)/d]*FresnelS[(2*Sqrt[b]*Sqrt[c + d*x])/(Sqrt[d]*Sqrt[Pi])])/d^(3/2) - (2*Sqrt[b]*Sqrt[Pi]*FresnelC[(2*Sqrt[b]*Sqrt[c + d*x])/(Sqrt[d]*Sqrt[Pi])]*Sin[2*a - (2*b*c)/d])/d^(3/2)}


(* ::Section::Closed:: *)
(*Integrands of the form x^m Cos[a+b x^2]^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Cos[a+b x^2]^p*)


{x^3*Cos[a + b*x^2], x, 2, Cos[a + b*x^2]/(2*b^2) + (x^2*Sin[a + b*x^2])/(2*b)}
{x^2*Cos[a + b*x^2], x, 4, -((Sqrt[Pi/2]*Cos[a]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*x])/(2*b^(3/2))) - (Sqrt[Pi/2]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*x]*Sin[a])/(2*b^(3/2)) + (x*Sin[a + b*x^2])/(2*b)}
{x^1*Cos[a + b*x^2], x, 1, Sin[a + b*x^2]/(2*b)}
{x^0*Cos[a + b*x^2], x, 3, (Sqrt[Pi/2]*Cos[a]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*x])/Sqrt[b] - (Sqrt[Pi/2]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*x]*Sin[a])/Sqrt[b]}
{Cos[a + b*x^2]/x^1, x, 3, (1/2)*Cos[a]*CosIntegral[b*x^2] - (1/2)*Sin[a]*SinIntegral[b*x^2]}
{Cos[a + b*x^2]/x^2, x, 4, -(Cos[a + b*x^2]/x) - Sqrt[b]*Sqrt[2*Pi]*Cos[a]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*x] - Sqrt[b]*Sqrt[2*Pi]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*x]*Sin[a]}
{Cos[a + b*x^2]/x^3, x, 4, -(Cos[a + b*x^2]/(2*x^2)) - (1/2)*b*CosIntegral[b*x^2]*Sin[a] - (1/2)*b*Cos[a]*SinIntegral[b*x^2]}


{x^3*Cos[a + b*x^2]^2, x, 2, x^4/8 + Cos[a + b*x^2]^2/(8*b^2) + (x^2*Cos[a + b*x^2]*Sin[a + b*x^2])/(4*b)}
{x^2*Cos[a + b*x^2]^2, x, 6, x^3/6 - (Sqrt[Pi]*Cos[2*a]*FresnelS[(2*Sqrt[b]*x)/Sqrt[Pi]])/(16*b^(3/2)) - (Sqrt[Pi]*FresnelC[(2*Sqrt[b]*x)/Sqrt[Pi]]*Sin[2*a])/(16*b^(3/2)) + (x*Sin[2*a + 2*b*x^2])/(8*b)}
{x^1*Cos[a + b*x^2]^2, x, 2, x^2/4 + (Cos[a + b*x^2]*Sin[a + b*x^2])/(4*b)}
{x^0*Cos[a + b*x^2]^2, x, 5, x/2 + (Sqrt[Pi]*Cos[2*a]*FresnelC[(2*Sqrt[b]*x)/Sqrt[Pi]])/(4*Sqrt[b]) - (Sqrt[Pi]*FresnelS[(2*Sqrt[b]*x)/Sqrt[Pi]]*Sin[2*a])/(4*Sqrt[b])}
{Cos[a + b*x^2]^2/x^1, x, 5, (1/4)*Cos[2*a]*CosIntegral[2*b*x^2] + Log[x]/2 - (1/4)*Sin[2*a]*SinIntegral[2*b*x^2]}
{Cos[a + b*x^2]^2/x^2, x, 5, -(Cos[a + b*x^2]^2/x) - Sqrt[b]*Sqrt[Pi]*Cos[2*a]*FresnelS[(2*Sqrt[b]*x)/Sqrt[Pi]] - Sqrt[b]*Sqrt[Pi]*FresnelC[(2*Sqrt[b]*x)/Sqrt[Pi]]*Sin[2*a]}
{Cos[a + b*x^2]^2/x^3, x, 6, -(1/(4*x^2)) - Cos[2*a + 2*b*x^2]/(4*x^2) - (1/2)*b*CosIntegral[2*b*x^2]*Sin[2*a] - (1/2)*b*Cos[2*a]*SinIntegral[2*b*x^2]}


{x^3*Cos[a + b*x^2]^3, x, 3, Cos[a + b*x^2]/(3*b^2) + Cos[a + b*x^2]^3/(18*b^2) + (x^2*Sin[a + b*x^2])/(3*b) + (x^2*Cos[a + b*x^2]^2*Sin[a + b*x^2])/(6*b)}
{x^2*Cos[a + b*x^2]^3, x, 10, -((3*Sqrt[Pi/2]*Cos[a]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*x])/(8*b^(3/2))) - (Sqrt[Pi/6]*Cos[3*a]*FresnelS[Sqrt[b]*Sqrt[6/Pi]*x])/(24*b^(3/2)) - (3*Sqrt[Pi/2]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*x]*Sin[a])/(8*b^(3/2)) - (Sqrt[Pi/6]*FresnelC[Sqrt[b]*Sqrt[6/Pi]*x]*Sin[3*a])/(24*b^(3/2)) + (3*x*Sin[a + b*x^2])/(8*b) + (x*Sin[3*a + 3*b*x^2])/(24*b)}
{x^1*Cos[a + b*x^2]^3, x, 3, Sin[a + b*x^2]/(2*b) - Sin[a + b*x^2]^3/(6*b)}
{x^0*Cos[a + b*x^2]^3, x, 8, (3*Sqrt[Pi/2]*Cos[a]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*x])/(4*Sqrt[b]) + (Sqrt[Pi/6]*Cos[3*a]*FresnelC[Sqrt[b]*Sqrt[6/Pi]*x])/(4*Sqrt[b]) - (3*Sqrt[Pi/2]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*x]*Sin[a])/(4*Sqrt[b]) - (Sqrt[Pi/6]*FresnelS[Sqrt[b]*Sqrt[6/Pi]*x]*Sin[3*a])/(4*Sqrt[b])}
{Cos[a + b*x^2]^3/x^1, x, 8, (3/8)*Cos[a]*CosIntegral[b*x^2] + (1/8)*Cos[3*a]*CosIntegral[3*b*x^2] - (3/8)*Sin[a]*SinIntegral[b*x^2] - (1/8)*Sin[3*a]*SinIntegral[3*b*x^2]}
{Cos[a + b*x^2]^3/x^2, x, 9, -(Cos[a + b*x^2]^3/x) - (3/2)*Sqrt[b]*Sqrt[Pi/2]*Cos[a]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*x] - (1/2)*Sqrt[b]*Sqrt[(3*Pi)/2]*Cos[3*a]*FresnelS[Sqrt[b]*Sqrt[6/Pi]*x] - (3/2)*Sqrt[b]*Sqrt[Pi/2]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*x]*Sin[a] - (1/2)*Sqrt[b]*Sqrt[(3*Pi)/2]*FresnelC[Sqrt[b]*Sqrt[6/Pi]*x]*Sin[3*a]}
{Cos[a + b*x^2]^3/x^3, x, 10, -((3*Cos[a + b*x^2])/(8*x^2)) - Cos[3*a + 3*b*x^2]/(8*x^2) - (3/8)*b*CosIntegral[b*x^2]*Sin[a] - (3/8)*b*CosIntegral[3*b*x^2]*Sin[3*a] - (3/8)*b*Cos[a]*SinIntegral[b*x^2] - (3/8)*b*Cos[3*a]*SinIntegral[3*b*x^2]}


{x*Cos[a + b*x^2]^7, x, 3, Sin[a + b*x^2]/(2*b) - Sin[a + b*x^2]^3/(2*b) + (3*Sin[a + b*x^2]^5)/(10*b) - Sin[a + b*x^2]^7/(14*b)}


(* ::Subsection:: *)
(*Integrands of the form x^m Cos[a+b x^2]^(p/2)*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^(m/2) Cos[a+b x^2]^p*)


{x^(5/2)*Cos[a + b*x^2], x, 4, -((3*I*E^(I*a)*x^(3/2)*Gamma[3/4, (-I)*b*x^2])/(16*b*((-I)*b*x^2)^(3/4))) + (3*I*x^(3/2)*Gamma[3/4, I*b*x^2])/(E^(I*a)*(16*b*(I*b*x^2)^(3/4))) + (x^(3/2)*Sin[a + b*x^2])/(2*b)}
{x^(3/2)*Cos[a + b*x^2], x, 4, -((I*E^(I*a)*Sqrt[x]*Gamma[1/4, (-I)*b*x^2])/(16*b*((-I)*b*x^2)^(1/4))) + (I*Sqrt[x]*Gamma[1/4, I*b*x^2])/(E^(I*a)*(16*b*(I*b*x^2)^(1/4))) + (Sqrt[x]*Sin[a + b*x^2])/(2*b)}
{x^(1/2)*Cos[a + b*x^2], x, 3, -((E^(I*a)*x^(3/2)*Gamma[3/4, (-I)*b*x^2])/(4*((-I)*b*x^2)^(3/4))) - (x^(3/2)*Gamma[3/4, I*b*x^2])/(E^(I*a)*(4*(I*b*x^2)^(3/4)))}
{Cos[a + b*x^2]/x^(1/2), x, 3, -((E^(I*a)*Sqrt[x]*Gamma[1/4, (-I)*b*x^2])/(4*((-I)*b*x^2)^(1/4))) - (Sqrt[x]*Gamma[1/4, I*b*x^2])/(E^(I*a)*(4*(I*b*x^2)^(1/4)))}
{Cos[a + b*x^2]/x^(3/2), x, 4, -((2*Cos[a + b*x^2])/Sqrt[x]) - (I*b*E^(I*a)*x^(3/2)*Gamma[3/4, (-I)*b*x^2])/((-I)*b*x^2)^(3/4) + (I*b*x^(3/2)*Gamma[3/4, I*b*x^2])/(E^(I*a)*(I*b*x^2)^(3/4))}
{Cos[a + b*x^2]/x^(5/2), x, 4, -((2*Cos[a + b*x^2])/(3*x^(3/2))) - (I*b*E^(I*a)*Sqrt[x]*Gamma[1/4, (-I)*b*x^2])/(3*((-I)*b*x^2)^(1/4)) + (I*b*Sqrt[x]*Gamma[1/4, I*b*x^2])/(E^(I*a)*(3*(I*b*x^2)^(1/4)))}


{x^(5/2)*Cos[a + b*x^2]^2, x, 7, x^(7/2)/7 - (3*I*E^(2*I*a)*x^(3/2)*Gamma[3/4, -2*I*b*x^2])/(64*2^(3/4)*b*((-I)*b*x^2)^(3/4)) + (3*I*x^(3/2)*Gamma[3/4, 2*I*b*x^2])/(E^(2*I*a)*(64*2^(3/4)*b*(I*b*x^2)^(3/4))) + (x^(3/2)*Sin[2*a + 2*b*x^2])/(8*b)}
{x^(3/2)*Cos[a + b*x^2]^2, x, 7, x^(5/2)/5 - (I*E^(2*I*a)*Sqrt[x]*Gamma[1/4, -2*I*b*x^2])/(64*2^(1/4)*b*((-I)*b*x^2)^(1/4)) + (I*Sqrt[x]*Gamma[1/4, 2*I*b*x^2])/(E^(2*I*a)*(64*2^(1/4)*b*(I*b*x^2)^(1/4))) + (Sqrt[x]*Sin[2*a + 2*b*x^2])/(8*b)}
{x^(1/2)*Cos[a + b*x^2]^2, x, 6, x^(3/2)/3 - (E^(2*I*a)*x^(3/2)*Gamma[3/4, -2*I*b*x^2])/(8*2^(3/4)*((-I)*b*x^2)^(3/4)) - (x^(3/2)*Gamma[3/4, 2*I*b*x^2])/(E^(2*I*a)*(8*2^(3/4)*(I*b*x^2)^(3/4)))}
{Cos[a + b*x^2]^2/x^(1/2), x, 6, Sqrt[x] - (E^(2*I*a)*Sqrt[x]*Gamma[1/4, -2*I*b*x^2])/(8*2^(1/4)*((-I)*b*x^2)^(1/4)) - (Sqrt[x]*Gamma[1/4, 2*I*b*x^2])/(E^(2*I*a)*(8*2^(1/4)*(I*b*x^2)^(1/4)))}
{Cos[a + b*x^2]^2/x^(3/2), x, 7, -(1/Sqrt[x]) - Cos[2*a + 2*b*x^2]/Sqrt[x] - (I*b*E^(2*I*a)*x^(3/2)*Gamma[3/4, -2*I*b*x^2])/(2^(3/4)*((-I)*b*x^2)^(3/4)) + (I*b*x^(3/2)*Gamma[3/4, 2*I*b*x^2])/(E^(2*I*a)*(2^(3/4)*(I*b*x^2)^(3/4)))}
{Cos[a + b*x^2]^2/x^(5/2), x, 6, -((2*Cos[a + b*x^2]^2)/(3*x^(3/2))) - (I*b*E^(2*I*a)*Sqrt[x]*Gamma[1/4, -2*I*b*x^2])/(3*2^(1/4)*((-I)*b*x^2)^(1/4)) + (I*b*Sqrt[x]*Gamma[1/4, 2*I*b*x^2])/(E^(2*I*a)*(3*2^(1/4)*(I*b*x^2)^(1/4)))}


(* ::Subsection:: *)
(*Integrands of the form x^(m/2) Cos[a+b x^2]^(p/2)*)


(* ::Section::Closed:: *)
(*Integrands of the form x^m Cos[a+b / x^n]^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Cos[a+b / x]^p*)


{Cos[a + b/x], x, 5, x*Cos[a + b/x] + b*CosIntegral[b/x]*Sin[a] + b*Cos[a]*SinIntegral[b/x]}
{Cos[a + b/x]/x, x, 3, (-Cos[a])*CosIntegral[b/x] + Sin[a]*SinIntegral[b/x]}
{Cos[a + b/x]/x^2, x, 1, -(Sin[a + b/x]/b)}
{Cos[a + b/x]/x^3, x, 2, -(Cos[a + b/x]/b^2) - Sin[a + b/x]/(b*x)}
{Cos[a + b/x]/x^4, x, 3, -((2*Cos[a + b/x])/(b^2*x)) + (2*Sin[a + b/x])/b^3 - Sin[a + b/x]/(b*x^2)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Cos[a+b / x^2]^p*)


{x^0*Cos[a + b/x^2], x, 5, x*Cos[a + b/x^2] + Sqrt[b]*Sqrt[2*Pi]*Cos[a]*FresnelS[(Sqrt[b]*Sqrt[2/Pi])/x] + Sqrt[b]*Sqrt[2*Pi]*FresnelC[(Sqrt[b]*Sqrt[2/Pi])/x]*Sin[a]}
{Cos[a + b/x^2]/x^1, x, 3, (-(1/2))*Cos[a]*CosIntegral[b/x^2] + (1/2)*Sin[a]*SinIntegral[b/x^2]}
{Cos[a + b/x^2]/x^2, x, 4, -((Sqrt[Pi/2]*Cos[a]*FresnelC[(Sqrt[b]*Sqrt[2/Pi])/x])/Sqrt[b]) + (Sqrt[Pi/2]*FresnelS[(Sqrt[b]*Sqrt[2/Pi])/x]*Sin[a])/Sqrt[b]}
{Cos[a + b/x^2]/x^3, x, 1, -(Sin[a + b/x^2]/(2*b))}
{Cos[a + b/x^2]/x^4, x, 5, (Sqrt[Pi/2]*Cos[a]*FresnelS[(Sqrt[b]*Sqrt[2/Pi])/x])/(2*b^(3/2)) + (Sqrt[Pi/2]*FresnelC[(Sqrt[b]*Sqrt[2/Pi])/x]*Sin[a])/(2*b^(3/2)) - Sin[a + b/x^2]/(2*b*x)}


(* ::Section::Closed:: *)
(*Integrands of the form x^m Cos[a+b x^n]^p*)


{Cos[a + b*x^n]/x, x, 3, (Cos[a]*CosIntegral[b*x^n])/n - (Sin[a]*SinIntegral[b*x^n])/n}
{Cos[a + b*x^n]^2/x, x, 5, (Cos[2*a]*CosIntegral[2*b*x^n])/(2*n) + Log[x]/2 - (Sin[2*a]*SinIntegral[2*b*x^n])/(2*n)}
{Cos[a + b*x^n]^3/x, x, 8, (3*Cos[a]*CosIntegral[b*x^n])/(4*n) + (Cos[3*a]*CosIntegral[3*b*x^n])/(4*n) - (3*Sin[a]*SinIntegral[b*x^n])/(4*n) - (Sin[3*a]*SinIntegral[3*b*x^n])/(4*n)}
{Cos[a + b*x^n]^4/x, x, 8, (Cos[2*a]*CosIntegral[2*b*x^n])/(2*n) + (Cos[4*a]*CosIntegral[4*b*x^n])/(8*n) + (3*Log[x])/8 - (Sin[2*a]*SinIntegral[2*b*x^n])/(2*n) - (Sin[4*a]*SinIntegral[4*b*x^n])/(8*n)}


{Cos[Sqrt[x]]^2/Sqrt[x], x, 2, Sqrt[x] + Cos[Sqrt[x]]*Sin[Sqrt[x]]}
{Cos[Sqrt[x]]/Sqrt[x], x, 1, 2*Sin[Sqrt[x]]}
{Cos[Sqrt[x]], x, 3, 2*Cos[Sqrt[x]] + 2*Sqrt[x]*Sin[Sqrt[x]]}
{Cos[Sqrt[x]]^2, x, 3, x/2 + (1/2)*Cos[Sqrt[x]]^2 + Sqrt[x]*Cos[Sqrt[x]]*Sin[Sqrt[x]]}


{x^(3/2)*Cos[a + b*x^(1/3)], x, 11, (135135*Sqrt[x]*Cos[a + b*x^(1/3)])/(32*b^6) - (3861*x^(7/6)*Cos[a + b*x^(1/3)])/(8*b^4) + (39*x^(11/6)*Cos[a + b*x^(1/3)])/(2*b^2) + (405405*Sqrt[Pi/2]*Cos[a]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*x^(1/6)])/(64*b^(15/2)) + (405405*Sqrt[Pi/2]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*x^(1/6)]*Sin[a])/(64*b^(15/2)) - (405405*x^(1/6)*Sin[a + b*x^(1/3)])/(64*b^7) + (27027*x^(5/6)*Sin[a + b*x^(1/3)])/(16*b^5) - (429*x^(3/2)*Sin[a + b*x^(1/3)])/(4*b^3) + (3*x^(13/6)*Sin[a + b*x^(1/3)])/b}
{x^(1/2)*Cos[a + b*x^(1/3)], x, 8, -((315*x^(1/6)*Cos[a + b*x^(1/3)])/(8*b^4)) + (21*x^(5/6)*Cos[a + b*x^(1/3)])/(2*b^2) + (315*Sqrt[Pi/2]*Cos[a]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*x^(1/6)])/(8*b^(9/2)) - (315*Sqrt[Pi/2]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*x^(1/6)]*Sin[a])/(8*b^(9/2)) - (105*Sqrt[x]*Sin[a + b*x^(1/3)])/(4*b^3) + (3*x^(7/6)*Sin[a + b*x^(1/3)])/b}
{Cos[a + b*x^(1/3)]/x^(1/2), x, 5, -((3*Sqrt[Pi/2]*Cos[a]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*x^(1/6)])/b^(3/2)) - (3*Sqrt[Pi/2]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*x^(1/6)]*Sin[a])/b^(3/2) + (3*x^(1/6)*Sin[a + b*x^(1/3)])/b}
{Cos[a + b*x^(1/3)]/x^(3/2), x, 6, -((2*Cos[a + b*x^(1/3)])/Sqrt[x]) - 4*b^(3/2)*Sqrt[2*Pi]*Cos[a]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*x^(1/6)] + 4*b^(3/2)*Sqrt[2*Pi]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*x^(1/6)]*Sin[a] + (4*b*Sin[a + b*x^(1/3)])/x^(1/6)}
{Cos[a + b*x^(1/3)]/x^(5/2), x, 9, -((2*Cos[a + b*x^(1/3)])/(3*x^(3/2))) + (8*b^2*Cos[a + b*x^(1/3)])/(105*x^(5/6)) - (32*b^4*Cos[a + b*x^(1/3)])/(315*x^(1/6)) - (32/315)*b^(9/2)*Sqrt[2*Pi]*Cos[a]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*x^(1/6)] - (32/315)*b^(9/2)*Sqrt[2*Pi]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*x^(1/6)]*Sin[a] + (4*b*Sin[a + b*x^(1/3)])/(21*x^(7/6)) - (16*b^3*Sin[a + b*x^(1/3)])/(315*Sqrt[x])}
{Cos[a + b*x^(1/3)]/x^(7/2), x, 12, -((2*Cos[a + b*x^(1/3)])/(5*x^(5/2))) + (8*b^2*Cos[a + b*x^(1/3)])/(715*x^(11/6)) - (32*b^4*Cos[a + b*x^(1/3)])/(45045*x^(7/6)) + (128*b^6*Cos[a + b*x^(1/3)])/(675675*Sqrt[x]) + (256*b^(15/2)*Sqrt[2*Pi]*Cos[a]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*x^(1/6)])/675675 - (256*b^(15/2)*Sqrt[2*Pi]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*x^(1/6)]*Sin[a])/675675 + (4*b*Sin[a + b*x^(1/3)])/(65*x^(13/6)) - (16*b^3*Sin[a + b*x^(1/3)])/(6435*x^(3/2)) + (64*b^5*Sin[a + b*x^(1/3)])/(225225*x^(5/6)) - (256*b^7*Sin[a + b*x^(1/3)])/(675675*x^(1/6))}


{x^(3/2)*Cos[a + b*x^(1/3)]^2, x, 13, -((135135*Sqrt[x])/(4096*b^6)) + (3861*x^(7/6))/(256*b^4) - (39*x^(11/6))/(16*b^2) + x^(5/2)/5 + (135135*Sqrt[x]*Cos[a + b*x^(1/3)]^2)/(2048*b^6) - (3861*x^(7/6)*Cos[a + b*x^(1/3)]^2)/(128*b^4) + (39*x^(11/6)*Cos[a + b*x^(1/3)]^2)/(8*b^2) + (405405*Sqrt[Pi]*Cos[2*a]*FresnelS[(2*Sqrt[b]*x^(1/6))/Sqrt[Pi]])/(32768*b^(15/2)) + (405405*Sqrt[Pi]*FresnelC[(2*Sqrt[b]*x^(1/6))/Sqrt[Pi]]*Sin[2*a])/(32768*b^(15/2)) + (27027*x^(5/6)*Cos[a + b*x^(1/3)]*Sin[a + b*x^(1/3)])/(512*b^5) - (429*x^(3/2)*Cos[a + b*x^(1/3)]*Sin[a + b*x^(1/3)])/(32*b^3) + (3*x^(13/6)*Cos[a + b*x^(1/3)]*Sin[a + b*x^(1/3)])/(2*b) - (405405*x^(1/6)*Sin[2*a + 2*b*x^(1/3)])/(16384*b^7)}
{x^(1/2)*Cos[a + b*x^(1/3)]^2, x, 10, (315*x^(1/6))/(256*b^4) - (21*x^(5/6))/(16*b^2) + x^(3/2)/3 - (315*x^(1/6)*Cos[a + b*x^(1/3)]^2)/(128*b^4) + (21*x^(5/6)*Cos[a + b*x^(1/3)]^2)/(8*b^2) + (315*Sqrt[Pi]*Cos[2*a]*FresnelC[(2*Sqrt[b]*x^(1/6))/Sqrt[Pi]])/(512*b^(9/2)) - (315*Sqrt[Pi]*FresnelS[(2*Sqrt[b]*x^(1/6))/Sqrt[Pi]]*Sin[2*a])/(512*b^(9/2)) - (105*Sqrt[x]*Cos[a + b*x^(1/3)]*Sin[a + b*x^(1/3)])/(32*b^3) + (3*x^(7/6)*Cos[a + b*x^(1/3)]*Sin[a + b*x^(1/3)])/(2*b)}
{Cos[a + b*x^(1/3)]^2/x^(1/2), x, 7, Sqrt[x] - (3*Sqrt[Pi]*Cos[2*a]*FresnelS[(2*Sqrt[b]*x^(1/6))/Sqrt[Pi]])/(8*b^(3/2)) - (3*Sqrt[Pi]*FresnelC[(2*Sqrt[b]*x^(1/6))/Sqrt[Pi]]*Sin[2*a])/(8*b^(3/2)) + (3*x^(1/6)*Sin[2*a + 2*b*x^(1/3)])/(4*b)}
{Cos[a + b*x^(1/3)]^2/x^(3/2), x, 8, -((2*Cos[a + b*x^(1/3)]^2)/Sqrt[x]) - 8*b^(3/2)*Sqrt[Pi]*Cos[2*a]*FresnelC[(2*Sqrt[b]*x^(1/6))/Sqrt[Pi]] + 8*b^(3/2)*Sqrt[Pi]*FresnelS[(2*Sqrt[b]*x^(1/6))/Sqrt[Pi]]*Sin[2*a] + (8*b*Cos[a + b*x^(1/3)]*Sin[a + b*x^(1/3)])/x^(1/6)}
{Cos[a + b*x^(1/3)]^2/x^(5/2), x, 10, -((16*b^2)/(105*x^(5/6))) + (256*b^4)/(315*x^(1/6)) - (2*Cos[a + b*x^(1/3)]^2)/(3*x^(3/2)) + (32*b^2*Cos[a + b*x^(1/3)]^2)/(105*x^(5/6)) - (512*b^4*Cos[a + b*x^(1/3)]^2)/(315*x^(1/6)) - (512/315)*b^(9/2)*Sqrt[Pi]*Cos[2*a]*FresnelS[(2*Sqrt[b]*x^(1/6))/Sqrt[Pi]] - (512/315)*b^(9/2)*Sqrt[Pi]*FresnelC[(2*Sqrt[b]*x^(1/6))/Sqrt[Pi]]*Sin[2*a] + (8*b*Cos[a + b*x^(1/3)]*Sin[a + b*x^(1/3)])/(21*x^(7/6)) - (128*b^3*Cos[a + b*x^(1/3)]*Sin[a + b*x^(1/3)])/(315*Sqrt[x])}
{Cos[a + b*x^(1/3)]^2/x^(7/2), x, 14, -((16*b^2)/(715*x^(11/6))) + (256*b^4)/(45045*x^(7/6)) - (4096*b^6)/(675675*Sqrt[x]) - (2*Cos[a + b*x^(1/3)]^2)/(5*x^(5/2)) + (32*b^2*Cos[a + b*x^(1/3)]^2)/(715*x^(11/6)) - (512*b^4*Cos[a + b*x^(1/3)]^2)/(45045*x^(7/6)) + (8192*b^6*Cos[a + b*x^(1/3)]^2)/(675675*Sqrt[x]) + (32768*b^(15/2)*Sqrt[Pi]*Cos[2*a]*FresnelC[(2*Sqrt[b]*x^(1/6))/Sqrt[Pi]])/675675 - (32768*b^(15/2)*Sqrt[Pi]*FresnelS[(2*Sqrt[b]*x^(1/6))/Sqrt[Pi]]*Sin[2*a])/675675 + (8*b*Cos[a + b*x^(1/3)]*Sin[a + b*x^(1/3)])/(65*x^(13/6)) - (128*b^3*Cos[a + b*x^(1/3)]*Sin[a + b*x^(1/3)])/(6435*x^(3/2)) + (2048*b^5*Cos[a + b*x^(1/3)]*Sin[a + b*x^(1/3)])/(225225*x^(5/6)) - (32768*b^7*Cos[a + b*x^(1/3)]*Sin[a + b*x^(1/3)])/(675675*x^(1/6))}


{Cos[x^(1/3)]^3, x, 7, 4*x^(1/3)*Cos[x^(1/3)] + (2/3)*x^(1/3)*Cos[x^(1/3)]^3 - (14/3)*Sin[x^(1/3)] + 2*x^(2/3)*Sin[x^(1/3)] + x^(2/3)*Cos[x^(1/3)]^2*Sin[x^(1/3)] + (2/9)*Sin[x^(1/3)]^3}
{Cos[x^(1/6)]/x^(5/6), x, 1, 6*Sin[x^(1/6)]}


{Cos[a + b*x^n], x, 3, -((E^(I*a)*x*Gamma[1/n, (-I)*b*x^n])/(((-I)*b*x^n)^n^(-1)*(2*n))) - (x*Gamma[1/n, I*b*x^n])/(E^(I*a)*(I*b*x^n)^n^(-1)*(2*n))}
{Cos[a + b*x^n]^2, x, 5, x/2 - (2^(-2 - 1/n)*E^(2*I*a)*x*Gamma[1/n, -2*I*b*x^n])/(((-I)*b*x^n)^n^(-1)*n) - (2^(-2 - 1/n)*x*Gamma[1/n, 2*I*b*x^n])/(E^(2*I*a)*(I*b*x^n)^n^(-1)*n)}
{Cos[a + b*x^n]^3, x, 8, -((3*E^(I*a)*x*Gamma[1/n, (-I)*b*x^n])/(((-I)*b*x^n)^n^(-1)*(8*n))) - (3*x*Gamma[1/n, I*b*x^n])/(E^(I*a)*(I*b*x^n)^n^(-1)*(8*n)) - (E^(3*I*a)*x*Gamma[1/n, -3*I*b*x^n])/(3^n^(-1)*((-I)*b*x^n)^n^(-1)*(8*n)) - (x*Gamma[1/n, 3*I*b*x^n])/(3^n^(-1)*E^(3*I*a)*(I*b*x^n)^n^(-1)*(8*n))}

{x^m*Cos[a + b*x^n], x, 3, -((E^(I*a)*x^(1 + m)*Gamma[(1 + m)/n, (-I)*b*x^n])/(((-I)*b*x^n)^((1 + m)/n)*(2*n))) - (x^(1 + m)*Gamma[(1 + m)/n, I*b*x^n])/(E^(I*a)*(I*b*x^n)^((1 + m)/n)*(2*n))}
{x^m*Cos[a + b*x^n]^2, x, 5, x^(1 + m)/(2*(1 + m)) - (E^(2*I*a)*x^(1 + m)*Gamma[(1 + m)/n, -2*I*b*x^n])/(2^((1 + m + 2*n)/n)*((-I)*b*x^n)^((1 + m)/n)*n) - (x^(1 + m)*Gamma[(1 + m)/n, 2*I*b*x^n])/(2^((1 + m + 2*n)/n)*E^(2*I*a)*(I*b*x^n)^((1 + m)/n)*n)}
{x^m*Cos[a + b*x^n]^3, x, 8, -((3*E^(I*a)*x^(1 + m)*Gamma[(1 + m)/n, (-I)*b*x^n])/(((-I)*b*x^n)^((1 + m)/n)*(8*n))) - (3*x^(1 + m)*Gamma[(1 + m)/n, I*b*x^n])/(E^(I*a)*(I*b*x^n)^((1 + m)/n)*(8*n)) - (E^(3*I*a)*x^(1 + m)*Gamma[(1 + m)/n, -3*I*b*x^n])/(3^((1 + m)/n)*((-I)*b*x^n)^((1 + m)/n)*(8*n)) - (x^(1 + m)*Gamma[(1 + m)/n, 3*I*b*x^n])/(3^((1 + m)/n)*E^(3*I*a)*(I*b*x^n)^((1 + m)/n)*(8*n))}


{Cos[a + b*x^n]/x^(n + 1), x, 4, -(Cos[a + b*x^n]/(x^n*n)) - (b*CosIntegral[b*x^n]*Sin[a])/n - (b*Cos[a]*SinIntegral[b*x^n])/n}
{Cos[a + b*x^n]^2/x^(n + 1), x, 6, -(1/(x^n*(2*n))) - Cos[2*a + 2*b*x^n]/(x^n*(2*n)) - (b*CosIntegral[2*b*x^n]*Sin[2*a])/n - (b*Cos[2*a]*SinIntegral[2*b*x^n])/n}
{Cos[a + b*x^n]^3/x^(n + 1), x, 10, -((3*Cos[a + b*x^n])/(x^n*(4*n))) - Cos[3*a + 3*b*x^n]/(x^n*(4*n)) - (3*b*CosIntegral[b*x^n]*Sin[a])/(4*n) - (3*b*CosIntegral[3*b*x^n]*Sin[3*a])/(4*n) - (3*b*Cos[a]*SinIntegral[b*x^n])/(4*n) - (3*b*Cos[3*a]*SinIntegral[3*b*x^n])/(4*n)}

{Cos[a + b*x^n]/x^(2*n + 1), x, 5, -(Cos[a + b*x^n]/(x^(2*n)*(2*n))) - (b^2*Cos[a]*CosIntegral[b*x^n])/(2*n) + (b*Sin[a + b*x^n])/(x^n*(2*n)) + (b^2*Sin[a]*SinIntegral[b*x^n])/(2*n)}
{Cos[a + b*x^n]^2/x^(2*n + 1), x, 7, -(1/(x^(2*n)*(4*n))) - Cos[2*a + 2*b*x^n]/(x^(2*n)*(4*n)) - (b^2*Cos[2*a]*CosIntegral[2*b*x^n])/n + (b*Sin[2*a + 2*b*x^n])/(x^n*(2*n)) + (b^2*Sin[2*a]*SinIntegral[2*b*x^n])/n}
{Cos[a + b*x^n]^3/x^(2*n + 1), x, 12, -((3*Cos[a + b*x^n])/(x^(2*n)*(8*n))) - Cos[3*a + 3*b*x^n]/(x^(2*n)*(8*n)) - (3*b^2*Cos[a]*CosIntegral[b*x^n])/(8*n) - (9*b^2*Cos[3*a]*CosIntegral[3*b*x^n])/(8*n) + (3*b*Sin[a + b*x^n])/(x^n*(8*n)) + (3*b*Sin[3*a + 3*b*x^n])/(x^n*(8*n)) + (3*b^2*Sin[a]*SinIntegral[b*x^n])/(8*n) + (9*b^2*Sin[3*a]*SinIntegral[3*b*x^n])/(8*n)}


(* ::Title:: *)
(*Integration problems of the form x^m Tan[a+b x^n]^p*)


(* ::Section::Closed:: *)
(*Integrands of the form x^m Tan[a+b x]^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Tan[a+b x]^p*)


{x^3*Tan[a + b*x], x, 6, (I*x^4)/4 - (x^3*Log[1 + E^(2*I*a + 2*I*b*x)])/b + (3*I*x^2*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/(2*b^2) - (3*x*PolyLog[3, -E^(2*I*a + 2*I*b*x)])/(2*b^3) - (3*I*PolyLog[4, -E^(2*I*a + 2*I*b*x)])/(4*b^4)}
{x^2*Tan[a + b*x], x, 5, (I*x^3)/3 - (x^2*Log[1 + E^(2*I*a + 2*I*b*x)])/b + (I*x*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/b^2 - PolyLog[3, -E^(2*I*a + 2*I*b*x)]/(2*b^3)}
{x*Tan[a + b*x], x, 4, (I*x^2)/2 - (x*Log[1 + E^(2*I*a + 2*I*b*x)])/b + (I*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/(2*b^2)}
{Tan[a + b*x]/x, x, 0, Int[Tan[a + b*x]/x, x]}
{Tan[a + b*x]/x^2, x, 0, Int[Tan[a + b*x]/x^2, x]}
{Tan[a + b*x]/x^3, x, 0, Int[Tan[a + b*x]/x^3, x]}


{x^3*Tan[a + b*x]^2, x, 7, -((I*x^3)/b) - x^4/4 + (3*x^2*Log[1 + E^(2*I*a + 2*I*b*x)])/b^2 - (3*I*x*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/b^3 + (3*PolyLog[3, -E^(2*I*a + 2*I*b*x)])/(2*b^4) + (x^3*Tan[a + b*x])/b}
{x^2*Tan[a + b*x]^2, x, 6, -((I*x^2)/b) - x^3/3 + (2*x*Log[1 + E^(2*I*a + 2*I*b*x)])/b^2 - (I*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/b^3 + (x^2*Tan[a + b*x])/b}
{x*Tan[a + b*x]^2, x, 3, -x^2/2 + Log[Cos[a + b*x]]/b^2 + (x*Tan[a + b*x])/b}
{Tan[a + b*x]^2/x, x, 0, Int[Tan[a + b*x]^2/x, x]}
{Tan[a + b*x]^2/x^2, x, 0, Int[Tan[a + b*x]^2/x^2, x]}
{Tan[a + b*x]^2/x^3, x, 0, Int[Tan[a + b*x]^2/x^3, x]}


{x^3*Tan[a + b*x]^3, x, 13, (3*I*x^2)/(2*b^2) + x^3/(2*b) - (I*x^4)/4 - (3*x*Log[1 + E^(2*I*a + 2*I*b*x)])/b^3 + (x^3*Log[1 + E^(2*I*a + 2*I*b*x)])/b + (3*I*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/(2*b^4) - (3*I*x^2*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/(2*b^2) + (3*x*PolyLog[3, -E^(2*I*a + 2*I*b*x)])/(2*b^3) + (3*I*PolyLog[4, -E^(2*I*a + 2*I*b*x)])/(4*b^4) - (3*x^2*Tan[a + b*x])/(2*b^2) + (x^3*Tan[a + b*x]^2)/(2*b)}
{x^2*Tan[a + b*x]^3, x, 9, x^2/(2*b) - (I*x^3)/3 + (x^2*Log[1 + E^(2*I*a + 2*I*b*x)])/b - Log[Cos[a + b*x]]/b^3 - (I*x*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/b^2 + PolyLog[3, -E^(2*I*a + 2*I*b*x)]/(2*b^3) - (x*Tan[a + b*x])/b^2 + (x^2*Tan[a + b*x]^2)/(2*b)}
{x*Tan[a + b*x]^3, x, 7, x/(2*b) - (I*x^2)/2 + (x*Log[1 + E^(2*I*a + 2*I*b*x)])/b - (I*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/(2*b^2) - Tan[a + b*x]/(2*b^2) + (x*Tan[a + b*x]^2)/(2*b)}
{Tan[a + b*x]^3/x, x, 0, Int[Tan[a + b*x]^3/x, x]}
{Tan[a + b*x]^3/x^2, x, 0, Int[Tan[a + b*x]^3/x^2, x]}
{Tan[a + b*x]^3/x^3, x, 0, Int[Tan[a + b*x]^3/x^3, x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Tan[a+b x]^(p/2)*)


{x^2/Tan[a + b*x]^(3/2) - (4*x)/(b*Sqrt[Tan[a + b*x]]) + x^2*Sqrt[Tan[a + b*x]], x, 2, -((2*x^2)/(b*Sqrt[Tan[a + b*x]]))}
{x^2*Tan[a + b*x^2]^(3/2) + x^2/Sqrt[Tan[a + b*x^2]] + Sqrt[Tan[a + b*x^2]]/b, x, 2, (x*Sqrt[Tan[a + b*x^2]])/b}


(* ::Section:: *)
(*Integrands of the form x^m Tan[a+b x^2]^p*)


(* ::Section:: *)
(*Integrands of the form x^m Tan[a+b x^n]^p*)


(* ::Title:: *)
(*Integration problems of the form x^m Cot[a+b x^n]^p*)


(* ::Section::Closed:: *)
(*Integrands of the form x^m Cot[a+b x]^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Cot[a+b x]^p*)


{x^3*Cot[a + b*x], x, 6, -((I*x^4)/4) + (x^3*Log[1 - E^(2*I*a + 2*I*b*x)])/b - (3*I*x^2*PolyLog[2, E^(2*I*a + 2*I*b*x)])/(2*b^2) + (3*x*PolyLog[3, E^(2*I*a + 2*I*b*x)])/(2*b^3) + (3*I*PolyLog[4, E^(2*I*a + 2*I*b*x)])/(4*b^4)}
{x^2*Cot[a + b*x], x, 5, -((I*x^3)/3) + (x^2*Log[1 - E^(2*I*a + 2*I*b*x)])/b - (I*x*PolyLog[2, E^(2*I*a + 2*I*b*x)])/b^2 + PolyLog[3, E^(2*I*a + 2*I*b*x)]/(2*b^3)}
{x*Cot[a + b*x], x, 4, -((I*x^2)/2) + (x*Log[1 - E^(2*I*a + 2*I*b*x)])/b - (I*PolyLog[2, E^(2*I*a + 2*I*b*x)])/(2*b^2)}
{Cot[a + b*x]/x, x, 0, Int[Cot[a + b*x]/x, x]}
{Cot[a + b*x]/x^2, x, 0, Int[Cot[a + b*x]/x^2, x]}
{Cot[a + b*x]/x^3, x, 0, Int[Cot[a + b*x]/x^3, x]}


{x^3*Cot[a + b*x]^2, x, 7, -((I*x^3)/b) - x^4/4 - (x^3*Cot[a + b*x])/b + (3*x^2*Log[1 - E^(2*I*a + 2*I*b*x)])/b^2 - (3*I*x*PolyLog[2, E^(2*I*a + 2*I*b*x)])/b^3 + (3*PolyLog[3, E^(2*I*a + 2*I*b*x)])/(2*b^4)}
{x^2*Cot[a + b*x]^2, x, 6, -((I*x^2)/b) - x^3/3 - (x^2*Cot[a + b*x])/b + (2*x*Log[1 - E^(2*I*a + 2*I*b*x)])/b^2 - (I*PolyLog[2, E^(2*I*a + 2*I*b*x)])/b^3}
{x*Cot[a + b*x]^2, x, 3, -x^2/2 - (x*Cot[a + b*x])/b + Log[Sin[a + b*x]]/b^2}
{Cot[a + b*x]^2/x, x, 0, Int[Cot[a + b*x]^2/x, x]}
{Cot[a + b*x]^2/x^2, x, 0, Int[Cot[a + b*x]^2/x^2, x]}
{Cot[a + b*x]^2/x^3, x, 0, Int[Cot[a + b*x]^2/x^3, x]}


{x^3*Cot[a + b*x]^3, x, 13, -((3*I*x^2)/(2*b^2)) - x^3/(2*b) + (I*x^4)/4 - (3*x^2*Cot[a + b*x])/(2*b^2) - (x^3*Cot[a + b*x]^2)/(2*b) + (3*x*Log[1 - E^(2*I*a + 2*I*b*x)])/b^3 - (x^3*Log[1 - E^(2*I*a + 2*I*b*x)])/b - (3*I*PolyLog[2, E^(2*I*a + 2*I*b*x)])/(2*b^4) + (3*I*x^2*PolyLog[2, E^(2*I*a + 2*I*b*x)])/(2*b^2) - (3*x*PolyLog[3, E^(2*I*a + 2*I*b*x)])/(2*b^3) - (3*I*PolyLog[4, E^(2*I*a + 2*I*b*x)])/(4*b^4)}
{x^2*Cot[a + b*x]^3, x, 9, -(x^2/(2*b)) + (I*x^3)/3 - (x*Cot[a + b*x])/b^2 - (x^2*Cot[a + b*x]^2)/(2*b) - (x^2*Log[1 - E^(2*I*a + 2*I*b*x)])/b + Log[Sin[a + b*x]]/b^3 + (I*x*PolyLog[2, E^(2*I*a + 2*I*b*x)])/b^2 - PolyLog[3, E^(2*I*a + 2*I*b*x)]/(2*b^3)}
{x*Cot[a + b*x]^3, x, 7, -(x/(2*b)) + (I*x^2)/2 - Cot[a + b*x]/(2*b^2) - (x*Cot[a + b*x]^2)/(2*b) - (x*Log[1 - E^(2*I*a + 2*I*b*x)])/b + (I*PolyLog[2, E^(2*I*a + 2*I*b*x)])/(2*b^2)}
{Cot[a + b*x]^3/x, x, 0, Int[Cot[a + b*x]^3/x, x]}
{Cot[a + b*x]^3/x^2, x, 0, Int[Cot[a + b*x]^3/x^2, x]}
{Cot[a + b*x]^3/x^3, x, 0, Int[Cot[a + b*x]^3/x^3, x]}


(* ::Subsection:: *)
(*Integrands of the form x^m Cot[a+b x]^(p/2)*)


(* ::Section:: *)
(*Integrands of the form x^m Cot[a+b x^2]^p*)


(* ::Section:: *)
(*Integrands of the form x^m Cot[a+b x^n]^p*)


(* ::Title:: *)
(*Integration problems of the form x^m Sec[a+b x^n]^p*)


(* ::Section::Closed:: *)
(*Integrands of the form x^m Sec[a+b x]^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Sec[a+b x]^p*)


{x^3*Sec[a + b*x], x, 7, -((2*I*x^3*ArcTan[E^(I*a + I*b*x)])/b) + (3*I*x^2*PolyLog[2, (-I)*E^(I*(a + b*x))])/b^2 - (3*I*x^2*PolyLog[2, I*E^(I*(a + b*x))])/b^2 - (6*x*PolyLog[3, (-I)*E^(I*(a + b*x))])/b^3 + (6*x*PolyLog[3, I*E^(I*(a + b*x))])/b^3 - (6*I*PolyLog[4, (-I)*E^(I*(a + b*x))])/b^4 + (6*I*PolyLog[4, I*E^(I*(a + b*x))])/b^4}
{x^2*Sec[a + b*x], x, 5, -((2*I*x^2*ArcTan[E^(I*a + I*b*x)])/b) + (2*I*x*PolyLog[2, (-I)*E^(I*(a + b*x))])/b^2 - (2*I*x*PolyLog[2, I*E^(I*(a + b*x))])/b^2 - (2*PolyLog[3, (-I)*E^(I*(a + b*x))])/b^3 + (2*PolyLog[3, I*E^(I*(a + b*x))])/b^3}
{x^1*Sec[a + b*x], x, 3, -((2*I*x*ArcTan[E^(I*a + I*b*x)])/b) + (I*PolyLog[2, (-I)*E^(I*(a + b*x))])/b^2 - (I*PolyLog[2, I*E^(I*(a + b*x))])/b^2}
{x^0*Sec[a + b*x], x, 1, ArcTanh[Sin[a + b*x]]/b}
{Sec[a + b*x]/x^1, x, 0, Int[Sec[a + b*x]/x, x]}


{x^3*Sec[a + b*x]^2, x, 6, -((I*x^3)/b) + (3*x^2*Log[1 + E^(2*I*a + 2*I*b*x)])/b^2 - (3*I*x*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/b^3 + (3*PolyLog[3, -E^(2*I*a + 2*I*b*x)])/(2*b^4) + (x^3*Tan[a + b*x])/b}
{x^2*Sec[a + b*x]^2, x, 5, -((I*x^2)/b) + (2*x*Log[1 + E^(2*I*a + 2*I*b*x)])/b^2 - (I*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/b^3 + (x^2*Tan[a + b*x])/b}
{x^1*Sec[a + b*x]^2, x, 2, Log[Cos[a + b*x]]/b^2 + (x*Tan[a + b*x])/b}
{x^0*Sec[a + b*x]^2, x, 1, Tan[a + b*x]/b}
{Sec[a + b*x]^2/x^1, x, 0, Int[Sec[a + b*x]^2/x, x]}


{x^3*Sec[a + b*x]^3, x, 11, -((6*I*x*ArcTan[E^(I*a + I*b*x)])/b^3) - (I*x^3*ArcTan[E^(I*a + I*b*x)])/b + (3*I*PolyLog[2, (-I)*E^(I*(a + b*x))])/b^4 + (3*I*x^2*PolyLog[2, (-I)*E^(I*(a + b*x))])/(2*b^2) - (3*I*PolyLog[2, I*E^(I*(a + b*x))])/b^4 - (3*I*x^2*PolyLog[2, I*E^(I*(a + b*x))])/(2*b^2) - (3*x*PolyLog[3, (-I)*E^(I*(a + b*x))])/b^3 + (3*x*PolyLog[3, I*E^(I*(a + b*x))])/b^3 - (3*I*PolyLog[4, (-I)*E^(I*(a + b*x))])/b^4 + (3*I*PolyLog[4, I*E^(I*(a + b*x))])/b^4 - (3*x^2*Sec[a + b*x])/(2*b^2) + (x^3*Sec[a + b*x]*Tan[a + b*x])/(2*b)}
{x^2*Sec[a + b*x]^3, x, 7, -((I*x^2*ArcTan[E^(I*a + I*b*x)])/b) + ArcTanh[Sin[a + b*x]]/b^3 + (I*x*PolyLog[2, (-I)*E^(I*(a + b*x))])/b^2 - (I*x*PolyLog[2, I*E^(I*(a + b*x))])/b^2 - PolyLog[3, (-I)*E^(I*(a + b*x))]/b^3 + PolyLog[3, I*E^(I*(a + b*x))]/b^3 - (x*Sec[a + b*x])/b^2 + (x^2*Sec[a + b*x]*Tan[a + b*x])/(2*b)}
{x^1*Sec[a + b*x]^3, x, 4, -((I*x*ArcTan[E^(I*a + I*b*x)])/b) + (I*PolyLog[2, (-I)*E^(I*(a + b*x))])/(2*b^2) - (I*PolyLog[2, I*E^(I*(a + b*x))])/(2*b^2) - Sec[a + b*x]/(2*b^2) + (x*Sec[a + b*x]*Tan[a + b*x])/(2*b)}
{x^0*Sec[a + b*x]^3, x, 2, ArcTanh[Sin[a + b*x]]/(2*b) + (Sec[a + b*x]*Tan[a + b*x])/(2*b)}
{Sec[a + b*x]^3/x^1, x, 0, Int[Sec[a + b*x]^3/x, x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Sec[a+b x]^(p/2)*)


{x/Sec[x]^(3/2) - (1/3)*x*Sqrt[Sec[x]], x, 4, 4/(9*Sec[x]^(3/2)) + (2*x*Sin[x])/(3*Sqrt[Sec[x]])}
{x/Sec[x]^(5/2) - (3/5)*x/Sqrt[Sec[x]], x, 4, 4/(25*Sec[x]^(5/2)) + (2*x*Sin[x])/(5*Sec[x]^(3/2))}
{x/Sec[x]^(7/2) - (5/21)*x*Sqrt[Sec[x]], x, 5, 4/(49*Sec[x]^(7/2)) + 20/(63*Sec[x]^(3/2)) + (2*x*Sin[x])/(7*Sec[x]^(5/2)) + (10*x*Sin[x])/(21*Sqrt[Sec[x]])}
{x^2/Sec[x]^(3/2) - (1/3)*x^2*Sqrt[Sec[x]], x, 7, (8*x)/(9*Sec[x]^(3/2)) - (16/27)*Sqrt[Cos[x]]*EllipticF[x/2, 2]*Sqrt[Sec[x]] - (16*Sin[x])/(27*Sqrt[Sec[x]]) + (2*x^2*Sin[x])/(3*Sqrt[Sec[x]])}


(* ::Subsection:: *)
(*Integrands of the form x^(m/2) Sec[a+b x]^p*)


(* ::Subsection:: *)
(*Integrands of the form x^(m/2) Sec[a+b x]^(p/2)*)


(* ::Section::Closed:: *)
(*Integrands of the form (c+d x)^m Sec[a+b x]^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (c+d x)^m Sec[a+b x]^p*)


{(c + d*x)*Sec[a + b*x], x, 3, -((2*I*(c + d*x)*ArcTan[E^(I*a + I*b*x)])/b) + (I*d*PolyLog[2, (-I)*E^(I*(a + b*x))])/b^2 - (I*d*PolyLog[2, I*E^(I*(a + b*x))])/b^2}
{(c + d*x)^2*Sec[a + b*x], x, 5, -((2*I*(c + d*x)^2*ArcTan[E^(I*a + I*b*x)])/b) + (2*I*d*(c + d*x)*PolyLog[2, (-I)*E^(I*(a + b*x))])/b^2 - (2*I*d*(c + d*x)*PolyLog[2, I*E^(I*(a + b*x))])/b^2 - (2*d^2*PolyLog[3, (-I)*E^(I*(a + b*x))])/b^3 + (2*d^2*PolyLog[3, I*E^(I*(a + b*x))])/b^3}
{(c + d*x)^3*Sec[a + b*x], x, 7, -((2*I*(c + d*x)^3*ArcTan[E^(I*a + I*b*x)])/b) + (3*I*d*(c + d*x)^2*PolyLog[2, (-I)*E^(I*(a + b*x))])/b^2 - (3*I*d*(c + d*x)^2*PolyLog[2, I*E^(I*(a + b*x))])/b^2 - (6*d^2*(c + d*x)*PolyLog[3, (-I)*E^(I*(a + b*x))])/b^3 + (6*d^2*(c + d*x)*PolyLog[3, I*E^(I*(a + b*x))])/b^3 - (6*I*d^3*PolyLog[4, (-I)*E^(I*(a + b*x))])/b^4 + (6*I*d^3*PolyLog[4, I*E^(I*(a + b*x))])/b^4}


{(c + d*x)*Sec[a + b*x]^2, x, 2, (d*Log[Cos[a + b*x]])/b^2 + ((c + d*x)*Tan[a + b*x])/b}
{(c + d*x)^2*Sec[a + b*x]^2, x, 5, -((I*(c + d*x)^2)/b) + (2*d*(c + d*x)*Log[1 + E^(2*I*a + 2*I*b*x)])/b^2 - (I*d^2*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/b^3 + ((c + d*x)^2*Tan[a + b*x])/b}
{(c + d*x)^3*Sec[a + b*x]^2, x, 6, -((I*(c + d*x)^3)/b) + (3*d*(c + d*x)^2*Log[1 + E^(2*I*a + 2*I*b*x)])/b^2 - (3*I*d^2*(c + d*x)*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/b^3 + (3*d^3*PolyLog[3, -E^(2*I*a + 2*I*b*x)])/(2*b^4) + ((c + d*x)^3*Tan[a + b*x])/b}


{(c + d*x)*Sec[a + b*x]^3, x, 4, -((I*(c + d*x)*ArcTan[E^(I*a + I*b*x)])/b) + (I*d*PolyLog[2, (-I)*E^(I*(a + b*x))])/(2*b^2) - (I*d*PolyLog[2, I*E^(I*(a + b*x))])/(2*b^2) - (d*Sec[a + b*x])/(2*b^2) + ((c + d*x)*Sec[a + b*x]*Tan[a + b*x])/(2*b)}
{(c + d*x)^2*Sec[a + b*x]^3, x, 7, -((I*(c + d*x)^2*ArcTan[E^(I*a + I*b*x)])/b) + (d^2*ArcTanh[Sin[a + b*x]])/b^3 + (I*d*(c + d*x)*PolyLog[2, (-I)*E^(I*(a + b*x))])/b^2 - (I*d*(c + d*x)*PolyLog[2, I*E^(I*(a + b*x))])/b^2 - (d^2*PolyLog[3, (-I)*E^(I*(a + b*x))])/b^3 + (d^2*PolyLog[3, I*E^(I*(a + b*x))])/b^3 - (d*(c + d*x)*Sec[a + b*x])/b^2 + ((c + d*x)^2*Sec[a + b*x]*Tan[a + b*x])/(2*b)}
{(c + d*x)^3*Sec[a + b*x]^3, x, 11, -((6*I*d^2*(c + d*x)*ArcTan[E^(I*a + I*b*x)])/b^3) - (I*(c + d*x)^3*ArcTan[E^(I*a + I*b*x)])/b + (3*I*d^3*PolyLog[2, (-I)*E^(I*(a + b*x))])/b^4 + (3*I*d*(c + d*x)^2*PolyLog[2, (-I)*E^(I*(a + b*x))])/(2*b^2) - (3*I*d^3*PolyLog[2, I*E^(I*(a + b*x))])/b^4 - (3*I*d*(c + d*x)^2*PolyLog[2, I*E^(I*(a + b*x))])/(2*b^2) - (3*d^2*(c + d*x)*PolyLog[3, (-I)*E^(I*(a + b*x))])/b^3 + (3*d^2*(c + d*x)*PolyLog[3, I*E^(I*(a + b*x))])/b^3 - (3*I*d^3*PolyLog[4, (-I)*E^(I*(a + b*x))])/b^4 + (3*I*d^3*PolyLog[4, I*E^(I*(a + b*x))])/b^4 - (3*d*(c + d*x)^2*Sec[a + b*x])/(2*b^2) + ((c + d*x)^3*Sec[a + b*x]*Tan[a + b*x])/(2*b)}


(* ::Subsection:: *)
(*Integrands of the form (c+d x)^m Sec[a+b x]^(p/2)*)


(* ::Section::Closed:: *)
(*Integrands of the form x^m Sec[a+b x^2]^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Sec[a+b x^2]^p*)


{x*Sec[a + b*x^2]^7, x, 5, (5*ArcTanh[Sin[a + b*x^2]])/(32*b) + (5*Sec[a + b*x^2]*Tan[a + b*x^2])/(32*b) + (5*Sec[a + b*x^2]^3*Tan[a + b*x^2])/(48*b) + (Sec[a + b*x^2]^5*Tan[a + b*x^2])/(12*b)}


(* ::Subsection:: *)
(*Integrands of the form x^m Sec[a+b x^2]^(p/2)*)


(* ::Subsection:: *)
(*Integrands of the form x^(m/2) Sec[a+b x^2]^p*)


(* ::Subsection:: *)
(*Integrands of the form x^(m/2) Sec[a+b x^2]^(p/2)*)


(* ::Section::Closed:: *)
(*Integrands of the form x^m Sec[a+b x^n]^p*)


{Sec[Sqrt[x]]/Sqrt[x], x, 2, 2*ArcTanh[Sin[Sqrt[x]]]}


(* ::Title:: *)
(*Integration problems of the form x^m Csc[a+b x^n]^p*)


(* ::Section::Closed:: *)
(*Integrands of the form x^m Csc[a+b x]^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Csc[a+b x]^p*)


{x^3*Csc[a + b*x], x, 7, -((2*x^3*ArcTanh[E^(I*a + I*b*x)])/b) + (3*I*x^2*PolyLog[2, -E^(I*(a + b*x))])/b^2 - (3*I*x^2*PolyLog[2, E^(I*(a + b*x))])/b^2 - (6*x*PolyLog[3, -E^(I*(a + b*x))])/b^3 + (6*x*PolyLog[3, E^(I*(a + b*x))])/b^3 - (6*I*PolyLog[4, -E^(I*(a + b*x))])/b^4 + (6*I*PolyLog[4, E^(I*(a + b*x))])/b^4}
{x^2*Csc[a + b*x], x, 5, -((2*x^2*ArcTanh[E^(I*a + I*b*x)])/b) + (2*I*x*PolyLog[2, -E^(I*(a + b*x))])/b^2 - (2*I*x*PolyLog[2, E^(I*(a + b*x))])/b^2 - (2*PolyLog[3, -E^(I*(a + b*x))])/b^3 + (2*PolyLog[3, E^(I*(a + b*x))])/b^3}
{x^1*Csc[a + b*x], x, 3, -((2*x*ArcTanh[E^(I*a + I*b*x)])/b) + (I*PolyLog[2, -E^(I*(a + b*x))])/b^2 - (I*PolyLog[2, E^(I*(a + b*x))])/b^2}
{x^0*Csc[a + b*x], x, 1, -(ArcTanh[Cos[a + b*x]]/b)}
{1/x^1*Csc[a + b*x], x, 0, Int[Csc[a + b*x]/x, x]}
{1/x^2*Csc[a + b*x], x, 0, Int[Csc[a + b*x]/x^2, x]}


{x^3*Csc[a + b*x]^2, x, 6, -((I*x^3)/b) - (x^3*Cot[a + b*x])/b + (3*x^2*Log[1 - E^(2*I*a + 2*I*b*x)])/b^2 - (3*I*x*PolyLog[2, E^(2*I*a + 2*I*b*x)])/b^3 + (3*PolyLog[3, E^(2*I*a + 2*I*b*x)])/(2*b^4)}
{x^2*Csc[a + b*x]^2, x, 5, -((I*x^2)/b) - (x^2*Cot[a + b*x])/b + (2*x*Log[1 - E^(2*I*a + 2*I*b*x)])/b^2 - (I*PolyLog[2, E^(2*I*a + 2*I*b*x)])/b^3}
{x^1*Csc[a + b*x]^2, x, 2, -((x*Cot[a + b*x])/b) + Log[Sin[a + b*x]]/b^2}
{x^0*Csc[a + b*x]^2, x, 1, -(Cot[a + b*x]/b)}
{1/x^1*Csc[a + b*x]^2, x, 0, Int[Csc[a + b*x]^2/x, x]}
{1/x^2*Csc[a + b*x]^2, x, 0, Int[Csc[a + b*x]^2/x^2, x]}


{x^3*Csc[a + b*x]^3, x, 11, -((6*x*ArcTanh[E^(I*a + I*b*x)])/b^3) - (x^3*ArcTanh[E^(I*a + I*b*x)])/b - (3*x^2*Csc[a + b*x])/(2*b^2) - (x^3*Cot[a + b*x]*Csc[a + b*x])/(2*b) + (3*I*PolyLog[2, -E^(I*(a + b*x))])/b^4 + (3*I*x^2*PolyLog[2, -E^(I*(a + b*x))])/(2*b^2) - (3*I*PolyLog[2, E^(I*(a + b*x))])/b^4 - (3*I*x^2*PolyLog[2, E^(I*(a + b*x))])/(2*b^2) - (3*x*PolyLog[3, -E^(I*(a + b*x))])/b^3 + (3*x*PolyLog[3, E^(I*(a + b*x))])/b^3 - (3*I*PolyLog[4, -E^(I*(a + b*x))])/b^4 + (3*I*PolyLog[4, E^(I*(a + b*x))])/b^4}
{x^2*Csc[a + b*x]^3, x, 7, -((x^2*ArcTanh[E^(I*a + I*b*x)])/b) - ArcTanh[Cos[a + b*x]]/b^3 - (x*Csc[a + b*x])/b^2 - (x^2*Cot[a + b*x]*Csc[a + b*x])/(2*b) + (I*x*PolyLog[2, -E^(I*(a + b*x))])/b^2 - (I*x*PolyLog[2, E^(I*(a + b*x))])/b^2 - PolyLog[3, -E^(I*(a + b*x))]/b^3 + PolyLog[3, E^(I*(a + b*x))]/b^3}
{x^1*Csc[a + b*x]^3, x, 4, -((x*ArcTanh[E^(I*a + I*b*x)])/b) - Csc[a + b*x]/(2*b^2) - (x*Cot[a + b*x]*Csc[a + b*x])/(2*b) + (I*PolyLog[2, -E^(I*(a + b*x))])/(2*b^2) - (I*PolyLog[2, E^(I*(a + b*x))])/(2*b^2)}
{x^0*Csc[a + b*x]^3, x, 2, -(ArcTanh[Cos[a + b*x]]/(2*b)) - (Cot[a + b*x]*Csc[a + b*x])/(2*b)}
{1/x^1*Csc[a + b*x]^3, x, 0, Int[Csc[a + b*x]^3/x, x]}
{1/x^2*Csc[a + b*x]^3, x, 0, Int[Csc[a + b*x]^3/x^2, x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Csc[a+b x]^(p/2)*)


{x/Csc[x]^(3/2) - x*Sqrt[Csc[x]]/3, x, 4, 4/(9*Csc[x]^(3/2)) - (2*x*Cos[x])/(3*Sqrt[Csc[x]])}
{x/Csc[x]^(5/2) - 3*x/(5*Sqrt[Csc[x]]), x, 4, 4/(25*Csc[x]^(5/2)) - (2*x*Cos[x])/(5*Csc[x]^(3/2))}
{x/Csc[x]^(7/2) - (5/21)*x*Sqrt[Csc[x]], x, 5, 4/(49*Csc[x]^(7/2)) - (2*x*Cos[x])/(7*Csc[x]^(5/2)) + 20/(63*Csc[x]^(3/2)) - (10*x*Cos[x])/(21*Sqrt[Csc[x]])}
{x^2/Csc[x]^(3/2) - (1/3)*x^2*Sqrt[Csc[x]], x, 7, (8*x)/(9*Csc[x]^(3/2)) + (16*Cos[x])/(27*Sqrt[Csc[x]]) - (2*x^2*Cos[x])/(3*Sqrt[Csc[x]]) + (16/27)*Sqrt[Csc[x]]*EllipticF[Pi/4 - x/2, 2]*Sqrt[Sin[x]]}


(* ::Subsection:: *)
(*Integrands of the form x^(m/2) Csc[a+b x]^p*)


(* ::Subsection:: *)
(*Integrands of the form x^(m/2) Csc[a+b x]^(p/2)*)


(* ::Section::Closed:: *)
(*Integrands of the form (c+d x)^m Csc[a+b x]^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (c+d x)^m Csc[a+b x]^p*)


{(c + d*x)*Csc[a + b*x], x, 3, -((2*(c + d*x)*ArcTanh[E^(I*a + I*b*x)])/b) + (I*d*PolyLog[2, -E^(I*(a + b*x))])/b^2 - (I*d*PolyLog[2, E^(I*(a + b*x))])/b^2}
{(c + d*x)^2*Csc[a + b*x], x, 5, -((2*(c + d*x)^2*ArcTanh[E^(I*a + I*b*x)])/b) + (2*I*d*(c + d*x)*PolyLog[2, -E^(I*(a + b*x))])/b^2 - (2*I*d*(c + d*x)*PolyLog[2, E^(I*(a + b*x))])/b^2 - (2*d^2*PolyLog[3, -E^(I*(a + b*x))])/b^3 + (2*d^2*PolyLog[3, E^(I*(a + b*x))])/b^3}
{(c + d*x)^3*Csc[a + b*x], x, 7, -((2*(c + d*x)^3*ArcTanh[E^(I*a + I*b*x)])/b) + (3*I*d*(c + d*x)^2*PolyLog[2, -E^(I*(a + b*x))])/b^2 - (3*I*d*(c + d*x)^2*PolyLog[2, E^(I*(a + b*x))])/b^2 - (6*d^2*(c + d*x)*PolyLog[3, -E^(I*(a + b*x))])/b^3 + (6*d^2*(c + d*x)*PolyLog[3, E^(I*(a + b*x))])/b^3 - (6*I*d^3*PolyLog[4, -E^(I*(a + b*x))])/b^4 + (6*I*d^3*PolyLog[4, E^(I*(a + b*x))])/b^4}


{(c + d*x)*Csc[a + b*x]^2, x, 2, -(((c + d*x)*Cot[a + b*x])/b) + (d*Log[Sin[a + b*x]])/b^2}
{(c + d*x)^2*Csc[a + b*x]^2, x, 5, -((I*(c + d*x)^2)/b) - ((c + d*x)^2*Cot[a + b*x])/b + (2*d*(c + d*x)*Log[1 - E^(2*I*a + 2*I*b*x)])/b^2 - (I*d^2*PolyLog[2, E^(2*I*a + 2*I*b*x)])/b^3}
{(c + d*x)^3*Csc[a + b*x]^2, x, 6, -((I*(c + d*x)^3)/b) - ((c + d*x)^3*Cot[a + b*x])/b + (3*d*(c + d*x)^2*Log[1 - E^(2*I*a + 2*I*b*x)])/b^2 - (3*I*d^2*(c + d*x)*PolyLog[2, E^(2*I*a + 2*I*b*x)])/b^3 + (3*d^3*PolyLog[3, E^(2*I*a + 2*I*b*x)])/(2*b^4)}


{(c + d*x)*Csc[a + b*x]^3, x, 4, -(((c + d*x)*ArcTanh[E^(I*a + I*b*x)])/b) - (d*Csc[a + b*x])/(2*b^2) - ((c + d*x)*Cot[a + b*x]*Csc[a + b*x])/(2*b) + (I*d*PolyLog[2, -E^(I*(a + b*x))])/(2*b^2) - (I*d*PolyLog[2, E^(I*(a + b*x))])/(2*b^2)}
{(c + d*x)^2*Csc[a + b*x]^3, x, 7, -(((c + d*x)^2*ArcTanh[E^(I*a + I*b*x)])/b) - (d^2*ArcTanh[Cos[a + b*x]])/b^3 - (d*(c + d*x)*Csc[a + b*x])/b^2 - ((c + d*x)^2*Cot[a + b*x]*Csc[a + b*x])/(2*b) + (I*d*(c + d*x)*PolyLog[2, -E^(I*(a + b*x))])/b^2 - (I*d*(c + d*x)*PolyLog[2, E^(I*(a + b*x))])/b^2 - (d^2*PolyLog[3, -E^(I*(a + b*x))])/b^3 + (d^2*PolyLog[3, E^(I*(a + b*x))])/b^3}
{(c + d*x)^3*Csc[a + b*x]^3, x, 11, -((6*d^2*(c + d*x)*ArcTanh[E^(I*a + I*b*x)])/b^3) - ((c + d*x)^3*ArcTanh[E^(I*a + I*b*x)])/b - (3*d*(c + d*x)^2*Csc[a + b*x])/(2*b^2) - ((c + d*x)^3*Cot[a + b*x]*Csc[a + b*x])/(2*b) + (3*I*d^3*PolyLog[2, -E^(I*(a + b*x))])/b^4 + (3*I*d*(c + d*x)^2*PolyLog[2, -E^(I*(a + b*x))])/(2*b^2) - (3*I*d^3*PolyLog[2, E^(I*(a + b*x))])/b^4 - (3*I*d*(c + d*x)^2*PolyLog[2, E^(I*(a + b*x))])/(2*b^2) - (3*d^2*(c + d*x)*PolyLog[3, -E^(I*(a + b*x))])/b^3 + (3*d^2*(c + d*x)*PolyLog[3, E^(I*(a + b*x))])/b^3 - (3*I*d^3*PolyLog[4, -E^(I*(a + b*x))])/b^4 + (3*I*d^3*PolyLog[4, E^(I*(a + b*x))])/b^4}


(* ::Subsection:: *)
(*Integrands of the form (c+d x)^m Csc[a+b x]^(p/2)*)


(* ::Section::Closed:: *)
(*Integrands of the form x^m Csc[a+b x^2]^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Csc[a+b x^2]^p*)


{x*Csc[a + b*x^2]^7, x, 5, -((5*ArcTanh[Cos[a + b*x^2]])/(32*b)) - (5*Cot[a + b*x^2]*Csc[a + b*x^2])/(32*b) - (5*Cot[a + b*x^2]*Csc[a + b*x^2]^3)/(48*b) - (Cot[a + b*x^2]*Csc[a + b*x^2]^5)/(12*b)}


(* ::Subsection:: *)
(*Integrands of the form x^m Csc[a+b x^2]^(p/2)*)


(* ::Subsection:: *)
(*Integrands of the form x^(m/2) Csc[a+b x^2]^p*)


(* ::Subsection:: *)
(*Integrands of the form x^(m/2) Csc[a+b x^2]^(p/2)*)


(* ::Section::Closed:: *)
(*Integrands of the form x^m Csc[a+b x^n]^p*)


{Csc[Sqrt[x]]^3/Sqrt[x], x, 3, -ArcTanh[Cos[Sqrt[x]]] - Cot[Sqrt[x]]*Csc[Sqrt[x]]}


(* ::Title:: *)
(*Integration problems of the form x^m (c Sin[a+b x^n]^p)^q*)


(* ::Section::Closed:: *)
(*Integrands of the form x^m (c Sin[a+b x^n]^p)^(q/3)*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (c Sin[a+b x^n]^3)^(1/3)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{x^m*(c*Sin[a + b*x]^3)^(1/3), x, 4, -(E^(I*a)*x^m*Csc[a + b*x]*Gamma[1 + m, (-I)*b*x]*(c*Sin[a + b*x]^3)^(1/3))/(2*b*((-I)*b*x)^m) - (x^m*Csc[a + b*x]*Gamma[1 + m, I*b*x]*(c*Sin[a + b*x]^3)^(1/3))/(2*b*E^(I*a)*(I*b*x)^m)}
{x^3*(c*Sin[a + b*x]^3)^(1/3), x, 5, (-6*(c*Sin[a + b*x]^3)^(1/3))/b^4 + (3*x^2*(c*Sin[a + b*x]^3)^(1/3))/b^2 + (6*x*Cot[a + b*x]*(c*Sin[a + b*x]^3)^(1/3))/b^3 - (x^3*Cot[a + b*x]*(c*Sin[a + b*x]^3)^(1/3))/b}
{x^2*(c*Sin[a + b*x]^3)^(1/3), x, 4, (2*x*(c*Sin[a + b*x]^3)^(1/3))/b^2 + (2*Cot[a + b*x]*(c*Sin[a + b*x]^3)^(1/3))/b^3 - (x^2*Cot[a + b*x]*(c*Sin[a + b*x]^3)^(1/3))/b}
{x*(c*Sin[a + b*x]^3)^(1/3), x, 3, (c*Sin[a + b*x]^3)^(1/3)/b^2 - (x*Cot[a + b*x]*(c*Sin[a + b*x]^3)^(1/3))/b}
{(c*Sin[a + b*x]^3)^(1/3), x, 2, -((Cot[a + b*x]*(c*Sin[a + b*x]^3)^(1/3))/b)}
{(c*Sin[a + b*x]^3)^(1/3)/x, x, 4, CosIntegral[b*x]*Csc[a + b*x]*Sin[a]*(c*Sin[a + b*x]^3)^(1/3) + Cos[a]*Csc[a + b*x]*(c*Sin[a + b*x]^3)^(1/3)*SinIntegral[b*x]}
{(c*Sin[a + b*x]^3)^(1/3)/x^2, x, 5, -((c*Sin[a + b*x]^3)^(1/3)/x) + b*Cos[a]*CosIntegral[b*x]*Csc[a + b*x]*(c*Sin[a + b*x]^3)^(1/3) - b*Csc[a + b*x]*Sin[a]*(c*Sin[a + b*x]^3)^(1/3)*SinIntegral[b*x]}
{(c*Sin[a + b*x]^3)^(1/3)/x^3, x, 6, -(c*Sin[a + b*x]^3)^(1/3)/(2*x^2) - (b*Cot[a + b*x]*(c*Sin[a + b*x]^3)^(1/3))/(2*x) - (b^2*CosIntegral[b*x]*Csc[a + b*x]*Sin[a]*(c*Sin[a + b*x]^3)^(1/3))/2 - (b^2*Cos[a]*Csc[a + b*x]*(c*Sin[a + b*x]^3)^(1/3)*SinIntegral[b*x])/2}


{x^m*(c*Sin[a + b*x^2]^3)^(1/3), x, 4, (I/4)*E^(I*a)*x^(1 + m)*((-I)*b*x^2)^((-1 - m)/2)*Csc[a + b*x^2]*Gamma[(1 + m)/2, (-I)*b*x^2]*(c*Sin[a + b*x^2]^3)^(1/3) - ((I/4)*x^(1 + m)*(I*b*x^2)^((-1 - m)/2)*Csc[a + b*x^2]*Gamma[(1 + m)/2, I*b*x^2]*(c*Sin[a + b*x^2]^3)^(1/3))/E^(I*a)}
{x^3*(c*Sin[a + b*x^2]^3)^(1/3), x, 3, (c*Sin[a + b*x^2]^3)^(1/3)/(2*b^2) - (x^2*Cot[a + b*x^2]*(c*Sin[a + b*x^2]^3)^(1/3))/(2*b)}
{x^2*(c*Sin[a + b*x^2]^3)^(1/3), x, 5, -(x*Cot[a + b*x^2]*(c*Sin[a + b*x^2]^3)^(1/3))/(2*b) + (Sqrt[Pi/2]*Cos[a]*Csc[a + b*x^2]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*x]*(c*Sin[a + b*x^2]^3)^(1/3))/(2*b^(3/2)) - (Sqrt[Pi/2]*Csc[a + b*x^2]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*x]*Sin[a]*(c*Sin[a + b*x^2]^3)^(1/3))/(2*b^(3/2))}
{x*(c*Sin[a + b*x^2]^3)^(1/3), x, 2, -(Cot[a + b*x^2]*(c*Sin[a + b*x^2]^3)^(1/3))/(2*b)}
{(c*Sin[a + b*x^2]^3)^(1/3), x, 4, (Sqrt[Pi/2]*Cos[a]*Csc[a + b*x^2]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*x]*(c*Sin[a + b*x^2]^3)^(1/3))/Sqrt[b] + (Sqrt[Pi/2]*Csc[a + b*x^2]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*x]*Sin[a]*(c*Sin[a + b*x^2]^3)^(1/3))/Sqrt[b]}
{(c*Sin[a + b*x^2]^3)^(1/3)/x, x, 4, (CosIntegral[b*x^2]*Csc[a + b*x^2]*Sin[a]*(c*Sin[a + b*x^2]^3)^(1/3))/2 + (Cos[a]*Csc[a + b*x^2]*(c*Sin[a + b*x^2]^3)^(1/3)*SinIntegral[b*x^2])/2}
{(c*Sin[a + b*x^2]^3)^(1/3)/x^2, x, 5, -((c*Sin[a + b*x^2]^3)^(1/3)/x) + Sqrt[b]*Sqrt[2*Pi]*Cos[a]*Csc[a + b*x^2]*FresnelC[Sqrt[b]*Sqrt[2/Pi]*x]*(c*Sin[a + b*x^2]^3)^(1/3) - Sqrt[b]*Sqrt[2*Pi]*Csc[a + b*x^2]*FresnelS[Sqrt[b]*Sqrt[2/Pi]*x]*Sin[a]*(c*Sin[a + b*x^2]^3)^(1/3)}
{(c*Sin[a + b*x^2]^3)^(1/3)/x^3, x, 5, -(c*Sin[a + b*x^2]^3)^(1/3)/(2*x^2) + (b*Cos[a]*CosIntegral[b*x^2]*Csc[a + b*x^2]*(c*Sin[a + b*x^2]^3)^(1/3))/2 - (b*Csc[a + b*x^2]*Sin[a]*(c*Sin[a + b*x^2]^3)^(1/3)*SinIntegral[b*x^2])/2}


(* ::Subsubsection:: *)
(*n<0*)


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{x^m*(c*Sin[a + b*x^n]^3)^(1/3), x, 4, ((I/2)*E^(I*a)*x^(1 + m)*Csc[a + b*x^n]*Gamma[(1 + m)/n, (-I)*b*x^n]*(c*Sin[a + b*x^n]^3)^(1/3))/(n*((-I)*b*x^n)^((1 + m)/n)) - ((I/2)*x^(1 + m)*Csc[a + b*x^n]*Gamma[(1 + m)/n, I*b*x^n]*(c*Sin[a + b*x^n]^3)^(1/3))/(E^(I*a)*n*(I*b*x^n)^((1 + m)/n))}
{x^3*(c*Sin[a + b*x^n]^3)^(1/3), x, 4, ((I/2)*E^(I*a)*x^4*Csc[a + b*x^n]*Gamma[4/n, (-I)*b*x^n]*(c*Sin[a + b*x^n]^3)^(1/3))/(n*((-I)*b*x^n)^(4/n)) - ((I/2)*x^4*Csc[a + b*x^n]*Gamma[4/n, I*b*x^n]*(c*Sin[a + b*x^n]^3)^(1/3))/(E^(I*a)*n*(I*b*x^n)^(4/n))}
{x^2*(c*Sin[a + b*x^n]^3)^(1/3), x, 4, ((I/2)*E^(I*a)*x^3*Csc[a + b*x^n]*Gamma[3/n, (-I)*b*x^n]*(c*Sin[a + b*x^n]^3)^(1/3))/(n*((-I)*b*x^n)^(3/n)) - ((I/2)*x^3*Csc[a + b*x^n]*Gamma[3/n, I*b*x^n]*(c*Sin[a + b*x^n]^3)^(1/3))/(E^(I*a)*n*(I*b*x^n)^(3/n))}
{x*(c*Sin[a + b*x^n]^3)^(1/3), x, 4, ((I/2)*E^(I*a)*x^2*Csc[a + b*x^n]*Gamma[2/n, (-I)*b*x^n]*(c*Sin[a + b*x^n]^3)^(1/3))/(n*((-I)*b*x^n)^(2/n)) - ((I/2)*x^2*Csc[a + b*x^n]*Gamma[2/n, I*b*x^n]*(c*Sin[a + b*x^n]^3)^(1/3))/(E^(I*a)*n*(I*b*x^n)^(2/n))}
{(c*Sin[a + b*x^n]^3)^(1/3), x, 4, ((I/2)*E^(I*a)*x*Csc[a + b*x^n]*Gamma[n^(-1), (-I)*b*x^n]*(c*Sin[a + b*x^n]^3)^(1/3))/(n*((-I)*b*x^n)^n^(-1)) - ((I/2)*x*Csc[a + b*x^n]*Gamma[n^(-1), I*b*x^n]*(c*Sin[a + b*x^n]^3)^(1/3))/(E^(I*a)*n*(I*b*x^n)^n^(-1))}
{(c*Sin[a + b*x^n]^3)^(1/3)/x, x, 4, (CosIntegral[b*x^n]*Csc[a + b*x^n]*Sin[a]*(c*Sin[a + b*x^n]^3)^(1/3))/n + (Cos[a]*Csc[a + b*x^n]*(c*Sin[a + b*x^n]^3)^(1/3)*SinIntegral[b*x^n])/n}
{(c*Sin[a + b*x^n]^3)^(1/3)/x^2, x, 4, ((I/2)*E^(I*a)*((-I)*b*x^n)^n^(-1)*Csc[a + b*x^n]*Gamma[-n^(-1), (-I)*b*x^n]*(c*Sin[a + b*x^n]^3)^(1/3))/(n*x) - ((I/2)*(I*b*x^n)^n^(-1)*Csc[a + b*x^n]*Gamma[-n^(-1), I*b*x^n]*(c*Sin[a + b*x^n]^3)^(1/3))/(E^(I*a)*n*x)}
{(c*Sin[a + b*x^n]^3)^(1/3)/x^3, x, 4, ((I/2)*E^(I*a)*((-I)*b*x^n)^(2/n)*Csc[a + b*x^n]*Gamma[-2/n, (-I)*b*x^n]*(c*Sin[a + b*x^n]^3)^(1/3))/(n*x^2) - ((I/2)*(I*b*x^n)^(2/n)*Csc[a + b*x^n]*Gamma[-2/n, I*b*x^n]*(c*Sin[a + b*x^n]^3)^(1/3))/(E^(I*a)*n*x^2)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (c Sin[a+b x^n]^3)^(2/3)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{x^m*(c*Sin[a + b*x]^3)^(2/3), x, 6, (x^(1 + m)*Csc[a + b*x]^2*(c*Sin[a + b*x]^3)^(2/3))/(2*(1 + m)) + (I*2^(-3 - m)*E^((2*I)*a)*x^m*Csc[a + b*x]^2*Gamma[1 + m, (-2*I)*b*x]*(c*Sin[a + b*x]^3)^(2/3))/(b*((-I)*b*x)^m) - (I*2^(-3 - m)*x^m*Csc[a + b*x]^2*Gamma[1 + m, (2*I)*b*x]*(c*Sin[a + b*x]^3)^(2/3))/(b*E^((2*I)*a)*(I*b*x)^m)}
{x^3*(c*Sin[a + b*x]^3)^(2/3), x, 5, (-3*(c*Sin[a + b*x]^3)^(2/3))/(8*b^4) + (3*x^2*(c*Sin[a + b*x]^3)^(2/3))/(4*b^2) + (3*x*Cot[a + b*x]*(c*Sin[a + b*x]^3)^(2/3))/(4*b^3) - (x^3*Cot[a + b*x]*(c*Sin[a + b*x]^3)^(2/3))/(2*b) - (3*x^2*Csc[a + b*x]^2*(c*Sin[a + b*x]^3)^(2/3))/(8*b^2) + (x^4*Csc[a + b*x]^2*(c*Sin[a + b*x]^3)^(2/3))/8}
{x^2*(c*Sin[a + b*x]^3)^(2/3), x, 4, (x*(c*Sin[a + b*x]^3)^(2/3))/(2*b^2) + (Cot[a + b*x]*(c*Sin[a + b*x]^3)^(2/3))/(4*b^3) - (x^2*Cot[a + b*x]*(c*Sin[a + b*x]^3)^(2/3))/(2*b) - (x*Csc[a + b*x]^2*(c*Sin[a + b*x]^3)^(2/3))/(4*b^2) + (x^3*Csc[a + b*x]^2*(c*Sin[a + b*x]^3)^(2/3))/6}
{x*(c*Sin[a + b*x]^3)^(2/3), x, 3, (c*Sin[a + b*x]^3)^(2/3)/(4*b^2) - (x*Cot[a + b*x]*(c*Sin[a + b*x]^3)^(2/3))/(2*b) + (x^2*Csc[a + b*x]^2*(c*Sin[a + b*x]^3)^(2/3))/4}
{(c*Sin[a + b*x]^3)^(2/3), x, 2, -(Cot[a + b*x]*(c*Sin[a + b*x]^3)^(2/3))/(2*b) + (x*Csc[a + b*x]^2*(c*Sin[a + b*x]^3)^(2/3))/2}
{(c*Sin[a + b*x]^3)^(2/3)/x, x, 6, -(Cos[2*a]*CosIntegral[2*b*x]*Csc[a + b*x]^2*(c*Sin[a + b*x]^3)^(2/3))/2 + (Csc[a + b*x]^2*Log[x]*(c*Sin[a + b*x]^3)^(2/3))/2 + (Csc[a + b*x]^2*Sin[2*a]*(c*Sin[a + b*x]^3)^(2/3)*SinIntegral[2*b*x])/2}
{(c*Sin[a + b*x]^3)^(2/3)/x^2, x, 6, -((c*Sin[a + b*x]^3)^(2/3)/x) + b*CosIntegral[2*b*x]*Csc[a + b*x]^2*Sin[2*a]*(c*Sin[a + b*x]^3)^(2/3) + b*Cos[2*a]*Csc[a + b*x]^2*(c*Sin[a + b*x]^3)^(2/3)*SinIntegral[2*b*x]}
{(c*Sin[a + b*x]^3)^(2/3)/x^3, x, 8, -(c*Sin[a + b*x]^3)^(2/3)/(2*x^2) - (b*Cot[a + b*x]*(c*Sin[a + b*x]^3)^(2/3))/x + b^2*Cos[2*a]*CosIntegral[2*b*x]*Csc[a + b*x]^2*(c*Sin[a + b*x]^3)^(2/3) - b^2*Csc[a + b*x]^2*Sin[2*a]*(c*Sin[a + b*x]^3)^(2/3)*SinIntegral[2*b*x]}


{x^m*(c*Sin[a + b*x^2]^3)^(2/3), x, 6, (x^(1 + m)*Csc[a + b*x^2]^2*(c*Sin[a + b*x^2]^3)^(2/3))/(2*(1 + m)) + 2^(-7/2 - m/2)*E^((2*I)*a)*x^(1 + m)*((-I)*b*x^2)^((-1 - m)/2)*Csc[a + b*x^2]^2*Gamma[(1 + m)/2, (-2*I)*b*x^2]*(c*Sin[a + b*x^2]^3)^(2/3) + (2^(-7/2 - m/2)*x^(1 + m)*(I*b*x^2)^((-1 - m)/2)*Csc[a + b*x^2]^2*Gamma[(1 + m)/2, (2*I)*b*x^2]*(c*Sin[a + b*x^2]^3)^(2/3))/E^((2*I)*a)}
{x^3*(c*Sin[a + b*x^2]^3)^(2/3), x, 3, (c*Sin[a + b*x^2]^3)^(2/3)/(8*b^2) - (x^2*Cot[a + b*x^2]*(c*Sin[a + b*x^2]^3)^(2/3))/(4*b) + (x^4*Csc[a + b*x^2]^2*(c*Sin[a + b*x^2]^3)^(2/3))/8}
{x^2*(c*Sin[a + b*x^2]^3)^(2/3), x, 7, (x^3*Csc[a + b*x^2]^2*(c*Sin[a + b*x^2]^3)^(2/3))/6 + (Sqrt[Pi]*Cos[2*a]*Csc[a + b*x^2]^2*FresnelS[(2*Sqrt[b]*x)/Sqrt[Pi]]*(c*Sin[a + b*x^2]^3)^(2/3))/(16*b^(3/2)) + (Sqrt[Pi]*Csc[a + b*x^2]^2*FresnelC[(2*Sqrt[b]*x)/Sqrt[Pi]]*Sin[2*a]*(c*Sin[a + b*x^2]^3)^(2/3))/(16*b^(3/2)) - (x*Csc[a + b*x^2]^2*(c*Sin[a + b*x^2]^3)^(2/3)*Sin[2*a + 2*b*x^2])/(8*b)}
{x*(c*Sin[a + b*x^2]^3)^(2/3), x, 3, -(Cot[a + b*x^2]*(c*Sin[a + b*x^2]^3)^(2/3))/(4*b) + (x^2*Csc[a + b*x^2]^2*(c*Sin[a + b*x^2]^3)^(2/3))/4}
{(c*Sin[a + b*x^2]^3)^(2/3), x, 6, (x*Csc[a + b*x^2]^2*(c*Sin[a + b*x^2]^3)^(2/3))/2 - (Sqrt[Pi]*Cos[2*a]*Csc[a + b*x^2]^2*FresnelC[(2*Sqrt[b]*x)/Sqrt[Pi]]*(c*Sin[a + b*x^2]^3)^(2/3))/(4*Sqrt[b]) + (Sqrt[Pi]*Csc[a + b*x^2]^2*FresnelS[(2*Sqrt[b]*x)/Sqrt[Pi]]*Sin[2*a]*(c*Sin[a + b*x^2]^3)^(2/3))/(4*Sqrt[b])}
{(c*Sin[a + b*x^2]^3)^(2/3)/x, x, 6, -(Cos[2*a]*CosIntegral[2*b*x^2]*Csc[a + b*x^2]^2*(c*Sin[a + b*x^2]^3)^(2/3))/4 + (Csc[a + b*x^2]^2*Log[x]*(c*Sin[a + b*x^2]^3)^(2/3))/2 + (Csc[a + b*x^2]^2*Sin[2*a]*(c*Sin[a + b*x^2]^3)^(2/3)*SinIntegral[2*b*x^2])/4}
{(c*Sin[a + b*x^2]^3)^(2/3)/x^2, x, 6, -((c*Sin[a + b*x^2]^3)^(2/3)/x) + Sqrt[b]*Sqrt[Pi]*Cos[2*a]*Csc[a + b*x^2]^2*FresnelS[(2*Sqrt[b]*x)/Sqrt[Pi]]*(c*Sin[a + b*x^2]^3)^(2/3) + Sqrt[b]*Sqrt[Pi]*Csc[a + b*x^2]^2*FresnelC[(2*Sqrt[b]*x)/Sqrt[Pi]]*Sin[2*a]*(c*Sin[a + b*x^2]^3)^(2/3)}
{(c*Sin[a + b*x^2]^3)^(2/3)/x^3, x, 7, -(Csc[a + b*x^2]^2*(c*Sin[a + b*x^2]^3)^(2/3))/(4*x^2) + (Cos[2*a + 2*b*x^2]*Csc[a + b*x^2]^2*(c*Sin[a + b*x^2]^3)^(2/3))/(4*x^2) + (b*CosIntegral[2*b*x^2]*Csc[a + b*x^2]^2*Sin[2*a]*(c*Sin[a + b*x^2]^3)^(2/3))/2 + (b*Cos[2*a]*Csc[a + b*x^2]^2*(c*Sin[a + b*x^2]^3)^(2/3)*SinIntegral[2*b*x^2])/2}


(* ::Subsubsection:: *)
(*n<0*)


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{x^m*(c*Sin[a + b*x^n]^3)^(2/3), x, 6, (x^(1 + m)*Csc[a + b*x^n]^2*(c*Sin[a + b*x^n]^3)^(2/3))/(2*(1 + m)) + (E^((2*I)*a)*x^(1 + m)*Csc[a + b*x^n]^2*Gamma[(1 + m)/n, (-2*I)*b*x^n]*(c*Sin[a + b*x^n]^3)^(2/3))/(2^((1 + m + 2*n)/n)*n*((-I)*b*x^n)^((1 + m)/n)) + (x^(1 + m)*Csc[a + b*x^n]^2*Gamma[(1 + m)/n, (2*I)*b*x^n]*(c*Sin[a + b*x^n]^3)^(2/3))/(2^((1 + m + 2*n)/n)*E^((2*I)*a)*n*(I*b*x^n)^((1 + m)/n))}
{x^3*(c*Sin[a + b*x^n]^3)^(2/3), x, 6, (x^4*Csc[a + b*x^n]^2*(c*Sin[a + b*x^n]^3)^(2/3))/8 + (4^(-1 - 2/n)*E^((2*I)*a)*x^4*Csc[a + b*x^n]^2*Gamma[4/n, (-2*I)*b*x^n]*(c*Sin[a + b*x^n]^3)^(2/3))/(n*((-I)*b*x^n)^(4/n)) + (4^(-1 - 2/n)*x^4*Csc[a + b*x^n]^2*Gamma[4/n, (2*I)*b*x^n]*(c*Sin[a + b*x^n]^3)^(2/3))/(E^((2*I)*a)*n*(I*b*x^n)^(4/n))}
{x^2*(c*Sin[a + b*x^n]^3)^(2/3), x, 6, (x^3*Csc[a + b*x^n]^2*(c*Sin[a + b*x^n]^3)^(2/3))/6 + (2^(-2 - 3/n)*E^((2*I)*a)*x^3*Csc[a + b*x^n]^2*Gamma[3/n, (-2*I)*b*x^n]*(c*Sin[a + b*x^n]^3)^(2/3))/(n*((-I)*b*x^n)^(3/n)) + (2^(-2 - 3/n)*x^3*Csc[a + b*x^n]^2*Gamma[3/n, (2*I)*b*x^n]*(c*Sin[a + b*x^n]^3)^(2/3))/(E^((2*I)*a)*n*(I*b*x^n)^(3/n))}
{x*(c*Sin[a + b*x^n]^3)^(2/3), x, 6, (x^2*Csc[a + b*x^n]^2*(c*Sin[a + b*x^n]^3)^(2/3))/4 + (4^(-1 - n^(-1))*E^((2*I)*a)*x^2*Csc[a + b*x^n]^2*Gamma[2/n, (-2*I)*b*x^n]*(c*Sin[a + b*x^n]^3)^(2/3))/(n*((-I)*b*x^n)^(2/n)) + (4^(-1 - n^(-1))*x^2*Csc[a + b*x^n]^2*Gamma[2/n, (2*I)*b*x^n]*(c*Sin[a + b*x^n]^3)^(2/3))/(E^((2*I)*a)*n*(I*b*x^n)^(2/n))}
{(c*Sin[a + b*x^n]^3)^(2/3), x, 6, (x*Csc[a + b*x^n]^2*(c*Sin[a + b*x^n]^3)^(2/3))/2 + (2^(-2 - n^(-1))*E^((2*I)*a)*x*Csc[a + b*x^n]^2*Gamma[n^(-1), (-2*I)*b*x^n]*(c*Sin[a + b*x^n]^3)^(2/3))/(n*((-I)*b*x^n)^n^(-1)) + (2^(-2 - n^(-1))*x*Csc[a + b*x^n]^2*Gamma[n^(-1), (2*I)*b*x^n]*(c*Sin[a + b*x^n]^3)^(2/3))/(E^((2*I)*a)*n*(I*b*x^n)^n^(-1))}
{(c*Sin[a + b*x^n]^3)^(2/3)/x, x, 6, -(Cos[2*a]*CosIntegral[2*b*x^n]*Csc[a + b*x^n]^2*(c*Sin[a + b*x^n]^3)^(2/3))/(2*n) + (Csc[a + b*x^n]^2*Log[x]*(c*Sin[a + b*x^n]^3)^(2/3))/2 + (Csc[a + b*x^n]^2*Sin[2*a]*(c*Sin[a + b*x^n]^3)^(2/3)*SinIntegral[2*b*x^n])/(2*n)}
{(c*Sin[a + b*x^n]^3)^(2/3)/x^2, x, 6, -(Csc[a + b*x^n]^2*(c*Sin[a + b*x^n]^3)^(2/3))/(2*x) + (2^(-2 + n^(-1))*E^((2*I)*a)*((-I)*b*x^n)^n^(-1)*Csc[a + b*x^n]^2*Gamma[-n^(-1), (-2*I)*b*x^n]*(c*Sin[a + b*x^n]^3)^(2/3))/(n*x) + (2^(-2 + n^(-1))*(I*b*x^n)^n^(-1)*Csc[a + b*x^n]^2*Gamma[-n^(-1), (2*I)*b*x^n]*(c*Sin[a + b*x^n]^3)^(2/3))/(E^((2*I)*a)*n*x)}
{(c*Sin[a + b*x^n]^3)^(2/3)/x^3, x, 6, -(Csc[a + b*x^n]^2*(c*Sin[a + b*x^n]^3)^(2/3))/(4*x^2) + (4^(-1 + n^(-1))*E^((2*I)*a)*((-I)*b*x^n)^(2/n)*Csc[a + b*x^n]^2*Gamma[-2/n, (-2*I)*b*x^n]*(c*Sin[a + b*x^n]^3)^(2/3))/(n*x^2) + (4^(-1 + n^(-1))*(I*b*x^n)^(2/n)*Csc[a + b*x^n]^2*Gamma[-2/n, (2*I)*b*x^n]*(c*Sin[a + b*x^n]^3)^(2/3))/(E^((2*I)*a)*n*x^2)}
