(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Hyperbolic Cosecants*)


(* ::Subsection::Closed:: *)
(*Csch[a+b x]^n*)


(* Integrands of the form Csch[a+b*x]^n where n is a positive integer *)
{Csch[a+b*x], x, 1, -ArcCoth[Cosh[a+b*x]]/b}
{Csch[a+b*x]^2, x, 1, -Coth[a+b*x]/b}
{Csch[a+b*x]^3, x, 2, ArcCoth[Cosh[a + b*x]]/(2*b) - (Coth[a + b*x]*Csch[a + b*x])/(2*b)}
{Csch[a+b*x]^4, x, 2, Coth[a + b*x]/b - Coth[a + b*x]^3/(3*b)}
{Csch[a+b*x]^5, x, 3, -((3*ArcCoth[Cosh[a + b*x]])/(8*b)) + (3*Coth[a + b*x]*Csch[a + b*x])/(8*b) - (Coth[a + b*x]*Csch[a + b*x]^3)/(4*b)}


(* Integrands of the form Csch[a+b*x]^n where n is a half-integer *)
{Csch[a+b*x]^(1/2), x, 3, (2*I*Sqrt[Csch[a + b*x]]*EllipticF[Pi/4 - (1/2)*I*(a + b*x), 2]*Sqrt[I*Sinh[a + b*x]])/b}
{Csch[a+b*x]^(3/2), x, 4, -((2*Cosh[a + b*x]*Sqrt[Csch[a + b*x]])/b) + (2*I*EllipticE[Pi/4 - (1/2)*I*(a + b*x), 2])/(b*Sqrt[Csch[a + b*x]]*Sqrt[I*Sinh[a + b*x]])}
{Csch[a+b*x]^(5/2), x, 4, -((2*Cosh[a + b*x]*Csch[a + b*x]^(3/2))/(3*b)) - (2*I*Sqrt[Csch[a + b*x]]*EllipticF[Pi/4 - (1/2)*I*(a + b*x), 2]*Sqrt[I*Sinh[a + b*x]])/(3*b)}

{1/Csch[a+b*x]^(1/2), x, 3, (2*I*EllipticE[Pi/4 - (1/2)*I*(a + b*x), 2])/(b*Sqrt[Csch[a + b*x]]*Sqrt[I*Sinh[a + b*x]])}
{1/Csch[a+b*x]^(3/2), x, 4, (2*Cosh[a + b*x])/(3*b*Sqrt[Csch[a + b*x]]) - (2*I*Sqrt[Csch[a + b*x]]*EllipticF[Pi/4 - (1/2)*I*(a + b*x), 2]*Sqrt[I*Sinh[a + b*x]])/(3*b)}
{1/Csch[a+b*x]^(5/2), x, 4, (2*Cosh[a + b*x])/(5*b*Csch[a + b*x]^(3/2)) - (6*I*EllipticE[Pi/4 - (1/2)*I*(a + b*x), 2])/(5*b*Sqrt[Csch[a + b*x]]*Sqrt[I*Sinh[a + b*x]])}


(* ::Subsection::Closed:: *)
(*(c+d x)^m Csch[a+b x]^n*)


(* Integrands of the form x^m*Csch[a+b*x]^n where m and n are integers *)
{x*Csch[a + b*x], x, 4, -((2*x*ArcTanh[E^(a + b*x)])/b) - PolyLog[2, -E^(a + b*x)]/b^2 + PolyLog[2, E^(a + b*x)]/b^2}
{x^2*Csch[a + b*x], x, 6, -((2*x^2*ArcTanh[E^(a + b*x)])/b) - (2*x*PolyLog[2, -E^(a + b*x)])/b^2 + (2*x*PolyLog[2, E^(a + b*x)])/b^2 + (2*PolyLog[3, -E^(a + b*x)])/b^3 - (2*PolyLog[3, E^(a + b*x)])/b^3}
{x^3*Csch[a + b*x], x, 8, -((2*x^3*ArcTanh[E^(a + b*x)])/b) - (3*x^2*PolyLog[2, -E^(a + b*x)])/b^2 + (3*x^2*PolyLog[2, E^(a + b*x)])/b^2 + (6*x*PolyLog[3, -E^(a + b*x)])/b^3 - (6*x*PolyLog[3, E^(a + b*x)])/b^3 - (6*PolyLog[4, -E^(a + b*x)])/b^4 + (6*PolyLog[4, E^(a + b*x)])/b^4}
{1/x*Csch[a + b*x], x, 0, Int[Csch[a + b*x]/x, x]}

{x*Csch[a + b*x]^2, x, 2, -((x*Coth[a + b*x])/b) + Log[Sinh[a + b*x]]/b^2}
{x^2*Csch[a + b*x]^2, x, 5, -(x^2/b) - (x^2*Coth[a + b*x])/b + (2*x*Log[1 - E^(2*a + 2*b*x)])/b^2 + PolyLog[2, E^(2*a + 2*b*x)]/b^3}
{x^3*Csch[a + b*x]^2, x, 6, -(x^3/b) - (x^3*Coth[a + b*x])/b + (3*x^2*Log[1 - E^(2*a + 2*b*x)])/b^2 + (3*x*PolyLog[2, E^(2*a + 2*b*x)])/b^3 - (3*PolyLog[3, E^(2*a + 2*b*x)])/(2*b^4)}
{1/x*Csch[a + b*x]^2, x, 0, Int[Csch[a + b*x]^2/x, x]}

