(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Hyperbolic Tangents*)


(* ::Subsection::Closed:: *)
(*Tanh[a+b x]^n*)


(* Integrands of the form Tanh[a+b*x]^n where n is a positive integer *)
{Tanh[a+b*x], x, 1, Log[Cosh[a+b*x]]/b}
{Tanh[a+b*x]^2, x, 1, x - Tanh[a+b*x]/b}
{Tanh[a+b*x]^3, x, 2, Log[Cosh[a + b*x]]/b - Tanh[a + b*x]^2/(2*b)}
{Tanh[a+b*x]^4, x, 2, x - Tanh[a + b*x]/b - Tanh[a + b*x]^3/(3*b)}
{Tanh[a+b*x]^5, x, 3, Log[Cosh[a + b*x]]/b - Tanh[a + b*x]^2/(2*b) - Tanh[a + b*x]^4/(4*b)}


(* Integrands of the form Tanh[a+b*x]^n where n is a half-integer *)
{Tanh[a+b*x]^(1/2), x, 5, -(ArcTan[Sqrt[Tanh[a + b*x]]]/b) + ArcTanh[Sqrt[Tanh[a + b*x]]]/b}
{Tanh[a+b*x]^(3/2), x, 6, ArcTan[Sqrt[Tanh[a + b*x]]]/b + ArcTanh[Sqrt[Tanh[a + b*x]]]/b - (2*Sqrt[Tanh[a + b*x]])/b}
{Tanh[a+b*x]^(5/2), x, 6, -(ArcTan[Sqrt[Tanh[a + b*x]]]/b) + ArcTanh[Sqrt[Tanh[a + b*x]]]/b - (2*Tanh[a + b*x]^(3/2))/(3*b)}

{1/Tanh[a+b*x]^(1/2), x, 5, ArcTan[Sqrt[Tanh[a + b*x]]]/b + ArcTanh[Sqrt[Tanh[a + b*x]]]/b}
{1/Tanh[a+b*x]^(3/2), x, 6, -(ArcTan[Sqrt[Tanh[a + b*x]]]/b) + ArcTanh[Sqrt[Tanh[a + b*x]]]/b - 2/(b*Sqrt[Tanh[a + b*x]])}
{1/Tanh[a+b*x]^(5/2), x, 6, ArcTan[Sqrt[Tanh[a + b*x]]]/b + ArcTanh[Sqrt[Tanh[a + b*x]]]/b - 2/(3*b*Tanh[a + b*x]^(3/2))}

{Tanh[8*x]^(1/3), x, 7, (-(1/16))*Sqrt[3]*ArcTan[(1 + 2*Tanh[8*x]^(2/3))/Sqrt[3]] - (1/16)*Log[1 - Tanh[8*x]^(2/3)] + (1/32)*Log[1 + Tanh[8*x]^(2/3) + Tanh[8*x]^(4/3)]}


(* ::Subsection::Closed:: *)
(*x^m Tanh[a+b x]^n*)


(* Integrands of the form x^m*Tanh[a+b*x]^n where m and n are integers *)
{x*Tanh[a + b*x], x, 4, -(x^2/2) + (x*Log[1 + E^(2*a + 2*b*x)])/b + PolyLog[2, -E^(2*a + 2*b*x)]/(2*b^2)}
{x*Tanh[a + b*x]^2, x, 3, x^2/2 + Log[Cosh[a + b*x]]/b^2 - (x*Tanh[a + b*x])/b}
{x*Tanh[a + b*x]^3, x, 6, -(x^2/2) + (x*Log[1 + E^(2*a + 2*b*x)])/b + PolyLog[2, -E^(2*a + 2*b*x)]/(2*b^2) + (x*Sech[a + b*x]^2)/(2*b) - Tanh[a + b*x]/(2*b^2)}

