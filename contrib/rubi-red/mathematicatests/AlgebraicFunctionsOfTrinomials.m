(* ::Package:: *)

(* ::Title:: *)
(*Algebraic Function Integration Problems Involving Trinomials*)


(* ::Subsection::Closed:: *)
(*Integrands involving roots of quadratic trinomials*)


(* Integrands of the form x^m/Sqrt[a+b*x+c*x^2] where m is an integer *)
{x^3/Sqrt[a + b*x + c*x^2], x, 7, (5*b^2*Sqrt[a + b*x + c*x^2])/(8*c^3) - (2*a*Sqrt[a + b*x + c*x^2])/(3*c^2) - (5*b*x*Sqrt[a + b*x + c*x^2])/(12*c^2) + (x^2*Sqrt[a + b*x + c*x^2])/(3*c) - (5*b^3*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(16*c^(7/2)) + (3*a*b*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(4*c^(5/2))}
{x^2/Sqrt[a + b*x + c*x^2], x, 4, -((3*b*Sqrt[a + b*x + c*x^2])/(4*c^2)) + (x*Sqrt[a + b*x + c*x^2])/(2*c) + (3*b^2*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(8*c^(5/2)) - (a*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*c^(3/2))}
{x/Sqrt[a + b*x + c*x^2], x, 2, Sqrt[a + b*x + c*x^2]/c - (b*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*c^(3/2))}
{1/Sqrt[a + b*x + c*x^2], x, 1, ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])]/Sqrt[c]}
{1/(x*Sqrt[a + b*x + c*x^2]), x, 1, -(ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])]/Sqrt[a])}
{1/(x^2*Sqrt[a + b*x + c*x^2]), x, 2, -(Sqrt[a + b*x + c*x^2]/(a*x)) + (b*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/(2*a^(3/2))}
{1/(x^3*Sqrt[a + b*x + c*x^2]), x, 4, -(Sqrt[a + b*x + c*x^2]/(2*a*x^2)) + (3*b*Sqrt[a + b*x + c*x^2])/(4*a^2*x) - (3*b^2*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/(8*a^(5/2)) + (c*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/(2*a^(3/2))}

{x^3/Sqrt[a + b*x - c*x^2], x, 7, -((5*b^2*Sqrt[a + b*x - c*x^2])/(8*c^3)) - (2*a*Sqrt[a + b*x - c*x^2])/(3*c^2) - (5*b*x*Sqrt[a + b*x - c*x^2])/(12*c^2) - (x^2*Sqrt[a + b*x - c*x^2])/(3*c) - (5*b^3*ArcTan[(b - 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x - c*x^2])])/(16*c^(7/2)) - (3*a*b*ArcTan[(b - 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x - c*x^2])])/(4*c^(5/2))}
{x^2/Sqrt[a + b*x - c*x^2], x, 4, -((3*b*Sqrt[a + b*x - c*x^2])/(4*c^2)) - (x*Sqrt[a + b*x - c*x^2])/(2*c) - (3*b^2*ArcTan[(b - 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x - c*x^2])])/(8*c^(5/2)) - (a*ArcTan[(b - 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x - c*x^2])])/(2*c^(3/2))}
{x/Sqrt[a + b*x - c*x^2], x, 2, -(Sqrt[a + b*x - c*x^2]/c) - (b*ArcTan[(b - 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x - c*x^2])])/(2*c^(3/2))}
{1/Sqrt[a + b*x - c*x^2], x, 1, -(ArcTan[(b - 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x - c*x^2])]/Sqrt[c])}
{1/(x*Sqrt[-a + b*x + c*x^2]), x, 1, -(ArcTan[(2*a - b*x)/(2*Sqrt[a]*Sqrt[-a + b*x + c*x^2])]/Sqrt[a])}
{1/(x^2*Sqrt[-a + b*x + c*x^2]), x, 2, Sqrt[-a + b*x + c*x^2]/(a*x) - (b*ArcTan[(2*a - b*x)/(2*Sqrt[a]*Sqrt[-a + b*x + c*x^2])])/(2*a^(3/2))}
{1/(x^3*Sqrt[-a + b*x + c*x^2]), x, 4, Sqrt[-a + b*x + c*x^2]/(2*a*x^2) + (3*b*Sqrt[-a + b*x + c*x^2])/(4*a^2*x) - (3*b^2*ArcTan[(2*a - b*x)/(2*Sqrt[a]*Sqrt[-a + b*x + c*x^2])])/(8*a^(5/2)) - (c*ArcTan[(2*a - b*x)/(2*Sqrt[a]*Sqrt[-a + b*x + c*x^2])])/(2*a^(3/2))}


(* Integrands of the form x^m*Sqrt[a+b*x+c*x^2] where m is an integer *)
{x^3*Sqrt[a + b*x + c*x^2], x, 10, -((7*b^3*(b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(128*c^4)) + (3*a*b*(b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(32*c^3) + (7*b^2*(a + b*x + c*x^2)^(3/2))/(48*c^3) - (2*a*(a + b*x + c*x^2)^(3/2))/(15*c^2) - (7*b*x*(a + b*x + c*x^2)^(3/2))/(40*c^2) + (x^2*(a + b*x + c*x^2)^(3/2))/(5*c) + (7*b^5*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(256*c^(9/2)) - (3*a*b*((10*b^2)/3 - 4*a*c)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(64*c^(7/2))}
{x^2*Sqrt[a + b*x + c*x^2], x, 6, (5*b^2*(b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(64*c^3) - (a*(b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(16*c^2) - (5*b*(a + b*x + c*x^2)^(3/2))/(24*c^2) + (x*(a + b*x + c*x^2)^(3/2))/(4*c) - (5*b^4*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(128*c^(7/2)) + (a*(6*b^2 - 4*a*c)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(32*c^(5/2))}
{x*Sqrt[a + b*x + c*x^2], x, 3, -((b*(b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(8*c^2)) + (a + b*x + c*x^2)^(3/2)/(3*c) + (b*(b^2 - 4*a*c)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(16*c^(5/2))}
{Sqrt[a + b*x + c*x^2], x, 2, ((b + 2*c*x)*Sqrt[a + b*x + c*x^2])/(4*c) - ((b^2 - 4*a*c)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(8*c^(3/2))}
{Sqrt[a + b*x + c*x^2]/x, x, 3, Sqrt[a + b*x + c*x^2] - Sqrt[a]*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])] + (b*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c])}
{Sqrt[a + b*x + c*x^2]/x^2, x, 3, -(Sqrt[a + b*x + c*x^2]/x) - (b*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[a]) + Sqrt[c]*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])]}
{Sqrt[a + b*x + c*x^2]/x^3, x, 4, -(Sqrt[a + b*x + c*x^2]/(2*x^2)) - (b*Sqrt[a + b*x + c*x^2])/(4*a*x) + (b^2*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/(8*a^(3/2)) - (c*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[a])}

{x^3*Sqrt[a + b*x - c*x^2], x, 10, -((7*b^3*(b - 2*c*x)*Sqrt[a + b*x - c*x^2])/(128*c^4)) - (3*a*b*(b - 2*c*x)*Sqrt[a + b*x - c*x^2])/(32*c^3) - (7*b^2*(a + b*x - c*x^2)^(3/2))/(48*c^3) - (2*a*(a + b*x - c*x^2)^(3/2))/(15*c^2) - (7*b*x*(a + b*x - c*x^2)^(3/2))/(40*c^2) - (x^2*(a + b*x - c*x^2)^(3/2))/(5*c) - (7*b^5*ArcTan[(b - 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x - c*x^2])])/(256*c^(9/2)) - (3*a*b*((10*b^2)/3 + 4*a*c)*ArcTan[(b - 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x - c*x^2])])/(64*c^(7/2))}
{x^2*Sqrt[a + b*x - c*x^2], x, 6, -((5*b^2*(b - 2*c*x)*Sqrt[a + b*x - c*x^2])/(64*c^3)) - (a*(b - 2*c*x)*Sqrt[a + b*x - c*x^2])/(16*c^2) - (5*b*(a + b*x - c*x^2)^(3/2))/(24*c^2) - (x*(a + b*x - c*x^2)^(3/2))/(4*c) - (5*b^4*ArcTan[(b - 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x - c*x^2])])/(128*c^(7/2)) - (a*(6*b^2 + 4*a*c)*ArcTan[(b - 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x - c*x^2])])/(32*c^(5/2))}
{x*Sqrt[a + b*x - c*x^2], x, 3, -((b*(b - 2*c*x)*Sqrt[a + b*x - c*x^2])/(8*c^2)) - (a + b*x - c*x^2)^(3/2)/(3*c) - (b*(b^2 + 4*a*c)*ArcTan[(b - 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x - c*x^2])])/(16*c^(5/2))}
{Sqrt[a + b*x - c*x^2], x, 2, -(((b - 2*c*x)*Sqrt[a + b*x - c*x^2])/(4*c)) - ((b^2 + 4*a*c)*ArcTan[(b - 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x - c*x^2])])/(8*c^(3/2))}
{Sqrt[-a + b*x + c*x^2]/x, x, 3, Sqrt[-a + b*x + c*x^2] + Sqrt[a]*ArcTan[(2*a - b*x)/(2*Sqrt[a]*Sqrt[-a + b*x + c*x^2])] + (b*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[-a + b*x + c*x^2])])/(2*Sqrt[c])}
{Sqrt[-a + b*x + c*x^2]/x^2, x, 3, -(Sqrt[-a + b*x + c*x^2]/x) - (b*ArcTan[(2*a - b*x)/(2*Sqrt[a]*Sqrt[-a + b*x + c*x^2])])/(2*Sqrt[a]) + Sqrt[c]*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[-a + b*x + c*x^2])]}
{Sqrt[-a + b*x + c*x^2]/x^3, x, 4, -(Sqrt[-a + b*x + c*x^2]/(2*x^2)) + (b*Sqrt[-a + b*x + c*x^2])/(4*a*x) - (b^2*ArcTan[(2*a - b*x)/(2*Sqrt[a]*Sqrt[-a + b*x + c*x^2])])/(8*a^(3/2)) - (c*ArcTan[(2*a - b*x)/(2*Sqrt[a]*Sqrt[-a + b*x + c*x^2])])/(2*Sqrt[a])}


(* Integrands of the form x^m/(a+b*x+c*x^2)^(3/2) where m is an integer *)
{x^3/(a + b*x + c*x^2)^(3/2), x, 7, (2*a)/(c^2*Sqrt[a + b*x + c*x^2]) + (3*b*x)/(2*c^2*Sqrt[a + b*x + c*x^2]) - (4*a*b*x)/(c*(b^2 - 4*a*c)*Sqrt[a + b*x + c*x^2]) + x^2/(c*Sqrt[a + b*x + c*x^2]) + (3*b^2*((2*a)/3 + b*x))/(2*c^2*(b^2 - 4*a*c)*Sqrt[a + b*x + c*x^2]) - (3*b*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*c^(5/2))}
{x^2/(a + b*x + c*x^2)^(3/2), x, 4, -(x/(c*Sqrt[a + b*x + c*x^2])) - (b*(2*a + b*x))/(c*(b^2 - 4*a*c)*Sqrt[a + b*x + c*x^2]) + ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])]/c^(3/2)}
{x/(a + b*x + c*x^2)^(3/2), x, 2, (2*(2*a + b*x))/((b^2 - 4*a*c)*Sqrt[a + b*x + c*x^2])}
{1/(a + b*x + c*x^2)^(3/2), x, 1, -((2*(b + 2*c*x))/((b^2 - 4*a*c)*Sqrt[a + b*x + c*x^2]))}
{1/(x*(a + b*x + c*x^2)^(3/2)), x, 3, 1/(a*Sqrt[a + b*x + c*x^2]) + (b*(b + 2*c*x))/(a*(b^2 - 4*a*c)*Sqrt[a + b*x + c*x^2]) - ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])]/a^(3/2)}
{1/(x^2*(a + b*x + c*x^2)^(3/2)), x, 5, -((3*b)/(2*a^2*Sqrt[a + b*x + c*x^2])) - 1/(a*x*Sqrt[a + b*x + c*x^2]) - (3*b^2*(b + 2*c*x))/(2*a^2*(b^2 - 4*a*c)*Sqrt[a + b*x + c*x^2]) + (4*c*(b + 2*c*x))/(a*(b^2 - 4*a*c)*Sqrt[a + b*x + c*x^2]) + (3*b*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/(2*a^(5/2))}
{1/(x^3*(a + b*x + c*x^2)^(3/2)), x, 9, (15*b^2)/(8*a^3*Sqrt[a + b*x + c*x^2]) - (3*c)/(2*a^2*Sqrt[a + b*x + c*x^2]) - 1/(2*a*x^2*Sqrt[a + b*x + c*x^2]) + (5*b)/(4*a^2*x*Sqrt[a + b*x + c*x^2]) + (15*b^3*(b + 2*c*x))/(8*a^3*(b^2 - 4*a*c)*Sqrt[a + b*x + c*x^2]) - (13*b*c*(b + 2*c*x))/(2*a^2*(b^2 - 4*a*c)*Sqrt[a + b*x + c*x^2]) - (15*b^2*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/(8*a^(7/2)) + (3*c*ArcTanh[(2*a + b*x)/(2*Sqrt[a]*Sqrt[a + b*x + c*x^2])])/(2*a^(5/2))}

{x^3/(a + b*x - c*x^2)^(3/2), x, 7, (2*a)/(c^2*Sqrt[a + b*x - c*x^2]) + (3*b*x)/(2*c^2*Sqrt[a + b*x - c*x^2]) + (4*a*b*x)/(c*(b^2 + 4*a*c)*Sqrt[a + b*x - c*x^2]) - x^2/(c*Sqrt[a + b*x - c*x^2]) + (3*b^2*((2*a)/3 + b*x))/(2*c^2*(b^2 + 4*a*c)*Sqrt[a + b*x - c*x^2]) + (3*b*ArcTan[(b - 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x - c*x^2])])/(2*c^(5/2))}
{x^2/(a + b*x - c*x^2)^(3/2), x, 4, x/(c*Sqrt[a + b*x - c*x^2]) + (b*(2*a + b*x))/(c*(b^2 + 4*a*c)*Sqrt[a + b*x - c*x^2]) + ArcTan[(b - 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x - c*x^2])]/c^(3/2)}
{x/(a + b*x - c*x^2)^(3/2), x, 2, (2*(2*a + b*x))/((b^2 + 4*a*c)*Sqrt[a + b*x - c*x^2])}
{1/(a + b*x - c*x^2)^(3/2), x, 1, -((2*(b - 2*c*x))/((b^2 + 4*a*c)*Sqrt[a + b*x - c*x^2]))}
{1/(x*(-a + b*x + c*x^2)^(3/2)), x, 3, -(1/(a*Sqrt[-a + b*x + c*x^2])) - (b*(b + 2*c*x))/(a*(b^2 + 4*a*c)*Sqrt[-a + b*x + c*x^2]) + ArcTan[(2*a - b*x)/(2*Sqrt[a]*Sqrt[-a + b*x + c*x^2])]/a^(3/2)}
{1/(x^2*(-a + b*x + c*x^2)^(3/2)), x, 5, -((3*b)/(2*a^2*Sqrt[-a + b*x + c*x^2])) + 1/(a*x*Sqrt[-a + b*x + c*x^2]) - (3*b^2*(b + 2*c*x))/(2*a^2*(b^2 + 4*a*c)*Sqrt[-a + b*x + c*x^2]) - (4*c*(b + 2*c*x))/(a*(b^2 + 4*a*c)*Sqrt[-a + b*x + c*x^2]) + (3*b*ArcTan[(2*a - b*x)/(2*Sqrt[a]*Sqrt[-a + b*x + c*x^2])])/(2*a^(5/2))}
{1/(x^3*(-a + b*x + c*x^2)^(3/2)), x, 9, -((15*b^2)/(8*a^3*Sqrt[-a + b*x + c*x^2])) - (3*c)/(2*a^2*Sqrt[-a + b*x + c*x^2]) + 1/(2*a*x^2*Sqrt[-a + b*x + c*x^2]) + (5*b)/(4*a^2*x*Sqrt[-a + b*x + c*x^2]) - (15*b^3*(b + 2*c*x))/(8*a^3*(b^2 + 4*a*c)*Sqrt[-a + b*x + c*x^2]) - (13*b*c*(b + 2*c*x))/(2*a^2*(b^2 + 4*a*c)*Sqrt[-a + b*x + c*x^2]) + (15*b^2*ArcTan[(2*a - b*x)/(2*Sqrt[a]*Sqrt[-a + b*x + c*x^2])])/(8*a^(7/2)) + (3*c*ArcTan[(2*a - b*x)/(2*Sqrt[a]*Sqrt[-a + b*x + c*x^2])])/(2*a^(5/2))}

{1/(4 + 12*x + 9*x^2)^(3/2), x, 1, -((2 + 3*x)/(6*(4 + 12*x + 9*x^2)^(3/2)))}


(* Integrands of the form 1/Sqrt[a+b*x+c*x^2] where b^2-4*a*c==0 *)
{1/Sqrt[4 + 12*x + 9*x^2], x, 3, ((2 + 3*x)*Log[2 + 3*x])/(3*Sqrt[4 + 12*x + 9*x^2])}
{1/Sqrt[4 - 12*x + 9*x^2], x, 3, -(((2 - 3*x)*Log[2 - 3*x])/(3*Sqrt[4 - 12*x + 9*x^2]))}
{1/Sqrt[-4 + 12*x - 9*x^2], x, 3, -(((2 - 3*x)*Log[2 - 3*x])/(3*Sqrt[-4 + 12*x - 9*x^2]))}
{1/Sqrt[-4 - 12*x - 9*x^2], x, 3, ((2 + 3*x)*Log[2 + 3*x])/(3*Sqrt[-4 - 12*x - 9*x^2])}
{1/Sqrt[a^2 + 2*a*b*x + b^2*x^2], x, 3, ((a + b*x)*Log[a + b*x])/(b*Sqrt[a^2 + 2*a*b*x + b^2*x^2])}
{1/Sqrt[a^2 - 2*a*b*x + b^2*x^2], x, 3, -(((a - b*x)*Log[a - b*x])/(b*Sqrt[a^2 - 2*a*b*x + b^2*x^2]))}
{1/Sqrt[-a^2 + 2*a*b*x - b^2*x^2], x, 3, -(((a - b*x)*Log[a - b*x])/(b*Sqrt[-a^2 + 2*a*b*x - b^2*x^2]))}
{1/Sqrt[-a^2 - 2*a*b*x - b^2*x^2], x, 3, ((a + b*x)*Log[a + b*x])/(b*Sqrt[-a^2 - 2*a*b*x - b^2*x^2])}


(* Integrands of the form 1/Sqrt[a+b*x+c*x^2] *)
{1/Sqrt[5 - 6*x + 9*x^2], x, 1, ArcSinh[(-1 + 3*x)/2]/3}
{1/Sqrt[3 - 4*x - 4*x^2], x, 1, ArcSin[1/2 + x]/2, (-(1/2))*ArcSin[(1/2)*(-1 - 2*x)]}
{1/Sqrt[-8 + 6*x + 9*x^2], x, 1, (1/3)*ArcTanh[(1 + 3*x)/Sqrt[-8 + 6*x + 9*x^2]]}
{1/Sqrt[2 + 4*x + 3*x^2], x, 1, ArcSinh[(2 + 3*x)/Sqrt[2]]/Sqrt[3]}
{1/Sqrt[2 + 4*x - 3*x^2], x, 1, -(ArcSin[(2 - 3*x)/Sqrt[10]]/Sqrt[3])}
{1/Sqrt[2 + 5*x + 3*x^2], x, 1, ArcTanh[(5 + 6*x)/(2*Sqrt[3]*Sqrt[2 + 5*x + 3*x^2])]/Sqrt[3]}
{1/Sqrt[2 + 5*x - 3*x^2], x, 1, -(ArcSin[(5 - 6*x)/7]/Sqrt[3])}
{1/Sqrt[-2 + 4*x + 3*x^2], x, 1, ArcTanh[(2 + 3*x)/(Sqrt[3]*Sqrt[-2 + 4*x + 3*x^2])]/Sqrt[3]}
{1/Sqrt[-2 + 4*x - 3*x^2], x, 1, -(ArcTan[(2 - 3*x)/(Sqrt[3]*Sqrt[-2 + 4*x - 3*x^2])]/Sqrt[3])}
{1/Sqrt[-2 + 5*x + 3*x^2], x, 1, ArcTanh[(5 + 6*x)/(2*Sqrt[3]*Sqrt[-2 + 5*x + 3*x^2])]/Sqrt[3]}
{1/Sqrt[-2 + 5*x - 3*x^2], x, 1, -(ArcSin[5 - 6*x]/Sqrt[3])}
{1/Sqrt[b*x - b^2*x^2], x, 1, -(ArcSin[1 - 2*b*x]/b)}
{1/Sqrt[b*x + b^2*x^2], x, 1, (2*ArcTanh[(b*x)/Sqrt[b*x + b^2*x^2]])/b}

