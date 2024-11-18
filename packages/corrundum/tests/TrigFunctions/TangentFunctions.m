(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Tangents*)


(* ::Subsection::Closed:: *)
(*Tan[a+b x]^n*)


(* Integrands of the form Tan[a+b*x]^n where n is a positive integer *)
{Tan[a + b*x], x, 1, -(Log[Cos[a + b*x]]/b)}
{Tan[a + b*x]^2, x, 1, -x + Tan[a + b*x]/b}
{Tan[a + b*x]^3, x, 2, Log[Cos[a + b*x]]/b + Tan[a + b*x]^2/(2*b)}
{Tan[a + b*x]^4, x, 2, x - Tan[a + b*x]/b + Tan[a + b*x]^3/(3*b)}
{Tan[a + b*x]^5, x, 3, -(Log[Cos[a + b*x]]/b) - Tan[a + b*x]^2/(2*b) + Tan[a + b*x]^4/(4*b)}


(* Integrands of the form Tan[a+b*x]^n where n is a half-integer *)
{Tan[a + b*x]^(1/2), x, 7, -(ArcTan[1 - Sqrt[2]*Sqrt[Tan[a + b*x]]]/(Sqrt[2]*b)) + ArcTan[1 + Sqrt[2]*Sqrt[Tan[a + b*x]]]/(Sqrt[2]*b) + Log[1 - Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b) - Log[1 + Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b)}
{Tan[a + b*x]^(3/2), x, 8, ArcTan[1 - Sqrt[2]*Sqrt[Tan[a + b*x]]]/(Sqrt[2]*b) - ArcTan[1 + Sqrt[2]*Sqrt[Tan[a + b*x]]]/(Sqrt[2]*b) + Log[1 - Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b) - Log[1 + Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b) + (2*Sqrt[Tan[a + b*x]])/b}
{Tan[a + b*x]^(5/2), x, 8, ArcTan[1 - Sqrt[2]*Sqrt[Tan[a + b*x]]]/(Sqrt[2]*b) - ArcTan[1 + Sqrt[2]*Sqrt[Tan[a + b*x]]]/(Sqrt[2]*b) - Log[1 - Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b) + Log[1 + Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b) + (2*Tan[a + b*x]^(3/2))/(3*b)}

{1/Tan[a + b*x]^(1/2), x, 7, -(ArcTan[1 - Sqrt[2]*Sqrt[Tan[a + b*x]]]/(Sqrt[2]*b)) + ArcTan[1 + Sqrt[2]*Sqrt[Tan[a + b*x]]]/(Sqrt[2]*b) - Log[1 - Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b) + Log[1 + Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b)}
{1/Tan[a + b*x]^(3/2), x, 8, ArcTan[1 - Sqrt[2]*Sqrt[Tan[a + b*x]]]/(Sqrt[2]*b) - ArcTan[1 + Sqrt[2]*Sqrt[Tan[a + b*x]]]/(Sqrt[2]*b) - Log[1 - Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b) + Log[1 + Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b) - 2/(b*Sqrt[Tan[a + b*x]])}
{1/Tan[a + b*x]^(5/2), x, 8, ArcTan[1 - Sqrt[2]*Sqrt[Tan[a + b*x]]]/(Sqrt[2]*b) - ArcTan[1 + Sqrt[2]*Sqrt[Tan[a + b*x]]]/(Sqrt[2]*b) + Log[1 - Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b) - Log[1 + Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b) - 2/(3*b*Tan[a + b*x]^(3/2))}

{Tan[8*x]^(1/3), x, 7, (-(1/16))*Sqrt[3]*ArcTan[(1 - 2*Tan[8*x]^(2/3))/Sqrt[3]] - (1/16)*Log[1 + Tan[8*x]^(2/3)] + (1/32)*Log[1 - Tan[8*x]^(2/3) + Tan[8*x]^(4/3)]}


(* ::Subsection::Closed:: *)
(*x^m Tan[a+b x]^n*)


