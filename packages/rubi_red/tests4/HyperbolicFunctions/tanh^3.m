(* ::Package:: *)

(* ::Section:: *)
(*Integrands of the form Hyper[c+d x]^m (a+b Tanh[c+d x]^3)^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sinh[c+d x]^m (a+b Tanh[c+d x]^3)^n*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Sinh[c + d*x]^4*(a + b*Tanh[c + d*x]^3), x, 8, (3*a*x)/8 + (15*b*x)/8 - (3*a*Cosh[c + d*x]*Sinh[c + d*x])/(8*d) + (a*Cosh[c + d*x]*Sinh[c + d*x]^3)/(4*d) - (15*b*Tanh[c + d*x])/(8*d) - (5*b*Sinh[c + d*x]^2*Tanh[c + d*x])/(8*d) + (b*Sinh[c + d*x]^4*Tanh[c + d*x])/(4*d)}
{Sinh[c + d*x]^3*(a + b*Tanh[c + d*x]^3), x, 4, -(((a + 2*b)*Cosh[c + d*x])/d) + ((a + b)*Cosh[c + d*x]^3)/(3*d) - (b*Sech[c + d*x])/d}
{Sinh[c + d*x]^2*(a + b*Tanh[c + d*x]^3), x, 6, -(a*x)/2 - (3*b*x)/2 + (a*Cosh[c + d*x]*Sinh[c + d*x])/(2*d) + (3*b*Tanh[c + d*x])/(2*d) + (b*Sinh[c + d*x]^2*Tanh[c + d*x])/(2*d)}
{Sinh[c + d*x]^1*(a + b*Tanh[c + d*x]^3), x, 4, ((a + b)*Cosh[c + d*x])/d + (b*Sech[c + d*x])/d}
{Csch[c + d*x]^1*(a + b*Tanh[c + d*x]^3), x, 4, -((a*ArcTanh[Cosh[c + d*x]])/d) - (b*Sech[c + d*x])/d}
{Csch[c + d*x]^2*(a + b*Tanh[c + d*x]^3), x, 4, -((a*Coth[c + d*x])/d) + (b*Tanh[c + d*x])/d}
{Csch[c + d*x]^3*(a + b*Tanh[c + d*x]^3), x, 5, ((a - 2*b)*ArcTanh[Cosh[c + d*x]])/(2*d) - ((a - 2*b)*Sech[c + d*x])/(2*d) + (a*Sech[c + d*x])/(2*d*(1 - Cosh[c + d*x]^2))}
{Csch[c + d*x]^4*(a + b*Tanh[c + d*x]^3), x, 7, (a*Coth[c + d*x])/d - (b*Coth[c + d*x])/d - (a*Coth[c + d*x]^3)/(3*d) - (b*Tanh[c + d*x])/d}


{Sinh[c + d*x]^4*(a + b*Tanh[c + d*x]^3)^2, x, 6, ((3*a^2 + 30*a*b + 35*b^2)*x)/8 - ((3*a^2 + 30*a*b + 35*b^2)*Tanh[c + d*x])/(8*d) - ((3*a^2 + 30*a*b + 35*b^2)*Tanh[c + d*x]^3)/(24*d) + ((a + b)^2*Tanh[c + d*x]^5)/(4*d*(1 - Tanh[c + d*x]^2)^2) - ((a + b)*(a + 9*b)*Tanh[c + d*x]^5)/(8*d*(1 - Tanh[c + d*x]^2))}
{Sinh[c + d*x]^3*(a + b*Tanh[c + d*x]^3)^2, x, 4, -(((a + b)*(a + 3*b)*Cosh[c + d*x])/d) + ((a + b)^2*Cosh[c + d*x]^3)/(3*d) - (b*(2*a + 3*b)*Sech[c + d*x])/d + (b^2*Sech[c + d*x]^3)/(3*d)}
{Sinh[c + d*x]^2*(a + b*Tanh[c + d*x]^3)^2, x, 4, -((a + b)*(a + 5*b)*x)/2 + (a + b)^2/(4*d*(1 - Tanh[c + d*x])) + (2*b*(a + b)*Tanh[c + d*x])/d + (b^2*Tanh[c + d*x]^3)/(3*d) - (a + b)^2/(4*d*(1 + Tanh[c + d*x]))}
{Sinh[c + d*x]^1*(a + b*Tanh[c + d*x]^3)^2, x, 4, ((a + b)^2*Cosh[c + d*x])/d + (2*b*(a + b)*Sech[c + d*x])/d - (b^2*Sech[c + d*x]^3)/(3*d)}
{Csch[c + d*x]^1*(a + b*Tanh[c + d*x]^3)^2, x, 5, -((a^2*ArcTanh[Cosh[c + d*x]])/d) - (b*(2*a + b)*Sech[c + d*x])/d + (b^2*Sech[c + d*x]^3)/(3*d)}
{Csch[c + d*x]^2*(a + b*Tanh[c + d*x]^3)^2, x, 3, -((a^2*Coth[c + d*x])/d) + (2*a*b*Tanh[c + d*x])/d + (b^2*Tanh[c + d*x]^3)/(3*d)}
{Csch[c + d*x]^3*(a + b*Tanh[c + d*x]^3)^2, x, 5, (a*(a - 4*b)*ArcTanh[Cosh[c + d*x]])/(2*d) + a^2/(4*d*(1 - Cosh[c + d*x])) - a^2/(4*d*(1 + Cosh[c + d*x])) + (2*a*b*Sech[c + d*x])/d - (b^2*Sech[c + d*x]^3)/(3*d)}
{Csch[c + d*x]^4*(a + b*Tanh[c + d*x]^3)^2, x, 3, (a*(a - 2*b)*Coth[c + d*x])/d - (a^2*Coth[c + d*x]^3)/(3*d) - ((2*a - b)*b*Tanh[c + d*x])/d - (b^2*Tanh[c + d*x]^3)/(3*d)}


