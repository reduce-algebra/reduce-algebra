(* ::Package:: *)

(* ::Title:: *)
(*Algebraic Function Integration Problems Involving Linears*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (c (a+b x)^n)^(m/2)*)


(* Integrands of the form (a+b*x)^n where n is a half-integer *)
{(a + b*x)^(5/2), x, 1, (2*(a + b*x)^(7/2))/(7*b)}
{(a + b*x)^(3/2), x, 1, (2*(a + b*x)^(5/2))/(5*b)}
{Sqrt[a + b*x], x, 1, (2*(a + b*x)^(3/2))/(3*b)}
{1/Sqrt[a + b*x], x, 1, (2*Sqrt[a + b*x])/b}
{1/(a + b*x)^(3/2), x, 1, -2/(b*Sqrt[a + b*x])}
{1/(a + b*x)^(5/2), x, 1, -2/(3*b*(a + b*x)^(3/2))}


(* Integrands of the form (c*(a+b*x)^2)^n where n is a half-integer *)
{(c*(a + b*x)^2)^(5/2), x, 1, ((a + b*x)*(c*(a + b*x)^2)^(5/2))/(6*b)}
{(c*(a + b*x)^2)^(3/2), x, 1, ((a + b*x)*(c*(a + b*x)^2)^(3/2))/(4*b)}
{(c*(a + b*x)^2)^(1/2), x, 1, ((a + b*x)*Sqrt[c*(a + b*x)^2])/(2*b)}
{1/(c*(a + b*x)^2)^(1/2), x, 1, ((a + b*x)*Log[a + b*x])/(b*Sqrt[c*(a + b*x)^2])}
{1/(c*(a + b*x)^2)^(3/2), x, 1, -((a + b*x)/(2*b*(c*(a + b*x)^2)^(3/2)))}
{1/(c*(a + b*x)^2)^(5/2), x, 1, -((a + b*x)/(4*b*(c*(a + b*x)^2)^(5/2)))}


(* Integrands of the form (c*(a+b*x)^3)^n where n is a half-integer *)
{(c*(a + b*x)^3)^(5/2), x, 1, (2*(a + b*x)*(c*(a + b*x)^3)^(5/2))/(17*b)}
{(c*(a + b*x)^3)^(3/2), x, 1, (2*(a + b*x)*(c*(a + b*x)^3)^(3/2))/(11*b)}
{(c*(a + b*x)^3)^(1/2), x, 1, (2*(a + b*x)*Sqrt[c*(a + b*x)^3])/(5*b)}
{1/(c*(a + b*x)^3)^(1/2), x, 1, -((2*(a + b*x))/(b*Sqrt[c*(a + b*x)^3]))}
{1/(c*(a + b*x)^3)^(3/2), x, 1, -((2*(a + b*x))/(7*b*(c*(a + b*x)^3)^(3/2)))}
{1/(c*(a + b*x)^3)^(5/2), x, 1, -((2*(a + b*x))/(13*b*(c*(a + b*x)^3)^(5/2)))}


(* Integrands of the form (c/(a+b*x))^n where n is a half-integer *)
{(c/(a + b*x))^(5/2), x, 1, -((2*(c/(a + b*x))^(5/2)*(a + b*x))/(3*b))}
{(c/(a + b*x))^(3/2), x, 1, -((2*(c/(a + b*x))^(3/2)*(a + b*x))/b)}
{(c/(a + b*x))^(1/2), x, 1, (2*Sqrt[c/(a + b*x)]*(a + b*x))/b}
{1/(c/(a + b*x))^(1/2), x, 1, (2*(a + b*x))/(3*b*Sqrt[c/(a + b*x)])}
{1/(c/(a + b*x))^(3/2), x, 1, (2*(a + b*x))/(5*b*(c/(a + b*x))^(3/2))}
{1/(c/(a + b*x))^(5/2), x, 1, (2*(a + b*x))/(7*b*(c/(a + b*x))^(5/2))}


(* Integrands of the form (c/(a+b*x)^2)^n where n is a half-integer *)
{(c/(a + b*x)^2)^(5/2), x, 1, -(((c/(a + b*x)^2)^(5/2)*(a + b*x))/(4*b))}
{(c/(a + b*x)^2)^(3/2), x, 1, -(((c/(a + b*x)^2)^(3/2)*(a + b*x))/(2*b))}
{(c/(a + b*x)^2)^(1/2), x, 1, (Sqrt[c/(a + b*x)^2]*(a + b*x)*Log[a + b*x])/b}
{1/(c/(a + b*x)^2)^(1/2), x, 1, (a + b*x)/(2*b*Sqrt[c/(a + b*x)^2])}
{1/(c/(a + b*x)^2)^(3/2), x, 1, (a + b*x)/(4*b*(c/(a + b*x)^2)^(3/2))}
{1/(c/(a + b*x)^2)^(5/2), x, 1, (a + b*x)/(6*b*(c/(a + b*x)^2)^(5/2))}


(* Integrands of the form (c/(a+b*x)^3)^n where n is a half-integer *)
{(c/(a + b*x)^3)^(5/2), x, 1, -((2*(c/(a + b*x)^3)^(5/2)*(a + b*x))/(13*b))}
{(c/(a + b*x)^3)^(3/2), x, 1, -((2*(c/(a + b*x)^3)^(3/2)*(a + b*x))/(7*b))}
{(c/(a + b*x)^3)^(1/2), x, 1, -((2*Sqrt[c/(a + b*x)^3]*(a + b*x))/b)}
{1/(c/(a + b*x)^3)^(1/2), x, 1, (2*(a + b*x))/(5*b*Sqrt[c/(a + b*x)^3])}
{1/(c/(a + b*x)^3)^(3/2), x, 1, (2*(a + b*x))/(11*b*(c/(a + b*x)^3)^(3/2))}
{1/(c/(a + b*x)^3)^(5/2), x, 1, (2*(a + b*x))/(17*b*(c/(a + b*x)^3)^(5/2))}


{Sqrt[(3 + 5*x)^2], x, 1, (1/10)*(3 + 5*x)*Sqrt[(3 + 5*x)^2]}
{Sqrt[(6 + 10*x)^2], x, 1, (1/5)*(3 + 5*x)*Sqrt[(3 + 5*x)^2]}

{1/Sqrt[(3 + 5*x)^2], x, 1, (3 + 5*x)*(Log[3 + 5*x]/(5*Sqrt[(3 + 5*x)^2]))}
{1/Sqrt[(6 + 10*x)^2], x, 2, ((3 + 5*x)*Log[3 + 5*x])/(10*Sqrt[(3 + 5*x)^2])}


{1/(Sqrt[2 - 3*x]*Sqrt[2 + 3*x]), x, 1, (1/3)*ArcSin[(3*x)/2]}
{1/Sqrt[(-(-2 + 3*x))*(2 + 3*x)], x, 2, (1/3)*ArcSin[(3*x)/2]}
{1/Sqrt[4 - 9*x^2], x, 1, (1/3)*ArcSin[(3*x)/2]}

{1/(Sqrt[-2 - 3*x]*Sqrt[2 + 3*x]), x, 1, (Sqrt[2 + 3*x]*Log[2 + 3*x])/(3*Sqrt[-2 - 3*x])}
{1/Sqrt[-(2 + 3*x)^2], x, 1, ((2 + 3*x)*Log[2 + 3*x])/(3*Sqrt[-(2 + 3*x)^2])}


{1/(Sqrt[3 - x]*Sqrt[5 + x]), x, 1, -ArcSin[(1/4)*(-1 - x)]}
{1/Sqrt[(-(-3 + x))*(5 + x)], x, 2, -ArcSin[(1/4)*(-1 - x)]}
{1/Sqrt[15 - 2*x - x^2], x, 1, -ArcSin[(1/4)*(-1 - x)]}

{1/(Sqrt[-3 - x]*Sqrt[5 + x]), x, 1, ArcSin[4 + x]}
{1/Sqrt[(-(3 + x))*(5 + x)], x, 2, ArcSin[4 + x]}
{1/Sqrt[-15 - 8*x - x^2], x, 1, ArcSin[4 + x]}


(* Integrands of the form (c*(a+b*x))^n where n is a half-integer *)
{(c*(a + b*x))^(5/2), x, 2, (2*(c*(a + b*x))^(7/2))/(7*b*c)}
{(c*(a + b*x))^(3/2), x, 2, (2*(c*(a + b*x))^(5/2))/(5*b*c)}
{(c*(a + b*x))^(1/2), x, 2, (2*(c*(a + b*x))^(3/2))/(3*b*c)}
{1/(c*(a + b*x))^(1/2), x, 2, (2*Sqrt[c*(a + b*x)])/(b*c)}
{1/(c*(a + b*x))^(3/2), x, 2, -(2/(b*c*Sqrt[c*(a + b*x)]))}
{1/(c*(a + b*x))^(5/2), x, 2, -(2/(3*b*c*(c*(a + b*x))^(3/2)))}


(* Integrands of the form (c+d*(a+b*x))^n where n is a half-integer *)
{(c + d*(a + b*x))^(5/2), x, 2, (2*(c + d*(a + b*x))^(7/2))/(7*b*d)}
{(c + d*(a + b*x))^(3/2), x, 2, (2*(c + d*(a + b*x))^(5/2))/(5*b*d)}
{Sqrt[c + d*(a + b*x)], x, 2, (2*(c + d*(a + b*x))^(3/2))/(3*b*d)}
{1/Sqrt[c + d*(a + b*x)], x, 2, (2*Sqrt[c + d*(a + b*x)])/(b*d)}
{1/(c + d*(a + b*x))^(3/2), x, 2, -(2/(b*d*Sqrt[c + d*(a + b*x)]))}
{1/(c + d*(a + b*x))^(5/2), x, 2, -(2/(3*b*d*(c + d*(a + b*x))^(3/2)))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a+b x)^(n/2)*)


(* Integrands of the form x^m*(a+b*x)^n where m is an integer and n is a half-integer *)
{x*Sqrt[a + b*x], x, 2, -((4*a*(a + b*x)^(3/2))/(15*b^2)) + (2*x*(a + b*x)^(3/2))/(5*b)}
{x*(a + b*x)^(3/2), x, 2, -((4*a*(a + b*x)^(5/2))/(35*b^2)) + (2*x*(a + b*x)^(5/2))/(7*b)}
{x*(a + b*x)^(5/2), x, 2, -((4*a*(a + b*x)^(7/2))/(63*b^2)) + (2*x*(a + b*x)^(7/2))/(9*b)}
{x/Sqrt[a + b*x], x, 2, -((4*a*Sqrt[a + b*x])/(3*b^2)) + (2*x*Sqrt[a + b*x])/(3*b)}
{x/(a + b*x)^(3/2), x, 2, (4*a)/(b^2*Sqrt[a + b*x]) + (2*x)/(b*Sqrt[a + b*x])}
{x/(a + b*x)^(5/2), x, 2, -((4*a)/(3*b^2*(a + b*x)^(3/2))) - (2*x)/(b*(a + b*x)^(3/2))}

{x^2*Sqrt[a + b*x], x, 3, (16*a^2*(a + b*x)^(3/2))/(105*b^3) - (8*a*x*(a + b*x)^(3/2))/(35*b^2) + (2*x^2*(a + b*x)^(3/2))/(7*b)}
{x^2*(a + b*x)^(3/2), x, 3, (16*a^2*(a + b*x)^(5/2))/(315*b^3) - (8*a*x*(a + b*x)^(5/2))/(63*b^2) + (2*x^2*(a + b*x)^(5/2))/(9*b)}
{x^2*(a + b*x)^(5/2), x, 3, (16*a^2*(a + b*x)^(7/2))/(693*b^3) - (8*a*x*(a + b*x)^(7/2))/(99*b^2) + (2*x^2*(a + b*x)^(7/2))/(11*b)}
{x^2/Sqrt[a + b*x], x, 3, (16*a^2*Sqrt[a + b*x])/(15*b^3) - (8*a*x*Sqrt[a + b*x])/(15*b^2) + (2*x^2*Sqrt[a + b*x])/(5*b)}
{x^2/(a + b*x)^(3/2), x, 3, -((16*a^2)/(3*b^3*Sqrt[a + b*x])) - (8*a*x)/(3*b^2*Sqrt[a + b*x]) + (2*x^2)/(3*b*Sqrt[a + b*x])}
{x^2/(a + b*x)^(5/2), x, 3, (16*a^2)/(3*b^3*(a + b*x)^(3/2)) + (8*a*x)/(b^2*(a + b*x)^(3/2)) + (2*x^2)/(b*(a + b*x)^(3/2))}

{x^3*Sqrt[a + b*x], x, 4, -((32*a^3*(a + b*x)^(3/2))/(315*b^4)) + (16*a^2*x*(a + b*x)^(3/2))/(105*b^3) - (4*a*x^2*(a + b*x)^(3/2))/(21*b^2) + (2*x^3*(a + b*x)^(3/2))/(9*b)}
{x^3*(a + b*x)^(3/2), x, 4, -((32*a^3*(a + b*x)^(5/2))/(1155*b^4)) + (16*a^2*x*(a + b*x)^(5/2))/(231*b^3) - (4*a*x^2*(a + b*x)^(5/2))/(33*b^2) + (2*x^3*(a + b*x)^(5/2))/(11*b)}
{x^3*(a + b*x)^(5/2), x, 4, -((32*a^3*(a + b*x)^(7/2))/(3003*b^4)) + (16*a^2*x*(a + b*x)^(7/2))/(429*b^3) - (12*a*x^2*(a + b*x)^(7/2))/(143*b^2) + (2*x^3*(a + b*x)^(7/2))/(13*b)}
{x^3/Sqrt[a + b*x], x, 4, -((32*a^3*Sqrt[a + b*x])/(35*b^4)) + (16*a^2*x*Sqrt[a + b*x])/(35*b^3) - (12*a*x^2*Sqrt[a + b*x])/(35*b^2) + (2*x^3*Sqrt[a + b*x])/(7*b)}
{x^3/(a + b*x)^(3/2), x, 4, (32*a^3)/(5*b^4*Sqrt[a + b*x]) + (16*a^2*x)/(5*b^3*Sqrt[a + b*x]) - (4*a*x^2)/(5*b^2*Sqrt[a + b*x]) + (2*x^3)/(5*b*Sqrt[a + b*x])}
{x^3/(a + b*x)^(5/2), x, 4, -((32*a^3)/(3*b^4*(a + b*x)^(3/2))) - (16*a^2*x)/(b^3*(a + b*x)^(3/2)) - (4*a*x^2)/(b^2*(a + b*x)^(3/2)) + (2*x^3)/(3*b*(a + b*x)^(3/2))}

{Sqrt[a + b*x]/x, x, 2, 2*Sqrt[a + b*x] - 2*Sqrt[a]*ArcTanh[Sqrt[a + b*x]/Sqrt[a]]}
{(a + b*x)^(3/2)/x, x, 3, 2*a*Sqrt[a + b*x] + (2/3)*(a + b*x)^(3/2) - 2*a^(3/2)*ArcTanh[Sqrt[a + b*x]/Sqrt[a]]}
{(a + b*x)^(5/2)/x, x, 4, 2*a^2*Sqrt[a + b*x] + (2/3)*a*(a + b*x)^(3/2) + (2/5)*(a + b*x)^(5/2) - 2*a^(5/2)*ArcTanh[Sqrt[a + b*x]/Sqrt[a]]}
{1/(x*Sqrt[a + b*x]), x, 1, (-2*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/Sqrt[a]}
{1/(x*(a + b*x)^(3/2)), x, 2, 2/(a*Sqrt[a + b*x]) - (2*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/a^(3/2)}
{1/(x*(a + b*x)^(5/2)), x, 3, 2/(3*a*(a + b*x)^(3/2)) + 2/(a^2*Sqrt[a + b*x]) - (2*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/a^(5/2)}

{Sqrt[a + b*x]/x^2, x, 2, -(Sqrt[a + b*x]/x) - (b*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/Sqrt[a]}
{(a + b*x)^(3/2)/x^2, x, 3, 3*b*Sqrt[a + b*x] - (a + b*x)^(3/2)/x - 3*Sqrt[a]*b*ArcTanh[Sqrt[a + b*x]/Sqrt[a]]}
{(a + b*x)^(5/2)/x^2, x, 4, 5*a*b*Sqrt[a + b*x] + (5/3)*b*(a + b*x)^(3/2) - (a + b*x)^(5/2)/x - 5*a^(3/2)*b*ArcTanh[Sqrt[a + b*x]/Sqrt[a]]}
{1/(x^2*Sqrt[a + b*x]), x, 2, -(Sqrt[a + b*x]/(a*x)) + (b*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/a^(3/2)}
{1/(x^2*(a + b*x)^(3/2)), x, 3, 2/(a*x*Sqrt[a + b*x]) - (3*Sqrt[a + b*x])/(a^2*x) + (3*b*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/a^(5/2)}
{1/(x^2*(a + b*x)^(5/2)), x, 4, -((5*b)/(3*a^2*(a + b*x)^(3/2))) - 1/(a*x*(a + b*x)^(3/2)) - (5*b)/(a^3*Sqrt[a + b*x]) + (5*b*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/a^(7/2)}

{Sqrt[a + b*x]/x^3, x, 3, -(Sqrt[a + b*x]/(2*x^2)) - (b*Sqrt[a + b*x])/(4*a*x) + (b^2*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(4*a^(3/2))}
{(a + b*x)^(3/2)/x^3, x, 3, -((3*b*Sqrt[a + b*x])/(4*x)) - (a + b*x)^(3/2)/(2*x^2) - (3*b^2*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(4*Sqrt[a])}
{(a + b*x)^(5/2)/x^3, x, 4, (15/4)*b^2*Sqrt[a + b*x] - (5*b*(a + b*x)^(3/2))/(4*x) - (a + b*x)^(5/2)/(2*x^2) - (15/4)*Sqrt[a]*b^2*ArcTanh[Sqrt[a + b*x]/Sqrt[a]]}
{1/(x^3*Sqrt[a + b*x]), x, 3, -(Sqrt[a + b*x]/(2*a*x^2)) + (3*b*Sqrt[a + b*x])/(4*a^2*x) - (3*b^2*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(4*a^(5/2))}
{1/(x^3*(a + b*x)^(3/2)), x, 4, 2/(a*x^2*Sqrt[a + b*x]) - (5*Sqrt[a + b*x])/(2*a^2*x^2) + (15*b*Sqrt[a + b*x])/(4*a^3*x) - (15*b^2*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(4*a^(7/2))}
{1/(x^3*(a + b*x)^(5/2)), x, 5, 2/(3*a*x^2*(a + b*x)^(3/2)) + 14/(3*a^2*x^2*Sqrt[a + b*x]) - (35*Sqrt[a + b*x])/(6*a^3*x^2) + (35*b*Sqrt[a + b*x])/(4*a^4*x) - (35*b^2*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(4*a^(9/2))}


(* Integrands of the form x^m*(-a+b*x)^n where m is an integer and n is a half-integer *)
{Sqrt[-a + b*x]/x, x, 2, 2*Sqrt[-a + b*x] - 2*Sqrt[a]*ArcTan[Sqrt[-a + b*x]/Sqrt[a]]}
{(-a + b*x)^(3/2)/x, x, 3, -2*a*Sqrt[-a + b*x] + (2/3)*(-a + b*x)^(3/2) + 2*a^(3/2)*ArcTan[Sqrt[-a + b*x]/Sqrt[a]]}
{(-a + b*x)^(5/2)/x, x, 4, 2*a^2*Sqrt[-a + b*x] - (2/3)*a*(-a + b*x)^(3/2) + (2/5)*(-a + b*x)^(5/2) - 2*a^(5/2)*ArcTan[Sqrt[-a + b*x]/Sqrt[a]]}
{1/(x*Sqrt[-a + b*x]), x, 1, (2*ArcTan[Sqrt[-a + b*x]/Sqrt[a]])/Sqrt[a]}
{1/(x*(-a + b*x)^(3/2)), x, 2, -2/(a*Sqrt[-a + b*x]) - (2*ArcTan[Sqrt[-a + b*x]/Sqrt[a]])/a^(3/2)}
{1/(x*(-a + b*x)^(5/2)), x, 3, -(2/(3*a*(-a + b*x)^(3/2))) + 2/(a^2*Sqrt[-a + b*x]) + (2*ArcTan[Sqrt[-a + b*x]/Sqrt[a]])/a^(5/2)}

{Sqrt[-a + b*x]/x^2, x, 2, -(Sqrt[-a + b*x]/x) + (b*ArcTan[Sqrt[-a + b*x]/Sqrt[a]])/Sqrt[a]}
{(-a + b*x)^(3/2)/x^2, x, 3, 3*b*Sqrt[-a + b*x] - (-a + b*x)^(3/2)/x - 3*Sqrt[a]*b*ArcTan[Sqrt[-a + b*x]/Sqrt[a]]}
{(-a + b*x)^(5/2)/x^2, x, 4, -5*a*b*Sqrt[-a + b*x] + (5/3)*b*(-a + b*x)^(3/2) - (-a + b*x)^(5/2)/x + 5*a^(3/2)*b*ArcTan[Sqrt[-a + b*x]/Sqrt[a]]}
{1/(x^2*Sqrt[-a + b*x]), x, 2, Sqrt[-a + b*x]/(a*x) + (b*ArcTan[Sqrt[-a + b*x]/Sqrt[a]])/a^(3/2)}
{1/(x^2*(-a + b*x)^(3/2)), x, 3, -(2/(a*x*Sqrt[-a + b*x])) - (3*Sqrt[-a + b*x])/(a^2*x) - (3*b*ArcTan[Sqrt[-a + b*x]/Sqrt[a]])/a^(5/2)}
{1/(x^2*(-a + b*x)^(5/2)), x, 4, -((5*b)/(3*a^2*(-a + b*x)^(3/2))) + 1/(a*x*(-a + b*x)^(3/2)) + (5*b)/(a^3*Sqrt[-a + b*x]) + (5*b*ArcTan[Sqrt[-a + b*x]/Sqrt[a]])/a^(7/2)}

{Sqrt[-a + b*x]/x^3, x, 3, -(Sqrt[-a + b*x]/(2*x^2)) + (b*Sqrt[-a + b*x])/(4*a*x) + (b^2*ArcTan[Sqrt[-a + b*x]/Sqrt[a]])/(4*a^(3/2))}
{(-a + b*x)^(3/2)/x^3, x, 3, -((3*b*Sqrt[-a + b*x])/(4*x)) - (-a + b*x)^(3/2)/(2*x^2) + (3*b^2*ArcTan[Sqrt[-a + b*x]/Sqrt[a]])/(4*Sqrt[a])}
{(-a + b*x)^(5/2)/x^3, x, 4, (15/4)*b^2*Sqrt[-a + b*x] - (5*b*(-a + b*x)^(3/2))/(4*x) - (-a + b*x)^(5/2)/(2*x^2) - (15/4)*Sqrt[a]*b^2*ArcTan[Sqrt[-a + b*x]/Sqrt[a]]}
{1/(x^3*Sqrt[-a + b*x]), x, 3, Sqrt[-a + b*x]/(2*a*x^2) + (3*b*Sqrt[-a + b*x])/(4*a^2*x) + (3*b^2*ArcTan[Sqrt[-a + b*x]/Sqrt[a]])/(4*a^(5/2))}
{1/(x^3*(-a + b*x)^(3/2)), x, 4, -(2/(a*x^2*Sqrt[-a + b*x])) - (5*Sqrt[-a + b*x])/(2*a^2*x^2) - (15*b*Sqrt[-a + b*x])/(4*a^3*x) - (15*b^2*ArcTan[Sqrt[-a + b*x]/Sqrt[a]])/(4*a^(7/2))}
{1/(x^3*(-a + b*x)^(5/2)), x, 5, -(2/(3*a*x^2*(-a + b*x)^(3/2))) + 14/(3*a^2*x^2*Sqrt[-a + b*x]) + (35*Sqrt[-a + b*x])/(6*a^3*x^2) + (35*b*Sqrt[-a + b*x])/(4*a^4*x) + (35*b^2*ArcTan[Sqrt[-a + b*x]/Sqrt[a]])/(4*a^(9/2))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^(m/2) (a+b x)^n*)


(* Integrands of the form x^m*(a+b*x)^n where m is a half-integer and n is an integer *)
{Sqrt[x]*(a + b*x), x, 2, (2/3)*a*x^(3/2) + (2/5)*b*x^(5/2)}
{Sqrt[x]*(a + b*x)^2, x, 2, (2/3)*a^2*x^(3/2) + (4/5)*a*b*x^(5/2) + (2/7)*b^2*x^(7/2)}
{Sqrt[x]*(a + b*x)^3, x, 2, (2/3)*a^3*x^(3/2) + (6/5)*a^2*b*x^(5/2) + (6/7)*a*b^2*x^(7/2) + (2/9)*b^3*x^(9/2)}
{Sqrt[x]/(a + b*x), x, 2, (2*Sqrt[x])/b - (2*Sqrt[a]*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a]])/b^(3/2)}
{Sqrt[x]/(a + b*x)^2, x, 2, -(Sqrt[x]/(b*(a + b*x))) + ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a]]/(Sqrt[a]*b^(3/2))}
{Sqrt[x]/(a + b*x)^3, x, 3, -(Sqrt[x]/(2*b*(a + b*x)^2)) + Sqrt[x]/(4*a*b*(a + b*x)) + ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a]]/(4*a^(3/2)*b^(3/2))}

{x^(3/2)*(a + b*x), x, 2, (2/5)*a*x^(5/2) + (2/7)*b*x^(7/2)}
{x^(3/2)*(a + b*x)^2, x, 2, (2/5)*a^2*x^(5/2) + (4/7)*a*b*x^(7/2) + (2/9)*b^2*x^(9/2)}
{x^(3/2)*(a + b*x)^3, x, 2, (2/5)*a^3*x^(5/2) + (6/7)*a^2*b*x^(7/2) + (2/3)*a*b^2*x^(9/2) + (2/11)*b^3*x^(11/2)}
{x^(3/2)/(a + b*x), x, 3, -((2*a*Sqrt[x])/b^2) + (2*x^(3/2))/(3*b) + (2*a^(3/2)*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a]])/b^(5/2)}
{x^(3/2)/(a + b*x)^2, x, 3, (3*Sqrt[x])/b^2 - x^(3/2)/(b*(a + b*x)) - (3*Sqrt[a]*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a]])/b^(5/2)}
{x^(3/2)/(a + b*x)^3, x, 3, -(x^(3/2)/(2*b*(a + b*x)^2)) - (3*Sqrt[x])/(4*b^2*(a + b*x)) + (3*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a]])/(4*Sqrt[a]*b^(5/2))}

