(* ::Package:: *)

(* ::Title:: *)
(*Integrands of the form trig(c+d x)^m (a+b cos(c+d x))^n*)


(* ::Section::Closed:: *)
(*Integrands of the form Sin[c+d x]^m (a+b Cos[c+d x])^n when a^2-b^2=0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[c+d x]^m (a+b Cos[c+d x])^n when a^2-b^2=0*)


(* ::Subsubsection:: *)
(*n>0*)


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Sin[x]^4/(a + a*Cos[x]), x, 2, x/(2*a) - (Cos[x]*Sin[x])/(2*a) - Sin[x]^3/(3*a)}
{Sin[x]^3/(a + a*Cos[x]), x, 3, -(Cos[x]/a) + Cos[x]^2/(2*a)}
{Sin[x]^2/(a + a*Cos[x]), x, 2, x/a - Sin[x]/a}
{Sin[x]^1/(a + a*Cos[x]), x, 2, -(Log[1 + Cos[x]]/a)}
{Sin[x]^0/(a + a*Cos[x]), x, 1, Sin[x]/(a + a*Cos[x])}
{Csc[x]^1/(a + a*Cos[x]), x, 5, -(ArcTanh[Cos[x]]/(2*a)) + 1/(2*a*(1 + Cos[x]))}
{Csc[x]^2/(a + a*Cos[x]), x, 3, -(Cot[x]/a) - Cot[x]^3/(3*a) + Csc[x]^3/(3*a)}
{Csc[x]^3/(a + a*Cos[x]), x, 5, -((3*ArcTanh[Cos[x]])/(8*a)) - 1/(8*a*(1 - Cos[x])) + 1/(8*a*(1 + Cos[x])^2) + 1/(4*a*(1 + Cos[x]))}
{Csc[x]^4/(a + a*Cos[x]), x, 3, -(Cot[x]/a) - (2*Cot[x]^3)/(3*a) - Cot[x]^5/(5*a) + Csc[x]^5/(5*a)}


{Sin[2*x]/(1 + Cos[2*x]), x, 2, -Log[Cos[x]], (-(1/2))*Log[1 + Cos[2*x]]}
{Sin[2*x]/(1 - Cos[2*x]), x, 2, Log[Sin[x]], (1/2)*Log[1 - Cos[2*x]]}


{Sin[x]/(1 + Cos[x])^2, x, 2, 1/(1 + Cos[x])}
{Sin[x]/(1 - Cos[x])^2, x, 2, -(1/(1 - Cos[x]))}
{Sin[x]^2/(1 + Cos[x])^2, x, 2, -x + (2*Sin[x])/(1 + Cos[x])}
{Sin[x]^2/(1 - Cos[x])^2, x, 2, -x - (2*Sin[x])/(1 - Cos[x])}
{Sin[x]^3/(1 + Cos[x])^2, x, 4, Cos[x] - 2*Log[1 + Cos[x]]}
{Sin[x]^3/(1 - Cos[x])^2, x, 4, Cos[x] + 2*Log[1 - Cos[x]]}


{Sin[x]/(1 + Cos[x])^3, x, 2, 1/(2*(1 + Cos[x])^2)}
{Sin[x]/(1 - Cos[x])^3, x, 2, -(1/(2*(1 - Cos[x])^2))}
{Sin[x]^2/(1 + Cos[x])^3, x, 1, Sin[x]^3/(3*(1 + Cos[x])^3)}
{Sin[x]^2/(1 - Cos[x])^3, x, 1, -(Sin[x]^3/(3*(1 - Cos[x])^3))}
{Sin[x]^3/(1 + Cos[x])^3, x, 4, 2/(1 + Cos[x]) + Log[1 + Cos[x]]}
{Sin[x]^3/(1 - Cos[x])^3, x, 4, -(2/(1 - Cos[x])) - Log[1 - Cos[x]]}


(* ::Subsection:: *)
(*Integrands of the form Sin[c+d x]^m (a+b Cos[c+d x])^(n/2) when a^2-b^2=0*)


