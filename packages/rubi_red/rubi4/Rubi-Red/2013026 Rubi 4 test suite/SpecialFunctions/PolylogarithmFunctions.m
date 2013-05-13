(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving the Polylogarithm Function*)


(* ::Section::Closed:: *)
(*Integrands involving polylogarithms of algebraic functions*)


{PolyLog[n, a*x^m]/x, x, 1, PolyLog[1 + n, a*x^m]/m}

{PolyLog[2, a*x^2], x, 4, -4*x + (4*ArcTanh[Sqrt[a]*x])/Sqrt[a] + 2*x*Log[1 - a*x^2] + x*PolyLog[2, a*x^2]}
{x*PolyLog[2, a*x^2], x, 3, -(x^2/2) - ((1 - a*x^2)*Log[1 - a*x^2])/(2*a) + (1/2)*x^2*PolyLog[2, a*x^2]}
{x^2*PolyLog[2, a*x^2], x, 5, -((4*x)/(9*a)) - (4*x^3)/27 + (4*ArcTanh[Sqrt[a]*x])/(9*a^(3/2)) + (2/9)*x^3*Log[1 - a*x^2] + (1/3)*x^3*PolyLog[2, a*x^2]}

{PolyLog[2, a+b*x], x, 3, -x - ((1 - a - b*x)*Log[1 - a - b*x])/b + (a*PolyLog[2, a + b*x])/b + x*PolyLog[2, a + b*x]}
{x*PolyLog[2, a+b*x], x, 8, -(((1 - a)*x)/(4*b)) + (a*x)/(2*b) - x^2/8 - ((1 - a)^2*Log[1 - a - b*x])/(4*b^2) + (1/4)*x^2*Log[1 - a - b*x] + (a*(1 - a - b*x)*Log[1 - a - b*x])/(2*b^2) - (a^2*PolyLog[2, a + b*x])/(2*b^2) + (1/2)*x^2*PolyLog[2, a + b*x]}
{x^2*PolyLog[2, a+b*x], x, 11, -(((1 - a)^2*x)/(9*b^2)) + ((1 - a)*a*x)/(6*b^2) - (a^2*x)/(3*b^2) - ((1 - a)*x^2)/(18*b) + (a*x^2)/(12*b) - x^3/27 - ((1 - a)^3*Log[1 - a - b*x])/(9*b^3) + ((1 - a)^2*a*Log[1 - a - b*x])/(6*b^3) - (a*x^2*Log[1 - a - b*x])/(6*b) + (1/9)*x^3*Log[1 - a - b*x] - (a^2*(1 - a - b*x)*Log[1 - a - b*x])/(3*b^3) + (a^3*PolyLog[2, a + b*x])/(3*b^3) + (1/3)*x^3*PolyLog[2, a + b*x]}


{PolyLog[3/2, x], x, 2, Int[PolyLog[-(1/2), x], x] - x*PolyLog[1/2, x] + x*PolyLog[3/2, x]}
{PolyLog[1/2, x], x, 1, -Int[PolyLog[-(1/2), x], x] + x*PolyLog[1/2, x]}
{PolyLog[-1/2, x], x, 0, Int[PolyLog[-(1/2), x], x]}
{PolyLog[-3/2, x], x, 1, -Int[PolyLog[-(1/2), x], x] + x*PolyLog[-(1/2), x]}
{PolyLog[-5/2, x], x, 2, Int[PolyLog[-(1/2), x], x] + x*PolyLog[-(3/2), x] - x*PolyLog[-(1/2), x]}

{PolyLog[-3/2, x] + PolyLog[-2^(-1), x], x, 2, x*PolyLog[-(1/2), x]}


{PolyLog[n, e*((a + b*x)/(c + d*x))^n]/((a + b*x)*(c + d*x)), x, 1, PolyLog[1 + n, e*((a + b*x)/(c + d*x))^n]/((b*c - a*d)*n)}

