(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Trig Integral Functions*)


(* ::Section:: *)
(*Sine integral function*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m SinIntegral[b x]^n*)


{x^m*SinIntegral[b*x], x, 5, (x^m*Gamma[1 + m, (-I)*b*x])/(((-I)*b*x)^m*(2*b*(1 + m))) + (x^m*Gamma[1 + m, I*b*x])/((I*b*x)^m*(2*b*(1 + m))) + (x^(1 + m)*SinIntegral[b*x])/(1 + m)}

{x^3*SinIntegral[b*x], x, 6, -((3*x*Cos[b*x])/(2*b^3)) + (x^3*Cos[b*x])/(4*b) + (3*Sin[b*x])/(2*b^4) - (3*x^2*Sin[b*x])/(4*b^2) + (1/4)*x^4*SinIntegral[b*x]}
{x^2*SinIntegral[b*x], x, 5, -((2*Cos[b*x])/(3*b^3)) + (x^2*Cos[b*x])/(3*b) - (2*x*Sin[b*x])/(3*b^2) + (1/3)*x^3*SinIntegral[b*x]}
{x^1*SinIntegral[b*x], x, 4, (x*Cos[b*x])/(2*b) - Sin[b*x]/(2*b^2) + (1/2)*x^2*SinIntegral[b*x]}
{x^0*SinIntegral[b*x], x, 1, Cos[b*x]/b + x*SinIntegral[b*x]}
{SinIntegral[b*x]/x^1, x, 0, Int[SinIntegral[b*x]/x, x]}
{SinIntegral[b*x]/x^2, x, 4, b*CosIntegral[b*x] - Sin[b*x]/x - SinIntegral[b*x]/x}
{SinIntegral[b*x]/x^3, x, 5, -((b*Cos[b*x])/(4*x)) - Sin[b*x]/(4*x^2) - (1/4)*b^2*SinIntegral[b*x] - SinIntegral[b*x]/(2*x^2)}


{x^m*SinIntegral[b*x]^2, x, 0, Int[x^m*SinIntegral[b*x]^2, x]}

