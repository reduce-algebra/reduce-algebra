(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Inverse Hyperbolic Secants*)


(* ::Subsection::Closed:: *)
(*Integrands involving inverse hyperbolic secants*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m ArcSech[a x]^n*)


(* Integrands of the form x^m*ArcSech[a*x] where m is an integer *)
{x^4*ArcSech[a*x], x, 12, -((3*Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x))/(40*a^5)) - (Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x)^2)/(40*a^5) - (Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x)^3)/(100*a^5) + (Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x)^4)/(200*a^5) + (11*((1 - a*x)/(1 + a*x))^(3/2)*(1 + a*x)^4)/(200*a^5) + (((1 - a*x)/(1 + a*x))^(5/2)*(1 + a*x)^4)/(40*a^5) + (((1 - a*x)/(1 + a*x))^(7/2)*(1 + a*x)^4)/(40*a^5) + (1/5)*x^5*ArcSech[a*x] - (3*ArcTan[Sqrt[(1 - a*x)/(1 + a*x)]])/(20*a^5)}
{x^3*ArcSech[a*x], x, 5, -((Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x)^3)/(16*a^4)) - (((1 - a*x)/(1 + a*x))^(3/2)*(1 + a*x)^3)/(24*a^4) - (((1 - a*x)/(1 + a*x))^(5/2)*(1 + a*x)^3)/(16*a^4) + (1/4)*x^4*ArcSech[a*x]}
{x^2*ArcSech[a*x], x, 5, -((Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x))/(6*a^3)) + (((1 - a*x)/(1 + a*x))^(3/2)*(1 + a*x)^2)/(6*a^3) + (1/3)*x^3*ArcSech[a*x] - ArcTan[Sqrt[(1 - a*x)/(1 + a*x)]]/(3*a^3)}
{x*ArcSech[a*x], x, 3, -((Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x))/(2*a^2)) + (1/2)*x^2*ArcSech[a*x]}
{ArcSech[a*x], x, 1, x*ArcSech[a*x] - (2*ArcTan[Sqrt[(1 - a*x)/(1 + a*x)]])/a}
{ArcSech[a*x]/x, x, 6, (1/2)*ArcSech[a*x]^2 - ArcSech[a*x]*Log[1 + E^(2*ArcSech[a*x])] - (1/2)*PolyLog[2, -E^(2*ArcSech[a*x])]}
{ArcSech[a*x]/x^2, x, 3, (Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x))/x - ArcSech[a*x]/x}
{ArcSech[a*x]/x^3, x, 8, (a*Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x))/(4*x) + (((1 - a*x)/(1 + a*x))^(3/2)*(1 + a*x)^2)/(4*x^2) - ArcSech[a*x]/(2*x^2) + (1/2)*a^2*ArcTanh[Sqrt[(1 - a*x)/(1 + a*x)]]}
{ArcSech[a*x]/x^4, x, 5, (Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x)^3)/(12*x^3) - (((1 - a*x)/(1 + a*x))^(3/2)*(1 + a*x)^3)/(18*x^3) + (((1 - a*x)/(1 + a*x))^(5/2)*(1 + a*x)^3)/(12*x^3) - ArcSech[a*x]/(3*x^3)}


(* ::Subsubsection::Closed:: *)
(*Miscellaneous integrands involving inverse hyperbolic secants*)


(* Integrands of the form x^m*ArcSech[a+b*x] where m is an integer *)
{x*ArcSech[a + b*x], x, 7, -(Sqrt[(1 - a - b*x)/(1 + a + b*x)]/(b^2*(1 + (1 - a - b*x)/(1 + a + b*x)))) - (a*(a + b*x)*ArcSech[a + b*x])/b^2 + ((a + b*x)^2*ArcSech[a + b*x])/(2*b^2) + (2*a*ArcTan[Sqrt[(1 - a - b*x)/(1 + a + b*x)]])/b^2}
{x^2*ArcSech[a + b*x], x, 12, (2*((1 - a - b*x)/(1 + a + b*x))^(3/2))/(3*b^3*(1 + (1 - a - b*x)/(1 + a + b*x))^2) - Sqrt[(1 - a - b*x)/(1 + a + b*x)]/(3*b^3*(1 + (1 - a - b*x)/(1 + a + b*x))) + (2*a*Sqrt[(1 - a - b*x)/(1 + a + b*x)])/(b^3*(1 + (1 - a - b*x)/(1 + a + b*x))) + (a^2*(a + b*x)*ArcSech[a + b*x])/b^3 - (a*(a + b*x)^2*ArcSech[a + b*x])/b^3 + ((a + b*x)^3*ArcSech[a + b*x])/(3*b^3) - ArcTan[Sqrt[(1 - a - b*x)/(1 + a + b*x)]]/(3*b^3) - (2*a^2*ArcTan[Sqrt[(1 - a - b*x)/(1 + a + b*x)]])/b^3}
{ArcSech[a + b*x]/x, x, 3, Int[ArcSech[a + b*x]/x, x]}
(* {ArcSech[a + b*x]/x^2, x, 0, (b*ArcCsch[a + b*x])/a - ArcSech[a + b*x]/x - (Sqrt[-1 + (a + b*x)^2]*ArcTanh[(-(1/b) + (a*(a + b*x))/b)/(Sqrt[-(1/b^2) + a^2/b^2]*Sqrt[-1 + (a + b*x)^2])])/(a*Sqrt[-(1/b^2) + a^2/b^2]*(a + b*x)*Sqrt[1 - 1/(a + b*x)^2])} *)


