(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving the Lambert W (ProductLogarithm) Function*)


(* ::Subsection::Closed:: *)
(*Integrands involving ProductLog[a+b x]*)


(* ::Subsubsection::Closed:: *)
(*ProductLog[a+b x]^n*)


{ProductLog[a + b*x]^4, x, 6, 96*x - (96*(a + b*x))/(b*ProductLog[a + b*x]) - (48*(a + b*x)*ProductLog[a + b*x])/b + (16*(a + b*x)*ProductLog[a + b*x]^2)/b - (4*(a + b*x)*ProductLog[a + b*x]^3)/b + ((a + b*x)*ProductLog[a + b*x]^4)/b}
{ProductLog[a + b*x]^3, x, 5, -18*x + (18*(a + b*x))/(b*ProductLog[a + b*x]) + (9*(a + b*x)*ProductLog[a + b*x])/b - (3*(a + b*x)*ProductLog[a + b*x]^2)/b + ((a + b*x)*ProductLog[a + b*x]^3)/b}
{ProductLog[a + b*x]^2, x, 4, 4*x - (4*(a + b*x))/(b*ProductLog[a + b*x]) - (2*(a + b*x)*ProductLog[a + b*x])/b + ((a + b*x)*ProductLog[a + b*x]^2)/b}
{ProductLog[a + b*x], x, 3, -x + (a + b*x)/(b*ProductLog[a + b*x]) + ((a + b*x)*ProductLog[a + b*x])/b}
{1/ProductLog[a + b*x], x, 2, ExpIntegralEi[ProductLog[a + b*x]]/b + (a + b*x)/(b*ProductLog[a + b*x])}
{1/ProductLog[a + b*x]^2, x, 2, (2*ExpIntegralEi[ProductLog[a + b*x]])/b - (a + b*x)/(b*ProductLog[a + b*x]^2)}
{1/ProductLog[a + b*x]^3, x, 3, (3*ExpIntegralEi[ProductLog[a + b*x]])/(2*b) - (a + b*x)/(2*b*ProductLog[a + b*x]^3) - (3*(a + b*x))/(2*b*ProductLog[a + b*x]^2)}
{1/ProductLog[a + b*x]^4, x, 4, (2*ExpIntegralEi[ProductLog[a + b*x]])/(3*b) - (a + b*x)/(3*b*ProductLog[a + b*x]^4) - (2*(a + b*x))/(3*b*ProductLog[a + b*x]^3) - (2*(a + b*x))/(3*b*ProductLog[a + b*x]^2)}
{1/ProductLog[a + b*x]^5, x, 5, (5*ExpIntegralEi[ProductLog[a + b*x]])/(24*b) - (a + b*x)/(4*b*ProductLog[a + b*x]^5) - (5*(a + b*x))/(12*b*ProductLog[a + b*x]^4) - (5*(a + b*x))/(24*b*ProductLog[a + b*x]^3) - (5*(a + b*x))/(24*b*ProductLog[a + b*x]^2)}


{(c*ProductLog[a+b*x])^(5/2), x, 5, (75*c^(5/2)*Sqrt[Pi]*Erfi[Sqrt[c*ProductLog[a + b*x]]/Sqrt[c]])/(16*b) - (75*c^3*(a + b*x))/(8*b*Sqrt[c*ProductLog[a + b*x]]) + (25*c^2*(a + b*x)*Sqrt[c*ProductLog[a + b*x]])/(4*b) - (5*c*(a + b*x)*(c*ProductLog[a + b*x])^(3/2))/(2*b) + ((a + b*x)*(c*ProductLog[a + b*x])^(5/2))/b}
{(c*ProductLog[a+b*x])^(3/2), x, 4, -((9*c^(3/2)*Sqrt[Pi]*Erfi[Sqrt[c*ProductLog[a + b*x]]/Sqrt[c]])/(8*b)) + (9*c^2*(a + b*x))/(4*b*Sqrt[c*ProductLog[a + b*x]]) - (3*c*(a + b*x)*Sqrt[c*ProductLog[a + b*x]])/(2*b) + ((a + b*x)*(c*ProductLog[a + b*x])^(3/2))/b}
{Sqrt[c*ProductLog[a+b*x]], x, 3, (Sqrt[c]*Sqrt[Pi]*Erfi[Sqrt[c*ProductLog[a + b*x]]/Sqrt[c]])/(4*b) - (c*(a + b*x))/(2*b*Sqrt[c*ProductLog[a + b*x]]) + ((a + b*x)*Sqrt[c*ProductLog[a + b*x]])/b}
{1/Sqrt[c*ProductLog[a+b*x]], x, 2, (Sqrt[Pi]*Erfi[Sqrt[c*ProductLog[a + b*x]]/Sqrt[c]])/(2*b*Sqrt[c]) + (a + b*x)/(b*Sqrt[c*ProductLog[a + b*x]])}
{1/(c*ProductLog[a+b*x])^(3/2), x, 2, (3*Sqrt[Pi]*Erfi[Sqrt[c*ProductLog[a + b*x]]/Sqrt[c]])/(b*c^(3/2)) - (2*(a + b*x))/(b*(c*ProductLog[a + b*x])^(3/2))}
{1/(c*ProductLog[a+b*x])^(5/2), x, 3, (10*Sqrt[Pi]*Erfi[Sqrt[c*ProductLog[a + b*x]]/Sqrt[c]])/(3*b*c^(5/2)) - (2*(a + b*x))/(3*b*(c*ProductLog[a + b*x])^(5/2)) - (10*(a + b*x))/(3*b*c*(c*ProductLog[a + b*x])^(3/2))}
{1/(c*ProductLog[a+b*x])^(7/2), x, 4, (28*Sqrt[Pi]*Erfi[Sqrt[c*ProductLog[a + b*x]]/Sqrt[c]])/(15*b*c^(7/2)) - (2*(a + b*x))/(5*b*(c*ProductLog[a + b*x])^(7/2)) - (14*(a + b*x))/(15*b*c*(c*ProductLog[a + b*x])^(5/2)) - (28*(a + b*x))/(15*b*c^2*(c*ProductLog[a + b*x])^(3/2))}


{(-c*ProductLog[a+b*x])^(5/2), x, 5, (75*c^(5/2)*Sqrt[Pi]*Erf[Sqrt[(-c)*ProductLog[a + b*x]]/Sqrt[c]])/(16*b) + (75*c^3*(a + b*x))/(8*b*Sqrt[(-c)*ProductLog[a + b*x]]) + (25*c^2*(a + b*x)*Sqrt[(-c)*ProductLog[a + b*x]])/(4*b) + (5*c*(a + b*x)*((-c)*ProductLog[a + b*x])^(3/2))/(2*b) + ((a + b*x)*((-c)*ProductLog[a + b*x])^(5/2))/b}
{(-c*ProductLog[a+b*x])^(3/2), x, 4, (9*c^(3/2)*Sqrt[Pi]*Erf[Sqrt[(-c)*ProductLog[a + b*x]]/Sqrt[c]])/(8*b) + (9*c^2*(a + b*x))/(4*b*Sqrt[(-c)*ProductLog[a + b*x]]) + (3*c*(a + b*x)*Sqrt[(-c)*ProductLog[a + b*x]])/(2*b) + ((a + b*x)*((-c)*ProductLog[a + b*x])^(3/2))/b}
{Sqrt[-c*ProductLog[a+b*x]], x, 3, (Sqrt[c]*Sqrt[Pi]*Erf[Sqrt[(-c)*ProductLog[a + b*x]]/Sqrt[c]])/(4*b) + (c*(a + b*x))/(2*b*Sqrt[(-c)*ProductLog[a + b*x]]) + ((a + b*x)*Sqrt[(-c)*ProductLog[a + b*x]])/b}
{1/Sqrt[-c*ProductLog[a+b*x]], x, 2, -((Sqrt[Pi]*Erf[Sqrt[(-c)*ProductLog[a + b*x]]/Sqrt[c]])/(2*b*Sqrt[c])) + (a + b*x)/(b*Sqrt[(-c)*ProductLog[a + b*x]])}
{1/(-c*ProductLog[a+b*x])^(3/2), x, 2, (3*Sqrt[Pi]*Erf[Sqrt[(-c)*ProductLog[a + b*x]]/Sqrt[c]])/(b*c^(3/2)) - (2*(a + b*x))/(b*((-c)*ProductLog[a + b*x])^(3/2))}
{1/(-c*ProductLog[a+b*x])^(5/2), x, 3, -((10*Sqrt[Pi]*Erf[Sqrt[(-c)*ProductLog[a + b*x]]/Sqrt[c]])/(3*b*c^(5/2))) - (2*(a + b*x))/(3*b*((-c)*ProductLog[a + b*x])^(5/2)) + (10*(a + b*x))/(3*b*c*((-c)*ProductLog[a + b*x])^(3/2))}
{1/(-c*ProductLog[a+b*x])^(7/2), x, 4, (28*Sqrt[Pi]*Erf[Sqrt[(-c)*ProductLog[a + b*x]]/Sqrt[c]])/(15*b*c^(7/2)) - (2*(a + b*x))/(5*b*((-c)*ProductLog[a + b*x])^(7/2)) + (14*(a + b*x))/(15*b*c*((-c)*ProductLog[a + b*x])^(5/2)) - (28*(a + b*x))/(15*b*c^2*((-c)*ProductLog[a + b*x])^(3/2))}


{(c*ProductLog[a + b*x])^n, x, 2, ((a + b*x)*(c*ProductLog[a + b*x])^n)/b - (n*Gamma[1 + n, -ProductLog[a + b*x]]*(c*ProductLog[a + b*x])^n)/((-ProductLog[a + b*x])^n*b)}


(* ::Subsubsection::Closed:: *)
(*x^m ProductLog[a+b x]^n*)


{x^3*ProductLog[a + b*x], x, 20, (a^3*(a + b*x))/b^4 - (3*a^2*(a + b*x)^2)/(4*b^4) + (a*(a + b*x)^3)/(3*b^4) - (a + b*x)^4/(16*b^4) - (3*(a + b*x)^4)/(512*b^4*ProductLog[a + b*x]^4) - (2*a*(a + b*x)^3)/(27*b^4*ProductLog[a + b*x]^3) + (3*(a + b*x)^4)/(128*b^4*ProductLog[a + b*x]^3) - (3*a^2*(a + b*x)^2)/(8*b^4*ProductLog[a + b*x]^2) + (2*a*(a + b*x)^3)/(9*b^4*ProductLog[a + b*x]^2) - (3*(a + b*x)^4)/(64*b^4*ProductLog[a + b*x]^2) - (a^3*(a + b*x))/(b^4*ProductLog[a + b*x]) + (3*a^2*(a + b*x)^2)/(4*b^4*ProductLog[a + b*x]) - (a*(a + b*x)^3)/(3*b^4*ProductLog[a + b*x]) + (a + b*x)^4/(16*b^4*ProductLog[a + b*x]) - (a^3*(a + b*x)*ProductLog[a + b*x])/b^4 + (3*a^2*(a + b*x)^2*ProductLog[a + b*x])/(2*b^4) - (a*(a + b*x)^3*ProductLog[a + b*x])/b^4 + ((a + b*x)^4*ProductLog[a + b*x])/(4*b^4)}
{x^2*ProductLog[a + b*x], x, 14, -((a^2*(a + b*x))/b^3) + (a*(a + b*x)^2)/(2*b^3) - (a + b*x)^3/(9*b^3) + (2*(a + b*x)^3)/(81*b^3*ProductLog[a + b*x]^3) + (a*(a + b*x)^2)/(4*b^3*ProductLog[a + b*x]^2) - (2*(a + b*x)^3)/(27*b^3*ProductLog[a + b*x]^2) + (a^2*(a + b*x))/(b^3*ProductLog[a + b*x]) - (a*(a + b*x)^2)/(2*b^3*ProductLog[a + b*x]) + (a + b*x)^3/(9*b^3*ProductLog[a + b*x]) + (a^2*(a + b*x)*ProductLog[a + b*x])/b^3 - (a*(a + b*x)^2*ProductLog[a + b*x])/b^3 + ((a + b*x)^3*ProductLog[a + b*x])/(3*b^3)}
{x*ProductLog[a + b*x], x, 9, (a*(a + b*x))/b^2 - (a + b*x)^2/(4*b^2) - (a + b*x)^2/(8*b^2*ProductLog[a + b*x]^2) - (a*(a + b*x))/(b^2*ProductLog[a + b*x]) + (a + b*x)^2/(4*b^2*ProductLog[a + b*x]) - (a*(a + b*x)*ProductLog[a + b*x])/b^2 + ((a + b*x)^2*ProductLog[a + b*x])/(2*b^2)}
{ProductLog[a + b*x], x, 3, -x + (a + b*x)/(b*ProductLog[a + b*x]) + ((a + b*x)*ProductLog[a + b*x])/b}
{ProductLog[a + b*x]/x, x, 0, Int[ProductLog[a + b*x]/x, x]}
{ProductLog[a + b*x]/x^2, x, 0, Int[ProductLog[a + b*x]/x^2, x]}


{x^3*ProductLog[a + b*x]^2, x, 24, -((4*a^3*(a + b*x))/b^4) + (9*a^2*(a + b*x)^2)/(4*b^4) - (8*a*(a + b*x)^3)/(9*b^4) + (5*(a + b*x)^4)/(32*b^4) + (15*(a + b*x)^4)/(1024*b^4*ProductLog[a + b*x]^4) + (16*a*(a + b*x)^3)/(81*b^4*ProductLog[a + b*x]^3) - (15*(a + b*x)^4)/(256*b^4*ProductLog[a + b*x]^3) + (9*a^2*(a + b*x)^2)/(8*b^4*ProductLog[a + b*x]^2) - (16*a*(a + b*x)^3)/(27*b^4*ProductLog[a + b*x]^2) + (15*(a + b*x)^4)/(128*b^4*ProductLog[a + b*x]^2) + (4*a^3*(a + b*x))/(b^4*ProductLog[a + b*x]) - (9*a^2*(a + b*x)^2)/(4*b^4*ProductLog[a + b*x]) + (8*a*(a + b*x)^3)/(9*b^4*ProductLog[a + b*x]) - (5*(a + b*x)^4)/(32*b^4*ProductLog[a + b*x]) + (2*a^3*(a + b*x)*ProductLog[a + b*x])/b^4 - (3*a^2*(a + b*x)^2*ProductLog[a + b*x])/(2*b^4) + (2*a*(a + b*x)^3*ProductLog[a + b*x])/(3*b^4) - ((a + b*x)^4*ProductLog[a + b*x])/(8*b^4) - (a^3*(a + b*x)*ProductLog[a + b*x]^2)/b^4 + (3*a^2*(a + b*x)^2*ProductLog[a + b*x]^2)/(2*b^4) - (a*(a + b*x)^3*ProductLog[a + b*x]^2)/b^4 + ((a + b*x)^4*ProductLog[a + b*x]^2)/(4*b^4)}
{x^2*ProductLog[a + b*x]^2, x, 17, (4*a^2*(a + b*x))/b^3 - (3*a*(a + b*x)^2)/(2*b^3) + (8*(a + b*x)^3)/(27*b^3) - (16*(a + b*x)^3)/(243*b^3*ProductLog[a + b*x]^3) - (3*a*(a + b*x)^2)/(4*b^3*ProductLog[a + b*x]^2) + (16*(a + b*x)^3)/(81*b^3*ProductLog[a + b*x]^2) - (4*a^2*(a + b*x))/(b^3*ProductLog[a + b*x]) + (3*a*(a + b*x)^2)/(2*b^3*ProductLog[a + b*x]) - (8*(a + b*x)^3)/(27*b^3*ProductLog[a + b*x]) - (2*a^2*(a + b*x)*ProductLog[a + b*x])/b^3 + (a*(a + b*x)^2*ProductLog[a + b*x])/b^3 - (2*(a + b*x)^3*ProductLog[a + b*x])/(9*b^3) + (a^2*(a + b*x)*ProductLog[a + b*x]^2)/b^3 - (a*(a + b*x)^2*ProductLog[a + b*x]^2)/b^3 + ((a + b*x)^3*ProductLog[a + b*x]^2)/(3*b^3)}
{x*ProductLog[a + b*x]^2, x, 11, -((4*a*(a + b*x))/b^2) + (3*(a + b*x)^2)/(4*b^2) + (3*(a + b*x)^2)/(8*b^2*ProductLog[a + b*x]^2) + (4*a*(a + b*x))/(b^2*ProductLog[a + b*x]) - (3*(a + b*x)^2)/(4*b^2*ProductLog[a + b*x]) + (2*a*(a + b*x)*ProductLog[a + b*x])/b^2 - ((a + b*x)^2*ProductLog[a + b*x])/(2*b^2) - (a*(a + b*x)*ProductLog[a + b*x]^2)/b^2 + ((a + b*x)^2*ProductLog[a + b*x]^2)/(2*b^2)}
{ProductLog[a + b*x]^2, x, 4, 4*x - (4*(a + b*x))/(b*ProductLog[a + b*x]) - (2*(a + b*x)*ProductLog[a + b*x])/b + ((a + b*x)*ProductLog[a + b*x]^2)/b}
{ProductLog[a + b*x]^2/x, x, 0, Int[ProductLog[a + b*x]^2/x, x]}
{ProductLog[a + b*x]^2/x^2, x, 0, Int[ProductLog[a + b*x]^2/x^2, x]}


