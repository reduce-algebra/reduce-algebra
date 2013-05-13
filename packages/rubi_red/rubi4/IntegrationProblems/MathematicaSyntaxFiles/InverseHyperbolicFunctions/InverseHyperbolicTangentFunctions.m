(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Inverse Hyperbolic Tangents*)


(* ::Subsection::Closed:: *)
(*Integrands involving inverse hyperbolic tangents*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m ArcTanh[a x]^n*)


(* Integrands of the form x^m*ArcTanh[a*x] where m is an integer *)
{x^5*ArcTanh[a*x], x, 6, x/(6*a^5) + x^3/(18*a^3) + x^5/(30*a) - ArcTanh[a*x]/(6*a^6) + (1/6)*x^6*ArcTanh[a*x]}
{x^4*ArcTanh[a*x], x, 5, x^2/(10*a^3) + x^4/(20*a) + (1/5)*x^5*ArcTanh[a*x] + Log[1 - a^2*x^2]/(10*a^5)}
{x^3*ArcTanh[a*x], x, 4, x/(4*a^3) + x^3/(12*a) - ArcTanh[a*x]/(4*a^4) + (1/4)*x^4*ArcTanh[a*x]}
{x^2*ArcTanh[a*x], x, 3, x^2/(6*a) + (1/3)*x^3*ArcTanh[a*x] + Log[1 - a^2*x^2]/(6*a^3)}
{x*ArcTanh[a*x], x, 2, x/(2*a) - ArcTanh[a*x]/(2*a^2) + (1/2)*x^2*ArcTanh[a*x]}
{ArcTanh[a*x], x, 1, x*ArcTanh[a*x] + Log[1 - a^2*x^2]/(2*a)}
{ArcTanh[a*x]/x, x, 3, (-(1/2))*PolyLog[2, (-a)*x] + (1/2)*PolyLog[2, a*x]}
{ArcTanh[a*x]/x^2, x, 2, -(ArcTanh[a*x]/x) - a*ArcTanh[1 - 2*a^2*x^2]}
{ArcTanh[a*x]/x^3, x, 2, -(a/(2*x)) + (1/2)*a^2*ArcTanh[a*x] - ArcTanh[a*x]/(2*x^2)}
{ArcTanh[a*x]/x^4, x, 4, -(a/(6*x^2)) - ArcTanh[a*x]/(3*x^3) - (1/3)*a^3*ArcTanh[1 - 2*a^2*x^2]}
{ArcTanh[a*x]/x^5, x, 4, -(a/(12*x^3)) - a^3/(4*x) + (1/4)*a^4*ArcTanh[a*x] - ArcTanh[a*x]/(4*x^4)}


(* Integrands of the form x^m*ArcTanh[a*x]^2 where m is an integer *)
{x^5*ArcTanh[a*x]^2, x, 12, (4*x^2)/(45*a^4) + x^4/(60*a^2) + (x*ArcTanh[a*x])/(3*a^5) + (x^3*ArcTanh[a*x])/(9*a^3) + (x^5*ArcTanh[a*x])/(15*a) - ArcTanh[a*x]^2/(6*a^6) + (1/6)*x^6*ArcTanh[a*x]^2 + (23*Log[1 - a^2*x^2])/(90*a^6)}
{x^4*ArcTanh[a*x]^2, x, 12, (3*x)/(10*a^4) + x^3/(30*a^2) - (3*ArcTanh[a*x])/(10*a^5) + (x^2*ArcTanh[a*x])/(5*a^3) + (x^4*ArcTanh[a*x])/(10*a) + ArcTanh[a*x]^2/(5*a^5) + (1/5)*x^5*ArcTanh[a*x]^2 - (2*ArcTanh[a*x]*Log[2/(1 - a*x)])/(5*a^5) - PolyLog[2, 1 - 2/(1 - a*x)]/(5*a^5)}
{x^3*ArcTanh[a*x]^2, x, 6, x^2/(12*a^2) + (x*ArcTanh[a*x])/(2*a^3) + (x^3*ArcTanh[a*x])/(6*a) - ArcTanh[a*x]^2/(4*a^4) + (1/4)*x^4*ArcTanh[a*x]^2 + Log[1 - a^2*x^2]/(3*a^4)}
{x^2*ArcTanh[a*x]^2, x, 7, x/(3*a^2) - ArcTanh[a*x]/(3*a^3) + (x^2*ArcTanh[a*x])/(3*a) + ArcTanh[a*x]^2/(3*a^3) + (1/3)*x^3*ArcTanh[a*x]^2 - (2*ArcTanh[a*x]*Log[2/(1 - a*x)])/(3*a^3) - PolyLog[2, 1 - 2/(1 - a*x)]/(3*a^3)}
{x*ArcTanh[a*x]^2, x, 2, (x*ArcTanh[a*x])/a - ArcTanh[a*x]^2/(2*a^2) + (1/2)*x^2*ArcTanh[a*x]^2 + Log[1 - a^2*x^2]/(2*a^2)}
{ArcTanh[a*x]^2, x, 4, ArcTanh[a*x]^2/a + x*ArcTanh[a*x]^2 - (2*ArcTanh[a*x]*Log[2/(1 - a*x)])/a - PolyLog[2, 1 - 2/(1 - a*x)]/a}
{ArcTanh[a*x]^2/x, x, 6, 2*ArcTanh[a*x]^2*ArcTanh[1 - 2/(1 - a*x)] - ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)] + ArcTanh[a*x]*PolyLog[2, -1 + 2/(1 - a*x)] + (1/2)*PolyLog[3, 1 - 2/(1 - a*x)] - (1/2)*PolyLog[3, -1 + 2/(1 - a*x)]}
{ArcTanh[a*x]^2/x^2, x, 4, a*ArcTanh[a*x]^2 - ArcTanh[a*x]^2/x + 2*a*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)] - a*PolyLog[2, -1 + 2/(1 + a*x)]}
{ArcTanh[a*x]^2/x^3, x, 3, -((a*ArcTanh[a*x])/x) + (1/2)*a^2*ArcTanh[a*x]^2 - ArcTanh[a*x]^2/(2*x^2) - a^2*ArcTanh[1 - 2*a^2*x^2]}
{ArcTanh[a*x]^2/x^4, x, 7, -(a^2/(3*x)) + (1/3)*a^3*ArcTanh[a*x] - (a*ArcTanh[a*x])/(3*x^2) + (1/3)*a^3*ArcTanh[a*x]^2 - ArcTanh[a*x]^2/(3*x^3) + (2/3)*a^3*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)] - (1/3)*a^3*PolyLog[2, -1 + 2/(1 + a*x)]}
{ArcTanh[a*x]^2/x^5, x, 8, -(a^2/(12*x^2)) - (a*ArcTanh[a*x])/(6*x^3) - (a^3*ArcTanh[a*x])/(2*x) + (1/4)*a^4*ArcTanh[a*x]^2 - ArcTanh[a*x]^2/(4*x^4) - (2/3)*a^4*ArcTanh[1 - 2*a^2*x^2]}


(* Integrands of the form x^m*ArcTanh[a*x]^3 where m is an integer *)
{x^5*ArcTanh[a*x]^3, x, 26, (19*x)/(60*a^5) + x^3/(60*a^3) - (19*ArcTanh[a*x])/(60*a^6) + (4*x^2*ArcTanh[a*x])/(15*a^4) + (x^4*ArcTanh[a*x])/(20*a^2) + (23*ArcTanh[a*x]^2)/(30*a^6) + (x*ArcTanh[a*x]^2)/(2*a^5) + (x^3*ArcTanh[a*x]^2)/(6*a^3) + (x^5*ArcTanh[a*x]^2)/(10*a) - ArcTanh[a*x]^3/(6*a^6) + (1/6)*x^6*ArcTanh[a*x]^3 - (23*ArcTanh[a*x]*Log[2/(1 - a*x)])/(15*a^6) - (23*PolyLog[2, 1 - 2/(1 - a*x)])/(30*a^6)}
{x^4*ArcTanh[a*x]^3, x, 15, x^2/(20*a^3) + (9*x*ArcTanh[a*x])/(10*a^4) + (x^3*ArcTanh[a*x])/(10*a^2) - (9*ArcTanh[a*x]^2)/(20*a^5) + (3*x^2*ArcTanh[a*x]^2)/(10*a^3) + (3*x^4*ArcTanh[a*x]^2)/(20*a) + ArcTanh[a*x]^3/(5*a^5) + (1/5)*x^5*ArcTanh[a*x]^3 - (3*ArcTanh[a*x]^2*Log[2/(1 - a*x)])/(5*a^5) + Log[1 - a^2*x^2]/(2*a^5) - (3*ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/(5*a^5) + (3*PolyLog[3, 1 - 2/(1 - a*x)])/(10*a^5)}
{x^3*ArcTanh[a*x]^3, x, 13, x/(4*a^3) - ArcTanh[a*x]/(4*a^4) + (x^2*ArcTanh[a*x])/(4*a^2) + ArcTanh[a*x]^2/a^4 + (3*x*ArcTanh[a*x]^2)/(4*a^3) + (x^3*ArcTanh[a*x]^2)/(4*a) - ArcTanh[a*x]^3/(4*a^4) + (1/4)*x^4*ArcTanh[a*x]^3 - (2*ArcTanh[a*x]*Log[2/(1 - a*x)])/a^4 - PolyLog[2, 1 - 2/(1 - a*x)]/a^4}
{x^2*ArcTanh[a*x]^3, x, 8, (x*ArcTanh[a*x])/a^2 - ArcTanh[a*x]^2/(2*a^3) + (x^2*ArcTanh[a*x]^2)/(2*a) + ArcTanh[a*x]^3/(3*a^3) + (1/3)*x^3*ArcTanh[a*x]^3 - (ArcTanh[a*x]^2*Log[2/(1 - a*x)])/a^3 + Log[1 - a^2*x^2]/(2*a^3) - (ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/a^3 + PolyLog[3, 1 - 2/(1 - a*x)]/(2*a^3)}
{x*ArcTanh[a*x]^3, x, 5, (3*ArcTanh[a*x]^2)/(2*a^2) + (3*x*ArcTanh[a*x]^2)/(2*a) - ArcTanh[a*x]^3/(2*a^2) + (1/2)*x^2*ArcTanh[a*x]^3 - (3*ArcTanh[a*x]*Log[2/(1 - a*x)])/a^2 - (3*PolyLog[2, 1 - 2/(1 - a*x)])/(2*a^2)}
{ArcTanh[a*x]^3, x, 5, ArcTanh[a*x]^3/a + x*ArcTanh[a*x]^3 - (3*ArcTanh[a*x]^2*Log[2/(1 - a*x)])/a - (3*ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/a + (3*PolyLog[3, 1 - 2/(1 - a*x)])/(2*a)}
{ArcTanh[a*x]^3/x, x, 8, 2*ArcTanh[a*x]^3*ArcTanh[1 - 2/(1 - a*x)] - (3/2)*ArcTanh[a*x]^2*PolyLog[2, 1 - 2/(1 - a*x)] + (3/2)*ArcTanh[a*x]^2*PolyLog[2, -1 + 2/(1 - a*x)] + (3/2)*ArcTanh[a*x]*PolyLog[3, 1 - 2/(1 - a*x)] - (3/2)*ArcTanh[a*x]*PolyLog[3, -1 + 2/(1 - a*x)] - (3/4)*PolyLog[4, 1 - 2/(1 - a*x)] + (3/4)*PolyLog[4, -1 + 2/(1 - a*x)]}
{ArcTanh[a*x]^3/x^2, x, 5, a*ArcTanh[a*x]^3 - ArcTanh[a*x]^3/x + 3*a*ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)] - 3*a*ArcTanh[a*x]*PolyLog[2, -1 + 2/(1 + a*x)] - (3/2)*a*PolyLog[3, -1 + 2/(1 + a*x)]}
{ArcTanh[a*x]^3/x^3, x, 5, (3/2)*a^2*ArcTanh[a*x]^2 - (3*a*ArcTanh[a*x]^2)/(2*x) + (1/2)*a^2*ArcTanh[a*x]^3 - ArcTanh[a*x]^3/(2*x^2) + 3*a^2*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)] - (3/2)*a^2*PolyLog[2, -1 + 2/(1 + a*x)]}
{ArcTanh[a*x]^3/x^4, x, 9, -((a^2*ArcTanh[a*x])/x) + (1/2)*a^3*ArcTanh[a*x]^2 - (a*ArcTanh[a*x]^2)/(2*x^2) + (1/3)*a^3*ArcTanh[a*x]^3 - ArcTanh[a*x]^3/(3*x^3) - a^3*ArcTanh[1 - 2*a^2*x^2] + a^3*ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)] - a^3*ArcTanh[a*x]*PolyLog[2, -1 + 2/(1 + a*x)] - (1/2)*a^3*PolyLog[3, -1 + 2/(1 + a*x)]}
{ArcTanh[a*x]^3/x^5, x, 13, -(a^3/(4*x)) + (1/4)*a^4*ArcTanh[a*x] - (a^2*ArcTanh[a*x])/(4*x^2) + a^4*ArcTanh[a*x]^2 - (a*ArcTanh[a*x]^2)/(4*x^3) - (3*a^3*ArcTanh[a*x]^2)/(4*x) + (1/4)*a^4*ArcTanh[a*x]^3 - ArcTanh[a*x]^3/(4*x^4) + 2*a^4*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)] - a^4*PolyLog[2, -1 + 2/(1 + a*x)]}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m ArcTanh[a x]^n / (c+d x)*)


(* Integrands of the form x^m*ArcTanh[a*x]/(c+d*x) where d^2=a^2*c^2 and m is an integer *)
{x^3*ArcTanh[a*x]/(c + a*c*x), x, 11, -(x/(2*a^3*c)) + x^2/(6*a^2*c) + ArcTanh[a*x]/(2*a^4*c) + (x*ArcTanh[a*x])/(a^3*c) - (x^2*ArcTanh[a*x])/(2*a^2*c) + (x^3*ArcTanh[a*x])/(3*a*c) + (ArcTanh[a*x]*Log[2/(1 + a*x)])/(a^4*c) + (2*Log[1 - a^2*x^2])/(3*a^4*c) - PolyLog[2, 1 - 2/(1 + a*x)]/(2*a^4*c)}
{x^2*ArcTanh[a*x]/(c + a*c*x), x, 7, x/(2*a^2*c) - ArcTanh[a*x]/(2*a^3*c) - (x*ArcTanh[a*x])/(a^2*c) + (x^2*ArcTanh[a*x])/(2*a*c) - (ArcTanh[a*x]*Log[2/(1 + a*x)])/(a^3*c) - Log[1 - a^2*x^2]/(2*a^3*c) + PolyLog[2, 1 - 2/(1 + a*x)]/(2*a^3*c)}
{x*ArcTanh[a*x]/(c + a*c*x), x, 4, (x*ArcTanh[a*x])/(a*c) + (ArcTanh[a*x]*Log[2/(1 + a*x)])/(a^2*c) + Log[1 - a^2*x^2]/(2*a^2*c) - PolyLog[2, 1 - 2/(1 + a*x)]/(2*a^2*c)}
{ArcTanh[a*x]/(c + a*c*x), x, 2, -((ArcTanh[a*x]*Log[2/(1 + a*x)])/(a*c)) + PolyLog[2, 1 - 2/(1 + a*x)]/(2*a*c)}
{ArcTanh[a*x]/(x*(c + a*c*x)), x, 2, (ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)])/c - PolyLog[2, -1 + 2/(1 + a*x)]/(2*c)}
{ArcTanh[a*x]/(c*x + a*c*x^2), x, 2, (ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)])/c - PolyLog[2, -1 + 2/(1 + a*x)]/(2*c)}
{ArcTanh[a*x]/(x^2*(c + a*c*x)), x, 5, -(ArcTanh[a*x]/(c*x)) - (a*ArcTanh[1 - 2*a^2*x^2])/c - (a*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)])/c + (a*PolyLog[2, -1 + 2/(1 + a*x)])/(2*c)}
{ArcTanh[a*x]/(x^3*(c + a*c*x)), x, 8, -(a/(2*c*x)) + (a^2*ArcTanh[a*x])/(2*c) - ArcTanh[a*x]/(2*c*x^2) + (a*ArcTanh[a*x])/(c*x) + (a^2*ArcTanh[1 - 2*a^2*x^2])/c + (a^2*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)])/c - (a^2*PolyLog[2, -1 + 2/(1 + a*x)])/(2*c)}

{x^3*ArcTanh[a*x]/(c - a*c*x), x, 11, -(x/(2*a^3*c)) - x^2/(6*a^2*c) + ArcTanh[a*x]/(2*a^4*c) - (x*ArcTanh[a*x])/(a^3*c) - (x^2*ArcTanh[a*x])/(2*a^2*c) - (x^3*ArcTanh[a*x])/(3*a*c) + (ArcTanh[a*x]*Log[2/(1 - a*x)])/(a^4*c) - (2*Log[1 - a^2*x^2])/(3*a^4*c) + PolyLog[2, 1 - 2/(1 - a*x)]/(2*a^4*c)}
{x^2*ArcTanh[a*x]/(c - a*c*x), x, 7, -(x/(2*a^2*c)) + ArcTanh[a*x]/(2*a^3*c) - (x*ArcTanh[a*x])/(a^2*c) - (x^2*ArcTanh[a*x])/(2*a*c) + (ArcTanh[a*x]*Log[2/(1 - a*x)])/(a^3*c) - Log[1 - a^2*x^2]/(2*a^3*c) + PolyLog[2, 1 - 2/(1 - a*x)]/(2*a^3*c)}
{x*ArcTanh[a*x]/(c - a*c*x), x, 4, -((x*ArcTanh[a*x])/(a*c)) + (ArcTanh[a*x]*Log[2/(1 - a*x)])/(a^2*c) - Log[1 - a^2*x^2]/(2*a^2*c) + PolyLog[2, 1 - 2/(1 - a*x)]/(2*a^2*c)}
{ArcTanh[a*x]/(c - a*c*x), x, 2, (ArcTanh[a*x]*Log[2/(1 - a*x)])/(a*c) + PolyLog[2, 1 - 2/(1 - a*x)]/(2*a*c)}
{ArcTanh[a*x]/(x*(c - a*c*x)), x, 2, (ArcTanh[a*x]*Log[-((2*a*x)/(1 - a*x))])/c + PolyLog[2, -1 + 2/(1 - a*x)]/(2*c)}
{ArcTanh[a*x]/(c*x - a*c*x^2), x, 2, (ArcTanh[a*x]*Log[-((2*a*x)/(1 - a*x))])/c + PolyLog[2, -1 + 2/(1 - a*x)]/(2*c)}
{ArcTanh[a*x]/(x^2*(c - a*c*x)), x, 5, -(ArcTanh[a*x]/(c*x)) - (a*ArcTanh[1 - 2*a^2*x^2])/c + (a*ArcTanh[a*x]*Log[-((2*a*x)/(1 - a*x))])/c + (a*PolyLog[2, -1 + 2/(1 - a*x)])/(2*c)}
{ArcTanh[a*x]/(x^3*(c - a*c*x)), x, 8, -(a/(2*c*x)) + (a^2*ArcTanh[a*x])/(2*c) - ArcTanh[a*x]/(2*c*x^2) - (a*ArcTanh[a*x])/(c*x) - (a^2*ArcTanh[1 - 2*a^2*x^2])/c + (a^2*ArcTanh[a*x]*Log[-((2*a*x)/(1 - a*x))])/c + (a^2*PolyLog[2, -1 + 2/(1 - a*x)])/(2*c)}


(* Integrands of the form x^m*ArcTanh[a*x]^2/(c+d*x) where d^2=a^2*c^2 and m is an integer *)
{x^3*ArcTanh[a*x]^2/(c + a*c*x), x, 19, x/(3*a^3*c) - ArcTanh[a*x]/(3*a^4*c) - (x*ArcTanh[a*x])/(a^3*c) + (x^2*ArcTanh[a*x])/(3*a^2*c) + (11*ArcTanh[a*x]^2)/(6*a^4*c) + (x*ArcTanh[a*x]^2)/(a^3*c) - (x^2*ArcTanh[a*x]^2)/(2*a^2*c) + (x^3*ArcTanh[a*x]^2)/(3*a*c) - (8*ArcTanh[a*x]*Log[2/(1 - a*x)])/(3*a^4*c) + (ArcTanh[a*x]^2*Log[2/(1 + a*x)])/(a^4*c) - Log[1 - a^2*x^2]/(2*a^4*c) - (4*PolyLog[2, 1 - 2/(1 - a*x)])/(3*a^4*c) - (ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 + a*x)])/(a^4*c) - PolyLog[3, 1 - 2/(1 + a*x)]/(2*a^4*c)}
{x^2*ArcTanh[a*x]^2/(c + a*c*x), x, 11, (x*ArcTanh[a*x])/(a^2*c) - (3*ArcTanh[a*x]^2)/(2*a^3*c) - (x*ArcTanh[a*x]^2)/(a^2*c) + (x^2*ArcTanh[a*x]^2)/(2*a*c) + (2*ArcTanh[a*x]*Log[2/(1 - a*x)])/(a^3*c) - (ArcTanh[a*x]^2*Log[2/(1 + a*x)])/(a^3*c) + Log[1 - a^2*x^2]/(2*a^3*c) + PolyLog[2, 1 - 2/(1 - a*x)]/(a^3*c) + (ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 + a*x)])/(a^3*c) + PolyLog[3, 1 - 2/(1 + a*x)]/(2*a^3*c)}
{x*ArcTanh[a*x]^2/(c + a*c*x), x, 8, ArcTanh[a*x]^2/(a^2*c) + (x*ArcTanh[a*x]^2)/(a*c) - (2*ArcTanh[a*x]*Log[2/(1 - a*x)])/(a^2*c) + (ArcTanh[a*x]^2*Log[2/(1 + a*x)])/(a^2*c) - PolyLog[2, 1 - 2/(1 - a*x)]/(a^2*c) - (ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 + a*x)])/(a^2*c) - PolyLog[3, 1 - 2/(1 + a*x)]/(2*a^2*c)}
{ArcTanh[a*x]^2/(c + a*c*x), x, 3, -((ArcTanh[a*x]^2*Log[2/(1 + a*x)])/(a*c)) + (ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 + a*x)])/(a*c) + PolyLog[3, 1 - 2/(1 + a*x)]/(2*a*c)}
{ArcTanh[a*x]^2/(x*(c + a*c*x)), x, 3, (ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)])/c - (ArcTanh[a*x]*PolyLog[2, -1 + 2/(1 + a*x)])/c - PolyLog[3, -1 + 2/(1 + a*x)]/(2*c)}
{ArcTanh[a*x]^2/(c*x + a*c*x^2), x, 3, (ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)])/c - (ArcTanh[a*x]*PolyLog[2, -1 + 2/(1 + a*x)])/c - PolyLog[3, -1 + 2/(1 + a*x)]/(2*c)}
{ArcTanh[a*x]^2/(x^2*(c + a*c*x)), x, 8, (a*ArcTanh[a*x]^2)/c - ArcTanh[a*x]^2/(c*x) + (2*a*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)])/c - (a*ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)])/c - (a*(1 - ArcTanh[a*x])*PolyLog[2, -1 + 2/(1 + a*x)])/c + (a*PolyLog[3, -1 + 2/(1 + a*x)])/(2*c)}
{ArcTanh[a*x]^2/(x^3*(c + a*c*x)), x, 12, -((a*ArcTanh[a*x])/(c*x)) - (a^2*ArcTanh[a*x]^2)/(2*c) - ArcTanh[a*x]^2/(2*c*x^2) + (a*ArcTanh[a*x]^2)/(c*x) - (a^2*ArcTanh[1 - 2*a^2*x^2])/c - (2*a^2*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)])/c + (a^2*ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)])/c + (a^2*(1 - ArcTanh[a*x])*PolyLog[2, -1 + 2/(1 + a*x)])/c - (a^2*PolyLog[3, -1 + 2/(1 + a*x)])/(2*c)}

{x^3*ArcTanh[a*x]^2/(c - a*c*x), x, 19, -(x/(3*a^3*c)) + ArcTanh[a*x]/(3*a^4*c) - (x*ArcTanh[a*x])/(a^3*c) - (x^2*ArcTanh[a*x])/(3*a^2*c) - (5*ArcTanh[a*x]^2)/(6*a^4*c) - (x*ArcTanh[a*x]^2)/(a^3*c) - (x^2*ArcTanh[a*x]^2)/(2*a^2*c) - (x^3*ArcTanh[a*x]^2)/(3*a*c) + (8*ArcTanh[a*x]*Log[2/(1 - a*x)])/(3*a^4*c) + (ArcTanh[a*x]^2*Log[2/(1 - a*x)])/(a^4*c) - Log[1 - a^2*x^2]/(2*a^4*c) + ((4 + 3*ArcTanh[a*x])*PolyLog[2, 1 - 2/(1 - a*x)])/(3*a^4*c) - PolyLog[3, 1 - 2/(1 - a*x)]/(2*a^4*c)}
{x^2*ArcTanh[a*x]^2/(c - a*c*x), x, 11, -((x*ArcTanh[a*x])/(a^2*c)) - ArcTanh[a*x]^2/(2*a^3*c) - (x*ArcTanh[a*x]^2)/(a^2*c) - (x^2*ArcTanh[a*x]^2)/(2*a*c) + (2*ArcTanh[a*x]*Log[2/(1 - a*x)])/(a^3*c) + (ArcTanh[a*x]^2*Log[2/(1 - a*x)])/(a^3*c) - Log[1 - a^2*x^2]/(2*a^3*c) + ((1 + ArcTanh[a*x])*PolyLog[2, 1 - 2/(1 - a*x)])/(a^3*c) - PolyLog[3, 1 - 2/(1 - a*x)]/(2*a^3*c)}
{x*ArcTanh[a*x]^2/(c - a*c*x), x, 8, -(ArcTanh[a*x]^2/(a^2*c)) - (x*ArcTanh[a*x]^2)/(a*c) + (2*ArcTanh[a*x]*Log[2/(1 - a*x)])/(a^2*c) + (ArcTanh[a*x]^2*Log[2/(1 - a*x)])/(a^2*c) + ((1 + ArcTanh[a*x])*PolyLog[2, 1 - 2/(1 - a*x)])/(a^2*c) - PolyLog[3, 1 - 2/(1 - a*x)]/(2*a^2*c)}
{ArcTanh[a*x]^2/(c - a*c*x), x, 3, (ArcTanh[a*x]^2*Log[2/(1 - a*x)])/(a*c) + (ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/(a*c) - PolyLog[3, 1 - 2/(1 - a*x)]/(2*a*c)}
{ArcTanh[a*x]^2/(x*(c - a*c*x)), x, 3, (ArcTanh[a*x]^2*Log[-((2*a*x)/(1 - a*x))])/c + (ArcTanh[a*x]*PolyLog[2, -1 + 2/(1 - a*x)])/c - PolyLog[3, -1 + 2/(1 - a*x)]/(2*c)}
{ArcTanh[a*x]^2/(c*x - a*c*x^2), x, 3, (ArcTanh[a*x]^2*Log[-((2*a*x)/(1 - a*x))])/c + (ArcTanh[a*x]*PolyLog[2, -1 + 2/(1 - a*x)])/c - PolyLog[3, -1 + 2/(1 - a*x)]/(2*c)}
{ArcTanh[a*x]^2/(x^2*(c - a*c*x)), x, 8, (a*ArcTanh[a*x]^2)/c - ArcTanh[a*x]^2/(c*x) + (a*ArcTanh[a*x]^2*Log[-((2*a*x)/(1 - a*x))])/c + (2*a*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)])/c + (a*ArcTanh[a*x]*PolyLog[2, -1 + 2/(1 - a*x)])/c - (a*PolyLog[2, -1 + 2/(1 + a*x)])/c - (a*PolyLog[3, -1 + 2/(1 - a*x)])/(2*c)}
{ArcTanh[a*x]^2/(x^3*(c - a*c*x)), x, 12, -((a*ArcTanh[a*x])/(c*x)) + (3*a^2*ArcTanh[a*x]^2)/(2*c) - ArcTanh[a*x]^2/(2*c*x^2) - (a*ArcTanh[a*x]^2)/(c*x) - (a^2*ArcTanh[1 - 2*a^2*x^2])/c + (a^2*ArcTanh[a*x]^2*Log[-((2*a*x)/(1 - a*x))])/c + (2*a^2*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)])/c + (a^2*ArcTanh[a*x]*PolyLog[2, -1 + 2/(1 - a*x)])/c - (a^2*PolyLog[2, -1 + 2/(1 + a*x)])/c - (a^2*PolyLog[3, -1 + 2/(1 - a*x)])/(2*c)}


