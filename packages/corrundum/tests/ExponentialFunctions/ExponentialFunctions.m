(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Exponentials*)


(* ::Section::Closed:: *)
(*Integrands involving one exponential function*)


(* ::Subsection::Closed:: *)
(*Exponentials of powers of linears*)


(* Integrands of the form x^m*E^(a+b*x) where m is an integer *)
{x^5*E^(b*x), x, 6, -((120*E^(b*x))/b^6) + (120*E^(b*x)*x)/b^5 - (60*E^(b*x)*x^2)/b^4 + (20*E^(b*x)*x^3)/b^3 - (5*E^(b*x)*x^4)/b^2 + (E^(b*x)*x^5)/b}
{x^4*E^(b*x), x, 5, (24*E^(b*x))/b^5 - (24*E^(b*x)*x)/b^4 + (12*E^(b*x)*x^2)/b^3 - (4*E^(b*x)*x^3)/b^2 + (E^(b*x)*x^4)/b}
{E^(b*x), x, 1, E^(b*x)/b}

{x^3*E^(a + b*x), x, 4, -((6*E^(a + b*x))/b^4) + (6*E^(a + b*x)*x)/b^3 - (3*E^(a + b*x)*x^2)/b^2 + (E^(a + b*x)*x^3)/b}
{x^2*E^(a + b*x), x, 3, (2*E^(a + b*x))/b^3 - (2*E^(a + b*x)*x)/b^2 + (E^(a + b*x)*x^2)/b}
{x*E^(a + b*x), x, 2, -(E^(a + b*x)/b^2) + (E^(a + b*x)*x)/b}
{E^(a + b*x), x, 1, E^(a + b*x)/b}
{E^(a + b*x)/x, x, 1, E^a*ExpIntegralEi[b*x]}
{E^(a + b*x)/x^2, x, 2, -(E^(a + b*x)/x) + b*E^a*ExpIntegralEi[b*x]}
{E^(a + b*x)/x^3, x, 3, -(E^(a + b*x)/(2*x^2)) - (b*E^(a + b*x))/(2*x) + (1/2)*b^2*E^a*ExpIntegralEi[b*x]}

{x^3/E^(a + b*x), x, 4, -((6*E^(-a - b*x))/b^4) - (6*E^(-a - b*x)*x)/b^3 - (3*E^(-a - b*x)*x^2)/b^2 - (E^(-a - b*x)*x^3)/b}
{x^2/E^(a + b*x), x, 3, -((2*E^(-a - b*x))/b^3) - (2*E^(-a - b*x)*x)/b^2 - (E^(-a - b*x)*x^2)/b}
{x/E^(a + b*x), x, 2, -(E^(-a - b*x)/b^2) - (E^(-a - b*x)*x)/b}
{x/E^(0.1*x), x, 2, -100./E^(0.1*x) - (10.*x)/E^(0.1*x)}
{1/E^(a + b*x), x, 1, -(E^(-a - b*x)/b)}
{1/(x*E^(a + b*x)), x, 1, ExpIntegralEi[(-b)*x]/E^a}
{1/(x^2*E^(a + b*x)), x, 2, -(E^(-a - b*x)/x) - (b*ExpIntegralEi[(-b)*x])/E^a}
{1/(x^3*E^(a + b*x)), x, 3, -(E^(-a - b*x)/(2*x^2)) + (b*E^(-a - b*x))/(2*x) + ((1/2)*b^2*ExpIntegralEi[(-b)*x])/E^a}


(* Integrands of the form x^m*f^(a+b*x) *)
{f^x, x, 1, f^x/Log[f]}
{f^(-x), x, 1, -(1/(f^x*Log[f]))}
{f^(2*x), x, 1, f^(2*x)/(2*Log[f])}
{10^(2*x), x, 1, (2^(-1 + 2*x)*5^(2*x))/Log[10]}
{f^(2 + 5*x), x, 1, f^(2 + 5*x)/(5*Log[f])}
{10^(2 + 5*x), x, 1, (2^(2 + 5*x)*5^(1 + 5*x))/Log[10]}
{f^(b*x), x, 1, f^(b*x)/(b*Log[f])}
{f^(a + b*x), x, 1, f^(a + b*x)/(b*Log[f])}

{5^x*x, x, 2, -(5^x/Log[5]^2) + (5^x*x)/Log[5]}


(* Integrands of the form x^m*E^(a+b*x)^2 where m is an integer *)
{x^3*E^(a + b*x)^2, x, 24, -(E^(a + b*x)^2/(2*b^4)) - (3*a*E^(a + b*x)^2*x)/(2*b^3) + (E^(a + b*x)^2*(a + b*x)^2)/(2*b^4) + (a*(3 - 2*a^2)*Sqrt[Pi]*Erfi[a + b*x])/(4*b^4)}
{x^2*E^(a + b*x)^2, x, 10, -((a*E^(a + b*x)^2)/(2*b^3)) + (E^(a + b*x)^2*x)/(2*b^2) - ((1 - 2*a^2)*Sqrt[Pi]*Erfi[a + b*x])/(4*b^3)}
{x*E^(a + b*x)^2, x, 6, E^(a + b*x)^2/(2*b^2) - (a*Sqrt[Pi]*Erfi[a + b*x])/(2*b^2)}
{E^(a + b*x)^2, x, 2, (Sqrt[Pi]*Erfi[a + b*x])/(2*b)}
{E^(a + b*x)^2/x, x, 0, Int[E^(a + b*x)^2/x, x]}
{E^(a + b*x)^2/x^2, x, 5, -(E^(a + b*x)^2/x) + b*Sqrt[Pi]*Erfi[a + b*x] + 2*a*b*Int[E^(a + b*x)^2/x, x]}
{E^(a + b*x)^2/x^3, x, 8, -(E^(a + b*x)^2/(2*x^2)) - (a*b*E^(a + b*x)^2)/x + a*b^2*Sqrt[Pi]*Erfi[a + b*x] + (1 + 2*a^2)*b^2*Int[E^(a + b*x)^2/x, x]}

{E^x^2/x^3, x, 2, -(E^x^2/(2*x^2)) + ExpIntegralEi[x^2]/2}
{E^x^2*x^5, x, 4, E^x^2 - E^x^2*x^2 + (1/2)*E^x^2*x^4}
{x^3/E^x^2, x, 3, -(1/(E^x^2*2)) - ((1/2)*x^2)/E^x^2}
{x/E^x^2, x, 2, -1/(2*E^x^2)}
{x^3/E^x^2, x, 3, -(1/(E^x^2*2)) - ((1/2)*x^2)/E^x^2}
{x^5/E^x^2, x, 4, -E^(-x^2) - x^2/E^x^2 - ((1/2)*x^4)/E^x^2}
{E^x^2*x, x, 2, E^x^2/2}


(* Integrands of the form x^m*E^(a+b*x)^3 where m is an integer *)
{x^3*E^(a + b*x)^3, x, 21, -((2*a*E^(a + b*x)^3)/(3*b^4)) + (E^(a + b*x)^3*x)/(3*b^3) + ((1 + 3*a^3)*(a + b*x)*Gamma[1/3, -(a + b*x)^3])/(9*b^4*(-(a + b*x)^3)^(1/3)) - (a^2*(a + b*x)^2*Gamma[2/3, -(a + b*x)^3])/(b^4*(-(a + b*x)^3)^(2/3))}
{x^2*E^(a + b*x)^3, x, 9, E^(a + b*x)^3/(3*b^3) - (a^2*(a + b*x)*Gamma[1/3, -(a + b*x)^3])/(3*b^3*(-(a + b*x)^3)^(1/3)) + (2*a*(a + b*x)^2*Gamma[2/3, -(a + b*x)^3])/(3*b^3*(-(a + b*x)^3)^(2/3))}
{x*E^(a + b*x)^3, x, 5, (a*(a + b*x)*Gamma[1/3, -(a + b*x)^3])/(3*b^2*(-(a + b*x)^3)^(1/3)) - ((a + b*x)^2*Gamma[2/3, -(a + b*x)^3])/(3*b^2*(-(a + b*x)^3)^(2/3))}
{E^(a + b*x)^3, x, 2, -(((a + b*x)*Gamma[1/3, -(a + b*x)^3])/(3*b*(-(a + b*x)^3)^(1/3)))}
{E^(a + b*x)^3/x, x, 0, Int[E^(a + b*x)^3/x, x]}
{E^(a + b*x)^3/x^2, x, 10, -(E^(a + b*x)^3/x) - (a*b*(a + b*x)*Gamma[1/3, -(a + b*x)^3])/(-(a + b*x)^3)^(1/3) - (b*(a + b*x)^2*Gamma[2/3, -(a + b*x)^3])/(-(a + b*x)^3)^(2/3) + 3*a^2*b*Int[E^(a + b*x)^3/x, x]}
{E^(a + b*x)^3/x^3, x, 15, -(E^(a + b*x)^3/(2*x^2)) - (3*a^2*b*E^(a + b*x)^3)/(2*x) - ((1 + 3*a^3)*b^2*(a + b*x)*Gamma[1/3, -(a + b*x)^3])/(2*(-(a + b*x)^3)^(1/3)) - (3*a^2*b^2*(a + b*x)^2*Gamma[2/3, -(a + b*x)^3])/(2*(-(a + b*x)^3)^(2/3)) + (3/2)*a*(2 + 3*a^3)*b^2*Int[E^(a + b*x)^3/x, x]}

{x^2*E^x^3, x, 2, E^x^3/3}
{E^x^3*x^5, x, 3, -(E^x^3/3) + (1/3)*E^x^3*x^3}
{E^(4*x^3)*x^2, x, 2, E^(4*x^3)/12}
{x^5/E^x^3, x, 3, -(1/(E^x^3*3)) - ((1/3)*x^3)/E^x^3}


(* Intgrands of the form f^((c+d*x)^n) *)
{E^Sqrt[x], x, 3, -2*E^Sqrt[x] + 2*E^Sqrt[x]*Sqrt[x]}
{E^(-Sqrt[x]), x, 3, -2/E^Sqrt[x] - (2*Sqrt[x])/E^Sqrt[x]}
{E^Sqrt[5 + 3*x], x, 3, (-(2/3))*E^Sqrt[5 + 3*x] + (2/3)*E^Sqrt[5 + 3*x]*Sqrt[5 + 3*x]}
{E^x^(1/3), x, 4, 6*E^x^(1/3) - 6*E^x^(1/3)*x^(1/3) + 3*E^x^(1/3)*x^(2/3)}
{E^x^(2/3), x, 3, (3/2)*E^x^(2/3)*x^(1/3) - (3/4)*Sqrt[Pi]*Erfi[x^(1/3)]}


(* Integrands of the form E^(a+b*x)^m*(a+b*x)^n where m and n are integers *)
{E^(a + b*x)*(a + b*x)^3, x, 5, -((6*E^(a + b*x))/b) + (6*E^(a + b*x)*(a + b*x))/b - (3*E^(a + b*x)*(a + b*x)^2)/b + (E^(a + b*x)*(a + b*x)^3)/b}
{E^(a + b*x)*(a + b*x)^2, x, 4, (2*E^(a + b*x))/b - (2*E^(a + b*x)*(a + b*x))/b + (E^(a + b*x)*(a + b*x)^2)/b}
{E^(a + b*x)*(a + b*x), x, 3, -(E^(a + b*x)/b) + (E^(a + b*x)*(a + b*x))/b}
{E^(a + b*x)/(a + b*x), x, 2, ExpIntegralEi[a + b*x]/b}
{E^(a + b*x)/(a + b*x)^2, x, 3, -(E^(a + b*x)/(b*(a + b*x))) + ExpIntegralEi[a + b*x]/b}
{E^(a + b*x)/(a + b*x)^3, x, 4, -(E^(a + b*x)/(2*b*(a + b*x)^2)) - E^(a + b*x)/(2*b*(a + b*x)) + ExpIntegralEi[a + b*x]/(2*b)}

{E^(a + b*x)^2*(a + b*x)^3, x, 4, -(E^(a + b*x)^2/(2*b)) + (E^(a + b*x)^2*(a + b*x)^2)/(2*b)}
{E^(a + b*x)^2*(a + b*x)^2, x, 3, (E^(a + b*x)^2*(a + b*x))/(2*b) - (Sqrt[Pi]*Erfi[a + b*x])/(4*b)}
{E^(a + b*x)^2*(a + b*x), x, 3, E^(a + b*x)^2/(2*b)}
{E^(a + b*x)^2/(a + b*x), x, 2, ExpIntegralEi[(a + b*x)^2]/(2*b)}
{E^(a + b*x)^2/(a + b*x)^2, x, 3, -(E^(a + b*x)^2/(b*(a + b*x))) + (Sqrt[Pi]*Erfi[a + b*x])/b}
{E^(a + b*x)^2/(a + b*x)^3, x, 3, -(E^(a + b*x)^2/(2*b*(a + b*x)^2)) + ExpIntegralEi[(a + b*x)^2]/(2*b)}

{E^(a + b*x)^3*(a + b*x)^3, x, 3, (E^(a + b*x)^3*(a + b*x))/(3*b) + ((a + b*x)*Gamma[1/3, -(a + b*x)^3])/(9*b*(-(a + b*x)^3)^(1/3))}
{E^(a + b*x)^3*(a + b*x)^2, x, 3, E^(a + b*x)^3/(3*b)}
{E^(a + b*x)^3*(a + b*x), x, 2, -(((a + b*x)^2*Gamma[2/3, -(a + b*x)^3])/(3*b*(-(a + b*x)^3)^(2/3)))}
{E^(a + b*x)^3/(a + b*x), x, 2, ExpIntegralEi[(a + b*x)^3]/(3*b)}
{E^(a + b*x)^3/(a + b*x)^2, x, 3, -(E^(a + b*x)^3/(b*(a + b*x))) - ((a + b*x)^2*Gamma[2/3, -(a + b*x)^3])/(b*(-(a + b*x)^3)^(2/3))}
{E^(a + b*x)^3/(a + b*x)^3, x, 3, -(E^(a + b*x)^3/(2*b*(a + b*x)^2)) - ((a + b*x)*Gamma[1/3, -(a + b*x)^3])/(2*b*(-(a + b*x)^3)^(1/3))}


(* Integrands of the form (a+b*x)^m*f ((a+b*x)^n) *)
{x^m*E^(x^n), x, 1, -((x^(1 + m)*Gamma[(1 + m)/n, -x^n])/((-x^n)^((1 + m)/n)*n))}
{x^m*f^(x^n), x, 1, -((x^(1 + m)*Gamma[(1 + m)/n, (-x^n)*Log[f]])/(((-x^n)*Log[f])^((1 + m)/n)*n))}

{(a + b*x)^m*E^((a + b*x)^n), x, 2, -(((a + b*x)^(1 + m)*Gamma[(1 + m)/n, -(a + b*x)^n])/((-(a + b*x)^n)^((1 + m)/n)*(b*n)))}
{(a + b*x)^m*f^((a + b*x)^n), x, 2, -(((a + b*x)^(1 + m)*Gamma[(1 + m)/n, (-(a + b*x)^n)*Log[f]])/(((-(a + b*x)^n)*Log[f])^((1 + m)/n)*(b*n)))}


(* Integrands of the form E^(c+d*x)^m*(a+b*x)^n where m and n are integers *)
{E^(c + d*x)*(a + b*x)^3, x, 5, -((6*b^3*E^(c + d*x))/d^4) + (6*b^2*E^(c + d*x)*(a + b*x))/d^3 - (3*b*E^(c + d*x)*(a + b*x)^2)/d^2 + (E^(c + d*x)*(a + b*x)^3)/d}
{E^(c + d*x)*(a + b*x)^2, x, 4, (2*b^2*E^(c + d*x))/d^3 - (2*b*E^(c + d*x)*(a + b*x))/d^2 + (E^(c + d*x)*(a + b*x)^2)/d}
{E^(c + d*x)*(a + b*x), x, 3, -((b*E^(c + d*x))/d^2) + (E^(c + d*x)*(a + b*x))/d}
{E^(c + d*x)/(a + b*x), x, 2, (E^(c - (a*d)/b)*ExpIntegralEi[(d*(a + b*x))/b])/b}
{E^(c + d*x)/(a + b*x)^2, x, 3, -(E^(c + d*x)/(b*(a + b*x))) + (d*E^(c - (a*d)/b)*ExpIntegralEi[(d*(a + b*x))/b])/b^2}
{E^(c + d*x)/(a + b*x)^3, x, 4, -(E^(c + d*x)/(2*b*(a + b*x)^2)) - (d*E^(c + d*x))/(2*b^2*(a + b*x)) + (d^2*E^(c - (a*d)/b)*ExpIntegralEi[(d*(a + b*x))/b])/(2*b^3)}

(* {E^(c + d*x)^2*(a + b*x)^3, x, 40, (1/(4*d^4))*(2*b*E^(c + d*x)^2*(3*a^2*d^2 + 3*a*b*d*(-c + d*x) + b^2*(-1 + c^2 - c*d*x + d^2*x^2)) + (b^3*(3*c - 2*c^3) + 3*a*b^2*(-1 + 2*c^2)*d - 6*a^2*b*c*d^2 + 2*a^3*d^3)*Sqrt[Pi]*Erfi[c + d*x])} *)
{E^(c + d*x)^2*(a + b*x)^2, x, 14, -((b*((b*c)/2 - a*d)*E^(c + d*x)^2)/d^3) + (b^2*E^(c + d*x)^2*x)/(2*d^2) - ((b^2*(1 - 2*c^2) + 4*a*b*c*d - 2*a^2*d^2)*Sqrt[Pi]*Erfi[c + d*x])/(4*d^3)}
{E^(c + d*x)^2*(a + b*x), x, 7, (b*E^(c + d*x)^2)/(2*d^2) - ((b*c - a*d)*Sqrt[Pi]*Erfi[c + d*x])/(2*d^2)}
{E^(c + d*x)^2/(a + b*x), x, 2, Subst[Int[E^((b*c - a*d + d*x)^2/b^2)/x, x], x, a + b*x]/b}

(* {E^(c + d*x)^3*(a + b*x)^3, x, 38, (1/(9*d^4*(-(c + d*x)^3)^(2/3)))*((b^3*(1 + 3*c^3) - 9*a*b^2*c^2*d + 9*a^2*b*c*d^2 - 3*a^3*d^3)*(c + d*x)*(-(c + d*x)^3)^(1/3)*Gamma[1/3, -(c + d*x)^3] - 3*b*(b*E^(c + d*x)^3*(-(c + d*x)^3)^(2/3)*(2*b*c - 3*a*d - b*d*x) + 3*(b*c - a*d)^2*(c + d*x)^2*Gamma[2/3, -(c + d*x)^3]))} *)
{E^(c + d*x)^3*(a + b*x)^2, x, 13, (b^2*E^(c + d*x)^3)/(3*d^3) - ((b*c - a*d)^2*(c + d*x)*Gamma[1/3, -(c + d*x)^3])/(3*d^3*(-(c + d*x)^3)^(1/3)) + (2*b*(b*c - a*d)*(c + d*x)^2*Gamma[2/3, -(c + d*x)^3])/(3*d^3*(-(c + d*x)^3)^(2/3))}
{E^(c + d*x)^3*(a + b*x), x, 6, ((b*c - a*d)*(c + d*x)*Gamma[1/3, -(c + d*x)^3])/(3*d^2*(-(c + d*x)^3)^(1/3)) - (b*(c + d*x)^2*Gamma[2/3, -(c + d*x)^3])/(3*d^2*(-(c + d*x)^3)^(2/3))}


(* Integrands of the form x^m*E^(a+b*x)/(c+d*x^2) where m is an integer *)
{E^(a + b*x)/(c + d*x^2), x, 5, (E^(a + (b*Sqrt[-c])/Sqrt[d])*ExpIntegralEi[-((b*(Sqrt[-c] - Sqrt[d]*x))/Sqrt[d])])/(2*Sqrt[-c]*Sqrt[d]) - (E^(a - (b*Sqrt[-c])/Sqrt[d])*ExpIntegralEi[(b*(Sqrt[-c] + Sqrt[d]*x))/Sqrt[d]])/(2*Sqrt[-c]*Sqrt[d])}
{x*E^(a + b*x)/(c + d*x^2), x, 5, (E^(a + (b*Sqrt[-c])/Sqrt[d])*ExpIntegralEi[-((b*(Sqrt[-c] - Sqrt[d]*x))/Sqrt[d])])/(2*d) + (E^(a - (b*Sqrt[-c])/Sqrt[d])*ExpIntegralEi[(b*(Sqrt[-c] + Sqrt[d]*x))/Sqrt[d]])/(2*d)}
{x^2*E^(a + b*x)/(c + d*x^2), x, 8, E^(a + b*x)/(b*d) + (Sqrt[-c]*E^(a + (b*Sqrt[-c])/Sqrt[d])*ExpIntegralEi[-((b*(Sqrt[-c] - Sqrt[d]*x))/Sqrt[d])])/(2*d^(3/2)) - (Sqrt[-c]*E^(a - (b*Sqrt[-c])/Sqrt[d])*ExpIntegralEi[(b*(Sqrt[-c] + Sqrt[d]*x))/Sqrt[d]])/(2*d^(3/2))}


