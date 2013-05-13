(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Inverse Sines*)


(* ::Section::Closed:: *)
(*Integrands of the form u ArcSin[a x^n]^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcSin[a x]^n*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{x^m*ArcSin[a*x], x, 2, (x^(1 + m)*ArcSin[a*x])/(1 + m) - (a*x^(2 + m)*Hypergeometric2F1[1/2, (2 + m)/2, (4 + m)/2, a^2*x^2])/(2 + 3*m + m^2)}

{x^4*ArcSin[a*x], x, 4, (8*Sqrt[1 - a^2*x^2])/(75*a^5) + (4*x^2*Sqrt[1 - a^2*x^2])/(75*a^3) + (x^4*Sqrt[1 - a^2*x^2])/(25*a) + (1/5)*x^5*ArcSin[a*x]}
{x^3*ArcSin[a*x], x, 4, (3*x*Sqrt[1 - a^2*x^2])/(32*a^3) + (x^3*Sqrt[1 - a^2*x^2])/(16*a) - (3*ArcSin[a*x])/(32*a^4) + (1/4)*x^4*ArcSin[a*x]}
{x^2*ArcSin[a*x], x, 3, (2*Sqrt[1 - a^2*x^2])/(9*a^3) + (x^2*Sqrt[1 - a^2*x^2])/(9*a) + (1/3)*x^3*ArcSin[a*x]}
{x^1*ArcSin[a*x], x, 3, (x*Sqrt[1 - a^2*x^2])/(4*a) - ArcSin[a*x]/(4*a^2) + (1/2)*x^2*ArcSin[a*x]}
{x^0*ArcSin[a*x], x, 1, Sqrt[1 - a^2*x^2]/a + x*ArcSin[a*x]}
{ArcSin[a*x]/x^1, x, 5, (-(1/2))*I*ArcSin[a*x]^2 + ArcSin[a*x]*Log[1 - E^(2*I*ArcSin[a*x])] - (1/2)*I*PolyLog[2, E^(2*I*ArcSin[a*x])]}
{ArcSin[a*x]/x^2, x, 3, -(ArcSin[a*x]/x) - a*ArcTanh[Sqrt[1 - a^2*x^2]]}
{ArcSin[a*x]/x^3, x, 2, -((a*Sqrt[1 - a^2*x^2])/(2*x)) - ArcSin[a*x]/(2*x^2)}
{ArcSin[a*x]/x^4, x, 4, -((a*Sqrt[1 - a^2*x^2])/(6*x^2)) - ArcSin[a*x]/(3*x^3) - (1/6)*a^3*ArcTanh[Sqrt[1 - a^2*x^2]]}
{ArcSin[a*x]/x^5, x, 3, -((a*Sqrt[1 - a^2*x^2])/(12*x^3)) - (a^3*Sqrt[1 - a^2*x^2])/(6*x) - ArcSin[a*x]/(4*x^4)}
{ArcSin[a*x]/x^6, x, 5, -((a*Sqrt[1 - a^2*x^2])/(20*x^4)) - (3*a^3*Sqrt[1 - a^2*x^2])/(40*x^2) - ArcSin[a*x]/(5*x^5) - (3/40)*a^5*ArcTanh[Sqrt[1 - a^2*x^2]]}


{x^m*ArcSin[a*x]^2, x, 2, (x^(1 + m)*ArcSin[a*x]^2)/(1 + m) - (2*a*x^(2 + m)*ArcSin[a*x]*Hypergeometric2F1[1/2, (2 + m)/2, (4 + m)/2, a^2*x^2])/(2 + 3*m + m^2) + (2*a^2*x^(3 + m)*HypergeometricPFQ[{1, 3/2 + m/2, 3/2 + m/2}, {2 + m/2, 5/2 + m/2}, a^2*x^2])/(6 + 11*m + 6*m^2 + m^3)}

{x^4*ArcSin[a*x]^2, x, 7, -((16*x)/(75*a^4)) - (8*x^3)/(225*a^2) - (2*x^5)/125 + (16*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(75*a^5) + (8*x^2*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(75*a^3) + (2*x^4*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(25*a) + (1/5)*x^5*ArcSin[a*x]^2}
{x^3*ArcSin[a*x]^2, x, 6, -((3*x^2)/(32*a^2)) - x^4/32 + (3*x*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(16*a^3) + (x^3*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(8*a) - (3*ArcSin[a*x]^2)/(32*a^4) + (1/4)*x^4*ArcSin[a*x]^2}
{x^2*ArcSin[a*x]^2, x, 5, -((4*x)/(9*a^2)) - (2*x^3)/27 + (4*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(9*a^3) + (2*x^2*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(9*a) + (1/3)*x^3*ArcSin[a*x]^2}
{x^1*ArcSin[a*x]^2, x, 4, -(x^2/4) + (x*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(2*a) - ArcSin[a*x]^2/(4*a^2) + (1/2)*x^2*ArcSin[a*x]^2}
{x^0*ArcSin[a*x]^2, x, 2, -2*x + (2*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/a + x*ArcSin[a*x]^2}
{ArcSin[a*x]^2/x^1, x, 6, (-(1/3))*I*ArcSin[a*x]^3 + ArcSin[a*x]^2*Log[1 - E^(2*I*ArcSin[a*x])] - I*ArcSin[a*x]*PolyLog[2, E^(2*I*ArcSin[a*x])] + (1/2)*PolyLog[3, E^(2*I*ArcSin[a*x])]}
{ArcSin[a*x]^2/x^2, x, 2, -(ArcSin[a*x]^2/x) - 4*I*a*ArcSin[a*x]*ArcTan[a*x - I*Sqrt[1 - a^2*x^2]] + 2*I*a*PolyLog[2, (-I)*a*x - Sqrt[1 - a^2*x^2]] - 2*I*a*PolyLog[2, I*a*x + Sqrt[1 - a^2*x^2]]}
{ArcSin[a*x]^2/x^3, x, 3, -((a*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/x) - ArcSin[a*x]^2/(2*x^2) + a^2*Log[x]}
{ArcSin[a*x]^2/x^4, x, 4, -(a^2/(3*x)) - (a*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(3*x^2) - ArcSin[a*x]^2/(3*x^3) - (2/3)*I*a^3*ArcSin[a*x]*ArcTan[a*x - I*Sqrt[1 - a^2*x^2]] + (1/3)*I*a^3*PolyLog[2, (-I)*a*x - Sqrt[1 - a^2*x^2]] - (1/3)*I*a^3*PolyLog[2, I*a*x + Sqrt[1 - a^2*x^2]]}
{ArcSin[a*x]^2/x^5, x, 5, -(a^2/(12*x^2)) - (a*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(6*x^3) - (a^3*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(3*x) - ArcSin[a*x]^2/(4*x^4) + (1/3)*a^4*Log[x]}


{x^m*ArcSin[a*x]^3, x, 1, (x^(1 + m)*ArcSin[a*x]^3)/(1 + m) - (3*a*Int[(x^(1 + m)*ArcSin[a*x]^2)/Sqrt[1 - a^2*x^2], x])/(1 + m)}

{x^4*ArcSin[a*x]^3, x, 12, -((4144*Sqrt[1 - a^2*x^2])/(5625*a^5)) - (272*x^2*Sqrt[1 - a^2*x^2])/(5625*a^3) - (6*x^4*Sqrt[1 - a^2*x^2])/(625*a) - (16*x*ArcSin[a*x])/(25*a^4) - (8*x^3*ArcSin[a*x])/(75*a^2) - (6/125)*x^5*ArcSin[a*x] + (8*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^2)/(25*a^5) + (4*x^2*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^2)/(25*a^3) + (3*x^4*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^2)/(25*a) + (1/5)*x^5*ArcSin[a*x]^3}
{x^3*ArcSin[a*x]^3, x, 11, -((45*x*Sqrt[1 - a^2*x^2])/(256*a^3)) - (3*x^3*Sqrt[1 - a^2*x^2])/(128*a) + (45*ArcSin[a*x])/(256*a^4) - (9*x^2*ArcSin[a*x])/(32*a^2) - (3/32)*x^4*ArcSin[a*x] + (9*x*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^2)/(32*a^3) + (3*x^3*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^2)/(16*a) - (3*ArcSin[a*x]^3)/(32*a^4) + (1/4)*x^4*ArcSin[a*x]^3}
{x^2*ArcSin[a*x]^3, x, 7, -((40*Sqrt[1 - a^2*x^2])/(27*a^3)) - (2*x^2*Sqrt[1 - a^2*x^2])/(27*a) - (4*x*ArcSin[a*x])/(3*a^2) - (2/9)*x^3*ArcSin[a*x] + (2*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^2)/(3*a^3) + (x^2*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^2)/(3*a) + (1/3)*x^3*ArcSin[a*x]^3}
{x^1*ArcSin[a*x]^3, x, 6, -((3*x*Sqrt[1 - a^2*x^2])/(8*a)) + (3*ArcSin[a*x])/(8*a^2) - (3/4)*x^2*ArcSin[a*x] + (3*x*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^2)/(4*a) - ArcSin[a*x]^3/(4*a^2) + (1/2)*x^2*ArcSin[a*x]^3}
{x^0*ArcSin[a*x]^3, x, 2, -((6*Sqrt[1 - a^2*x^2])/a) - 6*x*ArcSin[a*x] + (3*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^2)/a + x*ArcSin[a*x]^3}
{ArcSin[a*x]^3/x^1, x, 7, (-(1/4))*I*ArcSin[a*x]^4 + ArcSin[a*x]^3*Log[1 - E^(2*I*ArcSin[a*x])] - (3/2)*I*ArcSin[a*x]^2*PolyLog[2, E^(2*I*ArcSin[a*x])] + (3/2)*ArcSin[a*x]*PolyLog[3, E^(2*I*ArcSin[a*x])] + (3/4)*I*PolyLog[4, E^(2*I*ArcSin[a*x])]}
{ArcSin[a*x]^3/x^2, x, 7, -(ArcSin[a*x]^3/x) - 6*a*ArcSin[a*x]^2*ArcTanh[E^(I*ArcSin[a*x])] + 6*I*a*ArcSin[a*x]*PolyLog[2, -E^(I*ArcSin[a*x])] - 6*I*a*ArcSin[a*x]*PolyLog[2, E^(I*ArcSin[a*x])] - 6*a*PolyLog[3, -E^(I*ArcSin[a*x])] + 6*a*PolyLog[3, E^(I*ArcSin[a*x])]}
{ArcSin[a*x]^3/x^3, x, 7, (-(3/2))*I*a^2*ArcSin[a*x]^2 - (3*a*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^2)/(2*x) - ArcSin[a*x]^3/(2*x^2) + 3*a^2*ArcSin[a*x]*Log[1 - E^(2*I*ArcSin[a*x])] - (3/2)*I*a^2*PolyLog[2, E^(2*I*ArcSin[a*x])]}
{ArcSin[a*x]^3/x^4, x, 11, -((a^2*ArcSin[a*x])/x) - (a*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^2)/(2*x^2) - ArcSin[a*x]^3/(3*x^3) - a^3*ArcSin[a*x]^2*ArcTanh[E^(I*ArcSin[a*x])] - a^3*ArcTanh[Sqrt[1 - a^2*x^2]] + I*a^3*ArcSin[a*x]*PolyLog[2, -E^(I*ArcSin[a*x])] - I*a^3*ArcSin[a*x]*PolyLog[2, E^(I*ArcSin[a*x])] - a^3*PolyLog[3, -E^(I*ArcSin[a*x])] + a^3*PolyLog[3, E^(I*ArcSin[a*x])]}
{ArcSin[a*x]^3/x^5, x, 10, -((a^3*Sqrt[1 - a^2*x^2])/(4*x)) - (a^2*ArcSin[a*x])/(4*x^2) - (1/2)*I*a^4*ArcSin[a*x]^2 - (a*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^2)/(4*x^3) - (a^3*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^2)/(2*x) - ArcSin[a*x]^3/(4*x^4) + a^4*ArcSin[a*x]*Log[1 - E^(2*I*ArcSin[a*x])] - (1/2)*I*a^4*PolyLog[2, E^(2*I*ArcSin[a*x])]}


{x^m*ArcSin[a*x]^4, x, 1, (x^(1 + m)*ArcSin[a*x]^4)/(1 + m) - (4*a*Int[(x^(1 + m)*ArcSin[a*x]^3)/Sqrt[1 - a^2*x^2], x])/(1 + m)}

{x^5*ArcSin[a*x]^4, x, 23, (245*x^2)/(1152*a^4) + (65*x^4)/(3456*a^2) + x^6/324 - (245*x*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(576*a^5) - (65*x^3*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(864*a^3) - (x^5*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(54*a) + (245*ArcSin[a*x]^2)/(1152*a^6) - (5*x^2*ArcSin[a*x]^2)/(16*a^4) - (5*x^4*ArcSin[a*x]^2)/(48*a^2) - (1/18)*x^6*ArcSin[a*x]^2 + (5*x*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^3)/(24*a^5) + (5*x^3*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^3)/(36*a^3) + (x^5*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^3)/(9*a) - (5*ArcSin[a*x]^4)/(96*a^6) + (1/6)*x^6*ArcSin[a*x]^4}
{x^4*ArcSin[a*x]^4, x, 18, (16576*x)/(5625*a^4) + (1088*x^3)/(16875*a^2) + (24*x^5)/3125 - (16576*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(5625*a^5) - (1088*x^2*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(5625*a^3) - (24*x^4*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(625*a) - (32*x*ArcSin[a*x]^2)/(25*a^4) - (16*x^3*ArcSin[a*x]^2)/(75*a^2) - (12/125)*x^5*ArcSin[a*x]^2 + (32*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^3)/(75*a^5) + (16*x^2*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^3)/(75*a^3) + (4*x^4*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^3)/(25*a) + (1/5)*x^5*ArcSin[a*x]^4}
{x^3*ArcSin[a*x]^4, x, 14, (45*x^2)/(128*a^2) + (3*x^4)/128 - (45*x*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(64*a^3) - (3*x^3*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(32*a) + (45*ArcSin[a*x]^2)/(128*a^4) - (9*x^2*ArcSin[a*x]^2)/(16*a^2) - (3/16)*x^4*ArcSin[a*x]^2 + (3*x*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^3)/(8*a^3) + (x^3*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^3)/(4*a) - (3*ArcSin[a*x]^4)/(32*a^4) + (1/4)*x^4*ArcSin[a*x]^4}
{x^2*ArcSin[a*x]^4, x, 10, (160*x)/(27*a^2) + (8*x^3)/81 - (160*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(27*a^3) - (8*x^2*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(27*a) - (8*x*ArcSin[a*x]^2)/(3*a^2) - (4/9)*x^3*ArcSin[a*x]^2 + (8*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^3)/(9*a^3) + (4*x^2*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^3)/(9*a) + (1/3)*x^3*ArcSin[a*x]^4}
{x^1*ArcSin[a*x]^4, x, 7, (3*x^2)/4 - (3*x*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(2*a) + (3*ArcSin[a*x]^2)/(4*a^2) - (3/2)*x^2*ArcSin[a*x]^2 + (x*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^3)/a - ArcSin[a*x]^4/(4*a^2) + (1/2)*x^2*ArcSin[a*x]^4}
{x^0*ArcSin[a*x]^4, x, 3, 24*x - (24*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/a - 12*x*ArcSin[a*x]^2 + (4*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^3)/a + x*ArcSin[a*x]^4}
{ArcSin[a*x]^4/x^1, x, 8, (-(1/5))*I*ArcSin[a*x]^5 + ArcSin[a*x]^4*Log[1 - E^(2*I*ArcSin[a*x])] - 2*I*ArcSin[a*x]^3*PolyLog[2, E^(2*I*ArcSin[a*x])] + 3*ArcSin[a*x]^2*PolyLog[3, E^(2*I*ArcSin[a*x])] + 3*I*ArcSin[a*x]*PolyLog[4, E^(2*I*ArcSin[a*x])] - (3/2)*PolyLog[5, E^(2*I*ArcSin[a*x])]}
{ArcSin[a*x]^4/x^2, x, 9, -(ArcSin[a*x]^4/x) - 8*a*ArcSin[a*x]^3*ArcTanh[E^(I*ArcSin[a*x])] + 12*I*a*ArcSin[a*x]^2*PolyLog[2, -E^(I*ArcSin[a*x])] - 12*I*a*ArcSin[a*x]^2*PolyLog[2, E^(I*ArcSin[a*x])] - 24*a*ArcSin[a*x]*PolyLog[3, -E^(I*ArcSin[a*x])] + 24*a*ArcSin[a*x]*PolyLog[3, E^(I*ArcSin[a*x])] - 24*I*a*PolyLog[4, -E^(I*ArcSin[a*x])] + 24*I*a*PolyLog[4, E^(I*ArcSin[a*x])]}
{ArcSin[a*x]^4/x^3, x, 8, -2*I*a^2*ArcSin[a*x]^3 - (2*a*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^3)/x - ArcSin[a*x]^4/(2*x^2) + 6*a^2*ArcSin[a*x]^2*Log[1 - E^(2*I*ArcSin[a*x])] - 6*I*a^2*ArcSin[a*x]*PolyLog[2, E^(2*I*ArcSin[a*x])] + 3*a^2*PolyLog[3, E^(2*I*ArcSin[a*x])]}
{ArcSin[a*x]^4/x^4, x, 12, -((2*a^2*ArcSin[a*x]^2)/x) - (2*a*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^3)/(3*x^2) - ArcSin[a*x]^4/(3*x^3) - 8*I*a^3*ArcSin[a*x]*ArcTan[a*x - I*Sqrt[1 - a^2*x^2]] - (4/3)*a^3*ArcSin[a*x]^3*ArcTanh[E^(I*ArcSin[a*x])] + 2*I*a^3*ArcSin[a*x]^2*PolyLog[2, -E^(I*ArcSin[a*x])] - 2*I*a^3*ArcSin[a*x]^2*PolyLog[2, E^(I*ArcSin[a*x])] + 4*I*a^3*PolyLog[2, (-I)*a*x - Sqrt[1 - a^2*x^2]] - 4*I*a^3*PolyLog[2, I*a*x + Sqrt[1 - a^2*x^2]] - 4*a^3*ArcSin[a*x]*PolyLog[3, -E^(I*ArcSin[a*x])] + 4*a^3*ArcSin[a*x]*PolyLog[3, E^(I*ArcSin[a*x])] - 4*I*a^3*PolyLog[4, -E^(I*ArcSin[a*x])] + 4*I*a^3*PolyLog[4, E^(I*ArcSin[a*x])]}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{x^m/ArcSin[a*x], x, 0, Int[x^m/ArcSin[a*x], x]}

{x^6/ArcSin[a*x], x, 7, (5*CosIntegral[ArcSin[a*x]])/(64*a^7) - (9*CosIntegral[3*ArcSin[a*x]])/(64*a^7) + (5*CosIntegral[5*ArcSin[a*x]])/(64*a^7) - CosIntegral[7*ArcSin[a*x]]/(64*a^7)}
{x^5/ArcSin[a*x], x, 6, (5*SinIntegral[2*ArcSin[a*x]])/(32*a^6) - SinIntegral[4*ArcSin[a*x]]/(8*a^6) + SinIntegral[6*ArcSin[a*x]]/(32*a^6)}
{x^4/ArcSin[a*x], x, 6, CosIntegral[ArcSin[a*x]]/(8*a^5) - (3*CosIntegral[3*ArcSin[a*x]])/(16*a^5) + CosIntegral[5*ArcSin[a*x]]/(16*a^5)}
{x^3/ArcSin[a*x], x, 5, SinIntegral[2*ArcSin[a*x]]/(4*a^4) - SinIntegral[4*ArcSin[a*x]]/(8*a^4)}
{x^2/ArcSin[a*x], x, 5, CosIntegral[ArcSin[a*x]]/(4*a^3) - CosIntegral[3*ArcSin[a*x]]/(4*a^3)}
{x^1/ArcSin[a*x], x, 4, SinIntegral[2*ArcSin[a*x]]/(2*a^2)}
{x^0/ArcSin[a*x], x, 2, CosIntegral[ArcSin[a*x]]/a}
{1/(x^1*ArcSin[a*x]), x, 0, Int[1/(x*ArcSin[a*x]), x]}
{1/(x^2*ArcSin[a*x]), x, 0, Int[1/(x^2*ArcSin[a*x]), x]}


{x^m/ArcSin[a*x]^2, x, 0, Int[x^m/ArcSin[a*x]^2, x]}

{x^6/ArcSin[a*x]^2, x, 6, -((x^6*Sqrt[1 - a^2*x^2])/(a*ArcSin[a*x])) - (5*SinIntegral[ArcSin[a*x]])/(64*a^7) + (27*SinIntegral[3*ArcSin[a*x]])/(64*a^7) - (25*SinIntegral[5*ArcSin[a*x]])/(64*a^7) + (7*SinIntegral[7*ArcSin[a*x]])/(64*a^7)}
{x^5/ArcSin[a*x]^2, x, 5, -((x^5*Sqrt[1 - a^2*x^2])/(a*ArcSin[a*x])) + (5*CosIntegral[2*ArcSin[a*x]])/(16*a^6) - CosIntegral[4*ArcSin[a*x]]/(2*a^6) + (3*CosIntegral[6*ArcSin[a*x]])/(16*a^6)}
{x^4/ArcSin[a*x]^2, x, 5, -((x^4*Sqrt[1 - a^2*x^2])/(a*ArcSin[a*x])) - SinIntegral[ArcSin[a*x]]/(8*a^5) + (9*SinIntegral[3*ArcSin[a*x]])/(16*a^5) - (5*SinIntegral[5*ArcSin[a*x]])/(16*a^5)}
{x^3/ArcSin[a*x]^2, x, 4, -((x^3*Sqrt[1 - a^2*x^2])/(a*ArcSin[a*x])) + CosIntegral[2*ArcSin[a*x]]/(2*a^4) - CosIntegral[4*ArcSin[a*x]]/(2*a^4)}
{x^2/ArcSin[a*x]^2, x, 4, -((x^2*Sqrt[1 - a^2*x^2])/(a*ArcSin[a*x])) - SinIntegral[ArcSin[a*x]]/(4*a^3) + (3*SinIntegral[3*ArcSin[a*x]])/(4*a^3)}
{x^1/ArcSin[a*x]^2, x, 2, -((x*Sqrt[1 - a^2*x^2])/(a*ArcSin[a*x])) + CosIntegral[2*ArcSin[a*x]]/a^2}
{x^0/ArcSin[a*x]^2, x, 4, -(Sqrt[1 - a^2*x^2]/(a*ArcSin[a*x])) - SinIntegral[ArcSin[a*x]]/a}
{1/(x^1*ArcSin[a*x]^2), x, 0, Int[1/(x*ArcSin[a*x]^2), x]}
{1/(x^2*ArcSin[a*x]^2), x, 0, Int[1/(x^2*ArcSin[a*x]^2), x]}


{x^m/ArcSin[a*x]^3, x, 0, Int[x^m/ArcSin[a*x]^3, x]}

{x^4/ArcSin[a*x]^3, x, 12, -((x^4*Sqrt[1 - a^2*x^2])/(2*a*ArcSin[a*x]^2)) - (2*x^3)/(a^2*ArcSin[a*x]) + (5*x^5)/(2*ArcSin[a*x]) - CosIntegral[ArcSin[a*x]]/(16*a^5) + (27*CosIntegral[3*ArcSin[a*x]])/(32*a^5) - (25*CosIntegral[5*ArcSin[a*x]])/(32*a^5)}
{x^3/ArcSin[a*x]^3, x, 10, -((x^3*Sqrt[1 - a^2*x^2])/(2*a*ArcSin[a*x]^2)) - (3*x^2)/(2*a^2*ArcSin[a*x]) + (2*x^4)/ArcSin[a*x] - SinIntegral[2*ArcSin[a*x]]/(2*a^4) + SinIntegral[4*ArcSin[a*x]]/a^4}
{x^2/ArcSin[a*x]^3, x, 8, -((x^2*Sqrt[1 - a^2*x^2])/(2*a*ArcSin[a*x]^2)) - x/(a^2*ArcSin[a*x]) + (3*x^3)/(2*ArcSin[a*x]) - CosIntegral[ArcSin[a*x]]/(8*a^3) + (9*CosIntegral[3*ArcSin[a*x]])/(8*a^3)}
{x^1/ArcSin[a*x]^3, x, 6, -((x*Sqrt[1 - a^2*x^2])/(2*a*ArcSin[a*x]^2)) - 1/(2*a^2*ArcSin[a*x]) + x^2/ArcSin[a*x] - SinIntegral[2*ArcSin[a*x]]/a^2}
{x^0/ArcSin[a*x]^3, x, 3, -(Sqrt[1 - a^2*x^2]/(2*a*ArcSin[a*x]^2)) + x/(2*ArcSin[a*x]) - CosIntegral[ArcSin[a*x]]/(2*a)}
{1/(x^1*ArcSin[a*x]^3), x, 0, Int[1/(x*ArcSin[a*x]^3), x]}
{1/(x^2*ArcSin[a*x]^3), x, 0, Int[1/(x^2*ArcSin[a*x]^3), x]}


{x^m/ArcSin[a*x]^4, x, 0, Int[x^m/ArcSin[a*x]^4, x]}

{x^4/ArcSin[a*x]^4, x, 10, -((x^4*Sqrt[1 - a^2*x^2])/(3*a*ArcSin[a*x]^3)) - (2*x^3)/(3*a^2*ArcSin[a*x]^2) + (5*x^5)/(6*ArcSin[a*x]^2) - (2*x^2*Sqrt[1 - a^2*x^2])/(a^3*ArcSin[a*x]) + (25*x^4*Sqrt[1 - a^2*x^2])/(6*a*ArcSin[a*x]) + SinIntegral[ArcSin[a*x]]/(48*a^5) - (27*SinIntegral[3*ArcSin[a*x]])/(32*a^5) + (125*SinIntegral[5*ArcSin[a*x]])/(96*a^5)}
{x^3/ArcSin[a*x]^4, x, 7, -((x^3*Sqrt[1 - a^2*x^2])/(3*a*ArcSin[a*x]^3)) - x^2/(2*a^2*ArcSin[a*x]^2) + (2*x^4)/(3*ArcSin[a*x]^2) - (x*Sqrt[1 - a^2*x^2])/(a^3*ArcSin[a*x]) + (8*x^3*Sqrt[1 - a^2*x^2])/(3*a*ArcSin[a*x]) - CosIntegral[2*ArcSin[a*x]]/(3*a^4) + (4*CosIntegral[4*ArcSin[a*x]])/(3*a^4)}
{x^2/ArcSin[a*x]^4, x, 9, -((x^2*Sqrt[1 - a^2*x^2])/(3*a*ArcSin[a*x]^3)) - x/(3*a^2*ArcSin[a*x]^2) + x^3/(2*ArcSin[a*x]^2) - Sqrt[1 - a^2*x^2]/(3*a^3*ArcSin[a*x]) + (3*x^2*Sqrt[1 - a^2*x^2])/(2*a*ArcSin[a*x]) + SinIntegral[ArcSin[a*x]]/(24*a^3) - (9*SinIntegral[3*ArcSin[a*x]])/(8*a^3)}
{x^1/ArcSin[a*x]^4, x, 4, -((x*Sqrt[1 - a^2*x^2])/(3*a*ArcSin[a*x]^3)) - 1/(6*a^2*ArcSin[a*x]^2) + x^2/(3*ArcSin[a*x]^2) + (2*x*Sqrt[1 - a^2*x^2])/(3*a*ArcSin[a*x]) - (2*CosIntegral[2*ArcSin[a*x]])/(3*a^2)}
{x^0/ArcSin[a*x]^4, x, 5, -(Sqrt[1 - a^2*x^2]/(3*a*ArcSin[a*x]^3)) + x/(6*ArcSin[a*x]^2) + Sqrt[1 - a^2*x^2]/(6*a*ArcSin[a*x]) + SinIntegral[ArcSin[a*x]]/(6*a)}
{1/(x^1*ArcSin[a*x]^4), x, 0, Int[1/(x*ArcSin[a*x]^4), x]}
{1/(x^2*ArcSin[a*x]^4), x, 0, Int[1/(x^2*ArcSin[a*x]^4), x]}


(* ::Subsubsection::Closed:: *)
(*n/2>0*)


{x^m*Sqrt[ArcSin[a*x]], x, 1, (x^(1 + m)*Sqrt[ArcSin[a*x]])/(1 + m) - (a*Int[x^(1 + m)/(Sqrt[1 - a^2*x^2]*Sqrt[ArcSin[a*x]]), x])/(2*(1 + m))}

{x^4*Sqrt[ArcSin[a*x]], x, 7, (1/5)*x^5*Sqrt[ArcSin[a*x]] - (Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(8*a^5) + (Sqrt[Pi/6]*FresnelS[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/(16*a^5) - (Sqrt[Pi/10]*FresnelS[Sqrt[10/Pi]*Sqrt[ArcSin[a*x]]])/(80*a^5)}
{x^3*Sqrt[ArcSin[a*x]], x, 6, -((3*Sqrt[ArcSin[a*x]])/(32*a^4)) + (1/4)*x^4*Sqrt[ArcSin[a*x]] - (Sqrt[Pi/2]*FresnelC[2*Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(64*a^4) + (Sqrt[Pi]*FresnelC[(2*Sqrt[ArcSin[a*x]])/Sqrt[Pi]])/(16*a^4)}
{x^2*Sqrt[ArcSin[a*x]], x, 6, (1/3)*x^3*Sqrt[ArcSin[a*x]] - (Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(4*a^3) + (Sqrt[Pi/6]*FresnelS[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/(12*a^3)}
{x^1*Sqrt[ArcSin[a*x]], x, 5, -(Sqrt[ArcSin[a*x]]/(4*a^2)) + (1/2)*x^2*Sqrt[ArcSin[a*x]] + (Sqrt[Pi]*FresnelC[(2*Sqrt[ArcSin[a*x]])/Sqrt[Pi]])/(8*a^2)}
{x^0*Sqrt[ArcSin[a*x]], x, 4, x*Sqrt[ArcSin[a*x]] - (Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/a}
{Sqrt[ArcSin[a*x]]/x^1, x, 0, Int[Sqrt[ArcSin[a*x]]/x, x]}


{x^m*ArcSin[a*x]^(3/2), x, 1, (x^(1 + m)*ArcSin[a*x]^(3/2))/(1 + m) - (3*a*Int[(x^(1 + m)*Sqrt[ArcSin[a*x]])/Sqrt[1 - a^2*x^2], x])/(2*(1 + m))}

{x^4*ArcSin[a*x]^(3/2), x, 18, (4*Sqrt[1 - a^2*x^2]*Sqrt[ArcSin[a*x]])/(25*a^5) + (2*x^2*Sqrt[1 - a^2*x^2]*Sqrt[ArcSin[a*x]])/(25*a^3) + (3*x^4*Sqrt[1 - a^2*x^2]*Sqrt[ArcSin[a*x]])/(50*a) + (1/5)*x^5*ArcSin[a*x]^(3/2) - (3*Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(16*a^5) + (Sqrt[Pi/6]*FresnelC[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/(32*a^5) - (3*Sqrt[Pi/10]*FresnelC[Sqrt[10/Pi]*Sqrt[ArcSin[a*x]]])/(800*a^5), (4*Sqrt[1 - a^2*x^2]*Sqrt[ArcSin[a*x]])/(25*a^5) + (2*x^2*Sqrt[1 - a^2*x^2]*Sqrt[ArcSin[a*x]])/(25*a^3) + (3*x^4*Sqrt[1 - a^2*x^2]*Sqrt[ArcSin[a*x]])/(50*a) + (1/5)*x^5*ArcSin[a*x]^(3/2) - (11*Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(400*a^5) - (2*Sqrt[2*Pi]*FresnelC[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(25*a^5) + (Sqrt[Pi/6]*FresnelC[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/(50*a^5) + (3*Sqrt[(3*Pi)/2]*FresnelC[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/(800*a^5) - (3*Sqrt[Pi/10]*FresnelC[Sqrt[10/Pi]*Sqrt[ArcSin[a*x]]])/(800*a^5)}
{x^3*ArcSin[a*x]^(3/2), x, 12, (9*x*Sqrt[1 - a^2*x^2]*Sqrt[ArcSin[a*x]])/(64*a^3) + (3*x^3*Sqrt[1 - a^2*x^2]*Sqrt[ArcSin[a*x]])/(32*a) - (3*ArcSin[a*x]^(3/2))/(32*a^4) + (1/4)*x^4*ArcSin[a*x]^(3/2) + (3*Sqrt[Pi/2]*FresnelS[2*Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(512*a^4) - (3*Sqrt[Pi]*FresnelS[(2*Sqrt[ArcSin[a*x]])/Sqrt[Pi]])/(64*a^4)}
{x^2*ArcSin[a*x]^(3/2), x, 11, (Sqrt[1 - a^2*x^2]*Sqrt[ArcSin[a*x]])/(3*a^3) + (x^2*Sqrt[1 - a^2*x^2]*Sqrt[ArcSin[a*x]])/(6*a) + (1/3)*x^3*ArcSin[a*x]^(3/2) - (3*Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(8*a^3) + (Sqrt[Pi/6]*FresnelC[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/(24*a^3)}
{x^1*ArcSin[a*x]^(3/2), x, 6, (3*x*Sqrt[1 - a^2*x^2]*Sqrt[ArcSin[a*x]])/(8*a) - ArcSin[a*x]^(3/2)/(4*a^2) + (1/2)*x^2*ArcSin[a*x]^(3/2) - (3*Sqrt[Pi]*FresnelS[(2*Sqrt[ArcSin[a*x]])/Sqrt[Pi]])/(32*a^2)}
{x^0*ArcSin[a*x]^(3/2), x, 4, (3*Sqrt[1 - a^2*x^2]*Sqrt[ArcSin[a*x]])/(2*a) + x*ArcSin[a*x]^(3/2) - (3*Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(2*a)}
{ArcSin[a*x]^(3/2)/x^1, x, 0, Int[ArcSin[a*x]^(3/2)/x, x]}


{x^m*ArcSin[a*x]^(5/2), x, 1, (x^(1 + m)*ArcSin[a*x]^(5/2))/(1 + m) - (5*a*Int[(x^(1 + m)*ArcSin[a*x]^(3/2))/Sqrt[1 - a^2*x^2], x])/(2*(1 + m))}

{x^4*ArcSin[a*x]^(5/2), x, 21, -((2*x*Sqrt[ArcSin[a*x]])/(5*a^4)) - (x^3*Sqrt[ArcSin[a*x]])/(15*a^2) - (3/100)*x^5*Sqrt[ArcSin[a*x]] + (4*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^(3/2))/(15*a^5) + (2*x^2*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^(3/2))/(15*a^3) + (x^4*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^(3/2))/(10*a) + (1/5)*x^5*ArcSin[a*x]^(5/2) + (15*Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(32*a^5) - (5*Sqrt[Pi/6]*FresnelS[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/(192*a^5) + (3*Sqrt[Pi/10]*FresnelS[Sqrt[10/Pi]*Sqrt[ArcSin[a*x]]])/(1600*a^5), -((2*x*Sqrt[ArcSin[a*x]])/(5*a^4)) - (x^3*Sqrt[ArcSin[a*x]])/(15*a^2) - (3/100)*x^5*Sqrt[ArcSin[a*x]] + (4*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^(3/2))/(15*a^5) + (2*x^2*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^(3/2))/(15*a^3) + (x^4*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^(3/2))/(10*a) + (1/5)*x^5*ArcSin[a*x]^(5/2) + (15*Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(32*a^5) - (Sqrt[Pi/6]*FresnelS[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/(60*a^5) - (Sqrt[(3*Pi)/2]*FresnelS[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/(320*a^5) + (3*Sqrt[Pi/10]*FresnelS[Sqrt[10/Pi]*Sqrt[ArcSin[a*x]]])/(1600*a^5)}
{x^3*ArcSin[a*x]^(5/2), x, 15, (225*Sqrt[ArcSin[a*x]])/(2048*a^4) - (45*x^2*Sqrt[ArcSin[a*x]])/(256*a^2) - (15/256)*x^4*Sqrt[ArcSin[a*x]] + (15*x*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^(3/2))/(64*a^3) + (5*x^3*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^(3/2))/(32*a) - (3*ArcSin[a*x]^(5/2))/(32*a^4) + (1/4)*x^4*ArcSin[a*x]^(5/2) + (15*Sqrt[Pi/2]*FresnelC[2*Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(4096*a^4) - (15*Sqrt[Pi]*FresnelC[(2*Sqrt[ArcSin[a*x]])/Sqrt[Pi]])/(256*a^4)}
{x^2*ArcSin[a*x]^(5/2), x, 13, -((5*x*Sqrt[ArcSin[a*x]])/(6*a^2)) - (5/36)*x^3*Sqrt[ArcSin[a*x]] + (5*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^(3/2))/(9*a^3) + (5*x^2*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^(3/2))/(18*a) + (1/3)*x^3*ArcSin[a*x]^(5/2) + (15*Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(16*a^3) - (5*Sqrt[Pi/6]*FresnelS[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/(144*a^3)}
{x^1*ArcSin[a*x]^(5/2), x, 8, (15*Sqrt[ArcSin[a*x]])/(64*a^2) - (15/32)*x^2*Sqrt[ArcSin[a*x]] + (5*x*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^(3/2))/(8*a) - ArcSin[a*x]^(5/2)/(4*a^2) + (1/2)*x^2*ArcSin[a*x]^(5/2) - (15*Sqrt[Pi]*FresnelC[(2*Sqrt[ArcSin[a*x]])/Sqrt[Pi]])/(128*a^2)}
{x^0*ArcSin[a*x]^(5/2), x, 5, (-(15/4))*x*Sqrt[ArcSin[a*x]] + (5*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^(3/2))/(2*a) + x*ArcSin[a*x]^(5/2) + (15*Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(4*a)}
{ArcSin[a*x]^(5/2)/x^1, x, 0, Int[ArcSin[a*x]^(5/2)/x, x]}


(* ::Subsubsection::Closed:: *)
(*n/2<0*)


{x^m/Sqrt[ArcSin[a*x]], x, 0, Int[x^m/Sqrt[ArcSin[a*x]], x]}

{x^4/Sqrt[ArcSin[a*x]], x, 6, (Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(4*a^5) - (Sqrt[(3*Pi)/2]*FresnelC[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/(8*a^5) + (Sqrt[Pi/10]*FresnelC[Sqrt[10/Pi]*Sqrt[ArcSin[a*x]]])/(8*a^5)}
{x^3/Sqrt[ArcSin[a*x]], x, 5, -((Sqrt[Pi/2]*FresnelS[2*Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(8*a^4)) + (Sqrt[Pi]*FresnelS[(2*Sqrt[ArcSin[a*x]])/Sqrt[Pi]])/(4*a^4)}
{x^2/Sqrt[ArcSin[a*x]], x, 5, (Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(2*a^3) - (Sqrt[Pi/6]*FresnelC[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/(2*a^3)}
{x^1/Sqrt[ArcSin[a*x]], x, 3, (Sqrt[Pi]*FresnelS[(2*Sqrt[ArcSin[a*x]])/Sqrt[Pi]])/(2*a^2)}
{x^0/Sqrt[ArcSin[a*x]], x, 3, (Sqrt[2*Pi]*FresnelC[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/a}
{1/(x^1*Sqrt[ArcSin[a*x]]), x, 0, Int[1/(x*Sqrt[ArcSin[a*x]]), x]}
{1/(x^2*Sqrt[ArcSin[a*x]]), x, 0, Int[1/(x^2*Sqrt[ArcSin[a*x]]), x]}


{x^m/ArcSin[a*x]^(3/2), x, 0, Int[x^m/ArcSin[a*x]^(3/2), x]}

{x^6/ArcSin[a*x]^(3/2), x, 7, -((2*x^6*Sqrt[1 - a^2*x^2])/(a*Sqrt[ArcSin[a*x]])) - (5*Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(16*a^7) + (9*Sqrt[(3*Pi)/2]*FresnelS[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/(16*a^7) - (5*Sqrt[(5*Pi)/2]*FresnelS[Sqrt[10/Pi]*Sqrt[ArcSin[a*x]]])/(16*a^7) + (Sqrt[(7*Pi)/2]*FresnelS[Sqrt[14/Pi]*Sqrt[ArcSin[a*x]]])/(16*a^7)}
{x^5/ArcSin[a*x]^(3/2), x, 6, -((2*x^5*Sqrt[1 - a^2*x^2])/(a*Sqrt[ArcSin[a*x]])) - (Sqrt[Pi/2]*FresnelC[2*Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/a^6 + (Sqrt[3*Pi]*FresnelC[2*Sqrt[3/Pi]*Sqrt[ArcSin[a*x]]])/(8*a^6) + (5*Sqrt[Pi]*FresnelC[(2*Sqrt[ArcSin[a*x]])/Sqrt[Pi]])/(8*a^6)}
{x^4/ArcSin[a*x]^(3/2), x, 6, -((2*x^4*Sqrt[1 - a^2*x^2])/(a*Sqrt[ArcSin[a*x]])) - (Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(2*a^5) + (3*Sqrt[(3*Pi)/2]*FresnelS[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/(4*a^5) - (Sqrt[(5*Pi)/2]*FresnelS[Sqrt[10/Pi]*Sqrt[ArcSin[a*x]]])/(4*a^5)}
{x^3/ArcSin[a*x]^(3/2), x, 5, -((2*x^3*Sqrt[1 - a^2*x^2])/(a*Sqrt[ArcSin[a*x]])) - (Sqrt[Pi/2]*FresnelC[2*Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/a^4 + (Sqrt[Pi]*FresnelC[(2*Sqrt[ArcSin[a*x]])/Sqrt[Pi]])/a^4}
{x^2/ArcSin[a*x]^(3/2), x, 5, -((2*x^2*Sqrt[1 - a^2*x^2])/(a*Sqrt[ArcSin[a*x]])) - (Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/a^3 + (Sqrt[(3*Pi)/2]*FresnelS[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/a^3}
{x^1/ArcSin[a*x]^(3/2), x, 2, -((2*x*Sqrt[1 - a^2*x^2])/(a*Sqrt[ArcSin[a*x]])) + (2*Sqrt[Pi]*FresnelC[(2*Sqrt[ArcSin[a*x]])/Sqrt[Pi]])/a^2}
{x^0/ArcSin[a*x]^(3/2), x, 4, -((2*Sqrt[1 - a^2*x^2])/(a*Sqrt[ArcSin[a*x]])) - (2*Sqrt[2*Pi]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/a}
{1/(x^1*ArcSin[a*x]^(3/2)), x, 0, Int[1/(x*ArcSin[a*x]^(3/2)), x]}


{x^m/ArcSin[a*x]^(5/2), x, 0, Int[x^m/ArcSin[a*x]^(5/2), x]}

{x^4/ArcSin[a*x]^(5/2), x, 12, -((2*x^4*Sqrt[1 - a^2*x^2])/(3*a*ArcSin[a*x]^(3/2))) - (16*x^3)/(3*a^2*Sqrt[ArcSin[a*x]]) + (20*x^5)/(3*Sqrt[ArcSin[a*x]]) - (Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(3*a^5) + (3*Sqrt[(3*Pi)/2]*FresnelC[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/(2*a^5) - (5*Sqrt[(5*Pi)/2]*FresnelC[Sqrt[10/Pi]*Sqrt[ArcSin[a*x]]])/(6*a^5), -((2*x^4*Sqrt[1 - a^2*x^2])/(3*a*ArcSin[a*x]^(3/2))) - (16*x^3)/(3*a^2*Sqrt[ArcSin[a*x]]) + (20*x^5)/(3*Sqrt[ArcSin[a*x]]) - (25*Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(3*a^5) + (4*Sqrt[2*Pi]*FresnelC[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/a^5 + (25*Sqrt[Pi/6]*FresnelC[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/(2*a^5) - (4*Sqrt[(2*Pi)/3]*FresnelC[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/a^5 - (5*Sqrt[(5*Pi)/2]*FresnelC[Sqrt[10/Pi]*Sqrt[ArcSin[a*x]]])/(6*a^5)}
{x^3/ArcSin[a*x]^(5/2), x, 9, -((2*x^3*Sqrt[1 - a^2*x^2])/(3*a*ArcSin[a*x]^(3/2))) - (4*x^2)/(a^2*Sqrt[ArcSin[a*x]]) + (16*x^4)/(3*Sqrt[ArcSin[a*x]]) + (4*Sqrt[2*Pi]*FresnelS[2*Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(3*a^4) - (4*Sqrt[Pi]*FresnelS[(2*Sqrt[ArcSin[a*x]])/Sqrt[Pi]])/(3*a^4)}
{x^2/ArcSin[a*x]^(5/2), x, 9, -((2*x^2*Sqrt[1 - a^2*x^2])/(3*a*ArcSin[a*x]^(3/2))) - (8*x)/(3*a^2*Sqrt[ArcSin[a*x]]) + (4*x^3)/Sqrt[ArcSin[a*x]] - (Sqrt[2*Pi]*FresnelC[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(3*a^3) + (Sqrt[6*Pi]*FresnelC[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/a^3}
{x^1/ArcSin[a*x]^(5/2), x, 5, -((2*x*Sqrt[1 - a^2*x^2])/(3*a*ArcSin[a*x]^(3/2))) - 4/(3*a^2*Sqrt[ArcSin[a*x]]) + (8*x^2)/(3*Sqrt[ArcSin[a*x]]) - (8*Sqrt[Pi]*FresnelS[(2*Sqrt[ArcSin[a*x]])/Sqrt[Pi]])/(3*a^2)}
{x^0/ArcSin[a*x]^(5/2), x, 4, -((2*Sqrt[1 - a^2*x^2])/(3*a*ArcSin[a*x]^(3/2))) + (4*x)/(3*Sqrt[ArcSin[a*x]]) - (4*Sqrt[2*Pi]*FresnelC[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(3*a)}
{1/(x^1*ArcSin[a*x]^(5/2)), x, 0, Int[1/(x*ArcSin[a*x]^(5/2)), x]}


{x^m/ArcSin[a*x]^(7/2), x, 0, Int[x^m/ArcSin[a*x]^(7/2), x]}

{x^4/ArcSin[a*x]^(7/2), x, 12, -((2*x^4*Sqrt[1 - a^2*x^2])/(5*a*ArcSin[a*x]^(5/2))) - (16*x^3)/(15*a^2*ArcSin[a*x]^(3/2)) + (4*x^5)/(3*ArcSin[a*x]^(3/2)) - (32*x^2*Sqrt[1 - a^2*x^2])/(5*a^3*Sqrt[ArcSin[a*x]]) + (40*x^4*Sqrt[1 - a^2*x^2])/(3*a*Sqrt[ArcSin[a*x]]) + (Sqrt[2*Pi]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(15*a^5) - (5*Sqrt[(3*Pi)/2]*FresnelS[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/a^5 + (8*Sqrt[6*Pi]*FresnelS[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/(5*a^5) + (5*Sqrt[(5*Pi)/2]*FresnelS[Sqrt[10/Pi]*Sqrt[ArcSin[a*x]]])/(3*a^5)}
{x^3/ArcSin[a*x]^(7/2), x, 8, -((2*x^3*Sqrt[1 - a^2*x^2])/(5*a*ArcSin[a*x]^(5/2))) - (4*x^2)/(5*a^2*ArcSin[a*x]^(3/2)) + (16*x^4)/(15*ArcSin[a*x]^(3/2)) - (16*x*Sqrt[1 - a^2*x^2])/(5*a^3*Sqrt[ArcSin[a*x]]) + (128*x^3*Sqrt[1 - a^2*x^2])/(15*a*Sqrt[ArcSin[a*x]]) + (32*Sqrt[2*Pi]*FresnelC[2*Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(15*a^4) - (16*Sqrt[Pi]*FresnelC[(2*Sqrt[ArcSin[a*x]])/Sqrt[Pi]])/(15*a^4)}
{x^2/ArcSin[a*x]^(7/2), x, 10, -((2*x^2*Sqrt[1 - a^2*x^2])/(5*a*ArcSin[a*x]^(5/2))) - (8*x)/(15*a^2*ArcSin[a*x]^(3/2)) + (4*x^3)/(5*ArcSin[a*x]^(3/2)) - (16*Sqrt[1 - a^2*x^2])/(15*a^3*Sqrt[ArcSin[a*x]]) + (24*x^2*Sqrt[1 - a^2*x^2])/(5*a*Sqrt[ArcSin[a*x]]) + (2*Sqrt[2*Pi]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(15*a^3) - (6*Sqrt[6*Pi]*FresnelS[Sqrt[6/Pi]*Sqrt[ArcSin[a*x]]])/(5*a^3)}
{x^1/ArcSin[a*x]^(7/2), x, 4, -((2*x*Sqrt[1 - a^2*x^2])/(5*a*ArcSin[a*x]^(5/2))) - 4/(15*a^2*ArcSin[a*x]^(3/2)) + (8*x^2)/(15*ArcSin[a*x]^(3/2)) + (32*x*Sqrt[1 - a^2*x^2])/(15*a*Sqrt[ArcSin[a*x]]) - (32*Sqrt[Pi]*FresnelC[(2*Sqrt[ArcSin[a*x]])/Sqrt[Pi]])/(15*a^2)}
{x^0/ArcSin[a*x]^(7/2), x, 5, -((2*Sqrt[1 - a^2*x^2])/(5*a*ArcSin[a*x]^(5/2))) + (4*x)/(15*ArcSin[a*x]^(3/2)) + (8*Sqrt[1 - a^2*x^2])/(15*a*Sqrt[ArcSin[a*x]]) + (8*Sqrt[2*Pi]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcSin[a*x]]])/(15*a)}
{1/(x^1*ArcSin[a*x]^(7/2)), x, 0, Int[1/(x*ArcSin[a*x]^(7/2)), x]}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{x^m*ArcSin[a*x]^n, x, 0, Int[x^m*ArcSin[a*x]^n, x]}

{x^4*ArcSin[a*x]^n, x, 13, (1/5)*x^5*ArcSin[a*x]^n - (I*n*ArcSin[a*x]^n*Gamma[n, (-I)*ArcSin[a*x]])/(((-I)*ArcSin[a*x])^n*(16*a^5)) + (I*n*ArcSin[a*x]^n*Gamma[n, I*ArcSin[a*x]])/((I*ArcSin[a*x])^n*(16*a^5)) + (I*n*ArcSin[a*x]^n*Gamma[n, -3*I*ArcSin[a*x]])/(3^n*((-I)*ArcSin[a*x])^n*(32*a^5)) - (I*n*ArcSin[a*x]^n*Gamma[n, 3*I*ArcSin[a*x]])/(3^n*(I*ArcSin[a*x])^n*(32*a^5)) - (I*5^(-1 - n)*n*ArcSin[a*x]^n*Gamma[n, -5*I*ArcSin[a*x]])/(((-I)*ArcSin[a*x])^n*(32*a^5)) + (I*5^(-1 - n)*n*ArcSin[a*x]^n*Gamma[n, 5*I*ArcSin[a*x]])/((I*ArcSin[a*x])^n*(32*a^5))}
{x^3*ArcSin[a*x]^n, x, 10, -((3*ArcSin[a*x]^n)/(32*a^4)) + (1/4)*x^4*ArcSin[a*x]^n - (2^(-4 - n)*n*ArcSin[a*x]^n*Gamma[n, -2*I*ArcSin[a*x]])/(((-I)*ArcSin[a*x])^n*a^4) - (2^(-4 - n)*n*ArcSin[a*x]^n*Gamma[n, 2*I*ArcSin[a*x]])/((I*ArcSin[a*x])^n*a^4) + (n*ArcSin[a*x]^n*Gamma[n, -4*I*ArcSin[a*x]])/(2^(2*(3 + n))*((-I)*ArcSin[a*x])^n*a^4) + (n*ArcSin[a*x]^n*Gamma[n, 4*I*ArcSin[a*x]])/(2^(2*(3 + n))*(I*ArcSin[a*x])^n*a^4)}
{x^2*ArcSin[a*x]^n, x, 10, (1/3)*x^3*ArcSin[a*x]^n - (I*n*ArcSin[a*x]^n*Gamma[n, (-I)*ArcSin[a*x]])/(((-I)*ArcSin[a*x])^n*(8*a^3)) + (I*n*ArcSin[a*x]^n*Gamma[n, I*ArcSin[a*x]])/((I*ArcSin[a*x])^n*(8*a^3)) + (I*3^(-1 - n)*n*ArcSin[a*x]^n*Gamma[n, -3*I*ArcSin[a*x]])/(((-I)*ArcSin[a*x])^n*(8*a^3)) - (I*3^(-1 - n)*n*ArcSin[a*x]^n*Gamma[n, 3*I*ArcSin[a*x]])/((I*ArcSin[a*x])^n*(8*a^3))}
{x^1*ArcSin[a*x]^n, x, 7, -(ArcSin[a*x]^n/(4*a^2)) + (1/2)*x^2*ArcSin[a*x]^n - (2^(-3 - n)*n*ArcSin[a*x]^n*Gamma[n, -2*I*ArcSin[a*x]])/(((-I)*ArcSin[a*x])^n*a^2) - (2^(-3 - n)*n*ArcSin[a*x]^n*Gamma[n, 2*I*ArcSin[a*x]])/((I*ArcSin[a*x])^n*a^2)}
{x^0*ArcSin[a*x]^n, x, 4, -((I*ArcSin[a*x]^n*Gamma[1 + n, (-I)*ArcSin[a*x]])/(((-I)*ArcSin[a*x])^n*(2*a))) + (I*ArcSin[a*x]^n*Gamma[1 + n, I*ArcSin[a*x]])/((I*ArcSin[a*x])^n*(2*a))}
{ArcSin[a*x]^n/x^1, x, 0, Int[ArcSin[a*x]^n/x, x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcSin[a x^n]*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{x^3*ArcSin[a*x^2], x, 5, (x^2*Sqrt[1 - a^2*x^4])/(8*a) - ArcSin[a*x^2]/(8*a^2) + (1/4)*x^4*ArcSin[a*x^2]}
{x^2*ArcSin[a*x^2], x, 4, (2*x*Sqrt[1 - a^2*x^4])/(9*a) + (1/3)*x^3*ArcSin[a*x^2] - (2*EllipticF[ArcSin[Sqrt[a]*x], -1])/(9*a^(3/2))}
{x^1*ArcSin[a*x^2], x, 2, Sqrt[1 - a^2*x^4]/(2*a) + (1/2)*x^2*ArcSin[a*x^2]}
{x^0*ArcSin[a*x^2], x, 3, x*ArcSin[a*x^2] - (2*EllipticE[ArcSin[Sqrt[a]*x], -1])/Sqrt[a] + (2*EllipticF[ArcSin[Sqrt[a]*x], -1])/Sqrt[a]}
{ArcSin[a*x^2]/x^1, x, 5, (-(1/4))*I*ArcSin[a*x^2]^2 + (1/2)*ArcSin[a*x^2]*Log[1 - E^(2*I*ArcSin[a*x^2])] - (1/4)*I*PolyLog[2, E^(2*I*ArcSin[a*x^2])]}
{ArcSin[a*x^2]/x^2, x, 3, -(ArcSin[a*x^2]/x) + 2*Sqrt[a]*EllipticF[ArcSin[Sqrt[a]*x], -1]}
{ArcSin[a*x^2]/x^3, x, 4, -(ArcSin[a*x^2]/(2*x^2)) - (1/2)*a*ArcTanh[Sqrt[1 - a^2*x^4]]}
{ArcSin[a*x^2]/x^4, x, 4, -((2*a*Sqrt[1 - a^2*x^4])/(3*x)) - ArcSin[a*x^2]/(3*x^3) - (2/3)*a^(3/2)*EllipticE[ArcSin[Sqrt[a]*x], -1] + (2/3)*a^(3/2)*EllipticF[ArcSin[Sqrt[a]*x], -1]}


{ArcSin[a*x^5]/x, x, 5, (-(1/10))*I*ArcSin[a*x^5]^2 + (1/5)*ArcSin[a*x^5]*Log[1 - E^(2*I*ArcSin[a*x^5])] - (1/10)*I*PolyLog[2, E^(2*I*ArcSin[a*x^5])]}


{x^2*ArcSin[Sqrt[x]], x, 6, (5/48)*Sqrt[1 - x]*Sqrt[x] + (5/72)*Sqrt[1 - x]*x^(3/2) + (1/18)*Sqrt[1 - x]*x^(5/2) + (5/96)*ArcSin[1 - 2*x] + (1/3)*x^3*ArcSin[Sqrt[x]]}
{x^1*ArcSin[Sqrt[x]], x, 5, (3/16)*Sqrt[1 - x]*Sqrt[x] + (1/8)*Sqrt[1 - x]*x^(3/2) + (3/32)*ArcSin[1 - 2*x] + (1/2)*x^2*ArcSin[Sqrt[x]]}
{x^0*ArcSin[Sqrt[x]], x, 4, (1/2)*Sqrt[1 - x]*Sqrt[x] + (1/4)*ArcSin[1 - 2*x] + x*ArcSin[Sqrt[x]]}
{ArcSin[Sqrt[x]]/x^1, x, 5, (-I)*ArcSin[Sqrt[x]]^2 + 2*ArcSin[Sqrt[x]]*Log[1 - E^(2*I*ArcSin[Sqrt[x]])] - I*PolyLog[2, E^(2*I*ArcSin[Sqrt[x]])]}
{ArcSin[Sqrt[x]]/x^2, x, 3, -(Sqrt[1 - x]/Sqrt[x]) - ArcSin[Sqrt[x]]/x}
{ArcSin[Sqrt[x]]/x^3, x, 4, -(Sqrt[1 - x]/(6*x^(3/2))) - Sqrt[1 - x]/(3*Sqrt[x]) - ArcSin[Sqrt[x]]/(2*x^2)}
{ArcSin[Sqrt[x]]/x^4, x, 5, -(Sqrt[1 - x]/(15*x^(5/2))) - (4*Sqrt[1 - x])/(45*x^(3/2)) - (8*Sqrt[1 - x])/(45*Sqrt[x]) - ArcSin[Sqrt[x]]/(3*x^3)}
{ArcSin[Sqrt[x]]/x^5, x, 6, -(Sqrt[1 - x]/(28*x^(7/2))) - (3*Sqrt[1 - x])/(70*x^(5/2)) - (2*Sqrt[1 - x])/(35*x^(3/2)) - (4*Sqrt[1 - x])/(35*Sqrt[x]) - ArcSin[Sqrt[x]]/(4*x^4)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{x^2*ArcSin[a/x], x, 5, (1/6)*a*Sqrt[1 - a^2/x^2]*x^2 + (1/3)*x^3*ArcCsc[x/a] + (1/6)*a^3*ArcTanh[Sqrt[1 - a^2/x^2]]}
{x^1*ArcSin[a/x], x, 3, (1/2)*a*Sqrt[1 - a^2/x^2]*x + (1/2)*x^2*ArcCsc[x/a]}
{x^0*ArcSin[a/x], x, 4, x*ArcCsc[x/a] + a*ArcTanh[Sqrt[1 - a^2/x^2]]}
{ArcSin[a/x]/x^1, x, 5, (1/2)*I*ArcSin[a/x]^2 - ArcSin[a/x]*Log[1 - E^(2*I*ArcSin[a/x])] + (1/2)*I*PolyLog[2, E^(2*I*ArcSin[a/x])]}
{ArcSin[a/x]/x^2, x, 3, -(Sqrt[1 - a^2/x^2]/a) - ArcCsc[x/a]/x}
{ArcSin[a/x]/x^3, x, 5, -(Sqrt[1 - a^2/x^2]/(4*a*x)) - ArcCsc[x/a]/(2*x^2) + ArcSin[a/x]/(4*a^2)}
{ArcSin[a/x]/x^4, x, 5, -((2*Sqrt[1 - a^2/x^2])/(9*a^3)) - Sqrt[1 - a^2/x^2]/(9*a*x^2) - ArcCsc[x/a]/(3*x^3)}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{x^m*ArcSin[a*x^n], x, 3, (x^(1 + m)*ArcSin[a*x^n])/(1 + m) - (a*n*x^(1 + m + n)*Hypergeometric2F1[1/2, (1 + m + n)/(2*n), (1 + m + 3*n)/(2*n), a^2*x^(2*n)])/((1 + m)*(1 + m + n))}

{x^2*ArcSin[a*x^n], x, 3, (1/3)*x^3*ArcSin[a*x^n] - (a*n*x^(3 + n)*Hypergeometric2F1[1/2, (3 + n)/(2*n), (3*(1 + n))/(2*n), a^2*x^(2*n)])/(3*(3 + n))}
{x^1*ArcSin[a*x^n], x, 3, (1/2)*x^2*ArcSin[a*x^n] - (a*n*x^(2 + n)*Hypergeometric2F1[1/2, (2 + n)/(2*n), (1/2)*(3 + 2/n), a^2*x^(2*n)])/(2*(2 + n))}
{x^0*ArcSin[a*x^n], x, 3, x*ArcSin[a*x^n] - (a*n*x^(1 + n)*Hypergeometric2F1[1/2, (1 + n)/(2*n), (1/2)*(3 + 1/n), a^2*x^(2*n)])/(1 + n)}
{ArcSin[a*x^n]/x^1, x, 5, -((I*ArcSin[a*x^n]^2)/(2*n)) + (ArcSin[a*x^n]*Log[1 - E^(2*I*ArcSin[a*x^n])])/n - (I*PolyLog[2, E^(2*I*ArcSin[a*x^n])])/(2*n)}
{ArcSin[a*x^n]/x^2, x, 3, -(ArcSin[a*x^n]/x) - (a*n*x^(-1 + n)*Hypergeometric2F1[1/2, -((1 - n)/(2*n)), (1/2)*(3 - 1/n), a^2*x^(2*n)])/(1 - n)}
{ArcSin[a*x^n]/x^3, x, 3, -(ArcSin[a*x^n]/(2*x^2)) - (a*n*x^(-2 + n)*Hypergeometric2F1[1/2, (1/2)*(1 - 2/n), (1/2)*(3 - 2/n), a^2*x^(2*n)])/(2*(2 - n))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcSin[a x]^p (1-a^2 x^2)^(n/2)*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{x^m*ArcSin[a*x]/Sqrt[1 - a^2*x^2], x, 1, (x^(1 + m)*ArcSin[a*x]*Hypergeometric2F1[1/2, (1 + m)/2, (3 + m)/2, a^2*x^2])/(1 + m) - (a*x^(2 + m)*HypergeometricPFQ[{1, 1 + m/2, 1 + m/2}, {3/2 + m/2, 2 + m/2}, a^2*x^2])/(2 + 3*m + m^2)}

{x^4*ArcSin[a*x]/Sqrt[1 - a^2*x^2], x, 5, (3*x^2)/(16*a^3) + x^4/(16*a) - (3*x*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(8*a^4) - (x^3*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(4*a^2) + (3*ArcSin[a*x]^2)/(16*a^5)}
{x^3*ArcSin[a*x]/Sqrt[1 - a^2*x^2], x, 4, (2*x)/(3*a^3) + x^3/(9*a) - (2*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(3*a^4) - (x^2*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(3*a^2)}
{x^2*ArcSin[a*x]/Sqrt[1 - a^2*x^2], x, 3, x^2/(4*a) - (x*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(2*a^2) + ArcSin[a*x]^2/(4*a^3)}
{x^1*ArcSin[a*x]/Sqrt[1 - a^2*x^2], x, 2, x/a - (Sqrt[1 - a^2*x^2]*ArcSin[a*x])/a^2}
{x^0*ArcSin[a*x]/Sqrt[1 - a^2*x^2], x, 1, ArcSin[a*x]^2/(2*a)}
{ArcSin[a*x]/(x^1*Sqrt[1 - a^2*x^2]), x, 1, -2*I*ArcSin[a*x]*ArcTan[a*x - I*Sqrt[1 - a^2*x^2]] + I*PolyLog[2, (-I)*a*x - Sqrt[1 - a^2*x^2]] - I*PolyLog[2, I*a*x + Sqrt[1 - a^2*x^2]]}
{ArcSin[a*x]/(x^2*Sqrt[1 - a^2*x^2]), x, 2, -((Sqrt[1 - a^2*x^2]*ArcSin[a*x])/x) + a*Log[x]}
{ArcSin[a*x]/(x^3*Sqrt[1 - a^2*x^2]), x, 3, -(a/(2*x)) - (Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(2*x^2) - I*a^2*ArcSin[a*x]*ArcTan[a*x - I*Sqrt[1 - a^2*x^2]] + (1/2)*I*a^2*PolyLog[2, (-I)*a*x - Sqrt[1 - a^2*x^2]] - (1/2)*I*a^2*PolyLog[2, I*a*x + Sqrt[1 - a^2*x^2]]}


{x^m*ArcSin[a*x]^2/Sqrt[1 - a^2*x^2], x, 0, Defer[Int][(x^m*ArcSin[a*x]^2)/Sqrt[1 - a^2*x^2], x]}

{x^4*ArcSin[a*x]^2/Sqrt[1 - a^2*x^2], x, 10, (15*x*Sqrt[1 - a^2*x^2])/(64*a^4) + (x^3*Sqrt[1 - a^2*x^2])/(32*a^2) - (15*ArcSin[a*x])/(64*a^5) + (3*x^2*ArcSin[a*x])/(8*a^3) + (x^4*ArcSin[a*x])/(8*a) - (3*x*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^2)/(8*a^4) - (x^3*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^2)/(4*a^2) + ArcSin[a*x]^3/(8*a^5)}
{x^3*ArcSin[a*x]^2/Sqrt[1 - a^2*x^2], x, 6, (40*Sqrt[1 - a^2*x^2])/(27*a^4) + (2*x^2*Sqrt[1 - a^2*x^2])/(27*a^2) + (4*x*ArcSin[a*x])/(3*a^3) + (2*x^3*ArcSin[a*x])/(9*a) - (2*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^2)/(3*a^4) - (x^2*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^2)/(3*a^2)}
{x^2*ArcSin[a*x]^2/Sqrt[1 - a^2*x^2], x, 5, (x*Sqrt[1 - a^2*x^2])/(4*a^2) - ArcSin[a*x]/(4*a^3) + (x^2*ArcSin[a*x])/(2*a) - (x*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^2)/(2*a^2) + ArcSin[a*x]^3/(6*a^3)}
{x^1*ArcSin[a*x]^2/Sqrt[1 - a^2*x^2], x, 2, (2*Sqrt[1 - a^2*x^2])/a^2 + (2*x*ArcSin[a*x])/a - (Sqrt[1 - a^2*x^2]*ArcSin[a*x]^2)/a^2}
{x^0*ArcSin[a*x]^2/Sqrt[1 - a^2*x^2], x, 1, ArcSin[a*x]^3/(3*a)}
{ArcSin[a*x]^2/(x^1*Sqrt[1 - a^2*x^2]), x, 6, -2*ArcSin[a*x]^2*ArcTanh[E^(I*ArcSin[a*x])] + 2*I*ArcSin[a*x]*PolyLog[2, -E^(I*ArcSin[a*x])] - 2*I*ArcSin[a*x]*PolyLog[2, E^(I*ArcSin[a*x])] - 2*PolyLog[3, -E^(I*ArcSin[a*x])] + 2*PolyLog[3, E^(I*ArcSin[a*x])]}
{ArcSin[a*x]^2/(x^2*Sqrt[1 - a^2*x^2]), x, 6, (-I)*a*ArcSin[a*x]^2 - (Sqrt[1 - a^2*x^2]*ArcSin[a*x]^2)/x + 2*a*ArcSin[a*x]*Log[1 - E^(2*I*ArcSin[a*x])] - I*a*PolyLog[2, E^(2*I*ArcSin[a*x])]}
{ArcSin[a*x]^2/(x^3*Sqrt[1 - a^2*x^2]), x, 10, -((a*ArcSin[a*x])/x) - (Sqrt[1 - a^2*x^2]*ArcSin[a*x]^2)/(2*x^2) - a^2*ArcSin[a*x]^2*ArcTanh[E^(I*ArcSin[a*x])] - a^2*ArcTanh[Sqrt[1 - a^2*x^2]] + I*a^2*ArcSin[a*x]*PolyLog[2, -E^(I*ArcSin[a*x])] - I*a^2*ArcSin[a*x]*PolyLog[2, E^(I*ArcSin[a*x])] - a^2*PolyLog[3, -E^(I*ArcSin[a*x])] + a^2*PolyLog[3, E^(I*ArcSin[a*x])]}


{x^m*ArcSin[a*x]^3/Sqrt[1 - a^2*x^2], x, 0, Defer[Int][(x^m*ArcSin[a*x]^3)/Sqrt[1 - a^2*x^2], x]}

{x^4*ArcSin[a*x]^3/Sqrt[1 - a^2*x^2], x, 13, -((45*x^2)/(128*a^3)) - (3*x^4)/(128*a) + (45*x*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(64*a^4) + (3*x^3*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(32*a^2) - (45*ArcSin[a*x]^2)/(128*a^5) + (9*x^2*ArcSin[a*x]^2)/(16*a^3) + (3*x^4*ArcSin[a*x]^2)/(16*a) - (3*x*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^3)/(8*a^4) - (x^3*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^3)/(4*a^2) + (3*ArcSin[a*x]^4)/(32*a^5)}
{x^3*ArcSin[a*x]^3/Sqrt[1 - a^2*x^2], x, 9, -((40*x)/(9*a^3)) - (2*x^3)/(27*a) + (40*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(9*a^4) + (2*x^2*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(9*a^2) + (2*x*ArcSin[a*x]^2)/a^3 + (x^3*ArcSin[a*x]^2)/(3*a) - (2*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^3)/(3*a^4) - (x^2*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^3)/(3*a^2)}
{x^2*ArcSin[a*x]^3/Sqrt[1 - a^2*x^2], x, 6, -((3*x^2)/(8*a)) + (3*x*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/(4*a^2) - (3*ArcSin[a*x]^2)/(8*a^3) + (3*x^2*ArcSin[a*x]^2)/(4*a) - (x*Sqrt[1 - a^2*x^2]*ArcSin[a*x]^3)/(2*a^2) + ArcSin[a*x]^4/(8*a^3)}
{x^1*ArcSin[a*x]^3/Sqrt[1 - a^2*x^2], x, 3, -((6*x)/a) + (6*Sqrt[1 - a^2*x^2]*ArcSin[a*x])/a^2 + (3*x*ArcSin[a*x]^2)/a - (Sqrt[1 - a^2*x^2]*ArcSin[a*x]^3)/a^2}
{x^0*ArcSin[a*x]^3/Sqrt[1 - a^2*x^2], x, 1, ArcSin[a*x]^4/(4*a)}
{ArcSin[a*x]^3/(x^1*Sqrt[1 - a^2*x^2]), x, 8, -2*ArcSin[a*x]^3*ArcTanh[E^(I*ArcSin[a*x])] + 3*I*ArcSin[a*x]^2*PolyLog[2, -E^(I*ArcSin[a*x])] - 3*I*ArcSin[a*x]^2*PolyLog[2, E^(I*ArcSin[a*x])] - 6*ArcSin[a*x]*PolyLog[3, -E^(I*ArcSin[a*x])] + 6*ArcSin[a*x]*PolyLog[3, E^(I*ArcSin[a*x])] - 6*I*PolyLog[4, -E^(I*ArcSin[a*x])] + 6*I*PolyLog[4, E^(I*ArcSin[a*x])]}
{ArcSin[a*x]^3/(x^2*Sqrt[1 - a^2*x^2]), x, 7, (-I)*a*ArcSin[a*x]^3 - (Sqrt[1 - a^2*x^2]*ArcSin[a*x]^3)/x + 3*a*ArcSin[a*x]^2*Log[1 - E^(2*I*ArcSin[a*x])] - 3*I*a*ArcSin[a*x]*PolyLog[2, E^(2*I*ArcSin[a*x])] + (3/2)*a*PolyLog[3, E^(2*I*ArcSin[a*x])]}
{ArcSin[a*x]^3/(x^3*Sqrt[1 - a^2*x^2]), x, 11, -((3*a*ArcSin[a*x]^2)/(2*x)) - (Sqrt[1 - a^2*x^2]*ArcSin[a*x]^3)/(2*x^2) - 6*I*a^2*ArcSin[a*x]*ArcTan[a*x - I*Sqrt[1 - a^2*x^2]] - a^2*ArcSin[a*x]^3*ArcTanh[E^(I*ArcSin[a*x])] + (3/2)*I*a^2*ArcSin[a*x]^2*PolyLog[2, -E^(I*ArcSin[a*x])] - (3/2)*I*a^2*ArcSin[a*x]^2*PolyLog[2, E^(I*ArcSin[a*x])] + 3*I*a^2*PolyLog[2, (-I)*a*x - Sqrt[1 - a^2*x^2]] - 3*I*a^2*PolyLog[2, I*a*x + Sqrt[1 - a^2*x^2]] - 3*a^2*ArcSin[a*x]*PolyLog[3, -E^(I*ArcSin[a*x])] + 3*a^2*ArcSin[a*x]*PolyLog[3, E^(I*ArcSin[a*x])] - 3*I*a^2*PolyLog[4, -E^(I*ArcSin[a*x])] + 3*I*a^2*PolyLog[4, E^(I*ArcSin[a*x])]}


{Sqrt[1 - x^2]*ArcSin[x], x, 3, (1/4)*(1 - x^2) + (1/2)*x*Sqrt[1 - x^2]*ArcSin[x] + ArcSin[x]^2/4}


(* ::Subsubsection::Closed:: *)
(*p<0*)


{x^1/(ArcSin[a*x]*Sqrt[1 - a^2*x^2]), x, 2, SinIntegral[ArcSin[a*x]]/a^2}
{x^0/(ArcSin[a*x]*Sqrt[1 - a^2*x^2]), x, 1, Log[ArcSin[a*x]]/a}
{1/(x^1*ArcSin[a*x]*Sqrt[1 - a^2*x^2]), x, 1, Subst[Int[Csc[x]/x, x], x, ArcSin[a*x]]}


{1/(ArcSin[a*x]^2*Sqrt[1 - a^2*x^2]), x, 1, -(1/(a*ArcSin[a*x]))}


{1/(ArcSin[a*x]^3*Sqrt[1 - a^2*x^2]), x, 1, -(1/(2*a*ArcSin[a*x]^2))}


{x/(Sqrt[1 - x^2]*Sqrt[ArcSin[x]]), x, 2, Sqrt[2*Pi]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcSin[x]]]}
{x/(Sqrt[1 - x^2]*ArcSin[x]), x, 2, SinIntegral[ArcSin[x]]}


(* ::Subsubsection::Closed:: *)
(*p symbolic*)


{x^m*ArcSin[a*x]^n/Sqrt[1 - a^2*x^2], x, 0, Int[(x^m*ArcSin[a*x]^n)/Sqrt[1 - a^2*x^2], x]}

{x^3*ArcSin[a*x]^n/Sqrt[1 - a^2*x^2], x, 9, -((3*ArcSin[a*x]^n*Gamma[1 + n, (-I)*ArcSin[a*x]])/(((-I)*ArcSin[a*x])^n*(8*a^4))) - (3*ArcSin[a*x]^n*Gamma[1 + n, I*ArcSin[a*x]])/((I*ArcSin[a*x])^n*(8*a^4)) + (3^(-1 - n)*ArcSin[a*x]^n*Gamma[1 + n, -3*I*ArcSin[a*x]])/(((-I)*ArcSin[a*x])^n*(8*a^4)) + (3^(-1 - n)*ArcSin[a*x]^n*Gamma[1 + n, 3*I*ArcSin[a*x]])/((I*ArcSin[a*x])^n*(8*a^4))}
{x^2*ArcSin[a*x]^n/Sqrt[1 - a^2*x^2], x, 6, ArcSin[a*x]^(1 + n)/(2*a^3*(1 + n)) + (I*2^(-3 - n)*ArcSin[a*x]^n*Gamma[1 + n, -2*I*ArcSin[a*x]])/(((-I)*ArcSin[a*x])^n*a^3) - (I*2^(-3 - n)*ArcSin[a*x]^n*Gamma[1 + n, 2*I*ArcSin[a*x]])/((I*ArcSin[a*x])^n*a^3)}
{x^1*ArcSin[a*x]^n/Sqrt[1 - a^2*x^2], x, 4, -((ArcSin[a*x]^n*Gamma[1 + n, (-I)*ArcSin[a*x]])/(((-I)*ArcSin[a*x])^n*(2*a^2))) - (ArcSin[a*x]^n*Gamma[1 + n, I*ArcSin[a*x]])/((I*ArcSin[a*x])^n*(2*a^2))}
{x^0*ArcSin[a*x]^n/Sqrt[1 - a^2*x^2], x, 1, ArcSin[a*x]^(1 + n)/(a*(1 + n))}
{ArcSin[a*x]^n/(x^1*Sqrt[1 - a^2*x^2]), x, 1, Subst[Int[x^n*Csc[x], x], x, ArcSin[a*x]]}
{ArcSin[a*x]^n/(x^2*Sqrt[1 - a^2*x^2]), x, 1, a*Subst[Int[x^n*Csc[x]^2, x], x, ArcSin[a*x]]}


(* ::Section::Closed:: *)
(*Integrands of the form u ArcSin[a+b x]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcSin[a+b x]^n*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{x^3*ArcSin[a + b*x], x, 7, -((a*(41 + 64*a^2)*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(96*b^4)) - (7*a*x^2*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(48*b^2) + (x^3*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(16*b) - ((14*a*(1 - a^2) - (9 + 26*a^2)*b*x)*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(96*b^4) - ((3 + 24*a^2 + 8*a^4)*ArcSin[a + b*x])/(32*b^4) + (1/4)*x^4*ArcSin[a + b*x]}
{x^2*ArcSin[a + b*x], x, 6, ((2 + 13*a^2)*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(18*b^3) + (x^2*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(9*b) + ((2*(1 - a^2) - 5*a*b*x)*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(18*b^3) + (a*(3 + 2*a^2)*ArcSin[a + b*x])/(6*b^3) + (1/3)*x^3*ArcSin[a + b*x]}
{x^1*ArcSin[a + b*x], x, 5, -((3*a*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(4*b^2)) + (x*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(4*b) - ((1 + 2*a^2)*ArcSin[a + b*x])/(4*b^2) + (1/2)*x^2*ArcSin[a + b*x]}
{x^0*ArcSin[a + b*x], x, 1, Sqrt[1 - (a + b*x)^2]/b + ((a + b*x)*ArcSin[a + b*x])/b}
{ArcSin[a + b*x]/x^1, x, -3, (1/8)*I*(Pi - 2*ArcSin[a + b*x])^2 + (1/2)*Pi*Log[b*x] - 2*I*ArcTanh[((1 + a)*(-1 + a + b*x - I*Sqrt[1 - (a + b*x)^2]))/(Sqrt[-1 + a^2]*(1 + a + b*x - I*Sqrt[1 - (a + b*x)^2]))]*(Log[2] - 2*Log[I*Sqrt[1 - a] + Sqrt[1 + a]]) - (ArcCos[a + b*x] + I*(Log[2] - 2*Log[I*Sqrt[1 - a] + Sqrt[1 + a]]))*Log[1 - (a + Sqrt[-1 + a^2])*(a + b*x + I*Sqrt[1 - (a + b*x)^2])] - (ArcCos[a + b*x] - I*(Log[2] - 2*Log[I*Sqrt[1 - a] + Sqrt[1 + a]]))*Log[1 + (-a + Sqrt[-1 + a^2])*(a + b*x + I*Sqrt[1 - (a + b*x)^2])] + I*PolyLog[2, (a - Sqrt[-1 + a^2])*(a + b*x + I*Sqrt[1 - (a + b*x)^2])] + I*PolyLog[2, (a + Sqrt[-1 + a^2])*(a + b*x + I*Sqrt[1 - (a + b*x)^2])]}
{ArcSin[a + b*x]/x^2, x, 3, -(ArcSin[a + b*x]/x) - (b*ArcTanh[(1 - a^2 - a*b*x)/(Sqrt[1 - a^2]*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])])/Sqrt[1 - a^2]}
{ArcSin[a + b*x]/x^3, x, 4, -((b*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(2*(1 - a^2)*x)) - ArcSin[a + b*x]/(2*x^2) - (a*b^2*ArcTanh[(1 - a^2 - a*b*x)/(Sqrt[1 - a^2]*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])])/(2*(1 - a^2)^(3/2))}
{ArcSin[a + b*x]/x^4, x, 6, -((b*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(6*(1 - a^2)*x^2)) - (a*b^2*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(2*(1 - a^2)^2*x) - ArcSin[a + b*x]/(3*x^3) - ((1 + 2*a^2)*b^3*ArcTanh[(1 - a^2 - a*b*x)/(Sqrt[1 - a^2]*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])])/(6*(1 - a^2)^(5/2))}
{ArcSin[a + b*x]/x^5, x, 7, -((b*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(12*(1 - a^2)*x^3)) - (5*a*b^2*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(24*(1 - a^2)^2*x^2) - ((4 + 11*a^2)*b^3*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(24*(1 - a^2)^3*x) - ArcSin[a + b*x]/(4*x^4) - (a*(3 + 2*a^2)*b^4*ArcTanh[(1 - a^2 - a*b*x)/(Sqrt[1 - a^2]*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])])/(8*(1 - a^2)^(7/2))}


{x^3*ArcSin[a + b*x]^2, x, 19, (55*a*x)/(48*b^3) + (a^3*x)/(2*b^3) - (3*x^2)/(32*b^2) - (3*a^2*x^2)/(4*b^2) + (2*a*(a + b*x)^3)/(9*b^4) - (a + b*x)^4/(32*b^4) - (4*a*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x])/(3*b^4) - (2*a^3*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x])/b^4 + (3*(a + b*x)*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x])/(16*b^4) + (3*a^2*(a + b*x)*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x])/(2*b^4) - (2*a*(a + b*x)^2*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x])/(3*b^4) + ((a + b*x)^3*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x])/(8*b^4) - (3*ArcSin[a + b*x]^2)/(32*b^4) - (3*a^2*ArcSin[a + b*x]^2)/(4*b^4) - (a^3*(a + b*x)*ArcSin[a + b*x]^2)/b^4 + (3*a^2*(a + b*x)^2*ArcSin[a + b*x]^2)/(2*b^4) - (a*(a + b*x)^3*ArcSin[a + b*x]^2)/b^4 + ((a + b*x)^4*ArcSin[a + b*x]^2)/(4*b^4)}
{x^2*ArcSin[a + b*x]^2, x, 13, -((4*x)/(9*b^2)) - (a^2*x)/b^2 + (a*x^2)/(2*b) - (2*(a + b*x)^3)/(27*b^3) + (4*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x])/(9*b^3) + (2*a^2*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x])/b^3 - (a*(a + b*x)*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x])/b^3 + (2*(a + b*x)^2*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x])/(9*b^3) + (a*ArcSin[a + b*x]^2)/(2*b^3) + (a^2*(a + b*x)*ArcSin[a + b*x]^2)/b^3 - (a*(a + b*x)^2*ArcSin[a + b*x]^2)/b^3 + ((a + b*x)^3*ArcSin[a + b*x]^2)/(3*b^3)}
{x^1*ArcSin[a + b*x]^2, x, 8, (3*a*x)/(2*b) - x^2/4 - (2*a*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x])/b^2 + ((a + b*x)*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x])/(2*b^2) - ArcSin[a + b*x]^2/(4*b^2) - (a*(a + b*x)*ArcSin[a + b*x]^2)/b^2 + ((a + b*x)^2*ArcSin[a + b*x]^2)/(2*b^2)}
{x^0*ArcSin[a + b*x]^2, x, 2, -2*x + (2*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x])/b + ((a + b*x)*ArcSin[a + b*x]^2)/b}
{ArcSin[a + b*x]^2/x^1, x, 0, Int[ArcSin[a + b*x]^2/x, x]}
{ArcSin[a + b*x]^2/x^2, x, 10, -(ArcSin[a + b*x]^2/x) + (2*I*b*ArcSin[a + b*x]*Log[1 + (I*E^(I*ArcSin[a + b*x]))/(a - Sqrt[-1 + a^2])])/Sqrt[-1 + a^2] - (2*I*b*ArcSin[a + b*x]*Log[1 + (I*E^(I*ArcSin[a + b*x]))/(a + Sqrt[-1 + a^2])])/Sqrt[-1 + a^2] + (2*b*PolyLog[2, -((I*E^(I*ArcSin[a + b*x]))/(a - Sqrt[-1 + a^2]))])/Sqrt[-1 + a^2] - (2*b*PolyLog[2, -((I*E^(I*ArcSin[a + b*x]))/(a + Sqrt[-1 + a^2]))])/Sqrt[-1 + a^2]}
{ArcSin[a + b*x]^2/x^3, x, 14, -((b*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x])/((1 - a^2)*x)) - ArcSin[a + b*x]^2/(2*x^2) - (I*a*b^2*ArcSin[a + b*x]*Log[1 + (I*E^(I*ArcSin[a + b*x]))/(a - Sqrt[-1 + a^2])])/(-1 + a^2)^(3/2) + (I*a*b^2*ArcSin[a + b*x]*Log[1 + (I*E^(I*ArcSin[a + b*x]))/(a + Sqrt[-1 + a^2])])/(-1 + a^2)^(3/2) + (b^2*Log[x])/(1 - a^2) - (a*b^2*PolyLog[2, -((I*E^(I*ArcSin[a + b*x]))/(a - Sqrt[-1 + a^2]))])/(-1 + a^2)^(3/2) + (a*b^2*PolyLog[2, -((I*E^(I*ArcSin[a + b*x]))/(a + Sqrt[-1 + a^2]))])/(-1 + a^2)^(3/2)}
(* {ArcSin[a + b*x]^2/x^4, x, 0, 0} *)


{x^2*ArcSin[a + b*x]^3, x, 19, -((40*Sqrt[1 - (a + b*x)^2])/(27*b^3)) - (6*a^2*Sqrt[1 - (a + b*x)^2])/b^3 + (3*a*(a + b*x)*Sqrt[1 - (a + b*x)^2])/(4*b^3) - (2*(a + b*x)^2*Sqrt[1 - (a + b*x)^2])/(27*b^3) - (3*a*ArcSin[a + b*x])/(4*b^3) - (4*(a + b*x)*ArcSin[a + b*x])/(3*b^3) - (6*a^2*(a + b*x)*ArcSin[a + b*x])/b^3 + (3*a*(a + b*x)^2*ArcSin[a + b*x])/(2*b^3) - (2*(a + b*x)^3*ArcSin[a + b*x])/(9*b^3) + (2*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x]^2)/(3*b^3) + (3*a^2*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x]^2)/b^3 - (3*a*(a + b*x)*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x]^2)/(2*b^3) + ((a + b*x)^2*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x]^2)/(3*b^3) + (a*ArcSin[a + b*x]^3)/(2*b^3) + (a^2*(a + b*x)*ArcSin[a + b*x]^3)/b^3 - (a*(a + b*x)^2*ArcSin[a + b*x]^3)/b^3 + ((a + b*x)^3*ArcSin[a + b*x]^3)/(3*b^3)}
{x^1*ArcSin[a + b*x]^3, x, 11, (6*a*Sqrt[1 - (a + b*x)^2])/b^2 - (3*(a + b*x)*Sqrt[1 - (a + b*x)^2])/(8*b^2) + (3*ArcSin[a + b*x])/(8*b^2) + (6*a*(a + b*x)*ArcSin[a + b*x])/b^2 - (3*(a + b*x)^2*ArcSin[a + b*x])/(4*b^2) - (3*a*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x]^2)/b^2 + (3*(a + b*x)*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x]^2)/(4*b^2) - ArcSin[a + b*x]^3/(4*b^2) - (a*(a + b*x)*ArcSin[a + b*x]^3)/b^2 + ((a + b*x)^2*ArcSin[a + b*x]^3)/(2*b^2)}
{x^0*ArcSin[a + b*x]^3, x, 2, -((6*Sqrt[1 - (a + b*x)^2])/b) - (6*(a + b*x)*ArcSin[a + b*x])/b + (3*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x]^2)/b + ((a + b*x)*ArcSin[a + b*x]^3)/b}
{ArcSin[a + b*x]^3/x^1, x, 0, Int[ArcSin[a + b*x]^3/x, x]}
{ArcSin[a + b*x]^3/x^2, x, 12, -(ArcSin[a + b*x]^3/x) + (3*I*b*ArcSin[a + b*x]^2*Log[1 + (I*E^(I*ArcSin[a + b*x]))/(a - Sqrt[-1 + a^2])])/Sqrt[-1 + a^2] - (3*I*b*ArcSin[a + b*x]^2*Log[1 + (I*E^(I*ArcSin[a + b*x]))/(a + Sqrt[-1 + a^2])])/Sqrt[-1 + a^2] + (6*b*ArcSin[a + b*x]*PolyLog[2, -((I*E^(I*ArcSin[a + b*x]))/(a - Sqrt[-1 + a^2]))])/Sqrt[-1 + a^2] - (6*b*ArcSin[a + b*x]*PolyLog[2, -((I*E^(I*ArcSin[a + b*x]))/(a + Sqrt[-1 + a^2]))])/Sqrt[-1 + a^2] + (6*I*b*PolyLog[3, -((I*E^(I*ArcSin[a + b*x]))/(a - Sqrt[-1 + a^2]))])/Sqrt[-1 + a^2] - (6*I*b*PolyLog[3, -((I*E^(I*ArcSin[a + b*x]))/(a + Sqrt[-1 + a^2]))])/Sqrt[-1 + a^2]}
(* {ArcSin[a + b*x]^3/x^3, x, 0, 0} *)


{Sqrt[ArcSin[a + b*x]], x, 4, ((a + b*x)*Sqrt[ArcSin[a + b*x]])/b - (Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcSin[a + b*x]]])/b}
{ArcSin[a + b*x]^(3/2), x, 4, (3*Sqrt[1 - (a + b*x)^2]*Sqrt[ArcSin[a + b*x]])/(2*b) + ((a + b*x)*ArcSin[a + b*x]^(3/2))/b - (3*Sqrt[Pi/2]*FresnelC[Sqrt[2/Pi]*Sqrt[ArcSin[a + b*x]]])/(2*b)}
{ArcSin[a + b*x]^(5/2), x, 5, -((15*(a + b*x)*Sqrt[ArcSin[a + b*x]])/(4*b)) + (5*Sqrt[1 - (a + b*x)^2]*ArcSin[a + b*x]^(3/2))/(2*b) + ((a + b*x)*ArcSin[a + b*x]^(5/2))/b + (15*Sqrt[Pi/2]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcSin[a + b*x]]])/(4*b)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{x^2/ArcSin[a + b*x], x, 13, CosIntegral[ArcSin[a + b*x]]/(4*b^3) + (a^2*CosIntegral[ArcSin[a + b*x]])/b^3 - CosIntegral[3*ArcSin[a + b*x]]/(4*b^3) - (a*SinIntegral[2*ArcSin[a + b*x]])/b^3}
{x^1/ArcSin[a + b*x], x, 8, -((a*CosIntegral[ArcSin[a + b*x]])/b^2) + SinIntegral[2*ArcSin[a + b*x]]/(2*b^2)}
{x^0/ArcSin[a + b*x], x, 2, CosIntegral[ArcSin[a + b*x]]/b}
{1/(x^1*ArcSin[a + b*x]), x, 0, Int[1/(x*ArcSin[a + b*x]), x]}


{x^2/ArcSin[a + b*x]^2, x, 12, -((x^2*Sqrt[1 - (a + b*x)^2])/(b*ArcSin[a + b*x])) - (2*a*CosIntegral[2*ArcSin[a + b*x]])/b^3 - ((1 + 4*a^2)*SinIntegral[ArcSin[a + b*x]])/(4*b^3) + (3*SinIntegral[3*ArcSin[a + b*x]])/(4*b^3), -((a^2*Sqrt[1 - (a + b*x)^2])/(b^3*ArcSin[a + b*x])) + (2*a*(a + b*x)*Sqrt[1 - (a + b*x)^2])/(b^3*ArcSin[a + b*x]) - ((a + b*x)^2*Sqrt[1 - (a + b*x)^2])/(b^3*ArcSin[a + b*x]) - (2*a*CosIntegral[2*ArcSin[a + b*x]])/b^3 - SinIntegral[ArcSin[a + b*x]]/(4*b^3) - (a^2*SinIntegral[ArcSin[a + b*x]])/b^3 + (3*SinIntegral[3*ArcSin[a + b*x]])/(4*b^3)}
{x^1/ArcSin[a + b*x]^2, x, 8, -((x*Sqrt[1 - (a + b*x)^2])/(b*ArcSin[a + b*x])) + CosIntegral[2*ArcSin[a + b*x]]/b^2 + (a*SinIntegral[ArcSin[a + b*x]])/b^2, (a*Sqrt[1 - (a + b*x)^2])/(b^2*ArcSin[a + b*x]) - ((a + b*x)*Sqrt[1 - (a + b*x)^2])/(b^2*ArcSin[a + b*x]) + CosIntegral[2*ArcSin[a + b*x]]/b^2 + (a*SinIntegral[ArcSin[a + b*x]])/b^2}
{x^0/ArcSin[a + b*x]^2, x, 4, -(Sqrt[1 - (a + b*x)^2]/(b*ArcSin[a + b*x])) - SinIntegral[ArcSin[a + b*x]]/b}
{1/(x^1*ArcSin[a + b*x]^2), x, 0, Int[1/(x*ArcSin[a + b*x]^2), x]}


{x^2/ArcSin[a + b*x]^3, x, 19, -((x^2*Sqrt[1 - (a + b*x)^2])/(2*b*ArcSin[a + b*x]^2)) + (a^2*(a + b*x))/(2*b^3*ArcSin[a + b*x]) - (2*a*(a + b*x)^2)/(b^3*ArcSin[a + b*x]) + (9*a + b*x)/(8*b^3*ArcSin[a + b*x]) - ((1 + 4*a^2)*CosIntegral[ArcSin[a + b*x]])/(8*b^3) + (9*CosIntegral[3*ArcSin[a + b*x]])/(8*b^3) - (3*Sin[3*ArcSin[a + b*x]])/(8*b^3*ArcSin[a + b*x]) + (2*a*SinIntegral[2*ArcSin[a + b*x]])/b^3, -((a^2*Sqrt[1 - (a + b*x)^2])/(2*b^3*ArcSin[a + b*x]^2)) + (a*(a + b*x)*Sqrt[1 - (a + b*x)^2])/(b^3*ArcSin[a + b*x]^2) - ((a + b*x)^2*Sqrt[1 - (a + b*x)^2])/(2*b^3*ArcSin[a + b*x]^2) + a/(b^3*ArcSin[a + b*x]) - (a + b*x)/(b^3*ArcSin[a + b*x]) + (a^2*(a + b*x))/(2*b^3*ArcSin[a + b*x]) - (2*a*(a + b*x)^2)/(b^3*ArcSin[a + b*x]) + (3*(a + b*x)^3)/(2*b^3*ArcSin[a + b*x]) - CosIntegral[ArcSin[a + b*x]]/(8*b^3) - (a^2*CosIntegral[ArcSin[a + b*x]])/(2*b^3) + (9*CosIntegral[3*ArcSin[a + b*x]])/(8*b^3) + (2*a*SinIntegral[2*ArcSin[a + b*x]])/b^3}
{x^1/ArcSin[a + b*x]^3, x, 11, -((x*Sqrt[1 - (a + b*x)^2])/(2*b*ArcSin[a + b*x]^2)) - (a*(a + b*x))/(2*b^2*ArcSin[a + b*x]) - (1 - 2*(a + b*x)^2)/(2*b^2*ArcSin[a + b*x]) + (a*CosIntegral[ArcSin[a + b*x]])/(2*b^2) - SinIntegral[2*ArcSin[a + b*x]]/b^2, (a*Sqrt[1 - (a + b*x)^2])/(2*b^2*ArcSin[a + b*x]^2) - ((a + b*x)*Sqrt[1 - (a + b*x)^2])/(2*b^2*ArcSin[a + b*x]^2) - 1/(2*b^2*ArcSin[a + b*x]) - (a*(a + b*x))/(2*b^2*ArcSin[a + b*x]) + (a + b*x)^2/(b^2*ArcSin[a + b*x]) + (a*CosIntegral[ArcSin[a + b*x]])/(2*b^2) - SinIntegral[2*ArcSin[a + b*x]]/b^2}
{x^0/ArcSin[a + b*x]^3, x, 3, -(Sqrt[1 - (a + b*x)^2]/(2*b*ArcSin[a + b*x]^2)) + (a + b*x)/(2*b*ArcSin[a + b*x]) - CosIntegral[ArcSin[a + b*x]]/(2*b)}
{1/(x^1*ArcSin[a + b*x]^3), x, 0, Int[1/(x*ArcSin[a + b*x]^3), x]}


{1/Sqrt[ArcSin[a + b*x]], x, 3, (Sqrt[2*Pi]*FresnelC[Sqrt[2/Pi]*Sqrt[ArcSin[a + b*x]]])/b}
{1/ArcSin[a + b*x]^(3/2), x, 4, -((2*Sqrt[1 - (a + b*x)^2])/(b*Sqrt[ArcSin[a + b*x]])) - (2*Sqrt[2*Pi]*FresnelS[Sqrt[2/Pi]*Sqrt[ArcSin[a + b*x]]])/b}
{1/ArcSin[a + b*x]^(5/2), x, 4, -((2*Sqrt[1 - (a + b*x)^2])/(3*b*ArcSin[a + b*x]^(3/2))) + (4*(a + b*x))/(3*b*Sqrt[ArcSin[a + b*x]]) - (4*Sqrt[2*Pi]*FresnelC[Sqrt[2/Pi]*Sqrt[ArcSin[a + b*x]]])/(3*b)}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{x^m*ArcSin[a + b*x]^n, x, 0, Int[x^m*ArcSin[a + b*x]^n, x]}

{x^2*ArcSin[a + b*x]^n, x, 25, (a*ArcSin[a + b*x]^n)/(2*b^3) - (a*(a + b*x)^2*ArcSin[a + b*x]^n)/b^3 + ((a + b*x)^3*ArcSin[a + b*x]^n)/(3*b^3) - (I*n*ArcSin[a + b*x]^n*Gamma[n, (-I)*ArcSin[a + b*x]])/(((-I)*ArcSin[a + b*x])^n*(8*b^3)) + (I*n*ArcSin[a + b*x]^n*Gamma[n, I*ArcSin[a + b*x]])/((I*ArcSin[a + b*x])^n*(8*b^3)) + (2^(-2 - n)*a*n*ArcSin[a + b*x]^n*Gamma[n, -2*I*ArcSin[a + b*x]])/(((-I)*ArcSin[a + b*x])^n*b^3) + (2^(-2 - n)*a*n*ArcSin[a + b*x]^n*Gamma[n, 2*I*ArcSin[a + b*x]])/((I*ArcSin[a + b*x])^n*b^3) + (I*3^(-1 - n)*n*ArcSin[a + b*x]^n*Gamma[n, -3*I*ArcSin[a + b*x]])/(((-I)*ArcSin[a + b*x])^n*(8*b^3)) - (I*3^(-1 - n)*n*ArcSin[a + b*x]^n*Gamma[n, 3*I*ArcSin[a + b*x]])/((I*ArcSin[a + b*x])^n*(8*b^3)) - (I*a^2*ArcSin[a + b*x]^n*Gamma[1 + n, (-I)*ArcSin[a + b*x]])/(((-I)*ArcSin[a + b*x])^n*(2*b^3)) + (I*a^2*ArcSin[a + b*x]^n*Gamma[1 + n, I*ArcSin[a + b*x]])/((I*ArcSin[a + b*x])^n*(2*b^3))}
{x^1*ArcSin[a + b*x]^n, x, 14, -(ArcSin[a + b*x]^n/(4*b^2)) + ((a + b*x)^2*ArcSin[a + b*x]^n)/(2*b^2) - (2^(-3 - n)*n*ArcSin[a + b*x]^n*Gamma[n, -2*I*ArcSin[a + b*x]])/(((-I)*ArcSin[a + b*x])^n*b^2) - (2^(-3 - n)*n*ArcSin[a + b*x]^n*Gamma[n, 2*I*ArcSin[a + b*x]])/((I*ArcSin[a + b*x])^n*b^2) + (I*a*ArcSin[a + b*x]^n*Gamma[1 + n, (-I)*ArcSin[a + b*x]])/(((-I)*ArcSin[a + b*x])^n*(2*b^2)) - (I*a*ArcSin[a + b*x]^n*Gamma[1 + n, I*ArcSin[a + b*x]])/((I*ArcSin[a + b*x])^n*(2*b^2))}
{x^0*ArcSin[a + b*x]^n, x, 4, -((I*ArcSin[a + b*x]^n*Gamma[1 + n, (-I)*ArcSin[a + b*x]])/(((-I)*ArcSin[a + b*x])^n*(2*b))) + (I*ArcSin[a + b*x]^n*Gamma[1 + n, I*ArcSin[a + b*x]])/((I*ArcSin[a + b*x])^n*(2*b))}
{ArcSin[a + b*x]^n/x^1, x, 0, Int[ArcSin[a + b*x]^n/x, x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c+d x)^m ArcSin[a+b x]^n*)


{ArcSin[a + b*x]/((a*d)/b + d*x), x, 5, -((I*ArcSin[a + b*x]^2)/(2*d)) + (ArcSin[a + b*x]*Log[1 - E^(2*I*ArcSin[a + b*x])])/d - (I*PolyLog[2, E^(2*I*ArcSin[a + b*x])])/(2*d)}


(* ::Section::Closed:: *)
(*Integrands of the form u ArcSin[a +b x^n]*)


{x^3*ArcSin[a + b*x^4], x, 2, Sqrt[1 - (a + b*x^4)^2]/(4*b) + ((a + b*x^4)*ArcSin[a + b*x^4])/(4*b)}


{x^(n-1)*ArcSin[a + b*x^n], x, 2, Sqrt[1 - (a + b*x^n)^2]/(b*n) + ((a + b*x^n)*ArcSin[a + b*x^n])/(b*n)}


(* ::Section::Closed:: *)
(*Integrands of the form u (a+b ArcSin[d +e x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a+b ArcSin[c x])^n*)


(* ::Subsubsection::Closed:: *)
(*n/2>0*)


{x^2*(a + b*ArcSin[c*x])^(1/2), x, 10, (1/3)*x^3*Sqrt[a + b*ArcSin[c*x]] - (Sqrt[b]*Sqrt[Pi/2]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(4*c^3) + (Sqrt[b]*Sqrt[Pi/6]*Cos[(3*a)/b]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(12*c^3) + (Sqrt[b]*Sqrt[Pi/2]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[a/b])/(4*c^3) - (Sqrt[b]*Sqrt[Pi/6]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[(3*a)/b])/(12*c^3)}
{x^1*(a + b*ArcSin[c*x])^(1/2), x, 7, -(Sqrt[a + b*ArcSin[c*x]]/(4*c^2)) + (1/2)*x^2*Sqrt[a + b*ArcSin[c*x]] + (Sqrt[b]*Sqrt[Pi]*Cos[(2*a)/b]*FresnelC[(2*Sqrt[a + b*ArcSin[c*x]])/(Sqrt[b]*Sqrt[Pi])])/(8*c^2) + (Sqrt[b]*Sqrt[Pi]*FresnelS[(2*Sqrt[a + b*ArcSin[c*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(8*c^2)}
{x^0*(a + b*ArcSin[c*x])^(1/2), x, 6, x*Sqrt[a + b*ArcSin[c*x]] - (Sqrt[b]*Sqrt[Pi/2]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/c + (Sqrt[b]*Sqrt[Pi/2]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[a/b])/c}


{x^2*(a + b*ArcSin[c*x])^(3/2), x, 18, (b*Sqrt[1 - c^2*x^2]*Sqrt[a + b*ArcSin[c*x]])/(3*c^3) + (b*x^2*Sqrt[1 - c^2*x^2]*Sqrt[a + b*ArcSin[c*x]])/(6*c) + (1/3)*x^3*(a + b*ArcSin[c*x])^(3/2) - (3*b^(3/2)*Sqrt[Pi/2]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(8*c^3) + (b^(3/2)*Sqrt[Pi/6]*Cos[(3*a)/b]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(24*c^3) - (3*b^(3/2)*Sqrt[Pi/2]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[a/b])/(8*c^3) + (b^(3/2)*Sqrt[Pi/6]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[(3*a)/b])/(24*c^3)}
{x^1*(a + b*ArcSin[c*x])^(3/2), x, 8, (3*b*x*Sqrt[1 - c^2*x^2]*Sqrt[a + b*ArcSin[c*x]])/(8*c) - (a + b*ArcSin[c*x])^(3/2)/(4*c^2) + (1/2)*x^2*(a + b*ArcSin[c*x])^(3/2) - (3*b^(3/2)*Sqrt[Pi]*Cos[(2*a)/b]*FresnelS[(2*Sqrt[a + b*ArcSin[c*x]])/(Sqrt[b]*Sqrt[Pi])])/(32*c^2) + (3*b^(3/2)*Sqrt[Pi]*FresnelC[(2*Sqrt[a + b*ArcSin[c*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(32*c^2)}
{x^0*(a + b*ArcSin[c*x])^(3/2), x, 7, (3*b*Sqrt[1 - c^2*x^2]*Sqrt[a + b*ArcSin[c*x]])/(2*c) + x*(a + b*ArcSin[c*x])^(3/2) - (3*b^(3/2)*Sqrt[Pi/2]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(2*c) - (3*b^(3/2)*Sqrt[Pi/2]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[a/b])/(2*c)}


{x^2*(a + b*ArcSin[c*x])^(5/2), x, 19, -((5*b^2*x*Sqrt[a + b*ArcSin[c*x]])/(6*c^2)) - (5/36)*b^2*x^3*Sqrt[a + b*ArcSin[c*x]] + (5*b*Sqrt[1 - c^2*x^2]*(a + b*ArcSin[c*x])^(3/2))/(9*c^3) + (5*b*x^2*Sqrt[1 - c^2*x^2]*(a + b*ArcSin[c*x])^(3/2))/(18*c) + (1/3)*x^3*(a + b*ArcSin[c*x])^(5/2) + (15*b^(5/2)*Sqrt[Pi/2]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(16*c^3) - (5*b^(5/2)*Sqrt[Pi/6]*Cos[(3*a)/b]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(144*c^3) - (15*b^(5/2)*Sqrt[Pi/2]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[a/b])/(16*c^3) + (5*b^(5/2)*Sqrt[Pi/6]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[(3*a)/b])/(144*c^3)}
{x^1*(a + b*ArcSin[c*x])^(5/2), x, 10, (15*b^2*Sqrt[a + b*ArcSin[c*x]])/(64*c^2) - (15/32)*b^2*x^2*Sqrt[a + b*ArcSin[c*x]] + (5*b*x*Sqrt[1 - c^2*x^2]*(a + b*ArcSin[c*x])^(3/2))/(8*c) - (a + b*ArcSin[c*x])^(5/2)/(4*c^2) + (1/2)*x^2*(a + b*ArcSin[c*x])^(5/2) - (15*b^(5/2)*Sqrt[Pi]*Cos[(2*a)/b]*FresnelC[(2*Sqrt[a + b*ArcSin[c*x]])/(Sqrt[b]*Sqrt[Pi])])/(128*c^2) - (15*b^(5/2)*Sqrt[Pi]*FresnelS[(2*Sqrt[a + b*ArcSin[c*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(128*c^2)}
{x^0*(a + b*ArcSin[c*x])^(5/2), x, 7, (-(15/4))*b^2*x*Sqrt[a + b*ArcSin[c*x]] + (5*b*Sqrt[1 - c^2*x^2]*(a + b*ArcSin[c*x])^(3/2))/(2*c) + x*(a + b*ArcSin[c*x])^(5/2) + (15*b^(5/2)*Sqrt[Pi/2]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(4*c) - (15*b^(5/2)*Sqrt[Pi/2]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[a/b])/(4*c)}


(* ::Subsubsection::Closed:: *)
(*n/2<0*)


{x^2/(a + b*ArcSin[c*x])^(1/2), x, 9, (Sqrt[Pi/2]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(2*Sqrt[b]*c^3) - (Sqrt[Pi/6]*Cos[(3*a)/b]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(2*Sqrt[b]*c^3) + (Sqrt[Pi/2]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[a/b])/(2*Sqrt[b]*c^3) - (Sqrt[Pi/6]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[(3*a)/b])/(2*Sqrt[b]*c^3)}
{x^1/(a + b*ArcSin[c*x])^(1/2), x, 5, (Sqrt[Pi]*Cos[(2*a)/b]*FresnelS[(2*Sqrt[a + b*ArcSin[c*x]])/(Sqrt[b]*Sqrt[Pi])])/(2*Sqrt[b]*c^2) - (Sqrt[Pi]*FresnelC[(2*Sqrt[a + b*ArcSin[c*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(2*Sqrt[b]*c^2)}
{x^0/(a + b*ArcSin[c*x])^(1/2), x, 6, (Sqrt[2*Pi]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(Sqrt[b]*c) + (Sqrt[2*Pi]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[a/b])/(Sqrt[b]*c)}


{x^2/(a + b*ArcSin[c*x])^(3/2), x, 9, -((2*x^2*Sqrt[1 - c^2*x^2])/(b*c*Sqrt[a + b*ArcSin[c*x]])) - (Sqrt[Pi/2]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(b^(3/2)*c^3) + (Sqrt[(3*Pi)/2]*Cos[(3*a)/b]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(b^(3/2)*c^3) + (Sqrt[Pi/2]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[a/b])/(b^(3/2)*c^3) - (Sqrt[(3*Pi)/2]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[(3*a)/b])/(b^(3/2)*c^3)}
{x^1/(a + b*ArcSin[c*x])^(3/2), x, 4, -((2*x*Sqrt[1 - c^2*x^2])/(b*c*Sqrt[a + b*ArcSin[c*x]])) + (2*Sqrt[Pi]*Cos[(2*a)/b]*FresnelC[(2*Sqrt[a + b*ArcSin[c*x]])/(Sqrt[b]*Sqrt[Pi])])/(b^(3/2)*c^2) + (2*Sqrt[Pi]*FresnelS[(2*Sqrt[a + b*ArcSin[c*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(b^(3/2)*c^2)}
{x^0/(a + b*ArcSin[c*x])^(3/2), x, 6, -((2*Sqrt[1 - c^2*x^2])/(b*c*Sqrt[a + b*ArcSin[c*x]])) - (2*Sqrt[2*Pi]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(b^(3/2)*c) + (2*Sqrt[2*Pi]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[a/b])/(b^(3/2)*c)}


{x^2/(a + b*ArcSin[c*x])^(5/2), x, 16, -((2*x^2*Sqrt[1 - c^2*x^2])/(3*b*c*(a + b*ArcSin[c*x])^(3/2))) - (8*x)/(3*b^2*c^2*Sqrt[a + b*ArcSin[c*x]]) + (4*x^3)/(b^2*Sqrt[a + b*ArcSin[c*x]]) - (Sqrt[2*Pi]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(3*b^(5/2)*c^3) + (Sqrt[6*Pi]*Cos[(3*a)/b]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(b^(5/2)*c^3) - (Sqrt[2*Pi]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[a/b])/(3*b^(5/2)*c^3) + (Sqrt[6*Pi]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[(3*a)/b])/(b^(5/2)*c^3)}
{x^1/(a + b*ArcSin[c*x])^(5/2), x, 7, -((2*x*Sqrt[1 - c^2*x^2])/(3*b*c*(a + b*ArcSin[c*x])^(3/2))) - 4/(3*b^2*c^2*Sqrt[a + b*ArcSin[c*x]]) + (8*x^2)/(3*b^2*Sqrt[a + b*ArcSin[c*x]]) - (8*Sqrt[Pi]*Cos[(2*a)/b]*FresnelS[(2*Sqrt[a + b*ArcSin[c*x]])/(Sqrt[b]*Sqrt[Pi])])/(3*b^(5/2)*c^2) + (8*Sqrt[Pi]*FresnelC[(2*Sqrt[a + b*ArcSin[c*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(3*b^(5/2)*c^2)}
{x^0/(a + b*ArcSin[c*x])^(5/2), x, 7, -((2*Sqrt[1 - c^2*x^2])/(3*b*c*(a + b*ArcSin[c*x])^(3/2))) + (4*x)/(3*b^2*Sqrt[a + b*ArcSin[c*x]]) - (4*Sqrt[2*Pi]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(3*b^(5/2)*c) - (4*Sqrt[2*Pi]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[a/b])/(3*b^(5/2)*c)}


{x^2/(a + b*ArcSin[c*x])^(7/2), x, 16, -((2*x^2*Sqrt[1 - c^2*x^2])/(5*b*c*(a + b*ArcSin[c*x])^(5/2))) - (8*x)/(15*b^2*c^2*(a + b*ArcSin[c*x])^(3/2)) + (4*x^3)/(5*b^2*(a + b*ArcSin[c*x])^(3/2)) - (16*Sqrt[1 - c^2*x^2])/(15*b^3*c^3*Sqrt[a + b*ArcSin[c*x]]) + (24*x^2*Sqrt[1 - c^2*x^2])/(5*b^3*c*Sqrt[a + b*ArcSin[c*x]]) + (2*Sqrt[2*Pi]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(15*b^(7/2)*c^3) - (6*Sqrt[6*Pi]*Cos[(3*a)/b]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(5*b^(7/2)*c^3) - (2*Sqrt[2*Pi]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[a/b])/(15*b^(7/2)*c^3) + (6*Sqrt[6*Pi]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[(3*a)/b])/(5*b^(7/2)*c^3)}
{x^1/(a + b*ArcSin[c*x])^(7/2), x, 6, -((2*x*Sqrt[1 - c^2*x^2])/(5*b*c*(a + b*ArcSin[c*x])^(5/2))) - 4/(15*b^2*c^2*(a + b*ArcSin[c*x])^(3/2)) + (8*x^2)/(15*b^2*(a + b*ArcSin[c*x])^(3/2)) + (32*x*Sqrt[1 - c^2*x^2])/(15*b^3*c*Sqrt[a + b*ArcSin[c*x]]) - (32*Sqrt[Pi]*Cos[(2*a)/b]*FresnelC[(2*Sqrt[a + b*ArcSin[c*x]])/(Sqrt[b]*Sqrt[Pi])])/(15*b^(7/2)*c^2) - (32*Sqrt[Pi]*FresnelS[(2*Sqrt[a + b*ArcSin[c*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(15*b^(7/2)*c^2)}
{x^0/(a + b*ArcSin[c*x])^(7/2), x, 7, -((2*Sqrt[1 - c^2*x^2])/(5*b*c*(a + b*ArcSin[c*x])^(5/2))) + (4*x)/(15*b^2*(a + b*ArcSin[c*x])^(3/2)) + (8*Sqrt[1 - c^2*x^2])/(15*b^3*c*Sqrt[a + b*ArcSin[c*x]]) + (8*Sqrt[2*Pi]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]])/(15*b^(7/2)*c) - (8*Sqrt[2*Pi]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c*x]])/Sqrt[b]]*Sin[a/b])/(15*b^(7/2)*c)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a+b ArcSin[c+d x])^n*)


(* ::Subsubsection::Closed:: *)
(*n*)


{(a + b*ArcSin[c + d*x])^5, x, 4, 120*a*b^4*x + (120*b^5*Sqrt[1 - (c + d*x)^2])/d + (120*b^5*(c + d*x)*ArcSin[c + d*x])/d - (60*b^3*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^2)/d - (20*b^2*(c + d*x)*(a + b*ArcSin[c + d*x])^3)/d + (5*b*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^4)/d + ((c + d*x)*(a + b*ArcSin[c + d*x])^5)/d}
{(a + b*ArcSin[c + d*x])^4, x, 3, 24*b^4*x - (24*b^3*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x]))/d - (12*b^2*(c + d*x)*(a + b*ArcSin[c + d*x])^2)/d + (4*b*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^3)/d + ((c + d*x)*(a + b*ArcSin[c + d*x])^4)/d}
{(a + b*ArcSin[c + d*x])^3, x, 3, -6*a*b^2*x - (6*b^3*Sqrt[1 - (c + d*x)^2])/d - (6*b^3*(c + d*x)*ArcSin[c + d*x])/d + (3*b*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^2)/d + ((c + d*x)*(a + b*ArcSin[c + d*x])^3)/d}
{(a + b*ArcSin[c + d*x])^2, x, 2, -2*b^2*x + (2*b*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x]))/d + ((c + d*x)*(a + b*ArcSin[c + d*x])^2)/d}
{(a + b*ArcSin[c + d*x])^1, x, 2, a*x + (b*Sqrt[1 - (c + d*x)^2])/d + (b*(c + d*x)*ArcSin[c + d*x])/d}
{1/(a + b*ArcSin[c + d*x])^1, x, 4, (Cos[a/b]*CosIntegral[(a + b*ArcSin[c + d*x])/b])/(b*d) + (Sin[a/b]*SinIntegral[(a + b*ArcSin[c + d*x])/b])/(b*d)}
{1/(a + b*ArcSin[c + d*x])^2, x, 6, -(Sqrt[1 - (c + d*x)^2]/(b*d*(a + b*ArcSin[c + d*x]))) + (CosIntegral[(a + b*ArcSin[c + d*x])/b]*Sin[a/b])/(b^2*d) - (Cos[a/b]*SinIntegral[(a + b*ArcSin[c + d*x])/b])/(b^2*d)}
{1/(a + b*ArcSin[c + d*x])^3, x, 5, -(Sqrt[1 - (c + d*x)^2]/(2*b*d*(a + b*ArcSin[c + d*x])^2)) + (c + d*x)/(2*b^2*d*(a + b*ArcSin[c + d*x])) - (Cos[a/b]*CosIntegral[(a + b*ArcSin[c + d*x])/b])/(2*b^3*d) - (Sin[a/b]*SinIntegral[(a + b*ArcSin[c + d*x])/b])/(2*b^3*d)}
{1/(a + b*ArcSin[c + d*x])^4, x, 7, -(Sqrt[1 - (c + d*x)^2]/(3*b*d*(a + b*ArcSin[c + d*x])^3)) + (c + d*x)/(6*b^2*d*(a + b*ArcSin[c + d*x])^2) + Sqrt[1 - (c + d*x)^2]/(6*b^3*d*(a + b*ArcSin[c + d*x])) - (CosIntegral[(a + b*ArcSin[c + d*x])/b]*Sin[a/b])/(6*b^4*d) + (Cos[a/b]*SinIntegral[(a + b*ArcSin[c + d*x])/b])/(6*b^4*d)}
{1/(a + b*ArcSin[c + d*x])^5, x, 6, -(Sqrt[1 - (c + d*x)^2]/(4*b*d*(a + b*ArcSin[c + d*x])^4)) + (c + d*x)/(12*b^2*d*(a + b*ArcSin[c + d*x])^3) + Sqrt[1 - (c + d*x)^2]/(24*b^3*d*(a + b*ArcSin[c + d*x])^2) - (c + d*x)/(24*b^4*d*(a + b*ArcSin[c + d*x])) + (Cos[a/b]*CosIntegral[(a + b*ArcSin[c + d*x])/b])/(24*b^5*d) + (Sin[a/b]*SinIntegral[(a + b*ArcSin[c + d*x])/b])/(24*b^5*d)}


(* ::Subsubsection::Closed:: *)
(*n/2*)


{(a + b*ArcSin[c + d*x])^(7/2), x, 8, -((105*b^3*Sqrt[1 - (c + d*x)^2]*Sqrt[a + b*ArcSin[c + d*x]])/(8*d)) - (35*b^2*(c + d*x)*(a + b*ArcSin[c + d*x])^(3/2))/(4*d) + (7*b*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^(5/2))/(2*d) + ((c + d*x)*(a + b*ArcSin[c + d*x])^(7/2))/d + (105*b^(7/2)*Sqrt[Pi/2]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(8*d) + (105*b^(7/2)*Sqrt[Pi/2]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(8*d)}
{(a + b*ArcSin[c + d*x])^(5/2), x, 7, -((15*b^2*(c + d*x)*Sqrt[a + b*ArcSin[c + d*x]])/(4*d)) + (5*b*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^(3/2))/(2*d) + ((c + d*x)*(a + b*ArcSin[c + d*x])^(5/2))/d + (15*b^(5/2)*Sqrt[Pi/2]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(4*d) - (15*b^(5/2)*Sqrt[Pi/2]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(4*d)}
{(a + b*ArcSin[c + d*x])^(3/2), x, 7, (3*b*Sqrt[1 - (c + d*x)^2]*Sqrt[a + b*ArcSin[c + d*x]])/(2*d) + ((c + d*x)*(a + b*ArcSin[c + d*x])^(3/2))/d - (3*b^(3/2)*Sqrt[Pi/2]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(2*d) - (3*b^(3/2)*Sqrt[Pi/2]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(2*d)}
{(a + b*ArcSin[c + d*x])^(1/2), x, 6, ((c + d*x)*Sqrt[a + b*ArcSin[c + d*x]])/d - (Sqrt[b]*Sqrt[Pi/2]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/d + (Sqrt[b]*Sqrt[Pi/2]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/d}
{1/(a + b*ArcSin[c + d*x])^(1/2), x, 6, (Sqrt[2*Pi]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(Sqrt[b]*d) + (Sqrt[2*Pi]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(Sqrt[b]*d)}
{1/(a + b*ArcSin[c + d*x])^(3/2), x, 6, -((2*Sqrt[1 - (c + d*x)^2])/(b*d*Sqrt[a + b*ArcSin[c + d*x]])) - (2*Sqrt[2*Pi]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(b^(3/2)*d) + (2*Sqrt[2*Pi]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(b^(3/2)*d)}
{1/(a + b*ArcSin[c + d*x])^(5/2), x, 7, -((2*Sqrt[1 - (c + d*x)^2])/(3*b*d*(a + b*ArcSin[c + d*x])^(3/2))) + (4*(c + d*x))/(3*b^2*d*Sqrt[a + b*ArcSin[c + d*x]]) - (4*Sqrt[2*Pi]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(3*b^(5/2)*d) - (4*Sqrt[2*Pi]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(3*b^(5/2)*d)}
{1/(a + b*ArcSin[c + d*x])^(7/2), x, 7, -((2*Sqrt[1 - (c + d*x)^2])/(5*b*d*(a + b*ArcSin[c + d*x])^(5/2))) + (4*(c + d*x))/(15*b^2*d*(a + b*ArcSin[c + d*x])^(3/2)) + (8*Sqrt[1 - (c + d*x)^2])/(15*b^3*d*Sqrt[a + b*ArcSin[c + d*x]]) + (8*Sqrt[2*Pi]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(15*b^(7/2)*d) - (8*Sqrt[2*Pi]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(15*b^(7/2)*d)}


{x*(a + b*ArcSin[c + d*x])^(5/2), x, 20, (15*b^2*Sqrt[a + b*ArcSin[c + d*x]])/(64*d^2) + (15*b^2*c*(c + d*x)*Sqrt[a + b*ArcSin[c + d*x]])/(4*d^2) - (15*b^2*(c + d*x)^2*Sqrt[a + b*ArcSin[c + d*x]])/(32*d^2) - (5*b*c*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^(3/2))/(2*d^2) + (5*b*(c + d*x)*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^(3/2))/(8*d^2) - (a + b*ArcSin[c + d*x])^(5/2)/(4*d^2) - (c*(c + d*x)*(a + b*ArcSin[c + d*x])^(5/2))/d^2 + ((c + d*x)^2*(a + b*ArcSin[c + d*x])^(5/2))/(2*d^2) - (15*b^(5/2)*Sqrt[Pi]*Cos[(2*a)/b]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(128*d^2) - (15*b^(5/2)*c*Sqrt[Pi/2]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(4*d^2) + (15*b^(5/2)*c*Sqrt[Pi/2]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(4*d^2) - (15*b^(5/2)*Sqrt[Pi]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(128*d^2)}
{x*(a + b*ArcSin[c + d*x])^(3/2), x, 18, -((3*b*c*Sqrt[1 - (c + d*x)^2]*Sqrt[a + b*ArcSin[c + d*x]])/(2*d^2)) + (3*b*(c + d*x)*Sqrt[1 - (c + d*x)^2]*Sqrt[a + b*ArcSin[c + d*x]])/(8*d^2) - (a + b*ArcSin[c + d*x])^(3/2)/(4*d^2) - (c*(c + d*x)*(a + b*ArcSin[c + d*x])^(3/2))/d^2 + ((c + d*x)^2*(a + b*ArcSin[c + d*x])^(3/2))/(2*d^2) + (3*b^(3/2)*c*Sqrt[Pi/2]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(2*d^2) - (3*b^(3/2)*Sqrt[Pi]*Cos[(2*a)/b]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(32*d^2) + (3*b^(3/2)*c*Sqrt[Pi/2]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(2*d^2) + (3*b^(3/2)*Sqrt[Pi]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(32*d^2)}
{x*(a + b*ArcSin[c + d*x])^(1/2), x, 16, -(Sqrt[a + b*ArcSin[c + d*x]]/(4*d^2)) - (c*(c + d*x)*Sqrt[a + b*ArcSin[c + d*x]])/d^2 + ((c + d*x)^2*Sqrt[a + b*ArcSin[c + d*x]])/(2*d^2) + (Sqrt[b]*Sqrt[Pi]*Cos[(2*a)/b]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(8*d^2) + (Sqrt[b]*c*Sqrt[Pi/2]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/d^2 - (Sqrt[b]*c*Sqrt[Pi/2]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/d^2 + (Sqrt[b]*Sqrt[Pi]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(8*d^2)}
{x/(a + b*ArcSin[c + d*x])^(1/2), x, 14, -((c*Sqrt[2*Pi]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(Sqrt[b]*d^2)) + (Sqrt[Pi]*Cos[(2*a)/b]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(2*Sqrt[b]*d^2) - (c*Sqrt[2*Pi]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(Sqrt[b]*d^2) - (Sqrt[Pi]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(2*Sqrt[b]*d^2)}
{x/(a + b*ArcSin[c + d*x])^(3/2), x, 12, (2*c*Sqrt[1 - (c + d*x)^2])/(b*d^2*Sqrt[a + b*ArcSin[c + d*x]]) - (2*(c + d*x)*Sqrt[1 - (c + d*x)^2])/(b*d^2*Sqrt[a + b*ArcSin[c + d*x]]) + (2*Sqrt[Pi]*Cos[(2*a)/b]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(b^(3/2)*d^2) + (2*c*Sqrt[2*Pi]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(b^(3/2)*d^2) - (2*c*Sqrt[2*Pi]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(b^(3/2)*d^2) + (2*Sqrt[Pi]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(b^(3/2)*d^2)}
{x/(a + b*ArcSin[c + d*x])^(5/2), x, 17, (2*c*Sqrt[1 - (c + d*x)^2])/(3*b*d^2*(a + b*ArcSin[c + d*x])^(3/2)) - (2*(c + d*x)*Sqrt[1 - (c + d*x)^2])/(3*b*d^2*(a + b*ArcSin[c + d*x])^(3/2)) - 4/(3*b^2*d^2*Sqrt[a + b*ArcSin[c + d*x]]) - (4*c*(c + d*x))/(3*b^2*d^2*Sqrt[a + b*ArcSin[c + d*x]]) + (8*(c + d*x)^2)/(3*b^2*d^2*Sqrt[a + b*ArcSin[c + d*x]]) + (4*c*Sqrt[2*Pi]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(3*b^(5/2)*d^2) - (8*Sqrt[Pi]*Cos[(2*a)/b]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(3*b^(5/2)*d^2) + (4*c*Sqrt[2*Pi]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(3*b^(5/2)*d^2) + (8*Sqrt[Pi]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(3*b^(5/2)*d^2)}
{x/(a + b*ArcSin[c + d*x])^(7/2), x, 15, (2*c*Sqrt[1 - (c + d*x)^2])/(5*b*d^2*(a + b*ArcSin[c + d*x])^(5/2)) - (2*(c + d*x)*Sqrt[1 - (c + d*x)^2])/(5*b*d^2*(a + b*ArcSin[c + d*x])^(5/2)) - 4/(15*b^2*d^2*(a + b*ArcSin[c + d*x])^(3/2)) - (4*c*(c + d*x))/(15*b^2*d^2*(a + b*ArcSin[c + d*x])^(3/2)) + (8*(c + d*x)^2)/(15*b^2*d^2*(a + b*ArcSin[c + d*x])^(3/2)) - (8*c*Sqrt[1 - (c + d*x)^2])/(15*b^3*d^2*Sqrt[a + b*ArcSin[c + d*x]]) + (32*(c + d*x)*Sqrt[1 - (c + d*x)^2])/(15*b^3*d^2*Sqrt[a + b*ArcSin[c + d*x]]) - (32*Sqrt[Pi]*Cos[(2*a)/b]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(15*b^(7/2)*d^2) - (8*c*Sqrt[2*Pi]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(15*b^(7/2)*d^2) + (8*c*Sqrt[2*Pi]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(15*b^(7/2)*d^2) - (32*Sqrt[Pi]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(15*b^(7/2)*d^2)}


{x^2*(a + b*ArcSin[c + d*x])^(1/2), x, 27, (c*Sqrt[a + b*ArcSin[c + d*x]])/(2*d^3) + (c^2*(c + d*x)*Sqrt[a + b*ArcSin[c + d*x]])/d^3 - (c*(c + d*x)^2*Sqrt[a + b*ArcSin[c + d*x]])/d^3 + ((c + d*x)^3*Sqrt[a + b*ArcSin[c + d*x]])/(3*d^3) - (Sqrt[b]*c*Sqrt[Pi]*Cos[(2*a)/b]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(4*d^3) - (Sqrt[b]*Sqrt[Pi/2]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(4*d^3) - (Sqrt[b]*c^2*Sqrt[Pi/2]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/d^3 + (Sqrt[b]*Sqrt[Pi/6]*Cos[(3*a)/b]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(12*d^3) + (Sqrt[b]*Sqrt[Pi/2]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(4*d^3) + (Sqrt[b]*c^2*Sqrt[Pi/2]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/d^3 - (Sqrt[b]*c*Sqrt[Pi]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(4*d^3) - (Sqrt[b]*Sqrt[Pi/6]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(3*a)/b])/(12*d^3)}
{x^2/(a + b*ArcSin[c + d*x])^(1/2), x, 24, (Sqrt[Pi/2]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(2*Sqrt[b]*d^3) + (c^2*Sqrt[2*Pi]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(Sqrt[b]*d^3) - (Sqrt[Pi/6]*Cos[(3*a)/b]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(2*Sqrt[b]*d^3) - (c*Sqrt[Pi]*Cos[(2*a)/b]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(Sqrt[b]*d^3) + (Sqrt[Pi/2]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(2*Sqrt[b]*d^3) + (c^2*Sqrt[2*Pi]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(Sqrt[b]*d^3) + (c*Sqrt[Pi]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(Sqrt[b]*d^3) - (Sqrt[Pi/6]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(3*a)/b])/(2*Sqrt[b]*d^3)}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{x^2*(a + b*ArcSin[c + d*x])^n, x, 25, (c*(a + b*ArcSin[c + d*x])^n)/(2*d^3) - (c*(c + d*x)^2*(a + b*ArcSin[c + d*x])^n)/d^3 + ((c + d*x)^3*(a + b*ArcSin[c + d*x])^n)/(3*d^3) - (I*n*(a + b*ArcSin[c + d*x])^n*Gamma[n, -((I*(a + b*ArcSin[c + d*x]))/b)])/(E^((I*a)/b)*(-((I*(a + b*ArcSin[c + d*x]))/b))^n*(8*d^3)) + (I*E^((I*a)/b)*n*(a + b*ArcSin[c + d*x])^n*Gamma[n, (I*(a + b*ArcSin[c + d*x]))/b])/(((I*(a + b*ArcSin[c + d*x]))/b)^n*(8*d^3)) + (2^(-2 - n)*c*n*(a + b*ArcSin[c + d*x])^n*Gamma[n, -((2*I*(a + b*ArcSin[c + d*x]))/b)])/(E^((2*I*a)/b)*(-((I*(a + b*ArcSin[c + d*x]))/b))^n*d^3) + (2^(-2 - n)*c*E^((2*I*a)/b)*n*(a + b*ArcSin[c + d*x])^n*Gamma[n, (2*I*(a + b*ArcSin[c + d*x]))/b])/(((I*(a + b*ArcSin[c + d*x]))/b)^n*d^3) + (I*3^(-1 - n)*n*(a + b*ArcSin[c + d*x])^n*Gamma[n, -((3*I*(a + b*ArcSin[c + d*x]))/b)])/(E^((3*I*a)/b)*(-((I*(a + b*ArcSin[c + d*x]))/b))^n*(8*d^3)) - (I*3^(-1 - n)*E^((3*I*a)/b)*n*(a + b*ArcSin[c + d*x])^n*Gamma[n, (3*I*(a + b*ArcSin[c + d*x]))/b])/(((I*(a + b*ArcSin[c + d*x]))/b)^n*(8*d^3)) - (I*c^2*(a + b*ArcSin[c + d*x])^n*Gamma[1 + n, -((I*(a + b*ArcSin[c + d*x]))/b)])/(E^((I*a)/b)*(-((I*(a + b*ArcSin[c + d*x]))/b))^n*(2*d^3)) + (I*c^2*E^((I*a)/b)*(a + b*ArcSin[c + d*x])^n*Gamma[1 + n, (I*(a + b*ArcSin[c + d*x]))/b])/(((I*(a + b*ArcSin[c + d*x]))/b)^n*(2*d^3))}
{x^1*(a + b*ArcSin[c + d*x])^n, x, 14, -((a + b*ArcSin[c + d*x])^n/(4*d^2)) + ((c + d*x)^2*(a + b*ArcSin[c + d*x])^n)/(2*d^2) - (2^(-3 - n)*n*(a + b*ArcSin[c + d*x])^n*Gamma[n, -((2*I*(a + b*ArcSin[c + d*x]))/b)])/(E^((2*I*a)/b)*(-((I*(a + b*ArcSin[c + d*x]))/b))^n*d^2) - (2^(-3 - n)*E^((2*I*a)/b)*n*(a + b*ArcSin[c + d*x])^n*Gamma[n, (2*I*(a + b*ArcSin[c + d*x]))/b])/(((I*(a + b*ArcSin[c + d*x]))/b)^n*d^2) + (I*c*(a + b*ArcSin[c + d*x])^n*Gamma[1 + n, -((I*(a + b*ArcSin[c + d*x]))/b)])/(E^((I*a)/b)*(-((I*(a + b*ArcSin[c + d*x]))/b))^n*(2*d^2)) - (I*c*E^((I*a)/b)*(a + b*ArcSin[c + d*x])^n*Gamma[1 + n, (I*(a + b*ArcSin[c + d*x]))/b])/(((I*(a + b*ArcSin[c + d*x]))/b)^n*(2*d^2))}
{x^0*(a + b*ArcSin[c + d*x])^n, x, 4, -((I*(a + b*ArcSin[c + d*x])^n*Gamma[1 + n, -((I*(a + b*ArcSin[c + d*x]))/b)])/(E^((I*a)/b)*(-((I*(a + b*ArcSin[c + d*x]))/b))^n*(2*d))) + (I*E^((I*a)/b)*(a + b*ArcSin[c + d*x])^n*Gamma[1 + n, (I*(a + b*ArcSin[c + d*x]))/b])/(((I*(a + b*ArcSin[c + d*x]))/b)^n*(2*d))}
{(a + b*ArcSin[c + d*x])^n/x^1, x, 0, Int[(a + b*ArcSin[c + d*x])^n/x, x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c e+d e x)^m (a+b ArcSin[c+d x])^n*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{(a + b*ArcSin[c + d*x])*(e*c + e*d*x)^m, x, 3, ((c*e + d*e*x)^(1 + m)*(a + b*ArcSin[c + d*x]))/(d*e*(1 + m)) - (b*(c + d*x)*(c*e + d*e*x)^(1 + m)*Hypergeometric2F1[1/2, (2 + m)/2, (4 + m)/2, (c + d*x)^2])/(d*e*(2 + 3*m + m^2))}

{(a + b*ArcSin[c + d*x])*(e*c + e*d*x)^4, x, 5, (8*b*e^4*Sqrt[1 - (c + d*x)^2])/(75*d) + (4*b*e^4*(c + d*x)^2*Sqrt[1 - (c + d*x)^2])/(75*d) + (b*e^4*(c + d*x)^4*Sqrt[1 - (c + d*x)^2])/(25*d) + (e^4*(c + d*x)^5*(a + b*ArcSin[c + d*x]))/(5*d)}
{(a + b*ArcSin[c + d*x])*(e*c + e*d*x)^3, x, 5, (3*b*e^3*(c + d*x)*Sqrt[1 - (c + d*x)^2])/(32*d) + (b*e^3*(c + d*x)^3*Sqrt[1 - (c + d*x)^2])/(16*d) - (3*b*e^3*ArcSin[c + d*x])/(32*d) + (e^3*(c + d*x)^4*(a + b*ArcSin[c + d*x]))/(4*d)}
{(a + b*ArcSin[c + d*x])*(e*c + e*d*x)^2, x, 4, (2*b*e^2*Sqrt[1 - (c + d*x)^2])/(9*d) + (b*e^2*(c + d*x)^2*Sqrt[1 - (c + d*x)^2])/(9*d) + (e^2*(c + d*x)^3*(a + b*ArcSin[c + d*x]))/(3*d)}
{(a + b*ArcSin[c + d*x])*(e*c + e*d*x)^1, x, 4, (b*e*(c + d*x)*Sqrt[1 - (c + d*x)^2])/(4*d) - (b*e*ArcSin[c + d*x])/(4*d) + (e*(c + d*x)^2*(a + b*ArcSin[c + d*x]))/(2*d)}
{(a + b*ArcSin[c + d*x])*(e*c + e*d*x)^0, x, 2, a*x + (b*Sqrt[1 - (c + d*x)^2])/d + (b*(c + d*x)*ArcSin[c + d*x])/d}
{(a + b*ArcSin[c + d*x])/(e*c + e*d*x)^1, x, 5, -((I*(a + b*ArcSin[c + d*x])^2)/(2*b*d*e)) + ((a + b*ArcSin[c + d*x])*Log[1 - E^(2*I*ArcSin[c + d*x])])/(d*e) - (I*b*PolyLog[2, E^(2*I*ArcSin[c + d*x])])/(2*d*e)}
{(a + b*ArcSin[c + d*x])/(e*c + e*d*x)^2, x, 4, -((a + b*ArcSin[c + d*x])/(d*e^2*(c + d*x))) - (b*ArcTanh[Sqrt[1 - (c + d*x)^2]])/(d*e^2)}
{(a + b*ArcSin[c + d*x])/(e*c + e*d*x)^3, x, 3, -((b*Sqrt[1 - (c + d*x)^2])/(2*d*e^3*(c + d*x))) - (a + b*ArcSin[c + d*x])/(2*d*e^3*(c + d*x)^2)}
{(a + b*ArcSin[c + d*x])/(e*c + e*d*x)^4, x, 5, -((b*Sqrt[1 - (c + d*x)^2])/(6*d*e^4*(c + d*x)^2)) - (a + b*ArcSin[c + d*x])/(3*d*e^4*(c + d*x)^3) - (b*ArcTanh[Sqrt[1 - (c + d*x)^2]])/(6*d*e^4)}
{(a + b*ArcSin[c + d*x])/(e*c + e*d*x)^5, x, 4, -((b*Sqrt[1 - (c + d*x)^2])/(12*d*e^5*(c + d*x)^3)) - (b*Sqrt[1 - (c + d*x)^2])/(6*d*e^5*(c + d*x)) - (a + b*ArcSin[c + d*x])/(4*d*e^5*(c + d*x)^4)}
{(a + b*ArcSin[c + d*x])/(e*c + e*d*x)^6, x, 6, -((b*Sqrt[1 - (c + d*x)^2])/(20*d*e^6*(c + d*x)^4)) - (3*b*Sqrt[1 - (c + d*x)^2])/(40*d*e^6*(c + d*x)^2) - (a + b*ArcSin[c + d*x])/(5*d*e^6*(c + d*x)^5) - (3*b*ArcTanh[Sqrt[1 - (c + d*x)^2]])/(40*d*e^6)}


{(a + b*ArcSin[c + d*x])^2*(e*c + e*d*x)^m, x, 2, ((c*e + d*e*x)^(1 + m)*(a + b*ArcSin[c + d*x])^2)/(d*e*(1 + m)) - (2*b*(c + d*x)*(c*e + d*e*x)^(1 + m)*(a + b*ArcSin[c + d*x])*Hypergeometric2F1[1/2, (2 + m)/2, (4 + m)/2, (c + d*x)^2])/(d*e*(2 + 3*m + m^2)) + (2*b^2*(c + d*x)^2*(c*e + d*e*x)^(1 + m)*HypergeometricPFQ[{1, 3/2 + m/2, 3/2 + m/2}, {2 + m/2, 5/2 + m/2}, (c + d*x)^2])/(d*e*(1 + m)*(6 + 5*m + m^2))}

{(a + b*ArcSin[c + d*x])^2*(e*c + e*d*x)^4, x, 7, (-(16/75))*b^2*e^4*x - (8*b^2*e^4*(c + d*x)^3)/(225*d) - (2*b^2*e^4*(c + d*x)^5)/(125*d) + (16*b*e^4*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x]))/(75*d) + (8*b*e^4*(c + d*x)^2*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x]))/(75*d) + (2*b*e^4*(c + d*x)^4*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x]))/(25*d) + (e^4*(c + d*x)^5*(a + b*ArcSin[c + d*x])^2)/(5*d)}
{(a + b*ArcSin[c + d*x])^2*(e*c + e*d*x)^3, x, 6, (-(3/16))*b^2*c*e^3*x - (3/32)*b^2*d*e^3*x^2 - (b^2*e^3*(c + d*x)^4)/(32*d) + (3*b*e^3*(c + d*x)*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x]))/(16*d) + (b*e^3*(c + d*x)^3*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x]))/(8*d) - (3*e^3*(a + b*ArcSin[c + d*x])^2)/(32*d) + (e^3*(c + d*x)^4*(a + b*ArcSin[c + d*x])^2)/(4*d)}
{(a + b*ArcSin[c + d*x])^2*(e*c + e*d*x)^2, x, 5, (-(4/9))*b^2*e^2*x - (2*b^2*e^2*(c + d*x)^3)/(27*d) + (4*b*e^2*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x]))/(9*d) + (2*b*e^2*(c + d*x)^2*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x]))/(9*d) + (e^2*(c + d*x)^3*(a + b*ArcSin[c + d*x])^2)/(3*d)}
{(a + b*ArcSin[c + d*x])^2*(e*c + e*d*x)^1, x, 4, (-(1/2))*b^2*c*e*x - (1/4)*b^2*d*e*x^2 + (b*e*(c + d*x)*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x]))/(2*d) - (e*(a + b*ArcSin[c + d*x])^2)/(4*d) + (e*(c + d*x)^2*(a + b*ArcSin[c + d*x])^2)/(2*d)}
{(a + b*ArcSin[c + d*x])^2*(e*c + e*d*x)^0, x, 2, -2*b^2*x + (2*b*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x]))/d + ((c + d*x)*(a + b*ArcSin[c + d*x])^2)/d}
{(a + b*ArcSin[c + d*x])^2/(e*c + e*d*x)^1, x, 6, -((I*(a + b*ArcSin[c + d*x])^3)/(3*b*d*e)) + ((a + b*ArcSin[c + d*x])^2*Log[1 - E^(2*I*ArcSin[c + d*x])])/(d*e) - (I*b*(a + b*ArcSin[c + d*x])*PolyLog[2, E^(2*I*ArcSin[c + d*x])])/(d*e) + (b^2*PolyLog[3, E^(2*I*ArcSin[c + d*x])])/(2*d*e)}
{(a + b*ArcSin[c + d*x])^2/(e*c + e*d*x)^2, x, 6, -((a + b*ArcSin[c + d*x])^2/(d*e^2*(c + d*x))) - (4*I*b^2*ArcSin[c + d*x]*ArcTan[c + d*x - I*Sqrt[1 - (c + d*x)^2]])/(d*e^2) - (2*a*b*ArcTanh[Sqrt[1 - (c + d*x)^2]])/(d*e^2) + (2*I*b^2*PolyLog[2, (-I)*(c + d*x) - Sqrt[1 - (c + d*x)^2]])/(d*e^2) - (2*I*b^2*PolyLog[2, I*(c + d*x) + Sqrt[1 - (c + d*x)^2]])/(d*e^2)}
{(a + b*ArcSin[c + d*x])^2/(e*c + e*d*x)^3, x, 3, -((b*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x]))/(d*e^3*(c + d*x))) - (a + b*ArcSin[c + d*x])^2/(2*d*e^3*(c + d*x)^2) + (b^2*Log[c + d*x])/(d*e^3)}
{(a + b*ArcSin[c + d*x])^2/(e*c + e*d*x)^4, x, 8, -(b^2/(3*d*e^4*(c + d*x))) - (b*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x]))/(3*d*e^4*(c + d*x)^2) - (a + b*ArcSin[c + d*x])^2/(3*d*e^4*(c + d*x)^3) - (2*I*b^2*ArcSin[c + d*x]*ArcTan[c + d*x - I*Sqrt[1 - (c + d*x)^2]])/(3*d*e^4) - (a*b*ArcTanh[Sqrt[1 - (c + d*x)^2]])/(3*d*e^4) + (I*b^2*PolyLog[2, (-I)*(c + d*x) - Sqrt[1 - (c + d*x)^2]])/(3*d*e^4) - (I*b^2*PolyLog[2, I*(c + d*x) + Sqrt[1 - (c + d*x)^2]])/(3*d*e^4)}


{(a + b*ArcSin[c + d*x])^3*(e*c + e*d*x)^m, x, 1, ((c*e + d*e*x)^(1 + m)*(a + b*ArcSin[c + d*x])^3)/(d*e*(1 + m)) - (3*b*Int[((c*e + d*e*x)^(1 + m)*(a + b*ArcSin[c + d*x])^2)/Sqrt[1 - (c + d*x)^2], x])/(e*(1 + m))}

{(a + b*ArcSin[c + d*x])^3*(e*c + e*d*x)^4, x, 15, (-(16/25))*a*b^2*e^4*x - (4144*b^3*e^4*Sqrt[1 - (c + d*x)^2])/(5625*d) - (272*b^3*e^4*(c + d*x)^2*Sqrt[1 - (c + d*x)^2])/(5625*d) - (6*b^3*e^4*(c + d*x)^4*Sqrt[1 - (c + d*x)^2])/(625*d) - (16*b^3*e^4*(c + d*x)*ArcSin[c + d*x])/(25*d) - (8*b^2*e^4*(c + d*x)^3*(a + b*ArcSin[c + d*x]))/(75*d) - (6*b^2*e^4*(c + d*x)^5*(a + b*ArcSin[c + d*x]))/(125*d) + (8*b*e^4*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^2)/(25*d) + (4*b*e^4*(c + d*x)^2*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^2)/(25*d) + (3*b*e^4*(c + d*x)^4*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^2)/(25*d) + (e^4*(c + d*x)^5*(a + b*ArcSin[c + d*x])^3)/(5*d)}
{(a + b*ArcSin[c + d*x])^3*(e*c + e*d*x)^3, x, 13, -((45*b^3*e^3*(c + d*x)*Sqrt[1 - (c + d*x)^2])/(256*d)) - (3*b^3*e^3*(c + d*x)^3*Sqrt[1 - (c + d*x)^2])/(128*d) + (45*b^3*e^3*ArcSin[c + d*x])/(256*d) - (9*b^2*e^3*(c + d*x)^2*(a + b*ArcSin[c + d*x]))/(32*d) - (3*b^2*e^3*(c + d*x)^4*(a + b*ArcSin[c + d*x]))/(32*d) + (9*b*e^3*(c + d*x)*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^2)/(32*d) + (3*b*e^3*(c + d*x)^3*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^2)/(16*d) - (3*e^3*(a + b*ArcSin[c + d*x])^3)/(32*d) + (e^3*(c + d*x)^4*(a + b*ArcSin[c + d*x])^3)/(4*d)}
{(a + b*ArcSin[c + d*x])^3*(e*c + e*d*x)^2, x, 9, (-(4/3))*a*b^2*e^2*x - (40*b^3*e^2*Sqrt[1 - (c + d*x)^2])/(27*d) - (2*b^3*e^2*(c + d*x)^2*Sqrt[1 - (c + d*x)^2])/(27*d) - (4*b^3*e^2*(c + d*x)*ArcSin[c + d*x])/(3*d) - (2*b^2*e^2*(c + d*x)^3*(a + b*ArcSin[c + d*x]))/(9*d) + (2*b*e^2*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^2)/(3*d) + (b*e^2*(c + d*x)^2*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^2)/(3*d) + (e^2*(c + d*x)^3*(a + b*ArcSin[c + d*x])^3)/(3*d)}
{(a + b*ArcSin[c + d*x])^3*(e*c + e*d*x)^1, x, 7, -((3*b^3*e*(c + d*x)*Sqrt[1 - (c + d*x)^2])/(8*d)) + (3*b^3*e*ArcSin[c + d*x])/(8*d) - (3*b^2*e*(c + d*x)^2*(a + b*ArcSin[c + d*x]))/(4*d) + (3*b*e*(c + d*x)*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^2)/(4*d) - (e*(a + b*ArcSin[c + d*x])^3)/(4*d) + (e*(c + d*x)^2*(a + b*ArcSin[c + d*x])^3)/(2*d)}
{(a + b*ArcSin[c + d*x])^3*(e*c + e*d*x)^0, x, 3, -6*a*b^2*x - (6*b^3*Sqrt[1 - (c + d*x)^2])/d - (6*b^3*(c + d*x)*ArcSin[c + d*x])/d + (3*b*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^2)/d + ((c + d*x)*(a + b*ArcSin[c + d*x])^3)/d}
{(a + b*ArcSin[c + d*x])^3/(e*c + e*d*x)^1, x, 7, -((I*(a + b*ArcSin[c + d*x])^4)/(4*b*d*e)) + ((a + b*ArcSin[c + d*x])^3*Log[1 - E^(2*I*ArcSin[c + d*x])])/(d*e) - (3*I*b*(a + b*ArcSin[c + d*x])^2*PolyLog[2, E^(2*I*ArcSin[c + d*x])])/(2*d*e) + (3*b^2*(a + b*ArcSin[c + d*x])*PolyLog[3, E^(2*I*ArcSin[c + d*x])])/(2*d*e) + (3*I*b^3*PolyLog[4, E^(2*I*ArcSin[c + d*x])])/(4*d*e)}
{(a + b*ArcSin[c + d*x])^3/(e*c + e*d*x)^2, x, 8, -((a + b*ArcSin[c + d*x])^3/(d*e^2*(c + d*x))) - (6*b*(a + b*ArcSin[c + d*x])^2*ArcTanh[E^((I*a)/b - (I*(a + b*ArcSin[c + d*x]))/b)])/(d*e^2) - (6*I*b^2*(a + b*ArcSin[c + d*x])*PolyLog[2, -E^((-I)*ArcSin[c + d*x])])/(d*e^2) + (6*I*b^2*(a + b*ArcSin[c + d*x])*PolyLog[2, E^((-I)*ArcSin[c + d*x])])/(d*e^2) - (6*b^3*PolyLog[3, -E^((-I)*ArcSin[c + d*x])])/(d*e^2) + (6*b^3*PolyLog[3, E^((-I)*ArcSin[c + d*x])])/(d*e^2)}
{(a + b*ArcSin[c + d*x])^3/(e*c + e*d*x)^3, x, 7, -((3*I*b*(a + b*ArcSin[c + d*x])^2)/(2*d*e^3)) - (3*b*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^2)/(2*d*e^3*(c + d*x)) - (a + b*ArcSin[c + d*x])^3/(2*d*e^3*(c + d*x)^2) + (3*b^2*(a + b*ArcSin[c + d*x])*Log[1 - E^(2*I*ArcSin[c + d*x])])/(d*e^3) - (3*I*b^3*PolyLog[2, E^(2*I*ArcSin[c + d*x])])/(2*d*e^3)}
{(a + b*ArcSin[c + d*x])^3/(e*c + e*d*x)^4, x, 13, -((b^2*(a + b*ArcSin[c + d*x]))/(d*e^4*(c + d*x))) - (b*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^2)/(2*d*e^4*(c + d*x)^2) - (a + b*ArcSin[c + d*x])^3/(3*d*e^4*(c + d*x)^3) - (b*(a + b*ArcSin[c + d*x])^2*ArcTanh[E^((I*a)/b - (I*(a + b*ArcSin[c + d*x]))/b)])/(d*e^4) - (b^3*ArcTanh[Sqrt[1 - (c + d*x)^2]])/(d*e^4) - (I*b^2*(a + b*ArcSin[c + d*x])*PolyLog[2, -E^((-I)*ArcSin[c + d*x])])/(d*e^4) + (I*b^2*(a + b*ArcSin[c + d*x])*PolyLog[2, E^((-I)*ArcSin[c + d*x])])/(d*e^4) - (b^3*PolyLog[3, -E^((-I)*ArcSin[c + d*x])])/(d*e^4) + (b^3*PolyLog[3, E^((-I)*ArcSin[c + d*x])])/(d*e^4)}


{(a + b*ArcSin[c + d*x])^4*(e*c + e*d*x)^m, x, 1, ((c*e + d*e*x)^(1 + m)*(a + b*ArcSin[c + d*x])^4)/(d*e*(1 + m)) - (4*b*Int[((c*e + d*e*x)^(1 + m)*(a + b*ArcSin[c + d*x])^3)/Sqrt[1 - (c + d*x)^2], x])/(e*(1 + m))}

{(a + b*ArcSin[c + d*x])^4*(e*c + e*d*x)^3, x, 14, (45/64)*b^4*c*e^3*x + (45/128)*b^4*d*e^3*x^2 + (3*b^4*e^3*(c + d*x)^4)/(128*d) - (45*b^3*e^3*(c + d*x)*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x]))/(64*d) - (3*b^3*e^3*(c + d*x)^3*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x]))/(32*d) + (45*b^2*e^3*(a + b*ArcSin[c + d*x])^2)/(128*d) - (9*b^2*e^3*(c + d*x)^2*(a + b*ArcSin[c + d*x])^2)/(16*d) - (3*b^2*e^3*(c + d*x)^4*(a + b*ArcSin[c + d*x])^2)/(16*d) + (3*b*e^3*(c + d*x)*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^3)/(8*d) + (b*e^3*(c + d*x)^3*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^3)/(4*d) - (3*e^3*(a + b*ArcSin[c + d*x])^4)/(32*d) + (e^3*(c + d*x)^4*(a + b*ArcSin[c + d*x])^4)/(4*d)}
{(a + b*ArcSin[c + d*x])^4*(e*c + e*d*x)^2, x, 10, (160/27)*b^4*e^2*x + (8*b^4*e^2*(c + d*x)^3)/(81*d) - (160*b^3*e^2*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x]))/(27*d) - (8*b^3*e^2*(c + d*x)^2*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x]))/(27*d) - (8*b^2*e^2*(c + d*x)*(a + b*ArcSin[c + d*x])^2)/(3*d) - (4*b^2*e^2*(c + d*x)^3*(a + b*ArcSin[c + d*x])^2)/(9*d) + (8*b*e^2*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^3)/(9*d) + (4*b*e^2*(c + d*x)^2*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^3)/(9*d) + (e^2*(c + d*x)^3*(a + b*ArcSin[c + d*x])^4)/(3*d)}
{(a + b*ArcSin[c + d*x])^4*(e*c + e*d*x)^1, x, 7, (3/2)*b^4*c*e*x + (3/4)*b^4*d*e*x^2 - (3*b^3*e*(c + d*x)*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x]))/(2*d) + (3*b^2*e*(a + b*ArcSin[c + d*x])^2)/(4*d) - (3*b^2*e*(c + d*x)^2*(a + b*ArcSin[c + d*x])^2)/(2*d) + (b*e*(c + d*x)*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^3)/d - (e*(a + b*ArcSin[c + d*x])^4)/(4*d) + (e*(c + d*x)^2*(a + b*ArcSin[c + d*x])^4)/(2*d)}
{(a + b*ArcSin[c + d*x])^4*(e*c + e*d*x)^0, x, 3, 24*b^4*x - (24*b^3*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x]))/d - (12*b^2*(c + d*x)*(a + b*ArcSin[c + d*x])^2)/d + (4*b*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^3)/d + ((c + d*x)*(a + b*ArcSin[c + d*x])^4)/d}
{(a + b*ArcSin[c + d*x])^4/(e*c + e*d*x)^1, x, 8, -((I*(a + b*ArcSin[c + d*x])^5)/(5*b*d*e)) + ((a + b*ArcSin[c + d*x])^4*Log[1 - E^(2*I*ArcSin[c + d*x])])/(d*e) - (2*I*b*(a + b*ArcSin[c + d*x])^3*PolyLog[2, E^(2*I*ArcSin[c + d*x])])/(d*e) + (3*b^2*(a + b*ArcSin[c + d*x])^2*PolyLog[3, E^(2*I*ArcSin[c + d*x])])/(d*e) + (3*I*b^3*(a + b*ArcSin[c + d*x])*PolyLog[4, E^(2*I*ArcSin[c + d*x])])/(d*e) - (3*b^4*PolyLog[5, E^(2*I*ArcSin[c + d*x])])/(2*d*e)}
{(a + b*ArcSin[c + d*x])^4/(e*c + e*d*x)^2, x, 10, -((a + b*ArcSin[c + d*x])^4/(d*e^2*(c + d*x))) - (8*b*(a + b*ArcSin[c + d*x])^3*ArcTanh[E^((I*a)/b - (I*(a + b*ArcSin[c + d*x]))/b)])/(d*e^2) - (12*I*b^2*(a + b*ArcSin[c + d*x])^2*PolyLog[2, -E^((-I)*ArcSin[c + d*x])])/(d*e^2) + (12*I*b^2*(a + b*ArcSin[c + d*x])^2*PolyLog[2, E^((-I)*ArcSin[c + d*x])])/(d*e^2) - (24*b^3*(a + b*ArcSin[c + d*x])*PolyLog[3, -E^((-I)*ArcSin[c + d*x])])/(d*e^2) + (24*b^3*(a + b*ArcSin[c + d*x])*PolyLog[3, E^((-I)*ArcSin[c + d*x])])/(d*e^2) + (24*I*b^4*PolyLog[4, -E^((-I)*ArcSin[c + d*x])])/(d*e^2) - (24*I*b^4*PolyLog[4, E^((-I)*ArcSin[c + d*x])])/(d*e^2)}
{(a + b*ArcSin[c + d*x])^4/(e*c + e*d*x)^3, x, 8, -((2*I*b*(a + b*ArcSin[c + d*x])^3)/(d*e^3)) - (2*b*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^3)/(d*e^3*(c + d*x)) - (a + b*ArcSin[c + d*x])^4/(2*d*e^3*(c + d*x)^2) + (6*b^2*(a + b*ArcSin[c + d*x])^2*Log[1 - E^(2*I*ArcSin[c + d*x])])/(d*e^3) - (6*I*b^3*(a + b*ArcSin[c + d*x])*PolyLog[2, E^(2*I*ArcSin[c + d*x])])/(d*e^3) + (3*b^4*PolyLog[3, E^(2*I*ArcSin[c + d*x])])/(d*e^3)}
{(a + b*ArcSin[c + d*x])^4/(e*c + e*d*x)^4, x, 17, -((2*b^2*(a + b*ArcSin[c + d*x])^2)/(d*e^4*(c + d*x))) - (2*b*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^3)/(3*d*e^4*(c + d*x)^2) - (a + b*ArcSin[c + d*x])^4/(3*d*e^4*(c + d*x)^3) - (8*I*b^4*ArcSin[c + d*x]*ArcTan[c + d*x - I*Sqrt[1 - (c + d*x)^2]])/(d*e^4) - (4*b*(a + b*ArcSin[c + d*x])^3*ArcTanh[E^((I*a)/b - (I*(a + b*ArcSin[c + d*x]))/b)])/(3*d*e^4) - (4*a*b^3*ArcTanh[Sqrt[1 - (c + d*x)^2]])/(d*e^4) - (2*I*b^2*(a + b*ArcSin[c + d*x])^2*PolyLog[2, -E^((-I)*ArcSin[c + d*x])])/(d*e^4) + (2*I*b^2*(a + b*ArcSin[c + d*x])^2*PolyLog[2, E^((-I)*ArcSin[c + d*x])])/(d*e^4) + (4*I*b^4*PolyLog[2, (-I)*(c + d*x) - Sqrt[1 - (c + d*x)^2]])/(d*e^4) - (4*I*b^4*PolyLog[2, I*(c + d*x) + Sqrt[1 - (c + d*x)^2]])/(d*e^4) - (4*b^3*(a + b*ArcSin[c + d*x])*PolyLog[3, -E^((-I)*ArcSin[c + d*x])])/(d*e^4) + (4*b^3*(a + b*ArcSin[c + d*x])*PolyLog[3, E^((-I)*ArcSin[c + d*x])])/(d*e^4) + (4*I*b^4*PolyLog[4, -E^((-I)*ArcSin[c + d*x])])/(d*e^4) - (4*I*b^4*PolyLog[4, E^((-I)*ArcSin[c + d*x])])/(d*e^4)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{1/(a + b*ArcSin[c + d*x])*(e*c + e*d*x)^m, x, 1, Defer[Subst][Int[(e*x)^m/(a + b*ArcSin[x]), x], x, c + d*x]/d}

{1/(a + b*ArcSin[c + d*x])*(e*c + e*d*x)^4, x, 12, (e^4*Cos[a/b]*CosIntegral[(a + b*ArcSin[c + d*x])/b])/(8*b*d) - (3*e^4*Cos[(3*a)/b]*CosIntegral[(3*(a + b*ArcSin[c + d*x]))/b])/(16*b*d) + (e^4*Cos[(5*a)/b]*CosIntegral[(5*(a + b*ArcSin[c + d*x]))/b])/(16*b*d) + (e^4*Sin[a/b]*SinIntegral[(a + b*ArcSin[c + d*x])/b])/(8*b*d) - (3*e^4*Sin[(3*a)/b]*SinIntegral[(3*(a + b*ArcSin[c + d*x]))/b])/(16*b*d) + (e^4*Sin[(5*a)/b]*SinIntegral[(5*(a + b*ArcSin[c + d*x]))/b])/(16*b*d)}
{1/(a + b*ArcSin[c + d*x])*(e*c + e*d*x)^3, x, 9, -((e^3*CosIntegral[(2*(a + b*ArcSin[c + d*x]))/b]*Sin[(2*a)/b])/(4*b*d)) + (e^3*CosIntegral[(4*(a + b*ArcSin[c + d*x]))/b]*Sin[(4*a)/b])/(8*b*d) + (e^3*Cos[(2*a)/b]*SinIntegral[(2*(a + b*ArcSin[c + d*x]))/b])/(4*b*d) - (e^3*Cos[(4*a)/b]*SinIntegral[(4*(a + b*ArcSin[c + d*x]))/b])/(8*b*d)}
{1/(a + b*ArcSin[c + d*x])*(e*c + e*d*x)^2, x, 9, (e^2*Cos[a/b]*CosIntegral[(a + b*ArcSin[c + d*x])/b])/(4*b*d) - (e^2*Cos[(3*a)/b]*CosIntegral[(3*(a + b*ArcSin[c + d*x]))/b])/(4*b*d) + (e^2*Sin[a/b]*SinIntegral[(a + b*ArcSin[c + d*x])/b])/(4*b*d) - (e^2*Sin[(3*a)/b]*SinIntegral[(3*(a + b*ArcSin[c + d*x]))/b])/(4*b*d)}
{1/(a + b*ArcSin[c + d*x])*(e*c + e*d*x)^1, x, 6, -((e*CosIntegral[(2*(a + b*ArcSin[c + d*x]))/b]*Sin[(2*a)/b])/(2*b*d)) + (e*Cos[(2*a)/b]*SinIntegral[(2*(a + b*ArcSin[c + d*x]))/b])/(2*b*d)}
{1/(a + b*ArcSin[c + d*x])*(e*c + e*d*x)^0, x, 4, (Cos[a/b]*CosIntegral[(a + b*ArcSin[c + d*x])/b])/(b*d) + (Sin[a/b]*SinIntegral[(a + b*ArcSin[c + d*x])/b])/(b*d)}
{1/(a + b*ArcSin[c + d*x])/(e*c + e*d*x)^1, x, 0, Defer[Int][1/((c*e + d*e*x)*(a + b*ArcSin[c + d*x])), x]}


{1/(a + b*ArcSin[c + d*x])^2*(e*c + e*d*x)^4, x, 11, -((e^4*(c + d*x)^4*Sqrt[1 - (c + d*x)^2])/(b*d*(a + b*ArcSin[c + d*x]))) + (e^4*CosIntegral[(a + b*ArcSin[c + d*x])/b]*Sin[a/b])/(8*b^2*d) - (9*e^4*CosIntegral[(3*(a + b*ArcSin[c + d*x]))/b]*Sin[(3*a)/b])/(16*b^2*d) + (5*e^4*CosIntegral[(5*(a + b*ArcSin[c + d*x]))/b]*Sin[(5*a)/b])/(16*b^2*d) - (e^4*Cos[a/b]*SinIntegral[(a + b*ArcSin[c + d*x])/b])/(8*b^2*d) + (9*e^4*Cos[(3*a)/b]*SinIntegral[(3*(a + b*ArcSin[c + d*x]))/b])/(16*b^2*d) - (5*e^4*Cos[(5*a)/b]*SinIntegral[(5*(a + b*ArcSin[c + d*x]))/b])/(16*b^2*d)}
{1/(a + b*ArcSin[c + d*x])^2*(e*c + e*d*x)^3, x, 8, -((e^3*(c + d*x)^3*Sqrt[1 - (c + d*x)^2])/(b*d*(a + b*ArcSin[c + d*x]))) + (e^3*Cos[(2*a)/b]*CosIntegral[(2*(a + b*ArcSin[c + d*x]))/b])/(2*b^2*d) - (e^3*Cos[(4*a)/b]*CosIntegral[(4*(a + b*ArcSin[c + d*x]))/b])/(2*b^2*d) + (e^3*Sin[(2*a)/b]*SinIntegral[(2*(a + b*ArcSin[c + d*x]))/b])/(2*b^2*d) - (e^3*Sin[(4*a)/b]*SinIntegral[(4*(a + b*ArcSin[c + d*x]))/b])/(2*b^2*d)}
{1/(a + b*ArcSin[c + d*x])^2*(e*c + e*d*x)^2, x, 8, -((e^2*(c + d*x)^2*Sqrt[1 - (c + d*x)^2])/(b*d*(a + b*ArcSin[c + d*x]))) + (e^2*CosIntegral[(a + b*ArcSin[c + d*x])/b]*Sin[a/b])/(4*b^2*d) - (3*e^2*CosIntegral[(3*(a + b*ArcSin[c + d*x]))/b]*Sin[(3*a)/b])/(4*b^2*d) - (e^2*Cos[a/b]*SinIntegral[(a + b*ArcSin[c + d*x])/b])/(4*b^2*d) + (3*e^2*Cos[(3*a)/b]*SinIntegral[(3*(a + b*ArcSin[c + d*x]))/b])/(4*b^2*d)}
{1/(a + b*ArcSin[c + d*x])^2*(e*c + e*d*x)^1, x, 4, (e*Cos[(2*a)/b]*CosIntegral[(2*(a + b*ArcSin[c + d*x]))/b])/(b^2*d) - (e*(c + d*x)*Sqrt[1 - (c + d*x)^2])/(b*d*(a + b*ArcSin[c + d*x])) + (e*Sin[(2*a)/b]*SinIntegral[(2*(a + b*ArcSin[c + d*x]))/b])/(b^2*d)}
{1/(a + b*ArcSin[c + d*x])^2*(e*c + e*d*x)^0, x, 6, -(Sqrt[1 - (c + d*x)^2]/(b*d*(a + b*ArcSin[c + d*x]))) + (CosIntegral[(a + b*ArcSin[c + d*x])/b]*Sin[a/b])/(b^2*d) - (Cos[a/b]*SinIntegral[(a + b*ArcSin[c + d*x])/b])/(b^2*d)}
{1/(a + b*ArcSin[c + d*x])^2/(e*c + e*d*x)^1, x, 0, Defer[Int][1/((c*e + d*e*x)*(a + b*ArcSin[c + d*x])^2), x]}


{1/(a + b*ArcSin[c + d*x])^3*(e*c + e*d*x)^4, x, 22, -((e^4*(c + d*x)^4*Sqrt[1 - (c + d*x)^2])/(2*b*d*(a + b*ArcSin[c + d*x])^2)) - (2*e^4*(c + d*x)^3)/(b^2*d*(a + b*ArcSin[c + d*x])) + (5*e^4*(c + d*x)^5)/(2*b^2*d*(a + b*ArcSin[c + d*x])) - (e^4*Cos[a/b]*CosIntegral[(a + b*ArcSin[c + d*x])/b])/(16*b^3*d) + (27*e^4*Cos[(3*a)/b]*CosIntegral[(3*(a + b*ArcSin[c + d*x]))/b])/(32*b^3*d) - (25*e^4*Cos[(5*a)/b]*CosIntegral[(5*(a + b*ArcSin[c + d*x]))/b])/(32*b^3*d) - (e^4*Sin[a/b]*SinIntegral[(a + b*ArcSin[c + d*x])/b])/(16*b^3*d) + (27*e^4*Sin[(3*a)/b]*SinIntegral[(3*(a + b*ArcSin[c + d*x]))/b])/(32*b^3*d) - (25*e^4*Sin[(5*a)/b]*SinIntegral[(5*(a + b*ArcSin[c + d*x]))/b])/(32*b^3*d)}
{1/(a + b*ArcSin[c + d*x])^3*(e*c + e*d*x)^3, x, 16, -((e^3*(c + d*x)^3*Sqrt[1 - (c + d*x)^2])/(2*b*d*(a + b*ArcSin[c + d*x])^2)) - (3*e^3*(c + d*x)^2)/(2*b^2*d*(a + b*ArcSin[c + d*x])) + (2*e^3*(c + d*x)^4)/(b^2*d*(a + b*ArcSin[c + d*x])) + (e^3*CosIntegral[(2*(a + b*ArcSin[c + d*x]))/b]*Sin[(2*a)/b])/(2*b^3*d) - (e^3*CosIntegral[(4*(a + b*ArcSin[c + d*x]))/b]*Sin[(4*a)/b])/(b^3*d) - (e^3*Cos[(2*a)/b]*SinIntegral[(2*(a + b*ArcSin[c + d*x]))/b])/(2*b^3*d) + (e^3*Cos[(4*a)/b]*SinIntegral[(4*(a + b*ArcSin[c + d*x]))/b])/(b^3*d)}
{1/(a + b*ArcSin[c + d*x])^3*(e*c + e*d*x)^2, x, 14, -((e^2*(c + d*x)^2*Sqrt[1 - (c + d*x)^2])/(2*b*d*(a + b*ArcSin[c + d*x])^2)) - (e^2*(c + d*x))/(b^2*d*(a + b*ArcSin[c + d*x])) + (3*e^2*(c + d*x)^3)/(2*b^2*d*(a + b*ArcSin[c + d*x])) - (e^2*Cos[a/b]*CosIntegral[(a + b*ArcSin[c + d*x])/b])/(8*b^3*d) + (9*e^2*Cos[(3*a)/b]*CosIntegral[(3*(a + b*ArcSin[c + d*x]))/b])/(8*b^3*d) - (e^2*Sin[a/b]*SinIntegral[(a + b*ArcSin[c + d*x])/b])/(8*b^3*d) + (9*e^2*Sin[(3*a)/b]*SinIntegral[(3*(a + b*ArcSin[c + d*x]))/b])/(8*b^3*d)}
{1/(a + b*ArcSin[c + d*x])^3*(e*c + e*d*x)^1, x, 8, -((e*(c + d*x)*Sqrt[1 - (c + d*x)^2])/(2*b*d*(a + b*ArcSin[c + d*x])^2)) - e/(2*b^2*d*(a + b*ArcSin[c + d*x])) + (e*(c + d*x)^2)/(b^2*d*(a + b*ArcSin[c + d*x])) + (e*CosIntegral[(2*(a + b*ArcSin[c + d*x]))/b]*Sin[(2*a)/b])/(b^3*d) - (e*Cos[(2*a)/b]*SinIntegral[(2*(a + b*ArcSin[c + d*x]))/b])/(b^3*d)}
{1/(a + b*ArcSin[c + d*x])^3*(e*c + e*d*x)^0, x, 5, -(Sqrt[1 - (c + d*x)^2]/(2*b*d*(a + b*ArcSin[c + d*x])^2)) + (c + d*x)/(2*b^2*d*(a + b*ArcSin[c + d*x])) - (Cos[a/b]*CosIntegral[(a + b*ArcSin[c + d*x])/b])/(2*b^3*d) - (Sin[a/b]*SinIntegral[(a + b*ArcSin[c + d*x])/b])/(2*b^3*d)}
{1/(a + b*ArcSin[c + d*x])^3/(e*c + e*d*x)^1, x, 0, Defer[Int][1/((c*e + d*e*x)*(a + b*ArcSin[c + d*x])^3), x]}


{1/(a + b*ArcSin[c + d*x])^4*(e*c + e*d*x)^4, x, 20, -((e^4*(c + d*x)^4*Sqrt[1 - (c + d*x)^2])/(3*b*d*(a + b*ArcSin[c + d*x])^3)) - (2*e^4*(c + d*x)^3)/(3*b^2*d*(a + b*ArcSin[c + d*x])^2) + (5*e^4*(c + d*x)^5)/(6*b^2*d*(a + b*ArcSin[c + d*x])^2) - (2*e^4*(c + d*x)^2*Sqrt[1 - (c + d*x)^2])/(b^3*d*(a + b*ArcSin[c + d*x])) + (25*e^4*(c + d*x)^4*Sqrt[1 - (c + d*x)^2])/(6*b^3*d*(a + b*ArcSin[c + d*x])) - (e^4*CosIntegral[(a + b*ArcSin[c + d*x])/b]*Sin[a/b])/(48*b^4*d) + (27*e^4*CosIntegral[(3*(a + b*ArcSin[c + d*x]))/b]*Sin[(3*a)/b])/(32*b^4*d) - (125*e^4*CosIntegral[(5*(a + b*ArcSin[c + d*x]))/b]*Sin[(5*a)/b])/(96*b^4*d) + (e^4*Cos[a/b]*SinIntegral[(a + b*ArcSin[c + d*x])/b])/(48*b^4*d) - (27*e^4*Cos[(3*a)/b]*SinIntegral[(3*(a + b*ArcSin[c + d*x]))/b])/(32*b^4*d) + (125*e^4*Cos[(5*a)/b]*SinIntegral[(5*(a + b*ArcSin[c + d*x]))/b])/(96*b^4*d)}
{1/(a + b*ArcSin[c + d*x])^4*(e*c + e*d*x)^3, x, 13, -((e^3*(c + d*x)^3*Sqrt[1 - (c + d*x)^2])/(3*b*d*(a + b*ArcSin[c + d*x])^3)) - (e^3*(c + d*x)^2)/(2*b^2*d*(a + b*ArcSin[c + d*x])^2) + (2*e^3*(c + d*x)^4)/(3*b^2*d*(a + b*ArcSin[c + d*x])^2) - (e^3*(c + d*x)*Sqrt[1 - (c + d*x)^2])/(b^3*d*(a + b*ArcSin[c + d*x])) + (8*e^3*(c + d*x)^3*Sqrt[1 - (c + d*x)^2])/(3*b^3*d*(a + b*ArcSin[c + d*x])) - (e^3*Cos[(2*a)/b]*CosIntegral[(2*(a + b*ArcSin[c + d*x]))/b])/(3*b^4*d) + (4*e^3*Cos[(4*a)/b]*CosIntegral[(4*(a + b*ArcSin[c + d*x]))/b])/(3*b^4*d) - (e^3*Sin[(2*a)/b]*SinIntegral[(2*(a + b*ArcSin[c + d*x]))/b])/(3*b^4*d) + (4*e^3*Sin[(4*a)/b]*SinIntegral[(4*(a + b*ArcSin[c + d*x]))/b])/(3*b^4*d)}
{1/(a + b*ArcSin[c + d*x])^4*(e*c + e*d*x)^2, x, 15, -((e^2*(c + d*x)^2*Sqrt[1 - (c + d*x)^2])/(3*b*d*(a + b*ArcSin[c + d*x])^3)) - (e^2*(c + d*x))/(3*b^2*d*(a + b*ArcSin[c + d*x])^2) + (e^2*(c + d*x)^3)/(2*b^2*d*(a + b*ArcSin[c + d*x])^2) - (e^2*Sqrt[1 - (c + d*x)^2])/(3*b^3*d*(a + b*ArcSin[c + d*x])) + (3*e^2*(c + d*x)^2*Sqrt[1 - (c + d*x)^2])/(2*b^3*d*(a + b*ArcSin[c + d*x])) - (e^2*CosIntegral[(a + b*ArcSin[c + d*x])/b]*Sin[a/b])/(24*b^4*d) + (9*e^2*CosIntegral[(3*(a + b*ArcSin[c + d*x]))/b]*Sin[(3*a)/b])/(8*b^4*d) + (e^2*Cos[a/b]*SinIntegral[(a + b*ArcSin[c + d*x])/b])/(24*b^4*d) - (9*e^2*Cos[(3*a)/b]*SinIntegral[(3*(a + b*ArcSin[c + d*x]))/b])/(8*b^4*d)}
{1/(a + b*ArcSin[c + d*x])^4*(e*c + e*d*x)^1, x, 6, -((e*(c + d*x)*Sqrt[1 - (c + d*x)^2])/(3*b*d*(a + b*ArcSin[c + d*x])^3)) - e/(6*b^2*d*(a + b*ArcSin[c + d*x])^2) + (e*(c + d*x)^2)/(3*b^2*d*(a + b*ArcSin[c + d*x])^2) + (2*e*(c + d*x)*Sqrt[1 - (c + d*x)^2])/(3*b^3*d*(a + b*ArcSin[c + d*x])) - (2*e*Cos[(2*a)/b]*CosIntegral[(2*(a + b*ArcSin[c + d*x]))/b])/(3*b^4*d) - (2*e*Sin[(2*a)/b]*SinIntegral[(2*(a + b*ArcSin[c + d*x]))/b])/(3*b^4*d)}
{1/(a + b*ArcSin[c + d*x])^4*(e*c + e*d*x)^0, x, 7, -(Sqrt[1 - (c + d*x)^2]/(3*b*d*(a + b*ArcSin[c + d*x])^3)) + (c + d*x)/(6*b^2*d*(a + b*ArcSin[c + d*x])^2) + Sqrt[1 - (c + d*x)^2]/(6*b^3*d*(a + b*ArcSin[c + d*x])) - (CosIntegral[(a + b*ArcSin[c + d*x])/b]*Sin[a/b])/(6*b^4*d) + (Cos[a/b]*SinIntegral[(a + b*ArcSin[c + d*x])/b])/(6*b^4*d)}
{1/(a + b*ArcSin[c + d*x])^4/(e*c + e*d*x)^1, x, 0, Defer[Int][1/((c*e + d*e*x)*(a + b*ArcSin[c + d*x])^4), x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c e+d e x)^m (a+b ArcSin[c+d x])^(n/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{(c*e + d*e*x)^4*Sqrt[a + b*ArcSin[c + d*x]], x, 14, (e^4*(c + d*x)^5*Sqrt[a + b*ArcSin[c + d*x]])/(5*d) - (Sqrt[b]*e^4*Sqrt[Pi/2]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(8*d) + (Sqrt[b]*e^4*Sqrt[Pi/6]*Cos[(3*a)/b]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(16*d) - (Sqrt[b]*e^4*Sqrt[Pi/10]*Cos[(5*a)/b]*FresnelS[(Sqrt[10/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(80*d) + (Sqrt[b]*e^4*Sqrt[Pi/2]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(8*d) - (Sqrt[b]*e^4*Sqrt[Pi/6]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(3*a)/b])/(16*d) + (Sqrt[b]*e^4*Sqrt[Pi/10]*FresnelC[(Sqrt[10/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(5*a)/b])/(80*d)}
{(c*e + d*e*x)^3*Sqrt[a + b*ArcSin[c + d*x]], x, 11, (-3*e^3*Sqrt[a + b*ArcSin[c + d*x]])/(32*d) + (e^3*(c + d*x)^4*Sqrt[a + b*ArcSin[c + d*x]])/(4*d) - (Sqrt[b]*e^3*Sqrt[Pi/2]*Cos[(4*a)/b]*FresnelC[(2*Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(64*d) + (Sqrt[b]*e^3*Sqrt[Pi]*Cos[(2*a)/b]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(16*d) + (Sqrt[b]*e^3*Sqrt[Pi]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(16*d) - (Sqrt[b]*e^3*Sqrt[Pi/2]*FresnelS[(2*Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(4*a)/b])/(64*d)}
{(c*e + d*e*x)^2*Sqrt[a + b*ArcSin[c + d*x]], x, 11, (e^2*(c + d*x)^3*Sqrt[a + b*ArcSin[c + d*x]])/(3*d) - (Sqrt[b]*e^2*Sqrt[Pi/2]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(4*d) + (Sqrt[b]*e^2*Sqrt[Pi/6]*Cos[(3*a)/b]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(12*d) + (Sqrt[b]*e^2*Sqrt[Pi/2]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(4*d) - (Sqrt[b]*e^2*Sqrt[Pi/6]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(3*a)/b])/(12*d)}
{(c*e + d*e*x)^1*Sqrt[a + b*ArcSin[c + d*x]], x, 8, -(e*Sqrt[a + b*ArcSin[c + d*x]])/(4*d) + (e*(c + d*x)^2*Sqrt[a + b*ArcSin[c + d*x]])/(2*d) + (Sqrt[b]*e*Sqrt[Pi]*Cos[(2*a)/b]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(8*d) + (Sqrt[b]*e*Sqrt[Pi]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(8*d)}
{(c*e + d*e*x)^0*Sqrt[a + b*ArcSin[c + d*x]], x, 6, ((c + d*x)*Sqrt[a + b*ArcSin[c + d*x]])/d - (Sqrt[b]*Sqrt[Pi/2]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/d + (Sqrt[b]*Sqrt[Pi/2]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/d}
{Sqrt[a + b*ArcSin[c + d*x]]/(c*e + d*e*x)^1, x, 0, Defer[Int][Sqrt[a + b*ArcSin[c + d*x]]/(c*e + d*e*x), x]}


{(c*e + d*e*x)^3*(a + b*ArcSin[c + d*x])^(3/2), x, 20, (9*b*e^3*(c + d*x)*Sqrt[1 - (c + d*x)^2]*Sqrt[a + b*ArcSin[c + d*x]])/(64*d) + (3*b*e^3*(c + d*x)^3*Sqrt[1 - (c + d*x)^2]*Sqrt[a + b*ArcSin[c + d*x]])/(32*d) - (3*e^3*(a + b*ArcSin[c + d*x])^(3/2))/(32*d) + (e^3*(c + d*x)^4*(a + b*ArcSin[c + d*x])^(3/2))/(4*d) + (3*b^(3/2)*e^3*Sqrt[Pi/2]*Cos[(4*a)/b]*FresnelS[(2*Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(512*d) - (3*b^(3/2)*e^3*Sqrt[Pi]*Cos[(2*a)/b]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(64*d) + (3*b^(3/2)*e^3*Sqrt[Pi]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(64*d) - (3*b^(3/2)*e^3*Sqrt[Pi/2]*FresnelC[(2*Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(4*a)/b])/(512*d)}
{(c*e + d*e*x)^2*(a + b*ArcSin[c + d*x])^(3/2), x, 19, (b*e^2*Sqrt[1 - (c + d*x)^2]*Sqrt[a + b*ArcSin[c + d*x]])/(3*d) + (b*e^2*(c + d*x)^2*Sqrt[1 - (c + d*x)^2]*Sqrt[a + b*ArcSin[c + d*x]])/(6*d) + (e^2*(c + d*x)^3*(a + b*ArcSin[c + d*x])^(3/2))/(3*d) - (3*b^(3/2)*e^2*Sqrt[Pi/2]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(8*d) + (b^(3/2)*e^2*Sqrt[Pi/6]*Cos[(3*a)/b]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(24*d) - (3*b^(3/2)*e^2*Sqrt[Pi/2]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(8*d) + (b^(3/2)*e^2*Sqrt[Pi/6]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(3*a)/b])/(24*d)}
{(c*e + d*e*x)^1*(a + b*ArcSin[c + d*x])^(3/2), x, 9, (3*b*e*(c + d*x)*Sqrt[1 - (c + d*x)^2]*Sqrt[a + b*ArcSin[c + d*x]])/(8*d) - (e*(a + b*ArcSin[c + d*x])^(3/2))/(4*d) + (e*(c + d*x)^2*(a + b*ArcSin[c + d*x])^(3/2))/(2*d) - (3*b^(3/2)*e*Sqrt[Pi]*Cos[(2*a)/b]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(32*d) + (3*b^(3/2)*e*Sqrt[Pi]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(32*d)}
{(c*e + d*e*x)^0*(a + b*ArcSin[c + d*x])^(3/2), x, 7, (3*b*Sqrt[1 - (c + d*x)^2]*Sqrt[a + b*ArcSin[c + d*x]])/(2*d) + ((c + d*x)*(a + b*ArcSin[c + d*x])^(3/2))/d - (3*b^(3/2)*Sqrt[Pi/2]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(2*d) - (3*b^(3/2)*Sqrt[Pi/2]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(2*d)}
{(a + b*ArcSin[c + d*x])^(3/2)/(c*e + d*e*x)^1, x, 0, Defer[Int][(a + b*ArcSin[c + d*x])^(3/2)/(c*e + d*e*x), x]}


{(c*e + d*e*x)^3*(a + b*ArcSin[c + d*x])^(5/2), x, 23, (225*b^2*e^3*Sqrt[a + b*ArcSin[c + d*x]])/(2048*d) - (45*b^2*e^3*(c + d*x)^2*Sqrt[a + b*ArcSin[c + d*x]])/(256*d) - (15*b^2*e^3*(c + d*x)^4*Sqrt[a + b*ArcSin[c + d*x]])/(256*d) + (15*b*e^3*(c + d*x)*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^(3/2))/(64*d) + (5*b*e^3*(c + d*x)^3*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^(3/2))/(32*d) - (3*e^3*(a + b*ArcSin[c + d*x])^(5/2))/(32*d) + (e^3*(c + d*x)^4*(a + b*ArcSin[c + d*x])^(5/2))/(4*d) + (15*b^(5/2)*e^3*Sqrt[Pi/2]*Cos[(4*a)/b]*FresnelC[(2*Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(4096*d) - (15*b^(5/2)*e^3*Sqrt[Pi]*Cos[(2*a)/b]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(256*d) - (15*b^(5/2)*e^3*Sqrt[Pi]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(256*d) + (15*b^(5/2)*e^3*Sqrt[Pi/2]*FresnelS[(2*Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(4*a)/b])/(4096*d)}
{(c*e + d*e*x)^2*(a + b*ArcSin[c + d*x])^(5/2), x, 20, (-5*b^2*e^2*(c + d*x)*Sqrt[a + b*ArcSin[c + d*x]])/(6*d) - (5*b^2*e^2*(c + d*x)^3*Sqrt[a + b*ArcSin[c + d*x]])/(36*d) + (5*b*e^2*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^(3/2))/(9*d) + (5*b*e^2*(c + d*x)^2*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^(3/2))/(18*d) + (e^2*(c + d*x)^3*(a + b*ArcSin[c + d*x])^(5/2))/(3*d) + (15*b^(5/2)*e^2*Sqrt[Pi/2]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(16*d) - (5*b^(5/2)*e^2*Sqrt[Pi/6]*Cos[(3*a)/b]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(144*d) - (15*b^(5/2)*e^2*Sqrt[Pi/2]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(16*d) + (5*b^(5/2)*e^2*Sqrt[Pi/6]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(3*a)/b])/(144*d)}
{(c*e + d*e*x)^1*(a + b*ArcSin[c + d*x])^(5/2), x, 11, (15*b^2*e*Sqrt[a + b*ArcSin[c + d*x]])/(64*d) - (15*b^2*e*(c + d*x)^2*Sqrt[a + b*ArcSin[c + d*x]])/(32*d) + (5*b*e*(c + d*x)*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^(3/2))/(8*d) - (e*(a + b*ArcSin[c + d*x])^(5/2))/(4*d) + (e*(c + d*x)^2*(a + b*ArcSin[c + d*x])^(5/2))/(2*d) - (15*b^(5/2)*e*Sqrt[Pi]*Cos[(2*a)/b]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(128*d) - (15*b^(5/2)*e*Sqrt[Pi]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(128*d)}
{(c*e + d*e*x)^0*(a + b*ArcSin[c + d*x])^(5/2), x, 7, (-15*b^2*(c + d*x)*Sqrt[a + b*ArcSin[c + d*x]])/(4*d) + (5*b*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^(3/2))/(2*d) + ((c + d*x)*(a + b*ArcSin[c + d*x])^(5/2))/d + (15*b^(5/2)*Sqrt[Pi/2]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(4*d) - (15*b^(5/2)*Sqrt[Pi/2]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(4*d)}
{(a + b*ArcSin[c + d*x])^(5/2)/(c*e + d*e*x)^1, x, 0, Defer[Int][(a + b*ArcSin[c + d*x])^(5/2)/(c*e + d*e*x), x]}


{(c*e + d*e*x)^3*(a + b*ArcSin[c + d*x])^(7/2), x, 33, (-1575*b^3*e^3*(c + d*x)*Sqrt[1 - (c + d*x)^2]*Sqrt[a + b*ArcSin[c + d*x]])/(4096*d) - (105*b^3*e^3*(c + d*x)^3*Sqrt[1 - (c + d*x)^2]*Sqrt[a + b*ArcSin[c + d*x]])/(2048*d) + (525*b^2*e^3*(a + b*ArcSin[c + d*x])^(3/2))/(2048*d) - (105*b^2*e^3*(c + d*x)^2*(a + b*ArcSin[c + d*x])^(3/2))/(256*d) - (35*b^2*e^3*(c + d*x)^4*(a + b*ArcSin[c + d*x])^(3/2))/(256*d) + (21*b*e^3*(c + d*x)*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^(5/2))/(64*d) + (7*b*e^3*(c + d*x)^3*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^(5/2))/(32*d) - (3*e^3*(a + b*ArcSin[c + d*x])^(7/2))/(32*d) + (e^3*(c + d*x)^4*(a + b*ArcSin[c + d*x])^(7/2))/(4*d) - (105*b^(7/2)*e^3*Sqrt[Pi/2]*Cos[(4*a)/b]*FresnelS[(2*Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(32768*d) + (105*b^(7/2)*e^3*Sqrt[Pi]*Cos[(2*a)/b]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(1024*d) - (105*b^(7/2)*e^3*Sqrt[Pi]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(1024*d) + (105*b^(7/2)*e^3*Sqrt[Pi/2]*FresnelC[(2*Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(4*a)/b])/(32768*d)}
{(c*e + d*e*x)^2*(a + b*ArcSin[c + d*x])^(7/2), x, 29, (-175*b^3*e^2*Sqrt[1 - (c + d*x)^2]*Sqrt[a + b*ArcSin[c + d*x]])/(54*d) - (35*b^3*e^2*(c + d*x)^2*Sqrt[1 - (c + d*x)^2]*Sqrt[a + b*ArcSin[c + d*x]])/(216*d) - (35*b^2*e^2*(c + d*x)*(a + b*ArcSin[c + d*x])^(3/2))/(18*d) - (35*b^2*e^2*(c + d*x)^3*(a + b*ArcSin[c + d*x])^(3/2))/(108*d) + (7*b*e^2*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^(5/2))/(9*d) + (7*b*e^2*(c + d*x)^2*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^(5/2))/(18*d) + (e^2*(c + d*x)^3*(a + b*ArcSin[c + d*x])^(7/2))/(3*d) + (105*b^(7/2)*e^2*Sqrt[Pi/2]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(32*d) - (35*b^(7/2)*e^2*Sqrt[Pi/6]*Cos[(3*a)/b]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(864*d) + (105*b^(7/2)*e^2*Sqrt[Pi/2]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(32*d) - (35*b^(7/2)*e^2*Sqrt[Pi/6]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(3*a)/b])/(864*d)}
{(c*e + d*e*x)^1*(a + b*ArcSin[c + d*x])^(7/2), x, 12, (-105*b^3*e*(c + d*x)*Sqrt[1 - (c + d*x)^2]*Sqrt[a + b*ArcSin[c + d*x]])/(128*d) + (35*b^2*e*(a + b*ArcSin[c + d*x])^(3/2))/(64*d) - (35*b^2*e*(c + d*x)^2*(a + b*ArcSin[c + d*x])^(3/2))/(32*d) + (7*b*e*(c + d*x)*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^(5/2))/(8*d) - (e*(a + b*ArcSin[c + d*x])^(7/2))/(4*d) + (e*(c + d*x)^2*(a + b*ArcSin[c + d*x])^(7/2))/(2*d) + (105*b^(7/2)*e*Sqrt[Pi]*Cos[(2*a)/b]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(512*d) - (105*b^(7/2)*e*Sqrt[Pi]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(512*d)}
{(c*e + d*e*x)^0*(a + b*ArcSin[c + d*x])^(7/2), x, 8, (-105*b^3*Sqrt[1 - (c + d*x)^2]*Sqrt[a + b*ArcSin[c + d*x]])/(8*d) - (35*b^2*(c + d*x)*(a + b*ArcSin[c + d*x])^(3/2))/(4*d) + (7*b*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^(5/2))/(2*d) + ((c + d*x)*(a + b*ArcSin[c + d*x])^(7/2))/d + (105*b^(7/2)*Sqrt[Pi/2]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(8*d) + (105*b^(7/2)*Sqrt[Pi/2]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(8*d)}
{(a + b*ArcSin[c + d*x])^(7/2)/(c*e + d*e*x)^1, x, 0, Defer[Int][(a + b*ArcSin[c + d*x])^(7/2)/(c*e + d*e*x), x]}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(c*e + d*e*x)^4/Sqrt[a + b*ArcSin[c + d*x]], x, 13, (e^4*Sqrt[Pi/2]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(4*Sqrt[b]*d) - (e^4*Sqrt[(3*Pi)/2]*Cos[(3*a)/b]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(8*Sqrt[b]*d) + (e^4*Sqrt[Pi/10]*Cos[(5*a)/b]*FresnelC[(Sqrt[10/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(8*Sqrt[b]*d) + (e^4*Sqrt[Pi/2]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(4*Sqrt[b]*d) - (e^4*Sqrt[(3*Pi)/2]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(3*a)/b])/(8*Sqrt[b]*d) + (e^4*Sqrt[Pi/10]*FresnelS[(Sqrt[10/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(5*a)/b])/(8*Sqrt[b]*d)}
{(c*e + d*e*x)^3/Sqrt[a + b*ArcSin[c + d*x]], x, 10, -(e^3*Sqrt[Pi/2]*Cos[(4*a)/b]*FresnelS[(2*Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(8*Sqrt[b]*d) + (e^3*Sqrt[Pi]*Cos[(2*a)/b]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(4*Sqrt[b]*d) - (e^3*Sqrt[Pi]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(4*Sqrt[b]*d) + (e^3*Sqrt[Pi/2]*FresnelC[(2*Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(4*a)/b])/(8*Sqrt[b]*d)}
{(c*e + d*e*x)^2/Sqrt[a + b*ArcSin[c + d*x]], x, 10, (e^2*Sqrt[Pi/2]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(2*Sqrt[b]*d) - (e^2*Sqrt[Pi/6]*Cos[(3*a)/b]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(2*Sqrt[b]*d) + (e^2*Sqrt[Pi/2]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(2*Sqrt[b]*d) - (e^2*Sqrt[Pi/6]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(3*a)/b])/(2*Sqrt[b]*d)}
{(c*e + d*e*x)^1/Sqrt[a + b*ArcSin[c + d*x]], x, 6, (e*Sqrt[Pi]*Cos[(2*a)/b]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(2*Sqrt[b]*d) - (e*Sqrt[Pi]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(2*Sqrt[b]*d)}
{(c*e + d*e*x)^0/Sqrt[a + b*ArcSin[c + d*x]], x, 6, (Sqrt[2*Pi]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(Sqrt[b]*d) + (Sqrt[2*Pi]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(Sqrt[b]*d)}
{1/((c*e + d*e*x)^1*Sqrt[a + b*ArcSin[c + d*x]]), x, 0, Defer[Int][1/((c*e + d*e*x)*Sqrt[a + b*ArcSin[c + d*x]]), x]}


{(c*e + d*e*x)^4/(a + b*ArcSin[c + d*x])^(3/2), x, 12, (-2*e^4*(c + d*x)^4*Sqrt[1 - (c + d*x)^2])/(b*d*Sqrt[a + b*ArcSin[c + d*x]]) - (e^4*Sqrt[Pi/2]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(2*b^(3/2)*d) + (3*e^4*Sqrt[(3*Pi)/2]*Cos[(3*a)/b]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(4*b^(3/2)*d) - (e^4*Sqrt[(5*Pi)/2]*Cos[(5*a)/b]*FresnelS[(Sqrt[10/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(4*b^(3/2)*d) + (e^4*Sqrt[Pi/2]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(2*b^(3/2)*d) - (3*e^4*Sqrt[(3*Pi)/2]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(3*a)/b])/(4*b^(3/2)*d) + (e^4*Sqrt[(5*Pi)/2]*FresnelC[(Sqrt[10/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(5*a)/b])/(4*b^(3/2)*d)}
{(c*e + d*e*x)^3/(a + b*ArcSin[c + d*x])^(3/2), x, 9, (-2*e^3*(c + d*x)^3*Sqrt[1 - (c + d*x)^2])/(b*d*Sqrt[a + b*ArcSin[c + d*x]]) - (e^3*Sqrt[Pi/2]*Cos[(4*a)/b]*FresnelC[(2*Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(b^(3/2)*d) + (e^3*Sqrt[Pi]*Cos[(2*a)/b]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(b^(3/2)*d) + (e^3*Sqrt[Pi]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(b^(3/2)*d) - (e^3*Sqrt[Pi/2]*FresnelS[(2*Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(4*a)/b])/(b^(3/2)*d)}
{(c*e + d*e*x)^2/(a + b*ArcSin[c + d*x])^(3/2), x, 9, (-2*e^2*(c + d*x)^2*Sqrt[1 - (c + d*x)^2])/(b*d*Sqrt[a + b*ArcSin[c + d*x]]) - (e^2*Sqrt[Pi/2]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(b^(3/2)*d) + (e^2*Sqrt[(3*Pi)/2]*Cos[(3*a)/b]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(b^(3/2)*d) + (e^2*Sqrt[Pi/2]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(b^(3/2)*d) - (e^2*Sqrt[(3*Pi)/2]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(3*a)/b])/(b^(3/2)*d)}
{(c*e + d*e*x)^1/(a + b*ArcSin[c + d*x])^(3/2), x, 4, (-2*e*(c + d*x)*Sqrt[1 - (c + d*x)^2])/(b*d*Sqrt[a + b*ArcSin[c + d*x]]) + (2*e*Sqrt[Pi]*Cos[(2*a)/b]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(b^(3/2)*d) + (2*e*Sqrt[Pi]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(b^(3/2)*d)}
{(c*e + d*e*x)^0/(a + b*ArcSin[c + d*x])^(3/2), x, 6, (-2*Sqrt[1 - (c + d*x)^2])/(b*d*Sqrt[a + b*ArcSin[c + d*x]]) - (2*Sqrt[2*Pi]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(b^(3/2)*d) + (2*Sqrt[2*Pi]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(b^(3/2)*d)}
{1/((c*e + d*e*x)^1*(a + b*ArcSin[c + d*x])^(3/2)), x, 0, Defer[Int][1/((c*e + d*e*x)*(a + b*ArcSin[c + d*x])^(3/2)), x]}


{(c*e + d*e*x)^4/(a + b*ArcSin[c + d*x])^(5/2), x, 24, (-2*e^4*(c + d*x)^4*Sqrt[1 - (c + d*x)^2])/(3*b*d*(a + b*ArcSin[c + d*x])^(3/2)) - (16*e^4*(c + d*x)^3)/(3*b^2*d*Sqrt[a + b*ArcSin[c + d*x]]) + (20*e^4*(c + d*x)^5)/(3*b^2*d*Sqrt[a + b*ArcSin[c + d*x]]) - (25*e^4*Sqrt[Pi/2]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(3*b^(5/2)*d) + (4*e^4*Sqrt[2*Pi]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(b^(5/2)*d) + (25*e^4*Sqrt[Pi/6]*Cos[(3*a)/b]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(2*b^(5/2)*d) - (4*e^4*Sqrt[(2*Pi)/3]*Cos[(3*a)/b]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(b^(5/2)*d) - (5*e^4*Sqrt[(5*Pi)/2]*Cos[(5*a)/b]*FresnelC[(Sqrt[10/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(6*b^(5/2)*d) - (25*e^4*Sqrt[Pi/2]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(3*b^(5/2)*d) + (4*e^4*Sqrt[2*Pi]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(b^(5/2)*d) + (25*e^4*Sqrt[Pi/6]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(3*a)/b])/(2*b^(5/2)*d) - (4*e^4*Sqrt[(2*Pi)/3]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(3*a)/b])/(b^(5/2)*d) - (5*e^4*Sqrt[(5*Pi)/2]*FresnelS[(Sqrt[10/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(5*a)/b])/(6*b^(5/2)*d)}
{(c*e + d*e*x)^3/(a + b*ArcSin[c + d*x])^(5/2), x, 17, (-2*e^3*(c + d*x)^3*Sqrt[1 - (c + d*x)^2])/(3*b*d*(a + b*ArcSin[c + d*x])^(3/2)) - (4*e^3*(c + d*x)^2)/(b^2*d*Sqrt[a + b*ArcSin[c + d*x]]) + (16*e^3*(c + d*x)^4)/(3*b^2*d*Sqrt[a + b*ArcSin[c + d*x]]) + (4*e^3*Sqrt[2*Pi]*Cos[(4*a)/b]*FresnelS[(2*Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(3*b^(5/2)*d) - (4*e^3*Sqrt[Pi]*Cos[(2*a)/b]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(3*b^(5/2)*d) + (4*e^3*Sqrt[Pi]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(3*b^(5/2)*d) - (4*e^3*Sqrt[2*Pi]*FresnelC[(2*Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(4*a)/b])/(3*b^(5/2)*d)}
{(c*e + d*e*x)^2/(a + b*ArcSin[c + d*x])^(5/2), x, 17, (-2*e^2*(c + d*x)^2*Sqrt[1 - (c + d*x)^2])/(3*b*d*(a + b*ArcSin[c + d*x])^(3/2)) - (8*e^2*(c + d*x))/(3*b^2*d*Sqrt[a + b*ArcSin[c + d*x]]) + (4*e^2*(c + d*x)^3)/(b^2*d*Sqrt[a + b*ArcSin[c + d*x]]) - (e^2*Sqrt[2*Pi]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(3*b^(5/2)*d) + (e^2*Sqrt[6*Pi]*Cos[(3*a)/b]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(b^(5/2)*d) - (e^2*Sqrt[2*Pi]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(3*b^(5/2)*d) + (e^2*Sqrt[6*Pi]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(3*a)/b])/(b^(5/2)*d)}
{(c*e + d*e*x)^1/(a + b*ArcSin[c + d*x])^(5/2), x, 8, (-2*e*(c + d*x)*Sqrt[1 - (c + d*x)^2])/(3*b*d*(a + b*ArcSin[c + d*x])^(3/2)) - (4*e)/(3*b^2*d*Sqrt[a + b*ArcSin[c + d*x]]) + (8*e*(c + d*x)^2)/(3*b^2*d*Sqrt[a + b*ArcSin[c + d*x]]) - (8*e*Sqrt[Pi]*Cos[(2*a)/b]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(3*b^(5/2)*d) + (8*e*Sqrt[Pi]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(3*b^(5/2)*d)}
{(c*e + d*e*x)^0/(a + b*ArcSin[c + d*x])^(5/2), x, 7, (-2*Sqrt[1 - (c + d*x)^2])/(3*b*d*(a + b*ArcSin[c + d*x])^(3/2)) + (4*(c + d*x))/(3*b^2*d*Sqrt[a + b*ArcSin[c + d*x]]) - (4*Sqrt[2*Pi]*Cos[a/b]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(3*b^(5/2)*d) - (4*Sqrt[2*Pi]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(3*b^(5/2)*d)}
{1/((c*e + d*e*x)^1*(a + b*ArcSin[c + d*x])^(5/2)), x, 0, Defer[Int][1/((c*e + d*e*x)*(a + b*ArcSin[c + d*x])^(5/2)), x]}


{(c*e + d*e*x)^4/(a + b*ArcSin[c + d*x])^(7/2), x, 22, (-2*e^4*(c + d*x)^4*Sqrt[1 - (c + d*x)^2])/(5*b*d*(a + b*ArcSin[c + d*x])^(5/2)) - (16*e^4*(c + d*x)^3)/(15*b^2*d*(a + b*ArcSin[c + d*x])^(3/2)) + (4*e^4*(c + d*x)^5)/(3*b^2*d*(a + b*ArcSin[c + d*x])^(3/2)) - (32*e^4*(c + d*x)^2*Sqrt[1 - (c + d*x)^2])/(5*b^3*d*Sqrt[a + b*ArcSin[c + d*x]]) + (40*e^4*(c + d*x)^4*Sqrt[1 - (c + d*x)^2])/(3*b^3*d*Sqrt[a + b*ArcSin[c + d*x]]) + (e^4*Sqrt[2*Pi]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(15*b^(7/2)*d) - (5*e^4*Sqrt[(3*Pi)/2]*Cos[(3*a)/b]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(b^(7/2)*d) + (8*e^4*Sqrt[6*Pi]*Cos[(3*a)/b]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(5*b^(7/2)*d) + (5*e^4*Sqrt[(5*Pi)/2]*Cos[(5*a)/b]*FresnelS[(Sqrt[10/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(3*b^(7/2)*d) - (e^4*Sqrt[2*Pi]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(15*b^(7/2)*d) + (5*e^4*Sqrt[(3*Pi)/2]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(3*a)/b])/(b^(7/2)*d) - (8*e^4*Sqrt[6*Pi]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(3*a)/b])/(5*b^(7/2)*d) - (5*e^4*Sqrt[(5*Pi)/2]*FresnelC[(Sqrt[10/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(5*a)/b])/(3*b^(7/2)*d)}
{(c*e + d*e*x)^3/(a + b*ArcSin[c + d*x])^(7/2), x, 14, (-2*e^3*(c + d*x)^3*Sqrt[1 - (c + d*x)^2])/(5*b*d*(a + b*ArcSin[c + d*x])^(5/2)) - (4*e^3*(c + d*x)^2)/(5*b^2*d*(a + b*ArcSin[c + d*x])^(3/2)) + (16*e^3*(c + d*x)^4)/(15*b^2*d*(a + b*ArcSin[c + d*x])^(3/2)) - (16*e^3*(c + d*x)*Sqrt[1 - (c + d*x)^2])/(5*b^3*d*Sqrt[a + b*ArcSin[c + d*x]]) + (128*e^3*(c + d*x)^3*Sqrt[1 - (c + d*x)^2])/(15*b^3*d*Sqrt[a + b*ArcSin[c + d*x]]) + (32*e^3*Sqrt[2*Pi]*Cos[(4*a)/b]*FresnelC[(2*Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(15*b^(7/2)*d) - (16*e^3*Sqrt[Pi]*Cos[(2*a)/b]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(15*b^(7/2)*d) - (16*e^3*Sqrt[Pi]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(15*b^(7/2)*d) + (32*e^3*Sqrt[2*Pi]*FresnelS[(2*Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(4*a)/b])/(15*b^(7/2)*d)}
{(c*e + d*e*x)^2/(a + b*ArcSin[c + d*x])^(7/2), x, 16, (-2*e^2*(c + d*x)^2*Sqrt[1 - (c + d*x)^2])/(5*b*d*(a + b*ArcSin[c + d*x])^(5/2)) - (8*e^2*(c + d*x))/(15*b^2*d*(a + b*ArcSin[c + d*x])^(3/2)) + (4*e^2*(c + d*x)^3)/(5*b^2*d*(a + b*ArcSin[c + d*x])^(3/2)) - (16*e^2*Sqrt[1 - (c + d*x)^2])/(15*b^3*d*Sqrt[a + b*ArcSin[c + d*x]]) + (24*e^2*(c + d*x)^2*Sqrt[1 - (c + d*x)^2])/(5*b^3*d*Sqrt[a + b*ArcSin[c + d*x]]) + (2*e^2*Sqrt[2*Pi]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(15*b^(7/2)*d) - (6*e^2*Sqrt[6*Pi]*Cos[(3*a)/b]*FresnelS[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(5*b^(7/2)*d) - (2*e^2*Sqrt[2*Pi]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(15*b^(7/2)*d) + (6*e^2*Sqrt[6*Pi]*FresnelC[(Sqrt[6/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[(3*a)/b])/(5*b^(7/2)*d)}
{(c*e + d*e*x)^1/(a + b*ArcSin[c + d*x])^(7/2), x, 6, (-2*e*(c + d*x)*Sqrt[1 - (c + d*x)^2])/(5*b*d*(a + b*ArcSin[c + d*x])^(5/2)) - (4*e)/(15*b^2*d*(a + b*ArcSin[c + d*x])^(3/2)) + (8*e*(c + d*x)^2)/(15*b^2*d*(a + b*ArcSin[c + d*x])^(3/2)) + (32*e*(c + d*x)*Sqrt[1 - (c + d*x)^2])/(15*b^3*d*Sqrt[a + b*ArcSin[c + d*x]]) - (32*e*Sqrt[Pi]*Cos[(2*a)/b]*FresnelC[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])])/(15*b^(7/2)*d) - (32*e*Sqrt[Pi]*FresnelS[(2*Sqrt[a + b*ArcSin[c + d*x]])/(Sqrt[b]*Sqrt[Pi])]*Sin[(2*a)/b])/(15*b^(7/2)*d)}
{(c*e + d*e*x)^0/(a + b*ArcSin[c + d*x])^(7/2), x, 7, (-2*Sqrt[1 - (c + d*x)^2])/(5*b*d*(a + b*ArcSin[c + d*x])^(5/2)) + (4*(c + d*x))/(15*b^2*d*(a + b*ArcSin[c + d*x])^(3/2)) + (8*Sqrt[1 - (c + d*x)^2])/(15*b^3*d*Sqrt[a + b*ArcSin[c + d*x]]) + (8*Sqrt[2*Pi]*Cos[a/b]*FresnelS[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]])/(15*b^(7/2)*d) - (8*Sqrt[2*Pi]*FresnelC[(Sqrt[2/Pi]*Sqrt[a + b*ArcSin[c + d*x]])/Sqrt[b]]*Sin[a/b])/(15*b^(7/2)*d)}
{1/((c*e + d*e*x)^1*(a + b*ArcSin[c + d*x])^(7/2)), x, 0, Defer[Int][1/((c*e + d*e*x)*(a + b*ArcSin[c + d*x])^(7/2)), x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c e+d e x)^(m/2) (a+b ArcSin[c+d x])^n*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{(c*e + d*e*x)^(7/2)*(a + b*ArcSin[c + d*x]), x, 6, (28*b*(c*e + d*e*x)^(9/2)*Sqrt[1 - (c + d*x)^2])/(405*d*e*(c + d*x)^3) + (4*b*(c*e + d*e*x)^(9/2)*Sqrt[1 - (c + d*x)^2])/(81*d*e*(c + d*x)) + (2*(c*e + d*e*x)^(9/2)*(a + b*ArcSin[c + d*x]))/(9*d*e) - (28*b*(c*e + d*e*x)^(9/2)*EllipticE[ArcSin[Sqrt[c + d*x]], -1])/(135*d*e*(c + d*x)^(9/2)) + (28*b*(c*e + d*e*x)^(9/2)*EllipticF[ArcSin[Sqrt[c + d*x]], -1])/(135*d*e*(c + d*x)^(9/2))}
{(c*e + d*e*x)^(5/2)*(a + b*ArcSin[c + d*x]), x, 6, (20*b*(c*e + d*e*x)^(7/2)*Sqrt[1 - (c + d*x)^2])/(147*d*e*(c + d*x)^3) + (4*b*(c*e + d*e*x)^(7/2)*Sqrt[1 - (c + d*x)^2])/(49*d*e*(c + d*x)) + (2*(c*e + d*e*x)^(7/2)*(a + b*ArcSin[c + d*x]))/(7*d*e) - (20*b*(c*e + d*e*x)^(7/2)*EllipticF[ArcSin[Sqrt[c + d*x]], -1])/(147*d*e*(c + d*x)^(7/2))}
{(c*e + d*e*x)^(3/2)*(a + b*ArcSin[c + d*x]), x, 5, (4*b*(c*e + d*e*x)^(5/2)*Sqrt[1 - (c + d*x)^2])/(25*d*e*(c + d*x)) + (2*(c*e + d*e*x)^(5/2)*(a + b*ArcSin[c + d*x]))/(5*d*e) - (12*b*(c*e + d*e*x)^(5/2)*EllipticE[ArcSin[Sqrt[c + d*x]], -1])/(25*d*e*(c + d*x)^(5/2)) + (12*b*(c*e + d*e*x)^(5/2)*EllipticF[ArcSin[Sqrt[c + d*x]], -1])/(25*d*e*(c + d*x)^(5/2))}
{(c*e + d*e*x)^(1/2)*(a + b*ArcSin[c + d*x]), x, 5, (4*b*(c*e + d*e*x)^(3/2)*Sqrt[1 - (c + d*x)^2])/(9*d*e*(c + d*x)) + (2*(c*e + d*e*x)^(3/2)*(a + b*ArcSin[c + d*x]))/(3*d*e) - (4*b*(c*e + d*e*x)^(3/2)*EllipticF[ArcSin[Sqrt[c + d*x]], -1])/(9*d*e*(c + d*x)^(3/2))}
{(a + b*ArcSin[c + d*x])/(c*e + d*e*x)^(1/2), x, 4, (2*Sqrt[c*e + d*e*x]*(a + b*ArcSin[c + d*x]))/(d*e) - (4*b*Sqrt[c*e + d*e*x]*EllipticE[ArcSin[Sqrt[c + d*x]], -1])/(d*e*Sqrt[c + d*x]) + (4*b*Sqrt[c*e + d*e*x]*EllipticF[ArcSin[Sqrt[c + d*x]], -1])/(d*e*Sqrt[c + d*x])}
{(a + b*ArcSin[c + d*x])/(c*e + d*e*x)^(3/2), x, 4, -((2*(a + b*ArcSin[c + d*x]))/(d*e*Sqrt[c*e + d*e*x])) + (4*b*Sqrt[c + d*x]*EllipticF[ArcSin[Sqrt[c + d*x]], -1])/(d*e*Sqrt[c*e + d*e*x])}
{(a + b*ArcSin[c + d*x])/(c*e + d*e*x)^(5/2), x, 5, -((4*b*(c + d*x)*Sqrt[1 - (c + d*x)^2])/(3*d*e*(c*e + d*e*x)^(3/2))) - (2*(a + b*ArcSin[c + d*x]))/(3*d*e*(c*e + d*e*x)^(3/2)) - (4*b*(c + d*x)^(3/2)*EllipticE[ArcSin[Sqrt[c + d*x]], -1])/(3*d*e*(c*e + d*e*x)^(3/2)) + (4*b*(c + d*x)^(3/2)*EllipticF[ArcSin[Sqrt[c + d*x]], -1])/(3*d*e*(c*e + d*e*x)^(3/2))}
{(a + b*ArcSin[c + d*x])/(c*e + d*e*x)^(7/2), x, 5, -((4*b*(c + d*x)*Sqrt[1 - (c + d*x)^2])/(15*d*e*(c*e + d*e*x)^(5/2))) - (2*(a + b*ArcSin[c + d*x]))/(5*d*e*(c*e + d*e*x)^(5/2)) + (4*b*(c + d*x)^(5/2)*EllipticF[ArcSin[Sqrt[c + d*x]], -1])/(15*d*e*(c*e + d*e*x)^(5/2))}


{(c*e + d*e*x)^(7/2)*(a + b*ArcSin[c + d*x])^2, x, 6, (-112*b^2*e*(c*e + d*e*x)^(5/2))/(2025*d) - (16*b^2*(c*e + d*e*x)^(9/2))/(729*d*e) + (56*b*e^2*(c*e + d*e*x)^(3/2)*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x]))/(405*d) + (8*b*(c*e + d*e*x)^(7/2)*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x]))/(81*d) + (2*(c*e + d*e*x)^(9/2)*(a + b*ArcSin[c + d*x])^2)/(9*d*e) - (56*b*e^3*(c + d*x)*Sqrt[c*e + d*e*x]*(a + b*ArcSin[c + d*x])*Hypergeometric2F1[1/2, 3/4, 7/4, (c + d*x)^2])/(405*d) + (112*b^2*e^3*(c + d*x)^2*Sqrt[c*e + d*e*x]*HypergeometricPFQ[{1, 5/4, 5/4}, {7/4, 9/4}, (c + d*x)^2])/(2025*d)}
{(c*e + d*e*x)^(5/2)*(a + b*ArcSin[c + d*x])^2, x, 6, (-80*b^2*e*(c*e + d*e*x)^(3/2))/(441*d) - (16*b^2*(c*e + d*e*x)^(7/2))/(343*d*e) + (40*b*e^2*Sqrt[c*e + d*e*x]*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x]))/(147*d) + (8*b*(c*e + d*e*x)^(5/2)*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x]))/(49*d) + (2*(c*e + d*e*x)^(7/2)*(a + b*ArcSin[c + d*x])^2)/(7*d*e) - (40*b*e^3*(c + d*x)*(a + b*ArcSin[c + d*x])*Hypergeometric2F1[1/4, 1/2, 5/4, (c + d*x)^2])/(147*d*Sqrt[c*e + d*e*x]) + (80*b^2*e^3*(c + d*x)^2*HypergeometricPFQ[{3/4, 3/4, 1}, {5/4, 7/4}, (c + d*x)^2])/(441*d*Sqrt[c*e + d*e*x])}
{(c*e + d*e*x)^(3/2)*(a + b*ArcSin[c + d*x])^2, x, 4, (-16*b^2*(c*e + d*e*x)^(5/2))/(125*d*e) + (8*b*(c*e + d*e*x)^(3/2)*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x]))/(25*d) + (2*(c*e + d*e*x)^(5/2)*(a + b*ArcSin[c + d*x])^2)/(5*d*e) - (8*b*e*(c + d*x)*Sqrt[c*e + d*e*x]*(a + b*ArcSin[c + d*x])*Hypergeometric2F1[1/2, 3/4, 7/4, (c + d*x)^2])/(25*d) + (16*b^2*e*(c + d*x)^2*Sqrt[c*e + d*e*x]*HypergeometricPFQ[{1, 5/4, 5/4}, {7/4, 9/4}, (c + d*x)^2])/(125*d)}
{(c*e + d*e*x)^(1/2)*(a + b*ArcSin[c + d*x])^2, x, 4, (-16*b^2*(c*e + d*e*x)^(3/2))/(27*d*e) + (8*b*Sqrt[c*e + d*e*x]*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x]))/(9*d) + (2*(c*e + d*e*x)^(3/2)*(a + b*ArcSin[c + d*x])^2)/(3*d*e) - (8*b*e*(c + d*x)*(a + b*ArcSin[c + d*x])*Hypergeometric2F1[1/4, 1/2, 5/4, (c + d*x)^2])/(9*d*Sqrt[c*e + d*e*x]) + (16*b^2*e*(c + d*x)^2*HypergeometricPFQ[{3/4, 3/4, 1}, {5/4, 7/4}, (c + d*x)^2])/(27*d*Sqrt[c*e + d*e*x])}
{(a + b*ArcSin[c + d*x])^2/(c*e + d*e*x)^(1/2), x, 2, (2*Sqrt[c*e + d*e*x]*(a + b*ArcSin[c + d*x])^2)/(d*e) - (8*b*(c + d*x)*Sqrt[c*e + d*e*x]*(a + b*ArcSin[c + d*x])*Hypergeometric2F1[1/2, 3/4, 7/4, (c + d*x)^2])/(3*d*e) + (16*b^2*(c + d*x)^2*Sqrt[c*e + d*e*x]*HypergeometricPFQ[{1, 5/4, 5/4}, {7/4, 9/4}, (c + d*x)^2])/(15*d*e)}
{(a + b*ArcSin[c + d*x])^2/(c*e + d*e*x)^(3/2), x, 2, (-2*(a + b*ArcSin[c + d*x])^2)/(d*e*Sqrt[c*e + d*e*x]) + (8*b*(c + d*x)*(a + b*ArcSin[c + d*x])*Hypergeometric2F1[1/4, 1/2, 5/4, (c + d*x)^2])/(d*e*Sqrt[c*e + d*e*x]) - (16*b^2*(c + d*x)^2*HypergeometricPFQ[{3/4, 3/4, 1}, {5/4, 7/4}, (c + d*x)^2])/(3*d*e*Sqrt[c*e + d*e*x])}
{(a + b*ArcSin[c + d*x])^2/(c*e + d*e*x)^(5/2), x, 4, (16*b^2*Sqrt[c*e + d*e*x])/(3*d*e^3) - (8*b*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x]))/(3*d*e^2*Sqrt[c*e + d*e*x]) - (2*(a + b*ArcSin[c + d*x])^2)/(3*d*e*(c*e + d*e*x)^(3/2)) - (8*b*(c + d*x)*Sqrt[c*e + d*e*x]*(a + b*ArcSin[c + d*x])*Hypergeometric2F1[1/2, 3/4, 7/4, (c + d*x)^2])/(9*d*e^3) + (16*b^2*(c + d*x)^2*Sqrt[c*e + d*e*x]*HypergeometricPFQ[{1, 5/4, 5/4}, {7/4, 9/4}, (c + d*x)^2])/(45*d*e^3)}
{(a + b*ArcSin[c + d*x])^2/(c*e + d*e*x)^(7/2), x, 4, (-16*b^2)/(15*d*e^3*Sqrt[c*e + d*e*x]) - (8*b*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x]))/(15*d*e^2*(c*e + d*e*x)^(3/2)) - (2*(a + b*ArcSin[c + d*x])^2)/(5*d*e*(c*e + d*e*x)^(5/2)) + (8*b*(c + d*x)*(a + b*ArcSin[c + d*x])*Hypergeometric2F1[1/4, 1/2, 5/4, (c + d*x)^2])/(15*d*e^3*Sqrt[c*e + d*e*x]) - (16*b^2*(c + d*x)^2*HypergeometricPFQ[{3/4, 3/4, 1}, {5/4, 7/4}, (c + d*x)^2])/(45*d*e^3*Sqrt[c*e + d*e*x])}


{(c*e + d*e*x)^(7/2)*(a + b*ArcSin[c + d*x])^3, x, 14, -((224*b^3*e*(c*e + d*e*x)^(5/2)*Sqrt[1 - (c + d*x)^2])/(3375*d*(c + d*x))) - (224*b^3*(c*e + d*e*x)^(9/2)*Sqrt[1 - (c + d*x)^2])/(10935*d*e*(c + d*x)^3) - (32*b^3*(c*e + d*e*x)^(9/2)*Sqrt[1 - (c + d*x)^2])/(2187*d*e*(c + d*x)) - (112*b^2*e*(c*e + d*e*x)^(5/2)*(a + b*ArcSin[c + d*x]))/(675*d) - (16*b^2*(c*e + d*e*x)^(9/2)*(a + b*ArcSin[c + d*x]))/(243*d*e) + (28*b*e^2*(c*e + d*e*x)^(3/2)*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^2)/(135*d) + (4*b*(c*e + d*e*x)^(7/2)*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^2)/(27*d) + (2*(c*e + d*e*x)^(9/2)*(a + b*ArcSin[c + d*x])^3)/(9*d*e) + (224*b^3*e*(c*e + d*e*x)^(5/2)*EllipticE[ArcSin[Sqrt[c + d*x]], -1])/(1125*d*(c + d*x)^(5/2)) + (224*b^3*(c*e + d*e*x)^(9/2)*EllipticE[ArcSin[Sqrt[c + d*x]], -1])/(3645*d*e*(c + d*x)^(9/2)) - (224*b^3*e*(c*e + d*e*x)^(5/2)*EllipticF[ArcSin[Sqrt[c + d*x]], -1])/(1125*d*(c + d*x)^(5/2)) - (224*b^3*(c*e + d*e*x)^(9/2)*EllipticF[ArcSin[Sqrt[c + d*x]], -1])/(3645*d*e*(c + d*x)^(9/2)) - (14/45)*b*e^3*Int[(Sqrt[c*e + d*e*x]*(a + b*ArcSin[c + d*x])^2)/Sqrt[1 - (c + d*x)^2], x]}
{(c*e + d*e*x)^(5/2)*(a + b*ArcSin[c + d*x])^3, x, 14, -((160*b^3*e*(c*e + d*e*x)^(3/2)*Sqrt[1 - (c + d*x)^2])/(441*d*(c + d*x))) - (160*b^3*(c*e + d*e*x)^(7/2)*Sqrt[1 - (c + d*x)^2])/(2401*d*e*(c + d*x)^3) - (96*b^3*(c*e + d*e*x)^(7/2)*Sqrt[1 - (c + d*x)^2])/(2401*d*e*(c + d*x)) - (80*b^2*e*(c*e + d*e*x)^(3/2)*(a + b*ArcSin[c + d*x]))/(147*d) - (48*b^2*(c*e + d*e*x)^(7/2)*(a + b*ArcSin[c + d*x]))/(343*d*e) + (20*b*e^2*Sqrt[c*e + d*e*x]*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^2)/(49*d) + (12*b*(c*e + d*e*x)^(5/2)*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^2)/(49*d) + (2*(c*e + d*e*x)^(7/2)*(a + b*ArcSin[c + d*x])^3)/(7*d*e) + (160*b^3*e*(c*e + d*e*x)^(3/2)*EllipticF[ArcSin[Sqrt[c + d*x]], -1])/(441*d*(c + d*x)^(3/2)) + (160*b^3*(c*e + d*e*x)^(7/2)*EllipticF[ArcSin[Sqrt[c + d*x]], -1])/(2401*d*e*(c + d*x)^(7/2)) - (10/49)*b*e^3*Int[(a + b*ArcSin[c + d*x])^2/(Sqrt[c*e + d*e*x]*Sqrt[1 - (c + d*x)^2]), x]}
{(c*e + d*e*x)^(3/2)*(a + b*ArcSin[c + d*x])^3, x, 7, -((96*b^3*(c*e + d*e*x)^(5/2)*Sqrt[1 - (c + d*x)^2])/(625*d*e*(c + d*x))) - (48*b^2*(c*e + d*e*x)^(5/2)*(a + b*ArcSin[c + d*x]))/(125*d*e) + (12*b*(c*e + d*e*x)^(3/2)*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^2)/(25*d) + (2*(c*e + d*e*x)^(5/2)*(a + b*ArcSin[c + d*x])^3)/(5*d*e) + (288*b^3*(c*e + d*e*x)^(5/2)*EllipticE[ArcSin[Sqrt[c + d*x]], -1])/(625*d*e*(c + d*x)^(5/2)) - (288*b^3*(c*e + d*e*x)^(5/2)*EllipticF[ArcSin[Sqrt[c + d*x]], -1])/(625*d*e*(c + d*x)^(5/2)) - (18/25)*b*e*Int[(Sqrt[c*e + d*e*x]*(a + b*ArcSin[c + d*x])^2)/Sqrt[1 - (c + d*x)^2], x]}
{(c*e + d*e*x)^(1/2)*(a + b*ArcSin[c + d*x])^3, x, 7, -((32*b^3*(c*e + d*e*x)^(3/2)*Sqrt[1 - (c + d*x)^2])/(27*d*e*(c + d*x))) - (16*b^2*(c*e + d*e*x)^(3/2)*(a + b*ArcSin[c + d*x]))/(9*d*e) + (4*b*Sqrt[c*e + d*e*x]*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^2)/(3*d) + (2*(c*e + d*e*x)^(3/2)*(a + b*ArcSin[c + d*x])^3)/(3*d*e) + (32*b^3*(c*e + d*e*x)^(3/2)*EllipticF[ArcSin[Sqrt[c + d*x]], -1])/(27*d*e*(c + d*x)^(3/2)) - (2/3)*b*e*Int[(a + b*ArcSin[c + d*x])^2/(Sqrt[c*e + d*e*x]*Sqrt[1 - (c + d*x)^2]), x]}
{(a + b*ArcSin[c + d*x])^3/(c*e + d*e*x)^(1/2), x, 1, (2*Sqrt[c*e + d*e*x]*(a + b*ArcSin[c + d*x])^3)/(d*e) - (6*b*Defer[Int][(Sqrt[c*e + d*e*x]*(a + b*ArcSin[c + d*x])^2)/Sqrt[1 - (c + d*x)^2], x])/e}
{(a + b*ArcSin[c + d*x])^3/(c*e + d*e*x)^(3/2), x, 1, (-2*(a + b*ArcSin[c + d*x])^3)/(d*e*Sqrt[c*e + d*e*x]) + (6*b*Defer[Int][(a + b*ArcSin[c + d*x])^2/(Sqrt[c*e + d*e*x]*Sqrt[1 - (c + d*x)^2]), x])/e}
{(a + b*ArcSin[c + d*x])^3/(c*e + d*e*x)^(5/2), x, 6, (16*b^2*Sqrt[c*e + d*e*x]*(a + b*ArcSin[c + d*x]))/(d*e^3) - (4*b*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^2)/(d*e^2*Sqrt[c*e + d*e*x]) - (2*(a + b*ArcSin[c + d*x])^3)/(3*d*e*(c*e + d*e*x)^(3/2)) - (32*b^3*Sqrt[c*e + d*e*x]*EllipticE[ArcSin[Sqrt[c + d*x]], -1])/(d*e^3*Sqrt[c + d*x]) + (32*b^3*Sqrt[c*e + d*e*x]*EllipticF[ArcSin[Sqrt[c + d*x]], -1])/(d*e^3*Sqrt[c + d*x]) - (2*b*Int[(Sqrt[c*e + d*e*x]*(a + b*ArcSin[c + d*x])^2)/Sqrt[1 - (c + d*x)^2], x])/e^3}
{(a + b*ArcSin[c + d*x])^3/(c*e + d*e*x)^(7/2), x, 6, -((16*b^2*(a + b*ArcSin[c + d*x]))/(5*d*e^3*Sqrt[c*e + d*e*x])) - (4*b*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^2)/(5*d*e^2*(c*e + d*e*x)^(3/2)) - (2*(a + b*ArcSin[c + d*x])^3)/(5*d*e*(c*e + d*e*x)^(5/2)) + (32*b^3*Sqrt[c + d*x]*EllipticF[ArcSin[Sqrt[c + d*x]], -1])/(5*d*e^3*Sqrt[c*e + d*e*x]) + (2*b*Int[(a + b*ArcSin[c + d*x])^2/(Sqrt[c*e + d*e*x]*Sqrt[1 - (c + d*x)^2]), x])/(5*e^3)}


{(c*e + d*e*x)^(7/2)*(a + b*ArcSin[c + d*x])^4, x, 13, (189952*b^4*e*(c*e + d*e*x)^(5/2))/(1366875*d) + (256*b^4*(c*e + d*e*x)^(9/2))/(19683*d*e) - (94976*b^3*e^2*(c*e + d*e*x)^(3/2)*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x]))/(273375*d) - (128*b^3*(c*e + d*e*x)^(7/2)*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x]))/(2187*d) - (224*b^2*e*(c*e + d*e*x)^(5/2)*(a + b*ArcSin[c + d*x])^2)/(675*d) - (32*b^2*(c*e + d*e*x)^(9/2)*(a + b*ArcSin[c + d*x])^2)/(243*d*e) + (112*b*e^2*(c*e + d*e*x)^(3/2)*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^3)/(405*d) + (16*b*(c*e + d*e*x)^(7/2)*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^3)/(81*d) + (2*(c*e + d*e*x)^(9/2)*(a + b*ArcSin[c + d*x])^4)/(9*d*e) + (94976*b^3*e^3*(c + d*x)*Sqrt[c*e + d*e*x]*(a + b*ArcSin[c + d*x])*Hypergeometric2F1[1/2, 3/4, 7/4, (c + d*x)^2])/(273375*d) - (189952*b^4*e^3*(c + d*x)^2*Sqrt[c*e + d*e*x]*HypergeometricPFQ[{1, 5/4, 5/4}, {7/4, 9/4}, (c + d*x)^2])/(1366875*d) - (56*b*e^3*Defer[Int][(Sqrt[c*e + d*e*x]*(a + b*ArcSin[c + d*x])^3)/Sqrt[1 - (c + d*x)^2], x])/135}
{(c*e + d*e*x)^(5/2)*(a + b*ArcSin[c + d*x])^4, x, 13, (74240*b^4*e*(c*e + d*e*x)^(3/2))/(64827*d) + (768*b^4*(c*e + d*e*x)^(7/2))/(16807*d*e) - (37120*b^3*e^2*Sqrt[c*e + d*e*x]*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x]))/(21609*d) - (384*b^3*(c*e + d*e*x)^(5/2)*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x]))/(2401*d) - (160*b^2*e*(c*e + d*e*x)^(3/2)*(a + b*ArcSin[c + d*x])^2)/(147*d) - (96*b^2*(c*e + d*e*x)^(7/2)*(a + b*ArcSin[c + d*x])^2)/(343*d*e) + (80*b*e^2*Sqrt[c*e + d*e*x]*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^3)/(147*d) + (16*b*(c*e + d*e*x)^(5/2)*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^3)/(49*d) + (2*(c*e + d*e*x)^(7/2)*(a + b*ArcSin[c + d*x])^4)/(7*d*e) + (37120*b^3*e^3*(c + d*x)*(a + b*ArcSin[c + d*x])*Hypergeometric2F1[1/4, 1/2, 5/4, (c + d*x)^2])/(21609*d*Sqrt[c*e + d*e*x]) - (74240*b^4*e^3*(c + d*x)^2*HypergeometricPFQ[{3/4, 3/4, 1}, {5/4, 7/4}, (c + d*x)^2])/(64827*d*Sqrt[c*e + d*e*x]) - (40*b*e^3*Defer[Int][(a + b*ArcSin[c + d*x])^3/(Sqrt[c*e + d*e*x]*Sqrt[1 - (c + d*x)^2]), x])/147}
{(c*e + d*e*x)^(3/2)*(a + b*ArcSin[c + d*x])^4, x, 6, (768*b^4*(c*e + d*e*x)^(5/2))/(3125*d*e) - (384*b^3*(c*e + d*e*x)^(3/2)*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x]))/(625*d) - (96*b^2*(c*e + d*e*x)^(5/2)*(a + b*ArcSin[c + d*x])^2)/(125*d*e) + (16*b*(c*e + d*e*x)^(3/2)*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^3)/(25*d) + (2*(c*e + d*e*x)^(5/2)*(a + b*ArcSin[c + d*x])^4)/(5*d*e) + (384*b^3*e*(c + d*x)*Sqrt[c*e + d*e*x]*(a + b*ArcSin[c + d*x])*Hypergeometric2F1[1/2, 3/4, 7/4, (c + d*x)^2])/(625*d) - (768*b^4*e*(c + d*x)^2*Sqrt[c*e + d*e*x]*HypergeometricPFQ[{1, 5/4, 5/4}, {7/4, 9/4}, (c + d*x)^2])/(3125*d) - (24*b*e*Defer[Int][(Sqrt[c*e + d*e*x]*(a + b*ArcSin[c + d*x])^3)/Sqrt[1 - (c + d*x)^2], x])/25}
{(c*e + d*e*x)^(1/2)*(a + b*ArcSin[c + d*x])^4, x, 6, (256*b^4*(c*e + d*e*x)^(3/2))/(81*d*e) - (128*b^3*Sqrt[c*e + d*e*x]*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x]))/(27*d) - (32*b^2*(c*e + d*e*x)^(3/2)*(a + b*ArcSin[c + d*x])^2)/(9*d*e) + (16*b*Sqrt[c*e + d*e*x]*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^3)/(9*d) + (2*(c*e + d*e*x)^(3/2)*(a + b*ArcSin[c + d*x])^4)/(3*d*e) + (128*b^3*e*(c + d*x)*(a + b*ArcSin[c + d*x])*Hypergeometric2F1[1/4, 1/2, 5/4, (c + d*x)^2])/(27*d*Sqrt[c*e + d*e*x]) - (256*b^4*e*(c + d*x)^2*HypergeometricPFQ[{3/4, 3/4, 1}, {5/4, 7/4}, (c + d*x)^2])/(81*d*Sqrt[c*e + d*e*x]) - (8*b*e*Defer[Int][(a + b*ArcSin[c + d*x])^3/(Sqrt[c*e + d*e*x]*Sqrt[1 - (c + d*x)^2]), x])/9}
{(a + b*ArcSin[c + d*x])^4/(c*e + d*e*x)^(1/2), x, 1, (2*Sqrt[c*e + d*e*x]*(a + b*ArcSin[c + d*x])^4)/(d*e) - (8*b*Defer[Int][(Sqrt[c*e + d*e*x]*(a + b*ArcSin[c + d*x])^3)/Sqrt[1 - (c + d*x)^2], x])/e}
{(a + b*ArcSin[c + d*x])^4/(c*e + d*e*x)^(3/2), x, 1, (-2*(a + b*ArcSin[c + d*x])^4)/(d*e*Sqrt[c*e + d*e*x]) + (8*b*Defer[Int][(a + b*ArcSin[c + d*x])^3/(Sqrt[c*e + d*e*x]*Sqrt[1 - (c + d*x)^2]), x])/e}
{(a + b*ArcSin[c + d*x])^4/(c*e + d*e*x)^(5/2), x, 4, (32*b^2*Sqrt[c*e + d*e*x]*(a + b*ArcSin[c + d*x])^2)/(d*e^3) - (16*b*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^3)/(3*d*e^2*Sqrt[c*e + d*e*x]) - (2*(a + b*ArcSin[c + d*x])^4)/(3*d*e*(c*e + d*e*x)^(3/2)) - (128*b^3*(c + d*x)*Sqrt[c*e + d*e*x]*(a + b*ArcSin[c + d*x])*Hypergeometric2F1[1/2, 3/4, 7/4, (c + d*x)^2])/(3*d*e^3) + (256*b^4*(c + d*x)^2*Sqrt[c*e + d*e*x]*HypergeometricPFQ[{1, 5/4, 5/4}, {7/4, 9/4}, (c + d*x)^2])/(15*d*e^3) - (8*b*Defer[Int][(Sqrt[c*e + d*e*x]*(a + b*ArcSin[c + d*x])^3)/Sqrt[1 - (c + d*x)^2], x])/(3*e^3)}
{(a + b*ArcSin[c + d*x])^4/(c*e + d*e*x)^(7/2), x, 4, (-32*b^2*(a + b*ArcSin[c + d*x])^2)/(5*d*e^3*Sqrt[c*e + d*e*x]) - (16*b*Sqrt[1 - (c + d*x)^2]*(a + b*ArcSin[c + d*x])^3)/(15*d*e^2*(c*e + d*e*x)^(3/2)) - (2*(a + b*ArcSin[c + d*x])^4)/(5*d*e*(c*e + d*e*x)^(5/2)) + (128*b^3*(c + d*x)*(a + b*ArcSin[c + d*x])*Hypergeometric2F1[1/4, 1/2, 5/4, (c + d*x)^2])/(5*d*e^3*Sqrt[c*e + d*e*x]) - (256*b^4*(c + d*x)^2*HypergeometricPFQ[{3/4, 3/4, 1}, {5/4, 7/4}, (c + d*x)^2])/(15*d*e^3*Sqrt[c*e + d*e*x]) + (8*b*Defer[Int][(a + b*ArcSin[c + d*x])^3/(Sqrt[c*e + d*e*x]*Sqrt[1 - (c + d*x)^2]), x])/(15*e^3)}


(* ::Subsubsection:: *)
(*n<0*)


(* ::Section::Closed:: *)
(*Integrands involving inverse trig functions of exponentials*)


{E^x*ArcSin[E^x], x, 2, Sqrt[1 - E^(2*x)] + E^x*ArcSin[E^x]}


{ArcSin[c*E^(a + b*x)], x, 6, -((I*ArcSin[c*E^(a + b*x)]^2)/(2*b)) + (ArcSin[c*E^(a + b*x)]*Log[1 - E^(2*I*ArcSin[c*E^(a + b*x)])])/b - (I*PolyLog[2, E^(2*I*ArcSin[c*E^(a + b*x)])])/(2*b)}


(* ::Section::Closed:: *)
(*Integrands involving exponentials of inverse trig functions*)


(* Integrands of the form x^m*E^ArcSin[x] where m is an integer *)
{x^3*E^ArcSin[x], x, 5, (-(1/10))*E^ArcSin[x]*Cos[2*ArcSin[x]] + (1/34)*E^ArcSin[x]*Cos[4*ArcSin[x]] + (1/20)*E^ArcSin[x]*Sin[2*ArcSin[x]] - (1/136)*E^ArcSin[x]*Sin[4*ArcSin[x]]}
{x^2*E^ArcSin[x], x, 5, (1/8)*E^ArcSin[x]*x + (1/8)*E^ArcSin[x]*Sqrt[1 - x^2] - (1/40)*E^ArcSin[x]*Cos[3*ArcSin[x]] - (3/40)*E^ArcSin[x]*Sin[3*ArcSin[x]]}
{x*E^ArcSin[x], x, 4, (-(1/5))*E^ArcSin[x]*Cos[2*ArcSin[x]] + (1/10)*E^ArcSin[x]*Sin[2*ArcSin[x]]}
{E^ArcSin[x], x, 1, (1/2)*E^ArcSin[x]*(x + Sqrt[1 - x^2])}
{E^ArcSin[x]/x, x, 1, (-(2/5) - I/5)*E^ArcSin[x]*((1 + 2*I)*Hypergeometric2F1[-(I/2), 1, 1 - I/2, E^(2*I*ArcSin[x])] + E^(2*I*ArcSin[x])*Hypergeometric2F1[1, 1 - I/2, 2 - I/2, E^(2*I*ArcSin[x])])}


{E^ArcSin[x]/Sqrt[1 - x^2], x, 2, E^ArcSin[x]}


(* ::Section::Closed:: *)
(*Miscellaneous integrands involving inverse sines*)


{ArcSin[c/(a + b*x)], x, 5, ((a + b*x)*ArcCsc[a/c + (b*x)/c])/b + (c*ArcTanh[Sqrt[1 - c^2/(a + b*x)^2]])/b}