{x^3/Sqrt[c*ProductLog[a + b*x]], x, 16, -((a^3*Sqrt[Pi]*Erfi[Sqrt[c*ProductLog[a + b*x]]/Sqrt[c]])/(2*b^4*Sqrt[c])) - (15*Sqrt[Pi]*Erfi[(2*Sqrt[c*ProductLog[a + b*x]])/Sqrt[c]])/(8192*b^4*Sqrt[c]) - (3*a^2*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[c*ProductLog[a + b*x]])/Sqrt[c]])/(16*b^4*Sqrt[c]) - (a*Sqrt[Pi/3]*Erfi[(Sqrt[3]*Sqrt[c*ProductLog[a + b*x]])/Sqrt[c]])/(24*b^4*Sqrt[c]) + (15*c^3*(a + b*x)^4)/(2048*b^4*(c*ProductLog[a + b*x])^(7/2)) + (a*c^2*(a + b*x)^3)/(12*b^4*(c*ProductLog[a + b*x])^(5/2)) - (5*c^2*(a + b*x)^4)/(256*b^4*(c*ProductLog[a + b*x])^(5/2)) + (3*a^2*c*(a + b*x)^2)/(8*b^4*(c*ProductLog[a + b*x])^(3/2)) - (a*c*(a + b*x)^3)/(6*b^4*(c*ProductLog[a + b*x])^(3/2)) + (c*(a + b*x)^4)/(32*b^4*(c*ProductLog[a + b*x])^(3/2)) - (a^3*(a + b*x))/(b^4*Sqrt[c*ProductLog[a + b*x]]) + (3*a^2*(a + b*x)^2)/(2*b^4*Sqrt[c*ProductLog[a + b*x]]) - (a*(a + b*x)^3)/(b^4*Sqrt[c*ProductLog[a + b*x]]) + (a + b*x)^4/(4*b^4*Sqrt[c*ProductLog[a + b*x]])}
{x^2/Sqrt[c*ProductLog[a + b*x]], x, 11, (a^2*Sqrt[Pi]*Erfi[Sqrt[c*ProductLog[a + b*x]]/Sqrt[c]])/(2*b^3*Sqrt[c]) + (a*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[c*ProductLog[a + b*x]])/Sqrt[c]])/(8*b^3*Sqrt[c]) + (Sqrt[Pi/3]*Erfi[(Sqrt[3]*Sqrt[c*ProductLog[a + b*x]])/Sqrt[c]])/(72*b^3*Sqrt[c]) - (c^2*(a + b*x)^3)/(36*b^3*(c*ProductLog[a + b*x])^(5/2)) - (a*c*(a + b*x)^2)/(4*b^3*(c*ProductLog[a + b*x])^(3/2)) + (c*(a + b*x)^3)/(18*b^3*(c*ProductLog[a + b*x])^(3/2)) + (a^2*(a + b*x))/(b^3*Sqrt[c*ProductLog[a + b*x]]) - (a*(a + b*x)^2)/(b^3*Sqrt[c*ProductLog[a + b*x]]) + (a + b*x)^3/(3*b^3*Sqrt[c*ProductLog[a + b*x]])}
{x/Sqrt[c*ProductLog[a + b*x]], x, 7, -((a*Sqrt[Pi]*Erfi[Sqrt[c*ProductLog[a + b*x]]/Sqrt[c]])/(2*b^2*Sqrt[c])) - (Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[c*ProductLog[a + b*x]])/Sqrt[c]])/(16*b^2*Sqrt[c]) + (c*(a + b*x)^2)/(8*b^2*(c*ProductLog[a + b*x])^(3/2)) - (a*(a + b*x))/(b^2*Sqrt[c*ProductLog[a + b*x]]) + (a + b*x)^2/(2*b^2*Sqrt[c*ProductLog[a + b*x]])}
{1/Sqrt[c*ProductLog[a + b*x]], x, 2, (Sqrt[Pi]*Erfi[Sqrt[c*ProductLog[a + b*x]]/Sqrt[c]])/(2*b*Sqrt[c]) + (a + b*x)/(b*Sqrt[c*ProductLog[a + b*x]])}
{1/Sqrt[c*ProductLog[a + b*x]]/x, x, 2, (Int[1/(x*Sqrt[ProductLog[a + b*x]]), x]*Sqrt[ProductLog[a + b*x]])/Sqrt[c*ProductLog[a + b*x]]}
{1/Sqrt[c*ProductLog[a + b*x]]/x^2, x, 2, (Int[1/(x^2*Sqrt[ProductLog[a + b*x]]), x]*Sqrt[ProductLog[a + b*x]])/Sqrt[c*ProductLog[a + b*x]]}


{x^3/Sqrt[-c*ProductLog[a + b*x]], x, 16, (a^3*Sqrt[Pi]*Erf[Sqrt[(-c)*ProductLog[a + b*x]]/Sqrt[c]])/(2*b^4*Sqrt[c]) + (15*Sqrt[Pi]*Erf[(2*Sqrt[(-c)*ProductLog[a + b*x]])/Sqrt[c]])/(8192*b^4*Sqrt[c]) + (3*a^2*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[(-c)*ProductLog[a + b*x]])/Sqrt[c]])/(16*b^4*Sqrt[c]) + (a*Sqrt[Pi/3]*Erf[(Sqrt[3]*Sqrt[(-c)*ProductLog[a + b*x]])/Sqrt[c]])/(24*b^4*Sqrt[c]) - (15*c^3*(a + b*x)^4)/(2048*b^4*((-c)*ProductLog[a + b*x])^(7/2)) + (a*c^2*(a + b*x)^3)/(12*b^4*((-c)*ProductLog[a + b*x])^(5/2)) - (5*c^2*(a + b*x)^4)/(256*b^4*((-c)*ProductLog[a + b*x])^(5/2)) - (3*a^2*c*(a + b*x)^2)/(8*b^4*((-c)*ProductLog[a + b*x])^(3/2)) + (a*c*(a + b*x)^3)/(6*b^4*((-c)*ProductLog[a + b*x])^(3/2)) - (c*(a + b*x)^4)/(32*b^4*((-c)*ProductLog[a + b*x])^(3/2)) - (a^3*(a + b*x))/(b^4*Sqrt[(-c)*ProductLog[a + b*x]]) + (3*a^2*(a + b*x)^2)/(2*b^4*Sqrt[(-c)*ProductLog[a + b*x]]) - (a*(a + b*x)^3)/(b^4*Sqrt[(-c)*ProductLog[a + b*x]]) + (a + b*x)^4/(4*b^4*Sqrt[(-c)*ProductLog[a + b*x]])}
{x^2/Sqrt[-c*ProductLog[a + b*x]], x, 11, -((a^2*Sqrt[Pi]*Erf[Sqrt[(-c)*ProductLog[a + b*x]]/Sqrt[c]])/(2*b^3*Sqrt[c])) - (a*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[(-c)*ProductLog[a + b*x]])/Sqrt[c]])/(8*b^3*Sqrt[c]) - (Sqrt[Pi/3]*Erf[(Sqrt[3]*Sqrt[(-c)*ProductLog[a + b*x]])/Sqrt[c]])/(72*b^3*Sqrt[c]) - (c^2*(a + b*x)^3)/(36*b^3*((-c)*ProductLog[a + b*x])^(5/2)) + (a*c*(a + b*x)^2)/(4*b^3*((-c)*ProductLog[a + b*x])^(3/2)) - (c*(a + b*x)^3)/(18*b^3*((-c)*ProductLog[a + b*x])^(3/2)) + (a^2*(a + b*x))/(b^3*Sqrt[(-c)*ProductLog[a + b*x]]) - (a*(a + b*x)^2)/(b^3*Sqrt[(-c)*ProductLog[a + b*x]]) + (a + b*x)^3/(3*b^3*Sqrt[(-c)*ProductLog[a + b*x]])}
{x/Sqrt[-c*ProductLog[a + b*x]], x, 7, (a*Sqrt[Pi]*Erf[Sqrt[(-c)*ProductLog[a + b*x]]/Sqrt[c]])/(2*b^2*Sqrt[c]) + (Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[(-c)*ProductLog[a + b*x]])/Sqrt[c]])/(16*b^2*Sqrt[c]) - (c*(a + b*x)^2)/(8*b^2*((-c)*ProductLog[a + b*x])^(3/2)) - (a*(a + b*x))/(b^2*Sqrt[(-c)*ProductLog[a + b*x]]) + (a + b*x)^2/(2*b^2*Sqrt[(-c)*ProductLog[a + b*x]])}
{1/Sqrt[-c*ProductLog[a + b*x]], x, 2, -((Sqrt[Pi]*Erf[Sqrt[(-c)*ProductLog[a + b*x]]/Sqrt[c]])/(2*b*Sqrt[c])) + (a + b*x)/(b*Sqrt[(-c)*ProductLog[a + b*x]])}
{1/Sqrt[-c*ProductLog[a + b*x]]/x, x, 2, (Int[1/(x*Sqrt[ProductLog[a + b*x]]), x]*Sqrt[ProductLog[a + b*x]])/Sqrt[(-c)*ProductLog[a + b*x]]}
{1/Sqrt[-c*ProductLog[a + b*x]]/x^2, x, 2, (Int[1/(x^2*Sqrt[ProductLog[a + b*x]]), x]*Sqrt[ProductLog[a + b*x]])/Sqrt[(-c)*ProductLog[a + b*x]]}


{x^3*Sqrt[c*ProductLog[a + b*x]], x, 20, -((a^3*Sqrt[c]*Sqrt[Pi]*Erfi[Sqrt[c*ProductLog[a + b*x]]/Sqrt[c]])/(4*b^4)) - (105*Sqrt[c]*Sqrt[Pi]*Erfi[(2*Sqrt[c*ProductLog[a + b*x]])/Sqrt[c]])/(65536*b^4) - (9*a^2*Sqrt[c]*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[c*ProductLog[a + b*x]])/Sqrt[c]])/(64*b^4) - (5*a*Sqrt[c]*Sqrt[Pi/3]*Erfi[(Sqrt[3]*Sqrt[c*ProductLog[a + b*x]])/Sqrt[c]])/(144*b^4) + (105*c^4*(a + b*x)^4)/(16384*b^4*(c*ProductLog[a + b*x])^(7/2)) + (5*a*c^3*(a + b*x)^3)/(72*b^4*(c*ProductLog[a + b*x])^(5/2)) - (35*c^3*(a + b*x)^4)/(2048*b^4*(c*ProductLog[a + b*x])^(5/2)) + (9*a^2*c^2*(a + b*x)^2)/(32*b^4*(c*ProductLog[a + b*x])^(3/2)) - (5*a*c^2*(a + b*x)^3)/(36*b^4*(c*ProductLog[a + b*x])^(3/2)) + (7*c^2*(a + b*x)^4)/(256*b^4*(c*ProductLog[a + b*x])^(3/2)) + (a^3*c*(a + b*x))/(2*b^4*Sqrt[c*ProductLog[a + b*x]]) - (3*a^2*c*(a + b*x)^2)/(8*b^4*Sqrt[c*ProductLog[a + b*x]]) + (a*c*(a + b*x)^3)/(6*b^4*Sqrt[c*ProductLog[a + b*x]]) - (c*(a + b*x)^4)/(32*b^4*Sqrt[c*ProductLog[a + b*x]]) - (a^3*(a + b*x)*Sqrt[c*ProductLog[a + b*x]])/b^4 + (3*a^2*(a + b*x)^2*Sqrt[c*ProductLog[a + b*x]])/(2*b^4) - (a*(a + b*x)^3*Sqrt[c*ProductLog[a + b*x]])/b^4 + ((a + b*x)^4*Sqrt[c*ProductLog[a + b*x]])/(4*b^4)}
{x^2*Sqrt[c*ProductLog[a + b*x]], x, 14, (a^2*Sqrt[c]*Sqrt[Pi]*Erfi[Sqrt[c*ProductLog[a + b*x]]/Sqrt[c]])/(4*b^3) + (3*a*Sqrt[c]*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[c*ProductLog[a + b*x]])/Sqrt[c]])/(32*b^3) + (5*Sqrt[c]*Sqrt[Pi/3]*Erfi[(Sqrt[3]*Sqrt[c*ProductLog[a + b*x]])/Sqrt[c]])/(432*b^3) - (5*c^3*(a + b*x)^3)/(216*b^3*(c*ProductLog[a + b*x])^(5/2)) - (3*a*c^2*(a + b*x)^2)/(16*b^3*(c*ProductLog[a + b*x])^(3/2)) + (5*c^2*(a + b*x)^3)/(108*b^3*(c*ProductLog[a + b*x])^(3/2)) - (a^2*c*(a + b*x))/(2*b^3*Sqrt[c*ProductLog[a + b*x]]) + (a*c*(a + b*x)^2)/(4*b^3*Sqrt[c*ProductLog[a + b*x]]) - (c*(a + b*x)^3)/(18*b^3*Sqrt[c*ProductLog[a + b*x]]) + (a^2*(a + b*x)*Sqrt[c*ProductLog[a + b*x]])/b^3 - (a*(a + b*x)^2*Sqrt[c*ProductLog[a + b*x]])/b^3 + ((a + b*x)^3*Sqrt[c*ProductLog[a + b*x]])/(3*b^3)}
{x*Sqrt[c*ProductLog[a + b*x]], x, 9, -((a*Sqrt[c]*Sqrt[Pi]*Erfi[Sqrt[c*ProductLog[a + b*x]]/Sqrt[c]])/(4*b^2)) - (3*Sqrt[c]*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[c*ProductLog[a + b*x]])/Sqrt[c]])/(64*b^2) + (3*c^2*(a + b*x)^2)/(32*b^2*(c*ProductLog[a + b*x])^(3/2)) + (a*c*(a + b*x))/(2*b^2*Sqrt[c*ProductLog[a + b*x]]) - (c*(a + b*x)^2)/(8*b^2*Sqrt[c*ProductLog[a + b*x]]) - (a*(a + b*x)*Sqrt[c*ProductLog[a + b*x]])/b^2 + ((a + b*x)^2*Sqrt[c*ProductLog[a + b*x]])/(2*b^2)}
{Sqrt[c*ProductLog[a + b*x]], x, 3, (Sqrt[c]*Sqrt[Pi]*Erfi[Sqrt[c*ProductLog[a + b*x]]/Sqrt[c]])/(4*b) - (c*(a + b*x))/(2*b*Sqrt[c*ProductLog[a + b*x]]) + ((a + b*x)*Sqrt[c*ProductLog[a + b*x]])/b}
{Sqrt[c*ProductLog[a + b*x]]/x, x, 2, (Int[Sqrt[ProductLog[a + b*x]]/x, x]*Sqrt[c*ProductLog[a + b*x]])/Sqrt[ProductLog[a + b*x]]}
{Sqrt[c*ProductLog[a + b*x]]/x^2, x, 2, (Int[Sqrt[ProductLog[a + b*x]]/x^2, x]*Sqrt[c*ProductLog[a + b*x]])/Sqrt[ProductLog[a + b*x]]}


(* ::Subsubsection::Closed:: *)
(*x^m / (1+ProductLog[a+b x])*)
(**)


