(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Hyperbolic Integral Functions*)


(* ::Subsection::Closed:: *)
(*Hyperbolic sine integral function*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m SinhIntegral[b x]^n*)


{SinhIntegral[b*x]/x^3, x, 5, -((b*Cosh[b*x])/(4*x)) - Sinh[b*x]/(4*x^2) + (1/4)*(b^2 - 2/x^2)*SinhIntegral[b*x]}
{SinhIntegral[b*x]/x^2, x, 4, b*CoshIntegral[b*x] - Sinh[b*x]/x - SinhIntegral[b*x]/x}
{SinhIntegral[b*x]/x, x, 0, Int[SinhIntegral[b*x]/x, x]}
{SinhIntegral[b*x], x, 1, -(Cosh[b*x]/b) + x*SinhIntegral[b*x]}
{x*SinhIntegral[b*x], x, 4, -((x*Cosh[b*x])/(2*b)) + Sinh[b*x]/(2*b^2) + (1/2)*x^2*SinhIntegral[b*x]}
{x^2*SinhIntegral[b*x], x, 5, -((2*Cosh[b*x])/(3*b^3)) - (x^2*Cosh[b*x])/(3*b) + (2*x*Sinh[b*x])/(3*b^2) + (1/3)*x^3*SinhIntegral[b*x]}
{x^3*SinhIntegral[b*x], x, 6, -((3*x*Cosh[b*x])/(2*b^3)) - (x^3*Cosh[b*x])/(4*b) + (3*Sinh[b*x])/(2*b^4) + (3*x^2*Sinh[b*x])/(4*b^2) + (1/4)*x^4*SinhIntegral[b*x]}
{x^m*SinhIntegral[b*x], x, 5, (x^(1 + m)*((-b)*x)^(-1 - m)*Gamma[1 + m, (-b)*x])/(2*(1 + m)) - (x^(1 + m)*(b*x)^(-1 - m)*Gamma[1 + m, b*x])/(2*(1 + m)) + (x^(1 + m)*SinhIntegral[b*x])/(1 + m)}


{SinhIntegral[b*x]^2/x^3, x, 0, Int[SinhIntegral[b*x]^2/x^3, x]}
{SinhIntegral[b*x]^2/x^2, x, 0, Int[SinhIntegral[b*x]^2/x^2, x]}
{SinhIntegral[b*x]^2/x, x, 0, Int[SinhIntegral[b*x]^2/x, x]}
{SinhIntegral[b*x]^2, x, 6, -((2*Cosh[b*x]*SinhIntegral[b*x])/b) + x*SinhIntegral[b*x]^2 + SinhIntegral[2*b*x]/b}
{x*SinhIntegral[b*x]^2, x, 11, -(CoshIntegral[2*b*x]/(2*b^2)) + Log[x]/(2*b^2) + Sinh[b*x]^2/(2*b^2) - ((b*x*Cosh[b*x] - Sinh[b*x])*SinhIntegral[b*x])/b^2 + (1/2)*x^2*SinhIntegral[b*x]^2}
{x^2*SinhIntegral[b*x]^2, x, 13, (5*x)/(6*b^2) - (5*Cosh[b*x]*Sinh[b*x])/(6*b^3) + (x*Sinh[b*x]^2)/(3*b^2) - (2*((2 + b^2*x^2)*Cosh[b*x] - 2*b*x*Sinh[b*x])*SinhIntegral[b*x])/(3*b^3) + (1/3)*x^3*SinhIntegral[b*x]^2 + (2*SinhIntegral[2*b*x])/(3*b^3)}
{x^3*SinhIntegral[b*x]^2, x, 20, x^2/(2*b^2) - (3*CoshIntegral[2*b*x])/(2*b^4) + (3*Log[x])/(2*b^4) - (x*Cosh[b*x]*Sinh[b*x])/b^3 + (2*Sinh[b*x]^2)/b^4 + (x^2*Sinh[b*x]^2)/(4*b^2) - ((b*x*(6 + b^2*x^2)*Cosh[b*x] - 3*(2 + b^2*x^2)*Sinh[b*x])*SinhIntegral[b*x])/(2*b^4) + (1/4)*x^4*SinhIntegral[b*x]^2}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m SinhIntegral[a+b x]^n*)


{SinhIntegral[a + b*x]/x^3, x, 12, (b^2*CoshIntegral[b*x]*(a*Cosh[a] - Sinh[a]))/(2*a^2) - (b*Sinh[a + b*x])/(2*a*x) - (b^2*(Cosh[a] - a*Sinh[a])*SinhIntegral[b*x])/(2*a^2) + (1/2)*(b^2/a^2 - 1/x^2)*SinhIntegral[a + b*x]}
{SinhIntegral[a + b*x]/x^2, x, 8, (b*CoshIntegral[b*x]*Sinh[a])/a + (b*Cosh[a]*SinhIntegral[b*x])/a - ((a + b*x)*SinhIntegral[a + b*x])/(a*x)}
{SinhIntegral[a + b*x]/x, x, 0, Int[SinhIntegral[a + b*x]/x, x]}
{SinhIntegral[a + b*x], x, 1, -(Cosh[a + b*x]/b) + ((a + b*x)*SinhIntegral[a + b*x])/b}
{x*SinhIntegral[a + b*x], x, 8, (a*Cosh[a + b*x])/(2*b^2) - (x*Cosh[a + b*x])/(2*b) + Sinh[a + b*x]/(2*b^2) - (1/2)*(a^2/b^2 - x^2)*SinhIntegral[a + b*x]}
{x^2*SinhIntegral[a + b*x], x, 11, -((2*Cosh[a + b*x])/(3*b^3)) - (a^2*Cosh[a + b*x])/(3*b^3) + (a*x*Cosh[a + b*x])/(3*b^2) - (x^2*Cosh[a + b*x])/(3*b) - (a*Sinh[a + b*x])/(3*b^3) + (2*x*Sinh[a + b*x])/(3*b^2) + (1/3)*(a^3/b^3 + x^3)*SinhIntegral[a + b*x]}
{x^3*SinhIntegral[a + b*x], x, 15, (a*Cosh[a + b*x])/(2*b^4) + (a^3*Cosh[a + b*x])/(4*b^4) - (3*x*Cosh[a + b*x])/(2*b^3) - (a^2*x*Cosh[a + b*x])/(4*b^3) + (a*x^2*Cosh[a + b*x])/(4*b^2) - (x^3*Cosh[a + b*x])/(4*b) + (3*Sinh[a + b*x])/(2*b^4) + (a^2*Sinh[a + b*x])/(4*b^4) - (a*x*Sinh[a + b*x])/(2*b^3) + (3*x^2*Sinh[a + b*x])/(4*b^2) - (1/4)*(a^4/b^4 - x^4)*SinhIntegral[a + b*x]}
{x^m*SinhIntegral[a + b*x], x, 6, (E^a*x^(1 + m)*((-b)*x)^(-1 - m)*Gamma[1 + m, (-b)*x])/(2*(1 + m)) - (x^(1 + m)*(b*x)^(-1 - m)*Gamma[1 + m, b*x])/(E^a*(2*(1 + m))) + (a*Int[(x^m*Sinh[a + b*x])/(a + b*x), x])/(1 + m) + (x^(1 + m)*SinhIntegral[a + b*x])/(1 + m)}