(* Integrands of the form E^(a+b*x)/(c+d*x+e*x^2) *)
{E^(a + b*x)/(c + d*x + e*x^2), x, 5, (E^(a - (b*(d - Sqrt[d^2 - 4*c*e]))/(2*e))*ExpIntegralEi[(b*(d - Sqrt[d^2 - 4*c*e] + 2*e*x))/(2*e)])/Sqrt[d^2 - 4*c*e] - (E^(a - (b*(d + Sqrt[d^2 - 4*c*e]))/(2*e))*ExpIntegralEi[(b*(d + Sqrt[d^2 - 4*c*e] + 2*e*x))/(2*e)])/Sqrt[d^2 - 4*c*e]}


(* Integrands of the form 1/(a+b*E^(c+d*x))^m where m is an integer *)
{1/(a + b*E^(c + d*x)), x, 1, x/a - Log[a + b*E^(c + d*x)]/(a*d)}
{1/(a + b*E^(c + d*x))^2, x, 2, 1/(a*d*(a + b*E^(c + d*x))) + x/a^2 - Log[a + b*E^(c + d*x)]/(a^2*d)}
{1/(a + b*E^(c + d*x))^3, x, 3, 1/(2*a*d*(a + b*E^(c + d*x))^2) + 1/(a^2*d*(a + b*E^(c + d*x))) + x/a^3 - Log[a + b*E^(c + d*x)]/(a^3*d)}

{1/(a + b*E^(c - d*x)), x, 1, Log[b + a*E^(-c + d*x)]/(a*d)}
{1/(a + b*E^(c - d*x))^2, x, 2, -(1/(a*d*(a + b*E^(c - d*x)))) + Log[b + a*E^(-c + d*x)]/(a^2*d)}
{1/(a + b*E^(c - d*x))^3, x, 3, -(1/(2*a*d*(a + b*E^(c - d*x))^2)) - 1/(a^2*d*(a + b*E^(c - d*x))) + Log[b + a*E^(-c + d*x)]/(a^3*d)}

{1/(a + b*E^(-c - d*x)), x, 1, Log[b + a*E^(c + d*x)]/(a*d)}
{1/(a + b*E^(-c - d*x))^2, x, 2, -(1/(a*d*(a + b*E^(-c - d*x)))) + Log[b + a*E^(c + d*x)]/(a^2*d)}
{1/(a + b*E^(-c - d*x))^3, x, 3, -(1/(2*a*d*(a + b*E^(-c - d*x))^2)) - 1/(a^2*d*(a + b*E^(-c - d*x))) + Log[b + a*E^(c + d*x)]/(a^3*d)}


(* Integrands of the form (a+b*E^(c+d*x))^n *)
(* Note: Apart should NOT be used to expand integrands of this form! *)
{(a + b*E^x)^2, x, 4, 2*a*b*E^x + (1/2)*b^2*E^(2*x) + a^2*x}
{(a + b*E^x)^3, x, 5, 3*a^2*b*E^x + (3/2)*a*b^2*E^(2*x) + (1/3)*b^3*E^(3*x) + a^3*x}
{(a + b*E^x)^4, x, 6, 4*a^3*b*E^x + 3*a^2*b^2*E^(2*x) + (4/3)*a*b^3*E^(3*x) + (1/4)*b^4*E^(4*x) + a^4*x}

{1/Sqrt[a + b*E^(c + d*x)], x, 1, -((2*ArcTanh[Sqrt[a + b*E^(c + d*x)]/Sqrt[a]])/(Sqrt[a]*d))}
{1/Sqrt[-a + b*E^(c + d*x)], x, 1, (2*ArcTan[Sqrt[-a + b*E^(c + d*x)]/Sqrt[a]])/(Sqrt[a]*d)}

{Sqrt[a + b*E^(c + d*x)], x, 2, (2*Sqrt[a + b*E^(c + d*x)])/d - (2*Sqrt[a]*ArcTanh[Sqrt[a + b*E^(c + d*x)]/Sqrt[a]])/d}
{Sqrt[-a + b*E^(c + d*x)], x, 2, (2*Sqrt[-a + b*E^(c + d*x)])/d - (2*Sqrt[a]*ArcTan[Sqrt[-a + b*E^(c + d*x)]/Sqrt[a]])/d}


(* Integrands of the form x^m/(a+b*E^(c+d*x))^n where m and n are positive integers *)
{x/(a + b*E^(c + d*x)), x, 3, x^2/(2*a) - (x*Log[1 + (b*E^(c + d*x))/a])/(a*d) - PolyLog[2, -((b*E^(c + d*x))/a)]/(a*d^2)}
{x^2/(a + b*E^(c + d*x)), x, 4, x^3/(3*a) - (x^2*Log[1 + (b*E^(c + d*x))/a])/(a*d) - (2*x*PolyLog[2, -((b*E^(c + d*x))/a)])/(a*d^2) + (2*PolyLog[3, -((b*E^(c + d*x))/a)])/(a*d^3)}
{x^3/(a + b*E^(c + d*x)), x, 5, x^4/(4*a) - (x^3*Log[1 + (b*E^(c + d*x))/a])/(a*d) - (3*x^2*PolyLog[2, -((b*E^(c + d*x))/a)])/(a*d^2) + (6*x*PolyLog[3, -((b*E^(c + d*x))/a)])/(a*d^3) - (6*PolyLog[4, -((b*E^(c + d*x))/a)])/(a*d^4)}

{x/(a + b*E^(c + d*x))^2, x, 6, -((b*E^(c + d*x)*x)/(a^2*d*(a + b*E^(c + d*x)))) + x^2/(2*a^2) + Log[a + b*E^(c + d*x)]/(a^2*d^2) - (x*Log[1 + (b*E^(c + d*x))/a])/(a^2*d) - PolyLog[2, -((b*E^(c + d*x))/a)]/(a^2*d^2)}
{x^2/(a + b*E^(c + d*x))^2, x, 10, -((b*E^(c + d*x)*x^2)/(a^2*d*(a + b*E^(c + d*x)))) + x^3/(3*a^2) + (2*x*Log[1 + (b*E^(c + d*x))/a])/(a^2*d^2) - (x^2*Log[1 + (b*E^(c + d*x))/a])/(a^2*d) + (2*(1 - d*x)*PolyLog[2, -((b*E^(c + d*x))/a)])/(a^2*d^3) + (2*PolyLog[3, -((b*E^(c + d*x))/a)])/(a^2*d^3)}
{x^3/(a + b*E^(c + d*x))^2, x, 12, -((b*E^(c + d*x)*x^3)/(a^2*d*(a + b*E^(c + d*x)))) + x^4/(4*a^2) + (3*x^2*Log[1 + (b*E^(c + d*x))/a])/(a^2*d^2) - (x^3*Log[1 + (b*E^(c + d*x))/a])/(a^2*d) + (3*x*(2 - d*x)*PolyLog[2, -((b*E^(c + d*x))/a)])/(a^2*d^3) - (6*(1 - d*x)*PolyLog[3, -((b*E^(c + d*x))/a)])/(a^2*d^4) - (6*PolyLog[4, -((b*E^(c + d*x))/a)])/(a^2*d^4)}

{x/(a + b*E^(c + d*x))^3, x, 8, -(1/(2*a^2*d^2*(a + b*E^(c + d*x)))) - (3*x)/(2*a^3*d) + ((3*a + 2*b*E^(c + d*x))*x)/(2*a^2*d*(a + b*E^(c + d*x))^2) + x^2/(2*a^3) + (3*Log[a + b*E^(c + d*x)])/(2*a^3*d^2) - (x*Log[1 + (b*E^(c + d*x))/a])/(a^3*d) - PolyLog[2, -((b*E^(c + d*x))/a)]/(a^3*d^2)}
{x^2/(a + b*E^(c + d*x))^3, x, 16, (b*E^(c + d*x)*x)/(a^3*d^2*(a + b*E^(c + d*x))) - (3*x^2)/(2*a^3*d) + ((3*a + 2*b*E^(c + d*x))*x^2)/(2*a^2*d*(a + b*E^(c + d*x))^2) + x^3/(3*a^3) - Log[a + b*E^(c + d*x)]/(a^3*d^3) + (3*x*Log[1 + (b*E^(c + d*x))/a])/(a^3*d^2) - (x^2*Log[1 + (b*E^(c + d*x))/a])/(a^3*d) + ((3 - 2*d*x)*PolyLog[2, -((b*E^(c + d*x))/a)])/(a^3*d^3) + (2*PolyLog[3, -((b*E^(c + d*x))/a)])/(a^3*d^3)}
(* {x^3/(a + b*E^(c + d*x))^3, x, 30, (1/(4*a^3*d^4*(a + b*E^(c + d*x))^2))*(6*a*b*d^2*E^(c + d*x)*x^2 + 6*b^2*d^2*E^(2*(c + d*x))*x^2 - 8*a*b*d^3*E^(c + d*x)*x^3 - 6*b^2*d^3*E^(2*(c + d*x))*x^3 + a^2*d^4*x^4 + 2*a*b*d^4*E^(c + d*x)*x^4 + b^2*d^4*E^(2*(c + d*x))*x^4 - 12*a^2*d*x*Log[1 + (b*E^(c + d*x))/a] - 24*a*b*d*E^(c + d*x)*x*Log[1 + (b*E^(c + d*x))/a] - 12*b^2*d*E^(2*(c + d*x))*x*Log[1 + (b*E^(c + d*x))/a] + 18*a^2*d^2*x^2*Log[1 + (b*E^(c + d*x))/a] + 36*a*b*d^2*E^(c + d*x)*x^2*Log[1 + (b*E^(c + d*x))/a] + 18*b^2*d^2*E^(2*(c + d*x))*x^2*Log[1 + (b*E^(c + d*x))/a] - 4*a^2*d^3*x^3*Log[1 + (b*E^(c + d*x))/a] - 8*a*b*d^3*E^(c + d*x)*x^3*Log[1 + (b*E^(c + d*x))/a] - 4*b^2*d^3*E^(2*(c + d*x))*x^3*Log[1 + (b*E^(c + d*x))/a] - 12*(a + b*E^(c + d*x))^2*(1 - 3*d*x + d^2*x^2)*PolyLog[2, -((b*E^(c + d*x))/a)] + 12*(a + b*E^(c + d*x))^2*(-3 + 2*d*x)*PolyLog[3, -((b*E^(c + d*x))/a)] - 24*a^2*PolyLog[4, -((b*E^(c + d*x))/a)] - 48*a*b*E^(c + d*x)*PolyLog[4, -((b*E^(c + d*x))/a)] - 24*b^2*E^(2*(c + d*x))*PolyLog[4, -((b*E^(c + d*x))/a)])} *)


(* Integrands of the form x^m*f^(a+b*x) where m is a half integer *)
{x^(3/2)*f^(a + b*x), x, 4, (3*f^a*Sqrt[Pi]*Erfi[Sqrt[b]*Sqrt[x]*Sqrt[Log[f]]])/(4*b^(5/2)*Log[f]^(5/2)) - (3*f^(a + b*x)*Sqrt[x])/(2*b^2*Log[f]^2) + (f^(a + b*x)*x^(3/2))/(b*Log[f])}
{x^(1/2)*f^(a + b*x), x, 3, -((f^a*Sqrt[Pi]*Erfi[Sqrt[b]*Sqrt[x]*Sqrt[Log[f]]])/(2*b^(3/2)*Log[f]^(3/2))) + (f^(a + b*x)*Sqrt[x])/(b*Log[f])}
{f^(a + b*x)/x^(1/2), x, 2, (f^a*Sqrt[Pi]*Erfi[Sqrt[b]*Sqrt[x]*Sqrt[Log[f]]])/(Sqrt[b]*Sqrt[Log[f]])}
{f^(a + b*x)/x^(3/2), x, 3, -((2*f^(a + b*x))/Sqrt[x]) + 2*Sqrt[b]*f^a*Sqrt[Pi]*Erfi[Sqrt[b]*Sqrt[x]*Sqrt[Log[f]]]*Sqrt[Log[f]]}


(* Integrands of the form x^m*Sqrt[E^(a+b*x)] where m is an integer *)

{Sqrt[E^(a + b*x)]*x^3, x, 5, -((2*Sqrt[E^(a + b*x)]*(48 - b*x*(24 - b*x*(6 - b*x))))/b^4)}
{Sqrt[E^(a + b*x)]*x^2, x, 4, (2*Sqrt[E^(a + b*x)]*(8 - b*x*(4 - b*x)))/b^3}
{Sqrt[E^(a + b*x)]*x, x, 3, -((2*Sqrt[E^(a + b*x)]*(2 - b*x))/b^2)}
{Sqrt[E^(a + b*x)], x, 2, (2*Sqrt[E^(a + b*x)])/b}
{Sqrt[E^(a + b*x)]/x, x, 2, (Sqrt[E^(a + b*x)]*ExpIntegralEi[(b*x)/2])/E^((b*x)/2)}
{Sqrt[E^(a + b*x)]/x^2, x, 3, (-(1/2))*E^(-(a/2) - (b*x)/2)*Sqrt[E^(a + b*x)]*((2*E^(a/2 + (b*x)/2))/x - b*E^(a/2)*ExpIntegralEi[(b*x)/2])}
{Sqrt[E^(a + b*x)]/x^3, x, 4, (-(1/8))*E^(-(a/2) - (b*x)/2)*Sqrt[E^(a + b*x)]*((4*E^(a/2 + (b*x)/2))/x^2 + (2*b*E^(a/2 + (b*x)/2))/x - b^2*E^(a/2)*ExpIntegralEi[(b*x)/2])}


(* ::Subsection::Closed:: *)
(*Exponentials of binomials*)


(* Intgrands of the form f^(a+b*(c+d*x)^n) *)
{f^(a + b*(c + d*x)), x, 2, f^(a + b*c + b*d*x)/(b*d*Log[f])}
{f^(a + b*(c + d*x)^2), x, 2, (f^a*Sqrt[Pi]*Erfi[Sqrt[b]*(c + d*x)*Sqrt[Log[f]]])/(2*Sqrt[b]*d*Sqrt[Log[f]])}
{f^(a + b*(c + d*x)^3), x, 2, -((f^a*(c + d*x)*Gamma[1/3, (-b)*(c + d*x)^3*Log[f]])/(3*d*((-b)*(c + d*x)^3*Log[f])^(1/3)))}
{f^(a + b*(c + d*x)^n), x, 2, -((f^a*(c + d*x)*Gamma[1/n, (-b)*(c + d*x)^n*Log[f]])/(((-b)*(c + d*x)^n*Log[f])^n^(-1)*(d*n)))}

{f^(a + b*Sqrt[c + d*x]), x, 3, -((2*f^(a + b*Sqrt[c + d*x]))/(b^2*d*Log[f]^2)) + (2*f^(a + b*Sqrt[c + d*x])*Sqrt[c + d*x])/(b*d*Log[f])}
{f^(a + b*(c + d*x)^(1/3)), x, 4, (6*f^(a + b*(c + d*x)^(1/3)))/(b^3*d*Log[f]^3) - (6*f^(a + b*(c + d*x)^(1/3))*(c + d*x)^(1/3))/(b^2*d*Log[f]^2) + (3*f^(a + b*(c + d*x)^(1/3))*(c + d*x)^(2/3))/(b*d*Log[f])}


(* Integrands of the form x^m*f^(a+b/x^n) where m and n<0 are integers *)
{x^3*f^(a + b/x), x, 5, (1/4)*f^(a + b/x)*x^4 + (1/12)*b*f^(a + b/x)*x^3*Log[f] + (1/24)*b^2*f^(a + b/x)*x^2*Log[f]^2 + (1/24)*b^3*f^(a + b/x)*x*Log[f]^3 - (1/24)*b^4*f^a*ExpIntegralEi[(b*Log[f])/x]*Log[f]^4}
{x^2*f^(a + b/x), x, 4, (1/3)*f^(a + b/x)*x^3 + (1/6)*b*f^(a + b/x)*x^2*Log[f] + (1/6)*b^2*f^(a + b/x)*x*Log[f]^2 - (1/6)*b^3*f^a*ExpIntegralEi[(b*Log[f])/x]*Log[f]^3}
{x*f^(a + b/x), x, 3, (1/2)*f^(a + b/x)*x^2 + (1/2)*b*f^(a + b/x)*x*Log[f] - (1/2)*b^2*f^a*ExpIntegralEi[(b*Log[f])/x]*Log[f]^2}
{f^(a + b/x), x, 2, f^(a + b/x)*x - b*f^a*ExpIntegralEi[(b*Log[f])/x]*Log[f]}
{f^(a + b/x)/x, x, 1, (-f^a)*ExpIntegralEi[(b*Log[f])/x]}
{f^(a + b/x)/x^2, x, 2, -(f^(a + b/x)/(b*Log[f]))}
{f^(a + b/x)/x^3, x, 3, f^(a + b/x)/(b^2*Log[f]^2) - f^(a + b/x)/(b*x*Log[f])}
{f^(a + b/x)/x^4, x, 4, -((2*f^(a + b/x))/(b^3*Log[f]^3)) + (2*f^(a + b/x))/(b^2*x*Log[f]^2) - f^(a + b/x)/(b*x^2*Log[f])}

{x^4*f^(a + b/x^2), x, 5, (1/5)*f^(a + b/x^2)*x^5 + (2/15)*b*f^(a + b/x^2)*x^3*Log[f] + (4/15)*b^2*f^(a + b/x^2)*x*Log[f]^2 - (4/15)*b^(5/2)*f^a*Sqrt[Pi]*Erfi[(Sqrt[b]*Sqrt[Log[f]])/x]*Log[f]^(5/2)}
{x^3*f^(a + b/x^2), x, 3, (1/4)*f^(a + b/x^2)*x^4 + (1/4)*b*f^(a + b/x^2)*x^2*Log[f] - (1/4)*b^2*f^a*ExpIntegralEi[(b*Log[f])/x^2]*Log[f]^2}
{x^2*f^(a + b/x^2), x, 4, (1/3)*f^(a + b/x^2)*x^3 + (2/3)*b*f^(a + b/x^2)*x*Log[f] - (2/3)*b^(3/2)*f^a*Sqrt[Pi]*Erfi[(Sqrt[b]*Sqrt[Log[f]])/x]*Log[f]^(3/2)}
{x*f^(a + b/x^2), x, 2, (1/2)*f^(a + b/x^2)*x^2 - (1/2)*b*f^a*ExpIntegralEi[(b*Log[f])/x^2]*Log[f]}
{f^(a + b/x^2), x, 3, f^(a + b/x^2)*x - Sqrt[b]*f^a*Sqrt[Pi]*Erfi[(Sqrt[b]*Sqrt[Log[f]])/x]*Sqrt[Log[f]]}
{f^(a + b/x^2)/x, x, 1, (-(1/2))*f^a*ExpIntegralEi[(b*Log[f])/x^2]}
{f^(a + b/x^2)/x^2, x, 2, -((f^a*Sqrt[Pi]*Erfi[(Sqrt[b]*Sqrt[Log[f]])/x])/(2*Sqrt[b]*Sqrt[Log[f]]))}
{f^(a + b/x^2)/x^3, x, 2, -(f^(a + b/x^2)/(2*b*Log[f]))}
{f^(a + b/x^2)/x^4, x, 3, (f^a*Sqrt[Pi]*Erfi[(Sqrt[b]*Sqrt[Log[f]])/x])/(4*b^(3/2)*Log[f]^(3/2)) - f^(a + b/x^2)/(2*b*x*Log[f])}


(* ::Subsection::Closed:: *)
(*Exponentials of quadratic trinomials*)


(* Integrands of the form x^m*E^(a+b*x+c*x^2) where m is an integer *)
{x^3*E^(a + b*x + c*x^2), x, 13, (b^2*E^(a + b*x + c*x^2))/(8*c^3) - E^(a + b*x + c*x^2)/(2*c^2) - (b*E^(a + b*x + c*x^2)*x)/(4*c^2) + (E^(a + b*x + c*x^2)*x^2)/(2*c) - (b*(b^2 - 6*c)*E^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b + 2*c*x)/(2*Sqrt[c])])/(16*c^(7/2))}
{x^2*E^(a + b*x + c*x^2), x, 8, -((b*E^(a + b*x + c*x^2))/(4*c^2)) + (E^(a + b*x + c*x^2)*x)/(2*c) + ((b^2 - 2*c)*E^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b + 2*c*x)/(2*Sqrt[c])])/(8*c^(5/2))}
{x*E^(a + b*x + c*x^2), x, 4, E^(a + b*x + c*x^2)/(2*c) - (b*E^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b + 2*c*x)/(2*Sqrt[c])])/(4*c^(3/2))}
{E^(a + b*x + c*x^2), x, 3, (E^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b + 2*c*x)/(2*Sqrt[c])])/(2*Sqrt[c])}
{E^(a + b*x + c*x^2)/x, x, 1, E^a*Int[E^(b*x + c*x^2)/x, x]}
{E^(a + b*x + c*x^2)/x^2, x, 5, -(E^(a + b*x + c*x^2)/x) + Sqrt[c]*E^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b + 2*c*x)/(2*Sqrt[c])] + b*E^a*Int[E^(b*x + c*x^2)/x, x]}


