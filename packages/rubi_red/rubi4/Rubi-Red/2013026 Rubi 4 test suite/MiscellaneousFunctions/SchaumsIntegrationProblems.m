(* ::Package:: *)

(* ::Subsubsection::Closed:: *)
(*14.59 - 14.65		x^m/(a*x + b)*)


{1/(a*x + b), x, 1, Log[b + a*x]/a}
{x/(a*x + b), x, 3, x/a - (b*Log[b + a*x])/a^2}
{x^2/(a*x + b), x, 4, -((b*x)/a^2) + x^2/(2*a) + (b^2*Log[b + a*x])/a^3}
{x^3/(a*x + b), x, 4, (b^2*x)/a^3 - (b*x^2)/(2*a^2) + x^3/(3*a) - (b^3*Log[b + a*x])/a^4}
{1/(x*(a*x + b)), x, 4, Log[x]/b - Log[b + a*x]/b}
{1/(x^2*(a*x + b)), x, 4, -(1/(b*x)) - (a*Log[x])/b^2 + (a*Log[b + a*x])/b^2}
{1/(x^3*(a*x + b)), x, 4, -(1/(2*b*x^2)) + a/(b^2*x) + (a^2*Log[x])/b^3 - (a^2*Log[b + a*x])/b^3}


(* ::Subsubsection::Closed:: *)
(*14.66 - 14.72		x^m/(a*x + b)^2*)


{1/(a*x + b)^2, x, 1, -(1/(a*(b + a*x)))}
{x/(a*x + b)^2, x, 4, b/(a^2*(b + a*x)) + Log[b + a*x]/a^2}
{x^2/(a*x + b)^2, x, 4, x/a^2 - b^2/(a^3*(b + a*x)) - (2*b*Log[b + a*x])/a^3}
{x^3/(a*x + b)^2, x, 5, -((2*b*x)/a^3) + x^2/(2*a^2) + b^3/(a^4*(b + a*x)) + (3*b^2*Log[b + a*x])/a^4}
{1/(x*(a*x + b)^2), x, 5, 1/(b*(b + a*x)) + Log[x]/b^2 - Log[b + a*x]/b^2}
{1/(x^2*(a*x + b)^2), x, 5, -(1/(b^2*x)) - a/(b^2*(b + a*x)) - (2*a*Log[x])/b^3 + (2*a*Log[b + a*x])/b^3}
{1/(x^3*(a*x + b)^2), x, 5, -(1/(2*b^2*x^2)) + (2*a)/(b^3*x) + a^2/(b^3*(b + a*x)) + (3*a^2*Log[x])/b^4 - (3*a^2*Log[b + a*x])/b^4}


(* ::Subsubsection::Closed:: *)
(*14.73 - 14.79		x^m/(a*x + b)^3*)


{1/(a*x + b)^3, x, 1, -(1/(2*a*(b + a*x)^2))}
{x/(a*x + b)^3, x, 1, x^2/(2*b*(b + a*x)^2)}
{x^2/(a*x + b)^3, x, 5, -(b^2/(2*a^3*(b + a*x)^2)) + (2*b)/(a^3*(b + a*x)) + Log[b + a*x]/a^3}
{x^3/(a*x + b)^3, x, 5, x/a^3 + b^3/(2*a^4*(b + a*x)^2) - (3*b^2)/(a^4*(b + a*x)) - (3*b*Log[b + a*x])/a^4}
{1/(x*(a*x + b)^3), x, 6, 1/(2*b*(b + a*x)^2) + 1/(b^2*(b + a*x)) + Log[x]/b^3 - Log[b + a*x]/b^3}
{1/(x^2*(a*x + b)^3), x, 6, -(1/(b^3*x)) - a/(2*b^2*(b + a*x)^2) - (2*a)/(b^3*(b + a*x)) - (3*a*Log[x])/b^4 + (3*a*Log[b + a*x])/b^4}
{1/(x^3*(a*x + b)^3), x, 6, -(1/(2*b^3*x^2)) + (3*a)/(b^4*x) + a^2/(2*b^3*(b + a*x)^2) + (3*a^2)/(b^4*(b + a*x)) + (6*a^2*Log[x])/b^5 - (6*a^2*Log[b + a*x])/b^5}


(* ::Subsubsection::Closed:: *)
(*14.80 - 14.83		x^m*(a*x + b)^n*)


{(a*x + b)^n, x, 1, (b + a*x)^(1 + n)/(a*(1 + n))}
{x*(a*x + b)^n, x, 2, -((b*(b + a*x)^(1 + n))/(a^2*(1 + n)*(2 + n))) + (x*(b + a*x)^(1 + n))/(a*(2 + n))}
{x^2*(a*x + b)^n, x, 3, (2*b^2*(b + a*x)^(1 + n))/(a^3*(1 + n)*(2 + n)*(3 + n)) - (2*b*x*(b + a*x)^(1 + n))/(a^2*(2 + n)*(3 + n)) + (x^2*(b + a*x)^(1 + n))/(a*(3 + n))}
{x^m*(a*x + b)^n, x, 0, Int[x^m*(b + a*x)^n, x]}


(* ::Subsubsection::Closed:: *)
(*14.84 - 14.88		x^m/Sqrt[a*x + b]*)