{x^2*Tanh[a + b*x], x, 5, -(x^3/3) + (x^2*Log[1 + E^(2*a + 2*b*x)])/b + (x*PolyLog[2, -E^(2*a + 2*b*x)])/b^2 - PolyLog[3, -E^(2*a + 2*b*x)]/(2*b^3)}
{x^2*Tanh[a + b*x]^2, x, 6, -(x^2/b) + x^3/3 + (2*x*Log[1 + E^(2*a + 2*b*x)])/b^2 + PolyLog[2, -E^(2*a + 2*b*x)]/b^3 - (x^2*Tanh[a + b*x])/b}
{x^2*Tanh[a + b*x]^3, x, 9, -(x^3/3) + (x^2*Log[1 + E^(2*a + 2*b*x)])/b + Log[Cosh[a + b*x]]/b^3 + (x*PolyLog[2, -E^(2*a + 2*b*x)])/b^2 - PolyLog[3, -E^(2*a + 2*b*x)]/(2*b^3) + (x^2*Sech[a + b*x]^2)/(2*b) - (x*Tanh[a + b*x])/b^2}

{x^3*Tanh[a + b*x], x, 6, -(x^4/4) + (x^3*Log[1 + E^(2*a + 2*b*x)])/b + (3*x^2*PolyLog[2, -E^(2*a + 2*b*x)])/(2*b^2) - (3*x*PolyLog[3, -E^(2*a + 2*b*x)])/(2*b^3) + (3*PolyLog[4, -E^(2*a + 2*b*x)])/(4*b^4)}
{x^3*Tanh[a + b*x]^2, x, 7, -(x^3/b) + x^4/4 + (3*x^2*Log[1 + E^(2*a + 2*b*x)])/b^2 + (3*x*PolyLog[2, -E^(2*a + 2*b*x)])/b^3 - (3*PolyLog[3, -E^(2*a + 2*b*x)])/(2*b^4) - (x^3*Tanh[a + b*x])/b}
{x^3*Tanh[a + b*x]^3, x, 13, -((3*x^2)/(2*b^2)) - x^4/4 + (3*x*Log[1 + E^(2*a + 2*b*x)])/b^3 + (x^3*Log[1 + E^(2*a + 2*b*x)])/b + (3*(1 + b^2*x^2)*PolyLog[2, -E^(2*a + 2*b*x)])/(2*b^4) - (3*x*PolyLog[3, -E^(2*a + 2*b*x)])/(2*b^3) + (3*PolyLog[4, -E^(2*a + 2*b*x)])/(4*b^4) + (x^3*Sech[a + b*x]^2)/(2*b) - (3*x^2*Tanh[a + b*x])/(2*b^2)}

{Tanh[a + b*x]/x, x, 0, Int[Tanh[a + b*x]/x, x]}
{Tanh[a + b*x]^2/x, x, 0, Int[Tanh[a + b*x]^2/x, x]}
{Tanh[a + b*x]^3/x, x, 0, Int[Tanh[a + b*x]^3/x, x]}

{Tanh[a + b*x]/x^2, x, 0, Int[Tanh[a + b*x]/x^2, x]}
{Tanh[a + b*x]^2/x^2, x, 0, Int[Tanh[a + b*x]^2/x^2, x]}
{Tanh[a + b*x]^3/x^2, x, 0, Int[Tanh[a + b*x]^3/x^2, x]}

{Tanh[a + b*x]/x^3, x, 0, Int[Tanh[a + b*x]/x^3, x]}
{Tanh[a + b*x]^2/x^3, x, 0, Int[Tanh[a + b*x]^2/x^3, x]}
{Tanh[a + b*x]^3/x^3, x, 0, Int[Tanh[a + b*x]^3/x^3, x]}


(* ::Subsection::Closed:: *)
(*(a Tanh[a+b x]^n)^m*)


(* Integrands of the form (a*Tanh[x]^n)^m where n is an integer and m is a half-integer *)
{Sqrt[a*Tanh[x]], x, 5, (-Sqrt[a])*ArcTan[Sqrt[a*Tanh[x]]/Sqrt[a]] + Sqrt[a]*ArcTanh[Sqrt[a*Tanh[x]]/Sqrt[a]]}
{Sqrt[a*Tanh[x]^2], x, 2, Coth[x]*Log[Cosh[x]]*Sqrt[a*Tanh[x]^2]}
{Sqrt[a*Tanh[x]^3], x, 8, ((ArcTan[Sqrt[Tanh[x]]] + ArcTanh[Sqrt[Tanh[x]]] - 2*Sqrt[Tanh[x]])*Sqrt[a*Tanh[x]^3])/Tanh[x]^(3/2)}
{Sqrt[a*Tanh[x]^4], x, 2, (-Coth[x])*Sqrt[a*Tanh[x]^4] + x*Coth[x]^2*Sqrt[a*Tanh[x]^4]}