{SinhIntegral[a + b*x]^2/x^3, x, 0, Int[SinhIntegral[a + b*x]^2/x^3, x]}
{SinhIntegral[a + b*x]^2/x^2, x, 0, Int[SinhIntegral[a + b*x]^2/x^2, x]}
{SinhIntegral[a + b*x]^2/x, x, 0, Int[SinhIntegral[a + b*x]^2/x, x]}
{SinhIntegral[a + b*x]^2, x, 6, -((2*Cosh[a + b*x]*SinhIntegral[a + b*x])/b) + ((a + b*x)*SinhIntegral[a + b*x]^2)/b + SinhIntegral[2*(a + b*x)]/b}
{x*SinhIntegral[a + b*x]^2, x, 19, Cosh[2*a + 2*b*x]/(4*b^2) - CoshIntegral[2*(a + b*x)]/(2*b^2) + Log[a + b*x]/(2*b^2) + (((a - b*x)*Cosh[a + b*x] + Sinh[a + b*x])*SinhIntegral[a + b*x])/b^2 - (1/2)*(a^2/b^2 - x^2)*SinhIntegral[a + b*x]^2 - (a*SinhIntegral[2*(a + b*x)])/b^2}
{x^2*SinhIntegral[a + b*x]^2, x, 42, (2*x)/(3*b^2) - (a*Cosh[2*a + 2*b*x])/(3*b^3) + (x*Cosh[2*a + 2*b*x])/(6*b^2) + (a*CoshIntegral[2*(a + b*x)])/b^3 - (a*Log[a + b*x])/b^3 - (2*Cosh[a + b*x]*Sinh[a + b*x])/(3*b^3) - Sinh[2*a + 2*b*x]/(12*b^3) - (2*((2 + a^2 - a*b*x + b^2*x^2)*Cosh[a + b*x] + (a - 2*b*x)*Sinh[a + b*x])*SinhIntegral[a + b*x])/(3*b^3) + (1/3)*(a^3/b^3 + x^3)*SinhIntegral[a + b*x]^2 + ((2 + 3*a^2)*SinhIntegral[2*(a + b*x)])/(3*b^3)}
(* {x^3*SinhIntegral[a + b*x]^2, x, 77, -((5*a*x)/(4*b^3)) + (3*x^2)/(8*b^2) + (13*Cosh[2*a + 2*b*x])/(16*b^4) + (3*a^2*Cosh[2*a + 2*b*x])/(8*b^4) - (a*x*Cosh[2*a + 2*b*x])/(4*b^3) + (x^2*Cosh[2*a + 2*b*x])/(8*b^2) - (3*(1 + a^2)*CoshIntegral[2*(a + b*x)])/(2*b^4) + (3*Log[a + b*x])/(2*b^4) + (3*a^2*Log[a + b*x])/(2*b^4) + (5*a*Cosh[a + b*x]*Sinh[a + b*x])/(4*b^4) - (3*x*Cosh[a + b*x]*Sinh[a + b*x])/(4*b^3) + (3*Sinh[a + b*x]^2)/(8*b^4) + (a*Sinh[2*a + 2*b*x])/(8*b^4) - (x*Sinh[2*a + 2*b*x])/(8*b^3) + (((a^3 - a^2*b*x + a*(2 + b^2*x^2) - b*x*(6 + b^2*x^2))*Cosh[a + b*x] + (6 + a^2 - 2*a*b*x + 3*b^2*x^2)*Sinh[a + b*x])*SinhIntegral[a + b*x])/(2*b^4) - (1/4)*(a^4/b^4 - x^4)*SinhIntegral[a + b*x]^2 - (a*(2 + a^2)*SinhIntegral[2*(a + b*x)])/b^4} *)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m Hyper[b x] SinhIntegral[b x]^n*)


{Sinh[b*x]*SinhIntegral[b*x]/x^3, x, 16, b^2*CoshIntegral[2*b*x] - (b*Cosh[b*x]*Sinh[b*x])/(2*x) - Sinh[b*x]^2/(4*x^2) - (b*Sinh[2*b*x])/(4*x) - ((b*x*Cosh[b*x] + Sinh[b*x])*SinhIntegral[b*x])/(2*x^2) + (1/4)*b^2*SinhIntegral[b*x]^2}
{Sinh[b*x]*SinhIntegral[b*x]/x^2, x, 7, 1/(2*x) - Cosh[2*b*x]/(2*x) + b*Int[(Cosh[b*x]*SinhIntegral[b*x])/x, x] - (Sinh[b*x]*SinhIntegral[b*x])/x + b*SinhIntegral[2*b*x]}
{Sinh[b*x]*SinhIntegral[b*x]/x, x, 2, (1/2)*SinhIntegral[b*x]^2}
{Sinh[b*x]*SinhIntegral[b*x], x, 5, (Cosh[b*x]*SinhIntegral[b*x])/b - SinhIntegral[2*b*x]/(2*b)}
{x*Sinh[b*x]*SinhIntegral[b*x], x, 10, CoshIntegral[2*b*x]/(2*b^2) - Log[x]/(2*b^2) - Sinh[b*x]^2/(2*b^2) + ((b*x*Cosh[b*x] - Sinh[b*x])*SinhIntegral[b*x])/b^2}
{x^2*Sinh[b*x]*SinhIntegral[b*x], x, 12, -((5*x)/(4*b^2)) + (5*Cosh[b*x]*Sinh[b*x])/(4*b^3) - (x*Sinh[b*x]^2)/(2*b^2) + (((2 + b^2*x^2)*Cosh[b*x] - 2*b*x*Sinh[b*x])*SinhIntegral[b*x])/b^3 - SinhIntegral[2*b*x]/b^3}
{x^3*Sinh[b*x]*SinhIntegral[b*x], x, 19, -(x^2/b^2) + (3*CoshIntegral[2*b*x])/b^4 - (3*Log[x])/b^4 + (2*x*Cosh[b*x]*Sinh[b*x])/b^3 - (4*Sinh[b*x]^2)/b^4 - (x^2*Sinh[b*x]^2)/(2*b^2) + ((b*x*(6 + b^2*x^2)*Cosh[b*x] - 3*(2 + b^2*x^2)*Sinh[b*x])*SinhIntegral[b*x])/b^4}


