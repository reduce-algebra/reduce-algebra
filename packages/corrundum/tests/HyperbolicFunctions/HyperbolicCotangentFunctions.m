(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Hyperbolic Cotangents*)


(* ::Subsection::Closed:: *)
(*Coth[a+b x]^n*)


(* Integrands of the form Coth[a+b*x]^n where n is a positive integer *)
{Coth[a+b*x], x, 1, Log[Sinh[a+b*x]]/b}
{Coth[a+b*x]^2, x, 1, x - Coth[a+b*x]/b}
{Coth[a+b*x]^3, x, 2, -(Coth[a + b*x]^2/(2*b)) + Log[Sinh[a + b*x]]/b}
{Coth[a+b*x]^4, x, 2, x - Coth[a + b*x]/b - Coth[a + b*x]^3/(3*b)}
{Coth[a+b*x]^5, x, 3, -(Coth[a + b*x]^2/(2*b)) - Coth[a + b*x]^4/(4*b) + Log[Sinh[a + b*x]]/b}


(* Integrands of the form Coth[a+b*x]^n where n is a half-integer *)
{Coth[a+b*x]^(1/2), x, 5, -(ArcTan[Sqrt[Coth[a + b*x]]]/b) + ArcTanh[Sqrt[Coth[a + b*x]]]/b}
{Coth[a+b*x]^(3/2), x, 6, ArcTan[Sqrt[Coth[a + b*x]]]/b + ArcTanh[Sqrt[Coth[a + b*x]]]/b - (2*Sqrt[Coth[a + b*x]])/b}
{Coth[a+b*x]^(5/2), x, 6, -(ArcTan[Sqrt[Coth[a + b*x]]]/b) + ArcTanh[Sqrt[Coth[a + b*x]]]/b - (2*Coth[a + b*x]^(3/2))/(3*b)}

{1/Coth[a+b*x]^(1/2), x, 5, ArcTan[Sqrt[Coth[a + b*x]]]/b + ArcTanh[Sqrt[Coth[a + b*x]]]/b}
{1/Coth[a+b*x]^(3/2), x, 6, -(ArcTan[Sqrt[Coth[a + b*x]]]/b) + ArcTanh[Sqrt[Coth[a + b*x]]]/b - 2/(b*Sqrt[Coth[a + b*x]])}
{1/Coth[a+b*x]^(5/2), x, 6, ArcTan[Sqrt[Coth[a + b*x]]]/b + ArcTanh[Sqrt[Coth[a + b*x]]]/b - 2/(3*b*Coth[a + b*x]^(3/2))}

{Coth[8*x]^(1/3), x, 7, (-(1/16))*Sqrt[3]*ArcTan[(1 + 2*Coth[8*x]^(2/3))/Sqrt[3]] - (1/16)*Log[1 - Coth[8*x]^(2/3)] + (1/32)*Log[1 + Coth[8*x]^(2/3) + Coth[8*x]^(4/3)]}


(* ::Subsection::Closed:: *)
(*x^m Coth[a+b x]^n*)


(* Integrands of the form x^m*Coth[a+b*x]^n where m and n are integers *)
{x*Coth[a + b*x], x, 4, -(x^2/2) + (x*Log[1 - E^(2*a + 2*b*x)])/b + PolyLog[2, E^(2*a + 2*b*x)]/(2*b^2)}
{x*Coth[a + b*x]^2, x, 3, x^2/2 - (x*Coth[a + b*x])/b + Log[Sinh[a + b*x]]/b^2}
{x*Coth[a + b*x]^3, x, 6, -(x^2/2) - Coth[a + b*x]/(2*b^2) - (x*Csch[a + b*x]^2)/(2*b) + (x*Log[1 - E^(2*a + 2*b*x)])/b + PolyLog[2, E^(2*a + 2*b*x)]/(2*b^2)}