(* ::Section::Closed:: *)
(*Integrands of the form Sin[c+d x]^m (a+b Cos[c+d x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[c+d x]^m (a+b Cos[c+d x])^n*)


(* ::Subsubsection:: *)
(*n>0*)


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Sin[x]^4/(a + b*Cos[x]), x, 5, (a*x)/(2*b^2) - (a*(a^2 - b^2)*x)/b^4 + (2*(a^2 - b^2)^(3/2)*ArcTan[(Sqrt[a^2 - b^2]*Tan[x/2])/(a + b)])/b^4 + ((a^2 - b^2)*Sin[x])/b^3 - (a*Cos[x]*Sin[x])/(2*b^2) - Sin[x]^3/(3*b)}
{Sin[x]^3/(a + b*Cos[x]), x, 3, -((a*Cos[x])/b^2) + Cos[x]^2/(2*b) + ((a - b)*(a + b)*Log[a + b*Cos[x]])/b^3}
{Sin[x]^2/(a + b*Cos[x]), x, 3, (a*x)/b^2 - (2*Sqrt[a^2 - b^2]*ArcTan[(Sqrt[a^2 - b^2]*Tan[x/2])/(a + b)])/b^2 - Sin[x]/b}
{Sin[x]^1/(a + b*Cos[x]), x, 2, -(Log[a + b*Cos[x]]/b)}
{Sin[x]^0/(a + b*Cos[x]), x, 1, (2*ArcTan[(Sqrt[a^2 - b^2]*Tan[x/2])/(a + b)])/Sqrt[a^2 - b^2]}
{Csc[x]^1/(a + b*Cos[x]), x, 6, Log[1 - Cos[x]]/(2*(a + b)) - Log[1 + Cos[x]]/(2*(a - b)) + (b*Log[a + b*Cos[x]])/(a^2 - b^2)}
{Csc[x]^2/(a + b*Cos[x]), x, 3, -((2*b^2*ArcTan[(Sqrt[a^2 - b^2]*Tan[x/2])/(a + b)])/(a^2 - b^2)^(3/2)) - (a*Cot[x])/(a^2 - b^2) + (b*Csc[x])/(a^2 - b^2)}
{Csc[x]^3/(a + b*Cos[x]), x, 7, (b - a*Cos[x])/(2*(a^2 - b^2)*(1 - Cos[x]^2)) + ((a + 2*b)*Log[1 - Cos[x]])/(4*(a + b)^2) - ((a - 2*b)*Log[1 + Cos[x]])/(4*(a - b)^2) - (b^3*Log[a + b*Cos[x]])/(a^2 - b^2)^2}
{Csc[x]^4/(a + b*Cos[x]), x, 6, (2*b^4*ArcTan[(Sqrt[a^2 - b^2]*Tan[x/2])/(a + b)])/(a^2 - b^2)^(5/2) + (a*b^2*Cot[x])/(a^2 - b^2)^2 - (a*Cot[x])/(a^2 - b^2) - (a*Cot[x]^3)/(3*(a^2 - b^2)) - (b^3*Csc[x])/(a^2 - b^2)^2 + (b*Csc[x]^3)/(3*(a^2 - b^2))}


(* ::Subsection:: *)
(*Integrands of the form Sin[c+d x]^m (a+b Cos[c+d x])^(n/2)*)


(* ::Section::Closed:: *)
(*Integrands of the form Tan[c+d x]^m (a+b Cos[c+d x])^n when a^2-b^2=0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Tan[c+d x]^m (a+b Cos[c+d x])^n when a^2-b^2=0*)


(* ::Subsubsection:: *)
(*n>0*)


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Tan[x]^4/(a + a*Cos[x]), x, 3, ArcTanh[Sin[x]]/(2*a) - (Sec[x]*Tan[x])/(2*a) + Tan[x]^3/(3*a)}
{Tan[x]^3/(a + a*Cos[x]), x, 4, -(Sec[x]/a) + Sec[x]^2/(2*a)}
{Tan[x]^2/(a + a*Cos[x]), x, 2, -(ArcTanh[Sin[x]]/a) + Tan[x]/a}
{Tan[x]^1/(a + a*Cos[x]), x, 3, -(Log[Cos[x]]/a) + Log[1 + Cos[x]]/a}
{Cot[x]^1/(a + a*Cos[x]), x, 5, -(ArcTanh[Cos[x]]/(2*a)) - 1/(2*a*(1 + Cos[x]))}
{Cot[x]^2/(a + a*Cos[x]), x, 3, -(Cot[x]^3/(3*a)) - Csc[x]/a + Csc[x]^3/(3*a)}
{Cot[x]^3/(a + a*Cos[x]), x, 5, (3*ArcTanh[Cos[x]])/(8*a) - 1/(8*a*(1 - Cos[x])) - 1/(8*a*(1 + Cos[x])^2) + 1/(2*a*(1 + Cos[x]))}
{Cot[x]^4/(a + a*Cos[x]), x, 4, -(Cot[x]^5/(5*a)) + Csc[x]/a - (2*Csc[x]^3)/(3*a) + Csc[x]^5/(5*a)}