{Sinh[c + d*x]^4*(a + b*Tanh[c + d*x]^3)^3, x, 6, (3*(a + b)*(a^2 + 14*a*b + 21*b^2)*x)/8 - (3*(a + b)*(a^2 + 14*a*b + 21*b^2)*Tanh[c + d*x])/(8*d) - (b*(6*a^2 + 35*a*b + 21*b^2)*Tanh[c + d*x]^3)/(8*d) - (3*b^2*(5*a + 21*b)*Tanh[c + d*x]^5)/(40*d) - (3*(a + 3*b)*Tanh[c + d*x]^3*(a + b*Tanh[c + d*x]^3)^2)/(8*d*(1 - Tanh[c + d*x]^2)) + (Tanh[c + d*x]^3*(a + b*Tanh[c + d*x]^3)^3)/(4*d*(1 - Tanh[c + d*x]^2)^2)}
{Sinh[c + d*x]^3*(a + b*Tanh[c + d*x]^3)^3, x, 4, -(((a + b)^2*(a + 4*b)*Cosh[c + d*x])/d) + ((a + b)^3*Cosh[c + d*x]^3)/(3*d) - (3*b*(a + b)*(a + 2*b)*Sech[c + d*x])/d + (b^2*(3*a + 4*b)*Sech[c + d*x]^3)/(3*d) - (b^3*Sech[c + d*x]^5)/(5*d)}
{Sinh[c + d*x]^2*(a + b*Tanh[c + d*x]^3)^3, x, 4, -((a + b)^2*(a + 7*b)*x)/2 + (a + b)^3/(4*d*(1 - Tanh[c + d*x])) + (3*b*(a + b)^2*Tanh[c + d*x])/d + (b^2*(3*a + 2*b)*Tanh[c + d*x]^3)/(3*d) + (b^3*Tanh[c + d*x]^5)/(5*d) - (a + b)^3/(4*d*(1 + Tanh[c + d*x]))}
{Sinh[c + d*x]^1*(a + b*Tanh[c + d*x]^3)^3, x, 4, ((a + b)^3*Cosh[c + d*x])/d + (3*b*(a + b)^2*Sech[c + d*x])/d - (b^2*(a + b)*Sech[c + d*x]^3)/d + (b^3*Sech[c + d*x]^5)/(5*d)}
{Csch[c + d*x]^1*(a + b*Tanh[c + d*x]^3)^3, x, 5, -((a^3*ArcTanh[Cosh[c + d*x]])/d) - (b*(3*a^2 + 3*a*b + b^2)*Sech[c + d*x])/d + (b^2*(3*a + 2*b)*Sech[c + d*x]^3)/(3*d) - (b^3*Sech[c + d*x]^5)/(5*d)}
{Csch[c + d*x]^2*(a + b*Tanh[c + d*x]^3)^3, x, 3, -((a^3*Coth[c + d*x])/d) + (3*a^2*b*Tanh[c + d*x])/d + (a*b^2*Tanh[c + d*x]^3)/d + (b^3*Tanh[c + d*x]^5)/(5*d)}
{Csch[c + d*x]^3*(a + b*Tanh[c + d*x]^3)^3, x, 5, (a^2*(a - 6*b)*ArcTanh[Cosh[c + d*x]])/(2*d) + a^3/(4*d*(1 - Cosh[c + d*x])) - a^3/(4*d*(1 + Cosh[c + d*x])) + (3*a^2*b*Sech[c + d*x])/d - (b^2*(3*a + b)*Sech[c + d*x]^3)/(3*d) + (b^3*Sech[c + d*x]^5)/(5*d)}
{Csch[c + d*x]^4*(a + b*Tanh[c + d*x]^3)^3, x, 3, (a^2*(a - 3*b)*Coth[c + d*x])/d - (a^3*Coth[c + d*x]^3)/(3*d) - (3*a*(a - b)*b*Tanh[c + d*x])/d - ((3*a - b)*b^2*Tanh[c + d*x]^3)/(3*d) - (b^3*Tanh[c + d*x]^5)/(5*d)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Sinh[c + d*x]^4/(a + b*Tanh[c + d*x]^3), x, 6, ((3*a^2 - 6*a*b - b^2)*x)/(8*(a + b)^3) + (a^(3/2)*Sqrt[b]*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/((a + b)^3*d) + Tanh[c + d*x]/(4*(a + b)*d*(1 - Tanh[c + d*x]^2)^2) - ((5*a + b)*Tanh[c + d*x])/(8*(a + b)^2*d*(1 - Tanh[c + d*x]^2))}
{Sinh[c + d*x]^3/(a + b*Tanh[c + d*x]^3), x, 5, (a*Sqrt[b]*ArcTanh[(Sqrt[a + b]*Cosh[c + d*x])/Sqrt[b]])/((a + b)^(5/2)*d) - (a*Cosh[c + d*x])/((a + b)^2*d) + Cosh[c + d*x]^3/(3*(a + b)*d)}
{Sinh[c + d*x]^2/(a + b*Tanh[c + d*x]^3), x, 5, -((a - b)*x)/(2*(a + b)^2) - (Sqrt[a]*Sqrt[b]*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/((a + b)^2*d) + 1/(4*(a + b)*d*(1 - Tanh[c + d*x])) - 1/(4*(a + b)*d*(1 + Tanh[c + d*x]))}
{Sinh[c + d*x]^1/(a + b*Tanh[c + d*x]^3), x, 4, -((Sqrt[b]*ArcTanh[(Sqrt[a + b]*Cosh[c + d*x])/Sqrt[b]])/((a + b)^(3/2)*d)) + Cosh[c + d*x]/((a + b)*d)}
{Csch[c + d*x]^1/(a + b*Tanh[c + d*x]^3), x, 5, -(ArcTanh[Cosh[c + d*x]]/(a*d)) + (Sqrt[b]*ArcTanh[(Sqrt[a + b]*Cosh[c + d*x])/Sqrt[b]])/(a*Sqrt[a + b]*d)}
{Csch[c + d*x]^2/(a + b*Tanh[c + d*x]^3), x, 3, -((Sqrt[b]*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(a^(3/2)*d)) - Coth[c + d*x]/(a*d)}
{Csch[c + d*x]^3/(a + b*Tanh[c + d*x]^3), x, 6, (Sqrt[-a - b]*Sqrt[b]*ArcTan[(Sqrt[-a - b]*Cosh[c + d*x])/Sqrt[b]])/(a^2*d) + ((a + 2*b)*ArcTanh[Cosh[c + d*x]])/(2*a^2*d) + 1/(4*a*d*(1 - Cosh[c + d*x])) - 1/(4*a*d*(1 + Cosh[c + d*x]))}
{Csch[c + d*x]^4/(a + b*Tanh[c + d*x]^3), x, 4, (Sqrt[b]*(a + b)*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(a^(5/2)*d) + ((a + b)*Coth[c + d*x])/(a^2*d) - Coth[c + d*x]^3/(3*a*d)}


{Sinh[c + d*x]^4/(a + b*Tanh[c + d*x]^3)^2, x, 7, (3*(a^2 - 6*a*b + b^2)*x)/(8*(a + b)^4) + (3*Sqrt[a]*(a - b)*Sqrt[b]*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(2*(a + b)^4*d) + (3*(3*a - b)*b*Tanh[c + d*x])/(8*(a + b)^3*d*(a + b*Tanh[c + d*x]^3)) + Tanh[c + d*x]/(4*(a + b)*d*(1 - Tanh[c + d*x]^2)^2*(a + b*Tanh[c + d*x]^3)) - ((5*a - b)*Tanh[c + d*x])/(8*(a + b)^2*d*(1 - Tanh[c + d*x]^2)*(a + b*Tanh[c + d*x]^3))}
{Sinh[c + d*x]^3/(a + b*Tanh[c + d*x]^3)^2, x, 6, ((3*a - 2*b)*Sqrt[b]*ArcTanh[(Sqrt[a + b]*Cosh[c + d*x])/Sqrt[b]])/(2*(a + b)^(7/2)*d) - ((3*a - 2*b)*Cosh[c + d*x])/(2*(a + b)^3*d) - ((3*a - 2*b)*Cosh[c + d*x]^3)/(6*b*(a + b)^2*d) - (a*Cosh[c + d*x]^5)/(2*b*(a + b)*d*(b - (a + b)*Cosh[c + d*x]^2))}
{Sinh[c + d*x]^2/(a + b*Tanh[c + d*x]^3)^2, x, 7, -((a - 3*b)*x)/(2*(a + b)^3) - ((a - b)*Sqrt[b]*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(Sqrt[a]*(a + b)^3*d) - (Sqrt[b]*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(2*Sqrt[a]*(a + b)^2*d) + 1/(4*(a + b)^2*d*(1 - Tanh[c + d*x])) - 1/(4*(a + b)^2*d*(1 + Tanh[c + d*x])) - (b*Tanh[c + d*x])/(2*(a + b)^2*d*(a + b*Tanh[c + d*x]^3))}
{Sinh[c + d*x]^1/(a + b*Tanh[c + d*x]^3)^2, x, 5, (-3*Sqrt[b]*ArcTanh[(Sqrt[a + b]*Cosh[c + d*x])/Sqrt[b]])/(2*(a + b)^(5/2)*d) + (3*Cosh[c + d*x])/(2*(a + b)^2*d) + Cosh[c + d*x]^3/(2*(a + b)*d*(b - (a + b)*Cosh[c + d*x]^2))}
{Csch[c + d*x]^1/(a + b*Tanh[c + d*x]^3)^2, x, 8, (Sqrt[b]*ArcTan[(Sqrt[-a - b]*Cosh[c + d*x])/Sqrt[b]])/(2*a*(-a - b)^(3/2)*d) - (Sqrt[b]*(2*a + b)*ArcTan[(Sqrt[-a - b]*Cosh[c + d*x])/Sqrt[b]])/(a^2*(-a - b)^(3/2)*d) - ArcTanh[Cosh[c + d*x]]/(a^2*d) - (b*Cosh[c + d*x])/(2*a*(a + b)*d*(b - (a + b)*Cosh[c + d*x]^2))}
{Csch[c + d*x]^2/(a + b*Tanh[c + d*x]^3)^2, x, 4, (-3*Sqrt[b]*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(2*a^(5/2)*d) - (3*Coth[c + d*x])/(2*a^2*d) + Coth[c + d*x]/(2*a*d*(a + b*Tanh[c + d*x]^3))}
{Csch[c + d*x]^3/(a + b*Tanh[c + d*x]^3)^2, x, 8, (Sqrt[b]*ArcTan[(Sqrt[-a - b]*Cosh[c + d*x])/Sqrt[b]])/(2*a^2*Sqrt[-a - b]*d) + (2*Sqrt[-a - b]*Sqrt[b]*ArcTan[(Sqrt[-a - b]*Cosh[c + d*x])/Sqrt[b]])/(a^3*d) + ((a + 4*b)*ArcTanh[Cosh[c + d*x]])/(2*a^3*d) + 1/(4*a^2*d*(1 - Cosh[c + d*x])) - 1/(4*a^2*d*(1 + Cosh[c + d*x])) + (b*Cosh[c + d*x])/(2*a^2*d*(b - (a + b)*Cosh[c + d*x]^2))}
{Csch[c + d*x]^4/(a + b*Tanh[c + d*x]^3)^2, x, 5, (Sqrt[b]*(3*a + 5*b)*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(2*a^(7/2)*d) + ((3*a + 5*b)*Coth[c + d*x])/(2*a^3*d) - ((3*a + 5*b)*Coth[c + d*x]^3)/(6*a^2*b*d) + ((a + b)*Coth[c + d*x]^3)/(2*a*b*d*(a + b*Tanh[c + d*x]^3))}


{Sinh[c + d*x]^4/(a + b*Tanh[c + d*x]^3)^3, x, 8, (3*(a^2 - 10*a*b + 5*b^2)*x)/(8*(a + b)^5) + (3*Sqrt[b]*(5*a^2 - 10*a*b + b^2)*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(8*Sqrt[a]*(a + b)^5*d) + ((7*a - 5*b)*b*Tanh[c + d*x])/(8*(a + b)^3*d*(a + b*Tanh[c + d*x]^3)^2) + Tanh[c + d*x]/(4*(a + b)*d*(1 - Tanh[c + d*x]^2)^2*(a + b*Tanh[c + d*x]^3)^2) - ((5*a - 3*b)*Tanh[c + d*x])/(8*(a + b)^2*d*(1 - Tanh[c + d*x]^2)*(a + b*Tanh[c + d*x]^3)^2) + (3*(a - b)*b*Tanh[c + d*x])/(2*(a + b)^4*d*(a + b*Tanh[c + d*x]^3))}
{Sinh[c + d*x]^3/(a + b*Tanh[c + d*x]^3)^3, x, 7, (5*(3*a - 4*b)*Sqrt[b]*ArcTanh[(Sqrt[a + b]*Cosh[c + d*x])/Sqrt[b]])/(8*(a + b)^(9/2)*d) - (5*(3*a - 4*b)*Cosh[c + d*x])/(8*(a + b)^4*d) - (5*(3*a - 4*b)*Cosh[c + d*x]^3)/(24*b*(a + b)^3*d) + (a*Cosh[c + d*x]^7)/(4*b*(a + b)*d*(b - (a + b)*Cosh[c + d*x]^2)^2) - ((3*a - 4*b)*Cosh[c + d*x]^5)/(8*b*(a + b)^2*d*(b - (a + b)*Cosh[c + d*x]^2))}
{Sinh[c + d*x]^2/(a + b*Tanh[c + d*x]^3)^3, x, 7, -((a - 5*b)*x)/(2*(a + b)^4) - (Sqrt[b]*(15*a^2 - 10*a*b - b^2)*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(8*a^(3/2)*(a + b)^4*d) - (3*b*Tanh[c + d*x])/(4*(a + b)^2*d*(a + b*Tanh[c + d*x]^3)^2) + Tanh[c + d*x]/(2*(a + b)*d*(1 - Tanh[c + d*x]^2)*(a + b*Tanh[c + d*x]^3)^2) - ((11*a - b)*b*Tanh[c + d*x])/(8*a*(a + b)^3*d*(a + b*Tanh[c + d*x]^3))}
{Sinh[c + d*x]^1/(a + b*Tanh[c + d*x]^3)^3, x, 6, (-15*Sqrt[b]*ArcTanh[(Sqrt[a + b]*Cosh[c + d*x])/Sqrt[b]])/(8*(a + b)^(7/2)*d) + (15*Cosh[c + d*x])/(8*(a + b)^3*d) - Cosh[c + d*x]^5/(4*(a + b)*d*(b - (a + b)*Cosh[c + d*x]^2)^2) + (5*Cosh[c + d*x]^3)/(8*(a + b)^2*d*(b - (a + b)*Cosh[c + d*x]^2))}
{Csch[c + d*x]^1/(a + b*Tanh[c + d*x]^3)^3, x, 7, -(ArcTanh[Cosh[c + d*x]]/(a^3*d)) + (Sqrt[b]*(15*a^2 + 20*a*b + 8*b^2)*ArcTanh[(Sqrt[a + b]*Cosh[c + d*x])/Sqrt[b]])/(8*a^3*(a + b)^(5/2)*d) + (b*Cosh[c + d*x]^3)/(4*a*(a + b)*d*(b - (a + b)*Cosh[c + d*x]^2)^2) - (b*(7*a + 4*b)*Cosh[c + d*x])/(8*a^2*(a + b)^2*d*(b - (a + b)*Cosh[c + d*x]^2))}
{Csch[c + d*x]^2/(a + b*Tanh[c + d*x]^3)^3, x, 5, (-15*Sqrt[b]*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(8*a^(7/2)*d) - (15*Coth[c + d*x])/(8*a^3*d) + Coth[c + d*x]/(4*a*d*(a + b*Tanh[c + d*x]^3)^2) + (5*Coth[c + d*x])/(8*a^2*d*(a + b*Tanh[c + d*x]^3))}
{Csch[c + d*x]^3/(a + b*Tanh[c + d*x]^3)^3, x, 8, ((a + 6*b)*ArcTanh[Cosh[c + d*x]])/(2*a^4*d) - (Sqrt[b]*(15*a^2 + 40*a*b + 24*b^2)*ArcTanh[(Sqrt[a + b]*Cosh[c + d*x])/Sqrt[b]])/(8*a^4*(a + b)^(3/2)*d) - (b*(2*a + 3*b)*Cosh[c + d*x])/(4*a^2*(a + b)*d*(b - (a + b)*Cosh[c + d*x]^2)^2) + Cosh[c + d*x]^3/(2*a*d*(1 - Cosh[c + d*x]^2)*(b - (a + b)*Cosh[c + d*x]^2)^2) + ((4*a^2 + 17*a*b + 12*b^2)*Cosh[c + d*x])/(8*a^3*(a + b)*d*(b - (a + b)*Cosh[c + d*x]^2))}
{Csch[c + d*x]^4/(a + b*Tanh[c + d*x]^3)^3, x, 6, (5*Sqrt[b]*(3*a + 7*b)*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(8*a^(9/2)*d) + (5*(3*a + 7*b)*Coth[c + d*x])/(8*a^4*d) - (5*(3*a + 7*b)*Coth[c + d*x]^3)/(24*a^3*b*d) + ((a + b)*Coth[c + d*x]^3)/(4*a*b*d*(a + b*Tanh[c + d*x]^3)^2) + ((3*a + 7*b)*Coth[c + d*x]^3)/(8*a^2*b*d*(a + b*Tanh[c + d*x]^3))}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cosh[c+d x]^m (a+b Tanh[c+d x]^3)^n*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Cosh[c + d*x]^4*(a + b*Tanh[c + d*x]^3), x, 4, ((3*a - b)*x)/8 + ((a + b)*Tanh[c + d*x])/(4*d*(1 - Tanh[c + d*x]^2)^2) + ((3*a - b)*Tanh[c + d*x])/(8*d*(1 - Tanh[c + d*x]^2))}
{Cosh[c + d*x]^3*(a + b*Tanh[c + d*x]^3), x, 3, (a*Sinh[c + d*x])/d + (a*Sinh[c + d*x]^3)/(3*d) + (b*Sinh[c + d*x]^3)/(3*d)}
{Cosh[c + d*x]^2*(a + b*Tanh[c + d*x]^3), x, 3, ((a - b)*x)/2 + ((a + b)*Tanh[c + d*x])/(2*d*(1 - Tanh[c + d*x]^2))}
{Cosh[c + d*x]^1*(a + b*Tanh[c + d*x]^3), x, 4, -((b*ArcTan[Sinh[c + d*x]])/d) + ((a + b)*Sinh[c + d*x])/d}
{Sech[c + d*x]^1*(a + b*Tanh[c + d*x]^3), x, 4, ((2*a + b)*ArcTan[Sinh[c + d*x]])/(2*d) - (b*Sinh[c + d*x])/(2*d*(1 + Sinh[c + d*x]^2))}
{Sech[c + d*x]^2*(a + b*Tanh[c + d*x]^3), x, 2, (a*Tanh[c + d*x])/d + (b*Tanh[c + d*x]^3)/(3*d)}
{Sech[c + d*x]^3*(a + b*Tanh[c + d*x]^3), x, 5, ((4*a + b)*ArcTan[Sinh[c + d*x]])/(8*d) - (b*Sinh[c + d*x])/(4*d*(1 + Sinh[c + d*x]^2)^2) + ((4*a + b)*Sinh[c + d*x])/(8*d*(1 + Sinh[c + d*x]^2))}
{Sech[c + d*x]^4*(a + b*Tanh[c + d*x]^3), x, 3, (a*Tanh[c + d*x])/d - ((a - b)*Tanh[c + d*x]^3)/(3*d) - (b*Tanh[c + d*x]^5)/(5*d)}


{Cosh[c + d*x]^4*(a + b*Tanh[c + d*x]^3)^2, x, 4, ((3*a^2 - 2*a*b + 3*b^2)*x)/8 + (3*(a^2 - b^2)*Tanh[c + d*x])/(8*d*(1 - Tanh[c + d*x]^2)) + ((a + b)*Tanh[c + d*x]*(a + b*Tanh[c + d*x]^3))/(4*d*(1 - Tanh[c + d*x]^2)^2)}
{Cosh[c + d*x]^3*(a + b*Tanh[c + d*x]^3)^2, x, 5, (b^2*ArcTan[Sinh[c + d*x]])/d + ((a^2 - b^2)*Sinh[c + d*x])/d + ((a + b)^2*Sinh[c + d*x]^3)/(3*d)}
{Cosh[c + d*x]^2*(a + b*Tanh[c + d*x]^3)^2, x, 4, ((a - 3*b)*(a + b)*x)/2 + (b*(a + 3*b)*Tanh[c + d*x])/(2*d) + ((a + b)*Tanh[c + d*x]*(a + b*Tanh[c + d*x]^3))/(2*d*(1 - Tanh[c + d*x]^2))}
{Cosh[c + d*x]^1*(a + b*Tanh[c + d*x]^3)^2, x, 5, -(b*(4*a + 3*b)*ArcTan[Sinh[c + d*x]])/(2*d) + ((a + b)*(2*a + 3*b)*Sinh[c + d*x])/(2*d) - (b*Sinh[c + d*x]*(a + (a + b)*Sinh[c + d*x]^2))/(2*d*(1 + Sinh[c + d*x]^2))}
{Sech[c + d*x]^1*(a + b*Tanh[c + d*x]^3)^2, x, 5, ((8*a^2 + 8*a*b + 3*b^2)*ArcTan[Sinh[c + d*x]])/(8*d) - (3*b*(2*a + b)*Sinh[c + d*x])/(8*d*(1 + Sinh[c + d*x]^2)) - (b*Sinh[c + d*x]*(a + (a + b)*Sinh[c + d*x]^2))/(4*d*(1 + Sinh[c + d*x]^2)^2)}
{Sech[c + d*x]^2*(a + b*Tanh[c + d*x]^3)^2, x, 3, (a^2*Tanh[c + d*x])/d + (2*a*b*Tanh[c + d*x]^3)/(3*d) + (b^2*Tanh[c + d*x]^5)/(5*d)}
{Sech[c + d*x]^3*(a + b*Tanh[c + d*x]^3)^2, x, 6, ((8*a^2 + 4*a*b + b^2)*ArcTan[Sinh[c + d*x]])/(16*d) - (b*(8*a + 3*b)*Sinh[c + d*x])/(24*d*(1 + Sinh[c + d*x]^2)^2) + ((8*a^2 + 4*a*b + b^2)*Sinh[c + d*x])/(16*d*(1 + Sinh[c + d*x]^2)) - (b*Sinh[c + d*x]*(a + (a + b)*Sinh[c + d*x]^2))/(6*d*(1 + Sinh[c + d*x]^2)^3)}
{Sech[c + d*x]^4*(a + b*Tanh[c + d*x]^3)^2, x, 3, (a^2*Tanh[c + d*x])/d - (a*(a - 2*b)*Tanh[c + d*x]^3)/(3*d) - ((2*a - b)*b*Tanh[c + d*x]^5)/(5*d) - (b^2*Tanh[c + d*x]^7)/(7*d)}


{Cosh[c + d*x]^4*(a + b*Tanh[c + d*x]^3)^3, x, 5, (3*(a + b)*(a^2 - 2*a*b + 5*b^2)*x)/8 - (b*(a + 3*b)*(a + 5*b)*Tanh[c + d*x])/(8*d) + ((a + b)*Tanh[c + d*x]*(a + b*Tanh[c + d*x]^3)^2)/(4*d*(1 - Tanh[c + d*x]^2)^2) + ((a + b)*Tanh[c + d*x]*(a*(3*a - b) - b*(a + 5*b)*Tanh[c + d*x]^2))/(8*d*(1 - Tanh[c + d*x]^2))}
{Cosh[c + d*x]^3*(a + b*Tanh[c + d*x]^3)^3, x, 7, -(b^3*ArcTan[Sinh[c + d*x]])/(2*d) + (3*b^2*(a + b)*ArcTan[Sinh[c + d*x]])/d + ((a - 2*b)*(a + b)^2*Sinh[c + d*x])/d + ((a + b)^3*Sinh[c + d*x]^3)/(3*d) - (b^3*Sinh[c + d*x])/(2*d*(1 + Sinh[c + d*x]^2))}
{Cosh[c + d*x]^2*(a + b*Tanh[c + d*x]^3)^3, x, 4, ((a - 5*b)*(a + b)^2*x)/2 + (a + b)^3/(4*d*(1 - Tanh[c + d*x])) + (b^2*(3*a + 2*b)*Tanh[c + d*x])/d + (b^3*Tanh[c + d*x]^3)/(3*d) - (a + b)^3/(4*d*(1 + Tanh[c + d*x]))}
{Cosh[c + d*x]^1*(a + b*Tanh[c + d*x]^3)^3, x, 6, (-3*b*(8*a^2 + 12*a*b + 5*b^2)*ArcTan[Sinh[c + d*x]])/(8*d) + ((a + b)*(2*a + 3*b)*(4*a + 5*b)*Sinh[c + d*x])/(8*d) - (b*Sinh[c + d*x]*(a + (a + b)*Sinh[c + d*x]^2)^2)/(4*d*(1 + Sinh[c + d*x]^2)^2) - (b*Sinh[c + d*x]*(a*(4*a + b) + (a + b)*(4*a + 5*b)*Sinh[c + d*x]^2))/(8*d*(1 + Sinh[c + d*x]^2))}
{Sech[c + d*x]^1*(a + b*Tanh[c + d*x]^3)^3, x, 6, ((2*a + b)*(8*a^2 + 8*a*b + 5*b^2)*ArcTan[Sinh[c + d*x]])/(16*d) - (b*(52*a^2 + 52*a*b + 15*b^2)*Sinh[c + d*x])/(48*d*(1 + Sinh[c + d*x]^2)) - (b*Sinh[c + d*x]*(a + (a + b)*Sinh[c + d*x]^2)^2)/(6*d*(1 + Sinh[c + d*x]^2)^3) - (b*Sinh[c + d*x]*(a*(6*a + b) + (a + b)*(6*a + 5*b)*Sinh[c + d*x]^2))/(24*d*(1 + Sinh[c + d*x]^2)^2)}
{Sech[c + d*x]^2*(a + b*Tanh[c + d*x]^3)^3, x, 3, (a^3*Tanh[c + d*x])/d + (a^2*b*Tanh[c + d*x]^3)/d + (3*a*b^2*Tanh[c + d*x]^5)/(5*d) + (b^3*Tanh[c + d*x]^7)/(7*d)}
{Sech[c + d*x]^3*(a + b*Tanh[c + d*x]^3)^3, x, 7, ((64*a^3 + 48*a^2*b + 24*a*b^2 + 5*b^3)*ArcTan[Sinh[c + d*x]])/(128*d) - (b*(88*a^2 + 68*a*b + 15*b^2)*Sinh[c + d*x])/(192*d*(1 + Sinh[c + d*x]^2)^2) + ((64*a^3 + 48*a^2*b + 24*a*b^2 + 5*b^3)*Sinh[c + d*x])/(128*d*(1 + Sinh[c + d*x]^2)) - (b*Sinh[c + d*x]*(a + (a + b)*Sinh[c + d*x]^2)^2)/(8*d*(1 + Sinh[c + d*x]^2)^4) - (b*Sinh[c + d*x]*(a*(8*a + b) + (a + b)*(8*a + 5*b)*Sinh[c + d*x]^2))/(48*d*(1 + Sinh[c + d*x]^2)^3)}
{Sech[c + d*x]^4*(a + b*Tanh[c + d*x]^3)^3, x, 3, (a^3*Tanh[c + d*x])/d - (a^2*(a - 3*b)*Tanh[c + d*x]^3)/(3*d) - (3*a*(a - b)*b*Tanh[c + d*x]^5)/(5*d) - ((3*a - b)*b^2*Tanh[c + d*x]^7)/(7*d) - (b^3*Tanh[c + d*x]^9)/(9*d)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Cosh[c + d*x]^4/(a + b*Tanh[c + d*x]^3), x, 6, ((3*a^2 + 10*a*b + 15*b^2)*x)/(8*(a + b)^3) + (b^(5/2)*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(Sqrt[a]*(a + b)^3*d) + Tanh[c + d*x]/(4*(a + b)*d*(1 - Tanh[c + d*x]^2)^2) + ((3*a + 7*b)*Tanh[c + d*x])/(8*(a + b)^2*d*(1 - Tanh[c + d*x]^2))}
{Cosh[c + d*x]^3/(a + b*Tanh[c + d*x]^3), x, 5, (b^2*ArcTan[(Sqrt[a + b]*Sinh[c + d*x])/Sqrt[a]])/(Sqrt[a]*(a + b)^(5/2)*d) + ((a + 2*b)*Sinh[c + d*x])/((a + b)^2*d) + Sinh[c + d*x]^3/(3*(a + b)*d)}
{Cosh[c + d*x]^2/(a + b*Tanh[c + d*x]^3), x, 5, ((a + 3*b)*x)/(2*(a + b)^2) + (b^(3/2)*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(Sqrt[a]*(a + b)^2*d) + Tanh[c + d*x]/(2*(a + b)*d*(1 - Tanh[c + d*x]^2))}
{Cosh[c + d*x]^1/(a + b*Tanh[c + d*x]^3), x, 4, (b*ArcTan[(Sqrt[a + b]*Sinh[c + d*x])/Sqrt[a]])/(Sqrt[a]*(a + b)^(3/2)*d) + Sinh[c + d*x]/((a + b)*d)}
{Sech[c + d*x]^1/(a + b*Tanh[c + d*x]^3), x, 3, ArcTan[(Sqrt[a + b]*Sinh[c + d*x])/Sqrt[a]]/(Sqrt[a]*Sqrt[a + b]*d)}
{Sech[c + d*x]^2/(a + b*Tanh[c + d*x]^3), x, 2, ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]]/(Sqrt[a]*Sqrt[b]*d)}
{Sech[c + d*x]^3/(a + b*Tanh[c + d*x]^3), x, 5, -(ArcTan[Sinh[c + d*x]]/(b*d)) + (Sqrt[a + b]*ArcTan[(Sqrt[a + b]*Sinh[c + d*x])/Sqrt[a]])/(Sqrt[a]*b*d)}
{Sech[c + d*x]^4/(a + b*Tanh[c + d*x]^3), x, 3, ((a + b)*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(Sqrt[a]*b^(3/2)*d) - Tanh[c + d*x]/(b*d)}
{Sech[c + d*x]^5/(a + b*Tanh[c + d*x]^3), x, 6, -(((2*a + 3*b)*ArcTan[Sinh[c + d*x]])/(2*b^2*d)) + ((a + b)^(3/2)*ArcTan[(Sqrt[a + b]*Sinh[c + d*x])/Sqrt[a]])/(Sqrt[a]*b^2*d) - Sinh[c + d*x]/(2*b*d*(1 + Sinh[c + d*x]^2))}
{Sech[c + d*x]^6/(a + b*Tanh[c + d*x]^3), x, 4, ((a + b)^2*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(Sqrt[a]*b^(5/2)*d) - ((a + 2*b)*Tanh[c + d*x])/(b^2*d) + Tanh[c + d*x]^3/(3*b*d)}


{Cosh[c + d*x]^3/(a + b*Tanh[c + d*x]^3)^2, x, 7, (3*b^2*ArcTan[(Sqrt[a + b]*Sinh[c + d*x])/Sqrt[a]])/(Sqrt[a]*(a + b)^(7/2)*d) + (b^3*ArcTan[(Sqrt[a + b]*Sinh[c + d*x])/Sqrt[a]])/(2*a^(3/2)*(a + b)^(7/2)*d) + ((a + 3*b)*Sinh[c + d*x])/((a + b)^3*d) + Sinh[c + d*x]^3/(3*(a + b)^2*d) + (b^3*Sinh[c + d*x])/(2*a*(a + b)^3*d*(a + (a + b)*Sinh[c + d*x]^2))}
{Cosh[c + d*x]^2/(a + b*Tanh[c + d*x]^3)^2, x, 6, ((a + 5*b)*x)/(2*(a + b)^3) + (b^(3/2)*(5*a + b)*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(2*a^(3/2)*(a + b)^3*d) - ((a - b)*b*Tanh[c + d*x])/(2*a*(a + b)^2*d*(a + b*Tanh[c + d*x]^3)) + Tanh[c + d*x]/(2*(a + b)*d*(1 - Tanh[c + d*x]^2)*(a + b*Tanh[c + d*x]^3))}
{Cosh[c + d*x]^1/(a + b*Tanh[c + d*x]^3)^2, x, 5, (b*(4*a + b)*ArcTan[(Sqrt[a + b]*Sinh[c + d*x])/Sqrt[a]])/(2*a^(3/2)*(a + b)^(5/2)*d) + ((2*a - b)*Sinh[c + d*x])/(2*a*(a + b)^2*d) + (b*Sinh[c + d*x]*(1 + Sinh[c + d*x]^2))/(2*a*(a + b)*d*(a + (a + b)*Sinh[c + d*x]^2))}
{Sech[c + d*x]^1/(a + b*Tanh[c + d*x]^3)^2, x, 4, ((2*a + b)*ArcTan[(Sqrt[a + b]*Sinh[c + d*x])/Sqrt[a]])/(2*a^(3/2)*(a + b)^(3/2)*d) + (b*Sinh[c + d*x])/(2*a*(a + b)*d*(a + (a + b)*Sinh[c + d*x]^2))}
{Sech[c + d*x]^2/(a + b*Tanh[c + d*x]^3)^2, x, 3, ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]]/(2*a^(3/2)*Sqrt[b]*d) + Tanh[c + d*x]/(2*a*d*(a + b*Tanh[c + d*x]^3))}
{Sech[c + d*x]^3/(a + b*Tanh[c + d*x]^3)^2, x, 4, ArcTan[(Sqrt[a + b]*Sinh[c + d*x])/Sqrt[a]]/(2*a^(3/2)*Sqrt[a + b]*d) + Sinh[c + d*x]/(2*a*d*(a + (a + b)*Sinh[c + d*x]^2))}
{Sech[c + d*x]^4/(a + b*Tanh[c + d*x]^3)^2, x, 3, -((a - b)*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(2*a^(3/2)*b^(3/2)*d) + ((a + b)*Tanh[c + d*x])/(2*a*b*d*(a + b*Tanh[c + d*x]^3))}
{Sech[c + d*x]^5/(a + b*Tanh[c + d*x]^3)^2, x, 6, ArcTan[Sinh[c + d*x]]/(b^2*d) - ((2*a - b)*Sqrt[a + b]*ArcTan[(Sqrt[a + b]*Sinh[c + d*x])/Sqrt[a]])/(2*a^(3/2)*b^2*d) + ((a + b)*Sinh[c + d*x])/(2*a*b*d*(a + (a + b)*Sinh[c + d*x]^2))}
{Sech[c + d*x]^6/(a + b*Tanh[c + d*x]^3)^2, x, 4, -(((3*a - b)*(a + b)*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(2*a^(3/2)*b^(5/2)*d)) + ((3*a + b)*Tanh[c + d*x])/(2*a*b^2*d) + ((a + b)*Tanh[c + d*x]*(1 - Tanh[c + d*x]^2))/(2*a*b*d*(a + b*Tanh[c + d*x]^3))}
{Sech[c + d*x]^7/(a + b*Tanh[c + d*x]^3)^2, x, 7, ((4*a + 5*b)*ArcTan[Sinh[c + d*x]])/(2*b^3*d) - ((4*a - b)*(a + b)^(3/2)*ArcTan[(Sqrt[a + b]*Sinh[c + d*x])/Sqrt[a]])/(2*a^(3/2)*b^3*d) + ((a + b)*(2*a + b)*Sinh[c + d*x])/(2*a*b^2*d*(a + (a + b)*Sinh[c + d*x]^2)) - Sinh[c + d*x]/(2*b*d*(1 + Sinh[c + d*x]^2)*(a + (a + b)*Sinh[c + d*x]^2))}


{Cosh[c + d*x]^2/(a + b*Tanh[c + d*x]^3)^3, x, 7, ((a + 7*b)*x)/(2*(a + b)^4) + (b^(3/2)*(35*a^2 + 14*a*b + 3*b^2)*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(8*a^(5/2)*(a + b)^4*d) - ((2*a - b)*b*Tanh[c + d*x])/(4*a*(a + b)^2*d*(a + b*Tanh[c + d*x]^3)^2) + Tanh[c + d*x]/(2*(a + b)*d*(1 - Tanh[c + d*x]^2)*(a + b*Tanh[c + d*x]^3)^2) - ((a - 3*b)*b*(4*a + b)*Tanh[c + d*x])/(8*a^2*(a + b)^3*d*(a + b*Tanh[c + d*x]^3))}
{Cosh[c + d*x]^1/(a + b*Tanh[c + d*x]^3)^3, x, 6, (3*b*(8*a^2 + 4*a*b + b^2)*ArcTan[(Sqrt[a + b]*Sinh[c + d*x])/Sqrt[a]])/(8*a^(5/2)*(a + b)^(7/2)*d) + ((2*a - b)*(4*a - b)*Sinh[c + d*x])/(8*a^2*(a + b)^3*d) + (b*Sinh[c + d*x]*(1 + Sinh[c + d*x]^2)^2)/(4*a*(a + b)*d*(a + (a + b)*Sinh[c + d*x]^2)^2) + (b*Sinh[c + d*x]*(4*a + 3*b + (4*a - b)*Sinh[c + d*x]^2))/(8*a^2*(a + b)^2*d*(a + (a + b)*Sinh[c + d*x]^2))}
{Sech[c + d*x]^1/(a + b*Tanh[c + d*x]^3)^3, x, 5, ((8*a^2 + 8*a*b + 3*b^2)*ArcTan[(Sqrt[a + b]*Sinh[c + d*x])/Sqrt[a]])/(8*a^(5/2)*(a + b)^(5/2)*d) + (b*Sinh[c + d*x]*(1 + Sinh[c + d*x]^2))/(4*a*(a + b)*d*(a + (a + b)*Sinh[c + d*x]^2)^2) + (3*b*(2*a + b)*Sinh[c + d*x])/(8*a^2*(a + b)^2*d*(a + (a + b)*Sinh[c + d*x]^2))}
{Sech[c + d*x]^2/(a + b*Tanh[c + d*x]^3)^3, x, 4, (3*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(8*a^(5/2)*Sqrt[b]*d) + Tanh[c + d*x]/(4*a*d*(a + b*Tanh[c + d*x]^3)^2) + (3*Tanh[c + d*x])/(8*a^2*d*(a + b*Tanh[c + d*x]^3))}
{Sech[c + d*x]^3/(a + b*Tanh[c + d*x]^3)^3, x, 5, ((4*a + 3*b)*ArcTan[(Sqrt[a + b]*Sinh[c + d*x])/Sqrt[a]])/(8*a^(5/2)*(a + b)^(3/2)*d) + (b*Sinh[c + d*x])/(4*a*(a + b)*d*(a + (a + b)*Sinh[c + d*x]^2)^2) + ((4*a + 3*b)*Sinh[c + d*x])/(8*a^2*(a + b)*d*(a + (a + b)*Sinh[c + d*x]^2))}
{Sech[c + d*x]^4/(a + b*Tanh[c + d*x]^3)^3, x, 4, -((a - 3*b)*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(8*a^(5/2)*b^(3/2)*d) + ((a + b)*Tanh[c + d*x])/(4*a*b*d*(a + b*Tanh[c + d*x]^3)^2) - ((a - 3*b)*Tanh[c + d*x])/(8*a^2*b*d*(a + b*Tanh[c + d*x]^3))}
{Sech[c + d*x]^5/(a + b*Tanh[c + d*x]^3)^3, x, 5, (3*ArcTan[(Sqrt[a + b]*Sinh[c + d*x])/Sqrt[a]])/(8*a^(5/2)*Sqrt[a + b]*d) + Sinh[c + d*x]/(4*a*d*(a + (a + b)*Sinh[c + d*x]^2)^2) + (3*Sinh[c + d*x])/(8*a^2*d*(a + (a + b)*Sinh[c + d*x]^2))}
{Sech[c + d*x]^6/(a + b*Tanh[c + d*x]^3)^3, x, 4, ((3*a^2 - 2*a*b + 3*b^2)*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(8*a^(5/2)*b^(5/2)*d) + ((a + b)*Tanh[c + d*x]*(1 - Tanh[c + d*x]^2))/(4*a*b*d*(a + b*Tanh[c + d*x]^3)^2) + (3*(1/a^2 - 1/b^2)*Tanh[c + d*x])/(8*d*(a + b*Tanh[c + d*x]^3))}
{Sech[c + d*x]^7/(a + b*Tanh[c + d*x]^3)^3, x, 7, -(ArcTan[Sinh[c + d*x]]/(b^3*d)) + (Sqrt[a + b]*(8*a^2 - 4*a*b + 3*b^2)*ArcTan[(Sqrt[a + b]*Sinh[c + d*x])/Sqrt[a]])/(8*a^(5/2)*b^3*d) + ((a + b)*Sinh[c + d*x])/(4*a*b*d*(a + (a + b)*Sinh[c + d*x]^2)^2) - ((4*a - 3*b)*(a + b)*Sinh[c + d*x])/(8*a^2*b^2*d*(a + (a + b)*Sinh[c + d*x]^2))}


(* ::Subsection::Closed:: *)
(*Integrands of the form Tanh[c+d x]^m (a+b Tanh[c+d x]^3)^n*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Tanh[c + d*x]^4*(a + b*Tanh[c + d*x]^3), x, 4, (a + b)*x - ((a + b)*Tanh[c + d*x])/d - ((a + b)*Tanh[c + d*x]^3)/(3*d) - (b*Tanh[c + d*x]^5)/(5*d)}
{Tanh[c + d*x]^3*(a + b*Tanh[c + d*x]^3), x, 3, ((a + b)*Log[Cosh[c + d*x]])/d - ((a + b)*Tanh[c + d*x]^2)/(2*d) - (b*Tanh[c + d*x]^4)/(4*d)}
{Tanh[c + d*x]^2*(a + b*Tanh[c + d*x]^3), x, 3, (a + b)*x - ((a + b)*Tanh[c + d*x])/d - (b*Tanh[c + d*x]^3)/(3*d)}
{Tanh[c + d*x]^1*(a + b*Tanh[c + d*x]^3), x, 2, ((a + b)*Log[Cosh[c + d*x]])/d - (b*Tanh[c + d*x]^2)/(2*d)}
{Tanh[c + d*x]^0*(a + b*Tanh[c + d*x]^3), x, 3, a*x + b*x - (b*Tanh[c + d*x])/d}
{Coth[c + d*x]^1*(a + b*Tanh[c + d*x]^3), x, 3, (b*Log[Cosh[c + d*x]])/d + (a*Log[Sinh[c + d*x]])/d}
{Coth[c + d*x]^2*(a + b*Tanh[c + d*x]^3), x, 2, (a + b)*x - (a*Coth[c + d*x])/d}
{Coth[c + d*x]^3*(a + b*Tanh[c + d*x]^3), x, 2, -(a*Coth[c + d*x]^2)/(2*d) + ((a + b)*Log[Sinh[c + d*x]])/d}
{Coth[c + d*x]^4*(a + b*Tanh[c + d*x]^3), x, 3, (a + b)*x - ((a + b)*Coth[c + d*x])/d - (a*Coth[c + d*x]^3)/(3*d)}
{Coth[c + d*x]^5*(a + b*Tanh[c + d*x]^3), x, 3, -(((a + b)*Coth[c + d*x]^2)/(2*d)) - (a*Coth[c + d*x]^4)/(4*d) + ((a + b)*Log[Sinh[c + d*x]])/d}


{Tanh[c + d*x]^4*(a + b*Tanh[c + d*x]^3)^2, x, 4, (a + b)^2*x - ((a + b)^2*Tanh[c + d*x])/d - ((a + b)^2*Tanh[c + d*x]^3)/(3*d) - (b*(2*a + b)*Tanh[c + d*x]^5)/(5*d) - (b^2*Tanh[c + d*x]^7)/(7*d)}
{Tanh[c + d*x]^3*(a + b*Tanh[c + d*x]^3)^2, x, 4, -((a + b)^2*Log[1 - Tanh[c + d*x]^2])/(2*d) - ((a + b)^2*Tanh[c + d*x]^2)/(2*d) - (b*(2*a + b)*Tanh[c + d*x]^4)/(4*d) - (b^2*Tanh[c + d*x]^6)/(6*d)}
{Tanh[c + d*x]^2*(a + b*Tanh[c + d*x]^3)^2, x, 4, (a + b)^2*x - ((a + b)^2*Tanh[c + d*x])/d - (b*(2*a + b)*Tanh[c + d*x]^3)/(3*d) - (b^2*Tanh[c + d*x]^5)/(5*d)}
{Tanh[c + d*x]^1*(a + b*Tanh[c + d*x]^3)^2, x, 4, -((a + b)^2*Log[1 - Tanh[c + d*x]^2])/(2*d) - (b*(a + b)*Tanh[c + d*x]^2)/(2*d) - (a + b*Tanh[c + d*x]^3)^2/(4*d)}
{Tanh[c + d*x]^0*(a + b*Tanh[c + d*x]^3)^2, x, 4, (a + b)^2*x - (b*(2*a + b)*Tanh[c + d*x])/d - (b^2*Tanh[c + d*x]^3)/(3*d)}
{Coth[c + d*x]^1*(a + b*Tanh[c + d*x]^3)^2, x, 4, (a^2*Log[Tanh[c + d*x]])/d - ((a + b)^2*Log[1 - Tanh[c + d*x]^2])/(2*d) - (b^2*Tanh[c + d*x]^2)/(2*d)}
{Coth[c + d*x]^2*(a + b*Tanh[c + d*x]^3)^2, x, 4, (a + b)^2*x - (a^2*Coth[c + d*x])/d - (b^2*Tanh[c + d*x])/d}
{Coth[c + d*x]^3*(a + b*Tanh[c + d*x]^3)^2, x, 4, -(a^2*Coth[c + d*x]^2)/(2*d) + (a*(a + 2*b)*Log[Tanh[c + d*x]])/d - ((a + b)^2*Log[1 - Tanh[c + d*x]^2])/(2*d)}
{Coth[c + d*x]^4*(a + b*Tanh[c + d*x]^3)^2, x, 4, (a + b)^2*x - (a*(a + 2*b)*Coth[c + d*x])/d - (a^2*Coth[c + d*x]^3)/(3*d)}
{Coth[c + d*x]^5*(a + b*Tanh[c + d*x]^3)^2, x, 4, -((a*(a + 2*b)*Coth[c + d*x]^2)/(2*d)) - (a^2*Coth[c + d*x]^4)/(4*d) + ((a + b)^2*Log[Tanh[c + d*x]])/d - ((a + b)^2*Log[1 - Tanh[c + d*x]^2])/(2*d)}
{Coth[c + d*x]^6*(a + b*Tanh[c + d*x]^3)^2, x, 4, (a + b)^2*x - ((a + b)^2*Coth[c + d*x])/d - (a*(a + 2*b)*Coth[c + d*x]^3)/(3*d) - (a^2*Coth[c + d*x]^5)/(5*d)}
{Coth[c + d*x]^7*(a + b*Tanh[c + d*x]^3)^2, x, 4, -(((a + b)^2*Coth[c + d*x]^2)/(2*d)) - (a*(a + 2*b)*Coth[c + d*x]^4)/(4*d) - (a^2*Coth[c + d*x]^6)/(6*d) + ((a + b)^2*Log[Tanh[c + d*x]])/d - ((a + b)^2*Log[1 - Tanh[c + d*x]^2])/(2*d)}


{Tanh[c + d*x]^4*(a + b*Tanh[c + d*x]^3)^3, x, 4, (a + b)^3*x - ((a + b)^3*Tanh[c + d*x])/d - ((a + b)^3*Tanh[c + d*x]^3)/(3*d) - (b*(3*a^2 + 3*a*b + b^2)*Tanh[c + d*x]^5)/(5*d) - (b^2*(3*a + b)*Tanh[c + d*x]^7)/(7*d) - (b^3*Tanh[c + d*x]^9)/(9*d)}
{Tanh[c + d*x]^3*(a + b*Tanh[c + d*x]^3)^3, x, 4, -((a + b)^3*Log[1 - Tanh[c + d*x]^2])/(2*d) - ((a + b)^3*Tanh[c + d*x]^2)/(2*d) - (b*(3*a^2 + 3*a*b + b^2)*Tanh[c + d*x]^4)/(4*d) - (b^2*(3*a + b)*Tanh[c + d*x]^6)/(6*d) - (b^3*Tanh[c + d*x]^8)/(8*d)}
{Tanh[c + d*x]^2*(a + b*Tanh[c + d*x]^3)^3, x, 4, (a + b)^3*x - ((a + b)^3*Tanh[c + d*x])/d - (b*(3*a^2 + 3*a*b + b^2)*Tanh[c + d*x]^3)/(3*d) - (b^2*(3*a + b)*Tanh[c + d*x]^5)/(5*d) - (b^3*Tanh[c + d*x]^7)/(7*d)}
{Tanh[c + d*x]^1*(a + b*Tanh[c + d*x]^3)^3, x, 4, -((a + b)^3*Log[1 - Tanh[c + d*x]^2])/(2*d) - (b*(a + b)^2*Tanh[c + d*x]^2)/(2*d) - ((a + b)*(a + b*Tanh[c + d*x]^3)^2)/(4*d) - (a + b*Tanh[c + d*x]^3)^3/(6*d)}
{Tanh[c + d*x]^0*(a + b*Tanh[c + d*x]^3)^3, x, 4, (a + b)^3*x - (b*(3*a^2 + 3*a*b + b^2)*Tanh[c + d*x])/d - (b^2*(3*a + b)*Tanh[c + d*x]^3)/(3*d) - (b^3*Tanh[c + d*x]^5)/(5*d)}
{Coth[c + d*x]^1*(a + b*Tanh[c + d*x]^3)^3, x, 4, (a^3*Log[Tanh[c + d*x]])/d - ((a + b)^3*Log[1 - Tanh[c + d*x]^2])/(2*d) - (b^2*(3*a + b)*Tanh[c + d*x]^2)/(2*d) - (b^3*Tanh[c + d*x]^4)/(4*d)}
{Coth[c + d*x]^2*(a + b*Tanh[c + d*x]^3)^3, x, 4, (a + b)^3*x - (a^3*Coth[c + d*x])/d - (b^2*(3*a + b)*Tanh[c + d*x])/d - (b^3*Tanh[c + d*x]^3)/(3*d)}
{Coth[c + d*x]^3*(a + b*Tanh[c + d*x]^3)^3, x, 4, -(a^3*Coth[c + d*x]^2)/(2*d) + (a^2*(a + 3*b)*Log[Tanh[c + d*x]])/d - ((a + b)^3*Log[1 - Tanh[c + d*x]^2])/(2*d) - (b^3*Tanh[c + d*x]^2)/(2*d)}
{Coth[c + d*x]^4*(a + b*Tanh[c + d*x]^3)^3, x, 4, (a + b)^3*x - (a^2*(a + 3*b)*Coth[c + d*x])/d - (a^3*Coth[c + d*x]^3)/(3*d) - (b^3*Tanh[c + d*x])/d}
{Coth[c + d*x]^5*(a + b*Tanh[c + d*x]^3)^3, x, 4, -((a^2*(a + 3*b)*Coth[c + d*x]^2)/(2*d)) - (a^3*Coth[c + d*x]^4)/(4*d) + (a*(a^2 + 3*a*b + 3*b^2)*Log[Tanh[c + d*x]])/d - ((a + b)^3*Log[1 - Tanh[c + d*x]^2])/(2*d)}
{Coth[c + d*x]^6*(a + b*Tanh[c + d*x]^3)^3, x, 4, (a + b)^3*x - (a*(a^2 + 3*a*b + 3*b^2)*Coth[c + d*x])/d - (a^2*(a + 3*b)*Coth[c + d*x]^3)/(3*d) - (a^3*Coth[c + d*x]^5)/(5*d)}
{Coth[c + d*x]^7*(a + b*Tanh[c + d*x]^3)^3, x, 4, -((a*(a^2 + 3*a*b + 3*b^2)*Coth[c + d*x]^2)/(2*d)) - (a^2*(a + 3*b)*Coth[c + d*x]^4)/(4*d) - (a^3*Coth[c + d*x]^6)/(6*d) + ((a + b)^3*Log[Tanh[c + d*x]])/d - ((a + b)^3*Log[1 - Tanh[c + d*x]^2])/(2*d)}


{Tanh[c + d*x]^0*(a + b*Tanh[c + d*x]^3)^4, x, 4, (a + b)^4*x - (b*(2*a + b)*(2*a^2 + 2*a*b + b^2)*Tanh[c + d*x])/d - (b^2*(6*a^2 + 4*a*b + b^2)*Tanh[c + d*x]^3)/(3*d) - (b^3*(4*a + b)*Tanh[c + d*x]^5)/(5*d) - (b^4*Tanh[c + d*x]^7)/(7*d)}


{Tanh[c + d*x]^0*(a + b*Tanh[c + d*x]^3)^5, x, 4, (a + b)^5*x - (b*(5*a^4 + 10*a^3*b + 10*a^2*b^2 + 5*a*b^3 + b^4)*Tanh[c + d*x])/d - (b^2*(10*a^3 + 10*a^2*b + 5*a*b^2 + b^3)*Tanh[c + d*x]^3)/(3*d) - (b^3*(10*a^2 + 5*a*b + b^2)*Tanh[c + d*x]^5)/(5*d) - (b^4*(5*a + b)*Tanh[c + d*x]^7)/(7*d) - (b^5*Tanh[c + d*x]^9)/(9*d)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Tanh[c + d*x]^5/(a + b*Tanh[c + d*x]^3), x, 4, -(Log[1 - Tanh[c + d*x]^2]/(2*(a + b)*d)) + (a^2*Log[a + b*Tanh[c + d*x]^3])/(2*b^2*(a + b)*d) - Tanh[c + d*x]^2/(2*b*d)}
{Tanh[c + d*x]^4/(a + b*Tanh[c + d*x]^3), x, 5, x/(a + b) + (a^(3/2)*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(b^(3/2)*(a + b)*d) - Tanh[c + d*x]/(b*d)}
{Tanh[c + d*x]^3/(a + b*Tanh[c + d*x]^3), x, 4, -Log[1 - Tanh[c + d*x]^2]/(2*(a + b)*d) - (a*Log[a + b*Tanh[c + d*x]^3])/(2*b*(a + b)*d)}
{Tanh[c + d*x]^2/(a + b*Tanh[c + d*x]^3), x, 4, x/(a + b) - (Sqrt[a]*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(Sqrt[b]*(a + b)*d)}
{Tanh[c + d*x]^1/(a + b*Tanh[c + d*x]^3), x, 4, -Log[1 - Tanh[c + d*x]^2]/(2*(a + b)*d) + Log[a + b*Tanh[c + d*x]^3]/(2*(a + b)*d)}
{Tanh[c + d*x]^0/(a + b*Tanh[c + d*x]^3), x, 3, x/(a + b) + (Sqrt[b]*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(Sqrt[a]*(a + b)*d)}
{Coth[c + d*x]^1/(a + b*Tanh[c + d*x]^3), x, 4, Log[Tanh[c + d*x]]/(a*d) - Log[1 - Tanh[c + d*x]^2]/(2*(a + b)*d) - (b*Log[a + b*Tanh[c + d*x]^3])/(2*a*(a + b)*d)}
{Coth[c + d*x]^2/(a + b*Tanh[c + d*x]^3), x, 5, x/(a + b) - (b^(3/2)*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(a^(3/2)*(a + b)*d) - Coth[c + d*x]/(a*d)}
{Coth[c + d*x]^3/(a + b*Tanh[c + d*x]^3), x, 5, -Coth[c + d*x]^2/(2*a*d) + ((a - b)*Log[Tanh[c + d*x]])/(a^2*d) - Log[1 - Tanh[c + d*x]^2]/(2*(a + b)*d) + (b^2*Log[a + b*Tanh[c + d*x]^3])/(2*a^2*(a + b)*d)}
{Coth[c + d*x]^4/(a + b*Tanh[c + d*x]^3), x, 5, x/(a + b) + (b^(5/2)*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(a^(5/2)*(a + b)*d) - ((a - b)*Coth[c + d*x])/(a^2*d) - Coth[c + d*x]^3/(3*a*d)}


{Tanh[c + d*x]^5/(a + b*Tanh[c + d*x]^3)^2, x, 4, -(Log[1 - Tanh[c + d*x]^2]/(2*(a + b)^2*d)) - (a*(a + 2*b)*Log[a + b*Tanh[c + d*x]^3])/(2*b^2*(a + b)^2*d) - a^2/(2*b^2*(a + b)*d*(a + b*Tanh[c + d*x]^3))}
{Tanh[c + d*x]^4/(a + b*Tanh[c + d*x]^3)^2, x, 7, x/(a + b)^2 + (Sqrt[a]*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(2*b^(3/2)*(a + b)*d) - (Sqrt[a]*(a + 2*b)*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(b^(3/2)*(a + b)^2*d) + (a*Tanh[c + d*x])/(2*b*(a + b)*d*(a + b*Tanh[c + d*x]^3))}
{Tanh[c + d*x]^3/(a + b*Tanh[c + d*x]^3)^2, x, 4, -Log[1 - Tanh[c + d*x]^2]/(2*(a + b)^2*d) + Log[a + b*Tanh[c + d*x]^3]/(2*(a + b)^2*d) + a/(2*b*(a + b)*d*(a + b*Tanh[c + d*x]^3))}
{Tanh[c + d*x]^2/(a + b*Tanh[c + d*x]^3)^2, x, 7, x/(a + b)^2 + (Sqrt[b]*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(Sqrt[a]*(a + b)^2*d) - ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]]/(2*Sqrt[a]*Sqrt[b]*(a + b)*d) - Tanh[c + d*x]/(2*(a + b)*d*(a + b*Tanh[c + d*x]^3))}
{Tanh[c + d*x]^1/(a + b*Tanh[c + d*x]^3)^2, x, 4, -Log[1 - Tanh[c + d*x]^2]/(2*(a + b)^2*d) + Log[a + b*Tanh[c + d*x]^3]/(2*(a + b)^2*d) - 1/(2*(a + b)*d*(a + b*Tanh[c + d*x]^3))}
{Tanh[c + d*x]^0/(a + b*Tanh[c + d*x]^3)^2,x, 5, x/(a + b)^2 + (Sqrt[b]*(3*a + b)*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(2*a^(3/2)*(a + b)^2*d) + (b*Tanh[c + d*x])/(2*a*(a + b)*d*(a + b*Tanh[c + d*x]^3))}
{Coth[c + d*x]^1/(a + b*Tanh[c + d*x]^3)^2, x, 6, Log[Tanh[c + d*x]]/(a^2*d) - Log[1 - Tanh[c + d*x]^2]/(2*(a + b)^2*d) - (b*(2*a + b)*Log[a + b*Tanh[c + d*x]^3])/(2*a^2*(a + b)^2*d) + b/(2*a*(a + b)*d*(a + b*Tanh[c + d*x]^3))}
{Coth[c + d*x]^2/(a + b*Tanh[c + d*x]^3)^2, x, 7, x/(a + b)^2 - (b^(3/2)*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(2*a^(5/2)*(a + b)*d) - (b^(3/2)*(2*a + b)*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(a^(5/2)*(a + b)^2*d) - Coth[c + d*x]/(a^2*d) - (b^2*Tanh[c + d*x])/(2*a^2*(a + b)*d*(a + b*Tanh[c + d*x]^3))}
{Coth[c + d*x]^3/(a + b*Tanh[c + d*x]^3)^2, x, 6, -Coth[c + d*x]^2/(2*a^2*d) + ((a - 2*b)*Log[Tanh[c + d*x]])/(a^3*d) - Log[1 - Tanh[c + d*x]^2]/(2*(a + b)^2*d) + (b^2*(3*a + 2*b)*Log[a + b*Tanh[c + d*x]^3])/(2*a^3*(a + b)^2*d) - b^2/(2*a^2*(a + b)*d*(a + b*Tanh[c + d*x]^3))}
{Coth[c + d*x]^4/(a + b*Tanh[c + d*x]^3)^2, x, 7, x/(a + b)^2 + (b^(5/2)*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(2*a^(7/2)*(a + b)*d) + (b^(5/2)*(3*a + 2*b)*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(a^(7/2)*(a + b)^2*d) - ((a - 2*b)*Coth[c + d*x])/(a^3*d) - Coth[c + d*x]^3/(3*a^2*d) + (b^3*Tanh[c + d*x])/(2*a^3*(a + b)*d*(a + b*Tanh[c + d*x]^3))}


{Tanh[c + d*x]^6/(a + b*Tanh[c + d*x]^3)^3, x, 6, x/(a + b)^3 - (Sqrt[a]*(3*a^2 + 10*a*b + 15*b^2)*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(8*b^(5/2)*(a + b)^3*d) + (a*Tanh[c + d*x]^3)/(4*b*(a + b)*d*(a + b*Tanh[c + d*x]^3)^2) + (a*(3*a + 7*b)*Tanh[c + d*x])/(8*b^2*(a + b)^2*d*(a + b*Tanh[c + d*x]^3))}
{Tanh[c + d*x]^5/(a + b*Tanh[c + d*x]^3)^3, x, 4, -(Log[1 - Tanh[c + d*x]^2]/(2*(a + b)^3*d)) + Log[a + b*Tanh[c + d*x]^3]/(2*(a + b)^3*d) - a^2/(4*b^2*(a + b)*d*(a + b*Tanh[c + d*x]^3)^2) + (a*(a + 2*b))/(2*b^2*(a + b)^2*d*(a + b*Tanh[c + d*x]^3))}
{Tanh[c + d*x]^4/(a + b*Tanh[c + d*x]^3)^3, x, 6, x/(a + b)^3 - ((a^2 + 6*a*b - 3*b^2)*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(8*Sqrt[a]*b^(3/2)*(a + b)^3*d) + (a*Tanh[c + d*x])/(4*b*(a + b)*d*(a + b*Tanh[c + d*x]^3)^2) - ((a + 5*b)*Tanh[c + d*x])/(8*b*(a + b)^2*d*(a + b*Tanh[c + d*x]^3))}
{Tanh[c + d*x]^3/(a + b*Tanh[c + d*x]^3)^3, x, 4, -Log[1 - Tanh[c + d*x]^2]/(2*(a + b)^3*d) + Log[a + b*Tanh[c + d*x]^3]/(2*(a + b)^3*d) + a/(4*b*(a + b)*d*(a + b*Tanh[c + d*x]^3)^2) - 1/(2*(a + b)^2*d*(a + b*Tanh[c + d*x]^3))}
{Tanh[c + d*x]^2/(a + b*Tanh[c + d*x]^3)^3, x, 6, x/(a + b)^3 - ((3*a^2 - 6*a*b - b^2)*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(8*a^(3/2)*Sqrt[b]*(a + b)^3*d) - Tanh[c + d*x]/(4*(a + b)*d*(a + b*Tanh[c + d*x]^3)^2) - ((3*a - b)*Tanh[c + d*x])/(8*a*(a + b)^2*d*(a + b*Tanh[c + d*x]^3))}
{Tanh[c + d*x]^1/(a + b*Tanh[c + d*x]^3)^3, x, 4, -Log[1 - Tanh[c + d*x]^2]/(2*(a + b)^3*d) + Log[a + b*Tanh[c + d*x]^3]/(2*(a + b)^3*d) - 1/(4*(a + b)*d*(a + b*Tanh[c + d*x]^3)^2) - 1/(2*(a + b)^2*d*(a + b*Tanh[c + d*x]^3))}
{Tanh[c + d*x]^0/(a + b*Tanh[c + d*x]^3)^3,x, 6, x/(a + b)^3 + (Sqrt[b]*(15*a^2 + 10*a*b + 3*b^2)*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(8*a^(5/2)*(a + b)^3*d) + (b*Tanh[c + d*x])/(4*a*(a + b)*d*(a + b*Tanh[c + d*x]^3)^2) + (b*(7*a + 3*b)*Tanh[c + d*x])/(8*a^2*(a + b)^2*d*(a + b*Tanh[c + d*x]^3))}
{Coth[c + d*x]^1/(a + b*Tanh[c + d*x]^3)^3, x, 7, Log[Tanh[c + d*x]]/(a^3*d) - Log[1 - Tanh[c + d*x]^2]/(2*(a + b)^3*d) - (b*(3*a^2 + 3*a*b + b^2)*Log[a + b*Tanh[c + d*x]^3])/(2*a^3*(a + b)^3*d) + b/(4*a*(a + b)*d*(a + b*Tanh[c + d*x]^3)^2) + (b*(2*a + b))/(2*a^2*(a + b)^2*d*(a + b*Tanh[c + d*x]^3))}
{Coth[c + d*x]^2/(a + b*Tanh[c + d*x]^3)^3, x, 7, x/(a + b)^3 - (b^(3/2)*(35*a^2 + 42*a*b + 15*b^2)*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(8*a^(7/2)*(a + b)^3*d) - ((8*a^2 + 27*a*b + 15*b^2)*Coth[c + d*x])/(8*a^3*(a + b)^2*d) + (b*Coth[c + d*x])/(4*a*(a + b)*d*(a + b*Tanh[c + d*x]^3)^2) + (b*(9*a + 5*b)*Coth[c + d*x])/(8*a^2*(a + b)^2*d*(a + b*Tanh[c + d*x]^3))}
{Coth[c + d*x]^3/(a + b*Tanh[c + d*x]^3)^3, x, 7, -Coth[c + d*x]^2/(2*a^3*d) + ((a - 3*b)*Log[Tanh[c + d*x]])/(a^4*d) - Log[1 - Tanh[c + d*x]^2]/(2*(a + b)^3*d) + (b^2*(6*a^2 + 8*a*b + 3*b^2)*Log[a + b*Tanh[c + d*x]^3])/(2*a^4*(a + b)^3*d) - b^2/(4*a^2*(a + b)*d*(a + b*Tanh[c + d*x]^3)^2) - (b^2*(3*a + 2*b))/(2*a^3*(a + b)^2*d*(a + b*Tanh[c + d*x]^3))}
{Coth[c + d*x]^4/(a + b*Tanh[c + d*x]^3)^3, x, 8, x/(a + b)^3 + (b^(5/2)*(63*a^2 + 90*a*b + 35*b^2)*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(8*a^(9/2)*(a + b)^3*d) - ((8*a^3 - 8*a^2*b - 55*a*b^2 - 35*b^3)*Coth[c + d*x])/(8*a^4*(a + b)^2*d) - ((8*a^2 + 55*a*b + 35*b^2)*Coth[c + d*x]^3)/(24*a^3*(a + b)^2*d) + (b*Coth[c + d*x]^3)/(4*a*(a + b)*d*(a + b*Tanh[c + d*x]^3)^2) + (b*(11*a + 7*b)*Coth[c + d*x]^3)/(8*a^2*(a + b)^2*d*(a + b*Tanh[c + d*x]^3))}


{Tanh[c + d*x]^0/(a + b*Tanh[c + d*x]^3)^4,x, 7, x/(a + b)^4 + (Sqrt[b]*(35*a^3 + 35*a^2*b + 21*a*b^2 + 5*b^3)*ArcTan[(Sqrt[b]*Tanh[c + d*x])/Sqrt[a]])/(16*a^(7/2)*(a + b)^4*d) + (b*Tanh[c + d*x])/(6*a*(a + b)*d*(a + b*Tanh[c + d*x]^3)^3) + (b*(11*a + 5*b)*Tanh[c + d*x])/(24*a^2*(a + b)^2*d*(a + b*Tanh[c + d*x]^3)^2) + (b*(19*a^2 + 16*a*b + 5*b^2)*Tanh[c + d*x])/(16*a^3*(a + b)^3*d*(a + b*Tanh[c + d*x]^3))}


(* ::Subsubsection::Closed:: *)
(*n/2>0*)


{Tanh[x]^5*Sqrt[a + b*Tanh[x]^3], x, 6, 0}
{Tanh[x]^4*Sqrt[a + b*Tanh[x]^3], x, 6, ((a^2 - 4*a*b - 8*b^2)*ArcTanh[(Sqrt[b]*Tanh[x])/Sqrt[a + b*Tanh[x]^3]])/(8*b^(3/2)) + Sqrt[a + b]*ArcTanh[(Sqrt[a + b]*Tanh[x])/Sqrt[a + b*Tanh[x]^3]] - ((a + 4*b)*Tanh[x]*Sqrt[a + b*Tanh[x]^3])/(8*b) - (1/4)*Tanh[x]^3*Sqrt[a + b*Tanh[x]^3]}
{Tanh[x]^3*Sqrt[a + b*Tanh[x]^3], x, 5, Sqrt[a + b]*ArcTanh[Sqrt[a + b*Tanh[x]^3]/Sqrt[a + b]] - Sqrt[a + b*Tanh[x]^3] - (a + b*Tanh[x]^3)^(3/2)/(3*b)}
{Tanh[x]^2*Sqrt[a + b*Tanh[x]^3], x, 5, -(((a + 2*b)*ArcTanh[(Sqrt[b]*Tanh[x])/Sqrt[a + b*Tanh[x]^3]])/(2*Sqrt[b])) + Sqrt[a + b]*ArcTanh[(Sqrt[a + b]*Tanh[x])/Sqrt[a + b*Tanh[x]^3]] - (1/2)*Tanh[x]*Sqrt[a + b*Tanh[x]^3]}
{Tanh[x]^1*Sqrt[a + b*Tanh[x]^3], x, 4, Sqrt[a + b]*ArcTanh[Sqrt[a + b*Tanh[x]^3]/Sqrt[a + b]] - Sqrt[a + b*Tanh[x]^3]}
{Tanh[x]^0*Sqrt[a + b*Tanh[x]^3], x, 4, (-Sqrt[b])*ArcTanh[(Sqrt[b]*Tanh[x])/Sqrt[a + b*Tanh[x]^3]] + Sqrt[a + b]*ArcTanh[(Sqrt[a + b]*Tanh[x])/Sqrt[a + b*Tanh[x]^3]]}
{Coth[x]^1*Sqrt[a + b*Tanh[x]^3], x, 6, (-Sqrt[a])*ArcTanh[Sqrt[a + b*Tanh[x]^3]/Sqrt[a]] + Sqrt[a + b]*ArcTanh[Sqrt[a + b*Tanh[x]^3]/Sqrt[a + b]]}
{Coth[x]^2*Sqrt[a + b*Tanh[x]^3], x, 4, Sqrt[a + b]*ArcTanh[(Sqrt[a + b]*Tanh[x])/Sqrt[a + b*Tanh[x]^3]] - Coth[x]*Sqrt[a + b*Tanh[x]^3]}
{Coth[x]^3*Sqrt[a + b*Tanh[x]^3], x, 6, -(((2*a + b)*ArcTanh[Sqrt[a + b*Tanh[x]^3]/Sqrt[a]])/(2*Sqrt[a])) + Sqrt[a + b]*ArcTanh[Sqrt[a + b*Tanh[x]^3]/Sqrt[a + b]] - (1/2)*Coth[x]^2*Sqrt[a + b*Tanh[x]^3]}
{Coth[x]^4*Sqrt[a + b*Tanh[x]^3], x, 5, Sqrt[a + b]*ArcTanh[(Sqrt[a + b]*Tanh[x])/Sqrt[a + b*Tanh[x]^3]] - ((3*a + b)*Coth[x]*Sqrt[a + b*Tanh[x]^3])/(3*a) - (1/3)*Coth[x]^3*Sqrt[a + b*Tanh[x]^3]}
{Coth[x]^5*Sqrt[a + b*Tanh[x]^3], x, 7, -(((8*a^2 + 4*a*b - b^2)*ArcTanh[Sqrt[a + b*Tanh[x]^3]/Sqrt[a]])/(8*a^(3/2))) + Sqrt[a + b]*ArcTanh[Sqrt[a + b*Tanh[x]^3]/Sqrt[a + b]] - ((4*a + b)*Coth[x]^2*Sqrt[a + b*Tanh[x]^3])/(8*a) - (1/4)*Coth[x]^4*Sqrt[a + b*Tanh[x]^3]}


{Tanh[x]^3*(a + b*Tanh[x]^3)^(3/2), x, 6, (a + b)^(3/2)*ArcTanh[Sqrt[a + b*Tanh[x]^3]/Sqrt[a + b]] - (a + b)*Sqrt[a + b*Tanh[x]^3] - (1/3)*(a + b*Tanh[x]^3)^(3/2) - (a + b*Tanh[x]^3)^(5/2)/(5*b)}
{Tanh[x]^2*(a + b*Tanh[x]^3)^(3/2), x, 6, -(((3*a^2 + 12*a*b + 8*b^2)*ArcTanh[(Sqrt[b]*Tanh[x])/Sqrt[a + b*Tanh[x]^3]])/(8*Sqrt[b])) + (a + b)^(3/2)*ArcTanh[(Sqrt[a + b]*Tanh[x])/Sqrt[a + b*Tanh[x]^3]] - (1/8)*(5*a + 4*b)*Tanh[x]*Sqrt[a + b*Tanh[x]^3] - (1/4)*b*Tanh[x]^3*Sqrt[a + b*Tanh[x]^3]}
{Tanh[x]^1*(a + b*Tanh[x]^3)^(3/2), x, 5, (a + b)^(3/2)*ArcTanh[Sqrt[a + b*Tanh[x]^3]/Sqrt[a + b]] - (a + b)*Sqrt[a + b*Tanh[x]^3] - (1/3)*(a + b*Tanh[x]^3)^(3/2)}
{Tanh[x]^0*(a + b*Tanh[x]^3)^(3/2), x, 5, (-(1/2))*Sqrt[b]*(3*a + 2*b)*ArcTanh[(Sqrt[b]*Tanh[x])/Sqrt[a + b*Tanh[x]^3]] + (a + b)^(3/2)*ArcTanh[(Sqrt[a + b]*Tanh[x])/Sqrt[a + b*Tanh[x]^3]] - (1/2)*b*Tanh[x]*Sqrt[a + b*Tanh[x]^3]}
{Coth[x]^1*(a + b*Tanh[x]^3)^(3/2), x, 7, (-a^(3/2))*ArcTanh[Sqrt[a + b*Tanh[x]^3]/Sqrt[a]] + (a + b)^(3/2)*ArcTanh[Sqrt[a + b*Tanh[x]^3]/Sqrt[a + b]] - b*Sqrt[a + b*Tanh[x]^3]}
{Coth[x]^2*(a + b*Tanh[x]^3)^(3/2), x, 5, (-b^(3/2))*ArcTanh[(Sqrt[b]*Tanh[x])/Sqrt[a + b*Tanh[x]^3]] + (a + b)^(3/2)*ArcTanh[(Sqrt[a + b]*Tanh[x])/Sqrt[a + b*Tanh[x]^3]] - a*Coth[x]*Sqrt[a + b*Tanh[x]^3]}


(* ::Subsubsection::Closed:: *)
(*n/2<0*)


{Tanh[x]^5/Sqrt[a + b*Tanh[x]^3], x, 5, ArcTanh[Sqrt[a + b*Tanh[x]^3]/Sqrt[a + b]]/Sqrt[a + b] + ((2*a - 3*b)*Sqrt[a + b*Tanh[x]^3])/(3*b^2) - (Tanh[x]^2*Sqrt[a + b*Tanh[x]^3])/(3*b)}
{Tanh[x]^4/Sqrt[a + b*Tanh[x]^3], x, 5, ((a - 2*b)*ArcTanh[(Sqrt[b]*Tanh[x])/Sqrt[a + b*Tanh[x]^3]])/(2*b^(3/2)) + ArcTanh[(Sqrt[a + b]*Tanh[x])/Sqrt[a + b*Tanh[x]^3]]/Sqrt[a + b] - (Tanh[x]*Sqrt[a + b*Tanh[x]^3])/(2*b)}
{Tanh[x]^3/Sqrt[a + b*Tanh[x]^3], x, 4, ArcTanh[Sqrt[a + b*Tanh[x]^3]/Sqrt[a + b]]/Sqrt[a + b] - Sqrt[a + b*Tanh[x]^3]/b}
{Tanh[x]^2/Sqrt[a + b*Tanh[x]^3], x, 4, -(ArcTanh[(Sqrt[b]*Tanh[x])/Sqrt[a + b*Tanh[x]^3]]/Sqrt[b]) + ArcTanh[(Sqrt[a + b]*Tanh[x])/Sqrt[a + b*Tanh[x]^3]]/Sqrt[a + b]}
{Tanh[x]^1/Sqrt[a + b*Tanh[x]^3], x, 3, ArcTanh[Sqrt[a + b*Tanh[x]^3]/Sqrt[a + b]]/Sqrt[a + b]}
{Tanh[x]^0/Sqrt[a + b*Tanh[x]^3], x, 2, ArcTanh[(Sqrt[a + b]*Tanh[x])/Sqrt[a + b*Tanh[x]^3]]/Sqrt[a + b]}
{Coth[x]^1/Sqrt[a + b*Tanh[x]^3], x, 6, -(ArcTanh[Sqrt[a + b*Tanh[x]^3]/Sqrt[a]]/Sqrt[a]) + ArcTanh[Sqrt[a + b*Tanh[x]^3]/Sqrt[a + b]]/Sqrt[a + b]}
{Coth[x]^2/Sqrt[a + b*Tanh[x]^3], x, 4, ArcTanh[(Sqrt[a + b]*Tanh[x])/Sqrt[a + b*Tanh[x]^3]]/Sqrt[a + b] - (Coth[x]*Sqrt[a + b*Tanh[x]^3])/a}
{Coth[x]^3/Sqrt[a + b*Tanh[x]^3], x, 6, -(((2*a - b)*ArcTanh[Sqrt[a + b*Tanh[x]^3]/Sqrt[a]])/(2*a^(3/2))) + ArcTanh[Sqrt[a + b*Tanh[x]^3]/Sqrt[a + b]]/Sqrt[a + b] - (Coth[x]^2*Sqrt[a + b*Tanh[x]^3])/(2*a)}


{Tanh[x]^5/(a + b*Tanh[x]^3)^(3/2), x, 5, ArcTanh[Sqrt[a + b*Tanh[x]^3]/Sqrt[a + b]]/(a + b)^(3/2) - a^2/(b^2*(a + b)*Sqrt[a + b*Tanh[x]^3]) - Sqrt[a + b*Tanh[x]^3]/b^2}
{Tanh[x]^4/(a + b*Tanh[x]^3)^(3/2), x, 5, -(ArcTanh[(Sqrt[b]*Tanh[x])/Sqrt[a + b*Tanh[x]^3]]/b^(3/2)) + ArcTanh[(Sqrt[a + b]*Tanh[x])/Sqrt[a + b*Tanh[x]^3]]/(a + b)^(3/2) + (a*Tanh[x])/(b*(a + b)*Sqrt[a + b*Tanh[x]^3])}
{Tanh[x]^3/(a + b*Tanh[x]^3)^(3/2), x, 4, ArcTanh[Sqrt[a + b*Tanh[x]^3]/Sqrt[a + b]]/(a + b)^(3/2) + a/(b*(a + b)*Sqrt[a + b*Tanh[x]^3])}
{Tanh[x]^2/(a + b*Tanh[x]^3)^(3/2), x, 3, ArcTanh[(Sqrt[a + b]*Tanh[x])/Sqrt[a + b*Tanh[x]^3]]/(a + b)^(3/2) - Tanh[x]/((a + b)*Sqrt[a + b*Tanh[x]^3])}
{Tanh[x]^1/(a + b*Tanh[x]^3)^(3/2), x, 4, ArcTanh[Sqrt[a + b*Tanh[x]^3]/Sqrt[a + b]]/(a + b)^(3/2) - 1/((a + b)*Sqrt[a + b*Tanh[x]^3])}
{Tanh[x]^0/(a + b*Tanh[x]^3)^(3/2), x, 3, ArcTanh[(Sqrt[a + b]*Tanh[x])/Sqrt[a + b*Tanh[x]^3]]/(a + b)^(3/2) + (b*Tanh[x])/(a*(a + b)*Sqrt[a + b*Tanh[x]^3])}
{Coth[x]^1/(a + b*Tanh[x]^3)^(3/2), x, 7, -(ArcTanh[Sqrt[a + b*Tanh[x]^3]/Sqrt[a]]/a^(3/2)) + ArcTanh[Sqrt[a + b*Tanh[x]^3]/Sqrt[a + b]]/(a + b)^(3/2) + b/(a*(a + b)*Sqrt[a + b*Tanh[x]^3])}
{Coth[x]^2/(a + b*Tanh[x]^3)^(3/2), x, 5, ArcTanh[(Sqrt[a + b]*Tanh[x])/Sqrt[a + b*Tanh[x]^3]]/(a + b)^(3/2) + (b*Coth[x])/(a*(a + b)*Sqrt[a + b*Tanh[x]^3]) - ((a + 2*b)*Coth[x]*Sqrt[a + b*Tanh[x]^3])/(a^2*(a + b))}


{Tanh[x]^6/(a + b*Tanh[x]^3)^(5/2), x, 6, -(ArcTanh[(Sqrt[b]*Tanh[x])/Sqrt[a + b*Tanh[x]^3]]/b^(5/2)) + ArcTanh[(Sqrt[a + b]*Tanh[x])/Sqrt[a + b*Tanh[x]^3]]/(a + b)^(5/2) + (a*Tanh[x]^3)/(3*b*(a + b)*(a + b*Tanh[x]^3)^(3/2)) + (a*(a + 2*b)*Tanh[x])/(b^2*(a + b)^2*Sqrt[a + b*Tanh[x]^3])}
{Tanh[x]^5/(a + b*Tanh[x]^3)^(5/2), x, 5, ArcTanh[Sqrt[a + b*Tanh[x]^3]/Sqrt[a + b]]/(a + b)^(5/2) - a^2/(3*b^2*(a + b)*(a + b*Tanh[x]^3)^(3/2)) + (a*(a + 2*b))/(b^2*(a + b)^2*Sqrt[a + b*Tanh[x]^3])}
{Tanh[x]^4/(a + b*Tanh[x]^3)^(5/2), x, 5, ArcTanh[(Sqrt[a + b]*Tanh[x])/Sqrt[a + b*Tanh[x]^3]]/(a + b)^(5/2) + (a*Tanh[x])/(3*b*(a + b)*(a + b*Tanh[x]^3)^(3/2)) - ((a + 4*b)*Tanh[x])/(3*b*(a + b)^2*Sqrt[a + b*Tanh[x]^3])}
{Tanh[x]^3/(a + b*Tanh[x]^3)^(5/2), x, 5, ArcTanh[Sqrt[a + b*Tanh[x]^3]/Sqrt[a + b]]/(a + b)^(5/2) + a/(3*b*(a + b)*(a + b*Tanh[x]^3)^(3/2)) - 1/((a + b)^2*Sqrt[a + b*Tanh[x]^3])}
{Tanh[x]^2/(a + b*Tanh[x]^3)^(5/2), x, 5, ArcTanh[(Sqrt[a + b]*Tanh[x])/Sqrt[a + b*Tanh[x]^3]]/(a + b)^(5/2) - Tanh[x]/(3*(a + b)*(a + b*Tanh[x]^3)^(3/2)) - ((2*a - b)*Tanh[x])/(3*a*(a + b)^2*Sqrt[a + b*Tanh[x]^3])}
{Tanh[x]^1/(a + b*Tanh[x]^3)^(5/2), x, 5, ArcTanh[Sqrt[a + b*Tanh[x]^3]/Sqrt[a + b]]/(a + b)^(5/2) - 1/(3*(a + b)*(a + b*Tanh[x]^3)^(3/2)) - 1/((a + b)^2*Sqrt[a + b*Tanh[x]^3])}
{Tanh[x]^0/(a + b*Tanh[x]^3)^(5/2), x, 5, ArcTanh[(Sqrt[a + b]*Tanh[x])/Sqrt[a + b*Tanh[x]^3]]/(a + b)^(5/2) + (b*Tanh[x])/(3*a*(a + b)*(a + b*Tanh[x]^3)^(3/2)) + (b*(5*a + 2*b)*Tanh[x])/(3*a^2*(a + b)^2*Sqrt[a + b*Tanh[x]^3])}
{Coth[x]^1/(a + b*Tanh[x]^3)^(5/2), x, 8, -(ArcTanh[Sqrt[a + b*Tanh[x]^3]/Sqrt[a]]/a^(5/2)) + ArcTanh[Sqrt[a + b*Tanh[x]^3]/Sqrt[a + b]]/(a + b)^(5/2) + b/(3*a*(a + b)*(a + b*Tanh[x]^3)^(3/2)) + (b*(2*a + b))/(a^2*(a + b)^2*Sqrt[a + b*Tanh[x]^3])}
{Coth[x]^2/(a + b*Tanh[x]^3)^(5/2), x, 6, ArcTanh[(Sqrt[a + b]*Tanh[x])/Sqrt[a + b*Tanh[x]^3]]/(a + b)^(5/2) + (b*Coth[x])/(3*a*(a + b)*(a + b*Tanh[x]^3)^(3/2)) + (b*(7*a + 4*b)*Coth[x])/(3*a^2*(a + b)^2*Sqrt[a + b*Tanh[x]^3]) - ((3*a + 2*b)*(a + 4*b)*Coth[x]*Sqrt[a + b*Tanh[x]^3])/(3*a^3*(a + b)^2)}
