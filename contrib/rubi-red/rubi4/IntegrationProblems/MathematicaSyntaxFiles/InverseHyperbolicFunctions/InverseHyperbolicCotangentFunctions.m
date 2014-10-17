(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Inverse Hyperbolic Cotangents*)


(* ::Subsection::Closed:: *)
(*Integrands involving inverse hyperbolic cotangents*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m ArcCoth[a x]^n*)


(* Integrands of the form x^m*ArcCoth[a*x] where m is an integer *)
{x^5*ArcCoth[a*x], x, 6, x/(6*a^5) + x^3/(18*a^3) + x^5/(30*a) - ArcCoth[a*x]/(6*a^6) + (1/6)*x^6*ArcCoth[a*x]}
{x^4*ArcCoth[a*x], x, 5, x^2/(10*a^3) + x^4/(20*a) + (1/5)*x^5*ArcCoth[a*x] + Log[1 - a^2*x^2]/(10*a^5)}
{x^3*ArcCoth[a*x], x, 4, x/(4*a^3) + x^3/(12*a) - ArcCoth[a*x]/(4*a^4) + (1/4)*x^4*ArcCoth[a*x]}
{x^2*ArcCoth[a*x], x, 3, x^2/(6*a) + (1/3)*x^3*ArcCoth[a*x] + Log[1 - a^2*x^2]/(6*a^3)}
{x*ArcCoth[a*x], x, 2, x/(2*a) - ArcCoth[a*x]/(2*a^2) + (1/2)*x^2*ArcCoth[a*x]}
{ArcCoth[a*x], x, 1, x*ArcCoth[a*x] + Log[1 - a^2*x^2]/(2*a)}
{ArcCoth[a*x]/x, x, 3, (1/2)*PolyLog[2, -(1/(a*x))] - (1/2)*PolyLog[2, 1/(a*x)]}
{ArcCoth[a*x]/x^2, x, 2, -(ArcCoth[a*x]/x) - a*ArcTanh[1 - 2*a^2*x^2]}
{ArcCoth[a*x]/x^3, x, 2, -(a/(2*x)) + (1/2)*a^2*ArcCoth[a*x] - ArcCoth[a*x]/(2*x^2)}
{ArcCoth[a*x]/x^4, x, 4, -(a/(6*x^2)) - ArcCoth[a*x]/(3*x^3) - (1/3)*a^3*ArcTanh[1 - 2*a^2*x^2]}
{ArcCoth[a*x]/x^5, x, 4, -(a/(12*x^3)) - a^3/(4*x) + (1/4)*a^4*ArcCoth[a*x] - ArcCoth[a*x]/(4*x^4)}


(* Integrands of the form x^m*ArcCoth[a*x]^2 where m is an integer *)
{x^5*ArcCoth[a*x]^2, x, 12, (4*x^2)/(45*a^4) + x^4/(60*a^2) + (x*ArcCoth[a*x])/(3*a^5) + (x^3*ArcCoth[a*x])/(9*a^3) + (x^5*ArcCoth[a*x])/(15*a) - ArcCoth[a*x]^2/(6*a^6) + (1/6)*x^6*ArcCoth[a*x]^2 + (23*Log[1 - a^2*x^2])/(90*a^6)}
{x^4*ArcCoth[a*x]^2, x, 12, (3*x)/(10*a^4) + x^3/(30*a^2) - (3*ArcCoth[a*x])/(10*a^5) + (x^2*ArcCoth[a*x])/(5*a^3) + (x^4*ArcCoth[a*x])/(10*a) + ArcCoth[a*x]^2/(5*a^5) + (1/5)*x^5*ArcCoth[a*x]^2 - (2*ArcCoth[a*x]*Log[2/(1 - a*x)])/(5*a^5) - PolyLog[2, 1 - 2/(1 - a*x)]/(5*a^5)}
{x^3*ArcCoth[a*x]^2, x, 6, x^2/(12*a^2) + (x*ArcCoth[a*x])/(2*a^3) + (x^3*ArcCoth[a*x])/(6*a) - ArcCoth[a*x]^2/(4*a^4) + (1/4)*x^4*ArcCoth[a*x]^2 + Log[1 - a^2*x^2]/(3*a^4)}
{x^2*ArcCoth[a*x]^2, x, 7, x/(3*a^2) - ArcCoth[a*x]/(3*a^3) + (x^2*ArcCoth[a*x])/(3*a) + ArcCoth[a*x]^2/(3*a^3) + (1/3)*x^3*ArcCoth[a*x]^2 - (2*ArcCoth[a*x]*Log[2/(1 - a*x)])/(3*a^3) - PolyLog[2, 1 - 2/(1 - a*x)]/(3*a^3)}
{x*ArcCoth[a*x]^2, x, 2, (x*ArcCoth[a*x])/a - ArcCoth[a*x]^2/(2*a^2) + (1/2)*x^2*ArcCoth[a*x]^2 + Log[1 - a^2*x^2]/(2*a^2)}
{ArcCoth[a*x]^2, x, 4, ArcCoth[a*x]^2/a + x*ArcCoth[a*x]^2 - (2*ArcCoth[a*x]*Log[2/(1 - a*x)])/a - PolyLog[2, 1 - 2/(1 - a*x)]/a}
{ArcCoth[a*x]^2/x, x, 6, 2*ArcCoth[a*x]^2*ArcCoth[1 - 2/(1 - a*x)] + ArcCoth[a*x]*PolyLog[2, 1 - 2/(1 + a*x)] - ArcCoth[a*x]*PolyLog[2, 1 - (2*a*x)/(1 + a*x)] + (1/2)*PolyLog[3, 1 - 2/(1 + a*x)] - (1/2)*PolyLog[3, 1 - (2*a*x)/(1 + a*x)]}
{ArcCoth[a*x]^2/x^2, x, 4, a*ArcCoth[a*x]^2 - ArcCoth[a*x]^2/x + 2*a*ArcCoth[a*x]*Log[(2*a*x)/(1 + a*x)] - a*PolyLog[2, -1 + 2/(1 + a*x)]}
{ArcCoth[a*x]^2/x^3, x, 3, -((a*ArcCoth[a*x])/x) + (1/2)*a^2*ArcCoth[a*x]^2 - ArcCoth[a*x]^2/(2*x^2) - a^2*ArcTanh[1 - 2*a^2*x^2]}
{ArcCoth[a*x]^2/x^4, x, 7, -(a^2/(3*x)) + (1/3)*a^3*ArcCoth[a*x] - (a*ArcCoth[a*x])/(3*x^2) + (1/3)*a^3*ArcCoth[a*x]^2 - ArcCoth[a*x]^2/(3*x^3) + (2/3)*a^3*ArcCoth[a*x]*Log[(2*a*x)/(1 + a*x)] - (1/3)*a^3*PolyLog[2, -1 + 2/(1 + a*x)]}
{ArcCoth[a*x]^2/x^5, x, 8, -(a^2/(12*x^2)) - (a*ArcCoth[a*x])/(6*x^3) - (a^3*ArcCoth[a*x])/(2*x) + (1/4)*a^4*ArcCoth[a*x]^2 - ArcCoth[a*x]^2/(4*x^4) - (2/3)*a^4*ArcTanh[1 - 2*a^2*x^2]}


