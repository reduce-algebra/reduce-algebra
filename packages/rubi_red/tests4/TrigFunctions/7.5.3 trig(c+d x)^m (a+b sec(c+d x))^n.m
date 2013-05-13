(* ::Package:: *)

(* ::Title:: *)
(*Integrands of the form trig(c+d x)^m (a+b sec(c+d x))^n*)


(* ::Section::Closed:: *)
(*Integrands of the form Sin[c+d x]^m (a+b Sec[c+d x])^n when a^2-b^2=0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[c+d x]^m (a+b Sec[c+d x])^n when a^2-b^2=0*)


{Sin[c + d*x]^7/(a + a*Sec[c + d*x]), x, 4, Cos[c + d*x]^3/(3*a*d) - (2*Cos[c + d*x]^5)/(5*a*d) + Cos[c + d*x]^7/(7*a*d) + Sin[c + d*x]^6/(6*a*d)}
{Sin[c + d*x]^6/(a + a*Sec[c + d*x]), x, 4, -(x/(16*a)) - (Cos[c + d*x]*Sin[c + d*x])/(16*a*d) + (Cos[c + d*x]^3*Sin[c + d*x])/(8*a*d) + (Cos[c + d*x]^3*Sin[c + d*x]^3)/(6*a*d) + Sin[c + d*x]^5/(5*a*d)}
{Sin[c + d*x]^5/(a + a*Sec[c + d*x]), x, 4, Cos[c + d*x]^3/(3*a*d) - Cos[c + d*x]^5/(5*a*d) + Sin[c + d*x]^4/(4*a*d)}
{Sin[c + d*x]^4/(a + a*Sec[c + d*x]), x, 3, -(x/(8*a)) - (Cos[c + d*x]*Sin[c + d*x])/(8*a*d) + (Cos[c + d*x]^3*Sin[c + d*x])/(4*a*d) + Sin[c + d*x]^3/(3*a*d)}
{Sin[c + d*x]^3/(a + a*Sec[c + d*x]), x, 2, Cos[c + d*x]^3/(3*a*d) + Sin[c + d*x]^2/(2*a*d)}
{Sin[c + d*x]^2/(a + a*Sec[c + d*x]), x, 2, -(x/(2*a)) + Sin[c + d*x]/(a*d) - (Cos[c + d*x]*Sin[c + d*x])/(2*a*d)}
{Sin[c + d*x]^1/(a + a*Sec[c + d*x]), x, 3, -(Cos[c + d*x]/(a*d)) + Log[1 + Cos[c + d*x]]/(a*d)}
{Csc[c + d*x]^1/(a + a*Sec[c + d*x]), x, 3, -(ArcTanh[Cos[c + d*x]]/(2*a*d)) + (Cot[c + d*x]*Csc[c + d*x])/(2*a*d) - Csc[c + d*x]^2/(2*a*d)}
{Csc[c + d*x]^2/(a + a*Sec[c + d*x]), x, 3, Cot[c + d*x]^3/(3*a*d) - Csc[c + d*x]^3/(3*a*d)}
{Csc[c + d*x]^3/(a + a*Sec[c + d*x]), x, 4, -(ArcTanh[Cos[c + d*x]]/(8*a*d)) + (Cot[c + d*x]*Csc[c + d*x])/(8*a*d) + (Cot[c + d*x]^3*Csc[c + d*x])/(4*a*d) - Csc[c + d*x]^4/(4*a*d)}
{Csc[c + d*x]^4/(a + a*Sec[c + d*x]), x, 4, Cot[c + d*x]^3/(3*a*d) + Cot[c + d*x]^5/(5*a*d) - Csc[c + d*x]^5/(5*a*d)}
{Csc[c + d*x]^5/(a + a*Sec[c + d*x]), x, 5, -(ArcTanh[Cos[c + d*x]]/(16*a*d)) + (Cot[c + d*x]*Csc[c + d*x])/(16*a*d) + (Cot[c + d*x]^3*Csc[c + d*x])/(8*a*d) + (Cot[c + d*x]^3*Csc[c + d*x]^3)/(6*a*d) - Csc[c + d*x]^6/(6*a*d)}
{Csc[c + d*x]^6/(a + a*Sec[c + d*x]), x, 4, Cot[c + d*x]^3/(3*a*d) + (2*Cot[c + d*x]^5)/(5*a*d) + Cot[c + d*x]^7/(7*a*d) - Csc[c + d*x]^7/(7*a*d)}


