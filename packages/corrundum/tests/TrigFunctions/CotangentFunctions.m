(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Cotangents*)


(* ::Subsection::Closed:: *)
(*Cot[a+b x]^n*)


(* Integrands of the form Cot[a+b*x]^n where n is a positive integer *)
{Cot[a + b*x], x, 1, Log[Sin[a + b*x]]/b}
{Cot[a + b*x]^2, x, 1, -x - Cot[a + b*x]/b}
{Cot[a + b*x]^3, x, 2, -(Cot[a + b*x]^2/(2*b)) - Log[Sin[a + b*x]]/b}
{Cot[a + b*x]^4, x, 2, x + Cot[a + b*x]/b - Cot[a + b*x]^3/(3*b)}
{Cot[a + b*x]^5, x, 3, Cot[a + b*x]^2/(2*b) - Cot[a + b*x]^4/(4*b) + Log[Sin[a + b*x]]/b}


(* Integrands of the form Cot[a+b*x]^n where n is a half-integer *)
{Cot[a + b*x]^(1/2), x, 7, ArcTan[1 - Sqrt[2]*Sqrt[Cot[a + b*x]]]/(Sqrt[2]*b) - ArcTan[1 + Sqrt[2]*Sqrt[Cot[a + b*x]]]/(Sqrt[2]*b) - Log[1 - Sqrt[2]*Sqrt[Cot[a + b*x]] + Cot[a + b*x]]/(2*Sqrt[2]*b) + Log[1 + Sqrt[2]*Sqrt[Cot[a + b*x]] + Cot[a + b*x]]/(2*Sqrt[2]*b)}
{Cot[a + b*x]^(3/2), x, 8, -(ArcTan[1 - Sqrt[2]*Sqrt[Cot[a + b*x]]]/(Sqrt[2]*b)) + ArcTan[1 + Sqrt[2]*Sqrt[Cot[a + b*x]]]/(Sqrt[2]*b) - (2*Sqrt[Cot[a + b*x]])/b - Log[1 - Sqrt[2]*Sqrt[Cot[a + b*x]] + Cot[a + b*x]]/(2*Sqrt[2]*b) + Log[1 + Sqrt[2]*Sqrt[Cot[a + b*x]] + Cot[a + b*x]]/(2*Sqrt[2]*b)}
{Cot[a + b*x]^(5/2), x, 8, -(ArcTan[1 - Sqrt[2]*Sqrt[Cot[a + b*x]]]/(Sqrt[2]*b)) + ArcTan[1 + Sqrt[2]*Sqrt[Cot[a + b*x]]]/(Sqrt[2]*b) - (2*Cot[a + b*x]^(3/2))/(3*b) + Log[1 - Sqrt[2]*Sqrt[Cot[a + b*x]] + Cot[a + b*x]]/(2*Sqrt[2]*b) - Log[1 + Sqrt[2]*Sqrt[Cot[a + b*x]] + Cot[a + b*x]]/(2*Sqrt[2]*b)}

{1/Cot[a + b*x]^(1/2), x, 7, ArcTan[1 - Sqrt[2]*Sqrt[Cot[a + b*x]]]/(Sqrt[2]*b) - ArcTan[1 + Sqrt[2]*Sqrt[Cot[a + b*x]]]/(Sqrt[2]*b) + Log[1 - Sqrt[2]*Sqrt[Cot[a + b*x]] + Cot[a + b*x]]/(2*Sqrt[2]*b) - Log[1 + Sqrt[2]*Sqrt[Cot[a + b*x]] + Cot[a + b*x]]/(2*Sqrt[2]*b)}
{1/Cot[a + b*x]^(3/2), x, 8, -(ArcTan[1 - Sqrt[2]*Sqrt[Cot[a + b*x]]]/(Sqrt[2]*b)) + ArcTan[1 + Sqrt[2]*Sqrt[Cot[a + b*x]]]/(Sqrt[2]*b) + 2/(b*Sqrt[Cot[a + b*x]]) + Log[1 - Sqrt[2]*Sqrt[Cot[a + b*x]] + Cot[a + b*x]]/(2*Sqrt[2]*b) - Log[1 + Sqrt[2]*Sqrt[Cot[a + b*x]] + Cot[a + b*x]]/(2*Sqrt[2]*b)}
{1/Cot[a + b*x]^(5/2), x, 8, -(ArcTan[1 - Sqrt[2]*Sqrt[Cot[a + b*x]]]/(Sqrt[2]*b)) + ArcTan[1 + Sqrt[2]*Sqrt[Cot[a + b*x]]]/(Sqrt[2]*b) + 2/(3*b*Cot[a + b*x]^(3/2)) - Log[1 - Sqrt[2]*Sqrt[Cot[a + b*x]] + Cot[a + b*x]]/(2*Sqrt[2]*b) + Log[1 + Sqrt[2]*Sqrt[Cot[a + b*x]] + Cot[a + b*x]]/(2*Sqrt[2]*b)}

{Cot[8*x]^(1/3), x, 7, (1/16)*Sqrt[3]*ArcTan[(1 - 2*Cot[8*x]^(2/3))/Sqrt[3]] + (1/16)*Log[1 + Cot[8*x]^(2/3)] - (1/32)*Log[1 - Cot[8*x]^(2/3) + Cot[8*x]^(4/3)]}