{x^3/(d + d*ProductLog[a + b*x]), x, 12, -((3*(a + b*x)^4)/(128*b^4*d*ProductLog[a + b*x]^4)) - (2*a*(a + b*x)^3)/(9*b^4*d*ProductLog[a + b*x]^3) + (3*(a + b*x)^4)/(32*b^4*d*ProductLog[a + b*x]^3) - (3*a^2*(a + b*x)^2)/(4*b^4*d*ProductLog[a + b*x]^2) + (2*a*(a + b*x)^3)/(3*b^4*d*ProductLog[a + b*x]^2) - (3*(a + b*x)^4)/(16*b^4*d*ProductLog[a + b*x]^2) - (a^3*(a + b*x))/(b^4*d*ProductLog[a + b*x]) + (3*a^2*(a + b*x)^2)/(2*b^4*d*ProductLog[a + b*x]) - (a*(a + b*x)^3)/(b^4*d*ProductLog[a + b*x]) + (a + b*x)^4/(4*b^4*d*ProductLog[a + b*x])}
{x^2/(d + d*ProductLog[a + b*x]), x, 8, (2*(a + b*x)^3)/(27*b^3*d*ProductLog[a + b*x]^3) + (a*(a + b*x)^2)/(2*b^3*d*ProductLog[a + b*x]^2) - (2*(a + b*x)^3)/(9*b^3*d*ProductLog[a + b*x]^2) + (a^2*(a + b*x))/(b^3*d*ProductLog[a + b*x]) - (a*(a + b*x)^2)/(b^3*d*ProductLog[a + b*x]) + (a + b*x)^3/(3*b^3*d*ProductLog[a + b*x])}
{x/(d + d*ProductLog[a + b*x]), x, 5, -((a + b*x)^2/(4*b^2*d*ProductLog[a + b*x]^2)) - (a*(a + b*x))/(b^2*d*ProductLog[a + b*x]) + (a + b*x)^2/(2*b^2*d*ProductLog[a + b*x])}
{1/(d + d*ProductLog[a + b*x]), x, 1, (a + b*x)/(b*d*ProductLog[a + b*x])}
{1/(x*(d + d*ProductLog[a + b*x])), x, 2, Int[1/(x*(d + d*ProductLog[a + b*x])), x]}
{1/(x^2*(d + d*ProductLog[a + b*x])), x, 2, Int[1/(x^2*(d + d*ProductLog[a + b*x])), x]}


(* ::Subsection::Closed:: *)
(*Integrands involving ProductLog[a x^n]*)


(* ::Subsubsection::Closed:: *)
(*x^m ProductLog[a x]^p*)


{x^3*ProductLog[a*x], x, 6, -(x^4/16) - (3*x^4)/(512*ProductLog[a*x]^4) + (3*x^4)/(128*ProductLog[a*x]^3) - (3*x^4)/(64*ProductLog[a*x]^2) + x^4/(16*ProductLog[a*x]) + (1/4)*x^4*ProductLog[a*x]}
{x^2*ProductLog[a*x], x, 5, -(x^3/9) + (2*x^3)/(81*ProductLog[a*x]^3) - (2*x^3)/(27*ProductLog[a*x]^2) + x^3/(9*ProductLog[a*x]) + (1/3)*x^3*ProductLog[a*x]}
{x*ProductLog[a*x], x, 4, -(x^2/4) - x^2/(8*ProductLog[a*x]^2) + x^2/(4*ProductLog[a*x]) + (1/2)*x^2*ProductLog[a*x]}
{ProductLog[a*x], x, 3, -x + x/ProductLog[a*x] + x*ProductLog[a*x]}
{ProductLog[a*x]/x, x, 2, ProductLog[a*x] + (1/2)*ProductLog[a*x]^2}
{ProductLog[a*x]/x^2, x, 2, a*ExpIntegralEi[-ProductLog[a*x]] - ProductLog[a*x]/x}
{ProductLog[a*x]/x^3, x, 2, (-a^2)*ExpIntegralEi[-2*ProductLog[a*x]] - ProductLog[a*x]/x^2}
{ProductLog[a*x]/x^4, x, 3, (3/2)*a^3*ExpIntegralEi[-3*ProductLog[a*x]] - ProductLog[a*x]/(2*x^3) + ProductLog[a*x]^2/(2*x^3)}
{ProductLog[a*x]/x^5, x, 4, (-(8/3))*a^4*ExpIntegralEi[-4*ProductLog[a*x]] - ProductLog[a*x]/(3*x^4) + ProductLog[a*x]^2/(6*x^4) - (2*ProductLog[a*x]^3)/(3*x^4)}
{ProductLog[a*x]/x^6, x, 5, (125/24)*a^5*ExpIntegralEi[-5*ProductLog[a*x]] - ProductLog[a*x]/(4*x^5) + ProductLog[a*x]^2/(12*x^5) - (5*ProductLog[a*x]^3)/(24*x^5) + (25*ProductLog[a*x]^4)/(24*x^5)}


{x^2*ProductLog[a*x]^2, x, 6, (8*x^3)/27 - (16*x^3)/(243*ProductLog[a*x]^3) + (16*x^3)/(81*ProductLog[a*x]^2) - (8*x^3)/(27*ProductLog[a*x]) - (2/9)*x^3*ProductLog[a*x] + (1/3)*x^3*ProductLog[a*x]^2}
{x*ProductLog[a*x]^2, x, 5, (3*x^2)/4 + (3*x^2)/(8*ProductLog[a*x]^2) - (3*x^2)/(4*ProductLog[a*x]) - (1/2)*x^2*ProductLog[a*x] + (1/2)*x^2*ProductLog[a*x]^2}
{ProductLog[a*x]^2, x, 4, 4*x - (4*x)/ProductLog[a*x] - 2*x*ProductLog[a*x] + x*ProductLog[a*x]^2}
{ProductLog[a*x]^2/x, x, 2, (1/2)*ProductLog[a*x]^2 + (1/3)*ProductLog[a*x]^3}
{ProductLog[a*x]^2/x^2, x, 2, -((2*ProductLog[a*x])/x) - ProductLog[a*x]^2/x}
{ProductLog[a*x]^2/x^3, x, 2, a^2*ExpIntegralEi[-2*ProductLog[a*x]] - ProductLog[a*x]^2/(2*x^2)}
{ProductLog[a*x]^2/x^4, x, 2, -2*a^3*ExpIntegralEi[-3*ProductLog[a*x]] - ProductLog[a*x]^2/x^3}
{ProductLog[a*x]^2/x^5, x, 3, 4*a^4*ExpIntegralEi[-4*ProductLog[a*x]] - ProductLog[a*x]^2/(2*x^4) + ProductLog[a*x]^3/x^4}
{ProductLog[a*x]^2/x^6, x, 4, (-(25/3))*a^5*ExpIntegralEi[-5*ProductLog[a*x]] - ProductLog[a*x]^2/(3*x^5) + ProductLog[a*x]^3/(3*x^5) - (5*ProductLog[a*x]^4)/(3*x^5)}
{ProductLog[a*x]^2/x^7, x, 5, 18*a^6*ExpIntegralEi[-6*ProductLog[a*x]] - ProductLog[a*x]^2/(4*x^6) + ProductLog[a*x]^3/(6*x^6) - ProductLog[a*x]^4/(2*x^6) + (3*ProductLog[a*x]^5)/x^6}


{x^2*ProductLog[a*x]^3, x, 7, -((20*x^3)/27) + (40*x^3)/(243*ProductLog[a*x]^3) - (40*x^3)/(81*ProductLog[a*x]^2) + (20*x^3)/(27*ProductLog[a*x]) + (5/9)*x^3*ProductLog[a*x] - (1/3)*x^3*ProductLog[a*x]^2 + (1/3)*x^3*ProductLog[a*x]^3}
{x*ProductLog[a*x]^3, x, 6, -((9*x^2)/4) - (9*x^2)/(8*ProductLog[a*x]^2) + (9*x^2)/(4*ProductLog[a*x]) + (3/2)*x^2*ProductLog[a*x] - (3/4)*x^2*ProductLog[a*x]^2 + (1/2)*x^2*ProductLog[a*x]^3}
{ProductLog[a*x]^3, x, 5, -18*x + (18*x)/ProductLog[a*x] + 9*x*ProductLog[a*x] - 3*x*ProductLog[a*x]^2 + x*ProductLog[a*x]^3}
{ProductLog[a*x]^3/x, x, 2, (1/3)*ProductLog[a*x]^3 + (1/4)*ProductLog[a*x]^4}
{ProductLog[a*x]^3/x^2, x, 3, -((3*ProductLog[a*x])/x) - (3*ProductLog[a*x]^2)/x - ProductLog[a*x]^3/x}
{ProductLog[a*x]^3/x^3, x, 2, -((3*ProductLog[a*x]^2)/(4*x^2)) - ProductLog[a*x]^3/(2*x^2)}
{ProductLog[a*x]^3/x^4, x, 2, a^3*ExpIntegralEi[-3*ProductLog[a*x]] - ProductLog[a*x]^3/(3*x^3)}
{ProductLog[a*x]^3/x^5, x, 2, -3*a^4*ExpIntegralEi[-4*ProductLog[a*x]] - ProductLog[a*x]^3/x^4}
{ProductLog[a*x]^3/x^6, x, 3, (15/2)*a^5*ExpIntegralEi[-5*ProductLog[a*x]] - ProductLog[a*x]^3/(2*x^5) + (3*ProductLog[a*x]^4)/(2*x^5)}
{ProductLog[a*x]^3/x^7, x, 4, -18*a^6*ExpIntegralEi[-6*ProductLog[a*x]] - ProductLog[a*x]^3/(3*x^6) + ProductLog[a*x]^4/(2*x^6) - (3*ProductLog[a*x]^5)/x^6}
{ProductLog[a*x]^3/x^8, x, 5, (343/8)*a^7*ExpIntegralEi[-7*ProductLog[a*x]] - ProductLog[a*x]^3/(4*x^7) + ProductLog[a*x]^4/(4*x^7) - (7*ProductLog[a*x]^5)/(8*x^7) + (49*ProductLog[a*x]^6)/(8*x^7)}


{x^4/ProductLog[a*x], x, 5, -((6*x^5)/(3125*ProductLog[a*x]^5)) + (6*x^5)/(625*ProductLog[a*x]^4) - (3*x^5)/(125*ProductLog[a*x]^3) + x^5/(25*ProductLog[a*x]^2) + x^5/(5*ProductLog[a*x])}
{x^3/ProductLog[a*x], x, 4, x^4/(128*ProductLog[a*x]^4) - x^4/(32*ProductLog[a*x]^3) + x^4/(16*ProductLog[a*x]^2) + x^4/(4*ProductLog[a*x])}
{x^2/ProductLog[a*x], x, 3, -(x^3/(27*ProductLog[a*x]^3)) + x^3/(9*ProductLog[a*x]^2) + x^3/(3*ProductLog[a*x])}
{x/ProductLog[a*x], x, 2, x^2/(4*ProductLog[a*x]^2) + x^2/(2*ProductLog[a*x])}
{1/ProductLog[a*x], x, 2, ExpIntegralEi[ProductLog[a*x]]/a + x/ProductLog[a*x]}
{1/(x*ProductLog[a*x]), x, 2, Log[ProductLog[a*x]] - 1/ProductLog[a*x]}
{1/(x^2*ProductLog[a*x]), x, 3, -(1/(2*x)) - (1/2)*a*ExpIntegralEi[-ProductLog[a*x]] - 1/(2*x*ProductLog[a*x])}
{1/(x^3*ProductLog[a*x]), x, 4, -(1/(6*x^2)) + (2/3)*a^2*ExpIntegralEi[-2*ProductLog[a*x]] - 1/(3*x^2*ProductLog[a*x]) + ProductLog[a*x]/(3*x^2)}
{1/(x^4*ProductLog[a*x]), x, 5, -(1/(12*x^3)) - (9/8)*a^3*ExpIntegralEi[-3*ProductLog[a*x]] - 1/(4*x^3*ProductLog[a*x]) + ProductLog[a*x]/(8*x^3) - (3*ProductLog[a*x]^2)/(8*x^3)}


{x^5/ProductLog[a*x]^2, x, 5, -(x^6/(648*ProductLog[a*x]^6)) + x^6/(108*ProductLog[a*x]^5) - x^6/(36*ProductLog[a*x]^4) + x^6/(18*ProductLog[a*x]^3) + x^6/(6*ProductLog[a*x]^2)}
{x^4/ProductLog[a*x]^2, x, 4, (4*x^5)/(625*ProductLog[a*x]^5) - (4*x^5)/(125*ProductLog[a*x]^4) + (2*x^5)/(25*ProductLog[a*x]^3) + x^5/(5*ProductLog[a*x]^2)}
{x^3/ProductLog[a*x]^2, x, 3, -(x^4/(32*ProductLog[a*x]^4)) + x^4/(8*ProductLog[a*x]^3) + x^4/(4*ProductLog[a*x]^2)}
{x^2/ProductLog[a*x]^2, x, 2, (2*x^3)/(9*ProductLog[a*x]^3) + x^3/(3*ProductLog[a*x]^2)}
{x/ProductLog[a*x]^2, x, 2, ExpIntegralEi[2*ProductLog[a*x]]/a^2 + x^2/(2*ProductLog[a*x]^2)}
{1/ProductLog[a*x]^2, x, 2, (2*ExpIntegralEi[ProductLog[a*x]])/a - x/ProductLog[a*x]^2}
{1/(x*ProductLog[a*x]^2), x, 2, -(1/(2*ProductLog[a*x]^2)) - 1/ProductLog[a*x]}
{1/(x^2*ProductLog[a*x]^2), x, 4, 1/(3*x) + (1/3)*a*ExpIntegralEi[-ProductLog[a*x]] - 1/(3*x*ProductLog[a*x]^2) - 1/(3*x*ProductLog[a*x])}
{1/(x^3*ProductLog[a*x]^2), x, 5, 1/(6*x^2) - (2/3)*a^2*ExpIntegralEi[-2*ProductLog[a*x]] - 1/(4*x^2*ProductLog[a*x]^2) - 1/(6*x^2*ProductLog[a*x]) - ProductLog[a*x]/(3*x^2)}


{x^6/ProductLog[a*x]^3, x, 5, -((18*x^7)/(16807*ProductLog[a*x]^7)) + (18*x^7)/(2401*ProductLog[a*x]^6) - (9*x^7)/(343*ProductLog[a*x]^5) + (3*x^7)/(49*ProductLog[a*x]^4) + x^7/(7*ProductLog[a*x]^3)}
{x^5/ProductLog[a*x]^3, x, 4, x^6/(216*ProductLog[a*x]^6) - x^6/(36*ProductLog[a*x]^5) + x^6/(12*ProductLog[a*x]^4) + x^6/(6*ProductLog[a*x]^3)}
{x^4/ProductLog[a*x]^3, x, 3, -((3*x^5)/(125*ProductLog[a*x]^5)) + (3*x^5)/(25*ProductLog[a*x]^4) + x^5/(5*ProductLog[a*x]^3)}
{x^3/ProductLog[a*x]^3, x, 2, (3*x^4)/(16*ProductLog[a*x]^4) + x^4/(4*ProductLog[a*x]^3)}
{x^2/ProductLog[a*x]^3, x, 2, ExpIntegralEi[3*ProductLog[a*x]]/a^3 + x^3/(3*ProductLog[a*x]^3)}
{x/ProductLog[a*x]^3, x, 2, (3*ExpIntegralEi[2*ProductLog[a*x]])/a^2 - x^2/ProductLog[a*x]^3}
{1/ProductLog[a*x]^3, x, 3, (3*ExpIntegralEi[ProductLog[a*x]])/(2*a) - x/(2*ProductLog[a*x]^3) - (3*x)/(2*ProductLog[a*x]^2)}
{1/(x*ProductLog[a*x]^3), x, 2, -(1/(3*ProductLog[a*x]^3)) - 1/(2*ProductLog[a*x]^2)}
{1/(x^2*ProductLog[a*x]^3), x, 5, -(1/(8*x)) - (1/8)*a*ExpIntegralEi[-ProductLog[a*x]] - 1/(4*x*ProductLog[a*x]^3) - 1/(4*x*ProductLog[a*x]^2) + 1/(8*x*ProductLog[a*x])}
{1/(x^3*ProductLog[a*x]^3), x, 6, -(1/(10*x^2)) + (2/5)*a^2*ExpIntegralEi[-2*ProductLog[a*x]] - 1/(5*x^2*ProductLog[a*x]^3) - 3/(20*x^2*ProductLog[a*x]^2) + 1/(10*x^2*ProductLog[a*x]) + ProductLog[a*x]/(5*x^2)}


