(* ::Package:: *)

(* ::Title:: *)
(*Integration problems of the form *)
(*Csc[c+d x]^m (A+B Csc[c+d x]+C Csc[c+d x]^2) (a+b Csc[c+d x])^n when a^2=b^2*)


(* ::Section:: *)
(*Csc[c+d x]^m (a+a Csc[c+d x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Csc[c+d x]^m (a+a Csc[c+d x])^n*)


{Csc[x]^5/(a + a*Csc[x]), x, 5, (3*ArcTanh[Cos[x]])/(2*a) - (4*Cot[x])/a - (4*Cot[x]^3)/(3*a) + (3*Cot[x]*Csc[x])/(2*a) + (Cot[x]*Csc[x]^3)/(a + a*Csc[x])}
{Csc[x]^4/(a + a*Csc[x]), x, 4, -((3*ArcTanh[Cos[x]])/(2*a)) + (2*Cot[x])/a - (3*Cot[x]*Csc[x])/(2*a) + (Cot[x]*Csc[x]^2)/(a + a*Csc[x])}
{Csc[x]^3/(a + a*Csc[x]), x, 3, ArcTanh[Cos[x]]/a - (2*Cot[x])/a + (Cot[x]*Csc[x])/(a + a*Csc[x])}
{Csc[x]^2/(a + a*Csc[x]), x, 4, -(ArcTanh[Cos[x]]/a) + Cos[x]/(a + a*Sin[x])}
{Csc[x]^1/(a + a*Csc[x]), x, 2, -(Cos[x]/(a + a*Sin[x]))}
{Sin[x]^1/(a + a*Csc[x]), x, 3, -(x/a) - (2*Cos[x])/a + Cos[x]/(a + a*Csc[x])}
{Sin[x]^2/(a + a*Csc[x]), x, 4, (3*x)/(2*a) + (2*Cos[x])/a - (3*Cos[x]*Sin[x])/(2*a) + (Cos[x]*Sin[x])/(a + a*Csc[x])}
{Sin[x]^3/(a + a*Csc[x]), x, 5, -((3*x)/(2*a)) - (4*Cos[x])/a + (4*Cos[x]^3)/(3*a) + (3*Cos[x]*Sin[x])/(2*a) + (Cos[x]*Sin[x]^2)/(a + a*Csc[x])}
{Sin[x]^4/(a + a*Csc[x]), x, 6, (15*x)/(8*a) + (4*Cos[x])/a - (4*Cos[x]^3)/(3*a) - (15*Cos[x]*Sin[x])/(8*a) - (5*Cos[x]*Sin[x]^3)/(4*a) + (Cos[x]*Sin[x]^3)/(a + a*Csc[x])}


{1/(a + a*Csc[c + d*x]), x, 2, x/a + Cot[c + d*x]/(d*(a + a*Csc[c + d*x]))}
{1/(a + a*Csc[c + d*x])^2, x, 3, x/a^2 + Cot[c + d*x]/(3*d*(a + a*Csc[c + d*x])^2) + (4*Cos[c + d*x])/(3*a^2*d*(1 + Sin[c + d*x]))}
{1/(a + a*Csc[c + d*x])^3, x, 4, x/a^3 + Cot[c + d*x]/(5*d*(a + a*Csc[c + d*x])^3) + (7*Cot[c + d*x])/(15*a*d*(a + a*Csc[c + d*x])^2) + (22*Cos[c + d*x])/(15*d*(a^3 + a^3*Sin[c + d*x]))}


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


(* ::Subsection::Closed:: *)
(*Integrands of the form Csc[c+d x]^m (A+A Csc[c+d x]) (a+a Csc[c+d x])^n*)


{(A + A*Csc[c + d*x])*(a + a*Csc[c + d*x])^1*Csc[c + d*x]^3, x, 7, -((7*a*A*ArcTanh[Cos[c + d*x]])/(8*d)) - (2*a*A*Cot[c + d*x])/d - (2*a*A*Cot[c + d*x]^3)/(3*d) - (7*a*A*Cot[c + d*x]*Csc[c + d*x])/(8*d) - (a*A*Cot[c + d*x]*Csc[c + d*x]^3)/(4*d)}
{(A + A*Csc[c + d*x])*(a + a*Csc[c + d*x])^1*Csc[c + d*x]^2, x, 6, -((a*A*ArcTanh[Cos[c + d*x]])/d) - (5*a*A*Cot[c + d*x])/(3*d) - (a*A*Cot[c + d*x]*Csc[c + d*x])/d - (a*A*Cot[c + d*x]*Csc[c + d*x]^2)/(3*d)}
{(A + A*Csc[c + d*x])*(a + a*Csc[c + d*x])^1*Csc[c + d*x]^1, x, 5, -((3*a*A*ArcTanh[Cos[c + d*x]])/(2*d)) - (2*a*A*Cot[c + d*x])/d - (a*A*Cot[c + d*x]*Csc[c + d*x])/(2*d)}
{(A + A*Csc[c + d*x])*(a + a*Csc[c + d*x])^1/Csc[c + d*x]^1, x, 4, 2*a*A*x - (a*A*ArcTanh[Cos[c + d*x]])/d - (a*A*Cos[c + d*x])/d}
{(A + A*Csc[c + d*x])*(a + a*Csc[c + d*x])^1/Csc[c + d*x]^2, x, 4, (3*a*A*x)/2 - (2*a*A*Cos[c + d*x])/d - (a*A*Cos[c + d*x]*Sin[c + d*x])/(2*d)}
{(A + A*Csc[c + d*x])*(a + a*Csc[c + d*x])^1/Csc[c + d*x]^3, x, 5, a*A*x - (5*a*A*Cos[c + d*x])/(3*d) - (a*A*Cos[c + d*x]*Sin[c + d*x])/d - (a*A*Cos[c + d*x]*Sin[c + d*x]^2)/(3*d)}


{(A + A*Csc[c + d*x])*(a - a*Csc[c + d*x])^1*Csc[c + d*x]^3, x, 4, -((a*A*ArcTanh[Cos[c + d*x]])/(8*d)) - (a*A*Cot[c + d*x]*Csc[c + d*x])/(8*d) + (a*A*Cot[c + d*x]*Csc[c + d*x]^3)/(4*d)}
{(A + A*Csc[c + d*x])*(a - a*Csc[c + d*x])^1*Csc[c + d*x]^2, x, 3, -((a*A*Cot[c + d*x])/(3*d)) + (a*A*Cot[c + d*x]*Csc[c + d*x]^2)/(3*d)}
{(A + A*Csc[c + d*x])*(a - a*Csc[c + d*x])^1*Csc[c + d*x]^1, x, 3, -((a*A*ArcTanh[Cos[c + d*x]])/(2*d)) + (a*A*Cot[c + d*x]*Csc[c + d*x])/(2*d)}
{(A + A*Csc[c + d*x])*(a - a*Csc[c + d*x])^1/Csc[c + d*x]^1, x, 3, (a*A*ArcTanh[Cos[c + d*x]])/d - (a*A*Cos[c + d*x])/d}
{(A + A*Csc[c + d*x])*(a - a*Csc[c + d*x])^1/Csc[c + d*x]^2, x, 2, (-(1/2))*a*A*x - (a*A*Cos[c + d*x]*Sin[c + d*x])/(2*d)}
{(A + A*Csc[c + d*x])*(a - a*Csc[c + d*x])^1/Csc[c + d*x]^3, x, 3, (a*A*Cos[c + d*x])/(3*d) - (a*A*Cos[c + d*x]*Sin[c + d*x]^2)/(3*d)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Csc[c+d x]^m (A-A Csc[c+d x]) (a+a Csc[c+d x])^n*)


{(A - A*Csc[c + d*x])*(a + a*Csc[c + d*x])^1*Csc[c + d*x]^3, x, 4, -((a*A*ArcTanh[Cos[c + d*x]])/(8*d)) - (a*A*Cot[c + d*x]*Csc[c + d*x])/(8*d) + (a*A*Cot[c + d*x]*Csc[c + d*x]^3)/(4*d)}
{(A - A*Csc[c + d*x])*(a + a*Csc[c + d*x])^1*Csc[c + d*x]^2, x, 3, -((a*A*Cot[c + d*x])/(3*d)) + (a*A*Cot[c + d*x]*Csc[c + d*x]^2)/(3*d)}
{(A - A*Csc[c + d*x])*(a + a*Csc[c + d*x])^1*Csc[c + d*x]^1, x, 3, -((a*A*ArcTanh[Cos[c + d*x]])/(2*d)) + (a*A*Cot[c + d*x]*Csc[c + d*x])/(2*d)}
{(A - A*Csc[c + d*x])*(a + a*Csc[c + d*x])^1/Csc[c + d*x]^1, x, 3, (a*A*ArcTanh[Cos[c + d*x]])/d - (a*A*Cos[c + d*x])/d}
{(A - A*Csc[c + d*x])*(a + a*Csc[c + d*x])^1/Csc[c + d*x]^2, x, 2, (-(1/2))*a*A*x - (a*A*Cos[c + d*x]*Sin[c + d*x])/(2*d)}
{(A - A*Csc[c + d*x])*(a + a*Csc[c + d*x])^1/Csc[c + d*x]^3, x, 3, (a*A*Cos[c + d*x])/(3*d) - (a*A*Cos[c + d*x]*Sin[c + d*x]^2)/(3*d)}


{(A - A*Csc[c + d*x])*(a - a*Csc[c + d*x])^1*Csc[c + d*x]^3, x, 7, -((7*a*A*ArcTanh[Cos[c + d*x]])/(8*d)) + (2*a*A*Cot[c + d*x])/d + (2*a*A*Cot[c + d*x]^3)/(3*d) - (7*a*A*Cot[c + d*x]*Csc[c + d*x])/(8*d) - (a*A*Cot[c + d*x]*Csc[c + d*x]^3)/(4*d)}
{(A - A*Csc[c + d*x])*(a - a*Csc[c + d*x])^1*Csc[c + d*x]^2, x, 6, (a*A*ArcTanh[Cos[c + d*x]])/d - (5*a*A*Cot[c + d*x])/(3*d) + (a*A*Cot[c + d*x]*Csc[c + d*x])/d - (a*A*Cot[c + d*x]*Csc[c + d*x]^2)/(3*d)}
{(A - A*Csc[c + d*x])*(a - a*Csc[c + d*x])^1*Csc[c + d*x]^1, x, 5, -((3*a*A*ArcTanh[Cos[c + d*x]])/(2*d)) + (2*a*A*Cot[c + d*x])/d - (a*A*Cot[c + d*x]*Csc[c + d*x])/(2*d)}
{(A - A*Csc[c + d*x])*(a - a*Csc[c + d*x])^1/Csc[c + d*x]^1, x, 4, -2*a*A*x - (a*A*ArcTanh[Cos[c + d*x]])/d - (a*A*Cos[c + d*x])/d}
{(A - A*Csc[c + d*x])*(a - a*Csc[c + d*x])^1/Csc[c + d*x]^2, x, 4, (3*a*A*x)/2 + (2*a*A*Cos[c + d*x])/d - (a*A*Cos[c + d*x]*Sin[c + d*x])/(2*d)}
{(A - A*Csc[c + d*x])*(a - a*Csc[c + d*x])^1/Csc[c + d*x]^3, x, 5, (-a)*A*x - (5*a*A*Cos[c + d*x])/(3*d) + (a*A*Cos[c + d*x]*Sin[c + d*x])/d - (a*A*Cos[c + d*x]*Sin[c + d*x]^2)/(3*d)}


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
