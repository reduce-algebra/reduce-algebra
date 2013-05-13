(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Inverse Hyperbolic Cosines*)


(* ::Subsection::Closed:: *)
(*Integrands involving inverse hyperbolic cosines*)


(* Integrands of the form ArcCosh[x]^n where n is an integer *)
{ArcCosh[x]^5, x, 3, -120*Sqrt[-1 + x]*Sqrt[1 + x] + 120*x*ArcCosh[x] - 60*Sqrt[-1 + x]*Sqrt[1 + x]*ArcCosh[x]^2 + 20*x*ArcCosh[x]^3 - 5*Sqrt[-1 + x]*Sqrt[1 + x]*ArcCosh[x]^4 + x*ArcCosh[x]^5}
{ArcCosh[x]^4, x, 3, 24*x - 24*Sqrt[-1 + x]*Sqrt[1 + x]*ArcCosh[x] + 12*x*ArcCosh[x]^2 - 4*Sqrt[-1 + x]*Sqrt[1 + x]*ArcCosh[x]^3 + x*ArcCosh[x]^4}
{ArcCosh[x]^3, x, 2, -6*Sqrt[-1 + x]*Sqrt[1 + x] + 6*x*ArcCosh[x] - 3*Sqrt[-1 + x]*Sqrt[1 + x]*ArcCosh[x]^2 + x*ArcCosh[x]^3}
{ArcCosh[x]^2, x, 2, 2*x - 2*Sqrt[-1 + x]*Sqrt[1 + x]*ArcCosh[x] + x*ArcCosh[x]^2}
{ArcCosh[x]^1, x, 1, -(Sqrt[-1 + x]*Sqrt[1 + x]) + x*ArcCosh[x]}
{1/ArcCosh[x]^1, x, 1, SinhIntegral[ArcCosh[x]]}
{1/ArcCosh[x]^2, x, 1, -((Sqrt[-1 + x]*Sqrt[1 + x])/ArcCosh[x]) + CoshIntegral[ArcCosh[x]]}
{1/ArcCosh[x]^3, x, 2, -((Sqrt[-1 + x]*Sqrt[1 + x])/(2*ArcCosh[x]^2)) - x/(2*ArcCosh[x]) + (1/2)*SinhIntegral[ArcCosh[x]]}
{1/ArcCosh[x]^4, x, 2, -((Sqrt[-1 + x]*Sqrt[1 + x])/(3*ArcCosh[x]^3)) - x/(6*ArcCosh[x]^2) - (Sqrt[-1 + x]*Sqrt[1 + x])/(6*ArcCosh[x]) + (1/6)*CoshIntegral[ArcCosh[x]]}
{1/ArcCosh[x]^5, x, 3, -((Sqrt[-1 + x]*Sqrt[1 + x])/(4*ArcCosh[x]^4)) - x/(12*ArcCosh[x]^3) - (Sqrt[-1 + x]*Sqrt[1 + x])/(24*ArcCosh[x]^2) - x/(24*ArcCosh[x]) + (1/24)*SinhIntegral[ArcCosh[x]]}