{x^3*Sqrt[c*ProductLog[a*x]], x, 6, -((105*Sqrt[c]*Sqrt[Pi]*Erfi[(2*Sqrt[c*ProductLog[a*x]])/Sqrt[c]])/(65536*a^4)) + (105*c^4*x^4)/(16384*(c*ProductLog[a*x])^(7/2)) - (35*c^3*x^4)/(2048*(c*ProductLog[a*x])^(5/2)) + (7*c^2*x^4)/(256*(c*ProductLog[a*x])^(3/2)) - (c*x^4)/(32*Sqrt[c*ProductLog[a*x]]) + (1/4)*x^4*Sqrt[c*ProductLog[a*x]]}
{x^2*Sqrt[c*ProductLog[a*x]], x, 5, (5*Sqrt[c]*Sqrt[Pi/3]*Erfi[(Sqrt[3]*Sqrt[c*ProductLog[a*x]])/Sqrt[c]])/(432*a^3) - (5*c^3*x^3)/(216*(c*ProductLog[a*x])^(5/2)) + (5*c^2*x^3)/(108*(c*ProductLog[a*x])^(3/2)) - (c*x^3)/(18*Sqrt[c*ProductLog[a*x]]) + (1/3)*x^3*Sqrt[c*ProductLog[a*x]]}
{x*Sqrt[c*ProductLog[a*x]], x, 4, -((3*Sqrt[c]*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[c*ProductLog[a*x]])/Sqrt[c]])/(64*a^2)) + (3*c^2*x^2)/(32*(c*ProductLog[a*x])^(3/2)) - (c*x^2)/(8*Sqrt[c*ProductLog[a*x]]) + (1/2)*x^2*Sqrt[c*ProductLog[a*x]]}
{Sqrt[c*ProductLog[a*x]], x, 3, (Sqrt[c]*Sqrt[Pi]*Erfi[Sqrt[c*ProductLog[a*x]]/Sqrt[c]])/(4*a) - (c*x)/(2*Sqrt[c*ProductLog[a*x]]) + x*Sqrt[c*ProductLog[a*x]]}
{Sqrt[c*ProductLog[a*x]]/x, x, 2, 2*Sqrt[c*ProductLog[a*x]] + (2*(c*ProductLog[a*x])^(3/2))/(3*c)}
{Sqrt[c*ProductLog[a*x]]/x^2, x, 2, (-a)*Sqrt[c]*Sqrt[Pi]*Erf[Sqrt[c*ProductLog[a*x]]/Sqrt[c]] - (2*Sqrt[c*ProductLog[a*x]])/x}
{Sqrt[c*ProductLog[a*x]]/x^3, x, 3, (2/3)*a^2*Sqrt[c]*Sqrt[2*Pi]*Erf[(Sqrt[2]*Sqrt[c*ProductLog[a*x]])/Sqrt[c]] - (2*Sqrt[c*ProductLog[a*x]])/(3*x^2) + (2*(c*ProductLog[a*x])^(3/2))/(3*c*x^2)}
{Sqrt[c*ProductLog[a*x]]/x^4, x, 4, (-(4/5))*a^3*Sqrt[c]*Sqrt[3*Pi]*Erf[(Sqrt[3]*Sqrt[c*ProductLog[a*x]])/Sqrt[c]] - (2*Sqrt[c*ProductLog[a*x]])/(5*x^3) + (2*(c*ProductLog[a*x])^(3/2))/(15*c*x^3) - (4*(c*ProductLog[a*x])^(5/2))/(5*c^2*x^3)}
{Sqrt[c*ProductLog[a*x]]/x^5, x, 5, (256/105)*a^4*Sqrt[c]*Sqrt[Pi]*Erf[(2*Sqrt[c*ProductLog[a*x]])/Sqrt[c]] - (2*Sqrt[c*ProductLog[a*x]])/(7*x^4) + (2*(c*ProductLog[a*x])^(3/2))/(35*c*x^4) - (16*(c*ProductLog[a*x])^(5/2))/(105*c^2*x^4) + (128*(c*ProductLog[a*x])^(7/2))/(105*c^3*x^4)}
{Sqrt[c*ProductLog[a*x]]/x^6, x, 6, (-(400/189))*a^5*Sqrt[c]*Sqrt[5*Pi]*Erf[(Sqrt[5]*Sqrt[c*ProductLog[a*x]])/Sqrt[c]] - (2*Sqrt[c*ProductLog[a*x]])/(9*x^5) + (2*(c*ProductLog[a*x])^(3/2))/(63*c*x^5) - (4*(c*ProductLog[a*x])^(5/2))/(63*c^2*x^5) + (40*(c*ProductLog[a*x])^(7/2))/(189*c^3*x^5) - (400*(c*ProductLog[a*x])^(9/2))/(189*c^4*x^5)}


{x^4/Sqrt[c*ProductLog[a*x]], x, 6, (21*Sqrt[Pi/5]*Erfi[(Sqrt[5]*Sqrt[c*ProductLog[a*x]])/Sqrt[c]])/(20000*a^5*Sqrt[c]) - (21*c^4*x^5)/(10000*(c*ProductLog[a*x])^(9/2)) + (7*c^3*x^5)/(1000*(c*ProductLog[a*x])^(7/2)) - (7*c^2*x^5)/(500*(c*ProductLog[a*x])^(5/2)) + (c*x^5)/(50*(c*ProductLog[a*x])^(3/2)) + x^5/(5*Sqrt[c*ProductLog[a*x]])}
{x^3/Sqrt[c*ProductLog[a*x]], x, 5, -((15*Sqrt[Pi]*Erfi[(2*Sqrt[c*ProductLog[a*x]])/Sqrt[c]])/(8192*a^4*Sqrt[c])) + (15*c^3*x^4)/(2048*(c*ProductLog[a*x])^(7/2)) - (5*c^2*x^4)/(256*(c*ProductLog[a*x])^(5/2)) + (c*x^4)/(32*(c*ProductLog[a*x])^(3/2)) + x^4/(4*Sqrt[c*ProductLog[a*x]])}
{x^2/Sqrt[c*ProductLog[a*x]], x, 4, (Sqrt[Pi/3]*Erfi[(Sqrt[3]*Sqrt[c*ProductLog[a*x]])/Sqrt[c]])/(72*a^3*Sqrt[c]) - (c^2*x^3)/(36*(c*ProductLog[a*x])^(5/2)) + (c*x^3)/(18*(c*ProductLog[a*x])^(3/2)) + x^3/(3*Sqrt[c*ProductLog[a*x]])}
{x/Sqrt[c*ProductLog[a*x]], x, 3, -((Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[c*ProductLog[a*x]])/Sqrt[c]])/(16*a^2*Sqrt[c])) + (c*x^2)/(8*(c*ProductLog[a*x])^(3/2)) + x^2/(2*Sqrt[c*ProductLog[a*x]])}
{1/Sqrt[c*ProductLog[a*x]], x, 2, (Sqrt[Pi]*Erfi[Sqrt[c*ProductLog[a*x]]/Sqrt[c]])/(2*a*Sqrt[c]) + x/Sqrt[c*ProductLog[a*x]]}
{1/(x*Sqrt[c*ProductLog[a*x]]), x, 2, -(2/Sqrt[c*ProductLog[a*x]]) + (2*Sqrt[c*ProductLog[a*x]])/c}
{1/(x^2*Sqrt[c*ProductLog[a*x]]), x, 3, -((2*a*Sqrt[Pi]*Erf[Sqrt[c*ProductLog[a*x]]/Sqrt[c]])/(3*Sqrt[c])) - 2/(3*x*Sqrt[c*ProductLog[a*x]]) - (2*Sqrt[c*ProductLog[a*x]])/(3*c*x)}
{1/(x^3*Sqrt[c*ProductLog[a*x]]), x, 4, (8*a^2*Sqrt[2*Pi]*Erf[(Sqrt[2]*Sqrt[c*ProductLog[a*x]])/Sqrt[c]])/(15*Sqrt[c]) - 2/(5*x^2*Sqrt[c*ProductLog[a*x]]) - (2*Sqrt[c*ProductLog[a*x]])/(15*c*x^2) + (8*(c*ProductLog[a*x])^(3/2))/(15*c^2*x^2)}
{1/(x^4*Sqrt[c*ProductLog[a*x]]), x, 5, -((24*a^3*Sqrt[3*Pi]*Erf[(Sqrt[3]*Sqrt[c*ProductLog[a*x]])/Sqrt[c]])/(35*Sqrt[c])) - 2/(7*x^3*Sqrt[c*ProductLog[a*x]]) - (2*Sqrt[c*ProductLog[a*x]])/(35*c*x^3) + (4*(c*ProductLog[a*x])^(3/2))/(35*c^2*x^3) - (24*(c*ProductLog[a*x])^(5/2))/(35*c^3*x^3)}
{1/(x^5*Sqrt[c*ProductLog[a*x]]), x, 6, (2048*a^4*Sqrt[Pi]*Erf[(2*Sqrt[c*ProductLog[a*x]])/Sqrt[c]])/(945*Sqrt[c]) - 2/(9*x^4*Sqrt[c*ProductLog[a*x]]) - (2*Sqrt[c*ProductLog[a*x]])/(63*c*x^4) + (16*(c*ProductLog[a*x])^(3/2))/(315*c^2*x^4) - (128*(c*ProductLog[a*x])^(5/2))/(945*c^3*x^4) + (1024*(c*ProductLog[a*x])^(7/2))/(945*c^4*x^4)}


{x^2*(c*ProductLog[a*x])^p, x, 3, (3^(-3 - p)*x^2*Gamma[3 + p, -3*ProductLog[a*x]]*(-ProductLog[a*x])^(-2 - p)*(c*ProductLog[a*x])^p)/(E^(2*ProductLog[a*x])*a) + (3^(-4 - p)*x^2*Gamma[4 + p, -3*ProductLog[a*x]]*(-ProductLog[a*x])^(-3 - p)*(c*ProductLog[a*x])^(1 + p))/(E^(2*ProductLog[a*x])*(a*c))}
{x*(c*ProductLog[a*x])^p, x, 3, (2^(-2 - p)*x*Gamma[2 + p, -2*ProductLog[a*x]]*(-ProductLog[a*x])^(-1 - p)*(c*ProductLog[a*x])^p)/(E^ProductLog[a*x]*a) + (2^(-3 - p)*x*Gamma[3 + p, -2*ProductLog[a*x]]*(-ProductLog[a*x])^(-2 - p)*(c*ProductLog[a*x])^(1 + p))/(E^ProductLog[a*x]*(a*c))}
{(c*ProductLog[a*x])^p/x, x, 2, (c*ProductLog[a*x])^p/p + (c*ProductLog[a*x])^(1 + p)/(c*(1 + p))}
{(c*ProductLog[a*x])^p/x^2, x, 3, -((E^(2*ProductLog[a*x])*Gamma[-1 + p, ProductLog[a*x]]*ProductLog[a*x]^(2 - p)*(c*ProductLog[a*x])^p)/(a*x^2)) - (E^(2*ProductLog[a*x])*Gamma[p, ProductLog[a*x]]*ProductLog[a*x]^(1 - p)*(c*ProductLog[a*x])^(1 + p))/(a*c*x^2)}
{(c*ProductLog[a*x])^p/x^3, x, 3, -((2^(2 - p)*E^(3*ProductLog[a*x])*Gamma[-2 + p, 2*ProductLog[a*x]]*ProductLog[a*x]^(3 - p)*(c*ProductLog[a*x])^p)/(a*x^3)) - (2^(1 - p)*E^(3*ProductLog[a*x])*Gamma[-1 + p, 2*ProductLog[a*x]]*ProductLog[a*x]^(2 - p)*(c*ProductLog[a*x])^(1 + p))/(a*c*x^3)}


{x^m*ProductLog[a*x], x, 3, (x^m*Gamma[3 + m, -(1 + m)*ProductLog[a*x]]*ProductLog[a*x]^2*(-(1 + m)*ProductLog[a*x])^(-2 - m))/(E^(m*ProductLog[a*x])*(a*(1 + m))) + (x^m*Gamma[2 + m, -(1 + m)*ProductLog[a*x]]*ProductLog[a*x]*(-(1 + m)*ProductLog[a*x])^(-1 - m))/(E^(m*ProductLog[a*x])*(a*(1 + m)))}
{x^m*ProductLog[a*x]^2, x, 3, (x^m*Gamma[4 + m, -(1 + m)*ProductLog[a*x]]*ProductLog[a*x]^3*(-(1 + m)*ProductLog[a*x])^(-3 - m))/(E^(m*ProductLog[a*x])*(a*(1 + m))) + (x^m*Gamma[3 + m, -(1 + m)*ProductLog[a*x]]*ProductLog[a*x]^2*(-(1 + m)*ProductLog[a*x])^(-2 - m))/(E^(m*ProductLog[a*x])*(a*(1 + m)))}
{x^m/ProductLog[a*x], x, 3, (x^m*Gamma[m, -(1 + m)*ProductLog[a*x]]*(-(1 + m)*ProductLog[a*x])^(1 - m))/(E^(m*ProductLog[a*x])*(a*(1 + m)*ProductLog[a*x])) + (x^m*Gamma[1 + m, -(1 + m)*ProductLog[a*x]])/(E^(m*ProductLog[a*x])*(-(1 + m)*ProductLog[a*x])^m*(a*(1 + m)))}
{x^m/ProductLog[a*x]^2, x, 3, (x^m*Gamma[m, -(1 + m)*ProductLog[a*x]]*(-(1 + m)*ProductLog[a*x])^(1 - m))/(E^(m*ProductLog[a*x])*(a*(1 + m)*ProductLog[a*x])) + (x^m*Gamma[-1 + m, -(1 + m)*ProductLog[a*x]]*(-(1 + m)*ProductLog[a*x])^(2 - m))/(E^(m*ProductLog[a*x])*(a*(1 + m)*ProductLog[a*x]^2))}
{x^m*Sqrt[c*ProductLog[a*x]], x, 3, (x^m*Gamma[5/2 + m, -(1 + m)*ProductLog[a*x]]*(c*ProductLog[a*x])^(3/2)*(-(1 + m)*ProductLog[a*x])^(-(3/2) - m))/(E^(m*ProductLog[a*x])*(a*c*(1 + m))) + (x^m*Gamma[3/2 + m, -(1 + m)*ProductLog[a*x]]*Sqrt[c*ProductLog[a*x]]*(-(1 + m)*ProductLog[a*x])^(-(1/2) - m))/(E^(m*ProductLog[a*x])*(a*(1 + m)))}
{x^m/Sqrt[c*ProductLog[a*x]], x, 3, (x^m*Gamma[3/2 + m, -(1 + m)*ProductLog[a*x]]*Sqrt[c*ProductLog[a*x]]*(-(1 + m)*ProductLog[a*x])^(-(1/2) - m))/(E^(m*ProductLog[a*x])*(a*c*(1 + m))) + (x^m*Gamma[1/2 + m, -(1 + m)*ProductLog[a*x]]*(-(1 + m)*ProductLog[a*x])^(1/2 - m))/(E^(m*ProductLog[a*x])*(a*(1 + m)*Sqrt[c*ProductLog[a*x]]))}


{x^m*(c*ProductLog[a*x])^p, x, 3, (1/(a*c*(1 + m)))*((x^m*Gamma[2 + m + p, -(1 + m)*ProductLog[a*x]]*(c*ProductLog[a*x])^(1 + p)*(-(1 + m)*ProductLog[a*x])^(-1 - m - p))/E^(m*ProductLog[a*x])) + (1/(a*(1 + m)))*((x^m*Gamma[1 + m + p, -(1 + m)*ProductLog[a*x]]*(c*ProductLog[a*x])^p*(-(1 + m)*ProductLog[a*x])^(-m - p))/E^(m*ProductLog[a*x]))}


(* ::Subsubsection::Closed:: *)
(*x^m ProductLog[a x^2]^p*)


{x^4*ProductLog[a*x^2], x, 0, Int[x^4*ProductLog[a*x^2], x]}
{x^3*ProductLog[a*x^2], x, 5, -(x^4/8) - x^4/(16*ProductLog[a*x^2]^2) + x^4/(8*ProductLog[a*x^2]) + (1/4)*x^4*ProductLog[a*x^2]}
{x^2*ProductLog[a*x^2], x, 0, Int[x^2*ProductLog[a*x^2], x]}
{x*ProductLog[a*x^2], x, 4, -(x^2/2) + x^2/(2*ProductLog[a*x^2]) + (1/2)*x^2*ProductLog[a*x^2]}
{ProductLog[a*x^2], x, 0, Int[ProductLog[a*x^2], x]}
{ProductLog[a*x^2]/x, x, 2, (1/2)*ProductLog[a*x^2] + (1/4)*ProductLog[a*x^2]^2}
{ProductLog[a*x^2]/x^2, x, 0, Int[ProductLog[a*x^2]/x^2, x]}
{ProductLog[a*x^2]/x^3, x, 2, (1/2)*a*ExpIntegralEi[-ProductLog[a*x^2]] - ProductLog[a*x^2]/(2*x^2)}
{ProductLog[a*x^2]/x^4, x, 0, Int[ProductLog[a*x^2]/x^4, x]}
{ProductLog[a*x^2]/x^5, x, 2, (-(1/2))*a^2*ExpIntegralEi[-2*ProductLog[a*x^2]] - ProductLog[a*x^2]/(2*x^4)}
{ProductLog[a*x^2]/x^6, x, 0, Int[ProductLog[a*x^2]/x^6, x]}
{ProductLog[a*x^2]/x^7, x, 3, (3/4)*a^3*ExpIntegralEi[-3*ProductLog[a*x^2]] - ProductLog[a*x^2]/(4*x^6) + ProductLog[a*x^2]^2/(4*x^6)}


