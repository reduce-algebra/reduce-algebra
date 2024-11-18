(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Cosecants*)


(* ::Subsection::Closed:: *)
(*(c+d x)^m Csc[a+b x]^n*)


(* Integrands of the form x^m*Csc[a+b*x]^n where m and n are integers *)
{x*Csc[a + b*x], x, 4, -((2*x*ArcTanh[E^(I*a + I*b*x)])/b) + (I*PolyLog[2, -E^(I*a + I*b*x)])/b^2 - (I*PolyLog[2, E^(I*a + I*b*x)])/b^2}
{x^2*Csc[a + b*x], x, 6, -((2*x^2*ArcTanh[E^(I*a + I*b*x)])/b) + (2*I*x*PolyLog[2, -E^(I*a + I*b*x)])/b^2 - (2*I*x*PolyLog[2, E^(I*a + I*b*x)])/b^2 - (2*PolyLog[3, -E^(I*a + I*b*x)])/b^3 + (2*PolyLog[3, E^(I*a + I*b*x)])/b^3}
{x^3*Csc[a + b*x], x, 8, -((2*x^3*ArcTanh[E^(I*a + I*b*x)])/b) + (3*I*x^2*PolyLog[2, -E^(I*a + I*b*x)])/b^2 - (3*I*x^2*PolyLog[2, E^(I*a + I*b*x)])/b^2 - (6*x*PolyLog[3, -E^(I*a + I*b*x)])/b^3 + (6*x*PolyLog[3, E^(I*a + I*b*x)])/b^3 - (6*I*PolyLog[4, -E^(I*a + I*b*x)])/b^4 + (6*I*PolyLog[4, E^(I*a + I*b*x)])/b^4}
{1/x*Csc[a + b*x], x, 0, Int[Csc[a + b*x]/x, x]}

{x*Csc[a + b*x]^2, x, 2, -((x*Cot[a + b*x])/b) + Log[Sin[a + b*x]]/b^2}
{x^2*Csc[a + b*x]^2, x, 5, -((I*x^2)/b) - (x^2*Cot[a + b*x])/b + (2*x*Log[1 - E^(2*I*a + 2*I*b*x)])/b^2 - (I*PolyLog[2, E^(2*I*a + 2*I*b*x)])/b^3}
{x^3*Csc[a + b*x]^2, x, 6, -((I*x^3)/b) - (x^3*Cot[a + b*x])/b + (3*x^2*Log[1 - E^(2*I*a + 2*I*b*x)])/b^2 - (3*I*x*PolyLog[2, E^(2*I*a + 2*I*b*x)])/b^3 + (3*PolyLog[3, E^(2*I*a + 2*I*b*x)])/(2*b^4)}
{1/x*Csc[a + b*x]^2, x, 0, Int[Csc[a + b*x]^2/x, x]}

{x*Csc[a + b*x]^3, x, 5, -((x*ArcTanh[E^(I*a + I*b*x)])/b) - Csc[a + b*x]/(2*b^2) - (x*Cot[a + b*x]*Csc[a + b*x])/(2*b) + (I*PolyLog[2, -E^(I*a + I*b*x)])/(2*b^2) - (I*PolyLog[2, E^(I*a + I*b*x)])/(2*b^2)}
{x^2*Csc[a + b*x]^3, x, 8, -((x^2*ArcTanh[E^(I*a + I*b*x)])/b) - ArcTanh[Cos[a + b*x]]/b^3 - (x*Csc[a + b*x])/b^2 - (x^2*Cot[a + b*x]*Csc[a + b*x])/(2*b) + (I*x*PolyLog[2, -E^(I*a + I*b*x)])/b^2 - (I*x*PolyLog[2, E^(I*a + I*b*x)])/b^2 - PolyLog[3, -E^(I*a + I*b*x)]/b^3 + PolyLog[3, E^(I*a + I*b*x)]/b^3}
(* {x^3*Csc[a + b*x]^3, x, 13, -((6*x*ArcTanh[E^(I*a + I*b*x)])/b^3) - (x^3*ArcTanh[E^(I*a + I*b*x)])/b - (3*x^2*Csc[a + b*x])/(2*b^2) - (x^3*Cot[a + b*x]*Csc[a + b*x])/(2*b) + (3*I*(2 + b^2*x^2)*PolyLog[2, -E^(I*a + I*b*x)])/(2*b^4) - (3*I*(2 + b^2*x^2)*PolyLog[2, E^(I*a + I*b*x)])/(2*b^4) - (3*x*PolyLog[3, -E^(I*a + I*b*x)])/b^3 + (3*x*PolyLog[3, E^(I*a + I*b*x)])/b^3 - (3*I*PolyLog[4, -E^(I*a + I*b*x)])/b^4 + (3*I*PolyLog[4, E^(I*a + I*b*x)])/b^4} *)
{1/x*Csc[a + b*x]^3, x, 0, Int[Csc[a + b*x]^3/x, x]}


