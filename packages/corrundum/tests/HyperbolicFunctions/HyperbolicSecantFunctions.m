(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Hyperbolic Secants*)


(* ::Subsection::Closed:: *)
(*Sech[a+b x]^n*)


(* Integrands of the form Sech[a+b*x]^n where n is a positive integer *)
{Sech[a+b*x], x, 1, ArcTan[Sinh[a+b*x]]/b}
{Sech[a+b*x]^2, x, 1, Tanh[a+b*x]/b}
{Sech[a+b*x]^3, x, 2, ArcTan[Sinh[a + b*x]]/(2*b) + (Sech[a + b*x]*Tanh[a + b*x])/(2*b)}
{Sech[a+b*x]^4, x, 2, Tanh[a + b*x]/b - Tanh[a + b*x]^3/(3*b)}
{Sech[a+b*x]^5, x, 3, (3*ArcTan[Sinh[a + b*x]])/(8*b) + (3*Sech[a + b*x]*Tanh[a + b*x])/(8*b) + (Sech[a + b*x]^3*Tanh[a + b*x])/(4*b)}

{Sech[7*x]^4, x, 2, (1/7)*Tanh[7*x] - (1/21)*Tanh[7*x]^3}
{Sech[Pi*x]^6, x, 3, Tanh[Pi*x]/Pi - (2*Tanh[Pi*x]^3)/(3*Pi) + Tanh[Pi*x]^5/(5*Pi)}


(* Integrands of the form Sech[a+b*x]^n where n is a half-integer *)
{Sech[a+b*x]^(1/2), x, 2, -((2*I*Sqrt[Cosh[a + b*x]]*EllipticF[(1/2)*I*(a + b*x), 2]*Sqrt[Sech[a + b*x]])/b)}
{Sech[a+b*x]^(3/2), x, 3, (2*I*Sqrt[Cosh[a + b*x]]*EllipticE[(1/2)*I*(a + b*x), 2]*Sqrt[Sech[a + b*x]])/b + (2*Sqrt[Sech[a + b*x]]*Sinh[a + b*x])/b}
{Sech[a+b*x]^(5/2), x, 3, -((2*I*Sqrt[Cosh[a + b*x]]*EllipticF[(1/2)*I*(a + b*x), 2]*Sqrt[Sech[a + b*x]])/(3*b)) + (2*Sech[a + b*x]^(3/2)*Sinh[a + b*x])/(3*b)}

{1/Sech[a+b*x]^(1/2), x, 2, -((2*I*Sqrt[Cosh[a + b*x]]*EllipticE[(1/2)*I*(a + b*x), 2]*Sqrt[Sech[a + b*x]])/b)}
{1/Sech[a+b*x]^(3/2), x, 3, -((2*I*Sqrt[Cosh[a + b*x]]*EllipticF[(1/2)*I*(a + b*x), 2]*Sqrt[Sech[a + b*x]])/(3*b)) + (2*Sinh[a + b*x])/(3*b*Sqrt[Sech[a + b*x]])}
{1/Sech[a+b*x]^(5/2), x, 3, -((6*I*Sqrt[Cosh[a + b*x]]*EllipticE[(1/2)*I*(a + b*x), 2]*Sqrt[Sech[a + b*x]])/(5*b)) + (2*Sinh[a + b*x])/(5*b*Sech[a + b*x]^(3/2))}


(* ::Subsection::Closed:: *)
(*(c+d x)^m Sech[a+b x]^n*)


(* Integrands of the form x^m*Sech[a+b*x]^n where m and n are integers *)
{x*Sech[a + b*x], x, 4, (2*x*ArcTan[E^(a + b*x)])/b - (I*PolyLog[2, (-I)*E^(a + b*x)])/b^2 + (I*PolyLog[2, I*E^(a + b*x)])/b^2}
{x^2*Sech[a + b*x], x, 6, (2*x^2*ArcTan[E^(a + b*x)])/b - (2*I*x*PolyLog[2, (-I)*E^(a + b*x)])/b^2 + (2*I*x*PolyLog[2, I*E^(a + b*x)])/b^2 + (2*I*PolyLog[3, (-I)*E^(a + b*x)])/b^3 - (2*I*PolyLog[3, I*E^(a + b*x)])/b^3}
{x^3*Sech[a + b*x], x, 8, (2*x^3*ArcTan[E^(a + b*x)])/b - (3*I*x^2*PolyLog[2, (-I)*E^(a + b*x)])/b^2 + (3*I*x^2*PolyLog[2, I*E^(a + b*x)])/b^2 + (6*I*x*PolyLog[3, (-I)*E^(a + b*x)])/b^3 - (6*I*x*PolyLog[3, I*E^(a + b*x)])/b^3 - (6*I*PolyLog[4, (-I)*E^(a + b*x)])/b^4 + (6*I*PolyLog[4, I*E^(a + b*x)])/b^4}
{1/x*Sech[a + b*x], x, 0, Int[Sech[a + b*x]/x, x]}

