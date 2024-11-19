(* ::Package:: *)

(* ::Title:: *)
(*Integrands of the form *)
(*Cot[c+d x]^m (A+B Cot[c+d x]+C Cot[c+d x]^2) (a+b Cot[c+d x])^n*)


(* ::Section::Closed:: *)
(*Integrands of the form Cot[c+d x]^m (a+b Cot[c+d x])^n*)


{Cot[x]*(1 + Cot[x])^(3/2), x, 8, (1 - I)^(3/2)*ArcTanh[Sqrt[1 + Cot[x]]/Sqrt[1 - I]] + (1 + I)^(3/2)*ArcTanh[Sqrt[1 + Cot[x]]/Sqrt[1 + I]] - 2*Sqrt[1 + Cot[x]] - (2/3)*(1 + Cot[x])^(3/2)}
{Cot[x]*Sqrt[1 + Cot[x]], x, 7, Sqrt[1 - I]*ArcTanh[Sqrt[1 + Cot[x]]/Sqrt[1 - I]] + Sqrt[1 + I]*ArcTanh[Sqrt[1 + Cot[x]]/Sqrt[1 + I]] - 2*Sqrt[1 + Cot[x]]}
{Cot[x]/Sqrt[1 + Cot[x]], x, 5, ArcTanh[Sqrt[1 + Cot[x]]/Sqrt[1 - I]]/Sqrt[1 - I] + ArcTanh[Sqrt[1 + Cot[x]]/Sqrt[1 + I]]/Sqrt[1 + I]}
{Cot[x]/(1 + Cot[x])^(3/2), x, 6, (-(1/4))*(1 - I)^(5/2)*ArcTanh[Sqrt[1 + Cot[x]]/Sqrt[1 - I]] - (1/4)*(1 + I)^(5/2)*ArcTanh[Sqrt[1 + Cot[x]]/Sqrt[1 + I]] - 1/Sqrt[1 + Cot[x]]}


{Cot[x]^2*(1 + Cot[x])^(3/2), x, 8, -((2*ArcTanh[Sqrt[1 + Cot[x]]/Sqrt[1 - I]])/Sqrt[1 - I]) - (2*ArcTanh[Sqrt[1 + Cot[x]]/Sqrt[1 + I]])/Sqrt[1 + I] + 2*Sqrt[1 + Cot[x]] - (2/5)*(1 + Cot[x])^(5/2)}
{Cot[x]^2*Sqrt[1 + Cot[x]], x, 6, (1/2)*(1 - I)^(5/2)*ArcTanh[Sqrt[1 + Cot[x]]/Sqrt[1 - I]] + (1/2)*(1 + I)^(5/2)*ArcTanh[Sqrt[1 + Cot[x]]/Sqrt[1 + I]] - (2/3)*(1 + Cot[x])^(3/2)}
{Cot[x]^2/Sqrt[1 + Cot[x]], x, 6, (1/2)*(1 - I)^(3/2)*ArcTanh[Sqrt[1 + Cot[x]]/Sqrt[1 - I]] + (1/2)*(1 + I)^(3/2)*ArcTanh[Sqrt[1 + Cot[x]]/Sqrt[1 + I]] - 2*Sqrt[1 + Cot[x]]}
{Cot[x]^2/(1 + Cot[x])^(3/2), x, 7, (1/2)*Sqrt[1 - I]*ArcTanh[Sqrt[1 + Cot[x]]/Sqrt[1 - I]] + (1/2)*Sqrt[1 + I]*ArcTanh[Sqrt[1 + Cot[x]]/Sqrt[1 + I]] + 1/Sqrt[1 + Cot[x]]}
{Cot[x]^2/(1 + Cot[x])^(5/2), x, 9, ArcTanh[Sqrt[1 + Cot[x]]/Sqrt[1 - I]]/(2*Sqrt[1 - I]) + ArcTanh[Sqrt[1 + Cot[x]]/Sqrt[1 + I]]/(2*Sqrt[1 + I]) + 1/(3*(1 + Cot[x])^(3/2)) - 1/Sqrt[1 + Cot[x]]}