{x^(5/2)*(a + b*x), x, 2, (2/7)*a*x^(7/2) + (2/9)*b*x^(9/2)}
{x^(5/2)*(a + b*x)^2, x, 2, (2/7)*a^2*x^(7/2) + (4/9)*a*b*x^(9/2) + (2/11)*b^2*x^(11/2)}
{x^(5/2)*(a + b*x)^3, x, 2, (2/7)*a^3*x^(7/2) + (2/3)*a^2*b*x^(9/2) + (6/11)*a*b^2*x^(11/2) + (2/13)*b^3*x^(13/2)}
{x^(5/2)/(a + b*x), x, 4, (2*a^2*Sqrt[x])/b^3 - (2*a*x^(3/2))/(3*b^2) + (2*x^(5/2))/(5*b) - (2*a^(5/2)*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a]])/b^(7/2)}
{x^(5/2)/(a + b*x)^2, x, 4, -((5*a*Sqrt[x])/b^3) + (5*x^(3/2))/(3*b^2) - x^(5/2)/(b*(a + b*x)) + (5*a^(3/2)*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a]])/b^(7/2)}
{x^(5/2)/(a + b*x)^3, x, 4, (15*Sqrt[x])/(4*b^3) - x^(5/2)/(2*b*(a + b*x)^2) - (5*x^(3/2))/(4*b^2*(a + b*x)) - (15*Sqrt[a]*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a]])/(4*b^(7/2))}

{(a + b*x)/Sqrt[x], x, 2, 2*a*Sqrt[x] + (2/3)*b*x^(3/2)}
{(a + b*x)^2/Sqrt[x], x, 2, 2*a^2*Sqrt[x] + (4/3)*a*b*x^(3/2) + (2/5)*b^2*x^(5/2)}
{(a + b*x)^3/Sqrt[x], x, 2, 2*a^3*Sqrt[x] + 2*a^2*b*x^(3/2) + (6/5)*a*b^2*x^(5/2) + (2/7)*b^3*x^(7/2)}
{1/(Sqrt[x]*(a + b*x)), x, 1, (2*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a]])/(Sqrt[a]*Sqrt[b])}
{1/(Sqrt[x]*(a + b*x)^2), x, 2, Sqrt[x]/(a*(a + b*x)) + ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a]]/(a^(3/2)*Sqrt[b])}
{1/(Sqrt[x]*(a + b*x)^3), x, 3, Sqrt[x]/(2*a*(a + b*x)^2) + (3*Sqrt[x])/(4*a^2*(a + b*x)) + (3*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a]])/(4*a^(5/2)*Sqrt[b])}

{(a + b*x)/x^(3/2), x, 2, -((2*a)/Sqrt[x]) + 2*b*Sqrt[x]}
{(a + b*x)^2/x^(3/2), x, 2, -((2*a^2)/Sqrt[x]) + 4*a*b*Sqrt[x] + (2/3)*b^2*x^(3/2)}
{(a + b*x)^3/x^(3/2), x, 2, -((2*a^3)/Sqrt[x]) + 6*a^2*b*Sqrt[x] + 2*a*b^2*x^(3/2) + (2/5)*b^3*x^(5/2)}
{1/(x^(3/2)*(a + b*x)), x, 2, -2/(a*Sqrt[x]) - (2*Sqrt[b]*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a]])/a^(3/2)}
{1/(x^(3/2)*(a + b*x)^2), x, 3, -(2/(a*Sqrt[x]*(a + b*x))) - (3*b*Sqrt[x])/(a^2*(a + b*x)) - (3*Sqrt[b]*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a]])/a^(5/2)}
{1/(x^(3/2)*(a + b*x)^3), x, 4, -(2/(a*Sqrt[x]*(a + b*x)^2)) - (5*b*Sqrt[x])/(2*a^2*(a + b*x)^2) - (15*b*Sqrt[x])/(4*a^3*(a + b*x)) - (15*Sqrt[b]*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a]])/(4*a^(7/2))}

{(a + b*x)/x^(5/2), x, 2, -((2*a)/(3*x^(3/2))) - (2*b)/Sqrt[x]}
{(a + b*x)^2/x^(5/2), x, 2, -((2*a^2)/(3*x^(3/2))) - (4*a*b)/Sqrt[x] + 2*b^2*Sqrt[x]}
{(a + b*x)^3/x^(5/2), x, 2, -((2*a^3)/(3*x^(3/2))) - (6*a^2*b)/Sqrt[x] + 6*a*b^2*Sqrt[x] + (2/3)*b^3*x^(3/2)}
{1/(x^(5/2)*(a + b*x)), x, 3, -(2/(3*a*x^(3/2))) + (2*b)/(a^2*Sqrt[x]) + (2*b^(3/2)*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a]])/a^(5/2)}
{1/(x^(5/2)*(a + b*x)^2), x, 4, -(5/(3*a^2*x^(3/2))) + (5*b)/(a^3*Sqrt[x]) + 1/(a*x^(3/2)*(a + b*x)) + (5*b^(3/2)*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a]])/a^(7/2)}
{1/(x^(5/2)*(a + b*x)^3), x, 5, -(2/(3*a*x^(3/2)*(a + b*x)^2)) + (14*b)/(3*a^2*Sqrt[x]*(a + b*x)^2) + (35*b^2*Sqrt[x])/(6*a^3*(a + b*x)^2) + (35*b^2*Sqrt[x])/(4*a^4*(a + b*x)) + (35*b^(3/2)*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a]])/(4*a^(9/2))}


(* Integrands of the form x^m*(-a+b*x)^n where m is a half-integer and n is an integer *)
{Sqrt[x]*(-a + b*x), x, 2, (-(2/3))*a*x^(3/2) + (2/5)*b*x^(5/2)}
{Sqrt[x]*(-a + b*x)^2, x, 2, (2/3)*a^2*x^(3/2) - (4/5)*a*b*x^(5/2) + (2/7)*b^2*x^(7/2)}
{Sqrt[x]*(-a + b*x)^3, x, 2, (-(2/3))*a^3*x^(3/2) + (6/5)*a^2*b*x^(5/2) - (6/7)*a*b^2*x^(7/2) + (2/9)*b^3*x^(9/2)}
{Sqrt[x]/(-a + b*x), x, 2, (2*Sqrt[x])/b - (2*Sqrt[a]*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a]])/b^(3/2)}
{Sqrt[x]/(-a + b*x)^2, x, 2, Sqrt[x]/(b*(a - b*x)) - ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a]]/(Sqrt[a]*b^(3/2))}
{Sqrt[x]/(-a + b*x)^3, x, 3, -(Sqrt[x]/(2*b*(a - b*x)^2)) + Sqrt[x]/(4*a*b*(a - b*x)) + ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a]]/(4*a^(3/2)*b^(3/2))}

{x^(3/2)*(-a + b*x), x, 2, (-(2/5))*a*x^(5/2) + (2/7)*b*x^(7/2)}
{x^(3/2)*(-a + b*x)^2, x, 2, (2/5)*a^2*x^(5/2) - (4/7)*a*b*x^(7/2) + (2/9)*b^2*x^(9/2)}
{x^(3/2)*(-a + b*x)^3, x, 2, (-(2/5))*a^3*x^(5/2) + (6/7)*a^2*b*x^(7/2) - (2/3)*a*b^2*x^(9/2) + (2/11)*b^3*x^(11/2)}
{x^(3/2)/(-a + b*x), x, 3, (2*a*Sqrt[x])/b^2 + (2*x^(3/2))/(3*b) - (2*a^(3/2)*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a]])/b^(5/2)}
{x^(3/2)/(-a + b*x)^2, x, 3, (3*Sqrt[x])/b^2 + x^(3/2)/(b*(a - b*x)) - (3*Sqrt[a]*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a]])/b^(5/2)}
{x^(3/2)/(-a + b*x)^3, x, 3, -(x^(3/2)/(2*b*(a - b*x)^2)) + (3*Sqrt[x])/(4*b^2*(a - b*x)) - (3*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a]])/(4*Sqrt[a]*b^(5/2))}

{x^(5/2)*(-a + b*x), x, 2, (-(2/7))*a*x^(7/2) + (2/9)*b*x^(9/2)}
{x^(5/2)*(-a + b*x)^2, x, 2, (2/7)*a^2*x^(7/2) - (4/9)*a*b*x^(9/2) + (2/11)*b^2*x^(11/2)}
{x^(5/2)*(-a + b*x)^3, x, 2, (-(2/7))*a^3*x^(7/2) + (2/3)*a^2*b*x^(9/2) - (6/11)*a*b^2*x^(11/2) + (2/13)*b^3*x^(13/2)}
{x^(5/2)/(-a + b*x), x, 4, (2*a^2*Sqrt[x])/b^3 + (2*a*x^(3/2))/(3*b^2) + (2*x^(5/2))/(5*b) - (2*a^(5/2)*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a]])/b^(7/2)}
{x^(5/2)/(-a + b*x)^2, x, 4, (5*a*Sqrt[x])/b^3 + (5*x^(3/2))/(3*b^2) + x^(5/2)/(b*(a - b*x)) - (5*a^(3/2)*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a]])/b^(7/2)}
{x^(5/2)/(-a + b*x)^3, x, 4, (15*Sqrt[x])/(4*b^3) - x^(5/2)/(2*b*(a - b*x)^2) + (5*x^(3/2))/(4*b^2*(a - b*x)) - (15*Sqrt[a]*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a]])/(4*b^(7/2))}

{(-a + b*x)/Sqrt[x], x, 2, -2*a*Sqrt[x] + (2/3)*b*x^(3/2)}
{(-a + b*x)^2/Sqrt[x], x, 2, 2*a^2*Sqrt[x] - (4/3)*a*b*x^(3/2) + (2/5)*b^2*x^(5/2)}
{(-a + b*x)^3/Sqrt[x], x, 2, -2*a^3*Sqrt[x] + 2*a^2*b*x^(3/2) - (6/5)*a*b^2*x^(5/2) + (2/7)*b^3*x^(7/2)}
{1/(Sqrt[x]*(-a + b*x)), x, 1, (-2*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a]])/(Sqrt[a]*Sqrt[b])}
{1/(Sqrt[x]*(-a + b*x)^2), x, 2, Sqrt[x]/(a*(a - b*x)) + ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a]]/(a^(3/2)*Sqrt[b])}
{1/(Sqrt[x]*(-a + b*x)^3), x, 3, -(Sqrt[x]/(2*a*(a - b*x)^2)) - (3*Sqrt[x])/(4*a^2*(a - b*x)) - (3*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a]])/(4*a^(5/2)*Sqrt[b])}

{(-a + b*x)/x^(3/2), x, 2, (2*a)/Sqrt[x] + 2*b*Sqrt[x]}
{(-a + b*x)^2/x^(3/2), x, 2, -((2*a^2)/Sqrt[x]) - 4*a*b*Sqrt[x] + (2/3)*b^2*x^(3/2)}
{(-a + b*x)^3/x^(3/2), x, 2, (2*a^3)/Sqrt[x] + 6*a^2*b*Sqrt[x] - 2*a*b^2*x^(3/2) + (2/5)*b^3*x^(5/2)}
{1/(x^(3/2)*(-a + b*x)), x, 2, 2/(a*Sqrt[x]) - (2*Sqrt[b]*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a]])/a^(3/2)}
{1/(x^(3/2)*(-a + b*x)^2), x, 3, -(2/(a*Sqrt[x]*(a - b*x))) + (3*b*Sqrt[x])/(a^2*(a - b*x)) + (3*Sqrt[b]*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a]])/a^(5/2)}
{1/(x^(3/2)*(-a + b*x)^3), x, 4, 2/(a*Sqrt[x]*(a - b*x)^2) - (5*b*Sqrt[x])/(2*a^2*(a - b*x)^2) - (15*b*Sqrt[x])/(4*a^3*(a - b*x)) - (15*Sqrt[b]*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a]])/(4*a^(7/2))}

{(-a + b*x)/x^(5/2), x, 2, (2*a)/(3*x^(3/2)) - (2*b)/Sqrt[x]}
{(-a + b*x)^2/x^(5/2), x, 2, -((2*a^2)/(3*x^(3/2))) + (4*a*b)/Sqrt[x] + 2*b^2*Sqrt[x]}
{(-a + b*x)^3/x^(5/2), x, 2, (2*a^3)/(3*x^(3/2)) - (6*a^2*b)/Sqrt[x] - 6*a*b^2*Sqrt[x] + (2/3)*b^3*x^(3/2)}
{1/(x^(5/2)*(-a + b*x)), x, 3, 2/(3*a*x^(3/2)) + (2*b)/(a^2*Sqrt[x]) - (2*b^(3/2)*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a]])/a^(5/2)}
{1/(x^(5/2)*(-a + b*x)^2), x, 4, -(5/(3*a^2*x^(3/2))) - (5*b)/(a^3*Sqrt[x]) + 1/(a*x^(3/2)*(a - b*x)) + (5*b^(3/2)*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a]])/a^(7/2)}
{1/(x^(5/2)*(-a + b*x)^3), x, 5, 2/(3*a*x^(3/2)*(a - b*x)^2) + (14*b)/(3*a^2*Sqrt[x]*(a - b*x)^2) - (35*b^2*Sqrt[x])/(6*a^3*(a - b*x)^2) - (35*b^2*Sqrt[x])/(4*a^4*(a - b*x)) - (35*b^(3/2)*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a]])/(4*a^(9/2))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^(m/2) (a+b x)^(n/2)*)


(* Integrands of the form x^m*(2+b*x)^n where m and n are half-integers *)
{Sqrt[x]*Sqrt[2 + b*x], x, 3, (Sqrt[x]*Sqrt[2 + b*x])/(2*b) + (1/2)*x^(3/2)*Sqrt[2 + b*x] - ArcSinh[(Sqrt[b]*Sqrt[x])/Sqrt[2]]/b^(3/2)}
{Sqrt[x]*(2 + b*x)^(3/2), x, 4, -((Sqrt[x]*Sqrt[2 + b*x])/(2*b)) - (Sqrt[x]*(2 + b*x)^(3/2))/(6*b) + (Sqrt[x]*(2 + b*x)^(5/2))/(3*b) - ArcSinh[(Sqrt[b]*Sqrt[x])/Sqrt[2]]/b^(3/2)}
{Sqrt[x]*(2 + b*x)^(5/2), x, 5, -((5*Sqrt[x]*Sqrt[2 + b*x])/(8*b)) - (5*Sqrt[x]*(2 + b*x)^(3/2))/(24*b) - (Sqrt[x]*(2 + b*x)^(5/2))/(12*b) + (Sqrt[x]*(2 + b*x)^(7/2))/(4*b) - (5*ArcSinh[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/(4*b^(3/2))}
{Sqrt[x]/Sqrt[2 + b*x], x, 2, (Sqrt[x]*Sqrt[2 + b*x])/b - (2*ArcSinh[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/b^(3/2)}
{Sqrt[x]/(2 + b*x)^(3/2), x, 2, (-2*Sqrt[x])/(b*Sqrt[2 + b*x]) + (2*ArcSinh[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/b^(3/2)}
{Sqrt[x]/(2 + b*x)^(5/2), x, 1, x^(3/2)/(3*(2 + b*x)^(3/2))}

{x^(3/2)*Sqrt[2 + b*x], x, 4, -((Sqrt[x]*Sqrt[2 + b*x])/(2*b^2)) + (x^(3/2)*Sqrt[2 + b*x])/(6*b) + (1/3)*x^(5/2)*Sqrt[2 + b*x] + ArcSinh[(Sqrt[b]*Sqrt[x])/Sqrt[2]]/b^(5/2)}
{x^(3/2)*(2 + b*x)^(3/2), x, 5, -((3*Sqrt[x]*Sqrt[2 + b*x])/(8*b^2)) + (x^(3/2)*Sqrt[2 + b*x])/(8*b) + (1/4)*x^(5/2)*Sqrt[2 + b*x] + (1/4)*x^(5/2)*(2 + b*x)^(3/2) + (3*ArcSinh[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/(4*b^(5/2))}
{x^(3/2)*(2 + b*x)^(5/2), x, 6, (3*Sqrt[x]*Sqrt[2 + b*x])/(8*b^2) + (Sqrt[x]*(2 + b*x)^(3/2))/(8*b^2) + (Sqrt[x]*(2 + b*x)^(5/2))/(20*b^2) - (3*Sqrt[x]*(2 + b*x)^(7/2))/(20*b^2) + (x^(3/2)*(2 + b*x)^(7/2))/(5*b) + (3*ArcSinh[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/(4*b^(5/2))}
{x^(3/2)/Sqrt[2 + b*x], x, 3, -((3*Sqrt[x]*Sqrt[2 + b*x])/(2*b^2)) + (x^(3/2)*Sqrt[2 + b*x])/(2*b) + (3*ArcSinh[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/b^(5/2)}
{x^(3/2)/(2 + b*x)^(3/2), x, 3, -((2*x^(3/2))/(b*Sqrt[2 + b*x])) + (3*Sqrt[x]*Sqrt[2 + b*x])/b^2 - (6*ArcSinh[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/b^(5/2)}
{x^(3/2)/(2 + b*x)^(5/2), x, 3, -((2*x^(3/2))/(3*b*(2 + b*x)^(3/2))) - (2*Sqrt[x])/(b^2*Sqrt[2 + b*x]) + (2*ArcSinh[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/b^(5/2)}

{x^(5/2)*Sqrt[2 + b*x], x, 5, (5*Sqrt[x]*Sqrt[2 + b*x])/(8*b^3) - (5*x^(3/2)*Sqrt[2 + b*x])/(24*b^2) + (x^(5/2)*Sqrt[2 + b*x])/(12*b) + (1/4)*x^(7/2)*Sqrt[2 + b*x] - (5*ArcSinh[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/(4*b^(7/2))}
{x^(5/2)*(2 + b*x)^(3/2), x, 6, (3*Sqrt[x]*Sqrt[2 + b*x])/(8*b^3) - (x^(3/2)*Sqrt[2 + b*x])/(8*b^2) + (x^(5/2)*Sqrt[2 + b*x])/(20*b) + (3/20)*x^(7/2)*Sqrt[2 + b*x] + (1/5)*x^(7/2)*(2 + b*x)^(3/2) - (3*ArcSinh[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/(4*b^(7/2))}
{x^(5/2)*(2 + b*x)^(5/2), x, 7, (5*Sqrt[x]*Sqrt[2 + b*x])/(16*b^3) - (5*x^(3/2)*Sqrt[2 + b*x])/(48*b^2) + (x^(5/2)*Sqrt[2 + b*x])/(24*b) + (1/8)*x^(7/2)*Sqrt[2 + b*x] + (1/6)*x^(7/2)*(2 + b*x)^(3/2) + (1/6)*x^(7/2)*(2 + b*x)^(5/2) - (5*ArcSinh[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/(8*b^(7/2))}
{x^(5/2)/Sqrt[2 + b*x], x, 4, (5*Sqrt[x]*Sqrt[2 + b*x])/(2*b^3) - (5*x^(3/2)*Sqrt[2 + b*x])/(6*b^2) + (x^(5/2)*Sqrt[2 + b*x])/(3*b) - (5*ArcSinh[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/b^(7/2)}
{x^(5/2)/(2 + b*x)^(3/2), x, 4, -((2*x^(5/2))/(b*Sqrt[2 + b*x])) - (15*Sqrt[x]*Sqrt[2 + b*x])/(2*b^3) + (5*x^(3/2)*Sqrt[2 + b*x])/(2*b^2) + (15*ArcSinh[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/b^(7/2)}
{x^(5/2)/(2 + b*x)^(5/2), x, 4, -((2*x^(5/2))/(3*b*(2 + b*x)^(3/2))) - (10*x^(3/2))/(3*b^2*Sqrt[2 + b*x]) + (5*Sqrt[x]*Sqrt[2 + b*x])/b^3 - (10*ArcSinh[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/b^(7/2)}

{Sqrt[2 + b*x]/Sqrt[x], x, 2, Sqrt[x]*Sqrt[2 + b*x] + (2*ArcSinh[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/Sqrt[b]}
{(2 + b*x)^(3/2)/Sqrt[x], x, 3, (3/2)*Sqrt[x]*Sqrt[2 + b*x] + (1/2)*Sqrt[x]*(2 + b*x)^(3/2) + (3*ArcSinh[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/Sqrt[b]}
{(2 + b*x)^(5/2)/Sqrt[x], x, 4, (5/2)*Sqrt[x]*Sqrt[2 + b*x] + (5/6)*Sqrt[x]*(2 + b*x)^(3/2) + (1/3)*Sqrt[x]*(2 + b*x)^(5/2) + (5*ArcSinh[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/Sqrt[b]}
{1/(Sqrt[x]*Sqrt[2 + b*x]), x, 1, (2*ArcSinh[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/Sqrt[b]}
{1/(Sqrt[x]*(2 + b*x)^(3/2)), x, 1, Sqrt[x]/Sqrt[2 + b*x]}
{1/(Sqrt[x]*(2 + b*x)^(5/2)), x, 2, Sqrt[x]/(3*(2 + b*x)^(3/2)) + Sqrt[x]/(3*Sqrt[2 + b*x])}

{Sqrt[2 + b*x]/x^(3/2), x, 2, (-2*Sqrt[2 + b*x])/Sqrt[x] + 2*Sqrt[b]*ArcSinh[(Sqrt[b]*Sqrt[x])/Sqrt[2]]}
{(2 + b*x)^(3/2)/x^(3/2), x, 3, 3*b*Sqrt[x]*Sqrt[2 + b*x] - (2*(2 + b*x)^(3/2))/Sqrt[x] + 6*Sqrt[b]*ArcSinh[(Sqrt[b]*Sqrt[x])/Sqrt[2]]}
{(2 + b*x)^(5/2)/x^(3/2), x, 4, (15/2)*b*Sqrt[x]*Sqrt[2 + b*x] + (5/2)*b*Sqrt[x]*(2 + b*x)^(3/2) - (2*(2 + b*x)^(5/2))/Sqrt[x] + 15*Sqrt[b]*ArcSinh[(Sqrt[b]*Sqrt[x])/Sqrt[2]]}
{1/(x^(3/2)*Sqrt[2 + b*x]), x, 1, -(Sqrt[2 + b*x]/Sqrt[x])}
{1/(x^(3/2)*(2 + b*x)^(3/2)), x, 2, 1/(Sqrt[x]*Sqrt[2 + b*x]) - Sqrt[2 + b*x]/Sqrt[x]}
{1/(x^(3/2)*(2 + b*x)^(5/2)), x, 3, -(1/(Sqrt[x]*(2 + b*x)^(3/2))) - (2*b*Sqrt[x])/(3*(2 + b*x)^(3/2)) - (2*b*Sqrt[x])/(3*Sqrt[2 + b*x])}

{Sqrt[2 + b*x]/x^(5/2), x, 1, -(2 + b*x)^(3/2)/(3*x^(3/2))}
{(2 + b*x)^(3/2)/x^(5/2), x, 3, -((2*b*Sqrt[2 + b*x])/Sqrt[x]) - (2*(2 + b*x)^(3/2))/(3*x^(3/2)) + 2*b^(3/2)*ArcSinh[(Sqrt[b]*Sqrt[x])/Sqrt[2]]}
{(2 + b*x)^(5/2)/x^(5/2), x, 4, 5*b^2*Sqrt[x]*Sqrt[2 + b*x] - (10*b*(2 + b*x)^(3/2))/(3*Sqrt[x]) - (2*(2 + b*x)^(5/2))/(3*x^(3/2)) + 10*b^(3/2)*ArcSinh[(Sqrt[b]*Sqrt[x])/Sqrt[2]]}
{1/(x^(5/2)*Sqrt[2 + b*x]), x, 2, -(Sqrt[2 + b*x]/(3*x^(3/2))) + (b*Sqrt[2 + b*x])/(3*Sqrt[x])}
{1/(x^(5/2)*(2 + b*x)^(3/2)), x, 3, 1/(x^(3/2)*Sqrt[2 + b*x]) - (2*Sqrt[2 + b*x])/(3*x^(3/2)) + (2*b*Sqrt[2 + b*x])/(3*Sqrt[x])}
{1/(x^(5/2)*(2 + b*x)^(5/2)), x, 4, 1/(3*x^(3/2)*(2 + b*x)^(3/2)) + 1/(x^(3/2)*Sqrt[2 + b*x]) - (2*Sqrt[2 + b*x])/(3*x^(3/2)) + (2*b*Sqrt[2 + b*x])/(3*Sqrt[x])}


(* Integrands of the form x^m*(a+b*x)^n where m and n are half-integers *)
{Sqrt[x]*Sqrt[a + b*x], x, 3, (a*Sqrt[x]*Sqrt[a + b*x])/(4*b) + (1/2)*x^(3/2)*Sqrt[a + b*x] - (a^2*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a + b*x]])/(4*b^(3/2))}
{Sqrt[x]*(a + b*x)^(3/2), x, 4, -((a^2*Sqrt[x]*Sqrt[a + b*x])/(8*b)) - (a*Sqrt[x]*(a + b*x)^(3/2))/(12*b) + (Sqrt[x]*(a + b*x)^(5/2))/(3*b) - (a^3*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a + b*x]])/(8*b^(3/2))}
{Sqrt[x]*(a + b*x)^(5/2), x, 5, -((5*a^3*Sqrt[x]*Sqrt[a + b*x])/(64*b)) - (5*a^2*Sqrt[x]*(a + b*x)^(3/2))/(96*b) - (a*Sqrt[x]*(a + b*x)^(5/2))/(24*b) + (Sqrt[x]*(a + b*x)^(7/2))/(4*b) - (5*a^4*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a + b*x]])/(64*b^(3/2))}
{Sqrt[x]/Sqrt[a + b*x], x, 2, (Sqrt[x]*Sqrt[a + b*x])/b - (a*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a + b*x]])/b^(3/2)}
{Sqrt[x]/(a + b*x)^(3/2), x, 2, (-2*Sqrt[x])/(b*Sqrt[a + b*x]) + (2*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a + b*x]])/b^(3/2)}
{Sqrt[x]/(a + b*x)^(5/2), x, 1, (2*x^(3/2))/(3*a*(a + b*x)^(3/2))}

{x^(3/2)*Sqrt[a + b*x], x, 4, -((a^2*Sqrt[x]*Sqrt[a + b*x])/(8*b^2)) + (a*x^(3/2)*Sqrt[a + b*x])/(12*b) + (1/3)*x^(5/2)*Sqrt[a + b*x] + (a^3*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a + b*x]])/(8*b^(5/2))}
{x^(3/2)*(a + b*x)^(3/2), x, 5, -((3*a^3*Sqrt[x]*Sqrt[a + b*x])/(64*b^2)) + (a^2*x^(3/2)*Sqrt[a + b*x])/(32*b) + (1/8)*a*x^(5/2)*Sqrt[a + b*x] + (1/4)*x^(5/2)*(a + b*x)^(3/2) + (3*a^4*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a + b*x]])/(64*b^(5/2))}
{x^(3/2)*(a + b*x)^(5/2), x, 6, (3*a^4*Sqrt[x]*Sqrt[a + b*x])/(128*b^2) + (a^3*Sqrt[x]*(a + b*x)^(3/2))/(64*b^2) + (a^2*Sqrt[x]*(a + b*x)^(5/2))/(80*b^2) - (3*a*Sqrt[x]*(a + b*x)^(7/2))/(40*b^2) + (x^(3/2)*(a + b*x)^(7/2))/(5*b) + (3*a^5*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a + b*x]])/(128*b^(5/2))}
{x^(3/2)/Sqrt[a + b*x], x, 3, -((3*a*Sqrt[x]*Sqrt[a + b*x])/(4*b^2)) + (x^(3/2)*Sqrt[a + b*x])/(2*b) + (3*a^2*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a + b*x]])/(4*b^(5/2))}
{x^(3/2)/(a + b*x)^(3/2), x, 3, -((2*x^(3/2))/(b*Sqrt[a + b*x])) + (3*Sqrt[x]*Sqrt[a + b*x])/b^2 - (3*a*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a + b*x]])/b^(5/2)}
{x^(3/2)/(a + b*x)^(5/2), x, 3, -((2*x^(3/2))/(3*b*(a + b*x)^(3/2))) - (2*Sqrt[x])/(b^2*Sqrt[a + b*x]) + (2*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a + b*x]])/b^(5/2)}

{x^(5/2)*Sqrt[a + b*x], x, 5, (5*a^3*Sqrt[x]*Sqrt[a + b*x])/(64*b^3) - (5*a^2*x^(3/2)*Sqrt[a + b*x])/(96*b^2) + (a*x^(5/2)*Sqrt[a + b*x])/(24*b) + (1/4)*x^(7/2)*Sqrt[a + b*x] - (5*a^4*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a + b*x]])/(64*b^(7/2))}
{x^(5/2)*(a + b*x)^(3/2), x, 6, (3*a^4*Sqrt[x]*Sqrt[a + b*x])/(128*b^3) - (a^3*x^(3/2)*Sqrt[a + b*x])/(64*b^2) + (a^2*x^(5/2)*Sqrt[a + b*x])/(80*b) + (3/40)*a*x^(7/2)*Sqrt[a + b*x] + (1/5)*x^(7/2)*(a + b*x)^(3/2) - (3*a^5*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a + b*x]])/(128*b^(7/2))}
{x^(5/2)*(a + b*x)^(5/2), x, 7, (5*a^5*Sqrt[x]*Sqrt[a + b*x])/(512*b^3) - (5*a^4*x^(3/2)*Sqrt[a + b*x])/(768*b^2) + (a^3*x^(5/2)*Sqrt[a + b*x])/(192*b) + (1/32)*a^2*x^(7/2)*Sqrt[a + b*x] + (1/12)*a*x^(7/2)*(a + b*x)^(3/2) + (1/6)*x^(7/2)*(a + b*x)^(5/2) - (5*a^6*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a + b*x]])/(512*b^(7/2))}
{x^(5/2)/Sqrt[a + b*x], x, 4, (5*a^2*Sqrt[x]*Sqrt[a + b*x])/(8*b^3) - (5*a*x^(3/2)*Sqrt[a + b*x])/(12*b^2) + (x^(5/2)*Sqrt[a + b*x])/(3*b) - (5*a^3*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a + b*x]])/(8*b^(7/2))}
{x^(5/2)/(a + b*x)^(3/2), x, 4, -((2*x^(5/2))/(b*Sqrt[a + b*x])) - (15*a*Sqrt[x]*Sqrt[a + b*x])/(4*b^3) + (5*x^(3/2)*Sqrt[a + b*x])/(2*b^2) + (15*a^2*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a + b*x]])/(4*b^(7/2))}
{x^(5/2)/(a + b*x)^(5/2), x, 4, -((2*x^(5/2))/(3*b*(a + b*x)^(3/2))) - (10*x^(3/2))/(3*b^2*Sqrt[a + b*x]) + (5*Sqrt[x]*Sqrt[a + b*x])/b^3 - (5*a*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a + b*x]])/b^(7/2)}

{Sqrt[a + b*x]/Sqrt[x], x, 2, Sqrt[x]*Sqrt[a + b*x] + (a*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a + b*x]])/Sqrt[b]}
{(a + b*x)^(3/2)/Sqrt[x], x, 3, (3/4)*a*Sqrt[x]*Sqrt[a + b*x] + (1/2)*Sqrt[x]*(a + b*x)^(3/2) + (3*a^2*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a + b*x]])/(4*Sqrt[b])}
{(a + b*x)^(5/2)/Sqrt[x], x, 4, (5/8)*a^2*Sqrt[x]*Sqrt[a + b*x] + (5/12)*a*Sqrt[x]*(a + b*x)^(3/2) + (1/3)*Sqrt[x]*(a + b*x)^(5/2) + (5*a^3*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a + b*x]])/(8*Sqrt[b])}
{1/(Sqrt[x]*Sqrt[a + b*x]), x, 1, (2*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a + b*x]])/Sqrt[b]}
{1/(Sqrt[x]*(a + b*x)^(3/2)), x, 1, (2*Sqrt[x])/(a*Sqrt[a + b*x])}
{1/(Sqrt[x]*(a + b*x)^(5/2)), x, 2, (2*Sqrt[x])/(3*a*(a + b*x)^(3/2)) + (4*Sqrt[x])/(3*a^2*Sqrt[a + b*x])}