{x*Sech[a + b*x]^2, x, 2, -(Log[Cosh[a + b*x]]/b^2) + (x*Tanh[a + b*x])/b}
{x^2*Sech[a + b*x]^2, x, 5, x^2/b - (2*x*Log[1 + E^(2*a + 2*b*x)])/b^2 - PolyLog[2, -E^(2*a + 2*b*x)]/b^3 + (x^2*Tanh[a + b*x])/b}
{x^3*Sech[a + b*x]^2, x, 6, x^3/b - (3*x^2*Log[1 + E^(2*a + 2*b*x)])/b^2 - (3*x*PolyLog[2, -E^(2*a + 2*b*x)])/b^3 + (3*PolyLog[3, -E^(2*a + 2*b*x)])/(2*b^4) + (x^3*Tanh[a + b*x])/b}
{1/x*Sech[a + b*x]^2, x, 0, Int[Sech[a + b*x]^2/x, x]}

{x*Sech[a + b*x]^3, x, 5, (x*ArcTan[E^(a + b*x)])/b - (I*PolyLog[2, (-I)*E^(a + b*x)])/(2*b^2) + (I*PolyLog[2, I*E^(a + b*x)])/(2*b^2) + Sech[a + b*x]/(2*b^2) + (x*Sech[a + b*x]*Tanh[a + b*x])/(2*b)}
{x^2*Sech[a + b*x]^3, x, 8, (x^2*ArcTan[E^(a + b*x)])/b - ArcTan[Sinh[a + b*x]]/b^3 - (I*x*PolyLog[2, (-I)*E^(a + b*x)])/b^2 + (I*x*PolyLog[2, I*E^(a + b*x)])/b^2 + (I*PolyLog[3, (-I)*E^(a + b*x)])/b^3 - (I*PolyLog[3, I*E^(a + b*x)])/b^3 + (x*Sech[a + b*x])/b^2 + (x^2*Sech[a + b*x]*Tanh[a + b*x])/(2*b)}
(* {x^3*Sech[a + b*x]^3, x, 13, -((6*x*ArcTan[E^(a + b*x)])/b^3) + (x^3*ArcTan[E^(a + b*x)])/b + (3*I*(2 - b^2*x^2)*PolyLog[2, (-I)*E^(a + b*x)])/(2*b^4) - (3*I*(2 - b^2*x^2)*PolyLog[2, I*E^(a + b*x)])/(2*b^4) + (3*I*x*PolyLog[3, (-I)*E^(a + b*x)])/b^3 - (3*I*x*PolyLog[3, I*E^(a + b*x)])/b^3 - (3*I*PolyLog[4, (-I)*E^(a + b*x)])/b^4 + (3*I*PolyLog[4, I*E^(a + b*x)])/b^4 + (3*x^2*Sech[a + b*x])/(2*b^2) + (x^3*Sech[a + b*x]*Tanh[a + b*x])/(2*b)} *)
{1/x*Sech[a + b*x]^3, x, 0, Int[Sech[a + b*x]^3/x, x]}


(* Integrands of the form (c+d*x)^m*Sech[a+b*x]^n where m and n are integers *)
{(c + d*x)*Sech[a + b*x], x, 5, (2*(c + d*x)*ArcTan[E^(a + b*x)])/b - (I*d*PolyLog[2, (-I)*E^(a + b*x)])/b^2 + (I*d*PolyLog[2, I*E^(a + b*x)])/b^2}
{(c + d*x)^2*Sech[a + b*x], x, 7, (2*(c + d*x)^2*ArcTan[E^(a + b*x)])/b - (2*I*d*(c + d*x)*PolyLog[2, (-I)*E^(a + b*x)])/b^2 + (2*I*d*(c + d*x)*PolyLog[2, I*E^(a + b*x)])/b^2 + (2*I*d^2*PolyLog[3, (-I)*E^(a + b*x)])/b^3 - (2*I*d^2*PolyLog[3, I*E^(a + b*x)])/b^3}
{(c + d*x)^3*Sech[a + b*x], x, 9, (2*(c + d*x)^3*ArcTan[E^(a + b*x)])/b - (3*I*d*(c + d*x)^2*PolyLog[2, (-I)*E^(a + b*x)])/b^2 + (3*I*d*(c + d*x)^2*PolyLog[2, I*E^(a + b*x)])/b^2 + (6*I*d^2*(c + d*x)*PolyLog[3, (-I)*E^(a + b*x)])/b^3 - (6*I*d^2*(c + d*x)*PolyLog[3, I*E^(a + b*x)])/b^3 - (6*I*d^3*PolyLog[4, (-I)*E^(a + b*x)])/b^4 + (6*I*d^3*PolyLog[4, I*E^(a + b*x)])/b^4}