{x*Csch[a + b*x]^3, x, 5, (x*ArcTanh[E^(a + b*x)])/b - Csch[a + b*x]/(2*b^2) - (x*Coth[a + b*x]*Csch[a + b*x])/(2*b) + PolyLog[2, -E^(a + b*x)]/(2*b^2) - PolyLog[2, E^(a + b*x)]/(2*b^2)}
{x^2*Csch[a + b*x]^3, x, 8, -(ArcCoth[Cosh[a + b*x]]/b^3) + (x^2*ArcTanh[E^(a + b*x)])/b - (x*Csch[a + b*x])/b^2 - (x^2*Coth[a + b*x]*Csch[a + b*x])/(2*b) + (x*PolyLog[2, -E^(a + b*x)])/b^2 - (x*PolyLog[2, E^(a + b*x)])/b^2 - PolyLog[3, -E^(a + b*x)]/b^3 + PolyLog[3, E^(a + b*x)]/b^3}
(* {x^3*Csch[a + b*x]^3, x, 13, -((6*x*ArcTanh[E^(a + b*x)])/b^3) + (x^3*ArcTanh[E^(a + b*x)])/b - (3*x^2*Csch[a + b*x])/(2*b^2) - (x^3*Coth[a + b*x]*Csch[a + b*x])/(2*b) - (3*(2 - b^2*x^2)*PolyLog[2, -E^(a + b*x)])/(2*b^4) + (3*(2 - b^2*x^2)*PolyLog[2, E^(a + b*x)])/(2*b^4) - (3*x*PolyLog[3, -E^(a + b*x)])/b^3 + (3*x*PolyLog[3, E^(a + b*x)])/b^3 + (3*PolyLog[4, -E^(a + b*x)])/b^4 - (3*PolyLog[4, E^(a + b*x)])/b^4} *)
{1/x*Csch[a + b*x]^3, x, 0, Int[Csch[a + b*x]^3/x, x]}


(* Integrands of the form (c+d*x)^m*Csch[a+b*x]^n where m and n are integers *)
{(c + d*x)*Csch[a + b*x], x, 5, -((2*(c + d*x)*ArcTanh[E^(a + b*x)])/b) - (d*PolyLog[2, -E^(a + b*x)])/b^2 + (d*PolyLog[2, E^(a + b*x)])/b^2}
{(c + d*x)^2*Csch[a + b*x], x, 7, -((2*(c + d*x)^2*ArcTanh[E^(a + b*x)])/b) - (2*d*(c + d*x)*PolyLog[2, -E^(a + b*x)])/b^2 + (2*d*(c + d*x)*PolyLog[2, E^(a + b*x)])/b^2 + (2*d^2*PolyLog[3, -E^(a + b*x)])/b^3 - (2*d^2*PolyLog[3, E^(a + b*x)])/b^3}
{(c + d*x)^3*Csch[a + b*x], x, 9, -((2*(c + d*x)^3*ArcTanh[E^(a + b*x)])/b) - (3*d*(c + d*x)^2*PolyLog[2, -E^(a + b*x)])/b^2 + (3*d*(c + d*x)^2*PolyLog[2, E^(a + b*x)])/b^2 + (6*d^2*(c + d*x)*PolyLog[3, -E^(a + b*x)])/b^3 - (6*d^2*(c + d*x)*PolyLog[3, E^(a + b*x)])/b^3 - (6*d^3*PolyLog[4, -E^(a + b*x)])/b^4 + (6*d^3*PolyLog[4, E^(a + b*x)])/b^4}

{(c + d*x)*Csch[a + b*x]^2, x, 3, -(((c + d*x)*Coth[a + b*x])/b) + (d*Log[Sinh[a + b*x]])/b^2}
{(c + d*x)^2*Csch[a + b*x]^2, x, 6, -((c + d*x)^2/b) - ((c + d*x)^2*Coth[a + b*x])/b + (2*d*(c + d*x)*Log[1 - E^(2*a + 2*b*x)])/b^2 + (d^2*PolyLog[2, E^(2*a + 2*b*x)])/b^3}
{(c + d*x)^3*Csch[a + b*x]^2, x, 7, -((c + d*x)^3/b) - ((c + d*x)^3*Coth[a + b*x])/b + (3*d*(c + d*x)^2*Log[1 - E^(2*a + 2*b*x)])/b^2 + (3*d^2*(c + d*x)*PolyLog[2, E^(2*a + 2*b*x)])/b^3 - (3*d^3*PolyLog[3, E^(2*a + 2*b*x)])/(2*b^4)}