(* Integrands of the form x^m*E^(a+b*x-c*x^2) where m is an integer *)
{x^3*E^(a + b*x - c*x^2), x, 13, -((b^2*E^(a + b*x - c*x^2))/(8*c^3)) - E^(a + b*x - c*x^2)/(2*c^2) - (b*E^(a + b*x - c*x^2)*x)/(4*c^2) - (E^(a + b*x - c*x^2)*x^2)/(2*c) - (b*(b^2 + 6*c)*E^(a + b^2/(4*c))*Sqrt[Pi]*Erf[(b - 2*c*x)/(2*Sqrt[c])])/(16*c^(7/2))}
{x^2*E^(a + b*x - c*x^2), x, 8, -((b*E^(a + b*x - c*x^2))/(4*c^2)) - (E^(a + b*x - c*x^2)*x)/(2*c) - ((b^2 + 2*c)*E^(a + b^2/(4*c))*Sqrt[Pi]*Erf[(b - 2*c*x)/(2*Sqrt[c])])/(8*c^(5/2))}
{x*E^(a + b*x - c*x^2), x, 4, -(E^(a + b*x - c*x^2)/(2*c)) - (b*E^(a + b^2/(4*c))*Sqrt[Pi]*Erf[(b - 2*c*x)/(2*Sqrt[c])])/(4*c^(3/2))}
{E^(a + b*x - c*x^2), x, 3, -((E^(a + b^2/(4*c))*Sqrt[Pi]*Erf[(b - 2*c*x)/(2*Sqrt[c])])/(2*Sqrt[c]))}
{E^(a + b*x - c*x^2)/x, x, 1, E^a*Int[E^(b*x - c*x^2)/x, x]}
{E^(a + b*x - c*x^2)/x^2, x, 5, -(E^(a + b*x - c*x^2)/x) + Sqrt[c]*E^(a + b^2/(4*c))*Sqrt[Pi]*Erf[(b - 2*c*x)/(2*Sqrt[c])] + b*E^a*Int[E^(b*x - c*x^2)/x, x]}


(* Integrands of the form x^m*E^((a+b*x)*(c+d*x)) where m is an integer *)
{x^3*E^((a + b*x)*(c + d*x)), x, 14, -(E^(a*c + (b*c + a*d)*x + b*d*x^2)/(2*b^2*d^2)) + ((b*c + a*d)^2*E^(a*c + (b*c + a*d)*x + b*d*x^2))/(8*b^3*d^3) - ((b*c + a*d)*E^(a*c + (b*c + a*d)*x + b*d*x^2)*x)/(4*b^2*d^2) + (E^(a*c + (b*c + a*d)*x + b*d*x^2)*x^2)/(2*b*d) - ((b^3*c^3 - 3*b^2*c*(2 - a*c)*d - 3*a*b*(2 - a*c)*d^2 + a^3*d^3)*Sqrt[Pi]*Erfi[(b*c + a*d + 2*b*d*x)/(2*Sqrt[b]*Sqrt[d])])/(E^((b*c - a*d)^2/(4*b*d))*(16*b^(7/2)*d^(7/2)))}
{x^2*E^((a + b*x)*(c + d*x)), x, 9, -(((b*c + a*d)*E^(a*c + (b*c + a*d)*x + b*d*x^2))/(4*b^2*d^2)) + (E^(a*c + (b*c + a*d)*x + b*d*x^2)*x)/(2*b*d) + ((b^2*c^2 - 2*b*(1 - a*c)*d + a^2*d^2)*Sqrt[Pi]*Erfi[(b*c + a*d + 2*b*d*x)/(2*Sqrt[b]*Sqrt[d])])/(E^((b*c - a*d)^2/(4*b*d))*(8*b^(5/2)*d^(5/2)))}
{x*E^((a + b*x)*(c + d*x)), x, 5, E^(a*c + (b*c + a*d)*x + b*d*x^2)/(2*b*d) - ((b*c + a*d)*E^(a*c - (b*c + a*d)^2/(4*b*d))*Sqrt[Pi]*Erfi[(b*c + a*d + 2*b*d*x)/(2*Sqrt[b]*Sqrt[d])])/(4*b^(3/2)*d^(3/2))}
{E^((a + b*x)*(c + d*x)), x, 4, (E^(a*c - (b*c + a*d)^2/(4*b*d))*Sqrt[Pi]*Erfi[(b*c + a*d + 2*b*d*x)/(2*Sqrt[b]*Sqrt[d])])/(2*Sqrt[b]*Sqrt[d])}
{E^((a + b*x)*(c + d*x))/x, x, 2, E^(a*c)*Int[E^((b*c + a*d)*x + b*d*x^2)/x, x]}
{E^((a + b*x)*(c + d*x))/x^2, x, 6, -(E^(a*c + (b*c + a*d)*x + b*d*x^2)/x) + Sqrt[b]*Sqrt[d]*E^(a*c - (b*c + a*d)^2/(4*b*d))*Sqrt[Pi]*Erfi[(b*c + a*d + 2*b*d*x)/(2*Sqrt[b]*Sqrt[d])] + (b*c + a*d)*E^(a*c)*Int[E^((b*c + a*d)*x + b*d*x^2)/x, x]}


(* Integrands of the form x^m*f^(a+b*x+c*x^2) where m is an integer *)
{x^3*f^(a + b*x + c*x^2), x, 13, -(f^(a + b*x + c*x^2)/(2*c^2*Log[f]^2)) + (b^2*f^(a + b*x + c*x^2))/(8*c^3*Log[f]) - (b*f^(a + b*x + c*x^2)*x)/(4*c^2*Log[f]) + (f^(a + b*x + c*x^2)*x^2)/(2*c*Log[f]) + (b*f^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[((b + 2*c*x)*Sqrt[Log[f]])/(2*Sqrt[c])]*(6*c - b^2*Log[f]))/(16*c^(7/2)*Log[f]^(3/2))}
{x^2*f^(a + b*x + c*x^2), x, 8, -((b*f^(a + b*x + c*x^2))/(4*c^2*Log[f])) + (f^(a + b*x + c*x^2)*x)/(2*c*Log[f]) - (f^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[((b + 2*c*x)*Sqrt[Log[f]])/(2*Sqrt[c])]*(2*c - b^2*Log[f]))/(8*c^(5/2)*Log[f]^(3/2))}
{x*f^(a + b*x + c*x^2), x, 4, f^(a + b*x + c*x^2)/(2*c*Log[f]) - (b*f^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[((b + 2*c*x)*Sqrt[Log[f]])/(2*Sqrt[c])])/(4*c^(3/2)*Sqrt[Log[f]])}
{f^(a + b*x + c*x^2), x, 3, (f^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[((b + 2*c*x)*Sqrt[Log[f]])/(2*Sqrt[c])])/(2*Sqrt[c]*Sqrt[Log[f]])}
{f^(a + b*x + c*x^2)/x, x, 1, f^a*Int[f^(b*x + c*x^2)/x, x]}
{f^(a + b*x + c*x^2)/x^2, x, 5, -(f^(a + b*x + c*x^2)/x) + Sqrt[c]*f^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[((b + 2*c*x)*Sqrt[Log[f]])/(2*Sqrt[c])]*Sqrt[Log[f]] + b*f^a*Int[f^(b*x + c*x^2)/x, x]*Log[f]}


(* Integrands of the form (d+e*x)^m*f^(a+b*x+c*x^2) where m is an integer *)
{(d + e*x)^3*f^(a + b*x + c*x^2), x, 13, -((e^3*f^(a + b*x + c*x^2))/(2*c^2*Log[f]^2)) + (e*(2*c*d - b*e)^2*f^(a + b*x + c*x^2))/(8*c^3*Log[f]) + (e*(2*c*d - b*e)*f^(a + b*x + c*x^2)*(d + e*x))/(4*c^2*Log[f]) + (e*f^(a + b*x + c*x^2)*(d + e*x)^2)/(2*c*Log[f]) - ((2*c*d - b*e)*f^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[((b + 2*c*x)*Sqrt[Log[f]])/(2*Sqrt[c])]*(6*c*e^2 - (2*c*d - b*e)^2*Log[f]))/(16*c^(7/2)*Log[f]^(3/2))}
{(d + e*x)^2*f^(a + b*x + c*x^2), x, 8, (e*(4*c*d - b*e)*f^(a + b*x + c*x^2))/(4*c^2*Log[f]) + (e^2*f^(a + b*x + c*x^2)*x)/(2*c*Log[f]) - (f^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[((b + 2*c*x)*Sqrt[Log[f]])/(2*Sqrt[c])]*(2*c*e^2 - (2*c*d - b*e)^2*Log[f]))/(8*c^(5/2)*Log[f]^(3/2))}
{(d + e*x)*f^(a + b*x + c*x^2), x, 4, (e*f^(a + b*x + c*x^2))/(2*c*Log[f]) + ((2*c*d - b*e)*f^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[((b + 2*c*x)*Sqrt[Log[f]])/(2*Sqrt[c])])/(4*c^(3/2)*Sqrt[Log[f]])}
{f^(a + b*x + c*x^2)/(d + e*x), x, 1, f^a*Int[f^(b*x + c*x^2)/(d + e*x), x]}
{f^(a + b*x + c*x^2)/(d + e*x)^2, x, 5, -(f^(a + b*x + c*x^2)/(e*(d + e*x))) + (Sqrt[c]*f^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[((b + 2*c*x)*Sqrt[Log[f]])/(2*Sqrt[c])]*Sqrt[Log[f]])/e^2 - ((2*c*d - b*e)*f^a*Int[f^(b*x + c*x^2)/(d + e*x), x]*Log[f])/e^2}
{f^(a + b*x + c*x^2)/(d + e*x)^3, x, 7, -(f^(a + b*x + c*x^2)/(2*e*(d + e*x)^2)) + ((2*c*d - b*e)*f^(a + b*x + c*x^2)*Log[f])/(2*e^3*(d + e*x)) - (Sqrt[c]*(2*c*d - b*e)*f^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[((b + 2*c*x)*Sqrt[Log[f]])/(2*Sqrt[c])]*Log[f]^(3/2))/(2*e^4) + (f^a*Int[f^(b*x + c*x^2)/(d + e*x), x]*Log[f]*(2*c*e^2 + (2*c*d - b*e)^2*Log[f]))/(2*e^4)}


(* Integrands of the form (b+2*c*x)^m*f^(a+b*x+c*x^2) where m is an integer *)
{(b + 2*c*x)^3*f^(a + b*x + c*x^2), x, 3, -((4*c*f^(a + b*x + c*x^2))/Log[f]^2) + (f^(a + b*x + c*x^2)*(b + 2*c*x)^2)/Log[f]}
{(b + 2*c*x)^2*f^(a + b*x + c*x^2), x, 4, -((Sqrt[c]*f^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[((b + 2*c*x)*Sqrt[Log[f]])/(2*Sqrt[c])])/Log[f]^(3/2)) + (f^(a + b*x + c*x^2)*(b + 2*c*x))/Log[f]}
{(b + 2*c*x)*f^(a + b*x + c*x^2), x, 2, f^(a + b*x + c*x^2)/Log[f]}
{f^(a + b*x + c*x^2)/(b + 2*c*x), x, 1, f^a*Int[f^(b*x + c*x^2)/(b + 2*c*x), x]}
{f^(a + b*x + c*x^2)/(b + 2*c*x)^2, x, 4, -(f^(a + b*x + c*x^2)/(2*c*(b + 2*c*x))) + (f^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[((b + 2*c*x)*Sqrt[Log[f]])/(2*Sqrt[c])]*Sqrt[Log[f]])/(4*c^(3/2))}
{f^(a + b*x + c*x^2)/(b + 2*c*x)^3, x, 2, -(f^(a + b*x + c*x^2)/(4*c*(b + 2*c*x)^2)) + (f^a*Int[f^(b*x + c*x^2)/(b + 2*c*x), x]*Log[f])/(4*c)}


(* Integrands of the form (b+2*c*x)^m*f^(b*x+c*x^2) where m is an integer *)
{(b + 2*c*x)^3*f^(b*x + c*x^2), x, 3, -((4*c*f^(b*x + c*x^2))/Log[f]^2) + (f^(b*x + c*x^2)*(b + 2*c*x)^2)/Log[f]}
{(b + 2*c*x)^2*f^(b*x + c*x^2), x, 4, -((Sqrt[c]*Sqrt[Pi]*Erfi[((b + 2*c*x)*Sqrt[Log[f]])/(2*Sqrt[c])])/(f^(b^2/(4*c))*Log[f]^(3/2))) + (f^(b*x + c*x^2)*(b + 2*c*x))/Log[f]}
{(b + 2*c*x)*f^(b*x + c*x^2), x, 2, f^(b*x + c*x^2)/Log[f]}
{f^(b*x + c*x^2)/(b + 2*c*x), x, 0, Int[f^(b*x + c*x^2)/(b + 2*c*x), x]}
{f^(b*x + c*x^2)/(b + 2*c*x)^2, x, 4, -(f^(b*x + c*x^2)/(2*c*(b + 2*c*x))) + (Sqrt[Pi]*Erfi[((b + 2*c*x)*Sqrt[Log[f]])/(2*Sqrt[c])]*Sqrt[Log[f]])/(f^(b^2/(4*c))*(4*c^(3/2)))}
{f^(b*x + c*x^2)/(b + 2*c*x)^3, x, 1, -(f^(b*x + c*x^2)/(4*c*(b + 2*c*x)^2)) + (Int[f^(b*x + c*x^2)/(b + 2*c*x), x]*Log[f])/(4*c)}


(* ::Section::Closed:: *)
(*Integrands involving two exponential functions*)


(* ::Subsection::Closed:: *)
(*Integrands of the form f^x / (a+b g^x)*)


{4^x/(a + b*2^x), x, 4, 2^x/(b*Log[2]) - (a*Log[a + 2^x*b])/(b^2*Log[2])}
{2^(2*x)/(a + b*2^x), x, 4, 2^x/(b*Log[2]) - (a*Log[a + 2^x*b])/(b^2*Log[2])}

{4^x/(a - b*2^x), x, 4, -(2^x/(b*Log[2])) - (a*Log[-a + 2^x*b])/(b^2*Log[2])}
{2^(2*x)/(a - b*2^x), x, 4, -(2^x/(b*Log[2])) - (a*Log[a - 2^x*b])/(b^2*Log[2])}


{4^x/(a + b/2^x), x, 5, -((2^x*b)/(a^2*Log[2])) + 4^x/(a*Log[4]) + (b^2*Log[2^x*a + b])/(a^3*Log[2])}
{2^(2*x)/(a + b/2^x), x, 5, 2^(-1 + 2*x)/(a*Log[2]) - (2^x*b)/(a^2*Log[2]) + (b^2*Log[2^x*a + b])/(a^3*Log[2])}

{4^x/(a - b/2^x), x, 5, (2^x*b)/(a^2*Log[2]) + 4^x/(a*Log[4]) + (b^2*Log[2^x*a - b])/(a^3*Log[2])}
{2^(2*x)/(a - b/2^x), x, 5, 2^(-1 + 2*x)/(a*Log[2]) + (2^x*b)/(a^2*Log[2]) + (b^2*Log[(-2^x)*a + b])/(a^3*Log[2])}


{2^x/(a + b*4^x), x, 3, ArcTan[(2^x*Sqrt[b])/Sqrt[a]]/(Sqrt[a]*Sqrt[b]*Log[2])}
{2^x/(a + b*2^(2*x)), x, 2, ArcTan[(2^x*Sqrt[b])/Sqrt[a]]/(Sqrt[a]*Sqrt[b]*Log[2])}

{2^x/(a - b*4^x), x, 3, ArcTanh[(2^x*Sqrt[b])/Sqrt[a]]/(Sqrt[a]*Sqrt[b]*Log[2])}
{2^x/(a - b*2^(2*x)), x, 2, ArcTanh[(2^x*Sqrt[b])/Sqrt[a]]/(Sqrt[a]*Sqrt[b]*Log[2])}


{2^x/(a + b/4^x), x, 6, 2^x/(a*Log[2]) - (Sqrt[b]*ArcTan[(2^x*Sqrt[a])/Sqrt[b]])/(a^(3/2)*Log[2])}
{2^x/(a + b/2^(2*x)), x, 4, 2^x/(a*Log[2]) - (Sqrt[b]*ArcTan[(2^x*Sqrt[a])/Sqrt[b]])/(a^(3/2)*Log[2])}