(* Integrands of the form x^m*ArcTanh[a*x]^3/(c+d*x) where d^2=a^2*c^2 and m is an integer *)
(* {x^3*ArcTanh[a*x]^3/(c + a*c*x), x, 27, (x*ArcTanh[a*x])/(a^3*c) - (2*ArcTanh[a*x]^2)/(a^4*c) - (3*x*ArcTanh[a*x]^2)/(2*a^3*c) + (x^2*ArcTanh[a*x]^2)/(2*a^2*c) + (11*ArcTanh[a*x]^3)/(6*a^4*c) + (x*ArcTanh[a*x]^3)/(a^3*c) - (x^2*ArcTanh[a*x]^3)/(2*a^2*c) + (x^3*ArcTanh[a*x]^3)/(3*a*c) + (3*ArcTanh[a*x]*Log[2/(1 - a*x)])/(a^4*c) - (4*ArcTanh[a*x]^2*Log[2/(1 - a*x)])/(a^4*c) + (ArcTanh[a*x]^3*Log[2/(1 + a*x)])/(a^4*c) + Log[1 - a^2*x^2]/(2*a^4*c) + ((3 - 8*ArcTanh[a*x])*PolyLog[2, 1 - 2/(1 - a*x)])/(2*a^4*c) - (3*ArcTanh[a*x]^2*PolyLog[2, 1 - 2/(1 + a*x)])/(2*a^4*c) + (2*PolyLog[3, 1 - 2/(1 - a*x)])/(a^4*c) - (3*ArcTanh[a*x]*PolyLog[3, 1 - 2/(1 + a*x)])/(2*a^4*c) - (3*PolyLog[4, 1 - 2/(1 + a*x)])/(4*a^4*c)} *)
{x^2*ArcTanh[a*x]^3/(c + a*c*x), x, 16, (3*ArcTanh[a*x]^2)/(2*a^3*c) + (3*x*ArcTanh[a*x]^2)/(2*a^2*c) - (3*ArcTanh[a*x]^3)/(2*a^3*c) - (x*ArcTanh[a*x]^3)/(a^2*c) + (x^2*ArcTanh[a*x]^3)/(2*a*c) - (3*ArcTanh[a*x]*Log[2/(1 - a*x)])/(a^3*c) + (3*ArcTanh[a*x]^2*Log[2/(1 - a*x)])/(a^3*c) - (ArcTanh[a*x]^3*Log[2/(1 + a*x)])/(a^3*c) - (3*(1 - 2*ArcTanh[a*x])*PolyLog[2, 1 - 2/(1 - a*x)])/(2*a^3*c) + (3*ArcTanh[a*x]^2*PolyLog[2, 1 - 2/(1 + a*x)])/(2*a^3*c) - (3*PolyLog[3, 1 - 2/(1 - a*x)])/(2*a^3*c) + (3*ArcTanh[a*x]*PolyLog[3, 1 - 2/(1 + a*x)])/(2*a^3*c) + (3*PolyLog[4, 1 - 2/(1 + a*x)])/(4*a^3*c)}
{x*ArcTanh[a*x]^3/(c + a*c*x), x, 10, ArcTanh[a*x]^3/(a^2*c) + (x*ArcTanh[a*x]^3)/(a*c) - (3*ArcTanh[a*x]^2*Log[2/(1 - a*x)])/(a^2*c) + (ArcTanh[a*x]^3*Log[2/(1 + a*x)])/(a^2*c) - (3*ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/(a^2*c) - (3*ArcTanh[a*x]^2*PolyLog[2, 1 - 2/(1 + a*x)])/(2*a^2*c) + (3*PolyLog[3, 1 - 2/(1 - a*x)])/(2*a^2*c) - (3*ArcTanh[a*x]*PolyLog[3, 1 - 2/(1 + a*x)])/(2*a^2*c) - (3*PolyLog[4, 1 - 2/(1 + a*x)])/(4*a^2*c)}
{ArcTanh[a*x]^3/(c + a*c*x), x, 4, -((ArcTanh[a*x]^3*Log[2/(1 + a*x)])/(a*c)) + (3*ArcTanh[a*x]^2*PolyLog[2, 1 - 2/(1 + a*x)])/(2*a*c) + (3*ArcTanh[a*x]*PolyLog[3, 1 - 2/(1 + a*x)])/(2*a*c) + (3*PolyLog[4, 1 - 2/(1 + a*x)])/(4*a*c)}
{ArcTanh[a*x]^3/(x*(c + a*c*x)), x, 4, (ArcTanh[a*x]^3*Log[(2*a*x)/(1 + a*x)])/c - (3*ArcTanh[a*x]^2*PolyLog[2, -1 + 2/(1 + a*x)])/(2*c) - (3*ArcTanh[a*x]*PolyLog[3, -1 + 2/(1 + a*x)])/(2*c) - (3*PolyLog[4, -1 + 2/(1 + a*x)])/(4*c)}
{ArcTanh[a*x]^3/(c*x + a*c*x^2), x, 4, (ArcTanh[a*x]^3*Log[(2*a*x)/(1 + a*x)])/c - (3*ArcTanh[a*x]^2*PolyLog[2, -1 + 2/(1 + a*x)])/(2*c) - (3*ArcTanh[a*x]*PolyLog[3, -1 + 2/(1 + a*x)])/(2*c) - (3*PolyLog[4, -1 + 2/(1 + a*x)])/(4*c)}
{ArcTanh[a*x]^3/(x^2*(c + a*c*x)), x, 10, (a*ArcTanh[a*x]^3)/c - ArcTanh[a*x]^3/(c*x) + (3*a*ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)])/c - (a*ArcTanh[a*x]^3*Log[(2*a*x)/(1 + a*x)])/c - (3*a*(2 - ArcTanh[a*x])*ArcTanh[a*x]*PolyLog[2, -1 + 2/(1 + a*x)])/(2*c) - (3*a*(1 - ArcTanh[a*x])*PolyLog[3, -1 + 2/(1 + a*x)])/(2*c) + (3*a*PolyLog[4, -1 + 2/(1 + a*x)])/(4*c)}
{ArcTanh[a*x]^3/(x^3*(c + a*c*x)), x, 16, (3*a^2*ArcTanh[a*x]^2)/(2*c) - (3*a*ArcTanh[a*x]^2)/(2*c*x) - (a^2*ArcTanh[a*x]^3)/(2*c) - ArcTanh[a*x]^3/(2*c*x^2) + (a*ArcTanh[a*x]^3)/(c*x) + (3*a^2*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)])/c - (3*a^2*ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)])/c + (a^2*ArcTanh[a*x]^3*Log[(2*a*x)/(1 + a*x)])/c - (3*a^2*(1 - ArcTanh[a*x])^2*PolyLog[2, -1 + 2/(1 + a*x)])/(2*c) + (3*a^2*(1 - ArcTanh[a*x])*PolyLog[3, -1 + 2/(1 + a*x)])/(2*c) - (3*a^2*PolyLog[4, -1 + 2/(1 + a*x)])/(4*c)}

(* {x^3*ArcTanh[a*x]^3/(c - a*c*x), x, 27, -((x*ArcTanh[a*x])/(a^3*c)) - ArcTanh[a*x]^2/(a^4*c) - (3*x*ArcTanh[a*x]^2)/(2*a^3*c) - (x^2*ArcTanh[a*x]^2)/(2*a^2*c) - (5*ArcTanh[a*x]^3)/(6*a^4*c) - (x*ArcTanh[a*x]^3)/(a^3*c) - (x^2*ArcTanh[a*x]^3)/(2*a^2*c) - (x^3*ArcTanh[a*x]^3)/(3*a*c) + (3*ArcTanh[a*x]*Log[2/(1 - a*x)])/(a^4*c) + (4*ArcTanh[a*x]^2*Log[2/(1 - a*x)])/(a^4*c) + (ArcTanh[a*x]^3*Log[2/(1 - a*x)])/(a^4*c) - Log[1 - a^2*x^2]/(2*a^4*c) + ((3 + 8*ArcTanh[a*x] + 3*ArcTanh[a*x]^2)*PolyLog[2, 1 - 2/(1 - a*x)])/(2*a^4*c) - ((4 + 3*ArcTanh[a*x])*PolyLog[3, 1 - 2/(1 - a*x)])/(2*a^4*c) + (3*PolyLog[4, 1 - 2/(1 - a*x)])/(4*a^4*c)} *)
{x^2*ArcTanh[a*x]^3/(c - a*c*x), x, 16, -((3*ArcTanh[a*x]^2)/(2*a^3*c)) - (3*x*ArcTanh[a*x]^2)/(2*a^2*c) - ArcTanh[a*x]^3/(2*a^3*c) - (x*ArcTanh[a*x]^3)/(a^2*c) - (x^2*ArcTanh[a*x]^3)/(2*a*c) + (3*ArcTanh[a*x]*Log[2/(1 - a*x)])/(a^3*c) + (3*ArcTanh[a*x]^2*Log[2/(1 - a*x)])/(a^3*c) + (ArcTanh[a*x]^3*Log[2/(1 - a*x)])/(a^3*c) + (3*(1 + ArcTanh[a*x])^2*PolyLog[2, 1 - 2/(1 - a*x)])/(2*a^3*c) - (3*(1 + ArcTanh[a*x])*PolyLog[3, 1 - 2/(1 - a*x)])/(2*a^3*c) + (3*PolyLog[4, 1 - 2/(1 - a*x)])/(4*a^3*c)}
{x*ArcTanh[a*x]^3/(c - a*c*x), x, 10, -(ArcTanh[a*x]^3/(a^2*c)) - (x*ArcTanh[a*x]^3)/(a*c) + (3*ArcTanh[a*x]^2*Log[2/(1 - a*x)])/(a^2*c) + (ArcTanh[a*x]^3*Log[2/(1 - a*x)])/(a^2*c) + (3*ArcTanh[a*x]*(2 + ArcTanh[a*x])*PolyLog[2, 1 - 2/(1 - a*x)])/(2*a^2*c) - (3*(1 + ArcTanh[a*x])*PolyLog[3, 1 - 2/(1 - a*x)])/(2*a^2*c) + (3*PolyLog[4, 1 - 2/(1 - a*x)])/(4*a^2*c)}
{ArcTanh[a*x]^3/(c - a*c*x), x, 4, (ArcTanh[a*x]^3*Log[2/(1 - a*x)])/(a*c) + (3*ArcTanh[a*x]^2*PolyLog[2, 1 - 2/(1 - a*x)])/(2*a*c) - (3*ArcTanh[a*x]*PolyLog[3, 1 - 2/(1 - a*x)])/(2*a*c) + (3*PolyLog[4, 1 - 2/(1 - a*x)])/(4*a*c)}
{ArcTanh[a*x]^3/(x*(c - a*c*x)), x, 4, (ArcTanh[a*x]^3*Log[-((2*a*x)/(1 - a*x))])/c + (3*ArcTanh[a*x]^2*PolyLog[2, -1 + 2/(1 - a*x)])/(2*c) - (3*ArcTanh[a*x]*PolyLog[3, -1 + 2/(1 - a*x)])/(2*c) + (3*PolyLog[4, -1 + 2/(1 - a*x)])/(4*c)}
{ArcTanh[a*x]^3/(c*x - a*c*x^2), x, 4, (ArcTanh[a*x]^3*Log[-((2*a*x)/(1 - a*x))])/c + (3*ArcTanh[a*x]^2*PolyLog[2, -1 + 2/(1 - a*x)])/(2*c) - (3*ArcTanh[a*x]*PolyLog[3, -1 + 2/(1 - a*x)])/(2*c) + (3*PolyLog[4, -1 + 2/(1 - a*x)])/(4*c)}
{ArcTanh[a*x]^3/(x^2*(c - a*c*x)), x, 10, (a*ArcTanh[a*x]^3)/c - ArcTanh[a*x]^3/(c*x) + (a*ArcTanh[a*x]^3*Log[-((2*a*x)/(1 - a*x))])/c + (3*a*ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)])/c + (3*a*ArcTanh[a*x]^2*PolyLog[2, -1 + 2/(1 - a*x)])/(2*c) - (3*a*ArcTanh[a*x]*PolyLog[2, -1 + 2/(1 + a*x)])/c - (3*a*ArcTanh[a*x]*PolyLog[3, -1 + 2/(1 - a*x)])/(2*c) - (3*a*PolyLog[3, -1 + 2/(1 + a*x)])/(2*c) + (3*a*PolyLog[4, -1 + 2/(1 - a*x)])/(4*c)}
{ArcTanh[a*x]^3/(x^3*(c - a*c*x)), x, 16, (3*a^2*ArcTanh[a*x]^2)/(2*c) - (3*a*ArcTanh[a*x]^2)/(2*c*x) + (3*a^2*ArcTanh[a*x]^3)/(2*c) - ArcTanh[a*x]^3/(2*c*x^2) - (a*ArcTanh[a*x]^3)/(c*x) + (a^2*ArcTanh[a*x]^3*Log[-((2*a*x)/(1 - a*x))])/c + (3*a^2*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)])/c + (3*a^2*ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)])/c + (3*a^2*ArcTanh[a*x]^2*PolyLog[2, -1 + 2/(1 - a*x)])/(2*c) - (3*a^2*(1 + 2*ArcTanh[a*x])*PolyLog[2, -1 + 2/(1 + a*x)])/(2*c) - (3*a^2*ArcTanh[a*x]*PolyLog[3, -1 + 2/(1 - a*x)])/(2*c) - (3*a^2*PolyLog[3, -1 + 2/(1 + a*x)])/(2*c) + (3*a^2*PolyLog[4, -1 + 2/(1 - a*x)])/(4*c)}


(* Integrands of the form x^m*ArcTanh[a*x]^4/(c+d*x) where d^2=a^2*c^2 and m is an integer *)
(* {x^3*ArcTanh[a*x]^4/(c + a*c*x), x, 32, (2*ArcTanh[a*x]^2)/(a^4*c) + (2*x*ArcTanh[a*x]^2)/(a^3*c) - (8*ArcTanh[a*x]^3)/(3*a^4*c) - (2*x*ArcTanh[a*x]^3)/(a^3*c) + (2*x^2*ArcTanh[a*x]^3)/(3*a^2*c) + (11*ArcTanh[a*x]^4)/(6*a^4*c) + (x*ArcTanh[a*x]^4)/(a^3*c) - (x^2*ArcTanh[a*x]^4)/(2*a^2*c) + (x^3*ArcTanh[a*x]^4)/(3*a*c) - (4*ArcTanh[a*x]*Log[2/(1 - a*x)])/(a^4*c) + (6*ArcTanh[a*x]^2*Log[2/(1 - a*x)])/(a^4*c) - (16*ArcTanh[a*x]^3*Log[2/(1 - a*x)])/(3*a^4*c) + (ArcTanh[a*x]^4*Log[2/(1 + a*x)])/(a^4*c) - (2*(1 - 3*ArcTanh[a*x] + 4*ArcTanh[a*x]^2)*PolyLog[2, 1 - 2/(1 - a*x)])/(a^4*c) - (2*ArcTanh[a*x]^3*PolyLog[2, 1 - 2/(1 + a*x)])/(a^4*c) - ((3 - 8*ArcTanh[a*x])*PolyLog[3, 1 - 2/(1 - a*x)])/(a^4*c) - (3*ArcTanh[a*x]^2*PolyLog[3, 1 - 2/(1 + a*x)])/(a^4*c) - (4*PolyLog[4, 1 - 2/(1 - a*x)])/(a^4*c) - (3*ArcTanh[a*x]*PolyLog[4, 1 - 2/(1 + a*x)])/(a^4*c) - (3*PolyLog[5, 1 - 2/(1 + a*x)])/(2*a^4*c)} *)
{x^2*ArcTanh[a*x]^4/(c + a*c*x), x, 19, (2*ArcTanh[a*x]^3)/(a^3*c) + (2*x*ArcTanh[a*x]^3)/(a^2*c) - (3*ArcTanh[a*x]^4)/(2*a^3*c) - (x*ArcTanh[a*x]^4)/(a^2*c) + (x^2*ArcTanh[a*x]^4)/(2*a*c) - (6*ArcTanh[a*x]^2*Log[2/(1 - a*x)])/(a^3*c) + (4*ArcTanh[a*x]^3*Log[2/(1 - a*x)])/(a^3*c) - (ArcTanh[a*x]^4*Log[2/(1 + a*x)])/(a^3*c) - (6*(1 - ArcTanh[a*x])*ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/(a^3*c) + (2*ArcTanh[a*x]^3*PolyLog[2, 1 - 2/(1 + a*x)])/(a^3*c) + (3*(1 - 2*ArcTanh[a*x])*PolyLog[3, 1 - 2/(1 - a*x)])/(a^3*c) + (3*ArcTanh[a*x]^2*PolyLog[3, 1 - 2/(1 + a*x)])/(a^3*c) + (3*PolyLog[4, 1 - 2/(1 - a*x)])/(a^3*c) + (3*ArcTanh[a*x]*PolyLog[4, 1 - 2/(1 + a*x)])/(a^3*c) + (3*PolyLog[5, 1 - 2/(1 + a*x)])/(2*a^3*c)}
{x*ArcTanh[a*x]^4/(c + a*c*x), x, 12, ArcTanh[a*x]^4/(a^2*c) + (x*ArcTanh[a*x]^4)/(a*c) - (4*ArcTanh[a*x]^3*Log[2/(1 - a*x)])/(a^2*c) + (ArcTanh[a*x]^4*Log[2/(1 + a*x)])/(a^2*c) - (6*ArcTanh[a*x]^2*PolyLog[2, 1 - 2/(1 - a*x)])/(a^2*c) - (2*ArcTanh[a*x]^3*PolyLog[2, 1 - 2/(1 + a*x)])/(a^2*c) + (6*ArcTanh[a*x]*PolyLog[3, 1 - 2/(1 - a*x)])/(a^2*c) - (3*ArcTanh[a*x]^2*PolyLog[3, 1 - 2/(1 + a*x)])/(a^2*c) - (3*PolyLog[4, 1 - 2/(1 - a*x)])/(a^2*c) - (3*ArcTanh[a*x]*PolyLog[4, 1 - 2/(1 + a*x)])/(a^2*c) - (3*PolyLog[5, 1 - 2/(1 + a*x)])/(2*a^2*c)}
{ArcTanh[a*x]^4/(c + a*c*x), x, 5, -((ArcTanh[a*x]^4*Log[2/(1 + a*x)])/(a*c)) + (2*ArcTanh[a*x]^3*PolyLog[2, 1 - 2/(1 + a*x)])/(a*c) + (3*ArcTanh[a*x]^2*PolyLog[3, 1 - 2/(1 + a*x)])/(a*c) + (3*ArcTanh[a*x]*PolyLog[4, 1 - 2/(1 + a*x)])/(a*c) + (3*PolyLog[5, 1 - 2/(1 + a*x)])/(2*a*c)}
{ArcTanh[a*x]^4/(x*(c + a*c*x)), x, 5, (ArcTanh[a*x]^4*Log[(2*a*x)/(1 + a*x)])/c - (2*ArcTanh[a*x]^3*PolyLog[2, -1 + 2/(1 + a*x)])/c - (3*ArcTanh[a*x]^2*PolyLog[3, -1 + 2/(1 + a*x)])/c - (3*ArcTanh[a*x]*PolyLog[4, -1 + 2/(1 + a*x)])/c - (3*PolyLog[5, -1 + 2/(1 + a*x)])/(2*c)}
{ArcTanh[a*x]^4/(c*x + a*c*x^2), x, 5, (ArcTanh[a*x]^4*Log[(2*a*x)/(1 + a*x)])/c - (2*ArcTanh[a*x]^3*PolyLog[2, -1 + 2/(1 + a*x)])/c - (3*ArcTanh[a*x]^2*PolyLog[3, -1 + 2/(1 + a*x)])/c - (3*ArcTanh[a*x]*PolyLog[4, -1 + 2/(1 + a*x)])/c - (3*PolyLog[5, -1 + 2/(1 + a*x)])/(2*c)}
{ArcTanh[a*x]^4/(x^2*(c + a*c*x)), x, 12, (a*ArcTanh[a*x]^4)/c - ArcTanh[a*x]^4/(c*x) + (4*a*ArcTanh[a*x]^3*Log[(2*a*x)/(1 + a*x)])/c - (a*ArcTanh[a*x]^4*Log[(2*a*x)/(1 + a*x)])/c - (2*a*(3 - ArcTanh[a*x])*ArcTanh[a*x]^2*PolyLog[2, -1 + 2/(1 + a*x)])/c - (3*a*(2 - ArcTanh[a*x])*ArcTanh[a*x]*PolyLog[3, -1 + 2/(1 + a*x)])/c - (3*a*(1 - ArcTanh[a*x])*PolyLog[4, -1 + 2/(1 + a*x)])/c + (3*a*PolyLog[5, -1 + 2/(1 + a*x)])/(2*c)}
{ArcTanh[a*x]^4/(x^3*(c + a*c*x)), x, 19, (2*a^2*ArcTanh[a*x]^3)/c - (2*a*ArcTanh[a*x]^3)/(c*x) - (a^2*ArcTanh[a*x]^4)/(2*c) - ArcTanh[a*x]^4/(2*c*x^2) + (a*ArcTanh[a*x]^4)/(c*x) + (6*a^2*ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)])/c - (4*a^2*ArcTanh[a*x]^3*Log[(2*a*x)/(1 + a*x)])/c + (a^2*ArcTanh[a*x]^4*Log[(2*a*x)/(1 + a*x)])/c - (2*a^2*ArcTanh[a*x]*(3 - 3*ArcTanh[a*x] + ArcTanh[a*x]^2)*PolyLog[2, -1 + 2/(1 + a*x)])/c - (3*a^2*(1 - ArcTanh[a*x])^2*PolyLog[3, -1 + 2/(1 + a*x)])/c + (3*a^2*(1 - ArcTanh[a*x])*PolyLog[4, -1 + 2/(1 + a*x)])/c - (3*a^2*PolyLog[5, -1 + 2/(1 + a*x)])/(2*c)}

(* {x^3*ArcTanh[a*x]^4/(c - a*c*x), x, 32, -((2*ArcTanh[a*x]^2)/(a^4*c)) - (2*x*ArcTanh[a*x]^2)/(a^3*c) - (4*ArcTanh[a*x]^3)/(3*a^4*c) - (2*x*ArcTanh[a*x]^3)/(a^3*c) - (2*x^2*ArcTanh[a*x]^3)/(3*a^2*c) - (5*ArcTanh[a*x]^4)/(6*a^4*c) - (x*ArcTanh[a*x]^4)/(a^3*c) - (x^2*ArcTanh[a*x]^4)/(2*a^2*c) - (x^3*ArcTanh[a*x]^4)/(3*a*c) + (4*ArcTanh[a*x]*Log[2/(1 - a*x)])/(a^4*c) + (6*ArcTanh[a*x]^2*Log[2/(1 - a*x)])/(a^4*c) + (16*ArcTanh[a*x]^3*Log[2/(1 - a*x)])/(3*a^4*c) + (ArcTanh[a*x]^4*Log[2/(1 - a*x)])/(a^4*c) + (2*(1 + 3*ArcTanh[a*x] + 4*ArcTanh[a*x]^2 + ArcTanh[a*x]^3)*PolyLog[2, 1 - 2/(1 - a*x)])/(a^4*c) - ((3 + 8*ArcTanh[a*x] + 3*ArcTanh[a*x]^2)*PolyLog[3, 1 - 2/(1 - a*x)])/(a^4*c) + ((4 + 3*ArcTanh[a*x])*PolyLog[4, 1 - 2/(1 - a*x)])/(a^4*c) - (3*PolyLog[5, 1 - 2/(1 - a*x)])/(2*a^4*c)} *)
{x^2*ArcTanh[a*x]^4/(c - a*c*x), x, 19, -((2*ArcTanh[a*x]^3)/(a^3*c)) - (2*x*ArcTanh[a*x]^3)/(a^2*c) - ArcTanh[a*x]^4/(2*a^3*c) - (x*ArcTanh[a*x]^4)/(a^2*c) - (x^2*ArcTanh[a*x]^4)/(2*a*c) + (6*ArcTanh[a*x]^2*Log[2/(1 - a*x)])/(a^3*c) + (4*ArcTanh[a*x]^3*Log[2/(1 - a*x)])/(a^3*c) + (ArcTanh[a*x]^4*Log[2/(1 - a*x)])/(a^3*c) + (2*ArcTanh[a*x]*(3 + 3*ArcTanh[a*x] + ArcTanh[a*x]^2)*PolyLog[2, 1 - 2/(1 - a*x)])/(a^3*c) - (3*(1 + ArcTanh[a*x])^2*PolyLog[3, 1 - 2/(1 - a*x)])/(a^3*c) + (3*(1 + ArcTanh[a*x])*PolyLog[4, 1 - 2/(1 - a*x)])/(a^3*c) - (3*PolyLog[5, 1 - 2/(1 - a*x)])/(2*a^3*c)}
{x*ArcTanh[a*x]^4/(c - a*c*x), x, 12, -(ArcTanh[a*x]^4/(a^2*c)) - (x*ArcTanh[a*x]^4)/(a*c) + (4*ArcTanh[a*x]^3*Log[2/(1 - a*x)])/(a^2*c) + (ArcTanh[a*x]^4*Log[2/(1 - a*x)])/(a^2*c) + (2*ArcTanh[a*x]^2*(3 + ArcTanh[a*x])*PolyLog[2, 1 - 2/(1 - a*x)])/(a^2*c) - (3*ArcTanh[a*x]*(2 + ArcTanh[a*x])*PolyLog[3, 1 - 2/(1 - a*x)])/(a^2*c) + (3*(1 + ArcTanh[a*x])*PolyLog[4, 1 - 2/(1 - a*x)])/(a^2*c) - (3*PolyLog[5, 1 - 2/(1 - a*x)])/(2*a^2*c)}
{ArcTanh[a*x]^4/(c - a*c*x), x, 5, (ArcTanh[a*x]^4*Log[2/(1 - a*x)])/(a*c) + (2*ArcTanh[a*x]^3*PolyLog[2, 1 - 2/(1 - a*x)])/(a*c) - (3*ArcTanh[a*x]^2*PolyLog[3, 1 - 2/(1 - a*x)])/(a*c) + (3*ArcTanh[a*x]*PolyLog[4, 1 - 2/(1 - a*x)])/(a*c) - (3*PolyLog[5, 1 - 2/(1 - a*x)])/(2*a*c)}
{ArcTanh[a*x]^4/(x*(c - a*c*x)), x, 5, (ArcTanh[a*x]^4*Log[-((2*a*x)/(1 - a*x))])/c + (2*ArcTanh[a*x]^3*PolyLog[2, -1 + 2/(1 - a*x)])/c - (3*ArcTanh[a*x]^2*PolyLog[3, -1 + 2/(1 - a*x)])/c + (3*ArcTanh[a*x]*PolyLog[4, -1 + 2/(1 - a*x)])/c - (3*PolyLog[5, -1 + 2/(1 - a*x)])/(2*c)}
{ArcTanh[a*x]^4/(c*x - a*c*x^2), x, 5, (ArcTanh[a*x]^4*Log[-((2*a*x)/(1 - a*x))])/c + (2*ArcTanh[a*x]^3*PolyLog[2, -1 + 2/(1 - a*x)])/c - (3*ArcTanh[a*x]^2*PolyLog[3, -1 + 2/(1 - a*x)])/c + (3*ArcTanh[a*x]*PolyLog[4, -1 + 2/(1 - a*x)])/c - (3*PolyLog[5, -1 + 2/(1 - a*x)])/(2*c)}
{ArcTanh[a*x]^4/(x^2*(c - a*c*x)), x, 12, (a*ArcTanh[a*x]^4)/c - ArcTanh[a*x]^4/(c*x) + (a*ArcTanh[a*x]^4*Log[-((2*a*x)/(1 - a*x))])/c + (4*a*ArcTanh[a*x]^3*Log[(2*a*x)/(1 + a*x)])/c + (2*a*ArcTanh[a*x]^3*PolyLog[2, -1 + 2/(1 - a*x)])/c - (6*a*ArcTanh[a*x]^2*PolyLog[2, -1 + 2/(1 + a*x)])/c - (3*a*ArcTanh[a*x]^2*PolyLog[3, -1 + 2/(1 - a*x)])/c - (6*a*ArcTanh[a*x]*PolyLog[3, -1 + 2/(1 + a*x)])/c + (3*a*ArcTanh[a*x]*PolyLog[4, -1 + 2/(1 - a*x)])/c - (3*a*PolyLog[4, -1 + 2/(1 + a*x)])/c - (3*a*PolyLog[5, -1 + 2/(1 - a*x)])/(2*c)}
{ArcTanh[a*x]^4/(x^3*(c - a*c*x)), x, 19, (2*a^2*ArcTanh[a*x]^3)/c - (2*a*ArcTanh[a*x]^3)/(c*x) + (3*a^2*ArcTanh[a*x]^4)/(2*c) - ArcTanh[a*x]^4/(2*c*x^2) - (a*ArcTanh[a*x]^4)/(c*x) + (a^2*ArcTanh[a*x]^4*Log[-((2*a*x)/(1 - a*x))])/c + (6*a^2*ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)])/c + (4*a^2*ArcTanh[a*x]^3*Log[(2*a*x)/(1 + a*x)])/c + (2*a^2*ArcTanh[a*x]^3*PolyLog[2, -1 + 2/(1 - a*x)])/c - (6*a^2*ArcTanh[a*x]*(1 + ArcTanh[a*x])*PolyLog[2, -1 + 2/(1 + a*x)])/c - (3*a^2*ArcTanh[a*x]^2*PolyLog[3, -1 + 2/(1 - a*x)])/c - (3*a^2*(1 + 2*ArcTanh[a*x])*PolyLog[3, -1 + 2/(1 + a*x)])/c + (3*a^2*ArcTanh[a*x]*PolyLog[4, -1 + 2/(1 - a*x)])/c - (3*a^2*PolyLog[4, -1 + 2/(1 + a*x)])/c - (3*a^2*PolyLog[5, -1 + 2/(1 - a*x)])/(2*c)}


(* Integrands of the form x^m/(ArcTanh[a*x]*(c+d*x)) where d=a*c and m is an integer *)
{1/(ArcTanh[a*x]*(c + a*c*x)), x, 7, Log[ArcTanh[a*x]]/(a*c) - Subst[Int[Tanh[x]/x, x], x, ArcTanh[a*x]]/(a*c)}
{1/(ArcTanh[a*x]*x*(c + a*c*x)), x, 10, -(Log[ArcTanh[a*x]]/c) + (2*Subst[Int[Csch[2*x]/x, x], x, ArcTanh[a*x]])/c + Subst[Int[Tanh[x]/x, x], x, ArcTanh[a*x]]/c}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m ArcTanh[a x]^n (c+d x^2)*)


{(1 - a^2*x^2)*ArcTanh[a*x]/x, x, 7, -((a*x)/2) + (1/2)*ArcTanh[a*x] - (1/2)*a^2*x^2*ArcTanh[a*x] - (1/2)*PolyLog[2, (-a)*x] + (1/2)*PolyLog[2, a*x]}
{(1 - a^2*x^2)*ArcTanh[a*x]/x^2, x, 5, - ArcTanh[a*x]/x - a^2*x*ArcTanh[a*x] + a*Log[x] - a*Log[1 - a^2*x^2], -(a/2) - ArcTanh[a*x]/x - a^2*x*ArcTanh[a*x] + a*Log[x] - a*Log[1 - a^2*x^2]}
{(1 - a^2*x^2)*ArcTanh[a*x]/x^3, x, 10, -(a/(2*x)) + (1/2)*a^2*ArcTanh[a*x] - ArcTanh[a*x]/(2*x^2) + (1/2)*a^2*PolyLog[2, (-a)*x] - (1/2)*a^2*PolyLog[2, a*x]}
{(1 - a^2*x^2)*ArcTanh[a*x]/x^4, x, 8, - a/(6*x^2) - ArcTanh[a*x]/(3*x^3) + (a^2*ArcTanh[a*x])/x - (2/3)*a^3*Log[x] + (1/3)*a^3*Log[1 - a^2*x^2], a^3/6 - a/(6*x^2) - ArcTanh[a*x]/(3*x^3) + (a^2*ArcTanh[a*x])/x - (2/3)*a^3*Log[x] + (1/3)*a^3*Log[1 - a^2*x^2]}
{(1 - a^2*x^2)*ArcTanh[a*x]/x^5, x, 3, -(a/(12*x^3)) + a^3/(4*x) - ((1 - a^2*x^2)^2*ArcTanh[a*x])/(4*x^4)}
{(1 - a^2*x^2)*ArcTanh[a*x]/x^6, x, 11, - a/(20*x^4) + a^3/(15*x^2) - ArcTanh[a*x]/(5*x^5) + (a^2*ArcTanh[a*x])/(3*x^3) - (2/15)*a^5*Log[x] + (1/15)*a^5*Log[1 - a^2*x^2], a^5/30 - a/(20*x^4) + a^3/(15*x^2) - ArcTanh[a*x]/(5*x^5) + (a^2*ArcTanh[a*x])/(3*x^3) - (2/15)*a^5*Log[x] + (1/15)*a^5*Log[1 - a^2*x^2]}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m ArcTanh[a x]^n / (c+d x^2)*)


(* Integrands of the form x^m*ArcTanh[a*x]/(1-a^2*x^2) where m is an integer *)
{x^3*ArcTanh[a*x]/(1 - a^2*x^2), x, 6, -(x/(2*a^3)) + ArcTanh[a*x]/(2*a^4) - (x^2*ArcTanh[a*x])/(2*a^2) - ArcTanh[a*x]^2/(2*a^4) + (ArcTanh[a*x]*Log[2/(1 - a*x)])/a^4 + PolyLog[2, 1 - 2/(1 - a*x)]/(2*a^4)}
{x^2*ArcTanh[a*x]/(1 - a^2*x^2), x, 3, -((x*ArcTanh[a*x])/a^2) + ArcTanh[a*x]^2/(2*a^3) - Log[1 - a^2*x^2]/(2*a^3)}
{x*ArcTanh[a*x]/(1 - a^2*x^2), x, 3, -(ArcTanh[a*x]^2/(2*a^2)) + (ArcTanh[a*x]*Log[2/(1 - a*x)])/a^2 + PolyLog[2, 1 - 2/(1 - a*x)]/(2*a^2)}
{ArcTanh[a*x]/(1 - a^2*x^2), x, 1, ArcTanh[a*x]^2/(2*a)}
{ArcTanh[a*x]/(x*(1 - a^2*x^2)), x, 3, (1/2)*ArcTanh[a*x]^2 + ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)] - (1/2)*PolyLog[2, -1 + 2/(1 + a*x)]}
{ArcTanh[a*x]/(x^2*(1 - a^2*x^2)), x, 4, -(ArcTanh[a*x]/x) + (1/2)*a*ArcTanh[a*x]^2 - a*ArcTanh[1 - 2*a^2*x^2]}
{ArcTanh[a*x]/(x^3*(1 - a^2*x^2)), x, 6, -(a/(2*x)) + (1/2)*a^2*ArcTanh[a*x] - ArcTanh[a*x]/(2*x^2) + (1/2)*a^2*ArcTanh[a*x]^2 + a^2*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)] - (1/2)*a^2*PolyLog[2, -1 + 2/(1 + a*x)]}


