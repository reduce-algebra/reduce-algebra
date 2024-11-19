(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Inverse Hyperbolic Cosecants*)


(* ::Subsection::Closed:: *)
(*Integrands involving inverse hyperbolic cosecants*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m ArcCsch[a x]^n*)


(* Integrands of the form x^m*ArcCsch[a*x] where m is an integer *)
{x^4*ArcCsch[a*x], x, 5, -((3*Sqrt[1 + 1/(a^2*x^2)]*x^2)/(40*a^3)) + (Sqrt[1 + 1/(a^2*x^2)]*x^4)/(20*a) + (1/5)*x^5*ArcCsch[a*x] + (3*ArcTanh[Sqrt[1 + 1/(a^2*x^2)]])/(40*a^5)}
{x^3*ArcCsch[a*x], x, 4, -((Sqrt[1 + 1/(a^2*x^2)]*x)/(6*a^3)) + (Sqrt[1 + 1/(a^2*x^2)]*x^3)/(12*a) + (1/4)*x^4*ArcCsch[a*x]}
{x^2*ArcCsch[a*x], x, 4, (Sqrt[1 + 1/(a^2*x^2)]*x^2)/(6*a) + (1/3)*x^3*ArcCsch[a*x] - ArcTanh[Sqrt[1 + 1/(a^2*x^2)]]/(6*a^3)}
{x*ArcCsch[a*x], x, 3, (Sqrt[1 + 1/(a^2*x^2)]*x)/(2*a) + (1/2)*x^2*ArcCsch[a*x]}
{ArcCsch[a*x], x, 1, x*ArcCsch[a*x] + ArcTanh[Sqrt[1 + 1/(a^2*x^2)]]/a}
{ArcCsch[a*x]/x, x, 6, (1/2)*ArcCsch[a*x]^2 - ArcCsch[a*x]*Log[1 - E^(2*ArcCsch[a*x])] - (1/2)*PolyLog[2, E^(2*ArcCsch[a*x])]}
{ArcCsch[a*x]/x^2, x, 4, a*Sqrt[1 + 1/(a^2*x^2)] - ArcCsch[a*x]/x}
{ArcCsch[a*x]/x^3, x, 5, (a*Sqrt[1 + 1/(a^2*x^2)])/(4*x) - ArcCsch[a*x]/(2*x^2) - (1/4)*a^2*ArcSinh[1/(a*x)]}
{ArcCsch[a*x]/x^4, x, 5, (-(2/9))*a^3*Sqrt[1 + 1/(a^2*x^2)] + (a*Sqrt[1 + 1/(a^2*x^2)])/(9*x^2) - ArcCsch[a*x]/(3*x^3)}


(* ::Subsubsection::Closed:: *)
(*Miscellaneous integrands involving inverse hyperbolic cosecants*)


(* Integrands of the form x^m*ArcCsch[a+b*x] where m is an integer *)
{x*ArcCsch[a + b*x], x, 6, ((a + b*x)*Sqrt[1 + 1/(a + b*x)^2])/(2*b^2) - (a*(a + b*x)*ArcCsch[a + b*x])/b^2 + ((a + b*x)^2*ArcCsch[a + b*x])/(2*b^2) - (a*ArcTanh[Sqrt[1 + 1/(a + b*x)^2]])/b^2}
{x^2*ArcCsch[a + b*x], x, 9, -((a*(a + b*x)*Sqrt[1 + 1/(a + b*x)^2])/b^3) + ((a + b*x)^2*Sqrt[1 + 1/(a + b*x)^2])/(6*b^3) + (a^2*(a + b*x)*ArcCsch[a + b*x])/b^3 - (a*(a + b*x)^2*ArcCsch[a + b*x])/b^3 + ((a + b*x)^3*ArcCsch[a + b*x])/(3*b^3) - ArcTanh[Sqrt[1 + 1/(a + b*x)^2]]/(6*b^3) + (a^2*ArcTanh[Sqrt[1 + 1/(a + b*x)^2]])/b^3}
{ArcCsch[a + b*x]/x, x, 3, Int[ArcCsch[a + b*x]/x, x]}
(* {ArcCsch[a + b*x]/x^2, x, 0, -((1/(a*x))*(a*ArcCsch[a + b*x] + (1/Sqrt[-1 + a^2])*(b*x*(Sqrt[-1 + a^2]*ArcSin[1/(a + b*x)] + Log[x] - Log[-1 + a^2 + a*b*x + a*Sqrt[-1 + a^2]*Sqrt[(-1 + a^2 + 2*a*b*x + b^2*x^2)/(a + b*x)^2] + Sqrt[-1 + a^2]*b*x*Sqrt[(-1 + a^2 + 2*a*b*x + b^2*x^2)/(a + b*x)^2]]))))} *)