(* Integrands of the form x^m*ArcCoth[a*x]^3 where m is an integer *)
{x^5*ArcCoth[a*x]^3, x, 26, (19*x)/(60*a^5) + x^3/(60*a^3) - (19*ArcCoth[a*x])/(60*a^6) + (4*x^2*ArcCoth[a*x])/(15*a^4) + (x^4*ArcCoth[a*x])/(20*a^2) + (23*ArcCoth[a*x]^2)/(30*a^6) + (x*ArcCoth[a*x]^2)/(2*a^5) + (x^3*ArcCoth[a*x]^2)/(6*a^3) + (x^5*ArcCoth[a*x]^2)/(10*a) - ArcCoth[a*x]^3/(6*a^6) + (1/6)*x^6*ArcCoth[a*x]^3 - (23*ArcCoth[a*x]*Log[2/(1 - a*x)])/(15*a^6) - (23*PolyLog[2, 1 - 2/(1 - a*x)])/(30*a^6)}
{x^4*ArcCoth[a*x]^3, x, 15, x^2/(20*a^3) + (9*x*ArcCoth[a*x])/(10*a^4) + (x^3*ArcCoth[a*x])/(10*a^2) - (9*ArcCoth[a*x]^2)/(20*a^5) + (3*x^2*ArcCoth[a*x]^2)/(10*a^3) + (3*x^4*ArcCoth[a*x]^2)/(20*a) + ArcCoth[a*x]^3/(5*a^5) + (1/5)*x^5*ArcCoth[a*x]^3 - (3*ArcCoth[a*x]^2*Log[2/(1 - a*x)])/(5*a^5) + Log[1 - a^2*x^2]/(2*a^5) - (3*ArcCoth[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/(5*a^5) + (3*PolyLog[3, 1 - 2/(1 - a*x)])/(10*a^5)}
{x^3*ArcCoth[a*x]^3, x, 13, x/(4*a^3) - ArcCoth[a*x]/(4*a^4) + (x^2*ArcCoth[a*x])/(4*a^2) + ArcCoth[a*x]^2/a^4 + (3*x*ArcCoth[a*x]^2)/(4*a^3) + (x^3*ArcCoth[a*x]^2)/(4*a) - ArcCoth[a*x]^3/(4*a^4) + (1/4)*x^4*ArcCoth[a*x]^3 - (2*ArcCoth[a*x]*Log[2/(1 - a*x)])/a^4 - PolyLog[2, 1 - 2/(1 - a*x)]/a^4}
{x^2*ArcCoth[a*x]^3, x, 8, (x*ArcCoth[a*x])/a^2 - ArcCoth[a*x]^2/(2*a^3) + (x^2*ArcCoth[a*x]^2)/(2*a) + ArcCoth[a*x]^3/(3*a^3) + (1/3)*x^3*ArcCoth[a*x]^3 - (ArcCoth[a*x]^2*Log[2/(1 - a*x)])/a^3 + Log[1 - a^2*x^2]/(2*a^3) - (ArcCoth[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/a^3 + PolyLog[3, 1 - 2/(1 - a*x)]/(2*a^3)}
{x*ArcCoth[a*x]^3, x, 5, (3*ArcCoth[a*x]^2)/(2*a^2) + (3*x*ArcCoth[a*x]^2)/(2*a) - ArcCoth[a*x]^3/(2*a^2) + (1/2)*x^2*ArcCoth[a*x]^3 - (3*ArcCoth[a*x]*Log[2/(1 - a*x)])/a^2 - (3*PolyLog[2, 1 - 2/(1 - a*x)])/(2*a^2)}
{ArcCoth[a*x]^3, x, 5, ArcCoth[a*x]^3/a + x*ArcCoth[a*x]^3 - (3*ArcCoth[a*x]^2*Log[2/(1 - a*x)])/a - (3*ArcCoth[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/a + (3*PolyLog[3, 1 - 2/(1 - a*x)])/(2*a)}
{ArcCoth[a*x]^3/x, x, 8, 2*ArcCoth[a*x]^3*ArcCoth[1 - 2/(1 - a*x)] + (3/2)*ArcCoth[a*x]^2*PolyLog[2, 1 - 2/(1 + a*x)] - (3/2)*ArcCoth[a*x]^2*PolyLog[2, 1 - (2*a*x)/(1 + a*x)] + (3/2)*ArcCoth[a*x]*PolyLog[3, 1 - 2/(1 + a*x)] - (3/2)*ArcCoth[a*x]*PolyLog[3, 1 - (2*a*x)/(1 + a*x)] + (3/4)*PolyLog[4, 1 - 2/(1 + a*x)] - (3/4)*PolyLog[4, 1 - (2*a*x)/(1 + a*x)]}
{ArcCoth[a*x]^3/x^2, x, 5, a*ArcCoth[a*x]^3 - ArcCoth[a*x]^3/x + 3*a*ArcCoth[a*x]^2*Log[(2*a*x)/(1 + a*x)] - 3*a*ArcCoth[a*x]*PolyLog[2, -1 + 2/(1 + a*x)] - (3/2)*a*PolyLog[3, -1 + 2/(1 + a*x)]}
{ArcCoth[a*x]^3/x^3, x, 5, (3/2)*a^2*ArcCoth[a*x]^2 - (3*a*ArcCoth[a*x]^2)/(2*x) + (1/2)*a^2*ArcCoth[a*x]^3 - ArcCoth[a*x]^3/(2*x^2) + 3*a^2*ArcCoth[a*x]*Log[(2*a*x)/(1 + a*x)] - (3/2)*a^2*PolyLog[2, -1 + 2/(1 + a*x)]}
{ArcCoth[a*x]^3/x^4, x, 9, -((a^2*ArcCoth[a*x])/x) + (1/2)*a^3*ArcCoth[a*x]^2 - (a*ArcCoth[a*x]^2)/(2*x^2) + (1/3)*a^3*ArcCoth[a*x]^3 - ArcCoth[a*x]^3/(3*x^3) - a^3*ArcTanh[1 - 2*a^2*x^2] + a^3*ArcCoth[a*x]^2*Log[(2*a*x)/(1 + a*x)] - a^3*ArcCoth[a*x]*PolyLog[2, -1 + 2/(1 + a*x)] - (1/2)*a^3*PolyLog[3, -1 + 2/(1 + a*x)]}
{ArcCoth[a*x]^3/x^5, x, 13, -(a^3/(4*x)) + (1/4)*a^4*ArcCoth[a*x] - (a^2*ArcCoth[a*x])/(4*x^2) + a^4*ArcCoth[a*x]^2 - (a*ArcCoth[a*x]^2)/(4*x^3) - (3*a^3*ArcCoth[a*x]^2)/(4*x) + (1/4)*a^4*ArcCoth[a*x]^3 - ArcCoth[a*x]^3/(4*x^4) + 2*a^4*ArcCoth[a*x]*Log[(2*a*x)/(1 + a*x)] - a^4*PolyLog[2, -1 + 2/(1 + a*x)]}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m ArcCoth[a+b x]^n*)


{x^3*ArcCoth[a + b*x], x, 6, ((1 + 3*a^2)*x)/(4*b^3) - (a*x^2)/(4*b^2) + x^3/(12*b) + (1/4)*x^4*ArcCoth[a + b*x] + ((1 - a)^4*Log[1 - a - b*x])/(8*b^4) - ((1 + a)^4*Log[1 + a + b*x])/(8*b^4)}
{x^2*ArcCoth[a + b*x], x, 6, -((2*a*x)/(3*b^2)) + x^2/(6*b) + (1/3)*x^3*ArcCoth[a + b*x] + ((1 - a)^3*Log[1 - a - b*x])/(6*b^3) + ((1 + a)^3*Log[1 + a + b*x])/(6*b^3)}
{x*ArcCoth[a + b*x], x, 5, x/(2*b) + (1/2)*x^2*ArcCoth[a + b*x] + ((1 - a)^2*Log[1 - a - b*x])/(4*b^2) - ((1 + a)^2*Log[1 + a + b*x])/(4*b^2)}
{ArcCoth[a + b*x], x, 1, ((a + b*x)*ArcCoth[a + b*x])/b + Log[1 - (a + b*x)^2]/(2*b)}
(* Why does the following integral take so many steps!!! *)
{ArcCoth[a + b*x]/x, x, 13, (1/2)*Log[x]*Log[(1 - a - b*x)/(1 - a)] - (1/2)*Log[x]*Log[(1 + a + b*x)/(1 + a)] - (1/2)*Log[x]*Log[1 - 1/(a + b*x)] + (1/2)*Log[x]*Log[1 + 1/(a + b*x)] + (1/2)*PolyLog[2, (b*x)/(1 - a)] - (1/2)*PolyLog[2, -((b*x)/(1 + a))]}
{ArcCoth[a + b*x]/x^2, x, 6, -(ArcCoth[a + b*x]/x) + (b*Log[x])/(1 - a^2) - (b*Log[1 - a - b*x])/(2*(1 - a)) - (b*Log[1 + a + b*x])/(2*(1 + a))}
{ArcCoth[a + b*x]/x^3, x, 6, -(b/(2*(1 - a^2)*x)) - ArcCoth[a + b*x]/(2*x^2) + (a*b^2*Log[x])/(1 - a^2)^2 - (b^2*Log[1 - a - b*x])/(4*(1 - a)^2) + (b^2*Log[1 + a + b*x])/(4*(1 + a)^2)}


{x^3*ArcCoth[a + b*x]^2, x, 22, -((a*(a + b*x))/b^4) + (a + b*x)^2/(12*b^4) + (3*a*ArcCoth[a + b*x])/(2*b^4) + (x*ArcCoth[a + b*x])/(2*b^3) + (3*a^2*(a + b*x)*ArcCoth[a + b*x])/b^4 - (a*(a + b*x)^2*ArcCoth[a + b*x])/b^4 + ((a + b*x)^3*ArcCoth[a + b*x])/(6*b^4) - ArcCoth[a + b*x]^2/(4*b^4) - (a*ArcCoth[a + b*x]^2)/b^4 - (3*a^2*ArcCoth[a + b*x]^2)/(2*b^4) - (a^3*ArcCoth[a + b*x]^2)/b^4 - (a^3*(a + b*x)*ArcCoth[a + b*x]^2)/b^4 + (3*a^2*(a + b*x)^2*ArcCoth[a + b*x]^2)/(2*b^4) - (a*(a + b*x)^3*ArcCoth[a + b*x]^2)/b^4 + ((a + b*x)^4*ArcCoth[a + b*x]^2)/(4*b^4) + (2*a*ArcCoth[a + b*x]*Log[2/(1 - a - b*x)])/b^4 + (2*a^3*ArcCoth[a + b*x]*Log[2/(1 - a - b*x)])/b^4 + Log[1 - (a + b*x)^2]/(3*b^4) + (3*a^2*Log[1 - (a + b*x)^2])/(2*b^4) + (a*(1 + a^2)*PolyLog[2, 1 - 2/(1 - a - b*x)])/b^4}
{x^2*ArcCoth[a + b*x]^2, x, 16, (a + b*x)/(3*b^3) - ArcCoth[a + b*x]/(3*b^3) - (2*a*(a + b*x)*ArcCoth[a + b*x])/b^3 + ((a + b*x)^2*ArcCoth[a + b*x])/(3*b^3) + ArcCoth[a + b*x]^2/(3*b^3) + (a*ArcCoth[a + b*x]^2)/b^3 + (a^2*ArcCoth[a + b*x]^2)/b^3 + (a^2*(a + b*x)*ArcCoth[a + b*x]^2)/b^3 - (a*(a + b*x)^2*ArcCoth[a + b*x]^2)/b^3 + ((a + b*x)^3*ArcCoth[a + b*x]^2)/(3*b^3) - (2*ArcCoth[a + b*x]*Log[2/(1 - a - b*x)])/(3*b^3) - (2*a^2*ArcCoth[a + b*x]*Log[2/(1 - a - b*x)])/b^3 - (a*Log[1 - (a + b*x)^2])/b^3 - ((1 + 3*a^2)*PolyLog[2, 1 - 2/(1 - a - b*x)])/(3*b^3)}
{x*ArcCoth[a + b*x]^2, x, 9, ((a + b*x)*ArcCoth[a + b*x])/b^2 - ArcCoth[a + b*x]^2/(2*b^2) - (a*ArcCoth[a + b*x]^2)/b^2 - (a*(a + b*x)*ArcCoth[a + b*x]^2)/b^2 + ((a + b*x)^2*ArcCoth[a + b*x]^2)/(2*b^2) + (2*a*ArcCoth[a + b*x]*Log[2/(1 - a - b*x)])/b^2 + Log[1 - (a + b*x)^2]/(2*b^2) + (a*PolyLog[2, 1 - 2/(1 - a - b*x)])/b^2}
{ArcCoth[a + b*x]^2, x, 5, ArcCoth[a + b*x]^2/b + ((a + b*x)*ArcCoth[a + b*x]^2)/b - (2*ArcCoth[a + b*x]*Log[2/(1 - a - b*x)])/b - PolyLog[2, 1 - 2/(1 - a - b*x)]/b}
{ArcCoth[a + b*x]^2/x, x, -2, (-(2/3))*ArcCoth[a + b*x]^3 - ArcCoth[a + b*x]^2*Log[2/(1 + a + b*x)] + ArcCoth[a + b*x]^2*Log[1 - (Sqrt[(1 - a)/b]*(1 + a + b*x))/(Sqrt[(1 + a)/b]*Sqrt[1 - (a + b*x)^2])] + ArcCoth[a + b*x]^2*Log[1 + (Sqrt[(1 - a)/b]*(1 + a + b*x))/(Sqrt[(1 + a)/b]*Sqrt[1 - (a + b*x)^2])] + 2*ArcCoth[a + b*x]*PolyLog[2, -((Sqrt[(1 - a)/b]*(1 + a + b*x))/(Sqrt[(1 + a)/b]*Sqrt[1 - (a + b*x)^2]))] + 2*ArcCoth[a + b*x]*PolyLog[2, (Sqrt[(1 - a)/b]*(1 + a + b*x))/(Sqrt[(1 + a)/b]*Sqrt[1 - (a + b*x)^2])] + ArcCoth[a + b*x]*PolyLog[2, 1 - 2/(1 + a + b*x)] - 2*PolyLog[3, -((Sqrt[(1 - a)/b]*(1 + a + b*x))/(Sqrt[(1 + a)/b]*Sqrt[1 - (a + b*x)^2]))] - 2*PolyLog[3, (Sqrt[(1 - a)/b]*(1 + a + b*x))/(Sqrt[(1 + a)/b]*Sqrt[1 - (a + b*x)^2])] + (1/2)*PolyLog[3, 1 - 2/(1 + a + b*x)]}
(* {ArcCoth[a + b*x]^2/x^2, x, 0, 0}
{ArcCoth[a + b*x]^2/x^3, x, 0, 0} *)


(* {x^3/ArcCoth[a + b*x], x, 0, 0}
{x^2/ArcCoth[a + b*x], x, 0, 0}
{x/ArcCoth[a + b*x], x, 0, 0}
{1/ArcCoth[a + b*x], x, 0, 0}
{1/(x*ArcCoth[a + b*x]), x, 0, 0}
{1/(x^2*ArcCoth[a + b*x]), x, 0, 0}
{1/(x^3*ArcCoth[a + b*x]), x, 0, 0} *)


(* ::Subsubsection::Closed:: *)
(*Miscellaneous integrands involving inverse hyperbolic cotangents*)


(* Integrands of the form (a+b*x)^m*ArcCoth[a+b*x] where m is an integer *)
{(a + b*x)*ArcCoth[a + b*x], x, 3, (a + b*x)/(2*b) - ArcCoth[a + b*x]/(2*b) + ((a + b*x)^2*ArcCoth[a + b*x])/(2*b)}
{(a + b*x)^2*ArcCoth[a + b*x], x, 4, (a + b*x)^2/(6*b) + ((a + b*x)^3*ArcCoth[a + b*x])/(3*b) + Log[1 - (a + b*x)^2]/(6*b)}
{ArcCoth[1 + x]/(2 + 2*x), x, 5, (1/4)*PolyLog[2, -(1/(1 + x))] - (1/4)*PolyLog[2, 1/(1 + x)]}
{ArcCoth[a + b*x]/(a + b*x), x, 4, PolyLog[2, -(1/(a + b*x))]/(2*b) - PolyLog[2, 1/(a + b*x)]/(2*b)}
{ArcCoth[a + b*x]/(a + b*x)^2, x, 3, -(ArcCoth[a + b*x]/(b*(a + b*x))) - ArcTanh[1 - 2*(a + b*x)^2]/b}


(* Integrands of the form ArcCoth[a+b*x]/Pn where Pn is a polynomial *)
{ArcCoth[x]/(a + b*x), x, 14, -((Log[1 - 1/x]*Log[a + b*x])/(2*b)) + (Log[1 + 1/x]*Log[a + b*x])/(2*b) + (Log[(b*(1 - x))/(a + b)]*Log[a + b*x])/(2*b) - (Log[-((b*(1 + x))/(a - b))]*Log[a + b*x])/(2*b) - PolyLog[2, (a + b*x)/(a - b)]/(2*b) + PolyLog[2, (a + b*x)/(a + b)]/(2*b)}
{ArcCoth[x]/(a + b*x^2), x, 29, (Log[1 - 1/x]*Log[a - Sqrt[-a]*Sqrt[b]*x])/(4*Sqrt[-a]*Sqrt[b]) - (Log[1 + 1/x]*Log[a - Sqrt[-a]*Sqrt[b]*x])/(4*Sqrt[-a]*Sqrt[b]) - (Log[(Sqrt[b]*(1 - x))/(Sqrt[-a] + Sqrt[b])]*Log[a - Sqrt[-a]*Sqrt[b]*x])/(4*Sqrt[-a]*Sqrt[b]) + (Log[-((Sqrt[b]*(1 + x))/(Sqrt[-a] - Sqrt[b]))]*Log[a - Sqrt[-a]*Sqrt[b]*x])/(4*Sqrt[-a]*Sqrt[b]) - (Log[1 - 1/x]*Log[a + Sqrt[-a]*Sqrt[b]*x])/(4*Sqrt[-a]*Sqrt[b]) + (Log[1 + 1/x]*Log[a + Sqrt[-a]*Sqrt[b]*x])/(4*Sqrt[-a]*Sqrt[b]) + (Log[-((Sqrt[b]*(1 - x))/(Sqrt[-a] - Sqrt[b]))]*Log[a + Sqrt[-a]*Sqrt[b]*x])/(4*Sqrt[-a]*Sqrt[b]) - (Log[(Sqrt[b]*(1 + x))/(Sqrt[-a] + Sqrt[b])]*Log[a + Sqrt[-a]*Sqrt[b]*x])/(4*Sqrt[-a]*Sqrt[b]) + PolyLog[2, (Sqrt[-a] - Sqrt[b]*x)/(Sqrt[-a] - Sqrt[b])]/(4*Sqrt[-a]*Sqrt[b]) - PolyLog[2, (Sqrt[-a] - Sqrt[b]*x)/(Sqrt[-a] + Sqrt[b])]/(4*Sqrt[-a]*Sqrt[b]) + PolyLog[2, (Sqrt[-a] + Sqrt[b]*x)/(Sqrt[-a] - Sqrt[b])]/(4*Sqrt[-a]*Sqrt[b]) - PolyLog[2, (Sqrt[-a] + Sqrt[b]*x)/(Sqrt[-a] + Sqrt[b])]/(4*Sqrt[-a]*Sqrt[b])}
{ArcCoth[x]/(a + b*x + c*x^2), x, 29, -((Log[1 - 1/x]*Log[b - Sqrt[b^2 - 4*a*c] + 2*c*x])/(2*Sqrt[b^2 - 4*a*c])) + (Log[1 + 1/x]*Log[b - Sqrt[b^2 - 4*a*c] + 2*c*x])/(2*Sqrt[b^2 - 4*a*c]) + (Log[(2*c*(1 - x))/(b + 2*c - Sqrt[b^2 - 4*a*c])]*Log[b - Sqrt[b^2 - 4*a*c] + 2*c*x])/(2*Sqrt[b^2 - 4*a*c]) - (Log[-((2*c*(1 + x))/(b - 2*c - Sqrt[b^2 - 4*a*c]))]*Log[b - Sqrt[b^2 - 4*a*c] + 2*c*x])/(2*Sqrt[b^2 - 4*a*c]) + (Log[1 - 1/x]*Log[b + Sqrt[b^2 - 4*a*c] + 2*c*x])/(2*Sqrt[b^2 - 4*a*c]) - (Log[1 + 1/x]*Log[b + Sqrt[b^2 - 4*a*c] + 2*c*x])/(2*Sqrt[b^2 - 4*a*c]) - (Log[(2*c*(1 - x))/(b + 2*c + Sqrt[b^2 - 4*a*c])]*Log[b + Sqrt[b^2 - 4*a*c] + 2*c*x])/(2*Sqrt[b^2 - 4*a*c]) + (Log[-((2*c*(1 + x))/(b - 2*c + Sqrt[b^2 - 4*a*c]))]*Log[b + Sqrt[b^2 - 4*a*c] + 2*c*x])/(2*Sqrt[b^2 - 4*a*c]) - PolyLog[2, (b - Sqrt[b^2 - 4*a*c] + 2*c*x)/(b - 2*c - Sqrt[b^2 - 4*a*c])]/(2*Sqrt[b^2 - 4*a*c]) + PolyLog[2, (b - Sqrt[b^2 - 4*a*c] + 2*c*x)/(b + 2*c - Sqrt[b^2 - 4*a*c])]/(2*Sqrt[b^2 - 4*a*c]) + PolyLog[2, (b + Sqrt[b^2 - 4*a*c] + 2*c*x)/(b - 2*c + Sqrt[b^2 - 4*a*c])]/(2*Sqrt[b^2 - 4*a*c]) - PolyLog[2, (b + Sqrt[b^2 - 4*a*c] + 2*c*x)/(b + 2*c + Sqrt[b^2 - 4*a*c])]/(2*Sqrt[b^2 - 4*a*c])}

{ArcCoth[d + e*x]/(a + b*x), x, 13, (Log[a + b*x]*Log[(b*(1 - d - e*x))/(b*(1 - d) + a*e)])/(2*b) - (Log[a + b*x]*Log[(b*(1 + d + e*x))/(b*(1 + d) - a*e)])/(2*b) - (Log[a + b*x]*Log[1 - 1/(d + e*x)])/(2*b) + (Log[a + b*x]*Log[1 + 1/(d + e*x)])/(2*b) - PolyLog[2, -((e*(a + b*x))/(b*(1 + d) - a*e))]/(2*b) + PolyLog[2, (e*(a + b*x))/(b*(1 - d) + a*e)]/(2*b)}
{ArcCoth[d + e*x]/(a + b*x^2), x, 27, (Log[a + Sqrt[-a]*Sqrt[b]*x]*Log[(Sqrt[b]*(1 - d - e*x))/(Sqrt[b]*(1 - d) - Sqrt[-a]*e)])/(4*Sqrt[-a]*Sqrt[b]) - (Log[a - Sqrt[-a]*Sqrt[b]*x]*Log[(Sqrt[b]*(1 - d - e*x))/(Sqrt[b]*(1 - d) + Sqrt[-a]*e)])/(4*Sqrt[-a]*Sqrt[b]) + (Log[a - Sqrt[-a]*Sqrt[b]*x]*Log[(Sqrt[b]*(1 + d + e*x))/(Sqrt[b]*(1 + d) - Sqrt[-a]*e)])/(4*Sqrt[-a]*Sqrt[b]) - (Log[a + Sqrt[-a]*Sqrt[b]*x]*Log[(Sqrt[b]*(1 + d + e*x))/(Sqrt[b]*(1 + d) + Sqrt[-a]*e)])/(4*Sqrt[-a]*Sqrt[b]) + (Log[a - Sqrt[-a]*Sqrt[b]*x]*Log[1 - 1/(d + e*x)])/(4*Sqrt[-a]*Sqrt[b]) - (Log[a + Sqrt[-a]*Sqrt[b]*x]*Log[1 - 1/(d + e*x)])/(4*Sqrt[-a]*Sqrt[b]) - (Log[a - Sqrt[-a]*Sqrt[b]*x]*Log[1 + 1/(d + e*x)])/(4*Sqrt[-a]*Sqrt[b]) + (Log[a + Sqrt[-a]*Sqrt[b]*x]*Log[1 + 1/(d + e*x)])/(4*Sqrt[-a]*Sqrt[b]) + PolyLog[2, -((e*(Sqrt[-a] - Sqrt[b]*x))/(Sqrt[b]*(1 - d) - Sqrt[-a]*e))]/(4*Sqrt[-a]*Sqrt[b]) - PolyLog[2, (e*(Sqrt[-a] - Sqrt[b]*x))/(Sqrt[b]*(1 + d) + Sqrt[-a]*e)]/(4*Sqrt[-a]*Sqrt[b]) + PolyLog[2, -((e*(Sqrt[-a] + Sqrt[b]*x))/(Sqrt[b]*(1 + d) - Sqrt[-a]*e))]/(4*Sqrt[-a]*Sqrt[b]) - PolyLog[2, (e*(Sqrt[-a] + Sqrt[b]*x))/(Sqrt[b]*(1 - d) + Sqrt[-a]*e)]/(4*Sqrt[-a]*Sqrt[b])}
{ArcCoth[d + e*x]/(a + b*x + c*x^2), x, 27, (Log[b - Sqrt[b^2 - 4*a*c] + 2*c*x]*Log[(2*c*(1 - d - e*x))/(2*c*(1 - d) + (b - Sqrt[b^2 - 4*a*c])*e)])/(2*Sqrt[b^2 - 4*a*c]) - (Log[b + Sqrt[b^2 - 4*a*c] + 2*c*x]*Log[(2*c*(1 - d - e*x))/(2*c*(1 - d) + (b + Sqrt[b^2 - 4*a*c])*e)])/(2*Sqrt[b^2 - 4*a*c]) - (Log[b - Sqrt[b^2 - 4*a*c] + 2*c*x]*Log[(2*c*(1 + d + e*x))/(2*c*(1 + d) - (b - Sqrt[b^2 - 4*a*c])*e)])/(2*Sqrt[b^2 - 4*a*c]) + (Log[b + Sqrt[b^2 - 4*a*c] + 2*c*x]*Log[(2*c*(1 + d + e*x))/(2*c*(1 + d) - (b + Sqrt[b^2 - 4*a*c])*e)])/(2*Sqrt[b^2 - 4*a*c]) - (Log[b - Sqrt[b^2 - 4*a*c] + 2*c*x]*Log[1 - 1/(d + e*x)])/(2*Sqrt[b^2 - 4*a*c]) + (Log[b + Sqrt[b^2 - 4*a*c] + 2*c*x]*Log[1 - 1/(d + e*x)])/(2*Sqrt[b^2 - 4*a*c]) + (Log[b - Sqrt[b^2 - 4*a*c] + 2*c*x]*Log[1 + 1/(d + e*x)])/(2*Sqrt[b^2 - 4*a*c]) - (Log[b + Sqrt[b^2 - 4*a*c] + 2*c*x]*Log[1 + 1/(d + e*x)])/(2*Sqrt[b^2 - 4*a*c]) - PolyLog[2, -((e*(b - Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c*(1 + d) - (b - Sqrt[b^2 - 4*a*c])*e))]/(2*Sqrt[b^2 - 4*a*c]) + PolyLog[2, (e*(b - Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c*(1 - d) + (b - Sqrt[b^2 - 4*a*c])*e)]/(2*Sqrt[b^2 - 4*a*c]) + PolyLog[2, -((e*(b + Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c*(1 + d) - (b + Sqrt[b^2 - 4*a*c])*e))]/(2*Sqrt[b^2 - 4*a*c]) - PolyLog[2, (e*(b + Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c*(1 - d) + (b + Sqrt[b^2 - 4*a*c])*e)]/(2*Sqrt[b^2 - 4*a*c])}


(* Integrands of the form ArcCoth[x]^m*(1-x^2)^n where n is an integer *)
{1/((1 - x^2)*ArcCoth[x]), x, 1, Log[ArcCoth[x]]}
{ArcCoth[x]^n/(1 - x^2), x, 1, ArcCoth[x]^(1 + n)/(1 + n)}
{ArcCoth[x]/(1 - x^2)^2, x, 2, -(1/(4*(1 - x^2))) + (x*ArcCoth[x])/(2*(1 - x^2)) + ArcCoth[x]^2/4}
{ArcCoth[x]^2/(1 - x^2)^2, x, 4, x/(4*(1 - x^2)) - ArcCoth[x]/(2*(1 - x^2)) + (x*ArcCoth[x]^2)/(2*(1 - x^2)) + ArcCoth[x]^3/6 + ArcTanh[x]/4}

{1/((a - a*x^2)*(b - 2*b*ArcCoth[x])), x, 3, -(Log[1 - 2*ArcCoth[x]]/(2*a*b))}


{(x*ArcCoth[x])/(1 - x^2), x, 3, (-(1/2))*ArcCoth[x]^2 + ArcCoth[x]*Log[2/(1 - x)] + (1/2)*PolyLog[2, 1 - 2/(1 - x)]}
{(x*ArcCoth[x])/(1 - x^2)^2, x, 3, -(x/(4*(1 - x^2))) + ArcCoth[x]/(2*(1 - x^2)) - ArcTanh[x]/4}
{(x*ArcCoth[x])/(1 - x^2)^3, x, 4, -(x/(16*(1 - x^2)^2)) - (3*x)/(32*(1 - x^2)) + ArcCoth[x]/(4*(1 - x^2)^2) - (3*ArcTanh[x])/32}


(* Integrands of the form ArcCoth[x]/(a+b*x^2)^n where n is a half-integer *)
{ArcCoth[x]/(a + b*x^2)^(3/2), x, 3, (x*ArcCoth[x])/(a*Sqrt[a + b*x^2]) - ArcTanh[Sqrt[a + b*x^2]/Sqrt[a + b]]/(a*Sqrt[a + b])}
{ArcCoth[x]/(a + b*x^2)^(5/2), x, 8, 1/(3*a*(a + b)*Sqrt[a + b*x^2]) + (x*(3*a + 2*b*x^2)*ArcCoth[x])/(3*a^2*(a + b*x^2)^(3/2)) - ((3*a + 2*b)*ArcTanh[Sqrt[a + b*x^2]/Sqrt[a + b]])/(3*a^2*(a + b)^(3/2))}
{ArcCoth[x]/(a + b*x^2)^(7/2), x, 8, 1/(15*a*(a + b)*(a + b*x^2)^(3/2)) + (7*a + 4*b)/(15*a^2*(a + b)^2*Sqrt[a + b*x^2]) + (x*(8*(a + b*x^2)^2 + a*(7*a + 4*b*x^2))*ArcCoth[x])/(15*a^3*(a + b*x^2)^(5/2)) - ((15*a^2 + 20*a*b + 8*b^2)*ArcTanh[Sqrt[a + b*x^2]/Sqrt[a + b]])/(15*a^3*(a + b)^(5/2))}

{ArcCoth[x]*(a - a*x^2)^(1/2), x, 3, (1/2)*Sqrt[a - a*x^2] + (1/2)*x*Sqrt[a - a*x^2]*ArcCoth[x] - (a*Sqrt[1 - x^2]*(2*ArcCoth[x]*ArcTan[Sqrt[1 - x]/Sqrt[1 + x]] + I*PolyLog[2, -((I*Sqrt[1 - x])/Sqrt[1 + x])] - I*PolyLog[2, (I*Sqrt[1 - x])/Sqrt[1 + x]]))/(2*Sqrt[a - a*x^2])}
{ArcCoth[x]/(a - a*x^2)^(1/2), x, 2, -((Sqrt[1 - x^2]*(2*ArcCoth[x]*ArcTan[Sqrt[1 - x]/Sqrt[1 + x]] + I*PolyLog[2, -((I*Sqrt[1 - x])/Sqrt[1 + x])] - I*PolyLog[2, (I*Sqrt[1 - x])/Sqrt[1 + x]]))/Sqrt[a - a*x^2])}
{ArcCoth[x]/(a - a*x^2)^(3/2), x, 1, -(1/(a*Sqrt[a - a*x^2])) + (x*ArcCoth[x])/(a*Sqrt[a - a*x^2])}
{ArcCoth[x]/(a - a*x^2)^(5/2), x, 2, -(1/(9*a*(a - a*x^2)^(3/2))) - 2/(3*a^2*Sqrt[a - a*x^2]) + (x*ArcCoth[x])/(3*a*(a - a*x^2)^(3/2)) + (2*x*ArcCoth[x])/(3*a^2*Sqrt[a - a*x^2])}
{ArcCoth[x]/(a - a*x^2)^(7/2), x, 3, -(1/(25*a*(a - a*x^2)^(5/2))) - 4/(45*a^2*(a - a*x^2)^(3/2)) - 8/(15*a^3*Sqrt[a - a*x^2]) + (x*ArcCoth[x])/(5*a*(a - a*x^2)^(5/2)) + (4*x*ArcCoth[x])/(15*a^2*(a - a*x^2)^(3/2)) + (8*x*ArcCoth[x])/(15*a^3*Sqrt[a - a*x^2])}


(* Integrands of the form x^m*ArcCoth[Sqrt[x]] where m is an integer *)
{ArcCoth[Sqrt[x]], x, 4, Sqrt[x] + x*ArcCoth[Sqrt[x]] - ArcTanh[Sqrt[x]]}
{x*ArcCoth[Sqrt[x]], x, 5, Sqrt[x]/2 + x^(3/2)/6 + (1/2)*x^2*ArcCoth[Sqrt[x]] - ArcTanh[Sqrt[x]]/2}
{x^2*ArcCoth[Sqrt[x]], x, 6, Sqrt[x]/3 + x^(3/2)/9 + x^(5/2)/15 + (1/3)*x^3*ArcCoth[Sqrt[x]] - ArcTanh[Sqrt[x]]/3}
{ArcCoth[Sqrt[x]]/x, x, 3, PolyLog[2, -(1/Sqrt[x])] - PolyLog[2, 1/Sqrt[x]]}
{ArcCoth[Sqrt[x]]/x^2, x, 4, -(1/Sqrt[x]) - ArcCoth[Sqrt[x]]/x + ArcTanh[Sqrt[x]]}
{ArcCoth[Sqrt[x]]/x^3, x, 5, -(1/(6*x^(3/2))) - 1/(2*Sqrt[x]) - ArcCoth[Sqrt[x]]/(2*x^2) + ArcTanh[Sqrt[x]]/2}

{Sqrt[x]*ArcCoth[Sqrt[x]], x, 5, x/3 + (2/3)*x^(3/2)*ArcCoth[Sqrt[x]] + (1/3)*Log[1 - x]}
{x^(3/2)*ArcCoth[Sqrt[x]], x, 6, x/5 + x^2/10 + (2/5)*x^(5/2)*ArcCoth[Sqrt[x]] + (1/5)*Log[1 - x]}
{ArcCoth[Sqrt[x]]/Sqrt[x], x, 2, 2*Sqrt[x]*ArcCoth[Sqrt[x]] + Log[1 - x]}
{ArcCoth[Sqrt[x]]/x^(3/2), x, 4, -((2*ArcCoth[Sqrt[x]])/Sqrt[x]) - 2*ArcTanh[1 - 2*x]}


(* ::Subsection::Closed:: *)
(*Integrands involving inverse hyperbolic functions of exponentials*)


(* Integrands of the form x^m*ArcCoth[E^x] *)
{ArcCoth[E^x], x, 3, (1/2)*PolyLog[2, -E^(-x)] - (1/2)*PolyLog[2, E^(-x)]}
{x*ArcCoth[E^x], x, 5, (1/2)*x*PolyLog[2, -E^(-x)] - (1/2)*x*PolyLog[2, E^(-x)] + (1/2)*PolyLog[3, -E^(-x)] - (1/2)*PolyLog[3, E^(-x)]}
{x^2*ArcCoth[E^x], x, 7, (1/2)*x^2*PolyLog[2, -E^(-x)] - (1/2)*x^2*PolyLog[2, E^(-x)] + x*PolyLog[3, -E^(-x)] - x*PolyLog[3, E^(-x)] + PolyLog[4, -E^(-x)] - PolyLog[4, E^(-x)]}


(* Integrands of the form x^m*ArcCoth[E^(a+b*x)] *)
{ArcCoth[E^(a + b*x)], x, 3, PolyLog[2, -E^(-a - b*x)]/(2*b) - PolyLog[2, E^(-a - b*x)]/(2*b)}
{x*ArcCoth[E^(a + b*x)], x, 5, (x*PolyLog[2, -E^(-a - b*x)])/(2*b) - (x*PolyLog[2, E^(-a - b*x)])/(2*b) + PolyLog[3, -E^(-a - b*x)]/(2*b^2) - PolyLog[3, E^(-a - b*x)]/(2*b^2)}
{x^2*ArcCoth[E^(a + b*x)], x, 7, (x^2*PolyLog[2, -E^(-a - b*x)])/(2*b) - (x^2*PolyLog[2, E^(-a - b*x)])/(2*b) + (x*PolyLog[3, -E^(-a - b*x)])/b^2 - (x*PolyLog[3, E^(-a - b*x)])/b^2 + PolyLog[4, -E^(-a - b*x)]/b^3 - PolyLog[4, E^(-a - b*x)]/b^3}


(* Integrands of the form x^m*ArcCoth[a+b*f^(c+d*x)] *)
{ArcCoth[a + b*f^(c + d*x)], x, 10, x*ArcCoth[a + b*f^(c + d*x)] + (1/2)*x*Log[1 - (b*f^(c + d*x))/(1 - a)] - (1/2)*x*Log[1 + (b*f^(c + d*x))/(1 + a)] + PolyLog[2, (b*f^(c + d*x))/(1 - a)]/(2*d*Log[f]) - PolyLog[2, -((b*f^(c + d*x))/(1 + a))]/(2*d*Log[f])}
{x*ArcCoth[a + b*f^(c + d*x)], x, 12, (1/2)*x^2*ArcCoth[a + b*f^(c + d*x)] + (1/4)*x^2*Log[1 - (b*f^(c + d*x))/(1 - a)] - (1/4)*x^2*Log[1 + (b*f^(c + d*x))/(1 + a)] + (x*PolyLog[2, (b*f^(c + d*x))/(1 - a)])/(2*d*Log[f]) - (x*PolyLog[2, -((b*f^(c + d*x))/(1 + a))])/(2*d*Log[f]) - PolyLog[3, (b*f^(c + d*x))/(1 - a)]/(2*d^2*Log[f]^2) + PolyLog[3, -((b*f^(c + d*x))/(1 + a))]/(2*d^2*Log[f]^2)}
{x^2*ArcCoth[a + b*f^(c + d*x)], x, 14, (1/3)*x^3*ArcCoth[a + b*f^(c + d*x)] + (1/6)*x^3*Log[1 - (b*f^(c + d*x))/(1 - a)] - (1/6)*x^3*Log[1 + (b*f^(c + d*x))/(1 + a)] + (x^2*PolyLog[2, (b*f^(c + d*x))/(1 - a)])/(2*d*Log[f]) - (x^2*PolyLog[2, -((b*f^(c + d*x))/(1 + a))])/(2*d*Log[f]) - (x*PolyLog[3, (b*f^(c + d*x))/(1 - a)])/(d^2*Log[f]^2) + (x*PolyLog[3, -((b*f^(c + d*x))/(1 + a))])/(d^2*Log[f]^2) + PolyLog[4, (b*f^(c + d*x))/(1 - a)]/(d^3*Log[f]^3) - PolyLog[4, -((b*f^(c + d*x))/(1 + a))]/(d^3*Log[f]^3)}


(* ::Subsection::Closed:: *)
(*Integrands involving inverse hyperbolic functions of hyperbolic functions*)


(* Integrands of the form ArcCoth[a+b*Hyper[x]] *)
{ArcCoth[Tanh[x]], x, 2, -(x^2/2) + x*ArcCoth[Tanh[x]]}
{ArcCoth[b*Tanh[x]], x, 12, x*ArcCoth[b*Tanh[x]] - (1/2)*x*Log[1 + ((1 - b^2)*E^(2*x))/(1 - 2*b + b^2)] + (1/2)*x*Log[1 + ((1 - b^2)*E^(2*x))/(1 + 2*b + b^2)] - (1/4)*PolyLog[2, -(((1 - b^2)*E^(2*x))/(1 - 2*b + b^2))] + (1/4)*PolyLog[2, -(((1 - b^2)*E^(2*x))/(1 + 2*b + b^2))]}
(* {ArcCoth[a+b*Tanh[x]], x, 30, (-(1/4))*Log[-1 + Tanh[x]]*Log[(1 - a - b*Tanh[x])/(1 - a - b)] + (1/4)*Log[1 + Tanh[x]]*Log[(1 - a - b*Tanh[x])/(1 - a + b)] - (1/4)*Log[1 + Tanh[x]]*Log[(1 + a + b*Tanh[x])/(1 + a - b)] + (1/4)*Log[-1 + Tanh[x]]*Log[(1 + a + b*Tanh[x])/(1 + a + b)] + (1/4)*Log[-1 + Tanh[x]]*Log[1 - 1/(a + b*Tanh[x])] - (1/4)*Log[1 + Tanh[x]]*Log[1 - 1/(a + b*Tanh[x])] - (1/4)*Log[-1 + Tanh[x]]*Log[1 + 1/(a + b*Tanh[x])] + (1/4)*Log[1 + Tanh[x]]*Log[1 + 1/(a + b*Tanh[x])] - (1/4)*PolyLog[2, -((b*(1 - Tanh[x]))/(1 - a - b))] + (1/4)*PolyLog[2, (b*(1 - Tanh[x]))/(1 + a + b)] - (1/4)*PolyLog[2, -((b*(1 + Tanh[x]))/(1 + a - b))] + (1/4)*PolyLog[2, (b*(1 + Tanh[x]))/(1 - a + b)]} *)

{ArcCoth[b*Coth[x]], x, 12, x*ArcCoth[b*Coth[x]] - (1/2)*x*Log[1 - ((1 - b^2)*E^(2*x))/(1 - 2*b + b^2)] + (1/2)*x*Log[1 - ((1 - b^2)*E^(2*x))/(1 + 2*b + b^2)] - (1/4)*PolyLog[2, ((1 - b^2)*E^(2*x))/(1 - 2*b + b^2)] + (1/4)*PolyLog[2, ((1 - b^2)*E^(2*x))/(1 + 2*b + b^2)]}
(* {ArcCoth[a+b*Coth[x]], x, 30, (-(1/4))*Log[-1 + Coth[x]]*Log[(1 - a - b*Coth[x])/(1 - a - b)] + (1/4)*Log[1 + Coth[x]]*Log[(1 - a - b*Coth[x])/(1 - a + b)] - (1/4)*Log[1 + Coth[x]]*Log[(1 + a + b*Coth[x])/(1 + a - b)] + (1/4)*Log[-1 + Coth[x]]*Log[(1 + a + b*Coth[x])/(1 + a + b)] + (1/4)*Log[-1 + Coth[x]]*Log[1 - 1/(a + b*Coth[x])] - (1/4)*Log[1 + Coth[x]]*Log[1 - 1/(a + b*Coth[x])] - (1/4)*Log[-1 + Coth[x]]*Log[1 + 1/(a + b*Coth[x])] + (1/4)*Log[1 + Coth[x]]*Log[1 + 1/(a + b*Coth[x])] - (1/4)*PolyLog[2, -((b*(1 - Coth[x]))/(1 - a - b))] + (1/4)*PolyLog[2, (b*(1 - Coth[x]))/(1 + a + b)] - (1/4)*PolyLog[2, -((b*(1 + Coth[x]))/(1 + a - b))] + (1/4)*PolyLog[2, (b*(1 + Coth[x]))/(1 - a + b)]} *)


(* Integrands of the form x^m*ArcCoth[Sinh[x]] where m is an integer *)
(* {ArcCoth[Sinh[x]], x, 6, 0}
{x*ArcCoth[Sinh[x]], x, 8, 0}
{x^2*ArcCoth[Sinh[x]], x, 10, 0} *)


(* Integrands of the form x^m*ArcCoth[Cosh[x]] where m is an integer *)
{ArcCoth[Cosh[x]], x, 6, x*ArcCoth[Cosh[x]] - 2*x*ArcTanh[E^x] - PolyLog[2, -E^x] + PolyLog[2, E^x]}
{x*ArcCoth[Cosh[x]], x, 8, (1/2)*x^2*ArcCoth[Cosh[x]] - x^2*ArcTanh[E^x] - x*PolyLog[2, -E^x] + x*PolyLog[2, E^x] + PolyLog[3, -E^x] - PolyLog[3, E^x]}
{x^2*ArcCoth[Cosh[x]], x, 10, (1/3)*x^3*ArcCoth[Cosh[x]] - (2/3)*x^3*ArcTanh[E^x] - x^2*PolyLog[2, -E^x] + x^2*PolyLog[2, E^x] + 2*x*PolyLog[3, -E^x] - 2*x*PolyLog[3, E^x] - 2*PolyLog[4, -E^x] + 2*PolyLog[4, E^x]}


(* ::Subsection::Closed:: *)
(*Integrands involving exponentials of arccotangents*)


(* ::Subsubsection::Closed:: *)
(*Products of monomials and exponentials of inverse cotangents*)


{x^2*E^ArcCoth[x], x, 6, (2/3)*Sqrt[1 - 1/x^2]*x + (1/2)*Sqrt[1 - 1/x^2]*x^2 + (1/3)*Sqrt[1 - 1/x^2]*x^3 + (1/2)*ArcTanh[Sqrt[1 - 1/x^2]]}
{x*E^ArcCoth[x], x, 5, Sqrt[1 - 1/x^2]*x + (1/2)*Sqrt[1 - 1/x^2]*x^2 + (1/2)*ArcTanh[Sqrt[1 - 1/x^2]]}
{E^ArcCoth[x], x, 4, Sqrt[1 - 1/x^2]*x + ArcTanh[Sqrt[1 - 1/x^2]]}
{E^ArcCoth[x]/x, x, 5, -ArcCsc[x] + ArcTanh[Sqrt[1 - 1/x^2]]}
{E^ArcCoth[x]/x^2, x, 6, Sqrt[1 - 1/x^2] - ArcCsc[x]}
{E^ArcCoth[x]/x^3, x, 7, Sqrt[1 - 1/x^2] + Sqrt[1 - 1/x^2]/(2*x) - ArcCsc[x]/2}


{x^2*E^(2*ArcCoth[x]), x, 5, 2*x + x^2 + x^3/3 + 2*Log[1 - x]}
{x*E^(2*ArcCoth[x]), x, 5, 2*x + x^2/2 + 2*Log[1 - x]}
{E^(2*ArcCoth[x]), x, 4, x + 2*Log[1 - x]}
{E^(2*ArcCoth[x])/x, x, 5, 2*Log[1 - x] - Log[x]}
{E^(2*ArcCoth[x])/x^2, x, 5, 1/x + 4*ArcTanh[1 - 2*x]}
{E^(2*ArcCoth[x])/x^3, x, 5, 1/(2*x^2) + 2/x + 4*ArcTanh[1 - 2*x]}


{x^2*E^(3*ArcCoth[x]), x, 12, -(1/Sqrt[1 - 1/x^2]) - (3*x)/Sqrt[1 - 1/x^2] + (26/3)*Sqrt[1 - 1/x^2]*x - (3*x^2)/Sqrt[1 - 1/x^2] + (9/2)*Sqrt[1 - 1/x^2]*x^2 - x^3/Sqrt[1 - 1/x^2] + (4/3)*Sqrt[1 - 1/x^2]*x^3 + (11/2)*ArcTanh[Sqrt[1 - 1/x^2]]}
{x*E^(3*ArcCoth[x]), x, 10, -(3/Sqrt[1 - 1/x^2]) - 1/(Sqrt[1 - 1/x^2]*x) - (3*x)/Sqrt[1 - 1/x^2] + 6*Sqrt[1 - 1/x^2]*x - x^2/Sqrt[1 - 1/x^2] + (3/2)*Sqrt[1 - 1/x^2]*x^2 + (9/2)*ArcTanh[Sqrt[1 - 1/x^2]]}
{E^(3*ArcCoth[x]), x, 9, -(4/Sqrt[1 - 1/x^2]) - 3/(Sqrt[1 - 1/x^2]*x) - x/Sqrt[1 - 1/x^2] + 2*Sqrt[1 - 1/x^2]*x + 3*ArcTanh[Sqrt[1 - 1/x^2]]}
{E^(3*ArcCoth[x])/x, x, 10, -(4/Sqrt[1 - 1/x^2]) - 4/(Sqrt[1 - 1/x^2]*x) + ArcCsc[x] + ArcTanh[Sqrt[1 - 1/x^2]]}
{E^(3*ArcCoth[x])/x^2, x, 11, -(3/Sqrt[1 - 1/x^2]) - 2*Sqrt[1 - 1/x^2] - 1/(Sqrt[1 - 1/x^2]*x^2) - 4/(Sqrt[1 - 1/x^2]*x) + 3*ArcCsc[x]}
{E^(3*ArcCoth[x])/x^3, x, 14, -7*Sqrt[(-1 + x^2)/x^2] - (4*Sqrt[(-1 + x^2)/x^2])/(-1 + x) - Sqrt[(-1 + x^2)/x^2]/(2*x) + (9*ArcCsc[x])/2, -(1/Sqrt[1 - 1/x^2]) - 6*Sqrt[1 - 1/x^2] - 1/(Sqrt[1 - 1/x^2]*x^3) - 3/(Sqrt[1 - 1/x^2]*x^2) - 3/(Sqrt[1 - 1/x^2]*x) - (3*Sqrt[1 - 1/x^2])/(2*x) + (9*ArcCsc[x])/2}


{x^2*E^(4*ArcCoth[x]), x, 6, 4/(1 - x) + 8*x + 2*x^2 + x^3/3 + 12*Log[1 - x]}
{x*E^(4*ArcCoth[x]), x, 6, 4/(1 - x) + 4*x + x^2/2 + 8*Log[1 - x]}
{E^(4*ArcCoth[x]), x, 5, 4/(1 - x) + x + 4*Log[1 - x]}
{E^(4*ArcCoth[x])/x, x, 5, 4/(1 - x) + Log[x]}
{E^(4*ArcCoth[x])/x^2, x, 7, 4/(1 - x) - 1/x - 8*ArcTanh[1 - 2*x]}
{E^(4*ArcCoth[x])/x^3, x, 7, 4/(1 - x) - 1/(2*x^2) - 4/x - 16*ArcTanh[1 - 2*x]}


{x^3*E^(ArcCoth[x]/2), x, 34, (-(83/192))*E^(ArcCoth[x]/2) + (25/192)*E^(ArcCoth[x]/2)*x + (1/96)*E^(ArcCoth[x]/2)*x^2 + (1/24)*E^(ArcCoth[x]/2)*x^3 + (1/4)*E^(ArcCoth[x]/2)*x^4 + (11/64)*ArcTan[E^(ArcCoth[x]/2)] + (11/64)*ArcTanh[E^(ArcCoth[x]/2)], (-(23/64))*E^(ArcCoth[x]/2) + (1/96)*E^(ArcCoth[x]/2)*(1 - x)^2 + (1/24)*E^((5*ArcCoth[x])/2)*(1 - x)^2 - (1/48)*E^(ArcCoth[x]/2)*(1 - x)^3 - (1/48)*E^((9*ArcCoth[x])/2)*(1 - x)^3 + (7/64)*E^(ArcCoth[x]/2)*x + (1/4)*E^(ArcCoth[x]/2)*x^4 + (11/64)*ArcTan[E^(ArcCoth[x]/2)] + (11/64)*ArcTanh[E^(ArcCoth[x]/2)]}
{x^2*E^(ArcCoth[x]/2), x, 24, (-(11/24))*E^(ArcCoth[x]/2) + (1/24)*E^(ArcCoth[x]/2)*x + (1/12)*E^(ArcCoth[x]/2)*x^2 + (1/3)*E^(ArcCoth[x]/2)*x^3 + (3/8)*ArcTan[E^(ArcCoth[x]/2)] + (3/8)*ArcTanh[E^(ArcCoth[x]/2)], (-(31/72))*E^(ArcCoth[x]/2) + (1/36)*E^(ArcCoth[x]/2)*(1 - x)^2 + (1/18)*E^((5*ArcCoth[x])/2)*(1 - x)^2 + (7/72)*E^(ArcCoth[x]/2)*x + (1/3)*E^(ArcCoth[x]/2)*x^3 + (3/8)*ArcTan[E^(ArcCoth[x]/2)] + (3/8)*ArcTanh[E^(ArcCoth[x]/2)]}
{x*E^(ArcCoth[x]/2), x, 15, (-(3/4))*E^(ArcCoth[x]/2) + (1/4)*E^(ArcCoth[x]/2)*x + (1/2)*E^(ArcCoth[x]/2)*x^2 + (1/4)*ArcTan[E^(ArcCoth[x]/2)] + (1/4)*ArcTanh[E^(ArcCoth[x]/2)]}
{E^(ArcCoth[x]/2), x, 7, -E^(ArcCoth[x]/2) + E^(ArcCoth[x]/2)*x + ArcTan[E^(ArcCoth[x]/2)] + ArcTanh[E^(ArcCoth[x]/2)]}
{E^(ArcCoth[x]/2)/x, x, 13, 2*ArcTan[E^(ArcCoth[x]/2)] + Sqrt[2]*ArcTan[1 - Sqrt[2]*E^(ArcCoth[x]/2)] - Sqrt[2]*ArcTan[1 + Sqrt[2]*E^(ArcCoth[x]/2)] + 2*ArcTanh[E^(ArcCoth[x]/2)] + Log[1 - Sqrt[2]*E^(ArcCoth[x]/2) + E^ArcCoth[x]]/Sqrt[2] - Log[1 + Sqrt[2]*E^(ArcCoth[x]/2) + E^ArcCoth[x]]/Sqrt[2]}
{E^(ArcCoth[x]/2)/x^2, x, 10, -((E^(ArcCoth[x]/2)*(1 - x))/x) + ArcTan[1 - Sqrt[2]*E^(ArcCoth[x]/2)]/Sqrt[2] - ArcTan[1 + Sqrt[2]*E^(ArcCoth[x]/2)]/Sqrt[2] + Log[1 - Sqrt[2]*E^(ArcCoth[x]/2) + E^ArcCoth[x]]/(2*Sqrt[2]) - Log[1 + Sqrt[2]*E^(ArcCoth[x]/2) + E^ArcCoth[x]]/(2*Sqrt[2])}
{E^(ArcCoth[x]/2)/x^3, x, 13, (E^(ArcCoth[x]/2)*(1 - x)^2)/(6*x^2) + (2*E^((5*ArcCoth[x])/2)*(1 - x)^2)/(3*x^2) + (E^(ArcCoth[x]/2)*(1 - x))/(12*x) + ArcTan[1 - Sqrt[2]*E^(ArcCoth[x]/2)]/(4*Sqrt[2]) - ArcTan[1 + Sqrt[2]*E^(ArcCoth[x]/2)]/(4*Sqrt[2]) + Log[1 - Sqrt[2]*E^(ArcCoth[x]/2) + E^ArcCoth[x]]/(8*Sqrt[2]) - Log[1 + Sqrt[2]*E^(ArcCoth[x]/2) + E^ArcCoth[x]]/(8*Sqrt[2])}


{x^2*E^(ArcCoth[a+b*x]/2), x, 46, -((31*E^((1/2)*ArcCoth[a + b*x]))/(72*b^3)) + (115*a*E^((1/2)*ArcCoth[a + b*x]))/(72*b^3) - (3*a^2*E^((1/2)*ArcCoth[a + b*x]))/(2*b^3) + (a^3*E^((1/2)*ArcCoth[a + b*x]))/(3*b^3) + (7*E^((1/2)*ArcCoth[a + b*x])*x)/(72*b^2) - (a*E^((1/2)*ArcCoth[a + b*x])*x)/(2*b^2) + (1/3)*E^((1/2)*ArcCoth[a + b*x])*x^3 + (E^((1/2)*ArcCoth[a + b*x])*(1 - a - b*x)^2)/(36*b^3) + (E^((5/2)*ArcCoth[a + b*x])*(1 - a - b*x)^2)/(18*b^3) + (3*ArcTan[E^((1/2)*ArcCoth[a + b*x])])/(8*b^3) - (a*ArcTan[E^((1/2)*ArcCoth[a + b*x])])/(2*b^3) + (a^2*ArcTan[E^((1/2)*ArcCoth[a + b*x])])/b^3 + (3*ArcTanh[E^((1/2)*ArcCoth[a + b*x])])/(8*b^3) - (a*ArcTanh[E^((1/2)*ArcCoth[a + b*x])])/(2*b^3) + (a^2*ArcTanh[E^((1/2)*ArcCoth[a + b*x])])/b^3}
{x*E^(ArcCoth[a+b*x]/2), x, 24, -((3*E^((1/2)*ArcCoth[a + b*x]))/(4*b^2)) + (5*a*E^((1/2)*ArcCoth[a + b*x]))/(4*b^2) - (a^2*E^((1/2)*ArcCoth[a + b*x]))/(2*b^2) + (E^((1/2)*ArcCoth[a + b*x])*x)/(4*b) + (1/2)*E^((1/2)*ArcCoth[a + b*x])*x^2 + ArcTan[E^((1/2)*ArcCoth[a + b*x])]/(4*b^2) - (a*ArcTan[E^((1/2)*ArcCoth[a + b*x])])/b^2 + ArcTanh[E^((1/2)*ArcCoth[a + b*x])]/(4*b^2) - (a*ArcTanh[E^((1/2)*ArcCoth[a + b*x])])/b^2}
{E^(ArcCoth[a+b*x]/2), x, 11, -(E^((1/2)*ArcCoth[a + b*x])/b) + (a*E^((1/2)*ArcCoth[a + b*x]))/b + E^((1/2)*ArcCoth[a + b*x])*x + ArcTan[E^((1/2)*ArcCoth[a + b*x])]/b + ArcTanh[E^((1/2)*ArcCoth[a + b*x])]/b}


(* ::Subsubsection::Closed:: *)
(*Products of exponentials of inverse cotangents and powers of linear binomials*)


{E^ArcCoth[x]*(1 - x)^2, x, 17, (-(1/3))*Sqrt[1 - 1/x^2]*x - (1/2)*Sqrt[1 - 1/x^2]*x^2 + (1/3)*Sqrt[1 - 1/x^2]*x^3 + (1/2)*ArcTanh[Sqrt[1 - 1/x^2]]}
{E^ArcCoth[x]*(1 - x), x, 11, (-(1/2))*Sqrt[1 - 1/x^2]*x^2 + (1/2)*ArcTanh[Sqrt[1 - 1/x^2]]}
{E^ArcCoth[x]/(1 - x), x, 7, 2*E^ArcCoth[x] - 2*ArcTanh[E^ArcCoth[x]]}
{E^ArcCoth[x]/(1 - x)^2, x, 5, (-(1/3))*E^(3*ArcCoth[x])}
{E^ArcCoth[x]/(1 - x)^3, x, 7, (-(1/6))*E^(3*ArcCoth[x]) + (1/10)*E^(5*ArcCoth[x])}
{E^ArcCoth[x]/(1 - x)^4, x, 7, (-(1/12))*E^(3*ArcCoth[x]) + (1/10)*E^(5*ArcCoth[x]) - (1/28)*E^(7*ArcCoth[x])}


{E^ArcCoth[x]*(1 + x)^2, x, 17, (11/3)*Sqrt[1 - 1/x^2]*x + (3/2)*Sqrt[1 - 1/x^2]*x^2 + (1/3)*Sqrt[1 - 1/x^2]*x^3 + (5/2)*ArcTanh[Sqrt[1 - 1/x^2]]}
{E^ArcCoth[x]*(1 + x), x, 11, 2*Sqrt[1 - 1/x^2]*x + (1/2)*Sqrt[1 - 1/x^2]*x^2 + (3/2)*ArcTanh[Sqrt[1 - 1/x^2]]}
{E^ArcCoth[x]/(1 + x), x, 5, 2*ArcTanh[E^ArcCoth[x]]}
{E^ArcCoth[x]/(1 + x)^2, x, 4, E^(-ArcCoth[x])}
{E^ArcCoth[x]/(1 + x)^3, x, 5, -(1/6)/E^(3*ArcCoth[x]) + 1/2/E^ArcCoth[x]}
{E^ArcCoth[x]/(1 + x)^4, x, 6, 1/20/E^(5*ArcCoth[x]) - 1/6/E^(3*ArcCoth[x]) + 1/4/E^ArcCoth[x]}


(* ::Subsubsection::Closed:: *)
(*Products of exponentials of inverse cotangents and powers of quadratic binomials*)


{E^ArcCoth[x]*(a - a*x^2)^3, x, 19, (-(4/21))*a^3*Sqrt[1 - 1/x^2]*x - (11/16)*a^3*Sqrt[1 - 1/x^2]*x^2 - (2/21)*a^3*Sqrt[1 - 1/x^2]*x^3 - (1/3)*a^3*(1 - 1/x^2)^(3/2)*x^3 + (13/24)*a^3*Sqrt[1 - 1/x^2]*x^4 + (3/7)*a^3*Sqrt[1 - 1/x^2]*x^5 - (1/6)*a^3*Sqrt[1 - 1/x^2]*x^6 - (1/7)*a^3*Sqrt[1 - 1/x^2]*x^7 + (5/16)*a^3*ArcTanh[Sqrt[1 - 1/x^2]]}
{E^ArcCoth[x]*(a - a*x^2)^2, x, 11, (-(2/15))*a^2*Sqrt[1 - 1/x^2]*x - (5/8)*a^2*Sqrt[1 - 1/x^2]*x^2 - (1/15)*a^2*Sqrt[1 - 1/x^2]*x^3 - (1/3)*a^2*(1 - 1/x^2)^(3/2)*x^3 + (1/4)*a^2*Sqrt[1 - 1/x^2]*x^4 + (1/5)*a^2*Sqrt[1 - 1/x^2]*x^5 + (3/8)*a^2*ArcTanh[Sqrt[1 - 1/x^2]]}
{E^ArcCoth[x]*(a - a*x^2)^1, x, 5, (-(1/2))*a*Sqrt[1 - 1/x^2]*x^2 - (1/3)*a*(1 - 1/x^2)^(3/2)*x^3 + (1/2)*a*ArcTanh[Sqrt[1 - 1/x^2]]}
{E^ArcCoth[x]/(a - a*x^2)^1, x, 2, E^ArcCoth[x]/a}
{E^ArcCoth[x]/(a - a*x^2)^2, x, 4, (2*E^ArcCoth[x])/(3*a^2) - E^ArcCoth[x]/(3*a^2*(1 - x^2)) + (2*E^ArcCoth[x]*x)/(3*a^2*(1 - x^2))}
{E^ArcCoth[x]/(a - a*x^2)^3, x, 4, (8*E^ArcCoth[x])/(15*a^3) - E^ArcCoth[x]/(15*a^3*(1 - x^2)^2) + (4*E^ArcCoth[x]*x)/(15*a^3*(1 - x^2)^2) - (4*E^ArcCoth[x])/(15*a^3*(1 - x^2)) + (8*E^ArcCoth[x]*x)/(15*a^3*(1 - x^2))}
{E^ArcCoth[x]/(a - a*x^2)^4, x, 6, (16*E^ArcCoth[x])/(35*a^4) - E^ArcCoth[x]/(35*a^4*(1 - x^2)^3) + (6*E^ArcCoth[x]*x)/(35*a^4*(1 - x^2)^3) - (2*E^ArcCoth[x])/(35*a^4*(1 - x^2)^2) + (8*E^ArcCoth[x]*x)/(35*a^4*(1 - x^2)^2) - (8*E^ArcCoth[x])/(35*a^4*(1 - x^2)) + (16*E^ArcCoth[x]*x)/(35*a^4*(1 - x^2))}


{E^ArcCoth[x]*(1 - x^2)^(7/2), x, 5, -((Sqrt[1 - 1/x^2]*(28 + 30*(1 - x)^2 + 35*(1 - x)^3 - 20*x)*x*(1 + x)^5)/(280*Sqrt[1 - x^2]))}
{E^ArcCoth[x]*(1 - x^2)^(5/2), x, 4, -((Sqrt[1 - 1/x^2]*(6 + 5*(1 - x)^2 - 4*x)*x*(1 + x)^4)/(30*Sqrt[1 - x^2]))}
{E^ArcCoth[x]*(1 - x^2)^(3/2), x, 3, -((Sqrt[1 - 1/x^2]*(5 - 3*x)*x*(1 + x)^3)/(12*Sqrt[1 - x^2]))}
{E^ArcCoth[x]*(1 - x^2)^(1/2), x, 2, -((Sqrt[1 - 1/x^2]*x^2*(2 + x))/(2*Sqrt[1 - x^2]))}
{E^ArcCoth[x]/(1 - x^2)^(1/2), x, 2, (Sqrt[1 - 1/x^2]*x*Log[1 - x])/Sqrt[1 - x^2]}
{E^ArcCoth[x]/(1 - x^2)^(3/2), x, 5, -((Sqrt[1 - 1/x^2]*x*(1/(1 - x) + ArcTanh[x]))/(2*Sqrt[1 - x^2]))}
{E^ArcCoth[x]/(1 - x^2)^(5/2), x, 7, -((Sqrt[1 - 1/x^2]*x*(1/(1 - x)^2 + 2/(1 - x) - 1/(1 + x) + 3*ArcTanh[x]))/(8*Sqrt[1 - x^2]))}
{E^ArcCoth[x]/(1 - x^2)^(7/2), x, 9, -((Sqrt[1 - 1/x^2]*x*(4/(1 - x)^3 + 9/(1 - x)^2 + 18/(1 - x) - 3/(1 + x)^2 - 12/(1 + x) + 30*ArcTanh[x]))/(96*Sqrt[1 - x^2]))}


{E^ArcCoth[x]*(a - a*x^2)^(7/2), x, 6, -(((28 + 30*(1 - x)^2 + 35*(1 - x)^3 - 20*x)*(1 + x)^5*(a - a*x^2)^(7/2))/(280*(1 - 1/x^2)^(7/2)*x^7))}
{E^ArcCoth[x]*(a - a*x^2)^(5/2), x, 5, ((6 + 5*(1 - x)^2 - 4*x)*(1 + x)^4*(a - a*x^2)^(5/2))/(30*(1 - 1/x^2)^(5/2)*x^5)}
{E^ArcCoth[x]*(a - a*x^2)^(3/2), x, 4, -(((5 - 3*x)*(1 + x)^3*(a - a*x^2)^(3/2))/(12*(1 - 1/x^2)^(3/2)*x^3))}
{E^ArcCoth[x]*(a - a*x^2)^(1/2), x, 3, ((2 + x)*Sqrt[a - a*x^2])/(2*Sqrt[1 - 1/x^2])}
{E^ArcCoth[x]/(a - a*x^2)^(1/2), x, 3, (Sqrt[1 - 1/x^2]*x*Log[1 - x])/Sqrt[a - a*x^2]}
{E^ArcCoth[x]/(a - a*x^2)^(3/2), x, 6, ((1 - 1/x^2)^(3/2)*x^3*(1/(1 - x) + ArcTanh[x]))/(2*(a - a*x^2)^(3/2))}
{E^ArcCoth[x]/(a - a*x^2)^(5/2), x, 8, -(((1 - 1/x^2)^(5/2)*x^5*(1/(1 - x)^2 + 2/(1 - x) - 1/(1 + x) + 3*ArcTanh[x]))/(8*(a - a*x^2)^(5/2)))}
{E^ArcCoth[x]/(a - a*x^2)^(7/2), x, 10, ((1 - 1/x^2)^(7/2)*x^7*(4/(1 - x)^3 + 9/(1 - x)^2 + 18/(1 - x) - 3/(1 + x)^2 - 12/(1 + x) + 30*ArcTanh[x]))/(96*(a - a*x^2)^(7/2))}


(* ::Subsubsection::Closed:: *)
(*Products of exponentials of inverse cotangents and powers of inverse quadratic binomials*)


{E^ArcCoth[x]*(1 - 1/x^2), x, 7, -Sqrt[1 - 1/x^2] + Sqrt[1 - 1/x^2]*x + ArcCsc[x] + ArcTanh[Sqrt[1 - 1/x^2]]}
{E^ArcCoth[x]*(1 - 1/x^2)^2, x, 12, -Sqrt[1 - 1/x^2] - (1/3)*(1 - 1/x^2)^(3/2) + Sqrt[1 - 1/x^2]/(2*x) + Sqrt[1 - 1/x^2]*x + (3*ArcCsc[x])/2 + ArcTanh[Sqrt[1 - 1/x^2]]}
{E^ArcCoth[x]*(1 - 1/x^2)^3, x, 19, -Sqrt[1 - 1/x^2] - (8/15)*(1 - 1/x^2)^(3/2) - Sqrt[1 - 1/x^2]/(4*x^3) + (1 - 1/x^2)^(3/2)/(5*x^2) + (9*Sqrt[1 - 1/x^2])/(8*x) + Sqrt[1 - 1/x^2]*x + (15*ArcCsc[x])/8 + ArcTanh[Sqrt[1 - 1/x^2]]}

{E^ArcCoth[x]/(1 - 1/x^2), x, 6, -(1/Sqrt[1 - 1/x^2]) - x/Sqrt[1 - 1/x^2] + 2*Sqrt[1 - 1/x^2]*x + ArcTanh[Sqrt[1 - 1/x^2]]}
{E^ArcCoth[x]/(1 - 1/x^2)^2, x, 8, -(1/(3*(1 - 1/x^2)^(3/2))) - 1/Sqrt[1 - 1/x^2] - x/(3*(1 - 1/x^2)^(3/2)) - (4*x)/(3*Sqrt[1 - 1/x^2]) + (8/3)*Sqrt[1 - 1/x^2]*x + ArcTanh[Sqrt[1 - 1/x^2]]}
{E^ArcCoth[x]/(1 - 1/x^2)^3, x, 10, -(1/(5*(1 - 1/x^2)^(5/2))) - 1/(3*(1 - 1/x^2)^(3/2)) - 1/Sqrt[1 - 1/x^2] - x/(5*(1 - 1/x^2)^(5/2)) - (2*x)/(5*(1 - 1/x^2)^(3/2)) - (8*x)/(5*Sqrt[1 - 1/x^2]) + (16/5)*Sqrt[1 - 1/x^2]*x + ArcTanh[Sqrt[1 - 1/x^2]]}


{E^(3*ArcCoth[x])*(1 - 1/x^2), x, 8, Sqrt[1 - 1/x^2] + Sqrt[1 - 1/x^2]*x - 3*ArcCsc[x] + 3*ArcTanh[Sqrt[1 - 1/x^2]]}
{E^(3*ArcCoth[x])*(1 - 1/x^2)^2, x, 12, -3*Sqrt[1 - 1/x^2] + (1/3)*(1 - 1/x^2)^(3/2) - (3*Sqrt[1 - 1/x^2])/(2*x) + Sqrt[1 - 1/x^2]*x - ArcCsc[x]/2 + 3*ArcTanh[Sqrt[1 - 1/x^2]]}
{E^(3*ArcCoth[x])*(1 - 1/x^2)^3, x, 19, -3*Sqrt[1 - 1/x^2] - (4/5)*(1 - 1/x^2)^(3/2) + (3*Sqrt[1 - 1/x^2])/(4*x^3) - (1 - 1/x^2)^(3/2)/(5*x^2) - (11*Sqrt[1 - 1/x^2])/(8*x) + Sqrt[1 - 1/x^2]*x + (3*ArcCsc[x])/8 + 3*ArcTanh[Sqrt[1 - 1/x^2]]}

{E^(3*ArcCoth[x])/(1 - 1/x^2), x, 13, -(4/(3*(1 - 1/x^2)^(3/2))) - 3/Sqrt[1 - 1/x^2] - 1/((1 - 1/x^2)^(3/2)*x) - 2/(Sqrt[1 - 1/x^2]*x) - x/(3*(1 - 1/x^2)^(3/2)) - (4*x)/(3*Sqrt[1 - 1/x^2]) + (8/3)*Sqrt[1 - 1/x^2]*x + 3*ArcTanh[Sqrt[1 - 1/x^2]]}
{E^(3*ArcCoth[x])/(1 - 1/x^2)^2, x, 16, -(4/(5*(1 - 1/x^2)^(5/2))) - 1/(1 - 1/x^2)^(3/2) - 3/Sqrt[1 - 1/x^2] - 3/(5*(1 - 1/x^2)^(5/2)*x) - 4/(5*(1 - 1/x^2)^(3/2)*x) - 8/(5*Sqrt[1 - 1/x^2]*x) - x/(5*(1 - 1/x^2)^(5/2)) - (2*x)/(5*(1 - 1/x^2)^(3/2)) - (8*x)/(5*Sqrt[1 - 1/x^2]) + (16/5)*Sqrt[1 - 1/x^2]*x + 3*ArcTanh[Sqrt[1 - 1/x^2]]}
{E^(3*ArcCoth[x])/(1 - 1/x^2)^3, x, 19, -(4/(7*(1 - 1/x^2)^(7/2))) - 3/(5*(1 - 1/x^2)^(5/2)) - 1/(1 - 1/x^2)^(3/2) - 3/Sqrt[1 - 1/x^2] - 3/(7*(1 - 1/x^2)^(7/2)*x) - 18/(35*(1 - 1/x^2)^(5/2)*x) - 24/(35*(1 - 1/x^2)^(3/2)*x) - 48/(35*Sqrt[1 - 1/x^2]*x) - x/(7*(1 - 1/x^2)^(7/2)) - (8*x)/(35*(1 - 1/x^2)^(5/2)) - (16*x)/(35*(1 - 1/x^2)^(3/2)) - (64*x)/(35*Sqrt[1 - 1/x^2]) + (128/35)*Sqrt[1 - 1/x^2]*x + 3*ArcTanh[Sqrt[1 - 1/x^2]]}


{E^ArcCoth[x]*(1 - 1/x^2)^(1/2), x, 3, x + Log[x]}
{E^ArcCoth[x]*(1 - 1/x^2)^(3/2), x, 3, 1/(2*x^2) + 1/x + x + Log[x]}
{E^ArcCoth[x]*(1 - 1/x^2)^(5/2), x, 3, -(1/(4*x^4)) - 1/(3*x^3) + 1/x^2 + 2/x + x + Log[x]}

{E^ArcCoth[x]/(1 - 1/x^2)^(1/2), x, 4, x + Log[1 - x]}
{E^ArcCoth[x]/(1 - 1/x^2)^(3/2), x, 6, 1/(2*(1 - x)) + x + (5/4)*Log[1 - x] - (1/4)*Log[1 + x]}
{E^ArcCoth[x]/(1 - 1/x^2)^(5/2), x, 8, -(1/(8*(1 - x)^2)) + 1/(1 - x) + x - 1/(8*(1 + x)) + (23/16)*Log[1 - x] - (7/16)*Log[1 + x]}


(* ::Subsection::Closed:: *)
(*Miscellaneous integrands involving inverse hyperbolic cotangents*)


{ArcCoth[1/x], x, 1, x*ArcTanh[x] + Log[1 - x^2]/2}


{ArcCoth[a + b*x]/((a*d)/b + d*x), x, 6, PolyLog[2, -(1/(a + b*x))]/(2*d) - PolyLog[2, 1/(a + b*x)]/(2*d)}


{ArcCoth[a*x^n]/x, x, 3, PolyLog[2, -(1/(x^n*a))]/(2*n) - PolyLog[2, 1/(x^n*a)]/(2*n)}

{ArcCoth[a*x^5]/x, x, 3, (1/10)*PolyLog[2, -(1/(a*x^5))] - (1/10)*PolyLog[2, 1/(a*x^5)]}


{x^3*ArcCoth[a + b*x^4], x, 2, ((a + b*x^4)*ArcCoth[a + b*x^4])/(4*b) + Log[1 - (a + b*x^4)^2]/(8*b)}

{x^(n-1)*ArcCoth[a + b*x^n], x, 2, ((a + b*x^n)*ArcCoth[a + b*x^n])/(b*n) + Log[1 - (a + b*x^n)^2]/(2*b*n)}