(* Integrands of the form (c+d*x)^m*Csc[a+b*x]^n where m and n are integers *)
{(c + d*x)*Csc[a + b*x], x, 5, -((2*(c + d*x)*ArcTanh[E^(I*a + I*b*x)])/b) + (I*d*PolyLog[2, -E^(I*a + I*b*x)])/b^2 - (I*d*PolyLog[2, E^(I*a + I*b*x)])/b^2}
{(c + d*x)^2*Csc[a + b*x], x, 7, -((2*(c + d*x)^2*ArcTanh[E^(I*a + I*b*x)])/b) + (2*I*d*(c + d*x)*PolyLog[2, -E^(I*a + I*b*x)])/b^2 - (2*I*d*(c + d*x)*PolyLog[2, E^(I*a + I*b*x)])/b^2 - (2*d^2*PolyLog[3, -E^(I*a + I*b*x)])/b^3 + (2*d^2*PolyLog[3, E^(I*a + I*b*x)])/b^3}
{(c + d*x)^3*Csc[a + b*x], x, 9, -((2*(c + d*x)^3*ArcTanh[E^(I*a + I*b*x)])/b) + (3*I*d*(c + d*x)^2*PolyLog[2, -E^(I*a + I*b*x)])/b^2 - (3*I*d*(c + d*x)^2*PolyLog[2, E^(I*a + I*b*x)])/b^2 - (6*d^2*(c + d*x)*PolyLog[3, -E^(I*a + I*b*x)])/b^3 + (6*d^2*(c + d*x)*PolyLog[3, E^(I*a + I*b*x)])/b^3 - (6*I*d^3*PolyLog[4, -E^(I*a + I*b*x)])/b^4 + (6*I*d^3*PolyLog[4, E^(I*a + I*b*x)])/b^4}

{(c + d*x)*Csc[a + b*x]^2, x, 3, -(((c + d*x)*Cot[a + b*x])/b) + (d*Log[Sin[a + b*x]])/b^2}
{(c + d*x)^2*Csc[a + b*x]^2, x, 6, -((I*(c + d*x)^2)/b) - ((c + d*x)^2*Cot[a + b*x])/b + (2*d*(c + d*x)*Log[1 - E^(2*I*a + 2*I*b*x)])/b^2 - (I*d^2*PolyLog[2, E^(2*I*a + 2*I*b*x)])/b^3}
{(c + d*x)^3*Csc[a + b*x]^2, x, 7, -((I*(c + d*x)^3)/b) - ((c + d*x)^3*Cot[a + b*x])/b + (3*d*(c + d*x)^2*Log[1 - E^(2*I*a + 2*I*b*x)])/b^2 - (3*I*d^2*(c + d*x)*PolyLog[2, E^(2*I*a + 2*I*b*x)])/b^3 + (3*d^3*PolyLog[3, E^(2*I*a + 2*I*b*x)])/(2*b^4)}

{(c + d*x)*Csc[a + b*x]^3, x, 6, -(((c + d*x)*ArcTanh[E^(I*a + I*b*x)])/b) - (d*Csc[a + b*x])/(2*b^2) - ((c + d*x)*Cot[a + b*x]*Csc[a + b*x])/(2*b) + (I*d*PolyLog[2, -E^(I*a + I*b*x)])/(2*b^2) - (I*d*PolyLog[2, E^(I*a + I*b*x)])/(2*b^2)}
{(c + d*x)^2*Csc[a + b*x]^3, x, 9, -(((c + d*x)^2*ArcTanh[E^(I*a + I*b*x)])/b) - (d^2*ArcTanh[Cos[a + b*x]])/b^3 - (d*(c + d*x)*Csc[a + b*x])/b^2 - ((c + d*x)^2*Cot[a + b*x]*Csc[a + b*x])/(2*b) + (I*d*(c + d*x)*PolyLog[2, -E^(I*a + I*b*x)])/b^2 - (I*d*(c + d*x)*PolyLog[2, E^(I*a + I*b*x)])/b^2 - (d^2*PolyLog[3, -E^(I*a + I*b*x)])/b^3 + (d^2*PolyLog[3, E^(I*a + I*b*x)])/b^3}
(* {(c + d*x)^3*Csc[a + b*x]^3, x, 14, -((6*d^2*(c + d*x)*ArcTanh[E^(I*a + I*b*x)])/b^3) - ((c + d*x)^3*ArcTanh[E^(I*a + I*b*x)])/b - (3*d*(c + d*x)^2*Csc[a + b*x])/(2*b^2) - ((c + d*x)^3*Cot[a + b*x]*Csc[a + b*x])/(2*b) + (3*I*d*(2*d^2 + b^2*(c + d*x)^2)*PolyLog[2, -E^(I*a + I*b*x)])/(2*b^4) - (3*I*d*(2*d^2 + b^2*(c + d*x)^2)*PolyLog[2, E^(I*a + I*b*x)])/(2*b^4) - (3*d^2*(c + d*x)*PolyLog[3, -E^(I*a + I*b*x)])/b^3 + (3*d^2*(c + d*x)*PolyLog[3, E^(I*a + I*b*x)])/b^3 - (3*I*d^3*PolyLog[4, -E^(I*a + I*b*x)])/b^4 + (3*I*d^3*PolyLog[4, E^(I*a + I*b*x)])/b^4} *)


