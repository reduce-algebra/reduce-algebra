(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Logarithm Integral Functions*)


(* ::Subsection::Closed:: *)
(*Logarithm integral function*)


{LogIntegral[a + b*x], x, 1, -(ExpIntegralEi[2*Log[a + b*x]]/b) + ((a + b*x)*LogIntegral[a + b*x])/b}
{x*LogIntegral[a + b*x], x, 7, (a*ExpIntegralEi[2*Log[a + b*x]])/b^2 - ExpIntegralEi[3*Log[a + b*x]]/(2*b^2) - (1/2)*(a^2/b^2 - x^2)*LogIntegral[a + b*x]}
{x^2*LogIntegral[a + b*x], x, 8, -((a^2*ExpIntegralEi[2*Log[a + b*x]])/b^3) + (a*ExpIntegralEi[3*Log[a + b*x]])/b^3 - ExpIntegralEi[4*Log[a + b*x]]/(3*b^3) + (1/3)*(a^3/b^3 + x^3)*LogIntegral[a + b*x]}