(* ::Subsection:: *)
(*Integrands of the form Sin[c+d x]^m (a+b Sec[c+d x])^(n/2) when a^2-b^2=0*)


(* ::Section::Closed:: *)
(*Integrands of the form Sin[c+d x]^m (a+b Sec[c+d x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[c+d x]^m (a+b Sec[c+d x])^n*)


{Sin[c + d*x]^5/(a + b*Sec[c + d*x]), x, 3, -(((a^2 - b^2)^2*Cos[c + d*x])/(a^5*d)) - (b*(2*a^2 - b^2)*Cos[c + d*x]^2)/(2*a^4*d) + ((2*a^2 - b^2)*Cos[c + d*x]^3)/(3*a^3*d) + (b*Cos[c + d*x]^4)/(4*a^2*d) - Cos[c + d*x]^5/(5*a*d) + (b*(a^2 - b^2)^2*Log[b + a*Cos[c + d*x]])/(a^6*d)}
{Sin[c + d*x]^4/(a + b*Sec[c + d*x]), x, 7, -(x/(8*a)) - ((a^2 - b^2)*x)/(2*a^3) + ((a^2 - b^2)^2*x)/a^5 - (2*b*(a^2 - b^2)^(3/2)*ArcTanh[(Sqrt[a^2 - b^2]*Tan[(1/2)*(c + d*x)])/(a + b)])/(a^5*d) + (b*(a^2 - b^2)*Sin[c + d*x])/(a^4*d) - (Cos[c + d*x]*Sin[c + d*x])/(8*a*d) - ((a^2 - b^2)*Cos[c + d*x]*Sin[c + d*x])/(2*a^3*d) + (Cos[c + d*x]^3*Sin[c + d*x])/(4*a*d) + (b*Sin[c + d*x]^3)/(3*a^2*d)}
{Sin[c + d*x]^3/(a + b*Sec[c + d*x]), x, 3, -(((a^2 - b^2)*Cos[c + d*x])/(a^3*d)) - (b*Cos[c + d*x]^2)/(2*a^2*d) + Cos[c + d*x]^3/(3*a*d) + (b*(a^2 - b^2)*Log[b + a*Cos[c + d*x]])/(a^4*d)}
{Sin[c + d*x]^2/(a + b*Sec[c + d*x]), x, 4, -(x/(2*a)) + ((a^2 - b^2)*x)/a^3 - (2*b*Sqrt[a^2 - b^2]*ArcTanh[(Sqrt[a^2 - b^2]*Tan[(1/2)*(c + d*x)])/(a + b)])/(a^3*d) + (b*Sin[c + d*x])/(a^2*d) - (Cos[c + d*x]*Sin[c + d*x])/(2*a*d)}
{Sin[c + d*x]^1/(a + b*Sec[c + d*x]), x, 3, -(Cos[c + d*x]/(a*d)) + (b*Log[b + a*Cos[c + d*x]])/(a^2*d)}
{Csc[c + d*x]^1/(a + b*Sec[c + d*x]), x, 6, Log[1 - Cos[c + d*x]]/(2*(a + b)*d) - Log[1 + Cos[c + d*x]]/(2*(a - b)*d) + (b*Log[b + a*Cos[c + d*x]])/((a^2 - b^2)*d)}
{Csc[c + d*x]^2/(a + b*Sec[c + d*x]), x, 5, -((2*a*b*ArcTanh[(Sqrt[a^2 - b^2]*Tan[(1/2)*(c + d*x)])/(a + b)])/((a^2 - b^2)^(3/2)*d)) - (a*Cot[c + d*x])/((a^2 - b^2)*d) + (b*Csc[c + d*x])/((a^2 - b^2)*d)}
{Csc[c + d*x]^3/(a + b*Sec[c + d*x]), x, 7, (b - a*Cos[c + d*x])/(2*(a^2 - b^2)*d*(1 - Cos[c + d*x]^2)) + (a*Log[1 - Cos[c + d*x]])/(4*(a + b)^2*d) - (a*Log[1 + Cos[c + d*x]])/(4*(a - b)^2*d) + (a^2*b*Log[b + a*Cos[c + d*x]])/((a^2 - b^2)^2*d)}
{Csc[c + d*x]^4/(a + b*Sec[c + d*x]), x, 8, -((2*a^3*b*ArcTanh[(Sqrt[a^2 - b^2]*Tan[(1/2)*(c + d*x)])/(a + b)])/((a^2 - b^2)^(5/2)*d)) - (a^3*Cot[c + d*x])/((a^2 - b^2)^2*d) - (a*Cot[c + d*x]^3)/(3*(a^2 - b^2)*d) + (a^2*b*Csc[c + d*x])/((a^2 - b^2)^2*d) + (b*Csc[c + d*x]^3)/(3*(a^2 - b^2)*d)}
{Csc[c + d*x]^5/(a + b*Sec[c + d*x]), x, 8, (b - a*Cos[c + d*x])/(4*(a^2 - b^2)*d*(1 - Cos[c + d*x]^2)^2) + (a*(4*a*b - (3*a^2 + b^2)*Cos[c + d*x]))/(8*(a^2 - b^2)^2*d*(1 - Cos[c + d*x]^2)) + (a*(3*a + b)*Log[1 - Cos[c + d*x]])/(16*(a + b)^3*d) - (a*(3*a - b)*Log[1 + Cos[c + d*x]])/(16*(a - b)^3*d) + (a^4*b*Log[b + a*Cos[c + d*x]])/((a^2 - b^2)^3*d)}


{Sin[c + d*x]^5/(a + b*Sec[c + d*x])^2, x, 3, -(((a^4 - 6*a^2*b^2 + 5*b^4)*Cos[c + d*x])/(a^6*d)) - (2*b*(a^2 - b^2)*Cos[c + d*x]^2)/(a^5*d) + ((2*a^2 - 3*b^2)*Cos[c + d*x]^3)/(3*a^4*d) + (b*Cos[c + d*x]^4)/(2*a^3*d) - Cos[c + d*x]^5/(5*a^2*d) + (b^2*(a^2 - b^2)^2)/(a^7*d*(b + a*Cos[c + d*x])) + (2*b*(a^4 - 4*a^2*b^2 + 3*b^4)*Log[b + a*Cos[c + d*x]])/(a^7*d)}
{Sin[c + d*x]^4/(a + b*Sec[c + d*x])^2, x, 12, (3*x)/(8*a^2) - ((2*a^2 - 3*b^2)*x)/(2*a^4) + ((a^4 - 6*a^2*b^2 + 5*b^4)*x)/a^6 - (2*b^3*Sqrt[a^2 - b^2]*ArcTanh[(Sqrt[a^2 - b^2]*Tan[(1/2)*(c + d*x)])/(a + b)])/(a^6*d) - (4*b*(a^4 - 4*a^2*b^2 + 3*b^4)*ArcTanh[(Sqrt[a^2 - b^2]*Tan[(1/2)*(c + d*x)])/(a + b)])/(a^6*Sqrt[a^2 - b^2]*d) - (2*b*Sin[c + d*x])/(a^3*d) + (4*b*(a^2 - b^2)*Sin[c + d*x])/(a^5*d) + (3*Cos[c + d*x]*Sin[c + d*x])/(8*a^2*d) - ((2*a^2 - 3*b^2)*Cos[c + d*x]*Sin[c + d*x])/(2*a^4*d) + (Cos[c + d*x]^3*Sin[c + d*x])/(4*a^2*d) + (b^2*(a^2 - b^2)*Sin[c + d*x])/(a^5*d*(b + a*Cos[c + d*x])) + (2*b*Sin[c + d*x]^3)/(3*a^3*d)}
{Sin[c + d*x]^3/(a + b*Sec[c + d*x])^2, x, 3, -(((a^2 - 3*b^2)*Cos[c + d*x])/(a^4*d)) - (b*Cos[c + d*x]^2)/(a^3*d) + Cos[c + d*x]^3/(3*a^2*d) + (b^2*(a^2 - b^2))/(a^5*d*(b + a*Cos[c + d*x])) + (2*b*(a^2 - 2*b^2)*Log[b + a*Cos[c + d*x]])/(a^5*d)}
{Sin[c + d*x]^2/(a + b*Sec[c + d*x])^2, x, 6, ((a^2 - 6*b^2)*x)/(2*a^4) - (2*b*(2*a^2 - 3*b^2)*ArcTanh[(Sqrt[a^2 - b^2]*Tan[(1/2)*(c + d*x)])/(a + b)])/(a^4*Sqrt[a^2 - b^2]*d) + (3*b*Sin[c + d*x])/(a^3*d) - (3*Cos[c + d*x]*Sin[c + d*x])/(2*a^2*d) + (Cos[c + d*x]^2*Sin[c + d*x])/(a*d*(b + a*Cos[c + d*x]))}
{Sin[c + d*x]^1/(a + b*Sec[c + d*x])^2, x, 4, -(Cos[c + d*x]/(a^2*d)) + b^2/(a^3*d*(b + a*Cos[c + d*x])) + (2*b*Log[b + a*Cos[c + d*x]])/(a^3*d)}
{Csc[c + d*x]^1/(a + b*Sec[c + d*x])^2, x, 3, b^2/(a*(a^2 - b^2)*d*(b + a*Cos[c + d*x])) + Log[1 - Cos[c + d*x]]/(2*(a + b)^2*d) - Log[1 + Cos[c + d*x]]/(2*(a - b)^2*d) + (2*a*b*Log[b + a*Cos[c + d*x]])/((a^2 - b^2)^2*d)}
{Csc[c + d*x]^2/(a + b*Sec[c + d*x])^2, x, 8, -((4*a^2*b*ArcTanh[(Sqrt[a^2 - b^2]*Tan[(1/2)*(c + d*x)])/(a + b)])/((a^2 - b^2)^(5/2)*d)) - (2*b^3*ArcTanh[(Sqrt[a^2 - b^2]*Tan[(1/2)*(c + d*x)])/(a + b)])/((a^2 - b^2)^(5/2)*d) - Sin[c + d*x]/(2*(a + b)^2*d*(1 - Cos[c + d*x])) + Sin[c + d*x]/(2*(a - b)^2*d*(1 + Cos[c + d*x])) + (a*b^2*Sin[c + d*x])/((a^2 - b^2)^2*d*(b + a*Cos[c + d*x]))}
{Csc[c + d*x]^3/(a + b*Sec[c + d*x])^2, x, 3, -(1/(4*(a + b)^2*d*(1 - Cos[c + d*x]))) + 1/(4*(a - b)^2*d*(1 + Cos[c + d*x])) + (a*b^2)/((a^2 - b^2)^2*d*(b + a*Cos[c + d*x])) + ((a - b)*Log[1 - Cos[c + d*x]])/(4*(a + b)^3*d) - ((a + b)*Log[1 + Cos[c + d*x]])/(4*(a - b)^3*d) + (2*a*b*(a^2 + b^2)*Log[b + a*Cos[c + d*x]])/((a^2 - b^2)^3*d)}
{Csc[c + d*x]^4/(a + b*Sec[c + d*x])^2, x, 12, -((2*a^2*b^3*ArcTanh[(Sqrt[a^2 - b^2]*Tan[(1/2)*(c + d*x)])/(a + b)])/((a^2 - b^2)^(7/2)*d)) - (4*a^2*b*(a^2 + b^2)*ArcTanh[(Sqrt[a^2 - b^2]*Tan[(1/2)*(c + d*x)])/(a + b)])/((a^2 - b^2)^(7/2)*d) - Sin[c + d*x]/(12*(a + b)^2*d*(1 - Cos[c + d*x])^2) - ((a - b)*Sin[c + d*x])/(4*(a + b)^3*d*(1 - Cos[c + d*x])) - Sin[c + d*x]/(12*(a + b)^2*d*(1 - Cos[c + d*x])) + Sin[c + d*x]/(12*(a - b)^2*d*(1 + Cos[c + d*x])^2) + Sin[c + d*x]/(12*(a - b)^2*d*(1 + Cos[c + d*x])) + ((a + b)*Sin[c + d*x])/(4*(a - b)^3*d*(1 + Cos[c + d*x])) + (a^3*b^2*Sin[c + d*x])/((a^2 - b^2)^3*d*(b + a*Cos[c + d*x]))}
{Csc[c + d*x]^5/(a + b*Sec[c + d*x])^2, x, 3, -(1/(16*(a + b)^2*d*(1 - Cos[c + d*x])^2)) - (3*a - b)/(16*(a + b)^3*d*(1 - Cos[c + d*x])) + 1/(16*(a - b)^2*d*(1 + Cos[c + d*x])^2) + (3*a + b)/(16*(a - b)^3*d*(1 + Cos[c + d*x])) + (a^3*b^2)/((a^2 - b^2)^3*d*(b + a*Cos[c + d*x])) + ((3*a^2 - 4*a*b - b^2)*Log[1 - Cos[c + d*x]])/(16*(a + b)^4*d) - ((3*a^2 + 4*a*b - b^2)*Log[1 + Cos[c + d*x]])/(16*(a - b)^4*d) + (2*a^3*b*(a^2 + 2*b^2)*Log[b + a*Cos[c + d*x]])/((a^2 - b^2)^4*d)}


(* ::Subsection:: *)
(*Integrands of the form Sin[c+d x]^m (a+b Sec[c+d x])^(n/2)*)


(* ::Section::Closed:: *)
(*Integrands of the form Tan[c+d x]^m (a+b Sec[c+d x])^n when a^2-b^2=0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Tan[c+d x]^m (a+b Sec[c+d x])^n when a^2-b^2=0*)


{Tan[c + d*x]^7/(a + a*Sec[c + d*x]), x, 7, Log[Cos[c + d*x]]/(a*d) + Sec[c + d*x]/(a*d) - (2*Sec[c + d*x]^3)/(3*a*d) + Sec[c + d*x]^5/(5*a*d) + Tan[c + d*x]^2/(2*a*d) - Tan[c + d*x]^4/(4*a*d)}
{Tan[c + d*x]^6/(a + a*Sec[c + d*x]), x, 7, -(x/a) + (3*ArcTanh[Sin[c + d*x]])/(8*a*d) + Tan[c + d*x]/(a*d) - (3*Sec[c + d*x]*Tan[c + d*x])/(8*a*d) - Tan[c + d*x]^3/(3*a*d) + (Sec[c + d*x]*Tan[c + d*x]^3)/(4*a*d)}
{Tan[c + d*x]^5/(a + a*Sec[c + d*x]), x, 5, -(Log[Cos[c + d*x]]/(a*d)) - Sec[c + d*x]/(a*d) + Sec[c + d*x]^3/(3*a*d) - Tan[c + d*x]^2/(2*a*d)}
{Tan[c + d*x]^4/(a + a*Sec[c + d*x]), x, 5, x/a - ArcTanh[Sin[c + d*x]]/(2*a*d) - Tan[c + d*x]/(a*d) + (Sec[c + d*x]*Tan[c + d*x])/(2*a*d)}
{Tan[c + d*x]^3/(a + a*Sec[c + d*x]), x, 3, Log[Cos[c + d*x]]/(a*d) + Sec[c + d*x]/(a*d)}
{Tan[c + d*x]^2/(a + a*Sec[c + d*x]), x, 3, -(x/a) + ArcTanh[Sin[c + d*x]]/(a*d)}
{Tan[c + d*x]^1/(a + a*Sec[c + d*x]), x, 2, -(Log[1 + Cos[c + d*x]]/(a*d))}
{Cot[c + d*x]^1/(a + a*Sec[c + d*x]), x, 5, ArcTanh[Cos[c + d*x]]/(2*a*d) + Cot[c + d*x]^2/(2*a*d) - (Cot[c + d*x]*Csc[c + d*x])/(2*a*d) + Log[Sin[c + d*x]]/(a*d)}
{Cot[c + d*x]^2/(a + a*Sec[c + d*x]), x, 6, -(x/a) - Cot[c + d*x]/(a*d) + Cot[c + d*x]^3/(3*a*d) + Csc[c + d*x]/(a*d) - Csc[c + d*x]^3/(3*a*d)}
{Cot[c + d*x]^3/(a + a*Sec[c + d*x]), x, 7, -((3*ArcTanh[Cos[c + d*x]])/(8*a*d)) - Cot[c + d*x]^2/(2*a*d) + Cot[c + d*x]^4/(4*a*d) + (3*Cot[c + d*x]*Csc[c + d*x])/(8*a*d) - (Cot[c + d*x]^3*Csc[c + d*x])/(4*a*d) - Log[Sin[c + d*x]]/(a*d)}
{Cot[c + d*x]^4/(a + a*Sec[c + d*x]), x, 8, x/a + Cot[c + d*x]/(a*d) - Cot[c + d*x]^3/(3*a*d) + Cot[c + d*x]^5/(5*a*d) - Csc[c + d*x]/(a*d) + (2*Csc[c + d*x]^3)/(3*a*d) - Csc[c + d*x]^5/(5*a*d)}


(* ::Subsection:: *)
(*Integrands of the form Tan[c+d x]^m (a+b Sec[c+d x])^(n/2) when a^2-b^2=0*)


(* ::Section::Closed:: *)
(*Integrands of the form Tan[c+d x]^m (a+b Sec[c+d x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Tan[c+d x]^m (a+b Sec[c+d x])^n*)


{Tan[c + d*x]^5/(a + b*Sec[c + d*x]), x, 3, (a*(a^2 - 2*b^2)*Log[Cos[c + d*x]])/(b^4*d) - ((a^2 - b^2)^2*Log[b + a*Cos[c + d*x]])/(a*b^4*d) + ((a^2 - 2*b^2)*Sec[c + d*x])/(b^3*d) - (a*Sec[c + d*x]^2)/(2*b^2*d) + Sec[c + d*x]^3/(3*b*d)}
{Tan[c + d*x]^4/(a + b*Sec[c + d*x]), x, 10, x/a + ((2*a^2 - 3*b^2)*ArcTanh[Sin[c + d*x]])/(2*b^3*d) - (2*(a^2 - b^2)^(3/2)*ArcTanh[(Sqrt[a^2 - b^2]*Tan[(1/2)*(c + d*x)])/(a + b)])/(a*b^3*d) - (a*Tan[c + d*x])/(b^2*d) + (Sec[c + d*x]*Tan[c + d*x])/(2*b*d), (a*x)/b^2 - (a*(a^2 - b^2)*x)/b^4 + ((a^2 - b^2)^2*x)/(a*b^4) - ArcTanh[Sin[c + d*x]]/(2*b*d) + ((a^2 - b^2)*ArcTanh[Sin[c + d*x]])/(b^3*d) - (2*(a^2 - b^2)^(3/2)*ArcTanh[(Sqrt[a^2 - b^2]*Tan[(1/2)*(c + d*x)])/(a + b)])/(a*b^3*d) - (a*Tan[c + d*x])/(b^2*d) + (Sec[c + d*x]*Tan[c + d*x])/(2*b*d)}
{Tan[c + d*x]^3/(a + b*Sec[c + d*x]), x, 3, (a*Log[Cos[c + d*x]])/(b^2*d) + ((1 - a^2/b^2)*Log[b + a*Cos[c + d*x]])/(a*d) + Sec[c + d*x]/(b*d)}
{Tan[c + d*x]^2/(a + b*Sec[c + d*x]), x, 5, -(x/a) + ArcTanh[Sin[c + d*x]]/(b*d) - (2*Sqrt[a^2 - b^2]*ArcTanh[(Sqrt[a^2 - b^2]*Tan[(1/2)*(c + d*x)])/(a + b)])/(a*b*d), -(((1 - a^2/b^2)*x)/a) - (a*x)/b^2 + ArcTanh[Sin[c + d*x]]/(b*d) - (2*Sqrt[a^2 - b^2]*ArcTanh[(Sqrt[a^2 - b^2]*Tan[(1/2)*(c + d*x)])/(a + b)])/(a*b*d)}
{Tan[c + d*x]^1/(a + b*Sec[c + d*x]), x, 2, -(Log[b + a*Cos[c + d*x]]/(a*d))}
{Cot[c + d*x]^1/(a + b*Sec[c + d*x]), x, 3, Log[1 - Cos[c + d*x]]/(2*(a + b)*d) + Log[1 + Cos[c + d*x]]/(2*(a - b)*d) - (b^2*Log[b + a*Cos[c + d*x]])/(a*(a^2 - b^2)*d)}
{Cot[c + d*x]^2/(a + b*Sec[c + d*x]), x, 6, -(x/a) - (2*b^3*ArcTanh[(Sqrt[a^2 - b^2]*Tan[(1/2)*(c + d*x)])/(a + b)])/(a*(a^2 - b^2)^(3/2)*d) - (a*Cot[c + d*x])/((a^2 - b^2)*d) + (b*Csc[c + d*x])/((a^2 - b^2)*d), -((a*x)/(a^2 - b^2)) + (b^2*x)/(a*(a^2 - b^2)) - (2*b^3*ArcTanh[(Sqrt[a^2 - b^2]*Tan[(1/2)*(c + d*x)])/(a + b)])/(a*(a^2 - b^2)^(3/2)*d) - (a*Cot[c + d*x])/((a^2 - b^2)*d) + (b*Csc[c + d*x])/((a^2 - b^2)*d)}
{Cot[c + d*x]^3/(a + b*Sec[c + d*x]), x, 3, -(1/(4*(a + b)*d*(1 - Cos[c + d*x]))) - 1/(4*(a - b)*d*(1 + Cos[c + d*x])) - ((2*a + 3*b)*Log[1 - Cos[c + d*x]])/(4*(a + b)^2*d) - ((2*a - 3*b)*Log[1 + Cos[c + d*x]])/(4*(a - b)^2*d) - (b^4*Log[b + a*Cos[c + d*x]])/(a*(a^2 - b^2)^2*d)}
{Cot[c + d*x]^4/(a + b*Sec[c + d*x]), x, 12, x/a - (2*b^5*ArcTanh[(Sqrt[a^2 - b^2]*Tan[(1/2)*(c + d*x)])/(a + b)])/(a*(a^2 - b^2)^(5/2)*d) + (a*(a^2 - 2*b^2)*Cot[c + d*x])/((a^2 - b^2)^2*d) - (a*Cot[c + d*x]^3)/(3*(a^2 - b^2)*d) - (b*(a^2 - 2*b^2)*Csc[c + d*x])/((a^2 - b^2)^2*d) + (b*Csc[c + d*x]^3)/(3*(a^2 - b^2)*d), -((a*b^2*x)/(a^2 - b^2)^2) + (b^4*x)/(a*(a^2 - b^2)^2) + (a*x)/(a^2 - b^2) - (2*b^5*ArcTanh[(Sqrt[a^2 - b^2]*Tan[(1/2)*(c + d*x)])/(a + b)])/(a*(a^2 - b^2)^(5/2)*d) - (a*b^2*Cot[c + d*x])/((a^2 - b^2)^2*d) + (a*Cot[c + d*x])/((a^2 - b^2)*d) - (a*Cot[c + d*x]^3)/(3*(a^2 - b^2)*d) + (b^3*Csc[c + d*x])/((a^2 - b^2)^2*d) - (b*Csc[c + d*x])/((a^2 - b^2)*d) + (b*Csc[c + d*x]^3)/(3*(a^2 - b^2)*d)}


{Tan[c + d*x]^5/(a + b*Sec[c + d*x])^2, x, 3, -((a^2 - b^2)^2/(a^2*b^3*d*(b + a*Cos[c + d*x]))) - ((3*a^2 - 2*b^2)*Log[Cos[c + d*x]])/(b^4*d) + ((a^2 - b^2)*(3*a^2 + b^2)*Log[b + a*Cos[c + d*x]])/(a^2*b^4*d) - (2*a*Sec[c + d*x])/(b^3*d) + Sec[c + d*x]^2/(2*b^2*d)}
{Tan[c + d*x]^4/(a + b*Sec[c + d*x])^2, x, 13, x/a^2 - (2*a*ArcTanh[Sin[c + d*x]])/(b^3*d) + (4*b*ArcTanh[(Sqrt[a^2 - b^2]*Tan[(1/2)*(c + d*x)])/(a + b)])/((a^2 - b^2)^(3/2)*d) + (2*a^2*(2*a^2 - 3*b^2)*ArcTanh[(Sqrt[a^2 - b^2]*Tan[(1/2)*(c + d*x)])/(a + b)])/(b^3*(a^2 - b^2)^(3/2)*d) - (2*b*(2*a^2 - b^2)*ArcTanh[(Sqrt[a^2 - b^2]*Tan[(1/2)*(c + d*x)])/(a + b)])/(a^2*(a^2 - b^2)^(3/2)*d) - (2*a*Sin[c + d*x])/((a^2 - b^2)*d*(b + a*Cos[c + d*x])) + (b^2*Sin[c + d*x])/(a*(a^2 - b^2)*d*(b + a*Cos[c + d*x])) + ((2*a^2 - b^2)*Tan[c + d*x])/(b^2*(a^2 - b^2)*d) - (a^2*Tan[c + d*x])/(b*(a^2 - b^2)*d*(b + a*Cos[c + d*x]))}
{Tan[c + d*x]^3/(a + b*Sec[c + d*x])^2, x, 3, -((1 - b^2/a^2)/(b*d*(b + a*Cos[c + d*x]))) - Log[Cos[c + d*x]]/(b^2*d) + ((1/a^2 + 1/b^2)*Log[b + a*Cos[c + d*x]])/d}
{Tan[c + d*x]^2/(a + b*Sec[c + d*x])^2, x, 6, -(x/a^2) + (2*b*ArcTanh[(Sqrt[a^2 - b^2]*Tan[(1/2)*(c + d*x)])/(a + b)])/(a^2*Sqrt[a^2 - b^2]*d) + Sin[c + d*x]/(a*d*(b + a*Cos[c + d*x]))}
{Tan[c + d*x]^1/(a + b*Sec[c + d*x])^2, x, 3, -(b/(a^2*d*(b + a*Cos[c + d*x]))) - Log[b + a*Cos[c + d*x]]/(a^2*d)}
{Cot[c + d*x]^1/(a + b*Sec[c + d*x])^2, x, 3, -(b^3/(a^2*(a^2 - b^2)*d*(b + a*Cos[c + d*x]))) + Log[1 - Cos[c + d*x]]/(2*(a + b)^2*d) + Log[1 + Cos[c + d*x]]/(2*(a - b)^2*d) - (b^2*(3*a^2 - b^2)*Log[b + a*Cos[c + d*x]])/(a^2*(a^2 - b^2)^2*d)}
{Cot[c + d*x]^2/(a + b*Sec[c + d*x])^2, x, 8, -(x/a^2) - (2*b^5*ArcTanh[(Sqrt[a^2 - b^2]*Tan[(1/2)*(c + d*x)])/(a + b)])/(a^2*(a^2 - b^2)^(5/2)*d) - (4*b^3*(2*a^2 - b^2)*ArcTanh[(Sqrt[a^2 - b^2]*Tan[(1/2)*(c + d*x)])/(a + b)])/(a^2*(a^2 - b^2)^(5/2)*d) - Sin[c + d*x]/(2*(a + b)^2*d*(1 - Cos[c + d*x])) + Sin[c + d*x]/(2*(a - b)^2*d*(1 + Cos[c + d*x])) + (b^4*Sin[c + d*x])/(a*(a^2 - b^2)^2*d*(b + a*Cos[c + d*x]))}
{Cot[c + d*x]^3/(a + b*Sec[c + d*x])^2, x, 3, -(1/(4*(a + b)^2*d*(1 - Cos[c + d*x]))) - 1/(4*(a - b)^2*d*(1 + Cos[c + d*x])) - b^5/(a^2*(a^2 - b^2)^2*d*(b + a*Cos[c + d*x])) - ((a + 2*b)*Log[1 - Cos[c + d*x]])/(2*(a + b)^3*d) - ((a - 2*b)*Log[1 + Cos[c + d*x]])/(2*(a - b)^3*d) - (b^4*(5*a^2 - b^2)*Log[b + a*Cos[c + d*x]])/(a^2*(a^2 - b^2)^3*d)}
{Cot[c + d*x]^4/(a + b*Sec[c + d*x])^2, x, 12, x/a^2 - (2*b^7*ArcTanh[(Sqrt[a^2 - b^2]*Tan[(1/2)*(c + d*x)])/(a + b)])/(a^2*(a^2 - b^2)^(7/2)*d) - (4*b^5*(3*a^2 - b^2)*ArcTanh[(Sqrt[a^2 - b^2]*Tan[(1/2)*(c + d*x)])/(a + b)])/(a^2*(a^2 - b^2)^(7/2)*d) - Sin[c + d*x]/(12*(a + b)^2*d*(1 - Cos[c + d*x])^2) - Sin[c + d*x]/(12*(a + b)^2*d*(1 - Cos[c + d*x])) + ((3*a + 5*b)*Sin[c + d*x])/(4*(a + b)^3*d*(1 - Cos[c + d*x])) + Sin[c + d*x]/(12*(a - b)^2*d*(1 + Cos[c + d*x])^2) - ((3*a - 5*b)*Sin[c + d*x])/(4*(a - b)^3*d*(1 + Cos[c + d*x])) + Sin[c + d*x]/(12*(a - b)^2*d*(1 + Cos[c + d*x])) + (b^6*Sin[c + d*x])/(a*(a^2 - b^2)^3*d*(b + a*Cos[c + d*x]))}
{Cot[c + d*x]^5/(a + b*Sec[c + d*x])^2, x, 3, -(1/(16*(a + b)^2*d*(1 - Cos[c + d*x])^2)) + (7*a + 11*b)/(16*(a + b)^3*d*(1 - Cos[c + d*x])) - 1/(16*(a - b)^2*d*(1 + Cos[c + d*x])^2) + (7*a - 11*b)/(16*(a - b)^3*d*(1 + Cos[c + d*x])) - b^7/(a^2*(a^2 - b^2)^3*d*(b + a*Cos[c + d*x])) + ((4*a^2 + 13*a*b + 12*b^2)*Log[1 - Cos[c + d*x]])/(8*(a + b)^4*d) + ((4*a^2 - 13*a*b + 12*b^2)*Log[1 + Cos[c + d*x]])/(8*(a - b)^4*d) - (b^6*(7*a^2 - b^2)*Log[b + a*Cos[c + d*x]])/(a^2*(a^2 - b^2)^4*d)}


(* ::Subsection:: *)
(*Integrands of the form Tan[c+d x]^m (a+b Sec[c+d x])^(n/2) when a^2-b^2=0*)