{x*Csc[a + b*x^2]^7, x, 5, -((5*ArcTanh[Cos[a + b*x^2]])/(32*b)) - (5*Cot[a + b*x^2]*Csc[a + b*x^2])/(32*b) - (5*Cot[a + b*x^2]*Csc[a + b*x^2]^3)/(48*b) - (Cot[a + b*x^2]*Csc[a + b*x^2]^5)/(12*b)}


(* ::Subsection::Closed:: *)
(*(a Csc[a+b x]^n)^m*)


{(Csc[x]^2)^(5/2), x, 4, (-(3/8))*ArcCsch[Tan[x]] - (3/8)*Cot[x]*Sqrt[Csc[x]^2] - (1/4)*Cot[x]*(Csc[x]^2)^(3/2)}
{(Csc[x]^2)^(3/2), x, 3, (-(1/2))*ArcCsch[Tan[x]] - (1/2)*Cot[x]*Sqrt[Csc[x]^2]}
{(Csc[x]^2)^(1/2), x, 2, -ArcCsch[Tan[x]]}
{1/(Csc[x]^2)^(1/2), x, 2, -(Cot[x]/Sqrt[Csc[x]^2])}
{1/(Csc[x]^2)^(3/2), x, 3, -(((3 - Cos[x]^2)*Cot[x])/(3*Sqrt[Csc[x]^2]))}
{1/(Csc[x]^2)^(5/2), x, 3, -(((15 - 10*Cos[x]^2 + 3*Cos[x]^4)*Cot[x])/(15*Sqrt[Csc[x]^2]))}
{1/(Csc[x]^2)^(7/2), x, 3, -((Cot[x]*(21*Cos[x]^4 - 5*Cos[x]^6 + 35*Sin[x]^2))/(35*Sqrt[Csc[x]^2]))}


{(a*Csc[x]^2)^(5/2), x, 4, (-(1/8))*a^2*Sqrt[a*Csc[x]^2]*(3*ArcTanh[Cos[x]] + 3*Cot[x]*Csc[x] + 2*Cot[x]*Csc[x]^3)*Sin[x]}
{(a*Csc[x]^2)^(3/2), x, 3, (-(1/2))*a*Sqrt[a*Csc[x]^2]*(ArcTanh[Cos[x]] + Cot[x]*Csc[x])*Sin[x]}
{(a*Csc[x]^2)^(1/2), x, 2, (-ArcTanh[Cos[x]])*Sqrt[a*Csc[x]^2]*Sin[x]}
{1/(a*Csc[x]^2)^(1/2), x, 2, -(Cot[x]/Sqrt[a*Csc[x]^2])}
{1/(a*Csc[x]^2)^(3/2), x, 3, -(((3 - Cos[x]^2)*Cot[x])/(3*a*Sqrt[a*Csc[x]^2]))}
{1/(a*Csc[x]^2)^(5/2), x, 3, -(((15 - 10*Cos[x]^2 + 3*Cos[x]^4)*Cot[x])/(15*a^2*Sqrt[a*Csc[x]^2]))}
{1/(a*Csc[x]^2)^(7/2), x, 3, -((Cot[x]*(21*Cos[x]^4 - 5*Cos[x]^6 + 35*Sin[x]^2))/(35*a^3*Sqrt[a*Csc[x]^2]))}


{(a*Csc[x]^3)^(5/2), x, 7, (-(2/585))*a^2*Sqrt[a*Csc[x]^3]*(231*Cos[x] + 77*Cot[x]*Csc[x] + 55*Cot[x]*Csc[x]^3 + 45*Cot[x]*Csc[x]^5 - 231*EllipticE[Pi/4 - x/2, 2]*Sqrt[Sin[x]])*Sin[x]}
{(a*Csc[x]^3)^(3/2), x, 5, (-(2/21))*a*Sqrt[a*Csc[x]^3]*(5*Cot[x] + 3*Cot[x]*Csc[x]^2 + 5*EllipticF[Pi/4 - x/2, 2]*Sqrt[Sin[x]])*Sin[x]}
{(a*Csc[x]^3)^(1/2), x, 4, -2*Sqrt[a*Csc[x]^3]*(Cos[x] - EllipticE[Pi/4 - x/2, 2]*Sqrt[Sin[x]])*Sin[x]}
{1/(a*Csc[x]^3)^(1/2), x, 4, -((2*Csc[x]*(Cos[x] + EllipticF[Pi/4 - x/2, 2]/Sqrt[Sin[x]]))/(3*Sqrt[a*Csc[x]^3]))}
{1/(a*Csc[x]^3)^(3/2), x, 5, -((2*(5*Cos[x] + 7*Csc[x]^2*(Cos[x] + (3*EllipticE[Pi/4 - x/2, 2])/Sin[x]^(3/2)))*Sin[x]^2)/(45*a*Sqrt[a*Csc[x]^3]))}
{1/(a*Csc[x]^3)^(5/2), x, 7, -((2*(77*Cos[x] + 13*Csc[x]^2*(7*Cos[x] + 3*Csc[x]^2*(3*Cos[x] + 5*Csc[x]^2*(Cos[x] + EllipticF[Pi/4 - x/2, 2]/Sqrt[Sin[x]]))))*Sin[x]^5)/(1155*a^2*Sqrt[a*Csc[x]^3]))}