{x^3*ProductLog[a*x^2]^2, x, 6, (3*x^4)/8 + (3*x^4)/(16*ProductLog[a*x^2]^2) - (3*x^4)/(8*ProductLog[a*x^2]) - (1/4)*x^4*ProductLog[a*x^2] + (1/4)*x^4*ProductLog[a*x^2]^2}
{x^2*ProductLog[a*x^2]^2, x, 0, Int[x^2*ProductLog[a*x^2]^2, x]}
{x*ProductLog[a*x^2]^2, x, 5, 2*x^2 - (2*x^2)/ProductLog[a*x^2] - x^2*ProductLog[a*x^2] + (1/2)*x^2*ProductLog[a*x^2]^2}
{ProductLog[a*x^2]^2, x, 0, Int[ProductLog[a*x^2]^2, x]}
{ProductLog[a*x^2]^2/x, x, 2, (1/4)*ProductLog[a*x^2]^2 + (1/6)*ProductLog[a*x^2]^3}
{ProductLog[a*x^2]^2/x^2, x, 0, Int[ProductLog[a*x^2]^2/x^2, x]}
{ProductLog[a*x^2]^2/x^3, x, 2, -(ProductLog[a*x^2]/x^2) - ProductLog[a*x^2]^2/(2*x^2)}
{ProductLog[a*x^2]^2/x^4, x, 0, Int[ProductLog[a*x^2]^2/x^4, x]}
{ProductLog[a*x^2]^2/x^5, x, 2, (1/2)*a^2*ExpIntegralEi[-2*ProductLog[a*x^2]] - ProductLog[a*x^2]^2/(4*x^4)}
{ProductLog[a*x^2]^2/x^6, x, 0, Int[ProductLog[a*x^2]^2/x^6, x]}
{ProductLog[a*x^2]^2/x^7, x, 2, (-a^3)*ExpIntegralEi[-3*ProductLog[a*x^2]] - ProductLog[a*x^2]^2/(2*x^6)}
{ProductLog[a*x^2]^2/x^8, x, 0, Int[ProductLog[a*x^2]^2/x^8, x]}
{ProductLog[a*x^2]^2/x^9, x, 3, 2*a^4*ExpIntegralEi[-4*ProductLog[a*x^2]] - ProductLog[a*x^2]^2/(4*x^8) + ProductLog[a*x^2]^3/(2*x^8)}


{x^2*ProductLog[a*x^2]^3, x, 0, Int[x^2*ProductLog[a*x^2]^3, x]}
{x*ProductLog[a*x^2]^3, x, 6, -9*x^2 + (9*x^2)/ProductLog[a*x^2] + (9/2)*x^2*ProductLog[a*x^2] - (3/2)*x^2*ProductLog[a*x^2]^2 + (1/2)*x^2*ProductLog[a*x^2]^3}
{ProductLog[a*x^2]^3, x, 0, Int[ProductLog[a*x^2]^3, x]}
{ProductLog[a*x^2]^3/x, x, 2, (1/6)*ProductLog[a*x^2]^3 + (1/8)*ProductLog[a*x^2]^4}
{ProductLog[a*x^2]^3/x^2, x, 0, Int[ProductLog[a*x^2]^3/x^2, x]}
{ProductLog[a*x^2]^3/x^3, x, 3, -((3*ProductLog[a*x^2])/(2*x^2)) - (3*ProductLog[a*x^2]^2)/(2*x^2) - ProductLog[a*x^2]^3/(2*x^2)}
{ProductLog[a*x^2]^3/x^4, x, 0, Int[ProductLog[a*x^2]^3/x^4, x]}
{ProductLog[a*x^2]^3/x^5, x, 2, -((3*ProductLog[a*x^2]^2)/(8*x^4)) - ProductLog[a*x^2]^3/(4*x^4)}
{ProductLog[a*x^2]^3/x^6, x, 0, Int[ProductLog[a*x^2]^3/x^6, x]}
{ProductLog[a*x^2]^3/x^7, x, 2, (1/2)*a^3*ExpIntegralEi[-3*ProductLog[a*x^2]] - ProductLog[a*x^2]^3/(6*x^6)}
{ProductLog[a*x^2]^3/x^8, x, 0, Int[ProductLog[a*x^2]^3/x^8, x]}
{ProductLog[a*x^2]^3/x^9, x, 2, (-(3/2))*a^4*ExpIntegralEi[-4*ProductLog[a*x^2]] - ProductLog[a*x^2]^3/(2*x^8)}


{x^5/ProductLog[a*x^2], x, 3, -(x^6/(54*ProductLog[a*x^2]^3)) + x^6/(18*ProductLog[a*x^2]^2) + x^6/(6*ProductLog[a*x^2])}
{x^4/ProductLog[a*x^2], x, 0, Int[x^4/ProductLog[a*x^2], x]}
{x^3/ProductLog[a*x^2], x, 2, x^4/(8*ProductLog[a*x^2]^2) + x^4/(4*ProductLog[a*x^2])}
{x^2/ProductLog[a*x^2], x, 0, Int[x^2/ProductLog[a*x^2], x]}
{x/ProductLog[a*x^2], x, 2, ExpIntegralEi[ProductLog[a*x^2]]/(2*a) + x^2/(2*ProductLog[a*x^2])}
{1/ProductLog[a*x^2], x, 0, Int[1/ProductLog[a*x^2], x]}
{1/(x*ProductLog[a*x^2]), x, 2, (1/2)*Log[ProductLog[a*x^2]] - 1/(2*ProductLog[a*x^2])}
{1/(x^2*ProductLog[a*x^2]), x, 0, Int[1/(x^2*ProductLog[a*x^2]), x]}
{1/(x^3*ProductLog[a*x^2]), x, 4, -(1/(4*x^2)) - (1/4)*a*ExpIntegralEi[-ProductLog[a*x^2]] - 1/(4*x^2*ProductLog[a*x^2])}
{1/(x^4*ProductLog[a*x^2]), x, 0, Int[1/(x^4*ProductLog[a*x^2]), x]}
{1/(x^5*ProductLog[a*x^2]), x, 5, -(1/(12*x^4)) + (1/3)*a^2*ExpIntegralEi[-2*ProductLog[a*x^2]] - 1/(6*x^4*ProductLog[a*x^2]) + ProductLog[a*x^2]/(6*x^4)}


{x^7/ProductLog[a*x^2]^2, x, 3, -(x^8/(64*ProductLog[a*x^2]^4)) + x^8/(16*ProductLog[a*x^2]^3) + x^8/(8*ProductLog[a*x^2]^2)}
{x^6/ProductLog[a*x^2]^2, x, 0, Int[x^6/ProductLog[a*x^2]^2, x]}
{x^5/ProductLog[a*x^2]^2, x, 2, x^6/(9*ProductLog[a*x^2]^3) + x^6/(6*ProductLog[a*x^2]^2)}
{x^4/ProductLog[a*x^2]^2, x, 0, Int[x^4/ProductLog[a*x^2]^2, x]}
{x^3/ProductLog[a*x^2]^2, x, 2, ExpIntegralEi[2*ProductLog[a*x^2]]/(2*a^2) + x^4/(4*ProductLog[a*x^2]^2)}
{x^2/ProductLog[a*x^2]^2, x, 0, Int[x^2/ProductLog[a*x^2]^2, x]}
{x/ProductLog[a*x^2]^2, x, 2, ExpIntegralEi[ProductLog[a*x^2]]/a - x^2/(2*ProductLog[a*x^2]^2)}
{1/ProductLog[a*x^2]^2, x, 0, Int[1/ProductLog[a*x^2]^2, x]}
{1/(x*ProductLog[a*x^2]^2), x, 2, -(1/(4*ProductLog[a*x^2]^2)) - 1/(2*ProductLog[a*x^2])}
{1/(x^2*ProductLog[a*x^2]^2), x, 0, Int[1/(x^2*ProductLog[a*x^2]^2), x]}
{1/(x^3*ProductLog[a*x^2]^2), x, 5, 1/(6*x^2) + (1/6)*a*ExpIntegralEi[-ProductLog[a*x^2]] - 1/(6*x^2*ProductLog[a*x^2]^2) - 1/(6*x^2*ProductLog[a*x^2])}


{x^7*Sqrt[c*ProductLog[a*x^2]], x, 6, -((105*Sqrt[c]*Sqrt[Pi]*Erfi[(2*Sqrt[c*ProductLog[a*x^2]])/Sqrt[c]])/(131072*a^4)) + (105*c^4*x^8)/(32768*(c*ProductLog[a*x^2])^(7/2)) - (35*c^3*x^8)/(4096*(c*ProductLog[a*x^2])^(5/2)) + (7*c^2*x^8)/(512*(c*ProductLog[a*x^2])^(3/2)) - (c*x^8)/(64*Sqrt[c*ProductLog[a*x^2]]) + (1/8)*x^8*Sqrt[c*ProductLog[a*x^2]]}
{x^6*Sqrt[c*ProductLog[a*x^2]], x, 5, (48*c^4*x^7)/(16807*(c*ProductLog[a*x^2])^(7/2)) - (24*c^3*x^7)/(2401*(c*ProductLog[a*x^2])^(5/2)) + (6*c^2*x^7)/(343*(c*ProductLog[a*x^2])^(3/2)) - (c*x^7)/(49*Sqrt[c*ProductLog[a*x^2]]) + (1/7)*x^7*Sqrt[c*ProductLog[a*x^2]]}
{x^5*Sqrt[c*ProductLog[a*x^2]], x, 5, (5*Sqrt[c]*Sqrt[Pi/3]*Erfi[(Sqrt[3]*Sqrt[c*ProductLog[a*x^2]])/Sqrt[c]])/(864*a^3) - (5*c^3*x^6)/(432*(c*ProductLog[a*x^2])^(5/2)) + (5*c^2*x^6)/(216*(c*ProductLog[a*x^2])^(3/2)) - (c*x^6)/(36*Sqrt[c*ProductLog[a*x^2]]) + (1/6)*x^6*Sqrt[c*ProductLog[a*x^2]]}
{x^4*Sqrt[c*ProductLog[a*x^2]], x, 4, -((8*c^3*x^5)/(625*(c*ProductLog[a*x^2])^(5/2))) + (4*c^2*x^5)/(125*(c*ProductLog[a*x^2])^(3/2)) - (c*x^5)/(25*Sqrt[c*ProductLog[a*x^2]]) + (1/5)*x^5*Sqrt[c*ProductLog[a*x^2]]}
{x^3*Sqrt[c*ProductLog[a*x^2]], x, 4, -((3*Sqrt[c]*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[c*ProductLog[a*x^2]])/Sqrt[c]])/(128*a^2)) + (3*c^2*x^4)/(64*(c*ProductLog[a*x^2])^(3/2)) - (c*x^4)/(16*Sqrt[c*ProductLog[a*x^2]]) + (1/4)*x^4*Sqrt[c*ProductLog[a*x^2]]}
{x^2*Sqrt[c*ProductLog[a*x^2]], x, 3, (2*c^2*x^3)/(27*(c*ProductLog[a*x^2])^(3/2)) - (c*x^3)/(9*Sqrt[c*ProductLog[a*x^2]]) + (1/3)*x^3*Sqrt[c*ProductLog[a*x^2]]}
{x*Sqrt[c*ProductLog[a*x^2]], x, 3, (Sqrt[c]*Sqrt[Pi]*Erfi[Sqrt[c*ProductLog[a*x^2]]/Sqrt[c]])/(8*a) - (c*x^2)/(4*Sqrt[c*ProductLog[a*x^2]]) + (1/2)*x^2*Sqrt[c*ProductLog[a*x^2]]}
{Sqrt[c*ProductLog[a*x^2]], x, 2, -((c*x)/Sqrt[c*ProductLog[a*x^2]]) + x*Sqrt[c*ProductLog[a*x^2]]}
{Sqrt[c*ProductLog[a*x^2]]/x, x, 2, Sqrt[c*ProductLog[a*x^2]] + (c*ProductLog[a*x^2])^(3/2)/(3*c)}
{Sqrt[c*ProductLog[a*x^2]]/x^2, x, 2, (Int[Sqrt[ProductLog[a*x^2]]/x^2, x]*Sqrt[c*ProductLog[a*x^2]])/Sqrt[ProductLog[a*x^2]]}
{Sqrt[c*ProductLog[a*x^2]]/x^3, x, 2, (-(1/2))*a*Sqrt[c]*Sqrt[Pi]*Erf[Sqrt[c*ProductLog[a*x^2]]/Sqrt[c]] - Sqrt[c*ProductLog[a*x^2]]/x^2}
{Sqrt[c*ProductLog[a*x^2]]/x^4, x, 2, (Int[Sqrt[ProductLog[a*x^2]]/x^4, x]*Sqrt[c*ProductLog[a*x^2]])/Sqrt[ProductLog[a*x^2]]}
{Sqrt[c*ProductLog[a*x^2]]/x^5, x, 3, (1/3)*a^2*Sqrt[c]*Sqrt[2*Pi]*Erf[(Sqrt[2]*Sqrt[c*ProductLog[a*x^2]])/Sqrt[c]] - Sqrt[c*ProductLog[a*x^2]]/(3*x^4) + (c*ProductLog[a*x^2])^(3/2)/(3*c*x^4)}
{Sqrt[c*ProductLog[a*x^2]]/x^6, x, 2, (Int[Sqrt[ProductLog[a*x^2]]/x^6, x]*Sqrt[c*ProductLog[a*x^2]])/Sqrt[ProductLog[a*x^2]]}
{Sqrt[c*ProductLog[a*x^2]]/x^7, x, 4, (-(2/5))*a^3*Sqrt[c]*Sqrt[3*Pi]*Erf[(Sqrt[3]*Sqrt[c*ProductLog[a*x^2]])/Sqrt[c]] - Sqrt[c*ProductLog[a*x^2]]/(5*x^6) + (c*ProductLog[a*x^2])^(3/2)/(15*c*x^6) - (2*(c*ProductLog[a*x^2])^(5/2))/(5*c^2*x^6)}


