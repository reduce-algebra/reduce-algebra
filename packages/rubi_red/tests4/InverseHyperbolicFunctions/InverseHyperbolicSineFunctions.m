(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Inverse Hyperbolic Sines*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcSinh[a x]^n*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{x^m*ArcSinh[a*x], x, 2, (x^(1 + m)*ArcSinh[a*x])/(1 + m) - (a*x^(2 + m)*Hypergeometric2F1[1/2, (2 + m)/2, (4 + m)/2, -(a^2*x^2)])/(2 + 3*m + m^2)}

{x^4*ArcSinh[a*x], x, 4, -((8*Sqrt[1 + a^2*x^2])/(75*a^5)) + (4*x^2*Sqrt[1 + a^2*x^2])/(75*a^3) - (x^4*Sqrt[1 + a^2*x^2])/(25*a) + (1/5)*x^5*ArcSinh[a*x]}
{x^3*ArcSinh[a*x], x, 4, (3*x*Sqrt[1 + a^2*x^2])/(32*a^3) - (x^3*Sqrt[1 + a^2*x^2])/(16*a) - (3*ArcSinh[a*x])/(32*a^4) + (1/4)*x^4*ArcSinh[a*x]}
{x^2*ArcSinh[a*x], x, 3, (2*Sqrt[1 + a^2*x^2])/(9*a^3) - (x^2*Sqrt[1 + a^2*x^2])/(9*a) + (1/3)*x^3*ArcSinh[a*x]}
{x^1*ArcSinh[a*x], x, 3, -((x*Sqrt[1 + a^2*x^2])/(4*a)) + ArcSinh[a*x]/(4*a^2) + (1/2)*x^2*ArcSinh[a*x]}
{x^0*ArcSinh[a*x], x, 1, -(Sqrt[1 + a^2*x^2]/a) + x*ArcSinh[a*x]}
{ArcSinh[a*x]/x^1, x, 5, (-(1/2))*ArcSinh[a*x]^2 + ArcSinh[a*x]*Log[1 - E^(2*ArcSinh[a*x])] + (1/2)*PolyLog[2, E^(2*ArcSinh[a*x])]}
{ArcSinh[a*x]/x^2, x, 3, -(ArcSinh[a*x]/x) - a*ArcTanh[Sqrt[1 + a^2*x^2]]}
{ArcSinh[a*x]/x^3, x, 2, -((a*Sqrt[1 + a^2*x^2])/(2*x)) - ArcSinh[a*x]/(2*x^2)}
{ArcSinh[a*x]/x^4, x, 4, -((a*Sqrt[1 + a^2*x^2])/(6*x^2)) - ArcSinh[a*x]/(3*x^3) + (1/6)*a^3*ArcTanh[Sqrt[1 + a^2*x^2]]}
{ArcSinh[a*x]/x^5, x, 3, -((a*Sqrt[1 + a^2*x^2])/(12*x^3)) + (a^3*Sqrt[1 + a^2*x^2])/(6*x) - ArcSinh[a*x]/(4*x^4)}
{ArcSinh[a*x]/x^6, x, 5, -((a*Sqrt[1 + a^2*x^2])/(20*x^4)) + (3*a^3*Sqrt[1 + a^2*x^2])/(40*x^2) - ArcSinh[a*x]/(5*x^5) - (3/40)*a^5*ArcTanh[Sqrt[1 + a^2*x^2]]}


{x^m*ArcSinh[a*x]^2, x, 2, (x^(1 + m)*ArcSinh[a*x]^2)/(1 + m) - (2*a*x^(2 + m)*ArcSinh[a*x]*Hypergeometric2F1[1/2, (2 + m)/2, (4 + m)/2, (-a^2)*x^2])/(2 + 3*m + m^2) + (2*a^2*x^(3 + m)*HypergeometricPFQ[{1, 3/2 + m/2, 3/2 + m/2}, {2 + m/2, 5/2 + m/2}, (-a^2)*x^2])/(6 + 11*m + 6*m^2 + m^3)}

{x^4*ArcSinh[a*x]^2, x, 7, (16*x)/(75*a^4) - (8*x^3)/(225*a^2) + (2*x^5)/125 - (16*Sqrt[1 + a^2*x^2]*ArcSinh[a*x])/(75*a^5) + (8*x^2*Sqrt[1 + a^2*x^2]*ArcSinh[a*x])/(75*a^3) - (2*x^4*Sqrt[1 + a^2*x^2]*ArcSinh[a*x])/(25*a) + (x^5*ArcSinh[a*x]^2)/5}
{x^3*ArcSinh[a*x]^2, x, 6, (-3*x^2)/(32*a^2) + x^4/32 + (3*x*Sqrt[1 + a^2*x^2]*ArcSinh[a*x])/(16*a^3) - (x^3*Sqrt[1 + a^2*x^2]*ArcSinh[a*x])/(8*a) - (3*ArcSinh[a*x]^2)/(32*a^4) + (x^4*ArcSinh[a*x]^2)/4}
{x^2*ArcSinh[a*x]^2, x, 5, (-4*x)/(9*a^2) + (2*x^3)/27 + (4*Sqrt[1 + a^2*x^2]*ArcSinh[a*x])/(9*a^3) - (2*x^2*Sqrt[1 + a^2*x^2]*ArcSinh[a*x])/(9*a) + (x^3*ArcSinh[a*x]^2)/3}
{x*ArcSinh[a*x]^2, x, 4, x^2/4 - (x*Sqrt[1 + a^2*x^2]*ArcSinh[a*x])/(2*a) + ArcSinh[a*x]^2/(4*a^2) + (x^2*ArcSinh[a*x]^2)/2}
{ArcSinh[a*x]^2, x, 2, 2*x - (2*Sqrt[1 + a^2*x^2]*ArcSinh[a*x])/a + x*ArcSinh[a*x]^2}
{ArcSinh[a*x]^2/x, x, 6, -ArcSinh[a*x]^3/3 + ArcSinh[a*x]^2*Log[1 - E^(2*ArcSinh[a*x])] + ArcSinh[a*x]*PolyLog[2, E^(2*ArcSinh[a*x])] - PolyLog[3, E^(2*ArcSinh[a*x])]/2}
{ArcSinh[a*x]^2/x^2, x, 2, -(ArcSinh[a*x]^2/x) + 4*a*ArcSinh[a*x]*ArcTanh[a*x - Sqrt[1 + a^2*x^2]] + 2*a*PolyLog[2, a*x - Sqrt[1 + a^2*x^2]] - 2*a*PolyLog[2, -(a*x) + Sqrt[1 + a^2*x^2]]}
{ArcSinh[a*x]^2/x^3, x, 3, -((a*Sqrt[1 + a^2*x^2]*ArcSinh[a*x])/x) - ArcSinh[a*x]^2/(2*x^2) + a^2*Log[x]}
{ArcSinh[a*x]^2/x^4, x, 4, -a^2/(3*x) - (a*Sqrt[1 + a^2*x^2]*ArcSinh[a*x])/(3*x^2) - ArcSinh[a*x]^2/(3*x^3) - (2*a^3*ArcSinh[a*x]*ArcTanh[a*x - Sqrt[1 + a^2*x^2]])/3 - (a^3*PolyLog[2, a*x - Sqrt[1 + a^2*x^2]])/3 + (a^3*PolyLog[2, -(a*x) + Sqrt[1 + a^2*x^2]])/3}
{ArcSinh[a*x]^2/x^5, x, 5, -a^2/(12*x^2) - (a*Sqrt[1 + a^2*x^2]*ArcSinh[a*x])/(6*x^3) + (a^3*Sqrt[1 + a^2*x^2]*ArcSinh[a*x])/(3*x) - ArcSinh[a*x]^2/(4*x^4) - (a^4*Log[x])/3}


{x^m*ArcSinh[a*x]^3, x, 1, (x^(1 + m)*ArcSinh[a*x]^3)/(1 + m) - (3*a*Defer[Int][(x^(1 + m)*ArcSinh[a*x]^2)/Sqrt[1 + a^2*x^2], x])/(1 + m)}

{x^4*ArcSinh[a*x]^3, x, 12, -((4144*Sqrt[1 + a^2*x^2])/(5625*a^5)) + (272*x^2*Sqrt[1 + a^2*x^2])/(5625*a^3) - (6*x^4*Sqrt[1 + a^2*x^2])/(625*a) + (16*x*ArcSinh[a*x])/(25*a^4) - (8*x^3*ArcSinh[a*x])/(75*a^2) + (6/125)*x^5*ArcSinh[a*x] - (8*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^2)/(25*a^5) + (4*x^2*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^2)/(25*a^3) - (3*x^4*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^2)/(25*a) + (1/5)*x^5*ArcSinh[a*x]^3}
{x^3*ArcSinh[a*x]^3, x, 11, (45*x*Sqrt[1 + a^2*x^2])/(256*a^3) - (3*x^3*Sqrt[1 + a^2*x^2])/(128*a) - (45*ArcSinh[a*x])/(256*a^4) - (9*x^2*ArcSinh[a*x])/(32*a^2) + (3*x^4*ArcSinh[a*x])/32 + (9*x*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^2)/(32*a^3) - (3*x^3*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^2)/(16*a) - (3*ArcSinh[a*x]^3)/(32*a^4) + (x^4*ArcSinh[a*x]^3)/4}
{x^2*ArcSinh[a*x]^3, x, 7, (40*Sqrt[1 + a^2*x^2])/(27*a^3) - (2*x^2*Sqrt[1 + a^2*x^2])/(27*a) - (4*x*ArcSinh[a*x])/(3*a^2) + (2/9)*x^3*ArcSinh[a*x] + (2*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^2)/(3*a^3) - (x^2*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^2)/(3*a) + (1/3)*x^3*ArcSinh[a*x]^3}
{x*ArcSinh[a*x]^3, x, 6, (-3*x*Sqrt[1 + a^2*x^2])/(8*a) + (3*ArcSinh[a*x])/(8*a^2) + (3*x^2*ArcSinh[a*x])/4 - (3*x*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^2)/(4*a) + ArcSinh[a*x]^3/(4*a^2) + (x^2*ArcSinh[a*x]^3)/2}
{ArcSinh[a*x]^3, x, 2, (-6*Sqrt[1 + a^2*x^2])/a + 6*x*ArcSinh[a*x] - (3*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^2)/a + x*ArcSinh[a*x]^3}
{ArcSinh[a*x]^3/x, x, 7, -ArcSinh[a*x]^4/4 + ArcSinh[a*x]^3*Log[1 - E^(2*ArcSinh[a*x])] + (3*ArcSinh[a*x]^2*PolyLog[2, E^(2*ArcSinh[a*x])])/2 - (3*ArcSinh[a*x]*PolyLog[3, E^(2*ArcSinh[a*x])])/2 + (3*PolyLog[4, E^(2*ArcSinh[a*x])])/4}
{ArcSinh[a*x]^3/x^2, x, 7, -(ArcSinh[a*x]^3/x) - 6*a*ArcSinh[a*x]^2*ArcTanh[E^ArcSinh[a*x]] - 6*a*ArcSinh[a*x]*PolyLog[2, -E^ArcSinh[a*x]] + 6*a*ArcSinh[a*x]*PolyLog[2, E^ArcSinh[a*x]] + 6*a*PolyLog[3, -E^ArcSinh[a*x]] - 6*a*PolyLog[3, E^ArcSinh[a*x]]}
{ArcSinh[a*x]^3/x^3, x, 7, (-3*a^2*ArcSinh[a*x]^2)/2 - (3*a*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^2)/(2*x) - ArcSinh[a*x]^3/(2*x^2) + 3*a^2*ArcSinh[a*x]*Log[1 - E^(2*ArcSinh[a*x])] + (3*a^2*PolyLog[2, E^(2*ArcSinh[a*x])])/2}
{ArcSinh[a*x]^3/x^4, x, 11, -((a^2*ArcSinh[a*x])/x) - (a*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^2)/(2*x^2) - ArcSinh[a*x]^3/(3*x^3) + a^3*ArcSinh[a*x]^2*ArcTanh[E^ArcSinh[a*x]] - a^3*ArcTanh[Sqrt[1 + a^2*x^2]] + a^3*ArcSinh[a*x]*PolyLog[2, -E^ArcSinh[a*x]] - a^3*ArcSinh[a*x]*PolyLog[2, E^ArcSinh[a*x]] - a^3*PolyLog[3, -E^ArcSinh[a*x]] + a^3*PolyLog[3, E^ArcSinh[a*x]]}
{ArcSinh[a*x]^3/x^5, x, 10, -(a^3*Sqrt[1 + a^2*x^2])/(4*x) - (a^2*ArcSinh[a*x])/(4*x^2) + (a^4*ArcSinh[a*x]^2)/2 - (a*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^2)/(4*x^3) + (a^3*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^2)/(2*x) - ArcSinh[a*x]^3/(4*x^4) - a^4*ArcSinh[a*x]*Log[1 - E^(2*ArcSinh[a*x])] - (a^4*PolyLog[2, E^(2*ArcSinh[a*x])])/2}


{x^m*ArcSinh[a*x]^4, x, 1, (x^(1 + m)*ArcSinh[a*x]^4)/(1 + m) - (4*a*Defer[Int][(x^(1 + m)*ArcSinh[a*x]^3)/Sqrt[1 + a^2*x^2], x])/(1 + m)}

{x^5*ArcSinh[a*x]^4, x, 23, (245*x^2)/(1152*a^4) - (65*x^4)/(3456*a^2) + x^6/324 - (245*x*Sqrt[1 + a^2*x^2]*ArcSinh[a*x])/(576*a^5) + (65*x^3*Sqrt[1 + a^2*x^2]*ArcSinh[a*x])/(864*a^3) - (x^5*Sqrt[1 + a^2*x^2]*ArcSinh[a*x])/(54*a) + (245*ArcSinh[a*x]^2)/(1152*a^6) + (5*x^2*ArcSinh[a*x]^2)/(16*a^4) - (5*x^4*ArcSinh[a*x]^2)/(48*a^2) + (x^6*ArcSinh[a*x]^2)/18 - (5*x*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^3)/(24*a^5) + (5*x^3*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^3)/(36*a^3) - (x^5*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^3)/(9*a) + (5*ArcSinh[a*x]^4)/(96*a^6) + (x^6*ArcSinh[a*x]^4)/6}
{x^4*ArcSinh[a*x]^4, x, 18, (16576*x)/(5625*a^4) - (1088*x^3)/(16875*a^2) + (24*x^5)/3125 - (16576*Sqrt[1 + a^2*x^2]*ArcSinh[a*x])/(5625*a^5) + (1088*x^2*Sqrt[1 + a^2*x^2]*ArcSinh[a*x])/(5625*a^3) - (24*x^4*Sqrt[1 + a^2*x^2]*ArcSinh[a*x])/(625*a) + (32*x*ArcSinh[a*x]^2)/(25*a^4) - (16*x^3*ArcSinh[a*x]^2)/(75*a^2) + (12*x^5*ArcSinh[a*x]^2)/125 - (32*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^3)/(75*a^5) + (16*x^2*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^3)/(75*a^3) - (4*x^4*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^3)/(25*a) + (x^5*ArcSinh[a*x]^4)/5}
{x^3*ArcSinh[a*x]^4, x, 14, (-45*x^2)/(128*a^2) + (3*x^4)/128 + (45*x*Sqrt[1 + a^2*x^2]*ArcSinh[a*x])/(64*a^3) - (3*x^3*Sqrt[1 + a^2*x^2]*ArcSinh[a*x])/(32*a) - (45*ArcSinh[a*x]^2)/(128*a^4) - (9*x^2*ArcSinh[a*x]^2)/(16*a^2) + (3*x^4*ArcSinh[a*x]^2)/16 + (3*x*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^3)/(8*a^3) - (x^3*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^3)/(4*a) - (3*ArcSinh[a*x]^4)/(32*a^4) + (x^4*ArcSinh[a*x]^4)/4}
{x^2*ArcSinh[a*x]^4, x, 10, (-160*x)/(27*a^2) + (8*x^3)/81 + (160*Sqrt[1 + a^2*x^2]*ArcSinh[a*x])/(27*a^3) - (8*x^2*Sqrt[1 + a^2*x^2]*ArcSinh[a*x])/(27*a) - (8*x*ArcSinh[a*x]^2)/(3*a^2) + (4*x^3*ArcSinh[a*x]^2)/9 + (8*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^3)/(9*a^3) - (4*x^2*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^3)/(9*a) + (x^3*ArcSinh[a*x]^4)/3}
{x*ArcSinh[a*x]^4, x, 7, (3*x^2)/4 - (3*x*Sqrt[1 + a^2*x^2]*ArcSinh[a*x])/(2*a) + (3*ArcSinh[a*x]^2)/(4*a^2) + (3*x^2*ArcSinh[a*x]^2)/2 - (x*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^3)/a + ArcSinh[a*x]^4/(4*a^2) + (x^2*ArcSinh[a*x]^4)/2}
{ArcSinh[a*x]^4, x, 3, 24*x - (24*Sqrt[1 + a^2*x^2]*ArcSinh[a*x])/a + 12*x*ArcSinh[a*x]^2 - (4*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^3)/a + x*ArcSinh[a*x]^4}
{ArcSinh[a*x]^4/x, x, 8, -ArcSinh[a*x]^5/5 + ArcSinh[a*x]^4*Log[1 - E^(2*ArcSinh[a*x])] + 2*ArcSinh[a*x]^3*PolyLog[2, E^(2*ArcSinh[a*x])] - 3*ArcSinh[a*x]^2*PolyLog[3, E^(2*ArcSinh[a*x])] + 3*ArcSinh[a*x]*PolyLog[4, E^(2*ArcSinh[a*x])] - (3*PolyLog[5, E^(2*ArcSinh[a*x])])/2}
{ArcSinh[a*x]^4/x^2, x, 9, -(ArcSinh[a*x]^4/x) - 8*a*ArcSinh[a*x]^3*ArcTanh[E^ArcSinh[a*x]] - 12*a*ArcSinh[a*x]^2*PolyLog[2, -E^ArcSinh[a*x]] + 12*a*ArcSinh[a*x]^2*PolyLog[2, E^ArcSinh[a*x]] + 24*a*ArcSinh[a*x]*PolyLog[3, -E^ArcSinh[a*x]] - 24*a*ArcSinh[a*x]*PolyLog[3, E^ArcSinh[a*x]] - 24*a*PolyLog[4, -E^ArcSinh[a*x]] + 24*a*PolyLog[4, E^ArcSinh[a*x]]}
{ArcSinh[a*x]^4/x^3, x, 8, -2*a^2*ArcSinh[a*x]^3 - (2*a*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^3)/x - ArcSinh[a*x]^4/(2*x^2) + 6*a^2*ArcSinh[a*x]^2*Log[1 - E^(2*ArcSinh[a*x])] + 6*a^2*ArcSinh[a*x]*PolyLog[2, E^(2*ArcSinh[a*x])] - 3*a^2*PolyLog[3, E^(2*ArcSinh[a*x])]}
{ArcSinh[a*x]^4/x^4, x, 12, (-2*a^2*ArcSinh[a*x]^2)/x - (2*a*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^3)/(3*x^2) - ArcSinh[a*x]^4/(3*x^3) + (4*a^3*ArcSinh[a*x]^3*ArcTanh[E^ArcSinh[a*x]])/3 + 8*a^3*ArcSinh[a*x]*ArcTanh[a*x - Sqrt[1 + a^2*x^2]] + 2*a^3*ArcSinh[a*x]^2*PolyLog[2, -E^ArcSinh[a*x]] - 2*a^3*ArcSinh[a*x]^2*PolyLog[2, E^ArcSinh[a*x]] + 4*a^3*PolyLog[2, a*x - Sqrt[1 + a^2*x^2]] - 4*a^3*PolyLog[2, -(a*x) + Sqrt[1 + a^2*x^2]] - 4*a^3*ArcSinh[a*x]*PolyLog[3, -E^ArcSinh[a*x]] + 4*a^3*ArcSinh[a*x]*PolyLog[3, E^ArcSinh[a*x]] + 4*a^3*PolyLog[4, -E^ArcSinh[a*x]] - 4*a^3*PolyLog[4, E^ArcSinh[a*x]]}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{x^m/ArcSinh[a*x], x, 0, Int[x^m/ArcSinh[a*x], x]}

{x^4/ArcSinh[a*x], x, 6, CoshIntegral[ArcSinh[a*x]]/(8*a^5) - (3*CoshIntegral[3*ArcSinh[a*x]])/(16*a^5) + CoshIntegral[5*ArcSinh[a*x]]/(16*a^5)}
{x^3/ArcSinh[a*x], x, 5, -SinhIntegral[2*ArcSinh[a*x]]/(4*a^4) + SinhIntegral[4*ArcSinh[a*x]]/(8*a^4)}
{x^2/ArcSinh[a*x], x, 5, -CoshIntegral[ArcSinh[a*x]]/(4*a^3) + CoshIntegral[3*ArcSinh[a*x]]/(4*a^3)}
{x/ArcSinh[a*x], x, 4, SinhIntegral[2*ArcSinh[a*x]]/(2*a^2)}
{ArcSinh[a*x]^(-1), x, 2, CoshIntegral[ArcSinh[a*x]]/a}
{1/(x*ArcSinh[a*x]), x, 0, Int[1/(x*ArcSinh[a*x]), x]}
{1/(x^2*ArcSinh[a*x]), x, 0, Int[1/(x^2*ArcSinh[a*x]), x]}


{x^m/ArcSinh[a*x]^2, x, 0, Int[x^m/ArcSinh[a*x]^2, x]}

{x^4/ArcSinh[a*x]^2, x, 5, -((x^4*Sqrt[1 + a^2*x^2])/(a*ArcSinh[a*x])) + SinhIntegral[ArcSinh[a*x]]/(8*a^5) - (9*SinhIntegral[3*ArcSinh[a*x]])/(16*a^5) + (5*SinhIntegral[5*ArcSinh[a*x]])/(16*a^5)}
{x^3/ArcSinh[a*x]^2, x, 4, -((x^3*Sqrt[1 + a^2*x^2])/(a*ArcSinh[a*x])) - CoshIntegral[2*ArcSinh[a*x]]/(2*a^4) + CoshIntegral[4*ArcSinh[a*x]]/(2*a^4)}
{x^2/ArcSinh[a*x]^2, x, 4, -((x^2*Sqrt[1 + a^2*x^2])/(a*ArcSinh[a*x])) - SinhIntegral[ArcSinh[a*x]]/(4*a^3) + (3*SinhIntegral[3*ArcSinh[a*x]])/(4*a^3)}
{x/ArcSinh[a*x]^2, x, 2, -((x*Sqrt[1 + a^2*x^2])/(a*ArcSinh[a*x])) + CoshIntegral[2*ArcSinh[a*x]]/a^2}
{ArcSinh[a*x]^(-2), x, 4, -(Sqrt[1 + a^2*x^2]/(a*ArcSinh[a*x])) + SinhIntegral[ArcSinh[a*x]]/a}
{1/(x*ArcSinh[a*x]^2), x, 0, Int[1/(x*ArcSinh[a*x]^2), x]}
{1/(x^2*ArcSinh[a*x]^2), x, 0, Int[1/(x^2*ArcSinh[a*x]^2), x]}


{x^m/ArcSinh[a*x]^3, x, 0, Int[x^m/ArcSinh[a*x]^3, x]}

{x^4/ArcSinh[a*x]^3, x, 12, -(x^4*Sqrt[1 + a^2*x^2])/(2*a*ArcSinh[a*x]^2) - (2*x^3)/(a^2*ArcSinh[a*x]) - (5*x^5)/(2*ArcSinh[a*x]) + CoshIntegral[ArcSinh[a*x]]/(16*a^5) - (27*CoshIntegral[3*ArcSinh[a*x]])/(32*a^5) + (25*CoshIntegral[5*ArcSinh[a*x]])/(32*a^5)}
{x^3/ArcSinh[a*x]^3, x, 10, -(x^3*Sqrt[1 + a^2*x^2])/(2*a*ArcSinh[a*x]^2) - (3*x^2)/(2*a^2*ArcSinh[a*x]) - (2*x^4)/ArcSinh[a*x] - SinhIntegral[2*ArcSinh[a*x]]/(2*a^4) + SinhIntegral[4*ArcSinh[a*x]]/a^4}
{x^2/ArcSinh[a*x]^3, x, 8, -(x^2*Sqrt[1 + a^2*x^2])/(2*a*ArcSinh[a*x]^2) - x/(a^2*ArcSinh[a*x]) - (3*x^3)/(2*ArcSinh[a*x]) - CoshIntegral[ArcSinh[a*x]]/(8*a^3) + (9*CoshIntegral[3*ArcSinh[a*x]])/(8*a^3)}
{x/ArcSinh[a*x]^3, x, 6, -(x*Sqrt[1 + a^2*x^2])/(2*a*ArcSinh[a*x]^2) - 1/(2*a^2*ArcSinh[a*x]) - x^2/ArcSinh[a*x] + SinhIntegral[2*ArcSinh[a*x]]/a^2}
{ArcSinh[a*x]^(-3), x, 3, -Sqrt[1 + a^2*x^2]/(2*a*ArcSinh[a*x]^2) - x/(2*ArcSinh[a*x]) + CoshIntegral[ArcSinh[a*x]]/(2*a)}
{1/(x*ArcSinh[a*x]^3), x, 0, Int[1/(x*ArcSinh[a*x]^3), x]}
{1/(x^2*ArcSinh[a*x]^3), x, 0, Int[1/(x^2*ArcSinh[a*x]^3), x]}


{x^m/ArcSinh[a*x]^4, x, 0, Int[x^m/ArcSinh[a*x]^4, x]}

{x^4/ArcSinh[a*x]^4, x, 10, -(x^4*Sqrt[1 + a^2*x^2])/(3*a*ArcSinh[a*x]^3) - (2*x^3)/(3*a^2*ArcSinh[a*x]^2) - (5*x^5)/(6*ArcSinh[a*x]^2) - (2*x^2*Sqrt[1 + a^2*x^2])/(a^3*ArcSinh[a*x]) - (25*x^4*Sqrt[1 + a^2*x^2])/(6*a*ArcSinh[a*x]) + SinhIntegral[ArcSinh[a*x]]/(48*a^5) - (27*SinhIntegral[3*ArcSinh[a*x]])/(32*a^5) + (125*SinhIntegral[5*ArcSinh[a*x]])/(96*a^5)}
{x^3/ArcSinh[a*x]^4, x, 7, -(x^3*Sqrt[1 + a^2*x^2])/(3*a*ArcSinh[a*x]^3) - x^2/(2*a^2*ArcSinh[a*x]^2) - (2*x^4)/(3*ArcSinh[a*x]^2) - (x*Sqrt[1 + a^2*x^2])/(a^3*ArcSinh[a*x]) - (8*x^3*Sqrt[1 + a^2*x^2])/(3*a*ArcSinh[a*x]) - CoshIntegral[2*ArcSinh[a*x]]/(3*a^4) + (4*CoshIntegral[4*ArcSinh[a*x]])/(3*a^4)}
{x^2/ArcSinh[a*x]^4, x, 9, -(x^2*Sqrt[1 + a^2*x^2])/(3*a*ArcSinh[a*x]^3) - x/(3*a^2*ArcSinh[a*x]^2) - x^3/(2*ArcSinh[a*x]^2) - Sqrt[1 + a^2*x^2]/(3*a^3*ArcSinh[a*x]) - (3*x^2*Sqrt[1 + a^2*x^2])/(2*a*ArcSinh[a*x]) - SinhIntegral[ArcSinh[a*x]]/(24*a^3) + (9*SinhIntegral[3*ArcSinh[a*x]])/(8*a^3)}
{x/ArcSinh[a*x]^4, x, 4, -(x*Sqrt[1 + a^2*x^2])/(3*a*ArcSinh[a*x]^3) - 1/(6*a^2*ArcSinh[a*x]^2) - x^2/(3*ArcSinh[a*x]^2) - (2*x*Sqrt[1 + a^2*x^2])/(3*a*ArcSinh[a*x]) + (2*CoshIntegral[2*ArcSinh[a*x]])/(3*a^2)}
{ArcSinh[a*x]^(-4), x, 5, -Sqrt[1 + a^2*x^2]/(3*a*ArcSinh[a*x]^3) - x/(6*ArcSinh[a*x]^2) - Sqrt[1 + a^2*x^2]/(6*a*ArcSinh[a*x]) + SinhIntegral[ArcSinh[a*x]]/(6*a)}
{1/(x*ArcSinh[a*x]^4), x, 0, Int[1/(x*ArcSinh[a*x]^4), x]}
{1/(x^2*ArcSinh[a*x]^4), x, 0, Int[1/(x^2*ArcSinh[a*x]^4), x]}


(* ::Subsubsection::Closed:: *)
(*n/2>0*)


{x^m*Sqrt[ArcSinh[a*x]], x, 1, (x^(1 + m)*Sqrt[ArcSinh[a*x]])/(1 + m) - (a*Defer[Int][x^(1 + m)/(Sqrt[1 + a^2*x^2]*Sqrt[ArcSinh[a*x]]), x])/(2*(1 + m))}

{x^4*Sqrt[ArcSinh[a*x]], x, 13, (x^5*Sqrt[ArcSinh[a*x]])/5 + (Sqrt[Pi]*Erf[Sqrt[ArcSinh[a*x]]])/(32*a^5) - (Sqrt[Pi/3]*Erf[Sqrt[3]*Sqrt[ArcSinh[a*x]]])/(64*a^5) + (Sqrt[Pi/5]*Erf[Sqrt[5]*Sqrt[ArcSinh[a*x]]])/(320*a^5) - (Sqrt[Pi]*Erfi[Sqrt[ArcSinh[a*x]]])/(32*a^5) + (Sqrt[Pi/3]*Erfi[Sqrt[3]*Sqrt[ArcSinh[a*x]]])/(64*a^5) - (Sqrt[Pi/5]*Erfi[Sqrt[5]*Sqrt[ArcSinh[a*x]]])/(320*a^5)}
{x^3*Sqrt[ArcSinh[a*x]], x, 10, (-3*Sqrt[ArcSinh[a*x]])/(32*a^4) + (x^4*Sqrt[ArcSinh[a*x]])/4 - (Sqrt[Pi]*Erf[2*Sqrt[ArcSinh[a*x]]])/(256*a^4) + (Sqrt[Pi/2]*Erf[Sqrt[2]*Sqrt[ArcSinh[a*x]]])/(32*a^4) - (Sqrt[Pi]*Erfi[2*Sqrt[ArcSinh[a*x]]])/(256*a^4) + (Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[ArcSinh[a*x]]])/(32*a^4)}
{x^2*Sqrt[ArcSinh[a*x]], x, 10, (x^3*Sqrt[ArcSinh[a*x]])/3 - (Sqrt[Pi]*Erf[Sqrt[ArcSinh[a*x]]])/(16*a^3) + (Sqrt[Pi/3]*Erf[Sqrt[3]*Sqrt[ArcSinh[a*x]]])/(48*a^3) + (Sqrt[Pi]*Erfi[Sqrt[ArcSinh[a*x]]])/(16*a^3) - (Sqrt[Pi/3]*Erfi[Sqrt[3]*Sqrt[ArcSinh[a*x]]])/(48*a^3)}
{x*Sqrt[ArcSinh[a*x]], x, 7, Sqrt[ArcSinh[a*x]]/(4*a^2) + (x^2*Sqrt[ArcSinh[a*x]])/2 - (Sqrt[Pi/2]*Erf[Sqrt[2]*Sqrt[ArcSinh[a*x]]])/(16*a^2) - (Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[ArcSinh[a*x]]])/(16*a^2)}
{Sqrt[ArcSinh[a*x]], x, 6, x*Sqrt[ArcSinh[a*x]] + (Sqrt[Pi]*Erf[Sqrt[ArcSinh[a*x]]])/(4*a) - (Sqrt[Pi]*Erfi[Sqrt[ArcSinh[a*x]]])/(4*a)}
{Sqrt[ArcSinh[a*x]]/x, x, 0, Int[Sqrt[ArcSinh[a*x]]/x, x]}


