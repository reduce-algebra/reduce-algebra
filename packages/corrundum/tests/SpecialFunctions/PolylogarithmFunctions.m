(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving the Polylogarithm Function*)


(* ::Subsection::Closed:: *)
(*Integrands involving polylogarithm functions*)


{PolyLog[n, a*x^m]/x, x, 1, PolyLog[1 + n, a*x^m]/m}

{PolyLog[2, a*x^2], x, 4, -4*x + (4*ArcTanh[Sqrt[a]*x])/Sqrt[a] + 2*x*Log[1 - a*x^2] + x*PolyLog[2, a*x^2]}
{x*PolyLog[2, a*x^2], x, 4, -(x^2/2) - ((1 - a*x^2)*Log[1 - a*x^2])/(2*a) + (1/2)*x^2*PolyLog[2, a*x^2]}
{x^2*PolyLog[2, a*x^2], x, 7, -((4*x)/(9*a)) - (4*x^3)/27 + (4*ArcTanh[Sqrt[a]*x])/(9*a^(3/2)) + (2/9)*x^3*Log[1 - a*x^2] + (1/3)*x^3*PolyLog[2, a*x^2]}

{PolyLog[2, a+b*x], x, 5, -x - ((1 - a - b*x)*Log[1 - a - b*x])/b + (a/b + x)*PolyLog[2, a + b*x]}
{x*PolyLog[2, a+b*x], x, 11, -(x/(4*b)) + (3*a*x)/(4*b) - x^2/8 - ((1 - 4*a + 3*a^2)*Log[1 - a - b*x])/(4*b^2) - (a*x*Log[1 - a - b*x])/(2*b) + (1/4)*x^2*Log[1 - a - b*x] - (1/2)*(a^2/b^2 - x^2)*PolyLog[2, a + b*x]}
{x^2*PolyLog[2, a+b*x], x, 16, -(((1 - a)^2*x)/(9*b^2)) + (a*x)/(6*b^2) - (a^2*x)/(2*b^2) - x^2/(18*b) + (5*a*x^2)/(36*b) - x^3/27 - Log[1 - a - b*x]/(9*b^3) + (a*Log[1 - a - b*x])/(2*b^3) - (a*x^2*Log[1 - a - b*x])/(6*b) + (1/9)*x^3*Log[1 - a - b*x] - (a^2*(3 - (11*a)/6 - b*x)*Log[1 - a - b*x])/(3*b^3) + (1/3)*(a^3/b^3 + x^3)*PolyLog[2, a + b*x]}


{PolyLog[3/2, x], x, 2, Int[PolyLog[-(1/2), x], x] - x*PolyLog[1/2, x] + x*PolyLog[3/2, x]}
{PolyLog[1/2, x], x, 1, -Int[PolyLog[-(1/2), x], x] + x*PolyLog[1/2, x]}
{PolyLog[-1/2, x], x, 0, Int[PolyLog[-(1/2), x], x]}
{PolyLog[-3/2, x], x, 1, -Int[PolyLog[-(1/2), x], x] + x*PolyLog[-(1/2), x]}
{PolyLog[-5/2, x], x, 2, Int[PolyLog[-(1/2), x], x] + x*PolyLog[-(3/2), x] - x*PolyLog[-(1/2), x]}

{PolyLog[-3/2, x] + PolyLog[-2^(-1), x], x, 2, x*PolyLog[-(1/2), x]}


{PolyLog[n, c*f^(a + b*x)], x, 1, PolyLog[1 + n, c*f^(a + b*x)]/(b*Log[f])}
{x*PolyLog[n, c*f^(a + b*x)], x, 2, (x*PolyLog[1 + n, c*f^(a + b*x)])/(b*Log[f]) - PolyLog[2 + n, c*f^(a + b*x)]/(b^2*Log[f]^2)}
{x^2*PolyLog[n, c*f^(a + b*x)], x, 3, (x^2*PolyLog[1 + n, c*f^(a + b*x)])/(b*Log[f]) - (2*x*PolyLog[2 + n, c*f^(a + b*x)])/(b^2*Log[f]^2) + (2*PolyLog[3 + n, c*f^(a + b*x)])/(b^3*Log[f]^3)}

{(Log[x]*PolyLog[n, a*x])/x, x, 2, Log[x]*PolyLog[1 + n, a*x] - PolyLog[2 + n, a*x]}
{(Log[x]^2*PolyLog[n, a*x])/x, x, 3, Log[x]^2*PolyLog[1 + n, a*x] - 2*Log[x]*PolyLog[2 + n, a*x] + 2*PolyLog[3 + n, a*x]}