(* ::Subsection::Closed:: *)
(*x^m Cot[a+b x]^n*)


(* Integrands of the form x^m*Tan[a+b*x]^n where m and n are integers *)
{x*Cot[a + b*x], x, 4, -((I*x^2)/2) + (x*Log[1 - E^(2*I*a + 2*I*b*x)])/b - (I*PolyLog[2, E^(2*I*a + 2*I*b*x)])/(2*b^2)}
{x*Cot[a + b*x]^2, x, 3, -x^2/2 - (x*Cot[a + b*x])/b + Log[Sin[a + b*x]]/b^2}
{x*Cot[a + b*x]^3, x, 6, (I*x^2)/2 - Cot[a + b*x]/(2*b^2) - (x*Csc[a + b*x]^2)/(2*b) - (x*Log[1 - E^(2*I*a + 2*I*b*x)])/b + (I*PolyLog[2, E^(2*I*a + 2*I*b*x)])/(2*b^2)}

{x^2*Cot[a + b*x], x, 5, -((I*x^3)/3) + (x^2*Log[1 - E^(2*I*a + 2*I*b*x)])/b - (I*x*PolyLog[2, E^(2*I*a + 2*I*b*x)])/b^2 + PolyLog[3, E^(2*I*a + 2*I*b*x)]/(2*b^3)}
{x^2*Cot[a + b*x]^2, x, 6, -((I*x^2)/b) - x^3/3 - (x^2*Cot[a + b*x])/b + (2*x*Log[1 - E^(2*I*a + 2*I*b*x)])/b^2 - (I*PolyLog[2, E^(2*I*a + 2*I*b*x)])/b^3}
{x^2*Cot[a + b*x]^3, x, 9, (I*x^3)/3 - (x*Cot[a + b*x])/b^2 - (x^2*Csc[a + b*x]^2)/(2*b) - (x^2*Log[1 - E^(2*I*a + 2*I*b*x)])/b + Log[Sin[a + b*x]]/b^3 + (I*x*PolyLog[2, E^(2*I*a + 2*I*b*x)])/b^2 - PolyLog[3, E^(2*I*a + 2*I*b*x)]/(2*b^3)}

{x^3*Cot[a + b*x], x, 6, -((I*x^4)/4) + (x^3*Log[1 - E^(2*I*a + 2*I*b*x)])/b - (3*I*x^2*PolyLog[2, E^(2*I*a + 2*I*b*x)])/(2*b^2) + (3*x*PolyLog[3, E^(2*I*a + 2*I*b*x)])/(2*b^3) + (3*I*PolyLog[4, E^(2*I*a + 2*I*b*x)])/(4*b^4)}
{x^3*Cot[a + b*x]^2, x, 7, -((I*x^3)/b) - x^4/4 - (x^3*Cot[a + b*x])/b + (3*x^2*Log[1 - E^(2*I*a + 2*I*b*x)])/b^2 - (3*I*x*PolyLog[2, E^(2*I*a + 2*I*b*x)])/b^3 + (3*PolyLog[3, E^(2*I*a + 2*I*b*x)])/(2*b^4)}
{x^3*Cot[a + b*x]^3, x, 13, -((3*I*x^2)/(2*b^2)) + (I*x^4)/4 - (3*x^2*Cot[a + b*x])/(2*b^2) - (x^3*Csc[a + b*x]^2)/(2*b) + (3*x*Log[1 - E^(2*I*a + 2*I*b*x)])/b^3 - (x^3*Log[1 - E^(2*I*a + 2*I*b*x)])/b - (3*I*(1 - b^2*x^2)*PolyLog[2, E^(2*I*a + 2*I*b*x)])/(2*b^4) - (3*x*PolyLog[3, E^(2*I*a + 2*I*b*x)])/(2*b^3) - (3*I*PolyLog[4, E^(2*I*a + 2*I*b*x)])/(4*b^4)}

{Cot[a + b*x]/x, x, 0, Int[Cot[a + b*x]/x, x]}
{Cot[a + b*x]^2/x, x, 0, Int[Cot[a + b*x]^2/x, x]}
{Cot[a + b*x]^3/x, x, 0, Int[Cot[a + b*x]^3/x, x]}

{Cot[a + b*x]/x^2, x, 0, Int[Cot[a + b*x]/x^2, x]}
{Cot[a + b*x]^2/x^2, x, 0, Int[Cot[a + b*x]^2/x^2, x]}
{Cot[a + b*x]^3/x^2, x, 0, Int[Cot[a + b*x]^3/x^2, x]}

{Cot[a + b*x]/x^3, x, 0, Int[Cot[a + b*x]/x^3, x]}
{Cot[a + b*x]^2/x^3, x, 0, Int[Cot[a + b*x]^2/x^3, x]}
{Cot[a + b*x]^3/x^3, x, 0, Int[Cot[a + b*x]^3/x^3, x]}


(* ::Subsection::Closed:: *)
(*(a Cot[a+b x]^n)^m*)


