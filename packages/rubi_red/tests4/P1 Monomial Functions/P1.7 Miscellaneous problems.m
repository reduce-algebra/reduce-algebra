(* ::Package:: *)

(* ::Title:: *)
(*Miscellaneous integration problems*)


(* ::Section::Closed:: *)
(*Integrands of the form x^m (Sqrt[a+b x] + Sqrt[c+d x])^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (Sqrt[a+b x] + Sqrt[c+b x])^p*)


{x^2/(Sqrt[a + b*x] + Sqrt[c + b*x]), x, 6, (2*a^2*(a + b*x)^(3/2))/(3*b^3*(a - c)) - (4*a*(a + b*x)^(5/2))/(5*b^3*(a - c)) + (2*(a + b*x)^(7/2))/(7*b^3*(a - c)) - (2*c^2*(c + b*x)^(3/2))/(3*b^3*(a - c)) + (4*c*(c + b*x)^(5/2))/(5*b^3*(a - c)) - (2*(c + b*x)^(7/2))/(7*b^3*(a - c))}
{x/(Sqrt[a + b*x] + Sqrt[c + b*x]), x, 6, -((2*a*(a + b*x)^(3/2))/(3*b^2*(a - c))) + (2*(a + b*x)^(5/2))/(5*b^2*(a - c)) + (2*c*(c + b*x)^(3/2))/(3*b^2*(a - c)) - (2*(c + b*x)^(5/2))/(5*b^2*(a - c))}
{1/(Sqrt[a + b*x] + Sqrt[c + b*x]), x, 2, (2*(a + b*x)^(3/2))/(3*b*(a - c)) - (2*(c + b*x)^(3/2))/(3*b*(a - c))}
{1/(x*(Sqrt[a + b*x] + Sqrt[c + b*x])), x, 6, (2*Sqrt[a + b*x])/(a - c) - (2*Sqrt[c + b*x])/(a - c) - (2*Sqrt[a]*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(a - c) + (2*Sqrt[c]*ArcTanh[Sqrt[c + b*x]/Sqrt[c]])/(a - c)}
{1/(x^2*(Sqrt[a + b*x] + Sqrt[c + b*x])), x, 6, -(Sqrt[a + b*x]/((a - c)*x)) + Sqrt[c + b*x]/((a - c)*x) - (b*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(Sqrt[a]*(a - c)) + (b*ArcTanh[Sqrt[c + b*x]/Sqrt[c]])/((a - c)*Sqrt[c])}


{x^2/(Sqrt[a + b*x] + Sqrt[c + b*x])^2, x, 9, x^3/(3*(a - c)) + (2*c*x^3)/(3*(a - c)^2) + (b*x^4)/(2*(a - c)^2) - ((4*a*c - 5*(a + c)^2)*Sqrt[a + b*x]*Sqrt[c + b*x])/(32*b^3*(a - c)) + ((4*a*c - 5*(a + c)^2)*(a + b*x)^(3/2)*Sqrt[c + b*x])/(16*b^3*(a - c)^2) + (5*(a + c)*(a + b*x)^(3/2)*(c + b*x)^(3/2))/(12*b^3*(a - c)^2) - (x*(a + b*x)^(3/2)*(c + b*x)^(3/2))/(2*b^2*(a - c)^2) - ((4*a*c - 5*(a + c)^2)*ArcTanh[Sqrt[a + b*x]/Sqrt[c + b*x]])/(32*b^3)}
{x/(Sqrt[a + b*x] + Sqrt[c + b*x])^2, x, 8, x^2/(2*(a - c)) + (c*x^2)/(a - c)^2 + (2*b*x^3)/(3*(a - c)^2) - ((a + c)*Sqrt[a + b*x]*Sqrt[c + b*x])/(4*b^2*(a - c)) + ((a + c)*(a + b*x)^(3/2)*Sqrt[c + b*x])/(2*b^2*(a - c)^2) - (2*(a + b*x)^(3/2)*(c + b*x)^(3/2))/(3*b^2*(a - c)^2) - ((a + c)*ArcTanh[Sqrt[a + b*x]/Sqrt[c + b*x]])/(4*b^2)}
{1/(Sqrt[a + b*x] + Sqrt[c + b*x])^2, x, 5, (a - c)^2/(8*b*(Sqrt[a + b*x] + Sqrt[c + b*x])^4) + ArcTanh[Sqrt[a + b*x]/Sqrt[c + b*x]]/(2*b), x/(a - c) + (Sqrt[a + b*x]*Sqrt[c + b*x])/(2*b*(a - c)) - ((a + b*x)^(3/2)*Sqrt[c + b*x])/(b*(a - c)^2) + (c + b*x)^2/(b*(a - c)^2) + ArcTanh[Sqrt[a + b*x]/Sqrt[c + b*x]]/(2*b)}
{1/(x*(Sqrt[a + b*x] + Sqrt[c + b*x])^2), x, 8, (2*b*x)/(a - c)^2 - (2*Sqrt[a + b*x]*Sqrt[c + b*x])/(a - c)^2 - (2*(a + c)*ArcTanh[Sqrt[a + b*x]/Sqrt[c + b*x]])/(a - c)^2 + (4*Sqrt[a]*Sqrt[c]*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + b*x])])/(a - c)^2 + Log[x]/(a - c) + (2*c*Log[x])/(a - c)^2}
{1/(x^2*(Sqrt[a + b*x] + Sqrt[c + b*x])^2), x, 8, -(1/((a - c)*x)) - (2*c)/((a - c)^2*x) + (2*Sqrt[a + b*x]*Sqrt[c + b*x])/((a - c)^2*x) - (4*b*ArcTanh[Sqrt[a + b*x]/Sqrt[c + b*x]])/(a - c)^2 + (2*b*(a + c)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + b*x])])/(Sqrt[a]*(a - c)^2*Sqrt[c]) + (2*b*Log[x])/(a - c)^2}