{2^x/(a - b/4^x), x, 6, 2^x/(a*Log[2]) - (Sqrt[b]*ArcTanh[(2^x*Sqrt[a])/Sqrt[b]])/(a^(3/2)*Log[2])}
{2^x/(a - b/2^(2*x)), x, 4, 2^x/(a*Log[2]) - (Sqrt[b]*ArcTanh[(2^x*Sqrt[a])/Sqrt[b]])/(a^(3/2)*Log[2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form f^x / Sqrt[a+b g^x]*)


(* Contributed by Robert Israel in sci.math.symbolic *)
{2^x/Sqrt[a + b*4^x], x, 3, ArcTanh[(2^x*Sqrt[b])/Sqrt[a + 2^(2*x)*b]]/(Sqrt[b]*Log[2])}
{2^x/Sqrt[a + b*2^(2*x)], x, 2, ArcTanh[(2^x*Sqrt[b])/Sqrt[a + 2^(2*x)*b]]/(Sqrt[b]*Log[2])}

{2^x/Sqrt[a - b*4^x], x, 3, ArcTan[(2^x*Sqrt[b])/Sqrt[a - 2^(2*x)*b]]/(Sqrt[b]*Log[2])}
{2^x/Sqrt[a - b*2^(2*x)], x, 2, ArcTan[(2^x*Sqrt[b])/Sqrt[a - 2^(2*x)*b]]/(Sqrt[b]*Log[2])}


{2^x/Sqrt[a + b/4^x], x, 3, (2^x*Sqrt[a + b/2^(2*x)])/(a*Log[2])}
{2^x/Sqrt[a + b/2^(2*x)], x, 2, (2^x*Sqrt[a + b/2^(2*x)])/(a*Log[2])}

{2^x/Sqrt[a - b/4^x], x, 3, (2^x*Sqrt[a - b/2^(2*x)])/(a*Log[2])}
{2^x/Sqrt[a - b/2^(2*x)], x, 2, (2^x*Sqrt[a - b/2^(2*x)])/(a*Log[2])}


{4^x/Sqrt[a + b*2^x], x, 4, -((4*a*Sqrt[a + 2^x*b])/(3*b^2*Log[2])) + (2^(1 + x)*Sqrt[a + 2^x*b])/(3*b*Log[2])}
{2^(2*x)/Sqrt[a + b*2^x], x, 3, -((4*a*Sqrt[a + 2^x*b])/(3*b^2*Log[2])) + (2^(1 + x)*Sqrt[a + 2^x*b])/(3*b*Log[2])}

{4^x/Sqrt[a - b*2^x], x, 4, -((4*a*Sqrt[a - 2^x*b])/(3*b^2*Log[2])) - (2^(1 + x)*Sqrt[a - 2^x*b])/(3*b*Log[2])}
{2^(2*x)/Sqrt[a - b*2^x], x, 3, -((4*a*Sqrt[a - 2^x*b])/(3*b^2*Log[2])) - (2^(1 + x)*Sqrt[a - 2^x*b])/(3*b*Log[2])}


{4^x/Sqrt[a + b/2^x], x, 5, (2^(-1 + 2*x)*Sqrt[a + b/2^x])/(a*Log[2]) - (3*2^(-2 + x)*b*Sqrt[a + b/2^x])/(a^2*Log[2]) + (3*b^2*ArcTanh[Sqrt[a + b/2^x]/Sqrt[a]])/(4*a^(5/2)*Log[2])}
{2^(2*x)/Sqrt[a + b/2^x], x, 4, (2^(-1 + 2*x)*Sqrt[a + b/2^x])/(a*Log[2]) - (3*2^(-2 + x)*b*Sqrt[a + b/2^x])/(a^2*Log[2]) + (3*b^2*ArcTanh[Sqrt[a + b/2^x]/Sqrt[a]])/(4*a^(5/2)*Log[2])}

{4^x/Sqrt[a - b/2^x], x, 5, (2^(-1 + 2*x)*Sqrt[a - b/2^x])/(a*Log[2]) + (3*2^(-2 + x)*b*Sqrt[a - b/2^x])/(a^2*Log[2]) + (3*b^2*ArcTanh[Sqrt[a - b/2^x]/Sqrt[a]])/(4*a^(5/2)*Log[2])}
{2^(2*x)/Sqrt[a - b/2^x], x, 4, (2^(-1 + 2*x)*Sqrt[a - b/2^x])/(a*Log[2]) + (3*2^(-2 + x)*b*Sqrt[a - b/2^x])/(a^2*Log[2]) + (3*b^2*ArcTanh[Sqrt[a - b/2^x]/Sqrt[a]])/(4*a^(5/2)*Log[2])}


(* ::Subsection::Closed:: *)
(*Integrands involving products of exponentials*)


(* Integrands of the form x^m*a^x*b^x where m is an integer *)
{x^2*a^x*b^x, x, 4, (2*a^x*b^x)/(Log[a] + Log[b])^3 - (2*a^x*b^x*x)/(Log[a] + Log[b])^2 + (a^x*b^x*x^2)/(Log[a] + Log[b])}
{x*a^x*b^x, x, 3, -((a^x*b^x)/(Log[a] + Log[b])^2) + (a^x*b^x*x)/(Log[a] + Log[b])}
{a^x*b^x, x, 2, (a^x*b^x)/(Log[a] + Log[b])}
{a^x*b^x/x, x, 2, ExpIntegralEi[x*(Log[a] + Log[b])]}
{a^x*b^x/x^2, x, 3, -((a^x*b^x)/x) + ExpIntegralEi[x*(Log[a] + Log[b])]*(Log[a] + Log[b])}
{a^x*b^x/x^3, x, 4, -((a^x*b^x)/(2*x^2)) - (a^x*b^x*(Log[a] + Log[b]))/(2*x) + (1/2)*ExpIntegralEi[x*(Log[a] + Log[b])]*(Log[a] + Log[b])^2}


{a^x*b^x*c^x, x, 2, (a^x*b^x*c^x)/(Log[a] + Log[b] + Log[c])}
{a^x/b^x, x, 2, a^x/(b^x*(Log[a] - Log[b]))}

{(a^x*x^2)/b^x, x, 4, (2*a^x)/(b^x*(Log[a] - Log[b])^3) - (2*a^x*x)/(b^x*(Log[a] - Log[b])^2) + (a^x*x^2)/(b^x*(Log[a] - Log[b]))}


{E^(a + b*x^n)*E^(c + d*x^n), x, 2, -((E^(a + c)*x*Gamma[1/n, -((b + d)*x^n)])/((-((b + d)*x^n))^n^(-1)*n))}
{f^(a + b*x^n)*g^(c + d*x^n), x, 2, -((f^a*g^c*x*Gamma[1/n, (-x^n)*(b*Log[f] + d*Log[g])])/(((-x^n)*(b*Log[f] + d*Log[g]))^n^(-1)*n))}


(* ::Subsection::Closed:: *)
(*Integrands involving binomials of exponentials of linears*)


(* Integrands of the form E^(2*n*x)/(a+b*E^(n*x))^m where m is an integer *)
{E^(2*x)/(a + b*E^x), x, 4, E^x/b - (a*Log[a + b*E^x])/b^2}
{E^(2*x)/(a + b*E^x)^2, x, 5, a/(b^2*(a + b*E^x)) + Log[a + b*E^x]/b^2}
{E^(2*x)/(a + b*E^x)^3, x, 2, E^(2*x)/(2*a*(a + b*E^x)^2)}
{E^(2*x)/(a + b*E^x)^4, x, 5, a/(3*b^2*(a + b*E^x)^3) - 1/(2*b^2*(a + b*E^x)^2)}

{E^(4*x)/(a + b*E^(2*x)), x, 4, E^(2*x)/(2*b) - (a*Log[a + b*E^(2*x)])/(2*b^2)}
{E^(4*x)/(a + b*E^(2*x))^2, x, 5, a/(2*b^2*(a + b*E^(2*x))) + Log[a + b*E^(2*x)]/(2*b^2)}
{E^(4*x)/(a + b*E^(2*x))^3, x, 2, E^(4*x)/(4*a*(a + b*E^(2*x))^2)}
{E^(4*x)/(a + b*E^(2*x))^4, x, 5, a/(6*b^2*(a + b*E^(2*x))^3) - 1/(4*b^2*(a + b*E^(2*x))^2)}

{E^(4*x)/(a + b*E^(2*x))^(2/3), x, 3, -((9*a*(a + b*E^(2*x))^(1/3))/(8*b^2)) + (3*E^(2*x)*(a + b*E^(2*x))^(1/3))/(8*b)}


(* Integrands of the form E^(-n*x)*(a+b*E^(n*x))^m where m is an integer *)
{E^(-n*x)*(a + b*E^(n*x)), x, 3, -(a/(E^(n*x)*n)) + b*x}
{E^(-n*x)*(a + b*E^(n*x))^2, x, 4, -(a^2/(E^(n*x)*n)) + (b^2*E^(n*x))/n + 2*a*b*x}
{E^(-n*x)*(a + b*E^(n*x))^3, x, 5, -(a^3/(E^(n*x)*n)) + (3*a*b^2*E^(n*x))/n + (b^3*E^(2*n*x))/(2*n) + 3*a^2*b*x}

{E^(-n*x)/(a + b*E^(n*x)), x, 4, -(1/(E^(n*x)*(a*n))) + (b*Log[b + a/E^(n*x)])/(a^2*n)}
{E^(-n*x)/(a + b*E^(n*x))^2, x, 5, -(1/(E^(n*x)*(a^2*n))) + b^2/(a^3*(b + a/E^(n*x))*n) + (2*b*Log[b + a/E^(n*x)])/(a^3*n)}
{E^(-n*x)/(a + b*E^(n*x))^3, x, 6, -(1/(E^(n*x)*(a^3*n))) - b^3/(2*a^4*(b + a/E^(n*x))^2*n) + (3*b^2)/(a^4*(b + a/E^(n*x))*n) + (3*b*Log[b + a/E^(n*x)])/(a^4*n)}


(* Integrands of the form f^(a+n*b*x)/(c+d*f^(e+2*b*x)) where n is an integer *)
{f^(a + b*x)/(c + d*f^(e + 2*b*x)), x, 2, (f^(a - e/2)*ArcTan[(Sqrt[d]*f^(e/2 + b*x))/Sqrt[c]])/(b*Sqrt[c]*Sqrt[d]*Log[f]), (Sqrt[f^(2*a - e)]*ArcTan[(Sqrt[d]*f^(a + b*x))/(Sqrt[c]*Sqrt[f^(2*a - e)])])/(b*Sqrt[c]*Sqrt[d]*Log[f])}
{f^(a + 2*b*x)/(c + d*f^(e + 2*b*x)), x, 2, (f^(a - e)*Log[c + d*f^(e + 2*b*x)])/(2*b*d*Log[f])}
{f^(a + 3*b*x)/(c + d*f^(e + 2*b*x)), x, 5, f^(a - e + b*x)/(b*d*Log[f]) - (Sqrt[c]*f^a*(f^(-e))^(3/2)*ArcTan[(Sqrt[d]*f^(b*x))/(Sqrt[c]*Sqrt[f^(-e)])])/(b*d^(3/2)*Log[f])}
{f^(a + 4*b*x)/(c + d*f^(e + 2*b*x)), x, 5, f^(a - e + 2*b*x)/(2*b*d*Log[f]) - (c*f^(a - 2*e)*Log[c + d*f^(e + 2*b*x)])/(2*b*d^2*Log[f])}
{f^(a + 5*b*x)/(c + d*f^(e + 2*b*x)), x, 6, -((c*f^(a - 2*e + b*x))/(b*d^2*Log[f])) + f^(a - e + 3*b*x)/(3*b*d*Log[f]) + (c^(3/2)*f^(a - 2*e)*Sqrt[f^(-e)]*ArcTan[(Sqrt[d]*f^(b*x))/(Sqrt[c]*Sqrt[f^(-e)])])/(b*d^(5/2)*Log[f])}


(* Integrands of the form f^(c+d*x)*(a+b*f^(c+d*x))^n *)
{E^x/(4 + 6*E^x), x, 3, (1/6)*Log[2 + 3*E^x]}
{E^x/(a + b*E^x), x, 2, Log[a + b*E^x]/b}
{E^(d*x)/(a + b*E^(c + d*x)), x, 2, Log[a + b*E^(c + d*x)]/(E^c*(b*d))}
{E^(c + d*x)/(a + b*E^(c + d*x)), x, 2, Log[a + b*E^(c + d*x)]/(b*d)}

{E^x*(a + b*E^x)^n, x, 2, (a + b*E^x)^(1 + n)/(b*(1 + n))}
{E^(d*x)*(a + b*E^(c + d*x))^n, x, 2, (a + b*E^(c + d*x))^(1 + n)/(E^c*(b*d*(1 + n)))}
{E^(c + d*x)*(a + b*E^(c + d*x))^n, x, 2, (a + b*E^(c + d*x))^(1 + n)/(b*d*(1 + n))}

{f^x/(a + b*f^x), x, 2, Log[a + b*f^x]/(b*Log[f])}
{f^(d*x)/(a + b*f^(c + d*x)), x, 2, Log[a + b*f^(c + d*x)]/(f^c*(b*d*Log[f]))}
{f^(c + d*x)/(a + b*f^(c + d*x)), x, 2, Log[a + b*f^(c + d*x)]/(b*d*Log[f])}

{f^x*(a + b*f^x)^n, x, 2, (a + b*f^x)^(1 + n)/(b*(1 + n)*Log[f])}
{f^(d*x)*(a + b*f^(c + d*x))^n, x, 2, (a + b*f^(c + d*x))^(1 + n)/(f^c*(b*d*(1 + n)*Log[f]))}
{f^(c + d*x)*(a + b*f^(c + d*x))^n, x, 2, (a + b*f^(c + d*x))^(1 + n)/(b*d*(1 + n)*Log[f])}


(* Integrands of the form x^m*f^x/(a+b*f^x)^n where m and n are integers *)
{x*E^x/(1 + E^x), x, 2, x*Log[1 + E^x] + PolyLog[2, -E^x]}
{x*E^x/(1 + E^x)^2, x, 2, (E^x*x)/(1 + E^x) - Log[1 + E^x]}
{x*E^x/(1 + E^x)^3, x, 3, 1/(2*(1 + E^x)) + x/2 - x/(2*(1 + E^x)^2) - (1/2)*Log[1 + E^x]}


{x^0*E^x/(1 - E^(2*x)), x, 2, ArcTanh[E^x]}
{x^1*E^x/(1 - E^(2*x)), x, 4, x*ArcTanh[E^x] + (1/2)*PolyLog[2, -E^x] - (1/2)*PolyLog[2, E^x]}
{x^2*E^x/(1 - E^(2*x)), x, 6, x^2*ArcTanh[E^x] + x*PolyLog[2, -E^x] - x*PolyLog[2, E^x] - PolyLog[3, -E^x] + PolyLog[3, E^x]}
{x^3*E^x/(1 - E^(2*x)), x, 8, x^3*ArcTanh[E^x] + (3/2)*x^2*PolyLog[2, -E^x] - (3/2)*x^2*PolyLog[2, E^x] - 3*x*PolyLog[3, -E^x] + 3*x*PolyLog[3, E^x] + 3*PolyLog[4, -E^x] - 3*PolyLog[4, E^x]}


{x^0*f^x/(a + b*f^(2*x)), x, 2, ArcTan[(Sqrt[b]*f^x)/Sqrt[a]]/(Sqrt[a]*Sqrt[b]*Log[f])}
{x^1*f^x/(a + b*f^(2*x)), x, 5, (x*ArcTan[(Sqrt[b]*f^x)/Sqrt[a]])/(Sqrt[a]*Sqrt[b]*Log[f]) - (I*PolyLog[2, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(2*Sqrt[a]*Sqrt[b]*Log[f]^2) + (I*PolyLog[2, (I*Sqrt[b]*f^x)/Sqrt[a]])/(2*Sqrt[a]*Sqrt[b]*Log[f]^2)}
{x^2*f^x/(a + b*f^(2*x)), x, 7, (x^2*ArcTan[(Sqrt[b]*f^x)/Sqrt[a]])/(Sqrt[a]*Sqrt[b]*Log[f]) - (I*x*PolyLog[2, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(Sqrt[a]*Sqrt[b]*Log[f]^2) + (I*x*PolyLog[2, (I*Sqrt[b]*f^x)/Sqrt[a]])/(Sqrt[a]*Sqrt[b]*Log[f]^2) + (I*PolyLog[3, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(Sqrt[a]*Sqrt[b]*Log[f]^3) - (I*PolyLog[3, (I*Sqrt[b]*f^x)/Sqrt[a]])/(Sqrt[a]*Sqrt[b]*Log[f]^3)}
{x^3*f^x/(a + b*f^(2*x)), x, 9, (x^3*ArcTan[(Sqrt[b]*f^x)/Sqrt[a]])/(Sqrt[a]*Sqrt[b]*Log[f]) - (3*I*x^2*PolyLog[2, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(2*Sqrt[a]*Sqrt[b]*Log[f]^2) + (3*I*x^2*PolyLog[2, (I*Sqrt[b]*f^x)/Sqrt[a]])/(2*Sqrt[a]*Sqrt[b]*Log[f]^2) + (3*I*x*PolyLog[3, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(Sqrt[a]*Sqrt[b]*Log[f]^3) - (3*I*x*PolyLog[3, (I*Sqrt[b]*f^x)/Sqrt[a]])/(Sqrt[a]*Sqrt[b]*Log[f]^3) - (3*I*PolyLog[4, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(Sqrt[a]*Sqrt[b]*Log[f]^4) + (3*I*PolyLog[4, (I*Sqrt[b]*f^x)/Sqrt[a]])/(Sqrt[a]*Sqrt[b]*Log[f]^4)}


{x^0*f^x/(a + b*f^(2*x))^2, x, 3, f^x/(2*a*(a + b*f^(2*x))*Log[f]) + ArcTan[(Sqrt[b]*f^x)/Sqrt[a]]/(2*a^(3/2)*Sqrt[b]*Log[f])}
{x^1*f^x/(a + b*f^(2*x))^2, x, 7, -(ArcTan[(Sqrt[b]*f^x)/Sqrt[a]]/(2*a^(3/2)*Sqrt[b]*Log[f]^2)) + (x*((Sqrt[a]*f^x)/(a + b*f^(2*x)) + ArcTan[(Sqrt[b]*f^x)/Sqrt[a]]/Sqrt[b]))/(2*a^(3/2)*Log[f]) - (I*PolyLog[2, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(4*a^(3/2)*Sqrt[b]*Log[f]^2) + (I*PolyLog[2, (I*Sqrt[b]*f^x)/Sqrt[a]])/(4*a^(3/2)*Sqrt[b]*Log[f]^2)}
{x^2*f^x/(a + b*f^(2*x))^2, x, 13, -((x*ArcTan[(Sqrt[b]*f^x)/Sqrt[a]])/(a^(3/2)*Sqrt[b]*Log[f]^2)) + (x^2*((Sqrt[a]*f^x)/(a + b*f^(2*x)) + ArcTan[(Sqrt[b]*f^x)/Sqrt[a]]/Sqrt[b]))/(2*a^(3/2)*Log[f]) + (I*(1 - x*Log[f])*PolyLog[2, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(2*a^(3/2)*Sqrt[b]*Log[f]^3) - (I*(1 - x*Log[f])*PolyLog[2, (I*Sqrt[b]*f^x)/Sqrt[a]])/(2*a^(3/2)*Sqrt[b]*Log[f]^3) + (I*PolyLog[3, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(2*a^(3/2)*Sqrt[b]*Log[f]^3) - (I*PolyLog[3, (I*Sqrt[b]*f^x)/Sqrt[a]])/(2*a^(3/2)*Sqrt[b]*Log[f]^3)}
{x^3*f^x/(a + b*f^(2*x))^2, x, 17, -((3*x^2*ArcTan[(Sqrt[b]*f^x)/Sqrt[a]])/(2*a^(3/2)*Sqrt[b]*Log[f]^2)) + (x^3*((Sqrt[a]*f^x)/(a + b*f^(2*x)) + ArcTan[(Sqrt[b]*f^x)/Sqrt[a]]/Sqrt[b]))/(2*a^(3/2)*Log[f]) + (3*I*x*(2 - x*Log[f])*PolyLog[2, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(4*a^(3/2)*Sqrt[b]*Log[f]^3) - (3*I*x*(2 - x*Log[f])*PolyLog[2, (I*Sqrt[b]*f^x)/Sqrt[a]])/(4*a^(3/2)*Sqrt[b]*Log[f]^3) - (3*I*(1 - x*Log[f])*PolyLog[3, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(2*a^(3/2)*Sqrt[b]*Log[f]^4) + (3*I*(1 - x*Log[f])*PolyLog[3, (I*Sqrt[b]*f^x)/Sqrt[a]])/(2*a^(3/2)*Sqrt[b]*Log[f]^4) - (3*I*PolyLog[4, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(2*a^(3/2)*Sqrt[b]*Log[f]^4) + (3*I*PolyLog[4, (I*Sqrt[b]*f^x)/Sqrt[a]])/(2*a^(3/2)*Sqrt[b]*Log[f]^4)}


{x^0*f^x/(a + b*f^(2*x))^3, x, 4, f^x/(4*a*(a + b*f^(2*x))^2*Log[f]) + (3*f^x)/(8*a^2*(a + b*f^(2*x))*Log[f]) + (3*ArcTan[(Sqrt[b]*f^x)/Sqrt[a]])/(8*a^(5/2)*Sqrt[b]*Log[f])}
{x^1*f^x/(a + b*f^(2*x))^3, x, 10, -(f^x/(8*a^2*(a + b*f^(2*x))*Log[f]^2)) - ArcTan[(Sqrt[b]*f^x)/Sqrt[a]]/(2*a^(5/2)*Sqrt[b]*Log[f]^2) + (x*((2*a^(3/2)*f^x)/(a + b*f^(2*x))^2 + (3*Sqrt[a]*f^x)/(a + b*f^(2*x)) + (3*ArcTan[(Sqrt[b]*f^x)/Sqrt[a]])/Sqrt[b]))/(8*a^(5/2)*Log[f]) - (3*I*PolyLog[2, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(16*a^(5/2)*Sqrt[b]*Log[f]^2) + (3*I*PolyLog[2, (I*Sqrt[b]*f^x)/Sqrt[a]])/(16*a^(5/2)*Sqrt[b]*Log[f]^2)}
{x^2*f^x/(a + b*f^(2*x))^3, x, 20, ArcTan[(Sqrt[b]*f^x)/Sqrt[a]]/(4*a^(5/2)*Sqrt[b]*Log[f]^3) - (f^x*x)/(4*a^2*(a + b*f^(2*x))*Log[f]^2) - (x*ArcTan[(Sqrt[b]*f^x)/Sqrt[a]])/(a^(5/2)*Sqrt[b]*Log[f]^2) + (x^2*((2*a^(3/2)*f^x)/(a + b*f^(2*x))^2 + (3*Sqrt[a]*f^x)/(a + b*f^(2*x)) + (3*ArcTan[(Sqrt[b]*f^x)/Sqrt[a]])/Sqrt[b]))/(8*a^(5/2)*Log[f]) + (I*(4 - 3*x*Log[f])*PolyLog[2, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(8*a^(5/2)*Sqrt[b]*Log[f]^3) - (I*(4 - 3*x*Log[f])*PolyLog[2, (I*Sqrt[b]*f^x)/Sqrt[a]])/(8*a^(5/2)*Sqrt[b]*Log[f]^3) + (3*I*PolyLog[3, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(8*a^(5/2)*Sqrt[b]*Log[f]^3) - (3*I*PolyLog[3, (I*Sqrt[b]*f^x)/Sqrt[a]])/(8*a^(5/2)*Sqrt[b]*Log[f]^3)}
(* {x^3*f^x/(a + b*f^(2*x))^3, x, 30, (3*x*ArcTan[(Sqrt[b]*f^x)/Sqrt[a]])/(4*a^(5/2)*Sqrt[b]*Log[f]^3) - (3*f^x*x^2)/(8*a^2*(a + b*f^(2*x))*Log[f]^2) - (3*x^2*ArcTan[(Sqrt[b]*f^x)/Sqrt[a]])/(2*a^(5/2)*Sqrt[b]*Log[f]^2) + (x^3*((2*a^(3/2)*f^x)/(a + b*f^(2*x))^2 + (3*Sqrt[a]*f^x)/(a + b*f^(2*x)) + (3*ArcTan[(Sqrt[b]*f^x)/Sqrt[a]])/Sqrt[b]))/(8*a^(5/2)*Log[f]) - (3*I*(2 - 8*x*Log[f] + 3*x^2*Log[f]^2)*PolyLog[2, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(16*a^(5/2)*Sqrt[b]*Log[f]^4) + (3*I*(2 - 8*x*Log[f] + 3*x^2*Log[f]^2)*PolyLog[2, (I*Sqrt[b]*f^x)/Sqrt[a]])/(16*a^(5/2)*Sqrt[b]*Log[f]^4) - (3*I*(4 - 3*x*Log[f])*PolyLog[3, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(8*a^(5/2)*Sqrt[b]*Log[f]^4) + (3*I*(4 - 3*x*Log[f])*PolyLog[3, (I*Sqrt[b]*f^x)/Sqrt[a]])/(8*a^(5/2)*Sqrt[b]*Log[f]^4) - (9*I*PolyLog[4, -((I*Sqrt[b]*f^x)/Sqrt[a])])/(8*a^(5/2)*Sqrt[b]*Log[f]^4) + (9*I*PolyLog[4, (I*Sqrt[b]*f^x)/Sqrt[a]])/(8*a^(5/2)*Sqrt[b]*Log[f]^4)} *)


{x^0/(a*f^x + b*f^(-x)), x, 2, ArcTan[(Sqrt[a]*f^x)/Sqrt[b]]/(Sqrt[a]*Sqrt[b]*Log[f])}
{x^1/(a*f^x + b*f^(-x)), x, 5, (x*ArcTan[(Sqrt[a]*f^x)/Sqrt[b]])/(Sqrt[a]*Sqrt[b]*Log[f]) - (I*PolyLog[2, -((I*Sqrt[a]*f^x)/Sqrt[b])])/(2*Sqrt[a]*Sqrt[b]*Log[f]^2) + (I*PolyLog[2, (I*Sqrt[a]*f^x)/Sqrt[b]])/(2*Sqrt[a]*Sqrt[b]*Log[f]^2)}
{x^2/(a*f^x + b*f^(-x)), x, 7, (x^2*ArcTan[(Sqrt[a]*f^x)/Sqrt[b]])/(Sqrt[a]*Sqrt[b]*Log[f]) - (I*x*PolyLog[2, -((I*Sqrt[a]*f^x)/Sqrt[b])])/(Sqrt[a]*Sqrt[b]*Log[f]^2) + (I*x*PolyLog[2, (I*Sqrt[a]*f^x)/Sqrt[b]])/(Sqrt[a]*Sqrt[b]*Log[f]^2) + (I*PolyLog[3, -((I*Sqrt[a]*f^x)/Sqrt[b])])/(Sqrt[a]*Sqrt[b]*Log[f]^3) - (I*PolyLog[3, (I*Sqrt[a]*f^x)/Sqrt[b]])/(Sqrt[a]*Sqrt[b]*Log[f]^3)}
{x^3/(a*f^x + b*f^(-x)), x, 9, (x^3*ArcTan[(Sqrt[a]*f^x)/Sqrt[b]])/(Sqrt[a]*Sqrt[b]*Log[f]) - (3*I*x^2*PolyLog[2, -((I*Sqrt[a]*f^x)/Sqrt[b])])/(2*Sqrt[a]*Sqrt[b]*Log[f]^2) + (3*I*x^2*PolyLog[2, (I*Sqrt[a]*f^x)/Sqrt[b]])/(2*Sqrt[a]*Sqrt[b]*Log[f]^2) + (3*I*x*PolyLog[3, -((I*Sqrt[a]*f^x)/Sqrt[b])])/(Sqrt[a]*Sqrt[b]*Log[f]^3) - (3*I*x*PolyLog[3, (I*Sqrt[a]*f^x)/Sqrt[b]])/(Sqrt[a]*Sqrt[b]*Log[f]^3) - (3*I*PolyLog[4, -((I*Sqrt[a]*f^x)/Sqrt[b])])/(Sqrt[a]*Sqrt[b]*Log[f]^4) + (3*I*PolyLog[4, (I*Sqrt[a]*f^x)/Sqrt[b]])/(Sqrt[a]*Sqrt[b]*Log[f]^4)}


{x^0/(a*f^x + b*f^(-x))^2, x, 3, -(1/(2*a*(b + a*f^(2*x))*Log[f]))}
{x^1/(a*f^x + b*f^(-x))^2, x, 11, (f^(2*x)*x)/(2*b*(b + a*f^(2*x))*Log[f]) - Log[b + a*f^(2*x)]/(4*a*b*Log[f]^2)}
{x^2/(a*f^x + b*f^(-x))^2, x, 16, (f^(2*x)*x^2)/(2*b*(b + a*f^(2*x))*Log[f]) - (x*Log[1 + (a*f^(2*x))/b])/(2*a*b*Log[f]^2) - PolyLog[2, -((a*f^(2*x))/b)]/(4*a*b*Log[f]^3)}
{x^3/(a*f^x + b*f^(-x))^2, x, 19, (f^(2*x)*x^3)/(2*b*(b + a*f^(2*x))*Log[f]) - (3*x^2*Log[1 + (a*f^(2*x))/b])/(4*a*b*Log[f]^2) - (3*x*PolyLog[2, -((a*f^(2*x))/b)])/(4*a*b*Log[f]^3) + (3*PolyLog[3, -((a*f^(2*x))/b)])/(8*a*b*Log[f]^4)}


{x^0/(a*f^x + b*f^(-x))^3, x, 4, -(f^x/(4*a*(b + a*f^(2*x))^2*Log[f])) + f^x/(8*a*b*(b + a*f^(2*x))*Log[f]) + ArcTan[(Sqrt[a]*f^x)/Sqrt[b]]/(8*a^(3/2)*b^(3/2)*Log[f])}
{x^1/(a*f^x + b*f^(-x))^3, x, 19, f^x/(8*a*b*(b + a*f^(2*x))*Log[f]^2) - (f^x*(5 + (3*a*f^(2*x))/b)*x)/(8*a*(b + a*f^(2*x))^2*Log[f]) + (x*((4*Sqrt[a]*Sqrt[b]*f^x)/(b + a*f^(2*x)) + ArcTan[(Sqrt[a]*f^x)/Sqrt[b]]))/(8*a^(3/2)*b^(3/2)*Log[f]) - (I*PolyLog[2, -((I*Sqrt[a]*f^x)/Sqrt[b])])/(16*a^(3/2)*b^(3/2)*Log[f]^2) + (I*PolyLog[2, (I*Sqrt[a]*f^x)/Sqrt[b]])/(16*a^(3/2)*b^(3/2)*Log[f]^2)}
{x^2/(a*f^x + b*f^(-x))^3, x, 35, -(ArcTan[(Sqrt[a]*f^x)/Sqrt[b]]/(4*a^(3/2)*b^(3/2)*Log[f]^3)) + (f^x*x)/(4*a*b*(b + a*f^(2*x))*Log[f]^2) - (f^x*(5 + (3*a*f^(2*x))/b)*x^2)/(8*a*(b + a*f^(2*x))^2*Log[f]) + (x^2*((4*Sqrt[a]*Sqrt[b]*f^x)/(b + a*f^(2*x)) + ArcTan[(Sqrt[a]*f^x)/Sqrt[b]]))/(8*a^(3/2)*b^(3/2)*Log[f]) - (I*x*PolyLog[2, -((I*Sqrt[a]*f^x)/Sqrt[b])])/(8*a^(3/2)*b^(3/2)*Log[f]^2) + (I*x*PolyLog[2, (I*Sqrt[a]*f^x)/Sqrt[b]])/(8*a^(3/2)*b^(3/2)*Log[f]^2) + (I*PolyLog[3, -((I*Sqrt[a]*f^x)/Sqrt[b])])/(8*a^(3/2)*b^(3/2)*Log[f]^3) - (I*PolyLog[3, (I*Sqrt[a]*f^x)/Sqrt[b]])/(8*a^(3/2)*b^(3/2)*Log[f]^3)}
(* {x^3/(a*f^x + b*f^(-x))^3, x, 49, -((3*x*ArcTan[(Sqrt[a]*f^x)/Sqrt[b]])/(4*a^(3/2)*b^(3/2)*Log[f]^3)) + (3*f^x*x^2)/(8*a*b*(b + a*f^(2*x))*Log[f]^2) - (f^x*(5 + (3*a*f^(2*x))/b)*x^3)/(8*a*(b + a*f^(2*x))^2*Log[f]) + (x^3*((4*Sqrt[a]*Sqrt[b]*f^x)/(b + a*f^(2*x)) + ArcTan[(Sqrt[a]*f^x)/Sqrt[b]]))/(8*a^(3/2)*b^(3/2)*Log[f]) + (3*I*(2 - x^2*Log[f]^2)*PolyLog[2, -((I*Sqrt[a]*f^x)/Sqrt[b])])/(16*a^(3/2)*b^(3/2)*Log[f]^4) - (3*I*(2 - x^2*Log[f]^2)*PolyLog[2, (I*Sqrt[a]*f^x)/Sqrt[b]])/(16*a^(3/2)*b^(3/2)*Log[f]^4) + (3*I*x*PolyLog[3, -((I*Sqrt[a]*f^x)/Sqrt[b])])/(8*a^(3/2)*b^(3/2)*Log[f]^3) - (3*I*x*PolyLog[3, (I*Sqrt[a]*f^x)/Sqrt[b]])/(8*a^(3/2)*b^(3/2)*Log[f]^3) - (3*I*PolyLog[4, -((I*Sqrt[a]*f^x)/Sqrt[b])])/(8*a^(3/2)*b^(3/2)*Log[f]^4) + (3*I*PolyLog[4, (I*Sqrt[a]*f^x)/Sqrt[b]])/(8*a^(3/2)*b^(3/2)*Log[f]^4)} *)


(* ::Subsection::Closed:: *)
(*Integrands involving symmetric trinomials of exponentials of linears *)


(* Integrands of the form x^m/(a+b*E^x+c*E^(2*x)) where m is an integer *)
{1/(1 + 2*E^x + E^(2*x)), x, 3, 1/(1 + E^x) + x - Log[1 + E^x]}
{1/(2 + 3*E^x + E^(2*x)), x, 5, x/2 - Log[1 + E^x] + (1/2)*Log[2 + E^x]}
{1/(-1 + E^x + E^(2*x)), x, 4, -x - ArcTanh[(1 + 2*E^x)/Sqrt[5]]/Sqrt[5] + (1/2)*Log[1 - E^x - E^(2*x)]}
{1/(3 + 3*E^x + E^(2*x)), x, 4, x/3 - ArcTan[(3 + 2*E^x)/Sqrt[3]]/Sqrt[3] - (1/6)*Log[3 + 3*E^x + E^(2*x)]}
{1/(a + b*E^x + c*E^(2*x)), x, 4, x/a + (b*ArcTanh[(b + 2*c*E^x)/Sqrt[b^2 - 4*a*c]])/(a*Sqrt[b^2 - 4*a*c]) - Log[a + b*E^x + c*E^(2*x)]/(2*a)}

{x/(1 + 2*E^x + E^(2*x)), x, 6, -x + x^2/2 + x*(1/(1 + E^x) - Log[1 + E^x]) + Log[1 + E^x] - PolyLog[2, -E^x]}
{x/(2 + 3*E^x + E^(2*x)), x, 7, x^2/4 + (1/2)*x*Log[1 + E^x/2] - x*Log[1 + E^x] - PolyLog[2, -E^x] + (1/2)*PolyLog[2, -(E^x/2)]}
{x/(-1 + E^x + E^(2*x)), x, 7, -(x^2/2) + (1/10)*(5 - Sqrt[5])*x*Log[1 - (1/2)*(1 - Sqrt[5])*E^x] + (1/10)*(5 + Sqrt[5])*x*Log[1 - (1/2)*(1 + Sqrt[5])*E^x] + (1/10)*(5 - Sqrt[5])*PolyLog[2, (1/2)*(1 - Sqrt[5])*E^x] + (1/10)*(5 + Sqrt[5])*PolyLog[2, (1/2)*(1 + Sqrt[5])*E^x]}
{x/(3 + 3*E^x + E^(2*x)), x, 7, x^2/6 + (1/6)*I*(I + Sqrt[3])*x*Log[1 + (2*E^x)/(3 - I*Sqrt[3])] + (1/6)*I*(I - Sqrt[3])*x*Log[1 + (1/6)*(3 - I*Sqrt[3])*E^x] + (1/6)*I*(I + Sqrt[3])*PolyLog[2, -((2*E^x)/(3 - I*Sqrt[3]))] + (1/6)*I*(I - Sqrt[3])*PolyLog[2, (-(1/6))*(3 - I*Sqrt[3])*E^x]}
{x/(a + b*E^x + c*E^(2*x)), x, 7, (c*x^2)/(Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])) - (c*x^2)/(Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])) - (2*c*x*Log[1 + (2*c*E^x)/(b - Sqrt[b^2 - 4*a*c])])/(Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])) + (2*c*x*Log[1 + (2*c*E^x)/(b + Sqrt[b^2 - 4*a*c])])/(Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])) - (2*c*PolyLog[2, -((2*c*E^x)/(b - Sqrt[b^2 - 4*a*c]))])/(Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])) + (2*c*PolyLog[2, -((2*c*E^x)/(b + Sqrt[b^2 - 4*a*c]))])/(Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c]))}

{x^2/(1 + 2*E^x + E^(2*x)), x, 10, -x^2 + x^3/3 + x^2*(1/(1 + E^x) - Log[1 + E^x]) + 2*x*Log[1 + E^x] + 2*(1 - x)*PolyLog[2, -E^x] + 2*PolyLog[3, -E^x]}
{x^2/(2 + 3*E^x + E^(2*x)), x, 9, x^3/6 + (1/2)*x^2*Log[1 + E^x/2] - x^2*Log[1 + E^x] - 2*x*PolyLog[2, -E^x] + x*PolyLog[2, -(E^x/2)] + 2*PolyLog[3, -E^x] - PolyLog[3, -(E^x/2)]}
{x^2/(-1 + E^x + E^(2*x)), x, 9, -(x^3/3) + (1/10)*(5 - Sqrt[5])*x^2*Log[1 - (1/2)*(1 - Sqrt[5])*E^x] + (1/10)*(5 + Sqrt[5])*x^2*Log[1 - (1/2)*(1 + Sqrt[5])*E^x] + (1/5)*(5 - Sqrt[5])*x*PolyLog[2, (1/2)*(1 - Sqrt[5])*E^x] + (1/5)*(5 + Sqrt[5])*x*PolyLog[2, (1/2)*(1 + Sqrt[5])*E^x] - (1/5)*(5 - Sqrt[5])*PolyLog[3, (1/2)*(1 - Sqrt[5])*E^x] - (1/5)*(5 + Sqrt[5])*PolyLog[3, (1/2)*(1 + Sqrt[5])*E^x]}
{x^2/(3 + 3*E^x + E^(2*x)), x, 9, x^3/9 + (1/6)*I*(I + Sqrt[3])*x^2*Log[1 + (2*E^x)/(3 - I*Sqrt[3])] + (1/6)*I*(I - Sqrt[3])*x^2*Log[1 + (1/6)*(3 - I*Sqrt[3])*E^x] + (1/3)*I*(I + Sqrt[3])*x*PolyLog[2, -((2*E^x)/(3 - I*Sqrt[3]))] + (1/3)*I*(I - Sqrt[3])*x*PolyLog[2, (-(1/6))*(3 - I*Sqrt[3])*E^x] - (1/3)*I*(I + Sqrt[3])*PolyLog[3, -((2*E^x)/(3 - I*Sqrt[3]))] - (1/3)*I*(I - Sqrt[3])*PolyLog[3, (-(1/6))*(3 - I*Sqrt[3])*E^x]}
{x^2/(a + b*E^x + c*E^(2*x)), x, 9, (2*c*x^3)/(3*Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])) - (2*c*x^3)/(3*Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])) - (2*c*x^2*Log[1 + (2*c*E^x)/(b - Sqrt[b^2 - 4*a*c])])/(Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])) + (2*c*x^2*Log[1 + (2*c*E^x)/(b + Sqrt[b^2 - 4*a*c])])/(Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])) - (4*c*x*PolyLog[2, -((2*c*E^x)/(b - Sqrt[b^2 - 4*a*c]))])/(Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])) + (4*c*x*PolyLog[2, -((2*c*E^x)/(b + Sqrt[b^2 - 4*a*c]))])/(Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])) + (4*c*PolyLog[3, -((2*c*E^x)/(b - Sqrt[b^2 - 4*a*c]))])/(Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])) - (4*c*PolyLog[3, -((2*c*E^x)/(b + Sqrt[b^2 - 4*a*c]))])/(Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c]))}


(* Integrands of the form x^m/(a+b*f^(c+d*x)+c*f^(2*c+2*d*x)) where m is an integer *)
{1/(1 + 2*f^(c + d*x) + f^(2*c + 2*d*x)), x, 3, x + 1/(d*(1 + f^(c + d*x))*Log[f]) - Log[1 + f^(c + d*x)]/(d*Log[f])}
{1/(a + b*f^(c + d*x) + c*f^(2*c + 2*d*x)), x, 4, x/a + (b*ArcTanh[(b + 2*c*f^(c + d*x))/Sqrt[b^2 - 4*a*c]])/(a*Sqrt[b^2 - 4*a*c]*d*Log[f]) - Log[a + b*f^(c + d*x) + c*f^(2*c + 2*d*x)]/(2*a*d*Log[f])}
{1/(a + b*f^(g + h*x) + c*f^(2*(g + h*x))), x, 4, x/a + (b*ArcTanh[(b + 2*c*f^(g + h*x))/Sqrt[b^2 - 4*a*c]])/(a*Sqrt[b^2 - 4*a*c]*h*Log[f]) - Log[a + b*f^(g + h*x) + c*f^(2*g + 2*h*x)]/(2*a*h*Log[f])}

{x/(1 + 2*f^(c + d*x) + f^(2*c + 2*d*x)), x, 6, x^2/2 - x/(d*Log[f]) + (x*(1/(1 + f^(c + d*x)) - Log[1 + f^(c + d*x)]))/(d*Log[f]) + Log[1 + f^(c + d*x)]/(d^2*Log[f]^2) - PolyLog[2, -f^(c + d*x)]/(d^2*Log[f]^2)}
{x/(a + b*f^(c + d*x) + c*f^(2*c + 2*d*x)), x, 7, (c*x^2)/(Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])) - (c*x^2)/(Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])) - (2*c*x*Log[1 + (2*c*f^(c + d*x))/(b - Sqrt[b^2 - 4*a*c])])/(Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])*d*Log[f]) + (2*c*x*Log[1 + (2*c*f^(c + d*x))/(b + Sqrt[b^2 - 4*a*c])])/(Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])*d*Log[f]) - (2*c*PolyLog[2, -((2*c*f^(c + d*x))/(b - Sqrt[b^2 - 4*a*c]))])/(Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])*d^2*Log[f]^2) + (2*c*PolyLog[2, -((2*c*f^(c + d*x))/(b + Sqrt[b^2 - 4*a*c]))])/(Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])*d^2*Log[f]^2)}

