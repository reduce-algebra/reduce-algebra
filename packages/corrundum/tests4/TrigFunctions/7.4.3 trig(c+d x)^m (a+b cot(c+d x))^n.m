(* ::Package:: *)

(* ::Title:: *)
(*Integrands of the form trig(c+d x)^m (a+b cot(c+d x))^n*)


(* ::Section::Closed:: *)
(*Integrands of the form Sin[c+d x]^m (a+b Cot[c+d x])^n when a^2+b^2=0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[c+d x]^m (a+b Cot[c+d x])^n*)


(* ::Subsubsection:: *)
(*n>0*)


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Sin[x]^4/(I + Cot[x]), x, 5, -((5*I*x)/16) + 1/(32*(I - Cot[x])^2) - I/(8*(I - Cot[x])) - I/(24*(I + Cot[x])^3) - 3/(32*(I + Cot[x])^2) + (3*I)/(16*(I + Cot[x]))}
{Sin[x]^3/(I + Cot[x]), x, 7, I*Cos[x] - (2/3)*I*Cos[x]^3 + (1/5)*I*Cos[x]^5 + Sin[x]^5/5}
{Sin[x]^2/(I + Cot[x]), x, 5, -((3*I*x)/8) - I/(8*(I - Cot[x])) - 1/(8*(I + Cot[x])^2) + I/(4*(I + Cot[x]))}
{Sin[x]^1/(I + Cot[x]), x, 7, I*Cos[x] - (1/3)*I*Cos[x]^3 + Sin[x]^3/3}
{Csc[x]^1/(I + Cot[x]), x, 2, I/(Cos[x] + I*Sin[x])}
{Csc[x]^2/(I + Cot[x]), x, 2, -Log[I + Cot[x]]}
{Csc[x]^3/(I + Cot[x]), x, 6, I*ArcTanh[Cos[x]] - Csc[x]}
{Csc[x]^4/(I + Cot[x]), x, 3, I*Cot[x] - Cot[x]^2/2}
{Csc[x]^5/(I + Cot[x]), x, 7, (1/2)*I*ArcTanh[Cos[x]] + (1/2)*I*Cot[x]*Csc[x] - Csc[x]^3/3}
{Csc[x]^6/(I + Cot[x]), x, 4, I*Cot[x] - Cot[x]^2/2 + (1/3)*I*Cot[x]^3 - Cot[x]^4/4}
{Csc[x]^7/(I + Cot[x]), x, 8, (3/8)*I*ArcTanh[Cos[x]] + (3/8)*I*Cot[x]*Csc[x] + (1/4)*I*Cot[x]*Csc[x]^3 - Csc[x]^5/5}


