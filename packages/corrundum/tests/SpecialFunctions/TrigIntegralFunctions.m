(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Trig Integral Functions*)


(* ::Subsection::Closed:: *)
(*Sine integral function*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m SinIntegral[b x]^n*)


{SinIntegral[b*x]/x^3, x, 5, -((b*Cos[b*x])/(4*x)) - Sin[b*x]/(4*x^2) - ((2 + b^2*x^2)*SinIntegral[b*x])/(4*x^2)}
{SinIntegral[b*x]/x^2, x, 4, b*CosIntegral[b*x] - Sin[b*x]/x - SinIntegral[b*x]/x}
{SinIntegral[b*x]/x, x, 0, Int[SinIntegral[b*x]/x, x]}
{SinIntegral[b*x], x, 1, Cos[b*x]/b + x*SinIntegral[b*x]}
{x*SinIntegral[b*x], x, 4, (x*Cos[b*x])/(2*b) - Sin[b*x]/(2*b^2) + (1/2)*x^2*SinIntegral[b*x]}
{x^2*SinIntegral[b*x], x, 5, -((2*Cos[b*x])/(3*b^3)) + (x^2*Cos[b*x])/(3*b) - (2*x*Sin[b*x])/(3*b^2) + (1/3)*x^3*SinIntegral[b*x]}
{x^3*SinIntegral[b*x], x, 6, -((3*x*Cos[b*x])/(2*b^3)) + (x^3*Cos[b*x])/(4*b) + (3*Sin[b*x])/(2*b^4) - (3*x^2*Sin[b*x])/(4*b^2) + (1/4)*x^4*SinIntegral[b*x]}
{x^m*SinIntegral[b*x], x, 5, -((I*x^(1 + m)*((-I)*b*x)^(-1 - m)*Gamma[1 + m, (-I)*b*x])/(2*(1 + m))) + (I*x^(1 + m)*(I*b*x)^(-1 - m)*Gamma[1 + m, I*b*x])/(2*(1 + m)) + (x^(1 + m)*SinIntegral[b*x])/(1 + m)}


{SinIntegral[b*x]^2/x^3, x, 0, Int[SinIntegral[b*x]^2/x^3, x]}
{SinIntegral[b*x]^2/x^2, x, 0, Int[SinIntegral[b*x]^2/x^2, x]}
{SinIntegral[b*x]^2/x, x, 0, Int[SinIntegral[b*x]^2/x, x]}
{SinIntegral[b*x]^2, x, 6, (2*Cos[b*x]*SinIntegral[b*x])/b + x*SinIntegral[b*x]^2 - SinIntegral[2*b*x]/b}
{x*SinIntegral[b*x]^2, x, 11, -(CosIntegral[2*b*x]/(2*b^2)) + Log[x]/(2*b^2) - Sin[b*x]^2/(2*b^2) + ((b*x*Cos[b*x] - Sin[b*x])*SinIntegral[b*x])/b^2 + (1/2)*x^2*SinIntegral[b*x]^2}
{x^2*SinIntegral[b*x]^2, x, 13, (5*x)/(6*b^2) - (5*Cos[b*x]*Sin[b*x])/(6*b^3) - (x*Sin[b*x]^2)/(3*b^2) - (2*((2 - b^2*x^2)*Cos[b*x] + 2*b*x*Sin[b*x])*SinIntegral[b*x])/(3*b^3) + (1/3)*x^3*SinIntegral[b*x]^2 + (2*SinIntegral[2*b*x])/(3*b^3)}
{x^3*SinIntegral[b*x]^2, x, 20, x^2/(2*b^2) + (3*CosIntegral[2*b*x])/(2*b^4) - (3*Log[x])/(2*b^4) - (x*Cos[b*x]*Sin[b*x])/b^3 + (2*Sin[b*x]^2)/b^4 - (x^2*Sin[b*x]^2)/(4*b^2) - ((b*x*(6 - b^2*x^2)*Cos[b*x] - 3*(2 - b^2*x^2)*Sin[b*x])*SinIntegral[b*x])/(2*b^4) + (1/4)*x^4*SinIntegral[b*x]^2}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m SinIntegral[a+b x]^n*)


{SinIntegral[a + b*x]/x^3, x, 12, (b^2*CosIntegral[b*x]*(a*Cos[a] - Sin[a]))/(2*a^2) - (b*Sin[a + b*x])/(2*a*x) - (b^2*(Cos[a] + a*Sin[a])*SinIntegral[b*x])/(2*a^2) + (1/2)*(b^2/a^2 - 1/x^2)*SinIntegral[a + b*x]}
{SinIntegral[a + b*x]/x^2, x, 8, (b*CosIntegral[b*x]*Sin[a])/a + (b*Cos[a]*SinIntegral[b*x])/a - ((a + b*x)*SinIntegral[a + b*x])/(a*x)}
{SinIntegral[a + b*x]/x, x, 0, Int[SinIntegral[a + b*x]/x, x]}
{SinIntegral[a + b*x], x, 1, Cos[a + b*x]/b + ((a + b*x)*SinIntegral[a + b*x])/b}
{x*SinIntegral[a + b*x], x, 8, -((a*Cos[a + b*x])/(2*b^2)) + (x*Cos[a + b*x])/(2*b) - Sin[a + b*x]/(2*b^2) - (1/2)*(a^2/b^2 - x^2)*SinIntegral[a + b*x]}
{x^2*SinIntegral[a + b*x], x, 11, -((2*Cos[a + b*x])/(3*b^3)) + (a^2*Cos[a + b*x])/(3*b^3) - (a*x*Cos[a + b*x])/(3*b^2) + (x^2*Cos[a + b*x])/(3*b) + (a*Sin[a + b*x])/(3*b^3) - (2*x*Sin[a + b*x])/(3*b^2) + (1/3)*(a^3/b^3 + x^3)*SinIntegral[a + b*x]}
{x^3*SinIntegral[a + b*x], x, 15, (a*Cos[a + b*x])/(2*b^4) - (a^3*Cos[a + b*x])/(4*b^4) - (3*x*Cos[a + b*x])/(2*b^3) + (a^2*x*Cos[a + b*x])/(4*b^3) - (a*x^2*Cos[a + b*x])/(4*b^2) + (x^3*Cos[a + b*x])/(4*b) + (3*Sin[a + b*x])/(2*b^4) - (a^2*Sin[a + b*x])/(4*b^4) + (a*x*Sin[a + b*x])/(2*b^3) - (3*x^2*Sin[a + b*x])/(4*b^2) - (1/4)*(a^4/b^4 - x^4)*SinIntegral[a + b*x]}
{x^m*SinIntegral[a + b*x], x, 6, -((I*E^(I*a)*x^(1 + m)*((-I)*b*x)^(-1 - m)*Gamma[1 + m, (-I)*b*x])/(2*(1 + m))) + (I*x^(1 + m)*(I*b*x)^(-1 - m)*Gamma[1 + m, I*b*x])/(E^(I*a)*(2*(1 + m))) + (a*Int[(x^m*Sin[a + b*x])/(a + b*x), x])/(1 + m) + (x^(1 + m)*SinIntegral[a + b*x])/(1 + m)}


