(* ::Package:: *)

(* ::Title:: *)
(*Integration problems of the form *)
(*Csc[c+d x]^m (A+B Csc[c+d x]+C Csc[c+d x]^2) (a+b Csc[c+d x])^n when a^2=b^2*)


(* ::Section:: *)
(*Csc[c+d x]^m (a+a Csc[c+d x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Csc[c+d x]^m (a+a Csc[c+d x])^n*)


{Csc[x]^4/(a + a*Csc[x]), x, 4, -((3*ArcTanh[Cos[x]])/(2*a)) + (2*Cot[x])/a - (3*Cot[x]*Csc[x])/(2*a) + (Cot[x]*Csc[x]^2)/(a + a*Csc[x])}
{Csc[x]^3/(a + a*Csc[x]), x, 3, ArcTanh[Cos[x]]/a - (2*Cot[x])/a + (Cot[x]*Csc[x])/(a + a*Csc[x])}
{Csc[x]^2/(a + a*Csc[x]), x, 3, -(ArcTanh[Cos[x]]/a) + Cot[x]/(a + a*Csc[x])}
{Csc[x]^1/(a + a*Csc[x]), x, 1, -(Cot[x]/(a + a*Csc[x]))}
{Sin[x]^1/(a + a*Csc[x]), x, 3, -(x/a) - (2*Cos[x])/a + Cos[x]/(a + a*Csc[x])}
{Sin[x]^2/(a + a*Csc[x]), x, 4, (3*x)/(2*a) + (2*Cos[x])/a - (3*Cos[x]*Sin[x])/(2*a) + (Cos[x]*Sin[x])/(a + a*Csc[x])}
{Sin[x]^3/(a + a*Csc[x]), x, 5, -((3*x)/(2*a)) - (8*Cos[x])/(3*a) + (3*Cos[x]*Sin[x])/(2*a) - (4*Cos[x]*Sin[x]^2)/(3*a) + (Cos[x]*Sin[x]^2)/(a + a*Csc[x])}
{Sin[x]^4/(a + a*Csc[x]), x, 6, (15*x)/(8*a) + (8*Cos[x])/(3*a) - (15*Cos[x]*Sin[x])/(8*a) + (4*Cos[x]*Sin[x]^2)/(3*a) - (5*Cos[x]*Sin[x]^3)/(4*a) + (Cos[x]*Sin[x]^3)/(a + a*Csc[x])}


(* Integrands of the form (a+b*Csc[c+d*x])^n where a^2-b^2=0 and n is an integer *)
{1/(a + a*Csc[c + d*x]), x, 2, x/a + Cot[c + d*x]/(d*(a + a*Csc[c + d*x]))}
{1/(a + a*Csc[c + d*x])^2, x, 3, x/a^2 + Cot[c + d*x]/(3*d*(a + a*Csc[c + d*x])^2) + (4*Cot[c + d*x])/(3*a*d*(a + a*Csc[c + d*x]))}
{1/(a + a*Csc[c + d*x])^3, x, 4, x/a^3 + Cot[c + d*x]/(5*d*(a + a*Csc[c + d*x])^3) + (7*Cot[c + d*x])/(15*a*d*(a + a*Csc[c + d*x])^2) + (22*Cot[c + d*x])/(15*a^2*d*(a + a*Csc[c + d*x]))}


(* ::Subsection::Closed:: *)
(*Integrands of the form Csc[c+d x]^m (a+a Csc[c+d x])^(n/2)*)


(* Integrands of the form (a+b*Csc[c+d*x])^n where a^2-b^2=0 and n is a half-integer *)
{(a + a*Csc[x])^(5/2), x, 4, -2*a^(5/2)*ArcTan[(Sqrt[a]*Cot[x])/Sqrt[a + a*Csc[x]]] - (14*a^3*Cot[x])/(3*Sqrt[a + a*Csc[x]]) - (2/3)*a^2*Cot[x]*Sqrt[a + a*Csc[x]]}
{(a + a*Csc[x])^(3/2), x, 3, -2*a^(3/2)*ArcTan[(Sqrt[a]*Cot[x])/Sqrt[a + a*Csc[x]]] - (2*a^2*Cot[x])/Sqrt[a + a*Csc[x]]}
{(a + a*Csc[x])^(1/2), x, 1, -2*Sqrt[a]*ArcTan[(Sqrt[a]*Cot[x])/Sqrt[a + a*Csc[x]]]}
{1/(a + a*Csc[x])^(1/2), x, 3, -((2*ArcTan[(Sqrt[a]*Cot[x])/Sqrt[a + a*Csc[x]]])/Sqrt[a]) + (Sqrt[2]*ArcTan[(Sqrt[a]*Cot[x])/(Sqrt[2]*Sqrt[a + a*Csc[x]])])/Sqrt[a]}
{1/(a + a*Csc[x])^(3/2), x, 4, -((2*ArcTan[(Sqrt[a]*Cot[x])/Sqrt[a + a*Csc[x]]])/a^(3/2)) + (5*ArcTan[(Sqrt[a]*Cot[x])/(Sqrt[2]*Sqrt[a + a*Csc[x]])])/(2*Sqrt[2]*a^(3/2)) + Cot[x]/(2*(a + a*Csc[x])^(3/2))}
{1/(a + a*Csc[x])^(5/2), x, 5, -((2*ArcTan[(Sqrt[a]*Cot[x])/Sqrt[a + a*Csc[x]]])/a^(5/2)) + (43*ArcTan[(Sqrt[a]*Cot[x])/(Sqrt[2]*Sqrt[a + a*Csc[x]])])/(16*Sqrt[2]*a^(5/2)) + Cot[x]/(4*(a + a*Csc[x])^(5/2)) + (11*Cot[x])/(16*a*(a + a*Csc[x])^(3/2))}

{(a - a*Csc[x])^(5/2), x, 4, -2*a^(5/2)*ArcTan[(Sqrt[a]*Cot[x])/Sqrt[a - a*Csc[x]]] - (14*a^3*Cot[x])/(3*Sqrt[a - a*Csc[x]]) - (2/3)*a^2*Cot[x]*Sqrt[a - a*Csc[x]]}
{(a - a*Csc[x])^(3/2), x, 3, -2*a^(3/2)*ArcTan[(Sqrt[a]*Cot[x])/Sqrt[a - a*Csc[x]]] - (2*a^2*Cot[x])/Sqrt[a - a*Csc[x]]}
{(a - a*Csc[x])^(1/2), x, 1, -2*Sqrt[a]*ArcTan[(Sqrt[a]*Cot[x])/Sqrt[a - a*Csc[x]]]}
{1/(a - a*Csc[x])^(1/2), x, 3, -((2*ArcTan[(Sqrt[a]*Cot[x])/Sqrt[a - a*Csc[x]]])/Sqrt[a]) + (Sqrt[2]*ArcTan[(Sqrt[a]*Cot[x])/(Sqrt[2]*Sqrt[a - a*Csc[x]])])/Sqrt[a]}
{1/(a - a*Csc[x])^(3/2), x, 4, -((2*ArcTan[(Sqrt[a]*Cot[x])/Sqrt[a - a*Csc[x]]])/a^(3/2)) + (5*ArcTan[(Sqrt[a]*Cot[x])/(Sqrt[2]*Sqrt[a - a*Csc[x]])])/(2*Sqrt[2]*a^(3/2)) + Cot[x]/(2*(a - a*Csc[x])^(3/2))}
{1/(a - a*Csc[x])^(5/2), x, 5, -((2*ArcTan[(Sqrt[a]*Cot[x])/Sqrt[a - a*Csc[x]]])/a^(5/2)) + (43*ArcTan[(Sqrt[a]*Cot[x])/(Sqrt[2]*Sqrt[a - a*Csc[x]])])/(16*Sqrt[2]*a^(5/2)) + Cot[x]/(4*(a - a*Csc[x])^(5/2)) + (11*Cot[x])/(16*a*(a - a*Csc[x])^(3/2))}


(* ::Section:: *)
(*Csc[c+d x]^m (A+B Csc[c+d x]) (a+a Csc[c+d x])^n*)


(* ::Subsection:: *)
(*Integrands of the form Csc[c+d x]^m (A+B Csc[c+d x]) (a+a Csc[c+d x])^n*)


(* ::Subsection:: *)
(*Integrands of the form Csc[c+d x]^m (A+B Csc[c+d x]) (a+a Csc[c+d x])^(n/2)*)


(* ::Section:: *)
(*Csc[c+d x]^m (A+C Csc[c+d x]^2) (a+a Csc[c+d x])^n*)


(* ::Subsection:: *)
(*Integrands of the form Csc[c+d x]^m (A+C Csc[c+d x]^2) (a+a Csc[c+d x])^n*)


(* ::Subsection:: *)
(*Integrands of the form Csc[c+d x]^m (A+C Csc[c+d x]^2) (a+a Csc[c+d x])^(n/2)*)


(* ::Section:: *)
(*Csc[c+d x]^m (A+B Csc[c+d x]+C Csc[c+d x]^2) (a+a Csc[c+d x])^n*)


(* ::Subsection:: *)
(*Integrands of the form Csc[c+d x]^m (A+B Csc[c+d x]+C Csc[c+d x]^2) (a+a Csc[c+d x])^n*)


(* ::Subsection:: *)
(*Integrands of the form Csc[c+d x]^m (A+B Csc[c+d x]+C Csc[c+d x]^2) (a+a Csc[c+d x])^(n/2)*)