{(c + d*x)*Csch[a + b*x]^3, x, 6, ((c + d*x)*ArcTanh[E^(a + b*x)])/b - (d*Csch[a + b*x])/(2*b^2) - ((c + d*x)*Coth[a + b*x]*Csch[a + b*x])/(2*b) + (d*PolyLog[2, -E^(a + b*x)])/(2*b^2) - (d*PolyLog[2, E^(a + b*x)])/(2*b^2)}
{(c + d*x)^2*Csch[a + b*x]^3, x, 9, -((d^2*ArcCoth[Cosh[a + b*x]])/b^3) + ((c + d*x)^2*ArcTanh[E^(a + b*x)])/b - (d*(c + d*x)*Csch[a + b*x])/b^2 - ((c + d*x)^2*Coth[a + b*x]*Csch[a + b*x])/(2*b) + (d*(c + d*x)*PolyLog[2, -E^(a + b*x)])/b^2 - (d*(c + d*x)*PolyLog[2, E^(a + b*x)])/b^2 - (d^2*PolyLog[3, -E^(a + b*x)])/b^3 + (d^2*PolyLog[3, E^(a + b*x)])/b^3}
(* {(c + d*x)^3*Csch[a + b*x]^3, x, 14, -((6*d^2*(c + d*x)*ArcTanh[E^(a + b*x)])/b^3) + ((c + d*x)^3*ArcTanh[E^(a + b*x)])/b - (3*d*(c + d*x)^2*Csch[a + b*x])/(2*b^2) - ((c + d*x)^3*Coth[a + b*x]*Csch[a + b*x])/(2*b) - (3*d*(2*d^2 - b^2*(c + d*x)^2)*PolyLog[2, -E^(a + b*x)])/(2*b^4) + (3*d*(2*d^2 - b^2*(c + d*x)^2)*PolyLog[2, E^(a + b*x)])/(2*b^4) - (3*d^2*(c + d*x)*PolyLog[3, -E^(a + b*x)])/b^3 + (3*d^2*(c + d*x)*PolyLog[3, E^(a + b*x)])/b^3 + (3*d^3*PolyLog[4, -E^(a + b*x)])/b^4 - (3*d^3*PolyLog[4, E^(a + b*x)])/b^4} *)


{x*Csch[a + b*x^2]^7, x, 5, (5*ArcCoth[Cosh[a + b*x^2]])/(32*b) - (5*Coth[a + b*x^2]*Csch[a + b*x^2])/(32*b) + (5*Coth[a + b*x^2]*Csch[a + b*x^2]^3)/(48*b) - (Coth[a + b*x^2]*Csch[a + b*x^2]^5)/(12*b)}


(* ::Subsection::Closed:: *)
(*(a Csch[a+b x]^n)^m*)


{(-Csch[x]^2)^(5/2), x, 4, (3/8)*ArcCsc[Tanh[x]] + (3/8)*Coth[x]*Sqrt[-Csch[x]^2] + (1/4)*Coth[x]*(-Csch[x]^2)^(3/2)}
{(-Csch[x]^2)^(3/2), x, 3, (1/2)*ArcCsc[Tanh[x]] + (1/2)*Coth[x]*Sqrt[-Csch[x]^2]}
{(-Csch[x]^2)^(1/2), x, 2, ArcCsc[Tanh[x]]}
{1/(-Csch[x]^2)^(1/2), x, 2, Coth[x]/Sqrt[-Csch[x]^2]}
{1/(-Csch[x]^2)^(3/2), x, 3, ((3 - Cosh[x]^2)*Coth[x])/(3*Sqrt[-Csch[x]^2])}
{1/(-Csch[x]^2)^(5/2), x, 3, ((15 - 10*Cosh[x]^2 + 3*Cosh[x]^4)*Coth[x])/(15*Sqrt[-Csch[x]^2])}
{1/(-Csch[x]^2)^(7/2), x, 3, (Coth[x]*(21*Cosh[x]^4 - 5*Cosh[x]^6 - 35*Sinh[x]^2))/(35*Sqrt[-Csch[x]^2])}


{(a*Csch[x]^2)^(5/2), x, 4, (-(1/8))*a^2*Sqrt[a*Csch[x]^2]*(3*ArcCoth[Cosh[x]] - 3*Coth[x]*Csch[x] + 2*Coth[x]*Csch[x]^3)*Sinh[x]}
{(a*Csch[x]^2)^(3/2), x, 3, (1/2)*a*Sqrt[a*Csch[x]^2]*(ArcCoth[Cosh[x]] - Coth[x]*Csch[x])*Sinh[x]}
{(a*Csch[x]^2)^(1/2), x, 2, (-ArcCoth[Cosh[x]])*Sqrt[a*Csch[x]^2]*Sinh[x]}
{1/(a*Csch[x]^2)^(1/2), x, 2, Coth[x]/Sqrt[a*Csch[x]^2]}
{1/(a*Csch[x]^2)^(3/2), x, 3, -(((3 - Cosh[x]^2)*Coth[x])/(3*a*Sqrt[a*Csch[x]^2]))}
{1/(a*Csch[x]^2)^(5/2), x, 3, ((15 - 10*Cosh[x]^2 + 3*Cosh[x]^4)*Coth[x])/(15*a^2*Sqrt[a*Csch[x]^2])}
{1/(a*Csch[x]^2)^(7/2), x, 3, -((Coth[x]*(21*Cosh[x]^4 - 5*Cosh[x]^6 - 35*Sinh[x]^2))/(35*a^3*Sqrt[a*Csch[x]^2]))}