{(c + d*x)*Sech[a + b*x]^2, x, 3, -((d*Log[Cosh[a + b*x]])/b^2) + ((c + d*x)*Tanh[a + b*x])/b}
{(c + d*x)^2*Sech[a + b*x]^2, x, 6, (c + d*x)^2/b - (2*d*(c + d*x)*Log[1 + E^(2*a + 2*b*x)])/b^2 - (d^2*PolyLog[2, -E^(2*a + 2*b*x)])/b^3 + ((c + d*x)^2*Tanh[a + b*x])/b}
{(c + d*x)^3*Sech[a + b*x]^2, x, 7, (c + d*x)^3/b - (3*d*(c + d*x)^2*Log[1 + E^(2*a + 2*b*x)])/b^2 - (3*d^2*(c + d*x)*PolyLog[2, -E^(2*a + 2*b*x)])/b^3 + (3*d^3*PolyLog[3, -E^(2*a + 2*b*x)])/(2*b^4) + ((c + d*x)^3*Tanh[a + b*x])/b}

{(c + d*x)*Sech[a + b*x]^3, x, 6, ((c + d*x)*ArcTan[E^(a + b*x)])/b - (I*d*PolyLog[2, (-I)*E^(a + b*x)])/(2*b^2) + (I*d*PolyLog[2, I*E^(a + b*x)])/(2*b^2) + (d*Sech[a + b*x])/(2*b^2) + ((c + d*x)*Sech[a + b*x]*Tanh[a + b*x])/(2*b)}
{(c + d*x)^2*Sech[a + b*x]^3, x, 9, ((c + d*x)^2*ArcTan[E^(a + b*x)])/b - (d^2*ArcTan[Sinh[a + b*x]])/b^3 - (I*d*(c + d*x)*PolyLog[2, (-I)*E^(a + b*x)])/b^2 + (I*d*(c + d*x)*PolyLog[2, I*E^(a + b*x)])/b^2 + (I*d^2*PolyLog[3, (-I)*E^(a + b*x)])/b^3 - (I*d^2*PolyLog[3, I*E^(a + b*x)])/b^3 + (d*(c + d*x)*Sech[a + b*x])/b^2 + ((c + d*x)^2*Sech[a + b*x]*Tanh[a + b*x])/(2*b)}
(* {(c + d*x)^3*Sech[a + b*x]^3, x, 14, -((6*d^2*(c + d*x)*ArcTan[E^(a + b*x)])/b^3) + ((c + d*x)^3*ArcTan[E^(a + b*x)])/b + (3*I*d*(2*d^2 - b^2*(c + d*x)^2)*PolyLog[2, (-I)*E^(a + b*x)])/(2*b^4) - (3*I*d*(2*d^2 - b^2*(c + d*x)^2)*PolyLog[2, I*E^(a + b*x)])/(2*b^4) + (3*I*d^2*(c + d*x)*PolyLog[3, (-I)*E^(a + b*x)])/b^3 - (3*I*d^2*(c + d*x)*PolyLog[3, I*E^(a + b*x)])/b^3 - (3*I*d^3*PolyLog[4, (-I)*E^(a + b*x)])/b^4 + (3*I*d^3*PolyLog[4, I*E^(a + b*x)])/b^4 + (3*d*(c + d*x)^2*Sech[a + b*x])/(2*b^2) + ((c + d*x)^3*Sech[a + b*x]*Tanh[a + b*x])/(2*b)} *)


{x*Sech[a + b*x^2]^7, x, 5, (5*ArcTan[Sinh[a + b*x^2]])/(32*b) + (5*Sech[a + b*x^2]*Tanh[a + b*x^2])/(32*b) + (5*Sech[a + b*x^2]^3*Tanh[a + b*x^2])/(48*b) + (Sech[a + b*x^2]^5*Tanh[a + b*x^2])/(12*b)}


(* ::Subsection::Closed:: *)
(*(a Sech[a+b x]^n)^m*)


{(Sech[x]^2)^(5/2), x, 4, (3/8)*ArcSin[Tanh[x]] + (3/8)*Sqrt[Sech[x]^2]*Tanh[x] + (1/4)*(Sech[x]^2)^(3/2)*Tanh[x]}
{(Sech[x]^2)^(3/2), x, 3, (1/2)*ArcSin[Tanh[x]] + (1/2)*Sqrt[Sech[x]^2]*Tanh[x]}
{(Sech[x]^2)^(1/2), x, 2, ArcSin[Tanh[x]]}
{1/(Sech[x]^2)^(1/2), x, 2, Tanh[x]/Sqrt[Sech[x]^2]}
{1/(Sech[x]^2)^(3/2), x, 3, ((3 + Sinh[x]^2)*Tanh[x])/(3*Sqrt[Sech[x]^2])}
{1/(Sech[x]^2)^(5/2), x, 3, ((15 + 10*Sinh[x]^2 + 3*Sinh[x]^4)*Tanh[x])/(15*Sqrt[Sech[x]^2])}
{1/(Sech[x]^2)^(7/2), x, 3, ((35*Cosh[x]^2 + 21*Sinh[x]^4 + 5*Sinh[x]^6)*Tanh[x])/(35*Sqrt[Sech[x]^2])}