{(a*Tanh[x])^(3/2),x, 7, a^(3/2)*ArcTan[Sqrt[a*Tanh[x]]/Sqrt[a]] + a^(3/2)*ArcTanh[Sqrt[a*Tanh[x]]/Sqrt[a]] - 2*a*Sqrt[a*Tanh[x]]}
{(a*Tanh[x]^2)^(3/2),x, 3, a*Coth[x]*Log[Cosh[x]]*Sqrt[a*Tanh[x]^2] - (1/2)*a*Tanh[x]*Sqrt[a*Tanh[x]^2]}
{(a*Tanh[x]^3)^(3/2),x, 9, -((a*Sqrt[a*Tanh[x]^3]*(21*ArcTan[Sqrt[Tanh[x]]] - 21*ArcTanh[Sqrt[Tanh[x]]] + 14*Tanh[x]^(3/2) + 6*Tanh[x]^(7/2)))/(21*Tanh[x]^(3/2)))}
{(a*Tanh[x]^4)^(3/2),x, 4, (-a)*Coth[x]*Sqrt[a*Tanh[x]^4] + a*x*Coth[x]^2*Sqrt[a*Tanh[x]^4] - (1/3)*a*Tanh[x]*Sqrt[a*Tanh[x]^4] - (1/5)*a*Tanh[x]^3*Sqrt[a*Tanh[x]^4]}

{1/Sqrt[a*Tanh[x]], x, 6, ArcTan[Sqrt[a*Tanh[x]]/Sqrt[a]]/Sqrt[a] + ArcTanh[Sqrt[a*Tanh[x]]/Sqrt[a]]/Sqrt[a]}
{1/Sqrt[a*Tanh[x]^2], x, 2, (Log[Sinh[x]]*Tanh[x])/Sqrt[a*Tanh[x]^2]}
{1/Sqrt[a*Tanh[x]^3], x, 10, -(((2 + (ArcTan[Sqrt[Tanh[x]]] - ArcTanh[Sqrt[Tanh[x]]])*Sqrt[Tanh[x]])*Tanh[x])/Sqrt[a*Tanh[x]^3])}
{1/Sqrt[a*Tanh[x]^4], x, 2, -(Tanh[x]/Sqrt[a*Tanh[x]^4]) + (x*Tanh[x]^2)/Sqrt[a*Tanh[x]^4]}


(* ::Subsection::Closed:: *)
(*(a+b Tanh[c+d x])^n		where a^2 - b^2 is zero*)


(* Integrands of the form (a+b*Tanh[x])^n where a^2-b^2 is zero *)
{(1 + Tanh[x])^3, x, 6, 4*x + 4*Log[Cosh[x]] - 3*Tanh[x] - Tanh[x]^2/2}
{(1 + Tanh[x])^2, x, 4, 2*x + 2*Log[Cosh[x]] - Tanh[x]}
{1/(1 + Tanh[x]), x, 1, x/2 - 1/(2*(1 + Tanh[x]))}
{1/(1 + Tanh[x])^2, x, 2, x/4 - 1/(4*(1 + Tanh[x])^2) - 1/(4*(1 + Tanh[x]))}
{1/(1 + Tanh[x])^3, x, 3, x/8 - 1/(6*(1 + Tanh[x])^3) - 1/(8*(1 + Tanh[x])^2) - 1/(8*(1 + Tanh[x]))}