{Cosh[b*x]*SinhIntegral[b*x]/x^3, x, 14, b/(4*x) - (b*Cosh[2*b*x])/(2*x) + (1/2)*b^2*Int[(Cosh[b*x]*SinhIntegral[b*x])/x, x] - Sinh[2*b*x]/(8*x^2) - ((Cosh[b*x] + b*x*Sinh[b*x])*SinhIntegral[b*x])/(2*x^2) + b^2*SinhIntegral[2*b*x]}
{Cosh[b*x]*SinhIntegral[b*x]/x^2, x, 8, b*CoshIntegral[2*b*x] - Sinh[2*b*x]/(2*x) - (Cosh[b*x]*SinhIntegral[b*x])/x + (1/2)*b*SinhIntegral[b*x]^2}
{Cosh[b*x]*SinhIntegral[b*x]/x, x, 0, Int[(Cosh[b*x]*SinhIntegral[b*x])/x, x]}
{Cosh[b*x]*SinhIntegral[b*x], x, 6, -(CoshIntegral[2*b*x]/(2*b)) + Log[x]/(2*b) + (Sinh[b*x]*SinhIntegral[b*x])/b}
{x*Cosh[b*x]*SinhIntegral[b*x], x, 8, x/(2*b) - (Cosh[b*x]*Sinh[b*x])/(2*b^2) - ((Cosh[b*x] - b*x*Sinh[b*x])*SinhIntegral[b*x])/b^2 + SinhIntegral[2*b*x]/(2*b^2)}
{x^2*Cosh[b*x]*SinhIntegral[b*x], x, 14, x^2/(4*b) - CoshIntegral[2*b*x]/b^3 + Log[x]/b^3 - (x*Cosh[b*x]*Sinh[b*x])/(2*b^2) + (5*Sinh[b*x]^2)/(4*b^3) - ((2*b*x*Cosh[b*x] - (2 + b^2*x^2)*Sinh[b*x])*SinhIntegral[b*x])/b^3}
{x^3*Cosh[b*x]*SinhIntegral[b*x], x, 17, (4*x)/b^3 + x^3/(6*b) - (4*Cosh[b*x]*Sinh[b*x])/b^4 - (x^2*Cosh[b*x]*Sinh[b*x])/(2*b^2) + (2*x*Sinh[b*x]^2)/b^3 - ((3*(2 + b^2*x^2)*Cosh[b*x] - b*x*(6 + b^2*x^2)*Sinh[b*x])*SinhIntegral[b*x])/b^4 + (3*SinhIntegral[2*b*x])/b^4}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m Hyper[a+b x] SinhIntegral[c+d x]^n*)


(* {Sinh[a + b*x]*SinhIntegral[c + d*x]/x^3, x, 0, 0} *)
{Sinh[a + b*x]*SinhIntegral[c + d*x]/x^2, x, 20, -((d*Cosh[a - c]*CoshIntegral[(b - d)*x])/(2*c)) + (d*Cosh[a + c]*CoshIntegral[(b + d)*x])/(2*c) + (d*Cosh[a - (b*c)/d]*CoshIntegral[((b - d)*(c + d*x))/d])/(2*c) - (d*Cosh[a - (b*c)/d]*CoshIntegral[((b + d)*(c + d*x))/d])/(2*c) + b*Int[(Cosh[a + b*x]*SinhIntegral[c + d*x])/x, x] - (d*Sinh[a - c]*SinhIntegral[(b - d)*x])/(2*c) + (d*Sinh[a + c]*SinhIntegral[(b + d)*x])/(2*c) - (Sinh[a + b*x]*SinhIntegral[c + d*x])/x + (d*Sinh[a - (b*c)/d]*SinhIntegral[((b - d)*(c + d*x))/d])/(2*c) - (d*Sinh[a - (b*c)/d]*SinhIntegral[((b + d)*(c + d*x))/d])/(2*c)}
{Sinh[a + b*x]*SinhIntegral[c + d*x]/x, x, 0, Int[(Sinh[a + b*x]*SinhIntegral[c + d*x])/x, x]}
{Sinh[a + b*x]*SinhIntegral[c + d*x], x, 11, (CoshIntegral[((b - d)*(c + d*x))/d]*Sinh[a - (b*c)/d])/(2*b) - (CoshIntegral[((b + d)*(c + d*x))/d]*Sinh[a - (b*c)/d])/(2*b) + (Cosh[a + b*x]*SinhIntegral[c + d*x])/b + (Cosh[a - (b*c)/d]*SinhIntegral[((b - d)*(c + d*x))/d])/(2*b) - (Cosh[a - (b*c)/d]*SinhIntegral[((b + d)*(c + d*x))/d])/(2*b)}
{x*Sinh[a + b*x]*SinhIntegral[c + d*x], x, 27, Cosh[a - c + (b - d)*x]/(2*b*(b - d)) - Cosh[a + c + (b + d)*x]/(2*b*(b + d)) - (CoshIntegral[((b - d)*(c + d*x))/d]*(d*Cosh[a - (b*c)/d] + b*c*Sinh[a - (b*c)/d]))/(2*b^2*d) + (CoshIntegral[((b + d)*(c + d*x))/d]*(d*Cosh[a - (b*c)/d] + b*c*Sinh[a - (b*c)/d]))/(2*b^2*d) + ((b*x*Cosh[a + b*x] - Sinh[a + b*x])*SinhIntegral[c + d*x])/b^2 - ((b*c*Cosh[a - (b*c)/d] + d*Sinh[a - (b*c)/d])*SinhIntegral[((b - d)*(c + d*x))/d])/(2*b^2*d) + ((b*c*Cosh[a - (b*c)/d] + d*Sinh[a - (b*c)/d])*SinhIntegral[((b + d)*(c + d*x))/d])/(2*b^2*d)}
(* {x^2*Sinh[a + b*x]*SinhIntegral[c + d*x], x, 46, -((c*Cosh[a - c + (b - d)*x])/(2*b*(b - d)*d)) + (x*Cosh[a - c + (b - d)*x])/(2*b*(b - d)) + (c*Cosh[a + c + (b + d)*x])/(2*b*d*(b + d)) - (x*Cosh[a + c + (b + d)*x])/(2*b*(b + d)) + (CoshIntegral[((b - d)*(c + d*x))/d]*(2*b*c*d*Cosh[a - (b*c)/d] + (b^2*c^2 + 2*d^2)*Sinh[a - (b*c)/d]))/(2*b^3*d^2) - (CoshIntegral[((b + d)*(c + d*x))/d]*(2*b*c*d*Cosh[a - (b*c)/d] + (b^2*c^2 + 2*d^2)*Sinh[a - (b*c)/d]))/(2*b^3*d^2) - Sinh[a - c + (b - d)*x]/(2*b*(b - d)^2) - Sinh[a - c + (b - d)*x]/(b^2*(b - d)) + Sinh[a + c + (b + d)*x]/(2*b*(b + d)^2) + Sinh[a + c + (b + d)*x]/(b^2*(b + d)) + (((2 + b^2*x^2)*Cosh[a + b*x] - 2*b*x*Sinh[a + b*x])*SinhIntegral[c + d*x])/b^3 + (((b^2*c^2 + 2*d^2)*Cosh[a - (b*c)/d] + 2*b*c*d*Sinh[a - (b*c)/d])*SinhIntegral[((b - d)*(c + d*x))/d])/(2*b^3*d^2) - (((b^2*c^2 + 2*d^2)*Cosh[a - (b*c)/d] + 2*b*c*d*Sinh[a - (b*c)/d])*SinhIntegral[((b + d)*(c + d*x))/d])/(2*b^3*d^2)} *)
(* {x^3*Sinh[a + b*x]*SinhIntegral[c + d*x], x, 0, 0} *)