(* Integrands of the form (a*Cot[x]^n)^m where n is an integer and m is a half-integer *)
{Sqrt[a*Cot[x]], x, 5, -((a*ArcTan[Sqrt[a*Cot[x]]/(-a^2)^(1/4)])/(-a^2)^(1/4)) + (a*ArcTanh[Sqrt[a*Cot[x]]/(-a^2)^(1/4)])/(-a^2)^(1/4)}
{Sqrt[a*Cot[x]^2], x, 2, Sqrt[a*Cot[x]^2]*Log[Sin[x]]*Tan[x]}
{Sqrt[a*Cot[x]^3], x, 10, -((1/(4*Cot[x]^(3/2)))*(Sqrt[a*Cot[x]^3]*(2*Sqrt[2]*ArcTan[1 - Sqrt[2]*Sqrt[Cot[x]]] - 2*Sqrt[2]*ArcTan[1 + Sqrt[2]*Sqrt[Cot[x]]] + 8*Sqrt[Cot[x]] + Sqrt[2]*Log[1 - Sqrt[2]*Sqrt[Cot[x]] + Cot[x]] - Sqrt[2]*Log[1 + Sqrt[2]*Sqrt[Cot[x]] + Cot[x]])))}
{Sqrt[a*Cot[x]^4], x, 2, (-Sqrt[a*Cot[x]^4])*Tan[x] - x*Sqrt[a*Cot[x]^4]*Tan[x]^2}

{(a*Cot[x])^(3/2),x, 6, a*(-a^2)^(1/4)*ArcTan[Sqrt[a*Cot[x]]/(-a^2)^(1/4)] + a*(-a^2)^(1/4)*ArcTanh[Sqrt[a*Cot[x]]/(-a^2)^(1/4)] - 2*a*Sqrt[a*Cot[x]]}
{(a*Cot[x]^2)^(3/2),x, 3, (-(1/2))*a*Cot[x]*Sqrt[a*Cot[x]^2] - a*Sqrt[a*Cot[x]^2]*Log[Sin[x]]*Tan[x]}
{(a*Cot[x]^3)^(3/2),x, 11, (1/(84*Cot[x]^(3/2)))*(a*Sqrt[a*Cot[x]^3]*(42*Sqrt[2]*ArcTan[1 - Sqrt[2]*Sqrt[Cot[x]]] - 42*Sqrt[2]*ArcTan[1 + Sqrt[2]*Sqrt[Cot[x]]] + 56*Cot[x]^(3/2) - 24*Cot[x]^(7/2) - 21*Sqrt[2]*Log[1 - Sqrt[2]*Sqrt[Cot[x]] + Cot[x]] + 21*Sqrt[2]*Log[1 + Sqrt[2]*Sqrt[Cot[x]] + Cot[x]]))}
{(a*Cot[x]^4)^(3/2),x, 4, (1/3)*a*Cot[x]*Sqrt[a*Cot[x]^4] - (1/5)*a*Cot[x]^3*Sqrt[a*Cot[x]^4] - a*Sqrt[a*Cot[x]^4]*Tan[x] - a*x*Sqrt[a*Cot[x]^4]*Tan[x]^2}

{1/Sqrt[a*Cot[x]], x, 5, -(((-a^2)^(1/4)*ArcTan[Sqrt[a*Cot[x]]/(-a^2)^(1/4)])/a) - ((-a^2)^(1/4)*ArcTanh[Sqrt[a*Cot[x]]/(-a^2)^(1/4)])/a}
{1/Sqrt[a*Cot[x]^2], x, 2, -((Cot[x]*Log[Cos[x]])/Sqrt[a*Cot[x]^2])}
{1/Sqrt[a*Cot[x]^3], x, 11, (1/(4*Sqrt[a*Cot[x]^3]))*(Cot[x]*(8 - Sqrt[2]*Sqrt[Cot[x]]*(2*ArcTan[1 - Sqrt[2]*Sqrt[Cot[x]]] - 2*ArcTan[1 + Sqrt[2]*Sqrt[Cot[x]]] - Log[1 - Sqrt[2]*Sqrt[Cot[x]] + Cot[x]] + Log[1 + Sqrt[2]*Sqrt[Cot[x]] + Cot[x]])))}
{1/Sqrt[a*Cot[x]^4], x, 2, Cot[x]/Sqrt[a*Cot[x]^4] - (x*Cot[x]^2)/Sqrt[a*Cot[x]^4]}


(* ::Subsection::Closed:: *)
(*(a+b Cot[c+d x])^n*)