(* Integrands of the form x^m*ArcSech[Sqrt[x]] where m is an integer *)
{ArcSech[Sqrt[x]], x, 4, (-Sqrt[(1 - Sqrt[x])/(1 + Sqrt[x])])*(1 + Sqrt[x]) + x*ArcSech[Sqrt[x]]}
{x*ArcSech[Sqrt[x]], x, 6, (-(1/8))*Sqrt[(1 - Sqrt[x])/(1 + Sqrt[x])]*(1 + Sqrt[x])^3 - (1/12)*((1 - Sqrt[x])/(1 + Sqrt[x]))^(3/2)*(1 + Sqrt[x])^3 - (1/8)*((1 - Sqrt[x])/(1 + Sqrt[x]))^(5/2)*(1 + Sqrt[x])^3 + (1/2)*x^2*ArcSech[Sqrt[x]]}
{x^2*ArcSech[Sqrt[x]], x, 8, (-(1/48))*Sqrt[(1 - Sqrt[x])/(1 + Sqrt[x])]*(1 + Sqrt[x])^5 - (1/36)*((1 - Sqrt[x])/(1 + Sqrt[x]))^(3/2)*(1 + Sqrt[x])^5 - (29/360)*((1 - Sqrt[x])/(1 + Sqrt[x]))^(5/2)*(1 + Sqrt[x])^5 - (1/36)*((1 - Sqrt[x])/(1 + Sqrt[x]))^(7/2)*(1 + Sqrt[x])^5 - (1/48)*((1 - Sqrt[x])/(1 + Sqrt[x]))^(9/2)*(1 + Sqrt[x])^5 + (1/3)*x^3*ArcSech[Sqrt[x]]}
{ArcSech[Sqrt[x]]/x, x, 7, ArcSech[Sqrt[x]]^2 - 2*ArcSech[Sqrt[x]]*Log[1 + E^(2*ArcSech[Sqrt[x]])] - PolyLog[2, -E^(2*ArcSech[Sqrt[x]])]}
{ArcSech[Sqrt[x]]/x^2, x, 9, (((1 - Sqrt[x])/(1 + Sqrt[x]))^(3/2)*(1 + Sqrt[x])^2)/(2*x) + (Sqrt[(1 - Sqrt[x])/(1 + Sqrt[x])]*(1 + Sqrt[x]))/(2*Sqrt[x]) - ArcSech[Sqrt[x]]/x + ArcTanh[Sqrt[(1 - Sqrt[x])/(1 + Sqrt[x])]]}
{ArcSech[Sqrt[x]]/x^3, x, 13, -((Sqrt[(1 - Sqrt[x])/(1 + Sqrt[x])]*(1 + Sqrt[x])^4)/(80*x^2)) + (11*((1 - Sqrt[x])/(1 + Sqrt[x]))^(3/2)*(1 + Sqrt[x])^4)/(80*x^2) - (((1 - Sqrt[x])/(1 + Sqrt[x]))^(5/2)*(1 + Sqrt[x])^4)/(16*x^2) + (((1 - Sqrt[x])/(1 + Sqrt[x]))^(7/2)*(1 + Sqrt[x])^4)/(16*x^2) + (Sqrt[(1 - Sqrt[x])/(1 + Sqrt[x])]*(1 + Sqrt[x])^3)/(40*x^(3/2)) + (Sqrt[(1 - Sqrt[x])/(1 + Sqrt[x])]*(1 + Sqrt[x])^2)/(16*x) + (3*Sqrt[(1 - Sqrt[x])/(1 + Sqrt[x])]*(1 + Sqrt[x]))/(16*Sqrt[x]) - ArcSech[Sqrt[x]]/(2*x^2) + (3/8)*ArcTanh[Sqrt[(1 - Sqrt[x])/(1 + Sqrt[x])]]}


