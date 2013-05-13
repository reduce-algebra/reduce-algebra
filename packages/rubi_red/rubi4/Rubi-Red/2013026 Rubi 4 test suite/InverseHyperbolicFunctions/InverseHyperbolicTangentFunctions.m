(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Inverse Hyperbolic Tangents*)


(* ::Section::Closed:: *)
(*Integrands of the form u ArcTanh[a x]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcTanh[a x]^n*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{x^5*ArcTanh[a*x], x, 3, x/(6*a^5) + x^3/(18*a^3) + x^5/(30*a) - ArcTanh[a*x]/(6*a^6) + (1/6)*x^6*ArcTanh[a*x]}
{x^4*ArcTanh[a*x], x, 4, x^2/(10*a^3) + x^4/(20*a) + (1/5)*x^5*ArcTanh[a*x] + Log[1 - a^2*x^2]/(10*a^5)}
{x^3*ArcTanh[a*x], x, 2, x/(4*a^3) + x^3/(12*a) - ArcTanh[a*x]/(4*a^4) + (1/4)*x^4*ArcTanh[a*x]}
{x^2*ArcTanh[a*x], x, 3, x^2/(6*a) + (1/3)*x^3*ArcTanh[a*x] + Log[1 - a^2*x^2]/(6*a^3)}
{x*ArcTanh[a*x], x, 1, x/(2*a) - ArcTanh[a*x]/(2*a^2) + (1/2)*x^2*ArcTanh[a*x]}
{ArcTanh[a*x], x, 2, x*ArcTanh[a*x] + Log[1 - a^2*x^2]/(2*a)}
{ArcTanh[a*x]/x, x, 3, (-(1/2))*PolyLog[2, (-a)*x] + (1/2)*PolyLog[2, a*x]}
{ArcTanh[a*x]/x^2, x, 1, -(ArcTanh[a*x]/x) - a*ArcTanh[1 - 2*a^2*x^2]}
{ArcTanh[a*x]/x^3, x, 1, -(a/(2*x)) + (1/2)*a^2*ArcTanh[a*x] - ArcTanh[a*x]/(2*x^2)}
{ArcTanh[a*x]/x^4, x, 2, -(a/(6*x^2)) - ArcTanh[a*x]/(3*x^3) - (1/3)*a^3*ArcTanh[1 - 2*a^2*x^2]}
{ArcTanh[a*x]/x^5, x, 2, -(a/(12*x^3)) - a^3/(4*x) + (1/4)*a^4*ArcTanh[a*x] - ArcTanh[a*x]/(4*x^4)}


{x^5*ArcTanh[a*x]^2, x, 14, (4*x^2)/(45*a^4) + x^4/(60*a^2) + (x*ArcTanh[a*x])/(3*a^5) + (x^3*ArcTanh[a*x])/(9*a^3) + (x^5*ArcTanh[a*x])/(15*a) - ArcTanh[a*x]^2/(6*a^6) + (1/6)*x^6*ArcTanh[a*x]^2 + (23*Log[1 - a^2*x^2])/(90*a^6)}
{x^4*ArcTanh[a*x]^2, x, 9, (3*x)/(10*a^4) + x^3/(30*a^2) - (3*ArcTanh[a*x])/(10*a^5) + (x^2*ArcTanh[a*x])/(5*a^3) + (x^4*ArcTanh[a*x])/(10*a) + ArcTanh[a*x]^2/(5*a^5) + (1/5)*x^5*ArcTanh[a*x]^2 - (2*ArcTanh[a*x]*Log[2/(1 - a*x)])/(5*a^5) - PolyLog[2, -((1 + a*x)/(1 - a*x))]/(5*a^5)}
{x^3*ArcTanh[a*x]^2, x, 9, x^2/(12*a^2) + (x*ArcTanh[a*x])/(2*a^3) + (x^3*ArcTanh[a*x])/(6*a) - ArcTanh[a*x]^2/(4*a^4) + (1/4)*x^4*ArcTanh[a*x]^2 + Log[1 - a^2*x^2]/(3*a^4)}
{x^2*ArcTanh[a*x]^2, x, 6, x/(3*a^2) - ArcTanh[a*x]/(3*a^3) + (x^2*ArcTanh[a*x])/(3*a) + ArcTanh[a*x]^2/(3*a^3) + (1/3)*x^3*ArcTanh[a*x]^2 - (2*ArcTanh[a*x]*Log[2/(1 - a*x)])/(3*a^3) - PolyLog[2, -((1 + a*x)/(1 - a*x))]/(3*a^3)}
{x*ArcTanh[a*x]^2, x, 5, (x*ArcTanh[a*x])/a - ArcTanh[a*x]^2/(2*a^2) + (1/2)*x^2*ArcTanh[a*x]^2 + Log[1 - a^2*x^2]/(2*a^2)}
{ArcTanh[a*x]^2, x, 4, ArcTanh[a*x]^2/a + x*ArcTanh[a*x]^2 - (2*ArcTanh[a*x]*Log[2/(1 - a*x)])/a - PolyLog[2, -((1 + a*x)/(1 - a*x))]/a}
{ArcTanh[a*x]^2/x, x, 7, 2*ArcTanh[a*x]^2*ArcTanh[1 - 2/(1 - a*x)] - ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)] + ArcTanh[a*x]*PolyLog[2, 1 + (2*a*x)/(1 - a*x)] + (1/2)*PolyLog[3, 1 - 2/(1 - a*x)] - (1/2)*PolyLog[3, 1 + (2*a*x)/(1 - a*x)]}
{ArcTanh[a*x]^2/x^2, x, 4, a*ArcTanh[a*x]^2 - ArcTanh[a*x]^2/x + 2*a*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)] - a*PolyLog[2, 1 - (2*a*x)/(1 + a*x)]}
{ArcTanh[a*x]^2/x^3, x, 4, -((a*ArcTanh[a*x])/x) + (1/2)*a^2*ArcTanh[a*x]^2 - ArcTanh[a*x]^2/(2*x^2) - a^2*ArcTanh[1 - 2*a^2*x^2]}
{ArcTanh[a*x]^2/x^4, x, 6, -(a^2/(3*x)) + (1/3)*a^3*ArcTanh[a*x] - (a*ArcTanh[a*x])/(3*x^2) + (1/3)*a^3*ArcTanh[a*x]^2 - ArcTanh[a*x]^2/(3*x^3) + (2/3)*a^3*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)] - (1/3)*a^3*PolyLog[2, 1 - (2*a*x)/(1 + a*x)]}
{ArcTanh[a*x]^2/x^5, x, 7, -(a^2/(12*x^2)) - (a*ArcTanh[a*x])/(6*x^3) - (a^3*ArcTanh[a*x])/(2*x) + (1/4)*a^4*ArcTanh[a*x]^2 - ArcTanh[a*x]^2/(4*x^4) - (2/3)*a^4*ArcTanh[1 - 2*a^2*x^2]}


{x^5*ArcTanh[a*x]^3, x, 24, (19*x)/(60*a^5) + x^3/(60*a^3) - (19*ArcTanh[a*x])/(60*a^6) + (4*x^2*ArcTanh[a*x])/(15*a^4) + (x^4*ArcTanh[a*x])/(20*a^2) + (23*ArcTanh[a*x]^2)/(30*a^6) + (x*ArcTanh[a*x]^2)/(2*a^5) + (x^3*ArcTanh[a*x]^2)/(6*a^3) + (x^5*ArcTanh[a*x]^2)/(10*a) - ArcTanh[a*x]^3/(6*a^6) + (1/6)*x^6*ArcTanh[a*x]^3 - (23*ArcTanh[a*x]*Log[2/(1 - a*x)])/(15*a^6) - (23*PolyLog[2, -((1 + a*x)/(1 - a*x))])/(30*a^6)}
{x^4*ArcTanh[a*x]^3, x, 21, x^2/(20*a^3) + (9*x*ArcTanh[a*x])/(10*a^4) + (x^3*ArcTanh[a*x])/(10*a^2) - (9*ArcTanh[a*x]^2)/(20*a^5) + (3*x^2*ArcTanh[a*x]^2)/(10*a^3) + (3*x^4*ArcTanh[a*x]^2)/(20*a) + ArcTanh[a*x]^3/(5*a^5) + (1/5)*x^5*ArcTanh[a*x]^3 - (3*ArcTanh[a*x]^2*Log[2/(1 - a*x)])/(5*a^5) + Log[1 - a^2*x^2]/(2*a^5) - (3*ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/(5*a^5) + (3*PolyLog[3, 1 - 2/(1 - a*x)])/(10*a^5)}
{x^3*ArcTanh[a*x]^3, x, 14, x/(4*a^3) - ArcTanh[a*x]/(4*a^4) + (x^2*ArcTanh[a*x])/(4*a^2) + ArcTanh[a*x]^2/a^4 + (3*x*ArcTanh[a*x]^2)/(4*a^3) + (x^3*ArcTanh[a*x]^2)/(4*a) - ArcTanh[a*x]^3/(4*a^4) + (1/4)*x^4*ArcTanh[a*x]^3 - (2*ArcTanh[a*x]*Log[2/(1 - a*x)])/a^4 - PolyLog[2, -((1 + a*x)/(1 - a*x))]/a^4}
{x^2*ArcTanh[a*x]^3, x, 11, (x*ArcTanh[a*x])/a^2 - ArcTanh[a*x]^2/(2*a^3) + (x^2*ArcTanh[a*x]^2)/(2*a) + ArcTanh[a*x]^3/(3*a^3) + (1/3)*x^3*ArcTanh[a*x]^3 - (ArcTanh[a*x]^2*Log[2/(1 - a*x)])/a^3 + Log[1 - a^2*x^2]/(2*a^3) - (ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/a^3 + PolyLog[3, 1 - 2/(1 - a*x)]/(2*a^3)}
{x*ArcTanh[a*x]^3, x, 7, (3*ArcTanh[a*x]^2)/(2*a^2) + (3*x*ArcTanh[a*x]^2)/(2*a) - ArcTanh[a*x]^3/(2*a^2) + (1/2)*x^2*ArcTanh[a*x]^3 - (3*ArcTanh[a*x]*Log[2/(1 - a*x)])/a^2 - (3*PolyLog[2, -((1 + a*x)/(1 - a*x))])/(2*a^2)}
{ArcTanh[a*x]^3, x, 5, ArcTanh[a*x]^3/a + x*ArcTanh[a*x]^3 - (3*ArcTanh[a*x]^2*Log[2/(1 - a*x)])/a - (3*ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/a + (3*PolyLog[3, 1 - 2/(1 - a*x)])/(2*a)}
{ArcTanh[a*x]^3/x, x, 9, 2*ArcTanh[a*x]^3*ArcTanh[1 - 2/(1 - a*x)] - (3/2)*ArcTanh[a*x]^2*PolyLog[2, 1 - 2/(1 - a*x)] + (3/2)*ArcTanh[a*x]^2*PolyLog[2, 1 + (2*a*x)/(1 - a*x)] + (3/2)*ArcTanh[a*x]*PolyLog[3, 1 - 2/(1 - a*x)] - (3/2)*ArcTanh[a*x]*PolyLog[3, 1 + (2*a*x)/(1 - a*x)] - (3/4)*PolyLog[4, 1 - 2/(1 - a*x)] + (3/4)*PolyLog[4, 1 + (2*a*x)/(1 - a*x)]}
{ArcTanh[a*x]^3/x^2, x, 5, a*ArcTanh[a*x]^3 - ArcTanh[a*x]^3/x + 3*a*ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)] - 3*a*ArcTanh[a*x]*PolyLog[2, 1 - (2*a*x)/(1 + a*x)] - (3/2)*a*PolyLog[3, 1 - (2*a*x)/(1 + a*x)]}
{ArcTanh[a*x]^3/x^3, x, 7, (3/2)*a^2*ArcTanh[a*x]^2 - (3*a*ArcTanh[a*x]^2)/(2*x) + (1/2)*a^2*ArcTanh[a*x]^3 - ArcTanh[a*x]^3/(2*x^2) + 3*a^2*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)] - (3/2)*a^2*PolyLog[2, 1 - (2*a*x)/(1 + a*x)]}
{ArcTanh[a*x]^3/x^4, x, 10, -((a^2*ArcTanh[a*x])/x) + (1/2)*a^3*ArcTanh[a*x]^2 - (a*ArcTanh[a*x]^2)/(2*x^2) + (1/3)*a^3*ArcTanh[a*x]^3 - ArcTanh[a*x]^3/(3*x^3) - a^3*ArcTanh[1 - 2*a^2*x^2] + a^3*ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)] - a^3*ArcTanh[a*x]*PolyLog[2, 1 - (2*a*x)/(1 + a*x)] - (1/2)*a^3*PolyLog[3, 1 - (2*a*x)/(1 + a*x)]}
{ArcTanh[a*x]^3/x^5, x, 14, -(a^3/(4*x)) + (1/4)*a^4*ArcTanh[a*x] - (a^2*ArcTanh[a*x])/(4*x^2) + a^4*ArcTanh[a*x]^2 - (a*ArcTanh[a*x]^2)/(4*x^3) - (3*a^3*ArcTanh[a*x]^2)/(4*x) + (1/4)*a^4*ArcTanh[a*x]^3 - ArcTanh[a*x]^3/(4*x^4) + 2*a^4*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)] - a^4*PolyLog[2, 1 - (2*a*x)/(1 + a*x)]}


(* ::Subsubsection:: *)
(*n<0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcTanh[a x]^n / (c+d x)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{(x^3*ArcTanh[a*x])/(c + a*c*x), x, 11, -x/(2*a^3*c) + x^2/(6*a^2*c) + ArcTanh[a*x]/(2*a^4*c) + (x*ArcTanh[a*x])/(a^3*c) - (x^2*ArcTanh[a*x])/(2*a^2*c) + (x^3*ArcTanh[a*x])/(3*a*c) + (ArcTanh[a*x]*Log[2/(1 + a*x)])/(a^4*c) + (2*Log[1 - a^2*x^2])/(3*a^4*c) - PolyLog[2, -((1 - a*x)/(1 + a*x))]/(2*a^4*c)}
{(x^2*ArcTanh[a*x])/(c + a*c*x), x, 7, x/(2*a^2*c) - ArcTanh[a*x]/(2*a^3*c) - (x*ArcTanh[a*x])/(a^2*c) + (x^2*ArcTanh[a*x])/(2*a*c) - (ArcTanh[a*x]*Log[2/(1 + a*x)])/(a^3*c) - Log[1 - a^2*x^2]/(2*a^3*c) + PolyLog[2, -((1 - a*x)/(1 + a*x))]/(2*a^3*c)}
{(x*ArcTanh[a*x])/(c + a*c*x), x, 5, (x*ArcTanh[a*x])/(a*c) + (ArcTanh[a*x]*Log[2/(1 + a*x)])/(a^2*c) + Log[1 - a^2*x^2]/(2*a^2*c) - PolyLog[2, -((1 - a*x)/(1 + a*x))]/(2*a^2*c)}
{ArcTanh[a*x]/(c + a*c*x), x, 2, -((ArcTanh[a*x]*Log[2/(1 + a*x)])/(a*c)) + PolyLog[2, -((1 - a*x)/(1 + a*x))]/(2*a*c)}
{ArcTanh[a*x]/(x*(c + a*c*x)), x, 2, (ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)])/c - PolyLog[2, (1 - a*x)/(1 + a*x)]/(2*c)}
{ArcTanh[a*x]/(c*x + a*c*x^2), x, 3, (ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)])/c - PolyLog[2, (1 - a*x)/(1 + a*x)]/(2*c)}
{ArcTanh[a*x]/(x^2*(c + a*c*x)), x, 4, -(ArcTanh[a*x]/(c*x)) - (a*ArcTanh[1 - 2*a^2*x^2])/c - (a*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)])/c + (a*PolyLog[2, (1 - a*x)/(1 + a*x)])/(2*c)}
{ArcTanh[a*x]/(x^3*(c + a*c*x)), x, 6, -(a/(2*c*x)) + (a^2*ArcTanh[a*x])/(2*c) - ArcTanh[a*x]/(2*c*x^2) + (a*ArcTanh[a*x])/(c*x) + (a^2*ArcTanh[1 - 2*a^2*x^2])/c + (a^2*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)])/c - (a^2*PolyLog[2, (1 - a*x)/(1 + a*x)])/(2*c)}

{(x^3*ArcTanh[a*x])/(c - a*c*x), x, 11, -x/(2*a^3*c) - x^2/(6*a^2*c) + ArcTanh[a*x]/(2*a^4*c) - (x*ArcTanh[a*x])/(a^3*c) - (x^2*ArcTanh[a*x])/(2*a^2*c) - (x^3*ArcTanh[a*x])/(3*a*c) + (ArcTanh[a*x]*Log[2/(1 - a*x)])/(a^4*c) - (2*Log[1 - a^2*x^2])/(3*a^4*c) + PolyLog[2, -((1 + a*x)/(1 - a*x))]/(2*a^4*c)}
{(x^2*ArcTanh[a*x])/(c - a*c*x), x, 7, -x/(2*a^2*c) + ArcTanh[a*x]/(2*a^3*c) - (x*ArcTanh[a*x])/(a^2*c) - (x^2*ArcTanh[a*x])/(2*a*c) + (ArcTanh[a*x]*Log[2/(1 - a*x)])/(a^3*c) - Log[1 - a^2*x^2]/(2*a^3*c) + PolyLog[2, -((1 + a*x)/(1 - a*x))]/(2*a^3*c)}
{(x*ArcTanh[a*x])/(c - a*c*x), x, 5, -((x*ArcTanh[a*x])/(a*c)) + (ArcTanh[a*x]*Log[2/(1 - a*x)])/(a^2*c) - Log[1 - a^2*x^2]/(2*a^2*c) + PolyLog[2, -((1 + a*x)/(1 - a*x))]/(2*a^2*c)}
{ArcTanh[a*x]/(c - a*c*x), x, 2, (ArcTanh[a*x]*Log[2/(1 - a*x)])/(a*c) + PolyLog[2, -((1 + a*x)/(1 - a*x))]/(2*a*c)}
{ArcTanh[a*x]/(x*(c - a*c*x)), x, 2, (ArcTanh[a*x]*Log[-((2*a*x)/(1 - a*x))])/c + PolyLog[2, (1 + a*x)/(1 - a*x)]/(2*c)}
{ArcTanh[a*x]/(c*x - a*c*x^2), x, 3, (ArcTanh[a*x]*Log[-((2*a*x)/(1 - a*x))])/c + PolyLog[2, (1 + a*x)/(1 - a*x)]/(2*c)}
{ArcTanh[a*x]/(x^2*(c - a*c*x)), x, 4, -(ArcTanh[a*x]/(c*x)) - (a*ArcTanh[1 - 2*a^2*x^2])/c + (a*ArcTanh[a*x]*Log[-((2*a*x)/(1 - a*x))])/c + (a*PolyLog[2, (1 + a*x)/(1 - a*x)])/(2*c)}
{ArcTanh[a*x]/(x^3*(c - a*c*x)), x, 6, -(a/(2*c*x)) + (a^2*ArcTanh[a*x])/(2*c) - ArcTanh[a*x]/(2*c*x^2) - (a*ArcTanh[a*x])/(c*x) - (a^2*ArcTanh[1 - 2*a^2*x^2])/c + (a^2*ArcTanh[a*x]*Log[-((2*a*x)/(1 - a*x))])/c + (a^2*PolyLog[2, (1 + a*x)/(1 - a*x)])/(2*c)}


{(x^3*ArcTanh[a*x]^2)/(c + a*c*x), x, 21, x/(3*a^3*c) - ArcTanh[a*x]/(3*a^4*c) - (x*ArcTanh[a*x])/(a^3*c) + (x^2*ArcTanh[a*x])/(3*a^2*c) + (11*ArcTanh[a*x]^2)/(6*a^4*c) + (x*ArcTanh[a*x]^2)/(a^3*c) - (x^2*ArcTanh[a*x]^2)/(2*a^2*c) + (x^3*ArcTanh[a*x]^2)/(3*a*c) - (8*ArcTanh[a*x]*Log[2/(1 - a*x)])/(3*a^4*c) + (ArcTanh[a*x]^2*Log[2/(1 + a*x)])/(a^4*c) - Log[1 - a^2*x^2]/(2*a^4*c) - (4*PolyLog[2, -((1 + a*x)/(1 - a*x))])/(3*a^4*c) - (ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 + a*x)])/(a^4*c) - PolyLog[3, 1 - 2/(1 + a*x)]/(2*a^4*c)}
{(x^2*ArcTanh[a*x]^2)/(c + a*c*x), x, 14, (x*ArcTanh[a*x])/(a^2*c) - (3*ArcTanh[a*x]^2)/(2*a^3*c) - (x*ArcTanh[a*x]^2)/(a^2*c) + (x^2*ArcTanh[a*x]^2)/(2*a*c) + (2*ArcTanh[a*x]*Log[2/(1 - a*x)])/(a^3*c) - (ArcTanh[a*x]^2*Log[2/(1 + a*x)])/(a^3*c) + Log[1 - a^2*x^2]/(2*a^3*c) + PolyLog[2, -((1 + a*x)/(1 - a*x))]/(a^3*c) + (ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 + a*x)])/(a^3*c) + PolyLog[3, 1 - 2/(1 + a*x)]/(2*a^3*c)}
{(x*ArcTanh[a*x]^2)/(c + a*c*x), x, 8, ArcTanh[a*x]^2/(a^2*c) + (x*ArcTanh[a*x]^2)/(a*c) - (2*ArcTanh[a*x]*Log[2/(1 - a*x)])/(a^2*c) + (ArcTanh[a*x]^2*Log[2/(1 + a*x)])/(a^2*c) - PolyLog[2, -((1 + a*x)/(1 - a*x))]/(a^2*c) - (ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 + a*x)])/(a^2*c) - PolyLog[3, 1 - 2/(1 + a*x)]/(2*a^2*c)}
{ArcTanh[a*x]^2/(c + a*c*x), x, 3, -((ArcTanh[a*x]^2*Log[2/(1 + a*x)])/(a*c)) + (ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 + a*x)])/(a*c) + PolyLog[3, 1 - 2/(1 + a*x)]/(2*a*c)}
{ArcTanh[a*x]^2/(x*(c + a*c*x)), x, 3, (ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)])/c - (ArcTanh[a*x]*PolyLog[2, 1 - (2*a*x)/(1 + a*x)])/c - PolyLog[3, 1 - (2*a*x)/(1 + a*x)]/(2*c)}
{ArcTanh[a*x]^2/(c*x + a*c*x^2), x, 4, (ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)])/c - (ArcTanh[a*x]*PolyLog[2, 1 - (2*a*x)/(1 + a*x)])/c - PolyLog[3, 1 - (2*a*x)/(1 + a*x)]/(2*c)}
{ArcTanh[a*x]^2/(x^2*(c + a*c*x)), x, 8, (a*ArcTanh[a*x]^2)/c - ArcTanh[a*x]^2/(c*x) + (2*a*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)])/c - (a*ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)])/c - (a*PolyLog[2, 1 - (2*a*x)/(1 + a*x)])/c + (a*ArcTanh[a*x]*PolyLog[2, 1 - (2*a*x)/(1 + a*x)])/c + (a*PolyLog[3, 1 - (2*a*x)/(1 + a*x)])/(2*c)}
{ArcTanh[a*x]^2/(x^3*(c + a*c*x)), x, 13, -((a*ArcTanh[a*x])/(c*x)) - (a^2*ArcTanh[a*x]^2)/(2*c) - ArcTanh[a*x]^2/(2*c*x^2) + (a*ArcTanh[a*x]^2)/(c*x) - (a^2*ArcTanh[1 - 2*a^2*x^2])/c - (2*a^2*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)])/c + (a^2*ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)])/c + (a^2*PolyLog[2, 1 - (2*a*x)/(1 + a*x)])/c - (a^2*ArcTanh[a*x]*PolyLog[2, 1 - (2*a*x)/(1 + a*x)])/c - (a^2*PolyLog[3, 1 - (2*a*x)/(1 + a*x)])/(2*c)}

{(x^3*ArcTanh[a*x]^2)/(c - a*c*x), x, 21, -x/(3*a^3*c) + ArcTanh[a*x]/(3*a^4*c) - (x*ArcTanh[a*x])/(a^3*c) - (x^2*ArcTanh[a*x])/(3*a^2*c) - (5*ArcTanh[a*x]^2)/(6*a^4*c) - (x*ArcTanh[a*x]^2)/(a^3*c) - (x^2*ArcTanh[a*x]^2)/(2*a^2*c) - (x^3*ArcTanh[a*x]^2)/(3*a*c) + (8*ArcTanh[a*x]*Log[2/(1 - a*x)])/(3*a^4*c) + (ArcTanh[a*x]^2*Log[2/(1 - a*x)])/(a^4*c) - Log[1 - a^2*x^2]/(2*a^4*c) + (4*PolyLog[2, -((1 + a*x)/(1 - a*x))])/(3*a^4*c) + (ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/(a^4*c) - PolyLog[3, 1 - 2/(1 - a*x)]/(2*a^4*c)}
{(x^2*ArcTanh[a*x]^2)/(c - a*c*x), x, 14, -((x*ArcTanh[a*x])/(a^2*c)) - ArcTanh[a*x]^2/(2*a^3*c) - (x*ArcTanh[a*x]^2)/(a^2*c) - (x^2*ArcTanh[a*x]^2)/(2*a*c) + (2*ArcTanh[a*x]*Log[2/(1 - a*x)])/(a^3*c) + (ArcTanh[a*x]^2*Log[2/(1 - a*x)])/(a^3*c) - Log[1 - a^2*x^2]/(2*a^3*c) + PolyLog[2, -((1 + a*x)/(1 - a*x))]/(a^3*c) + (ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/(a^3*c) - PolyLog[3, 1 - 2/(1 - a*x)]/(2*a^3*c)}
{(x*ArcTanh[a*x]^2)/(c - a*c*x), x, 8, -(ArcTanh[a*x]^2/(a^2*c)) - (x*ArcTanh[a*x]^2)/(a*c) + (2*ArcTanh[a*x]*Log[2/(1 - a*x)])/(a^2*c) + (ArcTanh[a*x]^2*Log[2/(1 - a*x)])/(a^2*c) + PolyLog[2, -((1 + a*x)/(1 - a*x))]/(a^2*c) + (ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/(a^2*c) - PolyLog[3, 1 - 2/(1 - a*x)]/(2*a^2*c)}
{ArcTanh[a*x]^2/(c - a*c*x), x, 3, (ArcTanh[a*x]^2*Log[2/(1 - a*x)])/(a*c) + (ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/(a*c) - PolyLog[3, 1 - 2/(1 - a*x)]/(2*a*c)}
{ArcTanh[a*x]^2/(x*(c - a*c*x)), x, 3, (ArcTanh[a*x]^2*Log[-((2*a*x)/(1 - a*x))])/c + (ArcTanh[a*x]*PolyLog[2, 1 + (2*a*x)/(1 - a*x)])/c - PolyLog[3, 1 + (2*a*x)/(1 - a*x)]/(2*c)}
{ArcTanh[a*x]^2/(c*x - a*c*x^2), x, 4, (ArcTanh[a*x]^2*Log[-((2*a*x)/(1 - a*x))])/c + (ArcTanh[a*x]*PolyLog[2, 1 + (2*a*x)/(1 - a*x)])/c - PolyLog[3, 1 + (2*a*x)/(1 - a*x)]/(2*c)}
{ArcTanh[a*x]^2/(x^2*(c - a*c*x)), x, 8, (a*ArcTanh[a*x]^2)/c - ArcTanh[a*x]^2/(c*x) + (a*ArcTanh[a*x]^2*Log[-((2*a*x)/(1 - a*x))])/c + (2*a*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)])/c + (a*ArcTanh[a*x]*PolyLog[2, 1 + (2*a*x)/(1 - a*x)])/c - (a*PolyLog[2, 1 - (2*a*x)/(1 + a*x)])/c - (a*PolyLog[3, 1 + (2*a*x)/(1 - a*x)])/(2*c)}
{ArcTanh[a*x]^2/(x^3*(c - a*c*x)), x, 13, -((a*ArcTanh[a*x])/(c*x)) + (3*a^2*ArcTanh[a*x]^2)/(2*c) - ArcTanh[a*x]^2/(2*c*x^2) - (a*ArcTanh[a*x]^2)/(c*x) - (a^2*ArcTanh[1 - 2*a^2*x^2])/c + (a^2*ArcTanh[a*x]^2*Log[-((2*a*x)/(1 - a*x))])/c + (2*a^2*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)])/c + (a^2*ArcTanh[a*x]*PolyLog[2, 1 + (2*a*x)/(1 - a*x)])/c - (a^2*PolyLog[2, 1 - (2*a*x)/(1 + a*x)])/c - (a^2*PolyLog[3, 1 + (2*a*x)/(1 - a*x)])/(2*c)}


{(x^2*ArcTanh[a*x]^3)/(c + a*c*x), x, 18, (3*ArcTanh[a*x]^2)/(2*a^3*c) + (3*x*ArcTanh[a*x]^2)/(2*a^2*c) - (3*ArcTanh[a*x]^3)/(2*a^3*c) - (x*ArcTanh[a*x]^3)/(a^2*c) + (x^2*ArcTanh[a*x]^3)/(2*a*c) - (3*ArcTanh[a*x]*Log[2/(1 - a*x)])/(a^3*c) + (3*ArcTanh[a*x]^2*Log[2/(1 - a*x)])/(a^3*c) - (ArcTanh[a*x]^3*Log[2/(1 + a*x)])/(a^3*c) - (3*PolyLog[2, -((1 + a*x)/(1 - a*x))])/(2*a^3*c) + (3*ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/(a^3*c) + (3*ArcTanh[a*x]^2*PolyLog[2, 1 - 2/(1 + a*x)])/(2*a^3*c) - (3*PolyLog[3, 1 - 2/(1 - a*x)])/(2*a^3*c) + (3*ArcTanh[a*x]*PolyLog[3, 1 - 2/(1 + a*x)])/(2*a^3*c) + (3*PolyLog[4, 1 - 2/(1 + a*x)])/(4*a^3*c)}
{(x*ArcTanh[a*x]^3)/(c + a*c*x), x, 10, ArcTanh[a*x]^3/(a^2*c) + (x*ArcTanh[a*x]^3)/(a*c) - (3*ArcTanh[a*x]^2*Log[2/(1 - a*x)])/(a^2*c) + (ArcTanh[a*x]^3*Log[2/(1 + a*x)])/(a^2*c) - (3*ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/(a^2*c) - (3*ArcTanh[a*x]^2*PolyLog[2, 1 - 2/(1 + a*x)])/(2*a^2*c) + (3*PolyLog[3, 1 - 2/(1 - a*x)])/(2*a^2*c) - (3*ArcTanh[a*x]*PolyLog[3, 1 - 2/(1 + a*x)])/(2*a^2*c) - (3*PolyLog[4, 1 - 2/(1 + a*x)])/(4*a^2*c)}
{ArcTanh[a*x]^3/(c + a*c*x), x, 4, -((ArcTanh[a*x]^3*Log[2/(1 + a*x)])/(a*c)) + (3*ArcTanh[a*x]^2*PolyLog[2, 1 - 2/(1 + a*x)])/(2*a*c) + (3*ArcTanh[a*x]*PolyLog[3, 1 - 2/(1 + a*x)])/(2*a*c) + (3*PolyLog[4, 1 - 2/(1 + a*x)])/(4*a*c)}
{ArcTanh[a*x]^3/(x*(c + a*c*x)), x, 4, (ArcTanh[a*x]^3*Log[(2*a*x)/(1 + a*x)])/c - (3*ArcTanh[a*x]^2*PolyLog[2, 1 - (2*a*x)/(1 + a*x)])/(2*c) - (3*ArcTanh[a*x]*PolyLog[3, 1 - (2*a*x)/(1 + a*x)])/(2*c) - (3*PolyLog[4, 1 - (2*a*x)/(1 + a*x)])/(4*c)}
{ArcTanh[a*x]^3/(c*x + a*c*x^2), x, 5, (ArcTanh[a*x]^3*Log[(2*a*x)/(1 + a*x)])/c - (3*ArcTanh[a*x]^2*PolyLog[2, 1 - (2*a*x)/(1 + a*x)])/(2*c) - (3*ArcTanh[a*x]*PolyLog[3, 1 - (2*a*x)/(1 + a*x)])/(2*c) - (3*PolyLog[4, 1 - (2*a*x)/(1 + a*x)])/(4*c)}
{ArcTanh[a*x]^3/(x^2*(c + a*c*x)), x, 10, (a*ArcTanh[a*x]^3)/c - ArcTanh[a*x]^3/(c*x) + (3*a*ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)])/c - (a*ArcTanh[a*x]^3*Log[(2*a*x)/(1 + a*x)])/c - (3*a*ArcTanh[a*x]*PolyLog[2, 1 - (2*a*x)/(1 + a*x)])/c + (3*a*ArcTanh[a*x]^2*PolyLog[2, 1 - (2*a*x)/(1 + a*x)])/(2*c) - (3*a*PolyLog[3, 1 - (2*a*x)/(1 + a*x)])/(2*c) + (3*a*ArcTanh[a*x]*PolyLog[3, 1 - (2*a*x)/(1 + a*x)])/(2*c) + (3*a*PolyLog[4, 1 - (2*a*x)/(1 + a*x)])/(4*c)}
{ArcTanh[a*x]^3/(x^3*(c + a*c*x)), x, 18, (3*a^2*ArcTanh[a*x]^2)/(2*c) - (3*a*ArcTanh[a*x]^2)/(2*c*x) - (a^2*ArcTanh[a*x]^3)/(2*c) - ArcTanh[a*x]^3/(2*c*x^2) + (a*ArcTanh[a*x]^3)/(c*x) + (3*a^2*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)])/c - (3*a^2*ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)])/c + (a^2*ArcTanh[a*x]^3*Log[(2*a*x)/(1 + a*x)])/c - (3*a^2*PolyLog[2, 1 - (2*a*x)/(1 + a*x)])/(2*c) + (3*a^2*ArcTanh[a*x]*PolyLog[2, 1 - (2*a*x)/(1 + a*x)])/c - (3*a^2*ArcTanh[a*x]^2*PolyLog[2, 1 - (2*a*x)/(1 + a*x)])/(2*c) + (3*a^2*PolyLog[3, 1 - (2*a*x)/(1 + a*x)])/(2*c) - (3*a^2*ArcTanh[a*x]*PolyLog[3, 1 - (2*a*x)/(1 + a*x)])/(2*c) - (3*a^2*PolyLog[4, 1 - (2*a*x)/(1 + a*x)])/(4*c)}

{(x^2*ArcTanh[a*x]^3)/(c - a*c*x), x, 18, (-3*ArcTanh[a*x]^2)/(2*a^3*c) - (3*x*ArcTanh[a*x]^2)/(2*a^2*c) - ArcTanh[a*x]^3/(2*a^3*c) - (x*ArcTanh[a*x]^3)/(a^2*c) - (x^2*ArcTanh[a*x]^3)/(2*a*c) + (3*ArcTanh[a*x]*Log[2/(1 - a*x)])/(a^3*c) + (3*ArcTanh[a*x]^2*Log[2/(1 - a*x)])/(a^3*c) + (ArcTanh[a*x]^3*Log[2/(1 - a*x)])/(a^3*c) + (3*PolyLog[2, -((1 + a*x)/(1 - a*x))])/(2*a^3*c) + (3*ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/(a^3*c) + (3*ArcTanh[a*x]^2*PolyLog[2, 1 - 2/(1 - a*x)])/(2*a^3*c) - (3*PolyLog[3, 1 - 2/(1 - a*x)])/(2*a^3*c) - (3*ArcTanh[a*x]*PolyLog[3, 1 - 2/(1 - a*x)])/(2*a^3*c) + (3*PolyLog[4, 1 - 2/(1 - a*x)])/(4*a^3*c)}
{(x*ArcTanh[a*x]^3)/(c - a*c*x), x, 10, -(ArcTanh[a*x]^3/(a^2*c)) - (x*ArcTanh[a*x]^3)/(a*c) + (3*ArcTanh[a*x]^2*Log[2/(1 - a*x)])/(a^2*c) + (ArcTanh[a*x]^3*Log[2/(1 - a*x)])/(a^2*c) + (3*ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/(a^2*c) + (3*ArcTanh[a*x]^2*PolyLog[2, 1 - 2/(1 - a*x)])/(2*a^2*c) - (3*PolyLog[3, 1 - 2/(1 - a*x)])/(2*a^2*c) - (3*ArcTanh[a*x]*PolyLog[3, 1 - 2/(1 - a*x)])/(2*a^2*c) + (3*PolyLog[4, 1 - 2/(1 - a*x)])/(4*a^2*c)}
{ArcTanh[a*x]^3/(c - a*c*x), x, 4, (ArcTanh[a*x]^3*Log[2/(1 - a*x)])/(a*c) + (3*ArcTanh[a*x]^2*PolyLog[2, 1 - 2/(1 - a*x)])/(2*a*c) - (3*ArcTanh[a*x]*PolyLog[3, 1 - 2/(1 - a*x)])/(2*a*c) + (3*PolyLog[4, 1 - 2/(1 - a*x)])/(4*a*c)}
{ArcTanh[a*x]^3/(x*(c - a*c*x)), x, 4, (ArcTanh[a*x]^3*Log[-((2*a*x)/(1 - a*x))])/c + (3*ArcTanh[a*x]^2*PolyLog[2, 1 + (2*a*x)/(1 - a*x)])/(2*c) - (3*ArcTanh[a*x]*PolyLog[3, 1 + (2*a*x)/(1 - a*x)])/(2*c) + (3*PolyLog[4, 1 + (2*a*x)/(1 - a*x)])/(4*c)}
{ArcTanh[a*x]^3/(c*x - a*c*x^2), x, 5, (ArcTanh[a*x]^3*Log[-((2*a*x)/(1 - a*x))])/c + (3*ArcTanh[a*x]^2*PolyLog[2, 1 + (2*a*x)/(1 - a*x)])/(2*c) - (3*ArcTanh[a*x]*PolyLog[3, 1 + (2*a*x)/(1 - a*x)])/(2*c) + (3*PolyLog[4, 1 + (2*a*x)/(1 - a*x)])/(4*c)}
{ArcTanh[a*x]^3/(x^2*(c - a*c*x)), x, 10, (a*ArcTanh[a*x]^3)/c - ArcTanh[a*x]^3/(c*x) + (a*ArcTanh[a*x]^3*Log[-((2*a*x)/(1 - a*x))])/c + (3*a*ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)])/c + (3*a*ArcTanh[a*x]^2*PolyLog[2, 1 + (2*a*x)/(1 - a*x)])/(2*c) - (3*a*ArcTanh[a*x]*PolyLog[2, 1 - (2*a*x)/(1 + a*x)])/c - (3*a*ArcTanh[a*x]*PolyLog[3, 1 + (2*a*x)/(1 - a*x)])/(2*c) - (3*a*PolyLog[3, 1 - (2*a*x)/(1 + a*x)])/(2*c) + (3*a*PolyLog[4, 1 + (2*a*x)/(1 - a*x)])/(4*c)}
{ArcTanh[a*x]^3/(x^3*(c - a*c*x)), x, 18, (3*a^2*ArcTanh[a*x]^2)/(2*c) - (3*a*ArcTanh[a*x]^2)/(2*c*x) + (3*a^2*ArcTanh[a*x]^3)/(2*c) - ArcTanh[a*x]^3/(2*c*x^2) - (a*ArcTanh[a*x]^3)/(c*x) + (a^2*ArcTanh[a*x]^3*Log[-((2*a*x)/(1 - a*x))])/c + (3*a^2*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)])/c + (3*a^2*ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)])/c + (3*a^2*ArcTanh[a*x]^2*PolyLog[2, 1 + (2*a*x)/(1 - a*x)])/(2*c) - (3*a^2*PolyLog[2, 1 - (2*a*x)/(1 + a*x)])/(2*c) - (3*a^2*ArcTanh[a*x]*PolyLog[2, 1 - (2*a*x)/(1 + a*x)])/c - (3*a^2*ArcTanh[a*x]*PolyLog[3, 1 + (2*a*x)/(1 - a*x)])/(2*c) - (3*a^2*PolyLog[3, 1 - (2*a*x)/(1 + a*x)])/(2*c) + (3*a^2*PolyLog[4, 1 + (2*a*x)/(1 - a*x)])/(4*c)}


{(x^2*ArcTanh[a*x]^4)/(c + a*c*x), x, 21, (2*ArcTanh[a*x]^3)/(a^3*c) + (2*x*ArcTanh[a*x]^3)/(a^2*c) - (3*ArcTanh[a*x]^4)/(2*a^3*c) - (x*ArcTanh[a*x]^4)/(a^2*c) + (x^2*ArcTanh[a*x]^4)/(2*a*c) - (6*ArcTanh[a*x]^2*Log[2/(1 - a*x)])/(a^3*c) + (4*ArcTanh[a*x]^3*Log[2/(1 - a*x)])/(a^3*c) - (ArcTanh[a*x]^4*Log[2/(1 + a*x)])/(a^3*c) - (6*ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/(a^3*c) + (6*ArcTanh[a*x]^2*PolyLog[2, 1 - 2/(1 - a*x)])/(a^3*c) + (2*ArcTanh[a*x]^3*PolyLog[2, 1 - 2/(1 + a*x)])/(a^3*c) + (3*PolyLog[3, 1 - 2/(1 - a*x)])/(a^3*c) - (6*ArcTanh[a*x]*PolyLog[3, 1 - 2/(1 - a*x)])/(a^3*c) + (3*ArcTanh[a*x]^2*PolyLog[3, 1 - 2/(1 + a*x)])/(a^3*c) + (3*PolyLog[4, 1 - 2/(1 - a*x)])/(a^3*c) + (3*ArcTanh[a*x]*PolyLog[4, 1 - 2/(1 + a*x)])/(a^3*c) + (3*PolyLog[5, 1 - 2/(1 + a*x)])/(2*a^3*c)}
{(x*ArcTanh[a*x]^4)/(c + a*c*x), x, 12, ArcTanh[a*x]^4/(a^2*c) + (x*ArcTanh[a*x]^4)/(a*c) - (4*ArcTanh[a*x]^3*Log[2/(1 - a*x)])/(a^2*c) + (ArcTanh[a*x]^4*Log[2/(1 + a*x)])/(a^2*c) - (6*ArcTanh[a*x]^2*PolyLog[2, 1 - 2/(1 - a*x)])/(a^2*c) - (2*ArcTanh[a*x]^3*PolyLog[2, 1 - 2/(1 + a*x)])/(a^2*c) + (6*ArcTanh[a*x]*PolyLog[3, 1 - 2/(1 - a*x)])/(a^2*c) - (3*ArcTanh[a*x]^2*PolyLog[3, 1 - 2/(1 + a*x)])/(a^2*c) - (3*PolyLog[4, 1 - 2/(1 - a*x)])/(a^2*c) - (3*ArcTanh[a*x]*PolyLog[4, 1 - 2/(1 + a*x)])/(a^2*c) - (3*PolyLog[5, 1 - 2/(1 + a*x)])/(2*a^2*c)}
{ArcTanh[a*x]^4/(c + a*c*x), x, 5, -((ArcTanh[a*x]^4*Log[2/(1 + a*x)])/(a*c)) + (2*ArcTanh[a*x]^3*PolyLog[2, 1 - 2/(1 + a*x)])/(a*c) + (3*ArcTanh[a*x]^2*PolyLog[3, 1 - 2/(1 + a*x)])/(a*c) + (3*ArcTanh[a*x]*PolyLog[4, 1 - 2/(1 + a*x)])/(a*c) + (3*PolyLog[5, 1 - 2/(1 + a*x)])/(2*a*c)}
{ArcTanh[a*x]^4/(x*(c + a*c*x)), x, 5, (ArcTanh[a*x]^4*Log[(2*a*x)/(1 + a*x)])/c - (2*ArcTanh[a*x]^3*PolyLog[2, 1 - (2*a*x)/(1 + a*x)])/c - (3*ArcTanh[a*x]^2*PolyLog[3, 1 - (2*a*x)/(1 + a*x)])/c - (3*ArcTanh[a*x]*PolyLog[4, 1 - (2*a*x)/(1 + a*x)])/c - (3*PolyLog[5, 1 - (2*a*x)/(1 + a*x)])/(2*c)}
{ArcTanh[a*x]^4/(c*x + a*c*x^2), x, 6, (ArcTanh[a*x]^4*Log[(2*a*x)/(1 + a*x)])/c - (2*ArcTanh[a*x]^3*PolyLog[2, 1 - (2*a*x)/(1 + a*x)])/c - (3*ArcTanh[a*x]^2*PolyLog[3, 1 - (2*a*x)/(1 + a*x)])/c - (3*ArcTanh[a*x]*PolyLog[4, 1 - (2*a*x)/(1 + a*x)])/c - (3*PolyLog[5, 1 - (2*a*x)/(1 + a*x)])/(2*c)}
{ArcTanh[a*x]^4/(x^2*(c + a*c*x)), x, 12, (a*ArcTanh[a*x]^4)/c - ArcTanh[a*x]^4/(c*x) + (4*a*ArcTanh[a*x]^3*Log[(2*a*x)/(1 + a*x)])/c - (a*ArcTanh[a*x]^4*Log[(2*a*x)/(1 + a*x)])/c - (6*a*ArcTanh[a*x]^2*PolyLog[2, 1 - (2*a*x)/(1 + a*x)])/c + (2*a*ArcTanh[a*x]^3*PolyLog[2, 1 - (2*a*x)/(1 + a*x)])/c - (6*a*ArcTanh[a*x]*PolyLog[3, 1 - (2*a*x)/(1 + a*x)])/c + (3*a*ArcTanh[a*x]^2*PolyLog[3, 1 - (2*a*x)/(1 + a*x)])/c - (3*a*PolyLog[4, 1 - (2*a*x)/(1 + a*x)])/c + (3*a*ArcTanh[a*x]*PolyLog[4, 1 - (2*a*x)/(1 + a*x)])/c + (3*a*PolyLog[5, 1 - (2*a*x)/(1 + a*x)])/(2*c)}
{ArcTanh[a*x]^4/(x^3*(c + a*c*x)), x, 21, (2*a^2*ArcTanh[a*x]^3)/c - (2*a*ArcTanh[a*x]^3)/(c*x) - (a^2*ArcTanh[a*x]^4)/(2*c) - ArcTanh[a*x]^4/(2*c*x^2) + (a*ArcTanh[a*x]^4)/(c*x) + (6*a^2*ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)])/c - (4*a^2*ArcTanh[a*x]^3*Log[(2*a*x)/(1 + a*x)])/c + (a^2*ArcTanh[a*x]^4*Log[(2*a*x)/(1 + a*x)])/c - (6*a^2*ArcTanh[a*x]*PolyLog[2, 1 - (2*a*x)/(1 + a*x)])/c + (6*a^2*ArcTanh[a*x]^2*PolyLog[2, 1 - (2*a*x)/(1 + a*x)])/c - (2*a^2*ArcTanh[a*x]^3*PolyLog[2, 1 - (2*a*x)/(1 + a*x)])/c - (3*a^2*PolyLog[3, 1 - (2*a*x)/(1 + a*x)])/c + (6*a^2*ArcTanh[a*x]*PolyLog[3, 1 - (2*a*x)/(1 + a*x)])/c - (3*a^2*ArcTanh[a*x]^2*PolyLog[3, 1 - (2*a*x)/(1 + a*x)])/c + (3*a^2*PolyLog[4, 1 - (2*a*x)/(1 + a*x)])/c - (3*a^2*ArcTanh[a*x]*PolyLog[4, 1 - (2*a*x)/(1 + a*x)])/c - (3*a^2*PolyLog[5, 1 - (2*a*x)/(1 + a*x)])/(2*c)}

{(x^2*ArcTanh[a*x]^4)/(c - a*c*x), x, 21, (-2*ArcTanh[a*x]^3)/(a^3*c) - (2*x*ArcTanh[a*x]^3)/(a^2*c) - ArcTanh[a*x]^4/(2*a^3*c) - (x*ArcTanh[a*x]^4)/(a^2*c) - (x^2*ArcTanh[a*x]^4)/(2*a*c) + (6*ArcTanh[a*x]^2*Log[2/(1 - a*x)])/(a^3*c) + (4*ArcTanh[a*x]^3*Log[2/(1 - a*x)])/(a^3*c) + (ArcTanh[a*x]^4*Log[2/(1 - a*x)])/(a^3*c) + (6*ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/(a^3*c) + (6*ArcTanh[a*x]^2*PolyLog[2, 1 - 2/(1 - a*x)])/(a^3*c) + (2*ArcTanh[a*x]^3*PolyLog[2, 1 - 2/(1 - a*x)])/(a^3*c) - (3*PolyLog[3, 1 - 2/(1 - a*x)])/(a^3*c) - (6*ArcTanh[a*x]*PolyLog[3, 1 - 2/(1 - a*x)])/(a^3*c) - (3*ArcTanh[a*x]^2*PolyLog[3, 1 - 2/(1 - a*x)])/(a^3*c) + (3*PolyLog[4, 1 - 2/(1 - a*x)])/(a^3*c) + (3*ArcTanh[a*x]*PolyLog[4, 1 - 2/(1 - a*x)])/(a^3*c) - (3*PolyLog[5, 1 - 2/(1 - a*x)])/(2*a^3*c)}
{(x*ArcTanh[a*x]^4)/(c - a*c*x), x, 12, -(ArcTanh[a*x]^4/(a^2*c)) - (x*ArcTanh[a*x]^4)/(a*c) + (4*ArcTanh[a*x]^3*Log[2/(1 - a*x)])/(a^2*c) + (ArcTanh[a*x]^4*Log[2/(1 - a*x)])/(a^2*c) + (6*ArcTanh[a*x]^2*PolyLog[2, 1 - 2/(1 - a*x)])/(a^2*c) + (2*ArcTanh[a*x]^3*PolyLog[2, 1 - 2/(1 - a*x)])/(a^2*c) - (6*ArcTanh[a*x]*PolyLog[3, 1 - 2/(1 - a*x)])/(a^2*c) - (3*ArcTanh[a*x]^2*PolyLog[3, 1 - 2/(1 - a*x)])/(a^2*c) + (3*PolyLog[4, 1 - 2/(1 - a*x)])/(a^2*c) + (3*ArcTanh[a*x]*PolyLog[4, 1 - 2/(1 - a*x)])/(a^2*c) - (3*PolyLog[5, 1 - 2/(1 - a*x)])/(2*a^2*c)}
{ArcTanh[a*x]^4/(c - a*c*x), x, 5, (ArcTanh[a*x]^4*Log[2/(1 - a*x)])/(a*c) + (2*ArcTanh[a*x]^3*PolyLog[2, 1 - 2/(1 - a*x)])/(a*c) - (3*ArcTanh[a*x]^2*PolyLog[3, 1 - 2/(1 - a*x)])/(a*c) + (3*ArcTanh[a*x]*PolyLog[4, 1 - 2/(1 - a*x)])/(a*c) - (3*PolyLog[5, 1 - 2/(1 - a*x)])/(2*a*c)}
{ArcTanh[a*x]^4/(x*(c - a*c*x)), x, 5, (ArcTanh[a*x]^4*Log[-((2*a*x)/(1 - a*x))])/c + (2*ArcTanh[a*x]^3*PolyLog[2, 1 + (2*a*x)/(1 - a*x)])/c - (3*ArcTanh[a*x]^2*PolyLog[3, 1 + (2*a*x)/(1 - a*x)])/c + (3*ArcTanh[a*x]*PolyLog[4, 1 + (2*a*x)/(1 - a*x)])/c - (3*PolyLog[5, 1 + (2*a*x)/(1 - a*x)])/(2*c)}
{ArcTanh[a*x]^4/(c*x - a*c*x^2), x, 6, (ArcTanh[a*x]^4*Log[-((2*a*x)/(1 - a*x))])/c + (2*ArcTanh[a*x]^3*PolyLog[2, 1 + (2*a*x)/(1 - a*x)])/c - (3*ArcTanh[a*x]^2*PolyLog[3, 1 + (2*a*x)/(1 - a*x)])/c + (3*ArcTanh[a*x]*PolyLog[4, 1 + (2*a*x)/(1 - a*x)])/c - (3*PolyLog[5, 1 + (2*a*x)/(1 - a*x)])/(2*c)}
{ArcTanh[a*x]^4/(x^2*(c - a*c*x)), x, 12, (a*ArcTanh[a*x]^4)/c - ArcTanh[a*x]^4/(c*x) + (a*ArcTanh[a*x]^4*Log[-((2*a*x)/(1 - a*x))])/c + (4*a*ArcTanh[a*x]^3*Log[(2*a*x)/(1 + a*x)])/c + (2*a*ArcTanh[a*x]^3*PolyLog[2, 1 + (2*a*x)/(1 - a*x)])/c - (6*a*ArcTanh[a*x]^2*PolyLog[2, 1 - (2*a*x)/(1 + a*x)])/c - (3*a*ArcTanh[a*x]^2*PolyLog[3, 1 + (2*a*x)/(1 - a*x)])/c - (6*a*ArcTanh[a*x]*PolyLog[3, 1 - (2*a*x)/(1 + a*x)])/c + (3*a*ArcTanh[a*x]*PolyLog[4, 1 + (2*a*x)/(1 - a*x)])/c - (3*a*PolyLog[4, 1 - (2*a*x)/(1 + a*x)])/c - (3*a*PolyLog[5, 1 + (2*a*x)/(1 - a*x)])/(2*c)}
{ArcTanh[a*x]^4/(x^3*(c - a*c*x)), x, 21, (2*a^2*ArcTanh[a*x]^3)/c - (2*a*ArcTanh[a*x]^3)/(c*x) + (3*a^2*ArcTanh[a*x]^4)/(2*c) - ArcTanh[a*x]^4/(2*c*x^2) - (a*ArcTanh[a*x]^4)/(c*x) + (a^2*ArcTanh[a*x]^4*Log[-((2*a*x)/(1 - a*x))])/c + (6*a^2*ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)])/c + (4*a^2*ArcTanh[a*x]^3*Log[(2*a*x)/(1 + a*x)])/c + (2*a^2*ArcTanh[a*x]^3*PolyLog[2, 1 + (2*a*x)/(1 - a*x)])/c - (6*a^2*ArcTanh[a*x]*PolyLog[2, 1 - (2*a*x)/(1 + a*x)])/c - (6*a^2*ArcTanh[a*x]^2*PolyLog[2, 1 - (2*a*x)/(1 + a*x)])/c - (3*a^2*ArcTanh[a*x]^2*PolyLog[3, 1 + (2*a*x)/(1 - a*x)])/c - (3*a^2*PolyLog[3, 1 - (2*a*x)/(1 + a*x)])/c - (6*a^2*ArcTanh[a*x]*PolyLog[3, 1 - (2*a*x)/(1 + a*x)])/c + (3*a^2*ArcTanh[a*x]*PolyLog[4, 1 + (2*a*x)/(1 - a*x)])/c - (3*a^2*PolyLog[4, 1 - (2*a*x)/(1 + a*x)])/c - (3*a^2*PolyLog[5, 1 + (2*a*x)/(1 - a*x)])/(2*c)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{x/(ArcTanh[a*x]*(c + a*c*x)), x, 0, Defer[Int][x/((c + a*c*x)*ArcTanh[a*x]), x]}
{1/(ArcTanh[a*x]*(c + a*c*x)), x, 0, Defer[Int][1/((c + a*c*x)*ArcTanh[a*x]), x]}
{1/(x*ArcTanh[a*x]*(c + a*c*x)), x, 0, Defer[Int][1/(x*(c + a*c*x)*ArcTanh[a*x]), x]}


{x/(ArcTanh[a*x]^2*(c + a*c*x)), x, 0, Defer[Int][x/((c + a*c*x)*ArcTanh[a*x]^2), x]}
{1/(ArcTanh[a*x]^2*(c + a*c*x)), x, 0, Defer[Int][1/((c + a*c*x)*ArcTanh[a*x]^2), x]}
{1/(x*ArcTanh[a*x]^2*(c + a*c*x)), x, 0, Defer[Int][1/(x*(c + a*c*x)*ArcTanh[a*x]^2), x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcTanh[a x]^n (1-a^2 x^2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{ArcTanh[a*x]*(1 - a^2*x^2)*x^4, x, 10, x^2/(35*a^3) + x^4/(70*a) - (a*x^6)/42 + (1/5)*x^5*ArcTanh[a*x] - (1/7)*a^2*x^7*ArcTanh[a*x] + Log[1 - a^2*x^2]/(35*a^5)}
{ArcTanh[a*x]*(1 - a^2*x^2)*x^3, x, 6, x/(12*a^3) + x^3/(36*a) - (a*x^5)/30 - ArcTanh[a*x]/(12*a^4) + (1/4)*x^4*ArcTanh[a*x] - (1/6)*a^2*x^6*ArcTanh[a*x]}
{ArcTanh[a*x]*(1 - a^2*x^2)*x^2, x, 8, x^2/(15*a) - (a*x^4)/20 + (1/3)*x^3*ArcTanh[a*x] - (1/5)*a^2*x^5*ArcTanh[a*x] + Log[1 - a^2*x^2]/(15*a^3)}
{ArcTanh[a*x]*(1 - a^2*x^2)*x^1, x, 2, x/(4*a) - (a*x^3)/12 - ((1 - a^2*x^2)^2*ArcTanh[a*x])/(4*a^2)}
{ArcTanh[a*x]*(1 - a^2*x^2)*x^0, x, 3, (1 - a^2*x^2)/(6*a) + (2/3)*x*ArcTanh[a*x] + (1/3)*x*(1 - a^2*x^2)*ArcTanh[a*x] + Log[1 - a^2*x^2]/(3*a)}
{ArcTanh[a*x]*(1 - a^2*x^2)/x^1, x, 5, -((a*x)/2) + (1/2)*ArcTanh[a*x] - (1/2)*a^2*x^2*ArcTanh[a*x] - (1/2)*PolyLog[2, (-a)*x] + (1/2)*PolyLog[2, a*x]}
{ArcTanh[a*x]*(1 - a^2*x^2)/x^2, x, 4, -(ArcTanh[a*x]/x) - a^2*x*ArcTanh[a*x] - a*ArcTanh[1 - 2*a^2*x^2] - (1/2)*a*Log[1 - a^2*x^2]}
{ArcTanh[a*x]*(1 - a^2*x^2)/x^3, x, 5, -(a/(2*x)) + (1/2)*a^2*ArcTanh[a*x] - ArcTanh[a*x]/(2*x^2) + (1/2)*a^2*PolyLog[2, (-a)*x] - (1/2)*a^2*PolyLog[2, a*x]}
{ArcTanh[a*x]*(1 - a^2*x^2)/x^4, x, 4, -(a/(6*x^2)) - ArcTanh[a*x]/(3*x^3) + (a^2*ArcTanh[a*x])/x + (2/3)*a^3*ArcTanh[1 - 2*a^2*x^2]}
{ArcTanh[a*x]*(1 - a^2*x^2)/x^5, x, 3, -(a/(12*x^3)) + a^3/(4*x) - ((1 - a^2*x^2)^2*ArcTanh[a*x])/(4*x^4)}
{ArcTanh[a*x]*(1 - a^2*x^2)/x^6, x, 6, -(a/(20*x^4)) + a^3/(15*x^2) - ArcTanh[a*x]/(5*x^5) + (a^2*ArcTanh[a*x])/(3*x^3) + (2/15)*a^5*ArcTanh[1 - 2*a^2*x^2]}


{ArcTanh[a*x]^2*(1 - a^2*x^2)*x^4, x, 23, (4*x)/(105*a^4) - (2*x^3)/(315*a^2) - x^5/105 - (4*ArcTanh[a*x])/(105*a^5) + (2*x^2*ArcTanh[a*x])/(35*a^3) + (x^4*ArcTanh[a*x])/(35*a) - (1/21)*a*x^6*ArcTanh[a*x] + (2*ArcTanh[a*x]^2)/(35*a^5) + (1/5)*x^5*ArcTanh[a*x]^2 - (1/7)*a^2*x^7*ArcTanh[a*x]^2 - (4*ArcTanh[a*x]*Log[2/(1 - a*x)])/(35*a^5) - (2*PolyLog[2, -((1 + a*x)/(1 - a*x))])/(35*a^5)}
{ArcTanh[a*x]^2*(1 - a^2*x^2)*x^3, x, 24, -(x^2/(180*a^2)) - x^4/60 + (x*ArcTanh[a*x])/(6*a^3) + (x^3*ArcTanh[a*x])/(18*a) - (1/15)*a*x^5*ArcTanh[a*x] - ArcTanh[a*x]^2/(12*a^4) + (1/4)*x^4*ArcTanh[a*x]^2 - (1/6)*a^2*x^6*ArcTanh[a*x]^2 + (7*Log[1 - a^2*x^2])/(90*a^4)}
{ArcTanh[a*x]^2*(1 - a^2*x^2)*x^2, x, 16, x/(30*a^2) - x^3/30 - ArcTanh[a*x]/(30*a^3) + (2*x^2*ArcTanh[a*x])/(15*a) - (1/10)*a*x^4*ArcTanh[a*x] + (2*ArcTanh[a*x]^2)/(15*a^3) + (1/3)*x^3*ArcTanh[a*x]^2 - (1/5)*a^2*x^5*ArcTanh[a*x]^2 - (4*ArcTanh[a*x]*Log[2/(1 - a*x)])/(15*a^3) - (2*PolyLog[2, -((1 + a*x)/(1 - a*x))])/(15*a^3)}
{ArcTanh[a*x]^2*(1 - a^2*x^2)*x^1, x, 4, (1 - a^2*x^2)/(12*a^2) + (x*ArcTanh[a*x])/(3*a) + (x*(1 - a^2*x^2)*ArcTanh[a*x])/(6*a) - ((1 - a^2*x^2)^2*ArcTanh[a*x]^2)/(4*a^2) + Log[1 - a^2*x^2]/(6*a^2)}
{ArcTanh[a*x]^2*(1 - a^2*x^2)*x^0, x, 6, -(x/3) + ((1 - a^2*x^2)*ArcTanh[a*x])/(3*a) + (2*ArcTanh[a*x]^2)/(3*a) + (2/3)*x*ArcTanh[a*x]^2 + (1/3)*x*(1 - a^2*x^2)*ArcTanh[a*x]^2 - (4*ArcTanh[a*x]*Log[2/(1 - a*x)])/(3*a) - (2*PolyLog[2, -((1 + a*x)/(1 - a*x))])/(3*a)}
{ArcTanh[a*x]^2*(1 - a^2*x^2)/x^1, x, 13, (-a)*x*ArcTanh[a*x] + (1/2)*ArcTanh[a*x]^2 - (1/2)*a^2*x^2*ArcTanh[a*x]^2 + 2*ArcTanh[a*x]^2*ArcTanh[1 - 2/(1 - a*x)] - (1/2)*Log[1 - a^2*x^2] - ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)] + ArcTanh[a*x]*PolyLog[2, 1 + (2*a*x)/(1 - a*x)] + (1/2)*PolyLog[3, 1 - 2/(1 - a*x)] - (1/2)*PolyLog[3, 1 + (2*a*x)/(1 - a*x)]}
{ArcTanh[a*x]^2*(1 - a^2*x^2)/x^2, x, 9, -(ArcTanh[a*x]^2/x) - a^2*x*ArcTanh[a*x]^2 + 2*a*ArcTanh[a*x]*Log[2/(1 - a*x)] + 2*a*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)] + a*PolyLog[2, -((1 + a*x)/(1 - a*x))] - a*PolyLog[2, 1 - (2*a*x)/(1 + a*x)]}
{ArcTanh[a*x]^2*(1 - a^2*x^2)/x^3, x, 12, -((a*ArcTanh[a*x])/x) + (1/2)*a^2*ArcTanh[a*x]^2 - ArcTanh[a*x]^2/(2*x^2) - a^2*ArcTanh[1 - 2*a^2*x^2] - 2*a^2*ArcTanh[a*x]^2*ArcTanh[1 - 2/(1 - a*x)] + a^2*ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)] - a^2*ArcTanh[a*x]*PolyLog[2, 1 + (2*a*x)/(1 - a*x)] - (1/2)*a^2*PolyLog[3, 1 - 2/(1 - a*x)] + (1/2)*a^2*PolyLog[3, 1 + (2*a*x)/(1 - a*x)]}
{ArcTanh[a*x]^2*(1 - a^2*x^2)/x^4, x, 11, -(a^2/(3*x)) + (1/3)*a^3*ArcTanh[a*x] - (a*ArcTanh[a*x])/(3*x^2) - (2/3)*a^3*ArcTanh[a*x]^2 - ArcTanh[a*x]^2/(3*x^3) + (a^2*ArcTanh[a*x]^2)/x - (4/3)*a^3*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)] + (2/3)*a^3*PolyLog[2, 1 - (2*a*x)/(1 + a*x)]}
{ArcTanh[a*x]^2*(1 - a^2*x^2)/x^5, x, 5, -(a^2/(12*x^2)) - (a*ArcTanh[a*x])/(6*x^3) + (a^3*ArcTanh[a*x])/(2*x) - ((1 - a^2*x^2)^2*ArcTanh[a*x]^2)/(4*x^4) + (1/3)*a^4*ArcTanh[1 - 2*a^2*x^2]}
{ArcTanh[a*x]^2*(1 - a^2*x^2)/x^6, x, 16, -(a^2/(30*x^3)) + a^4/(30*x) - (1/30)*a^5*ArcTanh[a*x] - (a*ArcTanh[a*x])/(10*x^4) + (2*a^3*ArcTanh[a*x])/(15*x^2) - (2/15)*a^5*ArcTanh[a*x]^2 - ArcTanh[a*x]^2/(5*x^5) + (a^2*ArcTanh[a*x]^2)/(3*x^3) - (4/15)*a^5*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)] + (2/15)*a^5*PolyLog[2, 1 - (2*a*x)/(1 + a*x)]}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{1/ArcTanh[a*x]*(1 - a^2*x^2)*x^2, x, 0, Defer[Int][(x^2*(1 - a^2*x^2))/ArcTanh[a*x], x]}
{1/ArcTanh[a*x]*(1 - a^2*x^2)*x^1, x, 0, Defer[Int][(x*(1 - a^2*x^2))/ArcTanh[a*x], x]}
{1/ArcTanh[a*x]*(1 - a^2*x^2)*x^0, x, 0, Defer[Int][(1 - a^2*x^2)/ArcTanh[a*x], x]}
{1/ArcTanh[a*x]*(1 - a^2*x^2)/x^1, x, 0, Defer[Int][(1 - a^2*x^2)/(x*ArcTanh[a*x]), x]}
{1/ArcTanh[a*x]*(1 - a^2*x^2)/x^2, x, 0, Defer[Int][(1 - a^2*x^2)/(x^2*ArcTanh[a*x]), x]}


{1/ArcTanh[a*x]^2*(1 - a^2*x^2)*x^2, x, 0, Defer[Int][(x^2*(1 - a^2*x^2))/ArcTanh[a*x]^2, x]}
{1/ArcTanh[a*x]^2*(1 - a^2*x^2)*x^1, x, 0, Defer[Int][(x*(1 - a^2*x^2))/ArcTanh[a*x]^2, x]}
{1/ArcTanh[a*x]^2*(1 - a^2*x^2)*x^0, x, 0, Defer[Int][(1 - a^2*x^2)/ArcTanh[a*x]^2, x]}
{1/ArcTanh[a*x]^2*(1 - a^2*x^2)/x^1, x, 0, Defer[Int][(1 - a^2*x^2)/(x*ArcTanh[a*x]^2), x]}
{1/ArcTanh[a*x]^2*(1 - a^2*x^2)/x^2, x, 0, Defer[Int][(1 - a^2*x^2)/(x^2*ArcTanh[a*x]^2), x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcTanh[a x]^n (1-a^2 x^2)^2*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{ArcTanh[a*x]*(1 - a^2*x^2)^2*x^4, x, 17, (4*x^2)/(315*a^3) + (2*x^4)/(315*a) - (11*a*x^6)/378 + (a^3*x^8)/72 + (1/5)*x^5*ArcTanh[a*x] - (2/7)*a^2*x^7*ArcTanh[a*x] + (1/9)*a^4*x^9*ArcTanh[a*x] + (4*Log[1 - a^2*x^2])/(315*a^5)}
{ArcTanh[a*x]*(1 - a^2*x^2)^2*x^3, x, 11, x/(24*a^3) + x^3/(72*a) - (a*x^5)/24 + (a^3*x^7)/56 - ArcTanh[a*x]/(24*a^4) + (1/4)*x^4*ArcTanh[a*x] - (1/3)*a^2*x^6*ArcTanh[a*x] + (1/8)*a^4*x^8*ArcTanh[a*x]}
{ArcTanh[a*x]*(1 - a^2*x^2)^2*x^2, x, 14, (4*x^2)/(105*a) - (9*a*x^4)/140 + (a^3*x^6)/42 + (1/3)*x^3*ArcTanh[a*x] - (2/5)*a^2*x^5*ArcTanh[a*x] + (1/7)*a^4*x^7*ArcTanh[a*x] + (4*Log[1 - a^2*x^2])/(105*a^3)}
{ArcTanh[a*x]*(1 - a^2*x^2)^2*x^1, x, 3, x/(6*a) - (a*x^3)/9 + (a^3*x^5)/30 - ((1 - a^2*x^2)^3*ArcTanh[a*x])/(6*a^2)}
{ArcTanh[a*x]*(1 - a^2*x^2)^2*x^0, x, 4, (2*(1 - a^2*x^2))/(15*a) + (1 - a^2*x^2)^2/(20*a) + (8/15)*x*ArcTanh[a*x] + (4/15)*x*(1 - a^2*x^2)*ArcTanh[a*x] + (1/5)*x*(1 - a^2*x^2)^2*ArcTanh[a*x] + (4*Log[1 - a^2*x^2])/(15*a)}
{ArcTanh[a*x]*(1 - a^2*x^2)^2/x^1, x, 8, -((3*a*x)/4) + (a^3*x^3)/12 + (3/4)*ArcTanh[a*x] - a^2*x^2*ArcTanh[a*x] + (1/4)*a^4*x^4*ArcTanh[a*x] - (1/2)*PolyLog[2, (-a)*x] + (1/2)*PolyLog[2, a*x]}
{ArcTanh[a*x]*(1 - a^2*x^2)^2/x^2, x, 8, (a^3*x^2)/6 - ArcTanh[a*x]/x - 2*a^2*x*ArcTanh[a*x] + (1/3)*a^4*x^3*ArcTanh[a*x] - a*ArcTanh[1 - 2*a^2*x^2] - (5/6)*a*Log[1 - a^2*x^2]}
{ArcTanh[a*x]*(1 - a^2*x^2)^2/x^3, x, 7, -(a/(2*x)) + (a^3*x)/2 - ArcTanh[a*x]/(2*x^2) + (1/2)*a^4*x^2*ArcTanh[a*x] + a^2*PolyLog[2, (-a)*x] - a^2*PolyLog[2, a*x]}
{ArcTanh[a*x]*(1 - a^2*x^2)^2/x^4, x, 7, -(a/(6*x^2)) - ArcTanh[a*x]/(3*x^3) + (2*a^2*ArcTanh[a*x])/x + a^4*x*ArcTanh[a*x] + (5/3)*a^3*ArcTanh[1 - 2*a^2*x^2] + (1/2)*a^3*Log[1 - a^2*x^2]}
{ArcTanh[a*x]*(1 - a^2*x^2)^2/x^5, x, 8, -(a/(12*x^3)) + (3*a^3)/(4*x) - (3/4)*a^4*ArcTanh[a*x] - ArcTanh[a*x]/(4*x^4) + (a^2*ArcTanh[a*x])/x^2 - (1/2)*a^4*PolyLog[2, (-a)*x] + (1/2)*a^4*PolyLog[2, a*x]}
{ArcTanh[a*x]*(1 - a^2*x^2)^2/x^6, x, 8, -(a/(20*x^4)) + (7*a^3)/(30*x^2) - ArcTanh[a*x]/(5*x^5) + (2*a^2*ArcTanh[a*x])/(3*x^3) - (a^4*ArcTanh[a*x])/x - (8/15)*a^5*ArcTanh[1 - 2*a^2*x^2]}


{ArcTanh[a*x]^2*(1 - a^2*x^2)^2*x^4, x, 42, (29*x)/(3780*a^4) - (67*x^3)/(11340*a^2) - (23*x^5)/3780 + (a^2*x^7)/252 - (29*ArcTanh[a*x])/(3780*a^5) + (8*x^2*ArcTanh[a*x])/(315*a^3) + (4*x^4*ArcTanh[a*x])/(315*a) - (11/189)*a*x^6*ArcTanh[a*x] + (1/36)*a^3*x^8*ArcTanh[a*x] + (8*ArcTanh[a*x]^2)/(315*a^5) + (1/5)*x^5*ArcTanh[a*x]^2 - (2/7)*a^2*x^7*ArcTanh[a*x]^2 + (1/9)*a^4*x^9*ArcTanh[a*x]^2 - (16*ArcTanh[a*x]*Log[2/(1 - a*x)])/(315*a^5) - (8*PolyLog[2, -((1 + a*x)/(1 - a*x))])/(315*a^5)}
{ArcTanh[a*x]^2*(1 - a^2*x^2)^2*x^3, x, 45, -((5*x^2)/(504*a^2)) - x^4/84 + (a^2*x^6)/168 + (x*ArcTanh[a*x])/(12*a^3) + (x^3*ArcTanh[a*x])/(36*a) - (1/12)*a*x^5*ArcTanh[a*x] + (1/28)*a^3*x^7*ArcTanh[a*x] - ArcTanh[a*x]^2/(24*a^4) + (1/4)*x^4*ArcTanh[a*x]^2 - (1/3)*a^2*x^6*ArcTanh[a*x]^2 + (1/8)*a^4*x^8*ArcTanh[a*x]^2 + (2*Log[1 - a^2*x^2])/(63*a^4)}
{ArcTanh[a*x]^2*(1 - a^2*x^2)^2*x^2, x, 30, -(x/(210*a^2)) - (17*x^3)/630 + (a^2*x^5)/105 + ArcTanh[a*x]/(210*a^3) + (8*x^2*ArcTanh[a*x])/(105*a) - (9/70)*a*x^4*ArcTanh[a*x] + (1/21)*a^3*x^6*ArcTanh[a*x] + (8*ArcTanh[a*x]^2)/(105*a^3) + (1/3)*x^3*ArcTanh[a*x]^2 - (2/5)*a^2*x^5*ArcTanh[a*x]^2 + (1/7)*a^4*x^7*ArcTanh[a*x]^2 - (16*ArcTanh[a*x]*Log[2/(1 - a*x)])/(105*a^3) - (8*PolyLog[2, -((1 + a*x)/(1 - a*x))])/(105*a^3)}
{ArcTanh[a*x]^2*(1 - a^2*x^2)^2*x^1, x, 5, (2*(1 - a^2*x^2))/(45*a^2) + (1 - a^2*x^2)^2/(60*a^2) + (8*x*ArcTanh[a*x])/(45*a) + (4*x*(1 - a^2*x^2)*ArcTanh[a*x])/(45*a) + (x*(1 - a^2*x^2)^2*ArcTanh[a*x])/(15*a) - ((1 - a^2*x^2)^3*ArcTanh[a*x]^2)/(6*a^2) + (4*Log[1 - a^2*x^2])/(45*a^2)}
{ArcTanh[a*x]^2*(1 - a^2*x^2)^2*x^0, x, 8, -((11*x)/30) + (a^2*x^3)/30 + (4*(1 - a^2*x^2)*ArcTanh[a*x])/(15*a) + ((1 - a^2*x^2)^2*ArcTanh[a*x])/(10*a) + (8*ArcTanh[a*x]^2)/(15*a) + (8/15)*x*ArcTanh[a*x]^2 + (4/15)*x*(1 - a^2*x^2)*ArcTanh[a*x]^2 + (1/5)*x*(1 - a^2*x^2)^2*ArcTanh[a*x]^2 - (16*ArcTanh[a*x]*Log[2/(1 - a*x)])/(15*a) - (8*PolyLog[2, -((1 + a*x)/(1 - a*x))])/(15*a)}
{ArcTanh[a*x]^2*(1 - a^2*x^2)^2/x^1, x, 23, (a^2*x^2)/12 - (3/2)*a*x*ArcTanh[a*x] + (1/6)*a^3*x^3*ArcTanh[a*x] + (3/4)*ArcTanh[a*x]^2 - a^2*x^2*ArcTanh[a*x]^2 + (1/4)*a^4*x^4*ArcTanh[a*x]^2 + 2*ArcTanh[a*x]^2*ArcTanh[1 - 2/(1 - a*x)] - (2/3)*Log[1 - a^2*x^2] - ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)] + ArcTanh[a*x]*PolyLog[2, 1 + (2*a*x)/(1 - a*x)] + (1/2)*PolyLog[3, 1 - 2/(1 - a*x)] - (1/2)*PolyLog[3, 1 + (2*a*x)/(1 - a*x)]}
{ArcTanh[a*x]^2*(1 - a^2*x^2)^2/x^2, x, 16, (a^2*x)/3 - (1/3)*a*ArcTanh[a*x] + (1/3)*a^3*x^2*ArcTanh[a*x] - (2/3)*a*ArcTanh[a*x]^2 - ArcTanh[a*x]^2/x - 2*a^2*x*ArcTanh[a*x]^2 + (1/3)*a^4*x^3*ArcTanh[a*x]^2 + (10/3)*a*ArcTanh[a*x]*Log[2/(1 - a*x)] + 2*a*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)] + (5/3)*a*PolyLog[2, -((1 + a*x)/(1 - a*x))] - a*PolyLog[2, 1 - (2*a*x)/(1 + a*x)]}
{ArcTanh[a*x]^2*(1 - a^2*x^2)^2/x^3, x, 18, -((a*ArcTanh[a*x])/x) + a^3*x*ArcTanh[a*x] - ArcTanh[a*x]^2/(2*x^2) + (1/2)*a^4*x^2*ArcTanh[a*x]^2 - a^2*ArcTanh[1 - 2*a^2*x^2] - 4*a^2*ArcTanh[a*x]^2*ArcTanh[1 - 2/(1 - a*x)] + (1/2)*a^2*Log[1 - a^2*x^2] + 2*a^2*ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)] - 2*a^2*ArcTanh[a*x]*PolyLog[2, 1 + (2*a*x)/(1 - a*x)] - a^2*PolyLog[3, 1 - 2/(1 - a*x)] + a^2*PolyLog[3, 1 + (2*a*x)/(1 - a*x)]}
{ArcTanh[a*x]^2*(1 - a^2*x^2)^2/x^4, x, 16, -(a^2/(3*x)) + (1/3)*a^3*ArcTanh[a*x] - (a*ArcTanh[a*x])/(3*x^2) - (2/3)*a^3*ArcTanh[a*x]^2 - ArcTanh[a*x]^2/(3*x^3) + (2*a^2*ArcTanh[a*x]^2)/x + a^4*x*ArcTanh[a*x]^2 - 2*a^3*ArcTanh[a*x]*Log[2/(1 - a*x)] - (10/3)*a^3*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)] - a^3*PolyLog[2, -((1 + a*x)/(1 - a*x))] + (5/3)*a^3*PolyLog[2, 1 - (2*a*x)/(1 + a*x)]}
{ArcTanh[a*x]^2*(1 - a^2*x^2)^2/x^5, x, 20, -(a^2/(12*x^2)) - (a*ArcTanh[a*x])/(6*x^3) + (3*a^3*ArcTanh[a*x])/(2*x) - (3/4)*a^4*ArcTanh[a*x]^2 - ArcTanh[a*x]^2/(4*x^4) + (a^2*ArcTanh[a*x]^2)/x^2 + (4/3)*a^4*ArcTanh[1 - 2*a^2*x^2] + 2*a^4*ArcTanh[a*x]^2*ArcTanh[1 - 2/(1 - a*x)] - a^4*ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)] + a^4*ArcTanh[a*x]*PolyLog[2, 1 + (2*a*x)/(1 - a*x)] + (1/2)*a^4*PolyLog[3, 1 - 2/(1 - a*x)] - (1/2)*a^4*PolyLog[3, 1 + (2*a*x)/(1 - a*x)]}
{ArcTanh[a*x]^2*(1 - a^2*x^2)^2/x^6, x, 21, -(a^2/(30*x^3)) + (11*a^4)/(30*x) - (11/30)*a^5*ArcTanh[a*x] - (a*ArcTanh[a*x])/(10*x^4) + (7*a^3*ArcTanh[a*x])/(15*x^2) + (8/15)*a^5*ArcTanh[a*x]^2 - ArcTanh[a*x]^2/(5*x^5) + (2*a^2*ArcTanh[a*x]^2)/(3*x^3) - (a^4*ArcTanh[a*x]^2)/x + (16/15)*a^5*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)] - (8/15)*a^5*PolyLog[2, 1 - (2*a*x)/(1 + a*x)]}
{ArcTanh[a*x]^2*(1 - a^2*x^2)^2/x^7, x, 9, -(a^2/(60*x^4)) + (7*a^4)/(90*x^2) - (a*ArcTanh[a*x])/(15*x^5) + (2*a^3*ArcTanh[a*x])/(9*x^3) - (a^5*ArcTanh[a*x])/(3*x) - ((1 - a^2*x^2)^3*ArcTanh[a*x]^2)/(6*x^6) - (8/45)*a^6*ArcTanh[1 - 2*a^2*x^2]}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{1/ArcTanh[a*x]*(1 - a^2*x^2)^2*x^2, x, 0, Defer[Int][(x^2*(1 - a^2*x^2)^2)/ArcTanh[a*x], x]}
{1/ArcTanh[a*x]*(1 - a^2*x^2)^2*x^1, x, 0, Defer[Int][(x*(1 - a^2*x^2)^2)/ArcTanh[a*x], x]}
{1/ArcTanh[a*x]*(1 - a^2*x^2)^2*x^0, x, 0, Defer[Int][(1 - a^2*x^2)^2/ArcTanh[a*x], x]}
{1/ArcTanh[a*x]*(1 - a^2*x^2)^2/x^1, x, 0, Defer[Int][(1 - a^2*x^2)^2/(x*ArcTanh[a*x]), x]}
{1/ArcTanh[a*x]*(1 - a^2*x^2)^2/x^2, x, 0, Defer[Int][(1 - a^2*x^2)^2/(x^2*ArcTanh[a*x]), x]}


{1/ArcTanh[a*x]^2*(1 - a^2*x^2)^2*x^2, x, 0, Defer[Int][(x^2*(1 - a^2*x^2)^2)/ArcTanh[a*x]^2, x]}
{1/ArcTanh[a*x]^2*(1 - a^2*x^2)^2*x^1, x, 0, Defer[Int][(x*(1 - a^2*x^2)^2)/ArcTanh[a*x]^2, x]}
{1/ArcTanh[a*x]^2*(1 - a^2*x^2)^2*x^0, x, 0, Defer[Int][(1 - a^2*x^2)^2/ArcTanh[a*x]^2, x]}
{1/ArcTanh[a*x]^2*(1 - a^2*x^2)^2/x^1, x, 0, Defer[Int][(1 - a^2*x^2)^2/(x*ArcTanh[a*x]^2), x]}
{1/ArcTanh[a*x]^2*(1 - a^2*x^2)^2/x^2, x, 0, Defer[Int][(1 - a^2*x^2)^2/(x^2*ArcTanh[a*x]^2), x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcTanh[a x]^n / (1-a^2 x^2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{x^3*ArcTanh[a*x]/(1 - a^2*x^2), x, 5, -(x/(2*a^3)) + ArcTanh[a*x]/(2*a^4) - (x^2*ArcTanh[a*x])/(2*a^2) - ArcTanh[a*x]^2/(2*a^4) + (ArcTanh[a*x]*Log[2/(1 - a*x)])/a^4 + PolyLog[2, -((1 + a*x)/(1 - a*x))]/(2*a^4)}
{x^2*ArcTanh[a*x]/(1 - a^2*x^2), x, 4, -((x*ArcTanh[a*x])/a^2) + ArcTanh[a*x]^2/(2*a^3) - Log[1 - a^2*x^2]/(2*a^3)}
{x*ArcTanh[a*x]/(1 - a^2*x^2), x, 3, -(ArcTanh[a*x]^2/(2*a^2)) + (ArcTanh[a*x]*Log[2/(1 - a*x)])/a^2 + PolyLog[2, -((1 + a*x)/(1 - a*x))]/(2*a^2)}
{ArcTanh[a*x]/(1 - a^2*x^2), x, 1, ArcTanh[a*x]^2/(2*a)}
{ArcTanh[a*x]/(x*(1 - a^2*x^2)), x, 3, (1/2)*ArcTanh[a*x]^2 + ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)] - (1/2)*PolyLog[2, 1 - (2*a*x)/(1 + a*x)]}
{ArcTanh[a*x]/(x^2*(1 - a^2*x^2)), x, 3, -(ArcTanh[a*x]/x) + (1/2)*a*ArcTanh[a*x]^2 - a*ArcTanh[1 - 2*a^2*x^2]}
{ArcTanh[a*x]/(x^3*(1 - a^2*x^2)), x, 5, -(a/(2*x)) + (1/2)*a^2*ArcTanh[a*x] - ArcTanh[a*x]/(2*x^2) + (1/2)*a^2*ArcTanh[a*x]^2 + a^2*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)] - (1/2)*a^2*PolyLog[2, 1 - (2*a*x)/(1 + a*x)]}


{x^3*ArcTanh[a*x]^2/(1 - a^2*x^2), x, 10, -((x*ArcTanh[a*x])/a^3) + ArcTanh[a*x]^2/(2*a^4) - (x^2*ArcTanh[a*x]^2)/(2*a^2) - ArcTanh[a*x]^3/(3*a^4) + (ArcTanh[a*x]^2*Log[2/(1 - a*x)])/a^4 - Log[1 - a^2*x^2]/(2*a^4) + (ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/a^4 - PolyLog[3, 1 - 2/(1 - a*x)]/(2*a^4)}
{x^2*ArcTanh[a*x]^2/(1 - a^2*x^2), x, 6, -(ArcTanh[a*x]^2/a^3) - (x*ArcTanh[a*x]^2)/a^2 + ArcTanh[a*x]^3/(3*a^3) + (2*ArcTanh[a*x]*Log[2/(1 - a*x)])/a^3 + PolyLog[2, -((1 + a*x)/(1 - a*x))]/a^3}
{x*ArcTanh[a*x]^2/(1 - a^2*x^2), x, 4, -(ArcTanh[a*x]^3/(3*a^2)) + (ArcTanh[a*x]^2*Log[2/(1 - a*x)])/a^2 + (ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/a^2 - PolyLog[3, 1 - 2/(1 - a*x)]/(2*a^2)}
{ArcTanh[a*x]^2/(1 - a^2*x^2), x, 1, ArcTanh[a*x]^3/(3*a)}
{ArcTanh[a*x]^2/(x*(1 - a^2*x^2)), x, 4, (1/3)*ArcTanh[a*x]^3 + ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)] - ArcTanh[a*x]*PolyLog[2, 1 - (2*a*x)/(1 + a*x)] - (1/2)*PolyLog[3, 1 - (2*a*x)/(1 + a*x)]}
{ArcTanh[a*x]^2/(x^2*(1 - a^2*x^2)), x, 6, a*ArcTanh[a*x]^2 - ArcTanh[a*x]^2/x + (1/3)*a*ArcTanh[a*x]^3 + 2*a*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)] - a*PolyLog[2, 1 - (2*a*x)/(1 + a*x)]}
{ArcTanh[a*x]^2/(x^3*(1 - a^2*x^2)), x, 9, -((a*ArcTanh[a*x])/x) + (1/2)*a^2*ArcTanh[a*x]^2 - ArcTanh[a*x]^2/(2*x^2) + (1/3)*a^2*ArcTanh[a*x]^3 - a^2*ArcTanh[1 - 2*a^2*x^2] + a^2*ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)] - a^2*ArcTanh[a*x]*PolyLog[2, 1 - (2*a*x)/(1 + a*x)] - (1/2)*a^2*PolyLog[3, 1 - (2*a*x)/(1 + a*x)]}


{x^3*ArcTanh[a*x]^3/(1 - a^2*x^2), x, 13, -((3*ArcTanh[a*x]^2)/(2*a^4)) - (3*x*ArcTanh[a*x]^2)/(2*a^3) + ArcTanh[a*x]^3/(2*a^4) - (x^2*ArcTanh[a*x]^3)/(2*a^2) - ArcTanh[a*x]^4/(4*a^4) + (3*ArcTanh[a*x]*Log[2/(1 - a*x)])/a^4 + (ArcTanh[a*x]^3*Log[2/(1 - a*x)])/a^4 + (3*PolyLog[2, -((1 + a*x)/(1 - a*x))])/(2*a^4) + (3*ArcTanh[a*x]^2*PolyLog[2, 1 - 2/(1 - a*x)])/(2*a^4) - (3*ArcTanh[a*x]*PolyLog[3, 1 - 2/(1 - a*x)])/(2*a^4) + (3*PolyLog[4, 1 - 2/(1 - a*x)])/(4*a^4)}
{x^2*ArcTanh[a*x]^3/(1 - a^2*x^2), x, 7, -(ArcTanh[a*x]^3/a^3) - (x*ArcTanh[a*x]^3)/a^2 + ArcTanh[a*x]^4/(4*a^3) + (3*ArcTanh[a*x]^2*Log[2/(1 - a*x)])/a^3 + (3*ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/a^3 - (3*PolyLog[3, 1 - 2/(1 - a*x)])/(2*a^3)}
{x*ArcTanh[a*x]^3/(1 - a^2*x^2), x, 5, -(ArcTanh[a*x]^4/(4*a^2)) + (ArcTanh[a*x]^3*Log[2/(1 - a*x)])/a^2 + (3*ArcTanh[a*x]^2*PolyLog[2, 1 - 2/(1 - a*x)])/(2*a^2) - (3*ArcTanh[a*x]*PolyLog[3, 1 - 2/(1 - a*x)])/(2*a^2) + (3*PolyLog[4, 1 - 2/(1 - a*x)])/(4*a^2)}
{ArcTanh[a*x]^3/(1 - a^2*x^2), x, 1, ArcTanh[a*x]^4/(4*a)}
{ArcTanh[a*x]^3/(x*(1 - a^2*x^2)), x, 5, (1/4)*ArcTanh[a*x]^4 + ArcTanh[a*x]^3*Log[(2*a*x)/(1 + a*x)] - (3/2)*ArcTanh[a*x]^2*PolyLog[2, 1 - (2*a*x)/(1 + a*x)] - (3/2)*ArcTanh[a*x]*PolyLog[3, 1 - (2*a*x)/(1 + a*x)] - (3/4)*PolyLog[4, 1 - (2*a*x)/(1 + a*x)]}
{ArcTanh[a*x]^3/(x^2*(1 - a^2*x^2)), x, 7, a*ArcTanh[a*x]^3 - ArcTanh[a*x]^3/x + (1/4)*a*ArcTanh[a*x]^4 + 3*a*ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)] - 3*a*ArcTanh[a*x]*PolyLog[2, 1 - (2*a*x)/(1 + a*x)] - (3/2)*a*PolyLog[3, 1 - (2*a*x)/(1 + a*x)]}
{ArcTanh[a*x]^3/(x^3*(1 - a^2*x^2)), x, 13, (3/2)*a^2*ArcTanh[a*x]^2 - (3*a*ArcTanh[a*x]^2)/(2*x) + (1/2)*a^2*ArcTanh[a*x]^3 - ArcTanh[a*x]^3/(2*x^2) + (1/4)*a^2*ArcTanh[a*x]^4 + 3*a^2*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)] + a^2*ArcTanh[a*x]^3*Log[(2*a*x)/(1 + a*x)] - (3/2)*a^2*PolyLog[2, 1 - (2*a*x)/(1 + a*x)] - (3/2)*a^2*ArcTanh[a*x]^2*PolyLog[2, 1 - (2*a*x)/(1 + a*x)] - (3/2)*a^2*ArcTanh[a*x]*PolyLog[3, 1 - (2*a*x)/(1 + a*x)] - (3/4)*a^2*PolyLog[4, 1 - (2*a*x)/(1 + a*x)]}


{ArcTanh[a*x]^(1/2)/(1 - a^2*x^2), x, 1, (2*ArcTanh[a*x]^(3/2))/(3*a)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{x/(ArcTanh[a*x]*(1 - a^2*x^2)), x, 0, Defer[Int][x/((1 - a^2*x^2)*ArcTanh[a*x]), x]}
{1/(ArcTanh[a*x]*(1 - a^2*x^2)), x, 1, Log[ArcTanh[a*x]]/a}
{1/(x*ArcTanh[a*x]*(1 - a^2*x^2)), x, 0, Defer[Int][1/(x*(1 - a^2*x^2)*ArcTanh[a*x]), x]}


{x/((1 - a^2*x^2)*ArcTanh[a*x]^2), x, 1, -(x/(a*ArcTanh[a*x])) + Defer[Int][1/ArcTanh[a*x], x]/a}
{1/((1 - a^2*x^2)*ArcTanh[a*x]^2), x, 1, -(1/(a*ArcTanh[a*x]))}
{1/(x*(1 - a^2*x^2)*ArcTanh[a*x]^2), x, 1, -(1/(a*x*ArcTanh[a*x])) - Defer[Int][1/(x^2*ArcTanh[a*x]), x]/a}


{x/((1 - a^2*x^2)*ArcTanh[a*x]^3), x, 1, -(x/(2*a*ArcTanh[a*x]^2)) + Defer[Int][1/ArcTanh[a*x]^2, x]/(2*a)}
{1/((1 - a^2*x^2)*ArcTanh[a*x]^3), x, 1, -(1/(2*a*ArcTanh[a*x]^2))}
{1/(x*(1 - a^2*x^2)*ArcTanh[a*x]^3), x, 1, -(1/(2*a*x*ArcTanh[a*x]^2)) - Defer[Int][1/(x^2*ArcTanh[a*x]^2), x]/(2*a)}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{ArcTanh[a*x]^n/(1 - a^2*x^2), x, 1, ArcTanh[a*x]^(1 + n)/(a*(1 + n))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcTanh[a x]^n / (1-a^2 x^2)^2*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{x^3*ArcTanh[a*x]/(1 - a^2*x^2)^2, x, 7, -(x/(4*a^3*(1 - a^2*x^2))) - ArcTanh[a*x]/(4*a^4) + ArcTanh[a*x]/(2*a^4*(1 - a^2*x^2)) + ArcTanh[a*x]^2/(2*a^4) - (ArcTanh[a*x]*Log[2/(1 - a*x)])/a^4 - PolyLog[2, -((1 + a*x)/(1 - a*x))]/(2*a^4)}
{x^2*ArcTanh[a*x]/(1 - a^2*x^2)^2, x, 4, -(1/(4*a^3*(1 - a^2*x^2))) + (x*ArcTanh[a*x])/(2*a^2*(1 - a^2*x^2)) - ArcTanh[a*x]^2/(4*a^3)}
{x*ArcTanh[a*x]/(1 - a^2*x^2)^2, x, 3, -(x/(4*a*(1 - a^2*x^2))) - ArcTanh[a*x]/(4*a^2) + ArcTanh[a*x]/(2*a^2*(1 - a^2*x^2))}
{ArcTanh[a*x]/(1 - a^2*x^2)^2, x, 2, -(1/(4*a*(1 - a^2*x^2))) + (x*ArcTanh[a*x])/(2*(1 - a^2*x^2)) + ArcTanh[a*x]^2/(4*a)}
{ArcTanh[a*x]/(x*(1 - a^2*x^2)^2), x, 7, -((a*x)/(4*(1 - a^2*x^2))) - (1/4)*ArcTanh[a*x] + ArcTanh[a*x]/(2*(1 - a^2*x^2)) + (1/2)*ArcTanh[a*x]^2 + ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)] - (1/2)*PolyLog[2, 1 - (2*a*x)/(1 + a*x)]}
{ArcTanh[a*x]/(x^2*(1 - a^2*x^2)^2), x, 6, -(a/(4*(1 - a^2*x^2))) - ArcTanh[a*x]/x + (a^2*x*ArcTanh[a*x])/(2*(1 - a^2*x^2)) + (3/4)*a*ArcTanh[a*x]^2 - a*ArcTanh[1 - 2*a^2*x^2]}
{ArcTanh[a*x]/(x^3*(1 - a^2*x^2)^2), x, 13, -(a/(2*x)) - (a^3*x)/(4*(1 - a^2*x^2)) + (1/4)*a^2*ArcTanh[a*x] - ArcTanh[a*x]/(2*x^2) + (a^2*ArcTanh[a*x])/(2*(1 - a^2*x^2)) + a^2*ArcTanh[a*x]^2 + 2*a^2*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)] - a^2*PolyLog[2, 1 - (2*a*x)/(1 + a*x)]}


{x^3*ArcTanh[a*x]^2/(1 - a^2*x^2)^2, x, 8, 1/(4*a^4*(1 - a^2*x^2)) - (x*ArcTanh[a*x])/(2*a^3*(1 - a^2*x^2)) - ArcTanh[a*x]^2/(4*a^4) + ArcTanh[a*x]^2/(2*a^4*(1 - a^2*x^2)) + ArcTanh[a*x]^3/(3*a^4) - (ArcTanh[a*x]^2*Log[2/(1 - a*x)])/a^4 - (ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/a^4 + PolyLog[3, 1 - 2/(1 - a*x)]/(2*a^4)}
{x^2*ArcTanh[a*x]^2/(1 - a^2*x^2)^2, x, 6, x/(4*a^2*(1 - a^2*x^2)) + ArcTanh[a*x]/(4*a^3) - ArcTanh[a*x]/(2*a^3*(1 - a^2*x^2)) + (x*ArcTanh[a*x]^2)/(2*a^2*(1 - a^2*x^2)) - ArcTanh[a*x]^3/(6*a^3)}
{x*ArcTanh[a*x]^2/(1 - a^2*x^2)^2, x, 3, 1/(4*a^2*(1 - a^2*x^2)) - (x*ArcTanh[a*x])/(2*a*(1 - a^2*x^2)) - ArcTanh[a*x]^2/(4*a^2) + ArcTanh[a*x]^2/(2*a^2*(1 - a^2*x^2))}
{ArcTanh[a*x]^2/(1 - a^2*x^2)^2, x, 4, x/(4*(1 - a^2*x^2)) + ArcTanh[a*x]/(4*a) - ArcTanh[a*x]/(2*a*(1 - a^2*x^2)) + (x*ArcTanh[a*x]^2)/(2*(1 - a^2*x^2)) + ArcTanh[a*x]^3/(6*a)}
{ArcTanh[a*x]^2/(x*(1 - a^2*x^2)^2), x, 8, 1/(4*(1 - a^2*x^2)) - (a*x*ArcTanh[a*x])/(2*(1 - a^2*x^2)) - (1/4)*ArcTanh[a*x]^2 + ArcTanh[a*x]^2/(2*(1 - a^2*x^2)) + (1/3)*ArcTanh[a*x]^3 + ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)] - ArcTanh[a*x]*PolyLog[2, 1 - (2*a*x)/(1 + a*x)] - (1/2)*PolyLog[3, 1 - (2*a*x)/(1 + a*x)]}
{ArcTanh[a*x]^2/(x^2*(1 - a^2*x^2)^2), x, 11, (a^2*x)/(4*(1 - a^2*x^2)) + (1/4)*a*ArcTanh[a*x] - (a*ArcTanh[a*x])/(2*(1 - a^2*x^2)) + a*ArcTanh[a*x]^2 - ArcTanh[a*x]^2/x + (a^2*x*ArcTanh[a*x]^2)/(2*(1 - a^2*x^2)) + (1/2)*a*ArcTanh[a*x]^3 + 2*a*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)] - a*PolyLog[2, 1 - (2*a*x)/(1 + a*x)]}
{ArcTanh[a*x]^2/(x^3*(1 - a^2*x^2)^2), x, 18, a^2/(4*(1 - a^2*x^2)) - (a*ArcTanh[a*x])/x - (a^3*x*ArcTanh[a*x])/(2*(1 - a^2*x^2)) + (1/4)*a^2*ArcTanh[a*x]^2 - ArcTanh[a*x]^2/(2*x^2) + (a^2*ArcTanh[a*x]^2)/(2*(1 - a^2*x^2)) + (2/3)*a^2*ArcTanh[a*x]^3 - a^2*ArcTanh[1 - 2*a^2*x^2] + 2*a^2*ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)] - 2*a^2*ArcTanh[a*x]*PolyLog[2, 1 - (2*a*x)/(1 + a*x)] - a^2*PolyLog[3, 1 - (2*a*x)/(1 + a*x)]}


{x^3*ArcTanh[a*x]^3/(1 - a^2*x^2)^2, x, 11, -((3*x)/(8*a^3*(1 - a^2*x^2))) - (3*ArcTanh[a*x])/(8*a^4) + (3*ArcTanh[a*x])/(4*a^4*(1 - a^2*x^2)) - (3*x*ArcTanh[a*x]^2)/(4*a^3*(1 - a^2*x^2)) - ArcTanh[a*x]^3/(4*a^4) + ArcTanh[a*x]^3/(2*a^4*(1 - a^2*x^2)) + ArcTanh[a*x]^4/(4*a^4) - (ArcTanh[a*x]^3*Log[2/(1 - a*x)])/a^4 - (3*ArcTanh[a*x]^2*PolyLog[2, 1 - 2/(1 - a*x)])/(2*a^4) + (3*ArcTanh[a*x]*PolyLog[3, 1 - 2/(1 - a*x)])/(2*a^4) - (3*PolyLog[4, 1 - 2/(1 - a*x)])/(4*a^4)}
{x^2*ArcTanh[a*x]^3/(1 - a^2*x^2)^2, x, 6, -(3/(8*a^3*(1 - a^2*x^2))) + (3*x*ArcTanh[a*x])/(4*a^2*(1 - a^2*x^2)) + (3*ArcTanh[a*x]^2)/(8*a^3) - (3*ArcTanh[a*x]^2)/(4*a^3*(1 - a^2*x^2)) + (x*ArcTanh[a*x]^3)/(2*a^2*(1 - a^2*x^2)) - ArcTanh[a*x]^4/(8*a^3)}
{x*ArcTanh[a*x]^3/(1 - a^2*x^2)^2, x, 5, -((3*x)/(8*a*(1 - a^2*x^2))) - (3*ArcTanh[a*x])/(8*a^2) + (3*ArcTanh[a*x])/(4*a^2*(1 - a^2*x^2)) - (3*x*ArcTanh[a*x]^2)/(4*a*(1 - a^2*x^2)) - ArcTanh[a*x]^3/(4*a^2) + ArcTanh[a*x]^3/(2*a^2*(1 - a^2*x^2))}
{ArcTanh[a*x]^3/(1 - a^2*x^2)^2, x, 4, -(3/(8*a*(1 - a^2*x^2))) + (3*x*ArcTanh[a*x])/(4*(1 - a^2*x^2)) + (3*ArcTanh[a*x]^2)/(8*a) - (3*ArcTanh[a*x]^2)/(4*a*(1 - a^2*x^2)) + (x*ArcTanh[a*x]^3)/(2*(1 - a^2*x^2)) + ArcTanh[a*x]^4/(8*a)}
{ArcTanh[a*x]^3/(x*(1 - a^2*x^2)^2), x, 11, -((3*a*x)/(8*(1 - a^2*x^2))) - (3/8)*ArcTanh[a*x] + (3*ArcTanh[a*x])/(4*(1 - a^2*x^2)) - (3*a*x*ArcTanh[a*x]^2)/(4*(1 - a^2*x^2)) - (1/4)*ArcTanh[a*x]^3 + ArcTanh[a*x]^3/(2*(1 - a^2*x^2)) + (1/4)*ArcTanh[a*x]^4 + ArcTanh[a*x]^3*Log[(2*a*x)/(1 + a*x)] - (3/2)*ArcTanh[a*x]^2*PolyLog[2, 1 - (2*a*x)/(1 + a*x)] - (3/2)*ArcTanh[a*x]*PolyLog[3, 1 - (2*a*x)/(1 + a*x)] - (3/4)*PolyLog[4, 1 - (2*a*x)/(1 + a*x)]}
{ArcTanh[a*x]^3/(x^2*(1 - a^2*x^2)^2), x, 12, -((3*a)/(8*(1 - a^2*x^2))) + (3*a^2*x*ArcTanh[a*x])/(4*(1 - a^2*x^2)) + (3/8)*a*ArcTanh[a*x]^2 - (3*a*ArcTanh[a*x]^2)/(4*(1 - a^2*x^2)) + a*ArcTanh[a*x]^3 - ArcTanh[a*x]^3/x + (a^2*x*ArcTanh[a*x]^3)/(2*(1 - a^2*x^2)) + (3/8)*a*ArcTanh[a*x]^4 + 3*a*ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)] - 3*a*ArcTanh[a*x]*PolyLog[2, 1 - (2*a*x)/(1 + a*x)] - (3/2)*a*PolyLog[3, 1 - (2*a*x)/(1 + a*x)]}
{ArcTanh[a*x]^3/(x^3*(1 - a^2*x^2)^2), x, 25, -((3*a^3*x)/(8*(1 - a^2*x^2))) - (3/8)*a^2*ArcTanh[a*x] + (3*a^2*ArcTanh[a*x])/(4*(1 - a^2*x^2)) + (3/2)*a^2*ArcTanh[a*x]^2 - (3*a*ArcTanh[a*x]^2)/(2*x) - (3*a^3*x*ArcTanh[a*x]^2)/(4*(1 - a^2*x^2)) + (1/4)*a^2*ArcTanh[a*x]^3 - ArcTanh[a*x]^3/(2*x^2) + (a^2*ArcTanh[a*x]^3)/(2*(1 - a^2*x^2)) + (1/2)*a^2*ArcTanh[a*x]^4 + 3*a^2*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)] + 2*a^2*ArcTanh[a*x]^3*Log[(2*a*x)/(1 + a*x)] - (3/2)*a^2*PolyLog[2, 1 - (2*a*x)/(1 + a*x)] - 3*a^2*ArcTanh[a*x]^2*PolyLog[2, 1 - (2*a*x)/(1 + a*x)] - 3*a^2*ArcTanh[a*x]*PolyLog[3, 1 - (2*a*x)/(1 + a*x)] - (3/2)*a^2*PolyLog[4, 1 - (2*a*x)/(1 + a*x)]}


{Sqrt[ArcTanh[a*x]]/(1 - a^2*x^2)^2, x, 7, ArcTanh[a*x]^(3/2)/(3*a) + (Sqrt[Pi/2]*Erf[Sqrt[2]*Sqrt[ArcTanh[a*x]]])/(16*a) - (Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[ArcTanh[a*x]]])/(16*a) + (Sqrt[ArcTanh[a*x]]*Sinh[2*ArcTanh[a*x]])/(4*a)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{x^4/((1 - a^2*x^2)^2*ArcTanh[a*x]), x, 0, CoshIntegral[2*ArcTanh[a*x]]/(2*a^5) - (3*Log[ArcTanh[a*x]])/(2*a^5) + Defer[Int][ArcTanh[a*x]^(-1), x]/a^4, Defer[Int][x^4/((1 - a^2*x^2)^2*ArcTanh[a*x]), x]}
{x^3/((1 - a^2*x^2)^2*ArcTanh[a*x]), x, 0, SinhIntegral[2*ArcTanh[a*x]]/(2*a^4) - Defer[Int][x/((1 - a^2*x^2)*ArcTanh[a*x]), x]/a^2, Defer[Int][x^3/((1 - a^2*x^2)^2*ArcTanh[a*x]), x]}
{x^2/((1 - a^2*x^2)^2*ArcTanh[a*x]), x, 3, CoshIntegral[2*ArcTanh[a*x]]/(2*a^3) - Log[ArcTanh[a*x]]/(2*a^3)}
{x/((1 - a^2*x^2)^2*ArcTanh[a*x]), x, 3, SinhIntegral[2*ArcTanh[a*x]]/(2*a^2)}
{1/((1 - a^2*x^2)^2*ArcTanh[a*x]), x, 3, CoshIntegral[2*ArcTanh[a*x]]/(2*a) + Log[ArcTanh[a*x]]/(2*a)}
{1/(x*(1 - a^2*x^2)^2*ArcTanh[a*x]), x, 0, SinhIntegral[2*ArcTanh[a*x]]/2 + Defer[Int][1/(x*(1 - a^2*x^2)*ArcTanh[a*x]), x], Defer[Int][1/(x*(1 - a^2*x^2)^2*ArcTanh[a*x]), x]}


{x^3/((1 - a^2*x^2)^2*ArcTanh[a*x]^2), x, 4, x/(a^3*ArcTanh[a*x]) - x/(a^3*(1 - a^2*x^2)*ArcTanh[a*x]) + CoshIntegral[2*ArcTanh[a*x]]/a^4 - Int[1/ArcTanh[a*x], x]/a^3}
{x^2/((1 - a^2*x^2)^2*ArcTanh[a*x]^2), x, 4, -(x^2/(a*(1 - a^2*x^2)*ArcTanh[a*x])) + SinhIntegral[2*ArcTanh[a*x]]/a^3}
{x/((1 - a^2*x^2)^2*ArcTanh[a*x]^2), x, 2, -(x/(a*(1 - a^2*x^2)*ArcTanh[a*x])) + CoshIntegral[2*ArcTanh[a*x]]/a^2}
{1/((1 - a^2*x^2)^2*ArcTanh[a*x]^2), x, 4, -(1/(a*(1 - a^2*x^2)*ArcTanh[a*x])) + SinhIntegral[2*ArcTanh[a*x]]/a}
{1/(x*(1 - a^2*x^2)^2*ArcTanh[a*x]^2), x, 4, -(1/(a*x*ArcTanh[a*x])) - (a*x)/((1 - a^2*x^2)*ArcTanh[a*x]) + CoshIntegral[2*ArcTanh[a*x]] - Int[1/(x^2*ArcTanh[a*x]), x]/a}


{x^3/((1 - a^2*x^2)^2*ArcTanh[a*x]^3), x, 6, x/(2*a^3*ArcTanh[a*x]^2) - x/(2*a^3*(1 - a^2*x^2)*ArcTanh[a*x]^2) - (1 + a^2*x^2)/(2*a^4*(1 - a^2*x^2)*ArcTanh[a*x]) + SinhIntegral[2*ArcTanh[a*x]]/a^4 - Defer[Int][1/ArcTanh[a*x]^2, x]/(2*a^3)}
{x^2/((1 - a^2*x^2)^2*ArcTanh[a*x]^3), x, 3, -(x^2/(2*a*(1 - a^2*x^2)*ArcTanh[a*x]^2)) - x/(a^2*(1 - a^2*x^2)*ArcTanh[a*x]) + CoshIntegral[2*ArcTanh[a*x]]/a^3}
{x/((1 - a^2*x^2)^2*ArcTanh[a*x]^3), x, 4, -(x/(2*a*(1 - a^2*x^2)*ArcTanh[a*x]^2)) - (1 + a^2*x^2)/(2*a^2*(1 - a^2*x^2)*ArcTanh[a*x]) + SinhIntegral[2*ArcTanh[a*x]]/a^2}
{1/((1 - a^2*x^2)^2*ArcTanh[a*x]^3), x, 3, -(1/(2*a*(1 - a^2*x^2)*ArcTanh[a*x]^2)) - x/((1 - a^2*x^2)*ArcTanh[a*x]) + CoshIntegral[2*ArcTanh[a*x]]/a}
{1/(x*(1 - a^2*x^2)^2*ArcTanh[a*x]^3), x, 6, -(1/(2*a*x*ArcTanh[a*x]^2)) - (a*x)/(2*(1 - a^2*x^2)*ArcTanh[a*x]^2) - (1 + a^2*x^2)/(2*(1 - a^2*x^2)*ArcTanh[a*x]) - Int[1/(x^2*ArcTanh[a*x]^2), x]/(2*a) + SinhIntegral[2*ArcTanh[a*x]]}


{1/((1 - a^2*x^2)^2*ArcTanh[a*x]^4), x, 5, -(1/(3*a*(1 - a^2*x^2)*ArcTanh[a*x]^3)) - x/(3*(1 - a^2*x^2)*ArcTanh[a*x]^2) - (1 + a^2*x^2)/(3*a*(1 - a^2*x^2)*ArcTanh[a*x]) + (2*SinhIntegral[2*ArcTanh[a*x]])/(3*a)}
{1/((1 - a^2*x^2)^2*ArcTanh[a*x]^5), x, 4, -(1/(4*a*(1 - a^2*x^2)*ArcTanh[a*x]^4)) - x/(6*(1 - a^2*x^2)*ArcTanh[a*x]^3) - (1 + a^2*x^2)/(12*a*(1 - a^2*x^2)*ArcTanh[a*x]^2) - x/(3*(1 - a^2*x^2)*ArcTanh[a*x]) + CoshIntegral[2*ArcTanh[a*x]]/(3*a)}
{1/((1 - a^2*x^2)^2*ArcTanh[a*x]^6), x, 6, -(1/(5*a*(1 - a^2*x^2)*ArcTanh[a*x]^5)) - x/(10*(1 - a^2*x^2)*ArcTanh[a*x]^4) - (1 + a^2*x^2)/(30*a*(1 - a^2*x^2)*ArcTanh[a*x]^3) - x/(15*(1 - a^2*x^2)*ArcTanh[a*x]^2) - (1 + a^2*x^2)/(15*a*(1 - a^2*x^2)*ArcTanh[a*x]) + (2*SinhIntegral[2*ArcTanh[a*x]])/(15*a)}
{1/((1 - a^2*x^2)^2*ArcTanh[a*x]^7), x, 5, -(1/(6*a*(1 - a^2*x^2)*ArcTanh[a*x]^6)) - x/(15*(1 - a^2*x^2)*ArcTanh[a*x]^5) - (1 + a^2*x^2)/(60*a*(1 - a^2*x^2)*ArcTanh[a*x]^4) - x/(45*(1 - a^2*x^2)*ArcTanh[a*x]^3) - (1 + a^2*x^2)/(90*a*(1 - a^2*x^2)*ArcTanh[a*x]^2) - (2*x)/(45*(1 - a^2*x^2)*ArcTanh[a*x]) + (2*CoshIntegral[2*ArcTanh[a*x]])/(45*a)}
{1/((1 - a^2*x^2)^2*ArcTanh[a*x]^8), x, 7, -(1/(7*a*(1 - a^2*x^2)*ArcTanh[a*x]^7)) - x/(21*(1 - a^2*x^2)*ArcTanh[a*x]^6) - (1 + a^2*x^2)/(105*a*(1 - a^2*x^2)*ArcTanh[a*x]^5) - x/(105*(1 - a^2*x^2)*ArcTanh[a*x]^4) - (1 + a^2*x^2)/(315*a*(1 - a^2*x^2)*ArcTanh[a*x]^3) - (2*x)/(315*(1 - a^2*x^2)*ArcTanh[a*x]^2) - (2*(1 + a^2*x^2))/(315*a*(1 - a^2*x^2)*ArcTanh[a*x]) + (4*SinhIntegral[2*ArcTanh[a*x]])/(315*a)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcTanh[a x]^n / (1-a^2 x^2)^3*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{x^3*ArcTanh[a*x]/(1 - a^2*x^2)^3, x, 8, -(x/(16*a^3*(1 - a^2*x^2)^2)) + (5*x)/(32*a^3*(1 - a^2*x^2)) + (5*ArcTanh[a*x])/(32*a^4) + ArcTanh[a*x]/(4*a^4*(1 - a^2*x^2)^2) - ArcTanh[a*x]/(2*a^4*(1 - a^2*x^2))}
{x^2*ArcTanh[a*x]/(1 - a^2*x^2)^3, x, 6, -(1/(16*a^3*(1 - a^2*x^2)^2)) + 1/(16*a^3*(1 - a^2*x^2)) + (x*ArcTanh[a*x])/(4*a^2*(1 - a^2*x^2)^2) - (x*ArcTanh[a*x])/(8*a^2*(1 - a^2*x^2)) - ArcTanh[a*x]^2/(16*a^3)}
{x*ArcTanh[a*x]/(1 - a^2*x^2)^3, x, 4, -(x/(16*a*(1 - a^2*x^2)^2)) - (3*x)/(32*a*(1 - a^2*x^2)) - (3*ArcTanh[a*x])/(32*a^2) + ArcTanh[a*x]/(4*a^2*(1 - a^2*x^2)^2)}
{ArcTanh[a*x]/(1 - a^2*x^2)^3, x, 3, -(1/(16*a*(1 - a^2*x^2)^2)) - 3/(16*a*(1 - a^2*x^2)) + (x*ArcTanh[a*x])/(4*(1 - a^2*x^2)^2) + (3*x*ArcTanh[a*x])/(8*(1 - a^2*x^2)) + (3*ArcTanh[a*x]^2)/(16*a)}
{ArcTanh[a*x]/(x*(1 - a^2*x^2)^3), x, 12, -((a*x)/(16*(1 - a^2*x^2)^2)) - (11*a*x)/(32*(1 - a^2*x^2)) - (11/32)*ArcTanh[a*x] + ArcTanh[a*x]/(4*(1 - a^2*x^2)^2) + ArcTanh[a*x]/(2*(1 - a^2*x^2)) + (1/2)*ArcTanh[a*x]^2 + ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)] - (1/2)*PolyLog[2, 1 - (2*a*x)/(1 + a*x)]}
{ArcTanh[a*x]/(x^2*(1 - a^2*x^2)^3), x, 10, -(a/(16*(1 - a^2*x^2)^2)) - (7*a)/(16*(1 - a^2*x^2)) - ArcTanh[a*x]/x + (a^2*x*ArcTanh[a*x])/(4*(1 - a^2*x^2)^2) + (7*a^2*x*ArcTanh[a*x])/(8*(1 - a^2*x^2)) + (15/16)*a*ArcTanh[a*x]^2 - a*ArcTanh[1 - 2*a^2*x^2]}


{x^3*ArcTanh[a*x]^2/(1 - a^2*x^2)^3, x, 8, 1/(32*a^4*(1 - a^2*x^2)^2) - 5/(32*a^4*(1 - a^2*x^2)) - (x*ArcTanh[a*x])/(8*a^3*(1 - a^2*x^2)^2) + (5*x*ArcTanh[a*x])/(16*a^3*(1 - a^2*x^2)) + (5*ArcTanh[a*x]^2)/(32*a^4) + ArcTanh[a*x]^2/(4*a^4*(1 - a^2*x^2)^2) - ArcTanh[a*x]^2/(2*a^4*(1 - a^2*x^2))}
{x^2*ArcTanh[a*x]^2/(1 - a^2*x^2)^3, x, 13, x/(32*a^2*(1 - a^2*x^2)^2) - x/(64*a^2*(1 - a^2*x^2)) - ArcTanh[a*x]/(64*a^3) - ArcTanh[a*x]/(8*a^3*(1 - a^2*x^2)^2) + ArcTanh[a*x]/(8*a^3*(1 - a^2*x^2)) + (x*ArcTanh[a*x]^2)/(4*a^2*(1 - a^2*x^2)^2) - (x*ArcTanh[a*x]^2)/(8*a^2*(1 - a^2*x^2)) - ArcTanh[a*x]^3/(24*a^3)}
{x*ArcTanh[a*x]^2/(1 - a^2*x^2)^3, x, 4, 1/(32*a^2*(1 - a^2*x^2)^2) + 3/(32*a^2*(1 - a^2*x^2)) - (x*ArcTanh[a*x])/(8*a*(1 - a^2*x^2)^2) - (3*x*ArcTanh[a*x])/(16*a*(1 - a^2*x^2)) - (3*ArcTanh[a*x]^2)/(32*a^2) + ArcTanh[a*x]^2/(4*a^2*(1 - a^2*x^2)^2)}
{ArcTanh[a*x]^2/(1 - a^2*x^2)^3, x, 8, x/(32*(1 - a^2*x^2)^2) + (15*x)/(64*(1 - a^2*x^2)) + (15*ArcTanh[a*x])/(64*a) - ArcTanh[a*x]/(8*a*(1 - a^2*x^2)^2) - (3*ArcTanh[a*x])/(8*a*(1 - a^2*x^2)) + (x*ArcTanh[a*x]^2)/(4*(1 - a^2*x^2)^2) + (3*x*ArcTanh[a*x]^2)/(8*(1 - a^2*x^2)) + ArcTanh[a*x]^3/(8*a)}
{ArcTanh[a*x]^2/(x*(1 - a^2*x^2)^3), x, 13, 1/(32*(1 - a^2*x^2)^2) + 11/(32*(1 - a^2*x^2)) - (a*x*ArcTanh[a*x])/(8*(1 - a^2*x^2)^2) - (11*a*x*ArcTanh[a*x])/(16*(1 - a^2*x^2)) - (11/32)*ArcTanh[a*x]^2 + ArcTanh[a*x]^2/(4*(1 - a^2*x^2)^2) + ArcTanh[a*x]^2/(2*(1 - a^2*x^2)) + (1/3)*ArcTanh[a*x]^3 + ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)] - ArcTanh[a*x]*PolyLog[2, 1 - (2*a*x)/(1 + a*x)] - (1/2)*PolyLog[3, 1 - (2*a*x)/(1 + a*x)]}
{ArcTanh[a*x]^2/(x^2*(1 - a^2*x^2)^3), x, 20, (a^2*x)/(32*(1 - a^2*x^2)^2) + (31*a^2*x)/(64*(1 - a^2*x^2)) + (31/64)*a*ArcTanh[a*x] - (a*ArcTanh[a*x])/(8*(1 - a^2*x^2)^2) - (7*a*ArcTanh[a*x])/(8*(1 - a^2*x^2)) + a*ArcTanh[a*x]^2 - ArcTanh[a*x]^2/x + (a^2*x*ArcTanh[a*x]^2)/(4*(1 - a^2*x^2)^2) + (7*a^2*x*ArcTanh[a*x]^2)/(8*(1 - a^2*x^2)) + (5/8)*a*ArcTanh[a*x]^3 + 2*a*ArcTanh[a*x]*Log[(2*a*x)/(1 + a*x)] - a*PolyLog[2, 1 - (2*a*x)/(1 + a*x)]}


{x^3*ArcTanh[a*x]^3/(1 - a^2*x^2)^3, x, 15, -((3*x)/(128*a^3*(1 - a^2*x^2)^2)) + (51*x)/(256*a^3*(1 - a^2*x^2)) + (51*ArcTanh[a*x])/(256*a^4) + (3*ArcTanh[a*x])/(32*a^4*(1 - a^2*x^2)^2) - (15*ArcTanh[a*x])/(32*a^4*(1 - a^2*x^2)) - (3*x*ArcTanh[a*x]^2)/(16*a^3*(1 - a^2*x^2)^2) + (15*x*ArcTanh[a*x]^2)/(32*a^3*(1 - a^2*x^2)) + (5*ArcTanh[a*x]^3)/(32*a^4) + ArcTanh[a*x]^3/(4*a^4*(1 - a^2*x^2)^2) - ArcTanh[a*x]^3/(2*a^4*(1 - a^2*x^2))}
{x^2*ArcTanh[a*x]^3/(1 - a^2*x^2)^3, x, 13, -(3/(128*a^3*(1 - a^2*x^2)^2)) + 3/(128*a^3*(1 - a^2*x^2)) + (3*x*ArcTanh[a*x])/(32*a^2*(1 - a^2*x^2)^2) - (3*x*ArcTanh[a*x])/(64*a^2*(1 - a^2*x^2)) - (3*ArcTanh[a*x]^2)/(128*a^3) - (3*ArcTanh[a*x]^2)/(16*a^3*(1 - a^2*x^2)^2) + (3*ArcTanh[a*x]^2)/(16*a^3*(1 - a^2*x^2)) + (x*ArcTanh[a*x]^3)/(4*a^2*(1 - a^2*x^2)^2) - (x*ArcTanh[a*x]^3)/(8*a^2*(1 - a^2*x^2)) - ArcTanh[a*x]^4/(32*a^3)}
{x*ArcTanh[a*x]^3/(1 - a^2*x^2)^3, x, 9, -((3*x)/(128*a*(1 - a^2*x^2)^2)) - (45*x)/(256*a*(1 - a^2*x^2)) - (45*ArcTanh[a*x])/(256*a^2) + (3*ArcTanh[a*x])/(32*a^2*(1 - a^2*x^2)^2) + (9*ArcTanh[a*x])/(32*a^2*(1 - a^2*x^2)) - (3*x*ArcTanh[a*x]^2)/(16*a*(1 - a^2*x^2)^2) - (9*x*ArcTanh[a*x]^2)/(32*a*(1 - a^2*x^2)) - (3*ArcTanh[a*x]^3)/(32*a^2) + ArcTanh[a*x]^3/(4*a^2*(1 - a^2*x^2)^2)}
{ArcTanh[a*x]^3/(1 - a^2*x^2)^3, x, 8, -(3/(128*a*(1 - a^2*x^2)^2)) - 45/(128*a*(1 - a^2*x^2)) + (3*x*ArcTanh[a*x])/(32*(1 - a^2*x^2)^2) + (45*x*ArcTanh[a*x])/(64*(1 - a^2*x^2)) + (45*ArcTanh[a*x]^2)/(128*a) - (3*ArcTanh[a*x]^2)/(16*a*(1 - a^2*x^2)^2) - (9*ArcTanh[a*x]^2)/(16*a*(1 - a^2*x^2)) + (x*ArcTanh[a*x]^3)/(4*(1 - a^2*x^2)^2) + (3*x*ArcTanh[a*x]^3)/(8*(1 - a^2*x^2)) + (3*ArcTanh[a*x]^4)/(32*a)}
{ArcTanh[a*x]^3/(x*(1 - a^2*x^2)^3), x, 21, -((3*a*x)/(128*(1 - a^2*x^2)^2)) - (141*a*x)/(256*(1 - a^2*x^2)) - (141/256)*ArcTanh[a*x] + (3*ArcTanh[a*x])/(32*(1 - a^2*x^2)^2) + (33*ArcTanh[a*x])/(32*(1 - a^2*x^2)) - (3*a*x*ArcTanh[a*x]^2)/(16*(1 - a^2*x^2)^2) - (33*a*x*ArcTanh[a*x]^2)/(32*(1 - a^2*x^2)) - (11/32)*ArcTanh[a*x]^3 + ArcTanh[a*x]^3/(4*(1 - a^2*x^2)^2) + ArcTanh[a*x]^3/(2*(1 - a^2*x^2)) + (1/4)*ArcTanh[a*x]^4 + ArcTanh[a*x]^3*Log[(2*a*x)/(1 + a*x)] - (3/2)*ArcTanh[a*x]^2*PolyLog[2, 1 - (2*a*x)/(1 + a*x)] - (3/2)*ArcTanh[a*x]*PolyLog[3, 1 - (2*a*x)/(1 + a*x)] - (3/4)*PolyLog[4, 1 - (2*a*x)/(1 + a*x)]}
{ArcTanh[a*x]^3/(x^2*(1 - a^2*x^2)^3), x, 21, -((3*a)/(128*(1 - a^2*x^2)^2)) - (93*a)/(128*(1 - a^2*x^2)) + (3*a^2*x*ArcTanh[a*x])/(32*(1 - a^2*x^2)^2) + (93*a^2*x*ArcTanh[a*x])/(64*(1 - a^2*x^2)) + (93/128)*a*ArcTanh[a*x]^2 - (3*a*ArcTanh[a*x]^2)/(16*(1 - a^2*x^2)^2) - (21*a*ArcTanh[a*x]^2)/(16*(1 - a^2*x^2)) + a*ArcTanh[a*x]^3 - ArcTanh[a*x]^3/x + (a^2*x*ArcTanh[a*x]^3)/(4*(1 - a^2*x^2)^2) + (7*a^2*x*ArcTanh[a*x]^3)/(8*(1 - a^2*x^2)) + (15/32)*a*ArcTanh[a*x]^4 + 3*a*ArcTanh[a*x]^2*Log[(2*a*x)/(1 + a*x)] - 3*a*ArcTanh[a*x]*PolyLog[2, 1 - (2*a*x)/(1 + a*x)] - (3/2)*a*PolyLog[3, 1 - (2*a*x)/(1 + a*x)]}


{Sqrt[ArcTanh[a*x]]/(1 - a^2*x^2)^3, x, 11, ArcTanh[a*x]^(3/2)/(4*a) + (Sqrt[Pi]*Erf[2*Sqrt[ArcTanh[a*x]]])/(256*a) + (Sqrt[Pi/2]*Erf[Sqrt[2]*Sqrt[ArcTanh[a*x]]])/(16*a) - (Sqrt[Pi]*Erfi[2*Sqrt[ArcTanh[a*x]]])/(256*a) - (Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[ArcTanh[a*x]]])/(16*a) + (Sqrt[ArcTanh[a*x]]*Sinh[2*ArcTanh[a*x]])/(4*a) + (Sqrt[ArcTanh[a*x]]*Sinh[4*ArcTanh[a*x]])/(32*a)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{x^6/((1 - a^2*x^2)^3*ArcTanh[a*x]), x, 0, Defer[Int][x^6/((1 - a^2*x^2)^3*ArcTanh[a*x]), x]}
{x^5/((1 - a^2*x^2)^3*ArcTanh[a*x]), x, 0, Defer[Int][x^5/((1 - a^2*x^2)^3*ArcTanh[a*x]), x]}
{x^4/((1 - a^2*x^2)^3*ArcTanh[a*x]), x, 4, -(CoshIntegral[2*ArcTanh[a*x]]/(2*a^5)) + CoshIntegral[4*ArcTanh[a*x]]/(8*a^5) + (3*Log[ArcTanh[a*x]])/(8*a^5)}
{x^3/((1 - a^2*x^2)^3*ArcTanh[a*x]), x, 4, -(SinhIntegral[2*ArcTanh[a*x]]/(4*a^4)) + SinhIntegral[4*ArcTanh[a*x]]/(8*a^4)}
{x^2/((1 - a^2*x^2)^3*ArcTanh[a*x]), x, 3, CoshIntegral[4*ArcTanh[a*x]]/(8*a^3) - Log[ArcTanh[a*x]]/(8*a^3)}
{x/((1 - a^2*x^2)^3*ArcTanh[a*x]), x, 4, SinhIntegral[2*ArcTanh[a*x]]/(4*a^2) + SinhIntegral[4*ArcTanh[a*x]]/(8*a^2)}
{1/((1 - a^2*x^2)^3*ArcTanh[a*x]), x, 4, CoshIntegral[2*ArcTanh[a*x]]/(2*a) + CoshIntegral[4*ArcTanh[a*x]]/(8*a) + (3*Log[ArcTanh[a*x]])/(8*a)}
{1/(x*(1 - a^2*x^2)^3*ArcTanh[a*x]), x, 0, (3*SinhIntegral[2*ArcTanh[a*x]])/4 + SinhIntegral[4*ArcTanh[a*x]]/8 - Defer[Int][1/(x*(-1 + a^2*x^2)*ArcTanh[a*x]), x], Defer[Int][1/(x*(1 - a^2*x^2)^3*ArcTanh[a*x]), x]}


{x^5/((1 - a^2*x^2)^3*ArcTanh[a*x]^2), x, 12, -(x/(a^5*ArcTanh[a*x])) - x/(a^5*(1 - a^2*x^2)^2*ArcTanh[a*x]) + (2*x)/(a^5*(1 - a^2*x^2)*ArcTanh[a*x]) - (3*CoshIntegral[2*ArcTanh[a*x]])/(2*a^6) + CoshIntegral[4*ArcTanh[a*x]]/(2*a^6) + Defer[Int][1/ArcTanh[a*x], x]/a^5}
{x^4/((1 - a^2*x^2)^3*ArcTanh[a*x]^2), x, 5, -(x^4/(a*(1 - a^2*x^2)^2*ArcTanh[a*x])) - SinhIntegral[2*ArcTanh[a*x]]/a^5 + SinhIntegral[4*ArcTanh[a*x]]/(2*a^5)}
{x^3/((1 - a^2*x^2)^3*ArcTanh[a*x]^2), x, 7, -(x^3/(a*(1 - a^2*x^2)^2*ArcTanh[a*x])) - CoshIntegral[2*ArcTanh[a*x]]/(2*a^4) + CoshIntegral[4*ArcTanh[a*x]]/(2*a^4), -(x/(a^3*(1 - a^2*x^2)^2*ArcTanh[a*x])) + x/(a^3*(1 - a^2*x^2)*ArcTanh[a*x]) - CoshIntegral[2*ArcTanh[a*x]]/(2*a^4) + CoshIntegral[4*ArcTanh[a*x]]/(2*a^4)}
{x^2/((1 - a^2*x^2)^3*ArcTanh[a*x]^2), x, 10, -(x^2/(a*(1 - a^2*x^2)^2*ArcTanh[a*x])) + SinhIntegral[4*ArcTanh[a*x]]/(2*a^3), -(1/(a^3*(1 - a^2*x^2)^2*ArcTanh[a*x])) + 1/(a^3*(1 - a^2*x^2)*ArcTanh[a*x]) + SinhIntegral[4*ArcTanh[a*x]]/(2*a^3)}
{x/((1 - a^2*x^2)^3*ArcTanh[a*x]^2), x, 4, -(x/(a*(1 - a^2*x^2)^2*ArcTanh[a*x])) + CoshIntegral[2*ArcTanh[a*x]]/(2*a^2) + CoshIntegral[4*ArcTanh[a*x]]/(2*a^2)}
{1/((1 - a^2*x^2)^3*ArcTanh[a*x]^2), x, 5, -(1/(a*(1 - a^2*x^2)^2*ArcTanh[a*x])) + SinhIntegral[2*ArcTanh[a*x]]/a + SinhIntegral[4*ArcTanh[a*x]]/(2*a)}
{1/(x*(1 - a^2*x^2)^3*ArcTanh[a*x]^2), x, 9, -(1/(a*x*ArcTanh[a*x])) - (a*x)/((1 - a^2*x^2)^2*ArcTanh[a*x]) - (a*x)/((1 - a^2*x^2)*ArcTanh[a*x]) + (3/2)*CoshIntegral[2*ArcTanh[a*x]] + (1/2)*CoshIntegral[4*ArcTanh[a*x]] - Defer[Int][1/(x^2*ArcTanh[a*x]), x]/a}


{x^4/((1 - a^2*x^2)^3*ArcTanh[a*x]^3), x, 8, -(x^4/(2*a*(1 - a^2*x^2)^2*ArcTanh[a*x]^2)) - (2*x)/(a^4*(1 - a^2*x^2)^2*ArcTanh[a*x]) + (2*x)/(a^4*(1 - a^2*x^2)*ArcTanh[a*x]) - CoshIntegral[2*ArcTanh[a*x]]/a^5 + CoshIntegral[4*ArcTanh[a*x]]/a^5}
{x^3/((1 - a^2*x^2)^3*ArcTanh[a*x]^3), x, 21, -(x^3/(2*a*(1 - a^2*x^2)^2*ArcTanh[a*x]^2)) - (3*x^2)/(2*a^2*(1 - a^2*x^2)^2*ArcTanh[a*x]) - x^4/(2*(1 - a^2*x^2)^2*ArcTanh[a*x]) - SinhIntegral[2*ArcTanh[a*x]]/(2*a^4) + SinhIntegral[4*ArcTanh[a*x]]/a^4, -(x/(2*a^3*(1 - a^2*x^2)^2*ArcTanh[a*x]^2)) + x/(2*a^3*(1 - a^2*x^2)*ArcTanh[a*x]^2) - 2/(a^4*(1 - a^2*x^2)^2*ArcTanh[a*x]) + 3/(2*a^4*(1 - a^2*x^2)*ArcTanh[a*x]) + (1 + a^2*x^2)/(2*a^4*(1 - a^2*x^2)*ArcTanh[a*x]) - SinhIntegral[2*ArcTanh[a*x]]/(2*a^4) + SinhIntegral[4*ArcTanh[a*x]]/a^4}
{x^2/((1 - a^2*x^2)^3*ArcTanh[a*x]^3), x, 9, -(x^2/(2*a*(-1 + a^2*x^2)^2*ArcTanh[a*x]^2)) - (2*x)/(a^2*(1 - a^2*x^2)^2*ArcTanh[a*x]) + x/(a^2*(1 - a^2*x^2)*ArcTanh[a*x]) + CoshIntegral[4*ArcTanh[a*x]]/a^3, -(1/(2*a^3*(1 - a^2*x^2)^2*ArcTanh[a*x]^2)) + 1/(2*a^3*(1 - a^2*x^2)*ArcTanh[a*x]^2) - (2*x)/(a^2*(1 - a^2*x^2)^2*ArcTanh[a*x]) + x/(a^2*(1 - a^2*x^2)*ArcTanh[a*x]) + CoshIntegral[4*ArcTanh[a*x]]/a^3}
{x/((1 - a^2*x^2)^3*ArcTanh[a*x]^3), x, 16, -(x/(2*a*(1 - a^2*x^2)^2*ArcTanh[a*x]^2)) - 2/(a^2*(1 - a^2*x^2)^2*ArcTanh[a*x]) + 3/(2*a^2*(1 - a^2*x^2)*ArcTanh[a*x]) + SinhIntegral[2*ArcTanh[a*x]]/(2*a^2) + SinhIntegral[4*ArcTanh[a*x]]/a^2}
{1/((1 - a^2*x^2)^3*ArcTanh[a*x]^3), x, 5, -(1/(2*a*(1 - a^2*x^2)^2*ArcTanh[a*x]^2)) - (2*x)/((1 - a^2*x^2)^2*ArcTanh[a*x]) + CoshIntegral[2*ArcTanh[a*x]]/a + CoshIntegral[4*ArcTanh[a*x]]/a}
{1/(x*(1 - a^2*x^2)^3*ArcTanh[a*x]^3), x, 23, -(1/(2*a*x*ArcTanh[a*x]^2)) - (a*x)/(2*(1 - a^2*x^2)^2*ArcTanh[a*x]^2) - (a*x)/(2*(1 - a^2*x^2)*ArcTanh[a*x]^2) - 2/((1 - a^2*x^2)^2*ArcTanh[a*x]) + 3/(2*(1 - a^2*x^2)*ArcTanh[a*x]) - (1 + a^2*x^2)/(2*(1 - a^2*x^2)*ArcTanh[a*x]) - Int[1/(x^2*ArcTanh[a*x]^2), x]/(2*a) + (3/2)*SinhIntegral[2*ArcTanh[a*x]] + SinhIntegral[4*ArcTanh[a*x]]}


{1/((1 - a^2*x^2)^3*ArcTanh[a*x]^4), x, 17, -(1/(3*a*(1 - a^2*x^2)^2*ArcTanh[a*x]^3)) - (2*x)/(3*(1 - a^2*x^2)^2*ArcTanh[a*x]^2) - 8/(3*a*(1 - a^2*x^2)^2*ArcTanh[a*x]) + 2/(a*(1 - a^2*x^2)*ArcTanh[a*x]) + (2*SinhIntegral[2*ArcTanh[a*x]])/(3*a) + (4*SinhIntegral[4*ArcTanh[a*x]])/(3*a)}
{1/((1 - a^2*x^2)^3*ArcTanh[a*x]^5), x, 16, -(1/(4*a*(1 - a^2*x^2)^2*ArcTanh[a*x]^4)) - x/(3*(1 - a^2*x^2)^2*ArcTanh[a*x]^3) - 2/(3*a*(1 - a^2*x^2)^2*ArcTanh[a*x]^2) + 1/(2*a*(1 - a^2*x^2)*ArcTanh[a*x]^2) - (8*x)/(3*(1 - a^2*x^2)^2*ArcTanh[a*x]) + x/((1 - a^2*x^2)*ArcTanh[a*x]) + CoshIntegral[2*ArcTanh[a*x]]/(3*a) + (4*CoshIntegral[4*ArcTanh[a*x]])/(3*a)}
{1/((1 - a^2*x^2)^3*ArcTanh[a*x]^6), x, 42, -(1/(5*a*(1 - a^2*x^2)^2*ArcTanh[a*x]^5)) - x/(5*(1 - a^2*x^2)^2*ArcTanh[a*x]^4) - 4/(15*a*(1 - a^2*x^2)^2*ArcTanh[a*x]^3) + 1/(5*a*(1 - a^2*x^2)*ArcTanh[a*x]^3) - (8*x)/(15*(1 - a^2*x^2)^2*ArcTanh[a*x]^2) + x/(5*(1 - a^2*x^2)*ArcTanh[a*x]^2) - 32/(15*a*(1 - a^2*x^2)^2*ArcTanh[a*x]) + 8/(5*a*(1 - a^2*x^2)*ArcTanh[a*x]) + (1 + a^2*x^2)/(5*a*(1 - a^2*x^2)*ArcTanh[a*x]) + (2*SinhIntegral[2*ArcTanh[a*x]])/(15*a) + (16*SinhIntegral[4*ArcTanh[a*x]])/(15*a)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcTanh[a x]^n / (1-a^2 x^2)^4*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{ArcTanh[a*x]/(1 - a^2*x^2)^4, x, 4, -(1/(36*a*(1 - a^2*x^2)^3)) - 5/(96*a*(1 - a^2*x^2)^2) - 5/(32*a*(1 - a^2*x^2)) + (x*ArcTanh[a*x])/(6*(1 - a^2*x^2)^3) + (5*x*ArcTanh[a*x])/(24*(1 - a^2*x^2)^2) + (5*x*ArcTanh[a*x])/(16*(1 - a^2*x^2)) + (5*ArcTanh[a*x]^2)/(32*a)}


{ArcTanh[a*x]^2/(1 - a^2*x^2)^4, x, 13, x/(108*(1 - a^2*x^2)^3) + (65*x)/(1728*(1 - a^2*x^2)^2) + (245*x)/(1152*(1 - a^2*x^2)) + (245*ArcTanh[a*x])/(1152*a) - ArcTanh[a*x]/(18*a*(1 - a^2*x^2)^3) - (5*ArcTanh[a*x])/(48*a*(1 - a^2*x^2)^2) - (5*ArcTanh[a*x])/(16*a*(1 - a^2*x^2)) + (x*ArcTanh[a*x]^2)/(6*(1 - a^2*x^2)^3) + (5*x*ArcTanh[a*x]^2)/(24*(1 - a^2*x^2)^2) + (5*x*ArcTanh[a*x]^2)/(16*(1 - a^2*x^2)) + (5*ArcTanh[a*x]^3)/(48*a)}


{ArcTanh[a*x]^3/(1 - a^2*x^2)^4, x, 13, -(1/(216*a*(1 - a^2*x^2)^3)) - 65/(2304*a*(1 - a^2*x^2)^2) - 245/(768*a*(1 - a^2*x^2)) + (x*ArcTanh[a*x])/(36*(1 - a^2*x^2)^3) + (65*x*ArcTanh[a*x])/(576*(1 - a^2*x^2)^2) + (245*x*ArcTanh[a*x])/(384*(1 - a^2*x^2)) + (245*ArcTanh[a*x]^2)/(768*a) - ArcTanh[a*x]^2/(12*a*(1 - a^2*x^2)^3) - (5*ArcTanh[a*x]^2)/(32*a*(1 - a^2*x^2)^2) - (15*ArcTanh[a*x]^2)/(32*a*(1 - a^2*x^2)) + (x*ArcTanh[a*x]^3)/(6*(1 - a^2*x^2)^3) + (5*x*ArcTanh[a*x]^3)/(24*(1 - a^2*x^2)^2) + (5*x*ArcTanh[a*x]^3)/(16*(1 - a^2*x^2)) + (5*ArcTanh[a*x]^4)/(64*a)}


{Sqrt[ArcTanh[a*x]]/(1 - a^2*x^2)^4, x, 15, (5*ArcTanh[a*x]^(3/2))/(24*a) + (3*Sqrt[Pi]*Erf[2*Sqrt[ArcTanh[a*x]]])/(512*a) + (15*Sqrt[Pi/2]*Erf[Sqrt[2]*Sqrt[ArcTanh[a*x]]])/(256*a) + (Sqrt[Pi/6]*Erf[Sqrt[6]*Sqrt[ArcTanh[a*x]]])/(768*a) - (3*Sqrt[Pi]*Erfi[2*Sqrt[ArcTanh[a*x]]])/(512*a) - (15*Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[ArcTanh[a*x]]])/(256*a) - (Sqrt[Pi/6]*Erfi[Sqrt[6]*Sqrt[ArcTanh[a*x]]])/(768*a) + (15*Sqrt[ArcTanh[a*x]]*Sinh[2*ArcTanh[a*x]])/(64*a) + (3*Sqrt[ArcTanh[a*x]]*Sinh[4*ArcTanh[a*x]])/(64*a) + (Sqrt[ArcTanh[a*x]]*Sinh[6*ArcTanh[a*x]])/(192*a)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{x^9/((1 - a^2*x^2)^4*ArcTanh[a*x]), x, 0, Int[x^9/((1 - a^2*x^2)^4*ArcTanh[a*x]), x]}
{x^8/((1 - a^2*x^2)^4*ArcTanh[a*x]), x, 0, Int[x^8/((1 - a^2*x^2)^4*ArcTanh[a*x]), x]}
{x^7/((1 - a^2*x^2)^4*ArcTanh[a*x]), x, 0, Int[x^7/((1 - a^2*x^2)^4*ArcTanh[a*x]), x]}
{x^6/((1 - a^2*x^2)^4*ArcTanh[a*x]), x, 5, (15*CoshIntegral[2*ArcTanh[a*x]])/(32*a^7) - (3*CoshIntegral[4*ArcTanh[a*x]])/(16*a^7) + CoshIntegral[6*ArcTanh[a*x]]/(32*a^7) - (5*Log[ArcTanh[a*x]])/(16*a^7)}
{x^5/((1 - a^2*x^2)^4*ArcTanh[a*x]), x, 5, (5*SinhIntegral[2*ArcTanh[a*x]])/(32*a^6) - SinhIntegral[4*ArcTanh[a*x]]/(8*a^6) + SinhIntegral[6*ArcTanh[a*x]]/(32*a^6)}
{x^4/((1 - a^2*x^2)^4*ArcTanh[a*x]), x, 5, -(CoshIntegral[2*ArcTanh[a*x]]/(32*a^5)) - CoshIntegral[4*ArcTanh[a*x]]/(16*a^5) + CoshIntegral[6*ArcTanh[a*x]]/(32*a^5) + Log[ArcTanh[a*x]]/(16*a^5)}
{x^3/((1 - a^2*x^2)^4*ArcTanh[a*x]), x, 4, -((3*SinhIntegral[2*ArcTanh[a*x]])/(32*a^4)) + SinhIntegral[6*ArcTanh[a*x]]/(32*a^4)}
{x^2/((1 - a^2*x^2)^4*ArcTanh[a*x]), x, 5, -(CoshIntegral[2*ArcTanh[a*x]]/(32*a^3)) + CoshIntegral[4*ArcTanh[a*x]]/(16*a^3) + CoshIntegral[6*ArcTanh[a*x]]/(32*a^3) - Log[ArcTanh[a*x]]/(16*a^3)}
{x^1/((1 - a^2*x^2)^4*ArcTanh[a*x]), x, 5, (5*SinhIntegral[2*ArcTanh[a*x]])/(32*a^2) + SinhIntegral[4*ArcTanh[a*x]]/(8*a^2) + SinhIntegral[6*ArcTanh[a*x]]/(32*a^2)}
{x^0/((1 - a^2*x^2)^4*ArcTanh[a*x]), x, 5, (15*CoshIntegral[2*ArcTanh[a*x]])/(32*a) + (3*CoshIntegral[4*ArcTanh[a*x]])/(16*a) + CoshIntegral[6*ArcTanh[a*x]]/(32*a) + (5*Log[ArcTanh[a*x]])/(16*a)}
{1/(x^1*(1 - a^2*x^2)^4*ArcTanh[a*x]), x, 0, Int[1/(x*(1 - a^2*x^2)^4*ArcTanh[a*x]), x]}
{1/(x^2*(1 - a^2*x^2)^4*ArcTanh[a*x]), x, 0, Int[1/(x^2*(1 - a^2*x^2)^4*ArcTanh[a*x]), x]}
{1/(x^3*(1 - a^2*x^2)^4*ArcTanh[a*x]), x, 0, Int[1/(x^3*(1 - a^2*x^2)^4*ArcTanh[a*x]), x]}


{x/((1 - a^2*x^2)^4*ArcTanh[a*x]^2), x, 5, -(x/(a*(1 - a^2*x^2)^3*ArcTanh[a*x])) + (5*CoshIntegral[2*ArcTanh[a*x]])/(16*a^2) + CoshIntegral[4*ArcTanh[a*x]]/(2*a^2) + (3*CoshIntegral[6*ArcTanh[a*x]])/(16*a^2)}
{1/((1 - a^2*x^2)^4*ArcTanh[a*x]^2), x, 6, -(1/(a*(1 - a^2*x^2)^3*ArcTanh[a*x])) + (15*SinhIntegral[2*ArcTanh[a*x]])/(16*a) + (3*SinhIntegral[4*ArcTanh[a*x]])/(4*a) + (3*SinhIntegral[6*ArcTanh[a*x]])/(16*a)}


{x/((1 - a^2*x^2)^4*ArcTanh[a*x]^3), x, 19, -(x/(2*a*(1 - a^2*x^2)^3*ArcTanh[a*x]^2)) - 3/(a^2*(1 - a^2*x^2)^3*ArcTanh[a*x]) + 5/(2*a^2*(1 - a^2*x^2)^2*ArcTanh[a*x]) + (5*SinhIntegral[2*ArcTanh[a*x]])/(16*a^2) + SinhIntegral[4*ArcTanh[a*x]]/a^2 + (9*SinhIntegral[6*ArcTanh[a*x]])/(16*a^2)}
{1/((1 - a^2*x^2)^4*ArcTanh[a*x]^3), x, 6, -(1/(2*a*(1 - a^2*x^2)^3*ArcTanh[a*x]^2)) - (3*x)/((1 - a^2*x^2)^3*ArcTanh[a*x]) + (15*CoshIntegral[2*ArcTanh[a*x]])/(16*a) + (3*CoshIntegral[4*ArcTanh[a*x]])/(2*a) + (9*CoshIntegral[6*ArcTanh[a*x]])/(16*a)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcTanh[a x]^n / (1-a^2 x^2)^(1/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{x^5*ArcTanh[a*x]/(1 - a^2*x^2)^(1/2), x, 8, -((5*x*Sqrt[1 - a^2*x^2])/(24*a^5)) - (x^3*Sqrt[1 - a^2*x^2])/(20*a^3) + (89*ArcSin[a*x])/(120*a^6) - (8*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(15*a^6) - (4*x^2*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(15*a^4) - (x^4*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(5*a^2)}
{x^4*ArcTanh[a*x]/(1 - a^2*x^2)^(1/2), x, 5, -((5*Sqrt[1 - a^2*x^2])/(8*a^5)) + (1 - a^2*x^2)^(3/2)/(12*a^5) - (5*x*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(8*a^4) + (x*(1 - a^2*x^2)^(3/2)*ArcTanh[a*x])/(4*a^4) - (3*ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x])/(4*a^5) - (3*I*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])])/(8*a^5) + (3*I*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]])/(8*a^5)}
{x^3*ArcTanh[a*x]/(1 - a^2*x^2)^(1/2), x, 5, -((x*Sqrt[1 - a^2*x^2])/(6*a^3)) + (5*ArcSin[a*x])/(6*a^4) - (2*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(3*a^4) - (x^2*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(3*a^2)}
{x^2*ArcTanh[a*x]/(1 - a^2*x^2)^(1/2), x, 3, -(Sqrt[1 - a^2*x^2]/(2*a^3)) - (x*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(2*a^2) - (ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x])/a^3 - (I*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])])/(2*a^3) + (I*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]])/(2*a^3)}
{x^1*ArcTanh[a*x]/(1 - a^2*x^2)^(1/2), x, 2, ArcSin[a*x]/a^2 - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/a^2}
{x^0*ArcTanh[a*x]/(1 - a^2*x^2)^(1/2), x, 1, -((2*ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x])/a) - (I*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])])/a + (I*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]])/a}
{ArcTanh[a*x]/(x^1*(1 - a^2*x^2)^(1/2)), x, 1, -2*ArcTanh[a*x]*ArcTanh[Sqrt[1 + a*x]/Sqrt[1 - a*x]] + 2*PolyLog[2, Sqrt[1 + a*x]/Sqrt[1 - a*x]] - (1/2)*PolyLog[2, (1 + a*x)/(1 - a*x)]}
{ArcTanh[a*x]/(x^2*(1 - a^2*x^2)^(1/2)), x, 3, -((Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/x) - a*ArcTanh[Sqrt[1 - a^2*x^2]]}
{ArcTanh[a*x]/(x^3*(1 - a^2*x^2)^(1/2)), x, 3, -((a*Sqrt[1 - a^2*x^2])/(2*x)) - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(2*x^2) - a^2*ArcTanh[a*x]*ArcTanh[Sqrt[1 + a*x]/Sqrt[1 - a*x]] + a^2*PolyLog[2, Sqrt[1 + a*x]/Sqrt[1 - a*x]] - (1/4)*a^2*PolyLog[2, (1 + a*x)/(1 - a*x)]}


{x^3*ArcTanh[a*x]^2/(1 - a^2*x^2)^(1/2), x, 6, -(Sqrt[1 - a^2*x^2]/(3*a^4)) - (x*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(3*a^3) - (10*ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x])/(3*a^4) - (2*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)/(3*a^4) - (x^2*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)/(3*a^2) - (5*I*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])])/(3*a^4) + (5*I*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]])/(3*a^4)}
{x^2*ArcTanh[a*x]^2/(1 - a^2*x^2)^(1/2), x, 9, ArcSin[a*x]/a^3 - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/a^3 - (x*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)/(2*a^2) + (ArcTan[E^ArcTanh[a*x]]*ArcTanh[a*x]^2)/a^3 - (I*ArcTanh[a*x]*PolyLog[2, (-I)*E^ArcTanh[a*x]])/a^3 + (I*ArcTanh[a*x]*PolyLog[2, I*E^ArcTanh[a*x]])/a^3 + (I*PolyLog[3, (-I)*E^ArcTanh[a*x]])/a^3 - (I*PolyLog[3, I*E^ArcTanh[a*x]])/a^3}
{x^1*ArcTanh[a*x]^2/(1 - a^2*x^2)^(1/2), x, 2, -((4*ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x])/a^2) - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)/a^2 - (2*I*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])])/a^2 + (2*I*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]])/a^2}
{x^0*ArcTanh[a*x]^2/(1 - a^2*x^2)^(1/2), x, 6, (2*ArcTan[E^ArcTanh[a*x]]*ArcTanh[a*x]^2)/a - (2*I*ArcTanh[a*x]*PolyLog[2, (-I)*E^ArcTanh[a*x]])/a + (2*I*ArcTanh[a*x]*PolyLog[2, I*E^ArcTanh[a*x]])/a + (2*I*PolyLog[3, (-I)*E^ArcTanh[a*x]])/a - (2*I*PolyLog[3, I*E^ArcTanh[a*x]])/a}
{ArcTanh[a*x]^2/(x^1*(1 - a^2*x^2)^(1/2)), x, 6, -2*ArcTanh[E^ArcTanh[a*x]]*ArcTanh[a*x]^2 - 2*ArcTanh[a*x]*PolyLog[2, -E^ArcTanh[a*x]] + 2*ArcTanh[a*x]*PolyLog[2, E^ArcTanh[a*x]] + 2*PolyLog[3, -E^ArcTanh[a*x]] - 2*PolyLog[3, E^ArcTanh[a*x]]}
{ArcTanh[a*x]^2/(x^2*(1 - a^2*x^2)^(1/2)), x, 2, -((Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)/x) - 4*a*ArcTanh[a*x]*ArcTanh[Sqrt[1 + a*x]/Sqrt[1 - a*x]] + 4*a*PolyLog[2, Sqrt[1 + a*x]/Sqrt[1 - a*x]] - a*PolyLog[2, (1 + a*x)/(1 - a*x)]}
{ArcTanh[a*x]^2/(x^3*(1 - a^2*x^2)^(1/2)), x, 10, -((a*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/x) - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)/(2*x^2) - a^2*ArcTanh[E^ArcTanh[a*x]]*ArcTanh[a*x]^2 - a^2*ArcTanh[Sqrt[1 - a^2*x^2]] - a^2*ArcTanh[a*x]*PolyLog[2, -E^ArcTanh[a*x]] + a^2*ArcTanh[a*x]*PolyLog[2, E^ArcTanh[a*x]] + a^2*PolyLog[3, -E^ArcTanh[a*x]] - a^2*PolyLog[3, E^ArcTanh[a*x]]}


{x^3*ArcTanh[a*x]^3/(1 - a^2*x^2)^(1/2), x, 17, ArcSin[a*x]/a^4 - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/a^4 - (x*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)/(2*a^3) + (5*ArcTan[E^ArcTanh[a*x]]*ArcTanh[a*x]^2)/a^4 - (2*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^3)/(3*a^4) - (x^2*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^3)/(3*a^2) - (5*I*ArcTanh[a*x]*PolyLog[2, (-I)*E^ArcTanh[a*x]])/a^4 + (5*I*ArcTanh[a*x]*PolyLog[2, I*E^ArcTanh[a*x]])/a^4 + (5*I*PolyLog[3, (-I)*E^ArcTanh[a*x]])/a^4 - (5*I*PolyLog[3, I*E^ArcTanh[a*x]])/a^4}
{x^2*ArcTanh[a*x]^3/(1 - a^2*x^2)^(1/2), x, 11, -((6*ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x])/a^3) - (3*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)/(2*a^3) - (x*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^3)/(2*a^2) + (ArcTan[E^ArcTanh[a*x]]*ArcTanh[a*x]^3)/a^3 - (3*I*ArcTanh[a*x]^2*PolyLog[2, (-I)*E^ArcTanh[a*x]])/(2*a^3) + (3*I*ArcTanh[a*x]^2*PolyLog[2, I*E^ArcTanh[a*x]])/(2*a^3) - (3*I*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])])/a^3 + (3*I*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]])/a^3 + (3*I*ArcTanh[a*x]*PolyLog[3, (-I)*E^ArcTanh[a*x]])/a^3 - (3*I*ArcTanh[a*x]*PolyLog[3, I*E^ArcTanh[a*x]])/a^3 - (3*I*PolyLog[4, (-I)*E^ArcTanh[a*x]])/a^3 + (3*I*PolyLog[4, I*E^ArcTanh[a*x]])/a^3}
{x^1*ArcTanh[a*x]^3/(1 - a^2*x^2)^(1/2), x, 7, (6*ArcTan[E^ArcTanh[a*x]]*ArcTanh[a*x]^2)/a^2 - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^3)/a^2 - (6*I*ArcTanh[a*x]*PolyLog[2, (-I)*E^ArcTanh[a*x]])/a^2 + (6*I*ArcTanh[a*x]*PolyLog[2, I*E^ArcTanh[a*x]])/a^2 + (6*I*PolyLog[3, (-I)*E^ArcTanh[a*x]])/a^2 - (6*I*PolyLog[3, I*E^ArcTanh[a*x]])/a^2}
{x^0*ArcTanh[a*x]^3/(1 - a^2*x^2)^(1/2), x, 8, (2*ArcTan[E^ArcTanh[a*x]]*ArcTanh[a*x]^3)/a - (3*I*ArcTanh[a*x]^2*PolyLog[2, (-I)*E^ArcTanh[a*x]])/a + (3*I*ArcTanh[a*x]^2*PolyLog[2, I*E^ArcTanh[a*x]])/a + (6*I*ArcTanh[a*x]*PolyLog[3, (-I)*E^ArcTanh[a*x]])/a - (6*I*ArcTanh[a*x]*PolyLog[3, I*E^ArcTanh[a*x]])/a - (6*I*PolyLog[4, (-I)*E^ArcTanh[a*x]])/a + (6*I*PolyLog[4, I*E^ArcTanh[a*x]])/a}
{ArcTanh[a*x]^3/(x^1*(1 - a^2*x^2)^(1/2)), x, 8, -2*ArcTanh[E^ArcTanh[a*x]]*ArcTanh[a*x]^3 - 3*ArcTanh[a*x]^2*PolyLog[2, -E^ArcTanh[a*x]] + 3*ArcTanh[a*x]^2*PolyLog[2, E^ArcTanh[a*x]] + 6*ArcTanh[a*x]*PolyLog[3, -E^ArcTanh[a*x]] - 6*ArcTanh[a*x]*PolyLog[3, E^ArcTanh[a*x]] - 6*PolyLog[4, -E^ArcTanh[a*x]] + 6*PolyLog[4, E^ArcTanh[a*x]]}
{ArcTanh[a*x]^3/(x^2*(1 - a^2*x^2)^(1/2)), x, 7, -6*a*ArcTanh[E^ArcTanh[a*x]]*ArcTanh[a*x]^2 - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^3)/x - 6*a*ArcTanh[a*x]*PolyLog[2, -E^ArcTanh[a*x]] + 6*a*ArcTanh[a*x]*PolyLog[2, E^ArcTanh[a*x]] + 6*a*PolyLog[3, -E^ArcTanh[a*x]] - 6*a*PolyLog[3, E^ArcTanh[a*x]]}
{ArcTanh[a*x]^3/(x^3*(1 - a^2*x^2)^(1/2)), x, 11, -((3*a*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)/(2*x)) - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^3)/(2*x^2) - a^2*ArcTanh[E^ArcTanh[a*x]]*ArcTanh[a*x]^3 - 6*a^2*ArcTanh[a*x]*ArcTanh[Sqrt[1 + a*x]/Sqrt[1 - a*x]] - (3/2)*a^2*ArcTanh[a*x]^2*PolyLog[2, -E^ArcTanh[a*x]] + (3/2)*a^2*ArcTanh[a*x]^2*PolyLog[2, E^ArcTanh[a*x]] + 6*a^2*PolyLog[2, Sqrt[1 + a*x]/Sqrt[1 - a*x]] - (3/2)*a^2*PolyLog[2, (1 + a*x)/(1 - a*x)] + 3*a^2*ArcTanh[a*x]*PolyLog[3, -E^ArcTanh[a*x]] - 3*a^2*ArcTanh[a*x]*PolyLog[3, E^ArcTanh[a*x]] - 3*a^2*PolyLog[4, -E^ArcTanh[a*x]] + 3*a^2*PolyLog[4, E^ArcTanh[a*x]]}


(* ::Subsubsection:: *)
(*n<0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcTanh[a x]^n / (1-a^2 x^2)^(3/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{ArcTanh[a*x]/(1 - a^2*x^2)^(3/2)*x^m, x, 0, Defer[Int][(x^m*ArcTanh[a*x])/(1 - a^2*x^2)^(3/2), x]}

{ArcTanh[a*x]/(1 - a^2*x^2)^(3/2)*x^3, x, 5, -(x/(a^3*Sqrt[1 - a^2*x^2])) - ArcSin[a*x]/a^4 + ArcTanh[a*x]/(a^4*Sqrt[1 - a^2*x^2]) + (Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/a^4}
{ArcTanh[a*x]/(1 - a^2*x^2)^(3/2)*x^2, x, 3, -(1/(a^3*Sqrt[1 - a^2*x^2])) + (x*ArcTanh[a*x])/(a^2*Sqrt[1 - a^2*x^2]) + (2*ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x])/a^3 + (I*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])])/a^3 - (I*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]])/a^3} 
{ArcTanh[a*x]/(1 - a^2*x^2)^(3/2)*x^1, x, 2, -(x/(a*Sqrt[1 - a^2*x^2])) + ArcTanh[a*x]/(a^2*Sqrt[1 - a^2*x^2])}
{ArcTanh[a*x]/(1 - a^2*x^2)^(3/2)*x^0, x, 1, -(1/(a*Sqrt[1 - a^2*x^2])) + (x*ArcTanh[a*x])/Sqrt[1 - a^2*x^2]}
{ArcTanh[a*x]/(1 - a^2*x^2)^(3/2)/x^1, x, 4, -((a*x)/Sqrt[1 - a^2*x^2]) + ArcTanh[a*x]/Sqrt[1 - a^2*x^2] - 2*ArcTanh[a*x]*ArcTanh[Sqrt[1 + a*x]/Sqrt[1 - a*x]] + 2*PolyLog[2, Sqrt[1 + a*x]/Sqrt[1 - a*x]] - (1/2)*PolyLog[2, (1 + a*x)/(1 - a*x)]}
{ArcTanh[a*x]/(1 - a^2*x^2)^(3/2)/x^2, x, 5, -(a/Sqrt[1 - a^2*x^2]) + (a^2*x*ArcTanh[a*x])/Sqrt[1 - a^2*x^2] - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/x - a*ArcTanh[Sqrt[1 - a^2*x^2]]}
{ArcTanh[a*x]/(1 - a^2*x^2)^(3/2)/x^3, x, 8, -((a^3*x)/Sqrt[1 - a^2*x^2]) - (a*Sqrt[1 - a^2*x^2])/(2*x) + (a^2*ArcTanh[a*x])/Sqrt[1 - a^2*x^2] - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(2*x^2) - 3*a^2*ArcTanh[a*x]*ArcTanh[Sqrt[1 + a*x]/Sqrt[1 - a*x]] + 3*a^2*PolyLog[2, Sqrt[1 + a*x]/Sqrt[1 - a*x]] - (3/4)*a^2*PolyLog[2, (1 + a*x)/(1 - a*x)]}


{ArcTanh[a*x]^2/(1 - a^2*x^2)^(3/2)*x^m, x, 0, Defer[Int][(x^m*ArcTanh[a*x]^2)/(1 - a^2*x^2)^(3/2), x]}

{ArcTanh[a*x]^2/(1 - a^2*x^2)^(3/2)*x^3, x, 5, 2/(a^4*Sqrt[1 - a^2*x^2]) - (2*x*ArcTanh[a*x])/(a^3*Sqrt[1 - a^2*x^2]) + (4*ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x])/a^4 + ArcTanh[a*x]^2/(a^4*Sqrt[1 - a^2*x^2]) + (Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)/a^4 + (2*I*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])])/a^4 - (2*I*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]])/a^4}
{ArcTanh[a*x]^2/(1 - a^2*x^2)^(3/2)*x^2, x, 9, (2*x)/(a^2*Sqrt[1 - a^2*x^2]) - (2*ArcTanh[a*x])/(a^3*Sqrt[1 - a^2*x^2]) + (x*ArcTanh[a*x]^2)/(a^2*Sqrt[1 - a^2*x^2]) - (2*ArcTan[E^ArcTanh[a*x]]*ArcTanh[a*x]^2)/a^3 + (2*I*ArcTanh[a*x]*PolyLog[2, (-I)*E^ArcTanh[a*x]])/a^3 - (2*I*ArcTanh[a*x]*PolyLog[2, I*E^ArcTanh[a*x]])/a^3 - (2*I*PolyLog[3, (-I)*E^ArcTanh[a*x]])/a^3 + (2*I*PolyLog[3, I*E^ArcTanh[a*x]])/a^3}
{ArcTanh[a*x]^2/(1 - a^2*x^2)^(3/2)*x^1, x, 2, 2/(a^2*Sqrt[1 - a^2*x^2]) - (2*x*ArcTanh[a*x])/(a*Sqrt[1 - a^2*x^2]) + ArcTanh[a*x]^2/(a^2*Sqrt[1 - a^2*x^2])}
{ArcTanh[a*x]^2/(1 - a^2*x^2)^(3/2)*x^0, x, 2, (2*x)/Sqrt[1 - a^2*x^2] - (2*ArcTanh[a*x])/(a*Sqrt[1 - a^2*x^2]) + (x*ArcTanh[a*x]^2)/Sqrt[1 - a^2*x^2]}
{ArcTanh[a*x]^2/(1 - a^2*x^2)^(3/2)/x^1, x, 9, 2/Sqrt[1 - a^2*x^2] - (2*a*x*ArcTanh[a*x])/Sqrt[1 - a^2*x^2] + ArcTanh[a*x]^2/Sqrt[1 - a^2*x^2] - 2*ArcTanh[E^ArcTanh[a*x]]*ArcTanh[a*x]^2 - 2*ArcTanh[a*x]*PolyLog[2, -E^ArcTanh[a*x]] + 2*ArcTanh[a*x]*PolyLog[2, E^ArcTanh[a*x]] + 2*PolyLog[3, -E^ArcTanh[a*x]] - 2*PolyLog[3, E^ArcTanh[a*x]]}
{ArcTanh[a*x]^2/(1 - a^2*x^2)^(3/2)/x^2, x, 5, (2*a^2*x)/Sqrt[1 - a^2*x^2] - (2*a*ArcTanh[a*x])/Sqrt[1 - a^2*x^2] + (a^2*x*ArcTanh[a*x]^2)/Sqrt[1 - a^2*x^2] - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)/x - 4*a*ArcTanh[a*x]*ArcTanh[Sqrt[1 + a*x]/Sqrt[1 - a*x]] + 4*a*PolyLog[2, Sqrt[1 + a*x]/Sqrt[1 - a*x]] - a*PolyLog[2, (1 + a*x)/(1 - a*x)]}
{ArcTanh[a*x]^2/(1 - a^2*x^2)^(3/2)/x^3, x, 20, (2*a^2)/Sqrt[1 - a^2*x^2] - (2*a^3*x*ArcTanh[a*x])/Sqrt[1 - a^2*x^2] - (a*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/x + (a^2*ArcTanh[a*x]^2)/Sqrt[1 - a^2*x^2] - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)/(2*x^2) - 3*a^2*ArcTanh[E^ArcTanh[a*x]]*ArcTanh[a*x]^2 - a^2*ArcTanh[Sqrt[1 - a^2*x^2]] - 3*a^2*ArcTanh[a*x]*PolyLog[2, -E^ArcTanh[a*x]] + 3*a^2*ArcTanh[a*x]*PolyLog[2, E^ArcTanh[a*x]] + 3*a^2*PolyLog[3, -E^ArcTanh[a*x]] - 3*a^2*PolyLog[3, E^ArcTanh[a*x]]}


{ArcTanh[a*x]^3/(1 - a^2*x^2)^(3/2)*x^m, x, 0, Defer[Int][(x^m*ArcTanh[a*x]^3)/(1 - a^2*x^2)^(3/2), x]}

{ArcTanh[a*x]^3/(1 - a^2*x^2)^(3/2)*x^3, x, 11, -((6*x)/(a^3*Sqrt[1 - a^2*x^2])) + (6*ArcTanh[a*x])/(a^4*Sqrt[1 - a^2*x^2]) - (3*x*ArcTanh[a*x]^2)/(a^3*Sqrt[1 - a^2*x^2]) - (6*ArcTan[E^ArcTanh[a*x]]*ArcTanh[a*x]^2)/a^4 + ArcTanh[a*x]^3/(a^4*Sqrt[1 - a^2*x^2]) + (Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^3)/a^4 + (6*I*ArcTanh[a*x]*PolyLog[2, (-I)*E^ArcTanh[a*x]])/a^4 - (6*I*ArcTanh[a*x]*PolyLog[2, I*E^ArcTanh[a*x]])/a^4 - (6*I*PolyLog[3, (-I)*E^ArcTanh[a*x]])/a^4 + (6*I*PolyLog[3, I*E^ArcTanh[a*x]])/a^4}
{ArcTanh[a*x]^3/(1 - a^2*x^2)^(3/2)*x^2, x, 11, -(6/(a^3*Sqrt[1 - a^2*x^2])) + (6*x*ArcTanh[a*x])/(a^2*Sqrt[1 - a^2*x^2]) - (3*ArcTanh[a*x]^2)/(a^3*Sqrt[1 - a^2*x^2]) + (x*ArcTanh[a*x]^3)/(a^2*Sqrt[1 - a^2*x^2]) - (2*ArcTan[E^ArcTanh[a*x]]*ArcTanh[a*x]^3)/a^3 + (3*I*ArcTanh[a*x]^2*PolyLog[2, (-I)*E^ArcTanh[a*x]])/a^3 - (3*I*ArcTanh[a*x]^2*PolyLog[2, I*E^ArcTanh[a*x]])/a^3 - (6*I*ArcTanh[a*x]*PolyLog[3, (-I)*E^ArcTanh[a*x]])/a^3 + (6*I*ArcTanh[a*x]*PolyLog[3, I*E^ArcTanh[a*x]])/a^3 + (6*I*PolyLog[4, (-I)*E^ArcTanh[a*x]])/a^3 - (6*I*PolyLog[4, I*E^ArcTanh[a*x]])/a^3}
{ArcTanh[a*x]^3/(1 - a^2*x^2)^(3/2)*x^1, x, 3, -((6*x)/(a*Sqrt[1 - a^2*x^2])) + (6*ArcTanh[a*x])/(a^2*Sqrt[1 - a^2*x^2]) - (3*x*ArcTanh[a*x]^2)/(a*Sqrt[1 - a^2*x^2]) + ArcTanh[a*x]^3/(a^2*Sqrt[1 - a^2*x^2])}
{ArcTanh[a*x]^3/(1 - a^2*x^2)^(3/2)*x^0, x, 2, -(6/(a*Sqrt[1 - a^2*x^2])) + (6*x*ArcTanh[a*x])/Sqrt[1 - a^2*x^2] - (3*ArcTanh[a*x]^2)/(a*Sqrt[1 - a^2*x^2]) + (x*ArcTanh[a*x]^3)/Sqrt[1 - a^2*x^2]}
{ArcTanh[a*x]^3/(1 - a^2*x^2)^(3/2)/x^1, x, 12, -((6*a*x)/Sqrt[1 - a^2*x^2]) + (6*ArcTanh[a*x])/Sqrt[1 - a^2*x^2] - (3*a*x*ArcTanh[a*x]^2)/Sqrt[1 - a^2*x^2] + ArcTanh[a*x]^3/Sqrt[1 - a^2*x^2] - 2*ArcTanh[E^ArcTanh[a*x]]*ArcTanh[a*x]^3 - 3*ArcTanh[a*x]^2*PolyLog[2, -E^ArcTanh[a*x]] + 3*ArcTanh[a*x]^2*PolyLog[2, E^ArcTanh[a*x]] + 6*ArcTanh[a*x]*PolyLog[3, -E^ArcTanh[a*x]] - 6*ArcTanh[a*x]*PolyLog[3, E^ArcTanh[a*x]] - 6*PolyLog[4, -E^ArcTanh[a*x]] + 6*PolyLog[4, E^ArcTanh[a*x]]}
{ArcTanh[a*x]^3/(1 - a^2*x^2)^(3/2)/x^2, x, 10, -((6*a)/Sqrt[1 - a^2*x^2]) + (6*a^2*x*ArcTanh[a*x])/Sqrt[1 - a^2*x^2] - (3*a*ArcTanh[a*x]^2)/Sqrt[1 - a^2*x^2] - 6*a*ArcTanh[E^ArcTanh[a*x]]*ArcTanh[a*x]^2 + (a^2*x*ArcTanh[a*x]^3)/Sqrt[1 - a^2*x^2] - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^3)/x - 6*a*ArcTanh[a*x]*PolyLog[2, -E^ArcTanh[a*x]] + 6*a*ArcTanh[a*x]*PolyLog[2, E^ArcTanh[a*x]] + 6*a*PolyLog[3, -E^ArcTanh[a*x]] - 6*a*PolyLog[3, E^ArcTanh[a*x]]}
{ArcTanh[a*x]^3/(1 - a^2*x^2)^(3/2)/x^3, x, 24, -((6*a^3*x)/Sqrt[1 - a^2*x^2]) + (6*a^2*ArcTanh[a*x])/Sqrt[1 - a^2*x^2] - (3*a^3*x*ArcTanh[a*x]^2)/Sqrt[1 - a^2*x^2] - (3*a*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)/(2*x) + (a^2*ArcTanh[a*x]^3)/Sqrt[1 - a^2*x^2] - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^3)/(2*x^2) - 3*a^2*ArcTanh[E^ArcTanh[a*x]]*ArcTanh[a*x]^3 - 6*a^2*ArcTanh[a*x]*ArcTanh[Sqrt[1 + a*x]/Sqrt[1 - a*x]] - (9/2)*a^2*ArcTanh[a*x]^2*PolyLog[2, -E^ArcTanh[a*x]] + (9/2)*a^2*ArcTanh[a*x]^2*PolyLog[2, E^ArcTanh[a*x]] + 6*a^2*PolyLog[2, Sqrt[1 + a*x]/Sqrt[1 - a*x]] - (3/2)*a^2*PolyLog[2, (1 + a*x)/(1 - a*x)] + 9*a^2*ArcTanh[a*x]*PolyLog[3, -E^ArcTanh[a*x]] - 9*a^2*ArcTanh[a*x]*PolyLog[3, E^ArcTanh[a*x]] - 9*a^2*PolyLog[4, -E^ArcTanh[a*x]] + 9*a^2*PolyLog[4, E^ArcTanh[a*x]]}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{1/ArcTanh[a*x]/(1 - a^2*x^2)^(3/2)*x^m, x, 0, Defer[Int][x^m/((1 - a^2*x^2)^(3/2)*ArcTanh[a*x]), x]}

{1/ArcTanh[a*x]/(1 - a^2*x^2)^(3/2)*x^2, x, 0, Defer[Int][x^2/((1 - a^2*x^2)^(3/2)*ArcTanh[a*x]), x]} 
{1/ArcTanh[a*x]/(1 - a^2*x^2)^(3/2)*x^1, x, 2, SinhIntegral[ArcTanh[a*x]]/a^2}
{1/ArcTanh[a*x]/(1 - a^2*x^2)^(3/2)*x^0, x, 2, CoshIntegral[ArcTanh[a*x]]/a}
{1/ArcTanh[a*x]/(1 - a^2*x^2)^(3/2)/x^1, x, 0, Defer[Int][1/(x*(1 - a^2*x^2)^(3/2)*ArcTanh[a*x]), x]}


{1/ArcTanh[a*x]^2/(1 - a^2*x^2)^(3/2)*x^m, x, 0, Defer[Int][x^m/((1 - a^2*x^2)^(3/2)*ArcTanh[a*x]^2), x]}

{1/ArcTanh[a*x]^2/(1 - a^2*x^2)^(3/2)*x^2, x, 4, -(1/(a^3*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])) + SinhIntegral[ArcTanh[a*x]]/a^3 - Defer[Int][1/(Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2), x]/a^2}
{1/ArcTanh[a*x]^2/(1 - a^2*x^2)^(3/2)*x^1, x, 3, -(x/(a*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])) + CoshIntegral[ArcTanh[a*x]]/a^2}
{1/ArcTanh[a*x]^2/(1 - a^2*x^2)^(3/2)*x^0, x, 3, -(1/(a*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])) + SinhIntegral[ArcTanh[a*x]]/a}
{1/ArcTanh[a*x]^2/(1 - a^2*x^2)^(3/2)/x^1, x, 4, -((a*x)/(Sqrt[1 - a^2*x^2]*ArcTanh[a*x])) + CoshIntegral[ArcTanh[a*x]] + Defer[Int][1/(x*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2), x]}


{1/ArcTanh[a*x]^3/(1 - a^2*x^2)^(3/2)*x^m, x, 0, Defer[Int][x^m/((1 - a^2*x^2)^(3/2)*ArcTanh[a*x]^3), x]}

{1/ArcTanh[a*x]^3/(1 - a^2*x^2)^(3/2)*x^2, x, 4, -(1/(2*a^3*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)) - x/(2*a^2*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]) + CoshIntegral[ArcTanh[a*x]]/(2*a^3) - Defer[Int][1/(Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^3), x]/a^2}
{1/ArcTanh[a*x]^3/(1 - a^2*x^2)^(3/2)*x^1, x, 4, -(x/(2*a*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)) - 1/(2*a^2*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]) + SinhIntegral[ArcTanh[a*x]]/(2*a^2)}
{1/ArcTanh[a*x]^3/(1 - a^2*x^2)^(3/2)*x^0, x, 3, -(1/(2*a*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)) - x/(2*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]) + CoshIntegral[ArcTanh[a*x]]/(2*a)}
{1/ArcTanh[a*x]^3/(1 - a^2*x^2)^(3/2)/x^1, x, 5, -((a*x)/(2*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)) - 1/(2*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]) + (1/2)*SinhIntegral[ArcTanh[a*x]] + Defer[Int][1/(x*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^3), x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcTanh[a x]^n (1-a^2 x^2)^(1/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Sqrt[1 - a^2*x^2]*ArcTanh[a*x]*x^4, x, 10, -(Sqrt[1 - a^2*x^2]/(720*a^5)) + (11*x^2*Sqrt[1 - a^2*x^2])/(360*a^3) + (x^4*Sqrt[1 - a^2*x^2])/(30*a) - (x*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(16*a^4) - (x^3*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(24*a^2) + (1/6)*x^5*Sqrt[1 - a^2*x^2]*ArcTanh[a*x] - (ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x])/(8*a^5) - (I*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])])/(16*a^5) + (I*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]])/(16*a^5)}
{Sqrt[1 - a^2*x^2]*ArcTanh[a*x]*x^3, x, 9, (x*Sqrt[1 - a^2*x^2])/(24*a^3) + (x^3*Sqrt[1 - a^2*x^2])/(20*a) + (11*ArcSin[a*x])/(120*a^4) - (2*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(15*a^4) - (x^2*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(15*a^2) + (1/5)*x^4*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]}
{Sqrt[1 - a^2*x^2]*ArcTanh[a*x]*x^2, x, 6, Sqrt[1 - a^2*x^2]/(24*a^3) + (x^2*Sqrt[1 - a^2*x^2])/(12*a) - (x*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(8*a^2) + (1/4)*x^3*Sqrt[1 - a^2*x^2]*ArcTanh[a*x] - (ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x])/(4*a^3) - (I*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])])/(8*a^3) + (I*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]])/(8*a^3)}
{Sqrt[1 - a^2*x^2]*ArcTanh[a*x]*x^1, x, 3, (x*Sqrt[1 - a^2*x^2])/(6*a) + ArcSin[a*x]/(6*a^2) - ((1 - a^2*x^2)^(3/2)*ArcTanh[a*x])/(3*a^2)}
{Sqrt[1 - a^2*x^2]*ArcTanh[a*x]*x^0, x, 2, Sqrt[1 - a^2*x^2]/(2*a) + (1/2)*x*Sqrt[1 - a^2*x^2]*ArcTanh[a*x] - (ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x])/a - (I*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])])/(2*a) + (I*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]])/(2*a)}
{Sqrt[1 - a^2*x^2]*ArcTanh[a*x]/x^1, x, 3, -ArcSin[a*x] + Sqrt[1 - a^2*x^2]*ArcTanh[a*x] - 2*ArcTanh[a*x]*ArcTanh[Sqrt[1 + a*x]/Sqrt[1 - a*x]] + 2*PolyLog[2, Sqrt[1 + a*x]/Sqrt[1 - a*x]] - (1/2)*PolyLog[2, (1 + a*x)/(1 - a*x)]}
{Sqrt[1 - a^2*x^2]*ArcTanh[a*x]/x^2, x, 5, -((Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/x) + 2*a*ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x] - a*ArcTanh[Sqrt[1 - a^2*x^2]] + I*a*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])] - I*a*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]]}
{Sqrt[1 - a^2*x^2]*ArcTanh[a*x]/x^3, x, 5, -((a*Sqrt[1 - a^2*x^2])/(2*x)) - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(2*x^2) + a^2*ArcTanh[a*x]*ArcTanh[Sqrt[1 + a*x]/Sqrt[1 - a*x]] - a^2*PolyLog[2, Sqrt[1 + a*x]/Sqrt[1 - a*x]] + (1/4)*a^2*PolyLog[2, (1 + a*x)/(1 - a*x)]}
{Sqrt[1 - a^2*x^2]*ArcTanh[a*x]/x^4, x, 4, -((a*Sqrt[1 - a^2*x^2])/(6*x^2)) - ((1 - a^2*x^2)^(3/2)*ArcTanh[a*x])/(3*x^3) + (1/6)*a^3*ArcTanh[Sqrt[1 - a^2*x^2]]}
{Sqrt[1 - a^2*x^2]*ArcTanh[a*x]/x^5, x, 9, -((a*Sqrt[1 - a^2*x^2])/(12*x^3)) - (a^3*Sqrt[1 - a^2*x^2])/(24*x) - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(4*x^4) + (a^2*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(8*x^2) + (1/4)*a^4*ArcTanh[a*x]*ArcTanh[Sqrt[1 + a*x]/Sqrt[1 - a*x]] - (1/4)*a^4*PolyLog[2, Sqrt[1 + a*x]/Sqrt[1 - a*x]] + (1/16)*a^4*PolyLog[2, (1 + a*x)/(1 - a*x)]}
{Sqrt[1 - a^2*x^2]*ArcTanh[a*x]/x^6, x, 17, -((a*Sqrt[1 - a^2*x^2])/(20*x^4)) - (a^3*Sqrt[1 - a^2*x^2])/(24*x^2) - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(5*x^5) + (a^2*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(15*x^3) + (2*a^4*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(15*x) + (11/120)*a^5*ArcTanh[Sqrt[1 - a^2*x^2]]}
{Sqrt[1 - a^2*x^2]*ArcTanh[a*x]/x^7, x, 14, -((a*Sqrt[1 - a^2*x^2])/(30*x^5)) - (11*a^3*Sqrt[1 - a^2*x^2])/(360*x^3) + (a^5*Sqrt[1 - a^2*x^2])/(720*x) - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(6*x^6) + (a^2*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(24*x^4) + (a^4*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(16*x^2) + (1/8)*a^6*ArcTanh[a*x]*ArcTanh[Sqrt[1 + a*x]/Sqrt[1 - a*x]] - (1/8)*a^6*PolyLog[2, Sqrt[1 + a*x]/Sqrt[1 - a*x]] + (1/32)*a^6*PolyLog[2, (1 + a*x)/(1 - a*x)]}


{Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2*x^4, x, 39, (x*Sqrt[1 - a^2*x^2])/(18*a^4) + (x^3*Sqrt[1 - a^2*x^2])/(60*a^2) - (19*ArcSin[a*x])/(360*a^5) - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(360*a^5) + (11*x^2*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(180*a^3) + (x^4*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(15*a) - (x*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)/(16*a^4) - (x^3*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)/(24*a^2) + (1/6)*x^5*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2 + (ArcTan[E^ArcTanh[a*x]]*ArcTanh[a*x]^2)/(8*a^5) - (I*ArcTanh[a*x]*PolyLog[2, (-I)*E^ArcTanh[a*x]])/(8*a^5) + (I*ArcTanh[a*x]*PolyLog[2, I*E^ArcTanh[a*x]])/(8*a^5) + (I*PolyLog[3, (-I)*E^ArcTanh[a*x]])/(8*a^5) - (I*PolyLog[3, I*E^ArcTanh[a*x]])/(8*a^5)}
{Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2*x^3, x, 18, (11*Sqrt[1 - a^2*x^2])/(60*a^4) - (1 - a^2*x^2)^(3/2)/(30*a^4) + (11*x*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(60*a^3) - (x*(1 - a^2*x^2)^(3/2)*ArcTanh[a*x])/(10*a^3) - (11*ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x])/(30*a^4) - (2*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)/(15*a^4) - (x^2*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)/(15*a^2) + (1/5)*x^4*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2 - (11*I*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])])/(60*a^4) + (11*I*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]])/(60*a^4)}
{Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2*x^2, x, 23, (x*Sqrt[1 - a^2*x^2])/(12*a^2) - ArcSin[a*x]/(6*a^3) + (Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(4*a^3) - ((1 - a^2*x^2)^(3/2)*ArcTanh[a*x])/(6*a^3) + (x*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)/(8*a^2) - (x*(1 - a^2*x^2)^(3/2)*ArcTanh[a*x]^2)/(4*a^2) + (ArcTan[E^ArcTanh[a*x]]*ArcTanh[a*x]^2)/(4*a^3) - (I*ArcTanh[a*x]*PolyLog[2, (-I)*E^ArcTanh[a*x]])/(4*a^3) + (I*ArcTanh[a*x]*PolyLog[2, I*E^ArcTanh[a*x]])/(4*a^3) + (I*PolyLog[3, (-I)*E^ArcTanh[a*x]])/(4*a^3) - (I*PolyLog[3, I*E^ArcTanh[a*x]])/(4*a^3)}
{Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2*x^1, x, 3, Sqrt[1 - a^2*x^2]/(3*a^2) + (x*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(3*a) - (2*ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x])/(3*a^2) - ((1 - a^2*x^2)^(3/2)*ArcTanh[a*x]^2)/(3*a^2) - (I*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])])/(3*a^2) + (I*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]])/(3*a^2)}
{Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2*x^0, x, 8, -(ArcSin[a*x]/a) + (Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/a + (1/2)*x*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2 + (ArcTan[E^ArcTanh[a*x]]*ArcTanh[a*x]^2)/a - (I*ArcTanh[a*x]*PolyLog[2, (-I)*E^ArcTanh[a*x]])/a + (I*ArcTanh[a*x]*PolyLog[2, I*E^ArcTanh[a*x]])/a + (I*PolyLog[3, (-I)*E^ArcTanh[a*x]])/a - (I*PolyLog[3, I*E^ArcTanh[a*x]])/a}
{Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2/x^1, x, 9, 4*ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x] + Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2 - 2*ArcTanh[E^ArcTanh[a*x]]*ArcTanh[a*x]^2 - 2*ArcTanh[a*x]*PolyLog[2, -E^ArcTanh[a*x]] + 2*ArcTanh[a*x]*PolyLog[2, E^ArcTanh[a*x]] + 2*I*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])] - 2*I*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]] + 2*PolyLog[3, -E^ArcTanh[a*x]] - 2*PolyLog[3, E^ArcTanh[a*x]]}
{Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2/x^2, x, 9, -((Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)/x) - 2*a*ArcTan[E^ArcTanh[a*x]]*ArcTanh[a*x]^2 - 4*a*ArcTanh[a*x]*ArcTanh[Sqrt[1 + a*x]/Sqrt[1 - a*x]] + 2*I*a*ArcTanh[a*x]*PolyLog[2, (-I)*E^ArcTanh[a*x]] - 2*I*a*ArcTanh[a*x]*PolyLog[2, I*E^ArcTanh[a*x]] + 4*a*PolyLog[2, Sqrt[1 + a*x]/Sqrt[1 - a*x]] - a*PolyLog[2, (1 + a*x)/(1 - a*x)] - 2*I*a*PolyLog[3, (-I)*E^ArcTanh[a*x]] + 2*I*a*PolyLog[3, I*E^ArcTanh[a*x]]}
{Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2/x^3, x, 17, -((a*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/x) - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)/(2*x^2) + a^2*ArcTanh[E^ArcTanh[a*x]]*ArcTanh[a*x]^2 - a^2*ArcTanh[Sqrt[1 - a^2*x^2]] + a^2*ArcTanh[a*x]*PolyLog[2, -E^ArcTanh[a*x]] - a^2*ArcTanh[a*x]*PolyLog[2, E^ArcTanh[a*x]] - a^2*PolyLog[3, -E^ArcTanh[a*x]] + a^2*PolyLog[3, E^ArcTanh[a*x]]}
{Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2/x^4, x, 6, -((a^2*Sqrt[1 - a^2*x^2])/(3*x)) - (a*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(3*x^2) - ((1 - a^2*x^2)^(3/2)*ArcTanh[a*x]^2)/(3*x^3) + (2/3)*a^3*ArcTanh[a*x]*ArcTanh[Sqrt[1 + a*x]/Sqrt[1 - a*x]] - (2/3)*a^3*PolyLog[2, Sqrt[1 + a*x]/Sqrt[1 - a*x]] + (1/6)*a^3*PolyLog[2, (1 + a*x)/(1 - a*x)]}


(* ::Subsubsection:: *)
(*n<0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcTanh[a x]^n (1-a^2 x^2)^(3/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{(1 - a^2*x^2)^(3/2)*ArcTanh[a*x]*x^4, x, 25, (121*Sqrt[1 - a^2*x^2])/(13440*a^5) + (109*x^2*Sqrt[1 - a^2*x^2])/(6720*a^3) + (9*x^4*Sqrt[1 - a^2*x^2])/(560*a) - (1/56)*a*x^6*Sqrt[1 - a^2*x^2] - (3*x*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(128*a^4) - (x^3*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(64*a^2) + (3/16)*x^5*Sqrt[1 - a^2*x^2]*ArcTanh[a*x] - (1/8)*a^2*x^7*Sqrt[1 - a^2*x^2]*ArcTanh[a*x] - (3*ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x])/(64*a^5) - (3*I*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])])/(128*a^5) + (3*I*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]])/(128*a^5)}
{(1 - a^2*x^2)^(3/2)*ArcTanh[a*x]*x^3, x, 23, (3*x*Sqrt[1 - a^2*x^2])/(112*a^3) + (23*x^3*Sqrt[1 - a^2*x^2])/(840*a) - (1/42)*a*x^5*Sqrt[1 - a^2*x^2] + (17*ArcSin[a*x])/(560*a^4) - (2*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(35*a^4) - (x^2*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(35*a^2) + (8/35)*x^4*Sqrt[1 - a^2*x^2]*ArcTanh[a*x] - (1/7)*a^2*x^6*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]}
{(1 - a^2*x^2)^(3/2)*ArcTanh[a*x]*x^2, x, 17, (31*Sqrt[1 - a^2*x^2])/(720*a^3) + (19*x^2*Sqrt[1 - a^2*x^2])/(360*a) - (1/30)*a*x^4*Sqrt[1 - a^2*x^2] - (x*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(16*a^2) + (7/24)*x^3*Sqrt[1 - a^2*x^2]*ArcTanh[a*x] - (1/6)*a^2*x^5*Sqrt[1 - a^2*x^2]*ArcTanh[a*x] - (ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x])/(8*a^3) - (I*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])])/(16*a^3) + (I*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]])/(16*a^3)}
{(1 - a^2*x^2)^(3/2)*ArcTanh[a*x]*x^1, x, 4, (3*x*Sqrt[1 - a^2*x^2])/(40*a) + (x*(1 - a^2*x^2)^(3/2))/(20*a) + (3*ArcSin[a*x])/(40*a^2) - ((1 - a^2*x^2)^(5/2)*ArcTanh[a*x])/(5*a^2)}
{(1 - a^2*x^2)^(3/2)*ArcTanh[a*x]*x^0, x, 3, (3*Sqrt[1 - a^2*x^2])/(8*a) + (1 - a^2*x^2)^(3/2)/(12*a) + (3/8)*x*Sqrt[1 - a^2*x^2]*ArcTanh[a*x] + (1/4)*x*(1 - a^2*x^2)^(3/2)*ArcTanh[a*x] - (3*ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x])/(4*a) - (3*I*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])])/(8*a) + (3*I*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]])/(8*a)}
{(1 - a^2*x^2)^(3/2)*ArcTanh[a*x]/x^1, x, 7, (-(1/6))*a*x*Sqrt[1 - a^2*x^2] - (7/6)*ArcSin[a*x] + Sqrt[1 - a^2*x^2]*ArcTanh[a*x] + (1/3)*(1 - a^2*x^2)^(3/2)*ArcTanh[a*x] - 2*ArcTanh[a*x]*ArcTanh[Sqrt[1 + a*x]/Sqrt[1 - a*x]] + 2*PolyLog[2, Sqrt[1 + a*x]/Sqrt[1 - a*x]] - (1/2)*PolyLog[2, (1 + a*x)/(1 - a*x)]}
{(1 - a^2*x^2)^(3/2)*ArcTanh[a*x]/x^2, x, 8, (-(1/2))*a*Sqrt[1 - a^2*x^2] - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/x - (1/2)*a^2*x*Sqrt[1 - a^2*x^2]*ArcTanh[a*x] + 3*a*ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x] - a*ArcTanh[Sqrt[1 - a^2*x^2]] + (3/2)*I*a*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])] - (3/2)*I*a*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]]}
{(1 - a^2*x^2)^(3/2)*ArcTanh[a*x]/x^3, x, 9, -((a*Sqrt[1 - a^2*x^2])/(2*x)) + a^2*ArcSin[a*x] - a^2*Sqrt[1 - a^2*x^2]*ArcTanh[a*x] - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(2*x^2) + 3*a^2*ArcTanh[a*x]*ArcTanh[Sqrt[1 + a*x]/Sqrt[1 - a*x]] - 3*a^2*PolyLog[2, Sqrt[1 + a*x]/Sqrt[1 - a*x]] + (3/4)*a^2*PolyLog[2, (1 + a*x)/(1 - a*x)]}
{(1 - a^2*x^2)^(3/2)*ArcTanh[a*x]/x^4, x, 10, -((a*Sqrt[1 - a^2*x^2])/(6*x^2)) + (a^2*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/x - ((1 - a^2*x^2)^(3/2)*ArcTanh[a*x])/(3*x^3) - 2*a^3*ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x] + (7/6)*a^3*ArcTanh[Sqrt[1 - a^2*x^2]] - I*a^3*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])] + I*a^3*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]]}
{(1 - a^2*x^2)^(3/2)*ArcTanh[a*x]/x^5, x, 15, -((a*Sqrt[1 - a^2*x^2])/(12*x^3)) + (11*a^3*Sqrt[1 - a^2*x^2])/(24*x) - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(4*x^4) + (5*a^2*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(8*x^2) - (3/4)*a^4*ArcTanh[a*x]*ArcTanh[Sqrt[1 + a*x]/Sqrt[1 - a*x]] + (3/4)*a^4*PolyLog[2, Sqrt[1 + a*x]/Sqrt[1 - a*x]] - (3/16)*a^4*PolyLog[2, (1 + a*x)/(1 - a*x)]}
{(1 - a^2*x^2)^(3/2)*ArcTanh[a*x]/x^6, x, 5, (3*a^3*Sqrt[1 - a^2*x^2])/(40*x^2) - (a*(1 - a^2*x^2)^(3/2))/(20*x^4) - ((1 - a^2*x^2)^(5/2)*ArcTanh[a*x])/(5*x^5) - (3/40)*a^5*ArcTanh[Sqrt[1 - a^2*x^2]]}
{(1 - a^2*x^2)^(3/2)*ArcTanh[a*x]/x^7, x, 24, -((a*Sqrt[1 - a^2*x^2])/(30*x^5)) + (19*a^3*Sqrt[1 - a^2*x^2])/(360*x^3) + (31*a^5*Sqrt[1 - a^2*x^2])/(720*x) - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(6*x^6) + (7*a^2*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(24*x^4) - (a^4*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(16*x^2) - (1/8)*a^6*ArcTanh[a*x]*ArcTanh[Sqrt[1 + a*x]/Sqrt[1 - a*x]] + (1/8)*a^6*PolyLog[2, Sqrt[1 + a*x]/Sqrt[1 - a*x]] - (1/32)*a^6*PolyLog[2, (1 + a*x)/(1 - a*x)]}


(* ::Subsubsection:: *)
(*n<0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form ArcTanh[a x]^n (1-a^2 x^2)^p*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{ArcTanh[a*x]*(1 - a^2*x^2)^3, x, 5, (4*(1 - a^2*x^2))/(35*a) + (3*(1 - a^2*x^2)^2)/(70*a) + (1 - a^2*x^2)^3/(42*a) + (16/35)*x*ArcTanh[a*x] + (8/35)*x*(1 - a^2*x^2)*ArcTanh[a*x] + (6/35)*x*(1 - a^2*x^2)^2*ArcTanh[a*x] + (1/7)*x*(1 - a^2*x^2)^3*ArcTanh[a*x] + (8*Log[1 - a^2*x^2])/(35*a)}
{ArcTanh[a*x]*(1 - a^2*x^2)^2, x, 4, (2*(1 - a^2*x^2))/(15*a) + (1 - a^2*x^2)^2/(20*a) + (8/15)*x*ArcTanh[a*x] + (4/15)*x*(1 - a^2*x^2)*ArcTanh[a*x] + (1/5)*x*(1 - a^2*x^2)^2*ArcTanh[a*x] + (4*Log[1 - a^2*x^2])/(15*a)}
{ArcTanh[a*x]*(1 - a^2*x^2), x, 3, (1 - a^2*x^2)/(6*a) + (2/3)*x*ArcTanh[a*x] + (1/3)*x*(1 - a^2*x^2)*ArcTanh[a*x] + Log[1 - a^2*x^2]/(3*a)}


{ArcTanh[a*x]^2*(1 - a^2*x^2)^3, x, 11, -((38*x)/105) + (19*a^2*x^3)/315 - (a^4*x^5)/105 + (8*(1 - a^2*x^2)*ArcTanh[a*x])/(35*a) + (3*(1 - a^2*x^2)^2*ArcTanh[a*x])/(35*a) + ((1 - a^2*x^2)^3*ArcTanh[a*x])/(21*a) + (16*ArcTanh[a*x]^2)/(35*a) + (16/35)*x*ArcTanh[a*x]^2 + (8/35)*x*(1 - a^2*x^2)*ArcTanh[a*x]^2 + (6/35)*x*(1 - a^2*x^2)^2*ArcTanh[a*x]^2 + (1/7)*x*(1 - a^2*x^2)^3*ArcTanh[a*x]^2 - (32*ArcTanh[a*x]*Log[2/(1 - a*x)])/(35*a) - (16*PolyLog[2, -((1 + a*x)/(1 - a*x))])/(35*a)}
{ArcTanh[a*x]^2*(1 - a^2*x^2)^2, x, 8, -((11*x)/30) + (a^2*x^3)/30 + (4*(1 - a^2*x^2)*ArcTanh[a*x])/(15*a) + ((1 - a^2*x^2)^2*ArcTanh[a*x])/(10*a) + (8*ArcTanh[a*x]^2)/(15*a) + (8/15)*x*ArcTanh[a*x]^2 + (4/15)*x*(1 - a^2*x^2)*ArcTanh[a*x]^2 + (1/5)*x*(1 - a^2*x^2)^2*ArcTanh[a*x]^2 - (16*ArcTanh[a*x]*Log[2/(1 - a*x)])/(15*a) - (8*PolyLog[2, -((1 + a*x)/(1 - a*x))])/(15*a)}
{ArcTanh[a*x]^2*(1 - a^2*x^2), x, 6, -(x/3) + ((1 - a^2*x^2)*ArcTanh[a*x])/(3*a) + (2*ArcTanh[a*x]^2)/(3*a) + (2/3)*x*ArcTanh[a*x]^2 + (1/3)*x*(1 - a^2*x^2)*ArcTanh[a*x]^2 - (4*ArcTanh[a*x]*Log[2/(1 - a*x)])/(3*a) - (2*PolyLog[2, -((1 + a*x)/(1 - a*x))])/(3*a)}


{ArcTanh[a*x]^3*(1 - a^2*x^2)^3, x, 17, -((13*(1 - a^2*x^2))/(210*a)) - (1 - a^2*x^2)^2/(140*a) - (14/15)*x*ArcTanh[a*x] - (13/105)*x*(1 - a^2*x^2)*ArcTanh[a*x] - (1/35)*x*(1 - a^2*x^2)^2*ArcTanh[a*x] + (12*(1 - a^2*x^2)*ArcTanh[a*x]^2)/(35*a) + (9*(1 - a^2*x^2)^2*ArcTanh[a*x]^2)/(70*a) + ((1 - a^2*x^2)^3*ArcTanh[a*x]^2)/(14*a) + (16*ArcTanh[a*x]^3)/(35*a) + (16/35)*x*ArcTanh[a*x]^3 + (8/35)*x*(1 - a^2*x^2)*ArcTanh[a*x]^3 + (6/35)*x*(1 - a^2*x^2)^2*ArcTanh[a*x]^3 + (1/7)*x*(1 - a^2*x^2)^3*ArcTanh[a*x]^3 - (48*ArcTanh[a*x]^2*Log[2/(1 - a*x)])/(35*a) - (7*Log[1 - a^2*x^2])/(15*a) - (48*ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/(35*a) + (24*PolyLog[3, 1 - 2/(1 - a*x)])/(35*a)}
{ArcTanh[a*x]^3*(1 - a^2*x^2)^2, x, 12, -((1 - a^2*x^2)/(20*a)) - x*ArcTanh[a*x] - (1/10)*x*(1 - a^2*x^2)*ArcTanh[a*x] + (2*(1 - a^2*x^2)*ArcTanh[a*x]^2)/(5*a) + (3*(1 - a^2*x^2)^2*ArcTanh[a*x]^2)/(20*a) + (8*ArcTanh[a*x]^3)/(15*a) + (8/15)*x*ArcTanh[a*x]^3 + (4/15)*x*(1 - a^2*x^2)*ArcTanh[a*x]^3 + (1/5)*x*(1 - a^2*x^2)^2*ArcTanh[a*x]^3 - (8*ArcTanh[a*x]^2*Log[2/(1 - a*x)])/(5*a) - Log[1 - a^2*x^2]/(2*a) - (8*ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/(5*a) + (4*PolyLog[3, 1 - 2/(1 - a*x)])/(5*a)}
{ArcTanh[a*x]^3*(1 - a^2*x^2), x, 8, (-x)*ArcTanh[a*x] + ((1 - a^2*x^2)*ArcTanh[a*x]^2)/(2*a) + (2*ArcTanh[a*x]^3)/(3*a) + (2/3)*x*ArcTanh[a*x]^3 + (1/3)*x*(1 - a^2*x^2)*ArcTanh[a*x]^3 - (2*ArcTanh[a*x]^2*Log[2/(1 - a*x)])/a - Log[1 - a^2*x^2]/(2*a) - (2*ArcTanh[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/a + PolyLog[3, 1 - 2/(1 - a*x)]/a}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(1 - a^2*x^2)/ArcTanh[a*x], x, 0, Defer[Int][(1 - a^2*x^2)/ArcTanh[a*x], x]}
{(1 - a^2*x^2)/ArcTanh[a*x]^2, x, 0, Defer[Int][(1 - a^2*x^2)/ArcTanh[a*x]^2, x]}
{(1 - a^2*x^2)/ArcTanh[a*x]^3, x, 0, Defer[Int][(1 - a^2*x^2)/ArcTanh[a*x]^3, x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form ArcTanh[a x]^n (1-a^2 x^2)^(p/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{ArcTanh[a*x]*(1 - a^2*x^2)^(5/2), x, 4, (5*Sqrt[1 - a^2*x^2])/(16*a) + (5*(1 - a^2*x^2)^(3/2))/(72*a) + (1 - a^2*x^2)^(5/2)/(30*a) + (5/16)*x*Sqrt[1 - a^2*x^2]*ArcTanh[a*x] + (5/24)*x*(1 - a^2*x^2)^(3/2)*ArcTanh[a*x] + (1/6)*x*(1 - a^2*x^2)^(5/2)*ArcTanh[a*x] - (5*ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x])/(8*a) - (5*I*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])])/(16*a) + (5*I*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]])/(16*a)}
{ArcTanh[a*x]*(1 - a^2*x^2)^(3/2), x, 3, (3*Sqrt[1 - a^2*x^2])/(8*a) + (1 - a^2*x^2)^(3/2)/(12*a) + (3/8)*x*Sqrt[1 - a^2*x^2]*ArcTanh[a*x] + (1/4)*x*(1 - a^2*x^2)^(3/2)*ArcTanh[a*x] - (3*ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x])/(4*a) - (3*I*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])])/(8*a) + (3*I*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]])/(8*a)}
{ArcTanh[a*x]*(1 - a^2*x^2)^(1/2), x, 2, Sqrt[1 - a^2*x^2]/(2*a) + (1/2)*x*Sqrt[1 - a^2*x^2]*ArcTanh[a*x] - (ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x])/a - (I*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])])/(2*a) + (I*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]])/(2*a)}
{ArcTanh[a*x]/(1 - a^2*x^2)^(5/2), x, 2, -(1/(9*a*(1 - a^2*x^2)^(3/2))) - 2/(3*a*Sqrt[1 - a^2*x^2]) + (x*ArcTanh[a*x])/(3*(1 - a^2*x^2)^(3/2)) + (2*x*ArcTanh[a*x])/(3*Sqrt[1 - a^2*x^2])}
{ArcTanh[a*x]/(1 - a^2*x^2)^(7/2), x, 3, -(1/(25*a*(1 - a^2*x^2)^(5/2))) - 4/(45*a*(1 - a^2*x^2)^(3/2)) - 8/(15*a*Sqrt[1 - a^2*x^2]) + (x*ArcTanh[a*x])/(5*(1 - a^2*x^2)^(5/2)) + (4*x*ArcTanh[a*x])/(15*(1 - a^2*x^2)^(3/2)) + (8*x*ArcTanh[a*x])/(15*Sqrt[1 - a^2*x^2])}
{ArcTanh[a*x]/(1 - a^2*x^2)^(9/2), x, 4, -(1/(49*a*(1 - a^2*x^2)^(7/2))) - 6/(175*a*(1 - a^2*x^2)^(5/2)) - 8/(105*a*(1 - a^2*x^2)^(3/2)) - 16/(35*a*Sqrt[1 - a^2*x^2]) + (x*ArcTanh[a*x])/(7*(1 - a^2*x^2)^(7/2)) + (6*x*ArcTanh[a*x])/(35*(1 - a^2*x^2)^(5/2)) + (8*x*ArcTanh[a*x])/(35*(1 - a^2*x^2)^(3/2)) + (16*x*ArcTanh[a*x])/(35*Sqrt[1 - a^2*x^2])}

{ArcTanh[a*x]*(c - c*a^2*x^2)^(3/2), x, 4, (3*c*Sqrt[c - a^2*c*x^2])/(8*a) + (c - a^2*c*x^2)^(3/2)/(12*a) + (3/8)*c*x*Sqrt[c - a^2*c*x^2]*ArcTanh[a*x] + (1/4)*x*(c - a^2*c*x^2)^(3/2)*ArcTanh[a*x] - (3*c^2*Sqrt[1 - a^2*x^2]*ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x])/(4*a*Sqrt[c - a^2*c*x^2]) - (3*I*c^2*Sqrt[1 - a^2*x^2]*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])])/(8*a*Sqrt[c - a^2*c*x^2]) + (3*I*c^2*Sqrt[1 - a^2*x^2]*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]])/(8*a*Sqrt[c - a^2*c*x^2])}
{ArcTanh[a*x]*(c - c*a^2*x^2)^(1/2), x, 3, Sqrt[c - a^2*c*x^2]/(2*a) + (1/2)*x*Sqrt[c - a^2*c*x^2]*ArcTanh[a*x] - (c*Sqrt[1 - a^2*x^2]*ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x])/(a*Sqrt[c - a^2*c*x^2]) - (I*c*Sqrt[1 - a^2*x^2]*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])])/(2*a*Sqrt[c - a^2*c*x^2]) + (I*c*Sqrt[1 - a^2*x^2]*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]])/(2*a*Sqrt[c - a^2*c*x^2])}
{ArcTanh[a*x]/(c - c*a^2*x^2)^(1/2), x, 2, -((2*Sqrt[1 - a^2*x^2]*ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x])/(a*Sqrt[c - a^2*c*x^2])) - (I*Sqrt[1 - a^2*x^2]*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])])/(a*Sqrt[c - a^2*c*x^2]) + (I*Sqrt[1 - a^2*x^2]*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]])/(a*Sqrt[c - a^2*c*x^2])}
{ArcTanh[a*x]/(c - c*a^2*x^2)^(3/2), x, 1, -(1/(a*c*Sqrt[c - a^2*c*x^2])) + (x*ArcTanh[a*x])/(c*Sqrt[c - a^2*c*x^2])}
{ArcTanh[a*x]/(c - c*a^2*x^2)^(5/2), x, 2, -(1/(9*a*c*(c - a^2*c*x^2)^(3/2))) - 2/(3*a*c^2*Sqrt[c - a^2*c*x^2]) + (x*ArcTanh[a*x])/(3*c*(c - a^2*c*x^2)^(3/2)) + (2*x*ArcTanh[a*x])/(3*c^2*Sqrt[c - a^2*c*x^2])}
{ArcTanh[a*x]/(c - c*a^2*x^2)^(7/2), x, 3, -(1/(25*a*c*(c - a^2*c*x^2)^(5/2))) - 4/(45*a*c^2*(c - a^2*c*x^2)^(3/2)) - 8/(15*a*c^3*Sqrt[c - a^2*c*x^2]) + (x*ArcTanh[a*x])/(5*c*(c - a^2*c*x^2)^(5/2)) + (4*x*ArcTanh[a*x])/(15*c^2*(c - a^2*c*x^2)^(3/2)) + (8*x*ArcTanh[a*x])/(15*c^3*Sqrt[c - a^2*c*x^2])}


{ArcTanh[a*x]^2*(1 - a^2*x^2)^(1/2), x, 8, -(ArcSin[a*x]/a) + (Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/a + (1/2)*x*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2 + (ArcTan[E^ArcTanh[a*x]]*ArcTanh[a*x]^2)/a - (I*ArcTanh[a*x]*PolyLog[2, (-I)*E^ArcTanh[a*x]])/a + (I*ArcTanh[a*x]*PolyLog[2, I*E^ArcTanh[a*x]])/a + (I*PolyLog[3, (-I)*E^ArcTanh[a*x]])/a - (I*PolyLog[3, I*E^ArcTanh[a*x]])/a}
{ArcTanh[a*x]^2/(1 - a^2*x^2)^(5/2), x, 5, (2*x)/(27*(1 - a^2*x^2)^(3/2)) + (40*x)/(27*Sqrt[1 - a^2*x^2]) - (2*ArcTanh[a*x])/(9*a*(1 - a^2*x^2)^(3/2)) - (4*ArcTanh[a*x])/(3*a*Sqrt[1 - a^2*x^2]) + (x*ArcTanh[a*x]^2)/(3*(1 - a^2*x^2)^(3/2)) + (2*x*ArcTanh[a*x]^2)/(3*Sqrt[1 - a^2*x^2])}
{ArcTanh[a*x]^2/(1 - a^2*x^2)^(7/2), x, 9, (2*x)/(125*(1 - a^2*x^2)^(5/2)) + (272*x)/(3375*(1 - a^2*x^2)^(3/2)) + (4144*x)/(3375*Sqrt[1 - a^2*x^2]) - (2*ArcTanh[a*x])/(25*a*(1 - a^2*x^2)^(5/2)) - (8*ArcTanh[a*x])/(45*a*(1 - a^2*x^2)^(3/2)) - (16*ArcTanh[a*x])/(15*a*Sqrt[1 - a^2*x^2]) + (x*ArcTanh[a*x]^2)/(5*(1 - a^2*x^2)^(5/2)) + (4*x*ArcTanh[a*x]^2)/(15*(1 - a^2*x^2)^(3/2)) + (8*x*ArcTanh[a*x]^2)/(15*Sqrt[1 - a^2*x^2])}
{ArcTanh[a*x]^2/(1 - a^2*x^2)^(9/2), x, 14, (2*x)/(343*(1 - a^2*x^2)^(7/2)) + (888*x)/(42875*(1 - a^2*x^2)^(5/2)) + (30256*x)/(385875*(1 - a^2*x^2)^(3/2)) + (413312*x)/(385875*Sqrt[1 - a^2*x^2]) - (2*ArcTanh[a*x])/(49*a*(1 - a^2*x^2)^(7/2)) - (12*ArcTanh[a*x])/(175*a*(1 - a^2*x^2)^(5/2)) - (16*ArcTanh[a*x])/(105*a*(1 - a^2*x^2)^(3/2)) - (32*ArcTanh[a*x])/(35*a*Sqrt[1 - a^2*x^2]) + (x*ArcTanh[a*x]^2)/(7*(1 - a^2*x^2)^(7/2)) + (6*x*ArcTanh[a*x]^2)/(35*(1 - a^2*x^2)^(5/2)) + (8*x*ArcTanh[a*x]^2)/(35*(1 - a^2*x^2)^(3/2)) + (16*x*ArcTanh[a*x]^2)/(35*Sqrt[1 - a^2*x^2])}


{ArcTanh[a*x]^3*(1 - a^2*x^2)^(1/2), x, 10, (6*ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]*ArcTanh[a*x])/a + (3*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)/(2*a) + (1/2)*x*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^3 + (ArcTan[E^ArcTanh[a*x]]*ArcTanh[a*x]^3)/a - (3*I*ArcTanh[a*x]^2*PolyLog[2, (-I)*E^ArcTanh[a*x]])/(2*a) + (3*I*ArcTanh[a*x]^2*PolyLog[2, I*E^ArcTanh[a*x]])/(2*a) + (3*I*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])])/a - (3*I*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]])/a + (3*I*ArcTanh[a*x]*PolyLog[3, (-I)*E^ArcTanh[a*x]])/a - (3*I*ArcTanh[a*x]*PolyLog[3, I*E^ArcTanh[a*x]])/a - (3*I*PolyLog[4, (-I)*E^ArcTanh[a*x]])/a + (3*I*PolyLog[4, I*E^ArcTanh[a*x]])/a}
{ArcTanh[a*x]^3/(1 - a^2*x^2)^(5/2), x, 5, -(2/(27*a*(1 - a^2*x^2)^(3/2))) - 40/(9*a*Sqrt[1 - a^2*x^2]) + (2*x*ArcTanh[a*x])/(9*(1 - a^2*x^2)^(3/2)) + (40*x*ArcTanh[a*x])/(9*Sqrt[1 - a^2*x^2]) - ArcTanh[a*x]^2/(3*a*(1 - a^2*x^2)^(3/2)) - (2*ArcTanh[a*x]^2)/(a*Sqrt[1 - a^2*x^2]) + (x*ArcTanh[a*x]^3)/(3*(1 - a^2*x^2)^(3/2)) + (2*x*ArcTanh[a*x]^3)/(3*Sqrt[1 - a^2*x^2])}
{ArcTanh[a*x]^3/(1 - a^2*x^2)^(7/2), x, 9, -(6/(625*a*(1 - a^2*x^2)^(5/2))) - 272/(3375*a*(1 - a^2*x^2)^(3/2)) - 4144/(1125*a*Sqrt[1 - a^2*x^2]) + (6*x*ArcTanh[a*x])/(125*(1 - a^2*x^2)^(5/2)) + (272*x*ArcTanh[a*x])/(1125*(1 - a^2*x^2)^(3/2)) + (4144*x*ArcTanh[a*x])/(1125*Sqrt[1 - a^2*x^2]) - (3*ArcTanh[a*x]^2)/(25*a*(1 - a^2*x^2)^(5/2)) - (4*ArcTanh[a*x]^2)/(15*a*(1 - a^2*x^2)^(3/2)) - (8*ArcTanh[a*x]^2)/(5*a*Sqrt[1 - a^2*x^2]) + (x*ArcTanh[a*x]^3)/(5*(1 - a^2*x^2)^(5/2)) + (4*x*ArcTanh[a*x]^3)/(15*(1 - a^2*x^2)^(3/2)) + (8*x*ArcTanh[a*x]^3)/(15*Sqrt[1 - a^2*x^2])}
{ArcTanh[a*x]^3/(1 - a^2*x^2)^(9/2), x, 14, -(6/(2401*a*(1 - a^2*x^2)^(7/2))) - 2664/(214375*a*(1 - a^2*x^2)^(5/2)) - 30256/(385875*a*(1 - a^2*x^2)^(3/2)) - 413312/(128625*a*Sqrt[1 - a^2*x^2]) + (6*x*ArcTanh[a*x])/(343*(1 - a^2*x^2)^(7/2)) + (2664*x*ArcTanh[a*x])/(42875*(1 - a^2*x^2)^(5/2)) + (30256*x*ArcTanh[a*x])/(128625*(1 - a^2*x^2)^(3/2)) + (413312*x*ArcTanh[a*x])/(128625*Sqrt[1 - a^2*x^2]) - (3*ArcTanh[a*x]^2)/(49*a*(1 - a^2*x^2)^(7/2)) - (18*ArcTanh[a*x]^2)/(175*a*(1 - a^2*x^2)^(5/2)) - (8*ArcTanh[a*x]^2)/(35*a*(1 - a^2*x^2)^(3/2)) - (48*ArcTanh[a*x]^2)/(35*a*Sqrt[1 - a^2*x^2]) + (x*ArcTanh[a*x]^3)/(7*(1 - a^2*x^2)^(7/2)) + (6*x*ArcTanh[a*x]^3)/(35*(1 - a^2*x^2)^(5/2)) + (8*x*ArcTanh[a*x]^3)/(35*(1 - a^2*x^2)^(3/2)) + (16*x*ArcTanh[a*x]^3)/(35*Sqrt[1 - a^2*x^2])}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(1 - a^2*x^2)^(1/2)/ArcTanh[a*x], x, 0, Defer[Int][Sqrt[1 - a^2*x^2]/ArcTanh[a*x], x]}
{1/(1 - a^2*x^2)^(1/2)/ArcTanh[a*x], x, 0, Defer[Int][1/(Sqrt[1 - a^2*x^2]*ArcTanh[a*x]), x]}
{1/(1 - a^2*x^2)^(3/2)/ArcTanh[a*x], x, 2, CoshIntegral[ArcTanh[a*x]]/a}
{1/(1 - a^2*x^2)^(5/2)/ArcTanh[a*x], x, 4, (3*CoshIntegral[ArcTanh[a*x]])/(4*a) + CoshIntegral[3*ArcTanh[a*x]]/(4*a)}
{1/(1 - a^2*x^2)^(7/2)/ArcTanh[a*x], x, 5, (5*CoshIntegral[ArcTanh[a*x]])/(8*a) + (5*CoshIntegral[3*ArcTanh[a*x]])/(16*a) + CoshIntegral[5*ArcTanh[a*x]]/(16*a)}
{1/(1 - a^2*x^2)^(9/2)/ArcTanh[a*x], x, 6, (35*CoshIntegral[ArcTanh[a*x]])/(64*a) + (21*CoshIntegral[3*ArcTanh[a*x]])/(64*a) + (7*CoshIntegral[5*ArcTanh[a*x]])/(64*a) + CoshIntegral[7*ArcTanh[a*x]]/(64*a)}


{(1 - a^2*x^2)^(1/2)/ArcTanh[a*x]^2, x, 0, Defer[Int][Sqrt[1 - a^2*x^2]/ArcTanh[a*x]^2, x]}
{1/(1 - a^2*x^2)^(1/2)/ArcTanh[a*x]^2, x, 0, Defer[Int][1/(Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2), x]}
{1/(1 - a^2*x^2)^(3/2)/ArcTanh[a*x]^2, x, 3, -(1/(a*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])) + SinhIntegral[ArcTanh[a*x]]/a}
{1/(1 - a^2*x^2)^(5/2)/ArcTanh[a*x]^2, x, 5, -(1/(a*(1 - a^2*x^2)^(3/2)*ArcTanh[a*x])) + (3*SinhIntegral[ArcTanh[a*x]])/(4*a) + (3*SinhIntegral[3*ArcTanh[a*x]])/(4*a)}
{1/(1 - a^2*x^2)^(7/2)/ArcTanh[a*x]^2, x, 6, -(1/(a*(1 - a^2*x^2)^(5/2)*ArcTanh[a*x])) + (5*SinhIntegral[ArcTanh[a*x]])/(8*a) + (15*SinhIntegral[3*ArcTanh[a*x]])/(16*a) + (5*SinhIntegral[5*ArcTanh[a*x]])/(16*a)}
{1/(1 - a^2*x^2)^(9/2)/ArcTanh[a*x]^2, x, 7, -(1/(a*(1 - a^2*x^2)^(7/2)*ArcTanh[a*x])) + (35*SinhIntegral[ArcTanh[a*x]])/(64*a) + (63*SinhIntegral[3*ArcTanh[a*x]])/(64*a) + (35*SinhIntegral[5*ArcTanh[a*x]])/(64*a) + (7*SinhIntegral[7*ArcTanh[a*x]])/(64*a)}


{(1 - a^2*x^2)^(1/2)/ArcTanh[a*x]^3, x, 0, Defer[Int][Sqrt[1 - a^2*x^2]/ArcTanh[a*x]^3, x]}
{1/(1 - a^2*x^2)^(1/2)/ArcTanh[a*x]^3, x, 0, Defer[Int][1/(Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^3), x]}
{1/(1 - a^2*x^2)^(3/2)/ArcTanh[a*x]^3, x, 3, -(1/(2*a*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]^2)) - x/(2*Sqrt[1 - a^2*x^2]*ArcTanh[a*x]) + CoshIntegral[ArcTanh[a*x]]/(2*a)}
{1/(1 - a^2*x^2)^(5/2)/ArcTanh[a*x]^3, x, 5, -(1/(2*a*(1 - a^2*x^2)^(3/2)*ArcTanh[a*x]^2)) - (3*x)/(2*(1 - a^2*x^2)^(3/2)*ArcTanh[a*x]) + (3*CoshIntegral[ArcTanh[a*x]])/(8*a) + (9*CoshIntegral[3*ArcTanh[a*x]])/(8*a)}
{1/(1 - a^2*x^2)^(7/2)/ArcTanh[a*x]^3, x, 6, -(1/(2*a*(1 - a^2*x^2)^(5/2)*ArcTanh[a*x]^2)) - (5*x)/(2*(1 - a^2*x^2)^(5/2)*ArcTanh[a*x]) + (5*CoshIntegral[ArcTanh[a*x]])/(16*a) + (45*CoshIntegral[3*ArcTanh[a*x]])/(32*a) + (25*CoshIntegral[5*ArcTanh[a*x]])/(32*a)}
{1/(1 - a^2*x^2)^(9/2)/ArcTanh[a*x]^3, x, 7, -(1/(2*a*(1 - a^2*x^2)^(7/2)*ArcTanh[a*x]^2)) - (7*x)/(2*(1 - a^2*x^2)^(7/2)*ArcTanh[a*x]) + (35*CoshIntegral[ArcTanh[a*x]])/(128*a) + (189*CoshIntegral[3*ArcTanh[a*x]])/(128*a) + (175*CoshIntegral[5*ArcTanh[a*x]])/(128*a) + (49*CoshIntegral[7*ArcTanh[a*x]])/(128*a)}


(* ::Section::Closed:: *)
(*Integrands of the form u ArcTanh[a+b x]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcTanh[a+b x]^n*)


{x^3*ArcTanh[a + b*x], x, 6, ((1 + 3*a^2)*x)/(4*b^3) - (a*x^2)/(4*b^2) + x^3/(12*b) + (1/4)*x^4*ArcTanh[a + b*x] + ((1 - a)^4*Log[1 - a - b*x])/(8*b^4) - ((1 + a)^4*Log[1 + a + b*x])/(8*b^4)}
{x^2*ArcTanh[a + b*x], x, 6, -((2*a*x)/(3*b^2)) + x^2/(6*b) + (1/3)*x^3*ArcTanh[a + b*x] + ((1 - a)^3*Log[1 - a - b*x])/(6*b^3) + ((1 + a)^3*Log[1 + a + b*x])/(6*b^3)}
{x*ArcTanh[a + b*x], x, 5, x/(2*b) + (1/2)*x^2*ArcTanh[a + b*x] + ((1 - a)^2*Log[1 - a - b*x])/(4*b^2) - ((1 + a)^2*Log[1 + a + b*x])/(4*b^2)}
{ArcTanh[a + b*x], x, 1, ((a + b*x)*ArcTanh[a + b*x])/b + Log[1 - (a + b*x)^2]/(2*b)}
{ArcTanh[a + b*x]/x, x, 5, (-(1/2))*Log[(b*x)/(1 - a)]*Log[1 - a - b*x] + (1/2)*Log[-((b*x)/(1 + a))]*Log[1 + a + b*x] - (1/2)*PolyLog[2, (1 - a - b*x)/(1 - a)] + (1/2)*PolyLog[2, (1 + a + b*x)/(1 + a)]}
{ArcTanh[a + b*x]/x^2, x, 6, -(ArcTanh[a + b*x]/x) + (b*Log[x])/(1 - a^2) - (b*Log[1 - a - b*x])/(2*(1 - a)) - (b*Log[1 + a + b*x])/(2*(1 + a))}
{ArcTanh[a + b*x]/x^3, x, 7, -(b/(2*(1 - a^2)*x)) - ArcTanh[a + b*x]/(2*x^2) + (a*b^2*Log[x])/(1 - a^2)^2 - (b^2*Log[1 - a - b*x])/(4*(1 - a)^2) + (b^2*Log[1 + a + b*x])/(4*(1 + a)^2)}


{x^3*ArcTanh[a + b*x]^2, x, 27, -((a*(a + b*x))/b^4) + (a + b*x)^2/(12*b^4) + (a*ArcTanh[a + b*x])/b^4 + ((a + b*x)*ArcTanh[a + b*x])/(2*b^4) + (3*a^2*(a + b*x)*ArcTanh[a + b*x])/b^4 - (a*(a + b*x)^2*ArcTanh[a + b*x])/b^4 + ((a + b*x)^3*ArcTanh[a + b*x])/(6*b^4) - ArcTanh[a + b*x]^2/(4*b^4) - (a*ArcTanh[a + b*x]^2)/b^4 - (3*a^2*ArcTanh[a + b*x]^2)/(2*b^4) - (a^3*ArcTanh[a + b*x]^2)/b^4 - (a^3*(a + b*x)*ArcTanh[a + b*x]^2)/b^4 + (3*a^2*(a + b*x)^2*ArcTanh[a + b*x]^2)/(2*b^4) - (a*(a + b*x)^3*ArcTanh[a + b*x]^2)/b^4 + ((a + b*x)^4*ArcTanh[a + b*x]^2)/(4*b^4) + (2*a*ArcTanh[a + b*x]*Log[2/(1 - a - b*x)])/b^4 + (2*a^3*ArcTanh[a + b*x]*Log[2/(1 - a - b*x)])/b^4 + Log[1 - (a + b*x)^2]/(3*b^4) + (3*a^2*Log[1 - (a + b*x)^2])/(2*b^4) + (a*PolyLog[2, -((1 + a + b*x)/(1 - a - b*x))])/b^4 + (a^3*PolyLog[2, -((1 + a + b*x)/(1 - a - b*x))])/b^4}
{x^2*ArcTanh[a + b*x]^2, x, 18, (a + b*x)/(3*b^3) - ArcTanh[a + b*x]/(3*b^3) - (2*a*(a + b*x)*ArcTanh[a + b*x])/b^3 + ((a + b*x)^2*ArcTanh[a + b*x])/(3*b^3) + ArcTanh[a + b*x]^2/(3*b^3) + (a*ArcTanh[a + b*x]^2)/b^3 + (a^2*ArcTanh[a + b*x]^2)/b^3 + (a^2*(a + b*x)*ArcTanh[a + b*x]^2)/b^3 - (a*(a + b*x)^2*ArcTanh[a + b*x]^2)/b^3 + ((a + b*x)^3*ArcTanh[a + b*x]^2)/(3*b^3) - (2*ArcTanh[a + b*x]*Log[2/(1 - a - b*x)])/(3*b^3) - (2*a^2*ArcTanh[a + b*x]*Log[2/(1 - a - b*x)])/b^3 - (a*Log[1 - (a + b*x)^2])/b^3 - PolyLog[2, -((1 + a + b*x)/(1 - a - b*x))]/(3*b^3) - (a^2*PolyLog[2, -((1 + a + b*x)/(1 - a - b*x))])/b^3}
{x*ArcTanh[a + b*x]^2, x, 12, ((a + b*x)*ArcTanh[a + b*x])/b^2 - ArcTanh[a + b*x]^2/(2*b^2) - (a*ArcTanh[a + b*x]^2)/b^2 - (a*(a + b*x)*ArcTanh[a + b*x]^2)/b^2 + ((a + b*x)^2*ArcTanh[a + b*x]^2)/(2*b^2) + (2*a*ArcTanh[a + b*x]*Log[2/(1 - a - b*x)])/b^2 + Log[1 - (a + b*x)^2]/(2*b^2) + (a*PolyLog[2, -((1 + a + b*x)/(1 - a - b*x))])/b^2}
{ArcTanh[a + b*x]^2, x, 5, ArcTanh[a + b*x]^2/b + ((a + b*x)*ArcTanh[a + b*x]^2)/b - (2*ArcTanh[a + b*x]*Log[2/(1 - a - b*x)])/b - PolyLog[2, -((1 + a + b*x)/(1 - a - b*x))]/b}
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


(* ::Subsection::Closed:: *)
(*Integrands of the form (c+d x)^m ArcTanh[a+b x]*)


{(a + b*x)*ArcTanh[a + b*x], x, 2, (a + b*x)/(2*b) - ArcTanh[a + b*x]/(2*b) + ((a + b*x)^2*ArcTanh[a + b*x])/(2*b)}
{(a + b*x)^2*ArcTanh[a + b*x], x, 4, (a + b*x)^2/(6*b) + ((a + b*x)^3*ArcTanh[a + b*x])/(3*b) + Log[1 - (a + b*x)^2]/(6*b)}
{ArcTanh[1 + x]/(2 + 2*x), x, 3, (-(1/4))*PolyLog[2, -1 - x] + (1/4)*PolyLog[2, 1 + x]}
{ArcTanh[a + b*x]/(a + b*x), x, 3, -(PolyLog[2, -a - b*x]/(2*b)) + PolyLog[2, a + b*x]/(2*b)}
{ArcTanh[a + b*x]/(a + b*x)^2, x, 2, -(ArcTanh[a + b*x]/(b*(a + b*x))) - ArcTanh[1 - 2*(a + b*x)^2]/b}


{ArcTanh[a + b*x]/((a*d)/b + d*x), x, 3, -(PolyLog[2, -a - b*x]/(2*d)) + PolyLog[2, a + b*x]/(2*d)}


(* ::Subsection::Closed:: *)
(*Integrands of the form ArcTanh[a+b x] / (c+d x^n)*)


{ArcTanh[a + b*x]/(c + d*x^3), x, 15, -(Log[1 - a - b*x]*Log[(b*(c^(1/3) + d^(1/3)*x))/(b*c^(1/3) + (1 - a)*d^(1/3))])/(6*c^(2/3)*d^(1/3)) + (Log[1 + a + b*x]*Log[(b*(c^(1/3) + d^(1/3)*x))/(b*c^(1/3) - (1 + a)*d^(1/3))])/(6*c^(2/3)*d^(1/3)) - ((-1)^(2/3)*Log[1 - a - b*x]*Log[(b*((-1)^(2/3)*c^(1/3) + d^(1/3)*x))/((-1)^(2/3)*b*c^(1/3) + (1 - a)*d^(1/3))])/(6*c^(2/3)*d^(1/3)) + ((-1)^(2/3)*Log[1 + a + b*x]*Log[(b*((-1)^(2/3)*c^(1/3) + d^(1/3)*x))/((-1)^(2/3)*b*c^(1/3) - (1 + a)*d^(1/3))])/(6*c^(2/3)*d^(1/3)) + ((-1)^(1/3)*Log[1 - a - b*x]*Log[((-1)^(1/3)*b*(c^(1/3) + (-1)^(2/3)*d^(1/3)*x))/((-1)^(1/3)*b*c^(1/3) - (1 - a)*d^(1/3))])/(6*c^(2/3)*d^(1/3)) - ((-1)^(1/3)*Log[1 + a + b*x]*Log[((-1)^(1/3)*b*(c^(1/3) + (-1)^(2/3)*d^(1/3)*x))/((-1)^(1/3)*b*c^(1/3) + (1 + a)*d^(1/3))])/(6*c^(2/3)*d^(1/3)) + ((-1)^(1/3)*PolyLog[2, -((d^(1/3)*(1 - a - b*x))/((-1)^(1/3)*b*c^(1/3) - (1 - a)*d^(1/3)))])/(6*c^(2/3)*d^(1/3)) - PolyLog[2, (d^(1/3)*(1 - a - b*x))/(b*c^(1/3) + (1 - a)*d^(1/3))]/(6*c^(2/3)*d^(1/3)) - ((-1)^(2/3)*PolyLog[2, (d^(1/3)*(1 - a - b*x))/((-1)^(2/3)*b*c^(1/3) + (1 - a)*d^(1/3))])/(6*c^(2/3)*d^(1/3)) + PolyLog[2, -((d^(1/3)*(1 + a + b*x))/(b*c^(1/3) - (1 + a)*d^(1/3)))]/(6*c^(2/3)*d^(1/3)) + ((-1)^(2/3)*PolyLog[2, -((d^(1/3)*(1 + a + b*x))/((-1)^(2/3)*b*c^(1/3) - (1 + a)*d^(1/3)))])/(6*c^(2/3)*d^(1/3)) - ((-1)^(1/3)*PolyLog[2, (d^(1/3)*(1 + a + b*x))/((-1)^(1/3)*b*c^(1/3) + (1 + a)*d^(1/3))])/(6*c^(2/3)*d^(1/3))}
{ArcTanh[a + b*x]/(c + d*x^2), x, 11, -(Log[1 - a - b*x]*Log[(b*(Sqrt[-c] - Sqrt[d]*x))/(b*Sqrt[-c] - (1 - a)*Sqrt[d])])/(4*Sqrt[-c]*Sqrt[d]) + (Log[1 + a + b*x]*Log[(b*(Sqrt[-c] - Sqrt[d]*x))/(b*Sqrt[-c] + (1 + a)*Sqrt[d])])/(4*Sqrt[-c]*Sqrt[d]) + (Log[1 - a - b*x]*Log[(b*(Sqrt[-c] + Sqrt[d]*x))/(b*Sqrt[-c] + (1 - a)*Sqrt[d])])/(4*Sqrt[-c]*Sqrt[d]) - (Log[1 + a + b*x]*Log[(b*(Sqrt[-c] + Sqrt[d]*x))/(b*Sqrt[-c] - (1 + a)*Sqrt[d])])/(4*Sqrt[-c]*Sqrt[d]) - PolyLog[2, -((Sqrt[d]*(1 - a - b*x))/(b*Sqrt[-c] - (1 - a)*Sqrt[d]))]/(4*Sqrt[-c]*Sqrt[d]) + PolyLog[2, (Sqrt[d]*(1 - a - b*x))/(b*Sqrt[-c] + (1 - a)*Sqrt[d])]/(4*Sqrt[-c]*Sqrt[d]) - PolyLog[2, -((Sqrt[d]*(1 + a + b*x))/(b*Sqrt[-c] - (1 + a)*Sqrt[d]))]/(4*Sqrt[-c]*Sqrt[d]) + PolyLog[2, (Sqrt[d]*(1 + a + b*x))/(b*Sqrt[-c] + (1 + a)*Sqrt[d])]/(4*Sqrt[-c]*Sqrt[d])}
{ArcTanh[a + b*x]/(c + d*x), x, 5, -(Log[1 - a - b*x]*Log[(b*(c + d*x))/(b*c + d - a*d)])/(2*d) + (Log[1 + a + b*x]*Log[(b*(c + d*x))/(b*c - (1 + a)*d)])/(2*d) - PolyLog[2, (d*(1 - a - b*x))/(b*c + d - a*d)]/(2*d) + PolyLog[2, -((d*(1 + a + b*x))/(b*c - d - a*d))]/(2*d)}
{ArcTanh[a + b*x]/(c + d/x), x, 11, ((1 - a - b*x)*Log[1 - a - b*x])/(2*b*c) + ((1 + a + b*x)*Log[1 + a + b*x])/(2*b*c) - (d*Log[1 + a + b*x]*Log[-((b*(d + c*x))/(c + a*c - b*d))])/(2*c^2) + (d*Log[1 - a - b*x]*Log[(b*(d + c*x))/(c - a*c + b*d)])/(2*c^2) + (d*PolyLog[2, (c*(1 - a - b*x))/(c - a*c + b*d)])/(2*c^2) - (d*PolyLog[2, (c*(1 + a + b*x))/(c + a*c - b*d)])/(2*c^2)}
{ArcTanh[a + b*x]/(c + d/x^2), x, 17, ((1 - a - b*x)*Log[1 - a - b*x])/(2*b*c) + ((1 + a + b*x)*Log[1 + a + b*x])/(2*b*c) - (Sqrt[-d]*Log[1 - a - b*x]*Log[-((b*(Sqrt[-d] - Sqrt[c]*x))/((1 - a)*Sqrt[c] - b*Sqrt[-d]))])/(4*c^(3/2)) + (Sqrt[-d]*Log[1 + a + b*x]*Log[(b*(Sqrt[-d] - Sqrt[c]*x))/((1 + a)*Sqrt[c] + b*Sqrt[-d])])/(4*c^(3/2)) - (Sqrt[-d]*Log[1 + a + b*x]*Log[-((b*(Sqrt[-d] + Sqrt[c]*x))/((1 + a)*Sqrt[c] - b*Sqrt[-d]))])/(4*c^(3/2)) + (Sqrt[-d]*Log[1 - a - b*x]*Log[(b*(Sqrt[-d] + Sqrt[c]*x))/((1 - a)*Sqrt[c] + b*Sqrt[-d])])/(4*c^(3/2)) - (Sqrt[-d]*PolyLog[2, (Sqrt[c]*(1 - a - b*x))/((1 - a)*Sqrt[c] - b*Sqrt[-d])])/(4*c^(3/2)) + (Sqrt[-d]*PolyLog[2, (Sqrt[c]*(1 - a - b*x))/((1 - a)*Sqrt[c] + b*Sqrt[-d])])/(4*c^(3/2)) - (Sqrt[-d]*PolyLog[2, (Sqrt[c]*(1 + a + b*x))/((1 + a)*Sqrt[c] - b*Sqrt[-d])])/(4*c^(3/2)) + (Sqrt[-d]*PolyLog[2, (Sqrt[c]*(1 + a + b*x))/((1 + a)*Sqrt[c] + b*Sqrt[-d])])/(4*c^(3/2))}
{ArcTanh[a + b*x]/(c + d/x^3), x, 21, ((1 - a - b*x)*Log[1 - a - b*x])/(2*b*c) + ((1 + a + b*x)*Log[1 + a + b*x])/(2*b*c) - (d^(1/3)*Log[1 + a + b*x]*Log[-((b*(d^(1/3) + c^(1/3)*x))/((1 + a)*c^(1/3) - b*d^(1/3)))])/(6*c^(4/3)) + (d^(1/3)*Log[1 - a - b*x]*Log[(b*(d^(1/3) + c^(1/3)*x))/((1 - a)*c^(1/3) + b*d^(1/3))])/(6*c^(4/3)) - ((-1)^(2/3)*d^(1/3)*Log[1 + a + b*x]*Log[-((b*((-1)^(2/3)*d^(1/3) + c^(1/3)*x))/((1 + a)*c^(1/3) - (-1)^(2/3)*b*d^(1/3)))])/(6*c^(4/3)) + ((-1)^(2/3)*d^(1/3)*Log[1 - a - b*x]*Log[(b*((-1)^(2/3)*d^(1/3) + c^(1/3)*x))/((1 - a)*c^(1/3) + (-1)^(2/3)*b*d^(1/3))])/(6*c^(4/3)) - ((-1)^(1/3)*d^(1/3)*Log[1 - a - b*x]*Log[-(((-1)^(1/3)*b*(d^(1/3) + (-1)^(2/3)*c^(1/3)*x))/((1 - a)*c^(1/3) - (-1)^(1/3)*b*d^(1/3)))])/(6*c^(4/3)) + ((-1)^(1/3)*d^(1/3)*Log[1 + a + b*x]*Log[((-1)^(1/3)*b*(d^(1/3) + (-1)^(2/3)*c^(1/3)*x))/((1 + a)*c^(1/3) + (-1)^(1/3)*b*d^(1/3))])/(6*c^(4/3)) + (d^(1/3)*PolyLog[2, (c^(1/3)*(1 - a - b*x))/((1 - a)*c^(1/3) + b*d^(1/3))])/(6*c^(4/3)) - ((-1)^(1/3)*d^(1/3)*PolyLog[2, (c^(1/3)*(1 - a - b*x))/((1 - a)*c^(1/3) - (-1)^(1/3)*b*d^(1/3))])/(6*c^(4/3)) + ((-1)^(2/3)*d^(1/3)*PolyLog[2, (c^(1/3)*(1 - a - b*x))/((1 - a)*c^(1/3) + (-1)^(2/3)*b*d^(1/3))])/(6*c^(4/3)) - (d^(1/3)*PolyLog[2, (c^(1/3)*(1 + a + b*x))/((1 + a)*c^(1/3) - b*d^(1/3))])/(6*c^(4/3)) + ((-1)^(1/3)*d^(1/3)*PolyLog[2, (c^(1/3)*(1 + a + b*x))/((1 + a)*c^(1/3) + (-1)^(1/3)*b*d^(1/3))])/(6*c^(4/3)) - ((-1)^(2/3)*d^(1/3)*PolyLog[2, (c^(1/3)*(1 + a + b*x))/((1 + a)*c^(1/3) - (-1)^(2/3)*b*d^(1/3))])/(6*c^(4/3))}


(* {ArcTanh[a + b*x]/(a + b*x^(3/2)), x, 41, (Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-1 - a] - Sqrt[b]*Sqrt[x])/(Sqrt[-1 - a] + a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) + ((-1)^(2/3)*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-1 - a] - Sqrt[b]*Sqrt[x])/(Sqrt[-1 - a] - (-1)^(1/3)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) - ((-1)^(1/3)*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-1 - a] - Sqrt[b]*Sqrt[x])/(Sqrt[-1 - a] + (-1)^(2/3)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) - (Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[1 - a] - Sqrt[b]*Sqrt[x])/(Sqrt[1 - a] + a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) - ((-1)^(2/3)*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[1 - a] - Sqrt[b]*Sqrt[x])/(Sqrt[1 - a] - (-1)^(1/3)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) + ((-1)^(1/3)*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[1 - a] - Sqrt[b]*Sqrt[x])/(Sqrt[1 - a] + (-1)^(2/3)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) + (Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-1 - a] + Sqrt[b]*Sqrt[x])/(Sqrt[-1 - a] - a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) + ((-1)^(2/3)*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-1 - a] + Sqrt[b]*Sqrt[x])/(Sqrt[-1 - a] + (-1)^(1/3)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) - ((-1)^(1/3)*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-1 - a] + Sqrt[b]*Sqrt[x])/(Sqrt[-1 - a] - (-1)^(2/3)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) - (Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[1 - a] + Sqrt[b]*Sqrt[x])/(Sqrt[1 - a] - a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) - ((-1)^(2/3)*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[1 - a] + Sqrt[b]*Sqrt[x])/(Sqrt[1 - a] + (-1)^(1/3)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) + ((-1)^(1/3)*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[1 - a] + Sqrt[b]*Sqrt[x])/(Sqrt[1 - a] - (-1)^(2/3)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) + (Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[1 - a - b*x])/(3*a^(1/3)*b^(2/3)) + ((-1)^(2/3)*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[1 - a - b*x])/(3*a^(1/3)*b^(2/3)) - ((-1)^(1/3)*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[1 - a - b*x])/(3*a^(1/3)*b^(2/3)) - (Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[1 + a + b*x])/(3*a^(1/3)*b^(2/3)) - ((-1)^(2/3)*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[1 + a + b*x])/(3*a^(1/3)*b^(2/3)) + ((-1)^(1/3)*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[1 + a + b*x])/(3*a^(1/3)*b^(2/3)) + ((-1)^(2/3)*PolyLog[2, -((b^(1/6)*((-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]))/(Sqrt[-1 - a] - (-1)^(1/3)*a^(1/3)*b^(1/6)))])/(3*a^(1/3)*b^(2/3)) - ((-1)^(2/3)*PolyLog[2, -((b^(1/6)*((-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]))/(Sqrt[1 - a] - (-1)^(1/3)*a^(1/3)*b^(1/6)))])/(3*a^(1/3)*b^(2/3)) + PolyLog[2, -((b^(1/6)*(a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-1 - a] - a^(1/3)*b^(1/6)))]/(3*a^(1/3)*b^(2/3)) - PolyLog[2, -((b^(1/6)*(a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[1 - a] - a^(1/3)*b^(1/6)))]/(3*a^(1/3)*b^(2/3)) + PolyLog[2, (b^(1/6)*(a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-1 - a] + a^(1/3)*b^(1/6))]/(3*a^(1/3)*b^(2/3)) - PolyLog[2, (b^(1/6)*(a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[1 - a] + a^(1/3)*b^(1/6))]/(3*a^(1/3)*b^(2/3)) - ((-1)^(1/3)*PolyLog[2, -((b^(1/6)*((-1)^(2/3)*a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-1 - a] - (-1)^(2/3)*a^(1/3)*b^(1/6)))])/(3*a^(1/3)*b^(2/3)) + ((-1)^(1/3)*PolyLog[2, -((b^(1/6)*((-1)^(2/3)*a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[1 - a] - (-1)^(2/3)*a^(1/3)*b^(1/6)))])/(3*a^(1/3)*b^(2/3)) - ((-1)^(1/3)*PolyLog[2, (b^(1/6)*((-1)^(2/3)*a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-1 - a] + (-1)^(2/3)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) + ((-1)^(1/3)*PolyLog[2, (b^(1/6)*((-1)^(2/3)*a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[1 - a] + (-1)^(2/3)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) + ((-1)^(2/3)*PolyLog[2, ((-1)^(1/3)*b^(1/6)*(a^(1/3) + (-1)^(2/3)*b^(1/3)*Sqrt[x]))/(Sqrt[-1 - a] + (-1)^(1/3)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) - ((-1)^(2/3)*PolyLog[2, ((-1)^(1/3)*b^(1/6)*(a^(1/3) + (-1)^(2/3)*b^(1/3)*Sqrt[x]))/(Sqrt[1 - a] + (-1)^(1/3)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3))} *)
{ArcTanh[a + b*x]/(c + d*Sqrt[x]), x, 25, (2*Sqrt[1 + a]*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[1 + a]])/(Sqrt[b]*d) - (2*Sqrt[1 - a]*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[1 - a]])/(Sqrt[b]*d) + (c*Log[(d*(Sqrt[-1 - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[b]*c + Sqrt[-1 - a]*d)]*Log[c + d*Sqrt[x]])/d^2 - (c*Log[(d*(Sqrt[1 - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[b]*c + Sqrt[1 - a]*d)]*Log[c + d*Sqrt[x]])/d^2 + (c*Log[-((d*(Sqrt[-1 - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[b]*c - Sqrt[-1 - a]*d))]*Log[c + d*Sqrt[x]])/d^2 - (c*Log[-((d*(Sqrt[1 - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[b]*c - Sqrt[1 - a]*d))]*Log[c + d*Sqrt[x]])/d^2 - (Sqrt[x]*Log[1 - a - b*x])/d + (c*Log[c + d*Sqrt[x]]*Log[1 - a - b*x])/d^2 + (Sqrt[x]*Log[1 + a + b*x])/d - (c*Log[c + d*Sqrt[x]]*Log[1 + a + b*x])/d^2 + (c*PolyLog[2, (Sqrt[b]*(c + d*Sqrt[x]))/(Sqrt[b]*c - Sqrt[-1 - a]*d)])/d^2 + (c*PolyLog[2, (Sqrt[b]*(c + d*Sqrt[x]))/(Sqrt[b]*c + Sqrt[-1 - a]*d)])/d^2 - (c*PolyLog[2, (Sqrt[b]*(c + d*Sqrt[x]))/(Sqrt[b]*c - Sqrt[1 - a]*d)])/d^2 - (c*PolyLog[2, (Sqrt[b]*(c + d*Sqrt[x]))/(Sqrt[b]*c + Sqrt[1 - a]*d)])/d^2}
{ArcTanh[a + b*x]/(c + d/Sqrt[x]), x, 29, (-2*Sqrt[1 + a]*d*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[1 + a]])/(Sqrt[b]*c^2) + (2*Sqrt[1 - a]*d*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[1 - a]])/(Sqrt[b]*c^2) - (d^2*Log[(c*(Sqrt[-1 - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[-1 - a]*c + Sqrt[b]*d)]*Log[d + c*Sqrt[x]])/c^3 + (d^2*Log[(c*(Sqrt[1 - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[1 - a]*c + Sqrt[b]*d)]*Log[d + c*Sqrt[x]])/c^3 - (d^2*Log[(c*(Sqrt[-1 - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[-1 - a]*c - Sqrt[b]*d)]*Log[d + c*Sqrt[x]])/c^3 + (d^2*Log[(c*(Sqrt[1 - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[1 - a]*c - Sqrt[b]*d)]*Log[d + c*Sqrt[x]])/c^3 + (d*Sqrt[x]*Log[1 - a - b*x])/c^2 + ((1 - a - b*x)*Log[1 - a - b*x])/(2*b*c) - (d^2*Log[d + c*Sqrt[x]]*Log[1 - a - b*x])/c^3 - (d*Sqrt[x]*Log[1 + a + b*x])/c^2 + ((1 + a + b*x)*Log[1 + a + b*x])/(2*b*c) + (d^2*Log[d + c*Sqrt[x]]*Log[1 + a + b*x])/c^3 - (d^2*PolyLog[2, -((Sqrt[b]*(d + c*Sqrt[x]))/(Sqrt[-1 - a]*c - Sqrt[b]*d))])/c^3 + (d^2*PolyLog[2, -((Sqrt[b]*(d + c*Sqrt[x]))/(Sqrt[1 - a]*c - Sqrt[b]*d))])/c^3 - (d^2*PolyLog[2, (Sqrt[b]*(d + c*Sqrt[x]))/(Sqrt[-1 - a]*c + Sqrt[b]*d)])/c^3 + (d^2*PolyLog[2, (Sqrt[b]*(d + c*Sqrt[x]))/(Sqrt[1 - a]*c + Sqrt[b]*d)])/c^3}
(* {ArcTanh[a + b*x]/(a + b/x^(3/2)), x, 49, -(b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-1 - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) + b^(5/6))])/(3*a^(5/3)) - ((-1)^(2/3)*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-1 - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) - (-1)^(1/3)*b^(5/6))])/(3*a^(5/3)) + ((-1)^(1/3)*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-1 - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) + (-1)^(2/3)*b^(5/6))])/(3*a^(5/3)) + (b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[1 - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[1 - a]*a^(1/3) + b^(5/6))])/(3*a^(5/3)) + ((-1)^(2/3)*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[1 - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[1 - a]*a^(1/3) - (-1)^(1/3)*b^(5/6))])/(3*a^(5/3)) - ((-1)^(1/3)*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[1 - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[1 - a]*a^(1/3) + (-1)^(2/3)*b^(5/6))])/(3*a^(5/3)) - (b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-1 - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) - b^(5/6))])/(3*a^(5/3)) - ((-1)^(2/3)*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-1 - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) + (-1)^(1/3)*b^(5/6))])/(3*a^(5/3)) + ((-1)^(1/3)*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-1 - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) - (-1)^(2/3)*b^(5/6))])/(3*a^(5/3)) + (b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[1 - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[1 - a]*a^(1/3) - b^(5/6))])/(3*a^(5/3)) + ((-1)^(2/3)*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[1 - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[1 - a]*a^(1/3) + (-1)^(1/3)*b^(5/6))])/(3*a^(5/3)) - ((-1)^(1/3)*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[1 - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[1 - a]*a^(1/3) - (-1)^(2/3)*b^(5/6))])/(3*a^(5/3)) + ((1 - a - b*x)*Log[1 - a - b*x])/(2*a*b) - (b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[1 - a - b*x])/(3*a^(5/3)) - ((-1)^(2/3)*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[1 - a - b*x])/(3*a^(5/3)) + ((-1)^(1/3)*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[1 - a - b*x])/(3*a^(5/3)) + ((1 + a + b*x)*Log[1 + a + b*x])/(2*a*b) + (b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[1 + a + b*x])/(3*a^(5/3)) + ((-1)^(2/3)*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[1 + a + b*x])/(3*a^(5/3)) - ((-1)^(1/3)*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[1 + a + b*x])/(3*a^(5/3)) - ((-1)^(2/3)*b^(2/3)*PolyLog[2, -((Sqrt[b]*((-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) - (-1)^(1/3)*b^(5/6)))])/(3*a^(5/3)) + ((-1)^(2/3)*b^(2/3)*PolyLog[2, -((Sqrt[b]*((-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]))/(Sqrt[1 - a]*a^(1/3) - (-1)^(1/3)*b^(5/6)))])/(3*a^(5/3)) - (b^(2/3)*PolyLog[2, -((Sqrt[b]*(b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) - b^(5/6)))])/(3*a^(5/3)) + (b^(2/3)*PolyLog[2, -((Sqrt[b]*(b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[1 - a]*a^(1/3) - b^(5/6)))])/(3*a^(5/3)) - (b^(2/3)*PolyLog[2, (Sqrt[b]*(b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) + b^(5/6))])/(3*a^(5/3)) + (b^(2/3)*PolyLog[2, (Sqrt[b]*(b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[1 - a]*a^(1/3) + b^(5/6))])/(3*a^(5/3)) + ((-1)^(1/3)*b^(2/3)*PolyLog[2, -((Sqrt[b]*((-1)^(2/3)*b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) - (-1)^(2/3)*b^(5/6)))])/(3*a^(5/3)) - ((-1)^(1/3)*b^(2/3)*PolyLog[2, -((Sqrt[b]*((-1)^(2/3)*b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[1 - a]*a^(1/3) - (-1)^(2/3)*b^(5/6)))])/(3*a^(5/3)) + ((-1)^(1/3)*b^(2/3)*PolyLog[2, (Sqrt[b]*((-1)^(2/3)*b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) + (-1)^(2/3)*b^(5/6))])/(3*a^(5/3)) - ((-1)^(1/3)*b^(2/3)*PolyLog[2, (Sqrt[b]*((-1)^(2/3)*b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[1 - a]*a^(1/3) + (-1)^(2/3)*b^(5/6))])/(3*a^(5/3)) - ((-1)^(2/3)*b^(2/3)*PolyLog[2, ((-1)^(1/3)*Sqrt[b]*(b^(1/3) + (-1)^(2/3)*a^(1/3)*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) + (-1)^(1/3)*b^(5/6))])/(3*a^(5/3)) + ((-1)^(2/3)*b^(2/3)*PolyLog[2, ((-1)^(1/3)*Sqrt[b]*(b^(1/3) + (-1)^(2/3)*a^(1/3)*Sqrt[x]))/(Sqrt[1 - a]*a^(1/3) + (-1)^(1/3)*b^(5/6))])/(3*a^(5/3))} *)


(* ::Subsection::Closed:: *)
(*Integrands of the form (c e+d e x)^m (a+b ArcTanh[c+d x])^n / (1-(c+d x)^2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{(c*e + d*e*x)*(a + b*ArcTanh[c + d*x])/(1 - (c + d*x)^2), x, 0, -((b*e*ArcTanh[c + d*x]^2)/(2*d)) + (b*e*ArcTanh[c + d*x]*Log[2/(1 - c - d*x)])/d - (a*e*Log[1 - (c + d*x)^2])/(2*d) + (b*e*PolyLog[2, 1 - 2/(1 - c - d*x)])/(2*d)}


(* ::Subsubsection:: *)
(*n<0*)


(* ::Section::Closed:: *)
(*Integrands of the form u ArcTanh[a+b x^n]*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcTanh[a x^n]*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{ArcTanh[Sqrt[x]], x, 4, Sqrt[x] - ArcTanh[Sqrt[x]] + x*ArcTanh[Sqrt[x]]}
{x*ArcTanh[Sqrt[x]], x, 5, Sqrt[x]/2 + x^(3/2)/6 - ArcTanh[Sqrt[x]]/2 + (1/2)*x^2*ArcTanh[Sqrt[x]]}
{x^2*ArcTanh[Sqrt[x]], x, 6, Sqrt[x]/3 + x^(3/2)/9 + x^(5/2)/15 - ArcTanh[Sqrt[x]]/3 + (1/3)*x^3*ArcTanh[Sqrt[x]]}
{ArcTanh[Sqrt[x]]/x, x, 3, -PolyLog[2, -Sqrt[x]] + PolyLog[2, Sqrt[x]]}
{ArcTanh[Sqrt[x]]/x^2, x, 4, -(1/Sqrt[x]) + ArcTanh[Sqrt[x]] - ArcTanh[Sqrt[x]]/x}
{ArcTanh[Sqrt[x]]/x^3, x, 5, -(1/(6*x^(3/2))) - 1/(2*Sqrt[x]) + ArcTanh[Sqrt[x]]/2 - ArcTanh[Sqrt[x]]/(2*x^2)}


{x^(3/2)*ArcTanh[Sqrt[x]], x, 4, x/5 + x^2/10 + (2/5)*x^(5/2)*ArcTanh[Sqrt[x]] + (1/5)*Log[1 - x]}
{Sqrt[x]*ArcTanh[Sqrt[x]], x, 4, x/3 + (2/3)*x^(3/2)*ArcTanh[Sqrt[x]] + (1/3)*Log[1 - x]}
{ArcTanh[Sqrt[x]]/Sqrt[x], x, 3, 2*Sqrt[x]*ArcTanh[Sqrt[x]] + Log[1 - x]}
{ArcTanh[Sqrt[x]]/x^(3/2), x, 4, -((2*ArcTanh[Sqrt[x]])/Sqrt[x]) - Log[1 - x] + Log[x]}


{ArcTanh[a*x^5]/x, x, 3, (-(1/10))*PolyLog[2, (-a)*x^5] + (1/10)*PolyLog[2, a*x^5]}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{ArcTanh[1/x], x, 3, x*ArcCoth[x] + Log[1 - x^2]/2}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{ArcTanh[a*x^n]/x, x, 3, -(PolyLog[2, (-a)*x^n]/(2*n)) + PolyLog[2, a*x^n]/(2*n)}


(* ::Section::Closed:: *)
(*Integrands involving inverse hyperbolic tangents of exponentials*)


(* Integrands of the form x^m*ArcTanh[E^x] *)
{ArcTanh[E^x], x, 3, (-(1/2))*PolyLog[2, -E^x] + (1/2)*PolyLog[2, E^x]}
{x*ArcTanh[E^x], x, 5, (-(1/2))*x*PolyLog[2, -E^x] + (1/2)*x*PolyLog[2, E^x] + (1/2)*PolyLog[3, -E^x] - (1/2)*PolyLog[3, E^x]}
{x^2*ArcTanh[E^x], x, 7, (-(1/2))*x^2*PolyLog[2, -E^x] + (1/2)*x^2*PolyLog[2, E^x] + x*PolyLog[3, -E^x] - x*PolyLog[3, E^x] - PolyLog[4, -E^x] + PolyLog[4, E^x]}


(* Integrands of the form x^m*ArcTanh[E^(a+b*x)] *)
{ArcTanh[E^(a + b*x)], x, 3, -(PolyLog[2, -E^(a + b*x)]/(2*b)) + PolyLog[2, E^(a + b*x)]/(2*b)}
{x*ArcTanh[E^(a + b*x)], x, 5, -((x*PolyLog[2, -E^(a + b*x)])/(2*b)) + (x*PolyLog[2, E^(a + b*x)])/(2*b) + PolyLog[3, -E^(a + b*x)]/(2*b^2) - PolyLog[3, E^(a + b*x)]/(2*b^2)}
{x^2*ArcTanh[E^(a + b*x)], x, 7, -((x^2*PolyLog[2, -E^(a + b*x)])/(2*b)) + (x^2*PolyLog[2, E^(a + b*x)])/(2*b) + (x*PolyLog[3, -E^(a + b*x)])/b^2 - (x*PolyLog[3, E^(a + b*x)])/b^2 - PolyLog[4, -E^(a + b*x)]/b^3 + PolyLog[4, E^(a + b*x)]/b^3}


(* Integrands of the form x^m*ArcTanh[a+b*f^(c+d*x)] *)
{ArcTanh[a + b*f^(c + d*x)], x, 5, (-(1/2))*x*Log[1 - a - b*f^(c + d*x)] + (1/2)*x*Log[1 + a + b*f^(c + d*x)] + (1/2)*x*Log[1 - (b*f^(c + d*x))/(1 - a)] - (1/2)*x*Log[1 + (b*f^(c + d*x))/(1 + a)] + PolyLog[2, (b*f^(c + d*x))/(1 - a)]/(2*d*Log[f]) - PolyLog[2, -((b*f^(c + d*x))/(1 + a))]/(2*d*Log[f])}
{x*ArcTanh[a + b*f^(c + d*x)], x, 7, (-(1/4))*x^2*Log[1 - a - b*f^(c + d*x)] + (1/4)*x^2*Log[1 + a + b*f^(c + d*x)] + (1/4)*x^2*Log[1 - (b*f^(c + d*x))/(1 - a)] - (1/4)*x^2*Log[1 + (b*f^(c + d*x))/(1 + a)] + (x*PolyLog[2, (b*f^(c + d*x))/(1 - a)])/(2*d*Log[f]) - (x*PolyLog[2, -((b*f^(c + d*x))/(1 + a))])/(2*d*Log[f]) - PolyLog[3, (b*f^(c + d*x))/(1 - a)]/(2*d^2*Log[f]^2) + PolyLog[3, -((b*f^(c + d*x))/(1 + a))]/(2*d^2*Log[f]^2)}
{x^2*ArcTanh[a + b*f^(c + d*x)], x, 9, (-(1/6))*x^3*Log[1 - a - b*f^(c + d*x)] + (1/6)*x^3*Log[1 + a + b*f^(c + d*x)] + (1/6)*x^3*Log[1 - (b*f^(c + d*x))/(1 - a)] - (1/6)*x^3*Log[1 + (b*f^(c + d*x))/(1 + a)] + (x^2*PolyLog[2, (b*f^(c + d*x))/(1 - a)])/(2*d*Log[f]) - (x^2*PolyLog[2, -((b*f^(c + d*x))/(1 + a))])/(2*d*Log[f]) - (x*PolyLog[3, (b*f^(c + d*x))/(1 - a)])/(d^2*Log[f]^2) + (x*PolyLog[3, -((b*f^(c + d*x))/(1 + a))])/(d^2*Log[f]^2) + PolyLog[4, (b*f^(c + d*x))/(1 - a)]/(d^3*Log[f]^3) - PolyLog[4, -((b*f^(c + d*x))/(1 + a))]/(d^3*Log[f]^3)}


(* ::Section::Closed:: *)
(*Integrands of the form x^m ArcTanh[Tanh[a+b x]]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcTanh[Tanh[a+b x]]^n*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{ArcTanh[Tanh[a + b*x]]*x^m, x, 2, -((b*x^(2 + m))/(2 + 3*m + m^2)) + (x^(1 + m)*ArcTanh[Tanh[a + b*x]])/(1 + m)}

{ArcTanh[Tanh[a + b*x]]*x^2, x, 2, -((b*x^4)/12) + (1/3)*x^3*ArcTanh[Tanh[a + b*x]]}
{ArcTanh[Tanh[a + b*x]]*x^1, x, 2, -((b*x^3)/6) + (1/2)*x^2*ArcTanh[Tanh[a + b*x]]}
{ArcTanh[Tanh[a + b*x]]*x^0, x, 2, ArcTanh[Tanh[a + b*x]]^2/(2*b)}
{ArcTanh[Tanh[a + b*x]]/x^1, x, 2, b*x - (b*x - ArcTanh[Tanh[a + b*x]])*Log[x]}
{ArcTanh[Tanh[a + b*x]]/x^2, x, 2, -(ArcTanh[Tanh[a + b*x]]/x) + b*Log[x]}
{ArcTanh[Tanh[a + b*x]]/x^3, x, 2, -(b/(2*x)) - ArcTanh[Tanh[a + b*x]]/(2*x^2)}
{ArcTanh[Tanh[a + b*x]]/x^4, x, 2, -(b/(6*x^2)) - ArcTanh[Tanh[a + b*x]]/(3*x^3)}


{ArcTanh[Tanh[a + b*x]]^2*x^m, x, 3, (2*b^2*x^(3 + m))/(6 + 11*m + 6*m^2 + m^3) - (2*b*x^(2 + m)*ArcTanh[Tanh[a + b*x]])/(2 + 3*m + m^2) + (x^(1 + m)*ArcTanh[Tanh[a + b*x]]^2)/(1 + m)}

{ArcTanh[Tanh[a + b*x]]^2*x^3, x, 3, (b^2*x^6)/60 - (1/10)*b*x^5*ArcTanh[Tanh[a + b*x]] + (1/4)*x^4*ArcTanh[Tanh[a + b*x]]^2}
{ArcTanh[Tanh[a + b*x]]^2*x^2, x, 3, (b^2*x^5)/30 - (1/6)*b*x^4*ArcTanh[Tanh[a + b*x]] + (1/3)*x^3*ArcTanh[Tanh[a + b*x]]^2}
{ArcTanh[Tanh[a + b*x]]^2*x^1, x, 3, (x*ArcTanh[Tanh[a + b*x]]^3)/(3*b) - ArcTanh[Tanh[a + b*x]]^4/(12*b^2)}
{ArcTanh[Tanh[a + b*x]]^2*x^0, x, 2, ArcTanh[Tanh[a + b*x]]^3/(3*b)}
{ArcTanh[Tanh[a + b*x]]^2/x^1, x, 3, (-b)*x*(b*x - ArcTanh[Tanh[a + b*x]]) + (1/2)*ArcTanh[Tanh[a + b*x]]^2 + (b*x - ArcTanh[Tanh[a + b*x]])^2*Log[x]}
{ArcTanh[Tanh[a + b*x]]^2/x^2, x, 3, 2*b^2*x - ArcTanh[Tanh[a + b*x]]^2/x - 2*b*(b*x - ArcTanh[Tanh[a + b*x]])*Log[x]}
{ArcTanh[Tanh[a + b*x]]^2/x^3, x, 3, -((b*ArcTanh[Tanh[a + b*x]])/x) - ArcTanh[Tanh[a + b*x]]^2/(2*x^2) + b^2*Log[x]}
{ArcTanh[Tanh[a + b*x]]^2/x^4, x, 1, ArcTanh[Tanh[a + b*x]]^3/(3*x^3*(b*x - ArcTanh[Tanh[a + b*x]]))}
{ArcTanh[Tanh[a + b*x]]^2/x^5, x, 2, -(b^2/(12*x^2)) - (b*ArcTanh[Tanh[a + b*x]])/(6*x^3) - ArcTanh[Tanh[a + b*x]]^2/(4*x^4), (b*ArcTanh[Tanh[a + b*x]]^3)/(12*x^3*(b*x - ArcTanh[Tanh[a + b*x]])^2) + ArcTanh[Tanh[a + b*x]]^3/(4*x^4*(b*x - ArcTanh[Tanh[a + b*x]]))}


{ArcTanh[Tanh[a + b*x]]^3*x^m, x, 4, -((6*b^3*x^(4 + m))/((1 + m)*(24 + 26*m + 9*m^2 + m^3))) + (6*b^2*x^(3 + m)*ArcTanh[Tanh[a + b*x]])/(6 + 11*m + 6*m^2 + m^3) - (3*b*x^(2 + m)*ArcTanh[Tanh[a + b*x]]^2)/(2 + 3*m + m^2) + (x^(1 + m)*ArcTanh[Tanh[a + b*x]]^3)/(1 + m)}

{ArcTanh[Tanh[a + b*x]]^3*x^3, x, 4, (-(1/140))*b^3*x^7 + (1/20)*b^2*x^6*ArcTanh[Tanh[a + b*x]] - (3/20)*b*x^5*ArcTanh[Tanh[a + b*x]]^2 + (1/4)*x^4*ArcTanh[Tanh[a + b*x]]^3}
{ArcTanh[Tanh[a + b*x]]^3*x^2, x, 4, (x^2*ArcTanh[Tanh[a + b*x]]^4)/(4*b) - (x*ArcTanh[Tanh[a + b*x]]^5)/(10*b^2) + ArcTanh[Tanh[a + b*x]]^6/(60*b^3)}
{ArcTanh[Tanh[a + b*x]]^3*x^1, x, 3, (x*ArcTanh[Tanh[a + b*x]]^4)/(4*b) - ArcTanh[Tanh[a + b*x]]^5/(20*b^2)}
{ArcTanh[Tanh[a + b*x]]^3*x^0, x, 2, ArcTanh[Tanh[a + b*x]]^4/(4*b)}
{ArcTanh[Tanh[a + b*x]]^3/x^1, x, 4, b*x*(b*x - ArcTanh[Tanh[a + b*x]])^2 - (1/2)*(b*x - ArcTanh[Tanh[a + b*x]])*ArcTanh[Tanh[a + b*x]]^2 + (1/3)*ArcTanh[Tanh[a + b*x]]^3 - (b*x - ArcTanh[Tanh[a + b*x]])^3*Log[x]}
{ArcTanh[Tanh[a + b*x]]^3/x^2, x, 4, -3*b^2*x*(b*x - ArcTanh[Tanh[a + b*x]]) + (3/2)*b*ArcTanh[Tanh[a + b*x]]^2 - ArcTanh[Tanh[a + b*x]]^3/x + 3*b*(b*x - ArcTanh[Tanh[a + b*x]])^2*Log[x]}
{ArcTanh[Tanh[a + b*x]]^3/x^3, x, 4, 3*b^3*x - (3*b*ArcTanh[Tanh[a + b*x]]^2)/(2*x) - ArcTanh[Tanh[a + b*x]]^3/(2*x^2) - 3*b^2*(b*x - ArcTanh[Tanh[a + b*x]])*Log[x]}
{ArcTanh[Tanh[a + b*x]]^3/x^4, x, 4, -((b^2*ArcTanh[Tanh[a + b*x]])/x) - (b*ArcTanh[Tanh[a + b*x]]^2)/(2*x^2) - ArcTanh[Tanh[a + b*x]]^3/(3*x^3) + b^3*Log[x]}
{ArcTanh[Tanh[a + b*x]]^3/x^5, x, 1, ArcTanh[Tanh[a + b*x]]^4/(4*x^4*(b*x - ArcTanh[Tanh[a + b*x]]))}
{ArcTanh[Tanh[a + b*x]]^3/x^6, x, 2, (b*ArcTanh[Tanh[a + b*x]]^4)/(20*x^4*(b*x - ArcTanh[Tanh[a + b*x]])^2) + ArcTanh[Tanh[a + b*x]]^4/(5*x^5*(b*x - ArcTanh[Tanh[a + b*x]]))}


{ArcTanh[Tanh[a + b*x]]^4*x^m, x, 5, (24*b^4*x^(5 + m))/((1 + m)*(2 + m)*(3 + m)*(20 + 9*m + m^2)) - (24*b^3*x^(4 + m)*ArcTanh[Tanh[a + b*x]])/((1 + m)*(24 + 26*m + 9*m^2 + m^3)) + (12*b^2*x^(3 + m)*ArcTanh[Tanh[a + b*x]]^2)/(6 + 11*m + 6*m^2 + m^3) - (4*b*x^(2 + m)*ArcTanh[Tanh[a + b*x]]^3)/(2 + 3*m + m^2) + (x^(1 + m)*ArcTanh[Tanh[a + b*x]]^4)/(1 + m)}

{ArcTanh[Tanh[a + b*x]]^4*x^6, x, 5, (b^4*x^11)/2310 - (1/210)*b^3*x^10*ArcTanh[Tanh[a + b*x]] + (1/42)*b^2*x^9*ArcTanh[Tanh[a + b*x]]^2 - (1/14)*b*x^8*ArcTanh[Tanh[a + b*x]]^3 + (1/7)*x^7*ArcTanh[Tanh[a + b*x]]^4}
{ArcTanh[Tanh[a + b*x]]^4*x^5, x, 5, (b^4*x^10)/1260 - (1/126)*b^3*x^9*ArcTanh[Tanh[a + b*x]] + (1/28)*b^2*x^8*ArcTanh[Tanh[a + b*x]]^2 - (2/21)*b*x^7*ArcTanh[Tanh[a + b*x]]^3 + (1/6)*x^6*ArcTanh[Tanh[a + b*x]]^4}
{ArcTanh[Tanh[a + b*x]]^4*x^4, x, 5, (b^4*x^9)/630 - (1/70)*b^3*x^8*ArcTanh[Tanh[a + b*x]] + (2/35)*b^2*x^7*ArcTanh[Tanh[a + b*x]]^2 - (2/15)*b*x^6*ArcTanh[Tanh[a + b*x]]^3 + (1/5)*x^5*ArcTanh[Tanh[a + b*x]]^4}
{ArcTanh[Tanh[a + b*x]]^4*x^3, x, 5, (x^3*ArcTanh[Tanh[a + b*x]]^5)/(5*b) - (x^2*ArcTanh[Tanh[a + b*x]]^6)/(10*b^2) + (x*ArcTanh[Tanh[a + b*x]]^7)/(35*b^3) - ArcTanh[Tanh[a + b*x]]^8/(280*b^4)}
{ArcTanh[Tanh[a + b*x]]^4*x^2, x, 4, (x^2*ArcTanh[Tanh[a + b*x]]^5)/(5*b) - (x*ArcTanh[Tanh[a + b*x]]^6)/(15*b^2) + ArcTanh[Tanh[a + b*x]]^7/(105*b^3)}
{ArcTanh[Tanh[a + b*x]]^4*x^1, x, 3, (x*ArcTanh[Tanh[a + b*x]]^5)/(5*b) - ArcTanh[Tanh[a + b*x]]^6/(30*b^2)}
{ArcTanh[Tanh[a + b*x]]^4*x^0, x, 2, ArcTanh[Tanh[a + b*x]]^5/(5*b)}
{ArcTanh[Tanh[a + b*x]]^4/x^1, x, 5, (-b)*x*(b*x - ArcTanh[Tanh[a + b*x]])^3 + (1/2)*(b*x - ArcTanh[Tanh[a + b*x]])^2*ArcTanh[Tanh[a + b*x]]^2 - (1/3)*(b*x - ArcTanh[Tanh[a + b*x]])*ArcTanh[Tanh[a + b*x]]^3 + (1/4)*ArcTanh[Tanh[a + b*x]]^4 + (b*x - ArcTanh[Tanh[a + b*x]])^4*Log[x]}
{ArcTanh[Tanh[a + b*x]]^4/x^2, x, 5, 4*b^2*x*(b*x - ArcTanh[Tanh[a + b*x]])^2 - 2*b*(b*x - ArcTanh[Tanh[a + b*x]])*ArcTanh[Tanh[a + b*x]]^2 + (4/3)*b*ArcTanh[Tanh[a + b*x]]^3 - ArcTanh[Tanh[a + b*x]]^4/x - 4*b*(b*x - ArcTanh[Tanh[a + b*x]])^3*Log[x]}
{ArcTanh[Tanh[a + b*x]]^4/x^3, x, 5, -6*b^3*x*(b*x - ArcTanh[Tanh[a + b*x]]) + 3*b^2*ArcTanh[Tanh[a + b*x]]^2 - (2*b*ArcTanh[Tanh[a + b*x]]^3)/x - ArcTanh[Tanh[a + b*x]]^4/(2*x^2) + 6*b^2*(b*x - ArcTanh[Tanh[a + b*x]])^2*Log[x]}
{ArcTanh[Tanh[a + b*x]]^4/x^4, x, 5, 4*b^4*x - (2*b^2*ArcTanh[Tanh[a + b*x]]^2)/x - (2*b*ArcTanh[Tanh[a + b*x]]^3)/(3*x^2) - ArcTanh[Tanh[a + b*x]]^4/(3*x^3) - 4*b^3*(b*x - ArcTanh[Tanh[a + b*x]])*Log[x]}
{ArcTanh[Tanh[a + b*x]]^4/x^5, x, 5, -((b^3*ArcTanh[Tanh[a + b*x]])/x) - (b^2*ArcTanh[Tanh[a + b*x]]^2)/(2*x^2) - (b*ArcTanh[Tanh[a + b*x]]^3)/(3*x^3) - ArcTanh[Tanh[a + b*x]]^4/(4*x^4) + b^4*Log[x]}
{ArcTanh[Tanh[a + b*x]]^4/x^6, x, 1, ArcTanh[Tanh[a + b*x]]^5/(5*x^5*(b*x - ArcTanh[Tanh[a + b*x]]))}
{ArcTanh[Tanh[a + b*x]]^4/x^7, x, 2, (b*ArcTanh[Tanh[a + b*x]]^5)/(30*x^5*(b*x - ArcTanh[Tanh[a + b*x]])^2) + ArcTanh[Tanh[a + b*x]]^5/(6*x^6*(b*x - ArcTanh[Tanh[a + b*x]]))}
{ArcTanh[Tanh[a + b*x]]^4/x^8, x, 3, (b^2*ArcTanh[Tanh[a + b*x]]^5)/(105*x^5*(b*x - ArcTanh[Tanh[a + b*x]])^3) + (b*ArcTanh[Tanh[a + b*x]]^5)/(21*x^6*(b*x - ArcTanh[Tanh[a + b*x]])^2) + ArcTanh[Tanh[a + b*x]]^5/(7*x^7*(b*x - ArcTanh[Tanh[a + b*x]]))}
{ArcTanh[Tanh[a + b*x]]^4/x^9, x, 4, -(b^4/(280*x^4)) - (b^3*ArcTanh[Tanh[a + b*x]])/(70*x^5) - (b^2*ArcTanh[Tanh[a + b*x]]^2)/(28*x^6) - (b*ArcTanh[Tanh[a + b*x]]^3)/(14*x^7) - ArcTanh[Tanh[a + b*x]]^4/(8*x^8), (b^3*ArcTanh[Tanh[a + b*x]]^5)/(280*x^5*(b*x - ArcTanh[Tanh[a + b*x]])^4) + (b^2*ArcTanh[Tanh[a + b*x]]^5)/(56*x^6*(b*x - ArcTanh[Tanh[a + b*x]])^3) + (3*b*ArcTanh[Tanh[a + b*x]]^5)/(56*x^7*(b*x - ArcTanh[Tanh[a + b*x]])^2) + ArcTanh[Tanh[a + b*x]]^5/(8*x^8*(b*x - ArcTanh[Tanh[a + b*x]]))}
{ArcTanh[Tanh[a + b*x]]^4/x^10, x, 5, -(b^4/(630*x^5)) - (b^3*ArcTanh[Tanh[a + b*x]])/(126*x^6) - (b^2*ArcTanh[Tanh[a + b*x]]^2)/(42*x^7) - (b*ArcTanh[Tanh[a + b*x]]^3)/(18*x^8) - ArcTanh[Tanh[a + b*x]]^4/(9*x^9)}
{ArcTanh[Tanh[a + b*x]]^4/x^11, x, 5, -(b^4/(1260*x^6)) - (b^3*ArcTanh[Tanh[a + b*x]])/(210*x^7) - (b^2*ArcTanh[Tanh[a + b*x]]^2)/(60*x^8) - (2*b*ArcTanh[Tanh[a + b*x]]^3)/(45*x^9) - ArcTanh[Tanh[a + b*x]]^4/(10*x^10)}


{ArcTanh[Tanh[a + b*x]]^6*x^1, x, 3, (x*ArcTanh[Tanh[a + b*x]]^7)/(7*b) - ArcTanh[Tanh[a + b*x]]^8/(56*b^2)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{1/ArcTanh[Tanh[a + b*x]]*x^m, x, 1, -((x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, (b*x)/(b*x - ArcTanh[Tanh[a + b*x]])])/((1 + m)*(b*x - ArcTanh[Tanh[a + b*x]])))}

{1/ArcTanh[Tanh[a + b*x]]*x^3, x, 5, x^3/(3*b) + (x^2*(b*x - ArcTanh[Tanh[a + b*x]]))/(2*b^2) + (x*(b*x - ArcTanh[Tanh[a + b*x]])^2)/b^3 + ((b*x - ArcTanh[Tanh[a + b*x]])^3*Log[ArcTanh[Tanh[a + b*x]]])/b^4}
{1/ArcTanh[Tanh[a + b*x]]*x^2, x, 4, x^2/(2*b) + (x*(b*x - ArcTanh[Tanh[a + b*x]]))/b^2 + ((b*x - ArcTanh[Tanh[a + b*x]])^2*Log[ArcTanh[Tanh[a + b*x]]])/b^3}
{1/ArcTanh[Tanh[a + b*x]]*x^1, x, 3, x/b + ((b*x - ArcTanh[Tanh[a + b*x]])*Log[ArcTanh[Tanh[a + b*x]]])/b^2}
{1/ArcTanh[Tanh[a + b*x]]*x^0, x, 2, Log[ArcTanh[Tanh[a + b*x]]]/b}
{1/ArcTanh[Tanh[a + b*x]]/x^1, x, 4, -(Log[x]/(b*x - ArcTanh[Tanh[a + b*x]])) + Log[ArcTanh[Tanh[a + b*x]]]/(b*x - ArcTanh[Tanh[a + b*x]])}
{1/ArcTanh[Tanh[a + b*x]]/x^2, x, 5, 1/(x*(b*x - ArcTanh[Tanh[a + b*x]])) - (b*Log[x])/(b*x - ArcTanh[Tanh[a + b*x]])^2 + (b*Log[ArcTanh[Tanh[a + b*x]]])/(b*x - ArcTanh[Tanh[a + b*x]])^2}
{1/ArcTanh[Tanh[a + b*x]]/x^3, x, 6, b/(x*(b*x - ArcTanh[Tanh[a + b*x]])^2) + 1/(2*x^2*(b*x - ArcTanh[Tanh[a + b*x]])) - (b^2*Log[x])/(b*x - ArcTanh[Tanh[a + b*x]])^3 + (b^2*Log[ArcTanh[Tanh[a + b*x]]])/(b*x - ArcTanh[Tanh[a + b*x]])^3}


{1/ArcTanh[Tanh[a + b*x]]^2*x^m, x, 2, -(x^m/(b*ArcTanh[Tanh[a + b*x]])) - (x^m*Hypergeometric2F1[1, m, 1 + m, (b*x)/(b*x - ArcTanh[Tanh[a + b*x]])])/(b*(b*x - ArcTanh[Tanh[a + b*x]]))}

{1/ArcTanh[Tanh[a + b*x]]^2*x^4, x, 6, (4*x^3)/(3*b^2) + (2*x^2*(b*x - ArcTanh[Tanh[a + b*x]]))/b^3 + (4*x*(b*x - ArcTanh[Tanh[a + b*x]])^2)/b^4 - x^4/(b*ArcTanh[Tanh[a + b*x]]) + (4*(b*x - ArcTanh[Tanh[a + b*x]])^3*Log[ArcTanh[Tanh[a + b*x]]])/b^5}
{1/ArcTanh[Tanh[a + b*x]]^2*x^3, x, 5, (3*x^2)/(2*b^2) + (3*x*(b*x - ArcTanh[Tanh[a + b*x]]))/b^3 - x^3/(b*ArcTanh[Tanh[a + b*x]]) + (3*(b*x - ArcTanh[Tanh[a + b*x]])^2*Log[ArcTanh[Tanh[a + b*x]]])/b^4}
{1/ArcTanh[Tanh[a + b*x]]^2*x^2, x, 4, (2*x)/b^2 - x^2/(b*ArcTanh[Tanh[a + b*x]]) + (2*(b*x - ArcTanh[Tanh[a + b*x]])*Log[ArcTanh[Tanh[a + b*x]]])/b^3}
{1/ArcTanh[Tanh[a + b*x]]^2*x^1, x, 3, -(x/(b*ArcTanh[Tanh[a + b*x]])) + Log[ArcTanh[Tanh[a + b*x]]]/b^2}
{1/ArcTanh[Tanh[a + b*x]]^2*x^0, x, 2, -(1/(b*ArcTanh[Tanh[a + b*x]]))}
{1/ArcTanh[Tanh[a + b*x]]^2/x^1, x, 5, -(1/((b*x - ArcTanh[Tanh[a + b*x]])*ArcTanh[Tanh[a + b*x]])) + Log[x]/(b*x - ArcTanh[Tanh[a + b*x]])^2 - Log[ArcTanh[Tanh[a + b*x]]]/(b*x - ArcTanh[Tanh[a + b*x]])^2}
{1/ArcTanh[Tanh[a + b*x]]^2/x^2, x, 6, -((2*b)/((b*x - ArcTanh[Tanh[a + b*x]])^2*ArcTanh[Tanh[a + b*x]])) + 1/(x*(b*x - ArcTanh[Tanh[a + b*x]])*ArcTanh[Tanh[a + b*x]]) + (2*b*Log[x])/(b*x - ArcTanh[Tanh[a + b*x]])^3 - (2*b*Log[ArcTanh[Tanh[a + b*x]]])/(b*x - ArcTanh[Tanh[a + b*x]])^3}
{1/ArcTanh[Tanh[a + b*x]]^2/x^3, x, 7, -((3*b^2)/((b*x - ArcTanh[Tanh[a + b*x]])^3*ArcTanh[Tanh[a + b*x]])) + (3*b)/(2*x*(b*x - ArcTanh[Tanh[a + b*x]])^2*ArcTanh[Tanh[a + b*x]]) + 1/(2*x^2*(b*x - ArcTanh[Tanh[a + b*x]])*ArcTanh[Tanh[a + b*x]]) + (3*b^2*Log[x])/(b*x - ArcTanh[Tanh[a + b*x]])^4 - (3*b^2*Log[ArcTanh[Tanh[a + b*x]]])/(b*x - ArcTanh[Tanh[a + b*x]])^4}


{1/ArcTanh[Tanh[a + b*x]]^3*x^m, x, 3, -(x^m/(2*b*ArcTanh[Tanh[a + b*x]]^2)) - (m*x^(-1 + m))/(2*b^2*ArcTanh[Tanh[a + b*x]]) - (m*x^(-1 + m)*Hypergeometric2F1[1, -1 + m, m, (b*x)/(b*x - ArcTanh[Tanh[a + b*x]])])/(2*b^2*(b*x - ArcTanh[Tanh[a + b*x]]))}

{1/ArcTanh[Tanh[a + b*x]]^3*x^4, x, 6, (3*x^2)/b^3 + (6*x*(b*x - ArcTanh[Tanh[a + b*x]]))/b^4 - x^4/(2*b*ArcTanh[Tanh[a + b*x]]^2) - (2*x^3)/(b^2*ArcTanh[Tanh[a + b*x]]) + (6*(b*x - ArcTanh[Tanh[a + b*x]])^2*Log[ArcTanh[Tanh[a + b*x]]])/b^5}
{1/ArcTanh[Tanh[a + b*x]]^3*x^3, x, 5, (3*x)/b^3 - x^3/(2*b*ArcTanh[Tanh[a + b*x]]^2) - (3*x^2)/(2*b^2*ArcTanh[Tanh[a + b*x]]) + (3*(b*x - ArcTanh[Tanh[a + b*x]])*Log[ArcTanh[Tanh[a + b*x]]])/b^4}
{1/ArcTanh[Tanh[a + b*x]]^3*x^2, x, 4, -(x^2/(2*b*ArcTanh[Tanh[a + b*x]]^2)) - x/(b^2*ArcTanh[Tanh[a + b*x]]) + Log[ArcTanh[Tanh[a + b*x]]]/b^3}
{1/ArcTanh[Tanh[a + b*x]]^3*x^1, x, 3, -(x/(2*b*ArcTanh[Tanh[a + b*x]]^2)) - 1/(2*b^2*ArcTanh[Tanh[a + b*x]])}
{1/ArcTanh[Tanh[a + b*x]]^3*x^0, x, 2, -(1/(2*b*ArcTanh[Tanh[a + b*x]]^2))}
{1/ArcTanh[Tanh[a + b*x]]^3/x^1, x, 6, -(1/(2*(b*x - ArcTanh[Tanh[a + b*x]])*ArcTanh[Tanh[a + b*x]]^2)) + 1/((b*x - ArcTanh[Tanh[a + b*x]])^2*ArcTanh[Tanh[a + b*x]]) - Log[x]/(b*x - ArcTanh[Tanh[a + b*x]])^3 + Log[ArcTanh[Tanh[a + b*x]]]/(b*x - ArcTanh[Tanh[a + b*x]])^3}
{1/ArcTanh[Tanh[a + b*x]]^3/x^2, x, 7, -((3*b)/(2*(b*x - ArcTanh[Tanh[a + b*x]])^2*ArcTanh[Tanh[a + b*x]]^2)) + 1/(x*(b*x - ArcTanh[Tanh[a + b*x]])*ArcTanh[Tanh[a + b*x]]^2) + (3*b)/((b*x - ArcTanh[Tanh[a + b*x]])^3*ArcTanh[Tanh[a + b*x]]) - (3*b*Log[x])/(b*x - ArcTanh[Tanh[a + b*x]])^4 + (3*b*Log[ArcTanh[Tanh[a + b*x]]])/(b*x - ArcTanh[Tanh[a + b*x]])^4}
{1/ArcTanh[Tanh[a + b*x]]^3/x^3, x, 8, -((3*b^2)/((b*x - ArcTanh[Tanh[a + b*x]])^3*ArcTanh[Tanh[a + b*x]]^2)) + (2*b)/(x*(b*x - ArcTanh[Tanh[a + b*x]])^2*ArcTanh[Tanh[a + b*x]]^2) + 1/(2*x^2*(b*x - ArcTanh[Tanh[a + b*x]])*ArcTanh[Tanh[a + b*x]]^2) + (6*b^2)/((b*x - ArcTanh[Tanh[a + b*x]])^4*ArcTanh[Tanh[a + b*x]]) - (6*b^2*Log[x])/(b*x - ArcTanh[Tanh[a + b*x]])^5 + (6*b^2*Log[ArcTanh[Tanh[a + b*x]]])/(b*x - ArcTanh[Tanh[a + b*x]])^5}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcTanh[Tanh[a+b x]]^(n/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Sqrt[ArcTanh[Tanh[a + b*x]]]*x^4, x, 6, (2*x^4*ArcTanh[Tanh[a + b*x]]^(3/2))/(3*b) - (16*x^3*ArcTanh[Tanh[a + b*x]]^(5/2))/(15*b^2) + (32*x^2*ArcTanh[Tanh[a + b*x]]^(7/2))/(35*b^3) - (128*x*ArcTanh[Tanh[a + b*x]]^(9/2))/(315*b^4) + (256*ArcTanh[Tanh[a + b*x]]^(11/2))/(3465*b^5)}
{Sqrt[ArcTanh[Tanh[a + b*x]]]*x^3, x, 5, (2*x^3*ArcTanh[Tanh[a + b*x]]^(3/2))/(3*b) - (4*x^2*ArcTanh[Tanh[a + b*x]]^(5/2))/(5*b^2) + (16*x*ArcTanh[Tanh[a + b*x]]^(7/2))/(35*b^3) - (32*ArcTanh[Tanh[a + b*x]]^(9/2))/(315*b^4)}
{Sqrt[ArcTanh[Tanh[a + b*x]]]*x^2, x, 4, (2*x^2*ArcTanh[Tanh[a + b*x]]^(3/2))/(3*b) - (8*x*ArcTanh[Tanh[a + b*x]]^(5/2))/(15*b^2) + (16*ArcTanh[Tanh[a + b*x]]^(7/2))/(105*b^3)}
{Sqrt[ArcTanh[Tanh[a + b*x]]]*x^1, x, 3, (2*x*ArcTanh[Tanh[a + b*x]]^(3/2))/(3*b) - (4*ArcTanh[Tanh[a + b*x]]^(5/2))/(15*b^2)}
{Sqrt[ArcTanh[Tanh[a + b*x]]]*x^0, x, 2, (2*ArcTanh[Tanh[a + b*x]]^(3/2))/(3*b)}
{Sqrt[ArcTanh[Tanh[a + b*x]]]/x^1, x, 2, -2*ArcTan[Sqrt[ArcTanh[Tanh[a + b*x]]]/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]]*Sqrt[b*x - ArcTanh[Tanh[a + b*x]]] + 2*Sqrt[ArcTanh[Tanh[a + b*x]]]}
{Sqrt[ArcTanh[Tanh[a + b*x]]]/x^2, x, 2, (b*ArcTan[Sqrt[ArcTanh[Tanh[a + b*x]]]/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]])/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]] - Sqrt[ArcTanh[Tanh[a + b*x]]]/x}
{Sqrt[ArcTanh[Tanh[a + b*x]]]/x^3, x, 4, (b^2*ArcTan[Sqrt[ArcTanh[Tanh[a + b*x]]]/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]])/(4*(b*x - ArcTanh[Tanh[a + b*x]])^(3/2)) - b/(4*x*Sqrt[ArcTanh[Tanh[a + b*x]]]) + b^2/(4*(b*x - ArcTanh[Tanh[a + b*x]])*Sqrt[ArcTanh[Tanh[a + b*x]]]) - Sqrt[ArcTanh[Tanh[a + b*x]]]/(2*x^2)}
{Sqrt[ArcTanh[Tanh[a + b*x]]]/x^4, x, 6, (b^3*ArcTan[Sqrt[ArcTanh[Tanh[a + b*x]]]/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]])/(8*(b*x - ArcTanh[Tanh[a + b*x]])^(5/2)) + b^2/(24*x*ArcTanh[Tanh[a + b*x]]^(3/2)) - b^3/(24*(b*x - ArcTanh[Tanh[a + b*x]])*ArcTanh[Tanh[a + b*x]]^(3/2)) - b/(12*x^2*Sqrt[ArcTanh[Tanh[a + b*x]]]) + b^3/(8*(b*x - ArcTanh[Tanh[a + b*x]])^2*Sqrt[ArcTanh[Tanh[a + b*x]]]) - Sqrt[ArcTanh[Tanh[a + b*x]]]/(3*x^3)}


{ArcTanh[Tanh[a + b*x]]^(3/2)*x^4, x, 6, (2*x^4*ArcTanh[Tanh[a + b*x]]^(5/2))/(5*b) - (16*x^3*ArcTanh[Tanh[a + b*x]]^(7/2))/(35*b^2) + (32*x^2*ArcTanh[Tanh[a + b*x]]^(9/2))/(105*b^3) - (128*x*ArcTanh[Tanh[a + b*x]]^(11/2))/(1155*b^4) + (256*ArcTanh[Tanh[a + b*x]]^(13/2))/(15015*b^5)}
{ArcTanh[Tanh[a + b*x]]^(3/2)*x^3, x, 5, (2*x^3*ArcTanh[Tanh[a + b*x]]^(5/2))/(5*b) - (12*x^2*ArcTanh[Tanh[a + b*x]]^(7/2))/(35*b^2) + (16*x*ArcTanh[Tanh[a + b*x]]^(9/2))/(105*b^3) - (32*ArcTanh[Tanh[a + b*x]]^(11/2))/(1155*b^4)}
{ArcTanh[Tanh[a + b*x]]^(3/2)*x^2, x, 4, (2*x^2*ArcTanh[Tanh[a + b*x]]^(5/2))/(5*b) - (8*x*ArcTanh[Tanh[a + b*x]]^(7/2))/(35*b^2) + (16*ArcTanh[Tanh[a + b*x]]^(9/2))/(315*b^3)}
{ArcTanh[Tanh[a + b*x]]^(3/2)*x^1, x, 3, (2*x*ArcTanh[Tanh[a + b*x]]^(5/2))/(5*b) - (4*ArcTanh[Tanh[a + b*x]]^(7/2))/(35*b^2)}
{ArcTanh[Tanh[a + b*x]]^(3/2)*x^0, x, 2, (2*ArcTanh[Tanh[a + b*x]]^(5/2))/(5*b)}
{ArcTanh[Tanh[a + b*x]]^(3/2)/x^1, x, 3, 2*ArcTan[Sqrt[ArcTanh[Tanh[a + b*x]]]/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]]*(b*x - ArcTanh[Tanh[a + b*x]])^(3/2) - 2*(b*x - ArcTanh[Tanh[a + b*x]])*Sqrt[ArcTanh[Tanh[a + b*x]]] + (2/3)*ArcTanh[Tanh[a + b*x]]^(3/2)}
{ArcTanh[Tanh[a + b*x]]^(3/2)/x^2, x, 3, -3*b*ArcTan[Sqrt[ArcTanh[Tanh[a + b*x]]]/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]]*Sqrt[b*x - ArcTanh[Tanh[a + b*x]]] + 3*b*Sqrt[ArcTanh[Tanh[a + b*x]]] - ArcTanh[Tanh[a + b*x]]^(3/2)/x}
{ArcTanh[Tanh[a + b*x]]^(3/2)/x^3, x, 3, (3*b^2*ArcTan[Sqrt[ArcTanh[Tanh[a + b*x]]]/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]])/(4*Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]) - (3*b*Sqrt[ArcTanh[Tanh[a + b*x]]])/(4*x) - ArcTanh[Tanh[a + b*x]]^(3/2)/(2*x^2)}
{ArcTanh[Tanh[a + b*x]]^(3/2)/x^4, x, 5, (b^3*ArcTan[Sqrt[ArcTanh[Tanh[a + b*x]]]/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]])/(8*(b*x - ArcTanh[Tanh[a + b*x]])^(3/2)) - b^2/(8*x*Sqrt[ArcTanh[Tanh[a + b*x]]]) + b^3/(8*(b*x - ArcTanh[Tanh[a + b*x]])*Sqrt[ArcTanh[Tanh[a + b*x]]]) - (b*Sqrt[ArcTanh[Tanh[a + b*x]]])/(4*x^2) - ArcTanh[Tanh[a + b*x]]^(3/2)/(3*x^3)}


{ArcTanh[Tanh[a + b*x]]^(5/2)*x^4, x, 6, (2*x^4*ArcTanh[Tanh[a + b*x]]^(7/2))/(7*b) - (16*x^3*ArcTanh[Tanh[a + b*x]]^(9/2))/(63*b^2) + (32*x^2*ArcTanh[Tanh[a + b*x]]^(11/2))/(231*b^3) - (128*x*ArcTanh[Tanh[a + b*x]]^(13/2))/(3003*b^4) + (256*ArcTanh[Tanh[a + b*x]]^(15/2))/(45045*b^5)}
{ArcTanh[Tanh[a + b*x]]^(5/2)*x^3, x, 5, (2*x^3*ArcTanh[Tanh[a + b*x]]^(7/2))/(7*b) - (4*x^2*ArcTanh[Tanh[a + b*x]]^(9/2))/(21*b^2) + (16*x*ArcTanh[Tanh[a + b*x]]^(11/2))/(231*b^3) - (32*ArcTanh[Tanh[a + b*x]]^(13/2))/(3003*b^4)}
{ArcTanh[Tanh[a + b*x]]^(5/2)*x^2, x, 4, (2*x^2*ArcTanh[Tanh[a + b*x]]^(7/2))/(7*b) - (8*x*ArcTanh[Tanh[a + b*x]]^(9/2))/(63*b^2) + (16*ArcTanh[Tanh[a + b*x]]^(11/2))/(693*b^3)}
{ArcTanh[Tanh[a + b*x]]^(5/2)*x^1, x, 3, (2*x*ArcTanh[Tanh[a + b*x]]^(7/2))/(7*b) - (4*ArcTanh[Tanh[a + b*x]]^(9/2))/(63*b^2)}
{ArcTanh[Tanh[a + b*x]]^(5/2)*x^0, x, 2, (2*ArcTanh[Tanh[a + b*x]]^(7/2))/(7*b)}
{ArcTanh[Tanh[a + b*x]]^(5/2)/x^1, x, 4, -2*ArcTan[Sqrt[ArcTanh[Tanh[a + b*x]]]/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]]*(b*x - ArcTanh[Tanh[a + b*x]])^(5/2) + 2*(b*x - ArcTanh[Tanh[a + b*x]])^2*Sqrt[ArcTanh[Tanh[a + b*x]]] - (2/3)*(b*x - ArcTanh[Tanh[a + b*x]])*ArcTanh[Tanh[a + b*x]]^(3/2) + (2/5)*ArcTanh[Tanh[a + b*x]]^(5/2)}
{ArcTanh[Tanh[a + b*x]]^(5/2)/x^2, x, 4, 5*b*ArcTan[Sqrt[ArcTanh[Tanh[a + b*x]]]/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]]*(b*x - ArcTanh[Tanh[a + b*x]])^(3/2) - 5*b*(b*x - ArcTanh[Tanh[a + b*x]])*Sqrt[ArcTanh[Tanh[a + b*x]]] + (5/3)*b*ArcTanh[Tanh[a + b*x]]^(3/2) - ArcTanh[Tanh[a + b*x]]^(5/2)/x}
{ArcTanh[Tanh[a + b*x]]^(5/2)/x^3, x, 4, (-(15/4))*b^2*ArcTan[Sqrt[ArcTanh[Tanh[a + b*x]]]/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]]*Sqrt[b*x - ArcTanh[Tanh[a + b*x]]] + (15/4)*b^2*Sqrt[ArcTanh[Tanh[a + b*x]]] - (5*b*ArcTanh[Tanh[a + b*x]]^(3/2))/(4*x) - ArcTanh[Tanh[a + b*x]]^(5/2)/(2*x^2)}
{ArcTanh[Tanh[a + b*x]]^(5/2)/x^4, x, 4, (5*b^3*ArcTan[Sqrt[ArcTanh[Tanh[a + b*x]]]/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]])/(8*Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]) - (5*b^2*Sqrt[ArcTanh[Tanh[a + b*x]]])/(8*x) - (5*b*ArcTanh[Tanh[a + b*x]]^(3/2))/(12*x^2) - ArcTanh[Tanh[a + b*x]]^(5/2)/(3*x^3)}
{ArcTanh[Tanh[a + b*x]]^(5/2)/x^5, x, 6, (5*b^4*ArcTan[Sqrt[ArcTanh[Tanh[a + b*x]]]/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]])/(64*(b*x - ArcTanh[Tanh[a + b*x]])^(3/2)) - (5*b^3)/(64*x*Sqrt[ArcTanh[Tanh[a + b*x]]]) + (5*b^4)/(64*(b*x - ArcTanh[Tanh[a + b*x]])*Sqrt[ArcTanh[Tanh[a + b*x]]]) - (5*b^2*Sqrt[ArcTanh[Tanh[a + b*x]]])/(32*x^2) - (5*b*ArcTanh[Tanh[a + b*x]]^(3/2))/(24*x^3) - ArcTanh[Tanh[a + b*x]]^(5/2)/(4*x^4)}
{ArcTanh[Tanh[a + b*x]]^(5/2)/x^6, x, 8, (3*b^5*ArcTan[Sqrt[ArcTanh[Tanh[a + b*x]]]/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]])/(128*(b*x - ArcTanh[Tanh[a + b*x]])^(5/2)) + b^4/(128*x*ArcTanh[Tanh[a + b*x]]^(3/2)) - b^5/(128*(b*x - ArcTanh[Tanh[a + b*x]])*ArcTanh[Tanh[a + b*x]]^(3/2)) - b^3/(64*x^2*Sqrt[ArcTanh[Tanh[a + b*x]]]) + (3*b^5)/(128*(b*x - ArcTanh[Tanh[a + b*x]])^2*Sqrt[ArcTanh[Tanh[a + b*x]]]) - (b^2*Sqrt[ArcTanh[Tanh[a + b*x]]])/(16*x^3) - (b*ArcTanh[Tanh[a + b*x]]^(3/2))/(8*x^4) - ArcTanh[Tanh[a + b*x]]^(5/2)/(5*x^5)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{1/Sqrt[ArcTanh[Tanh[a + b*x]]]*x^4, x, 6, (2*x^4*Sqrt[ArcTanh[Tanh[a + b*x]]])/b - (16*x^3*ArcTanh[Tanh[a + b*x]]^(3/2))/(3*b^2) + (32*x^2*ArcTanh[Tanh[a + b*x]]^(5/2))/(5*b^3) - (128*x*ArcTanh[Tanh[a + b*x]]^(7/2))/(35*b^4) + (256*ArcTanh[Tanh[a + b*x]]^(9/2))/(315*b^5)}
{1/Sqrt[ArcTanh[Tanh[a + b*x]]]*x^3, x, 5, (2*x^3*Sqrt[ArcTanh[Tanh[a + b*x]]])/b - (4*x^2*ArcTanh[Tanh[a + b*x]]^(3/2))/b^2 + (16*x*ArcTanh[Tanh[a + b*x]]^(5/2))/(5*b^3) - (32*ArcTanh[Tanh[a + b*x]]^(7/2))/(35*b^4)}
{1/Sqrt[ArcTanh[Tanh[a + b*x]]]*x^2, x, 4, (2*x^2*Sqrt[ArcTanh[Tanh[a + b*x]]])/b - (8*x*ArcTanh[Tanh[a + b*x]]^(3/2))/(3*b^2) + (16*ArcTanh[Tanh[a + b*x]]^(5/2))/(15*b^3)}
{1/Sqrt[ArcTanh[Tanh[a + b*x]]]*x^1, x, 3, (2*x*Sqrt[ArcTanh[Tanh[a + b*x]]])/b - (4*ArcTanh[Tanh[a + b*x]]^(3/2))/(3*b^2)}
{1/Sqrt[ArcTanh[Tanh[a + b*x]]]*x^0, x, 2, (2*Sqrt[ArcTanh[Tanh[a + b*x]]])/b}
{1/Sqrt[ArcTanh[Tanh[a + b*x]]]/x^1, x, 1, (2*ArcTan[Sqrt[ArcTanh[Tanh[a + b*x]]]/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]])/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]}
{1/Sqrt[ArcTanh[Tanh[a + b*x]]]/x^2, x, 3, (b*ArcTan[Sqrt[ArcTanh[Tanh[a + b*x]]]/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]])/(b*x - ArcTanh[Tanh[a + b*x]])^(3/2) - 1/(x*Sqrt[ArcTanh[Tanh[a + b*x]]]) + b/((b*x - ArcTanh[Tanh[a + b*x]])*Sqrt[ArcTanh[Tanh[a + b*x]]])}
{1/Sqrt[ArcTanh[Tanh[a + b*x]]]/x^3, x, 5, (3*b^2*ArcTan[Sqrt[ArcTanh[Tanh[a + b*x]]]/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]])/(4*(b*x - ArcTanh[Tanh[a + b*x]])^(5/2)) + b/(4*x*ArcTanh[Tanh[a + b*x]]^(3/2)) - b^2/(4*(b*x - ArcTanh[Tanh[a + b*x]])*ArcTanh[Tanh[a + b*x]]^(3/2)) - 1/(2*x^2*Sqrt[ArcTanh[Tanh[a + b*x]]]) + (3*b^2)/(4*(b*x - ArcTanh[Tanh[a + b*x]])^2*Sqrt[ArcTanh[Tanh[a + b*x]]])}
{1/Sqrt[ArcTanh[Tanh[a + b*x]]]/x^4, x, 7, (5*b^3*ArcTan[Sqrt[ArcTanh[Tanh[a + b*x]]]/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]])/(8*(b*x - ArcTanh[Tanh[a + b*x]])^(7/2)) - b^2/(8*x*ArcTanh[Tanh[a + b*x]]^(5/2)) + b^3/(8*(b*x - ArcTanh[Tanh[a + b*x]])*ArcTanh[Tanh[a + b*x]]^(5/2)) + b/(12*x^2*ArcTanh[Tanh[a + b*x]]^(3/2)) - (5*b^3)/(24*(b*x - ArcTanh[Tanh[a + b*x]])^2*ArcTanh[Tanh[a + b*x]]^(3/2)) - 1/(3*x^3*Sqrt[ArcTanh[Tanh[a + b*x]]]) + (5*b^3)/(8*(b*x - ArcTanh[Tanh[a + b*x]])^3*Sqrt[ArcTanh[Tanh[a + b*x]]])}


{1/ArcTanh[Tanh[a + b*x]]^(3/2)*x^4, x, 6, -((2*x^4)/(b*Sqrt[ArcTanh[Tanh[a + b*x]]])) + (16*x^3*Sqrt[ArcTanh[Tanh[a + b*x]]])/b^2 - (32*x^2*ArcTanh[Tanh[a + b*x]]^(3/2))/b^3 + (128*x*ArcTanh[Tanh[a + b*x]]^(5/2))/(5*b^4) - (256*ArcTanh[Tanh[a + b*x]]^(7/2))/(35*b^5)}
{1/ArcTanh[Tanh[a + b*x]]^(3/2)*x^3, x, 5, -((2*x^3)/(b*Sqrt[ArcTanh[Tanh[a + b*x]]])) + (12*x^2*Sqrt[ArcTanh[Tanh[a + b*x]]])/b^2 - (16*x*ArcTanh[Tanh[a + b*x]]^(3/2))/b^3 + (32*ArcTanh[Tanh[a + b*x]]^(5/2))/(5*b^4)}
{1/ArcTanh[Tanh[a + b*x]]^(3/2)*x^2, x, 4, -((2*x^2)/(b*Sqrt[ArcTanh[Tanh[a + b*x]]])) + (8*x*Sqrt[ArcTanh[Tanh[a + b*x]]])/b^2 - (16*ArcTanh[Tanh[a + b*x]]^(3/2))/(3*b^3)}
{1/ArcTanh[Tanh[a + b*x]]^(3/2)*x^1, x, 3, -((2*x)/(b*Sqrt[ArcTanh[Tanh[a + b*x]]])) + (4*Sqrt[ArcTanh[Tanh[a + b*x]]])/b^2}
{1/ArcTanh[Tanh[a + b*x]]^(3/2)*x^0, x, 2, -(2/(b*Sqrt[ArcTanh[Tanh[a + b*x]]]))}
{1/ArcTanh[Tanh[a + b*x]]^(3/2)/x^1, x, 2, -((2*ArcTan[Sqrt[ArcTanh[Tanh[a + b*x]]]/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]])/(b*x - ArcTanh[Tanh[a + b*x]])^(3/2)) - 2/((b*x - ArcTanh[Tanh[a + b*x]])*Sqrt[ArcTanh[Tanh[a + b*x]]])}
{1/ArcTanh[Tanh[a + b*x]]^(3/2)/x^2, x, 4, -((3*b*ArcTan[Sqrt[ArcTanh[Tanh[a + b*x]]]/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]])/(b*x - ArcTanh[Tanh[a + b*x]])^(5/2)) - 1/(x*ArcTanh[Tanh[a + b*x]]^(3/2)) + b/((b*x - ArcTanh[Tanh[a + b*x]])*ArcTanh[Tanh[a + b*x]]^(3/2)) - (3*b)/((b*x - ArcTanh[Tanh[a + b*x]])^2*Sqrt[ArcTanh[Tanh[a + b*x]]])}
{1/ArcTanh[Tanh[a + b*x]]^(3/2)/x^3, x, 6, -((15*b^2*ArcTan[Sqrt[ArcTanh[Tanh[a + b*x]]]/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]])/(4*(b*x - ArcTanh[Tanh[a + b*x]])^(7/2))) + (3*b)/(4*x*ArcTanh[Tanh[a + b*x]]^(5/2)) - (3*b^2)/(4*(b*x - ArcTanh[Tanh[a + b*x]])*ArcTanh[Tanh[a + b*x]]^(5/2)) - 1/(2*x^2*ArcTanh[Tanh[a + b*x]]^(3/2)) + (5*b^2)/(4*(b*x - ArcTanh[Tanh[a + b*x]])^2*ArcTanh[Tanh[a + b*x]]^(3/2)) - (15*b^2)/(4*(b*x - ArcTanh[Tanh[a + b*x]])^3*Sqrt[ArcTanh[Tanh[a + b*x]]])}
{1/ArcTanh[Tanh[a + b*x]]^(3/2)/x^4, x, 8, -((35*b^3*ArcTan[Sqrt[ArcTanh[Tanh[a + b*x]]]/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]])/(8*(b*x - ArcTanh[Tanh[a + b*x]])^(9/2))) - (5*b^2)/(8*x*ArcTanh[Tanh[a + b*x]]^(7/2)) + (5*b^3)/(8*(b*x - ArcTanh[Tanh[a + b*x]])*ArcTanh[Tanh[a + b*x]]^(7/2)) + b/(4*x^2*ArcTanh[Tanh[a + b*x]]^(5/2)) - (7*b^3)/(8*(b*x - ArcTanh[Tanh[a + b*x]])^2*ArcTanh[Tanh[a + b*x]]^(5/2)) - 1/(3*x^3*ArcTanh[Tanh[a + b*x]]^(3/2)) + (35*b^3)/(24*(b*x - ArcTanh[Tanh[a + b*x]])^3*ArcTanh[Tanh[a + b*x]]^(3/2)) - (35*b^3)/(8*(b*x - ArcTanh[Tanh[a + b*x]])^4*Sqrt[ArcTanh[Tanh[a + b*x]]])}


{1/ArcTanh[Tanh[a + b*x]]^(5/2)*x^4, x, 6, -((2*x^4)/(3*b*ArcTanh[Tanh[a + b*x]]^(3/2))) - (16*x^3)/(3*b^2*Sqrt[ArcTanh[Tanh[a + b*x]]]) + (32*x^2*Sqrt[ArcTanh[Tanh[a + b*x]]])/b^3 - (128*x*ArcTanh[Tanh[a + b*x]]^(3/2))/(3*b^4) + (256*ArcTanh[Tanh[a + b*x]]^(5/2))/(15*b^5)}
{1/ArcTanh[Tanh[a + b*x]]^(5/2)*x^3, x, 5, -((2*x^3)/(3*b*ArcTanh[Tanh[a + b*x]]^(3/2))) - (4*x^2)/(b^2*Sqrt[ArcTanh[Tanh[a + b*x]]]) + (16*x*Sqrt[ArcTanh[Tanh[a + b*x]]])/b^3 - (32*ArcTanh[Tanh[a + b*x]]^(3/2))/(3*b^4)}
{1/ArcTanh[Tanh[a + b*x]]^(5/2)*x^2, x, 4, -((2*x^2)/(3*b*ArcTanh[Tanh[a + b*x]]^(3/2))) - (8*x)/(3*b^2*Sqrt[ArcTanh[Tanh[a + b*x]]]) + (16*Sqrt[ArcTanh[Tanh[a + b*x]]])/(3*b^3)}
{1/ArcTanh[Tanh[a + b*x]]^(5/2)*x^1, x, 3, -((2*x)/(3*b*ArcTanh[Tanh[a + b*x]]^(3/2))) - 4/(3*b^2*Sqrt[ArcTanh[Tanh[a + b*x]]])}
{1/ArcTanh[Tanh[a + b*x]]^(5/2)*x^0, x, 2, -(2/(3*b*ArcTanh[Tanh[a + b*x]]^(3/2)))}
{1/ArcTanh[Tanh[a + b*x]]^(5/2)/x^1, x, 3, (2*ArcTan[Sqrt[ArcTanh[Tanh[a + b*x]]]/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]])/(b*x - ArcTanh[Tanh[a + b*x]])^(5/2) - 2/(3*(b*x - ArcTanh[Tanh[a + b*x]])*ArcTanh[Tanh[a + b*x]]^(3/2)) + 2/((b*x - ArcTanh[Tanh[a + b*x]])^2*Sqrt[ArcTanh[Tanh[a + b*x]]])}
{1/ArcTanh[Tanh[a + b*x]]^(5/2)/x^2, x, 5, (5*b*ArcTan[Sqrt[ArcTanh[Tanh[a + b*x]]]/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]])/(b*x - ArcTanh[Tanh[a + b*x]])^(7/2) - 1/(x*ArcTanh[Tanh[a + b*x]]^(5/2)) + b/((b*x - ArcTanh[Tanh[a + b*x]])*ArcTanh[Tanh[a + b*x]]^(5/2)) - (5*b)/(3*(b*x - ArcTanh[Tanh[a + b*x]])^2*ArcTanh[Tanh[a + b*x]]^(3/2)) + (5*b)/((b*x - ArcTanh[Tanh[a + b*x]])^3*Sqrt[ArcTanh[Tanh[a + b*x]]])}
{1/ArcTanh[Tanh[a + b*x]]^(5/2)/x^3, x, 7, (35*b^2*ArcTan[Sqrt[ArcTanh[Tanh[a + b*x]]]/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]])/(4*(b*x - ArcTanh[Tanh[a + b*x]])^(9/2)) + (5*b)/(4*x*ArcTanh[Tanh[a + b*x]]^(7/2)) - (5*b^2)/(4*(b*x - ArcTanh[Tanh[a + b*x]])*ArcTanh[Tanh[a + b*x]]^(7/2)) - 1/(2*x^2*ArcTanh[Tanh[a + b*x]]^(5/2)) + (7*b^2)/(4*(b*x - ArcTanh[Tanh[a + b*x]])^2*ArcTanh[Tanh[a + b*x]]^(5/2)) - (35*b^2)/(12*(b*x - ArcTanh[Tanh[a + b*x]])^3*ArcTanh[Tanh[a + b*x]]^(3/2)) + (35*b^2)/(4*(b*x - ArcTanh[Tanh[a + b*x]])^4*Sqrt[ArcTanh[Tanh[a + b*x]]])}
{1/ArcTanh[Tanh[a + b*x]]^(5/2)/x^4, x, 9, (105*b^3*ArcTan[Sqrt[ArcTanh[Tanh[a + b*x]]]/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]])/(8*(b*x - ArcTanh[Tanh[a + b*x]])^(11/2)) - (35*b^2)/(24*x*ArcTanh[Tanh[a + b*x]]^(9/2)) + (35*b^3)/(24*(b*x - ArcTanh[Tanh[a + b*x]])*ArcTanh[Tanh[a + b*x]]^(9/2)) + (5*b)/(12*x^2*ArcTanh[Tanh[a + b*x]]^(7/2)) - (15*b^3)/(8*(b*x - ArcTanh[Tanh[a + b*x]])^2*ArcTanh[Tanh[a + b*x]]^(7/2)) - 1/(3*x^3*ArcTanh[Tanh[a + b*x]]^(5/2)) + (21*b^3)/(8*(b*x - ArcTanh[Tanh[a + b*x]])^3*ArcTanh[Tanh[a + b*x]]^(5/2)) - (35*b^3)/(8*(b*x - ArcTanh[Tanh[a + b*x]])^4*ArcTanh[Tanh[a + b*x]]^(3/2)) + (105*b^3)/(8*(b*x - ArcTanh[Tanh[a + b*x]])^5*Sqrt[ArcTanh[Tanh[a + b*x]]])}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^(m/2) ArcTanh[Tanh[a+b x]]^n*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{x^(7/2)*ArcTanh[Tanh[a + b*x]], x, 2, (-4*b*x^(11/2))/99 + (2*x^(9/2)*ArcTanh[Tanh[a + b*x]])/9}
{x^(5/2)*ArcTanh[Tanh[a + b*x]], x, 2, (-4*b*x^(9/2))/63 + (2*x^(7/2)*ArcTanh[Tanh[a + b*x]])/7}
{x^(3/2)*ArcTanh[Tanh[a + b*x]], x, 2, (-4*b*x^(7/2))/35 + (2*x^(5/2)*ArcTanh[Tanh[a + b*x]])/5}
{Sqrt[x]*ArcTanh[Tanh[a + b*x]], x, 2, (-4*b*x^(5/2))/15 + (2*x^(3/2)*ArcTanh[Tanh[a + b*x]])/3}
{ArcTanh[Tanh[a + b*x]]/Sqrt[x], x, 2, (-4*b*x^(3/2))/3 + 2*Sqrt[x]*ArcTanh[Tanh[a + b*x]]}
{ArcTanh[Tanh[a + b*x]]/x^(3/2), x, 2, 4*b*Sqrt[x] - (2*ArcTanh[Tanh[a + b*x]])/Sqrt[x]}
{ArcTanh[Tanh[a + b*x]]/x^(5/2), x, 2, (-4*b)/(3*Sqrt[x]) - (2*ArcTanh[Tanh[a + b*x]])/(3*x^(3/2))}
{ArcTanh[Tanh[a + b*x]]/x^(7/2), x, 2, (-4*b)/(15*x^(3/2)) - (2*ArcTanh[Tanh[a + b*x]])/(5*x^(5/2))}


{x^(7/2)*ArcTanh[Tanh[a + b*x]]^2, x, 3, (16*b^2*x^(13/2))/1287 - (8*b*x^(11/2)*ArcTanh[Tanh[a + b*x]])/99 + (2*x^(9/2)*ArcTanh[Tanh[a + b*x]]^2)/9}
{x^(5/2)*ArcTanh[Tanh[a + b*x]]^2, x, 3, (16*b^2*x^(11/2))/693 - (8*b*x^(9/2)*ArcTanh[Tanh[a + b*x]])/63 + (2*x^(7/2)*ArcTanh[Tanh[a + b*x]]^2)/7}
{x^(3/2)*ArcTanh[Tanh[a + b*x]]^2, x, 3, (16*b^2*x^(9/2))/315 - (8*b*x^(7/2)*ArcTanh[Tanh[a + b*x]])/35 + (2*x^(5/2)*ArcTanh[Tanh[a + b*x]]^2)/5}
{Sqrt[x]*ArcTanh[Tanh[a + b*x]]^2, x, 3, (16*b^2*x^(7/2))/105 - (8*b*x^(5/2)*ArcTanh[Tanh[a + b*x]])/15 + (2*x^(3/2)*ArcTanh[Tanh[a + b*x]]^2)/3}
{ArcTanh[Tanh[a + b*x]]^2/Sqrt[x], x, 3, (16*b^2*x^(5/2))/15 - (8*b*x^(3/2)*ArcTanh[Tanh[a + b*x]])/3 + 2*Sqrt[x]*ArcTanh[Tanh[a + b*x]]^2}
{ArcTanh[Tanh[a + b*x]]^2/x^(3/2), x, 3, (-16*b^2*x^(3/2))/3 + 8*b*Sqrt[x]*ArcTanh[Tanh[a + b*x]] - (2*ArcTanh[Tanh[a + b*x]]^2)/Sqrt[x]}
{ArcTanh[Tanh[a + b*x]]^2/x^(5/2), x, 3, (16*b^2*Sqrt[x])/3 - (8*b*ArcTanh[Tanh[a + b*x]])/(3*Sqrt[x]) - (2*ArcTanh[Tanh[a + b*x]]^2)/(3*x^(3/2))}
{ArcTanh[Tanh[a + b*x]]^2/x^(7/2), x, 3, (-16*b^2)/(15*Sqrt[x]) - (8*b*ArcTanh[Tanh[a + b*x]])/(15*x^(3/2)) - (2*ArcTanh[Tanh[a + b*x]]^2)/(5*x^(5/2))}


{x^(7/2)*ArcTanh[Tanh[a + b*x]]^3, x, 4, (-32*b^3*x^(15/2))/6435 + (16*b^2*x^(13/2)*ArcTanh[Tanh[a + b*x]])/429 - (4*b*x^(11/2)*ArcTanh[Tanh[a + b*x]]^2)/33 + (2*x^(9/2)*ArcTanh[Tanh[a + b*x]]^3)/9}
{x^(5/2)*ArcTanh[Tanh[a + b*x]]^3, x, 4, (-32*b^3*x^(13/2))/3003 + (16*b^2*x^(11/2)*ArcTanh[Tanh[a + b*x]])/231 - (4*b*x^(9/2)*ArcTanh[Tanh[a + b*x]]^2)/21 + (2*x^(7/2)*ArcTanh[Tanh[a + b*x]]^3)/7}
{x^(3/2)*ArcTanh[Tanh[a + b*x]]^3, x, 4, (-32*b^3*x^(11/2))/1155 + (16*b^2*x^(9/2)*ArcTanh[Tanh[a + b*x]])/105 - (12*b*x^(7/2)*ArcTanh[Tanh[a + b*x]]^2)/35 + (2*x^(5/2)*ArcTanh[Tanh[a + b*x]]^3)/5}
{Sqrt[x]*ArcTanh[Tanh[a + b*x]]^3, x, 4, (-32*b^3*x^(9/2))/315 + (16*b^2*x^(7/2)*ArcTanh[Tanh[a + b*x]])/35 - (4*b*x^(5/2)*ArcTanh[Tanh[a + b*x]]^2)/5 + (2*x^(3/2)*ArcTanh[Tanh[a + b*x]]^3)/3}
{ArcTanh[Tanh[a + b*x]]^3/Sqrt[x], x, 4, (-32*b^3*x^(7/2))/35 + (16*b^2*x^(5/2)*ArcTanh[Tanh[a + b*x]])/5 - 4*b*x^(3/2)*ArcTanh[Tanh[a + b*x]]^2 + 2*Sqrt[x]*ArcTanh[Tanh[a + b*x]]^3}
{ArcTanh[Tanh[a + b*x]]^3/x^(3/2), x, 4, (32*b^3*x^(5/2))/5 - 16*b^2*x^(3/2)*ArcTanh[Tanh[a + b*x]] + 12*b*Sqrt[x]*ArcTanh[Tanh[a + b*x]]^2 - (2*ArcTanh[Tanh[a + b*x]]^3)/Sqrt[x]}
{ArcTanh[Tanh[a + b*x]]^3/x^(5/2), x, 4, (-32*b^3*x^(3/2))/3 + 16*b^2*Sqrt[x]*ArcTanh[Tanh[a + b*x]] - (4*b*ArcTanh[Tanh[a + b*x]]^2)/Sqrt[x] - (2*ArcTanh[Tanh[a + b*x]]^3)/(3*x^(3/2))}
{ArcTanh[Tanh[a + b*x]]^3/x^(7/2), x, 4, (32*b^3*Sqrt[x])/5 - (16*b^2*ArcTanh[Tanh[a + b*x]])/(5*Sqrt[x]) - (4*b*ArcTanh[Tanh[a + b*x]]^2)/(5*x^(3/2)) - (2*ArcTanh[Tanh[a + b*x]]^3)/(5*x^(5/2))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{x^(7/2)/ArcTanh[Tanh[a + b*x]], x, 5, (2*x^(7/2))/(7*b) + (2*x^(5/2)*(b*x - ArcTanh[Tanh[a + b*x]]))/(5*b^2) + (2*x^(3/2)*(b*x - ArcTanh[Tanh[a + b*x]])^2)/(3*b^3) + (2*Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])^3)/b^4 - (2*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]]*(b*x - ArcTanh[Tanh[a + b*x]])^(7/2))/b^(9/2)}
{x^(5/2)/ArcTanh[Tanh[a + b*x]], x, 4, (2*x^(5/2))/(5*b) + (2*x^(3/2)*(b*x - ArcTanh[Tanh[a + b*x]]))/(3*b^2) + (2*Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])^2)/b^3 - (2*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]]*(b*x - ArcTanh[Tanh[a + b*x]])^(5/2))/b^(7/2)}
{x^(3/2)/ArcTanh[Tanh[a + b*x]], x, 3, (2*x^(3/2))/(3*b) + (2*Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]]))/b^2 - (2*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]]*(b*x - ArcTanh[Tanh[a + b*x]])^(3/2))/b^(5/2)}
{Sqrt[x]/ArcTanh[Tanh[a + b*x]], x, 2, (2*Sqrt[x])/b - (2*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]]*Sqrt[b*x - ArcTanh[Tanh[a + b*x]]])/b^(3/2)}
{1/(Sqrt[x]*ArcTanh[Tanh[a + b*x]]), x, 1, (-2*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]])/(Sqrt[b]*Sqrt[b*x - ArcTanh[Tanh[a + b*x]]])}
{1/(x^(3/2)*ArcTanh[Tanh[a + b*x]]), x, 2, (-2*Sqrt[b]*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]])/(b*x - ArcTanh[Tanh[a + b*x]])^(3/2) + 2/(Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]]))}
{1/(x^(5/2)*ArcTanh[Tanh[a + b*x]]), x, 3, (-2*b^(3/2)*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]])/(b*x - ArcTanh[Tanh[a + b*x]])^(5/2) + (2*b)/(Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])^2) + 2/(3*x^(3/2)*(b*x - ArcTanh[Tanh[a + b*x]]))}
{1/(x^(7/2)*ArcTanh[Tanh[a + b*x]]), x, 4, (-2*b^(5/2)*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]])/(b*x - ArcTanh[Tanh[a + b*x]])^(7/2) + (2*b^2)/(Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])^3) + (2*b)/(3*x^(3/2)*(b*x - ArcTanh[Tanh[a + b*x]])^2) + 2/(5*x^(5/2)*(b*x - ArcTanh[Tanh[a + b*x]]))}


{x^(7/2)/ArcTanh[Tanh[a + b*x]]^2, x, 5, (7*x^(5/2))/(5*b^2) + (7*x^(3/2)*(b*x - ArcTanh[Tanh[a + b*x]]))/(3*b^3) + (7*Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])^2)/b^4 - (7*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]]*(b*x - ArcTanh[Tanh[a + b*x]])^(5/2))/b^(9/2) - x^(7/2)/(b*ArcTanh[Tanh[a + b*x]])}
{x^(5/2)/ArcTanh[Tanh[a + b*x]]^2, x, 4, (5*x^(3/2))/(3*b^2) + (5*Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]]))/b^3 - (5*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]]*(b*x - ArcTanh[Tanh[a + b*x]])^(3/2))/b^(7/2) - x^(5/2)/(b*ArcTanh[Tanh[a + b*x]])}
{x^(3/2)/ArcTanh[Tanh[a + b*x]]^2, x, 3, (3*Sqrt[x])/b^2 - (3*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]]*Sqrt[b*x - ArcTanh[Tanh[a + b*x]]])/b^(5/2) - x^(3/2)/(b*ArcTanh[Tanh[a + b*x]])}
{Sqrt[x]/ArcTanh[Tanh[a + b*x]]^2, x, 2, -(ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]]/(b^(3/2)*Sqrt[b*x - ArcTanh[Tanh[a + b*x]]])) - Sqrt[x]/(b*ArcTanh[Tanh[a + b*x]])}
{1/(Sqrt[x]*ArcTanh[Tanh[a + b*x]]^2), x, 3, ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]]/(Sqrt[b]*(b*x - ArcTanh[Tanh[a + b*x]])^(3/2)) - 1/(b*Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])) - 1/(b*Sqrt[x]*ArcTanh[Tanh[a + b*x]])}
{1/(x^(3/2)*ArcTanh[Tanh[a + b*x]]^2), x, 4, (3*Sqrt[b]*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]])/(b*x - ArcTanh[Tanh[a + b*x]])^(5/2) - 3/(Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])^2) - 1/(b*x^(3/2)*(b*x - ArcTanh[Tanh[a + b*x]])) - 1/(b*x^(3/2)*ArcTanh[Tanh[a + b*x]])}
{1/(x^(5/2)*ArcTanh[Tanh[a + b*x]]^2), x, 5, (5*b^(3/2)*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]])/(b*x - ArcTanh[Tanh[a + b*x]])^(7/2) - (5*b)/(Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])^3) - 5/(3*x^(3/2)*(b*x - ArcTanh[Tanh[a + b*x]])^2) - 1/(b*x^(5/2)*(b*x - ArcTanh[Tanh[a + b*x]])) - 1/(b*x^(5/2)*ArcTanh[Tanh[a + b*x]])}
{1/(x^(7/2)*ArcTanh[Tanh[a + b*x]]^2), x, 6, (7*b^(5/2)*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]])/(b*x - ArcTanh[Tanh[a + b*x]])^(9/2) - (7*b^2)/(Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])^4) - (7*b)/(3*x^(3/2)*(b*x - ArcTanh[Tanh[a + b*x]])^3) - 7/(5*x^(5/2)*(b*x - ArcTanh[Tanh[a + b*x]])^2) - 1/(b*x^(7/2)*(b*x - ArcTanh[Tanh[a + b*x]])) - 1/(b*x^(7/2)*ArcTanh[Tanh[a + b*x]])}


{x^(7/2)/ArcTanh[Tanh[a + b*x]]^3, x, 5, (35*x^(3/2))/(12*b^3) + (35*Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]]))/(4*b^4) - (35*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]]*(b*x - ArcTanh[Tanh[a + b*x]])^(3/2))/(4*b^(9/2)) - x^(7/2)/(2*b*ArcTanh[Tanh[a + b*x]]^2) - (7*x^(5/2))/(4*b^2*ArcTanh[Tanh[a + b*x]])}
{x^(5/2)/ArcTanh[Tanh[a + b*x]]^3, x, 4, (15*Sqrt[x])/(4*b^3) - (15*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]]*Sqrt[b*x - ArcTanh[Tanh[a + b*x]]])/(4*b^(7/2)) - x^(5/2)/(2*b*ArcTanh[Tanh[a + b*x]]^2) - (5*x^(3/2))/(4*b^2*ArcTanh[Tanh[a + b*x]])}
{x^(3/2)/ArcTanh[Tanh[a + b*x]]^3, x, 3, (-3*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]])/(4*b^(5/2)*Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]) - x^(3/2)/(2*b*ArcTanh[Tanh[a + b*x]]^2) - (3*Sqrt[x])/(4*b^2*ArcTanh[Tanh[a + b*x]])}
{Sqrt[x]/ArcTanh[Tanh[a + b*x]]^3, x, 4, ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]]/(4*b^(3/2)*(b*x - ArcTanh[Tanh[a + b*x]])^(3/2)) - 1/(4*b^2*Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])) - Sqrt[x]/(2*b*ArcTanh[Tanh[a + b*x]]^2) - 1/(4*b^2*Sqrt[x]*ArcTanh[Tanh[a + b*x]])}
{1/(Sqrt[x]*ArcTanh[Tanh[a + b*x]]^3), x, 5, (-3*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]])/(4*Sqrt[b]*(b*x - ArcTanh[Tanh[a + b*x]])^(5/2)) + 3/(4*b*Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])^2) + 1/(4*b^2*x^(3/2)*(b*x - ArcTanh[Tanh[a + b*x]])) - 1/(2*b*Sqrt[x]*ArcTanh[Tanh[a + b*x]]^2) + 1/(4*b^2*x^(3/2)*ArcTanh[Tanh[a + b*x]])}
{1/(x^(3/2)*ArcTanh[Tanh[a + b*x]]^3), x, 6, (-15*Sqrt[b]*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]])/(4*(b*x - ArcTanh[Tanh[a + b*x]])^(7/2)) + 15/(4*Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])^3) + 5/(4*b*x^(3/2)*(b*x - ArcTanh[Tanh[a + b*x]])^2) + 3/(4*b^2*x^(5/2)*(b*x - ArcTanh[Tanh[a + b*x]])) - 1/(2*b*x^(3/2)*ArcTanh[Tanh[a + b*x]]^2) + 3/(4*b^2*x^(5/2)*ArcTanh[Tanh[a + b*x]])}
{1/(x^(5/2)*ArcTanh[Tanh[a + b*x]]^3), x, 7, (-35*b^(3/2)*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]])/(4*(b*x - ArcTanh[Tanh[a + b*x]])^(9/2)) + (35*b)/(4*Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])^4) + 35/(12*x^(3/2)*(b*x - ArcTanh[Tanh[a + b*x]])^3) + 7/(4*b*x^(5/2)*(b*x - ArcTanh[Tanh[a + b*x]])^2) + 5/(4*b^2*x^(7/2)*(b*x - ArcTanh[Tanh[a + b*x]])) - 1/(2*b*x^(5/2)*ArcTanh[Tanh[a + b*x]]^2) + 5/(4*b^2*x^(7/2)*ArcTanh[Tanh[a + b*x]])}
{1/(x^(7/2)*ArcTanh[Tanh[a + b*x]]^3), x, 8, (-63*b^(5/2)*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[b*x - ArcTanh[Tanh[a + b*x]]]])/(4*(b*x - ArcTanh[Tanh[a + b*x]])^(11/2)) + (63*b^2)/(4*Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])^5) + (21*b)/(4*x^(3/2)*(b*x - ArcTanh[Tanh[a + b*x]])^4) + 63/(20*x^(5/2)*(b*x - ArcTanh[Tanh[a + b*x]])^3) + 9/(4*b*x^(7/2)*(b*x - ArcTanh[Tanh[a + b*x]])^2) + 7/(4*b^2*x^(9/2)*(b*x - ArcTanh[Tanh[a + b*x]])) - 1/(2*b*x^(7/2)*ArcTanh[Tanh[a + b*x]]^2) + 7/(4*b^2*x^(9/2)*ArcTanh[Tanh[a + b*x]])}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^(m/2) ArcTanh[Tanh[a+b x]]^(n/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{ArcTanh[Tanh[a + b*x]]^(1/2)*x^(3/2), x, 4, -((ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[ArcTanh[Tanh[a + b*x]]]]*(b*x - ArcTanh[Tanh[a + b*x]])^3)/(8*b^(5/2))) + (1/3)*x^(5/2)*Sqrt[ArcTanh[Tanh[a + b*x]]] - (x^(3/2)*(b*x - ArcTanh[Tanh[a + b*x]])*Sqrt[ArcTanh[Tanh[a + b*x]]])/(12*b) - (Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])^2*Sqrt[ArcTanh[Tanh[a + b*x]]])/(8*b^2)}
{ArcTanh[Tanh[a + b*x]]^(1/2)*x^(1/2), x, 3, -((ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[ArcTanh[Tanh[a + b*x]]]]*(b*x - ArcTanh[Tanh[a + b*x]])^2)/(4*b^(3/2))) + (1/2)*x^(3/2)*Sqrt[ArcTanh[Tanh[a + b*x]]] - (Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])*Sqrt[ArcTanh[Tanh[a + b*x]]])/(4*b)}
{ArcTanh[Tanh[a + b*x]]^(1/2)/x^(1/2), x, 2, -((ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[ArcTanh[Tanh[a + b*x]]]]*(b*x - ArcTanh[Tanh[a + b*x]]))/Sqrt[b]) + Sqrt[x]*Sqrt[ArcTanh[Tanh[a + b*x]]]}
{ArcTanh[Tanh[a + b*x]]^(1/2)/x^(3/2), x, 2, 2*Sqrt[b]*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[ArcTanh[Tanh[a + b*x]]]] - (2*Sqrt[ArcTanh[Tanh[a + b*x]]])/Sqrt[x]}
{ArcTanh[Tanh[a + b*x]]^(1/2)/x^(5/2), x, 1, (2*ArcTanh[Tanh[a + b*x]]^(3/2))/(3*x^(3/2)*(b*x - ArcTanh[Tanh[a + b*x]]))}
{ArcTanh[Tanh[a + b*x]]^(1/2)/x^(7/2), x, 2, (4*b*ArcTanh[Tanh[a + b*x]]^(3/2))/(15*x^(3/2)*(b*x - ArcTanh[Tanh[a + b*x]])^2) + (2*ArcTanh[Tanh[a + b*x]]^(3/2))/(5*x^(5/2)*(b*x - ArcTanh[Tanh[a + b*x]]))}
{ArcTanh[Tanh[a + b*x]]^(1/2)/x^(9/2), x, 3, (16*b^2*ArcTanh[Tanh[a + b*x]]^(3/2))/(105*x^(3/2)*(b*x - ArcTanh[Tanh[a + b*x]])^3) + (8*b*ArcTanh[Tanh[a + b*x]]^(3/2))/(35*x^(5/2)*(b*x - ArcTanh[Tanh[a + b*x]])^2) + (2*ArcTanh[Tanh[a + b*x]]^(3/2))/(7*x^(7/2)*(b*x - ArcTanh[Tanh[a + b*x]]))}
{ArcTanh[Tanh[a + b*x]]^(1/2)/x^(11/2), x, 4, (32*b^3*ArcTanh[Tanh[a + b*x]]^(3/2))/(315*x^(3/2)*(b*x - ArcTanh[Tanh[a + b*x]])^4) + (16*b^2*ArcTanh[Tanh[a + b*x]]^(3/2))/(105*x^(5/2)*(b*x - ArcTanh[Tanh[a + b*x]])^3) + (4*b*ArcTanh[Tanh[a + b*x]]^(3/2))/(21*x^(7/2)*(b*x - ArcTanh[Tanh[a + b*x]])^2) + (2*ArcTanh[Tanh[a + b*x]]^(3/2))/(9*x^(9/2)*(b*x - ArcTanh[Tanh[a + b*x]]))}


{ArcTanh[Tanh[a + b*x]]^(3/2)*x^(3/2), x, 5, (3*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[ArcTanh[Tanh[a + b*x]]]]*(b*x - ArcTanh[Tanh[a + b*x]])^4)/(64*b^(5/2)) - (1/8)*x^(5/2)*(b*x - ArcTanh[Tanh[a + b*x]])*Sqrt[ArcTanh[Tanh[a + b*x]]] + (x^(3/2)*(b*x - ArcTanh[Tanh[a + b*x]])^2*Sqrt[ArcTanh[Tanh[a + b*x]]])/(32*b) + (3*Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])^3*Sqrt[ArcTanh[Tanh[a + b*x]]])/(64*b^2) + (1/4)*x^(5/2)*ArcTanh[Tanh[a + b*x]]^(3/2)}
{ArcTanh[Tanh[a + b*x]]^(3/2)*x^(1/2), x, 4, (ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[ArcTanh[Tanh[a + b*x]]]]*(b*x - ArcTanh[Tanh[a + b*x]])^3)/(8*b^(3/2)) - (1/4)*x^(3/2)*(b*x - ArcTanh[Tanh[a + b*x]])*Sqrt[ArcTanh[Tanh[a + b*x]]] + (Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])^2*Sqrt[ArcTanh[Tanh[a + b*x]]])/(8*b) + (1/3)*x^(3/2)*ArcTanh[Tanh[a + b*x]]^(3/2)}
{ArcTanh[Tanh[a + b*x]]^(3/2)/x^(1/2), x, 3, (3*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[ArcTanh[Tanh[a + b*x]]]]*(b*x - ArcTanh[Tanh[a + b*x]])^2)/(4*Sqrt[b]) - (3/4)*Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])*Sqrt[ArcTanh[Tanh[a + b*x]]] + (1/2)*Sqrt[x]*ArcTanh[Tanh[a + b*x]]^(3/2)}
{ArcTanh[Tanh[a + b*x]]^(3/2)/x^(3/2), x, 3, -3*Sqrt[b]*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[ArcTanh[Tanh[a + b*x]]]]*(b*x - ArcTanh[Tanh[a + b*x]]) + 3*b*Sqrt[x]*Sqrt[ArcTanh[Tanh[a + b*x]]] - (2*ArcTanh[Tanh[a + b*x]]^(3/2))/Sqrt[x]}
{ArcTanh[Tanh[a + b*x]]^(3/2)/x^(5/2), x, 3, 2*b^(3/2)*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[ArcTanh[Tanh[a + b*x]]]] - (2*b*Sqrt[ArcTanh[Tanh[a + b*x]]])/Sqrt[x] - (2*ArcTanh[Tanh[a + b*x]]^(3/2))/(3*x^(3/2))}
{ArcTanh[Tanh[a + b*x]]^(3/2)/x^(7/2), x, 1, (2*ArcTanh[Tanh[a + b*x]]^(5/2))/(5*x^(5/2)*(b*x - ArcTanh[Tanh[a + b*x]]))}
{ArcTanh[Tanh[a + b*x]]^(3/2)/x^(9/2), x, 2, (4*b*ArcTanh[Tanh[a + b*x]]^(5/2))/(35*x^(5/2)*(b*x - ArcTanh[Tanh[a + b*x]])^2) + (2*ArcTanh[Tanh[a + b*x]]^(5/2))/(7*x^(7/2)*(b*x - ArcTanh[Tanh[a + b*x]]))}
{ArcTanh[Tanh[a + b*x]]^(3/2)/x^(11/2), x, 3, (16*b^2*ArcTanh[Tanh[a + b*x]]^(5/2))/(315*x^(5/2)*(b*x - ArcTanh[Tanh[a + b*x]])^3) + (8*b*ArcTanh[Tanh[a + b*x]]^(5/2))/(63*x^(7/2)*(b*x - ArcTanh[Tanh[a + b*x]])^2) + (2*ArcTanh[Tanh[a + b*x]]^(5/2))/(9*x^(9/2)*(b*x - ArcTanh[Tanh[a + b*x]]))}
{ArcTanh[Tanh[a + b*x]]^(3/2)/x^(13/2), x, 4, (32*b^3*ArcTanh[Tanh[a + b*x]]^(5/2))/(1155*x^(5/2)*(b*x - ArcTanh[Tanh[a + b*x]])^4) + (16*b^2*ArcTanh[Tanh[a + b*x]]^(5/2))/(231*x^(7/2)*(b*x - ArcTanh[Tanh[a + b*x]])^3) + (4*b*ArcTanh[Tanh[a + b*x]]^(5/2))/(33*x^(9/2)*(b*x - ArcTanh[Tanh[a + b*x]])^2) + (2*ArcTanh[Tanh[a + b*x]]^(5/2))/(11*x^(11/2)*(b*x - ArcTanh[Tanh[a + b*x]]))}


{ArcTanh[Tanh[a + b*x]]^(5/2)*x^(1/2), x, 5, -((5*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[ArcTanh[Tanh[a + b*x]]]]*(b*x - ArcTanh[Tanh[a + b*x]])^4)/(64*b^(3/2))) + (5/32)*x^(3/2)*(b*x - ArcTanh[Tanh[a + b*x]])^2*Sqrt[ArcTanh[Tanh[a + b*x]]] - (5*Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])^3*Sqrt[ArcTanh[Tanh[a + b*x]]])/(64*b) - (5/24)*x^(3/2)*(b*x - ArcTanh[Tanh[a + b*x]])*ArcTanh[Tanh[a + b*x]]^(3/2) + (1/4)*x^(3/2)*ArcTanh[Tanh[a + b*x]]^(5/2)}
{ArcTanh[Tanh[a + b*x]]^(5/2)/x^(1/2), x, 4, -((5*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[ArcTanh[Tanh[a + b*x]]]]*(b*x - ArcTanh[Tanh[a + b*x]])^3)/(8*Sqrt[b])) + (5/8)*Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])^2*Sqrt[ArcTanh[Tanh[a + b*x]]] - (5/12)*Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])*ArcTanh[Tanh[a + b*x]]^(3/2) + (1/3)*Sqrt[x]*ArcTanh[Tanh[a + b*x]]^(5/2)}
{ArcTanh[Tanh[a + b*x]]^(5/2)/x^(3/2), x, 4, (15/4)*Sqrt[b]*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[ArcTanh[Tanh[a + b*x]]]]*(b*x - ArcTanh[Tanh[a + b*x]])^2 - (15/4)*b*Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])*Sqrt[ArcTanh[Tanh[a + b*x]]] + (5/2)*b*Sqrt[x]*ArcTanh[Tanh[a + b*x]]^(3/2) - (2*ArcTanh[Tanh[a + b*x]]^(5/2))/Sqrt[x]}
{ArcTanh[Tanh[a + b*x]]^(5/2)/x^(5/2), x, 4, -5*b^(3/2)*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[ArcTanh[Tanh[a + b*x]]]]*(b*x - ArcTanh[Tanh[a + b*x]]) + 5*b^2*Sqrt[x]*Sqrt[ArcTanh[Tanh[a + b*x]]] - (10*b*ArcTanh[Tanh[a + b*x]]^(3/2))/(3*Sqrt[x]) - (2*ArcTanh[Tanh[a + b*x]]^(5/2))/(3*x^(3/2))}
{ArcTanh[Tanh[a + b*x]]^(5/2)/x^(7/2), x, 4, 2*b^(5/2)*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[ArcTanh[Tanh[a + b*x]]]] - (2*b^2*Sqrt[ArcTanh[Tanh[a + b*x]]])/Sqrt[x] - (2*b*ArcTanh[Tanh[a + b*x]]^(3/2))/(3*x^(3/2)) - (2*ArcTanh[Tanh[a + b*x]]^(5/2))/(5*x^(5/2))}
{ArcTanh[Tanh[a + b*x]]^(5/2)/x^(9/2), x, 1, (2*ArcTanh[Tanh[a + b*x]]^(7/2))/(7*x^(7/2)*(b*x - ArcTanh[Tanh[a + b*x]]))}
{ArcTanh[Tanh[a + b*x]]^(5/2)/x^(11/2), x, 2, (4*b*ArcTanh[Tanh[a + b*x]]^(7/2))/(63*x^(7/2)*(b*x - ArcTanh[Tanh[a + b*x]])^2) + (2*ArcTanh[Tanh[a + b*x]]^(7/2))/(9*x^(9/2)*(b*x - ArcTanh[Tanh[a + b*x]]))}
{ArcTanh[Tanh[a + b*x]]^(5/2)/x^(13/2), x, 3, (16*b^2*ArcTanh[Tanh[a + b*x]]^(7/2))/(693*x^(7/2)*(b*x - ArcTanh[Tanh[a + b*x]])^3) + (8*b*ArcTanh[Tanh[a + b*x]]^(7/2))/(99*x^(9/2)*(b*x - ArcTanh[Tanh[a + b*x]])^2) + (2*ArcTanh[Tanh[a + b*x]]^(7/2))/(11*x^(11/2)*(b*x - ArcTanh[Tanh[a + b*x]]))}
{ArcTanh[Tanh[a + b*x]]^(5/2)/x^(15/2), x, 4, (32*b^3*ArcTanh[Tanh[a + b*x]]^(7/2))/(3003*x^(7/2)*(b*x - ArcTanh[Tanh[a + b*x]])^4) + (16*b^2*ArcTanh[Tanh[a + b*x]]^(7/2))/(429*x^(9/2)*(b*x - ArcTanh[Tanh[a + b*x]])^3) + (12*b*ArcTanh[Tanh[a + b*x]]^(7/2))/(143*x^(11/2)*(b*x - ArcTanh[Tanh[a + b*x]])^2) + (2*ArcTanh[Tanh[a + b*x]]^(7/2))/(13*x^(13/2)*(b*x - ArcTanh[Tanh[a + b*x]]))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{1/ArcTanh[Tanh[a + b*x]]^(1/2)*x^(5/2), x, 4, (5*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[ArcTanh[Tanh[a + b*x]]]]*(b*x - ArcTanh[Tanh[a + b*x]])^3)/(8*b^(7/2)) + (x^(5/2)*Sqrt[ArcTanh[Tanh[a + b*x]]])/(3*b) + (5*x^(3/2)*(b*x - ArcTanh[Tanh[a + b*x]])*Sqrt[ArcTanh[Tanh[a + b*x]]])/(12*b^2) + (5*Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])^2*Sqrt[ArcTanh[Tanh[a + b*x]]])/(8*b^3)}
{1/ArcTanh[Tanh[a + b*x]]^(1/2)*x^(3/2), x, 3, (3*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[ArcTanh[Tanh[a + b*x]]]]*(b*x - ArcTanh[Tanh[a + b*x]])^2)/(4*b^(5/2)) + (x^(3/2)*Sqrt[ArcTanh[Tanh[a + b*x]]])/(2*b) + (3*Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])*Sqrt[ArcTanh[Tanh[a + b*x]]])/(4*b^2)}
{1/ArcTanh[Tanh[a + b*x]]^(1/2)*x^(1/2), x, 2, (ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[ArcTanh[Tanh[a + b*x]]]]*(b*x - ArcTanh[Tanh[a + b*x]]))/b^(3/2) + (Sqrt[x]*Sqrt[ArcTanh[Tanh[a + b*x]]])/b}
{1/ArcTanh[Tanh[a + b*x]]^(1/2)/x^(1/2), x, 1, (2*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[ArcTanh[Tanh[a + b*x]]]])/Sqrt[b]}
{1/ArcTanh[Tanh[a + b*x]]^(1/2)/x^(3/2), x, 1, (2*Sqrt[ArcTanh[Tanh[a + b*x]]])/(Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]]))}
{1/ArcTanh[Tanh[a + b*x]]^(1/2)/x^(5/2), x, 2, (4*b*Sqrt[ArcTanh[Tanh[a + b*x]]])/(3*Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])^2) + (2*Sqrt[ArcTanh[Tanh[a + b*x]]])/(3*x^(3/2)*(b*x - ArcTanh[Tanh[a + b*x]]))}
{1/ArcTanh[Tanh[a + b*x]]^(1/2)/x^(7/2), x, 3, (16*b^2*Sqrt[ArcTanh[Tanh[a + b*x]]])/(15*Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])^3) + (8*b*Sqrt[ArcTanh[Tanh[a + b*x]]])/(15*x^(3/2)*(b*x - ArcTanh[Tanh[a + b*x]])^2) + (2*Sqrt[ArcTanh[Tanh[a + b*x]]])/(5*x^(5/2)*(b*x - ArcTanh[Tanh[a + b*x]]))}
{1/ArcTanh[Tanh[a + b*x]]^(1/2)/x^(9/2), x, 4, (32*b^3*Sqrt[ArcTanh[Tanh[a + b*x]]])/(35*Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])^4) + (16*b^2*Sqrt[ArcTanh[Tanh[a + b*x]]])/(35*x^(3/2)*(b*x - ArcTanh[Tanh[a + b*x]])^3) + (12*b*Sqrt[ArcTanh[Tanh[a + b*x]]])/(35*x^(5/2)*(b*x - ArcTanh[Tanh[a + b*x]])^2) + (2*Sqrt[ArcTanh[Tanh[a + b*x]]])/(7*x^(7/2)*(b*x - ArcTanh[Tanh[a + b*x]]))}


{1/ArcTanh[Tanh[a + b*x]]^(3/2)*x^(7/2), x, 5, (35*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[ArcTanh[Tanh[a + b*x]]]]*(b*x - ArcTanh[Tanh[a + b*x]])^3)/(8*b^(9/2)) - (2*x^(7/2))/(b*Sqrt[ArcTanh[Tanh[a + b*x]]]) + (7*x^(5/2)*Sqrt[ArcTanh[Tanh[a + b*x]]])/(3*b^2) + (35*x^(3/2)*(b*x - ArcTanh[Tanh[a + b*x]])*Sqrt[ArcTanh[Tanh[a + b*x]]])/(12*b^3) + (35*Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])^2*Sqrt[ArcTanh[Tanh[a + b*x]]])/(8*b^4)}
{1/ArcTanh[Tanh[a + b*x]]^(3/2)*x^(5/2), x, 4, (15*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[ArcTanh[Tanh[a + b*x]]]]*(b*x - ArcTanh[Tanh[a + b*x]])^2)/(4*b^(7/2)) - (2*x^(5/2))/(b*Sqrt[ArcTanh[Tanh[a + b*x]]]) + (5*x^(3/2)*Sqrt[ArcTanh[Tanh[a + b*x]]])/(2*b^2) + (15*Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])*Sqrt[ArcTanh[Tanh[a + b*x]]])/(4*b^3)}
{1/ArcTanh[Tanh[a + b*x]]^(3/2)*x^(3/2), x, 3, (3*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[ArcTanh[Tanh[a + b*x]]]]*(b*x - ArcTanh[Tanh[a + b*x]]))/b^(5/2) - (2*x^(3/2))/(b*Sqrt[ArcTanh[Tanh[a + b*x]]]) + (3*Sqrt[x]*Sqrt[ArcTanh[Tanh[a + b*x]]])/b^2}
{1/ArcTanh[Tanh[a + b*x]]^(3/2)*x^(1/2), x, 2, (2*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[ArcTanh[Tanh[a + b*x]]]])/b^(3/2) - (2*Sqrt[x])/(b*Sqrt[ArcTanh[Tanh[a + b*x]]])}
{1/ArcTanh[Tanh[a + b*x]]^(3/2)/x^(1/2), x, 1, -((2*Sqrt[x])/((b*x - ArcTanh[Tanh[a + b*x]])*Sqrt[ArcTanh[Tanh[a + b*x]]]))}
{1/ArcTanh[Tanh[a + b*x]]^(3/2)/x^(3/2), x, 2, -((4*b*Sqrt[x])/((b*x - ArcTanh[Tanh[a + b*x]])^2*Sqrt[ArcTanh[Tanh[a + b*x]]])) + 2/(Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])*Sqrt[ArcTanh[Tanh[a + b*x]]])}
{1/ArcTanh[Tanh[a + b*x]]^(3/2)/x^(5/2), x, 3, -((16*b^2*Sqrt[x])/(3*(b*x - ArcTanh[Tanh[a + b*x]])^3*Sqrt[ArcTanh[Tanh[a + b*x]]])) + (8*b)/(3*Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])^2*Sqrt[ArcTanh[Tanh[a + b*x]]]) + 2/(3*x^(3/2)*(b*x - ArcTanh[Tanh[a + b*x]])*Sqrt[ArcTanh[Tanh[a + b*x]]])}
{1/ArcTanh[Tanh[a + b*x]]^(3/2)/x^(7/2), x, 4, -((32*b^3*Sqrt[x])/(5*(b*x - ArcTanh[Tanh[a + b*x]])^4*Sqrt[ArcTanh[Tanh[a + b*x]]])) + (16*b^2)/(5*Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])^3*Sqrt[ArcTanh[Tanh[a + b*x]]]) + (4*b)/(5*x^(3/2)*(b*x - ArcTanh[Tanh[a + b*x]])^2*Sqrt[ArcTanh[Tanh[a + b*x]]]) + 2/(5*x^(5/2)*(b*x - ArcTanh[Tanh[a + b*x]])*Sqrt[ArcTanh[Tanh[a + b*x]]])}


{1/ArcTanh[Tanh[a + b*x]]^(5/2)*x^(7/2), x, 5, (35*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[ArcTanh[Tanh[a + b*x]]]]*(b*x - ArcTanh[Tanh[a + b*x]])^2)/(4*b^(9/2)) - (2*x^(7/2))/(3*b*ArcTanh[Tanh[a + b*x]]^(3/2)) - (14*x^(5/2))/(3*b^2*Sqrt[ArcTanh[Tanh[a + b*x]]]) + (35*x^(3/2)*Sqrt[ArcTanh[Tanh[a + b*x]]])/(6*b^3) + (35*Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])*Sqrt[ArcTanh[Tanh[a + b*x]]])/(4*b^4)}
{1/ArcTanh[Tanh[a + b*x]]^(5/2)*x^(5/2), x, 4, (5*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[ArcTanh[Tanh[a + b*x]]]]*(b*x - ArcTanh[Tanh[a + b*x]]))/b^(7/2) - (2*x^(5/2))/(3*b*ArcTanh[Tanh[a + b*x]]^(3/2)) - (10*x^(3/2))/(3*b^2*Sqrt[ArcTanh[Tanh[a + b*x]]]) + (5*Sqrt[x]*Sqrt[ArcTanh[Tanh[a + b*x]]])/b^3}
{1/ArcTanh[Tanh[a + b*x]]^(5/2)*x^(3/2), x, 3, (2*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[ArcTanh[Tanh[a + b*x]]]])/b^(5/2) - (2*x^(3/2))/(3*b*ArcTanh[Tanh[a + b*x]]^(3/2)) - (2*Sqrt[x])/(b^2*Sqrt[ArcTanh[Tanh[a + b*x]]])}
{1/ArcTanh[Tanh[a + b*x]]^(5/2)*x^(1/2), x, 1, -((2*x^(3/2))/(3*(b*x - ArcTanh[Tanh[a + b*x]])*ArcTanh[Tanh[a + b*x]]^(3/2)))}
{1/ArcTanh[Tanh[a + b*x]]^(5/2)/x^(1/2), x, 2, -((2*Sqrt[x])/(3*(b*x - ArcTanh[Tanh[a + b*x]])*ArcTanh[Tanh[a + b*x]]^(3/2))) + (4*Sqrt[x])/(3*(b*x - ArcTanh[Tanh[a + b*x]])^2*Sqrt[ArcTanh[Tanh[a + b*x]]])}
{1/ArcTanh[Tanh[a + b*x]]^(5/2)/x^(3/2), x, 3, -((8*b*Sqrt[x])/(3*(b*x - ArcTanh[Tanh[a + b*x]])^2*ArcTanh[Tanh[a + b*x]]^(3/2))) + 2/(Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])*ArcTanh[Tanh[a + b*x]]^(3/2)) + (16*b*Sqrt[x])/(3*(b*x - ArcTanh[Tanh[a + b*x]])^3*Sqrt[ArcTanh[Tanh[a + b*x]]])}
{1/ArcTanh[Tanh[a + b*x]]^(5/2)/x^(5/2), x, 4, -((16*b^2*Sqrt[x])/(3*(b*x - ArcTanh[Tanh[a + b*x]])^3*ArcTanh[Tanh[a + b*x]]^(3/2))) + (4*b)/(Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])^2*ArcTanh[Tanh[a + b*x]]^(3/2)) + 2/(3*x^(3/2)*(b*x - ArcTanh[Tanh[a + b*x]])*ArcTanh[Tanh[a + b*x]]^(3/2)) + (32*b^2*Sqrt[x])/(3*(b*x - ArcTanh[Tanh[a + b*x]])^4*Sqrt[ArcTanh[Tanh[a + b*x]]])}
{1/ArcTanh[Tanh[a + b*x]]^(5/2)/x^(7/2), x, 5, -((128*b^3*Sqrt[x])/(15*(b*x - ArcTanh[Tanh[a + b*x]])^4*ArcTanh[Tanh[a + b*x]]^(3/2))) + (32*b^2)/(5*Sqrt[x]*(b*x - ArcTanh[Tanh[a + b*x]])^3*ArcTanh[Tanh[a + b*x]]^(3/2)) + (16*b)/(15*x^(3/2)*(b*x - ArcTanh[Tanh[a + b*x]])^2*ArcTanh[Tanh[a + b*x]]^(3/2)) + 2/(5*x^(5/2)*(b*x - ArcTanh[Tanh[a + b*x]])*ArcTanh[Tanh[a + b*x]]^(3/2)) + (256*b^3*Sqrt[x])/(15*(b*x - ArcTanh[Tanh[a + b*x]])^5*Sqrt[ArcTanh[Tanh[a + b*x]]])}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcTanh[Tanh[a+b x]]^n when n symbolic*)


{ArcTanh[Tanh[a + b*x]]^n*x^m, x, 1, (1/(b*(1 + n)))*((x^m*ArcTanh[Tanh[a + b*x]]^(1 + n)*Hypergeometric2F1[-m, 1 + n, 2 + n, -(ArcTanh[Tanh[a + b*x]]/(b*x - ArcTanh[Tanh[a + b*x]]))])/((b*x)/(b*x - ArcTanh[Tanh[a + b*x]]))^m)}

{ArcTanh[Tanh[a + b*x]]^n*x^4, x, 6, (x^4*ArcTanh[Tanh[a + b*x]]^(1 + n))/(b*(1 + n)) - (4*x^3*ArcTanh[Tanh[a + b*x]]^(2 + n))/(b^2*(1 + n)*(2 + n)) + (12*x^2*ArcTanh[Tanh[a + b*x]]^(3 + n))/(b^3*(1 + n)*(2 + n)*(3 + n)) - (24*x*ArcTanh[Tanh[a + b*x]]^(4 + n))/(b^4*(1 + n)*(2 + n)*(3 + n)*(4 + n)) + (24*ArcTanh[Tanh[a + b*x]]^(5 + n))/(b^5*(1 + n)*(2 + n)*(3 + n)*(4 + n)*(5 + n))}
{ArcTanh[Tanh[a + b*x]]^n*x^3, x, 5, (x^3*ArcTanh[Tanh[a + b*x]]^(1 + n))/(b*(1 + n)) - (3*x^2*ArcTanh[Tanh[a + b*x]]^(2 + n))/(b^2*(1 + n)*(2 + n)) + (6*x*ArcTanh[Tanh[a + b*x]]^(3 + n))/(b^3*(1 + n)*(2 + n)*(3 + n)) - (6*ArcTanh[Tanh[a + b*x]]^(4 + n))/(b^4*(1 + n)*(2 + n)*(3 + n)*(4 + n))}
{ArcTanh[Tanh[a + b*x]]^n*x^2, x, 4, (x^2*ArcTanh[Tanh[a + b*x]]^(1 + n))/(b*(1 + n)) - (2*x*ArcTanh[Tanh[a + b*x]]^(2 + n))/(b^2*(1 + n)*(2 + n)) + (2*ArcTanh[Tanh[a + b*x]]^(3 + n))/(b^3*(1 + n)*(2 + n)*(3 + n))}
{ArcTanh[Tanh[a + b*x]]^n*x^1, x, 3, (x*ArcTanh[Tanh[a + b*x]]^(1 + n))/(b*(1 + n)) - ArcTanh[Tanh[a + b*x]]^(2 + n)/(b^2*(1 + n)*(2 + n))}
{ArcTanh[Tanh[a + b*x]]^n*x^0, x, 2, ArcTanh[Tanh[a + b*x]]^(1 + n)/(b*(1 + n))}
{ArcTanh[Tanh[a + b*x]]^n/x^1, x, 1, (ArcTanh[Tanh[a + b*x]]^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, -(ArcTanh[Tanh[a + b*x]]/(b*x - ArcTanh[Tanh[a + b*x]]))])/((1 + n)*(b*x - ArcTanh[Tanh[a + b*x]]))}
{ArcTanh[Tanh[a + b*x]]^n/x^2, x, 2, -(ArcTanh[Tanh[a + b*x]]^n/x) + (b*ArcTanh[Tanh[a + b*x]]^n*Hypergeometric2F1[1, n, 1 + n, -(ArcTanh[Tanh[a + b*x]]/(b*x - ArcTanh[Tanh[a + b*x]]))])/(b*x - ArcTanh[Tanh[a + b*x]])}
{ArcTanh[Tanh[a + b*x]]^n/x^3, x, 3, -((b*n*ArcTanh[Tanh[a + b*x]]^(-1 + n))/(2*x)) - ArcTanh[Tanh[a + b*x]]^n/(2*x^2) + (b^2*n*ArcTanh[Tanh[a + b*x]]^(-1 + n)*Hypergeometric2F1[1, -1 + n, n, -(ArcTanh[Tanh[a + b*x]]/(b*x - ArcTanh[Tanh[a + b*x]]))])/(2*(b*x - ArcTanh[Tanh[a + b*x]]))}


(* ::Section::Closed:: *)
(*Integrands of the form x^m ArcTanh[Coth[a+b x]]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcTanh[Coth[a+b x]]^n*)


{ArcCoth[Tanh[a + b*x]]*x^m, x, 2, -((b*x^(2 + m))/(2 + 3*m + m^2)) + (x^(1 + m)*ArcCoth[Tanh[a + b*x]])/(1 + m)}

{ArcTanh[Coth[a + b*x]]*x^2, x, 2, -((b*x^4)/12) + (1/3)*x^3*ArcTanh[Coth[a + b*x]]}
{ArcTanh[Coth[a + b*x]]*x^1, x, 2, -((b*x^3)/6) + (1/2)*x^2*ArcTanh[Coth[a + b*x]]}
{ArcTanh[Coth[a + b*x]]*x^0, x, 2, ArcTanh[Coth[a + b*x]]^2/(2*b)}
{ArcTanh[Coth[a + b*x]]/x^1, x, 2, b*x - (b*x - ArcTanh[Coth[a + b*x]])*Log[x]}
{ArcTanh[Coth[a + b*x]]/x^2, x, 2, -(ArcTanh[Coth[a + b*x]]/x) + b*Log[x]}
{ArcTanh[Coth[a + b*x]]/x^3, x, 2, -(b/(2*x)) - ArcTanh[Coth[a + b*x]]/(2*x^2)}


(* ::Section::Closed:: *)
(*Integrands involving inverse hyperbolic tangents of hyperbolic functions*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcTanh[c+d Tanh[a+b x]]*)


{ArcTanh[c + d*Tanh[a + b*x]]*x^2, x, 11, (1/3)*x^3*ArcTanh[c + d*Tanh[a + b*x]] + (1/6)*x^3*Log[1 + ((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d)] - (1/6)*x^3*Log[1 + ((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d)] + (x^2*PolyLog[2, -(((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d))])/(4*b) - (x^2*PolyLog[2, -(((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d))])/(4*b) - (x*PolyLog[3, -(((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d))])/(4*b^2) + (x*PolyLog[3, -(((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d))])/(4*b^2) + PolyLog[4, -(((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d))]/(8*b^3) - PolyLog[4, -(((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d))]/(8*b^3)}
{ArcTanh[c + d*Tanh[a + b*x]]*x^1, x, 9, (1/2)*x^2*ArcTanh[c + d*Tanh[a + b*x]] + (1/4)*x^2*Log[1 + ((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d)] - (1/4)*x^2*Log[1 + ((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d)] + (x*PolyLog[2, -(((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d))])/(4*b) - (x*PolyLog[2, -(((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d))])/(4*b) - PolyLog[3, -(((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d))]/(8*b^2) + PolyLog[3, -(((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d))]/(8*b^2)}
{ArcTanh[c + d*Tanh[a + b*x]]*x^0, x, 7, x*ArcTanh[c + d*Tanh[a + b*x]] + (1/2)*x*Log[1 + ((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d)] - (1/2)*x*Log[1 + ((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d)] + PolyLog[2, -(((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d))]/(4*b) - PolyLog[2, -(((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d))]/(4*b)}
{ArcTanh[c + d*Tanh[a + b*x]]/x^1, x, 0, Int[ArcTanh[c + d*Tanh[a + b*x]]/x, x]}
(* {ArcTanh[c + d*Tanh[a + b*x]]/x^2, x, 0, 0} *)


{ArcTanh[1 + d + d*Tanh[a + b*x]]*x^3, x, 7, (b*x^5)/20 + (1/4)*x^4*ArcTanh[1 + d + d*Tanh[a + b*x]] - (1/8)*x^4*Log[1 + (1 + d)*E^(2*a + 2*b*x)] - (x^3*PolyLog[2, -((1 + d)*E^(2*a + 2*b*x))])/(4*b) + (3*x^2*PolyLog[3, -((1 + d)*E^(2*a + 2*b*x))])/(8*b^2) - (3*x*PolyLog[4, -((1 + d)*E^(2*a + 2*b*x))])/(8*b^3) + (3*PolyLog[5, -((1 + d)*E^(2*a + 2*b*x))])/(16*b^4)}
{ArcTanh[1 + d + d*Tanh[a + b*x]]*x^2, x, 6, (b*x^4)/12 + (1/3)*x^3*ArcTanh[1 + d + d*Tanh[a + b*x]] - (1/6)*x^3*Log[1 + (1 + d)*E^(2*a + 2*b*x)] - (x^2*PolyLog[2, -((1 + d)*E^(2*a + 2*b*x))])/(4*b) + (x*PolyLog[3, -((1 + d)*E^(2*a + 2*b*x))])/(4*b^2) - PolyLog[4, -((1 + d)*E^(2*a + 2*b*x))]/(8*b^3)}
{ArcTanh[1 + d + d*Tanh[a + b*x]]*x^1, x, 5, (b*x^3)/6 + (1/2)*x^2*ArcTanh[1 + d + d*Tanh[a + b*x]] - (1/4)*x^2*Log[1 + (1 + d)*E^(2*a + 2*b*x)] - (x*PolyLog[2, -((1 + d)*E^(2*a + 2*b*x))])/(4*b) + PolyLog[3, -((1 + d)*E^(2*a + 2*b*x))]/(8*b^2)}
{ArcTanh[1 + d + d*Tanh[a + b*x]]*x^0, x, 4, (b*x^2)/2 + x*ArcTanh[1 + d + d*Tanh[a + b*x]] - (1/2)*x*Log[1 + (1 + d)*E^(2*a + 2*b*x)] - PolyLog[2, -((1 + d)*E^(2*a + 2*b*x))]/(4*b)}
{ArcTanh[1 + d + d*Tanh[a + b*x]]/x^1, x, 0, Int[ArcTanh[1 + d + d*Tanh[a + b*x]]/x, x]}


{ArcTanh[1 - d - d*Tanh[a + b*x]]*x^3, x, 7, (b*x^5)/20 + (1/4)*x^4*ArcTanh[1 - d - d*Tanh[a + b*x]] - (1/8)*x^4*Log[1 + (1 - d)*E^(2*a + 2*b*x)] - (x^3*PolyLog[2, -((1 - d)*E^(2*a + 2*b*x))])/(4*b) + (3*x^2*PolyLog[3, -((1 - d)*E^(2*a + 2*b*x))])/(8*b^2) - (3*x*PolyLog[4, -((1 - d)*E^(2*a + 2*b*x))])/(8*b^3) + (3*PolyLog[5, -((1 - d)*E^(2*a + 2*b*x))])/(16*b^4)}
{ArcTanh[1 - d - d*Tanh[a + b*x]]*x^2, x, 6, (b*x^4)/12 + (1/3)*x^3*ArcTanh[1 - d - d*Tanh[a + b*x]] - (1/6)*x^3*Log[1 + (1 - d)*E^(2*a + 2*b*x)] - (x^2*PolyLog[2, -((1 - d)*E^(2*a + 2*b*x))])/(4*b) + (x*PolyLog[3, -((1 - d)*E^(2*a + 2*b*x))])/(4*b^2) - PolyLog[4, -((1 - d)*E^(2*a + 2*b*x))]/(8*b^3)}
{ArcTanh[1 - d - d*Tanh[a + b*x]]*x^1, x, 5, (b*x^3)/6 + (1/2)*x^2*ArcTanh[1 - d - d*Tanh[a + b*x]] - (1/4)*x^2*Log[1 + (1 - d)*E^(2*a + 2*b*x)] - (x*PolyLog[2, -((1 - d)*E^(2*a + 2*b*x))])/(4*b) + PolyLog[3, -((1 - d)*E^(2*a + 2*b*x))]/(8*b^2)}
{ArcTanh[1 - d - d*Tanh[a + b*x]]*x^0, x, 4, (b*x^2)/2 + x*ArcTanh[1 - d - d*Tanh[a + b*x]] - (1/2)*x*Log[1 + (1 - d)*E^(2*a + 2*b*x)] - PolyLog[2, -((1 - d)*E^(2*a + 2*b*x))]/(4*b)}
{ArcTanh[1 - d - d*Tanh[a + b*x]]/x^1, x, 0, Int[ArcTanh[1 - d - d*Tanh[a + b*x]]/x, x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcTanh[c+d Coth[a+b x]]*)


{ArcTanh[c + d*Coth[a + b*x]]*x^2, x, 11, (1/3)*x^3*ArcTanh[c + d*Coth[a + b*x]] + (1/6)*x^3*Log[1 - ((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d)] - (1/6)*x^3*Log[1 - ((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d)] + (x^2*PolyLog[2, ((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d)])/(4*b) - (x^2*PolyLog[2, ((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d)])/(4*b) - (x*PolyLog[3, ((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d)])/(4*b^2) + (x*PolyLog[3, ((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d)])/(4*b^2) + PolyLog[4, ((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d)]/(8*b^3) - PolyLog[4, ((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d)]/(8*b^3)}
{ArcTanh[c + d*Coth[a + b*x]]*x^1, x, 9, (1/2)*x^2*ArcTanh[c + d*Coth[a + b*x]] + (1/4)*x^2*Log[1 - ((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d)] - (1/4)*x^2*Log[1 - ((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d)] + (x*PolyLog[2, ((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d)])/(4*b) - (x*PolyLog[2, ((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d)])/(4*b) - PolyLog[3, ((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d)]/(8*b^2) + PolyLog[3, ((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d)]/(8*b^2)}
{ArcTanh[c + d*Coth[a + b*x]]*x^0, x, 7, x*ArcTanh[c + d*Coth[a + b*x]] + (1/2)*x*Log[1 - ((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d)] - (1/2)*x*Log[1 - ((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d)] + PolyLog[2, ((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d)]/(4*b) - PolyLog[2, ((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d)]/(4*b)}
{ArcTanh[c + d*Coth[a + b*x]]/x^1, x, 0, Int[ArcTanh[c + d*Coth[a + b*x]]/x, x]}
(* {ArcTanh[c + d*Coth[a + b*x]]/x^2, x, 0, 0} *)


{ArcTanh[1 + d + d*Coth[a + b*x]]*x^3, x, 7, (b*x^5)/20 + (1/4)*x^4*ArcTanh[1 + d + d*Coth[a + b*x]] - (1/8)*x^4*Log[1 - (1 + d)*E^(2*a + 2*b*x)] - (x^3*PolyLog[2, (1 + d)*E^(2*a + 2*b*x)])/(4*b) + (3*x^2*PolyLog[3, (1 + d)*E^(2*a + 2*b*x)])/(8*b^2) - (3*x*PolyLog[4, (1 + d)*E^(2*a + 2*b*x)])/(8*b^3) + (3*PolyLog[5, (1 + d)*E^(2*a + 2*b*x)])/(16*b^4)}
{ArcTanh[1 + d + d*Coth[a + b*x]]*x^2, x, 6, (b*x^4)/12 + (1/3)*x^3*ArcTanh[1 + d + d*Coth[a + b*x]] - (1/6)*x^3*Log[1 - (1 + d)*E^(2*a + 2*b*x)] - (x^2*PolyLog[2, (1 + d)*E^(2*a + 2*b*x)])/(4*b) + (x*PolyLog[3, (1 + d)*E^(2*a + 2*b*x)])/(4*b^2) - PolyLog[4, (1 + d)*E^(2*a + 2*b*x)]/(8*b^3)}
{ArcTanh[1 + d + d*Coth[a + b*x]]*x^1, x, 5, (b*x^3)/6 + (1/2)*x^2*ArcTanh[1 + d + d*Coth[a + b*x]] - (1/4)*x^2*Log[1 - (1 + d)*E^(2*a + 2*b*x)] - (x*PolyLog[2, (1 + d)*E^(2*a + 2*b*x)])/(4*b) + PolyLog[3, (1 + d)*E^(2*a + 2*b*x)]/(8*b^2)}
{ArcTanh[1 + d + d*Coth[a + b*x]]*x^0, x, 4, (b*x^2)/2 + x*ArcTanh[1 + d + d*Coth[a + b*x]] - (1/2)*x*Log[1 - (1 + d)*E^(2*a + 2*b*x)] - PolyLog[2, (1 + d)*E^(2*a + 2*b*x)]/(4*b)}
{ArcTanh[1 + d + d*Coth[a + b*x]]/x^1, x, 0, Int[ArcTanh[1 + d + d*Coth[a + b*x]]/x, x]}


{ArcTanh[1 - d - d*Coth[a + b*x]]*x^3, x, 7, (b*x^5)/20 + (1/4)*x^4*ArcTanh[1 - d - d*Coth[a + b*x]] - (1/8)*x^4*Log[1 - (1 - d)*E^(2*a + 2*b*x)] - (x^3*PolyLog[2, (1 - d)*E^(2*a + 2*b*x)])/(4*b) + (3*x^2*PolyLog[3, (1 - d)*E^(2*a + 2*b*x)])/(8*b^2) - (3*x*PolyLog[4, (1 - d)*E^(2*a + 2*b*x)])/(8*b^3) + (3*PolyLog[5, (1 - d)*E^(2*a + 2*b*x)])/(16*b^4)}
{ArcTanh[1 - d - d*Coth[a + b*x]]*x^2, x, 6, (b*x^4)/12 + (1/3)*x^3*ArcTanh[1 - d - d*Coth[a + b*x]] - (1/6)*x^3*Log[1 - (1 - d)*E^(2*a + 2*b*x)] - (x^2*PolyLog[2, (1 - d)*E^(2*a + 2*b*x)])/(4*b) + (x*PolyLog[3, (1 - d)*E^(2*a + 2*b*x)])/(4*b^2) - PolyLog[4, (1 - d)*E^(2*a + 2*b*x)]/(8*b^3)}
{ArcTanh[1 - d - d*Coth[a + b*x]]*x^1, x, 5, (b*x^3)/6 + (1/2)*x^2*ArcTanh[1 - d - d*Coth[a + b*x]] - (1/4)*x^2*Log[1 - (1 - d)*E^(2*a + 2*b*x)] - (x*PolyLog[2, (1 - d)*E^(2*a + 2*b*x)])/(4*b) + PolyLog[3, (1 - d)*E^(2*a + 2*b*x)]/(8*b^2)}
{ArcTanh[1 - d - d*Coth[a + b*x]]*x^0, x, 4, (b*x^2)/2 + x*ArcTanh[1 - d - d*Coth[a + b*x]] - (1/2)*x*Log[1 - (1 - d)*E^(2*a + 2*b*x)] - PolyLog[2, (1 - d)*E^(2*a + 2*b*x)]/(4*b)}
{ArcTanh[1 - d - d*Coth[a + b*x]]/x^1, x, 0, Int[ArcTanh[1 - d - d*Coth[a + b*x]]/x, x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcTanh[c+d Sinh[a+b x]]*)


(* Integrands of the form x^m*ArcTanh[Sinh[x]] where m is an integer *)
(* {ArcTanh[Sinh[x]], x, 6, 0}
{x*ArcTanh[Sinh[x]], x, 8, 0}
{x^2*ArcTanh[Sinh[x]], x, 10, 0} *)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcTanh[c+d Cosh[a+b x]]*)


{ArcTanh[Cosh[x]], x, 4, -2*x*ArcTanh[E^x] + x*ArcTanh[Cosh[x]] - PolyLog[2, -E^x] + PolyLog[2, E^x]}
{x*ArcTanh[Cosh[x]], x, 6, (-x^2)*ArcTanh[E^x] + (1/2)*x^2*ArcTanh[Cosh[x]] - x*PolyLog[2, -E^x] + x*PolyLog[2, E^x] + PolyLog[3, -E^x] - PolyLog[3, E^x]}
{x^2*ArcTanh[Cosh[x]], x, 8, (-(2/3))*x^3*ArcTanh[E^x] + (1/3)*x^3*ArcTanh[Cosh[x]] - x^2*PolyLog[2, -E^x] + x^2*PolyLog[2, E^x] + 2*x*PolyLog[3, -E^x] - 2*x*PolyLog[3, E^x] - 2*PolyLog[4, -E^x] + 2*PolyLog[4, E^x]}


(* ::Section::Closed:: *)
(*Integrands involving inverse hyperbolic tangents of trig functions*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcTanh[c+d Tan[a+b x]]*)


{ArcTanh[Tan[a + b*x]], x, 7, x*ArcTanh[Tan[a + b*x]] - (1/2)*x*Log[1 - I*E^(2*I*a + 2*I*b*x)] + (1/2)*x*Log[1 + I*E^(2*I*a + 2*I*b*x)] - (I*PolyLog[2, (-I)*E^(2*I*a + 2*I*b*x)])/(4*b) + (I*PolyLog[2, I*E^(2*I*a + 2*I*b*x)])/(4*b)}
{ArcTanh[1 - I*d + d*Tan[a + b*x]], x, 4, (1/2)*I*b*x^2 + x*ArcTanh[1 - I*d + d*Tan[a + b*x]] - (1/2)*x*Log[1 + (1 - I*d)*E^(2*I*a + 2*I*b*x)] + (I*PolyLog[2, I*(I + d)*E^(2*I*a + 2*I*b*x)])/(4*b)}
{ArcTanh[1 + I*d - d*Tan[a + b*x]], x, 4, (1/2)*I*b*x^2 + x*ArcTanh[1 + I*d - d*Tan[a + b*x]] - (1/2)*x*Log[1 + (1 + I*d)*E^(2*I*a + 2*I*b*x)] + (I*PolyLog[2, -((1 + I*d)*E^(2*I*a + 2*I*b*x))])/(4*b)}
{ArcTanh[c + d*Tan[a + b*x]], x, 7, x*ArcTanh[c + d*Tan[a + b*x]] + (1/2)*x*Log[1 + ((1 - c + I*d)*E^(2*I*a + 2*I*b*x))/(1 - c - I*d)] - (1/2)*x*Log[1 + ((1 + c - I*d)*E^(2*I*a + 2*I*b*x))/(1 + c + I*d)] - (I*PolyLog[2, -(((1 - c + I*d)*E^(2*I*a + 2*I*b*x))/(1 - c - I*d))])/(4*b) + (I*PolyLog[2, -(((1 + c - I*d)*E^(2*I*a + 2*I*b*x))/(1 + c + I*d))])/(4*b)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcTanh[c+d Cot[a+b x]]*)


{ArcTanh[Cot[a + b*x]], x, 7, x*ArcTanh[Cot[a + b*x]] - (1/2)*x*Log[1 - I*E^(2*I*a + 2*I*b*x)] + (1/2)*x*Log[1 + I*E^(2*I*a + 2*I*b*x)] - (I*PolyLog[2, (-I)*E^(2*I*a + 2*I*b*x)])/(4*b) + (I*PolyLog[2, I*E^(2*I*a + 2*I*b*x)])/(4*b)}
{ArcTanh[1 + I*d + d*Cot[a + b*x]], x, 4, (1/2)*I*b*x^2 + x*ArcTanh[1 + I*d + d*Cot[a + b*x]] - (1/2)*x*Log[1 - (1 + I*d)*E^(2*I*a + 2*I*b*x)] + (I*PolyLog[2, (1 + I*d)*E^(2*I*a + 2*I*b*x)])/(4*b)}
{ArcTanh[1 - I*d - d*Cot[a + b*x]], x, 4, (1/2)*I*b*x^2 + x*ArcTanh[1 - I*d - d*Cot[a + b*x]] - (1/2)*x*Log[1 + I*(I + d)*E^(2*I*a + 2*I*b*x)] + (I*PolyLog[2, (1 - I*d)*E^(2*I*a + 2*I*b*x)])/(4*b)}
{ArcTanh[c + d*Cot[a + b*x]], x, 7, x*ArcTanh[c + d*Cot[a + b*x]] + (1/2)*x*Log[1 - ((1 - c - I*d)*E^(2*I*a + 2*I*b*x))/(1 - c + I*d)] - (1/2)*x*Log[1 - ((1 + c + I*d)*E^(2*I*a + 2*I*b*x))/(1 + c - I*d)] - (I*PolyLog[2, ((1 - c - I*d)*E^(2*I*a + 2*I*b*x))/(1 - c + I*d)])/(4*b) + (I*PolyLog[2, ((1 + c + I*d)*E^(2*I*a + 2*I*b*x))/(1 + c - I*d)])/(4*b)}


(* ::Title:: *)
(*Integrands involving exponentials of inverse hyperbolic tangents*)


(* ::Text:: *)
(**)


(* ::Subtitle::Closed:: *)
(*Integration problems of the form u E^(n ArcTanh[a x])*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(n ArcTanh[a x])*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{E^ArcTanh[a*x]*x^m, x, 2, (x^(1 + m)*AppellF1[1 + m, 1/2, -(1/2), 2 + m, a*x, (-a)*x])/(1 + m)}

{E^ArcTanh[a*x]*x^4, x, 7, -((8*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(15*a^5)) - (3*x*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(8*a^4) - (4*x^2*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(15*a^3) - (x^3*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(4*a^2) - (x^4*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(5*a) + (3*ArcSin[a*x])/(8*a^5)}
{E^ArcTanh[a*x]*x^3, x, 6, -((2*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(3*a^4)) - (3*x*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(8*a^3) - (x^2*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(3*a^2) - (x^3*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(4*a) + (3*ArcSin[a*x])/(8*a^4)}
{E^ArcTanh[a*x]*x^2, x, 6, -((Sqrt[1 - a*x]*Sqrt[1 + a*x])/(2*a^3)) - (Sqrt[1 - a*x]*(1 + a*x)^(3/2))/(6*a^3) - (x*Sqrt[1 - a*x]*(1 + a*x)^(3/2))/(3*a^2) + ArcSin[a*x]/(2*a^3)}
{E^ArcTanh[a*x]*x^1, x, 4, -((Sqrt[1 - a*x]*Sqrt[1 + a*x])/(2*a^2)) - (Sqrt[1 - a*x]*(1 + a*x)^(3/2))/(2*a^2) + ArcSin[a*x]/(2*a^2)}
{E^ArcTanh[a*x]*x^0, x, 3, -(Sqrt[1 - a^2*x^2]/a) + ArcSin[a*x]/a, -((Sqrt[1 - a*x]*Sqrt[1 + a*x])/a) + ArcSin[a*x]/a}
{E^ArcTanh[a*x]/x^1, x, 4, ArcSin[a*x] - ArcTanh[Sqrt[1 - a^2*x^2]], ArcSin[a*x] - 2*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]]}
{E^ArcTanh[a*x]/x^2, x, 3, -((Sqrt[1 - a*x]*Sqrt[1 + a*x])/x) - 2*a*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]]}
{E^ArcTanh[a*x]/x^3, x, 5, -((Sqrt[1 - a*x]*Sqrt[1 + a*x])/(2*x^2)) - (a*Sqrt[1 - a*x]*Sqrt[1 + a*x])/x - a^2*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]]}
{E^ArcTanh[a*x]/x^4, x, 6, -((Sqrt[1 - a*x]*Sqrt[1 + a*x])/(3*x^3)) - (a*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(2*x^2) - (2*a^2*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(3*x) - a^3*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]]}
{E^ArcTanh[a*x]/x^5, x, 7, -((Sqrt[1 - a*x]*Sqrt[1 + a*x])/(4*x^4)) - (a*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(3*x^3) - (3*a^2*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(8*x^2) - (2*a^3*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(3*x) - (3/4)*a^4*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]]}


{E^(2*ArcTanh[a*x])*x^m, x, 3, -(x^(1 + m)/(1 + m)) + (2*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, a*x])/(1 + m)}

{E^(2*ArcTanh[a*x])*x^3, x, 3, -((2*x)/a^3) - x^2/a^2 - (2*x^3)/(3*a) - x^4/4 - (2*Log[1 - a*x])/a^4}
{E^(2*ArcTanh[a*x])*x^2, x, 3, -((2*x)/a^2) - x^2/a - x^3/3 - (2*Log[1 - a*x])/a^3}
{E^(2*ArcTanh[a*x])*x^1, x, 3, -((2*x)/a) - x^2/2 - (2*Log[1 - a*x])/a^2}
{E^(2*ArcTanh[a*x])*x^0, x, 3, -x - (2*Log[1 - a*x])/a}
{E^(2*ArcTanh[a*x])/x^1, x, 3, Log[x] - 2*Log[1 - a*x]}
{E^(2*ArcTanh[a*x])/x^2, x, 3, -(1/x) + 2*a*Log[x] - 2*a*Log[1 - a*x]}
{E^(2*ArcTanh[a*x])/x^3, x, 3, -(1/(2*x^2)) - (2*a)/x + 2*a^2*Log[x] - 2*a^2*Log[1 - a*x]}
{E^(2*ArcTanh[a*x])/x^4, x, 3, -(1/(3*x^3)) - a/x^2 - (2*a^2)/x + 2*a^3*Log[x] - 2*a^3*Log[1 - a*x]}


{E^(3*ArcTanh[a*x])*x^m, x, 2, (x^(1 + m)*AppellF1[1 + m, 3/2, -(3/2), 2 + m, a*x, (-a)*x])/(1 + m)}

{E^(3*ArcTanh[a*x])*x^2, x, 6, (11*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(2*a^3) + (11*Sqrt[1 - a*x]*(1 + a*x)^(3/2))/(6*a^3) + (1 + a*x)^(5/2)/(a^3*Sqrt[1 - a*x]) + (Sqrt[1 - a*x]*(1 + a*x)^(5/2))/(3*a^3) - (11*ArcSin[a*x])/(2*a^3)}
{E^(3*ArcTanh[a*x])*x^1, x, 5, (9*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(2*a^2) + (3*Sqrt[1 - a*x]*(1 + a*x)^(3/2))/(2*a^2) + (1 + a*x)^(5/2)/(a^2*Sqrt[1 - a*x]) - (9*ArcSin[a*x])/(2*a^2)}
{E^(3*ArcTanh[a*x])*x^0, x, 4, (3*Sqrt[1 - a*x]*Sqrt[1 + a*x])/a + (2*(1 + a*x)^(3/2))/(a*Sqrt[1 - a*x]) - (3*ArcSin[a*x])/a}
{E^(3*ArcTanh[a*x])/x^1, x, 7, 2*Sqrt[1 - a*x]*Sqrt[1 + a*x] + (2*(1 + a*x)^(3/2))/Sqrt[1 - a*x] - ArcSin[a*x] - 2*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]]}
{E^(3*ArcTanh[a*x])/x^2, x, 4, (6*a*Sqrt[1 + a*x])/Sqrt[1 - a*x] - (1 + a*x)^(3/2)/(x*Sqrt[1 - a*x]) - 6*a*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]]}
{E^(3*ArcTanh[a*x])/x^3, x, 6, (7*a^2*Sqrt[1 + a*x])/Sqrt[1 - a*x] - (2*a*Sqrt[1 + a*x])/(x*Sqrt[1 - a*x]) - (1 + a*x)^(3/2)/(2*x^2*Sqrt[1 - a*x]) - 9*a^2*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]]}
{E^(3*ArcTanh[a*x])/x^4, x, 7, (26*a^3*Sqrt[1 + a*x])/(3*Sqrt[1 - a*x]) - (5*a*Sqrt[1 + a*x])/(6*x^2*Sqrt[1 - a*x]) - (19*a^2*Sqrt[1 + a*x])/(6*x*Sqrt[1 - a*x]) - (1 + a*x)^(3/2)/(3*x^3*Sqrt[1 - a*x]) - 11*a^3*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]]}


{E^(4*ArcTanh[a*x])*x^m, x, 4, x^(1 + m)/(1 + m) + (4*x^(1 + m))/(1 - a*x) - 4*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, a*x]}

{E^(4*ArcTanh[a*x])*x^3, x, 3, (12*x)/a^3 + (4*x^2)/a^2 + (4*x^3)/(3*a) + x^4/4 + 4/(a^4*(1 - a*x)) + (16*Log[1 - a*x])/a^4}
{E^(4*ArcTanh[a*x])*x^2, x, 3, (8*x)/a^2 + (2*x^2)/a + x^3/3 + 4/(a^3*(1 - a*x)) + (12*Log[1 - a*x])/a^3}
{E^(4*ArcTanh[a*x])*x^1, x, 3, (4*x)/a + x^2/2 + 4/(a^2*(1 - a*x)) + (8*Log[1 - a*x])/a^2}
{E^(4*ArcTanh[a*x])*x^0, x, 3, x + 4/(a*(1 - a*x)) + (4*Log[1 - a*x])/a}
{E^(4*ArcTanh[a*x])/x^1, x, 3, 4/(1 - a*x) + Log[x]}
{E^(4*ArcTanh[a*x])/x^2, x, 3, -(1/x) + (4*a)/(1 - a*x) + 4*a*Log[x] - 4*a*Log[1 - a*x]}
{E^(4*ArcTanh[a*x])/x^3, x, 3, -(1/(2*x^2)) - (4*a)/x + (4*a^2)/(1 - a*x) + 8*a^2*Log[x] - 8*a^2*Log[1 - a*x]}
{E^(4*ArcTanh[a*x])/x^4, x, 3, -(1/(3*x^3)) - (2*a)/x^2 - (8*a^2)/x + (4*a^3)/(1 - a*x) + 12*a^3*Log[x] - 12*a^3*Log[1 - a*x]}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{E^(-ArcTanh[a*x])*x^m, x, 2, (x^(1 + m)*AppellF1[1 + m, -(1/2), 1/2, 2 + m, a*x, (-a)*x])/(1 + m)}

{E^(-ArcTanh[a*x])*x^3, x, 6, -((2*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(3*a^4)) + (3*x*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(8*a^3) - (x^2*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(3*a^2) + (x^3*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(4*a) - (3*ArcSin[a*x])/(8*a^4)}
{E^(-ArcTanh[a*x])*x^2, x, 6, (Sqrt[1 - a*x]*Sqrt[1 + a*x])/(2*a^3) + ((1 - a*x)^(3/2)*Sqrt[1 + a*x])/(6*a^3) - (x*(1 - a*x)^(3/2)*Sqrt[1 + a*x])/(3*a^2) + ArcSin[a*x]/(2*a^3)}
{E^(-ArcTanh[a*x])*x^1, x, 4, -((Sqrt[1 - a*x]*Sqrt[1 + a*x])/(2*a^2)) - ((1 - a*x)^(3/2)*Sqrt[1 + a*x])/(2*a^2) - ArcSin[a*x]/(2*a^2)}
{E^(-ArcTanh[a*x])*x^0, x, 3, (Sqrt[1 - a*x]*Sqrt[1 + a*x])/a + ArcSin[a*x]/a}
{E^(-ArcTanh[a*x])/x^1, x, 4, -ArcSin[a*x] - 2*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]]}
{E^(-ArcTanh[a*x])/x^2, x, 3, -((Sqrt[1 - a*x]*Sqrt[1 + a*x])/x) + 2*a*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]]}
{E^(-ArcTanh[a*x])/x^3, x, 5, -((Sqrt[1 - a*x]*Sqrt[1 + a*x])/(2*x^2)) + (a*Sqrt[1 - a*x]*Sqrt[1 + a*x])/x - a^2*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]]}
{E^(-ArcTanh[a*x])/x^4, x, 6, -((Sqrt[1 - a*x]*Sqrt[1 + a*x])/(3*x^3)) + (a*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(2*x^2) - (2*a^2*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(3*x) + a^3*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]]}
{E^(-ArcTanh[a*x])/x^5, x, 7, -((Sqrt[1 - a*x]*Sqrt[1 + a*x])/(4*x^4)) + (a*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(3*x^3) - (3*a^2*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(8*x^2) + (2*a^3*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(3*x) - (3/4)*a^4*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]]}


{E^(-2*ArcTanh[a*x])*x^m, x, 3, -(x^(1 + m)/(1 + m)) + (2*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, (-a)*x])/(1 + m)}

{E^(-2*ArcTanh[a*x])*x^3, x, 3, (2*x)/a^3 - x^2/a^2 + (2*x^3)/(3*a) - x^4/4 - (2*Log[1 + a*x])/a^4}
{E^(-2*ArcTanh[a*x])*x^2, x, 3, -((2*x)/a^2) + x^2/a - x^3/3 + (2*Log[1 + a*x])/a^3}
{E^(-2*ArcTanh[a*x])*x^1, x, 3, (2*x)/a - x^2/2 - (2*Log[1 + a*x])/a^2}
{E^(-2*ArcTanh[a*x])*x^0, x, 3, -x + (2*Log[1 + a*x])/a}
{E^(-2*ArcTanh[a*x])/x^1, x, 3, Log[x] - 2*Log[1 + a*x]}
{E^(-2*ArcTanh[a*x])/x^2, x, 3, -(1/x) - 2*a*Log[x] + 2*a*Log[1 + a*x]}
{E^(-2*ArcTanh[a*x])/x^3, x, 3, -(1/(2*x^2)) + (2*a)/x + 2*a^2*Log[x] - 2*a^2*Log[1 + a*x]}
{E^(-2*ArcTanh[a*x])/x^4, x, 3, -(1/(3*x^3)) + a/x^2 - (2*a^2)/x - 2*a^3*Log[x] + 2*a^3*Log[1 + a*x]}


{E^(-3*ArcTanh[a*x])*x^m, x, 2, (x^(1 + m)*AppellF1[1 + m, -(3/2), 3/2, 2 + m, a*x, (-a)*x])/(1 + m)}

{E^(-3*ArcTanh[a*x])*x^3, x, 7, -((2*x^3*(1 - a*x)^(3/2))/(a*Sqrt[1 + a*x])) + (51*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(8*a^4) + (29*(1 - a*x)^(3/2)*Sqrt[1 + a*x])/(8*a^4) - (11*x*(1 - a*x)^(3/2)*Sqrt[1 + a*x])/(4*a^3) + (9*x^2*(1 - a*x)^(3/2)*Sqrt[1 + a*x])/(4*a^2) + (51*ArcSin[a*x])/(8*a^4)}
{E^(-3*ArcTanh[a*x])*x^2, x, 6, -((1 - a*x)^(5/2)/(a^3*Sqrt[1 + a*x])) - (11*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(2*a^3) - (11*(1 - a*x)^(3/2)*Sqrt[1 + a*x])/(6*a^3) - ((1 - a*x)^(5/2)*Sqrt[1 + a*x])/(3*a^3) - (11*ArcSin[a*x])/(2*a^3)}
{E^(-3*ArcTanh[a*x])*x^1, x, 5, (1 - a*x)^(5/2)/(a^2*Sqrt[1 + a*x]) + (9*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(2*a^2) + (3*(1 - a*x)^(3/2)*Sqrt[1 + a*x])/(2*a^2) + (9*ArcSin[a*x])/(2*a^2)}
{E^(-3*ArcTanh[a*x])*x^0, x, 4, -((2*(1 - a*x)^(3/2))/(a*Sqrt[1 + a*x])) - (3*Sqrt[1 - a*x]*Sqrt[1 + a*x])/a - (3*ArcSin[a*x])/a}
{E^(-3*ArcTanh[a*x])/x^1, x, 7, (2*(1 - a*x)^(3/2))/Sqrt[1 + a*x] + 2*Sqrt[1 - a*x]*Sqrt[1 + a*x] + ArcSin[a*x] - 2*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]]}
{E^(-3*ArcTanh[a*x])/x^2, x, 4, -((6*a*Sqrt[1 - a*x])/Sqrt[1 + a*x]) - (1 - a*x)^(3/2)/(x*Sqrt[1 + a*x]) + 6*a*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]]}
{E^(-3*ArcTanh[a*x])/x^3, x, 6, (7*a^2*Sqrt[1 - a*x])/Sqrt[1 + a*x] + (2*a*Sqrt[1 - a*x])/(x*Sqrt[1 + a*x]) - (1 - a*x)^(3/2)/(2*x^2*Sqrt[1 + a*x]) - 9*a^2*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]]}
{E^(-3*ArcTanh[a*x])/x^4, x, 7, -((26*a^3*Sqrt[1 - a*x])/(3*Sqrt[1 + a*x])) + (5*a*Sqrt[1 - a*x])/(6*x^2*Sqrt[1 + a*x]) - (19*a^2*Sqrt[1 - a*x])/(6*x*Sqrt[1 + a*x]) - (1 - a*x)^(3/2)/(3*x^3*Sqrt[1 + a*x]) + 11*a^3*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]]}
{E^(-3*ArcTanh[a*x])/x^5, x, 8, (10*a^4*Sqrt[1 - a*x])/Sqrt[1 + a*x] + (a*Sqrt[1 - a*x])/(2*x^3*Sqrt[1 + a*x]) - (11*a^2*Sqrt[1 - a*x])/(8*x^2*Sqrt[1 + a*x]) + (29*a^3*Sqrt[1 - a*x])/(8*x*Sqrt[1 + a*x]) - (1 - a*x)^(3/2)/(4*x^4*Sqrt[1 + a*x]) - (51/4)*a^4*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(n/2 ArcTanh[a x])*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{E^(ArcTanh[a*x]/2)*x^m, x, 2, (x^(1 + m)*AppellF1[1 + m, 1/4, -(1/4), 2 + m, a*x, (-a)*x])/(1 + m)}

{E^(ArcTanh[a*x]/2)*x^2, x, 12, -((3*(1 - a*x)^(3/4)*(1 + a*x)^(1/4))/(8*a^3)) - ((1 - a*x)^(3/4)*(1 + a*x)^(5/4))/(12*a^3) - (x*(1 - a*x)^(3/4)*(1 + a*x)^(5/4))/(3*a^2) + (3*ArcTan[1 - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(8*Sqrt[2]*a^3) - (3*ArcTan[1 + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(8*Sqrt[2]*a^3) - (3*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(16*Sqrt[2]*a^3) + (3*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(16*Sqrt[2]*a^3)}
{E^(ArcTanh[a*x]/2)*x^1, x, 11, -(((1 - a*x)^(3/4)*(1 + a*x)^(1/4))/(4*a^2)) - ((1 - a*x)^(3/4)*(1 + a*x)^(5/4))/(2*a^2) + ArcTan[1 - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)]/(4*Sqrt[2]*a^2) - ArcTan[1 + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)]/(4*Sqrt[2]*a^2) - Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)]/(8*Sqrt[2]*a^2) + Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)]/(8*Sqrt[2]*a^2)}
{E^(ArcTanh[a*x]/2)*x^0, x, 10, -(((1 - a*x)^(3/4)*(1 + a*x)^(1/4))/a) + ArcTan[1 - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)]/(Sqrt[2]*a) - ArcTan[1 + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)]/(Sqrt[2]*a) - Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)]/(2*Sqrt[2]*a) + Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)]/(2*Sqrt[2]*a)}
{E^(ArcTanh[a*x]/2)/x^1, x, 13, -2*ArcTan[(1 + a*x)^(1/4)/(1 - a*x)^(1/4)] - Sqrt[2]*ArcTan[1 - (Sqrt[2]*(1 + a*x)^(1/4))/(1 - a*x)^(1/4)] + Sqrt[2]*ArcTan[1 + (Sqrt[2]*(1 + a*x)^(1/4))/(1 - a*x)^(1/4)] - 2*ArcTanh[(1 + a*x)^(1/4)/(1 - a*x)^(1/4)] - Log[1 - (Sqrt[2]*(1 + a*x)^(1/4))/(1 - a*x)^(1/4) + Sqrt[1 + a*x]/Sqrt[1 - a*x]]/Sqrt[2] + Log[1 + (Sqrt[2]*(1 + a*x)^(1/4))/(1 - a*x)^(1/4) + Sqrt[1 + a*x]/Sqrt[1 - a*x]]/Sqrt[2]}
{E^(ArcTanh[a*x]/2)/x^2, x, 6, -(((1 - a*x)^(3/4)*(1 + a*x)^(1/4))/x) + a*ArcTan[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)] - a*ArcTanh[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)]}
{E^(ArcTanh[a*x]/2)/x^3, x, 8, -(((1 - a*x)^(3/4)*(1 + a*x)^(1/4))/(2*x^2)) - (3*a*(1 - a*x)^(3/4)*(1 + a*x)^(1/4))/(4*x) + (1/4)*a^2*ArcTan[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)] - (1/4)*a^2*ArcTanh[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)]}
{E^(ArcTanh[a*x]/2)/x^4, x, 9, -(((1 - a*x)^(3/4)*(1 + a*x)^(1/4))/(3*x^3)) - (5*a*(1 - a*x)^(3/4)*(1 + a*x)^(1/4))/(12*x^2) - (11*a^2*(1 - a*x)^(3/4)*(1 + a*x)^(1/4))/(24*x) + (3/8)*a^3*ArcTan[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)] - (3/8)*a^3*ArcTanh[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)]}
{E^(ArcTanh[a*x]/2)/x^5, x, 10, -(((1 - a*x)^(3/4)*(1 + a*x)^(1/4))/(4*x^4)) - (7*a*(1 - a*x)^(3/4)*(1 + a*x)^(1/4))/(24*x^3) - (29*a^2*(1 - a*x)^(3/4)*(1 + a*x)^(1/4))/(96*x^2) - (83*a^3*(1 - a*x)^(3/4)*(1 + a*x)^(1/4))/(192*x) + (11/64)*a^4*ArcTan[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)] - (11/64)*a^4*ArcTanh[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)]}
{E^(ArcTanh[a*x]/2)/x^6, x, 11, -(((1 - a*x)^(3/4)*(1 + a*x)^(1/4))/(5*x^5)) - (9*a*(1 - a*x)^(3/4)*(1 + a*x)^(1/4))/(40*x^4) - (11*a^2*(1 - a*x)^(3/4)*(1 + a*x)^(1/4))/(48*x^3) - (269*a^3*(1 - a*x)^(3/4)*(1 + a*x)^(1/4))/(960*x^2) - (611*a^4*(1 - a*x)^(3/4)*(1 + a*x)^(1/4))/(1920*x) + (31/128)*a^5*ArcTan[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)] - (31/128)*a^5*ArcTanh[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)]}


{E^(3*ArcTanh[a*x]/2)*x^m, x, 2, (x^(1 + m)*AppellF1[1 + m, 3/4, -(3/4), 2 + m, a*x, (-a)*x])/(1 + m)}

{E^((3*ArcTanh[a*x])/2)*x^3, x, 13, (-63*(1 - a*x)^(1/4)*(1 + a*x)^(3/4))/(64*a^4) - (15*x*(1 - a*x)^(1/4)*(1 + a*x)^(3/4))/(32*a^3) - (3*x^2*(1 - a*x)^(1/4)*(1 + a*x)^(3/4))/(8*a^2) - (x^3*(1 - a*x)^(1/4)*(1 + a*x)^(3/4))/(4*a) + (123*ArcTan[1 - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(64*Sqrt[2]*a^4) - (123*ArcTan[1 + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(64*Sqrt[2]*a^4) + (123*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(128*Sqrt[2]*a^4) - (123*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(128*Sqrt[2]*a^4)}
{E^((3*ArcTanh[a*x])/2)*x^2, x, 12, (-17*(1 - a*x)^(1/4)*(1 + a*x)^(3/4))/(24*a^3) - ((1 - a*x)^(1/4)*(1 + a*x)^(7/4))/(4*a^3) - (x*(1 - a*x)^(1/4)*(1 + a*x)^(7/4))/(3*a^2) + (17*ArcTan[1 - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(8*Sqrt[2]*a^3) - (17*ArcTan[1 + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(8*Sqrt[2]*a^3) + (17*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(16*Sqrt[2]*a^3) - (17*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(16*Sqrt[2]*a^3)}
{E^((3*ArcTanh[a*x])/2)*x^1, x, 11, (-3*(1 - a*x)^(1/4)*(1 + a*x)^(3/4))/(4*a^2) - ((1 - a*x)^(1/4)*(1 + a*x)^(7/4))/(2*a^2) + (9*ArcTan[1 - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(4*Sqrt[2]*a^2) - (9*ArcTan[1 + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(4*Sqrt[2]*a^2) + (9*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(8*Sqrt[2]*a^2) - (9*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(8*Sqrt[2]*a^2)}
{E^((3*ArcTanh[a*x])/2)*x^0, x, 10, -(((1 - a*x)^(1/4)*(1 + a*x)^(3/4))/a) + (3*ArcTan[1 - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(Sqrt[2]*a) - (3*ArcTan[1 + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(Sqrt[2]*a) + (3*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(2*Sqrt[2]*a) - (3*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(2*Sqrt[2]*a)}
{E^((3*ArcTanh[a*x])/2)/x^1, x, 13, 2*ArcTan[(1 + a*x)^(1/4)/(1 - a*x)^(1/4)] - Sqrt[2]*ArcTan[1 - (Sqrt[2]*(1 + a*x)^(1/4))/(1 - a*x)^(1/4)] + Sqrt[2]*ArcTan[1 + (Sqrt[2]*(1 + a*x)^(1/4))/(1 - a*x)^(1/4)] - 2*ArcTanh[(1 + a*x)^(1/4)/(1 - a*x)^(1/4)] + Log[1 - (Sqrt[2]*(1 + a*x)^(1/4))/(1 - a*x)^(1/4) + Sqrt[1 + a*x]/Sqrt[1 - a*x]]/Sqrt[2] - Log[1 + (Sqrt[2]*(1 + a*x)^(1/4))/(1 - a*x)^(1/4) + Sqrt[1 + a*x]/Sqrt[1 - a*x]]/Sqrt[2]}
{E^((3*ArcTanh[a*x])/2)/x^2, x, 6, -(((1 - a*x)^(1/4)*(1 + a*x)^(3/4))/x) - 3*a*ArcTan[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)] - 3*a*ArcTanh[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)]}
{E^((3*ArcTanh[a*x])/2)/x^3, x, 8, -((1 - a*x)^(1/4)*(1 + a*x)^(3/4))/(2*x^2) - (5*a*(1 - a*x)^(1/4)*(1 + a*x)^(3/4))/(4*x) - (9*a^2*ArcTan[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)])/4 - (9*a^2*ArcTanh[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)])/4}
{E^((3*ArcTanh[a*x])/2)/x^4, x, 9, -((1 - a*x)^(1/4)*(1 + a*x)^(3/4))/(3*x^3) - (7*a*(1 - a*x)^(1/4)*(1 + a*x)^(3/4))/(12*x^2) - (23*a^2*(1 - a*x)^(1/4)*(1 + a*x)^(3/4))/(24*x) - (17*a^3*ArcTan[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)])/8 - (17*a^3*ArcTanh[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)])/8}
{E^((3*ArcTanh[a*x])/2)/x^5, x, 10, -((1 - a*x)^(1/4)*(1 + a*x)^(3/4))/(4*x^4) - (3*a*(1 - a*x)^(1/4)*(1 + a*x)^(3/4))/(8*x^3) - (15*a^2*(1 - a*x)^(1/4)*(1 + a*x)^(3/4))/(32*x^2) - (63*a^3*(1 - a*x)^(1/4)*(1 + a*x)^(3/4))/(64*x) - (123*a^4*ArcTan[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)])/64 - (123*a^4*ArcTanh[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)])/64}


{E^(5*ArcTanh[a*x]/2)*x^m, x, 2, (x^(1 + m)*AppellF1[1 + m, 5/4, -(5/4), 2 + m, a*x, (-a)*x])/(1 + m)}

{E^((5*ArcTanh[a*x])/2)*x^3, x, 14, (475*(1 - a*x)^(3/4)*(1 + a*x)^(1/4))/(64*a^4) + (4*x^3*(1 + a*x)^(5/4))/(a*(1 - a*x)^(1/4)) + (521*(1 - a*x)^(3/4)*(1 + a*x)^(5/4))/(96*a^4) + (113*x*(1 - a*x)^(3/4)*(1 + a*x)^(5/4))/(24*a^3) + (17*x^2*(1 - a*x)^(3/4)*(1 + a*x)^(5/4))/(4*a^2) - (475*ArcTan[1 - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(64*Sqrt[2]*a^4) + (475*ArcTan[1 + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(64*Sqrt[2]*a^4) + (475*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(128*Sqrt[2]*a^4) - (475*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(128*Sqrt[2]*a^4)}
{E^((5*ArcTanh[a*x])/2)*x^2, x, 13, (55*(1 - a*x)^(3/4)*(1 + a*x)^(1/4))/(8*a^3) + (11*(1 - a*x)^(3/4)*(1 + a*x)^(5/4))/(4*a^3) + (2*(1 + a*x)^(9/4))/(a^3*(1 - a*x)^(1/4)) + ((1 - a*x)^(3/4)*(1 + a*x)^(9/4))/(3*a^3) - (55*ArcTan[1 - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(8*Sqrt[2]*a^3) + (55*ArcTan[1 + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(8*Sqrt[2]*a^3) + (55*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(16*Sqrt[2]*a^3) - (55*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(16*Sqrt[2]*a^3)}
{E^((5*ArcTanh[a*x])/2)*x^1, x, 12, (25*(1 - a*x)^(3/4)*(1 + a*x)^(1/4))/(4*a^2) + (5*(1 - a*x)^(3/4)*(1 + a*x)^(5/4))/(2*a^2) + (2*(1 + a*x)^(9/4))/(a^2*(1 - a*x)^(1/4)) - (25*ArcTan[1 - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(4*Sqrt[2]*a^2) + (25*ArcTan[1 + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(4*Sqrt[2]*a^2) + (25*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(8*Sqrt[2]*a^2) - (25*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(8*Sqrt[2]*a^2)}
{E^((5*ArcTanh[a*x])/2)*x^0, x, 11, (5*(1 - a*x)^(3/4)*(1 + a*x)^(1/4))/a + (4*(1 + a*x)^(5/4))/(a*(1 - a*x)^(1/4)) - (5*ArcTan[1 - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(Sqrt[2]*a) + (5*ArcTan[1 + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(Sqrt[2]*a) + (5*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(2*Sqrt[2]*a) - (5*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(2*Sqrt[2]*a)}
{E^((5*ArcTanh[a*x])/2)/x^1, x, 16, 4*(1 - a*x)^(3/4)*(1 + a*x)^(1/4) + (4*(1 + a*x)^(5/4))/(1 - a*x)^(1/4) + 2*ArcTan[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)] - Sqrt[2]*ArcTan[1 - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)] + Sqrt[2]*ArcTan[1 + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)] - 2*ArcTanh[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)] + Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)]/Sqrt[2] - Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)]/Sqrt[2]}
{E^((5*ArcTanh[a*x])/2)/x^2, x, 7, (10*a*(1 + a*x)^(1/4))/(1 - a*x)^(1/4) - (1 + a*x)^(5/4)/(x*(1 - a*x)^(1/4)) + 5*a*ArcTan[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)] - 5*a*ArcTanh[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)]}
{E^((5*ArcTanh[a*x])/2)/x^3, x, 9, (43*a^2*(1 + a*x)^(1/4))/(4*(1 - a*x)^(1/4)) - (7*a*(1 + a*x)^(1/4))/(4*x*(1 - a*x)^(1/4)) - (1 + a*x)^(5/4)/(2*x^2*(1 - a*x)^(1/4)) + (25*a^2*ArcTan[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)])/4 - (25*a^2*ArcTanh[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)])/4}
{E^((5*ArcTanh[a*x])/2)/x^4, x, 10, (287*a^3*(1 + a*x)^(1/4))/(24*(1 - a*x)^(1/4)) - (3*a*(1 + a*x)^(1/4))/(4*x^2*(1 - a*x)^(1/4)) - (61*a^2*(1 + a*x)^(1/4))/(24*x*(1 - a*x)^(1/4)) - (1 + a*x)^(5/4)/(3*x^3*(1 - a*x)^(1/4)) + (55*a^3*ArcTan[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)])/8 - (55*a^3*ArcTanh[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)])/8}
{E^((5*ArcTanh[a*x])/2)/x^5, x, 11, (2467*a^4*(1 + a*x)^(1/4))/(192*(1 - a*x)^(1/4)) - (11*a*(1 + a*x)^(1/4))/(24*x^3*(1 - a*x)^(1/4)) - (113*a^2*(1 + a*x)^(1/4))/(96*x^2*(1 - a*x)^(1/4)) - (521*a^3*(1 + a*x)^(1/4))/(192*x*(1 - a*x)^(1/4)) - (1 + a*x)^(5/4)/(4*x^4*(1 - a*x)^(1/4)) + (475*a^4*ArcTan[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)])/64 - (475*a^4*ArcTanh[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)])/64}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{x^m/E^(ArcTanh[a*x]/2), x, 2, (x^(1 + m)*AppellF1[1 + m, -(1/4), 1/4, 2 + m, a*x, (-a)*x])/(1 + m)}

{x^3/E^(ArcTanh[a*x]/2), x, 13, (-83*(1 - a*x)^(1/4)*(1 + a*x)^(3/4))/(192*a^4) + (29*x*(1 - a*x)^(1/4)*(1 + a*x)^(3/4))/(96*a^3) - (7*x^2*(1 - a*x)^(1/4)*(1 + a*x)^(3/4))/(24*a^2) + (x^3*(1 - a*x)^(1/4)*(1 + a*x)^(3/4))/(4*a) - (11*ArcTan[1 - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(64*Sqrt[2]*a^4) + (11*ArcTan[1 + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(64*Sqrt[2]*a^4) - (11*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(128*Sqrt[2]*a^4) + (11*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(128*Sqrt[2]*a^4)}
{x^2/E^(ArcTanh[a*x]/2), x, 12, (3*(1 - a*x)^(1/4)*(1 + a*x)^(3/4))/(8*a^3) + ((1 - a*x)^(5/4)*(1 + a*x)^(3/4))/(12*a^3) - (x*(1 - a*x)^(5/4)*(1 + a*x)^(3/4))/(3*a^2) + (3*ArcTan[1 - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(8*Sqrt[2]*a^3) - (3*ArcTan[1 + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(8*Sqrt[2]*a^3) + (3*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(16*Sqrt[2]*a^3) - (3*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(16*Sqrt[2]*a^3)}
{x/E^(ArcTanh[a*x]/2), x, 11, -((1 - a*x)^(1/4)*(1 + a*x)^(3/4))/(4*a^2) - ((1 - a*x)^(5/4)*(1 + a*x)^(3/4))/(2*a^2) - ArcTan[1 - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)]/(4*Sqrt[2]*a^2) + ArcTan[1 + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)]/(4*Sqrt[2]*a^2) - Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)]/(8*Sqrt[2]*a^2) + Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)]/(8*Sqrt[2]*a^2)}
{E^(-ArcTanh[a*x]/2), x, 10, ((1 - a*x)^(1/4)*(1 + a*x)^(3/4))/a + ArcTan[1 - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)]/(Sqrt[2]*a) - ArcTan[1 + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)]/(Sqrt[2]*a) + Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)]/(2*Sqrt[2]*a) - Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)]/(2*Sqrt[2]*a)}
{1/(E^(ArcTanh[a*x]/2)*x), x, 13, -2*ArcTan[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)] - Sqrt[2]*ArcTan[1 - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)] + Sqrt[2]*ArcTan[1 + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)] - 2*ArcTanh[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)] - Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)]/Sqrt[2] + Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)]/Sqrt[2]}
{1/(E^(ArcTanh[a*x]/2)*x^2), x, 6, -(((1 - a*x)^(1/4)*(1 + a*x)^(3/4))/x) + a*ArcTan[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)] + a*ArcTanh[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)]}
{1/(E^(ArcTanh[a*x]/2)*x^3), x, 8, -((1 - a*x)^(1/4)*(1 + a*x)^(3/4))/(2*x^2) + (3*a*(1 - a*x)^(1/4)*(1 + a*x)^(3/4))/(4*x) - (a^2*ArcTan[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)])/4 - (a^2*ArcTanh[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)])/4}
{1/(E^(ArcTanh[a*x]/2)*x^4), x, 9, -((1 - a*x)^(1/4)*(1 + a*x)^(3/4))/(3*x^3) + (5*a*(1 - a*x)^(1/4)*(1 + a*x)^(3/4))/(12*x^2) - (11*a^2*(1 - a*x)^(1/4)*(1 + a*x)^(3/4))/(24*x) + (3*a^3*ArcTan[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)])/8 + (3*a^3*ArcTanh[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)])/8}
{1/(E^(ArcTanh[a*x]/2)*x^5), x, 10, -((1 - a*x)^(1/4)*(1 + a*x)^(3/4))/(4*x^4) + (7*a*(1 - a*x)^(1/4)*(1 + a*x)^(3/4))/(24*x^3) - (29*a^2*(1 - a*x)^(1/4)*(1 + a*x)^(3/4))/(96*x^2) + (83*a^3*(1 - a*x)^(1/4)*(1 + a*x)^(3/4))/(192*x) - (11*a^4*ArcTan[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)])/64 - (11*a^4*ArcTanh[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)])/64}


{x^m/E^((3*ArcTanh[a*x])/2), x, 2, (x^(1 + m)*AppellF1[1 + m, -(3/4), 3/4, 2 + m, a*x, (-a)*x])/(1 + m)}

{x^3/E^((3*ArcTanh[a*x])/2), x, 13, (-63*(1 - a*x)^(3/4)*(1 + a*x)^(1/4))/(64*a^4) + (15*x*(1 - a*x)^(3/4)*(1 + a*x)^(1/4))/(32*a^3) - (3*x^2*(1 - a*x)^(3/4)*(1 + a*x)^(1/4))/(8*a^2) + (x^3*(1 - a*x)^(3/4)*(1 + a*x)^(1/4))/(4*a) - (123*ArcTan[1 - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(64*Sqrt[2]*a^4) + (123*ArcTan[1 + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(64*Sqrt[2]*a^4) + (123*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(128*Sqrt[2]*a^4) - (123*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(128*Sqrt[2]*a^4)}
{x^2/E^((3*ArcTanh[a*x])/2), x, 12, (17*(1 - a*x)^(3/4)*(1 + a*x)^(1/4))/(24*a^3) + ((1 - a*x)^(7/4)*(1 + a*x)^(1/4))/(4*a^3) - (x*(1 - a*x)^(7/4)*(1 + a*x)^(1/4))/(3*a^2) + (17*ArcTan[1 - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(8*Sqrt[2]*a^3) - (17*ArcTan[1 + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(8*Sqrt[2]*a^3) - (17*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(16*Sqrt[2]*a^3) + (17*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(16*Sqrt[2]*a^3)}
{x/E^((3*ArcTanh[a*x])/2), x, 11, (-3*(1 - a*x)^(3/4)*(1 + a*x)^(1/4))/(4*a^2) - ((1 - a*x)^(7/4)*(1 + a*x)^(1/4))/(2*a^2) - (9*ArcTan[1 - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(4*Sqrt[2]*a^2) + (9*ArcTan[1 + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(4*Sqrt[2]*a^2) + (9*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(8*Sqrt[2]*a^2) - (9*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(8*Sqrt[2]*a^2)}
{E^((-3*ArcTanh[a*x])/2), x, 10, ((1 - a*x)^(3/4)*(1 + a*x)^(1/4))/a + (3*ArcTan[1 - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(Sqrt[2]*a) - (3*ArcTan[1 + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(Sqrt[2]*a) - (3*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(2*Sqrt[2]*a) + (3*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(2*Sqrt[2]*a)}
{1/(E^((3*ArcTanh[a*x])/2)*x), x, 13, 2*ArcTan[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)] - Sqrt[2]*ArcTan[1 - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)] + Sqrt[2]*ArcTan[1 + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)] - 2*ArcTanh[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)] + Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)]/Sqrt[2] - Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)]/Sqrt[2]}
{1/(E^((3*ArcTanh[a*x])/2)*x^2), x, 6, -(((1 - a*x)^(3/4)*(1 + a*x)^(1/4))/x) - 3*a*ArcTan[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)] + 3*a*ArcTanh[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)]}
{1/(E^((3*ArcTanh[a*x])/2)*x^3), x, 8, -((1 - a*x)^(3/4)*(1 + a*x)^(1/4))/(2*x^2) + (5*a*(1 - a*x)^(3/4)*(1 + a*x)^(1/4))/(4*x) + (9*a^2*ArcTan[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)])/4 - (9*a^2*ArcTanh[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)])/4}
{1/(E^((3*ArcTanh[a*x])/2)*x^4), x, 9, -((1 - a*x)^(3/4)*(1 + a*x)^(1/4))/(3*x^3) + (7*a*(1 - a*x)^(3/4)*(1 + a*x)^(1/4))/(12*x^2) - (23*a^2*(1 - a*x)^(3/4)*(1 + a*x)^(1/4))/(24*x) - (17*a^3*ArcTan[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)])/8 + (17*a^3*ArcTanh[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)])/8}
{1/(E^((3*ArcTanh[a*x])/2)*x^5), x, 10, -((1 - a*x)^(3/4)*(1 + a*x)^(1/4))/(4*x^4) + (3*a*(1 - a*x)^(3/4)*(1 + a*x)^(1/4))/(8*x^3) - (15*a^2*(1 - a*x)^(3/4)*(1 + a*x)^(1/4))/(32*x^2) + (63*a^3*(1 - a*x)^(3/4)*(1 + a*x)^(1/4))/(64*x) + (123*a^4*ArcTan[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)])/64 - (123*a^4*ArcTanh[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)])/64}


{x^m/E^((5*ArcTanh[a*x])/2), x, 2, (x^(1 + m)*AppellF1[1 + m, -(5/4), 5/4, 2 + m, a*x, (-a)*x])/(1 + m)}

{x^3/E^((5*ArcTanh[a*x])/2), x, 14, (-4*x^3*(1 - a*x)^(5/4))/(a*(1 + a*x)^(1/4)) + (475*(1 - a*x)^(1/4)*(1 + a*x)^(3/4))/(64*a^4) + (521*(1 - a*x)^(5/4)*(1 + a*x)^(3/4))/(96*a^4) - (113*x*(1 - a*x)^(5/4)*(1 + a*x)^(3/4))/(24*a^3) + (17*x^2*(1 - a*x)^(5/4)*(1 + a*x)^(3/4))/(4*a^2) + (475*ArcTan[1 - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(64*Sqrt[2]*a^4) - (475*ArcTan[1 + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(64*Sqrt[2]*a^4) + (475*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(128*Sqrt[2]*a^4) - (475*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(128*Sqrt[2]*a^4)}
{x^2/E^((5*ArcTanh[a*x])/2), x, 13, (-2*(1 - a*x)^(9/4))/(a^3*(1 + a*x)^(1/4)) - (55*(1 - a*x)^(1/4)*(1 + a*x)^(3/4))/(8*a^3) - (11*(1 - a*x)^(5/4)*(1 + a*x)^(3/4))/(4*a^3) - ((1 - a*x)^(9/4)*(1 + a*x)^(3/4))/(3*a^3) - (55*ArcTan[1 - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(8*Sqrt[2]*a^3) + (55*ArcTan[1 + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(8*Sqrt[2]*a^3) - (55*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(16*Sqrt[2]*a^3) + (55*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(16*Sqrt[2]*a^3)}
{x/E^((5*ArcTanh[a*x])/2), x, 12, (2*(1 - a*x)^(9/4))/(a^2*(1 + a*x)^(1/4)) + (25*(1 - a*x)^(1/4)*(1 + a*x)^(3/4))/(4*a^2) + (5*(1 - a*x)^(5/4)*(1 + a*x)^(3/4))/(2*a^2) + (25*ArcTan[1 - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(4*Sqrt[2]*a^2) - (25*ArcTan[1 + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(4*Sqrt[2]*a^2) + (25*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(8*Sqrt[2]*a^2) - (25*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(8*Sqrt[2]*a^2)}
{E^((-5*ArcTanh[a*x])/2), x, 11, (-4*(1 - a*x)^(5/4))/(a*(1 + a*x)^(1/4)) - (5*(1 - a*x)^(1/4)*(1 + a*x)^(3/4))/a - (5*ArcTan[1 - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(Sqrt[2]*a) + (5*ArcTan[1 + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(Sqrt[2]*a) - (5*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] - (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(2*Sqrt[2]*a) + (5*Log[1 + Sqrt[1 - a*x]/Sqrt[1 + a*x] + (Sqrt[2]*(1 - a*x)^(1/4))/(1 + a*x)^(1/4)])/(2*Sqrt[2]*a)}
{1/(E^((5*ArcTanh[a*x])/2)*x), x, 16, (4*(1 - a*x)^(5/4))/(1 + a*x)^(1/4) + 4*(1 - a*x)^(1/4)*(1 + a*x)^(3/4) + 2*ArcTan[(1 + a*x)^(1/4)/(1 - a*x)^(1/4)] - Sqrt[2]*ArcTan[1 - (Sqrt[2]*(1 + a*x)^(1/4))/(1 - a*x)^(1/4)] + Sqrt[2]*ArcTan[1 + (Sqrt[2]*(1 + a*x)^(1/4))/(1 - a*x)^(1/4)] - 2*ArcTanh[(1 + a*x)^(1/4)/(1 - a*x)^(1/4)] + Log[1 - (Sqrt[2]*(1 + a*x)^(1/4))/(1 - a*x)^(1/4) + Sqrt[1 + a*x]/Sqrt[1 - a*x]]/Sqrt[2] - Log[1 + (Sqrt[2]*(1 + a*x)^(1/4))/(1 - a*x)^(1/4) + Sqrt[1 + a*x]/Sqrt[1 - a*x]]/Sqrt[2]}
{1/(E^((5*ArcTanh[a*x])/2)*x^2), x, 7, (-10*a*(1 - a*x)^(1/4))/(1 + a*x)^(1/4) - (1 - a*x)^(5/4)/(x*(1 + a*x)^(1/4)) + 5*a*ArcTan[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)] + 5*a*ArcTanh[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)]}
{1/(E^((5*ArcTanh[a*x])/2)*x^3), x, 9, (43*a^2*(1 - a*x)^(1/4))/(4*(1 + a*x)^(1/4)) + (7*a*(1 - a*x)^(1/4))/(4*x*(1 + a*x)^(1/4)) - (1 - a*x)^(5/4)/(2*x^2*(1 + a*x)^(1/4)) - (25*a^2*ArcTan[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)])/4 - (25*a^2*ArcTanh[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)])/4}
{1/(E^((5*ArcTanh[a*x])/2)*x^4), x, 10, (-287*a^3*(1 - a*x)^(1/4))/(24*(1 + a*x)^(1/4)) + (3*a*(1 - a*x)^(1/4))/(4*x^2*(1 + a*x)^(1/4)) - (61*a^2*(1 - a*x)^(1/4))/(24*x*(1 + a*x)^(1/4)) - (1 - a*x)^(5/4)/(3*x^3*(1 + a*x)^(1/4)) + (55*a^3*ArcTan[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)])/8 + (55*a^3*ArcTanh[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)])/8}
{1/(E^((5*ArcTanh[a*x])/2)*x^5), x, 11, (2467*a^4*(1 - a*x)^(1/4))/(192*(1 + a*x)^(1/4)) + (11*a*(1 - a*x)^(1/4))/(24*x^3*(1 + a*x)^(1/4)) - (113*a^2*(1 - a*x)^(1/4))/(96*x^2*(1 + a*x)^(1/4)) + (521*a^3*(1 - a*x)^(1/4))/(192*x*(1 + a*x)^(1/4)) - (1 - a*x)^(5/4)/(4*x^4*(1 + a*x)^(1/4)) - (475*a^4*ArcTan[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)])/64 - (475*a^4*ArcTanh[(1 - a*x)^(1/4)/(1 + a*x)^(1/4)])/64}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(n/3 ArcTanh[a x])*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{E^(ArcTanh[x]/3)*x^m, x, 2, (-(6/5))*2^(1/6)*(1 - x)^(5/6)*AppellF1[5/6, -m, -(1/6), 11/6, 1 - x, (1 - x)/2]}

{E^(ArcTanh[x]/3)*x^2, x, 12, (-(19/54))*(1 - x)^(5/6)*(1 + x)^(1/6) - (1/18)*(1 - x)^(5/6)*(1 + x)^(7/6) - (1/3)*(1 - x)^(5/6)*x*(1 + x)^(7/6) - (19/81)*ArcTan[(1 - x)^(1/6)/(1 + x)^(1/6)] + (19/162)*ArcTan[Sqrt[3] - (2*(1 - x)^(1/6))/(1 + x)^(1/6)] - (19/162)*ArcTan[Sqrt[3] + (2*(1 - x)^(1/6))/(1 + x)^(1/6)] + (19*ArcTanh[(Sqrt[3]*(1 - x)^(1/6))/((1 + x)^(1/6)*(1 + (1 - x)^(1/3)/(1 + x)^(1/3)))])/(54*Sqrt[3])}
{E^(ArcTanh[x]/3)*x^1, x, 11, (-(1/6))*(1 - x)^(5/6)*(1 + x)^(1/6) - (1/2)*(1 - x)^(5/6)*(1 + x)^(7/6) - (1/9)*ArcTan[(1 - x)^(1/6)/(1 + x)^(1/6)] + (1/18)*ArcTan[Sqrt[3] - (2*(1 - x)^(1/6))/(1 + x)^(1/6)] - (1/18)*ArcTan[Sqrt[3] + (2*(1 - x)^(1/6))/(1 + x)^(1/6)] + ArcTanh[(Sqrt[3]*(1 - x)^(1/6))/((1 + x)^(1/6)*(1 + (1 - x)^(1/3)/(1 + x)^(1/3)))]/(6*Sqrt[3])}
{E^(ArcTanh[x]/3)*x^0, x, 10, (-(1 - x)^(5/6))*(1 + x)^(1/6) - (2/3)*ArcTan[(1 - x)^(1/6)/(1 + x)^(1/6)] + (1/3)*ArcTan[Sqrt[3] - (2*(1 - x)^(1/6))/(1 + x)^(1/6)] - (1/3)*ArcTan[Sqrt[3] + (2*(1 - x)^(1/6))/(1 + x)^(1/6)] + ArcTanh[(Sqrt[3]*(1 - x)^(1/6))/((1 + x)^(1/6)*(1 + (1 - x)^(1/3)/(1 + x)^(1/3)))]/Sqrt[3]}
{E^(ArcTanh[x]/3)/x^1, x, 17, 2*ArcTan[(1 + x)^(1/6)/(1 - x)^(1/6)] + Sqrt[3]*ArcTan[(1 - (2*(1 + x)^(1/6))/(1 - x)^(1/6))/Sqrt[3]] - ArcTan[Sqrt[3] - (2*(1 + x)^(1/6))/(1 - x)^(1/6)] - Sqrt[3]*ArcTan[(1 + (2*(1 + x)^(1/6))/(1 - x)^(1/6))/Sqrt[3]] + ArcTan[Sqrt[3] + (2*(1 + x)^(1/6))/(1 - x)^(1/6)] - 2*ArcTanh[(1 + x)^(1/6)/(1 - x)^(1/6)] - ArcTanh[(1 + x)^(1/6)/((1 - x)^(1/6)*(1 + (1 + x)^(1/3)/(1 - x)^(1/3)))] + Sqrt[3]*ArcTanh[(Sqrt[3]*(1 + x)^(1/6))/((1 - x)^(1/6)*(1 + (1 + x)^(1/3)/(1 - x)^(1/3)))]}
{E^(ArcTanh[x]/3)/x^2, x, 10, -(((1 - x)^(5/6)*(1 + x)^(1/6))/x) - ArcTan[(1 - (2*(1 - x)^(1/6))/(1 + x)^(1/6))/Sqrt[3]]/Sqrt[3] + ArcTan[(1 + (2*(1 - x)^(1/6))/(1 + x)^(1/6))/Sqrt[3]]/Sqrt[3] - (2/3)*ArcTanh[(1 - x)^(1/6)/(1 + x)^(1/6)] - (1/3)*ArcTanh[(1 - x)^(1/6)/((1 + x)^(1/6)*(1 + (1 - x)^(1/3)/(1 + x)^(1/3)))]}
{E^(ArcTanh[x]/3)/x^3, x, 12, -(((1 - x)^(5/6)*(1 + x)^(1/6))/(2*x^2)) - (2*(1 - x)^(5/6)*(1 + x)^(1/6))/(3*x) - ArcTan[(1 - (2*(1 - x)^(1/6))/(1 + x)^(1/6))/Sqrt[3]]/(6*Sqrt[3]) + ArcTan[(1 + (2*(1 - x)^(1/6))/(1 + x)^(1/6))/Sqrt[3]]/(6*Sqrt[3]) - (1/9)*ArcTanh[(1 - x)^(1/6)/(1 + x)^(1/6)] - (1/18)*ArcTanh[(1 - x)^(1/6)/((1 + x)^(1/6)*(1 + (1 - x)^(1/3)/(1 + x)^(1/3)))]}


{E^(2*ArcTanh[x]/3)*x^m, x, 2, -((3*(1 - x)^(2/3)*AppellF1[2/3, -m, -(1/3), 5/3, 1 - x, (1 - x)/2])/2^(2/3))}

{E^(2*ArcTanh[x]/3)*x^2, x, 10, (-(11/27))*(1 - x)^(2/3)*(1 + x)^(1/3) - (1/9)*(1 - x)^(2/3)*(1 + x)^(4/3) - (1/3)*(1 - x)^(2/3)*x*(1 + x)^(4/3) + (22*ArcTan[(1 - (2*(1 - x)^(1/3))/(1 + x)^(1/3))/Sqrt[3]])/(27*Sqrt[3]) - (11/81)*Log[1 + (1 - x)^(2/3)/(1 + x)^(2/3) - (1 - x)^(1/3)/(1 + x)^(1/3)] + (22/81)*Log[1 + (1 - x)^(1/3)/(1 + x)^(1/3)]}
{E^(2*ArcTanh[x]/3)*x^1, x, 9, (-(1/3))*(1 - x)^(2/3)*(1 + x)^(1/3) - (1/2)*(1 - x)^(2/3)*(1 + x)^(4/3) + (2*ArcTan[(1 - (2*(1 - x)^(1/3))/(1 + x)^(1/3))/Sqrt[3]])/(3*Sqrt[3]) - (1/9)*Log[1 + (1 - x)^(2/3)/(1 + x)^(2/3) - (1 - x)^(1/3)/(1 + x)^(1/3)] + (2/9)*Log[1 + (1 - x)^(1/3)/(1 + x)^(1/3)]}
{E^(2*ArcTanh[x]/3)*x^0, x, 8, (-(1 - x)^(2/3))*(1 + x)^(1/3) + (2*ArcTan[(1 - (2*(1 - x)^(1/3))/(1 + x)^(1/3))/Sqrt[3]])/Sqrt[3] - (1/3)*Log[1 + (1 - x)^(2/3)/(1 + x)^(2/3) - (1 - x)^(1/3)/(1 + x)^(1/3)] + (2/3)*Log[1 + (1 - x)^(1/3)/(1 + x)^(1/3)]}
{E^(2*ArcTanh[x]/3)/x^1, x, 13, (-Sqrt[3])*ArcTan[(1 - (2*(1 + x)^(1/3))/(1 - x)^(1/3))/Sqrt[3]] - Sqrt[3]*ArcTan[(1 + (2*(1 + x)^(1/3))/(1 - x)^(1/3))/Sqrt[3]] + Log[1 - (1 + x)^(1/3)/(1 - x)^(1/3)] + Log[1 + (1 + x)^(1/3)/(1 - x)^(1/3)] - (1/2)*Log[1 - (1 + x)^(1/3)/(1 - x)^(1/3) + (1 + x)^(2/3)/(1 - x)^(2/3)] - (1/2)*Log[1 + (1 + x)^(1/3)/(1 - x)^(1/3) + (1 + x)^(2/3)/(1 - x)^(2/3)]}
{E^(2*ArcTanh[x]/3)/x^2, x, 8, -(((1 - x)^(2/3)*(1 + x)^(1/3))/x) + (2*ArcTan[(1 + (2*(1 - x)^(1/3))/(1 + x)^(1/3))/Sqrt[3]])/Sqrt[3] + (2/3)*Log[1 - (1 - x)^(1/3)/(1 + x)^(1/3)] - (1/3)*Log[1 + (1 - x)^(2/3)/(1 + x)^(2/3) + (1 - x)^(1/3)/(1 + x)^(1/3)]}
{E^(2*ArcTanh[x]/3)/x^3, x, 10, -(((1 - x)^(2/3)*(1 + x)^(1/3))/(2*x^2)) - (5*(1 - x)^(2/3)*(1 + x)^(1/3))/(6*x) + (2*ArcTan[(1 + (2*(1 - x)^(1/3))/(1 + x)^(1/3))/Sqrt[3]])/(3*Sqrt[3]) + (2/9)*Log[1 - (1 - x)^(1/3)/(1 + x)^(1/3)] - (1/9)*Log[1 + (1 - x)^(2/3)/(1 + x)^(2/3) + (1 - x)^(1/3)/(1 + x)^(1/3)]}


(* ::Subsubsection:: *)
(*n<0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(n/4 ArcTanh[a x])*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{E^(ArcTanh[a*x]/4)*x^m, x, 2, (x^(1 + m)*AppellF1[1 + m, 1/8, -(1/8), 2 + m, a*x, (-a)*x])/(1 + m)}

{E^(ArcTanh[a*x]/4)*x^2, x, 18, -((11*(1 - a*x)^(7/8)*(1 + a*x)^(1/8))/(32*a^3)) - ((1 - a*x)^(7/8)*(1 + a*x)^(9/8))/(24*a^3) - (x*(1 - a*x)^(7/8)*(1 + a*x)^(9/8))/(3*a^2) + (11*Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*ArcTan[(Sqrt[2 - Sqrt[2]] - (2*(1 - a*x)^(1/8))/(1 + a*x)^(1/8))/Sqrt[2 + Sqrt[2]]])/(128*a^3) - (11*(1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*ArcTan[(Sqrt[2 + Sqrt[2]] - (2*(1 - a*x)^(1/8))/(1 + a*x)^(1/8))/Sqrt[2 - Sqrt[2]]])/(128*a^3) - (11*Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*ArcTan[(Sqrt[2 - Sqrt[2]] + (2*(1 - a*x)^(1/8))/(1 + a*x)^(1/8))/Sqrt[2 + Sqrt[2]]])/(128*a^3) + (11*(1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*ArcTan[(Sqrt[2 + Sqrt[2]] + (2*(1 - a*x)^(1/8))/(1 + a*x)^(1/8))/Sqrt[2 - Sqrt[2]]])/(128*a^3) - (11*(1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*ArcTanh[(Sqrt[2 - Sqrt[2]]*(1 - a*x)^(1/8))/((1 + a*x)^(1/8)*(1 + (1 - a*x)^(1/4)/(1 + a*x)^(1/4)))])/(128*a^3) + (11*Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*ArcTanh[(Sqrt[2 + Sqrt[2]]*(1 - a*x)^(1/8))/((1 + a*x)^(1/8)*(1 + (1 - a*x)^(1/4)/(1 + a*x)^(1/4)))])/(128*a^3)}
{E^(ArcTanh[a*x]/4)*x^1, x, 17, -(((1 - a*x)^(7/8)*(1 + a*x)^(1/8))/(8*a^2)) - ((1 - a*x)^(7/8)*(1 + a*x)^(9/8))/(2*a^2) + (Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*ArcTan[(Sqrt[2 - Sqrt[2]] - (2*(1 - a*x)^(1/8))/(1 + a*x)^(1/8))/Sqrt[2 + Sqrt[2]]])/(32*a^2) - ((1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*ArcTan[(Sqrt[2 + Sqrt[2]] - (2*(1 - a*x)^(1/8))/(1 + a*x)^(1/8))/Sqrt[2 - Sqrt[2]]])/(32*a^2) - (Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*ArcTan[(Sqrt[2 - Sqrt[2]] + (2*(1 - a*x)^(1/8))/(1 + a*x)^(1/8))/Sqrt[2 + Sqrt[2]]])/(32*a^2) + ((1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*ArcTan[(Sqrt[2 + Sqrt[2]] + (2*(1 - a*x)^(1/8))/(1 + a*x)^(1/8))/Sqrt[2 - Sqrt[2]]])/(32*a^2) - ((1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*ArcTanh[(Sqrt[2 - Sqrt[2]]*(1 - a*x)^(1/8))/((1 + a*x)^(1/8)*(1 + (1 - a*x)^(1/4)/(1 + a*x)^(1/4)))])/(32*a^2) + (Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*ArcTanh[(Sqrt[2 + Sqrt[2]]*(1 - a*x)^(1/8))/((1 + a*x)^(1/8)*(1 + (1 - a*x)^(1/4)/(1 + a*x)^(1/4)))])/(32*a^2)}
{E^(ArcTanh[a*x]/4)*x^0, x, 16, -(((1 - a*x)^(7/8)*(1 + a*x)^(1/8))/a) + (Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*ArcTan[(Sqrt[2 - Sqrt[2]] - (2*(1 - a*x)^(1/8))/(1 + a*x)^(1/8))/Sqrt[2 + Sqrt[2]]])/(4*a) - ((1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*ArcTan[(Sqrt[2 + Sqrt[2]] - (2*(1 - a*x)^(1/8))/(1 + a*x)^(1/8))/Sqrt[2 - Sqrt[2]]])/(4*a) - (Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*ArcTan[(Sqrt[2 - Sqrt[2]] + (2*(1 - a*x)^(1/8))/(1 + a*x)^(1/8))/Sqrt[2 + Sqrt[2]]])/(4*a) + ((1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*ArcTan[(Sqrt[2 + Sqrt[2]] + (2*(1 - a*x)^(1/8))/(1 + a*x)^(1/8))/Sqrt[2 - Sqrt[2]]])/(4*a) - ((1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*ArcTanh[(Sqrt[2 - Sqrt[2]]*(1 - a*x)^(1/8))/((1 + a*x)^(1/8)*(1 + (1 - a*x)^(1/4)/(1 + a*x)^(1/4)))])/(4*a) + (Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*ArcTanh[(Sqrt[2 + Sqrt[2]]*(1 - a*x)^(1/8))/((1 + a*x)^(1/8)*(1 + (1 - a*x)^(1/4)/(1 + a*x)^(1/4)))])/(4*a)}
{E^(ArcTanh[a*x]/4)/x^1, x, 25, -2*ArcTan[(1 + a*x)^(1/8)/(1 - a*x)^(1/8)] - Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*ArcTan[(Sqrt[2 - Sqrt[2]] - (2*(1 + a*x)^(1/8))/(1 - a*x)^(1/8))/Sqrt[2 + Sqrt[2]]] + (1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*ArcTan[(Sqrt[2 + Sqrt[2]] - (2*(1 + a*x)^(1/8))/(1 - a*x)^(1/8))/Sqrt[2 - Sqrt[2]]] + Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*ArcTan[(Sqrt[2 - Sqrt[2]] + (2*(1 + a*x)^(1/8))/(1 - a*x)^(1/8))/Sqrt[2 + Sqrt[2]]] - (1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*ArcTan[(Sqrt[2 + Sqrt[2]] + (2*(1 + a*x)^(1/8))/(1 - a*x)^(1/8))/Sqrt[2 - Sqrt[2]]] + Sqrt[2]*ArcTan[1 - (Sqrt[2]*(1 + a*x)^(1/8))/(1 - a*x)^(1/8)] - Sqrt[2]*ArcTan[1 + (Sqrt[2]*(1 + a*x)^(1/8))/(1 - a*x)^(1/8)] - 2*ArcTanh[(1 + a*x)^(1/8)/(1 - a*x)^(1/8)] - (1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*ArcTanh[(Sqrt[2 - Sqrt[2]]*(1 + a*x)^(1/8))/((1 - a*x)^(1/8)*(1 + (1 + a*x)^(1/4)/(1 - a*x)^(1/4)))] + Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*ArcTanh[(Sqrt[2 + Sqrt[2]]*(1 + a*x)^(1/8))/((1 - a*x)^(1/8)*(1 + (1 + a*x)^(1/4)/(1 - a*x)^(1/4)))] + Log[1 - (Sqrt[2]*(1 + a*x)^(1/8))/(1 - a*x)^(1/8) + (1 + a*x)^(1/4)/(1 - a*x)^(1/4)]/Sqrt[2] - Log[1 + (Sqrt[2]*(1 + a*x)^(1/8))/(1 - a*x)^(1/8) + (1 + a*x)^(1/4)/(1 - a*x)^(1/4)]/Sqrt[2]}
{E^(ArcTanh[a*x]/4)/x^2, x, 14, -(((1 - a*x)^(7/8)*(1 + a*x)^(1/8))/x) + (1/2)*a*ArcTan[(1 - a*x)^(1/8)/(1 + a*x)^(1/8)] - (a*ArcTan[1 - (Sqrt[2]*(1 - a*x)^(1/8))/(1 + a*x)^(1/8)])/(2*Sqrt[2]) + (a*ArcTan[1 + (Sqrt[2]*(1 - a*x)^(1/8))/(1 + a*x)^(1/8)])/(2*Sqrt[2]) - (1/2)*a*ArcTanh[(1 - a*x)^(1/8)/(1 + a*x)^(1/8)] + (a*Log[1 + (1 - a*x)^(1/4)/(1 + a*x)^(1/4) - (Sqrt[2]*(1 - a*x)^(1/8))/(1 + a*x)^(1/8)])/(4*Sqrt[2]) - (a*Log[1 + (1 - a*x)^(1/4)/(1 + a*x)^(1/4) + (Sqrt[2]*(1 - a*x)^(1/8))/(1 + a*x)^(1/8)])/(4*Sqrt[2])}
{E^(ArcTanh[a*x]/4)/x^3, x, 16, -(((1 - a*x)^(7/8)*(1 + a*x)^(1/8))/(2*x^2)) - (5*a*(1 - a*x)^(7/8)*(1 + a*x)^(1/8))/(8*x) + (1/16)*a^2*ArcTan[(1 - a*x)^(1/8)/(1 + a*x)^(1/8)] - (a^2*ArcTan[1 - (Sqrt[2]*(1 - a*x)^(1/8))/(1 + a*x)^(1/8)])/(16*Sqrt[2]) + (a^2*ArcTan[1 + (Sqrt[2]*(1 - a*x)^(1/8))/(1 + a*x)^(1/8)])/(16*Sqrt[2]) - (1/16)*a^2*ArcTanh[(1 - a*x)^(1/8)/(1 + a*x)^(1/8)] + (a^2*Log[1 + (1 - a*x)^(1/4)/(1 + a*x)^(1/4) - (Sqrt[2]*(1 - a*x)^(1/8))/(1 + a*x)^(1/8)])/(32*Sqrt[2]) - (a^2*Log[1 + (1 - a*x)^(1/4)/(1 + a*x)^(1/4) + (Sqrt[2]*(1 - a*x)^(1/8))/(1 + a*x)^(1/8)])/(32*Sqrt[2])}


(* ::Subsubsection:: *)
(*n<0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(n ArcTanh[a x]) with n symbolic*)


{E^(n*ArcTanh[a*x])*x^m, x, 2, (x^(1 + m)*AppellF1[1 + m, n/2, -(n/2), 2 + m, a*x, (-a)*x])/(1 + m)}

{E^(n*ArcTanh[a*x])*x^3, x, 2, -(((6 + n^2)*(1 - a*x)^(1 - n/2)*(1 + a*x)^((2 + n)/2))/(24*a^4)) - (n*x*(1 - a*x)^(1 - n/2)*(1 + a*x)^((2 + n)/2))/(12*a^3) - (x^2*(1 - a*x)^(1 - n/2)*(1 + a*x)^((2 + n)/2))/(4*a^2) + (2^(-2 - n/2)*n*(8 + n^2)*(1 + a*x)^((2 + n)/2)*Hypergeometric2F1[n/2, (2 + n)/2, (4 + n)/2, (1/2)*(1 + a*x)])/(3*a^4*(2 + n)), (1/4)*x^4*AppellF1[4, n/2, -(n/2), 5, a*x, (-a)*x]}
{E^(n*ArcTanh[a*x])*x^2, x, 4, -((n*(1 - a*x)^(1 - n/2)*(1 + a*x)^((2 + n)/2))/(6*a^3)) - (x*(1 - a*x)^(1 - n/2)*(1 + a*x)^((2 + n)/2))/(3*a^2) + ((2 + n^2)*(1 + a*x)^((2 + n)/2)*Hypergeometric2F1[n/2, (2 + n)/2, (4 + n)/2, (1/2)*(1 + a*x)])/(2^(n/2)*(3*a^3*(2 + n)))}
{E^(n*ArcTanh[a*x])*x^1, x, 3, -(((1 - a*x)^(1 - n/2)*(1 + a*x)^((2 + n)/2))/(2*a^2)) + (n*(1 + a*x)^((2 + n)/2)*Hypergeometric2F1[n/2, (2 + n)/2, (4 + n)/2, (1/2)*(1 + a*x)])/(2^(n/2)*(a^2*(2 + n)))}
{E^(n*ArcTanh[a*x])*x^0, x, 2, (2^(1 - n/2)*(1 + a*x)^((2 + n)/2)*Hypergeometric2F1[n/2, (2 + n)/2, (4 + n)/2, (1/2)*(1 + a*x)])/(a*(2 + n))}
{E^(n*ArcTanh[a*x])/x^1, x, 2, -((2^(1 + n/2)*(1 - a*x)^(1 - n/2)*AppellF1[1 - n/2, 1, -(n/2), 2 - n/2, 1 - a*x, (1/2)*(1 - a*x)])/(2 - n))}
{E^(n*ArcTanh[a*x])/x^2, x, 2, -((2^(1 + n/2)*a*(1 - a*x)^(1 - n/2)*(1 + (1/2)*(-1 + a*x))^((1/2)*(-2 + n))*Hypergeometric2F1[2, 1 - n/2, 2 - n/2, (1 - a*x)/(1 + a*x)])/(2 - n))}
{E^(n*ArcTanh[a*x])/x^3, x, 2, -((2^(1 + n/2)*a^2*(1 - a*x)^(1 - n/2)*Defer[AppellF1][1 - n/2, 3, -(n/2), 2 - n/2, 1 - a*x, (1/2)*(1 - a*x)])/(2 - n))}
{E^(n*ArcTanh[a*x])/x^4, x, 2, -((2^(1 + n/2)*a^3*(1 - a*x)^(1 - n/2)*Defer[AppellF1][1 - n/2, 4, -(n/2), 2 - n/2, 1 - a*x, (1/2)*(1 - a*x)])/(2 - n))}


(* ::Subtitle::Closed:: *)
(*Integration problems of the form u E^(n ArcTanh[a x]) (c-c a x)^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form E^(n ArcTanh[a x]) (c-c a x)^p*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{E^ArcTanh[a*x]*(c - a*c*x)^p, x, 5, -((Sqrt[1 - a*x]*Sqrt[1 + a*x]*(c - a*c*x)^p)/(a*(1 + p))) - (Sqrt[1 - a*x]*Sqrt[1 + a*x]*(c - a*c*x)^p)/(a*(1 + 3*p + 2*p^2)) + (2^(3/2 + p)*Sqrt[1 + a*x]*(c - a*c*x)^p*Hypergeometric2F1[1/2, -1/2 - p, 3/2, (1 + a*x)/2])/(a*(1 + 2*p)*(1 - a*x)^p)}

{E^ArcTanh[a*x]*(c - a*c*x)^4, x, 7, (7*c^4*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(8*a) + (7*c^4*(1 - a*x)^(3/2)*Sqrt[1 + a*x])/(24*a) + (7*c^4*(1 - a*x)^(5/2)*Sqrt[1 + a*x])/(60*a) + (c^4*(1 - a*x)^(7/2)*Sqrt[1 + a*x])/(20*a) - (c^4*(1 - a*x)^(9/2)*Sqrt[1 + a*x])/(5*a) + (7*c^4*ArcSin[a*x])/(8*a)}
{E^ArcTanh[a*x]*(c - a*c*x)^3, x, 6, (5*c^3*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(8*a) + (5*c^3*(1 - a*x)^(3/2)*Sqrt[1 + a*x])/(24*a) + (c^3*(1 - a*x)^(5/2)*Sqrt[1 + a*x])/(12*a) - (c^3*(1 - a*x)^(7/2)*Sqrt[1 + a*x])/(4*a) + (5*c^3*ArcSin[a*x])/(8*a)}
{E^ArcTanh[a*x]*(c - a*c*x)^2, x, 5, (c^2*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(2*a) + (c^2*(1 - a*x)^(3/2)*Sqrt[1 + a*x])/(6*a) - (c^2*(1 - a*x)^(5/2)*Sqrt[1 + a*x])/(3*a) + (c^2*ArcSin[a*x])/(2*a)}
{E^ArcTanh[a*x]*(c - a*c*x), x, 4, (c*x*Sqrt[1 - a^2*x^2])/2 + (c*ArcSin[a*x])/(2*a)}
{E^ArcTanh[a*x]/(c - a*c*x), x, 3, (2*Sqrt[1 + a*x])/(a*c*Sqrt[1 - a*x]) - ArcSin[a*x]/(a*c)}
{E^ArcTanh[a*x]/(c - a*c*x)^2, x, 2, (1 + a*x)^(3/2)/(3*a*c^2*(1 - a*x)^(3/2))}
{E^ArcTanh[a*x]/(c - a*c*x)^3, x, 3, (1 + a*x)^(3/2)/(5*a*c^3*(1 - a*x)^(5/2)) + (1 + a*x)^(3/2)/(15*a*c^3*(1 - a*x)^(3/2))}
{E^ArcTanh[a*x]/(c - a*c*x)^4, x, 4, (1 + a*x)^(3/2)/(7*a*c^4*(1 - a*x)^(7/2)) + (2*(1 + a*x)^(3/2))/(35*a*c^4*(1 - a*x)^(5/2)) + (2*(1 + a*x)^(3/2))/(105*a*c^4*(1 - a*x)^(3/2))}
{E^ArcTanh[a*x]/(c - a*c*x)^5, x, 5, (1 + a*x)^(3/2)/(9*a*c^5*(1 - a*x)^(9/2)) + (1 + a*x)^(3/2)/(21*a*c^5*(1 - a*x)^(7/2)) + (2*(1 + a*x)^(3/2))/(105*a*c^5*(1 - a*x)^(5/2)) + (2*(1 + a*x)^(3/2))/(315*a*c^5*(1 - a*x)^(3/2))}


{E^(2*ArcTanh[a*x])*(c - a*c*x)^p, x, 4, (-2*(c - a*c*x)^p)/(a*p) + ((1 - a*x)*(c - a*c*x)^p)/(a*(1 + p))}

{E^(2*ArcTanh[a*x])*(c - a*c*x)^5, x, 3, (-2*c^5*(1 - a*x)^5)/(5*a) + (c^5*(1 - a*x)^6)/(6*a)}
{E^(2*ArcTanh[a*x])*(c - a*c*x)^4, x, 3, c^4*x - a*c^4*x^2 + (a^3*c^4*x^4)/2 - (a^4*c^4*x^5)/5}
{E^(2*ArcTanh[a*x])*(c - a*c*x)^3, x, 3, c^3*x - (a*c^3*x^2)/2 - (a^2*c^3*x^3)/3 + (a^3*c^3*x^4)/4}
{E^(2*ArcTanh[a*x])*(c - a*c*x)^2, x, 3, c^2*x - (a^2*c^2*x^3)/3}
{E^(2*ArcTanh[a*x])*(c - a*c*x), x, 2, c*x + (a*c*x^2)/2}
{E^(2*ArcTanh[a*x])/(c - a*c*x), x, 3, 2/(a*c*(1 - a*x)) + Log[1 - a*x]/(a*c)}
{E^(2*ArcTanh[a*x])/(c - a*c*x)^2, x, 2, (1 + a*x)^2/(4*a*c^2*(1 - a*x)^2)}
{E^(2*ArcTanh[a*x])/(c - a*c*x)^3, x, 3, 2/(3*a*c^3*(1 - a*x)^3) - 1/(2*a*c^3*(1 - a*x)^2)}
{E^(2*ArcTanh[a*x])/(c - a*c*x)^4, x, 3, 1/(2*a*c^4*(1 - a*x)^4) - 1/(3*a*c^4*(1 - a*x)^3)}


{E^(3*ArcTanh[a*x])*(c - a*c*x)^p, x, 7, (-3*Sqrt[1 + a*x]*(c - a*c*x)^p)/(a*p*(1 + p)*Sqrt[1 - a*x]) + (3*Sqrt[1 + a*x]*(c - a*c*x)^p)/(a*p*(1 - p - 2*p^2)*Sqrt[1 - a*x]) + (3*Sqrt[1 - a*x]*Sqrt[1 + a*x]*(c - a*c*x)^p)/(a*(1 + p)*(1 - 4*p^2)) - ((1 + a*x)^(3/2)*(c - a*c*x)^p)/(a*(1 + p)*Sqrt[1 - a*x]) - (3*2^(3/2 + p)*Sqrt[1 + a*x]*(c - a*c*x)^p*Hypergeometric2F1[1/2, -1/2 - p, 3/2, (1 + a*x)/2])/(a*(1 - 4*p^2)*(1 - a*x)^p)}

{E^(3*ArcTanh[a*x])*(c - a*c*x)^4, x, 7, (3*c^4*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(8*a) + (c^4*(1 - a*x)^(3/2)*Sqrt[1 + a*x])/(8*a) + (c^4*(1 - a*x)^(5/2)*Sqrt[1 + a*x])/(20*a) - (3*c^4*(1 - a*x)^(7/2)*Sqrt[1 + a*x])/(20*a) - (c^4*(1 - a*x)^(7/2)*(1 + a*x)^(3/2))/(5*a) + (3*c^4*ArcSin[a*x])/(8*a)}
{E^(3*ArcTanh[a*x])*(c - a*c*x)^3, x, 5, (3*c^3*x*Sqrt[1 - a^2*x^2])/8 + (c^3*x*(1 - a^2*x^2)^(3/2))/4 + (3*c^3*ArcSin[a*x])/(8*a)}
{E^(3*ArcTanh[a*x])*(c - a*c*x)^2, x, 5, -(c^2*(1 - a*x)^(3/2)*(1 + a*x)^(3/2))/(3*a) + (c^2*x*Sqrt[1 - a^2*x^2])/2 + (c^2*ArcSin[a*x])/(2*a)}
{E^(3*ArcTanh[a*x])*(c - a*c*x), x, 4, (-3*c*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(2*a) - (c*Sqrt[1 - a*x]*(1 + a*x)^(3/2))/(2*a) + (3*c*ArcSin[a*x])/(2*a)}
{E^(3*ArcTanh[a*x])/(c - a*c*x), x, 4, (-2*Sqrt[1 + a*x])/(a*c*Sqrt[1 - a*x]) + (2*(1 + a*x)^(3/2))/(3*a*c*(1 - a*x)^(3/2)) + ArcSin[a*x]/(a*c)}
{E^(3*ArcTanh[a*x])/(c - a*c*x)^2, x, 2, (1 + a*x)^(5/2)/(5*a*c^2*(1 - a*x)^(5/2))}
{E^(3*ArcTanh[a*x])/(c - a*c*x)^3, x, 3, (1 + a*x)^(5/2)/(7*a*c^3*(1 - a*x)^(7/2)) + (1 + a*x)^(5/2)/(35*a*c^3*(1 - a*x)^(5/2))}
{E^(3*ArcTanh[a*x])/(c - a*c*x)^4, x, 4, (1 + a*x)^(5/2)/(9*a*c^4*(1 - a*x)^(9/2)) + (2*(1 + a*x)^(5/2))/(63*a*c^4*(1 - a*x)^(7/2)) + (2*(1 + a*x)^(5/2))/(315*a*c^4*(1 - a*x)^(5/2))}
{E^(3*ArcTanh[a*x])/(c - a*c*x)^5, x, 5, (1 + a*x)^(5/2)/(11*a*c^5*(1 - a*x)^(11/2)) + (1 + a*x)^(5/2)/(33*a*c^5*(1 - a*x)^(9/2)) + (2*(1 + a*x)^(5/2))/(231*a*c^5*(1 - a*x)^(7/2)) + (2*(1 + a*x)^(5/2))/(1155*a*c^5*(1 - a*x)^(5/2))}


{E^(4*ArcTanh[a*x])*(c - a*c*x)^p, x, 4, (4*(c - a*c*x)^p)/(a*p) + (4*(c - a*c*x)^p)/(a*(1 - p)*(1 - a*x)) - ((1 - a*x)*(c - a*c*x)^p)/(a*(1 + p))}

{E^(4*ArcTanh[a*x])*(c - a*c*x)^5, x, 3, -((c^5*(1 - a*x)^4)/a) + (4*c^5*(1 - a*x)^5)/(5*a) - (c^5*(1 - a*x)^6)/(6*a)}
{E^(4*ArcTanh[a*x])*(c - a*c*x)^4, x, 3, c^4*x - (2*a^2*c^4*x^3)/3 + (a^4*c^4*x^5)/5}
{E^(4*ArcTanh[a*x])*(c - a*c*x)^3, x, 3, c^3*x + (a*c^3*x^2)/2 - (a^2*c^3*x^3)/3 - (a^3*c^3*x^4)/4}
{E^(4*ArcTanh[a*x])*(c - a*c*x)^2, x, 2, (c^2*(1 + a*x)^3)/(3*a)}
{E^(4*ArcTanh[a*x])*(c - a*c*x), x, 3, -3*c*x - (a*c*x^2)/2 - (4*c*Log[1 - a*x])/a}
{E^(4*ArcTanh[a*x])/(c - a*c*x), x, 3, 2/(a*c*(1 - a*x)^2) - 4/(a*c*(1 - a*x)) - Log[1 - a*x]/(a*c)}
{E^(4*ArcTanh[a*x])/(c - a*c*x)^2, x, 2, (1 + a*x)^3/(6*a*c^2*(1 - a*x)^3)}
{E^(4*ArcTanh[a*x])/(c - a*c*x)^3, x, 3, 1/(a*c^3*(1 - a*x)^4) - 4/(3*a*c^3*(1 - a*x)^3) + 1/(2*a*c^3*(1 - a*x)^2)}
{E^(4*ArcTanh[a*x])/(c - a*c*x)^4, x, 3, 4/(5*a*c^4*(1 - a*x)^5) - 1/(a*c^4*(1 - a*x)^4) + 1/(3*a*c^4*(1 - a*x)^3)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(c - a*c*x)^p/E^ArcTanh[a*x], x, 3, (2^(3/2 + p)*Sqrt[1 + a*x]*(c - a*c*x)^p*Hypergeometric2F1[1/2, -1/2 - p, 3/2, (1 + a*x)/2])/(a*(1 - a*x)^p)}

{(c - a*c*x)^3/E^ArcTanh[a*x], x, 6, (35*c^3*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(8*a) + (35*c^3*(1 - a*x)^(3/2)*Sqrt[1 + a*x])/(24*a) + (7*c^3*(1 - a*x)^(5/2)*Sqrt[1 + a*x])/(12*a) + (c^3*(1 - a*x)^(7/2)*Sqrt[1 + a*x])/(4*a) + (35*c^3*ArcSin[a*x])/(8*a)}
{(c - a*c*x)^2/E^ArcTanh[a*x], x, 5, (5*c^2*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(2*a) + (5*c^2*(1 - a*x)^(3/2)*Sqrt[1 + a*x])/(6*a) + (c^2*(1 - a*x)^(5/2)*Sqrt[1 + a*x])/(3*a) + (5*c^2*ArcSin[a*x])/(2*a)}
{(c - a*c*x)/E^ArcTanh[a*x], x, 4, (3*c*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(2*a) + (c*(1 - a*x)^(3/2)*Sqrt[1 + a*x])/(2*a) + (3*c*ArcSin[a*x])/(2*a)}
{1/(E^ArcTanh[a*x]*(c - a*c*x)), x, 2, ArcSin[a*x]/(a*c)}
{1/(E^ArcTanh[a*x]*(c - a*c*x)^2), x, 2, Sqrt[1 + a*x]/(a*c^2*Sqrt[1 - a*x])}
{1/(E^ArcTanh[a*x]*(c - a*c*x)^3), x, 3, Sqrt[1 + a*x]/(3*a*c^3*(1 - a*x)^(3/2)) + Sqrt[1 + a*x]/(3*a*c^3*Sqrt[1 - a*x])}
{1/(E^ArcTanh[a*x]*(c - a*c*x)^4), x, 4, Sqrt[1 + a*x]/(5*a*c^4*(1 - a*x)^(5/2)) + (2*Sqrt[1 + a*x])/(15*a*c^4*(1 - a*x)^(3/2)) + (2*Sqrt[1 + a*x])/(15*a*c^4*Sqrt[1 - a*x])}
{1/(E^ArcTanh[a*x]*(c - a*c*x)^5), x, 5, Sqrt[1 + a*x]/(7*a*c^5*(1 - a*x)^(7/2)) + (3*Sqrt[1 + a*x])/(35*a*c^5*(1 - a*x)^(5/2)) + (2*Sqrt[1 + a*x])/(35*a*c^5*(1 - a*x)^(3/2)) + (2*Sqrt[1 + a*x])/(35*a*c^5*Sqrt[1 - a*x])}


{(c - a*c*x)^p/E^(2*ArcTanh[a*x]), x, 3, -(((1 - a*x)^2*(c - a*c*x)^p*Hypergeometric2F1[1, 2 + p, 3 + p, (1/2)*(1 - a*x)])/(2*a*(2 + p)))}

{(c - a*c*x)^4/E^(2*ArcTanh[a*x]), x, 3, -16*c^4*x + (4*c^4*(1 - a*x)^2)/a + (4*c^4*(1 - a*x)^3)/(3*a) + (c^4*(1 - a*x)^4)/(2*a) + (c^4*(1 - a*x)^5)/(5*a) + (32*c^4*Log[1 + a*x])/a}
{(c - a*c*x)^3/E^(2*ArcTanh[a*x]), x, 3, -8*c^3*x + (2*c^3*(1 - a*x)^2)/a + (2*c^3*(1 - a*x)^3)/(3*a) + (c^3*(1 - a*x)^4)/(4*a) + (16*c^3*Log[1 + a*x])/a}
{(c - a*c*x)^2/E^(2*ArcTanh[a*x]), x, 3, -4*c^2*x + (c^2*(1 - a*x)^2)/a + (c^2*(1 - a*x)^3)/(3*a) + (8*c^2*Log[1 + a*x])/a}
{(c - a*c*x)/E^(2*ArcTanh[a*x]), x, 3, -3*c*x + (a*c*x^2)/2 + (4*c*Log[1 + a*x])/a}
{1/(E^(2*ArcTanh[a*x])*(c - a*c*x)), x, 2, Log[1 + a*x]/(a*c)}
{1/(E^(2*ArcTanh[a*x])*(c - a*c*x)^2), x, 3, ArcTanh[a*x]/(a*c^2)}
{1/(E^(2*ArcTanh[a*x])*(c - a*c*x)^3), x, 4, 1/(2*a*c^3*(1 - a*x)) + ArcTanh[a*x]/(2*a*c^3)}
{1/(E^(2*ArcTanh[a*x])*(c - a*c*x)^4), x, 4, 1/(4*a*c^4*(1 - a*x)^2) + 1/(4*a*c^4*(1 - a*x)) + ArcTanh[a*x]/(4*a*c^4)}
{1/(E^(2*ArcTanh[a*x])*(c - a*c*x)^5), x, 4, 1/(6*a*c^5*(1 - a*x)^3) + 1/(8*a*c^5*(1 - a*x)^2) + 1/(8*a*c^5*(1 - a*x)) + ArcTanh[a*x]/(8*a*c^5)}


{(c - a*c*x)^p/E^(3*ArcTanh[a*x]), x, 5, ((1 - a*x)^(3/2)*(c - a*c*x)^p)/(a*(1 + p)*Sqrt[1 + a*x]) - ((3 + 2*p)*(1 - a*x)^(3/2)*(c - a*c*x)^p)/(a*(1 + p)*Sqrt[1 + a*x]) - (2^(3/2 + p)*(3 + 2*p)*Sqrt[1 + a*x]*(c - a*c*x)^p*Hypergeometric2F1[1/2, -1/2 - p, 3/2, (1 + a*x)/2])/(a*(1 - a*x)^p)}

{(c - a*c*x)^3/E^(3*ArcTanh[a*x]), x, 7, (-2*c^3*(1 - a*x)^(9/2))/(a*Sqrt[1 + a*x]) - (315*c^3*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(8*a) - (105*c^3*(1 - a*x)^(3/2)*Sqrt[1 + a*x])/(8*a) - (21*c^3*(1 - a*x)^(5/2)*Sqrt[1 + a*x])/(4*a) - (9*c^3*(1 - a*x)^(7/2)*Sqrt[1 + a*x])/(4*a) - (315*c^3*ArcSin[a*x])/(8*a)}
{(c - a*c*x)^2/E^(3*ArcTanh[a*x]), x, 6, (-2*c^2*(1 - a*x)^(7/2))/(a*Sqrt[1 + a*x]) - (35*c^2*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(2*a) - (35*c^2*(1 - a*x)^(3/2)*Sqrt[1 + a*x])/(6*a) - (7*c^2*(1 - a*x)^(5/2)*Sqrt[1 + a*x])/(3*a) - (35*c^2*ArcSin[a*x])/(2*a)}
{(c - a*c*x)/E^(3*ArcTanh[a*x]), x, 5, (-2*c*(1 - a*x)^(5/2))/(a*Sqrt[1 + a*x]) - (15*c*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(2*a) - (5*c*(1 - a*x)^(3/2)*Sqrt[1 + a*x])/(2*a) - (15*c*ArcSin[a*x])/(2*a)}
{1/(E^(3*ArcTanh[a*x])*(c - a*c*x)), x, 3, (-2*Sqrt[1 - a*x])/(a*c*Sqrt[1 + a*x]) - ArcSin[a*x]/(a*c)}
{1/(E^(3*ArcTanh[a*x])*(c - a*c*x)^2), x, 2, -(Sqrt[1 - a*x]/(a*c^2*Sqrt[1 + a*x]))}
{1/(E^(3*ArcTanh[a*x])*(c - a*c*x)^3), x, 3, x/(c^3*Sqrt[1 - a^2*x^2])}
{1/(E^(3*ArcTanh[a*x])*(c - a*c*x)^4), x, 4, 1/(3*a*c^4*(1 - a*x)^(3/2)*Sqrt[1 + a*x]) + (2*x)/(3*c^4*Sqrt[1 - a^2*x^2])}
{1/(E^(3*ArcTanh[a*x])*(c - a*c*x)^5), x, 5, 1/(5*a*c^5*(1 - a*x)^(5/2)*Sqrt[1 + a*x]) + 1/(5*a*c^5*(1 - a*x)^(3/2)*Sqrt[1 + a*x]) + (2*x)/(5*c^5*Sqrt[1 - a^2*x^2])}
{1/(E^(3*ArcTanh[a*x])*(c - a*c*x)^6), x, 6, 1/(7*a*c^6*(1 - a*x)^(7/2)*Sqrt[1 + a*x]) + 4/(35*a*c^6*(1 - a*x)^(5/2)*Sqrt[1 + a*x]) + 4/(35*a*c^6*(1 - a*x)^(3/2)*Sqrt[1 + a*x]) + (8*x)/(35*c^6*Sqrt[1 - a^2*x^2])}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{(c - a*c*x)^p/E^(2*p*ArcTanh[a*x]), x, 3, (4^p*(1 + a*x)^(1 - p)*(c - a*c*x)^p*Hypergeometric2F1[1 - p, -2*p, 2 - p, (1 + a*x)/2])/(a*(1 - p)*(1 - a*x)^p)}
{E^(2*p*ArcTanh[a*x])*(c - a*c*x)^p, x, 3, ((1 + a*x)^(1 + p)*(c - a*c*x)^p)/(a*(1 + p)*(1 - a*x)^p)}


{E^(n*ArcTanh[a*x])*(c - a*c*x)^p, x, 3, (2^(1 - n/2 + p)*(1 + a*x)^((2 + n)/2)*(c - a*c*x)^p*Hypergeometric2F1[(2 + n)/2, (n - 2*p)/2, (4 + n)/2, (1 + a*x)/2])/(a*(2 + n)*(1 - a*x)^p)}

{E^(n*ArcTanh[a*x])*(c - a*c*x)^3, x, 5, (c^3*(4 - n)*(6 - n)*(1 - a*x)^(1 - n/2)*(1 + a*x)^((2 + n)/2))/(24*a) + (c^3*(6 - n)*(1 - a*x)^(2 - n/2)*(1 + a*x)^((2 + n)/2))/(12*a) + (c^3*(1 - a*x)^(3 - n/2)*(1 + a*x)^((2 + n)/2))/(4*a) + (2^(-2 - n/2)*c^3*(2 - n)*(4 - n)*(6 - n)*(1 + a*x)^((2 + n)/2)*Hypergeometric2F1[n/2, (2 + n)/2, (4 + n)/2, (1 + a*x)/2])/(3*a*(2 + n))}
{E^(n*ArcTanh[a*x])*(c - a*c*x)^2, x, 4, (c^2*(4 - n)*(1 - a*x)^(1 - n/2)*(1 + a*x)^((2 + n)/2))/(6*a) + (c^2*(1 - a*x)^(2 - n/2)*(1 + a*x)^((2 + n)/2))/(3*a) + (c^2*(2 - n)*(4 - n)*(1 + a*x)^((2 + n)/2)*Hypergeometric2F1[n/2, (2 + n)/2, (4 + n)/2, (1 + a*x)/2])/(3*2^(n/2)*a*(2 + n))}
{E^(n*ArcTanh[a*x])*(c - a*c*x), x, 3, (c*(1 - a*x)^(1 - n/2)*(1 + a*x)^((2 + n)/2))/(2*a) + (c*(2 - n)*(1 + a*x)^((2 + n)/2)*Hypergeometric2F1[n/2, (2 + n)/2, (4 + n)/2, (1 + a*x)/2])/(2^(n/2)*a*(2 + n))}
{E^(n*ArcTanh[a*x]), x, 2, (2^(1 - n/2)*(1 + a*x)^((2 + n)/2)*Hypergeometric2F1[n/2, (2 + n)/2, (4 + n)/2, (1 + a*x)/2])/(a*(2 + n))}
{E^(n*ArcTanh[a*x])/(c - a*c*x), x, 3, (1 + a*x)^((2 + n)/2)/(a*c*n*(1 - a*x)^(n/2)) - (2^(1 - n/2)*(1 + a*x)^((2 + n)/2)*Hypergeometric2F1[n/2, (2 + n)/2, (4 + n)/2, (1 + a*x)/2])/(a*c*n*(2 + n))}
{E^(n*ArcTanh[a*x])/(c - a*c*x)^2, x, 2, ((1 - a*x)^(-1 - n/2)*(1 + a*x)^((2 + n)/2))/(a*c^2*(2 + n))}
{E^(n*ArcTanh[a*x])/(c - a*c*x)^3, x, 3, ((1 - a*x)^(-2 - n/2)*(1 + a*x)^((2 + n)/2))/(a*c^3*(4 + n)) + ((1 - a*x)^(-1 - n/2)*(1 + a*x)^((2 + n)/2))/(a*c^3*(8 + 6*n + n^2))}
{E^(n*ArcTanh[a*x])/(c - a*c*x)^4, x, 4, ((1 - a*x)^(-3 - n/2)*(1 + a*x)^((2 + n)/2))/(a*c^4*(6 + n)) + (2*(1 - a*x)^(-2 - n/2)*(1 + a*x)^((2 + n)/2))/(a*c^4*(4 + n)*(6 + n)) + (2*(1 - a*x)^(-1 - n/2)*(1 + a*x)^((2 + n)/2))/(a*c^4*(6 + n)*(8 + 6*n + n^2))}


(* ::Subsection::Closed:: *)
(*Integrands of the form E^(n ArcTanh[a x])  (c-c a x)^(p/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{E^ArcTanh[a*x]*(c - a*c*x)^(9/2), x, 4, (32*(1 + a*x)^(3/2)*(c - a*c*x)^(9/2))/(3*a*(1 - a*x)^(9/2)) - (64*(1 + a*x)^(5/2)*(c - a*c*x)^(9/2))/(5*a*(1 - a*x)^(9/2)) + (48*(1 + a*x)^(7/2)*(c - a*c*x)^(9/2))/(7*a*(1 - a*x)^(9/2)) - (16*(1 + a*x)^(9/2)*(c - a*c*x)^(9/2))/(9*a*(1 - a*x)^(9/2)) + (2*(1 + a*x)^(11/2)*(c - a*c*x)^(9/2))/(11*a*(1 - a*x)^(9/2))}
{E^ArcTanh[a*x]*(c - a*c*x)^(7/2), x, 4, (16*(1 + a*x)^(3/2)*(c - a*c*x)^(7/2))/(3*a*(1 - a*x)^(7/2)) - (24*(1 + a*x)^(5/2)*(c - a*c*x)^(7/2))/(5*a*(1 - a*x)^(7/2)) + (12*(1 + a*x)^(7/2)*(c - a*c*x)^(7/2))/(7*a*(1 - a*x)^(7/2)) - (2*(1 + a*x)^(9/2)*(c - a*c*x)^(7/2))/(9*a*(1 - a*x)^(7/2))}
{E^ArcTanh[a*x]*(c - a*c*x)^(5/2), x, 4, (8*(1 + a*x)^(3/2)*(c - a*c*x)^(5/2))/(3*a*(1 - a*x)^(5/2)) - (8*(1 + a*x)^(5/2)*(c - a*c*x)^(5/2))/(5*a*(1 - a*x)^(5/2)) + (2*(1 + a*x)^(7/2)*(c - a*c*x)^(5/2))/(7*a*(1 - a*x)^(5/2))}
{E^ArcTanh[a*x]*(c - a*c*x)^(3/2), x, 4, (4*(1 + a*x)^(3/2)*(c - a*c*x)^(3/2))/(3*a*(1 - a*x)^(3/2)) - (2*(1 + a*x)^(5/2)*(c - a*c*x)^(3/2))/(5*a*(1 - a*x)^(3/2))}
{E^ArcTanh[a*x]*Sqrt[c - a*c*x], x, 3, (2*(1 + a*x)^(3/2)*Sqrt[c - a*c*x])/(3*a*Sqrt[1 - a*x])}
{E^ArcTanh[a*x]/Sqrt[c - a*c*x], x, 4, (-2*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(a*Sqrt[c - a*c*x]) + (2*Sqrt[2]*Sqrt[1 - a*x]*ArcTanh[Sqrt[1 + a*x]/Sqrt[2]])/(a*Sqrt[c - a*c*x])}
{E^ArcTanh[a*x]/(c - a*c*x)^(3/2), x, 4, (Sqrt[1 - a*x]*Sqrt[1 + a*x])/(a*(c - a*c*x)^(3/2)) - ((1 - a*x)^(3/2)*ArcTanh[Sqrt[1 + a*x]/Sqrt[2]])/(Sqrt[2]*a*(c - a*c*x)^(3/2))}
{E^ArcTanh[a*x]/(c - a*c*x)^(5/2), x, 5, (Sqrt[1 - a*x]*Sqrt[1 + a*x])/(2*a*(c - a*c*x)^(5/2)) - ((1 - a*x)^(3/2)*Sqrt[1 + a*x])/(8*a*(c - a*c*x)^(5/2)) - ((1 - a*x)^(5/2)*ArcTanh[Sqrt[1 + a*x]/Sqrt[2]])/(8*Sqrt[2]*a*(c - a*c*x)^(5/2))}
{E^ArcTanh[a*x]/(c - a*c*x)^(7/2), x, 6, (Sqrt[1 - a*x]*Sqrt[1 + a*x])/(3*a*(c - a*c*x)^(7/2)) - ((1 - a*x)^(3/2)*Sqrt[1 + a*x])/(24*a*(c - a*c*x)^(7/2)) - ((1 - a*x)^(5/2)*Sqrt[1 + a*x])/(32*a*(c - a*c*x)^(7/2)) - ((1 - a*x)^(7/2)*ArcTanh[Sqrt[1 + a*x]/Sqrt[2]])/(32*Sqrt[2]*a*(c - a*c*x)^(7/2))}


{E^(2*ArcTanh[a*x])*(c - a*c*x)^(9/2), x, 4, (-4*(c - a*c*x)^(9/2))/(9*a) + (2*(1 - a*x)*(c - a*c*x)^(9/2))/(11*a)}
{E^(2*ArcTanh[a*x])*(c - a*c*x)^(7/2), x, 4, (-4*(c - a*c*x)^(7/2))/(7*a) + (2*(1 - a*x)*(c - a*c*x)^(7/2))/(9*a)}
{E^(2*ArcTanh[a*x])*(c - a*c*x)^(5/2), x, 4, (-4*(c - a*c*x)^(5/2))/(5*a) + (2*(1 - a*x)*(c - a*c*x)^(5/2))/(7*a)}
{E^(2*ArcTanh[a*x])*(c - a*c*x)^(3/2), x, 4, (-4*(c - a*c*x)^(3/2))/(3*a) + (2*(1 - a*x)*(c - a*c*x)^(3/2))/(5*a)}
{E^(2*ArcTanh[a*x])*Sqrt[c - a*c*x], x, 4, (-4*Sqrt[c - a*c*x])/a + (2*(1 - a*x)*Sqrt[c - a*c*x])/(3*a)}
{E^(2*ArcTanh[a*x])/Sqrt[c - a*c*x], x, 4, 4/(a*Sqrt[c - a*c*x]) + (2*(1 - a*x))/(a*Sqrt[c - a*c*x])}
{E^(2*ArcTanh[a*x])/(c - a*c*x)^(3/2), x, 4, 4/(3*a*(c - a*c*x)^(3/2)) - (2*(1 - a*x))/(a*(c - a*c*x)^(3/2))}
{E^(2*ArcTanh[a*x])/(c - a*c*x)^(5/2), x, 4, 4/(5*a*(c - a*c*x)^(5/2)) - (2*(1 - a*x))/(3*a*(c - a*c*x)^(5/2))}
{E^(2*ArcTanh[a*x])/(c - a*c*x)^(7/2), x, 4, 4/(7*a*(c - a*c*x)^(7/2)) - (2*(1 - a*x))/(5*a*(c - a*c*x)^(7/2))}
{E^(2*ArcTanh[a*x])/(c - a*c*x)^(9/2), x, 4, 4/(9*a*(c - a*c*x)^(9/2)) - (2*(1 - a*x))/(7*a*(c - a*c*x)^(9/2))}


{E^(3*ArcTanh[a*x])*(c - a*c*x)^(9/2), x, 4, (16*(1 + a*x)^(5/2)*(c - a*c*x)^(9/2))/(5*a*(1 - a*x)^(9/2)) - (24*(1 + a*x)^(7/2)*(c - a*c*x)^(9/2))/(7*a*(1 - a*x)^(9/2)) + (4*(1 + a*x)^(9/2)*(c - a*c*x)^(9/2))/(3*a*(1 - a*x)^(9/2)) - (2*(1 + a*x)^(11/2)*(c - a*c*x)^(9/2))/(11*a*(1 - a*x)^(9/2))}
{E^(3*ArcTanh[a*x])*(c - a*c*x)^(7/2), x, 4, (8*(1 + a*x)^(5/2)*(c - a*c*x)^(7/2))/(5*a*(1 - a*x)^(7/2)) - (8*(1 + a*x)^(7/2)*(c - a*c*x)^(7/2))/(7*a*(1 - a*x)^(7/2)) + (2*(1 + a*x)^(9/2)*(c - a*c*x)^(7/2))/(9*a*(1 - a*x)^(7/2))}
{E^(3*ArcTanh[a*x])*(c - a*c*x)^(5/2), x, 4, (4*(1 + a*x)^(5/2)*(c - a*c*x)^(5/2))/(5*a*(1 - a*x)^(5/2)) - (2*(1 + a*x)^(7/2)*(c - a*c*x)^(5/2))/(7*a*(1 - a*x)^(5/2))}
{E^(3*ArcTanh[a*x])*(c - a*c*x)^(3/2), x, 3, (2*(1 + a*x)^(5/2)*(c - a*c*x)^(3/2))/(5*a*(1 - a*x)^(3/2))}
{E^(3*ArcTanh[a*x])*Sqrt[c - a*c*x], x, 5, (-4*Sqrt[1 + a*x]*Sqrt[c - a*c*x])/(a*Sqrt[1 - a*x]) - (2*(1 + a*x)^(3/2)*Sqrt[c - a*c*x])/(3*a*Sqrt[1 - a*x]) + (4*Sqrt[2]*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 + a*x]/Sqrt[2]])/(a*Sqrt[1 - a*x])}
{E^(3*ArcTanh[a*x])/Sqrt[c - a*c*x], x, 5, (3*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(a*Sqrt[c - a*c*x]) + (1 + a*x)^(3/2)/(a*Sqrt[1 - a*x]*Sqrt[c - a*c*x]) - (3*Sqrt[2]*Sqrt[1 - a*x]*ArcTanh[Sqrt[1 + a*x]/Sqrt[2]])/(a*Sqrt[c - a*c*x])}
{E^(3*ArcTanh[a*x])/(c - a*c*x)^(3/2), x, 5, (-3*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(4*a*(c - a*c*x)^(3/2)) + (1 + a*x)^(3/2)/(2*a*Sqrt[1 - a*x]*(c - a*c*x)^(3/2)) + (3*(1 - a*x)^(3/2)*ArcTanh[Sqrt[1 + a*x]/Sqrt[2]])/(4*Sqrt[2]*a*(c - a*c*x)^(3/2))}
{E^(3*ArcTanh[a*x])/(c - a*c*x)^(5/2), x, 6, -(Sqrt[1 - a*x]*Sqrt[1 + a*x])/(4*a*(c - a*c*x)^(5/2)) + ((1 - a*x)^(3/2)*Sqrt[1 + a*x])/(16*a*(c - a*c*x)^(5/2)) + (1 + a*x)^(3/2)/(3*a*Sqrt[1 - a*x]*(c - a*c*x)^(5/2)) + ((1 - a*x)^(5/2)*ArcTanh[Sqrt[1 + a*x]/Sqrt[2]])/(16*Sqrt[2]*a*(c - a*c*x)^(5/2))}
{E^(3*ArcTanh[a*x])/(c - a*c*x)^(7/2), x, 7, -(Sqrt[1 - a*x]*Sqrt[1 + a*x])/(8*a*(c - a*c*x)^(7/2)) + ((1 - a*x)^(3/2)*Sqrt[1 + a*x])/(64*a*(c - a*c*x)^(7/2)) + (3*(1 - a*x)^(5/2)*Sqrt[1 + a*x])/(256*a*(c - a*c*x)^(7/2)) + (1 + a*x)^(3/2)/(4*a*Sqrt[1 - a*x]*(c - a*c*x)^(7/2)) + (3*(1 - a*x)^(7/2)*ArcTanh[Sqrt[1 + a*x]/Sqrt[2]])/(256*Sqrt[2]*a*(c - a*c*x)^(7/2))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(c - a*c*x)^(9/2)/E^ArcTanh[a*x], x, 4, (64*Sqrt[1 + a*x]*(c - a*c*x)^(9/2))/(a*(1 - a*x)^(9/2)) - (160*(1 + a*x)^(3/2)*(c - a*c*x)^(9/2))/(3*a*(1 - a*x)^(9/2)) + (32*(1 + a*x)^(5/2)*(c - a*c*x)^(9/2))/(a*(1 - a*x)^(9/2)) - (80*(1 + a*x)^(7/2)*(c - a*c*x)^(9/2))/(7*a*(1 - a*x)^(9/2)) + (20*(1 + a*x)^(9/2)*(c - a*c*x)^(9/2))/(9*a*(1 - a*x)^(9/2)) - (2*(1 + a*x)^(11/2)*(c - a*c*x)^(9/2))/(11*a*(1 - a*x)^(9/2))}
{(c - a*c*x)^(7/2)/E^ArcTanh[a*x], x, 4, (32*Sqrt[1 + a*x]*(c - a*c*x)^(7/2))/(a*(1 - a*x)^(7/2)) - (64*(1 + a*x)^(3/2)*(c - a*c*x)^(7/2))/(3*a*(1 - a*x)^(7/2)) + (48*(1 + a*x)^(5/2)*(c - a*c*x)^(7/2))/(5*a*(1 - a*x)^(7/2)) - (16*(1 + a*x)^(7/2)*(c - a*c*x)^(7/2))/(7*a*(1 - a*x)^(7/2)) + (2*(1 + a*x)^(9/2)*(c - a*c*x)^(7/2))/(9*a*(1 - a*x)^(7/2))}
{(c - a*c*x)^(5/2)/E^ArcTanh[a*x], x, 4, (16*Sqrt[1 + a*x]*(c - a*c*x)^(5/2))/(a*(1 - a*x)^(5/2)) - (8*(1 + a*x)^(3/2)*(c - a*c*x)^(5/2))/(a*(1 - a*x)^(5/2)) + (12*(1 + a*x)^(5/2)*(c - a*c*x)^(5/2))/(5*a*(1 - a*x)^(5/2)) - (2*(1 + a*x)^(7/2)*(c - a*c*x)^(5/2))/(7*a*(1 - a*x)^(5/2))}
{(c - a*c*x)^(3/2)/E^ArcTanh[a*x], x, 4, (8*Sqrt[1 + a*x]*(c - a*c*x)^(3/2))/(a*(1 - a*x)^(3/2)) - (8*(1 + a*x)^(3/2)*(c - a*c*x)^(3/2))/(3*a*(1 - a*x)^(3/2)) + (2*(1 + a*x)^(5/2)*(c - a*c*x)^(3/2))/(5*a*(1 - a*x)^(3/2))}
{Sqrt[c - a*c*x]/E^ArcTanh[a*x], x, 4, (4*Sqrt[1 + a*x]*Sqrt[c - a*c*x])/(a*Sqrt[1 - a*x]) - (2*(1 + a*x)^(3/2)*Sqrt[c - a*c*x])/(3*a*Sqrt[1 - a*x])}
{1/(E^ArcTanh[a*x]*Sqrt[c - a*c*x]), x, 3, (2*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(a*Sqrt[c - a*c*x])}
{1/(E^ArcTanh[a*x]*(c - a*c*x)^(3/2)), x, 3, (Sqrt[2]*(1 - a*x)^(3/2)*ArcTanh[Sqrt[1 + a*x]/Sqrt[2]])/(a*(c - a*c*x)^(3/2))}
{1/(E^ArcTanh[a*x]*(c - a*c*x)^(5/2)), x, 4, ((1 - a*x)^(3/2)*Sqrt[1 + a*x])/(2*a*(c - a*c*x)^(5/2)) + ((1 - a*x)^(5/2)*ArcTanh[Sqrt[1 + a*x]/Sqrt[2]])/(2*Sqrt[2]*a*(c - a*c*x)^(5/2))}
{1/(E^ArcTanh[a*x]*(c - a*c*x)^(7/2)), x, 5, ((1 - a*x)^(3/2)*Sqrt[1 + a*x])/(4*a*(c - a*c*x)^(7/2)) + (3*(1 - a*x)^(5/2)*Sqrt[1 + a*x])/(16*a*(c - a*c*x)^(7/2)) + (3*(1 - a*x)^(7/2)*ArcTanh[Sqrt[1 + a*x]/Sqrt[2]])/(16*Sqrt[2]*a*(c - a*c*x)^(7/2))}


{(c - a*c*x)^(9/2)/E^(2*ArcTanh[a*x]), x, 9, (4*(c - a*c*x)^(9/2))/(9*a) + (64*(c - a*c*x)^(9/2))/(a*(1 - a*x)^4) + (32*(c - a*c*x)^(9/2))/(3*a*(1 - a*x)^3) + (16*(c - a*c*x)^(9/2))/(5*a*(1 - a*x)^2) + (8*(c - a*c*x)^(9/2))/(7*a*(1 - a*x)) + (2*(1 - a*x)*(c - a*c*x)^(9/2))/(11*a) - (64*Sqrt[2]*(c - a*c*x)^(9/2)*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/(a*(1 - a*x)^(9/2))}
{(c - a*c*x)^(7/2)/E^(2*ArcTanh[a*x]), x, 8, (4*(c - a*c*x)^(7/2))/(7*a) + (32*(c - a*c*x)^(7/2))/(a*(1 - a*x)^3) + (16*(c - a*c*x)^(7/2))/(3*a*(1 - a*x)^2) + (8*(c - a*c*x)^(7/2))/(5*a*(1 - a*x)) + (2*(1 - a*x)*(c - a*c*x)^(7/2))/(9*a) - (32*Sqrt[2]*(c - a*c*x)^(7/2)*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/(a*(1 - a*x)^(7/2))}
{(c - a*c*x)^(5/2)/E^(2*ArcTanh[a*x]), x, 7, (4*(c - a*c*x)^(5/2))/(5*a) + (16*(c - a*c*x)^(5/2))/(a*(1 - a*x)^2) + (8*(c - a*c*x)^(5/2))/(3*a*(1 - a*x)) + (2*(1 - a*x)*(c - a*c*x)^(5/2))/(7*a) - (16*Sqrt[2]*(c - a*c*x)^(5/2)*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/(a*(1 - a*x)^(5/2))}
{(c - a*c*x)^(3/2)/E^(2*ArcTanh[a*x]), x, 6, (4*(c - a*c*x)^(3/2))/(3*a) + (8*(c - a*c*x)^(3/2))/(a*(1 - a*x)) + (2*(1 - a*x)*(c - a*c*x)^(3/2))/(5*a) - (8*Sqrt[2]*(c - a*c*x)^(3/2)*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/(a*(1 - a*x)^(3/2))}
{Sqrt[c - a*c*x]/E^(2*ArcTanh[a*x]), x, 5, (4*Sqrt[c - a*c*x])/a + (2*(1 - a*x)*Sqrt[c - a*c*x])/(3*a) - (4*Sqrt[2]*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/(a*Sqrt[1 - a*x])}
{1/(E^(2*ArcTanh[a*x])*Sqrt[c - a*c*x]), x, 4, (2*(1 - a*x))/(a*Sqrt[c - a*c*x]) - (2*Sqrt[2]*Sqrt[1 - a*x]*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/(a*Sqrt[c - a*c*x])}
{1/(E^(2*ArcTanh[a*x])*(c - a*c*x)^(3/2)), x, 3, -((Sqrt[2]*(1 - a*x)^(3/2)*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/(a*(c - a*c*x)^(3/2)))}
{1/(E^(2*ArcTanh[a*x])*(c - a*c*x)^(5/2)), x, 4, (1 - a*x)^2/(a*(c - a*c*x)^(5/2)) - ((1 - a*x)^(5/2)*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/(Sqrt[2]*a*(c - a*c*x)^(5/2))}
{1/(E^(2*ArcTanh[a*x])*(c - a*c*x)^(7/2)), x, 5, (1 - a*x)^2/(3*a*(c - a*c*x)^(7/2)) + (1 - a*x)^3/(2*a*(c - a*c*x)^(7/2)) - ((1 - a*x)^(7/2)*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/(2*Sqrt[2]*a*(c - a*c*x)^(7/2))}


{(c - a*c*x)^(9/2)/E^(3*ArcTanh[a*x]), x, 4, (-128*(c - a*c*x)^(9/2))/(a*(1 - a*x)^(9/2)*Sqrt[1 + a*x]) - (384*Sqrt[1 + a*x]*(c - a*c*x)^(9/2))/(a*(1 - a*x)^(9/2)) + (160*(1 + a*x)^(3/2)*(c - a*c*x)^(9/2))/(a*(1 - a*x)^(9/2)) - (64*(1 + a*x)^(5/2)*(c - a*c*x)^(9/2))/(a*(1 - a*x)^(9/2)) + (120*(1 + a*x)^(7/2)*(c - a*c*x)^(9/2))/(7*a*(1 - a*x)^(9/2)) - (8*(1 + a*x)^(9/2)*(c - a*c*x)^(9/2))/(3*a*(1 - a*x)^(9/2)) + (2*(1 + a*x)^(11/2)*(c - a*c*x)^(9/2))/(11*a*(1 - a*x)^(9/2))}
{(c - a*c*x)^(7/2)/E^(3*ArcTanh[a*x]), x, 4, (-64*(c - a*c*x)^(7/2))/(a*(1 - a*x)^(7/2)*Sqrt[1 + a*x]) - (160*Sqrt[1 + a*x]*(c - a*c*x)^(7/2))/(a*(1 - a*x)^(7/2)) + (160*(1 + a*x)^(3/2)*(c - a*c*x)^(7/2))/(3*a*(1 - a*x)^(7/2)) - (16*(1 + a*x)^(5/2)*(c - a*c*x)^(7/2))/(a*(1 - a*x)^(7/2)) + (20*(1 + a*x)^(7/2)*(c - a*c*x)^(7/2))/(7*a*(1 - a*x)^(7/2)) - (2*(1 + a*x)^(9/2)*(c - a*c*x)^(7/2))/(9*a*(1 - a*x)^(7/2))}
{(c - a*c*x)^(5/2)/E^(3*ArcTanh[a*x]), x, 4, (-32*(c - a*c*x)^(5/2))/(a*(1 - a*x)^(5/2)*Sqrt[1 + a*x]) - (64*Sqrt[1 + a*x]*(c - a*c*x)^(5/2))/(a*(1 - a*x)^(5/2)) + (16*(1 + a*x)^(3/2)*(c - a*c*x)^(5/2))/(a*(1 - a*x)^(5/2)) - (16*(1 + a*x)^(5/2)*(c - a*c*x)^(5/2))/(5*a*(1 - a*x)^(5/2)) + (2*(1 + a*x)^(7/2)*(c - a*c*x)^(5/2))/(7*a*(1 - a*x)^(5/2))}
{(c - a*c*x)^(3/2)/E^(3*ArcTanh[a*x]), x, 4, (-16*(c - a*c*x)^(3/2))/(a*(1 - a*x)^(3/2)*Sqrt[1 + a*x]) - (24*Sqrt[1 + a*x]*(c - a*c*x)^(3/2))/(a*(1 - a*x)^(3/2)) + (4*(1 + a*x)^(3/2)*(c - a*c*x)^(3/2))/(a*(1 - a*x)^(3/2)) - (2*(1 + a*x)^(5/2)*(c - a*c*x)^(3/2))/(5*a*(1 - a*x)^(3/2))}
{Sqrt[c - a*c*x]/E^(3*ArcTanh[a*x]), x, 4, (-8*Sqrt[c - a*c*x])/(a*Sqrt[1 - a*x]*Sqrt[1 + a*x]) - (8*Sqrt[1 + a*x]*Sqrt[c - a*c*x])/(a*Sqrt[1 - a*x]) + (2*(1 + a*x)^(3/2)*Sqrt[c - a*c*x])/(3*a*Sqrt[1 - a*x])}
{1/(E^(3*ArcTanh[a*x])*Sqrt[c - a*c*x]), x, 4, (-4*Sqrt[1 - a*x])/(a*Sqrt[1 + a*x]*Sqrt[c - a*c*x]) - (2*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(a*Sqrt[c - a*c*x])}
{1/(E^(3*ArcTanh[a*x])*(c - a*c*x)^(3/2)), x, 3, (-2*(1 - a*x)^(3/2))/(a*Sqrt[1 + a*x]*(c - a*c*x)^(3/2))}
{1/(E^(3*ArcTanh[a*x])*(c - a*c*x)^(5/2)), x, 4, -((1 - a*x)^(5/2)/(a*Sqrt[1 + a*x]*(c - a*c*x)^(5/2))) + ((1 - a*x)^(5/2)*ArcTanh[Sqrt[1 + a*x]/Sqrt[2]])/(Sqrt[2]*a*(c - a*c*x)^(5/2))}
{1/(E^(3*ArcTanh[a*x])*(c - a*c*x)^(7/2)), x, 5, (1 - a*x)^(5/2)/(2*a*Sqrt[1 + a*x]*(c - a*c*x)^(7/2)) - (3*(1 - a*x)^(7/2))/(4*a*Sqrt[1 + a*x]*(c - a*c*x)^(7/2)) + (3*(1 - a*x)^(7/2)*ArcTanh[Sqrt[1 + a*x]/Sqrt[2]])/(4*Sqrt[2]*a*(c - a*c*x)^(7/2))}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{E^(n*ArcTanh[a*x])*(c - a*c*x)^(7/2), x, 6, (8*(5 - n)*(7 - n)*(1 - a*x)^((-4 - n)/2)*(1 + a*x)^((2 + n)/2)*(c - a*c*x)^(7/2))/(315*a) + (4*(7 - n)*(1 - a*x)^((-2 - n)/2)*(1 + a*x)^((2 + n)/2)*(c - a*c*x)^(7/2))/(63*a) + (2*(1 + a*x)^((2 + n)/2)*(c - a*c*x)^(7/2))/(9*a*(1 - a*x)^(n/2)) + (2^(9/2 - n/2)*(3 - n)*(5 - n)*(7 - n)*(1 + a*x)^((2 + n)/2)*(c - a*c*x)^(7/2)*Hypergeometric2F1[(-1 + n)/2, (2 + n)/2, (4 + n)/2, (1 + a*x)/2])/(315*a*(2 + n)*(1 - a*x)^(7/2))}
{E^(n*ArcTanh[a*x])*(c - a*c*x)^(5/2), x, 5, (4*(5 - n)*(1 - a*x)^((-2 - n)/2)*(1 + a*x)^((2 + n)/2)*(c - a*c*x)^(5/2))/(35*a) + (2*(1 + a*x)^((2 + n)/2)*(c - a*c*x)^(5/2))/(7*a*(1 - a*x)^(n/2)) + (2^(7/2 - n/2)*(3 - n)*(5 - n)*(1 + a*x)^((2 + n)/2)*(c - a*c*x)^(5/2)*Hypergeometric2F1[(-1 + n)/2, (2 + n)/2, (4 + n)/2, (1 + a*x)/2])/(35*a*(2 + n)*(1 - a*x)^(5/2))}
{E^(n*ArcTanh[a*x])*(c - a*c*x)^(3/2), x, 4, (2*(1 + a*x)^((2 + n)/2)*(c - a*c*x)^(3/2))/(5*a*(1 - a*x)^(n/2)) + (2^(5/2 - n/2)*(3 - n)*(1 + a*x)^((2 + n)/2)*(c - a*c*x)^(3/2)*Hypergeometric2F1[(-1 + n)/2, (2 + n)/2, (4 + n)/2, (1 + a*x)/2])/(5*a*(2 + n)*(1 - a*x)^(3/2))}
{E^(n*ArcTanh[a*x])*Sqrt[c - a*c*x], x, 3, (2^(3/2 - n/2)*(1 + a*x)^((2 + n)/2)*Sqrt[c - a*c*x]*Hypergeometric2F1[(-1 + n)/2, (2 + n)/2, (4 + n)/2, (1 + a*x)/2])/(a*(2 + n)*Sqrt[1 - a*x])}
{E^(n*ArcTanh[a*x])/Sqrt[c - a*c*x], x, 4, -(((1 - a*x)^((2 - n)/2)*(1 + a*x)^((2 + n)/2))/(a*(1 - n)*Sqrt[c - a*c*x])) + (3*2^(1/2 - n/2)*Sqrt[1 - a*x]*(1 + a*x)^((2 + n)/2)*Hypergeometric2F1[(-1 + n)/2, (2 + n)/2, (4 + n)/2, (1 + a*x)/2])/(a*(2 - n - n^2)*Sqrt[c - a*c*x])}
{E^(n*ArcTanh[a*x])/(c - a*c*x)^(3/2), x, 5, ((1 - a*x)^((2 - n)/2)*(1 + a*x)^((2 + n)/2))/(a*(1 + n)*(c - a*c*x)^(3/2)) + ((1 - a*x)^((4 - n)/2)*(1 + a*x)^((2 + n)/2))/(2*a*(1 - n^2)*(c - a*c*x)^(3/2)) - (3*2^(-1/2 - n/2)*(1 - a*x)^(3/2)*(1 + a*x)^((2 + n)/2)*Hypergeometric2F1[(-1 + n)/2, (2 + n)/2, (4 + n)/2, (1 + a*x)/2])/(a*(1 + n)*(2 - n - n^2)*(c - a*c*x)^(3/2))}
{E^(n*ArcTanh[a*x])/(c - a*c*x)^(5/2), x, 6, ((1 - a*x)^((2 - n)/2)*(1 + a*x)^((2 + n)/2))/(a*(3 + n)*(c - a*c*x)^(5/2)) + ((1 - a*x)^((4 - n)/2)*(1 + a*x)^((2 + n)/2))/(2*a*(3 + 4*n + n^2)*(c - a*c*x)^(5/2)) + ((1 - a*x)^((6 - n)/2)*(1 + a*x)^((2 + n)/2))/(4*a*(3 + n)*(1 - n^2)*(c - a*c*x)^(5/2)) - (3*2^(-3/2 - n/2)*(1 - a*x)^(5/2)*(1 + a*x)^((2 + n)/2)*Hypergeometric2F1[(-1 + n)/2, (2 + n)/2, (4 + n)/2, (1 + a*x)/2])/(a*(1 + n)*(3 + n)*(2 - n - n^2)*(c - a*c*x)^(5/2))}
{E^(n*ArcTanh[a*x])/(c - a*c*x)^(7/2), x, 7, ((1 - a*x)^((2 - n)/2)*(1 + a*x)^((2 + n)/2))/(a*(5 + n)*(c - a*c*x)^(7/2)) + (3*(1 - a*x)^((4 - n)/2)*(1 + a*x)^((2 + n)/2))/(2*a*(3 + n)*(5 + n)*(c - a*c*x)^(7/2)) + (3*(1 - a*x)^((6 - n)/2)*(1 + a*x)^((2 + n)/2))/(4*a*(5 + n)*(3 + 4*n + n^2)*(c - a*c*x)^(7/2)) + (3*(1 - a*x)^((8 - n)/2)*(1 + a*x)^((2 + n)/2))/(8*a*(3 + n)*(5 + n)*(1 - n^2)*(c - a*c*x)^(7/2)) - (9*2^(-5/2 - n/2)*(1 - a*x)^(7/2)*(1 + a*x)^((2 + n)/2)*Hypergeometric2F1[(-1 + n)/2, (2 + n)/2, (4 + n)/2, (1 + a*x)/2])/(a*(1 + n)*(3 + n)*(5 + n)*(2 - n - n^2)*(c - a*c*x)^(7/2))}
{E^(n*ArcTanh[a*x])/(c - a*c*x)^(9/2), x, 8, ((1 - a*x)^((2 - n)/2)*(1 + a*x)^((2 + n)/2))/(a*(7 + n)*(c - a*c*x)^(9/2)) + (5*(1 - a*x)^((4 - n)/2)*(1 + a*x)^((2 + n)/2))/(2*a*(5 + n)*(7 + n)*(c - a*c*x)^(9/2)) + (15*(1 - a*x)^((6 - n)/2)*(1 + a*x)^((2 + n)/2))/(4*a*(3 + n)*(5 + n)*(7 + n)*(c - a*c*x)^(9/2)) + (15*(1 - a*x)^((8 - n)/2)*(1 + a*x)^((2 + n)/2))/(8*a*(5 + n)*(7 + n)*(3 + 4*n + n^2)*(c - a*c*x)^(9/2)) + (15*(1 - a*x)^((10 - n)/2)*(1 + a*x)^((2 + n)/2))/(16*a*(3 + n)*(5 + n)*(7 + n)*(1 - n^2)*(c - a*c*x)^(9/2)) - (45*2^(-7/2 - n/2)*(1 - a*x)^(9/2)*(1 + a*x)^((2 + n)/2)*Hypergeometric2F1[(-1 + n)/2, (2 + n)/2, (4 + n)/2, (1 + a*x)/2])/(a*(1 + n)*(3 + n)*(5 + n)*(7 + n)*(2 - n - n^2)*(c - a*c*x)^(9/2))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(n ArcTanh[a x]) (c-c a x)^p*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{x*E^ArcTanh[x]*(1 + x), x, 5, (-Sqrt[1 - x])*Sqrt[1 + x] - (1/3)*Sqrt[1 - x]*(1 + x)^(3/2) - (1/3)*Sqrt[1 - x]*(1 + x)^(5/2) + ArcSin[x]}
{E^ArcTanh[x]*(1 + x), x, 4, (-(3/2))*Sqrt[1 - x]*Sqrt[1 + x] - (1/2)*Sqrt[1 - x]*(1 + x)^(3/2) + (3*ArcSin[x])/2}

{x*E^ArcTanh[x]*(1 - x), x, 2, (-(1/3))*(1 - x)^(3/2)*(1 + x)^(3/2)}
{E^ArcTanh[x]*(1 - x), x, 4, (1/2)*x*Sqrt[1 - x^2] + ArcSin[x]/2}


{x*E^ArcTanh[x]*(1 + x)^2, x, 6, (-(15/8))*Sqrt[1 - x]*Sqrt[1 + x] - (5/8)*Sqrt[1 - x]*(1 + x)^(3/2) - (1/4)*Sqrt[1 - x]*(1 + x)^(5/2) - (1/4)*Sqrt[1 - x]*(1 + x)^(7/2) + (15*ArcSin[x])/8}
{E^ArcTanh[x]*(1 + x)^2, x, 5, (-(5/2))*Sqrt[1 - x]*Sqrt[1 + x] - (5/6)*Sqrt[1 - x]*(1 + x)^(3/2) - (1/3)*Sqrt[1 - x]*(1 + x)^(5/2) + (5*ArcSin[x])/2}

{x*E^ArcTanh[x]*(1 - x)^2, x, 6, (-(1/8))*Sqrt[1 - x]*Sqrt[1 + x] - (1/24)*(1 - x)^(3/2)*Sqrt[1 + x] + (1/12)*(1 - x)^(5/2)*Sqrt[1 + x] - (1/4)*(1 - x)^(5/2)*(1 + x)^(3/2) - ArcSin[x]/8}
{E^ArcTanh[x]*(1 - x)^2, x, 5, (1/2)*Sqrt[1 - x]*Sqrt[1 + x] + (1/6)*(1 - x)^(3/2)*Sqrt[1 + x] - (1/3)*(1 - x)^(5/2)*Sqrt[1 + x] + ArcSin[x]/2}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{x*E^ArcTanh[x]/(1 + x), x, 2, (-Sqrt[1 - x])*Sqrt[1 + x]}
{E^ArcTanh[x]/(1 + x), x, 2, ArcSin[x]}

{x*E^ArcTanh[x]/(1 - x), x, 4, 2*Sqrt[1 - x]*Sqrt[1 + x] + (1 + x)^(3/2)/Sqrt[1 - x] - 2*ArcSin[x]}
{E^ArcTanh[x]/(1 - x), x, 3, (2*Sqrt[1 + x])/Sqrt[1 - x] - ArcSin[x]}


{x*E^ArcTanh[x]/(1 + x)^2, x, 3, Sqrt[1 - x]/Sqrt[1 + x] + ArcSin[x]}
{E^ArcTanh[x]/(1 + x)^2, x, 2, -(Sqrt[1 - x]/Sqrt[1 + x])}

{x*E^ArcTanh[x]/(1 - x)^2, x, 4, -((2*Sqrt[1 + x])/Sqrt[1 - x]) + (1 + x)^(3/2)/(3*(1 - x)^(3/2)) + ArcSin[x]}
{E^ArcTanh[x]/(1 - x)^2, x, 2, (1 + x)^(3/2)/(3*(1 - x)^(3/2))}


(* ::Subsubsection::Closed:: *)
(*n/2>0*)


{x*E^ArcTanh[x]*(1 + x)^(3/2), x, 3, -8*Sqrt[1 - x] + (16/3)*(1 - x)^(3/2) - 2*(1 - x)^(5/2) + (2/7)*(1 - x)^(7/2)}
{E^ArcTanh[x]*(1 + x)^(3/2), x, 3, -8*Sqrt[1 - x] + (8/3)*(1 - x)^(3/2) - (2/5)*(1 - x)^(5/2)}

{x*E^ArcTanh[x]*(1 - x)^(3/2), x, 3, (-(4/3))*(1 + x)^(3/2) + (6/5)*(1 + x)^(5/2) - (2/7)*(1 + x)^(7/2)}
{E^ArcTanh[x]*(1 - x)^(3/2), x, 3, (4/3)*(1 + x)^(3/2) - (2/5)*(1 + x)^(5/2)}


{x*E^ArcTanh[x]*(1 + x)^(1/2), x, 3, -4*Sqrt[1 - x] + 2*(1 - x)^(3/2) - (2/5)*(1 - x)^(5/2)}
{E^ArcTanh[x]*(1 + x)^(1/2), x, 3, -4*Sqrt[1 - x] + (2/3)*(1 - x)^(3/2)}

{x*E^ArcTanh[x]*(1 - x)^(1/2), x, 3, (-(2/3))*(1 + x)^(3/2) + (2/5)*(1 + x)^(5/2)}
{E^ArcTanh[x]*(1 - x)^(1/2), x, 2, (2/3)*(1 + x)^(3/2)}


(* ::Subsubsection::Closed:: *)
(*n/2<0*)


{x*E^ArcTanh[x]/(1 + x)^(1/2), x, 3, -2*Sqrt[1 - x] + (2/3)*(1 - x)^(3/2)}
{E^ArcTanh[x]/(1 + x)^(1/2), x, 2, -2*Sqrt[1 - x]}

{x*E^ArcTanh[x]/(1 - x)^(1/2), x, 4, -2*Sqrt[1 + x] - (2/3)*(1 + x)^(3/2) + 2*Sqrt[2]*ArcTanh[Sqrt[1 + x]/Sqrt[2]]}
{E^ArcTanh[x]/(1 - x)^(1/2), x, 3, -2*Sqrt[1 + x] + 2*Sqrt[2]*ArcTanh[Sqrt[1 + x]/Sqrt[2]]}


{x*E^ArcTanh[x]/(1 + x)^(3/2), x, 3, -2*Sqrt[1 - x] + Sqrt[2]*ArcTanh[Sqrt[1 - x]/Sqrt[2]]}
{E^ArcTanh[x]/(1 + x)^(3/2), x, 2, (-Sqrt[2])*ArcTanh[Sqrt[1 - x]/Sqrt[2]]}

{x*E^ArcTanh[x]/(1 - x)^(3/2), x, 4, (5*Sqrt[1 + x])/2 + (1 + x)^(3/2)/(2*(1 - x)) - (5*ArcTanh[Sqrt[1 + x]/Sqrt[2]])/Sqrt[2]}
{E^ArcTanh[x]/(1 - x)^(3/2), x, 3, Sqrt[1 + x]/(1 - x) - ArcTanh[Sqrt[1 + x]/Sqrt[2]]/Sqrt[2]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(n ArcTanh[a x]) (c-c a x)^(p/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{E^ArcTanh[a*x]*x^m*Sqrt[c - a*c*x], x, 4, (2*x^(1 + m)*Sqrt[1 + a*x]*Sqrt[c - a*c*x])/((3 + 2*m)*Sqrt[1 - a*x]) + (2*x^m*Sqrt[1 + a*x]*Sqrt[c - a*c*x]*Hypergeometric2F1[1/2, -m, 3/2, 1 + a*x])/(a*(3 + 2*m)*(-(a*x))^m*Sqrt[1 - a*x])}

{E^ArcTanh[a*x]*x^2*Sqrt[c - a*c*x], x, 4, (2*(1 + a*x)^(3/2)*Sqrt[c - a*c*x])/(3*a^3*Sqrt[1 - a*x]) - (4*(1 + a*x)^(5/2)*Sqrt[c - a*c*x])/(5*a^3*Sqrt[1 - a*x]) + (2*(1 + a*x)^(7/2)*Sqrt[c - a*c*x])/(7*a^3*Sqrt[1 - a*x])}
{E^ArcTanh[a*x]*x*Sqrt[c - a*c*x], x, 4, (-2*(1 + a*x)^(3/2)*Sqrt[c - a*c*x])/(3*a^2*Sqrt[1 - a*x]) + (2*(1 + a*x)^(5/2)*Sqrt[c - a*c*x])/(5*a^2*Sqrt[1 - a*x])}
{E^ArcTanh[a*x]*Sqrt[c - a*c*x], x, 3, (2*(1 + a*x)^(3/2)*Sqrt[c - a*c*x])/(3*a*Sqrt[1 - a*x])}
{(E^ArcTanh[a*x]*Sqrt[c - a*c*x])/x, x, 4, (2*Sqrt[1 + a*x]*Sqrt[c - a*c*x])/Sqrt[1 - a*x] - (2*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 + a*x]])/Sqrt[1 - a*x]}
{(E^ArcTanh[a*x]*Sqrt[c - a*c*x])/x^2, x, 4, -((Sqrt[1 + a*x]*Sqrt[c - a*c*x])/(x*Sqrt[1 - a*x])) - (a*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 + a*x]])/Sqrt[1 - a*x]}


{E^(2*ArcTanh[a*x])*x^3*Sqrt[c - a*c*x], x, 4, (-4*Sqrt[c - a*c*x])/a^4 + (14*(1 - a*x)*Sqrt[c - a*c*x])/(3*a^4) - (18*(1 - a*x)^2*Sqrt[c - a*c*x])/(5*a^4) + (10*(1 - a*x)^3*Sqrt[c - a*c*x])/(7*a^4) - (2*(1 - a*x)^4*Sqrt[c - a*c*x])/(9*a^4)}
{E^(2*ArcTanh[a*x])*x^2*Sqrt[c - a*c*x], x, 4, (-4*Sqrt[c - a*c*x])/a^3 + (10*(1 - a*x)*Sqrt[c - a*c*x])/(3*a^3) - (8*(1 - a*x)^2*Sqrt[c - a*c*x])/(5*a^3) + (2*(1 - a*x)^3*Sqrt[c - a*c*x])/(7*a^3)}
{E^(2*ArcTanh[a*x])*x*Sqrt[c - a*c*x], x, 4, (-4*Sqrt[c - a*c*x])/a^2 + (2*(1 - a*x)*Sqrt[c - a*c*x])/a^2 - (2*(1 - a*x)^2*Sqrt[c - a*c*x])/(5*a^2)}
{E^(2*ArcTanh[a*x])*Sqrt[c - a*c*x], x, 4, (-4*Sqrt[c - a*c*x])/a + (2*(1 - a*x)*Sqrt[c - a*c*x])/(3*a)}
{(E^(2*ArcTanh[a*x])*Sqrt[c - a*c*x])/x, x, 4, -2*Sqrt[c - a*c*x] - (2*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]])/Sqrt[1 - a*x]}
{(E^(2*ArcTanh[a*x])*Sqrt[c - a*c*x])/x^2, x, 4, -(Sqrt[c - a*c*x]/x) - (3*a*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]])/Sqrt[1 - a*x]}
{(E^(2*ArcTanh[a*x])*Sqrt[c - a*c*x])/x^3, x, 5, -Sqrt[c - a*c*x]/(2*x^2) - (7*a*Sqrt[c - a*c*x])/(4*x) - (7*a^2*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]])/(4*Sqrt[1 - a*x])}
{(E^(2*ArcTanh[a*x])*Sqrt[c - a*c*x])/x^4, x, 6, -Sqrt[c - a*c*x]/(3*x^3) - (11*a*Sqrt[c - a*c*x])/(12*x^2) - (11*a^2*Sqrt[c - a*c*x])/(8*x) - (11*a^3*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]])/(8*Sqrt[1 - a*x])}
{(E^(2*ArcTanh[a*x])*Sqrt[c - a*c*x])/x^5, x, 7, -Sqrt[c - a*c*x]/(4*x^4) - (5*a*Sqrt[c - a*c*x])/(8*x^3) - (25*a^2*Sqrt[c - a*c*x])/(32*x^2) - (75*a^3*Sqrt[c - a*c*x])/(64*x) - (75*a^4*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]])/(64*Sqrt[1 - a*x])}


{E^(3*ArcTanh[a*x])*x^3*Sqrt[c - a*c*x], x, 8, (-4*Sqrt[1 + a*x]*Sqrt[c - a*c*x])/(a^4*Sqrt[1 - a*x]) - (316*(1 + a*x)^(3/2)*Sqrt[c - a*c*x])/(315*a^4*Sqrt[1 - a*x]) - (52*x*(1 + a*x)^(3/2)*Sqrt[c - a*c*x])/(105*a^3*Sqrt[1 - a*x]) - (8*x^2*(1 + a*x)^(3/2)*Sqrt[c - a*c*x])/(21*a^2*Sqrt[1 - a*x]) - (2*x^3*(1 + a*x)^(3/2)*Sqrt[c - a*c*x])/(9*a*Sqrt[1 - a*x]) + (4*Sqrt[2]*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 + a*x]/Sqrt[2]])/(a^4*Sqrt[1 - a*x])}
{E^(3*ArcTanh[a*x])*x^2*Sqrt[c - a*c*x], x, 7, (-4*Sqrt[1 + a*x]*Sqrt[c - a*c*x])/(a^3*Sqrt[1 - a*x]) - (2*(1 + a*x)^(3/2)*Sqrt[c - a*c*x])/(3*a^3*Sqrt[1 - a*x]) - (2*(1 + a*x)^(5/2)*Sqrt[c - a*c*x])/(7*a^3*Sqrt[1 - a*x]) - (2*x*(1 + a*x)^(5/2)*Sqrt[c - a*c*x])/(7*a^2*Sqrt[1 - a*x]) + (4*Sqrt[2]*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 + a*x]/Sqrt[2]])/(a^3*Sqrt[1 - a*x])}
{E^(3*ArcTanh[a*x])*x*Sqrt[c - a*c*x], x, 6, (-4*Sqrt[1 + a*x]*Sqrt[c - a*c*x])/(a^2*Sqrt[1 - a*x]) - (2*(1 + a*x)^(3/2)*Sqrt[c - a*c*x])/(3*a^2*Sqrt[1 - a*x]) - (2*(1 + a*x)^(5/2)*Sqrt[c - a*c*x])/(5*a^2*Sqrt[1 - a*x]) + (4*Sqrt[2]*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 + a*x]/Sqrt[2]])/(a^2*Sqrt[1 - a*x])}
{E^(3*ArcTanh[a*x])*Sqrt[c - a*c*x], x, 5, (-4*Sqrt[1 + a*x]*Sqrt[c - a*c*x])/(a*Sqrt[1 - a*x]) - (2*(1 + a*x)^(3/2)*Sqrt[c - a*c*x])/(3*a*Sqrt[1 - a*x]) + (4*Sqrt[2]*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 + a*x]/Sqrt[2]])/(a*Sqrt[1 - a*x])}
{(E^(3*ArcTanh[a*x])*Sqrt[c - a*c*x])/x, x, 6, (-2*Sqrt[1 + a*x]*Sqrt[c - a*c*x])/Sqrt[1 - a*x] - (2*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 + a*x]])/Sqrt[1 - a*x] + (4*Sqrt[2]*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 + a*x]/Sqrt[2]])/Sqrt[1 - a*x]}
{(E^(3*ArcTanh[a*x])*Sqrt[c - a*c*x])/x^2, x, 7, (a*Sqrt[1 + a*x]*Sqrt[c - a*c*x])/Sqrt[1 - a*x] - ((1 + a*x)^(3/2)*Sqrt[c - a*c*x])/(x*Sqrt[1 - a*x]) - (5*a*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 + a*x]])/Sqrt[1 - a*x] + (4*Sqrt[2]*a*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 + a*x]/Sqrt[2]])/Sqrt[1 - a*x]}
{(E^(3*ArcTanh[a*x])*Sqrt[c - a*c*x])/x^3, x, 7, (-7*a*Sqrt[1 + a*x]*Sqrt[c - a*c*x])/(4*x*Sqrt[1 - a*x]) - ((1 + a*x)^(3/2)*Sqrt[c - a*c*x])/(2*x^2*Sqrt[1 - a*x]) - (23*a^2*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 + a*x]])/(4*Sqrt[1 - a*x]) + (4*Sqrt[2]*a^2*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 + a*x]/Sqrt[2]])/Sqrt[1 - a*x]}
{(E^(3*ArcTanh[a*x])*Sqrt[c - a*c*x])/x^4, x, 8, (-3*a*Sqrt[1 + a*x]*Sqrt[c - a*c*x])/(4*x^2*Sqrt[1 - a*x]) - (19*a^2*Sqrt[1 + a*x]*Sqrt[c - a*c*x])/(8*x*Sqrt[1 - a*x]) - ((1 + a*x)^(3/2)*Sqrt[c - a*c*x])/(3*x^3*Sqrt[1 - a*x]) - (45*a^3*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 + a*x]])/(8*Sqrt[1 - a*x]) + (4*Sqrt[2]*a^3*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 + a*x]/Sqrt[2]])/Sqrt[1 - a*x]}
{(E^(3*ArcTanh[a*x])*Sqrt[c - a*c*x])/x^5, x, 9, (-11*a*Sqrt[1 + a*x]*Sqrt[c - a*c*x])/(24*x^3*Sqrt[1 - a*x]) - (107*a^2*Sqrt[1 + a*x]*Sqrt[c - a*c*x])/(96*x^2*Sqrt[1 - a*x]) - (149*a^3*Sqrt[1 + a*x]*Sqrt[c - a*c*x])/(64*x*Sqrt[1 - a*x]) - ((1 + a*x)^(3/2)*Sqrt[c - a*c*x])/(4*x^4*Sqrt[1 - a*x]) - (363*a^4*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 + a*x]])/(64*Sqrt[1 - a*x]) + (4*Sqrt[2]*a^4*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 + a*x]/Sqrt[2]])/Sqrt[1 - a*x]}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(x^m*Sqrt[c - a*c*x])/E^ArcTanh[a*x], x, 4, (-2*x^(1 + m)*Sqrt[1 + a*x]*Sqrt[c - a*c*x])/((3 + 2*m)*Sqrt[1 - a*x]) + (2*(5 + 4*m)*x^m*Sqrt[1 + a*x]*Sqrt[c - a*c*x]*Hypergeometric2F1[1/2, -m, 3/2, 1 + a*x])/(a*(3 + 2*m)*(-(a*x))^m*Sqrt[1 - a*x])}

{(x^2*Sqrt[c - a*c*x])/E^ArcTanh[a*x], x, 4, (4*Sqrt[1 + a*x]*Sqrt[c - a*c*x])/(a^3*Sqrt[1 - a*x]) - (10*(1 + a*x)^(3/2)*Sqrt[c - a*c*x])/(3*a^3*Sqrt[1 - a*x]) + (8*(1 + a*x)^(5/2)*Sqrt[c - a*c*x])/(5*a^3*Sqrt[1 - a*x]) - (2*(1 + a*x)^(7/2)*Sqrt[c - a*c*x])/(7*a^3*Sqrt[1 - a*x])}
{(x*Sqrt[c - a*c*x])/E^ArcTanh[a*x], x, 4, (-4*Sqrt[1 + a*x]*Sqrt[c - a*c*x])/(a^2*Sqrt[1 - a*x]) + (2*(1 + a*x)^(3/2)*Sqrt[c - a*c*x])/(a^2*Sqrt[1 - a*x]) - (2*(1 + a*x)^(5/2)*Sqrt[c - a*c*x])/(5*a^2*Sqrt[1 - a*x])}
{Sqrt[c - a*c*x]/E^ArcTanh[a*x], x, 4, (4*Sqrt[1 + a*x]*Sqrt[c - a*c*x])/(a*Sqrt[1 - a*x]) - (2*(1 + a*x)^(3/2)*Sqrt[c - a*c*x])/(3*a*Sqrt[1 - a*x])}
{Sqrt[c - a*c*x]/(E^ArcTanh[a*x]*x), x, 4, (-2*Sqrt[1 + a*x]*Sqrt[c - a*c*x])/Sqrt[1 - a*x] - (2*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 + a*x]])/Sqrt[1 - a*x]}
{Sqrt[c - a*c*x]/(E^ArcTanh[a*x]*x^2), x, 4, -((Sqrt[1 + a*x]*Sqrt[c - a*c*x])/(x*Sqrt[1 - a*x])) + (3*a*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 + a*x]])/Sqrt[1 - a*x]}


{(x^3*Sqrt[c - a*c*x])/E^(2*ArcTanh[a*x]), x, 8, (-4*Sqrt[c - a*c*x])/a^4 - (316*(1 - a*x)*Sqrt[c - a*c*x])/(315*a^4) + (52*x*(1 - a*x)*Sqrt[c - a*c*x])/(105*a^3) - (8*x^2*(1 - a*x)*Sqrt[c - a*c*x])/(21*a^2) + (2*x^3*(1 - a*x)*Sqrt[c - a*c*x])/(9*a) + (4*Sqrt[2]*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/(a^4*Sqrt[1 - a*x])}
{(x^2*Sqrt[c - a*c*x])/E^(2*ArcTanh[a*x]), x, 7, (4*Sqrt[c - a*c*x])/a^3 + (2*(1 - a*x)*Sqrt[c - a*c*x])/(3*a^3) + (2*(1 - a*x)^2*Sqrt[c - a*c*x])/(7*a^3) - (2*x*(1 - a*x)^2*Sqrt[c - a*c*x])/(7*a^2) - (4*Sqrt[2]*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/(a^3*Sqrt[1 - a*x])}
{(x*Sqrt[c - a*c*x])/E^(2*ArcTanh[a*x]), x, 6, (-4*Sqrt[c - a*c*x])/a^2 - (2*(1 - a*x)*Sqrt[c - a*c*x])/(3*a^2) - (2*(1 - a*x)^2*Sqrt[c - a*c*x])/(5*a^2) + (4*Sqrt[2]*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/(a^2*Sqrt[1 - a*x])}
{Sqrt[c - a*c*x]/E^(2*ArcTanh[a*x]), x, 5, (4*Sqrt[c - a*c*x])/a + (2*(1 - a*x)*Sqrt[c - a*c*x])/(3*a) - (4*Sqrt[2]*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/(a*Sqrt[1 - a*x])}
{Sqrt[c - a*c*x]/(E^(2*ArcTanh[a*x])*x), x, 6, -2*Sqrt[c - a*c*x] - (2*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]])/Sqrt[1 - a*x] + (4*Sqrt[2]*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/Sqrt[1 - a*x]}
{Sqrt[c - a*c*x]/(E^(2*ArcTanh[a*x])*x^2), x, 7, -(a*Sqrt[c - a*c*x]) - ((1 - a*x)*Sqrt[c - a*c*x])/x + (5*a*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]])/Sqrt[1 - a*x] - (4*Sqrt[2]*a*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/Sqrt[1 - a*x]}
{Sqrt[c - a*c*x]/(E^(2*ArcTanh[a*x])*x^3), x, 7, (7*a*Sqrt[c - a*c*x])/(4*x) - ((1 - a*x)*Sqrt[c - a*c*x])/(2*x^2) - (23*a^2*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]])/(4*Sqrt[1 - a*x]) + (4*Sqrt[2]*a^2*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/Sqrt[1 - a*x]}
{Sqrt[c - a*c*x]/(E^(2*ArcTanh[a*x])*x^4), x, 8, (3*a*Sqrt[c - a*c*x])/(4*x^2) - (19*a^2*Sqrt[c - a*c*x])/(8*x) - ((1 - a*x)*Sqrt[c - a*c*x])/(3*x^3) + (45*a^3*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]])/(8*Sqrt[1 - a*x]) - (4*Sqrt[2]*a^3*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/Sqrt[1 - a*x]}
{Sqrt[c - a*c*x]/(E^(2*ArcTanh[a*x])*x^5), x, 9, (11*a*Sqrt[c - a*c*x])/(24*x^3) - (107*a^2*Sqrt[c - a*c*x])/(96*x^2) + (149*a^3*Sqrt[c - a*c*x])/(64*x) - ((1 - a*x)*Sqrt[c - a*c*x])/(4*x^4) - (363*a^4*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]])/(64*Sqrt[1 - a*x]) + (4*Sqrt[2]*a^4*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/Sqrt[1 - a*x]}


{(x^3*Sqrt[c - a*c*x])/E^(3*ArcTanh[a*x]), x, 4, (8*Sqrt[c - a*c*x])/(a^4*Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (32*Sqrt[1 + a*x]*Sqrt[c - a*c*x])/(a^4*Sqrt[1 - a*x]) - (50*(1 + a*x)^(3/2)*Sqrt[c - a*c*x])/(3*a^4*Sqrt[1 - a*x]) + (38*(1 + a*x)^(5/2)*Sqrt[c - a*c*x])/(5*a^4*Sqrt[1 - a*x]) - (2*(1 + a*x)^(7/2)*Sqrt[c - a*c*x])/(a^4*Sqrt[1 - a*x]) + (2*(1 + a*x)^(9/2)*Sqrt[c - a*c*x])/(9*a^4*Sqrt[1 - a*x])}
{(x^2*Sqrt[c - a*c*x])/E^(3*ArcTanh[a*x]), x, 4, (-8*Sqrt[c - a*c*x])/(a^3*Sqrt[1 - a*x]*Sqrt[1 + a*x]) - (24*Sqrt[1 + a*x]*Sqrt[c - a*c*x])/(a^3*Sqrt[1 - a*x]) + (26*(1 + a*x)^(3/2)*Sqrt[c - a*c*x])/(3*a^3*Sqrt[1 - a*x]) - (12*(1 + a*x)^(5/2)*Sqrt[c - a*c*x])/(5*a^3*Sqrt[1 - a*x]) + (2*(1 + a*x)^(7/2)*Sqrt[c - a*c*x])/(7*a^3*Sqrt[1 - a*x])}
{(x*Sqrt[c - a*c*x])/E^(3*ArcTanh[a*x]), x, 4, (8*Sqrt[c - a*c*x])/(a^2*Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (16*Sqrt[1 + a*x]*Sqrt[c - a*c*x])/(a^2*Sqrt[1 - a*x]) - (10*(1 + a*x)^(3/2)*Sqrt[c - a*c*x])/(3*a^2*Sqrt[1 - a*x]) + (2*(1 + a*x)^(5/2)*Sqrt[c - a*c*x])/(5*a^2*Sqrt[1 - a*x])}
{Sqrt[c - a*c*x]/E^(3*ArcTanh[a*x]), x, 4, (-8*Sqrt[c - a*c*x])/(a*Sqrt[1 - a*x]*Sqrt[1 + a*x]) - (8*Sqrt[1 + a*x]*Sqrt[c - a*c*x])/(a*Sqrt[1 - a*x]) + (2*(1 + a*x)^(3/2)*Sqrt[c - a*c*x])/(3*a*Sqrt[1 - a*x])}
{Sqrt[c - a*c*x]/(E^(3*ArcTanh[a*x])*x), x, 6, (8*Sqrt[c - a*c*x])/(Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (2*Sqrt[1 + a*x]*Sqrt[c - a*c*x])/Sqrt[1 - a*x] - (2*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 + a*x]])/Sqrt[1 - a*x]}
{Sqrt[c - a*c*x]/(E^(3*ArcTanh[a*x])*x^2), x, 5, (-9*a*Sqrt[c - a*c*x])/(Sqrt[1 - a*x]*Sqrt[1 + a*x]) - Sqrt[c - a*c*x]/(x*Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (7*a*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 + a*x]])/Sqrt[1 - a*x]}
{Sqrt[c - a*c*x]/(E^(3*ArcTanh[a*x])*x^3), x, 6, (47*a^2*Sqrt[c - a*c*x])/(4*Sqrt[1 - a*x]*Sqrt[1 + a*x]) - Sqrt[c - a*c*x]/(2*x^2*Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (13*a*Sqrt[c - a*c*x])/(4*x*Sqrt[1 - a*x]*Sqrt[1 + a*x]) - (47*a^2*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 + a*x]])/(4*Sqrt[1 - a*x])}
{Sqrt[c - a*c*x]/(E^(3*ArcTanh[a*x])*x^4), x, 7, -Sqrt[c - a*c*x]/(3*x^3*Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (19*a*Sqrt[c - a*c*x])/(12*x^2*Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (119*a^2*Sqrt[c - a*c*x])/(12*x*Sqrt[1 - a*x]*Sqrt[1 + a*x]) - (119*a^2*Sqrt[1 + a*x]*Sqrt[c - a*c*x])/(8*x*Sqrt[1 - a*x]) + (119*a^3*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 + a*x]])/(8*Sqrt[1 - a*x])}
{Sqrt[c - a*c*x]/(E^(3*ArcTanh[a*x])*x^5), x, 8, -Sqrt[c - a*c*x]/(4*x^4*Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (25*a*Sqrt[c - a*c*x])/(24*x^3*Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (223*a^2*Sqrt[c - a*c*x])/(24*x^2*Sqrt[1 - a*x]*Sqrt[1 + a*x]) - (1115*a^2*Sqrt[1 + a*x]*Sqrt[c - a*c*x])/(96*x^2*Sqrt[1 - a*x]) + (1115*a^3*Sqrt[1 + a*x]*Sqrt[c - a*c*x])/(64*x*Sqrt[1 - a*x]) - (1115*a^4*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 + a*x]])/(64*Sqrt[1 - a*x])}


(* ::Subtitle::Closed:: *)
(*Integration problems of the form u E^(n ArcTanh[a x]) (c-c/(a x))^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form E^(n ArcTanh[a x]) (c-c/(a x))^p*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{E^ArcTanh[a*x]*(c - c/(a*x))^p, x, 3, ((c - c/(a*x))^p*x*AppellF1[1 - p, 1/2 - p, -1/2, 2 - p, a*x, -(a*x)])/((1 - p)*(1 - a*x)^p)}

{E^ArcTanh[a*x]*(c - c/(a*x))^4, x, 9, (-5*c^4*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(2*a) - (2*c^4*(1 - a*x)^(3/2)*Sqrt[1 + a*x])/(3*a^2*x) + (c^4*(1 - a*x)^(5/2)*Sqrt[1 + a*x])/(2*a^3*x^2) - (c^4*(1 - a*x)^(7/2)*Sqrt[1 + a*x])/(3*a^4*x^3) - (3*c^4*ArcSin[a*x])/a - (c^4*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/a}
{E^ArcTanh[a*x]*(c - c/(a*x))^3, x, 8, (-5*c^3*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(2*a) - (c^3*(1 - a*x)^(3/2)*Sqrt[1 + a*x])/(a^2*x) + (c^3*(1 - a*x)^(5/2)*Sqrt[1 + a*x])/(2*a^3*x^2) - (2*c^3*ArcSin[a*x])/a + (c^3*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/a}
{E^ArcTanh[a*x]*(c - c/(a*x))^2, x, 8, (-2*c^2*Sqrt[1 - a*x]*Sqrt[1 + a*x])/a - (c^2*(1 - a*x)^(3/2)*Sqrt[1 + a*x])/(a^2*x) - (c^2*ArcSin[a*x])/a + (2*c^2*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/a}
{E^ArcTanh[a*x]*(c - c/(a*x)), x, 4, -((c*Sqrt[1 - a*x]*Sqrt[1 + a*x])/a) + (2*c*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/a}
{E^ArcTanh[a*x]/(c - c/(a*x)), x, 5, (-2*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(a*c) - (1 + a*x)^(3/2)/(a*c*Sqrt[1 - a*x]) + (2*ArcSin[a*x])/(a*c)}
{E^ArcTanh[a*x]/(c - c/(a*x))^2, x, 7, (-3*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(a*c^2) + (1 + a*x)^(3/2)/(3*a*c^2*(1 - a*x)^(3/2)) - (2*(1 + a*x)^(3/2))/(a*c^2*Sqrt[1 - a*x]) + (3*ArcSin[a*x])/(a*c^2)}
{E^ArcTanh[a*x]/(c - c/(a*x))^3, x, 7, (-2*a^2*x^3*Sqrt[1 + a*x])/(5*c^3*(1 - a*x)^(5/2)) + (13*a*x^2*Sqrt[1 + a*x])/(15*c^3*(1 - a*x)^(3/2)) - (68*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(15*a*c^3) - (2*Sqrt[1 + a*x]*(13 + 17*a*x))/(15*a*c^3*Sqrt[1 - a*x]) + (4*ArcSin[a*x])/(a*c^3)}
{E^ArcTanh[a*x]/(c - c/(a*x))^4, x, 8, (2*a^3*x^4*Sqrt[1 + a*x])/(7*c^4*(1 - a*x)^(7/2)) - (17*a^2*x^3*Sqrt[1 + a*x])/(35*c^4*(1 - a*x)^(5/2)) + (113*a*x^2*Sqrt[1 + a*x])/(105*c^4*(1 - a*x)^(3/2)) - (598*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(105*a*c^4) - (Sqrt[1 + a*x]*(226 + 299*a*x))/(105*a*c^4*Sqrt[1 - a*x]) + (5*ArcSin[a*x])/(a*c^4)}


{E^(2*ArcTanh[a*x])*(c - c/(a*x))^p, x, 9, (-2*(c - c/(a*x))^p*x)/p - ((2 - p)*(c - c/(a*x))^p*(a*x)^p*(1 - a*x)*Hypergeometric2F1[p, 1 + p, 2 + p, 1 - a*x])/(a*p*(1 + p)), -(((1 - p)*(c - c/(a*x))^p)/(a*p)) - (c - c/(a*x))^p*x - ((1 - p)*(c - c/(a*x))^(1 + p)*Hypergeometric2F1[1, 1 + p, 2 + p, 1 - 1/(a*x)])/(a*c*(1 + p)) - (c*(c - c/(a*x))^(-1 + p)*(-((a - 1/x)*x))^(1 - p)*Hypergeometric2F1[1 - p, 1 - p, 2 - p, a*x])/(a*(1 - p))}

{E^(2*ArcTanh[a*x])*(c - c/(a*x))^5, x, 4, c^5/(4*a^5*x^4) - c^5/(a^4*x^3) + c^5/(a^3*x^2) + (2*c^5)/(a^2*x) - c^5*x + (3*c^5*Log[x])/a}
{E^(2*ArcTanh[a*x])*(c - c/(a*x))^4, x, 4, -c^4/(3*a^4*x^3) + c^4/(a^3*x^2) - c^4*x + (2*c^4*Log[x])/a}
{E^(2*ArcTanh[a*x])*(c - c/(a*x))^3, x, 4, c^3/(2*a^3*x^2) - c^3/(a^2*x) - c^3*x + (c^3*Log[x])/a}
{E^(2*ArcTanh[a*x])*(c - c/(a*x))^2, x, 3, -((c^2*(1 + a*x)^2)/(a^2*x))}
{E^(2*ArcTanh[a*x])*(c - c/(a*x)), x, 4, -(c*x) - (c*Log[x])/a}
{E^(2*ArcTanh[a*x])/(c - c/(a*x)), x, 4, -(x/c) - 2/(a*c*(1 - a*x)) - (3*Log[1 - a*x])/(a*c)}
{E^(2*ArcTanh[a*x])/(c - c/(a*x))^2, x, 4, -(x/c^2) + 1/(a*c^2*(1 - a*x)^2) - 5/(a*c^2*(1 - a*x)) - (4*Log[1 - a*x])/(a*c^2)}
{E^(2*ArcTanh[a*x])/(c - c/(a*x))^3, x, 4, -(x/c^3) - 2/(3*a*c^3*(1 - a*x)^3) + 7/(2*a*c^3*(1 - a*x)^2) - 9/(a*c^3*(1 - a*x)) - (5*Log[1 - a*x])/(a*c^3)}
{E^(2*ArcTanh[a*x])/(c - c/(a*x))^4, x, 4, -(x/c^4) + 1/(2*a*c^4*(1 - a*x)^4) - 3/(a*c^4*(1 - a*x)^3) + 8/(a*c^4*(1 - a*x)^2) - 14/(a*c^4*(1 - a*x)) - (6*Log[1 - a*x])/(a*c^4)}


{E^(3*ArcTanh[a*x])*(c - c/(a*x))^4, x, 9, (c^4*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(2*a) + (c^4*Sqrt[1 - a*x]*(1 + a*x)^(3/2))/(a^2*x) + (c^4*(1 - a*x)^(3/2)*(1 + a*x)^(3/2))/(6*a^3*x^2) - (c^4*(1 - a*x)^(5/2)*(1 + a*x)^(3/2))/(3*a^4*x^3) + (c^4*ArcSin[a*x])/a - (3*c^4*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/a}
{E^(3*ArcTanh[a*x])*(c - c/(a*x))^3, x, 6, (3*c^3*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(2*a) + (c^3*(1 - a*x)^(3/2)*(1 + a*x)^(3/2))/(2*a^3*x^2) - (3*c^3*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/a}
{E^(3*ArcTanh[a*x])*(c - c/(a*x))^2, x, 8, (2*c^2*Sqrt[1 - a*x]*Sqrt[1 + a*x])/a - (c^2*Sqrt[1 - a*x]*(1 + a*x)^(3/2))/(a^2*x) - (c^2*ArcSin[a*x])/a - (2*c^2*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/a}
{E^(3*ArcTanh[a*x])*(c - c/(a*x)), x, 6, (c*Sqrt[1 - a*x]*Sqrt[1 + a*x])/a - (2*c*ArcSin[a*x])/a + (2*c*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/a}
{E^(3*ArcTanh[a*x])/(c - c/(a*x)), x, 6, (4*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(a*c) + (8*(1 + a*x)^(3/2))/(3*a*c*Sqrt[1 - a*x]) - (1 + a*x)^(5/2)/(3*a*c*(1 - a*x)^(3/2)) - (4*ArcSin[a*x])/(a*c)}
{E^(3*ArcTanh[a*x])/(c - c/(a*x))^2, x, 8, (5*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(a*c^2) + (10*(1 + a*x)^(3/2))/(3*a*c^2*Sqrt[1 - a*x]) + (1 + a*x)^(5/2)/(5*a*c^2*(1 - a*x)^(5/2)) - (2*(1 + a*x)^(5/2))/(3*a*c^2*(1 - a*x)^(3/2)) - (5*ArcSin[a*x])/(a*c^2)}
{E^(3*ArcTanh[a*x])/(c - c/(a*x))^3, x, 8, (130*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(21*a*c^3) - (2*a^2*x^3*(1 + a*x)^(3/2))/(7*c^3*(1 - a*x)^(7/2)) + (3*a*x^2*(1 + a*x)^(3/2))/(7*c^3*(1 - a*x)^(5/2)) - (4*Sqrt[1 + a*x]*(1 + 2*a*x)^2)/(21*a*c^3*(1 - a*x)^(3/2)) + (2*Sqrt[1 + a*x]*(12 + 13*a*x))/(7*a*c^3*Sqrt[1 - a*x]) - (6*ArcSin[a*x])/(a*c^3)}
{E^(3*ArcTanh[a*x])/(c - c/(a*x))^4, x, 9, (713164*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(98595*a*c^4) + (2*a^3*x^4*(1 + a*x)^(3/2))/(9*c^4*(1 - a*x)^(9/2)) - (19*a^2*x^3*(1 + a*x)^(3/2))/(63*c^4*(1 - a*x)^(7/2)) + (17*a*x^2*(1 + a*x)^(3/2))/(35*c^4*(1 - a*x)^(5/2)) - (2*Sqrt[1 + a*x]*(102 + 211*a*x)^2)/(98595*a*c^4*(1 - a*x)^(3/2)) + (Sqrt[1 + a*x]*(1252 + 1361*a*x))/(315*a*c^4*Sqrt[1 - a*x]) - (7*ArcSin[a*x])/(a*c^4)}


{E^(4*ArcTanh[a*x])*(c - c/(a*x))^p, x, 11, -((c*(c - c/(a*x))^(-1 + p))/(a*(1 - p))) - (c*(2 - p)*(c - c/(a*x))^(-1 + p))/(a*(1 - p)) + ((2 - p)*(c - c/(a*x))^p)/(a*p) + c*(c - c/(a*x))^(-1 + p)*x + ((2 - p)*(c - c/(a*x))^(1 + p)*Hypergeometric2F1[1, 1 + p, 2 + p, 1 - 1/(a*x)])/(a*c*(1 + p)) + (2*c^2*(c - c/(a*x))^(-2 + p)*(-((a - 1/x)*x))^(2 - p)*Hypergeometric2F1[2 - p, 2 - p, 3 - p, a*x])/(a*(2 - p))}

{E^(4*ArcTanh[a*x])*(c - c/(a*x))^5, x, 4, c^5/(4*a^5*x^4) - c^5/(3*a^4*x^3) - c^5/(a^3*x^2) + (2*c^5)/(a^2*x) + c^5*x - (c^5*Log[x])/a}
{E^(4*ArcTanh[a*x])*(c - c/(a*x))^4, x, 4, -c^4/(3*a^4*x^3) + (2*c^4)/(a^2*x) + c^4*x}
{E^(4*ArcTanh[a*x])*(c - c/(a*x))^3, x, 4, c^3/(2*a^3*x^2) + c^3/(a^2*x) + c^3*x + (c^3*Log[x])/a}
{E^(4*ArcTanh[a*x])*(c - c/(a*x))^2, x, 4, -(c^2/(a^2*x)) + c^2*x + (2*c^2*Log[x])/a}
{E^(4*ArcTanh[a*x])*(c - c/(a*x)), x, 4, c*x - (c*Log[x])/a + (4*c*Log[1 - a*x])/a}
{E^(4*ArcTanh[a*x])/(c - c/(a*x)), x, 4, x/c - 2/(a*c*(1 - a*x)^2) + 8/(a*c*(1 - a*x)) + (5*Log[1 - a*x])/(a*c)}
{E^(4*ArcTanh[a*x])/(c - c/(a*x))^2, x, 4, x/c^2 + 4/(3*a*c^2*(1 - a*x)^3) - 6/(a*c^2*(1 - a*x)^2) + 13/(a*c^2*(1 - a*x)) + (6*Log[1 - a*x])/(a*c^2)}
{E^(4*ArcTanh[a*x])/(c - c/(a*x))^3, x, 4, x/c^3 - 1/(a*c^3*(1 - a*x)^4) + 16/(3*a*c^3*(1 - a*x)^3) - 25/(2*a*c^3*(1 - a*x)^2) + 19/(a*c^3*(1 - a*x)) + (7*Log[1 - a*x])/(a*c^3)}
{E^(4*ArcTanh[a*x])/(c - c/(a*x))^4, x, 4, x/c^4 + 4/(5*a*c^4*(1 - a*x)^5) - 5/(a*c^4*(1 - a*x)^4) + 41/(3*a*c^4*(1 - a*x)^3) - 22/(a*c^4*(1 - a*x)^2) + 26/(a*c^4*(1 - a*x)) + (8*Log[1 - a*x])/(a*c^4)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(c - c/(a*x))^p/E^ArcTanh[a*x], x, 3, ((c - c/(a*x))^p*x*AppellF1[1 - p, -1/2 - p, 1/2, 2 - p, a*x, -(a*x)])/((1 - p)*(1 - a*x)^p)}

{(c - c/(a*x))^4/E^ArcTanh[a*x], x, 10, (-15*c^4*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(2*a) - (20*c^4*(1 - a*x)^(3/2)*Sqrt[1 + a*x])/(3*a) - (31*c^4*(1 - a*x)^(5/2)*Sqrt[1 + a*x])/(6*a^2*x) + (7*c^4*(1 - a*x)^(7/2)*Sqrt[1 + a*x])/(6*a^3*x^2) - (c^4*(1 - a*x)^(9/2)*Sqrt[1 + a*x])/(3*a^4*x^3) + (5*c^4*ArcSin[a*x])/a + (25*c^4*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/a}
{(c - c/(a*x))^3/E^ArcTanh[a*x], x, 9, (-5*c^3*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(2*a) - (3*c^3*(1 - a*x)^(3/2)*Sqrt[1 + a*x])/a - (5*c^3*(1 - a*x)^(5/2)*Sqrt[1 + a*x])/(2*a^2*x) + (c^3*(1 - a*x)^(7/2)*Sqrt[1 + a*x])/(2*a^3*x^2) + (4*c^3*ArcSin[a*x])/a + (13*c^3*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/a}
{(c - c/(a*x))^2/E^ArcTanh[a*x], x, 8, -((c^2*(1 - a*x)^(3/2)*Sqrt[1 + a*x])/a) - (c^2*(1 - a*x)^(5/2)*Sqrt[1 + a*x])/(a^2*x) + (3*c^2*ArcSin[a*x])/a + (6*c^2*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/a}
{(c - c/(a*x))/E^ArcTanh[a*x], x, 6, (c*Sqrt[1 - a*x]*Sqrt[1 + a*x])/a + (2*c*ArcSin[a*x])/a + (2*c*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/a}
{1/(E^ArcTanh[a*x]*(c - c/(a*x))), x, 3, (Sqrt[1 - a*x]*Sqrt[1 + a*x])/(a*c)}
{1/(E^ArcTanh[a*x]*(c - c/(a*x))^2), x, 6, Sqrt[1 + a*x]/(a*c^2*Sqrt[1 - a*x]) + (Sqrt[1 - a*x]*Sqrt[1 + a*x])/(a*c^2) - ArcSin[a*x]/(a*c^2)}
{1/(E^ArcTanh[a*x]*(c - c/(a*x))^3), x, 7, (a*x^2*Sqrt[1 + a*x])/(c^3*(1 - a*x)^(3/2)) + (4*Sqrt[1 + a*x])/(a*c^3*Sqrt[1 - a*x]) - (2*(1 + a*x)^(3/2))/(3*a*c^3*(1 - a*x)^(3/2)) - (2*ArcSin[a*x])/(a*c^3)}
{1/(E^ArcTanh[a*x]*(c - c/(a*x))^4), x, 8, -((a^2*x^3*Sqrt[1 + a*x])/(c^4*(1 - a*x)^(5/2))) + (6*Sqrt[1 + a*x])/(a*c^4*Sqrt[1 - a*x]) + (3*(1 + a*x)^(3/2))/(5*a*c^4*(1 - a*x)^(5/2)) - (9*(1 + a*x)^(3/2))/(5*a*c^4*(1 - a*x)^(3/2)) - (3*ArcSin[a*x])/(a*c^4)}


{(c - c/(a*x))^p/E^(2*ArcTanh[a*x]), x, 10, ((c - c/(a*x))^p*x*AppellF1[1 - p, -1 - p, 1, 2 - p, a*x, -(a*x)])/((1 - p)*(1 - a*x)^p), ((c - c/(a*x))^(1 + p)*x)/(c*p) - ((1 + p)*(c - c/(a*x))^(1 + p)*x)/(c*p) - ((c - c/(a*x))^(1 + p)*x*(1 - a*x)^(-1 - p)*AppellF1[-p, 1, -1 - p, 1 - p, (-a)*x, a*x])/(c*p) + ((c - c/(a*x))^(1 + p)*Hypergeometric2F1[1, 1 + p, 2 + p, 1 - 1/(a*x)])/(a*c)}

{(c - c/(a*x))^4/E^(2*ArcTanh[a*x]), x, 4, -c^4/(3*a^4*x^3) + (3*c^4)/(a^3*x^2) - (16*c^4)/(a^2*x) - c^4*x - (26*c^4*Log[x])/a + (32*c^4*Log[1 + a*x])/a}
{(c - c/(a*x))^3/E^(2*ArcTanh[a*x]), x, 4, c^3/(2*a^3*x^2) - (5*c^3)/(a^2*x) - c^3*x - (11*c^3*Log[x])/a + (16*c^3*Log[1 + a*x])/a}
{(c - c/(a*x))^2/E^(2*ArcTanh[a*x]), x, 4, -(c^2/(a^2*x)) - c^2*x - (4*c^2*Log[x])/a + (8*c^2*Log[1 + a*x])/a}
{(c - c/(a*x))/E^(2*ArcTanh[a*x]), x, 4, -(c*x) - (c*Log[x])/a + (4*c*Log[1 + a*x])/a}
{1/(E^(2*ArcTanh[a*x])*(c - c/(a*x))), x, 4, -(x/c) + Log[1 + a*x]/(a*c)}
{1/(E^(2*ArcTanh[a*x])*(c - c/(a*x))^2), x, 5, -(x/c^2) + ArcTanh[a*x]/(a*c^2)}
{1/(E^(2*ArcTanh[a*x])*(c - c/(a*x))^3), x, 4, -(x/c^3) - 1/(2*a*c^3*(1 - a*x)) - (5*Log[1 - a*x])/(4*a*c^3) + Log[1 + a*x]/(4*a*c^3)}
{1/(E^(2*ArcTanh[a*x])*(c - c/(a*x))^4), x, 4, -(x/c^4) + 1/(4*a*c^4*(1 - a*x)^2) - 7/(4*a*c^4*(1 - a*x)) - (17*Log[1 - a*x])/(8*a*c^4) + Log[1 + a*x]/(8*a*c^4)}


{(c - c/(a*x))^4/E^(3*ArcTanh[a*x]), x, 11, (-133*c^4*(1 - a*x)^(5/2))/(3*a*Sqrt[1 + a*x]) - (59*c^4*(1 - a*x)^(7/2))/(6*a^2*x*Sqrt[1 + a*x]) + (3*c^4*(1 - a*x)^(9/2))/(2*a^3*x^2*Sqrt[1 + a*x]) - (c^4*(1 - a*x)^(11/2))/(3*a^4*x^3*Sqrt[1 + a*x]) - (105*c^4*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(2*a) - (98*c^4*(1 - a*x)^(3/2)*Sqrt[1 + a*x])/(3*a) - (7*c^4*ArcSin[a*x])/a + (91*c^4*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/a}
{(c - c/(a*x))^3/E^(3*ArcTanh[a*x]), x, 10, (-17*c^3*(1 - a*x)^(5/2))/(a*Sqrt[1 + a*x]) - (7*c^3*(1 - a*x)^(7/2))/(2*a^2*x*Sqrt[1 + a*x]) + (c^3*(1 - a*x)^(9/2))/(2*a^3*x^2*Sqrt[1 + a*x]) - (45*c^3*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(2*a) - (13*c^3*(1 - a*x)^(3/2)*Sqrt[1 + a*x])/a - (6*c^3*ArcSin[a*x])/a + (33*c^3*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/a}
{(c - c/(a*x))^2/E^(3*ArcTanh[a*x]), x, 10, (-6*c^2*(1 - a*x)^(5/2))/(a*Sqrt[1 + a*x]) - (c^2*(1 - a*x)^(7/2))/(a^2*x*Sqrt[1 + a*x]) - (10*c^2*Sqrt[1 - a*x]*Sqrt[1 + a*x])/a - (5*c^2*(1 - a*x)^(3/2)*Sqrt[1 + a*x])/a - (5*c^2*ArcSin[a*x])/a + (10*c^2*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/a}
{(c - c/(a*x))/E^(3*ArcTanh[a*x]), x, 8, (-2*c*(1 - a*x)^(5/2))/(a*Sqrt[1 + a*x]) - (5*c*Sqrt[1 - a*x]*Sqrt[1 + a*x])/a - (2*c*(1 - a*x)^(3/2)*Sqrt[1 + a*x])/a - (4*c*ArcSin[a*x])/a + (2*c*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/a}
{1/(E^(3*ArcTanh[a*x])*(c - c/(a*x))), x, 5, -((1 - a*x)^(3/2)/(a*c*Sqrt[1 + a*x])) - (2*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(a*c) - (2*ArcSin[a*x])/(a*c)}
{1/(E^(3*ArcTanh[a*x])*(c - c/(a*x))^2), x, 6, -(Sqrt[1 - a*x]/(a*c^2*Sqrt[1 + a*x])) - (Sqrt[1 - a*x]*Sqrt[1 + a*x])/(a*c^2) - ArcSin[a*x]/(a*c^2)}
{1/(E^(3*ArcTanh[a*x])*(c - c/(a*x))^3), x, 5, -2/(a*c^3*Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (a*x^2)/(c^3*Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{1/(E^(3*ArcTanh[a*x])*(c - c/(a*x))^4), x, 7, (4*a*x^2)/(3*c^4*(1 - a*x)^(3/2)*Sqrt[1 + a*x]) - (a^2*x^3)/(c^4*(1 - a*x)^(3/2)*Sqrt[1 + a*x]) - (8 + 3*a*x)/(3*a*c^4*Sqrt[1 - a*x]*Sqrt[1 + a*x]) + ArcSin[a*x]/(a*c^4)}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{(c - c/(a*x))^p/E^(2*p*ArcTanh[a*x]), x, 3, ((c - c/(a*x))^p*x*AppellF1[1 - p, -2*p, p, 2 - p, a*x, -(a*x)])/((1 - p)*(1 - a*x)^p)}
{E^(2*p*ArcTanh[a*x])*(c - c/(a*x))^p, x, 3, ((c - c/(a*x))^p*(-(a*x))^p*(1 + a*x)^(1 + p)*Hypergeometric2F1[p, 1 + p, 2 + p, 1 + a*x])/(a*(1 + p)*(1 - a*x)^p)}


{E^(n*ArcTanh[a*x])*(c - c/(a*x))^p, x, 3, ((c - c/(a*x))^p*x*AppellF1[1 - p, (n - 2*p)/2, -n/2, 2 - p, a*x, -(a*x)])/((1 - p)*(1 - a*x)^p)}

{E^(n*ArcTanh[a*x])*(c - c/(a*x)), x, 3, (2^(1 + n/2)*c*(1 - a*x)^(2 - n/2)*AppellF1[2 - n/2, 1, -n/2, 3 - n/2, 1 - a*x, (1 - a*x)/2])/(a*(4 - n))}
{E^(n*ArcTanh[a*x]), x, 2, (2^(1 - n/2)*(1 + a*x)^((2 + n)/2)*Hypergeometric2F1[n/2, (2 + n)/2, (4 + n)/2, (1 + a*x)/2])/(a*(2 + n))}
{E^(n*ArcTanh[a*x])/(c - c/(a*x)), x, 4, -((1 + a*x)^((2 + n)/2)/(a*c*n*(1 - a*x)^(n/2))) + (2^(1 - n/2)*(1 + n)*(1 + a*x)^((2 + n)/2)*Hypergeometric2F1[n/2, (2 + n)/2, (4 + n)/2, (1 + a*x)/2])/(a*c*n*(2 + n))}
{E^(n*ArcTanh[a*x])/(c - c/(a*x))^2, x, 6, ((3 + n)*(1 - a*x)^(-1 - n/2)*(1 + a*x)^((2 + n)/2))/(a*c^2*(2 + n)) - (x*(1 - a*x)^(-1 - n/2)*(1 + a*x)^((2 + n)/2))/c^2 - ((2 + n)*(1 + a*x)^((2 + n)/2))/(a*c^2*n*(1 - a*x)^(n/2)) + (2^(1 - n/2)*(1 + a*x)^((2 + n)/2)*Hypergeometric2F1[n/2, (2 + n)/2, (4 + n)/2, (1 + a*x)/2])/(a*c^2*n)}


(* ::Subsection::Closed:: *)
(*Integrands of the form E^(n ArcTanh[a x]) (c-c/(a x))^(p/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{E^ArcTanh[a*x]*(c - c/(a*x))^(9/2), x, 8, -((227*a^4*(c - c/(a*x))^(9/2)*x^5*Sqrt[1 + a*x])/(105*(1 - a*x)^(9/2))) - (2*a^3*(c - c/(a*x))^(9/2)*x^4*(27 - 227*a*x)*Sqrt[1 + a*x])/(105*(1 - a*x)^(9/2)) - (10*a^2*(c - c/(a*x))^(9/2)*x^3*Sqrt[1 + a*x])/(21*(1 - a*x)^(5/2)) + (2*a*(c - c/(a*x))^(9/2)*x^2*Sqrt[1 + a*x])/(5*(1 - a*x)^(3/2)) - (2*(c - c/(a*x))^(9/2)*x*Sqrt[1 + a*x])/(7*Sqrt[1 - a*x]) - (7*a^(7/2)*(c - c/(a*x))^(9/2)*x^(9/2)*ArcSinh[Sqrt[a]*Sqrt[x]])/(1 - a*x)^(9/2)}
{E^ArcTanh[a*x]*(c - c/(a*x))^(7/2), x, 7, (31*a^3*(c - c/(a*x))^(7/2)*x^4*Sqrt[1 + a*x])/(15*(1 - a*x)^(7/2)) + (2*a*(c - c/(a*x))^(7/2)*x^2*Sqrt[1 + a*x])/(3*(1 - a*x)^(3/2)) - (2*(c - c/(a*x))^(7/2)*x*Sqrt[1 + a*x])/(5*Sqrt[1 - a*x]) - (2*a^2*(c - c/(a*x))^(7/2)*x^3*Sqrt[1 + a*x]*(9 + 31*a*x))/(15*(1 - a*x)^(7/2)) + (5*a^(5/2)*(c - c/(a*x))^(7/2)*x^(7/2)*ArcSinh[Sqrt[a]*Sqrt[x]])/(1 - a*x)^(7/2)}
{E^ArcTanh[a*x]*(c - c/(a*x))^(5/2), x, 6, -((3*a^2*(c - c/(a*x))^(5/2)*x^3*Sqrt[1 + a*x])/(1 - a*x)^(5/2)) - (2*(c - c/(a*x))^(5/2)*x*(1 + a*x)^(3/2))/(3*(1 - a*x)^(5/2)) + (4*a*(c - c/(a*x))^(5/2)*x^2*(1 + a*x)^(3/2))/(1 - a*x)^(5/2) - (3*a^(3/2)*(c - c/(a*x))^(5/2)*x^(5/2)*ArcSinh[Sqrt[a]*Sqrt[x]])/(1 - a*x)^(5/2)}
{E^ArcTanh[a*x]*(c - c/(a*x))^(3/2), x, 5, (a*(c - c/(a*x))^(3/2)*x^2*Sqrt[1 + a*x])/(1 - a*x)^(3/2) - (2*(c - c/(a*x))^(3/2)*x*(1 + a*x)^(3/2))/(1 - a*x)^(3/2) + (Sqrt[a]*(c - c/(a*x))^(3/2)*x^(3/2)*ArcSinh[Sqrt[a]*Sqrt[x]])/(1 - a*x)^(3/2)}
{E^ArcTanh[a*x]*Sqrt[c - c/(a*x)], x, 4, (Sqrt[c - c/(a*x)]*x*Sqrt[1 + a*x])/Sqrt[1 - a*x] + (Sqrt[c - c/(a*x)]*Sqrt[x]*ArcSinh[Sqrt[a]*Sqrt[x]])/(Sqrt[a]*Sqrt[1 - a*x])}
{E^ArcTanh[a*x]/Sqrt[c - c/(a*x)], x, 6, -((Sqrt[1 - a*x]*Sqrt[1 + a*x])/(a*Sqrt[c - c/(a*x)])) - (3*Sqrt[1 - a*x]*ArcSinh[Sqrt[a]*Sqrt[x]])/(a^(3/2)*Sqrt[c - c/(a*x)]*Sqrt[x]) + (2*Sqrt[2]*Sqrt[1 - a*x]*ArcTanh[(Sqrt[2]*Sqrt[a]*Sqrt[x])/Sqrt[1 + a*x]])/(a^(3/2)*Sqrt[c - c/(a*x)]*Sqrt[x])}
{E^ArcTanh[a*x]/(c - c/(a*x))^(3/2), x, 7, (Sqrt[1 - a*x]*Sqrt[1 + a*x])/(a*(c - c/(a*x))^(3/2)) + (2*(1 - a*x)^(3/2)*Sqrt[1 + a*x])/(a^2*(c - c/(a*x))^(3/2)*x) + (5*(1 - a*x)^(3/2)*ArcSinh[Sqrt[a]*Sqrt[x]])/(a^(5/2)*(c - c/(a*x))^(3/2)*x^(3/2)) - (7*(1 - a*x)^(3/2)*ArcTanh[(Sqrt[2]*Sqrt[a]*Sqrt[x])/Sqrt[1 + a*x]])/(Sqrt[2]*a^(5/2)*(c - c/(a*x))^(3/2)*x^(3/2))}
{E^ArcTanh[a*x]/(c - c/(a*x))^(5/2), x, 8, (Sqrt[1 - a*x]*Sqrt[1 + a*x])/(2*a*(c - c/(a*x))^(5/2)) - (11*(1 - a*x)^(3/2)*Sqrt[1 + a*x])/(8*a^2*(c - c/(a*x))^(5/2)*x) - (23*(1 - a*x)^(5/2)*Sqrt[1 + a*x])/(8*a^3*(c - c/(a*x))^(5/2)*x^2) - (7*(1 - a*x)^(5/2)*ArcSinh[Sqrt[a]*Sqrt[x]])/(a^(7/2)*(c - c/(a*x))^(5/2)*x^(5/2)) + (79*(1 - a*x)^(5/2)*ArcTanh[(Sqrt[2]*Sqrt[a]*Sqrt[x])/Sqrt[1 + a*x]])/(8*Sqrt[2]*a^(7/2)*(c - c/(a*x))^(5/2)*x^(5/2))}


{E^(2*ArcTanh[a*x])*(c - c/(a*x))^(9/2), x, 7, -((5*c^4*Sqrt[c - c/(a*x)])/a) - (5*c^3*(c - c/(a*x))^(3/2))/(3*a) - (c^2*(c - c/(a*x))^(5/2))/a - (5*c*(c - c/(a*x))^(7/2))/(7*a) - (c - c/(a*x))^(9/2)*x + (5*c^(9/2)*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/a}
{E^(2*ArcTanh[a*x])*(c - c/(a*x))^(7/2), x, 7, -((3*c^3*Sqrt[c - c/(a*x)])/a) - (c^2*(c - c/(a*x))^(3/2))/a - (3*c*(c - c/(a*x))^(5/2))/(5*a) - (c - c/(a*x))^(7/2)*x + (3*c^(7/2)*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/a}
{E^(2*ArcTanh[a*x])*(c - c/(a*x))^(5/2), x, 7, -((c^2*Sqrt[c - c/(a*x)])/a) - (c*(c - c/(a*x))^(3/2))/(3*a) - (c - c/(a*x))^(5/2)*x + (c^(5/2)*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/a}
{E^(2*ArcTanh[a*x])*(c - c/(a*x))^(3/2), x, 6, (c*Sqrt[c - c/(a*x)])/a - (c - c/(a*x))^(3/2)*x - (c^(3/2)*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/a}
{E^(2*ArcTanh[a*x])*Sqrt[c - c/(a*x)], x, 5, (-Sqrt[c - c/(a*x)])*x - (3*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/a}
{E^(2*ArcTanh[a*x])/Sqrt[c - c/(a*x)], x, 6, 5/(a*Sqrt[c - c/(a*x)]) - x/Sqrt[c - c/(a*x)] - (5*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/(a*Sqrt[c])}
{E^(2*ArcTanh[a*x])/(c - c/(a*x))^(3/2), x, 7, 7/(3*a*(c - c/(a*x))^(3/2)) + 7/(a*c*Sqrt[c - c/(a*x)]) - x/(c - c/(a*x))^(3/2) - (7*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/(a*c^(3/2))}
{E^(2*ArcTanh[a*x])/(c - c/(a*x))^(5/2), x, 8, 9/(5*a*(c - c/(a*x))^(5/2)) + 3/(a*c*(c - c/(a*x))^(3/2)) + 9/(a*c^2*Sqrt[c - c/(a*x)]) - x/(c - c/(a*x))^(5/2) - (9*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/(a*c^(5/2))}
{E^(2*ArcTanh[a*x])/(c - c/(a*x))^(7/2), x, 9, 11/(7*a*(c - c/(a*x))^(7/2)) + 11/(5*a*c*(c - c/(a*x))^(5/2)) + 11/(3*a*c^2*(c - c/(a*x))^(3/2)) + 11/(a*c^3*Sqrt[c - c/(a*x)]) - x/(c - c/(a*x))^(7/2) - (11*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/(a*c^(7/2))}


{E^(3*ArcTanh[a*x])*(c - c/(a*x))^(9/2), x, 8, (61*a^4*(c - c/(a*x))^(9/2)*x^5*Sqrt[1 + a*x])/(315*(1 - a*x)^(9/2)) + (2*a^2*(c - c/(a*x))^(9/2)*x^3*(9 - 17*a*x)^2*Sqrt[1 + a*x])/(315*(1 - a*x)^(9/2)) + (6*a*(c - c/(a*x))^(9/2)*x^2*(1 + a*x)^(3/2))/(35*(1 - a*x)^(5/2)) - (2*(c - c/(a*x))^(9/2)*x*(1 + a*x)^(3/2))/(7*(1 - a*x)^(3/2)) - (2*a^3*(c - c/(a*x))^(9/2)*x^4*Sqrt[1 + a*x]*(35 + 61*a*x))/(35*(1 - a*x)^(9/2)) + (3*a^(7/2)*(c - c/(a*x))^(9/2)*x^(9/2)*ArcSinh[Sqrt[a]*Sqrt[x]])/(1 - a*x)^(9/2)}
{E^(3*ArcTanh[a*x])*(c - c/(a*x))^(7/2), x, 7, -((a^3*(c - c/(a*x))^(7/2)*x^4*Sqrt[1 + a*x])/(1 - a*x)^(7/2)) + (2*a^2*(c - c/(a*x))^(7/2)*x^3*(1 + a*x)^(3/2))/(3*(1 - a*x)^(7/2)) - (2*(c - c/(a*x))^(7/2)*x*(1 + a*x)^(5/2))/(5*(1 - a*x)^(7/2)) + (4*a*(c - c/(a*x))^(7/2)*x^2*(1 + a*x)^(5/2))/(3*(1 - a*x)^(7/2)) - (a^(5/2)*(c - c/(a*x))^(7/2)*x^(7/2)*ArcSinh[Sqrt[a]*Sqrt[x]])/(1 - a*x)^(7/2)}
{E^(3*ArcTanh[a*x])*(c - c/(a*x))^(5/2), x, 6, -((a^2*(c - c/(a*x))^(5/2)*x^3*Sqrt[1 + a*x])/(1 - a*x)^(5/2)) + (2*a*(c - c/(a*x))^(5/2)*x^2*(1 + a*x)^(3/2))/(3*(1 - a*x)^(5/2)) - (2*(c - c/(a*x))^(5/2)*x*(1 + a*x)^(5/2))/(3*(1 - a*x)^(5/2)) - (a^(3/2)*(c - c/(a*x))^(5/2)*x^(5/2)*ArcSinh[Sqrt[a]*Sqrt[x]])/(1 - a*x)^(5/2)}
{E^(3*ArcTanh[a*x])*(c - c/(a*x))^(3/2), x, 5, (3*a*(c - c/(a*x))^(3/2)*x^2*Sqrt[1 + a*x])/(1 - a*x)^(3/2) - (2*(c - c/(a*x))^(3/2)*x*(1 + a*x)^(3/2))/(1 - a*x)^(3/2) + (3*Sqrt[a]*(c - c/(a*x))^(3/2)*x^(3/2)*ArcSinh[Sqrt[a]*Sqrt[x]])/(1 - a*x)^(3/2)}
{E^(3*ArcTanh[a*x])*Sqrt[c - c/(a*x)], x, 6, -((Sqrt[c - c/(a*x)]*x*Sqrt[1 + a*x])/Sqrt[1 - a*x]) - (5*Sqrt[c - c/(a*x)]*Sqrt[x]*ArcSinh[Sqrt[a]*Sqrt[x]])/(Sqrt[a]*Sqrt[1 - a*x]) + (4*Sqrt[2]*Sqrt[c - c/(a*x)]*Sqrt[x]*ArcTanh[(Sqrt[2]*Sqrt[a]*Sqrt[x])/Sqrt[1 + a*x]])/(Sqrt[a]*Sqrt[1 - a*x])}
{E^(3*ArcTanh[a*x])/Sqrt[c - c/(a*x)], x, 7, (2*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(a*Sqrt[c - c/(a*x)]) + (1 + a*x)^(3/2)/(a*Sqrt[c - c/(a*x)]*Sqrt[1 - a*x]) + (7*Sqrt[1 - a*x]*ArcSinh[Sqrt[a]*Sqrt[x]])/(a^(3/2)*Sqrt[c - c/(a*x)]*Sqrt[x]) - (5*Sqrt[2]*Sqrt[1 - a*x]*ArcTanh[(Sqrt[2]*Sqrt[a]*Sqrt[x])/Sqrt[1 + a*x]])/(a^(3/2)*Sqrt[c - c/(a*x)]*Sqrt[x])}
{E^(3*ArcTanh[a*x])/(c - c/(a*x))^(3/2), x, 8, -((21*(1 - a*x)^(3/2)*Sqrt[1 + a*x])/(8*a^2*(c - c/(a*x))^(3/2)*x)) + (1 + a*x)^(3/2)/(2*a*(c - c/(a*x))^(3/2)*Sqrt[1 - a*x]) - (9*Sqrt[1 - a*x]*(1 + a*x)^(3/2))/(8*a^2*(c - c/(a*x))^(3/2)*x) - (9*(1 - a*x)^(3/2)*ArcSinh[Sqrt[a]*Sqrt[x]])/(a^(5/2)*(c - c/(a*x))^(3/2)*x^(3/2)) + (51*(1 - a*x)^(3/2)*ArcTanh[(Sqrt[2]*Sqrt[a]*Sqrt[x])/Sqrt[1 + a*x]])/(4*Sqrt[2]*a^(5/2)*(c - c/(a*x))^(3/2)*x^(3/2))}
{E^(3*ArcTanh[a*x])/(c - c/(a*x))^(5/2), x, 9, (103*(1 - a*x)^(5/2)*Sqrt[1 + a*x])/(32*a^3*(c - c/(a*x))^(5/2)*x^2) + (1 + a*x)^(3/2)/(3*a*(c - c/(a*x))^(5/2)*Sqrt[1 - a*x]) - (13*Sqrt[1 - a*x]*(1 + a*x)^(3/2))/(24*a^2*(c - c/(a*x))^(5/2)*x) + (43*(1 - a*x)^(3/2)*(1 + a*x)^(3/2))/(32*a^3*(c - c/(a*x))^(5/2)*x^2) + (11*(1 - a*x)^(5/2)*ArcSinh[Sqrt[a]*Sqrt[x]])/(a^(7/2)*(c - c/(a*x))^(5/2)*x^(5/2)) - (249*(1 - a*x)^(5/2)*ArcTanh[(Sqrt[2]*Sqrt[a]*Sqrt[x])/Sqrt[1 + a*x]])/(16*Sqrt[2]*a^(7/2)*(c - c/(a*x))^(5/2)*x^(5/2))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(c - c/(a*x))^(9/2)/E^ArcTanh[a*x], x, 8, (225*a^3*(c - c/(a*x))^(9/2)*x^4*Sqrt[1 + a*x])/(7*(1 - a*x)^(9/2)) - (a^2*(c - c/(a*x))^(9/2)*x^3*(521 - 385*a*x)*Sqrt[1 + a*x])/(105*(1 - a*x)^(9/2)) + (17*a*(c - c/(a*x))^(9/2)*x^2*Sqrt[1 + a*x])/(35*(1 - a*x)^(5/2)) + (5*(c - c/(a*x))^(9/2)*x*Sqrt[1 + a*x])/(7*(1 - a*x)^(3/2)) - ((c - c/(a*x))^(9/2)*x*Sqrt[1 + a*x])/Sqrt[1 - a*x] + (11*a^(7/2)*(c - c/(a*x))^(9/2)*x^(9/2)*ArcSinh[Sqrt[a]*Sqrt[x]])/(1 - a*x)^(9/2)}
{(c - c/(a*x))^(7/2)/E^ArcTanh[a*x], x, 7, -((13*a^2*(c - c/(a*x))^(7/2)*x^3*Sqrt[1 + a*x])/(1 - a*x)^(7/2)) + (a*(c - c/(a*x))^(7/2)*x^2*(7 - 15*a*x)*Sqrt[1 + a*x])/(5*(1 - a*x)^(7/2)) + (3*(c - c/(a*x))^(7/2)*x*Sqrt[1 + a*x])/(5*(1 - a*x)^(3/2)) - ((c - c/(a*x))^(7/2)*x*Sqrt[1 + a*x])/Sqrt[1 - a*x] - (9*a^(5/2)*(c - c/(a*x))^(7/2)*x^(7/2)*ArcSinh[Sqrt[a]*Sqrt[x]])/(1 - a*x)^(7/2)}
{(c - c/(a*x))^(5/2)/E^ArcTanh[a*x], x, 6, (3*a*(c - c/(a*x))^(5/2)*x^2*Sqrt[1 + a*x])/(1 - a*x)^(5/2) - ((c - c/(a*x))^(5/2)*x*Sqrt[1 + a*x])/Sqrt[1 - a*x] + ((c - c/(a*x))^(5/2)*x*Sqrt[1 + a*x]*(1 + 7*a*x))/(3*(1 - a*x)^(5/2)) + (7*a^(3/2)*(c - c/(a*x))^(5/2)*x^(5/2)*ArcSinh[Sqrt[a]*Sqrt[x]])/(1 - a*x)^(5/2)}
{(c - c/(a*x))^(3/2)/E^ArcTanh[a*x], x, 5, -((2*(c - c/(a*x))^(3/2)*x*Sqrt[1 + a*x])/(1 - a*x)^(3/2)) + (a*(c - c/(a*x))^(3/2)*x^2*Sqrt[1 + a*x])/(1 - a*x)^(3/2) - (5*Sqrt[a]*(c - c/(a*x))^(3/2)*x^(3/2)*ArcSinh[Sqrt[a]*Sqrt[x]])/(1 - a*x)^(3/2)}
{Sqrt[c - c/(a*x)]/E^ArcTanh[a*x], x, 4, -((Sqrt[c - c/(a*x)]*x*Sqrt[1 + a*x])/Sqrt[1 - a*x]) + (3*Sqrt[c - c/(a*x)]*Sqrt[x]*ArcSinh[Sqrt[a]*Sqrt[x]])/(Sqrt[a]*Sqrt[1 - a*x])}
{1/(E^ArcTanh[a*x]*Sqrt[c - c/(a*x)]), x, 4, (Sqrt[1 - a*x]*Sqrt[1 + a*x])/(a*Sqrt[c - c/(a*x)]) - (Sqrt[1 - a*x]*ArcSinh[Sqrt[a]*Sqrt[x]])/(a^(3/2)*Sqrt[c - c/(a*x)]*Sqrt[x])}
{1/(E^ArcTanh[a*x]*(c - c/(a*x))^(3/2)), x, 7, -(((1 - a*x)^(3/2)*Sqrt[1 + a*x])/(a^2*(c - c/(a*x))^(3/2)*x)) - ((1 - a*x)^(3/2)*ArcSinh[Sqrt[a]*Sqrt[x]])/(a^(5/2)*(c - c/(a*x))^(3/2)*x^(3/2)) + (Sqrt[2]*(1 - a*x)^(3/2)*ArcTanh[(Sqrt[2]*Sqrt[a]*Sqrt[x])/Sqrt[1 + a*x]])/(a^(5/2)*(c - c/(a*x))^(3/2)*x^(3/2))}
{1/(E^ArcTanh[a*x]*(c - c/(a*x))^(5/2)), x, 8, ((1 - a*x)^(3/2)*Sqrt[1 + a*x])/(2*a*(c - c/(a*x))^(5/2)) + (3*(1 - a*x)^(5/2)*Sqrt[1 + a*x])/(2*a^3*(c - c/(a*x))^(5/2)*x^2) + ((1 - a*x)^(5/2)*Sqrt[1 + a*x])/(2*a^2*(c - c/(a*x))^(5/2)*x) + (3*(1 - a*x)^(5/2)*ArcSinh[Sqrt[a]*Sqrt[x]])/(a^(7/2)*(c - c/(a*x))^(5/2)*x^(5/2)) - (9*(1 - a*x)^(5/2)*ArcTanh[(Sqrt[2]*Sqrt[a]*Sqrt[x])/Sqrt[1 + a*x]])/(2*Sqrt[2]*a^(7/2)*(c - c/(a*x))^(5/2)*x^(5/2))}
{1/(E^ArcTanh[a*x]*(c - c/(a*x))^(7/2)), x, 9, ((1 - a*x)^(3/2)*Sqrt[1 + a*x])/(4*a*(c - c/(a*x))^(7/2)) - (11*(1 - a*x)^(5/2)*Sqrt[1 + a*x])/(16*a^2*(c - c/(a*x))^(7/2)*x) - (35*(1 - a*x)^(7/2)*Sqrt[1 + a*x])/(16*a^4*(c - c/(a*x))^(7/2)*x^3) - (15*(1 - a*x)^(7/2)*Sqrt[1 + a*x])/(16*a^3*(c - c/(a*x))^(7/2)*x^2) - (5*(1 - a*x)^(7/2)*ArcSinh[Sqrt[a]*Sqrt[x]])/(a^(9/2)*(c - c/(a*x))^(7/2)*x^(7/2)) + (115*(1 - a*x)^(7/2)*ArcTanh[(Sqrt[2]*Sqrt[a]*Sqrt[x])/Sqrt[1 + a*x]])/(16*Sqrt[2]*a^(9/2)*(c - c/(a*x))^(7/2)*x^(7/2))}


{(c - c/(a*x))^(9/2)/E^(2*ArcTanh[a*x]), x, 9, (52*c^4*Sqrt[c - c/(a*x)])/a + (22*c^3*(c - c/(a*x))^(3/2))/(3*a) + (8*c^2*(c - c/(a*x))^(5/2))/(5*a) + (2*c*(c - c/(a*x))^(7/2))/(7*a) - c^4*Sqrt[c - c/(a*x)]*x + (13*c^(9/2)*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/a - (64*Sqrt[2]*c^(9/2)*ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])])/a}
{(c - c/(a*x))^(7/2)/E^(2*ArcTanh[a*x]), x, 9, (22*c^3*Sqrt[c - c/(a*x)])/a + (8*c^2*(c - c/(a*x))^(3/2))/(3*a) + (2*c*(c - c/(a*x))^(5/2))/(5*a) - c^3*Sqrt[c - c/(a*x)]*x + (11*c^(7/2)*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/a - (32*Sqrt[2]*c^(7/2)*ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])])/a}
{(c - c/(a*x))^(5/2)/E^(2*ArcTanh[a*x]), x, 9, (8*c^2*Sqrt[c - c/(a*x)])/a + (2*c*(c - c/(a*x))^(3/2))/(3*a) - c^2*Sqrt[c - c/(a*x)]*x + (9*c^(5/2)*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/a - (16*Sqrt[2]*c^(5/2)*ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])])/a}
{(c - c/(a*x))^(3/2)/E^(2*ArcTanh[a*x]), x, 9, (2*c*Sqrt[c - c/(a*x)])/a - c*Sqrt[c - c/(a*x)]*x + (7*c^(3/2)*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/a - (8*Sqrt[2]*c^(3/2)*ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])])/a}
{Sqrt[c - c/(a*x)]/E^(2*ArcTanh[a*x]), x, 9, (-Sqrt[c - c/(a*x)])*x + (5*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/a - (4*Sqrt[2]*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])])/a}
{1/(E^(2*ArcTanh[a*x])*Sqrt[c - c/(a*x)]), x, 9, -((Sqrt[c - c/(a*x)]*x)/c) + (3*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/(a*Sqrt[c]) - (2*Sqrt[2]*ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])])/(a*Sqrt[c])}
{1/(E^(2*ArcTanh[a*x])*(c - c/(a*x))^(3/2)), x, 7, -((Sqrt[c - c/(a*x)]*x)/c^2) + ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]]/(a*c^(3/2)) - (Sqrt[2]*ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])])/(a*c^(3/2))}
{1/(E^(2*ArcTanh[a*x])*(c - c/(a*x))^(5/2)), x, 9, 1/(a*c^2*Sqrt[c - c/(a*x)]) - (Sqrt[c - c/(a*x)]*x)/c^3 - ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]]/(a*c^(5/2)) - ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])]/(Sqrt[2]*a*c^(5/2))}
{1/(E^(2*ArcTanh[a*x])*(c - c/(a*x))^(7/2)), x, 9, 1/(3*a*c^2*(c - c/(a*x))^(3/2)) + 5/(2*a*c^3*Sqrt[c - c/(a*x)]) - (Sqrt[c - c/(a*x)]*x)/c^4 - (3*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/(a*c^(7/2)) - ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])]/(2*Sqrt[2]*a*c^(7/2))}
{1/(E^(2*ArcTanh[a*x])*(c - c/(a*x))^(9/2)), x, 9, 1/(5*a*c^2*(c - c/(a*x))^(5/2)) + 5/(6*a*c^3*(c - c/(a*x))^(3/2)) + 17/(4*a*c^4*Sqrt[c - c/(a*x)]) - (Sqrt[c - c/(a*x)]*x)/c^5 - (5*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/(a*c^(9/2)) - ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])]/(4*Sqrt[2]*a*c^(9/2))}


{(c - c/(a*x))^(9/2)/E^(3*ArcTanh[a*x]), x, 9, (1950*a^4*(c - c/(a*x))^(9/2)*x^5)/(7*(1 - a*x)^(9/2)*Sqrt[1 + a*x]) + (5*a^3*(c - c/(a*x))^(9/2)*x^4*(109 - 21*a*x))/(7*(1 - a*x)^(9/2)*Sqrt[1 + a*x]) - (55*a^2*(c - c/(a*x))^(9/2)*x^3)/(7*(1 - a*x)^(5/2)*Sqrt[1 + a*x]) + (5*a*(c - c/(a*x))^(9/2)*x^2)/(7*(1 - a*x)^(3/2)*Sqrt[1 + a*x]) + (5*(c - c/(a*x))^(9/2)*x)/(7*Sqrt[1 - a*x]*Sqrt[1 + a*x]) - ((c - c/(a*x))^(9/2)*x*Sqrt[1 - a*x])/Sqrt[1 + a*x] - (15*a^(7/2)*(c - c/(a*x))^(9/2)*x^(9/2)*ArcSinh[Sqrt[a]*Sqrt[x]])/(1 - a*x)^(9/2)}
{(c - c/(a*x))^(7/2)/E^(3*ArcTanh[a*x]), x, 8, -((622*a^3*(c - c/(a*x))^(7/2)*x^4)/(5*(1 - a*x)^(7/2)*Sqrt[1 + a*x])) - (a^2*(c - c/(a*x))^(7/2)*x^3*(427 - 195*a*x))/(15*(1 - a*x)^(7/2)*Sqrt[1 + a*x]) + (29*a*(c - c/(a*x))^(7/2)*x^2)/(15*(1 - a*x)^(3/2)*Sqrt[1 + a*x]) + (3*(c - c/(a*x))^(7/2)*x)/(5*Sqrt[1 - a*x]*Sqrt[1 + a*x]) - ((c - c/(a*x))^(7/2)*x*Sqrt[1 - a*x])/Sqrt[1 + a*x] + (13*a^(5/2)*(c - c/(a*x))^(7/2)*x^(7/2)*ArcSinh[Sqrt[a]*Sqrt[x]])/(1 - a*x)^(7/2)}
{(c - c/(a*x))^(5/2)/E^(3*ArcTanh[a*x]), x, 7, (58*a^2*(c - c/(a*x))^(5/2)*x^3)/((1 - a*x)^(5/2)*Sqrt[1 + a*x]) + (a*(c - c/(a*x))^(5/2)*x^2*(25 - 33*a*x))/(3*(1 - a*x)^(5/2)*Sqrt[1 + a*x]) + ((c - c/(a*x))^(5/2)*x)/(3*Sqrt[1 - a*x]*Sqrt[1 + a*x]) - ((c - c/(a*x))^(5/2)*x*Sqrt[1 - a*x])/Sqrt[1 + a*x] - (11*a^(3/2)*(c - c/(a*x))^(5/2)*x^(5/2)*ArcSinh[Sqrt[a]*Sqrt[x]])/(1 - a*x)^(5/2)}
{(c - c/(a*x))^(3/2)/E^(3*ArcTanh[a*x]), x, 6, -((30*a*(c - c/(a*x))^(3/2)*x^2)/((1 - a*x)^(3/2)*Sqrt[1 + a*x])) - ((c - c/(a*x))^(3/2)*x*(1 - 9*a*x))/((1 - a*x)^(3/2)*Sqrt[1 + a*x]) - ((c - c/(a*x))^(3/2)*x*Sqrt[1 - a*x])/Sqrt[1 + a*x] + (9*Sqrt[a]*(c - c/(a*x))^(3/2)*x^(3/2)*ArcSinh[Sqrt[a]*Sqrt[x]])/(1 - a*x)^(3/2)}
{Sqrt[c - c/(a*x)]/E^(3*ArcTanh[a*x]), x, 5, (8*Sqrt[c - c/(a*x)]*x)/(Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (Sqrt[c - c/(a*x)]*x*Sqrt[1 + a*x])/Sqrt[1 - a*x] - (7*Sqrt[c - c/(a*x)]*Sqrt[x]*ArcSinh[Sqrt[a]*Sqrt[x]])/(Sqrt[a]*Sqrt[1 - a*x])}
{1/(E^(3*ArcTanh[a*x])*Sqrt[c - c/(a*x)]), x, 5, (4*x*Sqrt[1 - a*x])/(Sqrt[c - c/(a*x)]*Sqrt[1 + a*x]) - (5*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(a*Sqrt[c - c/(a*x)]) + (5*Sqrt[1 - a*x]*ArcSinh[Sqrt[a]*Sqrt[x]])/(a^(3/2)*Sqrt[c - c/(a*x)]*Sqrt[x])}
{1/(E^(3*ArcTanh[a*x])*(c - c/(a*x))^(3/2)), x, 5, -((2*(1 - a*x)^(3/2))/(a*(c - c/(a*x))^(3/2)*Sqrt[1 + a*x])) + (3*(1 - a*x)^(3/2)*Sqrt[1 + a*x])/(a^2*(c - c/(a*x))^(3/2)*x) - (3*(1 - a*x)^(3/2)*ArcSinh[Sqrt[a]*Sqrt[x]])/(a^(5/2)*(c - c/(a*x))^(3/2)*x^(3/2))}
{1/(E^(3*ArcTanh[a*x])*(c - c/(a*x))^(5/2)), x, 8, -((1 - a*x)^(5/2)/(a*(c - c/(a*x))^(5/2)*Sqrt[1 + a*x])) - (2*(1 - a*x)^(5/2)*Sqrt[1 + a*x])/(a^3*(c - c/(a*x))^(5/2)*x^2) + ((1 - a*x)^(5/2)*Sqrt[1 + a*x])/(a^2*(c - c/(a*x))^(5/2)*x) + ((1 - a*x)^(5/2)*ArcSinh[Sqrt[a]*Sqrt[x]])/(a^(7/2)*(c - c/(a*x))^(5/2)*x^(5/2)) + ((1 - a*x)^(5/2)*ArcTanh[(Sqrt[2]*Sqrt[a]*Sqrt[x])/Sqrt[1 + a*x]])/(Sqrt[2]*a^(7/2)*(c - c/(a*x))^(5/2)*x^(5/2))}
{1/(E^(3*ArcTanh[a*x])*(c - c/(a*x))^(7/2)), x, 9, (1 - a*x)^(5/2)/(2*a*(c - c/(a*x))^(7/2)*Sqrt[1 + a*x]) + (3*(1 - a*x)^(7/2))/(4*a^2*(c - c/(a*x))^(7/2)*x*Sqrt[1 + a*x]) + (7*(1 - a*x)^(7/2)*Sqrt[1 + a*x])/(4*a^4*(c - c/(a*x))^(7/2)*x^3) - ((1 - a*x)^(7/2)*Sqrt[1 + a*x])/(4*a^3*(c - c/(a*x))^(7/2)*x^2) + ((1 - a*x)^(7/2)*ArcSinh[Sqrt[a]*Sqrt[x]])/(a^(9/2)*(c - c/(a*x))^(7/2)*x^(7/2)) - (11*(1 - a*x)^(7/2)*ArcTanh[(Sqrt[2]*Sqrt[a]*Sqrt[x])/Sqrt[1 + a*x]])/(4*Sqrt[2]*a^(9/2)*(c - c/(a*x))^(7/2)*x^(7/2))}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{E^(n*ArcTanh[a*x])*(c - c/(a*x))^(3/2), x, 3, -((2*(c - c/(a*x))^(3/2)*x*AppellF1[-(1/2), (1/2)*(-3 + n), -(n/2), 1/2, a*x, (-a)*x])/(1 - a*x)^(3/2))}
{E^(n*ArcTanh[a*x])*Sqrt[c - c/(a*x)], x, 3, (2*Sqrt[c - c/(a*x)]*x*AppellF1[1/2, (-1 + n)/2, -n/2, 3/2, a*x, -(a*x)])/Sqrt[1 - a*x]}
{E^(n*ArcTanh[a*x])/Sqrt[c - c/(a*x)], x, 3, (2*x*Sqrt[1 - a*x]*AppellF1[3/2, (1 + n)/2, -n/2, 5/2, a*x, -(a*x)])/(3*Sqrt[c - c/(a*x)])}
{E^(n*ArcTanh[a*x])/(c - c/(a*x))^(3/2), x, 3, (2*x*(1 - a*x)^(3/2)*AppellF1[5/2, (3 + n)/2, -(n/2), 7/2, a*x, (-a)*x])/(5*(c - c/(a*x))^(3/2))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(n ArcTanh[a x]) (c-c/(a x))^(p/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{E^ArcTanh[a*x]*Sqrt[c - c/(a*x)]*x^m, x, 5, (Sqrt[c - c/(a*x)]*x^(1 + m)*Sqrt[1 + a*x])/((1 + m)*Sqrt[1 - a*x]) + (Sqrt[c - c/(a*x)]*x^(1 + m)*Sqrt[1 + a*x])/((1 + 3*m + 2*m^2)*Sqrt[1 - a*x]) - (2*Sqrt[c - c/(a*x)]*x^(1 + m)*(-(a*x))^(-1/2 - m)*Sqrt[1 + a*x]*Hypergeometric2F1[1/2, -1/2 - m, 3/2, 1 + a*x])/((1 + 2*m)*Sqrt[1 - a*x])}

{E^ArcTanh[a*x]*Sqrt[c - c/(a*x)]*x^2, x, 6, -(Sqrt[c - c/(a*x)]*x*Sqrt[1 + a*x])/(8*a^2*Sqrt[1 - a*x]) + (Sqrt[c - c/(a*x)]*x^2*Sqrt[1 + a*x])/(12*a*Sqrt[1 - a*x]) + (Sqrt[c - c/(a*x)]*x^3*Sqrt[1 + a*x])/(3*Sqrt[1 - a*x]) + (Sqrt[c - c/(a*x)]*Sqrt[x]*ArcSinh[Sqrt[a]*Sqrt[x]])/(8*a^(5/2)*Sqrt[1 - a*x])}
{E^ArcTanh[a*x]*Sqrt[c - c/(a*x)]*x, x, 5, (Sqrt[c - c/(a*x)]*x*Sqrt[1 + a*x])/(4*a*Sqrt[1 - a*x]) + (Sqrt[c - c/(a*x)]*x^2*Sqrt[1 + a*x])/(2*Sqrt[1 - a*x]) - (Sqrt[c - c/(a*x)]*Sqrt[x]*ArcSinh[Sqrt[a]*Sqrt[x]])/(4*a^(3/2)*Sqrt[1 - a*x])}
{E^ArcTanh[a*x]*Sqrt[c - c/(a*x)], x, 4, (Sqrt[c - c/(a*x)]*x*Sqrt[1 + a*x])/Sqrt[1 - a*x] + (Sqrt[c - c/(a*x)]*Sqrt[x]*ArcSinh[Sqrt[a]*Sqrt[x]])/(Sqrt[a]*Sqrt[1 - a*x])}
{(E^ArcTanh[a*x]*Sqrt[c - c/(a*x)])/x, x, 4, (-2*Sqrt[c - c/(a*x)]*Sqrt[1 + a*x])/Sqrt[1 - a*x] + (2*Sqrt[a]*Sqrt[c - c/(a*x)]*Sqrt[x]*ArcSinh[Sqrt[a]*Sqrt[x]])/Sqrt[1 - a*x]}
{(E^ArcTanh[a*x]*Sqrt[c - c/(a*x)])/x^2, x, 3, (-2*Sqrt[c - c/(a*x)]*(1 + a*x)^(3/2))/(3*x*Sqrt[1 - a*x])}


{E^(2*ArcTanh[a*x])*Sqrt[c - c/(a*x)]*x^3, x, 8, -((75*Sqrt[c - c/(a*x)]*x)/(64*a^3)) - (25*Sqrt[c - c/(a*x)]*x^2)/(32*a^2) - (5*Sqrt[c - c/(a*x)]*x^3)/(8*a) - (1/4)*Sqrt[c - c/(a*x)]*x^4 - (75*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/(64*a^4)}
{E^(2*ArcTanh[a*x])*Sqrt[c - c/(a*x)]*x^2, x, 7, -((11*Sqrt[c - c/(a*x)]*x)/(8*a^2)) - (11*Sqrt[c - c/(a*x)]*x^2)/(12*a) - (1/3)*Sqrt[c - c/(a*x)]*x^3 - (11*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/(8*a^3)}
{E^(2*ArcTanh[a*x])*Sqrt[c - c/(a*x)]*x, x, 6, -((7*Sqrt[c - c/(a*x)]*x)/(4*a)) - (1/2)*Sqrt[c - c/(a*x)]*x^2 - (7*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/(4*a^2)}
{E^(2*ArcTanh[a*x])*Sqrt[c - c/(a*x)], x, 5, (-Sqrt[c - c/(a*x)])*x - (3*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/a}
{(E^(2*ArcTanh[a*x])*Sqrt[c - c/(a*x)])/x, x, 5, -2*Sqrt[c - c/(a*x)] - 2*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]]}
{(E^(2*ArcTanh[a*x])*Sqrt[c - c/(a*x)])/x^2, x, 4, -4*a*Sqrt[c - c/(a*x)] + (2*a*(c - c/(a*x))^(3/2))/(3*c)}
{(E^(2*ArcTanh[a*x])*Sqrt[c - c/(a*x)])/x^3, x, 5, -4*a^2*Sqrt[c - c/(a*x)] + (2*a^2*(c - c/(a*x))^(3/2))/c - (2*a^2*(c - c/(a*x))^(5/2))/(5*c^2)}
{(E^(2*ArcTanh[a*x])*Sqrt[c - c/(a*x)])/x^4, x, 5, -4*a^3*Sqrt[c - c/(a*x)] + (10*a^3*(c - c/(a*x))^(3/2))/(3*c) - (8*a^3*(c - c/(a*x))^(5/2))/(5*c^2) + (2*a^3*(c - c/(a*x))^(7/2))/(7*c^3)}
{(E^(2*ArcTanh[a*x])*Sqrt[c - c/(a*x)])/x^5, x, 5, -4*a^4*Sqrt[c - c/(a*x)] + (14*a^4*(c - c/(a*x))^(3/2))/(3*c) - (18*a^4*(c - c/(a*x))^(5/2))/(5*c^2) + (10*a^4*(c - c/(a*x))^(7/2))/(7*c^3) - (2*a^4*(c - c/(a*x))^(9/2))/(9*c^4)}


{E^(3*ArcTanh[a*x])*Sqrt[c - c/(a*x)]*x^3, x, 9, -((107*Sqrt[c - c/(a*x)]*x*Sqrt[1 + a*x])/(64*a^3*Sqrt[1 - a*x])) - (21*Sqrt[c - c/(a*x)]*x*(1 + a*x)^(3/2))/(32*a^3*Sqrt[1 - a*x]) - (11*Sqrt[c - c/(a*x)]*x^2*(1 + a*x)^(3/2))/(24*a^2*Sqrt[1 - a*x]) - (Sqrt[c - c/(a*x)]*x^3*(1 + a*x)^(3/2))/(4*a*Sqrt[1 - a*x]) - (363*Sqrt[c - c/(a*x)]*Sqrt[x]*ArcSinh[Sqrt[a]*Sqrt[x]])/(64*a^(7/2)*Sqrt[1 - a*x]) + (4*Sqrt[2]*Sqrt[c - c/(a*x)]*Sqrt[x]*ArcTanh[(Sqrt[2]*Sqrt[a]*Sqrt[x])/Sqrt[1 + a*x]])/(a^(7/2)*Sqrt[1 - a*x])}
{E^(3*ArcTanh[a*x])*Sqrt[c - c/(a*x)]*x^2, x, 8, -((13*Sqrt[c - c/(a*x)]*x*Sqrt[1 + a*x])/(8*a^2*Sqrt[1 - a*x])) - (3*Sqrt[c - c/(a*x)]*x*(1 + a*x)^(3/2))/(4*a^2*Sqrt[1 - a*x]) - (Sqrt[c - c/(a*x)]*x^2*(1 + a*x)^(3/2))/(3*a*Sqrt[1 - a*x]) - (45*Sqrt[c - c/(a*x)]*Sqrt[x]*ArcSinh[Sqrt[a]*Sqrt[x]])/(8*a^(5/2)*Sqrt[1 - a*x]) + (4*Sqrt[2]*Sqrt[c - c/(a*x)]*Sqrt[x]*ArcTanh[(Sqrt[2]*Sqrt[a]*Sqrt[x])/Sqrt[1 + a*x]])/(a^(5/2)*Sqrt[1 - a*x])}
{E^(3*ArcTanh[a*x])*Sqrt[c - c/(a*x)]*x, x, 7, -((7*Sqrt[c - c/(a*x)]*x*Sqrt[1 + a*x])/(4*a*Sqrt[1 - a*x])) - (Sqrt[c - c/(a*x)]*x*(1 + a*x)^(3/2))/(2*a*Sqrt[1 - a*x]) - (23*Sqrt[c - c/(a*x)]*Sqrt[x]*ArcSinh[Sqrt[a]*Sqrt[x]])/(4*a^(3/2)*Sqrt[1 - a*x]) + (4*Sqrt[2]*Sqrt[c - c/(a*x)]*Sqrt[x]*ArcTanh[(Sqrt[2]*Sqrt[a]*Sqrt[x])/Sqrt[1 + a*x]])/(a^(3/2)*Sqrt[1 - a*x])}
{E^(3*ArcTanh[a*x])*Sqrt[c - c/(a*x)], x, 6, -((Sqrt[c - c/(a*x)]*x*Sqrt[1 + a*x])/Sqrt[1 - a*x]) - (5*Sqrt[c - c/(a*x)]*Sqrt[x]*ArcSinh[Sqrt[a]*Sqrt[x]])/(Sqrt[a]*Sqrt[1 - a*x]) + (4*Sqrt[2]*Sqrt[c - c/(a*x)]*Sqrt[x]*ArcTanh[(Sqrt[2]*Sqrt[a]*Sqrt[x])/Sqrt[1 + a*x]])/(Sqrt[a]*Sqrt[1 - a*x])}
{(E^(3*ArcTanh[a*x])*Sqrt[c - c/(a*x)])/x, x, 7, (2*a*Sqrt[c - c/(a*x)]*x*Sqrt[1 + a*x])/Sqrt[1 - a*x] - (2*Sqrt[c - c/(a*x)]*(1 + a*x)^(3/2))/Sqrt[1 - a*x] - (2*Sqrt[a]*Sqrt[c - c/(a*x)]*Sqrt[x]*ArcSinh[Sqrt[a]*Sqrt[x]])/Sqrt[1 - a*x] + (4*Sqrt[2]*Sqrt[a]*Sqrt[c - c/(a*x)]*Sqrt[x]*ArcTanh[(Sqrt[2]*Sqrt[a]*Sqrt[x])/Sqrt[1 + a*x]])/Sqrt[1 - a*x]}
{(E^(3*ArcTanh[a*x])*Sqrt[c - c/(a*x)])/x^2, x, 5, -((4*a*Sqrt[c - c/(a*x)]*Sqrt[1 + a*x])/Sqrt[1 - a*x]) - (2*Sqrt[c - c/(a*x)]*(1 + a*x)^(3/2))/(3*x*Sqrt[1 - a*x]) + (4*Sqrt[2]*a^(3/2)*Sqrt[c - c/(a*x)]*Sqrt[x]*ArcTanh[(Sqrt[2]*Sqrt[a]*Sqrt[x])/Sqrt[1 + a*x]])/Sqrt[1 - a*x]}
{(E^(3*ArcTanh[a*x])*Sqrt[c - c/(a*x)])/x^3, x, 7, -((76*a^2*Sqrt[c - c/(a*x)]*Sqrt[1 + a*x])/(15*Sqrt[1 - a*x])) - (16*a*Sqrt[c - c/(a*x)]*Sqrt[1 + a*x])/(15*x*Sqrt[1 - a*x]) - (2*Sqrt[c - c/(a*x)]*(1 + a*x)^(3/2))/(5*x^2*Sqrt[1 - a*x]) + (4*Sqrt[2]*a^(5/2)*Sqrt[c - c/(a*x)]*Sqrt[x]*ArcTanh[(Sqrt[2]*Sqrt[a]*Sqrt[x])/Sqrt[1 + a*x]])/Sqrt[1 - a*x]}
{(E^(3*ArcTanh[a*x])*Sqrt[c - c/(a*x)])/x^4, x, 8, -((104*a^3*Sqrt[c - c/(a*x)]*Sqrt[1 + a*x])/(21*Sqrt[1 - a*x])) - (4*a*Sqrt[c - c/(a*x)]*Sqrt[1 + a*x])/(7*x^2*Sqrt[1 - a*x]) - (32*a^2*Sqrt[c - c/(a*x)]*Sqrt[1 + a*x])/(21*x*Sqrt[1 - a*x]) - (2*Sqrt[c - c/(a*x)]*(1 + a*x)^(3/2))/(7*x^3*Sqrt[1 - a*x]) + (4*Sqrt[2]*a^(7/2)*Sqrt[c - c/(a*x)]*Sqrt[x]*ArcTanh[(Sqrt[2]*Sqrt[a]*Sqrt[x])/Sqrt[1 + a*x]])/Sqrt[1 - a*x]}
{(E^(3*ArcTanh[a*x])*Sqrt[c - c/(a*x)])/x^5, x, 9, -((1576*a^4*Sqrt[c - c/(a*x)]*Sqrt[1 + a*x])/(315*Sqrt[1 - a*x])) - (8*a*Sqrt[c - c/(a*x)]*Sqrt[1 + a*x])/(21*x^3*Sqrt[1 - a*x]) - (92*a^2*Sqrt[c - c/(a*x)]*Sqrt[1 + a*x])/(105*x^2*Sqrt[1 - a*x]) - (472*a^3*Sqrt[c - c/(a*x)]*Sqrt[1 + a*x])/(315*x*Sqrt[1 - a*x]) - (2*Sqrt[c - c/(a*x)]*(1 + a*x)^(3/2))/(9*x^4*Sqrt[1 - a*x]) + (4*Sqrt[2]*a^(9/2)*Sqrt[c - c/(a*x)]*Sqrt[x]*ArcTanh[(Sqrt[2]*Sqrt[a]*Sqrt[x])/Sqrt[1 + a*x]])/Sqrt[1 - a*x]}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(Sqrt[c - c/(a*x)]*x^m)/E^ArcTanh[a*x], x, 4, (2*Sqrt[c - c/(a*x)]*x^(1 + m)*Sqrt[1 + a*x])/((1 + 2*m)*Sqrt[1 - a*x]) - (2*(3 + 4*m)*Sqrt[c - c/(a*x)]*x^(1 + m)*((-a)*x)^(-(1/2) - m)*Sqrt[1 + a*x]*Hypergeometric2F1[1/2, -(1/2) - m, 3/2, 1 + a*x])/((1 + 2*m)*Sqrt[1 - a*x])}

{(Sqrt[c - c/(a*x)]*x^2)/E^ArcTanh[a*x], x, 6, -((11*Sqrt[c - c/(a*x)]*x*Sqrt[1 + a*x])/(8*a^2*Sqrt[1 - a*x])) + (11*Sqrt[c - c/(a*x)]*x^2*Sqrt[1 + a*x])/(12*a*Sqrt[1 - a*x]) - (Sqrt[c - c/(a*x)]*x^3*Sqrt[1 + a*x])/(3*Sqrt[1 - a*x]) + (11*Sqrt[c - c/(a*x)]*Sqrt[x]*ArcSinh[Sqrt[a]*Sqrt[x]])/(8*a^(5/2)*Sqrt[1 - a*x])}
{(Sqrt[c - c/(a*x)]*x)/E^ArcTanh[a*x], x, 5, (7*Sqrt[c - c/(a*x)]*x*Sqrt[1 + a*x])/(4*a*Sqrt[1 - a*x]) - (Sqrt[c - c/(a*x)]*x^2*Sqrt[1 + a*x])/(2*Sqrt[1 - a*x]) - (7*Sqrt[c - c/(a*x)]*Sqrt[x]*ArcSinh[Sqrt[a]*Sqrt[x]])/(4*a^(3/2)*Sqrt[1 - a*x])}
{Sqrt[c - c/(a*x)]/E^ArcTanh[a*x], x, 4, -((Sqrt[c - c/(a*x)]*x*Sqrt[1 + a*x])/Sqrt[1 - a*x]) + (3*Sqrt[c - c/(a*x)]*Sqrt[x]*ArcSinh[Sqrt[a]*Sqrt[x]])/(Sqrt[a]*Sqrt[1 - a*x])}
{Sqrt[c - c/(a*x)]/(E^ArcTanh[a*x]*x), x, 4, -((2*Sqrt[c - c/(a*x)]*Sqrt[1 + a*x])/Sqrt[1 - a*x]) - (2*Sqrt[a]*Sqrt[c - c/(a*x)]*Sqrt[x]*ArcSinh[Sqrt[a]*Sqrt[x]])/Sqrt[1 - a*x]}
{Sqrt[c - c/(a*x)]/(E^ArcTanh[a*x]*x^2), x, 4, (10*a*Sqrt[c - c/(a*x)]*Sqrt[1 + a*x])/(3*Sqrt[1 - a*x]) - (2*Sqrt[c - c/(a*x)]*Sqrt[1 + a*x])/(3*x*Sqrt[1 - a*x])}
{Sqrt[c - c/(a*x)]/(E^ArcTanh[a*x]*x^3), x, 5, -((12*a^2*Sqrt[c - c/(a*x)]*Sqrt[1 + a*x])/(5*Sqrt[1 - a*x])) - (2*Sqrt[c - c/(a*x)]*Sqrt[1 + a*x])/(5*x^2*Sqrt[1 - a*x]) + (6*a*Sqrt[c - c/(a*x)]*Sqrt[1 + a*x])/(5*x*Sqrt[1 - a*x])}
{Sqrt[c - c/(a*x)]/(E^ArcTanh[a*x]*x^4), x, 6, (208*a^3*Sqrt[c - c/(a*x)]*Sqrt[1 + a*x])/(105*Sqrt[1 - a*x]) - (2*Sqrt[c - c/(a*x)]*Sqrt[1 + a*x])/(7*x^3*Sqrt[1 - a*x]) + (26*a*Sqrt[c - c/(a*x)]*Sqrt[1 + a*x])/(35*x^2*Sqrt[1 - a*x]) - (104*a^2*Sqrt[c - c/(a*x)]*Sqrt[1 + a*x])/(105*x*Sqrt[1 - a*x])}


{(Sqrt[c - c/(a*x)]*x^3)/E^(2*ArcTanh[a*x]), x, 10, (149*Sqrt[c - c/(a*x)]*x)/(64*a^3) - (107*Sqrt[c - c/(a*x)]*x^2)/(96*a^2) + (17*Sqrt[c - c/(a*x)]*x^3)/(24*a) - (1/4)*Sqrt[c - c/(a*x)]*x^4 - (363*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/(64*a^4) + (4*Sqrt[2]*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])])/a^4}
{(Sqrt[c - c/(a*x)]*x^2)/E^(2*ArcTanh[a*x]), x, 9, -((19*Sqrt[c - c/(a*x)]*x)/(8*a^2)) + (13*Sqrt[c - c/(a*x)]*x^2)/(12*a) - (1/3)*Sqrt[c - c/(a*x)]*x^3 + (45*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/(8*a^3) - (4*Sqrt[2]*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])])/a^3}
{(Sqrt[c - c/(a*x)]*x)/E^(2*ArcTanh[a*x]), x, 8, (9*Sqrt[c - c/(a*x)]*x)/(4*a) - (1/2)*Sqrt[c - c/(a*x)]*x^2 - (23*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/(4*a^2) + (4*Sqrt[2]*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])])/a^2}
{Sqrt[c - c/(a*x)]/E^(2*ArcTanh[a*x]), x, 9, (-Sqrt[c - c/(a*x)])*x + (5*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/a - (4*Sqrt[2]*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])])/a}
{Sqrt[c - c/(a*x)]/(E^(2*ArcTanh[a*x])*x), x, 7, -2*Sqrt[c - c/(a*x)] - 2*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]] + 4*Sqrt[2]*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])]}
{Sqrt[c - c/(a*x)]/(E^(2*ArcTanh[a*x])*x^2), x, 6, 4*a*Sqrt[c - c/(a*x)] + (2*a*(c - c/(a*x))^(3/2))/(3*c) - 4*Sqrt[2]*a*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])]}
{Sqrt[c - c/(a*x)]/(E^(2*ArcTanh[a*x])*x^3), x, 6, -4*a^2*Sqrt[c - c/(a*x)] - (2*a^2*(c - c/(a*x))^(3/2))/(3*c) - (2*a^2*(c - c/(a*x))^(5/2))/(5*c^2) + 4*Sqrt[2]*a^2*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])]}
{Sqrt[c - c/(a*x)]/(E^(2*ArcTanh[a*x])*x^4), x, 6, 4*a^3*Sqrt[c - c/(a*x)] + (2*a^3*(c - c/(a*x))^(3/2))/(3*c) + (2*a^3*(c - c/(a*x))^(7/2))/(7*c^3) - 4*Sqrt[2]*a^3*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])]}
{Sqrt[c - c/(a*x)]/(E^(2*ArcTanh[a*x])*x^5), x, 6, -4*a^4*Sqrt[c - c/(a*x)] - (2*a^4*(c - c/(a*x))^(3/2))/(3*c) - (2*a^4*(c - c/(a*x))^(5/2))/(5*c^2) + (2*a^4*(c - c/(a*x))^(7/2))/(7*c^3) - (2*a^4*(c - c/(a*x))^(9/2))/(9*c^4) + 4*Sqrt[2]*a^4*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])]}


{(Sqrt[c - c/(a*x)]*x^3)/E^(3*ArcTanh[a*x]), x, 8, (8*Sqrt[c - c/(a*x)]*x^4)/(Sqrt[1 - a*x]*Sqrt[1 + a*x]) - (1115*Sqrt[c - c/(a*x)]*x*Sqrt[1 + a*x])/(64*a^3*Sqrt[1 - a*x]) + (1115*Sqrt[c - c/(a*x)]*x^2*Sqrt[1 + a*x])/(96*a^2*Sqrt[1 - a*x]) - (223*Sqrt[c - c/(a*x)]*x^3*Sqrt[1 + a*x])/(24*a*Sqrt[1 - a*x]) + (Sqrt[c - c/(a*x)]*x^4*Sqrt[1 + a*x])/(4*Sqrt[1 - a*x]) + (1115*Sqrt[c - c/(a*x)]*Sqrt[x]*ArcSinh[Sqrt[a]*Sqrt[x]])/(64*a^(7/2)*Sqrt[1 - a*x])}
{(Sqrt[c - c/(a*x)]*x^2)/E^(3*ArcTanh[a*x]), x, 7, (8*Sqrt[c - c/(a*x)]*x^3)/(Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (119*Sqrt[c - c/(a*x)]*x*Sqrt[1 + a*x])/(8*a^2*Sqrt[1 - a*x]) - (119*Sqrt[c - c/(a*x)]*x^2*Sqrt[1 + a*x])/(12*a*Sqrt[1 - a*x]) + (Sqrt[c - c/(a*x)]*x^3*Sqrt[1 + a*x])/(3*Sqrt[1 - a*x]) - (119*Sqrt[c - c/(a*x)]*Sqrt[x]*ArcSinh[Sqrt[a]*Sqrt[x]])/(8*a^(5/2)*Sqrt[1 - a*x])}
{(Sqrt[c - c/(a*x)]*x)/E^(3*ArcTanh[a*x]), x, 6, (8*Sqrt[c - c/(a*x)]*x^2)/(Sqrt[1 - a*x]*Sqrt[1 + a*x]) - (47*Sqrt[c - c/(a*x)]*x*Sqrt[1 + a*x])/(4*a*Sqrt[1 - a*x]) + (Sqrt[c - c/(a*x)]*x^2*Sqrt[1 + a*x])/(2*Sqrt[1 - a*x]) + (47*Sqrt[c - c/(a*x)]*Sqrt[x]*ArcSinh[Sqrt[a]*Sqrt[x]])/(4*a^(3/2)*Sqrt[1 - a*x])}
{Sqrt[c - c/(a*x)]/E^(3*ArcTanh[a*x]), x, 5, (8*Sqrt[c - c/(a*x)]*x)/(Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (Sqrt[c - c/(a*x)]*x*Sqrt[1 + a*x])/Sqrt[1 - a*x] - (7*Sqrt[c - c/(a*x)]*Sqrt[x]*ArcSinh[Sqrt[a]*Sqrt[x]])/(Sqrt[a]*Sqrt[1 - a*x])}
{Sqrt[c - c/(a*x)]/(E^(3*ArcTanh[a*x])*x), x, 5, (-2*Sqrt[c - c/(a*x)])/(Sqrt[1 - a*x]*Sqrt[1 + a*x]) - (10*a*Sqrt[c - c/(a*x)]*x)/(Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (2*Sqrt[a]*Sqrt[c - c/(a*x)]*Sqrt[x]*ArcSinh[Sqrt[a]*Sqrt[x]])/Sqrt[1 - a*x]}
{Sqrt[c - c/(a*x)]/(E^(3*ArcTanh[a*x])*x^2), x, 5, (20*a*Sqrt[c - c/(a*x)])/(3*Sqrt[1 - a*x]*Sqrt[1 + a*x]) - (2*Sqrt[c - c/(a*x)])/(3*x*Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (46*a^2*Sqrt[c - c/(a*x)]*x)/(3*Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{Sqrt[c - c/(a*x)]/(E^(3*ArcTanh[a*x])*x^3), x, 6, (158*a^2*Sqrt[c - c/(a*x)])/(15*Sqrt[1 - a*x]*Sqrt[1 + a*x]) - (2*Sqrt[c - c/(a*x)])/(5*x^2*Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (32*a*Sqrt[c - c/(a*x)])/(15*x*Sqrt[1 - a*x]*Sqrt[1 + a*x]) - (316*a^2*Sqrt[c - c/(a*x)]*Sqrt[1 + a*x])/(15*Sqrt[1 - a*x])}
{Sqrt[c - c/(a*x)]/(E^(3*ArcTanh[a*x])*x^4), x, 7, (-2*Sqrt[c - c/(a*x)])/(7*x^3*Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (44*a*Sqrt[c - c/(a*x)])/(35*x^2*Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (334*a^2*Sqrt[c - c/(a*x)])/(35*x*Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (2672*a^3*Sqrt[c - c/(a*x)]*Sqrt[1 + a*x])/(105*Sqrt[1 - a*x]) - (1336*a^2*Sqrt[c - c/(a*x)]*Sqrt[1 + a*x])/(105*x*Sqrt[1 - a*x])}
{Sqrt[c - c/(a*x)]/(E^(3*ArcTanh[a*x])*x^5), x, 8, (-2*Sqrt[c - c/(a*x)])/(9*x^4*Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (8*a*Sqrt[c - c/(a*x)])/(9*x^3*Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (82*a^2*Sqrt[c - c/(a*x)])/(9*x^2*Sqrt[1 - a*x]*Sqrt[1 + a*x]) - (1312*a^4*Sqrt[c - c/(a*x)]*Sqrt[1 + a*x])/(45*Sqrt[1 - a*x]) - (164*a^2*Sqrt[c - c/(a*x)]*Sqrt[1 + a*x])/(15*x^2*Sqrt[1 - a*x]) + (656*a^3*Sqrt[c - c/(a*x)]*Sqrt[1 + a*x])/(45*x*Sqrt[1 - a*x])}


(* ::Subtitle::Closed:: *)
(*Integration problems of the form u E^(n ArcTanh[a x]) (c-c a^2 x^2)^p*)


(* ::Section::Closed:: *)
(*Integrands of the form x^m E^(1 ArcTanh[a x]) (c-c a^2 x^2)^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^ArcTanh[a x] (c-c a^2 x^2)^p*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{E^ArcTanh[a*x]*(c - c*a^2*x^2)^4, x, 7, (35/128)*c^4*x*Sqrt[1 - a^2*x^2] + (35/192)*c^4*x*(1 - a^2*x^2)^(3/2) + (7/48)*c^4*x*(1 - a^2*x^2)^(5/2) + (1/8)*c^4*x*(1 - a^2*x^2)^(7/2) - (c^4*(1 - a^2*x^2)^(9/2))/(9*a) + (35*c^4*ArcSin[a*x])/(128*a)}


{E^ArcTanh[a*x]*(c - c*a^2*x^2)^3, x, 6, (5/16)*c^3*x*Sqrt[1 - a^2*x^2] + (5/24)*c^3*x*(1 - a^2*x^2)^(3/2) + (1/6)*c^3*x*(1 - a^2*x^2)^(5/2) - (c^3*(1 - a^2*x^2)^(7/2))/(7*a) + (5*c^3*ArcSin[a*x])/(16*a)}


{E^ArcTanh[a*x]*(c - c*a^2*x^2)^2, x, 5, (3/8)*c^2*x*Sqrt[1 - a^2*x^2] + (1/4)*c^2*x*(1 - a^2*x^2)^(3/2) - (c^2*(1 - a^2*x^2)^(5/2))/(5*a) + (3*c^2*ArcSin[a*x])/(8*a)}


{E^ArcTanh[a*x]*(c - c*a^2*x^2)^1, x, 4, (1/2)*c*x*Sqrt[1 - a^2*x^2] - (c*(1 - a^2*x^2)^(3/2))/(3*a) + (c*ArcSin[a*x])/(2*a)}


(* ::Subsubsection::Closed:: *)
(*p<0*)


{x^m*E^ArcTanh[a*x]/(c - a^2*c*x^2), x, 6, (x^(1 + m)*(1 + a*x))/(c*Sqrt[1 - a^2*x^2]) - (m*x^(1 + m)*Hypergeometric2F1[1/2, (1 + m)/2, (3 + m)/2, a^2*x^2])/(c*(1 + m)) - (a*(1 + m)*x^(2 + m)*Hypergeometric2F1[1/2, (2 + m)/2, (4 + m)/2, a^2*x^2])/(c*(2 + m))}

{x^4*E^ArcTanh[a*x]/(c - a^2*c*x^2), x, 6, (4*x^2*Sqrt[1 + a*x])/(3*a^3*c*Sqrt[1 - a*x]) - (x^3*Sqrt[1 + a*x])/(3*a^2*c*Sqrt[1 - a*x]) + (8*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(3*a^5*c) + (3*x*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(2*a^4*c) - (3*ArcSin[a*x])/(2*a^5*c)}
{x^3*E^ArcTanh[a*x]/(c - a^2*c*x^2), x, 5, -((x^2*Sqrt[1 + a*x])/(2*a^2*c*Sqrt[1 - a*x])) + (Sqrt[1 - a*x]*Sqrt[1 + a*x])/(a^4*c) + (Sqrt[1 + a*x]*(2 + a*x))/(2*a^4*c*Sqrt[1 - a*x]) - (3*ArcSin[a*x])/(2*a^4*c)}
{x^2*E^ArcTanh[a*x]/(c - a^2*c*x^2), x, 5, Sqrt[1 + a*x]/(a^3*c*Sqrt[1 - a*x]) + (Sqrt[1 - a*x]*Sqrt[1 + a*x])/(a^3*c) - ArcSin[a*x]/(a^3*c)}
{x^1*E^ArcTanh[a*x]/(c - a^2*c*x^2), x, 3, Sqrt[1 + a*x]/(a^2*c*Sqrt[1 - a*x]) - ArcSin[a*x]/(a^2*c)}
{x^0*E^ArcTanh[a*x]/(c - a^2*c*x^2), x, 1, E^ArcTanh[a*x]/(a*c)}
{E^ArcTanh[a*x]/(x*(c - a^2*c*x^2)), x, 4, Sqrt[1 + a*x]/(c*Sqrt[1 - a*x]) - (2*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/c}
{E^ArcTanh[a*x]/(x^2*(c - a^2*c*x^2)), x, 5, (2*a*Sqrt[1 + a*x])/(c*Sqrt[1 - a*x]) - Sqrt[1 + a*x]/(c*x*Sqrt[1 - a*x]) - (2*a*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/c}
{E^ArcTanh[a*x]/(x^3*(c - a^2*c*x^2)), x, 6, (2*a^2*Sqrt[1 + a*x])/(c*Sqrt[1 - a*x]) - Sqrt[1 + a*x]/(2*c*x^2*Sqrt[1 - a*x]) - (a*Sqrt[1 + a*x])/(2*c*x*Sqrt[1 - a*x]) - (3*a^2*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/c}
{E^ArcTanh[a*x]/(x^4*(c - a^2*c*x^2)), x, 7, (8*a^3*Sqrt[1 + a*x])/(3*c*Sqrt[1 - a*x]) - Sqrt[1 + a*x]/(3*c*x^3*Sqrt[1 - a*x]) - (a*Sqrt[1 + a*x])/(6*c*x^2*Sqrt[1 - a*x]) - (7*a^2*Sqrt[1 + a*x])/(6*c*x*Sqrt[1 - a*x]) - (3*a^3*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/c}


{x^m*E^ArcTanh[a*x]/(c - a^2*c*x^2)^2, x, 7, (x^(1 + m)*(1 + a*x))/(3*c^2*(1 - a^2*x^2)^(3/2)) + (x^(1 + m)*(2 - m + a*(1 - m)*x))/(3*c^2*Sqrt[1 - a^2*x^2]) - ((2 - m)*m*x^(1 + m)*Hypergeometric2F1[1/2, (1 + m)/2, (3 + m)/2, a^2*x^2])/(3*c^2*(1 + m)) - (a*(1 - m)*(1 + m)*x^(2 + m)*Hypergeometric2F1[1/2, (2 + m)/2, (4 + m)/2, a^2*x^2])/(3*c^2*(2 + m))}

{x^6*E^ArcTanh[a*x]/(c - a^2*c*x^2)^2, x, 9, (x^6*(1 + a*x))/(3*a*c^2*(1 - a^2*x^2)^(3/2)) - (2*x^5*(2 + 3*a*x))/(3*a^2*c^2*Sqrt[1 - a^2*x^2]) - (8*Sqrt[1 - a^2*x^2])/(3*a^7*c^2) - (8*x^2*Sqrt[1 - a^2*x^2])/(3*a^5*c^2) - (5*x^3*Sqrt[1 - a^2*x^2])/(3*a^4*c^2) - (2*x^4*Sqrt[1 - a^2*x^2])/(a^3*c^2) - ((16 + 15*a*x)*Sqrt[1 - a^2*x^2])/(6*a^7*c^2) + (5*ArcSin[a*x])/(2*a^7*c^2)}
{x^5*E^ArcTanh[a*x]/(c - a^2*c*x^2)^2, x, 8, (x^5*(1 + a*x))/(3*a*c^2*(1 - a^2*x^2)^(3/2)) - (x^4*(3 + 5*a*x))/(3*a^2*c^2*Sqrt[1 - a^2*x^2]) - (4*Sqrt[1 - a^2*x^2])/(3*a^6*c^2) - (4*x^2*Sqrt[1 - a^2*x^2])/(3*a^4*c^2) - (5*x^3*Sqrt[1 - a^2*x^2])/(3*a^3*c^2) - ((8 + 15*a*x)*Sqrt[1 - a^2*x^2])/(6*a^6*c^2) + (5*ArcSin[a*x])/(2*a^6*c^2)}
{x^4*E^ArcTanh[a*x]/(c - a^2*c*x^2)^2, x, 7, (4*x^2)/(3*a^3*c^2*(1 - a*x)^(3/2)*Sqrt[1 + a*x]) - x^3/(a^2*c^2*(1 - a*x)^(3/2)*Sqrt[1 + a*x]) - (8 + 3*a*x)/(3*a^5*c^2*Sqrt[1 - a*x]*Sqrt[1 + a*x]) + ArcSin[a*x]/(a^5*c^2), (x^4*(1 + a*x))/(3*a*c^2*(1 - a^2*x^2)^(3/2)) - (2*x^3*(1 + 2*a*x))/(3*a^2*c^2*Sqrt[1 - a^2*x^2]) - (4*Sqrt[1 - a^2*x^2])/(3*a^5*c^2) - (4*x^2*Sqrt[1 - a^2*x^2])/(3*a^3*c^2) - ((4 + 3*a*x)*Sqrt[1 - a^2*x^2])/(3*a^5*c^2) + ArcSin[a*x]/(a^5*c^2)}
{x^3*E^ArcTanh[a*x]/(c - a^2*c*x^2)^2, x, 6, (x^3*(1 + a*x))/(3*a*c^2*(1 - a^2*x^2)^(3/2)) - (x^2*(1 + 3*a*x))/(3*a^2*c^2*Sqrt[1 - a^2*x^2]) - Sqrt[1 - a^2*x^2]/(3*a^4*c^2) - ((1 + 3*a*x)*Sqrt[1 - a^2*x^2])/(3*a^4*c^2) + ArcSin[a*x]/(a^4*c^2)}
{x^2*E^ArcTanh[a*x]/(c - a^2*c*x^2)^2, x, 4, (x^2*(1 + a*x))/(3*a*c^2*(1 - a^2*x^2)^(3/2)) - 2/(3*a^3*c^2*Sqrt[1 - a^2*x^2])}
{x^1*E^ArcTanh[a*x]/(c - a^2*c*x^2)^2, x, 3, (1 + a*x)/(3*a^2*c^2*(1 - a^2*x^2)^(3/2)) - x/(3*a*c^2*Sqrt[1 - a^2*x^2])}
{x^0*E^ArcTanh[a*x]/(c - a^2*c*x^2)^2, x, 3, (1 + a*x)/(3*a*c^2*(1 - a^2*x^2)^(3/2)) + (2*x)/(3*c^2*Sqrt[1 - a^2*x^2])}
{E^ArcTanh[a*x]/(x^1*(c - a^2*c*x^2)^2), x, 6, (1 + a*x)/(3*c^2*(1 - a^2*x^2)^(3/2)) + (3 + 2*a*x)/(3*c^2*Sqrt[1 - a^2*x^2]) - ArcTanh[Sqrt[1 - a^2*x^2]]/c^2}
{E^ArcTanh[a*x]/(x^2*(c - a^2*c*x^2)^2), x, 7, (1 + a*x)/(3*c^2*x*(1 - a^2*x^2)^(3/2)) + (4 + 3*a*x)/(3*c^2*x*Sqrt[1 - a^2*x^2]) - (8*Sqrt[1 - a^2*x^2])/(3*c^2*x) - (a*ArcTanh[Sqrt[1 - a^2*x^2]])/c^2}
{E^ArcTanh[a*x]/(x^3*(c - a^2*c*x^2)^2), x, 8, (1 + a*x)/(3*c^2*x^2*(1 - a^2*x^2)^(3/2)) + (5 + 4*a*x)/(3*c^2*x^2*Sqrt[1 - a^2*x^2]) - (5*Sqrt[1 - a^2*x^2])/(2*c^2*x^2) - (8*a*Sqrt[1 - a^2*x^2])/(3*c^2*x) - (5*a^2*ArcTanh[Sqrt[1 - a^2*x^2]])/(2*c^2)}
{E^ArcTanh[a*x]/(x^4*(c - a^2*c*x^2)^2), x, 9, (1 + a*x)/(3*c^2*x^3*(1 - a^2*x^2)^(3/2)) + (6 + 5*a*x)/(3*c^2*x^3*Sqrt[1 - a^2*x^2]) - (8*Sqrt[1 - a^2*x^2])/(3*c^2*x^3) - (5*a*Sqrt[1 - a^2*x^2])/(2*c^2*x^2) - (16*a^2*Sqrt[1 - a^2*x^2])/(3*c^2*x) - (5*a^3*ArcTanh[Sqrt[1 - a^2*x^2]])/(2*c^2)}


{x^m*E^ArcTanh[a*x]/(c - a^2*c*x^2)^3, x, 8, (x^(1 + m)*(1 + a*x))/(5*c^3*(1 - a^2*x^2)^(5/2)) + (x^(1 + m)*(4 - m + a*(3 - m)*x))/(15*c^3*(1 - a^2*x^2)^(3/2)) + (x^(1 + m)*((2 - m)*(4 - m) + a*(1 - m)*(3 - m)*x))/(15*c^3*Sqrt[1 - a^2*x^2]) - ((2 - m)*(4 - m)*m*x^(1 + m)*Hypergeometric2F1[1/2, (1 + m)/2, (3 + m)/2, a^2*x^2])/(15*c^3*(1 + m)) - (a*(1 - m)*(3 - m)*(1 + m)*x^(2 + m)*Hypergeometric2F1[1/2, (2 + m)/2, (4 + m)/2, a^2*x^2])/(15*c^3*(2 + m))}

{x^7*E^ArcTanh[a*x]/(c - a^2*c*x^2)^3, x, 10, (x^7*(1 + a*x))/(5*a*c^3*(1 - a^2*x^2)^(5/2)) - (x^6*(3 + 7*a*x))/(15*a^2*c^3*(1 - a^2*x^2)^(3/2)) + (2*x^5*(14 + 9*a*x))/(15*a^3*c^3*Sqrt[1 - a^2*x^2]) + (8*Sqrt[1 - a^2*x^2])/(5*a^8*c^3) + (8*x^2*Sqrt[1 - a^2*x^2])/(5*a^6*c^3) + (7*x^3*Sqrt[1 - a^2*x^2])/(3*a^5*c^3) + (6*x^4*Sqrt[1 - a^2*x^2])/(5*a^4*c^3) + ((16 + 35*a*x)*Sqrt[1 - a^2*x^2])/(10*a^8*c^3) - (7*ArcSin[a*x])/(2*a^8*c^3)}
{x^6*E^ArcTanh[a*x]/(c - a^2*c*x^2)^3, x, 9, (x^6*(1 + a*x))/(5*a*c^3*(1 - a^2*x^2)^(5/2)) - (2*x^5*(1 + 3*a*x))/(15*a^2*c^3*(1 - a^2*x^2)^(3/2)) + (2*x^4*(9 + 5*a*x))/(15*a^3*c^3*Sqrt[1 - a^2*x^2]) + (8*Sqrt[1 - a^2*x^2])/(5*a^7*c^3) + (8*x^2*Sqrt[1 - a^2*x^2])/(5*a^5*c^3) + (2*x^3*Sqrt[1 - a^2*x^2])/(3*a^4*c^3) + ((8 + 5*a*x)*Sqrt[1 - a^2*x^2])/(5*a^7*c^3) - ArcSin[a*x]/(a^7*c^3)}
{x^5*E^ArcTanh[a*x]/(c - a^2*c*x^2)^3, x, 8, (x^5*(1 + a*x))/(5*a*c^3*(1 - a^2*x^2)^(5/2)) - (x^4*(1 + 5*a*x))/(15*a^2*c^3*(1 - a^2*x^2)^(3/2)) + (2*x^3*(5 + 2*a*x))/(15*a^3*c^3*Sqrt[1 - a^2*x^2]) + (4*Sqrt[1 - a^2*x^2])/(15*a^6*c^3) + (4*x^2*Sqrt[1 - a^2*x^2])/(15*a^4*c^3) + ((4 + 15*a*x)*Sqrt[1 - a^2*x^2])/(15*a^6*c^3) - ArcSin[a*x]/(a^6*c^3)}
{x^4*E^ArcTanh[a*x]/(c - a^2*c*x^2)^3, x, 6, (x^4*(1 + a*x))/(5*a*c^3*(1 - a^2*x^2)^(5/2)) - 4/(15*a^5*c^3*(1 - a^2*x^2)^(3/2)) + 4/(5*a^5*c^3*Sqrt[1 - a^2*x^2])}
{x^3*E^ArcTanh[a*x]/(c - a^2*c*x^2)^3, x, 5, (x^3*(1 + a*x))/(5*a*c^3*(1 - a^2*x^2)^(5/2)) + (x^2*(1 - 3*a*x))/(15*a^2*c^3*(1 - a^2*x^2)^(3/2)) - 2/(15*a^4*c^3*Sqrt[1 - a^2*x^2])}
{x^2*E^ArcTanh[a*x]/(c - a^2*c*x^2)^3, x, 4, (x^2*(1 + a*x))/(5*a*c^3*(1 - a^2*x^2)^(5/2)) - (2*(1 - a*x))/(15*a^3*c^3*(1 - a^2*x^2)^(3/2)) - (2*x)/(15*a^2*c^3*Sqrt[1 - a^2*x^2])}
{x^1*E^ArcTanh[a*x]/(c - a^2*c*x^2)^3, x, 4, (1 + a*x)/(5*a^2*c^3*(1 - a^2*x^2)^(5/2)) - x/(15*a*c^3*(1 - a^2*x^2)^(3/2)) - (2*x)/(15*a*c^3*Sqrt[1 - a^2*x^2])}
{x^0*E^ArcTanh[a*x]/(c - a^2*c*x^2)^3, x, 4, (1 + a*x)/(5*a*c^3*(1 - a^2*x^2)^(5/2)) + (4*x)/(15*c^3*(1 - a^2*x^2)^(3/2)) + (8*x)/(15*c^3*Sqrt[1 - a^2*x^2])}
{E^ArcTanh[a*x]/(x*(c - a^2*c*x^2)^3), x, 7, (1 + a*x)/(5*c^3*(1 - a^2*x^2)^(5/2)) + (5 + 4*a*x)/(15*c^3*(1 - a^2*x^2)^(3/2)) + (15 + 8*a*x)/(15*c^3*Sqrt[1 - a^2*x^2]) - ArcTanh[Sqrt[1 - a^2*x^2]]/c^3}
{E^ArcTanh[a*x]/(x^2*(c - a^2*c*x^2)^3), x, 8, (1 + a*x)/(5*c^3*x*(1 - a^2*x^2)^(5/2)) + (6 + 5*a*x)/(15*c^3*x*(1 - a^2*x^2)^(3/2)) + (8 + 5*a*x)/(5*c^3*x*Sqrt[1 - a^2*x^2]) - (16*Sqrt[1 - a^2*x^2])/(5*c^3*x) - (a*ArcTanh[Sqrt[1 - a^2*x^2]])/c^3}
{E^ArcTanh[a*x]/(x^3*(c - a^2*c*x^2)^3), x, 9, (1 + a*x)/(5*c^3*x^2*(1 - a^2*x^2)^(5/2)) + (7 + 6*a*x)/(15*c^3*x^2*(1 - a^2*x^2)^(3/2)) + (35 + 24*a*x)/(15*c^3*x^2*Sqrt[1 - a^2*x^2]) - (7*Sqrt[1 - a^2*x^2])/(2*c^3*x^2) - (16*a*Sqrt[1 - a^2*x^2])/(5*c^3*x) - (7*a^2*ArcTanh[Sqrt[1 - a^2*x^2]])/(2*c^3)}


{E^ArcTanh[a*x]/(c - c*a^2*x^2)^4, x, 5, (1 + a*x)/(7*a*c^4*(1 - a^2*x^2)^(7/2)) + (6*x)/(35*c^4*(1 - a^2*x^2)^(5/2)) + (8*x)/(35*c^4*(1 - a^2*x^2)^(3/2)) + (16*x)/(35*c^4*Sqrt[1 - a^2*x^2])}


{E^ArcTanh[a*x]/(c - c*a^2*x^2)^5, x, 6, (1 + a*x)/(9*a*c^5*(1 - a^2*x^2)^(9/2)) + (8*x)/(63*c^5*(1 - a^2*x^2)^(7/2)) + (16*x)/(105*c^5*(1 - a^2*x^2)^(5/2)) + (64*x)/(315*c^5*(1 - a^2*x^2)^(3/2)) + (128*x)/(315*c^5*Sqrt[1 - a^2*x^2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^ArcTanh[a x] (1-a^2 x^2)^(p/2)*)


(* ::Subsubsection:: *)
(*p>0*)


(* ::Subsubsection::Closed:: *)
(*p<0*)


{(E^ArcTanh[a*x]*x^m)/Sqrt[1 - a^2*x^2], x, 2, (x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, a*x])/(1 + m)}

{(E^ArcTanh[a*x]*x^4)/Sqrt[1 - a^2*x^2], x, 3, -(x/a^4) - x^2/(2*a^3) - x^3/(3*a^2) - x^4/(4*a) - Log[1 - a*x]/a^5}
{(E^ArcTanh[a*x]*x^3)/Sqrt[1 - a^2*x^2], x, 3, -(x/a^3) - x^2/(2*a^2) - x^3/(3*a) - Log[1 - a*x]/a^4}
{(E^ArcTanh[a*x]*x^2)/Sqrt[1 - a^2*x^2], x, 3, -(x/a^2) - x^2/(2*a) - Log[1 - a*x]/a^3}
{(E^ArcTanh[a*x]*x)/Sqrt[1 - a^2*x^2], x, 3, -(x/a) - Log[1 - a*x]/a^2}
{E^ArcTanh[a*x]/Sqrt[1 - a^2*x^2], x, 3, -(Log[1 - a*x]/a)}
{E^ArcTanh[a*x]/(x*Sqrt[1 - a^2*x^2]), x, 3, Log[x] - Log[1 - a*x]}
{E^ArcTanh[a*x]/(x^2*Sqrt[1 - a^2*x^2]), x, 3, -x^(-1) + a*Log[x] - a*Log[1 - a*x]}
{E^ArcTanh[a*x]/(x^3*Sqrt[1 - a^2*x^2]), x, 3, -1/(2*x^2) - a/x + a^2*Log[x] - a^2*Log[1 - a*x]}
{E^ArcTanh[a*x]/(x^4*Sqrt[1 - a^2*x^2]), x, 3, -1/(3*x^3) - a/(2*x^2) - a^2/x + a^3*Log[x] - a^3*Log[1 - a*x]}


{(E^ArcTanh[a*x]*x^m)/(1 - a^2*x^2)^(3/2), x, 7, x^(1 + m)/(2*(1 - a*x)) + (x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, (-a)*x])/(4*(1 + m)) + (x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, a*x])/(4*(1 + m)) - (m*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, a*x])/(2*(1 + m))}

{(E^ArcTanh[a*x]*x^4)/(1 - a^2*x^2)^(3/2), x, 3, x/a^4 + x^2/(2*a^3) + 1/(2*a^5*(1 - a*x)) + (7*Log[1 - a*x])/(4*a^5) + Log[1 + a*x]/(4*a^5)}
{(E^ArcTanh[a*x]*x^3)/(1 - a^2*x^2)^(3/2), x, 3, x/a^3 + 1/(2*a^4*(1 - a*x)) + (5*Log[1 - a*x])/(4*a^4) - Log[1 + a*x]/(4*a^4)}
{(E^ArcTanh[a*x]*x^2)/(1 - a^2*x^2)^(3/2), x, 3, 1/(2*a^3*(1 - a*x)) + (3*Log[1 - a*x])/(4*a^3) + Log[1 + a*x]/(4*a^3)}
{(E^ArcTanh[a*x]*x)/(1 - a^2*x^2)^(3/2), x, 4, 1/(2*a^2*(1 - a*x)) - ArcTanh[a*x]/(2*a^2)}
{E^ArcTanh[a*x]/(1 - a^2*x^2)^(3/2), x, 5, 1/(2*a*(1 - a*x)) + ArcTanh[a*x]/(2*a)}
{E^ArcTanh[a*x]/(x*(1 - a^2*x^2)^(3/2)), x, 3, 1/(2*(1 - a*x)) + Log[x] - (3*Log[1 - a*x])/4 - Log[1 + a*x]/4}
{E^ArcTanh[a*x]/(x^2*(1 - a^2*x^2)^(3/2)), x, 3, -x^(-1) + a/(2*(1 - a*x)) + a*Log[x] - (5*a*Log[1 - a*x])/4 + (a*Log[1 + a*x])/4}
{E^ArcTanh[a*x]/(x^3*(1 - a^2*x^2)^(3/2)), x, 3, -1/(2*x^2) - a/x + a^2/(2*(1 - a*x)) + 2*a^2*Log[x] - (7*a^2*Log[1 - a*x])/4 - (a^2*Log[1 + a*x])/4}
{E^ArcTanh[a*x]/(x^4*(1 - a^2*x^2)^(3/2)), x, 3, -1/(3*x^3) - a/(2*x^2) - (2*a^2)/x + a^3/(2*(1 - a*x)) + 2*a^3*Log[x] - (9*a^3*Log[1 - a*x])/4 + (a^3*Log[1 + a*x])/4}


{(E^ArcTanh[a*x]*x^m)/(1 - a^2*x^2)^(5/2), x, 12, x^(1 + m)/(8*(1 - a*x)^2) + x^(1 + m)/(4*(1 - a*x)) + ((1 - m)*x^(1 + m))/(8*(1 - a*x)) + x^(1 + m)/(8*(1 + a*x)) + (3*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, (-a)*x])/(16*(1 + m)) - (m*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, (-a)*x])/(8*(1 + m)) + (3*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, a*x])/(16*(1 + m)) - (m*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, a*x])/(4*(1 + m)) - ((1 - m)*m*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, a*x])/(8*(1 + m))}

{(E^ArcTanh[a*x]*x^6)/(1 - a^2*x^2)^(5/2), x, 3, -(x/a^6) - x^2/(2*a^5) + 1/(8*a^7*(1 - a*x)^2) - 5/(4*a^7*(1 - a*x)) - 1/(8*a^7*(1 + a*x)) - (39*Log[1 - a*x])/(16*a^7) - (9*Log[1 + a*x])/(16*a^7)}
{(E^ArcTanh[a*x]*x^5)/(1 - a^2*x^2)^(5/2), x, 3, -(x/a^5) + 1/(8*a^6*(1 - a*x)^2) - 1/(a^6*(1 - a*x)) + 1/(8*a^6*(1 + a*x)) - (23*Log[1 - a*x])/(16*a^6) + (7*Log[1 + a*x])/(16*a^6)}
{(E^ArcTanh[a*x]*x^4)/(1 - a^2*x^2)^(5/2), x, 3, 1/(8*a^5*(1 - a*x)^2) - 3/(4*a^5*(1 - a*x)) - 1/(8*a^5*(1 + a*x)) - (11*Log[1 - a*x])/(16*a^5) - (5*Log[1 + a*x])/(16*a^5)}
{(E^ArcTanh[a*x]*x^3)/(1 - a^2*x^2)^(5/2), x, 4, 1/(8*a^4*(1 - a*x)^2) - 1/(2*a^4*(1 - a*x)) + 1/(8*a^4*(1 + a*x)) + (3*ArcTanh[a*x])/(8*a^4)}
{(E^ArcTanh[a*x]*x^2)/(1 - a^2*x^2)^(5/2), x, 4, 1/(8*a^3*(1 - a*x)^2) - 1/(4*a^3*(1 - a*x)) - 1/(8*a^3*(1 + a*x)) - ArcTanh[a*x]/(8*a^3)}
{(E^ArcTanh[a*x]*x)/(1 - a^2*x^2)^(5/2), x, 4, 1/(8*a^2*(1 - a*x)^2) + 1/(8*a^2*(1 + a*x)) - ArcTanh[a*x]/(8*a^2)}
{E^ArcTanh[a*x]/(1 - a^2*x^2)^(5/2), x, 5, 1/(8*a*(1 - a*x)^2) + 1/(4*a*(1 - a*x)) - 1/(8*a*(1 + a*x)) + (3*ArcTanh[a*x])/(8*a)}
{E^ArcTanh[a*x]/(x*(1 - a^2*x^2)^(5/2)), x, 3, 1/(8*(1 - a*x)^2) + 1/(2*(1 - a*x)) + 1/(8*(1 + a*x)) + Log[x] - (11*Log[1 - a*x])/16 - (5*Log[1 + a*x])/16}
{E^ArcTanh[a*x]/(x^2*(1 - a^2*x^2)^(5/2)), x, 3, -x^(-1) + a/(8*(1 - a*x)^2) + (3*a)/(4*(1 - a*x)) - a/(8*(1 + a*x)) + a*Log[x] - (23*a*Log[1 - a*x])/16 + (7*a*Log[1 + a*x])/16}
{E^ArcTanh[a*x]/(x^3*(1 - a^2*x^2)^(5/2)), x, 3, -1/(2*x^2) - a/x + a^2/(8*(1 - a*x)^2) + a^2/(1 - a*x) + a^2/(8*(1 + a*x)) + 3*a^2*Log[x] - (39*a^2*Log[1 - a*x])/16 - (9*a^2*Log[1 + a*x])/16}
{E^ArcTanh[a*x]/(x^4*(1 - a^2*x^2)^(5/2)), x, 3, -1/(3*x^3) - a/(2*x^2) - (3*a^2)/x + a^3/(8*(1 - a*x)^2) + (5*a^3)/(4*(1 - a*x)) - a^3/(8*(1 + a*x)) + 3*a^3*Log[x] - (59*a^3*Log[1 - a*x])/16 + (11*a^3*Log[1 + a*x])/16}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^ArcTanh[a x] (c-c a^2 x^2)^(p/2)*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{E^ArcTanh[a*x]*(c - c*a^2*x^2)^(1/2)*x^m, x, 4, (x^(1 + m)*Sqrt[c - a^2*c*x^2])/((1 + m)*Sqrt[1 - a^2*x^2]) + (a*x^(2 + m)*Sqrt[c - a^2*c*x^2])/((2 + m)*Sqrt[1 - a^2*x^2])}

{E^ArcTanh[a*x]*(c - c*a^2*x^2)^(1/2)*x^2, x, 4, (x^3*Sqrt[c - a^2*c*x^2])/(3*Sqrt[1 - a^2*x^2]) + (a*x^4*Sqrt[c - a^2*c*x^2])/(4*Sqrt[1 - a^2*x^2])}
{E^ArcTanh[a*x]*(c - c*a^2*x^2)^(1/2)*x^1, x, 4, (x^2*Sqrt[c - a^2*c*x^2])/(2*Sqrt[1 - a^2*x^2]) + (a*x^3*Sqrt[c - a^2*c*x^2])/(3*Sqrt[1 - a^2*x^2])}
{E^ArcTanh[a*x]*(c - c*a^2*x^2)^(1/2)*x^0, x, 3, (x*Sqrt[c - a^2*c*x^2])/Sqrt[1 - a^2*x^2] + (a*x^2*Sqrt[c - a^2*c*x^2])/(2*Sqrt[1 - a^2*x^2])}
{E^ArcTanh[a*x]*(c - c*a^2*x^2)^(1/2)/x^1, x, 4, (a*x*Sqrt[c - a^2*c*x^2])/Sqrt[1 - a^2*x^2] + (Sqrt[c - a^2*c*x^2]*Log[x])/Sqrt[1 - a^2*x^2]}
{E^ArcTanh[a*x]*(c - c*a^2*x^2)^(1/2)/x^2, x, 4, -(Sqrt[c - a^2*c*x^2]/(x*Sqrt[1 - a^2*x^2])) + (a*Sqrt[c - a^2*c*x^2]*Log[x])/Sqrt[1 - a^2*x^2]}


{E^ArcTanh[a*x]*(c - c*a^2*x^2)^(9/2), x, 5, (8*c^4*(1 + a*x)^6*Sqrt[c - a^2*c*x^2])/(3*a*Sqrt[1 - a^2*x^2]) - (32*c^4*(1 + a*x)^7*Sqrt[c - a^2*c*x^2])/(7*a*Sqrt[1 - a^2*x^2]) + (3*c^4*(1 + a*x)^8*Sqrt[c - a^2*c*x^2])/(a*Sqrt[1 - a^2*x^2]) - (8*c^4*(1 + a*x)^9*Sqrt[c - a^2*c*x^2])/(9*a*Sqrt[1 - a^2*x^2]) + (c^4*(1 + a*x)^10*Sqrt[c - a^2*c*x^2])/(10*a*Sqrt[1 - a^2*x^2])}


{E^ArcTanh[a*x]*(c - c*a^2*x^2)^(7/2), x, 5, (8*c^3*(1 + a*x)^5*Sqrt[c - a^2*c*x^2])/(5*a*Sqrt[1 - a^2*x^2]) - (2*c^3*(1 + a*x)^6*Sqrt[c - a^2*c*x^2])/(a*Sqrt[1 - a^2*x^2]) + (6*c^3*(1 + a*x)^7*Sqrt[c - a^2*c*x^2])/(7*a*Sqrt[1 - a^2*x^2]) - (c^3*(1 + a*x)^8*Sqrt[c - a^2*c*x^2])/(8*a*Sqrt[1 - a^2*x^2])}


{E^ArcTanh[a*x]*(c - c*a^2*x^2)^(5/2), x, 5, (c^2*(1 + a*x)^4*Sqrt[c - a^2*c*x^2])/(a*Sqrt[1 - a^2*x^2]) - (4*c^2*(1 + a*x)^5*Sqrt[c - a^2*c*x^2])/(5*a*Sqrt[1 - a^2*x^2]) + (c^2*(1 + a*x)^6*Sqrt[c - a^2*c*x^2])/(6*a*Sqrt[1 - a^2*x^2])}


{E^ArcTanh[a*x]*(c - c*a^2*x^2)^(3/2), x, 5, (c*x*Sqrt[c - a^2*c*x^2])/Sqrt[1 - a^2*x^2] + (a*c*x^2*Sqrt[c - a^2*c*x^2])/(2*Sqrt[1 - a^2*x^2]) - (a^2*c*x^3*Sqrt[c - a^2*c*x^2])/(3*Sqrt[1 - a^2*x^2]) - (a^3*c*x^4*Sqrt[c - a^2*c*x^2])/(4*Sqrt[1 - a^2*x^2])}


(* ::Subsubsection::Closed:: *)
(*p<0*)


{(E^ArcTanh[a*x]*x^m)/Sqrt[c - a^2*c*x^2], x, 3, (x^(1 + m)*Sqrt[1 - a^2*x^2]*Hypergeometric2F1[1, 1 + m, 2 + m, a*x])/((1 + m)*Sqrt[c - a^2*c*x^2])}

{(E^ArcTanh[a*x]*x^4)/Sqrt[c - a^2*c*x^2], x, 4, -((x*Sqrt[1 - a^2*x^2])/(a^4*Sqrt[c - a^2*c*x^2])) - (x^2*Sqrt[1 - a^2*x^2])/(2*a^3*Sqrt[c - a^2*c*x^2]) - (x^3*Sqrt[1 - a^2*x^2])/(3*a^2*Sqrt[c - a^2*c*x^2]) - (x^4*Sqrt[1 - a^2*x^2])/(4*a*Sqrt[c - a^2*c*x^2]) - (Sqrt[1 - a^2*x^2]*Log[1 - a*x])/(a^5*Sqrt[c - a^2*c*x^2])}
{(E^ArcTanh[a*x]*x^3)/Sqrt[c - a^2*c*x^2], x, 4, -((x*Sqrt[1 - a^2*x^2])/(a^3*Sqrt[c - a^2*c*x^2])) - (x^2*Sqrt[1 - a^2*x^2])/(2*a^2*Sqrt[c - a^2*c*x^2]) - (x^3*Sqrt[1 - a^2*x^2])/(3*a*Sqrt[c - a^2*c*x^2]) - (Sqrt[1 - a^2*x^2]*Log[1 - a*x])/(a^4*Sqrt[c - a^2*c*x^2])}
{(E^ArcTanh[a*x]*x^2)/Sqrt[c - a^2*c*x^2], x, 4, -((x*Sqrt[1 - a^2*x^2])/(a^2*Sqrt[c - a^2*c*x^2])) - (x^2*Sqrt[1 - a^2*x^2])/(2*a*Sqrt[c - a^2*c*x^2]) - (Sqrt[1 - a^2*x^2]*Log[1 - a*x])/(a^3*Sqrt[c - a^2*c*x^2])}
{(E^ArcTanh[a*x]*x)/Sqrt[c - a^2*c*x^2], x, 4, -((x*Sqrt[1 - a^2*x^2])/(a*Sqrt[c - a^2*c*x^2])) - (Sqrt[1 - a^2*x^2]*Log[1 - a*x])/(a^2*Sqrt[c - a^2*c*x^2])}
{E^ArcTanh[a*x]/Sqrt[c - a^2*c*x^2], x, 4, -((Sqrt[1 - a^2*x^2]*Log[1 - a*x])/(a*Sqrt[c - a^2*c*x^2]))}
{E^ArcTanh[a*x]/(x*Sqrt[c - a^2*c*x^2]), x, 4, (Sqrt[1 - a^2*x^2]*Log[x])/Sqrt[c - a^2*c*x^2] - (Sqrt[1 - a^2*x^2]*Log[1 - a*x])/Sqrt[c - a^2*c*x^2]}
{E^ArcTanh[a*x]/(x^2*Sqrt[c - a^2*c*x^2]), x, 4, -(Sqrt[1 - a^2*x^2]/(x*Sqrt[c - a^2*c*x^2])) + (a*Sqrt[1 - a^2*x^2]*Log[x])/Sqrt[c - a^2*c*x^2] - (a*Sqrt[1 - a^2*x^2]*Log[1 - a*x])/Sqrt[c - a^2*c*x^2]}
{E^ArcTanh[a*x]/(x^3*Sqrt[c - a^2*c*x^2]), x, 4, -Sqrt[1 - a^2*x^2]/(2*x^2*Sqrt[c - a^2*c*x^2]) - (a*Sqrt[1 - a^2*x^2])/(x*Sqrt[c - a^2*c*x^2]) + (a^2*Sqrt[1 - a^2*x^2]*Log[x])/Sqrt[c - a^2*c*x^2] - (a^2*Sqrt[1 - a^2*x^2]*Log[1 - a*x])/Sqrt[c - a^2*c*x^2]}
{E^ArcTanh[a*x]/(x^4*Sqrt[c - a^2*c*x^2]), x, 4, -Sqrt[1 - a^2*x^2]/(3*x^3*Sqrt[c - a^2*c*x^2]) - (a*Sqrt[1 - a^2*x^2])/(2*x^2*Sqrt[c - a^2*c*x^2]) - (a^2*Sqrt[1 - a^2*x^2])/(x*Sqrt[c - a^2*c*x^2]) + (a^3*Sqrt[1 - a^2*x^2]*Log[x])/Sqrt[c - a^2*c*x^2] - (a^3*Sqrt[1 - a^2*x^2]*Log[1 - a*x])/Sqrt[c - a^2*c*x^2]}


{(E^ArcTanh[a*x]*x^m)/(c - a^2*c*x^2)^(3/2), x, 8, (x^(1 + m)*Sqrt[1 - a^2*x^2])/(2*c*(1 - a*x)*Sqrt[c - a^2*c*x^2]) + (x^(1 + m)*Sqrt[1 - a^2*x^2]*Hypergeometric2F1[1, 1 + m, 2 + m, (-a)*x])/(4*c*(1 + m)*Sqrt[c - a^2*c*x^2]) + (x^(1 + m)*Sqrt[1 - a^2*x^2]*Hypergeometric2F1[1, 1 + m, 2 + m, a*x])/(4*c*(1 + m)*Sqrt[c - a^2*c*x^2]) - (m*x^(1 + m)*Sqrt[1 - a^2*x^2]*Hypergeometric2F1[1, 1 + m, 2 + m, a*x])/(2*c*(1 + m)*Sqrt[c - a^2*c*x^2])}

{(E^ArcTanh[a*x]*x^5)/(c - a^2*c*x^2)^(3/2), x, 4, (2*x*Sqrt[1 - a^2*x^2])/(a^5*c*Sqrt[c - a^2*c*x^2]) + (x^2*Sqrt[1 - a^2*x^2])/(2*a^4*c*Sqrt[c - a^2*c*x^2]) + (x^3*Sqrt[1 - a^2*x^2])/(3*a^3*c*Sqrt[c - a^2*c*x^2]) + Sqrt[1 - a^2*x^2]/(2*a^6*c*(1 - a*x)*Sqrt[c - a^2*c*x^2]) + (9*Sqrt[1 - a^2*x^2]*Log[1 - a*x])/(4*a^6*c*Sqrt[c - a^2*c*x^2]) - (Sqrt[1 - a^2*x^2]*Log[1 + a*x])/(4*a^6*c*Sqrt[c - a^2*c*x^2])}
{(E^ArcTanh[a*x]*x^4)/(c - a^2*c*x^2)^(3/2), x, 4, (x*Sqrt[1 - a^2*x^2])/(a^4*c*Sqrt[c - a^2*c*x^2]) + (x^2*Sqrt[1 - a^2*x^2])/(2*a^3*c*Sqrt[c - a^2*c*x^2]) + Sqrt[1 - a^2*x^2]/(2*a^5*c*(1 - a*x)*Sqrt[c - a^2*c*x^2]) + (7*Sqrt[1 - a^2*x^2]*Log[1 - a*x])/(4*a^5*c*Sqrt[c - a^2*c*x^2]) + (Sqrt[1 - a^2*x^2]*Log[1 + a*x])/(4*a^5*c*Sqrt[c - a^2*c*x^2])}
{(E^ArcTanh[a*x]*x^3)/(c - a^2*c*x^2)^(3/2), x, 4, (x*Sqrt[1 - a^2*x^2])/(a^3*c*Sqrt[c - a^2*c*x^2]) + Sqrt[1 - a^2*x^2]/(2*a^4*c*(1 - a*x)*Sqrt[c - a^2*c*x^2]) + (5*Sqrt[1 - a^2*x^2]*Log[1 - a*x])/(4*a^4*c*Sqrt[c - a^2*c*x^2]) - (Sqrt[1 - a^2*x^2]*Log[1 + a*x])/(4*a^4*c*Sqrt[c - a^2*c*x^2])}
{(E^ArcTanh[a*x]*x^2)/(c - a^2*c*x^2)^(3/2), x, 4, Sqrt[1 - a^2*x^2]/(2*a^3*c*(1 - a*x)*Sqrt[c - a^2*c*x^2]) + (3*Sqrt[1 - a^2*x^2]*Log[1 - a*x])/(4*a^3*c*Sqrt[c - a^2*c*x^2]) + (Sqrt[1 - a^2*x^2]*Log[1 + a*x])/(4*a^3*c*Sqrt[c - a^2*c*x^2])}
{(E^ArcTanh[a*x]*x)/(c - a^2*c*x^2)^(3/2), x, 5, Sqrt[1 - a^2*x^2]/(2*a^2*c*(1 - a*x)*Sqrt[c - a^2*c*x^2]) - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(2*a^2*c*Sqrt[c - a^2*c*x^2])}
{E^ArcTanh[a*x]/(c - a^2*c*x^2)^(3/2), x, 6, Sqrt[1 - a^2*x^2]/(2*a*c*(1 - a*x)*Sqrt[c - a^2*c*x^2]) + (Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(2*a*c*Sqrt[c - a^2*c*x^2])}
{E^ArcTanh[a*x]/(x*(c - a^2*c*x^2)^(3/2)), x, 4, Sqrt[1 - a^2*x^2]/(2*c*(1 - a*x)*Sqrt[c - a^2*c*x^2]) + (Sqrt[1 - a^2*x^2]*Log[x])/(c*Sqrt[c - a^2*c*x^2]) - (3*Sqrt[1 - a^2*x^2]*Log[1 - a*x])/(4*c*Sqrt[c - a^2*c*x^2]) - (Sqrt[1 - a^2*x^2]*Log[1 + a*x])/(4*c*Sqrt[c - a^2*c*x^2])}
{E^ArcTanh[a*x]/(x^2*(c - a^2*c*x^2)^(3/2)), x, 4, -(Sqrt[1 - a^2*x^2]/(c*x*Sqrt[c - a^2*c*x^2])) + (a*Sqrt[1 - a^2*x^2])/(2*c*(1 - a*x)*Sqrt[c - a^2*c*x^2]) + (a*Sqrt[1 - a^2*x^2]*Log[x])/(c*Sqrt[c - a^2*c*x^2]) - (5*a*Sqrt[1 - a^2*x^2]*Log[1 - a*x])/(4*c*Sqrt[c - a^2*c*x^2]) + (a*Sqrt[1 - a^2*x^2]*Log[1 + a*x])/(4*c*Sqrt[c - a^2*c*x^2])}
{E^ArcTanh[a*x]/(x^3*(c - a^2*c*x^2)^(3/2)), x, 4, -(Sqrt[1 - a^2*x^2]/(2*c*x^2*Sqrt[c - a^2*c*x^2])) - (a*Sqrt[1 - a^2*x^2])/(c*x*Sqrt[c - a^2*c*x^2]) + (a^2*Sqrt[1 - a^2*x^2])/(2*c*(1 - a*x)*Sqrt[c - a^2*c*x^2]) + (2*a^2*Sqrt[1 - a^2*x^2]*Log[x])/(c*Sqrt[c - a^2*c*x^2]) - (7*a^2*Sqrt[1 - a^2*x^2]*Log[1 - a*x])/(4*c*Sqrt[c - a^2*c*x^2]) - (a^2*Sqrt[1 - a^2*x^2]*Log[1 + a*x])/(4*c*Sqrt[c - a^2*c*x^2])}
{E^ArcTanh[a*x]/(x^4*(c - a^2*c*x^2)^(3/2)), x, 4, -(Sqrt[1 - a^2*x^2]/(3*c*x^3*Sqrt[c - a^2*c*x^2])) - (a*Sqrt[1 - a^2*x^2])/(2*c*x^2*Sqrt[c - a^2*c*x^2]) - (2*a^2*Sqrt[1 - a^2*x^2])/(c*x*Sqrt[c - a^2*c*x^2]) + (a^3*Sqrt[1 - a^2*x^2])/(2*c*(1 - a*x)*Sqrt[c - a^2*c*x^2]) + (2*a^3*Sqrt[1 - a^2*x^2]*Log[x])/(c*Sqrt[c - a^2*c*x^2]) - (9*a^3*Sqrt[1 - a^2*x^2]*Log[1 - a*x])/(4*c*Sqrt[c - a^2*c*x^2]) + (a^3*Sqrt[1 - a^2*x^2]*Log[1 + a*x])/(4*c*Sqrt[c - a^2*c*x^2])}


{(E^ArcTanh[a*x]*x^m)/(c - a^2*c*x^2)^(5/2), x, 13, (x^(1 + m)*Sqrt[1 - a^2*x^2])/(8*c^2*(1 - a*x)^2*Sqrt[c - a^2*c*x^2]) + (x^(1 + m)*Sqrt[1 - a^2*x^2])/(4*c^2*(1 - a*x)*Sqrt[c - a^2*c*x^2]) + ((1 - m)*x^(1 + m)*Sqrt[1 - a^2*x^2])/(8*c^2*(1 - a*x)*Sqrt[c - a^2*c*x^2]) + (x^(1 + m)*Sqrt[1 - a^2*x^2])/(8*c^2*(1 + a*x)*Sqrt[c - a^2*c*x^2]) + (3*x^(1 + m)*Sqrt[1 - a^2*x^2]*Hypergeometric2F1[1, 1 + m, 2 + m, (-a)*x])/(16*c^2*(1 + m)*Sqrt[c - a^2*c*x^2]) - (m*x^(1 + m)*Sqrt[1 - a^2*x^2]*Hypergeometric2F1[1, 1 + m, 2 + m, (-a)*x])/(8*c^2*(1 + m)*Sqrt[c - a^2*c*x^2]) + (3*x^(1 + m)*Sqrt[1 - a^2*x^2]*Hypergeometric2F1[1, 1 + m, 2 + m, a*x])/(16*c^2*(1 + m)*Sqrt[c - a^2*c*x^2]) - (m*x^(1 + m)*Sqrt[1 - a^2*x^2]*Hypergeometric2F1[1, 1 + m, 2 + m, a*x])/(4*c^2*(1 + m)*Sqrt[c - a^2*c*x^2]) - ((1 - m)*m*x^(1 + m)*Sqrt[1 - a^2*x^2]*Hypergeometric2F1[1, 1 + m, 2 + m, a*x])/(8*c^2*(1 + m)*Sqrt[c - a^2*c*x^2])}

{(E^ArcTanh[a*x]*x^6)/(c - a^2*c*x^2)^(5/2), x, 4, -((x*Sqrt[1 - a^2*x^2])/(a^6*c^2*Sqrt[c - a^2*c*x^2])) - (x^2*Sqrt[1 - a^2*x^2])/(2*a^5*c^2*Sqrt[c - a^2*c*x^2]) + Sqrt[1 - a^2*x^2]/(8*a^7*c^2*(1 - a*x)^2*Sqrt[c - a^2*c*x^2]) - (5*Sqrt[1 - a^2*x^2])/(4*a^7*c^2*(1 - a*x)*Sqrt[c - a^2*c*x^2]) - Sqrt[1 - a^2*x^2]/(8*a^7*c^2*(1 + a*x)*Sqrt[c - a^2*c*x^2]) - (39*Sqrt[1 - a^2*x^2]*Log[1 - a*x])/(16*a^7*c^2*Sqrt[c - a^2*c*x^2]) - (9*Sqrt[1 - a^2*x^2]*Log[1 + a*x])/(16*a^7*c^2*Sqrt[c - a^2*c*x^2])}
{(E^ArcTanh[a*x]*x^5)/(c - a^2*c*x^2)^(5/2), x, 4, -((x*Sqrt[1 - a^2*x^2])/(a^5*c^2*Sqrt[c - a^2*c*x^2])) + Sqrt[1 - a^2*x^2]/(8*a^6*c^2*(1 - a*x)^2*Sqrt[c - a^2*c*x^2]) - Sqrt[1 - a^2*x^2]/(a^6*c^2*(1 - a*x)*Sqrt[c - a^2*c*x^2]) + Sqrt[1 - a^2*x^2]/(8*a^6*c^2*(1 + a*x)*Sqrt[c - a^2*c*x^2]) - (23*Sqrt[1 - a^2*x^2]*Log[1 - a*x])/(16*a^6*c^2*Sqrt[c - a^2*c*x^2]) + (7*Sqrt[1 - a^2*x^2]*Log[1 + a*x])/(16*a^6*c^2*Sqrt[c - a^2*c*x^2])}
{(E^ArcTanh[a*x]*x^4)/(c - a^2*c*x^2)^(5/2), x, 4, Sqrt[1 - a^2*x^2]/(8*a^5*c^2*(1 - a*x)^2*Sqrt[c - a^2*c*x^2]) - (3*Sqrt[1 - a^2*x^2])/(4*a^5*c^2*(1 - a*x)*Sqrt[c - a^2*c*x^2]) - Sqrt[1 - a^2*x^2]/(8*a^5*c^2*(1 + a*x)*Sqrt[c - a^2*c*x^2]) - (11*Sqrt[1 - a^2*x^2]*Log[1 - a*x])/(16*a^5*c^2*Sqrt[c - a^2*c*x^2]) - (5*Sqrt[1 - a^2*x^2]*Log[1 + a*x])/(16*a^5*c^2*Sqrt[c - a^2*c*x^2])}
{(E^ArcTanh[a*x]*x^3)/(c - a^2*c*x^2)^(5/2), x, 5, Sqrt[1 - a^2*x^2]/(8*a^4*c^2*(1 - a*x)^2*Sqrt[c - a^2*c*x^2]) - Sqrt[1 - a^2*x^2]/(2*a^4*c^2*(1 - a*x)*Sqrt[c - a^2*c*x^2]) + Sqrt[1 - a^2*x^2]/(8*a^4*c^2*(1 + a*x)*Sqrt[c - a^2*c*x^2]) + (3*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(8*a^4*c^2*Sqrt[c - a^2*c*x^2])}
{(E^ArcTanh[a*x]*x^2)/(c - a^2*c*x^2)^(5/2), x, 5, Sqrt[1 - a^2*x^2]/(8*a^3*c^2*(1 - a*x)^2*Sqrt[c - a^2*c*x^2]) - Sqrt[1 - a^2*x^2]/(4*a^3*c^2*(1 - a*x)*Sqrt[c - a^2*c*x^2]) - Sqrt[1 - a^2*x^2]/(8*a^3*c^2*(1 + a*x)*Sqrt[c - a^2*c*x^2]) - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(8*a^3*c^2*Sqrt[c - a^2*c*x^2])}
{(E^ArcTanh[a*x]*x)/(c - a^2*c*x^2)^(5/2), x, 5, Sqrt[1 - a^2*x^2]/(8*a^2*c^2*(1 - a*x)^2*Sqrt[c - a^2*c*x^2]) + Sqrt[1 - a^2*x^2]/(8*a^2*c^2*(1 + a*x)*Sqrt[c - a^2*c*x^2]) - (Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(8*a^2*c^2*Sqrt[c - a^2*c*x^2])}
{E^ArcTanh[a*x]/(c - a^2*c*x^2)^(5/2), x, 6, Sqrt[1 - a^2*x^2]/(8*a*c^2*(1 - a*x)^2*Sqrt[c - a^2*c*x^2]) + Sqrt[1 - a^2*x^2]/(4*a*c^2*(1 - a*x)*Sqrt[c - a^2*c*x^2]) - Sqrt[1 - a^2*x^2]/(8*a*c^2*(1 + a*x)*Sqrt[c - a^2*c*x^2]) + (3*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(8*a*c^2*Sqrt[c - a^2*c*x^2])}
{E^ArcTanh[a*x]/(x*(c - a^2*c*x^2)^(5/2)), x, 4, Sqrt[1 - a^2*x^2]/(8*c^2*(1 - a*x)^2*Sqrt[c - a^2*c*x^2]) + Sqrt[1 - a^2*x^2]/(2*c^2*(1 - a*x)*Sqrt[c - a^2*c*x^2]) + Sqrt[1 - a^2*x^2]/(8*c^2*(1 + a*x)*Sqrt[c - a^2*c*x^2]) + (Sqrt[1 - a^2*x^2]*Log[x])/(c^2*Sqrt[c - a^2*c*x^2]) - (11*Sqrt[1 - a^2*x^2]*Log[1 - a*x])/(16*c^2*Sqrt[c - a^2*c*x^2]) - (5*Sqrt[1 - a^2*x^2]*Log[1 + a*x])/(16*c^2*Sqrt[c - a^2*c*x^2])}
{E^ArcTanh[a*x]/(x^2*(c - a^2*c*x^2)^(5/2)), x, 4, -(Sqrt[1 - a^2*x^2]/(c^2*x*Sqrt[c - a^2*c*x^2])) + (a*Sqrt[1 - a^2*x^2])/(8*c^2*(1 - a*x)^2*Sqrt[c - a^2*c*x^2]) + (3*a*Sqrt[1 - a^2*x^2])/(4*c^2*(1 - a*x)*Sqrt[c - a^2*c*x^2]) - (a*Sqrt[1 - a^2*x^2])/(8*c^2*(1 + a*x)*Sqrt[c - a^2*c*x^2]) + (a*Sqrt[1 - a^2*x^2]*Log[x])/(c^2*Sqrt[c - a^2*c*x^2]) - (23*a*Sqrt[1 - a^2*x^2]*Log[1 - a*x])/(16*c^2*Sqrt[c - a^2*c*x^2]) + (7*a*Sqrt[1 - a^2*x^2]*Log[1 + a*x])/(16*c^2*Sqrt[c - a^2*c*x^2])}
{E^ArcTanh[a*x]/(x^3*(c - a^2*c*x^2)^(5/2)), x, 4, -(Sqrt[1 - a^2*x^2]/(2*c^2*x^2*Sqrt[c - a^2*c*x^2])) - (a*Sqrt[1 - a^2*x^2])/(c^2*x*Sqrt[c - a^2*c*x^2]) + (a^2*Sqrt[1 - a^2*x^2])/(8*c^2*(1 - a*x)^2*Sqrt[c - a^2*c*x^2]) + (a^2*Sqrt[1 - a^2*x^2])/(c^2*(1 - a*x)*Sqrt[c - a^2*c*x^2]) + (a^2*Sqrt[1 - a^2*x^2])/(8*c^2*(1 + a*x)*Sqrt[c - a^2*c*x^2]) + (3*a^2*Sqrt[1 - a^2*x^2]*Log[x])/(c^2*Sqrt[c - a^2*c*x^2]) - (39*a^2*Sqrt[1 - a^2*x^2]*Log[1 - a*x])/(16*c^2*Sqrt[c - a^2*c*x^2]) - (9*a^2*Sqrt[1 - a^2*x^2]*Log[1 + a*x])/(16*c^2*Sqrt[c - a^2*c*x^2])}


{E^ArcTanh[a*x]/(c - c*a^2*x^2)^(7/2), x, 6, Sqrt[1 - a^2*x^2]/(24*a*c^3*(1 - a*x)^3*Sqrt[c - a^2*c*x^2]) + (3*Sqrt[1 - a^2*x^2])/(32*a*c^3*(1 - a*x)^2*Sqrt[c - a^2*c*x^2]) + (3*Sqrt[1 - a^2*x^2])/(16*a*c^3*(1 - a*x)*Sqrt[c - a^2*c*x^2]) - Sqrt[1 - a^2*x^2]/(32*a*c^3*(1 + a*x)^2*Sqrt[c - a^2*c*x^2]) - Sqrt[1 - a^2*x^2]/(8*a*c^3*(1 + a*x)*Sqrt[c - a^2*c*x^2]) + (5*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(16*a*c^3*Sqrt[c - a^2*c*x^2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^ArcTanh[a x] (c-c a^2 x^2)^p with p symbolic*)


{E^ArcTanh[a*x]*(c - a^2*c*x^2)^p*x^m, x, 6, (x^(1 + m)*(c - a^2*c*x^2)^p*Hypergeometric2F1[(1 + m)/2, 1/2 - p, (3 + m)/2, a^2*x^2])/((1 - a^2*x^2)^p*(1 + m)) + (a*x^(2 + m)*(c - a^2*c*x^2)^p*Hypergeometric2F1[(2 + m)/2, 1/2 - p, (4 + m)/2, a^2*x^2])/((1 - a^2*x^2)^p*(2 + m))}

{E^ArcTanh[a*x]*(c - a^2*c*x^2)^p*x^3, x, 7, -((Sqrt[1 - a^2*x^2]*(c - a^2*c*x^2)^p)/(a^4*(1 + p)*(1 + 2*p)*(3 + 2*p))) - (x^2*Sqrt[1 - a^2*x^2]*(c - a^2*c*x^2)^p)/(a^2*(3 + 2*p)) - (x^3*Sqrt[1 - a^2*x^2]*(c - a^2*c*x^2)^p)/(2*a*(2 + p)) - ((4*(2 + p) + 3*a*(3 + 2*p)*x)*Sqrt[1 - a^2*x^2]*(c - a^2*c*x^2)^p)/(4*a^4*(1 + p)*(2 + p)*(3 + 2*p)) + (3*x*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2, 1/2 - p, 3/2, a^2*x^2])/((1 - a^2*x^2)^p*(4*a^3*(1 + p)*(2 + p)))}
{E^ArcTanh[a*x]*(c - a^2*c*x^2)^p*x^2, x, 6, -((Sqrt[1 - a^2*x^2]*(c - a^2*c*x^2)^p)/(a^3*(3 + 2*p)*(1 + 3*p + 2*p^2))) - (x^2*Sqrt[1 - a^2*x^2]*(c - a^2*c*x^2)^p)/(a*(3 + 2*p)) - ((2 + a*(3 + 2*p)*x)*Sqrt[1 - a^2*x^2]*(c - a^2*c*x^2)^p)/(2*a^3*(1 + p)*(3 + 2*p)) + (x*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2, 1/2 - p, 3/2, a^2*x^2])/((1 - a^2*x^2)^p*(2*a^2*(1 + p)))}
{E^ArcTanh[a*x]*(c - a^2*c*x^2)^p*x^1, x, 5, -((Sqrt[1 - a^2*x^2]*(c - a^2*c*x^2)^p)/(2*a^2*(1 + p)*(1 + 2*p))) - ((1 + a*x)*Sqrt[1 - a^2*x^2]*(c - a^2*c*x^2)^p)/(2*a^2*(1 + p)) + (x*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2, 1/2 - p, 3/2, a^2*x^2])/((1 - a^2*x^2)^p*(2*a*(1 + p)))}
{E^ArcTanh[a*x]*(c - a^2*c*x^2)^p*x^0, x, 4, -((Sqrt[1 - a^2*x^2]*(c - a^2*c*x^2)^p)/(a*(1 + 2*p))) + (x*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2, 1/2 - p, 3/2, a^2*x^2])/(1 - a^2*x^2)^p}
{E^ArcTanh[a*x]*(c - a^2*c*x^2)^p/x^1, x, 6, (a*x*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2, 1/2 - p, 3/2, a^2*x^2])/(1 - a^2*x^2)^p - ((-((1 - a^2*x^2)/(a^2*x^2)))^(1/2 - p)*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2 - p, 1/2 - p, 3/2 - p, 1/(a^2*x^2)])/((1 - 2*p)*Sqrt[1 - a^2*x^2])}
{E^ArcTanh[a*x]*(c - a^2*c*x^2)^p/x^2, x, 7, -((Sqrt[1 - a^2*x^2]*(c - a^2*c*x^2)^p)/x) - (2*a^2*p*x*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2, 1/2 - p, 3/2, a^2*x^2])/(1 - a^2*x^2)^p - (a*(-((1 - a^2*x^2)/(a^2*x^2)))^(1/2 - p)*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2 - p, 1/2 - p, 3/2 - p, 1/(a^2*x^2)])/((1 - 2*p)*Sqrt[1 - a^2*x^2])}
{E^ArcTanh[a*x]*(c - a^2*c*x^2)^p/x^3, x, 8, -((Sqrt[1 - a^2*x^2]*(c - a^2*c*x^2)^p)/(2*x^2)) - (a*Sqrt[1 - a^2*x^2]*(c - a^2*c*x^2)^p)/x - (2*a^3*p*x*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2, 1/2 - p, 3/2, a^2*x^2])/(1 - a^2*x^2)^p - (a^2*(-((1 - a^2*x^2)/(a^2*x^2)))^(1/2 - p)*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2 - p, 1/2 - p, 3/2 - p, 1/(a^2*x^2)])/(2*Sqrt[1 - a^2*x^2])}


(* ::Section::Closed:: *)
(*Integrands of the form x^m E^(2 ArcTanh[a x]) (c-c a^2 x^2)^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(2 ArcTanh[a x]) (c-c a^2 x^2)^p*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{E^(2*ArcTanh[a*x])*x^m*(c - a^2*c*x^2), x, 3, (c*x^(1 + m))/(1 + m) + (2*a*c*x^(2 + m))/(2 + m) + (a^2*c*x^(3 + m))/(3 + m)}

{E^(2*ArcTanh[a*x])*x^4*(c - a^2*c*x^2), x, 3, (c*x^5)/5 + (a*c*x^6)/3 + (a^2*c*x^7)/7}
{E^(2*ArcTanh[a*x])*x^3*(c - a^2*c*x^2), x, 3, (c*x^4)/4 + (2*a*c*x^5)/5 + (a^2*c*x^6)/6}
{E^(2*ArcTanh[a*x])*x^2*(c - a^2*c*x^2), x, 3, (c*x^3)/3 + (a*c*x^4)/2 + (a^2*c*x^5)/5}
{E^(2*ArcTanh[a*x])*x*(c - a^2*c*x^2), x, 3, (c*x^2)/2 + (2*a*c*x^3)/3 + (a^2*c*x^4)/4}
{E^(2*ArcTanh[a*x])*(c - a^2*c*x^2), x, 2, (c*(1 + a*x)^3)/(3*a)}
{(E^(2*ArcTanh[a*x])*(c - a^2*c*x^2))/x, x, 3, 2*a*c*x + (a^2*c*x^2)/2 + c*Log[x]}
{(E^(2*ArcTanh[a*x])*(c - a^2*c*x^2))/x^2, x, 3, -(c/x) + a^2*c*x + 2*a*c*Log[x]}
{(E^(2*ArcTanh[a*x])*(c - a^2*c*x^2))/x^3, x, 3, -c/(2*x^2) - (2*a*c)/x + a^2*c*Log[x]}
{(E^(2*ArcTanh[a*x])*(c - a^2*c*x^2))/x^4, x, 2, -(c*(1 + a*x)^3)/(3*x^3)}


{E^(2*ArcTanh[a*x])*x^m*(c - a^2*c*x^2)^2, x, 3, (c^2*x^(1 + m))/(1 + m) + (2*a*c^2*x^(2 + m))/(2 + m) - (2*a^3*c^2*x^(4 + m))/(4 + m) - (a^4*c^2*x^(5 + m))/(5 + m)}

{E^(2*ArcTanh[a*x])*x^4*(c - a^2*c*x^2)^2, x, 3, (c^2*x^5)/5 + (a*c^2*x^6)/3 - (a^3*c^2*x^8)/4 - (a^4*c^2*x^9)/9}
{E^(2*ArcTanh[a*x])*x^3*(c - a^2*c*x^2)^2, x, 3, (c^2*x^4)/4 + (2*a*c^2*x^5)/5 - (2*a^3*c^2*x^7)/7 - (a^4*c^2*x^8)/8}
{E^(2*ArcTanh[a*x])*x^2*(c - a^2*c*x^2)^2, x, 3, (c^2*x^3)/3 + (a*c^2*x^4)/2 - (a^3*c^2*x^6)/3 - (a^4*c^2*x^7)/7}
{E^(2*ArcTanh[a*x])*x*(c - a^2*c*x^2)^2, x, 3, (c^2*x^2)/2 + (2*a*c^2*x^3)/3 - (2*a^3*c^2*x^5)/5 - (a^4*c^2*x^6)/6}
{E^(2*ArcTanh[a*x])*(c - a^2*c*x^2)^2, x, 3, (c^2*(1 + a*x)^4)/(2*a) - (c^2*(1 + a*x)^5)/(5*a)}
{(E^(2*ArcTanh[a*x])*(c - a^2*c*x^2)^2)/x, x, 4, 2*a*c^2*x - (2*a^3*c^2*x^3)/3 - (a^4*c^2*x^4)/4 + c^2*Log[x], 3*a*c^2*x + (3/2)*a^2*c^2*x^2 + (1/3)*a^3*c^2*x^3 - (1/4)*c^2*(1 + a*x)^4 + c^2*Log[x]}
{(E^(2*ArcTanh[a*x])*(c - a^2*c*x^2)^2)/x^2, x, 3, -(c^2/x) - a^3*c^2*x^2 - (a^4*c^2*x^3)/3 + 2*a*c^2*Log[x]}
{(E^(2*ArcTanh[a*x])*(c - a^2*c*x^2)^2)/x^3, x, 2, -((c^2*(1 + a*x)^4)/(2*x^2))}
{(E^(2*ArcTanh[a*x])*(c - a^2*c*x^2)^2)/x^4, x, 3, -c^2/(3*x^3) - (a*c^2)/x^2 - a^4*c^2*x - 2*a^3*c^2*Log[x]}
{(E^(2*ArcTanh[a*x])*(c - a^2*c*x^2)^2)/x^5, x, 4, -(c^2/(4*x^4)) - (2*a*c^2)/(3*x^3) + (2*a^3*c^2)/x - a^4*c^2*Log[x], (a*c^2)/(3*x^3) + (3*a^2*c^2)/(2*x^2) + (3*a^3*c^2)/x - (c^2*(1 + a*x)^4)/(4*x^4) - a^4*c^2*Log[x]}
{(E^(2*ArcTanh[a*x])*(c - a^2*c*x^2)^2)/x^6, x, 3, -(c^2/(5*x^5)) - (a*c^2)/(2*x^4) + (a^3*c^2)/x^2 + (a^4*c^2)/x}


{E^(2*ArcTanh[a*x])*x^m*(c - a^2*c*x^2)^3, x, 3, (c^3*x^(1 + m))/(1 + m) + (2*a*c^3*x^(2 + m))/(2 + m) - (a^2*c^3*x^(3 + m))/(3 + m) - (4*a^3*c^3*x^(4 + m))/(4 + m) - (a^4*c^3*x^(5 + m))/(5 + m) + (2*a^5*c^3*x^(6 + m))/(6 + m) + (a^6*c^3*x^(7 + m))/(7 + m)}

{E^(2*ArcTanh[a*x])*x^4*(c - a^2*c*x^2)^3, x, 3, (c^3*x^5)/5 + (a*c^3*x^6)/3 - (a^2*c^3*x^7)/7 - (a^3*c^3*x^8)/2 - (a^4*c^3*x^9)/9 + (a^5*c^3*x^10)/5 + (a^6*c^3*x^11)/11}
{E^(2*ArcTanh[a*x])*x^3*(c - a^2*c*x^2)^3, x, 3, (c^3*x^4)/4 + (2*a*c^3*x^5)/5 - (a^2*c^3*x^6)/6 - (4*a^3*c^3*x^7)/7 - (a^4*c^3*x^8)/8 + (2*a^5*c^3*x^9)/9 + (a^6*c^3*x^10)/10}
{E^(2*ArcTanh[a*x])*x^2*(c - a^2*c*x^2)^3, x, 3, (c^3*x^3)/3 + (a*c^3*x^4)/2 - (a^2*c^3*x^5)/5 - (2*a^3*c^3*x^6)/3 - (a^4*c^3*x^7)/7 + (a^5*c^3*x^8)/4 + (a^6*c^3*x^9)/9}
{E^(2*ArcTanh[a*x])*x*(c - a^2*c*x^2)^3, x, 3, (c^3*x^2)/2 + (2*a*c^3*x^3)/3 - (a^2*c^3*x^4)/4 - (4*a^3*c^3*x^5)/5 - (a^4*c^3*x^6)/6 + (2*a^5*c^3*x^7)/7 + (a^6*c^3*x^8)/8}
{E^(2*ArcTanh[a*x])*(c - a^2*c*x^2)^3, x, 3, (4*c^3*(1 + a*x)^5)/(5*a) - (2*c^3*(1 + a*x)^6)/(3*a) + (c^3*(1 + a*x)^7)/(7*a)}
{(E^(2*ArcTanh[a*x])*(c - a^2*c*x^2)^3)/x, x, 3, 2*a*c^3*x - (a^2*c^3*x^2)/2 - (4*a^3*c^3*x^3)/3 - (a^4*c^3*x^4)/4 + (2*a^5*c^3*x^5)/5 + (a^6*c^3*x^6)/6 + c^3*Log[x]}
{(E^(2*ArcTanh[a*x])*(c - a^2*c*x^2)^3)/x^2, x, 3, -(c^3/x) - a^2*c^3*x - 2*a^3*c^3*x^2 - (a^4*c^3*x^3)/3 + (a^5*c^3*x^4)/2 + (a^6*c^3*x^5)/5 + 2*a*c^3*Log[x]}
{(E^(2*ArcTanh[a*x])*(c - a^2*c*x^2)^3)/x^3, x, 3, -c^3/(2*x^2) - (2*a*c^3)/x - 4*a^3*c^3*x - (a^4*c^3*x^2)/2 + (2*a^5*c^3*x^3)/3 + (a^6*c^3*x^4)/4 - a^2*c^3*Log[x]}
{(E^(2*ArcTanh[a*x])*(c - a^2*c*x^2)^3)/x^4, x, 3, -c^3/(3*x^3) - (a*c^3)/x^2 + (a^2*c^3)/x - a^4*c^3*x + a^5*c^3*x^2 + (a^6*c^3*x^3)/3 - 4*a^3*c^3*Log[x]}


{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^4, x, 3, (4*c^4*(1 + a*x)^6)/(3*a) - (12*c^4*(1 + a*x)^7)/(7*a) + (3*c^4*(1 + a*x)^8)/(4*a) - (c^4*(1 + a*x)^9)/(9*a)}


(* ::Subsubsection::Closed:: *)
(*p<0*)


{(E^(2*ArcTanh[a*x])*x^m)/(c - a^2*c*x^2), x, 3, x^(1 + m)/(c*(1 - a*x)) - (m*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, a*x])/(c*(1 + m))}

{(E^(2*ArcTanh[a*x])*x^4)/(c - a^2*c*x^2), x, 3, (3*x)/(a^4*c) + x^2/(a^3*c) + x^3/(3*a^2*c) + 1/(a^5*c*(1 - a*x)) + (4*Log[1 - a*x])/(a^5*c)}
{(E^(2*ArcTanh[a*x])*x^3)/(c - a^2*c*x^2), x, 3, (2*x)/(a^3*c) + x^2/(2*a^2*c) + 1/(a^4*c*(1 - a*x)) + (3*Log[1 - a*x])/(a^4*c)}
{(E^(2*ArcTanh[a*x])*x^2)/(c - a^2*c*x^2), x, 3, x/(a^2*c) + 1/(a^3*c*(1 - a*x)) + (2*Log[1 - a*x])/(a^3*c)}
{(E^(2*ArcTanh[a*x])*x)/(c - a^2*c*x^2), x, 3, 1/(a^2*c*(1 - a*x)) + Log[1 - a*x]/(a^2*c)}
{E^(2*ArcTanh[a*x])/(c - a^2*c*x^2), x, 2, 1/(a*c*(1 - a*x))}
{E^(2*ArcTanh[a*x])/(x*(c - a^2*c*x^2)), x, 3, 1/(c*(1 - a*x)) + Log[x]/c - Log[1 - a*x]/c}
{E^(2*ArcTanh[a*x])/(x^2*(c - a^2*c*x^2)), x, 3, -(1/(c*x)) + a/(c*(1 - a*x)) + (2*a*Log[x])/c - (2*a*Log[1 - a*x])/c}
{E^(2*ArcTanh[a*x])/(x^3*(c - a^2*c*x^2)), x, 3, -1/(2*c*x^2) - (2*a)/(c*x) + a^2/(c*(1 - a*x)) + (3*a^2*Log[x])/c - (3*a^2*Log[1 - a*x])/c}
{E^(2*ArcTanh[a*x])/(x^4*(c - a^2*c*x^2)), x, 3, -1/(3*c*x^3) - a/(c*x^2) - (3*a^2)/(c*x) + a^3/(c*(1 - a*x)) + (4*a^3*Log[x])/c - (4*a^3*Log[1 - a*x])/c}


{(E^(2*ArcTanh[a*x])*x^m)/(c - a^2*c*x^2)^2, x, 10, x^(1 + m)/(4*c^2*(1 - a*x)^2) + x^(1 + m)/(4*c^2*(1 - a*x)) + ((1 - m)*x^(1 + m))/(4*c^2*(1 - a*x)) + (x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, (-a)*x])/(8*c^2*(1 + m)) + (x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, a*x])/(8*c^2*(1 + m)) - (m*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, a*x])/(4*c^2*(1 + m)) - ((1 - m)*m*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, a*x])/(4*c^2*(1 + m))}

{(E^(2*ArcTanh[a*x])*x^4)/(c - a^2*c*x^2)^2, x, 3, -(x/(a^4*c^2)) + 1/(4*a^5*c^2*(1 - a*x)^2) - 7/(4*a^5*c^2*(1 - a*x)) - (17*Log[1 - a*x])/(8*a^5*c^2) + Log[1 + a*x]/(8*a^5*c^2)}
{(E^(2*ArcTanh[a*x])*x^3)/(c - a^2*c*x^2)^2, x, 3, 1/(4*a^4*c^2*(1 - a*x)^2) - 5/(4*a^4*c^2*(1 - a*x)) - (7*Log[1 - a*x])/(8*a^4*c^2) - Log[1 + a*x]/(8*a^4*c^2)}
{(E^(2*ArcTanh[a*x])*x^2)/(c - a^2*c*x^2)^2, x, 4, 1/(4*a^3*c^2*(1 - a*x)^2) - 3/(4*a^3*c^2*(1 - a*x)) + ArcTanh[a*x]/(4*a^3*c^2)}
{(E^(2*ArcTanh[a*x])*x)/(c - a^2*c*x^2)^2, x, 4, 1/(4*a^2*c^2*(1 - a*x)^2) - 1/(4*a^2*c^2*(1 - a*x)) - ArcTanh[a*x]/(4*a^2*c^2)}
{E^(2*ArcTanh[a*x])/(c - a^2*c*x^2)^2, x, 4, 1/(4*a*c^2*(1 - a*x)^2) + 1/(4*a*c^2*(1 - a*x)) + ArcTanh[a*x]/(4*a*c^2)}
{E^(2*ArcTanh[a*x])/(x*(c - a^2*c*x^2)^2), x, 3, 1/(4*c^2*(1 - a*x)^2) + 3/(4*c^2*(1 - a*x)) + Log[x]/c^2 - (7*Log[1 - a*x])/(8*c^2) - Log[1 + a*x]/(8*c^2)}
{E^(2*ArcTanh[a*x])/(x^2*(c - a^2*c*x^2)^2), x, 3, -(1/(c^2*x)) + a/(4*c^2*(1 - a*x)^2) + (5*a)/(4*c^2*(1 - a*x)) + (2*a*Log[x])/c^2 - (17*a*Log[1 - a*x])/(8*c^2) + (a*Log[1 + a*x])/(8*c^2)}
{E^(2*ArcTanh[a*x])/(x^3*(c - a^2*c*x^2)^2), x, 3, -1/(2*c^2*x^2) - (2*a)/(c^2*x) + a^2/(4*c^2*(1 - a*x)^2) + (7*a^2)/(4*c^2*(1 - a*x)) + (4*a^2*Log[x])/c^2 - (31*a^2*Log[1 - a*x])/(8*c^2) - (a^2*Log[1 + a*x])/(8*c^2)}
{E^(2*ArcTanh[a*x])/(x^4*(c - a^2*c*x^2)^2), x, 3, -1/(3*c^2*x^3) - a/(c^2*x^2) - (4*a^2)/(c^2*x) + a^3/(4*c^2*(1 - a*x)^2) + (9*a^3)/(4*c^2*(1 - a*x)) + (6*a^3*Log[x])/c^2 - (49*a^3*Log[1 - a*x])/(8*c^2) + (a^3*Log[1 + a*x])/(8*c^2)}


{(E^(2*ArcTanh[a*x])*x^m)/(c - a^2*c*x^2)^3, x, 16, x^(1 + m)/(12*c^3*(1 - a*x)^3) + x^(1 + m)/(8*c^3*(1 - a*x)^2) + ((2 - m)*x^(1 + m))/(24*c^3*(1 - a*x)^2) + (3*x^(1 + m))/(16*c^3*(1 - a*x)) + ((1 - m)*x^(1 + m))/(8*c^3*(1 - a*x)) + ((1 - m)*(2 - m)*x^(1 + m))/(24*c^3*(1 - a*x)) + x^(1 + m)/(16*c^3*(1 + a*x)) + (x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, (-a)*x])/(8*c^3*(1 + m)) - (m*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, (-a)*x])/(16*c^3*(1 + m)) + (x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, a*x])/(8*c^3*(1 + m)) - (3*m*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, a*x])/(16*c^3*(1 + m)) - ((1 - m)*m*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, a*x])/(8*c^3*(1 + m)) - ((1 - m)*(2 - m)*m*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, a*x])/(24*c^3*(1 + m))}

{(E^(2*ArcTanh[a*x])*x^5)/(c - a^2*c*x^2)^3, x, 3, 1/(12*a^6*c^3*(1 - a*x)^3) - 1/(2*a^6*c^3*(1 - a*x)^2) + 23/(16*a^6*c^3*(1 - a*x)) + 1/(16*a^6*c^3*(1 + a*x)) + (13*Log[1 - a*x])/(16*a^6*c^3) + (3*Log[1 + a*x])/(16*a^6*c^3)}
{(E^(2*ArcTanh[a*x])*x^4)/(c - a^2*c*x^2)^3, x, 4, 1/(12*a^5*c^3*(1 - a*x)^3) - 3/(8*a^5*c^3*(1 - a*x)^2) + 11/(16*a^5*c^3*(1 - a*x)) - 1/(16*a^5*c^3*(1 + a*x)) - ArcTanh[a*x]/(4*a^5*c^3)}
{(E^(2*ArcTanh[a*x])*x^3)/(c - a^2*c*x^2)^3, x, 4, 1/(12*a^4*c^3*(1 - a*x)^3) - 1/(4*a^4*c^3*(1 - a*x)^2) + 3/(16*a^4*c^3*(1 - a*x)) + 1/(16*a^4*c^3*(1 + a*x)) + ArcTanh[a*x]/(8*a^4*c^3)}
{(E^(2*ArcTanh[a*x])*x^2)/(c - a^2*c*x^2)^3, x, 3, 1/(12*a^3*c^3*(1 - a*x)^3) - 1/(8*a^3*c^3*(1 - a*x)^2) - 1/(16*a^3*c^3*(1 - a*x)) - 1/(16*a^3*c^3*(1 + a*x))}
{(E^(2*ArcTanh[a*x])*x)/(c - a^2*c*x^2)^3, x, 4, 1/(12*a^2*c^3*(1 - a*x)^3) - 1/(16*a^2*c^3*(1 - a*x)) + 1/(16*a^2*c^3*(1 + a*x)) - ArcTanh[a*x]/(8*a^2*c^3)}
{E^(2*ArcTanh[a*x])/(c - a^2*c*x^2)^3, x, 4, 1/(12*a*c^3*(1 - a*x)^3) + 1/(8*a*c^3*(1 - a*x)^2) + 3/(16*a*c^3*(1 - a*x)) - 1/(16*a*c^3*(1 + a*x)) + ArcTanh[a*x]/(4*a*c^3)}
{E^(2*ArcTanh[a*x])/(x*(c - a^2*c*x^2)^3), x, 3, 1/(12*c^3*(1 - a*x)^3) + 1/(4*c^3*(1 - a*x)^2) + 11/(16*c^3*(1 - a*x)) + 1/(16*c^3*(1 + a*x)) + Log[x]/c^3 - (13*Log[1 - a*x])/(16*c^3) - (3*Log[1 + a*x])/(16*c^3)}
{E^(2*ArcTanh[a*x])/(x^2*(c - a^2*c*x^2)^3), x, 3, -(1/(c^3*x)) + a/(12*c^3*(1 - a*x)^3) + (3*a)/(8*c^3*(1 - a*x)^2) + (23*a)/(16*c^3*(1 - a*x)) - a/(16*c^3*(1 + a*x)) + (2*a*Log[x])/c^3 - (9*a*Log[1 - a*x])/(4*c^3) + (a*Log[1 + a*x])/(4*c^3)}
{E^(2*ArcTanh[a*x])/(x^3*(c - a^2*c*x^2)^3), x, 3, -1/(2*c^3*x^2) - (2*a)/(c^3*x) + a^2/(12*c^3*(1 - a*x)^3) + a^2/(2*c^3*(1 - a*x)^2) + (39*a^2)/(16*c^3*(1 - a*x)) + a^2/(16*c^3*(1 + a*x)) + (5*a^2*Log[x])/c^3 - (75*a^2*Log[1 - a*x])/(16*c^3) - (5*a^2*Log[1 + a*x])/(16*c^3)}


{E^(2*ArcTanh[a*x])/(c - c*a^2*x^2)^4, x, 4, 1/(32*a*c^4*(1 - a*x)^4) + 1/(16*a*c^4*(1 - a*x)^3) + 3/(32*a*c^4*(1 - a*x)^2) + 5/(32*a*c^4*(1 - a*x)) - 1/(64*a*c^4*(1 + a*x)^2) - 5/(64*a*c^4*(1 + a*x)) + (15*ArcTanh[a*x])/(64*a*c^4)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(2 ArcTanh[a x]) (c-c a^2 x^2)^(p/2)*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)*x^m, x, 2, (x^(1 + m)*Sqrt[c - a^2*c*x^2]*AppellF1[1 + m, 1/2, -(3/2), 2 + m, a*x, (-a)*x])/((1 + m)*Sqrt[1 - a*x]*Sqrt[1 + a*x])}

{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)*x^3, x, 7, -((3*Sqrt[c - a^2*c*x^2])/(4*a^4)) - (9*(1 + a*x)*Sqrt[c - a^2*c*x^2])/(20*a^4) - (3*x*(1 + a*x)*Sqrt[c - a^2*c*x^2])/(10*a^3) - (3*x^2*(1 + a*x)*Sqrt[c - a^2*c*x^2])/(10*a^2) - (x^3*(1 + a*x)*Sqrt[c - a^2*c*x^2])/(5*a) + (3*Sqrt[c - a^2*c*x^2]*ArcSin[a*x])/(4*a^4*Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)*x^2, x, 6, -((7*Sqrt[c - a^2*c*x^2])/(8*a^3)) - (7*(1 + a*x)*Sqrt[c - a^2*c*x^2])/(24*a^3) - ((1 + a*x)^2*Sqrt[c - a^2*c*x^2])/(6*a^3) - (x*(1 + a*x)^2*Sqrt[c - a^2*c*x^2])/(4*a^2) + (7*Sqrt[c - a^2*c*x^2]*ArcSin[a*x])/(8*a^3*Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)*x^1, x, 5, -(Sqrt[c - a^2*c*x^2]/a^2) - ((1 + a*x)*Sqrt[c - a^2*c*x^2])/(3*a^2) - ((1 + a*x)^2*Sqrt[c - a^2*c*x^2])/(3*a^2) + (Sqrt[c]*ArcTan[(a*Sqrt[c]*x)/Sqrt[c - a^2*c*x^2]])/a^2}
{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)*x^0, x, 4, -((3*Sqrt[c - a^2*c*x^2])/(2*a)) - ((1 + a*x)*Sqrt[c - a^2*c*x^2])/(2*a) + (3*Sqrt[c]*ArcTan[(a*Sqrt[c]*x)/Sqrt[c - a^2*c*x^2]])/(2*a)}
{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)/x^1, x, 5, -Sqrt[c - a^2*c*x^2] + (2*Sqrt[c - a^2*c*x^2]*ArcSin[a*x])/(Sqrt[1 - a*x]*Sqrt[1 + a*x]) - (2*Sqrt[c - a^2*c*x^2]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)/x^2, x, 6, a*Sqrt[c - a^2*c*x^2] - ((1 + a*x)*Sqrt[c - a^2*c*x^2])/x + (a*Sqrt[c - a^2*c*x^2]*ArcSin[a*x])/(Sqrt[1 - a*x]*Sqrt[1 + a*x]) - (4*a*Sqrt[c - a^2*c*x^2]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)/x^3, x, 4, -((3*a*Sqrt[c - a^2*c*x^2])/(2*x)) - ((1 + a*x)*Sqrt[c - a^2*c*x^2])/(2*x^2) - (3*a^2*Sqrt[c - a^2*c*x^2]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)/x^4, x, 6, -((2*a*Sqrt[c - a^2*c*x^2])/(3*x^2)) - (5*a^2*Sqrt[c - a^2*c*x^2])/(3*x) - ((1 + a*x)*Sqrt[c - a^2*c*x^2])/(3*x^3) - (2*a^3*Sqrt[c - a^2*c*x^2]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)/x^5, x, 7, -((5*a*Sqrt[c - a^2*c*x^2])/(12*x^3)) - (7*a^2*Sqrt[c - a^2*c*x^2])/(8*x^2) - (4*a^3*Sqrt[c - a^2*c*x^2])/(3*x) - ((1 + a*x)*Sqrt[c - a^2*c*x^2])/(4*x^4) - (7*a^4*Sqrt[c - a^2*c*x^2]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(4*Sqrt[1 - a*x]*Sqrt[1 + a*x])}


{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(3/2)*x^m, x, 2, (c*x^(1 + m)*Sqrt[c - a^2*c*x^2]*AppellF1[1 + m, -(1/2), -(5/2), 2 + m, a*x, (-a)*x])/((1 + m)*Sqrt[1 - a*x]*Sqrt[1 + a*x])}

{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(3/2)*x^3, x, 9, -((c*Sqrt[c - a^2*c*x^2])/(8*a^4)) - (c*(1 + a*x)*Sqrt[c - a^2*c*x^2])/(24*a^4) - (c*(1 + a*x)^2*Sqrt[c - a^2*c*x^2])/(60*a^4) - (11*c*(1 + a*x)^3*Sqrt[c - a^2*c*x^2])/(420*a^4) + (c*x*(1 + a*x)^3*Sqrt[c - a^2*c*x^2])/(35*a^3) - (2*c*x^2*(1 + a*x)^3*Sqrt[c - a^2*c*x^2])/(21*a^2) + (c*x^3*(1 + a*x)^3*Sqrt[c - a^2*c*x^2])/(7*a) + (c*Sqrt[c - a^2*c*x^2]*ArcSin[a*x])/(8*a^4*Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(3/2)*x^2, x, 8, -((c*(1 - a*x)*(1 + a*x)*Sqrt[c - a^2*c*x^2])/(8*a^3)) - (3*c*(1 - a*x)*(1 + a*x)^2*Sqrt[c - a^2*c*x^2])/(40*a^3) - (c*(1 - a*x)*(1 + a*x)^3*Sqrt[c - a^2*c*x^2])/(15*a^3) - (c*x*(1 - a*x)*(1 + a*x)^3*Sqrt[c - a^2*c*x^2])/(6*a^2) + (3*c*x*Sqrt[1 - a^2*x^2]*Sqrt[c - a^2*c*x^2])/(16*a^2*Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (3*c*Sqrt[c - a^2*c*x^2]*ArcSin[a*x])/(16*a^3*Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(3/2)*x^1, x, 6, (c*x*Sqrt[c - a^2*c*x^2])/(4*a) - (c - a^2*c*x^2)^(3/2)/(6*a^2) - ((1 + a*x)*(c - a^2*c*x^2)^(3/2))/(10*a^2) - ((1 + a*x)^2*(c - a^2*c*x^2)^(3/2))/(5*a^2) + (c^(3/2)*ArcTan[(a*Sqrt[c]*x)/Sqrt[c - a^2*c*x^2]])/(4*a^2)}
{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(3/2)*x^0, x, 5, (5/8)*c*x*Sqrt[c - a^2*c*x^2] - (5*(c - a^2*c*x^2)^(3/2))/(12*a) - ((1 + a*x)*(c - a^2*c*x^2)^(3/2))/(4*a) + (5*c^(3/2)*ArcTan[(a*Sqrt[c]*x)/Sqrt[c - a^2*c*x^2]])/(8*a)}
{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(3/2)/x^1, x, 7, (1/3)*c*(1 + a*x)*Sqrt[c - a^2*c*x^2] + (1/3)*c*(1 + a*x)^2*Sqrt[c - a^2*c*x^2] + (c*Sqrt[c - a^2*c*x^2]*ArcSin[a*x])/(Sqrt[1 - a*x]*Sqrt[1 + a*x]) - (2*c*Sqrt[c - a^2*c*x^2]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(3/2)/x^2, x, 7, (5/2)*a*c*Sqrt[c - a^2*c*x^2] + (3/2)*a*c*(1 + a*x)*Sqrt[c - a^2*c*x^2] - (c*(1 + a*x)^2*Sqrt[c - a^2*c*x^2])/x - (a*c*Sqrt[c - a^2*c*x^2]*ArcSin[a*x])/(2*Sqrt[1 - a*x]*Sqrt[1 + a*x]) - (4*a*c*Sqrt[c - a^2*c*x^2]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(3/2)/x^3, x, 7, (5/2)*a^2*c*Sqrt[c - a^2*c*x^2] - (a*c*(1 + a*x)*Sqrt[c - a^2*c*x^2])/x - (c*(1 + a*x)^2*Sqrt[c - a^2*c*x^2])/(2*x^2) - (2*a^2*c*Sqrt[c - a^2*c*x^2]*ArcSin[a*x])/(Sqrt[1 - a*x]*Sqrt[1 + a*x]) - (a^2*c*Sqrt[c - a^2*c*x^2]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(3/2)/x^4, x, 7, -((a*c*(1 + a*x)*Sqrt[c - a^2*c*x^2])/(3*x^2)) - (c*(1 + a*x)^2*Sqrt[c - a^2*c*x^2])/(3*x^3) - (a^3*c*Sqrt[c - a^2*c*x^2]*ArcSin[a*x])/(Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (2*a^3*c*Sqrt[c - a^2*c*x^2]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(3/2)/x^5, x, 6, (5*a^3*c*Sqrt[c - a^2*c*x^2])/(8*x) + (5*a^2*c*(1 + a*x)*Sqrt[c - a^2*c*x^2])/(24*x^2) + (a*c*(1 + a*x)^2*Sqrt[c - a^2*c*x^2])/(12*x^3) - (c*(1 + a*x)^3*Sqrt[c - a^2*c*x^2])/(4*x^4) + (5*a^4*c*Sqrt[c - a^2*c*x^2]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(4*Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(3/2)/x^6, x, 8, (a^2*c*Sqrt[c - a^2*c*x^2])/(30*x^3) + (a^3*c*Sqrt[c - a^2*c*x^2])/(4*x^2) + (7*a^4*c*Sqrt[c - a^2*c*x^2])/(15*x) - (a*c*(1 + a*x)*Sqrt[c - a^2*c*x^2])/(10*x^4) - (c*(1 + a*x)^2*Sqrt[c - a^2*c*x^2])/(5*x^5) + (a^5*c*Sqrt[c - a^2*c*x^2]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(2*Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(3/2)/x^7, x, 9, (a^2*c*Sqrt[c - a^2*c*x^2])/(40*x^4) + (2*a^3*c*Sqrt[c - a^2*c*x^2])/(15*x^3) + (3*a^4*c*Sqrt[c - a^2*c*x^2])/(16*x^2) + (4*a^5*c*Sqrt[c - a^2*c*x^2])/(15*x) - (a*c*(1 + a*x)*Sqrt[c - a^2*c*x^2])/(15*x^5) - (c*(1 + a*x)^2*Sqrt[c - a^2*c*x^2])/(6*x^6) + (3*a^6*c*Sqrt[c - a^2*c*x^2]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(8*Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(3/2)/x^8, x, 10, (2*a^2*c*Sqrt[c - a^2*c*x^2])/(105*x^5) + (a^3*c*Sqrt[c - a^2*c*x^2])/(12*x^4) + (11*a^4*c*Sqrt[c - a^2*c*x^2])/(105*x^3) + (a^5*c*Sqrt[c - a^2*c*x^2])/(8*x^2) + (22*a^6*c*Sqrt[c - a^2*c*x^2])/(105*x) - (a*c*(1 + a*x)*Sqrt[c - a^2*c*x^2])/(21*x^6) - (c*(1 + a*x)^2*Sqrt[c - a^2*c*x^2])/(7*x^7) + (a^7*c*Sqrt[c - a^2*c*x^2]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(4*Sqrt[1 - a*x]*Sqrt[1 + a*x])}


{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(5/2)*x^m, x, 2, (c^2*x^(1 + m)*Sqrt[c - a^2*c*x^2]*AppellF1[1 + m, -(3/2), -(7/2), 2 + m, a*x, (-a)*x])/((1 + m)*Sqrt[1 - a*x]*Sqrt[1 + a*x])}

{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(5/2)*x^3, x, 11, -((c^2*(1 - a*x)*(1 + a*x)*Sqrt[c - a^2*c*x^2])/(32*a^4)) - (3*c^2*(1 - a*x)*(1 + a*x)^2*Sqrt[c - a^2*c*x^2])/(160*a^4) - (3*c^2*(1 - a*x)*(1 + a*x)^3*Sqrt[c - a^2*c*x^2])/(280*a^4) - (11*c^2*(1 - a*x)*(1 + a*x)^4*Sqrt[c - a^2*c*x^2])/(504*a^4) + (c^2*x*(1 - a*x)*(1 + a*x)^4*Sqrt[c - a^2*c*x^2])/(84*a^3) - (c^2*x^2*(1 - a*x)*(1 + a*x)^4*Sqrt[c - a^2*c*x^2])/(12*a^2) + (c^2*x^3*(1 - a*x)*(1 + a*x)^4*Sqrt[c - a^2*c*x^2])/(9*a) + (3*c^2*x*Sqrt[1 - a^2*x^2]*Sqrt[c - a^2*c*x^2])/(64*a^3*Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (3*c^2*Sqrt[c - a^2*c*x^2]*ArcSin[a*x])/(64*a^4*Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(5/2)*x^2, x, 9, -((11*c^2*(1 - a*x)^2*(1 + a*x)^2*Sqrt[c - a^2*c*x^2])/(240*a^3)) - (11*c^2*(1 - a*x)^2*(1 + a*x)^3*Sqrt[c - a^2*c*x^2])/(336*a^3) - (c^2*(1 - a*x)^2*(1 + a*x)^4*Sqrt[c - a^2*c*x^2])/(28*a^3) - (c^2*x*(1 - a*x)^2*(1 + a*x)^4*Sqrt[c - a^2*c*x^2])/(8*a^2) + (11*c^2*x*Sqrt[1 - a^2*x^2]*Sqrt[c - a^2*c*x^2])/(128*a^2*Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (11*c^2*x*(1 - a^2*x^2)^(3/2)*Sqrt[c - a^2*c*x^2])/(192*a^2*Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (11*c^2*Sqrt[c - a^2*c*x^2]*ArcSin[a*x])/(128*a^3*Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(5/2)*x^1, x, 7, (c^2*x*Sqrt[c - a^2*c*x^2])/(8*a) + (c*x*(c - a^2*c*x^2)^(3/2))/(12*a) - (c - a^2*c*x^2)^(5/2)/(15*a^2) - ((1 + a*x)*(c - a^2*c*x^2)^(5/2))/(21*a^2) - ((1 + a*x)^2*(c - a^2*c*x^2)^(5/2))/(7*a^2) + (c^(5/2)*ArcTan[(a*Sqrt[c]*x)/Sqrt[c - a^2*c*x^2]])/(8*a^2)}
{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(5/2)*x^0, x, 6, (7/16)*c^2*x*Sqrt[c - a^2*c*x^2] + (7/24)*c*x*(c - a^2*c*x^2)^(3/2) - (7*(c - a^2*c*x^2)^(5/2))/(30*a) - ((1 + a*x)*(c - a^2*c*x^2)^(5/2))/(6*a) + (7*c^(5/2)*ArcTan[(a*Sqrt[c]*x)/Sqrt[c - a^2*c*x^2]])/(16*a)}
{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(5/2)/x^1, x, 9, (1/4)*c^2*Sqrt[c - a^2*c*x^2] + (5/12)*c^2*(1 + a*x)*Sqrt[c - a^2*c*x^2] + (11/30)*c^2*(1 + a*x)^2*Sqrt[c - a^2*c*x^2] - (1/10)*c^2*(1 + a*x)^3*Sqrt[c - a^2*c*x^2] + (1/5)*c^2*(1 - a*x)*(1 + a*x)^3*Sqrt[c - a^2*c*x^2] + (3*c^2*Sqrt[c - a^2*c*x^2]*ArcSin[a*x])/(4*Sqrt[1 - a*x]*Sqrt[1 + a*x]) - (2*c^2*Sqrt[c - a^2*c*x^2]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(5/2)/x^2, x, 9, (25/8)*a*c^2*Sqrt[c - a^2*c*x^2] + (41/24)*a*c^2*(1 + a*x)*Sqrt[c - a^2*c*x^2] + (13/12)*a*c^2*(1 + a*x)^2*Sqrt[c - a^2*c*x^2] - (5/4)*a*c^2*(1 + a*x)^3*Sqrt[c - a^2*c*x^2] - (c^2*(1 - a*x)*(1 + a*x)^3*Sqrt[c - a^2*c*x^2])/x - (9*a*c^2*Sqrt[c - a^2*c*x^2]*ArcSin[a*x])/(8*Sqrt[1 - a*x]*Sqrt[1 + a*x]) - (4*a*c^2*Sqrt[c - a^2*c*x^2]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(5/2)/x^3, x, 10, (5/2)*a^2*c^2*Sqrt[c - a^2*c*x^2] + (2/3)*a^2*c^2*(1 + a*x)*Sqrt[c - a^2*c*x^2] + (1/6)*a^2*c^2*(1 + a*x)^2*Sqrt[c - a^2*c*x^2] - (a*c^2*(1 + a*x)^3*Sqrt[c - a^2*c*x^2])/x - (c^2*(1 - a*x)*(1 + a*x)^3*Sqrt[c - a^2*c*x^2])/(2*x^2) - (3*a^2*c^2*Sqrt[c - a^2*c*x^2]*ArcSin[a*x])/(Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (a^2*c^2*Sqrt[c - a^2*c*x^2]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(5/2)/x^4, x, 9, (-(5/2))*a^3*c^2*Sqrt[c - a^2*c*x^2] - (11/6)*a^3*c^2*(1 + a*x)*Sqrt[c - a^2*c*x^2] + (4*a^2*c^2*(1 + a*x)^2*Sqrt[c - a^2*c*x^2])/(3*x) - (a*c^2*(1 + a*x)^3*Sqrt[c - a^2*c*x^2])/(3*x^2) - (c^2*(1 - a*x)*(1 + a*x)^3*Sqrt[c - a^2*c*x^2])/(3*x^3) - (a^3*c^2*Sqrt[c - a^2*c*x^2]*ArcSin[a*x])/(2*Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (6*a^3*c^2*Sqrt[c - a^2*c*x^2]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(5/2)/x^5, x, 9, (-(25/8))*a^4*c^2*Sqrt[c - a^2*c*x^2] + (17*a^3*c^2*(1 + a*x)*Sqrt[c - a^2*c*x^2])/(12*x) + (5*a^2*c^2*(1 + a*x)^2*Sqrt[c - a^2*c*x^2])/(8*x^2) - (a*c^2*(1 + a*x)^3*Sqrt[c - a^2*c*x^2])/(6*x^3) - (c^2*(1 - a*x)*(1 + a*x)^3*Sqrt[c - a^2*c*x^2])/(4*x^4) + (2*a^4*c^2*Sqrt[c - a^2*c*x^2]*ArcSin[a*x])/(Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (9*a^4*c^2*Sqrt[c - a^2*c*x^2]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(4*Sqrt[1 - a*x]*Sqrt[1 + a*x])}


{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(7/2), x, 7, (45/128)*c^3*x*Sqrt[c - a^2*c*x^2] + (15/64)*c^2*x*(c - a^2*c*x^2)^(3/2) + (3/16)*c*x*(c - a^2*c*x^2)^(5/2) - (9*(c - a^2*c*x^2)^(7/2))/(56*a) - ((1 + a*x)*(c - a^2*c*x^2)^(7/2))/(8*a) + (45*c^(7/2)*ArcTan[(a*Sqrt[c]*x)/Sqrt[c - a^2*c*x^2]])/(128*a)}


(* ::Subsubsection::Closed:: *)
(*p<0*)


{E^(2*ArcTanh[a*x])/(c - c*a^2*x^2)^(1/2)*x^m, x, 2, (x^(1 + m)*Sqrt[1 - a*x]*Sqrt[1 + a*x]*AppellF1[1 + m, 3/2, -(1/2), 2 + m, a*x, (-a)*x])/((1 + m)*Sqrt[c - a^2*c*x^2])}

{E^(2*ArcTanh[a*x])/(c - c*a^2*x^2)^(1/2)*x^3, x, 6, (2*x^3*(1 + a*x))/(a*Sqrt[c - a^2*c*x^2]) + (14*(1 - a*x)*(1 + a*x))/(3*a^4*Sqrt[c - a^2*c*x^2]) + (3*x*(1 - a*x)*(1 + a*x))/(a^3*Sqrt[c - a^2*c*x^2]) + (7*x^2*(1 - a*x)*(1 + a*x))/(3*a^2*Sqrt[c - a^2*c*x^2]) - (3*Sqrt[1 - a*x]*Sqrt[1 + a*x]*ArcSin[a*x])/(a^4*Sqrt[c - a^2*c*x^2])}
{E^(2*ArcTanh[a*x])/(c - c*a^2*x^2)^(1/2)*x^2, x, 5, (5*(1 - a*x)*(1 + a*x))/(2*a^3*Sqrt[c - a^2*c*x^2]) + (1 + a*x)^2/(a^3*Sqrt[c - a^2*c*x^2]) + ((1 - a*x)*(1 + a*x)^2)/(2*a^3*Sqrt[c - a^2*c*x^2]) - (5*Sqrt[1 - a*x]*Sqrt[1 + a*x]*ArcSin[a*x])/(2*a^3*Sqrt[c - a^2*c*x^2])}
{E^(2*ArcTanh[a*x])/(c - c*a^2*x^2)^(1/2)*x^1, x, 4, (1 + a*x)^2/(a^2*Sqrt[c - a^2*c*x^2]) + (2*Sqrt[c - a^2*c*x^2])/(a^2*c) - (2*ArcTan[(a*Sqrt[c]*x)/Sqrt[c - a^2*c*x^2]])/(a^2*Sqrt[c])}
{E^(2*ArcTanh[a*x])/(c - c*a^2*x^2)^(1/2)*x^0, x, 3, (2*(1 + a*x))/(a*Sqrt[c - a^2*c*x^2]) - ArcTan[(a*Sqrt[c]*x)/Sqrt[c - a^2*c*x^2]]/(a*Sqrt[c])}
{E^(2*ArcTanh[a*x])/(c - c*a^2*x^2)^(1/2)/x^1, x, 3, (2*(1 + a*x))/Sqrt[c - a^2*c*x^2] - (2*Sqrt[1 - a*x]*Sqrt[1 + a*x]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/Sqrt[c - a^2*c*x^2]}
{E^(2*ArcTanh[a*x])/(c - c*a^2*x^2)^(1/2)/x^2, x, 5, (3*a*(1 + a*x))/Sqrt[c - a^2*c*x^2] - (1 + a*x)/(x*Sqrt[c - a^2*c*x^2]) - (4*a*Sqrt[1 - a*x]*Sqrt[1 + a*x]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/Sqrt[c - a^2*c*x^2]}
{E^(2*ArcTanh[a*x])/(c - c*a^2*x^2)^(1/2)/x^3, x, 6, (4*a^2*(1 + a*x))/Sqrt[c - a^2*c*x^2] - (1 + a*x)/(2*x^2*Sqrt[c - a^2*c*x^2]) - (3*a*(1 + a*x))/(2*x*Sqrt[c - a^2*c*x^2]) - (5*a^2*Sqrt[1 - a*x]*Sqrt[1 + a*x]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/Sqrt[c - a^2*c*x^2]}
{E^(2*ArcTanh[a*x])/(c - c*a^2*x^2)^(1/2)/x^4, x, 7, (14*a^3*(1 + a*x))/(3*Sqrt[c - a^2*c*x^2]) - (1 + a*x)/(3*x^3*Sqrt[c - a^2*c*x^2]) - (2*a*(1 + a*x))/(3*x^2*Sqrt[c - a^2*c*x^2]) - (5*a^2*(1 + a*x))/(3*x*Sqrt[c - a^2*c*x^2]) - (6*a^3*Sqrt[1 - a*x]*Sqrt[1 + a*x]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/Sqrt[c - a^2*c*x^2]}


{E^(2*ArcTanh[a*x])/(c - c*a^2*x^2)^(3/2), x, 4, (2*(1 + a*x))/(3*a*(c - a^2*c*x^2)^(3/2)) + x/(3*c*Sqrt[c - a^2*c*x^2])}


{E^(2*ArcTanh[a*x])/(c - c*a^2*x^2)^(5/2), x, 5, (2*(1 + a*x))/(5*a*(c - a^2*c*x^2)^(5/2)) + x/(5*c*(c - a^2*c*x^2)^(3/2)) + (2*x)/(5*c^2*Sqrt[c - a^2*c*x^2])}


{E^(2*ArcTanh[a*x])/(c - c*a^2*x^2)^(7/2), x, 6, (2*(1 + a*x))/(7*a*(c - a^2*c*x^2)^(7/2)) + x/(7*c*(c - a^2*c*x^2)^(5/2)) + (4*x)/(21*c^2*(c - a^2*c*x^2)^(3/2)) + (8*x)/(21*c^3*Sqrt[c - a^2*c*x^2])}


{E^(2*ArcTanh[a*x])/(c - c*a^2*x^2)^(9/2), x, 7, (2*(1 + a*x))/(9*a*(c - a^2*c*x^2)^(9/2)) + x/(9*c*(c - a^2*c*x^2)^(7/2)) + (2*x)/(15*c^2*(c - a^2*c*x^2)^(5/2)) + (8*x)/(45*c^3*(c - a^2*c*x^2)^(3/2)) + (16*x)/(45*c^4*Sqrt[c - a^2*c*x^2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(2 ArcTanh[a x]) (c-c a^2 x^2)^p with p symbolic*)


{E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^p, x, 4, -(((1 + p)*(c - a^2*c*x^2)^p)/(a*p*(1 + 2*p))) - ((1 + a*x)*(c - a^2*c*x^2)^p)/(a*(1 + 2*p)) + (2*c*(1 + p)*x*(1 - a^2*x^2)^(1 - p)*(c - a^2*c*x^2)^(-1 + p)*Hypergeometric2F1[1/2, 1 - p, 3/2, a^2*x^2])/(1 + 2*p)}


(* ::Section::Closed:: *)
(*Integrands of the form x^m E^(3 ArcTanh[a x]) (c-c a^2 x^2)^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(3 ArcTanh[a x]) (c-c a^2 x^2)^p*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)*x^3, x, 8, -((23*c*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(16*a^4)) - (23*c*Sqrt[1 - a*x]*(1 + a*x)^(3/2))/(48*a^4) - (7*c*Sqrt[1 - a*x]*(1 + a*x)^(5/2))/(20*a^4) - (31*c*x*Sqrt[1 - a*x]*(1 + a*x)^(5/2))/(120*a^3) - (4*c*x^2*Sqrt[1 - a*x]*(1 + a*x)^(5/2))/(15*a^2) - (c*x^3*Sqrt[1 - a*x]*(1 + a*x)^(5/2))/(6*a) + (23*c*ArcSin[a*x])/(16*a^4)}
{E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)*x^2, x, 7, -((13*c*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(8*a^3)) - (13*c*Sqrt[1 - a*x]*(1 + a*x)^(3/2))/(24*a^3) - (13*c*Sqrt[1 - a*x]*(1 + a*x)^(5/2))/(60*a^3) - (3*c*Sqrt[1 - a*x]*(1 + a*x)^(7/2))/(20*a^3) - (c*x*Sqrt[1 - a*x]*(1 + a*x)^(7/2))/(5*a^2) + (13*c*ArcSin[a*x])/(8*a^3)}
{E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)*x^1, x, 6, -((15*c*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(8*a^2)) - (5*c*Sqrt[1 - a*x]*(1 + a*x)^(3/2))/(8*a^2) - (c*Sqrt[1 - a*x]*(1 + a*x)^(5/2))/(4*a^2) - (c*Sqrt[1 - a*x]*(1 + a*x)^(7/2))/(4*a^2) + (15*c*ArcSin[a*x])/(8*a^2)}
{E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)*x^0, x, 5, -((5*c*Sqrt[1 - a^2*x^2])/(2*a)) - (5*c*(1 + a*x)*Sqrt[1 - a^2*x^2])/(6*a) - (c*(1 + a*x)^2*Sqrt[1 - a^2*x^2])/(3*a) + (5*c*ArcSin[a*x])/(2*a)}
{E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)/x^1, x, 6, (-(5/2))*c*Sqrt[1 - a*x]*Sqrt[1 + a*x] - (1/2)*c*Sqrt[1 - a*x]*(1 + a*x)^(3/2) + (7/2)*c*ArcSin[a*x] - 2*c*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]]}
{E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)/x^2, x, 7, a*c*Sqrt[1 - a*x]*(1 + a*x)^(3/2) - (c*Sqrt[1 - a*x]*(1 + a*x)^(5/2))/x + 3*a*c*ArcSin[a*x] - 6*a*c*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]]}
{E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)/x^3, x, 7, (5/2)*a^2*c*Sqrt[1 - a*x]*Sqrt[1 + a*x] - (2*a*c*Sqrt[1 - a*x]*(1 + a*x)^(3/2))/x - (c*Sqrt[1 - a*x]*(1 + a*x)^(5/2))/(2*x^2) + a^2*c*ArcSin[a*x] - 7*a^2*c*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]]}
{E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)/x^4, x, 5, -((5*a^2*c*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(2*x)) - (5*a*c*Sqrt[1 - a*x]*(1 + a*x)^(3/2))/(6*x^2) - (c*Sqrt[1 - a*x]*(1 + a*x)^(5/2))/(3*x^3) - 5*a^3*c*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]]}
{E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)/x^5, x, 7, -((9*a^2*c*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(8*x^2)) - (3*a^3*c*Sqrt[1 - a*x]*Sqrt[1 + a*x])/x - (a*c*Sqrt[1 - a*x]*(1 + a*x)^(3/2))/(2*x^3) - (c*Sqrt[1 - a*x]*(1 + a*x)^(5/2))/(4*x^4) - (15/4)*a^4*c*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]]}
{E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)/x^6, x, 8, -((43*a^2*c*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(60*x^3)) - (13*a^3*c*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(8*x^2) - (38*a^4*c*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(15*x) - (7*a*c*Sqrt[1 - a*x]*(1 + a*x)^(3/2))/(20*x^4) - (c*Sqrt[1 - a*x]*(1 + a*x)^(5/2))/(5*x^5) - (13/4)*a^5*c*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]]}
{E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)/x^7, x, 9, -((21*a^2*c*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(40*x^4)) - (17*a^3*c*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(15*x^3) - (23*a^4*c*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(16*x^2) - (34*a^5*c*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(15*x) - (4*a*c*Sqrt[1 - a*x]*(1 + a*x)^(3/2))/(15*x^5) - (c*Sqrt[1 - a*x]*(1 + a*x)^(5/2))/(6*x^6) - (23/8)*a^6*c*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]]}


{E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^2, x, 6, (7/8)*c^2*x*Sqrt[1 - a^2*x^2] - (7*c^2*(1 - a^2*x^2)^(3/2))/(12*a) - (7*c^2*(1 + a*x)*(1 - a^2*x^2)^(3/2))/(20*a) - (c^2*(1 + a*x)^2*(1 - a^2*x^2)^(3/2))/(5*a) + (7*c^2*ArcSin[a*x])/(8*a)}


{E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^3, x, 7, (9/16)*c^3*x*Sqrt[1 - a^2*x^2] + (3/8)*c^3*x*(1 - a^2*x^2)^(3/2) - (3*c^3*(1 - a^2*x^2)^(5/2))/(10*a) - (3*c^3*(1 + a*x)*(1 - a^2*x^2)^(5/2))/(14*a) - (c^3*(1 + a*x)^2*(1 - a^2*x^2)^(5/2))/(7*a) + (9*c^3*ArcSin[a*x])/(16*a)}


{E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^4, x, 8, (55/128)*c^4*x*Sqrt[1 - a^2*x^2] + (55/192)*c^4*x*(1 - a^2*x^2)^(3/2) + (11/48)*c^4*x*(1 - a^2*x^2)^(5/2) - (11*c^4*(1 - a^2*x^2)^(7/2))/(56*a) - (11*c^4*(1 + a*x)*(1 - a^2*x^2)^(7/2))/(72*a) - (c^4*(1 + a*x)^2*(1 - a^2*x^2)^(7/2))/(9*a) + (55*c^4*ArcSin[a*x])/(128*a)}


(* ::Subsubsection::Closed:: *)
(*p<0*)


{E^(3*ArcTanh[a*x])/(c - c*a^2*x^2)*x^2, x, 6, -((3*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(a^3*c)) + (1 + a*x)^(3/2)/(3*a^3*c*(1 - a*x)^(3/2)) - (2*(1 + a*x)^(3/2))/(a^3*c*Sqrt[1 - a*x]) + (3*ArcSin[a*x])/(a^3*c)}
{E^(3*ArcTanh[a*x])/(c - c*a^2*x^2)*x^1, x, 4, -((2*Sqrt[1 + a*x])/(a^2*c*Sqrt[1 - a*x])) + (1 + a*x)^(3/2)/(3*a^2*c*(1 - a*x)^(3/2)) + ArcSin[a*x]/(a^2*c)}
{E^(3*ArcTanh[a*x])/(c - c*a^2*x^2)*x^0, x, 1, E^(3*ArcTanh[a*x])/(3*a*c)}


{E^(3*ArcTanh[a*x])/(c - c*a^2*x^2)^2, x, 6, (2*(1 + a*x))/(15*a*c^2*(1 - a^2*x^2)^(5/2)) + (1 + a*x)^2/(3*a*c^2*(1 - a^2*x^2)^(5/2)) + x/(15*c^2*(1 - a^2*x^2)^(3/2)) + (2*x)/(15*c^2*Sqrt[1 - a^2*x^2])}
{E^(3*ArcTanh[a*x])/(c - c*a^2*x^2)^3, x, 7, (6*(1 + a*x))/(35*a*c^3*(1 - a^2*x^2)^(7/2)) + (1 + a*x)^2/(5*a*c^3*(1 - a^2*x^2)^(7/2)) + (3*x)/(35*c^3*(1 - a^2*x^2)^(5/2)) + (4*x)/(35*c^3*(1 - a^2*x^2)^(3/2)) + (8*x)/(35*c^3*Sqrt[1 - a^2*x^2])}
{E^(3*ArcTanh[a*x])/(c - c*a^2*x^2)^4, x, 8, (10*(1 + a*x))/(63*a*c^4*(1 - a^2*x^2)^(9/2)) + (1 + a*x)^2/(7*a*c^4*(1 - a^2*x^2)^(9/2)) + (5*x)/(63*c^4*(1 - a^2*x^2)^(7/2)) + (2*x)/(21*c^4*(1 - a^2*x^2)^(5/2)) + (8*x)/(63*c^4*(1 - a^2*x^2)^(3/2)) + (16*x)/(63*c^4*Sqrt[1 - a^2*x^2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(3 ArcTanh[a x]) (c-c a^2 x^2)^(p/2)*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)*x^m, x, 5, -(((5 + 2*m)*x^(1 + m)*Sqrt[c - a^2*c*x^2])/((1 + m)*(2 + m)*Sqrt[1 - a^2*x^2])) - (x^(1 + m)*(1 + a*x)*Sqrt[c - a^2*c*x^2])/((2 + m)*Sqrt[1 - a^2*x^2]) + (4*x^(1 + m)*Sqrt[c - a^2*c*x^2]*Hypergeometric2F1[1, 1 + m, 2 + m, a*x])/((1 + m)*Sqrt[1 - a^2*x^2])}

{E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)*x^3, x, 4, -((4*x*Sqrt[c - a^2*c*x^2])/(a^3*Sqrt[1 - a^2*x^2])) - (2*x^2*Sqrt[c - a^2*c*x^2])/(a^2*Sqrt[1 - a^2*x^2]) - (4*x^3*Sqrt[c - a^2*c*x^2])/(3*a*Sqrt[1 - a^2*x^2]) - (3*x^4*Sqrt[c - a^2*c*x^2])/(4*Sqrt[1 - a^2*x^2]) - (a*x^5*Sqrt[c - a^2*c*x^2])/(5*Sqrt[1 - a^2*x^2]) - (4*Sqrt[c - a^2*c*x^2]*Log[1 - a*x])/(a^4*Sqrt[1 - a^2*x^2])}
{E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)*x^2, x, 4, -((4*x*Sqrt[c - a^2*c*x^2])/(a^2*Sqrt[1 - a^2*x^2])) - (2*x^2*Sqrt[c - a^2*c*x^2])/(a*Sqrt[1 - a^2*x^2]) - (x^3*Sqrt[c - a^2*c*x^2])/Sqrt[1 - a^2*x^2] - (a*x^4*Sqrt[c - a^2*c*x^2])/(4*Sqrt[1 - a^2*x^2]) - (4*Sqrt[c - a^2*c*x^2]*Log[1 - a*x])/(a^3*Sqrt[1 - a^2*x^2])}
{E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)*x^1, x, 4, -((4*x*Sqrt[c - a^2*c*x^2])/(a*Sqrt[1 - a^2*x^2])) - (3*x^2*Sqrt[c - a^2*c*x^2])/(2*Sqrt[1 - a^2*x^2]) - (a*x^3*Sqrt[c - a^2*c*x^2])/(3*Sqrt[1 - a^2*x^2]) - (4*Sqrt[c - a^2*c*x^2]*Log[1 - a*x])/(a^2*Sqrt[1 - a^2*x^2])}
{E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)*x^0, x, 5, -((3*x*Sqrt[c - a^2*c*x^2])/Sqrt[1 - a^2*x^2]) - (a*x^2*Sqrt[c - a^2*c*x^2])/(2*Sqrt[1 - a^2*x^2]) - (4*Sqrt[c - a^2*c*x^2]*Log[1 - a*x])/(a*Sqrt[1 - a^2*x^2])}
{E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)/x^1, x, 4, -((a*x*Sqrt[c - a^2*c*x^2])/Sqrt[1 - a^2*x^2]) + (Sqrt[c - a^2*c*x^2]*Log[x])/Sqrt[1 - a^2*x^2] - (4*Sqrt[c - a^2*c*x^2]*Log[1 - a*x])/Sqrt[1 - a^2*x^2]}
{E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)/x^2, x, 4, -(Sqrt[c - a^2*c*x^2]/(x*Sqrt[1 - a^2*x^2])) + (3*a*Sqrt[c - a^2*c*x^2]*Log[x])/Sqrt[1 - a^2*x^2] - (4*a*Sqrt[c - a^2*c*x^2]*Log[1 - a*x])/Sqrt[1 - a^2*x^2]}
{E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)/x^3, x, 4, -(Sqrt[c - a^2*c*x^2]/(2*x^2*Sqrt[1 - a^2*x^2])) - (3*a*Sqrt[c - a^2*c*x^2])/(x*Sqrt[1 - a^2*x^2]) + (4*a^2*Sqrt[c - a^2*c*x^2]*Log[x])/Sqrt[1 - a^2*x^2] - (4*a^2*Sqrt[c - a^2*c*x^2]*Log[1 - a*x])/Sqrt[1 - a^2*x^2]}
{E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)/x^4, x, 4, -(Sqrt[c - a^2*c*x^2]/(3*x^3*Sqrt[1 - a^2*x^2])) - (3*a*Sqrt[c - a^2*c*x^2])/(2*x^2*Sqrt[1 - a^2*x^2]) - (4*a^2*Sqrt[c - a^2*c*x^2])/(x*Sqrt[1 - a^2*x^2]) + (4*a^3*Sqrt[c - a^2*c*x^2]*Log[x])/Sqrt[1 - a^2*x^2] - (4*a^3*Sqrt[c - a^2*c*x^2]*Log[1 - a*x])/Sqrt[1 - a^2*x^2]}
{E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)/x^5, x, 4, -(Sqrt[c - a^2*c*x^2]/(4*x^4*Sqrt[1 - a^2*x^2])) - (a*Sqrt[c - a^2*c*x^2])/(x^3*Sqrt[1 - a^2*x^2]) - (2*a^2*Sqrt[c - a^2*c*x^2])/(x^2*Sqrt[1 - a^2*x^2]) - (4*a^3*Sqrt[c - a^2*c*x^2])/(x*Sqrt[1 - a^2*x^2]) + (4*a^4*Sqrt[c - a^2*c*x^2]*Log[x])/Sqrt[1 - a^2*x^2] - (4*a^4*Sqrt[c - a^2*c*x^2]*Log[1 - a*x])/Sqrt[1 - a^2*x^2]}


{E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^(9/2), x, 5, (8*c^4*(1 + a*x)^7*Sqrt[c - a^2*c*x^2])/(7*a*Sqrt[1 - a^2*x^2]) - (3*c^4*(1 + a*x)^8*Sqrt[c - a^2*c*x^2])/(2*a*Sqrt[1 - a^2*x^2]) + (2*c^4*(1 + a*x)^9*Sqrt[c - a^2*c*x^2])/(3*a*Sqrt[1 - a^2*x^2]) - (c^4*(1 + a*x)^10*Sqrt[c - a^2*c*x^2])/(10*a*Sqrt[1 - a^2*x^2])}
{E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^(7/2), x, 5, (2*c^3*(1 + a*x)^6*Sqrt[c - a^2*c*x^2])/(3*a*Sqrt[1 - a^2*x^2]) - (4*c^3*(1 + a*x)^7*Sqrt[c - a^2*c*x^2])/(7*a*Sqrt[1 - a^2*x^2]) + (c^3*(1 + a*x)^8*Sqrt[c - a^2*c*x^2])/(8*a*Sqrt[1 - a^2*x^2])}
{E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^(5/2), x, 5, (2*c^2*(1 + a*x)^5*Sqrt[c - a^2*c*x^2])/(5*a*Sqrt[1 - a^2*x^2]) - (c^2*(1 + a*x)^6*Sqrt[c - a^2*c*x^2])/(6*a*Sqrt[1 - a^2*x^2])}
{E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^(3/2), x, 3, (c*(1 + a*x)^4*Sqrt[c - a^2*c*x^2])/(4*a*Sqrt[1 - a^2*x^2])}


(* ::Subsubsection::Closed:: *)
(*p<0*)


{E^(3*ArcTanh[a*x])/(c - c*a^2*x^2)^(1/2), x, 5, (2*Sqrt[1 - a^2*x^2])/(a*(1 - a*x)*Sqrt[c - a^2*c*x^2]) + (Sqrt[1 - a^2*x^2]*Log[1 - a*x])/(a*Sqrt[c - a^2*c*x^2])}
{E^(3*ArcTanh[a*x])/(c - c*a^2*x^2)^(3/2), x, 4, Sqrt[1 - a^2*x^2]/(2*a*c*(1 - a*x)^2*Sqrt[c - a^2*c*x^2])}
{E^(3*ArcTanh[a*x])/(c - c*a^2*x^2)^(5/2), x, 6, Sqrt[1 - a^2*x^2]/(6*a*c^2*(1 - a*x)^3*Sqrt[c - a^2*c*x^2]) + Sqrt[1 - a^2*x^2]/(8*a*c^2*(1 - a*x)^2*Sqrt[c - a^2*c*x^2]) + Sqrt[1 - a^2*x^2]/(8*a*c^2*(1 - a*x)*Sqrt[c - a^2*c*x^2]) + (Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(8*a*c^2*Sqrt[c - a^2*c*x^2])}
{E^(3*ArcTanh[a*x])/(c - c*a^2*x^2)^(7/2), x, 6, Sqrt[1 - a^2*x^2]/(16*a*c^3*(1 - a*x)^4*Sqrt[c - a^2*c*x^2]) + Sqrt[1 - a^2*x^2]/(12*a*c^3*(1 - a*x)^3*Sqrt[c - a^2*c*x^2]) + (3*Sqrt[1 - a^2*x^2])/(32*a*c^3*(1 - a*x)^2*Sqrt[c - a^2*c*x^2]) + Sqrt[1 - a^2*x^2]/(8*a*c^3*(1 - a*x)*Sqrt[c - a^2*c*x^2]) - Sqrt[1 - a^2*x^2]/(32*a*c^3*(1 + a*x)*Sqrt[c - a^2*c*x^2]) + (5*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(32*a*c^3*Sqrt[c - a^2*c*x^2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(3 ArcTanh[a x]) (c-c a^2 x^2)^p with p symbolic*)


{E^(3*ArcTanh[a*x])*(c - a^2*c*x^2)^p*x^m, x, 10, -((3*x^(1 + m)*(c - a^2*c*x^2)^p)/((m + 2*p)*Sqrt[1 - a^2*x^2])) - (a*x^(2 + m)*(c - a^2*c*x^2)^p)/((1 + m + 2*p)*Sqrt[1 - a^2*x^2]) + (x^(1 + m)*(c - a^2*c*x^2)^p*Hypergeometric2F1[(1 + m)/2, 3/2 - p, (3 + m)/2, a^2*x^2])/((1 - a^2*x^2)^p*(1 + m)) + (3*x^(1 + m)*(c - a^2*c*x^2)^p*Hypergeometric2F1[(1 + m)/2, 3/2 - p, (3 + m)/2, a^2*x^2])/((1 - a^2*x^2)^p*(m + 2*p)) + (3*a*x^(2 + m)*(c - a^2*c*x^2)^p*Hypergeometric2F1[(2 + m)/2, 3/2 - p, (4 + m)/2, a^2*x^2])/((1 - a^2*x^2)^p*(2 + m)) + (a*x^(2 + m)*(c - a^2*c*x^2)^p*Hypergeometric2F1[(2 + m)/2, 3/2 - p, (4 + m)/2, a^2*x^2])/((1 - a^2*x^2)^p*(1 + m + 2*p))}

{E^(3*ArcTanh[a*x])*(c - a^2*c*x^2)^p*x^3, x, 17, (4*(c - a^2*c*x^2)^p)/(a^4*(1 - 2*p)*Sqrt[1 - a^2*x^2]) - (9*x*(c - a^2*c*x^2)^p)/(4*a^3*p*(1 + p)*Sqrt[1 - a^2*x^2]) - (15*x*(c - a^2*c*x^2)^p)/(8*a^3*p*(1 + p)*(2 + p)*Sqrt[1 - a^2*x^2]) - (3*x^3*(c - a^2*c*x^2)^p)/(2*a*(1 + p)*Sqrt[1 - a^2*x^2]) - (5*x^3*(c - a^2*c*x^2)^p)/(4*a*(2 + 3*p + p^2)*Sqrt[1 - a^2*x^2]) - (a*x^5*(c - a^2*c*x^2)^p)/(2*(2 + p)*Sqrt[1 - a^2*x^2]) + (7*Sqrt[1 - a^2*x^2]*(c - a^2*c*x^2)^p)/(a^4*(1 + 2*p)) - (3*(1 - a^2*x^2)^(3/2)*(c - a^2*c*x^2)^p)/(a^4*(3 + 2*p)) + (9*x*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2, 3/2 - p, 3/2, a^2*x^2])/((1 - a^2*x^2)^p*(4*a^3*p*(1 + p))) + (15*x*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2, 3/2 - p, 3/2, a^2*x^2])/((1 - a^2*x^2)^p*(8*a^3*p*(1 + p)*(2 + p)))}
{E^(3*ArcTanh[a*x])*(c - a^2*c*x^2)^p*x^2, x, 15, (4*(c - a^2*c*x^2)^p)/(a^3*(1 - 2*p)*Sqrt[1 - a^2*x^2]) - (x*(c - a^2*c*x^2)^p)/(2*a^2*p*Sqrt[1 - a^2*x^2]) - (9*x*(c - a^2*c*x^2)^p)/(4*a^2*p*(1 + p)*Sqrt[1 - a^2*x^2]) - (3*x^3*(c - a^2*c*x^2)^p)/(2*(1 + p)*Sqrt[1 - a^2*x^2]) + (5*Sqrt[1 - a^2*x^2]*(c - a^2*c*x^2)^p)/(a^3*(1 + 2*p)) - ((1 - a^2*x^2)^(3/2)*(c - a^2*c*x^2)^p)/(a^3*(3 + 2*p)) + (x*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2, 3/2 - p, 3/2, a^2*x^2])/((1 - a^2*x^2)^p*(2*a^2*p)) + (9*x*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2, 3/2 - p, 3/2, a^2*x^2])/((1 - a^2*x^2)^p*(4*a^2*p*(1 + p)))}
{E^(3*ArcTanh[a*x])*(c - a^2*c*x^2)^p*x^1, x, 7, (3*(3 + 2*p)*(c - a^2*c*x^2)^p)/(4*a^2*(1 - 2*p)*p*(1 + p)*Sqrt[1 - a^2*x^2]) - (3*(3 + 2*p)*(1 + a*x)*(c - a^2*c*x^2)^p)/(4*a^2*p*(1 + p)*(1 + 2*p)*Sqrt[1 - a^2*x^2]) - (3*(1 + a*x)^2*(c - a^2*c*x^2)^p)/(2*a^2*(1 + p)*(1 + 2*p)*Sqrt[1 - a^2*x^2]) - ((1 + a*x)^3*(c - a^2*c*x^2)^p)/(2*a^2*(1 + p)*Sqrt[1 - a^2*x^2]) + (3*(3 + 2*p)*x*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2, 3/2 - p, 3/2, a^2*x^2])/((1 - a^2*x^2)^p*(4*a*p*(1 + p)))}
{E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^p*x^0, x, 6, ((3 + 2*p)*(c - a^2*c*x^2)^p)/(2*a*(1 - 2*p)*p*Sqrt[1 - a^2*x^2]) - ((3 + 2*p)*(1 + a*x)*(c - a^2*c*x^2)^p)/(2*a*p*(1 + 2*p)*Sqrt[1 - a^2*x^2]) - ((1 + a*x)^2*(c - a^2*c*x^2)^p)/(a*(1 + 2*p)*Sqrt[1 - a^2*x^2]) + ((3 + 2*p)*x*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2, 3/2 - p, 3/2, a^2*x^2])/((1 - a^2*x^2)^p*(2*p))}
{E^(3*ArcTanh[a*x])*(c - a^2*c*x^2)^p/x^1, x, 9, (3*(c - a^2*c*x^2)^p)/((1 - 2*p)*Sqrt[1 - a^2*x^2]) - (a*x*(c - a^2*c*x^2)^p)/(2*p*Sqrt[1 - a^2*x^2]) + (3*a*x*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2, 3/2 - p, 3/2, a^2*x^2])/(1 - a^2*x^2)^p + (a*x*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2, 3/2 - p, 3/2, a^2*x^2])/((1 - a^2*x^2)^p*(2*p)) - ((-((1 - a^2*x^2)/(a^2*x^2)))^(3/2 - p)*(c - a^2*c*x^2)^p*Hypergeometric2F1[3/2 - p, 3/2 - p, 5/2 - p, 1/(a^2*x^2)])/((3 - 2*p)*(1 - a^2*x^2)^(3/2))}
{E^(3*ArcTanh[a*x])*(c - a^2*c*x^2)^p/x^2, x, 9, (a*(c - a^2*c*x^2)^p)/((1 - 2*p)*Sqrt[1 - a^2*x^2]) - (c - a^2*c*x^2)^p/(x*Sqrt[1 - a^2*x^2]) + (3*a^2*x*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2, 3/2 - p, 3/2, a^2*x^2])/(1 - a^2*x^2)^p + (2*a^2*(1 - p)*x*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2, 3/2 - p, 3/2, a^2*x^2])/(1 - a^2*x^2)^p - (3*a*(-((1 - a^2*x^2)/(a^2*x^2)))^(3/2 - p)*(c - a^2*c*x^2)^p*Hypergeometric2F1[3/2 - p, 3/2 - p, 5/2 - p, 1/(a^2*x^2)])/((3 - 2*p)*(1 - a^2*x^2)^(3/2))}
{E^(3*ArcTanh[a*x])*(c - a^2*c*x^2)^p/x^3, x, 13, (a^2*(3 - 2*p)*(c - a^2*c*x^2)^p)/(2*(1 - 2*p)*Sqrt[1 - a^2*x^2]) - (c - a^2*c*x^2)^p/(2*x^2*Sqrt[1 - a^2*x^2]) - (3*a*(c - a^2*c*x^2)^p)/(x*Sqrt[1 - a^2*x^2]) - (a^2*(3 - 2*p)*Sqrt[1 - a^2*x^2]*(c - a^2*c*x^2)^p)/(2*(1 + 2*p)) + (a^3*x*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2, 3/2 - p, 3/2, a^2*x^2])/(1 - a^2*x^2)^p + (6*a^3*(1 - p)*x*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2, 3/2 - p, 3/2, a^2*x^2])/(1 - a^2*x^2)^p - (a^2*(3 - 2*p)*(1 - a^2*x^2)^(3/2)*(c - a^2*c*x^2)^p*Hypergeometric2F1[1, 3/2 + p, 5/2 + p, 1 - a^2*x^2])/(2*(3 + 2*p)) - (3*a^2*(-((1 - a^2*x^2)/(a^2*x^2)))^(3/2 - p)*(c - a^2*c*x^2)^p*Hypergeometric2F1[3/2 - p, 3/2 - p, 5/2 - p, 1/(a^2*x^2)])/((3 - 2*p)*(1 - a^2*x^2)^(3/2))}


(* ::Section::Closed:: *)
(*Integrands of the form x^m E^(4 ArcTanh[a x]) (c-c a^2 x^2)^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(4 ArcTanh[a x]) (c-c a^2 x^2)^p*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{E^(4*ArcTanh[a*x])*(c - c*a^2*x^2)^5, x, 3, (c^5*(1 + a*x)^8)/a - (4*c^5*(1 + a*x)^9)/(3*a) + (3*c^5*(1 + a*x)^10)/(5*a) - (c^5*(1 + a*x)^11)/(11*a)}
{E^(4*ArcTanh[a*x])*(c - c*a^2*x^2)^4, x, 3, (4*c^4*(1 + a*x)^7)/(7*a) - (c^4*(1 + a*x)^8)/(2*a) + (c^4*(1 + a*x)^9)/(9*a)}
{E^(4*ArcTanh[a*x])*(c - c*a^2*x^2)^3, x, 3, (c^3*(1 + a*x)^6)/(3*a) - (c^3*(1 + a*x)^7)/(7*a)}
{E^(4*ArcTanh[a*x])*(c - c*a^2*x^2)^2, x, 2, (c^2*(1 + a*x)^5)/(5*a)}
{E^(4*ArcTanh[a*x])*(c - c*a^2*x^2)^1, x, 3, -7*c*x - 2*a*c*x^2 - (1/3)*a^2*c*x^3 - (8*c*Log[1 - a*x])/a, -4*c*x - (c*(1 + a*x)^2)/a - (c*(1 + a*x)^3)/(3*a) - (8*c*Log[1 - a*x])/a}


(* ::Subsubsection::Closed:: *)
(*p<0*)


{E^(4*ArcTanh[a*x])/(c - c*a^2*x^2)^1, x, 2, (1 + a*x)^2/(4*a*c*(1 - a*x)^2)}
{E^(4*ArcTanh[a*x])/(c - c*a^2*x^2)^2, x, 2, 1/(3*a*c^2*(1 - a*x)^3)}
{E^(4*ArcTanh[a*x])/(c - c*a^2*x^2)^3, x, 4, 1/(8*a*c^3*(1 - a*x)^4) + 1/(12*a*c^3*(1 - a*x)^3) + 1/(16*a*c^3*(1 - a*x)^2) + 1/(16*a*c^3*(1 - a*x)) + ArcTanh[a*x]/(16*a*c^3)}
{E^(4*ArcTanh[a*x])/(c - c*a^2*x^2)^4, x, 4, 1/(20*a*c^4*(1 - a*x)^5) + 1/(16*a*c^4*(1 - a*x)^4) + 1/(16*a*c^4*(1 - a*x)^3) + 1/(16*a*c^4*(1 - a*x)^2) + 5/(64*a*c^4*(1 - a*x)) - 1/(64*a*c^4*(1 + a*x)) + (3*ArcTanh[a*x])/(32*a*c^4)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(4 ArcTanh[a x]) (c-c a^2 x^2)^(p/2)*)


(* ::Subsubsection:: *)
(*p>0*)


(* ::Subsubsection:: *)
(*p<0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(4 ArcTanh[a x]) (c-c a^2 x^2)^p with p symbolic*)


{E^(4*ArcTanh[a*x])*(c - c*a^2*x^2)^p, x, 6, -((2*c*(1 + p)*(2 + p)*(c - a^2*c*x^2)^(-1 + p))/(a*(1 - 2*p)*(1 - p)*(1 + 2*p))) + (2*c*(1 + p)*(2 + p)*(1 + a*x)*(c - a^2*c*x^2)^(-1 + p))/(a*p*(1 - 4*p^2)) - (c*(2 + p)*(1 + a*x)^2*(c - a^2*c*x^2)^(-1 + p))/(a*p*(1 + 2*p)) - (c*(1 + a*x)^3*(c - a^2*c*x^2)^(-1 + p))/(a*(1 + 2*p)) - (4*c^2*(1 + p)*(2 + p)*x*(1 - a^2*x^2)^(2 - p)*(c - a^2*c*x^2)^(-2 + p)*Hypergeometric2F1[1/2, 2 - p, 3/2, a^2*x^2])/(1 - 4*p^2)}


(* ::Section::Closed:: *)
(*Integrands of the form x^m E^(-1 ArcTanh[a x]) (c-c a^2 x^2)^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(-ArcTanh[a x]) (c-c a^2 x^2)^p*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{1/E^ArcTanh[a*x]*(c - c*a^2*x^2)^4, x, 7, (35/128)*c^4*x*Sqrt[1 - a^2*x^2] + (35/192)*c^4*x*(1 - a^2*x^2)^(3/2) + (7/48)*c^4*x*(1 - a^2*x^2)^(5/2) + (1/8)*c^4*x*(1 - a^2*x^2)^(7/2) + (c^4*(1 - a^2*x^2)^(9/2))/(9*a) + (35*c^4*ArcSin[a*x])/(128*a)}
{1/E^ArcTanh[a*x]*(c - c*a^2*x^2)^3, x, 6, (5/16)*c^3*x*Sqrt[1 - a^2*x^2] + (5/24)*c^3*x*(1 - a^2*x^2)^(3/2) + (1/6)*c^3*x*(1 - a^2*x^2)^(5/2) + (c^3*(1 - a^2*x^2)^(7/2))/(7*a) + (5*c^3*ArcSin[a*x])/(16*a)}
{1/E^ArcTanh[a*x]*(c - c*a^2*x^2)^2, x, 5, (3/8)*c^2*x*Sqrt[1 - a^2*x^2] + (1/4)*c^2*x*(1 - a^2*x^2)^(3/2) + (c^2*(1 - a^2*x^2)^(5/2))/(5*a) + (3*c^2*ArcSin[a*x])/(8*a)}
{1/E^ArcTanh[a*x]*(c - c*a^2*x^2)^1, x, 4, (1/2)*c*x*Sqrt[1 - a^2*x^2] + (c*(1 - a^2*x^2)^(3/2))/(3*a) + (c*ArcSin[a*x])/(2*a)}


(* ::Subsubsection::Closed:: *)
(*p<0*)


{1/E^ArcTanh[a*x]/(c - c*a^2*x^2)^1, x, 1, -(1/(E^ArcTanh[a*x]*(a*c)))}
{1/E^ArcTanh[a*x]/(c - c*a^2*x^2)^2, x, 3, (2*x)/(3*c^2*Sqrt[1 - a^2*x^2]) - 1/(3*a*c^2*(1 + a*x)*Sqrt[1 - a^2*x^2])}
{1/E^ArcTanh[a*x]/(c - c*a^2*x^2)^3, x, 4, (4*x)/(15*c^3*(1 - a^2*x^2)^(3/2)) - 1/(5*a*c^3*(1 + a*x)*(1 - a^2*x^2)^(3/2)) + (8*x)/(15*c^3*Sqrt[1 - a^2*x^2])}
{1/E^ArcTanh[a*x]/(c - c*a^2*x^2)^4, x, 5, (6*x)/(35*c^4*(1 - a^2*x^2)^(5/2)) - 1/(7*a*c^4*(1 + a*x)*(1 - a^2*x^2)^(5/2)) + (8*x)/(35*c^4*(1 - a^2*x^2)^(3/2)) + (16*x)/(35*c^4*Sqrt[1 - a^2*x^2])}
{1/E^ArcTanh[a*x]/(c - c*a^2*x^2)^5, x, 6, (8*x)/(63*c^5*(1 - a^2*x^2)^(7/2)) - 1/(9*a*c^5*(1 + a*x)*(1 - a^2*x^2)^(7/2)) + (16*x)/(105*c^5*(1 - a^2*x^2)^(5/2)) + (64*x)/(315*c^5*(1 - a^2*x^2)^(3/2)) + (128*x)/(315*c^5*Sqrt[1 - a^2*x^2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(-ArcTanh[a x]) (c-c a^2 x^2)^(p/2)*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{1/E^ArcTanh[a*x]*(c - c*a^2*x^2)^(1/2)*x^m, x, 4, (x^(1 + m)*Sqrt[c - a^2*c*x^2])/((1 + m)*Sqrt[1 - a^2*x^2]) - (a*x^(2 + m)*Sqrt[c - a^2*c*x^2])/((2 + m)*Sqrt[1 - a^2*x^2])}

{1/E^ArcTanh[a*x]*(c - c*a^2*x^2)^(1/2)*x^2, x, 4, (x^3*Sqrt[c - a^2*c*x^2])/(3*Sqrt[1 - a^2*x^2]) - (a*x^4*Sqrt[c - a^2*c*x^2])/(4*Sqrt[1 - a^2*x^2])}
{1/E^ArcTanh[a*x]*(c - c*a^2*x^2)^(1/2)*x^1, x, 4, (x^2*Sqrt[c - a^2*c*x^2])/(2*Sqrt[1 - a^2*x^2]) - (a*x^3*Sqrt[c - a^2*c*x^2])/(3*Sqrt[1 - a^2*x^2])}
{1/E^ArcTanh[a*x]*(c - c*a^2*x^2)^(1/2)*x^0, x, 4, (x*Sqrt[c - a^2*c*x^2])/Sqrt[1 - a^2*x^2] - (a*x^2*Sqrt[c - a^2*c*x^2])/(2*Sqrt[1 - a^2*x^2])}
{1/E^ArcTanh[a*x]*(c - c*a^2*x^2)^(1/2)/x^1, x, 4, -((a*x*Sqrt[c - a^2*c*x^2])/Sqrt[1 - a^2*x^2]) + (Sqrt[c - a^2*c*x^2]*Log[x])/Sqrt[1 - a^2*x^2]}
{1/E^ArcTanh[a*x]*(c - c*a^2*x^2)^(1/2)/x^2, x, 4, -(Sqrt[c - a^2*c*x^2]/(x*Sqrt[1 - a^2*x^2])) - (a*Sqrt[c - a^2*c*x^2]*Log[x])/Sqrt[1 - a^2*x^2]}


{1/E^ArcTanh[a*x]*(c - c*a^2*x^2)^(9/2), x, 5, -((8*c^4*(1 - a*x)^6*Sqrt[c - a^2*c*x^2])/(3*a*Sqrt[1 - a^2*x^2])) + (32*c^4*(1 - a*x)^7*Sqrt[c - a^2*c*x^2])/(7*a*Sqrt[1 - a^2*x^2]) - (3*c^4*(1 - a*x)^8*Sqrt[c - a^2*c*x^2])/(a*Sqrt[1 - a^2*x^2]) + (8*c^4*(1 - a*x)^9*Sqrt[c - a^2*c*x^2])/(9*a*Sqrt[1 - a^2*x^2]) - (c^4*(1 - a*x)^10*Sqrt[c - a^2*c*x^2])/(10*a*Sqrt[1 - a^2*x^2])}
{1/E^ArcTanh[a*x]*(c - c*a^2*x^2)^(7/2), x, 5, -((8*c^3*(1 - a*x)^5*Sqrt[c - a^2*c*x^2])/(5*a*Sqrt[1 - a^2*x^2])) + (2*c^3*(1 - a*x)^6*Sqrt[c - a^2*c*x^2])/(a*Sqrt[1 - a^2*x^2]) - (6*c^3*(1 - a*x)^7*Sqrt[c - a^2*c*x^2])/(7*a*Sqrt[1 - a^2*x^2]) + (c^3*(1 - a*x)^8*Sqrt[c - a^2*c*x^2])/(8*a*Sqrt[1 - a^2*x^2])}
{1/E^ArcTanh[a*x]*(c - c*a^2*x^2)^(5/2), x, 5, -((c^2*(1 - a*x)^4*Sqrt[c - a^2*c*x^2])/(a*Sqrt[1 - a^2*x^2])) + (4*c^2*(1 - a*x)^5*Sqrt[c - a^2*c*x^2])/(5*a*Sqrt[1 - a^2*x^2]) - (c^2*(1 - a*x)^6*Sqrt[c - a^2*c*x^2])/(6*a*Sqrt[1 - a^2*x^2])}
{1/E^ArcTanh[a*x]*(c - c*a^2*x^2)^(3/2), x, 5, (c*x*Sqrt[c - a^2*c*x^2])/Sqrt[1 - a^2*x^2] - (a*c*x^2*Sqrt[c - a^2*c*x^2])/(2*Sqrt[1 - a^2*x^2]) - (a^2*c*x^3*Sqrt[c - a^2*c*x^2])/(3*Sqrt[1 - a^2*x^2]) + (a^3*c*x^4*Sqrt[c - a^2*c*x^2])/(4*Sqrt[1 - a^2*x^2])}
{1/E^ArcTanh[a*x]*(c - c*a^2*x^2)^(1/2), x, 4, (x*Sqrt[c - a^2*c*x^2])/Sqrt[1 - a^2*x^2] - (a*x^2*Sqrt[c - a^2*c*x^2])/(2*Sqrt[1 - a^2*x^2])}


(* ::Subsubsection::Closed:: *)
(*p<0*)


{1/E^ArcTanh[a*x]/(c - c*a^2*x^2)^(1/2), x, 3, (Sqrt[1 - a^2*x^2]*Log[1 + a*x])/(a*Sqrt[c - a^2*c*x^2])}
{1/E^ArcTanh[a*x]/(c - c*a^2*x^2)^(3/2), x, 6, -(Sqrt[1 - a^2*x^2]/(2*a*c*(1 + a*x)*Sqrt[c - a^2*c*x^2])) + (Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(2*a*c*Sqrt[c - a^2*c*x^2])}
{1/E^ArcTanh[a*x]/(c - c*a^2*x^2)^(5/2), x, 6, Sqrt[1 - a^2*x^2]/(8*a*c^2*(1 - a*x)*Sqrt[c - a^2*c*x^2]) - Sqrt[1 - a^2*x^2]/(8*a*c^2*(1 + a*x)^2*Sqrt[c - a^2*c*x^2]) - Sqrt[1 - a^2*x^2]/(4*a*c^2*(1 + a*x)*Sqrt[c - a^2*c*x^2]) + (3*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(8*a*c^2*Sqrt[c - a^2*c*x^2])}
{1/E^ArcTanh[a*x]/(c - c*a^2*x^2)^(7/2), x, 6, Sqrt[1 - a^2*x^2]/(32*a*c^3*(1 - a*x)^2*Sqrt[c - a^2*c*x^2]) + Sqrt[1 - a^2*x^2]/(8*a*c^3*(1 - a*x)*Sqrt[c - a^2*c*x^2]) - Sqrt[1 - a^2*x^2]/(24*a*c^3*(1 + a*x)^3*Sqrt[c - a^2*c*x^2]) - (3*Sqrt[1 - a^2*x^2])/(32*a*c^3*(1 + a*x)^2*Sqrt[c - a^2*c*x^2]) - (3*Sqrt[1 - a^2*x^2])/(16*a*c^3*(1 + a*x)*Sqrt[c - a^2*c*x^2]) + (5*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(16*a*c^3*Sqrt[c - a^2*c*x^2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(-ArcTanh[a x]) (c-c a^2 x^2)^p with p symbolic*)


{1/E^ArcTanh[a*x]*(c - a^2*c*x^2)^p*x^m, x, 4, (x^(1 + m)*(c - a^2*c*x^2)^p*AppellF1[1 + m, -(1/2) - p, 1/2 - p, 2 + m, a*x, (-a)*x])/((1 - a^2*x^2)^p*(1 + m))}

{1/E^ArcTanh[a*x]*(c - a^2*c*x^2)^p*x^3, x, 10, ((1 - a^2*x^2)^(3/2)*(c - a^2*c*x^2)^p)/(a^4*(3 + 2*p)) - (x*(1 - a^2*x^2)^(3/2)*(c - a^2*c*x^2)^p)/(2*a^3*(2 + p)) - ((1 - a^2*x^2)^(3/2)*(c - a^2*c*x^2)^p)/(a^4*(1 + 2*p)*(1 + a*x)) + (x*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2, -(1/2) - p, 3/2, a^2*x^2])/((1 - a^2*x^2)^p*a^3) + (x*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2, -(1/2) - p, 3/2, a^2*x^2])/((1 - a^2*x^2)^p*(2*a^3*(2 + p))) - (2*(1 + p)*x*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2, -(1/2) - p, 3/2, a^2*x^2])/((1 - a^2*x^2)^p*(a^3*(1 + 2*p)))}
{1/E^ArcTanh[a*x]*(c - a^2*c*x^2)^p*x^2, x, 8, -(((1 - a^2*x^2)^(3/2)*(c - a^2*c*x^2)^p)/(a^3*(3 + 2*p))) + ((1 - a^2*x^2)^(3/2)*(c - a^2*c*x^2)^p)/(a^3*(1 + 2*p)*(1 + a*x)) - (x*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2, -(1/2) - p, 3/2, a^2*x^2])/((1 - a^2*x^2)^p*a^2) + (2*(1 + p)*x*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2, -(1/2) - p, 3/2, a^2*x^2])/((1 - a^2*x^2)^p*(a^2*(1 + 2*p)))}
{1/E^ArcTanh[a*x]*(c - a^2*c*x^2)^p*x^1, x, 5, -(((1 - a^2*x^2)^(3/2)*(c - a^2*c*x^2)^p)/(2*a^2*(1 + p)*(1 + a*x))) - ((1 - a^2*x^2)^(3/2)*(c - a^2*c*x^2)^p)/(2*a^2*(1 + p)*(1 + 2*p)*(1 + a*x)) - (x*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2, -(1/2) - p, 3/2, a^2*x^2])/((1 - a^2*x^2)^p*(a*(1 + 2*p)))}
{1/E^ArcTanh[a*x]*(c - c*a^2*x^2)^p*x^0, x, 4, ((1 - a^2*x^2)^(3/2)*(c - a^2*c*x^2)^p)/(a*(1 + 2*p)*(1 + a*x)) + (2*(1 + p)*x*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2, -(1/2) - p, 3/2, a^2*x^2])/((1 - a^2*x^2)^p*(1 + 2*p))}
{1/E^ArcTanh[a*x]*(c - a^2*c*x^2)^p/x^1, x, 7, -(((1 - a^2*x^2)^(3/2)*(c - a^2*c*x^2)^p)/((1 + 2*p)*(1 + a*x))) - (2*a*(1 + p)*x*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2, -(1/2) - p, 3/2, a^2*x^2])/((1 - a^2*x^2)^p*(1 + 2*p)) + (Sqrt[1 - a^2*x^2]*(-((1 - a^2*x^2)/(a^2*x^2)))^(-(1/2) - p)*(c - a^2*c*x^2)^p*Hypergeometric2F1[-(1/2) - p, -(1/2) - p, 1/2 - p, 1/(a^2*x^2)])/(1 + 2*p)}
{1/E^ArcTanh[a*x]*(c - a^2*c*x^2)^p/x^2, x, 9, -(((1 - a^2*x^2)^(3/2)*(c - a^2*c*x^2)^p)/x) + (a*(1 - a^2*x^2)^(3/2)*(c - a^2*c*x^2)^p)/((1 + 2*p)*(1 + a*x)) - (2*a^2*(1 + p)*x*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2, -(1/2) - p, 3/2, a^2*x^2])/(1 - a^2*x^2)^p + (2*a^2*(1 + p)*x*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2, -(1/2) - p, 3/2, a^2*x^2])/((1 - a^2*x^2)^p*(1 + 2*p)) - (a*Sqrt[1 - a^2*x^2]*(-((1 - a^2*x^2)/(a^2*x^2)))^(-(1/2) - p)*(c - a^2*c*x^2)^p*Hypergeometric2F1[-(1/2) - p, -(1/2) - p, 1/2 - p, 1/(a^2*x^2)])/(1 + 2*p)}
{1/E^ArcTanh[a*x]*(c - a^2*c*x^2)^p/x^3, x, 12, -(((1 - a^2*x^2)^(3/2)*(c - a^2*c*x^2)^p)/(2*x^2)) + (a*(1 - a^2*x^2)^(3/2)*(c - a^2*c*x^2)^p)/x - (a^2*(1 - a^2*x^2)^(3/2)*(c - a^2*c*x^2)^p)/((1 + 2*p)*(1 + a*x)) + (2*a^3*(1 + p)*x*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2, -(1/2) - p, 3/2, a^2*x^2])/(1 - a^2*x^2)^p - (2*a^3*(1 + p)*x*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2, -(1/2) - p, 3/2, a^2*x^2])/((1 - a^2*x^2)^p*(1 + 2*p)) + (a^2*(1 + 2*p)*(1 - a^2*x^2)^(3/2)*(c - a^2*c*x^2)^p*Hypergeometric2F1[1, 3/2 + p, 5/2 + p, 1 - a^2*x^2])/(2*(3 + 2*p)) + (a^2*Sqrt[1 - a^2*x^2]*(-((1 - a^2*x^2)/(a^2*x^2)))^(-(1/2) - p)*(c - a^2*c*x^2)^p*Hypergeometric2F1[-(1/2) - p, -(1/2) - p, 1/2 - p, 1/(a^2*x^2)])/(1 + 2*p)}


(* ::Section::Closed:: *)
(*Integrands of the form x^m E^(-2 ArcTanh[a x]) (c-c a^2 x^2)^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(-2 ArcTanh[a x]) (c-c a^2 x^2)^p*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{1/E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^4, x, 3, -((4*c^4*(1 - a*x)^6)/(3*a)) + (12*c^4*(1 - a*x)^7)/(7*a) - (3*c^4*(1 - a*x)^8)/(4*a) + (c^4*(1 - a*x)^9)/(9*a)}
{1/E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^3, x, 3, -((4*c^3*(1 - a*x)^5)/(5*a)) + (2*c^3*(1 - a*x)^6)/(3*a) - (c^3*(1 - a*x)^7)/(7*a)}
{1/E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^2, x, 3, c^2*x - a*c^2*x^2 + (1/2)*a^3*c^2*x^4 - (1/5)*a^4*c^2*x^5}
{1/E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^1, x, 2, -((c*(1 - a*x)^3)/(3*a))}


(* ::Subsubsection::Closed:: *)
(*p<0*)


{1/E^(2*ArcTanh[a*x])/(c - c*a^2*x^2)^1, x, 2, -(1/(a*c*(1 + a*x)))}
{1/E^(2*ArcTanh[a*x])/(c - c*a^2*x^2)^2, x, 4, -(1/(4*a*c^2*(1 + a*x)^2)) - 1/(4*a*c^2*(1 + a*x)) + ArcTanh[a*x]/(4*a*c^2)}
{1/E^(2*ArcTanh[a*x])/(c - c*a^2*x^2)^3, x, 4, 1/(16*a*c^3*(1 - a*x)) - 1/(12*a*c^3*(1 + a*x)^3) - 1/(8*a*c^3*(1 + a*x)^2) - 3/(16*a*c^3*(1 + a*x)) + ArcTanh[a*x]/(4*a*c^3)}
{1/E^(2*ArcTanh[a*x])/(c - c*a^2*x^2)^4, x, 4, 1/(64*a*c^4*(1 - a*x)^2) + 5/(64*a*c^4*(1 - a*x)) - 1/(32*a*c^4*(1 + a*x)^4) - 1/(16*a*c^4*(1 + a*x)^3) - 3/(32*a*c^4*(1 + a*x)^2) - 5/(32*a*c^4*(1 + a*x)) + (15*ArcTanh[a*x])/(64*a*c^4)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(-2 ArcTanh[a x]) (1-a^2 x^2)^(p/2)*)


(* ::Subsubsection:: *)
(*p>0*)


(* ::Subsubsection:: *)
(*p<0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(-2 ArcTanh[a x]) (c-c a^2 x^2)^(p/2)*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{1/E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)*x^m, x, 2, (x^(1 + m)*Sqrt[c - a^2*c*x^2]*AppellF1[1 + m, -(3/2), 1/2, 2 + m, a*x, (-a)*x])/((1 + m)*Sqrt[1 - a*x]*Sqrt[1 + a*x])}

{1/E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)*x^3, x, 7, -((3*Sqrt[c - a^2*c*x^2])/(4*a^4)) - (9*(1 - a*x)*Sqrt[c - a^2*c*x^2])/(20*a^4) + (3*x*(1 - a*x)*Sqrt[c - a^2*c*x^2])/(10*a^3) - (3*x^2*(1 - a*x)*Sqrt[c - a^2*c*x^2])/(10*a^2) + (x^3*(1 - a*x)*Sqrt[c - a^2*c*x^2])/(5*a) - (3*Sqrt[c - a^2*c*x^2]*ArcSin[a*x])/(4*a^4*Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{1/E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)*x^2, x, 6, (7*Sqrt[c - a^2*c*x^2])/(8*a^3) + (7*(1 - a*x)*Sqrt[c - a^2*c*x^2])/(24*a^3) + ((1 - a*x)^2*Sqrt[c - a^2*c*x^2])/(6*a^3) - (x*(1 - a*x)^2*Sqrt[c - a^2*c*x^2])/(4*a^2) + (7*Sqrt[c - a^2*c*x^2]*ArcSin[a*x])/(8*a^3*Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{1/E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)*x^1, x, 5, -((x*Sqrt[c - a^2*c*x^2])/a) - (2*(c - a^2*c*x^2)^(3/2))/(3*a^2*c) - (c - a^2*c*x^2)^(5/2)/(a^2*c^2*(1 + a*x)^2) - (Sqrt[c]*ArcTan[(a*Sqrt[c]*x)/Sqrt[c - a^2*c*x^2]])/a^2}
{1/E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)*x^0, x, 4, (3/2)*x*Sqrt[c - a^2*c*x^2] + (2*(c - a^2*c*x^2)^(3/2))/(a*c*(1 + a*x)) + (3*Sqrt[c]*ArcTan[(a*Sqrt[c]*x)/Sqrt[c - a^2*c*x^2]])/(2*a)}
{1/E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)/x^1, x, 5, -Sqrt[c - a^2*c*x^2] - (2*Sqrt[c - a^2*c*x^2]*ArcSin[a*x])/(Sqrt[1 - a*x]*Sqrt[1 + a*x]) - (2*Sqrt[c - a^2*c*x^2]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{1/E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)/x^2, x, 6, (-a)*Sqrt[c - a^2*c*x^2] - ((1 - a*x)*Sqrt[c - a^2*c*x^2])/x + (a*Sqrt[c - a^2*c*x^2]*ArcSin[a*x])/(Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (4*a*Sqrt[c - a^2*c*x^2]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{1/E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)/x^3, x, 4, (3*a*Sqrt[c - a^2*c*x^2])/(2*x) - ((1 - a*x)*Sqrt[c - a^2*c*x^2])/(2*x^2) - (3*a^2*Sqrt[c - a^2*c*x^2]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{1/E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)/x^4, x, 6, (2*a*Sqrt[c - a^2*c*x^2])/(3*x^2) - (5*a^2*Sqrt[c - a^2*c*x^2])/(3*x) - ((1 - a*x)*Sqrt[c - a^2*c*x^2])/(3*x^3) + (2*a^3*Sqrt[c - a^2*c*x^2]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{1/E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)/x^5, x, 7, (5*a*Sqrt[c - a^2*c*x^2])/(12*x^3) - (7*a^2*Sqrt[c - a^2*c*x^2])/(8*x^2) + (4*a^3*Sqrt[c - a^2*c*x^2])/(3*x) - ((1 - a*x)*Sqrt[c - a^2*c*x^2])/(4*x^4) - (7*a^4*Sqrt[c - a^2*c*x^2]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(4*Sqrt[1 - a*x]*Sqrt[1 + a*x])}


{1/E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(7/2), x, 7, (45/128)*c^3*x*Sqrt[c - a^2*c*x^2] + (15/64)*c^2*x*(c - a^2*c*x^2)^(3/2) + (3/16)*c*x*(c - a^2*c*x^2)^(5/2) + (9/56)*x*(c - a^2*c*x^2)^(7/2) + (2*(c - a^2*c*x^2)^(9/2))/(7*a*c*(1 + a*x)) + (45*c^(7/2)*ArcTan[(a*Sqrt[c]*x)/Sqrt[c - a^2*c*x^2]])/(128*a)}
{1/E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(5/2), x, 6, (7/16)*c^2*x*Sqrt[c - a^2*c*x^2] + (7/24)*c*x*(c - a^2*c*x^2)^(3/2) + (7/30)*x*(c - a^2*c*x^2)^(5/2) + (2*(c - a^2*c*x^2)^(7/2))/(5*a*c*(1 + a*x)) + (7*c^(5/2)*ArcTan[(a*Sqrt[c]*x)/Sqrt[c - a^2*c*x^2]])/(16*a)}
{1/E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(3/2), x, 5, (5/8)*c*x*Sqrt[c - a^2*c*x^2] + (5/12)*x*(c - a^2*c*x^2)^(3/2) + (2*(c - a^2*c*x^2)^(5/2))/(3*a*c*(1 + a*x)) + (5*c^(3/2)*ArcTan[(a*Sqrt[c]*x)/Sqrt[c - a^2*c*x^2]])/(8*a)}
{1/E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2), x, 4, (3/2)*x*Sqrt[c - a^2*c*x^2] + (2*(c - a^2*c*x^2)^(3/2))/(a*c*(1 + a*x)) + (3*Sqrt[c]*ArcTan[(a*Sqrt[c]*x)/Sqrt[c - a^2*c*x^2]])/(2*a)}


(* ::Subsubsection::Closed:: *)
(*p<0*)


{1/E^(2*ArcTanh[a*x])/(c - c*a^2*x^2)^(1/2), x, 3, -((2*Sqrt[c - a^2*c*x^2])/(a*c*(1 + a*x))) - ArcTan[(a*Sqrt[c]*x)/Sqrt[c - a^2*c*x^2]]/(a*Sqrt[c])}
{1/E^(2*ArcTanh[a*x])/(c - c*a^2*x^2)^(3/2), x, 3, -(Sqrt[c - a^2*c*x^2]/(3*a*c^2*(1 + a*x)^2)) - Sqrt[c - a^2*c*x^2]/(3*a*c^2*(1 + a*x))}
{1/E^(2*ArcTanh[a*x])/(c - c*a^2*x^2)^(5/2), x, 4, (2*x)/(5*c^2*Sqrt[c - a^2*c*x^2]) - 1/(5*a*c^2*(1 + a*x)^2*Sqrt[c - a^2*c*x^2]) - 1/(5*a*c^2*(1 + a*x)*Sqrt[c - a^2*c*x^2])}
{1/E^(2*ArcTanh[a*x])/(c - c*a^2*x^2)^(7/2), x, 5, (4*x)/(21*c^2*(c - a^2*c*x^2)^(3/2)) - 1/(7*a*c^2*(1 + a*x)^2*(c - a^2*c*x^2)^(3/2)) - 1/(7*a*c^2*(1 + a*x)*(c - a^2*c*x^2)^(3/2)) + (8*x)/(21*c^3*Sqrt[c - a^2*c*x^2])}
{1/E^(2*ArcTanh[a*x])/(c - c*a^2*x^2)^(9/2), x, 6, (2*x)/(15*c^2*(c - a^2*c*x^2)^(5/2)) - 1/(9*a*c^2*(1 + a*x)^2*(c - a^2*c*x^2)^(5/2)) - 1/(9*a*c^2*(1 + a*x)*(c - a^2*c*x^2)^(5/2)) + (8*x)/(45*c^3*(c - a^2*c*x^2)^(3/2)) + (16*x)/(45*c^4*Sqrt[c - a^2*c*x^2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(-2 ArcTanh[a x]) (c-c a^2 x^2)^p with p symbolic*)


{1/E^(2*ArcTanh[a*x])*(c - c*a^2*x^2)^p, x, 4, (c - a^2*c*x^2)^(2 + p)/(2*a*c^2*p*(1 + a*x)^2) + (c - a^2*c*x^2)^(2 + p)/(2*a*c^2*p*(1 + a*x)) + ((3 + 2*p)*x*(1 - a^2*x^2)^(-1 - p)*(c - a^2*c*x^2)^(1 + p)*Hypergeometric2F1[1/2, -1 - p, 3/2, a^2*x^2])/(2*c*p)}


(* ::Section::Closed:: *)
(*Integrands of the form x^m E^(-3 ArcTanh[a x]) (c-c a^2 x^2)^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(-3 ArcTanh[a x]) (c-c a^2 x^2)^p*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{1/E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^4, x, 8, (55/128)*c^4*x*Sqrt[1 - a^2*x^2] + (55/192)*c^4*x*(1 - a^2*x^2)^(3/2) + (11/48)*c^4*x*(1 - a^2*x^2)^(5/2) + (11/56)*c^4*x*(1 - a^2*x^2)^(7/2) + (11*c^4*(1 - a^2*x^2)^(9/2))/(63*a) + (2*c^4*(1 - a^2*x^2)^(11/2))/(7*a*(1 + a*x)^2) + (55*c^4*ArcSin[a*x])/(128*a)}
{1/E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^3, x, 7, (9/16)*c^3*x*Sqrt[1 - a^2*x^2] + (3/8)*c^3*x*(1 - a^2*x^2)^(3/2) + (3/10)*c^3*x*(1 - a^2*x^2)^(5/2) + (9*c^3*(1 - a^2*x^2)^(7/2))/(35*a) + (2*c^3*(1 - a^2*x^2)^(9/2))/(5*a*(1 + a*x)^2) + (9*c^3*ArcSin[a*x])/(16*a)}
{1/E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^2, x, 6, (7/8)*c^2*x*Sqrt[1 - a^2*x^2] + (7/12)*c^2*x*(1 - a^2*x^2)^(3/2) + (7*c^2*(1 - a^2*x^2)^(5/2))/(15*a) + (2*c^2*(1 - a^2*x^2)^(7/2))/(3*a*(1 + a*x)^2) + (7*c^2*ArcSin[a*x])/(8*a)}
{1/E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^1, x, 5, (5/2)*c*x*Sqrt[1 - a^2*x^2] + (5*c*(1 - a^2*x^2)^(3/2))/(3*a) + (2*c*(1 - a^2*x^2)^(5/2))/(a*(1 + a*x)^2) + (5*c*ArcSin[a*x])/(2*a)}


(* ::Subsubsection::Closed:: *)
(*p<0*)


{1/E^(3*ArcTanh[a*x])/(c - c*a^2*x^2)^1, x, 1, -(1/(E^(3*ArcTanh[a*x])*(3*a*c)))}
{1/E^(3*ArcTanh[a*x])/(c - c*a^2*x^2)^2, x, 4, -(Sqrt[1 - a^2*x^2]/(5*a*c^2*(1 + a*x)^3)) - (2*Sqrt[1 - a^2*x^2])/(15*a*c^2*(1 + a*x)^2) - (2*Sqrt[1 - a^2*x^2])/(15*a*c^2*(1 + a*x))}
{1/E^(3*ArcTanh[a*x])/(c - c*a^2*x^2)^3, x, 5, (8*x)/(35*c^3*Sqrt[1 - a^2*x^2]) - 1/(7*a*c^3*(1 + a*x)^3*Sqrt[1 - a^2*x^2]) - 4/(35*a*c^3*(1 + a*x)^2*Sqrt[1 - a^2*x^2]) - 4/(35*a*c^3*(1 + a*x)*Sqrt[1 - a^2*x^2])}
{1/E^(3*ArcTanh[a*x])/(c - c*a^2*x^2)^4, x, 6, (8*x)/(63*c^4*(1 - a^2*x^2)^(3/2)) - 1/(9*a*c^4*(1 + a*x)^3*(1 - a^2*x^2)^(3/2)) - 2/(21*a*c^4*(1 + a*x)^2*(1 - a^2*x^2)^(3/2)) - 2/(21*a*c^4*(1 + a*x)*(1 - a^2*x^2)^(3/2)) + (16*x)/(63*c^4*Sqrt[1 - a^2*x^2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(-3 ArcTanh[a x]) (c-c a^2 x^2)^(p/2)*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{1/E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)*x^m, x, 5, -(((5 + 2*m)*x^(1 + m)*Sqrt[c - a^2*c*x^2])/((1 + m)*(2 + m)*Sqrt[1 - a^2*x^2])) - (x^(1 + m)*(1 - a*x)*Sqrt[c - a^2*c*x^2])/((2 + m)*Sqrt[1 - a^2*x^2]) + (4*x^(1 + m)*Sqrt[c - a^2*c*x^2]*Hypergeometric2F1[1, 1 + m, 2 + m, (-a)*x])/((1 + m)*Sqrt[1 - a^2*x^2])}

{1/E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)*x^3, x, 4, (4*x*Sqrt[c - a^2*c*x^2])/(a^3*Sqrt[1 - a^2*x^2]) - (2*x^2*Sqrt[c - a^2*c*x^2])/(a^2*Sqrt[1 - a^2*x^2]) + (4*x^3*Sqrt[c - a^2*c*x^2])/(3*a*Sqrt[1 - a^2*x^2]) - (3*x^4*Sqrt[c - a^2*c*x^2])/(4*Sqrt[1 - a^2*x^2]) + (a*x^5*Sqrt[c - a^2*c*x^2])/(5*Sqrt[1 - a^2*x^2]) - (4*Sqrt[c - a^2*c*x^2]*Log[1 + a*x])/(a^4*Sqrt[1 - a^2*x^2])}
{1/E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)*x^2, x, 4, -((4*x*Sqrt[c - a^2*c*x^2])/(a^2*Sqrt[1 - a^2*x^2])) + (2*x^2*Sqrt[c - a^2*c*x^2])/(a*Sqrt[1 - a^2*x^2]) - (x^3*Sqrt[c - a^2*c*x^2])/Sqrt[1 - a^2*x^2] + (a*x^4*Sqrt[c - a^2*c*x^2])/(4*Sqrt[1 - a^2*x^2]) + (4*Sqrt[c - a^2*c*x^2]*Log[1 + a*x])/(a^3*Sqrt[1 - a^2*x^2])}
{1/E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)*x^1, x, 4, (4*x*Sqrt[c - a^2*c*x^2])/(a*Sqrt[1 - a^2*x^2]) - (3*x^2*Sqrt[c - a^2*c*x^2])/(2*Sqrt[1 - a^2*x^2]) + (a*x^3*Sqrt[c - a^2*c*x^2])/(3*Sqrt[1 - a^2*x^2]) - (4*Sqrt[c - a^2*c*x^2]*Log[1 + a*x])/(a^2*Sqrt[1 - a^2*x^2])}
{1/E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)*x^0, x, 5, -((3*x*Sqrt[c - a^2*c*x^2])/Sqrt[1 - a^2*x^2]) + (a*x^2*Sqrt[c - a^2*c*x^2])/(2*Sqrt[1 - a^2*x^2]) + (4*Sqrt[c - a^2*c*x^2]*Log[1 + a*x])/(a*Sqrt[1 - a^2*x^2])}
{1/E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)/x^1, x, 4, (a*x*Sqrt[c - a^2*c*x^2])/Sqrt[1 - a^2*x^2] + (Sqrt[c - a^2*c*x^2]*Log[x])/Sqrt[1 - a^2*x^2] - (4*Sqrt[c - a^2*c*x^2]*Log[1 + a*x])/Sqrt[1 - a^2*x^2]}
{1/E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)/x^2, x, 4, -(Sqrt[c - a^2*c*x^2]/(x*Sqrt[1 - a^2*x^2])) - (3*a*Sqrt[c - a^2*c*x^2]*Log[x])/Sqrt[1 - a^2*x^2] + (4*a*Sqrt[c - a^2*c*x^2]*Log[1 + a*x])/Sqrt[1 - a^2*x^2]}
{1/E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)/x^3, x, 4, -(Sqrt[c - a^2*c*x^2]/(2*x^2*Sqrt[1 - a^2*x^2])) + (3*a*Sqrt[c - a^2*c*x^2])/(x*Sqrt[1 - a^2*x^2]) + (4*a^2*Sqrt[c - a^2*c*x^2]*Log[x])/Sqrt[1 - a^2*x^2] - (4*a^2*Sqrt[c - a^2*c*x^2]*Log[1 + a*x])/Sqrt[1 - a^2*x^2]}
{1/E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)/x^4, x, 4, -(Sqrt[c - a^2*c*x^2]/(3*x^3*Sqrt[1 - a^2*x^2])) + (3*a*Sqrt[c - a^2*c*x^2])/(2*x^2*Sqrt[1 - a^2*x^2]) - (4*a^2*Sqrt[c - a^2*c*x^2])/(x*Sqrt[1 - a^2*x^2]) - (4*a^3*Sqrt[c - a^2*c*x^2]*Log[x])/Sqrt[1 - a^2*x^2] + (4*a^3*Sqrt[c - a^2*c*x^2]*Log[1 + a*x])/Sqrt[1 - a^2*x^2]}
{1/E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2)/x^5, x, 4, -(Sqrt[c - a^2*c*x^2]/(4*x^4*Sqrt[1 - a^2*x^2])) + (a*Sqrt[c - a^2*c*x^2])/(x^3*Sqrt[1 - a^2*x^2]) - (2*a^2*Sqrt[c - a^2*c*x^2])/(x^2*Sqrt[1 - a^2*x^2]) + (4*a^3*Sqrt[c - a^2*c*x^2])/(x*Sqrt[1 - a^2*x^2]) + (4*a^4*Sqrt[c - a^2*c*x^2]*Log[x])/Sqrt[1 - a^2*x^2] - (4*a^4*Sqrt[c - a^2*c*x^2]*Log[1 + a*x])/Sqrt[1 - a^2*x^2]}


{1/E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^(9/2), x, 5, -((8*c^4*(1 - a*x)^7*Sqrt[c - a^2*c*x^2])/(7*a*Sqrt[1 - a^2*x^2])) + (3*c^4*(1 - a*x)^8*Sqrt[c - a^2*c*x^2])/(2*a*Sqrt[1 - a^2*x^2]) - (2*c^4*(1 - a*x)^9*Sqrt[c - a^2*c*x^2])/(3*a*Sqrt[1 - a^2*x^2]) + (c^4*(1 - a*x)^10*Sqrt[c - a^2*c*x^2])/(10*a*Sqrt[1 - a^2*x^2])}
{1/E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^(7/2), x, 5, -((2*c^3*(1 - a*x)^6*Sqrt[c - a^2*c*x^2])/(3*a*Sqrt[1 - a^2*x^2])) + (4*c^3*(1 - a*x)^7*Sqrt[c - a^2*c*x^2])/(7*a*Sqrt[1 - a^2*x^2]) - (c^3*(1 - a*x)^8*Sqrt[c - a^2*c*x^2])/(8*a*Sqrt[1 - a^2*x^2])}
{1/E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^(5/2), x, 5, -((2*c^2*(1 - a*x)^5*Sqrt[c - a^2*c*x^2])/(5*a*Sqrt[1 - a^2*x^2])) + (c^2*(1 - a*x)^6*Sqrt[c - a^2*c*x^2])/(6*a*Sqrt[1 - a^2*x^2])}
{1/E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^(3/2), x, 4, -((c*(1 - a*x)^4*Sqrt[c - a^2*c*x^2])/(4*a*Sqrt[1 - a^2*x^2]))}
{1/E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2), x, 5, -((3*x*Sqrt[c - a^2*c*x^2])/Sqrt[1 - a^2*x^2]) + (a*x^2*Sqrt[c - a^2*c*x^2])/(2*Sqrt[1 - a^2*x^2]) + (4*Sqrt[c - a^2*c*x^2]*Log[1 + a*x])/(a*Sqrt[1 - a^2*x^2])}


(* ::Subsubsection::Closed:: *)
(*p<0*)


{1/E^(3*ArcTanh[a*x])/(c - c*a^2*x^2)^(1/2), x, 5, -((2*Sqrt[1 - a^2*x^2])/(a*(1 + a*x)*Sqrt[c - a^2*c*x^2])) - (Sqrt[1 - a^2*x^2]*Log[1 + a*x])/(a*Sqrt[c - a^2*c*x^2])}
{1/E^(3*ArcTanh[a*x])/(c - c*a^2*x^2)^(3/2), x, 3, -(Sqrt[1 - a^2*x^2]/(2*a*c*(1 + a*x)^2*Sqrt[c - a^2*c*x^2]))}
{1/E^(3*ArcTanh[a*x])/(c - c*a^2*x^2)^(5/2), x, 6, -(Sqrt[1 - a^2*x^2]/(6*a*c^2*(1 + a*x)^3*Sqrt[c - a^2*c*x^2])) - Sqrt[1 - a^2*x^2]/(8*a*c^2*(1 + a*x)^2*Sqrt[c - a^2*c*x^2]) - Sqrt[1 - a^2*x^2]/(8*a*c^2*(1 + a*x)*Sqrt[c - a^2*c*x^2]) + (Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(8*a*c^2*Sqrt[c - a^2*c*x^2])}
{1/E^(3*ArcTanh[a*x])/(c - c*a^2*x^2)^(7/2), x, 6, Sqrt[1 - a^2*x^2]/(32*a*c^3*(1 - a*x)*Sqrt[c - a^2*c*x^2]) - Sqrt[1 - a^2*x^2]/(16*a*c^3*(1 + a*x)^4*Sqrt[c - a^2*c*x^2]) - Sqrt[1 - a^2*x^2]/(12*a*c^3*(1 + a*x)^3*Sqrt[c - a^2*c*x^2]) - (3*Sqrt[1 - a^2*x^2])/(32*a*c^3*(1 + a*x)^2*Sqrt[c - a^2*c*x^2]) - Sqrt[1 - a^2*x^2]/(8*a*c^3*(1 + a*x)*Sqrt[c - a^2*c*x^2]) + (5*Sqrt[1 - a^2*x^2]*ArcTanh[a*x])/(32*a*c^3*Sqrt[c - a^2*c*x^2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(-3 ArcTanh[a x]) (c-c a^2 x^2)^p with p symbolic*)


{1/E^(3*ArcTanh[a*x])*(c - c*a^2*x^2)^p, x, 6, -(((1 - a^2*x^2)^(5/2)*(c - a^2*c*x^2)^p)/(a*(1 - 2*p)*(1 + a*x)^3)) - (2*(1 + p)*(1 - a^2*x^2)^(5/2)*(c - a^2*c*x^2)^p)/(a*(1 - 4*p^2)*(1 + a*x)^2) - (2*(1 + p)*(1 - a^2*x^2)^(5/2)*(c - a^2*c*x^2)^p)/(a*(1 - 4*p^2)*(1 + a*x)) - (4*(1 + p)*(2 + p)*x*(c - a^2*c*x^2)^p*Hypergeometric2F1[1/2, -(3/2) - p, 3/2, a^2*x^2])/((1 - a^2*x^2)^p*(1 - 4*p^2))}


(* ::Section::Closed:: *)
(*Integrands of the form x^m E^(n ArcTanh[a x]) (c-c a^2 x^2)^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(n ArcTanh[a x]) (c-c a^2 x^2)^p*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{E^(n*ArcTanh[a*x])*(c - c*a^2*x^2), x, 4, (c*(2 + n)*(1 - a*x)^(1 - n/2)*(1 + a*x)^((2 + n)/2))/(6*a) - (c*(1 - a*x)^(2 - n/2)*(1 + a*x)^((2 + n)/2))/(3*a) + (c*(2 - n)*(1 + a*x)^((2 + n)/2)*Hypergeometric2F1[n/2, (2 + n)/2, (4 + n)/2, (1/2)*(1 + a*x)])/(2^(n/2)*(3*a))}


{E^(n*ArcTanh[a*x])*(c - c*a^2*x^2)^2, x, 6, (c^2*(4 - n)*(2 + n)*(4 + n)*(1 - a*x)^(1 - n/2)*(1 + a*x)^((2 + n)/2))/(120*a) + (c^2*(2 + n)*(4 + n)*(1 - a*x)^(2 - n/2)*(1 + a*x)^((2 + n)/2))/(60*a) - (c^2*(4 + n)*(1 - a*x)^(3 - n/2)*(1 + a*x)^((2 + n)/2))/(20*a) - (c^2*(1 - a*x)^(3 - n/2)*(1 + a*x)^((4 + n)/2))/(5*a) + (2^(-2 - n/2)*c^2*(2 - n)*(4 - n)*(4 + n)*(1 + a*x)^((2 + n)/2)*Hypergeometric2F1[n/2, (2 + n)/2, (4 + n)/2, (1/2)*(1 + a*x)])/(15*a)}


{E^(n*ArcTanh[a*x])*(c - c*a^2*x^2)^3, x, 8, (c^3*(4 - n)*(6 - n)*(2 + n)*(4 + n)*(6 + n)*(1 - a*x)^(1 - n/2)*(1 + a*x)^((2 + n)/2))/(5040*a) + (c^3*(6 - n)*(2 + n)*(4 + n)*(6 + n)*(1 - a*x)^(2 - n/2)*(1 + a*x)^((2 + n)/2))/(2520*a) + (c^3*(2 + n)*(4 + n)*(6 + n)*(1 - a*x)^(3 - n/2)*(1 + a*x)^((2 + n)/2))/(840*a) - (c^3*(4 + n)*(6 + n)*(1 - a*x)^(4 - n/2)*(1 + a*x)^((2 + n)/2))/(210*a) - (c^3*(6 + n)*(1 - a*x)^(4 - n/2)*(1 + a*x)^((4 + n)/2))/(42*a) - (c^3*(1 - a*x)^(4 - n/2)*(1 + a*x)^((6 + n)/2))/(7*a) + (2^(-3 - n/2)*c^3*(2 - n)*(4 - n)*(6 - n)*(4 + n)*(6 + n)*(1 + a*x)^((2 + n)/2)*Hypergeometric2F1[n/2, (2 + n)/2, (4 + n)/2, (1/2)*(1 + a*x)])/(315*a)}


(* ::Subsubsection::Closed:: *)
(*p<0*)


{E^(n*ArcTanh[a*x])/(c - c*a^2*x^2)*x^m, x, 2, (x^(1 + m)*AppellF1[1 + m, (2 + n)/2, 1 - n/2, 2 + m, a*x, (-a)*x])/(c*(1 + m))}

{E^(n*ArcTanh[a*x])/(c - c*a^2*x^2)*x^4, x, 2, (x^5*AppellF1[5, (2 + n)/2, 1 - n/2, 6, a*x, (-a)*x])/(5*c)}
{E^(n*ArcTanh[a*x])/(c - c*a^2*x^2)*x^3, x, 2, (x^4*AppellF1[4, (2 + n)/2, 1 - n/2, 5, a*x, (-a)*x])/(4*c)}
{E^(n*ArcTanh[a*x])/(c - c*a^2*x^2)*x^2, x, 3, E^(n*ArcTanh[a*x])/(a^3*c*n) - (2^(1 - n/2)*(1 + a*x)^((2 + n)/2)*Hypergeometric2F1[n/2, (2 + n)/2, (4 + n)/2, (1/2)*(1 + a*x)])/(a^3*c*(2 + n))}
{E^(n*ArcTanh[a*x])/(c - c*a^2*x^2)*x^1, x, 3, (E^(n*ArcTanh[a*x])*x)/(a*c*n) - (2^(1 - n/2)*(1 + a*x)^((2 + n)/2)*Hypergeometric2F1[n/2, (2 + n)/2, (4 + n)/2, (1/2)*(1 + a*x)])/(a^2*c*n*(2 + n))}
{E^(n*ArcTanh[a*x])/(c - c*a^2*x^2)*x^0, x, 1, E^(n*ArcTanh[a*x])/(a*c*n)}
{E^(n*ArcTanh[a*x])/(c - c*a^2*x^2)/x^1, x, 2, (2^(n/2)*Defer[AppellF1][-(n/2), 1, 1 - n/2, 1 - n/2, 1 - a*x, (1/2)*(1 - a*x)])/((1 - a*x)^(n/2)*(c*n))}
{E^(n*ArcTanh[a*x])/(c - c*a^2*x^2)/x^2, x, 2, (2^(n/2)*a*Defer[AppellF1][-(n/2), 2, 1 - n/2, 1 - n/2, 1 - a*x, (1/2)*(1 - a*x)])/((1 - a*x)^(n/2)*(c*n))}


{E^(n*ArcTanh[a*x])/(c - c*a^2*x^2)^2*x^m, x, 2, (x^(1 + m)*AppellF1[1 + m, (4 + n)/2, 2 - n/2, 2 + m, a*x, (-a)*x])/(c^2*(1 + m))}

{E^(n*ArcTanh[a*x])/(c - c*a^2*x^2)^2*x^4, x, 2, (x^5*AppellF1[5, (4 + n)/2, 2 - n/2, 6, a*x, (-a)*x])/(5*c^2)}
{E^(n*ArcTanh[a*x])/(c - c*a^2*x^2)^2*x^3, x, 2, (x^4*AppellF1[4, (4 + n)/2, 2 - n/2, 5, a*x, (-a)*x])/(4*c^2)}
{E^(n*ArcTanh[a*x])/(c - c*a^2*x^2)^2*x^2, x, 2, -((E^(n*ArcTanh[a*x])*(2 - n^2))/(a^3*c^2*n*(4 - n^2))) - (E^(n*ArcTanh[a*x])*(n - 2*a*x))/(a^3*c^2*(4 - n^2)*(1 - a^2*x^2))}
{E^(n*ArcTanh[a*x])/(c - c*a^2*x^2)^2*x^1, x, 2, -(E^(n*ArcTanh[a*x])/(a^2*c^2*(4 - n^2))) + (E^(n*ArcTanh[a*x])*(2 - a*n*x))/(a^2*c^2*(4 - n^2)*(1 - a^2*x^2))}
{E^(n*ArcTanh[a*x])/(c - c*a^2*x^2)^2*x^0, x, 2, (2*E^(n*ArcTanh[a*x]))/(a*c^2*n*(4 - n^2)) - (E^(n*ArcTanh[a*x])*(n - 2*a*x))/(a*c^2*(4 - n^2)*(1 - a^2*x^2))}
{E^(n*ArcTanh[a*x])/(c - c*a^2*x^2)^2/x^1, x, 2, (2^(-1 + n/2)*(1 - a*x)^(-1 - n/2)*Defer[AppellF1][-1 - n/2, 1, 2 - n/2, -(n/2), 1 - a*x, (1/2)*(1 - a*x)])/(c^2*(2 + n))}
{E^(n*ArcTanh[a*x])/(c - c*a^2*x^2)^2/x^2, x, 2, (2^(-1 + n/2)*a*(1 - a*x)^(-1 - n/2)*Defer[AppellF1][-1 - n/2, 2, 2 - n/2, -(n/2), 1 - a*x, (1/2)*(1 - a*x)])/(c^2*(2 + n))}


{E^(n*ArcTanh[a*x])/(c - c*a^2*x^2)^3, x, 3, (24*E^(n*ArcTanh[a*x]))/(a*c^3*n*(64 - 20*n^2 + n^4)) - (E^(n*ArcTanh[a*x])*(n - 4*a*x))/(a*c^3*(16 - n^2)*(1 - a^2*x^2)^2) - (12*E^(n*ArcTanh[a*x])*(n - 2*a*x))/(a*c^3*(4 - n^2)*(16 - n^2)*(1 - a^2*x^2))}
{E^(n*ArcTanh[a*x])/(c - c*a^2*x^2)^4, x, 4, (720*E^(n*ArcTanh[a*x]))/(a*c^4*n*(36 - n^2)*(64 - 20*n^2 + n^4)) - (E^(n*ArcTanh[a*x])*(n - 6*a*x))/(a*c^4*(36 - n^2)*(1 - a^2*x^2)^3) - (30*E^(n*ArcTanh[a*x])*(n - 4*a*x))/(a*c^4*(16 - n^2)*(36 - n^2)*(1 - a^2*x^2)^2) - (360*E^(n*ArcTanh[a*x])*(n - 2*a*x))/(a*c^4*(4 - n^2)*(16 - n^2)*(36 - n^2)*(1 - a^2*x^2))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(n ArcTanh[a x]) (c-c a^2 x^2)^(p/2)*)


{E^(n*ArcTanh[a*x])*(c - c*a^2*x^2)^(7/2), x, 9, (c^3*(5 - n)*(7 - n)*(3 + n)*(5 + n)*(7 + n)*(1 - a*x)^((3 - n)/2)*(1 + a*x)^((3 + n)/2)*Sqrt[c - a^2*c*x^2])/(20160*a*Sqrt[1 - a^2*x^2]) + (c^3*(7 - n)*(3 + n)*(5 + n)*(7 + n)*(1 - a*x)^((5 - n)/2)*(1 + a*x)^((3 + n)/2)*Sqrt[c - a^2*c*x^2])/(6720*a*Sqrt[1 - a^2*x^2]) + (c^3*(3 + n)*(5 + n)*(7 + n)*(1 - a*x)^((7 - n)/2)*(1 + a*x)^((3 + n)/2)*Sqrt[c - a^2*c*x^2])/(1680*a*Sqrt[1 - a^2*x^2]) - (c^3*(5 + n)*(7 + n)*(1 - a*x)^((9 - n)/2)*(1 + a*x)^((3 + n)/2)*Sqrt[c - a^2*c*x^2])/(336*a*Sqrt[1 - a^2*x^2]) - (c^3*(7 + n)*(1 - a*x)^((9 - n)/2)*(1 + a*x)^((5 + n)/2)*Sqrt[c - a^2*c*x^2])/(56*a*Sqrt[1 - a^2*x^2]) - (c^3*(1 - a*x)^((9 - n)/2)*(1 + a*x)^((7 + n)/2)*Sqrt[c - a^2*c*x^2])/(8*a*Sqrt[1 - a^2*x^2]) + (2^(-(9/2) - n/2)*c^3*(3 - n)*(5 - n)*(7 - n)*(5 + n)*(7 + n)*(1 + a*x)^((3 + n)/2)*Sqrt[c - a^2*c*x^2]*Hypergeometric2F1[(1/2)*(-1 + n), (3 + n)/2, (5 + n)/2, (1/2)*(1 + a*x)])/(315*a*Sqrt[1 - a^2*x^2])}
{E^(n*ArcTanh[a*x])*(c - c*a^2*x^2)^(5/2), x, 7, (c^2*(5 - n)*(3 + n)*(5 + n)*(1 - a*x)^((3 - n)/2)*(1 + a*x)^((3 + n)/2)*Sqrt[c - a^2*c*x^2])/(360*a*Sqrt[1 - a^2*x^2]) + (c^2*(3 + n)*(5 + n)*(1 - a*x)^((5 - n)/2)*(1 + a*x)^((3 + n)/2)*Sqrt[c - a^2*c*x^2])/(120*a*Sqrt[1 - a^2*x^2]) - (c^2*(5 + n)*(1 - a*x)^((7 - n)/2)*(1 + a*x)^((3 + n)/2)*Sqrt[c - a^2*c*x^2])/(30*a*Sqrt[1 - a^2*x^2]) - (c^2*(1 - a*x)^((7 - n)/2)*(1 + a*x)^((5 + n)/2)*Sqrt[c - a^2*c*x^2])/(6*a*Sqrt[1 - a^2*x^2]) + (2^(-(3/2) - n/2)*c^2*(3 - n)*(5 - n)*(5 + n)*(1 + a*x)^((3 + n)/2)*Sqrt[c - a^2*c*x^2]*Hypergeometric2F1[(1/2)*(-1 + n), (3 + n)/2, (5 + n)/2, (1/2)*(1 + a*x)])/(45*a*Sqrt[1 - a^2*x^2])}
{E^(n*ArcTanh[a*x])*(c - c*a^2*x^2)^(3/2), x, 5, (c*(3 + n)*(1 - a*x)^((3 - n)/2)*(1 + a*x)^((3 + n)/2)*Sqrt[c - a^2*c*x^2])/(12*a*Sqrt[1 - a^2*x^2]) - (c*(1 - a*x)^((5 - n)/2)*(1 + a*x)^((3 + n)/2)*Sqrt[c - a^2*c*x^2])/(4*a*Sqrt[1 - a^2*x^2]) + (2^(-(1/2) - n/2)*c*(3 - n)*(1 + a*x)^((3 + n)/2)*Sqrt[c - a^2*c*x^2]*Hypergeometric2F1[(1/2)*(-1 + n), (3 + n)/2, (5 + n)/2, (1/2)*(1 + a*x)])/(3*a*Sqrt[1 - a^2*x^2])}
{E^(n*ArcTanh[a*x])*(c - c*a^2*x^2)^(1/2), x, 3, (2^(3/2 - n/2)*(1 + a*x)^((3 + n)/2)*Sqrt[c - a^2*c*x^2]*Hypergeometric2F1[(1/2)*(-1 + n), (3 + n)/2, (5 + n)/2, (1/2)*(1 + a*x)])/(a*(3 + n)*Sqrt[1 - a^2*x^2])}
{E^(n*ArcTanh[a*x])/(c - c*a^2*x^2)^(1/2), x, 5, -(((1 - a*x)^((1 - n)/2)*(1 + a*x)^((1 + n)/2)*Sqrt[1 - a^2*x^2])/(a*(1 - n)*Sqrt[c - a^2*c*x^2])) + ((1 - a*x)^((3 - n)/2)*(1 + a*x)^((1 + n)/2)*Sqrt[1 - a^2*x^2])/(a*(1 - n^2)*Sqrt[c - a^2*c*x^2]) + (2^(5/2 - n/2)*(1 + a*x)^((3 + n)/2)*Sqrt[1 - a^2*x^2]*Hypergeometric2F1[(1/2)*(-1 + n), (3 + n)/2, (5 + n)/2, (1/2)*(1 + a*x)])/(a*(1 - n)*(1 + n)*(3 + n)*Sqrt[c - a^2*c*x^2])}
{E^(n*ArcTanh[a*x])/(c - c*a^2*x^2)^(3/2), x, 1, -((E^(n*ArcTanh[a*x])*(n - a*x))/(a*c*(1 - n^2)*Sqrt[c - a^2*c*x^2]))}
{E^(n*ArcTanh[a*x])/(c - c*a^2*x^2)^(5/2), x, 2, -((E^(n*ArcTanh[a*x])*(n - 3*a*x))/(a*c*(9 - n^2)*(c - a^2*c*x^2)^(3/2))) - (6*E^(n*ArcTanh[a*x])*(n - a*x))/(a*c^2*(1 - n^2)*(9 - n^2)*Sqrt[c - a^2*c*x^2])}
{E^(n*ArcTanh[a*x])/(c - c*a^2*x^2)^(7/2), x, 3, -((E^(n*ArcTanh[a*x])*(n - 5*a*x))/(a*c*(25 - n^2)*(c - a^2*c*x^2)^(5/2))) - (20*E^(n*ArcTanh[a*x])*(n - 3*a*x))/(a*c^2*(9 - n^2)*(25 - n^2)*(c - a^2*c*x^2)^(3/2)) - (120*E^(n*ArcTanh[a*x])*(n - a*x))/(a*c^3*(1 - n^2)*(9 - n^2)*(25 - n^2)*Sqrt[c - a^2*c*x^2])}
{E^(n*ArcTanh[a*x])/(c - c*a^2*x^2)^(9/2), x, 4, -((E^(n*ArcTanh[a*x])*(n - 7*a*x))/(a*c*(49 - n^2)*(c - a^2*c*x^2)^(7/2))) - (42*E^(n*ArcTanh[a*x])*(n - 5*a*x))/(a*c^2*(25 - n^2)*(49 - n^2)*(c - a^2*c*x^2)^(5/2)) - (840*E^(n*ArcTanh[a*x])*(n - 3*a*x))/(a*c^3*(9 - n^2)*(25 - n^2)*(49 - n^2)*(c - a^2*c*x^2)^(3/2)) - (5040*E^(n*ArcTanh[a*x])*(n - a*x))/(a*c^4*(1 - n^2)*(9 - n^2)*(25 - n^2)*(49 - n^2)*Sqrt[c - a^2*c*x^2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(n ArcTanh[a x]) (c-c a^2 x^2)^p with p symbolic*)


{E^(n*ArcTanh[a*x])*(c - c*a^2*x^2)^p, x, 3, (2^(1 - n/2 + p)*(1 + a*x)^(1 + n/2 + p)*(c - a^2*c*x^2)^p*Hypergeometric2F1[(1/2)*(n - 2*p), 1 + n/2 + p, 2 + n/2 + p, (1/2)*(1 + a*x)])/((1 - a^2*x^2)^p*(a*(2 + n + 2*p)))}


{E^(2*(p + 1)*ArcTanh[a*x])/(1 - a^2*x^2)^p, x, 3, (1 - a*x)^(1 - 2*p)/(a*(1 - 2*p)) + 1/((1 - a*x)^(2*p)*(a*p))}
{E^(2*(p + 1)*ArcTanh[a*x])/(c - c*a^2*x^2)^p, x, 4, ((1 - a*x)^(1 - 2*p)*(1 - a^2*x^2)^p)/((c - a^2*c*x^2)^p*(a*(1 - 2*p))) + (1 - a^2*x^2)^p/((1 - a*x)^(2*p)*(c - a^2*c*x^2)^p*(a*p))}

{(c - c*a^2*x^2)^p/E^(2*p*ArcTanh[a*x]), x, 3, -(((1 - a*x)^(1 + 2*p)*(c - a^2*c*x^2)^p)/((1 - a^2*x^2)^p*(a*(1 + 2*p))))}
{(c - c*a^2*x^2)^p/E^(-2*p*ArcTanh[a*x]), x, 3, ((1 + a*x)^(1 + 2*p)*(c - a^2*c*x^2)^p)/((1 - a^2*x^2)^p*(a*(1 + 2*p)))}


(* ::Subtitle::Closed:: *)
(*Integration problems of the form u E^(n ArcTanh[a x]) (c-c/(a^2 x^2))^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form E^(n ArcTanh[a x]) (c-c/(a^2 x^2))^p*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{E^ArcTanh[a*x]*(c - c/(a^2*x^2))^p, x, 6, ((c - c/(a^2*x^2))^p*x*Hypergeometric2F1[(1/2)*(1 - 2*p), 1/2 - p, (1/2)*(3 - 2*p), a^2*x^2])/((1 - a^2*x^2)^p*(1 - 2*p)) + (a*(c - c/(a^2*x^2))^p*x^2*Hypergeometric2F1[1/2 - p, 1 - p, 2 - p, a^2*x^2])/((1 - a^2*x^2)^p*(2*(1 - p)))}

{E^ArcTanh[a*x]*(c - c/(a^2*x^2))^4, x, 13, (c^4*(16 - 35*a*x)*Sqrt[1 - a^2*x^2])/(16*a^2*x) - (35*c^4*(1 - a^2*x^2)^(3/2))/(16*a^3*x^2) - (c^4*(8 - 35*a*x)*(1 - a^2*x^2)^(3/2))/(24*a^4*x^3) + (35*c^4*(1 - a^2*x^2)^(5/2))/(24*a^5*x^4) + (c^4*(6 - 35*a*x)*(1 - a^2*x^2)^(5/2))/(30*a^6*x^5) - (7*c^4*(1 - a^2*x^2)^(7/2))/(6*a^7*x^6) - (c^4*(1 - 7*a*x)*(1 - a^2*x^2)^(7/2))/(7*a^8*x^7) + (c^4*ArcSin[a*x])/a + (35*c^4*ArcTanh[Sqrt[1 - a^2*x^2]])/(16*a)}
{E^ArcTanh[a*x]*(c - c/(a^2*x^2))^3, x, 11, (c^3*(8 - 15*a*x)*Sqrt[1 - a^2*x^2])/(8*a^2*x) - (15*c^3*(1 - a^2*x^2)^(3/2))/(8*a^3*x^2) - (c^3*(4 - 15*a*x)*(1 - a^2*x^2)^(3/2))/(12*a^4*x^3) + (5*c^3*(1 - a^2*x^2)^(5/2))/(4*a^5*x^4) + (c^3*(1 - 5*a*x)*(1 - a^2*x^2)^(5/2))/(5*a^6*x^5) + (c^3*ArcSin[a*x])/a + (15*c^3*ArcTanh[Sqrt[1 - a^2*x^2]])/(8*a)}
{E^ArcTanh[a*x]*(c - c/(a^2*x^2))^2, x, 9, (c^2*(2 - 3*a*x)*Sqrt[1 - a^2*x^2])/(2*a^2*x) - (3*c^2*(1 - a^2*x^2)^(3/2))/(2*a^3*x^2) - (c^2*(1 - 3*a*x)*(1 - a^2*x^2)^(3/2))/(3*a^4*x^3) + (c^2*ArcSin[a*x])/a + (3*c^2*ArcTanh[Sqrt[1 - a^2*x^2]])/(2*a)}
{E^ArcTanh[a*x]*(c - c/(a^2*x^2))^1, x, 7, (c*(1 - a*x)*Sqrt[1 - a^2*x^2])/(a^2*x) + (c*ArcSin[a*x])/a + (c*ArcTanh[Sqrt[1 - a^2*x^2]])/a}
{E^ArcTanh[a*x]/(c - c/(a^2*x^2))^1, x, 6, -(Sqrt[1 + a*x]/(a*c*Sqrt[1 - a*x])) - (Sqrt[1 - a*x]*Sqrt[1 + a*x])/(a*c) + ArcSin[a*x]/(a*c)}
{E^ArcTanh[a*x]/(c - c/(a^2*x^2))^2, x, 8, (4*a*x^2)/(3*c^2*(1 - a*x)^(3/2)*Sqrt[1 + a*x]) - (a^2*x^3)/(c^2*(1 - a*x)^(3/2)*Sqrt[1 + a*x]) - (8 + 3*a*x)/(3*a*c^2*Sqrt[1 - a*x]*Sqrt[1 + a*x]) + ArcSin[a*x]/(a*c^2), (a^3*x^4*(1 + a*x))/(3*c^2*(1 - a^2*x^2)^(3/2)) - (2*a^2*x^3*(1 + 2*a*x))/(3*c^2*Sqrt[1 - a^2*x^2]) - (4*Sqrt[1 - a^2*x^2])/(3*a*c^2) - (4*a*x^2*Sqrt[1 - a^2*x^2])/(3*c^2) - ((4 + 3*a*x)*Sqrt[1 - a^2*x^2])/(3*a*c^2) + ArcSin[a*x]/(a*c^2)}
{E^ArcTanh[a*x]/(c - c/(a^2*x^2))^3, x, 10, -((a^5*x^6*(1 + a*x))/(5*c^3*(1 - a^2*x^2)^(5/2))) + (2*a^4*x^5*(1 + 3*a*x))/(15*c^3*(1 - a^2*x^2)^(3/2)) - (2*a^3*x^4*(9 + 5*a*x))/(15*c^3*Sqrt[1 - a^2*x^2]) - (8*Sqrt[1 - a^2*x^2])/(5*a*c^3) - (8*a*x^2*Sqrt[1 - a^2*x^2])/(5*c^3) - (2*a^2*x^3*Sqrt[1 - a^2*x^2])/(3*c^3) - ((8 + 5*a*x)*Sqrt[1 - a^2*x^2])/(5*a*c^3) + ArcSin[a*x]/(a*c^3)}
{E^ArcTanh[a*x]/(c - c/(a^2*x^2))^4, x, 12, (a^7*x^8*(1 + a*x))/(7*c^4*(1 - a^2*x^2)^(7/2)) - (2*a^6*x^7*(1 + 4*a*x))/(35*c^4*(1 - a^2*x^2)^(5/2)) + (2*a^5*x^6*(12 + 7*a*x))/(105*c^4*(1 - a^2*x^2)^(3/2)) - (8*a^4*x^5*(7 + 18*a*x))/(105*c^4*Sqrt[1 - a^2*x^2]) - (64*Sqrt[1 - a^2*x^2])/(35*a*c^4) - (64*a*x^2*Sqrt[1 - a^2*x^2])/(35*c^4) - (2*a^2*x^3*Sqrt[1 - a^2*x^2])/(3*c^4) - (48*a^3*x^4*Sqrt[1 - a^2*x^2])/(35*c^4) - ((64 + 35*a*x)*Sqrt[1 - a^2*x^2])/(35*a*c^4) + ArcSin[a*x]/(a*c^4)}


{E^(2*ArcTanh[a*x])*(c - c/(a^2*x^2))^p, x, 3, (-c)*(1 - 1/(a^2*x^2))^(1 - p)*(c - c/(a^2*x^2))^(-1 + p)*x*Hypergeometric2F1[-(1/2), 1 - p, 1/2, 1/(a^2*x^2)] + (c*(1 - 1/(a^2*x^2))^(1 - p)*(c - c/(a^2*x^2))^(-1 + p)*Hypergeometric2F1[1/2, 1 - p, 3/2, 1/(a^2*x^2)])/(a^2*x) - (c*(c - c/(a^2*x^2))^(-1 + p)*(-((a^2 - 1/x^2)*x^2))^(1 - p)*Hypergeometric2F1[1 - p, 1 - p, 2 - p, a^2*x^2])/(a*(1 - p)), ((c - c/(a^2*x^2))^p*x*AppellF1[1 - 2*p, 1 - p, -1 - p, 2 - 2*p, a*x, (-a)*x])/((1 - a*x)^p*(1 + a*x)^p*(1 - 2*p))}

{E^(2*ArcTanh[a*x])*(c - c/(a^2*x^2))^5, x, 4, c^5/(9*a^10*x^9) + c^5/(4*a^9*x^8) - (3*c^5)/(7*a^8*x^7) - (4*c^5)/(3*a^7*x^6) + (2*c^5)/(5*a^6*x^5) + (3*c^5)/(a^5*x^4) + (2*c^5)/(3*a^4*x^3) - (4*c^5)/(a^3*x^2) - (3*c^5)/(a^2*x) - c^5*x - (2*c^5*Log[x])/a}
{E^(2*ArcTanh[a*x])*(c - c/(a^2*x^2))^4, x, 4, -c^4/(7*a^8*x^7) - c^4/(3*a^7*x^6) + (2*c^4)/(5*a^6*x^5) + (3*c^4)/(2*a^5*x^4) - (3*c^4)/(a^3*x^2) - (2*c^4)/(a^2*x) - c^4*x - (2*c^4*Log[x])/a}
{E^(2*ArcTanh[a*x])*(c - c/(a^2*x^2))^3, x, 4, c^3/(5*a^6*x^5) + c^3/(2*a^5*x^4) - c^3/(3*a^4*x^3) - (2*c^3)/(a^3*x^2) - c^3/(a^2*x) - c^3*x - (2*c^3*Log[x])/a}
{E^(2*ArcTanh[a*x])*(c - c/(a^2*x^2))^2, x, 4, -c^2/(3*a^4*x^3) - c^2/(a^3*x^2) - c^2*x - (2*c^2*Log[x])/a}
{E^(2*ArcTanh[a*x])*(c - c/(a^2*x^2)), x, 4, c/(a^2*x) - c*x - (2*c*Log[x])/a}
{E^(2*ArcTanh[a*x])/(c - c/(a^2*x^2)), x, 4, -(x/c) - 1/(a*c*(1 - a*x)) - (2*Log[1 - a*x])/(a*c)}
{E^(2*ArcTanh[a*x])/(c - c/(a^2*x^2))^2, x, 4, -(x/c^2) + 1/(4*a*c^2*(1 - a*x)^2) - 7/(4*a*c^2*(1 - a*x)) - (17*Log[1 - a*x])/(8*a*c^2) + Log[1 + a*x]/(8*a*c^2)}
{E^(2*ArcTanh[a*x])/(c - c/(a^2*x^2))^3, x, 4, -(x/c^3) - 1/(12*a*c^3*(1 - a*x)^3) + 5/(8*a*c^3*(1 - a*x)^2) - 39/(16*a*c^3*(1 - a*x)) + 1/(16*a*c^3*(1 + a*x)) - (9*Log[1 - a*x])/(4*a*c^3) + Log[1 + a*x]/(4*a*c^3)}
{E^(2*ArcTanh[a*x])/(c - c/(a^2*x^2))^4, x, 4, -(x/c^4) + 1/(32*a*c^4*(1 - a*x)^4) - 13/(48*a*c^4*(1 - a*x)^3) + 35/(32*a*c^4*(1 - a*x)^2) - 99/(32*a*c^4*(1 - a*x)) - 1/(64*a*c^4*(1 + a*x)^2) + 11/(64*a*c^4*(1 + a*x)) - (303*Log[1 - a*x])/(128*a*c^4) + (47*Log[1 + a*x])/(128*a*c^4)}


{E^(3*ArcTanh[a*x])*(c - c/(a^2*x^2))^p, x, 9, ((c - c/(a^2*x^2))^p*x)/((1 - 2*p)*Sqrt[1 - a^2*x^2]) - (a*(c - c/(a^2*x^2))^p*x^2)/Sqrt[1 - a^2*x^2] + (3*a^2*(c - c/(a^2*x^2))^p*x^3*Hypergeometric2F1[(1/2)*(3 - 2*p), 3/2 - p, (1/2)*(5 - 2*p), a^2*x^2])/((1 - a^2*x^2)^p*(3 - 2*p)) + (a*(c - c/(a^2*x^2))^p*x^2*Hypergeometric2F1[1 - p, 3/2 - p, 2 - p, a^2*x^2])/(1 - a^2*x^2)^p + (3*a*(c - c/(a^2*x^2))^p*x^2*Hypergeometric2F1[1 - p, 3/2 - p, 2 - p, a^2*x^2])/((1 - a^2*x^2)^p*(2*(1 - p)))}

{E^(3*ArcTanh[a*x])*(c - c/(a^2*x^2))^4, x, 13, (63*c^4*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(16*a) - (13*c^4*Sqrt[1 - a*x]*(1 + a*x)^(3/2))/(8*a^2*x) - (63*c^4*Sqrt[1 - a*x]*(1 + a*x)^(5/2))/(80*a^3*x^2) - (31*c^4*Sqrt[1 - a*x]*(1 + a*x)^(7/2))/(70*a^4*x^3) - (15*c^4*Sqrt[1 - a*x]*(1 + a*x)^(9/2))/(56*a^5*x^4) + (9*c^4*Sqrt[1 - a*x]*(1 + a*x)^(11/2))/(35*a^6*x^5) - (c^4*(1 - a*x)^(3/2)*(1 + a*x)^(11/2))/(14*a^7*x^6) - (c^4*(1 - a*x)^(5/2)*(1 + a*x)^(11/2))/(7*a^8*x^7) - (3*c^4*ArcSin[a*x])/a - (15*c^4*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(8*a)}
{E^(3*ArcTanh[a*x])*(c - c/(a^2*x^2))^3, x, 11, (27*c^3*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(8*a) - (5*c^3*Sqrt[1 - a*x]*(1 + a*x)^(3/2))/(4*a^2*x) - (27*c^3*Sqrt[1 - a*x]*(1 + a*x)^(5/2))/(40*a^3*x^2) - (2*c^3*Sqrt[1 - a*x]*(1 + a*x)^(7/2))/(5*a^4*x^3) + (3*c^3*Sqrt[1 - a*x]*(1 + a*x)^(9/2))/(20*a^5*x^4) + (c^3*(1 - a*x)^(3/2)*(1 + a*x)^(9/2))/(5*a^6*x^5) - (3*c^3*ArcSin[a*x])/a - (3*c^3*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(4*a)}
{E^(3*ArcTanh[a*x])*(c - c/(a^2*x^2))^2, x, 9, (5*c^2*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(2*a) - (2*c^2*Sqrt[1 - a*x]*(1 + a*x)^(3/2))/(3*a^2*x) - (c^2*Sqrt[1 - a*x]*(1 + a*x)^(5/2))/(2*a^3*x^2) - (c^2*Sqrt[1 - a*x]*(1 + a*x)^(7/2))/(3*a^4*x^3) - (3*c^2*ArcSin[a*x])/a + (c^2*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/a}
{E^(3*ArcTanh[a*x])*(c - c/(a^2*x^2)), x, 8, -((c*Sqrt[1 - a*x]*(1 + a*x)^(3/2))/a) + (c*Sqrt[1 - a*x]*(1 + a*x)^(5/2))/(a^2*x) - (3*c*ArcSin[a*x])/a + (6*c*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/a}
{E^(3*ArcTanh[a*x])/(c - c/(a^2*x^2)), x, 7, (3*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(a*c) - (1 + a*x)^(3/2)/(3*a*c*(1 - a*x)^(3/2)) + (2*(1 + a*x)^(3/2))/(a*c*Sqrt[1 - a*x]) - (3*ArcSin[a*x])/(a*c)}
{E^(3*ArcTanh[a*x])/(c - c/(a^2*x^2))^2, x, 8, -((a^2*x^3*Sqrt[1 + a*x])/(c^2*(1 - a*x)^(5/2))) + (6*Sqrt[1 + a*x])/(a*c^2*Sqrt[1 - a*x]) + (3*(1 + a*x)^(3/2))/(5*a*c^2*(1 - a*x)^(5/2)) - (9*(1 + a*x)^(3/2))/(5*a*c^2*(1 - a*x)^(3/2)) - (3*ArcSin[a*x])/(a*c^2)}
{E^(3*ArcTanh[a*x])/(c - c/(a^2*x^2))^3, x, 9, (-8*a^3*x^4)/(7*c^3*(1 - a*x)^(7/2)*Sqrt[1 + a*x]) + (a^4*x^5)/(c^3*(1 - a*x)^(7/2)*Sqrt[1 + a*x]) + (53*a^2*x^3)/(35*c^3*(1 - a*x)^(5/2)*Sqrt[1 + a*x]) - (88*a*x^2)/(35*c^3*(1 - a*x)^(3/2)*Sqrt[1 + a*x]) + (176 + 105*a*x)/(35*a*c^3*Sqrt[1 - a*x]*Sqrt[1 + a*x]) - (3*ArcSin[a*x])/(a*c^3)}
{E^(3*ArcTanh[a*x])/(c - c/(a^2*x^2))^4, x, 11, (10*a^5*x^6)/(9*c^4*(1 - a*x)^(9/2)*(1 + a*x)^(3/2)) - (a^6*x^7)/(c^4*(1 - a*x)^(9/2)*(1 + a*x)^(3/2)) - (29*a^4*x^5)/(21*c^4*(1 - a*x)^(7/2)*(1 + a*x)^(3/2)) + (208*a^3*x^4)/(105*c^4*(1 - a*x)^(5/2)*(1 + a*x)^(3/2)) - (1147*a^2*x^3)/(315*c^4*(1 - a*x)^(3/2)*(1 + a*x)^(3/2)) + (1462*a*x^2)/(105*c^4*Sqrt[1 - a*x]*(1 + a*x)^(3/2)) + (4588*Sqrt[1 - a*x])/(315*a*c^4*Sqrt[1 + a*x]) - (Sqrt[1 - a*x]*(2924 + 315*a*x))/(315*a*c^4*(1 + a*x)^(3/2)) - (3*ArcSin[a*x])/(a*c^4)}


{E^(4*ArcTanh[a*x])*(c - c/(a^2*x^2))^p, x, 3, -((2*c*(c - c/(a^2*x^2))^(-1 + p))/(a*(1 - p))) - (c*(c - c/(a^2*x^2))^(-1 + p))/(a^2*(1 - 2*p)*x) + c^2*(1 - 1/(a^2*x^2))^(2 - p)*(c - c/(a^2*x^2))^(-2 + p)*x*Hypergeometric2F1[-(1/2), 2 - p, 1/2, 1/(a^2*x^2)] - (6*c^2*(1 - 1/(a^2*x^2))^(2 - p)*(c - c/(a^2*x^2))^(-2 + p)*Hypergeometric2F1[1/2, 2 - p, 3/2, 1/(a^2*x^2)])/(a^2*x) + (c^2*(1 - 1/(a^2*x^2))^(2 - p)*(c - c/(a^2*x^2))^(-2 + p)*Hypergeometric2F1[1/2, 2 - p, 3/2, 1/(a^2*x^2)])/(a^2*(1 - 2*p)*x) + (2*c^2*(c - c/(a^2*x^2))^(-2 + p)*(-((a^2 - 1/x^2)*x^2))^(2 - p)*Hypergeometric2F1[2 - p, 2 - p, 3 - p, a^2*x^2])/(a*(2 - p)), ((c - c/(a^2*x^2))^p*x*AppellF1[1 - 2*p, 2 - p, -2 - p, 2 - 2*p, a*x, (-a)*x])/((1 - a*x)^p*(1 + a*x)^p*(1 - 2*p))}

{E^(4*ArcTanh[a*x])*(c - c/(a^2*x^2))^5, x, 4, c^5/(9*a^10*x^9) + c^5/(2*a^9*x^8) + (3*c^5)/(7*a^8*x^7) - (4*c^5)/(3*a^7*x^6) - (14*c^5)/(5*a^6*x^5) + (14*c^5)/(3*a^4*x^3) + (4*c^5)/(a^3*x^2) - (3*c^5)/(a^2*x) + c^5*x + (4*c^5*Log[x])/a}
{E^(4*ArcTanh[a*x])*(c - c/(a^2*x^2))^4, x, 4, -c^4/(7*a^8*x^7) - (2*c^4)/(3*a^7*x^6) - (4*c^4)/(5*a^6*x^5) + c^4/(a^5*x^4) + (10*c^4)/(3*a^4*x^3) + (2*c^4)/(a^3*x^2) - (4*c^4)/(a^2*x) + c^4*x + (4*c^4*Log[x])/a}
{E^(4*ArcTanh[a*x])*(c - c/(a^2*x^2))^3, x, 4, c^3/(5*a^6*x^5) + c^3/(a^5*x^4) + (5*c^3)/(3*a^4*x^3) - (5*c^3)/(a^2*x) + c^3*x + (4*c^3*Log[x])/a}
{E^(4*ArcTanh[a*x])*(c - c/(a^2*x^2))^2, x, 4, -c^2/(3*a^4*x^3) - (2*c^2)/(a^3*x^2) - (6*c^2)/(a^2*x) + c^2*x + (4*c^2*Log[x])/a}
{E^(4*ArcTanh[a*x])*(c - c/(a^2*x^2)), x, 4, c/(a^2*x) + c*x - (4*c*Log[x])/a + (8*c*Log[1 - a*x])/a}
{E^(4*ArcTanh[a*x])/(c - c/(a^2*x^2)), x, 4, x/c - 1/(a*c*(1 - a*x)^2) + 5/(a*c*(1 - a*x)) + (4*Log[1 - a*x])/(a*c)}
{E^(4*ArcTanh[a*x])/(c - c/(a^2*x^2))^2, x, 4, x/c^2 + 1/(3*a*c^2*(1 - a*x)^3) - 2/(a*c^2*(1 - a*x)^2) + 6/(a*c^2*(1 - a*x)) + (4*Log[1 - a*x])/(a*c^2)}
{E^(4*ArcTanh[a*x])/(c - c/(a^2*x^2))^3, x, 4, x/c^3 - 1/(8*a*c^3*(1 - a*x)^4) + 11/(12*a*c^3*(1 - a*x)^3) - 49/(16*a*c^3*(1 - a*x)^2) + 111/(16*a*c^3*(1 - a*x)) + (129*Log[1 - a*x])/(32*a*c^3) - Log[1 + a*x]/(32*a*c^3)}
{E^(4*ArcTanh[a*x])/(c - c/(a^2*x^2))^4, x, 4, x/c^4 + 1/(20*a*c^4*(1 - a*x)^5) - 7/(16*a*c^4*(1 - a*x)^4) + 83/(48*a*c^4*(1 - a*x)^3) - 67/(16*a*c^4*(1 - a*x)^2) + 501/(64*a*c^4*(1 - a*x)) - 1/(64*a*c^4*(1 + a*x)) + (261*Log[1 - a*x])/(64*a*c^4) - (5*Log[1 + a*x])/(64*a*c^4)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(c - c/(a^2*x^2))^p/E^ArcTanh[a*x], x, 4, ((c - c/(a^2*x^2))^p*x*AppellF1[1 - 2*p, -(1/2) - p, 1/2 - p, 2 - 2*p, a*x, (-a)*x])/((1 - a^2*x^2)^p*(1 - 2*p))}

{(c - c/(a^2*x^2))^4/E^ArcTanh[a*x], x, 13, (19*c^4*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(16*a) - (9*c^4*Sqrt[1 - a*x]*(1 + a*x)^(3/2))/(8*a^2*x) - (19*c^4*Sqrt[1 - a*x]*(1 + a*x)^(5/2))/(80*a^3*x^2) + (13*c^4*Sqrt[1 - a*x]*(1 + a*x)^(7/2))/(20*a^4*x^3) - (59*c^4*(1 - a*x)^(3/2)*(1 + a*x)^(7/2))/(120*a^5*x^4) + (c^4*(1 - a*x)^(5/2)*(1 + a*x)^(7/2))/(5*a^6*x^5) + (c^4*(1 - a*x)^(7/2)*(1 + a*x)^(7/2))/(42*a^7*x^6) - (c^4*(1 - a*x)^(9/2)*(1 + a*x)^(7/2))/(7*a^8*x^7) + (c^4*ArcSin[a*x])/a - (35*c^4*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(8*a)}
{(c - c/(a^2*x^2))^3/E^ArcTanh[a*x], x, 11, (7*c^3*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(8*a) - (11*c^3*Sqrt[1 - a*x]*(1 + a*x)^(3/2))/(12*a^2*x) + (23*c^3*Sqrt[1 - a*x]*(1 + a*x)^(5/2))/(24*a^3*x^2) - (c^3*(1 - a*x)^(3/2)*(1 + a*x)^(5/2))/(3*a^4*x^3) - (c^3*(1 - a*x)^(5/2)*(1 + a*x)^(5/2))/(20*a^5*x^4) + (c^3*(1 - a*x)^(7/2)*(1 + a*x)^(5/2))/(5*a^6*x^5) + (c^3*ArcSin[a*x])/a - (15*c^3*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(4*a)}
{(c - c/(a^2*x^2))^2/E^ArcTanh[a*x], x, 9, (c^2*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(2*a) + (c^2*Sqrt[1 - a*x]*(1 + a*x)^(3/2))/(a^2*x) + (c^2*(1 - a*x)^(3/2)*(1 + a*x)^(3/2))/(6*a^3*x^2) - (c^2*(1 - a*x)^(5/2)*(1 + a*x)^(3/2))/(3*a^4*x^3) + (c^2*ArcSin[a*x])/a - (3*c^2*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/a}
{(c - c/(a^2*x^2))/E^ArcTanh[a*x], x, 8, (2*c*Sqrt[1 - a*x]*Sqrt[1 + a*x])/a + (c*(1 - a*x)^(3/2)*Sqrt[1 + a*x])/(a^2*x) + (c*ArcSin[a*x])/a - (2*c*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/a}
{1/(E^ArcTanh[a*x]*(c - c/(a^2*x^2))), x, 6, Sqrt[1 - a*x]/(a*c*Sqrt[1 + a*x]) + (Sqrt[1 - a*x]*Sqrt[1 + a*x])/(a*c) + ArcSin[a*x]/(a*c)}
{1/(E^ArcTanh[a*x]*(c - c/(a^2*x^2))^2), x, 7, (2*a*x^2)/(c^2*Sqrt[1 - a*x]*(1 + a*x)^(3/2)) - (a^2*x^3)/(c^2*Sqrt[1 - a*x]*(1 + a*x)^(3/2)) - (Sqrt[1 - a*x]*(4 - a*x))/(3*a*c^2*(1 + a*x)^(3/2)) + (4*Sqrt[1 - a*x])/(a*c^2*Sqrt[1 + a*x]) + ArcSin[a*x]/(a*c^2)}
{1/(E^ArcTanh[a*x]*(c - c/(a^2*x^2))^3), x, 9, (-4*a^3*x^4)/(3*c^3*(1 - a*x)^(3/2)*(1 + a*x)^(5/2)) + (a^4*x^5)/(c^3*(1 - a*x)^(3/2)*(1 + a*x)^(5/2)) + (13*a^2*x^3)/(3*c^3*Sqrt[1 - a*x]*(1 + a*x)^(5/2)) + (14*a*x^2*Sqrt[1 - a*x])/(5*c^3*(1 + a*x)^(5/2)) - ((28 - 5*a*x)*Sqrt[1 - a*x])/(15*a*c^3*(1 + a*x)^(3/2)) + (76*Sqrt[1 - a*x])/(15*a*c^3*Sqrt[1 + a*x]) + ArcSin[a*x]/(a*c^3)}
{1/(E^ArcTanh[a*x]*(c - c/(a^2*x^2))^4), x, 11, (6*a^5*x^6)/(5*c^4*(1 - a*x)^(5/2)*(1 + a*x)^(7/2)) - (a^6*x^7)/(c^4*(1 - a*x)^(5/2)*(1 + a*x)^(7/2)) - (31*a^4*x^5)/(15*c^4*(1 - a*x)^(3/2)*(1 + a*x)^(7/2)) + (28*a^3*x^4)/(3*c^4*Sqrt[1 - a*x]*(1 + a*x)^(7/2)) + (115*a^2*x^3*Sqrt[1 - a*x])/(21*c^4*(1 + a*x)^(7/2)) + (122*a*x^2*Sqrt[1 - a*x])/(35*c^4*(1 + a*x)^(5/2)) - ((244 - 35*a*x)*Sqrt[1 - a*x])/(105*a*c^4*(1 + a*x)^(3/2)) + (628*Sqrt[1 - a*x])/(105*a*c^4*Sqrt[1 + a*x]) + ArcSin[a*x]/(a*c^4)}


{(c - c/(a^2*x^2))^p/E^(2*ArcTanh[a*x]), x, 3, ((c - c/(a^2*x^2))^p*x*AppellF1[1 - 2*p, -1 - p, 1 - p, 2 - 2*p, a*x, (-a)*x])/((1 - a*x)^p*(1 + a*x)^p*(1 - 2*p))}

{(c - c/(a^2*x^2))^4/E^(2*ArcTanh[a*x]), x, 4, -c^4/(7*a^8*x^7) + c^4/(3*a^7*x^6) + (2*c^4)/(5*a^6*x^5) - (3*c^4)/(2*a^5*x^4) + (3*c^4)/(a^3*x^2) - (2*c^4)/(a^2*x) - c^4*x + (2*c^4*Log[x])/a}
{(c - c/(a^2*x^2))^3/E^(2*ArcTanh[a*x]), x, 4, c^3/(5*a^6*x^5) - c^3/(2*a^5*x^4) - c^3/(3*a^4*x^3) + (2*c^3)/(a^3*x^2) - c^3/(a^2*x) - c^3*x + (2*c^3*Log[x])/a}
{(c - c/(a^2*x^2))^2/E^(2*ArcTanh[a*x]), x, 4, -c^2/(3*a^4*x^3) + c^2/(a^3*x^2) - c^2*x + (2*c^2*Log[x])/a}
{(c - c/(a^2*x^2))/E^(2*ArcTanh[a*x]), x, 4, c/(a^2*x) - c*x + (2*c*Log[x])/a}
{1/(E^(2*ArcTanh[a*x])*(c - c/(a^2*x^2))), x, 4, -(x/c) + 1/(a*c*(1 + a*x)) + (2*Log[1 + a*x])/(a*c)}
{1/(E^(2*ArcTanh[a*x])*(c - c/(a^2*x^2))^2), x, 4, -(x/c^2) - 1/(4*a*c^2*(1 + a*x)^2) + 7/(4*a*c^2*(1 + a*x)) - Log[1 - a*x]/(8*a*c^2) + (17*Log[1 + a*x])/(8*a*c^2)}
{1/(E^(2*ArcTanh[a*x])*(c - c/(a^2*x^2))^3), x, 4, -(x/c^3) - 1/(16*a*c^3*(1 - a*x)) + 1/(12*a*c^3*(1 + a*x)^3) - 5/(8*a*c^3*(1 + a*x)^2) + 39/(16*a*c^3*(1 + a*x)) - Log[1 - a*x]/(4*a*c^3) + (9*Log[1 + a*x])/(4*a*c^3)}
{1/(E^(2*ArcTanh[a*x])*(c - c/(a^2*x^2))^4), x, 4, -(x/c^4) + 1/(64*a*c^4*(1 - a*x)^2) - 11/(64*a*c^4*(1 - a*x)) - 1/(32*a*c^4*(1 + a*x)^4) + 13/(48*a*c^4*(1 + a*x)^3) - 35/(32*a*c^4*(1 + a*x)^2) + 99/(32*a*c^4*(1 + a*x)) - (47*Log[1 - a*x])/(128*a*c^4) + (303*Log[1 + a*x])/(128*a*c^4)}


{(c - c/(a^2*x^2))^p/E^(3*ArcTanh[a*x]), x, 4, ((c - c/(a^2*x^2))^p*x*AppellF1[1 - 2*p, -(3/2) - p, 3/2 - p, 2 - 2*p, a*x, (-a)*x])/((1 - a^2*x^2)^p*(1 - 2*p))}

{(c - c/(a^2*x^2))^4/E^(3*ArcTanh[a*x]), x, 13, (33*c^4*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(16*a) - (3*c^4*Sqrt[1 - a*x]*(1 + a*x)^(3/2))/(8*a^2*x) - (21*c^4*Sqrt[1 - a*x]*(1 + a*x)^(5/2))/(16*a^3*x^2) + (c^4*(1 - a*x)^(3/2)*(1 + a*x)^(5/2))/(a^4*x^3) - (19*c^4*(1 - a*x)^(5/2)*(1 + a*x)^(5/2))/(40*a^5*x^4) + (4*c^4*(1 - a*x)^(7/2)*(1 + a*x)^(5/2))/(35*a^6*x^5) + (c^4*(1 - a*x)^(9/2)*(1 + a*x)^(5/2))/(14*a^7*x^6) - (c^4*(1 - a*x)^(11/2)*(1 + a*x)^(5/2))/(7*a^8*x^7) - (3*c^4*ArcSin[a*x])/a + (15*c^4*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(8*a)}
{(c - c/(a^2*x^2))^3/E^(3*ArcTanh[a*x]), x, 11, (21*c^3*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(8*a) - (3*c^3*Sqrt[1 - a*x]*(1 + a*x)^(3/2))/(a^2*x) + (7*c^3*(1 - a*x)^(3/2)*(1 + a*x)^(3/2))/(8*a^3*x^2) - (c^3*(1 - a*x)^(5/2)*(1 + a*x)^(3/2))/(10*a^4*x^3) - (3*c^3*(1 - a*x)^(7/2)*(1 + a*x)^(3/2))/(20*a^5*x^4) + (c^3*(1 - a*x)^(9/2)*(1 + a*x)^(3/2))/(5*a^6*x^5) - (3*c^3*ArcSin[a*x])/a + (3*c^3*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(4*a)}
{(c - c/(a^2*x^2))^2/E^(3*ArcTanh[a*x]), x, 9, (-5*c^2*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(2*a) - (2*c^2*(1 - a*x)^(3/2)*Sqrt[1 + a*x])/(3*a^2*x) + (c^2*(1 - a*x)^(5/2)*Sqrt[1 + a*x])/(2*a^3*x^2) - (c^2*(1 - a*x)^(7/2)*Sqrt[1 + a*x])/(3*a^4*x^3) - (3*c^2*ArcSin[a*x])/a - (c^2*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/a}
{(c - c/(a^2*x^2))/E^(3*ArcTanh[a*x]), x, 8, (c*(1 - a*x)^(3/2)*Sqrt[1 + a*x])/a + (c*(1 - a*x)^(5/2)*Sqrt[1 + a*x])/(a^2*x) - (3*c*ArcSin[a*x])/a - (6*c*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/a}
{1/(E^(3*ArcTanh[a*x])*(c - c/(a^2*x^2))), x, 7, (1 - a*x)^(3/2)/(3*a*c*(1 + a*x)^(3/2)) - (2*(1 - a*x)^(3/2))/(a*c*Sqrt[1 + a*x]) - (3*Sqrt[1 - a*x]*Sqrt[1 + a*x])/(a*c) - (3*ArcSin[a*x])/(a*c)}
{1/(E^(3*ArcTanh[a*x])*(c - c/(a^2*x^2))^2), x, 8, -((a^2*x^3*Sqrt[1 - a*x])/(c^2*(1 + a*x)^(5/2))) - (3*(1 - a*x)^(3/2))/(5*a*c^2*(1 + a*x)^(5/2)) + (9*(1 - a*x)^(3/2))/(5*a*c^2*(1 + a*x)^(3/2)) - (6*Sqrt[1 - a*x])/(a*c^2*Sqrt[1 + a*x]) - (3*ArcSin[a*x])/(a*c^2)}
{1/(E^(3*ArcTanh[a*x])*(c - c/(a^2*x^2))^3), x, 9, (-2*a^3*x^4)/(c^3*Sqrt[1 - a*x]*(1 + a*x)^(7/2)) + (a^4*x^5)/(c^3*Sqrt[1 - a*x]*(1 + a*x)^(7/2)) - (11*a^2*x^3*Sqrt[1 - a*x])/(7*c^3*(1 + a*x)^(7/2)) - (54*a*x^2*Sqrt[1 - a*x])/(35*c^3*(1 + a*x)^(5/2)) + ((36 - 35*a*x)*Sqrt[1 - a*x])/(35*a*c^3*(1 + a*x)^(3/2)) - (212*Sqrt[1 - a*x])/(35*a*c^3*Sqrt[1 + a*x]) - (3*ArcSin[a*x])/(a*c^3)}
{1/(E^(3*ArcTanh[a*x])*(c - c/(a^2*x^2))^4), x, 11, (4*a^5*x^6)/(3*c^4*(1 - a*x)^(3/2)*(1 + a*x)^(9/2)) - (a^6*x^7)/(c^4*(1 - a*x)^(3/2)*(1 + a*x)^(9/2)) - (5*a^4*x^5)/(c^4*Sqrt[1 - a*x]*(1 + a*x)^(9/2)) - (28*a^3*x^4*Sqrt[1 - a*x])/(9*c^4*(1 + a*x)^(9/2)) - (139*a^2*x^3*Sqrt[1 - a*x])/(63*c^4*(1 + a*x)^(7/2)) - (202*a*x^2*Sqrt[1 - a*x])/(105*c^4*(1 + a*x)^(5/2)) + ((404 - 315*a*x)*Sqrt[1 - a*x])/(315*a*c^4*(1 + a*x)^(3/2)) - (2068*Sqrt[1 - a*x])/(315*a*c^4*Sqrt[1 + a*x]) - (3*ArcSin[a*x])/(a*c^4)}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{(c - c/(a^2*x^2))^p/E^(2*p*ArcTanh[a*x]), x, 3, -(((c - c/(a^2*x^2))^p*(a*x)^(2*p)*(1 - a*x)^(1 + 2*p)*Hypergeometric2F1[2*p, 1 + 2*p, 2*(1 + p), 1 - a*x])/((1 - a^2*x^2)^p*(a*(1 + 2*p))))}
{E^(2*p*ArcTanh[a*x])*(c - c/(a^2*x^2))^p, x, 3, ((c - c/(a^2*x^2))^p*((-a)*x)^(2*p)*(1 + a*x)^(1 + 2*p)*Hypergeometric2F1[2*p, 1 + 2*p, 2*(1 + p), 1 + a*x])/((1 - a^2*x^2)^p*(a*(1 + 2*p)))}


{E^(n*ArcTanh[a*x])*(c - c/(a^2*x^2))^p, x, 3, ((c - c/(a^2*x^2))^p*x*AppellF1[1 - 2*p, (1/2)*(n - 2*p), -(n/2) - p, 2 - 2*p, a*x, (-a)*x])/((1 - a^2*x^2)^p*(1 - 2*p))}

{E^(n*ArcTanh[a*x])*(c - c/(a^2*x^2)), x, 3, (2^(2 + n/2)*c*(1 - a*x)^(2 - n/2)*AppellF1[2 - n/2, 2, -1 - n/2, 3 - n/2, 1 - a*x, (1/2)*(1 - a*x)])/(a*(4 - n))}
{E^(n*ArcTanh[a*x])/(c - c/(a^2*x^2)), x, 4, -(E^(n*ArcTanh[a*x])/(a*c*n)) + (2^(1 - n/2)*(1 + a*x)^((2 + n)/2)*Hypergeometric2F1[n/2, (2 + n)/2, (4 + n)/2, (1/2)*(1 + a*x)])/(a*c*(2 + n))}
{E^(n*ArcTanh[a*x])/(c - c/(a^2*x^2))^2, x, 3, -((a^2*x^3*(1 - a*x)^(-1 - n/2)*(1 + a*x)^((1/2)*(-2 + n)))/c^2) - ((3 - n)*(1 - a*x)^(1 - n/2)*(1 + a*x)^((1/2)*(-2 + n)))/(4*a*c^2*(2 - n)) - ((3 - 2*n)*(1 - a*x)^(1 - n/2)*(1 + a*x)^(n/2))/(4*a*c^2*n) + ((3 + n)*(1 - a*x)^(-1 - n/2)*(1 + a*x)^((2 + n)/2))/(4*a*c^2*(2 + n)) - ((3 + 2*n)*(1 + a*x)^((2 + n)/2))/((1 - a*x)^(n/2)*(4*a*c^2*n)) - (2^(-1 - n/2)*(3 - 2*n)*(1 + a*x)^((2 + n)/2)*Hypergeometric2F1[n/2, (2 + n)/2, (4 + n)/2, (1/2)*(1 + a*x)])/(a*c^2*n*(2 + n)) + (2^(-1 - n/2)*(3 + 2*n)*(1 + a*x)^((2 + n)/2)*Hypergeometric2F1[n/2, (2 + n)/2, (4 + n)/2, (1/2)*(1 + a*x)])/(a*c^2*n*(2 + n)), (a^4*x^5*AppellF1[5, (4 + n)/2, 2 - n/2, 6, a*x, (-a)*x])/(5*c^2)}


(* ::Subsection::Closed:: *)
(*Integrands of the form E^(n ArcTanh[a x]) (c-c/(a^2 x^2))^(p/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{E^ArcTanh[a*x]*(c - c/(a^2*x^2))^(9/2), x, 4, -((c - c/(a^2*x^2))^(9/2)*x)/(8*(1 - a^2*x^2)^(9/2)) - (a*(c - c/(a^2*x^2))^(9/2)*x^2)/(7*(1 - a^2*x^2)^(9/2)) + (2*a^2*(c - c/(a^2*x^2))^(9/2)*x^3)/(3*(1 - a^2*x^2)^(9/2)) + (4*a^3*(c - c/(a^2*x^2))^(9/2)*x^4)/(5*(1 - a^2*x^2)^(9/2)) - (3*a^4*(c - c/(a^2*x^2))^(9/2)*x^5)/(2*(1 - a^2*x^2)^(9/2)) - (2*a^5*(c - c/(a^2*x^2))^(9/2)*x^6)/(1 - a^2*x^2)^(9/2) + (2*a^6*(c - c/(a^2*x^2))^(9/2)*x^7)/(1 - a^2*x^2)^(9/2) + (4*a^7*(c - c/(a^2*x^2))^(9/2)*x^8)/(1 - a^2*x^2)^(9/2) + (a^9*(c - c/(a^2*x^2))^(9/2)*x^10)/(1 - a^2*x^2)^(9/2) + (a^8*(c - c/(a^2*x^2))^(9/2)*x^9*Log[x])/(1 - a^2*x^2)^(9/2)}
{E^ArcTanh[a*x]*(c - c/(a^2*x^2))^(7/2), x, 4, -((c - c/(a^2*x^2))^(7/2)*x)/(6*(1 - a^2*x^2)^(7/2)) - (a*(c - c/(a^2*x^2))^(7/2)*x^2)/(5*(1 - a^2*x^2)^(7/2)) + (3*a^2*(c - c/(a^2*x^2))^(7/2)*x^3)/(4*(1 - a^2*x^2)^(7/2)) + (a^3*(c - c/(a^2*x^2))^(7/2)*x^4)/(1 - a^2*x^2)^(7/2) - (3*a^4*(c - c/(a^2*x^2))^(7/2)*x^5)/(2*(1 - a^2*x^2)^(7/2)) - (3*a^5*(c - c/(a^2*x^2))^(7/2)*x^6)/(1 - a^2*x^2)^(7/2) - (a^7*(c - c/(a^2*x^2))^(7/2)*x^8)/(1 - a^2*x^2)^(7/2) - (a^6*(c - c/(a^2*x^2))^(7/2)*x^7*Log[x])/(1 - a^2*x^2)^(7/2)}
{E^ArcTanh[a*x]*(c - c/(a^2*x^2))^(5/2), x, 4, -((c - c/(a^2*x^2))^(5/2)*x)/(4*(1 - a^2*x^2)^(5/2)) - (a*(c - c/(a^2*x^2))^(5/2)*x^2)/(3*(1 - a^2*x^2)^(5/2)) + (a^2*(c - c/(a^2*x^2))^(5/2)*x^3)/(1 - a^2*x^2)^(5/2) + (2*a^3*(c - c/(a^2*x^2))^(5/2)*x^4)/(1 - a^2*x^2)^(5/2) + (a^5*(c - c/(a^2*x^2))^(5/2)*x^6)/(1 - a^2*x^2)^(5/2) + (a^4*(c - c/(a^2*x^2))^(5/2)*x^5*Log[x])/(1 - a^2*x^2)^(5/2)}
{E^ArcTanh[a*x]*(c - c/(a^2*x^2))^(3/2), x, 4, -((c - c/(a^2*x^2))^(3/2)*x)/(2*(1 - a^2*x^2)^(3/2)) - (a*(c - c/(a^2*x^2))^(3/2)*x^2)/(1 - a^2*x^2)^(3/2) - (a^3*(c - c/(a^2*x^2))^(3/2)*x^4)/(1 - a^2*x^2)^(3/2) - (a^2*(c - c/(a^2*x^2))^(3/2)*x^3*Log[x])/(1 - a^2*x^2)^(3/2)}
{E^ArcTanh[a*x]*Sqrt[c - c/(a^2*x^2)], x, 4, (a*Sqrt[c - c/(a^2*x^2)]*x^2)/Sqrt[1 - a^2*x^2] + (Sqrt[c - c/(a^2*x^2)]*x*Log[x])/Sqrt[1 - a^2*x^2]}
{E^ArcTanh[a*x]/Sqrt[c - c/(a^2*x^2)], x, 4, -(Sqrt[1 - a^2*x^2]/(a*Sqrt[c - c/(a^2*x^2)])) - (Sqrt[1 - a^2*x^2]*Log[1 - a*x])/(a^2*Sqrt[c - c/(a^2*x^2)]*x)}
{E^ArcTanh[a*x]/(c - c/(a^2*x^2))^(3/2), x, 4, (1 - a^2*x^2)^(3/2)/(a^3*(c - c/(a^2*x^2))^(3/2)*x^2) + (1 - a^2*x^2)^(3/2)/(2*a^4*(c - c/(a^2*x^2))^(3/2)*x^3*(1 - a*x)) + (5*(1 - a^2*x^2)^(3/2)*Log[1 - a*x])/(4*a^4*(c - c/(a^2*x^2))^(3/2)*x^3) - ((1 - a^2*x^2)^(3/2)*Log[1 + a*x])/(4*a^4*(c - c/(a^2*x^2))^(3/2)*x^3)}
{E^ArcTanh[a*x]/(c - c/(a^2*x^2))^(5/2), x, 4, -((1 - a^2*x^2)^(5/2)/(a^5*(c - c/(a^2*x^2))^(5/2)*x^4)) + (1 - a^2*x^2)^(5/2)/(8*a^6*(c - c/(a^2*x^2))^(5/2)*x^5*(1 - a*x)^2) - (1 - a^2*x^2)^(5/2)/(a^6*(c - c/(a^2*x^2))^(5/2)*x^5*(1 - a*x)) + (1 - a^2*x^2)^(5/2)/(8*a^6*(c - c/(a^2*x^2))^(5/2)*x^5*(1 + a*x)) - (23*(1 - a^2*x^2)^(5/2)*Log[1 - a*x])/(16*a^6*(c - c/(a^2*x^2))^(5/2)*x^5) + (7*(1 - a^2*x^2)^(5/2)*Log[1 + a*x])/(16*a^6*(c - c/(a^2*x^2))^(5/2)*x^5)}
{E^ArcTanh[a*x]/(c - c/(a^2*x^2))^(7/2), x, 4, (1 - a^2*x^2)^(7/2)/(a^7*(c - c/(a^2*x^2))^(7/2)*x^6) + (1 - a^2*x^2)^(7/2)/(24*a^8*(c - c/(a^2*x^2))^(7/2)*x^7*(1 - a*x)^3) - (11*(1 - a^2*x^2)^(7/2))/(32*a^8*(c - c/(a^2*x^2))^(7/2)*x^7*(1 - a*x)^2) + (3*(1 - a^2*x^2)^(7/2))/(2*a^8*(c - c/(a^2*x^2))^(7/2)*x^7*(1 - a*x)) + (1 - a^2*x^2)^(7/2)/(32*a^8*(c - c/(a^2*x^2))^(7/2)*x^7*(1 + a*x)^2) - (5*(1 - a^2*x^2)^(7/2))/(16*a^8*(c - c/(a^2*x^2))^(7/2)*x^7*(1 + a*x)) + (51*(1 - a^2*x^2)^(7/2)*Log[1 - a*x])/(32*a^8*(c - c/(a^2*x^2))^(7/2)*x^7) - (19*(1 - a^2*x^2)^(7/2)*Log[1 + a*x])/(32*a^8*(c - c/(a^2*x^2))^(7/2)*x^7)}


{E^(2*ArcTanh[a*x])*(c - c/(a^2*x^2))^(9/2), x, 14, (295*a^4*(c - c/(a^2*x^2))^(9/2)*x^5)/(1344*(1 - a*x)^4) - (501*a^8*(c - c/(a^2*x^2))^(9/2)*x^9)/(128*(1 - a*x)^4*(1 + a*x)^4) + (373*a^7*(c - c/(a^2*x^2))^(9/2)*x^8)/(192*(1 - a*x)^4*(1 + a*x)^3) + (501*a^6*(c - c/(a^2*x^2))^(9/2)*x^7)/(640*(1 - a*x)^4*(1 + a*x)^2) + (661*a^5*(c - c/(a^2*x^2))^(9/2)*x^6)/(1680*(1 - a*x)^4*(1 + a*x)) - (127*a^3*(c - c/(a^2*x^2))^(9/2)*x^4*(1 + a*x))/(420*(1 - a*x)^4) + (71*a^2*(c - c/(a^2*x^2))^(9/2)*x^3*(1 + a*x))/(336*(1 - a*x)^3) - (a*(c - c/(a^2*x^2))^(9/2)*x^2*(1 + a*x))/(28*(1 - a*x)^2) - ((c - c/(a^2*x^2))^(9/2)*x*(1 + a*x))/(8*(1 - a*x)) + (2*a^8*(c - c/(a^2*x^2))^(9/2)*x^9*ArcSin[a*x])/((1 - a*x)^(9/2)*(1 + a*x)^(9/2)) + (245*a^8*(c - c/(a^2*x^2))^(9/2)*x^9*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(64*(1 - a*x)^(9/2)*(1 + a*x)^(9/2))}
{E^(2*ArcTanh[a*x])*(c - c/(a^2*x^2))^(7/2), x, 12, -((11*a^3*(c - c/(a^2*x^2))^(7/2)*x^4)/(30*(1 - a*x)^3)) + (57*a^6*(c - c/(a^2*x^2))^(7/2)*x^7)/(16*(1 - a*x)^3*(1 + a*x)^3) - (41*a^5*(c - c/(a^2*x^2))^(7/2)*x^6)/(24*(1 - a*x)^3*(1 + a*x)^2) - (57*a^4*(c - c/(a^2*x^2))^(7/2)*x^5)/(80*(1 - a*x)^3*(1 + a*x)) + (13*a^2*(c - c/(a^2*x^2))^(7/2)*x^3*(1 + a*x))/(40*(1 - a*x)^3) - (a*(c - c/(a^2*x^2))^(7/2)*x^2*(1 + a*x))/(15*(1 - a*x)^2) - ((c - c/(a^2*x^2))^(7/2)*x*(1 + a*x))/(6*(1 - a*x)) - (2*a^6*(c - c/(a^2*x^2))^(7/2)*x^7*ArcSin[a*x])/((1 - a*x)^(7/2)*(1 + a*x)^(7/2)) - (25*a^6*(c - c/(a^2*x^2))^(7/2)*x^7*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(8*(1 - a*x)^(7/2)*(1 + a*x)^(7/2))}
{E^(2*ArcTanh[a*x])*(c - c/(a^2*x^2))^(5/2), x, 10, (5*a^2*(c - c/(a^2*x^2))^(5/2)*x^3)/(8*(1 - a*x)^2) - (25*a^4*(c - c/(a^2*x^2))^(5/2)*x^5)/(8*(1 - a*x)^2*(1 + a*x)^2) + (17*a^3*(c - c/(a^2*x^2))^(5/2)*x^4)/(12*(1 - a*x)^2*(1 + a*x)) - (a*(c - c/(a^2*x^2))^(5/2)*x^2*(1 + a*x))/(6*(1 - a*x)^2) - ((c - c/(a^2*x^2))^(5/2)*x*(1 + a*x))/(4*(1 - a*x)) + (2*a^4*(c - c/(a^2*x^2))^(5/2)*x^5*ArcSin[a*x])/((1 - a*x)^(5/2)*(1 + a*x)^(5/2)) + (9*a^4*(c - c/(a^2*x^2))^(5/2)*x^5*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(4*(1 - a*x)^(5/2)*(1 + a*x)^(5/2))}
{E^(2*ArcTanh[a*x])*(c - c/(a^2*x^2))^(3/2), x, 8, -((a*(c - c/(a^2*x^2))^(3/2)*x^2)/(1 - a*x)) + (5*a^2*(c - c/(a^2*x^2))^(3/2)*x^3)/(2*(1 - a*x)*(1 + a*x)) - ((c - c/(a^2*x^2))^(3/2)*x*(1 + a*x))/(2*(1 - a*x)) - (2*a^2*(c - c/(a^2*x^2))^(3/2)*x^3*ArcSin[a*x])/((1 - a*x)^(3/2)*(1 + a*x)^(3/2)) - (a^2*(c - c/(a^2*x^2))^(3/2)*x^3*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/((1 - a*x)^(3/2)*(1 + a*x)^(3/2))}
{E^(2*ArcTanh[a*x])*Sqrt[c - c/(a^2*x^2)], x, 6, (-Sqrt[c - c/(a^2*x^2)])*x + (2*Sqrt[c - c/(a^2*x^2)]*x*ArcSin[a*x])/(Sqrt[1 - a*x]*Sqrt[1 + a*x]) - (2*Sqrt[c - c/(a^2*x^2)]*x*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{E^(2*ArcTanh[a*x])/Sqrt[c - c/(a^2*x^2)], x, 5, (2*(1 - a*x)*(1 + a*x))/(a^2*Sqrt[c - c/(a^2*x^2)]*x) + (1 + a*x)^2/(a^2*Sqrt[c - c/(a^2*x^2)]*x) - (2*Sqrt[1 - a*x]*Sqrt[1 + a*x]*ArcSin[a*x])/(a^2*Sqrt[c - c/(a^2*x^2)]*x)}
{E^(2*ArcTanh[a*x])/(c - c/(a^2*x^2))^(3/2), x, 7, -((1 + a*x)^2/(a^2*(c - c/(a^2*x^2))^(3/2)*x)) - (4*(1 - a*x)*(1 + a*x)^2)/(a^4*(c - c/(a^2*x^2))^(3/2)*x^3) + (2*(1 + a*x)^3)/(3*a^4*(c - c/(a^2*x^2))^(3/2)*x^3) + (2*(1 - a*x)^(3/2)*(1 + a*x)^(3/2)*ArcSin[a*x])/(a^4*(c - c/(a^2*x^2))^(3/2)*x^3)}
{E^(2*ArcTanh[a*x])/(c - c/(a^2*x^2))^(5/2), x, 8, (6*(1 + a*x)^2)/(5*a^3*(c - c/(a^2*x^2))^(5/2)*x^2) - (1 + a*x)^2/(a^2*(c - c/(a^2*x^2))^(5/2)*x) - (28*(1 - a*x)*(1 + a*x)^2)/(15*a^4*(c - c/(a^2*x^2))^(5/2)*x^3) + (2*(1 - a*x)^2*(1 + a*x)^2*(28 + 15*a*x))/(15*a^6*(c - c/(a^2*x^2))^(5/2)*x^5) - (2*(1 - a*x)^(5/2)*(1 + a*x)^(5/2)*ArcSin[a*x])/(a^6*(c - c/(a^2*x^2))^(5/2)*x^5)}
{E^(2*ArcTanh[a*x])/(c - c/(a^2*x^2))^(7/2), x, 10, (8*(1 + a*x)^2)/(7*a^3*(c - c/(a^2*x^2))^(7/2)*x^2) - (1 + a*x)^2/(a^2*(c - c/(a^2*x^2))^(7/2)*x) - (54*(1 - a*x)*(1 + a*x)^2)/(35*a^4*(c - c/(a^2*x^2))^(7/2)*x^3) + (286*(1 - a*x)^2*(1 + a*x)^2)/(105*a^5*(c - c/(a^2*x^2))^(7/2)*x^4) - (356*(1 - a*x)^3*(1 + a*x)^2)/(35*a^6*(c - c/(a^2*x^2))^(7/2)*x^5) - (1144*(1 - a*x)^4*(1 + a*x)^3)/(105*a^8*(c - c/(a^2*x^2))^(7/2)*x^7) + (2*(1 - a*x)^4*(1 + a*x)^2*(356 + 35*a*x))/(105*a^8*(c - c/(a^2*x^2))^(7/2)*x^7) + (2*(1 - a*x)^(7/2)*(1 + a*x)^(7/2)*ArcSin[a*x])/(a^8*(c - c/(a^2*x^2))^(7/2)*x^7)}
{E^(2*ArcTanh[a*x])/(c - c/(a^2*x^2))^(9/2), x, 12, (10*(1 + a*x)^2)/(9*a^3*(c - c/(a^2*x^2))^(9/2)*x^2) - (1 + a*x)^2/(a^2*(c - c/(a^2*x^2))^(9/2)*x) - (88*(1 - a*x)*(1 + a*x)^2)/(63*a^4*(c - c/(a^2*x^2))^(9/2)*x^3) + (218*(1 - a*x)^2*(1 + a*x)^2)/(105*a^5*(c - c/(a^2*x^2))^(9/2)*x^4) - (260*(1 - a*x)^3*(1 + a*x)^2)/(63*a^6*(c - c/(a^2*x^2))^(9/2)*x^5) + (1166*(1 - a*x)^4*(1 + a*x)^2)/(63*a^7*(c - c/(a^2*x^2))^(9/2)*x^6) + (1124*(1 - a*x)^5*(1 + a*x)^2)/(105*a^8*(c - c/(a^2*x^2))^(9/2)*x^7) + (3656*(1 - a*x)^5*(1 + a*x)^4)/(315*a^10*(c - c/(a^2*x^2))^(9/2)*x^9) - (2*(1 - a*x)^5*(1 + a*x)^3*(1124 + 105*a*x))/(315*a^10*(c - c/(a^2*x^2))^(9/2)*x^9) - (2*(1 - a*x)^(9/2)*(1 + a*x)^(9/2)*ArcSin[a*x])/(a^10*(c - c/(a^2*x^2))^(9/2)*x^9)}


{E^(3*ArcTanh[a*x])*(c - c/(a^2*x^2))^(9/2), x, 4, -((c - c/(a^2*x^2))^(9/2)*x)/(8*(1 - a^2*x^2)^(9/2)) - (3*a*(c - c/(a^2*x^2))^(9/2)*x^2)/(7*(1 - a^2*x^2)^(9/2)) + (8*a^3*(c - c/(a^2*x^2))^(9/2)*x^4)/(5*(1 - a^2*x^2)^(9/2)) + (3*a^4*(c - c/(a^2*x^2))^(9/2)*x^5)/(2*(1 - a^2*x^2)^(9/2)) - (2*a^5*(c - c/(a^2*x^2))^(9/2)*x^6)/(1 - a^2*x^2)^(9/2) - (4*a^6*(c - c/(a^2*x^2))^(9/2)*x^7)/(1 - a^2*x^2)^(9/2) - (a^9*(c - c/(a^2*x^2))^(9/2)*x^10)/(1 - a^2*x^2)^(9/2) - (3*a^8*(c - c/(a^2*x^2))^(9/2)*x^9*Log[x])/(1 - a^2*x^2)^(9/2)}
{E^(3*ArcTanh[a*x])*(c - c/(a^2*x^2))^(7/2), x, 4, -((c - c/(a^2*x^2))^(7/2)*x)/(6*(1 - a^2*x^2)^(7/2)) - (3*a*(c - c/(a^2*x^2))^(7/2)*x^2)/(5*(1 - a^2*x^2)^(7/2)) - (a^2*(c - c/(a^2*x^2))^(7/2)*x^3)/(4*(1 - a^2*x^2)^(7/2)) + (5*a^3*(c - c/(a^2*x^2))^(7/2)*x^4)/(3*(1 - a^2*x^2)^(7/2)) + (5*a^4*(c - c/(a^2*x^2))^(7/2)*x^5)/(2*(1 - a^2*x^2)^(7/2)) - (a^5*(c - c/(a^2*x^2))^(7/2)*x^6)/(1 - a^2*x^2)^(7/2) + (a^7*(c - c/(a^2*x^2))^(7/2)*x^8)/(1 - a^2*x^2)^(7/2) + (3*a^6*(c - c/(a^2*x^2))^(7/2)*x^7*Log[x])/(1 - a^2*x^2)^(7/2)}
{E^(3*ArcTanh[a*x])*(c - c/(a^2*x^2))^(5/2), x, 4, -((c - c/(a^2*x^2))^(5/2)*x)/(4*(1 - a^2*x^2)^(5/2)) - (a*(c - c/(a^2*x^2))^(5/2)*x^2)/(1 - a^2*x^2)^(5/2) - (a^2*(c - c/(a^2*x^2))^(5/2)*x^3)/(1 - a^2*x^2)^(5/2) + (2*a^3*(c - c/(a^2*x^2))^(5/2)*x^4)/(1 - a^2*x^2)^(5/2) - (a^5*(c - c/(a^2*x^2))^(5/2)*x^6)/(1 - a^2*x^2)^(5/2) - (3*a^4*(c - c/(a^2*x^2))^(5/2)*x^5*Log[x])/(1 - a^2*x^2)^(5/2)}
{E^(3*ArcTanh[a*x])*(c - c/(a^2*x^2))^(3/2), x, 4, -((c - c/(a^2*x^2))^(3/2)*x)/(2*(1 - a^2*x^2)^(3/2)) - (3*a*(c - c/(a^2*x^2))^(3/2)*x^2)/(1 - a^2*x^2)^(3/2) + (a^3*(c - c/(a^2*x^2))^(3/2)*x^4)/(1 - a^2*x^2)^(3/2) + (3*a^2*(c - c/(a^2*x^2))^(3/2)*x^3*Log[x])/(1 - a^2*x^2)^(3/2)}
{E^(3*ArcTanh[a*x])*Sqrt[c - c/(a^2*x^2)], x, 4, -((a*Sqrt[c - c/(a^2*x^2)]*x^2)/Sqrt[1 - a^2*x^2]) + (Sqrt[c - c/(a^2*x^2)]*x*Log[x])/Sqrt[1 - a^2*x^2] - (4*Sqrt[c - c/(a^2*x^2)]*x*Log[1 - a*x])/Sqrt[1 - a^2*x^2]}
{E^(3*ArcTanh[a*x])/Sqrt[c - c/(a^2*x^2)], x, 4, Sqrt[1 - a^2*x^2]/(a*Sqrt[c - c/(a^2*x^2)]) + (2*Sqrt[1 - a^2*x^2])/(a^2*Sqrt[c - c/(a^2*x^2)]*x*(1 - a*x)) + (3*Sqrt[1 - a^2*x^2]*Log[1 - a*x])/(a^2*Sqrt[c - c/(a^2*x^2)]*x)}
{E^(3*ArcTanh[a*x])/(c - c/(a^2*x^2))^(3/2), x, 4, -((1 - a^2*x^2)^(3/2)/(a^3*(c - c/(a^2*x^2))^(3/2)*x^2)) + (1 - a^2*x^2)^(3/2)/(2*a^4*(c - c/(a^2*x^2))^(3/2)*x^3*(1 - a*x)^2) - (3*(1 - a^2*x^2)^(3/2))/(a^4*(c - c/(a^2*x^2))^(3/2)*x^3*(1 - a*x)) - (3*(1 - a^2*x^2)^(3/2)*Log[1 - a*x])/(a^4*(c - c/(a^2*x^2))^(3/2)*x^3)}
{E^(3*ArcTanh[a*x])/(c - c/(a^2*x^2))^(5/2), x, 4, (1 - a^2*x^2)^(5/2)/(a^5*(c - c/(a^2*x^2))^(5/2)*x^4) + (1 - a^2*x^2)^(5/2)/(6*a^6*(c - c/(a^2*x^2))^(5/2)*x^5*(1 - a*x)^3) - (9*(1 - a^2*x^2)^(5/2))/(8*a^6*(c - c/(a^2*x^2))^(5/2)*x^5*(1 - a*x)^2) + (31*(1 - a^2*x^2)^(5/2))/(8*a^6*(c - c/(a^2*x^2))^(5/2)*x^5*(1 - a*x)) + (49*(1 - a^2*x^2)^(5/2)*Log[1 - a*x])/(16*a^6*(c - c/(a^2*x^2))^(5/2)*x^5) - ((1 - a^2*x^2)^(5/2)*Log[1 + a*x])/(16*a^6*(c - c/(a^2*x^2))^(5/2)*x^5)}
{E^(3*ArcTanh[a*x])/(c - c/(a^2*x^2))^(7/2), x, 4, -((1 - a^2*x^2)^(7/2)/(a^7*(c - c/(a^2*x^2))^(7/2)*x^6)) + (1 - a^2*x^2)^(7/2)/(16*a^8*(c - c/(a^2*x^2))^(7/2)*x^7*(1 - a*x)^4) - (1 - a^2*x^2)^(7/2)/(2*a^8*(c - c/(a^2*x^2))^(7/2)*x^7*(1 - a*x)^3) + (59*(1 - a^2*x^2)^(7/2))/(32*a^8*(c - c/(a^2*x^2))^(7/2)*x^7*(1 - a*x)^2) - (75*(1 - a^2*x^2)^(7/2))/(16*a^8*(c - c/(a^2*x^2))^(7/2)*x^7*(1 - a*x)) + (1 - a^2*x^2)^(7/2)/(32*a^8*(c - c/(a^2*x^2))^(7/2)*x^7*(1 + a*x)) - (201*(1 - a^2*x^2)^(7/2)*Log[1 - a*x])/(64*a^8*(c - c/(a^2*x^2))^(7/2)*x^7) + (9*(1 - a^2*x^2)^(7/2)*Log[1 + a*x])/(64*a^8*(c - c/(a^2*x^2))^(7/2)*x^7)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(c - c/(a^2*x^2))^(9/2)/E^ArcTanh[a*x], x, 4, -((c - c/(a^2*x^2))^(9/2)*x)/(8*(1 - a^2*x^2)^(9/2)) + (a*(c - c/(a^2*x^2))^(9/2)*x^2)/(7*(1 - a^2*x^2)^(9/2)) + (2*a^2*(c - c/(a^2*x^2))^(9/2)*x^3)/(3*(1 - a^2*x^2)^(9/2)) - (4*a^3*(c - c/(a^2*x^2))^(9/2)*x^4)/(5*(1 - a^2*x^2)^(9/2)) - (3*a^4*(c - c/(a^2*x^2))^(9/2)*x^5)/(2*(1 - a^2*x^2)^(9/2)) + (2*a^5*(c - c/(a^2*x^2))^(9/2)*x^6)/(1 - a^2*x^2)^(9/2) + (2*a^6*(c - c/(a^2*x^2))^(9/2)*x^7)/(1 - a^2*x^2)^(9/2) - (4*a^7*(c - c/(a^2*x^2))^(9/2)*x^8)/(1 - a^2*x^2)^(9/2) - (a^9*(c - c/(a^2*x^2))^(9/2)*x^10)/(1 - a^2*x^2)^(9/2) + (a^8*(c - c/(a^2*x^2))^(9/2)*x^9*Log[x])/(1 - a^2*x^2)^(9/2)}
{(c - c/(a^2*x^2))^(7/2)/E^ArcTanh[a*x], x, 4, -((c - c/(a^2*x^2))^(7/2)*x)/(6*(1 - a^2*x^2)^(7/2)) + (a*(c - c/(a^2*x^2))^(7/2)*x^2)/(5*(1 - a^2*x^2)^(7/2)) + (3*a^2*(c - c/(a^2*x^2))^(7/2)*x^3)/(4*(1 - a^2*x^2)^(7/2)) - (a^3*(c - c/(a^2*x^2))^(7/2)*x^4)/(1 - a^2*x^2)^(7/2) - (3*a^4*(c - c/(a^2*x^2))^(7/2)*x^5)/(2*(1 - a^2*x^2)^(7/2)) + (3*a^5*(c - c/(a^2*x^2))^(7/2)*x^6)/(1 - a^2*x^2)^(7/2) + (a^7*(c - c/(a^2*x^2))^(7/2)*x^8)/(1 - a^2*x^2)^(7/2) - (a^6*(c - c/(a^2*x^2))^(7/2)*x^7*Log[x])/(1 - a^2*x^2)^(7/2)}
{(c - c/(a^2*x^2))^(5/2)/E^ArcTanh[a*x], x, 4, -((c - c/(a^2*x^2))^(5/2)*x)/(4*(1 - a^2*x^2)^(5/2)) + (a*(c - c/(a^2*x^2))^(5/2)*x^2)/(3*(1 - a^2*x^2)^(5/2)) + (a^2*(c - c/(a^2*x^2))^(5/2)*x^3)/(1 - a^2*x^2)^(5/2) - (2*a^3*(c - c/(a^2*x^2))^(5/2)*x^4)/(1 - a^2*x^2)^(5/2) - (a^5*(c - c/(a^2*x^2))^(5/2)*x^6)/(1 - a^2*x^2)^(5/2) + (a^4*(c - c/(a^2*x^2))^(5/2)*x^5*Log[x])/(1 - a^2*x^2)^(5/2)}
{(c - c/(a^2*x^2))^(3/2)/E^ArcTanh[a*x], x, 4, -((c - c/(a^2*x^2))^(3/2)*x)/(2*(1 - a^2*x^2)^(3/2)) + (a*(c - c/(a^2*x^2))^(3/2)*x^2)/(1 - a^2*x^2)^(3/2) + (a^3*(c - c/(a^2*x^2))^(3/2)*x^4)/(1 - a^2*x^2)^(3/2) - (a^2*(c - c/(a^2*x^2))^(3/2)*x^3*Log[x])/(1 - a^2*x^2)^(3/2)}
{Sqrt[c - c/(a^2*x^2)]/E^ArcTanh[a*x], x, 4, -((a*Sqrt[c - c/(a^2*x^2)]*x^2)/Sqrt[1 - a^2*x^2]) + (Sqrt[c - c/(a^2*x^2)]*x*Log[x])/Sqrt[1 - a^2*x^2]}
{1/(E^ArcTanh[a*x]*Sqrt[c - c/(a^2*x^2)]), x, 4, Sqrt[1 - a^2*x^2]/(a*Sqrt[c - c/(a^2*x^2)]) - (Sqrt[1 - a^2*x^2]*Log[1 + a*x])/(a^2*Sqrt[c - c/(a^2*x^2)]*x)}
{1/(E^ArcTanh[a*x]*(c - c/(a^2*x^2))^(3/2)), x, 4, -((1 - a^2*x^2)^(3/2)/(a^3*(c - c/(a^2*x^2))^(3/2)*x^2)) + (1 - a^2*x^2)^(3/2)/(2*a^4*(c - c/(a^2*x^2))^(3/2)*x^3*(1 + a*x)) - ((1 - a^2*x^2)^(3/2)*Log[1 - a*x])/(4*a^4*(c - c/(a^2*x^2))^(3/2)*x^3) + (5*(1 - a^2*x^2)^(3/2)*Log[1 + a*x])/(4*a^4*(c - c/(a^2*x^2))^(3/2)*x^3)}
{1/(E^ArcTanh[a*x]*(c - c/(a^2*x^2))^(5/2)), x, 4, (1 - a^2*x^2)^(5/2)/(a^5*(c - c/(a^2*x^2))^(5/2)*x^4) + (1 - a^2*x^2)^(5/2)/(8*a^6*(c - c/(a^2*x^2))^(5/2)*x^5*(1 - a*x)) + (1 - a^2*x^2)^(5/2)/(8*a^6*(c - c/(a^2*x^2))^(5/2)*x^5*(1 + a*x)^2) - (1 - a^2*x^2)^(5/2)/(a^6*(c - c/(a^2*x^2))^(5/2)*x^5*(1 + a*x)) + (7*(1 - a^2*x^2)^(5/2)*Log[1 - a*x])/(16*a^6*(c - c/(a^2*x^2))^(5/2)*x^5) - (23*(1 - a^2*x^2)^(5/2)*Log[1 + a*x])/(16*a^6*(c - c/(a^2*x^2))^(5/2)*x^5)}
{1/(E^ArcTanh[a*x]*(c - c/(a^2*x^2))^(7/2)), x, 4, -((1 - a^2*x^2)^(7/2)/(a^7*(c - c/(a^2*x^2))^(7/2)*x^6)) + (1 - a^2*x^2)^(7/2)/(32*a^8*(c - c/(a^2*x^2))^(7/2)*x^7*(1 - a*x)^2) - (5*(1 - a^2*x^2)^(7/2))/(16*a^8*(c - c/(a^2*x^2))^(7/2)*x^7*(1 - a*x)) + (1 - a^2*x^2)^(7/2)/(24*a^8*(c - c/(a^2*x^2))^(7/2)*x^7*(1 + a*x)^3) - (11*(1 - a^2*x^2)^(7/2))/(32*a^8*(c - c/(a^2*x^2))^(7/2)*x^7*(1 + a*x)^2) + (3*(1 - a^2*x^2)^(7/2))/(2*a^8*(c - c/(a^2*x^2))^(7/2)*x^7*(1 + a*x)) - (19*(1 - a^2*x^2)^(7/2)*Log[1 - a*x])/(32*a^8*(c - c/(a^2*x^2))^(7/2)*x^7) + (51*(1 - a^2*x^2)^(7/2)*Log[1 + a*x])/(32*a^8*(c - c/(a^2*x^2))^(7/2)*x^7)}


{(c - c/(a^2*x^2))^(9/2)/E^(2*ArcTanh[a*x]), x, 14, (11*a^8*(c - c/(a^2*x^2))^(9/2)*x^9)/(128*(1 - a*x)^4*(1 + a*x)^4) + (39*a^7*(c - c/(a^2*x^2))^(9/2)*x^8)/(64*(1 - a*x)^4*(1 + a*x)^3) - (11*a^6*(c - c/(a^2*x^2))^(9/2)*x^7)/(640*(1 - a*x)^4*(1 + a*x)^2) + (a*(c - c/(a^2*x^2))^(9/2)*x^2)/(28*(1 + a*x)) - (103*a^5*(c - c/(a^2*x^2))^(9/2)*x^6)/(160*(1 - a*x)^4*(1 + a*x)) + (629*a^4*(c - c/(a^2*x^2))^(9/2)*x^5)/(960*(1 - a*x)^3*(1 + a*x)) - (2*a^3*(c - c/(a^2*x^2))^(9/2)*x^4)/(5*(1 - a*x)^2*(1 + a*x)) + (47*a^2*(c - c/(a^2*x^2))^(9/2)*x^3)/(336*(1 - a*x)*(1 + a*x)) - ((c - c/(a^2*x^2))^(9/2)*x*(1 - a*x))/(8*(1 + a*x)) - (2*a^8*(c - c/(a^2*x^2))^(9/2)*x^9*ArcSin[a*x])/((1 - a*x)^(9/2)*(1 + a*x)^(9/2)) + (245*a^8*(c - c/(a^2*x^2))^(9/2)*x^9*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(64*(1 - a*x)^(9/2)*(1 + a*x)^(9/2))}
{(c - c/(a^2*x^2))^(7/2)/E^(2*ArcTanh[a*x]), x, 12, -((7*a^6*(c - c/(a^2*x^2))^(7/2)*x^7)/(16*(1 - a*x)^3*(1 + a*x)^3)) - (3*a^5*(c - c/(a^2*x^2))^(7/2)*x^6)/(8*(1 - a*x)^3*(1 + a*x)^2) + (a*(c - c/(a^2*x^2))^(7/2)*x^2)/(15*(1 + a*x)) + (19*a^4*(c - c/(a^2*x^2))^(7/2)*x^5)/(16*(1 - a*x)^3*(1 + a*x)) - (2*a^3*(c - c/(a^2*x^2))^(7/2)*x^4)/(3*(1 - a*x)^2*(1 + a*x)) + (23*a^2*(c - c/(a^2*x^2))^(7/2)*x^3)/(120*(1 - a*x)*(1 + a*x)) - ((c - c/(a^2*x^2))^(7/2)*x*(1 - a*x))/(6*(1 + a*x)) + (2*a^6*(c - c/(a^2*x^2))^(7/2)*x^7*ArcSin[a*x])/((1 - a*x)^(7/2)*(1 + a*x)^(7/2)) - (25*a^6*(c - c/(a^2*x^2))^(7/2)*x^7*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(8*(1 - a*x)^(7/2)*(1 + a*x)^(7/2))}
{(c - c/(a^2*x^2))^(5/2)/E^(2*ArcTanh[a*x]), x, 10, (7*a^4*(c - c/(a^2*x^2))^(5/2)*x^5)/(8*(1 - a*x)^2*(1 + a*x)^2) + (a*(c - c/(a^2*x^2))^(5/2)*x^2)/(6*(1 + a*x)) - (2*a^3*(c - c/(a^2*x^2))^(5/2)*x^4)/((1 - a*x)^2*(1 + a*x)) + (7*a^2*(c - c/(a^2*x^2))^(5/2)*x^3)/(24*(1 - a*x)*(1 + a*x)) - ((c - c/(a^2*x^2))^(5/2)*x*(1 - a*x))/(4*(1 + a*x)) - (2*a^4*(c - c/(a^2*x^2))^(5/2)*x^5*ArcSin[a*x])/((1 - a*x)^(5/2)*(1 + a*x)^(5/2)) + (9*a^4*(c - c/(a^2*x^2))^(5/2)*x^5*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(4*(1 - a*x)^(5/2)*(1 + a*x)^(5/2))}
{(c - c/(a^2*x^2))^(3/2)/E^(2*ArcTanh[a*x]), x, 8, (a*(c - c/(a^2*x^2))^(3/2)*x^2)/(1 + a*x) + (5*a^2*(c - c/(a^2*x^2))^(3/2)*x^3)/(2*(1 - a*x)*(1 + a*x)) - ((c - c/(a^2*x^2))^(3/2)*x*(1 - a*x))/(2*(1 + a*x)) + (2*a^2*(c - c/(a^2*x^2))^(3/2)*x^3*ArcSin[a*x])/((1 - a*x)^(3/2)*(1 + a*x)^(3/2)) - (a^2*(c - c/(a^2*x^2))^(3/2)*x^3*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/((1 - a*x)^(3/2)*(1 + a*x)^(3/2))}
{Sqrt[c - c/(a^2*x^2)]/E^(2*ArcTanh[a*x]), x, 6, (-Sqrt[c - c/(a^2*x^2)])*x - (2*Sqrt[c - c/(a^2*x^2)]*x*ArcSin[a*x])/(Sqrt[1 - a*x]*Sqrt[1 + a*x]) - (2*Sqrt[c - c/(a^2*x^2)]*x*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{1/(E^(2*ArcTanh[a*x])*Sqrt[c - c/(a^2*x^2)]), x, 5, (1 - a*x)^2/(a^2*Sqrt[c - c/(a^2*x^2)]*x) + (2*(1 - a*x)*(1 + a*x))/(a^2*Sqrt[c - c/(a^2*x^2)]*x) + (2*Sqrt[1 - a*x]*Sqrt[1 + a*x]*ArcSin[a*x])/(a^2*Sqrt[c - c/(a^2*x^2)]*x)}
{1/(E^(2*ArcTanh[a*x])*(c - c/(a^2*x^2))^(3/2)), x, 7, -((1 - a*x)^2/(a^2*(c - c/(a^2*x^2))^(3/2)*x)) + (2*(1 - a*x)^3)/(3*a^4*(c - c/(a^2*x^2))^(3/2)*x^3) - (4*(1 - a*x)^2*(1 + a*x))/(a^4*(c - c/(a^2*x^2))^(3/2)*x^3) - (2*(1 - a*x)^(3/2)*(1 + a*x)^(3/2)*ArcSin[a*x])/(a^4*(c - c/(a^2*x^2))^(3/2)*x^3)}
{1/(E^(2*ArcTanh[a*x])*(c - c/(a^2*x^2))^(5/2)), x, 8, (2*(1 - a*x)^2)/(a^3*(c - c/(a^2*x^2))^(5/2)*x^2) - (1 - a*x)^2/(a^2*(c - c/(a^2*x^2))^(5/2)*x) + (8*(1 - a*x)^3)/(5*a^4*(c - c/(a^2*x^2))^(5/2)*x^3) - (2*(8 - 5*a*x)*(1 - a*x)^3*(1 + a*x))/(15*a^6*(c - c/(a^2*x^2))^(5/2)*x^5) + (24*(1 - a*x)^3*(1 + a*x)^2)/(5*a^6*(c - c/(a^2*x^2))^(5/2)*x^5) + (2*(1 - a*x)^(5/2)*(1 + a*x)^(5/2)*ArcSin[a*x])/(a^6*(c - c/(a^2*x^2))^(5/2)*x^5)}
{1/(E^(2*ArcTanh[a*x])*(c - c/(a^2*x^2))^(7/2)), x, 10, (4*(1 - a*x)^2)/(3*a^3*(c - c/(a^2*x^2))^(7/2)*x^2) - (1 - a*x)^2/(a^2*(c - c/(a^2*x^2))^(7/2)*x) - (14*(1 - a*x)^3)/(3*a^4*(c - c/(a^2*x^2))^(7/2)*x^3) - (62*(1 - a*x)^4)/(21*a^5*(c - c/(a^2*x^2))^(7/2)*x^4) - (76*(1 - a*x)^4*(1 + a*x))/(35*a^6*(c - c/(a^2*x^2))^(7/2)*x^5) + (2*(76 - 35*a*x)*(1 - a*x)^4*(1 + a*x)^2)/(105*a^8*(c - c/(a^2*x^2))^(7/2)*x^7) - (584*(1 - a*x)^4*(1 + a*x)^3)/(105*a^8*(c - c/(a^2*x^2))^(7/2)*x^7) - (2*(1 - a*x)^(7/2)*(1 + a*x)^(7/2)*ArcSin[a*x])/(a^8*(c - c/(a^2*x^2))^(7/2)*x^7)}


{(c - c/(a^2*x^2))^(9/2)/E^(3*ArcTanh[a*x]), x, 4, -((c - c/(a^2*x^2))^(9/2)*x)/(8*(1 - a^2*x^2)^(9/2)) + (3*a*(c - c/(a^2*x^2))^(9/2)*x^2)/(7*(1 - a^2*x^2)^(9/2)) - (8*a^3*(c - c/(a^2*x^2))^(9/2)*x^4)/(5*(1 - a^2*x^2)^(9/2)) + (3*a^4*(c - c/(a^2*x^2))^(9/2)*x^5)/(2*(1 - a^2*x^2)^(9/2)) + (2*a^5*(c - c/(a^2*x^2))^(9/2)*x^6)/(1 - a^2*x^2)^(9/2) - (4*a^6*(c - c/(a^2*x^2))^(9/2)*x^7)/(1 - a^2*x^2)^(9/2) + (a^9*(c - c/(a^2*x^2))^(9/2)*x^10)/(1 - a^2*x^2)^(9/2) - (3*a^8*(c - c/(a^2*x^2))^(9/2)*x^9*Log[x])/(1 - a^2*x^2)^(9/2)}
{(c - c/(a^2*x^2))^(7/2)/E^(3*ArcTanh[a*x]), x, 4, -((c - c/(a^2*x^2))^(7/2)*x)/(6*(1 - a^2*x^2)^(7/2)) + (3*a*(c - c/(a^2*x^2))^(7/2)*x^2)/(5*(1 - a^2*x^2)^(7/2)) - (a^2*(c - c/(a^2*x^2))^(7/2)*x^3)/(4*(1 - a^2*x^2)^(7/2)) - (5*a^3*(c - c/(a^2*x^2))^(7/2)*x^4)/(3*(1 - a^2*x^2)^(7/2)) + (5*a^4*(c - c/(a^2*x^2))^(7/2)*x^5)/(2*(1 - a^2*x^2)^(7/2)) + (a^5*(c - c/(a^2*x^2))^(7/2)*x^6)/(1 - a^2*x^2)^(7/2) - (a^7*(c - c/(a^2*x^2))^(7/2)*x^8)/(1 - a^2*x^2)^(7/2) + (3*a^6*(c - c/(a^2*x^2))^(7/2)*x^7*Log[x])/(1 - a^2*x^2)^(7/2)}
{(c - c/(a^2*x^2))^(5/2)/E^(3*ArcTanh[a*x]), x, 4, -((c - c/(a^2*x^2))^(5/2)*x)/(4*(1 - a^2*x^2)^(5/2)) + (a*(c - c/(a^2*x^2))^(5/2)*x^2)/(1 - a^2*x^2)^(5/2) - (a^2*(c - c/(a^2*x^2))^(5/2)*x^3)/(1 - a^2*x^2)^(5/2) - (2*a^3*(c - c/(a^2*x^2))^(5/2)*x^4)/(1 - a^2*x^2)^(5/2) + (a^5*(c - c/(a^2*x^2))^(5/2)*x^6)/(1 - a^2*x^2)^(5/2) - (3*a^4*(c - c/(a^2*x^2))^(5/2)*x^5*Log[x])/(1 - a^2*x^2)^(5/2)}
{(c - c/(a^2*x^2))^(3/2)/E^(3*ArcTanh[a*x]), x, 4, -((c - c/(a^2*x^2))^(3/2)*x)/(2*(1 - a^2*x^2)^(3/2)) + (3*a*(c - c/(a^2*x^2))^(3/2)*x^2)/(1 - a^2*x^2)^(3/2) - (a^3*(c - c/(a^2*x^2))^(3/2)*x^4)/(1 - a^2*x^2)^(3/2) + (3*a^2*(c - c/(a^2*x^2))^(3/2)*x^3*Log[x])/(1 - a^2*x^2)^(3/2)}
{Sqrt[c - c/(a^2*x^2)]/E^(3*ArcTanh[a*x]), x, 4, (a*Sqrt[c - c/(a^2*x^2)]*x^2)/Sqrt[1 - a^2*x^2] + (Sqrt[c - c/(a^2*x^2)]*x*Log[x])/Sqrt[1 - a^2*x^2] - (4*Sqrt[c - c/(a^2*x^2)]*x*Log[1 + a*x])/Sqrt[1 - a^2*x^2]}
{1/(E^(3*ArcTanh[a*x])*Sqrt[c - c/(a^2*x^2)]), x, 4, -(Sqrt[1 - a^2*x^2]/(a*Sqrt[c - c/(a^2*x^2)])) + (2*Sqrt[1 - a^2*x^2])/(a^2*Sqrt[c - c/(a^2*x^2)]*x*(1 + a*x)) + (3*Sqrt[1 - a^2*x^2]*Log[1 + a*x])/(a^2*Sqrt[c - c/(a^2*x^2)]*x)}
{1/(E^(3*ArcTanh[a*x])*(c - c/(a^2*x^2))^(3/2)), x, 4, (1 - a^2*x^2)^(3/2)/(a^3*(c - c/(a^2*x^2))^(3/2)*x^2) + (1 - a^2*x^2)^(3/2)/(2*a^4*(c - c/(a^2*x^2))^(3/2)*x^3*(1 + a*x)^2) - (3*(1 - a^2*x^2)^(3/2))/(a^4*(c - c/(a^2*x^2))^(3/2)*x^3*(1 + a*x)) - (3*(1 - a^2*x^2)^(3/2)*Log[1 + a*x])/(a^4*(c - c/(a^2*x^2))^(3/2)*x^3)}
{1/(E^(3*ArcTanh[a*x])*(c - c/(a^2*x^2))^(5/2)), x, 4, -((1 - a^2*x^2)^(5/2)/(a^5*(c - c/(a^2*x^2))^(5/2)*x^4)) + (1 - a^2*x^2)^(5/2)/(6*a^6*(c - c/(a^2*x^2))^(5/2)*x^5*(1 + a*x)^3) - (9*(1 - a^2*x^2)^(5/2))/(8*a^6*(c - c/(a^2*x^2))^(5/2)*x^5*(1 + a*x)^2) + (31*(1 - a^2*x^2)^(5/2))/(8*a^6*(c - c/(a^2*x^2))^(5/2)*x^5*(1 + a*x)) - ((1 - a^2*x^2)^(5/2)*Log[1 - a*x])/(16*a^6*(c - c/(a^2*x^2))^(5/2)*x^5) + (49*(1 - a^2*x^2)^(5/2)*Log[1 + a*x])/(16*a^6*(c - c/(a^2*x^2))^(5/2)*x^5)}
{1/(E^(3*ArcTanh[a*x])*(c - c/(a^2*x^2))^(7/2)), x, 4, (1 - a^2*x^2)^(7/2)/(a^7*(c - c/(a^2*x^2))^(7/2)*x^6) + (1 - a^2*x^2)^(7/2)/(32*a^8*(c - c/(a^2*x^2))^(7/2)*x^7*(1 - a*x)) + (1 - a^2*x^2)^(7/2)/(16*a^8*(c - c/(a^2*x^2))^(7/2)*x^7*(1 + a*x)^4) - (1 - a^2*x^2)^(7/2)/(2*a^8*(c - c/(a^2*x^2))^(7/2)*x^7*(1 + a*x)^3) + (59*(1 - a^2*x^2)^(7/2))/(32*a^8*(c - c/(a^2*x^2))^(7/2)*x^7*(1 + a*x)^2) - (75*(1 - a^2*x^2)^(7/2))/(16*a^8*(c - c/(a^2*x^2))^(7/2)*x^7*(1 + a*x)) + (9*(1 - a^2*x^2)^(7/2)*Log[1 - a*x])/(64*a^8*(c - c/(a^2*x^2))^(7/2)*x^7) - (201*(1 - a^2*x^2)^(7/2)*Log[1 + a*x])/(64*a^8*(c - c/(a^2*x^2))^(7/2)*x^7)}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{E^(n*ArcTanh[a*x])*(c - c/(a^2*x^2))^(3/2), x, 3, -((2^((5 + n)/2)*a^2*(c - c/(a^2*x^2))^(3/2)*x^3*(1 - a*x)^((5 - n)/2)*AppellF1[(5 - n)/2, 3, (1/2)*(-3 - n), (7 - n)/2, 1 - a*x, (1/2)*(1 - a*x)])/((5 - n)*(1 - a^2*x^2)^(3/2)))}
{E^(n*ArcTanh[a*x])*(c - c/(a^2*x^2))^(1/2), x, 3, -((2^((3 + n)/2)*Sqrt[c - c/(a^2*x^2)]*x*(1 - a*x)^((3 - n)/2)*AppellF1[(3 - n)/2, 1, (-1 - n)/2, (5 - n)/2, 1 - a*x, (1 - a*x)/2])/((3 - n)*Sqrt[1 - a^2*x^2]))}
{E^(n*ArcTanh[a*x])/(c - c/(a^2*x^2))^(1/2), x, 5, -(((1 - a*x)^((1 - n)/2)*(1 + a*x)^((1 + n)/2)*Sqrt[1 - a^2*x^2])/(a^2*(1 + n)*Sqrt[c - c/(a^2*x^2)]*x)) - (n*(1 - a*x)^((1 - n)/2)*(1 + a*x)^((3 + n)/2)*Sqrt[1 - a^2*x^2])/(a^2*(1 - n^2)*Sqrt[c - c/(a^2*x^2)]*x) + (2^(5/2 - n/2)*n*(1 + a*x)^((3 + n)/2)*Sqrt[1 - a^2*x^2]*Hypergeometric2F1[(1/2)*(-1 + n), (3 + n)/2, (5 + n)/2, (1/2)*(1 + a*x)])/(a^2*(1 + n)*(3 - 2*n - n^2)*Sqrt[c - c/(a^2*x^2)]*x)}
{E^(n*ArcTanh[a*x])/(c - c/(a^2*x^2))^(3/2), x, 3, (x*(1 - a^2*x^2)^(3/2)*AppellF1[4, (3 + n)/2, (3 - n)/2, 5, a*x, (-a)*x])/(4*(c - c/(a^2*x^2))^(3/2))}
{E^(n*ArcTanh[a*x])/(c - c/(a^2*x^2))^(5/2), x, 3, (x*(1 - a^2*x^2)^(5/2)*AppellF1[6, (5 + n)/2, (5 - n)/2, 7, a*x, (-a)*x])/(6*(c - c/(a^2*x^2))^(5/2))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(n ArcTanh[a x]) (c-c/(a^2 x^2))^(p/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{E^ArcTanh[a*x]*Sqrt[c - c/(a^2*x^2)]*x^m, x, 4, (Sqrt[c - c/(a^2*x^2)]*x^(1 + m))/(m*Sqrt[1 - a^2*x^2]) + (a*Sqrt[c - c/(a^2*x^2)]*x^(2 + m))/((1 + m)*Sqrt[1 - a^2*x^2])}

{E^ArcTanh[a*x]*Sqrt[c - c/(a^2*x^2)]*x^2, x, 4, (Sqrt[c - c/(a^2*x^2)]*x^3)/(2*Sqrt[1 - a^2*x^2]) + (a*Sqrt[c - c/(a^2*x^2)]*x^4)/(3*Sqrt[1 - a^2*x^2])}
{E^ArcTanh[a*x]*Sqrt[c - c/(a^2*x^2)]*x, x, 3, (Sqrt[c - c/(a^2*x^2)]*x^2)/Sqrt[1 - a^2*x^2] + (a*Sqrt[c - c/(a^2*x^2)]*x^3)/(2*Sqrt[1 - a^2*x^2])}
{E^ArcTanh[a*x]*Sqrt[c - c/(a^2*x^2)], x, 4, (a*Sqrt[c - c/(a^2*x^2)]*x^2)/Sqrt[1 - a^2*x^2] + (Sqrt[c - c/(a^2*x^2)]*x*Log[x])/Sqrt[1 - a^2*x^2]}
{(E^ArcTanh[a*x]*Sqrt[c - c/(a^2*x^2)])/x, x, 4, -(Sqrt[c - c/(a^2*x^2)]/Sqrt[1 - a^2*x^2]) + (a*Sqrt[c - c/(a^2*x^2)]*x*Log[x])/Sqrt[1 - a^2*x^2]}
{(E^ArcTanh[a*x]*Sqrt[c - c/(a^2*x^2)])/x^2, x, 4, -((a*Sqrt[c - c/(a^2*x^2)])/Sqrt[1 - a^2*x^2]) - Sqrt[c - c/(a^2*x^2)]/(2*x*Sqrt[1 - a^2*x^2])}


{E^(2*ArcTanh[a*x])*Sqrt[c - c/(a^2*x^2)]*x^3, x, 7, -((7*Sqrt[c - c/(a^2*x^2)]*x)/(8*a^3)) - (7*Sqrt[c - c/(a^2*x^2)]*x*(1 + a*x))/(24*a^3) - (Sqrt[c - c/(a^2*x^2)]*x*(1 + a*x)^2)/(6*a^3) - (Sqrt[c - c/(a^2*x^2)]*x^2*(1 + a*x)^2)/(4*a^2) + (7*Sqrt[c - c/(a^2*x^2)]*x*ArcSin[a*x])/(8*a^3*Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{E^(2*ArcTanh[a*x])*Sqrt[c - c/(a^2*x^2)]*x^2, x, 6, -((Sqrt[c - c/(a^2*x^2)]*x)/a^2) - (Sqrt[c - c/(a^2*x^2)]*x*(1 + a*x))/(3*a^2) - (Sqrt[c - c/(a^2*x^2)]*x*(1 + a*x)^2)/(3*a^2) + (Sqrt[c - c/(a^2*x^2)]*x*ArcSin[a*x])/(a^2*Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{E^(2*ArcTanh[a*x])*Sqrt[c - c/(a^2*x^2)]*x, x, 5, -((3*Sqrt[c - c/(a^2*x^2)]*x)/(2*a)) - (Sqrt[c - c/(a^2*x^2)]*x*(1 + a*x))/(2*a) + (3*Sqrt[c - c/(a^2*x^2)]*x*ArcSin[a*x])/(2*a*Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{E^(2*ArcTanh[a*x])*Sqrt[c - c/(a^2*x^2)], x, 6, (-Sqrt[c - c/(a^2*x^2)])*x + (2*Sqrt[c - c/(a^2*x^2)]*x*ArcSin[a*x])/(Sqrt[1 - a*x]*Sqrt[1 + a*x]) - (2*Sqrt[c - c/(a^2*x^2)]*x*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{(E^(2*ArcTanh[a*x])*Sqrt[c - c/(a^2*x^2)])/x, x, 7, a*Sqrt[c - c/(a^2*x^2)]*x - Sqrt[c - c/(a^2*x^2)]*(1 + a*x) + (a*Sqrt[c - c/(a^2*x^2)]*x*ArcSin[a*x])/(Sqrt[1 - a*x]*Sqrt[1 + a*x]) - (4*a*Sqrt[c - c/(a^2*x^2)]*x*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{(E^(2*ArcTanh[a*x])*Sqrt[c - c/(a^2*x^2)])/x^2, x, 5, (-(3/2))*a*Sqrt[c - c/(a^2*x^2)] - (Sqrt[c - c/(a^2*x^2)]*(1 + a*x))/(2*x) - (3*a^2*Sqrt[c - c/(a^2*x^2)]*x*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{(E^(2*ArcTanh[a*x])*Sqrt[c - c/(a^2*x^2)])/x^3, x, 7, (-(5/3))*a^2*Sqrt[c - c/(a^2*x^2)] - (2*a*Sqrt[c - c/(a^2*x^2)])/(3*x) - (Sqrt[c - c/(a^2*x^2)]*(1 + a*x))/(3*x^2) - (2*a^3*Sqrt[c - c/(a^2*x^2)]*x*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{(E^(2*ArcTanh[a*x])*Sqrt[c - c/(a^2*x^2)])/x^4, x, 8, (-(4/3))*a^3*Sqrt[c - c/(a^2*x^2)] - (5*a*Sqrt[c - c/(a^2*x^2)])/(12*x^2) - (7*a^2*Sqrt[c - c/(a^2*x^2)])/(8*x) - (Sqrt[c - c/(a^2*x^2)]*(1 + a*x))/(4*x^3) - (7*a^4*Sqrt[c - c/(a^2*x^2)]*x*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(4*Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{(E^(2*ArcTanh[a*x])*Sqrt[c - c/(a^2*x^2)])/x^5, x, 9, (-(6/5))*a^4*Sqrt[c - c/(a^2*x^2)] - (3*a*Sqrt[c - c/(a^2*x^2)])/(10*x^3) - (3*a^2*Sqrt[c - c/(a^2*x^2)])/(5*x^2) - (3*a^3*Sqrt[c - c/(a^2*x^2)])/(4*x) - (Sqrt[c - c/(a^2*x^2)]*(1 + a*x))/(5*x^4) - (3*a^5*Sqrt[c - c/(a^2*x^2)]*x*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(2*Sqrt[1 - a*x]*Sqrt[1 + a*x])}


{E^(3*ArcTanh[a*x])*Sqrt[c - c/(a^2*x^2)]*x^3, x, 4, (-4*Sqrt[c - c/(a^2*x^2)]*x^2)/(a^2*Sqrt[1 - a^2*x^2]) - (2*Sqrt[c - c/(a^2*x^2)]*x^3)/(a*Sqrt[1 - a^2*x^2]) - (Sqrt[c - c/(a^2*x^2)]*x^4)/Sqrt[1 - a^2*x^2] - (a*Sqrt[c - c/(a^2*x^2)]*x^5)/(4*Sqrt[1 - a^2*x^2]) - (4*Sqrt[c - c/(a^2*x^2)]*x*Log[1 - a*x])/(a^3*Sqrt[1 - a^2*x^2])}
{E^(3*ArcTanh[a*x])*Sqrt[c - c/(a^2*x^2)]*x^2, x, 4, (-4*Sqrt[c - c/(a^2*x^2)]*x^2)/(a*Sqrt[1 - a^2*x^2]) - (3*Sqrt[c - c/(a^2*x^2)]*x^3)/(2*Sqrt[1 - a^2*x^2]) - (a*Sqrt[c - c/(a^2*x^2)]*x^4)/(3*Sqrt[1 - a^2*x^2]) - (4*Sqrt[c - c/(a^2*x^2)]*x*Log[1 - a*x])/(a^2*Sqrt[1 - a^2*x^2])}
{E^(3*ArcTanh[a*x])*Sqrt[c - c/(a^2*x^2)]*x, x, 5, (-3*Sqrt[c - c/(a^2*x^2)]*x^2)/Sqrt[1 - a^2*x^2] - (a*Sqrt[c - c/(a^2*x^2)]*x^3)/(2*Sqrt[1 - a^2*x^2]) - (4*Sqrt[c - c/(a^2*x^2)]*x*Log[1 - a*x])/(a*Sqrt[1 - a^2*x^2])}
{E^(3*ArcTanh[a*x])*Sqrt[c - c/(a^2*x^2)], x, 4, -((a*Sqrt[c - c/(a^2*x^2)]*x^2)/Sqrt[1 - a^2*x^2]) + (Sqrt[c - c/(a^2*x^2)]*x*Log[x])/Sqrt[1 - a^2*x^2] - (4*Sqrt[c - c/(a^2*x^2)]*x*Log[1 - a*x])/Sqrt[1 - a^2*x^2]}
{(E^(3*ArcTanh[a*x])*Sqrt[c - c/(a^2*x^2)])/x, x, 4, -(Sqrt[c - c/(a^2*x^2)]/Sqrt[1 - a^2*x^2]) + (3*a*Sqrt[c - c/(a^2*x^2)]*x*Log[x])/Sqrt[1 - a^2*x^2] - (4*a*Sqrt[c - c/(a^2*x^2)]*x*Log[1 - a*x])/Sqrt[1 - a^2*x^2]}
{(E^(3*ArcTanh[a*x])*Sqrt[c - c/(a^2*x^2)])/x^2, x, 4, (-3*a*Sqrt[c - c/(a^2*x^2)])/Sqrt[1 - a^2*x^2] - Sqrt[c - c/(a^2*x^2)]/(2*x*Sqrt[1 - a^2*x^2]) + (4*a^2*Sqrt[c - c/(a^2*x^2)]*x*Log[x])/Sqrt[1 - a^2*x^2] - (4*a^2*Sqrt[c - c/(a^2*x^2)]*x*Log[1 - a*x])/Sqrt[1 - a^2*x^2]}
{(E^(3*ArcTanh[a*x])*Sqrt[c - c/(a^2*x^2)])/x^3, x, 4, (-4*a^2*Sqrt[c - c/(a^2*x^2)])/Sqrt[1 - a^2*x^2] - Sqrt[c - c/(a^2*x^2)]/(3*x^2*Sqrt[1 - a^2*x^2]) - (3*a*Sqrt[c - c/(a^2*x^2)])/(2*x*Sqrt[1 - a^2*x^2]) + (4*a^3*Sqrt[c - c/(a^2*x^2)]*x*Log[x])/Sqrt[1 - a^2*x^2] - (4*a^3*Sqrt[c - c/(a^2*x^2)]*x*Log[1 - a*x])/Sqrt[1 - a^2*x^2]}
{(E^(3*ArcTanh[a*x])*Sqrt[c - c/(a^2*x^2)])/x^4, x, 4, (-4*a^3*Sqrt[c - c/(a^2*x^2)])/Sqrt[1 - a^2*x^2] - Sqrt[c - c/(a^2*x^2)]/(4*x^3*Sqrt[1 - a^2*x^2]) - (a*Sqrt[c - c/(a^2*x^2)])/(x^2*Sqrt[1 - a^2*x^2]) - (2*a^2*Sqrt[c - c/(a^2*x^2)])/(x*Sqrt[1 - a^2*x^2]) + (4*a^4*Sqrt[c - c/(a^2*x^2)]*x*Log[x])/Sqrt[1 - a^2*x^2] - (4*a^4*Sqrt[c - c/(a^2*x^2)]*x*Log[1 - a*x])/Sqrt[1 - a^2*x^2]}
{(E^(3*ArcTanh[a*x])*Sqrt[c - c/(a^2*x^2)])/x^5, x, 4, (-4*a^4*Sqrt[c - c/(a^2*x^2)])/Sqrt[1 - a^2*x^2] - Sqrt[c - c/(a^2*x^2)]/(5*x^4*Sqrt[1 - a^2*x^2]) - (3*a*Sqrt[c - c/(a^2*x^2)])/(4*x^3*Sqrt[1 - a^2*x^2]) - (4*a^2*Sqrt[c - c/(a^2*x^2)])/(3*x^2*Sqrt[1 - a^2*x^2]) - (2*a^3*Sqrt[c - c/(a^2*x^2)])/(x*Sqrt[1 - a^2*x^2]) + (4*a^5*Sqrt[c - c/(a^2*x^2)]*x*Log[x])/Sqrt[1 - a^2*x^2] - (4*a^5*Sqrt[c - c/(a^2*x^2)]*x*Log[1 - a*x])/Sqrt[1 - a^2*x^2]}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(Sqrt[c - c/(a^2*x^2)]*x^m)/E^ArcTanh[a*x], x, 4, (Sqrt[c - c/(a^2*x^2)]*x^(1 + m))/(m*Sqrt[1 - a^2*x^2]) - (a*Sqrt[c - c/(a^2*x^2)]*x^(2 + m))/((1 + m)*Sqrt[1 - a^2*x^2])}

{(Sqrt[c - c/(a^2*x^2)]*x^2)/E^ArcTanh[a*x], x, 4, (Sqrt[c - c/(a^2*x^2)]*x^3)/(2*Sqrt[1 - a^2*x^2]) - (a*Sqrt[c - c/(a^2*x^2)]*x^4)/(3*Sqrt[1 - a^2*x^2])}
{(Sqrt[c - c/(a^2*x^2)]*x)/E^ArcTanh[a*x], x, 4, (Sqrt[c - c/(a^2*x^2)]*x^2)/Sqrt[1 - a^2*x^2] - (a*Sqrt[c - c/(a^2*x^2)]*x^3)/(2*Sqrt[1 - a^2*x^2])}
{Sqrt[c - c/(a^2*x^2)]/E^ArcTanh[a*x], x, 4, -((a*Sqrt[c - c/(a^2*x^2)]*x^2)/Sqrt[1 - a^2*x^2]) + (Sqrt[c - c/(a^2*x^2)]*x*Log[x])/Sqrt[1 - a^2*x^2]}
{Sqrt[c - c/(a^2*x^2)]/(E^ArcTanh[a*x]*x), x, 4, -(Sqrt[c - c/(a^2*x^2)]/Sqrt[1 - a^2*x^2]) - (a*Sqrt[c - c/(a^2*x^2)]*x*Log[x])/Sqrt[1 - a^2*x^2]}
{Sqrt[c - c/(a^2*x^2)]/(E^ArcTanh[a*x]*x^2), x, 4, (a*Sqrt[c - c/(a^2*x^2)])/Sqrt[1 - a^2*x^2] - Sqrt[c - c/(a^2*x^2)]/(2*x*Sqrt[1 - a^2*x^2])}


{(Sqrt[c - c/(a^2*x^2)]*x^3)/E^(2*ArcTanh[a*x]), x, 7, (7*Sqrt[c - c/(a^2*x^2)]*x)/(8*a^3) + (7*Sqrt[c - c/(a^2*x^2)]*x*(1 - a*x))/(24*a^3) + (Sqrt[c - c/(a^2*x^2)]*x*(1 - a*x)^2)/(6*a^3) - (Sqrt[c - c/(a^2*x^2)]*x^2*(1 - a*x)^2)/(4*a^2) + (7*Sqrt[c - c/(a^2*x^2)]*x*ArcSin[a*x])/(8*a^3*Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{(Sqrt[c - c/(a^2*x^2)]*x^2)/E^(2*ArcTanh[a*x]), x, 6, -((Sqrt[c - c/(a^2*x^2)]*x)/a^2) - (Sqrt[c - c/(a^2*x^2)]*x*(1 - a*x))/(3*a^2) - (Sqrt[c - c/(a^2*x^2)]*x*(1 - a*x)^2)/(3*a^2) - (Sqrt[c - c/(a^2*x^2)]*x*ArcSin[a*x])/(a^2*Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{(Sqrt[c - c/(a^2*x^2)]*x)/E^(2*ArcTanh[a*x]), x, 5, (3*Sqrt[c - c/(a^2*x^2)]*x)/(2*a) + (Sqrt[c - c/(a^2*x^2)]*x*(1 - a*x))/(2*a) + (3*Sqrt[c - c/(a^2*x^2)]*x*ArcSin[a*x])/(2*a*Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{Sqrt[c - c/(a^2*x^2)]/E^(2*ArcTanh[a*x]), x, 6, (-Sqrt[c - c/(a^2*x^2)])*x - (2*Sqrt[c - c/(a^2*x^2)]*x*ArcSin[a*x])/(Sqrt[1 - a*x]*Sqrt[1 + a*x]) - (2*Sqrt[c - c/(a^2*x^2)]*x*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{Sqrt[c - c/(a^2*x^2)]/(E^(2*ArcTanh[a*x])*x), x, 7, (-a)*Sqrt[c - c/(a^2*x^2)]*x - Sqrt[c - c/(a^2*x^2)]*(1 - a*x) + (a*Sqrt[c - c/(a^2*x^2)]*x*ArcSin[a*x])/(Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (4*a*Sqrt[c - c/(a^2*x^2)]*x*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{Sqrt[c - c/(a^2*x^2)]/(E^(2*ArcTanh[a*x])*x^2), x, 5, (3/2)*a*Sqrt[c - c/(a^2*x^2)] - (Sqrt[c - c/(a^2*x^2)]*(1 - a*x))/(2*x) - (3*a^2*Sqrt[c - c/(a^2*x^2)]*x*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{Sqrt[c - c/(a^2*x^2)]/(E^(2*ArcTanh[a*x])*x^3), x, 7, (-(5/3))*a^2*Sqrt[c - c/(a^2*x^2)] + (2*a*Sqrt[c - c/(a^2*x^2)])/(3*x) - (Sqrt[c - c/(a^2*x^2)]*(1 - a*x))/(3*x^2) + (2*a^3*Sqrt[c - c/(a^2*x^2)]*x*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{Sqrt[c - c/(a^2*x^2)]/(E^(2*ArcTanh[a*x])*x^4), x, 8, (4/3)*a^3*Sqrt[c - c/(a^2*x^2)] + (5*a*Sqrt[c - c/(a^2*x^2)])/(12*x^2) - (7*a^2*Sqrt[c - c/(a^2*x^2)])/(8*x) - (Sqrt[c - c/(a^2*x^2)]*(1 - a*x))/(4*x^3) - (7*a^4*Sqrt[c - c/(a^2*x^2)]*x*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(4*Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{Sqrt[c - c/(a^2*x^2)]/(E^(2*ArcTanh[a*x])*x^5), x, 9, (-(6/5))*a^4*Sqrt[c - c/(a^2*x^2)] + (3*a*Sqrt[c - c/(a^2*x^2)])/(10*x^3) - (3*a^2*Sqrt[c - c/(a^2*x^2)])/(5*x^2) + (3*a^3*Sqrt[c - c/(a^2*x^2)])/(4*x) - (Sqrt[c - c/(a^2*x^2)]*(1 - a*x))/(5*x^4) + (3*a^5*Sqrt[c - c/(a^2*x^2)]*x*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(2*Sqrt[1 - a*x]*Sqrt[1 + a*x])}


{(Sqrt[c - c/(a^2*x^2)]*x^3)/E^(3*ArcTanh[a*x]), x, 4, (-4*Sqrt[c - c/(a^2*x^2)]*x^2)/(a^2*Sqrt[1 - a^2*x^2]) + (2*Sqrt[c - c/(a^2*x^2)]*x^3)/(a*Sqrt[1 - a^2*x^2]) - (Sqrt[c - c/(a^2*x^2)]*x^4)/Sqrt[1 - a^2*x^2] + (a*Sqrt[c - c/(a^2*x^2)]*x^5)/(4*Sqrt[1 - a^2*x^2]) + (4*Sqrt[c - c/(a^2*x^2)]*x*Log[1 + a*x])/(a^3*Sqrt[1 - a^2*x^2])}
{(Sqrt[c - c/(a^2*x^2)]*x^2)/E^(3*ArcTanh[a*x]), x, 4, (4*Sqrt[c - c/(a^2*x^2)]*x^2)/(a*Sqrt[1 - a^2*x^2]) - (3*Sqrt[c - c/(a^2*x^2)]*x^3)/(2*Sqrt[1 - a^2*x^2]) + (a*Sqrt[c - c/(a^2*x^2)]*x^4)/(3*Sqrt[1 - a^2*x^2]) - (4*Sqrt[c - c/(a^2*x^2)]*x*Log[1 + a*x])/(a^2*Sqrt[1 - a^2*x^2])}
{(Sqrt[c - c/(a^2*x^2)]*x)/E^(3*ArcTanh[a*x]), x, 5, (-3*Sqrt[c - c/(a^2*x^2)]*x^2)/Sqrt[1 - a^2*x^2] + (a*Sqrt[c - c/(a^2*x^2)]*x^3)/(2*Sqrt[1 - a^2*x^2]) + (4*Sqrt[c - c/(a^2*x^2)]*x*Log[1 + a*x])/(a*Sqrt[1 - a^2*x^2])}
{Sqrt[c - c/(a^2*x^2)]/E^(3*ArcTanh[a*x]), x, 4, (a*Sqrt[c - c/(a^2*x^2)]*x^2)/Sqrt[1 - a^2*x^2] + (Sqrt[c - c/(a^2*x^2)]*x*Log[x])/Sqrt[1 - a^2*x^2] - (4*Sqrt[c - c/(a^2*x^2)]*x*Log[1 + a*x])/Sqrt[1 - a^2*x^2]}
{Sqrt[c - c/(a^2*x^2)]/(E^(3*ArcTanh[a*x])*x), x, 4, -(Sqrt[c - c/(a^2*x^2)]/Sqrt[1 - a^2*x^2]) - (3*a*Sqrt[c - c/(a^2*x^2)]*x*Log[x])/Sqrt[1 - a^2*x^2] + (4*a*Sqrt[c - c/(a^2*x^2)]*x*Log[1 + a*x])/Sqrt[1 - a^2*x^2]}
{Sqrt[c - c/(a^2*x^2)]/(E^(3*ArcTanh[a*x])*x^2), x, 4, (3*a*Sqrt[c - c/(a^2*x^2)])/Sqrt[1 - a^2*x^2] - Sqrt[c - c/(a^2*x^2)]/(2*x*Sqrt[1 - a^2*x^2]) + (4*a^2*Sqrt[c - c/(a^2*x^2)]*x*Log[x])/Sqrt[1 - a^2*x^2] - (4*a^2*Sqrt[c - c/(a^2*x^2)]*x*Log[1 + a*x])/Sqrt[1 - a^2*x^2]}
{Sqrt[c - c/(a^2*x^2)]/(E^(3*ArcTanh[a*x])*x^3), x, 4, (-4*a^2*Sqrt[c - c/(a^2*x^2)])/Sqrt[1 - a^2*x^2] - Sqrt[c - c/(a^2*x^2)]/(3*x^2*Sqrt[1 - a^2*x^2]) + (3*a*Sqrt[c - c/(a^2*x^2)])/(2*x*Sqrt[1 - a^2*x^2]) - (4*a^3*Sqrt[c - c/(a^2*x^2)]*x*Log[x])/Sqrt[1 - a^2*x^2] + (4*a^3*Sqrt[c - c/(a^2*x^2)]*x*Log[1 + a*x])/Sqrt[1 - a^2*x^2]}
{Sqrt[c - c/(a^2*x^2)]/(E^(3*ArcTanh[a*x])*x^4), x, 4, (4*a^3*Sqrt[c - c/(a^2*x^2)])/Sqrt[1 - a^2*x^2] - Sqrt[c - c/(a^2*x^2)]/(4*x^3*Sqrt[1 - a^2*x^2]) + (a*Sqrt[c - c/(a^2*x^2)])/(x^2*Sqrt[1 - a^2*x^2]) - (2*a^2*Sqrt[c - c/(a^2*x^2)])/(x*Sqrt[1 - a^2*x^2]) + (4*a^4*Sqrt[c - c/(a^2*x^2)]*x*Log[x])/Sqrt[1 - a^2*x^2] - (4*a^4*Sqrt[c - c/(a^2*x^2)]*x*Log[1 + a*x])/Sqrt[1 - a^2*x^2]}
{Sqrt[c - c/(a^2*x^2)]/(E^(3*ArcTanh[a*x])*x^5), x, 4, (-4*a^4*Sqrt[c - c/(a^2*x^2)])/Sqrt[1 - a^2*x^2] - Sqrt[c - c/(a^2*x^2)]/(5*x^4*Sqrt[1 - a^2*x^2]) + (3*a*Sqrt[c - c/(a^2*x^2)])/(4*x^3*Sqrt[1 - a^2*x^2]) - (4*a^2*Sqrt[c - c/(a^2*x^2)])/(3*x^2*Sqrt[1 - a^2*x^2]) + (2*a^3*Sqrt[c - c/(a^2*x^2)])/(x*Sqrt[1 - a^2*x^2]) - (4*a^5*Sqrt[c - c/(a^2*x^2)]*x*Log[x])/Sqrt[1 - a^2*x^2] + (4*a^5*Sqrt[c - c/(a^2*x^2)]*x*Log[1 + a*x])/Sqrt[1 - a^2*x^2]}


(* ::Subtitle::Closed:: *)
(*Integration problems of the form u Sin[a x] E^(n ArcTanh[a x])*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Sin[a x] E^ArcTanh[a x] (1+a x)^n*)


(* ::Subsubsection::Closed:: *)
(*n/2>0*)


{x*Sin[x]*E^ArcTanh[x]*(1 + x)^(1/2), x, 16, 3*Sqrt[1 - x]*Cos[x] - (1 - x)^(3/2)*Cos[x] - 3*Sqrt[Pi/2]*Cos[1]*FresnelC[Sqrt[2/Pi]*Sqrt[1 - x]] - (3/2)*Sqrt[Pi/2]*Cos[1]*FresnelS[Sqrt[2/Pi]*Sqrt[1 - x]] + 2*Sqrt[2*Pi]*Cos[1]*FresnelS[Sqrt[2/Pi]*Sqrt[1 - x]] + (3/2)*Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[1 - x]]*Sin[1] - 2*Sqrt[2*Pi]*FresnelC[Sqrt[2/Pi]*Sqrt[1 - x]]*Sin[1] - 3*Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[1 - x]]*Sin[1] - (3/2)*Sqrt[1 - x]*Sin[x]}
{Sin[x]*E^ArcTanh[x]*(1 + x)^(1/2), x, 11, Sqrt[1 - x]*Cos[x] - Sqrt[Pi/2]*Cos[1]*FresnelC[Sqrt[2/Pi]*Sqrt[1 - x]] + 2*Sqrt[2*Pi]*Cos[1]*FresnelS[Sqrt[2/Pi]*Sqrt[1 - x]] - 2*Sqrt[2*Pi]*FresnelC[Sqrt[2/Pi]*Sqrt[1 - x]]*Sin[1] - Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[1 - x]]*Sin[1]}

{x*Sin[x]*E^ArcTanh[x]*(1 - x)^(1/2), x, 13, Sqrt[1 + x]*Cos[x] - (1 + x)^(3/2)*Cos[x] - Sqrt[Pi/2]*Cos[1]*FresnelC[Sqrt[2/Pi]*Sqrt[1 + x]] - (3/2)*Sqrt[Pi/2]*Cos[1]*FresnelS[Sqrt[2/Pi]*Sqrt[1 + x]] + (3/2)*Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[1 + x]]*Sin[1] - Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[1 + x]]*Sin[1] + (3/2)*Sqrt[1 + x]*Sin[x]}
{Sin[x]*E^ArcTanh[x]*(1 - x)^(1/2), x, 7, (-Sqrt[1 + x])*Cos[x] + Sqrt[Pi/2]*Cos[1]*FresnelC[Sqrt[2/Pi]*Sqrt[1 + x]] + Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[1 + x]]*Sin[1]}


{x*Sin[x]*E^ArcTanh[x]*(1 + x)^(3/2), x, 22, (17/4)*Sqrt[1 - x]*Cos[x] - 5*(1 - x)^(3/2)*Cos[x] + (1 - x)^(5/2)*Cos[x] + (15/4)*Sqrt[Pi/2]*Cos[1]*FresnelC[Sqrt[2/Pi]*Sqrt[1 - x]] - 4*Sqrt[2*Pi]*Cos[1]*FresnelC[Sqrt[2/Pi]*Sqrt[1 - x]] - (15/2)*Sqrt[Pi/2]*Cos[1]*FresnelS[Sqrt[2/Pi]*Sqrt[1 - x]] + 4*Sqrt[2*Pi]*Cos[1]*FresnelS[Sqrt[2/Pi]*Sqrt[1 - x]] + (15/2)*Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[1 - x]]*Sin[1] - 4*Sqrt[2*Pi]*FresnelC[Sqrt[2/Pi]*Sqrt[1 - x]]*Sin[1] + (15/4)*Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[1 - x]]*Sin[1] - 4*Sqrt[2*Pi]*FresnelS[Sqrt[2/Pi]*Sqrt[1 - x]]*Sin[1] - (15/2)*Sqrt[1 - x]*Sin[x] + (5/2)*(1 - x)^(3/2)*Sin[x]}
{Sin[x]*E^ArcTanh[x]*(1 + x)^(3/2), x, 16, 4*Sqrt[1 - x]*Cos[x] - (1 - x)^(3/2)*Cos[x] - 2*Sqrt[2*Pi]*Cos[1]*FresnelC[Sqrt[2/Pi]*Sqrt[1 - x]] - (3/2)*Sqrt[Pi/2]*Cos[1]*FresnelS[Sqrt[2/Pi]*Sqrt[1 - x]] + 4*Sqrt[2*Pi]*Cos[1]*FresnelS[Sqrt[2/Pi]*Sqrt[1 - x]] + (3/2)*Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[1 - x]]*Sin[1] - 4*Sqrt[2*Pi]*FresnelC[Sqrt[2/Pi]*Sqrt[1 - x]]*Sin[1] - 2*Sqrt[2*Pi]*FresnelS[Sqrt[2/Pi]*Sqrt[1 - x]]*Sin[1] - (3/2)*Sqrt[1 - x]*Sin[x]}

{x*Sin[x]*E^ArcTanh[x]*(1 - x)^(3/2), x, 19, (-(7/4))*Sqrt[1 + x]*Cos[x] - 3*(1 + x)^(3/2)*Cos[x] + (1 + x)^(5/2)*Cos[x] + (7/4)*Sqrt[Pi/2]*Cos[1]*FresnelC[Sqrt[2/Pi]*Sqrt[1 + x]] - (9/2)*Sqrt[Pi/2]*Cos[1]*FresnelS[Sqrt[2/Pi]*Sqrt[1 + x]] + (9/2)*Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[1 + x]]*Sin[1] + (7/4)*Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[1 + x]]*Sin[1] + (9/2)*Sqrt[1 + x]*Sin[x] - (5/2)*(1 + x)^(3/2)*Sin[x]}
{Sin[x]*E^ArcTanh[x]*(1 - x)^(3/2), x, 13, -2*Sqrt[1 + x]*Cos[x] + (1 + x)^(3/2)*Cos[x] + Sqrt[2*Pi]*Cos[1]*FresnelC[Sqrt[2/Pi]*Sqrt[1 + x]] + (3/2)*Sqrt[Pi/2]*Cos[1]*FresnelS[Sqrt[2/Pi]*Sqrt[1 + x]] - (3/2)*Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[1 + x]]*Sin[1] + Sqrt[2*Pi]*FresnelS[Sqrt[2/Pi]*Sqrt[1 + x]]*Sin[1] - (3/2)*Sqrt[1 + x]*Sin[x]}


(* ::Subsubsection::Closed:: *)
(*n/2<0*)


{x*Sin[x]*E^ArcTanh[x]/(1 + x)^(1/2), x, 11, Sqrt[1 - x]*Cos[x] - Sqrt[Pi/2]*Cos[1]*FresnelC[Sqrt[2/Pi]*Sqrt[1 - x]] + Sqrt[2*Pi]*Cos[1]*FresnelS[Sqrt[2/Pi]*Sqrt[1 - x]] - Sqrt[2*Pi]*FresnelC[Sqrt[2/Pi]*Sqrt[1 - x]]*Sin[1] - Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[1 - x]]*Sin[1]}
{Sin[x]*E^ArcTanh[x]/(1 + x)^(1/2), x, 6, Sqrt[2*Pi]*Cos[1]*FresnelS[Sqrt[2/Pi]*Sqrt[1 - x]] - Sqrt[2*Pi]*FresnelC[Sqrt[2/Pi]*Sqrt[1 - x]]*Sin[1]}

(* {x*Sin[x]*E^ArcTanh[x]/(1 - x)^(1/2), x, 0, 0} *)
(* {Sin[x]*E^ArcTanh[x]/(1 - x)^(1/2), x, 0, 0} *)


(* {x*Sin[x]*E^ArcTanh[x]/(1 + x)^(3/2), x, 0, 0} *)
(* {Sin[x]*E^ArcTanh[x]/(1 + x)^(3/2), x, 0, 0} *)

(* {x*Sin[x]*E^ArcTanh[x]/(1 - x)^(3/2), x, 0, 0} *)
(* {Sin[x]*E^ArcTanh[x]/(1 - x)^(3/2), x, 0, 0} *)


(* ::Subtitle::Closed:: *)
(*Integrands of the form u E^(n ArcTanh[a+b x])*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(n ArcTanh[a+b x])*)


(* ::Subsubsection::Closed:: *)
(*n>0 integer*)


{E^ArcTanh[a + b*x]*x^3, x, 6, -(((16 - 39*a + 44*a^2 - 6*a^3)*Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/(24*b^4)) - ((9 - 20*a + 6*a^2)*x*Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/(24*b^3) - ((4 - 3*a)*x^2*Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/(12*b^2) - (x^3*Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/(4*b) + ((3 - 12*a + 12*a^2 - 8*a^3)*ArcSin[a + b*x])/(8*b^4)}
{E^ArcTanh[a + b*x]*x^2, x, 5, -(((1 - 2*a + 2*a^2)*Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/(2*b^3)) - ((1 - 4*a)*Sqrt[1 - a - b*x]*(1 + a + b*x)^(3/2))/(6*b^3) - (x*Sqrt[1 - a - b*x]*(1 + a + b*x)^(3/2))/(3*b^2) + ((1 - 2*a + 2*a^2)*ArcSin[a + b*x])/(2*b^3)}
{E^ArcTanh[a + b*x]*x^1, x, 4, -(((1 - 2*a)*Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/(2*b^2)) - (Sqrt[1 - a - b*x]*(1 + a + b*x)^(3/2))/(2*b^2) + ((1 - 2*a)*ArcSin[a + b*x])/(2*b^2)}
{E^ArcTanh[a + b*x]*x^0, x, 3, -((Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/b) + ArcSin[a + b*x]/b}
{E^ArcTanh[a + b*x]/x^1, x, 4, ArcSin[a + b*x] - (2*(1 + a)*ArcTanh[(Sqrt[1 - a]*Sqrt[1 + a + b*x])/(Sqrt[1 + a]*Sqrt[1 - a - b*x])])/Sqrt[1 - a^2]}
{E^ArcTanh[a + b*x]/x^2, x, 3, -((Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/((1 - a)*x)) - (2*b*ArcTanh[(Sqrt[1 - a]*Sqrt[1 + a + b*x])/(Sqrt[1 + a]*Sqrt[1 - a - b*x])])/((1 - a)*Sqrt[1 - a^2])}
{E^ArcTanh[a + b*x]/x^3, x, 5, -((Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/(2*(1 - a)*x^2)) - ((2 + a)*b*Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/(2*(1 - a)^2*(1 + a)*x) - ((1 + 2*a)*b^2*ArcTanh[(Sqrt[1 - a]*Sqrt[1 + a + b*x])/(Sqrt[1 + a]*Sqrt[1 - a - b*x])])/((1 - a)*(1 - a^2)^(3/2))}
{E^ArcTanh[a + b*x]/x^4, x, 6, -((Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/(3*(1 - a)*x^3)) - ((3 + 2*a)*b*Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/(6*(1 - a)^2*(1 + a)*x^2) - ((4 + a)*(1 + 2*a)*b^2*Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/(6*(1 - a)^3*(1 + a)^2*x) - ((1 + 2*a + 2*a^2)*b^3*ArcTanh[(Sqrt[1 - a]*Sqrt[1 + a + b*x])/(Sqrt[1 + a]*Sqrt[1 - a - b*x])])/((1 - a)*(1 - a^2)^(5/2))}


{E^(2*ArcTanh[a + b*x])*x^4, x, 3, -((2*(1 - a)^3*x)/b^4) - ((1 - a)^2*x^2)/b^3 - (2*(1 - a)*x^3)/(3*b^2) - x^4/(2*b) - x^5/5 - (2*(1 - a)^4*Log[1 - a - b*x])/b^5}
{E^(2*ArcTanh[a + b*x])*x^3, x, 3, -((2*(1 - a)^2*x)/b^3) - ((1 - a)*x^2)/b^2 - (2*x^3)/(3*b) - x^4/4 - (2*(1 - a)^3*Log[1 - a - b*x])/b^4}
{E^(2*ArcTanh[a + b*x])*x^2, x, 3, -((2*(1 - a)*x)/b^2) - x^2/b - x^3/3 - (2*(1 - a)^2*Log[1 - a - b*x])/b^3}
{E^(2*ArcTanh[a + b*x])*x^1, x, 3, -((2*x)/b) - x^2/2 - (2*(1 - a)*Log[1 - a - b*x])/b^2}
{E^(2*ArcTanh[a + b*x])*x^0, x, 3, -x - (2*Log[1 - a - b*x])/b}
{E^(2*ArcTanh[a + b*x])/x^1, x, 3, ((1 + a)*Log[x])/(1 - a) - (2*Log[1 - a - b*x])/(1 - a)}
{E^(2*ArcTanh[a + b*x])/x^2, x, 3, -((1 + a)/((1 - a)*x)) + (2*b*Log[x])/(1 - a)^2 - (2*b*Log[1 - a - b*x])/(1 - a)^2}
{E^(2*ArcTanh[a + b*x])/x^3, x, 3, -((1 + a)/(2*(1 - a)*x^2)) - (2*b)/((1 - a)^2*x) + (2*b^2*Log[x])/(1 - a)^3 - (2*b^2*Log[1 - a - b*x])/(1 - a)^3}
{E^(2*ArcTanh[a + b*x])/x^4, x, 3, -((1 + a)/(3*(1 - a)*x^3)) - b/((1 - a)^2*x^2) - (2*b^2)/((1 - a)^3*x) + (2*b^3*Log[x])/(1 - a)^4 - (2*b^3*Log[1 - a - b*x])/(1 - a)^4}


{E^(3*ArcTanh[a + b*x])*x^3, x, 7, (3*(17 - 44*a + 36*a^2 - 8*a^3)*Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/(8*b^4) + (2*x^3*(1 + a + b*x)^(3/2))/(b*Sqrt[1 - a - b*x]) + ((29 - 54*a + 22*a^2)*Sqrt[1 - a - b*x]*(1 + a + b*x)^(3/2))/(8*b^4) + ((11 - 10*a)*x*Sqrt[1 - a - b*x]*(1 + a + b*x)^(3/2))/(4*b^3) + (9*x^2*Sqrt[1 - a - b*x]*(1 + a + b*x)^(3/2))/(4*b^2) - (3*(17 - 44*a + 36*a^2 - 8*a^3)*ArcSin[a + b*x])/(8*b^4)}
{E^(3*ArcTanh[a + b*x])*x^2, x, 6, ((11 - 18*a + 6*a^2)*Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/(2*b^3) + ((11 - 18*a + 6*a^2)*Sqrt[1 - a - b*x]*(1 + a + b*x)^(3/2))/(6*b^3) + ((1 - a)^2*(1 + a + b*x)^(5/2))/(b^3*Sqrt[1 - a - b*x]) + (Sqrt[1 - a - b*x]*(1 + a + b*x)^(5/2))/(3*b^3) - ((11 - 18*a + 6*a^2)*ArcSin[a + b*x])/(2*b^3)}
{E^(3*ArcTanh[a + b*x])*x^1, x, 5, (3*(3 - 2*a)*Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/(2*b^2) + ((3 - 2*a)*Sqrt[1 - a - b*x]*(1 + a + b*x)^(3/2))/(2*b^2) + ((1 - a)*(1 + a + b*x)^(5/2))/(b^2*Sqrt[1 - a - b*x]) - (3*(3 - 2*a)*ArcSin[a + b*x])/(2*b^2)}
{E^(3*ArcTanh[a + b*x])*x^0, x, 4, (3*Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/b + (2*(1 + a + b*x)^(3/2))/(b*Sqrt[1 - a - b*x]) - (3*ArcSin[a + b*x])/b}
{E^(3*ArcTanh[a + b*x])/x^1, x, 6, (2*Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/(1 - a) + (2*(1 + a + b*x)^(3/2))/((1 - a)*Sqrt[1 - a - b*x]) - ArcSin[a + b*x] - (2*(1 + a)^2*ArcTanh[(Sqrt[1 - a]*Sqrt[1 + a + b*x])/(Sqrt[1 + a]*Sqrt[1 - a - b*x])])/((1 - a)*Sqrt[1 - a^2])}
{E^(3*ArcTanh[a + b*x])/x^2, x, 4, (6*b*Sqrt[1 + a + b*x])/((1 - a)^2*Sqrt[1 - a - b*x]) - (1 + a + b*x)^(3/2)/((1 - a)*x*Sqrt[1 - a - b*x]) - (6*(1 + a)*b*ArcTanh[(Sqrt[1 - a]*Sqrt[1 + a + b*x])/(Sqrt[1 + a]*Sqrt[1 - a - b*x])])/((1 - a)^2*Sqrt[1 - a^2])}
{E^(3*ArcTanh[a + b*x])/x^3, x, 6, ((14 + a)*b^2*Sqrt[1 + a + b*x])/(2*(1 - a)^3*Sqrt[1 - a - b*x]) - ((4 + a)*b*Sqrt[1 + a + b*x])/(2*(1 - a)^2*x*Sqrt[1 - a - b*x]) - (1 + a + b*x)^(3/2)/(2*(1 - a)*x^2*Sqrt[1 - a - b*x]) - (3*(3 + 2*a)*b^2*ArcTanh[(Sqrt[1 - a]*Sqrt[1 + a + b*x])/(Sqrt[1 + a]*Sqrt[1 - a - b*x])])/((1 - a)^3*Sqrt[1 - a^2])}
{E^(3*ArcTanh[a + b*x])/x^4, x, 7, ((52 + 51*a + 2*a^2)*b^3*Sqrt[1 + a + b*x])/(6*(1 - a)^4*(1 + a)*Sqrt[1 - a - b*x]) - ((5 + 2*a)*b*Sqrt[1 + a + b*x])/(6*(1 - a)^2*x^2*Sqrt[1 - a - b*x]) - ((19 + 16*a)*b^2*Sqrt[1 + a + b*x])/(6*(1 - a)^3*(1 + a)*x*Sqrt[1 - a - b*x]) - (1 + a + b*x)^(3/2)/(3*(1 - a)*x^3*Sqrt[1 - a - b*x]) - ((11 + 18*a + 6*a^2)*b^3*ArcTanh[(Sqrt[1 - a]*Sqrt[1 + a + b*x])/(Sqrt[1 + a]*Sqrt[1 - a - b*x])])/((1 - a)^4*(1 + a)*Sqrt[1 - a^2])}


(* ::Subsubsection::Closed:: *)
(*n<0 integer*)


{E^(-ArcTanh[a + b*x])*x^3, x, 6, -(((16 + 39*a + 44*a^2 + 6*a^3)*Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/(24*b^4)) + ((9 + 20*a + 6*a^2)*x*Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/(24*b^3) - ((4 + 3*a)*x^2*Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/(12*b^2) + (x^3*Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/(4*b) - ((3 + 12*a + 12*a^2 + 8*a^3)*ArcSin[a + b*x])/(8*b^4)}
{E^(-ArcTanh[a + b*x])*x^2, x, 5, ((1 + 2*a + 2*a^2)*Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/(2*b^3) + ((1 + 4*a)*(1 - a - b*x)^(3/2)*Sqrt[1 + a + b*x])/(6*b^3) - (x*(1 - a - b*x)^(3/2)*Sqrt[1 + a + b*x])/(3*b^2) + ((1 + 2*a + 2*a^2)*ArcSin[a + b*x])/(2*b^3)}
{E^(-ArcTanh[a + b*x])*x^1, x, 4, -(((1 + 2*a)*Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/(2*b^2)) - ((1 - a - b*x)^(3/2)*Sqrt[1 + a + b*x])/(2*b^2) - ((1 + 2*a)*ArcSin[a + b*x])/(2*b^2)}
{E^(-ArcTanh[a + b*x])*x^0, x, 3, (Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/b + ArcSin[a + b*x]/b}
{E^(-ArcTanh[a + b*x])/x^1, x, 4, -ArcSin[a + b*x] - (2*(1 - a)*ArcTanh[(Sqrt[1 - a]*Sqrt[1 + a + b*x])/(Sqrt[1 + a]*Sqrt[1 - a - b*x])])/Sqrt[1 - a^2]}
{E^(-ArcTanh[a + b*x])/x^2, x, 3, -((Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/((1 + a)*x)) + (2*b*ArcTanh[(Sqrt[1 - a]*Sqrt[1 + a + b*x])/(Sqrt[1 + a]*Sqrt[1 - a - b*x])])/((1 + a)*Sqrt[1 - a^2])}
{E^(-ArcTanh[a + b*x])/x^3, x, 5, -((Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/(2*(1 + a)*x^2)) + ((2 - a)*b*Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/(2*(1 - a)*(1 + a)^2*x) - ((1 - 2*a)*b^2*ArcTanh[(Sqrt[1 - a]*Sqrt[1 + a + b*x])/(Sqrt[1 + a]*Sqrt[1 - a - b*x])])/((1 + a)*(1 - a^2)^(3/2))}
{E^(-ArcTanh[a + b*x])/x^4, x, 6, -((Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/(3*(1 + a)*x^3)) + ((3 - 2*a)*b*Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/(6*(1 - a)*(1 + a)^2*x^2) - ((1 - 2*a)*(4 - a)*b^2*Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/(6*(1 - a)^2*(1 + a)^3*x) + ((1 - 2*a + 2*a^2)*b^3*ArcTanh[(Sqrt[1 - a]*Sqrt[1 + a + b*x])/(Sqrt[1 + a]*Sqrt[1 - a - b*x])])/((1 + a)*(1 - a^2)^(5/2))}


{E^(-2*ArcTanh[a + b*x])*x^4, x, 3, -((2*(1 + a)^3*x)/b^4) + ((1 + a)^2*x^2)/b^3 - (2*(1 + a)*x^3)/(3*b^2) + x^4/(2*b) - x^5/5 + (2*(1 + a)^4*Log[1 + a + b*x])/b^5}
{E^(-2*ArcTanh[a + b*x])*x^3, x, 3, (2*(1 + a)^2*x)/b^3 - ((1 + a)*x^2)/b^2 + (2*x^3)/(3*b) - x^4/4 - (2*(1 + a)^3*Log[1 + a + b*x])/b^4}
{E^(-2*ArcTanh[a + b*x])*x^2, x, 3, -((2*(1 + a)*x)/b^2) + x^2/b - x^3/3 + (2*(1 + a)^2*Log[1 + a + b*x])/b^3}
{E^(-2*ArcTanh[a + b*x])*x^1, x, 3, (2*x)/b - x^2/2 - (2*(1 + a)*Log[1 + a + b*x])/b^2}
{E^(-2*ArcTanh[a + b*x])*x^0, x, 3, -x + (2*Log[1 + a + b*x])/b}
{E^(-2*ArcTanh[a + b*x])/x^1, x, 3, ((1 - a)*Log[x])/(1 + a) - (2*Log[1 + a + b*x])/(1 + a)}
{E^(-2*ArcTanh[a + b*x])/x^2, x, 3, -((1 - a)/((1 + a)*x)) - (2*b*Log[x])/(1 + a)^2 + (2*b*Log[1 + a + b*x])/(1 + a)^2}
{E^(-2*ArcTanh[a + b*x])/x^3, x, 3, -((1 - a)/(2*(1 + a)*x^2)) + (2*b)/((1 + a)^2*x) + (2*b^2*Log[x])/(1 + a)^3 - (2*b^2*Log[1 + a + b*x])/(1 + a)^3}
{E^(-2*ArcTanh[a + b*x])/x^4, x, 3, -((1 - a)/(3*(1 + a)*x^3)) + b/((1 + a)^2*x^2) - (2*b^2)/((1 + a)^3*x) - (2*b^3*Log[x])/(1 + a)^4 + (2*b^3*Log[1 + a + b*x])/(1 + a)^4}


{E^(-3*ArcTanh[a + b*x])*x^3, x, 7, -((2*x^3*(1 - a - b*x)^(3/2))/(b*Sqrt[1 + a + b*x])) + (3*(17 + 44*a + 36*a^2 + 8*a^3)*Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/(8*b^4) + ((29 + 54*a + 22*a^2)*(1 - a - b*x)^(3/2)*Sqrt[1 + a + b*x])/(8*b^4) - ((11 + 10*a)*x*(1 - a - b*x)^(3/2)*Sqrt[1 + a + b*x])/(4*b^3) + (9*x^2*(1 - a - b*x)^(3/2)*Sqrt[1 + a + b*x])/(4*b^2) + (3*(17 + 44*a + 36*a^2 + 8*a^3)*ArcSin[a + b*x])/(8*b^4)}
{E^(-3*ArcTanh[a + b*x])*x^2, x, 6, -(((1 + a)^2*(1 - a - b*x)^(5/2))/(b^3*Sqrt[1 + a + b*x])) - ((11 + 18*a + 6*a^2)*Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/(2*b^3) - ((11 + 18*a + 6*a^2)*(1 - a - b*x)^(3/2)*Sqrt[1 + a + b*x])/(6*b^3) - ((1 - a - b*x)^(5/2)*Sqrt[1 + a + b*x])/(3*b^3) - ((11 + 18*a + 6*a^2)*ArcSin[a + b*x])/(2*b^3)}
{E^(-3*ArcTanh[a + b*x])*x^1, x, 5, ((1 + a)*(1 - a - b*x)^(5/2))/(b^2*Sqrt[1 + a + b*x]) + (3*(3 + 2*a)*Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/(2*b^2) + ((3 + 2*a)*(1 - a - b*x)^(3/2)*Sqrt[1 + a + b*x])/(2*b^2) + (3*(3 + 2*a)*ArcSin[a + b*x])/(2*b^2)}
{E^(-3*ArcTanh[a + b*x])*x^0, x, 4, -((2*(1 - a - b*x)^(3/2))/(b*Sqrt[1 + a + b*x])) - (3*Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/b - (3*ArcSin[a + b*x])/b}
{E^(-3*ArcTanh[a + b*x])/x^1, x, 6, (2*(1 - a - b*x)^(3/2))/((1 + a)*Sqrt[1 + a + b*x]) + (2*Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/(1 + a) + ArcSin[a + b*x] - (2*(1 - a)^2*ArcTanh[(Sqrt[1 - a]*Sqrt[1 + a + b*x])/(Sqrt[1 + a]*Sqrt[1 - a - b*x])])/((1 + a)*Sqrt[1 - a^2])}
{E^(-3*ArcTanh[a + b*x])/x^2, x, 4, -((6*b*Sqrt[1 - a - b*x])/((1 + a)^2*Sqrt[1 + a + b*x])) - (1 - a - b*x)^(3/2)/((1 + a)*x*Sqrt[1 + a + b*x]) + (6*(1 - a)*b*ArcTanh[(Sqrt[1 - a]*Sqrt[1 + a + b*x])/(Sqrt[1 + a]*Sqrt[1 - a - b*x])])/((1 + a)^2*Sqrt[1 - a^2])}
{E^(-3*ArcTanh[a + b*x])/x^3, x, 6, ((14 - a)*b^2*Sqrt[1 - a - b*x])/(2*(1 + a)^3*Sqrt[1 + a + b*x]) + ((4 - a)*b*Sqrt[1 - a - b*x])/(2*(1 + a)^2*x*Sqrt[1 + a + b*x]) - (1 - a - b*x)^(3/2)/(2*(1 + a)*x^2*Sqrt[1 + a + b*x]) - (3*(3 - 2*a)*b^2*ArcTanh[(Sqrt[1 - a]*Sqrt[1 + a + b*x])/(Sqrt[1 + a]*Sqrt[1 - a - b*x])])/((1 + a)^3*Sqrt[1 - a^2])}
{E^(-3*ArcTanh[a + b*x])/x^4, x, 7, -(((52 - 51*a + 2*a^2)*b^3*Sqrt[1 - a - b*x])/(6*(1 - a)*(1 + a)^4*Sqrt[1 + a + b*x])) + ((5 - 2*a)*b*Sqrt[1 - a - b*x])/(6*(1 + a)^2*x^2*Sqrt[1 + a + b*x]) - ((19 - 16*a)*b^2*Sqrt[1 - a - b*x])/(6*(1 - a)*(1 + a)^3*x*Sqrt[1 + a + b*x]) - (1 - a - b*x)^(3/2)/(3*(1 + a)*x^3*Sqrt[1 + a + b*x]) + ((11 - 18*a + 6*a^2)*b^3*ArcTanh[(Sqrt[1 - a]*Sqrt[1 + a + b*x])/(Sqrt[1 + a]*Sqrt[1 - a - b*x])])/((1 - a)*(1 + a)^4*Sqrt[1 - a^2])}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{E^(n*ArcTanh[a + b*x])*x^m, x, 2, (x^(1 + m)*((1 - a - b*x)/(1 - a))^(n/2)*(1 + a + b*x)^(n/2)*AppellF1[1 + m, n/2, -(n/2), 2 + m, (b*x)/(1 - a), -((b*x)/(1 + a))])/((1 - a - b*x)^(n/2)*((1 + a + b*x)/(1 + a))^(n/2)*(1 + m))}

{E^(n*ArcTanh[a + b*x])*x^3, x, 2, ((1/4)*x^4*((1 - a - b*x)/(1 - a))^(n/2)*(1 + a + b*x)^(n/2)*AppellF1[4, n/2, -(n/2), 5, (b*x)/(1 - a), -((b*x)/(1 + a))])/((1 - a - b*x)^(n/2)*((1 + a + b*x)/(1 + a))^(n/2))}
{E^(n*ArcTanh[a + b*x])*x^2, x, 4, ((4*a - n)*(1 - a - b*x)^(1 - n/2)*(1 + a + b*x)^((2 + n)/2))/(6*b^3) - (x*(1 - a - b*x)^(1 - n/2)*(1 + a + b*x)^((2 + n)/2))/(3*b^2) + ((2 + 6*a^2 - 6*a*n + n^2)*(1 + a + b*x)^((2 + n)/2)*Hypergeometric2F1[n/2, (2 + n)/2, (4 + n)/2, (1/2)*(1 + a + b*x)])/(2^(n/2)*(3*b^3*(2 + n)))}
{E^(n*ArcTanh[a + b*x])*x^1, x, 3, -(((1 - a - b*x)^(1 - n/2)*(1 + a + b*x)^((2 + n)/2))/(2*b^2)) - ((2*a - n)*(1 + a + b*x)^((2 + n)/2)*Hypergeometric2F1[n/2, (2 + n)/2, (4 + n)/2, (1/2)*(1 + a + b*x)])/(2^(n/2)*(b^2*(2 + n)))}
{E^(n*ArcTanh[a + b*x])*x^0, x, 2, (2^(1 - n/2)*(1 + a + b*x)^((2 + n)/2)*Hypergeometric2F1[n/2, (2 + n)/2, (4 + n)/2, (1/2)*(1 + a + b*x)])/(b*(2 + n))}
{E^(n*ArcTanh[a + b*x])/x^1, x, 2, -((2^(1 + n/2)*(1 - a - b*x)^(1 - n/2)*AppellF1[1 - n/2, 1, -(n/2), 2 - n/2, (1 - a - b*x)/(1 - a), (1/2)*(1 - a - b*x)])/((1 - a)*(2 - n)))}
{E^(n*ArcTanh[a + b*x])/x^2, x, 2, -((2^(1 + n/2)*b*(1 - a - b*x)^(1 - n/2)*(1 + (1/2)*(-1 + a + b*x))^((1/2)*(-2 + n))*Hypergeometric2F1[2, 1 - n/2, 2 - n/2, -((1 - a - b*x - (2*(1 - a - b*x))/(1 - a))/(1 + a + b*x))])/((1 - a)^2*(2 - n)))}
{E^(n*ArcTanh[a + b*x])/x^3, x, 2, -((2^(1 + n/2)*b^2*(1 - a - b*x)^(1 - n/2)*Defer[AppellF1][1 - n/2, 3, -(n/2), 2 - n/2, -((1 - a - b*x)/(-1 + a)), -((b*(1 - a - b*x))/(-((1 - a)*b) - (1 + a)*b))])/((1 - a)^3*(2 - n)))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(n ArcTanh[a+b x]) (c+d x)^p*)


{E^ArcTanh[1 + b*x]/(2 + b*x), x, 0, ArcSin[1 + b*x]/b}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^ArcTanh[a+b x] / (1-(a+b x)^2)*)


{x^3*E^ArcTanh[a + b*x]/(1 - a^2 - 2*a*b*x - b^2*x^2), x, 5, -((x^2*Sqrt[1 + a + b*x])/(2*b^2*Sqrt[1 - a - b*x])) + ((1 - 4*a)*(2 - a)*Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/(2*b^4) + ((1 - a)*Sqrt[1 + a + b*x]*(2*(1 - a^2) + (1 - 4*a)*b*x))/(2*b^4*Sqrt[1 - a - b*x]) - (3*(1 - 2*a + 2*a^2)*ArcSin[a + b*x])/(2*b^4)}
{x^2*E^ArcTanh[a + b*x]/(1 - a^2 - 2*a*b*x - b^2*x^2), x, 4, ((1 - a)^2*Sqrt[1 + a + b*x])/(b^3*Sqrt[1 - a - b*x]) + (Sqrt[1 - a - b*x]*Sqrt[1 + a + b*x])/b^3 - ((1 - 2*a)*ArcSin[a + b*x])/b^3}
{x^1*E^ArcTanh[a + b*x]/(1 - a^2 - 2*a*b*x - b^2*x^2), x, 3, ((1 - a)*Sqrt[1 + a + b*x])/(b^2*Sqrt[1 - a - b*x]) - ArcSin[a + b*x]/b^2}
{x^0*E^ArcTanh[a + b*x]/(1 - a^2 - 2*a*b*x - b^2*x^2), x, 2, Sqrt[1 + a + b*x]/(b*Sqrt[1 - a - b*x])}
{E^ArcTanh[a + b*x]/(x^1*(1 - a^2 - 2*a*b*x - b^2*x^2)), x, 4, Sqrt[1 + a + b*x]/((1 - a)*Sqrt[1 - a - b*x]) - (2*ArcTanh[(Sqrt[1 - a]*Sqrt[1 + a + b*x])/(Sqrt[1 + a]*Sqrt[1 - a - b*x])])/((1 - a)*Sqrt[1 - a^2])}
{E^ArcTanh[a + b*x]/(x^2*(1 - a^2 - 2*a*b*x - b^2*x^2)), x, 5, ((2 + a)*b*Sqrt[1 + a + b*x])/((1 - a)^2*(1 + a)*Sqrt[1 - a - b*x]) - Sqrt[1 + a + b*x]/((1 - a^2)*x*Sqrt[1 - a - b*x]) - (2*(1 + 2*a)*b*ArcTanh[(Sqrt[1 - a]*Sqrt[1 + a + b*x])/(Sqrt[1 + a]*Sqrt[1 - a - b*x])])/((1 - a)^2*(1 + a)*Sqrt[1 - a^2])}


(* ::Title::Closed:: *)
(*Miscellaneous integrands involving inverse hyperbolic tangents*)


(* Integrands of the form ArcTanh[a+b*x]/Pn where Pn is a polynomial *)
{ArcTanh[x]/(a + b*x), x, 5, (Log[1 + x]*Log[(a + b*x)/(a - b)])/(2*b) - (Log[1 - x]*Log[(a + b*x)/(a + b)])/(2*b) - PolyLog[2, (b*(1 - x))/(a + b)]/(2*b) + PolyLog[2, -((b*(1 + x))/(a - b))]/(2*b)}
{ArcTanh[x]/(a + b*x^2), x, 11, -((Log[1 - x]*Log[(Sqrt[-a] - Sqrt[b]*x)/(Sqrt[-a] - Sqrt[b])])/(4*Sqrt[-a]*Sqrt[b])) + (Log[1 + x]*Log[(Sqrt[-a] - Sqrt[b]*x)/(Sqrt[-a] + Sqrt[b])])/(4*Sqrt[-a]*Sqrt[b]) - (Log[1 + x]*Log[(Sqrt[-a] + Sqrt[b]*x)/(Sqrt[-a] - Sqrt[b])])/(4*Sqrt[-a]*Sqrt[b]) + (Log[1 - x]*Log[(Sqrt[-a] + Sqrt[b]*x)/(Sqrt[-a] + Sqrt[b])])/(4*Sqrt[-a]*Sqrt[b]) - PolyLog[2, -((Sqrt[b]*(1 - x))/(Sqrt[-a] - Sqrt[b]))]/(4*Sqrt[-a]*Sqrt[b]) + PolyLog[2, (Sqrt[b]*(1 - x))/(Sqrt[-a] + Sqrt[b])]/(4*Sqrt[-a]*Sqrt[b]) - PolyLog[2, -((Sqrt[b]*(1 + x))/(Sqrt[-a] - Sqrt[b]))]/(4*Sqrt[-a]*Sqrt[b]) + PolyLog[2, (Sqrt[b]*(1 + x))/(Sqrt[-a] + Sqrt[b])]/(4*Sqrt[-a]*Sqrt[b])}
{ArcTanh[x]/(a + b*x + c*x^2), x, 11, (Log[1 + x]*Log[(b - Sqrt[b^2 - 4*a*c] + 2*c*x)/(b - 2*c - Sqrt[b^2 - 4*a*c])])/(2*Sqrt[b^2 - 4*a*c]) - (Log[1 - x]*Log[(b - Sqrt[b^2 - 4*a*c] + 2*c*x)/(b + 2*c - Sqrt[b^2 - 4*a*c])])/(2*Sqrt[b^2 - 4*a*c]) - (Log[1 + x]*Log[(b + Sqrt[b^2 - 4*a*c] + 2*c*x)/(b - 2*c + Sqrt[b^2 - 4*a*c])])/(2*Sqrt[b^2 - 4*a*c]) + (Log[1 - x]*Log[(b + Sqrt[b^2 - 4*a*c] + 2*c*x)/(b + 2*c + Sqrt[b^2 - 4*a*c])])/(2*Sqrt[b^2 - 4*a*c]) - PolyLog[2, (2*c*(1 - x))/(b + 2*c - Sqrt[b^2 - 4*a*c])]/(2*Sqrt[b^2 - 4*a*c]) + PolyLog[2, (2*c*(1 - x))/(b + 2*c + Sqrt[b^2 - 4*a*c])]/(2*Sqrt[b^2 - 4*a*c]) + PolyLog[2, -((2*c*(1 + x))/(b - 2*c - Sqrt[b^2 - 4*a*c]))]/(2*Sqrt[b^2 - 4*a*c]) - PolyLog[2, -((2*c*(1 + x))/(b - 2*c + Sqrt[b^2 - 4*a*c]))]/(2*Sqrt[b^2 - 4*a*c])}

{ArcTanh[d + e*x]/(a + b*x), x, 5, -((Log[(e*(a + b*x))/(b - b*d + a*e)]*Log[1 - d - e*x])/(2*b)) + (Log[-((e*(a + b*x))/(b + b*d - a*e))]*Log[1 + d + e*x])/(2*b) - PolyLog[2, (b*(1 - d - e*x))/(b - b*d + a*e)]/(2*b) + PolyLog[2, (b*(1 + d + e*x))/(b + b*d - a*e)]/(2*b)}
{ArcTanh[d + e*x]/(a + b*x^2), x, 11, -((Log[-((e*(Sqrt[-a] - Sqrt[b]*x))/(Sqrt[b]*(1 - d) - Sqrt[-a]*e))]*Log[1 - d - e*x])/(4*Sqrt[-a]*Sqrt[b])) + (Log[(e*(Sqrt[-a] + Sqrt[b]*x))/(Sqrt[b]*(1 - d) + Sqrt[-a]*e)]*Log[1 - d - e*x])/(4*Sqrt[-a]*Sqrt[b]) + (Log[(e*(Sqrt[-a] - Sqrt[b]*x))/(Sqrt[b]*(1 + d) + Sqrt[-a]*e)]*Log[1 + d + e*x])/(4*Sqrt[-a]*Sqrt[b]) - (Log[-((e*(Sqrt[-a] + Sqrt[b]*x))/(Sqrt[b]*(1 + d) - Sqrt[-a]*e))]*Log[1 + d + e*x])/(4*Sqrt[-a]*Sqrt[b]) - PolyLog[2, (Sqrt[b]*(1 - d - e*x))/(Sqrt[b]*(1 - d) - Sqrt[-a]*e)]/(4*Sqrt[-a]*Sqrt[b]) + PolyLog[2, (Sqrt[b]*(1 - d - e*x))/(Sqrt[b]*(1 - d) + Sqrt[-a]*e)]/(4*Sqrt[-a]*Sqrt[b]) - PolyLog[2, (Sqrt[b]*(1 + d + e*x))/(Sqrt[b]*(1 + d) - Sqrt[-a]*e)]/(4*Sqrt[-a]*Sqrt[b]) + PolyLog[2, (Sqrt[b]*(1 + d + e*x))/(Sqrt[b]*(1 + d) + Sqrt[-a]*e)]/(4*Sqrt[-a]*Sqrt[b])}
{ArcTanh[d + e*x]/(a + b*x + c*x^2), x, 11, -((Log[(e*(b - Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c - 2*c*d + b*e - Sqrt[b^2 - 4*a*c]*e)]*Log[1 - d - e*x])/(2*Sqrt[b^2 - 4*a*c])) + (Log[(e*(b + Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c*(1 - d) + (b + Sqrt[b^2 - 4*a*c])*e)]*Log[1 - d - e*x])/(2*Sqrt[b^2 - 4*a*c]) + (Log[-((e*(b - Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c*(1 + d) - (b - Sqrt[b^2 - 4*a*c])*e))]*Log[1 + d + e*x])/(2*Sqrt[b^2 - 4*a*c]) - (Log[-((e*(b + Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c*(1 + d) - (b + Sqrt[b^2 - 4*a*c])*e))]*Log[1 + d + e*x])/(2*Sqrt[b^2 - 4*a*c]) - PolyLog[2, (2*c*(1 - d - e*x))/(2*c - 2*c*d + b*e - Sqrt[b^2 - 4*a*c]*e)]/(2*Sqrt[b^2 - 4*a*c]) + PolyLog[2, (2*c*(1 - d - e*x))/(2*c*(1 - d) + (b + Sqrt[b^2 - 4*a*c])*e)]/(2*Sqrt[b^2 - 4*a*c]) + PolyLog[2, (2*c*(1 + d + e*x))/(2*c*(1 + d) - (b - Sqrt[b^2 - 4*a*c])*e)]/(2*Sqrt[b^2 - 4*a*c]) - PolyLog[2, (2*c*(1 + d + e*x))/(2*c*(1 + d) - (b + Sqrt[b^2 - 4*a*c])*e)]/(2*Sqrt[b^2 - 4*a*c])}


{1/((a - a*x^2)*(b - 2*b*ArcTanh[x])), x, 1, -(Log[1 - 2*ArcTanh[x]]/(2*a*b))}


{ArcTanh[b*x]/(1 - x^2), x, 13, (1/4)*Log[-((b*(1 - x))/(1 - b))]*Log[1 - b*x] - (1/4)*Log[(b*(1 + x))/(1 + b)]*Log[1 - b*x] - (1/4)*Log[(b*(1 - x))/(1 + b)]*Log[1 + b*x] + (1/4)*Log[-((b*(1 + x))/(1 - b))]*Log[1 + b*x] + (1/4)*PolyLog[2, (1 - b*x)/(1 - b)] - (1/4)*PolyLog[2, (1 - b*x)/(1 + b)] + (1/4)*PolyLog[2, (1 + b*x)/(1 - b)] - (1/4)*PolyLog[2, (1 + b*x)/(1 + b)]}
{ArcTanh[a+b*x]/(1 - x^2), x, 13, (1/4)*Log[-((b*(1 - x))/(1 - a - b))]*Log[1 - a - b*x] - (1/4)*Log[(b*(1 + x))/(1 - a + b)]*Log[1 - a - b*x] - (1/4)*Log[(b*(1 - x))/(1 + a + b)]*Log[1 + a + b*x] + (1/4)*Log[-((b*(1 + x))/(1 + a - b))]*Log[1 + a + b*x] + (1/4)*PolyLog[2, (1 - a - b*x)/(1 - a - b)] - (1/4)*PolyLog[2, (1 - a - b*x)/(1 - a + b)] + (1/4)*PolyLog[2, (1 + a + b*x)/(1 + a - b)] - (1/4)*PolyLog[2, (1 + a + b*x)/(1 + a + b)]}


(* Integrands of the form ArcTanh[x]/(a+b*x^2)^n where n is a half-integer *)
{ArcTanh[x]/(a + b*x^2)^(3/2), x, 4, (x*ArcTanh[x])/(a*Sqrt[a + b*x^2]) - ArcTanh[Sqrt[a + b*x^2]/Sqrt[a + b]]/(a*Sqrt[a + b])}
{ArcTanh[x]/(a + b*x^2)^(5/2), x, 5, 1/(3*a*(a + b)*Sqrt[a + b*x^2]) + (x*ArcTanh[x])/(3*a*(a + b*x^2)^(3/2)) + (2*x*ArcTanh[x])/(3*a^2*Sqrt[a + b*x^2]) - ((3*a + 2*b)*ArcTanh[Sqrt[a + b*x^2]/Sqrt[a + b]])/(3*a^2*(a + b)^(3/2))}
{ArcTanh[x]/(a + b*x^2)^(7/2), x, 7, 1/(15*a*(a + b)*(a + b*x^2)^(3/2)) + (7*a + 4*b)/(15*a^2*(a + b)^2*Sqrt[a + b*x^2]) + (x*ArcTanh[x])/(5*a*(a + b*x^2)^(5/2)) + (4*x*ArcTanh[x])/(15*a^2*(a + b*x^2)^(3/2)) + (8*x*ArcTanh[x])/(15*a^3*Sqrt[a + b*x^2]) - ((15*a^2 + 20*a*b + 8*b^2)*ArcTanh[Sqrt[a + b*x^2]/Sqrt[a + b]])/(15*a^3*(a + b)^(5/2))}

{ArcTanh[x]*(a - a*x^2)^(1/2), x, 3, (1/2)*Sqrt[a - a*x^2] + (1/2)*x*Sqrt[a - a*x^2]*ArcTanh[x] - (a*Sqrt[1 - x^2]*ArcTan[Sqrt[1 - x]/Sqrt[1 + x]]*ArcTanh[x])/Sqrt[a - a*x^2] - (I*a*Sqrt[1 - x^2]*PolyLog[2, -((I*Sqrt[1 - x])/Sqrt[1 + x])])/(2*Sqrt[a - a*x^2]) + (I*a*Sqrt[1 - x^2]*PolyLog[2, (I*Sqrt[1 - x])/Sqrt[1 + x]])/(2*Sqrt[a - a*x^2])}
{ArcTanh[x]/(a - a*x^2)^(1/2), x, 2, -((2*Sqrt[1 - x^2]*ArcTan[Sqrt[1 - x]/Sqrt[1 + x]]*ArcTanh[x])/Sqrt[a - a*x^2]) - (I*Sqrt[1 - x^2]*PolyLog[2, -((I*Sqrt[1 - x])/Sqrt[1 + x])])/Sqrt[a - a*x^2] + (I*Sqrt[1 - x^2]*PolyLog[2, (I*Sqrt[1 - x])/Sqrt[1 + x]])/Sqrt[a - a*x^2]}
{ArcTanh[x]/(a - a*x^2)^(3/2), x, 1, -(1/(a*Sqrt[a - a*x^2])) + (x*ArcTanh[x])/(a*Sqrt[a - a*x^2])}
{ArcTanh[x]/(a - a*x^2)^(5/2), x, 2, -(1/(9*a*(a - a*x^2)^(3/2))) - 2/(3*a^2*Sqrt[a - a*x^2]) + (x*ArcTanh[x])/(3*a*(a - a*x^2)^(3/2)) + (2*x*ArcTanh[x])/(3*a^2*Sqrt[a - a*x^2])}
{ArcTanh[x]/(a - a*x^2)^(7/2), x, 3, -(1/(25*a*(a - a*x^2)^(5/2))) - 4/(45*a^2*(a - a*x^2)^(3/2)) - 8/(15*a^3*Sqrt[a - a*x^2]) + (x*ArcTanh[x])/(5*a*(a - a*x^2)^(5/2)) + (4*x*ArcTanh[x])/(15*a^2*(a - a*x^2)^(3/2)) + (8*x*ArcTanh[x])/(15*a^3*Sqrt[a - a*x^2])}


{x^3*ArcTanh[a + b*x^4], x, 2, ((a + b*x^4)*ArcTanh[a + b*x^4])/(4*b) + Log[1 - (a + b*x^4)^2]/(8*b)}

{x^(n-1)*ArcTanh[a + b*x^n], x, 2, ((a + b*x^n)*ArcTanh[a + b*x^n])/(b*n) + Log[1 - (a + b*x^n)^2]/(2*b*n)}