{x^m*ArcSinh[a*x]^(3/2), x, 1, (x^(1 + m)*ArcSinh[a*x]^(3/2))/(1 + m) - (3*a*Defer[Int][(x^(1 + m)*Sqrt[ArcSinh[a*x]])/Sqrt[1 + a^2*x^2], x])/(2*(1 + m))}

{x^4*ArcSinh[a*x]^(3/2), x, 31, -((4*Sqrt[1 + a^2*x^2]*Sqrt[ArcSinh[a*x]])/(25*a^5)) + (2*x^2*Sqrt[1 + a^2*x^2]*Sqrt[ArcSinh[a*x]])/(25*a^3) - (3*x^4*Sqrt[1 + a^2*x^2]*Sqrt[ArcSinh[a*x]])/(50*a) + (1/5)*x^5*ArcSinh[a*x]^(3/2) + (3*Sqrt[Pi]*Erf[Sqrt[ArcSinh[a*x]]])/(64*a^5) - (Sqrt[Pi/3]*Erf[Sqrt[3]*Sqrt[ArcSinh[a*x]]])/(200*a^5) - (3*Sqrt[3*Pi]*Erf[Sqrt[3]*Sqrt[ArcSinh[a*x]]])/(3200*a^5) + (3*Sqrt[Pi/5]*Erf[Sqrt[5]*Sqrt[ArcSinh[a*x]]])/(3200*a^5) + (3*Sqrt[Pi]*Erfi[Sqrt[ArcSinh[a*x]]])/(64*a^5) - (Sqrt[Pi/3]*Erfi[Sqrt[3]*Sqrt[ArcSinh[a*x]]])/(200*a^5) - (3*Sqrt[3*Pi]*Erfi[Sqrt[3]*Sqrt[ArcSinh[a*x]]])/(3200*a^5) + (3*Sqrt[Pi/5]*Erfi[Sqrt[5]*Sqrt[ArcSinh[a*x]]])/(3200*a^5)}
{x^3*ArcSinh[a*x]^(3/2), x, 18, (9*x*Sqrt[1 + a^2*x^2]*Sqrt[ArcSinh[a*x]])/(64*a^3) - (3*x^3*Sqrt[1 + a^2*x^2]*Sqrt[ArcSinh[a*x]])/(32*a) - (3*ArcSinh[a*x]^(3/2))/(32*a^4) + (1/4)*x^4*ArcSinh[a*x]^(3/2) - (3*Sqrt[Pi]*Erf[2*Sqrt[ArcSinh[a*x]]])/(2048*a^4) + (3*Sqrt[Pi/2]*Erf[Sqrt[2]*Sqrt[ArcSinh[a*x]]])/(128*a^4) + (3*Sqrt[Pi]*Erfi[2*Sqrt[ArcSinh[a*x]]])/(2048*a^4) - (3*Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[ArcSinh[a*x]]])/(128*a^4)}
{x^2*ArcSinh[a*x]^(3/2), x, 18, (Sqrt[1 + a^2*x^2]*Sqrt[ArcSinh[a*x]])/(3*a^3) - (x^2*Sqrt[1 + a^2*x^2]*Sqrt[ArcSinh[a*x]])/(6*a) + (1/3)*x^3*ArcSinh[a*x]^(3/2) - (3*Sqrt[Pi]*Erf[Sqrt[ArcSinh[a*x]]])/(32*a^3) + (Sqrt[Pi/3]*Erf[Sqrt[3]*Sqrt[ArcSinh[a*x]]])/(96*a^3) - (3*Sqrt[Pi]*Erfi[Sqrt[ArcSinh[a*x]]])/(32*a^3) + (Sqrt[Pi/3]*Erfi[Sqrt[3]*Sqrt[ArcSinh[a*x]]])/(96*a^3)}
{x^1*ArcSinh[a*x]^(3/2), x, 8, -((3*x*Sqrt[1 + a^2*x^2]*Sqrt[ArcSinh[a*x]])/(8*a)) + ArcSinh[a*x]^(3/2)/(4*a^2) + (1/2)*x^2*ArcSinh[a*x]^(3/2) - (3*Sqrt[Pi/2]*Erf[Sqrt[2]*Sqrt[ArcSinh[a*x]]])/(64*a^2) + (3*Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[ArcSinh[a*x]]])/(64*a^2)}
{ArcSinh[a*x]^(3/2), x, 7, (-3*Sqrt[1 + a^2*x^2]*Sqrt[ArcSinh[a*x]])/(2*a) + x*ArcSinh[a*x]^(3/2) + (3*Sqrt[Pi]*Erf[Sqrt[ArcSinh[a*x]]])/(8*a) + (3*Sqrt[Pi]*Erfi[Sqrt[ArcSinh[a*x]]])/(8*a)}
{ArcSinh[a*x]^(3/2)/x, x, 0, Int[ArcSinh[a*x]^(3/2)/x, x]}


{x^m*ArcSinh[a*x]^(5/2), x, 1, (x^(1 + m)*ArcSinh[a*x]^(5/2))/(1 + m) - (5*a*Defer[Int][(x^(1 + m)*ArcSinh[a*x]^(3/2))/Sqrt[1 + a^2*x^2], x])/(2*(1 + m))}

{x^4*ArcSinh[a*x]^(5/2), x, 33, (2*x*Sqrt[ArcSinh[a*x]])/(5*a^4) - (x^3*Sqrt[ArcSinh[a*x]])/(15*a^2) + (3/100)*x^5*Sqrt[ArcSinh[a*x]] - (4*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^(3/2))/(15*a^5) + (2*x^2*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^(3/2))/(15*a^3) - (x^4*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^(3/2))/(10*a) + (1/5)*x^5*ArcSinh[a*x]^(5/2) + (15*Sqrt[Pi]*Erf[Sqrt[ArcSinh[a*x]]])/(128*a^5) - (Sqrt[Pi/3]*Erf[Sqrt[3]*Sqrt[ArcSinh[a*x]]])/(240*a^5) - (Sqrt[3*Pi]*Erf[Sqrt[3]*Sqrt[ArcSinh[a*x]]])/(1280*a^5) + (3*Sqrt[Pi/5]*Erf[Sqrt[5]*Sqrt[ArcSinh[a*x]]])/(6400*a^5) - (15*Sqrt[Pi]*Erfi[Sqrt[ArcSinh[a*x]]])/(128*a^5) + (Sqrt[Pi/3]*Erfi[Sqrt[3]*Sqrt[ArcSinh[a*x]]])/(240*a^5) + (Sqrt[3*Pi]*Erfi[Sqrt[3]*Sqrt[ArcSinh[a*x]]])/(1280*a^5) - (3*Sqrt[Pi/5]*Erfi[Sqrt[5]*Sqrt[ArcSinh[a*x]]])/(6400*a^5)}
{x^3*ArcSinh[a*x]^(5/2), x, 21, (-225*Sqrt[ArcSinh[a*x]])/(2048*a^4) - (45*x^2*Sqrt[ArcSinh[a*x]])/(256*a^2) + (15*x^4*Sqrt[ArcSinh[a*x]])/256 + (15*x*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^(3/2))/(64*a^3) - (5*x^3*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^(3/2))/(32*a) - (3*ArcSinh[a*x]^(5/2))/(32*a^4) + (x^4*ArcSinh[a*x]^(5/2))/4 - (15*Sqrt[Pi]*Erf[2*Sqrt[ArcSinh[a*x]]])/(16384*a^4) + (15*Sqrt[Pi/2]*Erf[Sqrt[2]*Sqrt[ArcSinh[a*x]]])/(512*a^4) - (15*Sqrt[Pi]*Erfi[2*Sqrt[ArcSinh[a*x]]])/(16384*a^4) + (15*Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[ArcSinh[a*x]]])/(512*a^4)}
{x^2*ArcSinh[a*x]^(5/2), x, 19, (-5*x*Sqrt[ArcSinh[a*x]])/(6*a^2) + (5*x^3*Sqrt[ArcSinh[a*x]])/36 + (5*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^(3/2))/(9*a^3) - (5*x^2*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^(3/2))/(18*a) + (x^3*ArcSinh[a*x]^(5/2))/3 - (15*Sqrt[Pi]*Erf[Sqrt[ArcSinh[a*x]]])/(64*a^3) + (5*Sqrt[Pi/3]*Erf[Sqrt[3]*Sqrt[ArcSinh[a*x]]])/(576*a^3) + (15*Sqrt[Pi]*Erfi[Sqrt[ArcSinh[a*x]]])/(64*a^3) - (5*Sqrt[Pi/3]*Erfi[Sqrt[3]*Sqrt[ArcSinh[a*x]]])/(576*a^3)}
{x*ArcSinh[a*x]^(5/2), x, 10, (15*Sqrt[ArcSinh[a*x]])/(64*a^2) + (15*x^2*Sqrt[ArcSinh[a*x]])/32 - (5*x*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^(3/2))/(8*a) + ArcSinh[a*x]^(5/2)/(4*a^2) + (x^2*ArcSinh[a*x]^(5/2))/2 - (15*Sqrt[Pi/2]*Erf[Sqrt[2]*Sqrt[ArcSinh[a*x]]])/(256*a^2) - (15*Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[ArcSinh[a*x]]])/(256*a^2)}
{ArcSinh[a*x]^(5/2), x, 7, (15*x*Sqrt[ArcSinh[a*x]])/4 - (5*Sqrt[1 + a^2*x^2]*ArcSinh[a*x]^(3/2))/(2*a) + x*ArcSinh[a*x]^(5/2) + (15*Sqrt[Pi]*Erf[Sqrt[ArcSinh[a*x]]])/(16*a) - (15*Sqrt[Pi]*Erfi[Sqrt[ArcSinh[a*x]]])/(16*a)}
{ArcSinh[a*x]^(5/2)/x, x, 0, Int[ArcSinh[a*x]^(5/2)/x, x]}


(* ::Subsubsection::Closed:: *)
(*n/2<0*)


{x^m/Sqrt[ArcSinh[a*x]], x, 0, Int[x^m/Sqrt[ArcSinh[a*x]], x]}

{x^4/Sqrt[ArcSinh[a*x]], x, 12, (Sqrt[Pi]*Erf[Sqrt[ArcSinh[a*x]]])/(16*a^5) - (Sqrt[3*Pi]*Erf[Sqrt[3]*Sqrt[ArcSinh[a*x]]])/(32*a^5) + (Sqrt[Pi/5]*Erf[Sqrt[5]*Sqrt[ArcSinh[a*x]]])/(32*a^5) + (Sqrt[Pi]*Erfi[Sqrt[ArcSinh[a*x]]])/(16*a^5) - (Sqrt[3*Pi]*Erfi[Sqrt[3]*Sqrt[ArcSinh[a*x]]])/(32*a^5) + (Sqrt[Pi/5]*Erfi[Sqrt[5]*Sqrt[ArcSinh[a*x]]])/(32*a^5)}
{x^3/Sqrt[ArcSinh[a*x]], x, 9, -(Sqrt[Pi]*Erf[2*Sqrt[ArcSinh[a*x]]])/(32*a^4) + (Sqrt[Pi/2]*Erf[Sqrt[2]*Sqrt[ArcSinh[a*x]]])/(8*a^4) + (Sqrt[Pi]*Erfi[2*Sqrt[ArcSinh[a*x]]])/(32*a^4) - (Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[ArcSinh[a*x]]])/(8*a^4)}
{x^2/Sqrt[ArcSinh[a*x]], x, 9, -(Sqrt[Pi]*Erf[Sqrt[ArcSinh[a*x]]])/(8*a^3) + (Sqrt[Pi/3]*Erf[Sqrt[3]*Sqrt[ArcSinh[a*x]]])/(8*a^3) - (Sqrt[Pi]*Erfi[Sqrt[ArcSinh[a*x]]])/(8*a^3) + (Sqrt[Pi/3]*Erfi[Sqrt[3]*Sqrt[ArcSinh[a*x]]])/(8*a^3)}
{x/Sqrt[ArcSinh[a*x]], x, 5, -(Sqrt[Pi/2]*Erf[Sqrt[2]*Sqrt[ArcSinh[a*x]]])/(4*a^2) + (Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[ArcSinh[a*x]]])/(4*a^2)}
{1/Sqrt[ArcSinh[a*x]], x, 6, (Sqrt[Pi]*Erf[Sqrt[ArcSinh[a*x]]])/(2*a) + (Sqrt[Pi]*Erfi[Sqrt[ArcSinh[a*x]]])/(2*a)}
{1/(x*Sqrt[ArcSinh[a*x]]), x, 0, Int[1/(x*Sqrt[ArcSinh[a*x]]), x]}
{1/(x^2*Sqrt[ArcSinh[a*x]]), x, 0, Int[1/(x^2*Sqrt[ArcSinh[a*x]]), x]}


{x^m/ArcSinh[a*x]^(3/2), x, 0, Int[x^m/ArcSinh[a*x]^(3/2), x]}

{x^4/ArcSinh[a*x]^(3/2), x, 12, -((2*x^4*Sqrt[1 + a^2*x^2])/(a*Sqrt[ArcSinh[a*x]])) - (Sqrt[Pi]*Erf[Sqrt[ArcSinh[a*x]]])/(8*a^5) + (3*Sqrt[3*Pi]*Erf[Sqrt[3]*Sqrt[ArcSinh[a*x]]])/(16*a^5) - (Sqrt[5*Pi]*Erf[Sqrt[5]*Sqrt[ArcSinh[a*x]]])/(16*a^5) + (Sqrt[Pi]*Erfi[Sqrt[ArcSinh[a*x]]])/(8*a^5) - (3*Sqrt[3*Pi]*Erfi[Sqrt[3]*Sqrt[ArcSinh[a*x]]])/(16*a^5) + (Sqrt[5*Pi]*Erfi[Sqrt[5]*Sqrt[ArcSinh[a*x]]])/(16*a^5)}
{x^3/ArcSinh[a*x]^(3/2), x, 9, -((2*x^3*Sqrt[1 + a^2*x^2])/(a*Sqrt[ArcSinh[a*x]])) + (Sqrt[Pi]*Erf[2*Sqrt[ArcSinh[a*x]]])/(4*a^4) - (Sqrt[Pi/2]*Erf[Sqrt[2]*Sqrt[ArcSinh[a*x]]])/(2*a^4) + (Sqrt[Pi]*Erfi[2*Sqrt[ArcSinh[a*x]]])/(4*a^4) - (Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[ArcSinh[a*x]]])/(2*a^4)}
{x^2/ArcSinh[a*x]^(3/2), x, 9, -((2*x^2*Sqrt[1 + a^2*x^2])/(a*Sqrt[ArcSinh[a*x]])) + (Sqrt[Pi]*Erf[Sqrt[ArcSinh[a*x]]])/(4*a^3) - (Sqrt[3*Pi]*Erf[Sqrt[3]*Sqrt[ArcSinh[a*x]]])/(4*a^3) - (Sqrt[Pi]*Erfi[Sqrt[ArcSinh[a*x]]])/(4*a^3) + (Sqrt[3*Pi]*Erfi[Sqrt[3]*Sqrt[ArcSinh[a*x]]])/(4*a^3)}
{x/ArcSinh[a*x]^(3/2), x, 4, (-2*x*Sqrt[1 + a^2*x^2])/(a*Sqrt[ArcSinh[a*x]]) + (Sqrt[Pi/2]*Erf[Sqrt[2]*Sqrt[ArcSinh[a*x]]])/a^2 + (Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[ArcSinh[a*x]]])/a^2}
{ArcSinh[a*x]^(-3/2), x, 6, (-2*Sqrt[1 + a^2*x^2])/(a*Sqrt[ArcSinh[a*x]]) - (Sqrt[Pi]*Erf[Sqrt[ArcSinh[a*x]]])/a + (Sqrt[Pi]*Erfi[Sqrt[ArcSinh[a*x]]])/a}
{1/(x*ArcSinh[a*x]^(3/2)), x, 0, Int[1/(x*ArcSinh[a*x]^(3/2)), x]}


{x^m/ArcSinh[a*x]^(5/2), x, 0, Int[x^m/ArcSinh[a*x]^(5/2), x]}

{x^4/ArcSinh[a*x]^(5/2), x, 22, -((2*x^4*Sqrt[1 + a^2*x^2])/(3*a*ArcSinh[a*x]^(3/2))) - (16*x^3)/(3*a^2*Sqrt[ArcSinh[a*x]]) - (20*x^5)/(3*Sqrt[ArcSinh[a*x]]) + (Sqrt[Pi]*Erf[Sqrt[ArcSinh[a*x]]])/(12*a^5) - (3*Sqrt[3*Pi]*Erf[Sqrt[3]*Sqrt[ArcSinh[a*x]]])/(8*a^5) + (5*Sqrt[5*Pi]*Erf[Sqrt[5]*Sqrt[ArcSinh[a*x]]])/(24*a^5) + (Sqrt[Pi]*Erfi[Sqrt[ArcSinh[a*x]]])/(12*a^5) - (3*Sqrt[3*Pi]*Erfi[Sqrt[3]*Sqrt[ArcSinh[a*x]]])/(8*a^5) + (5*Sqrt[5*Pi]*Erfi[Sqrt[5]*Sqrt[ArcSinh[a*x]]])/(24*a^5)}
{x^3/ArcSinh[a*x]^(5/2), x, 15, (-2*x^3*Sqrt[1 + a^2*x^2])/(3*a*ArcSinh[a*x]^(3/2)) - (4*x^2)/(a^2*Sqrt[ArcSinh[a*x]]) - (16*x^4)/(3*Sqrt[ArcSinh[a*x]]) - (2*Sqrt[Pi]*Erf[2*Sqrt[ArcSinh[a*x]]])/(3*a^4) + (Sqrt[2*Pi]*Erf[Sqrt[2]*Sqrt[ArcSinh[a*x]]])/(3*a^4) + (2*Sqrt[Pi]*Erfi[2*Sqrt[ArcSinh[a*x]]])/(3*a^4) - (Sqrt[2*Pi]*Erfi[Sqrt[2]*Sqrt[ArcSinh[a*x]]])/(3*a^4)}
{x^2/ArcSinh[a*x]^(5/2), x, 16, (-2*x^2*Sqrt[1 + a^2*x^2])/(3*a*ArcSinh[a*x]^(3/2)) - (8*x)/(3*a^2*Sqrt[ArcSinh[a*x]]) - (4*x^3)/Sqrt[ArcSinh[a*x]] - (Sqrt[Pi]*Erf[Sqrt[ArcSinh[a*x]]])/(6*a^3) + (Sqrt[3*Pi]*Erf[Sqrt[3]*Sqrt[ArcSinh[a*x]]])/(2*a^3) - (Sqrt[Pi]*Erfi[Sqrt[ArcSinh[a*x]]])/(6*a^3) + (Sqrt[3*Pi]*Erfi[Sqrt[3]*Sqrt[ArcSinh[a*x]]])/(2*a^3)}
{x/ArcSinh[a*x]^(5/2), x, 7, (-2*x*Sqrt[1 + a^2*x^2])/(3*a*ArcSinh[a*x]^(3/2)) - 4/(3*a^2*Sqrt[ArcSinh[a*x]]) - (8*x^2)/(3*Sqrt[ArcSinh[a*x]]) - (2*Sqrt[2*Pi]*Erf[Sqrt[2]*Sqrt[ArcSinh[a*x]]])/(3*a^2) + (2*Sqrt[2*Pi]*Erfi[Sqrt[2]*Sqrt[ArcSinh[a*x]]])/(3*a^2)}
{1/ArcSinh[a*x]^(5/2), x, 7, (-2*Sqrt[1 + a^2*x^2])/(3*a*ArcSinh[a*x]^(3/2)) - (4*x)/(3*Sqrt[ArcSinh[a*x]]) + (2*Sqrt[Pi]*Erf[Sqrt[ArcSinh[a*x]]])/(3*a) + (2*Sqrt[Pi]*Erfi[Sqrt[ArcSinh[a*x]]])/(3*a)}
{1/(x*ArcSinh[a*x]^(5/2)), x, 0, Int[1/(x*ArcSinh[a*x]^(5/2)), x]}


{x^m/ArcSinh[a*x]^(7/2), x, 0, Int[x^m/ArcSinh[a*x]^(7/2), x]}

{x^4/ArcSinh[a*x]^(7/2), x, 22, -((2*x^4*Sqrt[1 + a^2*x^2])/(5*a*ArcSinh[a*x]^(5/2))) - (16*x^3)/(15*a^2*ArcSinh[a*x]^(3/2)) - (4*x^5)/(3*ArcSinh[a*x]^(3/2)) - (32*x^2*Sqrt[1 + a^2*x^2])/(5*a^3*Sqrt[ArcSinh[a*x]]) - (40*x^4*Sqrt[1 + a^2*x^2])/(3*a*Sqrt[ArcSinh[a*x]]) - (Sqrt[Pi]*Erf[Sqrt[ArcSinh[a*x]]])/(30*a^5) + (9*Sqrt[3*Pi]*Erf[Sqrt[3]*Sqrt[ArcSinh[a*x]]])/(20*a^5) - (5*Sqrt[5*Pi]*Erf[Sqrt[5]*Sqrt[ArcSinh[a*x]]])/(12*a^5) + (Sqrt[Pi]*Erfi[Sqrt[ArcSinh[a*x]]])/(30*a^5) - (9*Sqrt[3*Pi]*Erfi[Sqrt[3]*Sqrt[ArcSinh[a*x]]])/(20*a^5) + (5*Sqrt[5*Pi]*Erfi[Sqrt[5]*Sqrt[ArcSinh[a*x]]])/(12*a^5)}
{x^3/ArcSinh[a*x]^(7/2), x, 14, (-2*x^3*Sqrt[1 + a^2*x^2])/(5*a*ArcSinh[a*x]^(5/2)) - (4*x^2)/(5*a^2*ArcSinh[a*x]^(3/2)) - (16*x^4)/(15*ArcSinh[a*x]^(3/2)) - (16*x*Sqrt[1 + a^2*x^2])/(5*a^3*Sqrt[ArcSinh[a*x]]) - (128*x^3*Sqrt[1 + a^2*x^2])/(15*a*Sqrt[ArcSinh[a*x]]) + (16*Sqrt[Pi]*Erf[2*Sqrt[ArcSinh[a*x]]])/(15*a^4) - (4*Sqrt[2*Pi]*Erf[Sqrt[2]*Sqrt[ArcSinh[a*x]]])/(15*a^4) + (16*Sqrt[Pi]*Erfi[2*Sqrt[ArcSinh[a*x]]])/(15*a^4) - (4*Sqrt[2*Pi]*Erfi[Sqrt[2]*Sqrt[ArcSinh[a*x]]])/(15*a^4)}
{x^2/ArcSinh[a*x]^(7/2), x, 16, (-2*x^2*Sqrt[1 + a^2*x^2])/(5*a*ArcSinh[a*x]^(5/2)) - (8*x)/(15*a^2*ArcSinh[a*x]^(3/2)) - (4*x^3)/(5*ArcSinh[a*x]^(3/2)) - (16*Sqrt[1 + a^2*x^2])/(15*a^3*Sqrt[ArcSinh[a*x]]) - (24*x^2*Sqrt[1 + a^2*x^2])/(5*a*Sqrt[ArcSinh[a*x]]) + (Sqrt[Pi]*Erf[Sqrt[ArcSinh[a*x]]])/(15*a^3) - (3*Sqrt[3*Pi]*Erf[Sqrt[3]*Sqrt[ArcSinh[a*x]]])/(5*a^3) - (Sqrt[Pi]*Erfi[Sqrt[ArcSinh[a*x]]])/(15*a^3) + (3*Sqrt[3*Pi]*Erfi[Sqrt[3]*Sqrt[ArcSinh[a*x]]])/(5*a^3)}
{x/ArcSinh[a*x]^(7/2), x, 6, (-2*x*Sqrt[1 + a^2*x^2])/(5*a*ArcSinh[a*x]^(5/2)) - 4/(15*a^2*ArcSinh[a*x]^(3/2)) - (8*x^2)/(15*ArcSinh[a*x]^(3/2)) - (32*x*Sqrt[1 + a^2*x^2])/(15*a*Sqrt[ArcSinh[a*x]]) + (8*Sqrt[2*Pi]*Erf[Sqrt[2]*Sqrt[ArcSinh[a*x]]])/(15*a^2) + (8*Sqrt[2*Pi]*Erfi[Sqrt[2]*Sqrt[ArcSinh[a*x]]])/(15*a^2)}
{ArcSinh[a*x]^(-7/2), x, 7, (-2*Sqrt[1 + a^2*x^2])/(5*a*ArcSinh[a*x]^(5/2)) - (4*x)/(15*ArcSinh[a*x]^(3/2)) - (8*Sqrt[1 + a^2*x^2])/(15*a*Sqrt[ArcSinh[a*x]]) - (4*Sqrt[Pi]*Erf[Sqrt[ArcSinh[a*x]]])/(15*a) + (4*Sqrt[Pi]*Erfi[Sqrt[ArcSinh[a*x]]])/(15*a)}
{1/(x*ArcSinh[a*x]^(7/2)), x, 0, Int[1/(x*ArcSinh[a*x]^(7/2)), x]}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{x^m*ArcSinh[a*x]^n, x, 0, Int[x^m*ArcSinh[a*x]^n, x]}

