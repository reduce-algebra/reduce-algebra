(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Secants*)


(* ::Subsection::Closed:: *)
(*(c+d x)^m Sec[a+b x]^n*)


(* Integrands of the form x^m*Sec[a+b*x]^n where m and n are integers *)
{x*Sec[a + b*x], x, 4, -((2*I*x*ArcTan[E^(I*a + I*b*x)])/b) + (I*PolyLog[2, (-I)*E^(I*a + I*b*x)])/b^2 - (I*PolyLog[2, I*E^(I*a + I*b*x)])/b^2}
{x^2*Sec[a + b*x], x, 6, -((2*I*x^2*ArcTan[E^(I*a + I*b*x)])/b) + (2*I*x*PolyLog[2, (-I)*E^(I*a + I*b*x)])/b^2 - (2*I*x*PolyLog[2, I*E^(I*a + I*b*x)])/b^2 - (2*PolyLog[3, (-I)*E^(I*a + I*b*x)])/b^3 + (2*PolyLog[3, I*E^(I*a + I*b*x)])/b^3}
{x^3*Sec[a + b*x], x, 8, -((2*I*x^3*ArcTan[E^(I*a + I*b*x)])/b) + (3*I*x^2*PolyLog[2, (-I)*E^(I*a + I*b*x)])/b^2 - (3*I*x^2*PolyLog[2, I*E^(I*a + I*b*x)])/b^2 - (6*x*PolyLog[3, (-I)*E^(I*a + I*b*x)])/b^3 + (6*x*PolyLog[3, I*E^(I*a + I*b*x)])/b^3 - (6*I*PolyLog[4, (-I)*E^(I*a + I*b*x)])/b^4 + (6*I*PolyLog[4, I*E^(I*a + I*b*x)])/b^4}
{1/x*Sec[a + b*x], x, 0, Int[Sec[a + b*x]/x, x]}

