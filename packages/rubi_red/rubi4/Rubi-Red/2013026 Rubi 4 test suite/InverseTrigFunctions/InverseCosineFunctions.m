(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Inverse Cosines*)


(* ::Section::Closed:: *)
(*Integrands of the form u ArcCos[a x^n]^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcCos[a x]^n*)


{x^4*ArcCos[a*x], x, 4, -((8*Sqrt[1 - a^2*x^2])/(75*a^5)) - (4*x^2*Sqrt[1 - a^2*x^2])/(75*a^3) - (x^4*Sqrt[1 - a^2*x^2])/(25*a) + (1/5)*x^5*ArcCos[a*x]}
{x^3*ArcCos[a*x], x, 4, -((3*x*Sqrt[1 - a^2*x^2])/(32*a^3)) - (x^3*Sqrt[1 - a^2*x^2])/(16*a) + (1/4)*x^4*ArcCos[a*x] + (3*ArcSin[a*x])/(32*a^4)}
{x^2*ArcCos[a*x], x, 3, -((2*Sqrt[1 - a^2*x^2])/(9*a^3)) - (x^2*Sqrt[1 - a^2*x^2])/(9*a) + (1/3)*x^3*ArcCos[a*x]}
{x^1*ArcCos[a*x], x, 3, -((x*Sqrt[1 - a^2*x^2])/(4*a)) + (1/2)*x^2*ArcCos[a*x] + ArcSin[a*x]/(4*a^2)}
{x^0*ArcCos[a*x], x, 1, -(Sqrt[1 - a^2*x^2]/a) + x*ArcCos[a*x]}
{ArcCos[a*x]/x^1, x, 5, (-(1/2))*I*ArcCos[a*x]^2 + ArcCos[a*x]*Log[1 + E^(2*I*ArcCos[a*x])] - (1/2)*I*PolyLog[2, -E^(2*I*ArcCos[a*x])]}
{ArcCos[a*x]/x^2, x, 3, -(ArcCos[a*x]/x) + a*ArcTanh[Sqrt[1 - a^2*x^2]]}
{ArcCos[a*x]/x^3, x, 2, (a*Sqrt[1 - a^2*x^2])/(2*x) - ArcCos[a*x]/(2*x^2)}
{ArcCos[a*x]/x^4, x, 4, (a*Sqrt[1 - a^2*x^2])/(6*x^2) - ArcCos[a*x]/(3*x^3) + (1/6)*a^3*ArcTanh[Sqrt[1 - a^2*x^2]]}