{(a*Csch[x]^3)^(5/2), x, 8, (2/585)*a^2*Sqrt[a*Csch[x]^3]*(Coth[x]*(231 - 77*Csch[x]^2 + 55*Csch[x]^4 - 45*Csch[x]^6) - (231*I*EllipticE[Pi/4 - (I*x)/2, 2])/Sqrt[I*Sinh[x]])*Sinh[x]^2}
{(a*Csch[x]^3)^(3/2), x, 6, (2/21)*a*Sqrt[a*Csch[x]^3]*(5*Coth[x] - 3*Coth[x]*Csch[x]^2 + 5*I*EllipticF[Pi/4 - (I*x)/2, 2]*Sqrt[I*Sinh[x]])*Sinh[x]}
{(a*Csch[x]^3)^(1/2), x, 5, -2*Sqrt[a*Csch[x]^3]*(Coth[x] - (I*EllipticE[Pi/4 - (I*x)/2, 2])/Sqrt[I*Sinh[x]])*Sinh[x]^2}
{1/(a*Csch[x]^3)^(1/2), x, 5, (2*Csch[x]*(Cosh[x] - I*Csch[x]*EllipticF[Pi/4 - (I*x)/2, 2]*Sqrt[I*Sinh[x]]))/(3*Sqrt[a*Csch[x]^3])}
{1/(a*Csch[x]^3)^(3/2), x, 6, (2*Csch[x]*((21*I*EllipticE[Pi/4 - (I*x)/2, 2])/Sqrt[I*Sinh[x]] - 7*Cosh[x]*Sinh[x] + 5*Cosh[x]*Sinh[x]^3))/(45*a*Sqrt[a*Csch[x]^3])}
{1/(a*Csch[x]^3)^(5/2), x, 8, (2*(77*Cosh[x] - 13*Csch[x]^2*(7*Cosh[x] - 3*Csch[x]^2*(3*Cosh[x] - 5*Csch[x]^2*(Cosh[x] - I*Csch[x]*EllipticF[Pi/4 - (I*x)/2, 2]*Sqrt[I*Sinh[x]]))))*Sinh[x]^5)/(1155*a^2*Sqrt[a*Csch[x]^3])}


{(a*Csch[x]^4)^(7/2), x, 4, -((a^3*Cosh[x]*(3003 - 6006*Coth[x]^2 + 9009*Coth[x]^4 - 8580*Coth[x]^6 + 5005*Coth[x]^8 - 1638*Coth[x]^10 + 231*Coth[x]^12)*Sqrt[a*Csch[x]^4]*Sinh[x])/3003)}
{(a*Csch[x]^4)^(5/2), x, 4, (-(1/315))*a^2*Cosh[x]*(315 - 420*Coth[x]^2 + 378*Coth[x]^4 - 180*Coth[x]^6 + 35*Coth[x]^8)*Sqrt[a*Csch[x]^4]*Sinh[x]}
{(a*Csch[x]^4)^(3/2), x, 4, (-(1/15))*a*Cosh[x]*(15 - 10*Coth[x]^2 + 3*Coth[x]^4)*Sqrt[a*Csch[x]^4]*Sinh[x]}
{(a*Csch[x]^4)^(1/2), x, 2, (-Cosh[x])*Sqrt[a*Csch[x]^4]*Sinh[x]}
{1/(a*Csch[x]^4)^(1/2), x, 2, -((Csch[x]^2*(x - Cosh[x]*Sinh[x]))/(2*Sqrt[a*Csch[x]^4]))}
{1/(a*Csch[x]^4)^(3/2), x, 4, -((Csch[x]^2*(15*x - 15*Cosh[x]*Sinh[x] + 10*Cosh[x]*Sinh[x]^3 - 8*Cosh[x]*Sinh[x]^5))/(48*a*Sqrt[a*Csch[x]^4]))}
{1/(a*Csch[x]^4)^(5/2), x, 6, -((Csch[x]^2*(315*x - 315*Cosh[x]*Sinh[x] + 210*Cosh[x]*Sinh[x]^3 - 168*Cosh[x]*Sinh[x]^5 + 144*Cosh[x]*Sinh[x]^7 - 128*Cosh[x]*Sinh[x]^9))/(1280*a^2*Sqrt[a*Csch[x]^4]))}


(* ::Subsection::Closed:: *)
(*(a+b Csch[c+d x])^n		where a^2+b^2 is zero*)