{(a*Sech[x]^2)^(5/2), x, 4, (1/8)*a^2*Cosh[x]*Sqrt[a*Sech[x]^2]*(3*ArcTan[Sinh[x]] + 3*Sech[x]*Tanh[x] + 2*Sech[x]^3*Tanh[x])}
{(a*Sech[x]^2)^(3/2), x, 3, (1/2)*a*Cosh[x]*Sqrt[a*Sech[x]^2]*(ArcTan[Sinh[x]] + Sech[x]*Tanh[x])}
{(a*Sech[x]^2)^(1/2), x, 2, ArcTan[Sinh[x]]*Cosh[x]*Sqrt[a*Sech[x]^2]}
{1/(a*Sech[x]^2)^(1/2), x, 2, Tanh[x]/Sqrt[a*Sech[x]^2]}
{1/(a*Sech[x]^2)^(3/2), x, 3, ((3 + Sinh[x]^2)*Tanh[x])/(3*a*Sqrt[a*Sech[x]^2])}
{1/(a*Sech[x]^2)^(5/2), x, 3, ((15 + 10*Sinh[x]^2 + 3*Sinh[x]^4)*Tanh[x])/(15*a^2*Sqrt[a*Sech[x]^2])}
{1/(a*Sech[x]^2)^(7/2), x, 3, ((35*Cosh[x]^2 + 21*Sinh[x]^4 + 5*Sinh[x]^6)*Tanh[x])/(35*a^3*Sqrt[a*Sech[x]^2])}


{(a*Sech[x]^3)^(5/2), x, 7, (2/585)*a^2*Cosh[x]*Sqrt[a*Sech[x]^3]*(231*I*Sqrt[Cosh[x]]*EllipticE[(I*x)/2, 2] + 231*Sinh[x] + 77*Sech[x]*Tanh[x] + 55*Sech[x]^3*Tanh[x] + 45*Sech[x]^5*Tanh[x])}
{(a*Sech[x]^3)^(3/2), x, 5, (-(2/21))*a*Cosh[x]*Sqrt[a*Sech[x]^3]*(5*I*Sqrt[Cosh[x]]*EllipticF[(I*x)/2, 2] - 5*Tanh[x] - 3*Sech[x]^2*Tanh[x])}
{(a*Sech[x]^3)^(1/2), x, 4, 2*Cosh[x]*Sqrt[a*Sech[x]^3]*(I*Sqrt[Cosh[x]]*EllipticE[(I*x)/2, 2] + Sinh[x])}
{1/(a*Sech[x]^3)^(1/2), x, 4, -((2*Sech[x]*((I*EllipticF[(I*x)/2, 2])/Sqrt[Cosh[x]] - Sinh[x]))/(3*Sqrt[a*Sech[x]^3]))}
{1/(a*Sech[x]^3)^(3/2), x, 5, -((2*Cosh[x]^2*(7*Sech[x]^2*((3*I*EllipticE[(I*x)/2, 2])/Cosh[x]^(3/2) - Sinh[x]) - 5*Sinh[x]))/(45*a*Sqrt[a*Sech[x]^3]))}
{1/(a*Sech[x]^3)^(5/2), x, 7, -((2*Cosh[x]^5*(13*Sech[x]^2*(3*Sech[x]^2*(5*Sech[x]^2*((I*EllipticF[(I*x)/2, 2])/Sqrt[Cosh[x]] - Sinh[x]) - 3*Sinh[x]) - 7*Sinh[x]) - 77*Sinh[x]))/(1155*a^2*Sqrt[a*Sech[x]^3]))}


{(a*Sech[x]^4)^(7/2), x, 4, (a^3*Cosh[x]*Sqrt[a*Sech[x]^4]*Sinh[x]*(3003 - 6006*Tanh[x]^2 + 9009*Tanh[x]^4 - 8580*Tanh[x]^6 + 5005*Tanh[x]^8 - 1638*Tanh[x]^10 + 231*Tanh[x]^12))/3003}
{(a*Sech[x]^4)^(5/2), x, 4, (1/315)*a^2*Cosh[x]*Sqrt[a*Sech[x]^4]*Sinh[x]*(315 - 420*Tanh[x]^2 + 378*Tanh[x]^4 - 180*Tanh[x]^6 + 35*Tanh[x]^8)}
{(a*Sech[x]^4)^(3/2), x, 4, (1/15)*a*Cosh[x]*Sqrt[a*Sech[x]^4]*Sinh[x]*(15 - 10*Tanh[x]^2 + 3*Tanh[x]^4)}
{(a*Sech[x]^4)^(1/2), x, 2, Cosh[x]*Sqrt[a*Sech[x]^4]*Sinh[x]}
{1/(a*Sech[x]^4)^(1/2), x, 2, (Sech[x]^2*(x + Cosh[x]*Sinh[x]))/(2*Sqrt[a*Sech[x]^4])}
{1/(a*Sech[x]^4)^(3/2), x, 4, (Sech[x]^2*(15*x + 15*Cosh[x]*Sinh[x] + 10*Cosh[x]^3*Sinh[x] + 8*Cosh[x]^5*Sinh[x]))/(48*a*Sqrt[a*Sech[x]^4])}
{1/(a*Sech[x]^4)^(5/2), x, 6, (Sech[x]^2*(315*x + 315*Cosh[x]*Sinh[x] + 210*Cosh[x]^3*Sinh[x] + 168*Cosh[x]^5*Sinh[x] + 144*Cosh[x]^7*Sinh[x] + 128*Cosh[x]^9*Sinh[x]))/(1280*a^2*Sqrt[a*Sech[x]^4])}