(* Integrands of the form (a+b*Cot[x])^n where a^2+b^2 is nonzero *)
{(a + b*Cot[x])^4, x, 8, a^4*x - 6*a^2*b^2*x + b^4*x - 6*a^2*b^2*Cot[x] + b^4*Cot[x] - 2*a*b^3*Cot[x]^2 - (1/3)*b^4*Cot[x]^3 + 4*a^3*b*Log[Sin[x]] - 4*a*b^3*Log[Sin[x]]}
{(a + b*Cot[x])^3, x, 6, a^3*x - 3*a*b^2*x - 3*a*b^2*Cot[x] - (1/2)*b^3*Cot[x]^2 + 3*a^2*b*Log[Sin[x]] - b^3*Log[Sin[x]]}
{(a + b*Cot[x])^2, x, 4, a^2*x - b^2*x - b^2*Cot[x] + 2*a*b*Log[Sin[x]]}
{(a + b*Cot[x]), x, 2, a*x + b*Log[Sin[x]]}
{1/(a + b*Cot[x]), x, 1, (a*x)/(a^2 + b^2) - (b*Log[b*Cos[x] + a*Sin[x]])/(a^2 + b^2)}
{1/(a + b*Cot[x])^2, x, 3, (2*a^2*x)/(a^2 + b^2)^2 - x/(a^2 + b^2) + b/((a^2 + b^2)*(a + b*Cot[x])) - (2*a*b*Log[b*Cos[x] + a*Sin[x]])/(a^2 + b^2)^2}
{1/(a + b*Cot[x])^3, x, 4, (a*(3*a^2 - b^2)*x)/(a^2 + b^2)^3 - (2*a*x)/(a^2 + b^2)^2 + b/(2*(a^2 + b^2)*(a + b*Cot[x])^2) + (2*a*b)/((a^2 + b^2)^2*(a + b*Cot[x])) - (b*(3*a^2 - b^2)*Log[b*Cos[x] + a*Sin[x]])/(a^2 + b^2)^3}
{1/(a + b*Cot[x])^4, x, 5, (4*a^2*(a^2 - b^2)*x)/(a^2 + b^2)^4 - ((3*a^2 - b^2)*x)/(a^2 + b^2)^3 + b/(3*(a^2 + b^2)*(a + b*Cot[x])^3) + (a*b)/((a^2 + b^2)^2*(a + b*Cot[x])^2) + (b*(3*a^2 - b^2))/((a^2 + b^2)^3*(a + b*Cot[x])) - (4*a*b*(a^2 - b^2)*Log[b*Cos[x] + a*Sin[x]])/(a^2 + b^2)^4}

{1/(4 + 6*Cot[x]), x, 2, x/13 - (3/26)*Log[3*Cos[x] + 2*Sin[x]]}
{1/(4 - 6*Cot[x]), x, 2, x/13 + (3/26)*Log[-3*Cos[x] + 2*Sin[x]]}

{(a + b*Cot[x])^(5/2), x, 5, (I*(a^3 - 3*a*b^2 - I*b*(3*a^2 - b^2))*ArcCoth[Sqrt[a + b*Cot[x]]/Sqrt[a - I*b]])/Sqrt[a - I*b] - (I*(a^3 - 3*a*b^2 + I*b*(3*a^2 - b^2))*ArcCoth[Sqrt[a + b*Cot[x]]/Sqrt[a + I*b]])/Sqrt[a + I*b] - 4*a*b*Sqrt[a + b*Cot[x]] - (2/3)*b*(a + b*Cot[x])^(3/2)}
{(a + b*Cot[x])^(3/2), x, 4, (I*(a^2 - 2*I*a*b - b^2)*ArcCoth[Sqrt[a + b*Cot[x]]/Sqrt[a - I*b]])/Sqrt[a - I*b] - (I*(a^2 + 2*I*a*b - b^2)*ArcCoth[Sqrt[a + b*Cot[x]]/Sqrt[a + I*b]])/Sqrt[a + I*b] - 2*b*Sqrt[a + b*Cot[x]]}
{(a + b*Cot[x])^(1/2), x, 3, I*Sqrt[a - I*b]*ArcCoth[Sqrt[a + b*Cot[x]]/Sqrt[a - I*b]] - I*Sqrt[a + I*b]*ArcCoth[Sqrt[a + b*Cot[x]]/Sqrt[a + I*b]]}
{1/(a + b*Cot[x])^(1/2), x, 3, (I*ArcCoth[Sqrt[a + b*Cot[x]]/Sqrt[a - I*b]])/Sqrt[a - I*b] - (I*ArcCoth[Sqrt[a + b*Cot[x]]/Sqrt[a + I*b]])/Sqrt[a + I*b]}
{1/(a + b*Cot[x])^(3/2), x, 4, (I*(a + I*b)*ArcCoth[Sqrt[a + b*Cot[x]]/Sqrt[a - I*b]])/(Sqrt[a - I*b]*(a^2 + b^2)) - (I*(a - I*b)*ArcCoth[Sqrt[a + b*Cot[x]]/Sqrt[a + I*b]])/(Sqrt[a + I*b]*(a^2 + b^2)) + (2*b)/((a^2 + b^2)*Sqrt[a + b*Cot[x]])}
{1/(a + b*Cot[x])^(5/2), x, 5, (I*(a^2 + 2*I*a*b - b^2)*ArcCoth[Sqrt[a + b*Cot[x]]/Sqrt[a - I*b]])/(Sqrt[a - I*b]*(a^2 + b^2)^2) - (I*(a^2 - 2*I*a*b - b^2)*ArcCoth[Sqrt[a + b*Cot[x]]/Sqrt[a + I*b]])/(Sqrt[a + I*b]*(a^2 + b^2)^2) + (2*b)/(3*(a^2 + b^2)*(a + b*Cot[x])^(3/2)) + (4*a*b)/((a^2 + b^2)^2*Sqrt[a + b*Cot[x]])}