(* {Cosh[a + b*x]*SinhIntegral[c + d*x]/x^3, x, 0, 0} *)
{Cosh[a + b*x]*SinhIntegral[c + d*x]/x^2, x, 21, b*Int[(Sinh[a + b*x]*SinhIntegral[c + d*x])/x, x] - (d*CoshIntegral[(b - d)*x]*Sinh[a - c])/(2*c) + (d*CoshIntegral[(b + d)*x]*Sinh[a + c])/(2*c) + (d*CoshIntegral[((b - d)*(c + d*x))/d]*Sinh[a - (b*c)/d])/(2*c) - (d*CoshIntegral[((b + d)*(c + d*x))/d]*Sinh[a - (b*c)/d])/(2*c) - (d*Cosh[a - c]*SinhIntegral[(b - d)*x])/(2*c) + (d*Cosh[a + c]*SinhIntegral[(b + d)*x])/(2*c) - (Cosh[a + b*x]*SinhIntegral[c + d*x])/x + (d*Cosh[a - (b*c)/d]*SinhIntegral[((b - d)*(c + d*x))/d])/(2*c) - (d*Cosh[a - (b*c)/d]*SinhIntegral[((b + d)*(c + d*x))/d])/(2*c)}
{Cosh[a + b*x]*SinhIntegral[c + d*x]/x, x, 0, Int[(Cosh[a + b*x]*SinhIntegral[c + d*x])/x, x]}
{Cosh[a + b*x]*SinhIntegral[c + d*x], x, 10, (Cosh[a - (b*c)/d]*CoshIntegral[((b - d)*(c + d*x))/d])/(2*b) - (Cosh[a - (b*c)/d]*CoshIntegral[((b + d)*(c + d*x))/d])/(2*b) + (Sinh[a + b*x]*SinhIntegral[c + d*x])/b + (Sinh[a - (b*c)/d]*SinhIntegral[((b - d)*(c + d*x))/d])/(2*b) - (Sinh[a - (b*c)/d]*SinhIntegral[((b + d)*(c + d*x))/d])/(2*b)}
{x*Cosh[a + b*x]*SinhIntegral[c + d*x], x, 27, -((CoshIntegral[((b - d)*(c + d*x))/d]*(b*c*Cosh[a - (b*c)/d] + d*Sinh[a - (b*c)/d]))/(2*b^2*d)) + (CoshIntegral[((b + d)*(c + d*x))/d]*(b*c*Cosh[a - (b*c)/d] + d*Sinh[a - (b*c)/d]))/(2*b^2*d) + Sinh[a - c + (b - d)*x]/(2*b*(b - d)) - Sinh[a + c + (b + d)*x]/(2*b*(b + d)) - ((Cosh[a + b*x] - b*x*Sinh[a + b*x])*SinhIntegral[c + d*x])/b^2 - ((d*Cosh[a - (b*c)/d] + b*c*Sinh[a - (b*c)/d])*SinhIntegral[((b - d)*(c + d*x))/d])/(2*b^2*d) + ((d*Cosh[a - (b*c)/d] + b*c*Sinh[a - (b*c)/d])*SinhIntegral[((b + d)*(c + d*x))/d])/(2*b^2*d)}
(* {x^2*Cosh[a + b*x]*SinhIntegral[c + d*x], x, 46, -(Cosh[a - c + (b - d)*x]/(2*b*(b - d)^2)) - Cosh[a - c + (b - d)*x]/(b^2*(b - d)) + Cosh[a + c + (b + d)*x]/(2*b*(b + d)^2) + Cosh[a + c + (b + d)*x]/(b^2*(b + d)) + (CoshIntegral[((b - d)*(c + d*x))/d]*((b^2*c^2 + 2*d^2)*Cosh[a - (b*c)/d] + 2*b*c*d*Sinh[a - (b*c)/d]))/(2*b^3*d^2) - (CoshIntegral[((b + d)*(c + d*x))/d]*((b^2*c^2 + 2*d^2)*Cosh[a - (b*c)/d] + 2*b*c*d*Sinh[a - (b*c)/d]))/(2*b^3*d^2) - (c*Sinh[a - c + (b - d)*x])/(2*b*(b - d)*d) + (x*Sinh[a - c + (b - d)*x])/(2*b*(b - d)) + (c*Sinh[a + c + (b + d)*x])/(2*b*d*(b + d)) - (x*Sinh[a + c + (b + d)*x])/(2*b*(b + d)) - ((2*b*x*Cosh[a + b*x] - (2 + b^2*x^2)*Sinh[a + b*x])*SinhIntegral[c + d*x])/b^3 + ((2*b*c*d*Cosh[a - (b*c)/d] + (b^2*c^2 + 2*d^2)*Sinh[a - (b*c)/d])*SinhIntegral[((b - d)*(c + d*x))/d])/(2*b^3*d^2) - ((2*b*c*d*Cosh[a - (b*c)/d] + (b^2*c^2 + 2*d^2)*Sinh[a - (b*c)/d])*SinhIntegral[((b + d)*(c + d*x))/d])/(2*b^3*d^2)} *)
(* {x^3*Cosh[a + b*x]*SinhIntegral[c + d*x], x, 0, 0} *)


(* ::Subsection::Closed:: *)
(*Hyperbolic cosine integral function*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m CoshIntegral[b x]^n*)