(* Integrands of the form (a+b*Csch[c+d*x])^n where a^2+b^2 is zero *)
{1/(a + I*a*Csch[a+b*x]), x, 3, x/a + (I*Cosh[a + b*x])/(a*b*(1 - I*Sinh[a + b*x]))}
{1/(a - I*a*Csch[a+b*x]), x, 3, x/a - (I*Cosh[a + b*x])/(a*b*(1 + I*Sinh[a + b*x]))}

{Sqrt[3 + 3*I*Csch[x]], x, 1, (2*Sqrt[3]*ArcTan[Sqrt[-1 + I*Csch[x]]]*Coth[x])/(Sqrt[-1 + I*Csch[x]]*Sqrt[1 + I*Csch[x]])}
{Sqrt[3 - 3*I*Csch[x]], x, 1, (2*Sqrt[3]*ArcTan[Sqrt[-1 - I*Csch[x]]]*Coth[x])/(Sqrt[-1 - I*Csch[x]]*Sqrt[1 - I*Csch[x]])}
{Sqrt[-3 + 3*I*Csch[x]], x, 1, -((2*Sqrt[3]*ArcTan[Sqrt[-1 - I*Csch[x]]]*Coth[x])/(Sqrt[-1 - I*Csch[x]]*Sqrt[-1 + I*Csch[x]]))}
{Sqrt[-3 - 3*I*Csch[x]], x, 1, -((2*Sqrt[3]*ArcTan[Sqrt[-1 + I*Csch[x]]]*Coth[x])/(Sqrt[-1 - I*Csch[x]]*Sqrt[-1 + I*Csch[x]]))}
{Sqrt[a + a*I*Csch[x]], x, 1, (2*a*ArcTan[Sqrt[-1 + I*Csch[x]]]*Coth[x])/(Sqrt[-1 + I*Csch[x]]*Sqrt[a + I*a*Csch[x]])}
{Sqrt[a - a*I*Csch[x]], x, 1, (2*a*ArcTan[Sqrt[-1 - I*Csch[x]]]*Coth[x])/(Sqrt[-1 - I*Csch[x]]*Sqrt[a - I*a*Csch[x]])}

{1/Sqrt[a + I*a*Csch[x]], x, 1, -(((Sqrt[2]*ArcTan[(Sqrt[2]*Sqrt[a])/Sqrt[-a + I*a*Csch[x]]] + 2*ArcTan[Sqrt[-a + I*a*Csch[x]]/Sqrt[a]])*Sqrt[-a + I*a*Csch[x]]*Sqrt[a + I*a*Csch[x]]*Tanh[x])/a^(3/2))}
{1/Sqrt[a - I*a*Csch[x]], x, 1, -(((Sqrt[2]*ArcTan[(Sqrt[2]*Sqrt[a])/Sqrt[-a - I*a*Csch[x]]] + 2*ArcTan[Sqrt[-a - I*a*Csch[x]]/Sqrt[a]])*Sqrt[-a - I*a*Csch[x]]*Sqrt[a - I*a*Csch[x]]*Tanh[x])/a^(3/2))}


(* ::Subsection::Closed:: *)
(*(a+b Csch[c+d x])^n		where a^2+b^2 is nonzero*)


(*Integrands of the form (a+b*Csch[x])^m where m is an integer *)
{(a + b*Csch[x]), x, 2, a*x - b*ArcCoth[Cosh[x]]}
{(a + b*Csch[x])^2, x, 4, a^2*x - 2*a*b*ArcCoth[Cosh[x]] - b^2*Coth[x]}
{(a + b*Csch[x])^3, x, 6, a^3*x - 3*a^2*b*ArcCoth[Cosh[x]] + (1/2)*b^3*ArcCoth[Cosh[x]] - 3*a*b^2*Coth[x] - (1/2)*b^3*Coth[x]*Csch[x]}

