(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Inverse Hyperbolic Cosecants*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcCsch[a x]^n*)


{x^4*ArcCsch[a*x], x, 6, -((3*Sqrt[1 + 1/(a^2*x^2)]*x^2)/(40*a^3)) + (Sqrt[1 + 1/(a^2*x^2)]*x^4)/(20*a) + (1/5)*x^5*ArcCsch[a*x] + (3*ArcTanh[Sqrt[1 + 1/(a^2*x^2)]])/(40*a^5)}
{x^3*ArcCsch[a*x], x, 4, -((Sqrt[1 + 1/(a^2*x^2)]*x)/(6*a^3)) + (Sqrt[1 + 1/(a^2*x^2)]*x^3)/(12*a) + (1/4)*x^4*ArcCsch[a*x]}
{x^2*ArcCsch[a*x], x, 4, (Sqrt[1 + 1/(a^2*x^2)]*x^2)/(6*a) + (1/3)*x^3*ArcCsch[a*x] - ArcTanh[Sqrt[1 + 1/(a^2*x^2)]]/(6*a^3)}
{x^1*ArcCsch[a*x], x, 2, (Sqrt[1 + 1/(a^2*x^2)]*x)/(2*a) + (1/2)*x^2*ArcCsch[a*x]}
{x^0*ArcCsch[a*x], x, 3, x*ArcCsch[a*x] + ArcTanh[Sqrt[1 + 1/(a^2*x^2)]]/a}
{ArcCsch[a*x]/x^1, x, 1, (-(1/2))*ArcCsch[a*x]^2 - ArcCsch[a*x]*Log[-((2*(1 - a*Sqrt[1 + 1/(a^2*x^2)]*x))/(a^2*x^2))] + (1/2)*PolyLog[2, 1 + (2*(1 - a*Sqrt[1 + 1/(a^2*x^2)]*x))/(a^2*x^2)]}
{ArcCsch[a*x]/x^2, x, 2, a*Sqrt[1 + 1/(a^2*x^2)] - ArcCsch[a*x]/x}
{ArcCsch[a*x]/x^3, x, 4, (a*Sqrt[1 + 1/(a^2*x^2)])/(4*x) - ArcCsch[a*x]/(2*x^2) - (1/4)*a^2*ArcSinh[1/(a*x)]}
{ArcCsch[a*x]/x^4, x, 4, (-(2/9))*a^3*Sqrt[1 + 1/(a^2*x^2)] + (a*Sqrt[1 + 1/(a^2*x^2)])/(9*x^2) - ArcCsch[a*x]/(3*x^3)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcCsch[a+b x]^n*)