(* Integrands of the form (a+b*Cot[x])^n where a^2+b^2 is zero *)
{(1 + I*Cot[x])^4, x, 8, 8*x + 7*Cot[x] + 2*I*Cot[x]^2 - Cot[x]^3/3 + 8*I*Log[Sin[x]]}
{(1 + I*Cot[x])^3, x, 6, 4*x + 3*Cot[x] + (1/2)*I*Cot[x]^2 + 4*I*Log[Sin[x]]}
{(1 + I*Cot[x])^2, x, 4, 2*x + Cot[x] + 2*I*Log[Sin[x]]}
{(1 + I*Cot[x]), x, 2, x + I*Log[Sin[x]]}
{1/(1 + I*Cot[x]), x, 1, x/2 - I/(2*(1 + I*Cot[x]))}
{1/(1 + I*Cot[x])^2, x, 2, x/4 - I/(4*(1 + I*Cot[x])^2) - I/(4*(1 + I*Cot[x]))}
{1/(1 + I*Cot[x])^3, x, 3, x/8 - I/(6*(1 + I*Cot[x])^3) - I/(8*(1 + I*Cot[x])^2) - I/(8*(1 + I*Cot[x]))}

{(1 + I*Cot[x])^(5/2), x, 3, 4*I*Sqrt[2]*ArcCoth[Sqrt[1 + I*Cot[x]]/Sqrt[2]] - 4*I*Sqrt[1 + I*Cot[x]] - (2/3)*I*(1 + I*Cot[x])^(3/2)}
{(1 + I*Cot[x])^(3/2), x, 2, 2*I*Sqrt[2]*ArcCoth[Sqrt[1 + I*Cot[x]]/Sqrt[2]] - 2*I*Sqrt[1 + I*Cot[x]]}
{(1 + I*Cot[x])^(1/2), x, 1, I*Sqrt[2]*ArcCoth[Sqrt[1 + I*Cot[x]]/Sqrt[2]]}
{1/(1 + I*Cot[x])^(1/2), x, 2, (I*ArcCoth[Sqrt[1 + I*Cot[x]]/Sqrt[2]])/Sqrt[2] - I/Sqrt[1 + I*Cot[x]]}
{1/(1 + I*Cot[x])^(3/2), x, 3, (I*ArcCoth[Sqrt[1 + I*Cot[x]]/Sqrt[2]])/(2*Sqrt[2]) - I/(3*(1 + I*Cot[x])^(3/2)) - I/(2*Sqrt[1 + I*Cot[x]])}
{1/(1 + I*Cot[x])^(5/2), x, 4, (I*ArcCoth[Sqrt[1 + I*Cot[x]]/Sqrt[2]])/(4*Sqrt[2]) - I/(5*(1 + I*Cot[x])^(5/2)) - I/(6*(1 + I*Cot[x])^(3/2)) - I/(4*Sqrt[1 + I*Cot[x]])}


(* ::Subsection::Closed:: *)
(*(A+B Cot[c+d x]) (a+b Cot[c+d x])^n*)


{(A + B*Cot[c + d*x])/(a + b*Cot[c + d*x]), x, 2, ((a*A + b*B)*x)/(a^2 + b^2) - ((A*b - a*B)*Log[b*Cos[c + d*x] + a*Sin[c + d*x]])/((a^2 + b^2)*d)}
{(A + B*Cot[c + d*x])/(a + b*Cot[c + d*x])^2, x, 3, -(((A*b - a*B)*x)/(b*(a^2 + b^2))) + (a*(b^2*B + a*(2*A*b - a*B))*x)/(b*(a^2 + b^2)^2) + (A*b - a*B)/((a^2 + b^2)*d*(a + b*Cot[c + d*x])) - ((b^2*B + a*(2*A*b - a*B))*Log[b*Cos[c + d*x] + a*Sin[c + d*x]])/((a^2 + b^2)^2*d)}
{(A + B*Cot[c + d*x])/(a + b*Cot[c + d*x])^3, x, 4, -(((b^2*B + a*(2*A*b - a*B))*x)/(b*(a^2 + b^2)^2)) + (a*(b*(a^2*A - b*(A*b - 2*a*B)) + a*(b^2*B + a*(2*A*b - a*B)))*x)/(b*(a^2 + b^2)^3) + (A*b - a*B)/(2*(a^2 + b^2)*d*(a + b*Cot[c + d*x])^2) + (b^2*B + a*(2*A*b - a*B))/((a^2 + b^2)^2*d*(a + b*Cot[c + d*x])) - ((b*(a^2*A - b*(A*b - 2*a*B)) + a*(b^2*B + a*(2*A*b - a*B)))*Log[b*Cos[c + d*x] + a*Sin[c + d*x]])/((a^2 + b^2)^3*d)}


{(1 + I*Cot[c + d*x])/Sqrt[a + b*Cot[c + d*x]], x, 1, (2*I*ArcCoth[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a - I*b]])/(Sqrt[a - I*b]*d)}
{(1 - I*Cot[c + d*x])/Sqrt[a + b*Cot[c + d*x]], x, 1, -((2*I*ArcCoth[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a + I*b]])/(Sqrt[a + I*b]*d))}