{1/(3 + 5*I*Csch[x]), x, 3, x/3 - (5/6)*I*ArcTan[(1/4)*(3 - 5*I*Tanh[x/2])]}
{1/(a + b*Csch[x]), x, 3, x/a + (2*b*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a*Sqrt[a^2 + b^2])}
{1/(a + b*Csch[x])^2, x, 6, x/a^2 - (2*b^3*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2*(a^2 + b^2)^(3/2)) + (4*b*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2*Sqrt[a^2 + b^2]) - (b^2*Cosh[x])/(a*(a^2 + b^2)*(b + a*Sinh[x]))}
{1/(a + b*Csch[x])^3, x, 9, x/a^3 - (b^3*(a^2 - 2*b^2)*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^3*(a^2 + b^2)^(5/2)) - (6*b^3*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^3*(a^2 + b^2)^(3/2)) + (6*b*ArcTanh[(a - b*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^3*Sqrt[a^2 + b^2]) + (b^3*Cosh[x])/(2*a^2*(a^2 + b^2)*(b + a*Sinh[x])^2) + (3*b^4*Cosh[x])/(2*a^2*(a^2 + b^2)^2*(b + a*Sinh[x])) - (3*b^2*Cosh[x])/(a^2*(a^2 + b^2)*(b + a*Sinh[x]))}


(* ::Subsection::Closed:: *)
(*(a+b Csch[c+d x]^n)^m*)


(*Integrands of the form (a+b*Csch[x]^2)^m where m is an integer *)
{(a + b*Csch[x]^2), x, 2, a*x - b*Coth[x]}
{(a + b*Csch[x]^2)^2, x, 5, a^2*x - 2*a*b*Coth[x] + b^2*Coth[x] - (1/3)*b^2*Coth[x]^3}
{(a + b*Csch[x]^2)^3, x, 8, a^3*x - 3*a^2*b*Coth[x] + 3*a*b^2*Coth[x] - b^3*Coth[x] - a*b^2*Coth[x]^3 + (2/3)*b^3*Coth[x]^3 - (1/5)*b^3*Coth[x]^5}

{1/(a + b*Csch[x]^2), x, 5, x/a + (Sqrt[b]*ArcTan[(Sqrt[b]*Coth[x])/Sqrt[a - b]])/(a*Sqrt[a - b])}
{1/(a + b*Csch[x]^2)^2, x, 8, x/a^2 + (2*Sqrt[b]*ArcTan[(Sqrt[b]*Coth[x])/Sqrt[a - b]])/(a^2*Sqrt[a - b]) + ((a - 2*b)*Sqrt[b]*ArcTan[(Sqrt[a - b]*Tanh[x])/Sqrt[b]])/(2*a^2*(a - b)^(3/2)) - (b*Sinh[2*x])/(2*a*(a - b)*(a - 2*b - a*Cosh[2*x]))}
(* {1/(a + b*Csch[x]^2)^3, x, 12, x/a^3 + (3*Sqrt[b]*ArcTan[(Sqrt[b]*Coth[x])/Sqrt[a - b]])/(a^3*Sqrt[a - b]) - ((a^2 + 2*(a - 2*b)^2)*Sqrt[b]*ArcTan[(Sqrt[a - b]*Tanh[x])/Sqrt[b]])/(8*a^3*(a - b)^(5/2)) + (3*(a - 2*b)*Sqrt[b]*ArcTan[(Sqrt[a - b]*Tanh[x])/Sqrt[b]])/(2*a^3*(a - b)^(3/2)) - (b^2*Sinh[2*x])/(2*a^2*(a - b)*(a - 2*b - a*Cosh[2*x])^2) + (3*(a - 2*b)*b*Sinh[2*x])/(8*a^2*(a - b)^2*(a - 2*b - a*Cosh[2*x])) - (3*b*Sinh[2*x])/(2*a^2*(a - b)*(a - 2*b - a*Cosh[2*x]))} *)


(* Integrands of the form (a+b*Csch[x]^2)^m where m is a half-integer *)
{Sqrt[1 + Csch[x]^2], x, 3, Sqrt[Coth[x]^2]*Log[Sinh[x]]*Tanh[x]}
{Sqrt[1 - Csch[x]^2], x, 4, ArcSin[Coth[x]/Sqrt[2]] + ArcTanh[Coth[x]/Sqrt[2 - Coth[x]^2]]}
{Sqrt[-1 + Csch[x]^2], x, 4, -ArcTan[Coth[x]/Sqrt[-2 + Coth[x]^2]] - ArcTanh[Coth[x]/Sqrt[-2 + Coth[x]^2]]}
{Sqrt[-1 - Csch[x]^2], x, 3, Sqrt[-Coth[x]^2]*Log[Sinh[x]]*Tanh[x]}
{Sqrt[a + b*Csch[x]^2], x, 4, Sqrt[a]*ArcTanh[(Sqrt[a]*Coth[x])/Sqrt[a + b*Csch[x]^2]] - Sqrt[b]*ArcTanh[(Sqrt[b]*Coth[x])/Sqrt[a + b*Csch[x]^2]]}

{1/Sqrt[1 + Csch[x]^2], x, 3, (Coth[x]*Log[Cosh[x]])/Sqrt[Coth[x]^2]}
{1/Sqrt[1 - Csch[x]^2], x, 2, ArcTanh[Coth[x]/Sqrt[2 - Coth[x]^2]]}
{1/Sqrt[-1 + Csch[x]^2], x, 2, ArcTan[Coth[x]/Sqrt[-2 + Coth[x]^2]]}
{1/Sqrt[-1 - Csch[x]^2], x, 3, (Coth[x]*Log[Cosh[x]])/Sqrt[-Coth[x]^2]}
{1/Sqrt[a + b*Csch[x]^2], x, 2, ArcTanh[(Sqrt[a]*Coth[x])/Sqrt[a + b*Csch[x]^2]]/Sqrt[a]}

{(1 + Csch[x]^2)^(3/2), x, 4, (-(1/2))*(Coth[x]^2)^(3/2)*Tanh[x] + Sqrt[Coth[x]^2]*Log[Sinh[x]]*Tanh[x]}
{(1 - Csch[x]^2)^(3/2), x, 7, 2*ArcSin[Coth[x]/Sqrt[2]] + ArcTanh[Coth[x]/Sqrt[2 - Coth[x]^2]] + (1/2)*Coth[x]*Sqrt[2 - Coth[x]^2]}
{(-1 + Csch[x]^2)^(3/2), x, 8, ArcTan[Coth[x]/Sqrt[-2 + Coth[x]^2]] + 2*ArcTanh[Coth[x]/Sqrt[-2 + Coth[x]^2]] - (1/2)*Coth[x]*Sqrt[-2 + Coth[x]^2]}
{(-1 - Csch[x]^2)^(3/2), x, 4, (1/2)*Coth[x]*Sqrt[-Coth[x]^2] - Sqrt[-Coth[x]^2]*Log[Sinh[x]]*Tanh[x]}
{(a + b*Csch[x]^2)^(3/2), x, 7, a^(3/2)*ArcTanh[(Sqrt[a]*Coth[x])/Sqrt[a + b*Csch[x]^2]] - (3/2)*a*Sqrt[b]*ArcTanh[(Sqrt[b]*Coth[x])/Sqrt[a + b*Csch[x]^2]] + (1/2)*b^(3/2)*ArcTanh[(Sqrt[b]*Coth[x])/Sqrt[a + b*Csch[x]^2]] - (1/2)*b*Coth[x]*Sqrt[a + b*Csch[x]^2]}


(* ::Subsection::Closed:: *)
(*x^m Csch[a+b Log[c x^n]]^p*)


{Csch[a + b*Log[c*x^n]], x, 0, Int[Csch[a + b*Log[c*x^n]], x]}
{Csch[a + b*Log[c*x^n]]^2, x, 0, Int[Csch[a + b*Log[c*x^n]]^2, x]}
{Csch[a + b*Log[c*x^n]]^3, x, 1, -((x*Csch[a + b*Log[c*x^n]])/(2*b^2*n^2)) - (x*Coth[a + b*Log[c*x^n]]*Csch[a + b*Log[c*x^n]])/(2*b*n) + ((1 - b^2*n^2)*Int[Csch[a + b*Log[c*x^n]], x])/(2*b^2*n^2)}
{Csch[a + b*Log[c*x^n]]^4, x, 1, -((x*Csch[a + b*Log[c*x^n]]^2)/(6*b^2*n^2)) - (x*Coth[a + b*Log[c*x^n]]*Csch[a + b*Log[c*x^n]]^2)/(3*b*n) + ((1 - 4*b^2*n^2)*Int[Csch[a + b*Log[c*x^n]]^2, x])/(6*b^2*n^2)}

{2*b^2*n^2*Csch[a + b*Log[c*x^n]]^3 - (1 - b^2*n^2)*Csch[a + b*Log[c*x^n]], x, 2, (-x)*Csch[a + b*Log[c*x^n]] - b*n*x*Coth[a + b*Log[c*x^n]]*Csch[a + b*Log[c*x^n]]}


{Csch[a + 2*Log[c*x^(1/2)]]^3, x, 1, (-(1/2))*x*Csch[a + 2*Log[c*Sqrt[x]]] - (1/2)*x*Coth[a + 2*Log[c*Sqrt[x]]]*Csch[a + 2*Log[c*Sqrt[x]]]}
{Csch[a + 2*Log[c/x^(1/2)]]^3, x, 1, (-(1/2))*x*Csch[a + 2*Log[c/Sqrt[x]]] + (1/2)*x*Coth[a + 2*Log[c/Sqrt[x]]]*Csch[a + 2*Log[c/Sqrt[x]]]}
{Csch[a + 1/(n*(-2 + p))*Log[c*x^n]]^p, x, 1, -(((2 - p)*x*Csch[a - Log[c*x^n]/(n*(2 - p))]^(-2 + p))/(1 - p)) - ((2 - p)*x*Cosh[a - Log[c*x^n]/(n*(2 - p))]*Csch[a - Log[c*x^n]/(n*(2 - p))]^(-1 + p))/(1 - p)}
{Csch[a - 1/(n*(-2 + p))*Log[c*x^n]]^p, x, 1, -(((2 - p)*x*Csch[a + Log[c*x^n]/(n*(2 - p))]^(-2 + p))/(1 - p)) + ((2 - p)*x*Cosh[a + Log[c*x^n]/(n*(2 - p))]*Csch[a + Log[c*x^n]/(n*(2 - p))]^(-1 + p))/(1 - p)}


(* Integrands of the form Csch[a+b*Log[c*x^n]]^p/x where p is an integer *)
{Csch[a + b*Log[c*x^n]]/x, x, 2, -(ArcCoth[Cosh[a + b*Log[c*x^n]]]/(b*n))}
{Csch[a + b*Log[c*x^n]]^2/x, x, 2, -(Coth[a + b*Log[c*x^n]]/(b*n))}
{Csch[a + b*Log[c*x^n]]^3/x, x, 3, ArcCoth[Cosh[a + b*Log[c*x^n]]]/(2*b*n) - (Coth[a + b*Log[c*x^n]]*Csch[a + b*Log[c*x^n]])/(2*b*n)}
{Csch[a + b*Log[c*x^n]]^4/x, x, 3, Coth[a + b*Log[c*x^n]]/(b*n) - Coth[a + b*Log[c*x^n]]^3/(3*b*n)}
{Csch[a + b*Log[c*x^n]]^5/x, x, 4, -((3*ArcCoth[Cosh[a + b*Log[c*x^n]]])/(8*b*n)) + (3*Coth[a + b*Log[c*x^n]]*Csch[a + b*Log[c*x^n]])/(8*b*n) - (Coth[a + b*Log[c*x^n]]*Csch[a + b*Log[c*x^n]]^3)/(4*b*n)}


(* Integrands of the form Csch[a+b*Log[c*x^n]]^p/x where p is a half-integer *)
{Csch[a + b*Log[c*x^n]]^(5/2)/x, x, 5, -((2*Cosh[a + b*Log[c*x^n]]*Csch[a + b*Log[c*x^n]]^(3/2))/(3*b*n)) - (2*I*Sqrt[Csch[a + b*Log[c*x^n]]]*EllipticF[Pi/4 - (1/2)*I*(a + b*Log[c*x^n]), 2]*Sqrt[I*Sinh[a + b*Log[c*x^n]]])/(3*b*n)}
{Csch[a + b*Log[c*x^n]]^(3/2)/x, x, 5, -((2*Cosh[a + b*Log[c*x^n]]*Sqrt[Csch[a + b*Log[c*x^n]]])/(b*n)) + (2*I*EllipticE[Pi/4 - (1/2)*I*(a + b*Log[c*x^n]), 2])/(b*n*Sqrt[Csch[a + b*Log[c*x^n]]]*Sqrt[I*Sinh[a + b*Log[c*x^n]]])}
{Sqrt[Csch[a + b*Log[c*x^n]]]/x, x, 4, (2*I*Sqrt[Csch[a + b*Log[c*x^n]]]*EllipticF[Pi/4 - (1/2)*I*(a + b*Log[c*x^n]), 2]*Sqrt[I*Sinh[a + b*Log[c*x^n]]])/(b*n)}
{1/(x*Sqrt[Csch[a + b*Log[c*x^n]]]), x, 4, (2*I*EllipticE[Pi/4 - (1/2)*I*(a + b*Log[c*x^n]), 2])/(b*n*Sqrt[Csch[a + b*Log[c*x^n]]]*Sqrt[I*Sinh[a + b*Log[c*x^n]]])}
{1/(x*Csch[a + b*Log[c*x^n]]^(3/2)), x, 5, (2*Cosh[a + b*Log[c*x^n]])/(3*b*n*Sqrt[Csch[a + b*Log[c*x^n]]]) - (2*I*Sqrt[Csch[a + b*Log[c*x^n]]]*EllipticF[Pi/4 - (1/2)*I*(a + b*Log[c*x^n]), 2]*Sqrt[I*Sinh[a + b*Log[c*x^n]]])/(3*b*n)}
{1/(x*Csch[a + b*Log[c*x^n]]^(5/2)), x, 5, (2*Cosh[a + b*Log[c*x^n]])/(5*b*n*Csch[a + b*Log[c*x^n]]^(3/2)) - (6*I*EllipticE[Pi/4 - (1/2)*I*(a + b*Log[c*x^n]), 2])/(5*b*n*Sqrt[Csch[a + b*Log[c*x^n]]]*Sqrt[I*Sinh[a + b*Log[c*x^n]]])}


(* ::Subsection::Closed:: *)
(*Miscellaneous integrands involving one cosecant*)


(* Integrands of the form x^m*Csch[x]^n where m is an integer and n is a half-integer *)
{x/Csch[x]^(3/2) + x*Sqrt[Csch[x]]/3, x, 2, -(4/(9*Csch[x]^(3/2))) + (2*x*Cosh[x])/(3*Sqrt[Csch[x]])}
{x/Csch[x]^(5/2) + 3*x/(5*Sqrt[Csch[x]]), x, 2, -(4/(25*Csch[x]^(5/2))) + (2*x*Cosh[x])/(5*Csch[x]^(3/2))}
{x/Csch[x]^(7/2) - (5/21)*x*Sqrt[Csch[x]], x, 3, -(4/(49*Csch[x]^(7/2))) + (2*x*Cosh[x])/(7*Csch[x]^(5/2)) + 20/(63*Csch[x]^(3/2)) - (10*x*Cosh[x])/(21*Sqrt[Csch[x]])}
{x^2/Csch[x]^(3/2) + (1/3)*x^2*Sqrt[Csch[x]], x, 6, -((8*x)/(9*Csch[x]^(3/2))) + (16*Cosh[x])/(27*Sqrt[Csch[x]]) + (2*x^2*Cosh[x])/(3*Sqrt[Csch[x]]) - (16/27)*I*Sqrt[Csch[x]]*EllipticF[Pi/4 - (I*x)/2, 2]*Sqrt[I*Sinh[x]]}