{x^3*ArcCsch[a + b*x], x, 12, -(((a + b*x)*Sqrt[1 + 1/(a + b*x)^2])/(6*b^4)) + (3*a^2*(a + b*x)*Sqrt[1 + 1/(a + b*x)^2])/(2*b^4) - (a*(a + b*x)^2*Sqrt[1 + 1/(a + b*x)^2])/(2*b^4) + ((a + b*x)^3*Sqrt[1 + 1/(a + b*x)^2])/(12*b^4) - ((a^4 - b^4*x^4)*ArcCsch[a + b*x])/(4*b^4) + (a*ArcTanh[Sqrt[1 + 1/(a + b*x)^2]])/(2*b^4) - (a^3*ArcTanh[Sqrt[1 + 1/(a + b*x)^2]])/b^4}
{x^2*ArcCsch[a + b*x], x, 10, -((a*(a + b*x)*Sqrt[1 + 1/(a + b*x)^2])/b^3) + ((a + b*x)^2*Sqrt[1 + 1/(a + b*x)^2])/(6*b^3) + ((a^3 + b^3*x^3)*ArcCsch[a + b*x])/(3*b^3) - ArcTanh[Sqrt[1 + 1/(a + b*x)^2]]/(6*b^3) + (a^2*ArcTanh[Sqrt[1 + 1/(a + b*x)^2]])/b^3}
{x^1*ArcCsch[a + b*x], x, 6, ((a + b*x)*Sqrt[1 + 1/(a + b*x)^2])/(2*b^2) - ((a^2 - b^2*x^2)*ArcCsch[a + b*x])/(2*b^2) - (a*ArcTanh[Sqrt[1 + 1/(a + b*x)^2]])/b^2}
{ArcCsch[a + b*x]/x^1, x, 1, -ArcCsch[a + b*x]^2 - ArcCsch[a + b*x]*Log[1 - E^(-2*ArcCsch[a + b*x])] + ArcCsch[a + b*x]*Log[1 + ((1 - Sqrt[1 + a^2])*E^ArcCsch[a + b*x])/a] + ArcCsch[a + b*x]*Log[1 + ((1 + Sqrt[1 + a^2])*E^ArcCsch[a + b*x])/a] + (1/2)*PolyLog[2, E^(-2*ArcCsch[a + b*x])] + PolyLog[2, -(((1 - Sqrt[1 + a^2])*E^ArcCsch[a + b*x])/a)] + PolyLog[2, -(((1 + Sqrt[1 + a^2])*E^ArcCsch[a + b*x])/a)]}
{ArcCsch[a + b*x]/x^2, x, 4, -(((b + a/x)*ArcCsch[a + b*x])/a) + (b*ArcTanh[(a + 1/(a + b*x))/(Sqrt[1 + a^2]*Sqrt[1 + 1/(a + b*x)^2])])/(a*Sqrt[1 + a^2])}
{ArcCsch[a + b*x]/x^3, x, 6, (b^2*Sqrt[1 + 1/(a + b*x)^2])/(2*a*(1 + a^2)*(1 - a/(a + b*x))) + ((b^2 - a^2/x^2)*ArcCsch[a + b*x])/(2*a^2) - ((1 + 2*a^2)*b^2*ArcTanh[(a + 1/(a + b*x))/(Sqrt[1 + a^2]*Sqrt[1 + 1/(a + b*x)^2])])/(2*a^2*(1 + a^2)^(3/2))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcCsch[a x^n]*)


{x^2*ArcCsch[Sqrt[x]], x, 6, (8/45)*Sqrt[1 + 1/x]*Sqrt[x] - (4/45)*Sqrt[1 + 1/x]*x^(3/2) + (1/15)*Sqrt[1 + 1/x]*x^(5/2) + (1/3)*x^3*ArcCsch[Sqrt[x]]}
{x^1*ArcCsch[Sqrt[x]], x, 5, (-(1/3))*Sqrt[1 + 1/x]*Sqrt[x] + (1/6)*Sqrt[1 + 1/x]*x^(3/2) + (1/2)*x^2*ArcCsch[Sqrt[x]]}
{x^0*ArcCsch[Sqrt[x]], x, 3, Sqrt[1 + 1/x]*Sqrt[x] + x*ArcCsch[Sqrt[x]]}
{ArcCsch[Sqrt[x]]/x^1, x, 2, -ArcCsch[Sqrt[x]]^2 - 2*ArcCsch[Sqrt[x]]*Log[-((2*(1 - Sqrt[1 + 1/x]*Sqrt[x]))/x)] + PolyLog[2, 1 + (2*(1 - Sqrt[1 + 1/x]*Sqrt[x]))/x]}
{ArcCsch[Sqrt[x]]/x^2, x, 5, Sqrt[1 + 1/x]/(2*Sqrt[x]) - ArcCsch[Sqrt[x]]/x - (1/2)*ArcSinh[1/Sqrt[x]]}
{ArcCsch[Sqrt[x]]/x^3, x, 6, Sqrt[1 + 1/x]/(8*x^(3/2)) - (3*Sqrt[1 + 1/x])/(16*Sqrt[x]) - ArcCsch[Sqrt[x]]/(2*x^2) + (3/16)*ArcSinh[1/Sqrt[x]]}


{ArcCsch[a*x^n]/x, x, 2, -(ArcCsch[a*x^n]^2/(2*n)) - (ArcCsch[a*x^n]*Log[-((2*(1 - a*x^n*Sqrt[1 + 1/(x^(2*n)*a^2)]))/(x^(2*n)*a^2))])/n + PolyLog[2, 1 + (2*(1 - a*x^n*Sqrt[1 + 1/(x^(2*n)*a^2)]))/(x^(2*n)*a^2)]/(2*n)}
{ArcCsch[a*x^5]/x, x, 2, (-(1/10))*ArcCsch[a*x^5]^2 - (1/5)*ArcCsch[a*x^5]*Log[-((2*(1 - a*Sqrt[1 + 1/(a^2*x^10)]*x^5))/(a^2*x^10))] + (1/10)*PolyLog[2, 1 + (2*(1 - a*Sqrt[1 + 1/(a^2*x^10)]*x^5))/(a^2*x^10)]}