{1/Sqrt[(4*c + b^2)/(4*c) + b*x + c*x^2], x, 1, ArcSinh[(b + 2*c*x)/(2*Sqrt[c])]/Sqrt[c]}
{1/Sqrt[(4*c - b^2)/(4*c) + b*x - c*x^2], x, 1, -(ArcSin[(b - 2*c*x)/(2*Sqrt[c])]/Sqrt[c])}
{1/Sqrt[(c - b^2)/(4*c) + b*x - c*x^2], x, 1, -(ArcSin[(b - 2*c*x)/Sqrt[c]]/Sqrt[c])}


(* Integrands of the form Sqrt[a+b*x+c*x^2] where b^2-4*a*c==0 *)
{Sqrt[4 + 12*x + 9*x^2], x, 1, (1/6)*(2 + 3*x)*Sqrt[4 + 12*x + 9*x^2]}
{Sqrt[4 - 12*x + 9*x^2], x, 1, (-(1/6))*(2 - 3*x)*Sqrt[4 - 12*x + 9*x^2]}
{Sqrt[-4 + 12*x - 9*x^2], x, 1, (-(1/6))*(2 - 3*x)*Sqrt[-4 + 12*x - 9*x^2]}
{Sqrt[-4 - 12*x - 9*x^2], x, 1, (1/6)*(2 + 3*x)*Sqrt[-4 - 12*x - 9*x^2]}
{Sqrt[a^2 + 2*a*b*x + b^2*x^2], x, 1, ((a + b*x)*Sqrt[a^2 + 2*a*b*x + b^2*x^2])/(2*b)}
{Sqrt[a^2 - 2*a*b*x + b^2*x^2], x, 1, -(((a - b*x)*Sqrt[a^2 - 2*a*b*x + b^2*x^2])/(2*b))}
{Sqrt[-a^2 + 2*a*b*x - b^2*x^2], x, 1, -(((a - b*x)*Sqrt[-a^2 + 2*a*b*x - b^2*x^2])/(2*b))}
{Sqrt[-a^2 - 2*a*b*x - b^2*x^2], x, 1, ((a + b*x)*Sqrt[-a^2 - 2*a*b*x - b^2*x^2])/(2*b)}


(* Integrands of the form Sqrt[a+b*x+c*x^2] *)
{Sqrt[5 - 6*x + 9*x^2], x, 2, (-(1/6))*(1 - 3*x)*Sqrt[5 - 6*x + 9*x^2] + (2/3)*ArcSinh[(1/2)*(-1 + 3*x)]}
{Sqrt[3 - 4*x - 4*x^2], x, 2, (1/4)*(1 + 2*x)*Sqrt[3 - 4*x - 4*x^2] - ArcSin[(1/2)*(-1 - 2*x)]}
{Sqrt[-8 + 6*x + 9*x^2], x, 2, (1/6)*(1 + 3*x)*Sqrt[-8 + 6*x + 9*x^2] - (3/2)*ArcTanh[(1 + 3*x)/Sqrt[-8 + 6*x + 9*x^2]]}
{Sqrt[2 + 4*x + 3*x^2], x, 2, (1/6)*(2 + 3*x)*Sqrt[2 + 4*x + 3*x^2] + ArcSinh[(2 + 3*x)/Sqrt[2]]/(3*Sqrt[3])}
{Sqrt[2 + 4*x - 3*x^2], x, 2, (-(1/6))*(2 - 3*x)*Sqrt[2 + 4*x - 3*x^2] - (5*ArcSin[(2 - 3*x)/Sqrt[10]])/(3*Sqrt[3])}
{Sqrt[2 + 5*x + 3*x^2], x, 2, (1/12)*(5 + 6*x)*Sqrt[2 + 5*x + 3*x^2] - ArcTanh[(5 + 6*x)/(2*Sqrt[3]*Sqrt[2 + 5*x + 3*x^2])]/(24*Sqrt[3])}
{Sqrt[2 + 5*x - 3*x^2], x, 2, (-(1/12))*(5 - 6*x)*Sqrt[2 + 5*x - 3*x^2] - (49*ArcSin[(1/7)*(5 - 6*x)])/(24*Sqrt[3])}
{Sqrt[-2 + 4*x + 3*x^2], x, 2, (1/6)*(2 + 3*x)*Sqrt[-2 + 4*x + 3*x^2] - (5*ArcTanh[(2 + 3*x)/(Sqrt[3]*Sqrt[-2 + 4*x + 3*x^2])])/(3*Sqrt[3])}
{Sqrt[-2 + 4*x - 3*x^2], x, 2, (-(1/6))*(2 - 3*x)*Sqrt[-2 + 4*x - 3*x^2] + ArcTan[(2 - 3*x)/(Sqrt[3]*Sqrt[-2 + 4*x - 3*x^2])]/(3*Sqrt[3])}
{Sqrt[-2 + 5*x + 3*x^2], x, 2, (1/12)*(5 + 6*x)*Sqrt[-2 + 5*x + 3*x^2] - (49*ArcTanh[(5 + 6*x)/(2*Sqrt[3]*Sqrt[-2 + 5*x + 3*x^2])])/(24*Sqrt[3])}
{Sqrt[-2 + 5*x - 3*x^2], x, 2, (-(1/12))*(5 - 6*x)*Sqrt[-2 + 5*x - 3*x^2] - ArcSin[5 - 6*x]/(24*Sqrt[3])}


(* Integrands of the form x/Sqrt[a+b*x+c*x^2] where b^2-4*a*c==0 *)
{x/Sqrt[4 + 12*x + 9*x^2], x, 4, (1/9)*Sqrt[4 + 12*x + 9*x^2] - (2*(2 + 3*x)*Log[2 + 3*x])/(9*Sqrt[4 + 12*x + 9*x^2])}
{x/Sqrt[4 - 12*x + 9*x^2], x, 4, (1/9)*Sqrt[4 - 12*x + 9*x^2] - (2*(2 - 3*x)*Log[2 - 3*x])/(9*Sqrt[4 - 12*x + 9*x^2])}
{x/Sqrt[-4 + 12*x - 9*x^2], x, 4, (-(1/9))*Sqrt[-4 + 12*x - 9*x^2] - (2*(2 - 3*x)*Log[2 - 3*x])/(9*Sqrt[-4 + 12*x - 9*x^2])}
{x/Sqrt[-4 - 12*x - 9*x^2], x, 4, (-(1/9))*Sqrt[-4 - 12*x - 9*x^2] - (2*(2 + 3*x)*Log[2 + 3*x])/(9*Sqrt[-4 - 12*x - 9*x^2])}
{x/Sqrt[a^2 + 2*a*b*x + b^2*x^2], x, 4, Sqrt[a^2 + 2*a*b*x + b^2*x^2]/b^2 - (a*(a + b*x)*Log[a + b*x])/(b^2*Sqrt[a^2 + 2*a*b*x + b^2*x^2])}
{x/Sqrt[a^2 - 2*a*b*x + b^2*x^2], x, 4, Sqrt[a^2 - 2*a*b*x + b^2*x^2]/b^2 - (a*(a - b*x)*Log[a - b*x])/(b^2*Sqrt[a^2 - 2*a*b*x + b^2*x^2])}
{x/Sqrt[-a^2 + 2*a*b*x - b^2*x^2], x, 4, -(Sqrt[-a^2 + 2*a*b*x - b^2*x^2]/b^2) - (a*(a - b*x)*Log[a - b*x])/(b^2*Sqrt[-a^2 + 2*a*b*x - b^2*x^2])}
{x/Sqrt[-a^2 - 2*a*b*x - b^2*x^2], x, 4, -(Sqrt[-a^2 - 2*a*b*x - b^2*x^2]/b^2) - (a*(a + b*x)*Log[a + b*x])/(b^2*Sqrt[-a^2 - 2*a*b*x - b^2*x^2])}


(* Integrands of the form x/Sqrt[a+b*x+c*x^2] *)
{x/Sqrt[2 + 4*x + 3*x^2], x, 2, (1/3)*Sqrt[2 + 4*x + 3*x^2] - (2*ArcSinh[(2 + 3*x)/Sqrt[2]])/(3*Sqrt[3])}
{x/Sqrt[2 + 4*x - 3*x^2], x, 2, (-(1/3))*Sqrt[2 + 4*x - 3*x^2] - (2*ArcSin[(2 - 3*x)/Sqrt[10]])/(3*Sqrt[3])}
{x/Sqrt[2 + 5*x + 3*x^2], x, 2, (1/3)*Sqrt[2 + 5*x + 3*x^2] - (5*ArcTanh[(5 + 6*x)/(2*Sqrt[3]*Sqrt[2 + 5*x + 3*x^2])])/(6*Sqrt[3])}
{x/Sqrt[2 + 5*x - 3*x^2], x, 2, (-(1/3))*Sqrt[2 + 5*x - 3*x^2] - (5*ArcSin[(1/7)*(5 - 6*x)])/(6*Sqrt[3])}
{x/Sqrt[-2 + 4*x + 3*x^2], x, 2, (1/3)*Sqrt[-2 + 4*x + 3*x^2] - (2*ArcTanh[(2 + 3*x)/(Sqrt[3]*Sqrt[-2 + 4*x + 3*x^2])])/(3*Sqrt[3])}
{x/Sqrt[-2 + 4*x - 3*x^2], x, 2, (-(1/3))*Sqrt[-2 + 4*x - 3*x^2] - (2*ArcTan[(2 - 3*x)/(Sqrt[3]*Sqrt[-2 + 4*x - 3*x^2])])/(3*Sqrt[3])}
{x/Sqrt[-2 + 5*x + 3*x^2], x, 2, (1/3)*Sqrt[-2 + 5*x + 3*x^2] - (5*ArcTanh[(5 + 6*x)/(2*Sqrt[3]*Sqrt[-2 + 5*x + 3*x^2])])/(6*Sqrt[3])}
{x/Sqrt[-2 + 5*x - 3*x^2], x, 2, (-(1/3))*Sqrt[-2 + 5*x - 3*x^2] - (5*ArcSin[5 - 6*x])/(6*Sqrt[3])}


(* Integrands of the form 1/(x*Sqrt[a+b*x+c*x^2]) where b^2-4*a*c==0 *)
{1/(x*Sqrt[4 + 12*x + 9*x^2]), x, 3, -(((2 + 3*x)*ArcTanh[1 + 3*x])/Sqrt[4 + 12*x + 9*x^2])}
{1/(x*Sqrt[4 - 12*x + 9*x^2]), x, 3, -(((2 - 3*x)*ArcTanh[1 - 3*x])/Sqrt[4 - 12*x + 9*x^2])}
{1/(x*Sqrt[-4 + 12*x - 9*x^2]), x, 3, -(((2 - 3*x)*ArcTanh[1 - 3*x])/Sqrt[-4 + 12*x - 9*x^2])}
{1/(x*Sqrt[-4 - 12*x - 9*x^2]), x, 3, -(((2 + 3*x)*ArcTanh[1 + 3*x])/Sqrt[-4 - 12*x - 9*x^2])}
{1/(x*Sqrt[a^2 + 2*a*b*x + b^2*x^2]), x, 3, ((a + b*x)*(Log[x] - Log[a + b*x]))/(a*Sqrt[a^2 + 2*a*b*x + b^2*x^2])}
{1/(x*Sqrt[a^2 - 2*a*b*x + b^2*x^2]), x, 3, ((a - b*x)*(Log[x] - Log[-a + b*x]))/(a*Sqrt[a^2 - 2*a*b*x + b^2*x^2])}
{1/(x*Sqrt[-a^2 + 2*a*b*x - b^2*x^2]), x, 3, ((a - b*x)*(Log[x] - Log[a - b*x]))/(a*Sqrt[-a^2 + 2*a*b*x - b^2*x^2])}
{1/(x*Sqrt[-a^2 - 2*a*b*x - b^2*x^2]), x, 3, ((a + b*x)*(Log[x] - Log[a + b*x]))/(a*Sqrt[-a^2 - 2*a*b*x - b^2*x^2])}


(* Integrands of the form 1/(x*Sqrt[a+b*x+c*x^2]) *)
{1/(x*Sqrt[2 + 4*x + 3*x^2]), x, 1, -(ArcTanh[(Sqrt[2]*(1 + x))/Sqrt[2 + 4*x + 3*x^2]]/Sqrt[2])}
{1/(x*Sqrt[2 + 4*x - 3*x^2]), x, 1, -(ArcTanh[(Sqrt[2]*(1 + x))/Sqrt[2 + 4*x - 3*x^2]]/Sqrt[2])}
{1/(x*Sqrt[2 + 5*x + 3*x^2]), x, 1, -(ArcTanh[(4 + 5*x)/(2*Sqrt[2]*Sqrt[2 + 5*x + 3*x^2])]/Sqrt[2])}
{1/(x*Sqrt[2 + 5*x - 3*x^2]), x, 1, -(ArcTanh[(4 + 5*x)/(2*Sqrt[2]*Sqrt[2 + 5*x - 3*x^2])]/Sqrt[2])}
{1/(x*Sqrt[-2 + 4*x + 3*x^2]), x, 1, -(ArcTan[(Sqrt[2]*(1 - x))/Sqrt[-2 + 4*x + 3*x^2]]/Sqrt[2])}
{1/(x*Sqrt[-2 + 4*x - 3*x^2]), x, 1, -(ArcTan[(Sqrt[2]*(1 - x))/Sqrt[-2 + 4*x - 3*x^2]]/Sqrt[2])}
{1/(x*Sqrt[-2 + 5*x + 3*x^2]), x, 1, -(ArcTan[(4 - 5*x)/(2*Sqrt[2]*Sqrt[-2 + 5*x + 3*x^2])]/Sqrt[2])}
{1/(x*Sqrt[-2 + 5*x - 3*x^2]), x, 1, -(ArcTan[(4 - 5*x)/(2*Sqrt[2]*Sqrt[-2 + 5*x - 3*x^2])]/Sqrt[2])}


(* Integrands of the form x^m*(a+b*x+c*x^2)^n where m is an integer and n is a half-integer  *)
{1/(x^3*Sqrt[1 + x + x^2]), x, 4, -(Sqrt[1 + x + x^2]/(2*x^2)) + (3*Sqrt[1 + x + x^2])/(4*x) + (1/8)*ArcTanh[(2 + x)/(2*Sqrt[1 + x + x^2])]}

{x/(5 - 4*x - x^2)^(3/2), x, 2, 5/(9*Sqrt[5 - 4*x - x^2]) - (2*x)/(9*Sqrt[5 - 4*x - x^2])}
{(2 + 3*x + x^2)^(-3/2), x, 1, (-2*(3 + 2*x))/Sqrt[2 + 3*x + x^2]}
{(27 - 24*x + 4*x^2)^(-3/2), x, 1, (3 - x)/(9*Sqrt[27 - 24*x + 4*x^2])}
{(5 - 4*x - x^2)^(-5/2), x, 2, (2 + x)/(27*(5 - 4*x - x^2)^(3/2)) + (2*(2 + x))/(243*Sqrt[5 - 4*x - x^2])}

{x*Sqrt[3 - 2*x - x^2], x, 3, (-(1/2))*(1 + x)*Sqrt[3 - 2*x - x^2] - (1/3)*(3 - 2*x - x^2)^(3/2) + 2*ArcSin[(1/2)*(-1 - x)]}
{x*Sqrt[8 + 2*x - x^2], x, 3, (-(1/2))*(1 - x)*Sqrt[8 + 2*x - x^2] - (1/3)*(8 + 2*x - x^2)^(3/2) - (9/2)*ArcSin[(1 - x)/3]}
{x*Sqrt[4 + 2*x + x^2], x, 3, (-(1/2))*(1 + x)*Sqrt[4 + 2*x + x^2] + (1/3)*(4 + 2*x + x^2)^(3/2) - (3/2)*ArcSinh[(1 + x)/Sqrt[3]]}

{Sqrt[-2 - 3*x + 5*x^2]/x, x, 3, Sqrt[-2 - 3*x + 5*x^2] + Sqrt[2]*ArcTan[(4 + 3*x)/(2*Sqrt[2]*Sqrt[-2 - 3*x + 5*x^2])] + (3*ArcTanh[(3 - 10*x)/(2*Sqrt[5]*Sqrt[-2 - 3*x + 5*x^2])])/(2*Sqrt[5])}


(* Integrands of the form (a+b*x)^m*(c+2*a*x+b*x^2)^n where m is an integer and n is a half-integer *)
{(1 + x)/Sqrt[2 + 2*x + x^2], x, 1, Sqrt[2 + 2*x + x^2]}
{(-2 + x)/Sqrt[5 + 4*x - x^2], x, 1, -Sqrt[5 + 4*x - x^2]}
{(1 + x)/(-3 + 2*x + x^2)^(2/3), x, 1, (3*(-3 + 2*x + x^2)^(1/3))/2}
{(b + c*x)/Sqrt[a + 2*b*x + c*x^2], x, 1, Sqrt[a + 2*b*x + c*x^2]}
{(b + c*x)*Sqrt[a + 2*b*x + c*x^2], x, 1, (1/3)*(a + 2*b*x + c*x^2)^(3/2)}
{(b + c*x)/(a + 2*b*x + c*x^2)^(3/7), x, 1, (7/8)*(a + 2*b*x + c*x^2)^(4/7)}


(* Integrands of the form (a+b*x)^m*(c+d*x+e*x^2)^n where m is an integer and n is a half-integer *)
{(a + b*x)*Sqrt[c + d*x + e*x^2], x, 3, -(((b*d - 2*a*e)*(d + 2*e*x)*Sqrt[c + d*x + e*x^2])/(8*e^2)) + (b*(c + d*x + e*x^2)^(3/2))/(3*e) + ((b*d - 2*a*e)*(d^2 - 4*c*e)*ArcTanh[(d + 2*e*x)/(2*Sqrt[e]*Sqrt[c + d*x + e*x^2])])/(16*e^(5/2))}
(* {(a + b*x)^2*Sqrt[c + d*x + e*x^2], x, 6, (5*(b*d - 2*a*e)^2*(d + 2*e*x)*Sqrt[c + d*x + e*x^2])/(64*e^3) - ((b*(b*c - a*d) + a^2*e)*(d + 2*e*x)*Sqrt[c + d*x + e*x^2])/(16*e^2) - (5*b^2*d*(c + d*x + e*x^2)^(3/2))/(24*e^2) + (2*a*b*(c + d*x + e*x^2)^(3/2))/(3*e) + (b^2*x*(c + d*x + e*x^2)^(3/2))/(4*e) - (5*(b*d - 2*a*e)^2*(d^2 - 4*c*e)*ArcTanh[(d + 2*e*x)/(2*Sqrt[e]*Sqrt[c + d*x + e*x^2])])/(128*e^(7/2)) + ((b*(b*c - a*d) + a^2*e)*(d^2 - 4*c*e)*ArcTanh[(d + 2*e*x)/(2*Sqrt[e]*Sqrt[c + d*x + e*x^2])])/(32*e^(5/2))} *)
(* {(a + b*x)^3*Sqrt[c + d*x + e*x^2], x, 10, -((7*(b*d - 2*a*e)^3*(d + 2*e*x)*Sqrt[c + d*x + e*x^2])/(128*e^4)) + (3*(b*d - 2*a*e)*(b*(b*c - a*d) + a^2*e)*(d + 2*e*x)*Sqrt[c + d*x + e*x^2])/(32*e^3) + (7*b*(b*d - 2*a*e)^2*(c + d*x + e*x^2)^(3/2))/(48*e^3) - (2*b*(b*(b*c - a*d) + a^2*e)*(c + d*x + e*x^2)^(3/2))/(15*e^2) - (7*b*(b*d - 2*a*e)*(a + b*x)*(c + d*x + e*x^2)^(3/2))/(40*e^2) + (b*(a + b*x)^2*(c + d*x + e*x^2)^(3/2))/(5*e) + (7*(b*d - 2*a*e)^3*(d^2 - 4*c*e)*ArcTanh[(d + 2*e*x)/(2*Sqrt[e]*Sqrt[c + d*x + e*x^2])])/(256*e^(9/2)) - (3*(b*d - 2*a*e)*(b*(b*c - a*d) + a^2*e)*(d^2 - 4*c*e)*ArcTanh[(d + 2*e*x)/(2*Sqrt[e]*Sqrt[c + d*x + e*x^2])])/(64*e^(7/2))} *)