{Sqrt[a + b*x]/x^(3/2), x, 2, (-2*Sqrt[a + b*x])/Sqrt[x] + 2*Sqrt[b]*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a + b*x]]}
{(a + b*x)^(3/2)/x^(3/2), x, 3, 3*b*Sqrt[x]*Sqrt[a + b*x] - (2*(a + b*x)^(3/2))/Sqrt[x] + 3*a*Sqrt[b]*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a + b*x]]}
{(a + b*x)^(5/2)/x^(3/2), x, 4, (15/4)*a*b*Sqrt[x]*Sqrt[a + b*x] + (5/2)*b*Sqrt[x]*(a + b*x)^(3/2) - (2*(a + b*x)^(5/2))/Sqrt[x] + (15/4)*a^2*Sqrt[b]*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a + b*x]]}
{1/(x^(3/2)*Sqrt[a + b*x]), x, 1, (-2*Sqrt[a + b*x])/(a*Sqrt[x])}
{1/(x^(3/2)*(a + b*x)^(3/2)), x, 2, 2/(a*Sqrt[x]*Sqrt[a + b*x]) - (4*Sqrt[a + b*x])/(a^2*Sqrt[x])}
{1/(x^(3/2)*(a + b*x)^(5/2)), x, 3, -(2/(a*Sqrt[x]*(a + b*x)^(3/2))) - (8*b*Sqrt[x])/(3*a^2*(a + b*x)^(3/2)) - (16*b*Sqrt[x])/(3*a^3*Sqrt[a + b*x])}

{Sqrt[a + b*x]/x^(5/2), x, 1, (-2*(a + b*x)^(3/2))/(3*a*x^(3/2))}
{(a + b*x)^(3/2)/x^(5/2), x, 3, -((2*b*Sqrt[a + b*x])/Sqrt[x]) - (2*(a + b*x)^(3/2))/(3*x^(3/2)) + 2*b^(3/2)*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a + b*x]]}
{(a + b*x)^(5/2)/x^(5/2), x, 4, 5*b^2*Sqrt[x]*Sqrt[a + b*x] - (10*b*(a + b*x)^(3/2))/(3*Sqrt[x]) - (2*(a + b*x)^(5/2))/(3*x^(3/2)) + 5*a*b^(3/2)*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[a + b*x]]}
{1/(x^(5/2)*Sqrt[a + b*x]), x, 2, -((2*Sqrt[a + b*x])/(3*a*x^(3/2))) + (4*b*Sqrt[a + b*x])/(3*a^2*Sqrt[x])}
{1/(x^(5/2)*(a + b*x)^(3/2)), x, 3, 2/(a*x^(3/2)*Sqrt[a + b*x]) - (8*Sqrt[a + b*x])/(3*a^2*x^(3/2)) + (16*b*Sqrt[a + b*x])/(3*a^3*Sqrt[x])}
{1/(x^(5/2)*(a + b*x)^(5/2)), x, 4, 2/(3*a*x^(3/2)*(a + b*x)^(3/2)) + 4/(a^2*x^(3/2)*Sqrt[a + b*x]) - (16*Sqrt[a + b*x])/(3*a^3*x^(3/2)) + (32*b*Sqrt[a + b*x])/(3*a^4*Sqrt[x])}


(* Integrands of the form x^m*(2-b*x)^n where m and n are half-integers *)
{Sqrt[x]*Sqrt[2 - b*x], x, 3, -((Sqrt[x]*Sqrt[2 - b*x])/(2*b)) + (1/2)*x^(3/2)*Sqrt[2 - b*x] + ArcSin[(Sqrt[b]*Sqrt[x])/Sqrt[2]]/b^(3/2)}
{Sqrt[x]*(2 - b*x)^(3/2), x, 4, (Sqrt[x]*Sqrt[2 - b*x])/(2*b) + (Sqrt[x]*(2 - b*x)^(3/2))/(6*b) - (Sqrt[x]*(2 - b*x)^(5/2))/(3*b) + ArcSin[(Sqrt[b]*Sqrt[x])/Sqrt[2]]/b^(3/2)}
{Sqrt[x]*(2 - b*x)^(5/2), x, 5, (5*Sqrt[x]*Sqrt[2 - b*x])/(8*b) + (5*Sqrt[x]*(2 - b*x)^(3/2))/(24*b) + (Sqrt[x]*(2 - b*x)^(5/2))/(12*b) - (Sqrt[x]*(2 - b*x)^(7/2))/(4*b) + (5*ArcSin[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/(4*b^(3/2))}
{Sqrt[x]/Sqrt[1 - x], x, 2, (-Sqrt[1 - x])*Sqrt[x] + ArcSin[Sqrt[x]]}
{Sqrt[x]/Sqrt[2 - b*x], x, 2, -((Sqrt[x]*Sqrt[2 - b*x])/b) + (2*ArcSin[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/b^(3/2)}
{Sqrt[x]/(2 - b*x)^(3/2), x, 2, (2*Sqrt[x])/(b*Sqrt[2 - b*x]) - (2*ArcSin[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/b^(3/2)}
{Sqrt[x]/(2 - b*x)^(5/2), x, 1, x^(3/2)/(3*(2 - b*x)^(3/2))}

{x^(3/2)*Sqrt[2 - b*x], x, 4, -((Sqrt[x]*Sqrt[2 - b*x])/(2*b^2)) - (x^(3/2)*Sqrt[2 - b*x])/(6*b) + (1/3)*x^(5/2)*Sqrt[2 - b*x] + ArcSin[(Sqrt[b]*Sqrt[x])/Sqrt[2]]/b^(5/2)}
{x^(3/2)*(2 - b*x)^(3/2), x, 5, -((3*Sqrt[x]*Sqrt[2 - b*x])/(8*b^2)) - (x^(3/2)*Sqrt[2 - b*x])/(8*b) + (1/4)*x^(5/2)*Sqrt[2 - b*x] + (1/4)*x^(5/2)*(2 - b*x)^(3/2) + (3*ArcSin[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/(4*b^(5/2))}
{x^(3/2)*(2 - b*x)^(5/2), x, 6, (3*Sqrt[x]*Sqrt[2 - b*x])/(8*b^2) + (Sqrt[x]*(2 - b*x)^(3/2))/(8*b^2) + (Sqrt[x]*(2 - b*x)^(5/2))/(20*b^2) - (3*Sqrt[x]*(2 - b*x)^(7/2))/(20*b^2) - (x^(3/2)*(2 - b*x)^(7/2))/(5*b) + (3*ArcSin[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/(4*b^(5/2))}
{x^(3/2)/Sqrt[2 - b*x], x, 3, -((3*Sqrt[x]*Sqrt[2 - b*x])/(2*b^2)) - (x^(3/2)*Sqrt[2 - b*x])/(2*b) + (3*ArcSin[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/b^(5/2)}
{x^(3/2)/(2 - b*x)^(3/2), x, 3, (2*x^(3/2))/(b*Sqrt[2 - b*x]) + (3*Sqrt[x]*Sqrt[2 - b*x])/b^2 - (6*ArcSin[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/b^(5/2)}
{x^(3/2)/(2 - b*x)^(5/2), x, 3, (2*x^(3/2))/(3*b*(2 - b*x)^(3/2)) - (2*Sqrt[x])/(b^2*Sqrt[2 - b*x]) + (2*ArcSin[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/b^(5/2)}

{x^(5/2)*Sqrt[2 - b*x], x, 5, -((5*Sqrt[x]*Sqrt[2 - b*x])/(8*b^3)) - (5*x^(3/2)*Sqrt[2 - b*x])/(24*b^2) - (x^(5/2)*Sqrt[2 - b*x])/(12*b) + (1/4)*x^(7/2)*Sqrt[2 - b*x] + (5*ArcSin[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/(4*b^(7/2))}
{x^(5/2)*(2 - b*x)^(3/2), x, 6, -((3*Sqrt[x]*Sqrt[2 - b*x])/(8*b^3)) - (x^(3/2)*Sqrt[2 - b*x])/(8*b^2) - (x^(5/2)*Sqrt[2 - b*x])/(20*b) + (3/20)*x^(7/2)*Sqrt[2 - b*x] + (1/5)*x^(7/2)*(2 - b*x)^(3/2) + (3*ArcSin[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/(4*b^(7/2))}
{x^(5/2)*(2 - b*x)^(5/2), x, 7, -((5*Sqrt[x]*Sqrt[2 - b*x])/(16*b^3)) - (5*x^(3/2)*Sqrt[2 - b*x])/(48*b^2) - (x^(5/2)*Sqrt[2 - b*x])/(24*b) + (1/8)*x^(7/2)*Sqrt[2 - b*x] + (1/6)*x^(7/2)*(2 - b*x)^(3/2) + (1/6)*x^(7/2)*(2 - b*x)^(5/2) + (5*ArcSin[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/(8*b^(7/2))}
{x^(5/2)/Sqrt[2 - b*x], x, 4, -((5*Sqrt[x]*Sqrt[2 - b*x])/(2*b^3)) - (5*x^(3/2)*Sqrt[2 - b*x])/(6*b^2) - (x^(5/2)*Sqrt[2 - b*x])/(3*b) + (5*ArcSin[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/b^(7/2)}
{x^(5/2)/(2 - b*x)^(3/2), x, 4, (2*x^(5/2))/(b*Sqrt[2 - b*x]) + (15*Sqrt[x]*Sqrt[2 - b*x])/(2*b^3) + (5*x^(3/2)*Sqrt[2 - b*x])/(2*b^2) - (15*ArcSin[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/b^(7/2)}
{x^(5/2)/(2 - b*x)^(5/2), x, 4, (2*x^(5/2))/(3*b*(2 - b*x)^(3/2)) - (10*x^(3/2))/(3*b^2*Sqrt[2 - b*x]) - (5*Sqrt[x]*Sqrt[2 - b*x])/b^3 + (10*ArcSin[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/b^(7/2)}

{Sqrt[2 - b*x]/Sqrt[x], x, 2, Sqrt[x]*Sqrt[2 - b*x] + (2*ArcSin[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/Sqrt[b]}
{(2 - b*x)^(3/2)/Sqrt[x], x, 3, (3/2)*Sqrt[x]*Sqrt[2 - b*x] + (1/2)*Sqrt[x]*(2 - b*x)^(3/2) + (3*ArcSin[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/Sqrt[b]}
{(2 - b*x)^(5/2)/Sqrt[x], x, 4, (5/2)*Sqrt[x]*Sqrt[2 - b*x] + (5/6)*Sqrt[x]*(2 - b*x)^(3/2) + (1/3)*Sqrt[x]*(2 - b*x)^(5/2) + (5*ArcSin[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/Sqrt[b]}
{1/(Sqrt[x]*Sqrt[2 - b*x]), x, 1, (2*ArcSin[(Sqrt[b]*Sqrt[x])/Sqrt[2]])/Sqrt[b]}
{1/(Sqrt[x]*(2 - b*x)^(3/2)), x, 1, Sqrt[x]/Sqrt[2 - b*x]}
{1/(Sqrt[x]*(2 - b*x)^(5/2)), x, 2, Sqrt[x]/(3*(2 - b*x)^(3/2)) + Sqrt[x]/(3*Sqrt[2 - b*x])}

{Sqrt[2 - b*x]/x^(3/2), x, 2, (-2*Sqrt[2 - b*x])/Sqrt[x] - 2*Sqrt[b]*ArcSin[(Sqrt[b]*Sqrt[x])/Sqrt[2]]}
{(2 - b*x)^(3/2)/x^(3/2), x, 3, -3*b*Sqrt[x]*Sqrt[2 - b*x] - (2*(2 - b*x)^(3/2))/Sqrt[x] - 6*Sqrt[b]*ArcSin[(Sqrt[b]*Sqrt[x])/Sqrt[2]]}
{(2 - b*x)^(5/2)/x^(3/2), x, 4, (-(15/2))*b*Sqrt[x]*Sqrt[2 - b*x] - (5/2)*b*Sqrt[x]*(2 - b*x)^(3/2) - (2*(2 - b*x)^(5/2))/Sqrt[x] - 15*Sqrt[b]*ArcSin[(Sqrt[b]*Sqrt[x])/Sqrt[2]]}
{1/(x^(3/2)*Sqrt[2 - b*x]), x, 1, -(Sqrt[2 - b*x]/Sqrt[x])}
{1/(x^(3/2)*(2 - b*x)^(3/2)), x, 2, 1/(Sqrt[x]*Sqrt[2 - b*x]) - Sqrt[2 - b*x]/Sqrt[x]}
{1/(x^(3/2)*(2 - b*x)^(5/2)), x, 3, -(1/(Sqrt[x]*(2 - b*x)^(3/2))) + (2*b*Sqrt[x])/(3*(2 - b*x)^(3/2)) + (2*b*Sqrt[x])/(3*Sqrt[2 - b*x])}

{Sqrt[2 - b*x]/x^(5/2), x, 1, -(2 - b*x)^(3/2)/(3*x^(3/2))}
{(2 - b*x)^(3/2)/x^(5/2), x, 3, (2*b*Sqrt[2 - b*x])/Sqrt[x] - (2*(2 - b*x)^(3/2))/(3*x^(3/2)) + 2*b^(3/2)*ArcSin[(Sqrt[b]*Sqrt[x])/Sqrt[2]]}
{(2 - b*x)^(5/2)/x^(5/2), x, 4, 5*b^2*Sqrt[x]*Sqrt[2 - b*x] + (10*b*(2 - b*x)^(3/2))/(3*Sqrt[x]) - (2*(2 - b*x)^(5/2))/(3*x^(3/2)) + 10*b^(3/2)*ArcSin[(Sqrt[b]*Sqrt[x])/Sqrt[2]]}
{1/(x^(5/2)*Sqrt[2 - b*x]), x, 2, -(Sqrt[2 - b*x]/(3*x^(3/2))) - (b*Sqrt[2 - b*x])/(3*Sqrt[x])}
{1/(x^(5/2)*(2 - b*x)^(3/2)), x, 3, 1/(x^(3/2)*Sqrt[2 - b*x]) - (2*Sqrt[2 - b*x])/(3*x^(3/2)) - (2*b*Sqrt[2 - b*x])/(3*Sqrt[x])}
{1/(x^(5/2)*(2 - b*x)^(5/2)), x, 4, 1/(3*x^(3/2)*(2 - b*x)^(3/2)) + 1/(x^(3/2)*Sqrt[2 - b*x]) - (2*Sqrt[2 - b*x])/(3*x^(3/2)) - (2*b*Sqrt[2 - b*x])/(3*Sqrt[x])}


(* Integrands of the form x^m*(a-b*x)^n where m and n are half-integers *)
{Sqrt[x]*Sqrt[a - b*x], x, 3, -((a*Sqrt[x]*Sqrt[a - b*x])/(4*b)) + (1/2)*x^(3/2)*Sqrt[a - b*x] + (a^2*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a - b*x]])/(4*b^(3/2))}
{Sqrt[x]*(a - b*x)^(3/2), x, 4, (a^2*Sqrt[x]*Sqrt[a - b*x])/(8*b) + (a*Sqrt[x]*(a - b*x)^(3/2))/(12*b) - (Sqrt[x]*(a - b*x)^(5/2))/(3*b) + (a^3*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a - b*x]])/(8*b^(3/2))}
{Sqrt[x]*(a - b*x)^(5/2), x, 5, (5*a^3*Sqrt[x]*Sqrt[a - b*x])/(64*b) + (5*a^2*Sqrt[x]*(a - b*x)^(3/2))/(96*b) + (a*Sqrt[x]*(a - b*x)^(5/2))/(24*b) - (Sqrt[x]*(a - b*x)^(7/2))/(4*b) + (5*a^4*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a - b*x]])/(64*b^(3/2))}
{Sqrt[x]/Sqrt[a - b*x], x, 2, -((Sqrt[x]*Sqrt[a - b*x])/b) + (a*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a - b*x]])/b^(3/2)}
{Sqrt[x]/(a - b*x)^(3/2), x, 2, (2*Sqrt[x])/(b*Sqrt[a - b*x]) - (2*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a - b*x]])/b^(3/2)}
{Sqrt[x]/(a - b*x)^(5/2), x, 1, (2*x^(3/2))/(3*a*(a - b*x)^(3/2))}

{x^(3/2)*Sqrt[a - b*x], x, 4, -((a^2*Sqrt[x]*Sqrt[a - b*x])/(8*b^2)) - (a*x^(3/2)*Sqrt[a - b*x])/(12*b) + (1/3)*x^(5/2)*Sqrt[a - b*x] + (a^3*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a - b*x]])/(8*b^(5/2))}
{x^(3/2)*(a - b*x)^(3/2), x, 5, -((3*a^3*Sqrt[x]*Sqrt[a - b*x])/(64*b^2)) - (a^2*x^(3/2)*Sqrt[a - b*x])/(32*b) + (1/8)*a*x^(5/2)*Sqrt[a - b*x] + (1/4)*x^(5/2)*(a - b*x)^(3/2) + (3*a^4*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a - b*x]])/(64*b^(5/2))}
{x^(3/2)*(a - b*x)^(5/2), x, 6, (3*a^4*Sqrt[x]*Sqrt[a - b*x])/(128*b^2) + (a^3*Sqrt[x]*(a - b*x)^(3/2))/(64*b^2) + (a^2*Sqrt[x]*(a - b*x)^(5/2))/(80*b^2) - (3*a*Sqrt[x]*(a - b*x)^(7/2))/(40*b^2) - (x^(3/2)*(a - b*x)^(7/2))/(5*b) + (3*a^5*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a - b*x]])/(128*b^(5/2))}
{x^(3/2)/Sqrt[a - b*x], x, 3, -((3*a*Sqrt[x]*Sqrt[a - b*x])/(4*b^2)) - (x^(3/2)*Sqrt[a - b*x])/(2*b) + (3*a^2*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a - b*x]])/(4*b^(5/2))}
{x^(3/2)/(a - b*x)^(3/2), x, 3, (2*x^(3/2))/(b*Sqrt[a - b*x]) + (3*Sqrt[x]*Sqrt[a - b*x])/b^2 - (3*a*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a - b*x]])/b^(5/2)}
{x^(3/2)/(a - b*x)^(5/2), x, 3, (2*x^(3/2))/(3*b*(a - b*x)^(3/2)) - (2*Sqrt[x])/(b^2*Sqrt[a - b*x]) + (2*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a - b*x]])/b^(5/2)}

{x^(5/2)*Sqrt[a - b*x], x, 5, -((5*a^3*Sqrt[x]*Sqrt[a - b*x])/(64*b^3)) - (5*a^2*x^(3/2)*Sqrt[a - b*x])/(96*b^2) - (a*x^(5/2)*Sqrt[a - b*x])/(24*b) + (1/4)*x^(7/2)*Sqrt[a - b*x] + (5*a^4*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a - b*x]])/(64*b^(7/2))}
{x^(5/2)*(a - b*x)^(3/2), x, 6, -((3*a^4*Sqrt[x]*Sqrt[a - b*x])/(128*b^3)) - (a^3*x^(3/2)*Sqrt[a - b*x])/(64*b^2) - (a^2*x^(5/2)*Sqrt[a - b*x])/(80*b) + (3/40)*a*x^(7/2)*Sqrt[a - b*x] + (1/5)*x^(7/2)*(a - b*x)^(3/2) + (3*a^5*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a - b*x]])/(128*b^(7/2))}
{x^(5/2)*(a - b*x)^(5/2), x, 7, -((5*a^5*Sqrt[x]*Sqrt[a - b*x])/(512*b^3)) - (5*a^4*x^(3/2)*Sqrt[a - b*x])/(768*b^2) - (a^3*x^(5/2)*Sqrt[a - b*x])/(192*b) + (1/32)*a^2*x^(7/2)*Sqrt[a - b*x] + (1/12)*a*x^(7/2)*(a - b*x)^(3/2) + (1/6)*x^(7/2)*(a - b*x)^(5/2) + (5*a^6*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a - b*x]])/(512*b^(7/2))}
{x^(5/2)/Sqrt[a - b*x], x, 4, -((5*a^2*Sqrt[x]*Sqrt[a - b*x])/(8*b^3)) - (5*a*x^(3/2)*Sqrt[a - b*x])/(12*b^2) - (x^(5/2)*Sqrt[a - b*x])/(3*b) + (5*a^3*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a - b*x]])/(8*b^(7/2))}
{x^(5/2)/(a - b*x)^(3/2), x, 4, (2*x^(5/2))/(b*Sqrt[a - b*x]) + (15*a*Sqrt[x]*Sqrt[a - b*x])/(4*b^3) + (5*x^(3/2)*Sqrt[a - b*x])/(2*b^2) - (15*a^2*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a - b*x]])/(4*b^(7/2))}
{x^(5/2)/(a - b*x)^(5/2), x, 4, (2*x^(5/2))/(3*b*(a - b*x)^(3/2)) - (10*x^(3/2))/(3*b^2*Sqrt[a - b*x]) - (5*Sqrt[x]*Sqrt[a - b*x])/b^3 + (5*a*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a - b*x]])/b^(7/2)}

{Sqrt[a - b*x]/Sqrt[x], x, 2, Sqrt[x]*Sqrt[a - b*x] + (a*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a - b*x]])/Sqrt[b]}
{(a - b*x)^(3/2)/Sqrt[x], x, 3, (3/4)*a*Sqrt[x]*Sqrt[a - b*x] + (1/2)*Sqrt[x]*(a - b*x)^(3/2) + (3*a^2*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a - b*x]])/(4*Sqrt[b])}
{(a - b*x)^(5/2)/Sqrt[x], x, 4, (5/8)*a^2*Sqrt[x]*Sqrt[a - b*x] + (5/12)*a*Sqrt[x]*(a - b*x)^(3/2) + (1/3)*Sqrt[x]*(a - b*x)^(5/2) + (5*a^3*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a - b*x]])/(8*Sqrt[b])}
{1/(Sqrt[x]*Sqrt[a - b*x]), x, 1, (2*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a - b*x]])/Sqrt[b]}
{1/(Sqrt[x]*Sqrt[1 - b*x]), x, 1, (2*ArcSin[Sqrt[b]*Sqrt[x]])/Sqrt[b]}
{1/(Sqrt[x]*Sqrt[1 - x]), x, 1, 2*ArcSin[Sqrt[x]]}
{1/(Sqrt[x]*(a - b*x)^(3/2)), x, 1, (2*Sqrt[x])/(a*Sqrt[a - b*x])}
{1/(Sqrt[x]*(a - b*x)^(5/2)), x, 2, (2*Sqrt[x])/(3*a*(a - b*x)^(3/2)) + (4*Sqrt[x])/(3*a^2*Sqrt[a - b*x])}