{x^4*ArcSinh[a*x]^n, x, 13, (x^5*ArcSinh[a*x]^n)/5 + (5^(-1 - n)*n*ArcSinh[a*x]^n*Gamma[n, -5*ArcSinh[a*x]])/(32*a^5*(-ArcSinh[a*x])^n) - (n*ArcSinh[a*x]^n*Gamma[n, -3*ArcSinh[a*x]])/(32*3^n*a^5*(-ArcSinh[a*x])^n) + (n*ArcSinh[a*x]^n*Gamma[n, -ArcSinh[a*x]])/(16*a^5*(-ArcSinh[a*x])^n) - (n*Gamma[n, ArcSinh[a*x]])/(16*a^5) + (n*Gamma[n, 3*ArcSinh[a*x]])/(32*3^n*a^5) - (5^(-1 - n)*n*Gamma[n, 5*ArcSinh[a*x]])/(32*a^5)}
{x^3*ArcSinh[a*x]^n, x, 10, (-3*ArcSinh[a*x]^n)/(32*a^4) + (x^4*ArcSinh[a*x]^n)/4 + (n*ArcSinh[a*x]^n*Gamma[n, -4*ArcSinh[a*x]])/(2^(2*(3 + n))*a^4*(-ArcSinh[a*x])^n) - (2^(-4 - n)*n*ArcSinh[a*x]^n*Gamma[n, -2*ArcSinh[a*x]])/(a^4*(-ArcSinh[a*x])^n) - (2^(-4 - n)*n*Gamma[n, 2*ArcSinh[a*x]])/a^4 + (n*Gamma[n, 4*ArcSinh[a*x]])/(2^(2*(3 + n))*a^4)}
{x^2*ArcSinh[a*x]^n, x, 10, (x^3*ArcSinh[a*x]^n)/3 + (3^(-1 - n)*n*ArcSinh[a*x]^n*Gamma[n, -3*ArcSinh[a*x]])/(8*a^3*(-ArcSinh[a*x])^n) - (n*ArcSinh[a*x]^n*Gamma[n, -ArcSinh[a*x]])/(8*a^3*(-ArcSinh[a*x])^n) + (n*Gamma[n, ArcSinh[a*x]])/(8*a^3) - (3^(-1 - n)*n*Gamma[n, 3*ArcSinh[a*x]])/(8*a^3)}
{x*ArcSinh[a*x]^n, x, 7, ArcSinh[a*x]^n/(4*a^2) + (x^2*ArcSinh[a*x]^n)/2 + (2^(-3 - n)*n*ArcSinh[a*x]^n*Gamma[n, -2*ArcSinh[a*x]])/(a^2*(-ArcSinh[a*x])^n) + (2^(-3 - n)*n*Gamma[n, 2*ArcSinh[a*x]])/a^2}
{ArcSinh[a*x]^n, x, 4, (ArcSinh[a*x]^n*Gamma[1 + n, -ArcSinh[a*x]])/(2*a*(-ArcSinh[a*x])^n) - Gamma[1 + n, ArcSinh[a*x]]/(2*a)}
{ArcSinh[a*x]^n/x, x, 0, Int[ArcSinh[a*x]^n/x, x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcSinh[a+b x]^n*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{x^3*ArcSinh[a + b*x], x, 7, -((a*(41 - 64*a^2)*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(96*b^4)) + (7*a*x^2*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(48*b^2) - (x^3*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(16*b) - ((14*a*(1 + a^2) - (9 - 26*a^2)*b*x)*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(96*b^4) - ((3 - 24*a^2 + 8*a^4)*ArcSinh[a + b*x])/(32*b^4) + (1/4)*x^4*ArcSinh[a + b*x]}
{x^2*ArcSinh[a + b*x], x, 6, ((2 - 13*a^2)*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(18*b^3) - (x^2*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(9*b) + ((2*(1 + a^2) + 5*a*b*x)*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(18*b^3) - (a*(3 - 2*a^2)*ArcSinh[a + b*x])/(6*b^3) + (1/3)*x^3*ArcSinh[a + b*x]}
{x^1*ArcSinh[a + b*x], x, 5, (3*a*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(4*b^2) - (x*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(4*b) + ((1 - 2*a^2)*ArcSinh[a + b*x])/(4*b^2) + (1/2)*x^2*ArcSinh[a + b*x]}
{x^0*ArcSinh[a + b*x], x, 1, -(Sqrt[1 + (a + b*x)^2]/b) + ((a + b*x)*ArcSinh[a + b*x])/b}
{ArcSinh[a + b*x]/x^1, x, -3, (1/8)*(Pi^2 - 4*I*Pi*ArcSinh[a + b*x] - 4*ArcSinh[a + b*x]^2 + 32*ArcSin[Sqrt[1 - I*a]/Sqrt[2]]*ArcTan[((-I + a)*Cot[(1/4)*(Pi + 2*I*ArcSinh[a + b*x])])/Sqrt[1 + a^2]] - 4*I*Pi*Log[b*x] + 4*I*Pi*Log[1 + a^2 - a*Sqrt[1 + a^2] + a*b*x - Sqrt[1 + a^2]*b*x + a*Sqrt[1 + (a + b*x)^2] - Sqrt[1 + a^2]*Sqrt[1 + (a + b*x)^2]] - 16*I*ArcSin[Sqrt[1 - I*a]/Sqrt[2]]*Log[1 + a^2 - a*Sqrt[1 + a^2] + a*b*x - Sqrt[1 + a^2]*b*x + a*Sqrt[1 + (a + b*x)^2] - Sqrt[1 + a^2]*Sqrt[1 + (a + b*x)^2]] + 8*ArcSinh[a + b*x]*Log[1 + a^2 - a*Sqrt[1 + a^2] + a*b*x - Sqrt[1 + a^2]*b*x + a*Sqrt[1 + (a + b*x)^2] - Sqrt[1 + a^2]*Sqrt[1 + (a + b*x)^2]] + 4*I*Pi*Log[1 + a^2 + a*Sqrt[1 + a^2] + a*b*x + Sqrt[1 + a^2]*b*x + a*Sqrt[1 + (a + b*x)^2] + Sqrt[1 + a^2]*Sqrt[1 + (a + b*x)^2]] + 16*I*ArcSin[Sqrt[1 - I*a]/Sqrt[2]]*Log[1 + a^2 + a*Sqrt[1 + a^2] + a*b*x + Sqrt[1 + a^2]*b*x + a*Sqrt[1 + (a + b*x)^2] + Sqrt[1 + a^2]*Sqrt[1 + (a + b*x)^2]] + 8*ArcSinh[a + b*x]*Log[1 + a^2 + a*Sqrt[1 + a^2] + a*b*x + Sqrt[1 + a^2]*b*x + a*Sqrt[1 + (a + b*x)^2] + Sqrt[1 + a^2]*Sqrt[1 + (a + b*x)^2]] + 8*PolyLog[2, (-a + Sqrt[1 + a^2])*(a + b*x + Sqrt[1 + (a + b*x)^2])] + 8*PolyLog[2, (-(a + Sqrt[1 + a^2]))*(a + b*x + Sqrt[1 + (a + b*x)^2])])}
{ArcSinh[a + b*x]/x^2, x, 3, -(ArcSinh[a + b*x]/x) - (b*ArcTanh[(1 + a^2 + a*b*x)/(Sqrt[1 + a^2]*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])])/Sqrt[1 + a^2]}
{ArcSinh[a + b*x]/x^3, x, 4, -((b*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(2*(1 + a^2)*x)) - ArcSinh[a + b*x]/(2*x^2) + (a*b^2*ArcTanh[(1 + a^2 + a*b*x)/(Sqrt[1 + a^2]*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])])/(2*(1 + a^2)^(3/2))}
{ArcSinh[a + b*x]/x^4, x, 6, -((b*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(6*(1 + a^2)*x^2)) + (a*b^2*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(2*(1 + a^2)^2*x) - ArcSinh[a + b*x]/(3*x^3) + ((1 - 2*a^2)*b^3*ArcTanh[(1 + a^2 + a*b*x)/(Sqrt[1 + a^2]*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])])/(6*(1 + a^2)^(5/2))}
{ArcSinh[a + b*x]/x^5, x, 7, -((b*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(12*(1 + a^2)*x^3)) + (5*a*b^2*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(24*(1 + a^2)^2*x^2) + ((4 - 11*a^2)*b^3*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(24*(1 + a^2)^3*x) - ArcSinh[a + b*x]/(4*x^4) - (a*(3 - 2*a^2)*b^4*ArcTanh[(1 + a^2 + a*b*x)/(Sqrt[1 + a^2]*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])])/(8*(1 + a^2)^(7/2))}


{x^3*ArcSinh[a + b*x]^2, x, 19, (55*a*x)/(48*b^3) - (a^3*x)/(2*b^3) - (3*x^2)/(32*b^2) + (3*a^2*x^2)/(4*b^2) - (2*a*(a + b*x)^3)/(9*b^4) + (a + b*x)^4/(32*b^4) - (4*a*Sqrt[1 + (a + b*x)^2]*ArcSinh[a + b*x])/(3*b^4) + (2*a^3*Sqrt[1 + (a + b*x)^2]*ArcSinh[a + b*x])/b^4 + (3*(a + b*x)*Sqrt[1 + (a + b*x)^2]*ArcSinh[a + b*x])/(16*b^4) - (3*a^2*(a + b*x)*Sqrt[1 + (a + b*x)^2]*ArcSinh[a + b*x])/(2*b^4) + (2*a*(a + b*x)^2*Sqrt[1 + (a + b*x)^2]*ArcSinh[a + b*x])/(3*b^4) - ((a + b*x)^3*Sqrt[1 + (a + b*x)^2]*ArcSinh[a + b*x])/(8*b^4) - (3*ArcSinh[a + b*x]^2)/(32*b^4) + (3*a^2*ArcSinh[a + b*x]^2)/(4*b^4) - (a^3*(a + b*x)*ArcSinh[a + b*x]^2)/b^4 + (3*a^2*(a + b*x)^2*ArcSinh[a + b*x]^2)/(2*b^4) - (a*(a + b*x)^3*ArcSinh[a + b*x]^2)/b^4 + ((a + b*x)^4*ArcSinh[a + b*x]^2)/(4*b^4)}
{x^2*ArcSinh[a + b*x]^2, x, 13, -((4*x)/(9*b^2)) + (a^2*x)/b^2 - (a*x^2)/(2*b) + (2*(a + b*x)^3)/(27*b^3) + (4*Sqrt[1 + (a + b*x)^2]*ArcSinh[a + b*x])/(9*b^3) - (2*a^2*Sqrt[1 + (a + b*x)^2]*ArcSinh[a + b*x])/b^3 + (a*(a + b*x)*Sqrt[1 + (a + b*x)^2]*ArcSinh[a + b*x])/b^3 - (2*(a + b*x)^2*Sqrt[1 + (a + b*x)^2]*ArcSinh[a + b*x])/(9*b^3) - (a*ArcSinh[a + b*x]^2)/(2*b^3) + (a^2*(a + b*x)*ArcSinh[a + b*x]^2)/b^3 - (a*(a + b*x)^2*ArcSinh[a + b*x]^2)/b^3 + ((a + b*x)^3*ArcSinh[a + b*x]^2)/(3*b^3)}
{x^1*ArcSinh[a + b*x]^2, x, 8, -((3*a*x)/(2*b)) + x^2/4 + (2*a*Sqrt[1 + (a + b*x)^2]*ArcSinh[a + b*x])/b^2 - ((a + b*x)*Sqrt[1 + (a + b*x)^2]*ArcSinh[a + b*x])/(2*b^2) + ArcSinh[a + b*x]^2/(4*b^2) - (a*(a + b*x)*ArcSinh[a + b*x]^2)/b^2 + ((a + b*x)^2*ArcSinh[a + b*x]^2)/(2*b^2)}
{x^0*ArcSinh[a + b*x]^2, x, 2, 2*x - (2*Sqrt[1 + (a + b*x)^2]*ArcSinh[a + b*x])/b + ((a + b*x)*ArcSinh[a + b*x]^2)/b}
{ArcSinh[a + b*x]^2/x^1, x, 0, Int[ArcSinh[a + b*x]^2/x, x]}
{ArcSinh[a + b*x]^2/x^2, x, 10, -(ArcSinh[a + b*x]^2/x) - (2*b*ArcSinh[a + b*x]*Log[1 - E^ArcSinh[a + b*x]/(a - Sqrt[1 + a^2])])/Sqrt[1 + a^2] + (2*b*ArcSinh[a + b*x]*Log[1 - E^ArcSinh[a + b*x]/(a + Sqrt[1 + a^2])])/Sqrt[1 + a^2] - (2*b*PolyLog[2, E^ArcSinh[a + b*x]/(a - Sqrt[1 + a^2])])/Sqrt[1 + a^2] + (2*b*PolyLog[2, E^ArcSinh[a + b*x]/(a + Sqrt[1 + a^2])])/Sqrt[1 + a^2]}
{ArcSinh[a + b*x]^2/x^3, x, 14, -((b*Sqrt[1 + (a + b*x)^2]*ArcSinh[a + b*x])/((1 + a^2)*x)) - ArcSinh[a + b*x]^2/(2*x^2) + (a*b^2*ArcSinh[a + b*x]*Log[1 - E^ArcSinh[a + b*x]/(a - Sqrt[1 + a^2])])/(1 + a^2)^(3/2) - (a*b^2*ArcSinh[a + b*x]*Log[1 - E^ArcSinh[a + b*x]/(a + Sqrt[1 + a^2])])/(1 + a^2)^(3/2) + (b^2*Log[x])/(1 + a^2) + (a*b^2*PolyLog[2, E^ArcSinh[a + b*x]/(a - Sqrt[1 + a^2])])/(1 + a^2)^(3/2) - (a*b^2*PolyLog[2, E^ArcSinh[a + b*x]/(a + Sqrt[1 + a^2])])/(1 + a^2)^(3/2)}
(* {ArcSinh[a + b*x]^2/x^4, x, 0, 0} *)


{x^2*ArcSinh[a + b*x]^3, x, 19, (40*Sqrt[1 + (a + b*x)^2])/(27*b^3) - (6*a^2*Sqrt[1 + (a + b*x)^2])/b^3 + (3*a*(a + b*x)*Sqrt[1 + (a + b*x)^2])/(4*b^3) - (2*(a + b*x)^2*Sqrt[1 + (a + b*x)^2])/(27*b^3) - (3*a*ArcSinh[a + b*x])/(4*b^3) - (4*(a + b*x)*ArcSinh[a + b*x])/(3*b^3) + (6*a^2*(a + b*x)*ArcSinh[a + b*x])/b^3 - (3*a*(a + b*x)^2*ArcSinh[a + b*x])/(2*b^3) + (2*(a + b*x)^3*ArcSinh[a + b*x])/(9*b^3) + (2*Sqrt[1 + (a + b*x)^2]*ArcSinh[a + b*x]^2)/(3*b^3) - (3*a^2*Sqrt[1 + (a + b*x)^2]*ArcSinh[a + b*x]^2)/b^3 + (3*a*(a + b*x)*Sqrt[1 + (a + b*x)^2]*ArcSinh[a + b*x]^2)/(2*b^3) - ((a + b*x)^2*Sqrt[1 + (a + b*x)^2]*ArcSinh[a + b*x]^2)/(3*b^3) - (a*ArcSinh[a + b*x]^3)/(2*b^3) + (a^2*(a + b*x)*ArcSinh[a + b*x]^3)/b^3 - (a*(a + b*x)^2*ArcSinh[a + b*x]^3)/b^3 + ((a + b*x)^3*ArcSinh[a + b*x]^3)/(3*b^3)}
{x^1*ArcSinh[a + b*x]^3, x, 11, (6*a*Sqrt[1 + (a + b*x)^2])/b^2 - (3*(a + b*x)*Sqrt[1 + (a + b*x)^2])/(8*b^2) + (3*ArcSinh[a + b*x])/(8*b^2) - (6*a*(a + b*x)*ArcSinh[a + b*x])/b^2 + (3*(a + b*x)^2*ArcSinh[a + b*x])/(4*b^2) + (3*a*Sqrt[1 + (a + b*x)^2]*ArcSinh[a + b*x]^2)/b^2 - (3*(a + b*x)*Sqrt[1 + (a + b*x)^2]*ArcSinh[a + b*x]^2)/(4*b^2) + ArcSinh[a + b*x]^3/(4*b^2) - (a*(a + b*x)*ArcSinh[a + b*x]^3)/b^2 + ((a + b*x)^2*ArcSinh[a + b*x]^3)/(2*b^2)}
{x^0*ArcSinh[a + b*x]^3, x, 2, (-6*Sqrt[1 + (a + b*x)^2])/b + (6*(a + b*x)*ArcSinh[a + b*x])/b - (3*Sqrt[1 + (a + b*x)^2]*ArcSinh[a + b*x]^2)/b + ((a + b*x)*ArcSinh[a + b*x]^3)/b}
{ArcSinh[a + b*x]^3/x^1, x, 0, Int[ArcSinh[a + b*x]^3/x, x]}
{ArcSinh[a + b*x]^3/x^2, x, 12, -(ArcSinh[a + b*x]^3/x) - (3*b*ArcSinh[a + b*x]^2*Log[1 - E^ArcSinh[a + b*x]/(a - Sqrt[1 + a^2])])/Sqrt[1 + a^2] + (3*b*ArcSinh[a + b*x]^2*Log[1 - E^ArcSinh[a + b*x]/(a + Sqrt[1 + a^2])])/Sqrt[1 + a^2] - (6*b*ArcSinh[a + b*x]*PolyLog[2, E^ArcSinh[a + b*x]/(a - Sqrt[1 + a^2])])/Sqrt[1 + a^2] + (6*b*ArcSinh[a + b*x]*PolyLog[2, E^ArcSinh[a + b*x]/(a + Sqrt[1 + a^2])])/Sqrt[1 + a^2] + (6*b*PolyLog[3, E^ArcSinh[a + b*x]/(a - Sqrt[1 + a^2])])/Sqrt[1 + a^2] - (6*b*PolyLog[3, E^ArcSinh[a + b*x]/(a + Sqrt[1 + a^2])])/Sqrt[1 + a^2]}
(* {ArcSinh[a + b*x]^3/x^3, x, 0, 0} *)


{Sqrt[ArcSinh[a + b*x]], x, 6, ((a + b*x)*Sqrt[ArcSinh[a + b*x]])/b + (Sqrt[Pi]*Erf[Sqrt[ArcSinh[a + b*x]]])/(4*b) - (Sqrt[Pi]*Erfi[Sqrt[ArcSinh[a + b*x]]])/(4*b)}
{ArcSinh[a + b*x]^(3/2), x, 7, (-3*Sqrt[1 + (a + b*x)^2]*Sqrt[ArcSinh[a + b*x]])/(2*b) + ((a + b*x)*ArcSinh[a + b*x]^(3/2))/b + (3*Sqrt[Pi]*Erf[Sqrt[ArcSinh[a + b*x]]])/(8*b) + (3*Sqrt[Pi]*Erfi[Sqrt[ArcSinh[a + b*x]]])/(8*b)}
{ArcSinh[a + b*x]^(5/2), x, 7, (15*(a + b*x)*Sqrt[ArcSinh[a + b*x]])/(4*b) - (5*Sqrt[1 + (a + b*x)^2]*ArcSinh[a + b*x]^(3/2))/(2*b) + ((a + b*x)*ArcSinh[a + b*x]^(5/2))/b + (15*Sqrt[Pi]*Erf[Sqrt[ArcSinh[a + b*x]]])/(16*b) - (15*Sqrt[Pi]*Erfi[Sqrt[ArcSinh[a + b*x]]])/(16*b)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{x^2/ArcSinh[a + b*x], x, 13, -CoshIntegral[ArcSinh[a + b*x]]/(4*b^3) + (a^2*CoshIntegral[ArcSinh[a + b*x]])/b^3 + CoshIntegral[3*ArcSinh[a + b*x]]/(4*b^3) - (a*SinhIntegral[2*ArcSinh[a + b*x]])/b^3}
{x/ArcSinh[a + b*x], x, 8, -((a*CoshIntegral[ArcSinh[a + b*x]])/b^2) + SinhIntegral[2*ArcSinh[a + b*x]]/(2*b^2)}
{ArcSinh[a + b*x]^(-1), x, 2, CoshIntegral[ArcSinh[a + b*x]]/b}
{1/(x*ArcSinh[a + b*x]), x, 0, Int[1/(x*ArcSinh[a + b*x]), x]}


{x^2/ArcSinh[a + b*x]^2, x, 12, -((a^2*Sqrt[1 + (a + b*x)^2])/(b^3*ArcSinh[a + b*x])) + (2*a*(a + b*x)*Sqrt[1 + (a + b*x)^2])/(b^3*ArcSinh[a + b*x]) - ((a + b*x)^2*Sqrt[1 + (a + b*x)^2])/(b^3*ArcSinh[a + b*x]) - (2*a*CoshIntegral[2*ArcSinh[a + b*x]])/b^3 - SinhIntegral[ArcSinh[a + b*x]]/(4*b^3) + (a^2*SinhIntegral[ArcSinh[a + b*x]])/b^3 + (3*SinhIntegral[3*ArcSinh[a + b*x]])/(4*b^3)}
{x^1/ArcSinh[a + b*x]^2, x, 8, (a*Sqrt[1 + (a + b*x)^2])/(b^2*ArcSinh[a + b*x]) - ((a + b*x)*Sqrt[1 + (a + b*x)^2])/(b^2*ArcSinh[a + b*x]) + CoshIntegral[2*ArcSinh[a + b*x]]/b^2 - (a*SinhIntegral[ArcSinh[a + b*x]])/b^2}
{x^0/ArcSinh[a + b*x]^2, x, 4, -(Sqrt[1 + (a + b*x)^2]/(b*ArcSinh[a + b*x])) + SinhIntegral[ArcSinh[a + b*x]]/b}
{1/(x^1*ArcSinh[a + b*x]^2), x, 0, Int[1/(x*ArcSinh[a + b*x]^2), x]}


{x^2/ArcSinh[a + b*x]^3, x, 19, -((a^2*Sqrt[1 + (a + b*x)^2])/(2*b^3*ArcSinh[a + b*x]^2)) + (a*(a + b*x)*Sqrt[1 + (a + b*x)^2])/(b^3*ArcSinh[a + b*x]^2) - ((a + b*x)^2*Sqrt[1 + (a + b*x)^2])/(2*b^3*ArcSinh[a + b*x]^2) + a/(b^3*ArcSinh[a + b*x]) - (a + b*x)/(b^3*ArcSinh[a + b*x]) - (a^2*(a + b*x))/(2*b^3*ArcSinh[a + b*x]) + (2*a*(a + b*x)^2)/(b^3*ArcSinh[a + b*x]) - (3*(a + b*x)^3)/(2*b^3*ArcSinh[a + b*x]) - CoshIntegral[ArcSinh[a + b*x]]/(8*b^3) + (a^2*CoshIntegral[ArcSinh[a + b*x]])/(2*b^3) + (9*CoshIntegral[3*ArcSinh[a + b*x]])/(8*b^3) - (2*a*SinhIntegral[2*ArcSinh[a + b*x]])/b^3}
{x^1/ArcSinh[a + b*x]^3, x, 11, (a*Sqrt[1 + (a + b*x)^2])/(2*b^2*ArcSinh[a + b*x]^2) - ((a + b*x)*Sqrt[1 + (a + b*x)^2])/(2*b^2*ArcSinh[a + b*x]^2) - 1/(2*b^2*ArcSinh[a + b*x]) + (a*(a + b*x))/(2*b^2*ArcSinh[a + b*x]) - (a + b*x)^2/(b^2*ArcSinh[a + b*x]) - (a*CoshIntegral[ArcSinh[a + b*x]])/(2*b^2) + SinhIntegral[2*ArcSinh[a + b*x]]/b^2}
{ArcSinh[a + b*x]^(-3), x, 3, -Sqrt[1 + (a + b*x)^2]/(2*b*ArcSinh[a + b*x]^2) - (a + b*x)/(2*b*ArcSinh[a + b*x]) + CoshIntegral[ArcSinh[a + b*x]]/(2*b)}
{1/(x*ArcSinh[a + b*x]^3), x, 0, Int[1/(x*ArcSinh[a + b*x]^3), x]}


{1/Sqrt[ArcSinh[a + b*x]], x, 6, (Sqrt[Pi]*Erf[Sqrt[ArcSinh[a + b*x]]])/(2*b) + (Sqrt[Pi]*Erfi[Sqrt[ArcSinh[a + b*x]]])/(2*b)}
{1/ArcSinh[a + b*x]^(3/2), x, 6, (-2*Sqrt[1 + (a + b*x)^2])/(b*Sqrt[ArcSinh[a + b*x]]) - (Sqrt[Pi]*Erf[Sqrt[ArcSinh[a + b*x]]])/b + (Sqrt[Pi]*Erfi[Sqrt[ArcSinh[a + b*x]]])/b}
{1/ArcSinh[a + b*x]^(5/2), x, 7, (-2*Sqrt[1 + (a + b*x)^2])/(3*b*ArcSinh[a + b*x]^(3/2)) - (4*(a + b*x))/(3*b*Sqrt[ArcSinh[a + b*x]]) + (2*Sqrt[Pi]*Erf[Sqrt[ArcSinh[a + b*x]]])/(3*b) + (2*Sqrt[Pi]*Erfi[Sqrt[ArcSinh[a + b*x]]])/(3*b)}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{x^m*ArcSinh[a + b*x]^n, x, 0, Int[x^m*ArcSinh[a + b*x]^n, x]}

{x^2*ArcSinh[a + b*x]^n, x, 25, -(a*ArcSinh[a + b*x]^n)/(2*b^3) - (a*(a + b*x)^2*ArcSinh[a + b*x]^n)/b^3 + ((a + b*x)^3*ArcSinh[a + b*x]^n)/(3*b^3) + (3^(-1 - n)*n*ArcSinh[a + b*x]^n*Gamma[n, -3*ArcSinh[a + b*x]])/(8*b^3*(-ArcSinh[a + b*x])^n) - (2^(-2 - n)*a*n*ArcSinh[a + b*x]^n*Gamma[n, -2*ArcSinh[a + b*x]])/(b^3*(-ArcSinh[a + b*x])^n) - (n*ArcSinh[a + b*x]^n*Gamma[n, -ArcSinh[a + b*x]])/(8*b^3*(-ArcSinh[a + b*x])^n) + (n*Gamma[n, ArcSinh[a + b*x]])/(8*b^3) - (2^(-2 - n)*a*n*Gamma[n, 2*ArcSinh[a + b*x]])/b^3 - (3^(-1 - n)*n*Gamma[n, 3*ArcSinh[a + b*x]])/(8*b^3) + (a^2*ArcSinh[a + b*x]^n*Gamma[1 + n, -ArcSinh[a + b*x]])/(2*b^3*(-ArcSinh[a + b*x])^n) - (a^2*Gamma[1 + n, ArcSinh[a + b*x]])/(2*b^3)}
{x*ArcSinh[a + b*x]^n, x, 14, ArcSinh[a + b*x]^n/(4*b^2) + ((a + b*x)^2*ArcSinh[a + b*x]^n)/(2*b^2) + (2^(-3 - n)*n*ArcSinh[a + b*x]^n*Gamma[n, -2*ArcSinh[a + b*x]])/(b^2*(-ArcSinh[a + b*x])^n) + (2^(-3 - n)*n*Gamma[n, 2*ArcSinh[a + b*x]])/b^2 - (a*ArcSinh[a + b*x]^n*Gamma[1 + n, -ArcSinh[a + b*x]])/(2*b^2*(-ArcSinh[a + b*x])^n) + (a*Gamma[1 + n, ArcSinh[a + b*x]])/(2*b^2)}
{ArcSinh[a + b*x]^n, x, 4, (ArcSinh[a + b*x]^n*Gamma[1 + n, -ArcSinh[a + b*x]])/(2*b*(-ArcSinh[a + b*x])^n) - Gamma[1 + n, ArcSinh[a + b*x]]/(2*b)}
{ArcSinh[a + b*x]^n/x, x, 0, Int[ArcSinh[a + b*x]^n/x, x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcSinh[a x^n]*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{x^3*ArcSinh[a*x^2], x, 5, -((x^2*Sqrt[1 + a^2*x^4])/(8*a)) + ArcSinh[a*x^2]/(8*a^2) + (1/4)*x^4*ArcSinh[a*x^2]}
{x^2*ArcSinh[a*x^2], x, 4, -((2*x*Sqrt[1 + a^2*x^4])/(9*a)) + (1/3)*x^3*ArcSinh[a*x^2] - (2*a*EllipticF[ArcSin[(-a^2)^(1/4)*x], -1])/(9*(-a^2)^(5/4))}
{x^1*ArcSinh[a*x^2], x, 2, -(Sqrt[1 + a^2*x^4]/(2*a)) + (1/2)*x^2*ArcSinh[a*x^2]}
{x^0*ArcSinh[a*x^2], x, 3, x*ArcSinh[a*x^2] - (2*a*EllipticE[ArcSin[(-a^2)^(1/4)*x], -1])/(-a^2)^(3/4) + (2*a*EllipticF[ArcSin[(-a^2)^(1/4)*x], -1])/(-a^2)^(3/4)}
{ArcSinh[a*x^2]/x^1, x, 5, (-(1/4))*ArcSinh[a*x^2]^2 + (1/2)*ArcSinh[a*x^2]*Log[1 - E^(2*ArcSinh[a*x^2])] + (1/4)*PolyLog[2, E^(2*ArcSinh[a*x^2])]}
{ArcSinh[a*x^2]/x^2, x, 3, -(ArcSinh[a*x^2]/x) + (2*a*EllipticF[ArcSin[(-a^2)^(1/4)*x], -1])/(-a^2)^(1/4)}
{ArcSinh[a*x^2]/x^3, x, 4, -(ArcSinh[a*x^2]/(2*x^2)) - (1/2)*a*ArcTanh[Sqrt[1 + a^2*x^4]]}
{ArcSinh[a*x^2]/x^4, x, 4, -((2*a*Sqrt[1 + a^2*x^4])/(3*x)) - ArcSinh[a*x^2]/(3*x^3) - (2/3)*a*(-a^2)^(1/4)*EllipticE[ArcSin[(-a^2)^(1/4)*x], -1] + (2/3)*a*(-a^2)^(1/4)*EllipticF[ArcSin[(-a^2)^(1/4)*x], -1]}


{ArcSinh[a*x^5]/x, x, 5, (-(1/10))*ArcSinh[a*x^5]^2 + (1/5)*ArcSinh[a*x^5]*Log[1 - E^(2*ArcSinh[a*x^5])] + (1/10)*PolyLog[2, E^(2*ArcSinh[a*x^5])]}


{x^2*ArcSinh[Sqrt[x]], x, 6, (-(5/48))*Sqrt[x]*Sqrt[1 + x] + (5/72)*x^(3/2)*Sqrt[1 + x] - (1/18)*x^(5/2)*Sqrt[1 + x] + (5*ArcSinh[Sqrt[x]])/48 + (1/3)*x^3*ArcSinh[Sqrt[x]]}
{x^1*ArcSinh[Sqrt[x]], x, 5, (3/16)*Sqrt[x]*Sqrt[1 + x] - (1/8)*x^(3/2)*Sqrt[1 + x] - (3*ArcSinh[Sqrt[x]])/16 + (1/2)*x^2*ArcSinh[Sqrt[x]]}
{x^0*ArcSinh[Sqrt[x]], x, 4, (-(1/2))*Sqrt[x]*Sqrt[1 + x] + ArcSinh[Sqrt[x]]/2 + x*ArcSinh[Sqrt[x]]}
{ArcSinh[Sqrt[x]]/x^1, x, 5, -ArcSinh[Sqrt[x]]^2 + 2*ArcSinh[Sqrt[x]]*Log[1 - E^(2*ArcSinh[Sqrt[x]])] + PolyLog[2, E^(2*ArcSinh[Sqrt[x]])]}
{ArcSinh[Sqrt[x]]/x^2, x, 3, -(Sqrt[1 + x]/Sqrt[x]) - ArcSinh[Sqrt[x]]/x}
{ArcSinh[Sqrt[x]]/x^3, x, 4, -(Sqrt[1 + x]/(6*x^(3/2))) + Sqrt[1 + x]/(3*Sqrt[x]) - ArcSinh[Sqrt[x]]/(2*x^2)}
{ArcSinh[Sqrt[x]]/x^4, x, 5, -(Sqrt[1 + x]/(15*x^(5/2))) + (4*Sqrt[1 + x])/(45*x^(3/2)) - (8*Sqrt[1 + x])/(45*Sqrt[x]) - ArcSinh[Sqrt[x]]/(3*x^3)}
{ArcSinh[Sqrt[x]]/x^5, x, 6, -(Sqrt[1 + x]/(28*x^(7/2))) + (3*Sqrt[1 + x])/(70*x^(5/2)) - (2*Sqrt[1 + x])/(35*x^(3/2)) + (4*Sqrt[1 + x])/(35*Sqrt[x]) - ArcSinh[Sqrt[x]]/(4*x^4)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{x^2*ArcSinh[a/x], x, 5, (1/6)*a*Sqrt[1 + a^2/x^2]*x^2 + (1/3)*x^3*ArcCsch[x/a] - (1/6)*a^3*ArcTanh[Sqrt[1 + a^2/x^2]]}
{x^1*ArcSinh[a/x], x, 3, (1/2)*a*Sqrt[1 + a^2/x^2]*x + (1/2)*x^2*ArcCsch[x/a]}
{x^0*ArcSinh[a/x], x, 4, x*ArcCsch[x/a] + a*ArcTanh[Sqrt[1 + a^2/x^2]]}
{ArcSinh[a/x]/x^1, x, 5, (1/2)*ArcSinh[a/x]^2 - ArcSinh[a/x]*Log[1 - E^(2*ArcSinh[a/x])] - (1/2)*PolyLog[2, E^(2*ArcSinh[a/x])]}
{ArcSinh[a/x]/x^2, x, 3, Sqrt[1 + a^2/x^2]/a - ArcCsch[x/a]/x}
{ArcSinh[a/x]/x^3, x, 5, Sqrt[1 + a^2/x^2]/(4*a*x) - ArcCsch[x/a]/(2*x^2) - ArcSinh[a/x]/(4*a^2)}
{ArcSinh[a/x]/x^4, x, 5, -((2*Sqrt[1 + a^2/x^2])/(9*a^3)) + Sqrt[1 + a^2/x^2]/(9*a*x^2) - ArcCsch[x/a]/(3*x^3)}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{x^m*ArcSinh[a*x^n], x, 3, (x^(1 + m)*ArcSinh[a*x^n])/(1 + m) - (a*n*x^(1 + m + n)*Hypergeometric2F1[1/2, (1 + m + n)/(2*n), (1 + m + 3*n)/(2*n), (-a^2)*x^(2*n)])/((1 + m)*(1 + m + n))}

{x^2*ArcSinh[a*x^n], x, 3, (1/3)*x^3*ArcSinh[a*x^n] - (a*n*x^(3 + n)*Hypergeometric2F1[1/2, (3 + n)/(2*n), (3*(1 + n))/(2*n), (-a^2)*x^(2*n)])/(3*(3 + n))}
{x^1*ArcSinh[a*x^n], x, 3, (1/2)*x^2*ArcSinh[a*x^n] - (a*n*x^(2 + n)*Hypergeometric2F1[1/2, (2 + n)/(2*n), (1/2)*(3 + 2/n), (-a^2)*x^(2*n)])/(2*(2 + n))}
{x^0*ArcSinh[a*x^n], x, 3, x*ArcSinh[a*x^n] - (a*n*x^(1 + n)*Hypergeometric2F1[1/2, (1 + n)/(2*n), (1/2)*(3 + 1/n), (-a^2)*x^(2*n)])/(1 + n)}
{ArcSinh[a*x^n]/x^1, x, 5, -(ArcSinh[a*x^n]^2/(2*n)) + (ArcSinh[a*x^n]*Log[1 - E^(2*ArcSinh[a*x^n])])/n + PolyLog[2, E^(2*ArcSinh[a*x^n])]/(2*n)}
{ArcSinh[a*x^n]/x^2, x, 3, -(ArcSinh[a*x^n]/x) - (a*n*x^(-1 + n)*Hypergeometric2F1[1/2, -((1 - n)/(2*n)), (1/2)*(3 - 1/n), (-a^2)*x^(2*n)])/(1 - n)}
{ArcSinh[a*x^n]/x^3, x, 3, -(ArcSinh[a*x^n]/(2*x^2)) - (a*n*x^(-2 + n)*Hypergeometric2F1[1/2, (1/2)*(1 - 2/n), (1/2)*(3 - 2/n), (-a^2)*x^(2*n)])/(2*(2 - n))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a+b ArcSinh[c x])^n*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{x^2*(a + b*ArcSinh[c*x])^(1/2), x, 10, (1/3)*x^3*Sqrt[a + b*ArcSinh[c*x]] - (Sqrt[b]*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c*x]]/Sqrt[b]])/(16*c^3) + (Sqrt[b]*E^((3*a)/b)*Sqrt[Pi/3]*Erf[(Sqrt[3]*Sqrt[a + b*ArcSinh[c*x]])/Sqrt[b]])/(48*c^3) + (Sqrt[b]*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c*x]]/Sqrt[b]])/(E^(a/b)*(16*c^3)) - (Sqrt[b]*Sqrt[Pi/3]*Erfi[(Sqrt[3]*Sqrt[a + b*ArcSinh[c*x]])/Sqrt[b]])/(E^((3*a)/b)*(48*c^3))}
{x^1*(a + b*ArcSinh[c*x])^(1/2), x, 7, Sqrt[a + b*ArcSinh[c*x]]/(4*c^2) + (1/2)*x^2*Sqrt[a + b*ArcSinh[c*x]] - (Sqrt[b]*E^((2*a)/b)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[a + b*ArcSinh[c*x]])/Sqrt[b]])/(16*c^2) - (Sqrt[b]*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[a + b*ArcSinh[c*x]])/Sqrt[b]])/(E^((2*a)/b)*(16*c^2))}
{x^0*(a + b*ArcSinh[c*x])^(1/2), x, 6, x*Sqrt[a + b*ArcSinh[c*x]] + (Sqrt[b]*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c*x]]/Sqrt[b]])/(4*c) - (Sqrt[b]*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c*x]]/Sqrt[b]])/(E^(a/b)*(4*c))}


{x^2*(a + b*ArcSinh[c*x])^(3/2), x, 18, (b*Sqrt[1 + c^2*x^2]*Sqrt[a + b*ArcSinh[c*x]])/(3*c^3) - (b*x^2*Sqrt[1 + c^2*x^2]*Sqrt[a + b*ArcSinh[c*x]])/(6*c) + (1/3)*x^3*(a + b*ArcSinh[c*x])^(3/2) - (3*b^(3/2)*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c*x]]/Sqrt[b]])/(32*c^3) + (b^(3/2)*E^((3*a)/b)*Sqrt[Pi/3]*Erf[(Sqrt[3]*Sqrt[a + b*ArcSinh[c*x]])/Sqrt[b]])/(96*c^3) - (3*b^(3/2)*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c*x]]/Sqrt[b]])/(E^(a/b)*(32*c^3)) + (b^(3/2)*Sqrt[Pi/3]*Erfi[(Sqrt[3]*Sqrt[a + b*ArcSinh[c*x]])/Sqrt[b]])/(E^((3*a)/b)*(96*c^3))}
{x^1*(a + b*ArcSinh[c*x])^(3/2), x, 8, -((3*b*x*Sqrt[1 + c^2*x^2]*Sqrt[a + b*ArcSinh[c*x]])/(8*c)) + (a + b*ArcSinh[c*x])^(3/2)/(4*c^2) + (1/2)*x^2*(a + b*ArcSinh[c*x])^(3/2) - (3*b^(3/2)*E^((2*a)/b)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[a + b*ArcSinh[c*x]])/Sqrt[b]])/(64*c^2) + (3*b^(3/2)*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[a + b*ArcSinh[c*x]])/Sqrt[b]])/(E^((2*a)/b)*(64*c^2))}
{x^0*(a + b*ArcSinh[c*x])^(3/2), x, 7, -((3*b*Sqrt[1 + c^2*x^2]*Sqrt[a + b*ArcSinh[c*x]])/(2*c)) + x*(a + b*ArcSinh[c*x])^(3/2) + (3*b^(3/2)*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c*x]]/Sqrt[b]])/(8*c) + (3*b^(3/2)*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c*x]]/Sqrt[b]])/(E^(a/b)*(8*c))}