{x^7/Sqrt[c*ProductLog[a*x^2]], x, 5, -((15*Sqrt[Pi]*Erfi[(2*Sqrt[c*ProductLog[a*x^2]])/Sqrt[c]])/(16384*a^4*Sqrt[c])) + (15*c^3*x^8)/(4096*(c*ProductLog[a*x^2])^(7/2)) - (5*c^2*x^8)/(512*(c*ProductLog[a*x^2])^(5/2)) + (c*x^8)/(64*(c*ProductLog[a*x^2])^(3/2)) + x^8/(8*Sqrt[c*ProductLog[a*x^2]])}
{x^6/Sqrt[c*ProductLog[a*x^2]], x, 4, (8*c^3*x^7)/(2401*(c*ProductLog[a*x^2])^(7/2)) - (4*c^2*x^7)/(343*(c*ProductLog[a*x^2])^(5/2)) + (c*x^7)/(49*(c*ProductLog[a*x^2])^(3/2)) + x^7/(7*Sqrt[c*ProductLog[a*x^2]])}
{x^5/Sqrt[c*ProductLog[a*x^2]], x, 4, (Sqrt[Pi/3]*Erfi[(Sqrt[3]*Sqrt[c*ProductLog[a*x^2]])/Sqrt[c]])/(144*a^3*Sqrt[c]) - (c^2*x^6)/(72*(c*ProductLog[a*x^2])^(5/2)) + (c*x^6)/(36*(c*ProductLog[a*x^2])^(3/2)) + x^6/(6*Sqrt[c*ProductLog[a*x^2]])}
{x^4/Sqrt[c*ProductLog[a*x^2]], x, 3, -((2*c^2*x^5)/(125*(c*ProductLog[a*x^2])^(5/2))) + (c*x^5)/(25*(c*ProductLog[a*x^2])^(3/2)) + x^5/(5*Sqrt[c*ProductLog[a*x^2]])}
{x^3/Sqrt[c*ProductLog[a*x^2]], x, 3, -((Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[c*ProductLog[a*x^2]])/Sqrt[c]])/(32*a^2*Sqrt[c])) + (c*x^4)/(16*(c*ProductLog[a*x^2])^(3/2)) + x^4/(4*Sqrt[c*ProductLog[a*x^2]])}
{x^2/Sqrt[c*ProductLog[a*x^2]], x, 2, (c*x^3)/(9*(c*ProductLog[a*x^2])^(3/2)) + x^3/(3*Sqrt[c*ProductLog[a*x^2]])}
{x/Sqrt[c*ProductLog[a*x^2]], x, 2, (Sqrt[Pi]*Erfi[Sqrt[c*ProductLog[a*x^2]]/Sqrt[c]])/(4*a*Sqrt[c]) + x^2/(2*Sqrt[c*ProductLog[a*x^2]])}
{1/Sqrt[c*ProductLog[a*x^2]], x, 2, (Int[1/Sqrt[ProductLog[a*x^2]], x]*Sqrt[ProductLog[a*x^2]])/Sqrt[c*ProductLog[a*x^2]]}
{1/(x*Sqrt[c*ProductLog[a*x^2]]), x, 2, -(1/Sqrt[c*ProductLog[a*x^2]]) + Sqrt[c*ProductLog[a*x^2]]/c}
{1/(x^2*Sqrt[c*ProductLog[a*x^2]]), x, 2, (Int[1/(x^2*Sqrt[ProductLog[a*x^2]]), x]*Sqrt[ProductLog[a*x^2]])/Sqrt[c*ProductLog[a*x^2]]}
{1/(x^3*Sqrt[c*ProductLog[a*x^2]]), x, 3, -((a*Sqrt[Pi]*Erf[Sqrt[c*ProductLog[a*x^2]]/Sqrt[c]])/(3*Sqrt[c])) - 1/(3*x^2*Sqrt[c*ProductLog[a*x^2]]) - Sqrt[c*ProductLog[a*x^2]]/(3*c*x^2)}
{1/(x^4*Sqrt[c*ProductLog[a*x^2]]), x, 2, (Int[1/(x^4*Sqrt[ProductLog[a*x^2]]), x]*Sqrt[ProductLog[a*x^2]])/Sqrt[c*ProductLog[a*x^2]]}
{1/(x^5*Sqrt[c*ProductLog[a*x^2]]), x, 4, (4*a^2*Sqrt[2*Pi]*Erf[(Sqrt[2]*Sqrt[c*ProductLog[a*x^2]])/Sqrt[c]])/(15*Sqrt[c]) - 1/(5*x^4*Sqrt[c*ProductLog[a*x^2]]) - Sqrt[c*ProductLog[a*x^2]]/(15*c*x^4) + (4*(c*ProductLog[a*x^2])^(3/2))/(15*c^2*x^4)}
{1/(x^6*Sqrt[c*ProductLog[a*x^2]]), x, 2, (Int[1/(x^6*Sqrt[ProductLog[a*x^2]]), x]*Sqrt[ProductLog[a*x^2]])/Sqrt[c*ProductLog[a*x^2]]}
{1/(x^7*Sqrt[c*ProductLog[a*x^2]]), x, 5, -((12*a^3*Sqrt[3*Pi]*Erf[(Sqrt[3]*Sqrt[c*ProductLog[a*x^2]])/Sqrt[c]])/(35*Sqrt[c])) - 1/(7*x^6*Sqrt[c*ProductLog[a*x^2]]) - Sqrt[c*ProductLog[a*x^2]]/(35*c*x^6) + (2*(c*ProductLog[a*x^2])^(3/2))/(35*c^2*x^6) - (12*(c*ProductLog[a*x^2])^(5/2))/(35*c^3*x^6)}


{x^2*(c*ProductLog[a*x^2])^p, x, 0, Int[x^2*(c*ProductLog[a*x^2])^p, x]}
{x*(c*ProductLog[a*x^2])^p, x, 3, (1/2)*x^2*(c*ProductLog[a*x^2])^p - (p*Gamma[1 + p, -ProductLog[a*x^2]]*(c*ProductLog[a*x^2])^p)/((-ProductLog[a*x^2])^p*(2*a))}
{(c*ProductLog[a*x^2])^p/x, x, 2, (c*ProductLog[a*x^2])^p/(2*p) + (c*ProductLog[a*x^2])^(1 + p)/(2*c*(1 + p))}
{(c*ProductLog[a*x^2])^p/x^2, x, 0, Int[(c*ProductLog[a*x^2])^p/x^2, x]}
{(c*ProductLog[a*x^2])^p/x^3, x, 4, -((E^(2*ProductLog[a*x^2])*Gamma[-1 + p, ProductLog[a*x^2]]*ProductLog[a*x^2]^(2 - p)*(c*ProductLog[a*x^2])^p)/(2*a*x^4)) - (E^(2*ProductLog[a*x^2])*Gamma[p, ProductLog[a*x^2]]*ProductLog[a*x^2]^(1 - p)*(c*ProductLog[a*x^2])^(1 + p))/(2*a*c*x^4)}


(* ::Subsubsection::Closed:: *)
(*x^m ProductLog[a/x]^p*)


{x^4*ProductLog[a/x], x, 5, (-(125/24))*a^5*ExpIntegralEi[-5*ProductLog[a/x]] + (1/4)*x^5*ProductLog[a/x] - (1/12)*x^5*ProductLog[a/x]^2 + (5/24)*x^5*ProductLog[a/x]^3 - (25/24)*x^5*ProductLog[a/x]^4}
{x^3*ProductLog[a/x], x, 4, (8/3)*a^4*ExpIntegralEi[-4*ProductLog[a/x]] + (1/3)*x^4*ProductLog[a/x] - (1/6)*x^4*ProductLog[a/x]^2 + (2/3)*x^4*ProductLog[a/x]^3}
{x^2*ProductLog[a/x], x, 3, (-(3/2))*a^3*ExpIntegralEi[-3*ProductLog[a/x]] + (1/2)*x^3*ProductLog[a/x] - (1/2)*x^3*ProductLog[a/x]^2}
{x*ProductLog[a/x], x, 2, a^2*ExpIntegralEi[-2*ProductLog[a/x]] + x^2*ProductLog[a/x]}
{ProductLog[a/x], x, 3, (-a)*ExpIntegralEi[-ProductLog[a/x]] + x*ProductLog[a/x]}
{ProductLog[a/x]/x, x, 2, -ProductLog[a/x] - (1/2)*ProductLog[a/x]^2}
{ProductLog[a/x]/x^2, x, 4, 1/x - 1/(x*ProductLog[a/x]) - ProductLog[a/x]/x}
{ProductLog[a/x]/x^3, x, 5, 1/(4*x^2) + 1/(8*x^2*ProductLog[a/x]^2) - 1/(4*x^2*ProductLog[a/x]) - ProductLog[a/x]/(2*x^2)}
{ProductLog[a/x]/x^4, x, 6, 1/(9*x^3) - 2/(81*x^3*ProductLog[a/x]^3) + 2/(27*x^3*ProductLog[a/x]^2) - 1/(9*x^3*ProductLog[a/x]) - ProductLog[a/x]/(3*x^3)}
{ProductLog[a/x]/x^5, x, 7, 1/(16*x^4) + 3/(512*x^4*ProductLog[a/x]^4) - 3/(128*x^4*ProductLog[a/x]^3) + 3/(64*x^4*ProductLog[a/x]^2) - 1/(16*x^4*ProductLog[a/x]) - ProductLog[a/x]/(4*x^4)}


{x^4*ProductLog[a/x]^2, x, 4, (25/3)*a^5*ExpIntegralEi[-5*ProductLog[a/x]] + (1/3)*x^5*ProductLog[a/x]^2 - (1/3)*x^5*ProductLog[a/x]^3 + (5/3)*x^5*ProductLog[a/x]^4}
{x^3*ProductLog[a/x]^2, x, 3, -4*a^4*ExpIntegralEi[-4*ProductLog[a/x]] + (1/2)*x^4*ProductLog[a/x]^2 - x^4*ProductLog[a/x]^3}
{x^2*ProductLog[a/x]^2, x, 2, 2*a^3*ExpIntegralEi[-3*ProductLog[a/x]] + x^3*ProductLog[a/x]^2}
{x*ProductLog[a/x]^2, x, 2, (-a^2)*ExpIntegralEi[-2*ProductLog[a/x]] + (1/2)*x^2*ProductLog[a/x]^2}
{ProductLog[a/x]^2, x, 2, 2*x*ProductLog[a/x] + x*ProductLog[a/x]^2}
{ProductLog[a/x]^2/x, x, 2, (-(1/2))*ProductLog[a/x]^2 - (1/3)*ProductLog[a/x]^3}
{ProductLog[a/x]^2/x^2, x, 5, -(4/x) + 4/(x*ProductLog[a/x]) + (2*ProductLog[a/x])/x - ProductLog[a/x]^2/x}
{ProductLog[a/x]^2/x^3, x, 6, -(3/(4*x^2)) - 3/(8*x^2*ProductLog[a/x]^2) + 3/(4*x^2*ProductLog[a/x]) + ProductLog[a/x]/(2*x^2) - ProductLog[a/x]^2/(2*x^2)}
{ProductLog[a/x]^2/x^4, x, 7, -(8/(27*x^3)) + 16/(243*x^3*ProductLog[a/x]^3) - 16/(81*x^3*ProductLog[a/x]^2) + 8/(27*x^3*ProductLog[a/x]) + (2*ProductLog[a/x])/(9*x^3) - ProductLog[a/x]^2/(3*x^3)}
{ProductLog[a/x]^2/x^5, x, 8, -(5/(32*x^4)) - 15/(1024*x^4*ProductLog[a/x]^4) + 15/(256*x^4*ProductLog[a/x]^3) - 15/(128*x^4*ProductLog[a/x]^2) + 5/(32*x^4*ProductLog[a/x]) + ProductLog[a/x]/(8*x^4) - ProductLog[a/x]^2/(4*x^4)}


{x^3*Sqrt[ProductLog[a/x]], x, 5, (-(256/105))*a^4*Sqrt[Pi]*Erf[2*Sqrt[ProductLog[a/x]]] + (2/7)*x^4*Sqrt[ProductLog[a/x]] - (2/35)*x^4*ProductLog[a/x]^(3/2) + (16/105)*x^4*ProductLog[a/x]^(5/2) - (128/105)*x^4*ProductLog[a/x]^(7/2)}
{x^2*Sqrt[ProductLog[a/x]], x, 4, (4/5)*a^3*Sqrt[3*Pi]*Erf[Sqrt[3]*Sqrt[ProductLog[a/x]]] + (2/5)*x^3*Sqrt[ProductLog[a/x]] - (2/15)*x^3*ProductLog[a/x]^(3/2) + (4/5)*x^3*ProductLog[a/x]^(5/2)}
{x*Sqrt[ProductLog[a/x]], x, 3, (-(2/3))*a^2*Sqrt[2*Pi]*Erf[Sqrt[2]*Sqrt[ProductLog[a/x]]] + (2/3)*x^2*Sqrt[ProductLog[a/x]] - (2/3)*x^2*ProductLog[a/x]^(3/2)}
{Sqrt[ProductLog[a/x]], x, 2, a*Sqrt[Pi]*Erf[Sqrt[ProductLog[a/x]]] + 2*x*Sqrt[ProductLog[a/x]]}
{Sqrt[ProductLog[a/x]]/x, x, 2, -2*Sqrt[ProductLog[a/x]] - (2/3)*ProductLog[a/x]^(3/2)}
{Sqrt[ProductLog[a/x]]/x^2, x, 3, -((Sqrt[Pi]*Erfi[Sqrt[ProductLog[a/x]]])/(4*a)) + 1/(2*x*Sqrt[ProductLog[a/x]]) - Sqrt[ProductLog[a/x]]/x}
{Sqrt[ProductLog[a/x]]/x^3, x, 4, (3*Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[ProductLog[a/x]]])/(64*a^2) - 3/(32*x^2*ProductLog[a/x]^(3/2)) + 1/(8*x^2*Sqrt[ProductLog[a/x]]) - Sqrt[ProductLog[a/x]]/(2*x^2)}
{Sqrt[ProductLog[a/x]]/x^4, x, 5, -((5*Sqrt[Pi/3]*Erfi[Sqrt[3]*Sqrt[ProductLog[a/x]]])/(432*a^3)) + 5/(216*x^3*ProductLog[a/x]^(5/2)) - 5/(108*x^3*ProductLog[a/x]^(3/2)) + 1/(18*x^3*Sqrt[ProductLog[a/x]]) - Sqrt[ProductLog[a/x]]/(3*x^3)}


{x^3/Sqrt[ProductLog[a/x]], x, 6, (-(2048/945))*a^4*Sqrt[Pi]*Erf[2*Sqrt[ProductLog[a/x]]] + (2*x^4)/(9*Sqrt[ProductLog[a/x]]) + (2/63)*x^4*Sqrt[ProductLog[a/x]] - (16/315)*x^4*ProductLog[a/x]^(3/2) + (128/945)*x^4*ProductLog[a/x]^(5/2) - (1024/945)*x^4*ProductLog[a/x]^(7/2)}
{x^2/Sqrt[ProductLog[a/x]], x, 5, (24/35)*a^3*Sqrt[3*Pi]*Erf[Sqrt[3]*Sqrt[ProductLog[a/x]]] + (2*x^3)/(7*Sqrt[ProductLog[a/x]]) + (2/35)*x^3*Sqrt[ProductLog[a/x]] - (4/35)*x^3*ProductLog[a/x]^(3/2) + (24/35)*x^3*ProductLog[a/x]^(5/2)}
{x/Sqrt[ProductLog[a/x]], x, 4, (-(8/15))*a^2*Sqrt[2*Pi]*Erf[Sqrt[2]*Sqrt[ProductLog[a/x]]] + (2*x^2)/(5*Sqrt[ProductLog[a/x]]) + (2/15)*x^2*Sqrt[ProductLog[a/x]] - (8/15)*x^2*ProductLog[a/x]^(3/2)}
{1/Sqrt[ProductLog[a/x]], x, 4, (2/3)*a*Sqrt[Pi]*Erf[Sqrt[ProductLog[a/x]]] + (2*x)/(3*Sqrt[ProductLog[a/x]]) + (2/3)*x*Sqrt[ProductLog[a/x]]}
{1/(x*Sqrt[ProductLog[a/x]]), x, 2, 2/Sqrt[ProductLog[a/x]] - 2*Sqrt[ProductLog[a/x]]}
{1/(x^2*Sqrt[ProductLog[a/x]]), x, 2, -((Sqrt[Pi]*Erfi[Sqrt[ProductLog[a/x]]])/(2*a)) - 1/(x*Sqrt[ProductLog[a/x]])}
{1/(x^3*Sqrt[ProductLog[a/x]]), x, 3, (Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[ProductLog[a/x]]])/(16*a^2) - 1/(8*x^2*ProductLog[a/x]^(3/2)) - 1/(2*x^2*Sqrt[ProductLog[a/x]])}
{1/(x^4*Sqrt[ProductLog[a/x]]), x, 4, -((Sqrt[Pi/3]*Erfi[Sqrt[3]*Sqrt[ProductLog[a/x]]])/(72*a^3)) + 1/(36*x^3*ProductLog[a/x]^(5/2)) - 1/(18*x^3*ProductLog[a/x]^(3/2)) - 1/(3*x^3*Sqrt[ProductLog[a/x]])}