{(a*Csc[x]^4)^(7/2), x, 3, -((a^3*Cos[x]*(3003 + 6006*Cot[x]^2 + 9009*Cot[x]^4 + 8580*Cot[x]^6 + 5005*Cot[x]^8 + 1638*Cot[x]^10 + 231*Cot[x]^12)*Sqrt[a*Csc[x]^4]*Sin[x])/3003)}
{(a*Csc[x]^4)^(5/2), x, 3, (-(1/315))*a^2*Cos[x]*(315 + 420*Cot[x]^2 + 378*Cot[x]^4 + 180*Cot[x]^6 + 35*Cot[x]^8)*Sqrt[a*Csc[x]^4]*Sin[x]}
{(a*Csc[x]^4)^(3/2), x, 3, (-(1/15))*a*Cos[x]*(15 + 10*Cot[x]^2 + 3*Cot[x]^4)*Sqrt[a*Csc[x]^4]*Sin[x]}
{(a*Csc[x]^4)^(1/2), x, 2, (-Cos[x])*Sqrt[a*Csc[x]^4]*Sin[x]}
{1/(a*Csc[x]^4)^(1/2), x, 2, (Csc[x]^2*(x - Cos[x]*Sin[x]))/(2*Sqrt[a*Csc[x]^4])}
{1/(a*Csc[x]^4)^(3/2), x, 4, (Csc[x]^2*(15*x - 15*Cos[x]*Sin[x] - 10*Cos[x]*Sin[x]^3 - 8*Cos[x]*Sin[x]^5))/(48*a*Sqrt[a*Csc[x]^4])}
{1/(a*Csc[x]^4)^(5/2), x, 6, (Csc[x]^2*(315*x - 315*Cos[x]*Sin[x] - 210*Cos[x]*Sin[x]^3 - 168*Cos[x]*Sin[x]^5 - 144*Cos[x]*Sin[x]^7 - 128*Cos[x]*Sin[x]^9))/(1280*a^2*Sqrt[a*Csc[x]^4])}


(* ::Subsection::Closed:: *)
(*(a+b Csc[c+d x]^n)^m*)


(* Integrands of the form (a+b*Csc[x]^2)^m where m is a half-integer *)
{Sqrt[1 + Csc[x]^2], x, 4, -ArcSinh[Cot[x]/Sqrt[2]] - ArcTan[Cot[x]/Sqrt[2 + Cot[x]^2]]}
{Sqrt[1 - Csc[x]^2], x, 3, Sqrt[-Cot[x]^2]*Log[Sin[x]]*Tan[x]}
{Sqrt[-1 + Csc[x]^2], x, 3, Sqrt[Cot[x]^2]*Log[Sin[x]]*Tan[x]}
{Sqrt[-1 - Csc[x]^2], x, 4, ArcTan[Cot[x]/Sqrt[-2 - Cot[x]^2]] + ArcTanh[Cot[x]/Sqrt[-2 - Cot[x]^2]]}
{Sqrt[a + b*Csc[x]^2], x, 4, (-Sqrt[a])*ArcTan[(Sqrt[a]*Cot[x])/Sqrt[a + b*Csc[x]^2]] - Sqrt[b]*ArcTanh[(Sqrt[b]*Cot[x])/Sqrt[a + b*Csc[x]^2]]}

{1/Sqrt[1 + Csc[x]^2], x, 2, -ArcTan[Cot[x]/Sqrt[2 + Cot[x]^2]]}
{1/Sqrt[1 - Csc[x]^2], x, 3, -((Cot[x]*Log[Cos[x]])/Sqrt[-Cot[x]^2])}
{1/Sqrt[-1 + Csc[x]^2], x, 3, -((Cot[x]*Log[Cos[x]])/Sqrt[Cot[x]^2])}
{1/Sqrt[-1 - Csc[x]^2], x, 2, -ArcTanh[Cot[x]/Sqrt[-2 - Cot[x]^2]]}
{1/Sqrt[a + b*Csc[x]^2], x, 2, -(ArcTan[(Sqrt[a]*Cot[x])/Sqrt[a + b*Csc[x]^2]]/Sqrt[a])}