{x^2/(Sqrt[a + b*x] + Sqrt[c + b*x])^3, x, 10, -((8*a^3*(a + b*x)^(3/2))/(3*b^3*(a - c)^3)) + (2*a^2*(a + 3*c)*(a + b*x)^(3/2))/(3*b^3*(a - c)^3) + (24*a^2*(a + b*x)^(5/2))/(5*b^3*(a - c)^3) - (4*a*(a + 3*c)*(a + b*x)^(5/2))/(5*b^3*(a - c)^3) - (24*a*(a + b*x)^(7/2))/(7*b^3*(a - c)^3) + (2*(a + 3*c)*(a + b*x)^(7/2))/(7*b^3*(a - c)^3) + (8*(a + b*x)^(9/2))/(9*b^3*(a - c)^3) + (8*c^3*(c + b*x)^(3/2))/(3*b^3*(a - c)^3) - (2*c^2*(3*a + c)*(c + b*x)^(3/2))/(3*b^3*(a - c)^3) - (24*c^2*(c + b*x)^(5/2))/(5*b^3*(a - c)^3) + (4*c*(3*a + c)*(c + b*x)^(5/2))/(5*b^3*(a - c)^3) + (24*c*(c + b*x)^(7/2))/(7*b^3*(a - c)^3) - (2*(3*a + c)*(c + b*x)^(7/2))/(7*b^3*(a - c)^3) - (8*(c + b*x)^(9/2))/(9*b^3*(a - c)^3)}
{x/(Sqrt[a + b*x] + Sqrt[c + b*x])^3, x, 10, (8*a^2*(a + b*x)^(3/2))/(3*b^2*(a - c)^3) - (2*a*(a + 3*c)*(a + b*x)^(3/2))/(3*b^2*(a - c)^3) - (16*a*(a + b*x)^(5/2))/(5*b^2*(a - c)^3) + (2*(a + 3*c)*(a + b*x)^(5/2))/(5*b^2*(a - c)^3) + (8*(a + b*x)^(7/2))/(7*b^2*(a - c)^3) - (8*c^2*(c + b*x)^(3/2))/(3*b^2*(a - c)^3) + (2*c*(3*a + c)*(c + b*x)^(3/2))/(3*b^2*(a - c)^3) + (16*c*(c + b*x)^(5/2))/(5*b^2*(a - c)^3) - (2*(3*a + c)*(c + b*x)^(5/2))/(5*b^2*(a - c)^3) - (8*(c + b*x)^(7/2))/(7*b^2*(a - c)^3)}
{1/(Sqrt[a + b*x] + Sqrt[c + b*x])^3, x, 6, (a - c)^2/(10*b*(Sqrt[a + b*x] + Sqrt[c + b*x])^5) - 1/(2*b*(Sqrt[a + b*x] + Sqrt[c + b*x])), -((8*a*(a + b*x)^(3/2))/(3*b*(a - c)^3)) + (2*(a + 3*c)*(a + b*x)^(3/2))/(3*b*(a - c)^3) + (8*(a + b*x)^(5/2))/(5*b*(a - c)^3) + (8*c*(c + b*x)^(3/2))/(3*b*(a - c)^3) - (2*(3*a + c)*(c + b*x)^(3/2))/(3*b*(a - c)^3) - (8*(c + b*x)^(5/2))/(5*b*(a - c)^3)}
{1/(x*(Sqrt[a + b*x] + Sqrt[c + b*x])^3), x, 6, (2*(a + 3*c)*Sqrt[a + b*x])/(a - c)^3 + (8*(a + b*x)^(3/2))/(3*(a - c)^3) - (2*(3*a + c)*Sqrt[c + b*x])/(a - c)^3 - (8*(c + b*x)^(3/2))/(3*(a - c)^3) - (2*Sqrt[a]*(a + 3*c)*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(a - c)^3 + (2*Sqrt[c]*(3*a + c)*ArcTanh[Sqrt[c + b*x]/Sqrt[c]])/(a - c)^3}
{1/(x^2*(Sqrt[a + b*x] + Sqrt[c + b*x])^3), x, 10, (8*b*Sqrt[a + b*x])/(a - c)^3 - ((a + 3*c)*Sqrt[a + b*x])/((a - c)^3*x) - (8*b*Sqrt[c + b*x])/(a - c)^3 + ((3*a + c)*Sqrt[c + b*x])/((a - c)^3*x) - (3*b*(3*a + c)*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(Sqrt[a]*(a - c)^3) - (3*b*(a + 3*c)*ArcTanh[Sqrt[c + b*x]/Sqrt[c]])/(Sqrt[c]*(-a + c)^3), (8*b*Sqrt[a + b*x])/(a - c)^3 - ((a + 3*c)*Sqrt[a + b*x])/((a - c)^3*x) - (8*b*Sqrt[c + b*x])/(a - c)^3 + ((3*a + c)*Sqrt[c + b*x])/((a - c)^3*x) - (8*Sqrt[a]*b*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(a - c)^3 - (b*(a + 3*c)*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(Sqrt[a]*(a - c)^3) + (8*b*Sqrt[c]*ArcTanh[Sqrt[c + b*x]/Sqrt[c]])/(a - c)^3 + (b*(3*a + c)*ArcTanh[Sqrt[c + b*x]/Sqrt[c]])/((a - c)^3*Sqrt[c])}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (Sqrt[a+b x] + Sqrt[a+c x])^p*)


{x^3/(Sqrt[a + b*x] + Sqrt[a + c*x]), x, 6, (2*a^2*(a + b*x)^(3/2))/(3*b^3*(b - c)) - (4*a*(a + b*x)^(5/2))/(5*b^3*(b - c)) + (2*(a + b*x)^(7/2))/(7*b^3*(b - c)) - (2*a^2*(a + c*x)^(3/2))/(3*(b - c)*c^3) + (4*a*(a + c*x)^(5/2))/(5*(b - c)*c^3) - (2*(a + c*x)^(7/2))/(7*(b - c)*c^3)}
{x^2/(Sqrt[a + b*x] + Sqrt[a + c*x]), x, 6, -((2*a*(a + b*x)^(3/2))/(3*b^2*(b - c))) + (2*(a + b*x)^(5/2))/(5*b^2*(b - c)) + (2*a*(a + c*x)^(3/2))/(3*(b - c)*c^2) - (2*(a + c*x)^(5/2))/(5*(b - c)*c^2)}
{x/(Sqrt[a + b*x] + Sqrt[a + c*x]), x, 2, (2*(a + b*x)^(3/2))/(3*b*(b - c)) - (2*(a + c*x)^(3/2))/(3*(b - c)*c)}
{1/(Sqrt[a + b*x] + Sqrt[a + c*x]), x, 6, (2*Sqrt[a + b*x])/(b - c) - (2*Sqrt[a + c*x])/(b - c) - (2*Sqrt[a]*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(b - c) + (2*Sqrt[a]*ArcTanh[Sqrt[a + c*x]/Sqrt[a]])/(b - c)}
{1/(x*(Sqrt[a + b*x] + Sqrt[a + c*x])), x, 6, -(Sqrt[a + b*x]/((b - c)*x)) + Sqrt[a + c*x]/((b - c)*x) - (b*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(Sqrt[a]*(b - c)) + (c*ArcTanh[Sqrt[a + c*x]/Sqrt[a]])/(Sqrt[a]*(b - c))}
{1/(x^2*(Sqrt[a + b*x] + Sqrt[a + c*x])), x, 8, -(Sqrt[a + b*x]/(2*(b - c)*x^2)) - (b*Sqrt[a + b*x])/(4*a*(b - c)*x) + Sqrt[a + c*x]/(2*(b - c)*x^2) + (c*Sqrt[a + c*x])/(4*a*(b - c)*x) + (b^2*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(4*a^(3/2)*(b - c)) - (c^2*ArcTanh[Sqrt[a + c*x]/Sqrt[a]])/(4*a^(3/2)*(b - c))}


{x^3/(Sqrt[a + b*x] + Sqrt[a + c*x])^2, x, 6, (a*x^2)/(b - c)^2 + ((b + c)*x^3)/(3*(b - c)^2) + (a^2*(b + c)*Sqrt[a + b*x]*Sqrt[a + c*x])/(4*b^2*(b - c)*c^2) + (a*(b + c)*(a + b*x)^(3/2)*Sqrt[a + c*x])/(2*b^2*(b - c)^2*c) - (2*(a + b*x)^(3/2)*(a + c*x)^(3/2))/(3*b*(b - c)^2*c) - (a^3*(b + c)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[a + c*x])])/(4*b^(5/2)*c^(5/2))}
{x^2/(Sqrt[a + b*x] + Sqrt[a + c*x])^2, x, 5, (2*a*x)/(b - c)^2 + ((b + c)*x^2)/(2*(b - c)^2) - (a*Sqrt[a + b*x]*Sqrt[a + c*x])/(2*b*(b - c)*c) - ((a + b*x)^(3/2)*Sqrt[a + c*x])/(b*(b - c)^2) + (a^2*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[a + c*x])])/(2*b^(3/2)*c^(3/2))}
{x/(Sqrt[a + b*x] + Sqrt[a + c*x])^2, x, 6, ((b + c)*x)/(b - c)^2 - (2*Sqrt[a + b*x]*Sqrt[a + c*x])/(b - c)^2 + (4*a*ArcTanh[Sqrt[a + b*x]/Sqrt[a + c*x]])/(b - c)^2 - (2*a*(b + c)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[a + c*x])])/(Sqrt[b]*(b - c)^2*Sqrt[c]) + (2*a*Log[x])/(b - c)^2}
{1/(Sqrt[a + b*x] + Sqrt[a + c*x])^2, x, 6, -((2*a)/((b - c)^2*x)) + (2*Sqrt[a + b*x]*Sqrt[a + c*x])/((b - c)^2*x) + (2*(b + c)*ArcTanh[Sqrt[a + b*x]/Sqrt[a + c*x]])/(b - c)^2 - (4*Sqrt[b]*Sqrt[c]*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[a + c*x])])/(b - c)^2 + ((b + c)*Log[x])/(b - c)^2}
{1/(x*(Sqrt[a + b*x] + Sqrt[a + c*x])^2), x, 5, -(a/((b - c)^2*x^2)) - (b + c)/((b - c)^2*x) + (Sqrt[a + b*x]*Sqrt[a + c*x])/(2*a*(b - c)*x) + (Sqrt[a + b*x]*(a + c*x)^(3/2))/(a*(b - c)^2*x^2) - ArcTanh[Sqrt[a + b*x]/Sqrt[a + c*x]]/(2*a)}
{1/(x^2*(Sqrt[a + b*x] + Sqrt[a + c*x])^2), x, 7, -((2*a)/(3*(b - c)^2*x^3)) - (b + c)/(2*(b - c)^2*x^2) + (2*Sqrt[a + b*x]*Sqrt[a + c*x])/(3*(b - c)^2*x^3) + ((b + c)*Sqrt[a + b*x]*Sqrt[a + c*x])/(6*a*(b - c)^2*x^2) - ((3*b^2 - 2*b*c + 3*c^2)*Sqrt[a + b*x]*Sqrt[a + c*x])/(12*a^2*(b - c)^2*x) + ((b + c)*ArcTanh[Sqrt[a + b*x]/Sqrt[a + c*x]])/(4*a^2)}