{SinIntegral[a + b*x]^2/x^3, x, 0, Int[SinIntegral[a + b*x]^2/x^3, x]}
{SinIntegral[a + b*x]^2/x^2, x, 0, Int[SinIntegral[a + b*x]^2/x^2, x]}
{SinIntegral[a + b*x]^2/x, x, 0, Int[SinIntegral[a + b*x]^2/x, x]}
{SinIntegral[a + b*x]^2, x, 6, (2*Cos[a + b*x]*SinIntegral[a + b*x])/b + ((a + b*x)*SinIntegral[a + b*x]^2)/b - SinIntegral[2*(a + b*x)]/b}
{x*SinIntegral[a + b*x]^2, x, 19, Cos[2*a + 2*b*x]/(4*b^2) - CosIntegral[2*(a + b*x)]/(2*b^2) + Log[a + b*x]/(2*b^2) - (((a - b*x)*Cos[a + b*x] + Sin[a + b*x])*SinIntegral[a + b*x])/b^2 - (1/2)*(a^2/b^2 - x^2)*SinIntegral[a + b*x]^2 + (a*SinIntegral[2*(a + b*x)])/b^2}
{x^2*SinIntegral[a + b*x]^2, x, 42, (2*x)/(3*b^2) - (a*Cos[2*a + 2*b*x])/(3*b^3) + (x*Cos[2*a + 2*b*x])/(6*b^2) + (a*CosIntegral[2*(a + b*x)])/b^3 - (a*Log[a + b*x])/b^3 - (2*Cos[a + b*x]*Sin[a + b*x])/(3*b^3) - Sin[2*a + 2*b*x]/(12*b^3) - (2*((2 - a^2 + a*b*x - b^2*x^2)*Cos[a + b*x] - (a - 2*b*x)*Sin[a + b*x])*SinIntegral[a + b*x])/(3*b^3) + (1/3)*(a^3/b^3 + x^3)*SinIntegral[a + b*x]^2 + ((2 - 3*a^2)*SinIntegral[2*(a + b*x)])/(3*b^3)}
(* {x^3*SinIntegral[a + b*x]^2, x, 77, -((5*a*x)/(4*b^3)) + (3*x^2)/(8*b^2) - (13*Cos[2*a + 2*b*x])/(16*b^4) + (3*a^2*Cos[2*a + 2*b*x])/(8*b^4) - (a*x*Cos[2*a + 2*b*x])/(4*b^3) + (x^2*Cos[2*a + 2*b*x])/(8*b^2) + (3*(1 - a^2)*CosIntegral[2*(a + b*x)])/(2*b^4) - (3*Log[a + b*x])/(2*b^4) + (3*a^2*Log[a + b*x])/(2*b^4) + (5*a*Cos[a + b*x]*Sin[a + b*x])/(4*b^4) - (3*x*Cos[a + b*x]*Sin[a + b*x])/(4*b^3) + (3*Sin[a + b*x]^2)/(8*b^4) + (a*Sin[2*a + 2*b*x])/(8*b^4) - (x*Sin[2*a + 2*b*x])/(8*b^3) + (((2*a - a^3 - 6*b*x + a^2*b*x - a*b^2*x^2 + b^3*x^3)*Cos[a + b*x] + (6 - a^2 + 2*a*b*x - 3*b^2*x^2)*Sin[a + b*x])*SinIntegral[a + b*x])/(2*b^4) - (1/4)*(a^4/b^4 - x^4)*SinIntegral[a + b*x]^2 - (a*(2 - a^2)*SinIntegral[2*(a + b*x)])/b^4} *)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m Trig[b x] SinIntegral[b x]^n*)


{Sin[b*x]*SinIntegral[b*x]/x^3, x, 16, b^2*CosIntegral[2*b*x] - (b*Cos[b*x]*Sin[b*x])/(2*x) - Sin[b*x]^2/(4*x^2) - (b*Sin[2*b*x])/(4*x) - ((b*x*Cos[b*x] + Sin[b*x])*SinIntegral[b*x])/(2*x^2) - (1/4)*b^2*SinIntegral[b*x]^2}
{Sin[b*x]*SinIntegral[b*x]/x^2, x, 7, -(1/(2*x)) + Cos[2*b*x]/(2*x) + b*Int[(Cos[b*x]*SinIntegral[b*x])/x, x] - (Sin[b*x]*SinIntegral[b*x])/x + b*SinIntegral[2*b*x]}
{Sin[b*x]*SinIntegral[b*x]/x, x, 2, (1/2)*SinIntegral[b*x]^2}
{Sin[b*x]*SinIntegral[b*x], x, 5, -((Cos[b*x]*SinIntegral[b*x])/b) + SinIntegral[2*b*x]/(2*b)}
{x*Sin[b*x]*SinIntegral[b*x], x, 10, CosIntegral[2*b*x]/(2*b^2) - Log[x]/(2*b^2) + Sin[b*x]^2/(2*b^2) - ((b*x*Cos[b*x] - Sin[b*x])*SinIntegral[b*x])/b^2}
{x^2*Sin[b*x]*SinIntegral[b*x], x, 12, -((5*x)/(4*b^2)) + (5*Cos[b*x]*Sin[b*x])/(4*b^3) + (x*Sin[b*x]^2)/(2*b^2) + (((2 - b^2*x^2)*Cos[b*x] + 2*b*x*Sin[b*x])*SinIntegral[b*x])/b^3 - SinIntegral[2*b*x]/b^3}
{x^3*Sin[b*x]*SinIntegral[b*x], x, 19, -(x^2/b^2) - (3*CosIntegral[2*b*x])/b^4 + (3*Log[x])/b^4 + (2*x*Cos[b*x]*Sin[b*x])/b^3 - (4*Sin[b*x]^2)/b^4 + (x^2*Sin[b*x]^2)/(2*b^2) + ((b*x*(6 - b^2*x^2)*Cos[b*x] - 3*(2 - b^2*x^2)*Sin[b*x])*SinIntegral[b*x])/b^4}