(* Integrands of the form x^m*ArcCsch[Sqrt[x]] where m is an integer *)
{ArcCsch[Sqrt[x]], x, 3, Sqrt[1 + 1/x]*Sqrt[x] + x*ArcCsch[Sqrt[x]]}
{x*ArcCsch[Sqrt[x]], x, 4, (-(1/3))*Sqrt[1 + 1/x]*Sqrt[x] + (1/6)*Sqrt[1 + 1/x]*x^(3/2) + (1/2)*x^2*ArcCsch[Sqrt[x]]}
{x^2*ArcCsch[Sqrt[x]], x, 5, (8/45)*Sqrt[1 + 1/x]*Sqrt[x] - (4/45)*Sqrt[1 + 1/x]*x^(3/2) + (1/15)*Sqrt[1 + 1/x]*x^(5/2) + (1/3)*x^3*ArcCsch[Sqrt[x]]}
{ArcCsch[Sqrt[x]]/x, x, 7, ArcCsch[Sqrt[x]]^2 - 2*ArcCsch[Sqrt[x]]*Log[1 - E^(2*ArcCsch[Sqrt[x]])] - PolyLog[2, E^(2*ArcCsch[Sqrt[x]])]}
{ArcCsch[Sqrt[x]]/x^2, x, 5, Sqrt[1 + 1/x]/(2*Sqrt[x]) - ArcCsch[Sqrt[x]]/2 - ArcCsch[Sqrt[x]]/x}
{ArcCsch[Sqrt[x]]/x^3, x, 6, Sqrt[1 + 1/x]/(8*x^(3/2)) - (3*Sqrt[1 + 1/x])/(16*Sqrt[x]) + (3*ArcCsch[Sqrt[x]])/16 - ArcCsch[Sqrt[x]]/(2*x^2)}


(* ::Subsection::Closed:: *)
(*Integrands involving inverse hyperbolic functions of exponentials*)


{ArcCsch[c*E^(a + b*x)], x, 7, ArcCsch[c*E^(a + b*x)]^2/(2*b) - (ArcCsch[c*E^(a + b*x)]*Log[1 - E^(2*ArcCsch[c*E^(a + b*x)])])/b - PolyLog[2, E^(2*ArcCsch[c*E^(a + b*x)])]/(2*b)}


(* ::Subsection::Closed:: *)
(*Integrands involving exponentials of arccosecants*)


{x^4*E^ArcCsch[x], x, 7, (-(2/15))*Sqrt[1 + 1/x^2]*x + (1/15)*Sqrt[1 + 1/x^2]*x^3 + x^4/4 + (1/5)*Sqrt[1 + 1/x^2]*x^5}
{x^3*E^ArcCsch[x], x, 7, (1/8)*Sqrt[1 + 1/x^2]*x^2 + x^3/3 + (1/4)*Sqrt[1 + 1/x^2]*x^4 - (1/8)*ArcTanh[Sqrt[1 + 1/x^2]]}
{x^2*E^ArcCsch[x], x, 5, x^2/2 + (1/3)*(1 + 1/x^2)^(3/2)*x^3}
{x*E^ArcCsch[x], x, 5, x + (1/2)*Sqrt[1 + 1/x^2]*x^2 + (1/2)*ArcTanh[Sqrt[1 + 1/x^2]]}
{E^ArcCsch[x], x, 6, Sqrt[1 + 1/x^2]*x - ArcCsch[x] + Log[x]}
{E^ArcCsch[x]/x, x, 6, -Sqrt[1 + 1/x^2] - 1/x + ArcTanh[Sqrt[1 + 1/x^2]]}
{E^ArcCsch[x]/x^2, x, 7, -(1/(2*x^2)) - Sqrt[1 + 1/x^2]/(2*x) - ArcCsch[x]/2}
{E^ArcCsch[x]/x^3, x, 6, (-(1/3))*(1 + 1/x^2)^(3/2) - 1/(3*x^3)}
{E^ArcCsch[x]/x^4, x, 8, -(1/(4*x^4)) - Sqrt[1 + 1/x^2]/(4*x^3) - Sqrt[1 + 1/x^2]/(8*x) + ArcCsch[x]/8}
{E^ArcCsch[x]/x^5, x, 7, (2/15)*(1 + 1/x^2)^(3/2) - 1/(5*x^5) - (1 + 1/x^2)^(3/2)/(5*x^2)}


(* ::Subsection::Closed:: *)
(*Miscellaneous integrands involving inverse hyperbolic cosecants*)


{ArcCsch[1/x], x, 1, -Sqrt[1 + x^2] + x*ArcSinh[x]}


{ArcCsch[a + b*x]/((a*d)/b + d*x), x, 9, ArcCsch[a + b*x]^2/(2*d) - (ArcCsch[a + b*x]*Log[1 - E^(2*ArcCsch[a + b*x])])/d - PolyLog[2, E^(2*ArcCsch[a + b*x])]/(2*d)}


{ArcCsch[a*x^n]/x, x, 7, ArcCsch[a*x^n]^2/(2*n) - (ArcCsch[a*x^n]*Log[1 - E^(2*ArcCsch[a*x^n])])/n - PolyLog[2, E^(2*ArcCsch[a*x^n])]/(2*n)}

{ArcCsch[a*x^5]/x, x, 7, (1/10)*ArcCsch[a*x^5]^2 - (1/5)*ArcCsch[a*x^5]*Log[1 - E^(2*ArcCsch[a*x^5])] - (1/10)*PolyLog[2, E^(2*ArcCsch[a*x^5])]}


{x^3*ArcCsch[a + b*x^4], x, 2, ((a + b*x^4)*ArcCsch[a + b*x^4])/(4*b) + ArcTanh[Sqrt[1 + 1/(a + b*x^4)^2]]/(4*b)}

{x^(n-1)*ArcCsch[a + b*x^n], x, 2, ((a + b*x^n)*ArcCsch[a + b*x^n])/(b*n) + ArcTanh[Sqrt[1 + 1/(a + b*x^n)^2]]/(b*n)}
