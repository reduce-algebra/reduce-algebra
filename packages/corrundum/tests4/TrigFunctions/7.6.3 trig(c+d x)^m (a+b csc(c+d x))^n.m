(* ::Package:: *)

(* ::Title:: *)
(*Integrands of the form trig(c+d x)^m (a+b csc(c+d x))^n*)


(* ::Section:: *)
(*Integrands of the form Cos[c+d x]^m (a+b Csc[c+d x])^n when a^2-b^2=0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (a+b Csc[c+d x])^n when a^2-b^2=0*)


{Cos[x]^4/(a + a*Csc[x]), x, 3, -(x/(8*a)) - Cos[x]^3/(3*a) - (Cos[x]*Sin[x])/(8*a) + (Cos[x]^3*Sin[x])/(4*a)}
{Cos[x]^3/(a + a*Csc[x]), x, 2, -(Cos[x]^2/(2*a)) - Sin[x]^3/(3*a)}
{Cos[x]^2/(a + a*Csc[x]), x, 2, -(x/(2*a)) - Cos[x]/a + (Cos[x]*Sin[x])/(2*a)}
{Cos[x]^1/(a + a*Csc[x]), x, 3, -(Log[1 + Sin[x]]/a) + Sin[x]/a}
{Sec[x]^1/(a + a*Csc[x]), x, 3, ArcTanh[Sin[x]]/(2*a) + Sec[x]^2/(2*a) - (Sec[x]*Tan[x])/(2*a)}
{Sec[x]^2/(a + a*Csc[x]), x, 3, Sec[x]^3/(3*a) - Tan[x]^3/(3*a)}
{Sec[x]^3/(a + a*Csc[x]), x, 4, ArcTanh[Sin[x]]/(8*a) + Sec[x]^4/(4*a) - (Sec[x]*Tan[x])/(8*a) - (Sec[x]*Tan[x]^3)/(4*a)}
{Sec[x]^4/(a + a*Csc[x]), x, 4, Sec[x]^5/(5*a) - Tan[x]^3/(3*a) - Tan[x]^5/(5*a)}


(* ::Subsection:: *)
(*Integrands of the form Cos[c+d x]^m (a+b Csc[c+d x])^(n/2) when a^2-b^2=0*)


(* ::Section:: *)
(*Integrands of the form Cos[c+d x]^m (a+b Csc[c+d x])^n*)


(* ::Subsection:: *)
(*Integrands of the form Cos[c+d x]^m (a+b Csc[c+d x])^n*)