{(1 + Csc[x]^2)^(3/2), x, 7, -2*ArcSinh[Cot[x]/Sqrt[2]] - ArcTan[Cot[x]/Sqrt[2 + Cot[x]^2]] - (1/2)*Cot[x]*Sqrt[2 + Cot[x]^2]}
{(1 - Csc[x]^2)^(3/2), x, 4, (1/2)*Cot[x]*Sqrt[-Cot[x]^2] + Sqrt[-Cot[x]^2]*Log[Sin[x]]*Tan[x]}
{(-1 + Csc[x]^2)^(3/2), x, 4, (-(1/2))*(Cot[x]^2)^(3/2)*Tan[x] - Sqrt[Cot[x]^2]*Log[Sin[x]]*Tan[x]}
{(-1 - Csc[x]^2)^(3/2), x, 7, -2*ArcTan[Cot[x]/Sqrt[-2 - Cot[x]^2]] - ArcTanh[Cot[x]/Sqrt[-2 - Cot[x]^2]] + (1/2)*Cot[x]*Sqrt[-2 - Cot[x]^2]}
{(a + b*Csc[x]^2)^(3/2), x, 7, (-a^(3/2))*ArcTan[(Sqrt[a]*Cot[x])/Sqrt[a + b*Csc[x]^2]] - (3/2)*a*Sqrt[b]*ArcTanh[(Sqrt[b]*Cot[x])/Sqrt[a + b*Csc[x]^2]] - (1/2)*b^(3/2)*ArcTanh[(Sqrt[b]*Cot[x])/Sqrt[a + b*Csc[x]^2]] - (1/2)*b*Cot[x]*Sqrt[a + b*Csc[x]^2]}


(* ::Subsection::Closed:: *)
(*x^m Csc[a+b Log[c x^n]]^p*)


{Csc[a + b*Log[c*x^n]], x, 0, Int[Csc[a + b*Log[c*x^n]], x]}
{Csc[a + b*Log[c*x^n]]^2, x, 0, Int[Csc[a + b*Log[c*x^n]]^2, x]}
{Csc[a + b*Log[c*x^n]]^3, x, 1, -((x*Csc[a + b*Log[c*x^n]])/(2*b^2*n^2)) - (x*Cot[a + b*Log[c*x^n]]*Csc[a + b*Log[c*x^n]])/(2*b*n) + ((1 + b^2*n^2)*Int[Csc[a + b*Log[c*x^n]], x])/(2*b^2*n^2)}
{Csc[a + b*Log[c*x^n]]^4, x, 1, -((x*Csc[a + b*Log[c*x^n]]^2)/(6*b^2*n^2)) - (x*Cot[a + b*Log[c*x^n]]*Csc[a + b*Log[c*x^n]]^2)/(3*b*n) + ((1 + 4*b^2*n^2)*Int[Csc[a + b*Log[c*x^n]]^2, x])/(6*b^2*n^2)}

{2*b^2*n^2*Csc[a + b*Log[c*x^n]]^3 - (1 + b^2*n^2)*Csc[a + b*Log[c*x^n]], x, 2, (-x)*Csc[a + b*Log[c*x^n]] - b*n*x*Cot[a + b*Log[c*x^n]]*Csc[a + b*Log[c*x^n]]}


{Csc[a + 2*Log[c*x^(I/2)]]^3, x, 1, (-(1/2))*I*x*(I - Cot[a + 2*Log[c*x^(I/2)]])*Csc[a + 2*Log[c*x^(I/2)]]}
{Csc[a + 2*Log[c/x^(I/2)]]^3, x, 1, (-(1/2))*I*x*(I + Cot[a + 2*Log[c/x^(I/2)]])*Csc[a + 2*Log[c/x^(I/2)]]}
{Csc[a + I/(n*(-2 + p))*Log[c*x^n]]^p, x, 1, -((I*(2 - p)*x*(I - Cot[a - (I*Log[c*x^n])/(n*(2 - p))])*Csc[a - (I*Log[c*x^n])/(n*(2 - p))]^(-2 + p))/(1 - p))}
{Csc[a - I/(n*(-2 + p))*Log[c*x^n]]^p, x, 1, -((I*(2 - p)*x*(I + Cot[a + (I*Log[c*x^n])/(n*(2 - p))])*Csc[a + (I*Log[c*x^n])/(n*(2 - p))]^(-2 + p))/(1 - p))}


(* Integrands of the form Csc[a+b*Log[c*x^n]]^p/x where p is an integer *)
{Csc[a + b*Log[c*x^n]]/x, x, 2, -(ArcTanh[Cos[a + b*Log[c*x^n]]]/(b*n))}
{Csc[a + b*Log[c*x^n]]^2/x, x, 2, -(Cot[a + b*Log[c*x^n]]/(b*n))}
{Csc[a + b*Log[c*x^n]]^3/x, x, 3, -(ArcTanh[Cos[a + b*Log[c*x^n]]]/(2*b*n)) - (Cot[a + b*Log[c*x^n]]*Csc[a + b*Log[c*x^n]])/(2*b*n)}
{Csc[a + b*Log[c*x^n]]^4/x, x, 3, -(Cot[a + b*Log[c*x^n]]/(b*n)) - Cot[a + b*Log[c*x^n]]^3/(3*b*n)}
{Csc[a + b*Log[c*x^n]]^5/x, x, 4, -((3*ArcTanh[Cos[a + b*Log[c*x^n]]])/(8*b*n)) - (3*Cot[a + b*Log[c*x^n]]*Csc[a + b*Log[c*x^n]])/(8*b*n) - (Cot[a + b*Log[c*x^n]]*Csc[a + b*Log[c*x^n]]^3)/(4*b*n)}


