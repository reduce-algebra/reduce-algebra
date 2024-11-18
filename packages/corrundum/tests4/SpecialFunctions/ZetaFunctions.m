(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Zeta Functions*)


(* ::Subsection::Closed:: *)
(*Integrands involving zeta functions*)


{x^2*Zeta[2, a+b*x], x, 4, -((2*x*LogGamma[a + b*x])/b^2) + (2*PolyGamma[-2, a + b*x])/b^3 + (x^2*PolyGamma[0, a + b*x])/b}
{x*Zeta[2, a+b*x], x, 3, -(LogGamma[a + b*x]/b^2) + (x*PolyGamma[0, a + b*x])/b}
{Zeta[2, a+b*x], x, 2, PolyGamma[0, a+b*x]/b}
{Zeta[2, a+b*x]/x, x, 1, Int[PolyGamma[1, a + b*x]/x, x]}
{Zeta[2, a+b*x]/x^2, x, 2, b*Int[PolyGamma[2, a + b*x]/x, x] - PolyGamma[1, a + b*x]/x}
{Zeta[2, a+b*x]/x^3, x, 3, (1/2)*b^2*Int[PolyGamma[3, a + b*x]/x, x] - PolyGamma[1, a + b*x]/(2*x^2) - (b*PolyGamma[2, a + b*x])/(2*x)}

{Zeta[2, a + b*x]/x^2 - b*(PolyGamma[2, a + b*x]/x), x, 3, -(PolyGamma[1, a + b*x]/x)}


{x^2*Zeta[s, a+b*x], x, 3, (2*Zeta[-3 + s, a + b*x])/(b^3*(1 - s)*(2 - s)*(3 - s)) - (2*x*Zeta[-2 + s, a + b*x])/(b^2*(1 - s)*(2 - s)) + (x^2*Zeta[-1 + s, a + b*x])/(b*(1 - s))}
{x*Zeta[s, a+b*x], x, 2, -(Zeta[-2 + s, a + b*x]/(b^2*(1 - s)*(2 - s))) + (x*Zeta[-1 + s, a + b*x])/(b*(1 - s))}
{Zeta[s, a+b*x], x, 1, Zeta[-1 + s, a + b*x]/(b*(1 - s))}
{Zeta[s, a+b*x]/x, x, 0, Int[Zeta[s, a + b*x]/x, x]}
{Zeta[s, a+b*x]/x^2, x, 1, (-b)*s*Int[Zeta[1 + s, a + b*x]/x, x] - Zeta[s, a + b*x]/x}
{Zeta[s, a+b*x]/x^3, x, 2, (1/2)*b^2*s*(1 + s)*Int[Zeta[2 + s, a + b*x]/x, x] - Zeta[s, a + b*x]/(2*x^2) + (b*s*Zeta[1 + s, a + b*x])/(2*x)}

{Zeta[s, a + b*x]/x^2 + b*s*(Zeta[1 + s, a + b*x]/x), x, 2, -(Zeta[s, a + b*x]/x)}