{x^2*(a + b*ArcSinh[c*x])^(5/2), x, 19, -((5*b^2*x*Sqrt[a + b*ArcSinh[c*x]])/(6*c^2)) + (5/36)*b^2*x^3*Sqrt[a + b*ArcSinh[c*x]] + (5*b*Sqrt[1 + c^2*x^2]*(a + b*ArcSinh[c*x])^(3/2))/(9*c^3) - (5*b*x^2*Sqrt[1 + c^2*x^2]*(a + b*ArcSinh[c*x])^(3/2))/(18*c) + (1/3)*x^3*(a + b*ArcSinh[c*x])^(5/2) - (15*b^(5/2)*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c*x]]/Sqrt[b]])/(64*c^3) + (5*b^(5/2)*E^((3*a)/b)*Sqrt[Pi/3]*Erf[(Sqrt[3]*Sqrt[a + b*ArcSinh[c*x]])/Sqrt[b]])/(576*c^3) + (15*b^(5/2)*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c*x]]/Sqrt[b]])/(E^(a/b)*(64*c^3)) - (5*b^(5/2)*Sqrt[Pi/3]*Erfi[(Sqrt[3]*Sqrt[a + b*ArcSinh[c*x]])/Sqrt[b]])/(E^((3*a)/b)*(576*c^3))}
{x^1*(a + b*ArcSinh[c*x])^(5/2), x, 10, (15*b^2*Sqrt[a + b*ArcSinh[c*x]])/(64*c^2) + (15/32)*b^2*x^2*Sqrt[a + b*ArcSinh[c*x]] - (5*b*x*Sqrt[1 + c^2*x^2]*(a + b*ArcSinh[c*x])^(3/2))/(8*c) + (a + b*ArcSinh[c*x])^(5/2)/(4*c^2) + (1/2)*x^2*(a + b*ArcSinh[c*x])^(5/2) - (15*b^(5/2)*E^((2*a)/b)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[a + b*ArcSinh[c*x]])/Sqrt[b]])/(256*c^2) - (15*b^(5/2)*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[a + b*ArcSinh[c*x]])/Sqrt[b]])/(E^((2*a)/b)*(256*c^2))}
{x^0*(a + b*ArcSinh[c*x])^(5/2), x, 7, (15/4)*b^2*x*Sqrt[a + b*ArcSinh[c*x]] - (5*b*Sqrt[1 + c^2*x^2]*(a + b*ArcSinh[c*x])^(3/2))/(2*c) + x*(a + b*ArcSinh[c*x])^(5/2) + (15*b^(5/2)*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c*x]]/Sqrt[b]])/(16*c) - (15*b^(5/2)*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c*x]]/Sqrt[b]])/(E^(a/b)*(16*c))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{x^2/(a + b*ArcSinh[c*x])^(1/2), x, 9, -((E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c*x]]/Sqrt[b]])/(8*Sqrt[b]*c^3)) + (E^((3*a)/b)*Sqrt[Pi/3]*Erf[(Sqrt[3]*Sqrt[a + b*ArcSinh[c*x]])/Sqrt[b]])/(8*Sqrt[b]*c^3) - (Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c*x]]/Sqrt[b]])/(E^(a/b)*(8*Sqrt[b]*c^3)) + (Sqrt[Pi/3]*Erfi[(Sqrt[3]*Sqrt[a + b*ArcSinh[c*x]])/Sqrt[b]])/(E^((3*a)/b)*(8*Sqrt[b]*c^3))}
{x^1/(a + b*ArcSinh[c*x])^(1/2), x, 5, -((E^((2*a)/b)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[a + b*ArcSinh[c*x]])/Sqrt[b]])/(4*Sqrt[b]*c^2)) + (Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[a + b*ArcSinh[c*x]])/Sqrt[b]])/(E^((2*a)/b)*(4*Sqrt[b]*c^2))}
{x^0/(a + b*ArcSinh[c*x])^(1/2), x, 6, (E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c*x]]/Sqrt[b]])/(2*Sqrt[b]*c) + (Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c*x]]/Sqrt[b]])/(E^(a/b)*(2*Sqrt[b]*c))}


{x^2/(a + b*ArcSinh[c*x])^(3/2), x, 9, -((2*x^2*Sqrt[1 + c^2*x^2])/(b*c*Sqrt[a + b*ArcSinh[c*x]])) + (E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c*x]]/Sqrt[b]])/(4*b^(3/2)*c^3) - (E^((3*a)/b)*Sqrt[3*Pi]*Erf[(Sqrt[3]*Sqrt[a + b*ArcSinh[c*x]])/Sqrt[b]])/(4*b^(3/2)*c^3) - (Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c*x]]/Sqrt[b]])/(E^(a/b)*(4*b^(3/2)*c^3)) + (Sqrt[3*Pi]*Erfi[(Sqrt[3]*Sqrt[a + b*ArcSinh[c*x]])/Sqrt[b]])/(E^((3*a)/b)*(4*b^(3/2)*c^3))}
{x^1/(a + b*ArcSinh[c*x])^(3/2), x, 4, -((2*x*Sqrt[1 + c^2*x^2])/(b*c*Sqrt[a + b*ArcSinh[c*x]])) + (E^((2*a)/b)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[a + b*ArcSinh[c*x]])/Sqrt[b]])/(b^(3/2)*c^2) + (Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[a + b*ArcSinh[c*x]])/Sqrt[b]])/(E^((2*a)/b)*(b^(3/2)*c^2))}
{x^0/(a + b*ArcSinh[c*x])^(3/2), x, 6, -((2*Sqrt[1 + c^2*x^2])/(b*c*Sqrt[a + b*ArcSinh[c*x]])) - (E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c*x]]/Sqrt[b]])/(b^(3/2)*c) + (Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c*x]]/Sqrt[b]])/(E^(a/b)*(b^(3/2)*c))}


{x^2/(a + b*ArcSinh[c*x])^(5/2), x, 16, -((2*x^2*Sqrt[1 + c^2*x^2])/(3*b*c*(a + b*ArcSinh[c*x])^(3/2))) - (8*x)/(3*b^2*c^2*Sqrt[a + b*ArcSinh[c*x]]) - (4*x^3)/(b^2*Sqrt[a + b*ArcSinh[c*x]]) - (E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c*x]]/Sqrt[b]])/(6*b^(5/2)*c^3) + (E^((3*a)/b)*Sqrt[3*Pi]*Erf[(Sqrt[3]*Sqrt[a + b*ArcSinh[c*x]])/Sqrt[b]])/(2*b^(5/2)*c^3) - (Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c*x]]/Sqrt[b]])/(E^(a/b)*(6*b^(5/2)*c^3)) + (Sqrt[3*Pi]*Erfi[(Sqrt[3]*Sqrt[a + b*ArcSinh[c*x]])/Sqrt[b]])/(E^((3*a)/b)*(2*b^(5/2)*c^3))}
{x^1/(a + b*ArcSinh[c*x])^(5/2), x, 7, -((2*x*Sqrt[1 + c^2*x^2])/(3*b*c*(a + b*ArcSinh[c*x])^(3/2))) - 4/(3*b^2*c^2*Sqrt[a + b*ArcSinh[c*x]]) - (8*x^2)/(3*b^2*Sqrt[a + b*ArcSinh[c*x]]) - (2*E^((2*a)/b)*Sqrt[2*Pi]*Erf[(Sqrt[2]*Sqrt[a + b*ArcSinh[c*x]])/Sqrt[b]])/(3*b^(5/2)*c^2) + (2*Sqrt[2*Pi]*Erfi[(Sqrt[2]*Sqrt[a + b*ArcSinh[c*x]])/Sqrt[b]])/(E^((2*a)/b)*(3*b^(5/2)*c^2))}
{x^0/(a + b*ArcSinh[c*x])^(5/2), x, 7, -((2*Sqrt[1 + c^2*x^2])/(3*b*c*(a + b*ArcSinh[c*x])^(3/2))) - (4*x)/(3*b^2*Sqrt[a + b*ArcSinh[c*x]]) + (2*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c*x]]/Sqrt[b]])/(3*b^(5/2)*c) + (2*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c*x]]/Sqrt[b]])/(E^(a/b)*(3*b^(5/2)*c))}


{x^2/(a + b*ArcSinh[c*x])^(7/2), x, 16, -((2*x^2*Sqrt[1 + c^2*x^2])/(5*b*c*(a + b*ArcSinh[c*x])^(5/2))) - (8*x)/(15*b^2*c^2*(a + b*ArcSinh[c*x])^(3/2)) - (4*x^3)/(5*b^2*(a + b*ArcSinh[c*x])^(3/2)) - (16*Sqrt[1 + c^2*x^2])/(15*b^3*c^3*Sqrt[a + b*ArcSinh[c*x]]) - (24*x^2*Sqrt[1 + c^2*x^2])/(5*b^3*c*Sqrt[a + b*ArcSinh[c*x]]) + (E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c*x]]/Sqrt[b]])/(15*b^(7/2)*c^3) - (3*E^((3*a)/b)*Sqrt[3*Pi]*Erf[(Sqrt[3]*Sqrt[a + b*ArcSinh[c*x]])/Sqrt[b]])/(5*b^(7/2)*c^3) - (Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c*x]]/Sqrt[b]])/(E^(a/b)*(15*b^(7/2)*c^3)) + (3*Sqrt[3*Pi]*Erfi[(Sqrt[3]*Sqrt[a + b*ArcSinh[c*x]])/Sqrt[b]])/(E^((3*a)/b)*(5*b^(7/2)*c^3))}
{x^1/(a + b*ArcSinh[c*x])^(7/2), x, 6, -((2*x*Sqrt[1 + c^2*x^2])/(5*b*c*(a + b*ArcSinh[c*x])^(5/2))) - 4/(15*b^2*c^2*(a + b*ArcSinh[c*x])^(3/2)) - (8*x^2)/(15*b^2*(a + b*ArcSinh[c*x])^(3/2)) - (32*x*Sqrt[1 + c^2*x^2])/(15*b^3*c*Sqrt[a + b*ArcSinh[c*x]]) + (8*E^((2*a)/b)*Sqrt[2*Pi]*Erf[(Sqrt[2]*Sqrt[a + b*ArcSinh[c*x]])/Sqrt[b]])/(15*b^(7/2)*c^2) + (8*Sqrt[2*Pi]*Erfi[(Sqrt[2]*Sqrt[a + b*ArcSinh[c*x]])/Sqrt[b]])/(E^((2*a)/b)*(15*b^(7/2)*c^2))}
{x^0/(a + b*ArcSinh[c*x])^(7/2), x, 7, -((2*Sqrt[1 + c^2*x^2])/(5*b*c*(a + b*ArcSinh[c*x])^(5/2))) - (4*x)/(15*b^2*(a + b*ArcSinh[c*x])^(3/2)) - (8*Sqrt[1 + c^2*x^2])/(15*b^3*c*Sqrt[a + b*ArcSinh[c*x]]) - (4*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c*x]]/Sqrt[b]])/(15*b^(7/2)*c) + (4*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c*x]]/Sqrt[b]])/(E^(a/b)*(15*b^(7/2)*c))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a+b ArcSinh[c+d x])^n*)


(* ::Subsubsection::Closed:: *)
(*n/2*)