{Cos[b*x]*SinIntegral[b*x]/x^3, x, 14, b/(4*x) - (b*Cos[2*b*x])/(2*x) - (1/2)*b^2*Int[(Cos[b*x]*SinIntegral[b*x])/x, x] - Sin[2*b*x]/(8*x^2) - ((Cos[b*x] - b*x*Sin[b*x])*SinIntegral[b*x])/(2*x^2) - b^2*SinIntegral[2*b*x]}
{Cos[b*x]*SinIntegral[b*x]/x^2, x, 8, b*CosIntegral[2*b*x] - Sin[2*b*x]/(2*x) - (Cos[b*x]*SinIntegral[b*x])/x - (1/2)*b*SinIntegral[b*x]^2}
{Cos[b*x]*SinIntegral[b*x]/x, x, 0, Int[(Cos[b*x]*SinIntegral[b*x])/x, x]}
{Cos[b*x]*SinIntegral[b*x], x, 6, CosIntegral[2*b*x]/(2*b) - Log[x]/(2*b) + (Sin[b*x]*SinIntegral[b*x])/b}
{x*Cos[b*x]*SinIntegral[b*x], x, 8, -(x/(2*b)) + (Cos[b*x]*Sin[b*x])/(2*b^2) + ((Cos[b*x] + b*x*Sin[b*x])*SinIntegral[b*x])/b^2 - SinIntegral[2*b*x]/(2*b^2)}
{x^2*Cos[b*x]*SinIntegral[b*x], x, 14, -(x^2/(4*b)) - CosIntegral[2*b*x]/b^3 + Log[x]/b^3 + (x*Cos[b*x]*Sin[b*x])/(2*b^2) - (5*Sin[b*x]^2)/(4*b^3) + ((2*b*x*Cos[b*x] - (2 - b^2*x^2)*Sin[b*x])*SinIntegral[b*x])/b^3}
{x^3*Cos[b*x]*SinIntegral[b*x], x, 17, (4*x)/b^3 - x^3/(6*b) - (4*Cos[b*x]*Sin[b*x])/b^4 + (x^2*Cos[b*x]*Sin[b*x])/(2*b^2) - (2*x*Sin[b*x]^2)/b^3 - ((3*(2 - b^2*x^2)*Cos[b*x] + b*x*(6 - b^2*x^2)*Sin[b*x])*SinIntegral[b*x])/b^4 + (3*SinIntegral[2*b*x])/b^4}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m Trig[a+b x] SinIntegral[c+d x]^n*)


(* {Sin[a + b*x]*SinIntegral[c + d*x]/x^3, x, 0, 0} *)
{Sin[a + b*x]*SinIntegral[c + d*x]/x^2, x, 20, (d*Cos[a - c]*CosIntegral[(b - d)*x])/(2*c) - (d*Cos[a + c]*CosIntegral[(b + d)*x])/(2*c) - (d*Cos[a - (b*c)/d]*CosIntegral[((b - d)*(c + d*x))/d])/(2*c) + (d*Cos[a - (b*c)/d]*CosIntegral[((b + d)*(c + d*x))/d])/(2*c) + b*Int[(Cos[a + b*x]*SinIntegral[c + d*x])/x, x] - (d*Sin[a - c]*SinIntegral[(b - d)*x])/(2*c) + (d*Sin[a + c]*SinIntegral[(b + d)*x])/(2*c) - (Sin[a + b*x]*SinIntegral[c + d*x])/x + (d*Sin[a - (b*c)/d]*SinIntegral[((b - d)*(c + d*x))/d])/(2*c) - (d*Sin[a - (b*c)/d]*SinIntegral[((b + d)*(c + d*x))/d])/(2*c)}
{Sin[a + b*x]*SinIntegral[c + d*x]/x, x, 0, Int[(Sin[a + b*x]*SinIntegral[c + d*x])/x, x]}
{Sin[a + b*x]*SinIntegral[c + d*x], x, 11, -((CosIntegral[((b - d)*(c + d*x))/d]*Sin[a - (b*c)/d])/(2*b)) + (CosIntegral[((b + d)*(c + d*x))/d]*Sin[a - (b*c)/d])/(2*b) - (Cos[a + b*x]*SinIntegral[c + d*x])/b - (Cos[a - (b*c)/d]*SinIntegral[((b - d)*(c + d*x))/d])/(2*b) + (Cos[a - (b*c)/d]*SinIntegral[((b + d)*(c + d*x))/d])/(2*b)}
{x*Sin[a + b*x]*SinIntegral[c + d*x], x, 27, Cos[a - c + (b - d)*x]/(2*b*(b - d)) - Cos[a + c + (b + d)*x]/(2*b*(b + d)) - (CosIntegral[((b - d)*(c + d*x))/d]*(d*Cos[a - (b*c)/d] - b*c*Sin[a - (b*c)/d]))/(2*b^2*d) + (CosIntegral[((b + d)*(c + d*x))/d]*(d*Cos[a - (b*c)/d] - b*c*Sin[a - (b*c)/d]))/(2*b^2*d) - ((b*x*Cos[a + b*x] - Sin[a + b*x])*SinIntegral[c + d*x])/b^2 + ((b*c*Cos[a - (b*c)/d] + d*Sin[a - (b*c)/d])*SinIntegral[((b - d)*(c + d*x))/d])/(2*b^2*d) - ((b*c*Cos[a - (b*c)/d] + d*Sin[a - (b*c)/d])*SinIntegral[((b + d)*(c + d*x))/d])/(2*b^2*d)}
(* {x^2*Sin[a + b*x]*SinIntegral[c + d*x], x, 46, -((c*Cos[a - c + (b - d)*x])/(2*b*(b - d)*d)) + (x*Cos[a - c + (b - d)*x])/(2*b*(b - d)) + (c*Cos[a + c + (b + d)*x])/(2*b*d*(b + d)) - (x*Cos[a + c + (b + d)*x])/(2*b*(b + d)) + (CosIntegral[((b - d)*(c + d*x))/d]*(2*b*c*d*Cos[a - (b*c)/d] - (b^2*c^2 - 2*d^2)*Sin[a - (b*c)/d]))/(2*b^3*d^2) - (CosIntegral[((b + d)*(c + d*x))/d]*(2*b*c*d*Cos[a - (b*c)/d] - (b^2*c^2 - 2*d^2)*Sin[a - (b*c)/d]))/(2*b^3*d^2) - Sin[a - c + (b - d)*x]/(2*b*(b - d)^2) - Sin[a - c + (b - d)*x]/(b^2*(b - d)) + Sin[a + c + (b + d)*x]/(2*b*(b + d)^2) + Sin[a + c + (b + d)*x]/(b^2*(b + d)) + (((2 - b^2*x^2)*Cos[a + b*x] + 2*b*x*Sin[a + b*x])*SinIntegral[c + d*x])/b^3 - (((b^2*c^2 - 2*d^2)*Cos[a - (b*c)/d] + 2*b*c*d*Sin[a - (b*c)/d])*SinIntegral[((b - d)*(c + d*x))/d])/(2*b^3*d^2) + (((b^2*c^2 - 2*d^2)*Cos[a - (b*c)/d] + 2*b*c*d*Sin[a - (b*c)/d])*SinIntegral[((b + d)*(c + d*x))/d])/(2*b^3*d^2)} *)
(* {x^3*Sin[a + b*x]*SinIntegral[c + d*x], x, 0, 0} *)