{x^2*Coth[a + b*x], x, 5, -(x^3/3) + (x^2*Log[1 - E^(2*a + 2*b*x)])/b + (x*PolyLog[2, E^(2*a + 2*b*x)])/b^2 - PolyLog[3, E^(2*a + 2*b*x)]/(2*b^3)}
{x^2*Coth[a + b*x]^2, x, 6, -(x^2/b) + x^3/3 - (x^2*Coth[a + b*x])/b + (2*x*Log[1 - E^(2*a + 2*b*x)])/b^2 + PolyLog[2, E^(2*a + 2*b*x)]/b^3}
{x^2*Coth[a + b*x]^3, x, 9, -(x^3/3) - (x*Coth[a + b*x])/b^2 - (x^2*Csch[a + b*x]^2)/(2*b) + (x^2*Log[1 - E^(2*a + 2*b*x)])/b + Log[Sinh[a + b*x]]/b^3 + (x*PolyLog[2, E^(2*a + 2*b*x)])/b^2 - PolyLog[3, E^(2*a + 2*b*x)]/(2*b^3)}

{x^3*Coth[a + b*x], x, 6, -(x^4/4) + (x^3*Log[1 - E^(2*a + 2*b*x)])/b + (3*x^2*PolyLog[2, E^(2*a + 2*b*x)])/(2*b^2) - (3*x*PolyLog[3, E^(2*a + 2*b*x)])/(2*b^3) + (3*PolyLog[4, E^(2*a + 2*b*x)])/(4*b^4)}
{x^3*Coth[a + b*x]^2, x, 7, -(x^3/b) + x^4/4 - (x^3*Coth[a + b*x])/b + (3*x^2*Log[1 - E^(2*a + 2*b*x)])/b^2 + (3*x*PolyLog[2, E^(2*a + 2*b*x)])/b^3 - (3*PolyLog[3, E^(2*a + 2*b*x)])/(2*b^4)}
{x^3*Coth[a + b*x]^3, x, 13, -((3*x^2)/(2*b^2)) - x^4/4 - (3*x^2*Coth[a + b*x])/(2*b^2) - (x^3*Csch[a + b*x]^2)/(2*b) + (3*x*Log[1 - E^(2*a + 2*b*x)])/b^3 + (x^3*Log[1 - E^(2*a + 2*b*x)])/b + (3*(1 + b^2*x^2)*PolyLog[2, E^(2*a + 2*b*x)])/(2*b^4) - (3*x*PolyLog[3, E^(2*a + 2*b*x)])/(2*b^3) + (3*PolyLog[4, E^(2*a + 2*b*x)])/(4*b^4)}

{Coth[a + b*x]/x, x, 0, Int[Coth[a + b*x]/x, x]}
{Coth[a + b*x]^2/x, x, 0, Int[Coth[a + b*x]^2/x, x]}
{Coth[a + b*x]^3/x, x, 0, Int[Coth[a + b*x]^3/x, x]}

{Coth[a + b*x]/x^2, x, 0, Int[Coth[a + b*x]/x^2, x]}
{Coth[a + b*x]^2/x^2, x, 0, Int[Coth[a + b*x]^2/x^2, x]}
{Coth[a + b*x]^3/x^2, x, 0, Int[Coth[a + b*x]^3/x^2, x]}

{Coth[a + b*x]/x^3, x, 0, Int[Coth[a + b*x]/x^3, x]}
{Coth[a + b*x]^2/x^3, x, 0, Int[Coth[a + b*x]^2/x^3, x]}
{Coth[a + b*x]^3/x^3, x, 0, Int[Coth[a + b*x]^3/x^3, x]}


(* ::Subsection::Closed:: *)
(*(a Coth[a+b x]^n)^m*)


(* Integrands of the form (a*Coth[x]^n)^m where n is an integer and m is a half-integer *)
{Sqrt[a*Coth[x]], x, 5, (-Sqrt[a])*ArcTan[Sqrt[a*Coth[x]]/Sqrt[a]] + Sqrt[a]*ArcTanh[Sqrt[a*Coth[x]]/Sqrt[a]]}
{Sqrt[a*Coth[x]^2], x, 2, Sqrt[a*Coth[x]^2]*Log[Sinh[x]]*Tanh[x]}
{Sqrt[a*Coth[x]^3], x, 8, ((ArcTan[Sqrt[Coth[x]]] + ArcTanh[Sqrt[Coth[x]]] - 2*Sqrt[Coth[x]])*Sqrt[a*Coth[x]^3])/Coth[x]^(3/2)}
{Sqrt[a*Coth[x]^4], x, 2, (-Sqrt[a*Coth[x]^4])*Tanh[x] + x*Sqrt[a*Coth[x]^4]*Tanh[x]^2}