(* Integrands of the form x^m*ArcCosh[a*x] where m is an integer *)
{x^4*ArcCosh[a*x], x, 4, -((8*Sqrt[-1 + a*x]*Sqrt[1 + a*x])/(75*a^5)) - (4*x^2*Sqrt[-1 + a*x]*Sqrt[1 + a*x])/(75*a^3) - (x^4*Sqrt[-1 + a*x]*Sqrt[1 + a*x])/(25*a) + (1/5)*x^5*ArcCosh[a*x]}
{x^3*ArcCosh[a*x], x, 4, -((3*x*Sqrt[-1 + a*x]*Sqrt[1 + a*x])/(32*a^3)) - (x^3*Sqrt[-1 + a*x]*Sqrt[1 + a*x])/(16*a) - (3*ArcCosh[a*x])/(32*a^4) + (1/4)*x^4*ArcCosh[a*x]}
{x^2*ArcCosh[a*x], x, 3, -((2*Sqrt[-1 + a*x]*Sqrt[1 + a*x])/(9*a^3)) - (x^2*Sqrt[-1 + a*x]*Sqrt[1 + a*x])/(9*a) + (1/3)*x^3*ArcCosh[a*x]}
{x^1*ArcCosh[a*x], x, 3, -((x*Sqrt[-1 + a*x]*Sqrt[1 + a*x])/(4*a)) - ArcCosh[a*x]/(4*a^2) + (1/2)*x^2*ArcCosh[a*x]}
{x^0*ArcCosh[a*x], x, 1, -((Sqrt[-1 + a*x]*Sqrt[1 + a*x])/a) + x*ArcCosh[a*x]}
{ArcCosh[a*x]/x^1, x, 5, (-(1/2))*ArcCosh[a*x]^2 + ArcCosh[a*x]*Log[1 + E^(2*ArcCosh[a*x])] + (1/2)*PolyLog[2, -E^(2*ArcCosh[a*x])]}
{ArcCosh[a*x]/x^2, x, 2, -(ArcCosh[a*x]/x) + 2*a*ArcTan[Sqrt[-1 + a*x]/Sqrt[1 + a*x]]}
{ArcCosh[a*x]/x^3, x, 2, (a*Sqrt[-1 + a*x]*Sqrt[1 + a*x])/(2*x) - ArcCosh[a*x]/(2*x^2)}
{ArcCosh[a*x]/x^4, x, 3, (a*Sqrt[-1 + a*x]*Sqrt[1 + a*x])/(6*x^2) - ArcCosh[a*x]/(3*x^3) + (1/3)*a^3*ArcTan[Sqrt[-1 + a*x]/Sqrt[1 + a*x]]}
{ArcCosh[a*x]/x^5, x, 3, (a*Sqrt[-1 + a*x]*Sqrt[1 + a*x])/(12*x^3) + (a^3*Sqrt[-1 + a*x]*Sqrt[1 + a*x])/(6*x) - ArcCosh[a*x]/(4*x^4)}
{ArcCosh[a*x]/x^6, x, 4, (a*Sqrt[-1 + a*x]*Sqrt[1 + a*x])/(20*x^4) + (3*a^3*Sqrt[-1 + a*x]*Sqrt[1 + a*x])/(40*x^2) - ArcCosh[a*x]/(5*x^5) + (3/20)*a^5*ArcTan[Sqrt[-1 + a*x]/Sqrt[1 + a*x]]}