{x^4*ArcCos[a*x]^2, x, 7, -((16*x)/(75*a^4)) - (8*x^3)/(225*a^2) - (2*x^5)/125 - (16*Sqrt[1 - a^2*x^2]*ArcCos[a*x])/(75*a^5) - (8*x^2*Sqrt[1 - a^2*x^2]*ArcCos[a*x])/(75*a^3) - (2*x^4*Sqrt[1 - a^2*x^2]*ArcCos[a*x])/(25*a) + (1/5)*x^5*ArcCos[a*x]^2}
{x^3*ArcCos[a*x]^2, x, 6, -((3*x^2)/(32*a^2)) - x^4/32 - (3*x*Sqrt[1 - a^2*x^2]*ArcCos[a*x])/(16*a^3) - (x^3*Sqrt[1 - a^2*x^2]*ArcCos[a*x])/(8*a) - (3*ArcCos[a*x]^2)/(32*a^4) + (1/4)*x^4*ArcCos[a*x]^2}
{x^2*ArcCos[a*x]^2, x, 5, -((4*x)/(9*a^2)) - (2*x^3)/27 - (4*Sqrt[1 - a^2*x^2]*ArcCos[a*x])/(9*a^3) - (2*x^2*Sqrt[1 - a^2*x^2]*ArcCos[a*x])/(9*a) + (1/3)*x^3*ArcCos[a*x]^2}
{x^1*ArcCos[a*x]^2, x, 4, -(x^2/4) - (x*Sqrt[1 - a^2*x^2]*ArcCos[a*x])/(2*a) - ArcCos[a*x]^2/(4*a^2) + (1/2)*x^2*ArcCos[a*x]^2}
{x^0*ArcCos[a*x]^2, x, 2, -2*x - (2*Sqrt[1 - a^2*x^2]*ArcCos[a*x])/a + x*ArcCos[a*x]^2}
{ArcCos[a*x]^2/x^1, x, 6, (-(1/3))*I*ArcCos[a*x]^3 + ArcCos[a*x]^2*Log[1 + E^(2*I*ArcCos[a*x])] - I*ArcCos[a*x]*PolyLog[2, -E^(2*I*ArcCos[a*x])] + (1/2)*PolyLog[3, -E^(2*I*ArcCos[a*x])]}
{ArcCos[a*x]^2/x^2, x, 2, -(ArcCos[a*x]^2/x) - 4*I*a*ArcCos[a*x]*ArcTan[a*x + I*Sqrt[1 - a^2*x^2]] - 2*I*a*PolyLog[2, I*a*x - Sqrt[1 - a^2*x^2]] + 2*I*a*PolyLog[2, (-I)*a*x + Sqrt[1 - a^2*x^2]]}
{ArcCos[a*x]^2/x^3, x, 3, (a*Sqrt[1 - a^2*x^2]*ArcCos[a*x])/x - ArcCos[a*x]^2/(2*x^2) + a^2*Log[x]}
{ArcCos[a*x]^2/x^4, x, 4, -(a^2/(3*x)) + (a*Sqrt[1 - a^2*x^2]*ArcCos[a*x])/(3*x^2) - ArcCos[a*x]^2/(3*x^3) - (2/3)*I*a^3*ArcCos[a*x]*ArcTan[a*x + I*Sqrt[1 - a^2*x^2]] - (1/3)*I*a^3*PolyLog[2, I*a*x - Sqrt[1 - a^2*x^2]] + (1/3)*I*a^3*PolyLog[2, (-I)*a*x + Sqrt[1 - a^2*x^2]]}
{ArcCos[a*x]^2/x^5, x, 5, -(a^2/(12*x^2)) + (a*Sqrt[1 - a^2*x^2]*ArcCos[a*x])/(6*x^3) + (a^3*Sqrt[1 - a^2*x^2]*ArcCos[a*x])/(3*x) - ArcCos[a*x]^2/(4*x^4) + (1/3)*a^4*Log[x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcCos[a x^n]*)


{x^3*ArcCos[a*x^2], x, 5, -((x^2*Sqrt[1 - a^2*x^4])/(8*a)) + (1/4)*x^4*ArcCos[a*x^2] + ArcSin[a*x^2]/(8*a^2)}
{x^2*ArcCos[a*x^2], x, 4, -((2*x*Sqrt[1 - a^2*x^4])/(9*a)) + (1/3)*x^3*ArcCos[a*x^2] + (2*EllipticF[ArcSin[Sqrt[a]*x], -1])/(9*a^(3/2))}
{x^1*ArcCos[a*x^2], x, 2, -(Sqrt[1 - a^2*x^4]/(2*a)) + (1/2)*x^2*ArcCos[a*x^2]}
{x^0*ArcCos[a*x^2], x, 3, x*ArcCos[a*x^2] + (2*EllipticE[ArcSin[Sqrt[a]*x], -1])/Sqrt[a] - (2*EllipticF[ArcSin[Sqrt[a]*x], -1])/Sqrt[a]}
{ArcCos[a*x^2]/x^1, x, 5, (-(1/4))*I*ArcCos[a*x^2]^2 + (1/2)*ArcCos[a*x^2]*Log[1 + E^(2*I*ArcCos[a*x^2])] - (1/4)*I*PolyLog[2, -E^(2*I*ArcCos[a*x^2])]}
{ArcCos[a*x^2]/x^2, x, 3, -(ArcCos[a*x^2]/x) - 2*Sqrt[a]*EllipticF[ArcSin[Sqrt[a]*x], -1]}


{x^2*ArcCos[a/x], x, 5, (-(1/6))*a*Sqrt[1 - a^2/x^2]*x^2 + (1/3)*x^3*ArcSec[x/a] - (1/6)*a^3*ArcTanh[Sqrt[1 - a^2/x^2]]}
{x^1*ArcCos[a/x], x, 3, (-(1/2))*a*Sqrt[1 - a^2/x^2]*x + (1/2)*x^2*ArcSec[x/a]}
{x^0*ArcCos[a/x], x, 4, x*ArcSec[x/a] - a*ArcTanh[Sqrt[1 - a^2/x^2]]}
{ArcCos[a/x]/x^1, x, 5, (1/2)*I*ArcCos[a/x]^2 - ArcCos[a/x]*Log[1 + E^(2*I*ArcCos[a/x])] + (1/2)*I*PolyLog[2, -E^(2*I*ArcCos[a/x])]}
{ArcCos[a/x]/x^2, x, 3, Sqrt[1 - a^2/x^2]/a - ArcSec[x/a]/x}
{ArcCos[a/x]/x^3, x, 5, Sqrt[1 - a^2/x^2]/(4*a*x) - ArcSec[x/a]/(2*x^2) - ArcSin[a/x]/(4*a^2)}
{ArcCos[a/x]/x^4, x, 5, (2*Sqrt[1 - a^2/x^2])/(9*a^3) + Sqrt[1 - a^2/x^2]/(9*a*x^2) - ArcSec[x/a]/(3*x^3)}


{x^2*ArcCos[Sqrt[x]], x, 6, (-(5/48))*Sqrt[1 - x]*Sqrt[x] - (5/72)*Sqrt[1 - x]*x^(3/2) - (1/18)*Sqrt[1 - x]*x^(5/2) + (1/3)*x^3*ArcCos[Sqrt[x]] - (5/96)*ArcSin[1 - 2*x]}
{x^1*ArcCos[Sqrt[x]], x, 5, (-(3/16))*Sqrt[1 - x]*Sqrt[x] - (1/8)*Sqrt[1 - x]*x^(3/2) + (1/2)*x^2*ArcCos[Sqrt[x]] - (3/32)*ArcSin[1 - 2*x]}
{x^0*ArcCos[Sqrt[x]], x, 4, (-(1/2))*Sqrt[1 - x]*Sqrt[x] + x*ArcCos[Sqrt[x]] - (1/4)*ArcSin[1 - 2*x]}
{ArcCos[Sqrt[x]]/x^1, x, 5, (-I)*ArcCos[Sqrt[x]]^2 + 2*ArcCos[Sqrt[x]]*Log[1 + E^(2*I*ArcCos[Sqrt[x]])] - I*PolyLog[2, -E^(2*I*ArcCos[Sqrt[x]])]}
{ArcCos[Sqrt[x]]/x^2, x, 3, Sqrt[1 - x]/Sqrt[x] - ArcCos[Sqrt[x]]/x}
{ArcCos[Sqrt[x]]/x^3, x, 4, Sqrt[1 - x]/(6*x^(3/2)) + Sqrt[1 - x]/(3*Sqrt[x]) - ArcCos[Sqrt[x]]/(2*x^2)}
{ArcCos[Sqrt[x]]/x^4, x, 5, Sqrt[1 - x]/(15*x^(5/2)) + (4*Sqrt[1 - x])/(45*x^(3/2)) + (8*Sqrt[1 - x])/(45*Sqrt[x]) - ArcCos[Sqrt[x]]/(3*x^3)}
{ArcCos[Sqrt[x]]/x^5, x, 6, Sqrt[1 - x]/(28*x^(7/2)) + (3*Sqrt[1 - x])/(70*x^(5/2)) + (2*Sqrt[1 - x])/(35*x^(3/2)) + (4*Sqrt[1 - x])/(35*Sqrt[x]) - ArcCos[Sqrt[x]]/(4*x^4)}


{ArcCos[Sqrt[x]]/Sqrt[x], x, 2, -2*Sqrt[1 - x] + 2*Sqrt[x]*ArcCos[Sqrt[x]]}


{ArcCos[a*x^n]/x, x, 5, -((I*ArcCos[a*x^n]^2)/(2*n)) + (ArcCos[a*x^n]*Log[1 + E^(2*I*ArcCos[a*x^n])])/n - (I*PolyLog[2, -E^(2*I*ArcCos[a*x^n])])/(2*n)}
{ArcCos[a*x^5]/x, x, 5, (-(1/10))*I*ArcCos[a*x^5]^2 + (1/5)*ArcCos[a*x^5]*Log[1 + E^(2*I*ArcCos[a*x^5])] - (1/10)*I*PolyLog[2, -E^(2*I*ArcCos[a*x^5])]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcCos[a x]^p (1-a^2 x^2)^(n/2)*)


{Sqrt[1 - x^2]*ArcCos[x], x, 3, x^2/4 + (1/2)*x*Sqrt[1 - x^2]*ArcCos[x] - ArcCos[x]^2/4, (1/4)*(-1 + x^2) + (1/2)*x*Sqrt[1 - x^2]*ArcCos[x] - ArcCos[x]^2/4}


{x/(Sqrt[1 - x^2]*Sqrt[ArcCos[x]]), x, 2, -Sqrt[2*Pi]*FresnelC[Sqrt[2/Pi]*Sqrt[ArcCos[x]]]}
{x/(Sqrt[1 - x^2]*ArcCos[x]), x, 2, -CosIntegral[ArcCos[x]]}


(* ::Section::Closed:: *)
(*Integrands of the form u ArcCos[a+b x]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcCos[a+b x]^n*)


{x^3*ArcCos[a + b*x], x, 7, (a*(41 + 64*a^2)*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(96*b^4) + (7*a*x^2*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(48*b^2) - (x^3*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(16*b) + ((14*a*(1 - a^2) - (9 + 26*a^2)*b*x)*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(96*b^4) + (1/4)*x^4*ArcCos[a + b*x] + ((3 + 24*a^2 + 8*a^4)*ArcSin[a + b*x])/(32*b^4)}
{x^2*ArcCos[a + b*x], x, 6, -(((2 + 13*a^2)*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(18*b^3)) - (x^2*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(9*b) - ((2*(1 - a^2) - 5*a*b*x)*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(18*b^3) + (1/3)*x^3*ArcCos[a + b*x] - (a*(3 + 2*a^2)*ArcSin[a + b*x])/(6*b^3)}
{x^1*ArcCos[a + b*x], x, 5, (3*a*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(4*b^2) - (x*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(4*b) + (1/2)*x^2*ArcCos[a + b*x] + ((1 + 2*a^2)*ArcSin[a + b*x])/(4*b^2)}
{x^0*ArcCos[a + b*x], x, 1, -(Sqrt[1 - (a + b*x)^2]/b) + ((a + b*x)*ArcCos[a + b*x])/b}
{ArcCos[a + b*x]/x^1, x, -2, (-(1/8))*I*(Pi - 2*ArcSin[a + b*x])^2 + 2*I*ArcTanh[((1 + a)*(-1 + a + b*x - I*Sqrt[1 - (a + b*x)^2]))/(Sqrt[-1 + a^2]*(1 + a + b*x - I*Sqrt[1 - (a + b*x)^2]))]*(Log[2] - 2*Log[I*Sqrt[1 - a] + Sqrt[1 + a]]) + (ArcCos[a + b*x] + I*(Log[2] - 2*Log[I*Sqrt[1 - a] + Sqrt[1 + a]]))*Log[1 - (a + Sqrt[-1 + a^2])*(a + b*x + I*Sqrt[1 - (a + b*x)^2])] + (ArcCos[a + b*x] - I*(Log[2] - 2*Log[I*Sqrt[1 - a] + Sqrt[1 + a]]))*Log[1 + (-a + Sqrt[-1 + a^2])*(a + b*x + I*Sqrt[1 - (a + b*x)^2])] - I*PolyLog[2, (a - Sqrt[-1 + a^2])*(a + b*x + I*Sqrt[1 - (a + b*x)^2])] - I*PolyLog[2, (a + Sqrt[-1 + a^2])*(a + b*x + I*Sqrt[1 - (a + b*x)^2])]}
{ArcCos[a + b*x]/x^2, x, 3, -(ArcCos[a + b*x]/x) + (b*ArcTanh[(1 - a^2 - a*b*x)/(Sqrt[1 - a^2]*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])])/Sqrt[1 - a^2]}
{ArcCos[a + b*x]/x^3, x, 4, (b*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(2*(1 - a^2)*x) - ArcCos[a + b*x]/(2*x^2) + (a*b^2*ArcTanh[(1 - a^2 - a*b*x)/(Sqrt[1 - a^2]*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])])/(2*(1 - a^2)^(3/2))}
{ArcCos[a + b*x]/x^4, x, 6, (b*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(6*(1 - a^2)*x^2) + (a*b^2*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(2*(1 - a^2)^2*x) - ArcCos[a + b*x]/(3*x^3) + ((1 + 2*a^2)*b^3*ArcTanh[(1 - a^2 - a*b*x)/(Sqrt[1 - a^2]*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])])/(6*(1 - a^2)^(5/2))}


{ArcCos[a + b*x]^3, x, 2, (6*Sqrt[1 - (a + b*x)^2])/b - (6*(a + b*x)*ArcCos[a + b*x])/b - (3*Sqrt[1 - (a + b*x)^2]*ArcCos[a + b*x]^2)/b + ((a + b*x)*ArcCos[a + b*x]^3)/b}
{ArcCos[a + b*x]^2, x, 2, -2*x - (2*Sqrt[1 - (a + b*x)^2]*ArcCos[a + b*x])/b + ((a + b*x)*ArcCos[a + b*x]^2)/b}
{1/ArcCos[a + b*x], x, 2, -(SinIntegral[ArcCos[a + b*x]]/b)}
{1/ArcCos[a + b*x]^2, x, 4, Sqrt[1 - (a + b*x)^2]/(b*ArcCos[a + b*x]) - CosIntegral[ArcCos[a + b*x]]/b}
{1/ArcCos[a + b*x]^3, x, 3, Sqrt[1 - (a + b*x)^2]/(2*b*ArcCos[a + b*x]^2) + (a + b*x)/(2*b*ArcCos[a + b*x]) + SinIntegral[ArcCos[a + b*x]]/(2*b)}


{ArcCos[a + b*x]^(5/2), x, 5, -((15*(a + b*x)*Sqrt[ArcCos[a + b*x]])/(4*b)) - (5*Sqrt[1 - (a + b*x)^2]*ArcCos[a + b*x]^(3/2))/(2*b) + ((a + b*x)*ArcCos[a + b*x]^(5/2))/b + (15*Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[ArcCos[a + b*x]]])/(4*b)}
{ArcCos[a + b*x]^(3/2), x, 4, -((3*Sqrt[1 - (a + b*x)^2]*Sqrt[ArcCos[a + b*x]])/(2*b)) + ((a + b*x)*ArcCos[a + b*x]^(3/2))/b + (3*Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcCos[a + b*x]]])/(2*b)}
{ArcCos[a + b*x]^(1/2), x, 4, ((a + b*x)*Sqrt[ArcCos[a + b*x]])/b - (Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[ArcCos[a + b*x]]])/b}
{1/ArcCos[a + b*x]^(1/2), x, 3, -((Sqrt[2*Pi]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcCos[a + b*x]]])/b)}
{1/ArcCos[a + b*x]^(3/2), x, 4, (2*Sqrt[1 - (a + b*x)^2])/(b*Sqrt[ArcCos[a + b*x]]) - (2*Sqrt[2*Pi]*FresnelC[Sqrt[2/Pi]*Sqrt[ArcCos[a + b*x]]])/b}
{1/ArcCos[a + b*x]^(5/2), x, 4, (2*Sqrt[1 - (a + b*x)^2])/(3*b*ArcCos[a + b*x]^(3/2)) + (4*(a + b*x))/(3*b*Sqrt[ArcCos[a + b*x]]) + (4*Sqrt[2*Pi]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcCos[a + b*x]]])/(3*b)}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c+d x)^m ArcCos[a+b x]^n*)