(* Integrands of the form Csc[a+b*Log[c*x^n]]^p/x where p is a half-integer *)
{Csc[a + b*Log[c*x^n]]^(5/2)/x, x, 4, -((2*Cos[a + b*Log[c*x^n]]*Csc[a + b*Log[c*x^n]]^(3/2))/(3*b*n)) - (2*Sqrt[Csc[a + b*Log[c*x^n]]]*EllipticF[Pi/4 + (1/2)*(-a - b*Log[c*x^n]), 2]*Sqrt[Sin[a + b*Log[c*x^n]]])/(3*b*n)}
{Csc[a + b*Log[c*x^n]]^(3/2)/x, x, 4, -((2*Cos[a + b*Log[c*x^n]]*Sqrt[Csc[a + b*Log[c*x^n]]])/(b*n)) + (2*Sqrt[Csc[a + b*Log[c*x^n]]]*EllipticE[Pi/4 + (1/2)*(-a - b*Log[c*x^n]), 2]*Sqrt[Sin[a + b*Log[c*x^n]]])/(b*n)}
{Sqrt[Csc[a + b*Log[c*x^n]]]/x, x, 3, -((2*Sqrt[Csc[a + b*Log[c*x^n]]]*EllipticF[Pi/4 + (1/2)*(-a - b*Log[c*x^n]), 2]*Sqrt[Sin[a + b*Log[c*x^n]]])/(b*n))}
{1/(x*Sqrt[Csc[a + b*Log[c*x^n]]]), x, 3, -((2*Sqrt[Csc[a + b*Log[c*x^n]]]*EllipticE[Pi/4 + (1/2)*(-a - b*Log[c*x^n]), 2]*Sqrt[Sin[a + b*Log[c*x^n]]])/(b*n))}
{1/(x*Csc[a + b*Log[c*x^n]]^(3/2)), x, 4, -((2*Cos[a + b*Log[c*x^n]])/(3*b*n*Sqrt[Csc[a + b*Log[c*x^n]]])) - (2*Sqrt[Csc[a + b*Log[c*x^n]]]*EllipticF[Pi/4 + (1/2)*(-a - b*Log[c*x^n]), 2]*Sqrt[Sin[a + b*Log[c*x^n]]])/(3*b*n)}
{1/(x*Csc[a + b*Log[c*x^n]]^(5/2)), x, 4, -((2*Cos[a + b*Log[c*x^n]])/(5*b*n*Csc[a + b*Log[c*x^n]]^(3/2))) - (6*Sqrt[Csc[a + b*Log[c*x^n]]]*EllipticE[Pi/4 + (1/2)*(-a - b*Log[c*x^n]), 2]*Sqrt[Sin[a + b*Log[c*x^n]]])/(5*b*n)}


(* ::Subsection::Closed:: *)
(*Miscellaneous integrands involving one cosecant*)


(* Integrands of the form x^m*Csc[x]^n where m is an integer and n is a half-integer *)
{x/Csc[x]^(3/2) - x*Sqrt[Csc[x]]/3, x, 2, 4/(9*Csc[x]^(3/2)) - (2*x*Cos[x])/(3*Sqrt[Csc[x]])}
{x/Csc[x]^(5/2) - 3*x/(5*Sqrt[Csc[x]]), x, 2, 4/(25*Csc[x]^(5/2)) - (2*x*Cos[x])/(5*Csc[x]^(3/2))}
{x/Csc[x]^(7/2) - (5/21)*x*Sqrt[Csc[x]], x, 3, 4/(49*Csc[x]^(7/2)) - (2*x*Cos[x])/(7*Csc[x]^(5/2)) + 20/(63*Csc[x]^(3/2)) - (10*x*Cos[x])/(21*Sqrt[Csc[x]])}
{x^2/Csc[x]^(3/2) - (1/3)*x^2*Sqrt[Csc[x]], x, 5, (8*x)/(9*Csc[x]^(3/2)) + (16*Cos[x])/(27*Sqrt[Csc[x]]) - (2*x^2*Cos[x])/(3*Sqrt[Csc[x]]) + (16/27)*Sqrt[Csc[x]]*EllipticF[Pi/4 - x/2, 2]*Sqrt[Sin[x]]}


{Csc[Sqrt[x]]^3/Sqrt[x], x, 3, -ArcTanh[Cos[Sqrt[x]]] - Cot[Sqrt[x]]*Csc[Sqrt[x]]}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (a+b Csc[c+d x])^n*)


