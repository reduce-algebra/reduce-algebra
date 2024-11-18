(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Inverse Sines*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcSin[a x]^n*)


(* Integrands of the form x^m*ArcSin[a*x] where m is an integer *)
{x^4*ArcSin[a*x], x, 5, (8*Sqrt[1 - a^2*x^2])/(75*a^5) + (4*x^2*Sqrt[1 - a^2*x^2])/(75*a^3) + (x^4*Sqrt[1 - a^2*x^2])/(25*a) + (1/5)*x^5*ArcSin[a*x]}
{x^3*ArcSin[a*x], x, 4, (3*x*Sqrt[1 - a^2*x^2])/(32*a^3) + (x^3*Sqrt[1 - a^2*x^2])/(16*a) - (3*ArcSin[a*x])/(32*a^4) + (1/4)*x^4*ArcSin[a*x]}
{x^2*ArcSin[a*x], x, 4, (2*Sqrt[1 - a^2*x^2])/(9*a^3) + (x^2*Sqrt[1 - a^2*x^2])/(9*a) + (1/3)*x^3*ArcSin[a*x]}
{x*ArcSin[a*x], x, 3, (x*Sqrt[1 - a^2*x^2])/(4*a) - ArcSin[a*x]/(4*a^2) + (1/2)*x^2*ArcSin[a*x]}
{ArcSin[a*x], x, 1, Sqrt[1 - a^2*x^2]/a + x*ArcSin[a*x]}
{ArcSin[a*x]/x, x, 5, (-(1/2))*I*ArcSin[a*x]^2 + ArcSin[a*x]*Log[1 - E^(2*I*ArcSin[a*x])] - (1/2)*I*PolyLog[2, E^(2*I*ArcSin[a*x])]}
{ArcSin[a*x]/x^2, x, 2, -(ArcSin[a*x]/x) - a*ArcTanh[Sqrt[1 - a^2*x^2]]}
{ArcSin[a*x]/x^3, x, 2, -((a*Sqrt[1 - a^2*x^2])/(2*x)) - ArcSin[a*x]/(2*x^2)}
{ArcSin[a*x]/x^4, x, 3, -((a*Sqrt[1 - a^2*x^2])/(6*x^2)) - ArcSin[a*x]/(3*x^3) - (1/6)*a^3*ArcTanh[Sqrt[1 - a^2*x^2]]}
{ArcSin[a*x]/x^5, x, 3, -((a*Sqrt[1 - a^2*x^2])/(12*x^3)) - (a^3*Sqrt[1 - a^2*x^2])/(6*x) - ArcSin[a*x]/(4*x^4)}