(* {Cos[a + b*x]*SinIntegral[c + d*x]/x^3, x, 0, 0} *)
{Cos[a + b*x]*SinIntegral[c + d*x]/x^2, x, 21, (-b)*Int[(Sin[a + b*x]*SinIntegral[c + d*x])/x, x] - (d*CosIntegral[(b - d)*x]*Sin[a - c])/(2*c) + (d*CosIntegral[(b + d)*x]*Sin[a + c])/(2*c) + (d*CosIntegral[((b - d)*(c + d*x))/d]*Sin[a - (b*c)/d])/(2*c) - (d*CosIntegral[((b + d)*(c + d*x))/d]*Sin[a - (b*c)/d])/(2*c) - (d*Cos[a - c]*SinIntegral[(b - d)*x])/(2*c) + (d*Cos[a + c]*SinIntegral[(b + d)*x])/(2*c) - (Cos[a + b*x]*SinIntegral[c + d*x])/x + (d*Cos[a - (b*c)/d]*SinIntegral[((b - d)*(c + d*x))/d])/(2*c) - (d*Cos[a - (b*c)/d]*SinIntegral[((b + d)*(c + d*x))/d])/(2*c)}
{Cos[a + b*x]*SinIntegral[c + d*x]/x, x, 0, Int[(Cos[a + b*x]*SinIntegral[c + d*x])/x, x]}
{Cos[a + b*x]*SinIntegral[c + d*x], x, 10, -((Cos[a - (b*c)/d]*CosIntegral[((b - d)*(c + d*x))/d])/(2*b)) + (Cos[a - (b*c)/d]*CosIntegral[((b + d)*(c + d*x))/d])/(2*b) + (Sin[a + b*x]*SinIntegral[c + d*x])/b + (Sin[a - (b*c)/d]*SinIntegral[((b - d)*(c + d*x))/d])/(2*b) - (Sin[a - (b*c)/d]*SinIntegral[((b + d)*(c + d*x))/d])/(2*b)}
{x*Cos[a + b*x]*SinIntegral[c + d*x], x, 27, (CosIntegral[((b - d)*(c + d*x))/d]*(b*c*Cos[a - (b*c)/d] + d*Sin[a - (b*c)/d]))/(2*b^2*d) - (CosIntegral[((b + d)*(c + d*x))/d]*(b*c*Cos[a - (b*c)/d] + d*Sin[a - (b*c)/d]))/(2*b^2*d) - Sin[a - c + (b - d)*x]/(2*b*(b - d)) + Sin[a + c + (b + d)*x]/(2*b*(b + d)) + ((Cos[a + b*x] + b*x*Sin[a + b*x])*SinIntegral[c + d*x])/b^2 + ((d*Cos[a - (b*c)/d] - b*c*Sin[a - (b*c)/d])*SinIntegral[((b - d)*(c + d*x))/d])/(2*b^2*d) - ((d*Cos[a - (b*c)/d] - b*c*Sin[a - (b*c)/d])*SinIntegral[((b + d)*(c + d*x))/d])/(2*b^2*d)}
(* {x^2*Cos[a + b*x]*SinIntegral[c + d*x], x, 46, -(Cos[a - c + (b - d)*x]/(2*b*(b - d)^2)) - Cos[a - c + (b - d)*x]/(b^2*(b - d)) + Cos[a + c + (b + d)*x]/(2*b*(b + d)^2) + Cos[a + c + (b + d)*x]/(b^2*(b + d)) - (CosIntegral[((b - d)*(c + d*x))/d]*((b^2*c^2 - 2*d^2)*Cos[a - (b*c)/d] + 2*b*c*d*Sin[a - (b*c)/d]))/(2*b^3*d^2) + (CosIntegral[((b + d)*(c + d*x))/d]*((b^2*c^2 - 2*d^2)*Cos[a - (b*c)/d] + 2*b*c*d*Sin[a - (b*c)/d]))/(2*b^3*d^2) + (c*Sin[a - c + (b - d)*x])/(2*b*(b - d)*d) - (x*Sin[a - c + (b - d)*x])/(2*b*(b - d)) - (c*Sin[a + c + (b + d)*x])/(2*b*d*(b + d)) + (x*Sin[a + c + (b + d)*x])/(2*b*(b + d)) + ((2*b*x*Cos[a + b*x] - (2 - b^2*x^2)*Sin[a + b*x])*SinIntegral[c + d*x])/b^3 - ((2*b*c*d*Cos[a - (b*c)/d] - (b^2*c^2 - 2*d^2)*Sin[a - (b*c)/d])*SinIntegral[((b - d)*(c + d*x))/d])/(2*b^3*d^2) + ((2*b*c*d*Cos[a - (b*c)/d] - (b^2*c^2 - 2*d^2)*Sin[a - (b*c)/d])*SinIntegral[((b + d)*(c + d*x))/d])/(2*b^3*d^2)} *)
(* {x^3*Cos[a + b*x]*SinIntegral[c + d*x], x, 0, 0} *)


(* ::Subsection::Closed:: *)
(*Cosine integral function*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m CosIntegral[b x]^n*)