{(a*Coth[x])^(3/2),x, 7, a^(3/2)*ArcTan[Sqrt[a*Coth[x]]/Sqrt[a]] + a^(3/2)*ArcTanh[Sqrt[a*Coth[x]]/Sqrt[a]] - 2*a*Sqrt[a*Coth[x]]}
{(a*Coth[x]^2)^(3/2),x, 3, (-(1/2))*a*Coth[x]*Sqrt[a*Coth[x]^2] + a*Sqrt[a*Coth[x]^2]*Log[Sinh[x]]*Tanh[x]}
{(a*Coth[x]^3)^(3/2),x, 9, -((a*Sqrt[a*Coth[x]^3]*(21*ArcTan[Sqrt[Coth[x]]] - 21*ArcTanh[Sqrt[Coth[x]]] + 14*Coth[x]^(3/2) + 6*Coth[x]^(7/2)))/(21*Coth[x]^(3/2)))}
{(a*Coth[x]^4)^(3/2),x, 4, (-(1/3))*a*Coth[x]*Sqrt[a*Coth[x]^4] - (1/5)*a*Coth[x]^3*Sqrt[a*Coth[x]^4] - a*Sqrt[a*Coth[x]^4]*Tanh[x] + a*x*Sqrt[a*Coth[x]^4]*Tanh[x]^2}

{1/Sqrt[a*Coth[x]], x, 6, ArcTan[Sqrt[a*Coth[x]]/Sqrt[a]]/Sqrt[a] + ArcTanh[Sqrt[a*Coth[x]]/Sqrt[a]]/Sqrt[a]}
{1/Sqrt[a*Coth[x]^2], x, 2, (Coth[x]*Log[Cosh[x]])/Sqrt[a*Coth[x]^2]}
{1/Sqrt[a*Coth[x]^3], x, 10, -(((2 + (ArcTan[Sqrt[Coth[x]]] - ArcTanh[Sqrt[Coth[x]]])*Sqrt[Coth[x]])*Coth[x])/Sqrt[a*Coth[x]^3])}
{1/Sqrt[a*Coth[x]^4], x, 2, -(Coth[x]/Sqrt[a*Coth[x]^4]) + (x*Coth[x]^2)/Sqrt[a*Coth[x]^4]}


(* ::Subsection::Closed:: *)
(*(a+b Coth[c+d x])^n		where a^2 - b^2 is zero*)


(* Integrands of the form (a+b*Coth[x])^n where a^2-b^2 is zero *)
{(1 + Coth[x])^3, x, 6, 4*x - 3*Coth[x] - Coth[x]^2/2 + 4*Log[Sinh[x]]}
{(1 + Coth[x])^2, x, 4, 2*x - Coth[x] + 2*Log[Sinh[x]]}
{1/(1 + Coth[x]), x, 1, x/2 - 1/(2*(1 + Coth[x]))}
{1/(1 + Coth[x])^2, x, 2, x/4 - 1/(4*(1 + Coth[x])^2) - 1/(4*(1 + Coth[x]))}
{1/(1 + Coth[x])^3, x, 3, x/8 - 1/(6*(1 + Coth[x])^3) - 1/(8*(1 + Coth[x])^2) - 1/(8*(1 + Coth[x]))}