{(1 + x)^3*Sqrt[2 + 2*x + x^2], x, 2, (-(2/15))*(2 + 2*x + x^2)^(3/2) + (1/5)*(1 + x)^2*(2 + 2*x + x^2)^(3/2)}
{x*(1 + x^2)^3*Sqrt[2 + 2*x^2 + x^4], x, 3, (-(1/15))*(2 + 2*x^2 + x^4)^(3/2) + (1/10)*(1 + x^2)^2*(2 + 2*x^2 + x^4)^(3/2)}

{(3 + x)/Sqrt[5 - 4*x - x^2], x, 2, -Sqrt[5 - 4*x - x^2] - ArcSin[(1/3)*(-2 - x)]}
{(5 - 4*x)/Sqrt[-8 + 12*x - 4*x^2], x, 2, 2*Sqrt[-2 + 3*x - x^2] + (1/2)*ArcSin[3 - 2*x]}
{(3 + 2*x)/Sqrt[5 + 2*x + x^2], x, 2, 2*Sqrt[5 + 2*x + x^2] + ArcSinh[(1 + x)/2]}
{(-2 + 3*x)*Sqrt[8 + 12*x + 9*x^2], x, 3, (-(2/3))*(2 + 3*x)*Sqrt[8 + 12*x + 9*x^2] + (1/9)*(8 + 12*x + 9*x^2)^(3/2) - (8/3)*ArcSinh[(1/2)*(2 + 3*x)]}
{(7 - 2*x)*Sqrt[9 + 16*x - 4*x^2], x, 3, (-(3/2))*(2 - x)*Sqrt[9 + 16*x - 4*x^2] + (1/6)*(9 + 16*x - 4*x^2)^(3/2) - (75/4)*ArcSin[(2*(2 - x))/5]}

{1/((1 - x)*Sqrt[-4 + 2*x + x^2]), x, 1, ArcTan[(3 - 2*x)/Sqrt[-4 + 2*x + x^2]]}
{1/((-2 + x)*Sqrt[3 - 4*x + x^2]), x, 1, ArcTan[Sqrt[3 - 4*x + x^2]]}
{(-1 + x)/Sqrt[3 - 4*x + x^2], x, 2, Sqrt[3 - 4*x + x^2] - ArcTanh[(2 - x)/Sqrt[3 - 4*x + x^2]]}

{(1 + x)/(2 + 3*x + x^2)^(3/2), x, 2, 2/Sqrt[2 + 3*x + x^2] + (2*x)/Sqrt[2 + 3*x + x^2]}

{1/((d + e*x)*Sqrt[a + b*x + c*x^2]), x, 1, ArcTanh[(b*d - 2*a*e + (2*c*d - b*e)*x)/(2*Sqrt[c*d^2 - e*(b*d - a*e)]*Sqrt[a + b*x + c*x^2])]/Sqrt[c*d^2 - e*(b*d - a*e)]}
{1/((d + e*x)*Sqrt[b^2/(4*c) + b*x + c*x^2]), x, 5, (2*(b + 2*c*x)*(Log[b + 2*c*x] - Log[d + e*x]))/((2*c*d - b*e)*Sqrt[b^2/c + 4*b*x + 4*c*x^2])}
{1/(((b*e)/(2*c) + e*x)*Sqrt[a + b*x + c*x^2]), x, 1, (2*Sqrt[c]*ArcTan[(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])/Sqrt[b^2 - 4*a*c]])/(Sqrt[b^2 - 4*a*c]*e)}
{1/((d + e*x)*Sqrt[((-c)*d^2 + b*d*e)/e^2 + b*x + c*x^2]), x, 1, (2*e*Sqrt[-((d*(c*d - b*e))/e^2) + b*x + c*x^2])/((2*c*d - b*e)*(d + e*x))}
{1/(((b*e)/(2*c) + e*x)*Sqrt[b^2/(4*c) + b*x + c*x^2]), x, 3, -(2/(e*Sqrt[b^2/c + 4*b*x + 4*c*x^2]))}


{(3 - x + x^2)/x^(1/3), x, 2, (9*x^(2/3))/2 - (3*x^(5/3))/5 + (3*x^(8/3))/8}

{((-3 + x)*x)^(2/3)*(-3 + 2*x), x, 2, (3*((-3 + x)*x)^(5/3))/5}
(* Following integrand should be simplified to the above integrand before integrating! *)
{(x*(9 - 9*x + 2*x^2))/((-3 + x)*x)^(1/3), x, -8, (3*((-3 + x)*x)^(5/3))/5}


{1/(x + Sqrt[-3 - 2*x + x^2]), x, 7, -(2/(1 - x - Sqrt[-3 - 2*x + x^2])) + 2*Log[1 - x - Sqrt[-3 - 2*x + x^2]] - (3/2)*Log[x + Sqrt[-3 - 2*x + x^2]]}
{1/(x + Sqrt[-3 - 4*x - x^2]), x, 9, -ArcTan[Sqrt[-1 - x]/Sqrt[3 + x]] - Sqrt[2]*ArcTan[(1 - (3*Sqrt[-1 - x])/Sqrt[3 + x])/Sqrt[2]] - (1/2)*Log[2/(3 + x)] + (1/2)*Log[-((2*x)/(3 + x)) - (2*Sqrt[-1 - x])/Sqrt[3 + x]]}
{1/(x + Sqrt[3 - 2*x - x^2]), x, 8, ArcTan[(Sqrt[3] - Sqrt[3 - 2*x - x^2])/x] - ArcTanh[(1 + Sqrt[3] - (Sqrt[3]*(Sqrt[3] - Sqrt[3 - 2*x - x^2]))/x)/Sqrt[7]]/Sqrt[7] - (1/2)*Log[1 + (Sqrt[3] - Sqrt[3 - 2*x - x^2])^2/x^2] + (1/2)*Log[2 - Sqrt[3] - (2*(1 + Sqrt[3])*(Sqrt[3] - Sqrt[3 - 2*x - x^2]))/x + (Sqrt[3]*(Sqrt[3] - Sqrt[3 - 2*x - x^2])^2)/x^2]}

{1/x - 1/(x*Sqrt[1 + b*x + c*x^2]), x, 3, ArcTanh[(2 + b*x)/(2*Sqrt[1 + b*x + c*x^2])] + Log[x]}


{Sqrt[-1 - x + x^2]/(1 + x), x, 3, Sqrt[-1 - x + x^2] + (3/2)*ArcTanh[(1 - 2*x)/(2*Sqrt[-1 - x + x^2])] + ArcTanh[(1 + 3*x)/(2*Sqrt[-1 - x + x^2])]}
{Sqrt[-1 - x + x^2]/(1 - x), x, 3, -Sqrt[-1 - x + x^2] - ArcTan[(3 - x)/(2*Sqrt[-1 - x + x^2])] + (1/2)*ArcTanh[(1 - 2*x)/(2*Sqrt[-1 - x + x^2])]}