(* Integrands of the form x^m*ArcCosh[a+b*x] where m is an integer *)
{x^3*ArcCosh[a + b*x], x, 13, (5*a*(11 + 10*a^2)*Sqrt[-1 + a + b*x]*Sqrt[1 + a + b*x])/(96*b^4) - ((9 + 26*a^2)*x*Sqrt[-1 + a + b*x]*Sqrt[1 + a + b*x])/(96*b^3) + (7*a*x^2*Sqrt[-1 + a + b*x]*Sqrt[1 + a + b*x])/(48*b^2) - (x^3*Sqrt[-1 + a + b*x]*Sqrt[1 + a + b*x])/(16*b) + (1/4)*x^4*ArcCosh[a + b*x] - ((3 + 24*a^2 + 8*a^4)*ArcSinh[Sqrt[-1 + a + b*x]/Sqrt[2]])/(16*b^4), (55*a*Sqrt[-1 + a + b*x]*Sqrt[1 + a + b*x])/(96*b^4) + (25*a^3*Sqrt[-1 + a + b*x]*Sqrt[1 + a + b*x])/(48*b^4) - (3*x*Sqrt[-1 + a + b*x]*Sqrt[1 + a + b*x])/(32*b^3) - (13*a^2*x*Sqrt[-1 + a + b*x]*Sqrt[1 + a + b*x])/(48*b^3) + (7*a*x^2*Sqrt[-1 + a + b*x]*Sqrt[1 + a + b*x])/(48*b^2) - (x^3*Sqrt[-1 + a + b*x]*Sqrt[1 + a + b*x])/(16*b) + (1/4)*x^4*ArcCosh[a + b*x] - (15*a^2*ArcSinh[Sqrt[-1 + a + b*x]/Sqrt[2]])/(8*b^4) - (5*a^4*ArcSinh[Sqrt[-1 + a + b*x]/Sqrt[2]])/(16*b^4) - (3*(1 - a^2)^2*ArcSinh[Sqrt[-1 + a + b*x]/Sqrt[2]])/(16*b^4)}
{x^2*ArcCosh[a + b*x], x, 8, -(((4 + 11*a^2)*Sqrt[-1 + a + b*x]*Sqrt[1 + a + b*x])/(18*b^3)) + (5*a*x*Sqrt[-1 + a + b*x]*Sqrt[1 + a + b*x])/(18*b^2) - (x^2*Sqrt[-1 + a + b*x]*Sqrt[1 + a + b*x])/(9*b) + (1/3)*x^3*ArcCosh[a + b*x] + (a*(3 + 2*a^2)*ArcSinh[Sqrt[-1 + a + b*x]/Sqrt[2]])/(3*b^3), -((2*Sqrt[-1 + a + b*x]*Sqrt[1 + a + b*x])/(9*b^3)) - (11*a^2*Sqrt[-1 + a + b*x]*Sqrt[1 + a + b*x])/(18*b^3) + (5*a*x*Sqrt[-1 + a + b*x]*Sqrt[1 + a + b*x])/(18*b^2) - (x^2*Sqrt[-1 + a + b*x]*Sqrt[1 + a + b*x])/(9*b) + (1/3)*x^3*ArcCosh[a + b*x] + (a*ArcSinh[Sqrt[-1 + a + b*x]/Sqrt[2]])/b^3 + (2*a^3*ArcSinh[Sqrt[-1 + a + b*x]/Sqrt[2]])/(3*b^3)}
{x^1*ArcCosh[a + b*x], x, 5, (3*a*Sqrt[-1 + a + b*x]*Sqrt[1 + a + b*x])/(4*b^2) - (x*Sqrt[-1 + a + b*x]*Sqrt[1 + a + b*x])/(4*b) + (1/2)*x^2*ArcCosh[a + b*x] - ((1 + 2*a^2)*ArcSinh[Sqrt[-1 + a + b*x]/Sqrt[2]])/(2*b^2), (3*a*Sqrt[-1 + a + b*x]*Sqrt[1 + a + b*x])/(4*b^2) - (x*Sqrt[-1 + a + b*x]*Sqrt[1 + a + b*x])/(4*b) + (1/2)*x^2*ArcCosh[a + b*x] - ArcSinh[Sqrt[-1 + a + b*x]/Sqrt[2]]/(2*b^2) - (a^2*ArcSinh[Sqrt[-1 + a + b*x]/Sqrt[2]])/b^2}
{x^0*ArcCosh[a + b*x], x, 1, -((Sqrt[-1 + a + b*x]*Sqrt[1 + a + b*x])/b) + ((a + b*x)*ArcCosh[a + b*x])/b}
{ArcCosh[a + b*x]/x^1, x, 3, Subst[Int[(x*Sinh[x])/(-a + Cosh[x]), x], x, ArcCosh[a + b*x]]}
{ArcCosh[a + b*x]/x^2, x, 2, -(ArcCosh[a + b*x]/x) + (2*b*ArcTan[(Sqrt[1 + a]*Sqrt[-1 + a + b*x])/(Sqrt[1 - a]*Sqrt[1 + a + b*x])])/(Sqrt[1 - a]*Sqrt[1 + a])}
{ArcCosh[a + b*x]/x^3, x, 3, (b*Sqrt[-1 + a + b*x]*Sqrt[1 + a + b*x])/(2*(1 - a^2)*x) - ArcCosh[a + b*x]/(2*x^2) + (a*b^2*ArcTan[(Sqrt[1 + a]*Sqrt[-1 + a + b*x])/(Sqrt[1 - a]*Sqrt[1 + a + b*x])])/((1 - a)^(3/2)*(1 + a)^(3/2))}
{ArcCosh[a + b*x]/x^4, x, 5, (b*Sqrt[-1 + a + b*x]*Sqrt[1 + a + b*x])/(6*(1 - a^2)*x^2) + (a*b^2*Sqrt[-1 + a + b*x]*Sqrt[1 + a + b*x])/(2*(1 - a^2)^2*x) - ArcCosh[a + b*x]/(3*x^3) + (a^2*b^3*ArcTan[(Sqrt[1 + a]*Sqrt[-1 + a + b*x])/(Sqrt[1 - a]*Sqrt[1 + a + b*x])])/((1 - a)^(5/2)*(1 + a)^(5/2)) + (b^3*ArcTan[(Sqrt[1 + a]*Sqrt[-1 + a + b*x])/(Sqrt[1 - a]*Sqrt[1 + a + b*x])])/(3*(1 - a)^(3/2)*(1 + a)^(3/2))}