{(1 + Coth[x])^(5/2), x, 3, 4*Sqrt[2]*ArcCoth[Sqrt[1 + Coth[x]]/Sqrt[2]] - 4*Sqrt[1 + Coth[x]] - (2/3)*(1 + Coth[x])^(3/2)}
{(1 + Coth[x])^(3/2), x, 2, 2*Sqrt[2]*ArcCoth[Sqrt[1 + Coth[x]]/Sqrt[2]] - 2*Sqrt[1 + Coth[x]]}
{(1 + Coth[x])^(1/2), x, 1, Sqrt[2]*ArcCoth[Sqrt[1 + Coth[x]]/Sqrt[2]]}
{1/(1 + Coth[x])^(1/2), x, 2, ArcCoth[Sqrt[1 + Coth[x]]/Sqrt[2]]/Sqrt[2] - 1/Sqrt[1 + Coth[x]]}
{1/(1 + Coth[x])^(3/2), x, 3, ArcCoth[Sqrt[1 + Coth[x]]/Sqrt[2]]/(2*Sqrt[2]) - 1/(3*(1 + Coth[x])^(3/2)) - 1/(2*Sqrt[1 + Coth[x]])}
{1/(1 + Coth[x])^(5/2), x, 4, ArcCoth[Sqrt[1 + Coth[x]]/Sqrt[2]]/(4*Sqrt[2]) - 1/(5*(1 + Coth[x])^(5/2)) - 1/(6*(1 + Coth[x])^(3/2)) - 1/(4*Sqrt[1 + Coth[x]])}


(* ::Subsection::Closed:: *)
(*(a+b Coth[c+d x])^n		where a^2 - b^2 is nonzero*)


(* Integrands of the form (a+b*Coth[c+d*x])^n where a^2-b^2 is nonzero *)
{(a + b*Coth[c + d*x])^3, x, 6, a^3*x + 3*a*b^2*x - (3*a*b^2*Coth[c + d*x])/d - (b^3*Coth[c + d*x]^2)/(2*d) + (3*a^2*b*Log[Sinh[c + d*x]])/d + (b^3*Log[Sinh[c + d*x]])/d}
{(a + b*Coth[c + d*x])^2, x, 4, a^2*x + b^2*x - (b^2*Coth[c + d*x])/d + (2*a*b*Log[Sinh[c + d*x]])/d}
{1/(4 - 6*Coth[x]), x, 2, -(x/5) - (3/10)*Log[-3*Cosh[x] + 2*Sinh[x]]}
{1/(a + b*Coth[c + d*x]),x, 1, (a*x)/(a^2 - b^2) - (b*Log[b*Cosh[c + d*x] + a*Sinh[c + d*x]])/((a^2 - b^2)*d)}
{1/(a + b*Coth[c + d*x])^2,x, 8, b/((a^2 - b^2)*d*(a + b*Coth[c + d*x])) - Log[1 - Coth[c + d*x]]/(2*(a + b)^2*d) + Log[1 + Coth[c + d*x]]/(2*(a - b)^2*d) - (2*a*b*Log[a + b*Coth[c + d*x]])/((a^2 - b^2)^2*d)}
{1/(a + b*Coth[c + d*x])^3,x, 9, b/(2*(a^2 - b^2)*d*(a + b*Coth[c + d*x])^2) + (2*a*b)/((a^2 - b^2)^2*d*(a + b*Coth[c + d*x])) - Log[1 - Coth[c + d*x]]/(2*(a + b)^3*d) + Log[1 + Coth[c + d*x]]/(2*(a - b)^3*d) - (b*(3*a^2 + b^2)*Log[a + b*Coth[c + d*x]])/((a^2 - b^2)^3*d)}

{Sqrt[a + b*Coth[c + d*x]], x, 5, -((Sqrt[a - b]*ArcTanh[Sqrt[a + b*Coth[c + d*x]]/Sqrt[a - b]])/d) + (Sqrt[a + b]*ArcTanh[Sqrt[a + b*Coth[c + d*x]]/Sqrt[a + b]])/d}
{1/Sqrt[a + b*Coth[c + d*x]], x, 5, -(ArcTanh[Sqrt[a + b*Coth[c + d*x]]/Sqrt[a - b]]/(Sqrt[a - b]*d)) + ArcTanh[Sqrt[a + b*Coth[c + d*x]]/Sqrt[a + b]]/(Sqrt[a + b]*d)}