(* Integrands of the form x^m*ArcSin[a*x]^2 where m is an integer *)
{x^4*ArcSin[a*x]^2, x, 5, -((16*x)/(75*a^4)) - (8*x^3)/(225*a^2) - (2*x^5)/125 + (16*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(75*a^5) + (8*x^2*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(75*a^3) + (2*x^4*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(25*a) + (1/5)*x^5*ArcSin[a*x]^2}
{x^3*ArcSin[a*x]^2, x, 4, -((3*x^2)/(32*a^2)) - x^4/32 + (3*x*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(16*a^3) + (x^3*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(8*a) - (3*ArcSin[a*x]^2)/(32*a^4) + (1/4)*x^4*ArcSin[a*x]^2}
{x^2*ArcSin[a*x]^2, x, 4, -((4*x)/(9*a^2)) - (2*x^3)/27 + (4*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(9*a^3) + (2*x^2*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(9*a) + (1/3)*x^3*ArcSin[a*x]^2}
{x*ArcSin[a*x]^2, x, 2, -(x^2/4) + (x*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(2*a) - ArcSin[a*x]^2/(4*a^2) + (1/2)*x^2*ArcSin[a*x]^2}
{ArcSin[a*x]^2, x, 2, -2*x + (2*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/a + x*ArcSin[a*x]^2}
{ArcSin[a*x]^2/x, x, 6, (-(1/3))*I*ArcSin[a*x]^3 + ArcSin[a*x]^2*Log[1 - E^(2*I*ArcSin[a*x])] - I*ArcSin[a*x]*PolyLog[2, E^(2*I*ArcSin[a*x])] + (1/2)*PolyLog[3, E^(2*I*ArcSin[a*x])]}
{ArcSin[a*x]^2/x^2, x, 5, -(ArcSin[a*x]^2/x) - 4*a*ArcSin[a*x]*ArcTanh[E^(I*ArcSin[a*x])] + 2*I*a*PolyLog[2, -E^(I*ArcSin[a*x])] - 2*I*a*PolyLog[2, E^(I*ArcSin[a*x])]}
{ArcSin[a*x]^2/x^3, x, 2, -((a*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/x) - ArcSin[a*x]^2/(2*x^2) + a^2*Log[x]}
{ArcSin[a*x]^2/x^4, x, 7, -(a^2/(3*x)) - (a*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(3*x^2) - ArcSin[a*x]^2/(3*x^3) - (2/3)*a^3*ArcSin[a*x]*ArcTanh[E^(I*ArcSin[a*x])] + (1/3)*I*a^3*PolyLog[2, -E^(I*ArcSin[a*x])] - (1/3)*I*a^3*PolyLog[2, E^(I*ArcSin[a*x])]}
{ArcSin[a*x]^2/x^5, x, 4, -(a^2/(12*x^2)) - (a*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(6*x^3) - (a^3*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(3*x) - ArcSin[a*x]^2/(4*x^4) + (1/3)*a^4*Log[x]}


(* Integrands of the form x^m*ArcSin[a*x]^3 where m is an integer *)
{x^4*ArcSin[a*x]^3, x, 10, -((298*Sqrt[1 - a^2*x^2])/(375*a^5)) + (76*(1 - a^2*x^2)^(3/2))/(1125*a^5) - (6*(1 - a^2*x^2)^(5/2))/(625*a^5) - (16*x*ArcSin[a*x])/(25*a^4) - (8*x^3*ArcSin[a*x])/(75*a^2) - (6/125)*x^5*ArcSin[a*x] + (8*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^2)/(25*a^5) + (4*x^2*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^2)/(25*a^3) + (3*x^4*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^2)/(25*a) + (1/5)*x^5*ArcSin[a*x]^3}
{x^3*ArcSin[a*x]^3, x, 7, -((45*x*Sqrt[1 - a^2*x^2])/(256*a^3)) - (3*x^3*Sqrt[1 - a^2*x^2])/(128*a) + (45*ArcSin[a*x])/(256*a^4) - (9*x^2*ArcSin[a*x])/(32*a^2) - (3/32)*x^4*ArcSin[a*x] + (9*x*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^2)/(32*a^3) + (3*x^3*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^2)/(16*a) - (3*ArcSin[a*x]^3)/(32*a^4) + (1/4)*x^4*ArcSin[a*x]^3}
{x^2*ArcSin[a*x]^3, x, 7, -((14*Sqrt[1 - a^2*x^2])/(9*a^3)) + (2*(1 - a^2*x^2)^(3/2))/(27*a^3) - (4*x*ArcSin[a*x])/(3*a^2) - (2/9)*x^3*ArcSin[a*x] + (2*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^2)/(3*a^3) + (x^2*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^2)/(3*a) + (1/3)*x^3*ArcSin[a*x]^3}
{x*ArcSin[a*x]^3, x, 4, -((3*x*Sqrt[1 - a^2*x^2])/(8*a)) + (3*ArcSin[a*x])/(8*a^2) - (3/4)*x^2*ArcSin[a*x] + (3*x*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^2)/(4*a) - ArcSin[a*x]^3/(4*a^2) + (1/2)*x^2*ArcSin[a*x]^3}
{ArcSin[a*x]^3, x, 2, -((6*Sqrt[1 - a^2*x^2])/a) - 6*x*ArcSin[a*x] + (3*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^2)/a + x*ArcSin[a*x]^3}
{ArcSin[a*x]^3/x, x, 7, (-(1/4))*I*ArcSin[a*x]^4 + ArcSin[a*x]^3*Log[1 - E^(2*I*ArcSin[a*x])] - (3/2)*I*ArcSin[a*x]^2*PolyLog[2, E^(2*I*ArcSin[a*x])] + (3/2)*ArcSin[a*x]*PolyLog[3, E^(2*I*ArcSin[a*x])] + (3/4)*I*PolyLog[4, E^(2*I*ArcSin[a*x])]}
{ArcSin[a*x]^3/x^2, x, 7, -(ArcSin[a*x]^3/x) - 6*a*ArcSin[a*x]^2*ArcTanh[E^(I*ArcSin[a*x])] + 6*I*a*ArcSin[a*x]*PolyLog[2, -E^(I*ArcSin[a*x])] - 6*I*a*ArcSin[a*x]*PolyLog[2, E^(I*ArcSin[a*x])] - 6*a*PolyLog[3, -E^(I*ArcSin[a*x])] + 6*a*PolyLog[3, E^(I*ArcSin[a*x])]}
{ArcSin[a*x]^3/x^3, x, 6, (-(3/2))*I*a^2*ArcSin[a*x]^2 - (3*a*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^2)/(2*x) - ArcSin[a*x]^3/(2*x^2) + 3*a^2*ArcSin[a*x]*Log[1 - E^(2*I*ArcSin[a*x])] - (3/2)*I*a^2*PolyLog[2, E^(2*I*ArcSin[a*x])]}
{ArcSin[a*x]^3/x^4, x, 10, -((a^2*ArcSin[a*x])/x) - (a*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^2)/(2*x^2) - ArcSin[a*x]^3/(3*x^3) - a^3*ArcSin[a*x]^2*ArcTanh[E^(I*ArcSin[a*x])] - a^3*ArcTanh[Sqrt[1 - a^2*x^2]] + I*a^3*ArcSin[a*x]*PolyLog[2, -E^(I*ArcSin[a*x])] - I*a^3*ArcSin[a*x]*PolyLog[2, E^(I*ArcSin[a*x])] - a^3*PolyLog[3, -E^(I*ArcSin[a*x])] + a^3*PolyLog[3, E^(I*ArcSin[a*x])]}
{ArcSin[a*x]^3/x^5, x, 9, -((a^3*Sqrt[1 - a^2*x^2])/(4*x)) - (a^2*ArcSin[a*x])/(4*x^2) - (1/2)*I*a^4*ArcSin[a*x]^2 - (a*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^2)/(4*x^3) - (a^3*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^2)/(2*x) - ArcSin[a*x]^3/(4*x^4) + a^4*ArcSin[a*x]*Log[1 - E^(2*I*ArcSin[a*x])] - (1/2)*I*a^4*PolyLog[2, E^(2*I*ArcSin[a*x])]}


(* Integrands of the form x^m*Sqrt[ArcSin[a*x]] where m is an integer *)
{x^4*Sqrt[ArcSin[a*x]], x, 7, (1/5)*x^5*Sqrt[ArcSin[a*x]] - (Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(8*a^5) + (Sqrt[Pi/6]*FresnelS[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/(16*a^5) - (Sqrt[Pi/10]*FresnelS[Sqrt[10/Pi]*Sqrt[ArcSin[a*x]]])/(80*a^5)}
{x^3*Sqrt[ArcSin[a*x]], x, 6, -((3*Sqrt[ArcSin[a*x]])/(32*a^4)) + (1/4)*x^4*Sqrt[ArcSin[a*x]] - (Sqrt[Pi/2]*FresnelC[2*Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(64*a^4) + (Sqrt[Pi]*FresnelC[(2*Sqrt[ArcSin[a*x]])/Sqrt[Pi]])/(16*a^4)}
{x^2*Sqrt[ArcSin[a*x]], x, 6, (1/3)*x^3*Sqrt[ArcSin[a*x]] - (Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(4*a^3) + (Sqrt[Pi/6]*FresnelS[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/(12*a^3)}
{x*Sqrt[ArcSin[a*x]], x, 2, -(Sqrt[ArcSin[a*x]]/(4*a^2)) + (1/2)*x^2*Sqrt[ArcSin[a*x]] + (Sqrt[Pi]*FresnelC[(2*Sqrt[ArcSin[a*x]])/Sqrt[Pi]])/(8*a^2)}
{Sqrt[ArcSin[a*x]], x, 1, x*Sqrt[ArcSin[a*x]] - (Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/a}
{Sqrt[ArcSin[a*x]]/x, x, 3, 2*Subst[Int[x^2*Cot[x^2], x], x, Sqrt[ArcSin[a*x]]]}


(* Integrands of the form x^m*ArcSin[a*x]^(3/2) where m is an integer *)
{x^4*ArcSin[a*x]^(3/2), x, 12, (3*Sqrt[1 - a^2*x^2]*Sqrt[ArcSin[a*x]])/(16*a^5) + (1/5)*x^5*ArcSin[a*x]^(3/2) - (Sqrt[ArcSin[a*x]]*Cos[3*ArcSin[a*x]])/(32*a^5) + (3*Sqrt[ArcSin[a*x]]*Cos[5*ArcSin[a*x]])/(800*a^5) - (3*Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(16*a^5) + (Sqrt[Pi/6]*FresnelC[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/(32*a^5) - (3*Sqrt[Pi/10]*FresnelC[Sqrt[10/Pi]*Sqrt[ArcSin[a*x]]])/(800*a^5)}
{x^3*ArcSin[a*x]^(3/2), x, 11, -((3*ArcSin[a*x]^(3/2))/(32*a^4)) + (1/4)*x^4*ArcSin[a*x]^(3/2) + (3*Sqrt[Pi/2]*FresnelS[2*Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(512*a^4) - (3*Sqrt[Pi]*FresnelS[(2*Sqrt[ArcSin[a*x]])/Sqrt[Pi]])/(64*a^4) + (3*Sqrt[ArcSin[a*x]]*Sin[2*ArcSin[a*x]])/(32*a^4) - (3*Sqrt[ArcSin[a*x]]*Sin[4*ArcSin[a*x]])/(256*a^4)}
{x^2*ArcSin[a*x]^(3/2), x, 8, (Sqrt[1 - a^2*x^2]*Sqrt[ArcSin[a*x]])/(3*a^3) + (x^2*Sqrt[1 - a^2*x^2]*Sqrt[ArcSin[a*x]])/(6*a) + (1/3)*x^3*ArcSin[a*x]^(3/2) - (3*Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(8*a^3) + (Sqrt[Pi/6]*FresnelC[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/(24*a^3), (3*Sqrt[1 - a^2*x^2]*Sqrt[ArcSin[a*x]])/(8*a^3) + (1/3)*x^3*ArcSin[a*x]^(3/2) - (Sqrt[ArcSin[a*x]]*Cos[3*ArcSin[a*x]])/(24*a^3) - (3*Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(8*a^3) + (Sqrt[Pi/6]*FresnelC[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/(24*a^3)}
{x*ArcSin[a*x]^(3/2), x, 2, (3*x*Sqrt[1 - a^2*x^2]*Sqrt[ArcSin[a*x]])/(8*a) - ArcSin[a*x]^(3/2)/(4*a^2) + (1/2)*x^2*ArcSin[a*x]^(3/2) - (3*Sqrt[Pi]*FresnelS[(2*Sqrt[ArcSin[a*x]])/Sqrt[Pi]])/(32*a^2)}
{ArcSin[a*x]^(3/2), x, 2, (3*Sqrt[1 - a^2*x^2]*Sqrt[ArcSin[a*x]])/(2*a) + x*ArcSin[a*x]^(3/2) - (3*Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(2*a)}
{ArcSin[a*x]^(3/2)/x, x, 3, 2*Subst[Int[x^4*Cot[x^2], x], x, Sqrt[ArcSin[a*x]]]}


(* Integrands of the form x^m*ArcSin[a*x]^(5/2) where m is an integer *)
{x^4*ArcSin[a*x]^(5/2), x, 16, -((2*x*Sqrt[ArcSin[a*x]])/(5*a^4)) - (x^3*Sqrt[ArcSin[a*x]])/(15*a^2) - (3/100)*x^5*Sqrt[ArcSin[a*x]] + (4*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^(3/2))/(15*a^5) + (2*x^2*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^(3/2))/(15*a^3) + (x^4*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^(3/2))/(10*a) + (1/5)*x^5*ArcSin[a*x]^(5/2) + (15*Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(32*a^5) - (5*Sqrt[Pi/6]*FresnelS[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/(192*a^5) + (3*Sqrt[Pi/10]*FresnelS[Sqrt[10/Pi]*Sqrt[ArcSin[a*x]]])/(1600*a^5)}
{x^3*ArcSin[a*x]^(5/2), x, 12, (225*Sqrt[ArcSin[a*x]])/(2048*a^4) - (45*x^2*Sqrt[ArcSin[a*x]])/(256*a^2) - (15/256)*x^4*Sqrt[ArcSin[a*x]] + (15*x*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^(3/2))/(64*a^3) + (5*x^3*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^(3/2))/(32*a) - (3*ArcSin[a*x]^(5/2))/(32*a^4) + (1/4)*x^4*ArcSin[a*x]^(5/2) + (15*Sqrt[Pi/2]*FresnelC[2*Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(4096*a^4) - (15*Sqrt[Pi]*FresnelC[(2*Sqrt[ArcSin[a*x]])/Sqrt[Pi]])/(256*a^4)}
{x^2*ArcSin[a*x]^(5/2), x, 10, -((5*x*Sqrt[ArcSin[a*x]])/(6*a^2)) - (5/36)*x^3*Sqrt[ArcSin[a*x]] + (5*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^(3/2))/(9*a^3) + (5*x^2*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^(3/2))/(18*a) + (1/3)*x^3*ArcSin[a*x]^(5/2) + (15*Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(16*a^3) - (5*Sqrt[Pi/6]*FresnelS[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/(144*a^3)}
{x*ArcSin[a*x]^(5/2), x, 3, (15*Sqrt[ArcSin[a*x]])/(64*a^2) - (15/32)*x^2*Sqrt[ArcSin[a*x]] + (5*x*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^(3/2))/(8*a) - ArcSin[a*x]^(5/2)/(4*a^2) + (1/2)*x^2*ArcSin[a*x]^(5/2) - (15*Sqrt[Pi]*FresnelC[(2*Sqrt[ArcSin[a*x]])/Sqrt[Pi]])/(128*a^2)}
{ArcSin[a*x]^(5/2), x, 2, (-(15/4))*x*Sqrt[ArcSin[a*x]] + (5*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^(3/2))/(2*a) + x*ArcSin[a*x]^(5/2) + (15*Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(4*a)}
{ArcSin[a*x]^(5/2)/x, x, 3, 2*Subst[Int[x^6*Cot[x^2], x], x, Sqrt[ArcSin[a*x]]]}


(* Integrands of the form x^m/Sqrt[ArcSin[a*x]] where m is an integer *)
{x^4/Sqrt[ArcSin[a*x]], x, 8, (Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(4*a^5) - (Sqrt[(3*Pi)/2]*FresnelC[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/(8*a^5) + (Sqrt[Pi/10]*FresnelC[Sqrt[10/Pi]*Sqrt[ArcSin[a*x]]])/(8*a^5)}
{x^3/Sqrt[ArcSin[a*x]], x, 7, -((Sqrt[Pi/2]*FresnelS[2*Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(8*a^4)) + (Sqrt[Pi]*FresnelS[(2*Sqrt[ArcSin[a*x]])/Sqrt[Pi]])/(4*a^4)}
{x^2/Sqrt[ArcSin[a*x]], x, 7, (Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(2*a^3) - (Sqrt[Pi/6]*FresnelC[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/(2*a^3)}
{x/Sqrt[ArcSin[a*x]], x, 1, (Sqrt[Pi]*FresnelS[(2*Sqrt[ArcSin[a*x]])/Sqrt[Pi]])/(2*a^2)}
{1/Sqrt[ArcSin[a*x]], x, 1, (Sqrt[2*Pi]*FresnelC[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/a}
{1/(x*Sqrt[ArcSin[a*x]]), x, 3, 2*Subst[Int[Cot[x^2], x], x, Sqrt[ArcSin[a*x]]]}


(* Integrands of the form x^m/ArcSin[a*x]^(3/2) where m is an integer *)
{x^4/ArcSin[a*x]^(3/2), x, 14, -((2*x^4*Sqrt[1 - a^2*x^2])/(a*Sqrt[ArcSin[a*x]])) - (Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(2*a^5) + (3*Sqrt[(3*Pi)/2]*FresnelS[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/(4*a^5) - (Sqrt[(5*Pi)/2]*FresnelS[Sqrt[10/Pi]*Sqrt[ArcSin[a*x]]])/(4*a^5)}
{x^3/ArcSin[a*x]^(3/2), x, 9, -((2*x^3*Sqrt[1 - a^2*x^2])/(a*Sqrt[ArcSin[a*x]])) - (Sqrt[Pi/2]*FresnelC[2*Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/a^4 + (Sqrt[Pi]*FresnelC[(2*Sqrt[ArcSin[a*x]])/Sqrt[Pi]])/a^4}
{x^2/ArcSin[a*x]^(3/2), x, 8, -((2*x^2*Sqrt[1 - a^2*x^2])/(a*Sqrt[ArcSin[a*x]])) - (Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/a^3 + (Sqrt[(3*Pi)/2]*FresnelS[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/a^3}
{x/ArcSin[a*x]^(3/2), x, 1, -((2*x*Sqrt[1 - a^2*x^2])/(a*Sqrt[ArcSin[a*x]])) + (2*Sqrt[Pi]*FresnelC[(2*Sqrt[ArcSin[a*x]])/Sqrt[Pi]])/a^2}
{1/ArcSin[a*x]^(3/2), x, 2, -((2*Sqrt[1 - a^2*x^2])/(a*Sqrt[ArcSin[a*x]])) - (2*Sqrt[2*Pi]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/a}
{1/(x*ArcSin[a*x]^(3/2)), x, 3, 2*Subst[Int[Cot[x^2]/x^2, x], x, Sqrt[ArcSin[a*x]]]}


(* Integrands of the form x^m/ArcSin[a*x]^(5/2) where m is an integer *)
{x^4/ArcSin[a*x]^(5/2), x, 16, -((2*x^4*Sqrt[1 - a^2*x^2])/(3*a*ArcSin[a*x]^(3/2))) - (16*x^3)/(3*a^2*Sqrt[ArcSin[a*x]]) + (20*x^5)/(3*Sqrt[ArcSin[a*x]]) - (Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(3*a^5) + (3*Sqrt[(3*Pi)/2]*FresnelC[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/(2*a^5) - (5*Sqrt[(5*Pi)/2]*FresnelC[Sqrt[10/Pi]*Sqrt[ArcSin[a*x]]])/(6*a^5)}
{x^3/ArcSin[a*x]^(5/2), x, 9, -((2*x^3*Sqrt[1 - a^2*x^2])/(3*a*ArcSin[a*x]^(3/2))) - (4*x^2)/(a^2*Sqrt[ArcSin[a*x]]) + (16*x^4)/(3*Sqrt[ArcSin[a*x]]) + (4*Sqrt[2*Pi]*FresnelS[2*Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(3*a^4) - (4*Sqrt[Pi]*FresnelS[(2*Sqrt[ArcSin[a*x]])/Sqrt[Pi]])/(3*a^4)}
{x^2/ArcSin[a*x]^(5/2), x, 9, -((2*x^2*Sqrt[1 - a^2*x^2])/(3*a*ArcSin[a*x]^(3/2))) - (8*x)/(3*a^2*Sqrt[ArcSin[a*x]]) + (4*x^3)/Sqrt[ArcSin[a*x]] - (Sqrt[2*Pi]*FresnelC[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(3*a^3) + (Sqrt[6*Pi]*FresnelC[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/a^3}
{x/ArcSin[a*x]^(5/2), x, 2, -((2*x*Sqrt[1 - a^2*x^2])/(3*a*ArcSin[a*x]^(3/2))) - 4/(3*a^2*Sqrt[ArcSin[a*x]]) + (8*x^2)/(3*Sqrt[ArcSin[a*x]]) - (8*Sqrt[Pi]*FresnelS[(2*Sqrt[ArcSin[a*x]])/Sqrt[Pi]])/(3*a^2)}
{1/ArcSin[a*x]^(5/2), x, 2, -((2*Sqrt[1 - a^2*x^2])/(3*a*ArcSin[a*x]^(3/2))) + (4*x)/(3*Sqrt[ArcSin[a*x]]) - (4*Sqrt[2*Pi]*FresnelC[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(3*a)}
{1/(x*ArcSin[a*x]^(5/2)), x, 3, 2*Subst[Int[Cot[x^2]/x^4, x], x, Sqrt[ArcSin[a*x]]]}


(* Integrands of the form x^m/ArcSin[a*x]^(7/2) where m is an integer *)
{x^4/ArcSin[a*x]^(7/2), x, 23, -((2*x^4*Sqrt[1 - a^2*x^2])/(5*a*ArcSin[a*x]^(5/2))) - (16*x^3)/(15*a^2*ArcSin[a*x]^(3/2)) + (4*x^5)/(3*ArcSin[a*x]^(3/2)) - (32*x^2*Sqrt[1 - a^2*x^2])/(5*a^3*Sqrt[ArcSin[a*x]]) + (40*x^4*Sqrt[1 - a^2*x^2])/(3*a*Sqrt[ArcSin[a*x]]) + (Sqrt[2*Pi]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(15*a^5) - (9*Sqrt[(3*Pi)/2]*FresnelS[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/(5*a^5) + (5*Sqrt[(5*Pi)/2]*FresnelS[Sqrt[10/Pi]*Sqrt[ArcSin[a*x]]])/(3*a^5)}
{x^3/ArcSin[a*x]^(7/2), x, 11, -((2*x^3*Sqrt[1 - a^2*x^2])/(5*a*ArcSin[a*x]^(5/2))) - (4*x^2)/(5*a^2*ArcSin[a*x]^(3/2)) + (16*x^4)/(15*ArcSin[a*x]^(3/2)) - (16*x*Sqrt[1 - a^2*x^2])/(5*a^3*Sqrt[ArcSin[a*x]]) + (128*x^3*Sqrt[1 - a^2*x^2])/(15*a*Sqrt[ArcSin[a*x]]) + (32*Sqrt[2*Pi]*FresnelC[2*Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(15*a^4) - (16*Sqrt[Pi]*FresnelC[(2*Sqrt[ArcSin[a*x]])/Sqrt[Pi]])/(15*a^4)}
{x^2/ArcSin[a*x]^(7/2), x, 11, -((2*x^2*Sqrt[1 - a^2*x^2])/(5*a*ArcSin[a*x]^(5/2))) - (8*x)/(15*a^2*ArcSin[a*x]^(3/2)) + (4*x^3)/(5*ArcSin[a*x]^(3/2)) - (16*Sqrt[1 - a^2*x^2])/(15*a^3*Sqrt[ArcSin[a*x]]) + (24*x^2*Sqrt[1 - a^2*x^2])/(5*a*Sqrt[ArcSin[a*x]]) + (2*Sqrt[2*Pi]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(15*a^3) - (6*Sqrt[6*Pi]*FresnelS[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/(5*a^3)}
{x/ArcSin[a*x]^(7/2), x, 2, -((2*x*Sqrt[1 - a^2*x^2])/(5*a*ArcSin[a*x]^(5/2))) - 4/(15*a^2*ArcSin[a*x]^(3/2)) + (8*x^2)/(15*ArcSin[a*x]^(3/2)) + (32*x*Sqrt[1 - a^2*x^2])/(15*a*Sqrt[ArcSin[a*x]]) - (32*Sqrt[Pi]*FresnelC[(2*Sqrt[ArcSin[a*x]])/Sqrt[Pi]])/(15*a^2)}
{1/ArcSin[a*x]^(7/2), x, 3, -((2*Sqrt[1 - a^2*x^2])/(5*a*ArcSin[a*x]^(5/2))) + (4*x)/(15*ArcSin[a*x]^(3/2)) + (8*Sqrt[1 - a^2*x^2])/(15*a*Sqrt[ArcSin[a*x]]) + (8*Sqrt[2*Pi]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(15*a)}
{1/(x*ArcSin[a*x]^(7/2)), x, 3, 2*Subst[Int[Cot[x^2]/x^6, x], x, Sqrt[ArcSin[a*x]]]}


(* Integrands of the form x^m/ArcSin[a*x]^n where m is an integer *)
{x^4*ArcSin[a*x]^n, x, 12, (1/5)*x^5*ArcSin[a*x]^n - (I*n*ArcSin[a*x]^n*Gamma[n, (-I)*ArcSin[a*x]])/(((-I)*ArcSin[a*x])^n*(16*a^5)) + (I*n*ArcSin[a*x]^n*Gamma[n, I*ArcSin[a*x]])/((I*ArcSin[a*x])^n*(16*a^5)) + (I*n*ArcSin[a*x]^n*Gamma[n, -3*I*ArcSin[a*x]])/(3^n*((-I)*ArcSin[a*x])^n*(32*a^5)) - (I*n*ArcSin[a*x]^n*Gamma[n, 3*I*ArcSin[a*x]])/(3^n*(I*ArcSin[a*x])^n*(32*a^5)) - (I*5^(-1 - n)*n*ArcSin[a*x]^n*Gamma[n, -5*I*ArcSin[a*x]])/(((-I)*ArcSin[a*x])^n*(32*a^5)) + (I*5^(-1 - n)*n*ArcSin[a*x]^n*Gamma[n, 5*I*ArcSin[a*x]])/((I*ArcSin[a*x])^n*(32*a^5))}
{x^3*ArcSin[a*x]^n, x, 10, -((3*ArcSin[a*x]^n)/(32*a^4)) + (1/4)*x^4*ArcSin[a*x]^n - (2^(-4 - n)*n*ArcSin[a*x]^n*Gamma[n, -2*I*ArcSin[a*x]])/(((-I)*ArcSin[a*x])^n*a^4) - (2^(-4 - n)*n*ArcSin[a*x]^n*Gamma[n, 2*I*ArcSin[a*x]])/((I*ArcSin[a*x])^n*a^4) + (2^(-6 - 2*n)*n*ArcSin[a*x]^n*Gamma[n, -4*I*ArcSin[a*x]])/(((-I)*ArcSin[a*x])^n*a^4) + (2^(-6 - 2*n)*n*ArcSin[a*x]^n*Gamma[n, 4*I*ArcSin[a*x]])/((I*ArcSin[a*x])^n*a^4)}
{x^2*ArcSin[a*x]^n, x, 9, (1/3)*x^3*ArcSin[a*x]^n - (I*n*ArcSin[a*x]^n*Gamma[n, (-I)*ArcSin[a*x]])/(((-I)*ArcSin[a*x])^n*(8*a^3)) + (I*n*ArcSin[a*x]^n*Gamma[n, I*ArcSin[a*x]])/((I*ArcSin[a*x])^n*(8*a^3)) + (I*3^(-1 - n)*n*ArcSin[a*x]^n*Gamma[n, -3*I*ArcSin[a*x]])/(((-I)*ArcSin[a*x])^n*(8*a^3)) - (I*3^(-1 - n)*n*ArcSin[a*x]^n*Gamma[n, 3*I*ArcSin[a*x]])/((I*ArcSin[a*x])^n*(8*a^3))}
{x*ArcSin[a*x]^n, x, 7, -(ArcSin[a*x]^n/(4*a^2)) + (1/2)*x^2*ArcSin[a*x]^n - (2^(-3 - n)*n*ArcSin[a*x]^n*Gamma[n, -2*I*ArcSin[a*x]])/(((-I)*ArcSin[a*x])^n*a^2) - (2^(-3 - n)*n*ArcSin[a*x]^n*Gamma[n, 2*I*ArcSin[a*x]])/((I*ArcSin[a*x])^n*a^2)}
{ArcSin[a*x]^n, x, 1, -((I*ArcSin[a*x]^n*(Gamma[1 + n, (-I)*ArcSin[a*x]]/((-I)*ArcSin[a*x])^n - Gamma[1 + n, I*ArcSin[a*x]]/(I*ArcSin[a*x])^n))/(2*a))}
{ArcSin[a*x]^n/x, x, 2, Subst[Int[x^n*Cot[x], x], x, ArcSin[a*x]]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcSin[a+b x]^n*)


(* Integrands of the form x^m*ArcSin[a+b*x] where m is an integer *)
{x^3*ArcSin[a + b*x], x, 13, -((5*a*(11 + 10*a^2)*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(96*b^4)) + ((9 + 26*a^2)*x*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(96*b^3) - (7*a*x^2*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(48*b^2) + (x^3*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(16*b) - ((3 + 24*a^2 + 8*a^4)*ArcSin[a + b*x])/(32*b^4) + (1/4)*x^4*ArcSin[a + b*x], -((55*a*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(96*b^4)) - (25*a^3*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(48*b^4) + (3*x*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(32*b^3) + (13*a^2*x*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(48*b^3) - (7*a*x^2*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(48*b^2) + (x^3*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(16*b) - (15*a^2*ArcSin[a + b*x])/(16*b^4) - (5*a^4*ArcSin[a + b*x])/(32*b^4) - (3*(1 - a^2)^2*ArcSin[a + b*x])/(32*b^4) + (1/4)*x^4*ArcSin[a + b*x]}
{x^2*ArcSin[a + b*x], x, 8, ((4 + 11*a^2)*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(18*b^3) - (5*a*x*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(18*b^2) + (x^2*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(9*b) + ((3*a + 2*a^3 + 2*b^3*x^3)*ArcSin[a + b*x])/(6*b^3), (2*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(9*b^3) + (11*a^2*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(18*b^3) - (5*a*x*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(18*b^2) + (x^2*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(9*b) + (a*ArcSin[a + b*x])/(2*b^3) + (a^3*ArcSin[a + b*x])/(3*b^3) + (1/3)*x^3*ArcSin[a + b*x]}
{x*ArcSin[a + b*x], x, 5, -((3*a*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(4*b^2)) + (x*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(4*b) - ((1 + 2*a^2)*ArcSin[a + b*x])/(4*b^2) + (1/2)*x^2*ArcSin[a + b*x], -((3*a*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(4*b^2)) + (x*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(4*b) - ArcSin[a + b*x]/(4*b^2) - (a^2*ArcSin[a + b*x])/(2*b^2) + (1/2)*x^2*ArcSin[a + b*x]}
{ArcSin[a + b*x], x, 1, Sqrt[1 - (a + b*x)^2]/b + ((a + b*x)*ArcSin[a + b*x])/b}
{ArcSin[a + b*x]/x, x, -3, (1/8)*I*(Pi - 2*ArcSin[a + b*x])^2 + (1/2)*Pi*Log[b*x] - 2*I*ArcTanh[((1 + a)*(-1 + a + b*x - I*Sqrt[1 - (a + b*x)^2]))/(Sqrt[-1 + a^2]*(1 + a + b*x - I*Sqrt[1 - (a + b*x)^2]))]*(Log[2] - 2*Log[I*Sqrt[1 - a] + Sqrt[1 + a]]) - (ArcCos[a + b*x] + I*(Log[2] - 2*Log[I*Sqrt[1 - a] + Sqrt[1 + a]]))*Log[1 - (a + Sqrt[-1 + a^2])*(a + b*x + I*Sqrt[1 - (a + b*x)^2])] - (ArcCos[a + b*x] - I*(Log[2] - 2*Log[I*Sqrt[1 - a] + Sqrt[1 + a]]))*Log[1 + (-a + Sqrt[-1 + a^2])*(a + b*x + I*Sqrt[1 - (a + b*x)^2])] + I*PolyLog[2, (a - Sqrt[-1 + a^2])*(a + b*x + I*Sqrt[1 - (a + b*x)^2])] + I*PolyLog[2, (a + Sqrt[-1 + a^2])*(a + b*x + I*Sqrt[1 - (a + b*x)^2])]}
{ArcSin[a + b*x]/x^2, x, 2, -(ArcSin[a + b*x]/x) - (b*ArcTanh[(1 - a^2 - a*b*x)/(Sqrt[1 - a^2]*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])])/Sqrt[1 - a^2]}
{ArcSin[a + b*x]/x^3, x, 3, -((b*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(2*(1 - a^2)*x)) - ArcSin[a + b*x]/(2*x^2) - (a*b^2*ArcTanh[(1 - a^2 - a*b*x)/(Sqrt[1 - a^2]*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])])/(2*(1 - a^2)^(3/2))}


(* Integrands of the form x^m*ArcSin[a+b*x]^2 where m is an integer *)
{x^3*ArcSin[a + b*x]^2, x, 15, (4*a*(a + b*x))/(3*b^4) + (2*a^3*(a + b*x))/b^4 - (3*(a + b*x)^2)/(32*b^4) - (3*a^2*(a + b*x)^2)/(4*b^4) + (2*a*(a + b*x)^3)/(9*b^4) - (a + b*x)^4/(32*b^4) - (55*a*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x])/(48*b^4) - (a^3*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x])/(2*b^4) + (3*x*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x])/(16*b^3) + (3*a^2*x*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x])/(2*b^3) - (2*a*(a + b*x)^2*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x])/(3*b^4) + ((a + b*x)^3*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x])/(8*b^4) - (3*ArcSin[a + b*x]^2)/(32*b^4) - (3*a^2*ArcSin[a + b*x]^2)/(4*b^4) - (a^4*ArcSin[a + b*x]^2)/(4*b^4) + (1/4)*x^4*ArcSin[a + b*x]^2}
{x^2*ArcSin[a + b*x]^2, x, 12, -((4*(a + b*x))/(9*b^3)) - (2*a^2*(a + b*x))/b^3 + (a*(a + b*x)^2)/(2*b^3) - (2*(a + b*x)^3)/(27*b^3) + (4*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x])/(9*b^3) + (a^2*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x])/b^3 - (a*x*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x])/b^2 + (2*(a + b*x)^2*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x])/(9*b^3) + (a*ArcSin[a + b*x]^2)/(2*b^3) + (a^3*ArcSin[a + b*x]^2)/(3*b^3) + (1/3)*x^3*ArcSin[a + b*x]^2}
{x*ArcSin[a + b*x]^2, x, 9, (2*a*(a + b*x))/b^2 - (a + b*x)^2/(4*b^2) - (3*a*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x])/(2*b^2) + (x*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x])/(2*b) - ArcSin[a + b*x]^2/(4*b^2) - (a*(a + b*x)*ArcSin[a + b*x]^2)/b^2 + ((a + b*x)^2*ArcSin[a + b*x]^2)/(2*b^2)}
{ArcSin[a + b*x]^2, x, 2, -2*x + (2*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x])/b + ((a + b*x)*ArcSin[a + b*x]^2)/b}
{ArcSin[a + b*x]^2/x, x, 3, Subst[Int[(x^2*Cos[x])/(-a + Sin[x]), x], x, ArcSin[a + b*x]]}
{ArcSin[a + b*x]^2/x^2, x, 10, -(ArcSin[a + b*x]^2/x) + (2*I*b*ArcSin[a + b*x]*Log[1 + (I*E^(I*ArcSin[a + b*x]))/(a - Sqrt[-1 + a^2])])/Sqrt[-1 + a^2] - (2*I*b*ArcSin[a + b*x]*Log[1 + (I*E^(I*ArcSin[a + b*x]))/(a + Sqrt[-1 + a^2])])/Sqrt[-1 + a^2] + (2*b*PolyLog[2, -((I*E^(I*ArcSin[a + b*x]))/(a - Sqrt[-1 + a^2]))])/Sqrt[-1 + a^2] - (2*b*PolyLog[2, -((I*E^(I*ArcSin[a + b*x]))/(a + Sqrt[-1 + a^2]))])/Sqrt[-1 + a^2]}
{ArcSin[a + b*x]^2/x^3, x, 15, -((b*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x])/((1 - a^2)*x)) - ArcSin[a + b*x]^2/(2*x^2) - (I*a*b^2*ArcSin[a + b*x]*Log[1 + (I*E^(I*ArcSin[a + b*x]))/(a - Sqrt[-1 + a^2])])/(-1 + a^2)^(3/2) + (I*a*b^2*ArcSin[a + b*x]*Log[1 + (I*E^(I*ArcSin[a + b*x]))/(a + Sqrt[-1 + a^2])])/(-1 + a^2)^(3/2) + (b^2*Log[(-b)*x])/(1 - a^2) - (a*b^2*PolyLog[2, -((I*E^(I*ArcSin[a + b*x]))/(a - Sqrt[-1 + a^2]))])/(-1 + a^2)^(3/2) + (a*b^2*PolyLog[2, -((I*E^(I*ArcSin[a + b*x]))/(a + Sqrt[-1 + a^2]))])/(-1 + a^2)^(3/2)}


(* Integrands of the form x^m*ArcSin[a+b*x]^3 where m is an integer *)
{x^2*ArcSin[a + b*x]^3, x, 17, -((14*Sqrt[1 - (a + b*x)^2])/(9*b^3)) - (21*a^2*Sqrt[1 - (a + b*x)^2])/(4*b^3) + (3*a*x*Sqrt[1 - (a + b*x)^2])/(4*b^2) + (2*(1 - (a + b*x)^2)^(3/2))/(27*b^3) - (25*a*ArcSin[a + b*x])/(12*b^3) - (4*x*ArcSin[a + b*x])/(3*b^2) - (6*a^2*(a + b*x)*ArcSin[a + b*x])/b^3 + (3*a*(a + b*x)^2*ArcSin[a + b*x])/(2*b^3) - (2*(a + b*x)^3*ArcSin[a + b*x])/(9*b^3) + (2*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x]^2)/(3*b^3) + (3*a^2*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x]^2)/(2*b^3) - (3*a*x*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x]^2)/(2*b^2) + ((a + b*x)^2*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x]^2)/(3*b^3) + (a*ArcSin[a + b*x]^3)/(2*b^3) + (a^3*ArcSin[a + b*x]^3)/(3*b^3) + (1/3)*x^3*ArcSin[a + b*x]^3}
{x*ArcSin[a + b*x]^3, x, 11, (45*a*Sqrt[1 - (a + b*x)^2])/(8*b^2) - (3*x*Sqrt[1 - (a + b*x)^2])/(8*b) + (3*ArcSin[a + b*x])/(8*b^2) + (6*a*(a + b*x)*ArcSin[a + b*x])/b^2 - (3*(a + b*x)^2*ArcSin[a + b*x])/(4*b^2) - (9*a*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x]^2)/(4*b^2) + (3*x*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x]^2)/(4*b) - ArcSin[a + b*x]^3/(4*b^2) - (a*(a + b*x)*ArcSin[a + b*x]^3)/b^2 + ((a + b*x)^2*ArcSin[a + b*x]^3)/(2*b^2)}
{ArcSin[a + b*x]^3, x, 2, -((6*Sqrt[1 - (a + b*x)^2])/b) - (6*(a + b*x)*ArcSin[a + b*x])/b + (3*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x]^2)/b + ((a + b*x)*ArcSin[a + b*x]^3)/b}
{ArcSin[a + b*x]^3/x, x, 3, Subst[Int[(x^3*Cos[x])/(-a + Sin[x]), x], x, ArcSin[a + b*x]]}
{ArcSin[a + b*x]^3/x^2, x, 12, -(ArcSin[a + b*x]^3/x) + (3*I*b*ArcSin[a + b*x]^2*Log[1 + (I*E^(I*ArcSin[a + b*x]))/(a - Sqrt[-1 + a^2])])/Sqrt[-1 + a^2] - (3*I*b*ArcSin[a + b*x]^2*Log[1 + (I*E^(I*ArcSin[a + b*x]))/(a + Sqrt[-1 + a^2])])/Sqrt[-1 + a^2] + (6*b*ArcSin[a + b*x]*PolyLog[2, -((I*E^(I*ArcSin[a + b*x]))/(a - Sqrt[-1 + a^2]))])/Sqrt[-1 + a^2] - (6*b*ArcSin[a + b*x]*PolyLog[2, -((I*E^(I*ArcSin[a + b*x]))/(a + Sqrt[-1 + a^2]))])/Sqrt[-1 + a^2] + (6*I*b*PolyLog[3, -((I*E^(I*ArcSin[a + b*x]))/(a - Sqrt[-1 + a^2]))])/Sqrt[-1 + a^2] - (6*I*b*PolyLog[3, -((I*E^(I*ArcSin[a + b*x]))/(a + Sqrt[-1 + a^2]))])/Sqrt[-1 + a^2]}


(* Integrands of the form x^m/ArcSin[a+b*x] where m is an integer *)
{x^2/ArcSin[a + b*x], x, 11, ((1 + 4*a^2)*CosIntegral[ArcSin[a + b*x]])/(4*b^3) - CosIntegral[3*ArcSin[a + b*x]]/(4*b^3) - (a*SinIntegral[2*ArcSin[a + b*x]])/b^3}
{x/ArcSin[a + b*x], x, 7, -((a*CosIntegral[ArcSin[a + b*x]])/b^2) + SinIntegral[2*ArcSin[a + b*x]]/(2*b^2)}
{1/ArcSin[a + b*x], x, 1, CosIntegral[ArcSin[a + b*x]]/b}
{1/(x*ArcSin[a + b*x]), x, 3, Subst[Int[Cos[x]/(x*(-a + Sin[x])), x], x, ArcSin[a + b*x]]}


(* Integrands of the form x^m/ArcSin[a+b*x]^2 where m is an integer *)
{x^2/ArcSin[a + b*x]^2, x, 15, -((x^2*Sqrt[1 - (a + b*x)^2])/(b*ArcSin[a + b*x])) - (2*a*CosIntegral[2*ArcSin[a + b*x]])/b^3 - ((1 + 4*a^2)*SinIntegral[ArcSin[a + b*x]])/(4*b^3) + (3*SinIntegral[3*ArcSin[a + b*x]])/(4*b^3), -(Sqrt[1 - (a + b*x)^2]/(4*b^3*ArcSin[a + b*x])) - (a^2*Sqrt[1 - (a + b*x)^2])/(b^3*ArcSin[a + b*x]) + Cos[3*ArcSin[a + b*x]]/(4*b^3*ArcSin[a + b*x]) - (2*a*CosIntegral[2*ArcSin[a + b*x]])/b^3 + (a*Sin[2*ArcSin[a + b*x]])/(b^3*ArcSin[a + b*x]) - ((1 + 4*a^2)*SinIntegral[ArcSin[a + b*x]])/(4*b^3) + (3*SinIntegral[3*ArcSin[a + b*x]])/(4*b^3)}
{x/ArcSin[a + b*x]^2, x, 9, -((x*Sqrt[1 - (a + b*x)^2])/(b*ArcSin[a + b*x])) + CosIntegral[2*ArcSin[a + b*x]]/b^2 + (a*SinIntegral[ArcSin[a + b*x]])/b^2, (a*Sqrt[1 - (a + b*x)^2])/(b^2*ArcSin[a + b*x]) + CosIntegral[2*ArcSin[a + b*x]]/b^2 - Sin[2*ArcSin[a + b*x]]/(2*b^2*ArcSin[a + b*x]) + (a*SinIntegral[ArcSin[a + b*x]])/b^2}
{1/ArcSin[a + b*x]^2, x, 1, -(Sqrt[1 - (a + b*x)^2]/(b*ArcSin[a + b*x])) - SinIntegral[ArcSin[a + b*x]]/b}
{1/(x*ArcSin[a + b*x]^2), x, 3, Subst[Int[Cos[x]/(x^2*(-a + Sin[x])), x], x, ArcSin[a + b*x]]}


(* Integrands of the form x^m/ArcSin[a+b*x]^3 where m is an integer *)
{x^2/ArcSin[a + b*x]^3, x, 19, -((x^2*Sqrt[1 - (a + b*x)^2])/(2*b*ArcSin[a + b*x]^2)) + (a^2*(a + b*x))/(2*b^3*ArcSin[a + b*x]) - (2*a*(a + b*x)^2)/(b^3*ArcSin[a + b*x]) + (9*a + b*x)/(8*b^3*ArcSin[a + b*x]) - ((1 + 4*a^2)*CosIntegral[ArcSin[a + b*x]])/(8*b^3) + (9*CosIntegral[3*ArcSin[a + b*x]])/(8*b^3) - (3*Sin[3*ArcSin[a + b*x]])/(8*b^3*ArcSin[a + b*x]) + (2*a*SinIntegral[2*ArcSin[a + b*x]])/b^3, -(Sqrt[1 - (a + b*x)^2]/(8*b^3*ArcSin[a + b*x]^2)) - (a^2*Sqrt[1 - (a + b*x)^2])/(2*b^3*ArcSin[a + b*x]^2) + (a^2*(a + b*x))/(2*b^3*ArcSin[a + b*x]) - (2*a*(a + b*x)^2)/(b^3*ArcSin[a + b*x]) + (9*a + b*x)/(8*b^3*ArcSin[a + b*x]) + Cos[3*ArcSin[a + b*x]]/(8*b^3*ArcSin[a + b*x]^2) - ((1 + 4*a^2)*CosIntegral[ArcSin[a + b*x]])/(8*b^3) + (9*CosIntegral[3*ArcSin[a + b*x]])/(8*b^3) + (a*Sin[2*ArcSin[a + b*x]])/(2*b^3*ArcSin[a + b*x]^2) - (3*Sin[3*ArcSin[a + b*x]])/(8*b^3*ArcSin[a + b*x]) + (2*a*SinIntegral[2*ArcSin[a + b*x]])/b^3}
{x/ArcSin[a + b*x]^3, x, 11, -((x*Sqrt[1 - (a + b*x)^2])/(2*b*ArcSin[a + b*x]^2)) - (a*(a + b*x))/(2*b^2*ArcSin[a + b*x]) - (1 - 2*(a + b*x)^2)/(2*b^2*ArcSin[a + b*x]) + (a*CosIntegral[ArcSin[a + b*x]])/(2*b^2) - SinIntegral[2*ArcSin[a + b*x]]/b^2, (a*Sqrt[1 - (a + b*x)^2])/(2*b^2*ArcSin[a + b*x]^2) - (a*(a + b*x))/(2*b^2*ArcSin[a + b*x]) - (1 - 2*(a + b*x)^2)/(2*b^2*ArcSin[a + b*x]) + (a*CosIntegral[ArcSin[a + b*x]])/(2*b^2) - Sin[2*ArcSin[a + b*x]]/(4*b^2*ArcSin[a + b*x]^2) - SinIntegral[2*ArcSin[a + b*x]]/b^2}
{1/ArcSin[a + b*x]^3, x, 2, -(Sqrt[1 - (a + b*x)^2]/(2*b*ArcSin[a + b*x]^2)) + (a + b*x)/(2*b*ArcSin[a + b*x]) - CosIntegral[ArcSin[a + b*x]]/(2*b)}
{1/(x*ArcSin[a + b*x]^3), x, 3, Subst[Int[Cos[x]/(x^3*(-a + Sin[x])), x], x, ArcSin[a + b*x]]}


(* Integrands of the form ArcSin[a+b*x]^n where n is a half-integer *)
{Sqrt[ArcSin[a + b*x]], x, 1, ((a + b*x)*Sqrt[ArcSin[a + b*x]])/b - (Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcSin[a + b*x]]])/b}
{ArcSin[a + b*x]^(3/2), x, 2, (3*Sqrt[1 - (a + b*x)^2]*Sqrt[ArcSin[a + b*x]])/(2*b) + ((a + b*x)*ArcSin[a + b*x]^(3/2))/b - (3*Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[ArcSin[a + b*x]]])/(2*b)}
{ArcSin[a + b*x]^(5/2), x, 2, -((15*(a + b*x)*Sqrt[ArcSin[a + b*x]])/(4*b)) + (5*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x]^(3/2))/(2*b) + ((a + b*x)*ArcSin[a + b*x]^(5/2))/b + (15*Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcSin[a + b*x]]])/(4*b)}
{1/Sqrt[ArcSin[a + b*x]], x, 1, (Sqrt[2*Pi]*FresnelC[Sqrt[2/Pi]*Sqrt[ArcSin[a + b*x]]])/b}
{ArcSin[a + b*x]^(-3/2), x, 2, -((2*Sqrt[1 - (a + b*x)^2])/(b*Sqrt[ArcSin[a + b*x]])) - (2*Sqrt[2*Pi]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcSin[a + b*x]]])/b}
{ArcSin[a + b*x]^(-5/2), x, 2, -((2*Sqrt[1 - (a + b*x)^2])/(3*b*ArcSin[a + b*x]^(3/2))) + (4*(a + b*x))/(3*b*Sqrt[ArcSin[a + b*x]]) - (4*Sqrt[2*Pi]*FresnelC[Sqrt[2/Pi]*Sqrt[ArcSin[a + b*x]]])/(3*b)}


(* Integrands of the form x^m/ArcSin[a + b*x]^n where m is an integer *)
{x^2*ArcSin[a + b*x]^n, x, 19, -((1/(8*b^3))*((I*(1 + 4*a^2)*ArcSin[a + b*x]^n*Gamma[1 + n, (-I)*ArcSin[a + b*x]])/((-I)*ArcSin[a + b*x])^n)) + (1/(8*b^3))*((I*(1 + 4*a^2)*ArcSin[a + b*x]^n*Gamma[1 + n, I*ArcSin[a + b*x]])/(I*ArcSin[a + b*x])^n) - (1/b^3)*(I*2^(-2 - n)*a*((-I)*ArcSin[a + b*x])^(-1 - n)*ArcSin[a + b*x]^(1 + n)*Gamma[1 + n, -2*I*ArcSin[a + b*x]]) + (1/b^3)*(I*2^(-2 - n)*a*(I*ArcSin[a + b*x])^(-1 - n)*ArcSin[a + b*x]^(1 + n)*Gamma[1 + n, 2*I*ArcSin[a + b*x]]) + (1/(8*b^3))*(3^(-1 - n)*((-I)*ArcSin[a + b*x])^(-1 - n)*ArcSin[a + b*x]^(1 + n)*Gamma[1 + n, -3*I*ArcSin[a + b*x]]) + (1/(8*b^3))*(3^(-1 - n)*(I*ArcSin[a + b*x])^(-1 - n)*ArcSin[a + b*x]^(1 + n)*Gamma[1 + n, 3*I*ArcSin[a + b*x]])}
{x*ArcSin[a + b*x]^n, x, 11, (a*((-I)*ArcSin[a + b*x])^(-1 - n)*ArcSin[a + b*x]^(1 + n)*Gamma[1 + n, (-I)*ArcSin[a + b*x]])/(2*b^2) + (a*(I*ArcSin[a + b*x])^(-1 - n)*ArcSin[a + b*x]^(1 + n)*Gamma[1 + n, I*ArcSin[a + b*x]])/(2*b^2) + (I*2^(-3 - n)*((-I)*ArcSin[a + b*x])^(-1 - n)*ArcSin[a + b*x]^(1 + n)*Gamma[1 + n, -2*I*ArcSin[a + b*x]])/b^2 - (I*2^(-3 - n)*(I*ArcSin[a + b*x])^(-1 - n)*ArcSin[a + b*x]^(1 + n)*Gamma[1 + n, 2*I*ArcSin[a + b*x]])/b^2}
{ArcSin[a + b*x]^n, x, 1, -((I*ArcSin[a + b*x]^n*(Gamma[1 + n, (-I)*ArcSin[a + b*x]]/((-I)*ArcSin[a + b*x])^n - Gamma[1 + n, I*ArcSin[a + b*x]]/(I*ArcSin[a + b*x])^n))/(2*b))}
{ArcSin[a + b*x]^n/x, x, 3, Subst[Int[(x^n*Cos[x])/(-a + Sin[x]), x], x, ArcSin[a + b*x]]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a+b ArcSin[c x])^n*)


(* Integrands of the form (a+b*ArcSin[c*x])^n where n is a half-integer *)
{(a + b*ArcSin[c*x])^(5/2), x, 9, (-(15/4))*b^2*x*Sqrt[a + b*ArcSin[c*x]] + (5*b*Sqrt[1 - c^2*x^2]*(a + b*ArcSin[c*x])^(3/2))/(2*c) + x*(a + b*ArcSin[c*x])^(5/2) + (15*b^(5/2)*Sqrt[Pi/2]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(4*c) - (15*b^(5/2)*Sqrt[Pi/2]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[a/b])/(4*c)}
{(a + b*ArcSin[c*x])^(3/2), x, 8, (3*b*Sqrt[1 - c^2*x^2]*Sqrt[a + b*ArcSin[c*x]])/(2*c) + x*(a + b*ArcSin[c*x])^(3/2) - (3*b^(3/2)*Sqrt[Pi/2]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(2*c) - (3*b^(3/2)*Sqrt[Pi/2]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[a/b])/(2*c)}
{(a + b*ArcSin[c*x])^(1/2), x, 7, x*Sqrt[a + b*ArcSin[c*x]] - (Sqrt[b]*Sqrt[Pi/2]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/c + (Sqrt[b]*Sqrt[Pi/2]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[a/b])/c}
{1/(a + b*ArcSin[c*x])^(1/2), x, 6, (Sqrt[2*Pi]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(Sqrt[b]*c) + (Sqrt[2*Pi]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[a/b])/(Sqrt[b]*c)}
{1/(a + b*ArcSin[c*x])^(3/2), x, 7, -((2*Sqrt[1 - c^2*x^2])/(b*c*Sqrt[a + b*ArcSin[c*x]])) - (2*Sqrt[2*Pi]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(b^(3/2)*c) + (2*Sqrt[2*Pi]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[a/b])/(b^(3/2)*c)}
{1/(a + b*ArcSin[c*x])^(5/2), x, 8, -((2*Sqrt[1 - c^2*x^2])/(3*b*c*(a + b*ArcSin[c*x])^(3/2))) + (4*x)/(3*b^2*Sqrt[a + b*ArcSin[c*x]]) - (4*Sqrt[2*Pi]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(3*b^(5/2)*c) - (4*Sqrt[2*Pi]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[a/b])/(3*b^(5/2)*c)}
{1/(a + b*ArcSin[c*x])^(7/2), x, 9, -((2*Sqrt[1 - c^2*x^2])/(5*b*c*(a + b*ArcSin[c*x])^(5/2))) + (4*x)/(15*b^2*(a + b*ArcSin[c*x])^(3/2)) + (8*Sqrt[1 - c^2*x^2])/(15*b^3*c*Sqrt[a + b*ArcSin[c*x]]) + (8*Sqrt[2*Pi]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(15*b^(7/2)*c) - (8*Sqrt[2*Pi]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[a/b])/(15*b^(7/2)*c)}


(* Integrands of the form x*(a+b*ArcSin[c*x])^n where n is a half-integer *)
{x*(a + b*ArcSin[c*x])^(5/2), x, 9, (15*b^2*Sqrt[a + b*ArcSin[c*x]]*Cos[2*ArcSin[c*x]])/(64*c^2) - ((a + b*ArcSin[c*x])^(5/2)*Cos[2*ArcSin[c*x]])/(4*c^2) - (15*b^(5/2)*Sqrt[Pi]*Cos[(2*a)/b]*FresnelC[(2*Sqrt[a + b*ArcSin[c*x]])/(Sqrt[b]*Sqrt[Pi])])/(128*c^2) - (15*b^(5/2)*Sqrt[Pi]*FresnelS[(2*Sqrt[a + b*ArcSin[c*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(128*c^2) + (5*b*(a + b*ArcSin[c*x])^(3/2)*Sin[2*ArcSin[c*x]])/(16*c^2)}
{x*(a + b*ArcSin[c*x])^(3/2), x, 8, -(((a + b*ArcSin[c*x])^(3/2)*Cos[2*ArcSin[c*x]])/(4*c^2)) - (3*b^(3/2)*Sqrt[Pi]*Cos[(2*a)/b]*FresnelS[(2*Sqrt[a + b*ArcSin[c*x]])/(Sqrt[b]*Sqrt[Pi])])/(32*c^2) + (3*b^(3/2)*Sqrt[Pi]*FresnelC[(2*Sqrt[a + b*ArcSin[c*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(32*c^2) + (3*b*Sqrt[a + b*ArcSin[c*x]]*Sin[2*ArcSin[c*x]])/(16*c^2)}
{x*(a + b*ArcSin[c*x])^(1/2), x, 7, -((Sqrt[a + b*ArcSin[c*x]]*Cos[2*ArcSin[c*x]])/(4*c^2)) + (Sqrt[b]*Sqrt[Pi]*Cos[(2*a)/b]*FresnelC[(2*Sqrt[a + b*ArcSin[c*x]])/(Sqrt[b]*Sqrt[Pi])])/(8*c^2) + (Sqrt[b]*Sqrt[Pi]*FresnelS[(2*Sqrt[a + b*ArcSin[c*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(8*c^2)}
{x/(a + b*ArcSin[c*x])^(1/2), x, 6, (Sqrt[Pi]*Cos[(2*a)/b]*FresnelS[(2*Sqrt[a + b*ArcSin[c*x]])/(Sqrt[b]*Sqrt[Pi])])/(2*Sqrt[b]*c^2) - (Sqrt[Pi]*FresnelC[(2*Sqrt[a + b*ArcSin[c*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(2*Sqrt[b]*c^2)}
{x/(a + b*ArcSin[c*x])^(3/2), x, 7, (2*Sqrt[Pi]*Cos[(2*a)/b]*FresnelC[(2*Sqrt[a + b*ArcSin[c*x]])/(Sqrt[b]*Sqrt[Pi])])/(b^(3/2)*c^2) + (2*Sqrt[Pi]*FresnelS[(2*Sqrt[a + b*ArcSin[c*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(b^(3/2)*c^2) - Sin[2*ArcSin[c*x]]/(b*c^2*Sqrt[a + b*ArcSin[c*x]])}
{x/(a + b*ArcSin[c*x])^(5/2), x, 8, -((4*Cos[2*ArcSin[c*x]])/(3*b^2*c^2*Sqrt[a + b*ArcSin[c*x]])) - (8*Sqrt[Pi]*Cos[(2*a)/b]*FresnelS[(2*Sqrt[a + b*ArcSin[c*x]])/(Sqrt[b]*Sqrt[Pi])])/(3*b^(5/2)*c^2) + (8*Sqrt[Pi]*FresnelC[(2*Sqrt[a + b*ArcSin[c*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(3*b^(5/2)*c^2) - Sin[2*ArcSin[c*x]]/(3*b*c^2*(a + b*ArcSin[c*x])^(3/2))}
{x/(a + b*ArcSin[c*x])^(7/2), x, 9, -((4*Cos[2*ArcSin[c*x]])/(15*b^2*c^2*(a + b*ArcSin[c*x])^(3/2))) - (32*Sqrt[Pi]*Cos[(2*a)/b]*FresnelC[(2*Sqrt[a + b*ArcSin[c*x]])/(Sqrt[b]*Sqrt[Pi])])/(15*b^(7/2)*c^2) - (32*Sqrt[Pi]*FresnelS[(2*Sqrt[a + b*ArcSin[c*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(15*b^(7/2)*c^2) - Sin[2*ArcSin[c*x]]/(5*b*c^2*(a + b*ArcSin[c*x])^(5/2)) + (16*Sin[2*ArcSin[c*x]])/(15*b^3*c^2*Sqrt[a + b*ArcSin[c*x]])}


(* Integrands of the form x^2*(a+b*ArcSin[c*x])^n where n is a half-integer *)
{x^2*(a + b*ArcSin[c*x])^(5/2), x, 20, -((5*b^2*x*Sqrt[a + b*ArcSin[c*x]])/(6*c^2)) - (5/36)*b^2*x^3*Sqrt[a + b*ArcSin[c*x]] + (5*b*Sqrt[1 - c^2*x^2]*(a + b*ArcSin[c*x])^(3/2))/(9*c^3) + (5*b*x^2*Sqrt[1 - c^2*x^2]*(a + b*ArcSin[c*x])^(3/2))/(18*c) + (1/3)*x^3*(a + b*ArcSin[c*x])^(5/2) + (15*b^(5/2)*Sqrt[Pi/2]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(16*c^3) - (5*b^(5/2)*Sqrt[Pi/6]*Cos[(3*a)/b]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(144*c^3) - (15*b^(5/2)*Sqrt[Pi/2]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[a/b])/(16*c^3) + (5*b^(5/2)*Sqrt[Pi/6]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[(3*a)/b])/(144*c^3)}
{x^2*(a + b*ArcSin[c*x])^(3/2), x, 15, (b*Sqrt[1 - c^2*x^2]*Sqrt[a + b*ArcSin[c*x]])/(3*c^3) + (b*x^2*Sqrt[1 - c^2*x^2]*Sqrt[a + b*ArcSin[c*x]])/(6*c) + (1/3)*x^3*(a + b*ArcSin[c*x])^(3/2) - (3*b^(3/2)*Sqrt[Pi/2]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(8*c^3) + (b^(3/2)*Sqrt[Pi/6]*Cos[(3*a)/b]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(24*c^3) - (3*b^(3/2)*Sqrt[Pi/2]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[a/b])/(8*c^3) + (b^(3/2)*Sqrt[Pi/6]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[(3*a)/b])/(24*c^3), (3*b*Sqrt[1 - c^2*x^2]*Sqrt[a + b*ArcSin[c*x]])/(8*c^3) + (1/3)*x^3*(a + b*ArcSin[c*x])^(3/2) - (b*Sqrt[a + b*ArcSin[c*x]]*Cos[3*ArcSin[c*x]])/(24*c^3) - (3*b^(3/2)*Sqrt[Pi/2]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(8*c^3) + (b^(3/2)*Sqrt[Pi/6]*Cos[(3*a)/b]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(24*c^3) - (3*b^(3/2)*Sqrt[Pi/2]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[a/b])/(8*c^3) + (b^(3/2)*Sqrt[Pi/6]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[(3*a)/b])/(24*c^3)}
{x^2*(a + b*ArcSin[c*x])^(1/2), x, 13, (1/3)*x^3*Sqrt[a + b*ArcSin[c*x]] - (Sqrt[b]*Sqrt[Pi/2]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(4*c^3) + (Sqrt[b]*Sqrt[Pi/6]*Cos[(3*a)/b]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(12*c^3) + (Sqrt[b]*Sqrt[Pi/2]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[a/b])/(4*c^3) - (Sqrt[b]*Sqrt[Pi/6]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[(3*a)/b])/(12*c^3)}
{x^2/(a + b*ArcSin[c*x])^(1/2), x, 12, (Sqrt[Pi/2]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(2*Sqrt[b]*c^3) - (Sqrt[Pi/6]*Cos[(3*a)/b]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(2*Sqrt[b]*c^3) + (Sqrt[Pi/2]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[a/b])/(2*Sqrt[b]*c^3) - (Sqrt[Pi/6]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[(3*a)/b])/(2*Sqrt[b]*c^3)}
{x^2/(a + b*ArcSin[c*x])^(3/2), x, 14, -((2*x^2*Sqrt[1 - c^2*x^2])/(b*c*Sqrt[a + b*ArcSin[c*x]])) - (Sqrt[Pi/2]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(b^(3/2)*c^3) + (Sqrt[(3*Pi)/2]*Cos[(3*a)/b]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(b^(3/2)*c^3) + (Sqrt[Pi/2]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[a/b])/(b^(3/2)*c^3) - (Sqrt[(3*Pi)/2]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[(3*a)/b])/(b^(3/2)*c^3), -(Sqrt[1 - c^2*x^2]/(2*b*c^3*Sqrt[a + b*ArcSin[c*x]])) + Cos[3*ArcSin[c*x]]/(2*b*c^3*Sqrt[a + b*ArcSin[c*x]]) - (Sqrt[Pi/2]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(b^(3/2)*c^3) + (Sqrt[(3*Pi)/2]*Cos[(3*a)/b]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(b^(3/2)*c^3) + (Sqrt[Pi/2]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[a/b])/(b^(3/2)*c^3) - (Sqrt[(3*Pi)/2]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[(3*a)/b])/(b^(3/2)*c^3)}
{x^2/(a + b*ArcSin[c*x])^(5/2), x, 16, -((2*x^2*Sqrt[1 - c^2*x^2])/(3*b*c*(a + b*ArcSin[c*x])^(3/2))) - (8*x)/(3*b^2*c^2*Sqrt[a + b*ArcSin[c*x]]) + (4*x^3)/(b^2*Sqrt[a + b*ArcSin[c*x]]) - (Sqrt[2*Pi]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(3*b^(5/2)*c^3) + (Sqrt[6*Pi]*Cos[(3*a)/b]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(b^(5/2)*c^3) - (Sqrt[2*Pi]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[a/b])/(3*b^(5/2)*c^3) + (Sqrt[6*Pi]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[(3*a)/b])/(b^(5/2)*c^3), -(Sqrt[1 - c^2*x^2]/(6*b*c^3*(a + b*ArcSin[c*x])^(3/2))) + x/(3*b^2*c^2*Sqrt[a + b*ArcSin[c*x]]) + Cos[3*ArcSin[c*x]]/(6*b*c^3*(a + b*ArcSin[c*x])^(3/2)) - (Sqrt[2*Pi]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(3*b^(5/2)*c^3) + (Sqrt[6*Pi]*Cos[(3*a)/b]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(b^(5/2)*c^3) - (Sqrt[2*Pi]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[a/b])/(3*b^(5/2)*c^3) + (Sqrt[6*Pi]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[(3*a)/b])/(b^(5/2)*c^3) - Sin[3*ArcSin[c*x]]/(b^2*c^3*Sqrt[a + b*ArcSin[c*x]])}
{x^2/(a + b*ArcSin[c*x])^(7/2), x, 18, -((2*x^2*Sqrt[1 - c^2*x^2])/(5*b*c*(a + b*ArcSin[c*x])^(5/2))) - (8*x)/(15*b^2*c^2*(a + b*ArcSin[c*x])^(3/2)) + (4*x^3)/(5*b^2*(a + b*ArcSin[c*x])^(3/2)) - (16*Sqrt[1 - c^2*x^2])/(15*b^3*c^3*Sqrt[a + b*ArcSin[c*x]]) + (24*x^2*Sqrt[1 - c^2*x^2])/(5*b^3*c*Sqrt[a + b*ArcSin[c*x]]) + (2*Sqrt[2*Pi]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(15*b^(7/2)*c^3) - (6*Sqrt[6*Pi]*Cos[(3*a)/b]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(5*b^(7/2)*c^3) - (2*Sqrt[2*Pi]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[a/b])/(15*b^(7/2)*c^3) + (6*Sqrt[6*Pi]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[(3*a)/b])/(5*b^(7/2)*c^3), -(Sqrt[1 - c^2*x^2]/(10*b*c^3*(a + b*ArcSin[c*x])^(5/2))) + x/(15*b^2*c^2*(a + b*ArcSin[c*x])^(3/2)) + (2*Sqrt[1 - c^2*x^2])/(15*b^3*c^3*Sqrt[a + b*ArcSin[c*x]]) + Cos[3*ArcSin[c*x]]/(10*b*c^3*(a + b*ArcSin[c*x])^(5/2)) - (6*Cos[3*ArcSin[c*x]])/(5*b^3*c^3*Sqrt[a + b*ArcSin[c*x]]) + (2*Sqrt[2*Pi]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(15*b^(7/2)*c^3) - (6*Sqrt[6*Pi]*Cos[(3*a)/b]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(5*b^(7/2)*c^3) - (2*Sqrt[2*Pi]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[a/b])/(15*b^(7/2)*c^3) + (6*Sqrt[6*Pi]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[(3*a)/b])/(5*b^(7/2)*c^3) - Sin[3*ArcSin[c*x]]/(5*b^2*c^3*(a + b*ArcSin[c*x])^(3/2))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a+b ArcSin[c+d x])^n*)


(* Integrands of the form (a+b*ArcSin[c+d*x])^n where n is a half-integer *)
{(a + b*ArcSin[c + d*x])^(5/2), x, 9, -((15*b^2*(c + d*x)*Sqrt[a + b*ArcSin[c + d*x]])/(4*d)) + (5*b*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^(3/2))/(2*d) + ((c + d*x)*(a + b*ArcSin[c + d*x])^(5/2))/d + (15*b^(5/2)*Sqrt[Pi/2]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(4*d) - (15*b^(5/2)*Sqrt[Pi/2]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(4*d)}
{(a + b*ArcSin[c + d*x])^(3/2), x, 8, (3*b*Sqrt[1 - (c + d*x)^2]*Sqrt[a + b*ArcSin[c + d*x]])/(2*d) + ((c + d*x)*(a + b*ArcSin[c + d*x])^(3/2))/d - (3*b^(3/2)*Sqrt[Pi/2]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(2*d) - (3*b^(3/2)*Sqrt[Pi/2]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(2*d)}
{(a + b*ArcSin[c + d*x])^(1/2), x, 7, ((c + d*x)*Sqrt[a + b*ArcSin[c + d*x]])/d - (Sqrt[b]*Sqrt[Pi/2]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/d + (Sqrt[b]*Sqrt[Pi/2]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/d}
{1/(a + b*ArcSin[c + d*x])^(1/2), x, 6, (Sqrt[2*Pi]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(Sqrt[b]*d) + (Sqrt[2*Pi]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(Sqrt[b]*d)}
{1/(a + b*ArcSin[c + d*x])^(3/2), x, 7, -((2*Sqrt[1 - (c + d*x)^2])/(b*d*Sqrt[a + b*ArcSin[c + d*x]])) - (2*Sqrt[2*Pi]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(b^(3/2)*d) + (2*Sqrt[2*Pi]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(b^(3/2)*d)}
{1/(a + b*ArcSin[c + d*x])^(5/2), x, 8, -((2*Sqrt[1 - (c + d*x)^2])/(3*b*d*(a + b*ArcSin[c + d*x])^(3/2))) + (4*(c + d*x))/(3*b^2*d*Sqrt[a + b*ArcSin[c + d*x]]) - (4*Sqrt[2*Pi]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(3*b^(5/2)*d) - (4*Sqrt[2*Pi]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(3*b^(5/2)*d)}
{1/(a + b*ArcSin[c + d*x])^(7/2), x, 9, -((2*Sqrt[1 - (c + d*x)^2])/(5*b*d*(a + b*ArcSin[c + d*x])^(5/2))) + (4*(c + d*x))/(15*b^2*d*(a + b*ArcSin[c + d*x])^(3/2)) + (8*Sqrt[1 - (c + d*x)^2])/(15*b^3*d*Sqrt[a + b*ArcSin[c + d*x]]) + (8*Sqrt[2*Pi]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(15*b^(7/2)*d) - (8*Sqrt[2*Pi]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(15*b^(7/2)*d)}
{(a + b*ArcSin[c + d*x])^n, x, 5, -(((a + b*ArcSin[c + d*x])^(1 + n)*(-((I*(a + b*ArcSin[c + d*x]))/b))^(-1 - n)*Gamma[1 + n, -((I*(a + b*ArcSin[c + d*x]))/b)])/(E^((I*a)/b)*(2*b*d))) - (E^((I*a)/b)*(a + b*ArcSin[c + d*x])^(1 + n)*((I*(a + b*ArcSin[c + d*x]))/b)^(-1 - n)*Gamma[1 + n, (I*(a + b*ArcSin[c + d*x]))/b])/(2*b*d)}


(* Integrands of the form x*(a+b*ArcSin[c+d*x])^n where n is a half-integer *)
{x*(a + b*ArcSin[c + d*x])^(5/2), x, 18, (15*b^2*c*(c + d*x)*Sqrt[a + b*ArcSin[c + d*x]])/(4*d^2) - (5*b*c*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^(3/2))/(2*d^2) - (c*(c + d*x)*(a + b*ArcSin[c + d*x])^(5/2))/d^2 + (15*b^2*Sqrt[a + b*ArcSin[c + d*x]]*Cos[2*ArcSin[c + d*x]])/(64*d^2) - ((a + b*ArcSin[c + d*x])^(5/2)*Cos[2*ArcSin[c + d*x]])/(4*d^2) - (15*b^(5/2)*Sqrt[Pi]*Cos[(2*a)/b]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(128*d^2) - (15*b^(5/2)*c*Sqrt[Pi/2]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(4*d^2) + (15*b^(5/2)*c*Sqrt[Pi/2]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(4*d^2) - (15*b^(5/2)*Sqrt[Pi]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(128*d^2) + (5*b*(a + b*ArcSin[c + d*x])^(3/2)*Sin[2*ArcSin[c + d*x]])/(16*d^2)}
{x*(a + b*ArcSin[c + d*x])^(3/2), x, 16, -((3*b*c*Sqrt[1 - (c + d*x)^2]*Sqrt[a + b*ArcSin[c + d*x]])/(2*d^2)) - (c*(c + d*x)*(a + b*ArcSin[c + d*x])^(3/2))/d^2 - ((a + b*ArcSin[c + d*x])^(3/2)*Cos[2*ArcSin[c + d*x]])/(4*d^2) + (3*b^(3/2)*c*Sqrt[Pi/2]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(2*d^2) - (3*b^(3/2)*Sqrt[Pi]*Cos[(2*a)/b]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(32*d^2) + (3*b^(3/2)*c*Sqrt[Pi/2]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(2*d^2) + (3*b^(3/2)*Sqrt[Pi]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(32*d^2) + (3*b*Sqrt[a + b*ArcSin[c + d*x]]*Sin[2*ArcSin[c + d*x]])/(16*d^2)}
{x*(a + b*ArcSin[c + d*x])^(1/2), x, 14, -((c*(c + d*x)*Sqrt[a + b*ArcSin[c + d*x]])/d^2) - (Sqrt[a + b*ArcSin[c + d*x]]*Cos[2*ArcSin[c + d*x]])/(4*d^2) + (Sqrt[b]*Sqrt[Pi]*Cos[(2*a)/b]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(8*d^2) + (Sqrt[b]*c*Sqrt[Pi/2]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/d^2 - (Sqrt[b]*c*Sqrt[Pi/2]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/d^2 + (Sqrt[b]*Sqrt[Pi]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(8*d^2)}
{x/(a + b*ArcSin[c + d*x])^(1/2), x, 12, -((c*Sqrt[2*Pi]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(Sqrt[b]*d^2)) + (Sqrt[Pi]*Cos[(2*a)/b]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(2*Sqrt[b]*d^2) - (c*Sqrt[2*Pi]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(Sqrt[b]*d^2) - (Sqrt[Pi]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(2*Sqrt[b]*d^2)}
{x/(a + b*ArcSin[c + d*x])^(3/2), x, 14, (2*c*Sqrt[1 - (c + d*x)^2])/(b*d^2*Sqrt[a + b*ArcSin[c + d*x]]) + (2*Sqrt[Pi]*Cos[(2*a)/b]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(b^(3/2)*d^2) + (2*c*Sqrt[2*Pi]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(b^(3/2)*d^2) - (2*c*Sqrt[2*Pi]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(b^(3/2)*d^2) + (2*Sqrt[Pi]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(b^(3/2)*d^2) - Sin[2*ArcSin[c + d*x]]/(b*d^2*Sqrt[a + b*ArcSin[c + d*x]])}
{x/(a + b*ArcSin[c + d*x])^(5/2), x, 16, (2*c*Sqrt[1 - (c + d*x)^2])/(3*b*d^2*(a + b*ArcSin[c + d*x])^(3/2)) - (4*c*(c + d*x))/(3*b^2*d^2*Sqrt[a + b*ArcSin[c + d*x]]) - (4*Cos[2*ArcSin[c + d*x]])/(3*b^2*d^2*Sqrt[a + b*ArcSin[c + d*x]]) + (4*c*Sqrt[2*Pi]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(3*b^(5/2)*d^2) - (8*Sqrt[Pi]*Cos[(2*a)/b]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(3*b^(5/2)*d^2) + (4*c*Sqrt[2*Pi]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(3*b^(5/2)*d^2) + (8*Sqrt[Pi]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(3*b^(5/2)*d^2) - Sin[2*ArcSin[c + d*x]]/(3*b*d^2*(a + b*ArcSin[c + d*x])^(3/2))}
{x/(a + b*ArcSin[c + d*x])^(7/2), x, 18, (2*c*Sqrt[1 - (c + d*x)^2])/(5*b*d^2*(a + b*ArcSin[c + d*x])^(5/2)) - (4*c*(c + d*x))/(15*b^2*d^2*(a + b*ArcSin[c + d*x])^(3/2)) - (8*c*Sqrt[1 - (c + d*x)^2])/(15*b^3*d^2*Sqrt[a + b*ArcSin[c + d*x]]) - (4*Cos[2*ArcSin[c + d*x]])/(15*b^2*d^2*(a + b*ArcSin[c + d*x])^(3/2)) - (32*Sqrt[Pi]*Cos[(2*a)/b]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(15*b^(7/2)*d^2) - (8*c*Sqrt[2*Pi]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(15*b^(7/2)*d^2) + (8*c*Sqrt[2*Pi]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(15*b^(7/2)*d^2) - (32*Sqrt[Pi]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(15*b^(7/2)*d^2) - Sin[2*ArcSin[c + d*x]]/(5*b*d^2*(a + b*ArcSin[c + d*x])^(5/2)) + (16*Sin[2*ArcSin[c + d*x]])/(15*b^3*d^2*Sqrt[a + b*ArcSin[c + d*x]])}
(* {x*(a + b*ArcSin[c + d*x])^n, x, 0, ((1/d^2)*2^(-3 - n)*(a + b*ArcSin[c + d*x])^n*((-((I*(a + b*ArcSin[c + d*x]))/b)^n)*Cos[(2*a)/b]*Gamma[1 + n, -((2*I*(a + b*ArcSin[c + d*x]))/b)] - (-((I*(a + b*ArcSin[c + d*x]))/b))^n*Cos[(2*a)/b]*Gamma[1 + n, (2*I*(a + b*ArcSin[c + d*x]))/b] + 2^(2 + n)*c*(-((I*(a + b*ArcSin[c + d*x]))/b))^n*Gamma[1 + n, (I*(a + b*ArcSin[c + d*x]))/b]*((-I)*Cos[a/b] + Sin[a/b]) + 2^(2 + n)*c*((I*(a + b*ArcSin[c + d*x]))/b)^n*Gamma[1 + n, -((I*(a + b*ArcSin[c + d*x]))/b)]*(I*Cos[a/b] + Sin[a/b]) + I*((I*(a + b*ArcSin[c + d*x]))/b)^n*Gamma[1 + n, -((2*I*(a + b*ArcSin[c + d*x]))/b)]*Sin[(2*a)/b] - I*(-((I*(a + b*ArcSin[c + d*x]))/b))^n*Gamma[1 + n, (2*I*(a + b*ArcSin[c + d*x]))/b]*Sin[(2*a)/b]))/((a + b*ArcSin[c + d*x])^2/b^2)^n} *)


(* Integrands of the form x^2*(a+b*ArcSin[c+d*x])^n where n is a half-integer *)
(* {x^2*(a + b*ArcSin[c + d*x])^(3/2), x, 30, (3*b*Sqrt[1 - (c + d*x)^2]*Sqrt[a + b*ArcSin[c + d*x]])/(8*d^3) + (3*b*c^2*Sqrt[1 - (c + d*x)^2]*Sqrt[a + b*ArcSin[c + d*x]])/(2*d^3) + ((c + d*x)*(a + b*ArcSin[c + d*x])^(3/2))/(4*d^3) + (c^2*(c + d*x)*(a + b*ArcSin[c + d*x])^(3/2))/d^3 + (c*(a + b*ArcSin[c + d*x])^(3/2)*Cos[2*ArcSin[c + d*x]])/(2*d^3) - (b*Sqrt[a + b*ArcSin[c + d*x]]*Cos[3*ArcSin[c + d*x]])/(24*d^3) - (3*b^(3/2)*(1 + 4*c^2)*Sqrt[Pi/2]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(8*d^3) + (b^(3/2)*Sqrt[Pi/6]*Cos[(3*a)/b]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(24*d^3) + (3*b^(3/2)*c*Sqrt[Pi]*Cos[(2*a)/b]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(16*d^3) - (3*b^(3/2)*(1 + 4*c^2)*Sqrt[Pi/2]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(8*d^3) - (3*b^(3/2)*c*Sqrt[Pi]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(16*d^3) + (b^(3/2)*Sqrt[Pi/6]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(3*a)/b])/(24*d^3) - (3*b*c*Sqrt[a + b*ArcSin[c + d*x]]*Sin[2*ArcSin[c + d*x]])/(8*d^3) - ((a + b*ArcSin[c + d*x])^(3/2)*Sin[3*ArcSin[c + d*x]])/(12*d^3)} *)
(* {x^2*(a + b*ArcSin[c + d*x])^(1/2), x, 25, (c*Sqrt[a + b*ArcSin[c + d*x]])/(2*d^3) + (c^3*Sqrt[a + b*ArcSin[c + d*x]])/(3*d^3) + (1/3)*x^3*Sqrt[a + b*ArcSin[c + d*x]] - (Sqrt[b]*c*Sqrt[Pi]*Cos[(2*a)/b]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(4*d^3) - (Sqrt[b]*(1 + 4*c^2)*Sqrt[Pi/2]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(4*d^3) + (Sqrt[b]*Sqrt[Pi/6]*Cos[(3*a)/b]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(12*d^3) + (Sqrt[b]*(1 + 4*c^2)*Sqrt[Pi/2]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(4*d^3) - (Sqrt[b]*c*Sqrt[Pi]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(4*d^3) - (Sqrt[b]*Sqrt[Pi/6]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(3*a)/b])/(12*d^3)} *)
{x^2/(a + b*ArcSin[c + d*x])^(1/2), x, 22, ((1 + 4*c^2)*Sqrt[Pi/2]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(2*Sqrt[b]*d^3) - (Sqrt[Pi/6]*Cos[(3*a)/b]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(2*Sqrt[b]*d^3) - (c*Sqrt[Pi]*Cos[(2*a)/b]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(Sqrt[b]*d^3) + ((1 + 4*c^2)*Sqrt[Pi/2]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(2*Sqrt[b]*d^3) + (c*Sqrt[Pi]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(Sqrt[b]*d^3) - (Sqrt[Pi/6]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(3*a)/b])/(2*Sqrt[b]*d^3)}
(* {x^2/(a + b*ArcSin[c + d*x])^(3/2), x, 30, -((2*x^2*Sqrt[1 - (c + d*x)^2])/(b*d*Sqrt[a + b*ArcSin[c + d*x]])) - (4*c*Sqrt[Pi]*Cos[(2*a)/b]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(b^(3/2)*d^3) - ((1 + 4*c^2)*Sqrt[Pi/2]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(b^(3/2)*d^3) + (Sqrt[(3*Pi)/2]*Cos[(3*a)/b]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(b^(3/2)*d^3) + ((1 + 4*c^2)*Sqrt[Pi/2]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(b^(3/2)*d^3) - (4*c*Sqrt[Pi]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(b^(3/2)*d^3) - (Sqrt[(3*Pi)/2]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(3*a)/b])/(b^(3/2)*d^3)} *)
(* {x^2/(a + b*ArcSin[c + d*x])^(5/2), x, 30, -(Sqrt[1 - (c + d*x)^2]/(6*b*d^3*(a + b*ArcSin[c + d*x])^(3/2))) - (2*c^2*Sqrt[1 - (c + d*x)^2])/(3*b*d^3*(a + b*ArcSin[c + d*x])^(3/2)) + (c + d*x)/(3*b^2*d^3*Sqrt[a + b*ArcSin[c + d*x]]) + (4*c^2*(c + d*x))/(3*b^2*d^3*Sqrt[a + b*ArcSin[c + d*x]]) + (8*c*Cos[2*ArcSin[c + d*x]])/(3*b^2*d^3*Sqrt[a + b*ArcSin[c + d*x]]) + Cos[3*ArcSin[c + d*x]]/(6*b*d^3*(a + b*ArcSin[c + d*x])^(3/2)) - ((1 + 4*c^2)*Sqrt[2*Pi]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(3*b^(5/2)*d^3) + (Sqrt[6*Pi]*Cos[(3*a)/b]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(b^(5/2)*d^3) + (16*c*Sqrt[Pi]*Cos[(2*a)/b]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(3*b^(5/2)*d^3) - ((1 + 4*c^2)*Sqrt[2*Pi]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(3*b^(5/2)*d^3) - (16*c*Sqrt[Pi]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(3*b^(5/2)*d^3) + (Sqrt[6*Pi]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(3*a)/b])/(b^(5/2)*d^3) + (2*c*Sin[2*ArcSin[c + d*x]])/(3*b*d^3*(a + b*ArcSin[c + d*x])^(3/2)) - Sin[3*ArcSin[c + d*x]]/(b^2*d^3*Sqrt[a + b*ArcSin[c + d*x]])} *)
(* {x^2*(a + b*ArcSin[c + d*x])^n, x, 0, ((1/(24*d^3))*(a + b*ArcSin[c + d*x])^n*(12*I*c^2*((-((I*(a + b*ArcSin[c + d*x]))/b)^n)*Gamma[1 + n, -((I*(a + b*ArcSin[c + d*x]))/b)]*(Cos[a/b] - I*Sin[a/b]) + (-((I*(a + b*ArcSin[c + d*x]))/b))^n*Gamma[1 + n, (I*(a + b*ArcSin[c + d*x]))/b]*(Cos[a/b] + I*Sin[a/b])) + 3*2^(1 - n)*c*(((I*(a + b*ArcSin[c + d*x]))/b)^n*Gamma[1 + n, -((2*I*(a + b*ArcSin[c + d*x]))/b)]*(Cos[(2*a)/b] - I*Sin[(2*a)/b]) + (-((I*(a + b*ArcSin[c + d*x]))/b))^n*Gamma[1 + n, (2*I*(a + b*ArcSin[c + d*x]))/b]*(Cos[(2*a)/b] + I*Sin[(2*a)/b])) + I*(3*((-((I*(a + b*ArcSin[c + d*x]))/b)^n)*Gamma[1 + n, -((I*(a + b*ArcSin[c + d*x]))/b)]*(Cos[a/b] - I*Sin[a/b]) + (-((I*(a + b*ArcSin[c + d*x]))/b))^n*Gamma[1 + n, (I*(a + b*ArcSin[c + d*x]))/b]*(Cos[a/b] + I*Sin[a/b])) + (((I*(a + b*ArcSin[c + d*x]))/b)^n*Gamma[1 + n, -((3*I*(a + b*ArcSin[c + d*x]))/b)]*(Cos[(3*a)/b] - I*Sin[(3*a)/b]) - (-((I*(a + b*ArcSin[c + d*x]))/b))^n*Gamma[1 + n, (3*I*(a + b*ArcSin[c + d*x]))/b]*(Cos[(3*a)/b] + I*Sin[(3*a)/b]))/3^n)))/((a + b*ArcSin[c + d*x])^2/b^2)^n} *)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcSin[a x^n]*)


{x^3*ArcSin[a*x^2], x, 5, (x^2*Sqrt[1 - a^2*x^4])/(8*a) - ArcSin[a*x^2]/(8*a^2) + (1/4)*x^4*ArcSin[a*x^2]}
{x^2*ArcSin[a*x^2], x, 4, (2*x*Sqrt[1 - a^2*x^4])/(9*a) + (1/3)*x^3*ArcSin[a*x^2] - (2*EllipticF[ArcSin[Sqrt[a]*x], -1])/(9*a^(3/2))}
{x*ArcSin[a*x^2], x, 2, Sqrt[1 - a^2*x^4]/(2*a) + (1/2)*x^2*ArcSin[a*x^2]}
{ArcSin[a*x^2], x, 3, x*ArcSin[a*x^2] - (2*EllipticE[ArcSin[Sqrt[a]*x], -1])/Sqrt[a] + (2*EllipticF[ArcSin[Sqrt[a]*x], -1])/Sqrt[a]}
{ArcSin[a*x^2]/x, x, 5, (-(1/4))*I*ArcSin[a*x^2]^2 + (1/2)*ArcSin[a*x^2]*Log[1 - E^(2*I*ArcSin[a*x^2])] - (1/4)*I*PolyLog[2, E^(2*I*ArcSin[a*x^2])]}
{ArcSin[a*x^2]/x^2, x, 3, -(ArcSin[a*x^2]/x) + 2*Sqrt[a]*EllipticF[ArcSin[Sqrt[a]*x], -1]}


{x^2*ArcSin[a/x], x, 4, (1/6)*a*Sqrt[1 - a^2/x^2]*x^2 + (1/3)*x^3*ArcCsc[x/a] + (1/6)*a^3*ArcTanh[Sqrt[1 - a^2/x^2]]}
{x*ArcSin[a/x], x, 3, (1/2)*a*Sqrt[1 - a^2/x^2]*x + (1/2)*x^2*ArcCsc[x/a]}
{ArcSin[a/x], x, 4, x*ArcCsc[x/a] + a*ArcTanh[Sqrt[1 - a^2/x^2]]}
{ArcSin[a/x]/x, x, 5, (1/2)*I*ArcSin[a/x]^2 - ArcSin[a/x]*Log[1 - E^(2*I*ArcSin[a/x])] + (1/2)*I*PolyLog[2, E^(2*I*ArcSin[a/x])]}
{ArcSin[a/x]/x^2, x, 4, -(Sqrt[1 - a^2/x^2]/a) - ArcCsc[x/a]/x}
{ArcSin[a/x]/x^3, x, 5, -(Sqrt[1 - a^2/x^2]/(4*a*x)) - ArcCsc[x/a]/(2*x^2) + ArcSin[a/x]/(4*a^2)}
{ArcSin[a/x]/x^4, x, 5, -((2*Sqrt[1 - a^2/x^2])/(9*a^3)) - Sqrt[1 - a^2/x^2]/(9*a*x^2) - ArcCsc[x/a]/(3*x^3)}


(* Integrands of the form x^m*ArcSin[Sqrt[x]] where m is an integer *)
{x^2*ArcSin[Sqrt[x]], x, 6, (5/48)*Sqrt[1 - x]*Sqrt[x] + (5/72)*Sqrt[1 - x]*x^(3/2) + (1/18)*Sqrt[1 - x]*x^(5/2) - (5*ArcSin[Sqrt[x]])/48 + (1/3)*x^3*ArcSin[Sqrt[x]]}
{x*ArcSin[Sqrt[x]], x, 5, (3/16)*Sqrt[1 - x]*Sqrt[x] + (1/8)*Sqrt[1 - x]*x^(3/2) - (3*ArcSin[Sqrt[x]])/16 + (1/2)*x^2*ArcSin[Sqrt[x]]}
{ArcSin[Sqrt[x]], x, 4, (1/2)*Sqrt[1 - x]*Sqrt[x] - ArcSin[Sqrt[x]]/2 + x*ArcSin[Sqrt[x]]}
{ArcSin[Sqrt[x]]/x, x, 5, (-I)*ArcSin[Sqrt[x]]^2 + 2*ArcSin[Sqrt[x]]*Log[1 - E^(2*I*ArcSin[Sqrt[x]])] - I*PolyLog[2, E^(2*I*ArcSin[Sqrt[x]])]}
{ArcSin[Sqrt[x]]/x^2, x, 3, -(Sqrt[1 - x]/Sqrt[x]) - ArcSin[Sqrt[x]]/x}
{ArcSin[Sqrt[x]]/x^3, x, 4, -(Sqrt[1 - x]/(6*x^(3/2))) - Sqrt[1 - x]/(3*Sqrt[x]) - ArcSin[Sqrt[x]]/(2*x^2)}
{ArcSin[Sqrt[x]]/x^4, x, 5, -(Sqrt[1 - x]/(15*x^(5/2))) - (4*Sqrt[1 - x])/(45*x^(3/2)) - (8*Sqrt[1 - x])/(45*Sqrt[x]) - ArcSin[Sqrt[x]]/(3*x^3)}
{ArcSin[Sqrt[x]]/x^5, x, 6, -(Sqrt[1 - x]/(28*x^(7/2))) - (3*Sqrt[1 - x])/(70*x^(5/2)) - (2*Sqrt[1 - x])/(35*x^(3/2)) - (4*Sqrt[1 - x])/(35*Sqrt[x]) - ArcSin[Sqrt[x]]/(4*x^4)}


(* Integrands of the form ArcTrig[a*x^n]/x *)
{ArcSin[a*x^n]/x, x, 5, -((I*ArcSin[a*x^n]^2)/(2*n)) + (ArcSin[a*x^n]*Log[1 - E^(2*I*ArcSin[a*x^n])])/n - (I*PolyLog[2, E^(2*I*ArcSin[a*x^n])])/(2*n)}
{ArcSin[a*x^5]/x, x, 5, (-(1/10))*I*ArcSin[a*x^5]^2 + (1/5)*ArcSin[a*x^5]*Log[1 - E^(2*I*ArcSin[a*x^5])] - (1/10)*I*PolyLog[2, E^(2*I*ArcSin[a*x^5])]}


(* ::Subsection::Closed:: *)
(*Integrands involving inverse trig functions of exponentials*)


{ArcSin[c*E^(a + b*x)], x, 6, -((I*ArcSin[c*E^(a + b*x)]^2)/(2*b)) + (ArcSin[c*E^(a + b*x)]*Log[1 - E^(2*I*ArcSin[c*E^(a + b*x)])])/b - (I*PolyLog[2, E^(2*I*ArcSin[c*E^(a + b*x)])])/(2*b)}


(* ::Subsection::Closed:: *)
(*Integrands involving exponentials of inverse trig functions*)


(* Integrands of the form x^m*E^ArcSin[x] where m is an integer *)
{x^3*E^ArcSin[x], x, 5, (-(1/10))*E^ArcSin[x]*Cos[2*ArcSin[x]] + (1/34)*E^ArcSin[x]*Cos[4*ArcSin[x]] + (1/20)*E^ArcSin[x]*Sin[2*ArcSin[x]] - (1/136)*E^ArcSin[x]*Sin[4*ArcSin[x]]}
{x^2*E^ArcSin[x], x, 5, (1/8)*E^ArcSin[x]*x + (1/8)*E^ArcSin[x]*Sqrt[1 - x^2] - (1/40)*E^ArcSin[x]*Cos[3*ArcSin[x]] - (3/40)*E^ArcSin[x]*Sin[3*ArcSin[x]]}
{x*E^ArcSin[x], x, 4, (-(1/5))*E^ArcSin[x]*Cos[2*ArcSin[x]] + (1/10)*E^ArcSin[x]*Sin[2*ArcSin[x]]}
{E^ArcSin[x], x, 1, (1/2)*E^ArcSin[x]*(x + Sqrt[1 - x^2])}
{E^ArcSin[x]/x, x, 1, Subst[Int[E^x*Cot[x], x], x, ArcSin[x]]}


{E^ArcSin[x]/Sqrt[1 - x^2], x, 2, E^ArcSin[x]}


(* ::Subsection::Closed:: *)
(*Problems from Calculus textbooks*)


(* ::Subsubsection:: *)
(*Edwards and Penney Calculus*)


{ArcSin[x]^2/Sqrt[1 - x^2], x, 2, ArcSin[x]^3/3}
{E^x*ArcSin[E^x], x, 2, Sqrt[1 - E^(2*x)] + E^x*ArcSin[E^x]}


(* ::Subsubsection:: *)
(*Thomas Calculus, 8th Edition*)


{2*x*ArcSin[x^2], x, 3, Sqrt[1 - x^4] + x^2*ArcSin[x^2]}
{ArcSin[x]/Sqrt[1 - x^2], x, 2, ArcSin[x]^2/2}


(* ::Subsection::Closed:: *)
(*Miscellaneous integrands involving inverse sines*)


{ArcSin[a + b*x]/((a*d)/b + d*x), x, 8, -((I*ArcSin[a + b*x]^2)/(2*d)) + (ArcSin[a + b*x]*Log[1 - E^(2*I*ArcSin[a + b*x])])/d - (I*PolyLog[2, E^(2*I*ArcSin[a + b*x])])/(2*d)}


{x/(Sqrt[1 - x^2]*Sqrt[ArcSin[x]]), x, 2, Sqrt[2*Pi]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcSin[x]]]}
{x/(Sqrt[1 - x^2]*ArcSin[x]), x, 2, SinIntegral[ArcSin[x]]}


(* Integrands of the form x^(n-1)*ArcTrig[a+b*x^n] *)
{x^3*ArcSin[a + b*x^4], x, 2, Sqrt[1 - (a + b*x^4)^2]/(4*b) + ((a + b*x^4)*ArcSin[a + b*x^4])/(4*b)}
{x^(n-1)*ArcSin[a + b*x^n], x, 2, Sqrt[1 - (a + b*x^n)^2]/(b*n) + ((a + b*x^n)*ArcSin[a + b*x^n])/(b*n)}


{Sqrt[1 - x^2]*ArcSin[x], x, 3, (1/4)*(1 - x^2) + (1/2)*x*Sqrt[1 - x^2]*ArcSin[x] + ArcSin[x]^2/4}


{ArcSin[c/(a + b*x)], x, 4, ((a + b*x)*ArcCsc[a/c + (b*x)/c])/b + (c*ArcTanh[Sqrt[1 - c^2/(a + b*x)^2]])/b}