(* ::Subsection::Closed:: *)
(*(a+b Sech[c+d x])^n		where a^2-b^2 is zero*)


(* Integrands of the form (a+b*Sech[c+d*x])^n where a^2-b^2 is zero *)
{1/(a + a*Sech[c + d*x]), x, 3, x/a - Sinh[c + d*x]/(a*d*(1 + Cosh[c + d*x]))}
{1/(a - a*Sech[c + d*x]), x, 3, x/a + Sinh[c + d*x]/(a*d*(1 - Cosh[c + d*x]))}

{Sqrt[3 + 3*Sech[x]], x, 1, (2*Sqrt[3]*ArcTan[Sqrt[-1 + Sech[x]]]*Tanh[x])/(Sqrt[-1 + Sech[x]]*Sqrt[1 + Sech[x]])}
{Sqrt[3 - 3*Sech[x]], x, 1, (2*Sqrt[3]*ArcTan[Sqrt[-1 - Sech[x]]]*Tanh[x])/(Sqrt[-1 - Sech[x]]*Sqrt[1 - Sech[x]])}
{Sqrt[a + a*Sech[x]], x, 1, (2*a*ArcTan[Sqrt[-1 + Sech[x]]]*Tanh[x])/(Sqrt[-1 + Sech[x]]*Sqrt[a + a*Sech[x]])}
{Sqrt[a - a*Sech[x]], x, 1, (2*a*ArcTan[Sqrt[-1 - Sech[x]]]*Tanh[x])/(Sqrt[-1 - Sech[x]]*Sqrt[a - a*Sech[x]])}

{1/Sqrt[a + a*Sech[x]], x, 1, -(((Sqrt[2]*ArcTan[(Sqrt[2]*Sqrt[a])/Sqrt[-a + a*Sech[x]]] + 2*ArcTan[Sqrt[-a + a*Sech[x]]/Sqrt[a]])*Coth[x]*Sqrt[-a + a*Sech[x]]*Sqrt[a + a*Sech[x]])/a^(3/2))}
{1/Sqrt[a - a*Sech[x]], x, 1, -(((Sqrt[2]*ArcTan[(Sqrt[2]*Sqrt[a])/Sqrt[-a - a*Sech[x]]] + 2*ArcTan[Sqrt[-a - a*Sech[x]]/Sqrt[a]])*Coth[x]*Sqrt[-a - a*Sech[x]]*Sqrt[a - a*Sech[x]])/a^(3/2))}


(* ::Subsection::Closed:: *)
(*(a+b Sech[c+d x])^n		where a^2-b^2 is nonzero*)


(*Integrands of the form (a+b*Sech[x])^m where m is an integer *)
{(a + b*Sech[x]), x, 2, a*x + b*ArcTan[Sinh[x]]}
{(a + b*Sech[x])^2, x, 4, a^2*x + 2*a*b*ArcTan[Sinh[x]] + b^2*Tanh[x]}
{(a + b*Sech[x])^3, x, 6, a^3*x + 3*a^2*b*ArcTan[Sinh[x]] + (1/2)*b^3*ArcTan[Sinh[x]] + 3*a*b^2*Tanh[x] + (1/2)*b^3*Sech[x]*Tanh[x]}