(* Integrands of the form x^m*ArcTanh[a*x]^2/(1-a^2*x^2) where m is an integer *)
{x^3*ArcTanh[a*x]^2/(1 - a^2*x^2), x, 7, -((x*ArcTanh[a*x])/a^3) + ArcTanh[a*x]^2/(2*a^4) - (x^2*ArcTanh[a*x]^2)/(2*a^2) - ArcTanh[a*x]^3/(3*a^4) + (ArcTanh[a*x]^2*Log[2/(1 - a*x)])/a^4 - Log[1 - a^2*x^2]/(2*a^4) + (ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/a^4 - PolyLog[3, 1 - 2/(1 - a*x)]/(2*a^4)}
{x^2*ArcTanh[a*x]^2/(1 - a^2*x^2), x, 6, -(ArcTanh[a*x]^2/a^3) - (x*ArcTanh[a*x]^2)/a^2 + ArcTanh[a*x]^3/(3*a^3) + (2*ArcTanh[a*x]*Log[2/(1 - a*x)])/a^3 + PolyLog[2, 1 - 2/(1 - a*x)]/a^3}
{x*ArcTanh[a*x]^2/(1 - a^2*x^2), x, 4, -(ArcTanh[a*x]^3/(3*a^2)) + (ArcTanh[a*x]^2*Log[2/(1 - a*x)])/a^2 + (ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/a^2 - PolyLog[3, 1 - 2/(1 - a*x)]/(2*a^2)}
{ArcTanh[a*x]^2/(1 - a^2*x^2), x, 1, ArcTanh[a*x]^3/(3*a)}
{ArcTanh[a*x]^2/(x*(1 - a^2*x^2)), x, 4, (1/3)*ArcTanh[a*x]^3 + ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)] - ArcTanh[a*x]*PolyLog[2, -1 + 2/(1 + a*x)] - (1/2)*PolyLog[3, -1 + 2/(1 + a*x)]}
{ArcTanh[a*x]^2/(x^2*(1 - a^2*x^2)), x, 6, a*ArcTanh[a*x]^2 - ArcTanh[a*x]^2/x + (1/3)*a*ArcTanh[a*x]^3 + 2*a*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)] - a*PolyLog[2, -1 + 2/(1 + a*x)]}
{ArcTanh[a*x]^2/(x^3*(1 - a^2*x^2)), x, 8, -((a*ArcTanh[a*x])/x) + (1/2)*a^2*ArcTanh[a*x]^2 - ArcTanh[a*x]^2/(2*x^2) + (1/3)*a^2*ArcTanh[a*x]^3 - a^2*ArcTanh[1 - 2*a^2*x^2] + a^2*ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)] - a^2*ArcTanh[a*x]*PolyLog[2, -1 + 2/(1 + a*x)] - (1/2)*a^2*PolyLog[3, -1 + 2/(1 + a*x)]}


(* Integrands of the form x^m*ArcTanh[a*x]^3/(1-a^2*x^2) where m is an integer *)
{x^3*ArcTanh[a*x]^3/(1 - a^2*x^2), x, 11, -((3*ArcTanh[a*x]^2)/(2*a^4)) - (3*x*ArcTanh[a*x]^2)/(2*a^3) + ArcTanh[a*x]^3/(2*a^4) - (x^2*ArcTanh[a*x]^3)/(2*a^2) - ArcTanh[a*x]^4/(4*a^4) + (3*ArcTanh[a*x]*Log[2/(1 - a*x)])/a^4 + (ArcTanh[a*x]^3*Log[2/(1 - a*x)])/a^4 + (3*(1 + ArcTanh[a*x]^2)*PolyLog[2, 1 - 2/(1 - a*x)])/(2*a^4) - (3*ArcTanh[a*x]*PolyLog[3, 1 - 2/(1 - a*x)])/(2*a^4) + (3*PolyLog[4, 1 - 2/(1 - a*x)])/(4*a^4)}
{x^2*ArcTanh[a*x]^3/(1 - a^2*x^2), x, 7, -(ArcTanh[a*x]^3/a^3) - (x*ArcTanh[a*x]^3)/a^2 + ArcTanh[a*x]^4/(4*a^3) + (3*ArcTanh[a*x]^2*Log[2/(1 - a*x)])/a^3 + (3*ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/a^3 - (3*PolyLog[3, 1 - 2/(1 - a*x)])/(2*a^3)}
{x*ArcTanh[a*x]^3/(1 - a^2*x^2), x, 5, -(ArcTanh[a*x]^4/(4*a^2)) + (ArcTanh[a*x]^3*Log[2/(1 - a*x)])/a^2 + (3*ArcTanh[a*x]^2*PolyLog[2, 1 - 2/(1 - a*x)])/(2*a^2) - (3*ArcTanh[a*x]*PolyLog[3, 1 - 2/(1 - a*x)])/(2*a^2) + (3*PolyLog[4, 1 - 2/(1 - a*x)])/(4*a^2)}
{ArcTanh[a*x]^3/(1 - a^2*x^2), x, 1, ArcTanh[a*x]^4/(4*a)}
{ArcTanh[a*x]^3/(x*(1 - a^2*x^2)), x, 5, (1/4)*ArcTanh[a*x]^4 + ArcTanh[a*x]^3*Log[(2*a*x)/(1 + a*x)] - (3/2)*ArcTanh[a*x]^2*PolyLog[2, -1 + 2/(1 + a*x)] - (3/2)*ArcTanh[a*x]*PolyLog[3, -1 + 2/(1 + a*x)] - (3/4)*PolyLog[4, -1 + 2/(1 + a*x)]}
{ArcTanh[a*x]^3/(x^2*(1 - a^2*x^2)), x, 7, a*ArcTanh[a*x]^3 - ArcTanh[a*x]^3/x + (1/4)*a*ArcTanh[a*x]^4 + 3*a*ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)] - 3*a*ArcTanh[a*x]*PolyLog[2, -1 + 2/(1 + a*x)] - (3/2)*a*PolyLog[3, -1 + 2/(1 + a*x)]}
{ArcTanh[a*x]^3/(x^3*(1 - a^2*x^2)), x, 11, (3/2)*a^2*ArcTanh[a*x]^2 - (3*a*ArcTanh[a*x]^2)/(2*x) + (1/2)*a^2*ArcTanh[a*x]^3 - ArcTanh[a*x]^3/(2*x^2) + (1/4)*a^2*ArcTanh[a*x]^4 + 3*a^2*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)] + a^2*ArcTanh[a*x]^3*Log[(2*a*x)/(1 + a*x)] - (3/2)*a^2*(1 + ArcTanh[a*x]^2)*PolyLog[2, -1 + 2/(1 + a*x)] - (3/2)*a^2*ArcTanh[a*x]*PolyLog[3, -1 + 2/(1 + a*x)] - (3/4)*a^2*PolyLog[4, -1 + 2/(1 + a*x)]}


(* Integrands of the form x^m/(ArcTanh[a*x]*(1-a^2*x^2)) where m is an integer *)
{x/((1 - a^2*x^2)*ArcTanh[a*x]), x, 1, Subst[Int[Tanh[x]/x, x], x, ArcTanh[a*x]]/a^2}
{1/((1 - a^2*x^2)*ArcTanh[a*x]), x, 1, Log[ArcTanh[a*x]]/a}
{1/(x*(1 - a^2*x^2)*ArcTanh[a*x]), x, 1, Subst[Int[Coth[x]/x, x], x, ArcTanh[a*x]]}


(* Integrands of the form x^m/(ArcTanh[a*x]^2*(1-a^2*x^2)) where m is an integer *)
{x/((1 - a^2*x^2)*ArcTanh[a*x]^2), x, 1, Subst[Int[Tanh[x]/x^2, x], x, ArcTanh[a*x]]/a^2}
{1/((1 - a^2*x^2)*ArcTanh[a*x]^2), x, 1, -(1/(a*ArcTanh[a*x]))}
{1/(x*(1 - a^2*x^2)*ArcTanh[a*x]^2), x, 1, Subst[Int[Coth[x]/x^2, x], x, ArcTanh[a*x]]}


(* Integrands of the form x^m/(ArcTanh[a*x]^3*(1-a^2*x^2)) where m is an integer *)
{x/((1 - a^2*x^2)*ArcTanh[a*x]^3), x, 1, Subst[Int[Tanh[x]/x^3, x], x, ArcTanh[a*x]]/a^2}
{1/((1 - a^2*x^2)*ArcTanh[a*x]^3), x, 1, -(1/(2*a*ArcTanh[a*x]^2))}
{1/(x*(1 - a^2*x^2)*ArcTanh[a*x]^3), x, 1, Subst[Int[Coth[x]/x^3, x], x, ArcTanh[a*x]]}


(* Integrands of the form ArcTanh[a*x]^n/(1-a^2*x^2) where n is an integer *)
{ArcTanh[a*x]^(1/2)/(1 - a^2*x^2), x, 1, (2*ArcTanh[a*x]^(3/2))/(3*a)}
{ArcTanh[a*x]^n/(1 - a^2*x^2), x, 1, ArcTanh[a*x]^(1 + n)/(a*(1 + n))}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m ArcTanh[a x]^n / (c+d x^2)^2*)


(* Integrands of the form x^m*ArcTanh[a*x]/(1-a^2*x^2)^2 where m is an integer *)
{x^3*ArcTanh[a*x]/(1 - a^2*x^2)^2, x, 7, -(x/(4*a^3*(1 - a^2*x^2))) - ArcTanh[a*x]/(4*a^4) + ArcTanh[a*x]/(2*a^4*(1 - a^2*x^2)) + ArcTanh[a*x]^2/(2*a^4) - (ArcTanh[a*x]*Log[2/(1 - a*x)])/a^4 - PolyLog[2, 1 - 2/(1 - a*x)]/(2*a^4)}
{x^2*ArcTanh[a*x]/(1 - a^2*x^2)^2, x, 4, -(1/(4*a^3*(1 - a^2*x^2))) + (x*ArcTanh[a*x])/(2*a^2*(1 - a^2*x^2)) - ArcTanh[a*x]^2/(4*a^3)}
{x*ArcTanh[a*x]/(1 - a^2*x^2)^2, x, 3, -(x/(4*a*(1 - a^2*x^2))) - ArcTanh[a*x]/(4*a^2) + ArcTanh[a*x]/(2*a^2*(1 - a^2*x^2))}
{ArcTanh[a*x]/(1 - a^2*x^2)^2, x, 2, -(1/(4*a*(1 - a^2*x^2))) + (x*ArcTanh[a*x])/(2*(1 - a^2*x^2)) + ArcTanh[a*x]^2/(4*a)}
{ArcTanh[a*x]/(x*(1 - a^2*x^2)^2), x, 7, -((a*x)/(4*(1 - a^2*x^2))) - (1/4)*ArcTanh[a*x] + ArcTanh[a*x]/(2*(1 - a^2*x^2)) + (1/2)*ArcTanh[a*x]^2 + ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)] - (1/2)*PolyLog[2, -1 + 2/(1 + a*x)]}
{ArcTanh[a*x]/(x^2*(1 - a^2*x^2)^2), x, 7, -(a/(4*(1 - a^2*x^2))) - ArcTanh[a*x]/x + (a^2*x*ArcTanh[a*x])/(2*(1 - a^2*x^2)) + (3/4)*a*ArcTanh[a*x]^2 - a*ArcTanh[1 - 2*a^2*x^2]}
{ArcTanh[a*x]/(x^3*(1 - a^2*x^2)^2), x, 14, -(a/(2*x)) - (a^3*x)/(4*(1 - a^2*x^2)) + (1/4)*a^2*ArcTanh[a*x] - ArcTanh[a*x]/(2*x^2) + (a^2*ArcTanh[a*x])/(2*(1 - a^2*x^2)) + a^2*ArcTanh[a*x]^2 + 2*a^2*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)] - a^2*PolyLog[2, -1 + 2/(1 + a*x)]}


(* Integrands of the form x^m*ArcTanh[a*x]^2/(1-a^2*x^2)^2 where m is an integer *)
{x^3*ArcTanh[a*x]^2/(1 - a^2*x^2)^2, x, 8, 1/(4*a^4*(1 - a^2*x^2)) - (x*ArcTanh[a*x])/(2*a^3*(1 - a^2*x^2)) - ArcTanh[a*x]^2/(4*a^4) + ArcTanh[a*x]^2/(2*a^4*(1 - a^2*x^2)) + ArcTanh[a*x]^3/(3*a^4) - (ArcTanh[a*x]^2*Log[2/(1 - a*x)])/a^4 - (ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/a^4 + PolyLog[3, 1 - 2/(1 - a*x)]/(2*a^4)}
{x^2*ArcTanh[a*x]^2/(1 - a^2*x^2)^2, x, 6, x/(4*a^2*(1 - a^2*x^2)) + ArcTanh[a*x]/(4*a^3) - ArcTanh[a*x]/(2*a^3*(1 - a^2*x^2)) + (x*ArcTanh[a*x]^2)/(2*a^2*(1 - a^2*x^2)) - ArcTanh[a*x]^3/(6*a^3)}
{x*ArcTanh[a*x]^2/(1 - a^2*x^2)^2, x, 3, 1/(4*a^2*(1 - a^2*x^2)) - (x*ArcTanh[a*x])/(2*a*(1 - a^2*x^2)) - ArcTanh[a*x]^2/(4*a^2) + ArcTanh[a*x]^2/(2*a^2*(1 - a^2*x^2))}
{ArcTanh[a*x]^2/(1 - a^2*x^2)^2, x, 4, x/(4*(1 - a^2*x^2)) + ArcTanh[a*x]/(4*a) - ArcTanh[a*x]/(2*a*(1 - a^2*x^2)) + (x*ArcTanh[a*x]^2)/(2*(1 - a^2*x^2)) + ArcTanh[a*x]^3/(6*a)}
{ArcTanh[a*x]^2/(x*(1 - a^2*x^2)^2), x, 8, 1/(4*(1 - a^2*x^2)) - (a*x*ArcTanh[a*x])/(2*(1 - a^2*x^2)) - (1/4)*ArcTanh[a*x]^2 + ArcTanh[a*x]^2/(2*(1 - a^2*x^2)) + (1/3)*ArcTanh[a*x]^3 + ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)] - ArcTanh[a*x]*PolyLog[2, -1 + 2/(1 + a*x)] - (1/2)*PolyLog[3, -1 + 2/(1 + a*x)]}
{ArcTanh[a*x]^2/(x^2*(1 - a^2*x^2)^2), x, 11, (a^2*x)/(4*(1 - a^2*x^2)) + (1/4)*a*ArcTanh[a*x] - (a*ArcTanh[a*x])/(2*(1 - a^2*x^2)) + a*ArcTanh[a*x]^2 - ArcTanh[a*x]^2/x + (a^2*x*ArcTanh[a*x]^2)/(2*(1 - a^2*x^2)) + (1/2)*a*ArcTanh[a*x]^3 + 2*a*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)] - a*PolyLog[2, -1 + 2/(1 + a*x)]}
{ArcTanh[a*x]^2/(x^3*(1 - a^2*x^2)^2), x, 17, a^2/(4*(1 - a^2*x^2)) - (a*ArcTanh[a*x])/x - (a^3*x*ArcTanh[a*x])/(2*(1 - a^2*x^2)) + (1/4)*a^2*ArcTanh[a*x]^2 - ArcTanh[a*x]^2/(2*x^2) + (a^2*ArcTanh[a*x]^2)/(2*(1 - a^2*x^2)) + (2/3)*a^2*ArcTanh[a*x]^3 - a^2*ArcTanh[1 - 2*a^2*x^2] + 2*a^2*ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)] - 2*a^2*ArcTanh[a*x]*PolyLog[2, -1 + 2/(1 + a*x)] - a^2*PolyLog[3, -1 + 2/(1 + a*x)]}


(* Integrands of the form x^m*ArcTanh[a*x]^3/(1-a^2*x^2)^2 where m is an integer *)
{x^3*ArcTanh[a*x]^3/(1 - a^2*x^2)^2, x, 11, -((3*x)/(8*a^3*(1 - a^2*x^2))) - (3*ArcTanh[a*x])/(8*a^4) + (3*ArcTanh[a*x])/(4*a^4*(1 - a^2*x^2)) - (3*x*ArcTanh[a*x]^2)/(4*a^3*(1 - a^2*x^2)) - ArcTanh[a*x]^3/(4*a^4) + ArcTanh[a*x]^3/(2*a^4*(1 - a^2*x^2)) + ArcTanh[a*x]^4/(4*a^4) - (ArcTanh[a*x]^3*Log[2/(1 - a*x)])/a^4 - (3*ArcTanh[a*x]^2*PolyLog[2, 1 - 2/(1 - a*x)])/(2*a^4) + (3*ArcTanh[a*x]*PolyLog[3, 1 - 2/(1 - a*x)])/(2*a^4) - (3*PolyLog[4, 1 - 2/(1 - a*x)])/(4*a^4)}
{x^2*ArcTanh[a*x]^3/(1 - a^2*x^2)^2, x, 6, -(3/(8*a^3*(1 - a^2*x^2))) + (3*x*ArcTanh[a*x])/(4*a^2*(1 - a^2*x^2)) + (3*ArcTanh[a*x]^2)/(8*a^3) - (3*ArcTanh[a*x]^2)/(4*a^3*(1 - a^2*x^2)) + (x*ArcTanh[a*x]^3)/(2*a^2*(1 - a^2*x^2)) - ArcTanh[a*x]^4/(8*a^3)}
{x*ArcTanh[a*x]^3/(1 - a^2*x^2)^2, x, 5, -((3*x)/(8*a*(1 - a^2*x^2))) - (3*ArcTanh[a*x])/(8*a^2) + (3*ArcTanh[a*x])/(4*a^2*(1 - a^2*x^2)) - (3*x*ArcTanh[a*x]^2)/(4*a*(1 - a^2*x^2)) - ArcTanh[a*x]^3/(4*a^2) + ArcTanh[a*x]^3/(2*a^2*(1 - a^2*x^2))}
{ArcTanh[a*x]^3/(1 - a^2*x^2)^2, x, 4, -(3/(8*a*(1 - a^2*x^2))) + (3*x*ArcTanh[a*x])/(4*(1 - a^2*x^2)) + (3*ArcTanh[a*x]^2)/(8*a) - (3*ArcTanh[a*x]^2)/(4*a*(1 - a^2*x^2)) + (x*ArcTanh[a*x]^3)/(2*(1 - a^2*x^2)) + ArcTanh[a*x]^4/(8*a)}
{ArcTanh[a*x]^3/(x*(1 - a^2*x^2)^2), x, 11, -((3*a*x)/(8*(1 - a^2*x^2))) - (3/8)*ArcTanh[a*x] + (3*ArcTanh[a*x])/(4*(1 - a^2*x^2)) - (3*a*x*ArcTanh[a*x]^2)/(4*(1 - a^2*x^2)) - (1/4)*ArcTanh[a*x]^3 + ArcTanh[a*x]^3/(2*(1 - a^2*x^2)) + (1/4)*ArcTanh[a*x]^4 + ArcTanh[a*x]^3*Log[(2*a*x)/(1 + a*x)] - (3/2)*ArcTanh[a*x]^2*PolyLog[2, -1 + 2/(1 + a*x)] - (3/2)*ArcTanh[a*x]*PolyLog[3, -1 + 2/(1 + a*x)] - (3/4)*PolyLog[4, -1 + 2/(1 + a*x)]}
{ArcTanh[a*x]^3/(x^2*(1 - a^2*x^2)^2), x, 12, -((3*a)/(8*(1 - a^2*x^2))) + (3*a^2*x*ArcTanh[a*x])/(4*(1 - a^2*x^2)) + (3/8)*a*ArcTanh[a*x]^2 - (3*a*ArcTanh[a*x]^2)/(4*(1 - a^2*x^2)) + a*ArcTanh[a*x]^3 - ArcTanh[a*x]^3/x + (a^2*x*ArcTanh[a*x]^3)/(2*(1 - a^2*x^2)) + (3/8)*a*ArcTanh[a*x]^4 + 3*a*ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)] - 3*a*ArcTanh[a*x]*PolyLog[2, -1 + 2/(1 + a*x)] - (3/2)*a*PolyLog[3, -1 + 2/(1 + a*x)]}
{ArcTanh[a*x]^3/(x^3*(1 - a^2*x^2)^2), x, 23, -((3*a^3*x)/(8*(1 - a^2*x^2))) - (3/8)*a^2*ArcTanh[a*x] + (3*a^2*ArcTanh[a*x])/(4*(1 - a^2*x^2)) + (3/2)*a^2*ArcTanh[a*x]^2 - (3*a*ArcTanh[a*x]^2)/(2*x) - (3*a^3*x*ArcTanh[a*x]^2)/(4*(1 - a^2*x^2)) + (1/4)*a^2*ArcTanh[a*x]^3 - ArcTanh[a*x]^3/(2*x^2) + (a^2*ArcTanh[a*x]^3)/(2*(1 - a^2*x^2)) + (1/2)*a^2*ArcTanh[a*x]^4 + 3*a^2*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)] + 2*a^2*ArcTanh[a*x]^3*Log[(2*a*x)/(1 + a*x)] - (3/2)*a^2*(1 + 2*ArcTanh[a*x]^2)*PolyLog[2, -1 + 2/(1 + a*x)] - 3*a^2*ArcTanh[a*x]*PolyLog[3, -1 + 2/(1 + a*x)] - (3/2)*a^2*PolyLog[4, -1 + 2/(1 + a*x)]}


(* Integrands of the form x^m/(ArcTanh[a*x]*(1-a^2*x^2)^2) where m is an integer *)
{x^3/((1 - a^2*x^2)^2*ArcTanh[a*x]), x, 5, SinhIntegral[2*ArcTanh[a*x]]/(2*a^4) - Subst[Int[Tanh[x]/x, x], x, ArcTanh[a*x]]/a^4}
{x^2/((1 - a^2*x^2)^2*ArcTanh[a*x]), x, 4, CoshIntegral[2*ArcTanh[a*x]]/(2*a^3) - Log[ArcTanh[a*x]]/(2*a^3)}
{x/((1 - a^2*x^2)^2*ArcTanh[a*x]), x, 3, SinhIntegral[2*ArcTanh[a*x]]/(2*a^2)}
{1/((1 - a^2*x^2)^2*ArcTanh[a*x]), x, 5, CoshIntegral[2*ArcTanh[a*x]]/(2*a) + Log[ArcTanh[a*x]]/(2*a)}
{1/(x*(1 - a^2*x^2)^2*ArcTanh[a*x]), x, 5, (1/2)*SinhIntegral[2*ArcTanh[a*x]] + Subst[Int[Coth[x]/x, x], x, ArcTanh[a*x]]}


(* Integrands of the form x^m/(ArcTanh[a*x]^2*(1-a^2*x^2)^2) where m is an integer *)
{x^3/((1 - a^2*x^2)^2*ArcTanh[a*x]^2), x, 6, -(x/(a^3*(1 - a^2*x^2)*ArcTanh[a*x])) + CoshIntegral[2*ArcTanh[a*x]]/a^4 - Subst[Int[Tanh[x]/x^2, x], x, ArcTanh[a*x]]/a^4}
{x^2/((1 - a^2*x^2)^2*ArcTanh[a*x]^2), x, 4, -(x^2/(a*(1 - a^2*x^2)*ArcTanh[a*x])) + SinhIntegral[2*ArcTanh[a*x]]/a^3}
{x/((1 - a^2*x^2)^2*ArcTanh[a*x]^2), x, 4, -(x/(a*(1 - a^2*x^2)*ArcTanh[a*x])) + CoshIntegral[2*ArcTanh[a*x]]/a^2}
{1/((1 - a^2*x^2)^2*ArcTanh[a*x]^2), x, 4, -(1/(a*(1 - a^2*x^2)*ArcTanh[a*x])) + SinhIntegral[2*ArcTanh[a*x]]/a}
{1/(x*(1 - a^2*x^2)^2*ArcTanh[a*x]^2), x, 6, -((a*x)/((1 - a^2*x^2)*ArcTanh[a*x])) + CoshIntegral[2*ArcTanh[a*x]] + Subst[Int[Coth[x]/x^2, x], x, ArcTanh[a*x]]}


(* Integrands of the form x^m/(ArcTanh[a*x]^3*(1-a^2*x^2)^2) where m is an integer *)
{x^3/((1 - a^2*x^2)^2*ArcTanh[a*x]^3), x, 6, -(x/(2*a^3*(1 - a^2*x^2)*ArcTanh[a*x]^2)) - (1 + a^2*x^2)/(2*a^4*(1 - a^2*x^2)*ArcTanh[a*x]) + SinhIntegral[2*ArcTanh[a*x]]/a^4 - Subst[Int[Tanh[x]/x^3, x], x, ArcTanh[a*x]]/a^4}
{x^2/((1 - a^2*x^2)^2*ArcTanh[a*x]^3), x, 5, -(x^2/(2*a*(1 - a^2*x^2)*ArcTanh[a*x]^2)) - x/(a^2*(1 - a^2*x^2)*ArcTanh[a*x]) + CoshIntegral[2*ArcTanh[a*x]]/a^3}
{x/((1 - a^2*x^2)^2*ArcTanh[a*x]^3), x, 4, -(x/(2*a*(1 - a^2*x^2)*ArcTanh[a*x]^2)) - (1 + a^2*x^2)/(2*a^2*(1 - a^2*x^2)*ArcTanh[a*x]) + SinhIntegral[2*ArcTanh[a*x]]/a^2}
{1/((1 - a^2*x^2)^2*ArcTanh[a*x]^3), x, 5, -(1/(2*a*(1 - a^2*x^2)*ArcTanh[a*x]^2)) - x/((1 - a^2*x^2)*ArcTanh[a*x]) + CoshIntegral[2*ArcTanh[a*x]]/a}
{1/(x*(1 - a^2*x^2)^2*ArcTanh[a*x]^3), x, 6, -((a*x)/(2*(1 - a^2*x^2)*ArcTanh[a*x]^2)) - (1 + a^2*x^2)/(2*(1 - a^2*x^2)*ArcTanh[a*x]) + SinhIntegral[2*ArcTanh[a*x]] + Subst[Int[Coth[x]/x^3, x], x, ArcTanh[a*x]]}


{1/((1 - a^2*x^2)^2*ArcTanh[a*x]^4), x, 5, -(1/(3*a*(1 - a^2*x^2)*ArcTanh[a*x]^3)) - x/(3*(1 - a^2*x^2)*ArcTanh[a*x]^2) - (1 + a^2*x^2)/(3*a*(1 - a^2*x^2)*ArcTanh[a*x]) + (2*SinhIntegral[2*ArcTanh[a*x]])/(3*a)}
{1/((1 - a^2*x^2)^2*ArcTanh[a*x]^5), x, 6, -(1/(4*a*(1 - a^2*x^2)*ArcTanh[a*x]^4)) - x/(6*(1 - a^2*x^2)*ArcTanh[a*x]^3) - (1 + a^2*x^2)/(12*a*(1 - a^2*x^2)*ArcTanh[a*x]^2) - x/(3*(1 - a^2*x^2)*ArcTanh[a*x]) + CoshIntegral[2*ArcTanh[a*x]]/(3*a)}
{1/((1 - a^2*x^2)^2*ArcTanh[a*x]^6), x, 6, -(1/(5*a*(1 - a^2*x^2)*ArcTanh[a*x]^5)) - x/(10*(1 - a^2*x^2)*ArcTanh[a*x]^4) - (1 + a^2*x^2)/(30*a*(1 - a^2*x^2)*ArcTanh[a*x]^3) - x/(15*(1 - a^2*x^2)*ArcTanh[a*x]^2) - (1 + a^2*x^2)/(15*a*(1 - a^2*x^2)*ArcTanh[a*x]) + (2*SinhIntegral[2*ArcTanh[a*x]])/(15*a)}
{1/((1 - a^2*x^2)^2*ArcTanh[a*x]^7), x, 7, -(1/(6*a*(1 - a^2*x^2)*ArcTanh[a*x]^6)) - x/(15*(1 - a^2*x^2)*ArcTanh[a*x]^5) - (1 + a^2*x^2)/(60*a*(1 - a^2*x^2)*ArcTanh[a*x]^4) - x/(45*(1 - a^2*x^2)*ArcTanh[a*x]^3) - (1 + a^2*x^2)/(90*a*(1 - a^2*x^2)*ArcTanh[a*x]^2) - (2*x)/(45*(1 - a^2*x^2)*ArcTanh[a*x]) + (2*CoshIntegral[2*ArcTanh[a*x]])/(45*a)}
{1/((1 - a^2*x^2)^2*ArcTanh[a*x]^8), x, 7, -(1/(7*a*(1 - a^2*x^2)*ArcTanh[a*x]^7)) - x/(21*(1 - a^2*x^2)*ArcTanh[a*x]^6) - (1 + a^2*x^2)/(105*a*(1 - a^2*x^2)*ArcTanh[a*x]^5) - x/(105*(1 - a^2*x^2)*ArcTanh[a*x]^4) - (1 + a^2*x^2)/(315*a*(1 - a^2*x^2)*ArcTanh[a*x]^3) - (2*x)/(315*(1 - a^2*x^2)*ArcTanh[a*x]^2) - (2*(1 + a^2*x^2))/(315*a*(1 - a^2*x^2)*ArcTanh[a*x]) + (4*SinhIntegral[2*ArcTanh[a*x]])/(315*a)}


(* Integrands of the form x^m*ArcTanh[a*x]^(1/2)/(1-a^2*x^2)^2 where m is an integer *)
{Sqrt[ArcTanh[a*x]]/(1 - a^2*x^2)^2, x, 9, ArcTanh[a*x]^(3/2)/(3*a) + (Sqrt[Pi/2]*Erf[Sqrt[2]*Sqrt[ArcTanh[a*x]]])/(16*a) - (Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[ArcTanh[a*x]]])/(16*a) + (Sqrt[ArcTanh[a*x]]*Sinh[2*ArcTanh[a*x]])/(4*a)}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m ArcTanh[a x]^n / (c+d x^2)^3*)