{CoshIntegral[b*x]/x^3, x, 5, -(Cosh[b*x]/(4*x^2)) + (1/4)*(b^2 - 2/x^2)*CoshIntegral[b*x] - (b*Sinh[b*x])/(4*x)}
{CoshIntegral[b*x]/x^2, x, 4, -(Cosh[b*x]/x) - CoshIntegral[b*x]/x + b*SinhIntegral[b*x]}
{CoshIntegral[b*x]/x, x, 0, Int[CoshIntegral[b*x]/x, x]}
{CoshIntegral[b*x], x, 1, x*CoshIntegral[b*x] - Sinh[b*x]/b}
{x*CoshIntegral[b*x], x, 4, Cosh[b*x]/(2*b^2) + (1/2)*x^2*CoshIntegral[b*x] - (x*Sinh[b*x])/(2*b)}
{x^2*CoshIntegral[b*x], x, 5, (2*x*Cosh[b*x])/(3*b^2) + (1/3)*x^3*CoshIntegral[b*x] - (2*Sinh[b*x])/(3*b^3) - (x^2*Sinh[b*x])/(3*b)}
{x^3*CoshIntegral[b*x], x, 6, (3*Cosh[b*x])/(2*b^4) + (3*x^2*Cosh[b*x])/(4*b^2) + (1/4)*x^4*CoshIntegral[b*x] - (3*x*Sinh[b*x])/(2*b^3) - (x^3*Sinh[b*x])/(4*b)}
{x^m*CoshIntegral[b*x], x, 5, (x^(1 + m)*CoshIntegral[b*x])/(1 + m) + (x^(1 + m)*((-b)*x)^(-1 - m)*Gamma[1 + m, (-b)*x])/(2*(1 + m)) + (x^(1 + m)*(b*x)^(-1 - m)*Gamma[1 + m, b*x])/(2*(1 + m))}


{CoshIntegral[b*x]^2/x^3, x, 0, Int[CoshIntegral[b*x]^2/x^3, x]}
{CoshIntegral[b*x]^2/x^2, x, 0, Int[CoshIntegral[b*x]^2/x^2, x]}
{CoshIntegral[b*x]^2/x, x, 0, Int[CoshIntegral[b*x]^2/x, x]}
{CoshIntegral[b*x]^2, x, 6, x*CoshIntegral[b*x]^2 - (2*CoshIntegral[b*x]*Sinh[b*x])/b + SinhIntegral[2*b*x]/b}
{x*CoshIntegral[b*x]^2, x, 11, (1/2)*x^2*CoshIntegral[b*x]^2 - CoshIntegral[2*b*x]/(2*b^2) - Log[x]/(2*b^2) + Sinh[b*x]^2/(2*b^2) + (CoshIntegral[b*x]*(Cosh[b*x] - b*x*Sinh[b*x]))/b^2}
{x^2*CoshIntegral[b*x]^2, x, 13, -(x/(2*b^2)) + (1/3)*x^3*CoshIntegral[b*x]^2 - (5*Cosh[b*x]*Sinh[b*x])/(6*b^3) + (x*Sinh[b*x]^2)/(3*b^2) + (2*CoshIntegral[b*x]*(2*b*x*Cosh[b*x] - (2 + b^2*x^2)*Sinh[b*x]))/(3*b^3) + (2*SinhIntegral[2*b*x])/(3*b^3)}
{x^3*CoshIntegral[b*x]^2, x, 20, -(x^2/(4*b^2)) + (3*Cosh[b*x]^2)/(8*b^4) + (1/4)*x^4*CoshIntegral[b*x]^2 - (3*CoshIntegral[2*b*x])/(2*b^4) - (3*Log[x])/(2*b^4) - (x*Cosh[b*x]*Sinh[b*x])/b^3 + (13*Sinh[b*x]^2)/(8*b^4) + (x^2*Sinh[b*x]^2)/(4*b^2) + (CoshIntegral[b*x]*(3*(2 + b^2*x^2)*Cosh[b*x] - b*x*(6 + b^2*x^2)*Sinh[b*x]))/(2*b^4)}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m CoshIntegral[a+b x]^n*)


{CoshIntegral[a + b*x]/x^3, x, 12, -((b*Cosh[a + b*x])/(2*a*x)) + (1/2)*(b^2/a^2 - 1/x^2)*CoshIntegral[a + b*x] - (b^2*CoshIntegral[b*x]*(Cosh[a] - a*Sinh[a]))/(2*a^2) + (b^2*(a*Cosh[a] - Sinh[a])*SinhIntegral[b*x])/(2*a^2)}
{CoshIntegral[a + b*x]/x^2, x, 8, (b*Cosh[a]*CoshIntegral[b*x])/a - ((a + b*x)*CoshIntegral[a + b*x])/(a*x) + (b*Sinh[a]*SinhIntegral[b*x])/a}
{CoshIntegral[a + b*x]/x, x, 0, Int[CoshIntegral[a + b*x]/x, x]}
{CoshIntegral[a + b*x], x, 1, ((a + b*x)*CoshIntegral[a + b*x])/b - Sinh[a + b*x]/b}
{x*CoshIntegral[a + b*x], x, 8, Cosh[a + b*x]/(2*b^2) - (1/2)*(a^2/b^2 - x^2)*CoshIntegral[a + b*x] + (a*Sinh[a + b*x])/(2*b^2) - (x*Sinh[a + b*x])/(2*b)}
{x^2*CoshIntegral[a + b*x], x, 11, -((a*Cosh[a + b*x])/(3*b^3)) + (2*x*Cosh[a + b*x])/(3*b^2) + (1/3)*(a^3/b^3 + x^3)*CoshIntegral[a + b*x] - (2*Sinh[a + b*x])/(3*b^3) - (a^2*Sinh[a + b*x])/(3*b^3) + (a*x*Sinh[a + b*x])/(3*b^2) - (x^2*Sinh[a + b*x])/(3*b)}
{x^3*CoshIntegral[a + b*x], x, 15, (3*Cosh[a + b*x])/(2*b^4) + (a^2*Cosh[a + b*x])/(4*b^4) - (a*x*Cosh[a + b*x])/(2*b^3) + (3*x^2*Cosh[a + b*x])/(4*b^2) - (1/4)*(a^4/b^4 - x^4)*CoshIntegral[a + b*x] + (a*Sinh[a + b*x])/(2*b^4) + (a^3*Sinh[a + b*x])/(4*b^4) - (3*x*Sinh[a + b*x])/(2*b^3) - (a^2*x*Sinh[a + b*x])/(4*b^3) + (a*x^2*Sinh[a + b*x])/(4*b^2) - (x^3*Sinh[a + b*x])/(4*b)}
{x^m*CoshIntegral[a + b*x], x, 6, (x^(1 + m)*CoshIntegral[a + b*x])/(1 + m) + (E^a*x^(1 + m)*((-b)*x)^(-1 - m)*Gamma[1 + m, (-b)*x])/(2*(1 + m)) + (x^(1 + m)*(b*x)^(-1 - m)*Gamma[1 + m, b*x])/(E^a*(2*(1 + m))) + (a*Int[(x^m*Cosh[a + b*x])/(a + b*x), x])/(1 + m)}