{1/Sqrt[a*x + b], x, 1, (2*Sqrt[b + a*x])/a}
{x/Sqrt[a*x + b], x, 2, -((4*b*Sqrt[b + a*x])/(3*a^2)) + (2*x*Sqrt[b + a*x])/(3*a)}
{x^2/Sqrt[a*x + b], x, 3, (16*b^2*Sqrt[b + a*x])/(15*a^3) - (8*b*x*Sqrt[b + a*x])/(15*a^2) + (2*x^2*Sqrt[b + a*x])/(5*a)}
{1/(x*Sqrt[a*x + b]), x, 1, -((2*ArcTanh[Sqrt[b + a*x]/Sqrt[b]])/Sqrt[b])}
{1/(x^2*Sqrt[a*x + b]), x, 2, -(Sqrt[b + a*x]/(b*x)) + (a*ArcTanh[Sqrt[b + a*x]/Sqrt[b]])/b^(3/2)}


(* ::Subsubsection::Closed:: *)
(*14.89 - 14.93		x^m*Sqrt[a*x + b]*)


{Sqrt[a*x + b], x, 1, (2*(b + a*x)^(3/2))/(3*a)}
{x*Sqrt[a*x + b], x, 2, -((4*b*(b + a*x)^(3/2))/(15*a^2)) + (2*x*(b + a*x)^(3/2))/(5*a)}
{x^2*Sqrt[a*x + b], x, 3, (16*b^2*(b + a*x)^(3/2))/(105*a^3) - (8*b*x*(b + a*x)^(3/2))/(35*a^2) + (2*x^2*(b + a*x)^(3/2))/(7*a)}
{Sqrt[a*x + b]/x, x, 2, 2*Sqrt[b + a*x] - 2*Sqrt[b]*ArcTanh[Sqrt[b + a*x]/Sqrt[b]]}
{Sqrt[a*x + b]/x^2, x, 2, -(Sqrt[b + a*x]/x) - (a*ArcTanh[Sqrt[b + a*x]/Sqrt[b]])/Sqrt[b]}


(* ::Subsubsection::Closed:: *)
(*14.94 - 14.98		x^m*Sqrt[a*x + b]*)


{x^m/Sqrt[a*x + b], x, 1, (2*Subst[Int[(-(b/a) + x^2/a)^m, x], x, Sqrt[b + a*x]])/a}
{1/(x^m*Sqrt[a*x + b]), x, 1, (2*Subst[Int[(-(b/a) + x^2/a)^(-m), x], x, Sqrt[b + a*x]])/a}
{x^m*Sqrt[a*x + b], x, 2, (2*x^(1 + m)*Sqrt[b + a*x])/(3 + 2*m) + (2*b*Subst[Int[(-(b/a) + x^2/a)^m, x], x, Sqrt[b + a*x]])/(a*(3 + 2*m))}
{Sqrt[a*x + b]/x^m, x, 2, (2*x^(1 - m)*Sqrt[b + a*x])/(3 - 2*m) + (2*b*Subst[Int[(-(b/a) + x^2/a)^(-m), x], x, Sqrt[b + a*x]])/(a*(3 - 2*m))}
{Sqrt[a*x + b]/x^m, x, 2, (2*x^(1 - m)*Sqrt[b + a*x])/(3 - 2*m) + (2*b*Subst[Int[(-(b/a) + x^2/a)^(-m), x], x, Sqrt[b + a*x]])/(a*(3 - 2*m))}


(* ::Subsubsection::Closed:: *)
(*14.99 - 14.104		x^n*(a*x + b)^(m/2)*)


{(a*x + b)^(m/2), x, 1, (2*(b + a*x)^(1 + m/2))/(a*(2 + m))}
{x*(a*x + b)^(m/2), x, 2, -((4*b*(b + a*x)^(1 + m/2))/(a^2*(2 + m)*(4 + m))) + (2*x*(b + a*x)^(1 + m/2))/(a*(4 + m))}
{x^2*(a*x + b)^(m/2), x, 3, (16*b^2*(b + a*x)^(1 + m/2))/(a^3*(2 + m)*(4 + m)*(6 + m)) - (8*b*x*(b + a*x)^(1 + m/2))/(a^2*(4 + m)*(6 + m)) + (2*x^2*(b + a*x)^(1 + m/2))/(a*(6 + m))}
{(a*x + b)^(m/2)/x, x, 0, Int[(b + a*x)^(m/2)/x, x]}
{(a*x + b)^(m/2)/x^2, x, 1, -((b + a*x)^(1 + m/2)/(b*x)) + (a*m*Int[(b + a*x)^(m/2)/x, x])/(2*b)}
{1/(x*(a*x + b)^(m/2)), x, 0, Int[1/((b + a*x)^(m/2)*x), x]}


(* ::Subsubsection:: *)
(*14.105 - 14.112	(a*x+b)^m (b*x+q)^n*)


{1/((a*x + b)*(p*x + q)), x, 0, 0}
{x/((a*x + b)*(p*x + q)), x, 0, 0}
{1/((a*x + b)^2*(p*x + q)), x, 0, 0}
{x/((a*x + b)^2*(p*x + q)), x, 0, 0}
{x^2/((a*x + b)^2*(p*x + q)), x, 0, 0}
{1/((a*x + b)^m*(p*x + q)^n), x, 0, 0}
{(a*x + b)/(p*x + q), x, 0, 0}
{(a*x + b)^m/(p*x + q)^n, x, 0, 0}

{(p*x + q)/Sqrt[a*x + b], x, 0, 0}
{1/((p*x + q)*Sqrt[a*x + b]), x, 0, 0}
{Sqrt[a*x + b]/(p*x + q), x, 0, 0}
{(p*x + q)^n*Sqrt[a*x + b], x, 0, 0}
{1/((p*x + q)^n*Sqrt[a*x + b]), x, 0, 0}
{(p*x + q)^n/Sqrt[a*x + b], x, 0, 0}
{Sqrt[a*x + b]/(p*x + q)^n, x, 0, 0}


(* ::Subsubsection:: *)
(*14.113 - 14.112	(a*x+b)^m (b*x+q)^n*)