(* Integrands of the form x^m*Tan[a+b*x]^n where m and n are integers *)
{x*Tan[a + b*x], x, 4, (I*x^2)/2 - (x*Log[1 + E^(2*I*a + 2*I*b*x)])/b + (I*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/(2*b^2)}
{x*Tan[a + b*x]^2, x, 3, -x^2/2 + Log[Cos[a + b*x]]/b^2 + (x*Tan[a + b*x])/b}
{x*Tan[a + b*x]^3, x, 6, -((I*x^2)/2) + (x*Log[1 + E^(2*I*a + 2*I*b*x)])/b - (I*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/(2*b^2) + (x*Sec[a + b*x]^2)/(2*b) - Tan[a + b*x]/(2*b^2)}

{x^2*Tan[a + b*x], x, 5, (I*x^3)/3 - (x^2*Log[1 + E^(2*I*a + 2*I*b*x)])/b + (I*x*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/b^2 - PolyLog[3, -E^(2*I*a + 2*I*b*x)]/(2*b^3)}
{x^2*Tan[a + b*x]^2, x, 6, -((I*x^2)/b) - x^3/3 + (2*x*Log[1 + E^(2*I*a + 2*I*b*x)])/b^2 - (I*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/b^3 + (x^2*Tan[a + b*x])/b}
{x^2*Tan[a + b*x]^3, x, 9, -((I*x^3)/3) + (x^2*Log[1 + E^(2*I*a + 2*I*b*x)])/b - Log[Cos[a + b*x]]/b^3 - (I*x*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/b^2 + PolyLog[3, -E^(2*I*a + 2*I*b*x)]/(2*b^3) + (x^2*Sec[a + b*x]^2)/(2*b) - (x*Tan[a + b*x])/b^2}

{x^3*Tan[a + b*x], x, 6, (I*x^4)/4 - (x^3*Log[1 + E^(2*I*a + 2*I*b*x)])/b + (3*I*x^2*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/(2*b^2) - (3*x*PolyLog[3, -E^(2*I*a + 2*I*b*x)])/(2*b^3) - (3*I*PolyLog[4, -E^(2*I*a + 2*I*b*x)])/(4*b^4)}
{x^3*Tan[a + b*x]^2, x, 7, -((I*x^3)/b) - x^4/4 + (3*x^2*Log[1 + E^(2*I*a + 2*I*b*x)])/b^2 - (3*I*x*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/b^3 + (3*PolyLog[3, -E^(2*I*a + 2*I*b*x)])/(2*b^4) + (x^3*Tan[a + b*x])/b}
{x^3*Tan[a + b*x]^3, x, 13, (3*I*x^2)/(2*b^2) - (I*x^4)/4 - (3*x*Log[1 + E^(2*I*a + 2*I*b*x)])/b^3 + (x^3*Log[1 + E^(2*I*a + 2*I*b*x)])/b + (3*I*(1 - b^2*x^2)*PolyLog[2, -E^(2*I*a + 2*I*b*x)])/(2*b^4) + (3*x*PolyLog[3, -E^(2*I*a + 2*I*b*x)])/(2*b^3) + (3*I*PolyLog[4, -E^(2*I*a + 2*I*b*x)])/(4*b^4) + (x^3*Sec[a + b*x]^2)/(2*b) - (3*x^2*Tan[a + b*x])/(2*b^2)}

{Tan[a + b*x]/x, x, 0, Int[Tan[a + b*x]/x, x]}
{Tan[a + b*x]^2/x, x, 0, Int[Tan[a + b*x]^2/x, x]}
{Tan[a + b*x]^3/x, x, 0, Int[Tan[a + b*x]^3/x, x]}

{Tan[a + b*x]/x^2, x, 0, Int[Tan[a + b*x]/x^2, x]}
{Tan[a + b*x]^2/x^2, x, 0, Int[Tan[a + b*x]^2/x^2, x]}
{Tan[a + b*x]^3/x^2, x, 0, Int[Tan[a + b*x]^3/x^2, x]}

{Tan[a + b*x]/x^3, x, 0, Int[Tan[a + b*x]/x^3, x]}
{Tan[a + b*x]^2/x^3, x, 0, Int[Tan[a + b*x]^2/x^3, x]}
{Tan[a + b*x]^3/x^3, x, 0, Int[Tan[a + b*x]^3/x^3, x]}


(* ::Subsection::Closed:: *)
(*(a Tan[a+b x]^n)^m*)


(* Integrands of the form (a*Tan[x]^n)^m where n is an integer and m is a half-integer *)
{Sqrt[a*Tan[x]], x, 5, (a*ArcTan[Sqrt[a*Tan[x]]/(-a^2)^(1/4)])/(-a^2)^(1/4) - (a*ArcTanh[Sqrt[a*Tan[x]]/(-a^2)^(1/4)])/(-a^2)^(1/4)}
{Sqrt[Tan[x]^2], x, 2, (-Cot[x])*Log[Cos[x]]*Sqrt[Tan[x]^2]}
{Sqrt[a*Tan[x]^2], x, 2, (-Cot[x])*Log[Cos[x]]*Sqrt[a*Tan[x]^2]}
{Sqrt[a*Tan[x]^3], x, 10, (1/(4*Tan[x]^(3/2)))*((2*Sqrt[2]*ArcTan[1 - Sqrt[2]*Sqrt[Tan[x]]] - 2*Sqrt[2]*ArcTan[1 + Sqrt[2]*Sqrt[Tan[x]]] + Sqrt[2]*Log[1 - Sqrt[2]*Sqrt[Tan[x]] + Tan[x]] - Sqrt[2]*Log[1 + Sqrt[2]*Sqrt[Tan[x]] + Tan[x]] + 8*Sqrt[Tan[x]])*Sqrt[a*Tan[x]^3])}
{Sqrt[a*Tan[x]^4], x, 2, Cot[x]*Sqrt[a*Tan[x]^4] - x*Cot[x]^2*Sqrt[a*Tan[x]^4]}

{(a*Tan[x])^(3/2),x, 6, (-a)*(-a^2)^(1/4)*ArcTan[Sqrt[a*Tan[x]]/(-a^2)^(1/4)] - a*(-a^2)^(1/4)*ArcTanh[Sqrt[a*Tan[x]]/(-a^2)^(1/4)] + 2*a*Sqrt[a*Tan[x]]}
{(Tan[x]^2)^(3/2),x, 3, Cot[x]*Log[Cos[x]]*Sqrt[Tan[x]^2] + (1/2)*Cot[x]*(Tan[x]^2)^(3/2)}
{(a*Tan[x]^2)^(3/2),x, 3, a*Cot[x]*Log[Cos[x]]*Sqrt[a*Tan[x]^2] + (1/2)*a*Tan[x]*Sqrt[a*Tan[x]^2]}
{(a*Tan[x]^3)^(3/2),x, 11, -((1/(84*Tan[x]^(3/2)))*(a*Sqrt[a*Tan[x]^3]*(42*Sqrt[2]*ArcTan[1 - Sqrt[2]*Sqrt[Tan[x]]] - 42*Sqrt[2]*ArcTan[1 + Sqrt[2]*Sqrt[Tan[x]]] - 21*Sqrt[2]*Log[1 - Sqrt[2]*Sqrt[Tan[x]] + Tan[x]] + 21*Sqrt[2]*Log[1 + Sqrt[2]*Sqrt[Tan[x]] + Tan[x]] + 56*Tan[x]^(3/2) - 24*Tan[x]^(7/2))))}
{(a*Tan[x]^4)^(3/2),x, 4, a*Cot[x]*Sqrt[a*Tan[x]^4] - a*x*Cot[x]^2*Sqrt[a*Tan[x]^4] - (1/3)*a*Tan[x]*Sqrt[a*Tan[x]^4] + (1/5)*a*Tan[x]^3*Sqrt[a*Tan[x]^4]}

{1/Sqrt[a*Tan[x]], x, 5, ((-a^2)^(1/4)*ArcTan[Sqrt[a*Tan[x]]/(-a^2)^(1/4)])/a + ((-a^2)^(1/4)*ArcTanh[Sqrt[a*Tan[x]]/(-a^2)^(1/4)])/a}
{1/Sqrt[a*Tan[x]^2], x, 2, (Log[Sin[x]]*Tan[x])/Sqrt[a*Tan[x]^2]}
{1/Sqrt[a*Tan[x]^3], x, 11, -((1/(4*Sqrt[a*Tan[x]^3]))*((8 - Sqrt[2]*(2*ArcTan[1 - Sqrt[2]*Sqrt[Tan[x]]] - 2*ArcTan[1 + Sqrt[2]*Sqrt[Tan[x]]] - Log[1 - Sqrt[2]*Sqrt[Tan[x]] + Tan[x]] + Log[1 + Sqrt[2]*Sqrt[Tan[x]] + Tan[x]])*Sqrt[Tan[x]])*Tan[x]))}
{1/Sqrt[a*Tan[x]^4], x, 2, -(Tan[x]/Sqrt[a*Tan[x]^4]) - (x*Tan[x]^2)/Sqrt[a*Tan[x]^4]}


(* ::Subsection::Closed:: *)
(*(a+b Tan[c+d x])^n*)


(* Integrands of the form (a+b*Tan[x])^n where a^2+b^2 is nonzero *)
{(a + b*Tan[x])^4, x, 8, a^4*x - 6*a^2*b^2*x + b^4*x - 4*a^3*b*Log[Cos[x]] + 4*a*b^3*Log[Cos[x]] + 6*a^2*b^2*Tan[x] - b^4*Tan[x] + 2*a*b^3*Tan[x]^2 + (1/3)*b^4*Tan[x]^3}
{(a + b*Tan[x])^3, x, 6, a^3*x - 3*a*b^2*x - 3*a^2*b*Log[Cos[x]] + b^3*Log[Cos[x]] + 3*a*b^2*Tan[x] + (1/2)*b^3*Tan[x]^2}
{(a + b*Tan[x])^2, x, 4, a^2*x - b^2*x - 2*a*b*Log[Cos[x]] + b^2*Tan[x]}
{(a + b*Tan[x]), x, 2, a*x - b*Log[Cos[x]]}
{1/(a + b*Tan[x]), x, 1, (a*x)/(a^2 + b^2) + (b*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)}
{1/(a + b*Tan[x])^2, x, 3, (2*a^2*x)/(a^2 + b^2)^2 - x/(a^2 + b^2) + (2*a*b*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^2 - b/((a^2 + b^2)*(a + b*Tan[x]))}
{1/(a + b*Tan[x])^3, x, 4, (a*(3*a^2 - b^2)*x)/(a^2 + b^2)^3 - (2*a*x)/(a^2 + b^2)^2 + (b*(3*a^2 - b^2)*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^3 - b/(2*(a^2 + b^2)*(a + b*Tan[x])^2) - (2*a*b)/((a^2 + b^2)^2*(a + b*Tan[x]))}
{1/(a + b*Tan[x])^4, x, 5, (4*a^2*(a^2 - b^2)*x)/(a^2 + b^2)^4 - ((3*a^2 - b^2)*x)/(a^2 + b^2)^3 + (4*a*b*(a^2 - b^2)*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^4 - b/(3*(a^2 + b^2)*(a + b*Tan[x])^3) - (a*b)/((a^2 + b^2)^2*(a + b*Tan[x])^2) - (b*(3*a^2 - b^2))/((a^2 + b^2)^3*(a + b*Tan[x]))}

{1/(4 + 6*Tan[x]), x, 2, x/13 + (3/26)*Log[2*Cos[x] + 3*Sin[x]]}
{1/(4 - 6*Tan[x]), x, 2, x/13 - (3/26)*Log[2*Cos[x] - 3*Sin[x]]}

{(a + b*Tan[x])^(5/2), x, 5, -((I*(a^3 - 3*a*b^2 - I*b*(3*a^2 - b^2))*ArcTanh[Sqrt[a + b*Tan[x]]/Sqrt[a - I*b]])/Sqrt[a - I*b]) + (I*(a^3 - 3*a*b^2 + I*b*(3*a^2 - b^2))*ArcTanh[Sqrt[a + b*Tan[x]]/Sqrt[a + I*b]])/Sqrt[a + I*b] + 4*a*b*Sqrt[a + b*Tan[x]] + (2/3)*b*(a + b*Tan[x])^(3/2)}
{(a + b*Tan[x])^(3/2), x, 4, -((I*(a^2 - 2*I*a*b - b^2)*ArcTanh[Sqrt[a + b*Tan[x]]/Sqrt[a - I*b]])/Sqrt[a - I*b]) + (I*(a^2 + 2*I*a*b - b^2)*ArcTanh[Sqrt[a + b*Tan[x]]/Sqrt[a + I*b]])/Sqrt[a + I*b] + 2*b*Sqrt[a + b*Tan[x]]}
{(a + b*Tan[x])^(1/2), x, 3, (-I)*Sqrt[a - I*b]*ArcTanh[Sqrt[a + b*Tan[x]]/Sqrt[a - I*b]] + I*Sqrt[a + I*b]*ArcTanh[Sqrt[a + b*Tan[x]]/Sqrt[a + I*b]]}
{1/(a + b*Tan[x])^(1/2), x, 3, -((I*ArcTanh[Sqrt[a + b*Tan[x]]/Sqrt[a - I*b]])/Sqrt[a - I*b]) + (I*ArcTanh[Sqrt[a + b*Tan[x]]/Sqrt[a + I*b]])/Sqrt[a + I*b]}
{1/(a + b*Tan[x])^(3/2), x, 4, -((I*(a + I*b)*ArcTanh[Sqrt[a + b*Tan[x]]/Sqrt[a - I*b]])/(Sqrt[a - I*b]*(a^2 + b^2))) + (I*(a - I*b)*ArcTanh[Sqrt[a + b*Tan[x]]/Sqrt[a + I*b]])/(Sqrt[a + I*b]*(a^2 + b^2)) - (2*b)/((a^2 + b^2)*Sqrt[a + b*Tan[x]])}
{1/(a + b*Tan[x])^(5/2), x, 5, -((I*(a^2 + 2*I*a*b - b^2)*ArcTanh[Sqrt[a + b*Tan[x]]/Sqrt[a - I*b]])/(Sqrt[a - I*b]*(a^2 + b^2)^2)) + (I*(a^2 - 2*I*a*b - b^2)*ArcTanh[Sqrt[a + b*Tan[x]]/Sqrt[a + I*b]])/(Sqrt[a + I*b]*(a^2 + b^2)^2) - (2*b)/(3*(a^2 + b^2)*(a + b*Tan[x])^(3/2)) - (4*a*b)/((a^2 + b^2)^2*Sqrt[a + b*Tan[x]])}


(* Integrands of the form (a+b*Tan[x])^n where a^2+b^2 is zero *)
{(1 + I*Tan[x])^4, x, 8, 8*x - 8*I*Log[Cos[x]] - 7*Tan[x] - 2*I*Tan[x]^2 + Tan[x]^3/3}
{(1 + I*Tan[x])^3, x, 6, 4*x - 4*I*Log[Cos[x]] - 3*Tan[x] - (1/2)*I*Tan[x]^2}
{(1 + I*Tan[x])^2, x, 4, 2*x - 2*I*Log[Cos[x]] - Tan[x]}
{(1 + I*Tan[x]), x, 2, x - I*Log[Cos[x]]}
{1/(1 + I*Tan[x]), x, 1, x/2 + I/(2*(1 + I*Tan[x]))}
{1/(1 + I*Tan[x])^2, x, 2, x/4 + I/(4*(1 + I*Tan[x])^2) + I/(4*(1 + I*Tan[x]))}
{1/(1 + I*Tan[x])^3, x, 3, x/8 + I/(6*(1 + I*Tan[x])^3) + I/(8*(1 + I*Tan[x])^2) + I/(8*(1 + I*Tan[x]))}
{1/(1 + I*Tan[x])^4, x, 4, x/16 + I/(8*(1 + I*Tan[x])^4) + I/(12*(1 + I*Tan[x])^3) + I/(16*(1 + I*Tan[x])^2) + I/(16*(1 + I*Tan[x]))}

{(1 + I*Tan[x])^(5/2), x, 3, -4*I*Sqrt[2]*ArcTanh[Sqrt[1 + I*Tan[x]]/Sqrt[2]] + 4*I*Sqrt[1 + I*Tan[x]] + (2/3)*I*(1 + I*Tan[x])^(3/2)}
{(1 + I*Tan[x])^(3/2), x, 2, -2*I*Sqrt[2]*ArcTanh[Sqrt[1 + I*Tan[x]]/Sqrt[2]] + 2*I*Sqrt[1 + I*Tan[x]]}
{(1 + I*Tan[x])^(1/2), x, 1, (-I)*Sqrt[2]*ArcTanh[Sqrt[1 + I*Tan[x]]/Sqrt[2]]}
{1/(1 + I*Tan[x])^(1/2), x, 2, -((I*ArcTanh[Sqrt[1 + I*Tan[x]]/Sqrt[2]])/Sqrt[2]) + I/Sqrt[1 + I*Tan[x]]}
{1/(1 + I*Tan[x])^(3/2), x, 3, -((I*ArcTanh[Sqrt[1 + I*Tan[x]]/Sqrt[2]])/(2*Sqrt[2])) + I/(3*(1 + I*Tan[x])^(3/2)) + I/(2*Sqrt[1 + I*Tan[x]])}
{1/(1 + I*Tan[x])^(5/2), x, 4, -((I*ArcTanh[Sqrt[1 + I*Tan[x]]/Sqrt[2]])/(4*Sqrt[2])) + I/(5*(1 + I*Tan[x])^(5/2)) + I/(6*(1 + I*Tan[x])^(3/2)) + I/(4*Sqrt[1 + I*Tan[x]])}


(* ::Subsection::Closed:: *)
(*(A+B Tan[c+d x]) (a+b Tan[c+d x])^n*)


{(A + B*Tan[c + d*x])/(a + b*Tan[c + d*x]), x, 2, ((a*A + b*B)*x)/(a^2 + b^2) + ((A*b - a*B)*Log[a*Cos[c + d*x] + b*Sin[c + d*x]])/((a^2 + b^2)*d)}
{(A + B*Tan[c + d*x])/(a + b*Tan[c + d*x])^2, x, 3, -(((A*b - a*B)*x)/(b*(a^2 + b^2))) + (a*(b^2*B + a*(2*A*b - a*B))*x)/(b*(a^2 + b^2)^2) + ((b^2*B + a*(2*A*b - a*B))*Log[a*Cos[c + d*x] + b*Sin[c + d*x]])/((a^2 + b^2)^2*d) - (A*b - a*B)/((a^2 + b^2)*d*(a + b*Tan[c + d*x]))}
{(A + B*Tan[c + d*x])/(a + b*Tan[c + d*x])^3, x, 4, -(((b^2*B + a*(2*A*b - a*B))*x)/(b*(a^2 + b^2)^2)) + (a*(b*(a^2*A - b*(A*b - 2*a*B)) + a*(b^2*B + a*(2*A*b - a*B)))*x)/(b*(a^2 + b^2)^3) + ((b*(a^2*A - b*(A*b - 2*a*B)) + a*(b^2*B + a*(2*A*b - a*B)))*Log[a*Cos[c + d*x] + b*Sin[c + d*x]])/((a^2 + b^2)^3*d) - (A*b - a*B)/(2*(a^2 + b^2)*d*(a + b*Tan[c + d*x])^2) - (b^2*B + a*(2*A*b - a*B))/((a^2 + b^2)^2*d*(a + b*Tan[c + d*x]))}


{(1 + I*Tan[c + d*x])/Sqrt[a + b*Tan[c + d*x]], x, 1, -((2*I*ArcTanh[Sqrt[a + b*Tan[c + d*x]]/Sqrt[a - I*b]])/(Sqrt[a - I*b]*d))}
{(1 - I*Tan[c + d*x])/Sqrt[a + b*Tan[c + d*x]], x, 1, (2*I*ArcTanh[Sqrt[a + b*Tan[c + d*x]]/Sqrt[a + I*b]])/(Sqrt[a + I*b]*d)}

{(A + B*Tan[c + d*x])*(a + b*Tan[c + d*x])^(5/2), x, 6, -((I*(b*(b^2*B - a*(2*A*b + a*B)) + a*(a^2*A - b*(A*b + 2*a*B)) + I*(a*(b^2*B - a*(2*A*b + a*B)) - b*(a^2*A - b*(A*b + 2*a*B))))*ArcTanh[Sqrt[a + b*Tan[c + d*x]]/Sqrt[a - I*b]])/(Sqrt[a - I*b]*d)) + (I*(b*(b^2*B - a*(2*A*b + a*B)) + a*(a^2*A - b*(A*b + 2*a*B)) - I*(a*(b^2*B - a*(2*A*b + a*B)) - b*(a^2*A - b*(A*b + 2*a*B))))*ArcTanh[Sqrt[a + b*Tan[c + d*x]]/Sqrt[a + I*b]])/(Sqrt[a + I*b]*d) - (2*(b^2*B - a*(2*A*b + a*B))*Sqrt[a + b*Tan[c + d*x]])/d + (2*(A*b + a*B)*(a + b*Tan[c + d*x])^(3/2))/(3*d) + (2*B*(a + b*Tan[c + d*x])^(5/2))/(5*d)}
{(A + B*Tan[c + d*x])*(a + b*Tan[c + d*x])^(3/2), x, 5, -((I*(a^2*A - b*(A*b + 2*a*B) + I*(b^2*B - a*(2*A*b + a*B)))*ArcTanh[Sqrt[a + b*Tan[c + d*x]]/Sqrt[a - I*b]])/(Sqrt[a - I*b]*d)) + (I*(a^2*A - b*(A*b + 2*a*B) - I*(b^2*B - a*(2*A*b + a*B)))*ArcTanh[Sqrt[a + b*Tan[c + d*x]]/Sqrt[a + I*b]])/(Sqrt[a + I*b]*d) + (2*(A*b + a*B)*Sqrt[a + b*Tan[c + d*x]])/d + (2*B*(a + b*Tan[c + d*x])^(3/2))/(3*d)}
{(A + B*Tan[c + d*x])*(a + b*Tan[c + d*x])^(1/2), x, 4, -((I*(a*A - b*B - I*(A*b + a*B))*ArcTanh[Sqrt[a + b*Tan[c + d*x]]/Sqrt[a - I*b]])/(Sqrt[a - I*b]*d)) + (I*(a*A - b*B + I*(A*b + a*B))*ArcTanh[Sqrt[a + b*Tan[c + d*x]]/Sqrt[a + I*b]])/(Sqrt[a + I*b]*d) + (2*B*Sqrt[a + b*Tan[c + d*x]])/d}
{(A + B*Tan[c + d*x])/(a + b*Tan[c + d*x])^(1/2), x, 3, -((I*(A - I*B)*ArcTanh[Sqrt[a + b*Tan[c + d*x]]/Sqrt[a - I*b]])/(Sqrt[a - I*b]*d)) + (I*(A + I*B)*ArcTanh[Sqrt[a + b*Tan[c + d*x]]/Sqrt[a + I*b]])/(Sqrt[a + I*b]*d)}
{(A + B*Tan[c + d*x])/(a + b*Tan[c + d*x])^(3/2), x, 4, -((I*(a*A + b*B + I*(A*b - a*B))*ArcTanh[Sqrt[a + b*Tan[c + d*x]]/Sqrt[a - I*b]])/(Sqrt[a - I*b]*(a^2 + b^2)*d)) + (I*(a*A + b*B - I*(A*b - a*B))*ArcTanh[Sqrt[a + b*Tan[c + d*x]]/Sqrt[a + I*b]])/(Sqrt[a + I*b]*(a^2 + b^2)*d) - (2*(A*b - a*B))/((a^2 + b^2)*d*Sqrt[a + b*Tan[c + d*x]])}
{(A + B*Tan[c + d*x])/(a + b*Tan[c + d*x])^(5/2), x, 5, -((I*(a^2*A - b*(A*b - 2*a*B) + I*(b^2*B + a*(2*A*b - a*B)))*ArcTanh[Sqrt[a + b*Tan[c + d*x]]/Sqrt[a - I*b]])/(Sqrt[a - I*b]*(a^2 + b^2)^2*d)) + (I*(a^2*A - b*(A*b - 2*a*B) - I*(b^2*B + a*(2*A*b - a*B)))*ArcTanh[Sqrt[a + b*Tan[c + d*x]]/Sqrt[a + I*b]])/(Sqrt[a + I*b]*(a^2 + b^2)^2*d) - (2*(A*b - a*B))/(3*(a^2 + b^2)*d*(a + b*Tan[c + d*x])^(3/2)) - (2*(b^2*B + a*(2*A*b - a*B)))/((a^2 + b^2)^2*d*Sqrt[a + b*Tan[c + d*x]])}

{(-a + b*Tan[c + d*x])*(a + b*Tan[c + d*x])^(5/2), x, 5, (I*(a^2 - 2*I*a*b - b^2)*(a^2 + b^2)*ArcTanh[Sqrt[a + b*Tan[c + d*x]]/Sqrt[a - I*b]])/(Sqrt[a - I*b]*d) - (I*(a^2 + 2*I*a*b - b^2)*(a^2 + b^2)*ArcTanh[Sqrt[a + b*Tan[c + d*x]]/Sqrt[a + I*b]])/(Sqrt[a + I*b]*d) - (2*b*(a^2 + b^2)*Sqrt[a + b*Tan[c + d*x]])/d + (2*b*(a + b*Tan[c + d*x])^(5/2))/(5*d)}
{(-a + b*Tan[c + d*x])*(a + b*Tan[c + d*x])^(3/2), x, 4, (I*Sqrt[a - I*b]*(a^2 + b^2)*ArcTanh[Sqrt[a + b*Tan[c + d*x]]/Sqrt[a - I*b]])/d - (I*Sqrt[a + I*b]*(a^2 + b^2)*ArcTanh[Sqrt[a + b*Tan[c + d*x]]/Sqrt[a + I*b]])/d + (2*b*(a + b*Tan[c + d*x])^(3/2))/(3*d)}
{(-a + b*Tan[c + d*x])*(a + b*Tan[c + d*x])^(1/2), x, 4, (I*(a^2 + b^2)*ArcTanh[Sqrt[a + b*Tan[c + d*x]]/Sqrt[a - I*b]])/(Sqrt[a - I*b]*d) - (I*(a^2 + b^2)*ArcTanh[Sqrt[a + b*Tan[c + d*x]]/Sqrt[a + I*b]])/(Sqrt[a + I*b]*d) + (2*b*Sqrt[a + b*Tan[c + d*x]])/d}
{(-a + b*Tan[c + d*x])/(a + b*Tan[c + d*x])^(1/2), x, 3, (I*(a + I*b)*ArcTanh[Sqrt[a + b*Tan[c + d*x]]/Sqrt[a - I*b]])/(Sqrt[a - I*b]*d) - (I*(a - I*b)*ArcTanh[Sqrt[a + b*Tan[c + d*x]]/Sqrt[a + I*b]])/(Sqrt[a + I*b]*d)}
{(-a + b*Tan[c + d*x])/(a + b*Tan[c + d*x])^(3/2), x, 4, (I*(a^2 + 2*I*a*b - b^2)*ArcTanh[Sqrt[a + b*Tan[c + d*x]]/Sqrt[a - I*b]])/(Sqrt[a - I*b]*(a^2 + b^2)*d) - (I*(a^2 - 2*I*a*b - b^2)*ArcTanh[Sqrt[a + b*Tan[c + d*x]]/Sqrt[a + I*b]])/(Sqrt[a + I*b]*(a^2 + b^2)*d) + (4*a*b)/((a^2 + b^2)*d*Sqrt[a + b*Tan[c + d*x]])}
{(-a + b*Tan[c + d*x])/(a + b*Tan[c + d*x])^(5/2), x, 5, (I*(a^3 - 3*a*b^2 + I*b*(3*a^2 - b^2))*ArcTanh[Sqrt[a + b*Tan[c + d*x]]/Sqrt[a - I*b]])/(Sqrt[a - I*b]*(a^2 + b^2)^2*d) - (I*(a^3 - 3*a*b^2 - I*b*(3*a^2 - b^2))*ArcTanh[Sqrt[a + b*Tan[c + d*x]]/Sqrt[a + I*b]])/(Sqrt[a + I*b]*(a^2 + b^2)^2*d) + (4*a*b)/(3*(a^2 + b^2)*d*(a + b*Tan[c + d*x])^(3/2)) + (2*b*(3*a^2 - b^2))/((a^2 + b^2)^2*d*Sqrt[a + b*Tan[c + d*x]])}


(* ::Subsection::Closed:: *)
(*(a+b Tan[c+d x]^n)^m*)


{1/(1 + 2*Tan[x]^2), x, 1, -x + Sqrt[2]*ArcTan[Sqrt[2]*Tan[x]]}
{1/(1 - 2*Tan[x]^2), x, 1, x/3 + (1/3)*Sqrt[2]*ArcTanh[Sqrt[2]*Tan[x]]}

{1/(1 + Tan[x]^3), x, 8, x/2 + (1/4)*Log[Sec[x]^2] - (1/3)*Log[Sec[x]^2 - Tan[x]] + (1/6)*Log[1 + Tan[x]], (1/4)*Log[Sec[x]^2] - (1/3)*Log[Sec[x]^2 - Tan[x]] + (1/6)*Log[1 + Tan[x]] + (1/2)*Pi*Mods[x/Pi]}


(* Integrands of the form (a+b*Tan[x]^2)^m where m is a half-integer *)
{Sqrt[1 + Tan[x]^2], x, 3, ArcSinh[Tan[x]]}
{Sqrt[1 - Tan[x]^2], x, 4, -ArcSin[Tan[x]] + Sqrt[2]*ArcTan[(Sqrt[2]*Tan[x])/Sqrt[1 - Tan[x]^2]]}
{Sqrt[-1 + Tan[x]^2], x, 4, ArcTanh[Tan[x]/Sqrt[-1 + Tan[x]^2]] - Sqrt[2]*ArcTanh[(Sqrt[2]*Tan[x])/Sqrt[-1 + Tan[x]^2]]}
{Sqrt[-1 - Tan[x]^2], x, 3, ArcTanh[Sin[x]]*Cos[x]*Sqrt[-Sec[x]^2]}
{Sqrt[a + b*Tan[x]^2], x, 4, Sqrt[a - b]*ArcTan[(Sqrt[a - b]*Tan[x])/Sqrt[a + b*Tan[x]^2]] + Sqrt[b]*ArcTanh[(Sqrt[b]*Tan[x])/Sqrt[a + b*Tan[x]^2]]}

{1/Sqrt[1 + Tan[x]^2], x, 3, Tan[x]/Sqrt[Sec[x]^2]}
{1/Sqrt[1 - Tan[x]^2], x, 2, ArcTan[(Sqrt[2]*Tan[x])/Sqrt[1 - Tan[x]^2]]/Sqrt[2]}
{1/Sqrt[-1 + Tan[x]^2], x, 2, ArcTanh[(Sqrt[2]*Tan[x])/Sqrt[-1 + Tan[x]^2]]/Sqrt[2]}
{1/Sqrt[-1 - Tan[x]^2], x, 3, Tan[x]/Sqrt[-Sec[x]^2]}
{1/Sqrt[a + b*Tan[x]^2], x, 2, ArcTan[(Sqrt[a - b]*Tan[x])/Sqrt[a + b*Tan[x]^2]]/Sqrt[a - b]}

{(1 + Tan[x]^2)^(3/2), x, 4, (1/2)*ArcSinh[Tan[x]] + (1/2)*Sqrt[Sec[x]^2]*Tan[x]}
{(1 - Tan[x]^2)^(3/2), x, 7, (-(5/2))*ArcSin[Tan[x]] + 2*Sqrt[2]*ArcTan[(Sqrt[2]*Tan[x])/Sqrt[1 - Tan[x]^2]] - (1/2)*Tan[x]*Sqrt[1 - Tan[x]^2]}
{(-1 + Tan[x]^2)^(3/2), x, 7, (-(5/2))*ArcTanh[Tan[x]/Sqrt[-1 + Tan[x]^2]] + 2*Sqrt[2]*ArcTanh[(Sqrt[2]*Tan[x])/Sqrt[-1 + Tan[x]^2]] + (1/2)*Tan[x]*Sqrt[-1 + Tan[x]^2]}
{(-1 - Tan[x]^2)^(3/2), x, 4, (-(1/2))*Cos[x]*Sqrt[-Sec[x]^2]*(ArcTanh[Sin[x]] + Sec[x]*Tan[x])}
{(a + b*Tan[x]^2)^(3/2), x, 7, (a - b)^(3/2)*ArcTan[(Sqrt[a - b]*Tan[x])/Sqrt[a + b*Tan[x]^2]] + (3/2)*a*Sqrt[b]*ArcTanh[(Sqrt[b]*Tan[x])/Sqrt[a + b*Tan[x]^2]] - b^(3/2)*ArcTanh[(Sqrt[b]*Tan[x])/Sqrt[a + b*Tan[x]^2]] + (1/2)*b*Tan[x]*Sqrt[a + b*Tan[x]^2]}


(* ::Subsection::Closed:: *)
(*x^m Tan[a+b Log[c x^n]]^p*)


(* Integrands of the form Tan[a+b*Log[c*x^n]]^p/x where p is an integer *)
{Tan[a + b*Log[c*x^n]]/x, x, 2, -(Log[Cos[a + b*Log[c*x^n]]]/(b*n))}
{Tan[a + b*Log[c*x^n]]^2/x, x, 2, -(Log[c*x^n]/n) + Tan[a + b*Log[c*x^n]]/(b*n)}
{Tan[a + b*Log[c*x^n]]^3/x, x, 3, Log[Cos[a + b*Log[c*x^n]]]/(b*n) + Tan[a + b*Log[c*x^n]]^2/(2*b*n)}
{Tan[a + b*Log[c*x^n]]^4/x, x, 3, Log[c*x^n]/n - Tan[a + b*Log[c*x^n]]/(b*n) + Tan[a + b*Log[c*x^n]]^3/(3*b*n)}
{Tan[a + b*Log[c*x^n]]^5/x, x, 4, -(Log[Cos[a + b*Log[c*x^n]]]/(b*n)) - Tan[a + b*Log[c*x^n]]^2/(2*b*n) + Tan[a + b*Log[c*x^n]]^4/(4*b*n)}


(* Integrands of the form Tan[a+b*Log[c*x^n]]^p/x where p is a half-integer *)
{Tan[a + b*Log[c*x^n]]^(5/2)/x, x, 9, ArcTan[1 - Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) - ArcTan[1 + Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) - Log[1 - Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]] + Tan[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n) + Log[1 + Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]] + Tan[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n) + (2*Tan[a + b*Log[c*x^n]]^(3/2))/(3*b*n)}
{Tan[a + b*Log[c*x^n]]^(3/2)/x, x, 9, ArcTan[1 - Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) - ArcTan[1 + Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) + Log[1 - Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]] + Tan[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n) - Log[1 + Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]] + Tan[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n) + (2*Sqrt[Tan[a + b*Log[c*x^n]]])/(b*n)}
{Sqrt[Tan[a + b*Log[c*x^n]]]/x, x, 8, -(ArcTan[1 - Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n)) + ArcTan[1 + Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) + Log[1 - Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]] + Tan[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n) - Log[1 + Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]] + Tan[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n)}
{1/(x*Sqrt[Tan[a + b*Log[c*x^n]]]), x, 8, -(ArcTan[1 - Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n)) + ArcTan[1 + Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) - Log[1 - Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]] + Tan[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n) + Log[1 + Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]] + Tan[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n)}
{1/(x*Tan[a + b*Log[c*x^n]]^(3/2)), x, 9, ArcTan[1 - Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) - ArcTan[1 + Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) - Log[1 - Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]] + Tan[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n) + Log[1 + Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]] + Tan[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n) - 2/(b*n*Sqrt[Tan[a + b*Log[c*x^n]]])}
{1/(x*Tan[a + b*Log[c*x^n]]^(5/2)), x, 9, ArcTan[1 - Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) - ArcTan[1 + Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]]]/(Sqrt[2]*b*n) + Log[1 - Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]] + Tan[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n) - Log[1 + Sqrt[2]*Sqrt[Tan[a + b*Log[c*x^n]]] + Tan[a + b*Log[c*x^n]]]/(2*Sqrt[2]*b*n) - 2/(3*b*n*Tan[a + b*Log[c*x^n]]^(3/2))}


(* ::Subsection::Closed:: *)
(*Miscellaneous integrands involving tangents*)


{Tan[Sqrt[x]]/Sqrt[x], x, 2, -2*Log[Cos[Sqrt[x]]]}
{Tan[Sqrt[x]]^2/Sqrt[x], x, 2, -2*Sqrt[x] + 2*Tan[Sqrt[x]]}


{Tan[x]/Sqrt[1 + I*Tan[x]], x, 6, -(ArcTanh[Sqrt[1 + I*Tan[x]]/Sqrt[2]]/Sqrt[2]) - 1/Sqrt[1 + I*Tan[x]]}
{Tan[x]/Sqrt[I + Tan[x]], x, 6, (1/2 + I/2)*ArcTan[(1/2 + I/2)*Sqrt[I + Tan[x]]] - 1/Sqrt[I + Tan[x]]}
