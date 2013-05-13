(* ::Package:: *)

(* ::Title:: *)
(*Integration problems of the form *)
(*Csc[c+d x]^m (A+B Csc[c+d x]+C Csc[c+d x]^2) (a+b Csc[c+d x])^n*)


(* ::Section:: *)
(*Csc[c+d x]^m (a+b Csc[c+d x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Csc[c+d x]^m (a+b Csc[c+d x])^n*)


{Csc[x]^4/(a + b*Csc[x]), x, 6, -(((2*a^2 + b^2)*ArcTanh[Cos[x]])/(2*b^3)) + (2*a^3*ArcTanh[(a + b*Tan[x/2])/Sqrt[a^2 - b^2]])/(b^3*Sqrt[a^2 - b^2]) + (a*Cot[x])/b^2 - (Cot[x]*Csc[x])/(2*b)}
{Csc[x]^3/(a + b*Csc[x]), x, 6, (a*ArcTanh[Cos[x]])/b^2 - (2*a^2*ArcTanh[(a + b*Tan[x/2])/Sqrt[a^2 - b^2]])/(b^2*Sqrt[a^2 - b^2]) - Cot[x]/b}
{Csc[x]^2/(a + b*Csc[x]), x, 4, -(ArcTanh[Cos[x]]/b) + (2*a*ArcTanh[(a + b*Tan[x/2])/Sqrt[a^2 - b^2]])/(b*Sqrt[a^2 - b^2])}
{Csc[x]^1/(a + b*Csc[x]), x, 2, -((2*ArcTanh[(a + b*Tan[x/2])/Sqrt[a^2 - b^2]])/Sqrt[a^2 - b^2])}
{Sin[x]^1/(a + b*Csc[x]), x, 4, -((b*x)/a^2) - (2*b^2*ArcTanh[(a + b*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^2*Sqrt[a^2 - b^2]) - Cos[x]/a}
{Sin[x]^2/(a + b*Csc[x]), x, 4, ((a^2 + 2*b^2)*x)/(2*a^3) + (2*b^3*ArcTanh[(a + b*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^3*Sqrt[a^2 - b^2]) + (b*Cos[x])/a^2 - (Cos[x]*Sin[x])/(2*a)}
{Sin[x]^3/(a + b*Csc[x]), x, 5, -((b*(a^2 + 2*b^2)*x)/(2*a^4)) - (2*b^4*ArcTanh[(a + b*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^4*Sqrt[a^2 - b^2]) - ((2*a^2 + 3*b^2)*Cos[x])/(3*a^3) + (b*Cos[x]*Sin[x])/(2*a^2) - (Cos[x]*Sin[x]^2)/(3*a)}
{Sin[x]^4/(a + b*Csc[x]), x, 6, ((3*a^4 + 4*a^2*b^2 + 8*b^4)*x)/(8*a^5) + (2*b^5*ArcTanh[(a + b*Tan[x/2])/Sqrt[a^2 - b^2]])/(a^5*Sqrt[a^2 - b^2]) + (b*(2*a^2 + 3*b^2)*Cos[x])/(3*a^4) - ((3*a^2 + 4*b^2)*Cos[x]*Sin[x])/(8*a^3) + (b*Cos[x]*Sin[x]^2)/(3*a^2) - (Cos[x]*Sin[x]^3)/(4*a)}


(* Integrands of the form (a+b*Csc[c+d*x])^n where a^2-b^2!=0 *)
{(a + b*Csc[c + d*x])^3, x, 4, a^3*x - (b*(6*a^2 + b^2)*ArcTanh[Cos[c + d*x]])/(2*d) - (5*a*b^2*Cot[c + d*x])/(2*d) - (b^2*Cot[c + d*x]*(a + b*Csc[c + d*x]))/(2*d)}
{(a + b*Csc[c + d*x])^2, x, 3, a^2*x - (2*a*b*ArcTanh[Cos[c + d*x]])/d - (b^2*Cot[c + d*x])/d}
{1/(a + b*Csc[c + d*x]), x, 2, x/a + (2*b*ArcTanh[(a + b*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/(a*Sqrt[a^2 - b^2]*d)}
{1/(a + b*Csc[c + d*x])^2, x, 3, x/a^2 + (2*b*(2*a^2 - b^2)*ArcTanh[(a + b*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/(a^2*(a^2 - b^2)^(3/2)*d) - (b^2*Cot[c + d*x])/(a*(a^2 - b^2)*d*(a + b*Csc[c + d*x]))}
{1/(a + b*Csc[c + d*x])^3, x, 4, x/a^3 + (b*(6*a^4 - 5*a^2*b^2 + 2*b^4)*ArcTanh[(a + b*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/(a^3*(a^2 - b^2)^(5/2)*d) - (b^2*Cot[c + d*x])/(2*a*(a^2 - b^2)*d*(a + b*Csc[c + d*x])^2) - (b^2*(5*a^2 - 2*b^2)*Cot[c + d*x])/(2*a^2*(a^2 - b^2)^2*d*(a + b*Csc[c + d*x]))}
{1/(a + b*Csc[c + d*x])^4, x, 5, x/a^4 + (b*(8*a^6 - 8*a^4*b^2 + 7*a^2*b^4 - 2*b^6)*ArcTanh[(a + b*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/(a^4*(a^2 - b^2)^(7/2)*d) - (b^2*Cot[c + d*x])/(3*a*(a^2 - b^2)*d*(a + b*Csc[c + d*x])^3) - (b^2*(8*a^2 - 3*b^2)*Cot[c + d*x])/(6*a^2*(a^2 - b^2)^2*d*(a + b*Csc[c + d*x])^2) - (b^2*(26*a^4 - 17*a^2*b^2 + 6*b^4)*Cot[c + d*x])/(6*a^3*(a^2 - b^2)^3*d*(a + b*Csc[c + d*x]))}

{1/(3 + 5*Csc[c + d*x]), x, 2, -(x/12) - (5*ArcTan[Cos[c + d*x]/(3 + Sin[c + d*x])])/(6*d)}
{1/(5 + 3*Csc[c + d*x]), x, 2, x/5 + (3*ArcTanh[(1/4)*(5 + 3*Tan[(1/2)*(c + d*x)])])/(10*d)}


(* ::Subsection:: *)
(*Integrands of the form Csc[c+d x]^m (a+b Csc[c+d x])^(n/2)*)


(* ::Section:: *)
(*Csc[c+d x]^m (A+B Csc[c+d x]) (a+b Csc[c+d x])^n*)


(* ::Subsection:: *)
(*Integrands of the form Csc[c+d x]^m (A+B Csc[c+d x]) (a+b Csc[c+d x])^n*)


(* ::Subsection:: *)
(*Integrands of the form Csc[c+d x]^m (A+B Csc[c+d x]) (a+b Csc[c+d x])^(n/2)*)


(* ::Section:: *)
(*Csc[c+d x]^m (A+C Csc[c+d x]^2) (a+b Csc[c+d x])^n*)


(* ::Subsection:: *)
(*Integrands of the form Csc[c+d x]^m (A+C Csc[c+d x]^2) (a+b Csc[c+d x])^n*)


(* ::Subsection:: *)
(*Integrands of the form Csc[c+d x]^m (A+C Csc[c+d x]^2) (a+b Csc[c+d x])^(n/2)*)


(* ::Section:: *)
(*Csc[c+d x]^m (A+B Csc[c+d x]+C Csc[c+d x]^2) (a+b Csc[c+d x])^n*)


(* ::Subsection:: *)
(*Integrands of the form Csc[c+d x]^m (A+B Csc[c+d x]+C Csc[c+d x]^2) (a+b Csc[c+d x])^n*)


(* ::Subsection:: *)
(*Integrands of the form Csc[c+d x]^m (A+B Csc[c+d x]+C Csc[c+d x]^2) (a+b Csc[c+d x])^(n/2)*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Csc[c+d x]^(m/2) (A+B Csc[c+d x]+C Csc[c+d x]^2) (a+b Csc[c+d x])^n*)


{((a + b*Csc[x])*(A + B*Csc[x] + C*Csc[x]^2))/Csc[x]^(1/2), x, 7, -2*(b*B + a*C)*Cos[x]*Sqrt[Csc[x]] - (2/3)*b*C*Cos[x]*Csc[x]^(3/2) + 2*(b*B - a*(A - C))*Sqrt[Csc[x]]*EllipticE[Pi/4 - x/2, 2]*Sqrt[Sin[x]] - (2/3)*(3*A*b + 3*a*B + b*C)*Sqrt[Csc[x]]*EllipticF[Pi/4 - x/2, 2]*Sqrt[Sin[x]]}