(* Integrands of the form Cos[x]^m/(a+b*Csc[x]) where m is a positive integer *)
{Cos[x]/(a + b*Csc[x]), x, 4, -((b*Log[b + a*Sin[x]])/a^2) + Sin[x]/a}
{Cos[x]^2/(a + b*Csc[x]), x, 5, x/(2*a) - (b^2*x)/a^3 + (2*b*Sqrt[a^2 - b^2]*ArcTanh[(a + b*Tan[x/2])/Sqrt[a^2 - b^2]])/a^3 - (b*Cos[x])/a^2 + (Cos[x]*Sin[x])/(2*a)}
{Cos[x]^3/(a + b*Csc[x]), x, 5, -((b*(a^2 - b^2)*Log[b + a*Sin[x]])/a^4) + ((a^2 - b^2)*Sin[x])/a^3 + (b*Sin[x]^2)/(2*a^2) - Sin[x]^3/(3*a)}
{Cos[x]^4/(a + b*Csc[x]), x, 9, -((5*x)/(8*a)) + (b^2*x)/(2*a^3) + ((a^2 - b^2)^2*x)/a^5 + (2*b*(a^2 - b^2)^(3/2)*ArcTanh[(a + b*Tan[x/2])/Sqrt[a^2 - b^2]])/a^5 - (b*Cos[x])/a^2 + (b^3*Cos[x])/a^4 - (b*Cos[x]^3)/(3*a^2) + (5*Cos[x]*Sin[x])/(8*a) - (b^2*Cos[x]*Sin[x])/(2*a^3) - (Cos[x]*Sin[x]^3)/(4*a)}

{Cos[x]/(a + a*Csc[x]), x, 4, -(Log[1 + Sin[x]]/a) + Sin[x]/a}
{Cos[x]^2/(a + a*Csc[x]), x, 4, -(x/(2*a)) - Cos[x]/a + (Cos[x]*Sin[x])/(2*a)}
{Cos[x]^3/(a + a*Csc[x]), x, 2, Sin[x]^2/(2*a) - Sin[x]^3/(3*a)}
{Cos[x]^4/(a + a*Csc[x]), x, 8, -(x/(8*a)) - Cos[x]^3/(3*a) + (Cos[x]*Sin[x])/(8*a) - (Cos[x]*Sin[x]^3)/(4*a)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Tan[c+d x]^m (a+b Csc[c+d x])^n*)


(* Integrands of the form Tan[x]^m/(a+b*Csc[x]) where m is a positive integer *)
{Tan[x]/(a + b*Csc[x]), x, 7, -(Log[1 - Sin[x]]/(2*(a + b))) - Log[1 + Sin[x]]/(2*(a - b)) + (b^2*Log[b + a*Sin[x]])/(a*(a^2 - b^2))}
{Tan[x]^2/(a + b*Csc[x]), x, 5, -(x/a) + (2*b^3*ArcTanh[(a + b*Tan[x/2])/Sqrt[a^2 - b^2]])/(a*(a^2 - b^2)^(3/2)) + Cos[x]/(2*(a + b)*(1 - Sin[x])) - Cos[x]/(2*(a - b)*(1 + Sin[x]))}
{Tan[x]^3/(a + b*Csc[x]), x, 8, ((2*a + 3*b)*Log[1 - Sin[x]])/(4*(a + b)^2) + ((2*a - 3*b)*Log[1 + Sin[x]])/(4*(a - b)^2) + (b^4*Log[b + a*Sin[x]])/(a*(a^2 - b^2)^2) + 1/(4*(a + b)*(1 - Sin[x])) + 1/(4*(a - b)*(1 + Sin[x]))}
{Tan[x]^4/(a + b*Csc[x]), x, 9, x/a + (2*b^5*ArcTanh[(a + b*Tan[x/2])/Sqrt[a^2 - b^2]])/(a*(a^2 - b^2)^(5/2)) + Cos[x]/(12*(a + b)*(1 - Sin[x])^2) + Cos[x]/(12*(a + b)*(1 - Sin[x])) - ((3*a + 4*b)*Cos[x])/(4*(a + b)^2*(1 - Sin[x])) - Cos[x]/(12*(a - b)*(1 + Sin[x])^2) + ((3*a - 4*b)*Cos[x])/(4*(a - b)^2*(1 + Sin[x])) - Cos[x]/(12*(a - b)*(1 + Sin[x]))}

{Tan[x]/(a + a*Csc[x]), x, 7, -(Log[1 - Sin[x]]/(4*a)) - (3*Log[1 + Sin[x]])/(4*a) - 1/(2*a*(1 + Sin[x]))}
{Tan[x]^2/(a + a*Csc[x]), x, 6, -(x/a) + Cos[x]/(4*a*(1 - Sin[x])) + Cos[x]/(6*a*(1 + Sin[x])^2) - (13*Cos[x])/(12*a*(1 + Sin[x]))}
{Tan[x]^3/(a + a*Csc[x]), x, 9, (5*Log[1 - Sin[x]])/(16*a) + (11*Log[1 + Sin[x]])/(16*a) + 1/(8*a*(1 - Sin[x])) - 1/(8*a*(1 + Sin[x])^2) + 3/(4*a*(1 + Sin[x]))}
{Tan[x]^4/(a + a*Csc[x]), x, 11, x/a + Cos[x]/(24*a*(1 - Sin[x])^2) - (19*Cos[x])/(48*a*(1 - Sin[x])) + Cos[x]/(20*a*(1 + Sin[x])^3) - (3*Cos[x])/(10*a*(1 + Sin[x])^2) + (91*Cos[x])/(80*a*(1 + Sin[x]))}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cot[c+d x]^m (a+b Csc[c+d x])^n*)