(* ::Section::Closed:: *)
(*Integrands of the form Sin[c+d x]^m (a+b Cot[c+d x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[c+d x]^m (a+b Cot[c+d x])^n*)
(**)


(* ::Subsubsection:: *)
(*n>0*)


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Sin[x]^4/(a + b*Cot[x]), x, 8, (a*(3*a^4 + 10*a^2*b^2 + 15*b^4)*x)/(8*(a^2 + b^2)^3) - (b + a*Cot[x])/(4*(a^2 + b^2)*(1 + Cot[x]^2)^2) - (4*b^3 + a*(3*a^2 + 7*b^2)*Cot[x])/(8*(a^2 + b^2)^2*(1 + Cot[x]^2)) - (b^5*Log[a + b*Cot[x]])/(a^2 + b^2)^3 + (b^5*Log[1 + Cot[x]^2])/(2*(a^2 + b^2)^3)}
{Sin[x]^3/(a + b*Cot[x]), x, 8, -((b^4*ArcTanh[(a*Cos[x] - b*Sin[x])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2)) - (a*b^2*Cos[x])/(a^2 + b^2)^2 - (a*Cos[x])/(a^2 + b^2) + (a*Cos[x]^3)/(3*(a^2 + b^2)) - (b^3*Sin[x])/(a^2 + b^2)^2 - (b*Sin[x]^3)/(3*(a^2 + b^2))}
{Sin[x]^2/(a + b*Cot[x]), x, 7, (a*(a^2 + 3*b^2)*x)/(2*(a^2 + b^2)^2) - (b + a*Cot[x])/(2*(a^2 + b^2)*(1 + Cot[x]^2)) - (b^3*Log[a + b*Cot[x]])/(a^2 + b^2)^2 + (b^3*Log[1 + Cot[x]^2])/(2*(a^2 + b^2)^2)}
{Sin[x]^1/(a + b*Cot[x]), x, 5, -((b^2*ArcTanh[(a*Cos[x] - b*Sin[x])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(3/2)) - (a*Cos[x])/(a^2 + b^2) - (b*Sin[x])/(a^2 + b^2)}
{Csc[x]^1/(a + b*Cot[x]), x, 3, -(ArcTanh[(a*Cos[x] - b*Sin[x])/Sqrt[a^2 + b^2]]/Sqrt[a^2 + b^2])}
{Csc[x]^2/(a + b*Cot[x]), x, 2, -(Log[a + b*Cot[x]]/b)}
{Csc[x]^3/(a + b*Cot[x]), x, 5, (a*ArcTanh[Cos[x]])/b^2 - (Sqrt[a^2 + b^2]*ArcTanh[(a*Cos[x] - b*Sin[x])/Sqrt[a^2 + b^2]])/b^2 - Csc[x]/b}
{Csc[x]^4/(a + b*Cot[x]), x, 3, (a*Cot[x])/b^2 - Cot[x]^2/(2*b) - ((a^2 + b^2)*Log[a + b*Cot[x]])/b^3}


{Csc[x]^2/(a + b*Cot[x])^2, x, 2, 1/(b*(a + b*Cot[x]))}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{Csc[x]^2*(a + b*Cot[x])^n, x, 2, -((a + b*Cot[x])^(1 + n)/(b*(1 + n)))}


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[c+d x]^m (a+b Cot[c+d x])^(n/2)*)


(* ::Subsubsection:: *)
(*n>0*)


(* ::Subsubsection:: *)
(*n<0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[c+d x]^(m/2) (a+b Cot[c+d x])^n*)


(* ::Subsubsection:: *)
(*n>0*)


(* ::Subsubsection:: *)
(*n<0*)


(* ::Subsubsection:: *)
(*n symbolic*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[c+d x]^(m/2) (a+b Cot[c+d x])^(n/2)*)
(**)


(* ::Subsubsection:: *)
(*n>0*)


(* ::Subsubsection:: *)
(*n<0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[c+d x]^(m/3) (a+b Cot[c+d x])^n*)


(* ::Subsubsection:: *)
(*n>0*)


(* ::Subsubsection:: *)
(*n<0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[c+d x]^(m/3) (a+b Cot[c+d x])^(n/2)*)


(* ::Subsubsection:: *)
(*n>0*)


(* ::Subsubsection:: *)
(*n<0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Csc[c+d x]^(m/2) (a+b Cot[c+d x])^n*)


(* ::Subsubsection:: *)
(*n>0*)


(* ::Subsubsection:: *)
(*n<0*)


(* ::Subsubsection:: *)
(*n symbolic*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Csc[c+d x]^(m/2) (a+b Cot[c+d x])^(n/2)*)


(* ::Subsubsection:: *)
(*n>0*)


(* ::Subsubsection:: *)
(*n<0*)


(* ::Section::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (a+b Cot[c+d x])^n when a^2+b^2=0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (a+b Cot[c+d x])^n when a^2+b^2=0*)


(* ::Subsubsection:: *)
(*n>0*)


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Cos[x]^4/(I + Cot[x]), x, 5, -((I*x)/16) + 1/(32*(I - Cot[x])^2) + I/(8*(I - Cot[x])) - I/(24*(I + Cot[x])^3) + 5/(32*(I + Cot[x])^2) + (3*I)/(16*(I + Cot[x]))}
{Cos[x]^3/(I + Cot[x]), x, 8, (-(1/5))*Cos[x]^5 - (1/3)*I*Sin[x]^3 + (1/5)*I*Sin[x]^5}
{Cos[x]^2/(I + Cot[x]), x, 5, -((I*x)/8) + I/(8*(I - Cot[x])) + 1/(8*(I + Cot[x])^2) + I/(4*(I + Cot[x]))}
{Cos[x]^1/(I + Cot[x]), x, 6, (-(1/3))*Cos[x]^3 - (1/3)*I*Sin[x]^3}
{Sec[x]^1/(I + Cot[x]), x, 7, (-I)*ArcTanh[Sin[x]] - Cos[x] + I*Sin[x]}
{Sec[x]^2/(I + Cot[x]), x, 3, -Log[Cot[x]] + Log[I + Cot[x]] - I*Tan[x]}
{Sec[x]^3/(I + Cot[x]), x, 7, (1/2)*I*ArcTanh[Sin[x]] + Sec[x] - (1/2)*I*Sec[x]*Tan[x]}
{Sec[x]^4/(I + Cot[x]), x, 4, Tan[x]^2/2 - (1/3)*I*Tan[x]^3}
{Sec[x]^5/(I + Cot[x]), x, 8, (1/8)*I*ArcTanh[Sin[x]] + Sec[x]^3/3 - (1/8)*I*Sec[x]*Tan[x] - (1/4)*I*Sec[x]*Tan[x]^3}
{Sec[x]^6/(I + Cot[x]), x, 4, Tan[x]^2/2 - (1/3)*I*Tan[x]^3 + Tan[x]^4/4 - (1/5)*I*Tan[x]^5}


(* ::Section::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (a+b Cot[c+d x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (a+b Cot[c+d x])^n*)


(* ::Subsubsection:: *)
(*n>0*)


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Cos[x]^4/(a + b*Cot[x]), x, 11, (a^5*x)/(a^2 + b^2)^3 + (3*a*x)/(8*(a^2 + b^2)) - (a*(2*a^2 + b^2)*x)/(2*(a^2 + b^2)^2) - (b + a*Cot[x])/(4*(a^2 + b^2)*(1 + Cot[x]^2)^2) - (3*a*Cot[x])/(8*(a^2 + b^2)*(1 + Cot[x]^2)) + ((2*a^2 + b^2)*(b + a*Cot[x]))/(2*(a^2 + b^2)^2*(1 + Cot[x]^2)) - (a^4*b*Log[a + b*Cot[x]])/(a^2 + b^2)^3 + (a^4*b*Log[1 + Cot[x]^2])/(2*(a^2 + b^2)^3)}
{Cos[x]^3/(a + b*Cot[x]), x, 9, (a^3*b*ArcTanh[(a*Cos[x] - b*Sin[x])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2) - (a^2*b*Cos[x])/(a^2 + b^2)^2 - (b*Cos[x]^3)/(3*(a^2 + b^2)) - (a*b^2*Sin[x])/(a^2 + b^2)^2 + (a*Sin[x])/(a^2 + b^2) - (a*Sin[x]^3)/(3*(a^2 + b^2))}
{Cos[x]^2/(a + b*Cot[x]), x, 8, (a^3*x)/(a^2 + b^2)^2 - (a*x)/(2*(a^2 + b^2)) + (b + a*Cot[x])/(2*(a^2 + b^2)*(1 + Cot[x]^2)) - (a^2*b*Log[a + b*Cot[x]])/(a^2 + b^2)^2 + (a^2*b*Log[1 + Cot[x]^2])/(2*(a^2 + b^2)^2)}
{Cos[x]^1/(a + b*Cot[x]), x, 6, (a*b*ArcTanh[(a*Cos[x] - b*Sin[x])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(3/2) - (b*Cos[x])/(a^2 + b^2) + (a*Sin[x])/(a^2 + b^2)}
{Sec[x]^1/(a + b*Cot[x]), x, 6, ArcTanh[Sin[x]]/a + (b*ArcTanh[(a*Cos[x] - b*Sin[x])/Sqrt[a^2 + b^2]])/(a*Sqrt[a^2 + b^2])}
{Sec[x]^2/(a + b*Cot[x]), x, 3, (b*Log[Cot[x]])/a^2 - (b*Log[a + b*Cot[x]])/a^2 + Tan[x]/a}
{Sec[x]^3/(a + b*Cot[x]), x, 9, ArcTanh[Sin[x]]/(2*a) + (b^2*ArcTanh[Sin[x]])/a^3 + (b*Sqrt[a^2 + b^2]*ArcTanh[(a*Cos[x] - b*Sin[x])/Sqrt[a^2 + b^2]])/a^3 - (b*Sec[x])/a^2 + (Sec[x]*Tan[x])/(2*a)}
{Sec[x]^4/(a + b*Cot[x]), x, 3, (b*(a^2 + b^2)*Log[Cot[x]])/a^4 - (b*(a^2 + b^2)*Log[a + b*Cot[x]])/a^4 + ((a^2 + b^2)*Tan[x])/a^3 - (b*Tan[x]^2)/(2*a^2) + Tan[x]^3/(3*a)}


(* Following hangs Mathematica 6 & 7: *) 
{Sec[x]/(1 + 2*Cot[x]), x, 6, (2*ArcTanh[(Cos[x] - 2*Sin[x])/Sqrt[5]])/Sqrt[5] + ArcTanh[Sin[x]]}


(* ::Subsubsection:: *)
(*n symbolic*)