{ArcCos[a + b*x]/((a*d)/b + d*x), x, 5, -((I*ArcCos[a + b*x]^2)/(2*d)) + (ArcCos[a + b*x]*Log[1 + E^(2*I*ArcCos[a + b*x])])/d - (I*PolyLog[2, -E^(2*I*ArcCos[a + b*x])])/(2*d)}


(* ::Section::Closed:: *)
(*Integrands of the form u ArcCos[a +b x^n]*)


{x^3*ArcCos[a + b*x^4], x, 2, -(Sqrt[1 - (a + b*x^4)^2]/(4*b)) + ((a + b*x^4)*ArcCos[a + b*x^4])/(4*b)}


{x^(n-1)*ArcCos[a + b*x^n], x, 2, -(Sqrt[1 - (a + b*x^n)^2]/(b*n)) + ((a + b*x^n)*ArcCos[a + b*x^n])/(b*n)}


(* ::Section::Closed:: *)
(*Integrands of the form u (a+b ArcCos[d +e x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a+b ArcCos[c+d x])^n*)


{1/Sqrt[a + b*ArcCos[c + d*x]], x, 6, -((Sqrt[2*Pi]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcCos[c + d*x]])/Sqrt[b]])/(Sqrt[b]*d)) + (Sqrt[2*Pi]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcCos[c + d*x]])/Sqrt[b]]*Sin[a/b])/(Sqrt[b]*d)}
{1/Sqrt[a - b*ArcCos[c + d*x]], x, 6, -((Sqrt[2*Pi]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a - b*ArcCos[c + d*x]])/Sqrt[b]])/(Sqrt[b]*d)) + (Sqrt[2*Pi]*FresnelC[(Sqrt[2/Pi]*Sqrt[a - b*ArcCos[c + d*x]])/Sqrt[b]]*Sin[a/b])/(Sqrt[b]*d)}