{CosIntegral[b*x]/x^3, x, 5, -(Cos[b*x]/(4*x^2)) - ((2 + b^2*x^2)*CosIntegral[b*x])/(4*x^2) + (b*Sin[b*x])/(4*x)}
{CosIntegral[b*x]/x^2, x, 4, -(Cos[b*x]/x) - CosIntegral[b*x]/x - b*SinIntegral[b*x]}
{CosIntegral[b*x]/x, x, 0, Int[CosIntegral[b*x]/x, x]}
{CosIntegral[b*x], x, 1, x*CosIntegral[b*x] - Sin[b*x]/b}
{x*CosIntegral[b*x], x, 4, -(Cos[b*x]/(2*b^2)) + (1/2)*x^2*CosIntegral[b*x] - (x*Sin[b*x])/(2*b)}
{x^2*CosIntegral[b*x], x, 5, -((2*x*Cos[b*x])/(3*b^2)) + (1/3)*x^3*CosIntegral[b*x] + (2*Sin[b*x])/(3*b^3) - (x^2*Sin[b*x])/(3*b)}
{x^3*CosIntegral[b*x], x, 6, (3*Cos[b*x])/(2*b^4) - (3*x^2*Cos[b*x])/(4*b^2) + (1/4)*x^4*CosIntegral[b*x] + (3*x*Sin[b*x])/(2*b^3) - (x^3*Sin[b*x])/(4*b)}
{x^m*CosIntegral[b*x], x, 5, (x^(1 + m)*CosIntegral[b*x])/(1 + m) + (x^(1 + m)*((-I)*b*x)^(-1 - m)*Gamma[1 + m, (-I)*b*x])/(2*(1 + m)) + (x^(1 + m)*(I*b*x)^(-1 - m)*Gamma[1 + m, I*b*x])/(2*(1 + m))}


{CosIntegral[b*x]^2/x^3, x, 0, Int[CosIntegral[b*x]^2/x^3, x]}
{CosIntegral[b*x]^2/x^2, x, 0, Int[CosIntegral[b*x]^2/x^2, x]}
{CosIntegral[b*x]^2/x, x, 0, Int[CosIntegral[b*x]^2/x, x]}
{CosIntegral[b*x]^2, x, 6, x*CosIntegral[b*x]^2 - (2*CosIntegral[b*x]*Sin[b*x])/b + SinIntegral[2*b*x]/b}
{x*CosIntegral[b*x]^2, x, 11, (1/2)*x^2*CosIntegral[b*x]^2 + CosIntegral[2*b*x]/(2*b^2) + Log[x]/(2*b^2) + Sin[b*x]^2/(2*b^2) - (CosIntegral[b*x]*(Cos[b*x] + b*x*Sin[b*x]))/b^2}
{x^2*CosIntegral[b*x]^2, x, 13, x/(2*b^2) + (1/3)*x^3*CosIntegral[b*x]^2 + (5*Cos[b*x]*Sin[b*x])/(6*b^3) + (x*Sin[b*x]^2)/(3*b^2) - (2*CosIntegral[b*x]*(2*b*x*Cos[b*x] - (2 - b^2*x^2)*Sin[b*x]))/(3*b^3) - (2*SinIntegral[2*b*x])/(3*b^3)}
{x^3*CosIntegral[b*x]^2, x, 20, x^2/(4*b^2) + (3*Cos[b*x]^2)/(8*b^4) + (1/4)*x^4*CosIntegral[b*x]^2 - (3*CosIntegral[2*b*x])/(2*b^4) - (3*Log[x])/(2*b^4) + (x*Cos[b*x]*Sin[b*x])/b^3 - (13*Sin[b*x]^2)/(8*b^4) + (x^2*Sin[b*x]^2)/(4*b^2) + (CosIntegral[b*x]*(3*(2 - b^2*x^2)*Cos[b*x] + b*x*(6 - b^2*x^2)*Sin[b*x]))/(2*b^4)}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m CosIntegral[a+b x]^n*)


{CosIntegral[a + b*x]/x^3, x, 12, -((b*Cos[a + b*x])/(2*a*x)) + (1/2)*(b^2/a^2 - 1/x^2)*CosIntegral[a + b*x] - (b^2*CosIntegral[b*x]*(Cos[a] + a*Sin[a]))/(2*a^2) - (b^2*(a*Cos[a] - Sin[a])*SinIntegral[b*x])/(2*a^2)}
{CosIntegral[a + b*x]/x^2, x, 8, (b*Cos[a]*CosIntegral[b*x])/a - ((a + b*x)*CosIntegral[a + b*x])/(a*x) - (b*Sin[a]*SinIntegral[b*x])/a}
{CosIntegral[a + b*x]/x, x, 0, Int[CosIntegral[a + b*x]/x, x]}
{CosIntegral[a + b*x], x, 1, ((a + b*x)*CosIntegral[a + b*x])/b - Sin[a + b*x]/b}
{x*CosIntegral[a + b*x], x, 8, -(Cos[a + b*x]/(2*b^2)) - (1/2)*(a^2/b^2 - x^2)*CosIntegral[a + b*x] + (a*Sin[a + b*x])/(2*b^2) - (x*Sin[a + b*x])/(2*b)}
{x^2*CosIntegral[a + b*x], x, 11, (a*Cos[a + b*x])/(3*b^3) - (2*x*Cos[a + b*x])/(3*b^2) + (1/3)*(a^3/b^3 + x^3)*CosIntegral[a + b*x] + (2*Sin[a + b*x])/(3*b^3) - (a^2*Sin[a + b*x])/(3*b^3) + (a*x*Sin[a + b*x])/(3*b^2) - (x^2*Sin[a + b*x])/(3*b)}
{x^3*CosIntegral[a + b*x], x, 15, (3*Cos[a + b*x])/(2*b^4) - (a^2*Cos[a + b*x])/(4*b^4) + (a*x*Cos[a + b*x])/(2*b^3) - (3*x^2*Cos[a + b*x])/(4*b^2) - (1/4)*(a^4/b^4 - x^4)*CosIntegral[a + b*x] - (a*Sin[a + b*x])/(2*b^4) + (a^3*Sin[a + b*x])/(4*b^4) + (3*x*Sin[a + b*x])/(2*b^3) - (a^2*x*Sin[a + b*x])/(4*b^3) + (a*x^2*Sin[a + b*x])/(4*b^2) - (x^3*Sin[a + b*x])/(4*b)}
{x^m*CosIntegral[a + b*x], x, 6, (x^(1 + m)*CosIntegral[a + b*x])/(1 + m) + (E^(I*a)*x^(1 + m)*((-I)*b*x)^(-1 - m)*Gamma[1 + m, (-I)*b*x])/(2*(1 + m)) + (x^(1 + m)*(I*b*x)^(-1 - m)*Gamma[1 + m, I*b*x])/(E^(I*a)*(2*(1 + m))) + (a*Int[(x^m*Cos[a + b*x])/(a + b*x), x])/(1 + m)}