(* ::Subsection::Closed:: *)
(*(a+b Coth[c+d x]^n)^m*)


{1/(1 - 2*Coth[x]^2), x, 1, -x + Sqrt[2]*ArcTanh[Sqrt[2]*Coth[x]]}

{1/(1 + Coth[x]^3), x, 6, x/2 - (2*ArcTan[(1 - 2*Coth[x])/Sqrt[3]])/(3*Sqrt[3]) - 1/(6*(1 + Coth[x])), -((2*ArcTan[(1 - 2*Coth[x])/Sqrt[3]])/(3*Sqrt[3])) - 1/(6*(1 + Coth[x])) - (1/2)*I*Pi*Mods[1/2 + (I*x)/Pi]}


(* Integrands of the form (a+b*Coth[x]^2)^m where m is a half-integer *)
{Sqrt[1 + Coth[x]^2], x, 4, -ArcCsch[Tanh[x]] + Sqrt[2]*ArcTanh[(Sqrt[2]*Coth[x])/Sqrt[1 + Coth[x]^2]]}
{Sqrt[1 - Coth[x]^2], x, 2, ArcCsc[Tanh[x]]}
{Sqrt[-1 + Coth[x]^2], x, 3, -ArcTanh[Coth[x]/Sqrt[Csch[x]^2]]}
{Sqrt[-1 - Coth[x]^2], x, 4, ArcTan[Coth[x]/Sqrt[-1 - Coth[x]^2]] - Sqrt[2]*ArcTan[(Sqrt[2]*Coth[x])/Sqrt[-1 - Coth[x]^2]]}
{Sqrt[a + b*Coth[x]^2], x, 4, (-Sqrt[b])*ArcTanh[(Sqrt[b]*Coth[x])/Sqrt[a + b*Coth[x]^2]] + Sqrt[a + b]*ArcTanh[(Sqrt[a + b]*Coth[x])/Sqrt[a + b*Coth[x]^2]]}

{1/Sqrt[1 + Coth[x]^2], x, 2, ArcTanh[(Sqrt[2]*Coth[x])/Sqrt[1 + Coth[x]^2]]/Sqrt[2]}
{1/Sqrt[1 - Coth[x]^2], x, 2, Coth[x]/Sqrt[-Csch[x]^2]}
{1/Sqrt[-1 + Coth[x]^2], x, 3, Coth[x]/Sqrt[Csch[x]^2]}
{1/Sqrt[-1 - Coth[x]^2], x, 2, ArcTan[(Sqrt[2]*Coth[x])/Sqrt[-1 - Coth[x]^2]]/Sqrt[2]}
{1/Sqrt[a + b*Coth[x]^2], x, 2, ArcTanh[(Sqrt[a + b]*Coth[x])/Sqrt[a + b*Coth[x]^2]]/Sqrt[a + b]}

{(1 + Coth[x]^2)^(3/2), x, 8, (-(5/2))*ArcCsch[Tanh[x]] + 2*Sqrt[2]*ArcTanh[(Sqrt[2]*Coth[x])/Sqrt[1 + Coth[x]^2]] - (1/2)*Coth[x]*Sqrt[1 + Coth[x]^2]}
{(1 - Coth[x]^2)^(3/2), x, 3, (1/2)*ArcCsc[Tanh[x]] + (1/2)*Coth[x]*Sqrt[-Csch[x]^2]}
{(-1 + Coth[x]^2)^(3/2), x, 4, (1/2)*ArcTanh[Coth[x]/Sqrt[Csch[x]^2]] - (1/2)*Coth[x]*Sqrt[Csch[x]^2]}
{(-1 - Coth[x]^2)^(3/2), x, 7, (-(5/2))*ArcTan[Coth[x]/Sqrt[-1 - Coth[x]^2]] + 2*Sqrt[2]*ArcTan[(Sqrt[2]*Coth[x])/Sqrt[-1 - Coth[x]^2]] + (1/2)*Coth[x]*Sqrt[-1 - Coth[x]^2]}
{(a + b*Coth[x]^2)^(3/2), x, 8, (-(3/2))*a*Sqrt[b]*ArcTanh[(Sqrt[b]*Coth[x])/Sqrt[a + b*Coth[x]^2]] - b^(3/2)*ArcTanh[(Sqrt[b]*Coth[x])/Sqrt[a + b*Coth[x]^2]] + (a + b)^(3/2)*ArcTanh[(Sqrt[a + b]*Coth[x])/Sqrt[a + b*Coth[x]^2]] - (1/2)*b*Coth[x]*Sqrt[a + b*Coth[x]^2]}