(* Integrands of the form Cot[x]^m/(a+b*Csc[x]) where m is a positive integer *)
{Cot[x]/(a + b*Csc[x]), x, 2, Log[b + a*Sin[x]]/a}
{Cot[x]^2/(a + b*Csc[x]), x, 4, -(x/a) - ArcTanh[Cos[x]]/b + (2*Sqrt[a^2 - b^2]*ArcTanh[(a + b*Tan[x/2])/Sqrt[a^2 - b^2]])/(a*b)}
{Cot[x]^3/(a + b*Csc[x]), x, 5, -(Csc[x]/b) - (a*Log[Sin[x]])/b^2 + ((a^2 - b^2)*Log[b + a*Sin[x]])/(a*b^2)}
{Cot[x]^4/(a + b*Csc[x]), x, 7, x/a - (a^2*ArcTanh[Cos[x]])/b^3 + (3*ArcTanh[Cos[x]])/(2*b) + (2*(a^2 - b^2)^(3/2)*ArcTanh[(a + b*Tan[x/2])/Sqrt[a^2 - b^2]])/(a*b^3) + (a*Cot[x])/b^2 - (Cot[x]*Csc[x])/(2*b)}

{Cot[x]/(a + a*Csc[x]), x, 3, Log[1 + Sin[x]]/a}
{Cot[x]^2/(a + a*Csc[x]), x, 3, -(x/a) - ArcTanh[Cos[x]]/a}
{Cot[x]^3/(a + a*Csc[x]), x, 3, -(Csc[x]/a) - Log[Sin[x]]/a}
{Cot[x]^4/(a + a*Csc[x]), x, 6, x/a + ArcTanh[Cos[x]]/(2*a) + Cot[x]/a - (Cot[x]*Csc[x])/(2*a)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Sec[c+d x]^m (a+b Csc[c+d x])^n*)


(* Integrands of the form Sec[x]^m/(a+b*Csc[x]) where m is a positive integer *)
{Sec[x]/(a + b*Csc[x]), x, 7, -(Log[1 - Sin[x]]/(2*(a + b))) + Log[1 + Sin[x]]/(2*(a - b)) - (b*Log[b + a*Sin[x]])/(a^2 - b^2)}
{Sec[x]^2/(a + b*Csc[x]), x, 5, (2*a*b*ArcTanh[(a + b*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(3/2) + Cos[x]/(2*(a + b)*(1 - Sin[x])) - Cos[x]/(2*(a - b)*(1 + Sin[x]))}
{Sec[x]^3/(a + b*Csc[x]), x, 8, -((a*Log[1 - Sin[x]])/(4*(a + b)^2)) + (a*Log[1 + Sin[x]])/(4*(a - b)^2) - (a^2*b*Log[b + a*Sin[x]])/(a^2 - b^2)^2 + 1/(4*(a + b)*(1 - Sin[x])) - 1/(4*(a - b)*(1 + Sin[x]))}
{Sec[x]^4/(a + b*Csc[x]), x, 9, (2*a^3*b*ArcTanh[(a + b*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(5/2) + Cos[x]/(12*(a + b)*(1 - Sin[x])^2) + (a*Cos[x])/(4*(a + b)^2*(1 - Sin[x])) + Cos[x]/(12*(a + b)*(1 - Sin[x])) - Cos[x]/(12*(a - b)*(1 + Sin[x])^2) - (a*Cos[x])/(4*(a - b)^2*(1 + Sin[x])) - Cos[x]/(12*(a - b)*(1 + Sin[x]))}

{Sec[x]/(a + a*Csc[x]), x, 6, ArcTanh[Sin[x]]/(2*a) + 1/(2*a*(1 + Sin[x]))}
{Sec[x]^2/(a + a*Csc[x]), x, 6, Cos[x]/(4*a*(1 - Sin[x])) + Cos[x]/(6*a*(1 + Sin[x])^2) - Cos[x]/(12*a*(1 + Sin[x]))}
{Sec[x]^3/(a + a*Csc[x]), x, 7, ArcTanh[Sin[x]]/(8*a) + 1/(8*a*(1 - Sin[x])) + 1/(8*a*(1 + Sin[x])^2)}
{Sec[x]^4/(a + a*Csc[x]), x, 9, Cos[x]/(24*a*(1 - Sin[x])^2) + (5*Cos[x])/(48*a*(1 - Sin[x])) + Cos[x]/(20*a*(1 + Sin[x])^3) + Cos[x]/(30*a*(1 + Sin[x])^2) - (7*Cos[x])/(240*a*(1 + Sin[x]))}