{x*Sec[a + b*x]^2, x, 2, Log[Cos[a + b*x]]/b^2 + (x*Tan[a + b*x])/b}
{x^2*Sec[a + b*x]^2, x, 5, -((I*x^2)/b) + (2*x*Log[1 + E^(2*I*a + 2*I*b*x)])/b^2 - (I*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/b^3 + (x^2*Tan[a + b*x])/b}
{x^3*Sec[a + b*x]^2, x, 6, -((I*x^3)/b) + (3*x^2*Log[1 + E^(2*I*a + 2*I*b*x)])/b^2 - (3*I*x*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/b^3 + (3*PolyLog[3, -E^(2*I*a + 2*I*b*x)])/(2*b^4) + (x^3*Tan[a + b*x])/b}
{1/x*Sec[a + b*x]^2, x, 0, Int[Sec[a + b*x]^2/x, x]}

{x*Sec[a + b*x]^3, x, 5, -((I*x*ArcTan[E^(I*a + I*b*x)])/b) + (I*PolyLog[2, (-I)*E^(I*a + I*b*x)])/(2*b^2) - (I*PolyLog[2, I*E^(I*a + I*b*x)])/(2*b^2) - Sec[a + b*x]/(2*b^2) + (x*Sec[a + b*x]*Tan[a + b*x])/(2*b)}
{x^2*Sec[a + b*x]^3, x, 8, -((I*x^2*ArcTan[E^(I*a + I*b*x)])/b) + ArcTanh[Sin[a + b*x]]/b^3 + (I*x*PolyLog[2, (-I)*E^(I*a + I*b*x)])/b^2 - (I*x*PolyLog[2, I*E^(I*a + I*b*x)])/b^2 - PolyLog[3, (-I)*E^(I*a + I*b*x)]/b^3 + PolyLog[3, I*E^(I*a + I*b*x)]/b^3 - (x*Sec[a + b*x])/b^2 + (x^2*Sec[a + b*x]*Tan[a + b*x])/(2*b)}
(* {x^3*Sec[a + b*x]^3, x, 13, -((6*I*x*ArcTan[E^(I*a + I*b*x)])/b^3) - (I*x^3*ArcTan[E^(I*a + I*b*x)])/b + (3*I*(2 + b^2*x^2)*PolyLog[2, (-I)*E^(I*a + I*b*x)])/(2*b^4) - (3*I*(2 + b^2*x^2)*PolyLog[2, I*E^(I*a + I*b*x)])/(2*b^4) - (3*x*PolyLog[3, (-I)*E^(I*a + I*b*x)])/b^3 + (3*x*PolyLog[3, I*E^(I*a + I*b*x)])/b^3 - (3*I*PolyLog[4, (-I)*E^(I*a + I*b*x)])/b^4 + (3*I*PolyLog[4, I*E^(I*a + I*b*x)])/b^4 - (3*x^2*Sec[a + b*x])/(2*b^2) + (x^3*Sec[a + b*x]*Tan[a + b*x])/(2*b)} *)
{1/x*Sec[a + b*x]^3, x, 0, Int[Sec[a + b*x]^3/x, x]}


(* Integrands of the form (c+d*x)^m*Sec[a+b*x]^n where m and n are integers *)
{(c + d*x)*Sec[a + b*x], x, 5, -((2*I*(c + d*x)*ArcTan[E^(I*a + I*b*x)])/b) + (I*d*PolyLog[2, (-I)*E^(I*a + I*b*x)])/b^2 - (I*d*PolyLog[2, I*E^(I*a + I*b*x)])/b^2}
{(c + d*x)^2*Sec[a + b*x], x, 7, -((2*I*(c + d*x)^2*ArcTan[E^(I*a + I*b*x)])/b) + (2*I*d*(c + d*x)*PolyLog[2, (-I)*E^(I*a + I*b*x)])/b^2 - (2*I*d*(c + d*x)*PolyLog[2, I*E^(I*a + I*b*x)])/b^2 - (2*d^2*PolyLog[3, (-I)*E^(I*a + I*b*x)])/b^3 + (2*d^2*PolyLog[3, I*E^(I*a + I*b*x)])/b^3}
{(c + d*x)^3*Sec[a + b*x], x, 9, -((2*I*(c + d*x)^3*ArcTan[E^(I*a + I*b*x)])/b) + (3*I*d*(c + d*x)^2*PolyLog[2, (-I)*E^(I*a + I*b*x)])/b^2 - (3*I*d*(c + d*x)^2*PolyLog[2, I*E^(I*a + I*b*x)])/b^2 - (6*d^2*(c + d*x)*PolyLog[3, (-I)*E^(I*a + I*b*x)])/b^3 + (6*d^2*(c + d*x)*PolyLog[3, I*E^(I*a + I*b*x)])/b^3 - (6*I*d^3*PolyLog[4, (-I)*E^(I*a + I*b*x)])/b^4 + (6*I*d^3*PolyLog[4, I*E^(I*a + I*b*x)])/b^4}

{(c + d*x)*Sec[a + b*x]^2, x, 3, (d*Log[Cos[a + b*x]])/b^2 + ((c + d*x)*Tan[a + b*x])/b}
{(c + d*x)^2*Sec[a + b*x]^2, x, 6, -((I*(c + d*x)^2)/b) + (2*d*(c + d*x)*Log[1 + E^(2*I*a + 2*I*b*x)])/b^2 - (I*d^2*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/b^3 + ((c + d*x)^2*Tan[a + b*x])/b}
{(c + d*x)^3*Sec[a + b*x]^2, x, 7, -((I*(c + d*x)^3)/b) + (3*d*(c + d*x)^2*Log[1 + E^(2*I*a + 2*I*b*x)])/b^2 - (3*I*d^2*(c + d*x)*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/b^3 + (3*d^3*PolyLog[3, -E^(2*I*a + 2*I*b*x)])/(2*b^4) + ((c + d*x)^3*Tan[a + b*x])/b}

{(c + d*x)*Sec[a + b*x]^3, x, 6, -((I*(c + d*x)*ArcTan[E^(I*a + I*b*x)])/b) + (I*d*PolyLog[2, (-I)*E^(I*a + I*b*x)])/(2*b^2) - (I*d*PolyLog[2, I*E^(I*a + I*b*x)])/(2*b^2) - (d*Sec[a + b*x])/(2*b^2) + ((c + d*x)*Sec[a + b*x]*Tan[a + b*x])/(2*b)}
{(c + d*x)^2*Sec[a + b*x]^3, x, 9, -((I*(c + d*x)^2*ArcTan[E^(I*a + I*b*x)])/b) + (d^2*ArcTanh[Sin[a + b*x]])/b^3 + (I*d*(c + d*x)*PolyLog[2, (-I)*E^(I*a + I*b*x)])/b^2 - (I*d*(c + d*x)*PolyLog[2, I*E^(I*a + I*b*x)])/b^2 - (d^2*PolyLog[3, (-I)*E^(I*a + I*b*x)])/b^3 + (d^2*PolyLog[3, I*E^(I*a + I*b*x)])/b^3 - (d*(c + d*x)*Sec[a + b*x])/b^2 + ((c + d*x)^2*Sec[a + b*x]*Tan[a + b*x])/(2*b)}
(* {(c + d*x)^3*Sec[a + b*x]^3, x, 14, -((6*I*d^2*(c + d*x)*ArcTan[E^(I*a + I*b*x)])/b^3) - (I*(c + d*x)^3*ArcTan[E^(I*a + I*b*x)])/b + (3*I*d*(2*d^2 + b^2*(c + d*x)^2)*PolyLog[2, (-I)*E^(I*a + I*b*x)])/(2*b^4) - (3*I*d*(2*d^2 + b^2*(c + d*x)^2)*PolyLog[2, I*E^(I*a + I*b*x)])/(2*b^4) - (3*d^2*(c + d*x)*PolyLog[3, (-I)*E^(I*a + I*b*x)])/b^3 + (3*d^2*(c + d*x)*PolyLog[3, I*E^(I*a + I*b*x)])/b^3 - (3*I*d^3*PolyLog[4, (-I)*E^(I*a + I*b*x)])/b^4 + (3*I*d^3*PolyLog[4, I*E^(I*a + I*b*x)])/b^4 - (3*d*(c + d*x)^2*Sec[a + b*x])/(2*b^2) + ((c + d*x)^3*Sec[a + b*x]*Tan[a + b*x])/(2*b)} *)


{x*Sec[a + b*x^2]^7, x, 5, (5*ArcTanh[Sin[a + b*x^2]])/(32*b) + (5*Sec[a + b*x^2]*Tan[a + b*x^2])/(32*b) + (5*Sec[a + b*x^2]^3*Tan[a + b*x^2])/(48*b) + (Sec[a + b*x^2]^5*Tan[a + b*x^2])/(12*b)}


(* ::Subsection::Closed:: *)
(*(a Sec[a+b x]^n)^m*)


{(Sec[x]^2)^(5/2), x, 4, (3/8)*ArcSinh[Tan[x]] + (3/8)*Sqrt[Sec[x]^2]*Tan[x] + (1/4)*(Sec[x]^2)^(3/2)*Tan[x]}
{(Sec[x]^2)^(3/2), x, 3, (1/2)*ArcSinh[Tan[x]] + (1/2)*Sqrt[Sec[x]^2]*Tan[x]}
{(Sec[x]^2)^(1/2), x, 2, ArcSinh[Tan[x]]}
{1/(Sec[x]^2)^(1/2), x, 2, Tan[x]/Sqrt[Sec[x]^2]}
{1/(Sec[x]^2)^(3/2), x, 3, ((3 - Sin[x]^2)*Tan[x])/(3*Sqrt[Sec[x]^2])}
{1/(Sec[x]^2)^(5/2), x, 3, ((15 - 10*Sin[x]^2 + 3*Sin[x]^4)*Tan[x])/(15*Sqrt[Sec[x]^2])}
{1/(Sec[x]^2)^(7/2), x, 3, ((35*Cos[x]^2 + 21*Sin[x]^4 - 5*Sin[x]^6)*Tan[x])/(35*Sqrt[Sec[x]^2])}


{(a*Sec[x]^2)^(5/2), x, 4, (1/8)*a^2*Cos[x]*Sqrt[a*Sec[x]^2]*(3*ArcTanh[Sin[x]] + 3*Sec[x]*Tan[x] + 2*Sec[x]^3*Tan[x])}
{(a*Sec[x]^2)^(3/2), x, 3, (1/2)*a*Cos[x]*Sqrt[a*Sec[x]^2]*(ArcTanh[Sin[x]] + Sec[x]*Tan[x])}
{(a*Sec[x]^2)^(1/2), x, 2, ArcTanh[Sin[x]]*Cos[x]*Sqrt[a*Sec[x]^2]}
{1/(a*Sec[x]^2)^(1/2), x, 2, Tan[x]/Sqrt[a*Sec[x]^2]}
{1/(a*Sec[x]^2)^(3/2), x, 3, ((3 - Sin[x]^2)*Tan[x])/(3*a*Sqrt[a*Sec[x]^2])}
{1/(a*Sec[x]^2)^(5/2), x, 3, ((15 - 10*Sin[x]^2 + 3*Sin[x]^4)*Tan[x])/(15*a^2*Sqrt[a*Sec[x]^2])}
{1/(a*Sec[x]^2)^(7/2), x, 3, ((35*Cos[x]^2 + 21*Sin[x]^4 - 5*Sin[x]^6)*Tan[x])/(35*a^3*Sqrt[a*Sec[x]^2])}


{(a*Sec[x]^3)^(5/2), x, 7, (-(2/585))*a^2*Cos[x]*Sqrt[a*Sec[x]^3]*(231*Sqrt[Cos[x]]*EllipticE[x/2, 2] - 231*Sin[x] - 77*Sec[x]*Tan[x] - 55*Sec[x]^3*Tan[x] - 45*Sec[x]^5*Tan[x])}
{(a*Sec[x]^3)^(3/2), x, 5, (2/21)*a*Cos[x]*Sqrt[a*Sec[x]^3]*(5*Sqrt[Cos[x]]*EllipticF[x/2, 2] + 5*Tan[x] + 3*Sec[x]^2*Tan[x])}
{(a*Sec[x]^3)^(1/2), x, 4, -2*Cos[x]*Sqrt[a*Sec[x]^3]*(Sqrt[Cos[x]]*EllipticE[x/2, 2] - Sin[x])}
{1/(a*Sec[x]^3)^(1/2), x, 4, (2*Sec[x]*(EllipticF[x/2, 2]/Sqrt[Cos[x]] + Sin[x]))/(3*Sqrt[a*Sec[x]^3])}
{1/(a*Sec[x]^3)^(3/2), x, 5, (2*Cos[x]^2*(5*Sin[x] + 7*Sec[x]^2*((3*EllipticE[x/2, 2])/Cos[x]^(3/2) + Sin[x])))/(45*a*Sqrt[a*Sec[x]^3])}
{1/(a*Sec[x]^3)^(5/2), x, 7, (2*Cos[x]^5*(77*Sin[x] + 13*Sec[x]^2*(7*Sin[x] + 3*Sec[x]^2*(3*Sin[x] + 5*Sec[x]^2*(EllipticF[x/2, 2]/Sqrt[Cos[x]] + Sin[x])))))/(1155*a^2*Sqrt[a*Sec[x]^3])}


{(a*Sec[x]^4)^(7/2), x, 4, (a^3*Cos[x]*Sqrt[a*Sec[x]^4]*Sin[x]*(3003 + 6006*Tan[x]^2 + 9009*Tan[x]^4 + 8580*Tan[x]^6 + 5005*Tan[x]^8 + 1638*Tan[x]^10 + 231*Tan[x]^12))/3003}
{(a*Sec[x]^4)^(5/2), x, 4, (1/315)*a^2*Cos[x]*Sqrt[a*Sec[x]^4]*Sin[x]*(315 + 420*Tan[x]^2 + 378*Tan[x]^4 + 180*Tan[x]^6 + 35*Tan[x]^8)}
{(a*Sec[x]^4)^(3/2), x, 4, (1/15)*a*Cos[x]*Sqrt[a*Sec[x]^4]*Sin[x]*(15 + 10*Tan[x]^2 + 3*Tan[x]^4)}
{(a*Sec[x]^4)^(1/2), x, 2, Cos[x]*Sqrt[a*Sec[x]^4]*Sin[x]}
{1/(a*Sec[x]^4)^(1/2), x, 2, (Sec[x]^2*(x + Cos[x]*Sin[x]))/(2*Sqrt[a*Sec[x]^4])}
{1/(a*Sec[x]^4)^(3/2), x, 4, (Sec[x]^2*(15*x + 15*Cos[x]*Sin[x] + 10*Cos[x]^3*Sin[x] + 8*Cos[x]^5*Sin[x]))/(48*a*Sqrt[a*Sec[x]^4])}
{1/(a*Sec[x]^4)^(5/2), x, 6, (Sec[x]^2*(315*x + 315*Cos[x]*Sin[x] + 210*Cos[x]^3*Sin[x] + 168*Cos[x]^5*Sin[x] + 144*Cos[x]^7*Sin[x] + 128*Cos[x]^9*Sin[x]))/(1280*a^2*Sqrt[a*Sec[x]^4])}


(* ::Subsection::Closed:: *)
(*(a+b Sec[c+d x]^n)^m*)


(* Integrands of the form (a+b*Sec[x]^2)^m where m is a half-integer *)
{Sqrt[1 + Sec[x]^2], x, 4, ArcSinh[Tan[x]/Sqrt[2]] + ArcTan[Tan[x]/Sqrt[2 + Tan[x]^2]]}
{Sqrt[1 - Sec[x]^2], x, 3, (-Cot[x])*Log[Cos[x]]*Sqrt[-Tan[x]^2]}
{Sqrt[-1 + Sec[x]^2], x, 3, -(Cot[x]*Log[Cos[x]]*Sqrt[Tan[x]^2])}
{Sqrt[-1 - Sec[x]^2], x, 4, -ArcTan[Tan[x]/Sqrt[-2 - Tan[x]^2]] - ArcTanh[Tan[x]/Sqrt[-2 - Tan[x]^2]]}
{Sqrt[a + b*Sec[x]^2], x, 4, Sqrt[a]*ArcTan[(Sqrt[a]*Tan[x])/Sqrt[a + b*Sec[x]^2]] + Sqrt[b]*ArcTanh[(Sqrt[b]*Tan[x])/Sqrt[a + b*Sec[x]^2]]}

{1/Sqrt[1 + Sec[x]^2], x, 2, ArcTan[Tan[x]/Sqrt[2 + Tan[x]^2]]}
{1/Sqrt[1 - Sec[x]^2], x, 3, (Log[Sin[x]]*Tan[x])/Sqrt[-Tan[x]^2]}
{1/Sqrt[-1 + Sec[x]^2], x, 3, (Log[Sin[x]]*Tan[x])/Sqrt[Tan[x]^2]}
{1/Sqrt[-1 - Sec[x]^2], x, 2, ArcTanh[Tan[x]/Sqrt[-2 - Tan[x]^2]]}
{1/Sqrt[a + b*Sec[x]^2], x, 2, ArcTan[(Sqrt[a]*Tan[x])/Sqrt[a + b*Sec[x]^2]]/Sqrt[a]}

{(1 + Sec[x]^2)^(3/2), x, 7, 2*ArcSinh[Tan[x]/Sqrt[2]] + ArcTan[Tan[x]/Sqrt[2 + Tan[x]^2]] + (1/2)*Tan[x]*Sqrt[2 + Tan[x]^2]}
{(1 - Sec[x]^2)^(3/2), x, 4, (-Cot[x])*Log[Cos[x]]*Sqrt[-Tan[x]^2] - (1/2)*Tan[x]*Sqrt[-Tan[x]^2]}
{(-1 + Sec[x]^2)^(3/2), x, 4, Cot[x]*Log[Cos[x]]*Sqrt[Tan[x]^2] + (1/2)*Cot[x]*(Tan[x]^2)^(3/2)}
{(-1 - Sec[x]^2)^(3/2), x, 7, 2*ArcTan[Tan[x]/Sqrt[-2 - Tan[x]^2]] + ArcTanh[Tan[x]/Sqrt[-2 - Tan[x]^2]] - (1/2)*Tan[x]*Sqrt[-2 - Tan[x]^2]}
{(a + b*Sec[x]^2)^(3/2), x, 7, a^(3/2)*ArcTan[(Sqrt[a]*Tan[x])/Sqrt[a + b*Sec[x]^2]] + (3/2)*a*Sqrt[b]*ArcTanh[(Sqrt[b]*Tan[x])/Sqrt[a + b*Sec[x]^2]] + (1/2)*b^(3/2)*ArcTanh[(Sqrt[b]*Tan[x])/Sqrt[a + b*Sec[x]^2]] + (1/2)*b*Sqrt[a + b*Sec[x]^2]*Tan[x]}


(* ::Subsection::Closed:: *)
(*x^m Sec[a+b Log[c x^n]]^p*)


{Sec[a + b*Log[c*x^n]], x, 0, Int[Sec[a + b*Log[c*x^n]], x]}
{Sec[a + b*Log[c*x^n]]^2, x, 0, Int[Sec[a + b*Log[c*x^n]]^2, x]}
{Sec[a + b*Log[c*x^n]]^3, x, 1, ((1 + b^2*n^2)*Int[Sec[a + b*Log[c*x^n]], x])/(2*b^2*n^2) - (x*Sec[a + b*Log[c*x^n]])/(2*b^2*n^2) + (x*Sec[a + b*Log[c*x^n]]*Tan[a + b*Log[c*x^n]])/(2*b*n)}
{Sec[a + b*Log[c*x^n]]^4, x, 1, ((1 + 4*b^2*n^2)*Int[Sec[a + b*Log[c*x^n]]^2, x])/(6*b^2*n^2) - (x*Sec[a + b*Log[c*x^n]]^2)/(6*b^2*n^2) + (x*Sec[a + b*Log[c*x^n]]^2*Tan[a + b*Log[c*x^n]])/(3*b*n)}

{2*b^2*n^2*Sec[a + b*Log[c*x^n]]^3 - (1 + b^2*n^2)*Sec[a + b*Log[c*x^n]], x, 2, (-x)*Sec[a + b*Log[c*x^n]] + b*n*x*Sec[a + b*Log[c*x^n]]*Tan[a + b*Log[c*x^n]]}


{Sec[a + 2*Log[c*x^(I/2)]]^3, x, 1, (-(1/2))*I*x*Sec[a + 2*Log[c*x^(I/2)]]*(I + Tan[a + 2*Log[c*x^(I/2)]])}
{Sec[a + 2*Log[c/x^(I/2)]]^3, x, 1, (-(1/2))*I*x*Sec[a + 2*Log[c/x^(I/2)]]*(I - Tan[a + 2*Log[c/x^(I/2)]])}
{Sec[a + I/(n*(-2 + p))*Log[c*x^n]]^p, x, 1, -((I*(2 - p)*x*Sec[a - (I*Log[c*x^n])/(n*(2 - p))]^(-2 + p)*(I + Tan[a - (I*Log[c*x^n])/(n*(2 - p))]))/(1 - p))}
{Sec[a - I/(n*(-2 + p))*Log[c*x^n]]^p, x, 1, -((I*(2 - p)*x*Sec[a + (I*Log[c*x^n])/(n*(2 - p))]^(-2 + p)*(I - Tan[a + (I*Log[c*x^n])/(n*(2 - p))]))/(1 - p))}


(* Integrands of the form Sec[a+b*Log[c*x^n]]^p/x where p is an integer *)
{Sec[a + b*Log[c*x^n]]/x, x, 2, ArcTanh[Sin[a + b*Log[c*x^n]]]/(b*n)}
{Sec[a + b*Log[c*x^n]]^2/x, x, 2, Tan[a + b*Log[c*x^n]]/(b*n)}
{Sec[a + b*Log[c*x^n]]^3/x, x, 3, ArcTanh[Sin[a + b*Log[c*x^n]]]/(2*b*n) + (Sec[a + b*Log[c*x^n]]*Tan[a + b*Log[c*x^n]])/(2*b*n)}
{Sec[a + b*Log[c*x^n]]^4/x, x, 3, Tan[a + b*Log[c*x^n]]/(b*n) + Tan[a + b*Log[c*x^n]]^3/(3*b*n)}
{Sec[a + b*Log[c*x^n]]^5/x, x, 4, (3*ArcTanh[Sin[a + b*Log[c*x^n]]])/(8*b*n) + (3*Sec[a + b*Log[c*x^n]]*Tan[a + b*Log[c*x^n]])/(8*b*n) + (Sec[a + b*Log[c*x^n]]^3*Tan[a + b*Log[c*x^n]])/(4*b*n)}


(* Integrands of the form Sec[a+b*Log[c*x^n]]^p/x where p is a half-integer *)
{Sec[a + b*Log[c*x^n]]^(5/2)/x, x, 4, (2*Sqrt[Cos[a + b*Log[c*x^n]]]*EllipticF[(1/2)*(a + b*Log[c*x^n]), 2]*Sqrt[Sec[a + b*Log[c*x^n]]])/(3*b*n) + (2*Sec[a + b*Log[c*x^n]]^(3/2)*Sin[a + b*Log[c*x^n]])/(3*b*n)}
{Sec[a + b*Log[c*x^n]]^(3/2)/x, x, 4, -((2*Sqrt[Cos[a + b*Log[c*x^n]]]*EllipticE[(1/2)*(a + b*Log[c*x^n]), 2]*Sqrt[Sec[a + b*Log[c*x^n]]])/(b*n)) + (2*Sqrt[Sec[a + b*Log[c*x^n]]]*Sin[a + b*Log[c*x^n]])/(b*n)}
{Sqrt[Sec[a + b*Log[c*x^n]]]/x, x, 3, (2*Sqrt[Cos[a + b*Log[c*x^n]]]*EllipticF[(a + b*Log[c*x^n])/2, 2]*Sqrt[Sec[a + b*Log[c*x^n]]])/(b*n)}
{1/(x*Sqrt[Sec[a + b*Log[c*x^n]]]), x, 3, (2*Sqrt[Cos[a + b*Log[c*x^n]]]*EllipticE[(a + b*Log[c*x^n])/2, 2]*Sqrt[Sec[a + b*Log[c*x^n]]])/(b*n)}
{1/(x*Sec[a + b*Log[c*x^n]]^(3/2)), x, 4, (2*Sqrt[Cos[a + b*Log[c*x^n]]]*EllipticF[(1/2)*(a + b*Log[c*x^n]), 2]*Sqrt[Sec[a + b*Log[c*x^n]]])/(3*b*n) + (2*Sin[a + b*Log[c*x^n]])/(3*b*n*Sqrt[Sec[a + b*Log[c*x^n]]])}
{1/(x*Sec[a + b*Log[c*x^n]]^(5/2)), x, 4, (6*Sqrt[Cos[a + b*Log[c*x^n]]]*EllipticE[(1/2)*(a + b*Log[c*x^n]), 2]*Sqrt[Sec[a + b*Log[c*x^n]]])/(5*b*n) + (2*Sin[a + b*Log[c*x^n]])/(5*b*n*Sec[a + b*Log[c*x^n]]^(3/2))}


(* ::Subsection::Closed:: *)
(*Miscellaneous integrands involving secants*)


(* Integrands of the form x^m*Sec[x]^n where m is an integer and n is a half-integer *)
{x/Sec[x]^(3/2) - (1/3)*x*Sqrt[Sec[x]], x, 2, 4/(9*Sec[x]^(3/2)) + (2*x*Sin[x])/(3*Sqrt[Sec[x]])}
{x/Sec[x]^(5/2) - (3/5)*x/Sqrt[Sec[x]], x, 2, 4/(25*Sec[x]^(5/2)) + (2*x*Sin[x])/(5*Sec[x]^(3/2))}
{x/Sec[x]^(7/2) - (5/21)*x*Sqrt[Sec[x]], x, 3, 4/(49*Sec[x]^(7/2)) + 20/(63*Sec[x]^(3/2)) + (2*x*Sin[x])/(7*Sec[x]^(5/2)) + (10*x*Sin[x])/(21*Sqrt[Sec[x]])}
{x^2/Sec[x]^(3/2) - (1/3)*x^2*Sqrt[Sec[x]], x, 5, (8*x)/(9*Sec[x]^(3/2)) - (16/27)*Sqrt[Cos[x]]*EllipticF[x/2, 2]*Sqrt[Sec[x]] - (16*Sin[x])/(27*Sqrt[Sec[x]]) + (2*x^2*Sin[x])/(3*Sqrt[Sec[x]])}


{Sec[Sqrt[x]]/Sqrt[x], x, 2, 2*ArcTanh[Sin[Sqrt[x]]]}


{Sqrt[a + b*Sec[c + d*x]]/(1 + Cos[c + d*x]), x, -6, (((a + b)*Sqrt[(b + a*Cos[c + d*x])/((a + b)*(1 + Cos[c + d*x]))])/(d*Sqrt[a + b*Sec[c + d*x]]*Sqrt[1/(1 + Sec[c + d*x])]))*EllipticE[ArcSin[Tan[(1/2)*(c + d*x)]], (a - b)/(a + b)]}


{Sec[a + b*x]*Sec[2*a + 2*b*x], x, 5, -(ArcTanh[Sin[a + b*x]]/b) + (Sqrt[2]*ArcTanh[Sqrt[2]*Sin[a + b*x]])/b}
{Sec[a + b*x]*Sec[2*(a + b*x)], x, 4, -(ArcTanh[Sin[a + b*x]]/b) + (Sqrt[2]*ArcTanh[Sqrt[2]*Sin[a + b*x]])/b}


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[c+d x]^m (a+b Sec[c+d x])^n*)


(* Integrands of the form Sin[x]^m/(a+b*Sec[x]) where m is a positive integer *)
{Sin[x]/(a + b*Sec[x]), x, 4, -(Cos[x]/a) + (b*Log[b + a*Cos[x]])/a^2}
{Sin[x]^2/(a + b*Sec[x]), x, 5, x/(2*a) - (b^2*x)/a^3 - (2*b*Sqrt[a^2 - b^2]*ArcTanh[((a - b)*Tan[x/2])/Sqrt[a^2 - b^2]])/a^3 + (b*Sin[x])/a^2 - (Cos[x]*Sin[x])/(2*a)}
{Sin[x]^3/(a + b*Sec[x]), x, 5, -(((a^2 - b^2)*Cos[x])/a^3) - (b*Cos[x]^2)/(2*a^2) + Cos[x]^3/(3*a) + (b*(a^2 - b^2)*Log[b + a*Cos[x]])/a^4}
{Sin[x]^4/(a + b*Sec[x]), x, 9, -((5*x)/(8*a)) + (b^2*x)/(2*a^3) + ((a^2 - b^2)^2*x)/a^5 - (2*b*(a^2 - b^2)^(3/2)*ArcTanh[((a - b)*Tan[x/2])/Sqrt[a^2 - b^2]])/a^5 + (b*Sin[x])/a^2 - (b^3*Sin[x])/a^4 - (5*Cos[x]*Sin[x])/(8*a) + (b^2*Cos[x]*Sin[x])/(2*a^3) + (Cos[x]^3*Sin[x])/(4*a) + (b*Sin[x]^3)/(3*a^2)}

{Sin[x]/(a + a*Sec[x]), x, 4, -(Cos[x]/a) + Log[1 + Cos[x]]/a}
{Sin[x]^2/(a + a*Sec[x]), x, 4, -(x/(2*a)) + Sin[x]/a - (Cos[x]*Sin[x])/(2*a)}
{Sin[x]^3/(a + a*Sec[x]), x, 2, -(Cos[x]^2/(2*a)) + Cos[x]^3/(3*a)}
{Sin[x]^4/(a + a*Sec[x]), x, 8, -(x/(8*a)) - (Cos[x]*Sin[x])/(8*a) + (Cos[x]^3*Sin[x])/(4*a) + Sin[x]^3/(3*a)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Tan[c+d x]^m (a+b Sec[c+d x])^n*)


(* Integrands of the form Tan[x]^m/(a+b*Sec[x]) where m is a positive integer *)
{Tan[x]/(a + b*Sec[x]), x, 2, -(Log[b + a*Cos[x]]/a)}
{Tan[x]^2/(a + b*Sec[x]), x, 4, -(x/a) + ArcTanh[Sin[x]]/b - (2*Sqrt[a^2 - b^2]*ArcTanh[((a - b)*Tan[x/2])/Sqrt[a^2 - b^2]])/(a*b)}
{Tan[x]^3/(a + b*Sec[x]), x, 5, (a*Log[Cos[x]])/b^2 - ((a^2 - b^2)*Log[b + a*Cos[x]])/(a*b^2) + Sec[x]/b}
{Tan[x]^4/(a + b*Sec[x]), x, 7, x/a + (a^2*ArcTanh[Sin[x]])/b^3 - (3*ArcTanh[Sin[x]])/(2*b) - (2*(a^2 - b^2)^(3/2)*ArcTanh[((a - b)*Tan[x/2])/Sqrt[a^2 - b^2]])/(a*b^3) - (a*Tan[x])/b^2 + (Sec[x]*Tan[x])/(2*b)}

{Tan[x]/(a + a*Sec[x]), x, 3, -(Log[1 + Cos[x]]/a)}
{Tan[x]^2/(a + a*Sec[x]), x, 3, -(x/a) + ArcTanh[Sin[x]]/a}
{Tan[x]^3/(a + a*Sec[x]), x, 3, Log[Cos[x]]/a + Sec[x]/a}
{Tan[x]^4/(a + a*Sec[x]), x, 6, x/a - ArcTanh[Sin[x]]/(2*a) - Tan[x]/a + (Sec[x]*Tan[x])/(2*a)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cot[c+d x]^m (a+b Sec[c+d x])^n*)


(* Integrands of the form Cot[x]^m/(a+b*Sec[x]) where m is a positive integer *)
{Cot[x]/(a + b*Sec[x]), x, 7, Log[1 - Cos[x]]/(2*(a + b)) + Log[1 + Cos[x]]/(2*(a - b)) - (b^2*Log[b + a*Cos[x]])/(a*(a^2 - b^2))}
{Cot[x]^2/(a + b*Sec[x]), x, 5, -(x/a) - (2*b^3*ArcTanh[((a - b)*Tan[x/2])/Sqrt[a^2 - b^2]])/(a*(a^2 - b^2)^(3/2)) - Sin[x]/(2*(a + b)*(1 - Cos[x])) + Sin[x]/(2*(a - b)*(1 + Cos[x]))}
{Cot[x]^3/(a + b*Sec[x]), x, 8, -(1/(4*(a + b)*(1 - Cos[x]))) - 1/(4*(a - b)*(1 + Cos[x])) - ((2*a + 3*b)*Log[1 - Cos[x]])/(4*(a + b)^2) - ((2*a - 3*b)*Log[1 + Cos[x]])/(4*(a - b)^2) - (b^4*Log[b + a*Cos[x]])/(a*(a^2 - b^2)^2)}
{Cot[x]^4/(a + b*Sec[x]), x, 9, x/a - (2*b^5*ArcTanh[((a - b)*Tan[x/2])/Sqrt[a^2 - b^2]])/(a*(a^2 - b^2)^(5/2)) - Sin[x]/(12*(a + b)*(1 - Cos[x])^2) - Sin[x]/(12*(a + b)*(1 - Cos[x])) + ((3*a + 4*b)*Sin[x])/(4*(a + b)^2*(1 - Cos[x])) + Sin[x]/(12*(a - b)*(1 + Cos[x])^2) - ((3*a - 4*b)*Sin[x])/(4*(a - b)^2*(1 + Cos[x])) + Sin[x]/(12*(a - b)*(1 + Cos[x]))}

{Cot[x]/(a + a*Sec[x]), x, 7, 1/(2*a*(1 + Cos[x])) + Log[1 - Cos[x]]/(4*a) + (3*Log[1 + Cos[x]])/(4*a)}
{Cot[x]^2/(a + a*Sec[x]), x, 6, -(x/a) - Sin[x]/(4*a*(1 - Cos[x])) - Sin[x]/(6*a*(1 + Cos[x])^2) + (13*Sin[x])/(12*a*(1 + Cos[x]))}
{Cot[x]^3/(a + a*Sec[x]), x, 9, -(1/(8*a*(1 - Cos[x]))) + 1/(8*a*(1 + Cos[x])^2) - 3/(4*a*(1 + Cos[x])) - (5*Log[1 - Cos[x]])/(16*a) - (11*Log[1 + Cos[x]])/(16*a)}
{Cot[x]^4/(a + a*Sec[x]), x, 11, x/a - Sin[x]/(24*a*(1 - Cos[x])^2) + (19*Sin[x])/(48*a*(1 - Cos[x])) - Sin[x]/(20*a*(1 + Cos[x])^3) + (3*Sin[x])/(10*a*(1 + Cos[x])^2) - (91*Sin[x])/(80*a*(1 + Cos[x]))}


(* ::Subsection::Closed:: *)
(*Integrands of the form Csc[c+d x]^m (a+b Sec[c+d x])^n*)


(* ::Subsubsection::Closed:: *)
(*a^2 /= b^2*)


(* Integrands of the form Csc[x]^m/(a+b*Sec[x]) where m is a positive integer *)
{Csc[x]/(a + b*Sec[x]), x, 7, Log[1 - Cos[x]]/(2*(a + b)) - Log[1 + Cos[x]]/(2*(a - b)) + (b*Log[b + a*Cos[x]])/(a^2 - b^2)}
{Csc[x]^2/(a + b*Sec[x]), x, 5, -((2*a*b*ArcTanh[((a - b)*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(3/2)) - (a*Cot[x])/(a^2 - b^2) + (b*Csc[x])/(a^2 - b^2), -((2*a*b*ArcTanh[((a - b)*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(3/2)) - Sin[x]/(2*(a + b)*(1 - Cos[x])) + Sin[x]/(2*(a - b)*(1 + Cos[x]))}
{Csc[x]^3/(a + b*Sec[x]), x, 8, -(1/(4*(a + b)*(1 - Cos[x]))) + 1/(4*(a - b)*(1 + Cos[x])) + (a*Log[1 - Cos[x]])/(4*(a + b)^2) - (a*Log[1 + Cos[x]])/(4*(a - b)^2) + (a^2*b*Log[b + a*Cos[x]])/(a^2 - b^2)^2}
{Csc[x]^4/(a + b*Sec[x]), x, 9, -((2*a^3*b*ArcTanh[((a - b)*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(5/2)) - Sin[x]/(12*(a + b)*(1 - Cos[x])^2) - (a*Sin[x])/(4*(a + b)^2*(1 - Cos[x])) - Sin[x]/(12*(a + b)*(1 - Cos[x])) + Sin[x]/(12*(a - b)*(1 + Cos[x])^2) + (a*Sin[x])/(4*(a - b)^2*(1 + Cos[x])) + Sin[x]/(12*(a - b)*(1 + Cos[x]))}


(* ::Subsubsection::Closed:: *)
(*a^2 = b^2*)


{Csc[x]/(a + a*Sec[x]), x, 6, -(ArcTanh[Cos[x]]/(2*a)) - 1/(2*a*(1 + Cos[x]))}
{Csc[x]^2/(a + a*Sec[x]), x, 6, -(Sin[x]/(4*a*(1 - Cos[x]))) - Sin[x]/(6*a*(1 + Cos[x])^2) + Sin[x]/(12*a*(1 + Cos[x]))}
{Csc[x]^3/(a + a*Sec[x]), x, 7, -(ArcTanh[Cos[x]]/(8*a)) - 1/(8*a*(1 - Cos[x])) - 1/(8*a*(1 + Cos[x])^2)}
{Csc[x]^4/(a + a*Sec[x]), x, 9, -(Sin[x]/(24*a*(1 - Cos[x])^2)) - (5*Sin[x])/(48*a*(1 - Cos[x])) - Sin[x]/(20*a*(1 + Cos[x])^3) - Sin[x]/(30*a*(1 + Cos[x])^2) + (7*Sin[x])/(240*a*(1 + Cos[x]))}