{x^3*SinIntegral[b*x]^2, x, 18, x^2/(2*b^2) + (3*CosIntegral[2*b*x])/(2*b^4) - (3*Log[x])/(2*b^4) - (x*Cos[b*x]*Sin[b*x])/b^3 + (2*Sin[b*x]^2)/b^4 - (x^2*Sin[b*x]^2)/(4*b^2) - (3*x*Cos[b*x]*SinIntegral[b*x])/b^3 + (x^3*Cos[b*x]*SinIntegral[b*x])/(2*b) + (3*Sin[b*x]*SinIntegral[b*x])/b^4 - (3*x^2*Sin[b*x]*SinIntegral[b*x])/(2*b^2) + (1/4)*x^4*SinIntegral[b*x]^2}
{x^2*SinIntegral[b*x]^2, x, 13, (5*x)/(6*b^2) - (5*Cos[b*x]*Sin[b*x])/(6*b^3) - (x*Sin[b*x]^2)/(3*b^2) - (4*Cos[b*x]*SinIntegral[b*x])/(3*b^3) + (2*x^2*Cos[b*x]*SinIntegral[b*x])/(3*b) - (4*x*Sin[b*x]*SinIntegral[b*x])/(3*b^2) + (1/3)*x^3*SinIntegral[b*x]^2 + (2*SinIntegral[2*b*x])/(3*b^3)}
{x^1*SinIntegral[b*x]^2, x, 9, -(CosIntegral[2*b*x]/(2*b^2)) + Log[x]/(2*b^2) - Sin[b*x]^2/(2*b^2) + (x*Cos[b*x]*SinIntegral[b*x])/b - (Sin[b*x]*SinIntegral[b*x])/b^2 + (1/2)*x^2*SinIntegral[b*x]^2}
{x^0*SinIntegral[b*x]^2, x, 6, (2*Cos[b*x]*SinIntegral[b*x])/b + x*SinIntegral[b*x]^2 - SinIntegral[2*b*x]/b}
{SinIntegral[b*x]^2/x^1, x, 0, Int[SinIntegral[b*x]^2/x, x]}
{SinIntegral[b*x]^2/x^2, x, 0, Int[SinIntegral[b*x]^2/x^2, x]}
{SinIntegral[b*x]^2/x^3, x, 0, Int[SinIntegral[b*x]^2/x^3, x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m SinIntegral[a+b x]^n*)


{x^m*SinIntegral[a + b*x], x, 6, (E^(I*a)*x^m*Gamma[1 + m, (-I)*b*x])/(((-I)*b*x)^m*(2*b*(1 + m))) + (x^m*Gamma[1 + m, I*b*x])/(E^(I*a)*(I*b*x)^m*(2*b*(1 + m))) + (a*Int[(x^m*Sin[a + b*x])/(a + b*x), x])/(1 + m) + (x^(1 + m)*SinIntegral[a + b*x])/(1 + m)}

{x^3*SinIntegral[a + b*x], x, 14, (a*Cos[a + b*x])/(2*b^4) - (a^3*Cos[a + b*x])/(4*b^4) - (3*x*Cos[a + b*x])/(2*b^3) + (a^2*x*Cos[a + b*x])/(4*b^3) - (a*x^2*Cos[a + b*x])/(4*b^2) + (x^3*Cos[a + b*x])/(4*b) + (3*Sin[a + b*x])/(2*b^4) - (a^2*Sin[a + b*x])/(4*b^4) + (a*x*Sin[a + b*x])/(2*b^3) - (3*x^2*Sin[a + b*x])/(4*b^2) - (a^4*SinIntegral[a + b*x])/(4*b^4) + (1/4)*x^4*SinIntegral[a + b*x]}
{x^2*SinIntegral[a + b*x], x, 10, -((2*Cos[a + b*x])/(3*b^3)) + (a^2*Cos[a + b*x])/(3*b^3) - (a*x*Cos[a + b*x])/(3*b^2) + (x^2*Cos[a + b*x])/(3*b) + (a*Sin[a + b*x])/(3*b^3) - (2*x*Sin[a + b*x])/(3*b^2) + (a^3*SinIntegral[a + b*x])/(3*b^3) + (1/3)*x^3*SinIntegral[a + b*x]}
{x^1*SinIntegral[a + b*x], x, 7, -((a*Cos[a + b*x])/(2*b^2)) + (x*Cos[a + b*x])/(2*b) - Sin[a + b*x]/(2*b^2) - (a^2*SinIntegral[a + b*x])/(2*b^2) + (1/2)*x^2*SinIntegral[a + b*x]}
{x^0*SinIntegral[a + b*x], x, 1, Cos[a + b*x]/b + ((a + b*x)*SinIntegral[a + b*x])/b}
{SinIntegral[a + b*x]/x^1, x, 0, Int[SinIntegral[a + b*x]/x, x]}
{SinIntegral[a + b*x]/x^2, x, 7, (b*CosIntegral[b*x]*Sin[a])/a + (b*Cos[a]*SinIntegral[b*x])/a - (b*SinIntegral[a + b*x])/a - SinIntegral[a + b*x]/x}
{SinIntegral[a + b*x]/x^3, x, 11, (b^2*Cos[a]*CosIntegral[b*x])/(2*a) - (b^2*CosIntegral[b*x]*Sin[a])/(2*a^2) - (b*Sin[a + b*x])/(2*a*x) - (b^2*Cos[a]*SinIntegral[b*x])/(2*a^2) - (b^2*Sin[a]*SinIntegral[b*x])/(2*a) + (b^2*SinIntegral[a + b*x])/(2*a^2) - SinIntegral[a + b*x]/(2*x^2)}


{x^m*SinIntegral[a + b*x]^2, x, 0, Int[x^m*SinIntegral[a + b*x]^2, x]}

(* {x^3*SinIntegral[a + b*x]^2, x, 77, -((5*a*x)/(4*b^3)) + (3*x^2)/(8*b^2) - (13*Cos[2*a + 2*b*x])/(16*b^4) + (3*a^2*Cos[2*a + 2*b*x])/(8*b^4) - (a*x*Cos[2*a + 2*b*x])/(4*b^3) + (x^2*Cos[2*a + 2*b*x])/(8*b^2) + (3*(1 - a^2)*CosIntegral[2*(a + b*x)])/(2*b^4) - (3*Log[a + b*x])/(2*b^4) + (3*a^2*Log[a + b*x])/(2*b^4) + (5*a*Cos[a + b*x]*Sin[a + b*x])/(4*b^4) - (3*x*Cos[a + b*x]*Sin[a + b*x])/(4*b^3) + (3*Sin[a + b*x]^2)/(8*b^4) + (a*Sin[2*a + 2*b*x])/(8*b^4) - (x*Sin[2*a + 2*b*x])/(8*b^3) + (((2*a - a^3 - 6*b*x + a^2*b*x - a*b^2*x^2 + b^3*x^3)*Cos[a + b*x] + (6 - a^2 + 2*a*b*x - 3*b^2*x^2)*Sin[a + b*x])*SinIntegral[a + b*x])/(2*b^4) - (1/4)*(a^4/b^4 - x^4)*SinIntegral[a + b*x]^2 - (a*(2 - a^2)*SinIntegral[2*(a + b*x)])/b^4} *)
{x^2*SinIntegral[a + b*x]^2, x, 34, (2*x)/(3*b^2) - (a*Cos[2*a + 2*b*x])/(3*b^3) + (x*Cos[2*a + 2*b*x])/(6*b^2) + (a*CosIntegral[2*a + 2*b*x])/b^3 - (a*Log[a + b*x])/b^3 - (2*Cos[a + b*x]*Sin[a + b*x])/(3*b^3) - Sin[2*a + 2*b*x]/(12*b^3) - (4*Cos[a + b*x]*SinIntegral[a + b*x])/(3*b^3) + (2*a^2*Cos[a + b*x]*SinIntegral[a + b*x])/(3*b^3) - (2*a*x*Cos[a + b*x]*SinIntegral[a + b*x])/(3*b^2) + (2*x^2*Cos[a + b*x]*SinIntegral[a + b*x])/(3*b) + (2*a*Sin[a + b*x]*SinIntegral[a + b*x])/(3*b^3) - (4*x*Sin[a + b*x]*SinIntegral[a + b*x])/(3*b^2) - (a^2*x*SinIntegral[a + b*x]^2)/(3*b^2) + (1/3)*x^3*SinIntegral[a + b*x]^2 + (a^2*(a + b*x)*SinIntegral[a + b*x]^2)/(3*b^3) + (2*SinIntegral[2*a + 2*b*x])/(3*b^3) - (a^2*SinIntegral[2*a + 2*b*x])/b^3}
{x^1*SinIntegral[a + b*x]^2, x, 15, Cos[2*a + 2*b*x]/(4*b^2) - CosIntegral[2*a + 2*b*x]/(2*b^2) + Log[a + b*x]/(2*b^2) - (a*Cos[a + b*x]*SinIntegral[a + b*x])/b^2 + (x*Cos[a + b*x]*SinIntegral[a + b*x])/b - (Sin[a + b*x]*SinIntegral[a + b*x])/b^2 + (a*x*SinIntegral[a + b*x]^2)/(2*b) + (1/2)*x^2*SinIntegral[a + b*x]^2 - (a*(a + b*x)*SinIntegral[a + b*x]^2)/(2*b^2) + (a*SinIntegral[2*a + 2*b*x])/b^2}
{x^0*SinIntegral[a + b*x]^2, x, 5, (2*Cos[a + b*x]*SinIntegral[a + b*x])/b + ((a + b*x)*SinIntegral[a + b*x]^2)/b - SinIntegral[2*a + 2*b*x]/b}
{SinIntegral[a + b*x]^2/x^1, x, 0, Int[SinIntegral[a + b*x]^2/x, x]}
{SinIntegral[a + b*x]^2/x^2, x, 0, Int[SinIntegral[a + b*x]^2/x^2, x]}
{SinIntegral[a + b*x]^2/x^3, x, 0, Int[SinIntegral[a + b*x]^2/x^3, x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Trig[b x] SinIntegral[b x]^n*)


{Sin[b*x]*SinIntegral[b*x]/x^3, x, 14, b^2*CosIntegral[2*b*x] - (b*Cos[b*x]*Sin[b*x])/(2*x) - Sin[b*x]^2/(4*x^2) - (b*Sin[2*b*x])/(4*x) - (b*Cos[b*x]*SinIntegral[b*x])/(2*x) - (Sin[b*x]*SinIntegral[b*x])/(2*x^2) - (1/4)*b^2*SinIntegral[b*x]^2}
{Sin[b*x]*SinIntegral[b*x]/x^2, x, 5, b*Int[(Cos[b*x]*SinIntegral[b*x])/x, x] - Sin[b*x]^2/x - (Sin[b*x]*SinIntegral[b*x])/x + b*SinIntegral[2*b*x]}
{Sin[b*x]*SinIntegral[b*x]/x, x, 1, (1/2)*SinIntegral[b*x]^2}
{Sin[b*x]*SinIntegral[b*x], x, 5, -((Cos[b*x]*SinIntegral[b*x])/b) + SinIntegral[2*b*x]/(2*b)}
{x*Sin[b*x]*SinIntegral[b*x], x, 8, CosIntegral[2*b*x]/(2*b^2) - Log[x]/(2*b^2) + Sin[b*x]^2/(2*b^2) - (x*Cos[b*x]*SinIntegral[b*x])/b + (Sin[b*x]*SinIntegral[b*x])/b^2}
{x^2*Sin[b*x]*SinIntegral[b*x], x, 12, -((5*x)/(4*b^2)) + (5*Cos[b*x]*Sin[b*x])/(4*b^3) + (x*Sin[b*x]^2)/(2*b^2) + (2*Cos[b*x]*SinIntegral[b*x])/b^3 - (x^2*Cos[b*x]*SinIntegral[b*x])/b + (2*x*Sin[b*x]*SinIntegral[b*x])/b^2 - SinIntegral[2*b*x]/b^3}
{x^3*Sin[b*x]*SinIntegral[b*x], x, 17, -(x^2/b^2) - (3*CosIntegral[2*b*x])/b^4 + (3*Log[x])/b^4 + (2*x*Cos[b*x]*Sin[b*x])/b^3 - (4*Sin[b*x]^2)/b^4 + (x^2*Sin[b*x]^2)/(2*b^2) + (6*x*Cos[b*x]*SinIntegral[b*x])/b^3 - (x^3*Cos[b*x]*SinIntegral[b*x])/b - (6*Sin[b*x]*SinIntegral[b*x])/b^4 + (3*x^2*Sin[b*x]*SinIntegral[b*x])/b^2}


{Cos[b*x]*SinIntegral[b*x]/x^3, x, 12, -((b*Cos[2*b*x])/(4*x)) - (1/2)*b^2*Int[(Cos[b*x]*SinIntegral[b*x])/x, x] + (b*Sin[b*x]^2)/(2*x) - Sin[2*b*x]/(8*x^2) - (Cos[b*x]*SinIntegral[b*x])/(2*x^2) + (b*Sin[b*x]*SinIntegral[b*x])/(2*x) - b^2*SinIntegral[2*b*x]}
{Cos[b*x]*SinIntegral[b*x]/x^2, x, 7, b*CosIntegral[2*b*x] - Sin[2*b*x]/(2*x) - (Cos[b*x]*SinIntegral[b*x])/x - (1/2)*b*SinIntegral[b*x]^2}
{Cos[b*x]*SinIntegral[b*x]/x, x, 0, Int[(Cos[b*x]*SinIntegral[b*x])/x, x]}
{Cos[b*x]*SinIntegral[b*x], x, 5, CosIntegral[2*b*x]/(2*b) - Log[x]/(2*b) + (Sin[b*x]*SinIntegral[b*x])/b}
{x*Cos[b*x]*SinIntegral[b*x], x, 8, -(x/(2*b)) + (Cos[b*x]*Sin[b*x])/(2*b^2) + (Cos[b*x]*SinIntegral[b*x])/b^2 + (x*Sin[b*x]*SinIntegral[b*x])/b - SinIntegral[2*b*x]/(2*b^2)}
{x^2*Cos[b*x]*SinIntegral[b*x], x, 12, -(x^2/(4*b)) - CosIntegral[2*b*x]/b^3 + Log[x]/b^3 + (x*Cos[b*x]*Sin[b*x])/(2*b^2) - (5*Sin[b*x]^2)/(4*b^3) + (2*x*Cos[b*x]*SinIntegral[b*x])/b^2 - (2*Sin[b*x]*SinIntegral[b*x])/b^3 + (x^2*Sin[b*x]*SinIntegral[b*x])/b}
{x^3*Cos[b*x]*SinIntegral[b*x], x, 17, (4*x)/b^3 - x^3/(6*b) - (4*Cos[b*x]*Sin[b*x])/b^4 + (x^2*Cos[b*x]*Sin[b*x])/(2*b^2) - (2*x*Sin[b*x]^2)/b^3 - (6*Cos[b*x]*SinIntegral[b*x])/b^4 + (3*x^2*Cos[b*x]*SinIntegral[b*x])/b^2 - (6*x*Sin[b*x]*SinIntegral[b*x])/b^3 + (x^3*Sin[b*x]*SinIntegral[b*x])/b + (3*SinIntegral[2*b*x])/b^4}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Trig[a+b x] SinIntegral[c+d x]^n*)


(* {Sin[a + b*x]*SinIntegral[c + d*x]/x^3, x, 0, 0} *)
{Sin[a + b*x]*SinIntegral[c + d*x]/x^2, x, 19, (d*Cos[a - c]*CosIntegral[(b - d)*x])/(2*c) - (d*Cos[a + c]*CosIntegral[(b + d)*x])/(2*c) - (d*Cos[a - (b*c)/d]*CosIntegral[(c*(b - d))/d + (b - d)*x])/(2*c) + (d*Cos[a - (b*c)/d]*CosIntegral[(c*(b + d))/d + (b + d)*x])/(2*c) + b*Int[(Cos[a + b*x]*SinIntegral[c + d*x])/x, x] - (d*Sin[a - c]*SinIntegral[(b - d)*x])/(2*c) + (d*Sin[a + c]*SinIntegral[(b + d)*x])/(2*c) + (d*Sin[a - (b*c)/d]*SinIntegral[(c*(b - d))/d + (b - d)*x])/(2*c) - (Sin[a + b*x]*SinIntegral[c + d*x])/x - (d*Sin[a - (b*c)/d]*SinIntegral[(c*(b + d))/d + (b + d)*x])/(2*c)}
{Sin[a + b*x]*SinIntegral[c + d*x]/x, x, 0, Int[(Sin[a + b*x]*SinIntegral[c + d*x])/x, x]}
{Sin[a + b*x]*SinIntegral[c + d*x], x, 9, -((CosIntegral[(c*(b - d))/d + (b - d)*x]*Sin[a - (b*c)/d])/(2*b)) + (CosIntegral[(c*(b + d))/d + (b + d)*x]*Sin[a - (b*c)/d])/(2*b) - (Cos[a - (b*c)/d]*SinIntegral[(c*(b - d))/d + (b - d)*x])/(2*b) - (Cos[a + b*x]*SinIntegral[c + d*x])/b + (Cos[a - (b*c)/d]*SinIntegral[(c*(b + d))/d + (b + d)*x])/(2*b)}
{x*Sin[a + b*x]*SinIntegral[c + d*x], x, 24, Cos[a - c + (b - d)*x]/(2*b*(b - d)) - Cos[a + c + (b + d)*x]/(2*b*(b + d)) - (Cos[a - (b*c)/d]*CosIntegral[(c*(b - d))/d + (b - d)*x])/(2*b^2) + (Cos[a - (b*c)/d]*CosIntegral[(c*(b + d))/d + (b + d)*x])/(2*b^2) + (c*CosIntegral[(c*(b - d))/d + (b - d)*x]*Sin[a - (b*c)/d])/(2*b*d) - (c*CosIntegral[(c*(b + d))/d + (b + d)*x]*Sin[a - (b*c)/d])/(2*b*d) + (c*Cos[a - (b*c)/d]*SinIntegral[(c*(b - d))/d + (b - d)*x])/(2*b*d) + (Sin[a - (b*c)/d]*SinIntegral[(c*(b - d))/d + (b - d)*x])/(2*b^2) - (x*Cos[a + b*x]*SinIntegral[c + d*x])/b + (Sin[a + b*x]*SinIntegral[c + d*x])/b^2 - (c*Cos[a - (b*c)/d]*SinIntegral[(c*(b + d))/d + (b + d)*x])/(2*b*d) - (Sin[a - (b*c)/d]*SinIntegral[(c*(b + d))/d + (b + d)*x])/(2*b^2)}
(* {x^2*Sin[a + b*x]*SinIntegral[c + d*x], x, 46, -((c*Cos[a - c + (b - d)*x])/(2*b*(b - d)*d)) + (x*Cos[a - c + (b - d)*x])/(2*b*(b - d)) + (c*Cos[a + c + (b + d)*x])/(2*b*d*(b + d)) - (x*Cos[a + c + (b + d)*x])/(2*b*(b + d)) + (CosIntegral[((b - d)*(c + d*x))/d]*(2*b*c*d*Cos[a - (b*c)/d] - (b^2*c^2 - 2*d^2)*Sin[a - (b*c)/d]))/(2*b^3*d^2) - (CosIntegral[((b + d)*(c + d*x))/d]*(2*b*c*d*Cos[a - (b*c)/d] - (b^2*c^2 - 2*d^2)*Sin[a - (b*c)/d]))/(2*b^3*d^2) - Sin[a - c + (b - d)*x]/(2*b*(b - d)^2) - Sin[a - c + (b - d)*x]/(b^2*(b - d)) + Sin[a + c + (b + d)*x]/(2*b*(b + d)^2) + Sin[a + c + (b + d)*x]/(b^2*(b + d)) + (((2 - b^2*x^2)*Cos[a + b*x] + 2*b*x*Sin[a + b*x])*SinIntegral[c + d*x])/b^3 - (((b^2*c^2 - 2*d^2)*Cos[a - (b*c)/d] + 2*b*c*d*Sin[a - (b*c)/d])*SinIntegral[((b - d)*(c + d*x))/d])/(2*b^3*d^2) + (((b^2*c^2 - 2*d^2)*Cos[a - (b*c)/d] + 2*b*c*d*Sin[a - (b*c)/d])*SinIntegral[((b + d)*(c + d*x))/d])/(2*b^3*d^2)} *)
(* {x^3*Sin[a + b*x]*SinIntegral[c + d*x], x, 0, 0} *)


(* {Cos[a + b*x]*SinIntegral[c + d*x]/x^3, x, 0, 0} *)
{Cos[a + b*x]*SinIntegral[c + d*x]/x^2, x, 19, (-b)*Int[(Sin[a + b*x]*SinIntegral[c + d*x])/x, x] - (d*CosIntegral[(b - d)*x]*Sin[a - c])/(2*c) + (d*CosIntegral[(b + d)*x]*Sin[a + c])/(2*c) + (d*CosIntegral[(c*(b - d))/d + (b - d)*x]*Sin[a - (b*c)/d])/(2*c) - (d*CosIntegral[(c*(b + d))/d + (b + d)*x]*Sin[a - (b*c)/d])/(2*c) - (d*Cos[a - c]*SinIntegral[(b - d)*x])/(2*c) + (d*Cos[a + c]*SinIntegral[(b + d)*x])/(2*c) + (d*Cos[a - (b*c)/d]*SinIntegral[(c*(b - d))/d + (b - d)*x])/(2*c) - (Cos[a + b*x]*SinIntegral[c + d*x])/x - (d*Cos[a - (b*c)/d]*SinIntegral[(c*(b + d))/d + (b + d)*x])/(2*c)}
{Cos[a + b*x]*SinIntegral[c + d*x]/x, x, 0, Int[(Cos[a + b*x]*SinIntegral[c + d*x])/x, x]}
{Cos[a + b*x]*SinIntegral[c + d*x], x, 9, -((Cos[a - (b*c)/d]*CosIntegral[(c*(b - d))/d + (b - d)*x])/(2*b)) + (Cos[a - (b*c)/d]*CosIntegral[(c*(b + d))/d + (b + d)*x])/(2*b) + (Sin[a - (b*c)/d]*SinIntegral[(c*(b - d))/d + (b - d)*x])/(2*b) + (Sin[a + b*x]*SinIntegral[c + d*x])/b - (Sin[a - (b*c)/d]*SinIntegral[(c*(b + d))/d + (b + d)*x])/(2*b)}
{x*Cos[a + b*x]*SinIntegral[c + d*x], x, 24, (c*Cos[a - (b*c)/d]*CosIntegral[(c*(b - d))/d + (b - d)*x])/(2*b*d) - (c*Cos[a - (b*c)/d]*CosIntegral[(c*(b + d))/d + (b + d)*x])/(2*b*d) + (CosIntegral[(c*(b - d))/d + (b - d)*x]*Sin[a - (b*c)/d])/(2*b^2) - (CosIntegral[(c*(b + d))/d + (b + d)*x]*Sin[a - (b*c)/d])/(2*b^2) - Sin[a - c + (b - d)*x]/(2*b*(b - d)) + Sin[a + c + (b + d)*x]/(2*b*(b + d)) + (Cos[a - (b*c)/d]*SinIntegral[(c*(b - d))/d + (b - d)*x])/(2*b^2) - (c*Sin[a - (b*c)/d]*SinIntegral[(c*(b - d))/d + (b - d)*x])/(2*b*d) + (Cos[a + b*x]*SinIntegral[c + d*x])/b^2 + (x*Sin[a + b*x]*SinIntegral[c + d*x])/b - (Cos[a - (b*c)/d]*SinIntegral[(c*(b + d))/d + (b + d)*x])/(2*b^2) + (c*Sin[a - (b*c)/d]*SinIntegral[(c*(b + d))/d + (b + d)*x])/(2*b*d)}
(* {x^2*Cos[a + b*x]*SinIntegral[c + d*x], x, 46, -(Cos[a - c + (b - d)*x]/(2*b*(b - d)^2)) - Cos[a - c + (b - d)*x]/(b^2*(b - d)) + Cos[a + c + (b + d)*x]/(2*b*(b + d)^2) + Cos[a + c + (b + d)*x]/(b^2*(b + d)) - (CosIntegral[((b - d)*(c + d*x))/d]*((b^2*c^2 - 2*d^2)*Cos[a - (b*c)/d] + 2*b*c*d*Sin[a - (b*c)/d]))/(2*b^3*d^2) + (CosIntegral[((b + d)*(c + d*x))/d]*((b^2*c^2 - 2*d^2)*Cos[a - (b*c)/d] + 2*b*c*d*Sin[a - (b*c)/d]))/(2*b^3*d^2) + (c*Sin[a - c + (b - d)*x])/(2*b*(b - d)*d) - (x*Sin[a - c + (b - d)*x])/(2*b*(b - d)) - (c*Sin[a + c + (b + d)*x])/(2*b*d*(b + d)) + (x*Sin[a + c + (b + d)*x])/(2*b*(b + d)) + ((2*b*x*Cos[a + b*x] - (2 - b^2*x^2)*Sin[a + b*x])*SinIntegral[c + d*x])/b^3 - ((2*b*c*d*Cos[a - (b*c)/d] - (b^2*c^2 - 2*d^2)*Sin[a - (b*c)/d])*SinIntegral[((b - d)*(c + d*x))/d])/(2*b^3*d^2) + ((2*b*c*d*Cos[a - (b*c)/d] - (b^2*c^2 - 2*d^2)*Sin[a - (b*c)/d])*SinIntegral[((b + d)*(c + d*x))/d])/(2*b^3*d^2)} *)
(* {x^3*Cos[a + b*x]*SinIntegral[c + d*x], x, 0, 0} *)


(* ::Section:: *)
(*Cosine integral function*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m CosIntegral[b x]^n*)


{x^m*CosIntegral[b*x], x, 5, (x^(1 + m)*CosIntegral[b*x])/(1 + m) + (I*x^m*Gamma[1 + m, (-I)*b*x])/(((-I)*b*x)^m*(2*b*(1 + m))) - (I*x^m*Gamma[1 + m, I*b*x])/((I*b*x)^m*(2*b*(1 + m)))}

{x^3*CosIntegral[b*x], x, 6, (3*Cos[b*x])/(2*b^4) - (3*x^2*Cos[b*x])/(4*b^2) + (1/4)*x^4*CosIntegral[b*x] + (3*x*Sin[b*x])/(2*b^3) - (x^3*Sin[b*x])/(4*b)}
{x^2*CosIntegral[b*x], x, 5, -((2*x*Cos[b*x])/(3*b^2)) + (1/3)*x^3*CosIntegral[b*x] + (2*Sin[b*x])/(3*b^3) - (x^2*Sin[b*x])/(3*b)}
{x^1*CosIntegral[b*x], x, 4, -(Cos[b*x]/(2*b^2)) + (1/2)*x^2*CosIntegral[b*x] - (x*Sin[b*x])/(2*b)}
{x^0*CosIntegral[b*x], x, 1, x*CosIntegral[b*x] - Sin[b*x]/b}
{CosIntegral[b*x]/x^1, x, 0, Int[CosIntegral[b*x]/x, x]}
{CosIntegral[b*x]/x^2, x, 4, -(Cos[b*x]/x) - CosIntegral[b*x]/x - b*SinIntegral[b*x]}
{CosIntegral[b*x]/x^3, x, 5, -(Cos[b*x]/(4*x^2)) - (1/4)*b^2*CosIntegral[b*x] - CosIntegral[b*x]/(2*x^2) + (b*Sin[b*x])/(4*x)}


{x^m*CosIntegral[b*x]^2, x, 0, Int[x^m*CosIntegral[b*x]^2, x]}

{x^3*CosIntegral[b*x]^2, x, 18, x^2/(4*b^2) + (3*Cos[b*x]^2)/(8*b^4) + (3*Cos[b*x]*CosIntegral[b*x])/b^4 - (3*x^2*Cos[b*x]*CosIntegral[b*x])/(2*b^2) + (1/4)*x^4*CosIntegral[b*x]^2 - (3*CosIntegral[2*b*x])/(2*b^4) - (3*Log[x])/(2*b^4) + (x*Cos[b*x]*Sin[b*x])/b^3 + (3*x*CosIntegral[b*x]*Sin[b*x])/b^3 - (x^3*CosIntegral[b*x]*Sin[b*x])/(2*b) - (13*Sin[b*x]^2)/(8*b^4) + (x^2*Sin[b*x]^2)/(4*b^2)}
{x^2*CosIntegral[b*x]^2, x, 13, x/(2*b^2) - (4*x*Cos[b*x]*CosIntegral[b*x])/(3*b^2) + (1/3)*x^3*CosIntegral[b*x]^2 + (5*Cos[b*x]*Sin[b*x])/(6*b^3) + (4*CosIntegral[b*x]*Sin[b*x])/(3*b^3) - (2*x^2*CosIntegral[b*x]*Sin[b*x])/(3*b) + (x*Sin[b*x]^2)/(3*b^2) - (2*SinIntegral[2*b*x])/(3*b^3)}
{x^1*CosIntegral[b*x]^2, x, 9, -((Cos[b*x]*CosIntegral[b*x])/b^2) + (1/2)*x^2*CosIntegral[b*x]^2 + CosIntegral[2*b*x]/(2*b^2) + Log[x]/(2*b^2) - (x*CosIntegral[b*x]*Sin[b*x])/b + Sin[b*x]^2/(2*b^2)}
{x^0*CosIntegral[b*x]^2, x, 6, x*CosIntegral[b*x]^2 - (2*CosIntegral[b*x]*Sin[b*x])/b + SinIntegral[2*b*x]/b}
{CosIntegral[b*x]^2/x^1, x, 0, Int[CosIntegral[b*x]^2/x, x]}
{CosIntegral[b*x]^2/x^2, x, 0, Int[CosIntegral[b*x]^2/x^2, x]}
{CosIntegral[b*x]^2/x^3, x, 0, Int[CosIntegral[b*x]^2/x^3, x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m CosIntegral[a+b x]^n*)


{x^m*CosIntegral[a + b*x], x, 6, (x^(1 + m)*CosIntegral[a + b*x])/(1 + m) + (I*E^(I*a)*x^m*Gamma[1 + m, (-I)*b*x])/(((-I)*b*x)^m*(2*b*(1 + m))) - (I*x^m*Gamma[1 + m, I*b*x])/(E^(I*a)*(I*b*x)^m*(2*b*(1 + m))) + (a*Int[(x^m*Cos[a + b*x])/(a + b*x), x])/(1 + m)}

{x^3*CosIntegral[a + b*x], x, 14, (3*Cos[a + b*x])/(2*b^4) - (a^2*Cos[a + b*x])/(4*b^4) + (a*x*Cos[a + b*x])/(2*b^3) - (3*x^2*Cos[a + b*x])/(4*b^2) - (a^4*CosIntegral[a + b*x])/(4*b^4) + (1/4)*x^4*CosIntegral[a + b*x] - (a*Sin[a + b*x])/(2*b^4) + (a^3*Sin[a + b*x])/(4*b^4) + (3*x*Sin[a + b*x])/(2*b^3) - (a^2*x*Sin[a + b*x])/(4*b^3) + (a*x^2*Sin[a + b*x])/(4*b^2) - (x^3*Sin[a + b*x])/(4*b)}
{x^2*CosIntegral[a + b*x], x, 10, (a*Cos[a + b*x])/(3*b^3) - (2*x*Cos[a + b*x])/(3*b^2) + (a^3*CosIntegral[a + b*x])/(3*b^3) + (1/3)*x^3*CosIntegral[a + b*x] + (2*Sin[a + b*x])/(3*b^3) - (a^2*Sin[a + b*x])/(3*b^3) + (a*x*Sin[a + b*x])/(3*b^2) - (x^2*Sin[a + b*x])/(3*b)}
{x^1*CosIntegral[a + b*x], x, 7, -(Cos[a + b*x]/(2*b^2)) - (a^2*CosIntegral[a + b*x])/(2*b^2) + (1/2)*x^2*CosIntegral[a + b*x] + (a*Sin[a + b*x])/(2*b^2) - (x*Sin[a + b*x])/(2*b)}
{x^0*CosIntegral[a + b*x], x, 1, ((a + b*x)*CosIntegral[a + b*x])/b - Sin[a + b*x]/b}
{CosIntegral[a + b*x]/x^1, x, 0, Int[CosIntegral[a + b*x]/x, x]}
{CosIntegral[a + b*x]/x^2, x, 7, (b*Cos[a]*CosIntegral[b*x])/a - (b*CosIntegral[a + b*x])/a - CosIntegral[a + b*x]/x - (b*Sin[a]*SinIntegral[b*x])/a}
{CosIntegral[a + b*x]/x^3, x, 11, -((b*Cos[a + b*x])/(2*a*x)) - (b^2*Cos[a]*CosIntegral[b*x])/(2*a^2) + (b^2*CosIntegral[a + b*x])/(2*a^2) - CosIntegral[a + b*x]/(2*x^2) - (b^2*CosIntegral[b*x]*Sin[a])/(2*a) - (b^2*Cos[a]*SinIntegral[b*x])/(2*a) + (b^2*Sin[a]*SinIntegral[b*x])/(2*a^2)}


{x^m*CosIntegral[a + b*x]^2, x, 0, Int[x^m*CosIntegral[a + b*x]^2, x]}

(* {x^3*CosIntegral[a + b*x]^2, x, 77, -((5*a*x)/(4*b^3)) + (3*x^2)/(8*b^2) + (3*Cos[a + b*x]^2)/(8*b^4) + (13*Cos[2*a + 2*b*x])/(16*b^4) - (3*a^2*Cos[2*a + 2*b*x])/(8*b^4) + (a*x*Cos[2*a + 2*b*x])/(4*b^3) - (x^2*Cos[2*a + 2*b*x])/(8*b^2) - (1/4)*(a^4/b^4 - x^4)*CosIntegral[a + b*x]^2 - (3*(1 - a^2)*CosIntegral[2*(a + b*x)])/(2*b^4) - (3*Log[a + b*x])/(2*b^4) + (3*a^2*Log[a + b*x])/(2*b^4) - (5*a*Cos[a + b*x]*Sin[a + b*x])/(4*b^4) + (3*x*Cos[a + b*x]*Sin[a + b*x])/(4*b^3) + (CosIntegral[a + b*x]*((6 - a^2 + 2*a*b*x - 3*b^2*x^2)*Cos[a + b*x] + (a^3 + 6*b*x - a^2*b*x - b^3*x^3 - a*(2 - b^2*x^2))*Sin[a + b*x]))/(2*b^4) - (a*Sin[2*a + 2*b*x])/(8*b^4) + (x*Sin[2*a + 2*b*x])/(8*b^3) + (a*(2 - a^2)*SinIntegral[2*(a + b*x)])/b^4} *)
{x^2*CosIntegral[a + b*x]^2, x, 34, (2*x)/(3*b^2) + (a*Cos[2*a + 2*b*x])/(3*b^3) - (x*Cos[2*a + 2*b*x])/(6*b^2) + (2*a*Cos[a + b*x]*CosIntegral[a + b*x])/(3*b^3) - (4*x*Cos[a + b*x]*CosIntegral[a + b*x])/(3*b^2) - (a^2*x*CosIntegral[a + b*x]^2)/(3*b^2) + (1/3)*x^3*CosIntegral[a + b*x]^2 + (a^2*(a + b*x)*CosIntegral[a + b*x]^2)/(3*b^3) - (a*CosIntegral[2*a + 2*b*x])/b^3 - (a*Log[a + b*x])/b^3 + (2*Cos[a + b*x]*Sin[a + b*x])/(3*b^3) + (4*CosIntegral[a + b*x]*Sin[a + b*x])/(3*b^3) - (2*a^2*CosIntegral[a + b*x]*Sin[a + b*x])/(3*b^3) + (2*a*x*CosIntegral[a + b*x]*Sin[a + b*x])/(3*b^2) - (2*x^2*CosIntegral[a + b*x]*Sin[a + b*x])/(3*b) + Sin[2*a + 2*b*x]/(12*b^3) - (2*SinIntegral[2*a + 2*b*x])/(3*b^3) + (a^2*SinIntegral[2*a + 2*b*x])/b^3}
{x^1*CosIntegral[a + b*x]^2, x, 15, -(Cos[2*a + 2*b*x]/(4*b^2)) - (Cos[a + b*x]*CosIntegral[a + b*x])/b^2 + (a*x*CosIntegral[a + b*x]^2)/(2*b) + (1/2)*x^2*CosIntegral[a + b*x]^2 - (a*(a + b*x)*CosIntegral[a + b*x]^2)/(2*b^2) + CosIntegral[2*a + 2*b*x]/(2*b^2) + Log[a + b*x]/(2*b^2) + (a*CosIntegral[a + b*x]*Sin[a + b*x])/b^2 - (x*CosIntegral[a + b*x]*Sin[a + b*x])/b - (a*SinIntegral[2*a + 2*b*x])/b^2}
{x^0*CosIntegral[a + b*x]^2, x, 5, ((a + b*x)*CosIntegral[a + b*x]^2)/b - (2*CosIntegral[a + b*x]*Sin[a + b*x])/b + SinIntegral[2*a + 2*b*x]/b}
{CosIntegral[a + b*x]^2/x^1, x, 0, Int[CosIntegral[a + b*x]^2/x, x]}
{CosIntegral[a + b*x]^2/x^2, x, 0, Int[CosIntegral[a + b*x]^2/x^2, x]}
{CosIntegral[a + b*x]^2/x^3, x, 0, Int[CosIntegral[a + b*x]^2/x^3, x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Trig[b x] CosIntegral[b x]^n*)


{Sin[b*x]*CosIntegral[b*x]/x^3, x, 12, -((b*Cos[b*x]^2)/(2*x)) - (b*Cos[2*b*x])/(4*x) - (b*Cos[b*x]*CosIntegral[b*x])/(2*x) - (1/2)*b^2*Int[(CosIntegral[b*x]*Sin[b*x])/x, x] - (CosIntegral[b*x]*Sin[b*x])/(2*x^2) - Sin[2*b*x]/(8*x^2) - b^2*SinIntegral[2*b*x]}
{Sin[b*x]*CosIntegral[b*x]/x^2, x, 7, (1/2)*b*CosIntegral[b*x]^2 + b*CosIntegral[2*b*x] - (CosIntegral[b*x]*Sin[b*x])/x - Sin[2*b*x]/(2*x)}
{Sin[b*x]*CosIntegral[b*x]/x, x, 0, Int[(CosIntegral[b*x]*Sin[b*x])/x, x]}
{Sin[b*x]*CosIntegral[b*x], x, 5, -((Cos[b*x]*CosIntegral[b*x])/b) + CosIntegral[2*b*x]/(2*b) + Log[x]/(2*b)}
{x*Sin[b*x]*CosIntegral[b*x], x, 8, x/(2*b) - (x*Cos[b*x]*CosIntegral[b*x])/b + (Cos[b*x]*Sin[b*x])/(2*b^2) + (CosIntegral[b*x]*Sin[b*x])/b^2 - SinIntegral[2*b*x]/(2*b^2)}
{x^2*Sin[b*x]*CosIntegral[b*x], x, 12, x^2/(4*b) + Cos[b*x]^2/(4*b^3) + (2*Cos[b*x]*CosIntegral[b*x])/b^3 - (x^2*Cos[b*x]*CosIntegral[b*x])/b - CosIntegral[2*b*x]/b^3 - Log[x]/b^3 + (x*Cos[b*x]*Sin[b*x])/(2*b^2) + (2*x*CosIntegral[b*x]*Sin[b*x])/b^2 - Sin[b*x]^2/b^3}
{x^3*Sin[b*x]*CosIntegral[b*x], x, 17, -((5*x)/(2*b^3)) + x^3/(6*b) + (x*Cos[b*x]^2)/(2*b^3) + (6*x*Cos[b*x]*CosIntegral[b*x])/b^3 - (x^3*Cos[b*x]*CosIntegral[b*x])/b - (4*Cos[b*x]*Sin[b*x])/b^4 + (x^2*Cos[b*x]*Sin[b*x])/(2*b^2) - (6*CosIntegral[b*x]*Sin[b*x])/b^4 + (3*x^2*CosIntegral[b*x]*Sin[b*x])/b^2 - (3*x*Sin[b*x]^2)/(2*b^3) + (3*SinIntegral[2*b*x])/b^4}


{Cos[b*x]*CosIntegral[b*x]/x^3, x, 14, -(Cos[b*x]^2/(4*x^2)) - (Cos[b*x]*CosIntegral[b*x])/(2*x^2) - (1/4)*b^2*CosIntegral[b*x]^2 - b^2*CosIntegral[2*b*x] + (b*Cos[b*x]*Sin[b*x])/(2*x) + (b*CosIntegral[b*x]*Sin[b*x])/(2*x) + (b*Sin[2*b*x])/(4*x)}
{Cos[b*x]*CosIntegral[b*x]/x^2, x, 5, -(Cos[b*x]^2/x) - (Cos[b*x]*CosIntegral[b*x])/x - b*Int[(CosIntegral[b*x]*Sin[b*x])/x, x] - b*SinIntegral[2*b*x]}
{Cos[b*x]*CosIntegral[b*x]/x, x, 1, (1/2)*CosIntegral[b*x]^2}
{Cos[b*x]*CosIntegral[b*x], x, 5, (CosIntegral[b*x]*Sin[b*x])/b - SinIntegral[2*b*x]/(2*b)}
{x*Cos[b*x]*CosIntegral[b*x], x, 8, (Cos[b*x]*CosIntegral[b*x])/b^2 - CosIntegral[2*b*x]/(2*b^2) - Log[x]/(2*b^2) + (x*CosIntegral[b*x]*Sin[b*x])/b - Sin[b*x]^2/(2*b^2)}
{x^2*Cos[b*x]*CosIntegral[b*x], x, 12, -((3*x)/(4*b^2)) + (2*x*Cos[b*x]*CosIntegral[b*x])/b^2 - (5*Cos[b*x]*Sin[b*x])/(4*b^3) - (2*CosIntegral[b*x]*Sin[b*x])/b^3 + (x^2*CosIntegral[b*x]*Sin[b*x])/b - (x*Sin[b*x]^2)/(2*b^2) + SinIntegral[2*b*x]/b^3}
{x^3*Cos[b*x]*CosIntegral[b*x], x, 17, -(x^2/(2*b^2)) - (3*Cos[b*x]^2)/(4*b^4) - (6*Cos[b*x]*CosIntegral[b*x])/b^4 + (3*x^2*Cos[b*x]*CosIntegral[b*x])/b^2 + (3*CosIntegral[2*b*x])/b^4 + (3*Log[x])/b^4 - (2*x*Cos[b*x]*Sin[b*x])/b^3 - (6*x*CosIntegral[b*x]*Sin[b*x])/b^3 + (x^3*CosIntegral[b*x]*Sin[b*x])/b + (13*Sin[b*x]^2)/(4*b^4) - (x^2*Sin[b*x]^2)/(2*b^2)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Trig[a+b x] CosIntegral[c+d x]^n*)


{Cos[5*x]*CosIntegral[2*x], x, 6, (1/5)*CosIntegral[2*x]*Sin[5*x] - (1/10)*SinIntegral[3*x] - (1/10)*SinIntegral[7*x]}


(* {Sin[a + b*x]*CosIntegral[c + d*x]/x^3, x, 0, 0} *)
{Sin[a + b*x]*CosIntegral[c + d*x]/x^2, x, 19, b*Int[(Cos[a + b*x]*CosIntegral[c + d*x])/x, x] + (d*CosIntegral[(b - d)*x]*Sin[a - c])/(2*c) + (d*CosIntegral[(b + d)*x]*Sin[a + c])/(2*c) - (d*CosIntegral[(c*(b - d))/d + (b - d)*x]*Sin[a - (b*c)/d])/(2*c) - (d*CosIntegral[(c*(b + d))/d + (b + d)*x]*Sin[a - (b*c)/d])/(2*c) - (CosIntegral[c + d*x]*Sin[a + b*x])/x + (d*Cos[a - c]*SinIntegral[(b - d)*x])/(2*c) + (d*Cos[a + c]*SinIntegral[(b + d)*x])/(2*c) - (d*Cos[a - (b*c)/d]*SinIntegral[(c*(b - d))/d + (b - d)*x])/(2*c) - (d*Cos[a - (b*c)/d]*SinIntegral[(c*(b + d))/d + (b + d)*x])/(2*c)}
{Sin[a + b*x]*CosIntegral[c + d*x]/x, x, 0, Int[(CosIntegral[c + d*x]*Sin[a + b*x])/x, x]}
{Sin[a + b*x]*CosIntegral[c + d*x], x, 9, (Cos[a - (b*c)/d]*CosIntegral[(c*(b - d))/d + (b - d)*x])/(2*b) - (Cos[a + b*x]*CosIntegral[c + d*x])/b + (Cos[a - (b*c)/d]*CosIntegral[(c*(b + d))/d + (b + d)*x])/(2*b) - (Sin[a - (b*c)/d]*SinIntegral[(c*(b - d))/d + (b - d)*x])/(2*b) - (Sin[a - (b*c)/d]*SinIntegral[(c*(b + d))/d + (b + d)*x])/(2*b)}
{x*Sin[a + b*x]*CosIntegral[c + d*x], x, 24, -((c*Cos[a - (b*c)/d]*CosIntegral[(c*(b - d))/d + (b - d)*x])/(2*b*d)) - (x*Cos[a + b*x]*CosIntegral[c + d*x])/b - (c*Cos[a - (b*c)/d]*CosIntegral[(c*(b + d))/d + (b + d)*x])/(2*b*d) - (CosIntegral[(c*(b - d))/d + (b - d)*x]*Sin[a - (b*c)/d])/(2*b^2) - (CosIntegral[(c*(b + d))/d + (b + d)*x]*Sin[a - (b*c)/d])/(2*b^2) + (CosIntegral[c + d*x]*Sin[a + b*x])/b^2 + Sin[a - c + (b - d)*x]/(2*b*(b - d)) + Sin[a + c + (b + d)*x]/(2*b*(b + d)) - (Cos[a - (b*c)/d]*SinIntegral[(c*(b - d))/d + (b - d)*x])/(2*b^2) + (c*Sin[a - (b*c)/d]*SinIntegral[(c*(b - d))/d + (b - d)*x])/(2*b*d) - (Cos[a - (b*c)/d]*SinIntegral[(c*(b + d))/d + (b + d)*x])/(2*b^2) + (c*Sin[a - (b*c)/d]*SinIntegral[(c*(b + d))/d + (b + d)*x])/(2*b*d)}
(* {x^2*Sin[a + b*x]*CosIntegral[c + d*x], x, 46, Cos[a - c + (b - d)*x]/(2*b*(b - d)^2) + Cos[a - c + (b - d)*x]/(b^2*(b - d)) + Cos[a + c + (b + d)*x]/(2*b*(b + d)^2) + Cos[a + c + (b + d)*x]/(b^2*(b + d)) + (CosIntegral[((b - d)*(c + d*x))/d]*((b^2*c^2 - 2*d^2)*Cos[a - (b*c)/d] + 2*b*c*d*Sin[a - (b*c)/d]))/(2*b^3*d^2) + (CosIntegral[((b + d)*(c + d*x))/d]*((b^2*c^2 - 2*d^2)*Cos[a - (b*c)/d] + 2*b*c*d*Sin[a - (b*c)/d]))/(2*b^3*d^2) + (CosIntegral[c + d*x]*((2 - b^2*x^2)*Cos[a + b*x] + 2*b*x*Sin[a + b*x]))/b^3 - (c*Sin[a - c + (b - d)*x])/(2*b*(b - d)*d) + (x*Sin[a - c + (b - d)*x])/(2*b*(b - d)) - (c*Sin[a + c + (b + d)*x])/(2*b*d*(b + d)) + (x*Sin[a + c + (b + d)*x])/(2*b*(b + d)) + ((2*b*c*d*Cos[a - (b*c)/d] - (b^2*c^2 - 2*d^2)*Sin[a - (b*c)/d])*SinIntegral[((b - d)*(c + d*x))/d])/(2*b^3*d^2) + ((2*b*c*d*Cos[a - (b*c)/d] - (b^2*c^2 - 2*d^2)*Sin[a - (b*c)/d])*SinIntegral[((b + d)*(c + d*x))/d])/(2*b^3*d^2)} *)
(* {x^3*Sin[a + b*x]*CosIntegral[c + d*x], x, 0, 0} *)


(* {Cos[a + b*x]*CosIntegral[c + d*x]/x^3, x, 0, 0} *)
{Cos[a + b*x]*CosIntegral[c + d*x]/x^2, x, 19, (d*Cos[a - c]*CosIntegral[(b - d)*x])/(2*c) + (d*Cos[a + c]*CosIntegral[(b + d)*x])/(2*c) - (d*Cos[a - (b*c)/d]*CosIntegral[(c*(b - d))/d + (b - d)*x])/(2*c) - (Cos[a + b*x]*CosIntegral[c + d*x])/x - (d*Cos[a - (b*c)/d]*CosIntegral[(c*(b + d))/d + (b + d)*x])/(2*c) - b*Int[(CosIntegral[c + d*x]*Sin[a + b*x])/x, x] - (d*Sin[a - c]*SinIntegral[(b - d)*x])/(2*c) - (d*Sin[a + c]*SinIntegral[(b + d)*x])/(2*c) + (d*Sin[a - (b*c)/d]*SinIntegral[(c*(b - d))/d + (b - d)*x])/(2*c) + (d*Sin[a - (b*c)/d]*SinIntegral[(c*(b + d))/d + (b + d)*x])/(2*c)}
{Cos[a + b*x]*CosIntegral[c + d*x]/x, x, 0, Int[(Cos[a + b*x]*CosIntegral[c + d*x])/x, x]}
{Cos[a + b*x]*CosIntegral[c + d*x], x, 9, -((CosIntegral[(c*(b - d))/d + (b - d)*x]*Sin[a - (b*c)/d])/(2*b)) - (CosIntegral[(c*(b + d))/d + (b + d)*x]*Sin[a - (b*c)/d])/(2*b) + (CosIntegral[c + d*x]*Sin[a + b*x])/b - (Cos[a - (b*c)/d]*SinIntegral[(c*(b - d))/d + (b - d)*x])/(2*b) - (Cos[a - (b*c)/d]*SinIntegral[(c*(b + d))/d + (b + d)*x])/(2*b)}
{x*Cos[a + b*x]*CosIntegral[c + d*x], x, 24, Cos[a - c + (b - d)*x]/(2*b*(b - d)) + Cos[a + c + (b + d)*x]/(2*b*(b + d)) - (Cos[a - (b*c)/d]*CosIntegral[(c*(b - d))/d + (b - d)*x])/(2*b^2) + (Cos[a + b*x]*CosIntegral[c + d*x])/b^2 - (Cos[a - (b*c)/d]*CosIntegral[(c*(b + d))/d + (b + d)*x])/(2*b^2) + (c*CosIntegral[(c*(b - d))/d + (b - d)*x]*Sin[a - (b*c)/d])/(2*b*d) + (c*CosIntegral[(c*(b + d))/d + (b + d)*x]*Sin[a - (b*c)/d])/(2*b*d) + (x*CosIntegral[c + d*x]*Sin[a + b*x])/b + (c*Cos[a - (b*c)/d]*SinIntegral[(c*(b - d))/d + (b - d)*x])/(2*b*d) + (Sin[a - (b*c)/d]*SinIntegral[(c*(b - d))/d + (b - d)*x])/(2*b^2) + (c*Cos[a - (b*c)/d]*SinIntegral[(c*(b + d))/d + (b + d)*x])/(2*b*d) + (Sin[a - (b*c)/d]*SinIntegral[(c*(b + d))/d + (b + d)*x])/(2*b^2)}
(* {x^2*Cos[a + b*x]*CosIntegral[c + d*x], x, 46, -((c*Cos[a - c + (b - d)*x])/(2*b*(b - d)*d)) + (x*Cos[a - c + (b - d)*x])/(2*b*(b - d)) - (c*Cos[a + c + (b + d)*x])/(2*b*d*(b + d)) + (x*Cos[a + c + (b + d)*x])/(2*b*(b + d)) + (CosIntegral[((b - d)*(c + d*x))/d]*(2*b*c*d*Cos[a - (b*c)/d] - (b^2*c^2 - 2*d^2)*Sin[a - (b*c)/d]))/(2*b^3*d^2) + (CosIntegral[((b + d)*(c + d*x))/d]*(2*b*c*d*Cos[a - (b*c)/d] - (b^2*c^2 - 2*d^2)*Sin[a - (b*c)/d]))/(2*b^3*d^2) + (CosIntegral[c + d*x]*(2*b*x*Cos[a + b*x] - (2 - b^2*x^2)*Sin[a + b*x]))/b^3 - Sin[a - c + (b - d)*x]/(2*b*(b - d)^2) - Sin[a - c + (b - d)*x]/(b^2*(b - d)) - Sin[a + c + (b + d)*x]/(2*b*(b + d)^2) - Sin[a + c + (b + d)*x]/(b^2*(b + d)) - (((b^2*c^2 - 2*d^2)*Cos[a - (b*c)/d] + 2*b*c*d*Sin[a - (b*c)/d])*SinIntegral[((b - d)*(c + d*x))/d])/(2*b^3*d^2) - (((b^2*c^2 - 2*d^2)*Cos[a - (b*c)/d] + 2*b*c*d*Sin[a - (b*c)/d])*SinIntegral[((b + d)*(c + d*x))/d])/(2*b^3*d^2)} *)
(* {x^3*Cos[a + b*x]*CosIntegral[c + d*x], x, 0, 0} *)