{Sqrt[a - b*x]/x^(3/2), x, 2, (-2*Sqrt[a - b*x])/Sqrt[x] - 2*Sqrt[b]*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a - b*x]]}
{(a - b*x)^(3/2)/x^(3/2), x, 3, -3*b*Sqrt[x]*Sqrt[a - b*x] - (2*(a - b*x)^(3/2))/Sqrt[x] - 3*a*Sqrt[b]*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a - b*x]]}
{(a - b*x)^(5/2)/x^(3/2), x, 4, (-(15/4))*a*b*Sqrt[x]*Sqrt[a - b*x] - (5/2)*b*Sqrt[x]*(a - b*x)^(3/2) - (2*(a - b*x)^(5/2))/Sqrt[x] - (15/4)*a^2*Sqrt[b]*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a - b*x]]}
{1/(x^(3/2)*Sqrt[a - b*x]), x, 1, (-2*Sqrt[a - b*x])/(a*Sqrt[x])}
{1/(x^(3/2)*(a - b*x)^(3/2)), x, 2, 2/(a*Sqrt[x]*Sqrt[a - b*x]) - (4*Sqrt[a - b*x])/(a^2*Sqrt[x])}
{1/(x^(3/2)*(a - b*x)^(5/2)), x, 3, -(2/(a*Sqrt[x]*(a - b*x)^(3/2))) + (8*b*Sqrt[x])/(3*a^2*(a - b*x)^(3/2)) + (16*b*Sqrt[x])/(3*a^3*Sqrt[a - b*x])}

{Sqrt[a - b*x]/x^(5/2), x, 1, (-2*(a - b*x)^(3/2))/(3*a*x^(3/2))}
{(a - b*x)^(3/2)/x^(5/2), x, 3, (2*b*Sqrt[a - b*x])/Sqrt[x] - (2*(a - b*x)^(3/2))/(3*x^(3/2)) + 2*b^(3/2)*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a - b*x]]}
{(a - b*x)^(5/2)/x^(5/2), x, 4, 5*b^2*Sqrt[x]*Sqrt[a - b*x] + (10*b*(a - b*x)^(3/2))/(3*Sqrt[x]) - (2*(a - b*x)^(5/2))/(3*x^(3/2)) + 5*a*b^(3/2)*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[a - b*x]]}
{1/(x^(5/2)*Sqrt[a - b*x]), x, 2, -((2*Sqrt[a - b*x])/(3*a*x^(3/2))) - (4*b*Sqrt[a - b*x])/(3*a^2*Sqrt[x])}
{1/(x^(5/2)*(a - b*x)^(3/2)), x, 3, 2/(a*x^(3/2)*Sqrt[a - b*x]) - (8*Sqrt[a - b*x])/(3*a^2*x^(3/2)) - (16*b*Sqrt[a - b*x])/(3*a^3*Sqrt[x])}
{1/(x^(5/2)*(a - b*x)^(5/2)), x, 4, 2/(3*a*x^(3/2)*(a - b*x)^(3/2)) + 4/(a^2*x^(3/2)*Sqrt[a - b*x]) - (16*Sqrt[a - b*x])/(3*a^3*x^(3/2)) - (32*b*Sqrt[a - b*x])/(3*a^4*Sqrt[x])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x)^m (c+d x)^(n/2)*)


(* Integrands of the form (a+b*x)^5*(a*c+b*c*x)^n where n is a half-integer *)
{(a + b*x)^5*(a*c + b*c*x)^(3/2), x, 2, (2*(a*c + b*c*x)^(15/2))/(15*b*c^6)}
{(a + b*x)^5*(a*c + b*c*x)^(1/2), x, 2, (2*(a*c + b*c*x)^(13/2))/(13*b*c^6)}
{(a + b*x)^5/(a*c + b*c*x)^(1/2), x, 2, (2*(a*c + b*c*x)^(11/2))/(11*b*c^6)}
{(a + b*x)^5/(a*c + b*c*x)^(3/2), x, 2, (2*(a*c + b*c*x)^(9/2))/(9*b*c^6)}
{(a + b*x)^5/(a*c + b*c*x)^(5/2), x, 2, (2*(a*c + b*c*x)^(7/2))/(7*b*c^6)}
{(a + b*x)^5/(a*c + b*c*x)^(7/2), x, 2, (2*(a*c + b*c*x)^(5/2))/(5*b*c^6)}
{(a + b*x)^5/(a*c + b*c*x)^(9/2), x, 2, (2*(a*c + b*c*x)^(3/2))/(3*b*c^6)}
{(a + b*x)^5/(a*c + b*c*x)^(11/2), x, 2, (2*Sqrt[a*c + b*c*x])/(b*c^6)}
{(a + b*x)^5/(a*c + b*c*x)^(13/2), x, 2, -(2/(b*c^6*Sqrt[a*c + b*c*x]))}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x)^(m/2) (c+d x)^(n/2)*)


(* Integrands of the form (1-x)^m*(1+x)^m == (1-x^2)^m where m is an integer *)
{(1 - x)^(3/2)*(1 + x)^(3/2), x, 4, (3/8)*x*Sqrt[1 - x^2] + (1/4)*x*(1 - x^2)^(3/2) + (3*ArcSin[x])/8}
{Sqrt[1 - x]*Sqrt[1 + x], x, 3, (1/2)*x*Sqrt[1 - x]*Sqrt[1 + x] + ArcSin[x]/2, (1/2)*x*Sqrt[1 - x^2] + ArcSin[x]/2}
{1/(Sqrt[1 - x]*Sqrt[1 + x]), x, 1, ArcSin[x]}
{1/((1 - x)^(3/2)*(1 + x)^(3/2)), x, 2, x/(Sqrt[1 - x]*Sqrt[1 + x]), x/Sqrt[1 - x^2]}


