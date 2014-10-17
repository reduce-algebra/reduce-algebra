(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Inverse Hyperbolic Sines*)


(* ::Subsection::Closed:: *)
(*Integrands involving inverse hyperbolic sines*)


(* Integrands of the form ArcSinh[x]^n where n is an integer *)
{ArcSinh[x]^5, x, 3, -120*Sqrt[1 + x^2] + 120*x*ArcSinh[x] - 60*Sqrt[1 + x^2]*ArcSinh[x]^2 + 20*x*ArcSinh[x]^3 - 5*Sqrt[1 + x^2]*ArcSinh[x]^4 + x*ArcSinh[x]^5}
{ArcSinh[x]^4, x, 3, 24*x - 24*Sqrt[1 + x^2]*ArcSinh[x] + 12*x*ArcSinh[x]^2 - 4*Sqrt[1 + x^2]*ArcSinh[x]^3 + x*ArcSinh[x]^4}
{ArcSinh[x]^3, x, 2, -6*Sqrt[1 + x^2] + 6*x*ArcSinh[x] - 3*Sqrt[1 + x^2]*ArcSinh[x]^2 + x*ArcSinh[x]^3}
{ArcSinh[x]^2, x, 2, 2*x - 2*Sqrt[1 + x^2]*ArcSinh[x] + x*ArcSinh[x]^2}
{ArcSinh[x]^1, x, 1, -Sqrt[1 + x^2] + x*ArcSinh[x]}
{1/ArcSinh[x]^1, x, 1, CoshIntegral[ArcSinh[x]]}
{1/ArcSinh[x]^2, x, 1, -(Sqrt[1 + x^2]/ArcSinh[x]) + SinhIntegral[ArcSinh[x]]}
{1/ArcSinh[x]^3, x, 2, -(Sqrt[1 + x^2]/(2*ArcSinh[x]^2)) - x/(2*ArcSinh[x]) + (1/2)*CoshIntegral[ArcSinh[x]]}
{1/ArcSinh[x]^4, x, 2, -(Sqrt[1 + x^2]/(3*ArcSinh[x]^3)) - x/(6*ArcSinh[x]^2) - Sqrt[1 + x^2]/(6*ArcSinh[x]) + (1/6)*SinhIntegral[ArcSinh[x]]}
{1/ArcSinh[x]^5, x, 3, -(Sqrt[1 + x^2]/(4*ArcSinh[x]^4)) - x/(12*ArcSinh[x]^3) - Sqrt[1 + x^2]/(24*ArcSinh[x]^2) - x/(24*ArcSinh[x]) + (1/24)*CoshIntegral[ArcSinh[x]]}


(* Integrands of the form x^m*ArcSinh[a*x] where m is an integer *)
{x^4*ArcSinh[a*x], x, 5, -((8*Sqrt[1 + a^2*x^2])/(75*a^5)) + (4*x^2*Sqrt[1 + a^2*x^2])/(75*a^3) - (x^4*Sqrt[1 + a^2*x^2])/(25*a) + (1/5)*x^5*ArcSinh[a*x]}
{x^3*ArcSinh[a*x], x, 4, (3*x*Sqrt[1 + a^2*x^2])/(32*a^3) - (x^3*Sqrt[1 + a^2*x^2])/(16*a) - (3*ArcSinh[a*x])/(32*a^4) + (1/4)*x^4*ArcSinh[a*x]}
{x^2*ArcSinh[a*x], x, 4, (2*Sqrt[1 + a^2*x^2])/(9*a^3) - (x^2*Sqrt[1 + a^2*x^2])/(9*a) + (1/3)*x^3*ArcSinh[a*x]}
{x^1*ArcSinh[a*x], x, 3, -((x*Sqrt[1 + a^2*x^2])/(4*a)) + ArcSinh[a*x]/(4*a^2) + (1/2)*x^2*ArcSinh[a*x]}
{x^0*ArcSinh[a*x], x, 1, -(Sqrt[1 + a^2*x^2]/a) + x*ArcSinh[a*x]}
{ArcSinh[a*x]/x^1, x, 5, (-(1/2))*ArcSinh[a*x]^2 + ArcSinh[a*x]*Log[1 - E^(2*ArcSinh[a*x])] + (1/2)*PolyLog[2, E^(2*ArcSinh[a*x])]}
{ArcSinh[a*x]/x^2, x, 2, -(ArcSinh[a*x]/x) - a*ArcTanh[Sqrt[1 + a^2*x^2]]}
{ArcSinh[a*x]/x^3, x, 2, -((a*Sqrt[1 + a^2*x^2])/(2*x)) - ArcSinh[a*x]/(2*x^2)}
{ArcSinh[a*x]/x^4, x, 3, -((a*Sqrt[1 + a^2*x^2])/(6*x^2)) - ArcSinh[a*x]/(3*x^3) + (1/6)*a^3*ArcTanh[Sqrt[1 + a^2*x^2]]}
{ArcSinh[a*x]/x^5, x, 3, -((a*Sqrt[1 + a^2*x^2])/(12*x^3)) + (a^3*Sqrt[1 + a^2*x^2])/(6*x) - ArcSinh[a*x]/(4*x^4)}
{ArcSinh[a*x]/x^6, x, 4, -((a*Sqrt[1 + a^2*x^2])/(20*x^4)) + (3*a^3*Sqrt[1 + a^2*x^2])/(40*x^2) - ArcSinh[a*x]/(5*x^5) - (3/40)*a^5*ArcTanh[Sqrt[1 + a^2*x^2]]}