{(1 + Tanh[x])^(5/2), x, 3, 4*Sqrt[2]*ArcTanh[Sqrt[1 + Tanh[x]]/Sqrt[2]] - 4*Sqrt[1 + Tanh[x]] - (2/3)*(1 + Tanh[x])^(3/2)}
{(1 + Tanh[x])^(3/2), x, 2, 2*Sqrt[2]*ArcTanh[Sqrt[1 + Tanh[x]]/Sqrt[2]] - 2*Sqrt[1 + Tanh[x]]}
{(1 + Tanh[x])^(1/2), x, 1, Sqrt[2]*ArcTanh[Sqrt[1 + Tanh[x]]/Sqrt[2]]}
{1/(1 + Tanh[x])^(1/2), x, 2, ArcTanh[Sqrt[1 + Tanh[x]]/Sqrt[2]]/Sqrt[2] - 1/Sqrt[1 + Tanh[x]]}
{1/(1 + Tanh[x])^(3/2), x, 3, ArcTanh[Sqrt[1 + Tanh[x]]/Sqrt[2]]/(2*Sqrt[2]) - 1/(3*(1 + Tanh[x])^(3/2)) - 1/(2*Sqrt[1 + Tanh[x]])}
{1/(1 + Tanh[x])^(5/2), x, 4, ArcTanh[Sqrt[1 + Tanh[x]]/Sqrt[2]]/(4*Sqrt[2]) - 1/(5*(1 + Tanh[x])^(5/2)) - 1/(6*(1 + Tanh[x])^(3/2)) - 1/(4*Sqrt[1 + Tanh[x]])}


(* ::Subsection::Closed:: *)
(*(a+b Tanh[c+d x])^n		where a^2 - b^2 is nonzero*)


(* Integrands of the form (a+b*Tanh[c+d*x])^n where a^2-b^2 is nonzero *)
{(a + b*Tanh[c + d*x])^3, x, 6, a^3*x + 3*a*b^2*x + (3*a^2*b*Log[Cosh[c + d*x]])/d + (b^3*Log[Cosh[c + d*x]])/d - (3*a*b^2*Tanh[c + d*x])/d - (b^3*Tanh[c + d*x]^2)/(2*d)}
{(a + b*Tanh[c + d*x])^2, x, 4, a^2*x + b^2*x + (2*a*b*Log[Cosh[c + d*x]])/d - (b^2*Tanh[c + d*x])/d}
{1/(4 - 6*Tanh[x]), x, 2, -(x/5) - (3/10)*Log[2*Cosh[x] - 3*Sinh[x]]}
{1/(a + b*Tanh[c + d*x]),x, 1, (a*x)/(a^2 - b^2) - (b*Log[a*Cosh[c + d*x] + b*Sinh[c + d*x]])/((a^2 - b^2)*d)}
{1/(a + b*Tanh[c + d*x])^2,x, 8, -(Log[1 - Tanh[c + d*x]]/(2*(a + b)^2*d)) + Log[1 + Tanh[c + d*x]]/(2*(a - b)^2*d) - (2*a*b*Log[a + b*Tanh[c + d*x]])/((a^2 - b^2)^2*d) + b/((a^2 - b^2)*d*(a + b*Tanh[c + d*x]))}
{1/(a + b*Tanh[c + d*x])^3,x, 9, -(Log[1 - Tanh[c + d*x]]/(2*(a + b)^3*d)) + Log[1 + Tanh[c + d*x]]/(2*(a - b)^3*d) - (b*(3*a^2 + b^2)*Log[a + b*Tanh[c + d*x]])/((a^2 - b^2)^3*d) + b/(2*(a^2 - b^2)*d*(a + b*Tanh[c + d*x])^2) + (2*a*b)/((a^2 - b^2)^2*d*(a + b*Tanh[c + d*x]))}

{Sqrt[a + b*Tanh[c + d*x]], x, 5, -((Sqrt[a - b]*ArcTanh[Sqrt[a + b*Tanh[c + d*x]]/Sqrt[a - b]])/d) + (Sqrt[a + b]*ArcTanh[Sqrt[a + b*Tanh[c + d*x]]/Sqrt[a + b]])/d}
{1/Sqrt[a + b*Tanh[c + d*x]], x, 5, -(ArcTanh[Sqrt[a + b*Tanh[c + d*x]]/Sqrt[a - b]]/(Sqrt[a - b]*d)) + ArcTanh[Sqrt[a + b*Tanh[c + d*x]]/Sqrt[a + b]]/(Sqrt[a + b]*d)}