(* Integrands of the form x^m*ArcTanh[a*x]/(1-a^2*x^2)^3 where m is an integer *)
{x^3*ArcTanh[a*x]/(1 - a^2*x^2)^3, x, 8, -(x/(16*a^3*(1 - a^2*x^2)^2)) + (5*x)/(32*a^3*(1 - a^2*x^2)) + (5*ArcTanh[a*x])/(32*a^4) + ArcTanh[a*x]/(4*a^4*(1 - a^2*x^2)^2) - ArcTanh[a*x]/(2*a^4*(1 - a^2*x^2))}
{x^2*ArcTanh[a*x]/(1 - a^2*x^2)^3, x, 6, -(1/(16*a^3*(1 - a^2*x^2)^2)) + 1/(16*a^3*(1 - a^2*x^2)) + (x*ArcTanh[a*x])/(4*a^2*(1 - a^2*x^2)^2) - (x*ArcTanh[a*x])/(8*a^2*(1 - a^2*x^2)) - ArcTanh[a*x]^2/(16*a^3)}
{x*ArcTanh[a*x]/(1 - a^2*x^2)^3, x, 4, -(x/(16*a*(1 - a^2*x^2)^2)) - (3*x)/(32*a*(1 - a^2*x^2)) - (3*ArcTanh[a*x])/(32*a^2) + ArcTanh[a*x]/(4*a^2*(1 - a^2*x^2)^2)}
{ArcTanh[a*x]/(1 - a^2*x^2)^3, x, 3, -(1/(16*a*(1 - a^2*x^2)^2)) - 3/(16*a*(1 - a^2*x^2)) + (x*ArcTanh[a*x])/(4*(1 - a^2*x^2)^2) + (3*x*ArcTanh[a*x])/(8*(1 - a^2*x^2)) + (3*ArcTanh[a*x]^2)/(16*a)}
{ArcTanh[a*x]/(x*(1 - a^2*x^2)^3), x, 12, -((a*x)/(16*(1 - a^2*x^2)^2)) - (11*a*x)/(32*(1 - a^2*x^2)) - (11/32)*ArcTanh[a*x] + ArcTanh[a*x]/(4*(1 - a^2*x^2)^2) + ArcTanh[a*x]/(2*(1 - a^2*x^2)) + (1/2)*ArcTanh[a*x]^2 + ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)] - (1/2)*PolyLog[2, -1 + 2/(1 + a*x)]}
{ArcTanh[a*x]/(x^2*(1 - a^2*x^2)^3), x, 11, -(a/(16*(1 - a^2*x^2)^2)) - (7*a)/(16*(1 - a^2*x^2)) - ArcTanh[a*x]/x + (a^2*x*ArcTanh[a*x])/(4*(1 - a^2*x^2)^2) + (7*a^2*x*ArcTanh[a*x])/(8*(1 - a^2*x^2)) + (15/16)*a*ArcTanh[a*x]^2 - a*ArcTanh[1 - 2*a^2*x^2]}


(* Integrands of the form x^m*ArcTanh[a*x]^2/(1-a^2*x^2)^3 where m is an integer *)
{x^3*ArcTanh[a*x]^2/(1 - a^2*x^2)^3, x, 8, 1/(32*a^4*(1 - a^2*x^2)^2) - 5/(32*a^4*(1 - a^2*x^2)) - (x*ArcTanh[a*x])/(8*a^3*(1 - a^2*x^2)^2) + (5*x*ArcTanh[a*x])/(16*a^3*(1 - a^2*x^2)) + (5*ArcTanh[a*x]^2)/(32*a^4) + ArcTanh[a*x]^2/(4*a^4*(1 - a^2*x^2)^2) - ArcTanh[a*x]^2/(2*a^4*(1 - a^2*x^2))}
{x^2*ArcTanh[a*x]^2/(1 - a^2*x^2)^3, x, 13, x/(32*a^2*(1 - a^2*x^2)^2) - x/(64*a^2*(1 - a^2*x^2)) - ArcTanh[a*x]/(64*a^3) - ArcTanh[a*x]/(8*a^3*(1 - a^2*x^2)^2) + ArcTanh[a*x]/(8*a^3*(1 - a^2*x^2)) + (x*ArcTanh[a*x]^2)/(4*a^2*(1 - a^2*x^2)^2) - (x*ArcTanh[a*x]^2)/(8*a^2*(1 - a^2*x^2)) - ArcTanh[a*x]^3/(24*a^3)}
{x*ArcTanh[a*x]^2/(1 - a^2*x^2)^3, x, 4, 1/(32*a^2*(1 - a^2*x^2)^2) + 3/(32*a^2*(1 - a^2*x^2)) - (x*ArcTanh[a*x])/(8*a*(1 - a^2*x^2)^2) - (3*x*ArcTanh[a*x])/(16*a*(1 - a^2*x^2)) - (3*ArcTanh[a*x]^2)/(32*a^2) + ArcTanh[a*x]^2/(4*a^2*(1 - a^2*x^2)^2)}
{ArcTanh[a*x]^2/(1 - a^2*x^2)^3, x, 8, x/(32*(1 - a^2*x^2)^2) + (15*x)/(64*(1 - a^2*x^2)) + (15*ArcTanh[a*x])/(64*a) - ArcTanh[a*x]/(8*a*(1 - a^2*x^2)^2) - (3*ArcTanh[a*x])/(8*a*(1 - a^2*x^2)) + (x*ArcTanh[a*x]^2)/(4*(1 - a^2*x^2)^2) + (3*x*ArcTanh[a*x]^2)/(8*(1 - a^2*x^2)) + ArcTanh[a*x]^3/(8*a)}
{ArcTanh[a*x]^2/(x*(1 - a^2*x^2)^3), x, 13, 1/(32*(1 - a^2*x^2)^2) + 11/(32*(1 - a^2*x^2)) - (a*x*ArcTanh[a*x])/(8*(1 - a^2*x^2)^2) - (11*a*x*ArcTanh[a*x])/(16*(1 - a^2*x^2)) - (11/32)*ArcTanh[a*x]^2 + ArcTanh[a*x]^2/(4*(1 - a^2*x^2)^2) + ArcTanh[a*x]^2/(2*(1 - a^2*x^2)) + (1/3)*ArcTanh[a*x]^3 + ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)] - ArcTanh[a*x]*PolyLog[2, -1 + 2/(1 + a*x)] - (1/2)*PolyLog[3, -1 + 2/(1 + a*x)]}
{ArcTanh[a*x]^2/(x^2*(1 - a^2*x^2)^3), x, 20, (a^2*x)/(32*(1 - a^2*x^2)^2) + (31*a^2*x)/(64*(1 - a^2*x^2)) + (31/64)*a*ArcTanh[a*x] - (a*ArcTanh[a*x])/(8*(1 - a^2*x^2)^2) - (7*a*ArcTanh[a*x])/(8*(1 - a^2*x^2)) + a*ArcTanh[a*x]^2 - ArcTanh[a*x]^2/x + (a^2*x*ArcTanh[a*x]^2)/(4*(1 - a^2*x^2)^2) + (7*a^2*x*ArcTanh[a*x]^2)/(8*(1 - a^2*x^2)) + (5/8)*a*ArcTanh[a*x]^3 + 2*a*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)] - a*PolyLog[2, -1 + 2/(1 + a*x)]}


(* Integrands of the form x^m*ArcTanh[a*x]^3/(1-a^2*x^2)^3 where m is an integer *)
{x^3*ArcTanh[a*x]^3/(1 - a^2*x^2)^3, x, 15, -((3*x)/(128*a^3*(1 - a^2*x^2)^2)) + (51*x)/(256*a^3*(1 - a^2*x^2)) + (51*ArcTanh[a*x])/(256*a^4) + (3*ArcTanh[a*x])/(32*a^4*(1 - a^2*x^2)^2) - (15*ArcTanh[a*x])/(32*a^4*(1 - a^2*x^2)) - (3*x*ArcTanh[a*x]^2)/(16*a^3*(1 - a^2*x^2)^2) + (15*x*ArcTanh[a*x]^2)/(32*a^3*(1 - a^2*x^2)) + (5*ArcTanh[a*x]^3)/(32*a^4) + ArcTanh[a*x]^3/(4*a^4*(1 - a^2*x^2)^2) - ArcTanh[a*x]^3/(2*a^4*(1 - a^2*x^2))}
{x^2*ArcTanh[a*x]^3/(1 - a^2*x^2)^3, x, 13, -(3/(128*a^3*(1 - a^2*x^2)^2)) + 3/(128*a^3*(1 - a^2*x^2)) + (3*x*ArcTanh[a*x])/(32*a^2*(1 - a^2*x^2)^2) - (3*x*ArcTanh[a*x])/(64*a^2*(1 - a^2*x^2)) - (3*ArcTanh[a*x]^2)/(128*a^3) - (3*ArcTanh[a*x]^2)/(16*a^3*(1 - a^2*x^2)^2) + (3*ArcTanh[a*x]^2)/(16*a^3*(1 - a^2*x^2)) + (x*ArcTanh[a*x]^3)/(4*a^2*(1 - a^2*x^2)^2) - (x*ArcTanh[a*x]^3)/(8*a^2*(1 - a^2*x^2)) - ArcTanh[a*x]^4/(32*a^3)}
{x*ArcTanh[a*x]^3/(1 - a^2*x^2)^3, x, 9, -((3*x)/(128*a*(1 - a^2*x^2)^2)) - (45*x)/(256*a*(1 - a^2*x^2)) - (45*ArcTanh[a*x])/(256*a^2) + (3*ArcTanh[a*x])/(32*a^2*(1 - a^2*x^2)^2) + (9*ArcTanh[a*x])/(32*a^2*(1 - a^2*x^2)) - (3*x*ArcTanh[a*x]^2)/(16*a*(1 - a^2*x^2)^2) - (9*x*ArcTanh[a*x]^2)/(32*a*(1 - a^2*x^2)) - (3*ArcTanh[a*x]^3)/(32*a^2) + ArcTanh[a*x]^3/(4*a^2*(1 - a^2*x^2)^2)}
{ArcTanh[a*x]^3/(1 - a^2*x^2)^3, x, 8, -(3/(128*a*(1 - a^2*x^2)^2)) - 45/(128*a*(1 - a^2*x^2)) + (3*x*ArcTanh[a*x])/(32*(1 - a^2*x^2)^2) + (45*x*ArcTanh[a*x])/(64*(1 - a^2*x^2)) + (45*ArcTanh[a*x]^2)/(128*a) - (3*ArcTanh[a*x]^2)/(16*a*(1 - a^2*x^2)^2) - (9*ArcTanh[a*x]^2)/(16*a*(1 - a^2*x^2)) + (x*ArcTanh[a*x]^3)/(4*(1 - a^2*x^2)^2) + (3*x*ArcTanh[a*x]^3)/(8*(1 - a^2*x^2)) + (3*ArcTanh[a*x]^4)/(32*a)}
{ArcTanh[a*x]^3/(x*(1 - a^2*x^2)^3), x, 21, -((3*a*x)/(128*(1 - a^2*x^2)^2)) - (141*a*x)/(256*(1 - a^2*x^2)) - (141/256)*ArcTanh[a*x] + (3*ArcTanh[a*x])/(32*(1 - a^2*x^2)^2) + (33*ArcTanh[a*x])/(32*(1 - a^2*x^2)) - (3*a*x*ArcTanh[a*x]^2)/(16*(1 - a^2*x^2)^2) - (33*a*x*ArcTanh[a*x]^2)/(32*(1 - a^2*x^2)) - (11/32)*ArcTanh[a*x]^3 + ArcTanh[a*x]^3/(4*(1 - a^2*x^2)^2) + ArcTanh[a*x]^3/(2*(1 - a^2*x^2)) + (1/4)*ArcTanh[a*x]^4 + ArcTanh[a*x]^3*Log[(2*a*x)/(1 + a*x)] - (3/2)*ArcTanh[a*x]^2*PolyLog[2, -1 + 2/(1 + a*x)] - (3/2)*ArcTanh[a*x]*PolyLog[3, -1 + 2/(1 + a*x)] - (3/4)*PolyLog[4, -1 + 2/(1 + a*x)]}
{ArcTanh[a*x]^3/(x^2*(1 - a^2*x^2)^3), x, 21, -((3*a)/(128*(1 - a^2*x^2)^2)) - (93*a)/(128*(1 - a^2*x^2)) + (3*a^2*x*ArcTanh[a*x])/(32*(1 - a^2*x^2)^2) + (93*a^2*x*ArcTanh[a*x])/(64*(1 - a^2*x^2)) + (93/128)*a*ArcTanh[a*x]^2 - (3*a*ArcTanh[a*x]^2)/(16*(1 - a^2*x^2)^2) - (21*a*ArcTanh[a*x]^2)/(16*(1 - a^2*x^2)) + a*ArcTanh[a*x]^3 - ArcTanh[a*x]^3/x + (a^2*x*ArcTanh[a*x]^3)/(4*(1 - a^2*x^2)^2) + (7*a^2*x*ArcTanh[a*x]^3)/(8*(1 - a^2*x^2)) + (15/32)*a*ArcTanh[a*x]^4 + 3*a*ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)] - 3*a*ArcTanh[a*x]*PolyLog[2, -1 + 2/(1 + a*x)] - (3/2)*a*PolyLog[3, -1 + 2/(1 + a*x)]}


(* Integrands of the form x^m/(ArcTanh[a*x]*(1-a^2*x^2)^3) where m is an integer *)
{x^3/((1 - a^2*x^2)^3*ArcTanh[a*x]), x, 4, -(SinhIntegral[2*ArcTanh[a*x]]/(4*a^4)) + SinhIntegral[4*ArcTanh[a*x]]/(8*a^4)}
{x^2/((1 - a^2*x^2)^3*ArcTanh[a*x]), x, 4, CoshIntegral[4*ArcTanh[a*x]]/(8*a^3) - Log[ArcTanh[a*x]]/(8*a^3)}
{x/((1 - a^2*x^2)^3*ArcTanh[a*x]), x, 4, SinhIntegral[2*ArcTanh[a*x]]/(4*a^2) + SinhIntegral[4*ArcTanh[a*x]]/(8*a^2)}
{1/((1 - a^2*x^2)^3*ArcTanh[a*x]), x, 6, CoshIntegral[2*ArcTanh[a*x]]/(2*a) + CoshIntegral[4*ArcTanh[a*x]]/(8*a) + (3*Log[ArcTanh[a*x]])/(8*a)}
{1/(x*(1 - a^2*x^2)^3*ArcTanh[a*x]), x, 9, (3/4)*SinhIntegral[2*ArcTanh[a*x]] + (1/8)*SinhIntegral[4*ArcTanh[a*x]] + Subst[Int[Coth[x]/x, x], x, ArcTanh[a*x]]}


(* Integrands of the form x^m/(ArcTanh[a*x]^2*(1-a^2*x^2)^3) where m is an integer *)
{x^5/((1 - a^2*x^2)^3*ArcTanh[a*x]^2), x, 17, -(x/(a^5*(1 - a^2*x^2)^2*ArcTanh[a*x])) + (2*x)/(a^5*(1 - a^2*x^2)*ArcTanh[a*x]) - (3*CoshIntegral[2*ArcTanh[a*x]])/(2*a^6) + CoshIntegral[4*ArcTanh[a*x]]/(2*a^6) + Subst[Int[Tanh[x]/x^2, x], x, ArcTanh[a*x]]/a^6}
{x^4/((1 - a^2*x^2)^3*ArcTanh[a*x]^2), x, 5, -(x^4/(a*(1 - a^2*x^2)^2*ArcTanh[a*x])) - SinhIntegral[2*ArcTanh[a*x]]/a^5 + SinhIntegral[4*ArcTanh[a*x]]/(2*a^5)}
{x^3/((1 - a^2*x^2)^3*ArcTanh[a*x]^2), x, 10, -(x^3/(a*(1 - a^2*x^2)^2*ArcTanh[a*x])) - CoshIntegral[2*ArcTanh[a*x]]/(2*a^4) + CoshIntegral[4*ArcTanh[a*x]]/(2*a^4), -(x/(a^3*(1 - a^2*x^2)^2*ArcTanh[a*x])) + x/(a^3*(1 - a^2*x^2)*ArcTanh[a*x]) - CoshIntegral[2*ArcTanh[a*x]]/(2*a^4) + CoshIntegral[4*ArcTanh[a*x]]/(2*a^4)}
{x^2/((1 - a^2*x^2)^3*ArcTanh[a*x]^2), x, 10, -(x^2/(a*(1 - a^2*x^2)^2*ArcTanh[a*x])) + SinhIntegral[4*ArcTanh[a*x]]/(2*a^3), -(1/(a^3*(1 - a^2*x^2)^2*ArcTanh[a*x])) + 1/(a^3*(1 - a^2*x^2)*ArcTanh[a*x]) + SinhIntegral[4*ArcTanh[a*x]]/(2*a^3)}
{x/((1 - a^2*x^2)^3*ArcTanh[a*x]^2), x, 5, -(x/(a*(1 - a^2*x^2)^2*ArcTanh[a*x])) + CoshIntegral[2*ArcTanh[a*x]]/(2*a^2) + CoshIntegral[4*ArcTanh[a*x]]/(2*a^2)}
{1/((1 - a^2*x^2)^3*ArcTanh[a*x]^2), x, 5, -(1/(a*(1 - a^2*x^2)^2*ArcTanh[a*x])) + SinhIntegral[2*ArcTanh[a*x]]/a + SinhIntegral[4*ArcTanh[a*x]]/(2*a)}
{1/(x*(1 - a^2*x^2)^3*ArcTanh[a*x]^2), x, 12, -((a*x)/((1 - a^2*x^2)^2*ArcTanh[a*x])) - (a*x)/((1 - a^2*x^2)*ArcTanh[a*x]) + (3/2)*CoshIntegral[2*ArcTanh[a*x]] + (1/2)*CoshIntegral[4*ArcTanh[a*x]] + Subst[Int[Coth[x]/x^2, x], x, ArcTanh[a*x]]}


(* Integrands of the form x^m/(ArcTanh[a*x]^3*(1-a^2*x^2)^3) where m is an integer *)
{x^3/((1 - a^2*x^2)^3*ArcTanh[a*x]^3), x, 21, -(x^3/(2*a*(1 - a^2*x^2)^2*ArcTanh[a*x]^2)) - (3*x^2)/(2*a^2*(1 - a^2*x^2)^2*ArcTanh[a*x]) - x^4/(2*(1 - a^2*x^2)^2*ArcTanh[a*x]) - SinhIntegral[2*ArcTanh[a*x]]/(2*a^4) + SinhIntegral[4*ArcTanh[a*x]]/a^4, -(x/(2*a^3*(1 - a^2*x^2)^2*ArcTanh[a*x]^2)) + x/(2*a^3*(1 - a^2*x^2)*ArcTanh[a*x]^2) - 2/(a^4*(1 - a^2*x^2)^2*ArcTanh[a*x]) + 2/(a^4*(1 - a^2*x^2)*ArcTanh[a*x]) + x^2/(2*a^2*(1 - a^2*x^2)*ArcTanh[a*x]) - SinhIntegral[2*ArcTanh[a*x]]/(2*a^4) + SinhIntegral[4*ArcTanh[a*x]]/a^4}
{x^2/((1 - a^2*x^2)^3*ArcTanh[a*x]^3), x, 12, -(x^2/(2*a*(-1 + a^2*x^2)^2*ArcTanh[a*x]^2)) - (2*x)/(a^2*(1 - a^2*x^2)^2*ArcTanh[a*x]) + x/(a^2*(1 - a^2*x^2)*ArcTanh[a*x]) + CoshIntegral[4*ArcTanh[a*x]]/a^3, -(1/(2*a^3*(1 - a^2*x^2)^2*ArcTanh[a*x]^2)) + 1/(2*a^3*(1 - a^2*x^2)*ArcTanh[a*x]^2) - (2*x)/(a^2*(1 - a^2*x^2)^2*ArcTanh[a*x]) + x/(a^2*(1 - a^2*x^2)*ArcTanh[a*x]) + CoshIntegral[4*ArcTanh[a*x]]/a^3}
{x/((1 - a^2*x^2)^3*ArcTanh[a*x]^3), x, 16, -(x/(2*a*(1 - a^2*x^2)^2*ArcTanh[a*x]^2)) - 2/(a^2*(1 - a^2*x^2)^2*ArcTanh[a*x]) + 3/(2*a^2*(1 - a^2*x^2)*ArcTanh[a*x]) + SinhIntegral[2*ArcTanh[a*x]]/(2*a^2) + SinhIntegral[4*ArcTanh[a*x]]/a^2}
{1/((1 - a^2*x^2)^3*ArcTanh[a*x]^3), x, 6, -(1/(2*a*(1 - a^2*x^2)^2*ArcTanh[a*x]^2)) - (2*x)/((1 - a^2*x^2)^2*ArcTanh[a*x]) + CoshIntegral[2*ArcTanh[a*x]]/a + CoshIntegral[4*ArcTanh[a*x]]/a}
{1/(x*(1 - a^2*x^2)^3*ArcTanh[a*x]^3), x, 23, -((a*x)/(2*(1 - a^2*x^2)^2*ArcTanh[a*x]^2)) - (a*x)/(2*(1 - a^2*x^2)*ArcTanh[a*x]^2) - 2/((1 - a^2*x^2)^2*ArcTanh[a*x]) + 1/((1 - a^2*x^2)*ArcTanh[a*x]) - (a^2*x^2)/(2*(1 - a^2*x^2)*ArcTanh[a*x]) + (3/2)*SinhIntegral[2*ArcTanh[a*x]] + SinhIntegral[4*ArcTanh[a*x]] + Subst[Int[Coth[x]/x^3, x], x, ArcTanh[a*x]]}


{1/((1 - a^2*x^2)^3*ArcTanh[a*x]^4), x, 17, -(1/(3*a*(1 - a^2*x^2)^2*ArcTanh[a*x]^3)) - (2*x)/(3*(1 - a^2*x^2)^2*ArcTanh[a*x]^2) - 8/(3*a*(1 - a^2*x^2)^2*ArcTanh[a*x]) + 2/(a*(1 - a^2*x^2)*ArcTanh[a*x]) + (2*SinhIntegral[2*ArcTanh[a*x]])/(3*a) + (4*SinhIntegral[4*ArcTanh[a*x]])/(3*a)}
{1/((1 - a^2*x^2)^3*ArcTanh[a*x]^5), x, 20, -(1/(4*a*(1 - a^2*x^2)^2*ArcTanh[a*x]^4)) - x/(3*(1 - a^2*x^2)^2*ArcTanh[a*x]^3) - 2/(3*a*(1 - a^2*x^2)^2*ArcTanh[a*x]^2) + 1/(2*a*(1 - a^2*x^2)*ArcTanh[a*x]^2) - (8*x)/(3*(1 - a^2*x^2)^2*ArcTanh[a*x]) + x/((1 - a^2*x^2)*ArcTanh[a*x]) + CoshIntegral[2*ArcTanh[a*x]]/(3*a) + (4*CoshIntegral[4*ArcTanh[a*x]])/(3*a)}
{1/((1 - a^2*x^2)^3*ArcTanh[a*x]^6), x, 42, -(1/(5*a*(1 - a^2*x^2)^2*ArcTanh[a*x]^5)) - x/(5*(1 - a^2*x^2)^2*ArcTanh[a*x]^4) - 4/(15*a*(1 - a^2*x^2)^2*ArcTanh[a*x]^3) + 1/(5*a*(1 - a^2*x^2)*ArcTanh[a*x]^3) - (8*x)/(15*(1 - a^2*x^2)^2*ArcTanh[a*x]^2) + x/(5*(1 - a^2*x^2)*ArcTanh[a*x]^2) - 32/(15*a*(1 - a^2*x^2)^2*ArcTanh[a*x]) + 9/(5*a*(1 - a^2*x^2)*ArcTanh[a*x]) + (a*x^2)/(5*(1 - a^2*x^2)*ArcTanh[a*x]) + (2*SinhIntegral[2*ArcTanh[a*x]])/(15*a) + (16*SinhIntegral[4*ArcTanh[a*x]])/(15*a)}


(* Integrands of the form x^m*ArcTanh[a*x]^(1/2)/(1-a^2*x^2)^3 where m is an integer *)
{Sqrt[ArcTanh[a*x]]/(1 - a^2*x^2)^3, x, 13, ArcTanh[a*x]^(3/2)/(4*a) + (Sqrt[Pi]*Erf[2*Sqrt[ArcTanh[a*x]]])/(256*a) + (Sqrt[Pi/2]*Erf[Sqrt[2]*Sqrt[ArcTanh[a*x]]])/(16*a) - (Sqrt[Pi]*Erfi[2*Sqrt[ArcTanh[a*x]]])/(256*a) - (Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[ArcTanh[a*x]]])/(16*a) + (Sqrt[ArcTanh[a*x]]*Sinh[2*ArcTanh[a*x]])/(4*a) + (Sqrt[ArcTanh[a*x]]*Sinh[4*ArcTanh[a*x]])/(32*a)}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m ArcTanh[a x]^n / (c+d x^2)^4*)


(* Integrands of the form ArcTanh[a*x]^n/(1-a^2*x^2)^4 where n is an integer *)
{ArcTanh[a*x]^3/(1 - a^2*x^2)^4, x, 13, -(1/(216*a*(1 - a^2*x^2)^3)) - 65/(2304*a*(1 - a^2*x^2)^2) - 245/(768*a*(1 - a^2*x^2)) + (x*ArcTanh[a*x])/(36*(1 - a^2*x^2)^3) + (65*x*ArcTanh[a*x])/(576*(1 - a^2*x^2)^2) + (245*x*ArcTanh[a*x])/(384*(1 - a^2*x^2)) + (245*ArcTanh[a*x]^2)/(768*a) - ArcTanh[a*x]^2/(12*a*(1 - a^2*x^2)^3) - (5*ArcTanh[a*x]^2)/(32*a*(1 - a^2*x^2)^2) - (15*ArcTanh[a*x]^2)/(32*a*(1 - a^2*x^2)) + (x*ArcTanh[a*x]^3)/(6*(1 - a^2*x^2)^3) + (5*x*ArcTanh[a*x]^3)/(24*(1 - a^2*x^2)^2) + (5*x*ArcTanh[a*x]^3)/(16*(1 - a^2*x^2)) + (5*ArcTanh[a*x]^4)/(64*a)}
{ArcTanh[a*x]^2/(1 - a^2*x^2)^4, x, 13, x/(108*(1 - a^2*x^2)^3) + (65*x)/(1728*(1 - a^2*x^2)^2) + (245*x)/(1152*(1 - a^2*x^2)) + (245*ArcTanh[a*x])/(1152*a) - ArcTanh[a*x]/(18*a*(1 - a^2*x^2)^3) - (5*ArcTanh[a*x])/(48*a*(1 - a^2*x^2)^2) - (5*ArcTanh[a*x])/(16*a*(1 - a^2*x^2)) + (x*ArcTanh[a*x]^2)/(6*(1 - a^2*x^2)^3) + (5*x*ArcTanh[a*x]^2)/(24*(1 - a^2*x^2)^2) + (5*x*ArcTanh[a*x]^2)/(16*(1 - a^2*x^2)) + (5*ArcTanh[a*x]^3)/(48*a)}
{ArcTanh[a*x]/(1 - a^2*x^2)^4, x, 4, -(1/(36*a*(1 - a^2*x^2)^3)) - 5/(96*a*(1 - a^2*x^2)^2) - 5/(32*a*(1 - a^2*x^2)) + (x*ArcTanh[a*x])/(6*(1 - a^2*x^2)^3) + (5*x*ArcTanh[a*x])/(24*(1 - a^2*x^2)^2) + (5*x*ArcTanh[a*x])/(16*(1 - a^2*x^2)) + (5*ArcTanh[a*x]^2)/(32*a)}
{1/((1 - a^2*x^2)^4*ArcTanh[a*x]^3), x, 7, -(1/(2*a*(1 - a^2*x^2)^3*ArcTanh[a*x]^2)) - (3*x)/((1 - a^2*x^2)^3*ArcTanh[a*x]) + (15*CoshIntegral[2*ArcTanh[a*x]])/(16*a) + (3*CoshIntegral[4*ArcTanh[a*x]])/(2*a) + (9*CoshIntegral[6*ArcTanh[a*x]])/(16*a)}


(* Integrands of the form ArcTanh[a*x]^n/(1-a^2*x^2)^4 where n is a half-integer *)
{Sqrt[ArcTanh[a*x]]/(1 - a^2*x^2)^4, x, 17, (5*ArcTanh[a*x]^(3/2))/(24*a) + (3*Sqrt[Pi]*Erf[2*Sqrt[ArcTanh[a*x]]])/(512*a) + (15*Sqrt[Pi/2]*Erf[Sqrt[2]*Sqrt[ArcTanh[a*x]]])/(256*a) + (Sqrt[Pi/6]*Erf[Sqrt[6]*Sqrt[ArcTanh[a*x]]])/(768*a) - (3*Sqrt[Pi]*Erfi[2*Sqrt[ArcTanh[a*x]]])/(512*a) - (15*Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[ArcTanh[a*x]]])/(256*a) - (Sqrt[Pi/6]*Erfi[Sqrt[6]*Sqrt[ArcTanh[a*x]]])/(768*a) + (15*Sqrt[ArcTanh[a*x]]*Sinh[2*ArcTanh[a*x]])/(64*a) + (3*Sqrt[ArcTanh[a*x]]*Sinh[4*ArcTanh[a*x]])/(64*a) + (Sqrt[ArcTanh[a*x]]*Sinh[6*ArcTanh[a*x]])/(192*a)}


{x/((1 - a^2*x^2)^4*ArcTanh[a*x]), x, 5, (5*SinhIntegral[2*ArcTanh[a*x]])/(32*a^2) + SinhIntegral[4*ArcTanh[a*x]]/(8*a^2) + SinhIntegral[6*ArcTanh[a*x]]/(32*a^2)}
{1/((1 - a^2*x^2)^4*ArcTanh[a*x]), x, 7, (15*CoshIntegral[2*ArcTanh[a*x]])/(32*a) + (3*CoshIntegral[4*ArcTanh[a*x]])/(16*a) + CoshIntegral[6*ArcTanh[a*x]]/(32*a) + (5*Log[ArcTanh[a*x]])/(16*a)}


{x/((1 - a^2*x^2)^4*ArcTanh[a*x]^2), x, 6, -(x/(a*(1 - a^2*x^2)^3*ArcTanh[a*x])) + (5*CoshIntegral[2*ArcTanh[a*x]])/(16*a^2) + CoshIntegral[4*ArcTanh[a*x]]/(2*a^2) + (3*CoshIntegral[6*ArcTanh[a*x]])/(16*a^2)}
{1/((1 - a^2*x^2)^4*ArcTanh[a*x]^2), x, 6, -(1/(a*(1 - a^2*x^2)^3*ArcTanh[a*x])) + (15*SinhIntegral[2*ArcTanh[a*x]])/(16*a) + (3*SinhIntegral[4*ArcTanh[a*x]])/(4*a) + (3*SinhIntegral[6*ArcTanh[a*x]])/(16*a)}


{x/((1 - a^2*x^2)^5*ArcTanh[a*x]), x, 6, (7*SinhIntegral[2*ArcTanh[a*x]])/(64*a^2) + (7*SinhIntegral[4*ArcTanh[a*x]])/(64*a^2) + (3*SinhIntegral[6*ArcTanh[a*x]])/(64*a^2) + SinhIntegral[8*ArcTanh[a*x]]/(128*a^2)}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m ArcTanh[a x]^n / (c+d x^2)^(1/2)*)


