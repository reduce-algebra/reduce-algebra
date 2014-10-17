(* ::Package:: *)

(* ::Title:: *)
(*Miscellaneous Integration Problems Involving Trig Functions*)


(* ::Section::Closed:: *)
(*Integrands involving three trig functions*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Trig[x]^m (a Trig[x] + b Trig[x])*)


{Sin[x]*(Cos[x] + Sin[x]), x, 5, x/2 - (1/2)*Cos[x]*Sin[x] + Sin[x]^2/2}
{Sec[x]*(Cos[x] + Sin[x]), x, 3, x - Log[Cos[x]]}
{Cos[x]*(Sin[x] + Tan[x]), x, 5, -Cos[x] + Sin[x]^2/2}
{Csc[x]*(Cot[x] + Csc[x]), x, 5, -Cot[x] - Csc[x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form Trig[x]^m / (a Trig[x] + b Trig[x])*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Trig[x]^m / (a Cos[x] + b Sin[x])*)


(* Integrands of the form Sin[x]^m/(a*Cos[x]+b*Sin[x]) *)
{Sin[x]/(a*Cos[x] + b*Sin[x]), x, 1, (b*x)/(a^2 + b^2) - (a*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)}
{Sin[x]^2/(a*Cos[x] + b*Sin[x]), x, 4, -((2*a^2*ArcTanh[(b - a*Tan[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(3/2)) - (b*Cos[x])/(a^2 + b^2) - (a*Sin[x])/(a^2 + b^2)}
{Sin[x]^3/(a*Cos[x] + b*Sin[x]), x, 5, (a^2*b*x)/(a^2 + b^2)^2 + (b*x)/(2*(a^2 + b^2)) - (a^3*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^2 - (b*Cos[x]*Sin[x])/(2*(a^2 + b^2)) - (a*Sin[x]^2)/(2*(a^2 + b^2))}


(* Integrands of the form Cos[x]^m/(a*Cos[x]+b*Sin[x]) *)
{Cos[x]/(a*Cos[x] + b*Sin[x]), x, 1, (a*x)/(a^2 + b^2) + (b*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)}
{Cos[x]^2/(a*Cos[x] + b*Sin[x]), x, 4, -((2*b^2*ArcTanh[(b - a*Tan[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(3/2)) + (b*Cos[x])/(a^2 + b^2) + (a*Sin[x])/(a^2 + b^2)}
{Cos[x]^3/(a*Cos[x] + b*Sin[x]), x, 5, (a*b^2*x)/(a^2 + b^2)^2 + (a*x)/(2*(a^2 + b^2)) + (b^3*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^2 + (a*Cos[x]*Sin[x])/(2*(a^2 + b^2)) - (b*Sin[x]^2)/(2*(a^2 + b^2))}


(* Integrands of the form Tan[x]^m/(a*Cos[x]+b*Sin[x]) *)
{Tan[x]/(a*Sin[x] + b*Cos[x]), x, 4, ArcTanh[Sin[x]]/a + (2*b*ArcTanh[(a - b*Tan[x/2])/Sqrt[a^2 + b^2]])/(a*Sqrt[a^2 + b^2])}


(* Integrands of the form Cot[x]^m/(a*Cos[x]+b*Sin[x]) *)
{Cot[x]/(a*Sin[x] + b*Cos[x]), x, 4, -(ArcTanh[Cos[x]]/b) + (2*a*ArcTanh[(a - b*Tan[x/2])/Sqrt[a^2 + b^2]])/(b*Sqrt[a^2 + b^2])}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Trig[x]^m / (a Sec[x] + b Tan[x])*)


(* Integrands of the form Trig[x]/(Sec[x]+/-Tan[x]) *)
{Sin[x]/(Sec[x] + Tan[x]), x, 5, -Log[1 + Sin[x]] + Sin[x]}
{Cos[x]/(Sec[x] + Tan[x]), x, 4, x + Cos[x]}
{Tan[x]/(Sec[x] + Tan[x]), x, 3, x + Cos[x]/(1 + Sin[x])}
{Cot[x]/(Sec[x] + Tan[x]), x, 4, -x - ArcTanh[Cos[x]]}
{Sec[x]/(Sec[x] + Tan[x]), x, 2, -(Cos[x]/(1 + Sin[x]))}
{Csc[x]/(Sec[x] + Tan[x]), x, 3, -2*ArcTanh[1 + 2*Sin[x]]}

{Sin[x]/(Sec[x] - Tan[x]), x, 5, -Log[1 - Sin[x]] - Sin[x]}
{Cos[x]/(Sec[x] - Tan[x]), x, 4, x - Cos[x]}
{Tan[x]/(Sec[x] - Tan[x]), x, 3, -x + Cos[x]/(1 - Sin[x])}
{Cot[x]/(Sec[x] - Tan[x]), x, 4, x - ArcTanh[Cos[x]]}
{Sec[x]/(Sec[x] - Tan[x]), x, 2, Cos[x]/(1 - Sin[x])}
{Csc[x]/(Sec[x] - Tan[x]), x, 4, -2*ArcTanh[1 - 2*Sin[x]]}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Trig[x]^m / (a Csc[x] + b Cot[x])*)


(* Integrands of the form Trig[x]/(Csc[x]+/-Cot[x]) *)
{Sin[x]/(Csc[x] + Cot[x]), x, 4, x - Sin[x]}
{Cos[x]/(Csc[x] + Cot[x]), x, 5, -Cos[x] + Log[1 + Cos[x]]}
{Tan[x]/(Csc[x] + Cot[x]), x, 4, -x+ArcTanh[Sin[x]]}
{Cot[x]/(Csc[x] + Cot[x]), x, 3, x - Sin[x]/(1 + Cos[x])}
{Sec[x]/(Csc[x] + Cot[x]), x, 3, 2*ArcTanh[1 + 2*Cos[x]]}
{Csc[x]/(Csc[x] + Cot[x]), x, 2, Sin[x]/(1 + Cos[x])}

{Sin[x]/(Csc[x] - Cot[x]), x, 4, x + Sin[x]}
{Cos[x]/(Csc[x] - Cot[x]), x, 5, Cos[x] + Log[1 - Cos[x]]}
{Tan[x]/(Csc[x] - Cot[x]), x, 4, x + ArcTanh[Sin[x]]}
{Cot[x]/(Csc[x] - Cot[x]), x, 3, -x - Sin[x]/(1 - Cos[x])}
{Sec[x]/(Csc[x] - Cot[x]), x, 4, 2*ArcTanh[1 - 2*Cos[x]]}
{Csc[x]/(Csc[x] - Cot[x]), x, 2, -(Sin[x]/(1 - Cos[x]))}

{Csc[x]/(Csc[x] - Sin[x]), x, 3, Tan[x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form Trig[x]^m / (a Trig[x] + b Trig[x])^2*)


(* Integrands of the form Sin[x]^m/(a*Cos[x]+b*Sin[x])^2 *)
{Sin[x]/(a*Cos[x] + b*Sin[x])^2, x, 2, -((2*b*ArcTanh[(b - a*Tan[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(3/2)) + a/((a^2 + b^2)*(a*Cos[x] + b*Sin[x]))}
{Sin[x]^2/(a*Cos[x] + b*Sin[x])^2, x, 4, (2*b^2*x)/(a^2 + b^2)^2 - x/(a^2 + b^2) + a/((a^2 + b^2)*(b + a*Cot[x])) - (2*a*b*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^2}
(* {Sin[x]^3/(a*Cos[x] + b*Sin[x])^2, x, 0, (12*a^2*b*Sqrt[a^2 + b^2]*ArcTanh[(-b + a*Tan[x/2])/Sqrt[a^2 + b^2]]*(a*Cos[x] + b*Sin[x]) + (a^2 + b^2)*(3*a*(a^2 - b^2) + a*(a^2 + b^2)*Cos[2*x] - b*(a^2 + b^2)*Sin[2*x]))/(2*(a^2 + b^2)^3*(a*Cos[x] + b*Sin[x]))} *)


(* Integrands of the form Cos[x]^m/(a*Cos[x]+b*Sin[x])^2 *)
{Cos[x]/(a*Cos[x] + b*Sin[x])^2, x, 2, -((2*a*ArcTanh[(b - a*Tan[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(3/2)) - b/((a^2 + b^2)*(a*Cos[x] + b*Sin[x]))}
{Cos[x]^2/(a*Cos[x] + b*Sin[x])^2, x, 4, (2*a^2*x)/(a^2 + b^2)^2 - x/(a^2 + b^2) + (2*a*b*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^2 - b/((a^2 + b^2)*(a + b*Tan[x]))}
(* {Cos[x]^3/(a*Cos[x] + b*Sin[x])^2, x, 0, (12*a*b^2*Sqrt[a^2 + b^2]*ArcTanh[(-b + a*Tan[x/2])/Sqrt[a^2 + b^2]]*(a*Cos[x] + b*Sin[x]) + (a^2 + b^2)*(3*b*(a^2 - b^2) + b*(a^2 + b^2)*Cos[2*x] + a*(a^2 + b^2)*Sin[2*x]))/(2*(a^2 + b^2)^3*(a*Cos[x] + b*Sin[x]))} *)


(* ::Subsection::Closed:: *)
(*Integrands of the form Trig[x]^m / (a Trig[x] + b Trig[x])^3*)


(* Integrands of the form Sin[x]^m/(a*Cos[x]+b*Sin[x])^3 *)
{Sin[x]/(a*Cos[x] + b*Sin[x])^3, x, 3, a/(2*(a^2 + b^2)*(a*Cos[x] + b*Sin[x])^2) + (b*Sin[x])/(a*(a^2 + b^2)*(a*Cos[x] + b*Sin[x]))}
(* {Sin[x]^2/(a*Cos[x] + b*Sin[x])^3, x, 0, -(((a^2 - 2*b^2)*ArcTanh[(-b + a*Tan[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2)) + (a*(3*a*b*Cos[x] + (a^2 + 4*b^2)*Sin[x]))/(2*(a^2 + b^2)^2*(a*Cos[x] + b*Sin[x])^2)} *)
{Sin[x]^3/(a*Cos[x] + b*Sin[x])^3, x, 5, -((b*(a^2 - 3*b^2)*x)/(a^2 + b^2)^3) - (2*b*x)/(a^2 + b^2)^2 + a/(2*(a^2 + b^2)*(b + a*Cot[x])^2) + (2*a*b)/((a^2 + b^2)^2*(b + a*Cot[x])) + (a*(a^2 - 3*b^2)*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^3}


(* Integrands of the form Cos[x]^m/(a*Cos[x]+b*Sin[x])^3 *)
{Cos[x]/(a*Cos[x] + b*Sin[x])^3, x, 3, -(b/(2*(a^2 + b^2)*(a*Cos[x] + b*Sin[x])^2)) + Sin[x]/((a^2 + b^2)*(a*Cos[x] + b*Sin[x]))}
(* {Cos[x]^2/(a*Cos[x] + b*Sin[x])^3, x, 0, ((2*a^2 - b^2)*ArcTanh[(-b + a*Tan[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2) - (b*((4*a^2 + b^2)*Cos[x] + 3*a*b*Sin[x]))/(2*(a^2 + b^2)^2*(a*Cos[x] + b*Sin[x])^2)} *)
{Cos[x]^3/(a*Cos[x] + b*Sin[x])^3, x, 5, (a*(3*a^2 - b^2)*x)/(a^2 + b^2)^3 - (2*a*x)/(a^2 + b^2)^2 + (b*(3*a^2 - b^2)*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^3 - b/(2*(a^2 + b^2)*(a + b*Tan[x])^2) - (2*a*b)/((a^2 + b^2)^2*(a + b*Tan[x]))}


(* ::Subsection::Closed:: *)
(*Integrands of the form Trig[x]^m / (a+b Trig[x] + c Trig[x])*)


{Sin[x]/(a + b*Cos[x] + c*Sin[x]), x, 2, (c*x)/(b^2 + c^2) - (2*a*c*ArcTan[(c + (a - b)*Tan[x/2])/Sqrt[a^2 - b^2 - c^2]])/(Sqrt[a^2 - b^2 - c^2]*(b^2 + c^2)) - (b*Log[a + b*Cos[x] + c*Sin[x]])/(b^2 + c^2)}
{Sin[x]/(1 + Cos[x] + Sin[x]), x, 2, x/2 - (1/2)*Log[1 + Cos[x] + Sin[x]] - (1/2)*Log[1 + Tan[x/2]]}

{Sec[x]/(a + b*Tan[x] + c*Sec[x]), x, 2, -((2*ArcTanh[(b - (a - c)*Tan[x/2])/Sqrt[a^2 + b^2 - c^2]])/Sqrt[a^2 + b^2 - c^2])}
{Sec[x]^2/(a + b*Tan[x] + c*Sec[x]), x, 9, -((2*a*c*ArcTanh[(b - (a - c)*Tan[x/2])/Sqrt[a^2 + b^2 - c^2]])/((b^2 - c^2)*Sqrt[a^2 + b^2 - c^2])) - Log[1 - Tan[x/2]]/(b + c) - Log[1 + Tan[x/2]]/(b - c) + (b*Log[a + c + 2*b*Tan[x/2] - (a - c)*Tan[x/2]^2])/(b^2 - c^2)}

{Csc[x]/(2 + 2*Cot[x] + 3*Csc[x]), x, 2, 2*ArcTan[2 + Tan[x/2]]}
{Csc[x]/(a + b*Cot[x] + c*Csc[x]), x, 2, -((2*ArcTanh[(a - (b - c)*Tan[x/2])/Sqrt[a^2 + b^2 - c^2]])/Sqrt[a^2 + b^2 - c^2])}
{Csc[x]^2/(a + b*Cot[x] + c*Csc[x]), x, 8, -((2*a*c*ArcTanh[(a - (b - c)*Tan[x/2])/Sqrt[a^2 + b^2 - c^2]])/((b^2 - c^2)*Sqrt[a^2 + b^2 - c^2])) + Log[Tan[x/2]]/(b + c) - (b*Log[b + c + 2*a*Tan[x/2] - (b - c)*Tan[x/2]^2])/(b^2 - c^2)}


(* ::Subsection::Closed:: *)
(*Integrands of the form (A + B Trig[x]) (a Trig[x] + b Trig[x])^n*)


(* Integrands of the form (A+C*Sin[x])*(b*Cos[x]+c*Sin[x])^n *)
{(A + C*Sin[x])/(b*Cos[x] + c*Sin[x]), x, 2, (c*C*x)/(b^2 + c^2) - (2*A*ArcTanh[(c - b*Tan[x/2])/Sqrt[b^2 + c^2]])/Sqrt[b^2 + c^2] - (b*C*Log[b*Cos[x] + c*Sin[x]])/(b^2 + c^2)}
{(A + C*Sin[x])/(b*Cos[x] + c*Sin[x])^2, x, 2, -((2*c*C*ArcTanh[(c - b*Tan[x/2])/Sqrt[b^2 + c^2]])/(b^2 + c^2)^(3/2)) + (b*C - A*c*Cos[x] + A*b*Sin[x])/((b^2 + c^2)*(b*Cos[x] + c*Sin[x]))}
{(A + C*Sin[x])/(b*Cos[x] + c*Sin[x])^3, x, 3, -((A*ArcTanh[(c - b*Tan[x/2])/Sqrt[b^2 + c^2]])/(b^2 + c^2)^(3/2)) + (b*C - A*c*Cos[x] + A*b*Sin[x])/(2*(b^2 + c^2)*(b*Cos[x] + c*Sin[x])^2) - (c*C*(c*Cos[x] - b*Sin[x]))/((b^2 + c^2)^2*(b*Cos[x] + c*Sin[x]))}


(* Integrands of the form (A+B*Cos[x])*(b*Cos[x]+c*Sin[x])^n *)
{(A + B*Cos[x])/(b*Cos[x] + c*Sin[x]), x, 2, (b*B*x)/(b^2 + c^2) - (2*A*ArcTanh[(c - b*Tan[x/2])/Sqrt[b^2 + c^2]])/Sqrt[b^2 + c^2] + (B*c*Log[b*Cos[x] + c*Sin[x]])/(b^2 + c^2)}
{(A + B*Cos[x])/(b*Cos[x] + c*Sin[x])^2, x, 2, -((2*b*B*ArcTanh[(c - b*Tan[x/2])/Sqrt[b^2 + c^2]])/(b^2 + c^2)^(3/2)) - (B*c + A*c*Cos[x] - A*b*Sin[x])/((b^2 + c^2)*(b*Cos[x] + c*Sin[x]))}
{(A + B*Cos[x])/(b*Cos[x] + c*Sin[x])^3, x, 3, -((A*ArcTanh[(c - b*Tan[x/2])/Sqrt[b^2 + c^2]])/(b^2 + c^2)^(3/2)) - (B*c + A*c*Cos[x] - A*b*Sin[x])/(2*(b^2 + c^2)*(b*Cos[x] + c*Sin[x])^2) - (b*B*(c*Cos[x] - b*Sin[x]))/((b^2 + c^2)^2*(b*Cos[x] + c*Sin[x]))}


(* ::Subsection::Closed:: *)
(*Integrands of the form (A + B Trig[x]) (a+b Trig[x] + c Trig[x])^n*)


(* Integrands of the form (A+C*Sin[x])*(a+b*Cos[x]+c*Sin[x])^n *)
{(A + C*Sin[x])/(a + b*Cos[x] + c*Sin[x]), x, 2, (c*C*x)/(b^2 + c^2) + (2*(A*(b^2 + c^2) - a*c*C)*ArcTan[(c + (a - b)*Tan[x/2])/Sqrt[a^2 - b^2 - c^2]])/(Sqrt[a^2 - b^2 - c^2]*(b^2 + c^2)) - (b*C*Log[a + b*Cos[x] + c*Sin[x]])/(b^2 + c^2)}
{(A + C*Sin[x])/(a + b*Cos[x] + c*Sin[x])^2, x, 2, (2*(a*A - c*C)*ArcTan[(c + (a - b)*Tan[x/2])/Sqrt[a^2 - b^2 - c^2]])/(a^2 - b^2 - c^2)^(3/2) - (b*C - (A*c - a*C)*Cos[x] + A*b*Sin[x])/((a^2 - b^2 - c^2)*(a + b*Cos[x] + c*Sin[x]))}
{(A + C*Sin[x])/(a + b*Cos[x] + c*Sin[x])^3, x, 3, ((2*a^2*A + A*b^2 + c*(A*c - 3*a*C))*ArcTan[(c + (a - b)*Tan[x/2])/Sqrt[a^2 - b^2 - c^2]])/(a^2 - b^2 - c^2)^(5/2) - (b*C - (A*c - a*C)*Cos[x] + A*b*Sin[x])/(2*(a^2 - b^2 - c^2)*(a + b*Cos[x] + c*Sin[x])^2) - (a*b*C + (2*c^2*C - a*(3*A*c - a*C))*Cos[x] + b*(3*a*A - 2*c*C)*Sin[x])/(2*(a^2 - b^2 - c^2)^2*(a + b*Cos[x] + c*Sin[x]))}


(* Integrands of the form (A+B*Cos[x])*(a+b*Cos[x]+c*Sin[x])^n *)
{(A + B*Cos[x])/(a + b*Cos[x] + c*Sin[x]), x, 2, (b*B*x)/(b^2 + c^2) - (2*(a*b*B - A*(b^2 + c^2))*ArcTan[(c + (a - b)*Tan[x/2])/Sqrt[a^2 - b^2 - c^2]])/(Sqrt[a^2 - b^2 - c^2]*(b^2 + c^2)) + (B*c*Log[a + b*Cos[x] + c*Sin[x]])/(b^2 + c^2)}
{(A + B*Cos[x])/(a + b*Cos[x] + c*Sin[x])^2, x, 2, (2*(a*A - b*B)*ArcTan[(c + (a - b)*Tan[x/2])/Sqrt[a^2 - b^2 - c^2]])/(a^2 - b^2 - c^2)^(3/2) + (B*c + A*c*Cos[x] - (A*b - a*B)*Sin[x])/((a^2 - b^2 - c^2)*(a + b*Cos[x] + c*Sin[x]))}
{(A + B*Cos[x])/(a + b*Cos[x] + c*Sin[x])^3, x, 3, ((2*a^2*A + b*(A*b - 3*a*B) + A*c^2)*ArcTan[(c + (a - b)*Tan[x/2])/Sqrt[a^2 - b^2 - c^2]])/(a^2 - b^2 - c^2)^(5/2) + (B*c + A*c*Cos[x] - (A*b - a*B)*Sin[x])/(2*(a^2 - b^2 - c^2)*(a + b*Cos[x] + c*Sin[x])^2) + (a*B*c + (3*a*A - 2*b*B)*c*Cos[x] + (2*b^2*B - a*(3*A*b - a*B))*Sin[x])/(2*(a^2 - b^2 - c^2)^2*(a + b*Cos[x] + c*Sin[x]))}


(* ::Subsection::Closed:: *)
(*Miscellaneous rational functions of three trig functions*)


(* Integrands of the form Trig[x]^n/(a*Trig[x]^n+b*Trig[x]^n) *)
{Sin[x]^2/(a*Cos[x]^2 + b*Sin[x]^2), x, 2, -(x/(a - b)) - (Sqrt[a]*ArcTan[(Sqrt[a]*Cot[x])/Sqrt[b]])/((a - b)*Sqrt[b])}
{Cos[x]^2/(a*Cos[x]^2 + b*Sin[x]^2), x, 2, x/(a - b) - (Sqrt[b]*ArcTan[(Sqrt[b]*Tan[x])/Sqrt[a]])/(Sqrt[a]*(a - b))}

{Sin[x]^3/(Cos[x]^3 + Sin[x]^3), x, 9, x/2 - (1/6)*Log[Cos[x] + Sin[x]] + (1/3)*Log[1 - Cos[x]*Sin[x]], (-(1/6))*Log[1 + Cot[x]] - (1/4)*Log[Csc[x]^2] + (1/3)*Log[-Cot[x] + Csc[x]^2] - (1/2)*Pi*Mods[1/2 - x/Pi]}
{Cos[x]^3/(Cos[x]^3 + Sin[x]^3), x, 9, x/2 + (1/6)*Log[Cos[x] + Sin[x]] - (1/3)*Log[1 - Cos[x]*Sin[x]], (1/4)*Log[Sec[x]^2] - (1/3)*Log[Sec[x]^2 - Tan[x]] + (1/6)*Log[1 + Tan[x]] + (1/2)*Pi*Mods[x/Pi]}


(* Integrands of the form Sin[x]^m/(a+b*Sin[x]*c*Sin[x]^2) where m is an integer *)
{1/(a + b*Sin[x] + c*Sin[x]^2), x, 3, (4*c*ArcTan[(2*c + (b - Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]])/(Sqrt[b^2 - 4*a*c]*Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]) - (4*c*ArcTan[(2*c + (b + Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]])/(Sqrt[b^2 - 4*a*c]*Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2])}
{Sin[x]/(a + b*Sin[x] + c*Sin[x]^2), x, 3, (2*(1 - b/Sqrt[b^2 - 4*a*c])*ArcTan[(2*c + (b - Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]])/Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2] + (2*(1 + b/Sqrt[b^2 - 4*a*c])*ArcTan[(2*c + (b + Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]])/Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]}
{Sin[x]^2/(a + b*Sin[x] + c*Sin[x]^2), x, 5, x/c - (2*(b - (b^2 - 2*a*c)/Sqrt[b^2 - 4*a*c])*ArcTan[(2*c + (b - Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]])/(c*Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]) - (2*(b + (b^2 - 2*a*c)/Sqrt[b^2 - 4*a*c])*ArcTan[(2*c + (b + Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]])/(c*Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2])}
{Sin[x]^3/(a + b*Sin[x] + c*Sin[x]^2), x, 6, -((b*x)/c^2) + (2*(b^2 - a*c - (b*(b^2 - 3*a*c))/Sqrt[b^2 - 4*a*c])*ArcTan[(2*c + (b - Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]])/(c^2*Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]) + (2*(b^2 - a*c + (b*(b^2 - 3*a*c))/Sqrt[b^2 - 4*a*c])*ArcTan[(2*c + (b + Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]])/(c^2*Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]) - Cos[x]/c}

{(a + b*Sin[x])/(b^2 + 2*a*b*Sin[x] + a^2*Sin[x]^2), x, 3, -(Cos[x]/(b + a*Sin[x]))}
{(d + e*Sin[x])/(a + b*Sin[x] + c*Sin[x]^2), x, 3, (2*(e + (2*c*d - b*e)/Sqrt[b^2 - 4*a*c])*ArcTan[(2*c + (b - Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]])/Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2] + (2*(e - (2*c*d - b*e)/Sqrt[b^2 - 4*a*c])*ArcTan[(2*c + (b + Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]])/Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]}


(* Integrands of the form Cos[x]^m/(a+b*Cos[x]*c*Cos[x]^2) where m is an integer *)
{1/(a + b*Cos[x] + c*Cos[x]^2), x, 3, (4*c*ArcTan[((b - 2*c - Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]])/(Sqrt[b^2 - 4*a*c]*Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]) - (4*c*ArcTan[((b - 2*c + Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]])/(Sqrt[b^2 - 4*a*c]*Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2])}
{Cos[x]/(a + b*Cos[x] + c*Cos[x]^2), x, 3, (2*(1 - b/Sqrt[b^2 - 4*a*c])*ArcTan[((b - 2*c - Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]])/Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2] + (2*(1 + b/Sqrt[b^2 - 4*a*c])*ArcTan[((b - 2*c + Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]])/Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]}
{Cos[x]^2/(a + b*Cos[x] + c*Cos[x]^2), x, 5, x/c - (2*(b - (b^2 - 2*a*c)/Sqrt[b^2 - 4*a*c])*ArcTan[((b - 2*c - Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]])/(c*Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]) - (2*(b + (b^2 - 2*a*c)/Sqrt[b^2 - 4*a*c])*ArcTan[((b - 2*c + Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]])/(c*Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2])}
{Cos[x]^3/(a + b*Cos[x] + c*Cos[x]^2), x, 6, -((b*x)/c^2) + (2*(b^2 - a*c - (b*(b^2 - 3*a*c))/Sqrt[b^2 - 4*a*c])*ArcTan[((b - 2*c - Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]])/(c^2*Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]) + (2*(b^2 - a*c + (b*(b^2 - 3*a*c))/Sqrt[b^2 - 4*a*c])*ArcTan[((b - 2*c + Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]])/(c^2*Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]) + Sin[x]/c}

{(a + b*Cos[x])/(b^2 + 2*a*b*Cos[x] + a^2*Cos[x]^2), x, 3, Sin[x]/(b + a*Cos[x])}
{(d + e*Cos[x])/(a + b*Cos[x] + c*Cos[x]^2), x, 3, (2*(e + (2*c*d - b*e)/Sqrt[b^2 - 4*a*c])*ArcTan[((b - 2*c - Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]])/Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2] + (2*(e - (2*c*d - b*e)/Sqrt[b^2 - 4*a*c])*ArcTan[((b - 2*c + Sqrt[b^2 - 4*a*c])*Tan[x/2])/Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]])/Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]}


{Sin[x]/(-2 + Cos[x] + Cos[x]^2), x, 2, (2/3)*ArcTanh[1/3 + (2*Cos[x])/3]}
{Sin[x]/(4 - 5*Cos[x] + Cos[x]^2), x, 2, (-(2/3))*ArcTanh[5/3 - (2*Cos[x])/3]}
{Sin[x]/(3 - 2*Cos[x] + Cos[x]^2), x, 2, ArcTan[(1 - Cos[x])/Sqrt[2]]/Sqrt[2]}
{Sin[x]/(13 - 4*Cos[x] + Cos[x]^2)^2, x, 3, (1/54)*ArcTan[2/3 - Cos[x]/3] + (2 - Cos[x])/(18*(13 - 4*Cos[x] + Cos[x]^2))}

{Cos[x]/(-6 + Sin[x] + Sin[x]^2), x, 2, (-(2/5))*ArcTanh[1/5 + (2*Sin[x])/5]}
{Cos[x]/(2 - 3*Sin[x] + Sin[x]^2), x, 2, 2*ArcTanh[3 - 2*Sin[x]]}
{Cos[x]/(-5 + 4*Sin[x] + Sin[x]^2), x, 2, (-(1/3))*ArcTanh[2/3 + Sin[x]/3]}
{Cos[x]/(10 - 6*Sin[x] + Sin[x]^2), x, 2, -ArcTan[3 - Sin[x]]}
{Cos[x]/(2 + 2*Sin[x] + Sin[x]^2), x, 2, ArcTan[1 + Sin[x]]}

{Sec[x]/(-5 + Cos[x]^2 + 4*Sin[x]), x, 7, (-(4/9))*Log[2 - Sin[x]] + (1/2)*Log[1 - Sin[x]] - (1/18)*Log[1 + Sin[x]] + 1/(3*(2 - Sin[x]))}


{(x*Cos[x] - Sin[x])/(x - Sin[x])^2, x, -7, x/(x - Sin[x])}
(* Nonidempotent expansion results in infinite recursion: *) 
(* {x/(x - Cos[x])^2, x, 1, Int[x/(x - Cos[x])^2, x]} *)
(* {Cos[x]/(x - Cos[x])^2, x, 1, Int[Cos[x]/(x - Cos[x])^2, x]} *)
(* {(Cos[x] + x*Sin[x])/(x - Cos[x])^2, x, 0, -x/(x - Cos[x])} *)


(* ::Subsection::Closed:: *)
(*Miscellaneous algebraic functions of three trig functions*)


{Tan[x]^5/Sqrt[a + b*Tan[x]^2 + c*Tan[x]^4], x, 8, -(ArcTanh[(2*a - b + (b - 2*c)*Tan[x]^2)/(2*Sqrt[a - b + c]*Sqrt[a + b*Tan[x]^2 + c*Tan[x]^4])]/(2*Sqrt[a - b + c])) - (b*ArcTanh[(b + 2*c*Tan[x]^2)/(2*Sqrt[c]*Sqrt[a + b*Tan[x]^2 + c*Tan[x]^4])])/(4*c^(3/2)) - ArcTanh[(b + 2*c*Tan[x]^2)/(2*Sqrt[c]*Sqrt[a + b*Tan[x]^2 + c*Tan[x]^4])]/(2*Sqrt[c]) + Sqrt[a + b*Tan[x]^2 + c*Tan[x]^4]/(2*c)}
{Tan[x]^3/Sqrt[a + b*Tan[x]^2 + c*Tan[x]^4], x, 6, ArcTanh[(2*a - b + (b - 2*c)*Tan[x]^2)/(2*Sqrt[a - b + c]*Sqrt[a + b*Tan[x]^2 + c*Tan[x]^4])]/(2*Sqrt[a - b + c]) + ArcTanh[(b + 2*c*Tan[x]^2)/(2*Sqrt[c]*Sqrt[a + b*Tan[x]^2 + c*Tan[x]^4])]/(2*Sqrt[c])}
{Tan[x]/Sqrt[a + b*Tan[x]^2 + c*Tan[x]^4], x, 3, -(ArcTanh[(2*a - b + (b - 2*c)*Tan[x]^2)/(2*Sqrt[a - b + c]*Sqrt[a + b*Tan[x]^2 + c*Tan[x]^4])]/(2*Sqrt[a - b + c]))}
{Cot[x]/Sqrt[a + b*Tan[x]^2 + c*Tan[x]^4], x, 6, -(ArcTanh[(2*a + b*Tan[x]^2)/(2*Sqrt[a]*Sqrt[a + b*Tan[x]^2 + c*Tan[x]^4])]/(2*Sqrt[a])) + ArcTanh[(2*a - b + (b - 2*c)*Tan[x]^2)/(2*Sqrt[a - b + c]*Sqrt[a + b*Tan[x]^2 + c*Tan[x]^4])]/(2*Sqrt[a - b + c])}
{Cot[x]^3/Sqrt[a + b*Tan[x]^2 + c*Tan[x]^4], x, 8, ArcTanh[(2*a + b*Tan[x]^2)/(2*Sqrt[a]*Sqrt[a + b*Tan[x]^2 + c*Tan[x]^4])]/(2*Sqrt[a]) + (b*ArcTanh[(2*a + b*Tan[x]^2)/(2*Sqrt[a]*Sqrt[a + b*Tan[x]^2 + c*Tan[x]^4])])/(4*a^(3/2)) - ArcTanh[(2*a - b + (b - 2*c)*Tan[x]^2)/(2*Sqrt[a - b + c]*Sqrt[a + b*Tan[x]^2 + c*Tan[x]^4])]/(2*Sqrt[a - b + c]) - (Cot[x]^2*Sqrt[a + b*Tan[x]^2 + c*Tan[x]^4])/(2*a)}


{Cot[x]^5/Sqrt[a + b*Cot[x]^2 + c*Cot[x]^4], x, 8, ArcTanh[(2*a - b + (b - 2*c)*Cot[x]^2)/(2*Sqrt[a - b + c]*Sqrt[a + b*Cot[x]^2 + c*Cot[x]^4])]/(2*Sqrt[a - b + c]) + (b*ArcTanh[(b + 2*c*Cot[x]^2)/(2*Sqrt[c]*Sqrt[a + b*Cot[x]^2 + c*Cot[x]^4])])/(4*c^(3/2)) + ArcTanh[(b + 2*c*Cot[x]^2)/(2*Sqrt[c]*Sqrt[a + b*Cot[x]^2 + c*Cot[x]^4])]/(2*Sqrt[c]) - Sqrt[a + b*Cot[x]^2 + c*Cot[x]^4]/(2*c)}
{Cot[x]^3/Sqrt[a + b*Cot[x]^2 + c*Cot[x]^4], x, 6, -(ArcTanh[(2*a - b + (b - 2*c)*Cot[x]^2)/(2*Sqrt[a - b + c]*Sqrt[a + b*Cot[x]^2 + c*Cot[x]^4])]/(2*Sqrt[a - b + c])) - ArcTanh[(b + 2*c*Cot[x]^2)/(2*Sqrt[c]*Sqrt[a + b*Cot[x]^2 + c*Cot[x]^4])]/(2*Sqrt[c])}
{Cot[x]/Sqrt[a + b*Cot[x]^2 + c*Cot[x]^4], x, 3, ArcTanh[(2*a - b + (b - 2*c)*Cot[x]^2)/(2*Sqrt[a - b + c]*Sqrt[a + b*Cot[x]^2 + c*Cot[x]^4])]/(2*Sqrt[a - b + c])}
{Tan[x]/Sqrt[a + b*Cot[x]^2 + c*Cot[x]^4], x, 6, ArcTanh[(2*a + b*Cot[x]^2)/(2*Sqrt[a]*Sqrt[a + b*Cot[x]^2 + c*Cot[x]^4])]/(2*Sqrt[a]) - ArcTanh[(2*a - b + (b - 2*c)*Cot[x]^2)/(2*Sqrt[a - b + c]*Sqrt[a + b*Cot[x]^2 + c*Cot[x]^4])]/(2*Sqrt[a - b + c])}
{Tan[x]^3/Sqrt[a + b*Cot[x]^2 + c*Cot[x]^4], x, 8, -(ArcTanh[(2*a + b*Cot[x]^2)/(2*Sqrt[a]*Sqrt[a + b*Cot[x]^2 + c*Cot[x]^4])]/(2*Sqrt[a])) - (b*ArcTanh[(2*a + b*Cot[x]^2)/(2*Sqrt[a]*Sqrt[a + b*Cot[x]^2 + c*Cot[x]^4])])/(4*a^(3/2)) + ArcTanh[(2*a - b + (b - 2*c)*Cot[x]^2)/(2*Sqrt[a - b + c]*Sqrt[a + b*Cot[x]^2 + c*Cot[x]^4])]/(2*Sqrt[a - b + c]) + (Sqrt[a + b*Cot[x]^2 + c*Cot[x]^4]*Tan[x]^2)/(2*a)}


(* {Tan[x]^5*Sqrt[a + b*Tan[x]^2 + c*Tan[x]^4], x, 0, 0} *)
(* {Tan[x]^3*Sqrt[a + b*Tan[x]^2 + c*Tan[x]^4], x, 0, 0} *)
{Tan[x]*Sqrt[a + b*Tan[x]^2 + c*Tan[x]^4], x, 5, (-(1/2))*Sqrt[a - b + c]*ArcTanh[(2*a - b + (b - 2*c)*Tan[x]^2)/(2*Sqrt[a - b + c]*Sqrt[a + b*Tan[x]^2 + c*Tan[x]^4])] + ((b - 2*c)*ArcTanh[(b + 2*c*Tan[x]^2)/(2*Sqrt[c]*Sqrt[a + b*Tan[x]^2 + c*Tan[x]^4])])/(4*Sqrt[c]) + (1/2)*Sqrt[a + b*Tan[x]^2 + c*Tan[x]^4]}
(* {Cot[x]*Sqrt[a + b*Tan[x]^2 + c*Tan[x]^4], x, 0, 0} *)
(* {Cot[x]^3*Sqrt[a + b*Tan[x]^2 + c*Tan[x]^4], x, 0, 0} *)


(* {Cot[x]^5*Sqrt[a + b*Cot[x]^2 + c*Cot[x]^4], x, 0, 0} *)
(* {Cot[x]^3*Sqrt[a + b*Cot[x]^2 + c*Cot[x]^4], x, 0, 0} *)
{Cot[x]*Sqrt[a + b*Cot[x]^2 + c*Cot[x]^4], x, 5, (1/2)*Sqrt[a - b + c]*ArcTanh[(2*a - b + (b - 2*c)*Cot[x]^2)/(2*Sqrt[a - b + c]*Sqrt[a + b*Cot[x]^2 + c*Cot[x]^4])] - ((b - 2*c)*ArcTanh[(b + 2*c*Cot[x]^2)/(2*Sqrt[c]*Sqrt[a + b*Cot[x]^2 + c*Cot[x]^4])])/(4*Sqrt[c]) - (1/2)*Sqrt[a + b*Cot[x]^2 + c*Cot[x]^4]}
(* {Tan[x]*Sqrt[a + b*Cot[x]^2 + c*Cot[x]^4], x, 0, 0} *)
(* {Tan[x]^3*Sqrt[a + b*Cot[x]^2 + c*Cot[x]^4], x, 0, 0} *)


{1/(Cos[x]^(3/2)*Sqrt[3*Cos[x] + Sin[x]]), x, -6, (2*Sqrt[3*Cos[x] + Sin[x]])/Sqrt[Cos[x]]}
{(Csc[x]*Sqrt[Cos[x] + Sin[x]])/Cos[x]^(3/2), x, -6, -Log[Sin[x]] + 2*Log[-Sqrt[Cos[x]] + Sqrt[Cos[x] + Sin[x]]] + (2*Sqrt[Cos[x] + Sin[x]])/Sqrt[Cos[x]]}
{(Cos[x] + Sin[x])/Sqrt[1 + Sin[2*x]], x, 20, (x*Sqrt[1 + Sin[2*x]])/(Cos[x] + Sin[x])}
{Sec[x]*Sqrt[Sec[x] + Tan[x]], x, 4, 2*Sqrt[(1 + Tan[x/2])/(1 - Tan[x/2])]}

{Sec[x]*Sqrt[4 + 3*Sec[x]]*Tan[x], x, 3, (2*(4 + 3*Sec[x])^(3/2))/9}
{Sec[x]*Sqrt[1 + Sec[x]]*Tan[x]^3, x, 4, (-(4/5))*(1 + Sec[x])^(5/2) + (2/7)*(1 + Sec[x])^(7/2)}
{Csc[x]*Sqrt[1 + Csc[x]]*Cot[x]^3, x, 4, (4/5)*(1 + Csc[x])^(5/2) - (2/7)*(1 + Csc[x])^(7/2)}

{Sqrt[Csc[x]]*(x*Cos[x] - 4*Sec[x]*Tan[x]), x, 8, (2*x)/Sqrt[Csc[x]] - (4*Sec[x])/Csc[x]^(3/2)}


{Cot[x]*Sqrt[-1 + Csc[x]^2]*(1 - Sin[x]^2)^3, x, 7, (-(35/16))*Sqrt[Cot[x]^2] + (35/48)*Cos[x]^2*Sqrt[Cot[x]^2] + (7/24)*Cos[x]^4*Sqrt[Cot[x]^2] + (1/6)*Cos[x]^6*Sqrt[Cot[x]^2] - (35/16)*x*Sqrt[Cot[x]^2]*Tan[x]}
{Cos[x]*Sqrt[-1 + Csc[x]^2]*(1 - Sin[x]^2)^3, x, 8, Sqrt[Cot[x]^2]*Sin[x] + (1/3)*Cos[x]^2*Sqrt[Cot[x]^2]*Sin[x] + (1/5)*Cos[x]^4*Sqrt[Cot[x]^2]*Sin[x] + (1/7)*Cos[x]^6*Sqrt[Cot[x]^2]*Sin[x] - ArcTanh[Cos[x]]*Sqrt[Cot[x]^2]*Tan[x]}


{(x^1*Csc[x]*Sec[x])/Sqrt[a*Sec[x]^2], x, 5, -(((2*x*ArcTanh[E^(I*x)] - I*PolyLog[2, -E^(I*x)] + I*PolyLog[2, E^(I*x)])*Sec[x])/Sqrt[a*Sec[x]^2])}
{(x^2*Csc[x]*Sec[x])/Sqrt[a*Sec[x]^2], x, 7, -((2*(x^2*ArcTanh[E^(I*x)] - I*x*PolyLog[2, -E^(I*x)] + I*x*PolyLog[2, E^(I*x)] + PolyLog[3, -E^(I*x)] - PolyLog[3, E^(I*x)])*Sec[x])/Sqrt[a*Sec[x]^2])}
{(x^3*Csc[x]*Sec[x])/Sqrt[a*Sec[x]^2], x, 9, -(((2*x^3*ArcTanh[E^(I*x)] - 3*I*x^2*PolyLog[2, -E^(I*x)] + 3*I*x^2*PolyLog[2, E^(I*x)] + 6*x*PolyLog[3, -E^(I*x)] - 6*x*PolyLog[3, E^(I*x)] + 6*I*PolyLog[4, -E^(I*x)] - 6*I*PolyLog[4, E^(I*x)])*Sec[x])/Sqrt[a*Sec[x]^2])}


{(x^1*Csc[x]*Sec[x])/Sqrt[a*Sec[x]^4], x, 5, -(((I*x^2 - 2*x*Log[1 - E^(2*I*x)] + I*PolyLog[2, E^(2*I*x)])*Sec[x]^2)/(2*Sqrt[a*Sec[x]^4]))}
{(x^2*Csc[x]*Sec[x])/Sqrt[a*Sec[x]^4], x, 6, -(((2*I*x^3 - 6*x^2*Log[1 - E^(2*I*x)] + 6*I*x*PolyLog[2, E^(2*I*x)] - 3*PolyLog[3, E^(2*I*x)])*Sec[x]^2)/(6*Sqrt[a*Sec[x]^4]))}
{(x^3*Csc[x]*Sec[x])/Sqrt[a*Sec[x]^4], x, 7, -(((I*x^4 - 4*x^3*Log[1 - E^(2*I*x)] + 6*I*x^2*PolyLog[2, E^(2*I*x)] - 6*x*PolyLog[3, E^(2*I*x)] - 3*I*PolyLog[4, E^(2*I*x)])*Sec[x]^2)/(4*Sqrt[a*Sec[x]^4]))}


{(x^1*Csc[x]*Sec[x])*Sqrt[a*Sec[x]^2], x, 10, (-Cos[x])*Sqrt[a*Sec[x]^2]*(2*x*ArcTanh[E^(I*x)] + ArcTanh[Sin[x]] - I*PolyLog[2, -E^(I*x)] + I*PolyLog[2, E^(I*x)] - x*Sec[x])}
{(x^2*Csc[x]*Sec[x])*Sqrt[a*Sec[x]^2], x, 16, Cos[x]*Sqrt[a*Sec[x]^2]*(4*I*x*ArcTan[E^(I*x)] - 2*x^2*ArcTanh[E^(I*x)] + 2*I*x*PolyLog[2, -E^(I*x)] - 2*I*PolyLog[2, (-I)*E^(I*x)] + 2*I*PolyLog[2, I*E^(I*x)] - 2*I*x*PolyLog[2, E^(I*x)] - 2*PolyLog[3, -E^(I*x)] + 2*PolyLog[3, E^(I*x)] + x^2*Sec[x])}
{(x^3*Csc[x]*Sec[x])*Sqrt[a*Sec[x]^2], x, 20, Cos[x]*Sqrt[a*Sec[x]^2]*(6*I*x^2*ArcTan[E^(I*x)] - 2*x^3*ArcTanh[E^(I*x)] + 3*I*x^2*PolyLog[2, -E^(I*x)] - 6*I*x*PolyLog[2, (-I)*E^(I*x)] + 6*I*x*PolyLog[2, I*E^(I*x)] - 3*I*x^2*PolyLog[2, E^(I*x)] - 6*x*PolyLog[3, -E^(I*x)] + 6*PolyLog[3, (-I)*E^(I*x)] - 6*PolyLog[3, I*E^(I*x)] + 6*x*PolyLog[3, E^(I*x)] - 6*I*PolyLog[4, -E^(I*x)] + 6*I*PolyLog[4, E^(I*x)] + x^3*Sec[x])}


{(x^1*Csc[x]*Sec[x])*Sqrt[a*Sec[x]^4], x, 10, (-(1/2))*Cos[x]^2*Sqrt[a*Sec[x]^4]*(4*x*ArcTanh[E^(2*I*x)] - I*PolyLog[2, -E^(2*I*x)] + I*PolyLog[2, E^(2*I*x)] - x*Sec[x]^2 + Tan[x])}
{(x^2*Csc[x]*Sec[x])*Sqrt[a*Sec[x]^4], x, 15, (-(1/2))*Cos[x]^2*Sqrt[a*Sec[x]^4]*(4*x^2*ArcTanh[E^(2*I*x)] + 2*Log[Cos[x]] - 2*I*x*PolyLog[2, -E^(2*I*x)] + 2*I*x*PolyLog[2, E^(2*I*x)] + PolyLog[3, -E^(2*I*x)] - PolyLog[3, E^(2*I*x)] - x^2*Sec[x]^2 + 2*x*Tan[x])}
{(x^3*Csc[x]*Sec[x])*Sqrt[a*Sec[x]^4], x, 20, (1/4)*Cos[x]^2*Sqrt[a*Sec[x]^4]*(6*I*x^2 - 8*x^3*ArcTanh[E^(2*I*x)] - 12*x*Log[1 + E^(2*I*x)] + 6*I*(1 + x^2)*PolyLog[2, -E^(2*I*x)] - 6*I*x^2*PolyLog[2, E^(2*I*x)] - 6*x*PolyLog[3, -E^(2*I*x)] + 6*x*PolyLog[3, E^(2*I*x)] - 3*I*PolyLog[4, -E^(2*I*x)] + 3*I*PolyLog[4, E^(2*I*x)] + 2*x^3*Sec[x]^2 - 6*x^2*Tan[x])}


(* ::Section::Closed:: *)
(*Integrands involving four trig functions*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Trig[x]^m Trig[x]^n (a Trig[x] + b Trig[x])^n*)


(* Integrands of the form Cos[x]^m*Sin[x]^n/(a*Cos[x]+b*Sin[x]) where m and n are integers *)
{Cos[x]*Sin[x]/(a*Cos[x] + b*Sin[x]), x, 4, (2*a*b*ArcTanh[(b - a*Tan[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(3/2) - (a*Cos[x])/(a^2 + b^2) + (b*Sin[x])/(a^2 + b^2)}
{Cos[x]*Sin[x]^2/(a*Cos[x] + b*Sin[x]), x, 5, -((a*b^2*x)/(a^2 + b^2)^2) + (a*x)/(2*(a^2 + b^2)) + (a^2*b*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^2 - (a*Cos[x]*Sin[x])/(2*(a^2 + b^2)) + (b*Sin[x]^2)/(2*(a^2 + b^2))}
{Cos[x]*Sin[x]^3/(a*Cos[x] + b*Sin[x]), x, 9, (2*a^3*b*ArcTanh[(b - a*Tan[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2) + (a*b^2*Cos[x])/(a^2 + b^2)^2 - (a*Cos[x])/(a^2 + b^2) + (a*Cos[x]^3)/(3*(a^2 + b^2)) + (a^2*b*Sin[x])/(a^2 + b^2)^2 + (b*Sin[x]^3)/(3*(a^2 + b^2))}

{Cos[x]^2*Sin[x]/(a*Cos[x] + b*Sin[x]), x, 5, -((a^2*b*x)/(a^2 + b^2)^2) + (b*x)/(2*(a^2 + b^2)) - (a*b^2*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^2 + (b*Cos[x]*Sin[x])/(2*(a^2 + b^2)) + (a*Sin[x]^2)/(2*(a^2 + b^2))}
{Cos[x]^2*Sin[x]^2/(a*Cos[x] + b*Sin[x]), x, 9, -((2*a^2*b^2*ArcTanh[(b - a*Tan[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2)) + (a^2*b*Cos[x])/(a^2 + b^2)^2 - (b*Cos[x]^3)/(3*(a^2 + b^2)) - (a*b^2*Sin[x])/(a^2 + b^2)^2 + (a*Sin[x]^3)/(3*(a^2 + b^2))}
{Cos[x]^2*Sin[x]^3/(a*Cos[x] + b*Sin[x]), x, 10, (a^2*b^3*x)/(a^2 + b^2)^3 - (a^2*b*x)/(2*(a^2 + b^2)^2) + (b*x)/(8*(a^2 + b^2)) - (a^3*b^2*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^3 + (a^2*b*Cos[x]*Sin[x])/(2*(a^2 + b^2)^2) + (b*Cos[x]*Sin[x])/(8*(a^2 + b^2)) - (b*Cos[x]^3*Sin[x])/(4*(a^2 + b^2)) - (a*b^2*Sin[x]^2)/(2*(a^2 + b^2)^2) + (a*Sin[x]^4)/(4*(a^2 + b^2))}

{Cos[x]^3*Sin[x]/(a*Cos[x] + b*Sin[x]), x, 9, (2*a*b^3*ArcTanh[(b - a*Tan[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2) - (a*b^2*Cos[x])/(a^2 + b^2)^2 - (a*Cos[x]^3)/(3*(a^2 + b^2)) - (a^2*b*Sin[x])/(a^2 + b^2)^2 + (b*Sin[x])/(a^2 + b^2) - (b*Sin[x]^3)/(3*(a^2 + b^2))}
{Cos[x]^3*Sin[x]^2/(a*Cos[x] + b*Sin[x]), x, 10, (a^3*b^2*x)/(a^2 + b^2)^3 - (a*b^2*x)/(2*(a^2 + b^2)^2) + (a*x)/(8*(a^2 + b^2)) - (b*Cos[x]^4)/(4*(a^2 + b^2)) + (a^2*b^3*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^3 - (a*b^2*Cos[x]*Sin[x])/(2*(a^2 + b^2)^2) + (a*Cos[x]*Sin[x])/(8*(a^2 + b^2)) - (a*Cos[x]^3*Sin[x])/(4*(a^2 + b^2)) - (a^2*b*Sin[x]^2)/(2*(a^2 + b^2)^2)}
{Cos[x]^3*Sin[x]^3/(a*Cos[x] + b*Sin[x]), x, 16, (2*a^3*b^3*ArcTanh[(b - a*Tan[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(7/2) - (a^3*b^2*Cos[x])/(a^2 + b^2)^3 + (a*b^2*Cos[x]^3)/(3*(a^2 + b^2)^2) - (a*Cos[x]^3)/(3*(a^2 + b^2)) + (a*Cos[x]^5)/(5*(a^2 + b^2)) + (a^2*b^3*Sin[x])/(a^2 + b^2)^3 - (a^2*b*Sin[x]^3)/(3*(a^2 + b^2)^2) + (b*Sin[x]^3)/(3*(a^2 + b^2)) - (b*Sin[x]^5)/(5*(a^2 + b^2))}


(* Integrands of the form Cos[x]^m*Sin[x]^n/(a*Cos[x]+b*Sin[x])^2 where m and n are integers *)
(* {Cos[x]*Sin[x]/(a*Cos[x] + b*Sin[x])^2, x, 0, (2*a*b*x)/(a^2 + b^2)^2 - ((a^2 - b^2)*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^2 - (b*Sin[x])/((a^2 + b^2)*(a*Cos[x] + b*Sin[x]))}
{Cos[x]*Sin[x]^2/(a*Cos[x] + b*Sin[x])^2, x, 0, -((a*(a^2 - 2*b^2)*ArcTanh[(b*Cos[x] - a*Sin[x])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2)) - (2*a*b*Cos[x])/(a^2 + b^2)^2 - ((a^2 - b^2)*Sin[x])/(a^2 + b^2)^2 - (a^2*b)/((a^2 + b^2)^2*(a*Cos[x] + b*Sin[x]))}
{Cos[x]*Sin[x]^3/(a*Cos[x] + b*Sin[x])^2, x, 0, (b*(3*a^3 - a*b^2)*x)/(a^2 + b^2)^3 - (a^2*b)/((a^2 + b^2)^2*(b + a*Cot[x])) + (2*a^2*b^2*Log[b + a*Cot[x]])/(a^2 + b^2)^3 + (2*a^2*b^2*Log[Sin[x]])/(a^2 + b^2)^3 - (a^2*(a^2 - b^2)*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^3 - (a*b*Cos[x]*Sin[x])/(a^2 + b^2)^2 + ((-a^2 + b^2)*Sin[x]^2)/(2*(a^2 + b^2)^2)}

{Cos[x]^2*Sin[x]/(a*Cos[x] + b*Sin[x])^2, x, 0, -((b*(-2*a^2 + b^2)*ArcTanh[(b*Cos[x] - a*Sin[x])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2)) - ((a^2 - b^2)*Cos[x])/(a^2 + b^2)^2 + (2*a*b*Sin[x])/(a^2 + b^2)^2 + (a*b^2)/((a^2 + b^2)^2*(a*Cos[x] + b*Sin[x]))}
{Cos[x]^2*Sin[x]^2/(a*Cos[x] + b*Sin[x])^2, x, 0, ((a^4 - 6*a^2*b^2 + b^4)*x)/(2*(a^2 + b^2)^3) + (2*a*b*(a^2 - b^2)*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^3 + ((-a^2 + b^2)*Cos[x]*Sin[x])/(2*(a^2 + b^2)^2) + (a*b*Sin[x]^2)/(a^2 + b^2)^2 + (a*b^2*Sin[x])/((a^2 + b^2)^2*(a*Cos[x] + b*Sin[x]))}
{Cos[x]^2*Sin[x]^3/(a*Cos[x] + b*Sin[x])^2, x, 0, (a^2*b*(2*a^2 - 3*b^2)*ArcTanh[(b*Cos[x] - a*Sin[x])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(7/2) - (a^2*(a^2 - 3*b^2)*Cos[x])/(a^2 + b^2)^3 + ((a^2 - b^2)*Cos[x]^3)/(3*(a^2 + b^2)^2) + (2*a*b*(a^2 - b^2)*Sin[x])/(a^2 + b^2)^3 + (2*a*b*Sin[x]^3)/(3*(a^2 + b^2)^2) + (a^3*b^2)/((a^2 + b^2)^3*(a*Cos[x] + b*Sin[x]))}

{Cos[x]^3*Sin[x]/(a*Cos[x] + b*Sin[x])^2, x, 0, (2*a*b^3*x)/(a^2 + b^2)^3 - (a*b*(a^2 - b^2)*ArcTan[Tan[x]])/(a^2 + b^2)^3 - (2*a^2*b^2*Log[Cos[x]])/(a^2 + b^2)^3 - (b^2*(a^2 - b^2)*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^3 - (2*a^2*b^2*Log[a + b*Tan[x]])/(a^2 + b^2)^3 + (a*b*Cos[x]*Sin[x])/(a^2 + b^2)^2 + ((a^2 - b^2)*Sin[x]^2)/(2*(a^2 + b^2)^2) + (a*b^2)/((a^2 + b^2)^2*(a + b*Tan[x]))}
{Cos[x]^3*Sin[x]^2/(a*Cos[x] + b*Sin[x])^2, x, 0, -((a*b^2*(3*a^2 - 2*b^2)*ArcTanh[(b*Cos[x] - a*Sin[x])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(7/2)) + (2*a*b*(a^2 - b^2)*Cos[x])/(a^2 + b^2)^3 - (2*a*b*Cos[x]^3)/(3*(a^2 + b^2)^2) - (b^2*(3*a^2 - b^2)*Sin[x])/(a^2 + b^2)^3 + ((a^2 - b^2)*Sin[x]^3)/(3*(a^2 + b^2)^2) - (a^2*b^3)/((a^2 + b^2)^3*(a*Cos[x] + b*Sin[x]))}
{Cos[x]^3*Sin[x]^3/(a*Cos[x] + b*Sin[x])^2, x, 0, -((3*a*b*(a^4 - 6*a^2*b^2 + b^4)*x)/(4*(a^2 + b^2)^4)) - (b^2*Cos[x]^4)/(4*(a^2 + b^2)^2) - (3*a^2*b^2*(a^2 - b^2)*Log[a*Cos[x] + b*Sin[x]])/(a^2 + b^2)^4 + (a*b*(5*a^2 - 3*b^2)*Cos[x]*Sin[x])/(4*(a^2 + b^2)^3) - (a*b*Cos[x]^3*Sin[x])/(2*(a^2 + b^2)^2) - (2*a^2*b^2*Sin[x]^2)/(a^2 + b^2)^3 + (a^2*Sin[x]^4)/(4*(a^2 + b^2)^2) - (a^2*b^3*Sin[x])/((a^2 + b^2)^3*(a*Cos[x] + b*Sin[x]))} *)


(* ::Subsection::Closed:: *)
(*Integrands of the form (A + B Trig[x] + C Trig[x]) (b Trig[x] + c Trig[x])^n*)


(* Integrands of the form (B*Cos[x]+C*Sin[x])*(b*Cos[x]+c*Sin[x])^n *)
{(B*Cos[x] + C*Sin[x])/(b*Cos[x] + c*Sin[x]), x, 1, ((b*B + c*C)*x)/(b^2 + c^2) + ((B*c - b*C)*Log[b*Cos[x] + c*Sin[x]])/(b^2 + c^2)}
{(B*Cos[x] + C*Sin[x])/(b*Cos[x] + c*Sin[x])^2, x, 2, -((2*(b*B + c*C)*ArcTanh[(c - b*Tan[x/2])/Sqrt[b^2 + c^2]])/(b^2 + c^2)^(3/2)) - (B*c - b*C)/((b^2 + c^2)*(b*Cos[x] + c*Sin[x]))}
{(B*Cos[x] + C*Sin[x])/(b*Cos[x] + c*Sin[x])^3, x, 3, -((B*c - b*C)/(2*(b^2 + c^2)*(b*Cos[x] + c*Sin[x])^2)) + ((b*B + c*C)*Sin[x])/(b*(b^2 + c^2)*(b*Cos[x] + c*Sin[x]))}

{(Cos[x] - Sin[x])/(Cos[x] + Sin[x]), x, 1, Log[Cos[x] + Sin[x]]}
{(Cos[x] - I*Sin[x])/(Cos[x] + I*Sin[x]), x, 2, (1/2)*I*(Cos[x] - I*Sin[x])^2}


(* Integrands of the form (A+B*Cos[x]+C*Sin[x])*(b*Cos[x]+c*Sin[x])^n *)
{(A + B*Cos[x] + C*Sin[x])/(b*Cos[x] + c*Sin[x]), x, 2, ((b*B + c*C)*x)/(b^2 + c^2) - (2*A*ArcTanh[(c - b*Tan[x/2])/Sqrt[b^2 + c^2]])/Sqrt[b^2 + c^2] + ((B*c - b*C)*Log[b*Cos[x] + c*Sin[x]])/(b^2 + c^2)}
{(A + B*Cos[x] + C*Sin[x])/(b*Cos[x] + c*Sin[x])^2, x, 2, -((2*(b*B + c*C)*ArcTanh[(c - b*Tan[x/2])/Sqrt[b^2 + c^2]])/(b^2 + c^2)^(3/2)) - (B*c - b*C + A*c*Cos[x] - A*b*Sin[x])/((b^2 + c^2)*(b*Cos[x] + c*Sin[x]))}
{(A + B*Cos[x] + C*Sin[x])/(b*Cos[x] + c*Sin[x])^3, x, 3, -((A*ArcTanh[(c - b*Tan[x/2])/Sqrt[b^2 + c^2]])/(b^2 + c^2)^(3/2)) - (B*c - b*C + A*c*Cos[x] - A*b*Sin[x])/(2*(b^2 + c^2)*(b*Cos[x] + c*Sin[x])^2) - ((b*B + c*C)*(c*Cos[x] - b*Sin[x]))/((b^2 + c^2)^2*(b*Cos[x] + c*Sin[x]))}


(* ::Subsection::Closed:: *)
(*Integrands of the form (A + B Trig[x] + C Trig[x]) (a + b Trig[x] + c Trig[x])^n*)


(* Integrands of the form (B*Cos[x]+C*Sin[x])*(a+b*Cos[x]+c*Sin[x])^n *)
{(B*Cos[x] + C*Sin[x])/(a + b*Cos[x] + c*Sin[x]), x, 2, ((b*B + c*C)*x)/(b^2 + c^2) - (2*a*(b*B + c*C)*ArcTan[(c + (a - b)*Tan[x/2])/Sqrt[a^2 - b^2 - c^2]])/(Sqrt[a^2 - b^2 - c^2]*(b^2 + c^2)) + ((B*c - b*C)*Log[a + b*Cos[x] + c*Sin[x]])/(b^2 + c^2)}
{(B*Cos[x] + C*Sin[x])/(a + b*Cos[x] + c*Sin[x])^2, x, 2, -((2*(b*B + c*C)*ArcTan[(c + (a - b)*Tan[x/2])/Sqrt[a^2 - b^2 - c^2]])/(a^2 - b^2 - c^2)^(3/2)) + (B*c - b*C - a*C*Cos[x] + a*B*Sin[x])/((a^2 - b^2 - c^2)*(a + b*Cos[x] + c*Sin[x]))}
{(B*Cos[x] + C*Sin[x])/(a + b*Cos[x] + c*Sin[x])^3, x, 3, -((3*a*(b*B + c*C)*ArcTan[(c + (a - b)*Tan[x/2])/Sqrt[a^2 - b^2 - c^2]])/(a^2 - b^2 - c^2)^(5/2)) + (B*c - b*C - a*C*Cos[x] + a*B*Sin[x])/(2*(a^2 - b^2 - c^2)*(a + b*Cos[x] + c*Sin[x])^2) + (a*B*c - a*b*C - (a^2*C + 2*c*(b*B + c*C))*Cos[x] + (a^2*B + 2*b*(b*B + c*C))*Sin[x])/(2*(a^2 - b^2 - c^2)^2*(a + b*Cos[x] + c*Sin[x]))}


(* Integrands of the form (A+B*Cos[x]+C*Sin[x])*(a+b*Cos[x]+c*Sin[x])^n *)
{(A + B*Cos[x] + C*Sin[x])/(a + b*Cos[x] + c*Sin[x]), x, 2, ((b*B + c*C)*x)/(b^2 + c^2) + (2*(A*(b^2 + c^2) - a*(b*B + c*C))*ArcTan[(c + (a - b)*Tan[x/2])/Sqrt[a^2 - b^2 - c^2]])/(Sqrt[a^2 - b^2 - c^2]*(b^2 + c^2)) + ((B*c - b*C)*Log[a + b*Cos[x] + c*Sin[x]])/(b^2 + c^2)}
{(A + B*Cos[x] + C*Sin[x])/(a + b*Cos[x] + c*Sin[x])^2, x, 2, (2*(a*A - b*B - c*C)*ArcTan[(c + (a - b)*Tan[x/2])/Sqrt[a^2 - b^2 - c^2]])/(a^2 - b^2 - c^2)^(3/2) + (B*c - b*C + (A*c - a*C)*Cos[x] - (A*b - a*B)*Sin[x])/((a^2 - b^2 - c^2)*(a + b*Cos[x] + c*Sin[x]))}
{(A + B*Cos[x] + C*Sin[x])/(a + b*Cos[x] + c*Sin[x])^3, x, 3, ((2*a^2*A + b*(A*b - 3*a*B) + c*(A*c - 3*a*C))*ArcTan[(c + (a - b)*Tan[x/2])/Sqrt[a^2 - b^2 - c^2]])/(a^2 - b^2 - c^2)^(5/2) + (B*c - b*C + (A*c - a*C)*Cos[x] - (A*b - a*B)*Sin[x])/(2*(a^2 - b^2 - c^2)*(a + b*Cos[x] + c*Sin[x])^2) + (a*B*c - a*b*C + (a*(3*A*c - a*C) - 2*c*(b*B + c*C))*Cos[x] - (a*(3*A*b - a*B) - 2*b*(b*B + c*C))*Sin[x])/(2*(a^2 - b^2 - c^2)^2*(a + b*Cos[x] + c*Sin[x]))}

{(b^2 + c^2 + a*b*Cos[x] + a*c*Sin[x])/(a + b*Cos[x] + c*Sin[x])^2, x, 1, -((c*Cos[x] - b*Sin[x])/(a + b*Cos[x] + c*Sin[x]))}


{(d + b*e*Cos[x] + c*e*Sin[x])*(a + b*Cos[x] + c*Sin[x])^(5/2), x, 8, (-(2/105))*(56*a*d + 15*a^2*e + 25*(b^2 + c^2)*e)*(c*Cos[x] - b*Sin[x])*Sqrt[a + b*Cos[x] + c*Sin[x]] - (2/35)*(7*d + 5*a*e)*(c*Cos[x] - b*Sin[x])*(a + b*Cos[x] + c*Sin[x])^(3/2) - (2/7)*e*(c*Cos[x] - b*Sin[x])*(a + b*Cos[x] + c*Sin[x])^(5/2) + (1/(105*Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])]))*(2*(a*(56*a*d + 15*a^2*e + 25*(b^2 + c^2)*e) + 3*(21*(b^2 + c^2)*d + 5*a*(7*a*d + 8*(b^2 + c^2)*e)))*EllipticE[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[a + b*Cos[x] + c*Sin[x]]) + (1/(105*Sqrt[a + b*Cos[x] + c*Sin[x]]))*(2*(5*(b^2 + c^2)*(3*a^2 + 5*(b^2 + c^2))*e + a*(119*(b^2 + c^2)*d + 15*a*(7*a*d + 8*(b^2 + c^2)*e)) - a*(a*(56*a*d + 15*a^2*e + 25*(b^2 + c^2)*e) + 3*(21*(b^2 + c^2)*d + 5*a*(7*a*d + 8*(b^2 + c^2)*e))))*EllipticF[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])])}
{(d + b*e*Cos[x] + c*e*Sin[x])*(a + b*Cos[x] + c*Sin[x])^(3/2), x, 7, (-(2/15))*(5*d + 3*a*e)*(c*Cos[x] - b*Sin[x])*Sqrt[a + b*Cos[x] + c*Sin[x]] - (2/5)*e*(c*Cos[x] - b*Sin[x])*(a + b*Cos[x] + c*Sin[x])^(3/2) + (2*(9*(b^2 + c^2)*e + a*(20*d + 3*a*e))*EllipticE[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[a + b*Cos[x] + c*Sin[x]])/(15*Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])]) + (2*(15*a^2*d + (b^2 + c^2)*(5*d + 12*a*e) - a*(9*(b^2 + c^2)*e + a*(20*d + 3*a*e)))*EllipticF[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])])/(15*Sqrt[a + b*Cos[x] + c*Sin[x]])}
{(d + b*e*Cos[x] + c*e*Sin[x])*(a + b*Cos[x] + c*Sin[x])^(1/2), x, 6, (-(2/3))*e*(c*Cos[x] - b*Sin[x])*Sqrt[a + b*Cos[x] + c*Sin[x]] + (2*(3*d + a*e)*EllipticE[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[a + b*Cos[x] + c*Sin[x]])/(3*Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])]) - (2*(a^2 - b^2 - c^2)*e*EllipticF[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])])/(3*Sqrt[a + b*Cos[x] + c*Sin[x]])}
{(d + b*e*Cos[x] + c*e*Sin[x])/(a + b*Cos[x] + c*Sin[x])^(1/2), x, 5, (2*e*EllipticE[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[a + b*Cos[x] + c*Sin[x]])/Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])] + (2*(d - a*e)*EllipticF[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])])/Sqrt[a + b*Cos[x] + c*Sin[x]]}
{(d + b*e*Cos[x] + c*e*Sin[x])/(a + b*Cos[x] + c*Sin[x])^(3/2), x, 6, (2*(d - a*e)*(c*Cos[x] - b*Sin[x]))/((a^2 - b^2 - c^2)*Sqrt[a + b*Cos[x] + c*Sin[x]]) + (2*(d - a*e)*EllipticE[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[a + b*Cos[x] + c*Sin[x]])/((a^2 - b^2 - c^2)*Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])]) + (2*e*EllipticF[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])])/Sqrt[a + b*Cos[x] + c*Sin[x]]}
{(d + b*e*Cos[x] + c*e*Sin[x])/(a + b*Cos[x] + c*Sin[x])^(5/2), x, 7, (2*(d - a*e)*(c*Cos[x] - b*Sin[x]))/(3*(a^2 - b^2 - c^2)*(a + b*Cos[x] + c*Sin[x])^(3/2)) - (2*(3*(b^2 + c^2)*e - a*(4*d - a*e))*(c*Cos[x] - b*Sin[x]))/(3*(a^2 - b^2 - c^2)^2*Sqrt[a + b*Cos[x] + c*Sin[x]]) - (2*(3*(b^2 + c^2)*e - a*(4*d - a*e))*EllipticE[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[a + b*Cos[x] + c*Sin[x]])/(3*(a^2 - b^2 - c^2)^2*Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])]) + (2*(3*a^2*d + b^2*(d - 4*a*e) + c^2*(d - 4*a*e) + a*(3*(b^2 + c^2)*e - a*(4*d - a*e)))*EllipticF[(1/2)*(x - ArcTan[b, c]), (2*Sqrt[b^2 + c^2])/(a + Sqrt[b^2 + c^2])]*Sqrt[(a + b*Cos[x] + c*Sin[x])/(a + Sqrt[b^2 + c^2])])/(3*(a^2 - b^2 - c^2)^2*Sqrt[a + b*Cos[x] + c*Sin[x]])}


(* ::Section::Closed:: *)
(*Products of functions of a trig function and its derivative*)


{Cos[a + b*x]*f[c, d, Sin[a + b*x], r, s], x, 1, Subst[Int[f[c, d, x, r, s], x], x, Sin[a + b*x]]/b}
{Sin[a + b*x]*f[c, d, Cos[a + b*x], r, s], x, 1, -(Subst[Int[f[c, d, x, r, s], x], x, Cos[a + b*x]]/b)}
{Sec[a + b*x]^2*f[c, d, Tan[a + b*x], r, s], x, 1, Subst[Int[f[c, d, x, r, s], x], x, Tan[a + b*x]]/b}
{Csc[a + b*x]^2*f[c, d, Cot[a + b*x], r, s], x, 1, -(Subst[Int[f[c, d, x, r, s], x], x, Cot[a + b*x]]/b)}


(* Integrands of the form Cos[x]^m*f (Sin[x]) where m is odd *)
{Cos[x]/(a + b*Sin[x]), x, 2, Log[a + b*Sin[x]]/b}
{Cos[x]*(a + b*Sin[x])^n, x, 2, (a + b*Sin[x])^(1 + n)/(b*(1 + n))}

{Cos[x]*Csc[x]^(7/3), x, 2, (-3*Csc[x]^(4/3))/4}
{Cos[x]/Sqrt[1 + Sin[x]^2], x, 2, ArcSinh[Sin[x]]}
{Cos[x]/Sqrt[4 - Sin[x]^2], x, 2, ArcSin[Sin[x]/2]}
{Cos[3*x]/Sqrt[4 - Sin[3*x]^2], x, 2, ArcSin[Sin[3*x]/2]/3}
{Cos[x]*Sqrt[1 + Csc[x]], x, 4, ArcTanh[Sqrt[1 + Csc[x]]] + Sqrt[1 + Csc[x]]*Sin[x]}
{Cos[x]*Sqrt[4 - Sin[x]^2], x, 3, 2*ArcSin[Sin[x]/2] + (Sin[x]*Sqrt[4 - Sin[x]^2])/2}
{Cos[x]*Sin[x]*Sqrt[1 + Sin[x]^2], x, 3, (1/3)*(1 + Sin[x]^2)^(3/2)}
{Cos[x]/Sqrt[2*Sin[x] + Sin[x]^2], x, 2, 2*ArcTanh[Sin[x]/Sqrt[2*Sin[x] + Sin[x]^2]]}

{Cos[x]^3*Sqrt[Sin[x]], x, 3, (2/3)*Sin[x]^(3/2) - (2/7)*Sin[x]^(7/2)}
{Cos[x]^3*Sin[x]^(3/2), x, 3, (2/5)*Sin[x]^(5/2) - (2/9)*Sin[x]^(9/2)}
{Cos[x]^3*Sin[x]^(5/2), x, 3, (2/7)*Sin[x]^(7/2) - (2/11)*Sin[x]^(11/2)}
{Cos[x]^3/Sqrt[Sin[x]], x, 3, 2*Sqrt[Sin[x]] - (2/5)*Sin[x]^(5/2)}
{Cos[x]^3/Sqrt[Sin[x]^3], x, 6, -((2*Sin[x])/Sqrt[Sin[x]^3]) - (2/3)*Sqrt[Sin[x]^3]}
{Cos[x]^3*Sqrt[Csc[x]], x, 5, -(2/(5*Csc[x]^(5/2))) + 2/Sqrt[Csc[x]]}
{Cos[x]^3*Csc[x]^(9/2), x, 5, (2/3)*Csc[x]^(3/2) - (2/7)*Csc[x]^(7/2)}


(* Integrands of the form Sin[x]^m*f (Cos[x]) where m is odd *)
{Sin[x]/(a + b*Cos[x]), x, 2, -(Log[a + b*Cos[x]]/b)}
{Sin[x]*(a + b*Cos[x])^n, x, 2, -((a + b*Cos[x])^(1 + n)/(b*(1 + n)))}

{Sin[x]/Sqrt[1 + Cos[x]^2], x, 2, -ArcSinh[Cos[x]]}
{Sin[x]^5/Sqrt[1 - 5*Cos[x]], x, 4, (1152*Sqrt[1 - 5*Cos[x]])/3125 + (64*(1 - 5*Cos[x])^(3/2))/3125 - (88*(1 - 5*Cos[x])^(5/2))/15625 - (8*(1 - 5*Cos[x])^(7/2))/21875 + (2*(1 - 5*Cos[x])^(9/2))/28125}


(* Integrands of the form Sec[x]^n*f (Tan[x]) where n is even *)
{Sec[x]^2/(a + b*Tan[x]), x, 2, Log[a + b*Tan[x]]/b}
{Sec[x]^2*(a + b*Tan[x])^n, x, 2, (a + b*Tan[x])^(1 + n)/(b*(1 + n))}

{1 + Sec[x]^2, x, 2, x + Tan[x]}
{2 + Tan[x]^2, x, 2, x + Tan[x]}
{Sec[x]^2*(1 + Cos[x]^2), x, 2, x + Tan[x]}
{Sec[x]^2*(1 + 1/(1 + Tan[x]^2)), x, 3, x + Tan[x]}
{Sec[x]^2*(2 + Tan[x]^2)/(1 + Tan[x]^2), x, 3, x + Tan[x]}

{Sec[x]^2/(1 - Tan[x]^2), x, 2, ArcTanh[Tan[x]]}
{Sec[x]^2/(9 + Tan[x]^2), x, 2, ArcTan[Tan[x]/3]/3}
{Sec[x]^2/(2 + 2*Tan[x] + Tan[x]^2), x, 2, ArcTan[1 + Tan[x]]}
{Sec[x]^2/(Tan[x]^2 + Tan[x]^3), x, 5, -Cot[x] + Log[1 + Cot[x]], 2*ArcTanh[1 + 2*Tan[x]] - Cot[x]}
{Sec[x]^2/(-Tan[x]^2 + Tan[x]^3), x, 5, Cot[x] + Log[1 - Cot[x]], 2*ArcTanh[1 - 2*Tan[x]] + Cot[x]}
{Sec[x]^2/(3 - 4*Tan[x]^3), x, 5, ArcTan[(6^(1/3) + 4*Tan[x])/(2^(1/3)*3^(5/6))]/(3*2^(2/3)*3^(1/6)) - Log[6^(1/3) - 2*Tan[x]]/(3*6^(2/3)) + Log[6^(2/3) + 2*6^(1/3)*Tan[x] + 4*Tan[x]^2]/(6*6^(2/3))}
{Sec[x]^2/(11 - 5*Tan[x] + 5*Tan[x]^2), x, 2, -((2*ArcTan[Sqrt[5/39]*(1 - 2*Tan[x])])/Sqrt[195])}
{Sec[x]^2/(1 + Sec[x]^2 - 3*Tan[x]), x, 2, 2*ArcTanh[3 - 2*Tan[x]]}

{Sec[x]^2*(a + b*Tan[x])/(c + d*Tan[x]), x, 4, -(((b*c - a*d)*Log[c + d*Tan[x]])/d^2) + (b*Tan[x])/d}
{Sec[x]^2*(a + b*Tan[x])^2/(c + d*Tan[x]), x, 5, ((b*c - a*d)^2*Log[c + d*Tan[x]])/d^3 - (b*(b*c - a*d)*Tan[x])/d^2 + (a + b*Tan[x])^2/(2*d)}
{Sec[x]^2*(a + b*Tan[x])^3/(c + d*Tan[x]), x, 6, -(((b*c - a*d)^3*Log[c + d*Tan[x]])/d^4) + (b*(b*c - a*d)^2*Tan[x])/d^3 - ((b*c - a*d)*(a + b*Tan[x])^2)/(2*d^2) + (a + b*Tan[x])^3/(3*d)}
{Sec[x]^2*Tan[x]^2/(2 + Tan[x]^3)^2, x, 3, -1/(3*(2 + Tan[x]^3))}
{Sec[x]^2*Tan[x]^6*(1 + Tan[x]^2)^3, x, 4, Tan[x]^7/7 + Tan[x]^9/3 + (3*Tan[x]^11)/11 + Tan[x]^13/13}
{Sec[x]^2*(2 + Tan[x]^2)/(1 + Tan[x]^3), x, 5, -((2*ArcTan[(1 - 2*Tan[x])/Sqrt[3]])/Sqrt[3]) + Log[1 + Tan[x]]}

{Sec[x]^4*(-1 + Sec[x]^2)^2*Tan[x], x, 4, Tan[x]^6/6 + Tan[x]^8/8}
{Tan[x]^2*Sec[x]^4, x, 3, Tan[x]^3/3 + Tan[x]^5/5}
{Tan[x]^3*Sec[x]^4, x, 3, Tan[x]^4/4 + Tan[x]^6/6}
{Tan[x]^n*Sec[x]^4, x, 3, Tan[x]^(1 + n)/(1 + n) + Tan[x]^(3 + n)/(3 + n)}

{Sec[x]^2/Sqrt[4 - Sec[x]^2], x, 2, ArcSin[Tan[x]/Sqrt[3]]}
{Sec[x]^2/Sqrt[1 - 4*Tan[x]^2], x, 2, ArcSin[2*Tan[x]]/2}
{Sec[x]^2/Sqrt[-4 + Tan[x]^2], x, 2, ArcTanh[Tan[x]/Sqrt[-4 + Tan[x]^2]]}
{Sec[x]^2*Sqrt[1 - Cot[x]^2], x, 4, ArcSin[Cot[x]] + Sqrt[1 - Cot[x]^2]*Tan[x]}
{Sec[x]^2*Sqrt[1 - Tan[x]^2], x, 3, (1/2)*ArcSin[Tan[x]] + (1/2)*Tan[x]*Sqrt[1 - Tan[x]^2]}


(* Integrands of the form Csc[x]^n*f (Cot[x]) where n is even *)
{Csc[x]^2/(a + b*Cot[x]), x, 2, -(Log[a + b*Cot[x]]/b)}
{Csc[x]^2*(a + b*Cot[x])^n, x, 2, -((a + b*Cot[x])^(1 + n)/(b*(1 + n)))}

{1 + Csc[x]^2, x, 2, x - Cot[x]}
{2 + Cot[x]^2, x, 2, x - Cot[x]}
{(1 + Sin[x]^2)*Csc[x]^2, x, 2, x - Cot[x]}
{(1 + 1/(1 + Cot[x]^2))*Csc[x]^2, x, 3, x - Cot[x]}

{Csc[x]^2*(a + b*Cot[x])/(c + d*Cot[x]), x, 4, -((b*Cot[x])/d) + ((b*c - a*d)*Log[c + d*Cot[x]])/d^2}
{Csc[x]^2*(a + b*Cot[x])^2/(c + d*Cot[x]), x, 5, (b*(b*c - a*d)*Cot[x])/d^2 - (a + b*Cot[x])^2/(2*d) - ((b*c - a*d)^2*Log[c + d*Cot[x]])/d^3}
{Csc[x]^2*(a + b*Cot[x])^3/(c + d*Cot[x]), x, 6, -((b*(b*c - a*d)^2*Cot[x])/d^3) + ((b*c - a*d)*(a + b*Cot[x])^2)/(2*d^2) - (a + b*Cot[x])^3/(3*d) + ((b*c - a*d)^3*Log[c + d*Cot[x]])/d^4}

{Cot[x]^2*Csc[x]^4, x, 3, (-(1/3))*Cot[x]^3 - Cot[x]^5/5}
{Cot[x]^3*Csc[x]^4, x, 3, (-(1/4))*Cot[x]^4 - Cot[x]^6/6}
{Cot[x]^n*Csc[x]^4, x, 3, -(Cot[x]^(1 + n)/(1 + n)) - Cot[x]^(3 + n)/(3 + n)}


(* Integrands of the form Sec[a+b*x]*Tan[a+b*x]*f (Sec[a+b*x]) *)
{(Sec[x]*Tan[x])/(a + b*Sec[x]), x, 2, Log[a + b*Sec[x]]/b, -(Log[Cos[x]]/b) + Log[b + a*Cos[x]]/b}
{(Sec[2*x]*Tan[2*x])/(1 + Sec[2*x])^(3/2), x, 3, -(1/Sqrt[1 + Sec[2*x]])}
{(Sec[x]*Tan[x])/(1 + Sec[x]^2), x, 2, -ArcTan[Cos[x]]}
{(Sec[x]*Tan[x])/(9 + 4*Sec[x]^2), x, 2, (-(1/6))*ArcTan[(3*Cos[x])/2]}
{(Sec[x]*Tan[x])/(Sec[x] + Sec[x]^2), x, 2, -Log[1 + Cos[x]]}
{(Sec[x]*Tan[x])/Sqrt[4 + Sec[x]^2], x, 3, ArcSinh[Sec[x]/2]}
{(Sec[x]*Tan[x])/Sqrt[1 + Cos[x]^2], x, 2, Sqrt[1 + Cos[x]^2]*Sec[x]}
{Sqrt[1 + 5*Cos[3*x]^2]*Sec[3*x]*Tan[3*x], x, 3, (-(1/3))*Sqrt[5]*ArcSinh[Sqrt[5]*Cos[3*x]] + (1/3)*Sqrt[1 + 5*Cos[3*x]^2]*Sec[3*x]}
{(Sec[3*x]*Tan[3*x])/Sqrt[1 + 5*Cos[3*x]^2], x, 2, (Sqrt[1 + 5*Cos[3*x]^2]*Sec[3*x])/3}


(* Integrands of the form Csc[a+b*x]*Cot[a+b*x]*f (Csc[a+b*x]) *)
{(Csc[x]*Cot[x])/(a + b*Csc[x]), x, 2, -Log[a + b*Csc[x]]/b, Log[Sin[x]]/b - Log[b + a*Sin[x]]/b}
{5^Csc[3*x]*Cot[3*x]*Csc[3*x], x, 3, -5^Csc[3*x]/(3*Log[5])}
{(Cot[x]*Csc[x])/(1 + Csc[x]^2), x, 2, ArcTan[Sin[x]]}
{(Cot[6*x]*Csc[6*x])/(5 - 11*Csc[6*x]^2)^2, x, 3, -(ArcTanh[Sqrt[5/11]*Sin[6*x]]/(60*Sqrt[55])) + Sin[6*x]/(60*(11 - 5*Sin[6*x]^2))}
{(Cot[x]*Csc[x])/Sqrt[1 + Sin[x]^2], x, 2, -(Csc[x]*Sqrt[1 + Sin[x]^2])}
{(Cot[5*x]*Csc[5*x]^3)/Sqrt[1 + Sin[5*x]^2], x, 3, (2/15)*Csc[5*x]*Sqrt[1 + Sin[5*x]^2] - (1/15)*Csc[5*x]^3*Sqrt[1 + Sin[5*x]^2]}


{Cos[x]^3*(a + b*Cos[x]^2)^3*Sin[x], x, 4, (a*(a + b*Cos[x]^2)^4)/(40*b^2) - (Cos[x]^2*(a + b*Cos[x]^2)^4)/(10*b)}
{Sin[x]^3*(a + b*Sin[x]^2)^3*Cos[x], x, 4, -((a*(a + b*Sin[x]^2)^4)/(40*b^2)) + (Sin[x]^2*(a + b*Sin[x]^2)^4)/(10*b)}


{Cos[x]*Cos[Sin[x]], x, 2, Sin[Sin[x]]}
{Cos[x]*Cos[Sin[x]]*Cos[Sin[Sin[x]]], x, 3, Sin[Sin[Sin[x]]]}
{Cos[x]*Sec[Sin[x]], x, 2, ArcTanh[Sin[Sin[x]]]}

{Cos[Cos[x]]*Sin[x], x, 2, -Sin[Cos[x]]}
{Sin[3*x]*Sin[Cos[3*x]], x, 2, Cos[Cos[3*x]]/3}
{Cos[x]*Cos[Cos[x]]*Sin[x]*Sin[Cos[x]], x, 3, Cos[x]/4 - (1/4)*Cos[Cos[x]]*Sin[Cos[x]] - (1/2)*Cos[x]*Sin[Cos[x]]^2}
{Cos[Cos[x]]*Sin[x]*Sin[6*Cos[x]]^2, x, 6, (-(1/2))*Sin[Cos[x]] + (1/44)*Sin[11*Cos[x]] + (1/52)*Sin[13*Cos[x]]}


(* ::Section::Closed:: *)
(*Problems from Calculus textbooks*)


(* ::Subsection::Closed:: *)
(*Anton Calculus, 4th Edition*)


{x*Sec[x]^2, x, 2, Log[Cos[x]] + x*Tan[x]}
{x*Cos[x^2]^4, x, 3, (3*x^2)/16 + (3/16)*Cos[x^2]*Sin[x^2] + (1/8)*Cos[x^2]^3*Sin[x^2]}

{Sqrt[Cos[x]]*Sin[x], x, 2, (-2*Cos[x]^(3/2))/3}
{Tan[E^(-2*x)]/E^(2*x), x, 2, Log[Cos[E^(-2*x)]]/2}
{(Sec[x]*Sin[2*x])/(1 + Cos[x]), x, 3, -2*Log[1 + Cos[x]]}
{x*Sec[3*x]^2, x, 2, (1/9)*Log[Cos[3*x]] + (1/3)*x*Tan[3*x]}
{Cos[2*Pi*x]/E^(2*Pi*x), x, 1, -(Cos[2*Pi*x]/(E^(2*Pi*x)*(4*Pi))) + Sin[2*Pi*x]/(E^(2*Pi*x)*(4*Pi))}
{Cos[x]^12*Sin[x]^10 - Cos[x]^10*Sin[x]^12, x, -23, (Cos[x]^11*Sin[x]^11)/11}


(* ::Subsection::Closed:: *)
(*Ayres Calculus, 1964 edition*)


{x*Cot[x^2], x, 2, Log[Sin[x^2]]/2}
{x*Sec[x^2]^2, x, 2, Tan[x^2]/2}
{Sin[8*x]/(9 + Sin[4*x]^4), x, 4, ArcTan[Sin[4*x]^2/3]/12}
{Cos[2*x]/(8 + Sin[2*x]^2), x, 2, ArcTan[Sin[2*x]/(2*Sqrt[2])]/(4*Sqrt[2])}
{x*(Cos[x^2]^3 - Sin[x^2]^3), x, 8, Cos[x^2]/2 - (1/6)*Cos[x^2]^3 + Sin[x^2]/2 - (1/6)*Sin[x^2]^3}
{(Cos[x]*Sin[x])/(1 - Cos[x]), x, 4, Cos[x] + Log[1 - Cos[x]]}


(* ::Subsection::Closed:: *)
(*Edwards and Penney Calculus*)


{x*Cos[x^2], x, 2, Sin[x^2]/2}
{x^2*Cos[4*x^3], x, 2, Sin[4*x^3]/12}
{x^3*Cos[x^4], x, 2, Sin[x^4]/4}
{x*Sin[x^2/2], x, 2, -Cos[x^2/2]}
{x*Sec[x^2]*Tan[x^2], x, 2, Sec[x^2]/2}
{Tan[x^(-1)]^2/x^2, x, 2, x^(-1) - Tan[x^(-1)]}
{x*Tan[1 + x^2], x, 2, -Log[Cos[1 + x^2]]/2}
{Sin[Pi*(1 + 2*x)], x, 2, Cos[2*Pi*x]/(2*Pi)}

{(Cot[x] + Csc[x]^2)/(1 - Cos[x]^2), x, 9, -Cot[x] - Cot[x]^2/2 - Cot[x]^3/3}


(* ::Subsection::Closed:: *)
(*Grossman Calculus*)


{-(x*Cos[x^2]), x, 3, -Sin[x^2]/2}
{x^2*Cos[4*x^3]*Cos[5*x^3], x, 5, Sin[x^3]/6 + (1/54)*Sin[9*x^3]}
{x^14*Sin[x^3], x, 6, -8*Cos[x^3] + 4*x^6*Cos[x^3] - (1/3)*x^12*Cos[x^3] - 8*x^3*Sin[x^3] + (4/3)*x^9*Sin[x^3]}
{(x^2*Sin[2*x^3])/E^(3*x^3), x, 2, ((-(2/39))*Cos[2*x^3])/E^(3*x^3) - ((1/13)*Sin[2*x^3])/E^(3*x^3)}


(* ::Subsection::Closed:: *)
(*Hughes, Hallet, Gleason, et al Calculus, 2nd Edition*)


{2*x*Cos[x^2], x, 3, Sin[x^2]}
{3*x^2*Cos[7 + x^3], x, 3, Sin[7 + x^3]}
{(1 + x^2)^(-1) + Sin[x], x, 3, ArcTan[x] - Cos[x]}
{x*Sin[1 + x^2], x, 2, -Cos[1 + x^2]/2}
{x*Cos[1 + x^2], x, 2, Sin[1 + x^2]/2}
{1 + x^2*Cos[x^3], x, 3, x + Sin[x^3]/3}
{x^2*Sin[1 + x^3], x, 2, -Cos[1 + x^3]/3}
{12*x^2*Cos[x^3], x, 3, 4*Sin[x^3]}
{(1 + x)*Sin[1 + x], x, 3, -((1 + x)*Cos[1 + x]) + Sin[1 + x]}
{x^5*Cos[x^3], x, 3, Cos[x^3]/3 + (1/3)*x^3*Sin[x^3]}
{Cos[x]/E^(3*x), x, 1, ((-(3/10))*Cos[x])/E^(3*x) + ((1/10)*Sin[x])/E^(3*x)}
{x^3*Sin[x^2], x, 3, (-(1/2))*x^2*Cos[x^2] + Sin[x^2]/2}
{x^3*Cos[x^2], x, 3, Cos[x^2]/2 + (1/2)*x^2*Sin[x^2]}
{Cos[x]*Cos[2*Sin[x]], x, 2, (1/2)*Sin[2*Sin[x]]}
{(Cos[x]*Sin[x])/(1 + Cos[x]^2), x, 3, (-(1/2))*Log[1 + Cos[x]^2]}
{(1 + Cos[x])*(x + Sin[x])^3, x, 2, (x + Sin[x])^4/4}


(* ::Subsection::Closed:: *)
(*Spivak Calculus*)


{(1 + Cos[x])*Csc[x]^2, x, 4, -Cot[x] - Csc[x]}
{Sin[x]*Tan[x]^2, x, 3, Cos[x] + Sec[x]}


(* ::Subsection::Closed:: *)
(*Stewart Calculus*)


{x*Csc[x]^2, x, 2, -(x*Cot[x]) + Log[Sin[x]]}
{Cos[x]*Sin[Pi/6 + x], x, 3, x/4 - (1/4)*Cos[Pi/6 + 2*x]}
{x*Sin[x^2]^3, x, 3, (-(1/2))*Cos[x^2] + (1/6)*Cos[x^2]^3}
{Sin[x]^2*Tan[x], x, 3, Cos[x]^2/2 - Log[Cos[x]]}
{Cos[x]^2*Cot[x]^3, x, 3, (-(1/2))*Csc[x]^2 - 2*Log[Sin[x]] + Sin[x]^2/2}
{Sec[x]*(1 - Sin[x]), x, 2, Log[1 + Sin[x]]}
{(1 + Cos[x])*Csc[x], x, 2, Log[1 - Cos[x]]}
{Cos[x]^2*(1 - Tan[x]^2), x, 4, Cos[x]*Sin[x]}
{Csc[2*x]*(Cos[x] + Sin[x]), x, 5, (-(1/2))*ArcTanh[Cos[x]] + (1/2)*ArcTanh[Sin[x]]}
{(Cos[x]*(-3 + 2*Sin[x]))/(2 - 3*Sin[x] + Sin[x]^2), x, 2, Log[2 - 3*Sin[x] + Sin[x]^2]}
{(Cos[x]^2*Sin[x])/(5 + Cos[x]^2), x, 4, Sqrt[5]*ArcTan[Cos[x]/Sqrt[5]] - Cos[x]}
{Cos[x]/(Sin[x] + Sin[x]^2), x, 3, -2*ArcTanh[1 + 2*Sin[x]]}
{Cos[x]/(Sin[x] + Sin[x]^Sqrt[2]), x, 2, -2*(1 + Sqrt[2])*ArcTanh[1 + 2*Sin[x]^(-1 + Sqrt[2])]}
{1/(2*Sin[x] + Sin[2*x]), x, 7, (1/4)*Log[Tan[x/2]] + (1/8)*Tan[x/2]^2, (-(1/4))*ArcTanh[Cos[x]] + 1/(4*(1 + Cos[x]))}
{(-3 + 4*x + x^2)*Sin[2*x], x, 8, (7/4)*Cos[2*x] - 2*x*Cos[2*x] - (1/2)*x^2*Cos[2*x] + Sin[2*x] + (1/2)*x*Sin[2*x]}
{Cos[4*x]/E^(3*x), x, 1, ((-(3/25))*Cos[4*x])/E^(3*x) + ((4/25)*Sin[4*x])/E^(3*x)}
{(Cos[x]*Sin[x])/Sqrt[1 + Sin[x]], x, 3, (-(4/3))*Sqrt[1 + Sin[x]] + (2/3)*Sin[x]*Sqrt[1 + Sin[x]]}
{x + 60*Cos[x]^5*Sin[x]^4, x, 5, x^2/2 + 12*Sin[x]^5 - (120*Sin[x]^7)/7 + (20*Sin[x]^9)/3}


(* ::Subsection::Closed:: *)
(*Thomas Calculus, 8th Edition*)


{Cos[x]*(Sec[x] + Tan[x]), x, 3, x - Cos[x]}
{Cos[x]*(Sec[x]^3 + Tan[x]), x, 4, -Cos[x] + Tan[x]}
{(-(Cot[x]*Csc[x]) + Csc[x]^2)/2, x, 4, -(Cot[x]/2) + Csc[x]/2}
{-Csc[x]^2 + Sin[2*x], x, 3, -Cos[2*x]/2 + Cot[x]}
{2*Cot[2*x] - 3*Sin[3*x], x, 3, Cos[3*x] + Log[Sin[2*x]]}
{x*Sin[2*x^2], x, 2, -Cos[2*x^2]/4}
{-(Cos[1 - x]*Sin[1 - x]*Sqrt[1 + Sin[1 - x]^2]), x, 4, (1/3)*(1 + Sin[1 - x]^2)^(3/2)}
{(Cos[1/x]*Sin[1/x])/x^2, x, 3, (-(1/2))*Sin[1/x]^2}
{Cos[(1 + 3*x)/2]*Sin[(1 + 3*x)/2]^3, x, 2, (1/6)*Sin[(1/2)*(1 + 3*x)]^4}
{4*x*Tan[x^2], x, 3, -2*Log[Cos[x^2]]}
{x*Sec[5 - x^2], x, 2, -ArcTanh[Sin[5 - x^2]]/2}
{Csc[x^(-1)]/x^2, x, 2, ArcTanh[Cos[1/x]]}
{(Csc[x] - Sec[x])*(Cos[x] + Sin[x]), x, 4, Log[Cos[x]] + Log[Sin[x]]}
{-Cos[3*x]*Sin[2*x] + Cos[2*x]*Sin[3*x], x, 8, -Cos[x]}
{4*x*Sec[2*x]^2, x, 3, Log[Cos[2*x]] + 2*x*Tan[2*x]}
{4*Sin[x]^2*Tan[x]^2, x, 3, -6*x + 6*Tan[x] - 2*Sin[x]^2*Tan[x]}
{Cos[x]^4*Cot[x]^2, x, 3, -((15*x)/8) - (15*Cot[x])/8 + (5/8)*Cos[x]^2*Cot[x] + (1/4)*Cos[x]^4*Cot[x]}
{16*Cos[x]^2*Sin[x]^2, x, 3, 2*x + 2*Cos[x]*Sin[x] - 4*Cos[x]^3*Sin[x]}
{8*Cos[x]^2*Sin[x]^4, x, 4, x/2 + (1/2)*Cos[x]*Sin[x] - Cos[x]^3*Sin[x] - (4/3)*Cos[x]^3*Sin[x]^3}
{35*Cos[x]^3*Sin[x]^4, x, 4, 7*Sin[x]^5 - 5*Sin[x]^7}
{4*Cos[x]^4*Sin[x]^4, x, 5, (3*x)/32 + (3/32)*Cos[x]*Sin[x] + (1/16)*Cos[x]^3*Sin[x] - (1/4)*Cos[x]^5*Sin[x] - (1/2)*Cos[x]^5*Sin[x]^3}
{Cos[x]/(-Sin[x] + Sin[x]^3), x, 2, ArcTanh[1 - 2*Sin[x]^2]}


(* ::Section::Closed:: *)
(*Problems from integration competitions*)


(* ::Subsection::Closed:: *)
(*MIT Integration Competition*)


{-1 + 2*Cos[x]^2 + Cos[x]*Sin[x], x, 4, Cos[x]*Sin[x] + Sin[x]^2/2}


(* ::Subsection::Closed:: *)
(*North Texas University Integration Competition*)


{Cos[x]^2 + Sin[x]^2, x, 3, x}
{-Cos[x]^2 + Sin[x]^2, x, 3, -(Cos[x]*Sin[x])}
{2^Sin[x]*Cos[x], x, 2, 2^Sin[x]/Log[2]}


(* ::Subsection::Closed:: *)
(*University of Wisconsin Integration Competition*)


{Tan[x]^3 + Tan[x]^5, x, 6, Tan[x]^4/4}
{x*Sec[x]*(2 + x*Tan[x]), x, 11, x^2*Sec[x]}


(* ::Section::Closed:: *)
(*Miscellaneous problems*)


(* Problems contributed by Michael Wester *)

(* This example involves several symbolic parameters
   => 1/sqrt(b^2 - a^2) log ([sqrt (b^2 - a^2) tan (x/2) + a + b]/
                            [sqrt (b^2 - a^2) tan (x/2) - a - b])   (a^2 < b^2)
      [Gradshteyn and Ryzhik 2.553(3)] *)
(*
{1/(a + b*Cos[x]), x, 0, Assumptions -> a^2 < b^2,
 1/Sqrt[b^2 - a^2]*Log[(Sqrt[b^2 - a^2]*Tan[x/2] + a + b)/
                       (Sqrt[b^2 - a^2]*Tan[x/2] - a - b)]}
*)
{1/(a + b*Cos[x]), x, 1, (2*ArcTan[((a - b)*Tan[x/2])/Sqrt[a^2 - b^2]])/Sqrt[a^2 - b^2]}
(* The integral of 1/(a + 3 cos x + 4 sin x) can have 4 different forms
   depending on the value of a !   [Gradshteyn and Ryzhik 2.558(4)]
   => (a = 3) 1/4 log[3 + 4 tan (x/2)] *)
{1/(3 + 3*Cos[x] + 4*Sin[x]), x, 1, 1/4*Log[3 + 4*Tan[x/2]]}
(* => (a = 4) 1/3 log ([tan (x/2) + 1]/[tan (x/2) + 7]) *)
{1/(4 + 3*Cos[x] + 4*Sin[x]), x, 1, (-(2/3))*ArcTanh[(1/3)*(4 + Tan[x/2])]}
(* => (a = 5) -1/[2 + tan (x/2)] *)
{1/(5 + 3*Cos[x] + 4*Sin[x]), x, 1, -1/(2 + Tan[x/2]), -((4 - 5*Sin[x])/(4*(4*Cos[x] - 3*Sin[x])))}
(* => (a = 6) 2/sqrt(11) arctan ([3 tan (x/2) + 4]/sqrt(11)) *)
{1/(6 + 3*Cos[x] + 4*Sin[x]), x, 1, 2/Sqrt[11]*ArcTan[(3*Tan[x/2] + 4)/Sqrt[11]]}


{Sin[x]*Sin[2*x]*Sin[3*x], x, 10, (-(1/8))*Cos[2*x] - (1/16)*Cos[4*x] - (1/12)*Sin[3*x]^2, (1/8)*Cos[2*x] - (1/8)*Cos[4*x] + (1/24)*Cos[6*x] + Sin[x]^4/2}
{Cos[x]*Cos[2*x]*Cos[3*x], x, 5, x/4 + (1/8)*Sin[2*x] + (1/12)*Cos[3*x]*Sin[3*x] + (1/16)*Sin[4*x]}
{Cos[x]*Sin[2*x]*Sin[3*x], x, 11, x/4 + (1/8)*Sin[2*x] - (1/16)*Sin[4*x] - (1/24)*Sin[6*x]}
{Cos[2*x]*Cos[3*x]*Sin[x], x, 8, (-(1/8))*Cos[2*x] + (1/16)*Cos[4*x] + (1/12)*Sin[3*x]^2}


{x*Sin[x^2], x, 2, -Cos[x^2]/2}
{(-Cos[x] + Sin[x])*(Cos[x] + Sin[x])^5, x, 2, -(Cos[x] + Sin[x])^6/6}
{2*x*Sec[x]^2*Tan[x], x, 3, x*Sec[x]^2 - Tan[x]}
{(1 + Cos[x]^2)/(1 + Cos[2*x]), x, 3, x/2 + Tan[x]/2}


{Sin[x]/(Cos[x]^3 - Cos[x]^5), x, 6, Log[Tan[x]] + Tan[x]^2/2, -Log[Cos[x]] + (1/2)*Log[Sin[x]^2] + Sec[x]^2/2}
{Sec[x]*(5 - 11*Sec[x]^5)^2*Tan[x], x, 3, 25*Sec[x] - (55*Sec[x]^6)/3 + 11*Sec[x]^11}
{Sin[5*x]^3*Tan[5*x]^3, x, 4, (-(1/2))*ArcTanh[Sin[5*x]] + (1/2)*Sin[5*x] + (1/6)*Sin[5*x]*Tan[5*x]^2 - (1/15)*Sin[5*x]^3*Tan[5*x]^2}
{Sin[5*x]^3*Tan[5*x]^4, x, 3, (-(3/5))*Cos[5*x] + (1/15)*Cos[5*x]^3 - (3/5)*Sec[5*x] + (1/15)*Sec[5*x]^3}
{Sin[6*x]^5*Tan[6*x]^3, x, 5, (-(7/12))*ArcTanh[Sin[6*x]] + (7/12)*Sin[6*x] + (7/36)*Sin[6*x]*Tan[6*x]^2 - (7/90)*Sin[6*x]^3*Tan[6*x]^2 - (1/30)*Sin[6*x]^5*Tan[6*x]^2}
{(-1 + Sec[2*x]^2)^3*Sin[2*x], x, 4, (1/2)*Cos[2*x] + (3/2)*Sec[2*x] - (1/2)*Sec[2*x]^3 + (1/10)*Sec[2*x]^5}
{Sin[x]*Tan[x]^5, x, 4, (15/8)*ArcTanh[Sin[x]] - (15*Sin[x])/8 - (5/8)*Sin[x]*Tan[x]^2 + (1/4)*Sin[x]*Tan[x]^4}
{Cos[2*x]^5*Cot[2*x]^4, x, 3, 2*Csc[2*x] - (1/6)*Csc[2*x]^3 + 3*Sin[2*x] - (2/3)*Sin[2*x]^3 + (1/10)*Sin[2*x]^5}

{Cos[3*x]*(-1 + Csc[3*x]^2)^3*(1 - Sin[3*x]^2)^5, x, 5, (-(28/3))*Csc[3*x] + (8/9)*Csc[3*x]^3 - (1/15)*Csc[3*x]^5 - (56/3)*Sin[3*x] + (70/9)*Sin[3*x]^3 - (56/15)*Sin[3*x]^5 + (4/3)*Sin[3*x]^7 - (8/27)*Sin[3*x]^9 + (1/33)*Sin[3*x]^11}
{Cot[2*x]*(-1 + Csc[2*x]^2)^2*(1 - Sin[2*x]^2)^2, x, 5, Csc[2*x]^2 - (1/8)*Csc[2*x]^4 + 3*Log[Sin[2*x]] - Sin[2*x]^2 + (1/8)*Sin[2*x]^4}
{Cos[2*x]*(-1 + Csc[2*x]^2)^4*(1 - Sin[2*x]^2)^2, x, 5, 10*Csc[2*x] - (5/2)*Csc[2*x]^3 + (3/5)*Csc[2*x]^5 - (1/14)*Csc[2*x]^7 + (15/2)*Sin[2*x] - Sin[2*x]^3 + (1/10)*Sin[2*x]^5}
{Cot[3*x]*(-1 + Csc[3*x]^2)^3*(1 - Sin[3*x]^2)^2, x, 5, (-(5/3))*Csc[3*x]^2 + (5/12)*Csc[3*x]^4 - (1/18)*Csc[3*x]^6 - (10/3)*Log[Sin[3*x]] + (5/6)*Sin[3*x]^2 - (1/12)*Sin[3*x]^4}
{(1 + Cot[9*x]^2)^2*(1 + Tan[9*x]^2)^3, x, 5, (-(4/9))*Cot[9*x] - (1/27)*Cot[9*x]^3 + (2/3)*Tan[9*x] + (4/27)*Tan[9*x]^3 + (1/45)*Tan[9*x]^5}
{(Cos[x]*(9 - 7*Sin[x]^3)^2)/(1 - Sin[x]^2), x, 8, 130*ArcTanh[Sin[x]] + 63*Log[Cos[x]^2] - 49*Sin[x] + 63*Sin[x]^2 - (49*Sin[x]^3)/3 - (49*Sin[x]^5)/5}

{Cos[2*x]^4*Cot[2*x]^5, x, 3, Csc[2*x]^2 - (1/8)*Csc[2*x]^4 + 3*Log[Sin[2*x]] - Sin[2*x]^2 + (1/8)*Sin[2*x]^4}
{(Sec[x]*Tan[x]^2)/(4 + 3*Sec[x]), x, 6, (-(4/9))*ArcTanh[Sin[x]] + (2/9)*Sqrt[7]*ArcTanh[Tan[x/2]/Sqrt[7]] + Tan[x]/3}
{x*Sec[1 + x]*Tan[1 + x], x, 2, -ArcTanh[Sin[1 + x]] + x*Sec[1 + x]}
{Sin[2*x]/Sqrt[9 - Sin[x]^2], x, 4, -2*Sqrt[9 - Sin[x]^2]}
{Sin[2*x]/Sqrt[9 - Cos[x]^4], x, 4, -ArcSin[Cos[x]^2/3]}
{Cos[x^(-1)]/x^5, x, 5, 6*Cos[1/x] - (3*Cos[1/x])/x^2 - Sin[1/x]/x^3 + (6*Sin[1/x])/x}
{Cos[1 + x]^3*Sin[1 + x]^3, x, 3, (1/4)*Sin[1 + x]^4 - (1/6)*Sin[1 + x]^6}
{(1 + 2*x)^3*Sin[1 + 2*x]^2, x, 5, (-(3/16))*(1 + 2*x)^2 + (1/16)*(1 + 2*x)^4 + (3/8)*(1 + 2*x)*Cos[1 + 2*x]*Sin[1 + 2*x] - (1/4)*(1 + 2*x)^3*Cos[1 + 2*x]*Sin[1 + 2*x] - (3/16)*Sin[1 + 2*x]^2 + (3/8)*(1 + 2*x)^2*Sin[1 + 2*x]^2}
{(-1 + Sec[x])/(1 - Tan[x]), x, 4, -(x/2) + Sqrt[2]*ArcTanh[(1 + Tan[x/2])/Sqrt[2]] + (1/2)*Log[Cos[x] - Sin[x]]}
{x^2*Cos[3*x]*Cos[5*x], x, 7, (1/4)*x*Cos[2*x] + (1/64)*x*Cos[8*x] - (1/8)*Sin[2*x] + (1/4)*x^2*Sin[2*x] - (1/512)*Sin[8*x] + (1/16)*x^2*Sin[8*x]}
{Cos[x]^2*Sqrt[Tan[x]], x, 8, -(ArcTan[1 - Sqrt[2]*Sqrt[Tan[x]]]/(4*Sqrt[2])) + ArcTan[1 + Sqrt[2]*Sqrt[Tan[x]]]/(4*Sqrt[2]) + Log[1 - Sqrt[2]*Sqrt[Tan[x]] + Tan[x]]/(8*Sqrt[2]) - Log[1 + Sqrt[2]*Sqrt[Tan[x]] + Tan[x]]/(8*Sqrt[2]) + (1/2)*Cos[x]^2*Tan[x]^(3/2)}


{Sec[x]^2*(1 + Sin[x]), x, 4, Sec[x] + Tan[x]}

{10*x^9*Cos[x^5*Log[x]] - x^10*(x^4 + 5*x^4*Log[x])*Sin[x^5*Log[x]], x, 8, x^10*Cos[x^5*Log[x]]}
{Cos[x/2]^2*Tan[Pi/4 + x/2], x, 4, If[$VersionNumber > 6, x/2 - Cos[x]/2 - Log[Cos[Pi/4 + x/2]], x/2 - Cos[x]/2 - Log[-Cos[x/2] + Sin[x/2]]]}

{(2 + 3*x)^2*Sin[x]^3, x, 8, 14*Cos[x] - (2/3)*(2 + 3*x)^2*Cos[x] - (2*Cos[x]^3)/3 + 4*(2 + 3*x)*Sin[x] - (1/3)*(2 + 3*x)^2*Cos[x]*Sin[x]^2 + (2/3)*(2 + 3*x)*Sin[x]^3}
{Sec[x]^(1 + m)*Sin[x], x, 2, Sec[x]^m/m}
{Cos[a + b*x]^n*Sin[a + b*x]^(-2 - n), x, 1, -((Cos[a + b*x]^(1 + n)*Sin[a + b*x]^(-1 - n))/(b*(1 + n)))}
(* {Sin[(1+x)^2]/x, x, 0} *)
{(1 + Sin[x^2])^2/x^3, x, 11, -(3/(4*x^2)) + Cos[2*x^2]/(4*x^2) + CosIntegral[x^2] - Sin[x^2]/x^2 + (1/2)*SinIntegral[2*x^2]}
{1/(Sec[x] + Sin[x]*Tan[x]), x, 3, ArcTan[Sin[x]]}
{(a + b*x + c*x^2)*Sin[x], x, 8, (-a)*Cos[x] + 2*c*Cos[x] - b*x*Cos[x] - c*x^2*Cos[x] + b*Sin[x] + 2*c*x*Sin[x]}
{Sin[x^5]/x, x, 1, SinIntegral[x^5]/5}
{Sin[2^x]/(1 + 2^x), x, 10, (CosIntegral[1 + 2^x]*Sin[1])/Log[2] + SinIntegral[2^x]/Log[2] - (Cos[1]*SinIntegral[1 + 2^x])/Log[2]}

{x*Cos[2*x^2]*Sin[2*x^2]^(3/4), x, 3, Sin[2*x^2]^(7/4)/7}
{x*Sec[x^2]^2*Tan[x^2]^2, x, 3, Tan[x^2]^3/6}
{x^2*Cos[a + b*x^3]^7*Sin[a + b*x^3], x, 3, -Cos[a + b*x^3]^8/(24*b)}
{x^5*Cos[a + b*x^3]^7*Sin[a + b*x^3], x, 6, (35*x^3)/(3072*b) - (x^3*Cos[a + b*x^3]^8)/(24*b) + (35*Cos[a + b*x^3]*Sin[a + b*x^3])/(3072*b^2) + (35*Cos[a + b*x^3]^3*Sin[a + b*x^3])/(4608*b^2) + (7*Cos[a + b*x^3]^5*Sin[a + b*x^3])/(1152*b^2) + (Cos[a + b*x^3]^7*Sin[a + b*x^3])/(192*b^2)}
{x^5*Sec[a + b*x^3]^7*Tan[a + b*x^3], x, 6, -((5*ArcTanh[Sin[a + b*x^3]])/(336*b^2)) + (x^3*Sec[a + b*x^3]^7)/(21*b) - (5*Sec[a + b*x^3]*Tan[a + b*x^3])/(336*b^2) - (5*Sec[a + b*x^3]^3*Tan[a + b*x^3])/(504*b^2) - (Sec[a + b*x^3]^5*Tan[a + b*x^3])/(126*b^2)}

{Sec[x^(-1)]^2/x^2, x, 2, -Tan[x^(-1)]}
{3*x^2*Cos[x^3], x, 3, Sin[x^3]}

{(1 + 2*x)*Sec[1 + 2*x]^2, x, 3, (1/2)*Log[Cos[1 + 2*x]] + (1/2)*(1 + 2*x)*Tan[1 + 2*x]}


(* Problems requiring simplification of irreducible integrands *)
{(x^2*Cos[a + b*x])/Sqrt[3*Sin[a + b*x] + x^3] + x^4/(Sqrt[x^3 + 3*Sin[a + b*x]]*b) + (4*x*Sqrt[x^3 + 3*Sin[a + b*x]])/(3*b), x, 2, (2*x^2*Sqrt[x^3 + 3*Sin[a + b*x]])/(3*b)}
{x^2*(Cos[a + b*x]/Sqrt[3*Sin[a + b*x] + x^3]), x, 1, -(Int[x^4/Sqrt[x^3 + 3*Sin[a + b*x]], x]/b) - (4*Int[x*Sqrt[x^3 + 3*Sin[a + b*x]], x])/(3*b) + (2*x^2*Sqrt[x^3 + 3*Sin[a + b*x]])/(3*b)}