(* ::Subsection::Closed:: *)
(*Integrands involving inverse hyperbolic functions of exponentials*)


{ArcCsch[c*E^(a + b*x)], x, 2, -(ArcCsch[c*E^(a + b*x)]^2/(2*b)) - (ArcCsch[c*E^(a + b*x)]*Log[-((2*E^(-2*a - 2*b*x)*(1 - c*E^(a + b*x)*Sqrt[1 + E^(-2*a - 2*b*x)/c^2]))/c^2)])/b + PolyLog[2, 1 + (2*E^(-2*a - 2*b*x)*(1 - c*E^(a + b*x)*Sqrt[1 + E^(-2*a - 2*b*x)/c^2]))/c^2]/(2*b)}


(* ::Subsection::Closed:: *)
(*Integrands involving exponentials of arccosecants*)


{x^4*E^ArcCsch[x], x, 6, (-(2/15))*(1 + 1/x^2)^(3/2)*x^3 + x^4/4 + (1/5)*(1 + 1/x^2)^(3/2)*x^5}
{x^3*E^ArcCsch[x], x, 8, (1/8)*Sqrt[1 + 1/x^2]*x^2 + x^3/3 + (1/4)*Sqrt[1 + 1/x^2]*x^4 - (1/8)*ArcTanh[Sqrt[1 + 1/x^2]]}
{x^2*E^ArcCsch[x], x, 4, x^2/2 + (1/3)*(1 + 1/x^2)^(3/2)*x^3}
{x^1*E^ArcCsch[x], x, 7, x + (1/2)*Sqrt[1 + 1/x^2]*x^2 + (1/2)*ArcTanh[Sqrt[1 + 1/x^2]]}
{x^0*E^ArcCsch[x], x, 5, Sqrt[1 + 1/x^2]*x - ArcSinh[1/x] + Log[x]}
{E^ArcCsch[x]/x^1, x, 6, -Sqrt[1 + 1/x^2] - 1/x + ArcTanh[Sqrt[1 + 1/x^2]]}
{E^ArcCsch[x]/x^2, x, 5, -(1/(2*x^2)) - Sqrt[1 + 1/x^2]/(2*x) - (1/2)*ArcSinh[1/x]}
{E^ArcCsch[x]/x^3, x, 4, (-(1/3))*(1 + 1/x^2)^(3/2) - 1/(3*x^3)}
{E^ArcCsch[x]/x^4, x, 7, -(1/(4*x^4)) - Sqrt[1 + 1/x^2]/(4*x^3) - Sqrt[1 + 1/x^2]/(8*x) + (1/8)*ArcSinh[1/x]}
{E^ArcCsch[x]/x^5, x, 7, (1/3)*(1 + 1/x^2)^(3/2) - (1/5)*(1 + 1/x^2)^(5/2) - 1/(5*x^5)}


(* ::Subsection::Closed:: *)
(*Miscellaneous integrands involving inverse hyperbolic cosecants*)


{ArcCsch[1/x], x, 2, -Sqrt[1 + x^2] + x*ArcSinh[x]}


{ArcCsch[a + b*x]/((a*d)/b + d*x), x, 3, -(ArcCsch[b*(a/b + x)]^2/(2*d)) - (ArcCsch[b*(a/b + x)]*Log[-((2*(1 - b*(a/b + x)*Sqrt[1 + 1/(b^2*(a/b + x)^2)]))/(b^2*(a/b + x)^2))])/d + PolyLog[2, 1 + (2*(1 - b*(a/b + x)*Sqrt[1 + 1/(b^2*(a/b + x)^2)]))/(b^2*(a/b + x)^2)]/(2*d)}


{x^3*ArcCsch[a + b*x^4], x, 5, ((a + b*x^4)*ArcCsch[a + b*x^4])/(4*b) + ArcTanh[Sqrt[1 + 1/(a + b*x^4)^2]]/(4*b)}

{x^(n-1)*ArcCsch[a + b*x^n], x, 5, ((a + b*x^n)*ArcCsch[a + b*x^n])/(b*n) + ArcTanh[Sqrt[1 + 1/(a + b*x^n)^2]]/(b*n)}