(* Integrands of the form x^m*ArcTanh[a*x]/(1-a^2*x^2)^(1/2) where m is an integer *)
{x^3*ArcTanh[a*x]/(1 - a^2*x^2)^(1/2), x, 7, -((x*Sqrt[1 - a^2*x^2])/(6*a^3)) + (5*ArcSin[a*x])/(6*a^4) - (Sqrt[1 - a^2*x^2]*(2 + a^2*x^2)*ArcTanh[a*x])/(3*a^4)}
(* {x^2*ArcTanh[a*x]/(1 - a^2*x^2)^(1/2), x, 0, (Sqrt[1 - a^2*x^2]*(-1 - a*x*ArcTanh[a*x] - (I*(ArcTanh[a*x]*(Log[1 - I/E^ArcTanh[a*x]] - Log[1 + I/E^ArcTanh[a*x]]) + PolyLog[2, -I/E^ArcTanh[a*x]] - PolyLog[2, I/E^ArcTanh[a*x]]))/Sqrt[1 - a^2*x^2]))/(2*a^3)} *)
{x*ArcTanh[a*x]/(1 - a^2*x^2)^(1/2), x, 2, ArcSin[a*x]/a^2 - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/a^2}
{ArcTanh[a*x]/(1 - a^2*x^2)^(1/2), x, 1, -((2*ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x])/a) - (I*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])])/a + (I*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]])/a}
{ArcTanh[a*x]/(x*(1 - a^2*x^2)^(1/2)), x, 8, -2*ArcTanh[E^ArcTanh[a*x]]*ArcTanh[a*x] - PolyLog[2, -E^ArcTanh[a*x]] + PolyLog[2, E^ArcTanh[a*x]]}
{ArcTanh[a*x]/(x^2*(1 - a^2*x^2)^(1/2)), x, 2, -((Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/x) - a*ArcTanh[Sqrt[1 - a^2*x^2]]}
{ArcTanh[a*x]/(x^3*(1 - a^2*x^2)^(1/2)), x, 10, -((a*Sqrt[1 - a^2*x^2])/(2*x)) - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(2*x^2) - a^2*ArcTanh[E^ArcTanh[a*x]]*ArcTanh[a*x] - (1/2)*a^2*PolyLog[2, -E^ArcTanh[a*x]] + (1/2)*a^2*PolyLog[2, E^ArcTanh[a*x]]}


(* Integrands of the form x^m*ArcTanh[a*x]^2/(1-a^2*x^2)^(1/2) where m is an integer *)
(* {x^3*ArcTanh[a*x]^2/(1 - a^2*x^2)^(1/2), x, 0, (Sqrt[1 - a^2*x^2]*(-1 - a*x*ArcTanh[a*x] - 3*ArcTanh[a*x]^2 + (1 - a^2*x^2)*ArcTanh[a*x]^2 - (5*I*(ArcTanh[a*x]*(Log[1 - I/E^ArcTanh[a*x]] - Log[1 + I/E^ArcTanh[a*x]]) + PolyLog[2, -I/E^ArcTanh[a*x]] - PolyLog[2, I/E^ArcTanh[a*x]]))/Sqrt[1 - a^2*x^2]))/(3*a^4)}
{x^2*ArcTanh[a*x]^2/(1 - a^2*x^2)^(1/2), x, 0, (2*ArcTan[(1 + a*x)/Sqrt[1 - a^2*x^2]])/a^3 - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/a^3 - (x*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)/(2*a^2) + (ArcTan[(1 + a*x)/Sqrt[1 - a^2*x^2]]*ArcTanh[a*x]^2)/a^3 - (I*ArcTanh[a*x]*PolyLog[2, -((I*(1 + a*x))/Sqrt[1 - a^2*x^2])])/a^3 + (I*ArcTanh[a*x]*PolyLog[2, (I*(1 + a*x))/Sqrt[1 - a^2*x^2]])/a^3 + (I*PolyLog[3, -((I*(1 + a*x))/Sqrt[1 - a^2*x^2])])/a^3 - (I*PolyLog[3, (I*(1 + a*x))/Sqrt[1 - a^2*x^2]])/a^3} *)
{x*ArcTanh[a*x]^2/(1 - a^2*x^2)^(1/2), x, 2, -((4*ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x])/a^2) - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)/a^2 - (2*I*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])])/a^2 + (2*I*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]])/a^2}
{ArcTanh[a*x]^2/(1 - a^2*x^2)^(1/2), x, 9, (2*ArcTan[E^ArcTanh[a*x]]*ArcTanh[a*x]^2)/a - (2*I*ArcTanh[a*x]*PolyLog[2, (-I)*E^ArcTanh[a*x]])/a + (2*I*ArcTanh[a*x]*PolyLog[2, I*E^ArcTanh[a*x]])/a + (2*I*PolyLog[3, (-I)*E^ArcTanh[a*x]])/a - (2*I*PolyLog[3, I*E^ArcTanh[a*x]])/a}
{ArcTanh[a*x]^2/(x*(1 - a^2*x^2)^(1/2)), x, 10, -2*ArcTanh[E^ArcTanh[a*x]]*ArcTanh[a*x]^2 - 2*ArcTanh[a*x]*PolyLog[2, -E^ArcTanh[a*x]] + 2*ArcTanh[a*x]*PolyLog[2, E^ArcTanh[a*x]] + 2*PolyLog[3, -E^ArcTanh[a*x]] - 2*PolyLog[3, E^ArcTanh[a*x]]}
{ArcTanh[a*x]^2/(x^2*(1 - a^2*x^2)^(1/2)), x, 9, -4*a*ArcTanh[E^ArcTanh[a*x]]*ArcTanh[a*x] - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)/x - 2*a*PolyLog[2, -E^ArcTanh[a*x]] + 2*a*PolyLog[2, E^ArcTanh[a*x]]}
{ArcTanh[a*x]^2/(x^3*(1 - a^2*x^2)^(1/2)), x, 13, -((a*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/x) - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)/(2*x^2) - a^2*ArcTanh[E^ArcTanh[a*x]]*ArcTanh[a*x]^2 - a^2*ArcTanh[Sqrt[1 - a^2*x^2]] - a^2*ArcTanh[a*x]*PolyLog[2, -E^ArcTanh[a*x]] + a^2*ArcTanh[a*x]*PolyLog[2, E^ArcTanh[a*x]] + a^2*PolyLog[3, -E^ArcTanh[a*x]] - a^2*PolyLog[3, E^ArcTanh[a*x]]}


(* Integrands of the form x^m*ArcTanh[a*x]^3/(1-a^2*x^2)^(1/2) where m is an integer *)
(* {x^3*ArcTanh[a*x]^3/(1 - a^2*x^2)^(1/2), x, 0, (2*ArcTan[(1 + a*x)/Sqrt[1 - a^2*x^2]])/a^4 - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/a^4 - (x*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)/(2*a^3) + (5*ArcTan[(1 + a*x)/Sqrt[1 - a^2*x^2]]*ArcTanh[a*x]^2)/a^4 - (2*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^3)/(3*a^4) - (x^2*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^3)/(3*a^2) - (5*I*ArcTanh[a*x]*PolyLog[2, -((I*(1 + a*x))/Sqrt[1 - a^2*x^2])])/a^4 + (5*I*ArcTanh[a*x]*PolyLog[2, (I*(1 + a*x))/Sqrt[1 - a^2*x^2]])/a^4 + (5*I*PolyLog[3, -((I*(1 + a*x))/Sqrt[1 - a^2*x^2])])/a^4 - (5*I*PolyLog[3, (I*(1 + a*x))/Sqrt[1 - a^2*x^2]])/a^4}
{x^2*ArcTanh[a*x]^3/(1 - a^2*x^2)^(1/2), x, 0, 0} *)
{x*ArcTanh[a*x]^3/(1 - a^2*x^2)^(1/2), x, 10, (6*ArcTan[E^ArcTanh[a*x]]*ArcTanh[a*x]^2)/a^2 - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^3)/a^2 - (6*I*ArcTanh[a*x]*PolyLog[2, (-I)*E^ArcTanh[a*x]])/a^2 + (6*I*ArcTanh[a*x]*PolyLog[2, I*E^ArcTanh[a*x]])/a^2 + (6*I*PolyLog[3, (-I)*E^ArcTanh[a*x]])/a^2 - (6*I*PolyLog[3, I*E^ArcTanh[a*x]])/a^2}
{ArcTanh[a*x]^3/(1 - a^2*x^2)^(1/2), x, 11, (2*ArcTan[E^ArcTanh[a*x]]*ArcTanh[a*x]^3)/a - (3*I*ArcTanh[a*x]^2*PolyLog[2, (-I)*E^ArcTanh[a*x]])/a + (3*I*ArcTanh[a*x]^2*PolyLog[2, I*E^ArcTanh[a*x]])/a + (6*I*ArcTanh[a*x]*PolyLog[3, (-I)*E^ArcTanh[a*x]])/a - (6*I*ArcTanh[a*x]*PolyLog[3, I*E^ArcTanh[a*x]])/a - (6*I*PolyLog[4, (-I)*E^ArcTanh[a*x]])/a + (6*I*PolyLog[4, I*E^ArcTanh[a*x]])/a}
{ArcTanh[a*x]^3/(x*(1 - a^2*x^2)^(1/2)), x, 12, -2*ArcTanh[E^ArcTanh[a*x]]*ArcTanh[a*x]^3 - 3*ArcTanh[a*x]^2*PolyLog[2, -E^ArcTanh[a*x]] + 3*ArcTanh[a*x]^2*PolyLog[2, E^ArcTanh[a*x]] + 6*ArcTanh[a*x]*PolyLog[3, -E^ArcTanh[a*x]] - 6*ArcTanh[a*x]*PolyLog[3, E^ArcTanh[a*x]] - 6*PolyLog[4, -E^ArcTanh[a*x]] + 6*PolyLog[4, E^ArcTanh[a*x]]}
{ArcTanh[a*x]^3/(x^2*(1 - a^2*x^2)^(1/2)), x, 11, -6*a*ArcTanh[E^ArcTanh[a*x]]*ArcTanh[a*x]^2 - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^3)/x - 6*a*ArcTanh[a*x]*PolyLog[2, -E^ArcTanh[a*x]] + 6*a*ArcTanh[a*x]*PolyLog[2, E^ArcTanh[a*x]] + 6*a*PolyLog[3, -E^ArcTanh[a*x]] - 6*a*PolyLog[3, E^ArcTanh[a*x]]}
{ArcTanh[a*x]^3/(x^3*(1 - a^2*x^2)^(1/2)), x, 22, -6*a^2*ArcTanh[E^ArcTanh[a*x]]*ArcTanh[a*x] - (3*a*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)/(2*x) - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^3)/(2*x^2) - a^2*ArcTanh[E^ArcTanh[a*x]]*ArcTanh[a*x]^3 - (3/2)*a^2*(2 + ArcTanh[a*x]^2)*PolyLog[2, -E^ArcTanh[a*x]] + (3/2)*a^2*(2 + ArcTanh[a*x]^2)*PolyLog[2, E^ArcTanh[a*x]] + 3*a^2*ArcTanh[a*x]*PolyLog[3, -E^ArcTanh[a*x]] - 3*a^2*ArcTanh[a*x]*PolyLog[3, E^ArcTanh[a*x]] - 3*a^2*PolyLog[4, -E^ArcTanh[a*x]] + 3*a^2*PolyLog[4, E^ArcTanh[a*x]]}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m ArcTanh[a x]^n / (c+d x^2)^(3/2)*)


(* Integrands of the form x^m*ArcTanh[a*x]/(1-a^2*x^2)^(3/2) where m is an integer *)
{x^3*ArcTanh[a*x]/(1 - a^2*x^2)^(3/2), x, 5, -(x/(a^3*Sqrt[1 - a^2*x^2])) - ArcSin[a*x]/a^4 + ArcTanh[a*x]/(a^4*Sqrt[1 - a^2*x^2]) + (Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/a^4}
{x^2*ArcTanh[a*x]/(1 - a^2*x^2)^(3/2), x, 3, -(1/(a^3*Sqrt[1 - a^2*x^2])) + (x*ArcTanh[a*x])/(a^2*Sqrt[1 - a^2*x^2]) + (2*ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x])/a^3 + (I*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])])/a^3 - (I*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]])/a^3} 
{x*ArcTanh[a*x]/(1 - a^2*x^2)^(3/2), x, 2, -(x/(a*Sqrt[1 - a^2*x^2])) + ArcTanh[a*x]/(a^2*Sqrt[1 - a^2*x^2])}
{ArcTanh[a*x]/(1 - a^2*x^2)^(3/2), x, 1, -(1/(a*Sqrt[1 - a^2*x^2])) + (x*ArcTanh[a*x])/Sqrt[1 - a^2*x^2]}
{ArcTanh[a*x]/(x*(1 - a^2*x^2)^(3/2)), x, 11, -((a*x)/Sqrt[1 - a^2*x^2]) + ArcTanh[a*x]/Sqrt[1 - a^2*x^2] - 2*ArcTanh[E^ArcTanh[a*x]]*ArcTanh[a*x] - PolyLog[2, -E^ArcTanh[a*x]] + PolyLog[2, E^ArcTanh[a*x]]}
{ArcTanh[a*x]/(x^2*(1 - a^2*x^2)^(3/2)), x, 4, -(a/Sqrt[1 - a^2*x^2]) + (a^2*x*ArcTanh[a*x])/Sqrt[1 - a^2*x^2] - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/x - a*ArcTanh[Sqrt[1 - a^2*x^2]]}
(* {ArcTanh[a*x]/(x^3*(1 - a^2*x^2)^(3/2)), x, 22, -((a^3*x)/Sqrt[1 - a^2*x^2]) - (a*Sqrt[1 - a^2*x^2])/(2*x) + (a^2*ArcTanh[a*x])/Sqrt[1 - a^2*x^2] - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(2*x^2) - 3*a^2*ArcTanh[E^ArcTanh[a*x]]*ArcTanh[a*x] - (3/2)*a^2*PolyLog[2, -E^ArcTanh[a*x]] + (3/2)*a^2*PolyLog[2, E^ArcTanh[a*x]]} *)


(* Integrands of the form x^m*ArcTanh[a*x]^2/(1-a^2*x^2)^(3/2) where m is an integer *)
{x^3*ArcTanh[a*x]^2/(1 - a^2*x^2)^(3/2), x, 5, 2/(a^4*Sqrt[1 - a^2*x^2]) - (2*x*ArcTanh[a*x])/(a^3*Sqrt[1 - a^2*x^2]) + (4*ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x])/a^4 + ArcTanh[a*x]^2/(a^4*Sqrt[1 - a^2*x^2]) + (Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)/a^4 + (2*I*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])])/a^4 - (2*I*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]])/a^4}
{x^2*ArcTanh[a*x]^2/(1 - a^2*x^2)^(3/2), x, 12, (2*x)/(a^2*Sqrt[1 - a^2*x^2]) - (2*ArcTanh[a*x])/(a^3*Sqrt[1 - a^2*x^2]) + (x*ArcTanh[a*x]^2)/(a^2*Sqrt[1 - a^2*x^2]) - (2*ArcTan[E^ArcTanh[a*x]]*ArcTanh[a*x]^2)/a^3 + (2*I*ArcTanh[a*x]*PolyLog[2, (-I)*E^ArcTanh[a*x]])/a^3 - (2*I*ArcTanh[a*x]*PolyLog[2, I*E^ArcTanh[a*x]])/a^3 - (2*I*PolyLog[3, (-I)*E^ArcTanh[a*x]])/a^3 + (2*I*PolyLog[3, I*E^ArcTanh[a*x]])/a^3}
{x*ArcTanh[a*x]^2/(1 - a^2*x^2)^(3/2), x, 2, 2/(a^2*Sqrt[1 - a^2*x^2]) - (2*x*ArcTanh[a*x])/(a*Sqrt[1 - a^2*x^2]) + ArcTanh[a*x]^2/(a^2*Sqrt[1 - a^2*x^2])}
{ArcTanh[a*x]^2/(1 - a^2*x^2)^(3/2), x, 2, (2*x)/Sqrt[1 - a^2*x^2] - (2*ArcTanh[a*x])/(a*Sqrt[1 - a^2*x^2]) + (x*ArcTanh[a*x]^2)/Sqrt[1 - a^2*x^2]}
{ArcTanh[a*x]^2/(x*(1 - a^2*x^2)^(3/2)), x, 13, 2/Sqrt[1 - a^2*x^2] - (2*a*x*ArcTanh[a*x])/Sqrt[1 - a^2*x^2] + ArcTanh[a*x]^2/Sqrt[1 - a^2*x^2] - 2*ArcTanh[E^ArcTanh[a*x]]*ArcTanh[a*x]^2 - 2*ArcTanh[a*x]*PolyLog[2, -E^ArcTanh[a*x]] + 2*ArcTanh[a*x]*PolyLog[2, E^ArcTanh[a*x]] + 2*PolyLog[3, -E^ArcTanh[a*x]] - 2*PolyLog[3, E^ArcTanh[a*x]]}
{ArcTanh[a*x]^2/(x^2*(1 - a^2*x^2)^(3/2)), x, 12, (2*a^2*x)/Sqrt[1 - a^2*x^2] - (2*a*ArcTanh[a*x])/Sqrt[1 - a^2*x^2] - 4*a*ArcTanh[E^ArcTanh[a*x]]*ArcTanh[a*x] + (a^2*x*ArcTanh[a*x]^2)/Sqrt[1 - a^2*x^2] - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)/x - 2*a*PolyLog[2, -E^ArcTanh[a*x]] + 2*a*PolyLog[2, E^ArcTanh[a*x]]}
(* {ArcTanh[a*x]^2/(x^3*(1 - a^2*x^2)^(3/2)), x, 27, (2*a^2)/Sqrt[1 - a^2*x^2] - (2*a^3*x*ArcTanh[a*x])/Sqrt[1 - a^2*x^2] - (a*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/x + (a^2*ArcTanh[a*x]^2)/Sqrt[1 - a^2*x^2] - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)/(2*x^2) - 3*a^2*ArcTanh[E^ArcTanh[a*x]]*ArcTanh[a*x]^2 - a^2*ArcTanh[Sqrt[1 - a^2*x^2]] - 3*a^2*ArcTanh[a*x]*PolyLog[2, -E^ArcTanh[a*x]] + 3*a^2*ArcTanh[a*x]*PolyLog[2, E^ArcTanh[a*x]] + 3*a^2*PolyLog[3, -E^ArcTanh[a*x]] - 3*a^2*PolyLog[3, E^ArcTanh[a*x]]} *)


(* Integrands of the form x^m*ArcTanh[a*x]^3/(1-a^2*x^2)^(3/2) where m is an integer *)
{x^3*ArcTanh[a*x]^3/(1 - a^2*x^2)^(3/2), x, 14, -((6*x)/(a^3*Sqrt[1 - a^2*x^2])) + (6*ArcTanh[a*x])/(a^4*Sqrt[1 - a^2*x^2]) - (3*x*ArcTanh[a*x]^2)/(a^3*Sqrt[1 - a^2*x^2]) - (6*ArcTan[E^ArcTanh[a*x]]*ArcTanh[a*x]^2)/a^4 + ArcTanh[a*x]^3/(a^4*Sqrt[1 - a^2*x^2]) + (Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^3)/a^4 + (6*I*ArcTanh[a*x]*PolyLog[2, (-I)*E^ArcTanh[a*x]])/a^4 - (6*I*ArcTanh[a*x]*PolyLog[2, I*E^ArcTanh[a*x]])/a^4 - (6*I*PolyLog[3, (-I)*E^ArcTanh[a*x]])/a^4 + (6*I*PolyLog[3, I*E^ArcTanh[a*x]])/a^4}
{x^2*ArcTanh[a*x]^3/(1 - a^2*x^2)^(3/2), x, 14, -(6/(a^3*Sqrt[1 - a^2*x^2])) + (6*x*ArcTanh[a*x])/(a^2*Sqrt[1 - a^2*x^2]) - (3*ArcTanh[a*x]^2)/(a^3*Sqrt[1 - a^2*x^2]) + (x*ArcTanh[a*x]^3)/(a^2*Sqrt[1 - a^2*x^2]) - (2*ArcTan[E^ArcTanh[a*x]]*ArcTanh[a*x]^3)/a^3 + (3*I*ArcTanh[a*x]^2*PolyLog[2, (-I)*E^ArcTanh[a*x]])/a^3 - (3*I*ArcTanh[a*x]^2*PolyLog[2, I*E^ArcTanh[a*x]])/a^3 - (6*I*ArcTanh[a*x]*PolyLog[3, (-I)*E^ArcTanh[a*x]])/a^3 + (6*I*ArcTanh[a*x]*PolyLog[3, I*E^ArcTanh[a*x]])/a^3 + (6*I*PolyLog[4, (-I)*E^ArcTanh[a*x]])/a^3 - (6*I*PolyLog[4, I*E^ArcTanh[a*x]])/a^3}
{x*ArcTanh[a*x]^3/(1 - a^2*x^2)^(3/2), x, 3, -((6*x)/(a*Sqrt[1 - a^2*x^2])) + (6*ArcTanh[a*x])/(a^2*Sqrt[1 - a^2*x^2]) - (3*x*ArcTanh[a*x]^2)/(a*Sqrt[1 - a^2*x^2]) + ArcTanh[a*x]^3/(a^2*Sqrt[1 - a^2*x^2])}
{ArcTanh[a*x]^3/(1 - a^2*x^2)^(3/2), x, 2, -(6/(a*Sqrt[1 - a^2*x^2])) + (6*x*ArcTanh[a*x])/Sqrt[1 - a^2*x^2] - (3*ArcTanh[a*x]^2)/(a*Sqrt[1 - a^2*x^2]) + (x*ArcTanh[a*x]^3)/Sqrt[1 - a^2*x^2]}
{ArcTanh[a*x]^3/(x*(1 - a^2*x^2)^(3/2)), x, 16, -((6*a*x)/Sqrt[1 - a^2*x^2]) + (6*ArcTanh[a*x])/Sqrt[1 - a^2*x^2] - (3*a*x*ArcTanh[a*x]^2)/Sqrt[1 - a^2*x^2] + ArcTanh[a*x]^3/Sqrt[1 - a^2*x^2] - 2*ArcTanh[E^ArcTanh[a*x]]*ArcTanh[a*x]^3 - 3*ArcTanh[a*x]^2*PolyLog[2, -E^ArcTanh[a*x]] + 3*ArcTanh[a*x]^2*PolyLog[2, E^ArcTanh[a*x]] + 6*ArcTanh[a*x]*PolyLog[3, -E^ArcTanh[a*x]] - 6*ArcTanh[a*x]*PolyLog[3, E^ArcTanh[a*x]] - 6*PolyLog[4, -E^ArcTanh[a*x]] + 6*PolyLog[4, E^ArcTanh[a*x]]}
{ArcTanh[a*x]^3/(x^2*(1 - a^2*x^2)^(3/2)), x, 14, -((6*a)/Sqrt[1 - a^2*x^2]) + (6*a^2*x*ArcTanh[a*x])/Sqrt[1 - a^2*x^2] - (3*a*ArcTanh[a*x]^2)/Sqrt[1 - a^2*x^2] - 6*a*ArcTanh[E^ArcTanh[a*x]]*ArcTanh[a*x]^2 + (a^2*x*ArcTanh[a*x]^3)/Sqrt[1 - a^2*x^2] - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^3)/x - 6*a*ArcTanh[a*x]*PolyLog[2, -E^ArcTanh[a*x]] + 6*a*ArcTanh[a*x]*PolyLog[2, E^ArcTanh[a*x]] + 6*a*PolyLog[3, -E^ArcTanh[a*x]] - 6*a*PolyLog[3, E^ArcTanh[a*x]]}
(* {ArcTanh[a*x]^3/(x^3*(1 - a^2*x^2)^(3/2)), x, 39, -((6*a^3*x)/Sqrt[1 - a^2*x^2]) + (6*a^2*ArcTanh[a*x])/Sqrt[1 - a^2*x^2] - 6*a^2*ArcTanh[E^ArcTanh[a*x]]*ArcTanh[a*x] - (3*a^3*x*ArcTanh[a*x]^2)/Sqrt[1 - a^2*x^2] - (3*a*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)/(2*x) + (a^2*ArcTanh[a*x]^3)/Sqrt[1 - a^2*x^2] - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^3)/(2*x^2) - 3*a^2*ArcTanh[E^ArcTanh[a*x]]*ArcTanh[a*x]^3 - (3/2)*a^2*(2 + 3*ArcTanh[a*x]^2)*PolyLog[2, -E^ArcTanh[a*x]] + (3/2)*a^2*(2 + 3*ArcTanh[a*x]^2)*PolyLog[2, E^ArcTanh[a*x]] + 9*a^2*ArcTanh[a*x]*PolyLog[3, -E^ArcTanh[a*x]] - 9*a^2*ArcTanh[a*x]*PolyLog[3, E^ArcTanh[a*x]] - 9*a^2*PolyLog[4, -E^ArcTanh[a*x]] + 9*a^2*PolyLog[4, E^ArcTanh[a*x]]} *)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form ArcTanh[a x]^n (1-a^2 x^2)^p*)


(* Integrands of the form ArcTanh[a*x]*(1-a^2*x^2)^m where m is an integer *)
{ArcTanh[a*x]*(1 - a^2*x^2)^3, x, 4, (4*(1 - a^2*x^2))/(35*a) + (3*(1 - a^2*x^2)^2)/(70*a) + (1 - a^2*x^2)^3/(42*a) + (24/35)*x*ArcTanh[a*x] - (8/35)*a^2*x^3*ArcTanh[a*x] + (6/35)*x*(1 - a^2*x^2)^2*ArcTanh[a*x] + (1/7)*x*(1 - a^2*x^2)^3*ArcTanh[a*x] + (8*Log[1 - a^2*x^2])/(35*a)}
{ArcTanh[a*x]*(1 - a^2*x^2)^2, x, 3, (2*(1 - a^2*x^2))/(15*a) + (1 - a^2*x^2)^2/(20*a) + (4/5)*x*ArcTanh[a*x] - (4/15)*a^2*x^3*ArcTanh[a*x] + (1/5)*x*(1 - a^2*x^2)^2*ArcTanh[a*x] + (4*Log[1 - a^2*x^2])/(15*a)}
{ArcTanh[a*x]*(1 - a^2*x^2), x, 2, (1 - a^2*x^2)/(6*a) + x*ArcTanh[a*x] - (1/3)*a^2*x^3*ArcTanh[a*x] + Log[1 - a^2*x^2]/(3*a)}


(* Integrands of the form ArcTanh[a*x]^2*(1-a^2*x^2)^m where m is an integer *)
{ArcTanh[a*x]^2*(1 - a^2*x^2)^3, x, 44, -((38*x)/105) + (19*a^2*x^3)/315 - (a^4*x^5)/105 + (38*ArcTanh[a*x])/(105*a) - (19/35)*a*x^2*ArcTanh[a*x] + (8/35)*a^3*x^4*ArcTanh[a*x] - (1/21)*a^5*x^6*ArcTanh[a*x] + (16*ArcTanh[a*x]^2)/(35*a) + x*ArcTanh[a*x]^2 - a^2*x^3*ArcTanh[a*x]^2 + (3/5)*a^4*x^5*ArcTanh[a*x]^2 - (1/7)*a^6*x^7*ArcTanh[a*x]^2 - (32*ArcTanh[a*x]*Log[2/(1 - a*x)])/(35*a) - (16*PolyLog[2, 1 - 2/(1 - a*x)])/(35*a)}
{ArcTanh[a*x]^2*(1 - a^2*x^2)^2, x, 25, -((11*x)/30) + (a^2*x^3)/30 + (11*ArcTanh[a*x])/(30*a) - (7/15)*a*x^2*ArcTanh[a*x] + (1/10)*a^3*x^4*ArcTanh[a*x] + (8*ArcTanh[a*x]^2)/(15*a) + x*ArcTanh[a*x]^2 - (2/3)*a^2*x^3*ArcTanh[a*x]^2 + (1/5)*a^4*x^5*ArcTanh[a*x]^2 - (16*ArcTanh[a*x]*Log[2/(1 - a*x)])/(15*a) - (8*PolyLog[2, 1 - 2/(1 - a*x)])/(15*a)}
{ArcTanh[a*x]^2*(1 - a^2*x^2), x, 13, -(x/3) + ArcTanh[a*x]/(3*a) - (1/3)*a*x^2*ArcTanh[a*x] + (2*ArcTanh[a*x]^2)/(3*a) + x*ArcTanh[a*x]^2 - (1/3)*a^2*x^3*ArcTanh[a*x]^2 - (4*ArcTanh[a*x]*Log[2/(1 - a*x)])/(3*a) - (2*PolyLog[2, 1 - 2/(1 - a*x)])/(3*a)}