(* ::Subsection::Closed:: *)
(*(a+b Tanh[c+d x]^n)^m*)


{1/(1 - 2*Tanh[x]^2), x, 1, -x + Sqrt[2]*ArcTanh[Sqrt[2]*Tanh[x]]}

{1/(1 + Tanh[x]^3), x, 6, x/2 - (2*ArcTan[(1 - 2*Tanh[x])/Sqrt[3]])/(3*Sqrt[3]) - 1/(6*(1 + Tanh[x])), -((2*ArcTan[(1 - 2*Tanh[x])/Sqrt[3]])/(3*Sqrt[3])) + (1/2)*I*Pi*Mods[-((I*x)/Pi)] - 1/(6*(1 + Tanh[x]))}


(* Integrands of the form (a+b*Tanh[x]^2)^m where m is a half-integer *)
{Sqrt[1 + Tanh[x]^2], x, 4, -ArcSinh[Tanh[x]] + Sqrt[2]*ArcTanh[(Sqrt[2]*Tanh[x])/Sqrt[1 + Tanh[x]^2]]}
{Sqrt[1 - Tanh[x]^2], x, 2, ArcSin[Tanh[x]]}
{Sqrt[-1 + Tanh[x]^2], x, 3, -ArcTanh[Tanh[x]/Sqrt[-Sech[x]^2]]}
{Sqrt[-1 - Tanh[x]^2], x, 4, ArcTan[Tanh[x]/Sqrt[-1 - Tanh[x]^2]] - Sqrt[2]*ArcTan[(Sqrt[2]*Tanh[x])/Sqrt[-1 - Tanh[x]^2]]}
{Sqrt[a + b*Tanh[x]^2], x, 4, (-Sqrt[b])*ArcTanh[(Sqrt[b]*Tanh[x])/Sqrt[a + b*Tanh[x]^2]] + Sqrt[a + b]*ArcTanh[(Sqrt[a + b]*Tanh[x])/Sqrt[a + b*Tanh[x]^2]]}

{1/Sqrt[1 + Tanh[x]^2], x, 2, ArcTanh[(Sqrt[2]*Tanh[x])/Sqrt[1 + Tanh[x]^2]]/Sqrt[2]}
{1/Sqrt[1 - Tanh[x]^2], x, 2, Tanh[x]/Sqrt[Sech[x]^2]}
{1/Sqrt[-1 + Tanh[x]^2], x, 3, Tanh[x]/Sqrt[-Sech[x]^2]}
{1/Sqrt[-1 - Tanh[x]^2], x, 2, ArcTan[(Sqrt[2]*Tanh[x])/Sqrt[-1 - Tanh[x]^2]]/Sqrt[2]}
{1/Sqrt[a + b*Tanh[x]^2], x, 2, ArcTanh[(Sqrt[a + b]*Tanh[x])/Sqrt[a + b*Tanh[x]^2]]/Sqrt[a + b]}

{(1 + Tanh[x]^2)^(3/2), x, 8, (-(5/2))*ArcSinh[Tanh[x]] + 2*Sqrt[2]*ArcTanh[(Sqrt[2]*Tanh[x])/Sqrt[1 + Tanh[x]^2]] - (1/2)*Tanh[x]*Sqrt[1 + Tanh[x]^2]}
{(1 - Tanh[x]^2)^(3/2), x, 3, (1/2)*ArcSin[Tanh[x]] + (1/2)*Sqrt[Sech[x]^2]*Tanh[x]}
{(-1 + Tanh[x]^2)^(3/2), x, 4, (1/2)*ArcTanh[Tanh[x]/Sqrt[-Sech[x]^2]] - (1/2)*Sqrt[-Sech[x]^2]*Tanh[x]}
{(-1 - Tanh[x]^2)^(3/2), x, 7, (-(5/2))*ArcTan[Tanh[x]/Sqrt[-1 - Tanh[x]^2]] + 2*Sqrt[2]*ArcTan[(Sqrt[2]*Tanh[x])/Sqrt[-1 - Tanh[x]^2]] + (1/2)*Tanh[x]*Sqrt[-1 - Tanh[x]^2]}
{(a + b*Tanh[x]^2)^(3/2), x, 8, (-(3/2))*a*Sqrt[b]*ArcTanh[(Sqrt[b]*Tanh[x])/Sqrt[a + b*Tanh[x]^2]] - b^(3/2)*ArcTanh[(Sqrt[b]*Tanh[x])/Sqrt[a + b*Tanh[x]^2]] + (a + b)^(3/2)*ArcTanh[(Sqrt[a + b]*Tanh[x])/Sqrt[a + b*Tanh[x]^2]] - (1/2)*b*Tanh[x]*Sqrt[a + b*Tanh[x]^2]}