{(A + B*Cot[c + d*x])*(a + b*Cot[c + d*x])^(5/2), x, 6, (I*(b*(b^2*B - a*(2*A*b + a*B)) + a*(a^2*A - b*(A*b + 2*a*B)) + I*(a*(b^2*B - a*(2*A*b + a*B)) - b*(a^2*A - b*(A*b + 2*a*B))))*ArcCoth[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a - I*b]])/(Sqrt[a - I*b]*d) - (I*(b*(b^2*B - a*(2*A*b + a*B)) + a*(a^2*A - b*(A*b + 2*a*B)) - I*(a*(b^2*B - a*(2*A*b + a*B)) - b*(a^2*A - b*(A*b + 2*a*B))))*ArcCoth[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a + I*b]])/(Sqrt[a + I*b]*d) + (2*(b^2*B - a*(2*A*b + a*B))*Sqrt[a + b*Cot[c + d*x]])/d - (2*(A*b + a*B)*(a + b*Cot[c + d*x])^(3/2))/(3*d) - (2*B*(a + b*Cot[c + d*x])^(5/2))/(5*d)}
{(A + B*Cot[c + d*x])*(a + b*Cot[c + d*x])^(3/2), x, 5, (I*(a^2*A - b*(A*b + 2*a*B) + I*(b^2*B - a*(2*A*b + a*B)))*ArcCoth[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a - I*b]])/(Sqrt[a - I*b]*d) - (I*(a^2*A - b*(A*b + 2*a*B) - I*(b^2*B - a*(2*A*b + a*B)))*ArcCoth[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a + I*b]])/(Sqrt[a + I*b]*d) - (2*(A*b + a*B)*Sqrt[a + b*Cot[c + d*x]])/d - (2*B*(a + b*Cot[c + d*x])^(3/2))/(3*d)}
{(A + B*Cot[c + d*x])*(a + b*Cot[c + d*x])^(1/2), x, 4, (I*(a*A - b*B - I*(A*b + a*B))*ArcCoth[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a - I*b]])/(Sqrt[a - I*b]*d) - (I*(a*A - b*B + I*(A*b + a*B))*ArcCoth[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a + I*b]])/(Sqrt[a + I*b]*d) - (2*B*Sqrt[a + b*Cot[c + d*x]])/d}
{(A + B*Cot[c + d*x])/(a + b*Cot[c + d*x])^(1/2), x, 3, (I*(A - I*B)*ArcCoth[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a - I*b]])/(Sqrt[a - I*b]*d) - (I*(A + I*B)*ArcCoth[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a + I*b]])/(Sqrt[a + I*b]*d)}
{(A + B*Cot[c + d*x])/(a + b*Cot[c + d*x])^(3/2), x, 4, (I*(a*A + b*B + I*(A*b - a*B))*ArcCoth[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a - I*b]])/(Sqrt[a - I*b]*(a^2 + b^2)*d) - (I*(a*A + b*B - I*(A*b - a*B))*ArcCoth[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a + I*b]])/(Sqrt[a + I*b]*(a^2 + b^2)*d) + (2*(A*b - a*B))/((a^2 + b^2)*d*Sqrt[a + b*Cot[c + d*x]])}
{(A + B*Cot[c + d*x])/(a + b*Cot[c + d*x])^(5/2), x, 5, (I*(a^2*A - b*(A*b - 2*a*B) + I*(b^2*B + a*(2*A*b - a*B)))*ArcCoth[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a - I*b]])/(Sqrt[a - I*b]*(a^2 + b^2)^2*d) - (I*(a^2*A - b*(A*b - 2*a*B) - I*(b^2*B + a*(2*A*b - a*B)))*ArcCoth[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a + I*b]])/(Sqrt[a + I*b]*(a^2 + b^2)^2*d) + (2*(A*b - a*B))/(3*(a^2 + b^2)*d*(a + b*Cot[c + d*x])^(3/2)) + (2*(b^2*B + a*(2*A*b - a*B)))/((a^2 + b^2)^2*d*Sqrt[a + b*Cot[c + d*x]])}