{Tan[3*x]/(1 + Cos[3*x])^2, x, 3, -(1/(3*(1 + Cos[3*x]))) - (1/3)*Log[Cos[3*x]] + (1/3)*Log[1 + Cos[3*x]]}


(* ::Subsection:: *)
(*Integrands of the form Tan[c+d x]^m (a+b Cos[c+d x])^(n/2) when a^2-b^2=0*)


(* ::Section::Closed:: *)
(*Integrands of the form Tan[c+d x]^m (a+b Cos[c+d x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Tan[c+d x]^m (a+b Cos[c+d x])^n when a^2-b^2=0*)


(* ::Subsubsection:: *)
(*n>0*)


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Tan[x]^4/(a + b*Cos[x]), x, 6, (2*(a^2 - b^2)^(3/2)*ArcTan[(Sqrt[a^2 - b^2]*Tan[x/2])/(a + b)])/a^4 + (b*ArcTanh[Sin[x]])/(2*a^2) + (b*(a^2 - b^2)*ArcTanh[Sin[x]])/a^4 - ((a^2 - b^2)*Tan[x])/a^3 - (b*Sec[x]*Tan[x])/(2*a^2) + Tan[x]^3/(3*a)}
{Tan[x]^3/(a + b*Cos[x]), x, 3, ((a^2 - b^2)*Log[Cos[x]])/a^3 - ((a^2 - b^2)*Log[a + b*Cos[x]])/a^3 - (b*Sec[x])/a^2 + Sec[x]^2/(2*a)}
{Tan[x]^2/(a + b*Cos[x]), x, 3, -((2*Sqrt[a^2 - b^2]*ArcTan[(Sqrt[a^2 - b^2]*Tan[x/2])/(a + b)])/a^2) - (b*ArcTanh[Sin[x]])/a^2 + Tan[x]/a}
{Tan[x]^1/(a + b*Cos[x]), x, 3, -(Log[Cos[x]]/a) + Log[a + b*Cos[x]]/a}
{Cot[x]^1/(a + b*Cos[x]), x, 6, Log[1 - Cos[x]]/(2*(a + b)) + Log[1 + Cos[x]]/(2*(a - b)) - (a*Log[a + b*Cos[x]])/(a^2 - b^2)}
{Cot[x]^2/(a + b*Cos[x]), x, 3, -((2*a^2*ArcTan[(Sqrt[a^2 - b^2]*Tan[x/2])/(a + b)])/(a^2 - b^2)^(3/2)) - (a*Cot[x])/(a^2 - b^2) + (b*Csc[x])/(a^2 - b^2)}
{Cot[x]^3/(a + b*Cos[x]), x, 3, -(1/(4*(a + b)*(1 - Cos[x]))) - 1/(4*(a - b)*(1 + Cos[x])) - ((2*a + b)*Log[1 - Cos[x]])/(4*(a + b)^2) - ((2*a - b)*Log[1 + Cos[x]])/(4*(a - b)^2) + (a^3*Log[a + b*Cos[x]])/(a^2 - b^2)^2}
{Cot[x]^4/(a + b*Cos[x]), x, 6, (2*a^4*ArcTan[(Sqrt[a^2 - b^2]*Tan[x/2])/(a + b)])/(a^2 - b^2)^(5/2) + (a^3*Cot[x])/(a^2 - b^2)^2 - (a*Cot[x]^3)/(3*(a^2 - b^2)) - (a^2*b*Csc[x])/(a^2 - b^2)^2 - (b*Csc[x])/(a^2 - b^2) + (b*Csc[x]^3)/(3*(a^2 - b^2))}


(* ::Subsection::Closed:: *)
(*Integrands of the form Tan[c+d x]^m (a+b Cos[c+d x])^(n/2) when a^2-b^2=0*)


{Cot[x]/Sqrt[3 - Cos[x]], x, 4, -ArcTanh[Sqrt[3 - Cos[x]]/2]/2 - ArcTanh[Sqrt[3 - Cos[x]]/Sqrt[2]]/Sqrt[2]}
{Tan[x]*Sqrt[2 + 3*Cos[x]], x, 3, 2*Sqrt[2]*ArcTanh[Sqrt[2 + 3*Cos[x]]/Sqrt[2]] - 2*Sqrt[2 + 3*Cos[x]]}