(* ::Subsection::Closed:: *)
(*x^m Coth[a+b Log[c x^n]]^p*)


(* Integrands of the form Coth[a+b*Log[c*x^n]]^p/x where p is an integer *)
{Coth[a + b*Log[c*x^n]]/x, x, 2, Log[Sinh[a + b*Log[c*x^n]]]/(b*n)}
{Coth[a + b*Log[c*x^n]]^2/x, x, 2, -(Coth[a + b*Log[c*x^n]]/(b*n)) + Log[c*x^n]/n}
{Coth[a + b*Log[c*x^n]]^3/x, x, 3, -(Coth[a + b*Log[c*x^n]]^2/(2*b*n)) + Log[Sinh[a + b*Log[c*x^n]]]/(b*n)}
{Coth[a + b*Log[c*x^n]]^4/x, x, 3, -(Coth[a + b*Log[c*x^n]]/(b*n)) - Coth[a + b*Log[c*x^n]]^3/(3*b*n) + Log[c*x^n]/n}
{Coth[a + b*Log[c*x^n]]^5/x, x, 4, -(Coth[a + b*Log[c*x^n]]^2/(2*b*n)) - Coth[a + b*Log[c*x^n]]^4/(4*b*n) + Log[Sinh[a + b*Log[c*x^n]]]/(b*n)}


(* Integrands of the form Coth[a+b*Log[c*x^n]]^p/x where p is a half-integer *)
{Coth[a + b*Log[c*x^n]]^(5/2)/x, x, 7, -(ArcTan[Sqrt[Coth[a + b*Log[c*x^n]]]]/(b*n)) + ArcTanh[Sqrt[Coth[a + b*Log[c*x^n]]]]/(b*n) - (2*Coth[a + b*Log[c*x^n]]^(3/2))/(3*b*n)}
{Coth[a + b*Log[c*x^n]]^(3/2)/x, x, 7, ArcTan[Sqrt[Coth[a + b*Log[c*x^n]]]]/(b*n) + ArcTanh[Sqrt[Coth[a + b*Log[c*x^n]]]]/(b*n) - (2*Sqrt[Coth[a + b*Log[c*x^n]]])/(b*n)}
{Sqrt[Coth[a + b*Log[c*x^n]]]/x, x, 6, -(ArcTan[Sqrt[Coth[a + b*Log[c*x^n]]]]/(b*n)) + ArcTanh[Sqrt[Coth[a + b*Log[c*x^n]]]]/(b*n)}
{1/(x*Sqrt[Coth[a + b*Log[c*x^n]]]), x, 6, ArcTan[Sqrt[Coth[a + b*Log[c*x^n]]]]/(b*n) + ArcTanh[Sqrt[Coth[a + b*Log[c*x^n]]]]/(b*n)}
{1/(x*Coth[a + b*Log[c*x^n]]^(3/2)), x, 7, -(ArcTan[Sqrt[Coth[a + b*Log[c*x^n]]]]/(b*n)) + ArcTanh[Sqrt[Coth[a + b*Log[c*x^n]]]]/(b*n) - 2/(b*n*Sqrt[Coth[a + b*Log[c*x^n]]])}
{1/(x*Coth[a + b*Log[c*x^n]]^(5/2)), x, 7, ArcTan[Sqrt[Coth[a + b*Log[c*x^n]]]]/(b*n) + ArcTanh[Sqrt[Coth[a + b*Log[c*x^n]]]]/(b*n) - 2/(3*b*n*Coth[a + b*Log[c*x^n]]^(3/2))}