{(-a + b*Cot[c + d*x])*(a + b*Cot[c + d*x])^(5/2), x, 5, -((I*(a^2 - 2*I*a*b - b^2)*(a^2 + b^2)*ArcCoth[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a - I*b]])/(Sqrt[a - I*b]*d)) + (I*(a^2 + 2*I*a*b - b^2)*(a^2 + b^2)*ArcCoth[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a + I*b]])/(Sqrt[a + I*b]*d) + (2*b*(a^2 + b^2)*Sqrt[a + b*Cot[c + d*x]])/d - (2*b*(a + b*Cot[c + d*x])^(5/2))/(5*d)}
{(-a + b*Cot[c + d*x])*(a + b*Cot[c + d*x])^(3/2), x, 4, -((I*Sqrt[a - I*b]*(a^2 + b^2)*ArcCoth[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a - I*b]])/d) + (I*Sqrt[a + I*b]*(a^2 + b^2)*ArcCoth[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a + I*b]])/d - (2*b*(a + b*Cot[c + d*x])^(3/2))/(3*d)}
{(-a + b*Cot[c + d*x])*(a + b*Cot[c + d*x])^(1/2), x, 4, -((I*(a^2 + b^2)*ArcCoth[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a - I*b]])/(Sqrt[a - I*b]*d)) + (I*(a^2 + b^2)*ArcCoth[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a + I*b]])/(Sqrt[a + I*b]*d) - (2*b*Sqrt[a + b*Cot[c + d*x]])/d}
{(-a + b*Cot[c + d*x])/(a + b*Cot[c + d*x])^(1/2), x, 3, -((I*(a + I*b)*ArcCoth[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a - I*b]])/(Sqrt[a - I*b]*d)) + (I*(a - I*b)*ArcCoth[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a + I*b]])/(Sqrt[a + I*b]*d)}
{(-a + b*Cot[c + d*x])/(a + b*Cot[c + d*x])^(3/2), x, 4, -((I*(a^2 + 2*I*a*b - b^2)*ArcCoth[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a - I*b]])/(Sqrt[a - I*b]*(a^2 + b^2)*d)) + (I*(a^2 - 2*I*a*b - b^2)*ArcCoth[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a + I*b]])/(Sqrt[a + I*b]*(a^2 + b^2)*d) - (4*a*b)/((a^2 + b^2)*d*Sqrt[a + b*Cot[c + d*x]])}
{(-a + b*Cot[c + d*x])/(a + b*Cot[c + d*x])^(5/2), x, 5, -((I*(a^3 - 3*a*b^2 + I*b*(3*a^2 - b^2))*ArcCoth[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a - I*b]])/(Sqrt[a - I*b]*(a^2 + b^2)^2*d)) + (I*(a^3 - 3*a*b^2 - I*b*(3*a^2 - b^2))*ArcCoth[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a + I*b]])/(Sqrt[a + I*b]*(a^2 + b^2)^2*d) - (4*a*b)/(3*(a^2 + b^2)*d*(a + b*Cot[c + d*x])^(3/2)) - (2*b*(3*a^2 - b^2))/((a^2 + b^2)^2*d*Sqrt[a + b*Cot[c + d*x]])}


(* ::Subsection::Closed:: *)
(*(a+b Cot[c+d x]^n)^m*)


{1/(1 + 2*Cot[x]^2), x, 1, -x - Sqrt[2]*ArcTan[Sqrt[2]*Cot[x]]}
{1/(1 - 2*Cot[x]^2), x, 1, x/3 - (1/3)*Sqrt[2]*ArcTanh[Sqrt[2]*Cot[x]]}

{1/(1 + Cot[x]^3), x, 8, x/2 - (1/6)*Log[1 + Cot[x]] - (1/4)*Log[Csc[x]^2] + (1/3)*Log[-Cot[x] + Csc[x]^2], (-(1/6))*Log[1 + Cot[x]] - (1/4)*Log[Csc[x]^2] + (1/3)*Log[-Cot[x] + Csc[x]^2] - (1/2)*Pi*Mods[1/2 - x/Pi]}


(* Integrands of the form (a+b*Cot[x]^2)^m where m is a half-integer *)
{Sqrt[1 + Cot[x]^2], x, 3, -ArcCsch[Tan[x]]}
{Sqrt[1 - Cot[x]^2], x, 4, ArcCsc[Tan[x]] - Sqrt[2]*ArcTan[(Sqrt[2]*Cot[x])/Sqrt[1 - Cot[x]^2]]}
{Sqrt[-1 + Cot[x]^2], x, 4, -ArcTanh[Cot[x]/Sqrt[-1 + Cot[x]^2]] + Sqrt[2]*ArcTanh[(Sqrt[2]*Cot[x])/Sqrt[-1 + Cot[x]^2]]}
{Sqrt[-1 - Cot[x]^2], x, 3, (-ArcTanh[Cos[x]])*Sqrt[-Csc[x]^2]*Sin[x]}
{Sqrt[a + b*Cot[x]^2], x, 4, (-Sqrt[a - b])*ArcTan[(Sqrt[a - b]*Cot[x])/Sqrt[a + b*Cot[x]^2]] - Sqrt[b]*ArcTanh[(Sqrt[b]*Cot[x])/Sqrt[a + b*Cot[x]^2]]}

{1/Sqrt[1 + Cot[x]^2], x, 3, -(Cot[x]/Sqrt[Csc[x]^2])}
{1/Sqrt[1 - Cot[x]^2], x, 2, -(ArcTan[(Sqrt[2]*Cot[x])/Sqrt[1 - Cot[x]^2]]/Sqrt[2])}
{1/Sqrt[-1 + Cot[x]^2], x, 2, -(ArcTanh[(Sqrt[2]*Cot[x])/Sqrt[-1 + Cot[x]^2]]/Sqrt[2])}
{1/Sqrt[-1 - Cot[x]^2], x, 3, -(Cot[x]/Sqrt[-Csc[x]^2])}
{1/Sqrt[a + b*Cot[x]^2], x, 2, -(ArcTan[(Sqrt[a - b]*Cot[x])/Sqrt[a + b*Cot[x]^2]]/Sqrt[a - b])}