{x^2/(1 + 2*f^(c + d*x) + f^(2*c + 2*d*x)), x, 10, x^3/3 - x^2/(d*Log[f]) + (x^2*(1/(1 + f^(c + d*x)) - Log[1 + f^(c + d*x)]))/(d*Log[f]) + (2*x*Log[1 + f^(c + d*x)])/(d^2*Log[f]^2) + (2*(1 - d*x*Log[f])*PolyLog[2, -f^(c + d*x)])/(d^3*Log[f]^3) + (2*PolyLog[3, -f^(c + d*x)])/(d^3*Log[f]^3)}
{x^2/(a + b*f^(c + d*x) + c*f^(2*c + 2*d*x)), x, 9, (2*c*x^3)/(3*Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])) - (2*c*x^3)/(3*Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])) - (2*c*x^2*Log[1 + (2*c*f^(c + d*x))/(b - Sqrt[b^2 - 4*a*c])])/(Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])*d*Log[f]) + (2*c*x^2*Log[1 + (2*c*f^(c + d*x))/(b + Sqrt[b^2 - 4*a*c])])/(Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])*d*Log[f]) - (4*c*x*PolyLog[2, -((2*c*f^(c + d*x))/(b - Sqrt[b^2 - 4*a*c]))])/(Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])*d^2*Log[f]^2) + (4*c*x*PolyLog[2, -((2*c*f^(c + d*x))/(b + Sqrt[b^2 - 4*a*c]))])/(Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])*d^2*Log[f]^2) + (4*c*PolyLog[3, -((2*c*f^(c + d*x))/(b - Sqrt[b^2 - 4*a*c]))])/(Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])*d^3*Log[f]^3) - (4*c*PolyLog[3, -((2*c*f^(c + d*x))/(b + Sqrt[b^2 - 4*a*c]))])/(Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])*d^3*Log[f]^3)}


{(d + e*f^(g + h*x))/(a + b*f^(g + h*x) + c*f^(2*g + 2*h*x)), x, 4, (d*x)/a + ((b*d - 2*a*e)*ArcTanh[(b + 2*c*f^(g + h*x))/Sqrt[b^2 - 4*a*c]])/(a*Sqrt[b^2 - 4*a*c]*h*Log[f]) - (d*Log[a + b*f^(g + h*x) + c*f^(2*g + 2*h*x)])/(2*a*h*Log[f])}
{(d + e*f^(g + h*x))/(a + b*f^(g + h*x) + c*f^(2*(g + h*x))), x, 4, (d*x)/a + ((b*d - 2*a*e)*ArcTanh[(b + 2*c*f^(g + h*x))/Sqrt[b^2 - 4*a*c]])/(a*Sqrt[b^2 - 4*a*c]*h*Log[f]) - (d*Log[a + b*f^(g + h*x) + c*f^(2*g + 2*h*x)])/(2*a*h*Log[f])}