{PolyLog[3, e*((a + b*x)/(c + d*x))^n]/((a + b*x)*(c + d*x)), x, 1, PolyLog[4, e*((a + b*x)/(c + d*x))^n]/(n*(b*c - a*d))}
{PolyLog[2, e*((a + b*x)/(c + d*x))^n]/((a + b*x)*(c + d*x)), x, 1, PolyLog[3, e*((a + b*x)/(c + d*x))^n]/(n*(b*c - a*d))}
{PolyLog[1, e*((a + b*x)/(c + d*x))^n]/((a + b*x)*(c + d*x)), x, 1, PolyLog[2, e*((a + b*x)/(c + d*x))^n]/(n*(b*c - a*d))}
{PolyLog[0, e*((a + b*x)/(c + d*x))^n]/((a + b*x)*(c + d*x)), x, 2, PolyLog[1, e*((a + b*x)/(c + d*x))^n]/(n*(b*c - a*d))}
{PolyLog[-1, e*((a + b*x)/(c + d*x))^n]/((a + b*x)*(c + d*x)), x, 2, 1/((b*c - a*d)*n*(1 - e*((a + b*x)/(c + d*x))^n))}
{PolyLog[-2, e*((a + b*x)/(c + d*x))^n]/((a + b*x)*(c + d*x)), x, 4, PolyLog[-1, e*((a + b*x)/(c + d*x))^n]/(n*(b*c - a*d)), (1 + e*((a + b*x)/(c + d*x))^n)^2/(4*(b*c - a*d)*n*(1 - e*((a + b*x)/(c + d*x))^n)^2)}


(* ::Section::Closed:: *)
(*Integrands involving polylogarithms of expontial functions*)


{x^3*PolyLog[n, d*(f^(c*(a + b*x)))^p], x, 4, (x^3*PolyLog[1 + n, d*(f^(c*(a + b*x)))^p])/(b*c*p*Log[f]) - (3*x^2*PolyLog[2 + n, d*(f^(c*(a + b*x)))^p])/(b^2*c^2*p^2*Log[f]^2) + (6*x*PolyLog[3 + n, d*(f^(c*(a + b*x)))^p])/(b^3*c^3*p^3*Log[f]^3) - (6*PolyLog[4 + n, d*(f^(c*(a + b*x)))^p])/(b^4*c^4*p^4*Log[f]^4)}
{x^2*PolyLog[n, d*(f^(c*(a + b*x)))^p], x, 3, (x^2*PolyLog[1 + n, d*(f^(c*(a + b*x)))^p])/(b*c*p*Log[f]) - (2*x*PolyLog[2 + n, d*(f^(c*(a + b*x)))^p])/(b^2*c^2*p^2*Log[f]^2) + (2*PolyLog[3 + n, d*(f^(c*(a + b*x)))^p])/(b^3*c^3*p^3*Log[f]^3)}
{x^1*PolyLog[n, d*(f^(c*(a + b*x)))^p], x, 2, (x*PolyLog[1 + n, d*(f^(c*(a + b*x)))^p])/(b*c*p*Log[f]) - PolyLog[2 + n, d*(f^(c*(a + b*x)))^p]/(b^2*c^2*p^2*Log[f]^2)}
{x^0*PolyLog[n, d*(f^(c*(a + b*x)))^p], x, 1, PolyLog[1 + n, d*(f^(c*(a + b*x)))^p]/(b*c*p*Log[f])}
{PolyLog[n, d*(f^(c*(a + b*x)))^p]/x^1, x, 1, Int[PolyLog[n, d*(f^(a*c + b*c*x))^p]/x, x]}


{(Log[x]*PolyLog[n, a*x])/x, x, 2, Log[x]*PolyLog[1 + n, a*x] - PolyLog[2 + n, a*x]}
{(Log[x]^2*PolyLog[n, a*x])/x, x, 3, Log[x]^2*PolyLog[1 + n, a*x] - 2*Log[x]*PolyLog[2 + n, a*x] + 2*PolyLog[3 + n, a*x]}