{Sqrt[-1 - x + x^2]/(1 - x^2), x, 7, (-(1/2))*ArcTan[(3 - x)/(2*Sqrt[-1 - x + x^2])] + ArcTanh[(1 - 2*x)/(2*Sqrt[-1 - x + x^2])] + (1/2)*ArcTanh[(1 + 3*x)/(2*Sqrt[-1 - x + x^2])]}
{Sqrt[a + b*x + c*x^2]/(d + e*x^2), x, 7, (Sqrt[c]*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/e + (Sqrt[(-c)*d - b*Sqrt[-d]*Sqrt[e] + a*e]*ArcTanh[(b*d + 2*a*Sqrt[-d]*Sqrt[e] - Sqrt[-d]*(2*c*Sqrt[-d] - b*Sqrt[e])*x)/(2*Sqrt[-d]*Sqrt[(-c)*d - b*Sqrt[-d]*Sqrt[e] + a*e]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[-d]*e) + (Sqrt[(-c)*d + b*Sqrt[-d]*Sqrt[e] + a*e]*ArcTanh[(b*d - 2*a*Sqrt[-d]*Sqrt[e] - Sqrt[-d]*(2*c*Sqrt[-d] + b*Sqrt[e])*x)/(2*Sqrt[-d]*Sqrt[(-c)*d + b*Sqrt[-d]*Sqrt[e] + a*e]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[-d]*e)}
{x*Sqrt[a + b*x + c*x^2]/(d + e*x^2), x, 7, Sqrt[a + b*x + c*x^2]/e + (b*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(2*Sqrt[c]*e) - (Sqrt[(-c)*d - b*Sqrt[-d]*Sqrt[e] + a*e]*ArcTanh[(b*d + 2*a*Sqrt[-d]*Sqrt[e] - Sqrt[-d]*(2*c*Sqrt[-d] - b*Sqrt[e])*x)/(2*Sqrt[-d]*Sqrt[(-c)*d - b*Sqrt[-d]*Sqrt[e] + a*e]*Sqrt[a + b*x + c*x^2])])/(2*e^(3/2)) + (Sqrt[(-c)*d + b*Sqrt[-d]*Sqrt[e] + a*e]*ArcTanh[(b*d - 2*a*Sqrt[-d]*Sqrt[e] - Sqrt[-d]*(2*c*Sqrt[-d] + b*Sqrt[e])*x)/(2*Sqrt[-d]*Sqrt[(-c)*d + b*Sqrt[-d]*Sqrt[e] + a*e]*Sqrt[a + b*x + c*x^2])])/(2*e^(3/2))}
{(a + b*x + c*x^2)^(3/2)/(1 - x^2), x, 13, (-(5/4))*b*Sqrt[a + b*x + c*x^2] - (1/2)*c*x*Sqrt[a + b*x + c*x^2] - (1/2)*(a - b + c)^(3/2)*ArcTanh[(2*a - b + (b - 2*c)*x)/(2*Sqrt[a - b + c]*Sqrt[a + b*x + c*x^2])] - ((b - 2*c)*(b - c)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(4*Sqrt[c]) - ((b + c)*(b + 2*c)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(4*Sqrt[c]) + ((b^2 - 12*a*c)*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(8*Sqrt[c]) + (1/2)*(a + b + c)^(3/2)*ArcTanh[(2*a + b + (b + 2*c)*x)/(2*Sqrt[a + b + c]*Sqrt[a + b*x + c*x^2])]}


{Sqrt[-1 - Sqrt[x] + x]/((-1 + x)*Sqrt[x]), x, 8, ArcTan[(3 - Sqrt[x])/(2*Sqrt[-1 - Sqrt[x] + x])] - 2*ArcTanh[(1 - 2*Sqrt[x])/(2*Sqrt[-1 - Sqrt[x] + x])] - ArcTanh[(1 + 3*Sqrt[x])/(2*Sqrt[-1 - Sqrt[x] + x])]}


{Sqrt[a + b*x + c*x^2]/((d + e*x)*(f + g*x)), x, 6, -((2*Sqrt[c*d^2 - e*(b*d - a*e)]*ArcTanh[(Sqrt[c]*d + e*(Sqrt[c]*x + Sqrt[a + x*(b + c*x)]))/Sqrt[c*d^2 - e*(b*d - a*e)]])/(e*(e*f - d*g))) + (2*Sqrt[c*f^2 - g*(b*f - a*g)]*ArcTanh[(Sqrt[c]*f + g*(Sqrt[c]*x + Sqrt[a + x*(b + c*x)]))/Sqrt[c*f^2 - g*(b*f - a*g)]])/(g*(e*f - d*g)) + (Sqrt[c]*Log[b + 2*Sqrt[c]*(Sqrt[c]*x + Sqrt[a + x*(b + c*x)])])/(e*g)}
{(e*Sqrt[a + b*x + c*x^2])/((e*f - d*g)*(d + e*x)) + (g*Sqrt[a + b*x + c*x^2])/(((-e)*f + d*g)*(f + g*x)), x, 7, -((Sqrt[c]*d*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(e*(e*f - d*g))) + (Sqrt[c]*f*ArcTanh[(b + 2*c*x)/(2*Sqrt[c]*Sqrt[a + b*x + c*x^2])])/(g*(e*f - d*g)) + (Sqrt[c*d^2 - e*(b*d - a*e)]*ArcTanh[(b*d - 2*a*e + (2*c*d - b*e)*x)/(2*Sqrt[c*d^2 - e*(b*d - a*e)]*Sqrt[a + b*x + c*x^2])])/(e*(e*f - d*g)) - (Sqrt[c*f^2 - g*(b*f - a*g)]*ArcTanh[(b*f - 2*a*g + (2*c*f - b*g)*x)/(2*Sqrt[c*f^2 - g*(b*f - a*g)]*Sqrt[a + b*x + c*x^2])])/(g*(e*f - d*g))}


{x^(3/2)/(a + b*x + c*x^2), x, 5, (2*Sqrt[x])/c - (Sqrt[2]*(b - (b^2 - 2*a*c)/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*Sqrt[x])/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(c^(3/2)*Sqrt[b - Sqrt[b^2 - 4*a*c]]) - (Sqrt[2]*(b + (b^2 - 2*a*c)/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*Sqrt[x])/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(c^(3/2)*Sqrt[b + Sqrt[b^2 - 4*a*c]])}
{x^(1/2)/(a + b*x + c*x^2), x, 4, -((Sqrt[2]*Sqrt[b - Sqrt[b^2 - 4*a*c]]*ArcTan[(Sqrt[2]*Sqrt[c]*Sqrt[x])/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(Sqrt[c]*Sqrt[b^2 - 4*a*c])) + (Sqrt[2]*Sqrt[b + Sqrt[b^2 - 4*a*c]]*ArcTan[(Sqrt[2]*Sqrt[c]*Sqrt[x])/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(Sqrt[c]*Sqrt[b^2 - 4*a*c])}
{x^(-1/2)/(a + b*x + c*x^2), x, 4, (2*Sqrt[2]*Sqrt[c]*ArcTan[(Sqrt[2]*Sqrt[c]*Sqrt[x])/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(Sqrt[b^2 - 4*a*c]*Sqrt[b - Sqrt[b^2 - 4*a*c]]) - (2*Sqrt[2]*Sqrt[c]*ArcTan[(Sqrt[2]*Sqrt[c]*Sqrt[x])/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(Sqrt[b^2 - 4*a*c]*Sqrt[b + Sqrt[b^2 - 4*a*c]])}
{x^(-3/2)/(a + b*x + c*x^2), x, 5, -(2/(a*Sqrt[x])) - (Sqrt[2]*Sqrt[c]*(1 + b/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*Sqrt[x])/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(a*Sqrt[b - Sqrt[b^2 - 4*a*c]]) - (Sqrt[2]*Sqrt[c]*(1 - b/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*Sqrt[x])/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(a*Sqrt[b + Sqrt[b^2 - 4*a*c]])}
{x^(-5/2)/(a + b*x + c*x^2), x, 6, -(2/(3*a*x^(3/2))) + (2*b)/(a^2*Sqrt[x]) + (Sqrt[2]*Sqrt[c]*(b + (b^2 - 2*a*c)/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*Sqrt[x])/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(a^2*Sqrt[b - Sqrt[b^2 - 4*a*c]]) + (Sqrt[2]*Sqrt[c]*(b - (b^2 - 2*a*c)/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*Sqrt[x])/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(a^2*Sqrt[b + Sqrt[b^2 - 4*a*c]])}


{x^(3/2)*(d + e*x)/(a + b*x + c*x^2), x, 6, (2*(c*d - b*e)*Sqrt[x])/c^2 + (2*e*x^(3/2))/(3*c) - (Sqrt[2]*(a*c*e + b*(c*d - b*e) + (2*a*c^2*d - b*(3*a*c*e + b*(c*d - b*e)))/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*Sqrt[x])/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(c^(5/2)*Sqrt[b - Sqrt[b^2 - 4*a*c]]) - (Sqrt[2]*(a*c*e + b*(c*d - b*e) - (2*a*c^2*d - b*(3*a*c*e + b*(c*d - b*e)))/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*Sqrt[x])/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(c^(5/2)*Sqrt[b + Sqrt[b^2 - 4*a*c]])}
{x^(1/2)*(d + e*x)/(a + b*x + c*x^2), x, 5, (2*e*Sqrt[x])/c + (Sqrt[2]*(c*d - b*e - (2*a*c*e + b*(c*d - b*e))/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*Sqrt[x])/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(c^(3/2)*Sqrt[b - Sqrt[b^2 - 4*a*c]]) + (Sqrt[2]*(c*d - b*e + (2*a*c*e + b*(c*d - b*e))/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*Sqrt[x])/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(c^(3/2)*Sqrt[b + Sqrt[b^2 - 4*a*c]])}
{x^(-1/2)*(d + e*x)/(a + b*x + c*x^2), x, 4, (Sqrt[2]*(e + (2*c*d - b*e)/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*Sqrt[x])/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(Sqrt[c]*Sqrt[b - Sqrt[b^2 - 4*a*c]]) + (Sqrt[2]*(e - (2*c*d - b*e)/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*Sqrt[x])/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(Sqrt[c]*Sqrt[b + Sqrt[b^2 - 4*a*c]])}
{x^(-3/2)*(d + e*x)/(a + b*x + c*x^2), x, 5, -((2*d)/(a*Sqrt[x])) - (Sqrt[2]*Sqrt[c]*(d + (b*d - 2*a*e)/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*Sqrt[x])/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(a*Sqrt[b - Sqrt[b^2 - 4*a*c]]) - (Sqrt[2]*Sqrt[c]*(d - (b*d - 2*a*e)/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*Sqrt[x])/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(a*Sqrt[b + Sqrt[b^2 - 4*a*c]])}
{x^(-5/2)*(d + e*x)/(a + b*x + c*x^2), x, 6, -((2*d)/(3*a*x^(3/2))) + (2*(b*d - a*e))/(a^2*Sqrt[x]) + (Sqrt[2]*Sqrt[c]*(b*d - a*e - (2*a*c*d - b*(b*d - a*e))/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*Sqrt[x])/Sqrt[b - Sqrt[b^2 - 4*a*c]]])/(a^2*Sqrt[b - Sqrt[b^2 - 4*a*c]]) + (Sqrt[2]*Sqrt[c]*(b*d - a*e + (2*a*c*d - b*(b*d - a*e))/Sqrt[b^2 - 4*a*c])*ArcTan[(Sqrt[2]*Sqrt[c]*Sqrt[x])/Sqrt[b + Sqrt[b^2 - 4*a*c]]])/(a^2*Sqrt[b + Sqrt[b^2 - 4*a*c]])}


(* ::Subsection::Closed:: *)
(*Integrands involving roots of symmetric quartic trinomials*)


(* Integrands of the form x^m*Sqrt[a+b*x^2+c*x^4] where m is an integer *)
{x^4*Sqrt[a + b*x^2 + c*x^4], x, 11, -((a*x*Sqrt[a + b*x^2 + c*x^4])/(21*c)) - (4*b*x*(b + 3*c*x^2)*Sqrt[a + b*x^2 + c*x^4])/(105*c^2) + (x*(a + b*x^2 + c*x^4)^(3/2))/(7*c) - (1/(42*Sqrt[2]*(-c)^(5/2)*Sqrt[a + b*x^2 + c*x^4]))*(a*(b - Sqrt[b^2 - 4*a*c])*Sqrt[b + Sqrt[b^2 - 4*a*c]]*Sqrt[1 + (2*c*x^2)/(b - Sqrt[b^2 - 4*a*c])]*Sqrt[1 + (2*c*x^2)/(b + Sqrt[b^2 - 4*a*c])]*(b*EllipticE[ArcSin[(Sqrt[2]*Sqrt[-c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]], (b + Sqrt[b^2 - 4*a*c])/(b - Sqrt[b^2 - 4*a*c])] - (b - (4*a*c)/(b - Sqrt[b^2 - 4*a*c]))*EllipticF[ArcSin[(Sqrt[2]*Sqrt[-c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]], (b + Sqrt[b^2 - 4*a*c])/(b - Sqrt[b^2 - 4*a*c])])) - (1/(105*(-c)^(7/2)*Sqrt[a + b*x^2 + c*x^4]))*(2*Sqrt[2]*b*(b - Sqrt[b^2 - 4*a*c])*Sqrt[b + Sqrt[b^2 - 4*a*c]]*Sqrt[1 + (2*c*x^2)/(b - Sqrt[b^2 - 4*a*c])]*Sqrt[1 + (2*c*x^2)/(b + Sqrt[b^2 - 4*a*c])]*((b^2 - 3*a*c)*EllipticE[ArcSin[(Sqrt[2]*Sqrt[-c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]], (b + Sqrt[b^2 - 4*a*c])/(b - Sqrt[b^2 - 4*a*c])] - (b^2 - 3*a*c - (a*b*c)/(b - Sqrt[b^2 - 4*a*c]))*EllipticF[ArcSin[(Sqrt[2]*Sqrt[-c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]], (b + Sqrt[b^2 - 4*a*c])/(b - Sqrt[b^2 - 4*a*c])]))}
{x^3*Sqrt[a + b*x^2 + c*x^4], x, 4, -((b*(b + 2*c*x^2)*Sqrt[a + b*x^2 + c*x^4])/(16*c^2)) + (a + b*x^2 + c*x^4)^(3/2)/(6*c) + (b*(b^2 - 4*a*c)*ArcTanh[(b + 2*c*x^2)/(2*Sqrt[c]*Sqrt[a + b*x^2 + c*x^4])])/(32*c^(5/2))}
{x^2*Sqrt[a + b*x^2 + c*x^4], x, 5, (x*(b + 3*c*x^2)*Sqrt[a + b*x^2 + c*x^4])/(15*c) - (1/(15*Sqrt[2]*(-c)^(5/2)*Sqrt[a + b*x^2 + c*x^4]))*((b - Sqrt[b^2 - 4*a*c])*Sqrt[b + Sqrt[b^2 - 4*a*c]]*Sqrt[1 + (2*c*x^2)/(b - Sqrt[b^2 - 4*a*c])]*Sqrt[1 + (2*c*x^2)/(b + Sqrt[b^2 - 4*a*c])]*((b^2 - 3*a*c)*EllipticE[ArcSin[(Sqrt[2]*Sqrt[-c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]], (b + Sqrt[b^2 - 4*a*c])/(b - Sqrt[b^2 - 4*a*c])] - (b^2 - 3*a*c - (a*b*c)/(b - Sqrt[b^2 - 4*a*c]))*EllipticF[ArcSin[(Sqrt[2]*Sqrt[-c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]], (b + Sqrt[b^2 - 4*a*c])/(b - Sqrt[b^2 - 4*a*c])]))}
{x*Sqrt[a + b*x^2 + c*x^4], x, 3, ((b + 2*c*x^2)*Sqrt[a + b*x^2 + c*x^4])/(8*c) - ((b^2 - 4*a*c)*ArcTanh[(b + 2*c*x^2)/(2*Sqrt[c]*Sqrt[a + b*x^2 + c*x^4])])/(16*c^(3/2))}
{Sqrt[a + b*x^2 + c*x^4], x, 5, (1/3)*x*Sqrt[a + b*x^2 + c*x^4] - ((b - Sqrt[b^2 - 4*a*c])*Sqrt[b + Sqrt[b^2 - 4*a*c]]*Sqrt[1 + (2*c*x^2)/(b - Sqrt[b^2 - 4*a*c])]*Sqrt[1 + (2*c*x^2)/(b + Sqrt[b^2 - 4*a*c])]*(b*EllipticE[ArcSin[(Sqrt[2]*Sqrt[-c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]], (b + Sqrt[b^2 - 4*a*c])/(b - Sqrt[b^2 - 4*a*c])] - (b - (4*a*c)/(b - Sqrt[b^2 - 4*a*c]))*EllipticF[ArcSin[(Sqrt[2]*Sqrt[-c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]], (b + Sqrt[b^2 - 4*a*c])/(b - Sqrt[b^2 - 4*a*c])]))/(6*Sqrt[2]*(-c)^(3/2)*Sqrt[a + b*x^2 + c*x^4])}
{Sqrt[a + b*x^2 + c*x^4]/x, x, 4, (1/2)*Sqrt[a + b*x^2 + c*x^4] - (1/2)*Sqrt[a]*ArcTanh[(2*a + b*x^2)/(2*Sqrt[a]*Sqrt[a + b*x^2 + c*x^4])] + (b*ArcTanh[(b + 2*c*x^2)/(2*Sqrt[c]*Sqrt[a + b*x^2 + c*x^4])])/(4*Sqrt[c])}
{Sqrt[a + b*x^2 + c*x^4]/x^2, x, 7, -(Sqrt[a + b*x^2 + c*x^4]/x) + ((b - Sqrt[b^2 - 4*a*c])*Sqrt[b + Sqrt[b^2 - 4*a*c]]*Sqrt[1 + (2*c*x^2)/(b - Sqrt[b^2 - 4*a*c])]*Sqrt[1 + (2*c*x^2)/(b + Sqrt[b^2 - 4*a*c])]*(EllipticE[ArcSin[(Sqrt[2]*Sqrt[-c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]], (b + Sqrt[b^2 - 4*a*c])/(b - Sqrt[b^2 - 4*a*c])] - EllipticF[ArcSin[(Sqrt[2]*Sqrt[-c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]], (b + Sqrt[b^2 - 4*a*c])/(b - Sqrt[b^2 - 4*a*c])]))/(Sqrt[2]*Sqrt[-c]*Sqrt[a + b*x^2 + c*x^4]) + (b*Sqrt[b + Sqrt[b^2 - 4*a*c]]*Sqrt[1 + (2*c*x^2)/(b - Sqrt[b^2 - 4*a*c])]*Sqrt[1 + (2*c*x^2)/(b + Sqrt[b^2 - 4*a*c])]*EllipticF[ArcSin[(Sqrt[2]*Sqrt[-c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]], (b + Sqrt[b^2 - 4*a*c])/(b - Sqrt[b^2 - 4*a*c])])/(Sqrt[2]*Sqrt[-c]*Sqrt[a + b*x^2 + c*x^4])}
{Sqrt[a + b*x^2 + c*x^4]/x^3, x, 4, -(Sqrt[a + b*x^2 + c*x^4]/(2*x^2)) - (b*ArcTanh[(2*a + b*x^2)/(2*Sqrt[a]*Sqrt[a + b*x^2 + c*x^4])])/(4*Sqrt[a]) + (1/2)*Sqrt[c]*ArcTanh[(b + 2*c*x^2)/(2*Sqrt[c]*Sqrt[a + b*x^2 + c*x^4])]}
{Sqrt[a + b*x^2 + c*x^4]/x^4, x, 6, (c*x*Sqrt[a + b*x^2 + c*x^4])/(3*a) - (a + b*x^2 + c*x^4)^(3/2)/(3*a*x^3) + ((b - Sqrt[b^2 - 4*a*c])*Sqrt[b + Sqrt[b^2 - 4*a*c]]*Sqrt[1 + (2*c*x^2)/(b - Sqrt[b^2 - 4*a*c])]*Sqrt[1 + (2*c*x^2)/(b + Sqrt[b^2 - 4*a*c])]*(b*EllipticE[ArcSin[(Sqrt[2]*Sqrt[-c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]], (b + Sqrt[b^2 - 4*a*c])/(b - Sqrt[b^2 - 4*a*c])] - (b - (4*a*c)/(b - Sqrt[b^2 - 4*a*c]))*EllipticF[ArcSin[(Sqrt[2]*Sqrt[-c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]], (b + Sqrt[b^2 - 4*a*c])/(b - Sqrt[b^2 - 4*a*c])]))/(6*Sqrt[2]*a*Sqrt[-c]*Sqrt[a + b*x^2 + c*x^4])}

{x^4*Sqrt[b^2/(4*c) + b*x^2 + c*x^4], x, 3, (x^5*(7*b + 10*c*x^2)*Sqrt[b^2/c + 4*b*x^2 + 4*c*x^4])/(70*(b + 2*c*x^2))}
{x^3*Sqrt[b^2/(4*c) + b*x^2 + c*x^4], x, 3, (x^4*(3*b + 4*c*x^2)*Sqrt[b^2/c + 4*b*x^2 + 4*c*x^4])/(24*(b + 2*c*x^2))}
{x^2*Sqrt[b^2/(4*c) + b*x^2 + c*x^4], x, 3, (x^3*(5*b + 6*c*x^2)*Sqrt[b^2/c + 4*b*x^2 + 4*c*x^4])/(30*(b + 2*c*x^2))}
{x*Sqrt[b^2/(4*c) + b*x^2 + c*x^4], x, 2, ((b + 2*c*x^2)*Sqrt[b^2/c + 4*b*x^2 + 4*c*x^4])/(16*c)}
{Sqrt[b^2/(4*c) + b*x^2 + c*x^4], x, 2, (x*(3*b + 2*c*x^2)*Sqrt[b^2/c + 4*b*x^2 + 4*c*x^4])/(6*(b + 2*c*x^2))}
{Sqrt[b^2/(4*c) + b*x^2 + c*x^4]/x, x, 3, (Sqrt[b^2/c + 4*b*x^2 + 4*c*x^4]*(c*x^2 + b*Log[x]))/(2*(b + 2*c*x^2))}
{Sqrt[b^2/(4*c) + b*x^2 + c*x^4]/x^2, x, 3, -(((b/x - 2*c*x)*Sqrt[b^2/c + 4*b*x^2 + 4*c*x^4])/(2*(b + 2*c*x^2)))}
{Sqrt[b^2/(4*c) + b*x^2 + c*x^4]/x^3, x, 3, -((Sqrt[b^2/c + 4*b*x^2 + 4*c*x^4]*(b/x^2 - 4*c*Log[x]))/(4*(b + 2*c*x^2)))}
{Sqrt[b^2/(4*c) + b*x^2 + c*x^4]/x^4, x, 3, (2*c^2*x*(3*b + 2*c*x^2)*Sqrt[b^2/c + 4*b*x^2 + 4*c*x^4])/(3*b^2*(b + 2*c*x^2)) - (c*(b^2/c + 4*b*x^2 + 4*c*x^4)^(3/2))/(6*b^2*x^3)}


(* Integrands of the form x^m/Sqrt[a+b*x^2+c*x^4] where m is an integer *)
{x^4/Sqrt[a + b*x^2 + c*x^4], x, 7, (x*Sqrt[a + b*x^2 + c*x^4])/(3*c) - (b*(b - Sqrt[b^2 - 4*a*c])*Sqrt[b + Sqrt[b^2 - 4*a*c]]*Sqrt[1 + (2*c*x^2)/(b - Sqrt[b^2 - 4*a*c])]*Sqrt[1 + (2*c*x^2)/(b + Sqrt[b^2 - 4*a*c])]*(EllipticE[ArcSin[(Sqrt[2]*Sqrt[-c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]], (b + Sqrt[b^2 - 4*a*c])/(b - Sqrt[b^2 - 4*a*c])] - EllipticF[ArcSin[(Sqrt[2]*Sqrt[-c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]], (b + Sqrt[b^2 - 4*a*c])/(b - Sqrt[b^2 - 4*a*c])]))/(3*Sqrt[2]*(-c)^(5/2)*Sqrt[a + b*x^2 + c*x^4]) + (a*Sqrt[b + Sqrt[b^2 - 4*a*c]]*Sqrt[1 + (2*c*x^2)/(b - Sqrt[b^2 - 4*a*c])]*Sqrt[1 + (2*c*x^2)/(b + Sqrt[b^2 - 4*a*c])]*EllipticF[ArcSin[(Sqrt[2]*Sqrt[-c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]], (b + Sqrt[b^2 - 4*a*c])/(b - Sqrt[b^2 - 4*a*c])])/(3*Sqrt[2]*(-c)^(3/2)*Sqrt[a + b*x^2 + c*x^4])}
{x^3/Sqrt[a + b*x^2 + c*x^4], x, 3, Sqrt[a + b*x^2 + c*x^4]/(2*c) - (b*ArcTanh[(b + 2*c*x^2)/(2*Sqrt[c]*Sqrt[a + b*x^2 + c*x^4])])/(4*c^(3/2))}
{x^2/Sqrt[a + b*x^2 + c*x^4], x, 4, -(((b - Sqrt[b^2 - 4*a*c])*Sqrt[b + Sqrt[b^2 - 4*a*c]]*Sqrt[1 + (2*c*x^2)/(b - Sqrt[b^2 - 4*a*c])]*Sqrt[1 + (2*c*x^2)/(b + Sqrt[b^2 - 4*a*c])]*(EllipticE[ArcSin[(Sqrt[2]*Sqrt[-c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]], (b + Sqrt[b^2 - 4*a*c])/(b - Sqrt[b^2 - 4*a*c])] - EllipticF[ArcSin[(Sqrt[2]*Sqrt[-c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]], (b + Sqrt[b^2 - 4*a*c])/(b - Sqrt[b^2 - 4*a*c])]))/(2*Sqrt[2]*(-c)^(3/2)*Sqrt[a + b*x^2 + c*x^4]))}
{x/Sqrt[a + b*x^2 + c*x^4], x, 2, ArcTanh[(b + 2*c*x^2)/(2*Sqrt[c]*Sqrt[a + b*x^2 + c*x^4])]/(2*Sqrt[c])}
{1/Sqrt[a + b*x^2 + c*x^4], x, 2, (Sqrt[b + Sqrt[b^2 - 4*a*c]]*Sqrt[1 + (2*c*x^2)/(b - Sqrt[b^2 - 4*a*c])]*Sqrt[1 + (2*c*x^2)/(b + Sqrt[b^2 - 4*a*c])]*EllipticF[ArcSin[(Sqrt[2]*Sqrt[-c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]], (b + Sqrt[b^2 - 4*a*c])/(b - Sqrt[b^2 - 4*a*c])])/(Sqrt[2]*Sqrt[-c]*Sqrt[a + b*x^2 + c*x^4])}
{1/(x*Sqrt[a + b*x^2 + c*x^4]), x, 1, -(ArcTanh[(2*a + b*x^2)/(2*Sqrt[a]*Sqrt[a + b*x^2 + c*x^4])]/(2*Sqrt[a]))}
{1/(x^2*Sqrt[a + b*x^2 + c*x^4]), x, 5, -(Sqrt[a + b*x^2 + c*x^4]/(a*x)) + ((b - Sqrt[b^2 - 4*a*c])*Sqrt[b + Sqrt[b^2 - 4*a*c]]*Sqrt[1 + (2*c*x^2)/(b - Sqrt[b^2 - 4*a*c])]*Sqrt[1 + (2*c*x^2)/(b + Sqrt[b^2 - 4*a*c])]*(EllipticE[ArcSin[(Sqrt[2]*Sqrt[-c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]], (b + Sqrt[b^2 - 4*a*c])/(b - Sqrt[b^2 - 4*a*c])] - EllipticF[ArcSin[(Sqrt[2]*Sqrt[-c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]], (b + Sqrt[b^2 - 4*a*c])/(b - Sqrt[b^2 - 4*a*c])]))/(2*Sqrt[2]*a*Sqrt[-c]*Sqrt[a + b*x^2 + c*x^4])}
{1/(x^3*Sqrt[a + b*x^2 + c*x^4]), x, 2, -(Sqrt[a + b*x^2 + c*x^4]/(2*a*x^2)) + (b*ArcTanh[(2*a + b*x^2)/(2*Sqrt[a]*Sqrt[a + b*x^2 + c*x^4])])/(4*a^(3/2))}
{1/(x^4*Sqrt[a + b*x^2 + c*x^4]), x, 8, -(Sqrt[a + b*x^2 + c*x^4]/(3*a*x^3)) + (2*b*Sqrt[a + b*x^2 + c*x^4])/(3*a^2*x) - (b*(b - Sqrt[b^2 - 4*a*c])*Sqrt[b + Sqrt[b^2 - 4*a*c]]*Sqrt[1 + (2*c*x^2)/(b - Sqrt[b^2 - 4*a*c])]*Sqrt[1 + (2*c*x^2)/(b + Sqrt[b^2 - 4*a*c])]*(EllipticE[ArcSin[(Sqrt[2]*Sqrt[-c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]], (b + Sqrt[b^2 - 4*a*c])/(b - Sqrt[b^2 - 4*a*c])] - EllipticF[ArcSin[(Sqrt[2]*Sqrt[-c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]], (b + Sqrt[b^2 - 4*a*c])/(b - Sqrt[b^2 - 4*a*c])]))/(3*Sqrt[2]*a^2*Sqrt[-c]*Sqrt[a + b*x^2 + c*x^4]) + (Sqrt[-c]*Sqrt[b + Sqrt[b^2 - 4*a*c]]*Sqrt[1 + (2*c*x^2)/(b - Sqrt[b^2 - 4*a*c])]*Sqrt[1 + (2*c*x^2)/(b + Sqrt[b^2 - 4*a*c])]*EllipticF[ArcSin[(Sqrt[2]*Sqrt[-c]*x)/Sqrt[b + Sqrt[b^2 - 4*a*c]]], (b + Sqrt[b^2 - 4*a*c])/(b - Sqrt[b^2 - 4*a*c])])/(3*Sqrt[2]*a*Sqrt[a + b*x^2 + c*x^4])}

{x^4/Sqrt[b^2/(4*c) + b*x^2 + c*x^4], x, 5, -(((b + 2*c*x^2)*(6*b*Sqrt[c]*x - 4*c^(3/2)*x^3 - 3*Sqrt[2]*b^(3/2)*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b]]))/(12*c^(5/2)*Sqrt[b^2/c + 4*b*x^2 + 4*c*x^4]))}
{x^3/Sqrt[b^2/(4*c) + b*x^2 + c*x^4], x, 5, ((b + 2*c*x^2)*(2*c*x^2 - b*Log[b + 2*c*x^2]))/(4*c^2*Sqrt[b^2/c + 4*b*x^2 + 4*c*x^4])}
{x^2/Sqrt[b^2/(4*c) + b*x^2 + c*x^4], x, 4, (x*(b + 2*c*x^2))/(c*Sqrt[b^2/c + 4*b*x^2 + 4*c*x^4]) - (Sqrt[b]*(b + 2*c*x^2)*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b]])/(Sqrt[2]*c^(3/2)*Sqrt[b^2/c + 4*b*x^2 + 4*c*x^4])}
{x/Sqrt[b^2/(4*c) + b*x^2 + c*x^4], x, 3, ((b + 2*c*x^2)*Log[b + 2*c*x^2])/(2*c*Sqrt[b^2/c + 4*b*x^2 + 4*c*x^4])}
{1/Sqrt[b^2/(4*c) + b*x^2 + c*x^4], x, 2, (Sqrt[2]*(b + 2*c*x^2)*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b]])/(Sqrt[b]*Sqrt[c]*Sqrt[b^2/c + 4*b*x^2 + 4*c*x^4])}
{1/(x*Sqrt[b^2/(4*c) + b*x^2 + c*x^4]), x, 2, ((b + 2*c*x^2)*(2*Log[x] - Log[b + 2*c*x^2]))/(b*Sqrt[b^2/c + 4*b*x^2 + 4*c*x^4])}
{1/(x^2*Sqrt[b^2/(4*c) + b*x^2 + c*x^4]), x, 5, (4*c*x*(b + 2*c*x^2))/(b^2*Sqrt[b^2/c + 4*b*x^2 + 4*c*x^4]) - (2*c*Sqrt[b^2/c + 4*b*x^2 + 4*c*x^4])/(b^2*x) - (2*Sqrt[2]*Sqrt[c]*(b + 2*c*x^2)*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b]])/(b^(3/2)*Sqrt[b^2/c + 4*b*x^2 + 4*c*x^4])}
{1/(x^3*Sqrt[b^2/(4*c) + b*x^2 + c*x^4]), x, 3, -((c*Sqrt[b^2/c + 4*b*x^2 + 4*c*x^4])/(b^2*x^2)) - (2*c*(b + 2*c*x^2)*(2*Log[x] - Log[b + 2*c*x^2]))/(b^2*Sqrt[b^2/c + 4*b*x^2 + 4*c*x^4])}
{1/(x^4*Sqrt[b^2/(4*c) + b*x^2 + c*x^4]), x, 5, -((2*(b + 2*c*x^2)*(b^(3/2)/x^3 - (6*Sqrt[b]*c)/x - 6*Sqrt[2]*c^(3/2)*ArcTan[(Sqrt[2]*Sqrt[c]*x)/Sqrt[b]]))/(3*b^(5/2)*Sqrt[b^2/c + 4*b*x^2 + 4*c*x^4]))}


(* ::Subsection::Closed:: *)
(*Integrands involving roots of polynomials*)


{Sqrt[x^4*(a + b*x^3)], x, 1, (2*(x^4*(a + b*x^3))^(3/2))/(9*b*x^6)}
{x*Sqrt[x^2*(a + b*x^3)], x, 1, (2*(x^2*(a + b*x^3))^(3/2))/(9*b*x^3)}
{x*Sqrt[a*x^2 + b*x^5], x, 2, (2*(x^2*(a + b*x^3))^(3/2))/(9*b*x^3)}


(* Integrands having factors whose derivative is zero *)
{Sqrt[b - a/x^2]/Sqrt[a - b*x^2], x, 2, (Sqrt[b - a/x^2]*x*Log[x])/Sqrt[a - b*x^2]}
{x*Sqrt[b - a/x^2]/Sqrt[a - b*x^2], x, 2, (Sqrt[b - a/x^2]*x^2)/Sqrt[a - b*x^2]}
{Sqrt[b - a/x^2]/(x*Sqrt[a - b*x^2]), x, 2, -(Sqrt[b - a/x^2]/Sqrt[a - b*x^2])}


{1/(Sqrt[a + b/x^2]*Sqrt[c + d*x^2]), x, 3, (Sqrt[b + a*x^2]*ArcTanh[(Sqrt[d]*Sqrt[b + a*x^2])/(Sqrt[a]*Sqrt[c + d*x^2])])/(Sqrt[a]*Sqrt[d]*Sqrt[a + b/x^2]*x)}


{(3 - x^2)/Sqrt[3 - 2*x^2 - x^4], x, 4, (-Sqrt[3])*EllipticE[ArcSin[x], -(1/3)] + 2*Sqrt[3]*EllipticF[ArcSin[x], -(1/3)]}
{1/Sqrt[3 - 2*x^2 - x^4], x, 2, (Sqrt[1 - x^2]*Sqrt[3 + x^2]*EllipticF[ArcSin[x], -(1/3)])/(Sqrt[3]*Sqrt[3 - 2*x^2 - x^4])}
{1/Sqrt[(1 - x^2)*(x^2 + 3)], x, 3, (Sqrt[1 - x^2]*Sqrt[3 + x^2]*EllipticF[ArcSin[x], -(1/3)])/(Sqrt[3]*Sqrt[3 - 2*x^2 - x^4])}
{1/Sqrt[8*x - 8*x^2 + 4*x^3 - x^4], x, 3, -((Sqrt[3 + (1 - x)^2]*Sqrt[(2 - x)*x]*EllipticF[ArcSin[1 - x], -(1/3)])/(Sqrt[3]*Sqrt[3 - 2*(1 - x)^2 - (1 - x)^4]))}
{1/Sqrt[(2 - x)*x*(4 - 2*x + x^2)], x, 4, -((Sqrt[3 + (1 - x)^2]*Sqrt[(2 - x)*x]*EllipticF[ArcSin[1 - x], -(1/3)])/(Sqrt[3]*Sqrt[3 - 2*(1 - x)^2 - (1 - x)^4]))}


{Sqrt[3 - 2*x^2 - x^4], x, 5, (1/3)*x*Sqrt[3 - 2*x^2 - x^4] - (2*EllipticE[ArcSin[x], -(1/3)])/Sqrt[3] + (4*EllipticF[ArcSin[x], -(1/3)])/Sqrt[3]}
{Sqrt[(1 - x^2)*(x^2 + 3)], x, 6, (1/3)*x*Sqrt[3 - 2*x^2 - x^4] - (2*EllipticE[ArcSin[x], -(1/3)])/Sqrt[3] + (4*EllipticF[ArcSin[x], -(1/3)])/Sqrt[3]}
{Sqrt[8*x - 8*x^2 + 4*x^3 - x^4], x, 6, (-(1/3))*Sqrt[3 - 2*(1 - x)^2 - (1 - x)^4]*(1 - x) + (2*EllipticE[ArcSin[1 - x], -(1/3)])/Sqrt[3] - (4*EllipticF[ArcSin[1 - x], -(1/3)])/Sqrt[3]}
{Sqrt[(2 - x)*x*(4 - 2*x + x^2)], x, 7, (-(1/3))*Sqrt[3 - 2*(1 - x)^2 - (1 - x)^4]*(1 - x) + (2*EllipticE[ArcSin[1 - x], -(1/3)])/Sqrt[3] - (4*EllipticF[ArcSin[1 - x], -(1/3)])/Sqrt[3]}


{1/Sqrt[9 - 6*x - 44*x^2 + 15*x^3 + 3*x^4], x, 6, -((Sqrt[(1/613)*(91 - 6*Sqrt[213])]*Sqrt[15 - Sqrt[213] + (2*(-3 + x))/x^2]*Sqrt[15 + Sqrt[213] + (2*(-3 + x))/x^2]*x^2*EllipticF[ArcSin[(6*(-(1/6) + 1/x))/Sqrt[91 - 6*Sqrt[213]]], (-6552 + 432*Sqrt[213])/(-6552 - 432*Sqrt[213])])/Sqrt[9 - 6*x - 44*x^2 + 15*x^3 + 3*x^4]), (2*Sqrt[91 - 6*Sqrt[213]]*Sqrt[613 - (91 - 6*Sqrt[213])*(1 - 6/x)^2]*Sqrt[613 - (91 + 6*Sqrt[213])*(1 - 6/x)^2]*x^2*EllipticF[ArcSin[(1 - 6/x)/Sqrt[91 - 6*Sqrt[213]]], 15949/613 - (1092*Sqrt[213])/613])/(613*Sqrt[(613 - 182*(1 - 6/x)^2 + (1 - 6/x)^4)*x^4])}
{Sqrt[9 - 6*x - 44*x^2 + 15*x^3 + 3*x^4], x, -3, -((Sqrt[(1/613)*(91 - 6*Sqrt[213])]*Sqrt[15 - Sqrt[213] + (2*(-3 + x))/x^2]*Sqrt[15 + Sqrt[213] + (2*(-3 + x))/x^2]*x^2*EllipticF[ArcSin[(6*(-(1/6) + 1/x))/Sqrt[91 - 6*Sqrt[213]]], (-6552 + 432*Sqrt[213])/(-6552 - 432*Sqrt[213])])/Sqrt[9 - 6*x - 44*x^2 + 15*x^3 + 3*x^4])}


(* Contributed by Manuel Bronstein, 24 November 2000 *)
{x/Sqrt[x^4 + 10*x^2 - 96*x - 71], x, -1, -Log[(x^6 + 15*x^4 - 80*x^3 + 27*x^2 - 528*x + 781)*Sqrt[x^4 + 10*x^2 - 96*x - 71] - x^8 - 20*x^6 + 128*x^5 - 54*x^4 + 1408*x^3 - 3124*x^2 - 10001]/8}


(* ::Subsection::Closed:: *)
(*Problems from Calculus textbooks*)


(* ::Subsubsection::Closed:: *)
(*Anton Calculus, 4th Edition*)


{(Sqrt[x] + x^(3/2))^(-1), x, 2, 2*ArcTan[Sqrt[x]]}
{x/Sqrt[5 + 4*x - x^2], x, 2, -Sqrt[5 + 4*x - x^2] - 2*ArcSin[(2 - x)/3]}
{1/(x*Sqrt[-1 + 2*x]), x, 1, 2*ArcTan[Sqrt[-1 + 2*x]]}
{1/(x*Sqrt[x - 5*x^2]), x, 1, (-2*Sqrt[x - 5*x^2])/x}
{1/Sqrt[x], x, 1, 2*Sqrt[x]}
{(-2 + x)/Sqrt[4*x - x^2], x, 1, -Sqrt[4*x - x^2]}
{(-2 + x)^3/Sqrt[4*x - x^2], x, 2, (-(8/3))*Sqrt[4*x - x^2] - (1/3)*(2 - x)^2*Sqrt[4*x - x^2]}

{x^(2/3)/(1 + x^(1/3)), x, 5, -3*x^(1/3) + (3*x^(2/3))/2 - x + (3*x^(4/3))/4 + 3*Log[1 + x^(1/3)]}


(* ::Subsubsection::Closed:: *)
(*Apostol Calculus, Volume 1, 2nd Edition, Section 6.25*)


{1/Sqrt[1 - x^2], x, 1, ArcSin[x]}
{x/(4 - x^2 + Sqrt[4 - x^2]), x, 3, -Log[1 + Sqrt[4 - x^2]]}
{Sqrt[3 - x^2], x, 2, (1/2)*x*Sqrt[3 - x^2] + (3/2)*ArcSin[x/Sqrt[3]]}
{x/Sqrt[3 - x^2], x, 2, -Sqrt[3 - x^2]}
{Sqrt[3 - x^2]/x, x, 2, Sqrt[3 - x^2] - Sqrt[3]*ArcTanh[Sqrt[3 - x^2]/Sqrt[3]]}
{Sqrt[5 + x^2], x, 2, (1/2)*x*Sqrt[5 + x^2] + (5/2)*ArcSinh[x/Sqrt[5]]}
{x/Sqrt[1 + x + x^2], x, 2, Sqrt[1 + x + x^2] - ArcSinh[(1 + 2*x)/Sqrt[3]]/2}
{Sqrt[x + x^2]/x, x, 2, Sqrt[x + x^2] + ArcTanh[x/Sqrt[x + x^2]]}
{1/Sqrt[x + x^2], x, 1, 2*ArcTanh[x/Sqrt[x + x^2]]}
{Sqrt[2 - x - x^2]/x^2, x, 3, -(Sqrt[2 - x - x^2]/x) + ArcSin[(1/3)*(-1 - 2*x)] + ArcTanh[(4 - x)/(2*Sqrt[2]*Sqrt[2 - x - x^2])]/(2*Sqrt[2])}

{1/Sqrt[a^2 - x^2], x, 1, ArcTan[x/Sqrt[a^2 - x^2]]}
{1/Sqrt[1 - 2*x - x^2], x, 1, ArcSin[(1 + x)/Sqrt[2]]}
{Sqrt[1 - x^2], x, 2, (1/2)*x*Sqrt[1 - x^2] + ArcSin[x]/2}

{1/Sqrt[(b - x)*(-a + x)], x, 2, -ArcTan[(a + b - 2*x)/(2*Sqrt[(-a)*b + (a + b)*x - x^2])]}
{Sqrt[(b - x)*(-a + x)], x, 3, (-(1/4))*(a + b - 2*x)*Sqrt[(-a)*b + (a + b)*x - x^2] + (1/8)*(4*a*b - (a + b)^2)*ArcTan[(a + b - 2*x)/(2*Sqrt[(-a)*b + (a + b)*x - x^2])]}


(* ::Subsubsection::Closed:: *)
(*Ayres Calculus, 1964 edition*)


{(2 + x)/Sqrt[4*x - x^2], x, 2, -Sqrt[4*x - x^2] - 4*ArcSin[(2 - x)/2]}
{1/((1 - Sqrt[x])*Sqrt[x]), x, 2, -2*Log[1 - Sqrt[x]]}
{Sqrt[4*x - x^2]/x^3, x, 1, -((4*x - x^2)^(3/2)/(6*x^3))}
{Sqrt[x - x^2]/x^4, x, 2, -((2*(x - x^2)^(3/2))/(5*x^4)) - (4*(x - x^2)^(3/2))/(15*x^3)}

{(3 + x)/(6*x + x^2)^(1/3), x, 1, (3/4)*(6*x + x^2)^(2/3)}
{1/((1 + x)^(1/4) + Sqrt[1 + x]), x, 5, -4*(1 + x)^(1/4) + 2*Sqrt[1 + x] + 4*Log[1 + (1 + x)^(1/4)]}


(* ::Subsubsection::Closed:: *)
(*Edwards and Penney Calculus*)


{(1 + 2*x)/Sqrt[x + x^2], x, 1, 2*Sqrt[x + x^2]}
{1/(2*Sqrt[x]*(1 + x)), x, 2, ArcTan[Sqrt[x]]}
{1/(x*Sqrt[6*x - x^2]), x, 1, -(Sqrt[6*x - x^2]/(3*x))}
{x*Sqrt[(1 - x^2)/(1 + x^2)], x, 4, (1/2)*Sqrt[(1 - x^2)/(1 + x^2)]*(1 + x^2) - ArcTan[Sqrt[(1 - x^2)/(1 + x^2)]]}

{(-1 + x^3)/(-4*x + x^4)^(2/3), x, 2, (3/4)*(-4*x + x^4)^(1/3)}
{(2 - x^2)*(6*x - x^3)^(1/4), x, 2, (4/15)*(6*x - x^3)^(5/4)}
{1/((1 + x^(2/3))*x^(1/3)), x, 2, (3*Log[1 + x^(2/3)])/2}
{Sqrt[-1 + x^(2/3)]/x^(1/3), x, 2, (-1 + x^(2/3))^(3/2)}
{(4 + x)/(6*x - x^2)^(3/2), x, 2, -(4/(3*Sqrt[6*x - x^2])) + (7*x)/(9*Sqrt[6*x - x^2])}
{(x - x^2)^(3/2), x, 3, (-(3/64))*(1 - 2*x)*Sqrt[x - x^2] - (1/8)*(1 - 2*x)*(x - x^2)^(3/2) - (3/128)*ArcSin[1 - 2*x]}
{x^(1/3)/(1 + Sqrt[x]), x, 8, -3*x^(1/3) + (6*x^(5/6))/5 - 2*Sqrt[3]*ArcTan[(1 - 2*x^(1/6))/Sqrt[3]] - 2*Log[1 + x^(1/6)] + Log[1 - x^(1/6) + x^(1/3)]}
{(1 + x^(2/3))^(-1), x, 4, 3*x^(1/3) - 3*ArcTan[x^(1/3)]}
{x^(1/3)/(x^(1/4) + Sqrt[x]), x, 9, -12*x^(1/12) + 3*x^(1/3) - (12*x^(7/12))/7 + (6*x^(5/6))/5 - 4*Sqrt[3]*ArcTan[(1 - 2*x^(1/12))/Sqrt[3]] + 4*Log[1 + x^(1/12)] - 2*Log[1 - x^(1/12) + x^(1/6)]}
{(1 + x^(2/3))^(3/2)/x^(1/3), x, 2, (3*(1 + x^(2/3))^(5/2))/5}
{1/((1 + x^(1/3))*x^(3/2)), x, 5, -(2/Sqrt[x]) + 6/x^(1/6) + 6*ArcTan[x^(1/6)]}
{1/((1 + x^(2/3))*x^(2/3)), x, 2, 3*ArcTan[x^(1/3)]}


(* ::Subsubsection::Closed:: *)
(*Grossman Calculus*)


{(1 + x^4)*Sqrt[5*x + x^5], x, 2, (2/15)*(5*x + x^5)^(3/2)}
{(x + 3*x^2)/Sqrt[x^2 + 2*x^3], x, 2, Sqrt[x^2 + 2*x^3]}
{1/(x*Sqrt[4*x - x^2]), x, 1, -(Sqrt[4*x - x^2]/(2*x))}
{x^(7/3)*(a^(10/3) - x^(10/3))^(19/7), x, 2, (-21*(a^(10/3) - x^(10/3))^(26/7))/260}
{1/(1 + x^(1/5)), x, 5, -5*x^(1/5) + (5*x^(2/5))/2 - (5*x^(3/5))/3 + (5*x^(4/5))/4 + 5*Log[1 + x^(1/5)]}
{(-4 + x)/((1 + x^(1/3))*Sqrt[x]), x, 5, -30*x^(1/6) + 2*Sqrt[x] - (6*x^(5/6))/5 + (6*x^(7/6))/7 + 30*ArcTan[x^(1/6)]}
{Sqrt[x]/(x^(1/4) + x^(1/3)), x, 6, -12*x^(1/12) + 6*x^(1/6) - 4*x^(1/4) + 3*x^(1/3) - (12*x^(5/12))/5 + 2*Sqrt[x] - (12*x^(7/12))/7 + (3*x^(2/3))/2 - (4*x^(3/4))/3 + (6*x^(5/6))/5 - (12*x^(11/12))/11 + x - (12*x^(13/12))/13 + (6*x^(7/6))/7 + 12*Log[1 + x^(1/12)]}
{Sqrt[x]/(1 + x^(2/3)), x, 9, -6*x^(1/6) + (6*x^(5/6))/5 - (3*ArcTan[1 - Sqrt[2]*x^(1/6)])/Sqrt[2] + (3*ArcTan[1 + Sqrt[2]*x^(1/6)])/Sqrt[2] - (3*Log[1 - Sqrt[2]*x^(1/6) + x^(1/3)])/(2*Sqrt[2]) + (3*Log[1 + Sqrt[2]*x^(1/6) + x^(1/3)])/(2*Sqrt[2])}
{(1 + Sqrt[x])/(x^(5/6) + x^(7/6)), x, 7, 3*x^(1/3) + 6*ArcTan[x^(1/6)] - 3*Log[1 + x^(1/3)]}
{(1 + Sqrt[x])/((1 + x^(1/3))*Sqrt[x]), x, 7, 6*x^(1/6) - 3*x^(1/3) + (3*x^(2/3))/2 - 6*ArcTan[x^(1/6)] + 3*Log[1 + x^(1/3)]}
{(1 + x^(1/3))^(-1), x, 5, -3*x^(1/3) + (3*x^(2/3))/2 + 3*Log[1 + x^(1/3)]}


(* ::Subsubsection::Closed:: *)
(*Hardy Pure Mathematics*)


{1/(x*Sqrt[1 + 2*x + 3*x^2]), x, 1, -ArcTanh[(1 + x)/Sqrt[1 + 2*x + 3*x^2]]}
{(1 + x)/((4 + x^2)*Sqrt[9 + x^2]), x, 5, ArcTan[(Sqrt[5]*x)/(2*Sqrt[9 + x^2])]/(2*Sqrt[5]) - ArcTanh[Sqrt[9 + x^2]/Sqrt[5]]/Sqrt[5]}
{1/(Sqrt[-7 + 2*x + 5*x^2]*(8 + 12*x + 5*x^2)), x, 3, (-(1/20) + I/10)*ArcTan[((1/50 + I/100)*((-164 - 8*I) - (100 + 40*I)*x))/Sqrt[-7 + 2*x + 5*x^2]] - (1/10 - I/20)*ArcTanh[((1/100 + I/50)*((-164 + 8*I) - (100 - 40*I)*x))/Sqrt[-7 + 2*x + 5*x^2]]}


(* ::Subsubsection::Closed:: *)
(*Spivak Calculus*)


{(x^(1/6) + (x^3)^(1/5))/Sqrt[x], x, 5, (3*x^(2/3))/2 + (10*Sqrt[x]*(x^3)^(1/5))/11}


(* ::Subsubsection::Closed:: *)
(*Stewart Calculus*)


{Sqrt[x]/(x + x^2), x, 2, 2*ArcTan[Sqrt[x]]}
{(1 + Sqrt[x])*Sqrt[x], x, 2, (2*x^(3/2))/3 + x^2/2}
{(1 - Sqrt[x])/x^(1/3), x, 2, (3*x^(2/3))/2 - (6*x^(7/6))/7}
{(4 + x + Sqrt[1 + x])^(-1), x, 3, (-2*ArcTan[(1 + 2*Sqrt[1 + x])/Sqrt[11]])/Sqrt[11] + Log[4 + x + Sqrt[1 + x]]}
{Sqrt[x]/(1 + x^(1/3)), x, 5, -6*x^(1/6) + 2*Sqrt[x] - (6*x^(5/6))/5 + (6*x^(7/6))/7 + 6*ArcTan[x^(1/6)]}
{1/(-x^(-1/3) + Sqrt[x]), x, 13, 2*Sqrt[x] + (3/5)*Sqrt[10 - 2*Sqrt[5]]*ArcTan[(1 - Sqrt[5] + 4*x^(1/6))/Sqrt[10 + 2*Sqrt[5]]] - (3/5)*Sqrt[10 + 2*Sqrt[5]]*ArcTan[(1 + Sqrt[5] + 4*x^(1/6))/Sqrt[10 - 2*Sqrt[5]]] + (6/5)*Log[1 - x^(1/6)] - (3/10)*(1 + Sqrt[5])*Log[2 + (1 - Sqrt[5])*x^(1/6) + 2*x^(1/3)] - (3/10)*(1 - Sqrt[5])*Log[2 + (1 + Sqrt[5])*x^(1/6) + 2*x^(1/3)]}
{Sqrt[x]/(-x^(-1/3) + Sqrt[x]), x, 13, 6*x^(1/6) + x - (3/5)*Sqrt[10 + 2*Sqrt[5]]*ArcTan[(1 - Sqrt[5] + 4*x^(1/6))/Sqrt[10 + 2*Sqrt[5]]] - (3/5)*Sqrt[10 - 2*Sqrt[5]]*ArcTan[(1 + Sqrt[5] + 4*x^(1/6))/Sqrt[10 - 2*Sqrt[5]]] + (6/5)*Log[1 - x^(1/6)] - (3/10)*(1 - Sqrt[5])*Log[2 + (1 - Sqrt[5])*x^(1/6) + 2*x^(1/3)] - (3/10)*(1 + Sqrt[5])*Log[2 + (1 + Sqrt[5])*x^(1/6) + 2*x^(1/3)]}
{(x^(-1/4) + Sqrt[x])^(-1), x, 8, 2*Sqrt[x] + (4*ArcTan[(1 - 2*x^(1/4))/Sqrt[3]])/Sqrt[3] + (4/3)*Log[1 + x^(1/4)] - (2/3)*Log[1 - x^(1/4) + Sqrt[x]]}
{(x^(-1/3) + x^(-1/4))^(-1), x, 5, 12*x^(1/12) - 6*x^(1/6) + 4*x^(1/4) - 3*x^(1/3) + (12*x^(5/12))/5 - 2*Sqrt[x] + (12*x^(7/12))/7 - (3*x^(2/3))/2 + (4*x^(3/4))/3 - (6*x^(5/6))/5 + (12*x^(11/12))/11 - x + (12*x^(13/12))/13 - (6*x^(7/6))/7 + (4*x^(5/4))/5 - 12*Log[1 + x^(1/12)]}
{(1 + Sqrt[x])^(1/3)/x, x, 7, 6*(1 + Sqrt[x])^(1/3) - 2*Sqrt[3]*ArcTan[(1 + 2*(1 + Sqrt[x])^(1/3))/Sqrt[3]] + 2*Log[1 - (1 + Sqrt[x])^(1/3)] - Log[1 + (1 + Sqrt[x])^(1/3) + (1 + Sqrt[x])^(2/3)]}
{x/(x^2 - (x^2)^(1/3)), x, 3, (3/4)*Log[1 - (x^2)^(2/3)]}


(* ::Subsubsection::Closed:: *)
(*Thomas Calculus, 8th Edition*)


{(2 + 5*x^4)*Sqrt[2*x + x^5], x, 2, (2/3)*(2*x + x^5)^(3/2)}
{6/(Sqrt[x]*(1 + x)), x, 2, 12*ArcTan[Sqrt[x]]}
{1/((1 + x)*Sqrt[2*x + x^2]), x, 1, ArcTan[Sqrt[2*x + x^2]]}
{1/((1 + 2*x)*Sqrt[x + x^2]), x, 1, ArcTan[2*Sqrt[x + x^2]]}
{(2*Sqrt[-1 + x] + x)/(2*Sqrt[-1 + x]*x), x, 6, Sqrt[-1 + x] + Log[x]}
{2/(Sqrt[x] + 4*x^(3/2)), x, 3, 2*ArcTan[2*Sqrt[x]]}
{(-1 + x)/Sqrt[2*x - x^2], x, 1, -Sqrt[2*x - x^2]}
{1/Sqrt[(a^2 + x^2)^3], x, 2, (x*(a^2 + x^2))/(a^2*Sqrt[(a^2 + x^2)^3])}
{x/(1 + Sqrt[x]), x, 5, 2*Sqrt[x] - x + (2*x^(3/2))/3 - 2*Log[1 + Sqrt[x]]}
{x/(1 + Sqrt[x] + x), x, 5, -2*Sqrt[x] + x + (4*ArcTan[(1 + 2*Sqrt[x])/Sqrt[3]])/Sqrt[3]}

{x^(2/3)*(1 + x^(5/3))^(2/3), x, 2, (9*(1 + x^(5/3))^(5/3))/25}
{1/(Sqrt[1 + x^(4/5)]*x^(1/5)), x, 2, (5*Sqrt[1 + x^(4/5)])/2}


(* ::Subsection::Closed:: *)
(*Miscellaneous problems*)


(* Algebraic functions with symbolic exponents *)
{(x^m*(a + b*x^(m*p + 1)))^p, x, 1, (x^m*(a + b*x^(1 + m*p)))^(1 + p)/(x^((1 + p)*m)*(b*(1 + p)*(1 + m*p)))}
{(a*x^m + b*x^(m*p + m + 1))^p, x, 2, (x^m*(a + b*x^(1 + m*p)))^(1 + p)/(x^((1 + p)*m)*(b*(1 + p)*(1 + m*p)))}

{x^n*(x^m*(a + b*x^(m*p + n + 1)))^p, x, 1, (x^m*(a + b*x^(1 + n + m*p)))^(1 + p)/(x^(m*(1 + p))*(b*(1 + p)*(1 + n + m*p)))}
{x^n*(a*x^m + b*x^(m*p + m + n + 1))^p, x, 2, (x^m*(a + b*x^(1 + n + m*p)))^(1 + p)/(x^(m*(1 + p))*(b*(1 + p)*(1 + n + m*p)))}


{1/Sqrt[2 + Sqrt[1 + Sqrt[x]]], x, 5, -48*Sqrt[2 + Sqrt[1 + Sqrt[x]]] + (88/3)*(2 + Sqrt[1 + Sqrt[x]])^(3/2) - (48/5)*(2 + Sqrt[1 + Sqrt[x]])^(5/2) + (8/7)*(2 + Sqrt[1 + Sqrt[x]])^(7/2)}
{Sqrt[x]/(-1 + x), x, 2, 2*Sqrt[x] - 2*ArcTanh[Sqrt[x]]}
{(9 + 6*Sqrt[x] + x)/(4*Sqrt[x] + x), x, 5, 4*Sqrt[x] + x + 2*Log[4 + Sqrt[x]]}

{3/(4 + x^(1/3)), x, 6, -36*x^(1/3) + (9*x^(2/3))/2 + 144*Log[4 + x^(1/3)]}
{(1 + Sqrt[-3 + x])^(1/3), x, 3, (-(9/14))*(1 + Sqrt[-3 + x])^(4/3) + (6/7)*(1 + Sqrt[-3 + x])^(4/3)*Sqrt[-3 + x]}
{(5 + x^(1/4))/(-6 + x), x, 8, 4*x^(1/4) - 2*6^(1/4)*ArcTan[x^(1/4)/6^(1/4)] - 2*6^(1/4)*ArcTanh[x^(1/4)/6^(1/4)] + 5*Log[6 - x]}


{Sqrt[1 + Sqrt[x] + x], x, 4, (-(1/4))*(1 + 2*Sqrt[x])*Sqrt[1 + Sqrt[x] + x] + (2/3)*(1 + Sqrt[x] + x)^(3/2) - (3/8)*ArcSinh[(1 + 2*Sqrt[x])/Sqrt[3]]}
{1/Sqrt[1 + Sqrt[x]], x, 3, (-8/3)*Sqrt[1 + Sqrt[x]] + (4/3)*Sqrt[1 + Sqrt[x]]*Sqrt[x]}
{Sqrt[1 + Sqrt[x]]*Sqrt[x], x, 4, (32/105)*(1 + Sqrt[x])^(3/2) - (16/35)*(1 + Sqrt[x])^(3/2)*Sqrt[x] + (4/7)*(1 + Sqrt[x])^(3/2)*x}
{Sqrt[1 + Sqrt[x]]*x, x, 5, (-64/315)*(1 + Sqrt[x])^(3/2) + (32/105)*(1 + Sqrt[x])^(3/2)*Sqrt[x] - (8/21)*(1 + Sqrt[x])^(3/2)*x + (4/9)*(1 + Sqrt[x])^(3/2)*x^(3/2)}
{Sqrt[x]/(1 + x)^2, x, 2, -(Sqrt[x]/(1 + x)) + ArcTan[Sqrt[x]]}
{((2 - 3*x)^3*Sqrt[x])/(1 + x)^2, x, 7, -450*Sqrt[x] + 72*x^(3/2) - (54*x^(5/2))/5 - (125*Sqrt[x])/(1 + x) + 575*ArcTan[Sqrt[x]]}
{Sqrt[1 + x + Sqrt[1 + x]], x, 4, (2/3)*(1 + x + Sqrt[1 + x])^(3/2) - (1/4)*Sqrt[1 + x + Sqrt[1 + x]]*(1 + 2*Sqrt[1 + x]) + (1/4)*ArcTanh[Sqrt[1 + x]/Sqrt[1 + x + Sqrt[1 + x]]]}
{Sqrt[2*x + Sqrt[-1 + 2*x]], x, 4, (1/3)*(2*x + Sqrt[-1 + 2*x])^(3/2) - (1/8)*Sqrt[2*x + Sqrt[-1 + 2*x]]*(1 + 2*Sqrt[-1 + 2*x]) - (3/16)*ArcSinh[(1 + 2*Sqrt[-1 + 2*x])/Sqrt[3]]}
{Sqrt[Sqrt[-1 + x] + x], x, 4, (-(1/4))*(1 + 2*Sqrt[-1 + x])*Sqrt[Sqrt[-1 + x] + x] + (2/3)*(Sqrt[-1 + x] + x)^(3/2) - (3/8)*ArcSinh[(1 + 2*Sqrt[-1 + x])/Sqrt[3]]}
{1/Sqrt[3 + Sqrt[-1 + 2*x]], x, 3, -4*Sqrt[3 + Sqrt[-1 + 2*x]] + (2/3)*Sqrt[-1 + 2*x]*Sqrt[3 + Sqrt[-1 + 2*x]]}
{1/Sqrt[x + Sqrt[1 + x]], x, 3, 2*Sqrt[x + Sqrt[1 + x]] - ArcTanh[(1 + 2*Sqrt[1 + x])/(2*Sqrt[x + Sqrt[1 + x]])]}
{1/Sqrt[1 + x + Sqrt[-1 + 2*x]], x, 3, 2*Sqrt[1 + x + Sqrt[-1 + 2*x]] - Sqrt[2]*ArcSinh[(1 + Sqrt[-1 + 2*x])/Sqrt[2]]}
{Sqrt[x - x^2]/(1 + x), x, 3, Sqrt[x - x^2] - (3/2)*ArcSin[1 - 2*x] + Sqrt[2]*ArcTan[(1 - 3*x)/(2*Sqrt[2]*Sqrt[x - x^2])]}
{Sqrt[3*x + Sqrt[-7 + 8*x]], x, 4, (2/9)*(3*x + Sqrt[-7 + 8*x])^(3/2) - (1/18)*Sqrt[3*x + Sqrt[-7 + 8*x]]*(4 + 3*Sqrt[-7 + 8*x]) - (47*ArcSinh[(4 + 3*Sqrt[-7 + 8*x])/Sqrt[47]])/(36*Sqrt[6])}
{Sqrt[x]*Sqrt[Sqrt[x] + x], x, 5, (5/32)*(1 + 2*Sqrt[x])*Sqrt[Sqrt[x] + x] - (5/12)*(Sqrt[x] + x)^(3/2) + (1/2)*Sqrt[x]*(Sqrt[x] + x)^(3/2) - (5/32)*ArcTanh[Sqrt[x]/Sqrt[Sqrt[x] + x]]}
{1/(Sqrt[x]*(1 + Sqrt[x] + x)^(7/2)), x, 4, (4*(1 + 2*Sqrt[x]))/(15*(1 + Sqrt[x] + x)^(5/2)) + (64*(1 + 2*Sqrt[x]))/(135*(1 + Sqrt[x] + x)^(3/2)) + (512*(1 + 2*Sqrt[x]))/(405*Sqrt[1 + Sqrt[x] + x])}
{Sqrt[1 + Sqrt[1 + x^2]], x, 1, -((2*(1 - x^2 - Sqrt[1 + x^2])*Sqrt[1 + Sqrt[1 + x^2]])/(3*x))}
{Sqrt[5 + Sqrt[25 + x^2]], x, 1, -((2*(25 - x^2 - 5*Sqrt[25 + x^2])*Sqrt[5 + Sqrt[25 + x^2]])/(3*x))}
{x/(1 - x^2 + Sqrt[1 - x^2]), x, 3, -Log[1 + Sqrt[1 - x^2]]}
{(1 + x)/(4 + x + Sqrt[-9 + 6*x]), x, 6, -2*Sqrt[3]*Sqrt[-3 + 2*x] + (1/2)*(-3 + 2*x) + 4*Sqrt[6]*ArcTan[(3 + Sqrt[3]*Sqrt[-3 + 2*x])/(2*Sqrt[6])] + 3*Log[24 + 6*x + 6*Sqrt[3]*Sqrt[-3 + 2*x]]}
{(12 - x)/(4 + x + Sqrt[-9 + 6*x]), x, 6, (1/2)*(3 - 2*x) + 2*Sqrt[3]*Sqrt[-3 + 2*x] - 21*Sqrt[3/2]*ArcTan[(3 + Sqrt[3]*Sqrt[-3 + 2*x])/(2*Sqrt[6])] + 10*Log[24 + 6*x + 6*Sqrt[3]*Sqrt[-3 + 2*x]]}
{x*Sqrt[(5 - 7*x^2)/(7 + 5*x^2)], x, 4, (1/10)*Sqrt[(5 - 7*x^2)/(7 + 5*x^2)]*(7 + 5*x^2) - (37*ArcTan[Sqrt[5/7]*Sqrt[(5 - 7*x^2)/(7 + 5*x^2)]])/(5*Sqrt[35])}
{x^2*Sqrt[(1 - x^3)/(1 + x^3)], x, 4, (1/3)*Sqrt[(1 - x^3)/(1 + x^3)]*(1 + x^3) - (2/3)*ArcTan[Sqrt[(1 - x^3)/(1 + x^3)]]}
{x^8*Sqrt[(1 - x^3)/(1 + x^3)], x, 9, (-(1/6))*Sqrt[(1 - x^3)/(1 + x^3)]*(1 + x^3) - (1/18)*Sqrt[(1 - x^3)/(1 + x^3)]*(1 + x^3)^2 + (1/9)*Sqrt[(1 - x^3)/(1 + x^3)]*(1 + x^3)^3 + (1/6)*((1 - x^3)/(1 + x^3))^(3/2)*(1 + x^3)^3 + (1/6)*((1 - x^3)/(1 + x^3))^(5/2)*(1 + x^3)^3 - (1/3)*ArcTan[Sqrt[(1 - x^3)/(1 + x^3)]]}
{x^9*Sqrt[(5 - 7*x^5)/(7 + 5*x^5)], x, 7, (61*Sqrt[(5 - 7*x^5)/(7 + 5*x^5)]*(7 + 5*x^5))/1750 - (61*Sqrt[(5 - 7*x^5)/(7 + 5*x^5)]*(7 + 5*x^5)^2)/9250 - (7/925)*((5 - 7*x^5)/(7 + 5*x^5))^(3/2)*(7 + 5*x^5)^2 + (2257*ArcTan[Sqrt[5/7]*Sqrt[(5 - 7*x^5)/(7 + 5*x^5)]])/(875*Sqrt[35])}
{(1 + 2*x)*(x + x^2)^3*Sqrt[1 - (x + x^2)^2], x, 4, (-2/15)*(1 - x^2*(1 + x)^2)^(3/2) - (1/5)*x^2*(1 + x)^2*(1 - x^2*(1 + x)^2)^(3/2)}
{x*Sqrt[x^2 + x^5], x, 2, (2*(x^2*(1 + x^3))^(3/2))/(9*x^3)}
{(-1 + x^3)/(Sqrt[x]*(1 + x^2)), x, 14, (2*x^(3/2))/3 + Sqrt[2]*ArcTan[1 - Sqrt[2]*Sqrt[x]] - Sqrt[2]*ArcTan[1 + Sqrt[2]*Sqrt[x]]}
{Sqrt[(1 + x)/x^5], x, 1, (-(2/3))*x^6*((1 + x)/x^5)^(3/2)}
{1/(2*Sqrt[-1 + x]*Sqrt[-Sqrt[-1 + x] + x]), x, 3, -ArcSinh[(1 - 2*Sqrt[-1 + x])/Sqrt[3]]}
{1/((1 + x^4)*Sqrt[-x^2 + Sqrt[1 + x^4]]), x, -5, ArcCot[Sqrt[-x^2 + Sqrt[1 + x^4]]/x]}
{(9 - 9*Sqrt[x] + 2*x)/(-3*Sqrt[x] + x)^(1/3), x, If[$VersionNumber > 6, 2, 9],  If[$VersionNumber > 6, (6/5)*(-3*Sqrt[x] + x)^(5/3), (-18/5)*Sqrt[x]*(-3*Sqrt[x] + x)^(2/3) + (6/5)*x*(-3*Sqrt[x] + x)^(2/3)]}

{Sqrt[x]/(x^(1/3) + x), x, 9, 2*Sqrt[x] + (3*ArcTan[1 - Sqrt[2]*x^(1/6)])/Sqrt[2] - (3*ArcTan[1 + Sqrt[2]*x^(1/6)])/Sqrt[2] - (3*Log[1 - Sqrt[2]*x^(1/6) + x^(1/3)])/(2*Sqrt[2]) + (3*Log[1 + Sqrt[2]*x^(1/6) + x^(1/3)])/(2*Sqrt[2])}
{x/(2*x - x^2)^(3/2), x, 2, x/Sqrt[2*x - x^2]}
{(1 + x^(1/3))/(1 + Sqrt[x]), x, 7, -3*x^(1/3) + 2*Sqrt[x] + (6*x^(5/6))/5 - 2*Sqrt[3]*ArcTan[(1 - 2*x^(1/6))/Sqrt[3]] - 4*Log[1 + x^(1/6)] - Log[1 - x^(1/6) + x^(1/3)]}
{(1 + x^(1/3))/(1 + x^(1/4)), x, 7, 12*x^(1/12) + 4*x^(1/4) - 3*x^(1/3) - 2*Sqrt[x] + (12*x^(7/12))/7 + (4*x^(3/4))/3 - (6*x^(5/6))/5 + (12*x^(13/12))/13 + 4*Sqrt[3]*ArcTan[(1 - 2*x^(1/12))/Sqrt[3]] - 8*Log[1 + x^(1/12)] - 2*Log[1 - x^(1/12) + x^(1/6)]}
{(6 - 8*x^(7/2))/(5 - 9*Sqrt[x]), x, 5, -((56145628*Sqrt[x])/43046721) + (125000*x)/4782969 + (50000*x^(3/2))/1594323 + (2500*x^2)/59049 + (400*x^(5/2))/6561 + (200*x^3)/2187 + (80*x^(7/2))/567 + (2*x^4)/9 - (280728140*Log[5 - 9*Sqrt[x]])/387420489}
{(1 + x^(7/2))/(1 - x^2), x, 8, -2*Sqrt[x] - (2*x^(5/2))/5 + ArcTan[Sqrt[x]] + ArcTanh[Sqrt[x]] + ArcTanh[x], -2*Sqrt[x] - (2*x^(5/2))/5 + ArcTan[Sqrt[x]] - Log[1 - Sqrt[x]] + (1/2)*Log[1 + x]}

{(4 + 2*x)/((-1 + 2*x)^(1/3) + Sqrt[-1 + 2*x]), x, 5, (1/2)*(1 - 2*x) + 18*(-1 + 2*x)^(1/6) - 9*(-1 + 2*x)^(1/3) + 6*Sqrt[-1 + 2*x] - (3/4)*(-1 + 2*x)^(2/3) + (3/5)*(-1 + 2*x)^(5/6) + (3/7)*(-1 + 2*x)^(7/6) - (3/8)*(-1 + 2*x)^(4/3) + (1/3)*(-1 + 2*x)^(3/2) - 18*Log[1 + (-1 + 2*x)^(1/6)]}
{(x + (1 - 9*x^2)^(3/2))/Sqrt[1 - 9*x^2], x, 5, x - 3*x^3 - (1/9)*Sqrt[1 - 9*x^2]}
{(1 - x)^(1/3)*(1 + x)^2, x, 3, (-(9/7))*(1 - x)^(4/3) - (18/35)*(1 - x)^(4/3)*x - (3/10)*(1 - x)^(4/3)*(1 + x)^2}


{Sqrt[x + x^(5/2)], x, 2, (4*(x*(1 + x^(3/2)))^(3/2))/(9*x^(3/2))}
{Sqrt[x + x^(3/2)], x, 5, If[$VersionNumber > 6, (4*(1 + Sqrt[x])*Sqrt[(1 + Sqrt[x])*x]*(8 - 12*Sqrt[x] + 15*x))/(105*Sqrt[x]), (4*(1 + Sqrt[x])*Sqrt[(1 + Sqrt[x])*x]*(8 - 12*Sqrt[x] + 15*x))/(105*Sqrt[x])]}
{Sqrt[x^(1/4) + x], x, 7, (Sqrt[(1 + x^(3/4))*x^(1/4)]*(Sqrt[1 + x^(3/4)]*x^(3/8) + 2*Sqrt[1 + x^(3/4)]*x^(9/8) - ArcSinh[x^(3/8)]))/(3*Sqrt[1 + x^(3/4)]*x^(1/8))}

{x*Sqrt[x + x^(3/2)], x, 7, (4*(1 + Sqrt[x])*Sqrt[(1 + Sqrt[x])*x]*(128 - 192*Sqrt[x] + 240*x - 280*x^(3/2) + 315*x^2))/(3465*Sqrt[x])}

{Sqrt[x - x^2]/x^3, x, 1, -((2*(x - x^2)^(3/2))/(3*x^3))}
{Sqrt[b*x + c*x^2]/x^(3/2), x, 4, (2*Sqrt[x*(b + c*x)]*(Sqrt[b + c*x] - Sqrt[b]*ArcTanh[Sqrt[b + c*x]/Sqrt[b]]))/(Sqrt[x]*Sqrt[b + c*x])}


(* Positive integer powers of monomial sums *)
{(a + b*x^(2/3)+c*Sqrt[x])^2, x, 3, a^2*x + (4/3)*a*c*x^(3/2) + (6/5)*a*b*x^(5/3) + (c^2*x^2)/2 + (12/13)*b*c*x^(13/6) + (3/7)*b^2*x^(7/3)}
{(a + b*x^(2/3)+c*Sqrt[x])^3, x, 3, a^3*x + 2*a^2*c*x^(3/2) + (9/5)*a^2*b*x^(5/3) + (3/2)*a*c^2*x^2 + (36/13)*a*b*c*x^(13/6) + (9/7)*a*b^2*x^(7/3) + (2/5)*c^3*x^(5/2) + (9/8)*b*c^2*x^(8/3) + (18/17)*b^2*c*x^(17/6) + (b^3*x^3)/3}


(* Way kool example: *)
{(a*x^m + b*x^(6*m + 1))^5, x, 3, (a + b*x^(1 + 5*m))^6/(6*b*(1 + 5*m))}
{1/(a*x^m + b*x^(1 - 2*m))^3, x, 2, -(1/(2*b*(1 - 3*m)*(a + b*x^(1 - 3*m))^2)), -(x^(-2 + 6*m)/(2*b*(1 - 3*m)*(b + a*x^(-1 + 3*m))^2))}
{(a + b*n*x^(n-1))/(a*x + b*x^n), x, 2, Log[a*x+b*x^n]}
{(a + b*x^(n-1))/(c*x + d*x^n), x, 4, (b*Log[x])/d - ((b*c - a*d)*Log[d + c*x^(1 - n)])/(c*d*(1 - n))}
{(a*x^m + b*x^n)/(c*x^m + d*x^n), x, 2, (b*x)/d - ((b*c - a*d)*Int[x^m/(c*x^m + d*x^n), x])/d}


{(1 + x)^m*(1 + 2*x + x^2)^n, x, 4, ((1 + x)^(1 + m)*((1 + x)^2)^n)/(1 + m + 2*n)}
{((b*e)/(2*c) + e*x)^m*(b^2/(4*c) + b*x + c*x^2)^n, x, 7, (2^(-1 - m - 2*n)*(b/c + 2*x)*(e*(b/c + 2*x))^m*((b + 2*c*x)^2/c)^n)/(1 + m + 2*n)}


(* Integrands of the form (x^m)^(n/2) where m and n are integers *)
{Sqrt[x], x, 1, (2*x^(3/2))/3}
{Sqrt[x^2], x, 1, (x*Sqrt[x^2])/2}
{Sqrt[x^3], x, 1, 2*x*Sqrt[x^3]/5}
{Sqrt[1/x], x, 1, 2/Sqrt[x^(-1)]}
{Sqrt[1/x^2], x, 1, Sqrt[1/x^2]*x*Log[x]}
{Sqrt[1/x^3], x, 1, -2*Sqrt[1/x^3]*x}

{x^(3/2), x, 1, (2*x^(5/2))/5}
{(x^2)^(3/2), x, 1, (1/4)*x*(x^2)^(3/2)}
{(x^3)^(3/2), x, 1, (2/11)*x*(x^3)^(3/2)}
{(1/x)^(3/2), x, 1, -2*Sqrt[1/x]}
{(1/x^2)^(3/2), x, 1, (-(1/2))*(1/x^2)^(3/2)*x}
{(1/x^3)^(3/2), x, 1, (-(2/7))*(1/x^3)^(3/2)*x}

{1/Sqrt[x], x, 1, 2*Sqrt[x]}
{1/Sqrt[x^2], x, 1, (x*Log[x])/Sqrt[x^2]}
{1/Sqrt[x^3], x, 1, (-2*x)/Sqrt[x^3]}
{1/Sqrt[1/x], x, 1, 2/(3*(1/x)^(3/2))}
{1/Sqrt[1/x^2], x, 1, x/(2*Sqrt[1/x^2])}
{1/Sqrt[1/x^3], x, 1, (2*x)/(5*Sqrt[1/x^3])}


(* Integrands of the form (x^m)^(n/3) where m and n are integers *)
{x^(1/3), x, 1, (3*x^(4/3))/4}
{(x^2)^(1/3), x, 1, (3/5)*x*(x^2)^(1/3)}
{(x^3)^(1/3), x, 1, (1/2)*x*(x^3)^(1/3)}
{(1/x)^(1/3), x, 1, 3/(2*(1/x)^(2/3))}
{(1/x^2)^(1/3), x, 1, 3*(1/x^2)^(1/3)*x}
{(1/x^3)^(1/3), x, 1, (1/x^3)^(1/3)*x*Log[x]}

{x^(2/3), x, 1, (3*x^(5/3))/5}
{(x^2)^(2/3), x, 1, (3/7)*x*(x^2)^(2/3)}
{(x^3)^(2/3), x, 1, (1/3)*x*(x^3)^(2/3)}
{(1/x)^(2/3), x, 1, 3/(1/x)^(1/3)}
{(1/x^2)^(2/3), x, 1, -3*(1/x^2)^(2/3)*x}
{(1/x^3)^(2/3), x, 1, (-(1/x^3)^(2/3))*x}

{1/x^(1/3), x, 1, (3*x^(2/3))/2}
{1/(x^2)^(1/3), x, 1, (3*x)/(x^2)^(1/3)}
{1/(x^3)^(1/3), x, 1, (x*Log[x])/(x^3)^(1/3)}
{1/(1/x)^(1/3), x, 1, 3/(4*(1/x)^(4/3))}
{1/(1/x^2)^(1/3), x, 1, (3*x)/(5*(1/x^2)^(1/3))}
{1/(1/x^3)^(1/3), x, 1, x/(2*(1/x^3)^(1/3))}


(* Integrands of the form (x^m)^n where m and n are symbolic *)
{(x^m)^(-1/m), x, 1, (x*Log[x])/(x^m)^m^(-1)}
{(x^m)^n, x, 1, (x*(x^m)^n)/(1 + m*n)}
{(a*(b*x^m)^n)^(-1/(m*n)), x, 2, (x*Log[x])/(a*(b*x^m)^n)^(1/(m*n))}
{(a*(b*x^m)^n)^p, x, 2, (x*(a*(b*x^m)^n)^p)/(1 + m*n*p)}


{1/(a*x^n + b*x^n), x, 3, x^(1 - n)/((a + b)*(1 - n))}


{x^(-3 - n)*(a + b*x)^n, x, 2, -((x^(-2 - n)*(a + b*x)^(1 + n))/(a*(1 + n))) + (x^(-2 - n)*(a + b*x)^(2 + n))/(a^2*(1 + n)*(2 + n))}
{x^(2*n - 3*(1 + n))*(a + b*x)^n, x, 2, -((x^(-2 - n)*(a + b*x)^(1 + n))/(a*(1 + n))) + (x^(-2 - n)*(a + b*x)^(2 + n))/(a^2*(1 + n)*(2 + n))}

{x^(-1 - 3*n)*(x^2*(a + b*x))^n, x, 2, -(((x^2*(a + b*x))^n*((a + b*x)^(1 + n)/x^n - b*Int[(a + b*x)^n/x^n, x]))/(x^(2*n)*(a + b*x)^n*(a*n)))}
{x^(-2 - 3*n)*(x^2*(a + b*x))^n, x, 1, -((x^(-3 - 3*n)*(x^2*(a + b*x))^(1 + n))/(a*(1 + n)))}
{x^(-3 - 3*n)*(x^2*(a + b*x))^n, x, 4, -((x^(-2 - 3*n)*(x^2*(a + b*x))^n*(a*(a + b*x)^(1 + n) - (a + b*x)^(2 + n)/(2 + n)))/((a + b*x)^n*(a^2*(1 + n))))}
{x^(-4 - 3*n)*(x^2*(a + b*x))^n, x, 4, -((x^(-3 - 3*n)*(x^2*(a + b*x))^n*(a^2*(a + b*x)^(1 + n) - (2*a*(a + b*x)^(2 + n))/(2 + n) + (2*(a + b*x)^(3 + n))/((2 + n)*(3 + n))))/((a + b*x)^n*(a^3*(1 + n))))}


(* Integrands of the form x^m*Sqrt[a+b*x]/Sqrt[c+d*x] *)
{Sqrt[x]/Sqrt[1 + x], x, 2, Sqrt[x]*Sqrt[1 + x] - ArcSinh[Sqrt[x]]}
{Sqrt[-1 + x]/Sqrt[x], x, 2, Sqrt[-1 + x]*Sqrt[x] - ArcSinh[Sqrt[-1 + x]]}


(* Integrands of the form (a+b*Sqrt[x])^m/Sqrt[x] *)
{(1 + Sqrt[x])/Sqrt[x], x, 2, 2*Sqrt[x] + x}
{(1 + Sqrt[x])^2/Sqrt[x], x, 2, (2*(1 + Sqrt[x])^3)/3}
{(1 + Sqrt[x])^3/Sqrt[x], x, 2, (1 + Sqrt[x])^4/2}
{1/((1 + Sqrt[x])*Sqrt[x]), x, 2, 2*Log[1 + Sqrt[x]]}
{1/((1 + Sqrt[x])^2*Sqrt[x]), x, 2, -2/(1 + Sqrt[x])}
{1/((1 + Sqrt[x])^3*Sqrt[x]), x, 2, -(1 + Sqrt[x])^(-2)}
{Sqrt[1 + Sqrt[x]]/Sqrt[x], x, 2, (4*(1 + Sqrt[x])^(3/2))/3}
{(1 + Sqrt[x])^n/Sqrt[x], x, 2, (2*(1 + Sqrt[x])^(1 + n))/(1 + n)}

{Sqrt[x]/(1 + Sqrt[x]), x, 5, -2*Sqrt[x] + x + 2*Log[1 + Sqrt[x]]}


(* Integrands of the form x^m*Sqrt[(a+b*x)/(c+d*x)] *)
{Sqrt[x/(1 + x)], x, 3, Sqrt[x]*Sqrt[1 + x] - ArcSinh[Sqrt[x]], Sqrt[x/(1 + x)]*(1 + x) - ArcTanh[Sqrt[x/(1 + x)]]}
{Sqrt[-(x/(1 + x))], x, 3, Sqrt[-(x/(1 + x))]*(1 + x) - ArcTan[Sqrt[-(x/(1 + x))]]}
{Sqrt[(1 + x)/x], x, 3, x*Sqrt[(1 + x)/x] + ArcTanh[Sqrt[(1 + x)/x]]}
{Sqrt[(1 - x)/x], x, 3, Sqrt[(1 - x)/x]*x - ArcTan[Sqrt[(1 - x)/x]]}
{Sqrt[(-1 + x)/x], x, 3, Sqrt[-1 + x]*Sqrt[x] - ArcSinh[Sqrt[-1 + x]], Sqrt[-((1 - x)/x)]*x - ArcTanh[Sqrt[-((1 - x)/x)]]}

{Sqrt[-(x/(1 + x))]/x, x, 2, 2*ArcTan[Sqrt[-(x/(1 + x))]]}
{Sqrt[(1 + x)/x]/x, x, 4, -2*Sqrt[(1 + x)/x] + 2*ArcTanh[Sqrt[(1 + x)/x]]}
{Sqrt[(1 - x)/(1 + x)]/(-1 + x), x, 2, 2*ArcTan[Sqrt[(1 - x)/(1 + x)]]}


{1/Sqrt[a*c + (b*c + a*d)*x + b*d*x^2], x, 1, ArcTanh[(b*c + a*d + 2*b*d*x)/(2*Sqrt[b]*Sqrt[d]*Sqrt[a*c + (b*c + a*d)*x + b*d*x^2])]/(Sqrt[b]*Sqrt[d])}
{1/Sqrt[4 - (2 + x)^2], x, 2, -ArcSin[(1/2)*(-2 - x)]}
{1/Sqrt[4 - (-1 + x)^2], x, 2, -ArcSin[(1 - x)/2]}


(* Integrands of the form Sqrt[a+b*Sqrt[c+d*x]] *)
{Sqrt[5 + Sqrt[x]], x, 4, (-(40/3))*Sqrt[5 + Sqrt[x]] + (4/3)*Sqrt[5 + Sqrt[x]]*Sqrt[x] + (4/5)*Sqrt[5 + Sqrt[x]]*x}
{Sqrt[4 - Sqrt[x]], x, 4, (-(128/15))*Sqrt[4 - Sqrt[x]] - (16/15)*Sqrt[4 - Sqrt[x]]*Sqrt[x] + (4/5)*Sqrt[4 - Sqrt[x]]*x}

(* Integrands of the form Sqrt[a+b*Sqrt[c+d*Sqrt[e+f*x]]] *)
{Sqrt[2 + Sqrt[4 + Sqrt[x]]], x, 5, (64/5)*(2 + Sqrt[4 + Sqrt[x]])^(5/2) - (48/7)*(2 + Sqrt[4 + Sqrt[x]])^(7/2) + (8/9)*(2 + Sqrt[4 + Sqrt[x]])^(9/2)}
{Sqrt[2 - Sqrt[4 + Sqrt[-9 + 5*x]]], x, 5, (64/25)*(2 - Sqrt[4 + Sqrt[-9 + 5*x]])^(5/2) - (48/35)*(2 - Sqrt[4 + Sqrt[-9 + 5*x]])^(7/2) + (8/45)*(2 - Sqrt[4 + Sqrt[-9 + 5*x]])^(9/2)}

(* Integrands of the form Sqrt[a+b*Sqrt[c+d*Sqrt[e+f*Sqrt[g+h*x]]]] *)
{Sqrt[1 + Sqrt[1 + Sqrt[1 + Sqrt[x]]]], x, 6, (-(32/5))*(1 + Sqrt[1 + Sqrt[1 + Sqrt[x]]])^(5/2) + (48/7)*(1 + Sqrt[1 + Sqrt[1 + Sqrt[x]]])^(7/2) + (112/9)*(1 + Sqrt[1 + Sqrt[1 + Sqrt[x]]])^(9/2) - (320/11)*(1 + Sqrt[1 + Sqrt[1 + Sqrt[x]]])^(11/2) + (288/13)*(1 + Sqrt[1 + Sqrt[1 + Sqrt[x]]])^(13/2) - (112/15)*(1 + Sqrt[1 + Sqrt[1 + Sqrt[x]]])^(15/2) + (16/17)*(1 + Sqrt[1 + Sqrt[1 + Sqrt[x]]])^(17/2)}
{Sqrt[2 + Sqrt[3 + Sqrt[-1 + 2*Sqrt[x]]]], x, 6, (-(16/3))*(2 + Sqrt[3 + Sqrt[-1 + 2*Sqrt[x]]])^(3/2) + (136/5)*(2 + Sqrt[3 + Sqrt[-1 + 2*Sqrt[x]]])^(5/2) - (480/7)*(2 + Sqrt[3 + Sqrt[-1 + 2*Sqrt[x]]])^(7/2) + (304/3)*(2 + Sqrt[3 + Sqrt[-1 + 2*Sqrt[x]]])^(9/2) - (760/11)*(2 + Sqrt[3 + Sqrt[-1 + 2*Sqrt[x]]])^(11/2) + (300/13)*(2 + Sqrt[3 + Sqrt[-1 + 2*Sqrt[x]]])^(13/2) - (56/15)*(2 + Sqrt[3 + Sqrt[-1 + 2*Sqrt[x]]])^(15/2) + (4/17)*(2 + Sqrt[3 + Sqrt[-1 + 2*Sqrt[x]]])^(17/2)}

{x*Sqrt[1 + Sqrt[1 + Sqrt[-1 + x]]], x, 5, (16/5)*(1 + Sqrt[1 + Sqrt[-1 + x]])^(5/2) - (24/7)*(1 + Sqrt[1 + Sqrt[-1 + x]])^(7/2) + 8*(1 + Sqrt[1 + Sqrt[-1 + x]])^(9/2) - (160/11)*(1 + Sqrt[1 + Sqrt[-1 + x]])^(11/2) + (144/13)*(1 + Sqrt[1 + Sqrt[-1 + x]])^(13/2) - (56/15)*(1 + Sqrt[1 + Sqrt[-1 + x]])^(15/2) + (8/17)*(1 + Sqrt[1 + Sqrt[-1 + x]])^(17/2)}


(* Integrands of the form (a*x^3+b*x^6)^(n/3) where n is an integer *)
{(a*x^3 + b*x^6)^(5/3), x, 5, -(((3*a - 8*b*x^3)*(a + b*x^3)^2*(x^3*(a + b*x^3))^(2/3))/(88*b^2*x^2))}
{(a*x^3 + b*x^6)^(2/3), x, 2, (x^3*(a + b*x^3))^(5/3)/(5*b*x^5)}
{1/(a*x^3 + b*x^6)^(2/3), x, 2, -((x^3*(a + b*x^3))^(1/3)/(a*x^2))}
{1/(a*x^3 + b*x^6)^(5/3), x, 5, (-a^2 + 6*a*b*x^3 + 9*b^2*x^6)/(4*a^3*x^2*(x^3*(a + b*x^3))^(2/3)), ((a + b*x^3)^(2/3)*(9*b*x^3*(a + b*x^3)^(1/3) + a*((2*a)/(a + b*x^3)^(2/3) - 3*(a + b*x^3)^(1/3))))/(4*a^3*x^2*(x^3*(a + b*x^3))^(2/3))}


(* Integrands of the form x^3/Sqrt[a*x^2+b*x^4] *)
{x^3/Sqrt[3*x^2 - 4*x^4], x, 3, (-(1/8))*Sqrt[3*x^2 - 4*x^4] - (3/32)*ArcSin[(1/3)*(3 - 8*x^2)]}
{x^3/Sqrt[-3*x^2 - 4*x^4], x, 3, (-(1/8))*Sqrt[-3*x^2 - 4*x^4] + (3/32)*ArcSin[(1/3)*(-3 - 8*x^2)]}
{x^3/Sqrt[3*x^2 + 4*x^4], x, 3, (1/8)*Sqrt[3*x^2 + 4*x^4] - (3/16)*ArcTanh[(2*x^2)/Sqrt[3*x^2 + 4*x^4]]}
{x^3/Sqrt[-3*x^2 + 4*x^4], x, 3, (1/8)*Sqrt[-3*x^2 + 4*x^4] + (3/16)*ArcTanh[(2*x^2)/Sqrt[-3*x^2 + 4*x^4]]}
{x^3/Sqrt[a*x^2 + b*x^4], x, 3, Sqrt[a*x^2 + b*x^4]/(2*b) - (a*ArcTanh[(Sqrt[b]*x^2)/Sqrt[a*x^2 + b*x^4]])/(2*b^(3/2))}
{x^3/Sqrt[a*x^2 - b*x^4], x, 3, -(Sqrt[a*x^2 - b*x^4]/(2*b)) + (a*ArcTan[(Sqrt[b]*x^2)/Sqrt[a*x^2 - b*x^4]])/(2*b^(3/2))}


{Sqrt[b*x^2 + c*x^4], x, 2, (x^2*(b + c*x^2))^(3/2)/(3*c*x^3)}
{Sqrt[x^2 + x^3 - x^4], x, 5, -((Sqrt[x^2*(1 + x - x^2)]*(6*(1 - 2*x)*Sqrt[1 + x - x^2] + 16*(1 + x - x^2)^(3/2) + 15*ArcSin[(1 - 2*x)/Sqrt[5]]))/(48*x*Sqrt[1 + x - x^2]))}


(* Integrands of the form 1/(a*x^m+b*x^n) where m and n are fractions *)
{1/(Sqrt[x] - x^(5/2)), x, 4, ArcTan[Sqrt[x]] + ArcTanh[Sqrt[x]]}
{1/(-x^(1/4) + Sqrt[x]), x, 5, 4*x^(1/4) + 2*Sqrt[x] + 4*Log[1 - x^(1/4)]}
{1/(x^(1/4) + x^(1/3)), x, 5, -12*x^(1/12) + 6*x^(1/6) - 4*x^(1/4) + 3*x^(1/3) - (12*x^(5/12))/5 + 2*Sqrt[x] - (12*x^(7/12))/7 + (3*x^(2/3))/2 + 12*Log[1 + x^(1/12)]}
{1/(x^(1/3) + Sqrt[x]), x, 5, 6*x^(1/6) - 3*x^(1/3) + 2*Sqrt[x] - 6*Log[1 + x^(1/6)]}
{1/(x^(1/4) + Sqrt[x]), x, 5, -4*x^(1/4) + 2*Sqrt[x] + 4*Log[1 + x^(1/4)]}
{1/(-x^(1/3) + x^(2/3)), x, 4, 3*x^(1/3) + 3*Log[1 - x^(1/3)]}


(* Integrands of the form (a+b*x^n)/(c+d*x^n) where n is a fraction *) 
{(a + b*Sqrt[x])/(c + d*Sqrt[x]), x, 5, -((2*(b*c - a*d)*Sqrt[x])/d^2) + (b*x)/d + (2*c*(b*c - a*d)*Log[c + d*Sqrt[x]])/d^3}
{(-1 + x^(1/3))/(1 + x^(1/3)), x, 5, 6*x^(1/3) - 3*x^(2/3) + x - 6*Log[1 + x^(1/3)]}
{(1 + x^(-1/3))/(-1 + x^(-1/3)), x, 5, -6*x^(1/3) - 3*x^(2/3) - x - 6*Log[1 - x^(1/3)]}
{(1 + x^(2/3))/(-1 + x^(2/3)), x, 5, 6*x^(1/3) + x - 6*ArcTanh[x^(1/3)]}
{(-16 + x^(3/4))/(16 + x^(3/4)), x, 8, -128*x^(1/4) + x - (256*2^(1/3)*ArcTan[(2^(1/3) - x^(1/4))/(2^(1/3)*Sqrt[3])])/Sqrt[3] + (256/3)*2^(1/3)*Log[2*2^(1/3) + x^(1/4)] - (128/3)*2^(1/3)*Log[4*2^(2/3) - 2*2^(1/3)*x^(1/4) + Sqrt[x]]}
{(2 + (1 - 5*x)^(1/3))/(3 + (1 - 5*x)^(1/3)), x, 5, (-(9/5))*(1 - 5*x)^(1/3) + (3/10)*(1 - 5*x)^(2/3) + (1/5)*(-1 + 5*x) + (27/5)*Log[3 + (1 - 5*x)^(1/3)]}


(* Integrands of the form x^m*Sqrt[(a+b*x)/(c+d*x)] *)
{Sqrt[(a + x)/(a - x)], x, 3, -((a - x)*Sqrt[(a + x)/(a - x)]) + 2*a*ArcTan[Sqrt[(a + x)/(a - x)]]}
{Sqrt[(-a + x)/(a + x)], x, 3, Sqrt[-((a - x)/(a + x))]*(a + x) - 2*a*ArcTanh[Sqrt[-((a - x)/(a + x))]]}
{Sqrt[(a + b*x)/(c + d*x)], x, 3, (Sqrt[(a + b*x)/(c + d*x)]*(c + d*x))/d - ((b*c - a*d)*ArcTanh[(Sqrt[d]*Sqrt[(a + b*x)/(c + d*x)])/Sqrt[b]])/(Sqrt[b]*d^(3/2))}
{Sqrt[(-1 + 5*x)/(1 + 7*x)]/x^2, x, 3, -((Sqrt[-((1 - 5*x)/(1 + 7*x))]*(1 + 7*x))/x) + 12*ArcTan[Sqrt[-((1 - 5*x)/(1 + 7*x))]]}
{Sqrt[(-1 + x)/(5 + 3*x)], x, 3, (1/3)*Sqrt[-((1 - x)/(5 + 3*x))]*(5 + 3*x) - (8*ArcTanh[Sqrt[3]*Sqrt[-((1 - x)/(5 + 3*x))]])/(3*Sqrt[3])}

{x^3*Sqrt[(-1 + x)/(1 + x)], x, 10, (3/8)*Sqrt[-((1 - x)/(1 + x))]*(1 + x) + (1/8)*Sqrt[-((1 - x)/(1 + x))]*(1 + x)^2 + (1/20)*Sqrt[-((1 - x)/(1 + x))]*(1 + x)^3 - (3/20)*Sqrt[-((1 - x)/(1 + x))]*(1 + x)^4 + (29/60)*(-((1 - x)/(1 + x)))^(3/2)*(1 + x)^4 - (1/3)*(-((1 - x)/(1 + x)))^(5/2)*(1 + x)^4 + (1/4)*(-((1 - x)/(1 + x)))^(7/2)*(1 + x)^4 + (3/4)*ArcTanh[Sqrt[-((1 - x)/(1 + x))]]}


{1 - Sqrt[x], x, 1, x - (2*x^(3/2))/3}
{(1 - x)/(1 + Sqrt[x]), x, 2, x - (2*x^(3/2))/3}
{1 - x^(1/4), x, 1, x - (4*x^(5/4))/5}
{(1 - Sqrt[x])/(1 + x^(1/4)), x, 3, x - (4*x^(5/4))/5}

{1/Sqrt[(a + b*x)*(c + d*x)], x, 2, ArcTanh[(b*c + a*d + 2*b*d*x)/(2*Sqrt[b]*Sqrt[d]*Sqrt[a*c + (b*c + a*d)*x + b*d*x^2])]/(Sqrt[b]*Sqrt[d])}
{1/Sqrt[(a + b*x)*(c - d*x)], x, 2, -(ArcTan[(b*c - a*d - 2*b*d*x)/(2*Sqrt[b]*Sqrt[d]*Sqrt[a*c + (b*c - a*d)*x - b*d*x^2])]/(Sqrt[b]*Sqrt[d]))}

{(-1 + x^2)/((1 + x^2)*Sqrt[x + x^3]), x, 9, -((2*x)/Sqrt[x*(1 + x^2)])}
(* {1/Sqrt[a*x+b*x^3], x, 0} *)

{1/(Sqrt[x]*(1 - x^2)), x, 4, ArcTan[Sqrt[x]] + ArcTanh[Sqrt[x]]}
{Sqrt[x]/(x - x^3), x, 4, ArcTan[Sqrt[x]] + ArcTanh[Sqrt[x]]}

{Sqrt[x^6]/(x*(1 - x^4)), x, 4, -((Sqrt[x^6]*(ArcTan[x] - ArcTanh[x]))/(2*x^3))}
{Sqrt[x^6]/(x - x^5), x, 5, -((Sqrt[x^6]*(ArcTan[x] - ArcTanh[x]))/(2*x^3))}
{(x^6)^(3/2)/(x*(1 - x^4)), x, 7, -((Sqrt[x^6]*(10*x + 2*x^5 - 5*ArcTan[x] - 5*ArcTanh[x]))/(10*x^3))}

{1/(1 - x^4) - Sqrt[x^6]/(x - x^5), x, 9, ArcTan[x]/2 + (Sqrt[x^6]*(ArcTan[x] - ArcTanh[x]))/(2*x^3) + ArcTanh[x]/2}
{1/(1 - x^4) - Sqrt[x^6]/(x*(1 - x^4)), x, 8, ArcTan[x]/2 + (Sqrt[x^6]*(ArcTan[x] - ArcTanh[x]))/(2*x^3) + ArcTanh[x]/2}
{(x - Sqrt[x^6])/(x - x^5), x, 9, ArcTan[x]/2 + (Sqrt[x^6]*(ArcTan[x] - ArcTanh[x]))/(2*x^3) + ArcTanh[x]/2}
{(x - Sqrt[x^6])/(x*(1 - x^4)), x, 9, ArcTan[x]/2 + (Sqrt[x^6]*(ArcTan[x] - ArcTanh[x]))/(2*x^3) + ArcTanh[x]/2}
{(1 - Sqrt[x^6]/x)/(1 - x^4), x, 9, ArcTan[x]/2 + (Sqrt[x^6]*(ArcTan[x] - ArcTanh[x]))/(2*x^3) + ArcTanh[x]/2}
{x/(x + Sqrt[x^6]), x, 10, ArcTan[x]/2 + (Sqrt[x^6]*(ArcTan[x] - ArcTanh[x]))/(2*x^3) + ArcTanh[x]/2}

{Sqrt[x^3]/(x - x^3), x, 6, -((Sqrt[x^3]*(ArcTan[Sqrt[x]] - ArcTanh[Sqrt[x]]))/x^(3/2))}
{(Sqrt[x] - Sqrt[x^3])/(x - x^3), x, 11, ArcTan[Sqrt[x]] + (Sqrt[x^3]*(ArcTan[Sqrt[x]] - ArcTanh[Sqrt[x]]))/x^(3/2) + ArcTanh[Sqrt[x]]}
{1/(Sqrt[x] + Sqrt[x^3]), x, 12, ArcTan[Sqrt[x]] + (Sqrt[x^3]*(ArcTan[Sqrt[x]] - ArcTanh[Sqrt[x]]))/x^(3/2) + ArcTanh[Sqrt[x]]}
{1/(Sqrt[-1 + x] + Sqrt[(-1 + x)^3]), x, 12, ArcTan[Sqrt[-1 + x]] + (Sqrt[-(1 - x)^3]*(ArcTan[Sqrt[-1 + x]] - ArcTanh[Sqrt[-1 + x]]))/(-1 + x)^(3/2) + ArcTanh[Sqrt[-1 + x]]}

{x^2/(-1 + x^2 + Sqrt[1 - x^2]), x, 3, x + ArcSin[x]}
{(q + p*x)/(Sqrt[b + a*x]*(f + Sqrt[b + a*x])), x, 5, -((2*f*p*Sqrt[b + a*x])/a^2) + (p*(b + a*x))/a^2 - (2*(b*p - f^2*p - a*q)*Log[f + Sqrt[b + a*x]])/a^2}

{(x*Sqrt[1 + x])/(1 + x^2), x, 5, 2*Sqrt[1 + x] + (1/2)*Sqrt[-2 + 2*Sqrt[2]]*ArcTan[(Sqrt[-2 + 2*Sqrt[2]]*Sqrt[1 + x])/(1 - Sqrt[2] + x)] - (1/2)*Sqrt[2 + 2*Sqrt[2]]*ArcTanh[(Sqrt[2 + 2*Sqrt[2]]*Sqrt[1 + x])/(1 + Sqrt[2] + x)]}
{Sqrt[x^2/(-1 + x^2)]/(1 + x^2), x, 3, (Sqrt[-(x^2/(1 - x^2))]*Sqrt[-1 + x^2]*ArcTan[Sqrt[-1 + x^2]/Sqrt[2]])/(Sqrt[2]*x)}
{Sqrt[(-1 + x^2)^2/(x + x^3)]/(1 + x^2), x, 3, (2*x*Sqrt[(1 - x^2)^2/(x*(1 + x^2))])/(1 - x^2)}
{Sqrt[x^2/(-1 + a + (1 + a)*x^2)]/(1 + x^2), x, 3, (Sqrt[-(x^2/(1 - a - (1 + a)*x^2))]*Sqrt[-1 + a + (1 + a)*x^2]*ArcTan[Sqrt[-1 + a + (1 + a)*x^2]/Sqrt[2]])/(Sqrt[2]*x)}

{Sqrt[1 + 2*x/(1 + x^2)], x, -2, (Sqrt[(1 + x)^2/(1 + x^2)]*Sqrt[1 + x^2]*(Sqrt[1 + x^2] + ArcSinh[x]))/(1 + x)}
{Sqrt[1 + 2*x/(1 + x^2)]/(1 + x^2), x, -2, -(((1 - x)*Sqrt[(1 + x)^2/(1 + x^2)])/(1 + x))}
{1/Sqrt[1 + 2*x/(1 + x^2)], x, -2, ((1 + x)*Sqrt[1 + 2*x + x^2]*(Sqrt[1 + x^2] - ArcSinh[x] - 2*Sqrt[2]*ArcTanh[(1 - Tanh[ArcSinh[x]/2])/Sqrt[2]]))/(Sqrt[(1 + x)^2]*Sqrt[1 + x^2]*Sqrt[(1 + 2*x + x^2)/(1 + x^2)])}

{x/(x*(2 + x))^(3/2), x, 1, x/Sqrt[x*(2 + x)]}
{1/((2 + x)*Sqrt[2*x + x^2]), x, 1, x/Sqrt[2*x + x^2]}

{Sqrt[1 + x^(-1)]/(1 + x)^2, x, 2, 2/Sqrt[1 + x^(-1)]}
{(Sqrt[1 + 1/x^2]*x)/(1 + x^2)^2, x, 3, 1/Sqrt[1 + x^(-2)]}
{1/(Sqrt[1 + x^(-2)]*x*(1 + x^2)), x, 3, 1/Sqrt[1 + x^(-2)]}
{Sqrt[1 + x^(-1)]/Sqrt[1 - x^2], x, 4, (2*Sqrt[1 + 1/x]*Sqrt[1 - x]*Sqrt[x]*ArcSin[Sqrt[x]])/Sqrt[1 - x^2], -((2*Sqrt[-1 + 1/x]*Sqrt[1 + 1/x]*x*ArcTan[Sqrt[-1 + 1/x]])/Sqrt[1 - x^2])}

{x/(Sqrt[(1 - x)/(1 + x)]*(1 + x)), x, 2, (-Sqrt[(1 - x)/(1 + x)])*(1 + x)}
{x/((1 + x)*Sqrt[-1 + 2/(1 + x)]), x, 2, -((1 + x)*Sqrt[-1 + 2/(1 + x)])}
{x/((1 + x)*Sqrt[(2 + x)/(3 + x)]), x, 7, Sqrt[2 + x]*Sqrt[3 + x] - ArcTanh[Sqrt[(2 + x)/(3 + x)]] + 2*Sqrt[2]*ArcTanh[Sqrt[2]*Sqrt[(2 + x)/(3 + x)]], 1/(2*(1 - Sqrt[(2 + x)/(3 + x)])) - 1/(2*(1 + Sqrt[(2 + x)/(3 + x)])) - ArcTanh[Sqrt[(2 + x)/(3 + x)]] + 2*Sqrt[2]*ArcTanh[Sqrt[2]*Sqrt[(2 + x)/(3 + x)]]}

{1/Sqrt[Sqrt[x] + x], x, 3, 2*Sqrt[Sqrt[x] + x] - 2*ArcTanh[Sqrt[x]/Sqrt[Sqrt[x] + x]]}
{Sqrt[Sqrt[x] + x], x, 4, (-(1/4))*(1 + 2*Sqrt[x])*Sqrt[Sqrt[x] + x] + (2/3)*(Sqrt[x] + x)^(3/2) + (1/4)*ArcTanh[Sqrt[x]/Sqrt[Sqrt[x] + x]]}

{Sqrt[x - Sqrt[-4 + x^2]], x, 1, (2*Sqrt[x - Sqrt[-4 + x^2]]*(2*x + Sqrt[-4 + x^2]))/3}
{x^2/Sqrt[1 - (1 + x)^2], x, 4, (3/2)*Sqrt[-2*x - x^2] - (1/2)*x*Sqrt[-2*x - x^2] + (3/2)*ArcSin[1 + x]}
{Sqrt[1 + Sqrt[1 - x^2]], x, 1, (2*(1 + x^2 - Sqrt[1 - x^2])*Sqrt[1 + Sqrt[1 - x^2]])/(3*x)}
{x/(2 - Sqrt[3] + (1 + Sqrt[3])*x + x^2), x, 2, ArcTanh[(1 + Sqrt[3] + 2*x)/Sqrt[-4 + 6*Sqrt[3]]]/Sqrt[-13 + 8*Sqrt[3]] + (1/2)*Log[2 - Sqrt[3] + (1 + Sqrt[3])*x + x^2]}
{Sqrt[x^2 + x^3], x, 4, -((2*(2 - 3*x)*(1 + x)*Sqrt[x^2*(1 + x)])/(15*x))}
{1/((1 + x)*Sqrt[2*x + x^2]), x, 1, ArcTan[Sqrt[2*x + x^2]]}
{1/(Sqrt[-1 + x]*Sqrt[-Sqrt[-1 + x] + x]), x, 2, -2*ArcSinh[(1 - 2*Sqrt[-1 + x])/Sqrt[3]]}
{Sqrt[1 - Sqrt[x] - x]*Sqrt[x], x, 7, (9/32)*(1 + 2*Sqrt[x])*Sqrt[1 - Sqrt[x] - x] + (5/12)*(1 - Sqrt[x] - x)^(3/2) - (1/2)*(1 - Sqrt[x] - x)^(3/2)*Sqrt[x] + (45/64)*ArcSin[(1 + 2*Sqrt[x])/Sqrt[5]]}
{Sqrt[1 - Sqrt[x] - x], x, 4, (-(1/4))*(1 + 2*Sqrt[x])*Sqrt[1 - Sqrt[x] - x] - (2/3)*(1 - Sqrt[x] - x)^(3/2) - (5/8)*ArcSin[(1 + 2*Sqrt[x])/Sqrt[5]]}
{Sqrt[x]/(1 + Sqrt[x] + x), x, 5, 2*Sqrt[x] - (2*ArcTan[(1 + 2*Sqrt[x])/Sqrt[3]])/Sqrt[3] - Log[1 + Sqrt[x] + x]}
{x/(4*Sqrt[x] + x), x, 5, -8*Sqrt[x] + x + 32*Log[4 + Sqrt[x]]}
{1/Sqrt[(-1 - x)/x], x, 3, -(x*Sqrt[-((1 + x)/x)]) + ArcTan[Sqrt[-((1 + x)/x)]]}

{1/((1 + 1/x)^(3/2)*x^2), x, 2, 2/Sqrt[1 + 1/x]}

{(x + x^2)^(3/2)/(1 + x^2), x, 13, (5*Sqrt[x + x^2])/4 + (1/2)*x*Sqrt[x + x^2] - (5/4)*ArcTanh[x/Sqrt[x + x^2]] + (1/2)*(1 - I)^(3/2)*ArcTanh[(1 + (2 - I)*x)/(2*Sqrt[1 - I]*Sqrt[x + x^2])] + (1/2)*(1 + I)^(3/2)*ArcTanh[(1 + (2 + I)*x)/(2*Sqrt[1 + I]*Sqrt[x + x^2])]}


(* Simple antiderivative comes from putting complicated result over a common denominator. *)
{(1 - x^2)*Sqrt[1/(2 - x^2)], x, 7, x/(2*Sqrt[1/(2 - x^2)])}


{x^(1/3)/(-1 + x^(5/6)), x, 13, 2*Sqrt[x] + (3/5)*Sqrt[10 - 2*Sqrt[5]]*ArcTan[(1 - Sqrt[5] + 4*x^(1/6))/Sqrt[10 + 2*Sqrt[5]]] - (3/5)*Sqrt[10 + 2*Sqrt[5]]*ArcTan[(1 + Sqrt[5] + 4*x^(1/6))/Sqrt[10 - 2*Sqrt[5]]] + (6/5)*Log[1 - x^(1/6)] - (3/10)*(1 + Sqrt[5])*Log[2 + (1 - Sqrt[5])*x^(1/6) + 2*x^(1/3)] - (3/10)*(1 - Sqrt[5])*Log[2 + (1 + Sqrt[5])*x^(1/6) + 2*x^(1/3)]}
(* {(Sqrt[x]+x)^(2/3), x, 0} *)
(* {(-3*x+x^2)^(-1/3), x, 0} *)
{(4*x - x^2)^(-3/2), x, 1, -((2 - x)/(4*Sqrt[4*x - x^2]))}
{Sqrt[x]/(1 + x^(3/2)), x, 2, (2*Log[1 + x^(3/2)])/3}