(* ::Section::Closed:: *)
(*Integrands involving inverse trig functions of exponentials*)


{ArcCos[c*E^(a + b*x)], x, 6, -((I*ArcCos[c*E^(a + b*x)]^2)/(2*b)) + (ArcCos[c*E^(a + b*x)]*Log[1 + E^(2*I*ArcCos[c*E^(a + b*x)])])/b - (I*PolyLog[2, -E^(2*I*ArcCos[c*E^(a + b*x)])])/(2*b)}


(* ::Section::Closed:: *)
(*Integrands involving exponentials of inverse trig functions*)


{x^3*E^ArcCos[x], x, 6, (1/10)*E^ArcCos[x]*Cos[2*ArcCos[x]] + (1/34)*E^ArcCos[x]*Cos[4*ArcCos[x]] - (1/20)*E^ArcCos[x]*Sin[2*ArcCos[x]] - (1/136)*E^ArcCos[x]*Sin[4*ArcCos[x]]}
{x^2*E^ArcCos[x], x, 6, (1/8)*E^ArcCos[x]*x - (1/8)*E^ArcCos[x]*Sqrt[1 - x^2] + (3/40)*E^ArcCos[x]*Cos[3*ArcCos[x]] - (1/40)*E^ArcCos[x]*Sin[3*ArcCos[x]]}
{x*E^ArcCos[x], x, 5, (1/5)*E^ArcCos[x]*Cos[2*ArcCos[x]] - (1/10)*E^ArcCos[x]*Sin[2*ArcCos[x]]}
{E^ArcCos[x], x, 1, (1/2)*E^ArcCos[x]*(x - Sqrt[1 - x^2])}
{E^ArcCos[x]/x, x, 2, -Subst[Defer[Int][E^x*Tan[x], x], x, ArcCos[x]]}


(* ::Section::Closed:: *)
(*Miscellaneous integrands involving inverse cosines*)


{ArcCos[c/(a + b*x)], x, 5, ((a + b*x)*ArcSec[a/c + (b*x)/c])/b - (c*ArcTanh[Sqrt[1 - c^2/(a + b*x)^2]])/b}