(* ::Subsection::Closed:: *)
(*x^m Tanh[a+b Log[c x^n]]^p*)


(* Integrands of the form Tanh[a+b*Log[c*x^n]]^p/x where p is an integer *)
{Tanh[a + b*Log[c*x^n]]/x, x, 2, Log[Cosh[a + b*Log[c*x^n]]]/(b*n)}
{Tanh[a + b*Log[c*x^n]]^2/x, x, 2, Log[c*x^n]/n - Tanh[a + b*Log[c*x^n]]/(b*n)}
{Tanh[a + b*Log[c*x^n]]^3/x, x, 3, Log[Cosh[a + b*Log[c*x^n]]]/(b*n) - Tanh[a + b*Log[c*x^n]]^2/(2*b*n)}
{Tanh[a + b*Log[c*x^n]]^4/x, x, 3, Log[c*x^n]/n - Tanh[a + b*Log[c*x^n]]/(b*n) - Tanh[a + b*Log[c*x^n]]^3/(3*b*n)}
{Tanh[a + b*Log[c*x^n]]^5/x, x, 4, Log[Cosh[a + b*Log[c*x^n]]]/(b*n) - Tanh[a + b*Log[c*x^n]]^2/(2*b*n) - Tanh[a + b*Log[c*x^n]]^4/(4*b*n)}


(* Integrands of the form Tanh[a+b*Log[c*x^n]]^p/x where p is a half-integer *)
{Tanh[a + b*Log[c*x^n]]^(5/2)/x, x, 7, -(ArcTan[Sqrt[Tanh[a + b*Log[c*x^n]]]]/(b*n)) + ArcTanh[Sqrt[Tanh[a + b*Log[c*x^n]]]]/(b*n) - (2*Tanh[a + b*Log[c*x^n]]^(3/2))/(3*b*n)}
{Tanh[a + b*Log[c*x^n]]^(3/2)/x, x, 7, ArcTan[Sqrt[Tanh[a + b*Log[c*x^n]]]]/(b*n) + ArcTanh[Sqrt[Tanh[a + b*Log[c*x^n]]]]/(b*n) - (2*Sqrt[Tanh[a + b*Log[c*x^n]]])/(b*n)}
{Sqrt[Tanh[a + b*Log[c*x^n]]]/x, x, 6, -(ArcTan[Sqrt[Tanh[a + b*Log[c*x^n]]]]/(b*n)) + ArcTanh[Sqrt[Tanh[a + b*Log[c*x^n]]]]/(b*n)}
{1/(x*Sqrt[Tanh[a + b*Log[c*x^n]]]), x, 6, ArcTan[Sqrt[Tanh[a + b*Log[c*x^n]]]]/(b*n) + ArcTanh[Sqrt[Tanh[a + b*Log[c*x^n]]]]/(b*n)}
{1/(x*Tanh[a + b*Log[c*x^n]]^(3/2)), x, 7, -(ArcTan[Sqrt[Tanh[a + b*Log[c*x^n]]]]/(b*n)) + ArcTanh[Sqrt[Tanh[a + b*Log[c*x^n]]]]/(b*n) - 2/(b*n*Sqrt[Tanh[a + b*Log[c*x^n]]])}
{1/(x*Tanh[a + b*Log[c*x^n]]^(5/2)), x, 7, ArcTan[Sqrt[Tanh[a + b*Log[c*x^n]]]]/(b*n) + ArcTanh[Sqrt[Tanh[a + b*Log[c*x^n]]]]/(b*n) - 2/(3*b*n*Tanh[a + b*Log[c*x^n]]^(3/2))}