{x^4/(Sqrt[a + b*x] + Sqrt[a + c*x])^3, x, 10, -((8*a^2*(a + b*x)^(3/2))/(3*b^2*(b - c)^3)) + (2*a^2*(b + 3*c)*(a + b*x)^(3/2))/(3*b^3*(b - c)^3) + (8*a*(a + b*x)^(5/2))/(5*b^2*(b - c)^3) - (4*a*(b + 3*c)*(a + b*x)^(5/2))/(5*b^3*(b - c)^3) + (2*(b + 3*c)*(a + b*x)^(7/2))/(7*b^3*(b - c)^3) + (8*a^2*(a + c*x)^(3/2))/(3*(b - c)^3*c^2) - (2*a^2*(3*b + c)*(a + c*x)^(3/2))/(3*(b - c)^3*c^3) - (8*a*(a + c*x)^(5/2))/(5*(b - c)^3*c^2) + (4*a*(3*b + c)*(a + c*x)^(5/2))/(5*(b - c)^3*c^3) - (2*(3*b + c)*(a + c*x)^(7/2))/(7*(b - c)^3*c^3)}
{x^3/(Sqrt[a + b*x] + Sqrt[a + c*x])^3, x, 6, (8*a*(a + b*x)^(3/2))/(3*b*(b - c)^3) - (2*a*(b + 3*c)*(a + b*x)^(3/2))/(3*b^2*(b - c)^3) + (2*(b + 3*c)*(a + b*x)^(5/2))/(5*b^2*(b - c)^3) - (8*a*(a + c*x)^(3/2))/(3*(b - c)^3*c) + (2*a*(3*b + c)*(a + c*x)^(3/2))/(3*(b - c)^3*c^2) - (2*(3*b + c)*(a + c*x)^(5/2))/(5*(b - c)^3*c^2)}
{x^2/(Sqrt[a + b*x] + Sqrt[a + c*x])^3, x, 6, (8*a*Sqrt[a + b*x])/(b - c)^3 + (2*(b + 3*c)*(a + b*x)^(3/2))/(3*b*(b - c)^3) - (8*a*Sqrt[a + c*x])/(b - c)^3 - (2*(3*b + c)*(a + c*x)^(3/2))/(3*(b - c)^3*c) - (8*a^(3/2)*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(b - c)^3 + (8*a^(3/2)*ArcTanh[Sqrt[a + c*x]/Sqrt[a]])/(b - c)^3}
{x/(Sqrt[a + b*x] + Sqrt[a + c*x])^3, x, 10, (2*(b + 3*c)*Sqrt[a + b*x])/(b - c)^3 - (4*a*Sqrt[a + b*x])/((b - c)^3*x) - (2*(3*b + c)*Sqrt[a + c*x])/(b - c)^3 + (4*a*Sqrt[a + c*x])/((b - c)^3*x) - (6*Sqrt[a]*(b + c)*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(b - c)^3 + (6*Sqrt[a]*(b + c)*ArcTanh[Sqrt[a + c*x]/Sqrt[a]])/(b - c)^3, (2*(b + 3*c)*Sqrt[a + b*x])/(b - c)^3 - (4*a*Sqrt[a + b*x])/((b - c)^3*x) - (2*(3*b + c)*Sqrt[a + c*x])/(b - c)^3 + (4*a*Sqrt[a + c*x])/((b - c)^3*x) - (4*Sqrt[a]*b*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(b - c)^3 - (2*Sqrt[a]*(b + 3*c)*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(b - c)^3 + (4*Sqrt[a]*c*ArcTanh[Sqrt[a + c*x]/Sqrt[a]])/(b - c)^3 + (2*Sqrt[a]*(3*b + c)*ArcTanh[Sqrt[a + c*x]/Sqrt[a]])/(b - c)^3}
{1/(Sqrt[a + b*x] + Sqrt[a + c*x])^3, x, 12, -((2*a*Sqrt[a + b*x])/((b - c)^3*x^2)) - ((2*b + 3*c)*Sqrt[a + b*x])/((b - c)^3*x) + (2*a*Sqrt[a + c*x])/((b - c)^3*x^2) + ((3*b + 2*c)*Sqrt[a + c*x])/((b - c)^3*x) - (3*b*c*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(Sqrt[a]*(b - c)^3) + (3*b*c*ArcTanh[Sqrt[a + c*x]/Sqrt[a]])/(Sqrt[a]*(b - c)^3), -((2*a*Sqrt[a + b*x])/((b - c)^3*x^2)) - (b*Sqrt[a + b*x])/((b - c)^3*x) - ((b + 3*c)*Sqrt[a + b*x])/((b - c)^3*x) + (2*a*Sqrt[a + c*x])/((b - c)^3*x^2) + (c*Sqrt[a + c*x])/((b - c)^3*x) + ((3*b + c)*Sqrt[a + c*x])/((b - c)^3*x) + (b^2*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(Sqrt[a]*(b - c)^3) - (b*(b + 3*c)*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(Sqrt[a]*(b - c)^3) - (c^2*ArcTanh[Sqrt[a + c*x]/Sqrt[a]])/(Sqrt[a]*(b - c)^3) + (c*(3*b + c)*ArcTanh[Sqrt[a + c*x]/Sqrt[a]])/(Sqrt[a]*(b - c)^3)}


(* ::Section::Closed:: *)
(*Integrands involving roots of improper binomials*)


(* Integrands of the form f[x^m*(a+b*x^n)^p] where m==-n*p *)
(* Test to ensure NormalForm does not result in infinite recursion *)
{f[(a + b*x)/x], x, 1, Int[f[b + a/x], x]}
{f[(a + b*x^2)/x^2], x, 1, Int[f[b + a/x^2], x]}
{f[x/(a + b*x)], x, 0, Int[f[x/(a + b*x)], x]}
{f[x^2/(a + b*x^2)], x, 0, Int[f[x^2/(a + b*x^2)], x]}
{f[x^2/(a + b*x)^2], x, 0, Int[f[x^2/(a + b*x)^2], x]}
{f[x^4/(a + b*x^2)^2], x, 0, Int[f[x^4/(a + b*x^2)^2], x]}


(* ::Section::Closed:: *)
(*Integrands involving nested radicals*)


{Sqrt[x - Sqrt[-4 + x^2]], x, 1, (2*Sqrt[x - Sqrt[-4 + x^2]]*(2*x + Sqrt[-4 + x^2]))/3}
{Sqrt[1 + Sqrt[1 - x^2]], x, 1, (2*(1 + x^2 - Sqrt[1 - x^2])*Sqrt[1 + Sqrt[1 - x^2]])/(3*x)}


{Sqrt[b*x^2 + Sqrt[a + b^2*x^4]]/Sqrt[a + b^2*x^4], x, 1, ArcTanh[(Sqrt[2]*Sqrt[b]*x)/Sqrt[b*x^2 + Sqrt[a + b^2*x^4]]]/(Sqrt[2]*Sqrt[b])}
{Sqrt[-b*x^2 + Sqrt[a + b^2*x^4]]/Sqrt[a + b^2*x^4], x, 1, ArcTan[(Sqrt[2]*Sqrt[b]*x)/Sqrt[(-b)*x^2 + Sqrt[a + b^2*x^4]]]/(Sqrt[2]*Sqrt[b])}


{Sqrt[2*x^2 + Sqrt[3 + 4*x^4]]/((c + d*x)*Sqrt[3 + 4*x^4]), x, 3, ((1/2 - I/2)*ArcTan[(Sqrt[3]*d + 2*I*c*x)/(Sqrt[2*I*c^2 - Sqrt[3]*d^2]*Sqrt[Sqrt[3] - 2*I*x^2])])/Sqrt[2*I*c^2 - Sqrt[3]*d^2] - ((1/2 + I/2)*ArcTanh[(Sqrt[3]*d - 2*I*c*x)/(Sqrt[2*I*c^2 + Sqrt[3]*d^2]*Sqrt[Sqrt[3] + 2*I*x^2])])/Sqrt[2*I*c^2 + Sqrt[3]*d^2]}
{Sqrt[2*x^2 + Sqrt[3 + 4*x^4]]/((c + d*x)^2*Sqrt[3 + 4*x^4]), x, 5, ((1/2 - I/2)*d*Sqrt[Sqrt[3] - 2*I*x^2])/((2*I*c^2 - Sqrt[3]*d^2)*(c + d*x)) - ((1/2 + I/2)*d*Sqrt[Sqrt[3] + 2*I*x^2])/((2*I*c^2 + Sqrt[3]*d^2)*(c + d*x)) + ((1 + I)*c*ArcTan[(Sqrt[3]*d + 2*I*c*x)/(Sqrt[2*I*c^2 - Sqrt[3]*d^2]*Sqrt[Sqrt[3] - 2*I*x^2])])/(2*I*c^2 - Sqrt[3]*d^2)^(3/2) + ((1 - I)*c*ArcTanh[(Sqrt[3]*d - 2*I*c*x)/(Sqrt[2*I*c^2 + Sqrt[3]*d^2]*Sqrt[Sqrt[3] + 2*I*x^2])])/(2*I*c^2 + Sqrt[3]*d^2)^(3/2)}


{Sqrt[1 + Sqrt[1 + x^2]], x, 1, -((2*(1 - x^2 - Sqrt[1 + x^2])*Sqrt[1 + Sqrt[1 + x^2]])/(3*x))}
{Sqrt[5 + Sqrt[25 + x^2]], x, 1, -((2*(25 - x^2 - 5*Sqrt[25 + x^2])*Sqrt[5 + Sqrt[25 + x^2]])/(3*x))}
{Sqrt[1 + Sqrt[1 - x^2]], x, 1, (2*(1 + x^2 - Sqrt[1 - x^2])*Sqrt[1 + Sqrt[1 - x^2]])/(3*x)}
{Sqrt[x - Sqrt[-4 + x^2]], x, 1, (2*Sqrt[x - Sqrt[-4 + x^2]]*(2*x + Sqrt[-4 + x^2]))/3}


(* ::Section::Closed:: *)
(*Problems from Calculus textbooks*)


{(1 - 5*x^2)/(x^3*(1 + x^2)), x, 2, -(1/(2*x^2)) + 6*ArcTanh[1 + 2*x^2]}
{(2*x)/((-1 + x)*(5 + x^2)), x, 6, (1/3)*Sqrt[5]*ArcTan[x/Sqrt[5]] + (1/3)*Log[1 - x] - (1/6)*Log[5 + x^2]}
{(2 + x^2)/(2 + x), x, 2, -2*x + x^2/2 + 6*Log[2 + x]}
{1/((-3 + x)*(4 + x^2)), x, 5, (-(3/26))*ArcTan[x/2] + (1/13)*Log[3 - x] - (1/26)*Log[4 + x^2]}
{(-2 + 3*x^6)/(x*(5 + 2*x^6)), x, 2, (-2*Log[x])/5 + (19*Log[5 + 2*x^6])/60}


{(3 + 2*x)/((-2 + x)*(5 + x)), x, 2, Log[2 - x] + Log[5 + x]}
{x^4/(4 + 5*x^2 + x^4), x, 4, x - (8/3)*ArcTan[x/2] + ArcTan[x]/3}
{1/((1 + x)*(2 + x)^2*(3 + x)^3), x, 2, 1/(2 + x) + 1/(4*(3 + x)^2) + 5/(4*(3 + x)) + (1/8)*Log[1 + x] + 2*Log[2 + x] - (17/8)*Log[3 + x]}
{x/(-1 + x^2), x, 1, (1/2)*Log[1 - x^2]}
{(-1 + x^2)^(-2), x, 2, x/(2*(1 - x^2)) + ArcTanh[x]/2}
{x^2/(1 + x^2)^2, x, 2, -(x/(2*(1 + x^2))) + ArcTan[x]/2}
{1/(2 + 3*x), x, 1, Log[2 + 3*x]/3}
{1/(a^2 + x^2), x, 1, ArcTan[x/a]/a}
{1/(a + b*x^2), x, 1, ArcTan[(Sqrt[b]*x)/Sqrt[a]]/(Sqrt[a]*Sqrt[b])}
{1/(2 - x + x^2), x, 1, -((2*ArcTan[(1 - 2*x)/Sqrt[7]])/Sqrt[7])}


{x^2*(4 - x^2)^2, x, 2, (16*x^3)/3 - (8*x^5)/5 + x^7/7}
{x*(1 - x^3)^2, x, 2, x^2/2 - (2*x^5)/5 + x^8/8}
{(-4 + 5*x^2 + x^3)/x^2, x, 2, 4/x + 5*x + x^2/2}
{(-1 + x)/(3 - 4*x + 3*x^2), x, 3, ArcTan[(2 - 3*x)/Sqrt[5]]/(3*Sqrt[5]) + (1/6)*Log[3 - 4*x + 3*x^2]}


{(2 + x^3)^2, x, 2, 4*x + x^4 + x^7/7}
{(-4 + x^2)/(2 + x), x, 2, -2*x + x^2/2}
{1/((2 + x)*(1 + x^2)), x, 5, (2*ArcTan[x])/5 + (1/5)*Log[2 + x] - (1/10)*Log[1 + x^2]}
{1/((1 + x)*(1 + x^2)), x, 5, ArcTan[x]/2 + (1/2)*Log[1 + x] - (1/4)*Log[1 + x^2]}
{x/((1 + x)*(1 + x^2)), x, 5, ArcTan[x]/2 - (1/2)*Log[1 + x] + (1/4)*Log[1 + x^2]}
{(2*x + x^2)/(1 + x)^2, x, 2, (2 + x)^2/(1 + x)}
{(-10 + x^2)/(4 + 9*x^2 + 2*x^4), x, 3, ArcTan[x/2] - (3*ArcTan[Sqrt[2]*x])/Sqrt[2]}
{(31 + 5*x)/(11 - 4*x + 3*x^2), x, 3, -((103*ArcTan[(2 - 3*x)/Sqrt[29]])/(3*Sqrt[29])) + (5/6)*Log[11 - 4*x + 3*x^2]}


{(3 + x^2)/(-3 + x^2), x, 2, x - 2*Sqrt[3]*ArcTanh[x/Sqrt[3]]}
{(-1 + x^2)/(1 + x^2), x, 2, x - 2*ArcTan[x]}
{(-2 + x^2 + x^3)/x^4, x, 2, 2/(3*x^3) - x^(-1) + Log[x]}
{(1 + x + x^3)/x^2, x, 2, -(1/x) + x^2/2 + Log[x]}
{(-2 + x^2)/(x*(2 + x^2)), x, 2, -Log[x] + Log[2 + x^2]}


{(-3 + x)*(-7 + 4*x^2), x, 2, 21*x - (7*x^2)/2 - 4*x^3 + x^4}
{(-2 + 7*x)^3, x, 1, (1/28)*(2 - 7*x)^4}
{(-7 + 4*x^2)/(3 + 2*x), x, 2, -3*x + x^2 + Log[3 + 2*x]}
{(1 + x)/((-1 + x)*x^2), x, 2, 1/x + 2*Log[1 - x] - 2*Log[x]}
{(4 + 4*x)/(x^2*(1 + x^2)), x, 6, -4/x - 4*ArcTan[x] + 4*Log[x] - 2*Log[1 + x^2]}
{(2 + x)/(-1 + 2*x + x^2), x, 3, (1/4)*(2 + Sqrt[2])*Log[1 - Sqrt[2] + x] - ((1 - Sqrt[2])*Log[1 + Sqrt[2] + x])/(2*Sqrt[2])}
{(24 + 8*x)/(x*(-4 + x^2)), x, 5, 5*Log[2 - x] - 6*Log[x] + Log[2 + x]}


{1/(4*x^2 + 4*x^3 + x^4), x, 4, -(1/(4*x)) - 1/(4*(2 + x)) + (1/2)*ArcTanh[1 + x], -(1/(4*x)) - 1/(4*(2 + x)) - Log[x]/4 + (1/4)*Log[2 + x]}
{(1 + x^2)/(1 + x), x, 2, -x + x^2/2 + 2*Log[1 + x]}
{(-1 + 3*x - 3*x^2 + x^3)/x^2, x, 3, x^(-1) - 3*x + x^2/2 + 3*Log[x]}
{((3 - Sqrt[37])/2 + x)*((3 + Sqrt[37])/2 + x), x, 2, -7*x + (3*x^2)/2 + x^3/3}


(* ::Subsubsection::Closed:: *)
(*Grossman Calculus*)


{(-4 + x)/((1 + x^(1/3))*Sqrt[x]), x, 4, -30*x^(1/6) + 2*Sqrt[x] - (6*x^(5/6))/5 + (6*x^(7/6))/7 + 30*ArcTan[x^(1/6)]}
{(1 + Sqrt[x])/(x^(5/6) + x^(7/6)), x, 7, 3*x^(1/3) + 6*ArcTan[x^(1/6)] - 3*Log[1 + x^(1/3)]}
{(1 + Sqrt[x])/((1 + x^(1/3))*Sqrt[x]), x, 8, 6*x^(1/6) - 3*x^(1/3) + (3*x^(2/3))/2 - 6*ArcTan[x^(1/6)] + 3*Log[1 + x^(1/3)]}


(* ::Section::Closed:: *)
(*Miscellaneous problems*)


{Sqrt[2 + b/x^2]/(b + 2*x^2), x, 3, -(ArcSinh[Sqrt[b]/(Sqrt[2]*x)]/Sqrt[b])}
{Sqrt[2 - b/x^2]/(-b + 2*x^2), x, 3, -(ArcSin[Sqrt[b]/(Sqrt[2]*x)]/Sqrt[b])}


{1/(Sqrt[x] + Sqrt[1 + x]), x, 2, -((2*x^(3/2))/3) + (2/3)*(1 + x)^(3/2)}
{1/(Sqrt[-1 + x] + Sqrt[1 + x]), x, 2, (-(1/3))*(-1 + x)^(3/2) + (1/3)*(1 + x)^(3/2)}


{(x^(1/6) + (x^3)^(1/5))/Sqrt[x], x, 6, (3*x^(2/3))/2 + (10*Sqrt[x]*(x^3)^(1/5))/11}


{(2 + x)/Sqrt[4*x - x^2], x, 2, -Sqrt[4*x - x^2] - 4*ArcSin[1 - x/2]}
{(3 + x)/(6*x + x^2)^(1/3), x, 1, (3/4)*(6*x + x^2)^(2/3)}
{(4 + x)/(6*x - x^2)^(3/2), x, 1, -((12 - 7*x)/(9*Sqrt[6*x - x^2]))}
{1/((1 + x)*Sqrt[2*x + x^2]), x, 1, ArcTan[Sqrt[2*x + x^2]]}
{1/((1 + 2*x)*Sqrt[x + x^2]), x, 1, ArcTan[2*Sqrt[x + x^2]]}
{(-1 + x)/Sqrt[2*x - x^2], x, 1, -Sqrt[2*x - x^2]}
{Sqrt[x - x^2]/(1 + x), x, 4, Sqrt[x - x^2] - (3/2)*ArcSin[1 - 2*x] + Sqrt[2]*ArcTan[(1 - 3*x)/(2*Sqrt[2]*Sqrt[x - x^2])]}

{Sqrt[x^(1/4) + x], x, 3, (1/3)*x^(1/4)*Sqrt[x^(1/4) + x] + (2/3)*x*Sqrt[x^(1/4) + x] - (1/3)*ArcTanh[Sqrt[x]/Sqrt[x^(1/4) + x]]}
{Sqrt[x + x^(3/2)], x, 3, (32*(x + x^(3/2))^(3/2))/(105*x^(3/2)) - (16*(x + x^(3/2))^(3/2))/(35*x) + (4*(x + x^(3/2))^(3/2))/(7*Sqrt[x])}
{x*Sqrt[x + x^(3/2)], x, 5, (-(32/99))*(x + x^(3/2))^(3/2) + (512*(x + x^(3/2))^(3/2))/(3465*x^(3/2)) - (256*(x + x^(3/2))^(3/2))/(1155*x) + (64*(x + x^(3/2))^(3/2))/(231*Sqrt[x]) + (4/11)*Sqrt[x]*(x + x^(3/2))^(3/2)}


{(1 - x^2)*Sqrt[1/(2 - x^2)], x, 2, x/(2*Sqrt[1/(2 - x^2)])}


{Sqrt[x^2 + x^3 - x^4], x, 4, -(((1 - 2*x)*Sqrt[x^2 + x^3 - x^4])/(8*x)) - ((1 + x - x^2)*Sqrt[x^2 + x^3 - x^4])/(3*x) - (5*Sqrt[x^2 + x^3 - x^4]*ArcSin[(1 - 2*x)/Sqrt[5]])/(16*x*Sqrt[1 + x - x^2])}


{1/Sqrt[(a^2 + x^2)^3], x, 2, (x*(a^2 + x^2))/(a^2*Sqrt[(a^2 + x^2)^3])}


{Sqrt[x]/(1 + Sqrt[x] + x), x, 5, 2*Sqrt[x] - (2*ArcTan[(1 + 2*Sqrt[x])/Sqrt[3]])/Sqrt[3] - Log[1 + Sqrt[x] + x]}
{x/(1 + Sqrt[x] + x), x, 4, -2*Sqrt[x] + x + (4*ArcTan[(1 + 2*Sqrt[x])/Sqrt[3]])/Sqrt[3]}
{1/(Sqrt[x]*(1 + Sqrt[x] + x)^(7/2)), x, 4, (4*(1 + 2*Sqrt[x]))/(15*(1 + Sqrt[x] + x)^(5/2)) + (64*(1 + 2*Sqrt[x]))/(135*(1 + Sqrt[x] + x)^(3/2)) + (512*(1 + 2*Sqrt[x]))/(405*Sqrt[1 + Sqrt[x] + x])}


(* {Sqrt[1+x^2]/(1-x^3), x, 0} *)


{(-1 + x)/(1 + Sqrt[1 + x^2]), x, 9, -(1/x) + Sqrt[1 + x^2] + Sqrt[1 + x^2]/x - ArcSinh[x] - Log[1 + Sqrt[1 + x^2]]}

{(-x + x^3)/Sqrt[-2 + x^2], x, 4, Sqrt[-2 + x^2] + (1/3)*(-2 + x^2)^(3/2)}
{(x - x^2)/Sqrt[1 - x^2], x, 4, (-(1/2))*Sqrt[1 - x^2] - (1/2)*(1 - x)*Sqrt[1 - x^2] - ArcSin[x]/2}

{1/((1 + x)^(2/3)*(-1 + x^2)^(2/3)), x, 1, (3*(-1 + x^2)^(1/3))/(2*(1 + x)^(2/3))}

{(x*Sqrt[1 - x^2])/(1 + x), x, 3, (-(1/2))*Sqrt[1 - x^2] - (1 - x^2)^(3/2)/(2*(1 + x)) - ArcSin[x]/2}
{(x*(1 + x)^2)/Sqrt[1 - x^2], x, 4, -Sqrt[1 - x^2] - (1/3)*(1 + x)*Sqrt[1 - x^2] - (1/3)*(1 + x)^2*Sqrt[1 - x^2] + ArcSin[x]}


{(-1 + x^4)/(1 + x^4)^(3/2), x, 1, -(x/Sqrt[1 + x^4])}


{(1 - x^6)^(2/3) + (1 - x^6)^(2/3)/x^6, x, 5, -((1 - x^6)^(2/3)/(5*x^5)) + (1/5)*x*(1 - x^6)^(2/3)}


{(x^(-1 + m)*(2*a*m + b*(2*m - n)*x^n))/(2*(a + b*x^n)^(3/2)), x, 2, x^m/Sqrt[a + b*x^n]}


{(4 + 3*x^2 + 2*x^3)/(1 + x)^4, x, 2, -5/(3*(1 + x)^3) + 3/(1 + x) + 2*Log[1 + x]}
{x/((1 + x)^2*(1 + x^2)), x, 2, 1/(2*(1 + x)) + ArcTan[x]/2}
{(7 - 2*x + 3*x^2 - x^3 + x^4)/(2 + x), x, 2, -20*x + (9*x^2)/2 - x^3 + x^4/4 + 47*Log[2 + x]}
{(-1 + x^3)/(-1 + x), x, 2, x + x^2/2 + x^3/3}
{(2 + 2*x)/((-1 + x)^3*(1 + x^2)), x, 5, -(1/(1 - x)^2) - 1/(1 - x) + ArcTan[x]}


{(x - 2*x^3)/Sqrt[2 + 3*x], x, 3, (-(4/81))*Sqrt[2 + 3*x] - (10/81)*(2 + 3*x)^(3/2) + (8/135)*(2 + 3*x)^(5/2) - (4/567)*(2 + 3*x)^(7/2)}


{1/((1 + x)^(1/4) + Sqrt[1 + x]), x, 5, -4*(1 + x)^(1/4) + 2*Sqrt[1 + x] + 4*Log[1 + (1 + x)^(1/4)]}
{(1 + 2*x)/Sqrt[x + x^2], x, 1, 2*Sqrt[x + x^2]}
{1/(2*Sqrt[x]*(1 + x)), x, 2, ArcTan[Sqrt[x]]}
{1/(x*Sqrt[6*x - x^2]), x, 1, -(Sqrt[6*x - x^2]/(3*x))}
{(1 + Sqrt[x])*Sqrt[x], x, 2, (2*x^(3/2))/3 + x^2/2}
{(1 - Sqrt[x])/x^(1/3), x, 2, (3*x^(2/3))/2 - (6*x^(7/6))/7}
{Sqrt[x]/(1 + x^(1/3)), x, 6, -6*x^(1/6) + 2*Sqrt[x] - (6*x^(5/6))/5 + (6*x^(7/6))/7 + 6*ArcTan[x^(1/6)]}

{(1 + Sqrt[x])^(1/3)/x, x, 7, 6*(1 + Sqrt[x])^(1/3) - 2*Sqrt[3]*ArcTan[(1 + 2*(1 + Sqrt[x])^(1/3))/Sqrt[3]] + 2*Log[1 - (1 + Sqrt[x])^(1/3)] - Log[1 + (1 + Sqrt[x])^(1/3) + (1 + Sqrt[x])^(2/3)]}

{1 - Sqrt[x], x, 1, x - (2*x^(3/2))/3}
{1 - x^(1/4), x, 1, x - (4*x^(5/4))/5}
{(1 - Sqrt[x])/(1 + x^(1/4)), x, 2, x - (4*x^(5/4))/5}

{1/Sqrt[(a + b*x)*(c + d*x)], x, 2, ArcTanh[(b*c + a*d + 2*b*d*x)/(2*Sqrt[b]*Sqrt[d]*Sqrt[a*c + (b*c + a*d)*x + b*d*x^2])]/(Sqrt[b]*Sqrt[d])}
{1/Sqrt[(a + b*x)*(c - d*x)], x, 2, -(ArcTan[(b*c - a*d - 2*b*d*x)/(2*Sqrt[b]*Sqrt[d]*Sqrt[a*c + (b*c - a*d)*x - b*d*x^2])]/(Sqrt[b]*Sqrt[d]))}

{1/(Sqrt[x]*(1 - x^2)), x, 4, ArcTan[Sqrt[x]] + ArcTanh[Sqrt[x]]}
{Sqrt[x]/(x - x^3), x, 5, ArcTan[Sqrt[x]] + ArcTanh[Sqrt[x]]}

{x/(2 - Sqrt[3] + (1 + Sqrt[3])*x + x^2), x, 3, ArcTanh[(1 + Sqrt[3] + 2*x)/Sqrt[-4 + 6*Sqrt[3]]]/Sqrt[-13 + 8*Sqrt[3]] + (1/2)*Log[2 - Sqrt[3] + (1 + Sqrt[3])*x + x^2], ((1 + Sqrt[3])*ArcTanh[(1 + Sqrt[3] + 2*x)/Sqrt[2*(-2 + 3*Sqrt[3])]])/Sqrt[2*(-2 + 3*Sqrt[3])] + (1/2)*Log[2 - Sqrt[3] + (1 + Sqrt[3])*x + x^2]}
{Sqrt[x^2 + x^3], x, 2, -((4*(x^2 + x^3)^(3/2))/(15*x^3)) + (2*(x^2 + x^3)^(3/2))/(5*x^2)}
{1/((1 + x)*Sqrt[2*x + x^2]), x, 1, ArcTan[Sqrt[2*x + x^2]]}
{Sqrt[1 - Sqrt[x] - x]*Sqrt[x], x, 5, (9/32)*(1 + 2*Sqrt[x])*Sqrt[1 - Sqrt[x] - x] + (5/12)*(1 - Sqrt[x] - x)^(3/2) - (1/2)*(1 - Sqrt[x] - x)^(3/2)*Sqrt[x] + (45/64)*ArcSin[(1 + 2*Sqrt[x])/Sqrt[5]]}

{(1 + Sqrt[-3 + x])^(1/3), x, 4, (-(3/2))*(1 + Sqrt[-3 + x])^(4/3) + (6/7)*(1 + Sqrt[-3 + x])^(7/3)}
{1/Sqrt[3 + Sqrt[-1 + 2*x]], x, 4, -6*Sqrt[3 + Sqrt[-1 + 2*x]] + (2/3)*(3 + Sqrt[-1 + 2*x])^(3/2)}

(* {(Sqrt[x]+x)^(2/3), x, 0} *)
(* {(-3*x+x^2)^(-1/3), x, 0} *)


{Sqrt[1 - x]/(1 + Sqrt[x]), x, 4, -Sqrt[1 - x] - (1 - x)^(3/2)/(1 + Sqrt[x]) - ArcSin[Sqrt[x]]}
{Sqrt[1 - x]/(1 - Sqrt[x]), x, 4, -Sqrt[1 - x] - (1 - x)^(3/2)/(1 - Sqrt[x]) + ArcSin[Sqrt[x]]}


{x/(x - Sqrt[1 + x^2]), x, 3, -(x^3/3) - (1/3)*(1 + x^2)^(3/2)}
{x/(x - Sqrt[1 - x^2]), x, 6, x/2 + Sqrt[1 - x^2]/2 - ArcTanh[Sqrt[2]*x]/(2*Sqrt[2]) - ArcTanh[Sqrt[2]*Sqrt[1 - x^2]]/(2*Sqrt[2])}
{x/(x - Sqrt[1 + 2*x^2]), x, 6, -x - Sqrt[1 + 2*x^2] + ArcTan[x] + ArcTan[Sqrt[1 + 2*x^2]]}


{1/(Sqrt[-1 + x]*Sqrt[1 + x]*Sqrt[-1 + 2*x^2]), x, 0, (-I)*EllipticF[I*ArcCosh[x], 2]}


(* Contributed by Manuel Bronstein, 24 November 2000 *)
{x/Sqrt[x^4 + 10*x^2 - 96*x - 71], x, 0, -Log[(x^6 + 15*x^4 - 80*x^3 + 27*x^2 - 528*x + 781)*Sqrt[x^4 + 10*x^2 - 96*x - 71] - x^8 - 20*x^6 + 128*x^5 - 54*x^4 + 1408*x^3 - 3124*x^2 - 10001]/8}


{Sqrt[x]*Sqrt[Sqrt[x] + x], x, 6, (5*Sqrt[Sqrt[x] + x])/32 - (5/48)*Sqrt[x]*Sqrt[Sqrt[x] + x] + (1/12)*x*Sqrt[Sqrt[x] + x] + (1/2)*x^(3/2)*Sqrt[Sqrt[x] + x] - (5/32)*ArcTanh[Sqrt[x]/Sqrt[Sqrt[x] + x]]}

{1/((1 + x^4)*Sqrt[-x^2 + Sqrt[1 + x^4]]), x, 0, ArcCot[Sqrt[-x^2 + Sqrt[1 + x^4]]/x]}

{(1 + x^(1/3))/(1 + Sqrt[x]), x, 9, -3*x^(1/3) + 2*Sqrt[x] + (6*x^(5/6))/5 - 2*Sqrt[3]*ArcTan[(1 - 2*x^(1/6))/Sqrt[3]] - 4*Log[1 + x^(1/6)] - Log[1 - x^(1/6) + x^(1/3)]}
{(1 + x^(1/3))/(1 + x^(1/4)), x, 9, 12*x^(1/12) + 4*x^(1/4) - 3*x^(1/3) - 2*Sqrt[x] + (12*x^(7/12))/7 + (4*x^(3/4))/3 - (6*x^(5/6))/5 + (12*x^(13/12))/13 + 4*Sqrt[3]*ArcTan[(1 - 2*x^(1/12))/Sqrt[3]] - 8*Log[1 + x^(1/12)] - 2*Log[1 - x^(1/12) + x^(1/6)]}


(* {1/Sqrt[a*x+b*x^3], x, 0} *)

{x^2/(-1 + x^2 + Sqrt[1 - x^2]), x, 6, x + ArcSin[x]}