{CoshIntegral[a + b*x]^2/x^3, x, 0, Int[CoshIntegral[a + b*x]^2/x^3, x]}
{CoshIntegral[a + b*x]^2/x^2, x, 0, Int[CoshIntegral[a + b*x]^2/x^2, x]}
{CoshIntegral[a + b*x]^2/x, x, 0, Int[CoshIntegral[a + b*x]^2/x, x]}
{CoshIntegral[a + b*x]^2, x, 6, ((a + b*x)*CoshIntegral[a + b*x]^2)/b - (2*CoshIntegral[a + b*x]*Sinh[a + b*x])/b + SinhIntegral[2*(a + b*x)]/b}
{x*CoshIntegral[a + b*x]^2, x, 19, Cosh[2*a + 2*b*x]/(4*b^2) - (1/2)*(a^2/b^2 - x^2)*CoshIntegral[a + b*x]^2 - CoshIntegral[2*(a + b*x)]/(2*b^2) - Log[a + b*x]/(2*b^2) + (CoshIntegral[a + b*x]*(Cosh[a + b*x] + (a - b*x)*Sinh[a + b*x]))/b^2 - (a*SinhIntegral[2*(a + b*x)])/b^2}
{x^2*CoshIntegral[a + b*x]^2, x, 42, -((2*x)/(3*b^2)) - (a*Cosh[2*a + 2*b*x])/(3*b^3) + (x*Cosh[2*a + 2*b*x])/(6*b^2) + (1/3)*(a^3/b^3 + x^3)*CoshIntegral[a + b*x]^2 + (a*CoshIntegral[2*(a + b*x)])/b^3 + (a*Log[a + b*x])/b^3 - (2*Cosh[a + b*x]*Sinh[a + b*x])/(3*b^3) - (2*CoshIntegral[a + b*x]*((a - 2*b*x)*Cosh[a + b*x] + (2 + a^2 - a*b*x + b^2*x^2)*Sinh[a + b*x]))/(3*b^3) - Sinh[2*a + 2*b*x]/(12*b^3) + ((2 + 3*a^2)*SinhIntegral[2*(a + b*x)])/(3*b^3)}
(* {x^3*CoshIntegral[a + b*x]^2, x, 77, (5*a*x)/(4*b^3) - (3*x^2)/(8*b^2) + (3*Cosh[a + b*x]^2)/(8*b^4) + (13*Cosh[2*a + 2*b*x])/(16*b^4) + (3*a^2*Cosh[2*a + 2*b*x])/(8*b^4) - (a*x*Cosh[2*a + 2*b*x])/(4*b^3) + (x^2*Cosh[2*a + 2*b*x])/(8*b^2) - (1/4)*(a^4/b^4 - x^4)*CoshIntegral[a + b*x]^2 - (3*(1 + a^2)*CoshIntegral[2*(a + b*x)])/(2*b^4) - (3*Log[a + b*x])/(2*b^4) - (3*a^2*Log[a + b*x])/(2*b^4) + (5*a*Cosh[a + b*x]*Sinh[a + b*x])/(4*b^4) - (3*x*Cosh[a + b*x]*Sinh[a + b*x])/(4*b^3) + (CoshIntegral[a + b*x]*((6 + a^2 - 2*a*b*x + 3*b^2*x^2)*Cosh[a + b*x] + (a^3 - a^2*b*x + a*(2 + b^2*x^2) - b*x*(6 + b^2*x^2))*Sinh[a + b*x]))/(2*b^4) + (a*Sinh[2*a + 2*b*x])/(8*b^4) - (x*Sinh[2*a + 2*b*x])/(8*b^3) - (a*(2 + a^2)*SinhIntegral[2*(a + b*x)])/b^4} *)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m Hyper[b x] CoshIntegral[b x]^n*)


{Cosh[b*x]*CoshIntegral[b*x]/x^3, x, 16, -(Cosh[b*x]^2/(4*x^2)) + (1/4)*b^2*CoshIntegral[b*x]^2 + b^2*CoshIntegral[2*b*x] - (b*Cosh[b*x]*Sinh[b*x])/(2*x) - (CoshIntegral[b*x]*(Cosh[b*x] + b*x*Sinh[b*x]))/(2*x^2) - (b*Sinh[2*b*x])/(4*x)}
{Cosh[b*x]*CoshIntegral[b*x]/x^2, x, 7, -(1/(2*x)) - Cosh[2*b*x]/(2*x) - (Cosh[b*x]*CoshIntegral[b*x])/x + b*Int[(CoshIntegral[b*x]*Sinh[b*x])/x, x] + b*SinhIntegral[2*b*x]}
{Cosh[b*x]*CoshIntegral[b*x]/x, x, 2, (1/2)*CoshIntegral[b*x]^2}
{Cosh[b*x]*CoshIntegral[b*x], x, 5, (CoshIntegral[b*x]*Sinh[b*x])/b - SinhIntegral[2*b*x]/(2*b)}
{x*Cosh[b*x]*CoshIntegral[b*x], x, 10, CoshIntegral[2*b*x]/(2*b^2) + Log[x]/(2*b^2) - Sinh[b*x]^2/(2*b^2) - (CoshIntegral[b*x]*(Cosh[b*x] - b*x*Sinh[b*x]))/b^2}
{x^2*Cosh[b*x]*CoshIntegral[b*x], x, 12, (3*x)/(4*b^2) + (5*Cosh[b*x]*Sinh[b*x])/(4*b^3) - (x*Sinh[b*x]^2)/(2*b^2) - (CoshIntegral[b*x]*(2*b*x*Cosh[b*x] - (2 + b^2*x^2)*Sinh[b*x]))/b^3 - SinhIntegral[2*b*x]/b^3}
{x^3*Cosh[b*x]*CoshIntegral[b*x], x, 19, x^2/(2*b^2) - (3*Cosh[b*x]^2)/(4*b^4) + (3*CoshIntegral[2*b*x])/b^4 + (3*Log[x])/b^4 + (2*x*Cosh[b*x]*Sinh[b*x])/b^3 - (13*Sinh[b*x]^2)/(4*b^4) - (x^2*Sinh[b*x]^2)/(2*b^2) - (CoshIntegral[b*x]*(3*(2 + b^2*x^2)*Cosh[b*x] - b*x*(6 + b^2*x^2)*Sinh[b*x]))/b^4}