(* Integrands of the form x^m/(a+b*f^(c+d*x)+c*f^(2*c+2*d*x)) where b^2-4*a*c == 0 *)
{1/(2 + E^(-x) + E^x), x, 2, -(1/(1 + E^x))}
{x/(2 + E^(-x) + E^x), x, 4, (E^x*x)/(1 + E^x) - Log[1 + E^x]}
{x^2/(2 + E^(-x) + E^x), x, 6, (E^x*x^2)/(1 + E^x) - 2*x*Log[1 + E^x] - 2*PolyLog[2, -E^x]}

{1/(2 + f^(-c - d*x) + f^(c + d*x)), x, 2, -(1/(d*(1 + f^(c + d*x))*Log[f]))}
{x/(2 + f^(-c - d*x) + f^(c + d*x)), x, 4, (f^(c + d*x)*x)/(d*(1 + f^(c + d*x))*Log[f]) - Log[1 + f^(c + d*x)]/(d^2*Log[f]^2)}
{x^2/(2 + f^(-c - d*x) + f^(c + d*x)), x, 6, (f^(c + d*x)*x^2)/(d*(1 + f^(c + d*x))*Log[f]) - (2*x*Log[1 + f^(c + d*x)])/(d^2*Log[f]^2) - (2*PolyLog[2, -f^(c + d*x)])/(d^3*Log[f]^3)}


(* Integrands of the form x^m/(a+b*f^(c+d*x)+c*f^(2*c+2*d*x)) where b^2-4*a*c != 0 *)
{1/(2 + 3^(-x) + 3^x), x, 2, -(1/((1 + 3^x)*Log[3]))}
{1/(1 - E^(-x) + 2*E^x), x, 2, (-(2/3))*ArcTanh[1/3 + (4*E^x)/3]}

{1/(a + b*E^(-x) + c*E^x), x, 2, -((2*ArcTanh[(a + 2*c*E^x)/Sqrt[a^2 - 4*b*c]])/Sqrt[a^2 - 4*b*c])}
{x/(a + b*E^(-x) + c*E^x), x, 8, (x*Log[1 + (2*c*E^x)/(a - Sqrt[a^2 - 4*b*c])])/Sqrt[a^2 - 4*b*c] - (x*Log[1 + (2*c*E^x)/(a + Sqrt[a^2 - 4*b*c])])/Sqrt[a^2 - 4*b*c] + PolyLog[2, -((2*c*E^x)/(a - Sqrt[a^2 - 4*b*c]))]/Sqrt[a^2 - 4*b*c] - PolyLog[2, -((2*c*E^x)/(a + Sqrt[a^2 - 4*b*c]))]/Sqrt[a^2 - 4*b*c]}
{x^2/(a + b*E^(-x) + c*E^x), x, 10, (x^2*Log[1 + (2*c*E^x)/(a - Sqrt[a^2 - 4*b*c])])/Sqrt[a^2 - 4*b*c] - (x^2*Log[1 + (2*c*E^x)/(a + Sqrt[a^2 - 4*b*c])])/Sqrt[a^2 - 4*b*c] + (2*x*PolyLog[2, -((2*c*E^x)/(a - Sqrt[a^2 - 4*b*c]))])/Sqrt[a^2 - 4*b*c] - (2*x*PolyLog[2, -((2*c*E^x)/(a + Sqrt[a^2 - 4*b*c]))])/Sqrt[a^2 - 4*b*c] - (2*PolyLog[3, -((2*c*E^x)/(a - Sqrt[a^2 - 4*b*c]))])/Sqrt[a^2 - 4*b*c] + (2*PolyLog[3, -((2*c*E^x)/(a + Sqrt[a^2 - 4*b*c]))])/Sqrt[a^2 - 4*b*c]}

{1/(a + b*f^(-c - d*x) + c*f^(c + d*x)), x, 2, -((2*ArcTanh[(a + 2*c*f^(c + d*x))/Sqrt[a^2 - 4*b*c]])/(Sqrt[a^2 - 4*b*c]*d*Log[f]))}
{x/(a + b*f^(-c - d*x) + c*f^(c + d*x)), x, 8, (x*Log[1 + (2*c*f^(c + d*x))/(a - Sqrt[a^2 - 4*b*c])])/(Sqrt[a^2 - 4*b*c]*d*Log[f]) - (x*Log[1 + (2*c*f^(c + d*x))/(a + Sqrt[a^2 - 4*b*c])])/(Sqrt[a^2 - 4*b*c]*d*Log[f]) + PolyLog[2, -((2*c*f^(c + d*x))/(a - Sqrt[a^2 - 4*b*c]))]/(Sqrt[a^2 - 4*b*c]*d^2*Log[f]^2) - PolyLog[2, -((2*c*f^(c + d*x))/(a + Sqrt[a^2 - 4*b*c]))]/(Sqrt[a^2 - 4*b*c]*d^2*Log[f]^2)}
{x^2/(a + b*f^(-c - d*x) + c*f^(c + d*x)), x, 10, (x^2*Log[1 + (2*c*f^(c + d*x))/(a - Sqrt[a^2 - 4*b*c])])/(Sqrt[a^2 - 4*b*c]*d*Log[f]) - (x^2*Log[1 + (2*c*f^(c + d*x))/(a + Sqrt[a^2 - 4*b*c])])/(Sqrt[a^2 - 4*b*c]*d*Log[f]) + (2*x*PolyLog[2, -((2*c*f^(c + d*x))/(a - Sqrt[a^2 - 4*b*c]))])/(Sqrt[a^2 - 4*b*c]*d^2*Log[f]^2) - (2*x*PolyLog[2, -((2*c*f^(c + d*x))/(a + Sqrt[a^2 - 4*b*c]))])/(Sqrt[a^2 - 4*b*c]*d^2*Log[f]^2) - (2*PolyLog[3, -((2*c*f^(c + d*x))/(a - Sqrt[a^2 - 4*b*c]))])/(Sqrt[a^2 - 4*b*c]*d^3*Log[f]^3) + (2*PolyLog[3, -((2*c*f^(c + d*x))/(a + Sqrt[a^2 - 4*b*c]))])/(Sqrt[a^2 - 4*b*c]*d^3*Log[f]^3)}


(* ::Section::Closed:: *)
(*Integrands involving exponential and trig functions*)


{f^(a + b*x + c*x^2)*g^(d + e*x + f*x^2), x, 4, (f^a*g^d*Sqrt[Pi]*Erfi[(b*Log[f] + e*Log[g] + 2*x*(c*Log[f] + f*Log[g]))/(2*Sqrt[c*Log[f] + f*Log[g]])])/(E^((b*Log[f] + e*Log[g])^2/(4*(c*Log[f] + f*Log[g])))*(2*Sqrt[c*Log[f] + f*Log[g]]))}


(* ::Subsection::Closed:: *)
(*Integrands involving products of exponential and trig functions*)


(* Integrands of the form E^x*Cos[a+b*x]^m*Sin[a+b*x]^n where m and n are positive integers *)
{E^x*Cos[a + b*x]*Sin[a + b*x], x, 3, -((b*E^x*Cos[2*a + 2*b*x])/(1 + 4*b^2)) + (E^x*Sin[2*a + 2*b*x])/(2*(1 + 4*b^2))}
{E^x*Cos[a + b*x]*Sin[a + b*x]^2, x, 4, (E^x*Cos[a + b*x])/(4*(1 + b^2)) - (E^x*Cos[3*a + 3*b*x])/(4*(1 + 9*b^2)) + (b*E^x*Sin[a + b*x])/(4*(1 + b^2)) - (3*b*E^x*Sin[3*a + 3*b*x])/(4*(1 + 9*b^2))}
{E^x*Cos[a + b*x]*Sin[a + b*x]^3, x, 4, -((b*E^x*Cos[2*a + 2*b*x])/(2*(1 + 4*b^2))) + (b*E^x*Cos[4*a + 4*b*x])/(2*(1 + 16*b^2)) + (E^x*Sin[2*a + 2*b*x])/(4*(1 + 4*b^2)) - (E^x*Sin[4*a + 4*b*x])/(8*(1 + 16*b^2))}

{E^x*Cos[a + b*x]^2*Sin[a + b*x], x, 4, -((b*E^x*Cos[a + b*x])/(4*(1 + b^2))) - (3*b*E^x*Cos[3*a + 3*b*x])/(4*(1 + 9*b^2)) + (E^x*Sin[a + b*x])/(4*(1 + b^2)) + (E^x*Sin[3*a + 3*b*x])/(4*(1 + 9*b^2))}
{E^x*Cos[a + b*x]^2*Sin[a + b*x]^2, x, 4, E^x/8 - (E^x*Cos[4*a + 4*b*x])/(8*(1 + 16*b^2)) - (b*E^x*Sin[4*a + 4*b*x])/(2*(1 + 16*b^2))}
{E^x*Cos[a + b*x]^2*Sin[a + b*x]^3, x, 5, -((b*E^x*Cos[a + b*x])/(8*(1 + b^2))) - (3*b*E^x*Cos[3*a + 3*b*x])/(16*(1 + 9*b^2)) + (5*b*E^x*Cos[5*a + 5*b*x])/(16*(1 + 25*b^2)) + (E^x*Sin[a + b*x])/(8*(1 + b^2)) + (E^x*Sin[3*a + 3*b*x])/(16*(1 + 9*b^2)) - (E^x*Sin[5*a + 5*b*x])/(16*(1 + 25*b^2))}

{E^x*Cos[a + b*x]^3*Sin[a + b*x], x, 4, -((b*E^x*Cos[2*a + 2*b*x])/(2*(1 + 4*b^2))) - (b*E^x*Cos[4*a + 4*b*x])/(2*(1 + 16*b^2)) + (E^x*Sin[2*a + 2*b*x])/(4*(1 + 4*b^2)) + (E^x*Sin[4*a + 4*b*x])/(8*(1 + 16*b^2))}
{E^x*Cos[a + b*x]^3*Sin[a + b*x]^2, x, 5, (E^x*Cos[a + b*x])/(8*(1 + b^2)) - (E^x*Cos[3*a + 3*b*x])/(16*(1 + 9*b^2)) - (E^x*Cos[5*a + 5*b*x])/(16*(1 + 25*b^2)) + (b*E^x*Sin[a + b*x])/(8*(1 + b^2)) - (3*b*E^x*Sin[3*a + 3*b*x])/(16*(1 + 9*b^2)) - (5*b*E^x*Sin[5*a + 5*b*x])/(16*(1 + 25*b^2))}
{E^x*Cos[a + b*x]^3*Sin[a + b*x]^3, x, 4, -((3*b*E^x*Cos[2*a + 2*b*x])/(16*(1 + 4*b^2))) + (3*b*E^x*Cos[6*a + 6*b*x])/(16*(1 + 36*b^2)) + (3*E^x*Sin[2*a + 2*b*x])/(32*(1 + 4*b^2)) - (E^x*Sin[6*a + 6*b*x])/(32*(1 + 36*b^2))}


(* Integrands involving products of exponential and trig functions of quadratics *)
{E^x*Sin[a + b*x + c*x^2], x, 9, ((-1)^(3/4)*E^(I*a + (I*(1 + I*b)^2)/(4*c))*Sqrt[Pi]*Erf[((-1)^(1/4)*(1 + I*b + 2*I*c*x))/(2*Sqrt[c])])/(4*Sqrt[c]) + ((-1)^(3/4)*E^((-I)*a - (I*(1 - I*b)^2)/(4*c))*Sqrt[Pi]*Erfi[((-1)^(1/4)*(1 - I*b - 2*I*c*x))/(2*Sqrt[c])])/(4*Sqrt[c])}
{E^x*Cos[a + b*x + c*x^2], x, 9, -(((-1)^(1/4)*E^(I*a + (I*(1 + I*b)^2)/(4*c))*Sqrt[Pi]*Erf[((-1)^(1/4)*(1 + I*b + 2*I*c*x))/(2*Sqrt[c])])/(4*Sqrt[c])) + ((-1)^(1/4)*E^((-I)*a - (I*(1 - I*b)^2)/(4*c))*Sqrt[Pi]*Erfi[((-1)^(1/4)*(1 - I*b - 2*I*c*x))/(2*Sqrt[c])])/(4*Sqrt[c])}


{f^(a + b*x + c*x^2)*Sin[c + d*x + e*x^2], x, 10, -((I*E^((-I)*c + (I*d - b*Log[f])^2/(4*(I*e - c*Log[f])))*f^a*Sqrt[Pi]*Erfi[(I*d - b*Log[f] + 2*x*(I*e - c*Log[f]))/(2*Sqrt[(-I)*e + c*Log[f]])])/(4*Sqrt[(-I)*e + c*Log[f]])) - (I*E^(I*c - (I*d + b*Log[f])^2/(4*(I*e + c*Log[f])))*f^a*Sqrt[Pi]*Erfi[(I*d + b*Log[f] + 2*x*(I*e + c*Log[f]))/(2*Sqrt[I*e + c*Log[f]])])/(4*Sqrt[I*e + c*Log[f]])}
{f^(a + b*x + c*x^2)*Cos[c + d*x + e*x^2], x, 10, -((E^((-I)*c + (I*d - b*Log[f])^2/(4*(I*e - c*Log[f])))*f^a*Sqrt[Pi]*Erfi[(I*d - b*Log[f] + 2*x*(I*e - c*Log[f]))/(2*Sqrt[(-I)*e + c*Log[f]])])/(4*Sqrt[(-I)*e + c*Log[f]])) + (E^(I*c - (I*d + b*Log[f])^2/(4*(I*e + c*Log[f])))*f^a*Sqrt[Pi]*Erfi[(I*d + b*Log[f] + 2*x*(I*e + c*Log[f]))/(2*Sqrt[I*e + c*Log[f]])])/(4*Sqrt[I*e + c*Log[f]])}


{E^(a*x)*Sin[b*x], x, 1, -((b*E^(a*x)*Cos[b*x])/(a^2 + b^2)) + (a*E^(a*x)*Sin[b*x])/(a^2 + b^2)}
{E^x*Sin[7 + 5*x], x, 1, (-(5/26))*E^x*Cos[7 + 5*x] + (1/26)*E^x*Sin[7 + 5*x]}
{E^(5*x)*Sin[3*x], x, 1, (-(3/34))*E^(5*x)*Cos[3*x] + (5/34)*E^(5*x)*Sin[3*x]}

{E^(a*x)*Cos[b*x], x, 1, (a*E^(a*x)*Cos[b*x])/(a^2 + b^2) + (b*E^(a*x)*Sin[b*x])/(a^2 + b^2)}
{E^(2*x^2)*x*Cos[2*x^2], x, 2, (1/8)*E^(2*x^2)*Cos[2*x^2] + (1/8)*E^(2*x^2)*Sin[2*x^2]}

{E^(3*x)*(-5*Cos[4*x] + 2*Sin[4*x]), x, 4, (-(23/25))*E^(3*x)*Cos[4*x] - (14/25)*E^(3*x)*Sin[4*x]}

{E^x*x*Sin[x], x, 4, (1/2)*E^x*Cos[x] - (1/2)*E^x*x*(Cos[x] - Sin[x])}
{E^x*x*Cos[x], x, 4, (-(1/2))*E^x*Sin[x] + (1/2)*E^x*x*(Cos[x] + Sin[x])}

{E^x*x^2*Sin[x], x, 11, (-(1/2))*E^x*Cos[x] + E^x*x*Cos[x] - (1/2)*E^x*x^2*(Cos[x] - Sin[x]) - (1/2)*E^x*Sin[x]}
{E^x*x^2*Cos[x], x, 11, (-(1/2))*E^x*Cos[x] + (1/2)*E^x*Sin[x] - E^x*x*Sin[x] + (1/2)*E^x*x^2*(Cos[x] + Sin[x])}
{E^(3*x)*x^2*Sin[x], x, 11, (-(13/250))*E^(3*x)*Cos[x] + (3/25)*E^(3*x)*x*Cos[x] - (1/10)*E^(3*x)*x^2*(Cos[x] - 3*Sin[x]) + (9/250)*E^(3*x)*Sin[x] - (4/25)*E^(3*x)*x*Sin[x]}

{E^x*Sin[x]^2, x, 2, (2*E^x)/5 - (2/5)*E^x*Cos[x]*Sin[x] + (1/5)*E^x*Sin[x]^2}
{E^x*Cos[x]^2, x, 2, (2*E^x)/5 + (1/5)*E^x*Cos[x]^2 + (2/5)*E^x*Cos[x]*Sin[x]}
{E^x*Sin[x]^4, x, 3, (24*E^x)/85 - (24/85)*E^x*Cos[x]*Sin[x] + (12/85)*E^x*Sin[x]^2 - (4/17)*E^x*Cos[x]*Sin[x]^3 + (1/17)*E^x*Sin[x]^4}
{E^x*Cos[x]^4, x, 3, (24*E^x)/85 + (12/85)*E^x*Cos[x]^2 + (1/17)*E^x*Cos[x]^4 + (24/85)*E^x*Cos[x]*Sin[x] + (4/17)*E^x*Cos[x]^3*Sin[x]}

{(Cos[x] + Sin[x])/(E^(-x) + Sin[x]), x, -5, Log[1 + E^x*Sin[x]]}

{Sin[x]/E^x + E^x*Sin[x], x, 3, ((-(1/2))*Cos[x])/E^x - (1/2)*E^x*Cos[x] - ((1/2)*Sin[x])/E^x + (1/2)*E^x*Sin[x]}


{E^x*Sin[x], x, 1, (-(1/2))*E^x*Cos[x] + (1/2)*E^x*Sin[x]}
{E^(2*x)*Sin[3*x], x, 1, (-(3/13))*E^(2*x)*Cos[3*x] + (2/13)*E^(2*x)*Sin[3*x]}
{E^(2*x)*Cos[x], x, 1, (2/5)*E^(2*x)*Cos[x] + (1/5)*E^(2*x)*Sin[x]}
{Cos[5*x]/E^x, x, 1, ((-(1/26))*Cos[5*x])/E^x + ((5/26)*Sin[5*x])/E^x}

{E^(3*x)*Sin[4 + x], x, 1, (-(1/10))*E^(3*x)*Cos[4 + x] + (3/10)*E^(3*x)*Sin[4 + x]}
{E^(3*x)*Cos[4 + x], x, 1, (3/10)*E^(3*x)*Cos[4 + x] + (1/10)*E^(3*x)*Sin[4 + x]}

{E^x*Sin[x]^3, x, 2, (-(3/10))*E^x*Cos[x] + (3/10)*E^x*Sin[x] - (3/10)*E^x*Cos[x]*Sin[x]^2 + (1/10)*E^x*Sin[x]^3}
{E^x*Cos[x]^3, x, 2, (3/10)*E^x*Cos[x] + (1/10)*E^x*Cos[x]^3 + (3/10)*E^x*Sin[x] + (3/10)*E^x*Cos[x]^2*Sin[x]}

{E^(x^2)*Sin[b*x], x, 7, (1/4)*I*E^(b^2/4)*Sqrt[Pi]*Erfi[(1/2)*((-I)*b + 2*x)] - (1/4)*I*E^(b^2/4)*Sqrt[Pi]*Erfi[(1/2)*(I*b + 2*x)]}
{E^(x^2)*Cos[b*x], x, 7, (1/4)*E^(b^2/4)*Sqrt[Pi]*Erfi[(1/2)*((-I)*b + 2*x)] + (1/4)*E^(b^2/4)*Sqrt[Pi]*Erfi[(1/2)*(I*b + 2*x)]}
{E^(x^2)*Sin[a + b*x], x, 9, (1/4)*I*E^((-I)*a + b^2/4)*Sqrt[Pi]*Erfi[(1/2)*((-I)*b + 2*x)] - (1/4)*I*E^(I*a + b^2/4)*Sqrt[Pi]*Erfi[(1/2)*(I*b + 2*x)]}
{E^(x^2)*Cos[a + b*x], x, 9, (1/4)*E^((-I)*a + b^2/4)*Sqrt[Pi]*Erfi[(1/2)*((-I)*b + 2*x)] + (1/4)*E^(I*a + b^2/4)*Sqrt[Pi]*Erfi[(1/2)*(I*b + 2*x)]}


(* ::Subsection::Closed:: *)
(*Integrands involving exponentials of trig functions*)


(* Integrands of the form E^(n*Sin[a+b*x])*Sin[2*(a+b*x)] *)
{E^(n*Sin[a+b*x])*Sin[2*a+2*b*x], x, 4, -((2*E^(n*Sin[a + b*x]))/(b*n^2)) + (2*E^(n*Sin[a + b*x])*Sin[a + b*x])/(b*n)}
{E^(n*Sin[a+b*x])*Sin[2*(a+b*x)], x, 4, -((2*E^(n*Sin[a + b*x]))/(b*n^2)) + (2*E^(n*Sin[a + b*x])*Sin[a + b*x])/(b*n)}
{E^(n*Sin[a/2+b/2*x])*Sin[a+b*x], x, 4, -((4*E^(n*Sin[a/2 + (b*x)/2]))/(b*n^2)) + (4*E^(n*Sin[a/2 + (b*x)/2])*Sin[a/2 + (b*x)/2])/(b*n)}
{E^(n*Sin[(a+b*x)/2])*Sin[a+b*x], x, 4, -((4*E^(n*Sin[a/2 + (b*x)/2]))/(b*n^2)) + (4*E^(n*Sin[a/2 + (b*x)/2])*Sin[a/2 + (b*x)/2])/(b*n)}