(* Integrands of the form ArcTanh[a*x]^3*(1-a^2*x^2)^m where m is an integer *)
{ArcTanh[a*x]^3*(1 - a^2*x^2)^3, x, 58, (8*a*x^2)/105 - (a^3*x^4)/140 - (38/35)*x*ArcTanh[a*x] + (19/105)*a^2*x^3*ArcTanh[a*x] - (1/35)*a^4*x^5*ArcTanh[a*x] + (19*ArcTanh[a*x]^2)/(35*a) - (57/70)*a*x^2*ArcTanh[a*x]^2 + (12/35)*a^3*x^4*ArcTanh[a*x]^2 - (1/14)*a^5*x^6*ArcTanh[a*x]^2 + (16*ArcTanh[a*x]^3)/(35*a) + x*ArcTanh[a*x]^3 - a^2*x^3*ArcTanh[a*x]^3 + (3/5)*a^4*x^5*ArcTanh[a*x]^3 - (1/7)*a^6*x^7*ArcTanh[a*x]^3 - (48*ArcTanh[a*x]^2*Log[2/(1 - a*x)])/(35*a) - (7*Log[1 - a^2*x^2])/(15*a) - (48*ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/(35*a) + (24*PolyLog[3, 1 - 2/(1 - a*x)])/(35*a)}
{ArcTanh[a*x]^3*(1 - a^2*x^2)^2, x, 30, (a*x^2)/20 - (11/10)*x*ArcTanh[a*x] + (1/10)*a^2*x^3*ArcTanh[a*x] + (11*ArcTanh[a*x]^2)/(20*a) - (7/10)*a*x^2*ArcTanh[a*x]^2 + (3/20)*a^3*x^4*ArcTanh[a*x]^2 + (8*ArcTanh[a*x]^3)/(15*a) + x*ArcTanh[a*x]^3 - (2/3)*a^2*x^3*ArcTanh[a*x]^3 + (1/5)*a^4*x^5*ArcTanh[a*x]^3 - (8*ArcTanh[a*x]^2*Log[2/(1 - a*x)])/(5*a) - Log[1 - a^2*x^2]/(2*a) - (8*ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/(5*a) + (4*PolyLog[3, 1 - 2/(1 - a*x)])/(5*a)}
{ArcTanh[a*x]^3*(1 - a^2*x^2), x, 15, (-x)*ArcTanh[a*x] + ArcTanh[a*x]^2/(2*a) - (1/2)*a*x^2*ArcTanh[a*x]^2 + (2*ArcTanh[a*x]^3)/(3*a) + x*ArcTanh[a*x]^3 - (1/3)*a^2*x^3*ArcTanh[a*x]^3 - (2*ArcTanh[a*x]^2*Log[2/(1 - a*x)])/a - Log[1 - a^2*x^2]/(2*a) - (2*ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/a + PolyLog[3, 1 - 2/(1 - a*x)]/a}


(* Integrands of the form ArcTanh[a*x]^(1/2)*(1-a^2*x^2)^m where m is an integer *)
(* {Sqrt[ArcTanh[a*x]]*(1 - a^2*x^2)^3, x, 3, -3*a^2*Int[x^2*Sqrt[ArcTanh[a*x]], x] + 3*a^4*Int[x^4*Sqrt[ArcTanh[a*x]], x] - a^6*Int[x^6*Sqrt[ArcTanh[a*x]], x] + Subst[Int[Sqrt[ArcTanh[x]], x], x, a*x]/a}
{Sqrt[ArcTanh[a*x]]*(1 - a^2*x^2)^2, x, 3, -2*a^2*Int[x^2*Sqrt[ArcTanh[a*x]], x] + a^4*Int[x^4*Sqrt[ArcTanh[a*x]], x] + Subst[Int[Sqrt[ArcTanh[x]], x], x, a*x]/a}
{Sqrt[ArcTanh[a*x]]*(1 - a^2*x^2), x, 3, (-a^2)*Int[x^2*Sqrt[ArcTanh[a*x]], x] + Subst[Int[Sqrt[ArcTanh[x]], x], x, a*x]/a} *)


(* Integrands of the form (1-a^2*x^2)^m/ArcTanh[a*x] where m is an integer *)
{(1 - a^2*x^2)/ArcTanh[a*x], x, 6, Subst[Int[Sech[x]^2/x, x], x, ArcTanh[a*x]]/a - Subst[Int[(Sech[x]^2*Tanh[x]^2)/x, x], x, ArcTanh[a*x]]/a}
{(1 - a^2*x^2)/ArcTanh[a*x]^2, x, 6, Subst[Int[Sech[x]^2/x^2, x], x, ArcTanh[a*x]]/a - Subst[Int[(Sech[x]^2*Tanh[x]^2)/x^2, x], x, ArcTanh[a*x]]/a}
{(1 - a^2*x^2)/ArcTanh[a*x]^3, x, 6, Subst[Int[Sech[x]^2/x^3, x], x, ArcTanh[a*x]]/a - Subst[Int[(Sech[x]^2*Tanh[x]^2)/x^3, x], x, ArcTanh[a*x]]/a}


(* Integrands of the form ArcTanh[a*x]*(1-a^2*x^2)^m where m is a half-integer *)
{ArcTanh[a*x]*(1 - a^2*x^2)^(5/2), x, 4, (5*Sqrt[1 - a^2*x^2])/(16*a) + (5*(1 - a^2*x^2)^(3/2))/(72*a) + (1 - a^2*x^2)^(5/2)/(30*a) + (5/16)*x*Sqrt[1 - a^2*x^2]*ArcTanh[a*x] + (5/24)*x*(1 - a^2*x^2)^(3/2)*ArcTanh[a*x] + (1/6)*x*(1 - a^2*x^2)^(5/2)*ArcTanh[a*x] - (5*ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x])/(8*a) - (5*I*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])])/(16*a) + (5*I*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]])/(16*a)}
{ArcTanh[a*x]*(1 - a^2*x^2)^(3/2), x, 3, (3*Sqrt[1 - a^2*x^2])/(8*a) + (1 - a^2*x^2)^(3/2)/(12*a) + (3/8)*x*Sqrt[1 - a^2*x^2]*ArcTanh[a*x] + (1/4)*x*(1 - a^2*x^2)^(3/2)*ArcTanh[a*x] - (3*ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x])/(4*a) - (3*I*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])])/(8*a) + (3*I*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]])/(8*a)}
{ArcTanh[a*x]*(1 - a^2*x^2)^(1/2), x, 2, Sqrt[1 - a^2*x^2]/(2*a) + (1/2)*x*Sqrt[1 - a^2*x^2]*ArcTanh[a*x] - (ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x])/a - (I*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])])/(2*a) + (I*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]])/(2*a)}
{ArcTanh[a*x]/(1 - a^2*x^2)^(5/2), x, 2, -(1/(9*a*(1 - a^2*x^2)^(3/2))) - 2/(3*a*Sqrt[1 - a^2*x^2]) + (x*ArcTanh[a*x])/(3*(1 - a^2*x^2)^(3/2)) + (2*x*ArcTanh[a*x])/(3*Sqrt[1 - a^2*x^2])}
{ArcTanh[a*x]/(1 - a^2*x^2)^(7/2), x, 3, -(1/(25*a*(1 - a^2*x^2)^(5/2))) - 4/(45*a*(1 - a^2*x^2)^(3/2)) - 8/(15*a*Sqrt[1 - a^2*x^2]) + (x*ArcTanh[a*x])/(5*(1 - a^2*x^2)^(5/2)) + (4*x*ArcTanh[a*x])/(15*(1 - a^2*x^2)^(3/2)) + (8*x*ArcTanh[a*x])/(15*Sqrt[1 - a^2*x^2])}
{ArcTanh[a*x]/(1 - a^2*x^2)^(9/2), x, 4, -(1/(49*a*(1 - a^2*x^2)^(7/2))) - 6/(175*a*(1 - a^2*x^2)^(5/2)) - 8/(105*a*(1 - a^2*x^2)^(3/2)) - 16/(35*a*Sqrt[1 - a^2*x^2]) + (x*ArcTanh[a*x])/(7*(1 - a^2*x^2)^(7/2)) + (6*x*ArcTanh[a*x])/(35*(1 - a^2*x^2)^(5/2)) + (8*x*ArcTanh[a*x])/(35*(1 - a^2*x^2)^(3/2)) + (16*x*ArcTanh[a*x])/(35*Sqrt[1 - a^2*x^2])}

(* Integrands of the form ArcTanh[a*x]*(c-c*a^2*x^2)^m where m is a half-integer *)
{ArcTanh[a*x]*(c - c*a^2*x^2)^(3/2), x, 4, (3*c*Sqrt[c - a^2*c*x^2])/(8*a) + (c - a^2*c*x^2)^(3/2)/(12*a) + (3/8)*c*x*Sqrt[c - a^2*c*x^2]*ArcTanh[a*x] + (1/4)*x*(c - a^2*c*x^2)^(3/2)*ArcTanh[a*x] - (3*c^2*Sqrt[1 - a^2*x^2]*(2*ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x] + I*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])] - I*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]]))/(8*a*Sqrt[c - a^2*c*x^2])}
{ArcTanh[a*x]*(c - c*a^2*x^2)^(1/2), x, 3, Sqrt[c - a^2*c*x^2]/(2*a) + (1/2)*x*Sqrt[c - a^2*c*x^2]*ArcTanh[a*x] - (c*Sqrt[1 - a^2*x^2]*(2*ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x] + I*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])] - I*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]]))/(2*a*Sqrt[c - a^2*c*x^2])}
{ArcTanh[a*x]/(c - c*a^2*x^2)^(1/2), x, 2, -((Sqrt[1 - a^2*x^2]*(2*ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x] + I*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])] - I*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]]))/(a*Sqrt[c - a^2*c*x^2]))}
{ArcTanh[a*x]/(c - c*a^2*x^2)^(3/2), x, 1, -(1/(a*c*Sqrt[c - a^2*c*x^2])) + (x*ArcTanh[a*x])/(c*Sqrt[c - a^2*c*x^2])}
{ArcTanh[a*x]/(c - c*a^2*x^2)^(5/2), x, 2, -(1/(9*a*c*(c - a^2*c*x^2)^(3/2))) - 2/(3*a*c^2*Sqrt[c - a^2*c*x^2]) + (x*ArcTanh[a*x])/(3*c*(c - a^2*c*x^2)^(3/2)) + (2*x*ArcTanh[a*x])/(3*c^2*Sqrt[c - a^2*c*x^2])}
{ArcTanh[a*x]/(c - c*a^2*x^2)^(7/2), x, 3, -(1/(25*a*c*(c - a^2*c*x^2)^(5/2))) - 4/(45*a*c^2*(c - a^2*c*x^2)^(3/2)) - 8/(15*a*c^3*Sqrt[c - a^2*c*x^2]) + (x*ArcTanh[a*x])/(5*c*(c - a^2*c*x^2)^(5/2)) + (4*x*ArcTanh[a*x])/(15*c^2*(c - a^2*c*x^2)^(3/2)) + (8*x*ArcTanh[a*x])/(15*c^3*Sqrt[c - a^2*c*x^2])}


(* Integrands of the form ArcTanh[a*x]^2*(1-a^2*x^2)^m where m is a half-integer *)
{ArcTanh[a*x]^2*(1 - a^2*x^2)^(1/2), x, 11, -(ArcTan[(a*x)/Sqrt[1 - a^2*x^2]]/a) + (Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/a + (1/2)*x*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2 + (ArcTan[E^ArcTanh[a*x]]*ArcTanh[a*x]^2)/a - (I*ArcTanh[a*x]*PolyLog[2, (-I)*E^ArcTanh[a*x]])/a + (I*ArcTanh[a*x]*PolyLog[2, I*E^ArcTanh[a*x]])/a + (I*PolyLog[3, (-I)*E^ArcTanh[a*x]])/a - (I*PolyLog[3, I*E^ArcTanh[a*x]])/a}
{ArcTanh[a*x]^2/(1 - a^2*x^2)^(5/2), x, 5, (2*x)/(27*(1 - a^2*x^2)^(3/2)) + (40*x)/(27*Sqrt[1 - a^2*x^2]) - (2*ArcTanh[a*x])/(9*a*(1 - a^2*x^2)^(3/2)) - (4*ArcTanh[a*x])/(3*a*Sqrt[1 - a^2*x^2]) + (x*ArcTanh[a*x]^2)/(3*(1 - a^2*x^2)^(3/2)) + (2*x*ArcTanh[a*x]^2)/(3*Sqrt[1 - a^2*x^2])}
{ArcTanh[a*x]^2/(1 - a^2*x^2)^(7/2), x, 9, (2*x)/(125*(1 - a^2*x^2)^(5/2)) + (272*x)/(3375*(1 - a^2*x^2)^(3/2)) + (4144*x)/(3375*Sqrt[1 - a^2*x^2]) - (2*ArcTanh[a*x])/(25*a*(1 - a^2*x^2)^(5/2)) - (8*ArcTanh[a*x])/(45*a*(1 - a^2*x^2)^(3/2)) - (16*ArcTanh[a*x])/(15*a*Sqrt[1 - a^2*x^2]) + (x*ArcTanh[a*x]^2)/(5*(1 - a^2*x^2)^(5/2)) + (4*x*ArcTanh[a*x]^2)/(15*(1 - a^2*x^2)^(3/2)) + (8*x*ArcTanh[a*x]^2)/(15*Sqrt[1 - a^2*x^2])}
{ArcTanh[a*x]^2/(1 - a^2*x^2)^(9/2), x, 14, (2*x)/(343*(1 - a^2*x^2)^(7/2)) + (888*x)/(42875*(1 - a^2*x^2)^(5/2)) + (30256*x)/(385875*(1 - a^2*x^2)^(3/2)) + (413312*x)/(385875*Sqrt[1 - a^2*x^2]) - (2*ArcTanh[a*x])/(49*a*(1 - a^2*x^2)^(7/2)) - (12*ArcTanh[a*x])/(175*a*(1 - a^2*x^2)^(5/2)) - (16*ArcTanh[a*x])/(105*a*(1 - a^2*x^2)^(3/2)) - (32*ArcTanh[a*x])/(35*a*Sqrt[1 - a^2*x^2]) + (x*ArcTanh[a*x]^2)/(7*(1 - a^2*x^2)^(7/2)) + (6*x*ArcTanh[a*x]^2)/(35*(1 - a^2*x^2)^(5/2)) + (8*x*ArcTanh[a*x]^2)/(35*(1 - a^2*x^2)^(3/2)) + (16*x*ArcTanh[a*x]^2)/(35*Sqrt[1 - a^2*x^2])}


(* Integrands of the form ArcTanh[a*x]^3*(1-a^2*x^2)^m where m is a half-integer *)
{ArcTanh[a*x]^3*(1 - a^2*x^2)^(1/2), x, 16, -((6*ArcTan[E^ArcTanh[a*x]]*ArcTanh[a*x])/a) + (3*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)/(2*a) + (1/2)*x*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^3 + (ArcTan[E^ArcTanh[a*x]]*ArcTanh[a*x]^3)/a + (3*I*(2 - ArcTanh[a*x]^2)*PolyLog[2, (-I)*E^ArcTanh[a*x]])/(2*a) - (3*I*(2 - ArcTanh[a*x]^2)*PolyLog[2, I*E^ArcTanh[a*x]])/(2*a) + (3*I*ArcTanh[a*x]*PolyLog[3, (-I)*E^ArcTanh[a*x]])/a - (3*I*ArcTanh[a*x]*PolyLog[3, I*E^ArcTanh[a*x]])/a - (3*I*PolyLog[4, (-I)*E^ArcTanh[a*x]])/a + (3*I*PolyLog[4, I*E^ArcTanh[a*x]])/a}
{ArcTanh[a*x]^3/(1 - a^2*x^2)^(5/2), x, 5, -(2/(27*a*(1 - a^2*x^2)^(3/2))) - 40/(9*a*Sqrt[1 - a^2*x^2]) + (2*x*ArcTanh[a*x])/(9*(1 - a^2*x^2)^(3/2)) + (40*x*ArcTanh[a*x])/(9*Sqrt[1 - a^2*x^2]) - ArcTanh[a*x]^2/(3*a*(1 - a^2*x^2)^(3/2)) - (2*ArcTanh[a*x]^2)/(a*Sqrt[1 - a^2*x^2]) + (x*ArcTanh[a*x]^3)/(3*(1 - a^2*x^2)^(3/2)) + (2*x*ArcTanh[a*x]^3)/(3*Sqrt[1 - a^2*x^2])}
{ArcTanh[a*x]^3/(1 - a^2*x^2)^(7/2), x, 9, -(6/(625*a*(1 - a^2*x^2)^(5/2))) - 272/(3375*a*(1 - a^2*x^2)^(3/2)) - 4144/(1125*a*Sqrt[1 - a^2*x^2]) + (6*x*ArcTanh[a*x])/(125*(1 - a^2*x^2)^(5/2)) + (272*x*ArcTanh[a*x])/(1125*(1 - a^2*x^2)^(3/2)) + (4144*x*ArcTanh[a*x])/(1125*Sqrt[1 - a^2*x^2]) - (3*ArcTanh[a*x]^2)/(25*a*(1 - a^2*x^2)^(5/2)) - (4*ArcTanh[a*x]^2)/(15*a*(1 - a^2*x^2)^(3/2)) - (8*ArcTanh[a*x]^2)/(5*a*Sqrt[1 - a^2*x^2]) + (x*ArcTanh[a*x]^3)/(5*(1 - a^2*x^2)^(5/2)) + (4*x*ArcTanh[a*x]^3)/(15*(1 - a^2*x^2)^(3/2)) + (8*x*ArcTanh[a*x]^3)/(15*Sqrt[1 - a^2*x^2])}
{ArcTanh[a*x]^3/(1 - a^2*x^2)^(9/2), x, 14, -(6/(2401*a*(1 - a^2*x^2)^(7/2))) - 2664/(214375*a*(1 - a^2*x^2)^(5/2)) - 30256/(385875*a*(1 - a^2*x^2)^(3/2)) - 413312/(128625*a*Sqrt[1 - a^2*x^2]) + (6*x*ArcTanh[a*x])/(343*(1 - a^2*x^2)^(7/2)) + (2664*x*ArcTanh[a*x])/(42875*(1 - a^2*x^2)^(5/2)) + (30256*x*ArcTanh[a*x])/(128625*(1 - a^2*x^2)^(3/2)) + (413312*x*ArcTanh[a*x])/(128625*Sqrt[1 - a^2*x^2]) - (3*ArcTanh[a*x]^2)/(49*a*(1 - a^2*x^2)^(7/2)) - (18*ArcTanh[a*x]^2)/(175*a*(1 - a^2*x^2)^(5/2)) - (8*ArcTanh[a*x]^2)/(35*a*(1 - a^2*x^2)^(3/2)) - (48*ArcTanh[a*x]^2)/(35*a*Sqrt[1 - a^2*x^2]) + (x*ArcTanh[a*x]^3)/(7*(1 - a^2*x^2)^(7/2)) + (6*x*ArcTanh[a*x]^3)/(35*(1 - a^2*x^2)^(5/2)) + (8*x*ArcTanh[a*x]^3)/(35*(1 - a^2*x^2)^(3/2)) + (16*x*ArcTanh[a*x]^3)/(35*Sqrt[1 - a^2*x^2])}


(* Integrands of the form (1-a^2*x^2)^m/ArcTanh[a*x] where m is a half-integer *)
{(1 - a^2*x^2)^(1/2)/ArcTanh[a*x], x, 3, Subst[Int[Sech[x]^3/x, x], x, ArcTanh[a*x]]/a}
{1/(1 - a^2*x^2)^(1/2)/ArcTanh[a*x], x, 3, Subst[Int[Sech[x]/x, x], x, ArcTanh[a*x]]/a}
{1/(1 - a^2*x^2)^(3/2)/ArcTanh[a*x], x, 2, CoshIntegral[ArcTanh[a*x]]/a}
{1/(1 - a^2*x^2)^(5/2)/ArcTanh[a*x], x, 5, (3*CoshIntegral[ArcTanh[a*x]])/(4*a) + CoshIntegral[3*ArcTanh[a*x]]/(4*a)}
{1/(1 - a^2*x^2)^(7/2)/ArcTanh[a*x], x, 6, (5*CoshIntegral[ArcTanh[a*x]])/(8*a) + (5*CoshIntegral[3*ArcTanh[a*x]])/(16*a) + CoshIntegral[5*ArcTanh[a*x]]/(16*a)}
{1/(1 - a^2*x^2)^(9/2)/ArcTanh[a*x], x, 7, (35*CoshIntegral[ArcTanh[a*x]])/(64*a) + (21*CoshIntegral[3*ArcTanh[a*x]])/(64*a) + (7*CoshIntegral[5*ArcTanh[a*x]])/(64*a) + CoshIntegral[7*ArcTanh[a*x]]/(64*a)}


(* Integrands of the form (1-a^2*x^2)^m/ArcTanh[a*x]^2 where m is a half-integer *)
{(1 - a^2*x^2)^(1/2)/ArcTanh[a*x]^2, x, 3, Subst[Int[Sech[x]^3/x^2, x], x, ArcTanh[a*x]]/a}
{1/(1 - a^2*x^2)^(1/2)/ArcTanh[a*x]^2, x, 3, Subst[Int[Sech[x]/x^2, x], x, ArcTanh[a*x]]/a}
{1/(1 - a^2*x^2)^(3/2)/ArcTanh[a*x]^2, x, 3, -(1/(a*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])) + SinhIntegral[ArcTanh[a*x]]/a}
{1/(1 - a^2*x^2)^(5/2)/ArcTanh[a*x]^2, x, 5, -(1/(a*(1 - a^2*x^2)^(3/2)*ArcTanh[a*x])) + (3*SinhIntegral[ArcTanh[a*x]])/(4*a) + (3*SinhIntegral[3*ArcTanh[a*x]])/(4*a)}
{1/(1 - a^2*x^2)^(7/2)/ArcTanh[a*x]^2, x, 6, -(1/(a*(1 - a^2*x^2)^(5/2)*ArcTanh[a*x])) + (5*SinhIntegral[ArcTanh[a*x]])/(8*a) + (15*SinhIntegral[3*ArcTanh[a*x]])/(16*a) + (5*SinhIntegral[5*ArcTanh[a*x]])/(16*a)}
{1/(1 - a^2*x^2)^(9/2)/ArcTanh[a*x]^2, x, 7, -(1/(a*(1 - a^2*x^2)^(7/2)*ArcTanh[a*x])) + (35*SinhIntegral[ArcTanh[a*x]])/(64*a) + (63*SinhIntegral[3*ArcTanh[a*x]])/(64*a) + (35*SinhIntegral[5*ArcTanh[a*x]])/(64*a) + (7*SinhIntegral[7*ArcTanh[a*x]])/(64*a)}


(* Integrands of the form (1-a^2*x^2)^m/ArcTanh[a*x]^3 where m is a half-integer *)
{(1 - a^2*x^2)^(1/2)/ArcTanh[a*x]^3, x, 3, Subst[Int[Sech[x]^3/x^3, x], x, ArcTanh[a*x]]/a}
{1/(1 - a^2*x^2)^(1/2)/ArcTanh[a*x]^3, x, 3, Subst[Int[Sech[x]/x^3, x], x, ArcTanh[a*x]]/a}
{1/(1 - a^2*x^2)^(3/2)/ArcTanh[a*x]^3, x, 3, -(1/(2*a*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)) - x/(2*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]) + CoshIntegral[ArcTanh[a*x]]/(2*a)}
{1/(1 - a^2*x^2)^(5/2)/ArcTanh[a*x]^3, x, 6, -(1/(2*a*(1 - a^2*x^2)^(3/2)*ArcTanh[a*x]^2)) - (3*x)/(2*(1 - a^2*x^2)^(3/2)*ArcTanh[a*x]) + (3*CoshIntegral[ArcTanh[a*x]])/(8*a) + (9*CoshIntegral[3*ArcTanh[a*x]])/(8*a)}
{1/(1 - a^2*x^2)^(7/2)/ArcTanh[a*x]^3, x, 7, -(1/(2*a*(1 - a^2*x^2)^(5/2)*ArcTanh[a*x]^2)) - (5*x)/(2*(1 - a^2*x^2)^(5/2)*ArcTanh[a*x]) + (5*CoshIntegral[ArcTanh[a*x]])/(16*a) + (45*CoshIntegral[3*ArcTanh[a*x]])/(32*a) + (25*CoshIntegral[5*ArcTanh[a*x]])/(32*a)}
{1/(1 - a^2*x^2)^(9/2)/ArcTanh[a*x]^3, x, 8, -(1/(2*a*(1 - a^2*x^2)^(7/2)*ArcTanh[a*x]^2)) - (7*x)/(2*(1 - a^2*x^2)^(7/2)*ArcTanh[a*x]) + (35*CoshIntegral[ArcTanh[a*x]])/(128*a) + (189*CoshIntegral[3*ArcTanh[a*x]])/(128*a) + (175*CoshIntegral[5*ArcTanh[a*x]])/(128*a) + (49*CoshIntegral[7*ArcTanh[a*x]])/(128*a)}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m ArcTanh[a+b x]^n*)


{x^3*ArcTanh[a + b*x], x, 6, ((1 + 3*a^2)*x)/(4*b^3) - (a*x^2)/(4*b^2) + x^3/(12*b) + (1/4)*x^4*ArcTanh[a + b*x] + ((1 - a)^4*Log[1 - a - b*x])/(8*b^4) - ((1 + a)^4*Log[1 + a + b*x])/(8*b^4)}
{x^2*ArcTanh[a + b*x], x, 6, -((2*a*x)/(3*b^2)) + x^2/(6*b) + (1/3)*x^3*ArcTanh[a + b*x] + ((1 - a)^3*Log[1 - a - b*x])/(6*b^3) + ((1 + a)^3*Log[1 + a + b*x])/(6*b^3)}
{x*ArcTanh[a + b*x], x, 5, x/(2*b) + (1/2)*x^2*ArcTanh[a + b*x] + ((1 - a)^2*Log[1 - a - b*x])/(4*b^2) - ((1 + a)^2*Log[1 + a + b*x])/(4*b^2)}
{ArcTanh[a + b*x], x, 1, ((a + b*x)*ArcTanh[a + b*x])/b + Log[1 - (a + b*x)^2]/(2*b)}
{ArcTanh[a + b*x]/x, x, 5, (-(1/2))*Log[(b*x)/(1 - a)]*Log[1 - a - b*x] + (1/2)*Log[-((b*x)/(1 + a))]*Log[1 + a + b*x] - (1/2)*PolyLog[2, 1 - (b*x)/(1 - a)] + (1/2)*PolyLog[2, 1 + (b*x)/(1 + a)]}
{ArcTanh[a + b*x]/x^2, x, 6, -(ArcTanh[a + b*x]/x) + (b*Log[x])/(1 - a^2) - (b*Log[1 - a - b*x])/(2*(1 - a)) - (b*Log[1 + a + b*x])/(2*(1 + a))}
{ArcTanh[a + b*x]/x^3, x, 6, -(b/(2*(1 - a^2)*x)) - ArcTanh[a + b*x]/(2*x^2) + (a*b^2*Log[x])/(1 - a^2)^2 - (b^2*Log[1 - a - b*x])/(4*(1 - a)^2) + (b^2*Log[1 + a + b*x])/(4*(1 + a)^2)}


{x^3*ArcTanh[a + b*x]^2, x, 22, -((a*(a + b*x))/b^4) + (a + b*x)^2/(12*b^4) + (3*a*ArcTanh[a + b*x])/(2*b^4) + (x*ArcTanh[a + b*x])/(2*b^3) + (3*a^2*(a + b*x)*ArcTanh[a + b*x])/b^4 - (a*(a + b*x)^2*ArcTanh[a + b*x])/b^4 + ((a + b*x)^3*ArcTanh[a + b*x])/(6*b^4) - ArcTanh[a + b*x]^2/(4*b^4) - (a*ArcTanh[a + b*x]^2)/b^4 - (3*a^2*ArcTanh[a + b*x]^2)/(2*b^4) - (a^3*ArcTanh[a + b*x]^2)/b^4 - (a^3*(a + b*x)*ArcTanh[a + b*x]^2)/b^4 + (3*a^2*(a + b*x)^2*ArcTanh[a + b*x]^2)/(2*b^4) - (a*(a + b*x)^3*ArcTanh[a + b*x]^2)/b^4 + ((a + b*x)^4*ArcTanh[a + b*x]^2)/(4*b^4) + (2*a*ArcTanh[a + b*x]*Log[2/(1 - a - b*x)])/b^4 + (2*a^3*ArcTanh[a + b*x]*Log[2/(1 - a - b*x)])/b^4 + Log[1 - (a + b*x)^2]/(3*b^4) + (3*a^2*Log[1 - (a + b*x)^2])/(2*b^4) + (a*(1 + a^2)*PolyLog[2, 1 - 2/(1 - a - b*x)])/b^4}
{x^2*ArcTanh[a + b*x]^2, x, 16, (a + b*x)/(3*b^3) - ArcTanh[a + b*x]/(3*b^3) - (2*a*(a + b*x)*ArcTanh[a + b*x])/b^3 + ((a + b*x)^2*ArcTanh[a + b*x])/(3*b^3) + ArcTanh[a + b*x]^2/(3*b^3) + (a*ArcTanh[a + b*x]^2)/b^3 + (a^2*ArcTanh[a + b*x]^2)/b^3 + (a^2*(a + b*x)*ArcTanh[a + b*x]^2)/b^3 - (a*(a + b*x)^2*ArcTanh[a + b*x]^2)/b^3 + ((a + b*x)^3*ArcTanh[a + b*x]^2)/(3*b^3) - (2*ArcTanh[a + b*x]*Log[2/(1 - a - b*x)])/(3*b^3) - (2*a^2*ArcTanh[a + b*x]*Log[2/(1 - a - b*x)])/b^3 - (a*Log[1 - (a + b*x)^2])/b^3 - ((1 + 3*a^2)*PolyLog[2, 1 - 2/(1 - a - b*x)])/(3*b^3)}
{x*ArcTanh[a + b*x]^2, x, 9, ((a + b*x)*ArcTanh[a + b*x])/b^2 - ArcTanh[a + b*x]^2/(2*b^2) - (a*ArcTanh[a + b*x]^2)/b^2 - (a*(a + b*x)*ArcTanh[a + b*x]^2)/b^2 + ((a + b*x)^2*ArcTanh[a + b*x]^2)/(2*b^2) + (2*a*ArcTanh[a + b*x]*Log[2/(1 - a - b*x)])/b^2 + Log[1 - (a + b*x)^2]/(2*b^2) + (a*PolyLog[2, 1 - 2/(1 - a - b*x)])/b^2}
{ArcTanh[a + b*x]^2, x, 5, ArcTanh[a + b*x]^2/b + ((a + b*x)*ArcTanh[a + b*x]^2)/b - (2*ArcTanh[a + b*x]*Log[2/(1 - a - b*x)])/b - PolyLog[2, 1 - 2/(1 - a - b*x)]/b}
{ArcTanh[a + b*x]^2/x, x, -3, (-(2/3))*ArcTanh[a + b*x]^3 - ArcTanh[a + b*x]^2*Log[2/(1 + a + b*x)] + ArcTanh[a + b*x]^2*Log[1 - (Sqrt[(1 - a)/b]*(1 + a + b*x))/(Sqrt[(1 + a)/b]*Sqrt[1 - (a + b*x)^2])] + ArcTanh[a + b*x]^2*Log[1 + (Sqrt[(1 - a)/b]*(1 + a + b*x))/(Sqrt[(1 + a)/b]*Sqrt[1 - (a + b*x)^2])] + 2*ArcTanh[a + b*x]*PolyLog[2, -((Sqrt[(1 - a)/b]*(1 + a + b*x))/(Sqrt[(1 + a)/b]*Sqrt[1 - (a + b*x)^2]))] + 2*ArcTanh[a + b*x]*PolyLog[2, (Sqrt[(1 - a)/b]*(1 + a + b*x))/(Sqrt[(1 + a)/b]*Sqrt[1 - (a + b*x)^2])] + ArcTanh[a + b*x]*PolyLog[2, 1 - 2/(1 + a + b*x)] - 2*PolyLog[3, -((Sqrt[(1 - a)/b]*(1 + a + b*x))/(Sqrt[(1 + a)/b]*Sqrt[1 - (a + b*x)^2]))] - 2*PolyLog[3, (Sqrt[(1 - a)/b]*(1 + a + b*x))/(Sqrt[(1 + a)/b]*Sqrt[1 - (a + b*x)^2])] + (1/2)*PolyLog[3, 1 - 2/(1 + a + b*x)]}
(* {ArcTanh[a + b*x]^2/x^2, x, 0, 0}
{ArcTanh[a + b*x]^2/x^3, x, 0, 0} *)


(* {x^3/ArcTanh[a + b*x], x, 0, 0}
{x^2/ArcTanh[a + b*x], x, 0, 0}
{x/ArcTanh[a + b*x], x, 0, 0}
{1/ArcTanh[a + b*x], x, 0, 0}
{1/(x*ArcTanh[a + b*x]), x, 0, 0}
{1/(x^2*ArcTanh[a + b*x]), x, 0, 0}
{1/(x^3*ArcTanh[a + b*x]), x, 0, 0} *)


(* ::Subsubsection::Closed:: *)
(*Miscellaneous integrands involving inverse hyperbolic tangents*)


(* Integrands of the form (a+b*x)^m*ArcTanh[a+b*x] where m is an integer *)
{(a + b*x)*ArcTanh[a + b*x], x, 3, (a + b*x)/(2*b) - ArcTanh[a + b*x]/(2*b) + ((a + b*x)^2*ArcTanh[a + b*x])/(2*b)}
{(a + b*x)^2*ArcTanh[a + b*x], x, 4, (a + b*x)^2/(6*b) + ((a + b*x)^3*ArcTanh[a + b*x])/(3*b) + Log[1 - (a + b*x)^2]/(6*b)}
{ArcTanh[1 + x]/(2 + 2*x), x, 5, (-(1/4))*PolyLog[2, -1 - x] + (1/4)*PolyLog[2, 1 + x]}
{ArcTanh[a + b*x]/(a + b*x), x, 4, -(PolyLog[2, -a - b*x]/(2*b)) + PolyLog[2, a + b*x]/(2*b)}
{ArcTanh[a + b*x]/(a + b*x)^2, x, 3, -(ArcTanh[a + b*x]/(b*(a + b*x))) - ArcTanh[1 - 2*(a + b*x)^2]/b}