(* ::Section::Closed:: *)
(*Integrands of the form Cot[c+d x]^m (A+B Cot[c+d x]) (a+b Cot[c+d x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Cot[c+d x]^m (A+B Cot[c+d x]) (a+b Cot[c+d x])^n*)
(**)


(* ::Subsubsection:: *)
(*n>0*)


(* ::Subsubsection::Closed:: *)
(*n<0*)


{(A + B*Cot[c + d*x])/(a + b*Cot[c + d*x]), x, 4, ((a*A + b*B)*x)/(a^2 + b^2) - ((A*b - a*B)*Log[a + b*Cot[c + d*x]])/((a^2 + b^2)*d) - ((A*b - a*B)*Log[Sin[c + d*x]])/((a^2 + b^2)*d)}


{(A + B*Cot[c + d*x])/(a + b*Cot[c + d*x])^2, x, 5, ((a^2*A - A*b^2 + 2*a*b*B)*x)/(a^2 + b^2)^2 + (A*b - a*B)/((a^2 + b^2)*d*(a + b*Cot[c + d*x])) - ((2*a*A*b - a^2*B + b^2*B)*Log[a + b*Cot[c + d*x]])/((a^2 + b^2)^2*d) - ((2*a*A*b - a^2*B + b^2*B)*Log[Sin[c + d*x]])/((a^2 + b^2)^2*d)}


{(A + B*Cot[c + d*x])/(a + b*Cot[c + d*x])^3, x, 6, ((a^3*A - 3*a*A*b^2 + 3*a^2*b*B - b^3*B)*x)/(a^2 + b^2)^3 + (A*b - a*B)/(2*(a^2 + b^2)*d*(a + b*Cot[c + d*x])^2) + (2*a*A*b - a^2*B + b^2*B)/((a^2 + b^2)^2*d*(a + b*Cot[c + d*x])) - ((3*a^2*A*b - A*b^3 - a^3*B + 3*a*b^2*B)*Log[a + b*Cot[c + d*x]])/((a^2 + b^2)^3*d) - ((3*a^2*A*b - A*b^3 - a^3*B + 3*a*b^2*B)*Log[Sin[c + d*x]])/((a^2 + b^2)^3*d)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cot[c+d x]^m (A+B Cot[c+d x]) (a+b Cot[c+d x])^(n/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{(A + B*Cot[c + d*x])*(a + b*Cot[c + d*x])^(5/2), x, 8, ((a - I*b)^(5/2)*(I*A + B)*ArcTanh[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a - I*b]])/d - (I*(a + I*b)^(5/2)*(A + I*B)*ArcTanh[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a + I*b]])/d - (2*(2*a*A*b + a^2*B - b^2*B)*Sqrt[a + b*Cot[c + d*x]])/d - (2*(A*b + a*B)*(a + b*Cot[c + d*x])^(3/2))/(3*d) - (2*B*(a + b*Cot[c + d*x])^(5/2))/(5*d)}
{(A + B*Cot[c + d*x])*(a + b*Cot[c + d*x])^(3/2), x, 7, ((a - I*b)^(3/2)*(I*A + B)*ArcTanh[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a - I*b]])/d - (I*(a + I*b)^(3/2)*(A + I*B)*ArcTanh[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a + I*b]])/d - (2*(A*b + a*B)*Sqrt[a + b*Cot[c + d*x]])/d - (2*B*(a + b*Cot[c + d*x])^(3/2))/(3*d)}
{(A + B*Cot[c + d*x])*(a + b*Cot[c + d*x])^(1/2), x, 6, (Sqrt[a - I*b]*(I*A + B)*ArcTanh[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a - I*b]])/d - (I*Sqrt[a + I*b]*(A + I*B)*ArcTanh[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a + I*b]])/d - (2*B*Sqrt[a + b*Cot[c + d*x]])/d}


{(-a + b*Cot[c + d*x])*(a + b*Cot[c + d*x])^(5/2), x, 8, -(((I*a - b)*(a - I*b)^(5/2)*ArcTanh[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a - I*b]])/d) + (I*(a - I*b)*(a + I*b)^(5/2)*ArcTanh[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a + I*b]])/d + (2*b*(a^2 + b^2)*Sqrt[a + b*Cot[c + d*x]])/d - (2*b*(a + b*Cot[c + d*x])^(5/2))/(5*d)}
{(-a + b*Cot[c + d*x])*(a + b*Cot[c + d*x])^(3/2), x, 7, -((I*Sqrt[a - I*b]*(a^2 + b^2)*ArcTanh[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a - I*b]])/d) + (I*Sqrt[a + I*b]*(a^2 + b^2)*ArcTanh[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a + I*b]])/d - (2*b*(a + b*Cot[c + d*x])^(3/2))/(3*d)}
{(-a + b*Cot[c + d*x])*(a + b*Cot[c + d*x])^(1/2), x, 7, -((I*(a^2 + b^2)*ArcTanh[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a - I*b]])/(Sqrt[a - I*b]*d)) + (I*(a^2 + b^2)*ArcTanh[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a + I*b]])/(Sqrt[a + I*b]*d) - (2*b*Sqrt[a + b*Cot[c + d*x]])/d}








(* ::Subsubsection::Closed:: *)
(*n<0*)