{x^2*(c*ProductLog[a/x])^p, x, 4, (3^(3 - p)*E^(4*ProductLog[a/x])*x^4*Gamma[-3 + p, 3*ProductLog[a/x]]*ProductLog[a/x]^(4 - p)*(c*ProductLog[a/x])^p)/a + (3^(2 - p)*E^(4*ProductLog[a/x])*x^4*Gamma[-2 + p, 3*ProductLog[a/x]]*ProductLog[a/x]^(3 - p)*(c*ProductLog[a/x])^(1 + p))/(a*c)}
{x*(c*ProductLog[a/x])^p, x, 4, (2^(2 - p)*E^(3*ProductLog[a/x])*x^3*Gamma[-2 + p, 2*ProductLog[a/x]]*ProductLog[a/x]^(3 - p)*(c*ProductLog[a/x])^p)/a + (2^(1 - p)*E^(3*ProductLog[a/x])*x^3*Gamma[-1 + p, 2*ProductLog[a/x]]*ProductLog[a/x]^(2 - p)*(c*ProductLog[a/x])^(1 + p))/(a*c)}
{(c*ProductLog[a/x])^p/x, x, 2, -((c*ProductLog[a/x])^p/p) - (c*ProductLog[a/x])^(1 + p)/(c*(1 + p))}
{(c*ProductLog[a/x])^p/x^2, x, 3, -((c*ProductLog[a/x])^p/x) + (p*Gamma[1 + p, -ProductLog[a/x]]*(c*ProductLog[a/x])^p)/((-ProductLog[a/x])^p*a)}
{(c*ProductLog[a/x])^p/x^3, x, 4, -((2^(-2 - p)*Gamma[2 + p, -2*ProductLog[a/x]]*(-ProductLog[a/x])^(-1 - p)*(c*ProductLog[a/x])^p)/(E^ProductLog[a/x]*(a*x))) - (2^(-3 - p)*Gamma[3 + p, -2*ProductLog[a/x]]*(-ProductLog[a/x])^(-2 - p)*(c*ProductLog[a/x])^(1 + p))/(E^ProductLog[a/x]*(a*c*x))}


(* ::Subsubsection::Closed:: *)
(*ProductLog[a x^n]^p*)


{ProductLog[a/x^(1/4)]^5, x, 2, (5/4)*x*ProductLog[a/x^(1/4)]^4 + x*ProductLog[a/x^(1/4)]^5}
{ProductLog[a/x^(1/3)]^4, x, 2, (4/3)*x*ProductLog[a/x^(1/3)]^3 + x*ProductLog[a/x^(1/3)]^4}
{ProductLog[a/Sqrt[x]]^3, x, 2, (3/2)*x*ProductLog[a/Sqrt[x]]^2 + x*ProductLog[a/Sqrt[x]]^3}
{ProductLog[a/x]^2, x, 2, 2*x*ProductLog[a/x] + x*ProductLog[a/x]^2}
{1/ProductLog[a*Sqrt[x]], x, 2, x/(2*ProductLog[a*Sqrt[x]]^2) + x/ProductLog[a*Sqrt[x]]}
{1/ProductLog[a*x^(1/3)]^2, x, 2, (2*x)/(3*ProductLog[a*x^(1/3)]^3) + x/ProductLog[a*x^(1/3)]^2}
{1/ProductLog[a*x^(1/4)]^3, x, 2, (3*x)/(4*ProductLog[a*x^(1/4)]^4) + x/ProductLog[a*x^(1/4)]^3}


{ProductLog[a/x^(1/5)]^4, x, 2, 20*a^5*ExpIntegralEi[-5*ProductLog[a/x^(1/5)]] + 5*x*ProductLog[a/x^(1/5)]^4}
{ProductLog[a/x^(1/4)]^3, x, 2, 12*a^4*ExpIntegralEi[-4*ProductLog[a/x^(1/4)]] + 4*x*ProductLog[a/x^(1/4)]^3}
{ProductLog[a/x^(1/3)]^2, x, 2, 6*a^3*ExpIntegralEi[-3*ProductLog[a/x^(1/3)]] + 3*x*ProductLog[a/x^(1/3)]^2}
{ProductLog[a/Sqrt[x]], x, 2, 2*a^2*ExpIntegralEi[-2*ProductLog[a/Sqrt[x]]] + 2*x*ProductLog[a/Sqrt[x]]}
{1/ProductLog[a*x]^2, x, 2, (2*ExpIntegralEi[ProductLog[a*x]])/a - x/ProductLog[a*x]^2}
{1/ProductLog[a*Sqrt[x]]^3, x, 2, (6*ExpIntegralEi[2*ProductLog[a*Sqrt[x]]])/a^2 - (2*x)/ProductLog[a*Sqrt[x]]^3}
{1/ProductLog[a*x^(1/3)]^4, x, 2, (12*ExpIntegralEi[3*ProductLog[a*x^(1/3)]])/a^3 - (3*x)/ProductLog[a*x^(1/3)]^4}
{1/ProductLog[a*x^(1/4)]^5, x, 2, (20*ExpIntegralEi[4*ProductLog[a*x^(1/4)]])/a^4 - (4*x)/ProductLog[a*x^(1/4)]^5}


{ProductLog[a*x^n]^((-1 + n)/n), x, 2, ((1 - n)*x)/ProductLog[a*x^n]^n^(-1) + x/ProductLog[a*x^n]^((1 - n)/n)}
{ProductLog[a*x^(1/(1 - p))]^p, x, 2, x*ProductLog[a*x^(1/(1 - p))]^p - (p/(1 - p))*x*ProductLog[a*x^(1/(1 - p))]^(p - 1)}


(* ::Subsubsection::Closed:: *)
(*x^m ProductLog[a x^n]^p*)


{x^(-1 - n)*(c*ProductLog[a*x^n])^(9/2), x, 5, (135*a*c^(9/2)*Sqrt[Pi]*Erf[Sqrt[c*ProductLog[a*x^n]]/Sqrt[c]])/(16*n) - (135*c^3*(c*ProductLog[a*x^n])^(3/2))/(x^n*(8*n)) - (45*c^2*(c*ProductLog[a*x^n])^(5/2))/(x^n*(4*n)) - (9*c*(c*ProductLog[a*x^n])^(7/2))/(x^n*(2*n)) - (c*ProductLog[a*x^n])^(9/2)/(x^n*n)}
{x^(-1 - n)*(c*ProductLog[a*x^n])^(7/2), x, 4, (21*a*c^(7/2)*Sqrt[Pi]*Erf[Sqrt[c*ProductLog[a*x^n]]/Sqrt[c]])/(8*n) - (21*c^2*(c*ProductLog[a*x^n])^(3/2))/(x^n*(4*n)) - (7*c*(c*ProductLog[a*x^n])^(5/2))/(x^n*(2*n)) - (c*ProductLog[a*x^n])^(7/2)/(x^n*n)}
{x^(-1 - n)*(c*ProductLog[a*x^n])^(5/2), x, 3, (5*a*c^(5/2)*Sqrt[Pi]*Erf[Sqrt[c*ProductLog[a*x^n]]/Sqrt[c]])/(4*n) - (5*c*(c*ProductLog[a*x^n])^(3/2))/(x^n*(2*n)) - (c*ProductLog[a*x^n])^(5/2)/(x^n*n)}
{x^(-1 - n)*(c*ProductLog[a*x^n])^(3/2), x, 2, (3*a*c^(3/2)*Sqrt[Pi]*Erf[Sqrt[c*ProductLog[a*x^n]]/Sqrt[c]])/(2*n) - (c*ProductLog[a*x^n])^(3/2)/(x^n*n)}
{x^(-1 - n)*(c*ProductLog[a*x^n])^(1/2), x, 2, -((a*Sqrt[c]*Sqrt[Pi]*Erf[Sqrt[c*ProductLog[a*x^n]]/Sqrt[c]])/n) - (2*Sqrt[c*ProductLog[a*x^n]])/(x^n*n)}
{x^(-1 - n)/(c*ProductLog[a*x^n])^(1/2), x, 3, -((2*a*Sqrt[Pi]*Erf[Sqrt[c*ProductLog[a*x^n]]/Sqrt[c]])/(3*Sqrt[c]*n)) - 2/(x^n*(3*n*Sqrt[c*ProductLog[a*x^n]])) - (2*Sqrt[c*ProductLog[a*x^n]])/(x^n*(3*c*n))}
{x^(-1 - n)/(c*ProductLog[a*x^n])^(3/2), x, 4, (4*a*Sqrt[Pi]*Erf[Sqrt[c*ProductLog[a*x^n]]/Sqrt[c]])/(5*c^(3/2)*n) - 2/(x^n*(5*n*(c*ProductLog[a*x^n])^(3/2))) - 2/(x^n*(5*c*n*Sqrt[c*ProductLog[a*x^n]])) + (4*Sqrt[c*ProductLog[a*x^n]])/(x^n*(5*c^2*n))}
{x^(-1 - n)/(c*ProductLog[a*x^n])^(5/2), x, 5, -((8*a*Sqrt[Pi]*Erf[Sqrt[c*ProductLog[a*x^n]]/Sqrt[c]])/(21*c^(5/2)*n)) - 2/(x^n*(7*n*(c*ProductLog[a*x^n])^(5/2))) - 2/(x^n*(7*c*n*(c*ProductLog[a*x^n])^(3/2))) + 4/(x^n*(21*c^2*n*Sqrt[c*ProductLog[a*x^n]])) - (8*Sqrt[c*ProductLog[a*x^n]])/(x^n*(21*c^3*n))}


{x^(-1 - 2*n)*(c*ProductLog[a*x^n])^(11/2), x, 5, (165*a^2*c^(11/2)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[c*ProductLog[a*x^n]])/Sqrt[c]])/(256*n) - (165*c^3*(c*ProductLog[a*x^n])^(5/2))/(x^(2*n)*(128*n)) - (55*c^2*(c*ProductLog[a*x^n])^(7/2))/(x^(2*n)*(32*n)) - (11*c*(c*ProductLog[a*x^n])^(9/2))/(x^(2*n)*(8*n)) - (c*ProductLog[a*x^n])^(11/2)/(x^(2*n)*(2*n))}
{x^(-1 - 2*n)*(c*ProductLog[a*x^n])^(9/2), x, 4, (27*a^2*c^(9/2)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[c*ProductLog[a*x^n]])/Sqrt[c]])/(64*n) - (27*c^2*(c*ProductLog[a*x^n])^(5/2))/(x^(2*n)*(32*n)) - (9*c*(c*ProductLog[a*x^n])^(7/2))/(x^(2*n)*(8*n)) - (c*ProductLog[a*x^n])^(9/2)/(x^(2*n)*(2*n))}
{x^(-1 - 2*n)*(c*ProductLog[a*x^n])^(7/2), x, 3, (7*a^2*c^(7/2)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[c*ProductLog[a*x^n]])/Sqrt[c]])/(16*n) - (7*c*(c*ProductLog[a*x^n])^(5/2))/(x^(2*n)*(8*n)) - (c*ProductLog[a*x^n])^(7/2)/(x^(2*n)*(2*n))}
{x^(-1 - 2*n)*(c*ProductLog[a*x^n])^(5/2), x, 2, (5*a^2*c^(5/2)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[c*ProductLog[a*x^n]])/Sqrt[c]])/(4*n) - (c*ProductLog[a*x^n])^(5/2)/(x^(2*n)*(2*n))}
{x^(-1 - 2*n)*(c*ProductLog[a*x^n])^(3/2), x, 2, -((3*a^2*c^(3/2)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[c*ProductLog[a*x^n]])/Sqrt[c]])/n) - (2*(c*ProductLog[a*x^n])^(3/2))/(x^(2*n)*n)}
{x^(-1 - 2*n)*(c*ProductLog[a*x^n])^(1/2), x, 3, (2*a^2*Sqrt[c]*Sqrt[2*Pi]*Erf[(Sqrt[2]*Sqrt[c*ProductLog[a*x^n]])/Sqrt[c]])/(3*n) - (2*Sqrt[c*ProductLog[a*x^n]])/(x^(2*n)*(3*n)) + (2*(c*ProductLog[a*x^n])^(3/2))/(x^(2*n)*(3*c*n))}
{x^(-1 - 2*n)/(c*ProductLog[a*x^n])^(1/2), x, 4, (8*a^2*Sqrt[2*Pi]*Erf[(Sqrt[2]*Sqrt[c*ProductLog[a*x^n]])/Sqrt[c]])/(15*Sqrt[c]*n) - 2/(x^(2*n)*(5*n*Sqrt[c*ProductLog[a*x^n]])) - (2*Sqrt[c*ProductLog[a*x^n]])/(x^(2*n)*(15*c*n)) + (8*(c*ProductLog[a*x^n])^(3/2))/(x^(2*n)*(15*c^2*n))}
{x^(-1 - 2*n)/(c*ProductLog[a*x^n])^(3/2), x, 5, -((32*a^2*Sqrt[2*Pi]*Erf[(Sqrt[2]*Sqrt[c*ProductLog[a*x^n]])/Sqrt[c]])/(35*c^(3/2)*n)) - 2/(x^(2*n)*(7*n*(c*ProductLog[a*x^n])^(3/2))) - 6/(x^(2*n)*(35*c*n*Sqrt[c*ProductLog[a*x^n]])) + (8*Sqrt[c*ProductLog[a*x^n]])/(x^(2*n)*(35*c^2*n)) - (32*(c*ProductLog[a*x^n])^(3/2))/(x^(2*n)*(35*c^3*n))}


{x^(-1 + n)*(c*ProductLog[a*x^n])^(5/2), x, 5, (75*c^(5/2)*Sqrt[Pi]*Erfi[Sqrt[c*ProductLog[a*x^n]]/Sqrt[c]])/(16*a*n) - (75*c^3*x^n)/(8*n*Sqrt[c*ProductLog[a*x^n]]) + (25*c^2*x^n*Sqrt[c*ProductLog[a*x^n]])/(4*n) - (5*c*x^n*(c*ProductLog[a*x^n])^(3/2))/(2*n) + (x^n*(c*ProductLog[a*x^n])^(5/2))/n}
{x^(-1 + n)*(c*ProductLog[a*x^n])^(3/2), x, 4, -((9*c^(3/2)*Sqrt[Pi]*Erfi[Sqrt[c*ProductLog[a*x^n]]/Sqrt[c]])/(8*a*n)) + (9*c^2*x^n)/(4*n*Sqrt[c*ProductLog[a*x^n]]) - (3*c*x^n*Sqrt[c*ProductLog[a*x^n]])/(2*n) + (x^n*(c*ProductLog[a*x^n])^(3/2))/n}
{x^(-1 + n)*(c*ProductLog[a*x^n])^(1/2), x, 3, (Sqrt[c]*Sqrt[Pi]*Erfi[Sqrt[c*ProductLog[a*x^n]]/Sqrt[c]])/(4*a*n) - (c*x^n)/(2*n*Sqrt[c*ProductLog[a*x^n]]) + (x^n*Sqrt[c*ProductLog[a*x^n]])/n}
{x^(-1 + n)/(c*ProductLog[a*x^n])^(1/2), x, 2, (Sqrt[Pi]*Erfi[Sqrt[c*ProductLog[a*x^n]]/Sqrt[c]])/(2*a*Sqrt[c]*n) + x^n/(n*Sqrt[c*ProductLog[a*x^n]])}
{x^(-1 + n)/(c*ProductLog[a*x^n])^(3/2), x, 2, (3*Sqrt[Pi]*Erfi[Sqrt[c*ProductLog[a*x^n]]/Sqrt[c]])/(a*c^(3/2)*n) - (2*x^n)/(n*(c*ProductLog[a*x^n])^(3/2))}
{x^(-1 + n)/(c*ProductLog[a*x^n])^(5/2), x, 3, (10*Sqrt[Pi]*Erfi[Sqrt[c*ProductLog[a*x^n]]/Sqrt[c]])/(3*a*c^(5/2)*n) - (2*x^n)/(3*n*(c*ProductLog[a*x^n])^(5/2)) - (10*x^n)/(3*c*n*(c*ProductLog[a*x^n])^(3/2))}
{x^(-1 + n)/(c*ProductLog[a*x^n])^(7/2), x, 4, (28*Sqrt[Pi]*Erfi[Sqrt[c*ProductLog[a*x^n]]/Sqrt[c]])/(15*a*c^(7/2)*n) - (2*x^n)/(5*n*(c*ProductLog[a*x^n])^(7/2)) - (14*x^n)/(15*c*n*(c*ProductLog[a*x^n])^(5/2)) - (28*x^n)/(15*c^2*n*(c*ProductLog[a*x^n])^(3/2))}
{x^(-1 + n)/(c*ProductLog[a*x^n])^(9/2), x, 5, (24*Sqrt[Pi]*Erfi[Sqrt[c*ProductLog[a*x^n]]/Sqrt[c]])/(35*a*c^(9/2)*n) - (2*x^n)/(7*n*(c*ProductLog[a*x^n])^(9/2)) - (18*x^n)/(35*c*n*(c*ProductLog[a*x^n])^(7/2)) - (12*x^n)/(35*c^2*n*(c*ProductLog[a*x^n])^(5/2)) - (24*x^n)/(35*c^3*n*(c*ProductLog[a*x^n])^(3/2))}