(* Integrands of the form E^(n*Cos[a+b*x])*Sin[2*(a+b*x)] *)
{E^(n*Cos[a+b*x])*Sin[2*a+2*b*x], x, 4, (2*E^(n*Cos[a + b*x]))/(b*n^2) - (2*E^(n*Cos[a + b*x])*Cos[a + b*x])/(b*n)}
{E^(n*Cos[a+b*x])*Sin[2*(a+b*x)], x, 4, (2*E^(n*Cos[a + b*x]))/(b*n^2) - (2*E^(n*Cos[a + b*x])*Cos[a + b*x])/(b*n)}
{E^(n*Cos[a/2+b/2*x])*Sin[a+b*x], x, 4, (4*E^(n*Cos[a/2 + (b*x)/2]))/(b*n^2) - (4*E^(n*Cos[a/2 + (b*x)/2])*Cos[a/2 + (b*x)/2])/(b*n)}
{E^(n*Cos[(a+b*x)/2])*Sin[a+b*x], x, 4, (4*E^(n*Cos[a/2 + (b*x)/2]))/(b*n^2) - (4*E^(n*Cos[a/2 + (b*x)/2])*Cos[a/2 + (b*x)/2])/(b*n)}


(* Integrands of the form E^(n*Cos[a+b*x])*Sin[a+b*x] *)
{E^(n*Cos[a+b*x])*Sin[a+b*x], x, 2, -(E^(n*Cos[a + b*x])/(b*n))}
{E^(n*Cos[a*c+b*c*x])*Sin[c*(a+b*x)], x, 2, -(E^(n*Cos[c*(a + b*x)])/(b*c*n))}
{E^(n*Cos[c*(a+b*x)])*Sin[a*c+b*c*x], x, 2, -(E^(n*Cos[a*c + b*c*x])/(b*c*n))}


(* Integrands of the form E^(n*Sin[a+b*x])*Cos[a+b*x] *)
{E^(n*Sin[a+b*x])*Cos[a+b*x], x, 2, E^(n*Sin[a + b*x])/(b*n)}
{E^(n*Sin[a*c+b*c*x])*Cos[c*(a+b*x)], x, 2, E^(n*Sin[c*(a + b*x)])/(b*c*n)}
{E^(n*Sin[c*(a+b*x)])*Cos[a*c+b*c*x], x, 2, E^(n*Sin[a*c + b*c*x])/(b*c*n)}


(* Integrands of the form E^(n*Cos[a+b*x])*Sin[a+b*x] *)
{E^(n*Cos[a+b*x])*Tan[a+b*x], x, 2, -(ExpIntegralEi[n*Cos[a + b*x]]/b)}
{E^(n*Cos[a*c+b*c*x])*Tan[c*(a+b*x)], x, 2, -(ExpIntegralEi[n*Cos[c*(a + b*x)]]/(b*c))}
{E^(n*Cos[c*(a+b*x)])*Tan[a*c+b*c*x], x, 2, -(ExpIntegralEi[n*Cos[a*c + b*c*x]]/(b*c))}


(* Integrands of the form E^(n*Sin[a+b*x])*Cos[a+b*x] *)
{E^(n*Sin[a+b*x])*Cot[a+b*x], x, 2, ExpIntegralEi[n*Sin[a + b*x]]/b}
{E^(n*Sin[a*c+b*c*x])*Cot[c*(a+b*x)], x, 2, ExpIntegralEi[n*Sin[c*(a + b*x)]]/(b*c)}
{E^(n*Sin[c*(a+b*x)])*Cot[a*c+b*c*x], x, 2, ExpIntegralEi[n*Sin[a*c + b*c*x]]/(b*c)}


{E^(Cos[x]*Sin[x])*Cos[2*x], x, 2, E^((1/2)*Sin[2*x])}
{E^(Cos[x/2]*Sin[x/2])*Cos[x], x, 2, 2*E^(Sin[x]/2)}

{E^Sin[x]*Cos[x]*Sin[x], x, 3, -E^Sin[x] + E^Sin[x]*Sin[x]}
{E^Cos[1 + 3*x]*Cos[1 + 3*x]*Sin[1 + 3*x], x, 3, (1/3)*E^Cos[1 + 3*x] - (1/3)*E^Cos[1 + 3*x]*Cos[1 + 3*x]}

{Sec[x]^2*E^Tan[x], x, 2, E^Tan[x]}
{Csc[x]^2/E^Cot[x], x, 2, E^(-Cot[x])}
{E^Sec[x]*Sec[x]*Tan[x], x, 3, E^Sec[x]}
{2^Sec[x]*Sec[x]*Tan[x], x, 3, 2^Sec[x]/Log[2]}


(* ::Subsection::Closed:: *)
(*Integrands involving trig functions of exponentials*)


(* Integrands involving products of exponential and trig functions of exponentials *)
{E^x*Sin[E^x], x, 2, -Cos[E^x]}

{E^x*Csc[E^x]*Sec[E^x], x, 2, Log[Tan[E^x]]}
{E^x*Cos[E^x], x, 2, Sin[E^x]}
{E^(2*x)*Cos[E^(2*x)], x, 2, Sin[E^(2*x)]/2}
{Cos[E^(-2*x)]/E^(2*x), x, 2, -Sin[E^(-2*x)]/2}
{E^(2*x)*Cos[E^x], x, 3, Cos[E^x] + E^x*Sin[E^x]}
{E^(-1 + 3*x)*Cos[E^(-1 + 3*x)]*Sin[1 + E^(-1 + 3*x)], x, 4, -Cos[1 + 2*E^(-1 + 3*x)]/12 + (E^(-1 + 3*x)*Sin[1])/6}

{E^x*Tan[E^x], x, 2, -Log[Cos[E^x]]}

{E^x*Sec[E^x], x, 2, ArcTanh[Sin[E^x]]}
{E^x*Sec[E^x]*Tan[E^x], x, 2, Sec[E^x]}

{E^x*Csc[E^x]^2, x, 2, -Cot[E^x]}


(* ::Section::Closed:: *)
(*Integrands involving exponential and hyperbolic functions*)


(* ::Subsection::Closed:: *)
(*Integrands involving products of exponential and hyperbolic functions*)


(* Integrands of the form E^x*Cosh[a+b*x]^m*Sinh[a+b*x]^n where m and n are positive integers *)
{E^x*Cosh[a + b*x]*Sinh[a + b*x], x, 3, -((b*E^x*Cosh[2*a + 2*b*x])/(1 - 4*b^2)) + (E^x*Sinh[2*a + 2*b*x])/(2*(1 - 4*b^2))}
{E^x*Cosh[a + b*x]*Sinh[a + b*x]^2, x, 4, -((E^x*Cosh[a + b*x])/(4*(1 - b^2))) + (E^x*Cosh[3*a + 3*b*x])/(4*(1 - 9*b^2)) + (b*E^x*Sinh[a + b*x])/(4*(1 - b^2)) - (3*b*E^x*Sinh[3*a + 3*b*x])/(4*(1 - 9*b^2))}
{E^x*Cosh[a + b*x]*Sinh[a + b*x]^3, x, 4, (b*E^x*Cosh[2*a + 2*b*x])/(2*(1 - 4*b^2)) - (b*E^x*Cosh[4*a + 4*b*x])/(2*(1 - 16*b^2)) - (E^x*Sinh[2*a + 2*b*x])/(4*(1 - 4*b^2)) + (E^x*Sinh[4*a + 4*b*x])/(8*(1 - 16*b^2))}

{E^x*Cosh[a + b*x]^2*Sinh[a + b*x], x, 4, -((b*E^x*Cosh[a + b*x])/(4*(1 - b^2))) - (3*b*E^x*Cosh[3*a + 3*b*x])/(4*(1 - 9*b^2)) + (E^x*Sinh[a + b*x])/(4*(1 - b^2)) + (E^x*Sinh[3*a + 3*b*x])/(4*(1 - 9*b^2))}
{E^x*Cosh[a + b*x]^2*Sinh[a + b*x]^2, x, 4, -(E^x/8) + (E^x*Cosh[4*a + 4*b*x])/(8*(1 - 16*b^2)) - (b*E^x*Sinh[4*a + 4*b*x])/(2*(1 - 16*b^2))}
{E^x*Cosh[a + b*x]^2*Sinh[a + b*x]^3, x, 5, (b*E^x*Cosh[a + b*x])/(8*(1 - b^2)) + (3*b*E^x*Cosh[3*a + 3*b*x])/(16*(1 - 9*b^2)) - (5*b*E^x*Cosh[5*a + 5*b*x])/(16*(1 - 25*b^2)) - (E^x*Sinh[a + b*x])/(8*(1 - b^2)) - (E^x*Sinh[3*a + 3*b*x])/(16*(1 - 9*b^2)) + (E^x*Sinh[5*a + 5*b*x])/(16*(1 - 25*b^2))}

{E^x*Cosh[a + b*x]^3*Sinh[a + b*x], x, 4, -((b*E^x*Cosh[2*a + 2*b*x])/(2*(1 - 4*b^2))) - (b*E^x*Cosh[4*a + 4*b*x])/(2*(1 - 16*b^2)) + (E^x*Sinh[2*a + 2*b*x])/(4*(1 - 4*b^2)) + (E^x*Sinh[4*a + 4*b*x])/(8*(1 - 16*b^2))}
{E^x*Cosh[a + b*x]^3*Sinh[a + b*x]^2, x, 5, -((E^x*Cosh[a + b*x])/(8*(1 - b^2))) + (E^x*Cosh[3*a + 3*b*x])/(16*(1 - 9*b^2)) + (E^x*Cosh[5*a + 5*b*x])/(16*(1 - 25*b^2)) + (b*E^x*Sinh[a + b*x])/(8*(1 - b^2)) - (3*b*E^x*Sinh[3*a + 3*b*x])/(16*(1 - 9*b^2)) - (5*b*E^x*Sinh[5*a + 5*b*x])/(16*(1 - 25*b^2))}
{E^x*Cosh[a + b*x]^3*Sinh[a + b*x]^3, x, 4, (3*b*E^x*Cosh[2*a + 2*b*x])/(16*(1 - 4*b^2)) - (3*b*E^x*Cosh[6*a + 6*b*x])/(16*(1 - 36*b^2)) - (3*E^x*Sinh[2*a + 2*b*x])/(32*(1 - 4*b^2)) + (E^x*Sinh[6*a + 6*b*x])/(32*(1 - 36*b^2))}


(* Integrands of the form E^x*Cosh[x]^m*Sinh[x]^n where m and n are positive integers *)
{E^x*Cosh[x]*Sinh[x], x, 3, 1/(E^x*4) + E^(3*x)/12}
{E^x*Cosh[x]*Sinh[x]^2, x, 4, -(1/16)/E^(2*x) - E^(2*x)/16 + E^(4*x)/32 - x/8, -(1/16)/E^(2*x) - E^(2*x)/16 + E^(4*x)/32 - Log[E^x]/8}
{E^x*Cosh[x]*Sinh[x]^3, x, 4, 1/(E^(3*x)*48) - 1/(E^x*8) - E^(3*x)/24 + E^(5*x)/80}

{E^x*Cosh[x]^2*Sinh[x], x, 4, 1/(E^(2*x)*16) + E^(2*x)/16 + E^(4*x)/32 - x/8, 1/(E^(2*x)*16) + E^(2*x)/16 + E^(4*x)/32 - Log[E^x]/8}
{E^x*Cosh[x]^2*Sinh[x]^2, x, 4, -(1/48)/E^(3*x) - E^x/8 + E^(5*x)/80}
{E^x*Cosh[x]^2*Sinh[x]^3, x, 4, 1/(E^(4*x)*128) - 1/(E^(2*x)*64) - E^(2*x)/32 - E^(4*x)/128 + E^(6*x)/192 + x/16, 1/(E^(4*x)*128) - 1/(E^(2*x)*64) - E^(2*x)/32 - E^(4*x)/128 + E^(6*x)/192 + Log[E^x]/16}

{E^x*Cosh[x]^3*Sinh[x], x, 4, 1/(E^(3*x)*48) + 1/(E^x*8) + E^(3*x)/24 + E^(5*x)/80}
{E^x*Cosh[x]^3*Sinh[x]^2, x, 4, -(1/128)/E^(4*x) - 1/(E^(2*x)*64) - E^(2*x)/32 + E^(4*x)/128 + E^(6*x)/192 - x/16, -(1/128)/E^(4*x) - 1/(E^(2*x)*64) - E^(2*x)/32 + E^(4*x)/128 + E^(6*x)/192 - Log[E^x]/16}
{E^x*Cosh[x]^3*Sinh[x]^3, x, 4, 1/(E^(5*x)*320) - 3/(E^x*64) - E^(3*x)/64 + E^(7*x)/448}


(* Integrands involving products of exponential and trig functions of quadratics *)
{E^x*Sinh[a + b*x + c*x^2], x, 9, (E^(-a + (1 - b)^2/(4*c))*Sqrt[Pi]*Erf[(1 - b - 2*c*x)/(2*Sqrt[c])])/(4*Sqrt[c]) + (E^(a - (1 + b)^2/(4*c))*Sqrt[Pi]*Erfi[(1 + b + 2*c*x)/(2*Sqrt[c])])/(4*Sqrt[c])}
{E^x*Cosh[a + b*x + c*x^2], x, 9, -((E^(-a + (1 - b)^2/(4*c))*Sqrt[Pi]*Erf[(1 - b - 2*c*x)/(2*Sqrt[c])])/(4*Sqrt[c])) + (E^(a - (1 + b)^2/(4*c))*Sqrt[Pi]*Erfi[(1 + b + 2*c*x)/(2*Sqrt[c])])/(4*Sqrt[c])}


{f^(a + b*x + c*x^2)*Sinh[c + d*x + e*x^2], x, 9, (E^(-c + (d - b*Log[f])^2/(4*(e - c*Log[f])))*f^a*Sqrt[Pi]*Erfi[(d - b*Log[f] + 2*x*(e - c*Log[f]))/(2*Sqrt[-e + c*Log[f]])])/(4*Sqrt[-e + c*Log[f]]) + (E^(c - (d + b*Log[f])^2/(4*(e + c*Log[f])))*f^a*Sqrt[Pi]*Erfi[(d + b*Log[f] + 2*x*(e + c*Log[f]))/(2*Sqrt[e + c*Log[f]])])/(4*Sqrt[e + c*Log[f]])}
{f^(a + b*x + c*x^2)*Cosh[c + d*x + e*x^2], x, 9, -((E^(-c + (d - b*Log[f])^2/(4*(e - c*Log[f])))*f^a*Sqrt[Pi]*Erfi[(d - b*Log[f] + 2*x*(e - c*Log[f]))/(2*Sqrt[-e + c*Log[f]])])/(4*Sqrt[-e + c*Log[f]])) + (E^(c - (d + b*Log[f])^2/(4*(e + c*Log[f])))*f^a*Sqrt[Pi]*Erfi[(d + b*Log[f] + 2*x*(e + c*Log[f]))/(2*Sqrt[e + c*Log[f]])])/(4*Sqrt[e + c*Log[f]])}


(* Integrands of the form E^(a+b*x^n)*Trig[c+d*x]^m where m and n are integers *)
{E^(x^2)*Sinh[a + b*x], x, 7, (-(1/4))*E^(-a - b^2/4)*Sqrt[Pi]*Erfi[(1/2)*(-b + 2*x)] + (1/4)*E^(a - b^2/4)*Sqrt[Pi]*Erfi[(1/2)*(b + 2*x)]}
{E^(x^2)*Cosh[a + b*x], x, 7, (1/4)*E^(-a - b^2/4)*Sqrt[Pi]*Erfi[(1/2)*(-b + 2*x)] + (1/4)*E^(a - b^2/4)*Sqrt[Pi]*Erfi[(1/2)*(b + 2*x)]}


(* ::Subsection::Closed:: *)
(*Integrands involving exponentials of hyperbolic functions*)


(* Integrands of the form E^(n*Sinh[a+b*x])*Sinh[2*(a+b*x)] *)
{E^(n*Sinh[a+b*x])*Sinh[2*a+2*b*x], x, 4, -((2*E^(n*Sinh[a + b*x]))/(b*n^2)) + (2*E^(n*Sinh[a + b*x])*Sinh[a + b*x])/(b*n)}
{E^(n*Sinh[a+b*x])*Sinh[2*(a+b*x)], x, 4, -((2*E^(n*Sinh[a + b*x]))/(b*n^2)) + (2*E^(n*Sinh[a + b*x])*Sinh[a + b*x])/(b*n)}
{E^(n*Sinh[a/2+b/2*x])*Sinh[a+b*x], x, 4, -((4*E^(n*Sinh[a/2 + (b*x)/2]))/(b*n^2)) + (4*E^(n*Sinh[a/2 + (b*x)/2])*Sinh[a/2 + (b*x)/2])/(b*n)}
{E^(n*Sinh[(a+b*x)/2])*Sinh[a+b*x], x, 4, -((4*E^(n*Sinh[a/2 + (b*x)/2]))/(b*n^2)) + (4*E^(n*Sinh[a/2 + (b*x)/2])*Sinh[a/2 + (b*x)/2])/(b*n)}


(* Integrands of the form E^(n*Cosh[a+b*x])*Sinh[2*(a+b*x)] *)
{E^(n*Cosh[a+b*x])*Sinh[2*a+2*b*x], x, 4, -((2*E^(n*Cosh[a + b*x]))/(b*n^2)) + (2*E^(n*Cosh[a + b*x])*Cosh[a + b*x])/(b*n)}
{E^(n*Cosh[a+b*x])*Sinh[2*(a+b*x)], x, 4, -((2*E^(n*Cosh[a + b*x]))/(b*n^2)) + (2*E^(n*Cosh[a + b*x])*Cosh[a + b*x])/(b*n)}
{E^(n*Cosh[a/2+b/2*x])*Sinh[a+b*x], x, 4, -((4*E^(n*Cosh[a/2 + (b*x)/2]))/(b*n^2)) + (4*E^(n*Cosh[a/2 + (b*x)/2])*Cosh[a/2 + (b*x)/2])/(b*n)}
{E^(n*Cosh[(a+b*x)/2])*Sinh[a+b*x], x, 4, -((4*E^(n*Cosh[a/2 + (b*x)/2]))/(b*n^2)) + (4*E^(n*Cosh[a/2 + (b*x)/2])*Cosh[a/2 + (b*x)/2])/(b*n)}


(* Integrands of the form E^(n*Cosh[a+b*x])*Sinh[a+b*x] *)
{E^(n*Cosh[a+b*x])*Sinh[a+b*x], x, 2, E^(n*Cosh[a + b*x])/(b*n)}
{E^(n*Cosh[a*c+b*c*x])*Sinh[c*(a+b*x)], x, 2, E^(n*Cosh[c*(a + b*x)])/(b*c*n)}
{E^(n*Cosh[c*(a+b*x)])*Sinh[a*c+b*c*x], x, 2, E^(n*Cosh[a*c + b*c*x])/(b*c*n)}


(* Integrands of the form E^(n*Sinh[a+b*x])*Cosh[a+b*x] *)
{E^(n*Sinh[a+b*x])*Cosh[a+b*x], x, 2, E^(n*Sinh[a + b*x])/(b*n)}
{E^(n*Sinh[a*c+b*c*x])*Cosh[c*(a+b*x)], x, 2, E^(n*Sinh[c*(a + b*x)])/(b*c*n)}
{E^(n*Sinh[c*(a+b*x)])*Cosh[a*c+b*c*x], x, 2, E^(n*Sinh[a*c + b*c*x])/(b*c*n)}


(* Integrands of the form E^(n*Cosh[a+b*x])*Sinh[a+b*x] *)
{E^(n*Cosh[a+b*x])*Tanh[a+b*x], x, 2, ExpIntegralEi[n*Cosh[a + b*x]]/b}
{E^(n*Cosh[a*c+b*c*x])*Tanh[c*(a+b*x)], x, 2, ExpIntegralEi[n*Cosh[c*(a + b*x)]]/(b*c)}
{E^(n*Cosh[c*(a+b*x)])*Tanh[a*c+b*c*x], x, 2, ExpIntegralEi[n*Cosh[a*c + b*c*x]]/(b*c)}


(* Integrands of the form E^(n*Sinh[a+b*x])*Cosh[a+b*x] *)
{E^(n*Sinh[a+b*x])*Coth[a+b*x], x, 2, ExpIntegralEi[n*Sinh[a + b*x]]/b}
{E^(n*Sinh[a*c+b*c*x])*Coth[c*(a+b*x)], x, 2, ExpIntegralEi[n*Sinh[c*(a + b*x)]]/(b*c)}
{E^(n*Sinh[c*(a+b*x)])*Coth[a*c+b*c*x], x, 2, ExpIntegralEi[n*Sinh[a*c + b*c*x]]/(b*c)}