{Sinh[b*x]*CoshIntegral[b*x]/x^3, x, 14, -(b/(4*x)) - (b*Cosh[2*b*x])/(2*x) + (1/2)*b^2*Int[(CoshIntegral[b*x]*Sinh[b*x])/x, x] - (CoshIntegral[b*x]*(b*x*Cosh[b*x] + Sinh[b*x]))/(2*x^2) - Sinh[2*b*x]/(8*x^2) + b^2*SinhIntegral[2*b*x]}
{Sinh[b*x]*CoshIntegral[b*x]/x^2, x, 8, (1/2)*b*CoshIntegral[b*x]^2 + b*CoshIntegral[2*b*x] - (CoshIntegral[b*x]*Sinh[b*x])/x - Sinh[2*b*x]/(2*x)}
{Sinh[b*x]*CoshIntegral[b*x]/x, x, 0, Int[(CoshIntegral[b*x]*Sinh[b*x])/x, x]}
{Sinh[b*x]*CoshIntegral[b*x], x, 6, (Cosh[b*x]*CoshIntegral[b*x])/b - CoshIntegral[2*b*x]/(2*b) - Log[x]/(2*b)}
{x*Sinh[b*x]*CoshIntegral[b*x], x, 8, -(x/(2*b)) + (CoshIntegral[b*x]*(b*x*Cosh[b*x] - Sinh[b*x]))/b^2 - (Cosh[b*x]*Sinh[b*x])/(2*b^2) + SinhIntegral[2*b*x]/(2*b^2)}
{x^2*Sinh[b*x]*CoshIntegral[b*x], x, 14, -(x^2/(4*b)) + Cosh[b*x]^2/(4*b^3) - CoshIntegral[2*b*x]/b^3 - Log[x]/b^3 - (x*Cosh[b*x]*Sinh[b*x])/(2*b^2) + Sinh[b*x]^2/b^3 + (CoshIntegral[b*x]*((2 + b^2*x^2)*Cosh[b*x] - 2*b*x*Sinh[b*x]))/b^3}
{x^3*Sinh[b*x]*CoshIntegral[b*x], x, 17, -((5*x)/(2*b^3)) - x^3/(6*b) + (x*Cosh[b*x]^2)/(2*b^3) - (4*Cosh[b*x]*Sinh[b*x])/b^4 - (x^2*Cosh[b*x]*Sinh[b*x])/(2*b^2) + (3*x*Sinh[b*x]^2)/(2*b^3) + (CoshIntegral[b*x]*(b*x*(6 + b^2*x^2)*Cosh[b*x] - 3*(2 + b^2*x^2)*Sinh[b*x]))/b^4 + (3*SinhIntegral[2*b*x])/b^4}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m Hyper[a+b x] CoshIntegral[c+d x]^n*)


(* {Sinh[a + b*x]*CoshIntegral[c + d*x]/x^3, x, 0, 0} *)
{Sinh[a + b*x]*CoshIntegral[c + d*x]/x^2, x, 20, b*Int[(Cosh[a + b*x]*CoshIntegral[c + d*x])/x, x] + (d*CoshIntegral[(b - d)*x]*Sinh[a - c])/(2*c) + (d*CoshIntegral[(b + d)*x]*Sinh[a + c])/(2*c) - (d*CoshIntegral[((b - d)*(c + d*x))/d]*Sinh[a - (b*c)/d])/(2*c) - (d*CoshIntegral[((b + d)*(c + d*x))/d]*Sinh[a - (b*c)/d])/(2*c) - (CoshIntegral[c + d*x]*Sinh[a + b*x])/x + (d*Cosh[a - c]*SinhIntegral[(b - d)*x])/(2*c) + (d*Cosh[a + c]*SinhIntegral[(b + d)*x])/(2*c) - (d*Cosh[a - (b*c)/d]*SinhIntegral[((b - d)*(c + d*x))/d])/(2*c) - (d*Cosh[a - (b*c)/d]*SinhIntegral[((b + d)*(c + d*x))/d])/(2*c)}
{Sinh[a + b*x]*CoshIntegral[c + d*x]/x, x, 0, Int[(CoshIntegral[c + d*x]*Sinh[a + b*x])/x, x]}
{Sinh[a + b*x]*CoshIntegral[c + d*x], x, 10, (Cosh[a + b*x]*CoshIntegral[c + d*x])/b - (Cosh[a - (b*c)/d]*CoshIntegral[((b - d)*(c + d*x))/d])/(2*b) - (Cosh[a - (b*c)/d]*CoshIntegral[((b + d)*(c + d*x))/d])/(2*b) - (Sinh[a - (b*c)/d]*SinhIntegral[((b - d)*(c + d*x))/d])/(2*b) - (Sinh[a - (b*c)/d]*SinhIntegral[((b + d)*(c + d*x))/d])/(2*b)}
{x*Sinh[a + b*x]*CoshIntegral[c + d*x], x, 26, (CoshIntegral[((b - d)*(c + d*x))/d]*(b*c*Cosh[a - (b*c)/d] + d*Sinh[a - (b*c)/d]))/(2*b^2*d) + (CoshIntegral[((b + d)*(c + d*x))/d]*(b*c*Cosh[a - (b*c)/d] + d*Sinh[a - (b*c)/d]))/(2*b^2*d) + (CoshIntegral[c + d*x]*(b*x*Cosh[a + b*x] - Sinh[a + b*x]))/b^2 - Sinh[a - c + (b - d)*x]/(2*b*(b - d)) - Sinh[a + c + (b + d)*x]/(2*b*(b + d)) + ((d*Cosh[a - (b*c)/d] + b*c*Sinh[a - (b*c)/d])*SinhIntegral[((b - d)*(c + d*x))/d])/(2*b^2*d) + ((d*Cosh[a - (b*c)/d] + b*c*Sinh[a - (b*c)/d])*SinhIntegral[((b + d)*(c + d*x))/d])/(2*b^2*d)}
(* {x^2*Sinh[a + b*x]*CoshIntegral[c + d*x], x, 46, Cosh[a - c + (b - d)*x]/(2*b*(b - d)^2) + Cosh[a - c + (b - d)*x]/(b^2*(b - d)) + Cosh[a + c + (b + d)*x]/(2*b*(b + d)^2) + Cosh[a + c + (b + d)*x]/(b^2*(b + d)) - (CoshIntegral[((b - d)*(c + d*x))/d]*((b^2*c^2 + 2*d^2)*Cosh[a - (b*c)/d] + 2*b*c*d*Sinh[a - (b*c)/d]))/(2*b^3*d^2) - (CoshIntegral[((b + d)*(c + d*x))/d]*((b^2*c^2 + 2*d^2)*Cosh[a - (b*c)/d] + 2*b*c*d*Sinh[a - (b*c)/d]))/(2*b^3*d^2) + (CoshIntegral[c + d*x]*((2 + b^2*x^2)*Cosh[a + b*x] - 2*b*x*Sinh[a + b*x]))/b^3 + (c*Sinh[a - c + (b - d)*x])/(2*b*(b - d)*d) - (x*Sinh[a - c + (b - d)*x])/(2*b*(b - d)) + (c*Sinh[a + c + (b + d)*x])/(2*b*d*(b + d)) - (x*Sinh[a + c + (b + d)*x])/(2*b*(b + d)) - ((2*b*c*d*Cosh[a - (b*c)/d] + (b^2*c^2 + 2*d^2)*Sinh[a - (b*c)/d])*SinhIntegral[((b - d)*(c + d*x))/d])/(2*b^3*d^2) - ((2*b*c*d*Cosh[a - (b*c)/d] + (b^2*c^2 + 2*d^2)*Sinh[a - (b*c)/d])*SinhIntegral[((b + d)*(c + d*x))/d])/(2*b^3*d^2)} *)
(* {x^3*Sinh[a + b*x]*CoshIntegral[c + d*x], x, 0, 0} *)