{(a + b*ArcSinh[c + d*x])^(5/2), x, 7, (15*b^2*(c + d*x)*Sqrt[a + b*ArcSinh[c + d*x]])/(4*d) - (5*b*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^(3/2))/(2*d) + ((c + d*x)*(a + b*ArcSinh[c + d*x])^(5/2))/d + (15*b^(5/2)*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(16*d) - (15*b^(5/2)*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(E^(a/b)*(16*d))}
{(a + b*ArcSinh[c + d*x])^(3/2), x, 7, -((3*b*Sqrt[1 + (c + d*x)^2]*Sqrt[a + b*ArcSinh[c + d*x]])/(2*d)) + ((c + d*x)*(a + b*ArcSinh[c + d*x])^(3/2))/d + (3*b^(3/2)*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(8*d) + (3*b^(3/2)*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(E^(a/b)*(8*d))}
{(a + b*ArcSinh[c + d*x])^(1/2), x, 6, ((c + d*x)*Sqrt[a + b*ArcSinh[c + d*x]])/d + (Sqrt[b]*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(4*d) - (Sqrt[b]*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(E^(a/b)*(4*d))}
{1/(a + b*ArcSinh[c + d*x])^(1/2), x, 6, (E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(2*Sqrt[b]*d) + (Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(E^(a/b)*(2*Sqrt[b]*d))}
{1/(a + b*ArcSinh[c + d*x])^(3/2), x, 6, -((2*Sqrt[1 + (c + d*x)^2])/(b*d*Sqrt[a + b*ArcSinh[c + d*x]])) - (E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(b^(3/2)*d) + (Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(E^(a/b)*(b^(3/2)*d))}
{1/(a + b*ArcSinh[c + d*x])^(5/2), x, 7, -((2*Sqrt[1 + (c + d*x)^2])/(3*b*d*(a + b*ArcSinh[c + d*x])^(3/2))) - (4*(c + d*x))/(3*b^2*d*Sqrt[a + b*ArcSinh[c + d*x]]) + (2*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(3*b^(5/2)*d) + (2*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(E^(a/b)*(3*b^(5/2)*d))}
{1/(a + b*ArcSinh[c + d*x])^(7/2), x, 7, -((2*Sqrt[1 + (c + d*x)^2])/(5*b*d*(a + b*ArcSinh[c + d*x])^(5/2))) - (4*(c + d*x))/(15*b^2*d*(a + b*ArcSinh[c + d*x])^(3/2)) - (8*Sqrt[1 + (c + d*x)^2])/(15*b^3*d*Sqrt[a + b*ArcSinh[c + d*x]]) - (4*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(15*b^(7/2)*d) + (4*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(E^(a/b)*(15*b^(7/2)*d))}


{x*(a + b*ArcSinh[c + d*x])^(5/2), x, 20, (15*b^2*Sqrt[a + b*ArcSinh[c + d*x]])/(64*d^2) - (15*b^2*c*(c + d*x)*Sqrt[a + b*ArcSinh[c + d*x]])/(4*d^2) + (15*b^2*(c + d*x)^2*Sqrt[a + b*ArcSinh[c + d*x]])/(32*d^2) + (5*b*c*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^(3/2))/(2*d^2) - (5*b*(c + d*x)*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^(3/2))/(8*d^2) + (a + b*ArcSinh[c + d*x])^(5/2)/(4*d^2) - (c*(c + d*x)*(a + b*ArcSinh[c + d*x])^(5/2))/d^2 + ((c + d*x)^2*(a + b*ArcSinh[c + d*x])^(5/2))/(2*d^2) - (15*b^(5/2)*c*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(16*d^2) - (15*b^(5/2)*E^((2*a)/b)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(256*d^2) + (15*b^(5/2)*c*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(E^(a/b)*(16*d^2)) - (15*b^(5/2)*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(E^((2*a)/b)*(256*d^2))}
{x*(a + b*ArcSinh[c + d*x])^(3/2), x, 18, (3*b*c*Sqrt[1 + (c + d*x)^2]*Sqrt[a + b*ArcSinh[c + d*x]])/(2*d^2) - (3*b*(c + d*x)*Sqrt[1 + (c + d*x)^2]*Sqrt[a + b*ArcSinh[c + d*x]])/(8*d^2) + (a + b*ArcSinh[c + d*x])^(3/2)/(4*d^2) - (c*(c + d*x)*(a + b*ArcSinh[c + d*x])^(3/2))/d^2 + ((c + d*x)^2*(a + b*ArcSinh[c + d*x])^(3/2))/(2*d^2) - (3*b^(3/2)*c*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(8*d^2) - (3*b^(3/2)*E^((2*a)/b)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(64*d^2) - (3*b^(3/2)*c*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(E^(a/b)*(8*d^2)) + (3*b^(3/2)*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(E^((2*a)/b)*(64*d^2))}
{x*(a + b*ArcSinh[c + d*x])^(1/2), x, 16, Sqrt[a + b*ArcSinh[c + d*x]]/(4*d^2) - (c*(c + d*x)*Sqrt[a + b*ArcSinh[c + d*x]])/d^2 + ((c + d*x)^2*Sqrt[a + b*ArcSinh[c + d*x]])/(2*d^2) - (Sqrt[b]*c*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(4*d^2) - (Sqrt[b]*E^((2*a)/b)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(16*d^2) + (Sqrt[b]*c*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(E^(a/b)*(4*d^2)) - (Sqrt[b]*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(E^((2*a)/b)*(16*d^2))}
{x/(a + b*ArcSinh[c + d*x])^(1/2), x, 14, -((c*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(2*Sqrt[b]*d^2)) - (E^((2*a)/b)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(4*Sqrt[b]*d^2) - (c*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(E^(a/b)*(2*Sqrt[b]*d^2)) + (Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(E^((2*a)/b)*(4*Sqrt[b]*d^2))}
{x/(a + b*ArcSinh[c + d*x])^(3/2), x, 12, (2*c*Sqrt[1 + (c + d*x)^2])/(b*d^2*Sqrt[a + b*ArcSinh[c + d*x]]) - (2*(c + d*x)*Sqrt[1 + (c + d*x)^2])/(b*d^2*Sqrt[a + b*ArcSinh[c + d*x]]) + (c*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(b^(3/2)*d^2) + (E^((2*a)/b)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(b^(3/2)*d^2) - (c*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(E^(a/b)*(b^(3/2)*d^2)) + (Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(E^((2*a)/b)*(b^(3/2)*d^2))}
{x/(a + b*ArcSinh[c + d*x])^(5/2), x, 17, (2*c*Sqrt[1 + (c + d*x)^2])/(3*b*d^2*(a + b*ArcSinh[c + d*x])^(3/2)) - (2*(c + d*x)*Sqrt[1 + (c + d*x)^2])/(3*b*d^2*(a + b*ArcSinh[c + d*x])^(3/2)) - 4/(3*b^2*d^2*Sqrt[a + b*ArcSinh[c + d*x]]) + (4*c*(c + d*x))/(3*b^2*d^2*Sqrt[a + b*ArcSinh[c + d*x]]) - (8*(c + d*x)^2)/(3*b^2*d^2*Sqrt[a + b*ArcSinh[c + d*x]]) - (2*c*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(3*b^(5/2)*d^2) - (2*E^((2*a)/b)*Sqrt[2*Pi]*Erf[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(3*b^(5/2)*d^2) - (2*c*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(E^(a/b)*(3*b^(5/2)*d^2)) + (2*Sqrt[2*Pi]*Erfi[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(E^((2*a)/b)*(3*b^(5/2)*d^2))}
{x/(a + b*ArcSinh[c + d*x])^(7/2), x, 15, (2*c*Sqrt[1 + (c + d*x)^2])/(5*b*d^2*(a + b*ArcSinh[c + d*x])^(5/2)) - (2*(c + d*x)*Sqrt[1 + (c + d*x)^2])/(5*b*d^2*(a + b*ArcSinh[c + d*x])^(5/2)) - 4/(15*b^2*d^2*(a + b*ArcSinh[c + d*x])^(3/2)) + (4*c*(c + d*x))/(15*b^2*d^2*(a + b*ArcSinh[c + d*x])^(3/2)) - (8*(c + d*x)^2)/(15*b^2*d^2*(a + b*ArcSinh[c + d*x])^(3/2)) + (8*c*Sqrt[1 + (c + d*x)^2])/(15*b^3*d^2*Sqrt[a + b*ArcSinh[c + d*x]]) - (32*(c + d*x)*Sqrt[1 + (c + d*x)^2])/(15*b^3*d^2*Sqrt[a + b*ArcSinh[c + d*x]]) + (4*c*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(15*b^(7/2)*d^2) + (8*E^((2*a)/b)*Sqrt[2*Pi]*Erf[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(15*b^(7/2)*d^2) - (4*c*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(E^(a/b)*(15*b^(7/2)*d^2)) + (8*Sqrt[2*Pi]*Erfi[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(E^((2*a)/b)*(15*b^(7/2)*d^2))}


{x^2*(a + b*ArcSinh[c + d*x])^(1/2), x, 27, -((c*Sqrt[a + b*ArcSinh[c + d*x]])/(2*d^3)) + (c^2*(c + d*x)*Sqrt[a + b*ArcSinh[c + d*x]])/d^3 - (c*(c + d*x)^2*Sqrt[a + b*ArcSinh[c + d*x]])/d^3 + ((c + d*x)^3*Sqrt[a + b*ArcSinh[c + d*x]])/(3*d^3) - (Sqrt[b]*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(16*d^3) + (Sqrt[b]*c^2*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(4*d^3) + (Sqrt[b]*c*E^((2*a)/b)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(8*d^3) + (Sqrt[b]*E^((3*a)/b)*Sqrt[Pi/3]*Erf[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(48*d^3) + (Sqrt[b]*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(E^(a/b)*(16*d^3)) - (Sqrt[b]*c^2*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(E^(a/b)*(4*d^3)) + (Sqrt[b]*c*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(E^((2*a)/b)*(8*d^3)) - (Sqrt[b]*Sqrt[Pi/3]*Erfi[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(E^((3*a)/b)*(48*d^3))}
{x^2/(a + b*ArcSinh[c + d*x])^(1/2), x, 24, -((E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(8*Sqrt[b]*d^3)) + (c^2*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(2*Sqrt[b]*d^3) + (c*E^((2*a)/b)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(2*Sqrt[b]*d^3) + (E^((3*a)/b)*Sqrt[Pi/3]*Erf[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(8*Sqrt[b]*d^3) - (Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(E^(a/b)*(8*Sqrt[b]*d^3)) + (c^2*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(E^(a/b)*(2*Sqrt[b]*d^3)) - (c*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(E^((2*a)/b)*(2*Sqrt[b]*d^3)) + (Sqrt[Pi/3]*Erfi[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(E^((3*a)/b)*(8*Sqrt[b]*d^3))}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{(a + b*ArcSinh[c + d*x])^n, x, 4, ((a + b*ArcSinh[c + d*x])^n*Gamma[1 + n, -((a + b*ArcSinh[c + d*x])/b)])/(E^(a/b)*(-((a + b*ArcSinh[c + d*x])/b))^n*(2*d)) - (E^(a/b)*(a + b*ArcSinh[c + d*x])^n*Gamma[1 + n, (a + b*ArcSinh[c + d*x])/b])/(((a + b*ArcSinh[c + d*x])/b)^n*(2*d))}
{x*(a + b*ArcSinh[c + d*x])^n, x, 14, (a + b*ArcSinh[c + d*x])^n/(4*d^2) + ((c + d*x)^2*(a + b*ArcSinh[c + d*x])^n)/(2*d^2) + (2^(-3 - n)*n*(a + b*ArcSinh[c + d*x])^n*Gamma[n, -((2*(a + b*ArcSinh[c + d*x]))/b)])/(E^((2*a)/b)*(-((a + b*ArcSinh[c + d*x])/b))^n*d^2) + (2^(-3 - n)*E^((2*a)/b)*n*(a + b*ArcSinh[c + d*x])^n*Gamma[n, (2*(a + b*ArcSinh[c + d*x]))/b])/(((a + b*ArcSinh[c + d*x])/b)^n*d^2) - (c*(a + b*ArcSinh[c + d*x])^n*Gamma[1 + n, -((a + b*ArcSinh[c + d*x])/b)])/(E^(a/b)*(-((a + b*ArcSinh[c + d*x])/b))^n*(2*d^2)) + (c*E^(a/b)*(a + b*ArcSinh[c + d*x])^n*Gamma[1 + n, (a + b*ArcSinh[c + d*x])/b])/(((a + b*ArcSinh[c + d*x])/b)^n*(2*d^2))}
{x^2*(a + b*ArcSinh[c + d*x])^n, x, 25, -((c*(a + b*ArcSinh[c + d*x])^n)/(2*d^3)) - (c*(c + d*x)^2*(a + b*ArcSinh[c + d*x])^n)/d^3 + ((c + d*x)^3*(a + b*ArcSinh[c + d*x])^n)/(3*d^3) + (3^(-1 - n)*n*(a + b*ArcSinh[c + d*x])^n*Gamma[n, -((3*(a + b*ArcSinh[c + d*x]))/b)])/(E^((3*a)/b)*(-((a + b*ArcSinh[c + d*x])/b))^n*(8*d^3)) - (2^(-2 - n)*c*n*(a + b*ArcSinh[c + d*x])^n*Gamma[n, -((2*(a + b*ArcSinh[c + d*x]))/b)])/(E^((2*a)/b)*(-((a + b*ArcSinh[c + d*x])/b))^n*d^3) - (n*(a + b*ArcSinh[c + d*x])^n*Gamma[n, -((a + b*ArcSinh[c + d*x])/b)])/(E^(a/b)*(-((a + b*ArcSinh[c + d*x])/b))^n*(8*d^3)) + (E^(a/b)*n*(a + b*ArcSinh[c + d*x])^n*Gamma[n, (a + b*ArcSinh[c + d*x])/b])/(((a + b*ArcSinh[c + d*x])/b)^n*(8*d^3)) - (2^(-2 - n)*c*E^((2*a)/b)*n*(a + b*ArcSinh[c + d*x])^n*Gamma[n, (2*(a + b*ArcSinh[c + d*x]))/b])/(((a + b*ArcSinh[c + d*x])/b)^n*d^3) - (3^(-1 - n)*E^((3*a)/b)*n*(a + b*ArcSinh[c + d*x])^n*Gamma[n, (3*(a + b*ArcSinh[c + d*x]))/b])/(((a + b*ArcSinh[c + d*x])/b)^n*(8*d^3)) + (c^2*(a + b*ArcSinh[c + d*x])^n*Gamma[1 + n, -((a + b*ArcSinh[c + d*x])/b)])/(E^(a/b)*(-((a + b*ArcSinh[c + d*x])/b))^n*(2*d^3)) - (c^2*E^(a/b)*(a + b*ArcSinh[c + d*x])^n*Gamma[1 + n, (a + b*ArcSinh[c + d*x])/b])/(((a + b*ArcSinh[c + d*x])/b)^n*(2*d^3))}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c e+d e x)^m (a+b ArcSinh[c+d x])^n*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{(c*e + d*e*x)^m*(a + b*ArcSinh[c + d*x]), x, 3, ((c*e + d*e*x)^(1 + m)*(a + b*ArcSinh[c + d*x]))/(d*e*(1 + m)) - (b*(c + d*x)*(c*e + d*e*x)^(1 + m)*Hypergeometric2F1[1/2, (2 + m)/2, (4 + m)/2, -(c + d*x)^2])/(d*e*(2 + 3*m + m^2))}

{(c*e + d*e*x)^4*(a + b*ArcSinh[c + d*x]), x, 5, (-8*b*e^4*Sqrt[1 + (c + d*x)^2])/(75*d) + (4*b*e^4*(c + d*x)^2*Sqrt[1 + (c + d*x)^2])/(75*d) - (b*e^4*(c + d*x)^4*Sqrt[1 + (c + d*x)^2])/(25*d) + (e^4*(c + d*x)^5*(a + b*ArcSinh[c + d*x]))/(5*d)}
{(c*e + d*e*x)^3*(a + b*ArcSinh[c + d*x]), x, 5, (3*b*e^3*(c + d*x)*Sqrt[1 + (c + d*x)^2])/(32*d) - (b*e^3*(c + d*x)^3*Sqrt[1 + (c + d*x)^2])/(16*d) - (3*b*e^3*ArcSinh[c + d*x])/(32*d) + (e^3*(c + d*x)^4*(a + b*ArcSinh[c + d*x]))/(4*d)}
{(c*e + d*e*x)^2*(a + b*ArcSinh[c + d*x]), x, 4, (2*b*e^2*Sqrt[1 + (c + d*x)^2])/(9*d) - (b*e^2*(c + d*x)^2*Sqrt[1 + (c + d*x)^2])/(9*d) + (e^2*(c + d*x)^3*(a + b*ArcSinh[c + d*x]))/(3*d)}
{(c*e + d*e*x)*(a + b*ArcSinh[c + d*x]), x, 4, -(b*e*(c + d*x)*Sqrt[1 + (c + d*x)^2])/(4*d) + (b*e*ArcSinh[c + d*x])/(4*d) + (e*(c + d*x)^2*(a + b*ArcSinh[c + d*x]))/(2*d)}
{a + b*ArcSinh[c + d*x], x, 2, a*x - (b*Sqrt[1 + (c + d*x)^2])/d + (b*(c + d*x)*ArcSinh[c + d*x])/d}
{(a + b*ArcSinh[c + d*x])/(c*e + d*e*x), x, 5, -(a + b*ArcSinh[c + d*x])^2/(2*b*d*e) + ((a + b*ArcSinh[c + d*x])*Log[1 - E^(2*ArcSinh[c + d*x])])/(d*e) + (b*PolyLog[2, E^(2*ArcSinh[c + d*x])])/(2*d*e)}
{(a + b*ArcSinh[c + d*x])/(c*e + d*e*x)^2, x, 4, -((a + b*ArcSinh[c + d*x])/(d*e^2*(c + d*x))) - (b*ArcTanh[Sqrt[1 + (c + d*x)^2]])/(d*e^2)}
{(a + b*ArcSinh[c + d*x])/(c*e + d*e*x)^3, x, 3, -(b*Sqrt[1 + (c + d*x)^2])/(2*d*e^3*(c + d*x)) - (a + b*ArcSinh[c + d*x])/(2*d*e^3*(c + d*x)^2)}
{(a + b*ArcSinh[c + d*x])/(c*e + d*e*x)^4, x, 5, -(b*Sqrt[1 + (c + d*x)^2])/(6*d*e^4*(c + d*x)^2) - (a + b*ArcSinh[c + d*x])/(3*d*e^4*(c + d*x)^3) + (b*ArcTanh[Sqrt[1 + (c + d*x)^2]])/(6*d*e^4)}
{(a + b*ArcSinh[c + d*x])/(c*e + d*e*x)^5, x, 4, -(b*Sqrt[1 + (c + d*x)^2])/(12*d*e^5*(c + d*x)^3) + (b*Sqrt[1 + (c + d*x)^2])/(6*d*e^5*(c + d*x)) - (a + b*ArcSinh[c + d*x])/(4*d*e^5*(c + d*x)^4)}
{(a + b*ArcSinh[c + d*x])/(c*e + d*e*x)^6, x, 6, -(b*Sqrt[1 + (c + d*x)^2])/(20*d*e^6*(c + d*x)^4) + (3*b*Sqrt[1 + (c + d*x)^2])/(40*d*e^6*(c + d*x)^2) - (a + b*ArcSinh[c + d*x])/(5*d*e^6*(c + d*x)^5) - (3*b*ArcTanh[Sqrt[1 + (c + d*x)^2]])/(40*d*e^6)}


{(c*e + d*e*x)^m*(a + b*ArcSinh[c + d*x])^2, x, 2, ((c*e + d*e*x)^(1 + m)*(a + b*ArcSinh[c + d*x])^2)/(d*e*(1 + m)) - (2*b*(c + d*x)*(c*e + d*e*x)^(1 + m)*(a + b*ArcSinh[c + d*x])*Hypergeometric2F1[1/2, (2 + m)/2, (4 + m)/2, -(c + d*x)^2])/(d*e*(2 + 3*m + m^2)) + (2*b^2*(c + d*x)^2*(c*e + d*e*x)^(1 + m)*HypergeometricPFQ[{1, 3/2 + m/2, 3/2 + m/2}, {2 + m/2, 5/2 + m/2}, -(c + d*x)^2])/(d*e*(1 + m)*(6 + 5*m + m^2))}

{(c*e + d*e*x)^4*(a + b*ArcSinh[c + d*x])^2, x, 7, (16*b^2*e^4*x)/75 - (8*b^2*e^4*(c + d*x)^3)/(225*d) + (2*b^2*e^4*(c + d*x)^5)/(125*d) - (16*b*e^4*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x]))/(75*d) + (8*b*e^4*(c + d*x)^2*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x]))/(75*d) - (2*b*e^4*(c + d*x)^4*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x]))/(25*d) + (e^4*(c + d*x)^5*(a + b*ArcSinh[c + d*x])^2)/(5*d)}
{(c*e + d*e*x)^3*(a + b*ArcSinh[c + d*x])^2, x, 6, (-3*b^2*c*e^3*x)/16 - (3*b^2*d*e^3*x^2)/32 + (b^2*e^3*(c + d*x)^4)/(32*d) + (3*b*e^3*(c + d*x)*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x]))/(16*d) - (b*e^3*(c + d*x)^3*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x]))/(8*d) - (3*e^3*(a + b*ArcSinh[c + d*x])^2)/(32*d) + (e^3*(c + d*x)^4*(a + b*ArcSinh[c + d*x])^2)/(4*d)}
{(c*e + d*e*x)^2*(a + b*ArcSinh[c + d*x])^2, x, 5, (-4*b^2*e^2*x)/9 + (2*b^2*e^2*(c + d*x)^3)/(27*d) + (4*b*e^2*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x]))/(9*d) - (2*b*e^2*(c + d*x)^2*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x]))/(9*d) + (e^2*(c + d*x)^3*(a + b*ArcSinh[c + d*x])^2)/(3*d)}
{(c*e + d*e*x)*(a + b*ArcSinh[c + d*x])^2, x, 4, (b^2*c*e*x)/2 + (b^2*d*e*x^2)/4 - (b*e*(c + d*x)*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x]))/(2*d) + (e*(a + b*ArcSinh[c + d*x])^2)/(4*d) + (e*(c + d*x)^2*(a + b*ArcSinh[c + d*x])^2)/(2*d)}
{(a + b*ArcSinh[c + d*x])^2, x, 2, 2*b^2*x - (2*b*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x]))/d + ((c + d*x)*(a + b*ArcSinh[c + d*x])^2)/d}
{(a + b*ArcSinh[c + d*x])^2/(c*e + d*e*x), x, 6, -(a + b*ArcSinh[c + d*x])^3/(3*b*d*e) + ((a + b*ArcSinh[c + d*x])^2*Log[1 - E^(2*ArcSinh[c + d*x])])/(d*e) + (b*(a + b*ArcSinh[c + d*x])*PolyLog[2, E^(2*ArcSinh[c + d*x])])/(d*e) - (b^2*PolyLog[3, E^(2*ArcSinh[c + d*x])])/(2*d*e)}
{(a + b*ArcSinh[c + d*x])^2/(c*e + d*e*x)^2, x, 6, -((a + b*ArcSinh[c + d*x])^2/(d*e^2*(c + d*x))) - (2*a*b*ArcTanh[Sqrt[1 + (c + d*x)^2]])/(d*e^2) + (4*b^2*ArcSinh[c + d*x]*ArcTanh[c + d*x - Sqrt[1 + (c + d*x)^2]])/(d*e^2) + (2*b^2*PolyLog[2, c + d*x - Sqrt[1 + (c + d*x)^2]])/(d*e^2) - (2*b^2*PolyLog[2, -c - d*x + Sqrt[1 + (c + d*x)^2]])/(d*e^2)}
{(a + b*ArcSinh[c + d*x])^2/(c*e + d*e*x)^3, x, 3, -((b*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x]))/(d*e^3*(c + d*x))) - (a + b*ArcSinh[c + d*x])^2/(2*d*e^3*(c + d*x)^2) + (b^2*Log[c + d*x])/(d*e^3)}
{(a + b*ArcSinh[c + d*x])^2/(c*e + d*e*x)^4, x, 8, -b^2/(3*d*e^4*(c + d*x)) - (b*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x]))/(3*d*e^4*(c + d*x)^2) - (a + b*ArcSinh[c + d*x])^2/(3*d*e^4*(c + d*x)^3) + (a*b*ArcTanh[Sqrt[1 + (c + d*x)^2]])/(3*d*e^4) - (2*b^2*ArcSinh[c + d*x]*ArcTanh[c + d*x - Sqrt[1 + (c + d*x)^2]])/(3*d*e^4) - (b^2*PolyLog[2, c + d*x - Sqrt[1 + (c + d*x)^2]])/(3*d*e^4) + (b^2*PolyLog[2, -c - d*x + Sqrt[1 + (c + d*x)^2]])/(3*d*e^4)}


{(c*e + d*e*x)^m*(a + b*ArcSinh[c + d*x])^3, x, 1, ((c*e + d*e*x)^(1 + m)*(a + b*ArcSinh[c + d*x])^3)/(d*e*(1 + m)) - (3*b*Defer[Int][((c*e + d*e*x)^(1 + m)*(a + b*ArcSinh[c + d*x])^2)/Sqrt[1 + (c + d*x)^2], x])/(e*(1 + m))}

{(c*e + d*e*x)^4*(a + b*ArcSinh[c + d*x])^3, x, 15, (16*a*b^2*e^4*x)/25 - (4144*b^3*e^4*Sqrt[1 + (c + d*x)^2])/(5625*d) + (272*b^3*e^4*(c + d*x)^2*Sqrt[1 + (c + d*x)^2])/(5625*d) - (6*b^3*e^4*(c + d*x)^4*Sqrt[1 + (c + d*x)^2])/(625*d) + (16*b^3*e^4*(c + d*x)*ArcSinh[c + d*x])/(25*d) - (8*b^2*e^4*(c + d*x)^3*(a + b*ArcSinh[c + d*x]))/(75*d) + (6*b^2*e^4*(c + d*x)^5*(a + b*ArcSinh[c + d*x]))/(125*d) - (8*b*e^4*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^2)/(25*d) + (4*b*e^4*(c + d*x)^2*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^2)/(25*d) - (3*b*e^4*(c + d*x)^4*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^2)/(25*d) + (e^4*(c + d*x)^5*(a + b*ArcSinh[c + d*x])^3)/(5*d)}
{(c*e + d*e*x)^3*(a + b*ArcSinh[c + d*x])^3, x, 13, (45*b^3*e^3*(c + d*x)*Sqrt[1 + (c + d*x)^2])/(256*d) - (3*b^3*e^3*(c + d*x)^3*Sqrt[1 + (c + d*x)^2])/(128*d) - (45*b^3*e^3*ArcSinh[c + d*x])/(256*d) - (9*b^2*e^3*(c + d*x)^2*(a + b*ArcSinh[c + d*x]))/(32*d) + (3*b^2*e^3*(c + d*x)^4*(a + b*ArcSinh[c + d*x]))/(32*d) + (9*b*e^3*(c + d*x)*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^2)/(32*d) - (3*b*e^3*(c + d*x)^3*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^2)/(16*d) - (3*e^3*(a + b*ArcSinh[c + d*x])^3)/(32*d) + (e^3*(c + d*x)^4*(a + b*ArcSinh[c + d*x])^3)/(4*d)}
{(c*e + d*e*x)^2*(a + b*ArcSinh[c + d*x])^3, x, 9, (-4*a*b^2*e^2*x)/3 + (40*b^3*e^2*Sqrt[1 + (c + d*x)^2])/(27*d) - (2*b^3*e^2*(c + d*x)^2*Sqrt[1 + (c + d*x)^2])/(27*d) - (4*b^3*e^2*(c + d*x)*ArcSinh[c + d*x])/(3*d) + (2*b^2*e^2*(c + d*x)^3*(a + b*ArcSinh[c + d*x]))/(9*d) + (2*b*e^2*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^2)/(3*d) - (b*e^2*(c + d*x)^2*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^2)/(3*d) + (e^2*(c + d*x)^3*(a + b*ArcSinh[c + d*x])^3)/(3*d)}
{(c*e + d*e*x)*(a + b*ArcSinh[c + d*x])^3, x, 7, (-3*b^3*e*(c + d*x)*Sqrt[1 + (c + d*x)^2])/(8*d) + (3*b^3*e*ArcSinh[c + d*x])/(8*d) + (3*b^2*e*(c + d*x)^2*(a + b*ArcSinh[c + d*x]))/(4*d) - (3*b*e*(c + d*x)*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^2)/(4*d) + (e*(a + b*ArcSinh[c + d*x])^3)/(4*d) + (e*(c + d*x)^2*(a + b*ArcSinh[c + d*x])^3)/(2*d)}
{(a + b*ArcSinh[c + d*x])^3, x, 3, 6*a*b^2*x - (6*b^3*Sqrt[1 + (c + d*x)^2])/d + (6*b^3*(c + d*x)*ArcSinh[c + d*x])/d - (3*b*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^2)/d + ((c + d*x)*(a + b*ArcSinh[c + d*x])^3)/d}
{(a + b*ArcSinh[c + d*x])^3/(c*e + d*e*x), x, 7, -(a + b*ArcSinh[c + d*x])^4/(4*b*d*e) + ((a + b*ArcSinh[c + d*x])^3*Log[1 - E^(2*ArcSinh[c + d*x])])/(d*e) + (3*b*(a + b*ArcSinh[c + d*x])^2*PolyLog[2, E^(2*ArcSinh[c + d*x])])/(2*d*e) - (3*b^2*(a + b*ArcSinh[c + d*x])*PolyLog[3, E^(2*ArcSinh[c + d*x])])/(2*d*e) + (3*b^3*PolyLog[4, E^(2*ArcSinh[c + d*x])])/(4*d*e)}
{(a + b*ArcSinh[c + d*x])^3/(c*e + d*e*x)^2, x, 8, -((a + b*ArcSinh[c + d*x])^3/(d*e^2*(c + d*x))) - (6*b*(a + b*ArcSinh[c + d*x])^2*ArcTanh[E^(a/b - (a + b*ArcSinh[c + d*x])/b)])/(d*e^2) + (6*b^2*(a + b*ArcSinh[c + d*x])*PolyLog[2, -E^(a/b - (a + b*ArcSinh[c + d*x])/b)])/(d*e^2) - (6*b^2*(a + b*ArcSinh[c + d*x])*PolyLog[2, E^(a/b - (a + b*ArcSinh[c + d*x])/b)])/(d*e^2) + (6*b^3*PolyLog[3, -E^(a/b - (a + b*ArcSinh[c + d*x])/b)])/(d*e^2) - (6*b^3*PolyLog[3, E^(a/b - (a + b*ArcSinh[c + d*x])/b)])/(d*e^2)}
{(a + b*ArcSinh[c + d*x])^3/(c*e + d*e*x)^3, x, 7, (-3*b*(a + b*ArcSinh[c + d*x])^2)/(2*d*e^3) - (3*b*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^2)/(2*d*e^3*(c + d*x)) - (a + b*ArcSinh[c + d*x])^3/(2*d*e^3*(c + d*x)^2) + (3*b^2*(a + b*ArcSinh[c + d*x])*Log[1 - E^(2*ArcSinh[c + d*x])])/(d*e^3) + (3*b^3*PolyLog[2, E^(2*ArcSinh[c + d*x])])/(2*d*e^3)}
{(a + b*ArcSinh[c + d*x])^3/(c*e + d*e*x)^4, x, 13, -((b^2*(a + b*ArcSinh[c + d*x]))/(d*e^4*(c + d*x))) - (b*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^2)/(2*d*e^4*(c + d*x)^2) - (a + b*ArcSinh[c + d*x])^3/(3*d*e^4*(c + d*x)^3) + (b*(a + b*ArcSinh[c + d*x])^2*ArcTanh[E^(a/b - (a + b*ArcSinh[c + d*x])/b)])/(d*e^4) - (b^3*ArcTanh[Sqrt[1 + (c + d*x)^2]])/(d*e^4) - (b^2*(a + b*ArcSinh[c + d*x])*PolyLog[2, -E^(a/b - (a + b*ArcSinh[c + d*x])/b)])/(d*e^4) + (b^2*(a + b*ArcSinh[c + d*x])*PolyLog[2, E^(a/b - (a + b*ArcSinh[c + d*x])/b)])/(d*e^4) - (b^3*PolyLog[3, -E^(a/b - (a + b*ArcSinh[c + d*x])/b)])/(d*e^4) + (b^3*PolyLog[3, E^(a/b - (a + b*ArcSinh[c + d*x])/b)])/(d*e^4)}


{(c*e + d*e*x)^m*(a + b*ArcSinh[c + d*x])^4, x, 1, ((c*e + d*e*x)^(1 + m)*(a + b*ArcSinh[c + d*x])^4)/(d*e*(1 + m)) - (4*b*Defer[Int][((c*e + d*e*x)^(1 + m)*(a + b*ArcSinh[c + d*x])^3)/Sqrt[1 + (c + d*x)^2], x])/(e*(1 + m))}

{(c*e + d*e*x)^3*(a + b*ArcSinh[c + d*x])^4, x, 14, (-45*b^4*c*e^3*x)/64 - (45*b^4*d*e^3*x^2)/128 + (3*b^4*e^3*(c + d*x)^4)/(128*d) + (45*b^3*e^3*(c + d*x)*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x]))/(64*d) - (3*b^3*e^3*(c + d*x)^3*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x]))/(32*d) - (45*b^2*e^3*(a + b*ArcSinh[c + d*x])^2)/(128*d) - (9*b^2*e^3*(c + d*x)^2*(a + b*ArcSinh[c + d*x])^2)/(16*d) + (3*b^2*e^3*(c + d*x)^4*(a + b*ArcSinh[c + d*x])^2)/(16*d) + (3*b*e^3*(c + d*x)*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^3)/(8*d) - (b*e^3*(c + d*x)^3*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^3)/(4*d) - (3*e^3*(a + b*ArcSinh[c + d*x])^4)/(32*d) + (e^3*(c + d*x)^4*(a + b*ArcSinh[c + d*x])^4)/(4*d)}
{(c*e + d*e*x)^2*(a + b*ArcSinh[c + d*x])^4, x, 10, (-160*b^4*e^2*x)/27 + (8*b^4*e^2*(c + d*x)^3)/(81*d) + (160*b^3*e^2*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x]))/(27*d) - (8*b^3*e^2*(c + d*x)^2*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x]))/(27*d) - (8*b^2*e^2*(c + d*x)*(a + b*ArcSinh[c + d*x])^2)/(3*d) + (4*b^2*e^2*(c + d*x)^3*(a + b*ArcSinh[c + d*x])^2)/(9*d) + (8*b*e^2*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^3)/(9*d) - (4*b*e^2*(c + d*x)^2*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^3)/(9*d) + (e^2*(c + d*x)^3*(a + b*ArcSinh[c + d*x])^4)/(3*d)}
{(c*e + d*e*x)*(a + b*ArcSinh[c + d*x])^4, x, 7, (3*b^4*c*e*x)/2 + (3*b^4*d*e*x^2)/4 - (3*b^3*e*(c + d*x)*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x]))/(2*d) + (3*b^2*e*(a + b*ArcSinh[c + d*x])^2)/(4*d) + (3*b^2*e*(c + d*x)^2*(a + b*ArcSinh[c + d*x])^2)/(2*d) - (b*e*(c + d*x)*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^3)/d + (e*(a + b*ArcSinh[c + d*x])^4)/(4*d) + (e*(c + d*x)^2*(a + b*ArcSinh[c + d*x])^4)/(2*d)}
{(a + b*ArcSinh[c + d*x])^4, x, 3, 24*b^4*x - (24*b^3*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x]))/d + (12*b^2*(c + d*x)*(a + b*ArcSinh[c + d*x])^2)/d - (4*b*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^3)/d + ((c + d*x)*(a + b*ArcSinh[c + d*x])^4)/d}
{(a + b*ArcSinh[c + d*x])^4/(c*e + d*e*x), x, 8, -(a + b*ArcSinh[c + d*x])^5/(5*b*d*e) + ((a + b*ArcSinh[c + d*x])^4*Log[1 - E^(2*ArcSinh[c + d*x])])/(d*e) + (2*b*(a + b*ArcSinh[c + d*x])^3*PolyLog[2, E^(2*ArcSinh[c + d*x])])/(d*e) - (3*b^2*(a + b*ArcSinh[c + d*x])^2*PolyLog[3, E^(2*ArcSinh[c + d*x])])/(d*e) + (3*b^3*(a + b*ArcSinh[c + d*x])*PolyLog[4, E^(2*ArcSinh[c + d*x])])/(d*e) - (3*b^4*PolyLog[5, E^(2*ArcSinh[c + d*x])])/(2*d*e)}
{(a + b*ArcSinh[c + d*x])^4/(c*e + d*e*x)^2, x, 10, -((a + b*ArcSinh[c + d*x])^4/(d*e^2*(c + d*x))) - (8*b*(a + b*ArcSinh[c + d*x])^3*ArcTanh[E^(a/b - (a + b*ArcSinh[c + d*x])/b)])/(d*e^2) + (12*b^2*(a + b*ArcSinh[c + d*x])^2*PolyLog[2, -E^(a/b - (a + b*ArcSinh[c + d*x])/b)])/(d*e^2) - (12*b^2*(a + b*ArcSinh[c + d*x])^2*PolyLog[2, E^(a/b - (a + b*ArcSinh[c + d*x])/b)])/(d*e^2) + (24*b^3*(a + b*ArcSinh[c + d*x])*PolyLog[3, -E^(a/b - (a + b*ArcSinh[c + d*x])/b)])/(d*e^2) - (24*b^3*(a + b*ArcSinh[c + d*x])*PolyLog[3, E^(a/b - (a + b*ArcSinh[c + d*x])/b)])/(d*e^2) + (24*b^4*PolyLog[4, -E^(a/b - (a + b*ArcSinh[c + d*x])/b)])/(d*e^2) - (24*b^4*PolyLog[4, E^(a/b - (a + b*ArcSinh[c + d*x])/b)])/(d*e^2)}
{(a + b*ArcSinh[c + d*x])^4/(c*e + d*e*x)^3, x, 8, (-2*b*(a + b*ArcSinh[c + d*x])^3)/(d*e^3) - (2*b*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^3)/(d*e^3*(c + d*x)) - (a + b*ArcSinh[c + d*x])^4/(2*d*e^3*(c + d*x)^2) + (6*b^2*(a + b*ArcSinh[c + d*x])^2*Log[1 - E^(2*ArcSinh[c + d*x])])/(d*e^3) + (6*b^3*(a + b*ArcSinh[c + d*x])*PolyLog[2, E^(2*ArcSinh[c + d*x])])/(d*e^3) - (3*b^4*PolyLog[3, E^(2*ArcSinh[c + d*x])])/(d*e^3)}
{(a + b*ArcSinh[c + d*x])^4/(c*e + d*e*x)^4, x, 17, (-2*b^2*(a + b*ArcSinh[c + d*x])^2)/(d*e^4*(c + d*x)) - (2*b*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^3)/(3*d*e^4*(c + d*x)^2) - (a + b*ArcSinh[c + d*x])^4/(3*d*e^4*(c + d*x)^3) + (4*b*(a + b*ArcSinh[c + d*x])^3*ArcTanh[E^(a/b - (a + b*ArcSinh[c + d*x])/b)])/(3*d*e^4) - (4*a*b^3*ArcTanh[Sqrt[1 + (c + d*x)^2]])/(d*e^4) + (8*b^4*ArcSinh[c + d*x]*ArcTanh[c + d*x - Sqrt[1 + (c + d*x)^2]])/(d*e^4) - (2*b^2*(a + b*ArcSinh[c + d*x])^2*PolyLog[2, -E^(a/b - (a + b*ArcSinh[c + d*x])/b)])/(d*e^4) + (2*b^2*(a + b*ArcSinh[c + d*x])^2*PolyLog[2, E^(a/b - (a + b*ArcSinh[c + d*x])/b)])/(d*e^4) + (4*b^4*PolyLog[2, c + d*x - Sqrt[1 + (c + d*x)^2]])/(d*e^4) - (4*b^4*PolyLog[2, -c - d*x + Sqrt[1 + (c + d*x)^2]])/(d*e^4) - (4*b^3*(a + b*ArcSinh[c + d*x])*PolyLog[3, -E^(a/b - (a + b*ArcSinh[c + d*x])/b)])/(d*e^4) + (4*b^3*(a + b*ArcSinh[c + d*x])*PolyLog[3, E^(a/b - (a + b*ArcSinh[c + d*x])/b)])/(d*e^4) - (4*b^4*PolyLog[4, -E^(a/b - (a + b*ArcSinh[c + d*x])/b)])/(d*e^4) + (4*b^4*PolyLog[4, E^(a/b - (a + b*ArcSinh[c + d*x])/b)])/(d*e^4)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(c*e + d*e*x)^m/(a + b*ArcSinh[c + d*x]), x, 1, Defer[Subst][Int[(e*x)^m/(a + b*ArcSinh[x]), x], x, c + d*x]/d}

{(c*e + d*e*x)^4/(a + b*ArcSinh[c + d*x]), x, 12, (e^4*Cosh[a/b]*CoshIntegral[(a + b*ArcSinh[c + d*x])/b])/(8*b*d) - (3*e^4*Cosh[(3*a)/b]*CoshIntegral[(3*(a + b*ArcSinh[c + d*x]))/b])/(16*b*d) + (e^4*Cosh[(5*a)/b]*CoshIntegral[(5*(a + b*ArcSinh[c + d*x]))/b])/(16*b*d) - (e^4*Sinh[a/b]*SinhIntegral[(a + b*ArcSinh[c + d*x])/b])/(8*b*d) + (3*e^4*Sinh[(3*a)/b]*SinhIntegral[(3*(a + b*ArcSinh[c + d*x]))/b])/(16*b*d) - (e^4*Sinh[(5*a)/b]*SinhIntegral[(5*(a + b*ArcSinh[c + d*x]))/b])/(16*b*d)}
{(c*e + d*e*x)^3/(a + b*ArcSinh[c + d*x]), x, 9, (e^3*CoshIntegral[(2*(a + b*ArcSinh[c + d*x]))/b]*Sinh[(2*a)/b])/(4*b*d) - (e^3*CoshIntegral[(4*(a + b*ArcSinh[c + d*x]))/b]*Sinh[(4*a)/b])/(8*b*d) - (e^3*Cosh[(2*a)/b]*SinhIntegral[(2*(a + b*ArcSinh[c + d*x]))/b])/(4*b*d) + (e^3*Cosh[(4*a)/b]*SinhIntegral[(4*(a + b*ArcSinh[c + d*x]))/b])/(8*b*d)}
{(c*e + d*e*x)^2/(a + b*ArcSinh[c + d*x]), x, 9, -(e^2*Cosh[a/b]*CoshIntegral[(a + b*ArcSinh[c + d*x])/b])/(4*b*d) + (e^2*Cosh[(3*a)/b]*CoshIntegral[(3*(a + b*ArcSinh[c + d*x]))/b])/(4*b*d) + (e^2*Sinh[a/b]*SinhIntegral[(a + b*ArcSinh[c + d*x])/b])/(4*b*d) - (e^2*Sinh[(3*a)/b]*SinhIntegral[(3*(a + b*ArcSinh[c + d*x]))/b])/(4*b*d)}
{(c*e + d*e*x)/(a + b*ArcSinh[c + d*x]), x, 6, -(e*CoshIntegral[(2*(a + b*ArcSinh[c + d*x]))/b]*Sinh[(2*a)/b])/(2*b*d) + (e*Cosh[(2*a)/b]*SinhIntegral[(2*(a + b*ArcSinh[c + d*x]))/b])/(2*b*d)}
{1/(a + b*ArcSinh[c + d*x]), x, 4, (Cosh[a/b]*CoshIntegral[(a + b*ArcSinh[c + d*x])/b])/(b*d) - (Sinh[a/b]*SinhIntegral[(a + b*ArcSinh[c + d*x])/b])/(b*d)}
{1/((c*e + d*e*x)*(a + b*ArcSinh[c + d*x])), x, 0, Defer[Int][1/((c*e + d*e*x)*(a + b*ArcSinh[c + d*x])), x]}


{(c*e + d*e*x)^4/(a + b*ArcSinh[c + d*x])^2, x, 11, -((e^4*(c + d*x)^4*Sqrt[1 + (c + d*x)^2])/(b*d*(a + b*ArcSinh[c + d*x]))) - (e^4*CoshIntegral[(a + b*ArcSinh[c + d*x])/b]*Sinh[a/b])/(8*b^2*d) + (9*e^4*CoshIntegral[(3*(a + b*ArcSinh[c + d*x]))/b]*Sinh[(3*a)/b])/(16*b^2*d) - (5*e^4*CoshIntegral[(5*(a + b*ArcSinh[c + d*x]))/b]*Sinh[(5*a)/b])/(16*b^2*d) + (e^4*Cosh[a/b]*SinhIntegral[(a + b*ArcSinh[c + d*x])/b])/(8*b^2*d) - (9*e^4*Cosh[(3*a)/b]*SinhIntegral[(3*(a + b*ArcSinh[c + d*x]))/b])/(16*b^2*d) + (5*e^4*Cosh[(5*a)/b]*SinhIntegral[(5*(a + b*ArcSinh[c + d*x]))/b])/(16*b^2*d)}
{(c*e + d*e*x)^3/(a + b*ArcSinh[c + d*x])^2, x, 8, -((e^3*(c + d*x)^3*Sqrt[1 + (c + d*x)^2])/(b*d*(a + b*ArcSinh[c + d*x]))) - (e^3*Cosh[(2*a)/b]*CoshIntegral[(2*(a + b*ArcSinh[c + d*x]))/b])/(2*b^2*d) + (e^3*Cosh[(4*a)/b]*CoshIntegral[(4*(a + b*ArcSinh[c + d*x]))/b])/(2*b^2*d) + (e^3*Sinh[(2*a)/b]*SinhIntegral[(2*(a + b*ArcSinh[c + d*x]))/b])/(2*b^2*d) - (e^3*Sinh[(4*a)/b]*SinhIntegral[(4*(a + b*ArcSinh[c + d*x]))/b])/(2*b^2*d)}
{(c*e + d*e*x)^2/(a + b*ArcSinh[c + d*x])^2, x, 8, -((e^2*(c + d*x)^2*Sqrt[1 + (c + d*x)^2])/(b*d*(a + b*ArcSinh[c + d*x]))) + (e^2*CoshIntegral[(a + b*ArcSinh[c + d*x])/b]*Sinh[a/b])/(4*b^2*d) - (3*e^2*CoshIntegral[(3*(a + b*ArcSinh[c + d*x]))/b]*Sinh[(3*a)/b])/(4*b^2*d) - (e^2*Cosh[a/b]*SinhIntegral[(a + b*ArcSinh[c + d*x])/b])/(4*b^2*d) + (3*e^2*Cosh[(3*a)/b]*SinhIntegral[(3*(a + b*ArcSinh[c + d*x]))/b])/(4*b^2*d)}
{(c*e + d*e*x)/(a + b*ArcSinh[c + d*x])^2, x, 4, -((e*(c + d*x)*Sqrt[1 + (c + d*x)^2])/(b*d*(a + b*ArcSinh[c + d*x]))) + (e*Cosh[(2*a)/b]*CoshIntegral[(2*(a + b*ArcSinh[c + d*x]))/b])/(b^2*d) - (e*Sinh[(2*a)/b]*SinhIntegral[(2*(a + b*ArcSinh[c + d*x]))/b])/(b^2*d)}
{(a + b*ArcSinh[c + d*x])^(-2), x, 6, -(Sqrt[1 + (c + d*x)^2]/(b*d*(a + b*ArcSinh[c + d*x]))) - (CoshIntegral[(a + b*ArcSinh[c + d*x])/b]*Sinh[a/b])/(b^2*d) + (Cosh[a/b]*SinhIntegral[(a + b*ArcSinh[c + d*x])/b])/(b^2*d)}
{1/((c*e + d*e*x)*(a + b*ArcSinh[c + d*x])^2), x, 0, Defer[Int][1/((c*e + d*e*x)*(a + b*ArcSinh[c + d*x])^2), x]}


{(c*e + d*e*x)^4/(a + b*ArcSinh[c + d*x])^3, x, 22, -(e^4*(c + d*x)^4*Sqrt[1 + (c + d*x)^2])/(2*b*d*(a + b*ArcSinh[c + d*x])^2) - (2*e^4*(c + d*x)^3)/(b^2*d*(a + b*ArcSinh[c + d*x])) - (5*e^4*(c + d*x)^5)/(2*b^2*d*(a + b*ArcSinh[c + d*x])) + (e^4*Cosh[a/b]*CoshIntegral[(a + b*ArcSinh[c + d*x])/b])/(16*b^3*d) - (27*e^4*Cosh[(3*a)/b]*CoshIntegral[(3*(a + b*ArcSinh[c + d*x]))/b])/(32*b^3*d) + (25*e^4*Cosh[(5*a)/b]*CoshIntegral[(5*(a + b*ArcSinh[c + d*x]))/b])/(32*b^3*d) - (e^4*Sinh[a/b]*SinhIntegral[(a + b*ArcSinh[c + d*x])/b])/(16*b^3*d) + (27*e^4*Sinh[(3*a)/b]*SinhIntegral[(3*(a + b*ArcSinh[c + d*x]))/b])/(32*b^3*d) - (25*e^4*Sinh[(5*a)/b]*SinhIntegral[(5*(a + b*ArcSinh[c + d*x]))/b])/(32*b^3*d)}
{(c*e + d*e*x)^3/(a + b*ArcSinh[c + d*x])^3, x, 16, -(e^3*(c + d*x)^3*Sqrt[1 + (c + d*x)^2])/(2*b*d*(a + b*ArcSinh[c + d*x])^2) - (3*e^3*(c + d*x)^2)/(2*b^2*d*(a + b*ArcSinh[c + d*x])) - (2*e^3*(c + d*x)^4)/(b^2*d*(a + b*ArcSinh[c + d*x])) + (e^3*CoshIntegral[(2*(a + b*ArcSinh[c + d*x]))/b]*Sinh[(2*a)/b])/(2*b^3*d) - (e^3*CoshIntegral[(4*(a + b*ArcSinh[c + d*x]))/b]*Sinh[(4*a)/b])/(b^3*d) - (e^3*Cosh[(2*a)/b]*SinhIntegral[(2*(a + b*ArcSinh[c + d*x]))/b])/(2*b^3*d) + (e^3*Cosh[(4*a)/b]*SinhIntegral[(4*(a + b*ArcSinh[c + d*x]))/b])/(b^3*d)}
{(c*e + d*e*x)^2/(a + b*ArcSinh[c + d*x])^3, x, 14, -(e^2*(c + d*x)^2*Sqrt[1 + (c + d*x)^2])/(2*b*d*(a + b*ArcSinh[c + d*x])^2) - (e^2*(c + d*x))/(b^2*d*(a + b*ArcSinh[c + d*x])) - (3*e^2*(c + d*x)^3)/(2*b^2*d*(a + b*ArcSinh[c + d*x])) - (e^2*Cosh[a/b]*CoshIntegral[(a + b*ArcSinh[c + d*x])/b])/(8*b^3*d) + (9*e^2*Cosh[(3*a)/b]*CoshIntegral[(3*(a + b*ArcSinh[c + d*x]))/b])/(8*b^3*d) + (e^2*Sinh[a/b]*SinhIntegral[(a + b*ArcSinh[c + d*x])/b])/(8*b^3*d) - (9*e^2*Sinh[(3*a)/b]*SinhIntegral[(3*(a + b*ArcSinh[c + d*x]))/b])/(8*b^3*d)}
{(c*e + d*e*x)/(a + b*ArcSinh[c + d*x])^3, x, 8, -(e*(c + d*x)*Sqrt[1 + (c + d*x)^2])/(2*b*d*(a + b*ArcSinh[c + d*x])^2) - e/(2*b^2*d*(a + b*ArcSinh[c + d*x])) - (e*(c + d*x)^2)/(b^2*d*(a + b*ArcSinh[c + d*x])) - (e*CoshIntegral[(2*(a + b*ArcSinh[c + d*x]))/b]*Sinh[(2*a)/b])/(b^3*d) + (e*Cosh[(2*a)/b]*SinhIntegral[(2*(a + b*ArcSinh[c + d*x]))/b])/(b^3*d)}
{(a + b*ArcSinh[c + d*x])^(-3), x, 5, -Sqrt[1 + (c + d*x)^2]/(2*b*d*(a + b*ArcSinh[c + d*x])^2) - (c + d*x)/(2*b^2*d*(a + b*ArcSinh[c + d*x])) + (Cosh[a/b]*CoshIntegral[(a + b*ArcSinh[c + d*x])/b])/(2*b^3*d) - (Sinh[a/b]*SinhIntegral[(a + b*ArcSinh[c + d*x])/b])/(2*b^3*d)}
{1/((c*e + d*e*x)*(a + b*ArcSinh[c + d*x])^3), x, 0, Defer[Int][1/((c*e + d*e*x)*(a + b*ArcSinh[c + d*x])^3), x]}


{(c*e + d*e*x)^4/(a + b*ArcSinh[c + d*x])^4, x, 20, -(e^4*(c + d*x)^4*Sqrt[1 + (c + d*x)^2])/(3*b*d*(a + b*ArcSinh[c + d*x])^3) - (2*e^4*(c + d*x)^3)/(3*b^2*d*(a + b*ArcSinh[c + d*x])^2) - (5*e^4*(c + d*x)^5)/(6*b^2*d*(a + b*ArcSinh[c + d*x])^2) - (2*e^4*(c + d*x)^2*Sqrt[1 + (c + d*x)^2])/(b^3*d*(a + b*ArcSinh[c + d*x])) - (25*e^4*(c + d*x)^4*Sqrt[1 + (c + d*x)^2])/(6*b^3*d*(a + b*ArcSinh[c + d*x])) - (e^4*CoshIntegral[(a + b*ArcSinh[c + d*x])/b]*Sinh[a/b])/(48*b^4*d) + (27*e^4*CoshIntegral[(3*(a + b*ArcSinh[c + d*x]))/b]*Sinh[(3*a)/b])/(32*b^4*d) - (125*e^4*CoshIntegral[(5*(a + b*ArcSinh[c + d*x]))/b]*Sinh[(5*a)/b])/(96*b^4*d) + (e^4*Cosh[a/b]*SinhIntegral[(a + b*ArcSinh[c + d*x])/b])/(48*b^4*d) - (27*e^4*Cosh[(3*a)/b]*SinhIntegral[(3*(a + b*ArcSinh[c + d*x]))/b])/(32*b^4*d) + (125*e^4*Cosh[(5*a)/b]*SinhIntegral[(5*(a + b*ArcSinh[c + d*x]))/b])/(96*b^4*d)}
{(c*e + d*e*x)^3/(a + b*ArcSinh[c + d*x])^4, x, 13, -(e^3*(c + d*x)^3*Sqrt[1 + (c + d*x)^2])/(3*b*d*(a + b*ArcSinh[c + d*x])^3) - (e^3*(c + d*x)^2)/(2*b^2*d*(a + b*ArcSinh[c + d*x])^2) - (2*e^3*(c + d*x)^4)/(3*b^2*d*(a + b*ArcSinh[c + d*x])^2) - (e^3*(c + d*x)*Sqrt[1 + (c + d*x)^2])/(b^3*d*(a + b*ArcSinh[c + d*x])) - (8*e^3*(c + d*x)^3*Sqrt[1 + (c + d*x)^2])/(3*b^3*d*(a + b*ArcSinh[c + d*x])) - (e^3*Cosh[(2*a)/b]*CoshIntegral[(2*(a + b*ArcSinh[c + d*x]))/b])/(3*b^4*d) + (4*e^3*Cosh[(4*a)/b]*CoshIntegral[(4*(a + b*ArcSinh[c + d*x]))/b])/(3*b^4*d) + (e^3*Sinh[(2*a)/b]*SinhIntegral[(2*(a + b*ArcSinh[c + d*x]))/b])/(3*b^4*d) - (4*e^3*Sinh[(4*a)/b]*SinhIntegral[(4*(a + b*ArcSinh[c + d*x]))/b])/(3*b^4*d)}
{(c*e + d*e*x)^2/(a + b*ArcSinh[c + d*x])^4, x, 15, -(e^2*(c + d*x)^2*Sqrt[1 + (c + d*x)^2])/(3*b*d*(a + b*ArcSinh[c + d*x])^3) - (e^2*(c + d*x))/(3*b^2*d*(a + b*ArcSinh[c + d*x])^2) - (e^2*(c + d*x)^3)/(2*b^2*d*(a + b*ArcSinh[c + d*x])^2) - (e^2*Sqrt[1 + (c + d*x)^2])/(3*b^3*d*(a + b*ArcSinh[c + d*x])) - (3*e^2*(c + d*x)^2*Sqrt[1 + (c + d*x)^2])/(2*b^3*d*(a + b*ArcSinh[c + d*x])) + (e^2*CoshIntegral[(a + b*ArcSinh[c + d*x])/b]*Sinh[a/b])/(24*b^4*d) - (9*e^2*CoshIntegral[(3*(a + b*ArcSinh[c + d*x]))/b]*Sinh[(3*a)/b])/(8*b^4*d) - (e^2*Cosh[a/b]*SinhIntegral[(a + b*ArcSinh[c + d*x])/b])/(24*b^4*d) + (9*e^2*Cosh[(3*a)/b]*SinhIntegral[(3*(a + b*ArcSinh[c + d*x]))/b])/(8*b^4*d)}
{(c*e + d*e*x)/(a + b*ArcSinh[c + d*x])^4, x, 6, -(e*(c + d*x)*Sqrt[1 + (c + d*x)^2])/(3*b*d*(a + b*ArcSinh[c + d*x])^3) - e/(6*b^2*d*(a + b*ArcSinh[c + d*x])^2) - (e*(c + d*x)^2)/(3*b^2*d*(a + b*ArcSinh[c + d*x])^2) - (2*e*(c + d*x)*Sqrt[1 + (c + d*x)^2])/(3*b^3*d*(a + b*ArcSinh[c + d*x])) + (2*e*Cosh[(2*a)/b]*CoshIntegral[(2*(a + b*ArcSinh[c + d*x]))/b])/(3*b^4*d) - (2*e*Sinh[(2*a)/b]*SinhIntegral[(2*(a + b*ArcSinh[c + d*x]))/b])/(3*b^4*d)}
{(a + b*ArcSinh[c + d*x])^(-4), x, 7, -Sqrt[1 + (c + d*x)^2]/(3*b*d*(a + b*ArcSinh[c + d*x])^3) - (c + d*x)/(6*b^2*d*(a + b*ArcSinh[c + d*x])^2) - Sqrt[1 + (c + d*x)^2]/(6*b^3*d*(a + b*ArcSinh[c + d*x])) - (CoshIntegral[(a + b*ArcSinh[c + d*x])/b]*Sinh[a/b])/(6*b^4*d) + (Cosh[a/b]*SinhIntegral[(a + b*ArcSinh[c + d*x])/b])/(6*b^4*d)}
{1/((c*e + d*e*x)*(a + b*ArcSinh[c + d*x])^4), x, 0, Defer[Int][1/((c*e + d*e*x)*(a + b*ArcSinh[c + d*x])^4), x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c e+d e x)^m (a+b ArcSinh[c+d x])^(n/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{(c*e + d*e*x)^4*Sqrt[a + b*ArcSinh[c + d*x]], x, 14, (e^4*(c + d*x)^5*Sqrt[a + b*ArcSinh[c + d*x]])/(5*d) + (Sqrt[b]*e^4*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(32*d) - (Sqrt[b]*e^4*E^((3*a)/b)*Sqrt[Pi/3]*Erf[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(64*d) + (Sqrt[b]*e^4*E^((5*a)/b)*Sqrt[Pi/5]*Erf[(Sqrt[5]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(320*d) - (Sqrt[b]*e^4*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(32*d*E^(a/b)) + (Sqrt[b]*e^4*Sqrt[Pi/3]*Erfi[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(64*d*E^((3*a)/b)) - (Sqrt[b]*e^4*Sqrt[Pi/5]*Erfi[(Sqrt[5]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(320*d*E^((5*a)/b))}
{(c*e + d*e*x)^3*Sqrt[a + b*ArcSinh[c + d*x]], x, 11, (-3*e^3*Sqrt[a + b*ArcSinh[c + d*x]])/(32*d) + (e^3*(c + d*x)^4*Sqrt[a + b*ArcSinh[c + d*x]])/(4*d) - (Sqrt[b]*e^3*E^((4*a)/b)*Sqrt[Pi]*Erf[(2*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(256*d) + (Sqrt[b]*e^3*E^((2*a)/b)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(32*d) - (Sqrt[b]*e^3*Sqrt[Pi]*Erfi[(2*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(256*d*E^((4*a)/b)) + (Sqrt[b]*e^3*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(32*d*E^((2*a)/b))}
{(c*e + d*e*x)^2*Sqrt[a + b*ArcSinh[c + d*x]], x, 11, (e^2*(c + d*x)^3*Sqrt[a + b*ArcSinh[c + d*x]])/(3*d) - (Sqrt[b]*e^2*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(16*d) + (Sqrt[b]*e^2*E^((3*a)/b)*Sqrt[Pi/3]*Erf[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(48*d) + (Sqrt[b]*e^2*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(16*d*E^(a/b)) - (Sqrt[b]*e^2*Sqrt[Pi/3]*Erfi[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(48*d*E^((3*a)/b))}
{(c*e + d*e*x)*Sqrt[a + b*ArcSinh[c + d*x]], x, 8, (e*Sqrt[a + b*ArcSinh[c + d*x]])/(4*d) + (e*(c + d*x)^2*Sqrt[a + b*ArcSinh[c + d*x]])/(2*d) - (Sqrt[b]*e*E^((2*a)/b)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(16*d) - (Sqrt[b]*e*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(16*d*E^((2*a)/b))}
{Sqrt[a + b*ArcSinh[c + d*x]], x, 6, ((c + d*x)*Sqrt[a + b*ArcSinh[c + d*x]])/d + (Sqrt[b]*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(4*d) - (Sqrt[b]*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(4*d*E^(a/b))}
{1/(c*e + d*e*x)*Sqrt[a + b*ArcSinh[c + d*x]], x, 0, Defer[Int][Sqrt[a + b*ArcSinh[c + d*x]]/(c*e + d*e*x), x]}


{(c*e + d*e*x)^4*(a + b*ArcSinh[c + d*x])^(3/2), x, 33, (-4*b*e^4*Sqrt[1 + (c + d*x)^2]*Sqrt[a + b*ArcSinh[c + d*x]])/(25*d) + (2*b*e^4*(c + d*x)^2*Sqrt[1 + (c + d*x)^2]*Sqrt[a + b*ArcSinh[c + d*x]])/(25*d) - (3*b*e^4*(c + d*x)^4*Sqrt[1 + (c + d*x)^2]*Sqrt[a + b*ArcSinh[c + d*x]])/(50*d) + (e^4*(c + d*x)^5*(a + b*ArcSinh[c + d*x])^(3/2))/(5*d) + (3*b^(3/2)*e^4*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(64*d) - (b^(3/2)*e^4*E^((3*a)/b)*Sqrt[Pi/3]*Erf[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(200*d) - (3*b^(3/2)*e^4*E^((3*a)/b)*Sqrt[3*Pi]*Erf[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(3200*d) + (3*b^(3/2)*e^4*E^((5*a)/b)*Sqrt[Pi/5]*Erf[(Sqrt[5]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(3200*d) + (3*b^(3/2)*e^4*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(64*d*E^(a/b)) - (b^(3/2)*e^4*Sqrt[Pi/3]*Erfi[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(200*d*E^((3*a)/b)) - (3*b^(3/2)*e^4*Sqrt[3*Pi]*Erfi[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(3200*d*E^((3*a)/b)) + (3*b^(3/2)*e^4*Sqrt[Pi/5]*Erfi[(Sqrt[5]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(3200*d*E^((5*a)/b))}
{(c*e + d*e*x)^3*(a + b*ArcSinh[c + d*x])^(3/2), x, 20, (9*b*e^3*(c + d*x)*Sqrt[1 + (c + d*x)^2]*Sqrt[a + b*ArcSinh[c + d*x]])/(64*d) - (3*b*e^3*(c + d*x)^3*Sqrt[1 + (c + d*x)^2]*Sqrt[a + b*ArcSinh[c + d*x]])/(32*d) - (3*e^3*(a + b*ArcSinh[c + d*x])^(3/2))/(32*d) + (e^3*(c + d*x)^4*(a + b*ArcSinh[c + d*x])^(3/2))/(4*d) - (3*b^(3/2)*e^3*E^((4*a)/b)*Sqrt[Pi]*Erf[(2*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(2048*d) + (3*b^(3/2)*e^3*E^((2*a)/b)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(128*d) + (3*b^(3/2)*e^3*Sqrt[Pi]*Erfi[(2*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(2048*d*E^((4*a)/b)) - (3*b^(3/2)*e^3*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(128*d*E^((2*a)/b))}
{(c*e + d*e*x)^2*(a + b*ArcSinh[c + d*x])^(3/2), x, 19, (b*e^2*Sqrt[1 + (c + d*x)^2]*Sqrt[a + b*ArcSinh[c + d*x]])/(3*d) - (b*e^2*(c + d*x)^2*Sqrt[1 + (c + d*x)^2]*Sqrt[a + b*ArcSinh[c + d*x]])/(6*d) + (e^2*(c + d*x)^3*(a + b*ArcSinh[c + d*x])^(3/2))/(3*d) - (3*b^(3/2)*e^2*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(32*d) + (b^(3/2)*e^2*E^((3*a)/b)*Sqrt[Pi/3]*Erf[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(96*d) - (3*b^(3/2)*e^2*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(32*d*E^(a/b)) + (b^(3/2)*e^2*Sqrt[Pi/3]*Erfi[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(96*d*E^((3*a)/b))}
{(c*e + d*e*x)*(a + b*ArcSinh[c + d*x])^(3/2), x, 9, (-3*b*e*(c + d*x)*Sqrt[1 + (c + d*x)^2]*Sqrt[a + b*ArcSinh[c + d*x]])/(8*d) + (e*(a + b*ArcSinh[c + d*x])^(3/2))/(4*d) + (e*(c + d*x)^2*(a + b*ArcSinh[c + d*x])^(3/2))/(2*d) - (3*b^(3/2)*e*E^((2*a)/b)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(64*d) + (3*b^(3/2)*e*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(64*d*E^((2*a)/b))}
{(a + b*ArcSinh[c + d*x])^(3/2), x, 7, (-3*b*Sqrt[1 + (c + d*x)^2]*Sqrt[a + b*ArcSinh[c + d*x]])/(2*d) + ((c + d*x)*(a + b*ArcSinh[c + d*x])^(3/2))/d + (3*b^(3/2)*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(8*d) + (3*b^(3/2)*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(8*d*E^(a/b))}
{1/(c*e + d*e*x)*(a + b*ArcSinh[c + d*x])^(3/2), x, 0, Defer[Int][(a + b*ArcSinh[c + d*x])^(3/2)/(c*e + d*e*x), x]}


{(c*e + d*e*x)^4*(a + b*ArcSinh[c + d*x])^(5/2), x, 35, (2*b^2*e^4*(c + d*x)*Sqrt[a + b*ArcSinh[c + d*x]])/(5*d) - (b^2*e^4*(c + d*x)^3*Sqrt[a + b*ArcSinh[c + d*x]])/(15*d) + (3*b^2*e^4*(c + d*x)^5*Sqrt[a + b*ArcSinh[c + d*x]])/(100*d) - (4*b*e^4*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^(3/2))/(15*d) + (2*b*e^4*(c + d*x)^2*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^(3/2))/(15*d) - (b*e^4*(c + d*x)^4*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^(3/2))/(10*d) + (e^4*(c + d*x)^5*(a + b*ArcSinh[c + d*x])^(5/2))/(5*d) + (15*b^(5/2)*e^4*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(128*d) - (b^(5/2)*e^4*E^((3*a)/b)*Sqrt[Pi/3]*Erf[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(240*d) - (b^(5/2)*e^4*E^((3*a)/b)*Sqrt[3*Pi]*Erf[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(1280*d) + (3*b^(5/2)*e^4*E^((5*a)/b)*Sqrt[Pi/5]*Erf[(Sqrt[5]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(6400*d) - (15*b^(5/2)*e^4*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(128*d*E^(a/b)) + (b^(5/2)*e^4*Sqrt[Pi/3]*Erfi[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(240*d*E^((3*a)/b)) + (b^(5/2)*e^4*Sqrt[3*Pi]*Erfi[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(1280*d*E^((3*a)/b)) - (3*b^(5/2)*e^4*Sqrt[Pi/5]*Erfi[(Sqrt[5]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(6400*d*E^((5*a)/b))}
{(c*e + d*e*x)^3*(a + b*ArcSinh[c + d*x])^(5/2), x, 23, (-225*b^2*e^3*Sqrt[a + b*ArcSinh[c + d*x]])/(2048*d) - (45*b^2*e^3*(c + d*x)^2*Sqrt[a + b*ArcSinh[c + d*x]])/(256*d) + (15*b^2*e^3*(c + d*x)^4*Sqrt[a + b*ArcSinh[c + d*x]])/(256*d) + (15*b*e^3*(c + d*x)*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^(3/2))/(64*d) - (5*b*e^3*(c + d*x)^3*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^(3/2))/(32*d) - (3*e^3*(a + b*ArcSinh[c + d*x])^(5/2))/(32*d) + (e^3*(c + d*x)^4*(a + b*ArcSinh[c + d*x])^(5/2))/(4*d) - (15*b^(5/2)*e^3*E^((4*a)/b)*Sqrt[Pi]*Erf[(2*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(16384*d) + (15*b^(5/2)*e^3*E^((2*a)/b)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(512*d) - (15*b^(5/2)*e^3*Sqrt[Pi]*Erfi[(2*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(16384*d*E^((4*a)/b)) + (15*b^(5/2)*e^3*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(512*d*E^((2*a)/b))}
{(c*e + d*e*x)^2*(a + b*ArcSinh[c + d*x])^(5/2), x, 20, (-5*b^2*e^2*(c + d*x)*Sqrt[a + b*ArcSinh[c + d*x]])/(6*d) + (5*b^2*e^2*(c + d*x)^3*Sqrt[a + b*ArcSinh[c + d*x]])/(36*d) + (5*b*e^2*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^(3/2))/(9*d) - (5*b*e^2*(c + d*x)^2*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^(3/2))/(18*d) + (e^2*(c + d*x)^3*(a + b*ArcSinh[c + d*x])^(5/2))/(3*d) - (15*b^(5/2)*e^2*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(64*d) + (5*b^(5/2)*e^2*E^((3*a)/b)*Sqrt[Pi/3]*Erf[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(576*d) + (15*b^(5/2)*e^2*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(64*d*E^(a/b)) - (5*b^(5/2)*e^2*Sqrt[Pi/3]*Erfi[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(576*d*E^((3*a)/b))}
{(c*e + d*e*x)*(a + b*ArcSinh[c + d*x])^(5/2), x, 11, (15*b^2*e*Sqrt[a + b*ArcSinh[c + d*x]])/(64*d) + (15*b^2*e*(c + d*x)^2*Sqrt[a + b*ArcSinh[c + d*x]])/(32*d) - (5*b*e*(c + d*x)*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^(3/2))/(8*d) + (e*(a + b*ArcSinh[c + d*x])^(5/2))/(4*d) + (e*(c + d*x)^2*(a + b*ArcSinh[c + d*x])^(5/2))/(2*d) - (15*b^(5/2)*e*E^((2*a)/b)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(256*d) - (15*b^(5/2)*e*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(256*d*E^((2*a)/b))}
{(a + b*ArcSinh[c + d*x])^(5/2), x, 7, (15*b^2*(c + d*x)*Sqrt[a + b*ArcSinh[c + d*x]])/(4*d) - (5*b*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^(3/2))/(2*d) + ((c + d*x)*(a + b*ArcSinh[c + d*x])^(5/2))/d + (15*b^(5/2)*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(16*d) - (15*b^(5/2)*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(16*d*E^(a/b))}
{1/(c*e + d*e*x)*(a + b*ArcSinh[c + d*x])^(5/2), x, 0, Defer[Int][(a + b*ArcSinh[c + d*x])^(5/2)/(c*e + d*e*x), x]}


{(c*e + d*e*x)^4*(a + b*ArcSinh[c + d*x])^(7/2), x, 63, (-1813*b^3*e^4*Sqrt[1 + (c + d*x)^2]*Sqrt[a + b*ArcSinh[c + d*x]])/(1125*d) + (119*b^3*e^4*(c + d*x)^2*Sqrt[1 + (c + d*x)^2]*Sqrt[a + b*ArcSinh[c + d*x]])/(1125*d) - (21*b^3*e^4*(c + d*x)^4*Sqrt[1 + (c + d*x)^2]*Sqrt[a + b*ArcSinh[c + d*x]])/(1000*d) + (14*b^2*e^4*(c + d*x)*(a + b*ArcSinh[c + d*x])^(3/2))/(15*d) - (7*b^2*e^4*(c + d*x)^3*(a + b*ArcSinh[c + d*x])^(3/2))/(45*d) + (7*b^2*e^4*(c + d*x)^5*(a + b*ArcSinh[c + d*x])^(3/2))/(100*d) - (28*b*e^4*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^(5/2))/(75*d) + (14*b*e^4*(c + d*x)^2*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^(5/2))/(75*d) - (7*b*e^4*(c + d*x)^4*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^(5/2))/(50*d) + (e^4*(c + d*x)^5*(a + b*ArcSinh[c + d*x])^(7/2))/(5*d) + (105*b^(7/2)*e^4*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(256*d) - (119*b^(7/2)*e^4*E^((3*a)/b)*Sqrt[Pi/3]*Erf[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(18000*d) - (21*b^(7/2)*e^4*E^((3*a)/b)*Sqrt[3*Pi]*Erf[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(64000*d) + (21*b^(7/2)*e^4*E^((5*a)/b)*Sqrt[Pi/5]*Erf[(Sqrt[5]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(64000*d) + (105*b^(7/2)*e^4*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(256*d*E^(a/b)) - (119*b^(7/2)*e^4*Sqrt[Pi/3]*Erfi[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(18000*d*E^((3*a)/b)) - (21*b^(7/2)*e^4*Sqrt[3*Pi]*Erfi[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(64000*d*E^((3*a)/b)) + (21*b^(7/2)*e^4*Sqrt[Pi/5]*Erfi[(Sqrt[5]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(64000*d*E^((5*a)/b))}
{(c*e + d*e*x)^3*(a + b*ArcSinh[c + d*x])^(7/2), x, 33, (1575*b^3*e^3*(c + d*x)*Sqrt[1 + (c + d*x)^2]*Sqrt[a + b*ArcSinh[c + d*x]])/(4096*d) - (105*b^3*e^3*(c + d*x)^3*Sqrt[1 + (c + d*x)^2]*Sqrt[a + b*ArcSinh[c + d*x]])/(2048*d) - (525*b^2*e^3*(a + b*ArcSinh[c + d*x])^(3/2))/(2048*d) - (105*b^2*e^3*(c + d*x)^2*(a + b*ArcSinh[c + d*x])^(3/2))/(256*d) + (35*b^2*e^3*(c + d*x)^4*(a + b*ArcSinh[c + d*x])^(3/2))/(256*d) + (21*b*e^3*(c + d*x)*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^(5/2))/(64*d) - (7*b*e^3*(c + d*x)^3*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^(5/2))/(32*d) - (3*e^3*(a + b*ArcSinh[c + d*x])^(7/2))/(32*d) + (e^3*(c + d*x)^4*(a + b*ArcSinh[c + d*x])^(7/2))/(4*d) - (105*b^(7/2)*e^3*E^((4*a)/b)*Sqrt[Pi]*Erf[(2*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(131072*d) + (105*b^(7/2)*e^3*E^((2*a)/b)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(2048*d) + (105*b^(7/2)*e^3*Sqrt[Pi]*Erfi[(2*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(131072*d*E^((4*a)/b)) - (105*b^(7/2)*e^3*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(2048*d*E^((2*a)/b))}
{(c*e + d*e*x)^2*(a + b*ArcSinh[c + d*x])^(7/2), x, 29, (175*b^3*e^2*Sqrt[1 + (c + d*x)^2]*Sqrt[a + b*ArcSinh[c + d*x]])/(54*d) - (35*b^3*e^2*(c + d*x)^2*Sqrt[1 + (c + d*x)^2]*Sqrt[a + b*ArcSinh[c + d*x]])/(216*d) - (35*b^2*e^2*(c + d*x)*(a + b*ArcSinh[c + d*x])^(3/2))/(18*d) + (35*b^2*e^2*(c + d*x)^3*(a + b*ArcSinh[c + d*x])^(3/2))/(108*d) + (7*b*e^2*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^(5/2))/(9*d) - (7*b*e^2*(c + d*x)^2*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^(5/2))/(18*d) + (e^2*(c + d*x)^3*(a + b*ArcSinh[c + d*x])^(7/2))/(3*d) - (105*b^(7/2)*e^2*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(128*d) + (35*b^(7/2)*e^2*E^((3*a)/b)*Sqrt[Pi/3]*Erf[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(3456*d) - (105*b^(7/2)*e^2*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(128*d*E^(a/b)) + (35*b^(7/2)*e^2*Sqrt[Pi/3]*Erfi[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(3456*d*E^((3*a)/b))}
{(c*e + d*e*x)*(a + b*ArcSinh[c + d*x])^(7/2), x, 12, (-105*b^3*e*(c + d*x)*Sqrt[1 + (c + d*x)^2]*Sqrt[a + b*ArcSinh[c + d*x]])/(128*d) + (35*b^2*e*(a + b*ArcSinh[c + d*x])^(3/2))/(64*d) + (35*b^2*e*(c + d*x)^2*(a + b*ArcSinh[c + d*x])^(3/2))/(32*d) - (7*b*e*(c + d*x)*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^(5/2))/(8*d) + (e*(a + b*ArcSinh[c + d*x])^(7/2))/(4*d) + (e*(c + d*x)^2*(a + b*ArcSinh[c + d*x])^(7/2))/(2*d) - (105*b^(7/2)*e*E^((2*a)/b)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(1024*d) + (105*b^(7/2)*e*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(1024*d*E^((2*a)/b))}
{(a + b*ArcSinh[c + d*x])^(7/2), x, 8, (-105*b^3*Sqrt[1 + (c + d*x)^2]*Sqrt[a + b*ArcSinh[c + d*x]])/(8*d) + (35*b^2*(c + d*x)*(a + b*ArcSinh[c + d*x])^(3/2))/(4*d) - (7*b*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^(5/2))/(2*d) + ((c + d*x)*(a + b*ArcSinh[c + d*x])^(7/2))/d + (105*b^(7/2)*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(32*d) + (105*b^(7/2)*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(32*d*E^(a/b))}
{1/(c*e + d*e*x)*(a + b*ArcSinh[c + d*x])^(7/2), x, 0, Defer[Int][(a + b*ArcSinh[c + d*x])^(7/2)/(c*e + d*e*x), x]}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(c*e + d*e*x)^4/Sqrt[a + b*ArcSinh[c + d*x]], x, 13, (e^4*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(16*Sqrt[b]*d) - (e^4*E^((3*a)/b)*Sqrt[3*Pi]*Erf[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(32*Sqrt[b]*d) + (e^4*E^((5*a)/b)*Sqrt[Pi/5]*Erf[(Sqrt[5]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(32*Sqrt[b]*d) + (e^4*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(16*Sqrt[b]*d*E^(a/b)) - (e^4*Sqrt[3*Pi]*Erfi[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(32*Sqrt[b]*d*E^((3*a)/b)) + (e^4*Sqrt[Pi/5]*Erfi[(Sqrt[5]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(32*Sqrt[b]*d*E^((5*a)/b))}
{(c*e + d*e*x)^3/Sqrt[a + b*ArcSinh[c + d*x]], x, 10, -(e^3*E^((4*a)/b)*Sqrt[Pi]*Erf[(2*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(32*Sqrt[b]*d) + (e^3*E^((2*a)/b)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(8*Sqrt[b]*d) + (e^3*Sqrt[Pi]*Erfi[(2*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(32*Sqrt[b]*d*E^((4*a)/b)) - (e^3*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(8*Sqrt[b]*d*E^((2*a)/b))}
{(c*e + d*e*x)^2/Sqrt[a + b*ArcSinh[c + d*x]], x, 10, -(e^2*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(8*Sqrt[b]*d) + (e^2*E^((3*a)/b)*Sqrt[Pi/3]*Erf[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(8*Sqrt[b]*d) - (e^2*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(8*Sqrt[b]*d*E^(a/b)) + (e^2*Sqrt[Pi/3]*Erfi[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(8*Sqrt[b]*d*E^((3*a)/b))}
{(c*e + d*e*x)/Sqrt[a + b*ArcSinh[c + d*x]], x, 6, -(e*E^((2*a)/b)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(4*Sqrt[b]*d) + (e*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(4*Sqrt[b]*d*E^((2*a)/b))}
{1/Sqrt[a + b*ArcSinh[c + d*x]], x, 6, (E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(2*Sqrt[b]*d) + (Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(2*Sqrt[b]*d*E^(a/b))}
{1/(c*e + d*e*x)/Sqrt[a + b*ArcSinh[c + d*x]], x, 0, Defer[Int][1/((c*e + d*e*x)*Sqrt[a + b*ArcSinh[c + d*x]]), x]}


{(c*e + d*e*x)^4/(a + b*ArcSinh[c + d*x])^(3/2), x, 12, (-2*e^4*(c + d*x)^4*Sqrt[1 + (c + d*x)^2])/(b*d*Sqrt[a + b*ArcSinh[c + d*x]]) - (e^4*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(8*b^(3/2)*d) + (3*e^4*E^((3*a)/b)*Sqrt[3*Pi]*Erf[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(16*b^(3/2)*d) - (e^4*E^((5*a)/b)*Sqrt[5*Pi]*Erf[(Sqrt[5]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(16*b^(3/2)*d) + (e^4*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(8*b^(3/2)*d*E^(a/b)) - (3*e^4*Sqrt[3*Pi]*Erfi[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(16*b^(3/2)*d*E^((3*a)/b)) + (e^4*Sqrt[5*Pi]*Erfi[(Sqrt[5]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(16*b^(3/2)*d*E^((5*a)/b))}
{(c*e + d*e*x)^3/(a + b*ArcSinh[c + d*x])^(3/2), x, 9, (-2*e^3*(c + d*x)^3*Sqrt[1 + (c + d*x)^2])/(b*d*Sqrt[a + b*ArcSinh[c + d*x]]) + (e^3*E^((4*a)/b)*Sqrt[Pi]*Erf[(2*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(4*b^(3/2)*d) - (e^3*E^((2*a)/b)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(2*b^(3/2)*d) + (e^3*Sqrt[Pi]*Erfi[(2*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(4*b^(3/2)*d*E^((4*a)/b)) - (e^3*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(2*b^(3/2)*d*E^((2*a)/b))}
{(c*e + d*e*x)^2/(a + b*ArcSinh[c + d*x])^(3/2), x, 9, (-2*e^2*(c + d*x)^2*Sqrt[1 + (c + d*x)^2])/(b*d*Sqrt[a + b*ArcSinh[c + d*x]]) + (e^2*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(4*b^(3/2)*d) - (e^2*E^((3*a)/b)*Sqrt[3*Pi]*Erf[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(4*b^(3/2)*d) - (e^2*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(4*b^(3/2)*d*E^(a/b)) + (e^2*Sqrt[3*Pi]*Erfi[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(4*b^(3/2)*d*E^((3*a)/b))}
{(c*e + d*e*x)/(a + b*ArcSinh[c + d*x])^(3/2), x, 4, (-2*e*(c + d*x)*Sqrt[1 + (c + d*x)^2])/(b*d*Sqrt[a + b*ArcSinh[c + d*x]]) + (e*E^((2*a)/b)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(b^(3/2)*d) + (e*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(b^(3/2)*d*E^((2*a)/b))}
{(a + b*ArcSinh[c + d*x])^(-3/2), x, 6, (-2*Sqrt[1 + (c + d*x)^2])/(b*d*Sqrt[a + b*ArcSinh[c + d*x]]) - (E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(b^(3/2)*d) + (Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(b^(3/2)*d*E^(a/b))}
{1/(c*e + d*e*x)/(a + b*ArcSinh[c + d*x])^(3/2), x, 0, Defer[Int][1/((c*e + d*e*x)*(a + b*ArcSinh[c + d*x])^(3/2)), x]}


{(c*e + d*e*x)^4/(a + b*ArcSinh[c + d*x])^(5/2), x, 24, (-2*e^4*(c + d*x)^4*Sqrt[1 + (c + d*x)^2])/(3*b*d*(a + b*ArcSinh[c + d*x])^(3/2)) - (16*e^4*(c + d*x)^3)/(3*b^2*d*Sqrt[a + b*ArcSinh[c + d*x]]) - (20*e^4*(c + d*x)^5)/(3*b^2*d*Sqrt[a + b*ArcSinh[c + d*x]]) + (e^4*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(12*b^(5/2)*d) - (3*e^4*E^((3*a)/b)*Sqrt[3*Pi]*Erf[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(8*b^(5/2)*d) + (5*e^4*E^((5*a)/b)*Sqrt[5*Pi]*Erf[(Sqrt[5]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(24*b^(5/2)*d) + (e^4*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(12*b^(5/2)*d*E^(a/b)) - (3*e^4*Sqrt[3*Pi]*Erfi[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(8*b^(5/2)*d*E^((3*a)/b)) + (5*e^4*Sqrt[5*Pi]*Erfi[(Sqrt[5]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(24*b^(5/2)*d*E^((5*a)/b))}
{(c*e + d*e*x)^3/(a + b*ArcSinh[c + d*x])^(5/2), x, 17, (-2*e^3*(c + d*x)^3*Sqrt[1 + (c + d*x)^2])/(3*b*d*(a + b*ArcSinh[c + d*x])^(3/2)) - (4*e^3*(c + d*x)^2)/(b^2*d*Sqrt[a + b*ArcSinh[c + d*x]]) - (16*e^3*(c + d*x)^4)/(3*b^2*d*Sqrt[a + b*ArcSinh[c + d*x]]) - (2*e^3*E^((4*a)/b)*Sqrt[Pi]*Erf[(2*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(3*b^(5/2)*d) + (e^3*E^((2*a)/b)*Sqrt[2*Pi]*Erf[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(3*b^(5/2)*d) + (2*e^3*Sqrt[Pi]*Erfi[(2*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(3*b^(5/2)*d*E^((4*a)/b)) - (e^3*Sqrt[2*Pi]*Erfi[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(3*b^(5/2)*d*E^((2*a)/b))}
{(c*e + d*e*x)^2/(a + b*ArcSinh[c + d*x])^(5/2), x, 17, (-2*e^2*(c + d*x)^2*Sqrt[1 + (c + d*x)^2])/(3*b*d*(a + b*ArcSinh[c + d*x])^(3/2)) - (8*e^2*(c + d*x))/(3*b^2*d*Sqrt[a + b*ArcSinh[c + d*x]]) - (4*e^2*(c + d*x)^3)/(b^2*d*Sqrt[a + b*ArcSinh[c + d*x]]) - (e^2*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(6*b^(5/2)*d) + (e^2*E^((3*a)/b)*Sqrt[3*Pi]*Erf[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(2*b^(5/2)*d) - (e^2*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(6*b^(5/2)*d*E^(a/b)) + (e^2*Sqrt[3*Pi]*Erfi[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(2*b^(5/2)*d*E^((3*a)/b))}
{(c*e + d*e*x)/(a + b*ArcSinh[c + d*x])^(5/2), x, 8, (-2*e*(c + d*x)*Sqrt[1 + (c + d*x)^2])/(3*b*d*(a + b*ArcSinh[c + d*x])^(3/2)) - (4*e)/(3*b^2*d*Sqrt[a + b*ArcSinh[c + d*x]]) - (8*e*(c + d*x)^2)/(3*b^2*d*Sqrt[a + b*ArcSinh[c + d*x]]) - (2*e*E^((2*a)/b)*Sqrt[2*Pi]*Erf[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(3*b^(5/2)*d) + (2*e*Sqrt[2*Pi]*Erfi[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(3*b^(5/2)*d*E^((2*a)/b))}
{(a + b*ArcSinh[c + d*x])^(-5/2), x, 7, (-2*Sqrt[1 + (c + d*x)^2])/(3*b*d*(a + b*ArcSinh[c + d*x])^(3/2)) - (4*(c + d*x))/(3*b^2*d*Sqrt[a + b*ArcSinh[c + d*x]]) + (2*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(3*b^(5/2)*d) + (2*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(3*b^(5/2)*d*E^(a/b))}
{1/(c*e + d*e*x)/(a + b*ArcSinh[c + d*x])^(5/2), x, 0, Defer[Int][1/((c*e + d*e*x)*(a + b*ArcSinh[c + d*x])^(5/2)), x]}


{(c*e + d*e*x)^4/(a + b*ArcSinh[c + d*x])^(7/2), x, 22, (-2*e^4*(c + d*x)^4*Sqrt[1 + (c + d*x)^2])/(5*b*d*(a + b*ArcSinh[c + d*x])^(5/2)) - (16*e^4*(c + d*x)^3)/(15*b^2*d*(a + b*ArcSinh[c + d*x])^(3/2)) - (4*e^4*(c + d*x)^5)/(3*b^2*d*(a + b*ArcSinh[c + d*x])^(3/2)) - (32*e^4*(c + d*x)^2*Sqrt[1 + (c + d*x)^2])/(5*b^3*d*Sqrt[a + b*ArcSinh[c + d*x]]) - (40*e^4*(c + d*x)^4*Sqrt[1 + (c + d*x)^2])/(3*b^3*d*Sqrt[a + b*ArcSinh[c + d*x]]) - (e^4*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(30*b^(7/2)*d) + (9*e^4*E^((3*a)/b)*Sqrt[3*Pi]*Erf[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(20*b^(7/2)*d) - (5*e^4*E^((5*a)/b)*Sqrt[5*Pi]*Erf[(Sqrt[5]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(12*b^(7/2)*d) + (e^4*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(30*b^(7/2)*d*E^(a/b)) - (9*e^4*Sqrt[3*Pi]*Erfi[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(20*b^(7/2)*d*E^((3*a)/b)) + (5*e^4*Sqrt[5*Pi]*Erfi[(Sqrt[5]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(12*b^(7/2)*d*E^((5*a)/b))}
{(c*e + d*e*x)^3/(a + b*ArcSinh[c + d*x])^(7/2), x, 14, (-2*e^3*(c + d*x)^3*Sqrt[1 + (c + d*x)^2])/(5*b*d*(a + b*ArcSinh[c + d*x])^(5/2)) - (4*e^3*(c + d*x)^2)/(5*b^2*d*(a + b*ArcSinh[c + d*x])^(3/2)) - (16*e^3*(c + d*x)^4)/(15*b^2*d*(a + b*ArcSinh[c + d*x])^(3/2)) - (16*e^3*(c + d*x)*Sqrt[1 + (c + d*x)^2])/(5*b^3*d*Sqrt[a + b*ArcSinh[c + d*x]]) - (128*e^3*(c + d*x)^3*Sqrt[1 + (c + d*x)^2])/(15*b^3*d*Sqrt[a + b*ArcSinh[c + d*x]]) + (16*e^3*E^((4*a)/b)*Sqrt[Pi]*Erf[(2*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(15*b^(7/2)*d) - (4*e^3*E^((2*a)/b)*Sqrt[2*Pi]*Erf[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(15*b^(7/2)*d) + (16*e^3*Sqrt[Pi]*Erfi[(2*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(15*b^(7/2)*d*E^((4*a)/b)) - (4*e^3*Sqrt[2*Pi]*Erfi[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(15*b^(7/2)*d*E^((2*a)/b))}
{(c*e + d*e*x)^2/(a + b*ArcSinh[c + d*x])^(7/2), x, 16, (-2*e^2*(c + d*x)^2*Sqrt[1 + (c + d*x)^2])/(5*b*d*(a + b*ArcSinh[c + d*x])^(5/2)) - (8*e^2*(c + d*x))/(15*b^2*d*(a + b*ArcSinh[c + d*x])^(3/2)) - (4*e^2*(c + d*x)^3)/(5*b^2*d*(a + b*ArcSinh[c + d*x])^(3/2)) - (16*e^2*Sqrt[1 + (c + d*x)^2])/(15*b^3*d*Sqrt[a + b*ArcSinh[c + d*x]]) - (24*e^2*(c + d*x)^2*Sqrt[1 + (c + d*x)^2])/(5*b^3*d*Sqrt[a + b*ArcSinh[c + d*x]]) + (e^2*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(15*b^(7/2)*d) - (3*e^2*E^((3*a)/b)*Sqrt[3*Pi]*Erf[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(5*b^(7/2)*d) - (e^2*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(15*b^(7/2)*d*E^(a/b)) + (3*e^2*Sqrt[3*Pi]*Erfi[(Sqrt[3]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(5*b^(7/2)*d*E^((3*a)/b))}
{(c*e + d*e*x)/(a + b*ArcSinh[c + d*x])^(7/2), x, 6, (-2*e*(c + d*x)*Sqrt[1 + (c + d*x)^2])/(5*b*d*(a + b*ArcSinh[c + d*x])^(5/2)) - (4*e)/(15*b^2*d*(a + b*ArcSinh[c + d*x])^(3/2)) - (8*e*(c + d*x)^2)/(15*b^2*d*(a + b*ArcSinh[c + d*x])^(3/2)) - (32*e*(c + d*x)*Sqrt[1 + (c + d*x)^2])/(15*b^3*d*Sqrt[a + b*ArcSinh[c + d*x]]) + (8*e*E^((2*a)/b)*Sqrt[2*Pi]*Erf[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(15*b^(7/2)*d) + (8*e*Sqrt[2*Pi]*Erfi[(Sqrt[2]*Sqrt[a + b*ArcSinh[c + d*x]])/Sqrt[b]])/(15*b^(7/2)*d*E^((2*a)/b))}
{(a + b*ArcSinh[c + d*x])^(-7/2), x, 7, (-2*Sqrt[1 + (c + d*x)^2])/(5*b*d*(a + b*ArcSinh[c + d*x])^(5/2)) - (4*(c + d*x))/(15*b^2*d*(a + b*ArcSinh[c + d*x])^(3/2)) - (8*Sqrt[1 + (c + d*x)^2])/(15*b^3*d*Sqrt[a + b*ArcSinh[c + d*x]]) - (4*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(15*b^(7/2)*d) + (4*Sqrt[Pi]*Erfi[Sqrt[a + b*ArcSinh[c + d*x]]/Sqrt[b]])/(15*b^(7/2)*d*E^(a/b))}
{1/(c*e + d*e*x)/(a + b*ArcSinh[c + d*x])^(7/2), x, 0, Defer[Int][1/((c*e + d*e*x)*(a + b*ArcSinh[c + d*x])^(7/2)), x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c e+d e x)^(m/2) (a+b ArcSinh[c+d x])^n*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{(c*e + d*e*x)^(7/2)*(a + b*ArcSinh[c + d*x]), x, 6, (28*b*(c*e + d*e*x)^(9/2)*Sqrt[1 + (c + d*x)^2])/(405*d*e*(c + d*x)^3) - (4*b*(c*e + d*e*x)^(9/2)*Sqrt[1 + (c + d*x)^2])/(81*d*e*(c + d*x)) + (2*(c*e + d*e*x)^(9/2)*(a + b*ArcSinh[c + d*x]))/(9*d*e) + (28*(-1)^(1/4)*b*(c*e + d*e*x)^(9/2)*EllipticE[ArcSin[(-1)^(1/4)*Sqrt[c + d*x]], -1])/(135*d*e*(c + d*x)^(9/2)) - (28*(-1)^(1/4)*b*(c*e + d*e*x)^(9/2)*EllipticF[ArcSin[(-1)^(1/4)*Sqrt[c + d*x]], -1])/(135*d*e*(c + d*x)^(9/2))}
{(c*e + d*e*x)^(5/2)*(a + b*ArcSinh[c + d*x]), x, 6, (20*b*(c*e + d*e*x)^(7/2)*Sqrt[1 + (c + d*x)^2])/(147*d*e*(c + d*x)^3) - (4*b*(c*e + d*e*x)^(7/2)*Sqrt[1 + (c + d*x)^2])/(49*d*e*(c + d*x)) + (2*(c*e + d*e*x)^(7/2)*(a + b*ArcSinh[c + d*x]))/(7*d*e) + (20*(-1)^(3/4)*b*(c*e + d*e*x)^(7/2)*EllipticF[ArcSin[(-1)^(1/4)*Sqrt[c + d*x]], -1])/(147*d*e*(c + d*x)^(7/2))}
{(c*e + d*e*x)^(3/2)*(a + b*ArcSinh[c + d*x]), x, 5, -((4*b*(c*e + d*e*x)^(5/2)*Sqrt[1 + (c + d*x)^2])/(25*d*e*(c + d*x))) + (2*(c*e + d*e*x)^(5/2)*(a + b*ArcSinh[c + d*x]))/(5*d*e) - (12*(-1)^(1/4)*b*(c*e + d*e*x)^(5/2)*EllipticE[ArcSin[(-1)^(1/4)*Sqrt[c + d*x]], -1])/(25*d*e*(c + d*x)^(5/2)) + (12*(-1)^(1/4)*b*(c*e + d*e*x)^(5/2)*EllipticF[ArcSin[(-1)^(1/4)*Sqrt[c + d*x]], -1])/(25*d*e*(c + d*x)^(5/2))}
{Sqrt[c*e + d*e*x]*(a + b*ArcSinh[c + d*x]), x, 5, -((4*b*(c*e + d*e*x)^(3/2)*Sqrt[1 + (c + d*x)^2])/(9*d*e*(c + d*x))) + (2*(c*e + d*e*x)^(3/2)*(a + b*ArcSinh[c + d*x]))/(3*d*e) - (4*(-1)^(3/4)*b*(c*e + d*e*x)^(3/2)*EllipticF[ArcSin[(-1)^(1/4)*Sqrt[c + d*x]], -1])/(9*d*e*(c + d*x)^(3/2))}
{(a + b*ArcSinh[c + d*x])/Sqrt[c*e + d*e*x], x, 4, (2*Sqrt[c*e + d*e*x]*(a + b*ArcSinh[c + d*x]))/(d*e) + (4*(-1)^(1/4)*b*Sqrt[c*e + d*e*x]*EllipticE[ArcSin[(-1)^(1/4)*Sqrt[c + d*x]], -1])/(d*e*Sqrt[c + d*x]) - (4*(-1)^(1/4)*b*Sqrt[c*e + d*e*x]*EllipticF[ArcSin[(-1)^(1/4)*Sqrt[c + d*x]], -1])/(d*e*Sqrt[c + d*x])}
{(a + b*ArcSinh[c + d*x])/(c*e + d*e*x)^(3/2), x, 4, -((2*(a + b*ArcSinh[c + d*x]))/(d*e*Sqrt[c*e + d*e*x])) - (4*(-1)^(3/4)*b*Sqrt[c + d*x]*EllipticF[ArcSin[(-1)^(1/4)*Sqrt[c + d*x]], -1])/(d*e*Sqrt[c*e + d*e*x])}
{(a + b*ArcSinh[c + d*x])/(c*e + d*e*x)^(5/2), x, 5, -((4*b*(c + d*x)*Sqrt[1 + (c + d*x)^2])/(3*d*e*(c*e + d*e*x)^(3/2))) - (2*(a + b*ArcSinh[c + d*x]))/(3*d*e*(c*e + d*e*x)^(3/2)) - (4*(-1)^(1/4)*b*(c + d*x)^(3/2)*EllipticE[ArcSin[(-1)^(1/4)*Sqrt[c + d*x]], -1])/(3*d*e*(c*e + d*e*x)^(3/2)) + (4*(-1)^(1/4)*b*(c + d*x)^(3/2)*EllipticF[ArcSin[(-1)^(1/4)*Sqrt[c + d*x]], -1])/(3*d*e*(c*e + d*e*x)^(3/2))}
{(a + b*ArcSinh[c + d*x])/(c*e + d*e*x)^(7/2), x, 5, -((4*b*(c + d*x)*Sqrt[1 + (c + d*x)^2])/(15*d*e*(c*e + d*e*x)^(5/2))) - (2*(a + b*ArcSinh[c + d*x]))/(5*d*e*(c*e + d*e*x)^(5/2)) + (4*(-1)^(3/4)*b*(c + d*x)^(5/2)*EllipticF[ArcSin[(-1)^(1/4)*Sqrt[c + d*x]], -1])/(15*d*e*(c*e + d*e*x)^(5/2))}


{(c*e + d*e*x)^(7/2)*(a + b*ArcSinh[c + d*x])^2, x, 6, (-112*b^2*e*(c*e + d*e*x)^(5/2))/(2025*d) + (16*b^2*(c*e + d*e*x)^(9/2))/(729*d*e) + (56*b*e^2*(c*e + d*e*x)^(3/2)*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x]))/(405*d) - (8*b*(c*e + d*e*x)^(7/2)*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x]))/(81*d) + (2*(c*e + d*e*x)^(9/2)*(a + b*ArcSinh[c + d*x])^2)/(9*d*e) - (56*b*e^3*(c + d*x)*Sqrt[c*e + d*e*x]*(a + b*ArcSinh[c + d*x])*Hypergeometric2F1[1/2, 3/4, 7/4, -(c + d*x)^2])/(405*d) + (112*b^2*e^3*(c + d*x)^2*Sqrt[c*e + d*e*x]*HypergeometricPFQ[{1, 5/4, 5/4}, {7/4, 9/4}, -(c + d*x)^2])/(2025*d)}
{(c*e + d*e*x)^(5/2)*(a + b*ArcSinh[c + d*x])^2, x, 6, (-80*b^2*e*(c*e + d*e*x)^(3/2))/(441*d) + (16*b^2*(c*e + d*e*x)^(7/2))/(343*d*e) + (40*b*e^2*Sqrt[c*e + d*e*x]*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x]))/(147*d) - (8*b*(c*e + d*e*x)^(5/2)*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x]))/(49*d) + (2*(c*e + d*e*x)^(7/2)*(a + b*ArcSinh[c + d*x])^2)/(7*d*e) - (40*b*e^3*(c + d*x)*(a + b*ArcSinh[c + d*x])*Hypergeometric2F1[1/4, 1/2, 5/4, -(c + d*x)^2])/(147*d*Sqrt[c*e + d*e*x]) + (80*b^2*e^3*(c + d*x)^2*HypergeometricPFQ[{3/4, 3/4, 1}, {5/4, 7/4}, -(c + d*x)^2])/(441*d*Sqrt[c*e + d*e*x])}
{(c*e + d*e*x)^(3/2)*(a + b*ArcSinh[c + d*x])^2, x, 4, (16*b^2*(c*e + d*e*x)^(5/2))/(125*d*e) - (8*b*(c*e + d*e*x)^(3/2)*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x]))/(25*d) + (2*(c*e + d*e*x)^(5/2)*(a + b*ArcSinh[c + d*x])^2)/(5*d*e) + (8*b*e*(c + d*x)*Sqrt[c*e + d*e*x]*(a + b*ArcSinh[c + d*x])*Hypergeometric2F1[1/2, 3/4, 7/4, -(c + d*x)^2])/(25*d) - (16*b^2*e*(c + d*x)^2*Sqrt[c*e + d*e*x]*HypergeometricPFQ[{1, 5/4, 5/4}, {7/4, 9/4}, -(c + d*x)^2])/(125*d)}
{Sqrt[c*e + d*e*x]*(a + b*ArcSinh[c + d*x])^2, x, 4, (16*b^2*(c*e + d*e*x)^(3/2))/(27*d*e) - (8*b*Sqrt[c*e + d*e*x]*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x]))/(9*d) + (2*(c*e + d*e*x)^(3/2)*(a + b*ArcSinh[c + d*x])^2)/(3*d*e) + (8*b*e*(c + d*x)*(a + b*ArcSinh[c + d*x])*Hypergeometric2F1[1/4, 1/2, 5/4, -(c + d*x)^2])/(9*d*Sqrt[c*e + d*e*x]) - (16*b^2*e*(c + d*x)^2*HypergeometricPFQ[{3/4, 3/4, 1}, {5/4, 7/4}, -(c + d*x)^2])/(27*d*Sqrt[c*e + d*e*x])}
{(a + b*ArcSinh[c + d*x])^2/Sqrt[c*e + d*e*x], x, 2, (2*Sqrt[c*e + d*e*x]*(a + b*ArcSinh[c + d*x])^2)/(d*e) - (8*b*(c + d*x)*Sqrt[c*e + d*e*x]*(a + b*ArcSinh[c + d*x])*Hypergeometric2F1[1/2, 3/4, 7/4, -(c + d*x)^2])/(3*d*e) + (16*b^2*(c + d*x)^2*Sqrt[c*e + d*e*x]*HypergeometricPFQ[{1, 5/4, 5/4}, {7/4, 9/4}, -(c + d*x)^2])/(15*d*e)}
{(a + b*ArcSinh[c + d*x])^2/(c*e + d*e*x)^(3/2), x, 2, (-2*(a + b*ArcSinh[c + d*x])^2)/(d*e*Sqrt[c*e + d*e*x]) + (8*b*(c + d*x)*(a + b*ArcSinh[c + d*x])*Hypergeometric2F1[1/4, 1/2, 5/4, -(c + d*x)^2])/(d*e*Sqrt[c*e + d*e*x]) - (16*b^2*(c + d*x)^2*HypergeometricPFQ[{3/4, 3/4, 1}, {5/4, 7/4}, -(c + d*x)^2])/(3*d*e*Sqrt[c*e + d*e*x])}
{(a + b*ArcSinh[c + d*x])^2/(c*e + d*e*x)^(5/2), x, 4, (16*b^2*Sqrt[c*e + d*e*x])/(3*d*e^3) - (8*b*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x]))/(3*d*e^2*Sqrt[c*e + d*e*x]) - (2*(a + b*ArcSinh[c + d*x])^2)/(3*d*e*(c*e + d*e*x)^(3/2)) + (8*b*(c + d*x)*Sqrt[c*e + d*e*x]*(a + b*ArcSinh[c + d*x])*Hypergeometric2F1[1/2, 3/4, 7/4, -(c + d*x)^2])/(9*d*e^3) - (16*b^2*(c + d*x)^2*Sqrt[c*e + d*e*x]*HypergeometricPFQ[{1, 5/4, 5/4}, {7/4, 9/4}, -(c + d*x)^2])/(45*d*e^3)}
{(a + b*ArcSinh[c + d*x])^2/(c*e + d*e*x)^(7/2), x, 4, (-16*b^2)/(15*d*e^3*Sqrt[c*e + d*e*x]) - (8*b*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x]))/(15*d*e^2*(c*e + d*e*x)^(3/2)) - (2*(a + b*ArcSinh[c + d*x])^2)/(5*d*e*(c*e + d*e*x)^(5/2)) - (8*b*(c + d*x)*(a + b*ArcSinh[c + d*x])*Hypergeometric2F1[1/4, 1/2, 5/4, -(c + d*x)^2])/(15*d*e^3*Sqrt[c*e + d*e*x]) + (16*b^2*(c + d*x)^2*HypergeometricPFQ[{3/4, 3/4, 1}, {5/4, 7/4}, -(c + d*x)^2])/(45*d*e^3*Sqrt[c*e + d*e*x])}


{(c*e + d*e*x)^(7/2)*(a + b*ArcSinh[c + d*x])^3, x, 14, (224*b^3*e*(c*e + d*e*x)^(5/2)*Sqrt[1 + (c + d*x)^2])/(3375*d*(c + d*x)) + (224*b^3*(c*e + d*e*x)^(9/2)*Sqrt[1 + (c + d*x)^2])/(10935*d*e*(c + d*x)^3) - (32*b^3*(c*e + d*e*x)^(9/2)*Sqrt[1 + (c + d*x)^2])/(2187*d*e*(c + d*x)) - (112*b^2*e*(c*e + d*e*x)^(5/2)*(a + b*ArcSinh[c + d*x]))/(675*d) + (16*b^2*(c*e + d*e*x)^(9/2)*(a + b*ArcSinh[c + d*x]))/(243*d*e) + (28*b*e^2*(c*e + d*e*x)^(3/2)*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^2)/(135*d) - (4*b*(c*e + d*e*x)^(7/2)*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^2)/(27*d) + (2*(c*e + d*e*x)^(9/2)*(a + b*ArcSinh[c + d*x])^3)/(9*d*e) + (224*(-1)^(1/4)*b^3*e*(c*e + d*e*x)^(5/2)*EllipticE[ArcSin[(-1)^(1/4)*Sqrt[c + d*x]], -1])/(1125*d*(c + d*x)^(5/2)) + (224*(-1)^(1/4)*b^3*(c*e + d*e*x)^(9/2)*EllipticE[ArcSin[(-1)^(1/4)*Sqrt[c + d*x]], -1])/(3645*d*e*(c + d*x)^(9/2)) - (224*(-1)^(1/4)*b^3*e*(c*e + d*e*x)^(5/2)*EllipticF[ArcSin[(-1)^(1/4)*Sqrt[c + d*x]], -1])/(1125*d*(c + d*x)^(5/2)) - (224*(-1)^(1/4)*b^3*(c*e + d*e*x)^(9/2)*EllipticF[ArcSin[(-1)^(1/4)*Sqrt[c + d*x]], -1])/(3645*d*e*(c + d*x)^(9/2)) - (14/45)*b*e^3*Defer[Int][(Sqrt[c*e + d*e*x]*(a + b*ArcSinh[c + d*x])^2)/Sqrt[1 + (c + d*x)^2], x]}
{(c*e + d*e*x)^(5/2)*(a + b*ArcSinh[c + d*x])^3, x, 14, (160*b^3*e*(c*e + d*e*x)^(3/2)*Sqrt[1 + (c + d*x)^2])/(441*d*(c + d*x)) + (160*b^3*(c*e + d*e*x)^(7/2)*Sqrt[1 + (c + d*x)^2])/(2401*d*e*(c + d*x)^3) - (96*b^3*(c*e + d*e*x)^(7/2)*Sqrt[1 + (c + d*x)^2])/(2401*d*e*(c + d*x)) - (80*b^2*e*(c*e + d*e*x)^(3/2)*(a + b*ArcSinh[c + d*x]))/(147*d) + (48*b^2*(c*e + d*e*x)^(7/2)*(a + b*ArcSinh[c + d*x]))/(343*d*e) + (20*b*e^2*Sqrt[c*e + d*e*x]*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^2)/(49*d) - (12*b*(c*e + d*e*x)^(5/2)*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^2)/(49*d) + (2*(c*e + d*e*x)^(7/2)*(a + b*ArcSinh[c + d*x])^3)/(7*d*e) + (160*(-1)^(3/4)*b^3*e*(c*e + d*e*x)^(3/2)*EllipticF[ArcSin[(-1)^(1/4)*Sqrt[c + d*x]], -1])/(441*d*(c + d*x)^(3/2)) + (160*(-1)^(3/4)*b^3*(c*e + d*e*x)^(7/2)*EllipticF[ArcSin[(-1)^(1/4)*Sqrt[c + d*x]], -1])/(2401*d*e*(c + d*x)^(7/2)) - (10/49)*b*e^3*Defer[Int][(a + b*ArcSinh[c + d*x])^2/(Sqrt[c*e + d*e*x]*Sqrt[1 + (c + d*x)^2]), x]}
{(c*e + d*e*x)^(3/2)*(a + b*ArcSinh[c + d*x])^3, x, 7, -((96*b^3*(c*e + d*e*x)^(5/2)*Sqrt[1 + (c + d*x)^2])/(625*d*e*(c + d*x))) + (48*b^2*(c*e + d*e*x)^(5/2)*(a + b*ArcSinh[c + d*x]))/(125*d*e) - (12*b*(c*e + d*e*x)^(3/2)*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^2)/(25*d) + (2*(c*e + d*e*x)^(5/2)*(a + b*ArcSinh[c + d*x])^3)/(5*d*e) - (288*(-1)^(1/4)*b^3*(c*e + d*e*x)^(5/2)*EllipticE[ArcSin[(-1)^(1/4)*Sqrt[c + d*x]], -1])/(625*d*e*(c + d*x)^(5/2)) + (288*(-1)^(1/4)*b^3*(c*e + d*e*x)^(5/2)*EllipticF[ArcSin[(-1)^(1/4)*Sqrt[c + d*x]], -1])/(625*d*e*(c + d*x)^(5/2)) + (18/25)*b*e*Defer[Int][(Sqrt[c*e + d*e*x]*(a + b*ArcSinh[c + d*x])^2)/Sqrt[1 + (c + d*x)^2], x]}
{Sqrt[c*e + d*e*x]*(a + b*ArcSinh[c + d*x])^3, x, 7, -((32*b^3*(c*e + d*e*x)^(3/2)*Sqrt[1 + (c + d*x)^2])/(27*d*e*(c + d*x))) + (16*b^2*(c*e + d*e*x)^(3/2)*(a + b*ArcSinh[c + d*x]))/(9*d*e) - (4*b*Sqrt[c*e + d*e*x]*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^2)/(3*d) + (2*(c*e + d*e*x)^(3/2)*(a + b*ArcSinh[c + d*x])^3)/(3*d*e) - (32*(-1)^(3/4)*b^3*(c*e + d*e*x)^(3/2)*EllipticF[ArcSin[(-1)^(1/4)*Sqrt[c + d*x]], -1])/(27*d*e*(c + d*x)^(3/2)) + (2/3)*b*e*Defer[Int][(a + b*ArcSinh[c + d*x])^2/(Sqrt[c*e + d*e*x]*Sqrt[1 + (c + d*x)^2]), x]}
{(a + b*ArcSinh[c + d*x])^3/Sqrt[c*e + d*e*x], x, 1, (2*Sqrt[c*e + d*e*x]*(a + b*ArcSinh[c + d*x])^3)/(d*e) - (6*b*Defer[Int][(Sqrt[c*e + d*e*x]*(a + b*ArcSinh[c + d*x])^2)/Sqrt[1 + (c + d*x)^2], x])/e}
{(a + b*ArcSinh[c + d*x])^3/(c*e + d*e*x)^(3/2), x, 1, (-2*(a + b*ArcSinh[c + d*x])^3)/(d*e*Sqrt[c*e + d*e*x]) + (6*b*Defer[Int][(a + b*ArcSinh[c + d*x])^2/(Sqrt[c*e + d*e*x]*Sqrt[1 + (c + d*x)^2]), x])/e}
{(a + b*ArcSinh[c + d*x])^3/(c*e + d*e*x)^(5/2), x, 6, (16*b^2*Sqrt[c*e + d*e*x]*(a + b*ArcSinh[c + d*x]))/(d*e^3) - (4*b*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^2)/(d*e^2*Sqrt[c*e + d*e*x]) - (2*(a + b*ArcSinh[c + d*x])^3)/(3*d*e*(c*e + d*e*x)^(3/2)) + (32*(-1)^(1/4)*b^3*Sqrt[c*e + d*e*x]*EllipticE[ArcSin[(-1)^(1/4)*Sqrt[c + d*x]], -1])/(d*e^3*Sqrt[c + d*x]) - (32*(-1)^(1/4)*b^3*Sqrt[c*e + d*e*x]*EllipticF[ArcSin[(-1)^(1/4)*Sqrt[c + d*x]], -1])/(d*e^3*Sqrt[c + d*x]) + (2*b*Defer[Int][(Sqrt[c*e + d*e*x]*(a + b*ArcSinh[c + d*x])^2)/Sqrt[1 + (c + d*x)^2], x])/e^3}
{(a + b*ArcSinh[c + d*x])^3/(c*e + d*e*x)^(7/2), x, 6, -((16*b^2*(a + b*ArcSinh[c + d*x]))/(5*d*e^3*Sqrt[c*e + d*e*x])) - (4*b*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^2)/(5*d*e^2*(c*e + d*e*x)^(3/2)) - (2*(a + b*ArcSinh[c + d*x])^3)/(5*d*e*(c*e + d*e*x)^(5/2)) - (32*(-1)^(3/4)*b^3*Sqrt[c + d*x]*EllipticF[ArcSin[(-1)^(1/4)*Sqrt[c + d*x]], -1])/(5*d*e^3*Sqrt[c*e + d*e*x]) - (2*b*Defer[Int][(a + b*ArcSinh[c + d*x])^2/(Sqrt[c*e + d*e*x]*Sqrt[1 + (c + d*x)^2]), x])/(5*e^3)}


{(c*e + d*e*x)^(7/2)*(a + b*ArcSinh[c + d*x])^4, x, 13, (-189952*b^4*e*(c*e + d*e*x)^(5/2))/(1366875*d) + (256*b^4*(c*e + d*e*x)^(9/2))/(19683*d*e) + (94976*b^3*e^2*(c*e + d*e*x)^(3/2)*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x]))/(273375*d) - (128*b^3*(c*e + d*e*x)^(7/2)*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x]))/(2187*d) - (224*b^2*e*(c*e + d*e*x)^(5/2)*(a + b*ArcSinh[c + d*x])^2)/(675*d) + (32*b^2*(c*e + d*e*x)^(9/2)*(a + b*ArcSinh[c + d*x])^2)/(243*d*e) + (112*b*e^2*(c*e + d*e*x)^(3/2)*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^3)/(405*d) - (16*b*(c*e + d*e*x)^(7/2)*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^3)/(81*d) + (2*(c*e + d*e*x)^(9/2)*(a + b*ArcSinh[c + d*x])^4)/(9*d*e) - (94976*b^3*e^3*(c + d*x)*Sqrt[c*e + d*e*x]*(a + b*ArcSinh[c + d*x])*Hypergeometric2F1[1/2, 3/4, 7/4, -(c + d*x)^2])/(273375*d) + (189952*b^4*e^3*(c + d*x)^2*Sqrt[c*e + d*e*x]*HypergeometricPFQ[{1, 5/4, 5/4}, {7/4, 9/4}, -(c + d*x)^2])/(1366875*d) - (56*b*e^3*Defer[Int][(Sqrt[c*e + d*e*x]*(a + b*ArcSinh[c + d*x])^3)/Sqrt[1 + (c + d*x)^2], x])/135}
{(c*e + d*e*x)^(5/2)*(a + b*ArcSinh[c + d*x])^4, x, 13, (-74240*b^4*e*(c*e + d*e*x)^(3/2))/(64827*d) + (768*b^4*(c*e + d*e*x)^(7/2))/(16807*d*e) + (37120*b^3*e^2*Sqrt[c*e + d*e*x]*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x]))/(21609*d) - (384*b^3*(c*e + d*e*x)^(5/2)*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x]))/(2401*d) - (160*b^2*e*(c*e + d*e*x)^(3/2)*(a + b*ArcSinh[c + d*x])^2)/(147*d) + (96*b^2*(c*e + d*e*x)^(7/2)*(a + b*ArcSinh[c + d*x])^2)/(343*d*e) + (80*b*e^2*Sqrt[c*e + d*e*x]*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^3)/(147*d) - (16*b*(c*e + d*e*x)^(5/2)*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^3)/(49*d) + (2*(c*e + d*e*x)^(7/2)*(a + b*ArcSinh[c + d*x])^4)/(7*d*e) - (37120*b^3*e^3*(c + d*x)*(a + b*ArcSinh[c + d*x])*Hypergeometric2F1[1/4, 1/2, 5/4, -(c + d*x)^2])/(21609*d*Sqrt[c*e + d*e*x]) + (74240*b^4*e^3*(c + d*x)^2*HypergeometricPFQ[{3/4, 3/4, 1}, {5/4, 7/4}, -(c + d*x)^2])/(64827*d*Sqrt[c*e + d*e*x]) - (40*b*e^3*Defer[Int][(a + b*ArcSinh[c + d*x])^3/(Sqrt[c*e + d*e*x]*Sqrt[1 + (c + d*x)^2]), x])/147}
{(c*e + d*e*x)^(3/2)*(a + b*ArcSinh[c + d*x])^4, x, 6, (768*b^4*(c*e + d*e*x)^(5/2))/(3125*d*e) - (384*b^3*(c*e + d*e*x)^(3/2)*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x]))/(625*d) + (96*b^2*(c*e + d*e*x)^(5/2)*(a + b*ArcSinh[c + d*x])^2)/(125*d*e) - (16*b*(c*e + d*e*x)^(3/2)*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^3)/(25*d) + (2*(c*e + d*e*x)^(5/2)*(a + b*ArcSinh[c + d*x])^4)/(5*d*e) + (384*b^3*e*(c + d*x)*Sqrt[c*e + d*e*x]*(a + b*ArcSinh[c + d*x])*Hypergeometric2F1[1/2, 3/4, 7/4, -(c + d*x)^2])/(625*d) - (768*b^4*e*(c + d*x)^2*Sqrt[c*e + d*e*x]*HypergeometricPFQ[{1, 5/4, 5/4}, {7/4, 9/4}, -(c + d*x)^2])/(3125*d) + (24*b*e*Defer[Int][(Sqrt[c*e + d*e*x]*(a + b*ArcSinh[c + d*x])^3)/Sqrt[1 + (c + d*x)^2], x])/25}
{Sqrt[c*e + d*e*x]*(a + b*ArcSinh[c + d*x])^4, x, 6, (256*b^4*(c*e + d*e*x)^(3/2))/(81*d*e) - (128*b^3*Sqrt[c*e + d*e*x]*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x]))/(27*d) + (32*b^2*(c*e + d*e*x)^(3/2)*(a + b*ArcSinh[c + d*x])^2)/(9*d*e) - (16*b*Sqrt[c*e + d*e*x]*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^3)/(9*d) + (2*(c*e + d*e*x)^(3/2)*(a + b*ArcSinh[c + d*x])^4)/(3*d*e) + (128*b^3*e*(c + d*x)*(a + b*ArcSinh[c + d*x])*Hypergeometric2F1[1/4, 1/2, 5/4, -(c + d*x)^2])/(27*d*Sqrt[c*e + d*e*x]) - (256*b^4*e*(c + d*x)^2*HypergeometricPFQ[{3/4, 3/4, 1}, {5/4, 7/4}, -(c + d*x)^2])/(81*d*Sqrt[c*e + d*e*x]) + (8*b*e*Defer[Int][(a + b*ArcSinh[c + d*x])^3/(Sqrt[c*e + d*e*x]*Sqrt[1 + (c + d*x)^2]), x])/9}
{(a + b*ArcSinh[c + d*x])^4/Sqrt[c*e + d*e*x], x, 1, (2*Sqrt[c*e + d*e*x]*(a + b*ArcSinh[c + d*x])^4)/(d*e) - (8*b*Defer[Int][(Sqrt[c*e + d*e*x]*(a + b*ArcSinh[c + d*x])^3)/Sqrt[1 + (c + d*x)^2], x])/e}
{(a + b*ArcSinh[c + d*x])^4/(c*e + d*e*x)^(3/2), x, 1, (-2*(a + b*ArcSinh[c + d*x])^4)/(d*e*Sqrt[c*e + d*e*x]) + (8*b*Defer[Int][(a + b*ArcSinh[c + d*x])^3/(Sqrt[c*e + d*e*x]*Sqrt[1 + (c + d*x)^2]), x])/e}
{(a + b*ArcSinh[c + d*x])^4/(c*e + d*e*x)^(5/2), x, 4, (32*b^2*Sqrt[c*e + d*e*x]*(a + b*ArcSinh[c + d*x])^2)/(d*e^3) - (16*b*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^3)/(3*d*e^2*Sqrt[c*e + d*e*x]) - (2*(a + b*ArcSinh[c + d*x])^4)/(3*d*e*(c*e + d*e*x)^(3/2)) - (128*b^3*(c + d*x)*Sqrt[c*e + d*e*x]*(a + b*ArcSinh[c + d*x])*Hypergeometric2F1[1/2, 3/4, 7/4, -(c + d*x)^2])/(3*d*e^3) + (256*b^4*(c + d*x)^2*Sqrt[c*e + d*e*x]*HypergeometricPFQ[{1, 5/4, 5/4}, {7/4, 9/4}, -(c + d*x)^2])/(15*d*e^3) + (8*b*Defer[Int][(Sqrt[c*e + d*e*x]*(a + b*ArcSinh[c + d*x])^3)/Sqrt[1 + (c + d*x)^2], x])/(3*e^3)}
{(a + b*ArcSinh[c + d*x])^4/(c*e + d*e*x)^(7/2), x, 4, (-32*b^2*(a + b*ArcSinh[c + d*x])^2)/(5*d*e^3*Sqrt[c*e + d*e*x]) - (16*b*Sqrt[1 + (c + d*x)^2]*(a + b*ArcSinh[c + d*x])^3)/(15*d*e^2*(c*e + d*e*x)^(3/2)) - (2*(a + b*ArcSinh[c + d*x])^4)/(5*d*e*(c*e + d*e*x)^(5/2)) + (128*b^3*(c + d*x)*(a + b*ArcSinh[c + d*x])*Hypergeometric2F1[1/4, 1/2, 5/4, -(c + d*x)^2])/(5*d*e^3*Sqrt[c*e + d*e*x]) - (256*b^4*(c + d*x)^2*HypergeometricPFQ[{3/4, 3/4, 1}, {5/4, 7/4}, -(c + d*x)^2])/(15*d*e^3*Sqrt[c*e + d*e*x]) - (8*b*Defer[Int][(a + b*ArcSinh[c + d*x])^3/(Sqrt[c*e + d*e*x]*Sqrt[1 + (c + d*x)^2]), x])/(15*e^3)}


(* ::Subsubsection:: *)
(*n<0*)


(* ::Subsection::Closed:: *)
(*x^m ArcSinh[c E^(a+b x)]*)


{ArcSinh[c*E^(a + b*x)], x, 6, -(ArcSinh[c*E^(a + b*x)]^2/(2*b)) + (ArcSinh[c*E^(a + b*x)]*Log[1 - E^(2*ArcSinh[c*E^(a + b*x)])])/b + PolyLog[2, E^(2*ArcSinh[c*E^(a + b*x)])]/(2*b)}


(* ::Subsection::Closed:: *)
(*x^m E^ArcSinh[a x]*)


{x^3*E^ArcSinh[x], x, 6, x^5/5 - (1/3)*(1 + x^2)^(3/2) + (1/5)*(1 + x^2)^(5/2)}
{x^2*E^ArcSinh[x], x, 6, x^4/4 + (1/8)*x*Sqrt[1 + x^2] + (1/4)*x^3*Sqrt[1 + x^2] - ArcSinh[x]/8}
{x*E^ArcSinh[x], x, 4, x^3/3 + (1 + x^2)^(3/2)/3}
{E^ArcSinh[x], x, 4, x^2/2 + (1/2)*x*Sqrt[1 + x^2] + ArcSinh[x]/2}
{E^ArcSinh[x]/x, x, 6, x + Sqrt[1 + x^2] - ArcTanh[Sqrt[1 + x^2]]}
{E^ArcSinh[x]/x^2, x, 5, -(Sqrt[1 + x^2]/x) + ArcSinh[x] + Log[x]}
{E^ArcSinh[x]/x^3, x, 6, -(1/x) - Sqrt[1 + x^2]/(2*x^2) - (1/2)*ArcTanh[Sqrt[1 + x^2]]}


(* ::Subsection::Closed:: *)
(*Miscellaneous integrands involving inverse hyperbolic sines*)


{ArcSinh[a + b*x]/((a*d)/b + d*x), x, 5, -(ArcSinh[a + b*x]^2/(2*d)) + (ArcSinh[a + b*x]*Log[1 - E^(2*ArcSinh[a + b*x])])/d + PolyLog[2, E^(2*ArcSinh[a + b*x])]/(2*d)}


{x/(Sqrt[1 + x^2]*ArcSinh[x]), x, 2, SinhIntegral[ArcSinh[x]]}


{ArcSinh[a*x^n]/x, x, 5, -(ArcSinh[a*x^n]^2/(2*n)) + (ArcSinh[a*x^n]*Log[1 - E^(2*ArcSinh[a*x^n])])/n + PolyLog[2, E^(2*ArcSinh[a*x^n])]/(2*n)}

{ArcSinh[a*x^5]/x, x, 5, (-(1/10))*ArcSinh[a*x^5]^2 + (1/5)*ArcSinh[a*x^5]*Log[1 - E^(2*ArcSinh[a*x^5])] + (1/10)*PolyLog[2, E^(2*ArcSinh[a*x^5])]}


{x^3*ArcSinh[a + b*x^4], x, 2, -(Sqrt[1 + (a + b*x^4)^2]/(4*b)) + ((a + b*x^4)*ArcSinh[a + b*x^4])/(4*b)}

{x^(n-1)*ArcSinh[a + b*x^n], x, 2, -(Sqrt[1 + (a + b*x^n)^2]/(b*n)) + ((a + b*x^n)*ArcSinh[a + b*x^n])/(b*n)}


{ArcSinh[c/(a + b*x)], x, 5, ((a + b*x)*ArcCsch[a/c + (b*x)/c])/b + (c*ArcTanh[Sqrt[1 + 1/(a/c + (b*x)/c)^2]])/b}


{x/ArcSinh[Sinh[x]], x, 0, ArcSinh[Sinh[x]] + Log[ArcSinh[Sinh[x]]]*(-ArcSinh[Sinh[x]] + x*Sqrt[Cosh[x]^2]*Sech[x])}