(* ::Subsection:: *)
(*Integrands involving hyperbolic functions of exponentials*)


(* ::Section::Closed:: *)
(*Problems from Calculus textbooks*)


(* ::Subsection::Closed:: *)
(*Anton Calculus, 4th Edition*)


{1/(E^x*Sqrt[1 - E^(-2*x)]), x, 2, -ArcSin[E^(-x)]}
{E^x/(4 + E^(2*x)), x, 2, ArcTan[E^x/2]/2}
{E^x/(1 - E^(2*x)), x, 2, ArcTanh[E^x]}
{E^x/(3 - 4*E^(2*x)), x, 2, ArcTanh[(2*E^x)/Sqrt[3]]/(2*Sqrt[3])}
{E^x*Sqrt[3 - 4*E^(2*x)], x, 3, (1/2)*E^x*Sqrt[3 - 4*E^(2*x)] + (3/4)*ArcSin[(2*E^x)/Sqrt[3]]}
{E^x^2*x^3, x, 3, -(E^x^2/2) + (1/2)*E^x^2*x^2}
{E^x*Sqrt[1 - E^(2*x)], x, 3, (1/2)*E^x*Sqrt[1 - E^(2*x)] + ArcSin[E^x]/2}
{E^x/Sqrt[1 + E^x + E^(2*x)], x, 2, ArcSinh[(1 + 2*E^x)/Sqrt[3]]}
{E^x/(-4 + E^(2*x)), x, 2, -ArcTanh[E^x/2]/2}


(* ::Subsection::Closed:: *)
(*Apostol Calculus, Volume 1, 2nd Edition, Section 6.17*)


{E^Sqrt[x], x, 3, -2*E^Sqrt[x] + 2*E^Sqrt[x]*Sqrt[x]}
{E^x/(1 + E^(2*x)), x, 2, ArcTan[E^x]}


(* ::Subsection::Closed:: *)
(*Ayres Calculus, 1964 edition*)


{E^(2 - x^2)*x, x, 2, -E^(2 - x^2)/2}
{E^x - x^E, x, 3, E^x - x^(1 + E)/(1 + E)}
{(-1 + E^(2*x))/(3 + E^(2*x)), x, 5, -(x/3) + (2/3)*Log[3 + E^(2*x)], (-(1/6))*Log[E^(2*x)] + (2/3)*Log[3 + E^(2*x)]}
{E^x/Sqrt[1 - E^(2*x)], x, 2, ArcSin[E^x]}
{E^(2*x)/(1 + E^(4*x)), x, 2, ArcTan[E^(2*x)]/2}
{(-3*E^x + E^(2*x))^(-1), x, 4, 1/(E^x*3) - x/9 + (1/9)*Log[-3 + E^x]}
{(E^x*(-2 + E^x))/(1 + E^x), x, 4, E^x - 3*Log[1 + E^x]}


(* ::Subsection::Closed:: *)
(*Edwards and Penney Calculus*)


{E^x/(-1 + E^(2*x)), x, 2, -ArcTanh[E^x]}
{E^x/(1 + E^(2*x)), x, 2, ArcTan[E^x]}
{(E^(-x) + E^x)/(-E^(-x) + E^x), x, 2, Log[-E^(-x) + E^x]}
{(-E^(-x) + E^x)/(E^(-x) + E^x), x, 2, Log[E^(-x) + E^x]}
{(E^(-2*x) + E^(2*x))/(-E^(-2*x) + E^(2*x)), x, 2, (1/2)*Log[-E^(-2*x) + E^(2*x)]}
{E^x/Sqrt[1 + E^(2*x)], x, 2, ArcSinh[E^x]}
{E^Sqrt[4 + x]/Sqrt[4 + x], x, 3, 2*E^Sqrt[4 + x]}
{x/Sqrt[-1 + E^(2*x^2)], x, 2, ArcTan[Sqrt[-1 + E^(2*x^2)]]/2}
{E^x*Sqrt[9 + E^(2*x)], x, 3, (1/2)*E^x*Sqrt[9 + E^(2*x)] + (9/2)*ArcSinh[E^x/3]}
{E^x*Sqrt[1 + E^(2*x)], x, 3, (1/2)*E^x*Sqrt[1 + E^(2*x)] + ArcSinh[E^x]/2}
{(E^x^2*x)/(1 + E^(2*x^2)), x, 3, ArcTan[E^x^2]/2}
{(E^Sqrt[Sin[x]]*Cos[x])/Sqrt[Sin[x]], x, 3, 2*E^Sqrt[Sin[x]]}
{E^x^(3/2)*x^2, x, 4, (-(2/3))*E^x^(3/2) + (2/3)*E^x^(3/2)*x^(3/2)}


(* ::Subsection::Closed:: *)
(*Grossman Calculus*)


{E^x/Sqrt[-3 + E^(2*x)], x, 2, ArcTanh[E^x/Sqrt[-3 + E^(2*x)]]}
{E^x/(16 - E^(2*x)), x, 2, ArcTanh[E^x/4]/4}
{E^(5*x)/(1 + E^(10*x)), x, 2, ArcTan[E^(5*x)]/5}
{E^(4*x)/Sqrt[16 + E^(8*x)], x, 2, ArcSinh[E^(4*x)/4]/4}
{E^(4*x^3)*x^2*Cos[7*x^3], x, 2, (4/195)*E^(4*x^3)*Cos[7*x^3] + (7/195)*E^(4*x^3)*Sin[7*x^3]}


(* ::Subsection::Closed:: *)
(*Hughes, Hallet, Gleason, et al Calculus, 2nd Edition*)


{E^(1 + x^2)*x, x, 2, E^(1 + x^2)/2}
{E^(1 + x^3)*x^2, x, 2, E^(1 + x^3)/3}
{E^Sqrt[x]/Sqrt[x], x, 2, 2*E^Sqrt[x]}
{E^x^(1/3)/x^(2/3), x, 2, 3*E^x^(1/3)}
{E^(3*x)*(-8 + 2*x^3 + x^5), x, 13, -((724*E^(3*x))/243) + (76/81)*E^(3*x)*x - (38/27)*E^(3*x)*x^2 + (38/27)*E^(3*x)*x^3 - (5/9)*E^(3*x)*x^4 + (1/3)*E^(3*x)*x^5}
{(E^x + x)^2, x, 6, -2*E^x + E^(2*x)/2 + 2*E^x*x + x^3/3}


(* ::Subsection::Closed:: *)
(*Spivak Calculus*)


{(E^x + E^(2*x) + E^(3*x))/E^(4*x), x, 5, -(1/3)/E^(3*x) - 1/(E^(2*x)*2) - E^(-x)}
{E^x/(1 + 2*E^x + E^(2*x)), x, 3, -(1 + E^x)^(-1)}
{E^Sin[x]*Sec[x]^2*(x*Cos[x]^3 - Sin[x]), x, -7, E^Sin[x]*(-1 + x*Cos[x])*Sec[x]}


(* ::Subsection::Closed:: *)
(*Stewart Calculus*)


{Cos[3*x]/E^x, x, 1, ((-(1/10))*Cos[3*x])/E^x + ((3/10)*Sin[3*x])/E^x}
{E^(2*x)/(2 + 3*E^x + E^(2*x)), x, 5, -Log[1 + E^x] + 2*Log[2 + E^x]}
{E^(2*x)/(1 + E^x), x, 4, E^x - Log[1 + E^x]}
{E^(3*x)*Cos[5*x], x, 1, (3/34)*E^(3*x)*Cos[5*x] + (5/34)*E^(3*x)*Sin[5*x]}
{E^x*Sech[E^x], x, 2, ArcTan[Sinh[E^x]]}
{1/(E^x*(1 + 2*E^x)), x, 4, -E^(-x) + 2*Log[2 + E^(-x)]}
{E^x*Cos[4 + 3*x], x, 1, (1/10)*E^x*Cos[4 + 3*x] + (3/10)*E^x*Sin[4 + 3*x]}


(* ::Subsection::Closed:: *)
(*Thomas Calculus, 8th Edition*)


{E^x*Sec[1 - E^x]^3, x, 3, (-(1/2))*ArcTanh[Sin[1 - E^x]] - (1/2)*Sec[1 - E^x]*Tan[1 - E^x]}
{(E^(-x) + E^x)*x, x, 6, -E^(-x) - E^x - x/E^x + E^x*x}
{E^x/(2 + 3*E^x + E^(2*x)), x, 2, -2*ArcTanh[3 + 2*E^x]}
{E^(2*x)/(1 + E^x)^(1/3), x, 3, (-(9/10))*(1 + E^x)^(2/3) + (3/5)*E^x*(1 + E^x)^(2/3)}
{E^(2*x)/(1 + E^x)^(1/4), x, 3, (-16/21)*(1 + E^x)^(3/4) + (4/7)*E^x*(1 + E^x)^(3/4)}
{(-E^x + 2*E^(2*x))/Sqrt[-1 - 6*E^x + 3*E^(2*x)], x, 3, (2/3)*Sqrt[-1 - 6*E^x + 3*E^(2*x)] - ArcTanh[(Sqrt[3]*(1 - E^x))/Sqrt[-1 - 6*E^x + 3*E^(2*x)]]/Sqrt[3]}


(* ::Section::Closed:: *)
(*Problems from integration competitions*)


(* ::Subsection::Closed:: *)
(*MIT Integration Competition*)


{E^x*(-5*x + x^2), x, 7, 7*E^x - 7*E^x*x + E^x*x^2}
{E^(3*x)*(-x + x^2), x, 7, (5*E^(3*x))/27 - (5/9)*E^(3*x)*x + (1/3)*E^(3*x)*x^2}


(* ::Subsection::Closed:: *)
(*University of Wisconsin Integration Competition*)


{E^(Cos[x]^2 + Sin[x]^2), x, 2, E*x}
{E^x^x*x^(2*x)*(1 + Log[x]), x, -3, E^x^x*(-1 + x^x)}
{(E^(5*x) + E^(7*x))/(E^(-x) + E^x), x, 2, E^(6*x)/6}
{x^(-2 - x^(-1))*(1 - Log[x]), x, -3, -x^(-x^(-1))}


(* ::Section::Closed:: *)
(*Miscellaneous problems*)


(*  Problems contributed by Michael Wester *)

(* => 1/[2 m sqrt (10)] log ([-5 + e^(m x) sqrt (10)]/[-5 - e^(m x) sqrt (10)])
      [Gradshteyn and Ryzhik 2.314] *)
{1/(-5/E^(m*x) + 2*E^(m*x)), x, 2, -(ArcTanh[Sqrt[2/5]*E^(m*x)]/(Sqrt[10]*m))}


{E^(6*x)*Sin[3*x], x, 1, (-(1/15))*E^(6*x)*Cos[3*x] + (2/15)*E^(6*x)*Sin[3*x]}
{E^(3*x)/(1 + E^(2*x)), x, 4, E^x - ArcTan[E^x]}
{E^(3*x)/(-1 + E^(2*x)), x, 4, E^x - ArcTanh[E^x]}
{E^(4 + Sin[x])*Cos[x], x, 2, E^(4 + Sin[x])}
{1/(E^x*Sqrt[1 + E^(2*x)]), x, 2, -(Sqrt[1 + E^(2*x)]/E^x)}


{E^x/(-1 - 8*E^x + E^(2*x)), x, 2, ArcTanh[(4 - E^x)/Sqrt[17]]/Sqrt[17]}
{E^(7*x)*x^3, x, 4, -((6*E^(7*x))/2401) + (6/343)*E^(7*x)*x - (3/49)*E^(7*x)*x^2 + (1/7)*E^(7*x)*x^3}
{E^(8 - 2*x)*x^3, x, 4, (-(3/8))*E^(8 - 2*x) - (3/4)*E^(8 - 2*x)*x - (3/4)*E^(8 - 2*x)*x^2 - (1/2)*E^(8 - 2*x)*x^3}
{E^x*Sqrt[9 - E^(2*x)], x, 3, (1/2)*E^x*Sqrt[9 - E^(2*x)] + (9/2)*ArcSin[E^x/3]}
{E^(6*x)*Sqrt[9 - E^(2*x)], x, 4, (-(216/35))*(9 - E^(2*x))^(3/2) - (36/35)*E^(2*x)*(9 - E^(2*x))^(3/2) - (1/7)*E^(4*x)*(9 - E^(2*x))^(3/2)}
{E^(6*x)/(9 - E^x)^(5/2), x, 7, -(10077696/(7*(9 - E^x)^(3/2))) + (1679616*E^x)/(7*(9 - E^x)^(3/2)) - (46656*E^(2*x))/(7*(9 - E^x)^(3/2)) - (864*E^(3*x))/(7*(9 - E^x)^(3/2)) - (36*E^(4*x))/(7*(9 - E^x)^(3/2)) - (2*E^(5*x))/(7*(9 - E^x)^(3/2))}
{(2 - 7*E^x^4)^5*x^3, x, 8, -140*E^x^4 + 490*E^(2*x^4) - (3430*E^(3*x^4))/3 + (12005*E^(4*x^4))/8 - (16807*E^(5*x^4))/20 + 8*x^4}
{E^x^2*Sqrt[1 - E^(2*x^2)]*x, x, 4, (1/4)*E^x^2*Sqrt[1 - E^(2*x^2)] + (1/4)*ArcSin[E^x^2]}
{E^x^3*(1 - E^(4*x^3))^2*x^2, x, 6, E^x^3/3 - (2*E^(5*x^3))/15 + E^(9*x^3)/27}
{E^(E^x + x), x, 2, E^E^x}
{E^(E^E^x + E^x + x), x, 3, E^E^E^x}


{(E^(-x) + E^x)^2, x, 4, -(1/2)/E^(2*x) + E^(2*x)/2 + 2*x}
{1/(E^(-x) + E^x), x, 2, ArcTan[E^x]}
{1/(E^(-x) + E^x)^2, x, 3, -1/(2*(1 + E^(2*x)))}


{1/(-E^(-x) + E^x), x, 2, -ArcTanh[E^x]}
{1/(-E^(-x) + E^x)^2, x, 3, 1/(2*(1 - E^(2*x)))}


{E^x*(-E^(-x) + E^x)^2, x, 5, -E^(-x) - 2*E^x + E^(3*x)/3}
{E^x*(-E^(-x) + E^x)^3, x, 5, 1/(E^(2*x)*2) - (3*E^(2*x))/2 + E^(4*x)/4 + 3*x}


{(1 + 4^x)/(1 + 2^x), x, 4, x + 2^x/Log[2] - (2*Log[1 + 2^x])/Log[2]}
{(1 + 4^x)/(1 + 2^(-x)), x, 5, -(2^x/Log[2]) + 4^x/Log[4] + (2*Log[1 + 2^x])/Log[2]}

{E^(a + x)^2/x^2 - (2*a*E^(a + x)^2)/x, x, 6, -(E^(a + x)^2/x) + Sqrt[Pi]*Erfi[a + x]}
{(x^4 + x^6 + x^8)/E^x^2, x, 14, ((-(147/16))*x)/E^x^2 - ((49/8)*x^3)/E^x^2 - ((9/4)*x^5)/E^x^2 - ((1/2)*x^7)/E^x^2 + (147/32)*Sqrt[Pi]*Erf[x]}

{(E^x*(-5 + x + x^2))/(-1 + x)^2, x, 8, E^x - (3*E^x)/(1 - x)}
{(E^x*x)/(1 + x)^2, x, 7, E^x/(1 + x)}

{(-E^x + E^(3*x))^(-1), x, 5, E^(-x) - ArcTanh[E^x]}
{(E^x^2*x^3)/(1 + x^2)^2, x, 8, E^x^2/(2*(1 + x^2))}
{E^(3*x)/Sqrt[25 + 16*E^(2*x)], x, 3, (1/32)*E^x*Sqrt[25 + 16*E^(2*x)] - (25/128)*ArcSinh[(4*E^x)/5]}

(* {E^(a + b*x + c*x^2)/(d + e*x)^2, x, 0} *)
{(1 + E^x)/Sqrt[E^x + x], x, 2, 2*Sqrt[E^x + x]}
{(1 + E^x)/(E^x + x), x, 2, Log[E^x + x]}
{E^x^2/x^2, x, 2, -(E^x^2/x) + Sqrt[Pi]*Erfi[x]}
{(E^x^2*(1 + 4*x^4))/x^2, x, 6, -(E^x^2/x) + 2*E^x^2*x}

{Sqrt[f^x]*(a + b*x)^2, x, 5, (2*Sqrt[f^x]*(8*b^2 - (a + b*x)*Log[f]*(4*b - (a + b*x)*Log[f])))/Log[f]^3}

{3^(1 + x^2)*x, x, 2, 3^(1 + x^2)/(2*Log[3])}
{2^Sqrt[x]/Sqrt[x], x, 2, 2^(1 + Sqrt[x])/Log[2]}
{2^x^(-1)/x^2, x, 2, -(2^x^(-1)/Log[2])}
{2^(-x) + 2^x, x, 3, -(1/(2^x*Log[2])) + 2^x/Log[2]}
{(2 - 3*x + x^2)/E^(4*x), x, 8, -(11/32)/E^(4*x) + ((5/8)*x)/E^(4*x) - ((1/4)*x^2)/E^(4*x)}
{k^(x/2) + x^Sqrt[k], x, 3, x^(1 + Sqrt[k])/(1 + Sqrt[k]) + (2*k^(x/2))/Log[k]}
{10^Sqrt[x]/Sqrt[x], x, 2, (2^(1 + Sqrt[x])*5^Sqrt[x])/Log[10]}


(* Problems requiring simplification of irreducible integrands *)
{((1 + E^x)*x)/Sqrt[E^x + x] + 2*Sqrt[E^x + x], x, 2, 2*x*Sqrt[E^x + x]}
{x/Sqrt[E^x + x] + (E^x*x)/Sqrt[E^x + x] + 2*Sqrt[E^x + x], x, 4, 2*x*Sqrt[E^x + x]}
{((1 + E^x)*x)/Sqrt[E^x + x], x, 1, 2*x*Sqrt[E^x + x] - 2*Int[Sqrt[E^x + x], x]}
{x/Sqrt[E^x + x] + (E^x*x)/Sqrt[E^x + x], x, 4, 2*x*Sqrt[E^x + x] - 2*Int[Sqrt[E^x + x], x]}
{x*E^x/Sqrt[E^x + x], x, 2, 2*Sqrt[E^x + x] + 2*x*Sqrt[E^x + x] - Int[1/Sqrt[E^x + x], x] - 3*Int[Sqrt[E^x + x], x]}

{(x^2*(5*E^x + 3*x^2))/(5*Sqrt[5*E^x + x^3]) + (4/5)*x*Sqrt[5*E^x + x^3], x, 2, (2/5)*x^2*Sqrt[5*E^x + x^3]}
{x^2*E^x/Sqrt[5*E^x + x^3], x, 1, (2/5)*x^2*Sqrt[5*E^x + x^3] - (3/5)*Int[x^4/Sqrt[5*E^x + x^3], x] - (4/5)*Int[x*Sqrt[5*E^x + x^3], x]}

{-((1 + E^x)/(E^x + x)^(1/3)), x, 3, (-(3/2))*(E^x + x)^(2/3)}
{-(1/(E^x + x)^(1/3)) + x/(E^x + x)^(1/3) - (E^x + x)^(2/3), x, 2, (-(3/2))*(E^x + x)^(2/3)}
{x/(E^x + x)^(1/3), x, 1, (-(3/2))*(E^x + x)^(2/3) + Int[1/(E^x + x)^(1/3), x] + Int[(E^x + x)^(2/3), x]}

{(5*x + E^x*(3 + 2*x))/(E^x + x)^(1/3), x, 8, 3*x*(E^x + x)^(2/3)}
{(2*x)/(E^x + x)^(1/3) + (2*E^x*x)/(E^x + x)^(1/3) + 3*(E^x + x)^(2/3), x, 4, 3*x*(E^x + x)^(2/3)}


(* The substitution u=E^x will lead to a Log[E^x] term in antiderivative. *)
{E^x*(-E^(-x) + E^x)*(E^(-x) + E^x)^2, x, 3, 1/(E^(2*x)*2) + E^(2*x)/2 + E^(4*x)/4 - x, 1/(E^(2*x)*2) + E^(2*x)/2 + E^(4*x)/4 - Log[E^x]}


(* Unwise expansion leads to infinite recursion *)
{x/(E^x + x), x, 0, Int[x/(E^x + x), x]}
{E^x/(E^x + x), x, 2, x - Int[x/(E^x + x), x]}
{E^x/(E^x + x^2), x, 2, x - Int[x^2/(E^x + x^2), x]}

{f[x]/(f[x] + x), x, 2, x - Int[x/(x + f[x]), x]}
{f[x]/(f[x] + x^2), x, 2, x - Int[x^2/(x^2 + f[x]), x]}
{f[x]/(f[x] + x)^2, x, 2, -Int[x/(x + f[x])^2, x] + Int[1/(x + f[x]), x]}
{f[x]/(f[x] + x^2)^2, x, 2, -Int[x^2/(x^2 + f[x])^2, x] + Int[1/(x^2 + f[x]), x]}