(* Integrands of the form ArcTanh[a+b*x]/Pn where Pn is a polynomial *)
{ArcTanh[x]/(a + b*x), x, 3, (Log[1 + x]*Log[(a + b*x)/(a - b)])/(2*b) - (Log[1 - x]*Log[(a + b*x)/(a + b)])/(2*b) - PolyLog[2, (b*(1 - x))/(a + b)]/(2*b) + PolyLog[2, -((b*(1 + x))/(a - b))]/(2*b)}
{ArcTanh[x]/(a + b*x^2), x, 7, -((Log[1 - x]*Log[(Sqrt[-a] - Sqrt[b]*x)/(Sqrt[-a] - Sqrt[b])])/(4*Sqrt[-a]*Sqrt[b])) + (Log[1 + x]*Log[(Sqrt[-a] - Sqrt[b]*x)/(Sqrt[-a] + Sqrt[b])])/(4*Sqrt[-a]*Sqrt[b]) - (Log[1 + x]*Log[(Sqrt[-a] + Sqrt[b]*x)/(Sqrt[-a] - Sqrt[b])])/(4*Sqrt[-a]*Sqrt[b]) + (Log[1 - x]*Log[(Sqrt[-a] + Sqrt[b]*x)/(Sqrt[-a] + Sqrt[b])])/(4*Sqrt[-a]*Sqrt[b]) - PolyLog[2, -((Sqrt[b]*(1 - x))/(Sqrt[-a] - Sqrt[b]))]/(4*Sqrt[-a]*Sqrt[b]) + PolyLog[2, (Sqrt[b]*(1 - x))/(Sqrt[-a] + Sqrt[b])]/(4*Sqrt[-a]*Sqrt[b]) - PolyLog[2, -((Sqrt[b]*(1 + x))/(Sqrt[-a] - Sqrt[b]))]/(4*Sqrt[-a]*Sqrt[b]) + PolyLog[2, (Sqrt[b]*(1 + x))/(Sqrt[-a] + Sqrt[b])]/(4*Sqrt[-a]*Sqrt[b])}
{ArcTanh[x]/(a + b*x + c*x^2), x, 7, (Log[1 + x]*Log[(b - Sqrt[b^2 - 4*a*c] + 2*c*x)/(b - 2*c - Sqrt[b^2 - 4*a*c])])/(2*Sqrt[b^2 - 4*a*c]) - (Log[1 - x]*Log[(b - Sqrt[b^2 - 4*a*c] + 2*c*x)/(b + 2*c - Sqrt[b^2 - 4*a*c])])/(2*Sqrt[b^2 - 4*a*c]) - (Log[1 + x]*Log[(b + Sqrt[b^2 - 4*a*c] + 2*c*x)/(b - 2*c + Sqrt[b^2 - 4*a*c])])/(2*Sqrt[b^2 - 4*a*c]) + (Log[1 - x]*Log[(b + Sqrt[b^2 - 4*a*c] + 2*c*x)/(b + 2*c + Sqrt[b^2 - 4*a*c])])/(2*Sqrt[b^2 - 4*a*c]) - PolyLog[2, (2*c*(1 - x))/(b + 2*c - Sqrt[b^2 - 4*a*c])]/(2*Sqrt[b^2 - 4*a*c]) + PolyLog[2, (2*c*(1 - x))/(b + 2*c + Sqrt[b^2 - 4*a*c])]/(2*Sqrt[b^2 - 4*a*c]) + PolyLog[2, -((2*c*(1 + x))/(b - 2*c - Sqrt[b^2 - 4*a*c]))]/(2*Sqrt[b^2 - 4*a*c]) - PolyLog[2, -((2*c*(1 + x))/(b - 2*c + Sqrt[b^2 - 4*a*c]))]/(2*Sqrt[b^2 - 4*a*c])}

{ArcTanh[d + e*x]/(a + b*x), x, 3, -((Log[(e*(a + b*x))/(b*(1 - d) + a*e)]*Log[1 - d - e*x])/(2*b)) + (Log[-((e*(a + b*x))/(b*(1 + d) - a*e))]*Log[1 + d + e*x])/(2*b) - PolyLog[2, (b*(1 - d - e*x))/(b*(1 - d) + a*e)]/(2*b) + PolyLog[2, (b*(1 + d + e*x))/(b*(1 + d) - a*e)]/(2*b)}
{ArcTanh[d + e*x]/(a + b*x^2), x, 7, -((Log[-((e*(Sqrt[-a] - Sqrt[b]*x))/(Sqrt[b]*(1 - d) - Sqrt[-a]*e))]*Log[1 - d - e*x])/(4*Sqrt[-a]*Sqrt[b])) + (Log[(e*(Sqrt[-a] + Sqrt[b]*x))/(Sqrt[b]*(1 - d) + Sqrt[-a]*e)]*Log[1 - d - e*x])/(4*Sqrt[-a]*Sqrt[b]) + (Log[(e*(Sqrt[-a] - Sqrt[b]*x))/(Sqrt[b]*(1 + d) + Sqrt[-a]*e)]*Log[1 + d + e*x])/(4*Sqrt[-a]*Sqrt[b]) - (Log[-((e*(Sqrt[-a] + Sqrt[b]*x))/(Sqrt[b]*(1 + d) - Sqrt[-a]*e))]*Log[1 + d + e*x])/(4*Sqrt[-a]*Sqrt[b]) - PolyLog[2, (Sqrt[b]*(1 - d - e*x))/(Sqrt[b]*(1 - d) - Sqrt[-a]*e)]/(4*Sqrt[-a]*Sqrt[b]) + PolyLog[2, (Sqrt[b]*(1 - d - e*x))/(Sqrt[b]*(1 - d) + Sqrt[-a]*e)]/(4*Sqrt[-a]*Sqrt[b]) - PolyLog[2, (Sqrt[b]*(1 + d + e*x))/(Sqrt[b]*(1 + d) - Sqrt[-a]*e)]/(4*Sqrt[-a]*Sqrt[b]) + PolyLog[2, (Sqrt[b]*(1 + d + e*x))/(Sqrt[b]*(1 + d) + Sqrt[-a]*e)]/(4*Sqrt[-a]*Sqrt[b])}
{ArcTanh[d + e*x]/(a + b*x + c*x^2), x, 7, -((Log[(e*(b - Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c*(1 - d) + (b - Sqrt[b^2 - 4*a*c])*e)]*Log[1 - d - e*x])/(2*Sqrt[b^2 - 4*a*c])) + (Log[(e*(b + Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c*(1 - d) + (b + Sqrt[b^2 - 4*a*c])*e)]*Log[1 - d - e*x])/(2*Sqrt[b^2 - 4*a*c]) + (Log[-((e*(b - Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c*(1 + d) - (b - Sqrt[b^2 - 4*a*c])*e))]*Log[1 + d + e*x])/(2*Sqrt[b^2 - 4*a*c]) - (Log[-((e*(b + Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c*(1 + d) - (b + Sqrt[b^2 - 4*a*c])*e))]*Log[1 + d + e*x])/(2*Sqrt[b^2 - 4*a*c]) - PolyLog[2, (2*c*(1 - d - e*x))/(2*c*(1 - d) + (b - Sqrt[b^2 - 4*a*c])*e)]/(2*Sqrt[b^2 - 4*a*c]) + PolyLog[2, (2*c*(1 - d - e*x))/(2*c*(1 - d) + (b + Sqrt[b^2 - 4*a*c])*e)]/(2*Sqrt[b^2 - 4*a*c]) + PolyLog[2, (2*c*(1 + d + e*x))/(2*c*(1 + d) - (b - Sqrt[b^2 - 4*a*c])*e)]/(2*Sqrt[b^2 - 4*a*c]) - PolyLog[2, (2*c*(1 + d + e*x))/(2*c*(1 + d) - (b + Sqrt[b^2 - 4*a*c])*e)]/(2*Sqrt[b^2 - 4*a*c])}


{1/((a - a*x^2)*(b - 2*b*ArcTanh[x])), x, 3, -(Log[1 - 2*ArcTanh[x]]/(2*a*b))}


{ArcTanh[b*x]/(1 - x^2), x, 9, (1/4)*Log[-((b*(1 - x))/(1 - b))]*Log[1 - b*x] - (1/4)*Log[(b*(1 + x))/(1 + b)]*Log[1 - b*x] - (1/4)*Log[(b*(1 - x))/(1 + b)]*Log[1 + b*x] + (1/4)*Log[-((b*(1 + x))/(1 - b))]*Log[1 + b*x] + (1/4)*PolyLog[2, (1 - b*x)/(1 - b)] - (1/4)*PolyLog[2, (1 - b*x)/(1 + b)] + (1/4)*PolyLog[2, (1 + b*x)/(1 - b)] - (1/4)*PolyLog[2, (1 + b*x)/(1 + b)]}
{ArcTanh[a+b*x]/(1 - x^2), x, 9, (1/4)*Log[-((b*(1 - x))/(1 - a - b))]*Log[1 - a - b*x] - (1/4)*Log[(b*(1 + x))/(1 - a + b)]*Log[1 - a - b*x] - (1/4)*Log[(b*(1 - x))/(1 + a + b)]*Log[1 + a + b*x] + (1/4)*Log[-((b*(1 + x))/(1 + a - b))]*Log[1 + a + b*x] + (1/4)*PolyLog[2, (1 - a - b*x)/(1 - a - b)] - (1/4)*PolyLog[2, (1 - a - b*x)/(1 - a + b)] + (1/4)*PolyLog[2, (1 + a + b*x)/(1 + a - b)] - (1/4)*PolyLog[2, (1 + a + b*x)/(1 + a + b)]}


(* Integrands of the form ArcTanh[x]/(a+b*x^2)^n where n is a half-integer *)
{ArcTanh[x]/(a + b*x^2)^(3/2), x, 3, (x*ArcTanh[x])/(a*Sqrt[a + b*x^2]) - ArcTanh[Sqrt[a + b*x^2]/Sqrt[a + b]]/(a*Sqrt[a + b])}
{ArcTanh[x]/(a + b*x^2)^(5/2), x, 8, 1/(3*a*(a + b)*Sqrt[a + b*x^2]) + (x*(3*a + 2*b*x^2)*ArcTanh[x])/(3*a^2*(a + b*x^2)^(3/2)) - ((3*a + 2*b)*ArcTanh[Sqrt[a + b*x^2]/Sqrt[a + b]])/(3*a^2*(a + b)^(3/2))}
{ArcTanh[x]/(a + b*x^2)^(7/2), x, 8, 1/(15*a*(a + b)*(a + b*x^2)^(3/2)) + (7*a + 4*b)/(15*a^2*(a + b)^2*Sqrt[a + b*x^2]) + (x*(8*(a + b*x^2)^2 + a*(7*a + 4*b*x^2))*ArcTanh[x])/(15*a^3*(a + b*x^2)^(5/2)) - ((15*a^2 + 20*a*b + 8*b^2)*ArcTanh[Sqrt[a + b*x^2]/Sqrt[a + b]])/(15*a^3*(a + b)^(5/2))}

{ArcTanh[x]*(a - a*x^2)^(1/2), x, 3, (1/2)*Sqrt[a - a*x^2] + (1/2)*x*Sqrt[a - a*x^2]*ArcTanh[x] - (a*Sqrt[1 - x^2]*(2*ArcTan[Sqrt[1 - x]/Sqrt[1 + x]]*ArcTanh[x] + I*PolyLog[2, -((I*Sqrt[1 - x])/Sqrt[1 + x])] - I*PolyLog[2, (I*Sqrt[1 - x])/Sqrt[1 + x]]))/(2*Sqrt[a - a*x^2])}
{ArcTanh[x]/(a - a*x^2)^(1/2), x, 2, -((Sqrt[1 - x^2]*(2*ArcTan[Sqrt[1 - x]/Sqrt[1 + x]]*ArcTanh[x] + I*PolyLog[2, -((I*Sqrt[1 - x])/Sqrt[1 + x])] - I*PolyLog[2, (I*Sqrt[1 - x])/Sqrt[1 + x]]))/Sqrt[a - a*x^2])}
{ArcTanh[x]/(a - a*x^2)^(3/2), x, 1, -(1/(a*Sqrt[a - a*x^2])) + (x*ArcTanh[x])/(a*Sqrt[a - a*x^2])}
{ArcTanh[x]/(a - a*x^2)^(5/2), x, 2, -(1/(9*a*(a - a*x^2)^(3/2))) - 2/(3*a^2*Sqrt[a - a*x^2]) + (x*ArcTanh[x])/(3*a*(a - a*x^2)^(3/2)) + (2*x*ArcTanh[x])/(3*a^2*Sqrt[a - a*x^2])}
{ArcTanh[x]/(a - a*x^2)^(7/2), x, 3, -(1/(25*a*(a - a*x^2)^(5/2))) - 4/(45*a^2*(a - a*x^2)^(3/2)) - 8/(15*a^3*Sqrt[a - a*x^2]) + (x*ArcTanh[x])/(5*a*(a - a*x^2)^(5/2)) + (4*x*ArcTanh[x])/(15*a^2*(a - a*x^2)^(3/2)) + (8*x*ArcTanh[x])/(15*a^3*Sqrt[a - a*x^2])}


(* Integrands of the form x^m*ArcTanh[Sqrt[x]] where m is an integer *)
{ArcTanh[Sqrt[x]], x, 4, Sqrt[x] - ArcTanh[Sqrt[x]] + x*ArcTanh[Sqrt[x]]}
{x*ArcTanh[Sqrt[x]], x, 5, Sqrt[x]/2 + x^(3/2)/6 - ArcTanh[Sqrt[x]]/2 + (1/2)*x^2*ArcTanh[Sqrt[x]]}
{x^2*ArcTanh[Sqrt[x]], x, 6, Sqrt[x]/3 + x^(3/2)/9 + x^(5/2)/15 - ArcTanh[Sqrt[x]]/3 + (1/3)*x^3*ArcTanh[Sqrt[x]]}
{ArcTanh[Sqrt[x]]/x, x, 3, -PolyLog[2, -Sqrt[x]] + PolyLog[2, Sqrt[x]]}
{ArcTanh[Sqrt[x]]/x^2, x, 4, -(1/Sqrt[x]) + ArcTanh[Sqrt[x]] - ArcTanh[Sqrt[x]]/x}
{ArcTanh[Sqrt[x]]/x^3, x, 5, -(1/(6*x^(3/2))) - 1/(2*Sqrt[x]) + ArcTanh[Sqrt[x]]/2 - ArcTanh[Sqrt[x]]/(2*x^2)}

{Sqrt[x]*ArcTanh[Sqrt[x]], x, 5, x/3 + (2/3)*x^(3/2)*ArcTanh[Sqrt[x]] + (1/3)*Log[1 - x]}
{x^(3/2)*ArcTanh[Sqrt[x]], x, 6, x/5 + x^2/10 + (2/5)*x^(5/2)*ArcTanh[Sqrt[x]] + (1/5)*Log[1 - x]}
{ArcTanh[Sqrt[x]]/Sqrt[x], x, 2, 2*Sqrt[x]*ArcTanh[Sqrt[x]] + Log[1 - x]}
{ArcTanh[Sqrt[x]]/x^(3/2), x, 4, -2*ArcTanh[1 - 2*x] - (2*ArcTanh[Sqrt[x]])/Sqrt[x]}


(* ::Subsection::Closed:: *)
(*Integrands involving inverse hyperbolic functions of exponentials*)


(* Integrands of the form x^m*ArcTanh[E^x] *)
{ArcTanh[E^x], x, 3, (-(1/2))*PolyLog[2, -E^x] + (1/2)*PolyLog[2, E^x]}
{x*ArcTanh[E^x], x, 5, (-(1/2))*x*PolyLog[2, -E^x] + (1/2)*x*PolyLog[2, E^x] + (1/2)*PolyLog[3, -E^x] - (1/2)*PolyLog[3, E^x]}
{x^2*ArcTanh[E^x], x, 7, (-(1/2))*x^2*PolyLog[2, -E^x] + (1/2)*x^2*PolyLog[2, E^x] + x*PolyLog[3, -E^x] - x*PolyLog[3, E^x] - PolyLog[4, -E^x] + PolyLog[4, E^x]}


(* Integrands of the form x^m*ArcTanh[E^(a+b*x)] *)
{ArcTanh[E^(a + b*x)], x, 3, -(PolyLog[2, -E^(a + b*x)]/(2*b)) + PolyLog[2, E^(a + b*x)]/(2*b)}
{x*ArcTanh[E^(a + b*x)], x, 5, -((x*PolyLog[2, -E^(a + b*x)])/(2*b)) + (x*PolyLog[2, E^(a + b*x)])/(2*b) + PolyLog[3, -E^(a + b*x)]/(2*b^2) - PolyLog[3, E^(a + b*x)]/(2*b^2)}
{x^2*ArcTanh[E^(a + b*x)], x, 7, -((x^2*PolyLog[2, -E^(a + b*x)])/(2*b)) + (x^2*PolyLog[2, E^(a + b*x)])/(2*b) + (x*PolyLog[3, -E^(a + b*x)])/b^2 - (x*PolyLog[3, E^(a + b*x)])/b^2 - PolyLog[4, -E^(a + b*x)]/b^3 + PolyLog[4, E^(a + b*x)]/b^3}


(* Integrands of the form x^m*ArcTanh[a+b*f^(c+d*x)] *)
{ArcTanh[a + b*f^(c + d*x)], x, 10, x*ArcTanh[a + b*f^(c + d*x)] + (1/2)*x*Log[1 - (b*f^(c + d*x))/(1 - a)] - (1/2)*x*Log[1 + (b*f^(c + d*x))/(1 + a)] + PolyLog[2, (b*f^(c + d*x))/(1 - a)]/(2*d*Log[f]) - PolyLog[2, -((b*f^(c + d*x))/(1 + a))]/(2*d*Log[f])}
{x*ArcTanh[a + b*f^(c + d*x)], x, 12, (1/2)*x^2*ArcTanh[a + b*f^(c + d*x)] + (1/4)*x^2*Log[1 - (b*f^(c + d*x))/(1 - a)] - (1/4)*x^2*Log[1 + (b*f^(c + d*x))/(1 + a)] + (x*PolyLog[2, (b*f^(c + d*x))/(1 - a)])/(2*d*Log[f]) - (x*PolyLog[2, -((b*f^(c + d*x))/(1 + a))])/(2*d*Log[f]) - PolyLog[3, (b*f^(c + d*x))/(1 - a)]/(2*d^2*Log[f]^2) + PolyLog[3, -((b*f^(c + d*x))/(1 + a))]/(2*d^2*Log[f]^2)}
{x^2*ArcTanh[a + b*f^(c + d*x)], x, 14, (1/3)*x^3*ArcTanh[a + b*f^(c + d*x)] + (1/6)*x^3*Log[1 - (b*f^(c + d*x))/(1 - a)] - (1/6)*x^3*Log[1 + (b*f^(c + d*x))/(1 + a)] + (x^2*PolyLog[2, (b*f^(c + d*x))/(1 - a)])/(2*d*Log[f]) - (x^2*PolyLog[2, -((b*f^(c + d*x))/(1 + a))])/(2*d*Log[f]) - (x*PolyLog[3, (b*f^(c + d*x))/(1 - a)])/(d^2*Log[f]^2) + (x*PolyLog[3, -((b*f^(c + d*x))/(1 + a))])/(d^2*Log[f]^2) + PolyLog[4, (b*f^(c + d*x))/(1 - a)]/(d^3*Log[f]^3) - PolyLog[4, -((b*f^(c + d*x))/(1 + a))]/(d^3*Log[f]^3)}


(* ::Subsection::Closed:: *)
(*Integrands involving inverse hyperbolic functions of hyperbolic functions*)


(* Integrands of the form ArcTanh[a+b*Hyper[x]] *)
{ArcTanh[Tanh[x]], x, 2, -(x^2/2) + x*ArcTanh[Tanh[x]]}
{ArcTanh[b*Tanh[x]], x, 12, x*ArcTanh[b*Tanh[x]] - (1/2)*x*Log[1 + ((1 - b^2)*E^(2*x))/(1 - 2*b + b^2)] + (1/2)*x*Log[1 + ((1 - b^2)*E^(2*x))/(1 + 2*b + b^2)] - (1/4)*PolyLog[2, -(((1 - b^2)*E^(2*x))/(1 - 2*b + b^2))] + (1/4)*PolyLog[2, -(((1 - b^2)*E^(2*x))/(1 + 2*b + b^2))]}
{ArcTanh[a+b*Tanh[x]], x, 10, (1/4)*Log[-((b*(1 - Tanh[x]))/(1 - a - b))]*Log[1 - a - b*Tanh[x]] - (1/4)*Log[(b*(1 + Tanh[x]))/(1 - a + b)]*Log[1 - a - b*Tanh[x]] - (1/4)*Log[(b*(1 - Tanh[x]))/(1 + a + b)]*Log[1 + a + b*Tanh[x]] + (1/4)*Log[-((b*(1 + Tanh[x]))/(1 + a - b))]*Log[1 + a + b*Tanh[x]] + (1/4)*PolyLog[2, (1 - a - b*Tanh[x])/(1 - a - b)] - (1/4)*PolyLog[2, (1 - a - b*Tanh[x])/(1 - a + b)] + (1/4)*PolyLog[2, (1 + a + b*Tanh[x])/(1 + a - b)] - (1/4)*PolyLog[2, (1 + a + b*Tanh[x])/(1 + a + b)]}

{ArcTanh[b*Coth[x]], x, 12, x*ArcTanh[b*Coth[x]] - (1/2)*x*Log[1 - ((1 - b^2)*E^(2*x))/(1 - 2*b + b^2)] + (1/2)*x*Log[1 - ((1 - b^2)*E^(2*x))/(1 + 2*b + b^2)] - (1/4)*PolyLog[2, ((1 - b^2)*E^(2*x))/(1 - 2*b + b^2)] + (1/4)*PolyLog[2, ((1 - b^2)*E^(2*x))/(1 + 2*b + b^2)]}
{ArcTanh[a+b*Coth[x]], x, 10, (1/4)*Log[-((b*(1 - Coth[x]))/(1 - a - b))]*Log[1 - a - b*Coth[x]] - (1/4)*Log[(b*(1 + Coth[x]))/(1 - a + b)]*Log[1 - a - b*Coth[x]] - (1/4)*Log[(b*(1 - Coth[x]))/(1 + a + b)]*Log[1 + a + b*Coth[x]] + (1/4)*Log[-((b*(1 + Coth[x]))/(1 + a - b))]*Log[1 + a + b*Coth[x]] + (1/4)*PolyLog[2, (1 - a - b*Coth[x])/(1 - a - b)] - (1/4)*PolyLog[2, (1 - a - b*Coth[x])/(1 - a + b)] + (1/4)*PolyLog[2, (1 + a + b*Coth[x])/(1 + a - b)] - (1/4)*PolyLog[2, (1 + a + b*Coth[x])/(1 + a + b)]}


(* Integrands of the form x^m*ArcTanh[Sinh[x]] where m is an integer *)
(* {ArcTanh[Sinh[x]], x, 6, 0}
{x*ArcTanh[Sinh[x]], x, 8, 0}
{x^2*ArcTanh[Sinh[x]], x, 10, 0} *)


(* Integrands of the form x^m*ArcTanh[Cosh[x]] where m is an integer *)
{ArcTanh[Cosh[x]], x, 6, -2*x*ArcTanh[E^x] + x*ArcTanh[Cosh[x]] - PolyLog[2, -E^x] + PolyLog[2, E^x]}
{x*ArcTanh[Cosh[x]], x, 8, (-x^2)*ArcTanh[E^x] + (1/2)*x^2*ArcTanh[Cosh[x]] - x*PolyLog[2, -E^x] + x*PolyLog[2, E^x] + PolyLog[3, -E^x] - PolyLog[3, E^x]}
{x^2*ArcTanh[Cosh[x]], x, 10, (-(2/3))*x^3*ArcTanh[E^x] + (1/3)*x^3*ArcTanh[Cosh[x]] - x^2*PolyLog[2, -E^x] + x^2*PolyLog[2, E^x] + 2*x*PolyLog[3, -E^x] - 2*x*PolyLog[3, E^x] - 2*PolyLog[4, -E^x] + 2*PolyLog[4, E^x]}


(* ::Subsection::Closed:: *)
(*Integrands involving exponentials of inverse hyperbolic tangents*)


(* ::Subsubsection::Closed:: *)
(*Products of monomials and exponentials of inverse tangents*)


{x^2*E^ArcTanh[x], x, 8, (-(2/3))*Sqrt[1 - x^2] - (1/2)*x*Sqrt[1 - x^2] - (1/3)*x^2*Sqrt[1 - x^2] + ArcSin[x]/2}
{x*E^ArcTanh[x], x, 7, -Sqrt[1 - x^2] - (1/2)*x*Sqrt[1 - x^2] + ArcSin[x]/2}
{E^ArcTanh[x], x, 3, -Sqrt[1 - x^2] + ArcSin[x], (-Sqrt[1 - x])*Sqrt[1 + x] + ArcSin[x]}
{E^ArcTanh[x]/x, x, 5, ArcSin[x] - ArcTanh[Sqrt[1 - x^2]]}
{E^ArcTanh[x]/x^2, x, 5, -(Sqrt[1 - x^2]/x) - ArcTanh[Sqrt[1 - x^2]]}
{E^ArcTanh[x]/x^3, x, 6, -(Sqrt[1 - x^2]/(2*x^2)) - Sqrt[1 - x^2]/x - (1/2)*ArcTanh[Sqrt[1 - x^2]]}


{x^2*E^(2*ArcTanh[x]), x, 5, -2*x - x^2 - x^3/3 - 2*Log[1 - x]}
{x*E^(2*ArcTanh[x]), x, 5, -2*x - x^2/2 - 2*Log[1 - x]}
{E^(2*ArcTanh[x]), x, 4, -x - 2*Log[1 - x]}
{E^(2*ArcTanh[x])/x, x, 5, -2*Log[1 - x] + Log[x]}
{E^(2*ArcTanh[x])/x^2, x, 6, -(1/x) - 4*ArcTanh[1 - 2*x]}
{E^(2*ArcTanh[x])/x^3, x, 6, -(1/(2*x^2)) - 2/x - 4*ArcTanh[1 - 2*x]}


{x^2*E^(3*ArcTanh[x]), x, 15, x/Sqrt[1 - x^2] + (3*x^2)/Sqrt[1 - x^2] + (3*x^3)/Sqrt[1 - x^2] + x^4/Sqrt[1 - x^2] + (26*Sqrt[1 - x^2])/3 + (9/2)*x*Sqrt[1 - x^2] + (4/3)*x^2*Sqrt[1 - x^2] - (11*ArcSin[x])/2}
{x*E^(3*ArcTanh[x]), x, 13, 1/Sqrt[1 - x^2] + (3*x)/Sqrt[1 - x^2] + (3*x^2)/Sqrt[1 - x^2] + x^3/Sqrt[1 - x^2] + 6*Sqrt[1 - x^2] + (3/2)*x*Sqrt[1 - x^2] - (9*ArcSin[x])/2}
{E^(3*ArcTanh[x]), x, 4, -(((-5 + x)*Sqrt[1 + x])/Sqrt[1 - x]) - 3*ArcSin[x], 3*Sqrt[1 - x]*Sqrt[1 + x] + (2*(1 + x)^(3/2))/Sqrt[1 - x] - 3*ArcSin[x]}
{E^(3*ArcTanh[x])/x, x, 10, 4/Sqrt[1 - x^2] + (4*x)/Sqrt[1 - x^2] - ArcSin[x] - ArcTanh[Sqrt[1 - x^2]]}
{E^(3*ArcTanh[x])/x^2, x, 10, 4/Sqrt[1 - x^2] + 1/(x*Sqrt[1 - x^2]) + (3*x)/Sqrt[1 - x^2] - (2*Sqrt[1 - x^2])/x - 3*ArcTanh[Sqrt[1 - x^2]]}
{E^(3*ArcTanh[x])/x^3, x, 11, 3/Sqrt[1 - x^2] + 1/(x^2*Sqrt[1 - x^2]) + 3/(x*Sqrt[1 - x^2]) + x/Sqrt[1 - x^2] - (3*Sqrt[1 - x^2])/(2*x^2) - (6*Sqrt[1 - x^2])/x - (9/2)*ArcTanh[Sqrt[1 - x^2]]}


{x^2*E^(4*ArcTanh[x]), x, 6, 4/(1 - x) + 8*x + 2*x^2 + x^3/3 + 12*Log[1 - x]}
{x*E^(4*ArcTanh[x]), x, 6, 4/(1 - x) + 4*x + x^2/2 + 8*Log[1 - x]}
{E^(4*ArcTanh[x]), x, 5, 4/(1 - x) + x + 4*Log[1 - x]}
{E^(4*ArcTanh[x])/x, x, 5, 4/(1 - x) + Log[x]}
{E^(4*ArcTanh[x])/x^2, x, 7, 4/(1 - x) - 1/x - 8*ArcTanh[1 - 2*x]}
{E^(4*ArcTanh[x])/x^3, x, 7, 4/(1 - x) - 1/(2*x^2) - 4/x - 16*ArcTanh[1 - 2*x]}


{x^2*E^(ArcTanh[x]/2), x, 14, (1/8)*E^(ArcTanh[x]/2)*(1 - x) + (1/28)*E^(ArcTanh[x]/2)*(1 - x)^2 - (1/7)*E^(ArcTanh[x]/2)*(1 - x)^3 - (1/7)*E^((5*ArcTanh[x])/2)*(1 - x)^3 - (1/3)*E^((9*ArcTanh[x])/2)*(1 - x)^3 - (3*ArcTan[1 - Sqrt[2]*E^(ArcTanh[x]/2)])/(8*Sqrt[2]) + (3*ArcTan[1 + Sqrt[2]*E^(ArcTanh[x]/2)])/(8*Sqrt[2]) - (3*Log[1 - Sqrt[2]*E^(ArcTanh[x]/2) + E^ArcTanh[x]])/(16*Sqrt[2]) + (3*Log[1 + Sqrt[2]*E^(ArcTanh[x]/2) + E^ArcTanh[x]])/(16*Sqrt[2])}
{x*E^(ArcTanh[x]/2), x, 12, (1/12)*E^(ArcTanh[x]/2)*(1 - x) - (1/6)*E^(ArcTanh[x]/2)*(1 - x)^2 - (2/3)*E^((5*ArcTanh[x])/2)*(1 - x)^2 - ArcTan[1 - Sqrt[2]*E^(ArcTanh[x]/2)]/(4*Sqrt[2]) + ArcTan[1 + Sqrt[2]*E^(ArcTanh[x]/2)]/(4*Sqrt[2]) - Log[1 - Sqrt[2]*E^(ArcTanh[x]/2) + E^ArcTanh[x]]/(8*Sqrt[2]) + Log[1 + Sqrt[2]*E^(ArcTanh[x]/2) + E^ArcTanh[x]]/(8*Sqrt[2])}
{E^(ArcTanh[x]/2), x, 8, (-(1 - x)^(3/4))*(1 + x)^(1/4) + ArcTan[1 - (Sqrt[2]*(1 - x)^(1/4))/(1 + x)^(1/4)]/Sqrt[2] - ArcTan[1 + (Sqrt[2]*(1 - x)^(1/4))/(1 + x)^(1/4)]/Sqrt[2] - Log[1 + Sqrt[1 - x]/Sqrt[1 + x] - (Sqrt[2]*(1 - x)^(1/4))/(1 + x)^(1/4)]/(2*Sqrt[2]) + Log[1 + Sqrt[1 - x]/Sqrt[1 + x] + (Sqrt[2]*(1 - x)^(1/4))/(1 + x)^(1/4)]/(2*Sqrt[2])}
{E^(ArcTanh[x]/2)/x, x, 12, -2*ArcTan[E^(ArcTanh[x]/2)] - Sqrt[2]*ArcTan[1 - Sqrt[2]*E^(ArcTanh[x]/2)] + Sqrt[2]*ArcTan[1 + Sqrt[2]*E^(ArcTanh[x]/2)] - 2*ArcTanh[E^(ArcTanh[x]/2)] - Log[1 - Sqrt[2]*E^(ArcTanh[x]/2) + E^ArcTanh[x]]/Sqrt[2] + Log[1 + Sqrt[2]*E^(ArcTanh[x]/2) + E^ArcTanh[x]]/Sqrt[2]}
{E^(ArcTanh[x]/2)/x^2, x, 7, -((E^(ArcTanh[x]/2)*(1 - x))/x) - ArcTan[E^(ArcTanh[x]/2)] - ArcTanh[E^(ArcTanh[x]/2)]}
{E^(ArcTanh[x]/2)/x^3, x, 10, (E^(ArcTanh[x]/2)*(1 - x)^2)/(6*x^2) - (2*E^((5*ArcTanh[x])/2)*(1 - x)^2)/(3*x^2) + (E^(ArcTanh[x]/2)*(1 - x))/(12*x) - (1/4)*ArcTan[E^(ArcTanh[x]/2)] - (1/4)*ArcTanh[E^(ArcTanh[x]/2)]}


(* {x^2*E^(ArcTanh[x]/3), x, 8, 0}
{x*E^(ArcTanh[x]/3), x, 7, 0} *)
{E^(ArcTanh[x]/3), x, 8, (-(1 - x)^(5/6))*(1 + x)^(1/6) - (2/3)*ArcTan[(1 - x)^(1/6)/(1 + x)^(1/6)] + (1/3)*ArcTan[((1 - x)^(1/6)*(1 + x)^(1/6))/((1 - x)^(1/3) - (1 + x)^(1/3))] + ArcTanh[(Sqrt[3]*(1 - x)^(1/6)*(1 + x)^(1/6))/((1 - x)^(1/3) + (1 + x)^(1/3))]/Sqrt[3]}
(* {E^(ArcTanh[x]/3)/x, x, 32, 2*ArcTan[E^(ArcTanh[x]/3)] + Sqrt[3]*ArcTan[(1 - 2*E^(ArcTanh[x]/3))/Sqrt[3]] - ArcTan[Sqrt[3] - 2*E^(ArcTanh[x]/3)] - Sqrt[3]*ArcTan[(1 + 2*E^(ArcTanh[x]/3))/Sqrt[3]] + ArcTan[Sqrt[3] + 2*E^(ArcTanh[x]/3)] + Log[-1 + E^(ArcTanh[x]/3)] - Log[1 + E^(ArcTanh[x]/3)] + (1/2)*Log[1 - E^(ArcTanh[x]/3) + E^((2*ArcTanh[x])/3)] - (1/2)*Log[1 + E^(ArcTanh[x]/3) + E^((2*ArcTanh[x])/3)] - (1/2)*Sqrt[3]*Log[1 - Sqrt[3]*E^(ArcTanh[x]/3) + E^((2*ArcTanh[x])/3)] + (1/2)*Sqrt[3]*Log[1 + Sqrt[3]*E^(ArcTanh[x]/3) + E^((2*ArcTanh[x])/3)]}
{E^(ArcTanh[x]/3)/x^2, x, 39, 1/(3*(1 - E^(ArcTanh[x]/3))) - 1/(3*(1 + E^(ArcTanh[x]/3))) + 1/(3*(1 - E^(ArcTanh[x]/3) + E^((2*ArcTanh[x])/3))) + E^(ArcTanh[x]/3)/(3*(1 - E^(ArcTanh[x]/3) + E^((2*ArcTanh[x])/3))) - 1/(3*(1 + E^(ArcTanh[x]/3) + E^((2*ArcTanh[x])/3))) + E^(ArcTanh[x]/3)/(3*(1 + E^(ArcTanh[x]/3) + E^((2*ArcTanh[x])/3))) + ArcTan[(1 - 2*E^(ArcTanh[x]/3))/Sqrt[3]]/Sqrt[3] - ArcTan[(1 + 2*E^(ArcTanh[x]/3))/Sqrt[3]]/Sqrt[3] + (1/3)*Log[-1 + E^(ArcTanh[x]/3)] - (1/3)*Log[1 + E^(ArcTanh[x]/3)] + (1/6)*Log[1 - E^(ArcTanh[x]/3) + E^((2*ArcTanh[x])/3)] - (1/6)*Log[1 + E^(ArcTanh[x]/3) + E^((2*ArcTanh[x])/3)]}
{E^(ArcTanh[x]/3)/x^3, x, 6, 0} *)


{E^(2*ArcTanh[x]/3), x, 7, (-(1 - x)^(2/3))*(1 + x)^(1/3) + (2*ArcTan[(1 - (2*(1 - x)^(1/3))/(1 + x)^(1/3))/Sqrt[3]])/Sqrt[3] - (1/3)*Log[1 + (1 - x)^(2/3)/(1 + x)^(2/3) - (1 - x)^(1/3)/(1 + x)^(1/3)] + (2/3)*Log[1 + (1 - x)^(1/3)/(1 + x)^(1/3)]}
{E^(ArcTanh[x]/4), x, 22, (-(1 - x)^(7/8))*(1 + x)^(1/8) - (1/2)*(-1)^(1/8)*ArcTan[((-1)^(1/8)*(1 - x)^(1/8))/(1 + x)^(1/8)] - (1/2)*(-1)^(7/8)*ArcTan[((-1)^(7/8)*(1 - x)^(1/8))/(1 + x)^(1/8)] + (1/2)*(-1)^(1/8)*ArcTanh[((-1)^(1/8)*(1 - x)^(1/8))/(1 + x)^(1/8)] + (1/2)*(-1)^(7/8)*ArcTanh[((-1)^(7/8)*(1 - x)^(1/8))/(1 + x)^(1/8)]}


(* ::Subsubsection::Closed:: *)
(*Products of monomials, exponentials of inverse tangents and (1-v^2)^n*)


(* Integrands of the form x^m*E^ArcTanh[a+b*x]/(1-(a+b*x)^2) *)
{x^2*E^ArcTanh[a + b*x]/(1 - a^2 - 2*a*b*x - b^2*x^2), x, 15, (2*E^ArcTanh[a + b*x])/b^3 - (3*a*E^ArcTanh[a + b*x])/b^3 + (a^2*E^ArcTanh[a + b*x])/b^3 - (E^ArcTanh[a + b*x]*x)/b^2 - ArcSin[a + b*x]/b^3 + (2*a*ArcSin[a + b*x])/b^3, (2*E^ArcTanh[a + b*x])/b^3 - (3*a*E^ArcTanh[a + b*x])/b^3 + (a^2*E^ArcTanh[a + b*x])/b^3 - (E^ArcTanh[a + b*x]*x)/b^2 - (2*ArcTan[E^ArcTanh[a + b*x]])/b^3 + (4*a*ArcTan[E^ArcTanh[a + b*x]])/b^3}
{x*E^ArcTanh[a + b*x]/(1 - a^2 - 2*a*b*x - b^2*x^2), x, 9, E^ArcTanh[a + b*x]/b^2 - (a*E^ArcTanh[a + b*x])/b^2 - ArcSin[a + b*x]/b^2, E^ArcTanh[a + b*x]/b^2 - (a*E^ArcTanh[a + b*x])/b^2 - (2*ArcTan[E^ArcTanh[a + b*x]])/b^2}
{E^ArcTanh[a + b*x]/(1 - a^2 - 2*a*b*x - b^2*x^2), x, 2, E^ArcTanh[a + b*x]/b}
{E^ArcTanh[a + b*x]/(x*(1 - a^2 - 2*a*b*x - b^2*x^2)), x, 7, E^ArcTanh[a + b*x]/(1 - a) + (2*ArcTan[(Sqrt[-1 + a]*E^ArcTanh[a + b*x])/Sqrt[1 + a]])/((-1 + a)^(3/2)*Sqrt[1 + a])}
{E^ArcTanh[a + b*x]/(x^2*(1 - a^2 - 2*a*b*x - b^2*x^2)), x, 11, (b*E^ArcTanh[a + b*x])/(1 - a)^2 + (2*b*E^ArcTanh[a + b*x])/((1 - a)^2*(1 + a)*(1 + a + (1 - a)*(1 - 2/(1 - a - b*x)))) - (2*a*b*ArcTan[(Sqrt[-1 + a]*E^ArcTanh[a + b*x])/Sqrt[1 + a]])/((-1 + a)^(5/2)*(1 + a)^(3/2)) - (2*b*ArcTan[(Sqrt[-1 + a]*E^ArcTanh[a + b*x])/Sqrt[1 + a]])/((-1 + a)^(5/2)*Sqrt[1 + a])}


(* ::Subsubsection::Closed:: *)
(*Products of exponentials of inverse tangents and powers of linear binomials*)


{E^ArcTanh[x]*(1 - x)^2, x, 5, (1/2)*Sqrt[1 - x]*Sqrt[1 + x] + (1/6)*(1 - x)^(3/2)*Sqrt[1 + x] - (1/3)*(1 - x)^(5/2)*Sqrt[1 + x] + ArcSin[x]/2}
{E^ArcTanh[x]*(1 - x), x, 4, (1/2)*x*Sqrt[1 - x^2] + ArcSin[x]/2}
{E^ArcTanh[x]/(1 - x), x, 3, (2*Sqrt[1 + x])/Sqrt[1 - x] - ArcSin[x]}
{E^ArcTanh[x]/(1 - x)^2, x, 2, (1 + x)^(3/2)/(3*(1 - x)^(3/2))}


{E^ArcTanh[x]*(1 + x)^2, x, 5, (-(10/3))*Sqrt[1 - x^2] - (5/6)*x*Sqrt[1 - x^2] - (1/3)*(1 + x)^2*Sqrt[1 - x^2] + (5*ArcSin[x])/2}
{E^ArcTanh[x]*(1 + x), x, 4, -2*Sqrt[1 - x^2] - (1/2)*x*Sqrt[1 - x^2] + (3*ArcSin[x])/2}
{E^ArcTanh[x]/(1 + x), x, 2, ArcSin[x]}
{E^ArcTanh[x]/(1 + x)^2, x, 2, -(Sqrt[1 - x^2]/(1 + x))}


{E^ArcTanh[x]*(1 - x)^(3/2), x, 3, (14/15)*(1 + x)^(3/2) - (2/5)*x*(1 + x)^(3/2)}
{E^ArcTanh[x]*(1 - x)^(1/2), x, 2, (2/3)*(1 + x)^(3/2)}
{E^ArcTanh[x]/(1 - x)^(1/2), x, 3, -2*Sqrt[1 + x] + 2*Sqrt[2]*ArcTanh[Sqrt[1 + x]/Sqrt[2]]}
{E^ArcTanh[x]/(1 - x)^(3/2), x, 3, Sqrt[1 + x]/(1 - x) - ArcTanh[Sqrt[1 + x]/Sqrt[2]]/Sqrt[2]}


{E^ArcTanh[x]*(1 + x)^(3/2), x, 4, -((16*Sqrt[1 - x])/3) - (16/15)*Sqrt[1 - x]*x - (2/5)*Sqrt[1 - x]*(1 + x)^2}
{E^ArcTanh[x]*(1 + x)^(1/2), x, 3, -((10*Sqrt[1 - x])/3) - (2/3)*Sqrt[1 - x]*x}
{E^ArcTanh[x]/(1 + x)^(1/2), x, 2, -2*Sqrt[1 - x]}
{E^ArcTanh[x]/(1 + x)^(3/2), x, 2, (-Sqrt[2])*ArcTanh[Sqrt[1 - x]/Sqrt[2]]}


(* ::Subsubsection::Closed:: *)
(*Products of monomials, exponentials of inverse tangents and powers of linear binomials*)


{x*E^ArcTanh[x]*(1 - x), x, 2, (-(1/3))*(1 - x)^(3/2)*(1 + x)^(3/2)}
{x*E^ArcTanh[x]*(1 - x)^2, x, 11, (-(1/8))*Sqrt[1 - x]*Sqrt[1 + x] - (1/24)*(1 - x)^(3/2)*Sqrt[1 + x] - (5/12)*(1 - x)^(5/2)*Sqrt[1 + x] + (1/4)*(1 - x)^(7/2)*Sqrt[1 + x] - ArcSin[x]/8}

{x*E^ArcTanh[x]/(1 - x), x, 7, -(((-3 + x)*Sqrt[1 + x])/Sqrt[1 - x]) - 2*ArcSin[x], -((2*Sqrt[1 + x])/Sqrt[1 - x]) + 3*Sqrt[1 - x]*Sqrt[1 + x] + (2*(1 + x)^(3/2))/Sqrt[1 - x] - 2*ArcSin[x]}
{x*E^ArcTanh[x]/(1 - x)^2, x, 6, -((2*Sqrt[1 + x])/Sqrt[1 - x]) + (1 + x)^(3/2)/(3*(1 - x)^(3/2)) + ArcSin[x]}


{x*E^ArcTanh[x]*(1 + x), x, 10, (-(5/3))*Sqrt[1 - x^2] - x*Sqrt[1 - x^2] - (1/3)*x^2*Sqrt[1 - x^2] + ArcSin[x]}
{x*E^ArcTanh[x]*(1 + x)^2, x, 13, -3*Sqrt[1 - x^2] - (15/8)*x*Sqrt[1 - x^2] - x^2*Sqrt[1 - x^2] - (1/4)*x^3*Sqrt[1 - x^2] + (15*ArcSin[x])/8}

{x*E^ArcTanh[x]/(1 + x), x, 3, -Sqrt[1 - x^2]}
{x*E^ArcTanh[x]/(1 + x)^2, x, 5, Sqrt[1 - x^2]/(1 + x) + ArcSin[x]}


{x*E^ArcTanh[x]*(1 - x)^(1/2), x, 3, (-(4/15))*(1 + x)^(3/2) + (2/5)*x*(1 + x)^(3/2)}
{x*E^ArcTanh[x]*(1 - x)^(3/2), x, 4, (-(4/3))*(1 + x)^(3/2) + (6/5)*(1 + x)^(5/2) - (2/7)*(1 + x)^(7/2)}

{x*E^ArcTanh[x]/(1 - x)^(1/2), x, 6, -2*Sqrt[1 + x] - (2/3)*(1 + x)^(3/2) + 2*Sqrt[2]*ArcTanh[Sqrt[1 + x]/Sqrt[2]]}
{x*E^ArcTanh[x]/(1 - x)^(3/2), x, 7, 2*Sqrt[1 + x] + Sqrt[1 + x]/(1 - x) - (5*ArcTanh[Sqrt[1 + x]/Sqrt[2]])/Sqrt[2]}


{x*E^ArcTanh[x]*(1 + x)^(1/2), x, 3, -4*Sqrt[1 - x] + 2*(1 - x)^(3/2) - (2/5)*(1 - x)^(5/2)}
{x*E^ArcTanh[x]*(1 + x)^(3/2), x, 4, -8*Sqrt[1 - x] + (16/3)*(1 - x)^(3/2) - 2*(1 - x)^(5/2) + (2/7)*(1 - x)^(7/2)}

{x*E^ArcTanh[x]/(1 + x)^(1/2), x, 3, -((4*Sqrt[1 - x])/3) - (2/3)*Sqrt[1 - x]*x}
{x*E^ArcTanh[x]/(1 + x)^(3/2), x, 5, -2*Sqrt[1 - x] + Sqrt[2]*ArcTanh[Sqrt[1 - x]/Sqrt[2]]}


{Sin[x]*E^ArcTanh[x]*(1 - x)^(1/2), x, 7, (-Sqrt[1 + x])*Cos[x] + Sqrt[Pi/2]*Cos[1]*FresnelC[Sqrt[2/Pi]*Sqrt[1 + x]] + Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[1 + x]]*Sin[1]}
{Sin[x]*E^ArcTanh[x]*(1 - x)^(3/2), x, 15, -2*Sqrt[1 + x]*Cos[x] + (1 + x)^(3/2)*Cos[x] + (1/2)*Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[1 + x]]*(4*Cos[1] - 3*Sin[1]) + (1/2)*Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[1 + x]]*(3*Cos[1] + 4*Sin[1]) - (3/2)*Sqrt[1 + x]*Sin[x]}

(* {Sin[x]*E^ArcTanh[x]/(1 - x)^(1/2), x, 0, 0} *)
(* {Sin[x]*E^ArcTanh[x]/(1 - x)^(3/2), x, 0, 0} *)


{Sin[x]*E^ArcTanh[x]*(1 + x)^(1/2), x, 13, Sqrt[1 - x]*Cos[x] + Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[1 - x]]*(4*Cos[1] - Sin[1]) - Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[1 - x]]*(Cos[1] + 4*Sin[1])}
{Sin[x]*E^ArcTanh[x]*(1 + x)^(3/2), x, 19, 4*Sqrt[1 - x]*Cos[x] - (1 - x)^(3/2)*Cos[x] + (1/2)*Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[1 - x]]*(13*Cos[1] - 8*Sin[1]) - (1/2)*Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[1 - x]]*(8*Cos[1] + 13*Sin[1]) - (3/2)*Sqrt[1 - x]*Sin[x]}