{CosIntegral[a + b*x]^2/x^3, x, 0, Int[CosIntegral[a + b*x]^2/x^3, x]}
{CosIntegral[a + b*x]^2/x^2, x, 0, Int[CosIntegral[a + b*x]^2/x^2, x]}
{CosIntegral[a + b*x]^2/x, x, 0, Int[CosIntegral[a + b*x]^2/x, x]}
{CosIntegral[a + b*x]^2, x, 6, ((a + b*x)*CosIntegral[a + b*x]^2)/b - (2*CosIntegral[a + b*x]*Sin[a + b*x])/b + SinIntegral[2*(a + b*x)]/b}
{x*CosIntegral[a + b*x]^2, x, 19, -(Cos[2*a + 2*b*x]/(4*b^2)) - (1/2)*(a^2/b^2 - x^2)*CosIntegral[a + b*x]^2 + CosIntegral[2*(a + b*x)]/(2*b^2) + Log[a + b*x]/(2*b^2) - (CosIntegral[a + b*x]*(Cos[a + b*x] - (a - b*x)*Sin[a + b*x]))/b^2 - (a*SinIntegral[2*(a + b*x)])/b^2}
{x^2*CosIntegral[a + b*x]^2, x, 42, (2*x)/(3*b^2) + (a*Cos[2*a + 2*b*x])/(3*b^3) - (x*Cos[2*a + 2*b*x])/(6*b^2) + (1/3)*(a^3/b^3 + x^3)*CosIntegral[a + b*x]^2 - (a*CosIntegral[2*(a + b*x)])/b^3 - (a*Log[a + b*x])/b^3 + (2*Cos[a + b*x]*Sin[a + b*x])/(3*b^3) + (2*CosIntegral[a + b*x]*((a - 2*b*x)*Cos[a + b*x] + (2 - a^2 + a*b*x - b^2*x^2)*Sin[a + b*x]))/(3*b^3) + Sin[2*a + 2*b*x]/(12*b^3) - ((2 - 3*a^2)*SinIntegral[2*(a + b*x)])/(3*b^3)}
(* {x^3*CosIntegral[a + b*x]^2, x, 77, -((5*a*x)/(4*b^3)) + (3*x^2)/(8*b^2) + (3*Cos[a + b*x]^2)/(8*b^4) + (13*Cos[2*a + 2*b*x])/(16*b^4) - (3*a^2*Cos[2*a + 2*b*x])/(8*b^4) + (a*x*Cos[2*a + 2*b*x])/(4*b^3) - (x^2*Cos[2*a + 2*b*x])/(8*b^2) - (1/4)*(a^4/b^4 - x^4)*CosIntegral[a + b*x]^2 - (3*(1 - a^2)*CosIntegral[2*(a + b*x)])/(2*b^4) - (3*Log[a + b*x])/(2*b^4) + (3*a^2*Log[a + b*x])/(2*b^4) - (5*a*Cos[a + b*x]*Sin[a + b*x])/(4*b^4) + (3*x*Cos[a + b*x]*Sin[a + b*x])/(4*b^3) + (CosIntegral[a + b*x]*((6 - a^2 + 2*a*b*x - 3*b^2*x^2)*Cos[a + b*x] + (a^3 + 6*b*x - a^2*b*x - b^3*x^3 - a*(2 - b^2*x^2))*Sin[a + b*x]))/(2*b^4) - (a*Sin[2*a + 2*b*x])/(8*b^4) + (x*Sin[2*a + 2*b*x])/(8*b^3) + (a*(2 - a^2)*SinIntegral[2*(a + b*x)])/b^4} *)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m Trig[b x] CosIntegral[b x]^n*)


{Sin[b*x]*CosIntegral[b*x]/x^3, x, 14, -(b/(4*x)) - (b*Cos[2*b*x])/(2*x) - (1/2)*b^2*Int[(CosIntegral[b*x]*Sin[b*x])/x, x] - (CosIntegral[b*x]*(b*x*Cos[b*x] + Sin[b*x]))/(2*x^2) - Sin[2*b*x]/(8*x^2) - b^2*SinIntegral[2*b*x]}
{Sin[b*x]*CosIntegral[b*x]/x^2, x, 8, (1/2)*b*CosIntegral[b*x]^2 + b*CosIntegral[2*b*x] - (CosIntegral[b*x]*Sin[b*x])/x - Sin[2*b*x]/(2*x)}
{Sin[b*x]*CosIntegral[b*x]/x, x, 0, Int[(CosIntegral[b*x]*Sin[b*x])/x, x]}
{Sin[b*x]*CosIntegral[b*x], x, 6, -((Cos[b*x]*CosIntegral[b*x])/b) + CosIntegral[2*b*x]/(2*b) + Log[x]/(2*b)}
{x*Sin[b*x]*CosIntegral[b*x], x, 8, x/(2*b) - (CosIntegral[b*x]*(b*x*Cos[b*x] - Sin[b*x]))/b^2 + (Cos[b*x]*Sin[b*x])/(2*b^2) - SinIntegral[2*b*x]/(2*b^2)}
{x^2*Sin[b*x]*CosIntegral[b*x], x, 14, x^2/(4*b) + Cos[b*x]^2/(4*b^3) - CosIntegral[2*b*x]/b^3 - Log[x]/b^3 + (x*Cos[b*x]*Sin[b*x])/(2*b^2) - Sin[b*x]^2/b^3 + (CosIntegral[b*x]*((2 - b^2*x^2)*Cos[b*x] + 2*b*x*Sin[b*x]))/b^3}
{x^3*Sin[b*x]*CosIntegral[b*x], x, 17, -((5*x)/(2*b^3)) + x^3/(6*b) + (x*Cos[b*x]^2)/(2*b^3) - (4*Cos[b*x]*Sin[b*x])/b^4 + (x^2*Cos[b*x]*Sin[b*x])/(2*b^2) - (3*x*Sin[b*x]^2)/(2*b^3) + (CosIntegral[b*x]*(b*x*(6 - b^2*x^2)*Cos[b*x] - 3*(2 - b^2*x^2)*Sin[b*x]))/b^4 + (3*SinIntegral[2*b*x])/b^4}


