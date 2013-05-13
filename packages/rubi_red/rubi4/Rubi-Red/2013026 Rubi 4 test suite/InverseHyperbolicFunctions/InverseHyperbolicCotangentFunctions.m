(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Inverse Hyperbolic Cotangents*)


(* ::Section::Closed:: *)
(*Integrands of the form u ArcCoth[a x]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcCoth[a x]^n*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{x^5*ArcCoth[a*x], x, 3, x/(6*a^5) + x^3/(18*a^3) + x^5/(30*a) - ArcCoth[a*x]/(6*a^6) + (1/6)*x^6*ArcCoth[a*x]}
{x^4*ArcCoth[a*x], x, 4, x^2/(10*a^3) + x^4/(20*a) + (1/5)*x^5*ArcCoth[a*x] + Log[1 - a^2*x^2]/(10*a^5)}
{x^3*ArcCoth[a*x], x, 2, x/(4*a^3) + x^3/(12*a) - ArcCoth[a*x]/(4*a^4) + (1/4)*x^4*ArcCoth[a*x]}
{x^2*ArcCoth[a*x], x, 3, x^2/(6*a) + (1/3)*x^3*ArcCoth[a*x] + Log[1 - a^2*x^2]/(6*a^3)}
{x*ArcCoth[a*x], x, 1, x/(2*a) - ArcCoth[a*x]/(2*a^2) + (1/2)*x^2*ArcCoth[a*x]}
{ArcCoth[a*x], x, 2, x*ArcCoth[a*x] + Log[1 - a^2*x^2]/(2*a)}
{ArcCoth[a*x]/x, x, 3, (1/2)*PolyLog[2, -(1/(a*x))] - (1/2)*PolyLog[2, 1/(a*x)]}
{ArcCoth[a*x]/x^2, x, 1, -(ArcCoth[a*x]/x) - a*ArcCoth[1 - 2*a^2*x^2]}
{ArcCoth[a*x]/x^3, x, 1, -(a/(2*x)) + (1/2)*a^2*ArcCoth[a*x] - ArcCoth[a*x]/(2*x^2)}
{ArcCoth[a*x]/x^4, x, 2, -(a/(6*x^2)) - ArcCoth[a*x]/(3*x^3) - (1/3)*a^3*ArcCoth[1 - 2*a^2*x^2]}
{ArcCoth[a*x]/x^5, x, 2, -(a/(12*x^3)) - a^3/(4*x) + (1/4)*a^4*ArcCoth[a*x] - ArcCoth[a*x]/(4*x^4)}


{x^5*ArcCoth[a*x]^2, x, 14, (4*x^2)/(45*a^4) + x^4/(60*a^2) + (x*ArcCoth[a*x])/(3*a^5) + (x^3*ArcCoth[a*x])/(9*a^3) + (x^5*ArcCoth[a*x])/(15*a) - ArcCoth[a*x]^2/(6*a^6) + (1/6)*x^6*ArcCoth[a*x]^2 + (23*Log[1 - a^2*x^2])/(90*a^6)}
{x^4*ArcCoth[a*x]^2, x, 9, (3*x)/(10*a^4) + x^3/(30*a^2) - (3*ArcCoth[a*x])/(10*a^5) + (x^2*ArcCoth[a*x])/(5*a^3) + (x^4*ArcCoth[a*x])/(10*a) + ArcCoth[a*x]^2/(5*a^5) + (1/5)*x^5*ArcCoth[a*x]^2 - (2*ArcCoth[a*x]*Log[2/(1 - a*x)])/(5*a^5) - PolyLog[2, -((1 + a*x)/(1 - a*x))]/(5*a^5)}
{x^3*ArcCoth[a*x]^2, x, 9, x^2/(12*a^2) + (x*ArcCoth[a*x])/(2*a^3) + (x^3*ArcCoth[a*x])/(6*a) - ArcCoth[a*x]^2/(4*a^4) + (1/4)*x^4*ArcCoth[a*x]^2 + Log[1 - a^2*x^2]/(3*a^4)}
{x^2*ArcCoth[a*x]^2, x, 6, x/(3*a^2) - ArcCoth[a*x]/(3*a^3) + (x^2*ArcCoth[a*x])/(3*a) + ArcCoth[a*x]^2/(3*a^3) + (1/3)*x^3*ArcCoth[a*x]^2 - (2*ArcCoth[a*x]*Log[2/(1 - a*x)])/(3*a^3) - PolyLog[2, -((1 + a*x)/(1 - a*x))]/(3*a^3)}
{x*ArcCoth[a*x]^2, x, 5, (x*ArcCoth[a*x])/a - ArcCoth[a*x]^2/(2*a^2) + (1/2)*x^2*ArcCoth[a*x]^2 + Log[1 - a^2*x^2]/(2*a^2)}
{ArcCoth[a*x]^2, x, 4, ArcCoth[a*x]^2/a + x*ArcCoth[a*x]^2 - (2*ArcCoth[a*x]*Log[2/(1 - a*x)])/a - PolyLog[2, -((1 + a*x)/(1 - a*x))]/a}
{ArcCoth[a*x]^2/x, x, 6, 2*ArcCoth[a*x]^2*ArcCoth[1 - 2/(1 - a*x)] + ArcCoth[a*x]*PolyLog[2, -((1 - a*x)/(1 + a*x))] - ArcCoth[a*x]*PolyLog[2, (1 - a*x)/(1 + a*x)] + (1/2)*PolyLog[3, -((1 - a*x)/(1 + a*x))] - (1/2)*PolyLog[3, (1 - a*x)/(1 + a*x)]}
{ArcCoth[a*x]^2/x^2, x, 4, a*ArcCoth[a*x]^2 - ArcCoth[a*x]^2/x + 2*a*ArcCoth[a*x]*Log[(2*a*x)/(1 + a*x)] - a*PolyLog[2, 1 - (2*a*x)/(1 + a*x)]}
{ArcCoth[a*x]^2/x^3, x, 4, -((a*ArcCoth[a*x])/x) + (1/2)*a^2*ArcCoth[a*x]^2 - ArcCoth[a*x]^2/(2*x^2) - a^2*ArcCoth[1 - 2*a^2*x^2]}
{ArcCoth[a*x]^2/x^4, x, 6, -(a^2/(3*x)) + (1/3)*a^3*ArcCoth[a*x] - (a*ArcCoth[a*x])/(3*x^2) + (1/3)*a^3*ArcCoth[a*x]^2 - ArcCoth[a*x]^2/(3*x^3) + (2/3)*a^3*ArcCoth[a*x]*Log[(2*a*x)/(1 + a*x)] - (1/3)*a^3*PolyLog[2, 1 - (2*a*x)/(1 + a*x)]}
{ArcCoth[a*x]^2/x^5, x, 7, -(a^2/(12*x^2)) - (a*ArcCoth[a*x])/(6*x^3) - (a^3*ArcCoth[a*x])/(2*x) + (1/4)*a^4*ArcCoth[a*x]^2 - ArcCoth[a*x]^2/(4*x^4) - (2/3)*a^4*ArcCoth[1 - 2*a^2*x^2]}


{x^5*ArcCoth[a*x]^3, x, 24, (19*x)/(60*a^5) + x^3/(60*a^3) - (19*ArcCoth[a*x])/(60*a^6) + (4*x^2*ArcCoth[a*x])/(15*a^4) + (x^4*ArcCoth[a*x])/(20*a^2) + (23*ArcCoth[a*x]^2)/(30*a^6) + (x*ArcCoth[a*x]^2)/(2*a^5) + (x^3*ArcCoth[a*x]^2)/(6*a^3) + (x^5*ArcCoth[a*x]^2)/(10*a) - ArcCoth[a*x]^3/(6*a^6) + (1/6)*x^6*ArcCoth[a*x]^3 - (23*ArcCoth[a*x]*Log[2/(1 - a*x)])/(15*a^6) - (23*PolyLog[2, -((1 + a*x)/(1 - a*x))])/(30*a^6)}
{x^4*ArcCoth[a*x]^3, x, 21, x^2/(20*a^3) + (9*x*ArcCoth[a*x])/(10*a^4) + (x^3*ArcCoth[a*x])/(10*a^2) - (9*ArcCoth[a*x]^2)/(20*a^5) + (3*x^2*ArcCoth[a*x]^2)/(10*a^3) + (3*x^4*ArcCoth[a*x]^2)/(20*a) + ArcCoth[a*x]^3/(5*a^5) + (1/5)*x^5*ArcCoth[a*x]^3 - (3*ArcCoth[a*x]^2*Log[2/(1 - a*x)])/(5*a^5) + Log[1 - a^2*x^2]/(2*a^5) - (3*ArcCoth[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/(5*a^5) + (3*PolyLog[3, 1 - 2/(1 - a*x)])/(10*a^5)}
{x^3*ArcCoth[a*x]^3, x, 14, x/(4*a^3) - ArcCoth[a*x]/(4*a^4) + (x^2*ArcCoth[a*x])/(4*a^2) + ArcCoth[a*x]^2/a^4 + (3*x*ArcCoth[a*x]^2)/(4*a^3) + (x^3*ArcCoth[a*x]^2)/(4*a) - ArcCoth[a*x]^3/(4*a^4) + (1/4)*x^4*ArcCoth[a*x]^3 - (2*ArcCoth[a*x]*Log[2/(1 - a*x)])/a^4 - PolyLog[2, -((1 + a*x)/(1 - a*x))]/a^4}
{x^2*ArcCoth[a*x]^3, x, 11, (x*ArcCoth[a*x])/a^2 - ArcCoth[a*x]^2/(2*a^3) + (x^2*ArcCoth[a*x]^2)/(2*a) + ArcCoth[a*x]^3/(3*a^3) + (1/3)*x^3*ArcCoth[a*x]^3 - (ArcCoth[a*x]^2*Log[2/(1 - a*x)])/a^3 + Log[1 - a^2*x^2]/(2*a^3) - (ArcCoth[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/a^3 + PolyLog[3, 1 - 2/(1 - a*x)]/(2*a^3)}
{x*ArcCoth[a*x]^3, x, 7, (3*ArcCoth[a*x]^2)/(2*a^2) + (3*x*ArcCoth[a*x]^2)/(2*a) - ArcCoth[a*x]^3/(2*a^2) + (1/2)*x^2*ArcCoth[a*x]^3 - (3*ArcCoth[a*x]*Log[2/(1 - a*x)])/a^2 - (3*PolyLog[2, -((1 + a*x)/(1 - a*x))])/(2*a^2)}
{ArcCoth[a*x]^3, x, 5, ArcCoth[a*x]^3/a + x*ArcCoth[a*x]^3 - (3*ArcCoth[a*x]^2*Log[2/(1 - a*x)])/a - (3*ArcCoth[a*x]*PolyLog[2, 1 - 2/(1 - a*x)])/a + (3*PolyLog[3, 1 - 2/(1 - a*x)])/(2*a)}
{ArcCoth[a*x]^3/x, x, 8, 2*ArcCoth[a*x]^3*ArcCoth[1 - 2/(1 - a*x)] + (3/2)*ArcCoth[a*x]^2*PolyLog[2, -((1 - a*x)/(1 + a*x))] - (3/2)*ArcCoth[a*x]^2*PolyLog[2, (1 - a*x)/(1 + a*x)] + (3/2)*ArcCoth[a*x]*PolyLog[3, -((1 - a*x)/(1 + a*x))] - (3/2)*ArcCoth[a*x]*PolyLog[3, (1 - a*x)/(1 + a*x)] + (3/4)*PolyLog[4, -((1 - a*x)/(1 + a*x))] - (3/4)*PolyLog[4, (1 - a*x)/(1 + a*x)]}
{ArcCoth[a*x]^3/x^2, x, 5, a*ArcCoth[a*x]^3 - ArcCoth[a*x]^3/x + 3*a*ArcCoth[a*x]^2*Log[(2*a*x)/(1 + a*x)] - 3*a*ArcCoth[a*x]*PolyLog[2, 1 - (2*a*x)/(1 + a*x)] - (3/2)*a*PolyLog[3, 1 - (2*a*x)/(1 + a*x)]}
{ArcCoth[a*x]^3/x^3, x, 7, (3/2)*a^2*ArcCoth[a*x]^2 - (3*a*ArcCoth[a*x]^2)/(2*x) + (1/2)*a^2*ArcCoth[a*x]^3 - ArcCoth[a*x]^3/(2*x^2) + 3*a^2*ArcCoth[a*x]*Log[(2*a*x)/(1 + a*x)] - (3/2)*a^2*PolyLog[2, 1 - (2*a*x)/(1 + a*x)]}
{ArcCoth[a*x]^3/x^4, x, 10, -((a^2*ArcCoth[a*x])/x) + (1/2)*a^3*ArcCoth[a*x]^2 - (a*ArcCoth[a*x]^2)/(2*x^2) + (1/3)*a^3*ArcCoth[a*x]^3 - ArcCoth[a*x]^3/(3*x^3) - a^3*ArcCoth[1 - 2*a^2*x^2] + a^3*ArcCoth[a*x]^2*Log[(2*a*x)/(1 + a*x)] - a^3*ArcCoth[a*x]*PolyLog[2, 1 - (2*a*x)/(1 + a*x)] - (1/2)*a^3*PolyLog[3, 1 - (2*a*x)/(1 + a*x)]}
{ArcCoth[a*x]^3/x^5, x, 14, -(a^3/(4*x)) + (1/4)*a^4*ArcCoth[a*x] - (a^2*ArcCoth[a*x])/(4*x^2) + a^4*ArcCoth[a*x]^2 - (a*ArcCoth[a*x]^2)/(4*x^3) - (3*a^3*ArcCoth[a*x]^2)/(4*x) + (1/4)*a^4*ArcCoth[a*x]^3 - ArcCoth[a*x]^3/(4*x^4) + 2*a^4*ArcCoth[a*x]*Log[(2*a*x)/(1 + a*x)] - a^4*PolyLog[2, 1 - (2*a*x)/(1 + a*x)]}


(* ::Subsubsection:: *)
(*n<0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form ArcCoth[a x]^m (c+d x^2)^n*)


{1/((1 - x^2)*ArcCoth[x]), x, 1, Log[ArcCoth[x]]}
{ArcCoth[x]^n/(1 - x^2), x, 1, ArcCoth[x]^(1 + n)/(1 + n)}
{ArcCoth[x]^2/(1 - x^2)^2, x, 4, x/(4*(1 - x^2)) - ArcCoth[x]/(2*(1 - x^2)) + (x*ArcCoth[x]^2)/(2*(1 - x^2)) + ArcCoth[x]^3/6 + ArcTanh[x]/4}


{ArcCoth[x]/(a + b*x^2)^(3/2), x, 4, (x*ArcCoth[x])/(a*Sqrt[a + b*x^2]) - ArcTanh[Sqrt[a + b*x^2]/Sqrt[a + b]]/(a*Sqrt[a + b])}
{ArcCoth[x]/(a + b*x^2)^(5/2), x, 5, 1/(3*a*(a + b)*Sqrt[a + b*x^2]) + (x*ArcCoth[x])/(3*a*(a + b*x^2)^(3/2)) + (2*x*ArcCoth[x])/(3*a^2*Sqrt[a + b*x^2]) - ((3*a + 2*b)*ArcTanh[Sqrt[a + b*x^2]/Sqrt[a + b]])/(3*a^2*(a + b)^(3/2))}
{ArcCoth[x]/(a + b*x^2)^(7/2), x, 7, 1/(15*a*(a + b)*(a + b*x^2)^(3/2)) + (7*a + 4*b)/(15*a^2*(a + b)^2*Sqrt[a + b*x^2]) + (x*ArcCoth[x])/(5*a*(a + b*x^2)^(5/2)) + (4*x*ArcCoth[x])/(15*a^2*(a + b*x^2)^(3/2)) + (8*x*ArcCoth[x])/(15*a^3*Sqrt[a + b*x^2]) - ((15*a^2 + 20*a*b + 8*b^2)*ArcTanh[Sqrt[a + b*x^2]/Sqrt[a + b]])/(15*a^3*(a + b)^(5/2))}

{ArcCoth[x]*(a - a*x^2)^(1/2), x, 3, (1/2)*Sqrt[a - a*x^2] + (1/2)*x*Sqrt[a - a*x^2]*ArcCoth[x] - (a*Sqrt[1 - x^2]*ArcCoth[x]*ArcTan[Sqrt[1 - x]/Sqrt[1 + x]])/Sqrt[a - a*x^2] - (I*a*Sqrt[1 - x^2]*PolyLog[2, -((I*Sqrt[1 - x])/Sqrt[1 + x])])/(2*Sqrt[a - a*x^2]) + (I*a*Sqrt[1 - x^2]*PolyLog[2, (I*Sqrt[1 - x])/Sqrt[1 + x]])/(2*Sqrt[a - a*x^2])}
{ArcCoth[x]/(a - a*x^2)^(1/2), x, 2, -((2*Sqrt[1 - x^2]*ArcCoth[x]*ArcTan[Sqrt[1 - x]/Sqrt[1 + x]])/Sqrt[a - a*x^2]) - (I*Sqrt[1 - x^2]*PolyLog[2, -((I*Sqrt[1 - x])/Sqrt[1 + x])])/Sqrt[a - a*x^2] + (I*Sqrt[1 - x^2]*PolyLog[2, (I*Sqrt[1 - x])/Sqrt[1 + x]])/Sqrt[a - a*x^2]}
{ArcCoth[x]/(a - a*x^2)^(3/2), x, 1, -(1/(a*Sqrt[a - a*x^2])) + (x*ArcCoth[x])/(a*Sqrt[a - a*x^2])}
{ArcCoth[x]/(a - a*x^2)^(5/2), x, 2, -(1/(9*a*(a - a*x^2)^(3/2))) - 2/(3*a^2*Sqrt[a - a*x^2]) + (x*ArcCoth[x])/(3*a*(a - a*x^2)^(3/2)) + (2*x*ArcCoth[x])/(3*a^2*Sqrt[a - a*x^2])}
{ArcCoth[x]/(a - a*x^2)^(7/2), x, 3, -(1/(25*a*(a - a*x^2)^(5/2))) - 4/(45*a^2*(a - a*x^2)^(3/2)) - 8/(15*a^3*Sqrt[a - a*x^2]) + (x*ArcCoth[x])/(5*a*(a - a*x^2)^(5/2)) + (4*x*ArcCoth[x])/(15*a^2*(a - a*x^2)^(3/2)) + (8*x*ArcCoth[x])/(15*a^3*Sqrt[a - a*x^2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcCoth[a x] (c+d x^2)^n*)


{x^1*ArcCoth[x]/(1 - x^2), x, 3, (-(1/2))*ArcCoth[x]^2 + ArcCoth[x]*Log[2/(1 - x)] + (1/2)*PolyLog[2, -((1 + x)/(1 - x))]}
{x^0*ArcCoth[x]/(1 - x^2), x, 1, ArcCoth[x]^2/2}


{x^1*ArcCoth[x]/(1 - x^2)^2, x, 3, -(x/(4*(1 - x^2))) + ArcCoth[x]/(2*(1 - x^2)) - ArcTanh[x]/4}
{x^0*ArcCoth[x]/(1 - x^2)^2, x, 2, -(1/(4*(1 - x^2))) + (x*ArcCoth[x])/(2*(1 - x^2)) + ArcCoth[x]^2/4}


{x^1*ArcCoth[x]/(1 - x^2)^3, x, 4, -(x/(16*(1 - x^2)^2)) - (3*x)/(32*(1 - x^2)) + ArcCoth[x]/(4*(1 - x^2)^2) - (3*ArcTanh[x])/32}
{x^0*ArcCoth[x]/(1 - x^2)^3, x, 3, -(1/(16*(1 - x^2)^2)) - 3/(16*(1 - x^2)) + (x*ArcCoth[x])/(4*(1 - x^2)^2) + (3*x*ArcCoth[x])/(8*(1 - x^2)) + (3*ArcCoth[x]^2)/16}


(* ::Section::Closed:: *)
(*Integrands of the form u ArcCoth[a+b x]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcCoth[a+b x]^n*)


{x^3*ArcCoth[a + b*x], x, 6, ((1 + 3*a^2)*x)/(4*b^3) - (a*x^2)/(4*b^2) + x^3/(12*b) + (1/4)*x^4*ArcCoth[a + b*x] + ((1 - a)^4*Log[1 - a - b*x])/(8*b^4) - ((1 + a)^4*Log[1 + a + b*x])/(8*b^4)}
{x^2*ArcCoth[a + b*x], x, 6, -((2*a*x)/(3*b^2)) + x^2/(6*b) + (1/3)*x^3*ArcCoth[a + b*x] + ((1 - a)^3*Log[1 - a - b*x])/(6*b^3) + ((1 + a)^3*Log[1 + a + b*x])/(6*b^3)}
{x*ArcCoth[a + b*x], x, 5, x/(2*b) + (1/2)*x^2*ArcCoth[a + b*x] + ((1 - a)^2*Log[1 - a - b*x])/(4*b^2) - ((1 + a)^2*Log[1 + a + b*x])/(4*b^2)}
{ArcCoth[a + b*x], x, 1, ((a + b*x)*ArcCoth[a + b*x])/b + Log[1 - (a + b*x)^2]/(2*b)}
(* Why does the following integral take so many steps!!! *)
{ArcCoth[a + b*x]/x, x, 17, (1/2)*Log[x]*Log[(1 - a - b*x)/(1 - a)] - (1/2)*Log[x]*Log[-((1 - a - b*x)/(a + b*x))] - (1/2)*Log[x]*Log[(1 + a + b*x)/(1 + a)] + (1/2)*Log[x]*Log[(1 + a + b*x)/(a + b*x)] + (1/2)*PolyLog[2, (b*x)/(1 - a)] - (1/2)*PolyLog[2, -((b*x)/(1 + a))]}
{ArcCoth[a + b*x]/x^2, x, 6, -(ArcCoth[a + b*x]/x) + (b*Log[x])/(1 - a^2) - (b*Log[1 - a - b*x])/(2*(1 - a)) - (b*Log[1 + a + b*x])/(2*(1 + a))}
{ArcCoth[a + b*x]/x^3, x, 7, -(b/(2*(1 - a^2)*x)) - ArcCoth[a + b*x]/(2*x^2) + (a*b^2*Log[x])/(1 - a^2)^2 - (b^2*Log[1 - a - b*x])/(4*(1 - a)^2) + (b^2*Log[1 + a + b*x])/(4*(1 + a)^2)}


{x^3*ArcCoth[a + b*x]^2, x, 27, -((a*(a + b*x))/b^4) + (a + b*x)^2/(12*b^4) + (a*ArcCoth[a + b*x])/b^4 + ((a + b*x)*ArcCoth[a + b*x])/(2*b^4) + (3*a^2*(a + b*x)*ArcCoth[a + b*x])/b^4 - (a*(a + b*x)^2*ArcCoth[a + b*x])/b^4 + ((a + b*x)^3*ArcCoth[a + b*x])/(6*b^4) - ArcCoth[a + b*x]^2/(4*b^4) - (a*ArcCoth[a + b*x]^2)/b^4 - (3*a^2*ArcCoth[a + b*x]^2)/(2*b^4) - (a^3*ArcCoth[a + b*x]^2)/b^4 - (a^3*(a + b*x)*ArcCoth[a + b*x]^2)/b^4 + (3*a^2*(a + b*x)^2*ArcCoth[a + b*x]^2)/(2*b^4) - (a*(a + b*x)^3*ArcCoth[a + b*x]^2)/b^4 + ((a + b*x)^4*ArcCoth[a + b*x]^2)/(4*b^4) + (2*a*ArcCoth[a + b*x]*Log[2/(1 - a - b*x)])/b^4 + (2*a^3*ArcCoth[a + b*x]*Log[2/(1 - a - b*x)])/b^4 + Log[1 - (a + b*x)^2]/(3*b^4) + (3*a^2*Log[1 - (a + b*x)^2])/(2*b^4) + (a*PolyLog[2, -((1 + a + b*x)/(1 - a - b*x))])/b^4 + (a^3*PolyLog[2, -((1 + a + b*x)/(1 - a - b*x))])/b^4}
{x^2*ArcCoth[a + b*x]^2, x, 18, (a + b*x)/(3*b^3) - ArcCoth[a + b*x]/(3*b^3) - (2*a*(a + b*x)*ArcCoth[a + b*x])/b^3 + ((a + b*x)^2*ArcCoth[a + b*x])/(3*b^3) + ArcCoth[a + b*x]^2/(3*b^3) + (a*ArcCoth[a + b*x]^2)/b^3 + (a^2*ArcCoth[a + b*x]^2)/b^3 + (a^2*(a + b*x)*ArcCoth[a + b*x]^2)/b^3 - (a*(a + b*x)^2*ArcCoth[a + b*x]^2)/b^3 + ((a + b*x)^3*ArcCoth[a + b*x]^2)/(3*b^3) - (2*ArcCoth[a + b*x]*Log[2/(1 - a - b*x)])/(3*b^3) - (2*a^2*ArcCoth[a + b*x]*Log[2/(1 - a - b*x)])/b^3 - (a*Log[1 - (a + b*x)^2])/b^3 - PolyLog[2, -((1 + a + b*x)/(1 - a - b*x))]/(3*b^3) - (a^2*PolyLog[2, -((1 + a + b*x)/(1 - a - b*x))])/b^3}
{x*ArcCoth[a + b*x]^2, x, 12, ((a + b*x)*ArcCoth[a + b*x])/b^2 - ArcCoth[a + b*x]^2/(2*b^2) - (a*ArcCoth[a + b*x]^2)/b^2 - (a*(a + b*x)*ArcCoth[a + b*x]^2)/b^2 + ((a + b*x)^2*ArcCoth[a + b*x]^2)/(2*b^2) + (2*a*ArcCoth[a + b*x]*Log[2/(1 - a - b*x)])/b^2 + Log[1 - (a + b*x)^2]/(2*b^2) + (a*PolyLog[2, -((1 + a + b*x)/(1 - a - b*x))])/b^2}
{ArcCoth[a + b*x]^2, x, 5, ArcCoth[a + b*x]^2/b + ((a + b*x)*ArcCoth[a + b*x]^2)/b - (2*ArcCoth[a + b*x]*Log[2/(1 - a - b*x)])/b - PolyLog[2, -((1 + a + b*x)/(1 - a - b*x))]/b}
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


(* ::Subsection::Closed:: *)
(*Integrands of the form (c+d x)^m ArcCoth[a+b x]*)


{(a + b*x)*ArcCoth[a + b*x], x, 2, (a + b*x)/(2*b) - ArcCoth[a + b*x]/(2*b) + ((a + b*x)^2*ArcCoth[a + b*x])/(2*b)}
{(a + b*x)^2*ArcCoth[a + b*x], x, 4, (a + b*x)^2/(6*b) + ((a + b*x)^3*ArcCoth[a + b*x])/(3*b) + Log[1 - (a + b*x)^2]/(6*b)}
{ArcCoth[1 + x]/(2 + 2*x), x, 3, (1/4)*PolyLog[2, -(1/(1 + x))] - (1/4)*PolyLog[2, 1/(1 + x)]}
{ArcCoth[a + b*x]/(a + b*x), x, 3, PolyLog[2, -(1/(a + b*x))]/(2*b) - PolyLog[2, 1/(a + b*x)]/(2*b)}
{ArcCoth[a + b*x]/(a + b*x)^2, x, 2, -(ArcCoth[a + b*x]/(b*(a + b*x))) - ArcCoth[1 - 2*(a + b*x)^2]/b}


{ArcCoth[a + b*x]/((a*d)/b + d*x), x, 3, PolyLog[2, -(1/(a + b*x))]/(2*d) - PolyLog[2, 1/(a + b*x)]/(2*d)}


(* ::Subsection::Closed:: *)
(*Integrands of the form ArcCoth[a+b x] / (c+d x^n)*)


(* {ArcCoth[a + b*x]/(c + d*x^3), x, 51, (Log[(d^(1/3)*(1 - a - b*x))/(b*c^(1/3) + (1 - a)*d^(1/3))]*Log[-c^(1/3) - d^(1/3)*x])/(6*c^(2/3)*d^(1/3)) - (Log[-((d^(1/3)*(1 + a + b*x))/(b*c^(1/3) - (1 + a)*d^(1/3)))]*Log[-c^(1/3) - d^(1/3)*x])/(6*c^(2/3)*d^(1/3)) - ((-1)^(1/3)*Log[-((d^(1/3)*(1 - a - b*x))/((-1)^(1/3)*b*c^(1/3) - (1 - a)*d^(1/3)))]*Log[(-1)^(1/3)*c^(1/3) - d^(1/3)*x])/(6*c^(2/3)*d^(1/3)) + ((-1)^(1/3)*Log[(d^(1/3)*(1 + a + b*x))/((-1)^(1/3)*b*c^(1/3) + (1 + a)*d^(1/3))]*Log[(-1)^(1/3)*c^(1/3) - d^(1/3)*x])/(6*c^(2/3)*d^(1/3)) + ((-1)^(2/3)*Log[(d^(1/3)*(1 - a - b*x))/((-1)^(2/3)*b*c^(1/3) + (1 - a)*d^(1/3))]*Log[(-(-1)^(2/3))*c^(1/3) - d^(1/3)*x])/(6*c^(2/3)*d^(1/3)) - ((-1)^(2/3)*Log[-((d^(1/3)*(1 + a + b*x))/((-1)^(2/3)*b*c^(1/3) - (1 + a)*d^(1/3)))]*Log[(-(-1)^(2/3))*c^(1/3) - d^(1/3)*x])/(6*c^(2/3)*d^(1/3)) - (Log[-c^(1/3) - d^(1/3)*x]*Log[1 - 1/(a + b*x)])/(6*c^(2/3)*d^(1/3)) + ((-1)^(1/3)*Log[(-1)^(1/3)*c^(1/3) - d^(1/3)*x]*Log[1 - 1/(a + b*x)])/(6*c^(2/3)*d^(1/3)) - ((-1)^(2/3)*Log[(-(-1)^(2/3))*c^(1/3) - d^(1/3)*x]*Log[1 - 1/(a + b*x)])/(6*c^(2/3)*d^(1/3)) + (Log[-c^(1/3) - d^(1/3)*x]*Log[1 + 1/(a + b*x)])/(6*c^(2/3)*d^(1/3)) - ((-1)^(1/3)*Log[(-1)^(1/3)*c^(1/3) - d^(1/3)*x]*Log[1 + 1/(a + b*x)])/(6*c^(2/3)*d^(1/3)) + ((-1)^(2/3)*Log[(-(-1)^(2/3))*c^(1/3) - d^(1/3)*x]*Log[1 + 1/(a + b*x)])/(6*c^(2/3)*d^(1/3)) + PolyLog[2, (b*(c^(1/3) + d^(1/3)*x))/(b*c^(1/3) + (1 - a)*d^(1/3))]/(6*c^(2/3)*d^(1/3)) - PolyLog[2, (b*(c^(1/3) + d^(1/3)*x))/(b*c^(1/3) - (1 + a)*d^(1/3))]/(6*c^(2/3)*d^(1/3)) + ((-1)^(2/3)*PolyLog[2, (b*((-1)^(2/3)*c^(1/3) + d^(1/3)*x))/((-1)^(2/3)*b*c^(1/3) + (1 - a)*d^(1/3))])/(6*c^(2/3)*d^(1/3)) - ((-1)^(2/3)*PolyLog[2, (b*((-1)^(2/3)*c^(1/3) + d^(1/3)*x))/((-1)^(2/3)*b*c^(1/3) - (1 + a)*d^(1/3))])/(6*c^(2/3)*d^(1/3)) - ((-1)^(1/3)*PolyLog[2, ((-1)^(1/3)*b*(c^(1/3) + (-1)^(2/3)*d^(1/3)*x))/((-1)^(1/3)*b*c^(1/3) - (1 - a)*d^(1/3))])/(6*c^(2/3)*d^(1/3)) + ((-1)^(1/3)*PolyLog[2, ((-1)^(1/3)*b*(c^(1/3) + (-1)^(2/3)*d^(1/3)*x))/((-1)^(1/3)*b*c^(1/3) + (1 + a)*d^(1/3))])/(6*c^(2/3)*d^(1/3))} *)
{ArcCoth[a + b*x]/(c + d*x^2), x, 35, (Log[-((Sqrt[d]*(1 - a - b*x))/(b*Sqrt[-c] - (1 - a)*Sqrt[d]))]*Log[Sqrt[-c] - Sqrt[d]*x])/(4*Sqrt[-c]*Sqrt[d]) - (Log[(Sqrt[d]*(1 + a + b*x))/(b*Sqrt[-c] + (1 + a)*Sqrt[d])]*Log[Sqrt[-c] - Sqrt[d]*x])/(4*Sqrt[-c]*Sqrt[d]) - (Log[(Sqrt[d]*(1 - a - b*x))/(b*Sqrt[-c] + (1 - a)*Sqrt[d])]*Log[Sqrt[-c] + Sqrt[d]*x])/(4*Sqrt[-c]*Sqrt[d]) + (Log[-((Sqrt[d]*(1 + a + b*x))/(b*Sqrt[-c] - (1 + a)*Sqrt[d]))]*Log[Sqrt[-c] + Sqrt[d]*x])/(4*Sqrt[-c]*Sqrt[d]) - (Log[Sqrt[-c] - Sqrt[d]*x]*Log[1 - 1/(a + b*x)])/(4*Sqrt[-c]*Sqrt[d]) + (Log[Sqrt[-c] + Sqrt[d]*x]*Log[1 - 1/(a + b*x)])/(4*Sqrt[-c]*Sqrt[d]) + (Log[Sqrt[-c] - Sqrt[d]*x]*Log[1 + 1/(a + b*x)])/(4*Sqrt[-c]*Sqrt[d]) - (Log[Sqrt[-c] + Sqrt[d]*x]*Log[1 + 1/(a + b*x)])/(4*Sqrt[-c]*Sqrt[d]) + PolyLog[2, (b*(Sqrt[-c] - Sqrt[d]*x))/(b*Sqrt[-c] - (1 - a)*Sqrt[d])]/(4*Sqrt[-c]*Sqrt[d]) - PolyLog[2, (b*(Sqrt[-c] - Sqrt[d]*x))/(b*Sqrt[-c] + (1 + a)*Sqrt[d])]/(4*Sqrt[-c]*Sqrt[d]) - PolyLog[2, (b*(Sqrt[-c] + Sqrt[d]*x))/(b*Sqrt[-c] + (1 - a)*Sqrt[d])]/(4*Sqrt[-c]*Sqrt[d]) + PolyLog[2, (b*(Sqrt[-c] + Sqrt[d]*x))/(b*Sqrt[-c] - (1 + a)*Sqrt[d])]/(4*Sqrt[-c]*Sqrt[d])}
{ArcCoth[a + b*x]/(c + d*x), x, 17, (Log[(d*(1 - a - b*x))/(b*c + d - a*d)]*Log[c + d*x])/(2*d) - (Log[-((d*(1 + a + b*x))/(b*c - d - a*d))]*Log[c + d*x])/(2*d) - (Log[c + d*x]*Log[1 - 1/(a + b*x)])/(2*d) + (Log[c + d*x]*Log[1 + 1/(a + b*x)])/(2*d) - PolyLog[2, (b*(c + d*x))/(b*c - d - a*d)]/(2*d) + PolyLog[2, (b*(c + d*x))/(b*c + d - a*d)]/(2*d)}
{ArcCoth[a + b*x]/(c + d/x), x, 25, Log[1 - a - b*x]/(2*b*c) + Log[1 + a + b*x]/(2*b*c) - (d*Log[(c*(1 - a - b*x))/(c - a*c + b*d)]*Log[d + c*x])/(2*c^2) + (d*Log[(c*(1 + a + b*x))/(c + a*c - b*d)]*Log[d + c*x])/(2*c^2) - ((a + b*x)*Log[1 - (a + b*x)^(-1)])/(2*b*c) + (d*Log[d + c*x]*Log[1 - (a + b*x)^(-1)])/(2*c^2) + ((a + b*x)*Log[1 + (a + b*x)^(-1)])/(2*b*c) - (d*Log[d + c*x]*Log[1 + (a + b*x)^(-1)])/(2*c^2) + (d*PolyLog[2, -((b*(d + c*x))/(c + a*c - b*d))])/(2*c^2) - (d*PolyLog[2, (b*(d + c*x))/(c - a*c + b*d)])/(2*c^2)}
{ArcCoth[a + b*x]/(c + d/x^2), x, 43, Log[1 - a - b*x]/(2*b*c) + (Sqrt[-d]*Log[Sqrt[-d]/Sqrt[c] - x]*Log[(1 - a - b*x)/(1 - a - (b*Sqrt[-d])/Sqrt[c])])/(4*c^(3/2)) - (Sqrt[-d]*Log[Sqrt[-d]/Sqrt[c] + x]*Log[(1 - a - b*x)/(1 - a + (b*Sqrt[-d])/Sqrt[c])])/(4*c^(3/2)) + Log[1 + a + b*x]/(2*b*c) + (Sqrt[-d]*Log[Sqrt[-d]/Sqrt[c] + x]*Log[(1 + a + b*x)/(1 + a - (b*Sqrt[-d])/Sqrt[c])])/(4*c^(3/2)) - (Sqrt[-d]*Log[Sqrt[-d]/Sqrt[c] - x]*Log[(1 + a + b*x)/(1 + a + (b*Sqrt[-d])/Sqrt[c])])/(4*c^(3/2)) - ((a + b*x)*Log[1 - (a + b*x)^(-1)])/(2*b*c) - (Sqrt[-d]*Log[Sqrt[-d]/Sqrt[c] - x]*Log[1 - (a + b*x)^(-1)])/(4*c^(3/2)) + (Sqrt[-d]*Log[Sqrt[-d]/Sqrt[c] + x]*Log[1 - (a + b*x)^(-1)])/(4*c^(3/2)) + ((a + b*x)*Log[1 + (a + b*x)^(-1)])/(2*b*c) + (Sqrt[-d]*Log[Sqrt[-d]/Sqrt[c] - x]*Log[1 + (a + b*x)^(-1)])/(4*c^(3/2)) - (Sqrt[-d]*Log[Sqrt[-d]/Sqrt[c] + x]*Log[1 + (a + b*x)^(-1)])/(4*c^(3/2)) + (Sqrt[-d]*PolyLog[2, 1 - (1 - a - b*x)/(1 - a - (b*Sqrt[-d])/Sqrt[c])])/(4*c^(3/2)) - (Sqrt[-d]*PolyLog[2, 1 - (1 - a - b*x)/(1 - a + (b*Sqrt[-d])/Sqrt[c])])/(4*c^(3/2)) + (Sqrt[-d]*PolyLog[2, 1 - (1 + a + b*x)/(1 + a - (b*Sqrt[-d])/Sqrt[c])])/(4*c^(3/2)) - (Sqrt[-d]*PolyLog[2, 1 - (1 + a + b*x)/(1 + a + (b*Sqrt[-d])/Sqrt[c])])/(4*c^(3/2))}
(* {ArcCoth[a + b*x]/(c + d/x^3), x, 59, Log[1 - a - b*x]/(2*b*c) + Log[1 + a + b*x]/(2*b*c) - (d^(1/3)*Log[(c^(1/3)*(1 - a - b*x))/((1 - a)*c^(1/3) + b*d^(1/3))]*Log[-d^(1/3) - c^(1/3)*x])/(6*c^(4/3)) + (d^(1/3)*Log[(c^(1/3)*(1 + a + b*x))/((1 + a)*c^(1/3) - b*d^(1/3))]*Log[-d^(1/3) - c^(1/3)*x])/(6*c^(4/3)) + ((-1)^(1/3)*d^(1/3)*Log[(c^(1/3)*(1 - a - b*x))/((1 - a)*c^(1/3) - (-1)^(1/3)*b*d^(1/3))]*Log[(-1)^(1/3)*d^(1/3) - c^(1/3)*x])/(6*c^(4/3)) - ((-1)^(1/3)*d^(1/3)*Log[(c^(1/3)*(1 + a + b*x))/((1 + a)*c^(1/3) + (-1)^(1/3)*b*d^(1/3))]*Log[(-1)^(1/3)*d^(1/3) - c^(1/3)*x])/(6*c^(4/3)) - ((-1)^(2/3)*d^(1/3)*Log[(c^(1/3)*(1 - a - b*x))/((1 - a)*c^(1/3) + (-1)^(2/3)*b*d^(1/3))]*Log[(-(-1)^(2/3))*d^(1/3) - c^(1/3)*x])/(6*c^(4/3)) + ((-1)^(2/3)*d^(1/3)*Log[(c^(1/3)*(1 + a + b*x))/((1 + a)*c^(1/3) - (-1)^(2/3)*b*d^(1/3))]*Log[(-(-1)^(2/3))*d^(1/3) - c^(1/3)*x])/(6*c^(4/3)) - ((a + b*x)*Log[1 - 1/(a + b*x)])/(2*b*c) + (d^(1/3)*Log[-d^(1/3) - c^(1/3)*x]*Log[1 - 1/(a + b*x)])/(6*c^(4/3)) - ((-1)^(1/3)*d^(1/3)*Log[(-1)^(1/3)*d^(1/3) - c^(1/3)*x]*Log[1 - 1/(a + b*x)])/(6*c^(4/3)) + ((-1)^(2/3)*d^(1/3)*Log[(-(-1)^(2/3))*d^(1/3) - c^(1/3)*x]*Log[1 - 1/(a + b*x)])/(6*c^(4/3)) + ((a + b*x)*Log[1 + 1/(a + b*x)])/(2*b*c) - (d^(1/3)*Log[-d^(1/3) - c^(1/3)*x]*Log[1 + 1/(a + b*x)])/(6*c^(4/3)) + ((-1)^(1/3)*d^(1/3)*Log[(-1)^(1/3)*d^(1/3) - c^(1/3)*x]*Log[1 + 1/(a + b*x)])/(6*c^(4/3)) - ((-1)^(2/3)*d^(1/3)*Log[(-(-1)^(2/3))*d^(1/3) - c^(1/3)*x]*Log[1 + 1/(a + b*x)])/(6*c^(4/3)) + (d^(1/3)*PolyLog[2, -((b*(d^(1/3) + c^(1/3)*x))/((1 + a)*c^(1/3) - b*d^(1/3)))])/(6*c^(4/3)) - (d^(1/3)*PolyLog[2, (b*(d^(1/3) + c^(1/3)*x))/((1 - a)*c^(1/3) + b*d^(1/3))])/(6*c^(4/3)) + ((-1)^(2/3)*d^(1/3)*PolyLog[2, -((b*((-1)^(2/3)*d^(1/3) + c^(1/3)*x))/((1 + a)*c^(1/3) - (-1)^(2/3)*b*d^(1/3)))])/(6*c^(4/3)) - ((-1)^(2/3)*d^(1/3)*PolyLog[2, (b*((-1)^(2/3)*d^(1/3) + c^(1/3)*x))/((1 - a)*c^(1/3) + (-1)^(2/3)*b*d^(1/3))])/(6*c^(4/3)) + ((-1)^(1/3)*d^(1/3)*PolyLog[2, -(((-1)^(1/3)*b*(d^(1/3) + (-1)^(2/3)*c^(1/3)*x))/((1 - a)*c^(1/3) - (-1)^(1/3)*b*d^(1/3)))])/(6*c^(4/3)) - ((-1)^(1/3)*d^(1/3)*PolyLog[2, ((-1)^(1/3)*b*(d^(1/3) + (-1)^(2/3)*c^(1/3)*x))/((1 + a)*c^(1/3) + (-1)^(1/3)*b*d^(1/3))])/(6*c^(4/3))} *)


(* {ArcCoth[a + b*x]/(a + b*x^(3/2)), x, 131, ((1 - 1/Sqrt[1 + a^(-1)])*Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-1 - a] - Sqrt[b]*Sqrt[x])/(Sqrt[-1 - a] + a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) + ((1 + 1/Sqrt[1 + a^(-1)])*Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-1 - a] - Sqrt[b]*Sqrt[x])/(Sqrt[-1 - a] + a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) + ((-1)^(2/3)*(1 - 1/Sqrt[1 + a^(-1)])*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-1 - a] - Sqrt[b]*Sqrt[x])/(Sqrt[-1 - a] - (-1)^(1/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) + ((-1)^(2/3)*(1 + 1/Sqrt[1 + a^(-1)])*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-1 - a] - Sqrt[b]*Sqrt[x])/(Sqrt[-1 - a] - (-1)^(1/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) - ((-1)^(1/3)*(1 - 1/Sqrt[1 + a^(-1)])*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-1 - a] - Sqrt[b]*Sqrt[x])/(Sqrt[-1 - a] + (-1)^(2/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) - ((-1)^(1/3)*(1 + 1/Sqrt[1 + a^(-1)])*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-1 - a] - Sqrt[b]*Sqrt[x])/(Sqrt[-1 - a] + (-1)^(2/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) - (Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[1 - a] - Sqrt[b]*Sqrt[x])/(Sqrt[1 - a] + a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) - ((-1)^(2/3)*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[1 - a] - Sqrt[b]*Sqrt[x])/(Sqrt[1 - a] - (-1)^(1/3)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) + ((-1)^(1/3)*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[1 - a] - Sqrt[b]*Sqrt[x])/(Sqrt[1 - a] + (-1)^(2/3)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) - (Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-a] - Sqrt[b]*Sqrt[x])/(Sqrt[-a] + a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) - ((Sqrt[1 - a] - Sqrt[-a])*Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-a] - Sqrt[b]*Sqrt[x])/(Sqrt[-a] + a^(1/3)*b^(1/6))])/(6*Sqrt[-a]*a^(1/3)*b^(2/3)) - ((Sqrt[1 - a] + Sqrt[-a])*a^(2/3)*Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-a] - Sqrt[b]*Sqrt[x])/(Sqrt[-a] + a^(1/3)*b^(1/6))])/(6*(-a)^(3/2)*b^(2/3)) - ((-1)^(2/3)*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-a] - Sqrt[b]*Sqrt[x])/(Sqrt[-a] - (-1)^(1/3)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) - ((-1)^(2/3)*(Sqrt[1 - a] - Sqrt[-a])*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-a] - Sqrt[b]*Sqrt[x])/(Sqrt[-a] - (-1)^(1/3)*a^(1/3)*b^(1/6))])/(6*Sqrt[-a]*a^(1/3)*b^(2/3)) + ((-1)^(2/3)*(Sqrt[1 - a] + Sqrt[-a])*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-a] - Sqrt[b]*Sqrt[x])/(Sqrt[-a] - (-1)^(1/3)*a^(1/3)*b^(1/6))])/(6*Sqrt[-a]*a^(1/3)*b^(2/3)) + ((-1)^(1/3)*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-a] - Sqrt[b]*Sqrt[x])/(Sqrt[-a] + (-1)^(2/3)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) + ((-1)^(1/3)*(Sqrt[1 - a] - Sqrt[-a])*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-a] - Sqrt[b]*Sqrt[x])/(Sqrt[-a] + (-1)^(2/3)*a^(1/3)*b^(1/6))])/(6*Sqrt[-a]*a^(1/3)*b^(2/3)) - ((-1)^(1/3)*(Sqrt[1 - a] + Sqrt[-a])*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-a] - Sqrt[b]*Sqrt[x])/(Sqrt[-a] + (-1)^(2/3)*a^(1/3)*b^(1/6))])/(6*Sqrt[-a]*a^(1/3)*b^(2/3)) + ((1 - 1/Sqrt[1 + a^(-1)])*Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-1 - a] + Sqrt[b]*Sqrt[x])/(Sqrt[-1 - a] - a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) + ((1 + 1/Sqrt[1 + a^(-1)])*Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-1 - a] + Sqrt[b]*Sqrt[x])/(Sqrt[-1 - a] - a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) + ((-1)^(2/3)*(1 - 1/Sqrt[1 + a^(-1)])*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-1 - a] + Sqrt[b]*Sqrt[x])/(Sqrt[-1 - a] + (-1)^(1/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) + ((-1)^(2/3)*(1 + 1/Sqrt[1 + a^(-1)])*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-1 - a] + Sqrt[b]*Sqrt[x])/(Sqrt[-1 - a] + (-1)^(1/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) - ((-1)^(1/3)*(1 - 1/Sqrt[1 + a^(-1)])*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-1 - a] + Sqrt[b]*Sqrt[x])/(Sqrt[-1 - a] - (-1)^(2/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) - ((-1)^(1/3)*(1 + 1/Sqrt[1 + a^(-1)])*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-1 - a] + Sqrt[b]*Sqrt[x])/(Sqrt[-1 - a] - (-1)^(2/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) - (Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[1 - a] + Sqrt[b]*Sqrt[x])/(Sqrt[1 - a] - a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) - ((-1)^(2/3)*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[1 - a] + Sqrt[b]*Sqrt[x])/(Sqrt[1 - a] + (-1)^(1/3)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) + ((-1)^(1/3)*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[1 - a] + Sqrt[b]*Sqrt[x])/(Sqrt[1 - a] - (-1)^(2/3)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) - (Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-a] + Sqrt[b]*Sqrt[x])/(Sqrt[-a] - a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) - ((Sqrt[1 - a] - Sqrt[-a])*Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-a] + Sqrt[b]*Sqrt[x])/(Sqrt[-a] - a^(1/3)*b^(1/6))])/(6*Sqrt[-a]*a^(1/3)*b^(2/3)) - ((Sqrt[1 - a] + Sqrt[-a])*a^(2/3)*Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-a] + Sqrt[b]*Sqrt[x])/(Sqrt[-a] - a^(1/3)*b^(1/6))])/(6*(-a)^(3/2)*b^(2/3)) - ((-1)^(2/3)*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-a] + Sqrt[b]*Sqrt[x])/(Sqrt[-a] + (-1)^(1/3)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) - ((-1)^(2/3)*(Sqrt[1 - a] - Sqrt[-a])*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-a] + Sqrt[b]*Sqrt[x])/(Sqrt[-a] + (-1)^(1/3)*a^(1/3)*b^(1/6))])/(6*Sqrt[-a]*a^(1/3)*b^(2/3)) + ((-1)^(2/3)*(Sqrt[1 - a] + Sqrt[-a])*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-a] + Sqrt[b]*Sqrt[x])/(Sqrt[-a] + (-1)^(1/3)*a^(1/3)*b^(1/6))])/(6*Sqrt[-a]*a^(1/3)*b^(2/3)) + ((-1)^(1/3)*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-a] + Sqrt[b]*Sqrt[x])/(Sqrt[-a] - (-1)^(2/3)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) + ((-1)^(1/3)*(Sqrt[1 - a] - Sqrt[-a])*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-a] + Sqrt[b]*Sqrt[x])/(Sqrt[-a] - (-1)^(2/3)*a^(1/3)*b^(1/6))])/(6*Sqrt[-a]*a^(1/3)*b^(2/3)) - ((-1)^(1/3)*(Sqrt[1 - a] + Sqrt[-a])*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-a] + Sqrt[b]*Sqrt[x])/(Sqrt[-a] - (-1)^(2/3)*a^(1/3)*b^(1/6))])/(6*Sqrt[-a]*a^(1/3)*b^(2/3)) + (Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[1 - (a + b*x)^(-1)])/(3*a^(1/3)*b^(2/3)) + ((-1)^(2/3)*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[1 - (a + b*x)^(-1)])/(3*a^(1/3)*b^(2/3)) - ((-1)^(1/3)*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[1 - (a + b*x)^(-1)])/(3*a^(1/3)*b^(2/3)) - (Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[1 + (a + b*x)^(-1)])/(3*a^(1/3)*b^(2/3)) - ((-1)^(2/3)*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[1 + (a + b*x)^(-1)])/(3*a^(1/3)*b^(2/3)) + ((-1)^(1/3)*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[1 + (a + b*x)^(-1)])/(3*a^(1/3)*b^(2/3)) + ((-1)^(2/3)*(1 - 1/Sqrt[1 + a^(-1)])*PolyLog[2, -((b^(1/6)*((-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]))/(Sqrt[-1 - a] - (-1)^(1/3)*a^(1/3)*b^(1/6)))])/(6*a^(1/3)*b^(2/3)) + ((-1)^(2/3)*(1 + 1/Sqrt[1 + a^(-1)])*PolyLog[2, -((b^(1/6)*((-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]))/(Sqrt[-1 - a] - (-1)^(1/3)*a^(1/3)*b^(1/6)))])/(6*a^(1/3)*b^(2/3)) - ((-1)^(2/3)*PolyLog[2, -((b^(1/6)*((-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]))/(Sqrt[1 - a] - (-1)^(1/3)*a^(1/3)*b^(1/6)))])/(3*a^(1/3)*b^(2/3)) - ((-1)^(2/3)*PolyLog[2, -((b^(1/6)*((-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]))/(Sqrt[-a] - (-1)^(1/3)*a^(1/3)*b^(1/6)))])/(3*a^(1/3)*b^(2/3)) - ((-1)^(2/3)*(Sqrt[1 - a] - Sqrt[-a])*PolyLog[2, -((b^(1/6)*((-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]))/(Sqrt[-a] - (-1)^(1/3)*a^(1/3)*b^(1/6)))])/(6*Sqrt[-a]*a^(1/3)*b^(2/3)) + ((-1)^(2/3)*(Sqrt[1 - a] + Sqrt[-a])*PolyLog[2, -((b^(1/6)*((-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]))/(Sqrt[-a] - (-1)^(1/3)*a^(1/3)*b^(1/6)))])/(6*Sqrt[-a]*a^(1/3)*b^(2/3)) + ((1 - 1/Sqrt[1 + a^(-1)])*PolyLog[2, -((b^(1/6)*(a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-1 - a] - a^(1/3)*b^(1/6)))])/(6*a^(1/3)*b^(2/3)) + ((1 + 1/Sqrt[1 + a^(-1)])*PolyLog[2, -((b^(1/6)*(a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-1 - a] - a^(1/3)*b^(1/6)))])/(6*a^(1/3)*b^(2/3)) - PolyLog[2, -((b^(1/6)*(a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[1 - a] - a^(1/3)*b^(1/6)))]/(3*a^(1/3)*b^(2/3)) - PolyLog[2, -((b^(1/6)*(a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-a] - a^(1/3)*b^(1/6)))]/(3*a^(1/3)*b^(2/3)) - ((Sqrt[1 - a] - Sqrt[-a])*PolyLog[2, -((b^(1/6)*(a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-a] - a^(1/3)*b^(1/6)))])/(6*Sqrt[-a]*a^(1/3)*b^(2/3)) - ((Sqrt[1 - a] + Sqrt[-a])*a^(2/3)*PolyLog[2, -((b^(1/6)*(a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-a] - a^(1/3)*b^(1/6)))])/(6*(-a)^(3/2)*b^(2/3)) + ((1 - 1/Sqrt[1 + a^(-1)])*PolyLog[2, (b^(1/6)*(a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-1 - a] + a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) + ((1 + 1/Sqrt[1 + a^(-1)])*PolyLog[2, (b^(1/6)*(a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-1 - a] + a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) - PolyLog[2, (b^(1/6)*(a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[1 - a] + a^(1/3)*b^(1/6))]/(3*a^(1/3)*b^(2/3)) - PolyLog[2, (b^(1/6)*(a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-a] + a^(1/3)*b^(1/6))]/(3*a^(1/3)*b^(2/3)) - ((Sqrt[1 - a] - Sqrt[-a])*PolyLog[2, (b^(1/6)*(a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-a] + a^(1/3)*b^(1/6))])/(6*Sqrt[-a]*a^(1/3)*b^(2/3)) - ((Sqrt[1 - a] + Sqrt[-a])*a^(2/3)*PolyLog[2, (b^(1/6)*(a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-a] + a^(1/3)*b^(1/6))])/(6*(-a)^(3/2)*b^(2/3)) - ((-1)^(1/3)*(1 - 1/Sqrt[1 + a^(-1)])*PolyLog[2, -((b^(1/6)*((-1)^(2/3)*a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-1 - a] - (-1)^(2/3)*a^(1/3)*b^(1/6)))])/(6*a^(1/3)*b^(2/3)) - ((-1)^(1/3)*(1 + 1/Sqrt[1 + a^(-1)])*PolyLog[2, -((b^(1/6)*((-1)^(2/3)*a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-1 - a] - (-1)^(2/3)*a^(1/3)*b^(1/6)))])/(6*a^(1/3)*b^(2/3)) + ((-1)^(1/3)*PolyLog[2, -((b^(1/6)*((-1)^(2/3)*a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[1 - a] - (-1)^(2/3)*a^(1/3)*b^(1/6)))])/(3*a^(1/3)*b^(2/3)) + ((-1)^(1/3)*PolyLog[2, -((b^(1/6)*((-1)^(2/3)*a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-a] - (-1)^(2/3)*a^(1/3)*b^(1/6)))])/(3*a^(1/3)*b^(2/3)) + ((-1)^(1/3)*(Sqrt[1 - a] - Sqrt[-a])*PolyLog[2, -((b^(1/6)*((-1)^(2/3)*a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-a] - (-1)^(2/3)*a^(1/3)*b^(1/6)))])/(6*Sqrt[-a]*a^(1/3)*b^(2/3)) - ((-1)^(1/3)*(Sqrt[1 - a] + Sqrt[-a])*PolyLog[2, -((b^(1/6)*((-1)^(2/3)*a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-a] - (-1)^(2/3)*a^(1/3)*b^(1/6)))])/(6*Sqrt[-a]*a^(1/3)*b^(2/3)) - ((-1)^(1/3)*(1 - 1/Sqrt[1 + a^(-1)])*PolyLog[2, (b^(1/6)*((-1)^(2/3)*a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-1 - a] + (-1)^(2/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) - ((-1)^(1/3)*(1 + 1/Sqrt[1 + a^(-1)])*PolyLog[2, (b^(1/6)*((-1)^(2/3)*a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-1 - a] + (-1)^(2/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) + ((-1)^(1/3)*PolyLog[2, (b^(1/6)*((-1)^(2/3)*a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[1 - a] + (-1)^(2/3)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) + ((-1)^(1/3)*PolyLog[2, (b^(1/6)*((-1)^(2/3)*a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-a] + (-1)^(2/3)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) + ((-1)^(1/3)*(Sqrt[1 - a] - Sqrt[-a])*PolyLog[2, (b^(1/6)*((-1)^(2/3)*a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-a] + (-1)^(2/3)*a^(1/3)*b^(1/6))])/(6*Sqrt[-a]*a^(1/3)*b^(2/3)) - ((-1)^(1/3)*(Sqrt[1 - a] + Sqrt[-a])*PolyLog[2, (b^(1/6)*((-1)^(2/3)*a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-a] + (-1)^(2/3)*a^(1/3)*b^(1/6))])/(6*Sqrt[-a]*a^(1/3)*b^(2/3)) + ((-1)^(2/3)*(1 - 1/Sqrt[1 + a^(-1)])*PolyLog[2, ((-1)^(1/3)*b^(1/6)*(a^(1/3) + (-1)^(2/3)*b^(1/3)*Sqrt[x]))/(Sqrt[-1 - a] + (-1)^(1/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) + ((-1)^(2/3)*(1 + 1/Sqrt[1 + a^(-1)])*PolyLog[2, ((-1)^(1/3)*b^(1/6)*(a^(1/3) + (-1)^(2/3)*b^(1/3)*Sqrt[x]))/(Sqrt[-1 - a] + (-1)^(1/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) - ((-1)^(2/3)*PolyLog[2, ((-1)^(1/3)*b^(1/6)*(a^(1/3) + (-1)^(2/3)*b^(1/3)*Sqrt[x]))/(Sqrt[1 - a] + (-1)^(1/3)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) - ((-1)^(2/3)*PolyLog[2, ((-1)^(1/3)*b^(1/6)*(a^(1/3) + (-1)^(2/3)*b^(1/3)*Sqrt[x]))/(Sqrt[-a] + (-1)^(1/3)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) - ((-1)^(2/3)*(Sqrt[1 - a] - Sqrt[-a])*PolyLog[2, ((-1)^(1/3)*b^(1/6)*(a^(1/3) + (-1)^(2/3)*b^(1/3)*Sqrt[x]))/(Sqrt[-a] + (-1)^(1/3)*a^(1/3)*b^(1/6))])/(6*Sqrt[-a]*a^(1/3)*b^(2/3)) + ((-1)^(2/3)*(Sqrt[1 - a] + Sqrt[-a])*PolyLog[2, ((-1)^(1/3)*b^(1/6)*(a^(1/3) + (-1)^(2/3)*b^(1/3)*Sqrt[x]))/(Sqrt[-a] + (-1)^(1/3)*a^(1/3)*b^(1/6))])/(6*Sqrt[-a]*a^(1/3)*b^(2/3))} *)
{ArcCoth[a + b*x]/(c + d*Sqrt[x]), x, 59, (2*Sqrt[1 + a]*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[1 + a]])/(Sqrt[b]*d) - (2*Sqrt[1 - a]*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[1 - a]])/(Sqrt[b]*d) + ((1 - 1/Sqrt[1 + a^(-1)])*c*Log[(d*(Sqrt[-1 - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[b]*c + Sqrt[-1 - a]*d)]*Log[c + d*Sqrt[x]])/(2*d^2) + ((1 + 1/Sqrt[1 + a^(-1)])*c*Log[(d*(Sqrt[-1 - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[b]*c + Sqrt[-1 - a]*d)]*Log[c + d*Sqrt[x]])/(2*d^2) - (c*Log[(d*(Sqrt[1 - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[b]*c + Sqrt[1 - a]*d)]*Log[c + d*Sqrt[x]])/d^2 - (c*Log[(d*(Sqrt[-a] - Sqrt[b]*Sqrt[x]))/(Sqrt[b]*c + Sqrt[-a]*d)]*Log[c + d*Sqrt[x]])/d^2 - ((Sqrt[1 - a] - Sqrt[-a])*c*Log[(d*(Sqrt[-a] - Sqrt[b]*Sqrt[x]))/(Sqrt[b]*c + Sqrt[-a]*d)]*Log[c + d*Sqrt[x]])/(2*Sqrt[-a]*d^2) + ((Sqrt[1 - a] + Sqrt[-a])*c*Log[(d*(Sqrt[-a] - Sqrt[b]*Sqrt[x]))/(Sqrt[b]*c + Sqrt[-a]*d)]*Log[c + d*Sqrt[x]])/(2*Sqrt[-a]*d^2) + ((1 - 1/Sqrt[1 + a^(-1)])*c*Log[-((d*(Sqrt[-1 - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[b]*c - Sqrt[-1 - a]*d))]*Log[c + d*Sqrt[x]])/(2*d^2) + ((1 + 1/Sqrt[1 + a^(-1)])*c*Log[-((d*(Sqrt[-1 - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[b]*c - Sqrt[-1 - a]*d))]*Log[c + d*Sqrt[x]])/(2*d^2) - (c*Log[-((d*(Sqrt[1 - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[b]*c - Sqrt[1 - a]*d))]*Log[c + d*Sqrt[x]])/d^2 - (c*Log[-((d*(Sqrt[-a] + Sqrt[b]*Sqrt[x]))/(Sqrt[b]*c - Sqrt[-a]*d))]*Log[c + d*Sqrt[x]])/d^2 - ((Sqrt[1 - a] - Sqrt[-a])*c*Log[-((d*(Sqrt[-a] + Sqrt[b]*Sqrt[x]))/(Sqrt[b]*c - Sqrt[-a]*d))]*Log[c + d*Sqrt[x]])/(2*Sqrt[-a]*d^2) + ((Sqrt[1 - a] + Sqrt[-a])*c*Log[-((d*(Sqrt[-a] + Sqrt[b]*Sqrt[x]))/(Sqrt[b]*c - Sqrt[-a]*d))]*Log[c + d*Sqrt[x]])/(2*Sqrt[-a]*d^2) - (Sqrt[x]*Log[1 - (a + b*x)^(-1)])/d + (c*Log[c + d*Sqrt[x]]*Log[1 - (a + b*x)^(-1)])/d^2 + (Sqrt[x]*Log[1 + (a + b*x)^(-1)])/d - (c*Log[c + d*Sqrt[x]]*Log[1 + (a + b*x)^(-1)])/d^2 + ((1 - 1/Sqrt[1 + a^(-1)])*c*PolyLog[2, (Sqrt[b]*(c + d*Sqrt[x]))/(Sqrt[b]*c - Sqrt[-1 - a]*d)])/(2*d^2) + ((1 + 1/Sqrt[1 + a^(-1)])*c*PolyLog[2, (Sqrt[b]*(c + d*Sqrt[x]))/(Sqrt[b]*c - Sqrt[-1 - a]*d)])/(2*d^2) + ((1 - 1/Sqrt[1 + a^(-1)])*c*PolyLog[2, (Sqrt[b]*(c + d*Sqrt[x]))/(Sqrt[b]*c + Sqrt[-1 - a]*d)])/(2*d^2) + ((1 + 1/Sqrt[1 + a^(-1)])*c*PolyLog[2, (Sqrt[b]*(c + d*Sqrt[x]))/(Sqrt[b]*c + Sqrt[-1 - a]*d)])/(2*d^2) - (c*PolyLog[2, (Sqrt[b]*(c + d*Sqrt[x]))/(Sqrt[b]*c - Sqrt[1 - a]*d)])/d^2 - (c*PolyLog[2, (Sqrt[b]*(c + d*Sqrt[x]))/(Sqrt[b]*c + Sqrt[1 - a]*d)])/d^2 - (c*PolyLog[2, (Sqrt[b]*(c + d*Sqrt[x]))/(Sqrt[b]*c - Sqrt[-a]*d)])/d^2 - ((Sqrt[1 - a] - Sqrt[-a])*c*PolyLog[2, (Sqrt[b]*(c + d*Sqrt[x]))/(Sqrt[b]*c - Sqrt[-a]*d)])/(2*Sqrt[-a]*d^2) + ((Sqrt[1 - a] + Sqrt[-a])*c*PolyLog[2, (Sqrt[b]*(c + d*Sqrt[x]))/(Sqrt[b]*c - Sqrt[-a]*d)])/(2*Sqrt[-a]*d^2) - (c*PolyLog[2, (Sqrt[b]*(c + d*Sqrt[x]))/(Sqrt[b]*c + Sqrt[-a]*d)])/d^2 - ((Sqrt[1 - a] - Sqrt[-a])*c*PolyLog[2, (Sqrt[b]*(c + d*Sqrt[x]))/(Sqrt[b]*c + Sqrt[-a]*d)])/(2*Sqrt[-a]*d^2) + ((Sqrt[1 - a] + Sqrt[-a])*c*PolyLog[2, (Sqrt[b]*(c + d*Sqrt[x]))/(Sqrt[b]*c + Sqrt[-a]*d)])/(2*Sqrt[-a]*d^2)}
{ArcCoth[a + b*x]/(c + d/Sqrt[x]), x, 69, (-2*Sqrt[1 + a]*d*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[1 + a]])/(Sqrt[b]*c^2) + (2*Sqrt[1 - a]*d*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[1 - a]])/(Sqrt[b]*c^2) - ((1 - 1/Sqrt[1 + a^(-1)])*d^2*Log[(c*(Sqrt[-1 - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[-1 - a]*c + Sqrt[b]*d)]*Log[d + c*Sqrt[x]])/(2*c^3) - ((1 + 1/Sqrt[1 + a^(-1)])*d^2*Log[(c*(Sqrt[-1 - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[-1 - a]*c + Sqrt[b]*d)]*Log[d + c*Sqrt[x]])/(2*c^3) + (d^2*Log[(c*(Sqrt[1 - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[1 - a]*c + Sqrt[b]*d)]*Log[d + c*Sqrt[x]])/c^3 + (d^2*Log[(c*(Sqrt[-a] - Sqrt[b]*Sqrt[x]))/(Sqrt[-a]*c + Sqrt[b]*d)]*Log[d + c*Sqrt[x]])/c^3 + ((Sqrt[1 - a] - Sqrt[-a])*d^2*Log[(c*(Sqrt[-a] - Sqrt[b]*Sqrt[x]))/(Sqrt[-a]*c + Sqrt[b]*d)]*Log[d + c*Sqrt[x]])/(2*Sqrt[-a]*c^3) - ((Sqrt[1 - a] + Sqrt[-a])*d^2*Log[(c*(Sqrt[-a] - Sqrt[b]*Sqrt[x]))/(Sqrt[-a]*c + Sqrt[b]*d)]*Log[d + c*Sqrt[x]])/(2*Sqrt[-a]*c^3) - ((1 - 1/Sqrt[1 + a^(-1)])*d^2*Log[(c*(Sqrt[-1 - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[-1 - a]*c - Sqrt[b]*d)]*Log[d + c*Sqrt[x]])/(2*c^3) - ((1 + 1/Sqrt[1 + a^(-1)])*d^2*Log[(c*(Sqrt[-1 - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[-1 - a]*c - Sqrt[b]*d)]*Log[d + c*Sqrt[x]])/(2*c^3) + (d^2*Log[(c*(Sqrt[1 - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[1 - a]*c - Sqrt[b]*d)]*Log[d + c*Sqrt[x]])/c^3 + (d^2*Log[(c*(Sqrt[-a] + Sqrt[b]*Sqrt[x]))/(Sqrt[-a]*c - Sqrt[b]*d)]*Log[d + c*Sqrt[x]])/c^3 + ((Sqrt[1 - a] - Sqrt[-a])*d^2*Log[(c*(Sqrt[-a] + Sqrt[b]*Sqrt[x]))/(Sqrt[-a]*c - Sqrt[b]*d)]*Log[d + c*Sqrt[x]])/(2*Sqrt[-a]*c^3) - ((Sqrt[1 - a] + Sqrt[-a])*d^2*Log[(c*(Sqrt[-a] + Sqrt[b]*Sqrt[x]))/(Sqrt[-a]*c - Sqrt[b]*d)]*Log[d + c*Sqrt[x]])/(2*Sqrt[-a]*c^3) + ((1 - a)*Log[1 - a - b*x])/(2*b*c) + ((1 + a)*Log[1 + a + b*x])/(2*b*c) + (d*Sqrt[x]*Log[1 - (a + b*x)^(-1)])/c^2 - (x*Log[1 - (a + b*x)^(-1)])/(2*c) - (d^2*Log[d + c*Sqrt[x]]*Log[1 - (a + b*x)^(-1)])/c^3 - (d*Sqrt[x]*Log[1 + (a + b*x)^(-1)])/c^2 + (x*Log[1 + (a + b*x)^(-1)])/(2*c) + (d^2*Log[d + c*Sqrt[x]]*Log[1 + (a + b*x)^(-1)])/c^3 - ((1 - 1/Sqrt[1 + a^(-1)])*d^2*PolyLog[2, -((Sqrt[b]*(d + c*Sqrt[x]))/(Sqrt[-1 - a]*c - Sqrt[b]*d))])/(2*c^3) - ((1 + 1/Sqrt[1 + a^(-1)])*d^2*PolyLog[2, -((Sqrt[b]*(d + c*Sqrt[x]))/(Sqrt[-1 - a]*c - Sqrt[b]*d))])/(2*c^3) + (d^2*PolyLog[2, -((Sqrt[b]*(d + c*Sqrt[x]))/(Sqrt[1 - a]*c - Sqrt[b]*d))])/c^3 + (d^2*PolyLog[2, -((Sqrt[b]*(d + c*Sqrt[x]))/(Sqrt[-a]*c - Sqrt[b]*d))])/c^3 + ((Sqrt[1 - a] - Sqrt[-a])*d^2*PolyLog[2, -((Sqrt[b]*(d + c*Sqrt[x]))/(Sqrt[-a]*c - Sqrt[b]*d))])/(2*Sqrt[-a]*c^3) - ((Sqrt[1 - a] + Sqrt[-a])*d^2*PolyLog[2, -((Sqrt[b]*(d + c*Sqrt[x]))/(Sqrt[-a]*c - Sqrt[b]*d))])/(2*Sqrt[-a]*c^3) - ((1 - 1/Sqrt[1 + a^(-1)])*d^2*PolyLog[2, (Sqrt[b]*(d + c*Sqrt[x]))/(Sqrt[-1 - a]*c + Sqrt[b]*d)])/(2*c^3) - ((1 + 1/Sqrt[1 + a^(-1)])*d^2*PolyLog[2, (Sqrt[b]*(d + c*Sqrt[x]))/(Sqrt[-1 - a]*c + Sqrt[b]*d)])/(2*c^3) + (d^2*PolyLog[2, (Sqrt[b]*(d + c*Sqrt[x]))/(Sqrt[1 - a]*c + Sqrt[b]*d)])/c^3 + (d^2*PolyLog[2, (Sqrt[b]*(d + c*Sqrt[x]))/(Sqrt[-a]*c + Sqrt[b]*d)])/c^3 + ((Sqrt[1 - a] - Sqrt[-a])*d^2*PolyLog[2, (Sqrt[b]*(d + c*Sqrt[x]))/(Sqrt[-a]*c + Sqrt[b]*d)])/(2*Sqrt[-a]*c^3) - ((Sqrt[1 - a] + Sqrt[-a])*d^2*PolyLog[2, (Sqrt[b]*(d + c*Sqrt[x]))/(Sqrt[-a]*c + Sqrt[b]*d)])/(2*Sqrt[-a]*c^3)}
(* {ArcCoth[a + b*x]/(a + b/x^(3/2)), x, 145, -((1 - 1/Sqrt[1 + a^(-1)])*b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-1 - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) + b^(5/6))])/(6*a^(5/3)) - ((1 + 1/Sqrt[1 + a^(-1)])*b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-1 - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) + b^(5/6))])/(6*a^(5/3)) - ((-1)^(2/3)*(1 - 1/Sqrt[1 + a^(-1)])*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-1 - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) - (-1)^(1/3)*b^(5/6))])/(6*a^(5/3)) - ((-1)^(2/3)*(1 + 1/Sqrt[1 + a^(-1)])*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-1 - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) - (-1)^(1/3)*b^(5/6))])/(6*a^(5/3)) + ((-1)^(1/3)*(1 - 1/Sqrt[1 + a^(-1)])*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-1 - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) + (-1)^(2/3)*b^(5/6))])/(6*a^(5/3)) + ((-1)^(1/3)*(1 + 1/Sqrt[1 + a^(-1)])*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-1 - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) + (-1)^(2/3)*b^(5/6))])/(6*a^(5/3)) + (b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[1 - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[1 - a]*a^(1/3) + b^(5/6))])/(3*a^(5/3)) + ((-1)^(2/3)*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[1 - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[1 - a]*a^(1/3) - (-1)^(1/3)*b^(5/6))])/(3*a^(5/3)) - ((-1)^(1/3)*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[1 - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[1 - a]*a^(1/3) + (-1)^(2/3)*b^(5/6))])/(3*a^(5/3)) + (b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-a] - Sqrt[b]*Sqrt[x]))/(Sqrt[-a]*a^(1/3) + b^(5/6))])/(3*a^(5/3)) + ((Sqrt[1 - a] - Sqrt[-a])*b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-a] - Sqrt[b]*Sqrt[x]))/(Sqrt[-a]*a^(1/3) + b^(5/6))])/(6*Sqrt[-a]*a^(5/3)) - ((Sqrt[1 - a] + Sqrt[-a])*b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-a] - Sqrt[b]*Sqrt[x]))/(Sqrt[-a]*a^(1/3) + b^(5/6))])/(6*Sqrt[-a]*a^(5/3)) - ((-1)^(1/3)*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-a] - Sqrt[b]*Sqrt[x]))/(Sqrt[-a]*a^(1/3) + (-1)^(2/3)*b^(5/6))])/(3*a^(5/3)) - ((-1)^(1/3)*(Sqrt[1 - a] - Sqrt[-a])*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-a] - Sqrt[b]*Sqrt[x]))/(Sqrt[-a]*a^(1/3) + (-1)^(2/3)*b^(5/6))])/(6*Sqrt[-a]*a^(5/3)) - ((-1)^(1/3)*(Sqrt[1 - a] + Sqrt[-a])*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-a] - Sqrt[b]*Sqrt[x]))/(Sqrt[-a]*a^(1/3) + (-1)^(2/3)*b^(5/6))])/(6*(-a)^(3/2)*a^(2/3)) + ((-1)^(2/3)*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[-((Sqrt[-a]*a^(1/3)*(Sqrt[-a] - Sqrt[b]*Sqrt[x]))/(a^(4/3) + (-1)^(1/3)*Sqrt[-a]*b^(5/6)))])/(3*a^(5/3)) + ((-1)^(2/3)*(Sqrt[1 - a] - Sqrt[-a])*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[-((Sqrt[-a]*a^(1/3)*(Sqrt[-a] - Sqrt[b]*Sqrt[x]))/(a^(4/3) + (-1)^(1/3)*Sqrt[-a]*b^(5/6)))])/(6*Sqrt[-a]*a^(5/3)) + ((-1)^(2/3)*(Sqrt[1 - a] + Sqrt[-a])*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[-((Sqrt[-a]*a^(1/3)*(Sqrt[-a] - Sqrt[b]*Sqrt[x]))/(a^(4/3) + (-1)^(1/3)*Sqrt[-a]*b^(5/6)))])/(6*(-a)^(3/2)*a^(2/3)) - ((1 - 1/Sqrt[1 + a^(-1)])*b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-1 - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) - b^(5/6))])/(6*a^(5/3)) - ((1 + 1/Sqrt[1 + a^(-1)])*b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-1 - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) - b^(5/6))])/(6*a^(5/3)) - ((-1)^(2/3)*(1 - 1/Sqrt[1 + a^(-1)])*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-1 - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) + (-1)^(1/3)*b^(5/6))])/(6*a^(5/3)) - ((-1)^(2/3)*(1 + 1/Sqrt[1 + a^(-1)])*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-1 - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) + (-1)^(1/3)*b^(5/6))])/(6*a^(5/3)) + ((-1)^(1/3)*(1 - 1/Sqrt[1 + a^(-1)])*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-1 - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) - (-1)^(2/3)*b^(5/6))])/(6*a^(5/3)) + ((-1)^(1/3)*(1 + 1/Sqrt[1 + a^(-1)])*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-1 - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) - (-1)^(2/3)*b^(5/6))])/(6*a^(5/3)) + (b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[1 - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[1 - a]*a^(1/3) - b^(5/6))])/(3*a^(5/3)) + ((-1)^(2/3)*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[1 - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[1 - a]*a^(1/3) + (-1)^(1/3)*b^(5/6))])/(3*a^(5/3)) - ((-1)^(1/3)*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[1 - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[1 - a]*a^(1/3) - (-1)^(2/3)*b^(5/6))])/(3*a^(5/3)) + ((-1)^(2/3)*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-a] + Sqrt[b]*Sqrt[x]))/(Sqrt[-a]*a^(1/3) + (-1)^(1/3)*b^(5/6))])/(3*a^(5/3)) + ((-1)^(2/3)*(Sqrt[1 - a] - Sqrt[-a])*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-a] + Sqrt[b]*Sqrt[x]))/(Sqrt[-a]*a^(1/3) + (-1)^(1/3)*b^(5/6))])/(6*Sqrt[-a]*a^(5/3)) + ((-1)^(2/3)*(Sqrt[1 - a] + Sqrt[-a])*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-a] + Sqrt[b]*Sqrt[x]))/(Sqrt[-a]*a^(1/3) + (-1)^(1/3)*b^(5/6))])/(6*(-a)^(3/2)*a^(2/3)) + (b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[-((Sqrt[-a]*a^(1/3)*(Sqrt[-a] + Sqrt[b]*Sqrt[x]))/(a^(4/3) + Sqrt[-a]*b^(5/6)))])/(3*a^(5/3)) + ((Sqrt[1 - a] - Sqrt[-a])*b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[-((Sqrt[-a]*a^(1/3)*(Sqrt[-a] + Sqrt[b]*Sqrt[x]))/(a^(4/3) + Sqrt[-a]*b^(5/6)))])/(6*Sqrt[-a]*a^(5/3)) - ((Sqrt[1 - a] + Sqrt[-a])*b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[-((Sqrt[-a]*a^(1/3)*(Sqrt[-a] + Sqrt[b]*Sqrt[x]))/(a^(4/3) + Sqrt[-a]*b^(5/6)))])/(6*Sqrt[-a]*a^(5/3)) - ((-1)^(1/3)*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[-((Sqrt[-a]*a^(1/3)*(Sqrt[-a] + Sqrt[b]*Sqrt[x]))/(a^(4/3) + (-1)^(2/3)*Sqrt[-a]*b^(5/6)))])/(3*a^(5/3)) - ((-1)^(1/3)*(Sqrt[1 - a] - Sqrt[-a])*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[-((Sqrt[-a]*a^(1/3)*(Sqrt[-a] + Sqrt[b]*Sqrt[x]))/(a^(4/3) + (-1)^(2/3)*Sqrt[-a]*b^(5/6)))])/(6*Sqrt[-a]*a^(5/3)) - ((-1)^(1/3)*(Sqrt[1 - a] + Sqrt[-a])*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[-((Sqrt[-a]*a^(1/3)*(Sqrt[-a] + Sqrt[b]*Sqrt[x]))/(a^(4/3) + (-1)^(2/3)*Sqrt[-a]*b^(5/6)))])/(6*(-a)^(3/2)*a^(2/3)) + ((1 - a)*Log[1 - a - b*x])/(2*a*b) + ((1 + a)*Log[1 + a + b*x])/(2*a*b) - (x*Log[1 - (a + b*x)^(-1)])/(2*a) - (b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[1 - (a + b*x)^(-1)])/(3*a^(5/3)) - ((-1)^(2/3)*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[1 - (a + b*x)^(-1)])/(3*a^(5/3)) + ((-1)^(1/3)*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[1 - (a + b*x)^(-1)])/(3*a^(5/3)) + (x*Log[1 + (a + b*x)^(-1)])/(2*a) + (b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[1 + (a + b*x)^(-1)])/(3*a^(5/3)) + ((-1)^(2/3)*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[1 + (a + b*x)^(-1)])/(3*a^(5/3)) - ((-1)^(1/3)*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[1 + (a + b*x)^(-1)])/(3*a^(5/3)) - ((-1)^(2/3)*(1 - 1/Sqrt[1 + a^(-1)])*b^(2/3)*PolyLog[2, -((Sqrt[b]*((-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) - (-1)^(1/3)*b^(5/6)))])/(6*a^(5/3)) - ((-1)^(2/3)*(1 + 1/Sqrt[1 + a^(-1)])*b^(2/3)*PolyLog[2, -((Sqrt[b]*((-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) - (-1)^(1/3)*b^(5/6)))])/(6*a^(5/3)) + ((-1)^(2/3)*b^(2/3)*PolyLog[2, -((Sqrt[b]*((-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]))/(Sqrt[1 - a]*a^(1/3) - (-1)^(1/3)*b^(5/6)))])/(3*a^(5/3)) + ((-1)^(2/3)*b^(2/3)*PolyLog[2, -((Sqrt[b]*((-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]))/(Sqrt[-a]*a^(1/3) - (-1)^(1/3)*b^(5/6)))])/(3*a^(5/3)) + ((-1)^(2/3)*(Sqrt[1 - a] - Sqrt[-a])*b^(2/3)*PolyLog[2, -((Sqrt[b]*((-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]))/(Sqrt[-a]*a^(1/3) - (-1)^(1/3)*b^(5/6)))])/(6*Sqrt[-a]*a^(5/3)) + ((-1)^(2/3)*(Sqrt[1 - a] + Sqrt[-a])*b^(2/3)*PolyLog[2, -((Sqrt[b]*((-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]))/(Sqrt[-a]*a^(1/3) - (-1)^(1/3)*b^(5/6)))])/(6*(-a)^(3/2)*a^(2/3)) - ((1 - 1/Sqrt[1 + a^(-1)])*b^(2/3)*PolyLog[2, -((Sqrt[b]*(b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) - b^(5/6)))])/(6*a^(5/3)) - ((1 + 1/Sqrt[1 + a^(-1)])*b^(2/3)*PolyLog[2, -((Sqrt[b]*(b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) - b^(5/6)))])/(6*a^(5/3)) + (b^(2/3)*PolyLog[2, -((Sqrt[b]*(b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[1 - a]*a^(1/3) - b^(5/6)))])/(3*a^(5/3)) - ((1 - 1/Sqrt[1 + a^(-1)])*b^(2/3)*PolyLog[2, (Sqrt[b]*(b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) + b^(5/6))])/(6*a^(5/3)) - ((1 + 1/Sqrt[1 + a^(-1)])*b^(2/3)*PolyLog[2, (Sqrt[b]*(b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) + b^(5/6))])/(6*a^(5/3)) + (b^(2/3)*PolyLog[2, (Sqrt[b]*(b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[1 - a]*a^(1/3) + b^(5/6))])/(3*a^(5/3)) + (b^(2/3)*PolyLog[2, (Sqrt[b]*(b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[-a]*a^(1/3) + b^(5/6))])/(3*a^(5/3)) + ((Sqrt[1 - a] - Sqrt[-a])*b^(2/3)*PolyLog[2, (Sqrt[b]*(b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[-a]*a^(1/3) + b^(5/6))])/(6*Sqrt[-a]*a^(5/3)) - ((Sqrt[1 - a] + Sqrt[-a])*b^(2/3)*PolyLog[2, (Sqrt[b]*(b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[-a]*a^(1/3) + b^(5/6))])/(6*Sqrt[-a]*a^(5/3)) + (b^(2/3)*PolyLog[2, (Sqrt[b]*(b^(1/3) + a^(1/3)*Sqrt[x]))/(a^(4/3)/Sqrt[-a] + b^(5/6))])/(3*a^(5/3)) + ((Sqrt[1 - a] - Sqrt[-a])*b^(2/3)*PolyLog[2, (Sqrt[b]*(b^(1/3) + a^(1/3)*Sqrt[x]))/(a^(4/3)/Sqrt[-a] + b^(5/6))])/(6*Sqrt[-a]*a^(5/3)) - ((Sqrt[1 - a] + Sqrt[-a])*b^(2/3)*PolyLog[2, (Sqrt[b]*(b^(1/3) + a^(1/3)*Sqrt[x]))/(a^(4/3)/Sqrt[-a] + b^(5/6))])/(6*Sqrt[-a]*a^(5/3)) + ((-1)^(1/3)*(1 - 1/Sqrt[1 + a^(-1)])*b^(2/3)*PolyLog[2, -((Sqrt[b]*((-1)^(2/3)*b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) - (-1)^(2/3)*b^(5/6)))])/(6*a^(5/3)) + ((-1)^(1/3)*(1 + 1/Sqrt[1 + a^(-1)])*b^(2/3)*PolyLog[2, -((Sqrt[b]*((-1)^(2/3)*b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) - (-1)^(2/3)*b^(5/6)))])/(6*a^(5/3)) - ((-1)^(1/3)*b^(2/3)*PolyLog[2, -((Sqrt[b]*((-1)^(2/3)*b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[1 - a]*a^(1/3) - (-1)^(2/3)*b^(5/6)))])/(3*a^(5/3)) + ((-1)^(1/3)*(1 - 1/Sqrt[1 + a^(-1)])*b^(2/3)*PolyLog[2, (Sqrt[b]*((-1)^(2/3)*b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) + (-1)^(2/3)*b^(5/6))])/(6*a^(5/3)) + ((-1)^(1/3)*(1 + 1/Sqrt[1 + a^(-1)])*b^(2/3)*PolyLog[2, (Sqrt[b]*((-1)^(2/3)*b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) + (-1)^(2/3)*b^(5/6))])/(6*a^(5/3)) - ((-1)^(1/3)*b^(2/3)*PolyLog[2, (Sqrt[b]*((-1)^(2/3)*b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[1 - a]*a^(1/3) + (-1)^(2/3)*b^(5/6))])/(3*a^(5/3)) - ((-1)^(1/3)*b^(2/3)*PolyLog[2, (Sqrt[b]*((-1)^(2/3)*b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[-a]*a^(1/3) + (-1)^(2/3)*b^(5/6))])/(3*a^(5/3)) - ((-1)^(1/3)*(Sqrt[1 - a] - Sqrt[-a])*b^(2/3)*PolyLog[2, (Sqrt[b]*((-1)^(2/3)*b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[-a]*a^(1/3) + (-1)^(2/3)*b^(5/6))])/(6*Sqrt[-a]*a^(5/3)) - ((-1)^(1/3)*(Sqrt[1 - a] + Sqrt[-a])*b^(2/3)*PolyLog[2, (Sqrt[b]*((-1)^(2/3)*b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[-a]*a^(1/3) + (-1)^(2/3)*b^(5/6))])/(6*(-a)^(3/2)*a^(2/3)) - ((-1)^(1/3)*b^(2/3)*PolyLog[2, (Sqrt[b]*((-1)^(2/3)*b^(1/3) + a^(1/3)*Sqrt[x]))/(a^(4/3)/Sqrt[-a] + (-1)^(2/3)*b^(5/6))])/(3*a^(5/3)) - ((-1)^(1/3)*(Sqrt[1 - a] - Sqrt[-a])*b^(2/3)*PolyLog[2, (Sqrt[b]*((-1)^(2/3)*b^(1/3) + a^(1/3)*Sqrt[x]))/(a^(4/3)/Sqrt[-a] + (-1)^(2/3)*b^(5/6))])/(6*Sqrt[-a]*a^(5/3)) - ((-1)^(1/3)*(Sqrt[1 - a] + Sqrt[-a])*b^(2/3)*PolyLog[2, (Sqrt[b]*((-1)^(2/3)*b^(1/3) + a^(1/3)*Sqrt[x]))/(a^(4/3)/Sqrt[-a] + (-1)^(2/3)*b^(5/6))])/(6*(-a)^(3/2)*a^(2/3)) - ((-1)^(2/3)*(1 - 1/Sqrt[1 + a^(-1)])*b^(2/3)*PolyLog[2, ((-1)^(1/3)*Sqrt[b]*(b^(1/3) + (-1)^(2/3)*a^(1/3)*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) + (-1)^(1/3)*b^(5/6))])/(6*a^(5/3)) - ((-1)^(2/3)*(1 + 1/Sqrt[1 + a^(-1)])*b^(2/3)*PolyLog[2, ((-1)^(1/3)*Sqrt[b]*(b^(1/3) + (-1)^(2/3)*a^(1/3)*Sqrt[x]))/(Sqrt[-1 - a]*a^(1/3) + (-1)^(1/3)*b^(5/6))])/(6*a^(5/3)) + ((-1)^(2/3)*b^(2/3)*PolyLog[2, ((-1)^(1/3)*Sqrt[b]*(b^(1/3) + (-1)^(2/3)*a^(1/3)*Sqrt[x]))/(Sqrt[1 - a]*a^(1/3) + (-1)^(1/3)*b^(5/6))])/(3*a^(5/3)) + ((-1)^(2/3)*b^(2/3)*PolyLog[2, ((-1)^(1/3)*Sqrt[b]*(b^(1/3) + (-1)^(2/3)*a^(1/3)*Sqrt[x]))/(Sqrt[-a]*a^(1/3) + (-1)^(1/3)*b^(5/6))])/(3*a^(5/3)) + ((-1)^(2/3)*(Sqrt[1 - a] - Sqrt[-a])*b^(2/3)*PolyLog[2, ((-1)^(1/3)*Sqrt[b]*(b^(1/3) + (-1)^(2/3)*a^(1/3)*Sqrt[x]))/(Sqrt[-a]*a^(1/3) + (-1)^(1/3)*b^(5/6))])/(6*Sqrt[-a]*a^(5/3)) + ((-1)^(2/3)*(Sqrt[1 - a] + Sqrt[-a])*b^(2/3)*PolyLog[2, ((-1)^(1/3)*Sqrt[b]*(b^(1/3) + (-1)^(2/3)*a^(1/3)*Sqrt[x]))/(Sqrt[-a]*a^(1/3) + (-1)^(1/3)*b^(5/6))])/(6*(-a)^(3/2)*a^(2/3))} *)


(* ::Subsection::Closed:: *)
(*Integrands of the form ArcCoth[a+b x] / (c+d x+e x^2)*)


{ArcCoth[d + e*x]/(a + b*x + c*x^2), x, 35, (Log[b - Sqrt[b^2 - 4*a*c] + 2*c*x]*Log[(2*c*(1 - d - e*x))/(2*c - 2*c*d + b*e - Sqrt[b^2 - 4*a*c]*e)])/(2*Sqrt[b^2 - 4*a*c]) - (Log[b + Sqrt[b^2 - 4*a*c] + 2*c*x]*Log[(2*c*(1 - d - e*x))/(2*c*(1 - d) + (b + Sqrt[b^2 - 4*a*c])*e)])/(2*Sqrt[b^2 - 4*a*c]) - (Log[b - Sqrt[b^2 - 4*a*c] + 2*c*x]*Log[(2*c*(1 + d + e*x))/(2*c*(1 + d) - (b - Sqrt[b^2 - 4*a*c])*e)])/(2*Sqrt[b^2 - 4*a*c]) + (Log[b + Sqrt[b^2 - 4*a*c] + 2*c*x]*Log[(2*c*(1 + d + e*x))/(2*c*(1 + d) - (b + Sqrt[b^2 - 4*a*c])*e)])/(2*Sqrt[b^2 - 4*a*c]) - (Log[b - Sqrt[b^2 - 4*a*c] + 2*c*x]*Log[1 - 1/(d + e*x)])/(2*Sqrt[b^2 - 4*a*c]) + (Log[b + Sqrt[b^2 - 4*a*c] + 2*c*x]*Log[1 - 1/(d + e*x)])/(2*Sqrt[b^2 - 4*a*c]) + (Log[b - Sqrt[b^2 - 4*a*c] + 2*c*x]*Log[1 + 1/(d + e*x)])/(2*Sqrt[b^2 - 4*a*c]) - (Log[b + Sqrt[b^2 - 4*a*c] + 2*c*x]*Log[1 + 1/(d + e*x)])/(2*Sqrt[b^2 - 4*a*c]) + PolyLog[2, (e*(b - Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c - 2*c*d + b*e - Sqrt[b^2 - 4*a*c]*e)]/(2*Sqrt[b^2 - 4*a*c]) - PolyLog[2, -((e*(b - Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c*(1 + d) - (b - Sqrt[b^2 - 4*a*c])*e))]/(2*Sqrt[b^2 - 4*a*c]) + PolyLog[2, -((e*(b + Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c*(1 + d) - (b + Sqrt[b^2 - 4*a*c])*e))]/(2*Sqrt[b^2 - 4*a*c]) - PolyLog[2, (e*(b + Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c*(1 - d) + (b + Sqrt[b^2 - 4*a*c])*e)]/(2*Sqrt[b^2 - 4*a*c])}


(* ::Section::Closed:: *)
(*Integrands of the form u ArcCoth[a+b x^n]*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcCoth[a x^n]*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{ArcCoth[Sqrt[x]], x, 4, Sqrt[x] + x*ArcCoth[Sqrt[x]] - ArcTanh[Sqrt[x]]}
{x*ArcCoth[Sqrt[x]], x, 5, Sqrt[x]/2 + x^(3/2)/6 + (1/2)*x^2*ArcCoth[Sqrt[x]] - ArcTanh[Sqrt[x]]/2}
{x^2*ArcCoth[Sqrt[x]], x, 6, Sqrt[x]/3 + x^(3/2)/9 + x^(5/2)/15 + (1/3)*x^3*ArcCoth[Sqrt[x]] - ArcTanh[Sqrt[x]]/3}
{ArcCoth[Sqrt[x]]/x, x, 3, PolyLog[2, -(1/Sqrt[x])] - PolyLog[2, 1/Sqrt[x]]}
{ArcCoth[Sqrt[x]]/x^2, x, 4, -(1/Sqrt[x]) - ArcCoth[Sqrt[x]]/x + ArcTanh[Sqrt[x]]}
{ArcCoth[Sqrt[x]]/x^3, x, 5, -(1/(6*x^(3/2))) - 1/(2*Sqrt[x]) - ArcCoth[Sqrt[x]]/(2*x^2) + ArcTanh[Sqrt[x]]/2}


{Sqrt[x]*ArcCoth[Sqrt[x]], x, 4, x/3 + (2/3)*x^(3/2)*ArcCoth[Sqrt[x]] + (1/3)*Log[1 - x]}
{x^(3/2)*ArcCoth[Sqrt[x]], x, 4, x/5 + x^2/10 + (2/5)*x^(5/2)*ArcCoth[Sqrt[x]] + (1/5)*Log[1 - x]}
{ArcCoth[Sqrt[x]]/Sqrt[x], x, 3, 2*Sqrt[x]*ArcCoth[Sqrt[x]] + Log[1 - x]}
{ArcCoth[Sqrt[x]]/x^(3/2), x, 4, -((2*ArcCoth[Sqrt[x]])/Sqrt[x]) - Log[1 - x] + Log[x]}


{ArcCoth[a*x^5]/x, x, 3, (1/10)*PolyLog[2, -(1/(a*x^5))] - (1/10)*PolyLog[2, 1/(a*x^5)]}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{ArcCoth[1/x], x, 3, x*ArcTanh[x] + Log[1 - x^2]/2}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{ArcCoth[a*x^n]/x, x, 3, PolyLog[2, -(1/(x^n*a))]/(2*n) - PolyLog[2, 1/(x^n*a)]/(2*n)}


(* ::Section::Closed:: *)
(*Integrands involving inverse hyperbolic cotangents of exponentials*)


(* Integrands of the form x^m*ArcCoth[E^x] *)
{ArcCoth[E^x], x, 3, (1/2)*PolyLog[2, -E^(-x)] - (1/2)*PolyLog[2, E^(-x)]}
{x*ArcCoth[E^x], x, 5, (1/2)*x*PolyLog[2, -E^(-x)] - (1/2)*x*PolyLog[2, E^(-x)] + (1/2)*PolyLog[3, -E^(-x)] - (1/2)*PolyLog[3, E^(-x)]}
{x^2*ArcCoth[E^x], x, 7, (1/2)*x^2*PolyLog[2, -E^(-x)] - (1/2)*x^2*PolyLog[2, E^(-x)] + x*PolyLog[3, -E^(-x)] - x*PolyLog[3, E^(-x)] + PolyLog[4, -E^(-x)] - PolyLog[4, E^(-x)]}


(* Integrands of the form x^m*ArcCoth[E^(a+b*x)] *)
{ArcCoth[E^(a + b*x)], x, 3, PolyLog[2, -E^(-a - b*x)]/(2*b) - PolyLog[2, E^(-a - b*x)]/(2*b)}
{x*ArcCoth[E^(a + b*x)], x, 5, (x*PolyLog[2, -E^(-a - b*x)])/(2*b) - (x*PolyLog[2, E^(-a - b*x)])/(2*b) + PolyLog[3, -E^(-a - b*x)]/(2*b^2) - PolyLog[3, E^(-a - b*x)]/(2*b^2)}
{x^2*ArcCoth[E^(a + b*x)], x, 7, (x^2*PolyLog[2, -E^(-a - b*x)])/(2*b) - (x^2*PolyLog[2, E^(-a - b*x)])/(2*b) + (x*PolyLog[3, -E^(-a - b*x)])/b^2 - (x*PolyLog[3, E^(-a - b*x)])/b^2 + PolyLog[4, -E^(-a - b*x)]/b^3 - PolyLog[4, E^(-a - b*x)]/b^3}


(* Integrands of the form x^m*ArcCoth[a+b*f^(c+d*x)] *)
{ArcCoth[a + b*f^(c + d*x)], x, 17, (1/2)*x*Log[1 - (b*f^(c + d*x))/(1 - a)] - (1/2)*x*Log[1 + (b*f^(c + d*x))/(1 + a)] - (1/2)*x*Log[1 - 1/(a + b*f^(c + d*x))] + (1/2)*x*Log[1 + 1/(a + b*f^(c + d*x))] + PolyLog[2, (b*f^(c + d*x))/(1 - a)]/(2*d*Log[f]) - PolyLog[2, -((b*f^(c + d*x))/(1 + a))]/(2*d*Log[f])}
{x*ArcCoth[a + b*f^(c + d*x)], x, 21, (1/4)*x^2*Log[1 - (b*f^(c + d*x))/(1 - a)] - (1/4)*x^2*Log[1 + (b*f^(c + d*x))/(1 + a)] - (1/4)*x^2*Log[1 - 1/(a + b*f^(c + d*x))] + (1/4)*x^2*Log[1 + 1/(a + b*f^(c + d*x))] + (x*PolyLog[2, (b*f^(c + d*x))/(1 - a)])/(2*d*Log[f]) - (x*PolyLog[2, -((b*f^(c + d*x))/(1 + a))])/(2*d*Log[f]) - PolyLog[3, (b*f^(c + d*x))/(1 - a)]/(2*d^2*Log[f]^2) + PolyLog[3, -((b*f^(c + d*x))/(1 + a))]/(2*d^2*Log[f]^2)}
{x^2*ArcCoth[a + b*f^(c + d*x)], x, 25, (1/6)*x^3*Log[1 - (b*f^(c + d*x))/(1 - a)] - (1/6)*x^3*Log[1 + (b*f^(c + d*x))/(1 + a)] - (1/6)*x^3*Log[1 - 1/(a + b*f^(c + d*x))] + (1/6)*x^3*Log[1 + 1/(a + b*f^(c + d*x))] + (x^2*PolyLog[2, (b*f^(c + d*x))/(1 - a)])/(2*d*Log[f]) - (x^2*PolyLog[2, -((b*f^(c + d*x))/(1 + a))])/(2*d*Log[f]) - (x*PolyLog[3, (b*f^(c + d*x))/(1 - a)])/(d^2*Log[f]^2) + (x*PolyLog[3, -((b*f^(c + d*x))/(1 + a))])/(d^2*Log[f]^2) + PolyLog[4, (b*f^(c + d*x))/(1 - a)]/(d^3*Log[f]^3) - PolyLog[4, -((b*f^(c + d*x))/(1 + a))]/(d^3*Log[f]^3)}


(* ::Section::Closed:: *)
(*Integrands involving inverse hyperbolic cotangents of hyperbolic functions*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcCoth[Tanh[a+b x]]^n*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{ArcCoth[Tanh[a + b*x]]*x^m, x, 2, -((b*x^(2 + m))/(2 + 3*m + m^2)) + (x^(1 + m)*ArcCoth[Tanh[a + b*x]])/(1 + m)}

{ArcCoth[Tanh[a + b*x]]*x^2, x, 2, -((b*x^4)/12) + (1/3)*x^3*ArcCoth[Tanh[a + b*x]]}
{ArcCoth[Tanh[a + b*x]]*x^1, x, 2, -((b*x^3)/6) + (1/2)*x^2*ArcCoth[Tanh[a + b*x]]}
{ArcCoth[Tanh[a + b*x]]*x^0, x, 2, ArcCoth[Tanh[a + b*x]]^2/(2*b)}
{ArcCoth[Tanh[a + b*x]]/x^1, x, 2, b*x - (b*x - ArcCoth[Tanh[a + b*x]])*Log[x]}
{ArcCoth[Tanh[a + b*x]]/x^2, x, 2, -(ArcCoth[Tanh[a + b*x]]/x) + b*Log[x]}
{ArcCoth[Tanh[a + b*x]]/x^3, x, 2, -(b/(2*x)) - ArcCoth[Tanh[a + b*x]]/(2*x^2)}
{ArcCoth[Tanh[a + b*x]]/x^4, x, 2, -(b/(6*x^2)) - ArcCoth[Tanh[a + b*x]]/(3*x^3)}


{ArcCoth[Tanh[a + b*x]]^2*x^m, x, 3, (2*b^2*x^(3 + m))/(6 + 11*m + 6*m^2 + m^3) - (2*b*x^(2 + m)*ArcCoth[Tanh[a + b*x]])/(2 + 3*m + m^2) + (x^(1 + m)*ArcCoth[Tanh[a + b*x]]^2)/(1 + m)}

{ArcCoth[Tanh[a + b*x]]^2*x^3, x, 3, (b^2*x^6)/60 - (1/10)*b*x^5*ArcCoth[Tanh[a + b*x]] + (1/4)*x^4*ArcCoth[Tanh[a + b*x]]^2}
{ArcCoth[Tanh[a + b*x]]^2*x^2, x, 3, (b^2*x^5)/30 - (1/6)*b*x^4*ArcCoth[Tanh[a + b*x]] + (1/3)*x^3*ArcCoth[Tanh[a + b*x]]^2}
{ArcCoth[Tanh[a + b*x]]^2*x^1, x, 3, (x*ArcCoth[Tanh[a + b*x]]^3)/(3*b) - ArcCoth[Tanh[a + b*x]]^4/(12*b^2)}
{ArcCoth[Tanh[a + b*x]]^2*x^0, x, 2, ArcCoth[Tanh[a + b*x]]^3/(3*b)}
{ArcCoth[Tanh[a + b*x]]^2/x^1, x, 3, (-b)*x*(b*x - ArcCoth[Tanh[a + b*x]]) + (1/2)*ArcCoth[Tanh[a + b*x]]^2 + (b*x - ArcCoth[Tanh[a + b*x]])^2*Log[x]}
{ArcCoth[Tanh[a + b*x]]^2/x^2, x, 3, 2*b^2*x - ArcCoth[Tanh[a + b*x]]^2/x - 2*b*(b*x - ArcCoth[Tanh[a + b*x]])*Log[x]}
{ArcCoth[Tanh[a + b*x]]^2/x^3, x, 3, -((b*ArcCoth[Tanh[a + b*x]])/x) - ArcCoth[Tanh[a + b*x]]^2/(2*x^2) + b^2*Log[x]}
{ArcCoth[Tanh[a + b*x]]^2/x^4, x, 1, ArcCoth[Tanh[a + b*x]]^3/(3*x^3*(b*x - ArcCoth[Tanh[a + b*x]]))}
{ArcCoth[Tanh[a + b*x]]^2/x^5, x, 2, (b*ArcCoth[Tanh[a + b*x]]^3)/(12*x^3*(b*x - ArcCoth[Tanh[a + b*x]])^2) + ArcCoth[Tanh[a + b*x]]^3/(4*x^4*(b*x - ArcCoth[Tanh[a + b*x]]))}


{ArcCoth[Tanh[a + b*x]]^3*x^m, x, 4, -((6*b^3*x^(4 + m))/((1 + m)*(24 + 26*m + 9*m^2 + m^3))) + (6*b^2*x^(3 + m)*ArcCoth[Tanh[a + b*x]])/(6 + 11*m + 6*m^2 + m^3) - (3*b*x^(2 + m)*ArcCoth[Tanh[a + b*x]]^2)/(2 + 3*m + m^2) + (x^(1 + m)*ArcCoth[Tanh[a + b*x]]^3)/(1 + m)}

{ArcCoth[Tanh[a + b*x]]^3*x^4, x, 4, (-(1/280))*b^3*x^8 + (1/35)*b^2*x^7*ArcCoth[Tanh[a + b*x]] - (1/10)*b*x^6*ArcCoth[Tanh[a + b*x]]^2 + (1/5)*x^5*ArcCoth[Tanh[a + b*x]]^3}
{ArcCoth[Tanh[a + b*x]]^3*x^3, x, 4, (-(1/140))*b^3*x^7 + (1/20)*b^2*x^6*ArcCoth[Tanh[a + b*x]] - (3/20)*b*x^5*ArcCoth[Tanh[a + b*x]]^2 + (1/4)*x^4*ArcCoth[Tanh[a + b*x]]^3}
{ArcCoth[Tanh[a + b*x]]^3*x^2, x, 4, (x^2*ArcCoth[Tanh[a + b*x]]^4)/(4*b) - (x*ArcCoth[Tanh[a + b*x]]^5)/(10*b^2) + ArcCoth[Tanh[a + b*x]]^6/(60*b^3)}
{ArcCoth[Tanh[a + b*x]]^3*x^1, x, 3, (x*ArcCoth[Tanh[a + b*x]]^4)/(4*b) - ArcCoth[Tanh[a + b*x]]^5/(20*b^2)}
{ArcCoth[Tanh[a + b*x]]^3*x^0, x, 2, ArcCoth[Tanh[a + b*x]]^4/(4*b)}
{ArcCoth[Tanh[a + b*x]]^3/x^1, x, 4, b*x*(b*x - ArcCoth[Tanh[a + b*x]])^2 - (1/2)*(b*x - ArcCoth[Tanh[a + b*x]])*ArcCoth[Tanh[a + b*x]]^2 + (1/3)*ArcCoth[Tanh[a + b*x]]^3 - (b*x - ArcCoth[Tanh[a + b*x]])^3*Log[x]}
{ArcCoth[Tanh[a + b*x]]^3/x^2, x, 4, -3*b^2*x*(b*x - ArcCoth[Tanh[a + b*x]]) + (3/2)*b*ArcCoth[Tanh[a + b*x]]^2 - ArcCoth[Tanh[a + b*x]]^3/x + 3*b*(b*x - ArcCoth[Tanh[a + b*x]])^2*Log[x]}
{ArcCoth[Tanh[a + b*x]]^3/x^3, x, 4, 3*b^3*x - (3*b*ArcCoth[Tanh[a + b*x]]^2)/(2*x) - ArcCoth[Tanh[a + b*x]]^3/(2*x^2) - 3*b^2*(b*x - ArcCoth[Tanh[a + b*x]])*Log[x]}
{ArcCoth[Tanh[a + b*x]]^3/x^4, x, 4, -((b^2*ArcCoth[Tanh[a + b*x]])/x) - (b*ArcCoth[Tanh[a + b*x]]^2)/(2*x^2) - ArcCoth[Tanh[a + b*x]]^3/(3*x^3) + b^3*Log[x]}
{ArcCoth[Tanh[a + b*x]]^3/x^5, x, 1, ArcCoth[Tanh[a + b*x]]^4/(4*x^4*(b*x - ArcCoth[Tanh[a + b*x]]))}
{ArcCoth[Tanh[a + b*x]]^3/x^6, x, 2, (b*ArcCoth[Tanh[a + b*x]]^4)/(20*x^4*(b*x - ArcCoth[Tanh[a + b*x]])^2) + ArcCoth[Tanh[a + b*x]]^4/(5*x^5*(b*x - ArcCoth[Tanh[a + b*x]]))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{1/ArcCoth[Tanh[a + b*x]]*x^m, x, 1, -((x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, (b*x)/(b*x - ArcCoth[Tanh[a + b*x]])])/((1 + m)*(b*x - ArcCoth[Tanh[a + b*x]])))}

{1/ArcCoth[Tanh[a + b*x]]*x^3, x, 5, x^3/(3*b) + (x^2*(b*x - ArcCoth[Tanh[a + b*x]]))/(2*b^2) + (x*(b*x - ArcCoth[Tanh[a + b*x]])^2)/b^3 + ((b*x - ArcCoth[Tanh[a + b*x]])^3*Log[ArcCoth[Tanh[a + b*x]]])/b^4}
{1/ArcCoth[Tanh[a + b*x]]*x^2, x, 4, x^2/(2*b) + (x*(b*x - ArcCoth[Tanh[a + b*x]]))/b^2 + ((b*x - ArcCoth[Tanh[a + b*x]])^2*Log[ArcCoth[Tanh[a + b*x]]])/b^3}
{1/ArcCoth[Tanh[a + b*x]]*x^1, x, 3, x/b + ((b*x - ArcCoth[Tanh[a + b*x]])*Log[ArcCoth[Tanh[a + b*x]]])/b^2}
{1/ArcCoth[Tanh[a + b*x]]*x^0, x, 2, Log[ArcCoth[Tanh[a + b*x]]]/b}
{1/ArcCoth[Tanh[a + b*x]]/x^1, x, 4, -(Log[x]/(b*x - ArcCoth[Tanh[a + b*x]])) + Log[ArcCoth[Tanh[a + b*x]]]/(b*x - ArcCoth[Tanh[a + b*x]])}
{1/ArcCoth[Tanh[a + b*x]]/x^2, x, 5, 1/(x*(b*x - ArcCoth[Tanh[a + b*x]])) - (b*Log[x])/(b*x - ArcCoth[Tanh[a + b*x]])^2 + (b*Log[ArcCoth[Tanh[a + b*x]]])/(b*x - ArcCoth[Tanh[a + b*x]])^2}
{1/ArcCoth[Tanh[a + b*x]]/x^3, x, 6, b/(x*(b*x - ArcCoth[Tanh[a + b*x]])^2) + 1/(2*x^2*(b*x - ArcCoth[Tanh[a + b*x]])) - (b^2*Log[x])/(b*x - ArcCoth[Tanh[a + b*x]])^3 + (b^2*Log[ArcCoth[Tanh[a + b*x]]])/(b*x - ArcCoth[Tanh[a + b*x]])^3}


{1/ArcCoth[Tanh[a + b*x]]^2*x^m, x, 2, -(x^m/(b*ArcCoth[Tanh[a + b*x]])) - (x^m*Hypergeometric2F1[1, m, 1 + m, (b*x)/(b*x - ArcCoth[Tanh[a + b*x]])])/(b*(b*x - ArcCoth[Tanh[a + b*x]]))}

{1/ArcCoth[Tanh[a + b*x]]^2*x^4, x, 6, (4*x^3)/(3*b^2) + (2*x^2*(b*x - ArcCoth[Tanh[a + b*x]]))/b^3 + (4*x*(b*x - ArcCoth[Tanh[a + b*x]])^2)/b^4 - x^4/(b*ArcCoth[Tanh[a + b*x]]) + (4*(b*x - ArcCoth[Tanh[a + b*x]])^3*Log[ArcCoth[Tanh[a + b*x]]])/b^5}
{1/ArcCoth[Tanh[a + b*x]]^2*x^3, x, 5, (3*x^2)/(2*b^2) + (3*x*(b*x - ArcCoth[Tanh[a + b*x]]))/b^3 - x^3/(b*ArcCoth[Tanh[a + b*x]]) + (3*(b*x - ArcCoth[Tanh[a + b*x]])^2*Log[ArcCoth[Tanh[a + b*x]]])/b^4}
{1/ArcCoth[Tanh[a + b*x]]^2*x^2, x, 4, (2*x)/b^2 - x^2/(b*ArcCoth[Tanh[a + b*x]]) + (2*(b*x - ArcCoth[Tanh[a + b*x]])*Log[ArcCoth[Tanh[a + b*x]]])/b^3}
{1/ArcCoth[Tanh[a + b*x]]^2*x^1, x, 3, -(x/(b*ArcCoth[Tanh[a + b*x]])) + Log[ArcCoth[Tanh[a + b*x]]]/b^2}
{1/ArcCoth[Tanh[a + b*x]]^2*x^0, x, 2, -(1/(b*ArcCoth[Tanh[a + b*x]]))}
{1/ArcCoth[Tanh[a + b*x]]^2/x^1, x, 5, -(1/((b*x - ArcCoth[Tanh[a + b*x]])*ArcCoth[Tanh[a + b*x]])) + Log[x]/(b*x - ArcCoth[Tanh[a + b*x]])^2 - Log[ArcCoth[Tanh[a + b*x]]]/(b*x - ArcCoth[Tanh[a + b*x]])^2}
{1/ArcCoth[Tanh[a + b*x]]^2/x^2, x, 6, -((2*b)/((b*x - ArcCoth[Tanh[a + b*x]])^2*ArcCoth[Tanh[a + b*x]])) + 1/(x*(b*x - ArcCoth[Tanh[a + b*x]])*ArcCoth[Tanh[a + b*x]]) + (2*b*Log[x])/(b*x - ArcCoth[Tanh[a + b*x]])^3 - (2*b*Log[ArcCoth[Tanh[a + b*x]]])/(b*x - ArcCoth[Tanh[a + b*x]])^3}
{1/ArcCoth[Tanh[a + b*x]]^2/x^3, x, 7, -((3*b^2)/((b*x - ArcCoth[Tanh[a + b*x]])^3*ArcCoth[Tanh[a + b*x]])) + (3*b)/(2*x*(b*x - ArcCoth[Tanh[a + b*x]])^2*ArcCoth[Tanh[a + b*x]]) + 1/(2*x^2*(b*x - ArcCoth[Tanh[a + b*x]])*ArcCoth[Tanh[a + b*x]]) + (3*b^2*Log[x])/(b*x - ArcCoth[Tanh[a + b*x]])^4 - (3*b^2*Log[ArcCoth[Tanh[a + b*x]]])/(b*x - ArcCoth[Tanh[a + b*x]])^4}


{1/ArcCoth[Tanh[a + b*x]]^3*x^m, x, 3, -(x^m/(2*b*ArcCoth[Tanh[a + b*x]]^2)) - (m*x^(-1 + m))/(2*b^2*ArcCoth[Tanh[a + b*x]]) - (m*x^(-1 + m)*Hypergeometric2F1[1, -1 + m, m, (b*x)/(b*x - ArcCoth[Tanh[a + b*x]])])/(2*b^2*(b*x - ArcCoth[Tanh[a + b*x]]))}

{1/ArcCoth[Tanh[a + b*x]]^3*x^4, x, 6, (3*x^2)/b^3 + (6*x*(b*x - ArcCoth[Tanh[a + b*x]]))/b^4 - x^4/(2*b*ArcCoth[Tanh[a + b*x]]^2) - (2*x^3)/(b^2*ArcCoth[Tanh[a + b*x]]) + (6*(b*x - ArcCoth[Tanh[a + b*x]])^2*Log[ArcCoth[Tanh[a + b*x]]])/b^5}
{1/ArcCoth[Tanh[a + b*x]]^3*x^3, x, 5, (3*x)/b^3 - x^3/(2*b*ArcCoth[Tanh[a + b*x]]^2) - (3*x^2)/(2*b^2*ArcCoth[Tanh[a + b*x]]) + (3*(b*x - ArcCoth[Tanh[a + b*x]])*Log[ArcCoth[Tanh[a + b*x]]])/b^4}
{1/ArcCoth[Tanh[a + b*x]]^3*x^2, x, 4, -(x^2/(2*b*ArcCoth[Tanh[a + b*x]]^2)) - x/(b^2*ArcCoth[Tanh[a + b*x]]) + Log[ArcCoth[Tanh[a + b*x]]]/b^3}
{1/ArcCoth[Tanh[a + b*x]]^3*x^1, x, 3, -(x/(2*b*ArcCoth[Tanh[a + b*x]]^2)) - 1/(2*b^2*ArcCoth[Tanh[a + b*x]])}
{1/ArcCoth[Tanh[a + b*x]]^3*x^0, x, 2, -(1/(2*b*ArcCoth[Tanh[a + b*x]]^2))}
{1/ArcCoth[Tanh[a + b*x]]^3/x^1, x, 6, -(1/(2*(b*x - ArcCoth[Tanh[a + b*x]])*ArcCoth[Tanh[a + b*x]]^2)) + 1/((b*x - ArcCoth[Tanh[a + b*x]])^2*ArcCoth[Tanh[a + b*x]]) - Log[x]/(b*x - ArcCoth[Tanh[a + b*x]])^3 + Log[ArcCoth[Tanh[a + b*x]]]/(b*x - ArcCoth[Tanh[a + b*x]])^3}
{1/ArcCoth[Tanh[a + b*x]]^3/x^2, x, 7, -((3*b)/(2*(b*x - ArcCoth[Tanh[a + b*x]])^2*ArcCoth[Tanh[a + b*x]]^2)) + 1/(x*(b*x - ArcCoth[Tanh[a + b*x]])*ArcCoth[Tanh[a + b*x]]^2) + (3*b)/((b*x - ArcCoth[Tanh[a + b*x]])^3*ArcCoth[Tanh[a + b*x]]) - (3*b*Log[x])/(b*x - ArcCoth[Tanh[a + b*x]])^4 + (3*b*Log[ArcCoth[Tanh[a + b*x]]])/(b*x - ArcCoth[Tanh[a + b*x]])^4}
{1/ArcCoth[Tanh[a + b*x]]^3/x^3, x, 8, -((3*b^2)/((b*x - ArcCoth[Tanh[a + b*x]])^3*ArcCoth[Tanh[a + b*x]]^2)) + (2*b)/(x*(b*x - ArcCoth[Tanh[a + b*x]])^2*ArcCoth[Tanh[a + b*x]]^2) + 1/(2*x^2*(b*x - ArcCoth[Tanh[a + b*x]])*ArcCoth[Tanh[a + b*x]]^2) + (6*b^2)/((b*x - ArcCoth[Tanh[a + b*x]])^4*ArcCoth[Tanh[a + b*x]]) - (6*b^2*Log[x])/(b*x - ArcCoth[Tanh[a + b*x]])^5 + (6*b^2*Log[ArcCoth[Tanh[a + b*x]]])/(b*x - ArcCoth[Tanh[a + b*x]])^5}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{ArcCoth[Tanh[a + b*x]]^n*x^m, x, 1, (1/(b*(1 + n)))*((x^m*ArcCoth[Tanh[a + b*x]]^(1 + n)*Hypergeometric2F1[-m, 1 + n, 2 + n, -(ArcCoth[Tanh[a + b*x]]/(b*x - ArcCoth[Tanh[a + b*x]]))])/((b*x)/(b*x - ArcCoth[Tanh[a + b*x]]))^m)}

{ArcCoth[Tanh[a + b*x]]^n*x^4, x, 6, (x^4*ArcCoth[Tanh[a + b*x]]^(1 + n))/(b*(1 + n)) - (4*x^3*ArcCoth[Tanh[a + b*x]]^(2 + n))/(b^2*(1 + n)*(2 + n)) + (12*x^2*ArcCoth[Tanh[a + b*x]]^(3 + n))/(b^3*(1 + n)*(2 + n)*(3 + n)) - (24*x*ArcCoth[Tanh[a + b*x]]^(4 + n))/(b^4*(1 + n)*(2 + n)*(3 + n)*(4 + n)) + (24*ArcCoth[Tanh[a + b*x]]^(5 + n))/(b^5*(1 + n)*(2 + n)*(3 + n)*(4 + n)*(5 + n))}
{ArcCoth[Tanh[a + b*x]]^n*x^3, x, 5, (x^3*ArcCoth[Tanh[a + b*x]]^(1 + n))/(b*(1 + n)) - (3*x^2*ArcCoth[Tanh[a + b*x]]^(2 + n))/(b^2*(1 + n)*(2 + n)) + (6*x*ArcCoth[Tanh[a + b*x]]^(3 + n))/(b^3*(1 + n)*(2 + n)*(3 + n)) - (6*ArcCoth[Tanh[a + b*x]]^(4 + n))/(b^4*(1 + n)*(2 + n)*(3 + n)*(4 + n))}
{ArcCoth[Tanh[a + b*x]]^n*x^2, x, 4, (x^2*ArcCoth[Tanh[a + b*x]]^(1 + n))/(b*(1 + n)) - (2*x*ArcCoth[Tanh[a + b*x]]^(2 + n))/(b^2*(1 + n)*(2 + n)) + (2*ArcCoth[Tanh[a + b*x]]^(3 + n))/(b^3*(1 + n)*(2 + n)*(3 + n))}
{ArcCoth[Tanh[a + b*x]]^n*x^1, x, 3, (x*ArcCoth[Tanh[a + b*x]]^(1 + n))/(b*(1 + n)) - ArcCoth[Tanh[a + b*x]]^(2 + n)/(b^2*(1 + n)*(2 + n))}
{ArcCoth[Tanh[a + b*x]]^n*x^0, x, 2, ArcCoth[Tanh[a + b*x]]^(1 + n)/(b*(1 + n))}
{ArcCoth[Tanh[a + b*x]]^n/x^1, x, 1, (ArcCoth[Tanh[a + b*x]]^(1 + n)*Hypergeometric2F1[1, 1 + n, 2 + n, -(ArcCoth[Tanh[a + b*x]]/(b*x - ArcCoth[Tanh[a + b*x]]))])/((1 + n)*(b*x - ArcCoth[Tanh[a + b*x]]))}
{ArcCoth[Tanh[a + b*x]]^n/x^2, x, 2, -(ArcCoth[Tanh[a + b*x]]^n/x) + (b*ArcCoth[Tanh[a + b*x]]^n*Hypergeometric2F1[1, n, 1 + n, -(ArcCoth[Tanh[a + b*x]]/(b*x - ArcCoth[Tanh[a + b*x]]))])/(b*x - ArcCoth[Tanh[a + b*x]])}
{ArcCoth[Tanh[a + b*x]]^n/x^3, x, 3, -((b*n*ArcCoth[Tanh[a + b*x]]^(-1 + n))/(2*x)) - ArcCoth[Tanh[a + b*x]]^n/(2*x^2) + (b^2*n*ArcCoth[Tanh[a + b*x]]^(-1 + n)*Hypergeometric2F1[1, -1 + n, n, -(ArcCoth[Tanh[a + b*x]]/(b*x - ArcCoth[Tanh[a + b*x]]))])/(2*(b*x - ArcCoth[Tanh[a + b*x]]))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcCoth[Coth[a+b x]]*)


{ArcCoth[Tanh[a + b*x]]*x^m, x, 2, -((b*x^(2 + m))/(2 + 3*m + m^2)) + (x^(1 + m)*ArcCoth[Tanh[a + b*x]])/(1 + m)}

{ArcCoth[Coth[a + b*x]]*x^2, x, 2, -((b*x^4)/12) + (1/3)*x^3*ArcCoth[Coth[a + b*x]]}
{ArcCoth[Coth[a + b*x]]*x^1, x, 2, -((b*x^3)/6) + (1/2)*x^2*ArcCoth[Coth[a + b*x]]}
{ArcCoth[Coth[a + b*x]]*x^0, x, 2, ArcCoth[Coth[a + b*x]]^2/(2*b)}
{ArcCoth[Coth[a + b*x]]/x^1, x, 2, b*x - (b*x - ArcCoth[Coth[a + b*x]])*Log[x]}
{ArcCoth[Coth[a + b*x]]/x^2, x, 2, -(ArcCoth[Coth[a + b*x]]/x) + b*Log[x]}
{ArcCoth[Coth[a + b*x]]/x^3, x, 2, -(b/(2*x)) - ArcCoth[Coth[a + b*x]]/(2*x^2)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcCoth[c+d Tanh[a+b x]]*)


{ArcCoth[c + d*Tanh[a + b*x]]*x^2, x, 11, (1/3)*x^3*ArcCoth[c + d*Tanh[a + b*x]] + (1/6)*x^3*Log[1 + ((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d)] - (1/6)*x^3*Log[1 + ((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d)] + (x^2*PolyLog[2, -(((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d))])/(4*b) - (x^2*PolyLog[2, -(((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d))])/(4*b) - (x*PolyLog[3, -(((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d))])/(4*b^2) + (x*PolyLog[3, -(((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d))])/(4*b^2) + PolyLog[4, -(((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d))]/(8*b^3) - PolyLog[4, -(((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d))]/(8*b^3)}
{ArcCoth[c + d*Tanh[a + b*x]]*x^1, x, 9, (1/2)*x^2*ArcCoth[c + d*Tanh[a + b*x]] + (1/4)*x^2*Log[1 + ((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d)] - (1/4)*x^2*Log[1 + ((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d)] + (x*PolyLog[2, -(((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d))])/(4*b) - (x*PolyLog[2, -(((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d))])/(4*b) - PolyLog[3, -(((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d))]/(8*b^2) + PolyLog[3, -(((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d))]/(8*b^2)}
{ArcCoth[c + d*Tanh[a + b*x]]*x^0, x, 7, x*ArcCoth[c + d*Tanh[a + b*x]] + (1/2)*x*Log[1 + ((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d)] - (1/2)*x*Log[1 + ((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d)] + PolyLog[2, -(((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d))]/(4*b) - PolyLog[2, -(((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d))]/(4*b)}
{ArcCoth[c + d*Tanh[a + b*x]]/x^1, x, 0, Int[ArcCoth[c + d*Tanh[a + b*x]]/x, x]}
(* {ArcCoth[c + d*Tanh[a + b*x]]/x^2, x, 0, 0} *)


{ArcCoth[1 + d + d*Tanh[a + b*x]]*x^3, x, 7, (b*x^5)/20 + (1/4)*x^4*ArcCoth[1 + d + d*Tanh[a + b*x]] - (1/8)*x^4*Log[1 + (1 + d)*E^(2*a + 2*b*x)] - (x^3*PolyLog[2, -((1 + d)*E^(2*a + 2*b*x))])/(4*b) + (3*x^2*PolyLog[3, -((1 + d)*E^(2*a + 2*b*x))])/(8*b^2) - (3*x*PolyLog[4, -((1 + d)*E^(2*a + 2*b*x))])/(8*b^3) + (3*PolyLog[5, -((1 + d)*E^(2*a + 2*b*x))])/(16*b^4)}
{ArcCoth[1 + d + d*Tanh[a + b*x]]*x^2, x, 6, (b*x^4)/12 + (1/3)*x^3*ArcCoth[1 + d + d*Tanh[a + b*x]] - (1/6)*x^3*Log[1 + (1 + d)*E^(2*a + 2*b*x)] - (x^2*PolyLog[2, -((1 + d)*E^(2*a + 2*b*x))])/(4*b) + (x*PolyLog[3, -((1 + d)*E^(2*a + 2*b*x))])/(4*b^2) - PolyLog[4, -((1 + d)*E^(2*a + 2*b*x))]/(8*b^3)}
{ArcCoth[1 + d + d*Tanh[a + b*x]]*x^1, x, 5, (b*x^3)/6 + (1/2)*x^2*ArcCoth[1 + d + d*Tanh[a + b*x]] - (1/4)*x^2*Log[1 + (1 + d)*E^(2*a + 2*b*x)] - (x*PolyLog[2, -((1 + d)*E^(2*a + 2*b*x))])/(4*b) + PolyLog[3, -((1 + d)*E^(2*a + 2*b*x))]/(8*b^2)}
{ArcCoth[1 + d + d*Tanh[a + b*x]]*x^0, x, 4, (b*x^2)/2 + x*ArcCoth[1 + d + d*Tanh[a + b*x]] - (1/2)*x*Log[1 + (1 + d)*E^(2*a + 2*b*x)] - PolyLog[2, -((1 + d)*E^(2*a + 2*b*x))]/(4*b)}
{ArcCoth[1 + d + d*Tanh[a + b*x]]/x^1, x, 0, Int[ArcCoth[1 + d + d*Tanh[a + b*x]]/x, x]}


{ArcCoth[1 - d - d*Tanh[a + b*x]]*x^3, x, 7, (b*x^5)/20 + (1/4)*x^4*ArcCoth[1 - d - d*Tanh[a + b*x]] - (1/8)*x^4*Log[1 + (1 - d)*E^(2*a + 2*b*x)] - (x^3*PolyLog[2, -((1 - d)*E^(2*a + 2*b*x))])/(4*b) + (3*x^2*PolyLog[3, -((1 - d)*E^(2*a + 2*b*x))])/(8*b^2) - (3*x*PolyLog[4, -((1 - d)*E^(2*a + 2*b*x))])/(8*b^3) + (3*PolyLog[5, -((1 - d)*E^(2*a + 2*b*x))])/(16*b^4)}
{ArcCoth[1 - d - d*Tanh[a + b*x]]*x^2, x, 6, (b*x^4)/12 + (1/3)*x^3*ArcCoth[1 - d - d*Tanh[a + b*x]] - (1/6)*x^3*Log[1 + (1 - d)*E^(2*a + 2*b*x)] - (x^2*PolyLog[2, -((1 - d)*E^(2*a + 2*b*x))])/(4*b) + (x*PolyLog[3, -((1 - d)*E^(2*a + 2*b*x))])/(4*b^2) - PolyLog[4, -((1 - d)*E^(2*a + 2*b*x))]/(8*b^3)}
{ArcCoth[1 - d - d*Tanh[a + b*x]]*x^1, x, 5, (b*x^3)/6 + (1/2)*x^2*ArcCoth[1 - d - d*Tanh[a + b*x]] - (1/4)*x^2*Log[1 + (1 - d)*E^(2*a + 2*b*x)] - (x*PolyLog[2, -((1 - d)*E^(2*a + 2*b*x))])/(4*b) + PolyLog[3, -((1 - d)*E^(2*a + 2*b*x))]/(8*b^2)}
{ArcCoth[1 - d - d*Tanh[a + b*x]]*x^0, x, 4, (b*x^2)/2 + x*ArcCoth[1 - d - d*Tanh[a + b*x]] - (1/2)*x*Log[1 + (1 - d)*E^(2*a + 2*b*x)] - PolyLog[2, -((1 - d)*E^(2*a + 2*b*x))]/(4*b)}
{ArcCoth[1 - d - d*Tanh[a + b*x]]/x^1, x, 0, Int[ArcCoth[1 - d - d*Tanh[a + b*x]]/x, x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcCoth[c+d Coth[a+b x]]*)


{ArcCoth[c + d*Coth[a + b*x]]*x^2, x, 11, (1/3)*x^3*ArcCoth[c + d*Coth[a + b*x]] + (1/6)*x^3*Log[1 - ((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d)] - (1/6)*x^3*Log[1 - ((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d)] + (x^2*PolyLog[2, ((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d)])/(4*b) - (x^2*PolyLog[2, ((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d)])/(4*b) - (x*PolyLog[3, ((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d)])/(4*b^2) + (x*PolyLog[3, ((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d)])/(4*b^2) + PolyLog[4, ((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d)]/(8*b^3) - PolyLog[4, ((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d)]/(8*b^3)}
{ArcCoth[c + d*Coth[a + b*x]]*x^1, x, 9, (1/2)*x^2*ArcCoth[c + d*Coth[a + b*x]] + (1/4)*x^2*Log[1 - ((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d)] - (1/4)*x^2*Log[1 - ((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d)] + (x*PolyLog[2, ((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d)])/(4*b) - (x*PolyLog[2, ((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d)])/(4*b) - PolyLog[3, ((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d)]/(8*b^2) + PolyLog[3, ((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d)]/(8*b^2)}
{ArcCoth[c + d*Coth[a + b*x]]*x^0, x, 7, x*ArcCoth[c + d*Coth[a + b*x]] + (1/2)*x*Log[1 - ((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d)] - (1/2)*x*Log[1 - ((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d)] + PolyLog[2, ((1 - c - d)*E^(2*a + 2*b*x))/(1 - c + d)]/(4*b) - PolyLog[2, ((1 + c + d)*E^(2*a + 2*b*x))/(1 + c - d)]/(4*b)}
{ArcCoth[c + d*Coth[a + b*x]]/x^1, x, 0, Int[ArcCoth[c + d*Coth[a + b*x]]/x, x]}
(* {ArcCoth[c + d*Coth[a + b*x]]/x^2, x, 0, 0} *)


{ArcCoth[1 + d + d*Coth[a + b*x]]*x^3, x, 7, (b*x^5)/20 + (1/4)*x^4*ArcCoth[1 + d + d*Coth[a + b*x]] - (1/8)*x^4*Log[1 - (1 + d)*E^(2*a + 2*b*x)] - (x^3*PolyLog[2, (1 + d)*E^(2*a + 2*b*x)])/(4*b) + (3*x^2*PolyLog[3, (1 + d)*E^(2*a + 2*b*x)])/(8*b^2) - (3*x*PolyLog[4, (1 + d)*E^(2*a + 2*b*x)])/(8*b^3) + (3*PolyLog[5, (1 + d)*E^(2*a + 2*b*x)])/(16*b^4)}
{ArcCoth[1 + d + d*Coth[a + b*x]]*x^2, x, 6, (b*x^4)/12 + (1/3)*x^3*ArcCoth[1 + d + d*Coth[a + b*x]] - (1/6)*x^3*Log[1 - (1 + d)*E^(2*a + 2*b*x)] - (x^2*PolyLog[2, (1 + d)*E^(2*a + 2*b*x)])/(4*b) + (x*PolyLog[3, (1 + d)*E^(2*a + 2*b*x)])/(4*b^2) - PolyLog[4, (1 + d)*E^(2*a + 2*b*x)]/(8*b^3)}
{ArcCoth[1 + d + d*Coth[a + b*x]]*x^1, x, 5, (b*x^3)/6 + (1/2)*x^2*ArcCoth[1 + d + d*Coth[a + b*x]] - (1/4)*x^2*Log[1 - (1 + d)*E^(2*a + 2*b*x)] - (x*PolyLog[2, (1 + d)*E^(2*a + 2*b*x)])/(4*b) + PolyLog[3, (1 + d)*E^(2*a + 2*b*x)]/(8*b^2)}
{ArcCoth[1 + d + d*Coth[a + b*x]]*x^0, x, 4, (b*x^2)/2 + x*ArcCoth[1 + d + d*Coth[a + b*x]] - (1/2)*x*Log[1 - (1 + d)*E^(2*a + 2*b*x)] - PolyLog[2, (1 + d)*E^(2*a + 2*b*x)]/(4*b)}
{ArcCoth[1 + d + d*Coth[a + b*x]]/x^1, x, 0, Int[ArcCoth[1 + d + d*Coth[a + b*x]]/x, x]}


{ArcCoth[1 - d - d*Coth[a + b*x]]*x^3, x, 7, (b*x^5)/20 + (1/4)*x^4*ArcCoth[1 - d - d*Coth[a + b*x]] - (1/8)*x^4*Log[1 - (1 - d)*E^(2*a + 2*b*x)] - (x^3*PolyLog[2, (1 - d)*E^(2*a + 2*b*x)])/(4*b) + (3*x^2*PolyLog[3, (1 - d)*E^(2*a + 2*b*x)])/(8*b^2) - (3*x*PolyLog[4, (1 - d)*E^(2*a + 2*b*x)])/(8*b^3) + (3*PolyLog[5, (1 - d)*E^(2*a + 2*b*x)])/(16*b^4)}
{ArcCoth[1 - d - d*Coth[a + b*x]]*x^2, x, 6, (b*x^4)/12 + (1/3)*x^3*ArcCoth[1 - d - d*Coth[a + b*x]] - (1/6)*x^3*Log[1 - (1 - d)*E^(2*a + 2*b*x)] - (x^2*PolyLog[2, (1 - d)*E^(2*a + 2*b*x)])/(4*b) + (x*PolyLog[3, (1 - d)*E^(2*a + 2*b*x)])/(4*b^2) - PolyLog[4, (1 - d)*E^(2*a + 2*b*x)]/(8*b^3)}
{ArcCoth[1 - d - d*Coth[a + b*x]]*x^1, x, 5, (b*x^3)/6 + (1/2)*x^2*ArcCoth[1 - d - d*Coth[a + b*x]] - (1/4)*x^2*Log[1 - (1 - d)*E^(2*a + 2*b*x)] - (x*PolyLog[2, (1 - d)*E^(2*a + 2*b*x)])/(4*b) + PolyLog[3, (1 - d)*E^(2*a + 2*b*x)]/(8*b^2)}
{ArcCoth[1 - d - d*Coth[a + b*x]]*x^0, x, 4, (b*x^2)/2 + x*ArcCoth[1 - d - d*Coth[a + b*x]] - (1/2)*x*Log[1 - (1 - d)*E^(2*a + 2*b*x)] - PolyLog[2, (1 - d)*E^(2*a + 2*b*x)]/(4*b)}
{ArcCoth[1 - d - d*Coth[a + b*x]]/x^1, x, 0, Int[ArcCoth[1 - d - d*Coth[a + b*x]]/x, x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcCoth[c+d Tan[a+b x]]*)


{ArcCoth[Tan[a + b*x]], x, 7, x*ArcCoth[Tan[a + b*x]] - (1/2)*x*Log[1 - I*E^(2*I*a + 2*I*b*x)] + (1/2)*x*Log[1 + I*E^(2*I*a + 2*I*b*x)] - (I*PolyLog[2, (-I)*E^(2*I*a + 2*I*b*x)])/(4*b) + (I*PolyLog[2, I*E^(2*I*a + 2*I*b*x)])/(4*b)}
{ArcCoth[1 - I*d + d*Tan[a + b*x]], x, 4, (1/2)*I*b*x^2 + x*ArcCoth[1 - I*d + d*Tan[a + b*x]] - (1/2)*x*Log[1 + (1 - I*d)*E^(2*I*a + 2*I*b*x)] + (I*PolyLog[2, I*(I + d)*E^(2*I*a + 2*I*b*x)])/(4*b)}
{ArcCoth[1 + I*d - d*Tan[a + b*x]], x, 4, (1/2)*I*b*x^2 + x*ArcCoth[1 + I*d - d*Tan[a + b*x]] - (1/2)*x*Log[1 + (1 + I*d)*E^(2*I*a + 2*I*b*x)] + (I*PolyLog[2, -((1 + I*d)*E^(2*I*a + 2*I*b*x))])/(4*b)}
{ArcCoth[c + d*Tan[a + b*x]], x, 7, x*ArcCoth[c + d*Tan[a + b*x]] + (1/2)*x*Log[1 + ((1 - c + I*d)*E^(2*I*a + 2*I*b*x))/(1 - c - I*d)] - (1/2)*x*Log[1 + ((1 + c - I*d)*E^(2*I*a + 2*I*b*x))/(1 + c + I*d)] - (I*PolyLog[2, -(((1 - c + I*d)*E^(2*I*a + 2*I*b*x))/(1 - c - I*d))])/(4*b) + (I*PolyLog[2, -(((1 + c - I*d)*E^(2*I*a + 2*I*b*x))/(1 + c + I*d))])/(4*b)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcCoth[c+d Cot[a+b x]]*)


{ArcCoth[Cot[a + b*x]], x, 7, x*ArcCoth[Cot[a + b*x]] - (1/2)*x*Log[1 - I*E^(2*I*a + 2*I*b*x)] + (1/2)*x*Log[1 + I*E^(2*I*a + 2*I*b*x)] - (I*PolyLog[2, (-I)*E^(2*I*a + 2*I*b*x)])/(4*b) + (I*PolyLog[2, I*E^(2*I*a + 2*I*b*x)])/(4*b)}
{ArcCoth[1 + I*d + d*Cot[a + b*x]], x, 4, (1/2)*I*b*x^2 + x*ArcCoth[1 + I*d + d*Cot[a + b*x]] - (1/2)*x*Log[1 - (1 + I*d)*E^(2*I*a + 2*I*b*x)] + (I*PolyLog[2, (1 + I*d)*E^(2*I*a + 2*I*b*x)])/(4*b)}
{ArcCoth[1 - I*d - d*Cot[a + b*x]], x, 4, (1/2)*I*b*x^2 + x*ArcCoth[1 - I*d - d*Cot[a + b*x]] - (1/2)*x*Log[1 + I*(I + d)*E^(2*I*a + 2*I*b*x)] + (I*PolyLog[2, (1 - I*d)*E^(2*I*a + 2*I*b*x)])/(4*b)}
{ArcCoth[c + d*Cot[a + b*x]], x, 7, x*ArcCoth[c + d*Cot[a + b*x]] + (1/2)*x*Log[1 - ((1 - c - I*d)*E^(2*I*a + 2*I*b*x))/(1 - c + I*d)] - (1/2)*x*Log[1 - ((1 + c + I*d)*E^(2*I*a + 2*I*b*x))/(1 + c - I*d)] - (I*PolyLog[2, ((1 - c - I*d)*E^(2*I*a + 2*I*b*x))/(1 - c + I*d)])/(4*b) + (I*PolyLog[2, ((1 + c + I*d)*E^(2*I*a + 2*I*b*x))/(1 + c - I*d)])/(4*b)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcCoth[c+d Sinh[a+b x]]*)


(* Integrands of the form x^m*ArcCoth[Sinh[x]] where m is an integer *)
(* {ArcCoth[Sinh[x]], x, 6, 0}
{x*ArcCoth[Sinh[x]], x, 8, 0}
{x^2*ArcCoth[Sinh[x]], x, 10, 0} *)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcCoth[c+d Cosh[a+b x]]*)


(* Integrands of the form x^m*ArcCoth[Cosh[x]] where m is an integer *)
{ArcCoth[Cosh[x]], x, 4, x*ArcCoth[Cosh[x]] - 2*x*ArcTanh[E^x] - PolyLog[2, -E^x] + PolyLog[2, E^x]}
{x*ArcCoth[Cosh[x]], x, 6, (1/2)*x^2*ArcCoth[Cosh[x]] - x^2*ArcTanh[E^x] - x*PolyLog[2, -E^x] + x*PolyLog[2, E^x] + PolyLog[3, -E^x] - PolyLog[3, E^x]}
{x^2*ArcCoth[Cosh[x]], x, 8, (1/3)*x^3*ArcCoth[Cosh[x]] - (2/3)*x^3*ArcTanh[E^x] - x^2*PolyLog[2, -E^x] + x^2*PolyLog[2, E^x] + 2*x*PolyLog[3, -E^x] - 2*x*PolyLog[3, E^x] - 2*PolyLog[4, -E^x] + 2*PolyLog[4, E^x]}


(* ::Section::Closed:: *)
(*Integrands of the form u E^(n ArcCoth[a x])*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(n ArcCoth[a x])*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{E^ArcCoth[a*x]*x^m, x, 2, (x^(1 + m)*AppellF1[-1 - m, 1/2, -(1/2), -m, 1/(a*x), -(1/(a*x))])/(1 + m)}

{E^ArcCoth[a*x]*x^4, x, 8, (8*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/(15*a^4) + (3*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x^2)/(8*a^3) + (4*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x^3)/(15*a^2) + (Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x^4)/(4*a) + (Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x^5)/5 + (3*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(4*a^5)}
{E^ArcCoth[a*x]*x^3, x, 7, (2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/(3*a^3) + (3*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x^2)/(8*a^2) + (Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x^3)/(3*a) + (Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x^4)/4 + (3*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(4*a^4)}
{E^ArcCoth[a*x]*x^2, x, 6, (2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/(3*a^2) + (Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x^2)/(2*a) + (Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x^3)/3 + ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]]/a^3}
{E^ArcCoth[a*x]*x, x, 5, (Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/a + (Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x^2)/2 + ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]]/a^2}
{E^ArcCoth[a*x], x, 3, Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x + (2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{E^ArcCoth[a*x]/x, x, 4, -ArcSin[1/(a*x)] + 2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]]}
{E^ArcCoth[a*x]/x^2, x, 3, a*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)] - a*ArcSin[1/(a*x)]}
{E^ArcCoth[a*x]/x^3, x, 4, (a^2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/2 + (a^2*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2))/2 - (a^2*ArcSin[1/(a*x)])/2}
{E^ArcCoth[a*x]/x^4, x, 6, (a^3*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/2 + (a^3*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2))/6 + (a^2*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2))/(3*x) - (a^3*ArcSin[1/(a*x)])/2}
{E^ArcCoth[a*x]/x^5, x, 6, (2*a^4*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/3 + (a*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/(4*x^3) + (a^2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/(3*x^2) + (3*a^3*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/(8*x) - (3*a^4*ArcSin[1/(a*x)])/8}


{E^(2*ArcCoth[a*x])*x^m, x, 4, x^(1 + m)/(1 + m) - (2*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, a*x])/(1 + m)}

{E^(2*ArcCoth[a*x])*x^3, x, 4, (2*x)/a^3 + x^2/a^2 + (2*x^3)/(3*a) + x^4/4 + (2*Log[1 - a*x])/a^4}
{E^(2*ArcCoth[a*x])*x^2, x, 4, (2*x)/a^2 + x^2/a + x^3/3 + (2*Log[1 - a*x])/a^3}
{E^(2*ArcCoth[a*x])*x, x, 4, (2*x)/a + x^2/2 + (2*Log[1 - a*x])/a^2}
{E^(2*ArcCoth[a*x]), x, 4, x + (2*Log[1 - a*x])/a}
{E^(2*ArcCoth[a*x])/x, x, 4, -Log[x] + 2*Log[1 - a*x]}
{E^(2*ArcCoth[a*x])/x^2, x, 4, x^(-1) - 2*a*Log[x] + 2*a*Log[1 - a*x]}
{E^(2*ArcCoth[a*x])/x^3, x, 4, 1/(2*x^2) + (2*a)/x - 2*a^2*Log[x] + 2*a^2*Log[1 - a*x]}
{E^(2*ArcCoth[a*x])/x^4, x, 4, 1/(3*x^3) + a/x^2 + (2*a^2)/x - 2*a^3*Log[x] + 2*a^3*Log[1 - a*x]}


{E^(3*ArcCoth[a*x])*x^m, x, 2, (x^(1 + m)*AppellF1[-1 - m, 3/2, -(3/2), -m, 1/(a*x), -(1/(a*x))])/(1 + m)}

{E^(3*ArcCoth[a*x])*x^2, x, 7, -((26*Sqrt[1 + 1/(a*x)])/(3*a^3*Sqrt[1 - 1/(a*x)])) + (19*Sqrt[1 + 1/(a*x)]*x)/(6*a^2*Sqrt[1 - 1/(a*x)]) + (5*Sqrt[1 + 1/(a*x)]*x^2)/(6*a*Sqrt[1 - 1/(a*x)]) + ((1 + 1/(a*x))^(3/2)*x^3)/(3*Sqrt[1 - 1/(a*x)]) + (11*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a^3}
{E^(3*ArcCoth[a*x])*x, x, 6, -((7*Sqrt[1 + 1/(a*x)])/(a^2*Sqrt[1 - 1/(a*x)])) + (2*Sqrt[1 + 1/(a*x)]*x)/(a*Sqrt[1 - 1/(a*x)]) + ((1 + 1/(a*x))^(3/2)*x^2)/(2*Sqrt[1 - 1/(a*x)]) + (9*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a^2}
{E^(3*ArcCoth[a*x]), x, 4, -((6*Sqrt[1 + 1/(a*x)])/(a*Sqrt[1 - 1/(a*x)])) + ((1 + 1/(a*x))^(3/2)*x)/Sqrt[1 - 1/(a*x)] + (6*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{E^(3*ArcCoth[a*x])/x, x, 7, -2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)] - (2*(1 + 1/(a*x))^(3/2))/Sqrt[1 - 1/(a*x)] + ArcSin[1/(a*x)] + 2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]]}
{E^(3*ArcCoth[a*x])/x^2, x, 4, -3*a*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)] - (2*a*(1 + 1/(a*x))^(3/2))/Sqrt[1 - 1/(a*x)] + 3*a*ArcSin[1/(a*x)]}
{E^(3*ArcCoth[a*x])/x^3, x, 5, (-9*a^2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/2 - (3*a^2*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2))/2 - (a^2*(1 + 1/(a*x))^(5/2))/Sqrt[1 - 1/(a*x)] + (9*a^2*ArcSin[1/(a*x)])/2}
{E^(3*ArcCoth[a*x])/x^4, x, 6, (-11*a^3*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/2 - (11*a^3*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2))/6 - (a^3*(1 + 1/(a*x))^(5/2))/Sqrt[1 - 1/(a*x)] - (a^3*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(5/2))/3 + (11*a^3*ArcSin[1/(a*x)])/2}


{E^(4*ArcCoth[a*x])*x^m, x, 5, x^(1 + m)/(1 + m) + (4*x^(1 + m))/(1 - a*x) - 4*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, a*x]}

{E^(4*ArcCoth[a*x])*x^3, x, 4, (12*x)/a^3 + (4*x^2)/a^2 + (4*x^3)/(3*a) + x^4/4 + 4/(a^4*(1 - a*x)) + (16*Log[1 - a*x])/a^4}
{E^(4*ArcCoth[a*x])*x^2, x, 4, (8*x)/a^2 + (2*x^2)/a + x^3/3 + 4/(a^3*(1 - a*x)) + (12*Log[1 - a*x])/a^3}
{E^(4*ArcCoth[a*x])*x, x, 4, (4*x)/a + x^2/2 + 4/(a^2*(1 - a*x)) + (8*Log[1 - a*x])/a^2}
{E^(4*ArcCoth[a*x]), x, 4, x + 4/(a*(1 - a*x)) + (4*Log[1 - a*x])/a}
{E^(4*ArcCoth[a*x])/x, x, 4, 4/(1 - a*x) + Log[x]}
{E^(4*ArcCoth[a*x])/x^2, x, 4, -x^(-1) + (4*a)/(1 - a*x) + 4*a*Log[x] - 4*a*Log[1 - a*x]}
{E^(4*ArcCoth[a*x])/x^3, x, 4, -1/(2*x^2) - (4*a)/x + (4*a^2)/(1 - a*x) + 8*a^2*Log[x] - 8*a^2*Log[1 - a*x]}
{E^(4*ArcCoth[a*x])/x^4, x, 4, -1/(3*x^3) - (2*a)/x^2 - (8*a^2)/x + (4*a^3)/(1 - a*x) + 12*a^3*Log[x] - 12*a^3*Log[1 - a*x]}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{x^m/E^ArcCoth[a*x], x, 2, (x^(1 + m)*AppellF1[-1 - m, -(1/2), 1/2, -m, 1/(a*x), -(1/(a*x))])/(1 + m)}

{x^3/E^ArcCoth[a*x], x, 7, (-2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/(3*a^3) + (3*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x^2)/(8*a^2) - (Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x^3)/(3*a) + (Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x^4)/4 + (3*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(4*a^4)}
{x^2/E^ArcCoth[a*x], x, 6, (2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/(3*a^2) - (Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x^2)/(2*a) + (Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x^3)/3 - ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]]/a^3}
{x/E^ArcCoth[a*x], x, 5, -((Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/a) + (Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x^2)/2 + ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]]/a^2}
{E^(-ArcCoth[a*x]), x, 3, Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x - (2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{1/(E^ArcCoth[a*x]*x), x, 4, ArcSin[1/(a*x)] + 2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]]}
{1/(E^ArcCoth[a*x]*x^2), x, 3, -(a*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]) - a*ArcSin[1/(a*x)]}
{1/(E^ArcCoth[a*x]*x^3), x, 4, (a^2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/2 + (a^2*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)])/2 + (a^2*ArcSin[1/(a*x)])/2}
{1/(E^ArcCoth[a*x]*x^4), x, 6, -(a^3*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/2 - (a^3*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)])/6 + (a^2*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)])/(3*x) - (a^3*ArcSin[1/(a*x)])/2}
{1/(E^ArcCoth[a*x]*x^5), x, 6, (2*a^4*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/3 - (a*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/(4*x^3) + (a^2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/(3*x^2) - (3*a^3*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/(8*x) + (3*a^4*ArcSin[1/(a*x)])/8}


{x^m/E^(2*ArcCoth[a*x]), x, 4, x^(1 + m)/(1 + m) - (2*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, (-a)*x])/(1 + m)}

{x^3/E^(2*ArcCoth[a*x]), x, 4, (-2*x)/a^3 + x^2/a^2 - (2*x^3)/(3*a) + x^4/4 + (2*Log[1 + a*x])/a^4}
{x^2/E^(2*ArcCoth[a*x]), x, 4, (2*x)/a^2 - x^2/a + x^3/3 - (2*Log[1 + a*x])/a^3}
{x/E^(2*ArcCoth[a*x]), x, 4, (-2*x)/a + x^2/2 + (2*Log[1 + a*x])/a^2}
{E^(-2*ArcCoth[a*x]), x, 4, x - (2*Log[1 + a*x])/a}
{1/(E^(2*ArcCoth[a*x])*x), x, 4, -Log[x] + 2*Log[1 + a*x]}
{1/(E^(2*ArcCoth[a*x])*x^2), x, 4, x^(-1) + 2*a*Log[x] - 2*a*Log[1 + a*x]}
{1/(E^(2*ArcCoth[a*x])*x^3), x, 4, 1/(2*x^2) - (2*a)/x - 2*a^2*Log[x] + 2*a^2*Log[1 + a*x]}
{1/(E^(2*ArcCoth[a*x])*x^4), x, 4, 1/(3*x^3) - a/x^2 + (2*a^2)/x + 2*a^3*Log[x] - 2*a^3*Log[1 + a*x]}


{x^m/E^(3*ArcCoth[a*x]), x, 2, (x^(1 + m)*AppellF1[-1 - m, -(3/2), 3/2, -m, 1/(a*x), -(1/(a*x))])/(1 + m)}

{x^3/E^(3*ArcCoth[a*x]), x, 8, (-10*Sqrt[1 - 1/(a*x)])/(a^4*Sqrt[1 + 1/(a*x)]) - (29*Sqrt[1 - 1/(a*x)]*x)/(8*a^3*Sqrt[1 + 1/(a*x)]) + (11*Sqrt[1 - 1/(a*x)]*x^2)/(8*a^2*Sqrt[1 + 1/(a*x)]) - (Sqrt[1 - 1/(a*x)]*x^3)/(2*a*Sqrt[1 + 1/(a*x)]) + ((1 - 1/(a*x))^(3/2)*x^4)/(4*Sqrt[1 + 1/(a*x)]) + (51*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(4*a^4)}
{x^2/E^(3*ArcCoth[a*x]), x, 7, (26*Sqrt[1 - 1/(a*x)])/(3*a^3*Sqrt[1 + 1/(a*x)]) + (19*Sqrt[1 - 1/(a*x)]*x)/(6*a^2*Sqrt[1 + 1/(a*x)]) - (5*Sqrt[1 - 1/(a*x)]*x^2)/(6*a*Sqrt[1 + 1/(a*x)]) + ((1 - 1/(a*x))^(3/2)*x^3)/(3*Sqrt[1 + 1/(a*x)]) - (11*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a^3}
{x/E^(3*ArcCoth[a*x]), x, 6, (-7*Sqrt[1 - 1/(a*x)])/(a^2*Sqrt[1 + 1/(a*x)]) - (2*Sqrt[1 - 1/(a*x)]*x)/(a*Sqrt[1 + 1/(a*x)]) + ((1 - 1/(a*x))^(3/2)*x^2)/(2*Sqrt[1 + 1/(a*x)]) + (9*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a^2}
{E^(-3*ArcCoth[a*x]), x, 4, (6*Sqrt[1 - 1/(a*x)])/(a*Sqrt[1 + 1/(a*x)]) + ((1 - 1/(a*x))^(3/2)*x)/Sqrt[1 + 1/(a*x)] - (6*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{1/(E^(3*ArcCoth[a*x])*x), x, 7, (-2*(1 - 1/(a*x))^(3/2))/Sqrt[1 + 1/(a*x)] - 2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)] - ArcSin[1/(a*x)] + 2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]]}
{1/(E^(3*ArcCoth[a*x])*x^2), x, 4, (2*a*(1 - 1/(a*x))^(3/2))/Sqrt[1 + 1/(a*x)] + 3*a*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)] + 3*a*ArcSin[1/(a*x)]}
{1/(E^(3*ArcCoth[a*x])*x^3), x, 5, -((a^2*(1 - 1/(a*x))^(5/2))/Sqrt[1 + 1/(a*x)]) - (9*a^2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/2 - (3*a^2*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)])/2 - (9*a^2*ArcSin[1/(a*x)])/2}
{1/(E^(3*ArcCoth[a*x])*x^4), x, 6, (a^3*(1 - 1/(a*x))^(5/2))/Sqrt[1 + 1/(a*x)] + (11*a^3*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/2 + (11*a^3*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)])/6 + (a^3*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)])/3 + (11*a^3*ArcSin[1/(a*x)])/2}
{1/(E^(3*ArcCoth[a*x])*x^5), x, 7, (-(51/8))*a^4*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)] - (29/8)*a^4*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)] + (2*a*(1 - 1/(a*x))^(3/2))/(Sqrt[1 + 1/(a*x)]*x^3) - (9*a^2*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)])/(4*x^2) + (11*a^3*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)])/(4*x) - (51/8)*a^4*ArcSin[1/(a*x)]}


(* ::Subsubsection::Closed:: *)
(*n/2>0*)


{E^(ArcCoth[a*x]/2)*x^m, x, 2, (x^(1 + m)*AppellF1[-1 - m, 1/4, -(1/4), -m, 1/(a*x), -(1/(a*x))])/(1 + m)}

{E^(ArcCoth[a*x]/2)*x^4, x, 11, (611*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4)*x)/(1920*a^4) + (269*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4)*x^2)/(960*a^3) + (11*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4)*x^3)/(48*a^2) + (9*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4)*x^4)/(40*a) + ((1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4)*x^5)/5 - (31*ArcTan[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(128*a^5) + (31*ArcTanh[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(128*a^5)}
{E^(ArcCoth[a*x]/2)*x^3, x, 10, (83*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4)*x)/(192*a^3) + (29*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4)*x^2)/(96*a^2) + (7*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4)*x^3)/(24*a) + ((1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4)*x^4)/4 - (11*ArcTan[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(64*a^4) + (11*ArcTanh[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(64*a^4)}
{E^(ArcCoth[a*x]/2)*x^2, x, 9, (11*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4)*x)/(24*a^2) + (5*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4)*x^2)/(12*a) + ((1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4)*x^3)/3 - (3*ArcTan[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(8*a^3) + (3*ArcTanh[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(8*a^3)}
{E^(ArcCoth[a*x]/2)*x, x, 8, (3*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4)*x)/(4*a) + ((1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4)*x^2)/2 - ArcTan[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)]/(4*a^2) + ArcTanh[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)]/(4*a^2)}
{E^(ArcCoth[a*x]/2), x, 6, (1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4)*x - ArcTan[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)]/a + ArcTanh[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)]/a}
{E^(ArcCoth[a*x]/2)/x, x, 13, Sqrt[2]*ArcTan[1 - (Sqrt[2]*(1 + 1/(a*x))^(1/4))/(1 - 1/(a*x))^(1/4)] - Sqrt[2]*ArcTan[1 + (Sqrt[2]*(1 + 1/(a*x))^(1/4))/(1 - 1/(a*x))^(1/4)] + 2*ArcTan[(1 + 1/(a*x))^(1/4)/(1 - 1/(a*x))^(1/4)] + 2*ArcTanh[(1 + 1/(a*x))^(1/4)/(1 - 1/(a*x))^(1/4)] + Log[1 - (Sqrt[2]*(1 + 1/(a*x))^(1/4))/(1 - 1/(a*x))^(1/4) + Sqrt[1 + 1/(a*x)]/Sqrt[1 - 1/(a*x)]]/Sqrt[2] - Log[1 + (Sqrt[2]*(1 + 1/(a*x))^(1/4))/(1 - 1/(a*x))^(1/4) + Sqrt[1 + 1/(a*x)]/Sqrt[1 - 1/(a*x)]]/Sqrt[2]}
{E^(ArcCoth[a*x]/2)/x^2, x, 10, a*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4) - (a*ArcTan[1 - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/Sqrt[2] + (a*ArcTan[1 + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/Sqrt[2] + (a*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(2*Sqrt[2]) - (a*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(2*Sqrt[2])}
{E^(ArcCoth[a*x]/2)/x^3, x, 11, (a^2*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4))/4 + (a^2*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(5/4))/2 - (a^2*ArcTan[1 - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(4*Sqrt[2]) + (a^2*ArcTan[1 + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(4*Sqrt[2]) + (a^2*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(8*Sqrt[2]) - (a^2*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(8*Sqrt[2])}
{E^(ArcCoth[a*x]/2)/x^4, x, 12, (3*a^3*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4))/8 + (a^3*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(5/4))/12 + (a^2*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(5/4))/(3*x) - (3*a^3*ArcTan[1 - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(8*Sqrt[2]) + (3*a^3*ArcTan[1 + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(8*Sqrt[2]) + (3*a^3*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(16*Sqrt[2]) - (3*a^3*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(16*Sqrt[2])}


{E^((3*ArcCoth[a*x])/2)*x^m, x, 2, (x^(1 + m)*AppellF1[-1 - m, 3/4, -(3/4), -m, 1/(a*x), -(1/(a*x))])/(1 + m)}

{E^((3*ArcCoth[a*x])/2)*x^4, x, 11, (557*(1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4)*x)/(640*a^4) + (157*(1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4)*x^2)/(320*a^3) + (5*(1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4)*x^3)/(16*a^2) + (11*(1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4)*x^4)/(40*a) + ((1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4)*x^5)/5 + (237*ArcTan[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(128*a^5) + (237*ArcTanh[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(128*a^5)}
{E^((3*ArcCoth[a*x])/2)*x^3, x, 10, (63*(1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4)*x)/(64*a^3) + (15*(1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4)*x^2)/(32*a^2) + (3*(1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4)*x^3)/(8*a) + ((1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4)*x^4)/4 + (123*ArcTan[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(64*a^4) + (123*ArcTanh[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(64*a^4)}
{E^((3*ArcCoth[a*x])/2)*x^2, x, 9, (23*(1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4)*x)/(24*a^2) + (7*(1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4)*x^2)/(12*a) + ((1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4)*x^3)/3 + (17*ArcTan[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(8*a^3) + (17*ArcTanh[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(8*a^3)}
{E^((3*ArcCoth[a*x])/2)*x, x, 8, (5*(1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4)*x)/(4*a) + ((1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4)*x^2)/2 + (9*ArcTan[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(4*a^2) + (9*ArcTanh[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(4*a^2)}
{E^((3*ArcCoth[a*x])/2), x, 6, (1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4)*x + (3*ArcTan[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/a + (3*ArcTanh[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/a}
{E^((3*ArcCoth[a*x])/2)/x, x, 13, Sqrt[2]*ArcTan[1 - (Sqrt[2]*(1 + 1/(a*x))^(1/4))/(1 - 1/(a*x))^(1/4)] - Sqrt[2]*ArcTan[1 + (Sqrt[2]*(1 + 1/(a*x))^(1/4))/(1 - 1/(a*x))^(1/4)] - 2*ArcTan[(1 + 1/(a*x))^(1/4)/(1 - 1/(a*x))^(1/4)] + 2*ArcTanh[(1 + 1/(a*x))^(1/4)/(1 - 1/(a*x))^(1/4)] - Log[1 - (Sqrt[2]*(1 + 1/(a*x))^(1/4))/(1 - 1/(a*x))^(1/4) + Sqrt[1 + 1/(a*x)]/Sqrt[1 - 1/(a*x)]]/Sqrt[2] + Log[1 + (Sqrt[2]*(1 + 1/(a*x))^(1/4))/(1 - 1/(a*x))^(1/4) + Sqrt[1 + 1/(a*x)]/Sqrt[1 - 1/(a*x)]]/Sqrt[2]}
{E^((3*ArcCoth[a*x])/2)/x^2, x, 10, a*(1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4) - (3*a*ArcTan[1 - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/Sqrt[2] + (3*a*ArcTan[1 + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/Sqrt[2] - (3*a*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(2*Sqrt[2]) + (3*a*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(2*Sqrt[2])}
{E^((3*ArcCoth[a*x])/2)/x^3, x, 11, (3*a^2*(1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4))/4 + (a^2*(1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(7/4))/2 - (9*a^2*ArcTan[1 - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(4*Sqrt[2]) + (9*a^2*ArcTan[1 + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(4*Sqrt[2]) - (9*a^2*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(8*Sqrt[2]) + (9*a^2*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(8*Sqrt[2])}
{E^((3*ArcCoth[a*x])/2)/x^4, x, 12, (17*a^3*(1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4))/24 + (a^3*(1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(7/4))/4 + (a^2*(1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(7/4))/(3*x) - (17*a^3*ArcTan[1 - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(8*Sqrt[2]) + (17*a^3*ArcTan[1 + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(8*Sqrt[2]) - (17*a^3*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(16*Sqrt[2]) + (17*a^3*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(16*Sqrt[2])}


{E^((5*ArcCoth[a*x])/2)*x^m, x, 2, (x^(1 + m)*AppellF1[-1 - m, 5/4, -(5/4), -m, 1/(a*x), -(1/(a*x))])/(1 + m)}

{E^((5*ArcCoth[a*x])/2)*x^4, x, 12, (-26111*(1 + 1/(a*x))^(1/4))/(1920*a^5*(1 - 1/(a*x))^(1/4)) + (5533*(1 + 1/(a*x))^(1/4)*x)/(1920*a^4*(1 - 1/(a*x))^(1/4)) + (1189*(1 + 1/(a*x))^(1/4)*x^2)/(960*a^3*(1 - 1/(a*x))^(1/4)) + (181*(1 + 1/(a*x))^(1/4)*x^3)/(240*a^2*(1 - 1/(a*x))^(1/4)) + (13*(1 + 1/(a*x))^(1/4)*x^4)/(40*a*(1 - 1/(a*x))^(1/4)) + ((1 + 1/(a*x))^(5/4)*x^5)/(5*(1 - 1/(a*x))^(1/4)) - (1003*ArcTan[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(128*a^5) + (1003*ArcTanh[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(128*a^5)}
{E^((5*ArcCoth[a*x])/2)*x^3, x, 11, (-2467*(1 + 1/(a*x))^(1/4))/(192*a^4*(1 - 1/(a*x))^(1/4)) + (521*(1 + 1/(a*x))^(1/4)*x)/(192*a^3*(1 - 1/(a*x))^(1/4)) + (113*(1 + 1/(a*x))^(1/4)*x^2)/(96*a^2*(1 - 1/(a*x))^(1/4)) + (11*(1 + 1/(a*x))^(1/4)*x^3)/(24*a*(1 - 1/(a*x))^(1/4)) + ((1 + 1/(a*x))^(5/4)*x^4)/(4*(1 - 1/(a*x))^(1/4)) - (475*ArcTan[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(64*a^4) + (475*ArcTanh[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(64*a^4)}
{E^((5*ArcCoth[a*x])/2)*x^2, x, 10, (-287*(1 + 1/(a*x))^(1/4))/(24*a^3*(1 - 1/(a*x))^(1/4)) + (61*(1 + 1/(a*x))^(1/4)*x)/(24*a^2*(1 - 1/(a*x))^(1/4)) + (3*(1 + 1/(a*x))^(1/4)*x^2)/(4*a*(1 - 1/(a*x))^(1/4)) + ((1 + 1/(a*x))^(5/4)*x^3)/(3*(1 - 1/(a*x))^(1/4)) - (55*ArcTan[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(8*a^3) + (55*ArcTanh[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(8*a^3)}
{E^((5*ArcCoth[a*x])/2)*x, x, 9, (-43*(1 + 1/(a*x))^(1/4))/(4*a^2*(1 - 1/(a*x))^(1/4)) + (7*(1 + 1/(a*x))^(1/4)*x)/(4*a*(1 - 1/(a*x))^(1/4)) + ((1 + 1/(a*x))^(5/4)*x^2)/(2*(1 - 1/(a*x))^(1/4)) - (25*ArcTan[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(4*a^2) + (25*ArcTanh[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(4*a^2)}
{E^((5*ArcCoth[a*x])/2), x, 7, (-10*(1 + 1/(a*x))^(1/4))/(a*(1 - 1/(a*x))^(1/4)) + ((1 + 1/(a*x))^(5/4)*x)/(1 - 1/(a*x))^(1/4) - (5*ArcTan[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/a + (5*ArcTanh[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/a}
{E^((5*ArcCoth[a*x])/2)/x, x, 16, -4*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4) - (4*(1 + 1/(a*x))^(5/4))/(1 - 1/(a*x))^(1/4) + Sqrt[2]*ArcTan[1 - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)] - Sqrt[2]*ArcTan[1 + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)] - 2*ArcTan[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)] + 2*ArcTanh[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)] - Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)]/Sqrt[2] + Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)]/Sqrt[2]}
{E^((5*ArcCoth[a*x])/2)/x^2, x, 11, -5*a*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4) - (4*a*(1 + 1/(a*x))^(5/4))/(1 - 1/(a*x))^(1/4) + (5*a*ArcTan[1 - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/Sqrt[2] - (5*a*ArcTan[1 + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/Sqrt[2] - (5*a*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(2*Sqrt[2]) + (5*a*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(2*Sqrt[2])}
{E^((5*ArcCoth[a*x])/2)/x^3, x, 12, (-25*a^2*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4))/4 - (5*a^2*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(5/4))/2 - (2*a^2*(1 + 1/(a*x))^(9/4))/(1 - 1/(a*x))^(1/4) + (25*a^2*ArcTan[1 - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(4*Sqrt[2]) - (25*a^2*ArcTan[1 + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(4*Sqrt[2]) - (25*a^2*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(8*Sqrt[2]) + (25*a^2*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(8*Sqrt[2])}
{E^((5*ArcCoth[a*x])/2)/x^4, x, 13, (-55*a^3*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4))/8 - (11*a^3*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(5/4))/4 - (2*a^3*(1 + 1/(a*x))^(9/4))/(1 - 1/(a*x))^(1/4) - (a^3*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(9/4))/3 + (55*a^3*ArcTan[1 - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(8*Sqrt[2]) - (55*a^3*ArcTan[1 + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(8*Sqrt[2]) - (55*a^3*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(16*Sqrt[2]) + (55*a^3*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(16*Sqrt[2])}


(* ::Subsubsection::Closed:: *)
(*n/2<0*)


{x^m/E^(ArcCoth[a*x]/2), x, 2, (x^(1 + m)*AppellF1[-1 - m, -(1/4), 1/4, -m, 1/(a*x), -(1/(a*x))])/(1 + m)}

{x^4/E^(ArcCoth[a*x]/2), x, 11, (611*(1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4)*x)/(1920*a^4) - (269*(1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4)*x^2)/(960*a^3) + (11*(1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4)*x^3)/(48*a^2) - (9*(1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4)*x^4)/(40*a) + ((1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4)*x^5)/5 - (31*ArcTan[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(128*a^5) - (31*ArcTanh[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(128*a^5)}
{x^3/E^(ArcCoth[a*x]/2), x, 10, (-83*(1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4)*x)/(192*a^3) + (29*(1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4)*x^2)/(96*a^2) - (7*(1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4)*x^3)/(24*a) + ((1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4)*x^4)/4 + (11*ArcTan[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(64*a^4) + (11*ArcTanh[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(64*a^4)}
{x^2/E^(ArcCoth[a*x]/2), x, 9, (11*(1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4)*x)/(24*a^2) - (5*(1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4)*x^2)/(12*a) + ((1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4)*x^3)/3 - (3*ArcTan[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(8*a^3) - (3*ArcTanh[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(8*a^3)}
{x/E^(ArcCoth[a*x]/2), x, 8, (-3*(1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4)*x)/(4*a) + ((1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4)*x^2)/2 + ArcTan[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)]/(4*a^2) + ArcTanh[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)]/(4*a^2)}
{E^(-ArcCoth[a*x]/2), x, 6, (1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4)*x - ArcTan[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)]/a - ArcTanh[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)]/a}
{1/(E^(ArcCoth[a*x]/2)*x), x, 13, Sqrt[2]*ArcTan[1 - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)] - Sqrt[2]*ArcTan[1 + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)] + 2*ArcTan[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)] + 2*ArcTanh[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)] + Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)]/Sqrt[2] - Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)]/Sqrt[2]}
{1/(E^(ArcCoth[a*x]/2)*x^2), x, 10, -(a*(1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4)) - (a*ArcTan[1 - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/Sqrt[2] + (a*ArcTan[1 + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/Sqrt[2] - (a*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(2*Sqrt[2]) + (a*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(2*Sqrt[2])}
{1/(E^(ArcCoth[a*x]/2)*x^3), x, 11, (a^2*(1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4))/4 + (a^2*(1 - 1/(a*x))^(5/4)*(1 + 1/(a*x))^(3/4))/2 + (a^2*ArcTan[1 - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(4*Sqrt[2]) - (a^2*ArcTan[1 + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(4*Sqrt[2]) + (a^2*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(8*Sqrt[2]) - (a^2*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(8*Sqrt[2])}
{1/(E^(ArcCoth[a*x]/2)*x^4), x, 12, (-3*a^3*(1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4))/8 - (a^3*(1 - 1/(a*x))^(5/4)*(1 + 1/(a*x))^(3/4))/12 + (a^2*(1 - 1/(a*x))^(5/4)*(1 + 1/(a*x))^(3/4))/(3*x) - (3*a^3*ArcTan[1 - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(8*Sqrt[2]) + (3*a^3*ArcTan[1 + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(8*Sqrt[2]) - (3*a^3*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(16*Sqrt[2]) + (3*a^3*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(16*Sqrt[2])}


{x^m/E^((3*ArcCoth[a*x])/2), x, 2, (x^(1 + m)*AppellF1[-1 - m, -(3/4), 3/4, -m, 1/(a*x), -(1/(a*x))])/(1 + m)}

{x^4/E^((3*ArcCoth[a*x])/2), x, 11, (557*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4)*x)/(640*a^4) - (157*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4)*x^2)/(320*a^3) + (5*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4)*x^3)/(16*a^2) - (11*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4)*x^4)/(40*a) + ((1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4)*x^5)/5 + (237*ArcTan[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(128*a^5) - (237*ArcTanh[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(128*a^5)}
{x^3/E^((3*ArcCoth[a*x])/2), x, 10, (-63*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4)*x)/(64*a^3) + (15*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4)*x^2)/(32*a^2) - (3*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4)*x^3)/(8*a) + ((1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4)*x^4)/4 - (123*ArcTan[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(64*a^4) + (123*ArcTanh[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(64*a^4)}
{x^2/E^((3*ArcCoth[a*x])/2), x, 9, (23*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4)*x)/(24*a^2) - (7*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4)*x^2)/(12*a) + ((1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4)*x^3)/3 + (17*ArcTan[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(8*a^3) - (17*ArcTanh[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(8*a^3)}
{x/E^((3*ArcCoth[a*x])/2), x, 8, (-5*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4)*x)/(4*a) + ((1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4)*x^2)/2 - (9*ArcTan[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(4*a^2) + (9*ArcTanh[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(4*a^2)}
{E^((-3*ArcCoth[a*x])/2), x, 6, (1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4)*x + (3*ArcTan[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/a - (3*ArcTanh[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/a}
{1/(E^((3*ArcCoth[a*x])/2)*x), x, 13, Sqrt[2]*ArcTan[1 - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)] - Sqrt[2]*ArcTan[1 + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)] - 2*ArcTan[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)] + 2*ArcTanh[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)] - Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)]/Sqrt[2] + Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)]/Sqrt[2]}
{1/(E^((3*ArcCoth[a*x])/2)*x^2), x, 10, -(a*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4)) - (3*a*ArcTan[1 - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/Sqrt[2] + (3*a*ArcTan[1 + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/Sqrt[2] + (3*a*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(2*Sqrt[2]) - (3*a*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(2*Sqrt[2])}
{1/(E^((3*ArcCoth[a*x])/2)*x^3), x, 11, (3*a^2*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4))/4 + (a^2*(1 - 1/(a*x))^(7/4)*(1 + 1/(a*x))^(1/4))/2 + (9*a^2*ArcTan[1 - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(4*Sqrt[2]) - (9*a^2*ArcTan[1 + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(4*Sqrt[2]) - (9*a^2*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(8*Sqrt[2]) + (9*a^2*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(8*Sqrt[2])}
{1/(E^((3*ArcCoth[a*x])/2)*x^4), x, 12, (-17*a^3*(1 - 1/(a*x))^(3/4)*(1 + 1/(a*x))^(1/4))/24 - (a^3*(1 - 1/(a*x))^(7/4)*(1 + 1/(a*x))^(1/4))/4 + (a^2*(1 - 1/(a*x))^(7/4)*(1 + 1/(a*x))^(1/4))/(3*x) - (17*a^3*ArcTan[1 - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(8*Sqrt[2]) + (17*a^3*ArcTan[1 + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(8*Sqrt[2]) + (17*a^3*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(16*Sqrt[2]) - (17*a^3*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(16*Sqrt[2])}


{x^m/E^((5*ArcCoth[a*x])/2), x, 2, (x^(1 + m)*AppellF1[-1 - m, -(5/4), 5/4, -m, 1/(a*x), -(1/(a*x))])/(1 + m)}

{x^4/E^((5*ArcCoth[a*x])/2), x, 12, (26111*(1 - 1/(a*x))^(1/4))/(1920*a^5*(1 + 1/(a*x))^(1/4)) + (5533*(1 - 1/(a*x))^(1/4)*x)/(1920*a^4*(1 + 1/(a*x))^(1/4)) - (1189*(1 - 1/(a*x))^(1/4)*x^2)/(960*a^3*(1 + 1/(a*x))^(1/4)) + (181*(1 - 1/(a*x))^(1/4)*x^3)/(240*a^2*(1 + 1/(a*x))^(1/4)) - (13*(1 - 1/(a*x))^(1/4)*x^4)/(40*a*(1 + 1/(a*x))^(1/4)) + ((1 - 1/(a*x))^(5/4)*x^5)/(5*(1 + 1/(a*x))^(1/4)) - (1003*ArcTan[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(128*a^5) - (1003*ArcTanh[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(128*a^5)}
{x^3/E^((5*ArcCoth[a*x])/2), x, 11, (-2467*(1 - 1/(a*x))^(1/4))/(192*a^4*(1 + 1/(a*x))^(1/4)) - (521*(1 - 1/(a*x))^(1/4)*x)/(192*a^3*(1 + 1/(a*x))^(1/4)) + (113*(1 - 1/(a*x))^(1/4)*x^2)/(96*a^2*(1 + 1/(a*x))^(1/4)) - (11*(1 - 1/(a*x))^(1/4)*x^3)/(24*a*(1 + 1/(a*x))^(1/4)) + ((1 - 1/(a*x))^(5/4)*x^4)/(4*(1 + 1/(a*x))^(1/4)) + (475*ArcTan[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(64*a^4) + (475*ArcTanh[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(64*a^4)}
{x^2/E^((5*ArcCoth[a*x])/2), x, 10, (287*(1 - 1/(a*x))^(1/4))/(24*a^3*(1 + 1/(a*x))^(1/4)) + (61*(1 - 1/(a*x))^(1/4)*x)/(24*a^2*(1 + 1/(a*x))^(1/4)) - (3*(1 - 1/(a*x))^(1/4)*x^2)/(4*a*(1 + 1/(a*x))^(1/4)) + ((1 - 1/(a*x))^(5/4)*x^3)/(3*(1 + 1/(a*x))^(1/4)) - (55*ArcTan[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(8*a^3) - (55*ArcTanh[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(8*a^3)}
{x/E^((5*ArcCoth[a*x])/2), x, 9, (-43*(1 - 1/(a*x))^(1/4))/(4*a^2*(1 + 1/(a*x))^(1/4)) - (7*(1 - 1/(a*x))^(1/4)*x)/(4*a*(1 + 1/(a*x))^(1/4)) + ((1 - 1/(a*x))^(5/4)*x^2)/(2*(1 + 1/(a*x))^(1/4)) + (25*ArcTan[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(4*a^2) + (25*ArcTanh[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/(4*a^2)}
{E^((-5*ArcCoth[a*x])/2), x, 7, (10*(1 - 1/(a*x))^(1/4))/(a*(1 + 1/(a*x))^(1/4)) + ((1 - 1/(a*x))^(5/4)*x)/(1 + 1/(a*x))^(1/4) - (5*ArcTan[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/a - (5*ArcTanh[(1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4)])/a}
{1/(E^((5*ArcCoth[a*x])/2)*x), x, 16, (-4*(1 - 1/(a*x))^(5/4))/(1 + 1/(a*x))^(1/4) - 4*(1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4) + Sqrt[2]*ArcTan[1 - (Sqrt[2]*(1 + 1/(a*x))^(1/4))/(1 - 1/(a*x))^(1/4)] - Sqrt[2]*ArcTan[1 + (Sqrt[2]*(1 + 1/(a*x))^(1/4))/(1 - 1/(a*x))^(1/4)] - 2*ArcTan[(1 + 1/(a*x))^(1/4)/(1 - 1/(a*x))^(1/4)] + 2*ArcTanh[(1 + 1/(a*x))^(1/4)/(1 - 1/(a*x))^(1/4)] - Log[1 - (Sqrt[2]*(1 + 1/(a*x))^(1/4))/(1 - 1/(a*x))^(1/4) + Sqrt[1 + 1/(a*x)]/Sqrt[1 - 1/(a*x)]]/Sqrt[2] + Log[1 + (Sqrt[2]*(1 + 1/(a*x))^(1/4))/(1 - 1/(a*x))^(1/4) + Sqrt[1 + 1/(a*x)]/Sqrt[1 - 1/(a*x)]]/Sqrt[2]}
{1/(E^((5*ArcCoth[a*x])/2)*x^2), x, 11, (4*a*(1 - 1/(a*x))^(5/4))/(1 + 1/(a*x))^(1/4) + 5*a*(1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4) + (5*a*ArcTan[1 - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/Sqrt[2] - (5*a*ArcTan[1 + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/Sqrt[2] + (5*a*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(2*Sqrt[2]) - (5*a*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(2*Sqrt[2])}
{1/(E^((5*ArcCoth[a*x])/2)*x^3), x, 12, (-2*a^2*(1 - 1/(a*x))^(9/4))/(1 + 1/(a*x))^(1/4) - (25*a^2*(1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4))/4 - (5*a^2*(1 - 1/(a*x))^(5/4)*(1 + 1/(a*x))^(3/4))/2 - (25*a^2*ArcTan[1 - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(4*Sqrt[2]) + (25*a^2*ArcTan[1 + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(4*Sqrt[2]) - (25*a^2*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(8*Sqrt[2]) + (25*a^2*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(8*Sqrt[2])}
{1/(E^((5*ArcCoth[a*x])/2)*x^4), x, 13, (2*a^3*(1 - 1/(a*x))^(9/4))/(1 + 1/(a*x))^(1/4) + (55*a^3*(1 - 1/(a*x))^(1/4)*(1 + 1/(a*x))^(3/4))/8 + (11*a^3*(1 - 1/(a*x))^(5/4)*(1 + 1/(a*x))^(3/4))/4 + (a^3*(1 - 1/(a*x))^(9/4)*(1 + 1/(a*x))^(3/4))/3 + (55*a^3*ArcTan[1 - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(8*Sqrt[2]) - (55*a^3*ArcTan[1 + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(8*Sqrt[2]) + (55*a^3*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] - (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(16*Sqrt[2]) - (55*a^3*Log[1 + Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)] + (Sqrt[2]*(1 - 1/(a*x))^(1/4))/(1 + 1/(a*x))^(1/4)])/(16*Sqrt[2])}


(* ::Subsubsection::Closed:: *)
(*n/3>0*)


{E^(ArcCoth[x]/3)*x^m, x, 2, (6/5)*2^(1/6)*(1 - 1/x)^(5/6)*(1/x)^m*x^m*AppellF1[5/6, 2 + m, -(1/6), 11/6, 1 - 1/x, (1/2)*(1 - 1/x)]}

{E^(ArcCoth[x]/3)*x^2, x, 13, (11/27)*(1 - 1/x)^(5/6)*(1 + 1/x)^(1/6)*x + (7/18)*(1 - 1/x)^(5/6)*(1 + 1/x)^(1/6)*x^2 + (1/3)*(1 - 1/x)^(5/6)*(1 + 1/x)^(1/6)*x^3 + (19*ArcTan[(1 - (2*(1 - 1/x)^(1/6))/(1 + 1/x)^(1/6))/Sqrt[3]])/(54*Sqrt[3]) - (19*ArcTan[(1 + (2*(1 - 1/x)^(1/6))/(1 + 1/x)^(1/6))/Sqrt[3]])/(54*Sqrt[3]) + (19/81)*ArcTanh[(1 - 1/x)^(1/6)/(1 + 1/x)^(1/6)] + (19/162)*ArcTanh[(1 - 1/x)^(1/6)/((1 + (1 - 1/x)^(1/3)/(1 + 1/x)^(1/3))*(1 + 1/x)^(1/6))]}
{E^(ArcCoth[x]/3)*x, x, 12, (2/3)*(1 - 1/x)^(5/6)*(1 + 1/x)^(1/6)*x + (1/2)*(1 - 1/x)^(5/6)*(1 + 1/x)^(1/6)*x^2 + ArcTan[(1 - (2*(1 - 1/x)^(1/6))/(1 + 1/x)^(1/6))/Sqrt[3]]/(6*Sqrt[3]) - ArcTan[(1 + (2*(1 - 1/x)^(1/6))/(1 + 1/x)^(1/6))/Sqrt[3]]/(6*Sqrt[3]) + (1/9)*ArcTanh[(1 - 1/x)^(1/6)/(1 + 1/x)^(1/6)] + (1/18)*ArcTanh[(1 - 1/x)^(1/6)/((1 + (1 - 1/x)^(1/3)/(1 + 1/x)^(1/3))*(1 + 1/x)^(1/6))]}
{E^(ArcCoth[x]/3), x, 10, (1 - 1/x)^(5/6)*(1 + 1/x)^(1/6)*x + ArcTan[(1 - (2*(1 - 1/x)^(1/6))/(1 + 1/x)^(1/6))/Sqrt[3]]/Sqrt[3] - ArcTan[(1 + (2*(1 - 1/x)^(1/6))/(1 + 1/x)^(1/6))/Sqrt[3]]/Sqrt[3] + (2/3)*ArcTanh[(1 - 1/x)^(1/6)/(1 + 1/x)^(1/6)] + (1/3)*ArcTanh[(1 - 1/x)^(1/6)/((1 + (1 - 1/x)^(1/3)/(1 + 1/x)^(1/3))*(1 + 1/x)^(1/6))]}
{E^(ArcCoth[x]/3)/x, x, 17, -(Sqrt[3]*ArcTan[(1 - (2*(1 + x^(-1))^(1/6))/(1 - x^(-1))^(1/6))/Sqrt[3]]) + ArcTan[Sqrt[3] - (2*(1 + x^(-1))^(1/6))/(1 - x^(-1))^(1/6)] + Sqrt[3]*ArcTan[(1 + (2*(1 + x^(-1))^(1/6))/(1 - x^(-1))^(1/6))/Sqrt[3]] - ArcTan[Sqrt[3] + (2*(1 + x^(-1))^(1/6))/(1 - x^(-1))^(1/6)] - 2*ArcTan[(1 + x^(-1))^(1/6)/(1 - x^(-1))^(1/6)] + 2*ArcTanh[(1 + x^(-1))^(1/6)/(1 - x^(-1))^(1/6)] + ArcTanh[(1 + x^(-1))^(1/6)/((1 + (1 + x^(-1))^(1/3)/(1 - x^(-1))^(1/3))*(1 - x^(-1))^(1/6))] - Sqrt[3]*ArcTanh[(Sqrt[3]*(1 + x^(-1))^(1/6))/((1 + (1 + x^(-1))^(1/3)/(1 - x^(-1))^(1/3))*(1 - x^(-1))^(1/6))]}
{E^(ArcCoth[x]/3)/x^2, x, 10, (1 - 1/x)^(5/6)*(1 + 1/x)^(1/6) - (1/3)*ArcTan[Sqrt[3] - (2*(1 - 1/x)^(1/6))/(1 + 1/x)^(1/6)] + (1/3)*ArcTan[Sqrt[3] + (2*(1 - 1/x)^(1/6))/(1 + 1/x)^(1/6)] + (2/3)*ArcTan[(1 - 1/x)^(1/6)/(1 + 1/x)^(1/6)] - ArcTanh[(Sqrt[3]*(1 - 1/x)^(1/6))/((1 + (1 - 1/x)^(1/3)/(1 + 1/x)^(1/3))*(1 + 1/x)^(1/6))]/Sqrt[3]}
{E^(ArcCoth[x]/3)/x^3, x, 11, (1/6)*(1 - 1/x)^(5/6)*(1 + 1/x)^(1/6) + (1/2)*(1 - 1/x)^(5/6)*(1 + 1/x)^(7/6) - (1/18)*ArcTan[Sqrt[3] - (2*(1 - 1/x)^(1/6))/(1 + 1/x)^(1/6)] + (1/18)*ArcTan[Sqrt[3] + (2*(1 - 1/x)^(1/6))/(1 + 1/x)^(1/6)] + (1/9)*ArcTan[(1 - 1/x)^(1/6)/(1 + 1/x)^(1/6)] - ArcTanh[(Sqrt[3]*(1 - 1/x)^(1/6))/((1 + (1 - 1/x)^(1/3)/(1 + 1/x)^(1/3))*(1 + 1/x)^(1/6))]/(6*Sqrt[3])}
{E^(ArcCoth[x]/3)/x^4, x, 12, (19/54)*(1 - 1/x)^(5/6)*(1 + 1/x)^(1/6) + (1/18)*(1 - 1/x)^(5/6)*(1 + 1/x)^(7/6) + ((1 - 1/x)^(5/6)*(1 + 1/x)^(7/6))/(3*x) - (19/162)*ArcTan[Sqrt[3] - (2*(1 - 1/x)^(1/6))/(1 + 1/x)^(1/6)] + (19/162)*ArcTan[Sqrt[3] + (2*(1 - 1/x)^(1/6))/(1 + 1/x)^(1/6)] + (19/81)*ArcTan[(1 - 1/x)^(1/6)/(1 + 1/x)^(1/6)] - (19*ArcTanh[(Sqrt[3]*(1 - 1/x)^(1/6))/((1 + (1 - 1/x)^(1/3)/(1 + 1/x)^(1/3))*(1 + 1/x)^(1/6))])/(54*Sqrt[3])}


{E^((2*ArcCoth[x])/3)*x^m, x, 2, (3*(1 - 1/x)^(2/3)*(1/x)^m*x^m*AppellF1[2/3, 2 + m, -(1/3), 5/3, 1 - 1/x, (1/2)*(1 - 1/x)])/2^(2/3)}

{E^((2*ArcCoth[x])/3)*x^2, x, 11, (14/27)*(1 - 1/x)^(2/3)*(1 + 1/x)^(1/3)*x + (4/9)*(1 - 1/x)^(2/3)*(1 + 1/x)^(1/3)*x^2 + (1/3)*(1 - 1/x)^(2/3)*(1 + 1/x)^(1/3)*x^3 - (22*ArcTan[(1 + (2*(1 - 1/x)^(1/3))/(1 + 1/x)^(1/3))/Sqrt[3]])/(27*Sqrt[3]) - (22/81)*Log[1 - (1 - 1/x)^(1/3)/(1 + 1/x)^(1/3)] + (11/81)*Log[1 + (1 - 1/x)^(2/3)/(1 + 1/x)^(2/3) + (1 - 1/x)^(1/3)/(1 + 1/x)^(1/3)]}
{E^((2*ArcCoth[x])/3)*x, x, 10, (5/6)*(1 - 1/x)^(2/3)*(1 + 1/x)^(1/3)*x + (1/2)*(1 - 1/x)^(2/3)*(1 + 1/x)^(1/3)*x^2 - (2*ArcTan[(1 + (2*(1 - 1/x)^(1/3))/(1 + 1/x)^(1/3))/Sqrt[3]])/(3*Sqrt[3]) - (2/9)*Log[1 - (1 - 1/x)^(1/3)/(1 + 1/x)^(1/3)] + (1/9)*Log[1 + (1 - 1/x)^(2/3)/(1 + 1/x)^(2/3) + (1 - 1/x)^(1/3)/(1 + 1/x)^(1/3)]}
{E^((2*ArcCoth[x])/3), x, 8, (1 - 1/x)^(2/3)*(1 + 1/x)^(1/3)*x - (2*ArcTan[(1 + (2*(1 - 1/x)^(1/3))/(1 + 1/x)^(1/3))/Sqrt[3]])/Sqrt[3] - (2/3)*Log[1 - (1 - 1/x)^(1/3)/(1 + 1/x)^(1/3)] + (1/3)*Log[1 + (1 - 1/x)^(2/3)/(1 + 1/x)^(2/3) + (1 - 1/x)^(1/3)/(1 + 1/x)^(1/3)]}
{E^((2*ArcCoth[x])/3)/x, x, 13, Sqrt[3]*ArcTan[(1 - (2*(1 + x^(-1))^(1/3))/(1 - x^(-1))^(1/3))/Sqrt[3]] + Sqrt[3]*ArcTan[(1 + (2*(1 + x^(-1))^(1/3))/(1 - x^(-1))^(1/3))/Sqrt[3]] - Log[1 - (1 + x^(-1))^(1/3)/(1 - x^(-1))^(1/3)] - Log[1 + (1 + x^(-1))^(1/3)/(1 - x^(-1))^(1/3)] + Log[1 - (1 + x^(-1))^(1/3)/(1 - x^(-1))^(1/3) + (1 + x^(-1))^(2/3)/(1 - x^(-1))^(2/3)]/2 + Log[1 + (1 + x^(-1))^(1/3)/(1 - x^(-1))^(1/3) + (1 + x^(-1))^(2/3)/(1 - x^(-1))^(2/3)]/2}
{E^((2*ArcCoth[x])/3)/x^2, x, 8, (1 - 1/x)^(2/3)*(1 + 1/x)^(1/3) - (2*ArcTan[(1 - (2*(1 - 1/x)^(1/3))/(1 + 1/x)^(1/3))/Sqrt[3]])/Sqrt[3] + (1/3)*Log[1 + (1 - 1/x)^(2/3)/(1 + 1/x)^(2/3) - (1 - 1/x)^(1/3)/(1 + 1/x)^(1/3)] - (2/3)*Log[1 + (1 - 1/x)^(1/3)/(1 + 1/x)^(1/3)]}
{E^((2*ArcCoth[x])/3)/x^3, x, 9, (1/3)*(1 - 1/x)^(2/3)*(1 + 1/x)^(1/3) + (1/2)*(1 - 1/x)^(2/3)*(1 + 1/x)^(4/3) - (2*ArcTan[(1 - (2*(1 - 1/x)^(1/3))/(1 + 1/x)^(1/3))/Sqrt[3]])/(3*Sqrt[3]) + (1/9)*Log[1 + (1 - 1/x)^(2/3)/(1 + 1/x)^(2/3) - (1 - 1/x)^(1/3)/(1 + 1/x)^(1/3)] - (2/9)*Log[1 + (1 - 1/x)^(1/3)/(1 + 1/x)^(1/3)]}


(* ::Subsubsection::Closed:: *)
(*n/4>0*)


{E^(ArcCoth[a*x]/4)*x^m, x, 2, (x^(1 + m)*AppellF1[-1 - m, 1/8, -(1/8), -m, 1/(a*x), -(1/(a*x))])/(1 + m)}

{E^(ArcCoth[a*x]/4)*x^2, x, 17, (37*(1 - 1/(a*x))^(7/8)*(1 + 1/(a*x))^(1/8)*x)/(96*a^2) + (3*(1 - 1/(a*x))^(7/8)*(1 + 1/(a*x))^(1/8)*x^2)/(8*a) + (1/3)*(1 - 1/(a*x))^(7/8)*(1 + 1/(a*x))^(1/8)*x^3 + (11*ArcTan[1 - (Sqrt[2]*(1 - 1/(a*x))^(1/8))/(1 + 1/(a*x))^(1/8)])/(64*Sqrt[2]*a^3) - (11*ArcTan[1 + (Sqrt[2]*(1 - 1/(a*x))^(1/8))/(1 + 1/(a*x))^(1/8)])/(64*Sqrt[2]*a^3) - (11*ArcTan[(1 - 1/(a*x))^(1/8)/(1 + 1/(a*x))^(1/8)])/(64*a^3) + (11*ArcTanh[(1 - 1/(a*x))^(1/8)/(1 + 1/(a*x))^(1/8)])/(64*a^3) - (11*Log[1 + (1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4) - (Sqrt[2]*(1 - 1/(a*x))^(1/8))/(1 + 1/(a*x))^(1/8)])/(128*Sqrt[2]*a^3) + (11*Log[1 + (1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4) + (Sqrt[2]*(1 - 1/(a*x))^(1/8))/(1 + 1/(a*x))^(1/8)])/(128*Sqrt[2]*a^3)}
{E^(ArcCoth[a*x]/4)*x^1, x, 16, (5*(1 - 1/(a*x))^(7/8)*(1 + 1/(a*x))^(1/8)*x)/(8*a) + (1/2)*(1 - 1/(a*x))^(7/8)*(1 + 1/(a*x))^(1/8)*x^2 + ArcTan[1 - (Sqrt[2]*(1 - 1/(a*x))^(1/8))/(1 + 1/(a*x))^(1/8)]/(16*Sqrt[2]*a^2) - ArcTan[1 + (Sqrt[2]*(1 - 1/(a*x))^(1/8))/(1 + 1/(a*x))^(1/8)]/(16*Sqrt[2]*a^2) - ArcTan[(1 - 1/(a*x))^(1/8)/(1 + 1/(a*x))^(1/8)]/(16*a^2) + ArcTanh[(1 - 1/(a*x))^(1/8)/(1 + 1/(a*x))^(1/8)]/(16*a^2) - Log[1 + (1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4) - (Sqrt[2]*(1 - 1/(a*x))^(1/8))/(1 + 1/(a*x))^(1/8)]/(32*Sqrt[2]*a^2) + Log[1 + (1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4) + (Sqrt[2]*(1 - 1/(a*x))^(1/8))/(1 + 1/(a*x))^(1/8)]/(32*Sqrt[2]*a^2)}
{E^(ArcCoth[a*x]/4)*x^0, x, 14, (1 - 1/(a*x))^(7/8)*(1 + 1/(a*x))^(1/8)*x + ArcTan[1 - (Sqrt[2]*(1 - 1/(a*x))^(1/8))/(1 + 1/(a*x))^(1/8)]/(2*Sqrt[2]*a) - ArcTan[1 + (Sqrt[2]*(1 - 1/(a*x))^(1/8))/(1 + 1/(a*x))^(1/8)]/(2*Sqrt[2]*a) - ArcTan[(1 - 1/(a*x))^(1/8)/(1 + 1/(a*x))^(1/8)]/(2*a) + ArcTanh[(1 - 1/(a*x))^(1/8)/(1 + 1/(a*x))^(1/8)]/(2*a) - Log[1 + (1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4) - (Sqrt[2]*(1 - 1/(a*x))^(1/8))/(1 + 1/(a*x))^(1/8)]/(4*Sqrt[2]*a) + Log[1 + (1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4) + (Sqrt[2]*(1 - 1/(a*x))^(1/8))/(1 + 1/(a*x))^(1/8)]/(4*Sqrt[2]*a)}
{E^(ArcCoth[a*x]/4)/x^1, x, 25, Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*ArcTan[(Sqrt[2 - Sqrt[2]] - (2*(1 + 1/(a*x))^(1/8))/(1 - 1/(a*x))^(1/8))/Sqrt[2 + Sqrt[2]]] - (1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*ArcTan[(Sqrt[2 + Sqrt[2]] - (2*(1 + 1/(a*x))^(1/8))/(1 - 1/(a*x))^(1/8))/Sqrt[2 - Sqrt[2]]] - Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*ArcTan[(Sqrt[2 - Sqrt[2]] + (2*(1 + 1/(a*x))^(1/8))/(1 - 1/(a*x))^(1/8))/Sqrt[2 + Sqrt[2]]] + (1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*ArcTan[(Sqrt[2 + Sqrt[2]] + (2*(1 + 1/(a*x))^(1/8))/(1 - 1/(a*x))^(1/8))/Sqrt[2 - Sqrt[2]]] - Sqrt[2]*ArcTan[1 - (Sqrt[2]*(1 + 1/(a*x))^(1/8))/(1 - 1/(a*x))^(1/8)] + Sqrt[2]*ArcTan[1 + (Sqrt[2]*(1 + 1/(a*x))^(1/8))/(1 - 1/(a*x))^(1/8)] + 2*ArcTan[(1 + 1/(a*x))^(1/8)/(1 - 1/(a*x))^(1/8)] + 2*ArcTanh[(1 + 1/(a*x))^(1/8)/(1 - 1/(a*x))^(1/8)] + (1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*ArcTanh[(Sqrt[2 - Sqrt[2]]*(1 + 1/(a*x))^(1/8))/((1 + (1 + 1/(a*x))^(1/4)/(1 - 1/(a*x))^(1/4))*(1 - 1/(a*x))^(1/8))] - Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*ArcTanh[(Sqrt[2 + Sqrt[2]]*(1 + 1/(a*x))^(1/8))/((1 + (1 + 1/(a*x))^(1/4)/(1 - 1/(a*x))^(1/4))*(1 - 1/(a*x))^(1/8))] - Log[1 - (Sqrt[2]*(1 + 1/(a*x))^(1/8))/(1 - 1/(a*x))^(1/8) + (1 + 1/(a*x))^(1/4)/(1 - 1/(a*x))^(1/4)]/Sqrt[2] + Log[1 + (Sqrt[2]*(1 + 1/(a*x))^(1/8))/(1 - 1/(a*x))^(1/8) + (1 + 1/(a*x))^(1/4)/(1 - 1/(a*x))^(1/4)]/Sqrt[2]}
{E^(ArcCoth[a*x]/4)/x^2, x, 16, a*(1 - 1/(a*x))^(7/8)*(1 + 1/(a*x))^(1/8) - (1/4)*Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*a*ArcTan[(Sqrt[2 - Sqrt[2]] - (2*(1 - 1/(a*x))^(1/8))/(1 + 1/(a*x))^(1/8))/Sqrt[2 + Sqrt[2]]] + (1/4)*(1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*a*ArcTan[(Sqrt[2 + Sqrt[2]] - (2*(1 - 1/(a*x))^(1/8))/(1 + 1/(a*x))^(1/8))/Sqrt[2 - Sqrt[2]]] + (1/4)*Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*a*ArcTan[(Sqrt[2 - Sqrt[2]] + (2*(1 - 1/(a*x))^(1/8))/(1 + 1/(a*x))^(1/8))/Sqrt[2 + Sqrt[2]]] - (1/4)*(1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*a*ArcTan[(Sqrt[2 + Sqrt[2]] + (2*(1 - 1/(a*x))^(1/8))/(1 + 1/(a*x))^(1/8))/Sqrt[2 - Sqrt[2]]] + (1/4)*(1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*a*ArcTanh[(Sqrt[2 - Sqrt[2]]*(1 - 1/(a*x))^(1/8))/((1 + (1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4))*(1 + 1/(a*x))^(1/8))] - (1/4)*Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*a*ArcTanh[(Sqrt[2 + Sqrt[2]]*(1 - 1/(a*x))^(1/8))/((1 + (1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4))*(1 + 1/(a*x))^(1/8))]}
{E^(ArcCoth[a*x]/4)/x^3, x, 17, (1/8)*a^2*(1 - 1/(a*x))^(7/8)*(1 + 1/(a*x))^(1/8) + (1/2)*a^2*(1 - 1/(a*x))^(7/8)*(1 + 1/(a*x))^(9/8) - (1/32)*Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*a^2*ArcTan[(Sqrt[2 - Sqrt[2]] - (2*(1 - 1/(a*x))^(1/8))/(1 + 1/(a*x))^(1/8))/Sqrt[2 + Sqrt[2]]] + (1/32)*(1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*a^2*ArcTan[(Sqrt[2 + Sqrt[2]] - (2*(1 - 1/(a*x))^(1/8))/(1 + 1/(a*x))^(1/8))/Sqrt[2 - Sqrt[2]]] + (1/32)*Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*a^2*ArcTan[(Sqrt[2 - Sqrt[2]] + (2*(1 - 1/(a*x))^(1/8))/(1 + 1/(a*x))^(1/8))/Sqrt[2 + Sqrt[2]]] - (1/32)*(1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*a^2*ArcTan[(Sqrt[2 + Sqrt[2]] + (2*(1 - 1/(a*x))^(1/8))/(1 + 1/(a*x))^(1/8))/Sqrt[2 - Sqrt[2]]] + (1/32)*(1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*a^2*ArcTanh[(Sqrt[2 - Sqrt[2]]*(1 - 1/(a*x))^(1/8))/((1 + (1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4))*(1 + 1/(a*x))^(1/8))] - (1/32)*Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*a^2*ArcTanh[(Sqrt[2 + Sqrt[2]]*(1 - 1/(a*x))^(1/8))/((1 + (1 - 1/(a*x))^(1/4)/(1 + 1/(a*x))^(1/4))*(1 + 1/(a*x))^(1/8))]}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{E^(n*ArcCoth[a*x])*x^m, x, 2, (x^(1 + m)*AppellF1[-1 - m, n/2, -(n/2), -m, 1/(a*x), -(1/(a*x))])/(1 + m)}

{E^(n*ArcCoth[a*x])*x^2, x, 2, (2^(1 + n/2)*(1 - 1/(a*x))^(1 - n/2)*Defer[AppellF1][1 - n/2, 4, -(n/2), 2 - n/2, 1 - 1/(a*x), (1/2)*(1 - 1/(a*x))])/(a^3*(2 - n))}
{E^(n*ArcCoth[a*x])*x, x, 2, (2^(1 + n/2)*(1 - 1/(a*x))^(1 - n/2)*Defer[AppellF1][1 - n/2, 3, -(n/2), 2 - n/2, 1 - 1/(a*x), (1/2)*(1 - 1/(a*x))])/(a^2*(2 - n))}
{E^(n*ArcCoth[a*x]), x, 2, -((4*(1 + 1/(a*x))^(n/2)*(-1 + a*x)*Hypergeometric2F1[2, 1 - n/2, 2 - n/2, (-1 + a*x)/(1 + a*x)])/((1 - 1/(a*x))^(n/2)*(a*(-2 + n)*(1 + a*x)))), (2^(1 + n/2)*(1 - (a - 1/x)/(2*a))^((1/2)*(-2 + n))*(1 - 1/(a*x))^(1 - n/2)*Hypergeometric2F1[2, 1 - n/2, 2 - n/2, (2 - (a - 1/x)/a - 2/(a*x))/(2 - (a - 1/x)/a)])/(a*(2 - n))}
{E^(n*ArcCoth[a*x])/x, x, 2, (2^(1 + n/2)*(1 - 1/(a*x))^(1 - n/2)*AppellF1[1 - n/2, 1, -(n/2), 2 - n/2, 1 - 1/(a*x), (a - 1/x)/(2*a)])/(2 - n)}
{E^(n*ArcCoth[a*x])/x^2, x, 2, -((2^(1 - n/2)*a*(1 + 1/(a*x))^((2 + n)/2)*Hypergeometric2F1[n/2, (2 + n)/2, (4 + n)/2, (a + x^(-1))/(2*a)])/(2 + n))}
{E^(n*ArcCoth[a*x])/x^3, x, 3, (a^2*(1 - 1/(a*x))^(1 - n/2)*(1 + 1/(a*x))^((2 + n)/2))/2 - (a^2*n*(1 + 1/(a*x))^((2 + n)/2)*Hypergeometric2F1[n/2, (2 + n)/2, (4 + n)/2, (a + x^(-1))/(2*a)])/(2^(n/2)*(2 + n))}
{E^(n*ArcCoth[a*x])/x^4, x, 4, (a^3*n*(1 - 1/(a*x))^(1 - n/2)*(1 + 1/(a*x))^((2 + n)/2))/6 + (a^2*(1 - 1/(a*x))^(1 - n/2)*(1 + 1/(a*x))^((2 + n)/2))/(3*x) - (a^3*(2 + n^2)*(1 + 1/(a*x))^((2 + n)/2)*Hypergeometric2F1[n/2, (2 + n)/2, (4 + n)/2, (a + x^(-1))/(2*a)])/(3*2^(n/2)*(2 + n))}
{E^(n*ArcCoth[a*x])/x^5, x, 2, (a^4*(6 + n^2)*(1 - 1/(a*x))^(1 - n/2)*(1 + 1/(a*x))^((2 + n)/2))/24 + (a^2*(1 - 1/(a*x))^(1 - n/2)*(1 + 1/(a*x))^((2 + n)/2))/(4*x^2) + (a^3*n*(1 - 1/(a*x))^(1 - n/2)*(1 + 1/(a*x))^((2 + n)/2))/(12*x) - (2^(-2 - n/2)*a^4*n*(8 + n^2)*(1 + 1/(a*x))^((2 + n)/2)*Hypergeometric2F1[n/2, (2 + n)/2, (4 + n)/2, (a + x^(-1))/(2*a)])/(3*(2 + n)), -(AppellF1[4, n/2, -(n/2), 5, 1/(a*x), -(1/(a*x))]/(4*x^4))}


(* ::Subsection::Closed:: *)
(*Integrands of the form E^(n ArcCoth[a x]) (c-c a x)^p*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


(* A bug in Mathematica 8.0.4 simplifying AppellF1 to Hypergeometric2F1 results in Rubi returning an incorrect antiderivative for the following integrand: *) 
(* {E^ArcCoth[a*x]*(c - a*c*x)^p, x, 3, 0} *)

{E^ArcCoth[a*x]*(c - a*c*x)^4, x, 8, (7*c^4*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/8 - (7*a*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2)*x^2)/8 + (7*a^2*c^4*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(3/2)*x^3)/12 - (7*a^3*c^4*(1 - 1/(a*x))^(5/2)*(1 + 1/(a*x))^(3/2)*x^4)/20 + (a^4*c^4*(1 - 1/(a*x))^(7/2)*(1 + 1/(a*x))^(3/2)*x^5)/5 + (7*c^4*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(4*a)}
{E^ArcCoth[a*x]*(c - a*c*x)^3, x, 7, (5*c^3*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/8 - (5*a*c^3*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2)*x^2)/8 + (5*a^2*c^3*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(3/2)*x^3)/12 - (a^3*c^3*(1 - 1/(a*x))^(5/2)*(1 + 1/(a*x))^(3/2)*x^4)/4 + (5*c^3*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(4*a)}
{E^ArcCoth[a*x]*(c - a*c*x)^2, x, 6, (c^2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/2 - (a*c^2*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2)*x^2)/2 + (a^2*c^2*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(3/2)*x^3)/3 + (c^2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{E^ArcCoth[a*x]*(c - a*c*x), x, 5, (c*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/2 - (a*c*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2)*x^2)/2 + (c*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{E^ArcCoth[a*x]/(c - a*c*x), x, 4, (2*Sqrt[1 + 1/(a*x)])/(a*c*Sqrt[1 - 1/(a*x)]) - (2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(a*c)}
{E^ArcCoth[a*x]/(c - a*c*x)^2, x, 3, -(1 + 1/(a*x))^(3/2)/(3*a*c^2*(1 - 1/(a*x))^(3/2))}
{E^ArcCoth[a*x]/(c - a*c*x)^3, x, 4, (1 + 1/(a*x))^(3/2)/(5*a*c^3*(1 - 1/(a*x))^(5/2)) - (4*(1 + 1/(a*x))^(3/2))/(15*a*c^3*(1 - 1/(a*x))^(3/2))}
{E^ArcCoth[a*x]/(c - a*c*x)^4, x, 5, -(1 + 1/(a*x))^(3/2)/(7*a*c^4*(1 - 1/(a*x))^(7/2)) + (12*(1 + 1/(a*x))^(3/2))/(35*a*c^4*(1 - 1/(a*x))^(5/2)) - (23*(1 + 1/(a*x))^(3/2))/(105*a*c^4*(1 - 1/(a*x))^(3/2))}
{E^ArcCoth[a*x]/(c - a*c*x)^5, x, 6, -(1 + 1/(a*x))^(3/2)/(21*a*c^5*(1 - 1/(a*x))^(7/2)) + (4*(1 + 1/(a*x))^(3/2))/(35*a*c^5*(1 - 1/(a*x))^(5/2)) - (23*(1 + 1/(a*x))^(3/2))/(315*a*c^5*(1 - 1/(a*x))^(3/2)) + (1 + 1/(a*x))^(3/2)/(9*a^4*c^5*(1 - 1/(a*x))^(9/2)*x^3)}


{E^(2*ArcCoth[a*x])*(c - a*c*x)^p, x, 5, (2*(c - a*c*x)^p)/(a*p) - ((1 - a*x)*(c - a*c*x)^p)/(a*(1 + p))}

{E^(2*ArcCoth[a*x])*(c - a*c*x)^5, x, 4, (2*c^5*(1 - a*x)^5)/(5*a) - (c^5*(1 - a*x)^6)/(6*a)}
{E^(2*ArcCoth[a*x])*(c - a*c*x)^4, x, 4, -(c^4*x) + a*c^4*x^2 - (a^3*c^4*x^4)/2 + (a^4*c^4*x^5)/5}
{E^(2*ArcCoth[a*x])*(c - a*c*x)^3, x, 4, -(c^3*x) + (a*c^3*x^2)/2 + (a^2*c^3*x^3)/3 - (a^3*c^3*x^4)/4}
{E^(2*ArcCoth[a*x])*(c - a*c*x)^2, x, 4, -(c^2*x) + (a^2*c^2*x^3)/3}
{E^(2*ArcCoth[a*x])*(c - a*c*x), x, 3, -(c*x) - (a*c*x^2)/2}
{E^(2*ArcCoth[a*x])/(c - a*c*x), x, 4, -2/(a*c*(1 - a*x)) - Log[1 - a*x]/(a*c)}
{E^(2*ArcCoth[a*x])/(c - a*c*x)^2, x, 3, -(1 + a*x)^2/(4*a*c^2*(1 - a*x)^2)}
{E^(2*ArcCoth[a*x])/(c - a*c*x)^3, x, 4, -2/(3*a*c^3*(1 - a*x)^3) + 1/(2*a*c^3*(1 - a*x)^2)}
{E^(2*ArcCoth[a*x])/(c - a*c*x)^4, x, 4, -1/(2*a*c^4*(1 - a*x)^4) + 1/(3*a*c^4*(1 - a*x)^3)}


(* {E^(3*ArcCoth[a*x])*(c - a*c*x)^p, x, 3, 0} *)

{E^(3*ArcCoth[a*x])*(c - a*c*x)^4, x, 8, (-3*c^4*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/8 - (a*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2)*x^2)/8 + (a^2*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(5/2)*x^3)/4 - (a^3*c^4*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(5/2)*x^4)/4 + (a^4*c^4*(1 - 1/(a*x))^(5/2)*(1 + 1/(a*x))^(5/2)*x^5)/5 - (3*c^4*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(4*a)}
{E^(3*ArcCoth[a*x])*(c - a*c*x)^3, x, 7, (-3*c^3*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/8 - (a*c^3*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2)*x^2)/8 + (a^2*c^3*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(5/2)*x^3)/4 - (a^3*c^3*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(5/2)*x^4)/4 - (3*c^3*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(4*a)}
{E^(3*ArcCoth[a*x])*(c - a*c*x)^2, x, 6, -(c^2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/2 - (a*c^2*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2)*x^2)/6 + (a^2*c^2*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(5/2)*x^3)/3 - (c^2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{E^(3*ArcCoth[a*x])*(c - a*c*x), x, 5, (-3*c*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/2 - (a*c*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2)*x^2)/2 - (3*c*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{E^(3*ArcCoth[a*x])/(c - a*c*x), x, 5, (2*Sqrt[1 + 1/(a*x)])/(a*c*Sqrt[1 - 1/(a*x)]) + (2*(1 + 1/(a*x))^(3/2))/(3*a*c*(1 - 1/(a*x))^(3/2)) - (2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(a*c)}
{E^(3*ArcCoth[a*x])/(c - a*c*x)^2, x, 3, -(1 + 1/(a*x))^(5/2)/(5*a*c^2*(1 - 1/(a*x))^(5/2))}
{E^(3*ArcCoth[a*x])/(c - a*c*x)^3, x, 4, (1 + 1/(a*x))^(5/2)/(7*a*c^3*(1 - 1/(a*x))^(7/2)) - (6*(1 + 1/(a*x))^(5/2))/(35*a*c^3*(1 - 1/(a*x))^(5/2))}
{E^(3*ArcCoth[a*x])/(c - a*c*x)^4, x, 5, -(1 + 1/(a*x))^(5/2)/(9*a*c^4*(1 - 1/(a*x))^(9/2)) + (16*(1 + 1/(a*x))^(5/2))/(63*a*c^4*(1 - 1/(a*x))^(7/2)) - (47*(1 + 1/(a*x))^(5/2))/(315*a*c^4*(1 - 1/(a*x))^(5/2))}
{E^(3*ArcCoth[a*x])/(c - a*c*x)^5, x, 6, -(1 + 1/(a*x))^(5/2)/(33*a*c^5*(1 - 1/(a*x))^(9/2)) + (16*(1 + 1/(a*x))^(5/2))/(231*a*c^5*(1 - 1/(a*x))^(7/2)) - (47*(1 + 1/(a*x))^(5/2))/(1155*a*c^5*(1 - 1/(a*x))^(5/2)) + (1 + 1/(a*x))^(5/2)/(11*a^4*c^5*(1 - 1/(a*x))^(11/2)*x^3)}


{E^(4*ArcCoth[a*x])*(c - a*c*x)^p, x, 5, (4*(c - a*c*x)^p)/(a*p) + (4*(c - a*c*x)^p)/(a*(1 - p)*(1 - a*x)) - ((1 - a*x)*(c - a*c*x)^p)/(a*(1 + p))}

{E^(4*ArcCoth[a*x])*(c - a*c*x)^5, x, 4, -((c^5*(1 - a*x)^4)/a) + (4*c^5*(1 - a*x)^5)/(5*a) - (c^5*(1 - a*x)^6)/(6*a)}
{E^(4*ArcCoth[a*x])*(c - a*c*x)^4, x, 4, c^4*x - (2*a^2*c^4*x^3)/3 + (a^4*c^4*x^5)/5}
{E^(4*ArcCoth[a*x])*(c - a*c*x)^3, x, 4, c^3*x + (a*c^3*x^2)/2 - (a^2*c^3*x^3)/3 - (a^3*c^3*x^4)/4}
{E^(4*ArcCoth[a*x])*(c - a*c*x)^2, x, 3, (c^2*(1 + a*x)^3)/(3*a)}
{E^(4*ArcCoth[a*x])*(c - a*c*x), x, 4, -3*c*x - (a*c*x^2)/2 - (4*c*Log[1 - a*x])/a}
{E^(4*ArcCoth[a*x])/(c - a*c*x), x, 4, 2/(a*c*(1 - a*x)^2) - 4/(a*c*(1 - a*x)) - Log[1 - a*x]/(a*c)}
{E^(4*ArcCoth[a*x])/(c - a*c*x)^2, x, 3, (1 + a*x)^3/(6*a*c^2*(1 - a*x)^3)}
{E^(4*ArcCoth[a*x])/(c - a*c*x)^3, x, 4, 1/(a*c^3*(1 - a*x)^4) - 4/(3*a*c^3*(1 - a*x)^3) + 1/(2*a*c^3*(1 - a*x)^2)}
{E^(4*ArcCoth[a*x])/(c - a*c*x)^4, x, 4, 4/(5*a*c^4*(1 - a*x)^5) - 1/(a*c^4*(1 - a*x)^4) + 1/(3*a*c^4*(1 - a*x)^3)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


(* {(c - a*c*x)^p/E^ArcCoth[a*x], x, 3, 0} *)

{(c - a*c*x)^3/E^ArcCoth[a*x], x, 7, (35*c^3*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/8 - (35*a*c^3*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)]*x^2)/24 + (7*a^2*c^3*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)]*x^3)/12 - (a^3*c^3*(1 - 1/(a*x))^(7/2)*Sqrt[1 + 1/(a*x)]*x^4)/4 - (35*c^3*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(4*a)}
{(c - a*c*x)^2/E^ArcCoth[a*x], x, 6, (5*c^2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/2 - (5*a*c^2*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)]*x^2)/6 + (a^2*c^2*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)]*x^3)/3 - (5*c^2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{(c - a*c*x)/E^ArcCoth[a*x], x, 5, (3*c*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/2 - (a*c*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)]*x^2)/2 - (3*c*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{1/(E^ArcCoth[a*x]*(c - a*c*x)), x, 3, (-2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(a*c)}
{1/(E^ArcCoth[a*x]*(c - a*c*x)^2), x, 3, -(Sqrt[1 + 1/(a*x)]/(a*c^2*Sqrt[1 - 1/(a*x)]))}
{1/(E^ArcCoth[a*x]*(c - a*c*x)^3), x, 4, Sqrt[1 + 1/(a*x)]/(3*a*c^3*(1 - 1/(a*x))^(3/2)) - (2*Sqrt[1 + 1/(a*x)])/(3*a*c^3*Sqrt[1 - 1/(a*x)])}
{1/(E^ArcCoth[a*x]*(c - a*c*x)^4), x, 5, -Sqrt[1 + 1/(a*x)]/(5*a*c^4*(1 - 1/(a*x))^(5/2)) + (8*Sqrt[1 + 1/(a*x)])/(15*a*c^4*(1 - 1/(a*x))^(3/2)) - (7*Sqrt[1 + 1/(a*x)])/(15*a*c^4*Sqrt[1 - 1/(a*x)])}
{1/(E^ArcCoth[a*x]*(c - a*c*x)^5), x, 6, (-3*Sqrt[1 + 1/(a*x)])/(35*a*c^5*(1 - 1/(a*x))^(5/2)) + (8*Sqrt[1 + 1/(a*x)])/(35*a*c^5*(1 - 1/(a*x))^(3/2)) - Sqrt[1 + 1/(a*x)]/(5*a*c^5*Sqrt[1 - 1/(a*x)]) + Sqrt[1 + 1/(a*x)]/(7*a^4*c^5*(1 - 1/(a*x))^(7/2)*x^3)}


{(c - a*c*x)^p/E^(2*ArcCoth[a*x]), x, 4, ((1 - a*x)^2*(c - a*c*x)^p*Hypergeometric2F1[1, 2 + p, 3 + p, (1/2)*(1 - a*x)])/(2*a*(2 + p))}

{(c - a*c*x)^4/E^(2*ArcCoth[a*x]), x, 4, 16*c^4*x - (4*c^4*(1 - a*x)^2)/a - (4*c^4*(1 - a*x)^3)/(3*a) - (c^4*(1 - a*x)^4)/(2*a) - (c^4*(1 - a*x)^5)/(5*a) - (32*c^4*Log[1 + a*x])/a}
{(c - a*c*x)^3/E^(2*ArcCoth[a*x]), x, 4, 8*c^3*x - (2*c^3*(1 - a*x)^2)/a - (2*c^3*(1 - a*x)^3)/(3*a) - (c^3*(1 - a*x)^4)/(4*a) - (16*c^3*Log[1 + a*x])/a}
{(c - a*c*x)^2/E^(2*ArcCoth[a*x]), x, 4, 4*c^2*x - (c^2*(1 - a*x)^2)/a - (c^2*(1 - a*x)^3)/(3*a) - (8*c^2*Log[1 + a*x])/a}
{(c - a*c*x)/E^(2*ArcCoth[a*x]), x, 4, 3*c*x - (a*c*x^2)/2 - (4*c*Log[1 + a*x])/a}
{1/(E^(2*ArcCoth[a*x])*(c - a*c*x)), x, 3, -(Log[1 + a*x]/(a*c))}
{1/(E^(2*ArcCoth[a*x])*(c - a*c*x)^2), x, 4, -(ArcTanh[a*x]/(a*c^2))}
{1/(E^(2*ArcCoth[a*x])*(c - a*c*x)^3), x, 5, -(1/(2*a*c^3*(1 - a*x))) - ArcTanh[a*x]/(2*a*c^3)}
{1/(E^(2*ArcCoth[a*x])*(c - a*c*x)^4), x, 5, -(1/(4*a*c^4*(1 - a*x)^2)) - 1/(4*a*c^4*(1 - a*x)) - ArcTanh[a*x]/(4*a*c^4)}
{1/(E^(2*ArcCoth[a*x])*(c - a*c*x)^5), x, 5, -(1/(6*a*c^5*(1 - a*x)^3)) - 1/(8*a*c^5*(1 - a*x)^2) - 1/(8*a*c^5*(1 - a*x)) - ArcTanh[a*x]/(8*a*c^5)}


(* {(c - a*c*x)^p/E^(3*ArcCoth[a*x]), x, 3, 0} *)

{(c - a*c*x)^3/E^(3*ArcCoth[a*x]), x, 8, (315*c^3*Sqrt[1 - 1/(a*x)])/(4*a*Sqrt[1 + 1/(a*x)]) + (105*c^3*(1 - 1/(a*x))^(3/2)*x)/(8*Sqrt[1 + 1/(a*x)]) - (21*a*c^3*(1 - 1/(a*x))^(5/2)*x^2)/(8*Sqrt[1 + 1/(a*x)]) + (3*a^2*c^3*(1 - 1/(a*x))^(7/2)*x^3)/(4*Sqrt[1 + 1/(a*x)]) - (a^3*c^3*(1 - 1/(a*x))^(9/2)*x^4)/(4*Sqrt[1 + 1/(a*x)]) - (315*c^3*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(4*a)}
{(c - a*c*x)^2/E^(3*ArcCoth[a*x]), x, 7, (35*c^2*Sqrt[1 - 1/(a*x)])/(a*Sqrt[1 + 1/(a*x)]) + (35*c^2*(1 - 1/(a*x))^(3/2)*x)/(6*Sqrt[1 + 1/(a*x)]) - (7*a*c^2*(1 - 1/(a*x))^(5/2)*x^2)/(6*Sqrt[1 + 1/(a*x)]) + (a^2*c^2*(1 - 1/(a*x))^(7/2)*x^3)/(3*Sqrt[1 + 1/(a*x)]) - (35*c^2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{(c - a*c*x)/E^(3*ArcCoth[a*x]), x, 6, (15*c*Sqrt[1 - 1/(a*x)])/(a*Sqrt[1 + 1/(a*x)]) + (5*c*(1 - 1/(a*x))^(3/2)*x)/(2*Sqrt[1 + 1/(a*x)]) - (a*c*(1 - 1/(a*x))^(5/2)*x^2)/(2*Sqrt[1 + 1/(a*x)]) - (15*c*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{1/(E^(3*ArcCoth[a*x])*(c - a*c*x)), x, 4, (2*Sqrt[1 - 1/(a*x)])/(a*c*Sqrt[1 + 1/(a*x)]) - (2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(a*c)}
{1/(E^(3*ArcCoth[a*x])*(c - a*c*x)^2), x, 3, Sqrt[1 - 1/(a*x)]/(a*c^2*Sqrt[1 + 1/(a*x)])}
{1/(E^(3*ArcCoth[a*x])*(c - a*c*x)^3), x, 3, 1/(a*c^3*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])}
{1/(E^(3*ArcCoth[a*x])*(c - a*c*x)^4), x, 5, -1/(3*a*c^4*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)]) + 2/(3*a*c^4*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]) + Sqrt[1 + 1/(a*x)]/(3*a*c^4*Sqrt[1 - 1/(a*x)])}
{1/(E^(3*ArcCoth[a*x])*(c - a*c*x)^5), x, 6, -1/(5*a*c^5*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)]) + 2/(5*a*c^5*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]) + Sqrt[1 + 1/(a*x)]/(5*a*c^5*Sqrt[1 - 1/(a*x)]) + 1/(5*a^4*c^5*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)]*x^3)}
{1/(E^(3*ArcCoth[a*x])*(c - a*c*x)^6), x, 7, -4/(35*a*c^6*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)]) + 8/(35*a*c^6*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]) + (4*Sqrt[1 + 1/(a*x)])/(35*a*c^6*Sqrt[1 - 1/(a*x)]) - 1/(7*a^5*c^6*(1 - 1/(a*x))^(7/2)*Sqrt[1 + 1/(a*x)]*x^4) + 4/(35*a^4*c^6*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)]*x^3)}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


(* {(c - a*c*x)^p/E^(2*p*ArcCoth[a*x]), x, 3, 0} *)
{E^(2*p*ArcCoth[a*x])*(c - a*c*x)^p, x, 3, ((1 + 1/(a*x))^(1 + p)*x*(c - a*c*x)^p)/((1 + p)*(1 - 1/(a*x))^p)}


(* {E^(n*ArcCoth[a*x])*(c - a*c*x)^p, x, 3, 0} *)

{E^(n*ArcCoth[a*x])*(c - a*c*x)^3, x, 3, -((2^(1 + n/2)*c^3*(1 - (a - x^(-1))/(2*a))^((-8 + n)/2)*(1 - 1/(a*x))^(4 - n/2)*Hypergeometric2F1[5, 4 - n/2, 5 - n/2, (2 - (a - x^(-1))/a - 2/(a*x))/(2 - (a - x^(-1))/a)])/(a*(8 - n)))}
{E^(n*ArcCoth[a*x])*(c - a*c*x)^2, x, 3, (2^(1 + n/2)*c^2*(1 - (a - x^(-1))/(2*a))^((-6 + n)/2)*(1 - 1/(a*x))^(3 - n/2)*Hypergeometric2F1[4, 3 - n/2, 4 - n/2, (2 - (a - x^(-1))/a - 2/(a*x))/(2 - (a - x^(-1))/a)])/(a*(6 - n))}
{E^(n*ArcCoth[a*x])*(c - a*c*x), x, 3, -((2^(1 + n/2)*c*(1 - (a - x^(-1))/(2*a))^((-4 + n)/2)*(1 - 1/(a*x))^(2 - n/2)*Hypergeometric2F1[3, 2 - n/2, 3 - n/2, (2 - (a - x^(-1))/a - 2/(a*x))/(2 - (a - x^(-1))/a)])/(a*(4 - n)))}
{E^(n*ArcCoth[a*x]), x, 2, (2^(1 + n/2)*(1 - (a - x^(-1))/(2*a))^((-2 + n)/2)*(1 - 1/(a*x))^(1 - n/2)*Hypergeometric2F1[2, 1 - n/2, 2 - n/2, (2 - (a - x^(-1))/a - 2/(a*x))/(2 - (a - x^(-1))/a)])/(a*(2 - n))}
{E^(n*ArcCoth[a*x])/(c - a*c*x), x, 3, (2^(1 + n/2)*(1 - (a - x^(-1))/(2*a))^(n/2)*Hypergeometric2F1[1, -n/2, 1 - n/2, (2 - (a - x^(-1))/a - 2/(a*x))/(2 - (a - x^(-1))/a)])/(a*c*n*(1 - 1/(a*x))^(n/2))}
{E^(n*ArcCoth[a*x])/(c - a*c*x)^2, x, 3, -(((1 - 1/(a*x))^(-1 - n/2)*(1 + 1/(a*x))^((2 + n)/2))/(a*c^2*(2 + n)))}
{E^(n*ArcCoth[a*x])/(c - a*c*x)^3, x, 4, ((1 - 1/(a*x))^(-2 - n/2)*(1 + 1/(a*x))^((2 + n)/2))/(a*c^3*(4 + n)) - ((3 + n)*(1 - 1/(a*x))^(-1 - n/2)*(1 + 1/(a*x))^((2 + n)/2))/(a*c^3*(2 + n)*(4 + n))}
{E^(n*ArcCoth[a*x])/(c - a*c*x)^4, x, 6, ((5 + n)*(1 - 1/(a*x))^(-3 - n/2)*(1 + 1/(a*x))^((2 + n)/2))/(a*c^4*(6 + n)) - ((14 + 8*n + n^2)*(1 - 1/(a*x))^(-2 - n/2)*(1 + 1/(a*x))^((2 + n)/2))/(a*c^4*(4 + n)*(6 + n)) - ((14 + 8*n + n^2)*(1 - 1/(a*x))^(-1 - n/2)*(1 + 1/(a*x))^((2 + n)/2))/(a*c^4*(6 + n)*(8 + 6*n + n^2)) - ((1 - 1/(a*x))^(-3 - n/2)*(1 + 1/(a*x))^((2 + n)/2))/(a^2*c^4*x)}


(* ::Subsection::Closed:: *)
(*Integrands of the form E^(n ArcCoth[a x])  (c-c a x)^(p/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{E^ArcCoth[a*x]*(c - a*c*x)^(9/2), x, 7, (-32*(a - x^(-1))^3*(1 + 1/(a*x))^(3/2)*(c - a*c*x)^(9/2))/(99*a^4*(1 - 1/(a*x))^(9/2)) + (9088*(1 + 1/(a*x))^(3/2)*(c - a*c*x)^(9/2))/(3465*a^4*(1 - 1/(a*x))^(9/2)*x^3) - (768*(1 + 1/(a*x))^(3/2)*(c - a*c*x)^(9/2))/(385*a^3*(1 - 1/(a*x))^(9/2)*x^2) + (128*(1 + 1/(a*x))^(3/2)*(c - a*c*x)^(9/2))/(231*a^2*(1 - 1/(a*x))^(9/2)*x) + (2*(a - x^(-1))^4*(1 + 1/(a*x))^(3/2)*x*(c - a*c*x)^(9/2))/(11*a^4*(1 - 1/(a*x))^(9/2))}
{E^ArcCoth[a*x]*(c - a*c*x)^(7/2), x, 6, (-8*(1 + 1/(a*x))^(3/2)*(c - a*c*x)^(7/2))/(21*a*(1 - 1/(a*x))^(7/2)) - (568*(1 + 1/(a*x))^(3/2)*(c - a*c*x)^(7/2))/(315*a^3*(1 - 1/(a*x))^(7/2)*x^2) + (48*(1 + 1/(a*x))^(3/2)*(c - a*c*x)^(7/2))/(35*a^2*(1 - 1/(a*x))^(7/2)*x) + (2*(a - x^(-1))^3*(1 + 1/(a*x))^(3/2)*x*(c - a*c*x)^(7/2))/(9*a^3*(1 - 1/(a*x))^(7/2))}
{E^ArcCoth[a*x]*(c - a*c*x)^(5/2), x, 5, (-36*(1 + 1/(a*x))^(3/2)*(c - a*c*x)^(5/2))/(35*a*(1 - 1/(a*x))^(5/2)) + (142*(1 + 1/(a*x))^(3/2)*(c - a*c*x)^(5/2))/(105*a^2*(1 - 1/(a*x))^(5/2)*x) + (2*(1 + 1/(a*x))^(3/2)*x*(c - a*c*x)^(5/2))/(7*(1 - 1/(a*x))^(5/2))}
{E^ArcCoth[a*x]*(c - a*c*x)^(3/2), x, 4, (-14*(1 + 1/(a*x))^(3/2)*(c - a*c*x)^(3/2))/(15*a*(1 - 1/(a*x))^(3/2)) + (2*(1 + 1/(a*x))^(3/2)*x*(c - a*c*x)^(3/2))/(5*(1 - 1/(a*x))^(3/2))}
{E^ArcCoth[a*x]*Sqrt[c - a*c*x], x, 3, (2*(1 + 1/(a*x))^(3/2)*x*Sqrt[c - a*c*x])/(3*Sqrt[1 - 1/(a*x)])}
{E^ArcCoth[a*x]/Sqrt[c - a*c*x], x, 4, (2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/Sqrt[c - a*c*x] - (2*Sqrt[2]*Sqrt[1 - 1/(a*x)]*ArcTanh[(Sqrt[2]*Sqrt[1/x])/(Sqrt[a]*Sqrt[1 + 1/(a*x)])])/(Sqrt[a]*Sqrt[1/x]*Sqrt[c - a*c*x])}
{E^ArcCoth[a*x]/(c - a*c*x)^(3/2), x, 4, -((a*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)]*x)/((a - 1/x)*(c - a*c*x)^(3/2))) - (Sqrt[a]*(1 - 1/(a*x))^(3/2)*ArcTanh[(Sqrt[2]*Sqrt[1/x])/(Sqrt[a]*Sqrt[1 + 1/(a*x)])])/(Sqrt[2]*(1/x)^(3/2)*(c - a*c*x)^(3/2))}
{E^ArcCoth[a*x]/(c - a*c*x)^(5/2), x, 5, (a^2*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)]*x^2)/(8*(a - 1/x)*(c - a*c*x)^(5/2)) - (a^3*(1 - 1/(a*x))^(5/2)*(1 + 1/(a*x))^(3/2)*x^2)/(4*(a - 1/x)^2*(c - a*c*x)^(5/2)) + (a^(3/2)*(1 - 1/(a*x))^(5/2)*ArcTanh[(Sqrt[2]*Sqrt[1/x])/(Sqrt[a]*Sqrt[1 + 1/(a*x)])])/(8*Sqrt[2]*(1/x)^(5/2)*(c - a*c*x)^(5/2))}
{E^ArcCoth[a*x]/(c - a*c*x)^(7/2), x, 6, -((a^4*(1 - 1/(a*x))^(7/2)*(1 + 1/(a*x))^(3/2)*x^2)/(6*(a - 1/x)^3*(c - a*c*x)^(7/2))) - (a^3*(1 - 1/(a*x))^(7/2)*Sqrt[1 + 1/(a*x)]*x^3)/(32*(a - 1/x)*(c - a*c*x)^(7/2)) + (a^4*(1 - 1/(a*x))^(7/2)*(1 + 1/(a*x))^(3/2)*x^3)/(16*(a - 1/x)^2*(c - a*c*x)^(7/2)) - (a^(5/2)*(1 - 1/(a*x))^(7/2)*ArcTanh[(Sqrt[2]*Sqrt[1/x])/(Sqrt[a]*Sqrt[1 + 1/(a*x)])])/(32*Sqrt[2]*(1/x)^(7/2)*(c - a*c*x)^(7/2))}


{E^(2*ArcCoth[a*x])*(c - a*c*x)^(9/2), x, 5, (4*(c - a*c*x)^(9/2))/(9*a) - (2*(1 - a*x)*(c - a*c*x)^(9/2))/(11*a)}
{E^(2*ArcCoth[a*x])*(c - a*c*x)^(7/2), x, 5, (4*(c - a*c*x)^(7/2))/(7*a) - (2*(1 - a*x)*(c - a*c*x)^(7/2))/(9*a)}
{E^(2*ArcCoth[a*x])*(c - a*c*x)^(5/2), x, 5, (4*(c - a*c*x)^(5/2))/(5*a) - (2*(1 - a*x)*(c - a*c*x)^(5/2))/(7*a)}
{E^(2*ArcCoth[a*x])*(c - a*c*x)^(3/2), x, 5, (4*(c - a*c*x)^(3/2))/(3*a) - (2*(1 - a*x)*(c - a*c*x)^(3/2))/(5*a)}
{E^(2*ArcCoth[a*x])*Sqrt[c - a*c*x], x, 5, (4*Sqrt[c - a*c*x])/a - (2*(1 - a*x)*Sqrt[c - a*c*x])/(3*a)}
{E^(2*ArcCoth[a*x])/Sqrt[c - a*c*x], x, 5, -4/(a*Sqrt[c - a*c*x]) - (2*(1 - a*x))/(a*Sqrt[c - a*c*x])}
{E^(2*ArcCoth[a*x])/(c - a*c*x)^(3/2), x, 5, -4/(3*a*(c - a*c*x)^(3/2)) + (2*(1 - a*x))/(a*(c - a*c*x)^(3/2))}
{E^(2*ArcCoth[a*x])/(c - a*c*x)^(5/2), x, 5, -4/(5*a*(c - a*c*x)^(5/2)) + (2*(1 - a*x))/(3*a*(c - a*c*x)^(5/2))}
{E^(2*ArcCoth[a*x])/(c - a*c*x)^(7/2), x, 5, -4/(7*a*(c - a*c*x)^(7/2)) + (2*(1 - a*x))/(5*a*(c - a*c*x)^(7/2))}
{E^(2*ArcCoth[a*x])/(c - a*c*x)^(9/2), x, 5, -4/(9*a*(c - a*c*x)^(9/2)) + (2*(1 - a*x))/(7*a*(c - a*c*x)^(9/2))}


{E^(3*ArcCoth[a*x])*(c - a*c*x)^(9/2), x, 6, (-8*(1 + 1/(a*x))^(5/2)*(c - a*c*x)^(9/2))/(33*a*(1 - 1/(a*x))^(9/2)) - (856*(1 + 1/(a*x))^(5/2)*(c - a*c*x)^(9/2))/(1155*a^3*(1 - 1/(a*x))^(9/2)*x^2) + (16*(1 + 1/(a*x))^(5/2)*(c - a*c*x)^(9/2))/(21*a^2*(1 - 1/(a*x))^(9/2)*x) + (2*(a - x^(-1))^3*(1 + 1/(a*x))^(5/2)*x*(c - a*c*x)^(9/2))/(11*a^3*(1 - 1/(a*x))^(9/2))}
{E^(3*ArcCoth[a*x])*(c - a*c*x)^(7/2), x, 5, (-44*(1 + 1/(a*x))^(5/2)*(c - a*c*x)^(7/2))/(63*a*(1 - 1/(a*x))^(7/2)) + (214*(1 + 1/(a*x))^(5/2)*(c - a*c*x)^(7/2))/(315*a^2*(1 - 1/(a*x))^(7/2)*x) + (2*(1 + 1/(a*x))^(5/2)*x*(c - a*c*x)^(7/2))/(9*(1 - 1/(a*x))^(7/2))}
{E^(3*ArcCoth[a*x])*(c - a*c*x)^(5/2), x, 4, (-18*(1 + 1/(a*x))^(5/2)*(c - a*c*x)^(5/2))/(35*a*(1 - 1/(a*x))^(5/2)) + (2*(1 + 1/(a*x))^(5/2)*x*(c - a*c*x)^(5/2))/(7*(1 - 1/(a*x))^(5/2))}
{E^(3*ArcCoth[a*x])*(c - a*c*x)^(3/2), x, 3, (2*(1 + 1/(a*x))^(5/2)*x*(c - a*c*x)^(3/2))/(5*(1 - 1/(a*x))^(3/2))}
{E^(3*ArcCoth[a*x])*Sqrt[c - a*c*x], x, 5, (4*Sqrt[1 + 1/(a*x)]*Sqrt[c - a*c*x])/(a*Sqrt[1 - 1/(a*x)]) + (2*(1 + 1/(a*x))^(3/2)*x*Sqrt[c - a*c*x])/(3*Sqrt[1 - 1/(a*x)]) - (4*Sqrt[2]*Sqrt[1/x]*Sqrt[c - a*c*x]*ArcTanh[(Sqrt[2]*Sqrt[1/x])/(Sqrt[a]*Sqrt[1 + 1/(a*x)])])/(a^(3/2)*Sqrt[1 - 1/(a*x)])}
{E^(3*ArcCoth[a*x])/Sqrt[c - a*c*x], x, 5, -((6*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/((a - 1/x)*Sqrt[c - a*c*x])) + (2*a*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2)*x)/((a - 1/x)*Sqrt[c - a*c*x]) - (3*Sqrt[2]*Sqrt[1 - 1/(a*x)]*ArcTanh[(Sqrt[2]*Sqrt[1/x])/(Sqrt[a]*Sqrt[1 + 1/(a*x)])])/(Sqrt[a]*Sqrt[1/x]*Sqrt[c - a*c*x])}
{E^(3*ArcCoth[a*x])/(c - a*c*x)^(3/2), x, 5, -((3*a*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)]*x)/(4*(a - 1/x)*(c - a*c*x)^(3/2))) - (a^2*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(3/2)*x)/(2*(a - 1/x)^2*(c - a*c*x)^(3/2)) - (3*Sqrt[a]*(1 - 1/(a*x))^(3/2)*ArcTanh[(Sqrt[2]*Sqrt[1/x])/(Sqrt[a]*Sqrt[1 + 1/(a*x)])])/(4*Sqrt[2]*(1/x)^(3/2)*(c - a*c*x)^(3/2))}
{E^(3*ArcCoth[a*x])/(c - a*c*x)^(5/2), x, 6, (a^2*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)]*x^2)/(16*(a - 1/x)*(c - a*c*x)^(5/2)) + (a^3*(1 - 1/(a*x))^(5/2)*(1 + 1/(a*x))^(3/2)*x^2)/(24*(a - 1/x)^2*(c - a*c*x)^(5/2)) - (a^4*(1 - 1/(a*x))^(5/2)*(1 + 1/(a*x))^(5/2)*x^2)/(6*(a - 1/x)^3*(c - a*c*x)^(5/2)) + (a^(3/2)*(1 - 1/(a*x))^(5/2)*ArcTanh[(Sqrt[2]*Sqrt[1/x])/(Sqrt[a]*Sqrt[1 + 1/(a*x)])])/(16*Sqrt[2]*(1/x)^(5/2)*(c - a*c*x)^(5/2))}
{E^(3*ArcCoth[a*x])/(c - a*c*x)^(7/2), x, 7, -((a^5*(1 - 1/(a*x))^(7/2)*(1 + 1/(a*x))^(5/2)*x^2)/(8*(a - 1/x)^4*(c - a*c*x)^(7/2))) - (3*a^3*(1 - 1/(a*x))^(7/2)*Sqrt[1 + 1/(a*x)]*x^3)/(256*(a - 1/x)*(c - a*c*x)^(7/2)) - (a^4*(1 - 1/(a*x))^(7/2)*(1 + 1/(a*x))^(3/2)*x^3)/(128*(a - 1/x)^2*(c - a*c*x)^(7/2)) + (a^5*(1 - 1/(a*x))^(7/2)*(1 + 1/(a*x))^(5/2)*x^3)/(32*(a - 1/x)^3*(c - a*c*x)^(7/2)) - (3*a^(5/2)*(1 - 1/(a*x))^(7/2)*ArcTanh[(Sqrt[2]*Sqrt[1/x])/(Sqrt[a]*Sqrt[1 + 1/(a*x)])])/(256*Sqrt[2]*(1/x)^(7/2)*(c - a*c*x)^(7/2))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(c - a*c*x)^(9/2)/E^ArcCoth[a*x], x, 8, (-40*(a - x^(-1))^4*Sqrt[1 + 1/(a*x)]*(c - a*c*x)^(9/2))/(99*a^5*(1 - 1/(a*x))^(9/2)) - (22016*Sqrt[1 + 1/(a*x)]*(c - a*c*x)^(9/2))/(693*a^5*(1 - 1/(a*x))^(9/2)*x^4) + (1024*Sqrt[1 + 1/(a*x)]*(c - a*c*x)^(9/2))/(99*a^4*(1 - 1/(a*x))^(9/2)*x^3) - (512*Sqrt[1 + 1/(a*x)]*(c - a*c*x)^(9/2))/(231*a^3*(1 - 1/(a*x))^(9/2)*x^2) + (640*(a - x^(-1))^3*Sqrt[1 + 1/(a*x)]*(c - a*c*x)^(9/2))/(693*a^5*(1 - 1/(a*x))^(9/2)*x) + (2*(a - x^(-1))^5*Sqrt[1 + 1/(a*x)]*x*(c - a*c*x)^(9/2))/(11*a^5*(1 - 1/(a*x))^(9/2))}
{(c - a*c*x)^(7/2)/E^ArcCoth[a*x], x, 7, (-32*(a - x^(-1))^3*Sqrt[1 + 1/(a*x)]*(c - a*c*x)^(7/2))/(63*a^4*(1 - 1/(a*x))^(7/2)) + (5504*Sqrt[1 + 1/(a*x)]*(c - a*c*x)^(7/2))/(315*a^4*(1 - 1/(a*x))^(7/2)*x^3) - (256*Sqrt[1 + 1/(a*x)]*(c - a*c*x)^(7/2))/(45*a^3*(1 - 1/(a*x))^(7/2)*x^2) + (128*Sqrt[1 + 1/(a*x)]*(c - a*c*x)^(7/2))/(105*a^2*(1 - 1/(a*x))^(7/2)*x) + (2*(a - x^(-1))^4*Sqrt[1 + 1/(a*x)]*x*(c - a*c*x)^(7/2))/(9*a^4*(1 - 1/(a*x))^(7/2))}
{(c - a*c*x)^(5/2)/E^ArcCoth[a*x], x, 6, (-24*Sqrt[1 + 1/(a*x)]*(c - a*c*x)^(5/2))/(35*a*(1 - 1/(a*x))^(5/2)) - (344*Sqrt[1 + 1/(a*x)]*(c - a*c*x)^(5/2))/(35*a^3*(1 - 1/(a*x))^(5/2)*x^2) + (16*Sqrt[1 + 1/(a*x)]*(c - a*c*x)^(5/2))/(5*a^2*(1 - 1/(a*x))^(5/2)*x) + (2*(a - x^(-1))^3*Sqrt[1 + 1/(a*x)]*x*(c - a*c*x)^(5/2))/(7*a^3*(1 - 1/(a*x))^(5/2))}
{(c - a*c*x)^(3/2)/E^ArcCoth[a*x], x, 5, (-28*Sqrt[1 + 1/(a*x)]*(c - a*c*x)^(3/2))/(15*a*(1 - 1/(a*x))^(3/2)) + (86*Sqrt[1 + 1/(a*x)]*(c - a*c*x)^(3/2))/(15*a^2*(1 - 1/(a*x))^(3/2)*x) + (2*Sqrt[1 + 1/(a*x)]*x*(c - a*c*x)^(3/2))/(5*(1 - 1/(a*x))^(3/2))}
{Sqrt[c - a*c*x]/E^ArcCoth[a*x], x, 4, (-10*Sqrt[1 + 1/(a*x)]*Sqrt[c - a*c*x])/(3*a*Sqrt[1 - 1/(a*x)]) + (2*Sqrt[1 + 1/(a*x)]*x*Sqrt[c - a*c*x])/(3*Sqrt[1 - 1/(a*x)])}
{1/(E^ArcCoth[a*x]*Sqrt[c - a*c*x]), x, 3, (2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/Sqrt[c - a*c*x]}
{1/(E^ArcCoth[a*x]*(c - a*c*x)^(3/2)), x, 3, -((Sqrt[2]*Sqrt[a]*(1 - 1/(a*x))^(3/2)*ArcTanh[(Sqrt[2]*Sqrt[1/x])/(Sqrt[a]*Sqrt[1 + 1/(a*x)])])/((1/x)^(3/2)*(c - a*c*x)^(3/2)))}
{1/(E^ArcCoth[a*x]*(c - a*c*x)^(5/2)), x, 4, -((a^2*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)]*x^2)/(2*(a - 1/x)*(c - a*c*x)^(5/2))) + (a^(3/2)*(1 - 1/(a*x))^(5/2)*ArcTanh[(Sqrt[2]*Sqrt[1/x])/(Sqrt[a]*Sqrt[1 + 1/(a*x)])])/(2*Sqrt[2]*(1/x)^(5/2)*(c - a*c*x)^(5/2))}
{1/(E^ArcCoth[a*x]*(c - a*c*x)^(7/2)), x, 5, -((a^3*(1 - 1/(a*x))^(7/2)*Sqrt[1 + 1/(a*x)]*x^2)/(4*(a - 1/x)^2*(c - a*c*x)^(7/2))) + (3*a^3*(1 - 1/(a*x))^(7/2)*Sqrt[1 + 1/(a*x)]*x^3)/(16*(a - 1/x)*(c - a*c*x)^(7/2)) - (3*a^(5/2)*(1 - 1/(a*x))^(7/2)*ArcTanh[(Sqrt[2]*Sqrt[1/x])/(Sqrt[a]*Sqrt[1 + 1/(a*x)])])/(16*Sqrt[2]*(1/x)^(7/2)*(c - a*c*x)^(7/2))}


{(c - a*c*x)^(9/2)/E^(2*ArcCoth[a*x]), x, 10, (-4*(c - a*c*x)^(9/2))/(9*a) - (64*(c - a*c*x)^(9/2))/(a*(1 - a*x)^4) - (32*(c - a*c*x)^(9/2))/(3*a*(1 - a*x)^3) - (16*(c - a*c*x)^(9/2))/(5*a*(1 - a*x)^2) - (8*(c - a*c*x)^(9/2))/(7*a*(1 - a*x)) - (2*(1 - a*x)*(c - a*c*x)^(9/2))/(11*a) + (64*Sqrt[2]*(c - a*c*x)^(9/2)*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/(a*(1 - a*x)^(9/2))}
{(c - a*c*x)^(7/2)/E^(2*ArcCoth[a*x]), x, 9, (-4*(c - a*c*x)^(7/2))/(7*a) - (32*(c - a*c*x)^(7/2))/(a*(1 - a*x)^3) - (16*(c - a*c*x)^(7/2))/(3*a*(1 - a*x)^2) - (8*(c - a*c*x)^(7/2))/(5*a*(1 - a*x)) - (2*(1 - a*x)*(c - a*c*x)^(7/2))/(9*a) + (32*Sqrt[2]*(c - a*c*x)^(7/2)*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/(a*(1 - a*x)^(7/2))}
{(c - a*c*x)^(5/2)/E^(2*ArcCoth[a*x]), x, 8, (-4*(c - a*c*x)^(5/2))/(5*a) - (16*(c - a*c*x)^(5/2))/(a*(1 - a*x)^2) - (8*(c - a*c*x)^(5/2))/(3*a*(1 - a*x)) - (2*(1 - a*x)*(c - a*c*x)^(5/2))/(7*a) + (16*Sqrt[2]*(c - a*c*x)^(5/2)*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/(a*(1 - a*x)^(5/2))}
{(c - a*c*x)^(3/2)/E^(2*ArcCoth[a*x]), x, 7, (-4*(c - a*c*x)^(3/2))/(3*a) - (8*(c - a*c*x)^(3/2))/(a*(1 - a*x)) - (2*(1 - a*x)*(c - a*c*x)^(3/2))/(5*a) + (8*Sqrt[2]*(c - a*c*x)^(3/2)*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/(a*(1 - a*x)^(3/2))}
{Sqrt[c - a*c*x]/E^(2*ArcCoth[a*x]), x, 6, (-4*Sqrt[c - a*c*x])/a - (2*(1 - a*x)*Sqrt[c - a*c*x])/(3*a) + (4*Sqrt[2]*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/(a*Sqrt[1 - a*x])}
{1/(E^(2*ArcCoth[a*x])*Sqrt[c - a*c*x]), x, 5, (-2*(1 - a*x))/(a*Sqrt[c - a*c*x]) + (2*Sqrt[2]*Sqrt[1 - a*x]*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/(a*Sqrt[c - a*c*x])}
{1/(E^(2*ArcCoth[a*x])*(c - a*c*x)^(3/2)), x, 4, (Sqrt[2]*(1 - a*x)^(3/2)*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/(a*(c - a*c*x)^(3/2))}
{1/(E^(2*ArcCoth[a*x])*(c - a*c*x)^(5/2)), x, 5, -((1 - a*x)^2/(a*(c - a*c*x)^(5/2))) + ((1 - a*x)^(5/2)*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/(Sqrt[2]*a*(c - a*c*x)^(5/2))}
{1/(E^(2*ArcCoth[a*x])*(c - a*c*x)^(7/2)), x, 6, -(1 - a*x)^2/(3*a*(c - a*c*x)^(7/2)) - (1 - a*x)^3/(2*a*(c - a*c*x)^(7/2)) + ((1 - a*x)^(7/2)*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/(2*Sqrt[2]*a*(c - a*c*x)^(7/2))}


{(c - a*c*x)^(9/2)/E^(3*ArcCoth[a*x]), x, 9, (-16*(a - x^(-1))^5*(c - a*c*x)^(9/2))/(33*a^6*(1 - 1/(a*x))^(9/2)*Sqrt[1 + 1/(a*x)]) - (94208*(c - a*c*x)^(9/2))/(231*a^6*(1 - 1/(a*x))^(9/2)*Sqrt[1 + 1/(a*x)]*x^5) - (40960*(c - a*c*x)^(9/2))/(231*a^5*(1 - 1/(a*x))^(9/2)*Sqrt[1 + 1/(a*x)]*x^4) + (4096*(c - a*c*x)^(9/2))/(231*a^4*(1 - 1/(a*x))^(9/2)*Sqrt[1 + 1/(a*x)]*x^3) - (1024*(a - x^(-1))^3*(c - a*c*x)^(9/2))/(231*a^6*(1 - 1/(a*x))^(9/2)*Sqrt[1 + 1/(a*x)]*x^2) + (320*(a - x^(-1))^4*(c - a*c*x)^(9/2))/(231*a^6*(1 - 1/(a*x))^(9/2)*Sqrt[1 + 1/(a*x)]*x) + (2*(a - x^(-1))^6*x*(c - a*c*x)^(9/2))/(11*a^6*(1 - 1/(a*x))^(9/2)*Sqrt[1 + 1/(a*x)])}
{(c - a*c*x)^(7/2)/E^(3*ArcCoth[a*x]), x, 8, (-40*(a - x^(-1))^4*(c - a*c*x)^(7/2))/(63*a^5*(1 - 1/(a*x))^(7/2)*Sqrt[1 + 1/(a*x)]) + (11776*(c - a*c*x)^(7/2))/(63*a^5*(1 - 1/(a*x))^(7/2)*Sqrt[1 + 1/(a*x)]*x^4) + (5120*(c - a*c*x)^(7/2))/(63*a^4*(1 - 1/(a*x))^(7/2)*Sqrt[1 + 1/(a*x)]*x^3) - (512*(c - a*c*x)^(7/2))/(63*a^3*(1 - 1/(a*x))^(7/2)*Sqrt[1 + 1/(a*x)]*x^2) + (128*(a - x^(-1))^3*(c - a*c*x)^(7/2))/(63*a^5*(1 - 1/(a*x))^(7/2)*Sqrt[1 + 1/(a*x)]*x) + (2*(a - x^(-1))^5*x*(c - a*c*x)^(7/2))/(9*a^5*(1 - 1/(a*x))^(7/2)*Sqrt[1 + 1/(a*x)])}
{(c - a*c*x)^(5/2)/E^(3*ArcCoth[a*x]), x, 7, (-32*(a - x^(-1))^3*(c - a*c*x)^(5/2))/(35*a^4*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)]) - (2944*(c - a*c*x)^(5/2))/(35*a^4*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)]*x^3) - (256*(c - a*c*x)^(5/2))/(7*a^3*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)]*x^2) + (128*(c - a*c*x)^(5/2))/(35*a^2*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)]*x) + (2*(a - x^(-1))^4*x*(c - a*c*x)^(5/2))/(7*a^4*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)])}
{(c - a*c*x)^(3/2)/E^(3*ArcCoth[a*x]), x, 6, (-8*(c - a*c*x)^(3/2))/(5*a*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)]) + (184*(c - a*c*x)^(3/2))/(5*a^3*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)]*x^2) + (16*(c - a*c*x)^(3/2))/(a^2*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)]*x) + (2*(a - x^(-1))^3*x*(c - a*c*x)^(3/2))/(5*a^3*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)])}
{Sqrt[c - a*c*x]/E^(3*ArcCoth[a*x]), x, 5, (-20*Sqrt[c - a*c*x])/(3*a*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]) - (46*Sqrt[c - a*c*x])/(3*a^2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x) + (2*x*Sqrt[c - a*c*x])/(3*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])}
{1/(E^(3*ArcCoth[a*x])*Sqrt[c - a*c*x]), x, 4, (6*Sqrt[1 - 1/(a*x)])/(a*Sqrt[1 + 1/(a*x)]*Sqrt[c - a*c*x]) + (2*Sqrt[1 - 1/(a*x)]*x)/(Sqrt[1 + 1/(a*x)]*Sqrt[c - a*c*x])}
{1/(E^(3*ArcCoth[a*x])*(c - a*c*x)^(3/2)), x, 3, (-2*(1 - 1/(a*x))^(3/2)*x)/(Sqrt[1 + 1/(a*x)]*(c - a*c*x)^(3/2))}
{1/(E^(3*ArcCoth[a*x])*(c - a*c*x)^(5/2)), x, 4, (a*(1 - 1/(a*x))^(5/2)*x^2)/(Sqrt[1 + 1/(a*x)]*(c - a*c*x)^(5/2)) - (a^(3/2)*(1 - 1/(a*x))^(5/2)*ArcTanh[(Sqrt[2]*Sqrt[1/x])/(Sqrt[a]*Sqrt[1 + 1/(a*x)])])/(Sqrt[2]*(1/x)^(5/2)*(c - a*c*x)^(5/2))}
{1/(E^(3*ArcCoth[a*x])*(c - a*c*x)^(7/2)), x, 5, -((a^2*(1 - 1/(a*x))^(7/2)*x^2)/(2*(a - 1/x)*Sqrt[1 + 1/(a*x)]*(c - a*c*x)^(7/2))) - (3*a^2*(1 - 1/(a*x))^(7/2)*x^3)/(4*Sqrt[1 + 1/(a*x)]*(c - a*c*x)^(7/2)) + (3*a^(5/2)*(1 - 1/(a*x))^(7/2)*ArcTanh[(Sqrt[2]*Sqrt[1/x])/(Sqrt[a]*Sqrt[1 + 1/(a*x)])])/(4*Sqrt[2]*(1/x)^(7/2)*(c - a*c*x)^(7/2))}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


(* A bug in Mathematica 8.0.4 simplifying AppellF1 to Hypergeometric2F1 results in Rubi returning an incorrect antiderivative for the following integrand: *) 
(* {E^(n*ArcCoth[a*x])*(c - a*c*x)^(7/2), x, 3, (2*(1 + 1/(a*x))^(9/2)*x*(c - a*c*x)^(7/2)*Hypergeometric2F1[-9/2, (-7 + n)/2, -7/2, 2/((a + x^(-1))*x)])/(9*(1 - 1/(a*x))^(7/2))}
{E^(n*ArcCoth[a*x])*(c - a*c*x)^(5/2), x, 3, (2*(1 + 1/(a*x))^(7/2)*x*(c - a*c*x)^(5/2)*Hypergeometric2F1[-7/2, (-5 + n)/2, -5/2, 2/((a + x^(-1))*x)])/(7*(1 - 1/(a*x))^(5/2))}
{E^(n*ArcCoth[a*x])*(c - a*c*x)^(3/2), x, 3, (2*(1 + 1/(a*x))^(5/2)*x*(c - a*c*x)^(3/2)*Hypergeometric2F1[-5/2, (-3 + n)/2, -3/2, 2/((a + x^(-1))*x)])/(5*(1 - 1/(a*x))^(3/2))}
{E^(n*ArcCoth[a*x])*Sqrt[c - a*c*x], x, 3, (2*(1 + 1/(a*x))^(3/2)*x*Sqrt[c - a*c*x]*Hypergeometric2F1[-3/2, (-1 + n)/2, -1/2, 2/((a + x^(-1))*x)])/(3*Sqrt[1 - 1/(a*x)])}
{E^(n*ArcCoth[a*x])/Sqrt[c - a*c*x], x, 3, (2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x*Hypergeometric2F1[-1/2, (1 + n)/2, 1/2, 2/((a + x^(-1))*x)])/Sqrt[c - a*c*x]}
{E^(n*ArcCoth[a*x])/(c - a*c*x)^(3/2), x, 3, (-2*(1 - 1/(a*x))^(3/2)*x*Hypergeometric2F1[1/2, (3 + n)/2, 3/2, 2/((a + x^(-1))*x)])/(Sqrt[1 + 1/(a*x)]*(c - a*c*x)^(3/2))}
{E^(n*ArcCoth[a*x])/(c - a*c*x)^(5/2), x, 3, (-2*(1 - 1/(a*x))^(5/2)*x*Hypergeometric2F1[3/2, (5 + n)/2, 5/2, 2/((a + x^(-1))*x)])/(3*(1 + 1/(a*x))^(3/2)*(c - a*c*x)^(5/2))}
{E^(n*ArcCoth[a*x])/(c - a*c*x)^(7/2), x, 3, (-2*(1 - 1/(a*x))^(7/2)*x*Hypergeometric2F1[5/2, (7 + n)/2, 7/2, 2/((a + x^(-1))*x)])/(5*(1 + 1/(a*x))^(5/2)*(c - a*c*x)^(7/2))}
{E^(n*ArcCoth[a*x])/(c - a*c*x)^(9/2), x, 3, (-2*(1 - 1/(a*x))^(9/2)*x*Hypergeometric2F1[7/2, (9 + n)/2, 9/2, 2/((a + x^(-1))*x)])/(7*(1 + 1/(a*x))^(7/2)*(c - a*c*x)^(9/2))} *)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(n ArcCoth[a x]) (c-c a x)^p*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{E^ArcCoth[x]*x*(1 + x), x, 7, (5*Sqrt[1 - x^(-1)]*Sqrt[1 + x^(-1)]*x)/3 + (2*Sqrt[1 - x^(-1)]*Sqrt[1 + x^(-1)]*x^2)/3 + (Sqrt[1 - x^(-1)]*(1 + x^(-1))^(3/2)*x^3)/3 + 2*ArcTanh[Sqrt[1 - x^(-1)]/Sqrt[1 + x^(-1)]]}
{E^ArcCoth[x]*(1 + x), x, 5, (3*Sqrt[1 - x^(-1)]*Sqrt[1 + x^(-1)]*x)/2 + (Sqrt[1 - x^(-1)]*(1 + x^(-1))^(3/2)*x^2)/2 + 3*ArcTanh[Sqrt[1 - x^(-1)]/Sqrt[1 + x^(-1)]]}

{E^ArcCoth[x]*(1 - x)*x, x, 5, (Sqrt[1 - x^(-1)]*Sqrt[1 + x^(-1)]*x)/3 - (Sqrt[1 - x^(-1)]*Sqrt[1 + x^(-1)]*x^3)/3}
{E^ArcCoth[x]*(1 - x), x, 5, (Sqrt[1 - x^(-1)]*Sqrt[1 + x^(-1)]*x)/2 - (Sqrt[1 - x^(-1)]*(1 + x^(-1))^(3/2)*x^2)/2 + ArcTanh[Sqrt[1 - x^(-1)]/Sqrt[1 + x^(-1)]]}


{E^ArcCoth[x]*x*(1 + x)^2, x, 8, 3*Sqrt[1 - x^(-1)]*Sqrt[1 + x^(-1)]*x + (9*Sqrt[1 - x^(-1)]*Sqrt[1 + x^(-1)]*x^2)/8 + (Sqrt[1 - x^(-1)]*(1 + x^(-1))^(3/2)*x^3)/2 + (Sqrt[1 - x^(-1)]*(1 + x^(-1))^(5/2)*x^4)/4 + (15*ArcTanh[Sqrt[1 - x^(-1)]/Sqrt[1 + x^(-1)]])/4}
{E^ArcCoth[x]*(1 + x)^2, x, 6, (5*Sqrt[1 - x^(-1)]*Sqrt[1 + x^(-1)]*x)/2 + (5*Sqrt[1 - x^(-1)]*(1 + x^(-1))^(3/2)*x^2)/6 + (Sqrt[1 - x^(-1)]*(1 + x^(-1))^(5/2)*x^3)/3 + 5*ArcTanh[Sqrt[1 - x^(-1)]/Sqrt[1 + x^(-1)]]}

{E^ArcCoth[x]*(1 - x)^2*x, x, 8, (Sqrt[1 - x^(-1)]*Sqrt[1 + x^(-1)]*x)/3 - (Sqrt[1 - x^(-1)]*Sqrt[1 + x^(-1)]*x^2)/8 - (Sqrt[1 - x^(-1)]*Sqrt[1 + x^(-1)]*x^3)/12 + ((1 - x^(-1))^(3/2)*Sqrt[1 + x^(-1)]*x^4)/4 - ArcTanh[Sqrt[1 - x^(-1)]/Sqrt[1 + x^(-1)]]/4}
{E^ArcCoth[x]*(1 - x)^2, x, 6, (Sqrt[1 - x^(-1)]*Sqrt[1 + x^(-1)]*x)/2 - (Sqrt[1 - x^(-1)]*(1 + x^(-1))^(3/2)*x^2)/2 + ((1 - x^(-1))^(3/2)*(1 + x^(-1))^(3/2)*x^3)/3 + ArcTanh[Sqrt[1 - x^(-1)]/Sqrt[1 + x^(-1)]]}


(* ::Subsubsection::Closed:: *)
(*p<0*)


{(E^ArcCoth[x]*x)/(1 + x), x, 4, Sqrt[1 - x^(-1)]*Sqrt[1 + x^(-1)]*x}
{E^ArcCoth[x]/(1 + x), x, 3, 2*ArcTanh[Sqrt[1 - x^(-1)]/Sqrt[1 + x^(-1)]]}

{(E^ArcCoth[x]*x)/(1 - x), x, 5, (2*Sqrt[1 + x^(-1)]*x)/Sqrt[1 - x^(-1)] - 3*Sqrt[1 - x^(-1)]*Sqrt[1 + x^(-1)]*x - 4*ArcTanh[Sqrt[1 - x^(-1)]/Sqrt[1 + x^(-1)]]}
{E^ArcCoth[x]/(1 - x), x, 4, (2*Sqrt[1 + x^(-1)])/Sqrt[1 - x^(-1)] - 2*ArcTanh[Sqrt[1 - x^(-1)]/Sqrt[1 + x^(-1)]]}


{(E^ArcCoth[x]*x)/(1 + x)^2, x, 4, -(Sqrt[1 - x^(-1)]/Sqrt[1 + x^(-1)]) + 2*ArcTanh[Sqrt[1 - x^(-1)]/Sqrt[1 + x^(-1)]]}
{E^ArcCoth[x]/(1 + x)^2, x, 3, Sqrt[1 - x^(-1)]/Sqrt[1 + x^(-1)]}

{(E^ArcCoth[x]*x)/(1 - x)^2, x, 6, (-2*Sqrt[1 + x^(-1)])/(3*(1 - x^(-1))^(3/2)) - (5*Sqrt[1 + x^(-1)])/(3*Sqrt[1 - x^(-1)]) + 2*ArcTanh[Sqrt[1 - x^(-1)]/Sqrt[1 + x^(-1)]]}
{E^ArcCoth[x]/(1 - x)^2, x, 3, -(1 + x^(-1))^(3/2)/(3*(1 - x^(-1))^(3/2))}


(* ::Subsubsection::Closed:: *)
(*p/2>0*)


{E^ArcCoth[x]*x*(1 + x)^(3/2), x, 6, (46*Sqrt[1 - 1/x]*(1 + x)^(3/2))/(21*(1 + 1/x)^(3/2)) + (92*Sqrt[1 - 1/x]*(1 + x)^(3/2))/(21*(1 + 1/x)^(3/2)*x) + (8*Sqrt[1 - 1/x]*x*(1 + x)^(3/2))/(7*(1 + 1/x)^(3/2)) + (2*Sqrt[1 - 1/x]*x^2*(1 + x)^(3/2))/(7*(1 + 1/x)^(3/2))}
{E^ArcCoth[x]*(1 + x)^(3/2), x, 5, (28*Sqrt[1 - x^(-1)]*(1 + x)^(3/2))/(15*(1 + x^(-1))^(3/2)) + (86*Sqrt[1 - x^(-1)]*(1 + x)^(3/2))/(15*(1 + x^(-1))^(3/2)*x) + (2*Sqrt[1 - x^(-1)]*x*(1 + x)^(3/2))/(5*(1 + x^(-1))^(3/2))}

{E^ArcCoth[x]*(1 - x)^(3/2)*x, x, 5, (44*(1 + 1/x)^(3/2)*(1 - x)^(3/2))/(105*(1 - 1/x)^(3/2)) - (22*(1 + 1/x)^(3/2)*(1 - x)^(3/2)*x)/(35*(1 - 1/x)^(3/2)) + (2*(1 + 1/x)^(3/2)*(1 - x)^(3/2)*x^2)/(7*(1 - 1/x)^(3/2))}
{E^ArcCoth[x]*(1 - x)^(3/2), x, 4, (-14*(1 + x^(-1))^(3/2)*(1 - x)^(3/2))/(15*(1 - x^(-1))^(3/2)) + (2*(1 + x^(-1))^(3/2)*(1 - x)^(3/2)*x)/(5*(1 - x^(-1))^(3/2))}


{E^ArcCoth[x]*x*Sqrt[1 + x], x, 5, (12*Sqrt[1 - 1/x]*Sqrt[1 + x])/(5*Sqrt[1 + 1/x]) + (6*Sqrt[1 - 1/x]*x*Sqrt[1 + x])/(5*Sqrt[1 + 1/x]) + (2*Sqrt[1 - 1/x]*x^2*Sqrt[1 + x])/(5*Sqrt[1 + 1/x])}
{E^ArcCoth[x]*Sqrt[1 + x], x, 4, (10*Sqrt[1 - x^(-1)]*Sqrt[1 + x])/(3*Sqrt[1 + x^(-1)]) + (2*Sqrt[1 - x^(-1)]*x*Sqrt[1 + x])/(3*Sqrt[1 + x^(-1)])}

{E^ArcCoth[x]*Sqrt[1 - x]*x, x, 4, -((4*(1 + 1/x)^(3/2)*Sqrt[1 - x]*x)/(15*Sqrt[1 - 1/x])) + (2*(1 + 1/x)^(3/2)*Sqrt[1 - x]*x^2)/(5*Sqrt[1 - 1/x])}
{E^ArcCoth[x]*Sqrt[1 - x], x, 3, (2*(1 + x^(-1))^(3/2)*Sqrt[1 - x]*x)/(3*Sqrt[1 - x^(-1)])}


(* ::Subsubsection::Closed:: *)
(*p/2<0*)


{(E^ArcCoth[x]*x)/Sqrt[1 + x], x, 4, (4*Sqrt[1 - 1/x]*Sqrt[1 + 1/x]*x)/(3*Sqrt[1 + x]) + (2*Sqrt[1 - 1/x]*Sqrt[1 + 1/x]*x^2)/(3*Sqrt[1 + x])}
{E^ArcCoth[x]/Sqrt[1 + x], x, 3, (2*Sqrt[1 - x^(-1)]*Sqrt[1 + x^(-1)]*x)/Sqrt[1 + x]}

{(E^ArcCoth[x]*x)/Sqrt[1 - x], x, 6, (8*Sqrt[1 - 1/x]*Sqrt[1 + 1/x]*x)/(3*Sqrt[1 - x]) + (2*Sqrt[1 - 1/x]*Sqrt[1 + 1/x]*x^2)/(3*Sqrt[1 - x]) - (2*Sqrt[2]*Sqrt[1 - 1/x]*ArcTanh[(Sqrt[2]*Sqrt[1/x])/Sqrt[1 + 1/x]])/(Sqrt[1 - x]*Sqrt[1/x])}
{E^ArcCoth[x]/Sqrt[1 - x], x, 4, (2*Sqrt[1 - x^(-1)]*Sqrt[1 + x^(-1)]*x)/Sqrt[1 - x] - (2*Sqrt[2]*Sqrt[1 - x^(-1)]*ArcTanh[(Sqrt[2]*Sqrt[x^(-1)])/Sqrt[1 + x^(-1)]])/(Sqrt[1 - x]*Sqrt[x^(-1)])}


{(E^ArcCoth[x]*x)/(1 + x)^(3/2), x, 5, (2*Sqrt[1 - 1/x]*(1 + 1/x)^(3/2)*x^2)/(1 + x)^(3/2) + (Sqrt[2]*(1 + 1/x)^(3/2)*ArcTan[(Sqrt[2]*Sqrt[1/x])/Sqrt[1 - 1/x]])/((1/x)^(3/2)*(1 + x)^(3/2))}
{E^ArcCoth[x]/(1 + x)^(3/2), x, 3, -((Sqrt[2]*(1 + 1/x)^(3/2)*ArcTan[(Sqrt[2]*Sqrt[1/x])/Sqrt[1 - 1/x]])/((1/x)^(3/2)*(1 + x)^(3/2)))}

{(E^ArcCoth[x]*x)/(1 - x)^(3/2), x, 6, -((Sqrt[1 - 1/x]*Sqrt[1 + 1/x]*x^2)/(1 - x)^(3/2)) + (3*(1 - 1/x)^(3/2)*Sqrt[1 + 1/x]*x^2)/(1 - x)^(3/2) - (5*(1 - 1/x)^(3/2)*ArcTanh[(Sqrt[2]*Sqrt[1/x])/Sqrt[1 + 1/x]])/(Sqrt[2]*(1 - x)^(3/2)*(1/x)^(3/2))}
{E^ArcCoth[x]/(1 - x)^(3/2), x, 4, -((Sqrt[1 - x^(-1)]*Sqrt[1 + x^(-1)]*x)/(1 - x)^(3/2)) - ((1 - x^(-1))^(3/2)*ArcTanh[(Sqrt[2]*Sqrt[x^(-1)])/Sqrt[1 + x^(-1)]])/(Sqrt[2]*(1 - x)^(3/2)*(x^(-1))^(3/2))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(n ArcCoth[a x]) (c-c a x)^(p/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{E^ArcCoth[a*x]*x^m*Sqrt[c - a*c*x], x, 7, (4*m*Sqrt[1 + 1/(a*x)]*x^(-1 + m)*Sqrt[c - a*c*x])/(a^2*(3 + 2*m)*(1 - 4*m^2)*Sqrt[1 - 1/(a*x)]) + (2*Sqrt[1 + 1/(a*x)]*x^m*Sqrt[c - a*c*x])/(a*(3 + 8*m + 4*m^2)*Sqrt[1 - 1/(a*x)]) + (Sqrt[1 + 1/(a*x)]*x^(1 + m)*Sqrt[c - a*c*x])/((1 + m)*Sqrt[1 - 1/(a*x)]) - (Sqrt[1 + 1/(a*x)]*x^(1 + m)*Sqrt[c - a*c*x])/((3 + 5*m + 2*m^2)*Sqrt[1 - 1/(a*x)]) - (8*(1 - m)*m*Sqrt[1 + 1/(a*x)]*(-(1/(a*x)))^(-1/2 + m)*x^(-1 + m)*Sqrt[c - a*c*x]*Hypergeometric2F1[1/2, -1/2 + m, 3/2, 1 + 1/(a*x)])/(a^2*(3 + 2*m)*(1 - 4*m^2)*Sqrt[1 - 1/(a*x)])}

{E^ArcCoth[a*x]*x^2*Sqrt[c - a*c*x], x, 5, (16*(1 + 1/(a*x))^(3/2)*x*Sqrt[c - a*c*x])/(105*a^2*Sqrt[1 - 1/(a*x)]) - (8*(1 + 1/(a*x))^(3/2)*x^2*Sqrt[c - a*c*x])/(35*a*Sqrt[1 - 1/(a*x)]) + (2*(1 + 1/(a*x))^(3/2)*x^3*Sqrt[c - a*c*x])/(7*Sqrt[1 - 1/(a*x)])}
{E^ArcCoth[a*x]*x*Sqrt[c - a*c*x], x, 4, (-4*(1 + 1/(a*x))^(3/2)*x*Sqrt[c - a*c*x])/(15*a*Sqrt[1 - 1/(a*x)]) + (2*(1 + 1/(a*x))^(3/2)*x^2*Sqrt[c - a*c*x])/(5*Sqrt[1 - 1/(a*x)])}
{E^ArcCoth[a*x]*Sqrt[c - a*c*x], x, 3, (2*(1 + 1/(a*x))^(3/2)*x*Sqrt[c - a*c*x])/(3*Sqrt[1 - 1/(a*x)])}
{(E^ArcCoth[a*x]*Sqrt[c - a*c*x])/x, x, 4, (2*Sqrt[1 + 1/(a*x)]*Sqrt[c - a*c*x])/Sqrt[1 - 1/(a*x)] - (2*Sqrt[x^(-1)]*Sqrt[c - a*c*x]*ArcSinh[Sqrt[x^(-1)]/Sqrt[a]])/(Sqrt[a]*Sqrt[1 - 1/(a*x)])}
{(E^ArcCoth[a*x]*Sqrt[c - a*c*x])/x^2, x, 4, -((Sqrt[1 + 1/(a*x)]*Sqrt[c - a*c*x])/(Sqrt[1 - 1/(a*x)]*x)) - (Sqrt[a]*Sqrt[x^(-1)]*Sqrt[c - a*c*x]*ArcSinh[Sqrt[x^(-1)]/Sqrt[a]])/Sqrt[1 - 1/(a*x)]}


{E^(2*ArcCoth[a*x])*x^3*Sqrt[c - a*c*x], x, 5, (4*Sqrt[c - a*c*x])/a^4 - (14*(1 - a*x)*Sqrt[c - a*c*x])/(3*a^4) + (18*(1 - a*x)^2*Sqrt[c - a*c*x])/(5*a^4) - (10*(1 - a*x)^3*Sqrt[c - a*c*x])/(7*a^4) + (2*(1 - a*x)^4*Sqrt[c - a*c*x])/(9*a^4)}
{E^(2*ArcCoth[a*x])*x^2*Sqrt[c - a*c*x], x, 5, (4*Sqrt[c - a*c*x])/a^3 - (10*(1 - a*x)*Sqrt[c - a*c*x])/(3*a^3) + (8*(1 - a*x)^2*Sqrt[c - a*c*x])/(5*a^3) - (2*(1 - a*x)^3*Sqrt[c - a*c*x])/(7*a^3)}
{E^(2*ArcCoth[a*x])*x*Sqrt[c - a*c*x], x, 5, (4*Sqrt[c - a*c*x])/a^2 - (2*(1 - a*x)*Sqrt[c - a*c*x])/a^2 + (2*(1 - a*x)^2*Sqrt[c - a*c*x])/(5*a^2)}
{E^(2*ArcCoth[a*x])*Sqrt[c - a*c*x], x, 5, (4*Sqrt[c - a*c*x])/a - (2*(1 - a*x)*Sqrt[c - a*c*x])/(3*a)}
{(E^(2*ArcCoth[a*x])*Sqrt[c - a*c*x])/x, x, 5, 2*Sqrt[c - a*c*x] + (2*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]])/Sqrt[1 - a*x]}
{(E^(2*ArcCoth[a*x])*Sqrt[c - a*c*x])/x^2, x, 5, Sqrt[c - a*c*x]/x + (3*a*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]])/Sqrt[1 - a*x]}
{(E^(2*ArcCoth[a*x])*Sqrt[c - a*c*x])/x^3, x, 6, Sqrt[c - a*c*x]/(2*x^2) + (7*a*Sqrt[c - a*c*x])/(4*x) + (7*a^2*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]])/(4*Sqrt[1 - a*x])}
{(E^(2*ArcCoth[a*x])*Sqrt[c - a*c*x])/x^4, x, 7, Sqrt[c - a*c*x]/(3*x^3) + (11*a*Sqrt[c - a*c*x])/(12*x^2) + (11*a^2*Sqrt[c - a*c*x])/(8*x) + (11*a^3*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]])/(8*Sqrt[1 - a*x])}
{(E^(2*ArcCoth[a*x])*Sqrt[c - a*c*x])/x^5, x, 8, Sqrt[c - a*c*x]/(4*x^4) + (5*a*Sqrt[c - a*c*x])/(8*x^3) + (25*a^2*Sqrt[c - a*c*x])/(32*x^2) + (75*a^3*Sqrt[c - a*c*x])/(64*x) + (75*a^4*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]])/(64*Sqrt[1 - a*x])}


{E^(3*ArcCoth[a*x])*x^3*Sqrt[c - a*c*x], x, 9, (1576*Sqrt[1 + 1/(a*x)]*Sqrt[c - a*c*x])/(315*a^4*Sqrt[1 - 1/(a*x)]) + (472*Sqrt[1 + 1/(a*x)]*x*Sqrt[c - a*c*x])/(315*a^3*Sqrt[1 - 1/(a*x)]) + (92*Sqrt[1 + 1/(a*x)]*x^2*Sqrt[c - a*c*x])/(105*a^2*Sqrt[1 - 1/(a*x)]) + (8*Sqrt[1 + 1/(a*x)]*x^3*Sqrt[c - a*c*x])/(21*a*Sqrt[1 - 1/(a*x)]) + (2*(1 + 1/(a*x))^(3/2)*x^4*Sqrt[c - a*c*x])/(9*Sqrt[1 - 1/(a*x)]) - (4*Sqrt[2]*Sqrt[1/x]*Sqrt[c - a*c*x]*ArcTanh[(Sqrt[2]*Sqrt[1/x])/(Sqrt[a]*Sqrt[1 + 1/(a*x)])])/(a^(9/2)*Sqrt[1 - 1/(a*x)])}
{E^(3*ArcCoth[a*x])*x^2*Sqrt[c - a*c*x], x, 8, (104*Sqrt[1 + 1/(a*x)]*Sqrt[c - a*c*x])/(21*a^3*Sqrt[1 - 1/(a*x)]) + (32*Sqrt[1 + 1/(a*x)]*x*Sqrt[c - a*c*x])/(21*a^2*Sqrt[1 - 1/(a*x)]) + (4*Sqrt[1 + 1/(a*x)]*x^2*Sqrt[c - a*c*x])/(7*a*Sqrt[1 - 1/(a*x)]) + (2*(1 + 1/(a*x))^(3/2)*x^3*Sqrt[c - a*c*x])/(7*Sqrt[1 - 1/(a*x)]) - (4*Sqrt[2]*Sqrt[1/x]*Sqrt[c - a*c*x]*ArcTanh[(Sqrt[2]*Sqrt[1/x])/(Sqrt[a]*Sqrt[1 + 1/(a*x)])])/(a^(7/2)*Sqrt[1 - 1/(a*x)])}
{E^(3*ArcCoth[a*x])*x*Sqrt[c - a*c*x], x, 7, (76*Sqrt[1 + 1/(a*x)]*Sqrt[c - a*c*x])/(15*a^2*Sqrt[1 - 1/(a*x)]) + (16*Sqrt[1 + 1/(a*x)]*x*Sqrt[c - a*c*x])/(15*a*Sqrt[1 - 1/(a*x)]) + (2*(1 + 1/(a*x))^(3/2)*x^2*Sqrt[c - a*c*x])/(5*Sqrt[1 - 1/(a*x)]) - (4*Sqrt[2]*Sqrt[1/x]*Sqrt[c - a*c*x]*ArcTanh[(Sqrt[2]*Sqrt[1/x])/(Sqrt[a]*Sqrt[1 + 1/(a*x)])])/(a^(5/2)*Sqrt[1 - 1/(a*x)])}
{E^(3*ArcCoth[a*x])*Sqrt[c - a*c*x], x, 5, (4*Sqrt[1 + 1/(a*x)]*Sqrt[c - a*c*x])/(a*Sqrt[1 - 1/(a*x)]) + (2*(1 + 1/(a*x))^(3/2)*x*Sqrt[c - a*c*x])/(3*Sqrt[1 - 1/(a*x)]) - (4*Sqrt[2]*Sqrt[1/x]*Sqrt[c - a*c*x]*ArcTanh[(Sqrt[2]*Sqrt[1/x])/(Sqrt[a]*Sqrt[1 + 1/(a*x)])])/(a^(3/2)*Sqrt[1 - 1/(a*x)])}
{(E^(3*ArcCoth[a*x])*Sqrt[c - a*c*x])/x, x, 7, (2*(1 + 1/(a*x))^(3/2)*Sqrt[c - a*c*x])/Sqrt[1 - 1/(a*x)] - (2*Sqrt[1 + 1/(a*x)]*Sqrt[c - a*c*x])/(a*Sqrt[1 - 1/(a*x)]*x) + (2*Sqrt[1/x]*Sqrt[c - a*c*x]*ArcSinh[Sqrt[1/x]/Sqrt[a]])/(Sqrt[a]*Sqrt[1 - 1/(a*x)]) - (4*Sqrt[2]*Sqrt[1/x]*Sqrt[c - a*c*x]*ArcTanh[(Sqrt[2]*Sqrt[1/x])/(Sqrt[a]*Sqrt[1 + 1/(a*x)])])/(Sqrt[a]*Sqrt[1 - 1/(a*x)])}
{(E^(3*ArcCoth[a*x])*Sqrt[c - a*c*x])/x^2, x, 6, (Sqrt[1 + 1/(a*x)]*Sqrt[c - a*c*x])/(Sqrt[1 - 1/(a*x)]*x) + (5*Sqrt[a]*Sqrt[1/x]*Sqrt[c - a*c*x]*ArcSinh[Sqrt[1/x]/Sqrt[a]])/Sqrt[1 - 1/(a*x)] - (4*Sqrt[2]*Sqrt[a]*Sqrt[1/x]*Sqrt[c - a*c*x]*ArcTanh[(Sqrt[2]*Sqrt[1/x])/(Sqrt[a]*Sqrt[1 + 1/(a*x)])])/Sqrt[1 - 1/(a*x)]}
{(E^(3*ArcCoth[a*x])*Sqrt[c - a*c*x])/x^3, x, 7, (7*a*Sqrt[1 + 1/(a*x)]*Sqrt[c - a*c*x])/(4*Sqrt[1 - 1/(a*x)]*x) + (a*(1 + 1/(a*x))^(3/2)*Sqrt[c - a*c*x])/(2*Sqrt[1 - 1/(a*x)]*x) + (23*a^(3/2)*Sqrt[1/x]*Sqrt[c - a*c*x]*ArcSinh[Sqrt[1/x]/Sqrt[a]])/(4*Sqrt[1 - 1/(a*x)]) - (4*Sqrt[2]*a^(3/2)*Sqrt[1/x]*Sqrt[c - a*c*x]*ArcTanh[(Sqrt[2]*Sqrt[1/x])/(Sqrt[a]*Sqrt[1 + 1/(a*x)])])/Sqrt[1 - 1/(a*x)]}
{(E^(3*ArcCoth[a*x])*Sqrt[c - a*c*x])/x^4, x, 8, (a*(1 + 1/(a*x))^(3/2)*Sqrt[c - a*c*x])/(3*Sqrt[1 - 1/(a*x)]*x^2) + (13*a^2*Sqrt[1 + 1/(a*x)]*Sqrt[c - a*c*x])/(8*Sqrt[1 - 1/(a*x)]*x) + (3*a^2*(1 + 1/(a*x))^(3/2)*Sqrt[c - a*c*x])/(4*Sqrt[1 - 1/(a*x)]*x) + (45*a^(5/2)*Sqrt[1/x]*Sqrt[c - a*c*x]*ArcSinh[Sqrt[1/x]/Sqrt[a]])/(8*Sqrt[1 - 1/(a*x)]) - (4*Sqrt[2]*a^(5/2)*Sqrt[1/x]*Sqrt[c - a*c*x]*ArcTanh[(Sqrt[2]*Sqrt[1/x])/(Sqrt[a]*Sqrt[1 + 1/(a*x)])])/Sqrt[1 - 1/(a*x)]}
{(E^(3*ArcCoth[a*x])*Sqrt[c - a*c*x])/x^5, x, 9, (a*(1 + 1/(a*x))^(3/2)*Sqrt[c - a*c*x])/(4*Sqrt[1 - 1/(a*x)]*x^3) + (11*a^2*(1 + 1/(a*x))^(3/2)*Sqrt[c - a*c*x])/(24*Sqrt[1 - 1/(a*x)]*x^2) + (107*a^3*Sqrt[1 + 1/(a*x)]*Sqrt[c - a*c*x])/(64*Sqrt[1 - 1/(a*x)]*x) + (21*a^3*(1 + 1/(a*x))^(3/2)*Sqrt[c - a*c*x])/(32*Sqrt[1 - 1/(a*x)]*x) + (363*a^(7/2)*Sqrt[1/x]*Sqrt[c - a*c*x]*ArcSinh[Sqrt[1/x]/Sqrt[a]])/(64*Sqrt[1 - 1/(a*x)]) - (4*Sqrt[2]*a^(7/2)*Sqrt[1/x]*Sqrt[c - a*c*x]*ArcTanh[(Sqrt[2]*Sqrt[1/x])/(Sqrt[a]*Sqrt[1 + 1/(a*x)])])/Sqrt[1 - 1/(a*x)]}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(x^m*Sqrt[c - a*c*x])/E^ArcCoth[a*x], x, 6, (-4*m*(5 + 4*m)*Sqrt[1 + 1/(a*x)]*x^(-1 + m)*Sqrt[c - a*c*x])/(a^2*(3 + 2*m)*(1 - 4*m^2)*Sqrt[1 - 1/(a*x)]) - (2*(5 + 4*m)*Sqrt[1 + 1/(a*x)]*x^m*Sqrt[c - a*c*x])/(a*(1 + 2*m)*(3 + 2*m)*Sqrt[1 - 1/(a*x)]) + (2*Sqrt[1 + 1/(a*x)]*x^(1 + m)*Sqrt[c - a*c*x])/((3 + 2*m)*Sqrt[1 - 1/(a*x)]) + (8*(1 - m)*m*(5 + 4*m)*Sqrt[1 + 1/(a*x)]*(-(1/(a*x)))^(-1/2 + m)*x^(-1 + m)*Sqrt[c - a*c*x]*Hypergeometric2F1[1/2, -1/2 + m, 3/2, 1 + 1/(a*x)])/(a^2*(3 + 2*m)*(1 - 4*m^2)*Sqrt[1 - 1/(a*x)])}

{(x^2*Sqrt[c - a*c*x])/E^ArcCoth[a*x], x, 6, (-208*Sqrt[1 + 1/(a*x)]*Sqrt[c - a*c*x])/(105*a^3*Sqrt[1 - 1/(a*x)]) + (104*Sqrt[1 + 1/(a*x)]*x*Sqrt[c - a*c*x])/(105*a^2*Sqrt[1 - 1/(a*x)]) - (26*Sqrt[1 + 1/(a*x)]*x^2*Sqrt[c - a*c*x])/(35*a*Sqrt[1 - 1/(a*x)]) + (2*Sqrt[1 + 1/(a*x)]*x^3*Sqrt[c - a*c*x])/(7*Sqrt[1 - 1/(a*x)])}
{(x*Sqrt[c - a*c*x])/E^ArcCoth[a*x], x, 5, (12*Sqrt[1 + 1/(a*x)]*Sqrt[c - a*c*x])/(5*a^2*Sqrt[1 - 1/(a*x)]) - (6*Sqrt[1 + 1/(a*x)]*x*Sqrt[c - a*c*x])/(5*a*Sqrt[1 - 1/(a*x)]) + (2*Sqrt[1 + 1/(a*x)]*x^2*Sqrt[c - a*c*x])/(5*Sqrt[1 - 1/(a*x)])}
{Sqrt[c - a*c*x]/E^ArcCoth[a*x], x, 4, (-10*Sqrt[1 + 1/(a*x)]*Sqrt[c - a*c*x])/(3*a*Sqrt[1 - 1/(a*x)]) + (2*Sqrt[1 + 1/(a*x)]*x*Sqrt[c - a*c*x])/(3*Sqrt[1 - 1/(a*x)])}
{Sqrt[c - a*c*x]/(E^ArcCoth[a*x]*x), x, 4, (2*Sqrt[1 + 1/(a*x)]*Sqrt[c - a*c*x])/Sqrt[1 - 1/(a*x)] + (2*Sqrt[x^(-1)]*Sqrt[c - a*c*x]*ArcSinh[Sqrt[x^(-1)]/Sqrt[a]])/(Sqrt[a]*Sqrt[1 - 1/(a*x)])}
{Sqrt[c - a*c*x]/(E^ArcCoth[a*x]*x^2), x, 4, (Sqrt[1 + 1/(a*x)]*Sqrt[c - a*c*x])/(Sqrt[1 - 1/(a*x)]*x) - (3*Sqrt[a]*Sqrt[x^(-1)]*Sqrt[c - a*c*x]*ArcSinh[Sqrt[x^(-1)]/Sqrt[a]])/Sqrt[1 - 1/(a*x)]}


{(x^3*Sqrt[c - a*c*x])/E^(2*ArcCoth[a*x]), x, 9, (4*Sqrt[c - a*c*x])/a^4 + (316*(1 - a*x)*Sqrt[c - a*c*x])/(315*a^4) - (52*x*(1 - a*x)*Sqrt[c - a*c*x])/(105*a^3) + (8*x^2*(1 - a*x)*Sqrt[c - a*c*x])/(21*a^2) - (2*x^3*(1 - a*x)*Sqrt[c - a*c*x])/(9*a) - (4*Sqrt[2]*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/(a^4*Sqrt[1 - a*x])}
{(x^2*Sqrt[c - a*c*x])/E^(2*ArcCoth[a*x]), x, 8, (-4*Sqrt[c - a*c*x])/a^3 - (2*(1 - a*x)*Sqrt[c - a*c*x])/(3*a^3) - (2*(1 - a*x)^2*Sqrt[c - a*c*x])/(7*a^3) + (2*x*(1 - a*x)^2*Sqrt[c - a*c*x])/(7*a^2) + (4*Sqrt[2]*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/(a^3*Sqrt[1 - a*x])}
{(x*Sqrt[c - a*c*x])/E^(2*ArcCoth[a*x]), x, 7, (4*Sqrt[c - a*c*x])/a^2 + (2*(1 - a*x)*Sqrt[c - a*c*x])/(3*a^2) + (2*(1 - a*x)^2*Sqrt[c - a*c*x])/(5*a^2) - (4*Sqrt[2]*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/(a^2*Sqrt[1 - a*x])}
{Sqrt[c - a*c*x]/E^(2*ArcCoth[a*x]), x, 6, (-4*Sqrt[c - a*c*x])/a - (2*(1 - a*x)*Sqrt[c - a*c*x])/(3*a) + (4*Sqrt[2]*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/(a*Sqrt[1 - a*x])}
{Sqrt[c - a*c*x]/(E^(2*ArcCoth[a*x])*x), x, 7, 2*Sqrt[c - a*c*x] + (2*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]])/Sqrt[1 - a*x] - (4*Sqrt[2]*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/Sqrt[1 - a*x]}
{Sqrt[c - a*c*x]/(E^(2*ArcCoth[a*x])*x^2), x, 8, a*Sqrt[c - a*c*x] + ((1 - a*x)*Sqrt[c - a*c*x])/x - (5*a*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]])/Sqrt[1 - a*x] + (4*Sqrt[2]*a*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/Sqrt[1 - a*x]}
{Sqrt[c - a*c*x]/(E^(2*ArcCoth[a*x])*x^3), x, 8, (-7*a*Sqrt[c - a*c*x])/(4*x) + ((1 - a*x)*Sqrt[c - a*c*x])/(2*x^2) + (23*a^2*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]])/(4*Sqrt[1 - a*x]) - (4*Sqrt[2]*a^2*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/Sqrt[1 - a*x]}
{Sqrt[c - a*c*x]/(E^(2*ArcCoth[a*x])*x^4), x, 9, (-3*a*Sqrt[c - a*c*x])/(4*x^2) + (19*a^2*Sqrt[c - a*c*x])/(8*x) + ((1 - a*x)*Sqrt[c - a*c*x])/(3*x^3) - (45*a^3*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]])/(8*Sqrt[1 - a*x]) + (4*Sqrt[2]*a^3*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/Sqrt[1 - a*x]}
{Sqrt[c - a*c*x]/(E^(2*ArcCoth[a*x])*x^5), x, 10, (-11*a*Sqrt[c - a*c*x])/(24*x^3) + (107*a^2*Sqrt[c - a*c*x])/(96*x^2) - (149*a^3*Sqrt[c - a*c*x])/(64*x) + ((1 - a*x)*Sqrt[c - a*c*x])/(4*x^4) + (363*a^4*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]])/(64*Sqrt[1 - a*x]) - (4*Sqrt[2]*a^4*Sqrt[c - a*c*x]*ArcTanh[Sqrt[1 - a*x]/Sqrt[2]])/Sqrt[1 - a*x]}


{(x^3*Sqrt[c - a*c*x])/E^(3*ArcCoth[a*x]), x, 8, (1312*Sqrt[1 + 1/(a*x)]*Sqrt[c - a*c*x])/(45*a^4*Sqrt[1 - 1/(a*x)]) - (656*Sqrt[1 + 1/(a*x)]*x*Sqrt[c - a*c*x])/(45*a^3*Sqrt[1 - 1/(a*x)]) - (82*x^2*Sqrt[c - a*c*x])/(9*a^2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]) + (164*Sqrt[1 + 1/(a*x)]*x^2*Sqrt[c - a*c*x])/(15*a^2*Sqrt[1 - 1/(a*x)]) - (8*x^3*Sqrt[c - a*c*x])/(9*a*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]) + (2*x^4*Sqrt[c - a*c*x])/(9*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])}
{(x^2*Sqrt[c - a*c*x])/E^(3*ArcCoth[a*x]), x, 7, (-2672*Sqrt[1 + 1/(a*x)]*Sqrt[c - a*c*x])/(105*a^3*Sqrt[1 - 1/(a*x)]) - (334*x*Sqrt[c - a*c*x])/(35*a^2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]) + (1336*Sqrt[1 + 1/(a*x)]*x*Sqrt[c - a*c*x])/(105*a^2*Sqrt[1 - 1/(a*x)]) - (44*x^2*Sqrt[c - a*c*x])/(35*a*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]) + (2*x^3*Sqrt[c - a*c*x])/(7*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])}
{(x*Sqrt[c - a*c*x])/E^(3*ArcCoth[a*x]), x, 6, (-158*Sqrt[c - a*c*x])/(15*a^2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]) + (316*Sqrt[1 + 1/(a*x)]*Sqrt[c - a*c*x])/(15*a^2*Sqrt[1 - 1/(a*x)]) - (32*x*Sqrt[c - a*c*x])/(15*a*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]) + (2*x^2*Sqrt[c - a*c*x])/(5*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])}
{Sqrt[c - a*c*x]/E^(3*ArcCoth[a*x]), x, 5, (-20*Sqrt[c - a*c*x])/(3*a*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]) - (46*Sqrt[c - a*c*x])/(3*a^2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x) + (2*x*Sqrt[c - a*c*x])/(3*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])}
{Sqrt[c - a*c*x]/(E^(3*ArcCoth[a*x])*x), x, 5, (2*Sqrt[c - a*c*x])/(Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]) + (10*Sqrt[c - a*c*x])/(a*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x) - (2*Sqrt[x^(-1)]*Sqrt[c - a*c*x]*ArcSinh[Sqrt[x^(-1)]/Sqrt[a]])/(Sqrt[a]*Sqrt[1 - 1/(a*x)])}
{Sqrt[c - a*c*x]/(E^(3*ArcCoth[a*x])*x^2), x, 5, (-8*Sqrt[c - a*c*x])/(Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x) - (Sqrt[1 + 1/(a*x)]*Sqrt[c - a*c*x])/(Sqrt[1 - 1/(a*x)]*x) + (7*Sqrt[a]*Sqrt[x^(-1)]*Sqrt[c - a*c*x]*ArcSinh[Sqrt[x^(-1)]/Sqrt[a]])/Sqrt[1 - 1/(a*x)]}
{Sqrt[c - a*c*x]/(E^(3*ArcCoth[a*x])*x^3), x, 6, (-8*Sqrt[c - a*c*x])/(Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x^2) - (Sqrt[1 + 1/(a*x)]*Sqrt[c - a*c*x])/(2*Sqrt[1 - 1/(a*x)]*x^2) + (47*a*Sqrt[1 + 1/(a*x)]*Sqrt[c - a*c*x])/(4*Sqrt[1 - 1/(a*x)]*x) - (47*a^(3/2)*Sqrt[x^(-1)]*Sqrt[c - a*c*x]*ArcSinh[Sqrt[x^(-1)]/Sqrt[a]])/(4*Sqrt[1 - 1/(a*x)])}
{Sqrt[c - a*c*x]/(E^(3*ArcCoth[a*x])*x^4), x, 7, (-8*Sqrt[c - a*c*x])/(Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x^3) - (Sqrt[1 + 1/(a*x)]*Sqrt[c - a*c*x])/(3*Sqrt[1 - 1/(a*x)]*x^3) + (119*a*Sqrt[1 + 1/(a*x)]*Sqrt[c - a*c*x])/(12*Sqrt[1 - 1/(a*x)]*x^2) - (119*a^2*Sqrt[1 + 1/(a*x)]*Sqrt[c - a*c*x])/(8*Sqrt[1 - 1/(a*x)]*x) + (119*a^(5/2)*Sqrt[x^(-1)]*Sqrt[c - a*c*x]*ArcSinh[Sqrt[x^(-1)]/Sqrt[a]])/(8*Sqrt[1 - 1/(a*x)])}
{Sqrt[c - a*c*x]/(E^(3*ArcCoth[a*x])*x^5), x, 8, (-8*Sqrt[c - a*c*x])/(Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x^4) - (Sqrt[1 + 1/(a*x)]*Sqrt[c - a*c*x])/(4*Sqrt[1 - 1/(a*x)]*x^4) + (223*a*Sqrt[1 + 1/(a*x)]*Sqrt[c - a*c*x])/(24*Sqrt[1 - 1/(a*x)]*x^3) - (1115*a^2*Sqrt[1 + 1/(a*x)]*Sqrt[c - a*c*x])/(96*Sqrt[1 - 1/(a*x)]*x^2) + (1115*a^3*Sqrt[1 + 1/(a*x)]*Sqrt[c - a*c*x])/(64*Sqrt[1 - 1/(a*x)]*x) - (1115*a^(7/2)*Sqrt[x^(-1)]*Sqrt[c - a*c*x]*ArcSinh[Sqrt[x^(-1)]/Sqrt[a]])/(64*Sqrt[1 - 1/(a*x)])}


(* ::Subsection::Closed:: *)
(*Integrands of the form E^(n ArcCoth[a x]) (c-c/(a x))^p*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{E^ArcCoth[a*x]*(c - c/(a*x))^p, x, 3, (2*Sqrt[2]*Sqrt[1 - 1/(a*x)]*(c - c/(a*x))^p*AppellF1[1/2 + p, 2, -(1/2), 3/2 + p, 1 - 1/(a*x), (a - 1/x)/(2*a)])/(a*(1 + 2*p))}

{E^ArcCoth[a*x]*(c - c/(a*x))^4, x, 8, (5*c^4*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/(2*a) + (11*c^4*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)])/(6*a) + (4*c^4*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)])/(3*a) + c^4*(1 - 1/(a*x))^(7/2)*Sqrt[1 + 1/(a*x)]*x - (c^4*ArcSin[1/(a*x)])/(2*a) - (6*c^4*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{E^ArcCoth[a*x]*(c - c/(a*x))^3, x, 7, (5*c^3*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/(2*a) + (3*c^3*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)])/(2*a) + c^3*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)]*x + (c^3*ArcSin[1/(a*x)])/(2*a) - (4*c^3*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{E^ArcCoth[a*x]*(c - c/(a*x))^2, x, 7, c^2*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2)*x + (c^2*ArcSin[1/(a*x)])/a - (2*c^2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a, (2*c^2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/a + c^2*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)]*x + (c^2*ArcSin[1/(a*x)])/a - (2*c^2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{E^ArcCoth[a*x]*(c - c/(a*x)), x, 4, c*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x + (c*ArcSin[1/(a*x)])/a}
{E^ArcCoth[a*x]/(c - c/(a*x)), x, 5, -((3*Sqrt[1 + 1/(a*x)])/(a*c*Sqrt[1 - 1/(a*x)])) + (Sqrt[1 + 1/(a*x)]*x)/(c*Sqrt[1 - 1/(a*x)]) + (4*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(a*c)}
{E^ArcCoth[a*x]/(c - c/(a*x))^2, x, 6, -((5*Sqrt[1 + 1/(a*x)])/(3*a*c^2*(1 - 1/(a*x))^(3/2))) - (14*Sqrt[1 + 1/(a*x)])/(3*a*c^2*Sqrt[1 - 1/(a*x)]) + (Sqrt[1 + 1/(a*x)]*x)/(c^2*(1 - 1/(a*x))^(3/2)) + (6*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(a*c^2)}
{E^ArcCoth[a*x]/(c - c/(a*x))^3, x, 7, -((7*Sqrt[1 + 1/(a*x)])/(5*a*c^3*(1 - 1/(a*x))^(5/2))) - (34*Sqrt[1 + 1/(a*x)])/(15*a*c^3*(1 - 1/(a*x))^(3/2)) - (94*Sqrt[1 + 1/(a*x)])/(15*a*c^3*Sqrt[1 - 1/(a*x)]) + (Sqrt[1 + 1/(a*x)]*x)/(c^3*(1 - 1/(a*x))^(5/2)) + (8*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(a*c^3)}
{E^ArcCoth[a*x]/(c - c/(a*x))^4, x, 8, -((9*Sqrt[1 + 1/(a*x)])/(7*a*c^4*(1 - 1/(a*x))^(7/2))) - (62*Sqrt[1 + 1/(a*x)])/(35*a*c^4*(1 - 1/(a*x))^(5/2)) - (299*Sqrt[1 + 1/(a*x)])/(105*a*c^4*(1 - 1/(a*x))^(3/2)) - (824*Sqrt[1 + 1/(a*x)])/(105*a*c^4*Sqrt[1 - 1/(a*x)]) + (Sqrt[1 + 1/(a*x)]*x)/(c^4*(1 - 1/(a*x))^(7/2)) + (10*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(a*c^4)}


{E^(2*ArcCoth[a*x])*(c - c/(a*x))^p, x, 10, ((2 - p)*(c - c/(a*x))^p)/(a*p) + (c - c/(a*x))^p*x - ((2 - p)*(c - c/(a*x))^p*Hypergeometric2F1[-p, -p, 1 - p, a*x])/(((-(a - 1/x))*x)^p*(a*p)), ((1 - p)*(c - c/(a*x))^p)/(a*p) + (c - c/(a*x))^p*x + ((1 - p)*(c - c/(a*x))^(1 + p)*Hypergeometric2F1[1, 1 + p, 2 + p, 1 - 1/(a*x)])/(a*c*(1 + p)) + (c*(c - c/(a*x))^(-1 + p)*(-((a - 1/x)*x))^(1 - p)*Hypergeometric2F1[1 - p, 1 - p, 2 - p, a*x])/(a*(1 - p))}

{E^(2*ArcCoth[a*x])*(c - c/(a*x))^5, x, 5, -c^5/(4*a^5*x^4) + c^5/(a^4*x^3) - c^5/(a^3*x^2) - (2*c^5)/(a^2*x) + c^5*x - (3*c^5*Log[x])/a}
{E^(2*ArcCoth[a*x])*(c - c/(a*x))^4, x, 5, c^4/(3*a^4*x^3) - c^4/(a^3*x^2) + c^4*x - (2*c^4*Log[x])/a}
{E^(2*ArcCoth[a*x])*(c - c/(a*x))^3, x, 5, -c^3/(2*a^3*x^2) + c^3/(a^2*x) + c^3*x - (c^3*Log[x])/a}
{E^(2*ArcCoth[a*x])*(c - c/(a*x))^2, x, 4, (c^2*(1 + a*x)^2)/(a^2*x)}
{E^(2*ArcCoth[a*x])*(c - c/(a*x)), x, 5, c*x + (c*Log[x])/a}
{E^(2*ArcCoth[a*x])/(c - c/(a*x)), x, 5, x/c + 2/(a*c*(1 - a*x)) + (3*Log[1 - a*x])/(a*c)}
{E^(2*ArcCoth[a*x])/(c - c/(a*x))^2, x, 5, x/c^2 - 1/(a*c^2*(1 - a*x)^2) + 5/(a*c^2*(1 - a*x)) + (4*Log[1 - a*x])/(a*c^2)}
{E^(2*ArcCoth[a*x])/(c - c/(a*x))^3, x, 5, x/c^3 + 2/(3*a*c^3*(1 - a*x)^3) - 7/(2*a*c^3*(1 - a*x)^2) + 9/(a*c^3*(1 - a*x)) + (5*Log[1 - a*x])/(a*c^3)}
{E^(2*ArcCoth[a*x])/(c - c/(a*x))^4, x, 5, x/c^4 - 1/(2*a*c^4*(1 - a*x)^4) + 3/(a*c^4*(1 - a*x)^3) - 8/(a*c^4*(1 - a*x)^2) + 14/(a*c^4*(1 - a*x)) + (6*Log[1 - a*x])/(a*c^4)}


{E^(3*ArcCoth[a*x])*(c - c/(a*x))^4, x, 8, -((c^4*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/(2*a)) + (3*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2))/(2*a) + (4*c^4*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(3/2))/(3*a) + c^4*(1 - 1/(a*x))^(5/2)*(1 + 1/(a*x))^(3/2)*x + (3*c^4*ArcSin[1/(a*x)])/(2*a) - (2*c^4*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{E^(3*ArcCoth[a*x])*(c - c/(a*x))^3, x, 6, (3*c^3*Sqrt[1 - 1/(a^2*x^2)])/(2*a^2*x) + c^3*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(3/2)*x + (3*c^3*ArcSin[1/(a*x)])/(2*a)}
{E^(3*ArcCoth[a*x])*(c - c/(a*x))^2, x, 7, -((2*c^2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/a) + c^2*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2)*x + (c^2*ArcSin[1/(a*x)])/a + (2*c^2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{E^(3*ArcCoth[a*x])*(c - c/(a*x)), x, 6, -((c*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/a) + c*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2)*x - (c*ArcSin[1/(a*x)])/a + (4*c*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{E^(3*ArcCoth[a*x])/(c - c/(a*x)), x, 6, -((10*Sqrt[1 + 1/(a*x)])/(3*a*c*(1 - 1/(a*x))^(3/2))) - (19*Sqrt[1 + 1/(a*x)])/(3*a*c*Sqrt[1 - 1/(a*x)]) + ((1 + 1/(a*x))^(3/2)*x)/(c*(1 - 1/(a*x))^(3/2)) + (8*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(a*c)}
{E^(3*ArcCoth[a*x])/(c - c/(a*x))^2, x, 7, -((14*Sqrt[1 + 1/(a*x)])/(5*a*c^2*(1 - 1/(a*x))^(5/2))) - (43*Sqrt[1 + 1/(a*x)])/(15*a*c^2*(1 - 1/(a*x))^(3/2)) - (118*Sqrt[1 + 1/(a*x)])/(15*a*c^2*Sqrt[1 - 1/(a*x)]) + ((1 + 1/(a*x))^(3/2)*x)/(c^2*(1 - 1/(a*x))^(5/2)) + (10*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(a*c^2)}
{E^(3*ArcCoth[a*x])/(c - c/(a*x))^3, x, 8, -((18*Sqrt[1 + 1/(a*x)])/(7*a*c^3*(1 - 1/(a*x))^(7/2))) - (15*Sqrt[1 + 1/(a*x)])/(7*a*c^3*(1 - 1/(a*x))^(5/2)) - (24*Sqrt[1 + 1/(a*x)])/(7*a*c^3*(1 - 1/(a*x))^(3/2)) - (66*Sqrt[1 + 1/(a*x)])/(7*a*c^3*Sqrt[1 - 1/(a*x)]) + ((1 + 1/(a*x))^(3/2)*x)/(c^3*(1 - 1/(a*x))^(7/2)) + (12*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(a*c^3)}
{E^(3*ArcCoth[a*x])/(c - c/(a*x))^4, x, 9, -((22*Sqrt[1 + 1/(a*x)])/(9*a*c^4*(1 - 1/(a*x))^(9/2))) - (115*Sqrt[1 + 1/(a*x)])/(63*a*c^4*(1 - 1/(a*x))^(7/2)) - (262*Sqrt[1 + 1/(a*x)])/(105*a*c^4*(1 - 1/(a*x))^(5/2)) - (1259*Sqrt[1 + 1/(a*x)])/(315*a*c^4*(1 - 1/(a*x))^(3/2)) - (3464*Sqrt[1 + 1/(a*x)])/(315*a*c^4*Sqrt[1 - 1/(a*x)]) + ((1 + 1/(a*x))^(3/2)*x)/(c^4*(1 - 1/(a*x))^(9/2)) + (14*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(a*c^4)}


{E^(4*ArcCoth[a*x])*(c - c/(a*x))^5, x, 5, c^5/(4*a^5*x^4) - c^5/(3*a^4*x^3) - c^5/(a^3*x^2) + (2*c^5)/(a^2*x) + c^5*x - (c^5*Log[x])/a}
{E^(4*ArcCoth[a*x])*(c - c/(a*x))^4, x, 5, -c^4/(3*a^4*x^3) + (2*c^4)/(a^2*x) + c^4*x}
{E^(4*ArcCoth[a*x])*(c - c/(a*x))^3, x, 5, c^3/(2*a^3*x^2) + c^3/(a^2*x) + c^3*x + (c^3*Log[x])/a}
{E^(4*ArcCoth[a*x])*(c - c/(a*x))^2, x, 5, -(c^2/(a^2*x)) + c^2*x + (2*c^2*Log[x])/a}
{E^(4*ArcCoth[a*x])*(c - c/(a*x)), x, 5, c*x - (c*Log[x])/a + (4*c*Log[1 - a*x])/a}
{E^(4*ArcCoth[a*x])/(c - c/(a*x)), x, 5, x/c - 2/(a*c*(1 - a*x)^2) + 8/(a*c*(1 - a*x)) + (5*Log[1 - a*x])/(a*c)}
{E^(4*ArcCoth[a*x])/(c - c/(a*x))^2, x, 5, x/c^2 + 4/(3*a*c^2*(1 - a*x)^3) - 6/(a*c^2*(1 - a*x)^2) + 13/(a*c^2*(1 - a*x)) + (6*Log[1 - a*x])/(a*c^2)}
{E^(4*ArcCoth[a*x])/(c - c/(a*x))^3, x, 5, x/c^3 - 1/(a*c^3*(1 - a*x)^4) + 16/(3*a*c^3*(1 - a*x)^3) - 25/(2*a*c^3*(1 - a*x)^2) + 19/(a*c^3*(1 - a*x)) + (7*Log[1 - a*x])/(a*c^3)}
{E^(4*ArcCoth[a*x])/(c - c/(a*x))^4, x, 5, x/c^4 + 4/(5*a*c^4*(1 - a*x)^5) - 5/(a*c^4*(1 - a*x)^4) + 41/(3*a*c^4*(1 - a*x)^3) - 22/(a*c^4*(1 - a*x)^2) + 26/(a*c^4*(1 - a*x)) + (8*Log[1 - a*x])/(a*c^4)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(c - c/(a*x))^p/E^ArcCoth[a*x], x, 3, (Sqrt[2]*(1 - 1/(a*x))^(3/2)*(c - c/(a*x))^p*AppellF1[3/2 + p, 2, 1/2, 5/2 + p, 1 - 1/(a*x), (a - 1/x)/(2*a)])/(a*(3 + 2*p))}

{(c - c/(a*x))^4/E^ArcCoth[a*x], x, 9, -((15*c^4*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/(2*a)) - (5*c^4*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)])/(6*a) + (2*c^4*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)])/(3*a) + (c^4*(1 - 1/(a*x))^(7/2)*Sqrt[1 + 1/(a*x)])/a + c^4*(1 - 1/(a*x))^(9/2)*Sqrt[1 + 1/(a*x)]*x - (25*c^4*ArcSin[1/(a*x)])/(2*a) - (10*c^4*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{(c - c/(a*x))^3/E^ArcCoth[a*x], x, 8, -((5*c^3*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/(2*a)) + (c^3*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)])/(2*a) + (c^3*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)])/a + c^3*(1 - 1/(a*x))^(7/2)*Sqrt[1 + 1/(a*x)]*x - (13*c^3*ArcSin[1/(a*x)])/(2*a) - (8*c^3*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{(c - c/(a*x))^2/E^ArcCoth[a*x], x, 7, (c^2*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)])/a + c^2*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)]*x - (3*c^2*ArcSin[1/(a*x)])/a - (6*c^2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{(c - c/(a*x))/E^ArcCoth[a*x], x, 6, (c*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/a + c*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)]*x - (c*ArcSin[1/(a*x)])/a - (4*c*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{1/(E^ArcCoth[a*x]*(c - c/(a*x))), x, 3, (Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/c}
{1/(E^ArcCoth[a*x]*(c - c/(a*x))^2), x, 5, -((2*Sqrt[1 + 1/(a*x)])/(a*c^2*Sqrt[1 - 1/(a*x)])) + (Sqrt[1 + 1/(a*x)]*x)/(c^2*Sqrt[1 - 1/(a*x)]) + (2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(a*c^2)}
{1/(E^ArcCoth[a*x]*(c - c/(a*x))^3), x, 7, -((4*Sqrt[1 + 1/(a*x)])/(3*a*c^3*(1 - 1/(a*x))^(3/2))) - (10*Sqrt[1 + 1/(a*x)])/(3*a*c^3*Sqrt[1 - 1/(a*x)]) + (Sqrt[1 + 1/(a*x)]*x)/(c^3*(1 - 1/(a*x))^(3/2)) + (4*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(a*c^3)}
{1/(E^ArcCoth[a*x]*(c - c/(a*x))^4), x, 8, -((6*Sqrt[1 + 1/(a*x)])/(5*a*c^4*(1 - 1/(a*x))^(5/2))) - (9*Sqrt[1 + 1/(a*x)])/(5*a*c^4*(1 - 1/(a*x))^(3/2)) - (24*Sqrt[1 + 1/(a*x)])/(5*a*c^4*Sqrt[1 - 1/(a*x)]) + (Sqrt[1 + 1/(a*x)]*x)/(c^4*(1 - 1/(a*x))^(5/2)) + (6*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(a*c^4)}


{(c - c/(a*x))^p/E^(2*ArcCoth[a*x]), x, 11, ((a - 1/x)^2*(c - c/(a*x))^p*AppellF1[2 + p, 2, 1, 3 + p, 1 - 1/(a*x), (a - 1/x)/(2*a)])/(2*a^3*(2 + p)), -(((c - c/(a*x))^(1 + p)*x)/(c*p)) + ((1 + p)*(c - c/(a*x))^(1 + p)*x)/(c*p) + ((c - c/(a*x))^(1 + p)*x*(1 - a*x)^(-1 - p)*AppellF1[-p, 1, -1 - p, 1 - p, (-a)*x, a*x])/(c*p) - ((c - c/(a*x))^(1 + p)*Hypergeometric2F1[1, 1 + p, 2 + p, 1 - 1/(a*x)])/(a*c)}

{(c - c/(a*x))^4/E^(2*ArcCoth[a*x]), x, 5, c^4/(3*a^4*x^3) - (3*c^4)/(a^3*x^2) + (16*c^4)/(a^2*x) + c^4*x + (26*c^4*Log[x])/a - (32*c^4*Log[1 + a*x])/a}
{(c - c/(a*x))^3/E^(2*ArcCoth[a*x]), x, 5, -c^3/(2*a^3*x^2) + (5*c^3)/(a^2*x) + c^3*x + (11*c^3*Log[x])/a - (16*c^3*Log[1 + a*x])/a}
{(c - c/(a*x))^2/E^(2*ArcCoth[a*x]), x, 5, c^2/(a^2*x) + c^2*x + (4*c^2*Log[x])/a - (8*c^2*Log[1 + a*x])/a}
{(c - c/(a*x))/E^(2*ArcCoth[a*x]), x, 5, c*x + (c*Log[x])/a - (4*c*Log[1 + a*x])/a}
{1/(E^(2*ArcCoth[a*x])*(c - c/(a*x))), x, 5, x/c - Log[1 + a*x]/(a*c)}
{1/(E^(2*ArcCoth[a*x])*(c - c/(a*x))^2), x, 6, x/c^2 - ArcTanh[a*x]/(a*c^2)}
{1/(E^(2*ArcCoth[a*x])*(c - c/(a*x))^3), x, 5, x/c^3 + 1/(2*a*c^3*(1 - a*x)) + (5*Log[1 - a*x])/(4*a*c^3) - Log[1 + a*x]/(4*a*c^3)}
{1/(E^(2*ArcCoth[a*x])*(c - c/(a*x))^4), x, 5, x/c^4 - 1/(4*a*c^4*(1 - a*x)^2) + 7/(4*a*c^4*(1 - a*x)) + (17*Log[1 - a*x])/(8*a*c^4) - Log[1 + a*x]/(8*a*c^4)}


{(c - c/(a*x))^4/E^(3*ArcCoth[a*x]), x, 10, (6*c^4*(1 - 1/(a*x))^(9/2))/(a*Sqrt[1 + 1/(a*x)]) + (105*c^4*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/(2*a) + (119*c^4*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)])/(6*a) + (28*c^4*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)])/(3*a) + (5*c^4*(1 - 1/(a*x))^(7/2)*Sqrt[1 + 1/(a*x)])/a + (c^4*(1 - 1/(a*x))^(11/2)*x)/Sqrt[1 + 1/(a*x)] + (91*c^4*ArcSin[1/(a*x)])/(2*a) - (14*c^4*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{(c - c/(a*x))^3/E^(3*ArcCoth[a*x]), x, 9, (6*c^3*(1 - 1/(a*x))^(7/2))/(a*Sqrt[1 + 1/(a*x)]) + (45*c^3*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/(2*a) + (19*c^3*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)])/(2*a) + (5*c^3*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)])/a + (c^3*(1 - 1/(a*x))^(9/2)*x)/Sqrt[1 + 1/(a*x)] + (33*c^3*ArcSin[1/(a*x)])/(2*a) - (12*c^3*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{(c - c/(a*x))^2/E^(3*ArcCoth[a*x]), x, 9, (6*c^2*(1 - 1/(a*x))^(5/2))/(a*Sqrt[1 + 1/(a*x)]) + (10*c^2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/a + (5*c^2*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)])/a + (c^2*(1 - 1/(a*x))^(7/2)*x)/Sqrt[1 + 1/(a*x)] + (5*c^2*ArcSin[1/(a*x)])/a - (10*c^2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{(c - c/(a*x))/E^(3*ArcCoth[a*x]), x, 7, (6*c*(1 - 1/(a*x))^(3/2))/(a*Sqrt[1 + 1/(a*x)]) + (5*c*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/a + (c*(1 - 1/(a*x))^(5/2)*x)/Sqrt[1 + 1/(a*x)] + (c*ArcSin[1/(a*x)])/a - (8*c*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{1/(E^(3*ArcCoth[a*x])*(c - c/(a*x))), x, 5, (3*Sqrt[1 - 1/(a*x)])/(a*c*Sqrt[1 + 1/(a*x)]) + (Sqrt[1 - 1/(a*x)]*x)/(c*Sqrt[1 + 1/(a*x)]) - (4*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(a*c)}
{1/(E^(3*ArcCoth[a*x])*(c - c/(a*x))^2), x, 5, (2*Sqrt[1 - 1/(a*x)])/(a*c^2*Sqrt[1 + 1/(a*x)]) + (Sqrt[1 - 1/(a*x)]*x)/(c^2*Sqrt[1 + 1/(a*x)]) - (2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(a*c^2)}
{1/(E^(3*ArcCoth[a*x])*(c - c/(a*x))^3), x, 5, -(2/(a^2*c^3*Sqrt[1 - 1/(a^2*x^2)]*x)) + x/(c^3*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])}
{1/(E^(3*ArcCoth[a*x])*(c - c/(a*x))^4), x, 7, -(4/(3*a*c^4*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)])) - 11/(3*a*c^4*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]) + (8*Sqrt[1 - 1/(a*x)])/(3*a*c^4*Sqrt[1 + 1/(a*x)]) + x/(c^4*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)]) + (2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(a*c^4)}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{(c - c/(a*x))^p/E^(2*p*ArcCoth[a*x]), x, 3, ((1 - 1/(a*x))^(1 + p)*(c - c/(a*x))^p*AppellF1[1 + 2*p, 2, p, 2*(1 + p), 1 - 1/(a*x), (a - 1/x)/(2*a)])/(2^p*(a*(1 + 2*p)))}
{E^(2*p*ArcCoth[a*x])*(c - c/(a*x))^p, x, 4, ((1 + 1/(a*x))^(1 + p)*(c - c/(a*x))^p*x)/(1 - 1/(a*x))^p + (p*(1 + 1/(a*x))^(1 + p)*(c - c/(a*x))^p*Hypergeometric2F1[1, 1 + p, 2 + p, 1 + 1/(a*x)])/((1 - 1/(a*x))^p*(a*(1 + p)))}


{E^(n*ArcCoth[a*x])*(c - c/(a*x))^p, x, 3, (2^(1 + n/2)*(1 - 1/(a*x))^(1 - n/2)*(c - c/(a*x))^p*AppellF1[1 - n/2 + p, 2, -(n/2), 2 - n/2 + p, 1 - 1/(a*x), (a - 1/x)/(2*a)])/(a*(2 - n + 2*p))}

{E^(n*ArcCoth[a*x])*(c - c/(a*x)), x, 2, (2^(1 + n/2)*c*(1 - 1/(a*x))^(2 - n/2)*AppellF1[2 - n/2, 2, -(n/2), 3 - n/2, 1 - 1/(a*x), (a - 1/x)/(2*a)])/(a*(4 - n))}
{E^(n*ArcCoth[a*x]), x, 2, (2^(1 + n/2)*(1 - (a - x^(-1))/(2*a))^((-2 + n)/2)*(1 - 1/(a*x))^(1 - n/2)*Hypergeometric2F1[2, 1 - n/2, 2 - n/2, (2 - (a - x^(-1))/a - 2/(a*x))/(2 - (a - x^(-1))/a)])/(a*(2 - n))}
{E^(n*ArcCoth[a*x])/(c - c/(a*x)), x, 2, -((2^(1 + n/2)*Defer[AppellF1][-(n/2), 2, -(n/2), 1 - n/2, 1 - 1/(a*x), (1/2)*(1 - 1/(a*x))])/((1 - 1/(a*x))^(n/2)*(a*c*n)))}
{E^(n*ArcCoth[a*x])/(c - c/(a*x))^2, x, 2, -((2^(1 + n/2)*(1 - 1/(a*x))^(-1 - n/2)*Defer[AppellF1][-1 - n/2, 2, -(n/2), -(n/2), 1 - 1/(a*x), (1/2)*(1 - 1/(a*x))])/(a*c^2*(2 + n)))}


(* ::Subsection::Closed:: *)
(*Integrands of the form E^(n ArcCoth[a x]) (c-c/(a x))^(p/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{E^ArcCoth[a*x]*(c - c/(a*x))^(9/2), x, 8, (43*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(9/2))/(7*a*(1 - 1/(a*x))^(9/2)) + (59*(a - x^(-1))^2*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(9/2))/(35*a^3*(1 - 1/(a*x))^(9/2)) + (9*(a - x^(-1))^3*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(9/2))/(7*a^4*(1 - 1/(a*x))^(9/2)) - ((245*a + 227/x)*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(9/2))/(105*a^2*(1 - 1/(a*x))^(9/2)) + ((a - x^(-1))^4*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(9/2)*x)/(a^4*(1 - 1/(a*x))^(9/2)) - (7*(c - c/(a*x))^(9/2)*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*(1 - 1/(a*x))^(9/2))}
{E^ArcCoth[a*x]*(c - c/(a*x))^(7/2), x, 7, (7*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(7/2))/(a*(1 - 1/(a*x))^(7/2)) + (7*(a - x^(-1))^2*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(7/2))/(5*a^3*(1 - 1/(a*x))^(7/2)) - ((25*a + 31/x)*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(7/2))/(15*a^2*(1 - 1/(a*x))^(7/2)) + ((a - x^(-1))^3*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(7/2)*x)/(a^3*(1 - 1/(a*x))^(7/2)) - (5*(c - c/(a*x))^(7/2)*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*(1 - 1/(a*x))^(7/2))}
{E^ArcCoth[a*x]*(c - c/(a*x))^(5/2), x, 6, (3*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(5/2))/(a*(1 - 1/(a*x))^(5/2)) - (2*(1 + 1/(a*x))^(3/2)*(c - c/(a*x))^(5/2))/(3*a*(1 - 1/(a*x))^(5/2)) + ((1 + 1/(a*x))^(3/2)*(c - c/(a*x))^(5/2)*x)/(1 - 1/(a*x))^(5/2) - (3*(c - c/(a*x))^(5/2)*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*(1 - 1/(a*x))^(5/2))}
{E^ArcCoth[a*x]*(c - c/(a*x))^(3/2), x, 5, (Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(3/2))/(a*(1 - 1/(a*x))^(3/2)) + ((1 + 1/(a*x))^(3/2)*(c - c/(a*x))^(3/2)*x)/(1 - 1/(a*x))^(3/2) - ((c - c/(a*x))^(3/2)*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*(1 - 1/(a*x))^(3/2))}
{E^ArcCoth[a*x]*Sqrt[c - c/(a*x)], x, 4, (Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)]*x)/Sqrt[1 - 1/(a*x)] + (Sqrt[c - c/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*Sqrt[1 - 1/(a*x)])}
{E^ArcCoth[a*x]/Sqrt[c - c/(a*x)], x, 6, (Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/Sqrt[c - c/(a*x)] + (3*Sqrt[1 - 1/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*Sqrt[c - c/(a*x)]) - (2*Sqrt[2]*Sqrt[1 - 1/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]/Sqrt[2]])/(a*Sqrt[c - c/(a*x)])}
{E^ArcCoth[a*x]/(c - c/(a*x))^(3/2), x, 7, (-2*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)])/((a - x^(-1))*(c - c/(a*x))^(3/2)) + (a*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)]*x)/((a - x^(-1))*(c - c/(a*x))^(3/2)) + (5*(1 - 1/(a*x))^(3/2)*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*(c - c/(a*x))^(3/2)) - (7*(1 - 1/(a*x))^(3/2)*ArcTanh[Sqrt[1 + 1/(a*x)]/Sqrt[2]])/(Sqrt[2]*a*(c - c/(a*x))^(3/2))}
{E^ArcCoth[a*x]/(c - c/(a*x))^(5/2), x, 8, (-3*a*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)])/(2*(a - x^(-1))^2*(c - c/(a*x))^(5/2)) - (23*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)])/(8*(a - x^(-1))*(c - c/(a*x))^(5/2)) + (a^2*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)]*x)/((a - x^(-1))^2*(c - c/(a*x))^(5/2)) + (7*(1 - 1/(a*x))^(5/2)*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*(c - c/(a*x))^(5/2)) - (79*(1 - 1/(a*x))^(5/2)*ArcTanh[Sqrt[1 + 1/(a*x)]/Sqrt[2]])/(8*Sqrt[2]*a*(c - c/(a*x))^(5/2))}


{E^(2*ArcCoth[a*x])*(c - c/(a*x))^(9/2), x, 8, (5*c^4*Sqrt[c - c/(a*x)])/a + (5*c^3*(c - c/(a*x))^(3/2))/(3*a) + (c^2*(c - c/(a*x))^(5/2))/a + (5*c*(c - c/(a*x))^(7/2))/(7*a) + (c - c/(a*x))^(9/2)*x - (5*c^(9/2)*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/a}
{E^(2*ArcCoth[a*x])*(c - c/(a*x))^(7/2), x, 8, (3*c^3*Sqrt[c - c/(a*x)])/a + (c^2*(c - c/(a*x))^(3/2))/a + (3*c*(c - c/(a*x))^(5/2))/(5*a) + (c - c/(a*x))^(7/2)*x - (3*c^(7/2)*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/a}
{E^(2*ArcCoth[a*x])*(c - c/(a*x))^(5/2), x, 8, (c^2*Sqrt[c - c/(a*x)])/a + (c*(c - c/(a*x))^(3/2))/(3*a) + (c - c/(a*x))^(5/2)*x - (c^(5/2)*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/a}
{E^(2*ArcCoth[a*x])*(c - c/(a*x))^(3/2), x, 7, -((c*Sqrt[c - c/(a*x)])/a) + (c - c/(a*x))^(3/2)*x + (c^(3/2)*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/a}
{E^(2*ArcCoth[a*x])*Sqrt[c - c/(a*x)], x, 6, Sqrt[c - c/(a*x)]*x + (3*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/a}
{E^(2*ArcCoth[a*x])/Sqrt[c - c/(a*x)], x, 7, -5/(a*Sqrt[c - c/(a*x)]) + x/Sqrt[c - c/(a*x)] + (5*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/(a*Sqrt[c])}
{E^(2*ArcCoth[a*x])/(c - c/(a*x))^(3/2), x, 8, -7/(3*a*(c - c/(a*x))^(3/2)) - 7/(a*c*Sqrt[c - c/(a*x)]) + x/(c - c/(a*x))^(3/2) + (7*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/(a*c^(3/2))}
{E^(2*ArcCoth[a*x])/(c - c/(a*x))^(5/2), x, 9, -9/(5*a*(c - c/(a*x))^(5/2)) - 3/(a*c*(c - c/(a*x))^(3/2)) - 9/(a*c^2*Sqrt[c - c/(a*x)]) + x/(c - c/(a*x))^(5/2) + (9*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/(a*c^(5/2))}
{E^(2*ArcCoth[a*x])/(c - c/(a*x))^(7/2), x, 10, -11/(7*a*(c - c/(a*x))^(7/2)) - 11/(5*a*c*(c - c/(a*x))^(5/2)) - 11/(3*a*c^2*(c - c/(a*x))^(3/2)) - 11/(a*c^3*Sqrt[c - c/(a*x)]) + x/(c - c/(a*x))^(7/2) + (11*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/(a*c^(7/2))}


{E^(3*ArcCoth[a*x])*(c - c/(a*x))^(9/2), x, 8, (3*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(9/2))/(a*(1 - 1/(a*x))^(9/2)) + (3*(1 + 1/(a*x))^(3/2)*(c - c/(a*x))^(9/2))/(a*(1 - 1/(a*x))^(9/2)) + (9*(a - x^(-1))^2*(1 + 1/(a*x))^(3/2)*(c - c/(a*x))^(9/2))/(7*a^3*(1 - 1/(a*x))^(9/2)) - (3*(7*a + 17/x)*(1 + 1/(a*x))^(3/2)*(c - c/(a*x))^(9/2))/(35*a^2*(1 - 1/(a*x))^(9/2)) + ((a - x^(-1))^3*(1 + 1/(a*x))^(3/2)*(c - c/(a*x))^(9/2)*x)/(a^3*(1 - 1/(a*x))^(9/2)) - (3*(c - c/(a*x))^(9/2)*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*(1 - 1/(a*x))^(9/2))}
{E^(3*ArcCoth[a*x])*(c - c/(a*x))^(7/2), x, 7, (Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(7/2))/(a*(1 - 1/(a*x))^(7/2)) + ((1 + 1/(a*x))^(3/2)*(c - c/(a*x))^(7/2))/(3*a*(1 - 1/(a*x))^(7/2)) - (2*(1 + 1/(a*x))^(5/2)*(c - c/(a*x))^(7/2))/(5*a*(1 - 1/(a*x))^(7/2)) + ((1 + 1/(a*x))^(5/2)*(c - c/(a*x))^(7/2)*x)/(1 - 1/(a*x))^(7/2) - ((c - c/(a*x))^(7/2)*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*(1 - 1/(a*x))^(7/2))}
{E^(3*ArcCoth[a*x])*(c - c/(a*x))^(5/2), x, 6, -((Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(5/2))/(a*(1 - 1/(a*x))^(5/2))) - ((1 + 1/(a*x))^(3/2)*(c - c/(a*x))^(5/2))/(3*a*(1 - 1/(a*x))^(5/2)) + ((1 + 1/(a*x))^(5/2)*(c - c/(a*x))^(5/2)*x)/(1 - 1/(a*x))^(5/2) + ((c - c/(a*x))^(5/2)*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*(1 - 1/(a*x))^(5/2))}
{E^(3*ArcCoth[a*x])*(c - c/(a*x))^(3/2), x, 5, (-3*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(3/2))/(a*(1 - 1/(a*x))^(3/2)) + ((1 + 1/(a*x))^(3/2)*(c - c/(a*x))^(3/2)*x)/(1 - 1/(a*x))^(3/2) + (3*(c - c/(a*x))^(3/2)*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*(1 - 1/(a*x))^(3/2))}
{E^(3*ArcCoth[a*x])*Sqrt[c - c/(a*x)], x, 7, -((Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)])/(a*Sqrt[1 - 1/(a*x)])) + ((1 + 1/(a*x))^(3/2)*Sqrt[c - c/(a*x)]*x)/Sqrt[1 - 1/(a*x)] + (5*Sqrt[c - c/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*Sqrt[1 - 1/(a*x)]) - (4*Sqrt[2]*Sqrt[c - c/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]/Sqrt[2]])/(a*Sqrt[1 - 1/(a*x)])}
{E^(3*ArcCoth[a*x])/Sqrt[c - c/(a*x)], x, 7, (-4*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/((a - x^(-1))*Sqrt[c - c/(a*x)]) + (a*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2)*x)/((a - x^(-1))*Sqrt[c - c/(a*x)]) + (7*Sqrt[1 - 1/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*Sqrt[c - c/(a*x)]) - (5*Sqrt[2]*Sqrt[1 - 1/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]/Sqrt[2]])/(a*Sqrt[c - c/(a*x)])}
{E^(3*ArcCoth[a*x])/(c - c/(a*x))^(3/2), x, 8, (-3*a*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)])/((a - x^(-1))^2*(c - c/(a*x))^(3/2)) - (15*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)])/(4*(a - x^(-1))*(c - c/(a*x))^(3/2)) + (a^2*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(3/2)*x)/((a - x^(-1))^2*(c - c/(a*x))^(3/2)) + (9*(1 - 1/(a*x))^(3/2)*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*(c - c/(a*x))^(3/2)) - (51*(1 - 1/(a*x))^(3/2)*ArcTanh[Sqrt[1 + 1/(a*x)]/Sqrt[2]])/(4*Sqrt[2]*a*(c - c/(a*x))^(3/2))}
{E^(3*ArcCoth[a*x])/(c - c/(a*x))^(5/2), x, 9, (-8*a^2*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)])/(3*(a - x^(-1))^3*(c - c/(a*x))^(5/2)) - (29*a*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)])/(12*(a - x^(-1))^2*(c - c/(a*x))^(5/2)) - (73*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)])/(16*(a - x^(-1))*(c - c/(a*x))^(5/2)) + (a^3*(1 - 1/(a*x))^(5/2)*(1 + 1/(a*x))^(3/2)*x)/((a - x^(-1))^3*(c - c/(a*x))^(5/2)) + (11*(1 - 1/(a*x))^(5/2)*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*(c - c/(a*x))^(5/2)) - (249*(1 - 1/(a*x))^(5/2)*ArcTanh[Sqrt[1 + 1/(a*x)]/Sqrt[2]])/(16*Sqrt[2]*a*(c - c/(a*x))^(5/2))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(c - c/(a*x))^(9/2)/E^ArcCoth[a*x], x, 8, (-225*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(9/2))/(7*a*(1 - 1/(a*x))^(9/2)) - ((385*a - 521/x)*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(9/2))/(105*a^2*(1 - 1/(a*x))^(9/2)) - (17*(a - x^(-1))^2*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(9/2))/(35*a^3*(1 - 1/(a*x))^(9/2)) + (5*(a - x^(-1))^3*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(9/2)*x)/(7*a^3*(1 - 1/(a*x))^(9/2)) + (2*(a - x^(-1))^4*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(9/2)*x)/(7*a^4*(1 - 1/(a*x))^(9/2)) - (11*(c - c/(a*x))^(9/2)*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*(1 - 1/(a*x))^(9/2))}
{(c - c/(a*x))^(7/2)/E^ArcCoth[a*x], x, 7, (-13*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(7/2))/(a*(1 - 1/(a*x))^(7/2)) - ((15*a - 7/x)*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(7/2))/(5*a^2*(1 - 1/(a*x))^(7/2)) + (3*(a - x^(-1))^2*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(7/2)*x)/(5*a^2*(1 - 1/(a*x))^(7/2)) + (2*(a - x^(-1))^3*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(7/2)*x)/(5*a^3*(1 - 1/(a*x))^(7/2)) - (9*(c - c/(a*x))^(7/2)*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*(1 - 1/(a*x))^(7/2))}
{(c - c/(a*x))^(5/2)/E^ArcCoth[a*x], x, 6, (-17*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(5/2))/(3*a*(1 - 1/(a*x))^(5/2)) + ((a - x^(-1))*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(5/2)*x)/(3*a*(1 - 1/(a*x))^(5/2)) + (2*(a - x^(-1))^2*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(5/2)*x)/(3*a^2*(1 - 1/(a*x))^(5/2)) - (7*(c - c/(a*x))^(5/2)*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*(1 - 1/(a*x))^(5/2))}
{(c - c/(a*x))^(3/2)/E^ArcCoth[a*x], x, 5, (-2*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(3/2))/(a*(1 - 1/(a*x))^(3/2)) + (Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(3/2)*x)/(1 - 1/(a*x))^(3/2) - (5*(c - c/(a*x))^(3/2)*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*(1 - 1/(a*x))^(3/2))}
{Sqrt[c - c/(a*x)]/E^ArcCoth[a*x], x, 4, (Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)]*x)/Sqrt[1 - 1/(a*x)] - (3*Sqrt[c - c/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*Sqrt[1 - 1/(a*x)])}
{1/(E^ArcCoth[a*x]*Sqrt[c - c/(a*x)]), x, 4, (Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/Sqrt[c - c/(a*x)] - (Sqrt[1 - 1/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*Sqrt[c - c/(a*x)])}
{1/(E^ArcCoth[a*x]*(c - c/(a*x))^(3/2)), x, 7, ((1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)]*x)/(c - c/(a*x))^(3/2) + ((1 - 1/(a*x))^(3/2)*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*(c - c/(a*x))^(3/2)) - (Sqrt[2]*(1 - 1/(a*x))^(3/2)*ArcTanh[Sqrt[1 + 1/(a*x)]/Sqrt[2]])/(a*(c - c/(a*x))^(3/2))}
{1/(E^ArcCoth[a*x]*(c - c/(a*x))^(5/2)), x, 8, (-3*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)])/(2*(a - x^(-1))*(c - c/(a*x))^(5/2)) + (a*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)]*x)/((a - x^(-1))*(c - c/(a*x))^(5/2)) + (3*(1 - 1/(a*x))^(5/2)*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*(c - c/(a*x))^(5/2)) - (9*(1 - 1/(a*x))^(5/2)*ArcTanh[Sqrt[1 + 1/(a*x)]/Sqrt[2]])/(2*Sqrt[2]*a*(c - c/(a*x))^(5/2))}
{1/(E^ArcCoth[a*x]*(c - c/(a*x))^(7/2)), x, 9, (-5*a*(1 - 1/(a*x))^(7/2)*Sqrt[1 + 1/(a*x)])/(4*(a - x^(-1))^2*(c - c/(a*x))^(7/2)) - (35*(1 - 1/(a*x))^(7/2)*Sqrt[1 + 1/(a*x)])/(16*(a - x^(-1))*(c - c/(a*x))^(7/2)) + (a^2*(1 - 1/(a*x))^(7/2)*Sqrt[1 + 1/(a*x)]*x)/((a - x^(-1))^2*(c - c/(a*x))^(7/2)) + (5*(1 - 1/(a*x))^(7/2)*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*(c - c/(a*x))^(7/2)) - (115*(1 - 1/(a*x))^(7/2)*ArcTanh[Sqrt[1 + 1/(a*x)]/Sqrt[2]])/(16*Sqrt[2]*a*(c - c/(a*x))^(7/2))}


{(c - c/(a*x))^(9/2)/E^(2*ArcCoth[a*x]), x, 10, (-52*c^4*Sqrt[c - c/(a*x)])/a - (22*c^3*(c - c/(a*x))^(3/2))/(3*a) - (8*c^2*(c - c/(a*x))^(5/2))/(5*a) - (2*c*(c - c/(a*x))^(7/2))/(7*a) + c^4*Sqrt[c - c/(a*x)]*x - (13*c^(9/2)*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/a + (64*Sqrt[2]*c^(9/2)*ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])])/a}
{(c - c/(a*x))^(7/2)/E^(2*ArcCoth[a*x]), x, 10, (-22*c^3*Sqrt[c - c/(a*x)])/a - (8*c^2*(c - c/(a*x))^(3/2))/(3*a) - (2*c*(c - c/(a*x))^(5/2))/(5*a) + c^3*Sqrt[c - c/(a*x)]*x - (11*c^(7/2)*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/a + (32*Sqrt[2]*c^(7/2)*ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])])/a}
{(c - c/(a*x))^(5/2)/E^(2*ArcCoth[a*x]), x, 10, (-8*c^2*Sqrt[c - c/(a*x)])/a - (2*c*(c - c/(a*x))^(3/2))/(3*a) + c^2*Sqrt[c - c/(a*x)]*x - (9*c^(5/2)*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/a + (16*Sqrt[2]*c^(5/2)*ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])])/a}
{(c - c/(a*x))^(3/2)/E^(2*ArcCoth[a*x]), x, 10, (-2*c*Sqrt[c - c/(a*x)])/a + c*Sqrt[c - c/(a*x)]*x - (7*c^(3/2)*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/a + (8*Sqrt[2]*c^(3/2)*ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])])/a}
{Sqrt[c - c/(a*x)]/E^(2*ArcCoth[a*x]), x, 10, Sqrt[c - c/(a*x)]*x - (5*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/a + (4*Sqrt[2]*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])])/a}
{1/(E^(2*ArcCoth[a*x])*Sqrt[c - c/(a*x)]), x, 10, (Sqrt[c - c/(a*x)]*x)/c - (3*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/(a*Sqrt[c]) + (2*Sqrt[2]*ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])])/(a*Sqrt[c])}
{1/(E^(2*ArcCoth[a*x])*(c - c/(a*x))^(3/2)), x, 8, (Sqrt[c - c/(a*x)]*x)/c^2 - ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]]/(a*c^(3/2)) + (Sqrt[2]*ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])])/(a*c^(3/2))}
{1/(E^(2*ArcCoth[a*x])*(c - c/(a*x))^(5/2)), x, 10, -(1/(a*c^2*Sqrt[c - c/(a*x)])) + (Sqrt[c - c/(a*x)]*x)/c^3 + ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]]/(a*c^(5/2)) + ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])]/(Sqrt[2]*a*c^(5/2))}
{1/(E^(2*ArcCoth[a*x])*(c - c/(a*x))^(7/2)), x, 10, -1/(3*a*c^2*(c - c/(a*x))^(3/2)) - 5/(2*a*c^3*Sqrt[c - c/(a*x)]) + (Sqrt[c - c/(a*x)]*x)/c^4 + (3*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/(a*c^(7/2)) + ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])]/(2*Sqrt[2]*a*c^(7/2))}
{1/(E^(2*ArcCoth[a*x])*(c - c/(a*x))^(9/2)), x, 10, -1/(5*a*c^2*(c - c/(a*x))^(5/2)) - 5/(6*a*c^3*(c - c/(a*x))^(3/2)) - 17/(4*a*c^4*Sqrt[c - c/(a*x)]) + (Sqrt[c - c/(a*x)]*x)/c^5 + (5*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/(a*c^(9/2)) + ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])]/(4*Sqrt[2]*a*c^(9/2))}


{(c - c/(a*x))^(9/2)/E^(3*ArcCoth[a*x]), x, 9, (130*(a - x^(-1))^3*(c - c/(a*x))^(9/2))/(7*a^4*(1 - 1/(a*x))^(9/2)*Sqrt[1 + 1/(a*x)]) + (1555*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(9/2))/(7*a*(1 - 1/(a*x))^(9/2)) + (135*(a - x^(-1))^2*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(9/2))/(7*a^3*(1 - 1/(a*x))^(9/2)) - (5*(7*a + 65/x)*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(9/2))/(7*a^2*(1 - 1/(a*x))^(9/2)) + (5*(a - x^(-1))^4*(c - c/(a*x))^(9/2)*x)/(7*a^4*(1 - 1/(a*x))^(9/2)*Sqrt[1 + 1/(a*x)]) + (2*(a - x^(-1))^5*(c - c/(a*x))^(9/2)*x)/(7*a^5*(1 - 1/(a*x))^(9/2)*Sqrt[1 + 1/(a*x)]) - (15*(c - c/(a*x))^(9/2)*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*(1 - 1/(a*x))^(9/2))}
{(c - c/(a*x))^(7/2)/E^(3*ArcCoth[a*x]), x, 8, (94*(a - x^(-1))^2*(c - c/(a*x))^(7/2))/(5*a^3*(1 - 1/(a*x))^(7/2)*Sqrt[1 + 1/(a*x)]) + (95*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(7/2))/(a*(1 - 1/(a*x))^(7/2)) - ((65*a + 311/x)*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(7/2))/(15*a^2*(1 - 1/(a*x))^(7/2)) + (3*(a - x^(-1))^3*(c - c/(a*x))^(7/2)*x)/(5*a^3*(1 - 1/(a*x))^(7/2)*Sqrt[1 + 1/(a*x)]) + (2*(a - x^(-1))^4*(c - c/(a*x))^(7/2)*x)/(5*a^4*(1 - 1/(a*x))^(7/2)*Sqrt[1 + 1/(a*x)]) - (13*(c - c/(a*x))^(7/2)*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*(1 - 1/(a*x))^(7/2))}
{(c - c/(a*x))^(5/2)/E^(3*ArcCoth[a*x]), x, 7, (58*(a - x^(-1))*(c - c/(a*x))^(5/2))/(3*a^2*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)]) + (83*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(5/2))/(3*a*(1 - 1/(a*x))^(5/2)) + ((a - x^(-1))^2*(c - c/(a*x))^(5/2)*x)/(3*a^2*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)]) + (2*(a - x^(-1))^3*(c - c/(a*x))^(5/2)*x)/(3*a^3*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)]) - (11*(c - c/(a*x))^(5/2)*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*(1 - 1/(a*x))^(5/2))}
{(c - c/(a*x))^(3/2)/E^(3*ArcCoth[a*x]), x, 6, (22*(c - c/(a*x))^(3/2))/(a*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)]) - ((a - x^(-1))*(c - c/(a*x))^(3/2)*x)/(a*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)]) + (2*(a - x^(-1))^2*(c - c/(a*x))^(3/2)*x)/(a^2*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)]) - (9*(c - c/(a*x))^(3/2)*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*(1 - 1/(a*x))^(3/2))}
{Sqrt[c - c/(a*x)]/E^(3*ArcCoth[a*x]), x, 5, (9*Sqrt[c - c/(a*x)])/(a*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]) + (Sqrt[c - c/(a*x)]*x)/(Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]) - (7*Sqrt[c - c/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*Sqrt[1 - 1/(a*x)])}
{1/(E^(3*ArcCoth[a*x])*Sqrt[c - c/(a*x)]), x, 5, (5*Sqrt[1 - 1/(a*x)])/(a*Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)]) + (Sqrt[1 - 1/(a*x)]*x)/(Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)]) - (5*Sqrt[1 - 1/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*Sqrt[c - c/(a*x)])}
{1/(E^(3*ArcCoth[a*x])*(c - c/(a*x))^(3/2)), x, 5, (-2*(1 - 1/(a*x))^(3/2)*x)/(Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(3/2)) + (3*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)]*x)/(c - c/(a*x))^(3/2) - (3*(1 - 1/(a*x))^(3/2)*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*(c - c/(a*x))^(3/2))}
{1/(E^(3*ArcCoth[a*x])*(c - c/(a*x))^(5/2)), x, 7, (2*(1 - 1/(a*x))^(5/2))/(a*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(5/2)) + ((1 - 1/(a*x))^(5/2)*x)/(Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(5/2)) - ((1 - 1/(a*x))^(5/2)*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*(c - c/(a*x))^(5/2)) - ((1 - 1/(a*x))^(5/2)*ArcTanh[Sqrt[1 + 1/(a*x)]/Sqrt[2]])/(Sqrt[2]*a*(c - c/(a*x))^(5/2))}
{1/(E^(3*ArcCoth[a*x])*(c - c/(a*x))^(7/2)), x, 8, (7*(1 - 1/(a*x))^(7/2))/(4*a*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(7/2)) - (3*(1 - 1/(a*x))^(7/2))/(2*(a - x^(-1))*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(7/2)) + (a*(1 - 1/(a*x))^(7/2)*x)/((a - x^(-1))*Sqrt[1 + 1/(a*x)]*(c - c/(a*x))^(7/2)) + ((1 - 1/(a*x))^(7/2)*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*(c - c/(a*x))^(7/2)) - (11*(1 - 1/(a*x))^(7/2)*ArcTanh[Sqrt[1 + 1/(a*x)]/Sqrt[2]])/(4*Sqrt[2]*a*(c - c/(a*x))^(7/2))}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{E^(n*ArcCoth[a*x])*(c - c/(a*x))^(3/2), x, 3, (2^(1 + n/2)*(1 - 1/(a*x))^((2 - n)/2)*(c - c/(a*x))^(3/2)*AppellF1[(5 - n)/2, 2, -n/2, (7 - n)/2, 1 - 1/(a*x), (a - x^(-1))/(2*a)])/(a*(5 - n))}
{E^(n*ArcCoth[a*x])*Sqrt[c - c/(a*x)], x, 3, (2^(1 + n/2)*(1 - 1/(a*x))^((2 - n)/2)*Sqrt[c - c/(a*x)]*AppellF1[(3 - n)/2, 2, -n/2, (5 - n)/2, 1 - 1/(a*x), (a - x^(-1))/(2*a)])/(a*(3 - n))}
{E^(n*ArcCoth[a*x])/Sqrt[c - c/(a*x)], x, 3, (2^(1 + n/2)*(1 - 1/(a*x))^((2 - n)/2)*AppellF1[(1 - n)/2, 2, -n/2, (3 - n)/2, 1 - 1/(a*x), (a - x^(-1))/(2*a)])/(a*(1 - n)*Sqrt[c - c/(a*x)])}
{E^(n*ArcCoth[a*x])/(c - c/(a*x))^(3/2), x, 3, -((2^(1 + n/2)*(1 - 1/(a*x))^((2 - n)/2)*AppellF1[(-1 - n)/2, 2, -n/2, (1 - n)/2, 1 - 1/(a*x), (a - x^(-1))/(2*a)])/(a*(1 + n)*(c - c/(a*x))^(3/2)))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(n ArcCoth[a x]) (c-c/(a x))^(p/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{E^ArcCoth[a*x]*Sqrt[c - c/(a*x)]*x^m, x, 6, (2*Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)]*x^(1 + m))/((1 + 2*m)*Sqrt[1 - 1/(a*x)]) - (Sqrt[c - c/(a*x)]*x^(1 + m)*Hypergeometric2F1[1/2, -1 - m, -m, -(1/(a*x))])/((1 + 3*m + 2*m^2)*Sqrt[1 - 1/(a*x)]), (Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)]*x^m)/(2*a*m*(1 + m)*Sqrt[1 - 1/(a*x)]) + (2*Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)]*x^(1 + m))/((1 + 2*m)*Sqrt[1 - 1/(a*x)]) - (Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)]*x^(1 + m))/((1 + 3*m + 2*m^2)*Sqrt[1 - 1/(a*x)]) - ((1 - 2*m)*Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)]*(-(1/(a*x)))^m*x^m*Hypergeometric2F1[1/2, m, 3/2, 1 + 1/(a*x)])/(2*a*m*(1 + m)*Sqrt[1 - 1/(a*x)])}

{E^ArcCoth[a*x]*Sqrt[c - c/(a*x)]*x^2, x, 6, -(Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)]*x)/(8*a^2*Sqrt[1 - 1/(a*x)]) + (Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)]*x^2)/(12*a*Sqrt[1 - 1/(a*x)]) + (Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)]*x^3)/(3*Sqrt[1 - 1/(a*x)]) + (Sqrt[c - c/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]])/(8*a^3*Sqrt[1 - 1/(a*x)])}
{E^ArcCoth[a*x]*Sqrt[c - c/(a*x)]*x, x, 5, (Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)]*x)/(4*a*Sqrt[1 - 1/(a*x)]) + (Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)]*x^2)/(2*Sqrt[1 - 1/(a*x)]) - (Sqrt[c - c/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]])/(4*a^2*Sqrt[1 - 1/(a*x)])}
{E^ArcCoth[a*x]*Sqrt[c - c/(a*x)], x, 4, (Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)]*x)/Sqrt[1 - 1/(a*x)] + (Sqrt[c - c/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*Sqrt[1 - 1/(a*x)])}
{(E^ArcCoth[a*x]*Sqrt[c - c/(a*x)])/x, x, 4, (-2*Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)])/Sqrt[1 - 1/(a*x)] + (2*Sqrt[c - c/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]])/Sqrt[1 - 1/(a*x)]}
{(E^ArcCoth[a*x]*Sqrt[c - c/(a*x)])/x^2, x, 3, (-2*a*(1 + 1/(a*x))^(3/2)*Sqrt[c - c/(a*x)])/(3*Sqrt[1 - 1/(a*x)])}


{E^(2*ArcCoth[a*x])*Sqrt[c - c/(a*x)]*x^3, x, 9, (75*Sqrt[c - c/(a*x)]*x)/(64*a^3) + (25*Sqrt[c - c/(a*x)]*x^2)/(32*a^2) + (5*Sqrt[c - c/(a*x)]*x^3)/(8*a) + (Sqrt[c - c/(a*x)]*x^4)/4 + (75*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/(64*a^4)}
{E^(2*ArcCoth[a*x])*Sqrt[c - c/(a*x)]*x^2, x, 8, (11*Sqrt[c - c/(a*x)]*x)/(8*a^2) + (11*Sqrt[c - c/(a*x)]*x^2)/(12*a) + (Sqrt[c - c/(a*x)]*x^3)/3 + (11*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/(8*a^3)}
{E^(2*ArcCoth[a*x])*Sqrt[c - c/(a*x)]*x, x, 7, (7*Sqrt[c - c/(a*x)]*x)/(4*a) + (Sqrt[c - c/(a*x)]*x^2)/2 + (7*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/(4*a^2)}
{E^(2*ArcCoth[a*x])*Sqrt[c - c/(a*x)], x, 6, Sqrt[c - c/(a*x)]*x + (3*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/a}
{(E^(2*ArcCoth[a*x])*Sqrt[c - c/(a*x)])/x, x, 6, 2*Sqrt[c - c/(a*x)] + 2*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]]}
{(E^(2*ArcCoth[a*x])*Sqrt[c - c/(a*x)])/x^2, x, 5, 4*a*Sqrt[c - c/(a*x)] - (2*a*(c - c/(a*x))^(3/2))/(3*c)}
{(E^(2*ArcCoth[a*x])*Sqrt[c - c/(a*x)])/x^3, x, 6, 4*a^2*Sqrt[c - c/(a*x)] - (2*a^2*(c - c/(a*x))^(3/2))/c + (2*a^2*(c - c/(a*x))^(5/2))/(5*c^2)}
{(E^(2*ArcCoth[a*x])*Sqrt[c - c/(a*x)])/x^4, x, 6, 4*a^3*Sqrt[c - c/(a*x)] - (10*a^3*(c - c/(a*x))^(3/2))/(3*c) + (8*a^3*(c - c/(a*x))^(5/2))/(5*c^2) - (2*a^3*(c - c/(a*x))^(7/2))/(7*c^3)}
{(E^(2*ArcCoth[a*x])*Sqrt[c - c/(a*x)])/x^5, x, 6, 4*a^4*Sqrt[c - c/(a*x)] - (14*a^4*(c - c/(a*x))^(3/2))/(3*c) + (18*a^4*(c - c/(a*x))^(5/2))/(5*c^2) - (10*a^4*(c - c/(a*x))^(7/2))/(7*c^3) + (2*a^4*(c - c/(a*x))^(9/2))/(9*c^4)}


{E^(3*ArcCoth[a*x])*Sqrt[c - c/(a*x)]*x^3, x, 9, (149*Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)]*x)/(64*a^3*Sqrt[1 - 1/(a*x)]) + (107*Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)]*x^2)/(96*a^2*Sqrt[1 - 1/(a*x)]) + (11*Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)]*x^3)/(24*a*Sqrt[1 - 1/(a*x)]) + ((1 + 1/(a*x))^(3/2)*Sqrt[c - c/(a*x)]*x^4)/(4*Sqrt[1 - 1/(a*x)]) + (363*Sqrt[c - c/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]])/(64*a^4*Sqrt[1 - 1/(a*x)]) - (4*Sqrt[2]*Sqrt[c - c/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]/Sqrt[2]])/(a^4*Sqrt[1 - 1/(a*x)])}
{E^(3*ArcCoth[a*x])*Sqrt[c - c/(a*x)]*x^2, x, 8, (19*Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)]*x)/(8*a^2*Sqrt[1 - 1/(a*x)]) + (3*Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)]*x^2)/(4*a*Sqrt[1 - 1/(a*x)]) + ((1 + 1/(a*x))^(3/2)*Sqrt[c - c/(a*x)]*x^3)/(3*Sqrt[1 - 1/(a*x)]) + (45*Sqrt[c - c/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]])/(8*a^3*Sqrt[1 - 1/(a*x)]) - (4*Sqrt[2]*Sqrt[c - c/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]/Sqrt[2]])/(a^3*Sqrt[1 - 1/(a*x)])}
{E^(3*ArcCoth[a*x])*Sqrt[c - c/(a*x)]*x, x, 7, (7*Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)]*x)/(4*a*Sqrt[1 - 1/(a*x)]) + ((1 + 1/(a*x))^(3/2)*Sqrt[c - c/(a*x)]*x^2)/(2*Sqrt[1 - 1/(a*x)]) + (23*Sqrt[c - c/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]])/(4*a^2*Sqrt[1 - 1/(a*x)]) - (4*Sqrt[2]*Sqrt[c - c/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]/Sqrt[2]])/(a^2*Sqrt[1 - 1/(a*x)])}
{E^(3*ArcCoth[a*x])*Sqrt[c - c/(a*x)], x, 7, -((Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)])/(a*Sqrt[1 - 1/(a*x)])) + ((1 + 1/(a*x))^(3/2)*Sqrt[c - c/(a*x)]*x)/Sqrt[1 - 1/(a*x)] + (5*Sqrt[c - c/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*Sqrt[1 - 1/(a*x)]) - (4*Sqrt[2]*Sqrt[c - c/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]/Sqrt[2]])/(a*Sqrt[1 - 1/(a*x)])}
{(E^(3*ArcCoth[a*x])*Sqrt[c - c/(a*x)])/x, x, 6, (2*Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)])/Sqrt[1 - 1/(a*x)] + (2*Sqrt[c - c/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]])/Sqrt[1 - 1/(a*x)] - (4*Sqrt[2]*Sqrt[c - c/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]/Sqrt[2]])/Sqrt[1 - 1/(a*x)]}
{(E^(3*ArcCoth[a*x])*Sqrt[c - c/(a*x)])/x^2, x, 5, (4*a*Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)])/Sqrt[1 - 1/(a*x)] + (2*a*(1 + 1/(a*x))^(3/2)*Sqrt[c - c/(a*x)])/(3*Sqrt[1 - 1/(a*x)]) - (4*Sqrt[2]*a*Sqrt[c - c/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]/Sqrt[2]])/Sqrt[1 - 1/(a*x)]}
{(E^(3*ArcCoth[a*x])*Sqrt[c - c/(a*x)])/x^3, x, 6, (4*a^2*Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)])/Sqrt[1 - 1/(a*x)] + (2*a^2*(1 + 1/(a*x))^(3/2)*Sqrt[c - c/(a*x)])/(3*Sqrt[1 - 1/(a*x)]) + (2*a^2*(1 + 1/(a*x))^(5/2)*Sqrt[c - c/(a*x)])/(5*Sqrt[1 - 1/(a*x)]) - (4*Sqrt[2]*a^2*Sqrt[c - c/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]/Sqrt[2]])/Sqrt[1 - 1/(a*x)]}
{(E^(3*ArcCoth[a*x])*Sqrt[c - c/(a*x)])/x^4, x, 7, (4*a^3*Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)])/Sqrt[1 - 1/(a*x)] + (2*a^3*(1 + 1/(a*x))^(3/2)*Sqrt[c - c/(a*x)])/(3*Sqrt[1 - 1/(a*x)]) + (2*a^3*(1 + 1/(a*x))^(5/2)*Sqrt[c - c/(a*x)])/(7*Sqrt[1 - 1/(a*x)]) + (2*a^2*(1 + 1/(a*x))^(5/2)*Sqrt[c - c/(a*x)])/(7*Sqrt[1 - 1/(a*x)]*x) - (4*Sqrt[2]*a^3*Sqrt[c - c/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]/Sqrt[2]])/Sqrt[1 - 1/(a*x)]}
{(E^(3*ArcCoth[a*x])*Sqrt[c - c/(a*x)])/x^5, x, 8, (4*a^4*Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)])/Sqrt[1 - 1/(a*x)] + (316*a^4*(1 + 1/(a*x))^(3/2)*Sqrt[c - c/(a*x)])/(315*Sqrt[1 - 1/(a*x)]) + (2*a*(1 + 1/(a*x))^(3/2)*Sqrt[c - c/(a*x)])/(9*Sqrt[1 - 1/(a*x)]*x^3) + (8*a^2*(1 + 1/(a*x))^(3/2)*Sqrt[c - c/(a*x)])/(21*Sqrt[1 - 1/(a*x)]*x^2) + (52*a^3*(1 + 1/(a*x))^(3/2)*Sqrt[c - c/(a*x)])/(105*Sqrt[1 - 1/(a*x)]*x) - (4*Sqrt[2]*a^4*Sqrt[c - c/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]/Sqrt[2]])/Sqrt[1 - 1/(a*x)]}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(Sqrt[c - c/(a*x)]*x^m)/E^ArcCoth[a*x], x, 5, (-2*Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)]*x^(1 + m))/((1 + 2*m)*Sqrt[1 - 1/(a*x)]) + ((3 + 4*m)*Sqrt[c - c/(a*x)]*x^(1 + m)*Hypergeometric2F1[1/2, -1 - m, -m, -(1/(a*x))])/((1 + m)*(1 + 2*m)*Sqrt[1 - 1/(a*x)]), -(((3 + 4*m)*Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)]*x^m)/(2*a*m*(1 + m)*Sqrt[1 - 1/(a*x)])) + (Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)]*x^(1 + m))/((1 + m)*Sqrt[1 - 1/(a*x)]) + ((1 - 2*m)*(3 + 4*m)*Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)]*(-(1/(a*x)))^m*x^m*Hypergeometric2F1[1/2, m, 3/2, 1 + 1/(a*x)])/(2*a*m*(1 + m)*Sqrt[1 - 1/(a*x)])}

{(Sqrt[c - c/(a*x)]*x^2)/E^ArcCoth[a*x], x, 6, (11*Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)]*x)/(8*a^2*Sqrt[1 - 1/(a*x)]) - (11*Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)]*x^2)/(12*a*Sqrt[1 - 1/(a*x)]) + (Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)]*x^3)/(3*Sqrt[1 - 1/(a*x)]) - (11*Sqrt[c - c/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]])/(8*a^3*Sqrt[1 - 1/(a*x)])}
{(Sqrt[c - c/(a*x)]*x)/E^ArcCoth[a*x], x, 5, (-7*Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)]*x)/(4*a*Sqrt[1 - 1/(a*x)]) + (Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)]*x^2)/(2*Sqrt[1 - 1/(a*x)]) + (7*Sqrt[c - c/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]])/(4*a^2*Sqrt[1 - 1/(a*x)])}
{Sqrt[c - c/(a*x)]/E^ArcCoth[a*x], x, 4, (Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)]*x)/Sqrt[1 - 1/(a*x)] - (3*Sqrt[c - c/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*Sqrt[1 - 1/(a*x)])}
{Sqrt[c - c/(a*x)]/(E^ArcCoth[a*x]*x), x, 4, (2*Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)])/Sqrt[1 - 1/(a*x)] + (2*Sqrt[c - c/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]])/Sqrt[1 - 1/(a*x)]}
{Sqrt[c - c/(a*x)]/(E^ArcCoth[a*x]*x^2), x, 4, (-4*a*Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)])/Sqrt[1 - 1/(a*x)] + (2*a*(1 + 1/(a*x))^(3/2)*Sqrt[c - c/(a*x)])/(3*Sqrt[1 - 1/(a*x)])}
{Sqrt[c - c/(a*x)]/(E^ArcCoth[a*x]*x^3), x, 4, (4*a^2*Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)])/Sqrt[1 - 1/(a*x)] - (2*a^2*(1 + 1/(a*x))^(3/2)*Sqrt[c - c/(a*x)])/Sqrt[1 - 1/(a*x)] + (2*a^2*(1 + 1/(a*x))^(5/2)*Sqrt[c - c/(a*x)])/(5*Sqrt[1 - 1/(a*x)])}
{Sqrt[c - c/(a*x)]/(E^ArcCoth[a*x]*x^4), x, 4, (-4*a^3*Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)])/Sqrt[1 - 1/(a*x)] + (10*a^3*(1 + 1/(a*x))^(3/2)*Sqrt[c - c/(a*x)])/(3*Sqrt[1 - 1/(a*x)]) - (8*a^3*(1 + 1/(a*x))^(5/2)*Sqrt[c - c/(a*x)])/(5*Sqrt[1 - 1/(a*x)]) + (2*a^3*(1 + 1/(a*x))^(7/2)*Sqrt[c - c/(a*x)])/(7*Sqrt[1 - 1/(a*x)])}


{(Sqrt[c - c/(a*x)]*x^3)/E^(2*ArcCoth[a*x]), x, 11, (-149*Sqrt[c - c/(a*x)]*x)/(64*a^3) + (107*Sqrt[c - c/(a*x)]*x^2)/(96*a^2) - (17*Sqrt[c - c/(a*x)]*x^3)/(24*a) + (Sqrt[c - c/(a*x)]*x^4)/4 + (363*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/(64*a^4) - (4*Sqrt[2]*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])])/a^4}
{(Sqrt[c - c/(a*x)]*x^2)/E^(2*ArcCoth[a*x]), x, 10, (19*Sqrt[c - c/(a*x)]*x)/(8*a^2) - (13*Sqrt[c - c/(a*x)]*x^2)/(12*a) + (Sqrt[c - c/(a*x)]*x^3)/3 - (45*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/(8*a^3) + (4*Sqrt[2]*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])])/a^3}
{(Sqrt[c - c/(a*x)]*x)/E^(2*ArcCoth[a*x]), x, 9, (-9*Sqrt[c - c/(a*x)]*x)/(4*a) + (Sqrt[c - c/(a*x)]*x^2)/2 + (23*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/(4*a^2) - (4*Sqrt[2]*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])])/a^2}
{Sqrt[c - c/(a*x)]/E^(2*ArcCoth[a*x]), x, 10, Sqrt[c - c/(a*x)]*x - (5*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]])/a + (4*Sqrt[2]*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])])/a}
{Sqrt[c - c/(a*x)]/(E^(2*ArcCoth[a*x])*x), x, 8, 2*Sqrt[c - c/(a*x)] + 2*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/Sqrt[c]] - 4*Sqrt[2]*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])]}
{Sqrt[c - c/(a*x)]/(E^(2*ArcCoth[a*x])*x^2), x, 7, -4*a*Sqrt[c - c/(a*x)] - (2*a*(c - c/(a*x))^(3/2))/(3*c) + 4*Sqrt[2]*a*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])]}
{Sqrt[c - c/(a*x)]/(E^(2*ArcCoth[a*x])*x^3), x, 7, 4*a^2*Sqrt[c - c/(a*x)] + (2*a^2*(c - c/(a*x))^(3/2))/(3*c) + (2*a^2*(c - c/(a*x))^(5/2))/(5*c^2) - 4*Sqrt[2]*a^2*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])]}
{Sqrt[c - c/(a*x)]/(E^(2*ArcCoth[a*x])*x^4), x, 7, -4*a^3*Sqrt[c - c/(a*x)] - (2*a^3*(c - c/(a*x))^(3/2))/(3*c) - (2*a^3*(c - c/(a*x))^(7/2))/(7*c^3) + 4*Sqrt[2]*a^3*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])]}
{Sqrt[c - c/(a*x)]/(E^(2*ArcCoth[a*x])*x^5), x, 7, 4*a^4*Sqrt[c - c/(a*x)] + (2*a^4*(c - c/(a*x))^(3/2))/(3*c) + (2*a^4*(c - c/(a*x))^(5/2))/(5*c^2) - (2*a^4*(c - c/(a*x))^(7/2))/(7*c^3) + (2*a^4*(c - c/(a*x))^(9/2))/(9*c^4) - 4*Sqrt[2]*a^4*Sqrt[c]*ArcTanh[Sqrt[c - c/(a*x)]/(Sqrt[2]*Sqrt[c])]}


{(Sqrt[c - c/(a*x)]*x^3)/E^(3*ArcCoth[a*x]), x, 8, (-1115*Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)]*x)/(64*a^3*Sqrt[1 - 1/(a*x)]) - (223*Sqrt[c - c/(a*x)]*x^2)/(24*a^2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]) + (1115*Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)]*x^2)/(96*a^2*Sqrt[1 - 1/(a*x)]) - (25*Sqrt[c - c/(a*x)]*x^3)/(24*a*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]) + (Sqrt[c - c/(a*x)]*x^4)/(4*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]) + (1115*Sqrt[c - c/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]])/(64*a^4*Sqrt[1 - 1/(a*x)])}
{(Sqrt[c - c/(a*x)]*x^2)/E^(3*ArcCoth[a*x]), x, 7, (-119*Sqrt[c - c/(a*x)]*x)/(12*a^2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]) + (119*Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)]*x)/(8*a^2*Sqrt[1 - 1/(a*x)]) - (19*Sqrt[c - c/(a*x)]*x^2)/(12*a*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]) + (Sqrt[c - c/(a*x)]*x^3)/(3*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]) - (119*Sqrt[c - c/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]])/(8*a^3*Sqrt[1 - 1/(a*x)])}
{(Sqrt[c - c/(a*x)]*x)/E^(3*ArcCoth[a*x]), x, 6, (-47*Sqrt[c - c/(a*x)])/(4*a^2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]) - (13*Sqrt[c - c/(a*x)]*x)/(4*a*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]) + (Sqrt[c - c/(a*x)]*x^2)/(2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]) + (47*Sqrt[c - c/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]])/(4*a^2*Sqrt[1 - 1/(a*x)])}
{Sqrt[c - c/(a*x)]/E^(3*ArcCoth[a*x]), x, 5, (9*Sqrt[c - c/(a*x)])/(a*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]) + (Sqrt[c - c/(a*x)]*x)/(Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]) - (7*Sqrt[c - c/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]])/(a*Sqrt[1 - 1/(a*x)])}
{Sqrt[c - c/(a*x)]/(E^(3*ArcCoth[a*x])*x), x, 6, (-8*Sqrt[c - c/(a*x)])/(Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]) - (2*Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)])/Sqrt[1 - 1/(a*x)] + (2*Sqrt[c - c/(a*x)]*ArcTanh[Sqrt[1 + 1/(a*x)]])/Sqrt[1 - 1/(a*x)]}
{Sqrt[c - c/(a*x)]/(E^(3*ArcCoth[a*x])*x^2), x, 4, (8*a*Sqrt[c - c/(a*x)])/(Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]) + (8*a*Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)])/Sqrt[1 - 1/(a*x)] - (2*a*(1 + 1/(a*x))^(3/2)*Sqrt[c - c/(a*x)])/(3*Sqrt[1 - 1/(a*x)])}
{Sqrt[c - c/(a*x)]/(E^(3*ArcCoth[a*x])*x^3), x, 4, (-8*a^2*Sqrt[c - c/(a*x)])/(Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]) - (16*a^2*Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)])/Sqrt[1 - 1/(a*x)] + (10*a^2*(1 + 1/(a*x))^(3/2)*Sqrt[c - c/(a*x)])/(3*Sqrt[1 - 1/(a*x)]) - (2*a^2*(1 + 1/(a*x))^(5/2)*Sqrt[c - c/(a*x)])/(5*Sqrt[1 - 1/(a*x)])}
{Sqrt[c - c/(a*x)]/(E^(3*ArcCoth[a*x])*x^4), x, 4, (8*a^3*Sqrt[c - c/(a*x)])/(Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]) + (24*a^3*Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)])/Sqrt[1 - 1/(a*x)] - (26*a^3*(1 + 1/(a*x))^(3/2)*Sqrt[c - c/(a*x)])/(3*Sqrt[1 - 1/(a*x)]) + (12*a^3*(1 + 1/(a*x))^(5/2)*Sqrt[c - c/(a*x)])/(5*Sqrt[1 - 1/(a*x)]) - (2*a^3*(1 + 1/(a*x))^(7/2)*Sqrt[c - c/(a*x)])/(7*Sqrt[1 - 1/(a*x)])}
{Sqrt[c - c/(a*x)]/(E^(3*ArcCoth[a*x])*x^5), x, 4, (-8*a^4*Sqrt[c - c/(a*x)])/(Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]) - (32*a^4*Sqrt[1 + 1/(a*x)]*Sqrt[c - c/(a*x)])/Sqrt[1 - 1/(a*x)] + (50*a^4*(1 + 1/(a*x))^(3/2)*Sqrt[c - c/(a*x)])/(3*Sqrt[1 - 1/(a*x)]) - (38*a^4*(1 + 1/(a*x))^(5/2)*Sqrt[c - c/(a*x)])/(5*Sqrt[1 - 1/(a*x)]) + (2*a^4*(1 + 1/(a*x))^(7/2)*Sqrt[c - c/(a*x)])/Sqrt[1 - 1/(a*x)] - (2*a^4*(1 + 1/(a*x))^(9/2)*Sqrt[c - c/(a*x)])/(9*Sqrt[1 - 1/(a*x)])}


(* ::Subsection::Closed:: *)
(*Integrands of the form E^(n ArcCoth[a x]) (c-c a^2 x^2)^p*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{E^ArcCoth[a*x]*(c - a^2*c*x^2)^p, x, 3, ((1 + 1/(a*x))^(1 + 2*p)*x*(c - a^2*c*x^2)^p*Hypergeometric2F1[-1 - 2*p, 1/2 - p, -2*p, 2/((a + x^(-1))*x)])/((1 + 2*p)*(1 - 1/(a^2*x^2))^p)}

{E^ArcCoth[a*x]*(c - a^2*c*x^2)^4, x, 12, (35*c^4*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/128 + (35*a*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2)*x^2)/384 + (7*a^2*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(5/2)*x^3)/192 + (a^3*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(7/2)*x^4)/64 + (a^4*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(9/2)*x^5)/144 - (5*a^5*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(11/2)*x^6)/144 + (5*a^6*c^4*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(11/2)*x^7)/72 - (7*a^7*c^4*(1 - 1/(a*x))^(5/2)*(1 + 1/(a*x))^(11/2)*x^8)/72 + (a^8*c^4*(1 - 1/(a*x))^(7/2)*(1 + 1/(a*x))^(11/2)*x^9)/9 + (35*c^4*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(64*a)}
{E^ArcCoth[a*x]*(c - a^2*c*x^2)^3, x, 10, (5*c^3*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/16 + (5*a*c^3*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2)*x^2)/48 + (a^2*c^3*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(5/2)*x^3)/24 + (a^3*c^3*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(7/2)*x^4)/56 - (a^4*c^3*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(9/2)*x^5)/14 + (5*a^5*c^3*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(9/2)*x^6)/42 - (a^6*c^3*(1 - 1/(a*x))^(5/2)*(1 + 1/(a*x))^(9/2)*x^7)/7 + (5*c^3*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(8*a)}
{E^ArcCoth[a*x]*(c - a^2*c*x^2)^2, x, 8, (3*c^2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/8 + (a*c^2*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2)*x^2)/8 + (a^2*c^2*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(5/2)*x^3)/20 - (3*a^3*c^2*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(7/2)*x^4)/20 + (a^4*c^2*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(7/2)*x^5)/5 + (3*c^2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(4*a)}
{E^ArcCoth[a*x]*(c - a^2*c*x^2), x, 6, (c*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/2 + (a*c*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2)*x^2)/6 - (a^2*c*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(5/2)*x^3)/3 + (c*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{E^ArcCoth[a*x]/(c - a^2*c*x^2), x, 1, E^ArcCoth[a*x]/(a*c)}
{E^ArcCoth[a*x]/(c - a^2*c*x^2)^2, x, 2, (2*E^ArcCoth[a*x])/(3*a*c^2) - (E^ArcCoth[a*x]*(1 - 2*a*x))/(3*a*c^2*(1 - a^2*x^2))}
{E^ArcCoth[a*x]/(c - a^2*c*x^2)^3, x, 3, (8*E^ArcCoth[a*x])/(15*a*c^3) - (E^ArcCoth[a*x]*(1 - 4*a*x))/(15*a*c^3*(1 - a^2*x^2)^2) - (4*E^ArcCoth[a*x]*(1 - 2*a*x))/(15*a*c^3*(1 - a^2*x^2))}
{E^ArcCoth[a*x]/(c - a^2*c*x^2)^4, x, 4, (16*E^ArcCoth[a*x])/(35*a*c^4) - (E^ArcCoth[a*x]*(1 - 6*a*x))/(35*a*c^4*(1 - a^2*x^2)^3) - (2*E^ArcCoth[a*x]*(1 - 4*a*x))/(35*a*c^4*(1 - a^2*x^2)^2) - (8*E^ArcCoth[a*x]*(1 - 2*a*x))/(35*a*c^4*(1 - a^2*x^2))}


{E^(2*ArcCoth[a*x])*(c - a^2*c*x^2)^p, x, 5, ((1 + p)*(c - a^2*c*x^2)^p)/(a*p*(1 + 2*p)) + ((1 + a*x)*(c - a^2*c*x^2)^p)/(a*(1 + 2*p)) - (2*c*(1 + p)*x*(1 - a^2*x^2)^(1 - p)*(c - a^2*c*x^2)^(-1 + p)*Hypergeometric2F1[1/2, 1 - p, 3/2, a^2*x^2])/(1 + 2*p)}

{E^(2*ArcCoth[a*x])*(c - a^2*c*x^2)^5, x, 4, -((16*c^5*(1 + a*x)^7)/(7*a)) + (4*c^5*(1 + a*x)^8)/a - (8*c^5*(1 + a*x)^9)/(3*a) + (4*c^5*(1 + a*x)^10)/(5*a) - (c^5*(1 + a*x)^11)/(11*a)}
{E^(2*ArcCoth[a*x])*(c - a^2*c*x^2)^4, x, 4, -((4*c^4*(1 + a*x)^6)/(3*a)) + (12*c^4*(1 + a*x)^7)/(7*a) - (3*c^4*(1 + a*x)^8)/(4*a) + (c^4*(1 + a*x)^9)/(9*a)}
{E^(2*ArcCoth[a*x])*(c - a^2*c*x^2)^3, x, 4, -((4*c^3*(1 + a*x)^5)/(5*a)) + (2*c^3*(1 + a*x)^6)/(3*a) - (c^3*(1 + a*x)^7)/(7*a)}
{E^(2*ArcCoth[a*x])*(c - a^2*c*x^2)^2, x, 4, -((c^2*(1 + a*x)^4)/(2*a)) + (c^2*(1 + a*x)^5)/(5*a)}
{E^(2*ArcCoth[a*x])*(c - a^2*c*x^2)^1, x, 3, -((c*(1 + a*x)^3)/(3*a))}
{E^(2*ArcCoth[a*x])/(c - a^2*c*x^2)^1, x, 3, -(1/(a*c*(1 - a*x)))}
{E^(2*ArcCoth[a*x])/(c - a^2*c*x^2)^2, x, 5, -(1/(4*a*c^2*(1 - a*x)^2)) - 1/(4*a*c^2*(1 - a*x)) - ArcTanh[a*x]/(4*a*c^2)}
{E^(2*ArcCoth[a*x])/(c - a^2*c*x^2)^3, x, 5, -(1/(12*a*c^3*(1 - a*x)^3)) - 1/(8*a*c^3*(1 - a*x)^2) - 3/(16*a*c^3*(1 - a*x)) + 1/(16*a*c^3*(1 + a*x)) - ArcTanh[a*x]/(4*a*c^3)}
{E^(2*ArcCoth[a*x])/(c - a^2*c*x^2)^4, x, 5, -(1/(32*a*c^4*(1 - a*x)^4)) - 1/(16*a*c^4*(1 - a*x)^3) - 3/(32*a*c^4*(1 - a*x)^2) - 5/(32*a*c^4*(1 - a*x)) + 1/(64*a*c^4*(1 + a*x)^2) + 5/(64*a*c^4*(1 + a*x)) - (15*ArcTanh[a*x])/(64*a*c^4)}


{E^(3*ArcCoth[a*x])*(c - a^2*c*x^2)^p, x, 3, ((1 + 1/(a*x))^(1 + 2*p)*x*(c - a^2*c*x^2)^p*Hypergeometric2F1[-1 - 2*p, 3/2 - p, -2*p, 2/((a + x^(-1))*x)])/((1 + 2*p)*(1 - 1/(a^2*x^2))^p)}

{E^(3*ArcCoth[a*x])*(c - a^2*c*x^2)^4, x, 12, (-55*c^4*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/128 - (55*a*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2)*x^2)/384 - (11*a^2*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(5/2)*x^3)/192 - (11*a^3*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(7/2)*x^4)/448 - (11*a^4*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(9/2)*x^5)/1008 - (5*a^5*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(11/2)*x^6)/1008 + (5*a^6*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(13/2)*x^7)/168 - (5*a^7*c^4*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(13/2)*x^8)/72 + (a^8*c^4*(1 - 1/(a*x))^(5/2)*(1 + 1/(a*x))^(13/2)*x^9)/9 - (55*c^4*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(64*a)}
{E^(3*ArcCoth[a*x])*(c - a^2*c*x^2)^3, x, 10, (-9*c^3*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/16 - (3*a*c^3*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2)*x^2)/16 - (3*a^2*c^3*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(5/2)*x^3)/40 - (9*a^3*c^3*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(7/2)*x^4)/280 - (a^4*c^3*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(9/2)*x^5)/70 + (a^5*c^3*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(11/2)*x^6)/14 - (a^6*c^3*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(11/2)*x^7)/7 - (9*c^3*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(8*a)}
{E^(3*ArcCoth[a*x])*(c - a^2*c*x^2)^2, x, 8, (-7*c^2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/8 - (7*a*c^2*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2)*x^2)/24 - (7*a^2*c^2*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(5/2)*x^3)/60 - (a^3*c^2*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(7/2)*x^4)/20 + (a^4*c^2*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(9/2)*x^5)/5 - (7*c^2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(4*a)}
{E^(3*ArcCoth[a*x])*(c - a^2*c*x^2), x, 6, (-5*c*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/2 - (5*a*c*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2)*x^2)/6 - (a^2*c*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(5/2)*x^3)/3 - (5*c*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{E^(3*ArcCoth[a*x])/(c - a^2*c*x^2), x, 1, E^(3*ArcCoth[a*x])/(3*a*c)}
{E^(3*ArcCoth[a*x])/(c - a^2*c*x^2)^2, x, 2, -((2*E^(3*ArcCoth[a*x]))/(15*a*c^2)) + (E^(3*ArcCoth[a*x])*(3 - 2*a*x))/(5*a*c^2*(1 - a^2*x^2))}
{E^(3*ArcCoth[a*x])/(c - a^2*c*x^2)^3, x, 3, -((8*E^(3*ArcCoth[a*x]))/(35*a*c^3)) - (E^(3*ArcCoth[a*x])*(3 - 4*a*x))/(7*a*c^3*(1 - a^2*x^2)^2) + (12*E^(3*ArcCoth[a*x])*(3 - 2*a*x))/(35*a*c^3*(1 - a^2*x^2))}
{E^(3*ArcCoth[a*x])/(c - a^2*c*x^2)^4, x, 4, -((16*E^(3*ArcCoth[a*x]))/(63*a*c^4)) - (E^(3*ArcCoth[a*x])*(1 - 2*a*x))/(9*a*c^4*(1 - a^2*x^2)^3) - (10*E^(3*ArcCoth[a*x])*(3 - 4*a*x))/(63*a*c^4*(1 - a^2*x^2)^2) + (8*E^(3*ArcCoth[a*x])*(3 - 2*a*x))/(21*a*c^4*(1 - a^2*x^2))}


{E^(4*ArcCoth[a*x])*(c - a^2*c*x^2)^p, x, 7, -((2*c*(1 + p)*(2 + p)*(c - a^2*c*x^2)^(-1 + p))/(a*(1 - 2*p)*(1 - p)*(1 + 2*p))) + (2*c*(1 + p)*(2 + p)*(1 + a*x)*(c - a^2*c*x^2)^(-1 + p))/(a*p*(1 - 4*p^2)) - (c*(2 + p)*(1 + a*x)^2*(c - a^2*c*x^2)^(-1 + p))/(a*p*(1 + 2*p)) - (c*(1 + a*x)^3*(c - a^2*c*x^2)^(-1 + p))/(a*(1 + 2*p)) - (4*c^2*(1 + p)*(2 + p)*x*(1 - a^2*x^2)^(2 - p)*(c - a^2*c*x^2)^(-2 + p)*Hypergeometric2F1[1/2, 2 - p, 3/2, a^2*x^2])/(1 - 4*p^2)}

{E^(4*ArcCoth[a*x])*(c - a^2*c*x^2)^5, x, 4, (c^5*(1 + a*x)^8)/a - (4*c^5*(1 + a*x)^9)/(3*a) + (3*c^5*(1 + a*x)^10)/(5*a) - (c^5*(1 + a*x)^11)/(11*a)}
{E^(4*ArcCoth[a*x])*(c - a^2*c*x^2)^4, x, 4, (4*c^4*(1 + a*x)^7)/(7*a) - (c^4*(1 + a*x)^8)/(2*a) + (c^4*(1 + a*x)^9)/(9*a)}
{E^(4*ArcCoth[a*x])*(c - a^2*c*x^2)^3, x, 4, (c^3*(1 + a*x)^6)/(3*a) - (c^3*(1 + a*x)^7)/(7*a)}
{E^(4*ArcCoth[a*x])*(c - a^2*c*x^2)^2, x, 3, (c^2*(1 + a*x)^5)/(5*a)}
{E^(4*ArcCoth[a*x])*(c - a^2*c*x^2), x, 4, -4*c*x - (c*(1 + a*x)^2)/a - (c*(1 + a*x)^3)/(3*a) - (8*c*Log[1 - a*x])/a}
{E^(4*ArcCoth[a*x])/(c - a^2*c*x^2), x, 3, (1 + a*x)^2/(4*a*c*(1 - a*x)^2)}
{E^(4*ArcCoth[a*x])/(c - a^2*c*x^2)^2, x, 3, 1/(3*a*c^2*(1 - a*x)^3)}
{E^(4*ArcCoth[a*x])/(c - a^2*c*x^2)^3, x, 5, 1/(8*a*c^3*(1 - a*x)^4) + 1/(12*a*c^3*(1 - a*x)^3) + 1/(16*a*c^3*(1 - a*x)^2) + 1/(16*a*c^3*(1 - a*x)) + ArcTanh[a*x]/(16*a*c^3)}
{E^(4*ArcCoth[a*x])/(c - a^2*c*x^2)^4, x, 5, 1/(20*a*c^4*(1 - a*x)^5) + 1/(16*a*c^4*(1 - a*x)^4) + 1/(16*a*c^4*(1 - a*x)^3) + 1/(16*a*c^4*(1 - a*x)^2) + 5/(64*a*c^4*(1 - a*x)) - 1/(64*a*c^4*(1 + a*x)) + (3*ArcTanh[a*x])/(32*a*c^4)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(c - a^2*c*x^2)^p/E^ArcCoth[a*x], x, 3, ((1 + 1/(a*x))^(1 + 2*p)*x*(c - a^2*c*x^2)^p*Hypergeometric2F1[-1 - 2*p, -1/2 - p, -2*p, 2/((a + x^(-1))*x)])/((1 + 2*p)*(1 - 1/(a^2*x^2))^p)}

{(c - a^2*c*x^2)^4/E^ArcCoth[a*x], x, 12, (-35*c^4*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/128 - (35*a*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2)*x^2)/384 - (7*a^2*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(5/2)*x^3)/192 - (a^3*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(7/2)*x^4)/64 + (a^4*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(9/2)*x^5)/16 - (5*a^5*c^4*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(9/2)*x^6)/48 + (a^6*c^4*(1 - 1/(a*x))^(5/2)*(1 + 1/(a*x))^(9/2)*x^7)/8 - (a^7*c^4*(1 - 1/(a*x))^(7/2)*(1 + 1/(a*x))^(9/2)*x^8)/8 + (a^8*c^4*(1 - 1/(a*x))^(9/2)*(1 + 1/(a*x))^(9/2)*x^9)/9 - (35*c^4*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(64*a)}
{(c - a^2*c*x^2)^3/E^ArcCoth[a*x], x, 10, (-5*c^3*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/16 - (5*a*c^3*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2)*x^2)/48 - (a^2*c^3*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(5/2)*x^3)/24 + (a^3*c^3*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(7/2)*x^4)/8 - (a^4*c^3*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(7/2)*x^5)/6 + (a^5*c^3*(1 - 1/(a*x))^(5/2)*(1 + 1/(a*x))^(7/2)*x^6)/6 - (a^6*c^3*(1 - 1/(a*x))^(7/2)*(1 + 1/(a*x))^(7/2)*x^7)/7 - (5*c^3*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(8*a)}
{(c - a^2*c*x^2)^2/E^ArcCoth[a*x], x, 8, (-3*c^2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/8 - (a*c^2*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2)*x^2)/8 + (a^2*c^2*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(5/2)*x^3)/4 - (a^3*c^2*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(5/2)*x^4)/4 + (a^4*c^2*(1 - 1/(a*x))^(5/2)*(1 + 1/(a*x))^(5/2)*x^5)/5 - (3*c^2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(4*a)}
{(c - a^2*c*x^2)/E^ArcCoth[a*x], x, 6, -(c*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/2 + (a*c*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2)*x^2)/2 - (a^2*c*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(3/2)*x^3)/3 - (c*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{1/(E^ArcCoth[a*x]*(c - a^2*c*x^2)), x, 1, -(1/(a*c*E^ArcCoth[a*x]))}
{1/(E^ArcCoth[a*x]*(c - a^2*c*x^2)^2), x, 2, -(2/(E^ArcCoth[a*x]*(3*a*c^2))) + (1 + 2*a*x)/(E^ArcCoth[a*x]*(3*a*c^2*(1 - a^2*x^2)))}
{1/(E^ArcCoth[a*x]*(c - a^2*c*x^2)^3), x, 3, -(8/(E^ArcCoth[a*x]*(15*a*c^3))) + (1 + 4*a*x)/(E^ArcCoth[a*x]*(15*a*c^3*(1 - a^2*x^2)^2)) + (4*(1 + 2*a*x))/(E^ArcCoth[a*x]*(15*a*c^3*(1 - a^2*x^2)))}
{1/(E^ArcCoth[a*x]*(c - a^2*c*x^2)^4), x, 4, -(16/(E^ArcCoth[a*x]*(35*a*c^4))) + (1 + 6*a*x)/(E^ArcCoth[a*x]*(35*a*c^4*(1 - a^2*x^2)^3)) + (2*(1 + 4*a*x))/(E^ArcCoth[a*x]*(35*a*c^4*(1 - a^2*x^2)^2)) + (8*(1 + 2*a*x))/(E^ArcCoth[a*x]*(35*a*c^4*(1 - a^2*x^2)))}


{(c - a^2*c*x^2)^p/E^(2*ArcCoth[a*x]), x, 5, -((c - a^2*c*x^2)^(2 + p)/(2*a*c^2*p*(1 + a*x)^2)) - (c - a^2*c*x^2)^(2 + p)/(2*a*c^2*p*(1 + a*x)) - ((3 + 2*p)*x*(1 - a^2*x^2)^(-1 - p)*(c - a^2*c*x^2)^(1 + p)*Hypergeometric2F1[1/2, -1 - p, 3/2, a^2*x^2])/(2*c*p)}

{(c - a^2*c*x^2)^4/E^(2*ArcCoth[a*x]), x, 4, (4*c^4*(1 - a*x)^6)/(3*a) - (12*c^4*(1 - a*x)^7)/(7*a) + (3*c^4*(1 - a*x)^8)/(4*a) - (c^4*(1 - a*x)^9)/(9*a)}
{(c - a^2*c*x^2)^3/E^(2*ArcCoth[a*x]), x, 4, (4*c^3*(1 - a*x)^5)/(5*a) - (2*c^3*(1 - a*x)^6)/(3*a) + (c^3*(1 - a*x)^7)/(7*a)}
{(c - a^2*c*x^2)^2/E^(2*ArcCoth[a*x]), x, 4, (-c^2)*x + a*c^2*x^2 - (1/2)*a^3*c^2*x^4 + (1/5)*a^4*c^2*x^5}
{(c - a^2*c*x^2)/E^(2*ArcCoth[a*x]), x, 3, (c*(1 - a*x)^3)/(3*a)}
{1/(E^(2*ArcCoth[a*x])*(c - a^2*c*x^2)), x, 3, 1/(a*c*(1 + a*x))}
{1/(E^(2*ArcCoth[a*x])*(c - a^2*c*x^2)^2), x, 5, 1/(4*a*c^2*(1 + a*x)^2) + 1/(4*a*c^2*(1 + a*x)) - ArcTanh[a*x]/(4*a*c^2)}
{1/(E^(2*ArcCoth[a*x])*(c - a^2*c*x^2)^3), x, 5, -(1/(16*a*c^3*(1 - a*x))) + 1/(12*a*c^3*(1 + a*x)^3) + 1/(8*a*c^3*(1 + a*x)^2) + 3/(16*a*c^3*(1 + a*x)) - ArcTanh[a*x]/(4*a*c^3)}
{1/(E^(2*ArcCoth[a*x])*(c - a^2*c*x^2)^4), x, 5, -(1/(64*a*c^4*(1 - a*x)^2)) - 5/(64*a*c^4*(1 - a*x)) + 1/(32*a*c^4*(1 + a*x)^4) + 1/(16*a*c^4*(1 + a*x)^3) + 3/(32*a*c^4*(1 + a*x)^2) + 5/(32*a*c^4*(1 + a*x)) - (15*ArcTanh[a*x])/(64*a*c^4)}


{(c - a^2*c*x^2)^p/E^(3*ArcCoth[a*x]), x, 3, ((1 + 1/(a*x))^(1 + 2*p)*x*(c - a^2*c*x^2)^p*Hypergeometric2F1[-1 - 2*p, -3/2 - p, -2*p, 2/((a + x^(-1))*x)])/((1 + 2*p)*(1 - 1/(a^2*x^2))^p)}

{(c - a^2*c*x^2)^4/E^(3*ArcCoth[a*x]), x, 12, (55*c^4*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/128 + (55*a*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2)*x^2)/384 + (11*a^2*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(5/2)*x^3)/192 - (11*a^3*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(7/2)*x^4)/64 + (11*a^4*c^4*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(7/2)*x^5)/48 - (11*a^5*c^4*(1 - 1/(a*x))^(5/2)*(1 + 1/(a*x))^(7/2)*x^6)/48 + (11*a^6*c^4*(1 - 1/(a*x))^(7/2)*(1 + 1/(a*x))^(7/2)*x^7)/56 - (11*a^7*c^4*(1 - 1/(a*x))^(9/2)*(1 + 1/(a*x))^(7/2)*x^8)/72 + (a^8*c^4*(1 - 1/(a*x))^(11/2)*(1 + 1/(a*x))^(7/2)*x^9)/9 + (55*c^4*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(64*a)}
{(c - a^2*c*x^2)^3/E^(3*ArcCoth[a*x]), x, 10, (9*c^3*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/16 + (3*a*c^3*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2)*x^2)/16 - (3*a^2*c^3*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(5/2)*x^3)/8 + (3*a^3*c^3*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(5/2)*x^4)/8 - (3*a^4*c^3*(1 - 1/(a*x))^(5/2)*(1 + 1/(a*x))^(5/2)*x^5)/10 + (3*a^5*c^3*(1 - 1/(a*x))^(7/2)*(1 + 1/(a*x))^(5/2)*x^6)/14 - (a^6*c^3*(1 - 1/(a*x))^(9/2)*(1 + 1/(a*x))^(5/2)*x^7)/7 + (9*c^3*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(8*a)}
{(c - a^2*c*x^2)^2/E^(3*ArcCoth[a*x]), x, 8, (7*c^2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/8 - (7*a*c^2*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2)*x^2)/8 + (7*a^2*c^2*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(3/2)*x^3)/12 - (7*a^3*c^2*(1 - 1/(a*x))^(5/2)*(1 + 1/(a*x))^(3/2)*x^4)/20 + (a^4*c^2*(1 - 1/(a*x))^(7/2)*(1 + 1/(a*x))^(3/2)*x^5)/5 + (7*c^2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(4*a)}
{(c - a^2*c*x^2)/E^(3*ArcCoth[a*x]), x, 6, (-5*c*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]*x)/2 + (5*a*c*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)]*x^2)/6 - (a^2*c*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)]*x^3)/3 + (5*c*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{1/(E^(3*ArcCoth[a*x])*(c - a^2*c*x^2)), x, 1, -1/(3*a*c*E^(3*ArcCoth[a*x]))}
{1/(E^(3*ArcCoth[a*x])*(c - a^2*c*x^2)^2), x, 2, 2/(E^(3*ArcCoth[a*x])*(15*a*c^2)) - (3 + 2*a*x)/(E^(3*ArcCoth[a*x])*(5*a*c^2*(1 - a^2*x^2)))}
{1/(E^(3*ArcCoth[a*x])*(c - a^2*c*x^2)^3), x, 3, 8/(E^(3*ArcCoth[a*x])*(35*a*c^3)) + (3 + 4*a*x)/(E^(3*ArcCoth[a*x])*(7*a*c^3*(1 - a^2*x^2)^2)) - (12*(3 + 2*a*x))/(E^(3*ArcCoth[a*x])*(35*a*c^3*(1 - a^2*x^2)))}
{1/(E^(3*ArcCoth[a*x])*(c - a^2*c*x^2)^4), x, 4, 16/(E^(3*ArcCoth[a*x])*(63*a*c^4)) + (1 + 2*a*x)/(E^(3*ArcCoth[a*x])*(9*a*c^4*(1 - a^2*x^2)^3)) + (10*(3 + 4*a*x))/(E^(3*ArcCoth[a*x])*(63*a*c^4*(1 - a^2*x^2)^2)) - (8*(3 + 2*a*x))/(E^(3*ArcCoth[a*x])*(21*a*c^4*(1 - a^2*x^2)))}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{(c - a^2*c*x^2)^p/E^(2*p*ArcCoth[a*x]), x, 3, ((1 - 1/(a*x))^(1 + 2*p)*x*(c - a^2*c*x^2)^p)/((1 + 2*p)*(1 - 1/(a^2*x^2))^p)}
{E^(2*p*ArcCoth[a*x])*(c - a^2*c*x^2)^p, x, 3, ((1 + 1/(a*x))^(1 + 2*p)*x*(c - a^2*c*x^2)^p)/((1 + 2*p)*(1 - 1/(a^2*x^2))^p)}


{E^(n*ArcCoth[a*x])*(c - c*a^2*x^2)^p, x, 3, ((1 + 1/(a*x))^(1 + 2*p)*x*(c - a^2*c*x^2)^p*Hypergeometric2F1[-1 - 2*p, (1/2)*(n - 2*p), -2*p, 2/((a + 1/x)*x)])/((1 - 1/(a^2*x^2))^p*(1 + 2*p))}

{E^(n*ArcCoth[a*x])*(c - c*a^2*x^2)^3, x, 3, -((2^(4 + n/2)*c^3*(1 - (a - 1/x)/(2*a))^((1/2)*(-8 + n))*(1 - 1/(a*x))^(4 - n/2)*Hypergeometric2F1[8, 4 - n/2, 5 - n/2, (2 - (a - 1/x)/a - 2/(a*x))/(2 - (a - 1/x)/a)])/(a*(8 - n)))}
{E^(n*ArcCoth[a*x])*(c - c*a^2*x^2)^2, x, 3, (2^(3 + n/2)*c^2*(1 - (a - 1/x)/(2*a))^((1/2)*(-6 + n))*(1 - 1/(a*x))^(3 - n/2)*Hypergeometric2F1[6, 3 - n/2, 4 - n/2, (2 - (a - 1/x)/a - 2/(a*x))/(2 - (a - 1/x)/a)])/(a*(6 - n))}
{E^(n*ArcCoth[a*x])*(c - c*a^2*x^2)^1, x, 3, -((2^(2 + n/2)*c*(1 - (a - 1/x)/(2*a))^((1/2)*(-4 + n))*(1 - 1/(a*x))^(2 - n/2)*Hypergeometric2F1[4, 2 - n/2, 3 - n/2, (2 - (a - 1/x)/a - 2/(a*x))/(2 - (a - 1/x)/a)])/(a*(4 - n)))}
{E^(n*ArcCoth[a*x])*(c - c*a^2*x^2)^0, x, 2, (2^(1 + n/2)*(1 - (a - 1/x)/(2*a))^((1/2)*(-2 + n))*(1 - 1/(a*x))^(1 - n/2)*Hypergeometric2F1[2, 1 - n/2, 2 - n/2, (2 - (a - 1/x)/a - 2/(a*x))/(2 - (a - 1/x)/a)])/(a*(2 - n))}
{E^(n*ArcCoth[a*x])/(c - c*a^2*x^2)^1, x, 1, E^(n*ArcCoth[a*x])/(a*c*n)}
{E^(n*ArcCoth[a*x])/(c - c*a^2*x^2)^2, x, 2, (2*E^(n*ArcCoth[a*x]))/(a*c^2*n*(4 - n^2)) - (E^(n*ArcCoth[a*x])*(n - 2*a*x))/(a*c^2*(4 - n^2)*(1 - a^2*x^2))}
{E^(n*ArcCoth[a*x])/(c - c*a^2*x^2)^3, x, 3, (24*E^(n*ArcCoth[a*x]))/(a*c^3*n*(64 - 20*n^2 + n^4)) - (E^(n*ArcCoth[a*x])*(n - 4*a*x))/(a*c^3*(16 - n^2)*(1 - a^2*x^2)^2) - (12*E^(n*ArcCoth[a*x])*(n - 2*a*x))/(a*c^3*(4 - n^2)*(16 - n^2)*(1 - a^2*x^2))}
{E^(n*ArcCoth[a*x])/(c - c*a^2*x^2)^4, x, 4, (720*E^(n*ArcCoth[a*x]))/(a*c^4*n*(36 - n^2)*(64 - 20*n^2 + n^4)) - (E^(n*ArcCoth[a*x])*(n - 6*a*x))/(a*c^4*(36 - n^2)*(1 - a^2*x^2)^3) - (30*E^(n*ArcCoth[a*x])*(n - 4*a*x))/(a*c^4*(16 - n^2)*(36 - n^2)*(1 - a^2*x^2)^2) - (360*E^(n*ArcCoth[a*x])*(n - 2*a*x))/(a*c^4*(4 - n^2)*(16 - n^2)*(36 - n^2)*(1 - a^2*x^2))}


(* ::Subsection::Closed:: *)
(*Integrands of the form E^(n ArcCoth[a x])  (c-c a^2 x^2)^(p/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{E^ArcCoth[a*x]*(c - a^2*c*x^2)^(9/2), x, 4, (8*(1 + a*x)^6*(c - a^2*c*x^2)^(9/2))/(3*a^10*(1 - 1/(a^2*x^2))^(9/2)*x^9) - (32*(1 + a*x)^7*(c - a^2*c*x^2)^(9/2))/(7*a^10*(1 - 1/(a^2*x^2))^(9/2)*x^9) + (3*(1 + a*x)^8*(c - a^2*c*x^2)^(9/2))/(a^10*(1 - 1/(a^2*x^2))^(9/2)*x^9) - (8*(1 + a*x)^9*(c - a^2*c*x^2)^(9/2))/(9*a^10*(1 - 1/(a^2*x^2))^(9/2)*x^9) + ((1 + a*x)^10*(c - a^2*c*x^2)^(9/2))/(10*a^10*(1 - 1/(a^2*x^2))^(9/2)*x^9)}
{E^ArcCoth[a*x]*(c - a^2*c*x^2)^(7/2), x, 4, -((8*(1 + a*x)^5*(c - a^2*c*x^2)^(7/2))/(5*a^8*(1 - 1/(a^2*x^2))^(7/2)*x^7)) + (2*(1 + a*x)^6*(c - a^2*c*x^2)^(7/2))/(a^8*(1 - 1/(a^2*x^2))^(7/2)*x^7) - (6*(1 + a*x)^7*(c - a^2*c*x^2)^(7/2))/(7*a^8*(1 - 1/(a^2*x^2))^(7/2)*x^7) + ((1 + a*x)^8*(c - a^2*c*x^2)^(7/2))/(8*a^8*(1 - 1/(a^2*x^2))^(7/2)*x^7)}
{E^ArcCoth[a*x]*(c - a^2*c*x^2)^(5/2), x, 4, ((1 + a*x)^4*(c - a^2*c*x^2)^(5/2))/(a^6*(1 - 1/(a^2*x^2))^(5/2)*x^5) - (4*(1 + a*x)^5*(c - a^2*c*x^2)^(5/2))/(5*a^6*(1 - 1/(a^2*x^2))^(5/2)*x^5) + ((1 + a*x)^6*(c - a^2*c*x^2)^(5/2))/(6*a^6*(1 - 1/(a^2*x^2))^(5/2)*x^5)}
{E^ArcCoth[a*x]*(c - a^2*c*x^2)^(3/2), x, 4, -((2*(1 + a*x)^3*(c - a^2*c*x^2)^(3/2))/(3*a^4*(1 - 1/(a^2*x^2))^(3/2)*x^3)) + ((1 + a*x)^4*(c - a^2*c*x^2)^(3/2))/(4*a^4*(1 - 1/(a^2*x^2))^(3/2)*x^3)}
{E^ArcCoth[a*x]*Sqrt[c - a^2*c*x^2], x, 3, Sqrt[c - a^2*c*x^2]/(a*Sqrt[1 - 1/(a^2*x^2)]) + (x*Sqrt[c - a^2*c*x^2])/(2*Sqrt[1 - 1/(a^2*x^2)])}
{E^ArcCoth[a*x]/Sqrt[c - a^2*c*x^2], x, 3, (Sqrt[1 - 1/(a^2*x^2)]*x*Log[1 - a*x])/Sqrt[c - a^2*c*x^2]}
{E^ArcCoth[a*x]/(c - a^2*c*x^2)^(3/2), x, 5, (a^2*(1 - 1/(a^2*x^2))^(3/2)*x^3)/(2*(1 - a*x)*(c - a^2*c*x^2)^(3/2)) + (a^2*(1 - 1/(a^2*x^2))^(3/2)*x^3*ArcTanh[a*x])/(2*(c - a^2*c*x^2)^(3/2))}
{E^ArcCoth[a*x]/(c - a^2*c*x^2)^(5/2), x, 5, -((a^4*(1 - 1/(a^2*x^2))^(5/2)*x^5)/(8*(1 - a*x)^2*(c - a^2*c*x^2)^(5/2))) - (a^4*(1 - 1/(a^2*x^2))^(5/2)*x^5)/(4*(1 - a*x)*(c - a^2*c*x^2)^(5/2)) + (a^4*(1 - 1/(a^2*x^2))^(5/2)*x^5)/(8*(1 + a*x)*(c - a^2*c*x^2)^(5/2)) - (3*a^4*(1 - 1/(a^2*x^2))^(5/2)*x^5*ArcTanh[a*x])/(8*(c - a^2*c*x^2)^(5/2))}
{E^ArcCoth[a*x]/(c - a^2*c*x^2)^(7/2), x, 5, (a^6*(1 - 1/(a^2*x^2))^(7/2)*x^7)/(24*(1 - a*x)^3*(c - a^2*c*x^2)^(7/2)) + (3*a^6*(1 - 1/(a^2*x^2))^(7/2)*x^7)/(32*(1 - a*x)^2*(c - a^2*c*x^2)^(7/2)) + (3*a^6*(1 - 1/(a^2*x^2))^(7/2)*x^7)/(16*(1 - a*x)*(c - a^2*c*x^2)^(7/2)) - (a^6*(1 - 1/(a^2*x^2))^(7/2)*x^7)/(32*(1 + a*x)^2*(c - a^2*c*x^2)^(7/2)) - (a^6*(1 - 1/(a^2*x^2))^(7/2)*x^7)/(8*(1 + a*x)*(c - a^2*c*x^2)^(7/2)) + (5*a^6*(1 - 1/(a^2*x^2))^(7/2)*x^7*ArcTanh[a*x])/(16*(c - a^2*c*x^2)^(7/2))}


{E^(2*ArcCoth[a*x])*(c - a^2*c*x^2)^(9/2), x, 9, (-(77/256))*c^4*x*Sqrt[c - a^2*c*x^2] - (77/384)*c^3*x*(c - a^2*c*x^2)^(3/2) - (77/480)*c^2*x*(c - a^2*c*x^2)^(5/2) - (11/80)*c*x*(c - a^2*c*x^2)^(7/2) + (11*(c - a^2*c*x^2)^(9/2))/(90*a) + ((1 + a*x)*(c - a^2*c*x^2)^(9/2))/(10*a) - (77*c^(9/2)*ArcTan[(a*Sqrt[c]*x)/Sqrt[c - a^2*c*x^2]])/(256*a)}
{E^(2*ArcCoth[a*x])*(c - a^2*c*x^2)^(7/2), x, 8, (-(45/128))*c^3*x*Sqrt[c - a^2*c*x^2] - (15/64)*c^2*x*(c - a^2*c*x^2)^(3/2) - (3/16)*c*x*(c - a^2*c*x^2)^(5/2) + (9*(c - a^2*c*x^2)^(7/2))/(56*a) + ((1 + a*x)*(c - a^2*c*x^2)^(7/2))/(8*a) - (45*c^(7/2)*ArcTan[(a*Sqrt[c]*x)/Sqrt[c - a^2*c*x^2]])/(128*a)}
{E^(2*ArcCoth[a*x])*(c - a^2*c*x^2)^(5/2), x, 7, (-(7/16))*c^2*x*Sqrt[c - a^2*c*x^2] - (7/24)*c*x*(c - a^2*c*x^2)^(3/2) + (7*(c - a^2*c*x^2)^(5/2))/(30*a) + ((1 + a*x)*(c - a^2*c*x^2)^(5/2))/(6*a) - (7*c^(5/2)*ArcTan[(a*Sqrt[c]*x)/Sqrt[c - a^2*c*x^2]])/(16*a)}
{E^(2*ArcCoth[a*x])*(c - a^2*c*x^2)^(3/2), x, 6, (-(5/8))*c*x*Sqrt[c - a^2*c*x^2] + (5*(c - a^2*c*x^2)^(3/2))/(12*a) + ((1 + a*x)*(c - a^2*c*x^2)^(3/2))/(4*a) - (5*c^(3/2)*ArcTan[(a*Sqrt[c]*x)/Sqrt[c - a^2*c*x^2]])/(8*a)}
{E^(2*ArcCoth[a*x])*Sqrt[c - a^2*c*x^2], x, 5, (3*Sqrt[c - a^2*c*x^2])/(2*a) + ((1 + a*x)*Sqrt[c - a^2*c*x^2])/(2*a) - (3*Sqrt[c]*ArcTan[(a*Sqrt[c]*x)/Sqrt[c - a^2*c*x^2]])/(2*a)}
{E^(2*ArcCoth[a*x])/Sqrt[c - a^2*c*x^2], x, 4, -((2*(1 + a*x))/(a*Sqrt[c - a^2*c*x^2])) + ArcTan[(a*Sqrt[c]*x)/Sqrt[c - a^2*c*x^2]]/(a*Sqrt[c])}
{E^(2*ArcCoth[a*x])/(c - a^2*c*x^2)^(3/2), x, 5, -((2*(1 + a*x))/(3*a*(c - a^2*c*x^2)^(3/2))) - x/(3*c*Sqrt[c - a^2*c*x^2])}
{E^(2*ArcCoth[a*x])/(c - a^2*c*x^2)^(5/2), x, 6, -((2*(1 + a*x))/(5*a*(c - a^2*c*x^2)^(5/2))) - x/(5*c*(c - a^2*c*x^2)^(3/2)) - (2*x)/(5*c^2*Sqrt[c - a^2*c*x^2])}
{E^(2*ArcCoth[a*x])/(c - a^2*c*x^2)^(7/2), x, 7, -((2*(1 + a*x))/(7*a*(c - a^2*c*x^2)^(7/2))) - x/(7*c*(c - a^2*c*x^2)^(5/2)) - (4*x)/(21*c^2*(c - a^2*c*x^2)^(3/2)) - (8*x)/(21*c^3*Sqrt[c - a^2*c*x^2])}
{E^(2*ArcCoth[a*x])/(c - a^2*c*x^2)^(9/2), x, 8, -((2*(1 + a*x))/(9*a*(c - a^2*c*x^2)^(9/2))) - x/(9*c*(c - a^2*c*x^2)^(7/2)) - (2*x)/(15*c^2*(c - a^2*c*x^2)^(5/2)) - (8*x)/(45*c^3*(c - a^2*c*x^2)^(3/2)) - (16*x)/(45*c^4*Sqrt[c - a^2*c*x^2])}


{E^(3*ArcCoth[a*x])*(c - a^2*c*x^2)^(9/2), x, 4, -((8*(1 + a*x)^7*(c - a^2*c*x^2)^(9/2))/(7*a^10*(1 - 1/(a^2*x^2))^(9/2)*x^9)) + (3*(1 + a*x)^8*(c - a^2*c*x^2)^(9/2))/(2*a^10*(1 - 1/(a^2*x^2))^(9/2)*x^9) - (2*(1 + a*x)^9*(c - a^2*c*x^2)^(9/2))/(3*a^10*(1 - 1/(a^2*x^2))^(9/2)*x^9) + ((1 + a*x)^10*(c - a^2*c*x^2)^(9/2))/(10*a^10*(1 - 1/(a^2*x^2))^(9/2)*x^9)}
{E^(3*ArcCoth[a*x])*(c - a^2*c*x^2)^(7/2), x, 4, (2*(1 + a*x)^6*(c - a^2*c*x^2)^(7/2))/(3*a^8*(1 - 1/(a^2*x^2))^(7/2)*x^7) - (4*(1 + a*x)^7*(c - a^2*c*x^2)^(7/2))/(7*a^8*(1 - 1/(a^2*x^2))^(7/2)*x^7) + ((1 + a*x)^8*(c - a^2*c*x^2)^(7/2))/(8*a^8*(1 - 1/(a^2*x^2))^(7/2)*x^7)}
{E^(3*ArcCoth[a*x])*(c - a^2*c*x^2)^(5/2), x, 4, -((2*(1 + a*x)^5*(c - a^2*c*x^2)^(5/2))/(5*a^6*(1 - 1/(a^2*x^2))^(5/2)*x^5)) + ((1 + a*x)^6*(c - a^2*c*x^2)^(5/2))/(6*a^6*(1 - 1/(a^2*x^2))^(5/2)*x^5)}
{E^(3*ArcCoth[a*x])*(c - a^2*c*x^2)^(3/2), x, 3, ((1 + a*x)^4*(c - a^2*c*x^2)^(3/2))/(4*a^4*(1 - 1/(a^2*x^2))^(3/2)*x^3)}
{E^(3*ArcCoth[a*x])*Sqrt[c - a^2*c*x^2], x, 4, (3*Sqrt[c - a^2*c*x^2])/(a*Sqrt[1 - 1/(a^2*x^2)]) + (x*Sqrt[c - a^2*c*x^2])/(2*Sqrt[1 - 1/(a^2*x^2)]) + (4*Sqrt[c - a^2*c*x^2]*Log[1 - a*x])/(a^2*Sqrt[1 - 1/(a^2*x^2)]*x)}
{E^(3*ArcCoth[a*x])/Sqrt[c - a^2*c*x^2], x, 4, (2*Sqrt[1 - 1/(a^2*x^2)]*x)/((1 - a*x)*Sqrt[c - a^2*c*x^2]) + (Sqrt[1 - 1/(a^2*x^2)]*x*Log[1 - a*x])/Sqrt[c - a^2*c*x^2]}
{E^(3*ArcCoth[a*x])/(c - a^2*c*x^2)^(3/2), x, 3, -((a^2*(1 - 1/(a^2*x^2))^(3/2)*x^3)/(2*(1 - a*x)^2*(c - a^2*c*x^2)^(3/2)))}
{E^(3*ArcCoth[a*x])/(c - a^2*c*x^2)^(5/2), x, 5, (a^4*(1 - 1/(a^2*x^2))^(5/2)*x^5)/(6*(1 - a*x)^3*(c - a^2*c*x^2)^(5/2)) + (a^4*(1 - 1/(a^2*x^2))^(5/2)*x^5)/(8*(1 - a*x)^2*(c - a^2*c*x^2)^(5/2)) + (a^4*(1 - 1/(a^2*x^2))^(5/2)*x^5)/(8*(1 - a*x)*(c - a^2*c*x^2)^(5/2)) + (a^4*(1 - 1/(a^2*x^2))^(5/2)*x^5*ArcTanh[a*x])/(8*(c - a^2*c*x^2)^(5/2))}
{E^(3*ArcCoth[a*x])/(c - a^2*c*x^2)^(7/2), x, 5, -((a^6*(1 - 1/(a^2*x^2))^(7/2)*x^7)/(16*(1 - a*x)^4*(c - a^2*c*x^2)^(7/2))) - (a^6*(1 - 1/(a^2*x^2))^(7/2)*x^7)/(12*(1 - a*x)^3*(c - a^2*c*x^2)^(7/2)) - (3*a^6*(1 - 1/(a^2*x^2))^(7/2)*x^7)/(32*(1 - a*x)^2*(c - a^2*c*x^2)^(7/2)) - (a^6*(1 - 1/(a^2*x^2))^(7/2)*x^7)/(8*(1 - a*x)*(c - a^2*c*x^2)^(7/2)) + (a^6*(1 - 1/(a^2*x^2))^(7/2)*x^7)/(32*(1 + a*x)*(c - a^2*c*x^2)^(7/2)) - (5*a^6*(1 - 1/(a^2*x^2))^(7/2)*x^7*ArcTanh[a*x])/(32*(c - a^2*c*x^2)^(7/2))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(c - a^2*c*x^2)^(9/2)/E^ArcCoth[a*x], x, 4, (8*(1 - a*x)^6*(c - a^2*c*x^2)^(9/2))/(3*a^10*(1 - 1/(a^2*x^2))^(9/2)*x^9) - (32*(1 - a*x)^7*(c - a^2*c*x^2)^(9/2))/(7*a^10*(1 - 1/(a^2*x^2))^(9/2)*x^9) + (3*(1 - a*x)^8*(c - a^2*c*x^2)^(9/2))/(a^10*(1 - 1/(a^2*x^2))^(9/2)*x^9) - (8*(1 - a*x)^9*(c - a^2*c*x^2)^(9/2))/(9*a^10*(1 - 1/(a^2*x^2))^(9/2)*x^9) + ((1 - a*x)^10*(c - a^2*c*x^2)^(9/2))/(10*a^10*(1 - 1/(a^2*x^2))^(9/2)*x^9)}
{(c - a^2*c*x^2)^(7/2)/E^ArcCoth[a*x], x, 4, -((8*(1 - a*x)^5*(c - a^2*c*x^2)^(7/2))/(5*a^8*(1 - 1/(a^2*x^2))^(7/2)*x^7)) + (2*(1 - a*x)^6*(c - a^2*c*x^2)^(7/2))/(a^8*(1 - 1/(a^2*x^2))^(7/2)*x^7) - (6*(1 - a*x)^7*(c - a^2*c*x^2)^(7/2))/(7*a^8*(1 - 1/(a^2*x^2))^(7/2)*x^7) + ((1 - a*x)^8*(c - a^2*c*x^2)^(7/2))/(8*a^8*(1 - 1/(a^2*x^2))^(7/2)*x^7)}
{(c - a^2*c*x^2)^(5/2)/E^ArcCoth[a*x], x, 4, ((1 - a*x)^4*(c - a^2*c*x^2)^(5/2))/(a^6*(1 - 1/(a^2*x^2))^(5/2)*x^5) - (4*(1 - a*x)^5*(c - a^2*c*x^2)^(5/2))/(5*a^6*(1 - 1/(a^2*x^2))^(5/2)*x^5) + ((1 - a*x)^6*(c - a^2*c*x^2)^(5/2))/(6*a^6*(1 - 1/(a^2*x^2))^(5/2)*x^5)}
{(c - a^2*c*x^2)^(3/2)/E^ArcCoth[a*x], x, 4, -((2*(1 - a*x)^3*(c - a^2*c*x^2)^(3/2))/(3*a^4*(1 - 1/(a^2*x^2))^(3/2)*x^3)) + ((1 - a*x)^4*(c - a^2*c*x^2)^(3/2))/(4*a^4*(1 - 1/(a^2*x^2))^(3/2)*x^3)}
{Sqrt[c - a^2*c*x^2]/E^ArcCoth[a*x], x, 3, -(Sqrt[c - a^2*c*x^2]/(a*Sqrt[1 - 1/(a^2*x^2)])) + (x*Sqrt[c - a^2*c*x^2])/(2*Sqrt[1 - 1/(a^2*x^2)])}
{1/(E^ArcCoth[a*x]*Sqrt[c - a^2*c*x^2]), x, 3, (Sqrt[1 - 1/(a^2*x^2)]*x*Log[1 + a*x])/Sqrt[c - a^2*c*x^2]}
{1/(E^ArcCoth[a*x]*(c - a^2*c*x^2)^(3/2)), x, 5, (a^2*(1 - 1/(a^2*x^2))^(3/2)*x^3)/(2*(1 + a*x)*(c - a^2*c*x^2)^(3/2)) - (a^2*(1 - 1/(a^2*x^2))^(3/2)*x^3*ArcTanh[a*x])/(2*(c - a^2*c*x^2)^(3/2))}
{1/(E^ArcCoth[a*x]*(c - a^2*c*x^2)^(5/2)), x, 5, (a^4*(1 - 1/(a^2*x^2))^(5/2)*x^5)/(8*(1 - a*x)*(c - a^2*c*x^2)^(5/2)) - (a^4*(1 - 1/(a^2*x^2))^(5/2)*x^5)/(8*(1 + a*x)^2*(c - a^2*c*x^2)^(5/2)) - (a^4*(1 - 1/(a^2*x^2))^(5/2)*x^5)/(4*(1 + a*x)*(c - a^2*c*x^2)^(5/2)) + (3*a^4*(1 - 1/(a^2*x^2))^(5/2)*x^5*ArcTanh[a*x])/(8*(c - a^2*c*x^2)^(5/2))}
{1/(E^ArcCoth[a*x]*(c - a^2*c*x^2)^(7/2)), x, 5, -((a^6*(1 - 1/(a^2*x^2))^(7/2)*x^7)/(32*(1 - a*x)^2*(c - a^2*c*x^2)^(7/2))) - (a^6*(1 - 1/(a^2*x^2))^(7/2)*x^7)/(8*(1 - a*x)*(c - a^2*c*x^2)^(7/2)) + (a^6*(1 - 1/(a^2*x^2))^(7/2)*x^7)/(24*(1 + a*x)^3*(c - a^2*c*x^2)^(7/2)) + (3*a^6*(1 - 1/(a^2*x^2))^(7/2)*x^7)/(32*(1 + a*x)^2*(c - a^2*c*x^2)^(7/2)) + (3*a^6*(1 - 1/(a^2*x^2))^(7/2)*x^7)/(16*(1 + a*x)*(c - a^2*c*x^2)^(7/2)) - (5*a^6*(1 - 1/(a^2*x^2))^(7/2)*x^7*ArcTanh[a*x])/(16*(c - a^2*c*x^2)^(7/2))}


{(c - a^2*c*x^2)^(5/2)/E^(2*ArcCoth[a*x]), x, 7, (-(7/16))*c^2*x*Sqrt[c - a^2*c*x^2] - (7/24)*c*x*(c - a^2*c*x^2)^(3/2) - (7/30)*x*(c - a^2*c*x^2)^(5/2) - (2*(c - a^2*c*x^2)^(7/2))/(5*a*c*(1 + a*x)) - (7*c^(5/2)*ArcTan[(a*Sqrt[c]*x)/Sqrt[c - a^2*c*x^2]])/(16*a)}
{(c - a^2*c*x^2)^(3/2)/E^(2*ArcCoth[a*x]), x, 6, (-(5/8))*c*x*Sqrt[c - a^2*c*x^2] - (5/12)*x*(c - a^2*c*x^2)^(3/2) - (2*(c - a^2*c*x^2)^(5/2))/(3*a*c*(1 + a*x)) - (5*c^(3/2)*ArcTan[(a*Sqrt[c]*x)/Sqrt[c - a^2*c*x^2]])/(8*a)}
{Sqrt[c - a^2*c*x^2]/E^(2*ArcCoth[a*x]), x, 5, (-(3/2))*x*Sqrt[c - a^2*c*x^2] - (2*(c - a^2*c*x^2)^(3/2))/(a*c*(1 + a*x)) - (3*Sqrt[c]*ArcTan[(a*Sqrt[c]*x)/Sqrt[c - a^2*c*x^2]])/(2*a)}
{1/(E^(2*ArcCoth[a*x])*Sqrt[c - a^2*c*x^2]), x, 4, (2*Sqrt[c - a^2*c*x^2])/(a*c*(1 + a*x)) + ArcTan[(a*Sqrt[c]*x)/Sqrt[c - a^2*c*x^2]]/(a*Sqrt[c])}
{1/(E^(2*ArcCoth[a*x])*(c - a^2*c*x^2)^(3/2)), x, 4, Sqrt[c - a^2*c*x^2]/(3*a*c^2*(1 + a*x)^2) + Sqrt[c - a^2*c*x^2]/(3*a*c^2*(1 + a*x))}
{1/(E^(2*ArcCoth[a*x])*(c - a^2*c*x^2)^(5/2)), x, 5, -((2*x)/(5*c^2*Sqrt[c - a^2*c*x^2])) + 1/(5*a*c^2*(1 + a*x)^2*Sqrt[c - a^2*c*x^2]) + 1/(5*a*c^2*(1 + a*x)*Sqrt[c - a^2*c*x^2])}
{1/(E^(2*ArcCoth[a*x])*(c - a^2*c*x^2)^(7/2)), x, 6, -((4*x)/(21*c^2*(c - a^2*c*x^2)^(3/2))) + 1/(7*a*c^2*(1 + a*x)^2*(c - a^2*c*x^2)^(3/2)) + 1/(7*a*c^2*(1 + a*x)*(c - a^2*c*x^2)^(3/2)) - (8*x)/(21*c^3*Sqrt[c - a^2*c*x^2])}
{1/(E^(2*ArcCoth[a*x])*(c - a^2*c*x^2)^(9/2)), x, 7, -((2*x)/(15*c^2*(c - a^2*c*x^2)^(5/2))) + 1/(9*a*c^2*(1 + a*x)^2*(c - a^2*c*x^2)^(5/2)) + 1/(9*a*c^2*(1 + a*x)*(c - a^2*c*x^2)^(5/2)) - (8*x)/(45*c^3*(c - a^2*c*x^2)^(3/2)) - (16*x)/(45*c^4*Sqrt[c - a^2*c*x^2])}


{(c - a^2*c*x^2)^(9/2)/E^(3*ArcCoth[a*x]), x, 4, -((8*(1 - a*x)^7*(c - a^2*c*x^2)^(9/2))/(7*a^10*(1 - 1/(a^2*x^2))^(9/2)*x^9)) + (3*(1 - a*x)^8*(c - a^2*c*x^2)^(9/2))/(2*a^10*(1 - 1/(a^2*x^2))^(9/2)*x^9) - (2*(1 - a*x)^9*(c - a^2*c*x^2)^(9/2))/(3*a^10*(1 - 1/(a^2*x^2))^(9/2)*x^9) + ((1 - a*x)^10*(c - a^2*c*x^2)^(9/2))/(10*a^10*(1 - 1/(a^2*x^2))^(9/2)*x^9)}
{(c - a^2*c*x^2)^(7/2)/E^(3*ArcCoth[a*x]), x, 4, (2*(1 - a*x)^6*(c - a^2*c*x^2)^(7/2))/(3*a^8*(1 - 1/(a^2*x^2))^(7/2)*x^7) - (4*(1 - a*x)^7*(c - a^2*c*x^2)^(7/2))/(7*a^8*(1 - 1/(a^2*x^2))^(7/2)*x^7) + ((1 - a*x)^8*(c - a^2*c*x^2)^(7/2))/(8*a^8*(1 - 1/(a^2*x^2))^(7/2)*x^7)}
{(c - a^2*c*x^2)^(5/2)/E^(3*ArcCoth[a*x]), x, 4, -((2*(1 - a*x)^5*(c - a^2*c*x^2)^(5/2))/(5*a^6*(1 - 1/(a^2*x^2))^(5/2)*x^5)) + ((1 - a*x)^6*(c - a^2*c*x^2)^(5/2))/(6*a^6*(1 - 1/(a^2*x^2))^(5/2)*x^5)}
{(c - a^2*c*x^2)^(3/2)/E^(3*ArcCoth[a*x]), x, 3, ((1 - a*x)^4*(c - a^2*c*x^2)^(3/2))/(4*a^4*(1 - 1/(a^2*x^2))^(3/2)*x^3)}
{Sqrt[c - a^2*c*x^2]/E^(3*ArcCoth[a*x]), x, 4, (-3*Sqrt[c - a^2*c*x^2])/(a*Sqrt[1 - 1/(a^2*x^2)]) + (x*Sqrt[c - a^2*c*x^2])/(2*Sqrt[1 - 1/(a^2*x^2)]) + (4*Sqrt[c - a^2*c*x^2]*Log[1 + a*x])/(a^2*Sqrt[1 - 1/(a^2*x^2)]*x)}
{1/(E^(3*ArcCoth[a*x])*Sqrt[c - a^2*c*x^2]), x, 4, (2*Sqrt[1 - 1/(a^2*x^2)]*x)/((1 + a*x)*Sqrt[c - a^2*c*x^2]) + (Sqrt[1 - 1/(a^2*x^2)]*x*Log[1 + a*x])/Sqrt[c - a^2*c*x^2]}
{1/(E^(3*ArcCoth[a*x])*(c - a^2*c*x^2)^(3/2)), x, 3, -((a^2*(1 - 1/(a^2*x^2))^(3/2)*x^3)/(2*(1 + a*x)^2*(c - a^2*c*x^2)^(3/2)))}
{1/(E^(3*ArcCoth[a*x])*(c - a^2*c*x^2)^(5/2)), x, 5, (a^4*(1 - 1/(a^2*x^2))^(5/2)*x^5)/(6*(1 + a*x)^3*(c - a^2*c*x^2)^(5/2)) + (a^4*(1 - 1/(a^2*x^2))^(5/2)*x^5)/(8*(1 + a*x)^2*(c - a^2*c*x^2)^(5/2)) + (a^4*(1 - 1/(a^2*x^2))^(5/2)*x^5)/(8*(1 + a*x)*(c - a^2*c*x^2)^(5/2)) - (a^4*(1 - 1/(a^2*x^2))^(5/2)*x^5*ArcTanh[a*x])/(8*(c - a^2*c*x^2)^(5/2))}
{1/(E^(3*ArcCoth[a*x])*(c - a^2*c*x^2)^(7/2)), x, 5, (a^6*(1 - 1/(a^2*x^2))^(7/2)*x^7)/(32*(1 - a*x)*(c - a^2*c*x^2)^(7/2)) - (a^6*(1 - 1/(a^2*x^2))^(7/2)*x^7)/(16*(1 + a*x)^4*(c - a^2*c*x^2)^(7/2)) - (a^6*(1 - 1/(a^2*x^2))^(7/2)*x^7)/(12*(1 + a*x)^3*(c - a^2*c*x^2)^(7/2)) - (3*a^6*(1 - 1/(a^2*x^2))^(7/2)*x^7)/(32*(1 + a*x)^2*(c - a^2*c*x^2)^(7/2)) - (a^6*(1 - 1/(a^2*x^2))^(7/2)*x^7)/(8*(1 + a*x)*(c - a^2*c*x^2)^(7/2)) + (5*a^6*(1 - 1/(a^2*x^2))^(7/2)*x^7*ArcTanh[a*x])/(32*(c - a^2*c*x^2)^(7/2))}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{E^(n*ArcCoth[a*x])*(c - a^2*c*x^2)^(3/2), x, 3, (2^((5 + n)/2)*(1 - (a - 1/x)/(2*a))^((1/2)*(-5 + n))*(1 - 1/(a*x))^((5 - n)/2)*(c - a^2*c*x^2)^(3/2)*Hypergeometric2F1[5, (5 - n)/2, (7 - n)/2, (2 - (a - 1/x)/a - 2/(a*x))/(2 - (a - 1/x)/a)])/(a^4*(5 - n)*(1 - 1/(a^2*x^2))^(3/2)*x^3)}
{E^(n*ArcCoth[a*x])*Sqrt[c - a^2*c*x^2], x, 3, (2^((3 + n)/2)*(1 - (a - 1/x)/(2*a))^((1/2)*(-3 + n))*(1 - 1/(a*x))^((3 - n)/2)*Sqrt[c - a^2*c*x^2]*Hypergeometric2F1[3, (3 - n)/2, (5 - n)/2, (2 - (a - 1/x)/a - 2/(a*x))/(2 - (a - 1/x)/a)])/(a^2*(3 - n)*Sqrt[1 - 1/(a^2*x^2)]*x)}
{E^(n*ArcCoth[a*x])/Sqrt[c - a^2*c*x^2], x, 3, (2^((1 + n)/2)*(1 - (a - 1/x)/(2*a))^((1/2)*(-1 + n))*Sqrt[1 - 1/(a^2*x^2)]*(1 - 1/(a*x))^((1 - n)/2)*x*Hypergeometric2F1[1, (1 - n)/2, (3 - n)/2, (2 - (a - 1/x)/a - 2/(a*x))/(2 - (a - 1/x)/a)])/((1 - n)*Sqrt[c - a^2*c*x^2])}
{E^(n*ArcCoth[a*x])/(c - a^2*c*x^2)^(3/2), x, 1, -((E^(n*ArcCoth[a*x])*(n - a*x))/(a*c*(1 - n^2)*Sqrt[c - a^2*c*x^2]))}
{E^(n*ArcCoth[a*x])/(c - a^2*c*x^2)^(5/2), x, 2, -((E^(n*ArcCoth[a*x])*(n - 3*a*x))/(a*c*(9 - n^2)*(c - a^2*c*x^2)^(3/2))) - (6*E^(n*ArcCoth[a*x])*(n - a*x))/(a*c^2*(1 - n^2)*(9 - n^2)*Sqrt[c - a^2*c*x^2])}
{E^(n*ArcCoth[a*x])/(c - a^2*c*x^2)^(7/2), x, 3, -((E^(n*ArcCoth[a*x])*(n - 5*a*x))/(a*c*(25 - n^2)*(c - a^2*c*x^2)^(5/2))) - (20*E^(n*ArcCoth[a*x])*(n - 3*a*x))/(a*c^2*(9 - n^2)*(25 - n^2)*(c - a^2*c*x^2)^(3/2)) - (120*E^(n*ArcCoth[a*x])*(n - a*x))/(a*c^3*(1 - n^2)*(9 - n^2)*(25 - n^2)*Sqrt[c - a^2*c*x^2])}
{E^(n*ArcCoth[a*x])/(c - a^2*c*x^2)^(9/2), x, 4, -((E^(n*ArcCoth[a*x])*(n - 7*a*x))/(a*c*(49 - n^2)*(c - a^2*c*x^2)^(7/2))) - (42*E^(n*ArcCoth[a*x])*(n - 5*a*x))/(a*c^2*(25 - n^2)*(49 - n^2)*(c - a^2*c*x^2)^(5/2)) - (840*E^(n*ArcCoth[a*x])*(n - 3*a*x))/(a*c^3*(9 - n^2)*(25 - n^2)*(49 - n^2)*(c - a^2*c*x^2)^(3/2)) - (5040*E^(n*ArcCoth[a*x])*(n - a*x))/(a*c^4*(1 - n^2)*(9 - n^2)*(25 - n^2)*(49 - n^2)*Sqrt[c - a^2*c*x^2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(n ArcCoth[a x]) (c-c a^2 x^2)^(p/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{E^ArcCoth[a*x]*x^m*Sqrt[c - a^2*c*x^2], x, 4, (x^m*Sqrt[c - a^2*c*x^2])/(a*(1 + m)*Sqrt[1 - 1/(a^2*x^2)]) + (x^(1 + m)*Sqrt[c - a^2*c*x^2])/((2 + m)*Sqrt[1 - 1/(a^2*x^2)])}

{E^ArcCoth[a*x]*x^2*Sqrt[c - a^2*c*x^2], x, 4, (x^2*Sqrt[c - a^2*c*x^2])/(3*a*Sqrt[1 - 1/(a^2*x^2)]) + (x^3*Sqrt[c - a^2*c*x^2])/(4*Sqrt[1 - 1/(a^2*x^2)])}
{E^ArcCoth[a*x]*x*Sqrt[c - a^2*c*x^2], x, 4, (x*Sqrt[c - a^2*c*x^2])/(2*a*Sqrt[1 - 1/(a^2*x^2)]) + (x^2*Sqrt[c - a^2*c*x^2])/(3*Sqrt[1 - 1/(a^2*x^2)])}
{E^ArcCoth[a*x]*Sqrt[c - a^2*c*x^2], x, 3, Sqrt[c - a^2*c*x^2]/(a*Sqrt[1 - 1/(a^2*x^2)]) + (x*Sqrt[c - a^2*c*x^2])/(2*Sqrt[1 - 1/(a^2*x^2)])}
{(E^ArcCoth[a*x]*Sqrt[c - a^2*c*x^2])/x, x, 4, Sqrt[c - a^2*c*x^2]/Sqrt[1 - 1/(a^2*x^2)] + (Sqrt[c - a^2*c*x^2]*Log[x])/(a*Sqrt[1 - 1/(a^2*x^2)]*x)}
{(E^ArcCoth[a*x]*Sqrt[c - a^2*c*x^2])/x^2, x, 4, -(Sqrt[c - a^2*c*x^2]/(a*Sqrt[1 - 1/(a^2*x^2)]*x^2)) + (Sqrt[c - a^2*c*x^2]*Log[x])/(Sqrt[1 - 1/(a^2*x^2)]*x)}


{E^(2*ArcCoth[a*x])*x^m*Sqrt[c - a^2*c*x^2], x, 3, -((x^(1 + m)*Sqrt[c - a^2*c*x^2]*AppellF1[1 + m, 1/2, -(3/2), 2 + m, a*x, (-a)*x])/((1 + m)*Sqrt[1 - a*x]*Sqrt[1 + a*x]))}

{E^(2*ArcCoth[a*x])*x^3*Sqrt[c - a^2*c*x^2], x, 8, (3*Sqrt[c - a^2*c*x^2])/(4*a^4) + (9*(1 + a*x)*Sqrt[c - a^2*c*x^2])/(20*a^4) + (3*x*(1 + a*x)*Sqrt[c - a^2*c*x^2])/(10*a^3) + (3*x^2*(1 + a*x)*Sqrt[c - a^2*c*x^2])/(10*a^2) + (x^3*(1 + a*x)*Sqrt[c - a^2*c*x^2])/(5*a) - (3*Sqrt[c - a^2*c*x^2]*ArcSin[a*x])/(4*a^4*Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{E^(2*ArcCoth[a*x])*x^2*Sqrt[c - a^2*c*x^2], x, 7, (7*Sqrt[c - a^2*c*x^2])/(8*a^3) + (7*(1 + a*x)*Sqrt[c - a^2*c*x^2])/(24*a^3) + ((1 + a*x)^2*Sqrt[c - a^2*c*x^2])/(6*a^3) + (x*(1 + a*x)^2*Sqrt[c - a^2*c*x^2])/(4*a^2) - (7*Sqrt[c - a^2*c*x^2]*ArcSin[a*x])/(8*a^3*Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{E^(2*ArcCoth[a*x])*x*Sqrt[c - a^2*c*x^2], x, 6, Sqrt[c - a^2*c*x^2]/a^2 + ((1 + a*x)*Sqrt[c - a^2*c*x^2])/(3*a^2) + ((1 + a*x)^2*Sqrt[c - a^2*c*x^2])/(3*a^2) - (Sqrt[c]*ArcTan[(a*Sqrt[c]*x)/Sqrt[c - a^2*c*x^2]])/a^2}
{E^(2*ArcCoth[a*x])*Sqrt[c - a^2*c*x^2], x, 5, (3*Sqrt[c - a^2*c*x^2])/(2*a) + ((1 + a*x)*Sqrt[c - a^2*c*x^2])/(2*a) - (3*Sqrt[c]*ArcTan[(a*Sqrt[c]*x)/Sqrt[c - a^2*c*x^2]])/(2*a)}
{(E^(2*ArcCoth[a*x])*Sqrt[c - a^2*c*x^2])/x, x, 6, Sqrt[c - a^2*c*x^2] - (2*Sqrt[c - a^2*c*x^2]*ArcSin[a*x])/(Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (2*Sqrt[c - a^2*c*x^2]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{(E^(2*ArcCoth[a*x])*Sqrt[c - a^2*c*x^2])/x^2, x, 7, (-a)*Sqrt[c - a^2*c*x^2] + ((1 + a*x)*Sqrt[c - a^2*c*x^2])/x - (a*Sqrt[c - a^2*c*x^2]*ArcSin[a*x])/(Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (4*a*Sqrt[c - a^2*c*x^2]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{(E^(2*ArcCoth[a*x])*Sqrt[c - a^2*c*x^2])/x^3, x, 5, (3*a*Sqrt[c - a^2*c*x^2])/(2*x) + ((1 + a*x)*Sqrt[c - a^2*c*x^2])/(2*x^2) + (3*a^2*Sqrt[c - a^2*c*x^2]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{(E^(2*ArcCoth[a*x])*Sqrt[c - a^2*c*x^2])/x^4, x, 7, (2*a*Sqrt[c - a^2*c*x^2])/(3*x^2) + (5*a^2*Sqrt[c - a^2*c*x^2])/(3*x) + ((1 + a*x)*Sqrt[c - a^2*c*x^2])/(3*x^3) + (2*a^3*Sqrt[c - a^2*c*x^2]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{(E^(2*ArcCoth[a*x])*Sqrt[c - a^2*c*x^2])/x^5, x, 8, (5*a*Sqrt[c - a^2*c*x^2])/(12*x^3) + (7*a^2*Sqrt[c - a^2*c*x^2])/(8*x^2) + (4*a^3*Sqrt[c - a^2*c*x^2])/(3*x) + ((1 + a*x)*Sqrt[c - a^2*c*x^2])/(4*x^4) + (7*a^4*Sqrt[c - a^2*c*x^2]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(4*Sqrt[1 - a*x]*Sqrt[1 + a*x])}


{E^(3*ArcCoth[a*x])*x^m*Sqrt[c - a^2*c*x^2], x, 5, ((5 + 2*m)*x^m*Sqrt[c - a^2*c*x^2])/(a*(1 + m)*(2 + m)*Sqrt[1 - 1/(a^2*x^2)]) + (x^m*(1 + a*x)*Sqrt[c - a^2*c*x^2])/(a*(2 + m)*Sqrt[1 - 1/(a^2*x^2)]) - (4*x^m*Sqrt[c - a^2*c*x^2]*Hypergeometric2F1[1, 1 + m, 2 + m, a*x])/(a*(1 + m)*Sqrt[1 - 1/(a^2*x^2)])}

{E^(3*ArcCoth[a*x])*x^3*Sqrt[c - a^2*c*x^2], x, 4, (4*Sqrt[c - a^2*c*x^2])/(a^4*Sqrt[1 - 1/(a^2*x^2)]) + (2*x*Sqrt[c - a^2*c*x^2])/(a^3*Sqrt[1 - 1/(a^2*x^2)]) + (4*x^2*Sqrt[c - a^2*c*x^2])/(3*a^2*Sqrt[1 - 1/(a^2*x^2)]) + (3*x^3*Sqrt[c - a^2*c*x^2])/(4*a*Sqrt[1 - 1/(a^2*x^2)]) + (x^4*Sqrt[c - a^2*c*x^2])/(5*Sqrt[1 - 1/(a^2*x^2)]) + (4*Sqrt[c - a^2*c*x^2]*Log[1 - a*x])/(a^5*Sqrt[1 - 1/(a^2*x^2)]*x)}
{E^(3*ArcCoth[a*x])*x^2*Sqrt[c - a^2*c*x^2], x, 4, (4*Sqrt[c - a^2*c*x^2])/(a^3*Sqrt[1 - 1/(a^2*x^2)]) + (2*x*Sqrt[c - a^2*c*x^2])/(a^2*Sqrt[1 - 1/(a^2*x^2)]) + (x^2*Sqrt[c - a^2*c*x^2])/(a*Sqrt[1 - 1/(a^2*x^2)]) + (x^3*Sqrt[c - a^2*c*x^2])/(4*Sqrt[1 - 1/(a^2*x^2)]) + (4*Sqrt[c - a^2*c*x^2]*Log[1 - a*x])/(a^4*Sqrt[1 - 1/(a^2*x^2)]*x)}
{E^(3*ArcCoth[a*x])*x*Sqrt[c - a^2*c*x^2], x, 4, (4*Sqrt[c - a^2*c*x^2])/(a^2*Sqrt[1 - 1/(a^2*x^2)]) + (3*x*Sqrt[c - a^2*c*x^2])/(2*a*Sqrt[1 - 1/(a^2*x^2)]) + (x^2*Sqrt[c - a^2*c*x^2])/(3*Sqrt[1 - 1/(a^2*x^2)]) + (4*Sqrt[c - a^2*c*x^2]*Log[1 - a*x])/(a^3*Sqrt[1 - 1/(a^2*x^2)]*x)}
{E^(3*ArcCoth[a*x])*Sqrt[c - a^2*c*x^2], x, 4, (3*Sqrt[c - a^2*c*x^2])/(a*Sqrt[1 - 1/(a^2*x^2)]) + (x*Sqrt[c - a^2*c*x^2])/(2*Sqrt[1 - 1/(a^2*x^2)]) + (4*Sqrt[c - a^2*c*x^2]*Log[1 - a*x])/(a^2*Sqrt[1 - 1/(a^2*x^2)]*x)}
{(E^(3*ArcCoth[a*x])*Sqrt[c - a^2*c*x^2])/x, x, 4, Sqrt[c - a^2*c*x^2]/Sqrt[1 - 1/(a^2*x^2)] - (Sqrt[c - a^2*c*x^2]*Log[x])/(a*Sqrt[1 - 1/(a^2*x^2)]*x) + (4*Sqrt[c - a^2*c*x^2]*Log[1 - a*x])/(a*Sqrt[1 - 1/(a^2*x^2)]*x)}
{(E^(3*ArcCoth[a*x])*Sqrt[c - a^2*c*x^2])/x^2, x, 4, Sqrt[c - a^2*c*x^2]/(a*Sqrt[1 - 1/(a^2*x^2)]*x^2) - (3*Sqrt[c - a^2*c*x^2]*Log[x])/(Sqrt[1 - 1/(a^2*x^2)]*x) + (4*Sqrt[c - a^2*c*x^2]*Log[1 - a*x])/(Sqrt[1 - 1/(a^2*x^2)]*x)}
{(E^(3*ArcCoth[a*x])*Sqrt[c - a^2*c*x^2])/x^3, x, 4, Sqrt[c - a^2*c*x^2]/(2*a*Sqrt[1 - 1/(a^2*x^2)]*x^3) + (3*Sqrt[c - a^2*c*x^2])/(Sqrt[1 - 1/(a^2*x^2)]*x^2) - (4*a*Sqrt[c - a^2*c*x^2]*Log[x])/(Sqrt[1 - 1/(a^2*x^2)]*x) + (4*a*Sqrt[c - a^2*c*x^2]*Log[1 - a*x])/(Sqrt[1 - 1/(a^2*x^2)]*x)}
{(E^(3*ArcCoth[a*x])*Sqrt[c - a^2*c*x^2])/x^4, x, 4, Sqrt[c - a^2*c*x^2]/(3*a*Sqrt[1 - 1/(a^2*x^2)]*x^4) + (3*Sqrt[c - a^2*c*x^2])/(2*Sqrt[1 - 1/(a^2*x^2)]*x^3) + (4*a*Sqrt[c - a^2*c*x^2])/(Sqrt[1 - 1/(a^2*x^2)]*x^2) - (4*a^2*Sqrt[c - a^2*c*x^2]*Log[x])/(Sqrt[1 - 1/(a^2*x^2)]*x) + (4*a^2*Sqrt[c - a^2*c*x^2]*Log[1 - a*x])/(Sqrt[1 - 1/(a^2*x^2)]*x)}
{(E^(3*ArcCoth[a*x])*Sqrt[c - a^2*c*x^2])/x^5, x, 4, Sqrt[c - a^2*c*x^2]/(4*a*Sqrt[1 - 1/(a^2*x^2)]*x^5) + Sqrt[c - a^2*c*x^2]/(Sqrt[1 - 1/(a^2*x^2)]*x^4) + (2*a*Sqrt[c - a^2*c*x^2])/(Sqrt[1 - 1/(a^2*x^2)]*x^3) + (4*a^2*Sqrt[c - a^2*c*x^2])/(Sqrt[1 - 1/(a^2*x^2)]*x^2) - (4*a^3*Sqrt[c - a^2*c*x^2]*Log[x])/(Sqrt[1 - 1/(a^2*x^2)]*x) + (4*a^3*Sqrt[c - a^2*c*x^2]*Log[1 - a*x])/(Sqrt[1 - 1/(a^2*x^2)]*x)}


{E^ArcCoth[a*x]/(c - a^2*c*x^2)^(3/2)*x^4, x, 4, ((1 - 1/(a^2*x^2))^(3/2)*x^4)/(a*(c - a^2*c*x^2)^(3/2)) + ((1 - 1/(a^2*x^2))^(3/2)*x^5)/(2*(c - a^2*c*x^2)^(3/2)) + ((1 - 1/(a^2*x^2))^(3/2)*x^3)/(2*a^2*(1 - a*x)*(c - a^2*c*x^2)^(3/2)) + (7*(1 - 1/(a^2*x^2))^(3/2)*x^3*Log[1 - a*x])/(4*a^2*(c - a^2*c*x^2)^(3/2)) + ((1 - 1/(a^2*x^2))^(3/2)*x^3*Log[1 + a*x])/(4*a^2*(c - a^2*c*x^2)^(3/2))}
{E^ArcCoth[a*x]/(c - a^2*c*x^2)^(3/2)*x^3, x, 4, ((1 - 1/(a^2*x^2))^(3/2)*x^4)/(c - a^2*c*x^2)^(3/2) + ((1 - 1/(a^2*x^2))^(3/2)*x^3)/(2*a*(1 - a*x)*(c - a^2*c*x^2)^(3/2)) + (5*(1 - 1/(a^2*x^2))^(3/2)*x^3*Log[1 - a*x])/(4*a*(c - a^2*c*x^2)^(3/2)) - ((1 - 1/(a^2*x^2))^(3/2)*x^3*Log[1 + a*x])/(4*a*(c - a^2*c*x^2)^(3/2))}
{E^ArcCoth[a*x]/(c - a^2*c*x^2)^(3/2)*x^2, x, 4, ((1 - 1/(a^2*x^2))^(3/2)*x^3)/(2*(1 - a*x)*(c - a^2*c*x^2)^(3/2)) + (3*(1 - 1/(a^2*x^2))^(3/2)*x^3*Log[1 - a*x])/(4*(c - a^2*c*x^2)^(3/2)) + ((1 - 1/(a^2*x^2))^(3/2)*x^3*Log[1 + a*x])/(4*(c - a^2*c*x^2)^(3/2))}
{E^ArcCoth[a*x]/(c - a^2*c*x^2)^(3/2)*x^1, x, 5, (a*(1 - 1/(a^2*x^2))^(3/2)*x^3)/(2*(1 - a*x)*(c - a^2*c*x^2)^(3/2)) - (a*(1 - 1/(a^2*x^2))^(3/2)*x^3*ArcTanh[a*x])/(2*(c - a^2*c*x^2)^(3/2))}
{E^ArcCoth[a*x]/(c - a^2*c*x^2)^(3/2)*x^0, x, 5, (a^2*(1 - 1/(a^2*x^2))^(3/2)*x^3)/(2*(1 - a*x)*(c - a^2*c*x^2)^(3/2)) + (a^2*(1 - 1/(a^2*x^2))^(3/2)*x^3*ArcTanh[a*x])/(2*(c - a^2*c*x^2)^(3/2))}
{E^ArcCoth[a*x]/(c - a^2*c*x^2)^(3/2)/x^1, x, 4, (a^3*(1 - 1/(a^2*x^2))^(3/2)*x^3)/(2*(1 - a*x)*(c - a^2*c*x^2)^(3/2)) + (a^3*(1 - 1/(a^2*x^2))^(3/2)*x^3*Log[x])/(c - a^2*c*x^2)^(3/2) - (3*a^3*(1 - 1/(a^2*x^2))^(3/2)*x^3*Log[1 - a*x])/(4*(c - a^2*c*x^2)^(3/2)) - (a^3*(1 - 1/(a^2*x^2))^(3/2)*x^3*Log[1 + a*x])/(4*(c - a^2*c*x^2)^(3/2))}
{E^ArcCoth[a*x]/(c - a^2*c*x^2)^(3/2)/x^2, x, 4, -((a^3*(1 - 1/(a^2*x^2))^(3/2)*x^2)/(c - a^2*c*x^2)^(3/2)) + (a^4*(1 - 1/(a^2*x^2))^(3/2)*x^3)/(2*(1 - a*x)*(c - a^2*c*x^2)^(3/2)) + (a^4*(1 - 1/(a^2*x^2))^(3/2)*x^3*Log[x])/(c - a^2*c*x^2)^(3/2) - (5*a^4*(1 - 1/(a^2*x^2))^(3/2)*x^3*Log[1 - a*x])/(4*(c - a^2*c*x^2)^(3/2)) + (a^4*(1 - 1/(a^2*x^2))^(3/2)*x^3*Log[1 + a*x])/(4*(c - a^2*c*x^2)^(3/2))}
{E^ArcCoth[a*x]/(c - a^2*c*x^2)^(3/2)/x^3, x, 4, -((a^3*(1 - 1/(a^2*x^2))^(3/2)*x)/(2*(c - a^2*c*x^2)^(3/2))) - (a^4*(1 - 1/(a^2*x^2))^(3/2)*x^2)/(c - a^2*c*x^2)^(3/2) + (a^5*(1 - 1/(a^2*x^2))^(3/2)*x^3)/(2*(1 - a*x)*(c - a^2*c*x^2)^(3/2)) + (2*a^5*(1 - 1/(a^2*x^2))^(3/2)*x^3*Log[x])/(c - a^2*c*x^2)^(3/2) - (7*a^5*(1 - 1/(a^2*x^2))^(3/2)*x^3*Log[1 - a*x])/(4*(c - a^2*c*x^2)^(3/2)) - (a^5*(1 - 1/(a^2*x^2))^(3/2)*x^3*Log[1 + a*x])/(4*(c - a^2*c*x^2)^(3/2))}


{E^ArcCoth[a*x]/(c - a^2*c*x^2)^(5/2)*x^5, x, 4, ((1 - 1/(a^2*x^2))^(5/2)*x^6)/(c - a^2*c*x^2)^(5/2) - ((1 - 1/(a^2*x^2))^(5/2)*x^5)/(8*a*(1 - a*x)^2*(c - a^2*c*x^2)^(5/2)) + ((1 - 1/(a^2*x^2))^(5/2)*x^5)/(a*(1 - a*x)*(c - a^2*c*x^2)^(5/2)) - ((1 - 1/(a^2*x^2))^(5/2)*x^5)/(8*a*(1 + a*x)*(c - a^2*c*x^2)^(5/2)) + (23*(1 - 1/(a^2*x^2))^(5/2)*x^5*Log[1 - a*x])/(16*a*(c - a^2*c*x^2)^(5/2)) - (7*(1 - 1/(a^2*x^2))^(5/2)*x^5*Log[1 + a*x])/(16*a*(c - a^2*c*x^2)^(5/2))}
{E^ArcCoth[a*x]/(c - a^2*c*x^2)^(5/2)*x^4, x, 4, -(((1 - 1/(a^2*x^2))^(5/2)*x^5)/(8*(1 - a*x)^2*(c - a^2*c*x^2)^(5/2))) + (3*(1 - 1/(a^2*x^2))^(5/2)*x^5)/(4*(1 - a*x)*(c - a^2*c*x^2)^(5/2)) + ((1 - 1/(a^2*x^2))^(5/2)*x^5)/(8*(1 + a*x)*(c - a^2*c*x^2)^(5/2)) + (11*(1 - 1/(a^2*x^2))^(5/2)*x^5*Log[1 - a*x])/(16*(c - a^2*c*x^2)^(5/2)) + (5*(1 - 1/(a^2*x^2))^(5/2)*x^5*Log[1 + a*x])/(16*(c - a^2*c*x^2)^(5/2))}
{E^ArcCoth[a*x]/(c - a^2*c*x^2)^(5/2)*x^3, x, 5, -((a*(1 - 1/(a^2*x^2))^(5/2)*x^5)/(8*(1 - a*x)^2*(c - a^2*c*x^2)^(5/2))) + (a*(1 - 1/(a^2*x^2))^(5/2)*x^5)/(2*(1 - a*x)*(c - a^2*c*x^2)^(5/2)) - (a*(1 - 1/(a^2*x^2))^(5/2)*x^5)/(8*(1 + a*x)*(c - a^2*c*x^2)^(5/2)) - (3*a*(1 - 1/(a^2*x^2))^(5/2)*x^5*ArcTanh[a*x])/(8*(c - a^2*c*x^2)^(5/2))}
{E^ArcCoth[a*x]/(c - a^2*c*x^2)^(5/2)*x^2, x, 5, -((a^2*(1 - 1/(a^2*x^2))^(5/2)*x^5)/(8*(1 - a*x)^2*(c - a^2*c*x^2)^(5/2))) + (a^2*(1 - 1/(a^2*x^2))^(5/2)*x^5)/(4*(1 - a*x)*(c - a^2*c*x^2)^(5/2)) + (a^2*(1 - 1/(a^2*x^2))^(5/2)*x^5)/(8*(1 + a*x)*(c - a^2*c*x^2)^(5/2)) + (a^2*(1 - 1/(a^2*x^2))^(5/2)*x^5*ArcTanh[a*x])/(8*(c - a^2*c*x^2)^(5/2))}
{E^ArcCoth[a*x]/(c - a^2*c*x^2)^(5/2)*x^1, x, 5, -((a^3*(1 - 1/(a^2*x^2))^(5/2)*x^5)/(8*(1 - a*x)^2*(c - a^2*c*x^2)^(5/2))) - (a^3*(1 - 1/(a^2*x^2))^(5/2)*x^5)/(8*(1 + a*x)*(c - a^2*c*x^2)^(5/2)) + (a^3*(1 - 1/(a^2*x^2))^(5/2)*x^5*ArcTanh[a*x])/(8*(c - a^2*c*x^2)^(5/2))}
{E^ArcCoth[a*x]/(c - a^2*c*x^2)^(5/2)*x^0, x, 5, -((a^4*(1 - 1/(a^2*x^2))^(5/2)*x^5)/(8*(1 - a*x)^2*(c - a^2*c*x^2)^(5/2))) - (a^4*(1 - 1/(a^2*x^2))^(5/2)*x^5)/(4*(1 - a*x)*(c - a^2*c*x^2)^(5/2)) + (a^4*(1 - 1/(a^2*x^2))^(5/2)*x^5)/(8*(1 + a*x)*(c - a^2*c*x^2)^(5/2)) - (3*a^4*(1 - 1/(a^2*x^2))^(5/2)*x^5*ArcTanh[a*x])/(8*(c - a^2*c*x^2)^(5/2))}
{E^ArcCoth[a*x]/(c - a^2*c*x^2)^(5/2)/x^1, x, 4, -((a^5*(1 - 1/(a^2*x^2))^(5/2)*x^5)/(8*(1 - a*x)^2*(c - a^2*c*x^2)^(5/2))) - (a^5*(1 - 1/(a^2*x^2))^(5/2)*x^5)/(2*(1 - a*x)*(c - a^2*c*x^2)^(5/2)) - (a^5*(1 - 1/(a^2*x^2))^(5/2)*x^5)/(8*(1 + a*x)*(c - a^2*c*x^2)^(5/2)) - (a^5*(1 - 1/(a^2*x^2))^(5/2)*x^5*Log[x])/(c - a^2*c*x^2)^(5/2) + (11*a^5*(1 - 1/(a^2*x^2))^(5/2)*x^5*Log[1 - a*x])/(16*(c - a^2*c*x^2)^(5/2)) + (5*a^5*(1 - 1/(a^2*x^2))^(5/2)*x^5*Log[1 + a*x])/(16*(c - a^2*c*x^2)^(5/2))}
{E^ArcCoth[a*x]/(c - a^2*c*x^2)^(5/2)/x^2, x, 4, (a^5*(1 - 1/(a^2*x^2))^(5/2)*x^4)/(c - a^2*c*x^2)^(5/2) - (a^6*(1 - 1/(a^2*x^2))^(5/2)*x^5)/(8*(1 - a*x)^2*(c - a^2*c*x^2)^(5/2)) - (3*a^6*(1 - 1/(a^2*x^2))^(5/2)*x^5)/(4*(1 - a*x)*(c - a^2*c*x^2)^(5/2)) + (a^6*(1 - 1/(a^2*x^2))^(5/2)*x^5)/(8*(1 + a*x)*(c - a^2*c*x^2)^(5/2)) - (a^6*(1 - 1/(a^2*x^2))^(5/2)*x^5*Log[x])/(c - a^2*c*x^2)^(5/2) + (23*a^6*(1 - 1/(a^2*x^2))^(5/2)*x^5*Log[1 - a*x])/(16*(c - a^2*c*x^2)^(5/2)) - (7*a^6*(1 - 1/(a^2*x^2))^(5/2)*x^5*Log[1 + a*x])/(16*(c - a^2*c*x^2)^(5/2))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(x^m*Sqrt[c - a^2*c*x^2])/E^ArcCoth[a*x], x, 4, -((x^m*Sqrt[c - a^2*c*x^2])/(a*(1 + m)*Sqrt[1 - 1/(a^2*x^2)])) + (x^(1 + m)*Sqrt[c - a^2*c*x^2])/((2 + m)*Sqrt[1 - 1/(a^2*x^2)])}

{(x^2*Sqrt[c - a^2*c*x^2])/E^ArcCoth[a*x], x, 4, -(x^2*Sqrt[c - a^2*c*x^2])/(3*a*Sqrt[1 - 1/(a^2*x^2)]) + (x^3*Sqrt[c - a^2*c*x^2])/(4*Sqrt[1 - 1/(a^2*x^2)])}
{(x*Sqrt[c - a^2*c*x^2])/E^ArcCoth[a*x], x, 4, -(x*Sqrt[c - a^2*c*x^2])/(2*a*Sqrt[1 - 1/(a^2*x^2)]) + (x^2*Sqrt[c - a^2*c*x^2])/(3*Sqrt[1 - 1/(a^2*x^2)])}
{Sqrt[c - a^2*c*x^2]/E^ArcCoth[a*x], x, 3, -(Sqrt[c - a^2*c*x^2]/(a*Sqrt[1 - 1/(a^2*x^2)])) + (x*Sqrt[c - a^2*c*x^2])/(2*Sqrt[1 - 1/(a^2*x^2)])}
{Sqrt[c - a^2*c*x^2]/(E^ArcCoth[a*x]*x), x, 4, Sqrt[c - a^2*c*x^2]/Sqrt[1 - 1/(a^2*x^2)] - (Sqrt[c - a^2*c*x^2]*Log[x])/(a*Sqrt[1 - 1/(a^2*x^2)]*x)}
{Sqrt[c - a^2*c*x^2]/(E^ArcCoth[a*x]*x^2), x, 4, Sqrt[c - a^2*c*x^2]/(a*Sqrt[1 - 1/(a^2*x^2)]*x^2) + (Sqrt[c - a^2*c*x^2]*Log[x])/(Sqrt[1 - 1/(a^2*x^2)]*x)}


{(x^m*Sqrt[c - a^2*c*x^2])/E^(2*ArcCoth[a*x]), x, 3, -((x^(1 + m)*Sqrt[c - a^2*c*x^2]*AppellF1[1 + m, -(3/2), 1/2, 2 + m, a*x, (-a)*x])/((1 + m)*Sqrt[1 - a*x]*Sqrt[1 + a*x]))}

{(x^3*Sqrt[c - a^2*c*x^2])/E^(2*ArcCoth[a*x]), x, 8, (3*Sqrt[c - a^2*c*x^2])/(4*a^4) + (9*(1 - a*x)*Sqrt[c - a^2*c*x^2])/(20*a^4) - (3*x*(1 - a*x)*Sqrt[c - a^2*c*x^2])/(10*a^3) + (3*x^2*(1 - a*x)*Sqrt[c - a^2*c*x^2])/(10*a^2) - (x^3*(1 - a*x)*Sqrt[c - a^2*c*x^2])/(5*a) + (3*Sqrt[c - a^2*c*x^2]*ArcSin[a*x])/(4*a^4*Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{(x^2*Sqrt[c - a^2*c*x^2])/E^(2*ArcCoth[a*x]), x, 7, -((7*Sqrt[c - a^2*c*x^2])/(8*a^3)) - (7*(1 - a*x)*Sqrt[c - a^2*c*x^2])/(24*a^3) - ((1 - a*x)^2*Sqrt[c - a^2*c*x^2])/(6*a^3) + (x*(1 - a*x)^2*Sqrt[c - a^2*c*x^2])/(4*a^2) - (7*Sqrt[c - a^2*c*x^2]*ArcSin[a*x])/(8*a^3*Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{(x*Sqrt[c - a^2*c*x^2])/E^(2*ArcCoth[a*x]), x, 6, (x*Sqrt[c - a^2*c*x^2])/a + (2*(c - a^2*c*x^2)^(3/2))/(3*a^2*c) + (c - a^2*c*x^2)^(5/2)/(a^2*c^2*(1 + a*x)^2) + (Sqrt[c]*ArcTan[(a*Sqrt[c]*x)/Sqrt[c - a^2*c*x^2]])/a^2}
{Sqrt[c - a^2*c*x^2]/E^(2*ArcCoth[a*x]), x, 5, (-(3/2))*x*Sqrt[c - a^2*c*x^2] - (2*(c - a^2*c*x^2)^(3/2))/(a*c*(1 + a*x)) - (3*Sqrt[c]*ArcTan[(a*Sqrt[c]*x)/Sqrt[c - a^2*c*x^2]])/(2*a)}
{Sqrt[c - a^2*c*x^2]/(E^(2*ArcCoth[a*x])*x), x, 6, Sqrt[c - a^2*c*x^2] + (2*Sqrt[c - a^2*c*x^2]*ArcSin[a*x])/(Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (2*Sqrt[c - a^2*c*x^2]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{Sqrt[c - a^2*c*x^2]/(E^(2*ArcCoth[a*x])*x^2), x, 7, a*Sqrt[c - a^2*c*x^2] + ((1 - a*x)*Sqrt[c - a^2*c*x^2])/x - (a*Sqrt[c - a^2*c*x^2]*ArcSin[a*x])/(Sqrt[1 - a*x]*Sqrt[1 + a*x]) - (4*a*Sqrt[c - a^2*c*x^2]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{Sqrt[c - a^2*c*x^2]/(E^(2*ArcCoth[a*x])*x^3), x, 5, -((3*a*Sqrt[c - a^2*c*x^2])/(2*x)) + ((1 - a*x)*Sqrt[c - a^2*c*x^2])/(2*x^2) + (3*a^2*Sqrt[c - a^2*c*x^2]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{Sqrt[c - a^2*c*x^2]/(E^(2*ArcCoth[a*x])*x^4), x, 7, -((2*a*Sqrt[c - a^2*c*x^2])/(3*x^2)) + (5*a^2*Sqrt[c - a^2*c*x^2])/(3*x) + ((1 - a*x)*Sqrt[c - a^2*c*x^2])/(3*x^3) - (2*a^3*Sqrt[c - a^2*c*x^2]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{Sqrt[c - a^2*c*x^2]/(E^(2*ArcCoth[a*x])*x^5), x, 8, -((5*a*Sqrt[c - a^2*c*x^2])/(12*x^3)) + (7*a^2*Sqrt[c - a^2*c*x^2])/(8*x^2) - (4*a^3*Sqrt[c - a^2*c*x^2])/(3*x) + ((1 - a*x)*Sqrt[c - a^2*c*x^2])/(4*x^4) + (7*a^4*Sqrt[c - a^2*c*x^2]*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(4*Sqrt[1 - a*x]*Sqrt[1 + a*x])}


{(x^m*Sqrt[c - a^2*c*x^2])/E^(3*ArcCoth[a*x]), x, 5, -(((5 + 2*m)*x^m*Sqrt[c - a^2*c*x^2])/(a*(1 + m)*(2 + m)*Sqrt[1 - 1/(a^2*x^2)])) - (x^m*(1 - a*x)*Sqrt[c - a^2*c*x^2])/(a*(2 + m)*Sqrt[1 - 1/(a^2*x^2)]) + (4*x^m*Sqrt[c - a^2*c*x^2]*Hypergeometric2F1[1, 1 + m, 2 + m, (-a)*x])/(a*(1 + m)*Sqrt[1 - 1/(a^2*x^2)])}

{(x^3*Sqrt[c - a^2*c*x^2])/E^(3*ArcCoth[a*x]), x, 4, (4*Sqrt[c - a^2*c*x^2])/(a^4*Sqrt[1 - 1/(a^2*x^2)]) - (2*x*Sqrt[c - a^2*c*x^2])/(a^3*Sqrt[1 - 1/(a^2*x^2)]) + (4*x^2*Sqrt[c - a^2*c*x^2])/(3*a^2*Sqrt[1 - 1/(a^2*x^2)]) - (3*x^3*Sqrt[c - a^2*c*x^2])/(4*a*Sqrt[1 - 1/(a^2*x^2)]) + (x^4*Sqrt[c - a^2*c*x^2])/(5*Sqrt[1 - 1/(a^2*x^2)]) - (4*Sqrt[c - a^2*c*x^2]*Log[1 + a*x])/(a^5*Sqrt[1 - 1/(a^2*x^2)]*x)}
{(x^2*Sqrt[c - a^2*c*x^2])/E^(3*ArcCoth[a*x]), x, 4, (-4*Sqrt[c - a^2*c*x^2])/(a^3*Sqrt[1 - 1/(a^2*x^2)]) + (2*x*Sqrt[c - a^2*c*x^2])/(a^2*Sqrt[1 - 1/(a^2*x^2)]) - (x^2*Sqrt[c - a^2*c*x^2])/(a*Sqrt[1 - 1/(a^2*x^2)]) + (x^3*Sqrt[c - a^2*c*x^2])/(4*Sqrt[1 - 1/(a^2*x^2)]) + (4*Sqrt[c - a^2*c*x^2]*Log[1 + a*x])/(a^4*Sqrt[1 - 1/(a^2*x^2)]*x)}
{(x*Sqrt[c - a^2*c*x^2])/E^(3*ArcCoth[a*x]), x, 4, (4*Sqrt[c - a^2*c*x^2])/(a^2*Sqrt[1 - 1/(a^2*x^2)]) - (3*x*Sqrt[c - a^2*c*x^2])/(2*a*Sqrt[1 - 1/(a^2*x^2)]) + (x^2*Sqrt[c - a^2*c*x^2])/(3*Sqrt[1 - 1/(a^2*x^2)]) - (4*Sqrt[c - a^2*c*x^2]*Log[1 + a*x])/(a^3*Sqrt[1 - 1/(a^2*x^2)]*x)}
{Sqrt[c - a^2*c*x^2]/E^(3*ArcCoth[a*x]), x, 4, (-3*Sqrt[c - a^2*c*x^2])/(a*Sqrt[1 - 1/(a^2*x^2)]) + (x*Sqrt[c - a^2*c*x^2])/(2*Sqrt[1 - 1/(a^2*x^2)]) + (4*Sqrt[c - a^2*c*x^2]*Log[1 + a*x])/(a^2*Sqrt[1 - 1/(a^2*x^2)]*x)}
{Sqrt[c - a^2*c*x^2]/(E^(3*ArcCoth[a*x])*x), x, 4, Sqrt[c - a^2*c*x^2]/Sqrt[1 - 1/(a^2*x^2)] + (Sqrt[c - a^2*c*x^2]*Log[x])/(a*Sqrt[1 - 1/(a^2*x^2)]*x) - (4*Sqrt[c - a^2*c*x^2]*Log[1 + a*x])/(a*Sqrt[1 - 1/(a^2*x^2)]*x)}
{Sqrt[c - a^2*c*x^2]/(E^(3*ArcCoth[a*x])*x^2), x, 4, -(Sqrt[c - a^2*c*x^2]/(a*Sqrt[1 - 1/(a^2*x^2)]*x^2)) - (3*Sqrt[c - a^2*c*x^2]*Log[x])/(Sqrt[1 - 1/(a^2*x^2)]*x) + (4*Sqrt[c - a^2*c*x^2]*Log[1 + a*x])/(Sqrt[1 - 1/(a^2*x^2)]*x)}
{Sqrt[c - a^2*c*x^2]/(E^(3*ArcCoth[a*x])*x^3), x, 4, -(Sqrt[c - a^2*c*x^2]/(2*a*Sqrt[1 - 1/(a^2*x^2)]*x^3)) + (3*Sqrt[c - a^2*c*x^2])/(Sqrt[1 - 1/(a^2*x^2)]*x^2) + (4*a*Sqrt[c - a^2*c*x^2]*Log[x])/(Sqrt[1 - 1/(a^2*x^2)]*x) - (4*a*Sqrt[c - a^2*c*x^2]*Log[1 + a*x])/(Sqrt[1 - 1/(a^2*x^2)]*x)}
{Sqrt[c - a^2*c*x^2]/(E^(3*ArcCoth[a*x])*x^4), x, 4, -(Sqrt[c - a^2*c*x^2]/(3*a*Sqrt[1 - 1/(a^2*x^2)]*x^4)) + (3*Sqrt[c - a^2*c*x^2])/(2*Sqrt[1 - 1/(a^2*x^2)]*x^3) - (4*a*Sqrt[c - a^2*c*x^2])/(Sqrt[1 - 1/(a^2*x^2)]*x^2) - (4*a^2*Sqrt[c - a^2*c*x^2]*Log[x])/(Sqrt[1 - 1/(a^2*x^2)]*x) + (4*a^2*Sqrt[c - a^2*c*x^2]*Log[1 + a*x])/(Sqrt[1 - 1/(a^2*x^2)]*x)}
{Sqrt[c - a^2*c*x^2]/(E^(3*ArcCoth[a*x])*x^5), x, 4, -(Sqrt[c - a^2*c*x^2]/(4*a*Sqrt[1 - 1/(a^2*x^2)]*x^5)) + Sqrt[c - a^2*c*x^2]/(Sqrt[1 - 1/(a^2*x^2)]*x^4) - (2*a*Sqrt[c - a^2*c*x^2])/(Sqrt[1 - 1/(a^2*x^2)]*x^3) + (4*a^2*Sqrt[c - a^2*c*x^2])/(Sqrt[1 - 1/(a^2*x^2)]*x^2) + (4*a^3*Sqrt[c - a^2*c*x^2]*Log[x])/(Sqrt[1 - 1/(a^2*x^2)]*x) - (4*a^3*Sqrt[c - a^2*c*x^2]*Log[1 + a*x])/(Sqrt[1 - 1/(a^2*x^2)]*x)}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{E^(n*ArcCoth[a*x])/(c - a^2*c*x^2)^(3/2)*x^3, x, 3, -((2^(-(1/2) + n/2)*(1 - 1/(a^2*x^2))^(3/2)*(1 - 1/(a*x))^((1/2)*(-1 - n))*x^3*Defer[AppellF1][-(1/2) - n/2, 2, 3/2 - n/2, 1/2 - n/2, 1 - 1/(a*x), (1/2)*(1 - 1/(a*x))])/(a*(1 + n)*(c - a^2*c*x^2)^(3/2)))}
{E^(n*ArcCoth[a*x])/(c - a^2*c*x^2)^(3/2)*x^2, x, 4, -((E^(n*ArcCoth[a*x])*(n - a*x))/(a^3*c*(1 - n^2)*Sqrt[c - a^2*c*x^2])) - (2^((1 + n)/2)*(1 - (a - 1/x)/(2*a))^((1/2)*(-1 + n))*Sqrt[1 - 1/(a^2*x^2)]*(1 - 1/(a*x))^((1 - n)/2)*x*Hypergeometric2F1[1, (1 - n)/2, (3 - n)/2, (2 - (a - 1/x)/a - 2/(a*x))/(2 - (a - 1/x)/a)])/(a^2*c*(1 - n)*Sqrt[c - a^2*c*x^2])}
{E^(n*ArcCoth[a*x])/(c - a^2*c*x^2)^(3/2)*x^1, x, 1, (E^(n*ArcCoth[a*x])*(1 - a*n*x))/(a^2*c*(1 - n^2)*Sqrt[c - a^2*c*x^2])}
{E^(n*ArcCoth[a*x])/(c - a^2*c*x^2)^(3/2)*x^0, x, 1, -((E^(n*ArcCoth[a*x])*(n - a*x))/(a*c*(1 - n^2)*Sqrt[c - a^2*c*x^2]))}
{E^(n*ArcCoth[a*x])/(c - a^2*c*x^2)^(3/2)/x^1, x, 3, -(((1 - 1/(a^2*x^2))^(3/2)*AppellF1[3, (3 + n)/2, (3 - n)/2, 4, 1/(a*x), -(1/(a*x))])/(3*(c - a^2*c*x^2)^(3/2)))}


{E^(n*ArcCoth[a*x])/(c - a^2*c*x^2)^(5/2)*x^4, x, 3, -((2^((1/2)*(-3 + n))*(1 - 1/(a^2*x^2))^(5/2)*(1 - 1/(a*x))^((1/2)*(-3 - n))*x^5*Defer[AppellF1][-(3/2) - n/2, 1, 5/2 - n/2, -(1/2) - n/2, 1 - 1/(a*x), (1/2)*(1 - 1/(a*x))])/((3 + n)*(c - a^2*c*x^2)^(5/2)))}
{E^(n*ArcCoth[a*x])/(c - a^2*c*x^2)^(5/2)*x^3, x, 6, -((a*(1 - 1/(a^2*x^2))^(5/2)*(1 - 1/(a*x))^((1/2)*(-3 - n))*(1 + 1/(a*x))^((1/2)*(-3 + n))*x^5)/((3 + n)*(c - a^2*c*x^2)^(5/2))) - (3*a*(1 - 1/(a^2*x^2))^(5/2)*(1 - 1/(a*x))^((1/2)*(-1 - n))*(1 + 1/(a*x))^((1/2)*(-3 + n))*x^5)/((3 + 4*n + n^2)*(c - a^2*c*x^2)^(5/2)) + (6*a*(1 - 1/(a^2*x^2))^(5/2)*(1 - 1/(a*x))^((1 - n)/2)*(1 + 1/(a*x))^((1/2)*(-3 + n))*x^5)/((3 + n)*(1 - n^2)*(c - a^2*c*x^2)^(5/2)) - (6*a*(1 - 1/(a^2*x^2))^(5/2)*(1 - 1/(a*x))^((3 - n)/2)*(1 + 1/(a*x))^((1/2)*(-3 + n))*x^5)/((9 - 10*n^2 + n^4)*(c - a^2*c*x^2)^(5/2))}
{E^(n*ArcCoth[a*x])/(c - a^2*c*x^2)^(5/2)*x^2, x, 2, -((E^(n*ArcCoth[a*x])*(n - 3*a*x))/(a^3*c*(9 - n^2)*(c - a^2*c*x^2)^(3/2))) + (E^(n*ArcCoth[a*x])*(3 - n^2)*(n - a*x))/(a^3*c^2*(9 - 10*n^2 + n^4)*Sqrt[c - a^2*c*x^2])}
{E^(n*ArcCoth[a*x])/(c - a^2*c*x^2)^(5/2)*x^1, x, 2, (E^(n*ArcCoth[a*x])*(3 - a*n*x))/(a^2*c*(9 - n^2)*(c - a^2*c*x^2)^(3/2)) + (2*E^(n*ArcCoth[a*x])*n*(n - a*x))/(a^2*c^2*(9 - 10*n^2 + n^4)*Sqrt[c - a^2*c*x^2])}
{E^(n*ArcCoth[a*x])/(c - a^2*c*x^2)^(5/2)*x^0, x, 2, -((E^(n*ArcCoth[a*x])*(n - 3*a*x))/(a*c*(9 - n^2)*(c - a^2*c*x^2)^(3/2))) - (6*E^(n*ArcCoth[a*x])*(n - a*x))/(a*c^2*(1 - n^2)*(9 - n^2)*Sqrt[c - a^2*c*x^2])}
{E^(n*ArcCoth[a*x])/(c - a^2*c*x^2)^(5/2)/x^1, x, 3, -(((1 - 1/(a^2*x^2))^(5/2)*AppellF1[5, (5 + n)/2, (5 - n)/2, 6, 1/(a*x), -(1/(a*x))])/(5*(c - a^2*c*x^2)^(5/2)))}


(* ::Subsection::Closed:: *)
(*Integrands of the form E^(n ArcCoth[a x]) (c-c/(a^2 x^2))^p*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{E^ArcCoth[a*x]*(c - c/(a^2*x^2))^4, x, 12, -((51*c^4*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/(16*a)) - (67*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2))/(48*a) - (91*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(5/2))/(120*a) - (131*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(7/2))/(280*a) + (61*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(9/2))/(70*a) + (47*c^4*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(9/2))/(42*a) + (8*c^4*(1 - 1/(a*x))^(5/2)*(1 + 1/(a*x))^(9/2))/(7*a) + c^4*(1 - 1/(a*x))^(7/2)*(1 + 1/(a*x))^(9/2)*x + (35*c^4*ArcSin[1/(a*x)])/(16*a) + (2*c^4*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{E^ArcCoth[a*x]*(c - c/(a^2*x^2))^3, x, 10, -((23*c^3*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/(8*a)) - (31*c^3*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2))/(24*a) - (43*c^3*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(5/2))/(60*a) + (23*c^3*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(7/2))/(20*a) + (6*c^3*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(7/2))/(5*a) + c^3*(1 - 1/(a*x))^(5/2)*(1 + 1/(a*x))^(7/2)*x + (15*c^3*ArcSin[1/(a*x)])/(8*a) + (2*c^3*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{E^ArcCoth[a*x]*(c - c/(a^2*x^2))^2, x, 8, -((5*c^2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/(2*a)) - (7*c^2*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2))/(6*a) + (4*c^2*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(5/2))/(3*a) + c^2*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(5/2)*x + (3*c^2*ArcSin[1/(a*x)])/(2*a) + (2*c^2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{E^ArcCoth[a*x]*(c - c/(a^2*x^2)), x, 7, -((2*c*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/a) + c*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2)*x + (c*ArcSin[1/(a*x)])/a + (2*c*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{E^ArcCoth[a*x]/(c - c/(a^2*x^2)), x, 5, -((2*Sqrt[1 + 1/(a*x)])/(a*c*Sqrt[1 - 1/(a*x)])) + (Sqrt[1 + 1/(a*x)]*x)/(c*Sqrt[1 - 1/(a*x)]) + (2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(a*c)}
{E^ArcCoth[a*x]/(c - c/(a^2*x^2))^2, x, 7, -(4/(3*a*c^2*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)])) - 11/(3*a*c^2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]) + (8*Sqrt[1 - 1/(a*x)])/(3*a*c^2*Sqrt[1 + 1/(a*x)]) + x/(c^2*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)]) + (2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(a*c^2)}
{E^ArcCoth[a*x]/(c - c/(a^2*x^2))^3, x, 9, -(6/(5*a*c^3*(1 - 1/(a*x))^(5/2)*(1 + 1/(a*x))^(3/2))) - 29/(15*a*c^3*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(3/2)) - 34/(5*a*c^3*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2)) + (21*Sqrt[1 - 1/(a*x)])/(5*a*c^3*(1 + 1/(a*x))^(3/2)) + (16*Sqrt[1 - 1/(a*x)])/(5*a*c^3*Sqrt[1 + 1/(a*x)]) + x/(c^3*(1 - 1/(a*x))^(5/2)*(1 + 1/(a*x))^(3/2)) + (2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(a*c^3)}
{E^ArcCoth[a*x]/(c - c/(a^2*x^2))^4, x, 11, -(8/(7*a*c^4*(1 - 1/(a*x))^(7/2)*(1 + 1/(a*x))^(5/2))) - 11/(7*a*c^4*(1 - 1/(a*x))^(5/2)*(1 + 1/(a*x))^(5/2)) - 62/(21*a*c^4*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(5/2)) - 269/(21*a*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(5/2)) + (262*Sqrt[1 - 1/(a*x)])/(35*a*c^4*(1 + 1/(a*x))^(5/2)) + (163*Sqrt[1 - 1/(a*x)])/(35*a*c^4*(1 + 1/(a*x))^(3/2)) + (128*Sqrt[1 - 1/(a*x)])/(35*a*c^4*Sqrt[1 + 1/(a*x)]) + x/(c^4*(1 - 1/(a*x))^(7/2)*(1 + 1/(a*x))^(5/2)) + (2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(a*c^4)}


{E^(2*ArcCoth[a*x])*(c - c/(a^2*x^2))^5, x, 5, -(c^5/(9*a^10*x^9)) - c^5/(4*a^9*x^8) + (3*c^5)/(7*a^8*x^7) + (4*c^5)/(3*a^7*x^6) - (2*c^5)/(5*a^6*x^5) - (3*c^5)/(a^5*x^4) - (2*c^5)/(3*a^4*x^3) + (4*c^5)/(a^3*x^2) + (3*c^5)/(a^2*x) + c^5*x + (2*c^5*Log[x])/a}
{E^(2*ArcCoth[a*x])*(c - c/(a^2*x^2))^4, x, 5, c^4/(7*a^8*x^7) + c^4/(3*a^7*x^6) - (2*c^4)/(5*a^6*x^5) - (3*c^4)/(2*a^5*x^4) + (3*c^4)/(a^3*x^2) + (2*c^4)/(a^2*x) + c^4*x + (2*c^4*Log[x])/a}
{E^(2*ArcCoth[a*x])*(c - c/(a^2*x^2))^3, x, 5, -(c^3/(5*a^6*x^5)) - c^3/(2*a^5*x^4) + c^3/(3*a^4*x^3) + (2*c^3)/(a^3*x^2) + c^3/(a^2*x) + c^3*x + (2*c^3*Log[x])/a}
{E^(2*ArcCoth[a*x])*(c - c/(a^2*x^2))^2, x, 5, c^2/(3*a^4*x^3) + c^2/(a^3*x^2) + c^2*x + (2*c^2*Log[x])/a}
{E^(2*ArcCoth[a*x])*(c - c/(a^2*x^2)), x, 5, -(c/(a^2*x)) + c*x + (2*c*Log[x])/a}
{E^(2*ArcCoth[a*x])/(c - c/(a^2*x^2)), x, 5, x/c + 1/(a*c*(1 - a*x)) + (2*Log[1 - a*x])/(a*c)}
{E^(2*ArcCoth[a*x])/(c - c/(a^2*x^2))^2, x, 5, x/c^2 - 1/(4*a*c^2*(1 - a*x)^2) + 7/(4*a*c^2*(1 - a*x)) + (17*Log[1 - a*x])/(8*a*c^2) - Log[1 + a*x]/(8*a*c^2)}
{E^(2*ArcCoth[a*x])/(c - c/(a^2*x^2))^3, x, 5, x/c^3 + 1/(12*a*c^3*(1 - a*x)^3) - 5/(8*a*c^3*(1 - a*x)^2) + 39/(16*a*c^3*(1 - a*x)) - 1/(16*a*c^3*(1 + a*x)) + (9*Log[1 - a*x])/(4*a*c^3) - Log[1 + a*x]/(4*a*c^3)}
{E^(2*ArcCoth[a*x])/(c - c/(a^2*x^2))^4, x, 5, x/c^4 - 1/(32*a*c^4*(1 - a*x)^4) + 13/(48*a*c^4*(1 - a*x)^3) - 35/(32*a*c^4*(1 - a*x)^2) + 99/(32*a*c^4*(1 - a*x)) + 1/(64*a*c^4*(1 + a*x)^2) - 11/(64*a*c^4*(1 + a*x)) + (303*Log[1 - a*x])/(128*a*c^4) - (47*Log[1 + a*x])/(128*a*c^4)}


{E^(3*ArcCoth[a*x])*(c - c/(a^2*x^2))^4, x, 12, -((63*c^4*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/(16*a)) - (37*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2))/(16*a) - (61*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(5/2))/(40*a) - (303*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(7/2))/(280*a) - (57*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(9/2))/(70*a) + (15*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(11/2))/(14*a) + (8*c^4*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(11/2))/(7*a) + c^4*(1 - 1/(a*x))^(5/2)*(1 + 1/(a*x))^(11/2)*x + (15*c^4*ArcSin[1/(a*x)])/(16*a) + (6*c^4*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{E^(3*ArcCoth[a*x])*(c - c/(a^2*x^2))^3, x, 10, -((27*c^3*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/(8*a)) - (17*c^3*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2))/(8*a) - (29*c^3*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(5/2))/(20*a) - (21*c^3*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(7/2))/(20*a) + (6*c^3*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(9/2))/(5*a) + c^3*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(9/2)*x + (3*c^3*ArcSin[1/(a*x)])/(8*a) + (6*c^3*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{E^(3*ArcCoth[a*x])*(c - c/(a^2*x^2))^2, x, 8, -((5*c^2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/(2*a)) - (11*c^2*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2))/(6*a) - (4*c^2*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(5/2))/(3*a) + c^2*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(7/2)*x - (c^2*ArcSin[1/(a*x)])/(2*a) + (6*c^2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{E^(3*ArcCoth[a*x])*(c - c/(a^2*x^2)), x, 7, -((c*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2))/a) + c*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(5/2)*x - (3*c*ArcSin[1/(a*x)])/a + (6*c*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{E^(3*ArcCoth[a*x])/(c - c/(a^2*x^2)), x, 6, -((5*Sqrt[1 + 1/(a*x)])/(3*a*c*(1 - 1/(a*x))^(3/2))) - (14*Sqrt[1 + 1/(a*x)])/(3*a*c*Sqrt[1 - 1/(a*x)]) + (Sqrt[1 + 1/(a*x)]*x)/(c*(1 - 1/(a*x))^(3/2)) + (6*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(a*c)}
{E^(3*ArcCoth[a*x])/(c - c/(a^2*x^2))^2, x, 8, -((6*Sqrt[1 + 1/(a*x)])/(5*a*c^2*(1 - 1/(a*x))^(5/2))) - (9*Sqrt[1 + 1/(a*x)])/(5*a*c^2*(1 - 1/(a*x))^(3/2)) - (24*Sqrt[1 + 1/(a*x)])/(5*a*c^2*Sqrt[1 - 1/(a*x)]) + (Sqrt[1 + 1/(a*x)]*x)/(c^2*(1 - 1/(a*x))^(5/2)) + (6*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(a*c^2)}
{E^(3*ArcCoth[a*x])/(c - c/(a^2*x^2))^3, x, 9, -(8/(7*a*c^3*(1 - 1/(a*x))^(7/2)*Sqrt[1 + 1/(a*x)])) - 53/(35*a*c^3*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)]) - 88/(35*a*c^3*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)]) - 281/(35*a*c^3*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)]) + (176*Sqrt[1 - 1/(a*x)])/(35*a*c^3*Sqrt[1 + 1/(a*x)]) + x/(c^3*(1 - 1/(a*x))^(7/2)*Sqrt[1 + 1/(a*x)]) + (6*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(a*c^3)}
{E^(3*ArcCoth[a*x])/(c - c/(a^2*x^2))^4, x, 11, -(10/(9*a*c^4*(1 - 1/(a*x))^(9/2)*(1 + 1/(a*x))^(3/2))) - 29/(21*a*c^4*(1 - 1/(a*x))^(7/2)*(1 + 1/(a*x))^(3/2)) - 208/(105*a*c^4*(1 - 1/(a*x))^(5/2)*(1 + 1/(a*x))^(3/2)) - 1147/(315*a*c^4*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(3/2)) - 1462/(105*a*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2)) + (2609*Sqrt[1 - 1/(a*x)])/(315*a*c^4*(1 + 1/(a*x))^(3/2)) + (1664*Sqrt[1 - 1/(a*x)])/(315*a*c^4*Sqrt[1 + 1/(a*x)]) + x/(c^4*(1 - 1/(a*x))^(9/2)*(1 + 1/(a*x))^(3/2)) + (6*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(a*c^4)}


{E^(4*ArcCoth[a*x])*(c - c/(a^2*x^2))^5, x, 5, c^5/(9*a^10*x^9) + c^5/(2*a^9*x^8) + (3*c^5)/(7*a^8*x^7) - (4*c^5)/(3*a^7*x^6) - (14*c^5)/(5*a^6*x^5) + (14*c^5)/(3*a^4*x^3) + (4*c^5)/(a^3*x^2) - (3*c^5)/(a^2*x) + c^5*x + (4*c^5*Log[x])/a}
{E^(4*ArcCoth[a*x])*(c - c/(a^2*x^2))^4, x, 5, -(c^4/(7*a^8*x^7)) - (2*c^4)/(3*a^7*x^6) - (4*c^4)/(5*a^6*x^5) + c^4/(a^5*x^4) + (10*c^4)/(3*a^4*x^3) + (2*c^4)/(a^3*x^2) - (4*c^4)/(a^2*x) + c^4*x + (4*c^4*Log[x])/a}
{E^(4*ArcCoth[a*x])*(c - c/(a^2*x^2))^3, x, 5, c^3/(5*a^6*x^5) + c^3/(a^5*x^4) + (5*c^3)/(3*a^4*x^3) - (5*c^3)/(a^2*x) + c^3*x + (4*c^3*Log[x])/a}
{E^(4*ArcCoth[a*x])*(c - c/(a^2*x^2))^2, x, 5, -(c^2/(3*a^4*x^3)) - (2*c^2)/(a^3*x^2) - (6*c^2)/(a^2*x) + c^2*x + (4*c^2*Log[x])/a}
{E^(4*ArcCoth[a*x])*(c - c/(a^2*x^2)), x, 5, c/(a^2*x) + c*x - (4*c*Log[x])/a + (8*c*Log[1 - a*x])/a}
{E^(4*ArcCoth[a*x])/(c - c/(a^2*x^2)), x, 5, x/c - 1/(a*c*(1 - a*x)^2) + 5/(a*c*(1 - a*x)) + (4*Log[1 - a*x])/(a*c)}
{E^(4*ArcCoth[a*x])/(c - c/(a^2*x^2))^2, x, 5, x/c^2 + 1/(3*a*c^2*(1 - a*x)^3) - 2/(a*c^2*(1 - a*x)^2) + 6/(a*c^2*(1 - a*x)) + (4*Log[1 - a*x])/(a*c^2)}
{E^(4*ArcCoth[a*x])/(c - c/(a^2*x^2))^3, x, 5, x/c^3 - 1/(8*a*c^3*(1 - a*x)^4) + 11/(12*a*c^3*(1 - a*x)^3) - 49/(16*a*c^3*(1 - a*x)^2) + 111/(16*a*c^3*(1 - a*x)) + (129*Log[1 - a*x])/(32*a*c^3) - Log[1 + a*x]/(32*a*c^3)}
{E^(4*ArcCoth[a*x])/(c - c/(a^2*x^2))^4, x, 5, x/c^4 + 1/(20*a*c^4*(1 - a*x)^5) - 7/(16*a*c^4*(1 - a*x)^4) + 83/(48*a*c^4*(1 - a*x)^3) - 67/(16*a*c^4*(1 - a*x)^2) + 501/(64*a*c^4*(1 - a*x)) - 1/(64*a*c^4*(1 + a*x)) + (261*Log[1 - a*x])/(64*a*c^4) - (5*Log[1 + a*x])/(64*a*c^4)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(c - c/(a^2*x^2))^4/E^ArcCoth[a*x], x, 12, -((19*c^4*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/(16*a)) - (c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2))/(16*a) + (7*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(5/2))/(40*a) + (19*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(7/2))/(40*a) + (29*c^4*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(7/2))/(30*a) + (7*c^4*(1 - 1/(a*x))^(5/2)*(1 + 1/(a*x))^(7/2))/(6*a) + (8*c^4*(1 - 1/(a*x))^(7/2)*(1 + 1/(a*x))^(7/2))/(7*a) + c^4*(1 - 1/(a*x))^(9/2)*(1 + 1/(a*x))^(7/2)*x + (35*c^4*ArcSin[1/(a*x)])/(16*a) - (2*c^4*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{(c - c/(a^2*x^2))^3/E^ArcCoth[a*x], x, 10, -((7*c^3*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/(8*a)) + (c^3*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2))/(24*a) + (11*c^3*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(5/2))/(12*a) + (5*c^3*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(5/2))/(4*a) + (6*c^3*(1 - 1/(a*x))^(5/2)*(1 + 1/(a*x))^(5/2))/(5*a) + c^3*(1 - 1/(a*x))^(7/2)*(1 + 1/(a*x))^(5/2)*x + (15*c^3*ArcSin[1/(a*x)])/(8*a) - (2*c^3*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{(c - c/(a^2*x^2))^2/E^ArcCoth[a*x], x, 8, -((c^2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/(2*a)) + (3*c^2*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2))/(2*a) + (4*c^2*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(3/2))/(3*a) + c^2*(1 - 1/(a*x))^(5/2)*(1 + 1/(a*x))^(3/2)*x + (3*c^2*ArcSin[1/(a*x)])/(2*a) - (2*c^2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{(c - c/(a^2*x^2))/E^ArcCoth[a*x], x, 7, (2*c*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/a + c*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)]*x + (c*ArcSin[1/(a*x)])/a - (2*c*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{1/(E^ArcCoth[a*x]*(c - c/(a^2*x^2))), x, 5, (2*Sqrt[1 - 1/(a*x)])/(a*c*Sqrt[1 + 1/(a*x)]) + (Sqrt[1 - 1/(a*x)]*x)/(c*Sqrt[1 + 1/(a*x)]) - (2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(a*c)}
{1/(E^ArcCoth[a*x]*(c - c/(a^2*x^2))^2), x, 7, -(2/(a*c^2*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2))) + (5*Sqrt[1 - 1/(a*x)])/(3*a*c^2*(1 + 1/(a*x))^(3/2)) + (8*Sqrt[1 - 1/(a*x)])/(3*a*c^2*Sqrt[1 + 1/(a*x)]) + x/(c^2*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2)) - (2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(a*c^2)}
{1/(E^ArcCoth[a*x]*(c - c/(a^2*x^2))^3), x, 9, -(4/(3*a*c^3*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(5/2))) - 13/(3*a*c^3*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(5/2)) + (14*Sqrt[1 - 1/(a*x)])/(5*a*c^3*(1 + 1/(a*x))^(5/2)) + (11*Sqrt[1 - 1/(a*x)])/(5*a*c^3*(1 + 1/(a*x))^(3/2)) + (16*Sqrt[1 - 1/(a*x)])/(5*a*c^3*Sqrt[1 + 1/(a*x)]) + x/(c^3*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(5/2)) - (2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(a*c^3)}
{1/(E^ArcCoth[a*x]*(c - c/(a^2*x^2))^4), x, 11, -(6/(5*a*c^4*(1 - 1/(a*x))^(5/2)*(1 + 1/(a*x))^(7/2))) - 31/(15*a*c^4*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(7/2)) - 28/(3*a*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(7/2)) + (115*Sqrt[1 - 1/(a*x)])/(21*a*c^4*(1 + 1/(a*x))^(7/2)) + (122*Sqrt[1 - 1/(a*x)])/(35*a*c^4*(1 + 1/(a*x))^(5/2)) + (93*Sqrt[1 - 1/(a*x)])/(35*a*c^4*(1 + 1/(a*x))^(3/2)) + (128*Sqrt[1 - 1/(a*x)])/(35*a*c^4*Sqrt[1 + 1/(a*x)]) + x/(c^4*(1 - 1/(a*x))^(5/2)*(1 + 1/(a*x))^(7/2)) - (2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(a*c^4)}


{(c - c/(a^2*x^2))^4/E^(2*ArcCoth[a*x]), x, 5, c^4/(7*a^8*x^7) - c^4/(3*a^7*x^6) - (2*c^4)/(5*a^6*x^5) + (3*c^4)/(2*a^5*x^4) - (3*c^4)/(a^3*x^2) + (2*c^4)/(a^2*x) + c^4*x - (2*c^4*Log[x])/a}
{(c - c/(a^2*x^2))^3/E^(2*ArcCoth[a*x]), x, 5, -(c^3/(5*a^6*x^5)) + c^3/(2*a^5*x^4) + c^3/(3*a^4*x^3) - (2*c^3)/(a^3*x^2) + c^3/(a^2*x) + c^3*x - (2*c^3*Log[x])/a}
{(c - c/(a^2*x^2))^2/E^(2*ArcCoth[a*x]), x, 5, c^2/(3*a^4*x^3) - c^2/(a^3*x^2) + c^2*x - (2*c^2*Log[x])/a}
{(c - c/(a^2*x^2))/E^(2*ArcCoth[a*x]), x, 5, -(c/(a^2*x)) + c*x - (2*c*Log[x])/a}
{1/(E^(2*ArcCoth[a*x])*(c - c/(a^2*x^2))), x, 5, x/c - 1/(a*c*(1 + a*x)) - (2*Log[1 + a*x])/(a*c)}
{1/(E^(2*ArcCoth[a*x])*(c - c/(a^2*x^2))^2), x, 5, x/c^2 + 1/(4*a*c^2*(1 + a*x)^2) - 7/(4*a*c^2*(1 + a*x)) + Log[1 - a*x]/(8*a*c^2) - (17*Log[1 + a*x])/(8*a*c^2)}
{1/(E^(2*ArcCoth[a*x])*(c - c/(a^2*x^2))^3), x, 5, x/c^3 + 1/(16*a*c^3*(1 - a*x)) - 1/(12*a*c^3*(1 + a*x)^3) + 5/(8*a*c^3*(1 + a*x)^2) - 39/(16*a*c^3*(1 + a*x)) + Log[1 - a*x]/(4*a*c^3) - (9*Log[1 + a*x])/(4*a*c^3)}
{1/(E^(2*ArcCoth[a*x])*(c - c/(a^2*x^2))^4), x, 5, x/c^4 - 1/(64*a*c^4*(1 - a*x)^2) + 11/(64*a*c^4*(1 - a*x)) + 1/(32*a*c^4*(1 + a*x)^4) - 13/(48*a*c^4*(1 + a*x)^3) + 35/(32*a*c^4*(1 + a*x)^2) - 99/(32*a*c^4*(1 + a*x)) + (47*Log[1 - a*x])/(128*a*c^4) - (303*Log[1 + a*x])/(128*a*c^4)}


{(c - c/(a^2*x^2))^4/E^(3*ArcCoth[a*x]), x, 12, (33*c^4*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/(16*a) + (27*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2))/(16*a) - (3*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(5/2))/(8*a) + (5*c^4*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(5/2))/(8*a) + (11*c^4*(1 - 1/(a*x))^(5/2)*(1 + 1/(a*x))^(5/2))/(10*a) + (17*c^4*(1 - 1/(a*x))^(7/2)*(1 + 1/(a*x))^(5/2))/(14*a) + (8*c^4*(1 - 1/(a*x))^(9/2)*(1 + 1/(a*x))^(5/2))/(7*a) + c^4*(1 - 1/(a*x))^(11/2)*(1 + 1/(a*x))^(5/2)*x + (15*c^4*ArcSin[1/(a*x)])/(16*a) - (6*c^4*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{(c - c/(a^2*x^2))^3/E^(3*ArcCoth[a*x]), x, 10, (21*c^3*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/(8*a) + (3*c^3*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(3/2))/(8*a) + (5*c^3*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(3/2))/(4*a) + (27*c^3*(1 - 1/(a*x))^(5/2)*(1 + 1/(a*x))^(3/2))/(20*a) + (6*c^3*(1 - 1/(a*x))^(7/2)*(1 + 1/(a*x))^(3/2))/(5*a) + c^3*(1 - 1/(a*x))^(9/2)*(1 + 1/(a*x))^(3/2)*x + (3*c^3*ArcSin[1/(a*x)])/(8*a) - (6*c^3*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{(c - c/(a^2*x^2))^2/E^(3*ArcCoth[a*x]), x, 8, (5*c^2*Sqrt[1 - 1/(a*x)]*Sqrt[1 + 1/(a*x)])/(2*a) + (11*c^2*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)])/(6*a) + (4*c^2*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)])/(3*a) + c^2*(1 - 1/(a*x))^(7/2)*Sqrt[1 + 1/(a*x)]*x - (c^2*ArcSin[1/(a*x)])/(2*a) - (6*c^2*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{(c - c/(a^2*x^2))/E^(3*ArcCoth[a*x]), x, 7, (c*(1 - 1/(a*x))^(3/2)*Sqrt[1 + 1/(a*x)])/a + c*(1 - 1/(a*x))^(5/2)*Sqrt[1 + 1/(a*x)]*x - (3*c*ArcSin[1/(a*x)])/a - (6*c*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/a}
{1/(E^(3*ArcCoth[a*x])*(c - c/(a^2*x^2))), x, 6, (5*Sqrt[1 - 1/(a*x)])/(3*a*c*(1 + 1/(a*x))^(3/2)) + (14*Sqrt[1 - 1/(a*x)])/(3*a*c*Sqrt[1 + 1/(a*x)]) + (Sqrt[1 - 1/(a*x)]*x)/(c*(1 + 1/(a*x))^(3/2)) - (6*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(a*c)}
{1/(E^(3*ArcCoth[a*x])*(c - c/(a^2*x^2))^2), x, 8, (6*Sqrt[1 - 1/(a*x)])/(5*a*c^2*(1 + 1/(a*x))^(5/2)) + (9*Sqrt[1 - 1/(a*x)])/(5*a*c^2*(1 + 1/(a*x))^(3/2)) + (24*Sqrt[1 - 1/(a*x)])/(5*a*c^2*Sqrt[1 + 1/(a*x)]) + (Sqrt[1 - 1/(a*x)]*x)/(c^2*(1 + 1/(a*x))^(5/2)) - (6*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(a*c^2)}
{1/(E^(3*ArcCoth[a*x])*(c - c/(a^2*x^2))^3), x, 9, -(2/(a*c^3*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(7/2))) + (11*Sqrt[1 - 1/(a*x)])/(7*a*c^3*(1 + 1/(a*x))^(7/2)) + (54*Sqrt[1 - 1/(a*x)])/(35*a*c^3*(1 + 1/(a*x))^(5/2)) + (71*Sqrt[1 - 1/(a*x)])/(35*a*c^3*(1 + 1/(a*x))^(3/2)) + (176*Sqrt[1 - 1/(a*x)])/(35*a*c^3*Sqrt[1 + 1/(a*x)]) + x/(c^3*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(7/2)) - (6*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(a*c^3)}
{1/(E^(3*ArcCoth[a*x])*(c - c/(a^2*x^2))^4), x, 11, -(4/(3*a*c^4*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(9/2))) - 5/(a*c^4*Sqrt[1 - 1/(a*x)]*(1 + 1/(a*x))^(9/2)) + (28*Sqrt[1 - 1/(a*x)])/(9*a*c^4*(1 + 1/(a*x))^(9/2)) + (139*Sqrt[1 - 1/(a*x)])/(63*a*c^4*(1 + 1/(a*x))^(7/2)) + (202*Sqrt[1 - 1/(a*x)])/(105*a*c^4*(1 + 1/(a*x))^(5/2)) + (719*Sqrt[1 - 1/(a*x)])/(315*a*c^4*(1 + 1/(a*x))^(3/2)) + (1664*Sqrt[1 - 1/(a*x)])/(315*a*c^4*Sqrt[1 + 1/(a*x)]) + x/(c^4*(1 - 1/(a*x))^(3/2)*(1 + 1/(a*x))^(9/2)) - (6*ArcTanh[Sqrt[1 - 1/(a*x)]/Sqrt[1 + 1/(a*x)]])/(a*c^4)}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{(c - c/(a^2*x^2))^p/E^(2*p*ArcCoth[a*x]), x, 4, ((c - c/(a^2*x^2))^p*(1 - 1/(a*x))^(1 + 2*p)*x)/(1 - 1/(a^2*x^2))^p - (2*p*(c - c/(a^2*x^2))^p*(1 - 1/(a*x))^(1 + 2*p)*Hypergeometric2F1[1, 1 + 2*p, 2*(1 + p), 1 - 1/(a*x)])/((1 - 1/(a^2*x^2))^p*(a*(1 + 2*p)))}
{E^(2*p*ArcCoth[a*x])*(c - c/(a^2*x^2))^p, x, 4, ((c - c/(a^2*x^2))^p*(1 + 1/(a*x))^(1 + 2*p)*x)/(1 - 1/(a^2*x^2))^p + (2*p*(c - c/(a^2*x^2))^p*(1 + 1/(a*x))^(1 + 2*p)*Hypergeometric2F1[1, 1 + 2*p, 2*(1 + p), 1 + 1/(a*x)])/((1 - 1/(a^2*x^2))^p*(a*(1 + 2*p)))}


{E^(n*ArcCoth[a*x])*(c - c/(a^2*x^2))^p, x, 3, (2^(1 + n/2 + p)*(c - c/(a^2*x^2))^p*(1 - 1/(a*x))^(1 - n/2 + p)*AppellF1[1 - n/2 + p, 2, -(n/2) - p, 2 - n/2 + p, 1 - 1/(a*x), (a - 1/x)/(2*a)])/((1 - 1/(a^2*x^2))^p*(a*(2 - n + 2*p)))}

{E^(n*ArcCoth[a*x])*(c - c/(a^2*x^2)), x, 2, (2^(2 + n/2)*c*(1 - 1/(a*x))^(2 - n/2)*AppellF1[2 - n/2, 2, -1 - n/2, 3 - n/2, 1 - 1/(a*x), (a - 1/x)/(2*a)])/(a*(4 - n))}
{E^(n*ArcCoth[a*x]), x, 2, (2^(1 + n/2)*(1 - (a - 1/x)/(2*a))^((1/2)*(-2 + n))*(1 - 1/(a*x))^(1 - n/2)*Hypergeometric2F1[2, 1 - n/2, 2 - n/2, (2 - (a - 1/x)/a - 2/(a*x))/(2 - (a - 1/x)/a)])/(a*(2 - n))}
{E^(n*ArcCoth[a*x])/(c - c/(a^2*x^2)), x, 2, -((2^(n/2)*Defer[AppellF1][-(n/2), 2, 1 - n/2, 1 - n/2, 1 - 1/(a*x), (1/2)*(1 - 1/(a*x))])/((1 - 1/(a*x))^(n/2)*(a*c*n)))}
{E^(n*ArcCoth[a*x])/(c - c/(a^2*x^2))^2, x, 2, -((2^(-1 + n/2)*(1 - 1/(a*x))^(-1 - n/2)*Defer[AppellF1][-1 - n/2, 2, 2 - n/2, -(n/2), 1 - 1/(a*x), (1/2)*(1 - 1/(a*x))])/(a*c^2*(2 + n)))}


(* ::Subsection::Closed:: *)
(*Integrands of the form E^(n ArcCoth[a x]) (c-c/(a^2 x^2))^(p/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{E^ArcCoth[a*x]*(c - c/(a^2*x^2))^(7/2), x, 4, (c - c/(a^2*x^2))^(7/2)/(6*a^7*(1 - 1/(a^2*x^2))^(7/2)*x^6) + (c - c/(a^2*x^2))^(7/2)/(5*a^6*(1 - 1/(a^2*x^2))^(7/2)*x^5) - (3*(c - c/(a^2*x^2))^(7/2))/(4*a^5*(1 - 1/(a^2*x^2))^(7/2)*x^4) - (c - c/(a^2*x^2))^(7/2)/(a^4*(1 - 1/(a^2*x^2))^(7/2)*x^3) + (3*(c - c/(a^2*x^2))^(7/2))/(2*a^3*(1 - 1/(a^2*x^2))^(7/2)*x^2) + (3*(c - c/(a^2*x^2))^(7/2))/(a^2*(1 - 1/(a^2*x^2))^(7/2)*x) + ((c - c/(a^2*x^2))^(7/2)*x)/(1 - 1/(a^2*x^2))^(7/2) + ((c - c/(a^2*x^2))^(7/2)*Log[x])/(a*(1 - 1/(a^2*x^2))^(7/2))}
{E^ArcCoth[a*x]*(c - c/(a^2*x^2))^(5/2), x, 4, -(c - c/(a^2*x^2))^(5/2)/(4*a^5*(1 - 1/(a^2*x^2))^(5/2)*x^4) - (c - c/(a^2*x^2))^(5/2)/(3*a^4*(1 - 1/(a^2*x^2))^(5/2)*x^3) + (c - c/(a^2*x^2))^(5/2)/(a^3*(1 - 1/(a^2*x^2))^(5/2)*x^2) + (2*(c - c/(a^2*x^2))^(5/2))/(a^2*(1 - 1/(a^2*x^2))^(5/2)*x) + ((c - c/(a^2*x^2))^(5/2)*x)/(1 - 1/(a^2*x^2))^(5/2) + ((c - c/(a^2*x^2))^(5/2)*Log[x])/(a*(1 - 1/(a^2*x^2))^(5/2))}
{E^ArcCoth[a*x]*(c - c/(a^2*x^2))^(3/2), x, 4, (c - c/(a^2*x^2))^(3/2)/(2*a^3*(1 - 1/(a^2*x^2))^(3/2)*x^2) + (c - c/(a^2*x^2))^(3/2)/(a^2*(1 - 1/(a^2*x^2))^(3/2)*x) + ((c - c/(a^2*x^2))^(3/2)*x)/(1 - 1/(a^2*x^2))^(3/2) + ((c - c/(a^2*x^2))^(3/2)*Log[x])/(a*(1 - 1/(a^2*x^2))^(3/2))}
{E^ArcCoth[a*x]*Sqrt[c - c/(a^2*x^2)], x, 4, (Sqrt[c - c/(a^2*x^2)]*x)/Sqrt[1 - 1/(a^2*x^2)] + (Sqrt[c - c/(a^2*x^2)]*Log[x])/(a*Sqrt[1 - 1/(a^2*x^2)])}
{E^ArcCoth[a*x]/Sqrt[c - c/(a^2*x^2)], x, 4, (Sqrt[1 - 1/(a^2*x^2)]*x)/Sqrt[c - c/(a^2*x^2)] + (Sqrt[1 - 1/(a^2*x^2)]*Log[1 - a*x])/(a*Sqrt[c - c/(a^2*x^2)])}
{E^ArcCoth[a*x]/(c - c/(a^2*x^2))^(3/2), x, 4, ((1 - 1/(a^2*x^2))^(3/2)*x)/(c - c/(a^2*x^2))^(3/2) + (1 - 1/(a^2*x^2))^(3/2)/(2*a*(c - c/(a^2*x^2))^(3/2)*(1 - a*x)) + (5*(1 - 1/(a^2*x^2))^(3/2)*Log[1 - a*x])/(4*a*(c - c/(a^2*x^2))^(3/2)) - ((1 - 1/(a^2*x^2))^(3/2)*Log[1 + a*x])/(4*a*(c - c/(a^2*x^2))^(3/2))}
{E^ArcCoth[a*x]/(c - c/(a^2*x^2))^(5/2), x, 4, ((1 - 1/(a^2*x^2))^(5/2)*x)/(c - c/(a^2*x^2))^(5/2) - (1 - 1/(a^2*x^2))^(5/2)/(8*a*(c - c/(a^2*x^2))^(5/2)*(1 - a*x)^2) + (1 - 1/(a^2*x^2))^(5/2)/(a*(c - c/(a^2*x^2))^(5/2)*(1 - a*x)) - (1 - 1/(a^2*x^2))^(5/2)/(8*a*(c - c/(a^2*x^2))^(5/2)*(1 + a*x)) + (23*(1 - 1/(a^2*x^2))^(5/2)*Log[1 - a*x])/(16*a*(c - c/(a^2*x^2))^(5/2)) - (7*(1 - 1/(a^2*x^2))^(5/2)*Log[1 + a*x])/(16*a*(c - c/(a^2*x^2))^(5/2))}
{E^ArcCoth[a*x]/(c - c/(a^2*x^2))^(7/2), x, 4, ((1 - 1/(a^2*x^2))^(7/2)*x)/(c - c/(a^2*x^2))^(7/2) + (1 - 1/(a^2*x^2))^(7/2)/(24*a*(c - c/(a^2*x^2))^(7/2)*(1 - a*x)^3) - (11*(1 - 1/(a^2*x^2))^(7/2))/(32*a*(c - c/(a^2*x^2))^(7/2)*(1 - a*x)^2) + (3*(1 - 1/(a^2*x^2))^(7/2))/(2*a*(c - c/(a^2*x^2))^(7/2)*(1 - a*x)) + (1 - 1/(a^2*x^2))^(7/2)/(32*a*(c - c/(a^2*x^2))^(7/2)*(1 + a*x)^2) - (5*(1 - 1/(a^2*x^2))^(7/2))/(16*a*(c - c/(a^2*x^2))^(7/2)*(1 + a*x)) + (51*(1 - 1/(a^2*x^2))^(7/2)*Log[1 - a*x])/(32*a*(c - c/(a^2*x^2))^(7/2)) - (19*(1 - 1/(a^2*x^2))^(7/2)*Log[1 + a*x])/(32*a*(c - c/(a^2*x^2))^(7/2))}


{E^(2*ArcCoth[a*x])*(c - c/(a^2*x^2))^(7/2), x, 13, (11*a^3*(c - c/(a^2*x^2))^(7/2)*x^4)/(30*(1 - a*x)^3) - (57*a^6*(c - c/(a^2*x^2))^(7/2)*x^7)/(16*(1 - a*x)^3*(1 + a*x)^3) + (41*a^5*(c - c/(a^2*x^2))^(7/2)*x^6)/(24*(1 - a*x)^3*(1 + a*x)^2) + (57*a^4*(c - c/(a^2*x^2))^(7/2)*x^5)/(80*(1 - a*x)^3*(1 + a*x)) - (13*a^2*(c - c/(a^2*x^2))^(7/2)*x^3*(1 + a*x))/(40*(1 - a*x)^3) + (a*(c - c/(a^2*x^2))^(7/2)*x^2*(1 + a*x))/(15*(1 - a*x)^2) + ((c - c/(a^2*x^2))^(7/2)*x*(1 + a*x))/(6*(1 - a*x)) + (2*a^6*(c - c/(a^2*x^2))^(7/2)*x^7*ArcSin[a*x])/((1 - a*x)^(7/2)*(1 + a*x)^(7/2)) + (25*a^6*(c - c/(a^2*x^2))^(7/2)*x^7*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(8*(1 - a*x)^(7/2)*(1 + a*x)^(7/2))}
{E^(2*ArcCoth[a*x])*(c - c/(a^2*x^2))^(5/2), x, 11, -((5*a^2*(c - c/(a^2*x^2))^(5/2)*x^3)/(8*(1 - a*x)^2)) + (25*a^4*(c - c/(a^2*x^2))^(5/2)*x^5)/(8*(1 - a*x)^2*(1 + a*x)^2) - (17*a^3*(c - c/(a^2*x^2))^(5/2)*x^4)/(12*(1 - a*x)^2*(1 + a*x)) + (a*(c - c/(a^2*x^2))^(5/2)*x^2*(1 + a*x))/(6*(1 - a*x)^2) + ((c - c/(a^2*x^2))^(5/2)*x*(1 + a*x))/(4*(1 - a*x)) - (2*a^4*(c - c/(a^2*x^2))^(5/2)*x^5*ArcSin[a*x])/((1 - a*x)^(5/2)*(1 + a*x)^(5/2)) - (9*a^4*(c - c/(a^2*x^2))^(5/2)*x^5*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(4*(1 - a*x)^(5/2)*(1 + a*x)^(5/2))}
{E^(2*ArcCoth[a*x])*(c - c/(a^2*x^2))^(3/2), x, 9, (a*(c - c/(a^2*x^2))^(3/2)*x^2)/(1 - a*x) - (5*a^2*(c - c/(a^2*x^2))^(3/2)*x^3)/(2*(1 - a*x)*(1 + a*x)) + ((c - c/(a^2*x^2))^(3/2)*x*(1 + a*x))/(2*(1 - a*x)) + (2*a^2*(c - c/(a^2*x^2))^(3/2)*x^3*ArcSin[a*x])/((1 - a*x)^(3/2)*(1 + a*x)^(3/2)) + (a^2*(c - c/(a^2*x^2))^(3/2)*x^3*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/((1 - a*x)^(3/2)*(1 + a*x)^(3/2))}
{E^(2*ArcCoth[a*x])*Sqrt[c - c/(a^2*x^2)], x, 7, Sqrt[c - c/(a^2*x^2)]*x - (2*Sqrt[c - c/(a^2*x^2)]*x*ArcSin[a*x])/(Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (2*Sqrt[c - c/(a^2*x^2)]*x*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{E^(2*ArcCoth[a*x])/Sqrt[c - c/(a^2*x^2)], x, 6, -((2*(1 - a*x)*(1 + a*x))/(a^2*Sqrt[c - c/(a^2*x^2)]*x)) - (1 + a*x)^2/(a^2*Sqrt[c - c/(a^2*x^2)]*x) + (2*Sqrt[1 - a*x]*Sqrt[1 + a*x]*ArcSin[a*x])/(a^2*Sqrt[c - c/(a^2*x^2)]*x)}
{E^(2*ArcCoth[a*x])/(c - c/(a^2*x^2))^(3/2), x, 8, (1 + a*x)^2/(a^2*(c - c/(a^2*x^2))^(3/2)*x) + (4*(1 - a*x)*(1 + a*x)^2)/(a^4*(c - c/(a^2*x^2))^(3/2)*x^3) - (2*(1 + a*x)^3)/(3*a^4*(c - c/(a^2*x^2))^(3/2)*x^3) - (2*(1 - a*x)^(3/2)*(1 + a*x)^(3/2)*ArcSin[a*x])/(a^4*(c - c/(a^2*x^2))^(3/2)*x^3)}
{E^(2*ArcCoth[a*x])/(c - c/(a^2*x^2))^(5/2), x, 9, -((6*(1 + a*x)^2)/(5*a^3*(c - c/(a^2*x^2))^(5/2)*x^2)) + (1 + a*x)^2/(a^2*(c - c/(a^2*x^2))^(5/2)*x) + (28*(1 - a*x)*(1 + a*x)^2)/(15*a^4*(c - c/(a^2*x^2))^(5/2)*x^3) - (2*(1 - a*x)^2*(1 + a*x)^2*(28 + 15*a*x))/(15*a^6*(c - c/(a^2*x^2))^(5/2)*x^5) + (2*(1 - a*x)^(5/2)*(1 + a*x)^(5/2)*ArcSin[a*x])/(a^6*(c - c/(a^2*x^2))^(5/2)*x^5)}
{E^(2*ArcCoth[a*x])/(c - c/(a^2*x^2))^(7/2), x, 11, -((8*(1 + a*x)^2)/(7*a^3*(c - c/(a^2*x^2))^(7/2)*x^2)) + (1 + a*x)^2/(a^2*(c - c/(a^2*x^2))^(7/2)*x) + (54*(1 - a*x)*(1 + a*x)^2)/(35*a^4*(c - c/(a^2*x^2))^(7/2)*x^3) - (286*(1 - a*x)^2*(1 + a*x)^2)/(105*a^5*(c - c/(a^2*x^2))^(7/2)*x^4) + (356*(1 - a*x)^3*(1 + a*x)^2)/(35*a^6*(c - c/(a^2*x^2))^(7/2)*x^5) + (1144*(1 - a*x)^4*(1 + a*x)^3)/(105*a^8*(c - c/(a^2*x^2))^(7/2)*x^7) - (2*(1 - a*x)^4*(1 + a*x)^2*(356 + 35*a*x))/(105*a^8*(c - c/(a^2*x^2))^(7/2)*x^7) - (2*(1 - a*x)^(7/2)*(1 + a*x)^(7/2)*ArcSin[a*x])/(a^8*(c - c/(a^2*x^2))^(7/2)*x^7)}


{E^(3*ArcCoth[a*x])*(c - c/(a^2*x^2))^(9/2), x, 4, (c - c/(a^2*x^2))^(9/2)/(8*a^9*(1 - 1/(a^2*x^2))^(9/2)*x^8) + (3*(c - c/(a^2*x^2))^(9/2))/(7*a^8*(1 - 1/(a^2*x^2))^(9/2)*x^7) - (8*(c - c/(a^2*x^2))^(9/2))/(5*a^6*(1 - 1/(a^2*x^2))^(9/2)*x^5) - (3*(c - c/(a^2*x^2))^(9/2))/(2*a^5*(1 - 1/(a^2*x^2))^(9/2)*x^4) + (2*(c - c/(a^2*x^2))^(9/2))/(a^4*(1 - 1/(a^2*x^2))^(9/2)*x^3) + (4*(c - c/(a^2*x^2))^(9/2))/(a^3*(1 - 1/(a^2*x^2))^(9/2)*x^2) + ((c - c/(a^2*x^2))^(9/2)*x)/(1 - 1/(a^2*x^2))^(9/2) + (3*(c - c/(a^2*x^2))^(9/2)*Log[x])/(a*(1 - 1/(a^2*x^2))^(9/2))}
{E^(3*ArcCoth[a*x])*(c - c/(a^2*x^2))^(7/2), x, 4, -(c - c/(a^2*x^2))^(7/2)/(6*a^7*(1 - 1/(a^2*x^2))^(7/2)*x^6) - (3*(c - c/(a^2*x^2))^(7/2))/(5*a^6*(1 - 1/(a^2*x^2))^(7/2)*x^5) - (c - c/(a^2*x^2))^(7/2)/(4*a^5*(1 - 1/(a^2*x^2))^(7/2)*x^4) + (5*(c - c/(a^2*x^2))^(7/2))/(3*a^4*(1 - 1/(a^2*x^2))^(7/2)*x^3) + (5*(c - c/(a^2*x^2))^(7/2))/(2*a^3*(1 - 1/(a^2*x^2))^(7/2)*x^2) - (c - c/(a^2*x^2))^(7/2)/(a^2*(1 - 1/(a^2*x^2))^(7/2)*x) + ((c - c/(a^2*x^2))^(7/2)*x)/(1 - 1/(a^2*x^2))^(7/2) + (3*(c - c/(a^2*x^2))^(7/2)*Log[x])/(a*(1 - 1/(a^2*x^2))^(7/2))}
{E^(3*ArcCoth[a*x])*(c - c/(a^2*x^2))^(5/2), x, 4, (c - c/(a^2*x^2))^(5/2)/(4*a^5*(1 - 1/(a^2*x^2))^(5/2)*x^4) + (c - c/(a^2*x^2))^(5/2)/(a^4*(1 - 1/(a^2*x^2))^(5/2)*x^3) + (c - c/(a^2*x^2))^(5/2)/(a^3*(1 - 1/(a^2*x^2))^(5/2)*x^2) - (2*(c - c/(a^2*x^2))^(5/2))/(a^2*(1 - 1/(a^2*x^2))^(5/2)*x) + ((c - c/(a^2*x^2))^(5/2)*x)/(1 - 1/(a^2*x^2))^(5/2) + (3*(c - c/(a^2*x^2))^(5/2)*Log[x])/(a*(1 - 1/(a^2*x^2))^(5/2))}
{E^(3*ArcCoth[a*x])*(c - c/(a^2*x^2))^(3/2), x, 4, -(c - c/(a^2*x^2))^(3/2)/(2*a^3*(1 - 1/(a^2*x^2))^(3/2)*x^2) - (3*(c - c/(a^2*x^2))^(3/2))/(a^2*(1 - 1/(a^2*x^2))^(3/2)*x) + ((c - c/(a^2*x^2))^(3/2)*x)/(1 - 1/(a^2*x^2))^(3/2) + (3*(c - c/(a^2*x^2))^(3/2)*Log[x])/(a*(1 - 1/(a^2*x^2))^(3/2))}
{E^(3*ArcCoth[a*x])*Sqrt[c - c/(a^2*x^2)], x, 4, (Sqrt[c - c/(a^2*x^2)]*x)/Sqrt[1 - 1/(a^2*x^2)] - (Sqrt[c - c/(a^2*x^2)]*Log[x])/(a*Sqrt[1 - 1/(a^2*x^2)]) + (4*Sqrt[c - c/(a^2*x^2)]*Log[1 - a*x])/(a*Sqrt[1 - 1/(a^2*x^2)])}
{E^(3*ArcCoth[a*x])/Sqrt[c - c/(a^2*x^2)], x, 4, (Sqrt[1 - 1/(a^2*x^2)]*x)/Sqrt[c - c/(a^2*x^2)] + (2*Sqrt[1 - 1/(a^2*x^2)])/(a*Sqrt[c - c/(a^2*x^2)]*(1 - a*x)) + (3*Sqrt[1 - 1/(a^2*x^2)]*Log[1 - a*x])/(a*Sqrt[c - c/(a^2*x^2)])}
{E^(3*ArcCoth[a*x])/(c - c/(a^2*x^2))^(3/2), x, 4, ((1 - 1/(a^2*x^2))^(3/2)*x)/(c - c/(a^2*x^2))^(3/2) - (1 - 1/(a^2*x^2))^(3/2)/(2*a*(c - c/(a^2*x^2))^(3/2)*(1 - a*x)^2) + (3*(1 - 1/(a^2*x^2))^(3/2))/(a*(c - c/(a^2*x^2))^(3/2)*(1 - a*x)) + (3*(1 - 1/(a^2*x^2))^(3/2)*Log[1 - a*x])/(a*(c - c/(a^2*x^2))^(3/2))}
{E^(3*ArcCoth[a*x])/(c - c/(a^2*x^2))^(5/2), x, 4, ((1 - 1/(a^2*x^2))^(5/2)*x)/(c - c/(a^2*x^2))^(5/2) + (1 - 1/(a^2*x^2))^(5/2)/(6*a*(c - c/(a^2*x^2))^(5/2)*(1 - a*x)^3) - (9*(1 - 1/(a^2*x^2))^(5/2))/(8*a*(c - c/(a^2*x^2))^(5/2)*(1 - a*x)^2) + (31*(1 - 1/(a^2*x^2))^(5/2))/(8*a*(c - c/(a^2*x^2))^(5/2)*(1 - a*x)) + (49*(1 - 1/(a^2*x^2))^(5/2)*Log[1 - a*x])/(16*a*(c - c/(a^2*x^2))^(5/2)) - ((1 - 1/(a^2*x^2))^(5/2)*Log[1 + a*x])/(16*a*(c - c/(a^2*x^2))^(5/2))}
{E^(3*ArcCoth[a*x])/(c - c/(a^2*x^2))^(7/2), x, 4, ((1 - 1/(a^2*x^2))^(7/2)*x)/(c - c/(a^2*x^2))^(7/2) - (1 - 1/(a^2*x^2))^(7/2)/(16*a*(c - c/(a^2*x^2))^(7/2)*(1 - a*x)^4) + (1 - 1/(a^2*x^2))^(7/2)/(2*a*(c - c/(a^2*x^2))^(7/2)*(1 - a*x)^3) - (59*(1 - 1/(a^2*x^2))^(7/2))/(32*a*(c - c/(a^2*x^2))^(7/2)*(1 - a*x)^2) + (75*(1 - 1/(a^2*x^2))^(7/2))/(16*a*(c - c/(a^2*x^2))^(7/2)*(1 - a*x)) - (1 - 1/(a^2*x^2))^(7/2)/(32*a*(c - c/(a^2*x^2))^(7/2)*(1 + a*x)) + (201*(1 - 1/(a^2*x^2))^(7/2)*Log[1 - a*x])/(64*a*(c - c/(a^2*x^2))^(7/2)) - (9*(1 - 1/(a^2*x^2))^(7/2)*Log[1 + a*x])/(64*a*(c - c/(a^2*x^2))^(7/2))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(c - c/(a^2*x^2))^(7/2)/E^ArcCoth[a*x], x, 4, -(c - c/(a^2*x^2))^(7/2)/(6*a^7*(1 - 1/(a^2*x^2))^(7/2)*x^6) + (c - c/(a^2*x^2))^(7/2)/(5*a^6*(1 - 1/(a^2*x^2))^(7/2)*x^5) + (3*(c - c/(a^2*x^2))^(7/2))/(4*a^5*(1 - 1/(a^2*x^2))^(7/2)*x^4) - (c - c/(a^2*x^2))^(7/2)/(a^4*(1 - 1/(a^2*x^2))^(7/2)*x^3) - (3*(c - c/(a^2*x^2))^(7/2))/(2*a^3*(1 - 1/(a^2*x^2))^(7/2)*x^2) + (3*(c - c/(a^2*x^2))^(7/2))/(a^2*(1 - 1/(a^2*x^2))^(7/2)*x) + ((c - c/(a^2*x^2))^(7/2)*x)/(1 - 1/(a^2*x^2))^(7/2) - ((c - c/(a^2*x^2))^(7/2)*Log[x])/(a*(1 - 1/(a^2*x^2))^(7/2))}
{(c - c/(a^2*x^2))^(5/2)/E^ArcCoth[a*x], x, 4, (c - c/(a^2*x^2))^(5/2)/(4*a^5*(1 - 1/(a^2*x^2))^(5/2)*x^4) - (c - c/(a^2*x^2))^(5/2)/(3*a^4*(1 - 1/(a^2*x^2))^(5/2)*x^3) - (c - c/(a^2*x^2))^(5/2)/(a^3*(1 - 1/(a^2*x^2))^(5/2)*x^2) + (2*(c - c/(a^2*x^2))^(5/2))/(a^2*(1 - 1/(a^2*x^2))^(5/2)*x) + ((c - c/(a^2*x^2))^(5/2)*x)/(1 - 1/(a^2*x^2))^(5/2) - ((c - c/(a^2*x^2))^(5/2)*Log[x])/(a*(1 - 1/(a^2*x^2))^(5/2))}
{(c - c/(a^2*x^2))^(3/2)/E^ArcCoth[a*x], x, 4, -(c - c/(a^2*x^2))^(3/2)/(2*a^3*(1 - 1/(a^2*x^2))^(3/2)*x^2) + (c - c/(a^2*x^2))^(3/2)/(a^2*(1 - 1/(a^2*x^2))^(3/2)*x) + ((c - c/(a^2*x^2))^(3/2)*x)/(1 - 1/(a^2*x^2))^(3/2) - ((c - c/(a^2*x^2))^(3/2)*Log[x])/(a*(1 - 1/(a^2*x^2))^(3/2))}
{Sqrt[c - c/(a^2*x^2)]/E^ArcCoth[a*x], x, 4, (Sqrt[c - c/(a^2*x^2)]*x)/Sqrt[1 - 1/(a^2*x^2)] - (Sqrt[c - c/(a^2*x^2)]*Log[x])/(a*Sqrt[1 - 1/(a^2*x^2)])}
{1/(E^ArcCoth[a*x]*Sqrt[c - c/(a^2*x^2)]), x, 4, (Sqrt[1 - 1/(a^2*x^2)]*x)/Sqrt[c - c/(a^2*x^2)] - (Sqrt[1 - 1/(a^2*x^2)]*Log[1 + a*x])/(a*Sqrt[c - c/(a^2*x^2)])}
{1/(E^ArcCoth[a*x]*(c - c/(a^2*x^2))^(3/2)), x, 4, ((1 - 1/(a^2*x^2))^(3/2)*x)/(c - c/(a^2*x^2))^(3/2) - (1 - 1/(a^2*x^2))^(3/2)/(2*a*(c - c/(a^2*x^2))^(3/2)*(1 + a*x)) + ((1 - 1/(a^2*x^2))^(3/2)*Log[1 - a*x])/(4*a*(c - c/(a^2*x^2))^(3/2)) - (5*(1 - 1/(a^2*x^2))^(3/2)*Log[1 + a*x])/(4*a*(c - c/(a^2*x^2))^(3/2))}
{1/(E^ArcCoth[a*x]*(c - c/(a^2*x^2))^(5/2)), x, 4, ((1 - 1/(a^2*x^2))^(5/2)*x)/(c - c/(a^2*x^2))^(5/2) + (1 - 1/(a^2*x^2))^(5/2)/(8*a*(c - c/(a^2*x^2))^(5/2)*(1 - a*x)) + (1 - 1/(a^2*x^2))^(5/2)/(8*a*(c - c/(a^2*x^2))^(5/2)*(1 + a*x)^2) - (1 - 1/(a^2*x^2))^(5/2)/(a*(c - c/(a^2*x^2))^(5/2)*(1 + a*x)) + (7*(1 - 1/(a^2*x^2))^(5/2)*Log[1 - a*x])/(16*a*(c - c/(a^2*x^2))^(5/2)) - (23*(1 - 1/(a^2*x^2))^(5/2)*Log[1 + a*x])/(16*a*(c - c/(a^2*x^2))^(5/2))}
{1/(E^ArcCoth[a*x]*(c - c/(a^2*x^2))^(7/2)), x, 4, ((1 - 1/(a^2*x^2))^(7/2)*x)/(c - c/(a^2*x^2))^(7/2) - (1 - 1/(a^2*x^2))^(7/2)/(32*a*(c - c/(a^2*x^2))^(7/2)*(1 - a*x)^2) + (5*(1 - 1/(a^2*x^2))^(7/2))/(16*a*(c - c/(a^2*x^2))^(7/2)*(1 - a*x)) - (1 - 1/(a^2*x^2))^(7/2)/(24*a*(c - c/(a^2*x^2))^(7/2)*(1 + a*x)^3) + (11*(1 - 1/(a^2*x^2))^(7/2))/(32*a*(c - c/(a^2*x^2))^(7/2)*(1 + a*x)^2) - (3*(1 - 1/(a^2*x^2))^(7/2))/(2*a*(c - c/(a^2*x^2))^(7/2)*(1 + a*x)) + (19*(1 - 1/(a^2*x^2))^(7/2)*Log[1 - a*x])/(32*a*(c - c/(a^2*x^2))^(7/2)) - (51*(1 - 1/(a^2*x^2))^(7/2)*Log[1 + a*x])/(32*a*(c - c/(a^2*x^2))^(7/2))}


{(c - c/(a^2*x^2))^(7/2)/E^(2*ArcCoth[a*x]), x, 13, (7*a^6*(c - c/(a^2*x^2))^(7/2)*x^7)/(16*(1 - a*x)^3*(1 + a*x)^3) + (3*a^5*(c - c/(a^2*x^2))^(7/2)*x^6)/(8*(1 - a*x)^3*(1 + a*x)^2) - (a*(c - c/(a^2*x^2))^(7/2)*x^2)/(15*(1 + a*x)) - (19*a^4*(c - c/(a^2*x^2))^(7/2)*x^5)/(16*(1 - a*x)^3*(1 + a*x)) + (2*a^3*(c - c/(a^2*x^2))^(7/2)*x^4)/(3*(1 - a*x)^2*(1 + a*x)) - (23*a^2*(c - c/(a^2*x^2))^(7/2)*x^3)/(120*(1 - a*x)*(1 + a*x)) + ((c - c/(a^2*x^2))^(7/2)*x*(1 - a*x))/(6*(1 + a*x)) - (2*a^6*(c - c/(a^2*x^2))^(7/2)*x^7*ArcSin[a*x])/((1 - a*x)^(7/2)*(1 + a*x)^(7/2)) + (25*a^6*(c - c/(a^2*x^2))^(7/2)*x^7*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(8*(1 - a*x)^(7/2)*(1 + a*x)^(7/2))}
{(c - c/(a^2*x^2))^(5/2)/E^(2*ArcCoth[a*x]), x, 11, -((7*a^4*(c - c/(a^2*x^2))^(5/2)*x^5)/(8*(1 - a*x)^2*(1 + a*x)^2)) - (a*(c - c/(a^2*x^2))^(5/2)*x^2)/(6*(1 + a*x)) + (2*a^3*(c - c/(a^2*x^2))^(5/2)*x^4)/((1 - a*x)^2*(1 + a*x)) - (7*a^2*(c - c/(a^2*x^2))^(5/2)*x^3)/(24*(1 - a*x)*(1 + a*x)) + ((c - c/(a^2*x^2))^(5/2)*x*(1 - a*x))/(4*(1 + a*x)) + (2*a^4*(c - c/(a^2*x^2))^(5/2)*x^5*ArcSin[a*x])/((1 - a*x)^(5/2)*(1 + a*x)^(5/2)) - (9*a^4*(c - c/(a^2*x^2))^(5/2)*x^5*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(4*(1 - a*x)^(5/2)*(1 + a*x)^(5/2))}
{(c - c/(a^2*x^2))^(3/2)/E^(2*ArcCoth[a*x]), x, 9, -((a*(c - c/(a^2*x^2))^(3/2)*x^2)/(1 + a*x)) - (5*a^2*(c - c/(a^2*x^2))^(3/2)*x^3)/(2*(1 - a*x)*(1 + a*x)) + ((c - c/(a^2*x^2))^(3/2)*x*(1 - a*x))/(2*(1 + a*x)) - (2*a^2*(c - c/(a^2*x^2))^(3/2)*x^3*ArcSin[a*x])/((1 - a*x)^(3/2)*(1 + a*x)^(3/2)) + (a^2*(c - c/(a^2*x^2))^(3/2)*x^3*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/((1 - a*x)^(3/2)*(1 + a*x)^(3/2))}
{Sqrt[c - c/(a^2*x^2)]/E^(2*ArcCoth[a*x]), x, 7, Sqrt[c - c/(a^2*x^2)]*x + (2*Sqrt[c - c/(a^2*x^2)]*x*ArcSin[a*x])/(Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (2*Sqrt[c - c/(a^2*x^2)]*x*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{1/(E^(2*ArcCoth[a*x])*Sqrt[c - c/(a^2*x^2)]), x, 6, -((1 - a*x)^2/(a^2*Sqrt[c - c/(a^2*x^2)]*x)) - (2*(1 - a*x)*(1 + a*x))/(a^2*Sqrt[c - c/(a^2*x^2)]*x) - (2*Sqrt[1 - a*x]*Sqrt[1 + a*x]*ArcSin[a*x])/(a^2*Sqrt[c - c/(a^2*x^2)]*x)}
{1/(E^(2*ArcCoth[a*x])*(c - c/(a^2*x^2))^(3/2)), x, 8, (1 - a*x)^2/(a^2*(c - c/(a^2*x^2))^(3/2)*x) - (2*(1 - a*x)^3)/(3*a^4*(c - c/(a^2*x^2))^(3/2)*x^3) + (4*(1 - a*x)^2*(1 + a*x))/(a^4*(c - c/(a^2*x^2))^(3/2)*x^3) + (2*(1 - a*x)^(3/2)*(1 + a*x)^(3/2)*ArcSin[a*x])/(a^4*(c - c/(a^2*x^2))^(3/2)*x^3)}
{1/(E^(2*ArcCoth[a*x])*(c - c/(a^2*x^2))^(5/2)), x, 9, -((2*(1 - a*x)^2)/(a^3*(c - c/(a^2*x^2))^(5/2)*x^2)) + (1 - a*x)^2/(a^2*(c - c/(a^2*x^2))^(5/2)*x) - (8*(1 - a*x)^3)/(5*a^4*(c - c/(a^2*x^2))^(5/2)*x^3) + (2*(8 - 5*a*x)*(1 - a*x)^3*(1 + a*x))/(15*a^6*(c - c/(a^2*x^2))^(5/2)*x^5) - (24*(1 - a*x)^3*(1 + a*x)^2)/(5*a^6*(c - c/(a^2*x^2))^(5/2)*x^5) - (2*(1 - a*x)^(5/2)*(1 + a*x)^(5/2)*ArcSin[a*x])/(a^6*(c - c/(a^2*x^2))^(5/2)*x^5)}
{1/(E^(2*ArcCoth[a*x])*(c - c/(a^2*x^2))^(7/2)), x, 11, -((4*(1 - a*x)^2)/(3*a^3*(c - c/(a^2*x^2))^(7/2)*x^2)) + (1 - a*x)^2/(a^2*(c - c/(a^2*x^2))^(7/2)*x) + (14*(1 - a*x)^3)/(3*a^4*(c - c/(a^2*x^2))^(7/2)*x^3) + (62*(1 - a*x)^4)/(21*a^5*(c - c/(a^2*x^2))^(7/2)*x^4) + (76*(1 - a*x)^4*(1 + a*x))/(35*a^6*(c - c/(a^2*x^2))^(7/2)*x^5) - (2*(76 - 35*a*x)*(1 - a*x)^4*(1 + a*x)^2)/(105*a^8*(c - c/(a^2*x^2))^(7/2)*x^7) + (584*(1 - a*x)^4*(1 + a*x)^3)/(105*a^8*(c - c/(a^2*x^2))^(7/2)*x^7) + (2*(1 - a*x)^(7/2)*(1 + a*x)^(7/2)*ArcSin[a*x])/(a^8*(c - c/(a^2*x^2))^(7/2)*x^7)}


{(c - c/(a^2*x^2))^(9/2)/E^(3*ArcCoth[a*x]), x, 4, -(c - c/(a^2*x^2))^(9/2)/(8*a^9*(1 - 1/(a^2*x^2))^(9/2)*x^8) + (3*(c - c/(a^2*x^2))^(9/2))/(7*a^8*(1 - 1/(a^2*x^2))^(9/2)*x^7) - (8*(c - c/(a^2*x^2))^(9/2))/(5*a^6*(1 - 1/(a^2*x^2))^(9/2)*x^5) + (3*(c - c/(a^2*x^2))^(9/2))/(2*a^5*(1 - 1/(a^2*x^2))^(9/2)*x^4) + (2*(c - c/(a^2*x^2))^(9/2))/(a^4*(1 - 1/(a^2*x^2))^(9/2)*x^3) - (4*(c - c/(a^2*x^2))^(9/2))/(a^3*(1 - 1/(a^2*x^2))^(9/2)*x^2) + ((c - c/(a^2*x^2))^(9/2)*x)/(1 - 1/(a^2*x^2))^(9/2) - (3*(c - c/(a^2*x^2))^(9/2)*Log[x])/(a*(1 - 1/(a^2*x^2))^(9/2))}
{(c - c/(a^2*x^2))^(7/2)/E^(3*ArcCoth[a*x]), x, 4, (c - c/(a^2*x^2))^(7/2)/(6*a^7*(1 - 1/(a^2*x^2))^(7/2)*x^6) - (3*(c - c/(a^2*x^2))^(7/2))/(5*a^6*(1 - 1/(a^2*x^2))^(7/2)*x^5) + (c - c/(a^2*x^2))^(7/2)/(4*a^5*(1 - 1/(a^2*x^2))^(7/2)*x^4) + (5*(c - c/(a^2*x^2))^(7/2))/(3*a^4*(1 - 1/(a^2*x^2))^(7/2)*x^3) - (5*(c - c/(a^2*x^2))^(7/2))/(2*a^3*(1 - 1/(a^2*x^2))^(7/2)*x^2) - (c - c/(a^2*x^2))^(7/2)/(a^2*(1 - 1/(a^2*x^2))^(7/2)*x) + ((c - c/(a^2*x^2))^(7/2)*x)/(1 - 1/(a^2*x^2))^(7/2) - (3*(c - c/(a^2*x^2))^(7/2)*Log[x])/(a*(1 - 1/(a^2*x^2))^(7/2))}
{(c - c/(a^2*x^2))^(5/2)/E^(3*ArcCoth[a*x]), x, 4, -(c - c/(a^2*x^2))^(5/2)/(4*a^5*(1 - 1/(a^2*x^2))^(5/2)*x^4) + (c - c/(a^2*x^2))^(5/2)/(a^4*(1 - 1/(a^2*x^2))^(5/2)*x^3) - (c - c/(a^2*x^2))^(5/2)/(a^3*(1 - 1/(a^2*x^2))^(5/2)*x^2) - (2*(c - c/(a^2*x^2))^(5/2))/(a^2*(1 - 1/(a^2*x^2))^(5/2)*x) + ((c - c/(a^2*x^2))^(5/2)*x)/(1 - 1/(a^2*x^2))^(5/2) - (3*(c - c/(a^2*x^2))^(5/2)*Log[x])/(a*(1 - 1/(a^2*x^2))^(5/2))}
{(c - c/(a^2*x^2))^(3/2)/E^(3*ArcCoth[a*x]), x, 4, (c - c/(a^2*x^2))^(3/2)/(2*a^3*(1 - 1/(a^2*x^2))^(3/2)*x^2) - (3*(c - c/(a^2*x^2))^(3/2))/(a^2*(1 - 1/(a^2*x^2))^(3/2)*x) + ((c - c/(a^2*x^2))^(3/2)*x)/(1 - 1/(a^2*x^2))^(3/2) - (3*(c - c/(a^2*x^2))^(3/2)*Log[x])/(a*(1 - 1/(a^2*x^2))^(3/2))}
{Sqrt[c - c/(a^2*x^2)]/E^(3*ArcCoth[a*x]), x, 4, (Sqrt[c - c/(a^2*x^2)]*x)/Sqrt[1 - 1/(a^2*x^2)] + (Sqrt[c - c/(a^2*x^2)]*Log[x])/(a*Sqrt[1 - 1/(a^2*x^2)]) - (4*Sqrt[c - c/(a^2*x^2)]*Log[1 + a*x])/(a*Sqrt[1 - 1/(a^2*x^2)])}
{1/(E^(3*ArcCoth[a*x])*Sqrt[c - c/(a^2*x^2)]), x, 4, (Sqrt[1 - 1/(a^2*x^2)]*x)/Sqrt[c - c/(a^2*x^2)] - (2*Sqrt[1 - 1/(a^2*x^2)])/(a*Sqrt[c - c/(a^2*x^2)]*(1 + a*x)) - (3*Sqrt[1 - 1/(a^2*x^2)]*Log[1 + a*x])/(a*Sqrt[c - c/(a^2*x^2)])}
{1/(E^(3*ArcCoth[a*x])*(c - c/(a^2*x^2))^(3/2)), x, 4, ((1 - 1/(a^2*x^2))^(3/2)*x)/(c - c/(a^2*x^2))^(3/2) + (1 - 1/(a^2*x^2))^(3/2)/(2*a*(c - c/(a^2*x^2))^(3/2)*(1 + a*x)^2) - (3*(1 - 1/(a^2*x^2))^(3/2))/(a*(c - c/(a^2*x^2))^(3/2)*(1 + a*x)) - (3*(1 - 1/(a^2*x^2))^(3/2)*Log[1 + a*x])/(a*(c - c/(a^2*x^2))^(3/2))}
{1/(E^(3*ArcCoth[a*x])*(c - c/(a^2*x^2))^(5/2)), x, 4, ((1 - 1/(a^2*x^2))^(5/2)*x)/(c - c/(a^2*x^2))^(5/2) - (1 - 1/(a^2*x^2))^(5/2)/(6*a*(c - c/(a^2*x^2))^(5/2)*(1 + a*x)^3) + (9*(1 - 1/(a^2*x^2))^(5/2))/(8*a*(c - c/(a^2*x^2))^(5/2)*(1 + a*x)^2) - (31*(1 - 1/(a^2*x^2))^(5/2))/(8*a*(c - c/(a^2*x^2))^(5/2)*(1 + a*x)) + ((1 - 1/(a^2*x^2))^(5/2)*Log[1 - a*x])/(16*a*(c - c/(a^2*x^2))^(5/2)) - (49*(1 - 1/(a^2*x^2))^(5/2)*Log[1 + a*x])/(16*a*(c - c/(a^2*x^2))^(5/2))}
{1/(E^(3*ArcCoth[a*x])*(c - c/(a^2*x^2))^(7/2)), x, 4, ((1 - 1/(a^2*x^2))^(7/2)*x)/(c - c/(a^2*x^2))^(7/2) + (1 - 1/(a^2*x^2))^(7/2)/(32*a*(c - c/(a^2*x^2))^(7/2)*(1 - a*x)) + (1 - 1/(a^2*x^2))^(7/2)/(16*a*(c - c/(a^2*x^2))^(7/2)*(1 + a*x)^4) - (1 - 1/(a^2*x^2))^(7/2)/(2*a*(c - c/(a^2*x^2))^(7/2)*(1 + a*x)^3) + (59*(1 - 1/(a^2*x^2))^(7/2))/(32*a*(c - c/(a^2*x^2))^(7/2)*(1 + a*x)^2) - (75*(1 - 1/(a^2*x^2))^(7/2))/(16*a*(c - c/(a^2*x^2))^(7/2)*(1 + a*x)) + (9*(1 - 1/(a^2*x^2))^(7/2)*Log[1 - a*x])/(64*a*(c - c/(a^2*x^2))^(7/2)) - (201*(1 - 1/(a^2*x^2))^(7/2)*Log[1 + a*x])/(64*a*(c - c/(a^2*x^2))^(7/2))}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{E^(n*ArcCoth[a*x])*Sqrt[c - c/(a^2*x^2)], x, 3, (2^((3 + n)/2)*Sqrt[c - c/(a^2*x^2)]*(1 - 1/(a*x))^((3 - n)/2)*AppellF1[(3 - n)/2, 2, (1/2)*(-1 - n), (5 - n)/2, 1 - 1/(a*x), (a - 1/x)/(2*a)])/(a*(3 - n)*Sqrt[1 - 1/(a^2*x^2)])}
{E^(n*ArcCoth[a*x])/Sqrt[c - c/(a^2*x^2)], x, 3, (2^((1 + n)/2)*Sqrt[1 - 1/(a^2*x^2)]*(1 - 1/(a*x))^((1 - n)/2)*Defer[AppellF1][1/2 - n/2, 2, 1/2 - n/2, 3/2 - n/2, 1 - 1/(a*x), (1/2)*(1 - 1/(a*x))])/(a*(1 - n)*Sqrt[c - c/(a^2*x^2)])}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(n ArcCoth[a x]) (c-c/(a^2 x^2))^(p/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{E^ArcCoth[a*x]*Sqrt[c - c/(a^2*x^2)]*x^m, x, 4, (Sqrt[c - c/(a^2*x^2)]*x^m)/(a*m*Sqrt[1 - 1/(a^2*x^2)]) + (Sqrt[c - c/(a^2*x^2)]*x^(1 + m))/((1 + m)*Sqrt[1 - 1/(a^2*x^2)])}

{E^ArcCoth[a*x]*Sqrt[c - c/(a^2*x^2)]*x^2, x, 4, (Sqrt[c - c/(a^2*x^2)]*x^2)/(2*a*Sqrt[1 - 1/(a^2*x^2)]) + (Sqrt[c - c/(a^2*x^2)]*x^3)/(3*Sqrt[1 - 1/(a^2*x^2)])}
{E^ArcCoth[a*x]*Sqrt[c - c/(a^2*x^2)]*x, x, 3, (Sqrt[c - c/(a^2*x^2)]*x)/(a*Sqrt[1 - 1/(a^2*x^2)]) + (Sqrt[c - c/(a^2*x^2)]*x^2)/(2*Sqrt[1 - 1/(a^2*x^2)])}
{E^ArcCoth[a*x]*Sqrt[c - c/(a^2*x^2)], x, 4, (Sqrt[c - c/(a^2*x^2)]*x)/Sqrt[1 - 1/(a^2*x^2)] + (Sqrt[c - c/(a^2*x^2)]*Log[x])/(a*Sqrt[1 - 1/(a^2*x^2)])}
{(E^ArcCoth[a*x]*Sqrt[c - c/(a^2*x^2)])/x, x, 4, -(Sqrt[c - c/(a^2*x^2)]/(a*Sqrt[1 - 1/(a^2*x^2)]*x)) + (Sqrt[c - c/(a^2*x^2)]*Log[x])/Sqrt[1 - 1/(a^2*x^2)]}
{(E^ArcCoth[a*x]*Sqrt[c - c/(a^2*x^2)])/x^2, x, 4, -Sqrt[c - c/(a^2*x^2)]/(2*a*Sqrt[1 - 1/(a^2*x^2)]*x^2) - Sqrt[c - c/(a^2*x^2)]/(Sqrt[1 - 1/(a^2*x^2)]*x)}


{E^(2*ArcCoth[a*x])*Sqrt[c - c/(a^2*x^2)]*x^3, x, 8, (7*Sqrt[c - c/(a^2*x^2)]*x)/(8*a^3) + (7*Sqrt[c - c/(a^2*x^2)]*x*(1 + a*x))/(24*a^3) + (Sqrt[c - c/(a^2*x^2)]*x*(1 + a*x)^2)/(6*a^3) + (Sqrt[c - c/(a^2*x^2)]*x^2*(1 + a*x)^2)/(4*a^2) - (7*Sqrt[c - c/(a^2*x^2)]*x*ArcSin[a*x])/(8*a^3*Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{E^(2*ArcCoth[a*x])*Sqrt[c - c/(a^2*x^2)]*x^2, x, 7, (Sqrt[c - c/(a^2*x^2)]*x)/a^2 + (Sqrt[c - c/(a^2*x^2)]*x*(1 + a*x))/(3*a^2) + (Sqrt[c - c/(a^2*x^2)]*x*(1 + a*x)^2)/(3*a^2) - (Sqrt[c - c/(a^2*x^2)]*x*ArcSin[a*x])/(a^2*Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{E^(2*ArcCoth[a*x])*Sqrt[c - c/(a^2*x^2)]*x, x, 6, (3*Sqrt[c - c/(a^2*x^2)]*x)/(2*a) + (Sqrt[c - c/(a^2*x^2)]*x*(1 + a*x))/(2*a) - (3*Sqrt[c - c/(a^2*x^2)]*x*ArcSin[a*x])/(2*a*Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{E^(2*ArcCoth[a*x])*Sqrt[c - c/(a^2*x^2)], x, 7, Sqrt[c - c/(a^2*x^2)]*x - (2*Sqrt[c - c/(a^2*x^2)]*x*ArcSin[a*x])/(Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (2*Sqrt[c - c/(a^2*x^2)]*x*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{(E^(2*ArcCoth[a*x])*Sqrt[c - c/(a^2*x^2)])/x, x, 8, Sqrt[c - c/(a^2*x^2)] - (a*Sqrt[c - c/(a^2*x^2)]*x*ArcSin[a*x])/Sqrt[1 - a^2*x^2] + (4*a*Sqrt[c - c/(a^2*x^2)]*x*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/Sqrt[1 - a^2*x^2], (-a)*Sqrt[c - c/(a^2*x^2)]*x + Sqrt[c - c/(a^2*x^2)]*(1 + a*x) - (a*Sqrt[c - c/(a^2*x^2)]*x*ArcSin[a*x])/(Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (4*a*Sqrt[c - c/(a^2*x^2)]*x*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{(E^(2*ArcCoth[a*x])*Sqrt[c - c/(a^2*x^2)])/x^2, x, 6, (3/2)*a*Sqrt[c - c/(a^2*x^2)] + (Sqrt[c - c/(a^2*x^2)]*(1 + a*x))/(2*x) + (3*a^2*Sqrt[c - c/(a^2*x^2)]*x*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{(E^(2*ArcCoth[a*x])*Sqrt[c - c/(a^2*x^2)])/x^3, x, 8, (5/3)*a^2*Sqrt[c - c/(a^2*x^2)] + (2*a*Sqrt[c - c/(a^2*x^2)])/(3*x) + (Sqrt[c - c/(a^2*x^2)]*(1 + a*x))/(3*x^2) + (2*a^3*Sqrt[c - c/(a^2*x^2)]*x*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{(E^(2*ArcCoth[a*x])*Sqrt[c - c/(a^2*x^2)])/x^4, x, 9, (4/3)*a^3*Sqrt[c - c/(a^2*x^2)] + (5*a*Sqrt[c - c/(a^2*x^2)])/(12*x^2) + (7*a^2*Sqrt[c - c/(a^2*x^2)])/(8*x) + (Sqrt[c - c/(a^2*x^2)]*(1 + a*x))/(4*x^3) + (7*a^4*Sqrt[c - c/(a^2*x^2)]*x*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(4*Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{(E^(2*ArcCoth[a*x])*Sqrt[c - c/(a^2*x^2)])/x^5, x, 10, (6/5)*a^4*Sqrt[c - c/(a^2*x^2)] + (3*a*Sqrt[c - c/(a^2*x^2)])/(10*x^3) + (3*a^2*Sqrt[c - c/(a^2*x^2)])/(5*x^2) + (3*a^3*Sqrt[c - c/(a^2*x^2)])/(4*x) + (Sqrt[c - c/(a^2*x^2)]*(1 + a*x))/(5*x^4) + (3*a^5*Sqrt[c - c/(a^2*x^2)]*x*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(2*Sqrt[1 - a*x]*Sqrt[1 + a*x])}


{E^(3*ArcCoth[a*x])*Sqrt[c - c/(a^2*x^2)]*x^3, x, 4, (4*Sqrt[c - c/(a^2*x^2)]*x)/(a^3*Sqrt[1 - 1/(a^2*x^2)]) + (2*Sqrt[c - c/(a^2*x^2)]*x^2)/(a^2*Sqrt[1 - 1/(a^2*x^2)]) + (Sqrt[c - c/(a^2*x^2)]*x^3)/(a*Sqrt[1 - 1/(a^2*x^2)]) + (Sqrt[c - c/(a^2*x^2)]*x^4)/(4*Sqrt[1 - 1/(a^2*x^2)]) + (4*Sqrt[c - c/(a^2*x^2)]*Log[1 - a*x])/(a^4*Sqrt[1 - 1/(a^2*x^2)])}
{E^(3*ArcCoth[a*x])*Sqrt[c - c/(a^2*x^2)]*x^2, x, 4, (4*Sqrt[c - c/(a^2*x^2)]*x)/(a^2*Sqrt[1 - 1/(a^2*x^2)]) + (3*Sqrt[c - c/(a^2*x^2)]*x^2)/(2*a*Sqrt[1 - 1/(a^2*x^2)]) + (Sqrt[c - c/(a^2*x^2)]*x^3)/(3*Sqrt[1 - 1/(a^2*x^2)]) + (4*Sqrt[c - c/(a^2*x^2)]*Log[1 - a*x])/(a^3*Sqrt[1 - 1/(a^2*x^2)])}
{E^(3*ArcCoth[a*x])*Sqrt[c - c/(a^2*x^2)]*x, x, 4, (3*Sqrt[c - c/(a^2*x^2)]*x)/(a*Sqrt[1 - 1/(a^2*x^2)]) + (Sqrt[c - c/(a^2*x^2)]*x^2)/(2*Sqrt[1 - 1/(a^2*x^2)]) + (4*Sqrt[c - c/(a^2*x^2)]*Log[1 - a*x])/(a^2*Sqrt[1 - 1/(a^2*x^2)])}
{E^(3*ArcCoth[a*x])*Sqrt[c - c/(a^2*x^2)], x, 4, (Sqrt[c - c/(a^2*x^2)]*x)/Sqrt[1 - 1/(a^2*x^2)] - (Sqrt[c - c/(a^2*x^2)]*Log[x])/(a*Sqrt[1 - 1/(a^2*x^2)]) + (4*Sqrt[c - c/(a^2*x^2)]*Log[1 - a*x])/(a*Sqrt[1 - 1/(a^2*x^2)])}
{(E^(3*ArcCoth[a*x])*Sqrt[c - c/(a^2*x^2)])/x, x, 4, Sqrt[c - c/(a^2*x^2)]/(a*Sqrt[1 - 1/(a^2*x^2)]*x) - (3*Sqrt[c - c/(a^2*x^2)]*Log[x])/Sqrt[1 - 1/(a^2*x^2)] + (4*Sqrt[c - c/(a^2*x^2)]*Log[1 - a*x])/Sqrt[1 - 1/(a^2*x^2)]}
{(E^(3*ArcCoth[a*x])*Sqrt[c - c/(a^2*x^2)])/x^2, x, 4, Sqrt[c - c/(a^2*x^2)]/(2*a*Sqrt[1 - 1/(a^2*x^2)]*x^2) + (3*Sqrt[c - c/(a^2*x^2)])/(Sqrt[1 - 1/(a^2*x^2)]*x) - (4*a*Sqrt[c - c/(a^2*x^2)]*Log[x])/Sqrt[1 - 1/(a^2*x^2)] + (4*a*Sqrt[c - c/(a^2*x^2)]*Log[1 - a*x])/Sqrt[1 - 1/(a^2*x^2)]}
{(E^(3*ArcCoth[a*x])*Sqrt[c - c/(a^2*x^2)])/x^3, x, 4, Sqrt[c - c/(a^2*x^2)]/(3*a*Sqrt[1 - 1/(a^2*x^2)]*x^3) + (3*Sqrt[c - c/(a^2*x^2)])/(2*Sqrt[1 - 1/(a^2*x^2)]*x^2) + (4*a*Sqrt[c - c/(a^2*x^2)])/(Sqrt[1 - 1/(a^2*x^2)]*x) - (4*a^2*Sqrt[c - c/(a^2*x^2)]*Log[x])/Sqrt[1 - 1/(a^2*x^2)] + (4*a^2*Sqrt[c - c/(a^2*x^2)]*Log[1 - a*x])/Sqrt[1 - 1/(a^2*x^2)]}
{(E^(3*ArcCoth[a*x])*Sqrt[c - c/(a^2*x^2)])/x^4, x, 4, Sqrt[c - c/(a^2*x^2)]/(4*a*Sqrt[1 - 1/(a^2*x^2)]*x^4) + Sqrt[c - c/(a^2*x^2)]/(Sqrt[1 - 1/(a^2*x^2)]*x^3) + (2*a*Sqrt[c - c/(a^2*x^2)])/(Sqrt[1 - 1/(a^2*x^2)]*x^2) + (4*a^2*Sqrt[c - c/(a^2*x^2)])/(Sqrt[1 - 1/(a^2*x^2)]*x) - (4*a^3*Sqrt[c - c/(a^2*x^2)]*Log[x])/Sqrt[1 - 1/(a^2*x^2)] + (4*a^3*Sqrt[c - c/(a^2*x^2)]*Log[1 - a*x])/Sqrt[1 - 1/(a^2*x^2)]}
{(E^(3*ArcCoth[a*x])*Sqrt[c - c/(a^2*x^2)])/x^5, x, 4, Sqrt[c - c/(a^2*x^2)]/(5*a*Sqrt[1 - 1/(a^2*x^2)]*x^5) + (3*Sqrt[c - c/(a^2*x^2)])/(4*Sqrt[1 - 1/(a^2*x^2)]*x^4) + (4*a*Sqrt[c - c/(a^2*x^2)])/(3*Sqrt[1 - 1/(a^2*x^2)]*x^3) + (2*a^2*Sqrt[c - c/(a^2*x^2)])/(Sqrt[1 - 1/(a^2*x^2)]*x^2) + (4*a^3*Sqrt[c - c/(a^2*x^2)])/(Sqrt[1 - 1/(a^2*x^2)]*x) - (4*a^4*Sqrt[c - c/(a^2*x^2)]*Log[x])/Sqrt[1 - 1/(a^2*x^2)] + (4*a^4*Sqrt[c - c/(a^2*x^2)]*Log[1 - a*x])/Sqrt[1 - 1/(a^2*x^2)]}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(Sqrt[c - c/(a^2*x^2)]*x^m)/E^ArcCoth[a*x], x, 4, -((Sqrt[c - c/(a^2*x^2)]*x^m)/(a*m*Sqrt[1 - 1/(a^2*x^2)])) + (Sqrt[c - c/(a^2*x^2)]*x^(1 + m))/((1 + m)*Sqrt[1 - 1/(a^2*x^2)])}
{(Sqrt[c - c/(a^2*x^2)]*x^2)/E^ArcCoth[a*x], x, 4, -(Sqrt[c - c/(a^2*x^2)]*x^2)/(2*a*Sqrt[1 - 1/(a^2*x^2)]) + (Sqrt[c - c/(a^2*x^2)]*x^3)/(3*Sqrt[1 - 1/(a^2*x^2)])}
{(Sqrt[c - c/(a^2*x^2)]*x)/E^ArcCoth[a*x], x, 3, -((Sqrt[c - c/(a^2*x^2)]*x)/(a*Sqrt[1 - 1/(a^2*x^2)])) + (Sqrt[c - c/(a^2*x^2)]*x^2)/(2*Sqrt[1 - 1/(a^2*x^2)])}
{Sqrt[c - c/(a^2*x^2)]/E^ArcCoth[a*x], x, 4, (Sqrt[c - c/(a^2*x^2)]*x)/Sqrt[1 - 1/(a^2*x^2)] - (Sqrt[c - c/(a^2*x^2)]*Log[x])/(a*Sqrt[1 - 1/(a^2*x^2)])}
{Sqrt[c - c/(a^2*x^2)]/(E^ArcCoth[a*x]*x), x, 4, Sqrt[c - c/(a^2*x^2)]/(a*Sqrt[1 - 1/(a^2*x^2)]*x) + (Sqrt[c - c/(a^2*x^2)]*Log[x])/Sqrt[1 - 1/(a^2*x^2)]}
{Sqrt[c - c/(a^2*x^2)]/(E^ArcCoth[a*x]*x^2), x, 4, Sqrt[c - c/(a^2*x^2)]/(2*a*Sqrt[1 - 1/(a^2*x^2)]*x^2) - Sqrt[c - c/(a^2*x^2)]/(Sqrt[1 - 1/(a^2*x^2)]*x)}


{(Sqrt[c - c/(a^2*x^2)]*x^3)/E^(2*ArcCoth[a*x]), x, 8, -((7*Sqrt[c - c/(a^2*x^2)]*x)/(8*a^3)) - (7*Sqrt[c - c/(a^2*x^2)]*x*(1 - a*x))/(24*a^3) - (Sqrt[c - c/(a^2*x^2)]*x*(1 - a*x)^2)/(6*a^3) + (Sqrt[c - c/(a^2*x^2)]*x^2*(1 - a*x)^2)/(4*a^2) - (7*Sqrt[c - c/(a^2*x^2)]*x*ArcSin[a*x])/(8*a^3*Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{(Sqrt[c - c/(a^2*x^2)]*x^2)/E^(2*ArcCoth[a*x]), x, 7, (Sqrt[c - c/(a^2*x^2)]*x)/a^2 + (Sqrt[c - c/(a^2*x^2)]*x*(1 - a*x))/(3*a^2) + (Sqrt[c - c/(a^2*x^2)]*x*(1 - a*x)^2)/(3*a^2) + (Sqrt[c - c/(a^2*x^2)]*x*ArcSin[a*x])/(a^2*Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{(Sqrt[c - c/(a^2*x^2)]*x)/E^(2*ArcCoth[a*x]), x, 6, -((3*Sqrt[c - c/(a^2*x^2)]*x)/(2*a)) - (Sqrt[c - c/(a^2*x^2)]*x*(1 - a*x))/(2*a) - (3*Sqrt[c - c/(a^2*x^2)]*x*ArcSin[a*x])/(2*a*Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{Sqrt[c - c/(a^2*x^2)]/E^(2*ArcCoth[a*x]), x, 7, Sqrt[c - c/(a^2*x^2)]*x + (2*Sqrt[c - c/(a^2*x^2)]*x*ArcSin[a*x])/(Sqrt[1 - a*x]*Sqrt[1 + a*x]) + (2*Sqrt[c - c/(a^2*x^2)]*x*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{Sqrt[c - c/(a^2*x^2)]/(E^(2*ArcCoth[a*x])*x), x, 8, a*Sqrt[c - c/(a^2*x^2)]*x + Sqrt[c - c/(a^2*x^2)]*(1 - a*x) - (a*Sqrt[c - c/(a^2*x^2)]*x*ArcSin[a*x])/(Sqrt[1 - a*x]*Sqrt[1 + a*x]) - (4*a*Sqrt[c - c/(a^2*x^2)]*x*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{Sqrt[c - c/(a^2*x^2)]/(E^(2*ArcCoth[a*x])*x^2), x, 6, (-(3/2))*a*Sqrt[c - c/(a^2*x^2)] + (Sqrt[c - c/(a^2*x^2)]*(1 - a*x))/(2*x) + (3*a^2*Sqrt[c - c/(a^2*x^2)]*x*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{Sqrt[c - c/(a^2*x^2)]/(E^(2*ArcCoth[a*x])*x^3), x, 8, (5/3)*a^2*Sqrt[c - c/(a^2*x^2)] - (2*a*Sqrt[c - c/(a^2*x^2)])/(3*x) + (Sqrt[c - c/(a^2*x^2)]*(1 - a*x))/(3*x^2) - (2*a^3*Sqrt[c - c/(a^2*x^2)]*x*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{Sqrt[c - c/(a^2*x^2)]/(E^(2*ArcCoth[a*x])*x^4), x, 9, (-(4/3))*a^3*Sqrt[c - c/(a^2*x^2)] - (5*a*Sqrt[c - c/(a^2*x^2)])/(12*x^2) + (7*a^2*Sqrt[c - c/(a^2*x^2)])/(8*x) + (Sqrt[c - c/(a^2*x^2)]*(1 - a*x))/(4*x^3) + (7*a^4*Sqrt[c - c/(a^2*x^2)]*x*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(4*Sqrt[1 - a*x]*Sqrt[1 + a*x])}
{Sqrt[c - c/(a^2*x^2)]/(E^(2*ArcCoth[a*x])*x^5), x, 10, (6/5)*a^4*Sqrt[c - c/(a^2*x^2)] - (3*a*Sqrt[c - c/(a^2*x^2)])/(10*x^3) + (3*a^2*Sqrt[c - c/(a^2*x^2)])/(5*x^2) - (3*a^3*Sqrt[c - c/(a^2*x^2)])/(4*x) + (Sqrt[c - c/(a^2*x^2)]*(1 - a*x))/(5*x^4) - (3*a^5*Sqrt[c - c/(a^2*x^2)]*x*ArcTanh[Sqrt[1 - a*x]/Sqrt[1 + a*x]])/(2*Sqrt[1 - a*x]*Sqrt[1 + a*x])}


{(Sqrt[c - c/(a^2*x^2)]*x^3)/E^(3*ArcCoth[a*x]), x, 4, (-4*Sqrt[c - c/(a^2*x^2)]*x)/(a^3*Sqrt[1 - 1/(a^2*x^2)]) + (2*Sqrt[c - c/(a^2*x^2)]*x^2)/(a^2*Sqrt[1 - 1/(a^2*x^2)]) - (Sqrt[c - c/(a^2*x^2)]*x^3)/(a*Sqrt[1 - 1/(a^2*x^2)]) + (Sqrt[c - c/(a^2*x^2)]*x^4)/(4*Sqrt[1 - 1/(a^2*x^2)]) + (4*Sqrt[c - c/(a^2*x^2)]*Log[1 + a*x])/(a^4*Sqrt[1 - 1/(a^2*x^2)])}
{(Sqrt[c - c/(a^2*x^2)]*x^2)/E^(3*ArcCoth[a*x]), x, 4, (4*Sqrt[c - c/(a^2*x^2)]*x)/(a^2*Sqrt[1 - 1/(a^2*x^2)]) - (3*Sqrt[c - c/(a^2*x^2)]*x^2)/(2*a*Sqrt[1 - 1/(a^2*x^2)]) + (Sqrt[c - c/(a^2*x^2)]*x^3)/(3*Sqrt[1 - 1/(a^2*x^2)]) - (4*Sqrt[c - c/(a^2*x^2)]*Log[1 + a*x])/(a^3*Sqrt[1 - 1/(a^2*x^2)])}
{(Sqrt[c - c/(a^2*x^2)]*x)/E^(3*ArcCoth[a*x]), x, 4, (-3*Sqrt[c - c/(a^2*x^2)]*x)/(a*Sqrt[1 - 1/(a^2*x^2)]) + (Sqrt[c - c/(a^2*x^2)]*x^2)/(2*Sqrt[1 - 1/(a^2*x^2)]) + (4*Sqrt[c - c/(a^2*x^2)]*Log[1 + a*x])/(a^2*Sqrt[1 - 1/(a^2*x^2)])}
{Sqrt[c - c/(a^2*x^2)]/E^(3*ArcCoth[a*x]), x, 4, (Sqrt[c - c/(a^2*x^2)]*x)/Sqrt[1 - 1/(a^2*x^2)] + (Sqrt[c - c/(a^2*x^2)]*Log[x])/(a*Sqrt[1 - 1/(a^2*x^2)]) - (4*Sqrt[c - c/(a^2*x^2)]*Log[1 + a*x])/(a*Sqrt[1 - 1/(a^2*x^2)])}
{Sqrt[c - c/(a^2*x^2)]/(E^(3*ArcCoth[a*x])*x), x, 4, -(Sqrt[c - c/(a^2*x^2)]/(a*Sqrt[1 - 1/(a^2*x^2)]*x)) - (3*Sqrt[c - c/(a^2*x^2)]*Log[x])/Sqrt[1 - 1/(a^2*x^2)] + (4*Sqrt[c - c/(a^2*x^2)]*Log[1 + a*x])/Sqrt[1 - 1/(a^2*x^2)]}
{Sqrt[c - c/(a^2*x^2)]/(E^(3*ArcCoth[a*x])*x^2), x, 4, -(Sqrt[c - c/(a^2*x^2)]/(2*a*Sqrt[1 - 1/(a^2*x^2)]*x^2)) + (3*Sqrt[c - c/(a^2*x^2)])/(Sqrt[1 - 1/(a^2*x^2)]*x) + (4*a*Sqrt[c - c/(a^2*x^2)]*Log[x])/Sqrt[1 - 1/(a^2*x^2)] - (4*a*Sqrt[c - c/(a^2*x^2)]*Log[1 + a*x])/Sqrt[1 - 1/(a^2*x^2)]}
{Sqrt[c - c/(a^2*x^2)]/(E^(3*ArcCoth[a*x])*x^3), x, 4, -(Sqrt[c - c/(a^2*x^2)]/(3*a*Sqrt[1 - 1/(a^2*x^2)]*x^3)) + (3*Sqrt[c - c/(a^2*x^2)])/(2*Sqrt[1 - 1/(a^2*x^2)]*x^2) - (4*a*Sqrt[c - c/(a^2*x^2)])/(Sqrt[1 - 1/(a^2*x^2)]*x) - (4*a^2*Sqrt[c - c/(a^2*x^2)]*Log[x])/Sqrt[1 - 1/(a^2*x^2)] + (4*a^2*Sqrt[c - c/(a^2*x^2)]*Log[1 + a*x])/Sqrt[1 - 1/(a^2*x^2)]}
{Sqrt[c - c/(a^2*x^2)]/(E^(3*ArcCoth[a*x])*x^4), x, 4, -(Sqrt[c - c/(a^2*x^2)]/(4*a*Sqrt[1 - 1/(a^2*x^2)]*x^4)) + Sqrt[c - c/(a^2*x^2)]/(Sqrt[1 - 1/(a^2*x^2)]*x^3) - (2*a*Sqrt[c - c/(a^2*x^2)])/(Sqrt[1 - 1/(a^2*x^2)]*x^2) + (4*a^2*Sqrt[c - c/(a^2*x^2)])/(Sqrt[1 - 1/(a^2*x^2)]*x) + (4*a^3*Sqrt[c - c/(a^2*x^2)]*Log[x])/Sqrt[1 - 1/(a^2*x^2)] - (4*a^3*Sqrt[c - c/(a^2*x^2)]*Log[1 + a*x])/Sqrt[1 - 1/(a^2*x^2)]}
{Sqrt[c - c/(a^2*x^2)]/(E^(3*ArcCoth[a*x])*x^5), x, 4, -(Sqrt[c - c/(a^2*x^2)]/(5*a*Sqrt[1 - 1/(a^2*x^2)]*x^5)) + (3*Sqrt[c - c/(a^2*x^2)])/(4*Sqrt[1 - 1/(a^2*x^2)]*x^4) - (4*a*Sqrt[c - c/(a^2*x^2)])/(3*Sqrt[1 - 1/(a^2*x^2)]*x^3) + (2*a^2*Sqrt[c - c/(a^2*x^2)])/(Sqrt[1 - 1/(a^2*x^2)]*x^2) - (4*a^3*Sqrt[c - c/(a^2*x^2)])/(Sqrt[1 - 1/(a^2*x^2)]*x) - (4*a^4*Sqrt[c - c/(a^2*x^2)]*Log[x])/Sqrt[1 - 1/(a^2*x^2)] + (4*a^4*Sqrt[c - c/(a^2*x^2)]*Log[1 + a*x])/Sqrt[1 - 1/(a^2*x^2)]}


(* ::Section::Closed:: *)
(*Miscellaneous integrands involving inverse hyperbolic cotangents*)


{1/((a - a*x^2)*(b - 2*b*ArcCoth[x])), x, 1, -(Log[1 - 2*ArcCoth[x]]/(2*a*b))}


{x^3*ArcCoth[a + b*x^4], x, 2, ((a + b*x^4)*ArcCoth[a + b*x^4])/(4*b) + Log[1 - (a + b*x^4)^2]/(8*b)}


{x^(n-1)*ArcCoth[a + b*x^n], x, 2, ((a + b*x^n)*ArcCoth[a + b*x^n])/(b*n) + Log[1 - (a + b*x^n)^2]/(2*b*n)}