{Sin[x]*E^ArcTanh[x]/(1 + x)^(1/2), x, 6, Sqrt[2*Pi]*Cos[1]*FresnelS[Sqrt[2/Pi]*Sqrt[1 - x]] - Sqrt[2*Pi]*FresnelC[Sqrt[2/Pi]*Sqrt[1 - x]]*Sin[1]}
(* {Sin[x]*E^ArcTanh[x]/(1 + x)^(3/2), x, 0, 0} *)


{x*Sin[x]*E^ArcTanh[x]*(1 - x)^(1/2), x, 15, Sqrt[1 + x]*Cos[x] - (1 + x)^(3/2)*Cos[x] - (1/2)*Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[1 + x]]*(2*Cos[1] - 3*Sin[1]) - (1/2)*Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[1 + x]]*(3*Cos[1] + 2*Sin[1]) + (3/2)*Sqrt[1 + x]*Sin[x]}
{x*Sin[x]*E^ArcTanh[x]*(1 - x)^(3/2), x, 22, (-(7/4))*Sqrt[1 + x]*Cos[x] - 3*(1 + x)^(3/2)*Cos[x] + (1 + x)^(5/2)*Cos[x] - (1/4)*Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[1 + x]]*(18*Cos[1] - 7*Sin[1]) + (1/4)*Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[1 + x]]*(7*Cos[1] + 18*Sin[1]) + (9/2)*Sqrt[1 + x]*Sin[x] - (5/2)*(1 + x)^(3/2)*Sin[x]}

(* {x*Sin[x]*E^ArcTanh[x]/(1 - x)^(1/2), x, 0, 0} *)
(* {x*Sin[x]*E^ArcTanh[x]/(1 - x)^(3/2), x, 0, 0} *)


{x*Sin[x]*E^ArcTanh[x]*(1 + x)^(1/2), x, 19, 3*Sqrt[1 - x]*Cos[x] - (1 - x)^(3/2)*Cos[x] + (1/2)*Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[1 - x]]*(5*Cos[1] - 6*Sin[1]) - (1/2)*Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[1 - x]]*(6*Cos[1] + 5*Sin[1]) - (3/2)*Sqrt[1 - x]*Sin[x]}
{x*Sin[x]*E^ArcTanh[x]*(1 + x)^(3/2), x, 26, (17/4)*Sqrt[1 - x]*Cos[x] - 5*(1 - x)^(3/2)*Cos[x] + (1 - x)^(5/2)*Cos[x] + (1/4)*Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[1 - x]]*(2*Cos[1] - 17*Sin[1]) - (1/4)*Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[1 - x]]*(17*Cos[1] + 2*Sin[1]) - (15/2)*Sqrt[1 - x]*Sin[x] + (5/2)*(1 - x)^(3/2)*Sin[x]}

{x*Sin[x]*E^ArcTanh[x]/(1 + x)^(1/2), x, 13, Sqrt[1 - x]*Cos[x] + Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[1 - x]]*(2*Cos[1] - Sin[1]) - Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[1 - x]]*(Cos[1] + 2*Sin[1])}
(* {x*Sin[x]*E^ArcTanh[x]/(1 + x)^(3/2), x, 0, 0} *)


(* ::Subsubsection::Closed:: *)
(*Products of exponentials of inverse tangents and powers of quadratic binomials*)


{E^ArcTanh[x]*(a - a*x^2)^4, x, 7, (35/128)*a^4*x*Sqrt[1 - x^2] + (35/192)*a^4*x*(1 - x^2)^(3/2) + (7/48)*a^4*x*(1 - x^2)^(5/2) + (1/8)*a^4*x*(1 - x^2)^(7/2) - (1/9)*a^4*(1 - x^2)^(9/2) + (35/128)*a^4*ArcSin[x]}
{E^ArcTanh[x]*(a - a*x^2)^3, x, 6, (5/16)*a^3*x*Sqrt[1 - x^2] + (5/24)*a^3*x*(1 - x^2)^(3/2) + (1/6)*a^3*x*(1 - x^2)^(5/2) - (1/7)*a^3*(1 - x^2)^(7/2) + (5/16)*a^3*ArcSin[x]}
{E^ArcTanh[x]*(a - a*x^2)^2, x, 5, (3/8)*a^2*x*Sqrt[1 - x^2] + (1/4)*a^2*x*(1 - x^2)^(3/2) - (1/5)*a^2*(1 - x^2)^(5/2) + (3/8)*a^2*ArcSin[x]}
{E^ArcTanh[x]*(a - a*x^2)^1, x, 4, (1/2)*a*x*Sqrt[1 - x^2] - (1/3)*a*(1 - x^2)^(3/2) + (1/2)*a*ArcSin[x]}
{E^ArcTanh[x]/(a - a*x^2)^1, x, 2, E^ArcTanh[x]/a}
{E^ArcTanh[x]/(a - a*x^2)^2, x, 3, (2*E^ArcTanh[x])/(3*a^2) - E^ArcTanh[x]/(3*a^2*(1 - x^2)) + (2*E^ArcTanh[x]*x)/(3*a^2*(1 - x^2))}
{E^ArcTanh[x]/(a - a*x^2)^3, x, 4, (8*E^ArcTanh[x])/(15*a^3) - E^ArcTanh[x]/(15*a^3*(1 - x^2)^2) + (4*E^ArcTanh[x]*x)/(15*a^3*(1 - x^2)^2) - (4*E^ArcTanh[x])/(15*a^3*(1 - x^2)) + (8*E^ArcTanh[x]*x)/(15*a^3*(1 - x^2))}
{E^ArcTanh[x]/(a - a*x^2)^4, x, 5, (16*E^ArcTanh[x])/(35*a^4) - E^ArcTanh[x]/(35*a^4*(1 - x^2)^3) + (6*E^ArcTanh[x]*x)/(35*a^4*(1 - x^2)^3) - (2*E^ArcTanh[x])/(35*a^4*(1 - x^2)^2) + (8*E^ArcTanh[x]*x)/(35*a^4*(1 - x^2)^2) - (8*E^ArcTanh[x])/(35*a^4*(1 - x^2)) + (16*E^ArcTanh[x]*x)/(35*a^4*(1 - x^2))}


{E^ArcTanh[x]*(1 - x^2)^(7/2), x, 5, x + x^2/2 - x^3 - (3*x^4)/4 + (3*x^5)/5 + x^6/2 - x^7/7 - x^8/8, (1/10)*(1 + x)^5 + (3/28)*(1 - x)^2*(1 + x)^5 + (1/8)*(1 - x)^3*(1 + x)^5 - (1/14)*x*(1 + x)^5}
{E^ArcTanh[x]*(1 - x^2)^(5/2), x, 4, x + x^2/2 - (2*x^3)/3 - x^4/2 + x^5/5 + x^6/6, (1/5)*(1 + x)^4 + (1/6)*(1 - x)^2*(1 + x)^4 - (2/15)*x*(1 + x)^4}
{E^ArcTanh[x]*(1 - x^2)^(3/2), x, 3, x + x^2/2 - x^3/3 - x^4/4, (5/12)*(1 + x)^3 - (1/4)*x*(1 + x)^3}
{E^ArcTanh[x]*(1 - x^2)^(1/2), x, 2, x + x^2/2}
{E^ArcTanh[x]/(1 - x^2)^(1/2), x, 2, -Log[1 - x]}
{E^ArcTanh[x]/(1 - x^2)^(3/2), x, 5, 1/(2*(1 - x)) + ArcTanh[x]/2}
{E^ArcTanh[x]/(1 - x^2)^(5/2), x, 7, 1/(8*(1 - x)^2) + 1/(4*(1 - x)) - 1/(8*(1 + x)) + (3*ArcTanh[x])/8}
{E^ArcTanh[x]/(1 - x^2)^(7/2), x, 9, 1/(24*(1 - x)^3) + 3/(32*(1 - x)^2) + 3/(16*(1 - x)) - 1/(32*(1 + x)^2) - 1/(8*(1 + x)) + (5*ArcTanh[x])/16}


{E^ArcTanh[x]*(a - a*x^2)^(7/2), x, 5, ((28 + 30*(1 - x)^2 + 35*(1 - x)^3 - 20*x)*(1 + x)^5*(a - a*x^2)^(7/2))/(280*(1 - x^2)^(7/2))}
{E^ArcTanh[x]*(a - a*x^2)^(5/2), x, 4, ((6 + 5*(1 - x)^2 - 4*x)*(1 + x)^4*(a - a*x^2)^(5/2))/(30*(1 - x^2)^(5/2))}
{E^ArcTanh[x]*(a - a*x^2)^(3/2), x, 3, ((5 - 3*x)*(1 + x)^3*(a - a*x^2)^(3/2))/(12*(1 - x^2)^(3/2))}
{E^ArcTanh[x]*(a - a*x^2)^(1/2), x, 2, (x*(2 + x)*Sqrt[a - a*x^2])/(2*Sqrt[1 - x^2])}
{E^ArcTanh[x]/(a - a*x^2)^(1/2), x, 2, -((Sqrt[1 - x^2]*Log[1 - x])/Sqrt[a - a*x^2])}
{E^ArcTanh[x]/(a - a*x^2)^(3/2), x, 5, ((1 - x^2)^(3/2)*(1/(1 - x) + ArcTanh[x]))/(2*(a - a*x^2)^(3/2))}
{E^ArcTanh[x]/(a - a*x^2)^(5/2), x, 7, ((1 - x^2)^(5/2)*(1/(1 - x)^2 + 2/(1 - x) - 1/(1 + x) + 3*ArcTanh[x]))/(8*(a - a*x^2)^(5/2))}
{E^ArcTanh[x]/(a - a*x^2)^(7/2), x, 9, ((1 - x^2)^(7/2)*(4/(1 - x)^3 + 9/(1 - x)^2 + 18/(1 - x) - 3/(1 + x)^2 - 12/(1 + x) + 30*ArcTanh[x]))/(96*(a - a*x^2)^(7/2))}


(* ::Subsubsection::Closed:: *)
(*Products of exponentials of inverse tangents and powers of inverse quadratic binomials*)
(**)


{E^ArcTanh[x]*(1 - 1/x^2), x, 5, -Sqrt[1 - x^2] + Sqrt[1 - x^2]/x + ArcSin[x] + ArcTanh[Sqrt[1 - x^2]]}
{E^ArcTanh[x]*(1 - 1/x^2)^2, x, 7, (-(3/2))*Sqrt[1 - x^2] + Sqrt[1 - x^2]/x - (1 - x^2)^(3/2)/(3*x^3) - (1 - x^2)^(3/2)/(2*x^2) + ArcSin[x] + (3/2)*ArcTanh[Sqrt[1 - x^2]]}
{E^ArcTanh[x]*(1 - 1/x^2)^3, x, 9, (-(15/8))*Sqrt[1 - x^2] + Sqrt[1 - x^2]/x - (1 - x^2)^(3/2)/(3*x^3) - (5*(1 - x^2)^(3/2))/(8*x^2) + (1 - x^2)^(5/2)/(5*x^5) + (1 - x^2)^(5/2)/(4*x^4) + ArcSin[x] + (15/8)*ArcTanh[Sqrt[1 - x^2]]}

{E^ArcTanh[x]/(1 - 1/x^2), x, 6, -(x/Sqrt[1 - x^2]) - x^2/Sqrt[1 - x^2] - 2*Sqrt[1 - x^2] + ArcSin[x]}
{E^ArcTanh[x]/(1 - 1/x^2)^2, x, 8, x^3/(3*(1 - x^2)^(3/2)) + x^4/(3*(1 - x^2)^(3/2)) - x/Sqrt[1 - x^2] - (4*x^2)/(3*Sqrt[1 - x^2]) - (8*Sqrt[1 - x^2])/3 + ArcSin[x]}
{E^ArcTanh[x]/(1 - 1/x^2)^3, x, 10, -(x^5/(5*(1 - x^2)^(5/2))) - x^6/(5*(1 - x^2)^(5/2)) + x^3/(3*(1 - x^2)^(3/2)) + (2*x^4)/(5*(1 - x^2)^(3/2)) - x/Sqrt[1 - x^2] - (8*x^2)/(5*Sqrt[1 - x^2]) - (16*Sqrt[1 - x^2])/5 + ArcSin[x]}


{E^ArcTanh[x]*(1 - 1/x^2)^(1/2), x, 4, (Sqrt[1 - 1/x^2]*x*(x + Log[x]))/Sqrt[1 - x^2]}
{E^ArcTanh[x]*(1 - 1/x^2)^(3/2), x, 4, -(((1 - 1/x^2)^(3/2)*x^3*(1/x^2 + 2/x + 2*x + 2*Log[x]))/(2*(1 - x^2)^(3/2)))}
{E^ArcTanh[x]*(1 - 1/x^2)^(5/2), x, 4, -(((1 - 1/x^2)^(5/2)*x^5*(3/x^4 + 4/x^3 - 12/x^2 - 24/x - 12*x - 12*Log[x]))/(12*(1 - x^2)^(5/2)))}

{E^ArcTanh[x]/(1 - 1/x^2)^(1/2), x, 5, -((Sqrt[1 - x^2]*(x + Log[1 - x]))/(Sqrt[1 - 1/x^2]*x))}
{E^ArcTanh[x]/(1 - 1/x^2)^(3/2), x, 7, ((1 - x^2)^(3/2)*(2/(1 - x) + 4*x + 5*Log[1 - x] - Log[1 + x]))/(4*(1 - 1/x^2)^(3/2)*x^3)}
{E^ArcTanh[x]/(1 - 1/x^2)^(5/2), x, 9, ((1 - x^2)^(5/2)*(2/(1 - x)^2 - 16/(1 - x) - 16*x + 2/(1 + x) - 23*Log[1 - x] + 7*Log[1 + x]))/(16*(1 - 1/x^2)^(5/2)*x^5)}


(* ::Subsection::Closed:: *)
(*Miscellaneous integrands involving inverse hyperbolic tangents*)


{ArcTanh[1/x], x, 1, x*ArcCoth[x] + Log[1 - x^2]/2}


{ArcTanh[a + b*x]/((a*d)/b + d*x), x, 6, -(PolyLog[2, -a - b*x]/(2*d)) + PolyLog[2, a + b*x]/(2*d)}


{ArcTanh[a*x^n]/x, x, 3, -(PolyLog[2, (-a)*x^n]/(2*n)) + PolyLog[2, a*x^n]/(2*n)}

{ArcTanh[a*x^5]/x, x, 3, (-(1/10))*PolyLog[2, (-a)*x^5] + (1/10)*PolyLog[2, a*x^5]}


{x^3*ArcTanh[a + b*x^4], x, 2, ((a + b*x^4)*ArcTanh[a + b*x^4])/(4*b) + Log[1 - (a + b*x^4)^2]/(8*b)}

{x^(n-1)*ArcTanh[a + b*x^n], x, 2, ((a + b*x^n)*ArcTanh[a + b*x^n])/(b*n) + Log[1 - (a + b*x^n)^2]/(2*b*n)}