{Cos[b*x]*CosIntegral[b*x]/x^3, x, 16, -(Cos[b*x]^2/(4*x^2)) - (1/4)*b^2*CosIntegral[b*x]^2 - b^2*CosIntegral[2*b*x] + (b*Cos[b*x]*Sin[b*x])/(2*x) - (CosIntegral[b*x]*(Cos[b*x] - b*x*Sin[b*x]))/(2*x^2) + (b*Sin[2*b*x])/(4*x)}
{Cos[b*x]*CosIntegral[b*x]/x^2, x, 7, -(1/(2*x)) - Cos[2*b*x]/(2*x) - (Cos[b*x]*CosIntegral[b*x])/x - b*Int[(CosIntegral[b*x]*Sin[b*x])/x, x] - b*SinIntegral[2*b*x]}
{Cos[b*x]*CosIntegral[b*x]/x, x, 2, (1/2)*CosIntegral[b*x]^2}
{Cos[b*x]*CosIntegral[b*x], x, 5, (CosIntegral[b*x]*Sin[b*x])/b - SinIntegral[2*b*x]/(2*b)}
{x*Cos[b*x]*CosIntegral[b*x], x, 10, -(CosIntegral[2*b*x]/(2*b^2)) - Log[x]/(2*b^2) - Sin[b*x]^2/(2*b^2) + (CosIntegral[b*x]*(Cos[b*x] + b*x*Sin[b*x]))/b^2}
{x^2*Cos[b*x]*CosIntegral[b*x], x, 12, -((3*x)/(4*b^2)) - (5*Cos[b*x]*Sin[b*x])/(4*b^3) - (x*Sin[b*x]^2)/(2*b^2) + (CosIntegral[b*x]*(2*b*x*Cos[b*x] - (2 - b^2*x^2)*Sin[b*x]))/b^3 + SinIntegral[2*b*x]/b^3}
{x^3*Cos[b*x]*CosIntegral[b*x], x, 19, -(x^2/(2*b^2)) - (3*Cos[b*x]^2)/(4*b^4) + (3*CosIntegral[2*b*x])/b^4 + (3*Log[x])/b^4 - (2*x*Cos[b*x]*Sin[b*x])/b^3 + (13*Sin[b*x]^2)/(4*b^4) - (x^2*Sin[b*x]^2)/(2*b^2) - (CosIntegral[b*x]*(3*(2 - b^2*x^2)*Cos[b*x] + b*x*(6 - b^2*x^2)*Sin[b*x]))/b^4}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m Trig[a+b x] CosIntegral[c+d x]^n*)


{Cos[5*x]*CosIntegral[2*x], x, 5, (1/5)*CosIntegral[2*x]*Sin[5*x] - (1/10)*SinIntegral[3*x] - (1/10)*SinIntegral[7*x]}


(* {Sin[a + b*x]*CosIntegral[c + d*x]/x^3, x, 0, 0} *)
{Sin[a + b*x]*CosIntegral[c + d*x]/x^2, x, 20, b*Int[(Cos[a + b*x]*CosIntegral[c + d*x])/x, x] + (d*CosIntegral[(b - d)*x]*Sin[a - c])/(2*c) + (d*CosIntegral[(b + d)*x]*Sin[a + c])/(2*c) - (d*CosIntegral[((b - d)*(c + d*x))/d]*Sin[a - (b*c)/d])/(2*c) - (d*CosIntegral[((b + d)*(c + d*x))/d]*Sin[a - (b*c)/d])/(2*c) - (CosIntegral[c + d*x]*Sin[a + b*x])/x + (d*Cos[a - c]*SinIntegral[(b - d)*x])/(2*c) + (d*Cos[a + c]*SinIntegral[(b + d)*x])/(2*c) - (d*Cos[a - (b*c)/d]*SinIntegral[((b - d)*(c + d*x))/d])/(2*c) - (d*Cos[a - (b*c)/d]*SinIntegral[((b + d)*(c + d*x))/d])/(2*c)}
{Sin[a + b*x]*CosIntegral[c + d*x]/x, x, 0, Int[(CosIntegral[c + d*x]*Sin[a + b*x])/x, x]}
{Sin[a + b*x]*CosIntegral[c + d*x], x, 10, -((Cos[a + b*x]*CosIntegral[c + d*x])/b) + (Cos[a - (b*c)/d]*CosIntegral[((b - d)*(c + d*x))/d])/(2*b) + (Cos[a - (b*c)/d]*CosIntegral[((b + d)*(c + d*x))/d])/(2*b) - (Sin[a - (b*c)/d]*SinIntegral[((b - d)*(c + d*x))/d])/(2*b) - (Sin[a - (b*c)/d]*SinIntegral[((b + d)*(c + d*x))/d])/(2*b)}
{x*Sin[a + b*x]*CosIntegral[c + d*x], x, 26, -((CosIntegral[((b - d)*(c + d*x))/d]*(b*c*Cos[a - (b*c)/d] + d*Sin[a - (b*c)/d]))/(2*b^2*d)) - (CosIntegral[((b + d)*(c + d*x))/d]*(b*c*Cos[a - (b*c)/d] + d*Sin[a - (b*c)/d]))/(2*b^2*d) - (CosIntegral[c + d*x]*(b*x*Cos[a + b*x] - Sin[a + b*x]))/b^2 + Sin[a - c + (b - d)*x]/(2*b*(b - d)) + Sin[a + c + (b + d)*x]/(2*b*(b + d)) - ((d*Cos[a - (b*c)/d] - b*c*Sin[a - (b*c)/d])*SinIntegral[((b - d)*(c + d*x))/d])/(2*b^2*d) - ((d*Cos[a - (b*c)/d] - b*c*Sin[a - (b*c)/d])*SinIntegral[((b + d)*(c + d*x))/d])/(2*b^2*d)}
(* {x^2*Sin[a + b*x]*CosIntegral[c + d*x], x, 46, Cos[a - c + (b - d)*x]/(2*b*(b - d)^2) + Cos[a - c + (b - d)*x]/(b^2*(b - d)) + Cos[a + c + (b + d)*x]/(2*b*(b + d)^2) + Cos[a + c + (b + d)*x]/(b^2*(b + d)) + (CosIntegral[((b - d)*(c + d*x))/d]*((b^2*c^2 - 2*d^2)*Cos[a - (b*c)/d] + 2*b*c*d*Sin[a - (b*c)/d]))/(2*b^3*d^2) + (CosIntegral[((b + d)*(c + d*x))/d]*((b^2*c^2 - 2*d^2)*Cos[a - (b*c)/d] + 2*b*c*d*Sin[a - (b*c)/d]))/(2*b^3*d^2) + (CosIntegral[c + d*x]*((2 - b^2*x^2)*Cos[a + b*x] + 2*b*x*Sin[a + b*x]))/b^3 - (c*Sin[a - c + (b - d)*x])/(2*b*(b - d)*d) + (x*Sin[a - c + (b - d)*x])/(2*b*(b - d)) - (c*Sin[a + c + (b + d)*x])/(2*b*d*(b + d)) + (x*Sin[a + c + (b + d)*x])/(2*b*(b + d)) + ((2*b*c*d*Cos[a - (b*c)/d] - (b^2*c^2 - 2*d^2)*Sin[a - (b*c)/d])*SinIntegral[((b - d)*(c + d*x))/d])/(2*b^3*d^2) + ((2*b*c*d*Cos[a - (b*c)/d] - (b^2*c^2 - 2*d^2)*Sin[a - (b*c)/d])*SinIntegral[((b + d)*(c + d*x))/d])/(2*b^3*d^2)} *)
(* {x^3*Sin[a + b*x]*CosIntegral[c + d*x], x, 0, 0} *)