{(1 + I*Cot[c + d*x])/Sqrt[a + b*Cot[c + d*x]], x, 2, (2*I*ArcTanh[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a - I*b]])/(Sqrt[a - I*b]*d)}
{(1 - I*Cot[c + d*x])/Sqrt[a + b*Cot[c + d*x]], x, 2, -((2*I*ArcTanh[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a + I*b]])/(Sqrt[a + I*b]*d))}


{(A + B*Cot[c + d*x])/(a + b*Cot[c + d*x])^(1/2), x, 5, ((I*A + B)*ArcTanh[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a - I*b]])/(Sqrt[a - I*b]*d) - (I*(A + I*B)*ArcTanh[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a + I*b]])/(Sqrt[a + I*b]*d)}
{(A + B*Cot[c + d*x])/(a + b*Cot[c + d*x])^(3/2), x, 6, ((I*A + B)*ArcTanh[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a - I*b]])/((a - I*b)^(3/2)*d) - (I*(A + I*B)*ArcTanh[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a + I*b]])/((a + I*b)^(3/2)*d) + (2*(A*b - a*B))/((a^2 + b^2)*d*Sqrt[a + b*Cot[c + d*x]])}
{(A + B*Cot[c + d*x])/(a + b*Cot[c + d*x])^(5/2), x, 7, ((I*A + B)*ArcTanh[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a - I*b]])/((a - I*b)^(5/2)*d) - (I*(A + I*B)*ArcTanh[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a + I*b]])/((a + I*b)^(5/2)*d) + (2*(A*b - a*B))/(3*(a^2 + b^2)*d*(a + b*Cot[c + d*x])^(3/2)) + (2*(2*a*A*b - a^2*B + b^2*B))/((a^2 + b^2)^2*d*Sqrt[a + b*Cot[c + d*x]])}


{(-a + b*Cot[c + d*x])/(a + b*Cot[c + d*x])^(1/2), x, 5, -(((I*a - b)*ArcTanh[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a - I*b]])/(Sqrt[a - I*b]*d)) + (I*(a - I*b)*ArcTanh[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a + I*b]])/(Sqrt[a + I*b]*d)}
{(-a + b*Cot[c + d*x])/(a + b*Cot[c + d*x])^(3/2), x, 6, -((I*(a + I*b)*ArcTanh[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a - I*b]])/((a - I*b)^(3/2)*d)) + ((I*a + b)*ArcTanh[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a + I*b]])/((a + I*b)^(3/2)*d) - (4*a*b)/((a^2 + b^2)*d*Sqrt[a + b*Cot[c + d*x]])}
{(-a + b*Cot[c + d*x])/(a + b*Cot[c + d*x])^(5/2), x, 7, -((I*(a + I*b)*ArcTanh[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a - I*b]])/((a - I*b)^(5/2)*d)) + ((I*a + b)*ArcTanh[Sqrt[a + b*Cot[c + d*x]]/Sqrt[a + I*b]])/((a + I*b)^(5/2)*d) - (4*a*b)/(3*(a^2 + b^2)*d*(a + b*Cot[c + d*x])^(3/2)) - (2*b*(3*a^2 - b^2))/((a^2 + b^2)^2*d*Sqrt[a + b*Cot[c + d*x]])}


(* ::Subsection:: *)
(*Integrands of the form Cot[c+d x]^(m/2) (A+B Cot[c+d x]) (a+b Cot[c+d x])^n*)


(* ::Subsection:: *)
(*Integrands of the form Cot[c+d x]^(m/2) (A+B Cot[c+d x]) (a+b Cot[c+d x])^(n/2)*)
(**)


(* ::Subsection:: *)
(*Integrands of the form Cot[c+d x]^m (A+B Cot[c+d x]) (a+b Cot[c+d x])^(n/3)*)
(**)


(* ::Subsection:: *)
(*Integrands of the form Sec[c+d x]^(m/2) (A+B Cot[c+d x]) (a+b Cot[c+d x])^n*)


(* ::Subsection:: *)
(*Integrands of the form Sec[c+d x]^(m/2) (A+B Cot[c+d x]) (a+b Cot[c+d x])^(n/2)*)


(* ::Section:: *)
(*Integrands of the form Cot[c+d x]^m (A+C Cot[c+d x]^2) (a+b Cot[c+d x])^n*)


(* ::Section:: *)
(*Integrands of the form Cot[c+d x]^m (B Cot[c+d x]+C Cot[c+d x]^2) (a+b Cot[c+d x])^n*)


(* ::Section:: *)
(*Integrands of the form Cot[c+d x]^m (A+B Cot[c+d x]+C Cot[c+d x]^2) (a+b Cot[c+d x])^n*)