(* Integrands of the form (a+b*ArcCosh[c+d*x])^n *)
{1/Sqrt[a + b*ArcCosh[c + d*x]], x, 5, -((E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcCosh[c + d*x]]/Sqrt[b]])/(2*Sqrt[b]*d)) + (Sqrt[Pi]*Erfi[Sqrt[a + b*ArcCosh[c + d*x]]/Sqrt[b]])/(E^(a/b)*(2*Sqrt[b]*d))}
{1/Sqrt[a - b*ArcCosh[c + d*x]], x, 5, -((E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a - b*ArcCosh[c + d*x]]/Sqrt[b]])/(2*Sqrt[b]*d)) + (Sqrt[Pi]*Erfi[Sqrt[a - b*ArcCosh[c + d*x]]/Sqrt[b]])/(E^(a/b)*(2*Sqrt[b]*d))}


(* Integrands of the form x^m*ArcCosh[Sqrt[x]] where m is an integer *)
{ArcCosh[Sqrt[x]], x, 5, (-(1/2))*Sqrt[-1 + Sqrt[x]]*Sqrt[1 + Sqrt[x]]*Sqrt[x] - ArcCosh[Sqrt[x]]/2 + x*ArcCosh[Sqrt[x]]}
{x*ArcCosh[Sqrt[x]], x, 5, (-(3/16))*Sqrt[-1 + Sqrt[x]]*Sqrt[1 + Sqrt[x]]*Sqrt[x] - (1/8)*Sqrt[-1 + Sqrt[x]]*Sqrt[1 + Sqrt[x]]*x^(3/2) - (3*ArcCosh[Sqrt[x]])/16 + (1/2)*x^2*ArcCosh[Sqrt[x]]}
{x^2*ArcCosh[Sqrt[x]], x, 6, (-(5/48))*Sqrt[-1 + Sqrt[x]]*Sqrt[1 + Sqrt[x]]*Sqrt[x] - (5/72)*Sqrt[-1 + Sqrt[x]]*Sqrt[1 + Sqrt[x]]*x^(3/2) - (1/18)*Sqrt[-1 + Sqrt[x]]*Sqrt[1 + Sqrt[x]]*x^(5/2) - (5*ArcCosh[Sqrt[x]])/48 + (1/3)*x^3*ArcCosh[Sqrt[x]]}
{ArcCosh[Sqrt[x]]/x, x, 5, -ArcCosh[Sqrt[x]]^2 + 2*ArcCosh[Sqrt[x]]*Log[1 + E^(2*ArcCosh[Sqrt[x]])] + PolyLog[2, -E^(2*ArcCosh[Sqrt[x]])]}
{ArcCosh[Sqrt[x]]/x^2, x, 3, (Sqrt[-1 + Sqrt[x]]*Sqrt[1 + Sqrt[x]])/Sqrt[x] - ArcCosh[Sqrt[x]]/x}
{ArcCosh[Sqrt[x]]/x^3, x, 4, (Sqrt[-1 + Sqrt[x]]*Sqrt[1 + Sqrt[x]])/(6*x^(3/2)) + (Sqrt[-1 + Sqrt[x]]*Sqrt[1 + Sqrt[x]])/(3*Sqrt[x]) - ArcCosh[Sqrt[x]]/(2*x^2)}


(* ::Subsection::Closed:: *)
(*x^m ArcCosh[c E^(a+b x)]*)


{ArcCosh[c*E^(a + b*x)], x, 6, -(ArcCosh[c*E^(a + b*x)]^2/(2*b)) + (ArcCosh[c*E^(a + b*x)]*Log[1 + E^(2*ArcCosh[c*E^(a + b*x)])])/b + PolyLog[2, -E^(2*ArcCosh[c*E^(a + b*x)])]/(2*b)}


(* ::Subsection::Closed:: *)
(*x^m E^ArcCosh[a x]*)