(* Integrands of the form x^m*ArcSinh[a+b*x] where m is an integer *)
{x^3*ArcSinh[a + b*x], x, 13, (5*a*(-11 + 10*a^2)*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(96*b^4) + ((9 - 26*a^2)*x*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(96*b^3) + (7*a*x^2*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(48*b^2) - (x^3*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(16*b) - ((3 - 24*a^2 + 8*a^4)*ArcSinh[a + b*x])/(32*b^4) + (1/4)*x^4*ArcSinh[a + b*x], -((55*a*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(96*b^4)) + (25*a^3*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(48*b^4) + (3*x*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(32*b^3) - (13*a^2*x*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(48*b^3) + (7*a*x^2*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(48*b^2) - (x^3*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(16*b) + (15*a^2*ArcSinh[a + b*x])/(16*b^4) - (5*a^4*ArcSinh[a + b*x])/(32*b^4) - (3*(1 + a^2)^2*ArcSinh[a + b*x])/(32*b^4) + (1/4)*x^4*ArcSinh[a + b*x]}
{x^2*ArcSinh[a + b*x], x, 8, ((4 - 11*a^2)*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(18*b^3) + (5*a*x*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(18*b^2) - (x^2*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(9*b) - (a*(3 - 2*a^2)*ArcSinh[a + b*x])/(6*b^3) + (1/3)*x^3*ArcSinh[a + b*x], (2*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(9*b^3) - (11*a^2*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(18*b^3) + (5*a*x*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(18*b^2) - (x^2*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(9*b) - (a*ArcSinh[a + b*x])/(2*b^3) + (a^3*ArcSinh[a + b*x])/(3*b^3) + (1/3)*x^3*ArcSinh[a + b*x]}
{x^1*ArcSinh[a + b*x], x, 5, (3*a*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(4*b^2) - (x*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(4*b) + ((1 - 2*a^2)*ArcSinh[a + b*x])/(4*b^2) + (1/2)*x^2*ArcSinh[a + b*x], (3*a*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(4*b^2) - (x*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(4*b) + ArcSinh[a + b*x]/(4*b^2) - (a^2*ArcSinh[a + b*x])/(2*b^2) + (1/2)*x^2*ArcSinh[a + b*x]}
{ArcSinh[a + b*x]/x^1, x, 3, Subst[Int[(x*Cosh[x])/(-a + Sinh[x]), x], x, ArcSinh[a + b*x]]}
{ArcSinh[a + b*x]/x^2, x, 2, -(ArcSinh[a + b*x]/x) - (b*ArcTanh[(1 + a^2 + a*b*x)/(Sqrt[1 + a^2]*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])])/Sqrt[1 + a^2]}
{ArcSinh[a + b*x]/x^3, x, 3, -((b*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(2*(1 + a^2)*x)) - ArcSinh[a + b*x]/(2*x^2) + (a*b^2*ArcTanh[(1 + a^2 + a*b*x)/(Sqrt[1 + a^2]*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])])/(2*(1 + a^2)^(3/2))}
{ArcSinh[a + b*x]/x^4, x, 5, -((b*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(6*(1 + a^2)*x^2)) + (a*b^2*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(2*(1 + a^2)^2*x) - ArcSinh[a + b*x]/(3*x^3) - (a^2*b^3*ArcTanh[(1 + a^2 + a*b*x)/(Sqrt[1 + a^2]*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])])/(2*(1 + a^2)^(5/2)) + (b^3*ArcTanh[(1 + a^2 + a*b*x)/(Sqrt[1 + a^2]*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])])/(6*(1 + a^2)^(3/2))}


(* Integrands of the form (a+b*ArcSinh[c+d*x])^n *)
{1/Sqrt[a + b*ArcSinh[c + d*x]], x, 5, (E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(2*Sqrt[b]*d) + (Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(E^(a/b)*(2*Sqrt[b]*d))}
{1/Sqrt[a - b*ArcSinh[c + d*x]], x, 5, -((E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a - b*ArcSinh[c + d*x]]/Sqrt[b]])/(2*Sqrt[b]*d)) - (Sqrt[Pi]*Erfi[Sqrt[a - b*ArcSinh[c + d*x]]/Sqrt[b]])/(E^(a/b)*(2*Sqrt[b]*d))}


(* Integrands of the form x^m*ArcSinh[Sqrt[x]] where m is an integer *)
{ArcSinh[Sqrt[x]], x, 4, (-(1/2))*Sqrt[x]*Sqrt[1 + x] + ArcSinh[Sqrt[x]]/2 + x*ArcSinh[Sqrt[x]]}
{x*ArcSinh[Sqrt[x]], x, 5, (3/16)*Sqrt[x]*Sqrt[1 + x] - (1/8)*x^(3/2)*Sqrt[1 + x] - (3*ArcSinh[Sqrt[x]])/16 + (1/2)*x^2*ArcSinh[Sqrt[x]]}
{x^2*ArcSinh[Sqrt[x]], x, 6, (-(5/48))*Sqrt[x]*Sqrt[1 + x] + (5/72)*x^(3/2)*Sqrt[1 + x] - (1/18)*x^(5/2)*Sqrt[1 + x] + (5*ArcSinh[Sqrt[x]])/48 + (1/3)*x^3*ArcSinh[Sqrt[x]]}
{ArcSinh[Sqrt[x]]/x, x, 5, -ArcSinh[Sqrt[x]]^2 + 2*ArcSinh[Sqrt[x]]*Log[1 - E^(2*ArcSinh[Sqrt[x]])] + PolyLog[2, E^(2*ArcSinh[Sqrt[x]])]}
{ArcSinh[Sqrt[x]]/x^2, x, 3, -(Sqrt[1 + x]/Sqrt[x]) - ArcSinh[Sqrt[x]]/x}
{ArcSinh[Sqrt[x]]/x^3, x, 4, -(Sqrt[1 + x]/(6*x^(3/2))) + Sqrt[1 + x]/(3*Sqrt[x]) - ArcSinh[Sqrt[x]]/(2*x^2)}


(* ::Subsection::Closed:: *)
(*x^m ArcSinh[c E^(a+b x)]*)


{ArcSinh[c*E^(a + b*x)], x, 6, -(ArcSinh[c*E^(a + b*x)]^2/(2*b)) + (ArcSinh[c*E^(a + b*x)]*Log[1 - E^(2*ArcSinh[c*E^(a + b*x)])])/b + PolyLog[2, E^(2*ArcSinh[c*E^(a + b*x)])]/(2*b)}


(* ::Subsection::Closed:: *)
(*x^m E^ArcSinh[a x]*)


{x^3*E^ArcSinh[x], x, 7, x^5/5 - (2/15)*(1 + x^2)^(3/2) + (1/5)*x^2*(1 + x^2)^(3/2)}
{x^2*E^ArcSinh[x], x, 7, x^4/4 + (1/8)*x*Sqrt[1 + x^2] + (1/4)*x^3*Sqrt[1 + x^2] - ArcSinh[x]/8}
{x*E^ArcSinh[x], x, 6, x^3/3 + (1 + x^2)^(3/2)/3}
{E^ArcSinh[x], x, 5, x^2/2 + (1/2)*x*Sqrt[1 + x^2] + ArcSinh[x]/2}
{E^ArcSinh[x]/x, x, 5, x + Sqrt[1 + x^2] - ArcTanh[Sqrt[1 + x^2]]}
{E^ArcSinh[x]/x^2, x, 6, -(Sqrt[1 + x^2]/x) + ArcSinh[x] + Log[x]}
{E^ArcSinh[x]/x^3, x, 6, -(1/x) - Sqrt[1 + x^2]/(2*x^2) - (1/2)*ArcTanh[Sqrt[1 + x^2]]}


(* ::Subsection::Closed:: *)
(*Miscellaneous integrands involving inverse hyperbolic sines*)


{ArcSinh[1/x], x, 1, x*ArcCsch[x] + ArcTanh[Sqrt[1 + x^(-2)]]}


{ArcSinh[a + b*x]/((a*d)/b + d*x), x, 8, -(ArcSinh[a + b*x]^2/(2*d)) + (ArcSinh[a + b*x]*Log[1 - E^(2*ArcSinh[a + b*x])])/d + PolyLog[2, E^(2*ArcSinh[a + b*x])]/(2*d)}


{x/(Sqrt[1 + x^2]*ArcSinh[x]), x, 2, SinhIntegral[ArcSinh[x]]}


{ArcSinh[a*x^n]/x, x, 5, -(ArcSinh[a*x^n]^2/(2*n)) + (ArcSinh[a*x^n]*Log[1 - E^(2*ArcSinh[a*x^n])])/n + PolyLog[2, E^(2*ArcSinh[a*x^n])]/(2*n)}

{ArcSinh[a*x^5]/x, x, 5, (-(1/10))*ArcSinh[a*x^5]^2 + (1/5)*ArcSinh[a*x^5]*Log[1 - E^(2*ArcSinh[a*x^5])] + (1/10)*PolyLog[2, E^(2*ArcSinh[a*x^5])]}


{x^3*ArcSinh[a + b*x^4], x, 2, -(Sqrt[1 + (a + b*x^4)^2]/(4*b)) + ((a + b*x^4)*ArcSinh[a + b*x^4])/(4*b)}

{x^(n-1)*ArcSinh[a + b*x^n], x, 2, -(Sqrt[1 + (a + b*x^n)^2]/(b*n)) + ((a + b*x^n)*ArcSinh[a + b*x^n])/(b*n)}


{ArcSinh[c/(a + b*x)], x, 2, ((a + b*x)*ArcCsch[a/c + (b*x)/c])/b + (c*ArcTanh[Sqrt[1 + c^2/(a + b*x)^2]])/b}
