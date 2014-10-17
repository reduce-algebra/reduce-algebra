(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Gamma Functions*)


(* ::Subsection::Closed:: *)
(*Integrands involving Gamma*)


{x^m*Gamma[n, a*x], x, 1, (x^(1 + m)*Gamma[n, a*x])/(1 + m) - (x^(1 + m)*(a*x)^(-1 - m)*Gamma[1 + m + n, a*x])/(1 + m)}
{x^m*Gamma[n, 2*x], x, 1, (x^(1 + m)*Gamma[n, 2*x])/(1 + m) - (2^(-1 - m)*Gamma[1 + m + n, 2*x])/(1 + m)}
{x^1000*Gamma[n, a*x], x, 1, (x^1001*Gamma[n, a*x])/1001 - Gamma[1001 + n, a*x]/(1001*a^1001)}


{Gamma[n, a+b*x], x, 1, ((a + b*x)*Gamma[n, a + b*x])/b - Gamma[1 + n, a + b*x]/b}
{x*Gamma[n, a+b*x], x, 3, (-(1/2))*(a^2/b^2 - x^2)*Gamma[n, a + b*x] + (a*Gamma[1 + n, a + b*x])/b^2 - Gamma[2 + n, a + b*x]/(2*b^2)}
{x^2*Gamma[n, a+b*x], x, 7, (1/3)*(a^3/b^3 + x^3)*Gamma[n, a + b*x] - (a^2*Gamma[1 + n, a + b*x])/b^3 + (a*Gamma[2 + n, a + b*x])/b^3 - Gamma[3 + n, a + b*x]/(3*b^3)}


(* ::Subsection::Closed:: *)
(*Integrands involving LogGamma*)


{Log[Gamma[a+b*x]], x, 4, x*Log[Gamma[a + b*x]] - x*LogGamma[a + b*x] + PolyGamma[-2, a + b*x]/b}
{x*Log[Gamma[a+b*x]], x, 5, (1/2)*x^2*Log[Gamma[a + b*x]] - (1/2)*x^2*LogGamma[a + b*x] - PolyGamma[-3, a + b*x]/b^2 + (x*PolyGamma[-2, a + b*x])/b}
{x^2*Log[Gamma[a+b*x]], x, 6, (1/3)*x^3*Log[Gamma[a + b*x]] - (1/3)*x^3*LogGamma[a + b*x] + (2*PolyGamma[-4, a + b*x])/b^3 - (2*x*PolyGamma[-3, a + b*x])/b^2 + (x^2*PolyGamma[-2, a + b*x])/b}


{LogGamma[a+b*x], x, 1, PolyGamma[-2, a+b*x]/b}
{x*LogGamma[a+b*x], x, 2, -(PolyGamma[-3, a + b*x]/b^2) + (x*PolyGamma[-2, a + b*x])/b}
{x^2*LogGamma[a+b*x], x, 3, (2*PolyGamma[-4, a + b*x])/b^3 - (2*x*PolyGamma[-3, a + b*x])/b^2 + (x^2*PolyGamma[-2, a + b*x])/b}


(* ::Subsection::Closed:: *)
(*Integrands involving PolyGamma*)


{x^2*PolyGamma[1, a+b*x], x, 3, -((2*x*LogGamma[a + b*x])/b^2) + (2*PolyGamma[-2, a + b*x])/b^3 + (x^2*PolyGamma[0, a + b*x])/b}
{x*PolyGamma[n, a+b*x], x, 2, -(PolyGamma[-2 + n, a + b*x]/b^2) + (x*PolyGamma[-1 + n, a + b*x])/b}
{PolyGamma[n, a+b*x], x, 1, PolyGamma[-1 + n, a+b*x]/b}
{PolyGamma[n, a+b*x]/x, x, 0, Int[PolyGamma[n, a + b*x]/x, x]}
{PolyGamma[n, a+b*x]/x^2, x, 1, b*Int[PolyGamma[1 + n, a + b*x]/x, x] - PolyGamma[n, a + b*x]/x}
{PolyGamma[n, a+b*x]/x^3, x, 2, (1/2)*b^2*Int[PolyGamma[2 + n, a + b*x]/x, x] - PolyGamma[n, a + b*x]/(2*x^2) - (b*PolyGamma[1 + n, a + b*x])/(2*x)}

{PolyGamma[n, a + b*x]/x^2 - (b*PolyGamma[1 + n, a + b*x])/x, x, 2, -(PolyGamma[n, a + b*x]/x)}


(* ::Subsection::Closed:: *)
(*Integrands involving Gamma and PolyGamma*)


{Gamma[a + b*x]^n*PolyGamma[0, a + b*x], x, 1, Gamma[a + b*x]^n/(b*n)}
{(a + b*x)!^n*PolyGamma[0, 1 + a + b*x], x, 1, (a + b*x)!^n/(b*n)}