{x^3*E^ArcCosh[x], x, 6, x^5/5 + (2/15)*(-1 + x)^(3/2)*(1 + x)^(3/2) + (1/5)*(-1 + x)^(3/2)*x^2*(1 + x)^(3/2)}
{x^2*E^ArcCosh[x], x, 8, x^4/4 + (1/8)*Sqrt[-1 + x]*Sqrt[1 + x] + (1/8)*(-1 + x)^(3/2)*Sqrt[1 + x] + (1/4)*(-1 + x)^(3/2)*x*(1 + x)^(3/2) - ArcCosh[x]/8}
{x*E^ArcCosh[x], x, 5, x^3/3 + (1/3)*(-1 + x)^(3/2)*(1 + x)^(3/2)}
{E^ArcCosh[x], x, 6, x^2/2 + (1/2)*Sqrt[-1 + x]*x*Sqrt[1 + x] - ArcCosh[x]/2, x^2/2 + (1/2)*Sqrt[-1 + x]*Sqrt[1 + x] + (1/2)*(-1 + x)^(3/2)*Sqrt[1 + x] - ArcCosh[x]/2}
{E^ArcCosh[x]/x, x, 5, x + Sqrt[-1 + x]*Sqrt[1 + x] - 2*ArcTan[Sqrt[-1 + x]/Sqrt[1 + x]]}
{E^ArcCosh[x]/x^2, x, 8, -((Sqrt[-1 + x]*Sqrt[1 + x])/x) + ArcCosh[x] + Log[x], (-Sqrt[-1 + x])*Sqrt[1 + x] - (-1 + x)^(3/2)*Sqrt[1 + x] + ((-1 + x)^(3/2)*(1 + x)^(3/2))/x + ArcCosh[x] + Log[x]}
{E^ArcCosh[x]/x^3, x, 7, -(1/x) - (1/2)*Sqrt[-1 + x]*Sqrt[1 + x] + ((-1 + x)^(3/2)*(1 + x)^(3/2))/(2*x^2) + ArcTan[Sqrt[-1 + x]/Sqrt[1 + x]]}


(* ::Subsection::Closed:: *)
(*Miscellaneous integrands involving inverse hyperbolic cosine*)


{ArcCosh[1/x], x, 1, x*ArcSech[x] - 2*ArcTan[Sqrt[(1 - x)/(1 + x)]]}


{ArcCosh[a + b*x]/((a*d)/b + d*x), x, 8, -(ArcCosh[a + b*x]^2/(2*d)) + (ArcCosh[a + b*x]*Log[1 + E^(2*ArcCosh[a + b*x])])/d + PolyLog[2, -E^(2*ArcCosh[a + b*x])]/(2*d)}


{x/(Sqrt[-1 + x]*Sqrt[1 + x]*ArcCosh[x]), x, -3, CoshIntegral[ArcCosh[x]]}


{ArcCosh[a*x^n]/x, x, 5, -(ArcCosh[a*x^n]^2/(2*n)) + (ArcCosh[a*x^n]*Log[1 + E^(2*ArcCosh[a*x^n])])/n + PolyLog[2, -E^(2*ArcCosh[a*x^n])]/(2*n)}

{ArcCosh[a*x^5]/x, x, 5, (-(1/10))*ArcCosh[a*x^5]^2 + (1/5)*ArcCosh[a*x^5]*Log[1 + E^(2*ArcCosh[a*x^5])] + (1/10)*PolyLog[2, -E^(2*ArcCosh[a*x^5])]}


{x^3*ArcCosh[a + b*x^4], x, 2, -((Sqrt[-1 + a + b*x^4]*Sqrt[1 + a + b*x^4])/(4*b)) + ((a + b*x^4)*ArcCosh[a + b*x^4])/(4*b)}

{x^(n-1)*ArcCosh[a + b*x^n], x, 2, -((Sqrt[-1 + a + b*x^n]*Sqrt[1 + a + b*x^n])/(b*n)) + ((a + b*x^n)*ArcCosh[a + b*x^n])/(b*n)}


{ArcCosh[c/(a + b*x)], x, 2, ((a + b*x)*ArcSech[a/c + (b*x)/c])/b - (2*c*ArcTan[Sqrt[(1 - a/c - (b*x)/c)/(1 + a/c + (b*x)/c)]])/b}