{(1 + Cot[x]^2)^(3/2), x, 4, (-(1/2))*ArcCsch[Tan[x]] - (1/2)*Cot[x]*Sqrt[Csc[x]^2]}
{(1 - Cot[x]^2)^(3/2), x, 7, (5/2)*ArcCsc[Tan[x]] - 2*Sqrt[2]*ArcTan[(Sqrt[2]*Cot[x])/Sqrt[1 - Cot[x]^2]] + (1/2)*Cot[x]*Sqrt[1 - Cot[x]^2]}
{(-1 + Cot[x]^2)^(3/2), x, 7, (5/2)*ArcTanh[Cot[x]/Sqrt[-1 + Cot[x]^2]] - 2*Sqrt[2]*ArcTanh[(Sqrt[2]*Cot[x])/Sqrt[-1 + Cot[x]^2]] - (1/2)*Cot[x]*Sqrt[-1 + Cot[x]^2]}
{(-1 - Cot[x]^2)^(3/2), x, 4, (1/2)*Sqrt[-Csc[x]^2]*(ArcTanh[Cos[x]] + Cot[x]*Csc[x])*Sin[x]}
{(a + b*Cot[x]^2)^(3/2), x, 7, (-(a - b)^(3/2))*ArcTan[(Sqrt[a - b]*Cot[x])/Sqrt[a + b*Cot[x]^2]] - (3/2)*a*Sqrt[b]*ArcTanh[(Sqrt[b]*Cot[x])/Sqrt[a + b*Cot[x]^2]] + b^(3/2)*ArcTanh[(Sqrt[b]*Cot[x])/Sqrt[a + b*Cot[x]^2]] - (1/2)*b*Cot[x]*Sqrt[a + b*Cot[x]^2]}


(* ::Subsection::Closed:: *)
(*x^m Cot[a+b Log[c x^n]]^p*)


(* Integrands of the form Cot[a+b*Log[c*x^n]]^p/x where p is an integer *)
{Cot[a + b*Log[c*x^n]]/x, x, 2, Log[Sin[a + b*Log[c*x^n]]]/(b*n)}
{Cot[a + b*Log[c*x^n]]^2/x, x, 2, -(Cot[a + b*Log[c*x^n]]/(b*n)) - Log[c*x^n]/n}
{Cot[a + b*Log[c*x^n]]^3/x, x, 3, -(Cot[a + b*Log[c*x^n]]^2/(2*b*n)) - Log[Sin[a + b*Log[c*x^n]]]/(b*n)}
{Cot[a + b*Log[c*x^n]]^4/x, x, 3, Cot[a + b*Log[c*x^n]]/(b*n) - Cot[a + b*Log[c*x^n]]^3/(3*b*n) + Log[c*x^n]/n}
{Cot[a + b*Log[c*x^n]]^5/x, x, 4, Cot[a + b*Log[c*x^n]]^2/(2*b*n) - Cot[a + b*Log[c*x^n]]^4/(4*b*n) + Log[Sin[a + b*Log[c*x^n]]]/(b*n)}


(* Integrands of the form Cot[a+b*Log[c*x^n]]^p/x where p is a half-integer *)
{Cot[a + b*Log[c*x^n]]^(5/2)/x, x, 9, -(ArcTan[1 - Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n)) + ArcTan[1 + Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) - (2*Cot[a + b*Log[c*x^n]]^(3/2))/(3*b*n) + Log[1 - Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]] + Cot[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n) - Log[1 + Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]] + Cot[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n)}
{Cot[a + b*Log[c*x^n]]^(3/2)/x, x, 9, -(ArcTan[1 - Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n)) + ArcTan[1 + Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) - (2*Sqrt[Cot[a + b*Log[c*x^n]]])/(b*n) - Log[1 - Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]] + Cot[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n) + Log[1 + Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]] + Cot[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n)}
{Sqrt[Cot[a + b*Log[c*x^n]]]/x, x, 8, ArcTan[1 - Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) - ArcTan[1 + Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) - Log[1 - Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]] + Cot[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n) + Log[1 + Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]] + Cot[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n)}
{1/(x*Sqrt[Cot[a + b*Log[c*x^n]]]), x, 8, ArcTan[1 - Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) - ArcTan[1 + Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) + Log[1 - Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]] + Cot[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n) - Log[1 + Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]] + Cot[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n)}
{1/(x*Cot[a + b*Log[c*x^n]]^(3/2)), x, 9, -(ArcTan[1 - Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n)) + ArcTan[1 + Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) + 2/(b*n*Sqrt[Cot[a + b*Log[c*x^n]]]) + Log[1 - Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]] + Cot[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n) - Log[1 + Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]] + Cot[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n)}
{1/(x*Cot[a + b*Log[c*x^n]]^(5/2)), x, 9, -(ArcTan[1 - Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n)) + ArcTan[1 + Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) + 2/(3*b*n*Cot[a + b*Log[c*x^n]]^(3/2)) - Log[1 - Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]] + Cot[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n) + Log[1 + Sqrt[2]*Sqrt[Cot[a + b*Log[c*x^n]]] + Cot[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n)}


(* ::Subsection::Closed:: *)
(*Miscellaneous integrands involving cotangents*)


{Cot[Sqrt[x]]^2/Sqrt[x], x, 2, -2*Sqrt[x] - 2*Cot[Sqrt[x]]}


{Cot[x]/Sqrt[1 + I*Cot[x]], x, 6, ArcTanh[Sqrt[1 + I*Cot[x]]/Sqrt[2]]/Sqrt[2] + 1/Sqrt[1 + I*Cot[x]]}
{Cot[x]/Sqrt[I + Cot[x]], x, 6, (-(1/2) - I/2)*ArcTan[(1/2 + I/2)*Sqrt[I + Cot[x]]] + 1/Sqrt[I + Cot[x]]}