(* {Cos[a + b*x]*CosIntegral[c + d*x]/x^3, x, 0, 0} *)
{Cos[a + b*x]*CosIntegral[c + d*x]/x^2, x, 20, (d*Cos[a - c]*CosIntegral[(b - d)*x])/(2*c) + (d*Cos[a + c]*CosIntegral[(b + d)*x])/(2*c) - (Cos[a + b*x]*CosIntegral[c + d*x])/x - (d*Cos[a - (b*c)/d]*CosIntegral[((b - d)*(c + d*x))/d])/(2*c) - (d*Cos[a - (b*c)/d]*CosIntegral[((b + d)*(c + d*x))/d])/(2*c) - b*Int[(CosIntegral[c + d*x]*Sin[a + b*x])/x, x] - (d*Sin[a - c]*SinIntegral[(b - d)*x])/(2*c) - (d*Sin[a + c]*SinIntegral[(b + d)*x])/(2*c) + (d*Sin[a - (b*c)/d]*SinIntegral[((b - d)*(c + d*x))/d])/(2*c) + (d*Sin[a - (b*c)/d]*SinIntegral[((b + d)*(c + d*x))/d])/(2*c)}
{Cos[a + b*x]*CosIntegral[c + d*x]/x, x, 0, Int[(Cos[a + b*x]*CosIntegral[c + d*x])/x, x]}
{Cos[a + b*x]*CosIntegral[c + d*x], x, 10, -((CosIntegral[((b - d)*(c + d*x))/d]*Sin[a - (b*c)/d])/(2*b)) - (CosIntegral[((b + d)*(c + d*x))/d]*Sin[a - (b*c)/d])/(2*b) + (CosIntegral[c + d*x]*Sin[a + b*x])/b - (Cos[a - (b*c)/d]*SinIntegral[((b - d)*(c + d*x))/d])/(2*b) - (Cos[a - (b*c)/d]*SinIntegral[((b + d)*(c + d*x))/d])/(2*b)}
{x*Cos[a + b*x]*CosIntegral[c + d*x], x, 26, Cos[a - c + (b - d)*x]/(2*b*(b - d)) + Cos[a + c + (b + d)*x]/(2*b*(b + d)) - (CosIntegral[((b - d)*(c + d*x))/d]*(d*Cos[a - (b*c)/d] - b*c*Sin[a - (b*c)/d]))/(2*b^2*d) - (CosIntegral[((b + d)*(c + d*x))/d]*(d*Cos[a - (b*c)/d] - b*c*Sin[a - (b*c)/d]))/(2*b^2*d) + (CosIntegral[c + d*x]*(Cos[a + b*x] + b*x*Sin[a + b*x]))/b^2 + ((b*c*Cos[a - (b*c)/d] + d*Sin[a - (b*c)/d])*SinIntegral[((b - d)*(c + d*x))/d])/(2*b^2*d) + ((b*c*Cos[a - (b*c)/d] + d*Sin[a - (b*c)/d])*SinIntegral[((b + d)*(c + d*x))/d])/(2*b^2*d)}
(* {x^2*Cos[a + b*x]*CosIntegral[c + d*x], x, 46, -((c*Cos[a - c + (b - d)*x])/(2*b*(b - d)*d)) + (x*Cos[a - c + (b - d)*x])/(2*b*(b - d)) - (c*Cos[a + c + (b + d)*x])/(2*b*d*(b + d)) + (x*Cos[a + c + (b + d)*x])/(2*b*(b + d)) + (CosIntegral[((b - d)*(c + d*x))/d]*(2*b*c*d*Cos[a - (b*c)/d] - (b^2*c^2 - 2*d^2)*Sin[a - (b*c)/d]))/(2*b^3*d^2) + (CosIntegral[((b + d)*(c + d*x))/d]*(2*b*c*d*Cos[a - (b*c)/d] - (b^2*c^2 - 2*d^2)*Sin[a - (b*c)/d]))/(2*b^3*d^2) + (CosIntegral[c + d*x]*(2*b*x*Cos[a + b*x] - (2 - b^2*x^2)*Sin[a + b*x]))/b^3 - Sin[a - c + (b - d)*x]/(2*b*(b - d)^2) - Sin[a - c + (b - d)*x]/(b^2*(b - d)) - Sin[a + c + (b + d)*x]/(2*b*(b + d)^2) - Sin[a + c + (b + d)*x]/(b^2*(b + d)) - (((b^2*c^2 - 2*d^2)*Cos[a - (b*c)/d] + 2*b*c*d*Sin[a - (b*c)/d])*SinIntegral[((b - d)*(c + d*x))/d])/(2*b^3*d^2) - (((b^2*c^2 - 2*d^2)*Cos[a - (b*c)/d] + 2*b*c*d*Sin[a - (b*c)/d])*SinIntegral[((b + d)*(c + d*x))/d])/(2*b^3*d^2)} *)
(* {x^3*Cos[a + b*x]*CosIntegral[c + d*x], x, 0, 0} *)