(* ::Subsection::Closed:: *)
(*Integrands involving inverse hyperbolic functions of exponentials*)


{ArcSech[c*E^(a + b*x)], x, 7, ArcSech[c*E^(a + b*x)]^2/(2*b) - (ArcSech[c*E^(a + b*x)]*Log[1 + E^(2*ArcSech[c*E^(a + b*x)])])/b - PolyLog[2, -E^(2*ArcSech[c*E^(a + b*x)])]/(2*b)}


(* ::Subsection::Closed:: *)
(*Integrands involving exponentials of arcsecants*)


{x^2*E^ArcSech[x], x, 18, x^2/2 - (1/3)*Sqrt[(1 - x)/(1 + x)] - (1/3)*x*Sqrt[(1 - x)/(1 + x)] + (1/3)*x^2*Sqrt[(1 - x)/(1 + x)] + (1/3)*x^3*Sqrt[(1 - x)/(1 + x)], x^2/2 - (2/3)*Sqrt[(1 - x)/(1 + x)]*(1 + x)^2 - ((1 - x)/(1 + x))^(3/2)*(1 + x)^2 + (1/3)*Sqrt[(1 - x)/(1 + x)]*(1 + x)^3 + (1/2)*((1 - x)/(1 + x))^(3/2)*(1 + x)^3 + (1/2)*((1 - x)/(1 + x))^(5/2)*(1 + x)^3}
{x*E^ArcSech[x], x, 12, x + (1/2)*x*Sqrt[(1 - x)/(1 + x)] + (1/2)*x^2*Sqrt[(1 - x)/(1 + x)] - ArcTan[Sqrt[(1 - x)/(1 + x)]], x + (3/2)*Sqrt[(1 - x)/(1 + x)]*(1 + x) - (1/2)*Sqrt[(1 - x)/(1 + x)]*(1 + x)^2 - ((1 - x)/(1 + x))^(3/2)*(1 + x)^2 - ArcTan[Sqrt[(1 - x)/(1 + x)]]}
{E^ArcSech[x], x, 10, Sqrt[(1 - x)/(1 + x)]*(1 + x) - 2*ArcTanh[Sqrt[(1 - x)/(1 + x)]] + Log[x]}
{E^ArcSech[x]/x, x, 11, -(1/x) - (Sqrt[(1 - x)/(1 + x)]*(1 + x))/x + 2*ArcTan[Sqrt[(1 - x)/(1 + x)]]}
{E^ArcSech[x]/x^2, x, 13, -(1/(2*x^2)) - (3*Sqrt[(1 - x)/(1 + x)]*(1 + x))/(2*x) + (Sqrt[(1 - x)/(1 + x)]*(1 + x)^2)/(2*x^2) - (((1 - x)/(1 + x))^(3/2)*(1 + x)^2)/x^2 + ArcTanh[Sqrt[(1 - x)/(1 + x)]]}


(* ::Subsection::Closed:: *)
(*Miscellaneous integrands involving inverse hyperbolic secants*)


{ArcSech[1/x], x, 1, -(Sqrt[-1 + x]*Sqrt[1 + x]) + x*ArcCosh[x]}


{ArcSech[a + b*x]/((a*d)/b + d*x), x, 9, ArcSech[a + b*x]^2/(2*d) - (ArcSech[a + b*x]*Log[1 + E^(2*ArcSech[a + b*x])])/d - PolyLog[2, -E^(2*ArcSech[a + b*x])]/(2*d)}


{ArcSech[a*x^n]/x, x, 7, ArcSech[a*x^n]^2/(2*n) - (ArcSech[a*x^n]*Log[1 + E^(2*ArcSech[a*x^n])])/n - PolyLog[2, -E^(2*ArcSech[a*x^n])]/(2*n)}

{ArcSech[a*x^5]/x, x, 7, (1/10)*ArcSech[a*x^5]^2 - (1/5)*ArcSech[a*x^5]*Log[1 + E^(2*ArcSech[a*x^5])] - (1/10)*PolyLog[2, -E^(2*ArcSech[a*x^5])]}


{x^3*ArcSech[a + b*x^4], x, 2, ((a + b*x^4)*ArcSech[a + b*x^4])/(4*b) - ArcTan[Sqrt[(1 - a - b*x^4)/(1 + a + b*x^4)]]/(2*b)}

{x^(n-1)*ArcSech[a + b*x^n], x, 2, ((a + b*x^n)*ArcSech[a + b*x^n])/(b*n) - (2*ArcTan[Sqrt[(1 - a - b*x^n)/(1 + a + b*x^n)]])/(b*n)}