(* {Cosh[a + b*x]*CoshIntegral[c + d*x]/x^3, x, 0, 0} *)
{Cosh[a + b*x]*CoshIntegral[c + d*x]/x^2, x, 20, (d*Cosh[a - c]*CoshIntegral[(b - d)*x])/(2*c) + (d*Cosh[a + c]*CoshIntegral[(b + d)*x])/(2*c) - (Cosh[a + b*x]*CoshIntegral[c + d*x])/x - (d*Cosh[a - (b*c)/d]*CoshIntegral[((b - d)*(c + d*x))/d])/(2*c) - (d*Cosh[a - (b*c)/d]*CoshIntegral[((b + d)*(c + d*x))/d])/(2*c) + b*Int[(CoshIntegral[c + d*x]*Sinh[a + b*x])/x, x] + (d*Sinh[a - c]*SinhIntegral[(b - d)*x])/(2*c) + (d*Sinh[a + c]*SinhIntegral[(b + d)*x])/(2*c) - (d*Sinh[a - (b*c)/d]*SinhIntegral[((b - d)*(c + d*x))/d])/(2*c) - (d*Sinh[a - (b*c)/d]*SinhIntegral[((b + d)*(c + d*x))/d])/(2*c)}
{Cosh[a + b*x]*CoshIntegral[c + d*x]/x, x, 0, Int[(Cosh[a + b*x]*CoshIntegral[c + d*x])/x, x]}
{Cosh[a + b*x]*CoshIntegral[c + d*x], x, 10, -((CoshIntegral[((b - d)*(c + d*x))/d]*Sinh[a - (b*c)/d])/(2*b)) - (CoshIntegral[((b + d)*(c + d*x))/d]*Sinh[a - (b*c)/d])/(2*b) + (CoshIntegral[c + d*x]*Sinh[a + b*x])/b - (Cosh[a - (b*c)/d]*SinhIntegral[((b - d)*(c + d*x))/d])/(2*b) - (Cosh[a - (b*c)/d]*SinhIntegral[((b + d)*(c + d*x))/d])/(2*b)}
{x*Cosh[a + b*x]*CoshIntegral[c + d*x], x, 26, -(Cosh[a - c + (b - d)*x]/(2*b*(b - d))) - Cosh[a + c + (b + d)*x]/(2*b*(b + d)) + (CoshIntegral[((b - d)*(c + d*x))/d]*(d*Cosh[a - (b*c)/d] + b*c*Sinh[a - (b*c)/d]))/(2*b^2*d) + (CoshIntegral[((b + d)*(c + d*x))/d]*(d*Cosh[a - (b*c)/d] + b*c*Sinh[a - (b*c)/d]))/(2*b^2*d) - (CoshIntegral[c + d*x]*(Cosh[a + b*x] - b*x*Sinh[a + b*x]))/b^2 + ((b*c*Cosh[a - (b*c)/d] + d*Sinh[a - (b*c)/d])*SinhIntegral[((b - d)*(c + d*x))/d])/(2*b^2*d) + ((b*c*Cosh[a - (b*c)/d] + d*Sinh[a - (b*c)/d])*SinhIntegral[((b + d)*(c + d*x))/d])/(2*b^2*d)}
(* {x^2*Cosh[a + b*x]*CoshIntegral[c + d*x], x, 46, (c*Cosh[a - c + (b - d)*x])/(2*b*(b - d)*d) - (x*Cosh[a - c + (b - d)*x])/(2*b*(b - d)) + (c*Cosh[a + c + (b + d)*x])/(2*b*d*(b + d)) - (x*Cosh[a + c + (b + d)*x])/(2*b*(b + d)) - (CoshIntegral[((b - d)*(c + d*x))/d]*(2*b*c*d*Cosh[a - (b*c)/d] + (b^2*c^2 + 2*d^2)*Sinh[a - (b*c)/d]))/(2*b^3*d^2) - (CoshIntegral[((b + d)*(c + d*x))/d]*(2*b*c*d*Cosh[a - (b*c)/d] + (b^2*c^2 + 2*d^2)*Sinh[a - (b*c)/d]))/(2*b^3*d^2) - (CoshIntegral[c + d*x]*(2*b*x*Cosh[a + b*x] - (2 + b^2*x^2)*Sinh[a + b*x]))/b^3 + Sinh[a - c + (b - d)*x]/(2*b*(b - d)^2) + Sinh[a - c + (b - d)*x]/(b^2*(b - d)) + Sinh[a + c + (b + d)*x]/(2*b*(b + d)^2) + Sinh[a + c + (b + d)*x]/(b^2*(b + d)) - (((b^2*c^2 + 2*d^2)*Cosh[a - (b*c)/d] + 2*b*c*d*Sinh[a - (b*c)/d])*SinhIntegral[((b - d)*(c + d*x))/d])/(2*b^3*d^2) - (((b^2*c^2 + 2*d^2)*Cosh[a - (b*c)/d] + 2*b*c*d*Sinh[a - (b*c)/d])*SinhIntegral[((b + d)*(c + d*x))/d])/(2*b^3*d^2)} *)
(* {x^3*Cosh[a + b*x]*CoshIntegral[c + d*x], x, 0, 0} *)
