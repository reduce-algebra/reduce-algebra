(* ::Package:: *)

(* ::Title:: *)
(*Miscellaneous Integration Problems Involving Hyperbolic Functions*)


(* ::Section:: *)
(*Integrands involving three hyperbolic functions*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Hyper[x]^m / (a Hyper[x] + b Hyper[x])*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Hyper[x]^m / (a Cosh[x] + b Sinh[x])*)


(* Integrands of the form Sinh[x]^m/(a*Cosh[x]+b*Sinh[x]) *)
{Sinh[x]/(a*Cosh[x] + b*Sinh[x]), x, 1, -((b*x)/(a^2 - b^2)) + (a*Log[a*Cosh[x] + b*Sinh[x]])/(a^2 - b^2)}
{Sinh[x]^2/(a*Cosh[x] + b*Sinh[x]), x, 4, -((2*a^2*ArcTan[(b + a*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(3/2)) - (b*Cosh[x])/(a^2 - b^2) + (a*Sinh[x])/(a^2 - b^2)}
{Sinh[x]^3/(a*Cosh[x] + b*Sinh[x]), x, 5, (a^2*b*x)/(a^2 - b^2)^2 + (b*x)/(2*(a^2 - b^2)) - (a^3*Log[a*Cosh[x] + b*Sinh[x]])/(a^2 - b^2)^2 - (b*Cosh[x]*Sinh[x])/(2*(a^2 - b^2)) + (a*Sinh[x]^2)/(2*(a^2 - b^2))}


(* Integrands of the form Cosh[x]^m/(a*Cosh[x]+b*Sinh[x]) *)
{Cosh[x]/(a*Cosh[x] + b*Sinh[x]), x, 1, (a*x)/(a^2 - b^2) - (b*Log[a*Cosh[x] + b*Sinh[x]])/(a^2 - b^2)}
{Cosh[x]^2/(a*Cosh[x] + b*Sinh[x]), x, 4, -((2*b^2*ArcTan[(b + a*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(3/2)) - (b*Cosh[x])/(a^2 - b^2) + (a*Sinh[x])/(a^2 - b^2)}
{Cosh[x]^3/(a*Cosh[x] + b*Sinh[x]), x, 5, -((a*b^2*x)/(a^2 - b^2)^2) + (a*x)/(2*(a^2 - b^2)) + (b^3*Log[a*Cosh[x] + b*Sinh[x]])/(a^2 - b^2)^2 + (a*Cosh[x]*Sinh[x])/(2*(a^2 - b^2)) - (b*Sinh[x]^2)/(2*(a^2 - b^2))}


(* Integrands of the form Tanh[x]^m/(a*Cosh[x]+b*Sinh[x]) *)
{Tanh[x]/(a*Sinh[x] + b*Cosh[x]), x, 4, ArcTan[Sinh[x]]/a + (2*b*ArcTanh[(a + b*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a*Sqrt[a^2 - b^2])}


(* Integrands of the form Coth[x]^m/(a*Cosh[x]+b*Sinh[x]) *)
{Coth[x]/(a*Sinh[x] + b*Cosh[x]), x, 4, -(ArcCoth[Cosh[x]]/b) + (2*a*ArcTanh[(a + b*Tanh[x/2])/Sqrt[a^2 - b^2]])/(b*Sqrt[a^2 - b^2])}


(* ::Subsubsection:: *)
(*Integrands of the form Hyper[x]^m / (a Sech[x] + b Tanh[x])*)


(* ::Subsubsection:: *)
(*Integrands of the form Hyper[x]^m / (a Csch[x] + b Coth[x])*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Hyper[x]^m / (a Hyper[x] + b Hyper[x])^2*)


(* Integrands of the form Sinh[x]^m/(a*Cosh[x]+b*Sinh[x])^2 *)
{Sinh[x]/(a*Cosh[x] + b*Sinh[x])^2, x, 2, -((2*b*ArcTan[(b + a*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(3/2)) - a/((a^2 - b^2)*(a*Cosh[x] + b*Sinh[x]))}
{Sinh[x]^2/(a*Cosh[x] + b*Sinh[x])^2, x, 9, ((a^2 + b^2)*x)/(a^2 - b^2)^2 - a/((a^2 - b^2)*(b + a*Coth[x])) - (2*a*b*Log[a*Cosh[x] + b*Sinh[x]])/(a^2 - b^2)^2, -(a/((a^2 - b^2)*(b + a*Coth[x]))) - Log[1 - Coth[x]]/(2*(a + b)^2) + Log[1 + Coth[x]]/(2*(a - b)^2) - (2*a*b*Log[b + a*Coth[x]])/(a^2 - b^2)^2}
(* {Sinh[x]^3/(a*Cosh[x] + b*Sinh[x])^2, x, 0, (12*a^2*b*Sqrt[a^2 + b^2]*ArcTanh[(-b + a*Tan[x/2])/Sqrt[a^2 + b^2]]*(a*Cosh[x] + b*Sinh[x]) + (a^2 + b^2)*(3*a*(a^2 - b^2) + a*(a^2 + b^2)*Cos[2*x] - b*(a^2 + b^2)*Sin[2*x]))/(2*(a^2 + b^2)^3*(a*Cosh[x] + b*Sinh[x]))} *)


(* Integrands of the form Cosh[x]^m/(a*Cosh[x]+b*Sinh[x])^2 *)
{Cosh[x]/(a*Cosh[x] + b*Sinh[x])^2, x, 2, (2*a*ArcTan[(b + a*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(3/2) + b/((a^2 - b^2)*(a*Cosh[x] + b*Sinh[x]))}
{Cosh[x]^2/(a*Cosh[x] + b*Sinh[x])^2, x, 9, ((a^2 + b^2)*x)/(a^2 - b^2)^2 - (2*a*b*Log[a*Cosh[x] + b*Sinh[x]])/(a^2 - b^2)^2 + b/((a^2 - b^2)*(a + b*Tanh[x])), -(Log[1 - Tanh[x]]/(2*(a + b)^2)) + Log[1 + Tanh[x]]/(2*(a - b)^2) - (2*a*b*Log[a + b*Tanh[x]])/(a^2 - b^2)^2 + b/((a^2 - b^2)*(a + b*Tanh[x]))}
(* {Cosh[x]^3/(a*Cosh[x] + b*Sinh[x])^2, x, 0, (12*a*b^2*Sqrt[a^2 + b^2]*ArcTanh[(-b + a*Tan[x/2])/Sqrt[a^2 + b^2]]*(a*Cosh[x] + b*Sinh[x]) + (a^2 + b^2)*(3*b*(a^2 - b^2) + b*(a^2 + b^2)*Cos[2*x] + a*(a^2 + b^2)*Sin[2*x]))/(2*(a^2 + b^2)^3*(a*Cosh[x] + b*Sinh[x]))} *)


(* ::Subsection::Closed:: *)
(*Integrands of the form Hyper[x]^m / (a Hyper[x] + b Hyper[x])^3*)


(* Integrands of the form Sinh[x]^m/(a*Cosh[x]+b*Sinh[x])^3 *)
{Sinh[x]/(a*Cosh[x] + b*Sinh[x])^3, x, 3, -(a/(2*(a^2 - b^2)*(a*Cosh[x] + b*Sinh[x])^2)) - (b*Sinh[x])/(a*(a^2 - b^2)*(a*Cosh[x] + b*Sinh[x]))}
(* {Sinh[x]^2/(a*Cosh[x] + b*Sinh[x])^3, x, 0, -(((a^2 - 2*b^2)*ArcTanh[(-b + a*Tan[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2)) + (a*(3*a*b*Cosh[x] + (a^2 + 4*b^2)*Sinh[x]))/(2*(a^2 + b^2)^2*(a*Cosh[x] + b*Sinh[x])^2)} *)
{Sinh[x]^3/(a*Cosh[x] + b*Sinh[x])^3, x, 10, -((b*(3*a^2 + b^2)*x)/(a^2 - b^2)^3) - a/(2*(a^2 - b^2)*(b + a*Coth[x])^2) + (2*a*b)/((a^2 - b^2)^2*(b + a*Coth[x])) + (a*(a^2 + 3*b^2)*Log[a*Cosh[x] + b*Sinh[x]])/(a^2 - b^2)^3, -(a/(2*(a^2 - b^2)*(b + a*Coth[x])^2)) + (2*a*b)/((a^2 - b^2)^2*(b + a*Coth[x])) - Log[1 - Coth[x]]/(2*(a + b)^3) - Log[1 + Coth[x]]/(2*(a - b)^3) + (a*(a^2 + 3*b^2)*Log[b + a*Coth[x]])/(a^2 - b^2)^3}


(* Integrands of the form Cosh[x]^m/(a*Cosh[x]+b*Sinh[x])^3 *)
{Cosh[x]/(a*Cosh[x] + b*Sinh[x])^3, x, 3, b/(2*(a^2 - b^2)*(a*Cosh[x] + b*Sinh[x])^2) + Sinh[x]/((a^2 - b^2)*(a*Cosh[x] + b*Sinh[x]))}
(* {Cosh[x]^2/(a*Cosh[x] + b*Sinh[x])^3, x, 0, ((2*a^2 - b^2)*ArcTanh[(-b + a*Tan[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2) - (b*((4*a^2 + b^2)*Cosh[x] + 3*a*b*Sinh[x]))/(2*(a^2 + b^2)^2*(a*Cosh[x] + b*Sinh[x])^2)} *)
{Cosh[x]^3/(a*Cosh[x] + b*Sinh[x])^3, x, 10, (a*(a^2 + 3*b^2)*x)/(a^2 - b^2)^3 - (b*(3*a^2 + b^2)*Log[a*Cosh[x] + b*Sinh[x]])/(a^2 - b^2)^3 + b/(2*(a^2 - b^2)*(a + b*Tanh[x])^2) + (2*a*b)/((a^2 - b^2)^2*(a + b*Tanh[x])), -(Log[1 - Tanh[x]]/(2*(a + b)^3)) + Log[1 + Tanh[x]]/(2*(a - b)^3) - (b*(3*a^2 + b^2)*Log[a + b*Tanh[x]])/(a^2 - b^2)^3 + b/(2*(a^2 - b^2)*(a + b*Tanh[x])^2) + (2*a*b)/((a^2 - b^2)^2*(a + b*Tanh[x]))}


(* ::Subsection::Closed:: *)
(*Integrands of the form Hyper[x]^m / (a+b Hyper[x] + c Hyper[x])*)


{Sinh[x]/(a + b*Cosh[x] + c*Sinh[x]), x, 2, -((c*x)/(b^2 - c^2)) - (2*a*c*ArcTanh[(c - (a - b)*Tanh[x/2])/Sqrt[a^2 - b^2 + c^2]])/((b^2 - c^2)*Sqrt[a^2 - b^2 + c^2]) + (b*Log[a + b*Cosh[x] + c*Sinh[x]])/(b^2 - c^2)}
{Sinh[x]/(1 + Cosh[x] + Sinh[x]), x, 12, x + (1/2)*Log[1 - Tanh[x/2]] - (1/2)*Log[1 + Tanh[x/2]] + 1/(1 + Tanh[x/2])}

{Sech[x]/(a + b*Tanh[x] + c*Sech[x]), x, 2, (2*ArcTan[(b + (a - c)*Tanh[x/2])/Sqrt[a^2 - b^2 - c^2]])/Sqrt[a^2 - b^2 - c^2]}
{Sech[x]^2/(a + b*Tanh[x] + c*Sech[x]), x, 9, (2*c*ArcTan[Tanh[x/2]])/(b^2 + c^2) - (2*a*c*ArcTan[(b + (a - c)*Tanh[x/2])/Sqrt[a^2 - b^2 - c^2]])/(Sqrt[a^2 - b^2 - c^2]*(b^2 + c^2)) - (b*Log[1 + Tanh[x/2]^2])/(b^2 + c^2) + (b*Log[a + c + 2*b*Tanh[x/2] + (a - c)*Tanh[x/2]^2])/(b^2 + c^2)}

{Csch[x]/(2 + 2*Coth[x] + 3*Csch[x]), x, 2, (-(2/3))*ArcTanh[(1/3)*(2 - Tanh[x/2])]}
{Csch[x]/(a + b*Coth[x] + c*Csch[x]), x, 2, -((2*ArcTanh[(a + (b - c)*Tanh[x/2])/Sqrt[a^2 - b^2 + c^2]])/Sqrt[a^2 - b^2 + c^2])}
{Csch[x]^2/(a + b*Coth[x] + c*Csch[x]), x, 8, -((2*a*c*ArcTanh[(a + (b - c)*Tanh[x/2])/Sqrt[a^2 - b^2 + c^2]])/((b^2 - c^2)*Sqrt[a^2 - b^2 + c^2])) + Log[Tanh[x/2]]/(b + c) - (b*Log[b + c + 2*a*Tanh[x/2] + (b - c)*Tanh[x/2]^2])/(b^2 - c^2)}


(* ::Subsection::Closed:: *)
(*Integrands of the form (A + B Hyper[x]) / (a Hyper[x] + b Hyper[x])*)


(* Integrands of the form (A+C*Sinh[x])*(b*Cosh[x]+c*Sinh[x])^n *)
{(A + C*Sinh[x])/(b*Cosh[x] + c*Sinh[x]), x, 2, -((c*C*x)/(b^2 - c^2)) + (2*A*ArcTan[(c + b*Tanh[x/2])/Sqrt[b^2 - c^2]])/Sqrt[b^2 - c^2] + (b*C*Log[b*Cosh[x] + c*Sinh[x]])/(b^2 - c^2)}
{(A + C*Sinh[x])/(b*Cosh[x] + c*Sinh[x])^2, x, 2, -((2*c*C*ArcTan[(c + b*Tanh[x/2])/Sqrt[b^2 - c^2]])/(b^2 - c^2)^(3/2)) - (b*C - A*c*Cosh[x] - A*b*Sinh[x])/((b^2 - c^2)*(b*Cosh[x] + c*Sinh[x]))}
{(A + C*Sinh[x])/(b*Cosh[x] + c*Sinh[x])^3, x, 3, (A*ArcTan[(c + b*Tanh[x/2])/Sqrt[b^2 - c^2]])/(b^2 - c^2)^(3/2) - (b*C - A*c*Cosh[x] - A*b*Sinh[x])/(2*(b^2 - c^2)*(b*Cosh[x] + c*Sinh[x])^2) - (c*C*(c*Cosh[x] + b*Sinh[x]))/((b^2 - c^2)^2*(b*Cosh[x] + c*Sinh[x]))}


(* Integrands of the form (A+B*Cosh[x])*(b*Cosh[x]+c*Sinh[x])^n *)
{(A + B*Cosh[x])/(b*Cosh[x] + c*Sinh[x]), x, 2, (b*B*x)/(b^2 - c^2) + (2*A*ArcTan[(c + b*Tanh[x/2])/Sqrt[b^2 - c^2]])/Sqrt[b^2 - c^2] - (B*c*Log[b*Cosh[x] + c*Sinh[x]])/(b^2 - c^2)}
{(A + B*Cosh[x])/(b*Cosh[x] + c*Sinh[x])^2, x, 2, (2*b*B*ArcTan[(c + b*Tanh[x/2])/Sqrt[b^2 - c^2]])/(b^2 - c^2)^(3/2) + (B*c + A*c*Cosh[x] + A*b*Sinh[x])/((b^2 - c^2)*(b*Cosh[x] + c*Sinh[x]))}
{(A + B*Cosh[x])/(b*Cosh[x] + c*Sinh[x])^3, x, 3, (A*ArcTan[(c + b*Tanh[x/2])/Sqrt[b^2 - c^2]])/(b^2 - c^2)^(3/2) + (B*c + A*c*Cosh[x] + A*b*Sinh[x])/(2*(b^2 - c^2)*(b*Cosh[x] + c*Sinh[x])^2) + (b*B*(c*Cosh[x] + b*Sinh[x]))/((b^2 - c^2)^2*(b*Cosh[x] + c*Sinh[x]))}


(* ::Subsection::Closed:: *)
(*Integrands of the form (A + B Hyper[x]) / (a + b Hyper[x] + c Hyper[x])*)


(* Integrands of the form (A+C*Sinh[x])*(a+b*Cosh[x]+c*Sinh[x])^n *)
{(A + C*Sinh[x])/(a + b*Cosh[x] + c*Sinh[x]), x, 2, -((c*C*x)/(b^2 - c^2)) - (2*(A*(b^2 - c^2) + a*c*C)*ArcTanh[(c - (a - b)*Tanh[x/2])/Sqrt[a^2 - b^2 + c^2]])/((b^2 - c^2)*Sqrt[a^2 - b^2 + c^2]) + (b*C*Log[a + b*Cosh[x] + c*Sinh[x]])/(b^2 - c^2)}
{(A + C*Sinh[x])/(a + b*Cosh[x] + c*Sinh[x])^2, x, 2, -((2*(a*A + c*C)*ArcTanh[(c - (a - b)*Tanh[x/2])/Sqrt[a^2 - b^2 + c^2]])/(a^2 - b^2 + c^2)^(3/2)) + (b*C - (A*c - a*C)*Cosh[x] - A*b*Sinh[x])/((a^2 - b^2 + c^2)*(a + b*Cosh[x] + c*Sinh[x]))}
{(A + C*Sinh[x])/(a + b*Cosh[x] + c*Sinh[x])^3, x, 3, -(((2*a^2*A + A*b^2 - c*(A*c - 3*a*C))*ArcTanh[(c - (a - b)*Tanh[x/2])/Sqrt[a^2 - b^2 + c^2]])/(a^2 - b^2 + c^2)^(5/2)) + (b*C - (A*c - a*C)*Cosh[x] - A*b*Sinh[x])/(2*(a^2 - b^2 + c^2)*(a + b*Cosh[x] + c*Sinh[x])^2) + (a*b*C - (2*c^2*C + a*(3*A*c - a*C))*Cosh[x] - b*(3*a*A + 2*c*C)*Sinh[x])/(2*(a^2 - b^2 + c^2)^2*(a + b*Cosh[x] + c*Sinh[x]))}


(* Integrands of the form (A+B*Cosh[x])*(a+b*Cosh[x]+c*Sinh[x])^n *)
{(A + B*Cosh[x])/(a + b*Cosh[x] + c*Sinh[x]), x, 2, (b*B*x)/(b^2 - c^2) + (2*(a*b*B - A*(b^2 - c^2))*ArcTanh[(c - (a - b)*Tanh[x/2])/Sqrt[a^2 - b^2 + c^2]])/((b^2 - c^2)*Sqrt[a^2 - b^2 + c^2]) - (B*c*Log[a + b*Cosh[x] + c*Sinh[x]])/(b^2 - c^2)}
{(A + B*Cosh[x])/(a + b*Cosh[x] + c*Sinh[x])^2, x, 2, -((2*(a*A - b*B)*ArcTanh[(c - (a - b)*Tanh[x/2])/Sqrt[a^2 - b^2 + c^2]])/(a^2 - b^2 + c^2)^(3/2)) - (B*c + A*c*Cosh[x] + (A*b - a*B)*Sinh[x])/((a^2 - b^2 + c^2)*(a + b*Cosh[x] + c*Sinh[x]))}
{(A + B*Cosh[x])/(a + b*Cosh[x] + c*Sinh[x])^3, x, 3, -(((2*a^2*A + b*(A*b - 3*a*B) - A*c^2)*ArcTanh[(c - (a - b)*Tanh[x/2])/Sqrt[a^2 - b^2 + c^2]])/(a^2 - b^2 + c^2)^(5/2)) - (B*c + A*c*Cosh[x] + (A*b - a*B)*Sinh[x])/(2*(a^2 - b^2 + c^2)*(a + b*Cosh[x] + c*Sinh[x])^2) - (a*B*c + (3*a*A - 2*b*B)*c*Cosh[x] - (2*b^2*B - a*(3*A*b - a*B))*Sinh[x])/(2*(a^2 - b^2 + c^2)^2*(a + b*Cosh[x] + c*Sinh[x]))}


(* ::Subsection::Closed:: *)
(*Miscellaneous rational functions of three hyperbolic functions*)


(* Integrands of the form Sinh[x]^m/(a+b*Sinh[x]*c*Sinh[x]^2) where m is an integer *)
{1/(a + b*Sinh[x] + c*Sinh[x]^2), x, 3, -((4*c*ArcTanh[(2*c - (b - Sqrt[b^2 - 4*a*c])*Tanh[x/2])/Sqrt[4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]])/(Sqrt[b^2 - 4*a*c]*Sqrt[4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2])) + (4*c*ArcTanh[(2*c - (b + Sqrt[b^2 - 4*a*c])*Tanh[x/2])/Sqrt[4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]])/(Sqrt[b^2 - 4*a*c]*Sqrt[4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2])}
{Sinh[x]/(a + b*Sinh[x] + c*Sinh[x]^2), x, 3, -((2*(1 - b/Sqrt[b^2 - 4*a*c])*ArcTanh[(2*c - (b - Sqrt[b^2 - 4*a*c])*Tanh[x/2])/Sqrt[4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]])/Sqrt[4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]) - (2*(1 + b/Sqrt[b^2 - 4*a*c])*ArcTanh[(2*c - (b + Sqrt[b^2 - 4*a*c])*Tanh[x/2])/Sqrt[4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]])/Sqrt[4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]}
{Sinh[x]^2/(a + b*Sinh[x] + c*Sinh[x]^2), x, 5, x/c + (2*(b - (b^2 - 2*a*c)/Sqrt[b^2 - 4*a*c])*ArcTanh[(2*c - (b - Sqrt[b^2 - 4*a*c])*Tanh[x/2])/Sqrt[4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]])/(c*Sqrt[4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]) + (2*(b + (b^2 - 2*a*c)/Sqrt[b^2 - 4*a*c])*ArcTanh[(2*c - (b + Sqrt[b^2 - 4*a*c])*Tanh[x/2])/Sqrt[4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]])/(c*Sqrt[4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2])}
{Sinh[x]^3/(a + b*Sinh[x] + c*Sinh[x]^2), x, 6, -((b*x)/c^2) - (2*(b^2 - a*c - (b*(b^2 - 3*a*c))/Sqrt[b^2 - 4*a*c])*ArcTanh[(2*c - (b - Sqrt[b^2 - 4*a*c])*Tanh[x/2])/Sqrt[4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]])/(c^2*Sqrt[4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]) - (2*(b^2 - a*c + (b*(b^2 - 3*a*c))/Sqrt[b^2 - 4*a*c])*ArcTanh[(2*c - (b + Sqrt[b^2 - 4*a*c])*Tanh[x/2])/Sqrt[4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]])/(c^2*Sqrt[4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]) + Cosh[x]/c}

{(a + b*Sinh[x])/(b^2 - 2*a*b*Sinh[x] + a^2*Sinh[x]^2), x, 2, Cosh[x]/(b - a*Sinh[x])}
{(d + e*Sinh[x])/(a + b*Sinh[x] + c*Sinh[x]^2), x, 3, -((2*(e + (2*c*d - b*e)/Sqrt[b^2 - 4*a*c])*ArcTanh[(2*c - (b - Sqrt[b^2 - 4*a*c])*Tanh[x/2])/Sqrt[4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]])/Sqrt[4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]) - (2*(e - (2*c*d - b*e)/Sqrt[b^2 - 4*a*c])*ArcTanh[(2*c - (b + Sqrt[b^2 - 4*a*c])*Tanh[x/2])/Sqrt[4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]])/Sqrt[4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]}


(* Integrands of the form Cosh[x]^m/(a+b*Cosh[x]*c*Cosh[x]^2) where m is an integer *)
{1/(a + b*Cosh[x] + c*Cosh[x]^2), x, 3, (4*c*ArcTanh[((b - 2*c - Sqrt[b^2 - 4*a*c])*Tanh[x/2])/Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]])/(Sqrt[b^2 - 4*a*c]*Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]) - (4*c*ArcTanh[((b - 2*c + Sqrt[b^2 - 4*a*c])*Tanh[x/2])/Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]])/(Sqrt[b^2 - 4*a*c]*Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2])}
{Cosh[x]/(a + b*Cosh[x] + c*Cosh[x]^2), x, 3, (2*(1 - b/Sqrt[b^2 - 4*a*c])*ArcTanh[((b - 2*c - Sqrt[b^2 - 4*a*c])*Tanh[x/2])/Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]])/Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2] + (2*(1 + b/Sqrt[b^2 - 4*a*c])*ArcTanh[((b - 2*c + Sqrt[b^2 - 4*a*c])*Tanh[x/2])/Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]])/Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]}
{Cosh[x]^2/(a + b*Cosh[x] + c*Cosh[x]^2), x, 5, x/c - (2*(b - (b^2 - 2*a*c)/Sqrt[b^2 - 4*a*c])*ArcTanh[((b - 2*c - Sqrt[b^2 - 4*a*c])*Tanh[x/2])/Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]])/(c*Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]) - (2*(b + (b^2 - 2*a*c)/Sqrt[b^2 - 4*a*c])*ArcTanh[((b - 2*c + Sqrt[b^2 - 4*a*c])*Tanh[x/2])/Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]])/(c*Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2])}
{Cosh[x]^3/(a + b*Cosh[x] + c*Cosh[x]^2), x, 6, -((b*x)/c^2) + (2*(b^2 - a*c - (b*(b^2 - 3*a*c))/Sqrt[b^2 - 4*a*c])*ArcTanh[((b - 2*c - Sqrt[b^2 - 4*a*c])*Tanh[x/2])/Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]])/(c^2*Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]) + (2*(b^2 - a*c + (b*(b^2 - 3*a*c))/Sqrt[b^2 - 4*a*c])*ArcTanh[((b - 2*c + Sqrt[b^2 - 4*a*c])*Tanh[x/2])/Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]])/(c^2*Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]) + Sinh[x]/c}

{(a + b*Cosh[x])/(b^2 + 2*a*b*Cosh[x] + a^2*Cosh[x]^2), x, 2, Sinh[x]/(b + a*Cosh[x])}
{(d + e*Cosh[x])/(a + b*Cosh[x] + c*Cosh[x]^2), x, 3, (2*(e + (2*c*d - b*e)/Sqrt[b^2 - 4*a*c])*ArcTanh[((b - 2*c - Sqrt[b^2 - 4*a*c])*Tanh[x/2])/Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2]])/Sqrt[-4*c^2 + (b - Sqrt[b^2 - 4*a*c])^2] + (2*(e - (2*c*d - b*e)/Sqrt[b^2 - 4*a*c])*ArcTanh[((b - 2*c + Sqrt[b^2 - 4*a*c])*Tanh[x/2])/Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]])/Sqrt[-4*c^2 + (b + Sqrt[b^2 - 4*a*c])^2]}


(* Integrands of the form Hyper[x]^n/(a*Hyper[x]^n+b*Hyper[x]^n) *)
{Sinh[x]^2/(a*Cosh[x]^2 + b*Sinh[x]^2), x, 2, x/(a + b) + (Sqrt[a]*ArcTan[(Sqrt[a]*Coth[x])/Sqrt[b]])/(Sqrt[b]*(a + b))}
{Cosh[x]^2/(a*Cosh[x]^2 + b*Sinh[x]^2), x, 2, x/(a + b) + (Sqrt[b]*ArcTan[(Sqrt[b]*Tanh[x])/Sqrt[a]])/(Sqrt[a]*(a + b))}

{Sinh[x]^3/(Cosh[x]^3 + Sinh[x]^3), x, 7, x/2 - (2*ArcTan[(1 - 2*Coth[x])/Sqrt[3]])/(3*Sqrt[3]) - 1/(6*(1 + Coth[x])), -((2*ArcTan[(1 - 2*Coth[x])/Sqrt[3]])/(3*Sqrt[3])) - 1/(6*(1 + Coth[x])) - (1/2)*I*Pi*Mods[1/2 + (I*x)/Pi]}
{Cosh[x]^3/(Cosh[x]^3 + Sinh[x]^3), x, 7, x/2 - (2*ArcTan[(1 - 2*Tanh[x])/Sqrt[3]])/(3*Sqrt[3]) - 1/(6*(1 + Tanh[x])), -((2*ArcTan[(1 - 2*Tanh[x])/Sqrt[3]])/(3*Sqrt[3])) + (1/2)*I*Pi*Mods[-((I*x)/Pi)] - 1/(6*(1 + Tanh[x]))}


{(x*Cosh[x] - Sinh[x])/(x - Sinh[x])^2, x, -7, x/(x - Sinh[x])}
(* Nonidempotent expansion results in infinite recursion: *) 
(* {(-Cosh[x] + x*Sinh[x])/(x - Cosh[x])^2, x, 0, x/(x - Cosh[x])} *)


(* ::Subsection::Closed:: *)
(*Miscellaneous algebraic functions of three hyperbolic functions*)


{Tanh[x]^5/Sqrt[a + b*Tanh[x]^2 + c*Tanh[x]^4], x, 9, (b*ArcTanh[(b + 2*c*Tanh[x]^2)/(2*Sqrt[c]*Sqrt[a + b*Tanh[x]^2 + c*Tanh[x]^4])])/(4*c^(3/2)) - ArcTanh[(b + 2*c*Tanh[x]^2)/(2*Sqrt[c]*Sqrt[a + b*Tanh[x]^2 + c*Tanh[x]^4])]/(2*Sqrt[c]) + ArcTanh[(2*a + b + (b + 2*c)*Tanh[x]^2)/(2*Sqrt[a + b + c]*Sqrt[a + b*Tanh[x]^2 + c*Tanh[x]^4])]/(2*Sqrt[a + b + c]) - Sqrt[a + b*Tanh[x]^2 + c*Tanh[x]^4]/(2*c)}
{Tanh[x]^3/Sqrt[a + b*Tanh[x]^2 + c*Tanh[x]^4], x, 7, -(ArcTanh[(b + 2*c*Tanh[x]^2)/(2*Sqrt[c]*Sqrt[a + b*Tanh[x]^2 + c*Tanh[x]^4])]/(2*Sqrt[c])) + ArcTanh[(2*a + b + (b + 2*c)*Tanh[x]^2)/(2*Sqrt[a + b + c]*Sqrt[a + b*Tanh[x]^2 + c*Tanh[x]^4])]/(2*Sqrt[a + b + c])}
{Tanh[x]/Sqrt[a + b*Tanh[x]^2 + c*Tanh[x]^4], x, 4, ArcTanh[(2*a + b + (b + 2*c)*Tanh[x]^2)/(2*Sqrt[a + b + c]*Sqrt[a + b*Tanh[x]^2 + c*Tanh[x]^4])]/(2*Sqrt[a + b + c])}
{Coth[x]/Sqrt[a + b*Tanh[x]^2 + c*Tanh[x]^4], x, 6, -(ArcTanh[(2*a + b*Tanh[x]^2)/(2*Sqrt[a]*Sqrt[a + b*Tanh[x]^2 + c*Tanh[x]^4])]/(2*Sqrt[a])) + ArcTanh[(2*a + b + (b + 2*c)*Tanh[x]^2)/(2*Sqrt[a + b + c]*Sqrt[a + b*Tanh[x]^2 + c*Tanh[x]^4])]/(2*Sqrt[a + b + c])}
{Coth[x]^3/Sqrt[a + b*Tanh[x]^2 + c*Tanh[x]^4], x, 9, -(ArcTanh[(2*a + b*Tanh[x]^2)/(2*Sqrt[a]*Sqrt[a + b*Tanh[x]^2 + c*Tanh[x]^4])]/(2*Sqrt[a])) + (b*ArcTanh[(2*a + b*Tanh[x]^2)/(2*Sqrt[a]*Sqrt[a + b*Tanh[x]^2 + c*Tanh[x]^4])])/(4*a^(3/2)) + ArcTanh[(2*a + b + (b + 2*c)*Tanh[x]^2)/(2*Sqrt[a + b + c]*Sqrt[a + b*Tanh[x]^2 + c*Tanh[x]^4])]/(2*Sqrt[a + b + c]) - (Coth[x]^2*Sqrt[a + b*Tanh[x]^2 + c*Tanh[x]^4])/(2*a)}


{Coth[x]^5/Sqrt[a + b*Coth[x]^2 + c*Coth[x]^4], x, 9, (b*ArcTanh[(b + 2*c*Coth[x]^2)/(2*Sqrt[c]*Sqrt[a + b*Coth[x]^2 + c*Coth[x]^4])])/(4*c^(3/2)) - ArcTanh[(b + 2*c*Coth[x]^2)/(2*Sqrt[c]*Sqrt[a + b*Coth[x]^2 + c*Coth[x]^4])]/(2*Sqrt[c]) + ArcTanh[(2*a + b + (b + 2*c)*Coth[x]^2)/(2*Sqrt[a + b + c]*Sqrt[a + b*Coth[x]^2 + c*Coth[x]^4])]/(2*Sqrt[a + b + c]) - Sqrt[a + b*Coth[x]^2 + c*Coth[x]^4]/(2*c)}
{Coth[x]^3/Sqrt[a + b*Coth[x]^2 + c*Coth[x]^4], x, 7, -(ArcTanh[(b + 2*c*Coth[x]^2)/(2*Sqrt[c]*Sqrt[a + b*Coth[x]^2 + c*Coth[x]^4])]/(2*Sqrt[c])) + ArcTanh[(2*a + b + (b + 2*c)*Coth[x]^2)/(2*Sqrt[a + b + c]*Sqrt[a + b*Coth[x]^2 + c*Coth[x]^4])]/(2*Sqrt[a + b + c])}
{Coth[x]/Sqrt[a + b*Coth[x]^2 + c*Coth[x]^4], x, 4, ArcTanh[(2*a + b + (b + 2*c)*Coth[x]^2)/(2*Sqrt[a + b + c]*Sqrt[a + b*Coth[x]^2 + c*Coth[x]^4])]/(2*Sqrt[a + b + c])}
{Tanh[x]/Sqrt[a + b*Coth[x]^2 + c*Coth[x]^4], x, 6, -(ArcTanh[(2*a + b*Coth[x]^2)/(2*Sqrt[a]*Sqrt[a + b*Coth[x]^2 + c*Coth[x]^4])]/(2*Sqrt[a])) + ArcTanh[(2*a + b + (b + 2*c)*Coth[x]^2)/(2*Sqrt[a + b + c]*Sqrt[a + b*Coth[x]^2 + c*Coth[x]^4])]/(2*Sqrt[a + b + c])}
{Tanh[x]^3/Sqrt[a + b*Coth[x]^2 + c*Coth[x]^4], x, 9, -(ArcTanh[(2*a + b*Coth[x]^2)/(2*Sqrt[a]*Sqrt[a + b*Coth[x]^2 + c*Coth[x]^4])]/(2*Sqrt[a])) + (b*ArcTanh[(2*a + b*Coth[x]^2)/(2*Sqrt[a]*Sqrt[a + b*Coth[x]^2 + c*Coth[x]^4])])/(4*a^(3/2)) + ArcTanh[(2*a + b + (b + 2*c)*Coth[x]^2)/(2*Sqrt[a + b + c]*Sqrt[a + b*Coth[x]^2 + c*Coth[x]^4])]/(2*Sqrt[a + b + c]) - (Sqrt[a + b*Coth[x]^2 + c*Coth[x]^4]*Tanh[x]^2)/(2*a)}


(* {Tanh[x]^5*Sqrt[a + b*Tanh[x]^2 + c*Tanh[x]^4], x, 0, 0} *)
(* {Tanh[x]^3*Sqrt[a + b*Tanh[x]^2 + c*Tanh[x]^4], x, 0, 0} *)
{Tanh[x]*Sqrt[a + b*Tanh[x]^2 + c*Tanh[x]^4], x, 6, -(((b + 2*c)*ArcTanh[(b + 2*c*Tanh[x]^2)/(2*Sqrt[c]*Sqrt[a + b*Tanh[x]^2 + c*Tanh[x]^4])])/(4*Sqrt[c])) + (1/2)*Sqrt[a + b + c]*ArcTanh[(2*a + b + (b + 2*c)*Tanh[x]^2)/(2*Sqrt[a + b + c]*Sqrt[a + b*Tanh[x]^2 + c*Tanh[x]^4])] - (1/2)*Sqrt[a + b*Tanh[x]^2 + c*Tanh[x]^4]}
(* {Coth[x]*Sqrt[a + b*Tanh[x]^2 + c*Tanh[x]^4], x, 0, 0} *)
(* {Coth[x]^3*Sqrt[a + b*Tanh[x]^2 + c*Tanh[x]^4], x, 0, 0} *)


(* {Coth[x]^5*Sqrt[a + b*Coth[x]^2 + c*Coth[x]^4], x, 0, 0} *)
(* {Coth[x]^3*Sqrt[a + b*Coth[x]^2 + c*Coth[x]^4], x, 0, 0} *)
{Coth[x]*Sqrt[a + b*Coth[x]^2 + c*Coth[x]^4], x, 6, -(((b + 2*c)*ArcTanh[(b + 2*c*Coth[x]^2)/(2*Sqrt[c]*Sqrt[a + b*Coth[x]^2 + c*Coth[x]^4])])/(4*Sqrt[c])) + (1/2)*Sqrt[a + b + c]*ArcTanh[(2*a + b + (b + 2*c)*Coth[x]^2)/(2*Sqrt[a + b + c]*Sqrt[a + b*Coth[x]^2 + c*Coth[x]^4])] - (1/2)*Sqrt[a + b*Coth[x]^2 + c*Coth[x]^4]}
(* {Tanh[x]*Sqrt[a + b*Coth[x]^2 + c*Coth[x]^4], x, 0, 0} *)
(* {Tanh[x]^3*Sqrt[a + b*Coth[x]^2 + c*Coth[x]^4], x, 0, 0} *)


{(x^1*Csch[x]*Sech[x])/Sqrt[a*Sech[x]^2], x, 5, -(((2*x*ArcTanh[E^x] + PolyLog[2, -E^x] - PolyLog[2, E^x])*Sech[x])/Sqrt[a*Sech[x]^2])}
{(x^2*Csch[x]*Sech[x])/Sqrt[a*Sech[x]^2], x, 7, -((2*(x^2*ArcTanh[E^x] + x*PolyLog[2, -E^x] - x*PolyLog[2, E^x] - PolyLog[3, -E^x] + PolyLog[3, E^x])*Sech[x])/Sqrt[a*Sech[x]^2])}
{(x^3*Csch[x]*Sech[x])/Sqrt[a*Sech[x]^2], x, 9, -(((2*x^3*ArcTanh[E^x] + 3*x^2*PolyLog[2, -E^x] - 3*x^2*PolyLog[2, E^x] - 6*x*PolyLog[3, -E^x] + 6*x*PolyLog[3, E^x] + 6*PolyLog[4, -E^x] - 6*PolyLog[4, E^x])*Sech[x])/Sqrt[a*Sech[x]^2])}


{(x^1*Csch[x]*Sech[x])/Sqrt[a*Sech[x]^4], x, 5, -(((x^2 - 2*x*Log[1 - E^(2*x)] - PolyLog[2, E^(2*x)])*Sech[x]^2)/(2*Sqrt[a*Sech[x]^4]))}
{(x^2*Csch[x]*Sech[x])/Sqrt[a*Sech[x]^4], x, 6, -(((2*x^3 - 6*x^2*Log[1 - E^(2*x)] - 6*x*PolyLog[2, E^(2*x)] + 3*PolyLog[3, E^(2*x)])*Sech[x]^2)/(6*Sqrt[a*Sech[x]^4]))}
{(x^3*Csch[x]*Sech[x])/Sqrt[a*Sech[x]^4], x, 7, -(((x^4 - 4*x^3*Log[1 - E^(2*x)] - 6*x^2*PolyLog[2, E^(2*x)] + 6*x*PolyLog[3, E^(2*x)] - 3*PolyLog[4, E^(2*x)])*Sech[x]^2)/(4*Sqrt[a*Sech[x]^4]))}


{(x^1*Csch[x]*Sech[x])*Sqrt[a*Sech[x]^2], x, 10, (-Cosh[x])*Sqrt[a*Sech[x]^2]*(ArcTan[Sinh[x]] + 2*x*ArcTanh[E^x] + PolyLog[2, -E^x] - PolyLog[2, E^x] - x*Sech[x])}
{(x^2*Csch[x]*Sech[x])*Sqrt[a*Sech[x]^2], x, 16, (-Cosh[x])*Sqrt[a*Sech[x]^2]*(4*x*ArcTan[E^x] + 2*x^2*ArcTanh[E^x] + 2*x*PolyLog[2, -E^x] - 2*I*PolyLog[2, (-I)*E^x] + 2*I*PolyLog[2, I*E^x] - 2*x*PolyLog[2, E^x] - 2*PolyLog[3, -E^x] + 2*PolyLog[3, E^x] - x^2*Sech[x])}
{(x^3*Csch[x]*Sech[x])*Sqrt[a*Sech[x]^2], x, 20, (-Cosh[x])*Sqrt[a*Sech[x]^2]*(6*x^2*ArcTan[E^x] + 2*x^3*ArcTanh[E^x] + 3*x^2*PolyLog[2, -E^x] - 6*I*x*PolyLog[2, (-I)*E^x] + 6*I*x*PolyLog[2, I*E^x] - 3*x^2*PolyLog[2, E^x] - 6*x*PolyLog[3, -E^x] + 6*I*PolyLog[3, (-I)*E^x] - 6*I*PolyLog[3, I*E^x] + 6*x*PolyLog[3, E^x] + 6*PolyLog[4, -E^x] - 6*PolyLog[4, E^x] - x^3*Sech[x])}


{(x^1*Csch[x]*Sech[x])*Sqrt[a*Sech[x]^4], x, 10, (-(1/2))*Cosh[x]^2*Sqrt[a*Sech[x]^4]*(4*x*ArcTanh[E^(2*x)] + PolyLog[2, -E^(2*x)] - PolyLog[2, E^(2*x)] - x*Sech[x]^2 + Tanh[x])}
{(x^2*Csch[x]*Sech[x])*Sqrt[a*Sech[x]^4], x, 15, (-(1/2))*Cosh[x]^2*Sqrt[a*Sech[x]^4]*(4*x^2*ArcTanh[E^(2*x)] - 2*Log[Cosh[x]] + 2*x*PolyLog[2, -E^(2*x)] - 2*x*PolyLog[2, E^(2*x)] - PolyLog[3, -E^(2*x)] + PolyLog[3, E^(2*x)] - x^2*Sech[x]^2 + 2*x*Tanh[x])}
{(x^3*Csch[x]*Sech[x])*Sqrt[a*Sech[x]^4], x, 20, (-(1/4))*Cosh[x]^2*Sqrt[a*Sech[x]^4]*(6*x^2 + 8*x^3*ArcTanh[E^(2*x)] - 12*x*Log[1 + E^(2*x)] - 6*(1 - x^2)*PolyLog[2, -E^(2*x)] - 6*x^2*PolyLog[2, E^(2*x)] - 6*x*PolyLog[3, -E^(2*x)] + 6*x*PolyLog[3, E^(2*x)] + 3*PolyLog[4, -E^(2*x)] - 3*PolyLog[4, E^(2*x)] - 2*x^3*Sech[x]^2 + 6*x^2*Tanh[x])}


(* ::Section:: *)
(*Integrands involving four hyperbolic functions*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Hyper[x]^m Hyper[x]^n / (a Hyper[x] + b Hyper[x])^n*)


(* Integrands of the form Cosh[x]^m*Sinh[x]^n/(a*Cosh[x]+b*Sinh[x]) where m and n are integers *)
{Cosh[x]*Sinh[x]/(a*Cosh[x] + b*Sinh[x]), x, 4, (2*a*b*ArcTan[(b + a*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(3/2) + (a*Cosh[x])/(a^2 - b^2) - (b*Sinh[x])/(a^2 - b^2)}
{Cosh[x]*Sinh[x]^2/(a*Cosh[x] + b*Sinh[x]), x, 5, -((a*b^2*x)/(a^2 - b^2)^2) - (a*x)/(2*(a^2 - b^2)) + (a^2*b*Log[a*Cosh[x] + b*Sinh[x]])/(a^2 - b^2)^2 + (a*Cosh[x]*Sinh[x])/(2*(a^2 - b^2)) - (b*Sinh[x]^2)/(2*(a^2 - b^2))}
{Cosh[x]*Sinh[x]^3/(a*Cosh[x] + b*Sinh[x]), x, 9, -((2*a^3*b*ArcTan[(b + a*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(5/2)) - (a*b^2*Cosh[x])/(a^2 - b^2)^2 - (a*Cosh[x])/(a^2 - b^2) + (a*Cosh[x]^3)/(3*(a^2 - b^2)) + (a^2*b*Sinh[x])/(a^2 - b^2)^2 - (b*Sinh[x]^3)/(3*(a^2 - b^2))}

{Cosh[x]^2*Sinh[x]/(a*Cosh[x] + b*Sinh[x]), x, 5, (a^2*b*x)/(a^2 - b^2)^2 - (b*x)/(2*(a^2 - b^2)) - (a*b^2*Log[a*Cosh[x] + b*Sinh[x]])/(a^2 - b^2)^2 - (b*Cosh[x]*Sinh[x])/(2*(a^2 - b^2)) + (a*Sinh[x]^2)/(2*(a^2 - b^2))}
{Cosh[x]^2*Sinh[x]^2/(a*Cosh[x] + b*Sinh[x]), x, 9, (2*a^2*b^2*ArcTan[(b + a*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(5/2) + (a^2*b*Cosh[x])/(a^2 - b^2)^2 - (b*Cosh[x]^3)/(3*(a^2 - b^2)) - (a*b^2*Sinh[x])/(a^2 - b^2)^2 + (a*Sinh[x]^3)/(3*(a^2 - b^2))}
{Cosh[x]^2*Sinh[x]^3/(a*Cosh[x] + b*Sinh[x]), x, 10, -((a^2*b^3*x)/(a^2 - b^2)^3) - (a^2*b*x)/(2*(a^2 - b^2)^2) + (b*x)/(8*(a^2 - b^2)) + (a^3*b^2*Log[a*Cosh[x] + b*Sinh[x]])/(a^2 - b^2)^3 + (a^2*b*Cosh[x]*Sinh[x])/(2*(a^2 - b^2)^2) + (b*Cosh[x]*Sinh[x])/(8*(a^2 - b^2)) - (b*Cosh[x]^3*Sinh[x])/(4*(a^2 - b^2)) - (a*b^2*Sinh[x]^2)/(2*(a^2 - b^2)^2) + (a*Sinh[x]^4)/(4*(a^2 - b^2))}

{Cosh[x]^3*Sinh[x]/(a*Cosh[x] + b*Sinh[x]), x, 9, -((2*a*b^3*ArcTan[(b + a*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(5/2)) - (a*b^2*Cosh[x])/(a^2 - b^2)^2 + (a*Cosh[x]^3)/(3*(a^2 - b^2)) + (a^2*b*Sinh[x])/(a^2 - b^2)^2 - (b*Sinh[x])/(a^2 - b^2) - (b*Sinh[x]^3)/(3*(a^2 - b^2))}
{Cosh[x]^3*Sinh[x]^2/(a*Cosh[x] + b*Sinh[x]), x, 10, (a^3*b^2*x)/(a^2 - b^2)^3 - (a*b^2*x)/(2*(a^2 - b^2)^2) - (a*x)/(8*(a^2 - b^2)) - (b*Cosh[x]^4)/(4*(a^2 - b^2)) - (a^2*b^3*Log[a*Cosh[x] + b*Sinh[x]])/(a^2 - b^2)^3 - (a*b^2*Cosh[x]*Sinh[x])/(2*(a^2 - b^2)^2) - (a*Cosh[x]*Sinh[x])/(8*(a^2 - b^2)) + (a*Cosh[x]^3*Sinh[x])/(4*(a^2 - b^2)) + (a^2*b*Sinh[x]^2)/(2*(a^2 - b^2)^2)}
{Cosh[x]^3*Sinh[x]^3/(a*Cosh[x] + b*Sinh[x]), x, 16, (2*a^3*b^3*ArcTan[(b + a*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(7/2) + (a^3*b^2*Cosh[x])/(a^2 - b^2)^3 - (a*b^2*Cosh[x]^3)/(3*(a^2 - b^2)^2) - (a*Cosh[x]^3)/(3*(a^2 - b^2)) + (a*Cosh[x]^5)/(5*(a^2 - b^2)) - (a^2*b^3*Sinh[x])/(a^2 - b^2)^3 + (a^2*b*Sinh[x]^3)/(3*(a^2 - b^2)^2) - (b*Sinh[x]^3)/(3*(a^2 - b^2)) - (b*Sinh[x]^5)/(5*(a^2 - b^2))}


(* Integrands of the form Cosh[x]^m*Sinh[x]^n/(a*Cosh[x]+b*Sinh[x])^2 where m and n are integers *)
{Cosh[x]*Sinh[x]/(a*Cosh[x] + b*Sinh[x])^2, x, 4, -((2*a*b*x)/(a^2 - b^2)^2) + (a^2*Log[a*Cosh[x] + b*Sinh[x]])/(a^2 - b^2)^2 + (b^2*Log[a*Cosh[x] + b*Sinh[x]])/(a^2 - b^2)^2 + (b*Sinh[x])/((a^2 - b^2)*(a*Cosh[x] + b*Sinh[x]))}
{Cosh[x]*Sinh[x]^2/(a*Cosh[x] + b*Sinh[x])^2, x, 11, -((2*a^3*ArcTan[(b + a*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(5/2)) - (4*a*b^2*ArcTan[(b + a*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(5/2) - (2*a*b*Cosh[x])/(a^2 - b^2)^2 + (a^2*Sinh[x])/(a^2 - b^2)^2 + (b^2*Sinh[x])/(a^2 - b^2)^2 - (a^2*b)/((a^2 - b^2)^2*(a*Cosh[x] + b*Sinh[x]))}
{Cosh[x]*Sinh[x]^3/(a*Cosh[x] + b*Sinh[x])^2, x, 20, (a^3*b*x)/(a^2 - b^2)^3 + (a*b^3*x)/(a^2 - b^2)^3 + (a*b*x)/(a^2 - b^2)^2 - (a^2*b)/((a^2 - b^2)^2*(b + a*Coth[x])) - (a*b*Log[1 - Coth[x]])/(2*(a + b)^2*(a^2 - b^2)) + (a*b*Log[1 + Coth[x]])/(2*(a - b)^2*(a^2 - b^2)) - (2*a^2*b^2*Log[b + a*Coth[x]])/(a^2 - b^2)^3 - (a^4*Log[a*Cosh[x] + b*Sinh[x]])/(a^2 - b^2)^3 - (a^2*b^2*Log[a*Cosh[x] + b*Sinh[x]])/(a^2 - b^2)^3 - (a*b*Cosh[x]*Sinh[x])/(a^2 - b^2)^2 + (a^2*Sinh[x]^2)/(2*(a^2 - b^2)^2) + (b^2*Sinh[x]^2)/(2*(a^2 - b^2)^2)}

{Cosh[x]^2*Sinh[x]/(a*Cosh[x] + b*Sinh[x])^2, x, 11, (4*a^2*b*ArcTan[(b + a*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(5/2) + (2*b^3*ArcTan[(b + a*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(5/2) + (a^2*Cosh[x])/(a^2 - b^2)^2 + (b^2*Cosh[x])/(a^2 - b^2)^2 - (2*a*b*Sinh[x])/(a^2 - b^2)^2 + (a*b^2)/((a^2 - b^2)^2*(a*Cosh[x] + b*Sinh[x]))}
{Cosh[x]^2*Sinh[x]^2/(a*Cosh[x] + b*Sinh[x])^2, x, 15, -((4*a^2*b^2*x)/(a^2 - b^2)^3) - (a^2*x)/(2*(a^2 - b^2)^2) + (b^2*x)/(2*(a^2 - b^2)^2) + (2*a^3*b*Log[a*Cosh[x] + b*Sinh[x]])/(a^2 - b^2)^3 + (2*a*b^3*Log[a*Cosh[x] + b*Sinh[x]])/(a^2 - b^2)^3 + (a^2*Cosh[x]*Sinh[x])/(2*(a^2 - b^2)^2) + (b^2*Cosh[x]*Sinh[x])/(2*(a^2 - b^2)^2) - (a*b*Sinh[x]^2)/(a^2 - b^2)^2 + (a*b^2*Sinh[x])/((a^2 - b^2)^2*(a*Cosh[x] + b*Sinh[x]))}
{Cosh[x]^2*Sinh[x]^3/(a*Cosh[x] + b*Sinh[x])^2, x, 30, -((4*a^4*b*ArcTan[(b + a*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(7/2)) - (6*a^2*b^3*ArcTan[(b + a*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(7/2) - (4*a^2*b^2*Cosh[x])/(a^2 - b^2)^3 - (a^2*Cosh[x])/(a^2 - b^2)^2 + (a^2*Cosh[x]^3)/(3*(a^2 - b^2)^2) + (b^2*Cosh[x]^3)/(3*(a^2 - b^2)^2) + (2*a^3*b*Sinh[x])/(a^2 - b^2)^3 + (2*a*b^3*Sinh[x])/(a^2 - b^2)^3 - (2*a*b*Sinh[x]^3)/(3*(a^2 - b^2)^2) - (a^3*b^2)/((a^2 - b^2)^3*(a*Cosh[x] + b*Sinh[x]))}

{Cosh[x]^3*Sinh[x]/(a*Cosh[x] + b*Sinh[x])^2, x, 20, (a^3*b*x)/(a^2 - b^2)^3 + (a*b^3*x)/(a^2 - b^2)^3 - (a*b*x)/(a^2 - b^2)^2 - (a^2*b^2*Log[a*Cosh[x] + b*Sinh[x]])/(a^2 - b^2)^3 - (b^4*Log[a*Cosh[x] + b*Sinh[x]])/(a^2 - b^2)^3 - (a*b*Log[1 - Tanh[x]])/(2*(a + b)^2*(a^2 - b^2)) + (a*b*Log[1 + Tanh[x]])/(2*(a - b)^2*(a^2 - b^2)) - (2*a^2*b^2*Log[a + b*Tanh[x]])/(a^2 - b^2)^3 - (a*b*Cosh[x]*Sinh[x])/(a^2 - b^2)^2 + (a^2*Sinh[x]^2)/(2*(a^2 - b^2)^2) + (b^2*Sinh[x]^2)/(2*(a^2 - b^2)^2) + (a*b^2)/((a^2 - b^2)^2*(a + b*Tanh[x]))}
{Cosh[x]^3*Sinh[x]^2/(a*Cosh[x] + b*Sinh[x])^2, x, 30, (6*a^3*b^2*ArcTan[(b + a*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(7/2) + (4*a*b^4*ArcTan[(b + a*Tanh[x/2])/Sqrt[a^2 - b^2]])/(a^2 - b^2)^(7/2) + (2*a^3*b*Cosh[x])/(a^2 - b^2)^3 + (2*a*b^3*Cosh[x])/(a^2 - b^2)^3 - (2*a*b*Cosh[x]^3)/(3*(a^2 - b^2)^2) - (4*a^2*b^2*Sinh[x])/(a^2 - b^2)^3 + (b^2*Sinh[x])/(a^2 - b^2)^2 + (a^2*Sinh[x]^3)/(3*(a^2 - b^2)^2) + (b^2*Sinh[x]^3)/(3*(a^2 - b^2)^2) + (a^2*b^3)/((a^2 - b^2)^3*(a*Cosh[x] + b*Sinh[x]))}
{Cosh[x]^3*Sinh[x]^3/(a*Cosh[x] + b*Sinh[x])^2, x, 36, -((6*a^3*b^3*x)/(a^2 - b^2)^4) - (a^3*b*x)/(a^2 - b^2)^3 + (a*b^3*x)/(a^2 - b^2)^3 + (a*b*x)/(4*(a^2 - b^2)^2) + (b^2*Cosh[x]^4)/(4*(a^2 - b^2)^2) + (3*a^4*b^2*Log[a*Cosh[x] + b*Sinh[x]])/(a^2 - b^2)^4 + (3*a^2*b^4*Log[a*Cosh[x] + b*Sinh[x]])/(a^2 - b^2)^4 + (a^3*b*Cosh[x]*Sinh[x])/(a^2 - b^2)^3 + (a*b^3*Cosh[x]*Sinh[x])/(a^2 - b^2)^3 + (a*b*Cosh[x]*Sinh[x])/(4*(a^2 - b^2)^2) - (a*b*Cosh[x]^3*Sinh[x])/(2*(a^2 - b^2)^2) - (2*a^2*b^2*Sinh[x]^2)/(a^2 - b^2)^3 + (a^2*Sinh[x]^4)/(4*(a^2 - b^2)^2) + (a^2*b^3*Sinh[x])/((a^2 - b^2)^3*(a*Cosh[x] + b*Sinh[x]))}


(* ::Subsection::Closed:: *)
(*Integrands of the form (A + B Hyper[x] + C Hyper[x]) (a + b Hyper[x])^n*)


{(A + B*Cosh[d + e*x] + C*Sinh[d + e*x])/(a + c*Sinh[d + e*x]), x, 6, (C*x)/c - (2*(A*c - a*C)*ArcTanh[(c - a*Tanh[(1/2)*(d + e*x)])/Sqrt[a^2 + c^2]])/(c*Sqrt[a^2 + c^2]*e) + (B*Log[a + c*Sinh[d + e*x]])/(c*e)}
{(A + B*Cosh[d + e*x] + C*Sinh[d + e*x])/(a + c*Sinh[d + e*x])^2, x, 6, -((2*(a*A + c*C)*ArcTanh[(c - a*Tanh[(1/2)*(d + e*x)])/Sqrt[a^2 + c^2]])/((a^2 + c^2)^(3/2)*e)) - B/(c*e*(a + c*Sinh[d + e*x])) - ((A*c - a*C)*Cosh[d + e*x])/((a^2 + c^2)*e*(a + c*Sinh[d + e*x]))}
{(A + B*Cosh[d + e*x] + C*Sinh[d + e*x])/(a + c*Sinh[d + e*x])^3, x, 7, -(((2*a^2*A - c*(A*c - 3*a*C))*ArcTanh[(c - a*Tanh[(1/2)*(d + e*x)])/Sqrt[a^2 + c^2]])/((a^2 + c^2)^(5/2)*e)) - B/(2*c*e*(a + c*Sinh[d + e*x])^2) - ((A*c - a*C)*Cosh[d + e*x])/(2*(a^2 + c^2)*e*(a + c*Sinh[d + e*x])^2) - ((2*c^2*C + a*(3*A*c - a*C))*Cosh[d + e*x])/(2*(a^2 + c^2)^2*e*(a + c*Sinh[d + e*x]))}
{(A + B*Cosh[d + e*x] + C*Sinh[d + e*x])/(a + c*Sinh[d + e*x])^4, x, 8, -(((c*(2*a^2*C - c*(5*a*A + 3*c*C)) - 2*a*(2*A*c^2 - a*(3*a*A + 5*c*C)))*ArcTanh[(c - a*Tanh[(1/2)*(d + e*x)])/Sqrt[a^2 + c^2]])/(3*(a^2 + c^2)^(7/2)*e)) - B/(3*c*e*(a + c*Sinh[d + e*x])^3) - ((A*c - a*C)*Cosh[d + e*x])/(3*(a^2 + c^2)*e*(a + c*Sinh[d + e*x])^3) + ((2*a^2*C - c*(5*a*A + 3*c*C))*Cosh[d + e*x])/(6*(a^2 + c^2)^2*e*(a + c*Sinh[d + e*x])^2) + ((a*(2*a^2*C - c*(5*a*A + 3*c*C)) + 2*c*(2*A*c^2 - a*(3*a*A + 5*c*C)))*Cosh[d + e*x])/(6*(a^2 + c^2)^3*e*(a + c*Sinh[d + e*x]))}


{(A + B*Cosh[d + e*x] + C*Sinh[d + e*x])/(a + b*Cosh[d + e*x]), x, 6, (B*x)/b + (2*(A*b - a*B)*ArcTanh[((a - b)*Tanh[(1/2)*(d + e*x)])/Sqrt[a^2 - b^2]])/(b*Sqrt[a^2 - b^2]*e) + (C*Log[a + b*Cosh[d + e*x]])/(b*e)}
{(A + B*Cosh[d + e*x] + C*Sinh[d + e*x])/(a + b*Cosh[d + e*x])^2, x, 6, (2*(a*A - b*B)*ArcTanh[((a - b)*Tanh[(1/2)*(d + e*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(3/2)*e) - C/(b*e*(a + b*Cosh[d + e*x])) - ((A*b - a*B)*Sinh[d + e*x])/((a^2 - b^2)*e*(a + b*Cosh[d + e*x]))}
{(A + B*Cosh[d + e*x] + C*Sinh[d + e*x])/(a + b*Cosh[d + e*x])^3, x, 7, ((2*a^2*A + b*(A*b - 3*a*B))*ArcTanh[((a - b)*Tanh[(1/2)*(d + e*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(5/2)*e) - C/(2*b*e*(a + b*Cosh[d + e*x])^2) - ((A*b - a*B)*Sinh[d + e*x])/(2*(a^2 - b^2)*e*(a + b*Cosh[d + e*x])^2) + ((2*b^2*B - a*(3*A*b - a*B))*Sinh[d + e*x])/(2*(a^2 - b^2)^2*e*(a + b*Cosh[d + e*x]))}
{(A + B*Cosh[d + e*x] + C*Sinh[d + e*x])/(a + b*Cosh[d + e*x])^4, x, 8, ((2*a*(2*A*b^2 + a*(3*a*A - 5*b*B)) - b*(2*a^2*B - b*(5*a*A - 3*b*B)))*ArcTanh[((a - b)*Tanh[(1/2)*(d + e*x)])/Sqrt[a^2 - b^2]])/(3*(a^2 - b^2)^(7/2)*e) - C/(3*b*e*(a + b*Cosh[d + e*x])^3) - ((A*b - a*B)*Sinh[d + e*x])/(3*(a^2 - b^2)*e*(a + b*Cosh[d + e*x])^3) + ((2*a^2*B - b*(5*a*A - 3*b*B))*Sinh[d + e*x])/(6*(a^2 - b^2)^2*e*(a + b*Cosh[d + e*x])^2) - ((2*b*(2*A*b^2 + a*(3*a*A - 5*b*B)) - a*(2*a^2*B - b*(5*a*A - 3*b*B)))*Sinh[d + e*x])/(6*(a^2 - b^2)^3*e*(a + b*Cosh[d + e*x]))}


(* ::Subsection::Closed:: *)
(*Integrands of the form (A+B Hyper[x]+C Hyper[x]) / (b Hyper[x]+c Hyper[x])*)


(* Integrands of the form (A+B*Cosh[x]+C*Sinh[x])*(b*Cosh[x]+c*Sinh[x])^n *)
{(B*Cosh[x] + C*Sinh[x])/(b*Cosh[x] + c*Sinh[x]), x, 1, ((b*B - c*C)*x)/(b^2 - c^2) - ((B*c - b*C)*Log[b*Cosh[x] + c*Sinh[x]])/(b^2 - c^2)}
{(B*Cosh[x] + C*Sinh[x])/(b*Cosh[x] + c*Sinh[x])^2, x, 2, (2*(b*B - c*C)*ArcTan[(c + b*Tanh[x/2])/Sqrt[b^2 - c^2]])/(b^2 - c^2)^(3/2) + (B*c - b*C)/((b^2 - c^2)*(b*Cosh[x] + c*Sinh[x]))}
{(B*Cosh[x] + C*Sinh[x])/(b*Cosh[x] + c*Sinh[x])^3, x, 3, (B*c - b*C)/(2*(b^2 - c^2)*(b*Cosh[x] + c*Sinh[x])^2) + ((b*B - c*C)*Sinh[x])/(b*(b^2 - c^2)*(b*Cosh[x] + c*Sinh[x]))}

{(Cosh[x] - Sinh[x])/(Cosh[x] + Sinh[x]), x, 2, (-(1/2))*(Cosh[x] - Sinh[x])^2}
{(Cosh[x] - I*Sinh[x])/(Cosh[x] + I*Sinh[x]), x, 1, (-I)*Log[Cosh[x] + I*Sinh[x]]}


(* Integrands of the form (A+B*Cosh[x]+C*Sinh[x])*(b*Cosh[x]+c*Sinh[x])^n *)
{(A + B*Cosh[x] + C*Sinh[x])/(b*Cosh[x] + c*Sinh[x]), x, 2, ((b*B - c*C)*x)/(b^2 - c^2) + (2*A*ArcTan[(c + b*Tanh[x/2])/Sqrt[b^2 - c^2]])/Sqrt[b^2 - c^2] - ((B*c - b*C)*Log[b*Cosh[x] + c*Sinh[x]])/(b^2 - c^2)}
{(A + B*Cosh[x] + C*Sinh[x])/(b*Cosh[x] + c*Sinh[x])^2, x, 2, (2*(b*B - c*C)*ArcTan[(c + b*Tanh[x/2])/Sqrt[b^2 - c^2]])/(b^2 - c^2)^(3/2) + (B*c - b*C + A*c*Cosh[x] + A*b*Sinh[x])/((b^2 - c^2)*(b*Cosh[x] + c*Sinh[x]))}
{(A + B*Cosh[x] + C*Sinh[x])/(b*Cosh[x] + c*Sinh[x])^3, x, 3, (A*ArcTan[(c + b*Tanh[x/2])/Sqrt[b^2 - c^2]])/(b^2 - c^2)^(3/2) + (B*c - b*C + A*c*Cosh[x] + A*b*Sinh[x])/(2*(b^2 - c^2)*(b*Cosh[x] + c*Sinh[x])^2) + ((b*B - c*C)*(c*Cosh[x] + b*Sinh[x]))/((b^2 - c^2)^2*(b*Cosh[x] + c*Sinh[x]))}


(* ::Subsection::Closed:: *)
(*Integrands of the form (A+B Hyper[x]+C Hyper[x]) / (a+b Hyper[x]+c Hyper[x])*)


(* Integrands of the form (A+B*Cosh[x]+C*Sinh[x])*(a+b*Cosh[x]+c*Sinh[x])^n *)
{(B*Cosh[x] + C*Sinh[x])/(a + b*Cosh[x] + c*Sinh[x]), x, 2, ((b*B - c*C)*x)/(b^2 - c^2) + (2*a*(b*B - c*C)*ArcTanh[(c - (a - b)*Tanh[x/2])/Sqrt[a^2 - b^2 + c^2]])/((b^2 - c^2)*Sqrt[a^2 - b^2 + c^2]) - ((B*c - b*C)*Log[a + b*Cosh[x] + c*Sinh[x]])/(b^2 - c^2)}
{(B*Cosh[x] + C*Sinh[x])/(a + b*Cosh[x] + c*Sinh[x])^2, x, 2, (2*(b*B - c*C)*ArcTanh[(c - (a - b)*Tanh[x/2])/Sqrt[a^2 - b^2 + c^2]])/(a^2 - b^2 + c^2)^(3/2) - (B*c - b*C - a*C*Cosh[x] - a*B*Sinh[x])/((a^2 - b^2 + c^2)*(a + b*Cosh[x] + c*Sinh[x]))}
{(B*Cosh[x] + C*Sinh[x])/(a + b*Cosh[x] + c*Sinh[x])^3, x, 3, (3*a*(b*B - c*C)*ArcTanh[(c - (a - b)*Tanh[x/2])/Sqrt[a^2 - b^2 + c^2]])/(a^2 - b^2 + c^2)^(5/2) - (B*c - b*C - a*C*Cosh[x] - a*B*Sinh[x])/(2*(a^2 - b^2 + c^2)*(a + b*Cosh[x] + c*Sinh[x])^2) - (a*B*c - a*b*C - (a^2*C + 2*c*(b*B - c*C))*Cosh[x] - (a^2*B + 2*b*(b*B - c*C))*Sinh[x])/(2*(a^2 - b^2 + c^2)^2*(a + b*Cosh[x] + c*Sinh[x]))}


(* Integrands of the form (A+B*Cosh[x]+C*Sinh[x])*(a+b*Cosh[x]+c*Sinh[x])^n *)
{(A + B*Cosh[x] + C*Sinh[x])/(a + b*Cosh[x] + c*Sinh[x]), x, 2, ((b*B - c*C)*x)/(b^2 - c^2) - (2*(A*(b^2 - c^2) - a*(b*B - c*C))*ArcTanh[(c - (a - b)*Tanh[x/2])/Sqrt[a^2 - b^2 + c^2]])/((b^2 - c^2)*Sqrt[a^2 - b^2 + c^2]) - ((B*c - b*C)*Log[a + b*Cosh[x] + c*Sinh[x]])/(b^2 - c^2)}
{(A + B*Cosh[x] + C*Sinh[x])/(a + b*Cosh[x] + c*Sinh[x])^2, x, 2, -((2*(a*A - b*B + c*C)*ArcTanh[(c - (a - b)*Tanh[x/2])/Sqrt[a^2 - b^2 + c^2]])/(a^2 - b^2 + c^2)^(3/2)) - (B*c - b*C + (A*c - a*C)*Cosh[x] + (A*b - a*B)*Sinh[x])/((a^2 - b^2 + c^2)*(a + b*Cosh[x] + c*Sinh[x]))}
{(A + B*Cosh[x] + C*Sinh[x])/(a + b*Cosh[x] + c*Sinh[x])^3, x, 3, -(((2*a^2*A + b*(A*b - 3*a*B) - c*(A*c - 3*a*C))*ArcTanh[(c - (a - b)*Tanh[x/2])/Sqrt[a^2 - b^2 + c^2]])/(a^2 - b^2 + c^2)^(5/2)) - (B*c - b*C + (A*c - a*C)*Cosh[x] + (A*b - a*B)*Sinh[x])/(2*(a^2 - b^2 + c^2)*(a + b*Cosh[x] + c*Sinh[x])^2) - (a*B*c - a*b*C + (a*(3*A*c - a*C) - 2*c*(b*B - c*C))*Cosh[x] + (a*(3*A*b - a*B) - 2*b*(b*B - c*C))*Sinh[x])/(2*(a^2 - b^2 + c^2)^2*(a + b*Cosh[x] + c*Sinh[x]))}

{(b^2 - c^2 + a*b*Cosh[x] + a*c*Sinh[x])/(a + b*Cosh[x] + c*Sinh[x])^2, x, 1, (c*Cosh[x] + b*Sinh[x])/(a + b*Cosh[x] + c*Sinh[x])}


(* ::Section:: *)
(*Integrands involving exponential and hyperbolic functions*)


(* ::Subsection::Closed:: *)
(*Products of an exponential function and powers of a hyperbolic function*)


{E^(a + b*x)*Sinh[a + b*x]^3, x, 4, -((3*E^(2*a + 2*b*x))/(16*b)) + (3*x)/8 + (3*E^(a + b*x)*Cosh[a + b*x]*Sinh[a + b*x]^2)/(8*b) - (E^(a + b*x)*Sinh[a + b*x]^3)/(8*b)}
{E^(a + b*x)*Sinh[a + b*x]^2, x, 2, -((2*E^(a + b*x))/(3*b)) + (2*E^(a + b*x)*Cosh[a + b*x]*Sinh[a + b*x])/(3*b) - (E^(a + b*x)*Sinh[a + b*x]^2)/(3*b)}
{E^(a + b*x)*Sinh[a + b*x]^1, x, 3, E^(2*a + 2*b*x)/(4*b) - x/2}
{E^(a + b*x)*Csch[a + b*x]^1, x, 4, Log[1 - E^(2*a + 2*b*x)]/b}
{E^(a + b*x)*Csch[a + b*x]^2, x, 4, (2*E^(a + b*x))/(b*(1 - E^(2*a + 2*b*x))) - (2*ArcTanh[E^(a + b*x)])/b}
{E^(a + b*x)*Csch[a + b*x]^3, x, 1, -((E^(a + b*x)*Csch[a + b*x])/(2*b)) - (E^(a + b*x)*Coth[a + b*x]*Csch[a + b*x])/(2*b)}
{E^(a + b*x)*Csch[a + b*x]^4, x, 5, -(E^(a + b*x)/(b*(1 - E^(2*a + 2*b*x)))) + ArcTanh[E^(a + b*x)]/b - (E^(a + b*x)*Csch[a + b*x]^2)/(6*b) - (E^(a + b*x)*Coth[a + b*x]*Csch[a + b*x]^2)/(3*b)}
{E^(a + b*x)*Csch[a + b*x]^5, x, 2, (E^(a + b*x)*Csch[a + b*x])/(3*b) + (E^(a + b*x)*Coth[a + b*x]*Csch[a + b*x])/(3*b) - (E^(a + b*x)*Csch[a + b*x]^3)/(12*b) - (E^(a + b*x)*Coth[a + b*x]*Csch[a + b*x]^3)/(4*b)}


{E^(a + b*x)*Sinh[c + d*x]^3, x, 2, -((6*d^3*E^(a + b*x)*Cosh[c + d*x])/((b^2 - 9*d^2)*(b^2 - d^2))) + (6*b*d^2*E^(a + b*x)*Sinh[c + d*x])/((b^2 - 9*d^2)*(b^2 - d^2)) - (3*d*E^(a + b*x)*Cosh[c + d*x]*Sinh[c + d*x]^2)/(b^2 - 9*d^2) + (b*E^(a + b*x)*Sinh[c + d*x]^3)/(b^2 - 9*d^2)}
{E^(a + b*x)*Sinh[c + d*x]^2, x, 2, (2*d^2*E^(a + b*x))/(b*(b^2 - 4*d^2)) - (2*d*E^(a + b*x)*Cosh[c + d*x]*Sinh[c + d*x])/(b^2 - 4*d^2) + (b*E^(a + b*x)*Sinh[c + d*x]^2)/(b^2 - 4*d^2)}
{E^(a + b*x)*Sinh[c + d*x]^1, x, 1, -((d*E^(a + b*x)*Cosh[c + d*x])/(b^2 - d^2)) + (b*E^(a + b*x)*Sinh[c + d*x])/(b^2 - d^2)}
{E^(a + b*x)*Csch[c + d*x]^1, x, 1, E^a*Int[E^(b*x)*Csch[c + d*x], x]}


{E^(a + b*x)*Cosh[a + b*x]^3, x, 4, (3*E^(2*a + 2*b*x))/(16*b) + (3*x)/8 - (E^(a + b*x)*Cosh[a + b*x]^3)/(8*b) + (3*E^(a + b*x)*Cosh[a + b*x]^2*Sinh[a + b*x])/(8*b)}
{E^(a + b*x)*Cosh[a + b*x]^2, x, 2, (2*E^(a + b*x))/(3*b) - (E^(a + b*x)*Cosh[a + b*x]^2)/(3*b) + (2*E^(a + b*x)*Cosh[a + b*x]*Sinh[a + b*x])/(3*b)}
{E^(a + b*x)*Cosh[a + b*x]^1, x, 3, E^(2*a + 2*b*x)/(4*b) + x/2}
{E^(a + b*x)*Sech[a + b*x]^1, x, 4, Log[1 + E^(2*a + 2*b*x)]/b}
{E^(a + b*x)*Sech[a + b*x]^2, x, 4, -((2*E^(a + b*x))/(b*(1 + E^(2*a + 2*b*x)))) + (2*ArcTan[E^(a + b*x)])/b}
{E^(a + b*x)*Sech[a + b*x]^3, x, 1, (E^(a + b*x)*Sech[a + b*x])/(2*b) + (E^(a + b*x)*Sech[a + b*x]*Tanh[a + b*x])/(2*b)}
{E^(a + b*x)*Sech[a + b*x]^4, x, 5, -(E^(a + b*x)/(b*(1 + E^(2*a + 2*b*x)))) + ArcTan[E^(a + b*x)]/b + (E^(a + b*x)*Sech[a + b*x]^2)/(6*b) + (E^(a + b*x)*Sech[a + b*x]^2*Tanh[a + b*x])/(3*b)}
{E^(a + b*x)*Sech[a + b*x]^5, x, 2, (E^(a + b*x)*Sech[a + b*x])/(3*b) + (E^(a + b*x)*Sech[a + b*x]^3)/(12*b) + (E^(a + b*x)*Sech[a + b*x]*Tanh[a + b*x])/(3*b) + (E^(a + b*x)*Sech[a + b*x]^3*Tanh[a + b*x])/(4*b)}


{E^(a + b*x)*Cosh[c + d*x]^3, x, 2, -((6*b*d^2*E^(a + b*x)*Cosh[c + d*x])/((b^2 - 9*d^2)*(b^2 - d^2))) + (b*E^(a + b*x)*Cosh[c + d*x]^3)/(b^2 - 9*d^2) + (6*d^3*E^(a + b*x)*Sinh[c + d*x])/((b^2 - 9*d^2)*(b^2 - d^2)) - (3*d*E^(a + b*x)*Cosh[c + d*x]^2*Sinh[c + d*x])/(b^2 - 9*d^2)}
{E^(a + b*x)*Cosh[c + d*x]^2, x, 2, -((2*d^2*E^(a + b*x))/(b*(b^2 - 4*d^2))) + (b*E^(a + b*x)*Cosh[c + d*x]^2)/(b^2 - 4*d^2) - (2*d*E^(a + b*x)*Cosh[c + d*x]*Sinh[c + d*x])/(b^2 - 4*d^2)}
{E^(a + b*x)*Cosh[c + d*x]^1, x, 1, (b*E^(a + b*x)*Cosh[c + d*x])/(b^2 - d^2) - (d*E^(a + b*x)*Sinh[c + d*x])/(b^2 - d^2)}
{E^(a + b*x)*Sech[c + d*x]^1, x, 1, E^a*Int[E^(b*x)*Sech[c + d*x], x]}


{E^(a + b*x)*Sinh[c + d*x]^(3/2) - ((3*d^2)/(4*(b^2 - (9*d^2)/4)))*(E^(a + b*x)/Sqrt[Sinh[c + d*x]]), x, 4, -((6*d*E^(a + b*x)*Cosh[c + d*x]*Sqrt[Sinh[c + d*x]])/(4*b^2 - 9*d^2)) + (4*b*E^(a + b*x)*Sinh[c + d*x]^(3/2))/(4*b^2 - 9*d^2)}


(* Integrands of the form E^x*Tanh[n*x]^m where m and n are integers *)
{E^x*Tanh[x], x, 4, E^x - 2*ArcTan[E^x]}
{E^x*Tanh[2*x], x, 8, E^x + ArcTan[1 - Sqrt[2]*E^x]/Sqrt[2] - ArcTan[1 + Sqrt[2]*E^x]/Sqrt[2] + Log[1 - Sqrt[2]*E^x + E^(2*x)]/(2*Sqrt[2]) - Log[1 + Sqrt[2]*E^x + E^(2*x)]/(2*Sqrt[2])}
{E^x*Tanh[3*x], x, 7, E^x - (2*ArcTan[E^x])/3 - (1/3)*ArcTan[E^x/(1 - E^(2*x))] - ArcTanh[(Sqrt[3]*E^x)/(1 + E^(2*x))]/Sqrt[3]}
{E^x*Tanh[4*x], x, 10, E^x - (1/4)*Sqrt[2 - Sqrt[2]]*ArcTan[(Sqrt[2 - Sqrt[2]]*E^x)/(1 - E^(2*x))] - (1/4)*Sqrt[2 + Sqrt[2]]*ArcTan[(Sqrt[2 + Sqrt[2]]*E^x)/(1 - E^(2*x))] - (1/4)*Sqrt[2 - Sqrt[2]]*ArcTanh[(Sqrt[2 - Sqrt[2]]*E^x)/(1 + E^(2*x))] - (1/4)*Sqrt[2 + Sqrt[2]]*ArcTanh[(Sqrt[2 + Sqrt[2]]*E^x)/(1 + E^(2*x))]}

{E^x*Tanh[x]^2, x, 6, E^x + (2*E^x)/(1 + E^(2*x)) - 2*ArcTan[E^x]}
{E^x*Tanh[2*x]^2, x, 17, E^x + E^x/(1 + E^(4*x)) + ArcTan[1 - Sqrt[2]*E^x]/(2*Sqrt[2]) - ArcTan[1 + Sqrt[2]*E^x]/(2*Sqrt[2]) + Log[1 - Sqrt[2]*E^x + E^(2*x)]/(4*Sqrt[2]) - Log[1 + Sqrt[2]*E^x + E^(2*x)]/(4*Sqrt[2])}
{E^x*Tanh[3*x]^2, x, 17, E^x + (2*E^x)/(3*(1 + E^(6*x))) - (2*ArcTan[E^x])/9 - (1/9)*ArcTan[E^x/(1 - E^(2*x))] - ArcTanh[(Sqrt[3]*E^x)/(1 + E^(2*x))]/(3*Sqrt[3])}
{E^x*Tanh[4*x]^2, x, 21, E^x + E^x/(2*(1 + E^(8*x))) - (1/16)*Sqrt[2 - Sqrt[2]]*ArcTan[(Sqrt[2 - Sqrt[2]]*E^x)/(1 - E^(2*x))] - (1/16)*Sqrt[2 + Sqrt[2]]*ArcTan[(Sqrt[2 + Sqrt[2]]*E^x)/(1 - E^(2*x))] - (1/16)*Sqrt[2 - Sqrt[2]]*ArcTanh[(Sqrt[2 - Sqrt[2]]*E^x)/(1 + E^(2*x))] - (1/16)*Sqrt[2 + Sqrt[2]]*ArcTanh[(Sqrt[2 + Sqrt[2]]*E^x)/(1 + E^(2*x))]}


(* Integrands of the form E^x*Coth[n*x]^m where m and n are integers *)
{E^x*Coth[x], x, 4, E^x - 2*ArcTanh[E^x]}
{E^x*Coth[2*x], x, 5, E^x - ArcTan[E^x] - ArcTanh[E^x]}
{E^x*Coth[3*x], x, 8, E^x - ArcTan[(Sqrt[3]*E^x)/(1 - E^(2*x))]/Sqrt[3] - (2*ArcTanh[E^x])/3 - (1/3)*ArcTanh[E^x/(1 + E^(2*x))], E^x + ArcTan[(1 - 2*E^x)/Sqrt[3]]/Sqrt[3] - ArcTan[(1 + 2*E^x)/Sqrt[3]]/Sqrt[3] - (2*ArcTanh[E^x])/3 + (1/6)*Log[1 - E^x + E^(2*x)] - (1/6)*Log[1 + E^x + E^(2*x)]}
{E^x*Coth[4*x], x, 10, E^x - ArcTan[E^x]/2 + ArcTan[1 - Sqrt[2]*E^x]/(2*Sqrt[2]) - ArcTan[1 + Sqrt[2]*E^x]/(2*Sqrt[2]) - ArcTanh[E^x]/2 + Log[1 - Sqrt[2]*E^x + E^(2*x)]/(4*Sqrt[2]) - Log[1 + Sqrt[2]*E^x + E^(2*x)]/(4*Sqrt[2])}

{E^x*Coth[x]^2, x, 6, E^x + (2*E^x)/(1 - E^(2*x)) - 2*ArcTanh[E^x]}
{E^x*Coth[2*x]^2, x, 13, E^x + E^x/(1 - E^(4*x)) - ArcTan[E^x]/2 - ArcTanh[E^x]/2}
{E^x*Coth[3*x]^2, x, 17, E^x + (2*E^x)/(3*(1 - E^(6*x))) - ArcTan[(Sqrt[3]*E^x)/(1 - E^(2*x))]/(3*Sqrt[3]) - (2*ArcTanh[E^x])/9 - (1/9)*ArcTanh[E^x/(1 + E^(2*x))]}
{E^x*Coth[4*x]^2, x, 25, E^x + E^x/(2*(1 - E^(8*x))) - ArcTan[E^x]/8 + ArcTan[1 - Sqrt[2]*E^x]/(8*Sqrt[2]) - ArcTan[1 + Sqrt[2]*E^x]/(8*Sqrt[2]) - ArcTanh[E^x]/8 + Log[1 - Sqrt[2]*E^x + E^(2*x)]/(16*Sqrt[2]) - Log[1 + Sqrt[2]*E^x + E^(2*x)]/(16*Sqrt[2])}


(* Integrands of the form E^x*Sech[n*x]^m where m and n are integers *)
{E^x*Sech[x], x, 4, Log[1 + E^(2*x)]}
{E^x*Sech[2*x], x, 7, -(ArcTan[1 - Sqrt[2]*E^x]/Sqrt[2]) + ArcTan[1 + Sqrt[2]*E^x]/Sqrt[2] + Log[1 - Sqrt[2]*E^x + E^(2*x)]/(2*Sqrt[2]) - Log[1 + Sqrt[2]*E^x + E^(2*x)]/(2*Sqrt[2])}
{E^x*Sech[3*x], x, 7, -(ArcTan[(1 - 2*E^(2*x))/Sqrt[3]]/Sqrt[3]) - (1/3)*Log[1 + E^(2*x)] + (1/6)*Log[1 - E^(2*x) + E^(4*x)]}
{E^x*Sech[4*x], x, 9, (1/4)*Sqrt[2 + Sqrt[2]]*ArcTan[(Sqrt[2 - Sqrt[2]]*E^x)/(1 - E^(2*x))] - (1/4)*Sqrt[2 - Sqrt[2]]*ArcTan[(Sqrt[2 + Sqrt[2]]*E^x)/(1 - E^(2*x))] + (1/4)*Sqrt[2 + Sqrt[2]]*ArcTanh[(Sqrt[2 - Sqrt[2]]*E^x)/(1 + E^(2*x))] - (1/4)*Sqrt[2 - Sqrt[2]]*ArcTanh[(Sqrt[2 + Sqrt[2]]*E^x)/(1 + E^(2*x))]}

{E^x*Sech[x]^2, x, 4, -((2*E^x)/(1 + E^(2*x))) + 2*ArcTan[E^x]}
{E^x*Sech[2*x]^2, x, 8, -(E^x/(1 + E^(4*x))) - ArcTan[1 - Sqrt[2]*E^x]/(2*Sqrt[2]) + ArcTan[1 + Sqrt[2]*E^x]/(2*Sqrt[2]) - Log[1 - Sqrt[2]*E^x + E^(2*x)]/(4*Sqrt[2]) + Log[1 + Sqrt[2]*E^x + E^(2*x)]/(4*Sqrt[2])}
{E^x*Sech[3*x]^2, x, 8, -((2*E^x)/(3*(1 + E^(6*x)))) + (2*ArcTan[E^x])/9 + (1/9)*ArcTan[E^x/(1 - E^(2*x))] + ArcTanh[(Sqrt[3]*E^x)/(1 + E^(2*x))]/(3*Sqrt[3])}
{E^x*Sech[4*x]^2, x, 10, -(E^x/(2*(1 + E^(8*x)))) + (1/16)*Sqrt[2 - Sqrt[2]]*ArcTan[(Sqrt[2 - Sqrt[2]]*E^x)/(1 - E^(2*x))] + (1/16)*Sqrt[2 + Sqrt[2]]*ArcTan[(Sqrt[2 + Sqrt[2]]*E^x)/(1 - E^(2*x))] + (1/16)*Sqrt[2 - Sqrt[2]]*ArcTanh[(Sqrt[2 - Sqrt[2]]*E^x)/(1 + E^(2*x))] + (1/16)*Sqrt[2 + Sqrt[2]]*ArcTanh[(Sqrt[2 + Sqrt[2]]*E^x)/(1 + E^(2*x))]}


(* Integrands of the form E^x*Csch[n*x]^m where m and n are integers *)
{E^x*Csch[x], x, 4, Log[1 - E^(2*x)]}
{E^x*Csch[2*x], x, 5, ArcTan[E^x] - ArcTanh[E^x]}
{E^x*Csch[3*x], x, 7, ArcTan[(1 + 2*E^(2*x))/Sqrt[3]]/Sqrt[3] + (1/3)*Log[1 - E^(2*x)] - (1/6)*Log[1 + E^(2*x) + E^(4*x)]}
{E^x*Csch[4*x], x, 11, (-(1/2))*ArcTan[E^x] - ArcTan[1 - Sqrt[2]*E^x]/(2*Sqrt[2]) + ArcTan[1 + Sqrt[2]*E^x]/(2*Sqrt[2]) - ArcTanh[E^x]/2 - Log[1 - Sqrt[2]*E^x + E^(2*x)]/(4*Sqrt[2]) + Log[1 + Sqrt[2]*E^x + E^(2*x)]/(4*Sqrt[2])}

{E^x*Csch[x]^2, x, 4, (2*E^x)/(1 - E^(2*x)) - 2*ArcTanh[E^x]}
{E^x*Csch[2*x]^2, x, 6, E^x/(1 - E^(4*x)) - ArcTan[E^x]/2 - ArcTanh[E^x]/2}
{E^x*Csch[3*x]^2, x, 8, (2*E^x)/(3*(1 - E^(6*x))) - ArcTan[(Sqrt[3]*E^x)/(1 - E^(2*x))]/(3*Sqrt[3]) - (2*ArcTanh[E^x])/9 - (1/9)*ArcTanh[E^x/(1 + E^(2*x))]}
{E^x*Csch[4*x]^2, x, 12, E^x/(2*(1 - E^(8*x))) - ArcTan[E^x]/8 + ArcTan[1 - Sqrt[2]*E^x]/(8*Sqrt[2]) - ArcTan[1 + Sqrt[2]*E^x]/(8*Sqrt[2]) - ArcTanh[E^x]/8 + Log[1 - Sqrt[2]*E^x + E^(2*x)]/(16*Sqrt[2]) - Log[1 + Sqrt[2]*E^x + E^(2*x)]/(16*Sqrt[2])}


(* ::Subsection::Closed:: *)
(*Products of an exponential function and powers of two hyperbolic functions*)


{E^x*Sech[2*x]*Tanh[2*x], x, 10, -(E^(3*x)/(1 + E^(4*x))) - ArcTan[1 - Sqrt[2]*E^x]/(2*Sqrt[2]) + ArcTan[1 + Sqrt[2]*E^x]/(2*Sqrt[2]) + Log[1 - Sqrt[2]*E^x + E^(2*x)]/(4*Sqrt[2]) - Log[1 + Sqrt[2]*E^x + E^(2*x)]/(4*Sqrt[2])}
{E^x*Sech[2*x]^2*Tanh[2*x], x, 11, -(E^x/(3*(1 + E^(4*x))^2)) - (4*E^(5*x))/(3*(1 + E^(4*x))^2) + E^x/(12*(1 + E^(4*x))) - ArcTan[1 - Sqrt[2]*E^x]/(8*Sqrt[2]) + ArcTan[1 + Sqrt[2]*E^x]/(8*Sqrt[2]) - Log[1 - Sqrt[2]*E^x + E^(2*x)]/(16*Sqrt[2]) + Log[1 + Sqrt[2]*E^x + E^(2*x)]/(16*Sqrt[2])}
{E^x*Sech[2*x]*Tanh[2*x]^2, x, 12, -(E^(3*x)/(1 + E^(4*x))^2) - (2*E^(7*x))/(1 + E^(4*x))^2 + (5*E^(3*x))/(4*(1 + E^(4*x))) - (5*ArcTan[1 - Sqrt[2]*E^x])/(8*Sqrt[2]) + (5*ArcTan[1 + Sqrt[2]*E^x])/(8*Sqrt[2]) + (5*Log[1 - Sqrt[2]*E^x + E^(2*x)])/(16*Sqrt[2]) - (5*Log[1 + Sqrt[2]*E^x + E^(2*x)])/(16*Sqrt[2])}
{E^x*Sech[2*x]^2*Tanh[2*x]^2, x, 13, -((4*E^x)/(7*(1 + E^(4*x))^3)) - (4*E^(5*x))/(7*(1 + E^(4*x))^3) - (4*E^(9*x))/(3*(1 + E^(4*x))^3) + E^x/(14*(1 + E^(4*x))^2) + E^x/(8*(1 + E^(4*x))) - (3*ArcTan[1 - Sqrt[2]*E^x])/(16*Sqrt[2]) + (3*ArcTan[1 + Sqrt[2]*E^x])/(16*Sqrt[2]) - (3*Log[1 - Sqrt[2]*E^x + E^(2*x)])/(32*Sqrt[2]) + (3*Log[1 + Sqrt[2]*E^x + E^(2*x)])/(32*Sqrt[2])}


{E^x*Coth[2*x]*Csch[2*x], x, 8, E^(3*x)/(1 - E^(4*x)) + ArcTan[E^x]/2 - ArcTanh[E^x]/2}
{E^x*Coth[2*x]*Csch[2*x]^2, x, 9, E^x/(3*(1 - E^(4*x))^2) - (4*E^(5*x))/(3*(1 - E^(4*x))^2) - E^x/(12*(1 - E^(4*x))) - ArcTan[E^x]/8 - ArcTanh[E^x]/8}
{E^x*Coth[2*x]^2*Csch[2*x], x, 10, E^(3*x)/(1 - E^(4*x))^2 - (2*E^(7*x))/(1 - E^(4*x))^2 - (5*E^(3*x))/(4*(1 - E^(4*x))) + (5*ArcTan[E^x])/8 - (5*ArcTanh[E^x])/8}
{E^x*Coth[2*x]^2*Csch[2*x]^2, x, 11, (4*E^x)/(7*(1 - E^(4*x))^3) - (4*E^(5*x))/(7*(1 - E^(4*x))^3) + (4*E^(9*x))/(3*(1 - E^(4*x))^3) - E^x/(14*(1 - E^(4*x))^2) - E^x/(8*(1 - E^(4*x))) - (3*ArcTan[E^x])/16 - (3*ArcTanh[E^x])/16}


(* ::Subsection::Closed:: *)
(*Miscellaneous integrands involving exponential and hyperbolic functions*)


{E^x/(a - Tanh[2*x]), x, 6, -(E^x/(1 - a)) + ArcTan[((1 - a)^(1/4)*E^x)/(1 + a)^(1/4)]/((1 - a)^(5/4)*(1 + a)^(3/4)) + ArcTanh[((1 - a)^(1/4)*E^x)/(1 + a)^(1/4)]/((1 - a)^(5/4)*(1 + a)^(3/4))}
{E^x/(a - Tanh[2*x])^2, x, 13, E^x/(1 - a)^2 + E^x/((1 - a)^2*(1 + a)*(1 + a - (1 - a)*E^(4*x))) + ((1 - 2*a)*ArcTan[((1 - a)^(1/4)*E^x)/(1 + a)^(1/4)])/(2*(1 - a)^(9/4)*(1 + a)^(7/4)) - ArcTan[((1 - a)^(1/4)*E^x)/(1 + a)^(1/4)]/((1 - a)^(9/4)*(1 + a)^(3/4)) + ((1 - 2*a)*ArcTanh[((1 - a)^(1/4)*E^x)/(1 + a)^(1/4)])/(2*(1 - a)^(9/4)*(1 + a)^(7/4)) - ArcTanh[((1 - a)^(1/4)*E^x)/(1 + a)^(1/4)]/((1 - a)^(9/4)*(1 + a)^(3/4))}


(* ::Section::Closed:: *)
(*Products of functions of a trig function and its derivative*)


{Cosh[a + b*x]*f[c, d, Sinh[a + b*x], r, s], x, 1, Subst[Int[f[c, d, x, r, s], x], x, Sinh[a + b*x]]/b}
{Sinh[a + b*x]*f[c, d, Cosh[a + b*x], r, s], x, 1, (Subst[Int[f[c, d, x, r, s], x], x, Cosh[a + b*x]]/b)}
{Sech[a + b*x]^2*f[c, d, Tanh[a + b*x], r, s], x, 1, Subst[Int[f[c, d, x, r, s], x], x, Tanh[a + b*x]]/b}
{Csch[a + b*x]^2*f[c, d, Coth[a + b*x], r, s], x, 1, -(Subst[Int[f[c, d, x, r, s], x], x, Coth[a + b*x]]/b)}


(* Integrands of the form Sech[x]^n*f (Tanh[x]) where n is even *)
{Sech[x]^2/(a + b*Tanh[x]), x, 2, Log[a + b*Tanh[x]]/b}
{Sech[x]^2*(a + b*Tanh[x])^n, x, 2, (a + b*Tanh[x])^(1 + n)/(b*(1 + n))}

{Sech[x]^2*(1 + Cosh[x]^2), x, 3, x + Tanh[x]}
{Sech[x]^2*(1 + 1/(1 - Tanh[x]^2)), x, 4, x + Tanh[x]}
{Sech[x]^2*(2 - Tanh[x]^2)/(1 - Tanh[x]^2), x, -4, x + Tanh[x]}

{Sech[x]^2/(1 + Tanh[x]^2), x, 2, ArcTan[Tanh[x]]}
{Sech[x]^2/(9 + Tanh[x]^2), x, 2, ArcTan[Tanh[x]/3]/3}
{Sech[x]^2/Sqrt[4 - Sech[x]^2], x, 2, ArcSinh[Tanh[x]/Sqrt[3]]}
{Sech[x]^2/Sqrt[1 - 4*Tanh[x]^2], x, 2, ArcSin[2*Tanh[x]]/2}
{Sech[x]^2/Sqrt[-4 + Tanh[x]^2], x, 2, ArcTanh[Tanh[x]/Sqrt[-4 + Tanh[x]^2]]}
{Sech[x]^2*Sqrt[1 + Coth[x]^2], x, 4, -ArcCsch[Tanh[x]] + Sqrt[1 + Coth[x]^2]*Tanh[x]}
{Sech[x]^2*Sqrt[1 + Tanh[x]^2], x, 3, (1/2)*ArcSinh[Tanh[x]] + (1/2)*Tanh[x]*Sqrt[1 + Tanh[x]^2]}
{Sech[x]^2/(Tanh[x]^2 + Tanh[x]^3), x, 5, 2*ArcTanh[1 + 2*Tanh[x]] - Coth[x]}
{Sech[x]^2/(-Tanh[x]^2 + Tanh[x]^3), x, 5, 2*ArcTanh[1 - 2*Tanh[x]] + Coth[x]}
{Sech[x]^2/(2 + 2*Tanh[x] + Tanh[x]^2), x, 2, ArcTan[1 + Tanh[x]]}
{Sech[x]^2/(3 - 4*Tanh[x]^3), x, 5, ArcTan[(6^(1/3) + 4*Tanh[x])/(2^(1/3)*3^(5/6))]/(3*2^(2/3)*3^(1/6)) - Log[6^(1/3) - 2*Tanh[x]]/(3*6^(2/3)) + Log[6^(2/3) + 2*6^(1/3)*Tanh[x] + 4*Tanh[x]^2]/(6*6^(2/3))}
{Sech[x]^2/(11 - 5*Tanh[x] + 5*Tanh[x]^2), x, 2, -((2*ArcTan[Sqrt[5/39]*(1 - 2*Tanh[x])])/Sqrt[195])}
{Sech[x]^2/(1 + Sech[x]^2 - 3*Tanh[x]), x, 2, (2*ArcTanh[(3 + 2*Tanh[x])/Sqrt[17]])/Sqrt[17]}

{Sech[x]^2*(a + b*Tanh[x])/(c + d*Tanh[x]), x, 4, -(((b*c - a*d)*Log[c + d*Tanh[x]])/d^2) + (b*Tanh[x])/d}
{Sech[x]^2*(a + b*Tanh[x])^2/(c + d*Tanh[x]), x, 5, ((b*c - a*d)^2*Log[c + d*Tanh[x]])/d^3 - (b*(b*c - a*d)*Tanh[x])/d^2 + (a + b*Tanh[x])^2/(2*d)}
{Sech[x]^2*(a + b*Tanh[x])^3/(c + d*Tanh[x]), x, 6, -(((b*c - a*d)^3*Log[c + d*Tanh[x]])/d^4) + (b*(b*c - a*d)^2*Tanh[x])/d^3 - ((b*c - a*d)*(a + b*Tanh[x])^2)/(2*d^2) + (a + b*Tanh[x])^3/(3*d)}

{Sech[x]^2*Tanh[x]^2/(2 + Tanh[x]^3)^2, x, 3, -1/(3*(2 + Tanh[x]^3))}
{Sech[x]^2*Tanh[x]^6*(1 - Tanh[x]^2)^3, x, 3, Tanh[x]^7/7 - Tanh[x]^9/3 + (3*Tanh[x]^11)/11 - Tanh[x]^13/13}
{Sech[x]^2*(2 + Tanh[x]^2)/(1 + Tanh[x]^3), x, 5, -((2*ArcTan[(1 - 2*Tanh[x])/Sqrt[3]])/Sqrt[3]) + Log[1 + Tanh[x]]}

{Sech[x]^4*(-1 + Sech[x]^2)^2*Tanh[x], x, 3, Tanh[x]^6/6 - Tanh[x]^8/8, (-(1/4))*Sech[x]^4 + Sech[x]^6/3 - Sech[x]^8/8}


{Sech[x]*(5 - 11*Sech[x]^2)*Tanh[x], x, 3, -5*Sech[x] + (11*Sech[x]^3)/3}


(* Integrands of the form Csch[x]^n*f (Coth[x]) where n is even  *)
{Csch[x]^2/(a + b*Coth[x]), x, 2, -(Log[a + b*Coth[x]]/b)}
{Csch[x]^2*(a + b*Coth[x])^n, x, 2, -((a + b*Coth[x])^(1 + n)/(b*(1 + n)))}

{Csch[x]^2*(-1 + Sinh[x]^2), x, 3, x + Coth[x]}
{Csch[x]^2*(-1 - 1/(1 - Coth[x]^2)), x, 4, x + Coth[x]}
{Csch[x]^2*(a + b*Coth[x])/(c + d*Coth[x]), x, 4, -((b*Coth[x])/d) + ((b*c - a*d)*Log[c + d*Coth[x]])/d^2}
{Csch[x]^2*(a + b*Coth[x])^2/(c + d*Coth[x]), x, 5, (b*(b*c - a*d)*Coth[x])/d^2 - (a + b*Coth[x])^2/(2*d) - ((b*c - a*d)^2*Log[c + d*Coth[x]])/d^3}
{Csch[x]^2*(a + b*Coth[x])^3/(c + d*Coth[x]), x, 6, -((b*(b*c - a*d)^2*Coth[x])/d^3) + ((b*c - a*d)*(a + b*Coth[x])^2)/(2*d^2) - (a + b*Coth[x])^3/(3*d) + ((b*c - a*d)^3*Log[c + d*Coth[x]])/d^4}


{Cosh[x]^3*(a + b*Cosh[x]^2)^3*Sinh[x], x, 4, -((a*(a + b*Cosh[x]^2)^4)/(40*b^2)) + (Cosh[x]^2*(a + b*Cosh[x]^2)^4)/(10*b)}
{Sinh[x]^3*(a + b*Sinh[x]^2)^3*Cosh[x], x, 4, -((a*(a + b*Sinh[x]^2)^4)/(40*b^2)) + (Sinh[x]^2*(a + b*Sinh[x]^2)^4)/(10*b)}


{Cosh[x]*Sinh[x]*Sqrt[a + b*Sinh[x]^2], x, 3, (a + b*Sinh[x]^2)^(3/2)/(3*b)}


(* ::Section::Closed:: *)
(*Miscellaneous problems*)


(* Miscellaneous integrands involving hyperbolic functions *)
{(Cosh[x] - Sinh[x])/(Cosh[x] + Sinh[x]), x, 2, (-(1/2))*(Cosh[x] - Sinh[x])^2}
{Sinh[x]*(Cosh[x] + Sinh[x]), x, 5, -(x/2) + (1/2)*Cosh[x]*Sinh[x] + Sinh[x]^2/2}

{(1 + Sinh[x]^2)/(1 + Cosh[x] + Sinh[x]), x, -13, (3*x)/4 + Cosh[x]/2 - Cosh[x]^2/8 - Log[1 + Cosh[x] + Sinh[x]] + (1/4)*Cosh[x]*Sinh[x] - Sinh[x]^2/8}
{x^5*Cosh[a + b*x^3]^7*Sinh[a + b*x^3], x, 6, -((35*x^3)/(3072*b)) + (x^3*Cosh[a + b*x^3]^8)/(24*b) - (35*Cosh[a + b*x^3]*Sinh[a + b*x^3])/(3072*b^2) - (35*Cosh[a + b*x^3]^3*Sinh[a + b*x^3])/(4608*b^2) - (7*Cosh[a + b*x^3]^5*Sinh[a + b*x^3])/(1152*b^2) - (Cosh[a + b*x^3]^7*Sinh[a + b*x^3])/(192*b^2)}

(* {Csch[x^5]/x, x, Int[Csch[x^5]/x, x]} *)

{Cosh[x]^2/(1 + E^x), x, 6, -(1/8)/E^(2*x) + 1/(E^x*4) + E^x/4 + (3*x)/4 - Log[1 + E^x], -(1/8)/E^(2*x) + 1/(E^x*4) + E^x/4 + (3*Log[E^x])/4 - Log[1 + E^x]}


{Sqrt[1 + Sech[x]]*Sech[x]*Tanh[x]^3, x, 4, (-(4/5))*(1 + Sech[x])^(5/2) + (2/7)*(1 + Sech[x])^(7/2)}
{Sqrt[1 + Csch[x]]*Csch[x]*Coth[x]^3, x, 4, (-(4/3))*(1 + Csch[x])^(3/2) + (4/5)*(1 + Csch[x])^(5/2) - (2/7)*(1 + Csch[x])^(7/2)}


{Cosh[x]^x*(Log[Cosh[x]] + x*Tanh[x]), x, 3, Cosh[x]^x}

{Csch[x]*Sqrt[1 + Log[Coth[x]]^2]*Sech[x], x, 3, (-(1/2))*ArcSinh[Log[Coth[x]]] - (1/2)*Log[Coth[x]]*Sqrt[1 + Log[Coth[x]]^2]}


{x^2/Sech[2*Log[x]]^(3/2), x, 7, (x*(3*Sqrt[1 + x^4] + (1 + x^4)^(3/2) - 3*ArcTanh[Sqrt[1 + x^4]]))/(12*Sqrt[2]*Sqrt[x^2/(1 + x^4)]*Sqrt[1 + x^4])}
{x^2/Csch[2*Log[x]]^(3/2), x, 7, -((x*(3*Sqrt[-1 + x^4] - (-1 + x^4)^(3/2) - 3*ArcTan[Sqrt[-1 + x^4]]))/(12*Sqrt[2]*Sqrt[-(x^2/(1 - x^4))]*Sqrt[-1 + x^4]))}