{x^(-1 + 2*n)*(c*ProductLog[a*x^n])^(3/2), x, 5, (45*c^(3/2)*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[c*ProductLog[a*x^n]])/Sqrt[c]])/(256*a^2*n) - (45*c^3*x^(2*n))/(128*n*(c*ProductLog[a*x^n])^(3/2)) + (15*c^2*x^(2*n))/(32*n*Sqrt[c*ProductLog[a*x^n]]) - (3*c*x^(2*n)*Sqrt[c*ProductLog[a*x^n]])/(8*n) + (x^(2*n)*(c*ProductLog[a*x^n])^(3/2))/(2*n)}
{x^(-1 + 2*n)*(c*ProductLog[a*x^n])^(1/2), x, 4, -((3*Sqrt[c]*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[c*ProductLog[a*x^n]])/Sqrt[c]])/(64*a^2*n)) + (3*c^2*x^(2*n))/(32*n*(c*ProductLog[a*x^n])^(3/2)) - (c*x^(2*n))/(8*n*Sqrt[c*ProductLog[a*x^n]]) + (x^(2*n)*Sqrt[c*ProductLog[a*x^n]])/(2*n)}
{x^(-1 + 2*n)/(c*ProductLog[a*x^n])^(1/2), x, 3, -((Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[c*ProductLog[a*x^n]])/Sqrt[c]])/(16*a^2*Sqrt[c]*n)) + (c*x^(2*n))/(8*n*(c*ProductLog[a*x^n])^(3/2)) + x^(2*n)/(2*n*Sqrt[c*ProductLog[a*x^n]])}
{x^(-1 + 2*n)/(c*ProductLog[a*x^n])^(3/2), x, 2, (3*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[c*ProductLog[a*x^n]])/Sqrt[c]])/(4*a^2*c^(3/2)*n) + x^(2*n)/(2*n*(c*ProductLog[a*x^n])^(3/2))}
{x^(-1 + 2*n)/(c*ProductLog[a*x^n])^(5/2), x, 2, (5*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[c*ProductLog[a*x^n]])/Sqrt[c]])/(a^2*c^(5/2)*n) - (2*x^(2*n))/(n*(c*ProductLog[a*x^n])^(5/2))}
{x^(-1 + 2*n)/(c*ProductLog[a*x^n])^(7/2), x, 3, (14*Sqrt[2*Pi]*Erfi[(Sqrt[2]*Sqrt[c*ProductLog[a*x^n]])/Sqrt[c]])/(3*a^2*c^(7/2)*n) - (2*x^(2*n))/(3*n*(c*ProductLog[a*x^n])^(7/2)) - (14*x^(2*n))/(3*c*n*(c*ProductLog[a*x^n])^(5/2))}
{x^(-1 + 2*n)/(c*ProductLog[a*x^n])^(9/2), x, 4, (24*Sqrt[2*Pi]*Erfi[(Sqrt[2]*Sqrt[c*ProductLog[a*x^n]])/Sqrt[c]])/(5*a^2*c^(9/2)*n) - (2*x^(2*n))/(5*n*(c*ProductLog[a*x^n])^(9/2)) - (6*x^(2*n))/(5*c*n*(c*ProductLog[a*x^n])^(7/2)) - (24*x^(2*n))/(5*c^2*n*(c*ProductLog[a*x^n])^(5/2))}
{x^(-1 + 2*n)/(c*ProductLog[a*x^n])^(11/2), x, 5, (352*Sqrt[2*Pi]*Erfi[(Sqrt[2]*Sqrt[c*ProductLog[a*x^n]])/Sqrt[c]])/(105*a^2*c^(11/2)*n) - (2*x^(2*n))/(7*n*(c*ProductLog[a*x^n])^(11/2)) - (22*x^(2*n))/(35*c*n*(c*ProductLog[a*x^n])^(9/2)) - (88*x^(2*n))/(105*c^2*n*(c*ProductLog[a*x^n])^(7/2)) - (352*x^(2*n))/(105*c^3*n*(c*ProductLog[a*x^n])^(5/2))}


{ProductLog[a*x^n]^4/x^(3*n + 1), x, 2, -((4*ProductLog[a*x^n]^3)/(x^(3*n)*(9*n))) - ProductLog[a*x^n]^4/(x^(3*n)*(3*n))}
{ProductLog[a*x^n]^3/x^(2*n + 1), x, 2, -((3*ProductLog[a*x^n]^2)/(x^(2*n)*(4*n))) - ProductLog[a*x^n]^3/(x^(2*n)*(2*n))}
{ProductLog[a*x^n]^2/x^(n + 1), x, 2, -((2*ProductLog[a*x^n])/(x^n*n)) - ProductLog[a*x^n]^2/(x^n*n)}
{x^(2*n - 1)/ProductLog[a*x^n], x, 2, x^(2*n)/(4*n*ProductLog[a*x^n]^2) + x^(2*n)/(2*n*ProductLog[a*x^n])}
{x^(3*n - 1)/ProductLog[a*x^n]^2, x, 2, (2*x^(3*n))/(9*n*ProductLog[a*x^n]^3) + x^(3*n)/(3*n*ProductLog[a*x^n]^2)}
{x^(4*n - 1)/ProductLog[a*x^n]^3, x, 2, (3*x^(4*n))/(16*n*ProductLog[a*x^n]^4) + x^(4*n)/(4*n*ProductLog[a*x^n]^3)}


{x^(-1 - n*(1 + p))*(c*ProductLog[a*x^n])^p, x, 1, -((p*Int[(x^(-1 - n*(1 + p))*(c*ProductLog[a*x^n])^(1 + p))/(1 + ProductLog[a*x^n]), x])/c) - (c*ProductLog[a*x^n])^p/(x^(n*(1 + p))*n)}
{x^(-1 + n*(0 - p))*(c*ProductLog[a*x^n])^p, x, 1, Int[(x^(-1 - n*p)*(c*ProductLog[a*x^n])^p)/(1 + ProductLog[a*x^n]), x] - (c*ProductLog[a*x^n])^p/(x^(n*p)*(n*p))}
{x^(-1 + n*(1 - p))*(c*ProductLog[a*x^n])^p, x, 2, -((c*p*x^(n*(1 - p))*(c*ProductLog[a*x^n])^(-1 + p))/(n*(1 - p)^2)) + (x^(n*(1 - p))*(c*ProductLog[a*x^n])^p)/(n*(1 - p))}
{x^(-1 + n*(2 - p))*(c*ProductLog[a*x^n])^p, x, 3, (c^2*p*x^(n*(2 - p))*(c*ProductLog[a*x^n])^(-2 + p))/(n*(2 - p)^3) - (c*p*x^(n*(2 - p))*(c*ProductLog[a*x^n])^(-1 + p))/(n*(2 - p)^2) + (x^(n*(2 - p))*(c*ProductLog[a*x^n])^p)/(n*(2 - p))}
{x^(-1 + n*(3 - p))*(c*ProductLog[a*x^n])^p, x, 4, -((2*c^3*p*x^(n*(3 - p))*(c*ProductLog[a*x^n])^(-3 + p))/(n*(3 - p)^4)) + (2*c^2*p*x^(n*(3 - p))*(c*ProductLog[a*x^n])^(-2 + p))/(n*(3 - p)^3) - (c*p*x^(n*(3 - p))*(c*ProductLog[a*x^n])^(-1 + p))/(n*(3 - p)^2) + (x^(n*(3 - p))*(c*ProductLog[a*x^n])^p)/(n*(3 - p))}


(* ::Subsubsection::Closed:: *)
(*x^m / (1+ProductLog[a x^n])*)


{x^3/(1 + ProductLog[a*x]), x, 4, -((3*x^4)/(128*ProductLog[a*x]^4)) + (3*x^4)/(32*ProductLog[a*x]^3) - (3*x^4)/(16*ProductLog[a*x]^2) + x^4/(4*ProductLog[a*x])}
{x^2/(1 + ProductLog[a*x]), x, 3, (2*x^3)/(27*ProductLog[a*x]^3) - (2*x^3)/(9*ProductLog[a*x]^2) + x^3/(3*ProductLog[a*x])}
{x/(1 + ProductLog[a*x]), x, 2, -(x^2/(4*ProductLog[a*x]^2)) + x^2/(2*ProductLog[a*x])}
{1/(1 + ProductLog[a*x]), x, 1, a*x/(a*ProductLog[a*x])}
{1/(x*(1 + ProductLog[a*x])), x, 1, Log[ProductLog[a*x]]}
{1/(x^2*(1 + ProductLog[a*x])), x, 2, -(1/x) - a*ExpIntegralEi[-ProductLog[a*x]]}
{1/(x^3*(1 + ProductLog[a*x])), x, 3, -(1/(2*x^2)) + 2*a^2*ExpIntegralEi[-2*ProductLog[a*x]] + ProductLog[a*x]/x^2}
{1/(x^4*(1 + ProductLog[a*x])), x, 4, -(1/(3*x^3)) - (9/2)*a^3*ExpIntegralEi[-3*ProductLog[a*x]] + ProductLog[a*x]/(2*x^3) - (3*ProductLog[a*x]^2)/(2*x^3)}


{x^3/(1 + ProductLog[a*x^2]), x, 3, -(x^4/(8*ProductLog[a*x^2]^2)) + x^4/(4*ProductLog[a*x^2])}
{x^2/(1 + ProductLog[a*x^2]), x, 0, Int[x^2/(1 + ProductLog[a*x^2]), x]}
{x/(1 + ProductLog[a*x^2]), x, 2, x^2/(2*ProductLog[a*x^2])}
{1/(1 + ProductLog[a*x^2]), x, 0, Int[1/(1 + ProductLog[a*x^2]), x]}
{1/(x*(1 + ProductLog[a*x^2])), x, 1, (1/2)*Log[ProductLog[a*x^2]]}
{1/(x^2*(1 + ProductLog[a*x^2])), x, 0, Int[1/(x^2*(1 + ProductLog[a*x^2])), x]}
{1/(x^3*(1 + ProductLog[a*x^2])), x, 3, -(1/(2*x^2)) - (1/2)*a*ExpIntegralEi[-ProductLog[a*x^2]]}
{1/(x^4*(1 + ProductLog[a*x^2])), x, 0, Int[1/(x^4*(1 + ProductLog[a*x^2])), x]}


{x^3/(1 + ProductLog[a/x]), x, 6, x^4/4 - (32/3)*a^4*ExpIntegralEi[-4*ProductLog[a/x]] - (1/3)*x^4*ProductLog[a/x] + (2/3)*x^4*ProductLog[a/x]^2 - (8/3)*x^4*ProductLog[a/x]^3}
{x^2/(1 + ProductLog[a/x]), x, 5, x^3/3 + (9/2)*a^3*ExpIntegralEi[-3*ProductLog[a/x]] - (1/2)*x^3*ProductLog[a/x] + (3/2)*x^3*ProductLog[a/x]^2}
{x/(1 + ProductLog[a/x]), x, 4, x^2/2 - 2*a^2*ExpIntegralEi[-2*ProductLog[a/x]] - x^2*ProductLog[a/x]}
{1/(1 + ProductLog[a/x]), x, 3, x + a*ExpIntegralEi[-ProductLog[a/x]]}
{1/(x*(1 + ProductLog[a/x])), x, 1, -Log[ProductLog[a/x]]}
{1/(x^2*(1 + ProductLog[a/x])), x, 2, -(1/(x*ProductLog[a/x]))}
{1/(x^3*(1 + ProductLog[a/x])), x, 3, 1/(4*x^2*ProductLog[a/x]^2) - 1/(2*x^2*ProductLog[a/x])}
{1/(x^4*(1 + ProductLog[a/x])), x, 4, -(2/(27*x^3*ProductLog[a/x]^3)) + 2/(9*x^3*ProductLog[a/x]^2) - 1/(3*x^3*ProductLog[a/x])}


{x^3/(1 + ProductLog[a/x^2]), x, 5, x^4/4 - a^2*ExpIntegralEi[-2*ProductLog[a/x^2]] - (1/2)*x^4*ProductLog[a/x^2]}
{x^2/(1 + ProductLog[a/x^2]), x, 1, -Subst[Int[1/(x^4*(1 + ProductLog[a*x^2])), x], x, 1/x]}
{x/(1 + ProductLog[a/x^2]), x, 4, x^2/2 + (1/2)*a*ExpIntegralEi[-ProductLog[a/x^2]]}
{1/(1 + ProductLog[a/x^2]), x, 1, -Subst[Int[1/(x^2*(1 + ProductLog[a*x^2])), x], x, 1/x]}
{1/(x*(1 + ProductLog[a/x^2])), x, 1, (-(1/2))*Log[ProductLog[a/x^2]]}
{1/(x^2*(1 + ProductLog[a/x^2])), x, 1, -Subst[Int[1/(1 + ProductLog[a*x^2]), x], x, 1/x]}
{1/(x^3*(1 + ProductLog[a/x^2])), x, 3, -(1/(2*x^2*ProductLog[a/x^2]))}
{1/(x^4*(1 + ProductLog[a/x^2])), x, 1, -Subst[Int[x^2/(1 + ProductLog[a*x^2]), x], x, 1/x]}


{x^m/(d + d*ProductLog[a*x]), x, 1, (x^m*Gamma[1 + m, (-(1 + m)*ProductLog[a*x])])/(E^(m*ProductLog[a*x])*(-(1 + m)*ProductLog[a*x])^m*(a*d*(1 + m)))}


(* ::Subsubsection::Closed:: *)
(*ProductLog[a x^n]^p / (1+ProductLog[a x^n])*)


{ProductLog[a/x^(1/4)]^5/(1 + ProductLog[a/x^(1/4)]), x, 1, x*ProductLog[a/x^(1/4)]^4}
{ProductLog[a/x^(1/3)]^4/(1 + ProductLog[a/x^(1/3)]), x, 1, x*ProductLog[a/x^(1/3)]^3}
{ProductLog[a/Sqrt[x]]^3/(1 + ProductLog[a/Sqrt[x]]), x, 1, x*ProductLog[a/Sqrt[x]]^2}
{ProductLog[a/x]^2/(1 + ProductLog[a/x]), x, 1, x*ProductLog[a/x]}
{1/(ProductLog[a*Sqrt[x]]*(1 + ProductLog[a*Sqrt[x]])), x, 1, x/ProductLog[a*Sqrt[x]]^2}
{1/(ProductLog[a*x^(1/3)]^2*(1 + ProductLog[a*x^(1/3)])), x, 1, x/ProductLog[a*x^(1/3)]^3}
{1/(ProductLog[a*x^(1/4)]^3*(1 + ProductLog[a*x^(1/4)])), x, 1, x/ProductLog[a*x^(1/4)]^4}


{ProductLog[a/x^(1/4)]^4/(1 + ProductLog[a/x^(1/4)]), x, 1, -4*a^4*ExpIntegralEi[-4*ProductLog[a/x^(1/4)]]}
{ProductLog[a/x^(1/3)]^3/(1 + ProductLog[a/x^(1/3)]), x, 1, -3*a^3*ExpIntegralEi[-3*ProductLog[a/x^(1/3)]]}
{ProductLog[a/Sqrt[x]]^2/(1 + ProductLog[a/Sqrt[x]]), x, 1, -2*a^2*ExpIntegralEi[-2*ProductLog[a/Sqrt[x]]]}
{ProductLog[a/x]/(1 + ProductLog[a/x]), x, 1, (-a)*ExpIntegralEi[-ProductLog[a/x]]}
{1/(ProductLog[a*x]*(1 + ProductLog[a*x])), x, 1, ExpIntegralEi[ProductLog[a*x]]/a}
{1/(ProductLog[a*Sqrt[x]]^2*(1 + ProductLog[a*Sqrt[x]])), x, 1, (2*ExpIntegralEi[2*ProductLog[a*Sqrt[x]]])/a^2}
{1/(ProductLog[a*x^(1/3)]^3*(1 + ProductLog[a*x^(1/3)])), x, 1, (3*ExpIntegralEi[3*ProductLog[a*x^(1/3)]])/a^3}
{1/(ProductLog[a*x^(1/4)]^4*(1 + ProductLog[a*x^(1/4)])), x, 1, (4*ExpIntegralEi[4*ProductLog[a*x^(1/4)]])/a^4}


{ProductLog[a*x^n]^(1 - 1/n)/(1 + ProductLog[a*x^n]), x, 1, x/ProductLog[a*x^n]^(n^(-1))}
{ProductLog[a*x^(1/(1 - p))]^p/(1 + ProductLog[a*x^(1/(1 - p))]), x, 1, x*ProductLog[a*x^(1/(1 - p))]^(p - 1)}