{1/(3 + 5*Sech[x]), x, 3, x/3 - (5/6)*ArcTanh[(1/2)*Tanh[x/2]]}
{1/(a + b*Sech[x]), x, 3, x/a - (2*b*ArcTan[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a*Sqrt[a^2 - b^2])}
{1/(a + b*Sech[x])^2, x, 6, x/a^2 - (2*b^3*ArcTan[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2*(a^2 - b^2)^(3/2)) - (4*b*ArcTan[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2*Sqrt[a^2 - b^2]) + (b^2*Sinh[x])/(a*(a^2 - b^2)*(b + a*Cosh[x]))}
{1/(a + b*Sech[x])^3, x, 9, x/a^3 - (6*b^3*ArcTan[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^3*(a^2 - b^2)^(3/2)) - (6*b*ArcTan[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^3*Sqrt[a^2 - b^2]) - (b^3*(a^2 + 2*b^2)*ArcTan[((a - b)*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^3*(a^2 - b^2)^(5/2)) - (b^3*Sinh[x])/(2*a^2*(a^2 - b^2)*(b + a*Cosh[x])^2) + (3*b^4*Sinh[x])/(2*a^2*(a^2 - b^2)^2*(b + a*Cosh[x])) + (3*b^2*Sinh[x])/(a^2*(a^2 - b^2)*(b + a*Cosh[x]))}


(* ::Subsection::Closed:: *)
(*(a+b Sech[c+d x]^n)^m*)


(*Integrands of the form (a+b*Sech[x]^2)^m where m is an integer *)
{(a + b*Sech[x]^2), x, 2, a*x + b*Tanh[x]}
{(a + b*Sech[x]^2)^2, x, 5, a^2*x + 2*a*b*Tanh[x] + b^2*Tanh[x] - (1/3)*b^2*Tanh[x]^3}
{(a + b*Sech[x]^2)^3, x, 8, a^3*x + 3*a^2*b*Tanh[x] + 3*a*b^2*Tanh[x] + b^3*Tanh[x] - a*b^2*Tanh[x]^3 - (2/3)*b^3*Tanh[x]^3 + (1/5)*b^3*Tanh[x]^5}

{1/(a + b*Sech[x]^2), x, 5, x/a - (Sqrt[b]*ArcTanh[(Sqrt[b]*Tanh[x])/Sqrt[a + b]])/(a*Sqrt[a + b])}
{1/(a + b*Sech[x]^2)^2, x, 8, x/a^2 - (2*Sqrt[b]*ArcTanh[(Sqrt[b]*Tanh[x])/Sqrt[a + b]])/(a^2*Sqrt[a + b]) + (Sqrt[b]*(a + 2*b)*ArcTanh[(Sqrt[b]*Tanh[x])/Sqrt[a + b]])/(2*a^2*(a + b)^(3/2)) - (b*Sinh[2*x])/(2*a*(a + b)*(a + 2*b + a*Cosh[2*x]))}
(* {1/(a + b*Sech[x]^2)^3, x, 12, x/a^3 - (3*Sqrt[b]*ArcTanh[(Sqrt[b]*Tanh[x])/Sqrt[a + b]])/(a^3*Sqrt[a + b]) + (3*Sqrt[b]*(a + 2*b)*ArcTanh[(Sqrt[b]*Tanh[x])/Sqrt[a + b]])/(2*a^3*(a + b)^(3/2)) - (Sqrt[b]*(a^2 + 2*(a + 2*b)^2)*ArcTanh[(Sqrt[b]*Tanh[x])/Sqrt[a + b]])/(8*a^3*(a + b)^(5/2)) + (b^2*Sinh[2*x])/(2*a^2*(a + b)*(a + 2*b + a*Cosh[2*x])^2) - (3*b*Sinh[2*x])/(2*a^2*(a + b)*(a + 2*b + a*Cosh[2*x])) + (3*b*(a + 2*b)*Sinh[2*x])/(8*a^2*(a + b)^2*(a + 2*b + a*Cosh[2*x]))} *)


(* Integrands of the form (a+b*Sech[x]^2)^m where m is a half-integer *)
{Sqrt[1 + Sech[x]^2], x, 4, ArcSin[Tanh[x]/Sqrt[2]] + ArcTanh[Tanh[x]/Sqrt[2 - Tanh[x]^2]]}
{Sqrt[1 - Sech[x]^2], x, 3, Coth[x]*Log[Cosh[x]]*Sqrt[Tanh[x]^2]}
{Sqrt[-1 + Sech[x]^2], x, 3, Coth[x]*Log[Cosh[x]]*Sqrt[-Tanh[x]^2]}
{Sqrt[-1 - Sech[x]^2], x, 4, -ArcTan[Tanh[x]/Sqrt[-2 + Tanh[x]^2]] - ArcTanh[Tanh[x]/Sqrt[-2 + Tanh[x]^2]]}
{Sqrt[a + b*Sech[x]^2], x, 4, Sqrt[b]*ArcTan[(Sqrt[b]*Tanh[x])/Sqrt[a + b*Sech[x]^2]] + Sqrt[a]*ArcTanh[(Sqrt[a]*Tanh[x])/Sqrt[a + b*Sech[x]^2]]}

{1/Sqrt[1 + Sech[x]^2], x, 2, ArcTanh[Tanh[x]/Sqrt[2 - Tanh[x]^2]]}
{1/Sqrt[1 - Sech[x]^2], x, 3, (Log[Sinh[x]]*Tanh[x])/Sqrt[Tanh[x]^2]}
{1/Sqrt[-1 + Sech[x]^2], x, 3, (Log[Sinh[x]]*Tanh[x])/Sqrt[-Tanh[x]^2]}
{1/Sqrt[-1 - Sech[x]^2], x, 2, ArcTan[Tanh[x]/Sqrt[-2 + Tanh[x]^2]]}
{1/Sqrt[a + b*Sech[x]^2], x, 2, ArcTanh[(Sqrt[a]*Tanh[x])/Sqrt[a + b*Sech[x]^2]]/Sqrt[a]}

{(1 + Sech[x]^2)^(3/2), x, 7, 2*ArcSin[Tanh[x]/Sqrt[2]] + ArcTanh[Tanh[x]/Sqrt[2 - Tanh[x]^2]] + (1/2)*Tanh[x]*Sqrt[2 - Tanh[x]^2]}
{(1 - Sech[x]^2)^(3/2), x, 4, Coth[x]*Log[Cosh[x]]*Sqrt[Tanh[x]^2] - (1/2)*Coth[x]*(Tanh[x]^2)^(3/2)}
{(-1 + Sech[x]^2)^(3/2), x, 4, (-Coth[x])*Log[Cosh[x]]*Sqrt[-Tanh[x]^2] + (1/2)*Tanh[x]*Sqrt[-Tanh[x]^2]}
{(-1 - Sech[x]^2)^(3/2), x, 8, ArcTan[Tanh[x]/Sqrt[-2 + Tanh[x]^2]] + 2*ArcTanh[Tanh[x]/Sqrt[-2 + Tanh[x]^2]] - (1/2)*Tanh[x]*Sqrt[-2 + Tanh[x]^2]}
{(a + b*Sech[x]^2)^(3/2), x, 8, (3/2)*a*Sqrt[b]*ArcTan[(Sqrt[b]*Tanh[x])/Sqrt[a + b*Sech[x]^2]] + (1/2)*b^(3/2)*ArcTan[(Sqrt[b]*Tanh[x])/Sqrt[a + b*Sech[x]^2]] + a^(3/2)*ArcTanh[(Sqrt[a]*Tanh[x])/Sqrt[a + b*Sech[x]^2]] + (1/2)*b*Sqrt[a + b*Sech[x]^2]*Tanh[x]}


(* ::Subsection::Closed:: *)
(*x^m Sech[a+b Log[c x^n]]^p*)


{Sech[a + b*Log[c*x^n]], x, 0, Int[Sech[a + b*Log[c*x^n]], x]}
{Sech[a + b*Log[c*x^n]]^2, x, 0, Int[Sech[a + b*Log[c*x^n]]^2, x]}
{Sech[a + b*Log[c*x^n]]^3, x, 1, -(((1 - b^2*n^2)*Int[Sech[a + b*Log[c*x^n]], x])/(2*b^2*n^2)) + (x*Sech[a + b*Log[c*x^n]])/(2*b^2*n^2) + (x*Sech[a + b*Log[c*x^n]]*Tanh[a + b*Log[c*x^n]])/(2*b*n)}
{Sech[a + b*Log[c*x^n]]^4, x, 1, -(((1 - 4*b^2*n^2)*Int[Sech[a + b*Log[c*x^n]]^2, x])/(6*b^2*n^2)) + (x*Sech[a + b*Log[c*x^n]]^2)/(6*b^2*n^2) + (x*Sech[a + b*Log[c*x^n]]^2*Tanh[a + b*Log[c*x^n]])/(3*b*n)}

{2*b^2*n^2*Sech[a + b*Log[c*x^n]]^3 + (1 - b^2*n^2)*Sech[a + b*Log[c*x^n]], x, 2, x*Sech[a + b*Log[c*x^n]] + b*n*x*Sech[a + b*Log[c*x^n]]*Tanh[a + b*Log[c*x^n]]}


{Sech[a + 2*Log[c*x^(1/2)]]^3, x, 1, (1/2)*x*Sech[a + 2*Log[c*Sqrt[x]]] + (1/2)*x*Sech[a + 2*Log[c*Sqrt[x]]]*Tanh[a + 2*Log[c*Sqrt[x]]]}
{Sech[a + 2*Log[c/x^(1/2)]]^3, x, 1, (1/2)*x*Sech[a + 2*Log[c/Sqrt[x]]] - (1/2)*x*Sech[a + 2*Log[c/Sqrt[x]]]*Tanh[a + 2*Log[c/Sqrt[x]]]}
{Sech[a + 1/(n*(-2 + p))*Log[c*x^n]]^p, x, 1, ((2 - p)*x*Sech[a - Log[c*x^n]/(n*(2 - p))]^(-2 + p))/(1 - p) + ((2 - p)*x*Sech[a - Log[c*x^n]/(n*(2 - p))]^(-1 + p)*Sinh[a - Log[c*x^n]/(n*(2 - p))])/(1 - p)}
{Sech[a - 1/(n*(-2 + p))*Log[c*x^n]]^p, x, 1, ((2 - p)*x*Sech[a + Log[c*x^n]/(n*(2 - p))]^(-2 + p))/(1 - p) - ((2 - p)*x*Sech[a + Log[c*x^n]/(n*(2 - p))]^(-1 + p)*Sinh[a + Log[c*x^n]/(n*(2 - p))])/(1 - p)}


(* Integrands of the form Sech[a+b*Log[c*x^n]]^p/x where p is an integer *)
{Sech[a + b*Log[c*x^n]]/x, x, 2, ArcTan[Sinh[a + b*Log[c*x^n]]]/(b*n)}
{Sech[a + b*Log[c*x^n]]^2/x, x, 2, Tanh[a + b*Log[c*x^n]]/(b*n)}
{Sech[a + b*Log[c*x^n]]^3/x, x, 3, ArcTan[Sinh[a + b*Log[c*x^n]]]/(2*b*n) + (Sech[a + b*Log[c*x^n]]*Tanh[a + b*Log[c*x^n]])/(2*b*n)}
{Sech[a + b*Log[c*x^n]]^4/x, x, 3, Tanh[a + b*Log[c*x^n]]/(b*n) - Tanh[a + b*Log[c*x^n]]^3/(3*b*n)}
{Sech[a + b*Log[c*x^n]]^5/x, x, 4, (3*ArcTan[Sinh[a + b*Log[c*x^n]]])/(8*b*n) + (3*Sech[a + b*Log[c*x^n]]*Tanh[a + b*Log[c*x^n]])/(8*b*n) + (Sech[a + b*Log[c*x^n]]^3*Tanh[a + b*Log[c*x^n]])/(4*b*n)}


(* Integrands of the form Sech[a+b*Log[c*x^n]]^p/x where p is a half-integer *)
{Sech[a + b*Log[c*x^n]]^(5/2)/x, x, 4, -((2*I*Sqrt[Cosh[a + b*Log[c*x^n]]]*EllipticF[(1/2)*I*(a + b*Log[c*x^n]), 2]*Sqrt[Sech[a + b*Log[c*x^n]]])/(3*b*n)) + (2*Sech[a + b*Log[c*x^n]]^(3/2)*Sinh[a + b*Log[c*x^n]])/(3*b*n)}
{Sech[a + b*Log[c*x^n]]^(3/2)/x, x, 4, (2*I*Sqrt[Cosh[a + b*Log[c*x^n]]]*EllipticE[(1/2)*I*(a + b*Log[c*x^n]), 2]*Sqrt[Sech[a + b*Log[c*x^n]]])/(b*n) + (2*Sqrt[Sech[a + b*Log[c*x^n]]]*Sinh[a + b*Log[c*x^n]])/(b*n)}
{Sqrt[Sech[a + b*Log[c*x^n]]]/x, x, 3, -((2*I*Sqrt[Cosh[a + b*Log[c*x^n]]]*EllipticF[(1/2)*I*(a + b*Log[c*x^n]), 2]*Sqrt[Sech[a + b*Log[c*x^n]]])/(b*n))}
{1/(x*Sqrt[Sech[a + b*Log[c*x^n]]]), x, 3, -((2*I*Sqrt[Cosh[a + b*Log[c*x^n]]]*EllipticE[(1/2)*I*(a + b*Log[c*x^n]), 2]*Sqrt[Sech[a + b*Log[c*x^n]]])/(b*n))}
{1/(x*Sech[a + b*Log[c*x^n]]^(3/2)), x, 4, -((2*I*Sqrt[Cosh[a + b*Log[c*x^n]]]*EllipticF[(1/2)*I*(a + b*Log[c*x^n]), 2]*Sqrt[Sech[a + b*Log[c*x^n]]])/(3*b*n)) + (2*Sinh[a + b*Log[c*x^n]])/(3*b*n*Sqrt[Sech[a + b*Log[c*x^n]]])}
{1/(x*Sech[a + b*Log[c*x^n]]^(5/2)), x, 4, -((6*I*Sqrt[Cosh[a + b*Log[c*x^n]]]*EllipticE[(1/2)*I*(a + b*Log[c*x^n]), 2]*Sqrt[Sech[a + b*Log[c*x^n]]])/(5*b*n)) + (2*Sinh[a + b*Log[c*x^n]])/(5*b*n*Sech[a + b*Log[c*x^n]]^(3/2))}


(* ::Subsection::Closed:: *)
(*Miscellaneous integrands involving one secant*)


(* Integrands of the form x^m*Sech[x]^n where m is an integer and n is a half-integer *)
{x/Sech[x]^(3/2) - (1/3)*x*Sqrt[Sech[x]], x, 2, -(4/(9*Sech[x]^(3/2))) + (2*x*Sinh[x])/(3*Sqrt[Sech[x]])}
{x/Sech[x]^(5/2) - (3/5)*x/Sqrt[Sech[x]], x, 2, -(4/(25*Sech[x]^(5/2))) + (2*x*Sinh[x])/(5*Sech[x]^(3/2))}
{x/Sech[x]^(7/2) - (5/21)*x*Sqrt[Sech[x]], x, 3, -(4/(49*Sech[x]^(7/2))) - 20/(63*Sech[x]^(3/2)) + (2*x*Sinh[x])/(7*Sech[x]^(5/2)) + (10*x*Sinh[x])/(21*Sqrt[Sech[x]])}
{x^2/Sech[x]^(3/2) - (1/3)*x^2*Sqrt[Sech[x]], x, 5, -((8*x)/(9*Sech[x]^(3/2))) - (16/27)*I*Sqrt[Cosh[x]]*EllipticF[(I*x)/2, 2]*Sqrt[Sech[x]] + (16*Sinh[x])/(27*Sqrt[Sech[x]]) + (2*x^2*Sinh[x])/(3*Sqrt[Sech[x]])}


{Sech[x^(-1)]^2/x^2, x, 2, -Tanh[x^(-1)]}