(* Integrands of the form (3-x)^m*(-2+x)^m == (-6+5*x-x^2)^m where m is a half-integer *)
{(3 - x)^(3/2)*(-2 + x)^(3/2), x, 4, (-(3/64))*(5 - 2*x)*Sqrt[-6 + 5*x - x^2] - (1/8)*(5 - 2*x)*(-6 + 5*x - x^2)^(3/2) - (3/128)*ArcSin[5 - 2*x]}
{Sqrt[3 - x]*Sqrt[-2 + x], x, 3, (-(1/4))*(5 - 2*x)*Sqrt[-6 + 5*x - x^2] - (1/8)*ArcSin[5 - 2*x]}
{1/(Sqrt[3 - x]*Sqrt[-2 + x]), x, 1, -ArcSin[5 - 2*x]}
{1/((3 - x)^(3/2)*(-2 + x)^(3/2)), x, 2, -((2*(5 - 2*x))/Sqrt[-6 + 5*x - x^2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a+b x)^(n/2) (c+d x)^(p/2)*)


(* Note that the derivative of (a+b*x)^n/(-a-b*x)^n is zero. *)
{x^2*Sqrt[a + b*x]/Sqrt[-a - b*x], x, 2, (x^3*Sqrt[a + b*x])/(3*Sqrt[-a - b*x])}
{x*Sqrt[a + b*x]/Sqrt[-a - b*x], x, 2, (x^2*Sqrt[a + b*x])/(2*Sqrt[-a - b*x])}
{Sqrt[a + b*x]/Sqrt[-a - b*x], x, 2, (x*Sqrt[a + b*x])/Sqrt[-a - b*x]}
{Sqrt[a + b*x]/(x*Sqrt[-a - b*x]), x, 2, (Sqrt[a + b*x]*Log[x])/Sqrt[-a - b*x]}
{Sqrt[a + b*x]/(x^2*Sqrt[-a - b*x]), x, 2, -(Sqrt[a + b*x]/(x*Sqrt[-a - b*x]))}
{Sqrt[a + b*x]/(x^3*Sqrt[-a - b*x]), x, 2, -(Sqrt[a + b*x]/(2*x^2*Sqrt[-a - b*x]))}
{Sqrt[a + b*x]/(x^m*Sqrt[-a - b*x]), x, 2, (x^(1 - m)*Sqrt[a + b*x])/((1 - m)*Sqrt[-a - b*x])}

{x^2*((a + b*x)^n/(-a - b*x)^n), x, 2, ((1/3)*x^3*(a + b*x)^n)/(-a - b*x)^n}
{x*((a + b*x)^n/(-a - b*x)^n), x, 2, ((1/2)*x^2*(a + b*x)^n)/(-a - b*x)^n}
{((a + b*x)^n/(-a - b*x)^n), x, 2, (x*(a + b*x)^n)/(-a - b*x)^n}
{((a + b*x)^n/(x*(-a - b*x)^n)), x, 2, ((a + b*x)^n*Log[x])/(-a - b*x)^n}
{((a + b*x)^n/(x^2*(-a - b*x)^n)), x, 2, -((a + b*x)^n/((-a - b*x)^n*x))}
{((a + b*x)^n/(x^3*(-a - b*x)^n)), x, 2, -((a + b*x)^n/((-a - b*x)^n*(2*x^2)))}
{((a + b*x)^n/(x^m*(-a - b*x)^n)), x, 2, (x^(1 - m)*(a + b*x)^n)/((-a - b*x)^n*(1 - m))}


(* Integrands of the form x^m/(Sqrt[a+b*x]*(c+d*x)^n) where m is an integer and n>0 is a half-integer *)
{x^3/(Sqrt[a + b*x]*Sqrt[c + d*x]), x, 7, -((2*a*c*Sqrt[a + b*x]*Sqrt[c + d*x])/(3*b^2*d^2)) + (5*(b*c + a*d)^2*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*b^3*d^3) - (5*(b*c + a*d)*x*Sqrt[a + b*x]*Sqrt[c + d*x])/(12*b^2*d^2) + (x^2*Sqrt[a + b*x]*Sqrt[c + d*x])/(3*b*d) + (3*a*c*(b*c + a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(2*b^(5/2)*d^(5/2)) - (5*(b*c + a*d)^3*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(8*b^(7/2)*d^(7/2))}
{x^2/(Sqrt[a + b*x]*Sqrt[c + d*x]), x, 4, -((3*(b*c + a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*b^2*d^2)) + (x*Sqrt[a + b*x]*Sqrt[c + d*x])/(2*b*d) - (a*c*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(b^(3/2)*d^(3/2)) + (3*(b*c + a*d)^2*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*b^(5/2)*d^(5/2))}
{x/(Sqrt[a + b*x]*Sqrt[c + d*x]), x, 2, (Sqrt[a + b*x]*Sqrt[c + d*x])/(b*d) - ((b*c + a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(b^(3/2)*d^(3/2))}
{1/(Sqrt[a + b*x]*Sqrt[c + d*x]), x, 1, (2*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(Sqrt[b]*Sqrt[d])}
{1/(x*Sqrt[a + b*x]*Sqrt[c + d*x]), x, 1, -((2*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(Sqrt[a]*Sqrt[c]))}
{1/(x^2*Sqrt[a + b*x]*Sqrt[c + d*x]), x, 2, -((Sqrt[a + b*x]*Sqrt[c + d*x])/(a*c*x)) + ((b*c + a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(a^(3/2)*c^(3/2))}
{1/(x^3*Sqrt[a + b*x]*Sqrt[c + d*x]), x, 4, -((Sqrt[a + b*x]*Sqrt[c + d*x])/(2*a*c*x^2)) + (3*(b*c + a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*a^2*c^2*x) + (b*d*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(a^(3/2)*c^(3/2)) - (3*(b*c + a*d)^2*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*a^(5/2)*c^(5/2))}

{x^3/(Sqrt[a + b*x]*(c + d*x)^(3/2)), x, 9, -((2*c^3*Sqrt[a + b*x])/(d^3*(b*c - a*d)*Sqrt[c + d*x])) - (7*c*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*b*d^3) - (3*a*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*b^2*d^2) + (x*Sqrt[a + b*x]*Sqrt[c + d*x])/(2*b*d^2) + (3*c^2*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(Sqrt[b]*d^(7/2)) + (3*(b*c + a*d)^2*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*b^(5/2)*d^(7/2))}
{x^2/(Sqrt[a + b*x]*(c + d*x)^(3/2)), x, 5, (2*c^2*Sqrt[a + b*x])/(d^2*(b*c - a*d)*Sqrt[c + d*x]) + (Sqrt[a + b*x]*Sqrt[c + d*x])/(b*d^2) - (3*c*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(Sqrt[b]*d^(5/2)) - (a*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(b^(3/2)*d^(3/2))}
{x/(Sqrt[a + b*x]*(c + d*x)^(3/2)), x, 3, -((2*c*Sqrt[a + b*x])/(d*(b*c - a*d)*Sqrt[c + d*x])) + (2*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(Sqrt[b]*d^(3/2))}
{1/(Sqrt[a + b*x]*(c + d*x)^(3/2)), x, 1, (2*Sqrt[a + b*x])/((b*c - a*d)*Sqrt[c + d*x])}
{1/(x*Sqrt[a + b*x]*(c + d*x)^(3/2)), x, 3, -((2*d*Sqrt[a + b*x])/(c*(b*c - a*d)*Sqrt[c + d*x])) - (2*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(Sqrt[a]*c^(3/2))}
{1/(x^2*Sqrt[a + b*x]*(c + d*x)^(3/2)), x, 5, (2*d^2*Sqrt[a + b*x])/(c^2*(b*c - a*d)*Sqrt[c + d*x]) - (Sqrt[a + b*x]*Sqrt[c + d*x])/(a*c^2*x) + (b*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(a^(3/2)*c^(3/2)) + (3*d*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(Sqrt[a]*c^(5/2))}
{1/(x^3*Sqrt[a + b*x]*(c + d*x)^(3/2)), x, 9, -((2*d^3*Sqrt[a + b*x])/(c^3*(b*c - a*d)*Sqrt[c + d*x])) - (Sqrt[a + b*x]*Sqrt[c + d*x])/(2*a*c^2*x^2) + (3*b*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*a^2*c^2*x) + (7*d*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*a*c^3*x) - (3*d^2*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(Sqrt[a]*c^(7/2)) - (3*(b*c + a*d)^2*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*a^(5/2)*c^(7/2))}

{x^5/(Sqrt[a + b*x]*(c + d*x)^(5/2)), x, 22, -((2*a^5*Sqrt[a + b*x])/(3*b^5*(b*c - a*d)*(c + d*x)^(3/2))) + (20*a^3*(a + b*x)^(3/2))/(3*b^5*d*(c + d*x)^(3/2)) + (10*a^4*(a + b*x)^(3/2))/(3*b^5*(b*c - a*d)*(c + d*x)^(3/2)) - (20*a^2*(a + b*x)^(5/2))/(3*b^5*d*(c + d*x)^(3/2)) + (10*a*(a + b*x)^(7/2))/(3*b^5*d*(c + d*x)^(3/2)) - (2*(a + b*x)^(9/2))/(3*b^5*d*(c + d*x)^(3/2)) + (20*a^3*Sqrt[a + b*x])/(b^4*d^2*Sqrt[c + d*x]) - (4*a^5*Sqrt[a + b*x])/(3*b^4*(b*c - a*d)^2*Sqrt[c + d*x]) - (100*a^2*(a + b*x)^(3/2))/(3*b^4*d^2*Sqrt[c + d*x]) + (70*a*(a + b*x)^(5/2))/(3*b^4*d^2*Sqrt[c + d*x]) - (6*(a + b*x)^(7/2))/(b^4*d^2*Sqrt[c + d*x]) + (175*a*c*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*b^2*d^4) + (25*a^2*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*b^3*d^3) + (105*(b*c - a*d)^2*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*b^3*d^5) - (35*c*(a + b*x)^(3/2)*Sqrt[c + d*x])/(4*b^2*d^4) - (245*a*(a + b*x)^(3/2)*Sqrt[c + d*x])/(12*b^3*d^3) + (7*(a + b*x)^(5/2)*Sqrt[c + d*x])/(b^3*d^3) - (50*a^2*c*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(b^(5/2)*d^(7/2)) + (30*a^3*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(b^(7/2)*d^(5/2)) - (175*a*(b*c - a*d)^2*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*b^(7/2)*d^(9/2)) - (105*(b*c - a*d)^3*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(8*b^(7/2)*d^(11/2))}
{x^4/(Sqrt[a + b*x]*(c + d*x)^(5/2)), x, 16, (2*a^4*Sqrt[a + b*x])/(3*b^4*(b*c - a*d)*(c + d*x)^(3/2)) - (4*a^2*(a + b*x)^(3/2))/(b^4*d*(c + d*x)^(3/2)) - (8*a^3*(a + b*x)^(3/2))/(3*b^4*(b*c - a*d)*(c + d*x)^(3/2)) + (8*a*(a + b*x)^(5/2))/(3*b^4*d*(c + d*x)^(3/2)) - (2*(a + b*x)^(7/2))/(3*b^4*d*(c + d*x)^(3/2)) - (12*a^2*Sqrt[a + b*x])/(b^3*d^2*Sqrt[c + d*x]) + (4*a^4*Sqrt[a + b*x])/(3*b^3*(b*c - a*d)^2*Sqrt[c + d*x]) + (40*a*(a + b*x)^(3/2))/(3*b^3*d^2*Sqrt[c + d*x]) - (14*(a + b*x)^(5/2))/(3*b^3*d^2*Sqrt[c + d*x]) - (35*c*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*b*d^4) - (45*a*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*b^2*d^3) + (35*(a + b*x)^(3/2)*Sqrt[c + d*x])/(6*b^2*d^3) + (20*a*c*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(b^(3/2)*d^(7/2)) - (8*a^2*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(b^(5/2)*d^(5/2)) + (35*(b*c - a*d)^2*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*b^(5/2)*d^(9/2))}
{x^3/(Sqrt[a + b*x]*(c + d*x)^(5/2)), x, 7, -((2*c^3*Sqrt[a + b*x])/(3*d^3*(b*c - a*d)*(c + d*x)^(3/2))) - (4*b*c^3*Sqrt[a + b*x])/(3*d^3*(b*c - a*d)^2*Sqrt[c + d*x]) + (6*c^2*Sqrt[a + b*x])/(d^3*(b*c - a*d)*Sqrt[c + d*x]) + (Sqrt[a + b*x]*Sqrt[c + d*x])/(b*d^3) - (5*c*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(Sqrt[b]*d^(7/2)) - (a*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(b^(3/2)*d^(5/2))}
{x^2/(Sqrt[a + b*x]*(c + d*x)^(5/2)), x, 5, (2*c^2*Sqrt[a + b*x])/(3*d^2*(b*c - a*d)*(c + d*x)^(3/2)) + (4*b*c^2*Sqrt[a + b*x])/(3*d^2*(b*c - a*d)^2*Sqrt[c + d*x]) - (4*c*Sqrt[a + b*x])/(d^2*(b*c - a*d)*Sqrt[c + d*x]) + (2*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(Sqrt[b]*d^(5/2))}
{x/(Sqrt[a + b*x]*(c + d*x)^(5/2)), x, 5, -((2*c*Sqrt[a + b*x])/(3*d*(b*c - a*d)*(c + d*x)^(3/2))) + (2*(b*c - 3*a*d)*Sqrt[a + b*x])/(3*d*(b*c - a*d)^2*Sqrt[c + d*x])}
{1/(Sqrt[a + b*x]*(c + d*x)^(5/2)), x, 2, (2*Sqrt[a + b*x])/(3*(b*c - a*d)*(c + d*x)^(3/2)) + (4*b*Sqrt[a + b*x])/(3*(b*c - a*d)^2*Sqrt[c + d*x])}
{1/(x*Sqrt[a + b*x]*(c + d*x)^(5/2)), x, 6, -((2*d*Sqrt[a + b*x])/(3*c*(b*c - a*d)*(c + d*x)^(3/2))) - (4*b*d*Sqrt[a + b*x])/(3*c*(b*c - a*d)^2*Sqrt[c + d*x]) - (2*d*Sqrt[a + b*x])/(c^2*(b*c - a*d)*Sqrt[c + d*x]) - (2*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(Sqrt[a]*c^(5/2))}
{1/(x^2*Sqrt[a + b*x]*(c + d*x)^(5/2)), x, 7, (2*d^2*Sqrt[a + b*x])/(3*c^2*(b*c - a*d)*(c + d*x)^(3/2)) + (4*b*d^2*Sqrt[a + b*x])/(3*c^2*(b*c - a*d)^2*Sqrt[c + d*x]) + (4*d^2*Sqrt[a + b*x])/(c^3*(b*c - a*d)*Sqrt[c + d*x]) - (Sqrt[a + b*x]*Sqrt[c + d*x])/(a*c^3*x) + (b*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(a^(3/2)*c^(5/2)) + (5*d*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(Sqrt[a]*c^(7/2))}
{1/(x^3*Sqrt[a + b*x]*(c + d*x)^(5/2)), x, 11, -((2*d^3*Sqrt[a + b*x])/(3*c^3*(b*c - a*d)*(c + d*x)^(3/2))) - (4*b*d^3*Sqrt[a + b*x])/(3*c^3*(b*c - a*d)^2*Sqrt[c + d*x]) - (6*d^3*Sqrt[a + b*x])/(c^4*(b*c - a*d)*Sqrt[c + d*x]) - (Sqrt[a + b*x]*Sqrt[c + d*x])/(2*a*c^3*x^2) + (3*b*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*a^2*c^3*x) + (11*d*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*a*c^4*x) - (b*d*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(a^(3/2)*c^(7/2)) - (8*d^2*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(Sqrt[a]*c^(9/2)) - (3*(b*c + a*d)^2*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*a^(5/2)*c^(9/2))}


(* Integrands of the form x^m/((a+b*x)^(3/2)*(c+d*x)^n) where m is an integer and n>0 is a half-integer *)
{x^3/((a + b*x)^(3/2)*(c + d*x)^(3/2)), x, 9, (4*a*c^2)/(b*d^2*(b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x]) - (3*(b*c + a*d)^2)/(4*b^3*d^3*Sqrt[a + b*x]*Sqrt[c + d*x]) - (3*(b*c + a*d)^3)/(4*b^3*d^3*(b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x]) + (3*(b*c + a*d)*x)/(2*b^2*d^2*Sqrt[a + b*x]*Sqrt[c + d*x]) + x^2/(b*d*Sqrt[a + b*x]*Sqrt[c + d*x]) - (4*a*c*(b*c + a*d)*Sqrt[c + d*x])/(b*d^2*(b*c - a*d)^2*Sqrt[a + b*x]) + (3*(b*c + a*d)^3*Sqrt[c + d*x])/(2*b^2*d^3*(b*c - a*d)^2*Sqrt[a + b*x]) - (3*(b*c + a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(b^(5/2)*d^(5/2))}
{x^2/((a + b*x)^(3/2)*(c + d*x)^(3/2)), x, 5, (b*c + a*d)/(2*b^2*d^2*Sqrt[a + b*x]*Sqrt[c + d*x]) + (b*c + a*d)^2/(2*b^2*d^2*(b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x]) - x/(b*d*Sqrt[a + b*x]*Sqrt[c + d*x]) - ((b*c + a*d)^2*Sqrt[c + d*x])/(b*d^2*(b*c - a*d)^2*Sqrt[a + b*x]) + (2*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(b^(3/2)*d^(3/2))}
{x/((a + b*x)^(3/2)*(c + d*x)^(3/2)), x, 3, -((2*c)/(d*(b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])) + (2*(b*c + a*d)*Sqrt[c + d*x])/(d*(b*c - a*d)^2*Sqrt[a + b*x])}
{1/((a + b*x)^(3/2)*(c + d*x)^(3/2)), x, 2, 2/((b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x]) - (4*b*Sqrt[c + d*x])/((b*c - a*d)^2*Sqrt[a + b*x])}
{1/(x*(a + b*x)^(3/2)*(c + d*x)^(3/2)), x, 4, -((2*d)/(c*(b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])) + (2*b*(b*c + a*d)*Sqrt[c + d*x])/(a*c*(b*c - a*d)^2*Sqrt[a + b*x]) - (2*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(a^(3/2)*c^(3/2))}
{1/(x^2*(a + b*x)^(3/2)*(c + d*x)^(3/2)), x, 7, -((4*b*d)/(a*c*(b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])) - (3*(b*c + a*d))/(2*a^2*c^2*Sqrt[a + b*x]*Sqrt[c + d*x]) + (3*(b*c + a*d)^2)/(2*a^2*c^2*(b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x]) - 1/(a*c*x*Sqrt[a + b*x]*Sqrt[c + d*x]) + (8*b^2*d*Sqrt[c + d*x])/(a*c*(b*c - a*d)^2*Sqrt[a + b*x]) - (3*b*(b*c + a*d)^2*Sqrt[c + d*x])/(a^2*c^2*(b*c - a*d)^2*Sqrt[a + b*x]) + (3*(b*c + a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(a^(5/2)*c^(5/2))}
{1/(x^3*(a + b*x)^(3/2)*(c + d*x)^(3/2)), x, 12, -((3*b*d)/(2*a^2*c^2*Sqrt[a + b*x]*Sqrt[c + d*x])) + (13*b*d*(b*c + a*d))/(2*a^2*c^2*(b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x]) + (15*(b*c + a*d)^2)/(8*a^3*c^3*Sqrt[a + b*x]*Sqrt[c + d*x]) - (15*(b*c + a*d)^3)/(8*a^3*c^3*(b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x]) - 1/(2*a*c*x^2*Sqrt[a + b*x]*Sqrt[c + d*x]) + (5*(b*c + a*d))/(4*a^2*c^2*x*Sqrt[a + b*x]*Sqrt[c + d*x]) - (13*b^2*d*(b*c + a*d)*Sqrt[c + d*x])/(a^2*c^2*(b*c - a*d)^2*Sqrt[a + b*x]) + (15*b*(b*c + a*d)^3*Sqrt[c + d*x])/(4*a^3*c^3*(b*c - a*d)^2*Sqrt[a + b*x]) + (3*b*d*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(a^(5/2)*c^(5/2)) - (15*(b*c + a*d)^2*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*a^(7/2)*c^(7/2))}

{x^5/((a + b*x)^(3/2)*(c + d*x)^(5/2)), x, 19, (2*a^5)/(b^5*(b*c - a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2)) + (8*a^5*d*Sqrt[a + b*x])/(3*b^5*(b*c - a*d)^2*(c + d*x)^(3/2)) + (10*a^4*Sqrt[a + b*x])/(3*b^5*(b*c - a*d)*(c + d*x)^(3/2)) - (20*a^2*c*(a + b*x)^(3/2))/(3*b^4*d*(b*c - a*d)*(c + d*x)^(3/2)) + (10*a*(a + b*x)^(5/2))/(3*b^5*d*(c + d*x)^(3/2)) - (2*(a + b*x)^(7/2))/(3*b^5*d*(c + d*x)^(3/2)) - (20*a^2*Sqrt[a + b*x])/(b^4*d^2*Sqrt[c + d*x]) + (16*a^5*d*Sqrt[a + b*x])/(3*b^4*(b*c - a*d)^3*Sqrt[c + d*x]) + (20*a^4*Sqrt[a + b*x])/(3*b^4*(b*c - a*d)^2*Sqrt[c + d*x]) + (50*a*(a + b*x)^(3/2))/(3*b^4*d^2*Sqrt[c + d*x]) - (14*(a + b*x)^(5/2))/(3*b^4*d^2*Sqrt[c + d*x]) - (35*c*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*b^2*d^4) - (65*a*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*b^3*d^3) + (35*(a + b*x)^(3/2)*Sqrt[c + d*x])/(6*b^3*d^3) + (25*a*c*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(b^(5/2)*d^(7/2)) - (5*a^2*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(b^(7/2)*d^(5/2)) + (35*(b*c - a*d)^2*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*b^(7/2)*d^(9/2))}
{x^4/((a + b*x)^(3/2)*(c + d*x)^(5/2)), x, 14, -((2*a^4)/(b^4*(b*c - a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))) - (8*a^4*d*Sqrt[a + b*x])/(3*b^4*(b*c - a*d)^2*(c + d*x)^(3/2)) - (8*a^3*Sqrt[a + b*x])/(3*b^4*(b*c - a*d)*(c + d*x)^(3/2)) + (8*a*(a + b*x)^(3/2))/(3*b^4*d*(c + d*x)^(3/2)) + (4*a^2*(a + b*x)^(3/2))/(b^4*(b*c - a*d)*(c + d*x)^(3/2)) - (2*(a + b*x)^(5/2))/(3*b^4*d*(c + d*x)^(3/2)) + (8*a*Sqrt[a + b*x])/(b^3*d^2*Sqrt[c + d*x]) - (16*a^4*d*Sqrt[a + b*x])/(3*b^3*(b*c - a*d)^3*Sqrt[c + d*x]) - (16*a^3*Sqrt[a + b*x])/(3*b^3*(b*c - a*d)^2*Sqrt[c + d*x]) - (10*(a + b*x)^(3/2))/(3*b^3*d^2*Sqrt[c + d*x]) + (5*Sqrt[a + b*x]*Sqrt[c + d*x])/(b^2*d^3) - (5*c*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(b^(3/2)*d^(7/2)) - (3*a*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(b^(5/2)*d^(5/2))}
{x^3/((a + b*x)^(3/2)*(c + d*x)^(5/2)), x, 10, (2*a^3)/(b^3*(b*c - a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2)) + (8*a^3*d*Sqrt[a + b*x])/(3*b^3*(b*c - a*d)^2*(c + d*x)^(3/2)) + (2*a^2*Sqrt[a + b*x])/(b^3*(b*c - a*d)*(c + d*x)^(3/2)) - (2*(a + b*x)^(3/2))/(3*b^3*d*(c + d*x)^(3/2)) - (2*a*(a + b*x)^(3/2))/(b^3*(b*c - a*d)*(c + d*x)^(3/2)) - (2*Sqrt[a + b*x])/(b^2*d^2*Sqrt[c + d*x]) + (16*a^3*d*Sqrt[a + b*x])/(3*b^2*(b*c - a*d)^3*Sqrt[c + d*x]) + (4*a^2*Sqrt[a + b*x])/(b^2*(b*c - a*d)^2*Sqrt[c + d*x]) + (2*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(b^(3/2)*d^(5/2))}
{x^2/((a + b*x)^(3/2)*(c + d*x)^(5/2)), x, 7, -((2*a^2)/(b^2*(b*c - a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))) - (8*a^2*d*Sqrt[a + b*x])/(3*b^2*(b*c - a*d)^2*(c + d*x)^(3/2)) - (4*a*Sqrt[a + b*x])/(3*b^2*(b*c - a*d)*(c + d*x)^(3/2)) + (2*(a + b*x)^(3/2))/(3*b^2*(b*c - a*d)*(c + d*x)^(3/2)) - (16*a^2*d*Sqrt[a + b*x])/(3*b*(b*c - a*d)^3*Sqrt[c + d*x]) - (8*a*Sqrt[a + b*x])/(3*b*(b*c - a*d)^2*Sqrt[c + d*x])}
{x/((a + b*x)^(3/2)*(c + d*x)^(5/2)), x, 6, (2*a)/(b*(b*c - a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2)) + (8*a*d*Sqrt[a + b*x])/(3*b*(b*c - a*d)^2*(c + d*x)^(3/2)) + (2*Sqrt[a + b*x])/(3*b*(b*c - a*d)*(c + d*x)^(3/2)) + (16*a*d*Sqrt[a + b*x])/(3*(b*c - a*d)^3*Sqrt[c + d*x]) + (4*Sqrt[a + b*x])/(3*(b*c - a*d)^2*Sqrt[c + d*x])}
{1/((a + b*x)^(3/2)*(c + d*x)^(5/2)), x, 3, -(2/((b*c - a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))) - (8*d*Sqrt[a + b*x])/(3*(b*c - a*d)^2*(c + d*x)^(3/2)) - (16*b*d*Sqrt[a + b*x])/(3*(b*c - a*d)^3*Sqrt[c + d*x])}
{1/(x*(a + b*x)^(3/2)*(c + d*x)^(5/2)), x, 10, (2*b)/(a*(b*c - a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2)) + (8*b*d*Sqrt[a + b*x])/(3*a*(b*c - a*d)^2*(c + d*x)^(3/2)) - (2*d*Sqrt[a + b*x])/(3*a*c*(b*c - a*d)*(c + d*x)^(3/2)) + (16*b^2*d*Sqrt[a + b*x])/(3*a*(b*c - a*d)^3*Sqrt[c + d*x]) - (4*b*d*Sqrt[a + b*x])/(3*a*c*(b*c - a*d)^2*Sqrt[c + d*x]) - (2*d*Sqrt[a + b*x])/(a*c^2*(b*c - a*d)*Sqrt[c + d*x]) - (2*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(a^(3/2)*c^(5/2))}
{1/(x^2*(a + b*x)^(3/2)*(c + d*x)^(5/2)), x, 15, -((2*d^2)/(c^2*(b*c - a*d)*Sqrt[a + b*x]*(c + d*x)^(3/2))) - (8*d^3*Sqrt[a + b*x])/(3*c^2*(b*c - a*d)^2*(c + d*x)^(3/2)) - (3*b)/(2*a^2*c^2*Sqrt[a + b*x]*Sqrt[c + d*x]) - (5*d)/(2*a*c^3*Sqrt[a + b*x]*Sqrt[c + d*x]) - (3*b*d)/(a*c^2*(b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x]) + d^2/(c^3*(b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x]) + (3*(b*c + a*d)^2)/(2*a^2*c^3*(b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x]) - 1/(a*c^2*x*Sqrt[a + b*x]*Sqrt[c + d*x]) - (16*b*d^3*Sqrt[a + b*x])/(3*c^2*(b*c - a*d)^3*Sqrt[c + d*x]) + (6*b^2*d*Sqrt[c + d*x])/(a*c^2*(b*c - a*d)^2*Sqrt[a + b*x]) - (2*b*d^2*Sqrt[c + d*x])/(c^3*(b*c - a*d)^2*Sqrt[a + b*x]) - (3*b*(b*c + a*d)^2*Sqrt[c + d*x])/(a^2*c^3*(b*c - a*d)^2*Sqrt[a + b*x]) + (3*b*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(a^(5/2)*c^(5/2)) + (5*d*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(a^(3/2)*c^(7/2))}
(* {1/(x^3*(a + b*x)^(3/2)*(c + d*x)^(5/2)), x, 0, 0} *)


(* Integrands of the form x^m/((a+b*x)^(5/2)*(c+d*x)^n) where m is an integer and n>0 is a half-integer *)
{x^3/((a + b*x)^(5/2)*(c + d*x)^(5/2)), x, 16, -((2*a*c)/(3*b^2*d^2*(a + b*x)^(3/2)*(c + d*x)^(3/2))) - (a*c*(b*c + a*d))/(2*b^2*d^2*(b*c - a*d)*(a + b*x)^(3/2)*(c + d*x)^(3/2)) + (b*c + a*d)^2/(24*b^3*d^3*(a + b*x)^(3/2)*(c + d*x)^(3/2)) + (b*c + a*d)^3/(24*b^3*d^3*(b*c - a*d)*(a + b*x)^(3/2)*(c + d*x)^(3/2)) - ((b*c + a*d)*x)/(4*b^2*d^2*(a + b*x)^(3/2)*(c + d*x)^(3/2)) - x^2/(b*d*(a + b*x)^(3/2)*(c + d*x)^(3/2)) - (3*a*c*(b*c + a*d))/(b*d^2*(b*c - a*d)^2*(a + b*x)^(3/2)*Sqrt[c + d*x]) + (b*c + a*d)^3/(4*b^2*d^3*(b*c - a*d)^2*(a + b*x)^(3/2)*Sqrt[c + d*x]) + (4*a*c*(b*c + a*d)*Sqrt[c + d*x])/(d^2*(b*c - a*d)^3*(a + b*x)^(3/2)) - ((b*c + a*d)^3*Sqrt[c + d*x])/(3*b*d^3*(b*c - a*d)^3*(a + b*x)^(3/2)) - (8*a*c*(b*c + a*d)*Sqrt[c + d*x])/(d*(b*c - a*d)^4*Sqrt[a + b*x]) + (2*(b*c + a*d)^3*Sqrt[c + d*x])/(3*b*d^2*(b*c - a*d)^4*Sqrt[a + b*x])}
{x^2/((a + b*x)^(5/2)*(c + d*x)^(5/2)), x, 10, (a*c)/(3*b*d*(b*c - a*d)*(a + b*x)^(3/2)*(c + d*x)^(3/2)) + (b*c + a*d)/(12*b^2*d^2*(a + b*x)^(3/2)*(c + d*x)^(3/2)) + (b*c + a*d)^2/(12*b^2*d^2*(b*c - a*d)*(a + b*x)^(3/2)*(c + d*x)^(3/2)) - x/(2*b*d*(a + b*x)^(3/2)*(c + d*x)^(3/2)) + (2*a*c)/(d*(b*c - a*d)^2*(a + b*x)^(3/2)*Sqrt[c + d*x]) + (b*c + a*d)^2/(2*b*d^2*(b*c - a*d)^2*(a + b*x)^(3/2)*Sqrt[c + d*x]) - (8*a*b*c*Sqrt[c + d*x])/(3*d*(b*c - a*d)^3*(a + b*x)^(3/2)) - (2*(b*c + a*d)^2*Sqrt[c + d*x])/(3*d^2*(b*c - a*d)^3*(a + b*x)^(3/2)) + (16*a*b*c*Sqrt[c + d*x])/(3*(b*c - a*d)^4*Sqrt[a + b*x]) + (4*(b*c + a*d)^2*Sqrt[c + d*x])/(3*d*(b*c - a*d)^4*Sqrt[a + b*x])}
{x/((a + b*x)^(5/2)*(c + d*x)^(5/2)), x, 5, -((2*c)/(3*d*(b*c - a*d)*(a + b*x)^(3/2)*(c + d*x)^(3/2))) - (2*(b*c + a*d))/(d*(b*c - a*d)^2*(a + b*x)^(3/2)*Sqrt[c + d*x]) + (8*b*(b*c + a*d)*Sqrt[c + d*x])/(3*d*(b*c - a*d)^3*(a + b*x)^(3/2)) - (16*b*(b*c + a*d)*Sqrt[c + d*x])/(3*(b*c - a*d)^4*Sqrt[a + b*x])}
{1/((a + b*x)^(5/2)*(c + d*x)^(5/2)), x, 4, 2/(3*(b*c - a*d)*(a + b*x)^(3/2)*(c + d*x)^(3/2)) + (4*b)/((b*c - a*d)^2*(a + b*x)^(3/2)*Sqrt[c + d*x]) - (16*b^2*Sqrt[c + d*x])/(3*(b*c - a*d)^3*(a + b*x)^(3/2)) + (32*b^2*d*Sqrt[c + d*x])/(3*(b*c - a*d)^4*Sqrt[a + b*x])}
{1/(x*(a + b*x)^(5/2)*(c + d*x)^(5/2)), x, 9, -((2*d)/(3*c*(b*c - a*d)*(a + b*x)^(3/2)*(c + d*x)^(3/2))) - (2*b*(b*c + a*d))/(a*c*(b*c - a*d)^2*(a + b*x)^(3/2)*Sqrt[c + d*x]) - (2*d)/(a*c^2*(b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x]) + (8*b^2*(b*c + a*d)*Sqrt[c + d*x])/(3*a*c*(b*c - a*d)^3*(a + b*x)^(3/2)) - (16*b^2*d*(b*c + a*d)*Sqrt[c + d*x])/(3*a*c*(b*c - a*d)^4*Sqrt[a + b*x]) + (2*b*(b*c + a*d)*Sqrt[c + d*x])/(a^2*c^2*(b*c - a*d)^2*Sqrt[a + b*x]) - (2*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(a^(5/2)*c^(5/2))}
{1/(x^2*(a + b*x)^(5/2)*(c + d*x)^(5/2)), x, 14, -((8*b*d)/(3*a*c*(b*c - a*d)*(a + b*x)^(3/2)*(c + d*x)^(3/2))) - (5*(b*c + a*d))/(6*a^2*c^2*(a + b*x)^(3/2)*(c + d*x)^(3/2)) + (5*(b*c + a*d)^2)/(6*a^2*c^2*(b*c - a*d)*(a + b*x)^(3/2)*(c + d*x)^(3/2)) - 1/(a*c*x*(a + b*x)^(3/2)*(c + d*x)^(3/2)) - (16*b^2*d)/(a*c*(b*c - a*d)^2*(a + b*x)^(3/2)*Sqrt[c + d*x]) + (5*b*(b*c + a*d)^2)/(a^2*c^2*(b*c - a*d)^2*(a + b*x)^(3/2)*Sqrt[c + d*x]) - (5*(b*c + a*d))/(2*a^3*c^3*Sqrt[a + b*x]*Sqrt[c + d*x]) + (5*(b*c + a*d)^2)/(2*a^3*c^3*(b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x]) + (64*b^3*d*Sqrt[c + d*x])/(3*a*c*(b*c - a*d)^3*(a + b*x)^(3/2)) - (20*b^2*(b*c + a*d)^2*Sqrt[c + d*x])/(3*a^2*c^2*(b*c - a*d)^3*(a + b*x)^(3/2)) - (128*b^3*d^2*Sqrt[c + d*x])/(3*a*c*(b*c - a*d)^4*Sqrt[a + b*x]) + (40*b^2*d*(b*c + a*d)^2*Sqrt[c + d*x])/(3*a^2*c^2*(b*c - a*d)^4*Sqrt[a + b*x]) - (5*b*(b*c + a*d)^2*Sqrt[c + d*x])/(a^3*c^3*(b*c - a*d)^2*Sqrt[a + b*x]) + (5*(b*c + a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(a^(7/2)*c^(7/2))}
(* {1/(x^3*(a + b*x)^(5/2)*(c + d*x)^(5/2)), x, 0, 0} *)


(* Integrands of the form x^m*Sqrt[a+b*x]*(c+d*x)^(5/2) where m is an integer *)
(* {x^4*Sqrt[a + b*x]*(c + d*x)^(5/2), x, 36, -((5*c^4*(b*c - a*d)^3*Sqrt[a + b*x]*Sqrt[c + d*x])/(64*b^3*d^5)) + (7*c^3*(b*c - a*d)^4*Sqrt[a + b*x]*Sqrt[c + d*x])/(32*b^4*d^5) - (63*c^2*(b*c - a*d)^5*Sqrt[a + b*x]*Sqrt[c + d*x])/(256*b^5*d^5) + (33*c*(b*c - a*d)^6*Sqrt[a + b*x]*Sqrt[c + d*x])/(256*b^6*d^5) - (429*(b*c - a*d)^7*Sqrt[a + b*x]*Sqrt[c + d*x])/(16384*b^7*d^5) - (5*c^4*(b*c - a*d)^2*Sqrt[a + b*x]*(c + d*x)^(3/2))/(96*b^2*d^5) + (7*c^3*(b*c - a*d)^3*Sqrt[a + b*x]*(c + d*x)^(3/2))/(48*b^3*d^5) - (21*c^2*(b*c - a*d)^4*Sqrt[a + b*x]*(c + d*x)^(3/2))/(128*b^4*d^5) + (11*c*(b*c - a*d)^5*Sqrt[a + b*x]*(c + d*x)^(3/2))/(128*b^5*d^5) - (143*(b*c - a*d)^6*Sqrt[a + b*x]*(c + d*x)^(3/2))/(8192*b^6*d^5) - (c^4*(b*c - a*d)*Sqrt[a + b*x]*(c + d*x)^(5/2))/(24*b*d^5) + (7*c^3*(b*c - a*d)^2*Sqrt[a + b*x]*(c + d*x)^(5/2))/(60*b^2*d^5) - (21*c^2*(b*c - a*d)^3*Sqrt[a + b*x]*(c + d*x)^(5/2))/(160*b^3*d^5) + (11*c*(b*c - a*d)^4*Sqrt[a + b*x]*(c + d*x)^(5/2))/(160*b^4*d^5) - (143*(b*c - a*d)^5*Sqrt[a + b*x]*(c + d*x)^(5/2))/(10240*b^5*d^5) + (c^4*Sqrt[a + b*x]*(c + d*x)^(7/2))/(4*d^5) + (c^3*(b*c - a*d)*Sqrt[a + b*x]*(c + d*x)^(7/2))/(10*b*d^5) - (9*c^2*(b*c - a*d)^2*Sqrt[a + b*x]*(c + d*x)^(7/2))/(80*b^2*d^5) + (33*c*(b*c - a*d)^3*Sqrt[a + b*x]*(c + d*x)^(7/2))/(560*b^3*d^5) - (429*(b*c - a*d)^4*Sqrt[a + b*x]*(c + d*x)^(7/2))/(35840*b^4*d^5) - (4*c^3*Sqrt[a + b*x]*(c + d*x)^(9/2))/(5*d^5) - (c^2*(b*c - a*d)*Sqrt[a + b*x]*(c + d*x)^(9/2))/(10*b*d^5) + (11*c*(b*c - a*d)^2*Sqrt[a + b*x]*(c + d*x)^(9/2))/(210*b^2*d^5) - (143*(b*c - a*d)^3*Sqrt[a + b*x]*(c + d*x)^(9/2))/(13440*b^3*d^5) + (c^2*Sqrt[a + b*x]*(c + d*x)^(11/2))/d^5 + (c*(b*c - a*d)*Sqrt[a + b*x]*(c + d*x)^(11/2))/(21*b*d^5) - (13*(b*c - a*d)^2*Sqrt[a + b*x]*(c + d*x)^(11/2))/(1344*b^2*d^5) - (4*c*Sqrt[a + b*x]*(c + d*x)^(13/2))/(7*d^5) - ((b*c - a*d)*Sqrt[a + b*x]*(c + d*x)^(13/2))/(112*b*d^5) + (Sqrt[a + b*x]*(c + d*x)^(15/2))/(8*d^5) - (5*c^4*(b*c - a*d)^4*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(64*b^(7/2)*d^(11/2)) + (7*c^3*(b*c - a*d)^5*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(32*b^(9/2)*d^(11/2)) - (63*c^2*(b*c - a*d)^6*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(256*b^(11/2)*d^(11/2)) + (33*c*(b*c - a*d)^7*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(256*b^(13/2)*d^(11/2)) - (429*(b*c - a*d)^8*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(16384*b^(15/2)*d^(11/2))} *)
{x^3*Sqrt[a + b*x]*(c + d*x)^(5/2), x, 27, (5*c^3*(b*c - a*d)^3*Sqrt[a + b*x]*Sqrt[c + d*x])/(64*b^3*d^4) - (21*c^2*(b*c - a*d)^4*Sqrt[a + b*x]*Sqrt[c + d*x])/(128*b^4*d^4) + (63*c*(b*c - a*d)^5*Sqrt[a + b*x]*Sqrt[c + d*x])/(512*b^5*d^4) - (33*(b*c - a*d)^6*Sqrt[a + b*x]*Sqrt[c + d*x])/(1024*b^6*d^4) + (5*c^3*(b*c - a*d)^2*Sqrt[a + b*x]*(c + d*x)^(3/2))/(96*b^2*d^4) - (7*c^2*(b*c - a*d)^3*Sqrt[a + b*x]*(c + d*x)^(3/2))/(64*b^3*d^4) + (21*c*(b*c - a*d)^4*Sqrt[a + b*x]*(c + d*x)^(3/2))/(256*b^4*d^4) - (11*(b*c - a*d)^5*Sqrt[a + b*x]*(c + d*x)^(3/2))/(512*b^5*d^4) + (c^3*(b*c - a*d)*Sqrt[a + b*x]*(c + d*x)^(5/2))/(24*b*d^4) - (7*c^2*(b*c - a*d)^2*Sqrt[a + b*x]*(c + d*x)^(5/2))/(80*b^2*d^4) + (21*c*(b*c - a*d)^3*Sqrt[a + b*x]*(c + d*x)^(5/2))/(320*b^3*d^4) - (11*(b*c - a*d)^4*Sqrt[a + b*x]*(c + d*x)^(5/2))/(640*b^4*d^4) - (13*c^3*Sqrt[a + b*x]*(c + d*x)^(7/2))/(40*d^4) + (3*a*c^2*Sqrt[a + b*x]*(c + d*x)^(7/2))/(40*b*d^3) + (9*c*(b*c - a*d)^2*Sqrt[a + b*x]*(c + d*x)^(7/2))/(160*b^2*d^4) - (33*(b*c - a*d)^3*Sqrt[a + b*x]*(c + d*x)^(7/2))/(2240*b^3*d^4) + (13*c^2*Sqrt[a + b*x]*(c + d*x)^(9/2))/(20*d^4) - (a*c*Sqrt[a + b*x]*(c + d*x)^(9/2))/(20*b*d^3) - (11*(b*c - a*d)^2*Sqrt[a + b*x]*(c + d*x)^(9/2))/(840*b^2*d^4) - (43*c*Sqrt[a + b*x]*(c + d*x)^(11/2))/(84*d^4) + (a*Sqrt[a + b*x]*(c + d*x)^(11/2))/(84*b*d^3) + (Sqrt[a + b*x]*(c + d*x)^(13/2))/(7*d^4) + (5*c^3*(b*c - a*d)^4*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(64*b^(7/2)*d^(9/2)) - (21*c^2*(b*c - a*d)^5*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(128*b^(9/2)*d^(9/2)) + (63*c*(b*c - a*d)^6*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(512*b^(11/2)*d^(9/2)) - (33*(b*c - a*d)^7*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(1024*b^(13/2)*d^(9/2))}
{x^2*Sqrt[a + b*x]*(c + d*x)^(5/2), x, 19, -((5*c^2*(b*c - a*d)^3*Sqrt[a + b*x]*Sqrt[c + d*x])/(64*b^3*d^3)) + (7*c*(b*c - a*d)^4*Sqrt[a + b*x]*Sqrt[c + d*x])/(64*b^4*d^3) - (21*(b*c - a*d)^5*Sqrt[a + b*x]*Sqrt[c + d*x])/(512*b^5*d^3) - (5*c^2*(b*c - a*d)^2*Sqrt[a + b*x]*(c + d*x)^(3/2))/(96*b^2*d^3) + (7*c*(b*c - a*d)^3*Sqrt[a + b*x]*(c + d*x)^(3/2))/(96*b^3*d^3) - (7*(b*c - a*d)^4*Sqrt[a + b*x]*(c + d*x)^(3/2))/(256*b^4*d^3) - (c^2*(b*c - a*d)*Sqrt[a + b*x]*(c + d*x)^(5/2))/(24*b*d^3) + (7*c*(b*c - a*d)^2*Sqrt[a + b*x]*(c + d*x)^(5/2))/(120*b^2*d^3) - (7*(b*c - a*d)^3*Sqrt[a + b*x]*(c + d*x)^(5/2))/(320*b^3*d^3) + (3*c^2*Sqrt[a + b*x]*(c + d*x)^(7/2))/(10*d^3) - (a*c*Sqrt[a + b*x]*(c + d*x)^(7/2))/(20*b*d^2) - (3*(b*c - a*d)^2*Sqrt[a + b*x]*(c + d*x)^(7/2))/(160*b^2*d^3) - (5*c*Sqrt[a + b*x]*(c + d*x)^(9/2))/(12*d^3) + (a*Sqrt[a + b*x]*(c + d*x)^(9/2))/(60*b*d^2) + (Sqrt[a + b*x]*(c + d*x)^(11/2))/(6*d^3) - (5*c^2*(b*c - a*d)^4*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(64*b^(7/2)*d^(7/2)) + (7*c*(b*c - a*d)^5*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(64*b^(9/2)*d^(7/2)) - (21*(b*c - a*d)^6*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(512*b^(11/2)*d^(7/2))}
{x*Sqrt[a + b*x]*(c + d*x)^(5/2), x, 12, (5*c*(b*c - a*d)^3*Sqrt[a + b*x]*Sqrt[c + d*x])/(64*b^3*d^2) - (7*(b*c - a*d)^4*Sqrt[a + b*x]*Sqrt[c + d*x])/(128*b^4*d^2) + (5*c*(b*c - a*d)^2*Sqrt[a + b*x]*(c + d*x)^(3/2))/(96*b^2*d^2) - (7*(b*c - a*d)^3*Sqrt[a + b*x]*(c + d*x)^(3/2))/(192*b^3*d^2) + (c*(b*c - a*d)*Sqrt[a + b*x]*(c + d*x)^(5/2))/(24*b*d^2) - (7*(b*c - a*d)^2*Sqrt[a + b*x]*(c + d*x)^(5/2))/(240*b^2*d^2) - (11*c*Sqrt[a + b*x]*(c + d*x)^(7/2))/(40*d^2) + (a*Sqrt[a + b*x]*(c + d*x)^(7/2))/(40*b*d) + (Sqrt[a + b*x]*(c + d*x)^(9/2))/(5*d^2) + (5*c*(b*c - a*d)^4*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(64*b^(7/2)*d^(5/2)) - (7*(b*c - a*d)^5*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(128*b^(9/2)*d^(5/2))}
{Sqrt[a + b*x]*(c + d*x)^(5/2), x, 5, -((5*(b*c - a*d)^3*Sqrt[a + b*x]*Sqrt[c + d*x])/(64*b^3*d)) - (5*(b*c - a*d)^2*Sqrt[a + b*x]*(c + d*x)^(3/2))/(96*b^2*d) - ((b*c - a*d)*Sqrt[a + b*x]*(c + d*x)^(5/2))/(24*b*d) + (Sqrt[a + b*x]*(c + d*x)^(7/2))/(4*d) - (5*(b*c - a*d)^4*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(64*b^(7/2)*d^(3/2))}
{Sqrt[a + b*x]*(c + d*x)^(5/2)/x, x, 15, (7*a*c*d*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*b) - (3*a^2*d^2*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*b^2) + (5*(b*c - a*d)^2*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*b^2) + (5/12)*c*Sqrt[a + b*x]*(c + d*x)^(3/2) + (a*d*Sqrt[a + b*x]*(c + d*x)^(3/2))/(12*b) + (1/3)*Sqrt[a + b*x]*(c + d*x)^(5/2) - 2*Sqrt[a]*c^(5/2)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])] + (3*a*c^2*Sqrt[d]*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/Sqrt[b] - (a^2*c*d^(3/2)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/b^(3/2) + (3*a*Sqrt[d]*(b*c - a*d)^2*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*b^(5/2)) + (5*(b*c - a*d)^3*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(8*b^(5/2)*Sqrt[d])}
(* {Sqrt[a + b*x]*(c + d*x)^(5/2)/x^2, x, 19, 0} *)


(* Integrands of the form x^m*Sqrt[1+x]/(1-x)^(5/2) where m is an integer *)
{x^3*Sqrt[1 + x]/(1 - x)^(5/2), x, 14, -((6*Sqrt[1 + x])/Sqrt[1 - x]) - 3*Sqrt[1 - x]*Sqrt[1 + x] + (1 + x)^(3/2)/(3*(1 - x)^(3/2)) - (1/2)*x*Sqrt[1 - x^2] + (11*ArcSin[x])/2, -((6*Sqrt[1 + x])/Sqrt[1 - x]) - (5/2)*Sqrt[1 - x]*Sqrt[1 + x] + (5*(1 + x)^(3/2))/(3*(1 - x)^(3/2)) + (10*(1 + x)^(3/2))/Sqrt[1 - x] - (35/6)*Sqrt[1 - x]*(1 + x)^(3/2) - (2*(1 + x)^(5/2))/(1 - x)^(3/2) - (14*(1 + x)^(5/2))/(3*Sqrt[1 - x]) + (2*(1 + x)^(7/2))/(3*(1 - x)^(3/2)) + (11*ArcSin[x])/2}
{x^2*Sqrt[1 + x]/(1 - x)^(5/2), x, 9, -((4*Sqrt[1 + x])/Sqrt[1 - x]) - Sqrt[1 - x]*Sqrt[1 + x] + (1 + x)^(3/2)/(3*(1 - x)^(3/2)) + 3*ArcSin[x], (4*Sqrt[1 + x])/Sqrt[1 - x] - 5*Sqrt[1 - x]*Sqrt[1 + x] - (1 + x)^(3/2)/(1 - x)^(3/2) - (10*(1 + x)^(3/2))/(3*Sqrt[1 - x]) + (2*(1 + x)^(5/2))/(3*(1 - x)^(3/2)) + 3*ArcSin[x]}
{x*Sqrt[1 + x]/(1 - x)^(5/2), x, 5, -((2*Sqrt[1 + x])/Sqrt[1 - x]) + (1 + x)^(3/2)/(3*(1 - x)^(3/2)) + ArcSin[x]}
{Sqrt[1 + x]/(1 - x)^(5/2), x, 1, (1 + x)^(3/2)/(3*(1 - x)^(3/2))}
{Sqrt[1 + x]/(-1 + x)^(5/2), x, 1, -((1 + x)^(3/2)/(3*(-1 + x)^(3/2)))}
{Sqrt[1 + x]/(x*(1 - x)^(5/2)), x, 9, (2*Sqrt[1 + x])/(3*(1 - x)^(3/2)) + (5*Sqrt[1 + x])/(3*Sqrt[1 - x]) - 2*ArcTanh[Sqrt[1 - x]/Sqrt[1 + x]]}
{Sqrt[1 + x]/(x^2*(1 - x)^(5/2)), x, 12, (4*Sqrt[1 + x])/Sqrt[1 - x] + (1 + x)^(3/2)/(3*(1 - x)^(3/2)) - ((1 - x)^(3/2)*(1 + x)^(3/2))/x - x*Sqrt[1 - x^2] - 6*ArcTanh[Sqrt[1 - x]/Sqrt[1 + x]]}
{Sqrt[1 + x]/(x^3*(1 - x)^(5/2)), x, 15, (6*Sqrt[1 + x])/Sqrt[1 - x] - (1/2)*Sqrt[1 - x]*Sqrt[1 + x] + (1 + x)^(3/2)/(3*(1 - x)^(3/2)) - ((1 - x)^(3/2)*(1 + x)^(3/2))/(2*x^2) - (3*(1 - x)^(3/2)*(1 + x)^(3/2))/x - 3*x*Sqrt[1 - x^2] - 11*ArcTanh[Sqrt[1 - x]/Sqrt[1 + x]]}


(* Integrands of the form x^m*(a+b*x)^n*(c+d*x)^p where m is an integer, and n and p are half-integers *)
{x^3*Sqrt[a + b*x]/Sqrt[c + d*x], x, 12, (55*a*c^2*Sqrt[a + b*x]*Sqrt[c + d*x])/(48*b*d^3) + (23*a^2*c*Sqrt[a + b*x]*Sqrt[c + d*x])/(48*b^2*d^2) - (5*(7*b*c - a*d)*(b*c + a*d)^2*Sqrt[a + b*x]*Sqrt[c + d*x])/(64*b^3*d^4) - (3*a*c*x*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*b*d^2) + (5*(7*b*c - a*d)*(b*c + a*d)*x*Sqrt[a + b*x]*Sqrt[c + d*x])/(96*b^2*d^3) - ((7*b*c - a*d)*x^2*Sqrt[a + b*x]*Sqrt[c + d*x])/(24*b*d^2) + (x^3*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*d) + (3*a^2*c^2*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*b^(3/2)*d^(5/2)) - (3*a*c*(7*b*c - a*d)*(b*c + a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(16*b^(5/2)*d^(7/2)) - (9*a*c*(b*c + a*d)^2*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(16*b^(5/2)*d^(7/2)) + (5*(7*b*c - a*d)*(b*c + a*d)^3*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(64*b^(7/2)*d^(9/2))}
{x^2*Sqrt[a + b*x]/Sqrt[c + d*x], x, 7, -((2*a*c*Sqrt[a + b*x]*Sqrt[c + d*x])/(3*b*d^2)) + ((5*b*c - a*d)*(b*c + a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*b^2*d^3) - ((5*b*c - a*d)*x*Sqrt[a + b*x]*Sqrt[c + d*x])/(12*b*d^2) + (x^2*Sqrt[a + b*x]*Sqrt[c + d*x])/(3*d) + (3*a*c^2*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(2*Sqrt[b]*d^(5/2)) + (a^2*c*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(2*b^(3/2)*d^(3/2)) - ((5*b*c - a*d)*(b*c + a*d)^2*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(8*b^(5/2)*d^(7/2))}
{x*Sqrt[a + b*x]/Sqrt[c + d*x], x, 4, -(((3*b*c - a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*b*d^2)) + (x*Sqrt[a + b*x]*Sqrt[c + d*x])/(2*d) - (a*c*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(Sqrt[b]*d^(3/2)) + ((3*b*c - a*d)*(b*c + a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(4*b^(3/2)*d^(5/2))}
{Sqrt[a + b*x]/Sqrt[c + d*x], x, 2, (Sqrt[a + b*x]*Sqrt[c + d*x])/d - ((b*c - a*d)*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(Sqrt[b]*d^(3/2))}
{Sqrt[a + b*x]/(x*Sqrt[c + d*x]), x, 3, -((2*Sqrt[a]*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/Sqrt[c]) + (2*Sqrt[b]*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/Sqrt[d]}
{Sqrt[a + b*x]/(x^2*Sqrt[c + d*x]), x, 2, -((Sqrt[a + b*x]*Sqrt[c + d*x])/(c*x)) - ((b*c - a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(Sqrt[a]*c^(3/2))}
{Sqrt[a + b*x]/(x^3*Sqrt[c + d*x]), x, 4, -((Sqrt[a + b*x]*Sqrt[c + d*x])/(2*c*x^2)) - ((b*c - 3*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(4*a*c^2*x) + (b*d*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(Sqrt[a]*c^(3/2)) + ((b*c - 3*a*d)*(b*c + a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*a^(3/2)*c^(5/2))}
{Sqrt[a + b*x]/(x^4*Sqrt[c + d*x]), x, 7, -((Sqrt[a + b*x]*Sqrt[c + d*x])/(3*c*x^3)) - ((b*c - 5*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(12*a*c^2*x^2) + (2*b*d*Sqrt[a + b*x]*Sqrt[c + d*x])/(3*a*c^2*x) + ((b*c - 5*a*d)*(b*c + a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*a^2*c^3*x) - (b^2*d*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(2*a^(3/2)*c^(3/2)) - (3*b*d^2*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(2*Sqrt[a]*c^(5/2)) - ((b*c - 5*a*d)*(b*c + a*d)^2*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(8*a^(5/2)*c^(7/2))}
{Sqrt[a + b*x]/(x^5*Sqrt[c + d*x]), x, 12, -((Sqrt[a + b*x]*Sqrt[c + d*x])/(4*c*x^4)) - ((b*c - 7*a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(24*a*c^2*x^3) + (3*b*d*Sqrt[a + b*x]*Sqrt[c + d*x])/(8*a*c^2*x^2) + (5*(b*c - 7*a*d)*(b*c + a*d)*Sqrt[a + b*x]*Sqrt[c + d*x])/(96*a^2*c^3*x^2) - (23*b^2*d*Sqrt[a + b*x]*Sqrt[c + d*x])/(48*a^2*c^2*x) - (55*b*d^2*Sqrt[a + b*x]*Sqrt[c + d*x])/(48*a*c^3*x) - (5*(b*c - 7*a*d)*(b*c + a*d)^2*Sqrt[a + b*x]*Sqrt[c + d*x])/(64*a^3*c^4*x) - (3*b^2*d^2*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(4*a^(3/2)*c^(5/2)) - (3*b*d*(b*c - 7*a*d)*(b*c + a*d)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(16*a^(5/2)*c^(7/2)) + (9*b*d*(b*c + a*d)^2*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(16*a^(5/2)*c^(7/2)) + (5*(b*c - 7*a*d)*(b*c + a*d)^3*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + d*x])])/(64*a^(7/2)*c^(9/2))}

{x^2/(Sqrt[-1 + x]*Sqrt[1 + x]), x, 2, (1/2)*Sqrt[-1 + x]*x*Sqrt[1 + x] + ArcCosh[x]/2}
{x/(Sqrt[-1 + x]*Sqrt[1 + x]), x, 1, Sqrt[-1 + x]*Sqrt[1 + x]}
{1/(Sqrt[-1 + x]*Sqrt[1 + x]), x, 1, ArcCosh[x]}
{1/(x*Sqrt[-1 + x]*Sqrt[1 + x]), x, 1, 2*ArcTan[Sqrt[-1 + x]/Sqrt[1 + x]]}
{1/(x^2*Sqrt[-1 + x]*Sqrt[1 + x]), x, 1, (Sqrt[-1 + x]*Sqrt[1 + x])/x}
{(-1 + 2*x^2)/(Sqrt[-1 + x]*Sqrt[1 + x]), x, 5, Sqrt[-1 + x]*x*Sqrt[1 + x]}

{x^2*Sqrt[-1 + x]*Sqrt[1 + x], x, 4, (-(1/8))*Sqrt[-1 + x]*x*Sqrt[1 + x] + (1/4)*Sqrt[-1 + x]*x^3*Sqrt[1 + x] - ArcCosh[x]/8, (1/8)*Sqrt[-1 + x]*Sqrt[1 + x] + (1/8)*(-1 + x)^(3/2)*Sqrt[1 + x] + (1/4)*(-1 + x)^(3/2)*x*(1 + x)^(3/2) - ArcCosh[x]/8}
{x*Sqrt[-1 + x]*Sqrt[1 + x], x, 1, ((-1 + x)^(3/2)*(1 + x)^(3/2))/3}
{Sqrt[-1 + x]*Sqrt[1 + x], x, 3, (1/2)*Sqrt[-1 + x]*x*Sqrt[1 + x] - ArcCosh[x]/2, (1/2)*Sqrt[-1 + x]*Sqrt[1 + x] + (1/2)*(-1 + x)^(3/2)*Sqrt[1 + x] - ArcCosh[x]/2}
{Sqrt[-1 + x]*Sqrt[1 + x]/x, x, 2, Sqrt[-1 + x]*Sqrt[1 + x] - 2*ArcTan[Sqrt[-1 + x]/Sqrt[1 + x]]}
{Sqrt[-1 + x]*Sqrt[1 + x]/x^2, x, 4, -((Sqrt[-1 + x]*Sqrt[1 + x])/x) + ArcCosh[x], (-Sqrt[-1 + x])*Sqrt[1 + x] - (-1 + x)^(3/2)*Sqrt[1 + x] + ((-1 + x)^(3/2)*(1 + x)^(3/2))/x + ArcCosh[x]}

{1/(Sqrt[1 + 2*x]*Sqrt[3 + 2*x]), x, 1, ArcSinh[Sqrt[1 + 2*x]/Sqrt[2]]}
{1/(x*Sqrt[-2 + 3*x]*Sqrt[3 + 5*x]), x, 1, Sqrt[2/3]*ArcTan[(Sqrt[3/2]*Sqrt[-2 + 3*x])/Sqrt[3 + 5*x]]}

{1/(x*(1 + x)^(3/2)*(-1 + x)^(3/2)), x, 2, -(1/(Sqrt[-1 + x]*Sqrt[1 + x])) - 2*ArcTan[Sqrt[-1 + x]/Sqrt[1 + x]]}

{Sqrt[-1 + x]/(x^2*Sqrt[1 + x]), x, 2, -((Sqrt[-1 + x]*Sqrt[1 + x])/x) + 2*ArcTan[Sqrt[-1 + x]/Sqrt[1 + x]]}
(* Simplified form of above integrand: *)
{Sqrt[(-1 + x)/(1 + x)]/x^2, x, 3, -((Sqrt[-((1 - x)/(1 + x))]*(1 + x))/x) + 2*ArcTan[Sqrt[-((1 - x)/(1 + x))]]}

{x*Sqrt[1 - x]*Sqrt[1 + x], x, 1, (-(1/3))*(1 - x)^(3/2)*(1 + x)^(3/2)}
(* Checks to ensure that expansion occurs before substitution for fractional powers of linears: *) 
{x*(1 + Sqrt[1 - x]*Sqrt[1 + x]), x, 4, x^2/2 - (1/3)*(1 - x)^(3/2)*(1 + x)^(3/2)}
{x*(1 + 1/(Sqrt[2 + x]*Sqrt[3 + x])), x, 5, x^2/2 + Sqrt[2 + x]*Sqrt[3 + x] - 5*ArcSinh[Sqrt[2 + x]]}

{x^3*(2 + 3*x)^(3/2)*(1 + 4*x)^(1/2), x, 23, (213575*Sqrt[2 + 3*x]*Sqrt[1 + 4*x])/42467328 + (42715*(2 + 3*x)^(3/2)*Sqrt[1 + 4*x])/15925248 - (37613*(2 + 3*x)^(5/2)*Sqrt[1 + 4*x])/995328 + (539*(2 + 3*x)^(7/2)*Sqrt[1 + 4*x])/13824 - (293*(2 + 3*x)^(9/2)*Sqrt[1 + 4*x])/19440 + (1/486)*(2 + 3*x)^(11/2)*Sqrt[1 + 4*x] + (1067875*ArcSinh[Sqrt[3/5]*Sqrt[1 + 4*x]])/(84934656*Sqrt[3])}


{1/(Sqrt[-1 + a + b*x]*Sqrt[1 + a + b*x]), x, 1, (2/b)*ArcSinh[Sqrt[-1 + a + b*x]/Sqrt[2]]}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x)^(m/4) (c+d x)^(n/4)*)


(* Integrands of the form (c+d*x)^(n+1/4)/(a+b*x)^(1/4) where n is an integer *)
{(c + d*x)^(5/4)/(a + b*x)^(1/4), x, 6, (5*(b*c - a*d)*(a + b*x)^(3/4)*(c + d*x)^(1/4))/(8*b^2) + ((a + b*x)^(3/4)*(c + d*x)^(5/4))/(2*b) - (5*(b*c - a*d)^2*ArcTan[(d^(1/4)*(a + b*x)^(1/4))/(b^(1/4)*(c + d*x)^(1/4))])/(16*b^(9/4)*d^(3/4)) + (5*(b*c - a*d)^2*ArcTanh[(d^(1/4)*(a + b*x)^(1/4))/(b^(1/4)*(c + d*x)^(1/4))])/(16*b^(9/4)*d^(3/4))}
{(c + d*x)^(1/4)/(a + b*x)^(1/4), x, 5, ((a + b*x)^(3/4)*(c + d*x)^(1/4))/b - ((b*c - a*d)*ArcTan[(d^(1/4)*(a + b*x)^(1/4))/(b^(1/4)*(c + d*x)^(1/4))])/(2*b^(5/4)*d^(3/4)) + ((b*c - a*d)*ArcTanh[(d^(1/4)*(a + b*x)^(1/4))/(b^(1/4)*(c + d*x)^(1/4))])/(2*b^(5/4)*d^(3/4))}
{1/((a + b*x)^(1/4)*(c + d*x)^(3/4)), x, 4, -((2*ArcTan[(d^(1/4)*(a + b*x)^(1/4))/(b^(1/4)*(c + d*x)^(1/4))])/(b^(1/4)*d^(3/4))) + (2*ArcTanh[(d^(1/4)*(a + b*x)^(1/4))/(b^(1/4)*(c + d*x)^(1/4))])/(b^(1/4)*d^(3/4))}
{1/((a + b*x)^(1/4)*(c + d*x)^(7/4)), x, 1, (4*(a + b*x)^(3/4))/(3*(b*c - a*d)*(c + d*x)^(3/4))}
{1/((a + b*x)^(1/4)*(c + d*x)^(11/4)), x, 2, (4*(a + b*x)^(3/4))/(7*(b*c - a*d)*(c + d*x)^(7/4)) + (16*b*(a + b*x)^(3/4))/(21*(b*c - a*d)^2*(c + d*x)^(3/4))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a+b x)^n*)


(* Integrands of the form x^m*(a+b*x)^n where m is an integer and n is symbolic *)
{x^3*(a + b*x)^n, x, 4, -((6*a^3*(a + b*x)^(1 + n))/(b^4*(1 + n)*(2 + n)*(3 + n)*(4 + n))) + (6*a^2*x*(a + b*x)^(1 + n))/(b^3*(2 + n)*(3 + n)*(4 + n)) - (3*a*x^2*(a + b*x)^(1 + n))/(b^2*(3 + n)*(4 + n)) + (x^3*(a + b*x)^(1 + n))/(b*(4 + n))}
{x^2*(a + b*x)^n, x, 3, (2*a^2*(a + b*x)^(1 + n))/(b^3*(1 + n)*(2 + n)*(3 + n)) - (2*a*x*(a + b*x)^(1 + n))/(b^2*(2 + n)*(3 + n)) + (x^2*(a + b*x)^(1 + n))/(b*(3 + n))}
{x*(a + b*x)^n, x, 2, -((a*(a + b*x)^(1 + n))/(b^2*(1 + n)*(2 + n))) + (x*(a + b*x)^(1 + n))/(b*(2 + n))}
{(a + b*x)^n, x, 1, (a + b*x)^(1 + n)/(b*(1 + n))}
{(a + b*x)^n/x, x, 0, Int[(a + b*x)^n/x, x]}
{(a + b*x)^n/x^2, x, 1, -((a + b*x)^(1 + n)/(a*x)) + (b*n*Int[(a + b*x)^n/x, x])/a}
{(a + b*x)^n/x^3, x, 2, -((a + b*x)^(1 + n)/(2*a*x^2)) + (b*(1 - n)*(a + b*x)^(1 + n))/(2*a^2*x) - (b^2*(1 - n)*n*Int[(a + b*x)^n/x, x])/(2*a^2)}


(* Integrands of the form x^m*(a+b*x)^n where m is symbolic and n is an integer *)
{x^m*(a + b*x)^3, x, 2, (a^3*x^(1 + m))/(1 + m) + (3*a^2*b*x^(2 + m))/(2 + m) + (3*a*b^2*x^(3 + m))/(3 + m) + (b^3*x^(4 + m))/(4 + m)}
{x^m*(a + b*x)^2, x, 2, (a^2*x^(1 + m))/(1 + m) + (2*a*b*x^(2 + m))/(2 + m) + (b^2*x^(3 + m))/(3 + m)}
{x^m*(a + b*x), x, 2, (a*x^(1 + m))/(1 + m) + (b*x^(2 + m))/(2 + m)}
{x^m/(a + b*x), x, 0, Int[x^m/(a + b*x), x]}
{x^m/(a + b*x)^2, x, 1, x^(1 + m)/(a*(a + b*x)) - (m*Int[x^m/(a + b*x), x])/a}
{x^m/(a + b*x)^3, x, 2, x^(1 + m)/(2*a*(a + b*x)^2) + ((1 - m)*x^(1 + m))/(2*a^2*(a + b*x)) - ((1 - m)*m*Int[x^m/(a + b*x), x])/(2*a^2)}


(* Integrands of the form x^m*(a+b*x)^n where m and n are symbolic *)
{x^(-4 + n)/(a + b*x)^n, x, 3, -((x^(-3 + n)*(a + b*x)^(1 - n))/(a*(1 - n))) + (2*x^(-3 + n)*(a + b*x)^(2 - n))/(a^2*(1 - n)*(2 - n)) - (2*x^(-3 + n)*(a + b*x)^(3 - n))/(a^3*(1 - n)*(2 - n)*(3 - n))}
{x^(-3 + n)/(a + b*x)^n, x, 2, -((x^(-2 + n)*(a + b*x)^(1 - n))/(a*(1 - n))) + (x^(-2 + n)*(a + b*x)^(2 - n))/(a^2*(1 - n)*(2 - n))}
{x^(-2 + n)/(a + b*x)^n, x, 1, -((x^(-1 + n)*(a + b*x)^(1 - n))/(a*(1 - n)))}
{x^(-1 + n)/(a + b*x)^n, x, 1, (x^n*(a + b*x)^(1 - n))/(a*n) - (b*Int[x^n/(a + b*x)^n, x])/(a*n)}
{x^n/(a + b*x)^n, x, 0, Int[x^n/(a + b*x)^n, x]}
{x^(1 + n)/(a + b*x)^n, x, 1, (x^(1 + n)*(a + b*x)^(1 - n))/(2*b) - (a*(1 + n)*Int[x^n/(a + b*x)^n, x])/(2*b)}
{x^(2 + n)/(a + b*x)^n, x, 2, -((a*(2 + n)*x^(1 + n)*(a + b*x)^(1 - n))/(6*b^2)) + (x^(2 + n)*(a + b*x)^(1 - n))/(3*b) + (a^2*(1 + n)*(2 + n)*Int[x^n/(a + b*x)^n, x])/(6*b^2)}


(* ::Subsection::Closed:: *)
(*Integrands involving sums of fractional powers of linear binomials*)


(* Integrands of the form (a+b*Sqrt[x])^n where n is a positive integer *)
{a + b*Sqrt[x], x, 1, a*x + (2/3)*b*x^(3/2)}
{(a + b*Sqrt[x])^2, x, 3, a^2*x + (4/3)*a*b*x^(3/2) + (b^2*x^2)/2}
{(a + b*Sqrt[x])^3, x, 3, -((a*(a + b*Sqrt[x])^4)/(10*b^2)) + (2*(a + b*Sqrt[x])^4*Sqrt[x])/(5*b)}
{(a + b*Sqrt[x])^4, x, 3, -((a*(a + b*Sqrt[x])^5)/(15*b^2)) + ((a + b*Sqrt[x])^5*Sqrt[x])/(3*b)}
{(a + b*Sqrt[x])^5, x, 3, -((a*(a + b*Sqrt[x])^6)/(21*b^2)) + (2*(a + b*Sqrt[x])^6*Sqrt[x])/(7*b)}
{(a + b*Sqrt[x])^6, x, 3, -((a*(a + b*Sqrt[x])^7)/(28*b^2)) + ((a + b*Sqrt[x])^7*Sqrt[x])/(4*b)}
{(a + b*Sqrt[x])^7, x, 3, -((a*(a + b*Sqrt[x])^8)/(36*b^2)) + (2*(a + b*Sqrt[x])^8*Sqrt[x])/(9*b)}
{(a + b*Sqrt[x])^8, x, 3, -((a*(a + b*Sqrt[x])^9)/(45*b^2)) + ((a + b*Sqrt[x])^9*Sqrt[x])/(5*b)}


(* Integrands of the form x^m/(Sqrt[a+b*x]+Sqrt[c+b*x])^n where m and n are integers *)
{x^2/(Sqrt[a + b*x] + Sqrt[c + b*x]), x, 9, (16*a^2*(a + b*x)^(3/2))/(105*b^3*(a - c)) - (8*a*x*(a + b*x)^(3/2))/(35*b^2*(a - c)) + (2*x^2*(a + b*x)^(3/2))/(7*b*(a - c)) - (16*c^2*(c + b*x)^(3/2))/(105*b^3*(a - c)) + (8*c*x*(c + b*x)^(3/2))/(35*b^2*(a - c)) - (2*x^2*(c + b*x)^(3/2))/(7*b*(a - c))}
{x/(Sqrt[a + b*x] + Sqrt[c + b*x]), x, 7, -((4*a*(a + b*x)^(3/2))/(15*b^2*(a - c))) + (2*x*(a + b*x)^(3/2))/(5*b*(a - c)) + (4*c*(c + b*x)^(3/2))/(15*b^2*(a - c)) - (2*x*(c + b*x)^(3/2))/(5*b*(a - c))}
{1/(Sqrt[a + b*x] + Sqrt[c + b*x]), x, 4, (2*(a + b*x)^(3/2))/(3*b*(a - c)) - (2*(c + b*x)^(3/2))/(3*b*(a - c))}
{1/(x*(Sqrt[a + b*x] + Sqrt[c + b*x])), x, 7, (2*Sqrt[a + b*x])/(a - c) - (2*Sqrt[c + b*x])/(a - c) - (2*Sqrt[a]*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(a - c) + (2*Sqrt[c]*ArcTanh[Sqrt[c + b*x]/Sqrt[c]])/(a - c)}
{1/(x^2*(Sqrt[a + b*x] + Sqrt[c + b*x])), x, 7, -(Sqrt[a + b*x]/((a - c)*x)) + Sqrt[c + b*x]/((a - c)*x) - (b*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(Sqrt[a]*(a - c)) + (b*ArcTanh[Sqrt[c + b*x]/Sqrt[c]])/((a - c)*Sqrt[c])}

{x^2/(Sqrt[a + b*x] + Sqrt[c + b*x])^2, x, 12, ((a + c)*x^3)/(3*(a - c)^2) + (b*x^4)/(2*(a - c)^2) - (a*c*Sqrt[a + b*x]*Sqrt[c + b*x])/(8*b^3*(a - c)) + (5*(a + c)^2*Sqrt[a + b*x]*Sqrt[c + b*x])/(32*b^3*(a - c)) + (a*c*(a + b*x)^(3/2)*Sqrt[c + b*x])/(4*b^3*(a - c)^2) - (5*(a + c)^2*(a + b*x)^(3/2)*Sqrt[c + b*x])/(16*b^3*(a - c)^2) + (5*(a + c)*(a + b*x)^(3/2)*(c + b*x)^(3/2))/(12*b^3*(a - c)^2) - (x*(a + b*x)^(3/2)*(c + b*x)^(3/2))/(2*b^2*(a - c)^2) - (a*c*ArcTanh[Sqrt[a + b*x]/Sqrt[c + b*x]])/(8*b^3) + (5*(a + c)^2*ArcTanh[Sqrt[a + b*x]/Sqrt[c + b*x]])/(32*b^3)}
{x/(Sqrt[a + b*x] + Sqrt[c + b*x])^2, x, 8, ((a + c)*x^2)/(2*(a - c)^2) + (2*b*x^3)/(3*(a - c)^2) - ((a + c)*Sqrt[a + b*x]*Sqrt[c + b*x])/(4*b^2*(a - c)) + ((a + c)*(a + b*x)^(3/2)*Sqrt[c + b*x])/(2*b^2*(a - c)^2) - (2*(a + b*x)^(3/2)*(c + b*x)^(3/2))/(3*b^2*(a - c)^2) - ((a + c)*ArcTanh[Sqrt[a + b*x]/Sqrt[c + b*x]])/(4*b^2)}
{1/(Sqrt[a + b*x] + Sqrt[c + b*x])^2, x, -7, (a - c)^2/(8*b*(Sqrt[a + b*x] + Sqrt[c + b*x])^4) + ArcTanh[Sqrt[a + b*x]/Sqrt[c + b*x]]/(2*b)}
{1/(x*(Sqrt[a + b*x] + Sqrt[c + b*x])^2), x, 7, (2*b*x)/(a - c)^2 - (2*Sqrt[a + b*x]*Sqrt[c + b*x])/(a - c)^2 - (2*(a + c)*ArcTanh[Sqrt[a + b*x]/Sqrt[c + b*x]])/(a - c)^2 + (4*Sqrt[a]*Sqrt[c]*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + b*x])])/(a - c)^2 + ((a + c)*Log[x])/(a - c)^2}
{1/(x^2*(Sqrt[a + b*x] + Sqrt[c + b*x])^2), x, 11, -((a + c)/((a - c)^2*x)) + (b*Sqrt[a + b*x]*Sqrt[c + b*x])/(a*(a - c)*c) - (b*(a + c)*Sqrt[a + b*x]*Sqrt[c + b*x])/(a*(a - c)^2*c) - (2*b*(a + b*x)^(3/2)*Sqrt[c + b*x])/(a*(a - c)^2*c) + (2*(a + b*x)^(3/2)*(c + b*x)^(3/2))/(a*(a - c)^2*c*x) + (b*ArcTanh[Sqrt[a + b*x]/Sqrt[c + b*x]])/(a*c) - (b*(a + c)^2*ArcTanh[Sqrt[a + b*x]/Sqrt[c + b*x]])/(a*(a - c)^2*c) + (2*b*(a + c)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[a]*Sqrt[c + b*x])])/(Sqrt[a]*(a - c)^2*Sqrt[c]) + (2*b*Log[x])/(a - c)^2}

{x^2/(Sqrt[a + b*x] + Sqrt[c + b*x])^3, x, 17, -((16*a^3*(a + b*x)^(3/2))/(63*b^3*(a - c)^3)) + (16*a^2*c*(a + b*x)^(3/2))/(35*b^3*(a - c)^3) + (8*a^2*x*(a + b*x)^(3/2))/(21*b^2*(a - c)^3) - (24*a*c*x*(a + b*x)^(3/2))/(35*b^2*(a - c)^3) - (10*a*x^2*(a + b*x)^(3/2))/(21*b*(a - c)^3) + (6*c*x^2*(a + b*x)^(3/2))/(7*b*(a - c)^3) + (8*x^3*(a + b*x)^(3/2))/(9*(a - c)^3) - (16*a*c^2*(c + b*x)^(3/2))/(35*b^3*(a - c)^3) + (16*c^3*(c + b*x)^(3/2))/(63*b^3*(a - c)^3) + (24*a*c*x*(c + b*x)^(3/2))/(35*b^2*(a - c)^3) - (8*c^2*x*(c + b*x)^(3/2))/(21*b^2*(a - c)^3) - (6*a*x^2*(c + b*x)^(3/2))/(7*b*(a - c)^3) + (10*c*x^2*(c + b*x)^(3/2))/(21*b*(a - c)^3) - (8*x^3*(c + b*x)^(3/2))/(9*(a - c)^3)}
{x/(Sqrt[a + b*x] + Sqrt[c + b*x])^3, x, 13, (12*a^2*(a + b*x)^(3/2))/(35*b^2*(a - c)^3) - (4*a*c*(a + b*x)^(3/2))/(5*b^2*(a - c)^3) - (18*a*x*(a + b*x)^(3/2))/(35*b*(a - c)^3) + (6*c*x*(a + b*x)^(3/2))/(5*b*(a - c)^3) + (8*x^2*(a + b*x)^(3/2))/(7*(a - c)^3) + (4*a*c*(c + b*x)^(3/2))/(5*b^2*(a - c)^3) - (12*c^2*(c + b*x)^(3/2))/(35*b^2*(a - c)^3) - (6*a*x*(c + b*x)^(3/2))/(5*b*(a - c)^3) + (18*c*x*(c + b*x)^(3/2))/(35*b*(a - c)^3) - (8*x^2*(c + b*x)^(3/2))/(7*(a - c)^3)}
{1/(Sqrt[a + b*x] + Sqrt[c + b*x])^3, x, -9, (a - c)^2/(10*b*(Sqrt[a + b*x] + Sqrt[c + b*x])^5) - 1/(2*b*(Sqrt[a + b*x] + Sqrt[c + b*x]))}
{1/(x*(Sqrt[a + b*x] + Sqrt[c + b*x])^3), x, 9, (2*(a + 3*c)*Sqrt[a + b*x])/(a - c)^3 + (8*(a + b*x)^(3/2))/(3*(a - c)^3) - (2*(3*a + c)*Sqrt[c + b*x])/(a - c)^3 - (8*(c + b*x)^(3/2))/(3*(a - c)^3) - (2*Sqrt[a]*(a + 3*c)*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(a - c)^3 + (2*Sqrt[c]*(3*a + c)*ArcTanh[Sqrt[c + b*x]/Sqrt[c]])/(a - c)^3}
{1/(x^2*(Sqrt[a + b*x] + Sqrt[c + b*x])^3), x, 11, (8*b*Sqrt[a + b*x])/(a - c)^3 - ((a + 3*c)*Sqrt[a + b*x])/((a - c)^3*x) - (8*b*Sqrt[c + b*x])/(a - c)^3 + ((3*a + c)*Sqrt[c + b*x])/((a - c)^3*x) - (9*Sqrt[a]*b*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(a - c)^3 - (3*b*c*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(Sqrt[a]*(a - c)^3) + (3*a*b*ArcTanh[Sqrt[c + b*x]/Sqrt[c]])/((a - c)^3*Sqrt[c]) + (9*b*Sqrt[c]*ArcTanh[Sqrt[c + b*x]/Sqrt[c]])/(a - c)^3}


(* Integrands of the form x^m/(Sqrt[a+b*x]+Sqrt[a+c*x])^n where m and n are integers *)
{x^2/(Sqrt[a + b*x] + Sqrt[a + c*x]), x, 7, -((4*a*(a + b*x)^(3/2))/(15*b^2*(b - c))) + (2*x*(a + b*x)^(3/2))/(5*b*(b - c)) + (4*a*(a + c*x)^(3/2))/(15*(b - c)*c^2) - (2*x*(a + c*x)^(3/2))/(5*(b - c)*c)}
{x/(Sqrt[a + b*x] + Sqrt[a + c*x]), x, 4, (2*(a + b*x)^(3/2))/(3*b*(b - c)) - (2*(a + c*x)^(3/2))/(3*(b - c)*c)}
{1/(Sqrt[a + b*x] + Sqrt[a + c*x]), x, 7, (2*Sqrt[a + b*x])/(b - c) - (2*Sqrt[a + c*x])/(b - c) - (2*Sqrt[a]*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(b - c) + (2*Sqrt[a]*ArcTanh[Sqrt[a + c*x]/Sqrt[a]])/(b - c)}
{1/(x*(Sqrt[a + b*x] + Sqrt[a + c*x])), x, 7, -(Sqrt[a + b*x]/((b - c)*x)) + Sqrt[a + c*x]/((b - c)*x) - (b*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(Sqrt[a]*(b - c)) + (c*ArcTanh[Sqrt[a + c*x]/Sqrt[a]])/(Sqrt[a]*(b - c))}
{1/(x^2*(Sqrt[a + b*x] + Sqrt[a + c*x])), x, 9, -(Sqrt[a + b*x]/(2*(b - c)*x^2)) - (b*Sqrt[a + b*x])/(4*a*(b - c)*x) + Sqrt[a + c*x]/(2*(b - c)*x^2) + (c*Sqrt[a + c*x])/(4*a*(b - c)*x) + (b^2*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(4*a^(3/2)*(b - c)) - (c^2*ArcTanh[Sqrt[a + c*x]/Sqrt[a]])/(4*a^(3/2)*(b - c))}

{x^2/(Sqrt[a + b*x] + Sqrt[a + c*x])^2, x, 7, (2*a*x)/(b - c)^2 + ((b + c)*x^2)/(2*(b - c)^2) - (a*Sqrt[a + b*x]*Sqrt[a + c*x])/(2*b*(b - c)*c) - ((a + b*x)^(3/2)*Sqrt[a + c*x])/(b*(b - c)^2) + (a^2*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[a + c*x])])/(2*b^(3/2)*c^(3/2))}
{x/(Sqrt[a + b*x] + Sqrt[a + c*x])^2, x, 7, ((b + c)*x)/(b - c)^2 - (2*Sqrt[a + b*x]*Sqrt[a + c*x])/(b - c)^2 + (4*a*ArcTanh[Sqrt[a + b*x]/Sqrt[a + c*x]])/(b - c)^2 - (2*a*(b + c)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[a + c*x])])/(Sqrt[b]*(b - c)^2*Sqrt[c]) + (2*a*Log[x])/(b - c)^2}
{1/(Sqrt[a + b*x] + Sqrt[a + c*x])^2, x, 11, (2*a)/((Sqrt[b] + Sqrt[c])^2*(a + Sqrt[b]*Sqrt[c]*x + Sqrt[a + b*x]*Sqrt[a + c*x])) + (2*(b + c)*ArcTanh[Sqrt[a + b*x]/Sqrt[a + c*x]])/(b - c)^2 - (4*Sqrt[b]*Sqrt[c]*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[a + c*x])])/(b - c)^2 + ((b + c)*Log[x])/(b - c)^2, -((2*a)/((b - c)^2*x)) - (Sqrt[a + b*x]*Sqrt[a + c*x])/(a*(b - c)) - ((b + c)*Sqrt[a + b*x]*Sqrt[a + c*x])/(a*(b - c)^2) - (2*c*(a + b*x)^(3/2)*Sqrt[a + c*x])/(a^2*(b - c)^2) + (2*(a + b*x)^(3/2)*(a + c*x)^(3/2))/(a^2*(b - c)^2*x) + (2*(b + c)*ArcTanh[Sqrt[a + b*x]/Sqrt[a + c*x]])/(b - c)^2 + ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[a + c*x])]/(Sqrt[b]*Sqrt[c]) - ((b + c)^2*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[a + c*x])])/(Sqrt[b]*(b - c)^2*Sqrt[c]) + ((b + c)*Log[x])/(b - c)^2}
{1/(x*(Sqrt[a + b*x] + Sqrt[a + c*x])^2), x, 15, -(a/((b - c)^2*x^2)) - (b + c)/((b - c)^2*x) - (b*c*Sqrt[a + b*x]*Sqrt[a + c*x])/(a^2*(b - c)^2) + ((b + c)*Sqrt[a + b*x]*Sqrt[a + c*x])/(4*a^2*(b - c)) + ((b + c)^2*Sqrt[a + b*x]*Sqrt[a + c*x])/(4*a^2*(b - c)^2) + (c*(b + c)*(a + b*x)^(3/2)*Sqrt[a + c*x])/(2*a^3*(b - c)^2) + ((a + b*x)^(3/2)*(a + c*x)^(3/2))/(a^2*(b - c)^2*x^2) - ((b + c)*(a + b*x)^(3/2)*(a + c*x)^(3/2))/(2*a^3*(b - c)^2*x) + (2*b*c*ArcTanh[Sqrt[a + b*x]/Sqrt[a + c*x]])/(a*(b - c)^2) - ((b + c)^2*ArcTanh[Sqrt[a + b*x]/Sqrt[a + c*x]])/(2*a*(b - c)^2) - ((b + c)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[a + c*x])])/(4*a*Sqrt[b]*Sqrt[c]) - (Sqrt[b]*Sqrt[c]*(b + c)*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[a + c*x])])/(a*(b - c)^2) + ((b + c)^3*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[a + c*x])])/(4*a*Sqrt[b]*(b - c)^2*Sqrt[c])}
{1/(x^2*(Sqrt[a + b*x] + Sqrt[a + c*x])^2), x, 16, -((2*a)/(3*(b - c)^2*x^3)) - (b + c)/(2*(b - c)^2*x^2) + (b*c*(b + c)*Sqrt[a + b*x]*Sqrt[a + c*x])/(2*a^3*(b - c)^2) - ((b + c)^2*Sqrt[a + b*x]*Sqrt[a + c*x])/(8*a^3*(b - c)) - ((b + c)^3*Sqrt[a + b*x]*Sqrt[a + c*x])/(8*a^3*(b - c)^2) - (c*(b + c)^2*(a + b*x)^(3/2)*Sqrt[a + c*x])/(4*a^4*(b - c)^2) + (2*(a + b*x)^(3/2)*(a + c*x)^(3/2))/(3*a^2*(b - c)^2*x^3) - ((b + c)*(a + b*x)^(3/2)*(a + c*x)^(3/2))/(2*a^3*(b - c)^2*x^2) + ((b + c)^2*(a + b*x)^(3/2)*(a + c*x)^(3/2))/(4*a^4*(b - c)^2*x) - (b*c*(b + c)*ArcTanh[Sqrt[a + b*x]/Sqrt[a + c*x]])/(a^2*(b - c)^2) + ((b + c)^3*ArcTanh[Sqrt[a + b*x]/Sqrt[a + c*x]])/(4*a^2*(b - c)^2) + ((b + c)^2*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[a + c*x])])/(8*a^2*Sqrt[b]*Sqrt[c]) + (Sqrt[b]*Sqrt[c]*(b + c)^2*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[a + c*x])])/(2*a^2*(b - c)^2) - ((b + c)^4*ArcTanh[(Sqrt[c]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[a + c*x])])/(8*a^2*Sqrt[b]*(b - c)^2*Sqrt[c])}

{x^2/(Sqrt[a + b*x] + Sqrt[a + c*x])^3, x, 9, (8*a*Sqrt[a + b*x])/(b - c)^3 + (2*(b + 3*c)*(a + b*x)^(3/2))/(3*b*(b - c)^3) - (8*a*Sqrt[a + c*x])/(b - c)^3 - (2*(3*b + c)*(a + c*x)^(3/2))/(3*(b - c)^3*c) - (8*a^(3/2)*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(b - c)^3 + (8*a^(3/2)*ArcTanh[Sqrt[a + c*x]/Sqrt[a]])/(b - c)^3}
{x/(Sqrt[a + b*x] + Sqrt[a + c*x])^3, x, 11, (2*(b + 3*c)*Sqrt[a + b*x])/(b - c)^3 - (4*a*Sqrt[a + b*x])/((b - c)^3*x) - (2*(3*b + c)*Sqrt[a + c*x])/(b - c)^3 + (4*a*Sqrt[a + c*x])/((b - c)^3*x) - (6*Sqrt[a]*b*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(b - c)^3 - (6*Sqrt[a]*c*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(b - c)^3 + (6*Sqrt[a]*b*ArcTanh[Sqrt[a + c*x]/Sqrt[a]])/(b - c)^3 + (6*Sqrt[a]*c*ArcTanh[Sqrt[a + c*x]/Sqrt[a]])/(b - c)^3}
{1/(Sqrt[a + b*x] + Sqrt[a + c*x])^3, x, 13, -((2*a*Sqrt[a + b*x])/((b - c)^3*x^2)) - (2*b*Sqrt[a + b*x])/((b - c)^3*x) - (3*c*Sqrt[a + b*x])/((b - c)^3*x) + (2*a*Sqrt[a + c*x])/((b - c)^3*x^2) + (3*b*Sqrt[a + c*x])/((b - c)^3*x) + (2*c*Sqrt[a + c*x])/((b - c)^3*x) - (3*b*c*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(Sqrt[a]*(b - c)^3) + (3*b*c*ArcTanh[Sqrt[a + c*x]/Sqrt[a]])/(Sqrt[a]*(b - c)^3)}
{1/(x*(Sqrt[a + b*x] + Sqrt[a + c*x])^3), x, 17, -((4*a*Sqrt[a + b*x])/(3*(b - c)^3*x^3)) - (5*b*Sqrt[a + b*x])/(6*(b - c)^3*x^2) - (3*c*Sqrt[a + b*x])/(2*(b - c)^3*x^2) + (b^2*Sqrt[a + b*x])/(4*a*(b - c)^3*x) - (3*b*c*Sqrt[a + b*x])/(4*a*(b - c)^3*x) + (4*a*Sqrt[a + c*x])/(3*(b - c)^3*x^3) + (3*b*Sqrt[a + c*x])/(2*(b - c)^3*x^2) + (5*c*Sqrt[a + c*x])/(6*(b - c)^3*x^2) + (3*b*c*Sqrt[a + c*x])/(4*a*(b - c)^3*x) - (c^2*Sqrt[a + c*x])/(4*a*(b - c)^3*x) - (b^3*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(4*a^(3/2)*(b - c)^3) + (3*b^2*c*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(4*a^(3/2)*(b - c)^3) - (3*b*c^2*ArcTanh[Sqrt[a + c*x]/Sqrt[a]])/(4*a^(3/2)*(b - c)^3) + (c^3*ArcTanh[Sqrt[a + c*x]/Sqrt[a]])/(4*a^(3/2)*(b - c)^3)}
{1/(x^2*(Sqrt[a + b*x] + Sqrt[a + c*x])^3), x, 21, -((a*Sqrt[a + b*x])/((b - c)^3*x^4)) - (b*Sqrt[a + b*x])/(2*(b - c)^3*x^3) - (c*Sqrt[a + b*x])/((b - c)^3*x^3) + (b^2*Sqrt[a + b*x])/(8*a*(b - c)^3*x^2) - (b*c*Sqrt[a + b*x])/(4*a*(b - c)^3*x^2) - (3*b^3*Sqrt[a + b*x])/(16*a^2*(b - c)^3*x) + (3*b^2*c*Sqrt[a + b*x])/(8*a^2*(b - c)^3*x) + (a*Sqrt[a + c*x])/((b - c)^3*x^4) + (b*Sqrt[a + c*x])/((b - c)^3*x^3) + (c*Sqrt[a + c*x])/(2*(b - c)^3*x^3) + (b*c*Sqrt[a + c*x])/(4*a*(b - c)^3*x^2) - (c^2*Sqrt[a + c*x])/(8*a*(b - c)^3*x^2) - (3*b*c^2*Sqrt[a + c*x])/(8*a^2*(b - c)^3*x) + (3*c^3*Sqrt[a + c*x])/(16*a^2*(b - c)^3*x) + (3*b^4*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(16*a^(5/2)*(b - c)^3) - (3*b^3*c*ArcTanh[Sqrt[a + b*x]/Sqrt[a]])/(8*a^(5/2)*(b - c)^3) + (3*b*c^3*ArcTanh[Sqrt[a + c*x]/Sqrt[a]])/(8*a^(5/2)*(b - c)^3) - (3*c^4*ArcTanh[Sqrt[a + c*x]/Sqrt[a]])/(16*a^(5/2)*(b - c)^3)}


(* ::Subsection::Closed:: *)
(*Miscellaneous integrands involving fractional powers of linears*)


{Sqrt[-x]*(Sqrt[-x] + x), x, 3, (2/5)*(-x)^(5/2) - x^2/2}
{Sqrt[d*x]*(a + b*x + c*x^2), x, 3, (2*a*(d*x)^(3/2))/(3*d) + (2*b*(d*x)^(5/2))/(5*d^2) + (2*c*(d*x)^(7/2))/(7*d^3)}


(* Integrands of the form x^m*(a+b*x)^n where m is a half-integer and n is symbolic *)
{(a + b*x)^n/Sqrt[x], x, 1, 2*Subst[Int[(a + b*x^2)^n, x], x, Sqrt[x]]}
{Sqrt[x]*(a + b*x)^n, x, 2, (2*Sqrt[x]*(a + b*x)^(1 + n))/(b*(3 + 2*n)) - (2*a*Subst[Int[(a + b*x^2)^n, x], x, Sqrt[x]])/(b*(3 + 2*n))}
{(a + b*x)^n/x^(3/2), x, 2, -((2*(a + b*x)^(1 + n))/(a*Sqrt[x])) + (2*b*(1 + 2*n)*Subst[Int[(a + b*x^2)^n, x], x, Sqrt[x]])/a}
{x^(3/2)*(a + b*x)^n, x, 3, -((6*a*Sqrt[x]*(a + b*x)^(1 + n))/(b^2*(3 + 2*n)*(5 + 2*n))) + (2*x^(3/2)*(a + b*x)^(1 + n))/(b*(5 + 2*n)) + (6*a^2*Subst[Int[(a + b*x^2)^n, x], x, Sqrt[x]])/(b^2*(15 + 16*n + 4*n^2))}
{(a + b*x)^n/x^(5/2), x, 3, -((2*(a + b*x)^(1 + n))/(3*a*x^(3/2))) + (2*b*(1 - 2*n)*(a + b*x)^(1 + n))/(3*a^2*Sqrt[x]) - (2*b^2*(1 - 4*n^2)*Subst[Int[(a + b*x^2)^n, x], x, Sqrt[x]])/(3*a^2)}


(* Integrands of the form x^m*(a+b*x)^n where m is symbolic and n is a half-integer *)
{x^m/Sqrt[a + b*x], x, 1, (2*Subst[Int[(-(a/b) + x^2/b)^m, x], x, Sqrt[a + b*x]])/b}
{x^m*Sqrt[a + b*x], x, 2, (2*x^(1 + m)*Sqrt[a + b*x])/(3 + 2*m) + (2*a*Subst[Int[(-(a/b) + x^2/b)^m, x], x, Sqrt[a + b*x]])/(b*(3 + 2*m))}
{x^m/(a + b*x)^(3/2), x, 2, (2*x^(1 + m))/(a*Sqrt[a + b*x]) - (2*(1 + 2*m)*Subst[Int[(-(a/b) + x^2/b)^m, x], x, Sqrt[a + b*x]])/(a*b)}
{x^m*(a + b*x)^(3/2), x, 3, (6*a*x^(1 + m)*Sqrt[a + b*x])/((3 + 2*m)*(5 + 2*m)) + (2*x^(1 + m)*(a + b*x)^(3/2))/(5 + 2*m) + (6*a^2*Subst[Int[(-(a/b) + x^2/b)^m, x], x, Sqrt[a + b*x]])/(b*(15 + 16*m + 4*m^2))}
{x^m/(a + b*x)^(5/2), x, 3, (2*x^(1 + m))/(3*a*(a + b*x)^(3/2)) + (2*(1 - 2*m)*x^(1 + m))/(3*a^2*Sqrt[a + b*x]) - (2*(1 - 4*m^2)*Subst[Int[(-(a/b) + x^2/b)^m, x], x, Sqrt[a + b*x]])/(3*a^2*b)}


(* Integrands of the form 1/(Sqrt[a+b*x]*Sqrt[c+d*x]) *)
{1/(Sqrt[4+b*x]*Sqrt[-4+b*x]), x, 1, ArcCosh[(b*x)/4]/b}

{1/(Sqrt[(-b+b*c)/d+b*x]*Sqrt[c+d*x]), x, 1, (2*ArcSinh[(Sqrt[d]*Sqrt[-((b*(1 - c))/d) + b*x])/Sqrt[b]])/(Sqrt[b]*Sqrt[d])}
{1/(Sqrt[x]*Sqrt[-3 + 2*x]), x, 1, Sqrt[2]*ArcSinh[Sqrt[-3 + 2*x]/Sqrt[3]]}
{1/(Sqrt[2+3*x]*Sqrt[-3+2*x]), x, 1, Sqrt[2/3]*ArcSinh[Sqrt[3/13]*Sqrt[-3 + 2*x]]}
{1/(Sqrt[a+b*x]*Sqrt[c+d*x]), x, 1, (2*ArcTanh[(Sqrt[d]*Sqrt[a + b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(Sqrt[b]*Sqrt[d])}

{1/(Sqrt[(b-b*c)/d+b*x]*Sqrt[c-d*x]), x, 1, (2*ArcSin[(Sqrt[d]*Sqrt[(b*(1 - c))/d + b*x])/Sqrt[b]])/(Sqrt[b]*Sqrt[d])}
{1/(Sqrt[4 - x]*Sqrt[x]), x, 1, 2*ArcSin[Sqrt[x]/2]}
{1/(Sqrt[x]*Sqrt[3 - 2*x]), x, 1, Sqrt[2]*ArcSin[Sqrt[2/3]*Sqrt[x]]}
{1/(Sqrt[3+5*x]*Sqrt[3-2*x]), x, 1, Sqrt[2/5]*ArcSin[Sqrt[2/21]*Sqrt[3 + 5*x]]}
{1/(Sqrt[a-b*x]*Sqrt[c+d*x]), x, 1, -((2*ArcTan[(Sqrt[d]*Sqrt[a - b*x])/(Sqrt[b]*Sqrt[c + d*x])])/(Sqrt[b]*Sqrt[d]))}


{1/(a + b*Sqrt[c + d*x]), x, 4, (2*Sqrt[c + d*x])/(b*d) - (2*a*Log[a + b*Sqrt[c + d*x]])/(b^2*d)}
{x/(a + b*Sqrt[c + d*x]), x, 5, (2*(a^2 - b^2*c)*Sqrt[c + d*x])/(b^3*d^2) - (a*(c + d*x))/(b^2*d^2) + (2*(c + d*x)^(3/2))/(3*b*d^2) - (2*a*(a^2 - b^2*c)*Log[a + b*Sqrt[c + d*x]])/(b^4*d^2)}
{x^2/(a + b*Sqrt[c + d*x]), x, 5, (2*(a^2 - b^2*c)^2*Sqrt[c + d*x])/(b^5*d^3) - (a*(a^2 - 2*b^2*c)*(c + d*x))/(b^4*d^3) + (2*(a^2 - 2*b^2*c)*(c + d*x)^(3/2))/(3*b^3*d^3) - (a*(c + d*x)^2)/(2*b^2*d^3) + (2*(c + d*x)^(5/2))/(5*b*d^3) - (2*a*(a^2 - b^2*c)^2*Log[a + b*Sqrt[c + d*x]])/(b^6*d^3)}


{(1 + Sqrt[x])/(-1 + Sqrt[x]), x, 5, 4*Sqrt[x] + x + 4*Log[1 - Sqrt[x]]}
{(1 - Sqrt[2 + 3*x])/(1 + Sqrt[2 + 3*x]), x, 5, (1/3)*(-2 - 3*x) + (4/3)*Sqrt[2 + 3*x] - (4/3)*Log[1 + Sqrt[2 + 3*x]]}
{(-1 + Sqrt[a + b*x])/(1 + Sqrt[a + b*x]), x, 5, -((4*Sqrt[a + b*x])/b) + (a + b*x)/b + (4*Log[1 + Sqrt[a + b*x]])/b}


(* Integrands of the form (c+d*x)^m/(a+b*x^2) where m is a half-integer *)
{Sqrt[x]/(1 + x^2), x, 6, -(ArcTan[1 - Sqrt[2]*Sqrt[x]]/Sqrt[2]) + ArcTan[1 + Sqrt[2]*Sqrt[x]]/Sqrt[2] + Log[1 - Sqrt[2]*Sqrt[x] + x]/(2*Sqrt[2]) - Log[1 + Sqrt[2]*Sqrt[x] + x]/(2*Sqrt[2])}
{Sqrt[x]/(a + b*x^2), x, 4, ArcTan[(b^(1/4)*Sqrt[x])/(-a)^(1/4)]/((-a)^(1/4)*b^(3/4)) - ArcTanh[(b^(1/4)*Sqrt[x])/(-a)^(1/4)]/((-a)^(1/4)*b^(3/4))}
{Sqrt[x]/(1 - x^2), x, 4, -ArcTan[Sqrt[x]] + ArcTanh[Sqrt[x]]}
{Sqrt[x]/(a - b*x^2), x, 4, -(ArcTan[(b^(1/4)*Sqrt[x])/a^(1/4)]/(a^(1/4)*b^(3/4))) + ArcTanh[(b^(1/4)*Sqrt[x])/a^(1/4)]/(a^(1/4)*b^(3/4))}

{Sqrt[2 + 3*x]/(1 + x^2), x, 4, (-(1/2))*Sqrt[4 + 2*Sqrt[13]]*ArcTan[(Sqrt[-4 + 2*Sqrt[13]]*Sqrt[2 + 3*x])/(2 - Sqrt[13] + 3*x)] - (1/2)*Sqrt[-4 + 2*Sqrt[13]]*ArcTanh[(Sqrt[4 + 2*Sqrt[13]]*Sqrt[2 + 3*x])/(2 + Sqrt[13] + 3*x)]}
{Sqrt[2 + 3*x]/(1 - x^2), x, 4, -ArcTan[Sqrt[2 + 3*x]] + Sqrt[5]*ArcTanh[Sqrt[2 + 3*x]/Sqrt[5]]}
{Sqrt[2 + 3*x]/(a + b*x^2), x, 4, (Sqrt[3*Sqrt[-a]*Sqrt[b] - 2*b]*ArcTan[(Sqrt[b]*Sqrt[2 + 3*x])/Sqrt[3*Sqrt[-a]*Sqrt[b] - 2*b]])/(Sqrt[-a]*b) - (Sqrt[3*Sqrt[-a]*Sqrt[b] + 2*b]*ArcTanh[(Sqrt[b]*Sqrt[2 + 3*x])/Sqrt[3*Sqrt[-a]*Sqrt[b] + 2*b]])/(Sqrt[-a]*b)}
{Sqrt[2 + 3*x]/(a - b*x^2), x, 4, -((Sqrt[3*Sqrt[a]*Sqrt[b] - 2*b]*ArcTan[(Sqrt[b]*Sqrt[2 + 3*x])/Sqrt[3*Sqrt[a]*Sqrt[b] - 2*b]])/(Sqrt[a]*b)) + (Sqrt[3*Sqrt[a]*Sqrt[b] + 2*b]*ArcTanh[(Sqrt[b]*Sqrt[2 + 3*x])/Sqrt[3*Sqrt[a]*Sqrt[b] + 2*b]])/(Sqrt[a]*b)}

{Sqrt[c + d*x]/(1 + x^2), x, 4, (d*Sqrt[c - Sqrt[-d^2]]*ArcTanh[Sqrt[c + d*x]/Sqrt[c - Sqrt[-d^2]]])/Sqrt[-d^2] - (d*Sqrt[c + Sqrt[-d^2]]*ArcTanh[Sqrt[c + d*x]/Sqrt[c + Sqrt[-d^2]]])/Sqrt[-d^2]}
{Sqrt[c + d*x]/(1 - x^2), x, 4, (-Sqrt[c - d])*ArcTanh[Sqrt[c + d*x]/Sqrt[c - d]] + Sqrt[c + d]*ArcTanh[Sqrt[c + d*x]/Sqrt[c + d]]}
{Sqrt[c + d*x]/(a + b*x^2), x, 4, (Sqrt[b*c - Sqrt[-a]*Sqrt[b]*d]*ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c - Sqrt[-a]*Sqrt[b]*d]])/(Sqrt[-a]*b) - (Sqrt[b*c + Sqrt[-a]*Sqrt[b]*d]*ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c + Sqrt[-a]*Sqrt[b]*d]])/(Sqrt[-a]*b)}
{Sqrt[c + d*x]/(a - b*x^2), x, 4, -((Sqrt[b*c - Sqrt[a]*Sqrt[b]*d]*ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c - Sqrt[a]*Sqrt[b]*d]])/(Sqrt[a]*b)) + (Sqrt[b*c + Sqrt[a]*Sqrt[b]*d]*ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c + Sqrt[a]*Sqrt[b]*d]])/(Sqrt[a]*b)}

{1/(Sqrt[c + d*x]*(a + b*x^2)), x, 4, ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c - Sqrt[-a]*Sqrt[b]*d]]/(Sqrt[-a]*Sqrt[b*c - Sqrt[-a]*Sqrt[b]*d]) - ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c + Sqrt[-a]*Sqrt[b]*d]]/(Sqrt[-a]*Sqrt[b*c + Sqrt[-a]*Sqrt[b]*d])}
{1/(Sqrt[c + d*x]*(a - b*x^2)), x, 4, -(ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c - Sqrt[a]*Sqrt[b]*d]]/(Sqrt[a]*Sqrt[b*c - Sqrt[a]*Sqrt[b]*d])) + ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c + Sqrt[a]*Sqrt[b]*d]]/(Sqrt[a]*Sqrt[b*c + Sqrt[a]*Sqrt[b]*d])}
{(c + d*x)^(3/2)/(a - b*x^2), x, 5, -((2*d*Sqrt[c + d*x])/b) + ((2*Sqrt[b]*c*d - (b*c^2 + a*d^2)/Sqrt[a])*ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c - Sqrt[a]*Sqrt[b]*d]])/(b*Sqrt[b*c - Sqrt[a]*Sqrt[b]*d]) + ((2*Sqrt[b]*c*d + (b*c^2 + a*d^2)/Sqrt[a])*ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c + Sqrt[a]*Sqrt[b]*d]])/(b*Sqrt[b*c + Sqrt[a]*Sqrt[b]*d])}
{1/((c + d*x)^(3/2)*(a + b*x^2)), x, 5, -((2*d)/((b*c^2 + a*d^2)*Sqrt[c + d*x])) + (Sqrt[b]*((Sqrt[b]*c)/Sqrt[-a] + d)*ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c - Sqrt[-a]*Sqrt[b]*d]])/(Sqrt[b*c - Sqrt[-a]*Sqrt[b]*d]*(b*c^2 + a*d^2)) - (Sqrt[b]*((Sqrt[b]*c)/Sqrt[-a] - d)*ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c + Sqrt[-a]*Sqrt[b]*d]])/(Sqrt[b*c + Sqrt[-a]*Sqrt[b]*d]*(b*c^2 + a*d^2))}
{1/((c + d*x)^(3/2)*(a - b*x^2)), x, 5, (2*d)/((b*c^2 - a*d^2)*Sqrt[c + d*x]) - (Sqrt[b]*((Sqrt[b]*c)/Sqrt[a] + d)*ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c - Sqrt[a]*Sqrt[b]*d]])/(Sqrt[b*c - Sqrt[a]*Sqrt[b]*d]*(b*c^2 - a*d^2)) - (Sqrt[b]*(1 - (Sqrt[b]*c)/(Sqrt[a]*d))*d*ArcTanh[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[b*c + Sqrt[a]*Sqrt[b]*d]])/(Sqrt[b*c + Sqrt[a]*Sqrt[b]*d]*(b*c^2 - a*d^2))}


{Sqrt[d + e*x]/(a + b*x + c*x^2), x, 4, -((Sqrt[2]*Sqrt[2*c*d - (b - Sqrt[b^2 - 4*a*c])*e]*ArcTanh[(Sqrt[2]*Sqrt[c]*Sqrt[d + e*x])/Sqrt[2*c*d - (b - Sqrt[b^2 - 4*a*c])*e]])/(Sqrt[c]*Sqrt[b^2 - 4*a*c])) + (Sqrt[2]*Sqrt[2*c*d - (b + Sqrt[b^2 - 4*a*c])*e]*ArcTanh[(Sqrt[2]*Sqrt[c]*Sqrt[d + e*x])/Sqrt[2*c*d - (b + Sqrt[b^2 - 4*a*c])*e]])/(Sqrt[c]*Sqrt[b^2 - 4*a*c])}
{1/(Sqrt[d + e*x]*(a + b*x + c*x^2)), x, 4, -((2*Sqrt[2]*Sqrt[c]*ArcTanh[(Sqrt[2]*Sqrt[c]*Sqrt[d + e*x])/Sqrt[2*c*d - (b - Sqrt[b^2 - 4*a*c])*e]])/(Sqrt[b^2 - 4*a*c]*Sqrt[2*c*d - (b - Sqrt[b^2 - 4*a*c])*e])) + (2*Sqrt[2]*Sqrt[c]*ArcTanh[(Sqrt[2]*Sqrt[c]*Sqrt[d + e*x])/Sqrt[2*c*d - (b + Sqrt[b^2 - 4*a*c])*e]])/(Sqrt[b^2 - 4*a*c]*Sqrt[2*c*d - (b + Sqrt[b^2 - 4*a*c])*e])}
{1/((d + e*x)^(3/2)*(a + b*x + c*x^2)), x, 5, -((2*e)/((c*d^2 - b*d*e + a*e^2)*Sqrt[d + e*x])) + (Sqrt[2]*Sqrt[c]*(e - (2*c*d - b*e)/Sqrt[b^2 - 4*a*c])*ArcTanh[(Sqrt[2]*Sqrt[c]*Sqrt[d + e*x])/Sqrt[2*c*d - (b - Sqrt[b^2 - 4*a*c])*e]])/(Sqrt[2*c*d - (b - Sqrt[b^2 - 4*a*c])*e]*(c*d^2 - b*d*e + a*e^2)) + (Sqrt[2]*Sqrt[c]*(e + (2*c*d - b*e)/Sqrt[b^2 - 4*a*c])*ArcTanh[(Sqrt[2]*Sqrt[c]*Sqrt[d + e*x])/Sqrt[2*c*d - (b + Sqrt[b^2 - 4*a*c])*e]])/(Sqrt[2*c*d - (b + Sqrt[b^2 - 4*a*c])*e]*(c*d^2 - b*d*e + a*e^2))}


(* Miscellaneous integrands involving algebraic functions of linear binomials *)
{1/(Sqrt[x]*(1 + x)), x, 1, 2*ArcTan[Sqrt[x]]}
{1/((-1 - x)*Sqrt[x]), x, 1, -2*ArcTan[Sqrt[x]]}
{1/(Sqrt[x]*(4 + 9*x)), x, 1, ArcTan[(3*Sqrt[x])/2]/3}
{1/(Sqrt[x]*(9 + x)), x, 1, (2*ArcTan[Sqrt[x]/3])/3}
{1/((-2 + x)*Sqrt[2 + x]), x, 1, -ArcTanh[Sqrt[2 + x]/2]}
{1/(Sqrt[x]*(1 + x^2)), x, 6, -(ArcTan[1 - Sqrt[2]*Sqrt[x]]/Sqrt[2]) + ArcTan[1 + Sqrt[2]*Sqrt[x]]/Sqrt[2] - Log[1 - Sqrt[2]*Sqrt[x] + x]/(2*Sqrt[2]) + Log[1 + Sqrt[2]*Sqrt[x] + x]/(2*Sqrt[2])}

{1/(Sqrt[x] + Sqrt[1 + x]), x, 4, -((2*x^(3/2))/3) + (2/3)*(1 + x)^(3/2)}
{1/(Sqrt[-1 + x] + Sqrt[1 + x]), x, 4, (-(1/3))*(-1 + x)^(3/2) + (1/3)*(1 + x)^(3/2)}
{1/(1 + x - Sqrt[2 + x]), x, 3, (2*ArcTanh[(1 - 2*Sqrt[2 + x])/Sqrt[5]])/Sqrt[5] + Log[-1 - x + Sqrt[2 + x]]}
{1/(x - Sqrt[1 + x]), x, 3, (2*ArcTanh[(1 - 2*Sqrt[1 + x])/Sqrt[5]])/Sqrt[5] + Log[-x + Sqrt[1 + x]]}
{1/(x - Sqrt[2 + x]), x, 5, (4/3)*Log[2 - Sqrt[2 + x]] + (2/3)*Log[1 + Sqrt[2 + x]]}
{1/(x - Sqrt[1 - x]), x, 3, (2*ArcTanh[(1 + 2*Sqrt[1 - x])/Sqrt[5]])/Sqrt[5] + Log[-Sqrt[1 - x] + x]}
{1/(Sqrt[-1 + x] + Sqrt[x]), x, 4, (-(2/3))*(-1 + x)^(3/2) + (2*x^(3/2))/3}
{1/(4 + Sqrt[4 - x] - x), x, 2, -2*Log[1 + Sqrt[4 - x]]}

{(Sqrt[1 - x] + Sqrt[1 + x])*Sqrt[1 - x], x, 5, x - x^2/2 + (1/2)*x*Sqrt[1 - x^2] + ArcSin[x]/2}
{(Sqrt[1 - x] + Sqrt[1 + x])^2, x, 5, 2*x + x*Sqrt[1 - x^2] + ArcSin[x]}
{(-Sqrt[1 - x] - Sqrt[1 + x])*(Sqrt[1 - x] + Sqrt[1 + x]), x, 7, -2*x - x*Sqrt[1 - x^2] - ArcSin[x]}
{(Sqrt[1 - x] + Sqrt[1 + x])^2/x, x, 5, 2*Sqrt[1 - x]*Sqrt[1 + x] - 4*ArcTanh[Sqrt[1 - x]/Sqrt[1 + x]] + 2*Log[x]}
{(-Sqrt[1 - x] - Sqrt[1 + x])*(Sqrt[1 - x] + Sqrt[1 + x])/x, x, 7, -2*Sqrt[1 - x]*Sqrt[1 + x] + 4*ArcTanh[Sqrt[1 - x]/Sqrt[1 + x]] - 2*Log[x]}
{(Sqrt[1 - x] + Sqrt[1 + x])/(-Sqrt[1 - x] + Sqrt[1 + x]), x, 8, Sqrt[1 - x]*Sqrt[1 + x] - 2*ArcTanh[Sqrt[1 - x]/Sqrt[1 + x]] + Log[x]}
{(-Sqrt[-1 + x] + Sqrt[1 + x])/(Sqrt[-1 + x] + Sqrt[1 + x]), x, 7, x^2/2 - (1/2)*Sqrt[-1 + x]*x*Sqrt[1 + x] + ArcCosh[x]/2, x^2/2 - (1/2)*Sqrt[-1 + x]*Sqrt[1 + x] - (1/2)*(-1 + x)^(3/2)*Sqrt[1 + x] + ArcCosh[x]/2}

{(2*Sqrt[3 - x] + 3/Sqrt[1 + x])^2/x, x, 7, -4*x + 12*ArcSin[(1 - x)/2] - 24*Sqrt[3]*ArcTanh[Sqrt[3 - x]/(Sqrt[3]*Sqrt[1 + x])] - 18*ArcTanh[1 + 2*x] + 12*Log[x]}

{Sqrt[1 - x]/(1 + Sqrt[x]), x, 6, -2*Sqrt[1 - x] + Sqrt[1 - x]*Sqrt[x] - ArcSin[Sqrt[x]]}
{Sqrt[1 - x]/(1 - Sqrt[x]), x, 6, -2*Sqrt[1 - x] - Sqrt[1 - x]*Sqrt[x] + ArcSin[Sqrt[x]]}
{x/((1 + x)*Sqrt[2 + x]), x, 4, 2*Sqrt[2 + x] + 2*ArcTanh[Sqrt[2 + x]]}
{x/(Sqrt[2 + 5*x]*(-2 + 9*x)), x, 4, (2/45)*Sqrt[2 + 5*x] - (2*ArcTanh[(3*Sqrt[2 + 5*x])/(2*Sqrt[7])])/(27*Sqrt[7])}
{((-2 + x)*(1 + x))/Sqrt[x], x, 3, -4*Sqrt[x] - (2*x^(3/2))/3 + (2*x^(5/2))/5}
{(-1 + x^2)/Sqrt[x], x, 2, -2*Sqrt[x] + (2*x^(5/2))/5}
{Sqrt[x]*(-2 + x^2), x, 2, -((4*x^(3/2))/3) + (2*x^(7/2))/7}
{Sqrt[x]/(1 + x^3), x, 2, (2*ArcTan[x^(3/2)])/3}
{(1 + x)/Sqrt[1 - x], x, 2, -((10*Sqrt[1 - x])/3) - (2/3)*Sqrt[1 - x]*x}
{(-x + 3*x^2)/Sqrt[1 + x], x, 2, 8*Sqrt[1 + x] - (14/3)*(1 + x)^(3/2) + (6/5)*(1 + x)^(5/2)}
{(x - 2*x^3)/Sqrt[2 + 3*x], x, 2, (-(4/81))*Sqrt[2 + 3*x] - (10/81)*(2 + 3*x)^(3/2) + (8/135)*(2 + 3*x)^(5/2) - (4/567)*(2 + 3*x)^(7/2)}
{Sqrt[x]/(9 + x), x, 2, 2*Sqrt[x] - 6*ArcTan[Sqrt[x]/3]}
{(1 + x)/Sqrt[x], x, 2, 2*Sqrt[x] + (2*x^(3/2))/3}
{Sqrt[x]/(1 + x), x, 2, 2*Sqrt[x] - 2*ArcTan[Sqrt[x]]}
{(2 + x)*Sqrt[2 + 3*x], x, 2, (52/135)*(2 + 3*x)^(3/2) + (2/15)*x*(2 + 3*x)^(3/2)}
{(7 + x)/Sqrt[5 - x], x, 2, -((62*Sqrt[5 - x])/3) - (2/3)*Sqrt[5 - x]*x}
{(2 + 3*x)/Sqrt[-9 + x], x, 2, 40*Sqrt[-9 + x] + 2*Sqrt[-9 + x]*x}
{Sqrt[-1 + x]/(1 + x)^2, x, 2, -(Sqrt[-1 + x]/(1 + x)) + ArcTan[Sqrt[-1 + x]/Sqrt[2]]/Sqrt[2]}
{Sqrt[-1 + x]/(1 + x)^3, x, 3, -(Sqrt[-1 + x]/(2*(1 + x)^2)) + Sqrt[-1 + x]/(8*(1 + x)) + ArcTan[Sqrt[-1 + x]/Sqrt[2]]/(8*Sqrt[2])}
(* {Sqrt[-1 + x]/(1 + x^2)^3, x, 1/(256 Sqrt[-1+Sqrt[2]] (1+x^2)^2) (8 Sqrt[-1+Sqrt[2]] Sqrt[-1+x] (-1+x (19+x (-1+11 x)))+2 (-36+25 Sqrt[2]) (1+x^2)^2 ArcTan[(Sqrt[2 (-1+Sqrt[2])]-2 Sqrt[-1+x])/Sqrt[2 (1+Sqrt[2])]]-2 (-36+25 Sqrt[2]) (1+x^2)^2 ArcTan[(Sqrt[2 (-1+Sqrt[2])]+2 Sqrt[-1+x])/Sqrt[2 (1+Sqrt[2])]]+(14+11 Sqrt[2]) (1+x^2)^2 Log[-1+Sqrt[2]-Sqrt[2 (-1+Sqrt[2])] Sqrt[-1+x]+x]-(14+11 Sqrt[2]) (1+x^2)^2 Log[-1+Sqrt[2]+Sqrt[2 (-1+Sqrt[2])] Sqrt[-1+x]+x])} *)
{Sqrt[1 + x^2]/(-1 + x^2), x, 3, ArcSinh[x] - Sqrt[2]*ArcTanh[(Sqrt[2]*x)/Sqrt[1 + x^2]]}
{(Sqrt[1 + x]*(1 + x^3))/(1 + x^2), x, 7, -2*Sqrt[1 + x] - (2/3)*(1 + x)^(3/2) + (2/5)*(1 + x)^(5/2) - Sqrt[1 + Sqrt[2]]*ArcTan[(Sqrt[-2 + 2*Sqrt[2]]*Sqrt[1 + x])/(1 - Sqrt[2] + x)] + Sqrt[-1 + Sqrt[2]]*ArcTanh[(Sqrt[2 + 2*Sqrt[2]]*Sqrt[1 + x])/(1 + Sqrt[2] + x)]}
{-1/Sqrt[-1 + x] + 1/Sqrt[x], x, 3, -2*Sqrt[-1 + x] + 2*Sqrt[x]}
{Sqrt[-1 + x]/(1 + x), x, 2, 2*Sqrt[-1 + x] - 2*Sqrt[2]*ArcTan[Sqrt[-1 + x]/Sqrt[2]]}
{Sqrt[-2 + x]/(2 + x), x, 2, 2*Sqrt[-2 + x] - 4*ArcTan[Sqrt[-2 + x]/2]}

{1/(x*(a + b*x)^(1/3)), x, 5, (Sqrt[3]*ArcTan[(a^(1/3) + 2*(a + b*x)^(1/3))/(Sqrt[3]*a^(1/3))])/a^(1/3) + Log[a^(1/3) - (a + b*x)^(1/3)]/a^(1/3) - Log[a^(2/3) + a^(1/3)*(a + b*x)^(1/3) + (a + b*x)^(2/3)]/(2*a^(1/3))}
{(1 + x)^(1/3)/x, x, 6, 3*(1 + x)^(1/3) - Sqrt[3]*ArcTan[(1 + 2*(1 + x)^(1/3))/Sqrt[3]] + Log[1 - (1 + x)^(1/3)] - (1/2)*Log[1 + (1 + x)^(1/3) + (1 + x)^(2/3)]}
{(a + b*x)^(-1/3), x, 1, (3*(a + b*x)^(2/3))/(2*b)}
{(-1 + x)^(1/3)/(1 + x)^(1/3), x, 6, (-1 + x)^(1/3)*(1 + x)^(2/3) - (2*ArcTan[(1 + (2*(-1 + x)^(1/3))/(1 + x)^(1/3))/Sqrt[3]])/Sqrt[3] + (2/3)*Log[1 - (-1 + x)^(1/3)/(1 + x)^(1/3)] - (1/3)*Log[1 + (-1 + x)^(2/3)/(1 + x)^(2/3) + (-1 + x)^(1/3)/(1 + x)^(1/3)]}
{x/(1 + x)^(1/3), x, 2, (-(9/10))*(1 + x)^(2/3) + (3/5)*x*(1 + x)^(2/3)}
{(1 - x)^(1/3)/(1 + x), x, 6, 3*(1 - x)^(1/3) - 2^(1/3)*Sqrt[3]*ArcTan[(1 + 2^(2/3)*(1 - x)^(1/3))/Sqrt[3]] + 2^(1/3)*Log[2^(1/3) - (1 - x)^(1/3)] - Log[2^(2/3) + 2^(1/3)*(1 - x)^(1/3) + (1 - x)^(2/3)]/2^(2/3)}
{x*(c + x)^(1/3), x, 2, (-(9/28))*c*(c + x)^(4/3) + (3/7)*x*(c + x)^(4/3)}
{(3 - 2*x)^(1/3)*(7 + x), x, 2, (-(321/112))*(3 - 2*x)^(4/3) - (3/14)*(3 - 2*x)^(4/3)*x}

{(1 - x)^(2/3)*x^3, x, 4, -((243*(1 - x)^(5/3))/3080) - (81/616)*(1 - x)^(5/3)*x - (27/154)*(1 - x)^(5/3)*x^2 - (3/14)*(1 - x)^(5/3)*x^3}
{x*(1 + 2*x)^(2/3), x, 2, (-(9/160))*(1 + 2*x)^(5/3) + (3/16)*x*(1 + 2*x)^(5/3)}
{x^(2/3)/(1 + x), x, 6, (3*x^(2/3))/2 + Sqrt[3]*ArcTan[(1 - 2*x^(1/3))/Sqrt[3]] + Log[1 + x^(1/3)] - (1/2)*Log[1 - x^(1/3) + x^(2/3)]}
{(1 - x)^(1/4)/(1 + x), x, 5, 4*(1 - x)^(1/4) - 2*2^(1/4)*ArcTan[(1 - x)^(1/4)/2^(1/4)] - 2*2^(1/4)*ArcTanh[(1 - x)^(1/4)/2^(1/4)]}
{x/(3 + x)^(1/5), x, 2, (-(25/12))*(3 + x)^(4/5) + (5/9)*x*(3 + x)^(4/5)}
{(-1 + x)^(1/6)*x, x, 2, (36/91)*(-1 + x)^(7/6) + (6/13)*(-1 + x)^(7/6)*x}

{(2*x - x^2)^(3/2)/(2 - 2*x), x, 3, (-(1/2))*Sqrt[2*x - x^2] - (1/6)*(2*x - x^2)^(3/2) + (1/2)*ArcTanh[Sqrt[2*x - x^2]]}
{(2*x - x^2)^(1/2)/(2 - 2*x), x, 2, (-(1/2))*Sqrt[2*x - x^2] + (1/2)*ArcTanh[Sqrt[2*x - x^2]]}
{1/((2 - 2*x)*(2*x - x^2)^(1/2)), x, 1, (1/2)*ArcTanh[Sqrt[2*x - x^2]]}
{1/((2 - 2*x)*(2*x - x^2)^(3/2)), x, 2, -(1/(2*Sqrt[2*x - x^2])) + (1/2)*ArcTanh[Sqrt[2*x - x^2]]}
{1/((2 - 2*x)*(2*x - x^2)^(5/2)), x, 3, -(1/(6*(2*x - x^2)^(3/2))) - 1/(2*Sqrt[2*x - x^2]) + (1/2)*ArcTanh[Sqrt[2*x - x^2]]}

{(x + Sqrt[2*x - x^2])/(2 - 2*x), x, 7, -(x/2) - (1/2)*Sqrt[2*x - x^2] + (1/2)*ArcTanh[Sqrt[2*x - x^2]] - (1/2)*Log[1 - x]}

{Sqrt[x]/(Sqrt[2 - x] - Sqrt[x]), x, -37, -(x/2) - (1/2)*Sqrt[(2 - x)*x] + ArcTanh[Sqrt[2 - x]/Sqrt[x]] - (1/2)*Log[1 - x]}