{Cos[x]^4/(a + b*Csc[x]), x, 7, -(x/(8*a)) - ((a^2 - b^2)*x)/(2*a^3) + ((a^2 - b^2)^2*x)/a^5 + (2*b*(a^2 - b^2)^(3/2)*ArcTanh[(a + b*Tan[x/2])/Sqrt[a^2 - b^2]])/a^5 - (b*(a^2 - b^2)*Cos[x])/a^4 - (b*Cos[x]^3)/(3*a^2) - (Cos[x]*Sin[x])/(8*a) + ((a^2 - b^2)*Cos[x]*Sin[x])/(2*a^3) + (Cos[x]^3*Sin[x])/(4*a)}
{Cos[x]^3/(a + b*Csc[x]), x, 3, -((b*(a^2 - b^2)*Log[b + a*Sin[x]])/a^4) + ((a^2 - b^2)*Sin[x])/a^3 + (b*Sin[x]^2)/(2*a^2) - Sin[x]^3/(3*a)}
{Cos[x]^2/(a + b*Csc[x]), x, 4, -(x/(2*a)) + ((a^2 - b^2)*x)/a^3 + (2*b*Sqrt[a^2 - b^2]*ArcTanh[(a + b*Tan[x/2])/Sqrt[a^2 - b^2]])/a^3 - (b*Cos[x])/a^2 + (Cos[x]*Sin[x])/(2*a)}
{Cos[x]^1/(a + b*Csc[x]), x, 3, -((b*Log[b + a*Sin[x]])/a^2) + Sin[x]/a}
{Sec[x]^1/(a + b*Csc[x]), x, 6, -(Log[1 - Sin[x]]/(2*(a + b))) + Log[1 + Sin[x]]/(2*(a - b)) - (b*Log[b + a*Sin[x]])/(a^2 - b^2)}
{Sec[x]^2/(a + b*Csc[x]), x, 5, (2*a*b*ArcTanh[(a + b*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(3/2) - (b*Sec[x])/(a^2 - b^2) + (a*Tan[x])/(a^2 - b^2)}
{Sec[x]^3/(a + b*Csc[x]), x, 7, -((a*Log[1 - Sin[x]])/(4*(a + b)^2)) + (a*Log[1 + Sin[x]])/(4*(a - b)^2) - (a^2*b*Log[b + a*Sin[x]])/(a^2 - b^2)^2 - (b - a*Sin[x])/(2*(a^2 - b^2)*(1 - Sin[x]^2))}
{Sec[x]^4/(a + b*Csc[x]), x, 8, (2*a^3*b*ArcTanh[(a + b*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(5/2) - (a^2*b*Sec[x])/(a^2 - b^2)^2 - (b*Sec[x]^3)/(3*(a^2 - b^2)) + (a^3*Tan[x])/(a^2 - b^2)^2 + (a*Tan[x]^3)/(3*(a^2 - b^2))}


(* ::Subsection:: *)
(*Integrands of the form Cos[c+d x]^m (a+b Csc[c+d x])^(n/2)*)


(* ::Section:: *)
(*Integrands of the form Tan[c+d x]^m (a+b Csc[c+d x])^n when a^2-b^2=0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Tan[c+d x]^m (a+b Csc[c+d x])^n when a^2-b^2=0*)


{Tan[x]^4/(a + a*Csc[x]), x, 8, x/a + Sec[x]/a - (2*Sec[x]^3)/(3*a) + Sec[x]^5/(5*a) - Tan[x]/a + Tan[x]^3/(3*a) - Tan[x]^5/(5*a)}
{Tan[x]^3/(a + a*Csc[x]), x, 7, (3*ArcTanh[Sin[x]])/(8*a) + Log[Cos[x]]/a - (3*Sec[x]*Tan[x])/(8*a) + Tan[x]^2/(2*a) + (Sec[x]*Tan[x]^3)/(4*a) - Tan[x]^4/(4*a)}
{Tan[x]^2/(a + a*Csc[x]), x, 6, -(x/a) - Sec[x]/a + Sec[x]^3/(3*a) + Tan[x]/a - Tan[x]^3/(3*a)}
{Tan[x]^1/(a + a*Csc[x]), x, 5, -(ArcTanh[Sin[x]]/(2*a)) - Log[Cos[x]]/a + (Sec[x]*Tan[x])/(2*a) - Tan[x]^2/(2*a)}
{Cot[x]^1/(a + a*Csc[x]), x, 2, Log[1 + Sin[x]]/a}
{Cot[x]^2/(a + a*Csc[x]), x, 3, -(x/a) - ArcTanh[Cos[x]]/a}
{Cot[x]^3/(a + a*Csc[x]), x, 3, -(Csc[x]/a) - Log[Sin[x]]/a}
{Cot[x]^4/(a + a*Csc[x]), x, 5, x/a + ArcTanh[Cos[x]]/(2*a) + Cot[x]/a - (Cot[x]*Csc[x])/(2*a)}


(* ::Subsection:: *)
(*Integrands of the form Tan[c+d x]^m (a+b Csc[c+d x])^(n/2) when a^2-b^2=0*)


(* ::Section:: *)
(*Integrands of the form Tan[c+d x]^m (a+b Csc[c+d x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Tan[c+d x]^m (a+b Csc[c+d x])^n*)


{Tan[x]^4/(a + b*Csc[x]), x, 12, x/a + (2*b^5*ArcTanh[(a + b*Tan[x/2])/Sqrt[a^2 - b^2]])/(a*(a^2 - b^2)^(5/2)) - (b^3*Sec[x])/(a^2 - b^2)^2 + (b*Sec[x])/(a^2 - b^2) - (b*Sec[x]^3)/(3*(a^2 - b^2)) + (a*b^2*Tan[x])/(a^2 - b^2)^2 - (a*Tan[x])/(a^2 - b^2) + (a*Tan[x]^3)/(3*(a^2 - b^2)), -((a*b^2*x)/(a^2 - b^2)^2) + (b^4*x)/(a*(a^2 - b^2)^2) + (a*x)/(a^2 - b^2) + (2*b^5*ArcTanh[(a + b*Tan[x/2])/Sqrt[a^2 - b^2]])/(a*(a^2 - b^2)^(5/2)) - (b^3*Sec[x])/(a^2 - b^2)^2 + (b*Sec[x])/(a^2 - b^2) - (b*Sec[x]^3)/(3*(a^2 - b^2)) + (a*b^2*Tan[x])/(a^2 - b^2)^2 - (a*Tan[x])/(a^2 - b^2) + (a*Tan[x]^3)/(3*(a^2 - b^2))}
{Tan[x]^3/(a + b*Csc[x]), x, 3, ((2*a + 3*b)*Log[1 - Sin[x]])/(4*(a + b)^2) + ((2*a - 3*b)*Log[1 + Sin[x]])/(4*(a - b)^2) + (b^4*Log[b + a*Sin[x]])/(a*(a^2 - b^2)^2) + 1/(4*(a + b)*(1 - Sin[x])) + 1/(4*(a - b)*(1 + Sin[x]))}
{Tan[x]^2/(a + b*Csc[x]), x, 6, -(x/a) + (2*b^3*ArcTanh[(a + b*Tan[x/2])/Sqrt[a^2 - b^2]])/(a*(a^2 - b^2)^(3/2)) - (b*Sec[x])/(a^2 - b^2) + (a*Tan[x])/(a^2 - b^2), -((a*x)/(a^2 - b^2)) + (b^2*x)/(a*(a^2 - b^2)) + (2*b^3*ArcTanh[(a + b*Tan[x/2])/Sqrt[a^2 - b^2]])/(a*(a^2 - b^2)^(3/2)) - (b*Sec[x])/(a^2 - b^2) + (a*Tan[x])/(a^2 - b^2)}
{Tan[x]^1/(a + b*Csc[x]), x, 3, -(Log[1 - Sin[x]]/(2*(a + b))) - Log[1 + Sin[x]]/(2*(a - b)) + (b^2*Log[b + a*Sin[x]])/(a*(a^2 - b^2))}
{Cot[x]^1/(a + b*Csc[x]), x, 2, Log[b + a*Sin[x]]/a}
{Cot[x]^2/(a + b*Csc[x]), x, 5, -(x/a) - ArcTanh[Cos[x]]/b + (2*Sqrt[a^2 - b^2]*ArcTanh[(a + b*Tan[x/2])/Sqrt[a^2 - b^2]])/(a*b), -(((1 - a^2/b^2)*x)/a) - (a*x)/b^2 - ArcTanh[Cos[x]]/b + (2*Sqrt[a^2 - b^2]*ArcTanh[(a + b*Tan[x/2])/Sqrt[a^2 - b^2]])/(a*b)}
{Cot[x]^3/(a + b*Csc[x]), x, 3, -(Csc[x]/b) - (a*Log[Sin[x]])/b^2 - ((1 - a^2/b^2)*Log[b + a*Sin[x]])/a}
{Cot[x]^4/(a + b*Csc[x]), x, 10, x/a - (a^2*ArcTanh[Cos[x]])/b^3 + (3*ArcTanh[Cos[x]])/(2*b) + (2*(a^2 - b^2)^(3/2)*ArcTanh[(a + b*Tan[x/2])/Sqrt[a^2 - b^2]])/(a*b^3) + (a*Cot[x])/b^2 - (Cot[x]*Csc[x])/(2*b), (a*x)/b^2 - (a*(a^2 - b^2)*x)/b^4 + ((a^2 - b^2)^2*x)/(a*b^4) + ArcTanh[Cos[x]]/(2*b) - ((a^2 - b^2)*ArcTanh[Cos[x]])/b^3 + (2*(a^2 - b^2)^(3/2)*ArcTanh[(a + b*Tan[x/2])/Sqrt[a^2 - b^2]])/(a*b^3) + (a*Cot[x])/b^2 - (Cot[x]*Csc[x])/(2*b)}


(* ::Subsection:: *)
(*Integrands of the form Tan[c+d x]^m (a+b Csc[c+d x])^(n/2)*)
