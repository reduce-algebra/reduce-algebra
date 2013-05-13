(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Logarithms*)


(* ::Section::Closed:: *)
(*Integrands involving logarithms of monomials*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Log[c x^n]^p*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form Log[a x^n]^p / x*)


(* Integrands of the form Log[a*x^n]^p/x *)
{Log[a*x]/x, x, 2, Log[a*x]^2/2}
{Log[a*x]^2/x, x, 2, Log[a*x]^3/3}
{Log[a*x]^3/x, x, 2, Log[a*x]^4/4}
{1/(x*Log[a*x]), x, 2, Log[Log[a*x]]}
{1/(x*Log[a*x]^2), x, 2, -Log[a*x]^(-1)}
{1/(x*Log[a*x]^3), x, 2, -1/(2*Log[a*x]^2)}
{Log[a*x]^p/x, x, 2, Log[a*x]^(1 + p)/(1 + p)}

{Sqrt[Log[a*x^n]]/x, x, 2, (2*Log[a*x^n]^(3/2))/(3*n)}
{Log[a*x^n]^(3/2)/x, x, 2, (2*Log[a*x^n]^(5/2))/(5*n)}
{1/(x*Sqrt[Log[a*x^n]]), x, 2, (2*Sqrt[Log[a*x^n]])/n}
{1/(x*Log[a*x^n]^(3/2)), x, 2, -2/(n*Sqrt[Log[a*x^n]])}

{Log[a*x^n]/x, x, 2, Log[a*x^n]^2/(2*n)}
{Log[a*x^n]^2/x, x, 2, Log[a*x^n]^3/(3*n)}
{Log[a*x^n]^3/x, x, 2, Log[a*x^n]^4/(4*n)}
{1/(x*Log[a*x^n]), x, 2, Log[Log[a*x^n]]/n}
{1/(x*Log[a*x^n]^2), x, 2, -(1/(n*Log[a*x^n]))}
{1/(x*Log[a*x^n]^3), x, 2, -(1/(2*n*Log[a*x^n]^2))}
{Log[a*x^n]^p/x, x, 2, Log[a*x^n]^(1 + p)/((1 + p)*n)}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m Log[a x^n]^p where p is an integer*)


(* Integrands of the form x^m*Log[a*x^n] *)
{Log[a*x], x, 1, -x + x*Log[a*x]}
{x*Log[a*x], x, 1, -(x^2/4) + (1/2)*x^2*Log[a*x]}
{x^2*Log[a*x], x, 1, -(x^3/9) + (1/3)*x^3*Log[a*x]}
{x^3*Log[a*x], x, 1, -(x^4/16) + (1/4)*x^4*Log[a*x]}
{Log[a*x]/x^2, x, 1, -(1/x) - Log[a*x]/x}
{Log[a*x]/x^3, x, 1, -(1/(4*x^2)) - Log[a*x]/(2*x^2)}
{x^m*Log[a*x], x, 1, -(x^(1 + m)/(1 + m)^2) + (x^(1 + m)*Log[a*x])/(1 + m)}

{Sqrt[x]*Log[a*x], x, 1, -((4*x^(3/2))/9) + (2/3)*x^(3/2)*Log[a*x]}
{x^(3/2)*Log[a*x], x, 1, -((4*x^(5/2))/25) + (2/5)*x^(5/2)*Log[a*x]}
{Log[a*x]/Sqrt[x], x, 1, -4*Sqrt[x] + 2*Sqrt[x]*Log[a*x]}
{Log[a*x]/x^(3/2), x, 1, -(4/Sqrt[x]) - (2*Log[a*x])/Sqrt[x]}

{Log[1/x], x, 1, x + x*Log[1/x]}
{Log[1/x]/x^2, x, 1, 1/x - Log[1/x]/x}

{Log[a*x^n], x, 1, (-n)*x + x*Log[a*x^n]}
{x*Log[a*x^n], x, 1, -((n*x^2)/4) + (1/2)*x^2*Log[a*x^n]}
{x^2*Log[a*x^n], x, 1, -((n*x^3)/9) + (1/3)*x^3*Log[a*x^n]}
{x^3*Log[a*x^n], x, 1, -((n*x^4)/16) + (1/4)*x^4*Log[a*x^n]}
{Log[a*x^n]/x^2, x, 1, -(n/x) - Log[a*x^n]/x}
{Log[a*x^n]/x^3, x, 1, -(n/(4*x^2)) - Log[a*x^n]/(2*x^2)}
{x^(n-1)*Log[a*x^n], x, 1, -(x^n/n) + (x^n*Log[a*x^n])/n}
{x^m*Log[a*x^n], x, 1, -((n*x^(1 + m))/(1 + m)^2) + (x^(1 + m)*Log[a*x^n])/(1 + m)}
{x^3*Log[c*(a*x^n)^p], x, 1, (-(1/16))*n*p*x^4 + (1/4)*x^4*Log[c*(a*x^n)^p]}
{x^m*Log[c*(a*x^n)^p], x, 1, -((n*p*x^(1 + m))/(1 + m)^2) + (x^(1 + m)*Log[c*(a*x^n)^p])/(1 + m)}


(* Integrands of the form x^m*Log[a*x^n]^2 *)
{Log[a*x]^2, x, 2, 2*x - 2*x*Log[a*x] + x*Log[a*x]^2}
{x*Log[a*x]^2, x, 2, x^2/4 - (1/2)*x^2*Log[a*x] + (1/2)*x^2*Log[a*x]^2}
{x^2*Log[a*x]^2, x, 2, (2*x^3)/27 - (2/9)*x^3*Log[a*x] + (1/3)*x^3*Log[a*x]^2}
{x^3*Log[a*x]^2, x, 2, x^4/32 - (1/8)*x^4*Log[a*x] + (1/4)*x^4*Log[a*x]^2}
{Log[a*x]^2/x^2, x, 2, -(2/x) - (2*Log[a*x])/x - Log[a*x]^2/x}
{Log[a*x]^2/x^3, x, 2, -(1/(4*x^2)) - Log[a*x]/(2*x^2) - Log[a*x]^2/(2*x^2)}
{x^m*Log[a*x]^2, x, 2, (2*x^(1 + m))/(1 + m)^3 - (2*x^(1 + m)*Log[a*x])/(1 + m)^2 + (x^(1 + m)*Log[a*x]^2)/(1 + m)}

{Log[a*x^n]^2, x, 2, 2*n^2*x - 2*n*x*Log[a*x^n] + x*Log[a*x^n]^2}
{x*Log[a*x^n]^2, x, 2, (n^2*x^2)/4 - (1/2)*n*x^2*Log[a*x^n] + (1/2)*x^2*Log[a*x^n]^2}
{x^2*Log[a*x^n]^2, x, 2, (2*n^2*x^3)/27 - (2/9)*n*x^3*Log[a*x^n] + (1/3)*x^3*Log[a*x^n]^2}
{x^3*Log[a*x^n]^2, x, 2, (n^2*x^4)/32 - (1/8)*n*x^4*Log[a*x^n] + (1/4)*x^4*Log[a*x^n]^2}
{Log[a*x^n]^2/x^2, x, 2, -((2*n^2)/x) - (2*n*Log[a*x^n])/x - Log[a*x^n]^2/x}
{Log[a*x^n]^2/x^3, x, 2, -(n^2/(4*x^2)) - (n*Log[a*x^n])/(2*x^2) - Log[a*x^n]^2/(2*x^2)}
{x^m*Log[a*x^n]^2, x, 2, (2*n^2*x^(1 + m))/(1 + m)^3 - (2*n*x^(1 + m)*Log[a*x^n])/(1 + m)^2 + (x^(1 + m)*Log[a*x^n]^2)/(1 + m)}


(* Integrands of the form x^m*Log[a*x^n]^3 *)
{Log[a*x]^3, x, 3, -6*x + 6*x*Log[a*x] - 3*x*Log[a*x]^2 + x*Log[a*x]^3}
{x*Log[a*x]^3, x, 3, -((3*x^2)/8) + (3/4)*x^2*Log[a*x] - (3/4)*x^2*Log[a*x]^2 + (1/2)*x^2*Log[a*x]^3}
{x^2*Log[a*x]^3, x, 3, -((2*x^3)/27) + (2/9)*x^3*Log[a*x] - (1/3)*x^3*Log[a*x]^2 + (1/3)*x^3*Log[a*x]^3}
{x^3*Log[a*x]^3, x, 3, -((3*x^4)/128) + (3/32)*x^4*Log[a*x] - (3/16)*x^4*Log[a*x]^2 + (1/4)*x^4*Log[a*x]^3}
{Log[a*x]^3/x^2, x, 3, -(6/x) - (6*Log[a*x])/x - (3*Log[a*x]^2)/x - Log[a*x]^3/x}
{Log[a*x]^3/x^3, x, 3, -(3/(8*x^2)) - (3*Log[a*x])/(4*x^2) - (3*Log[a*x]^2)/(4*x^2) - Log[a*x]^3/(2*x^2)}
{x^m*Log[a*x]^3, x, 3, -((6*x^(1 + m))/(1 + m)^4) + (6*x^(1 + m)*Log[a*x])/(1 + m)^3 - (3*x^(1 + m)*Log[a*x]^2)/(1 + m)^2 + (x^(1 + m)*Log[a*x]^3)/(1 + m)}

{Log[a*x^n]^3, x, 3, -6*n^3*x + 6*n^2*x*Log[a*x^n] - 3*n*x*Log[a*x^n]^2 + x*Log[a*x^n]^3}
{x*Log[a*x^n]^3, x, 3, (-(3/8))*n^3*x^2 + (3/4)*n^2*x^2*Log[a*x^n] - (3/4)*n*x^2*Log[a*x^n]^2 + (1/2)*x^2*Log[a*x^n]^3}
{x^2*Log[a*x^n]^3, x, 3, (-(2/27))*n^3*x^3 + (2/9)*n^2*x^3*Log[a*x^n] - (1/3)*n*x^3*Log[a*x^n]^2 + (1/3)*x^3*Log[a*x^n]^3}
{x^3*Log[a*x^n]^3, x, 3, (-(3/128))*n^3*x^4 + (3/32)*n^2*x^4*Log[a*x^n] - (3/16)*n*x^4*Log[a*x^n]^2 + (1/4)*x^4*Log[a*x^n]^3}
{Log[a*x^n]^3/x^2, x, 3, -((6*n^3)/x) - (6*n^2*Log[a*x^n])/x - (3*n*Log[a*x^n]^2)/x - Log[a*x^n]^3/x}
{Log[a*x^n]^3/x^3, x, 3, -((3*n^3)/(8*x^2)) - (3*n^2*Log[a*x^n])/(4*x^2) - (3*n*Log[a*x^n]^2)/(4*x^2) - Log[a*x^n]^3/(2*x^2)}
{x^m*Log[a*x^n]^3, x, 3, -((6*n^3*x^(1 + m))/(1 + m)^4) + (6*n^2*x^(1 + m)*Log[a*x^n])/(1 + m)^3 - (3*n*x^(1 + m)*Log[a*x^n]^2)/(1 + m)^2 + (x^(1 + m)*Log[a*x^n]^3)/(1 + m)}


(* Integrands of the form x^m/Log[a*x^n] *)
{1/Log[a*x], x, 1, LogIntegral[a*x]/a}
{x/Log[a*x], x, 1, ExpIntegralEi[2*Log[a*x]]/a^2}
{x^2/Log[a*x], x, 1, ExpIntegralEi[3*Log[a*x]]/a^3}
{x^3/Log[a*x], x, 1, ExpIntegralEi[4*Log[a*x]]/a^4}
{1/(x^2*Log[a*x]), x, 1, a*ExpIntegralEi[-Log[a*x]]}
{1/(x^3*Log[a*x]), x, 1, a^2*ExpIntegralEi[-2*Log[a*x]]}
{x^m/Log[a*x], x, 1, x^(1 + m)*(a*x)^(-1 - m)*ExpIntegralEi[(1 + m)*Log[a*x]]}

{1/Log[a*x^n], x, 1, (x*ExpIntegralEi[Log[a*x^n]/n])/(n*(a*x^n)^n^(-1))}
{x/Log[a*x^n], x, 1, (x^2*ExpIntegralEi[(2*Log[a*x^n])/n])/(n*(a*x^n)^(2/n))}
{x^2/Log[a*x^n], x, 1, (x^3*ExpIntegralEi[(3*Log[a*x^n])/n])/(n*(a*x^n)^(3/n))}
{x^3/Log[a*x^n], x, 1, (x^4*ExpIntegralEi[(4*Log[a*x^n])/n])/(n*(a*x^n)^(4/n))}
{1/(x^2*Log[a*x^n]), x, 1, ((a*x^n)^n^(-1)*ExpIntegralEi[-(Log[a*x^n]/n)])/(n*x)}
{1/(x^3*Log[a*x^n]), x, 1, ((a*x^n)^(2/n)*ExpIntegralEi[(-2*Log[a*x^n])/n])/(n*x^2)}
{x^m/Log[a*x^n], x, 1, (x^(1 + m)*ExpIntegralEi[((1 + m)*Log[a*x^n])/n])/(n*(a*x^n)^((1 + m)/n))}
{x^m/Log[c*(a*x^n)^p], x, 2, (x^(1 + m)*ExpIntegralEi[((1 + m)*Log[c*(a*x^n)^p])/(n*p)])/((c*(a*x^n)^p)^((1 + m)/(n*p))*(n*p))}


(* Integrands of the form x^m/Log[a*x^n]^2 *)
{1/Log[a*x]^2, x, 2, -(x/Log[a*x]) + LogIntegral[a*x]/a}
{x/Log[a*x]^2, x, 2, (2*ExpIntegralEi[2*Log[a*x]])/a^2 - x^2/Log[a*x]}
{x^2/Log[a*x]^2, x, 2, (3*ExpIntegralEi[3*Log[a*x]])/a^3 - x^3/Log[a*x]}
{x^3/Log[a*x]^2, x, 2, (4*ExpIntegralEi[4*Log[a*x]])/a^4 - x^4/Log[a*x]}
{1/(x^2*Log[a*x]^2), x, 2, -(a*ExpIntegralEi[-Log[a*x]]) - 1/(x*Log[a*x])}
{1/(x^3*Log[a*x]^2), x, 2, -2*a^2*ExpIntegralEi[-2*Log[a*x]] - 1/(x^2*Log[a*x])}
{x^m/Log[a*x]^2, x, 2, (1 + m)*x^(1 + m)*(a*x)^(-1 - m)*ExpIntegralEi[(1 + m)*Log[a*x]] - x^(1 + m)/Log[a*x]}

{1/Log[a*x^n]^2, x, 2, (x*ExpIntegralEi[Log[a*x^n]/n])/((a*x^n)^n^(-1)*n^2) - x/(n*Log[a*x^n])}
{x/Log[a*x^n]^2, x, 2, (2*x^2*ExpIntegralEi[(2*Log[a*x^n])/n])/((a*x^n)^(2/n)*n^2) - x^2/(n*Log[a*x^n])}
{x^2/Log[a*x^n]^2, x, 2, (3*x^3*ExpIntegralEi[(3*Log[a*x^n])/n])/((a*x^n)^(3/n)*n^2) - x^3/(n*Log[a*x^n])}
{x^3/Log[a*x^n]^2, x, 2, (4*x^4*ExpIntegralEi[(4*Log[a*x^n])/n])/((a*x^n)^(4/n)*n^2) - x^4/(n*Log[a*x^n])}
{1/(x^2*Log[a*x^n]^2), x, 2, -(((a*x^n)^(1/n)*ExpIntegralEi[-(Log[a*x^n]/n)])/(n^2*x)) - 1/(n*x*Log[a*x^n])}
{1/(x^3*Log[a*x^n]^2), x, 2, -((2*(a*x^n)^(2/n)*ExpIntegralEi[-((2*Log[a*x^n])/n)])/(n^2*x^2)) - 1/(n*x^2*Log[a*x^n])}
{x^m/Log[a*x^n]^2, x, 2, ((1 + m)*x^(1 + m)*ExpIntegralEi[((1 + m)*Log[a*x^n])/n])/((a*x^n)^((1 + m)/n)*n^2) - x^(1 + m)/(n*Log[a*x^n])}


(* Integrands of the form x^m/Log[a*x^n]^3 *)
{1/Log[a*x]^3, x, 3, -(x/(2*Log[a*x]^2)) - x/(2*Log[a*x]) + LogIntegral[a*x]/(2*a)}
{x/Log[a*x]^3, x, 3, (2*ExpIntegralEi[2*Log[a*x]])/a^2 - x^2/(2*Log[a*x]^2) - x^2/Log[a*x]}
{x^2/Log[a*x]^3, x, 3, (9*ExpIntegralEi[3*Log[a*x]])/(2*a^3) - x^3/(2*Log[a*x]^2) - (3*x^3)/(2*Log[a*x])}
{x^3/Log[a*x]^3, x, 3, (8*ExpIntegralEi[4*Log[a*x]])/a^4 - x^4/(2*Log[a*x]^2) - (2*x^4)/Log[a*x]}
{1/(x^2*Log[a*x]^3), x, 3, (1/2)*a*ExpIntegralEi[-Log[a*x]] - 1/(2*x*Log[a*x]^2) + 1/(2*x*Log[a*x])}
{1/(x^3*Log[a*x]^3), x, 3, 2*a^2*ExpIntegralEi[-2*Log[a*x]] - 1/(2*x^2*Log[a*x]^2) + 1/(x^2*Log[a*x])}
{x^m/Log[a*x]^3, x, 3, (1/2)*(1 + m)^2*x^(1 + m)*(a*x)^(-1 - m)*ExpIntegralEi[(1 + m)*Log[a*x]] - x^(1 + m)/(2*Log[a*x]^2) - ((1 + m)*x^(1 + m))/(2*Log[a*x])}

{1/Log[a*x^n]^3, x, 3, (x*ExpIntegralEi[Log[a*x^n]/n])/((a*x^n)^n^(-1)*(2*n^3)) - x/(2*n*Log[a*x^n]^2) - x/(2*n^2*Log[a*x^n])}
{x/Log[a*x^n]^3, x, 3, (2*x^2*ExpIntegralEi[(2*Log[a*x^n])/n])/((a*x^n)^(2/n)*n^3) - x^2/(2*n*Log[a*x^n]^2) - x^2/(n^2*Log[a*x^n])}
{x^2/Log[a*x^n]^3, x, 3, (9*x^3*ExpIntegralEi[(3*Log[a*x^n])/n])/((a*x^n)^(3/n)*(2*n^3)) - x^3/(2*n*Log[a*x^n]^2) - (3*x^3)/(2*n^2*Log[a*x^n])}
{x^3/Log[a*x^n]^3, x, 3, (8*x^4*ExpIntegralEi[(4*Log[a*x^n])/n])/((a*x^n)^(4/n)*n^3) - x^4/(2*n*Log[a*x^n]^2) - (2*x^4)/(n^2*Log[a*x^n])}
{1/(x^2*Log[a*x^n]^3), x, 3, ((a*x^n)^(1/n)*ExpIntegralEi[-(Log[a*x^n]/n)])/(2*n^3*x) - 1/(2*n*x*Log[a*x^n]^2) + 1/(2*n^2*x*Log[a*x^n])}
{1/(x^3*Log[a*x^n]^3), x, 3, (2*(a*x^n)^(2/n)*ExpIntegralEi[-((2*Log[a*x^n])/n)])/(n^3*x^2) - 1/(2*n*x^2*Log[a*x^n]^2) + 1/(n^2*x^2*Log[a*x^n])}
{x^m/Log[a*x^n]^3, x, 3, ((1 + m)^2*x^(1 + m)*ExpIntegralEi[((1 + m)*Log[a*x^n])/n])/((a*x^n)^((1 + m)/n)*(2*n^3)) - x^(1 + m)/(2*n*Log[a*x^n]^2) - ((1 + m)*x^(1 + m))/(2*n^2*Log[a*x^n])}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m Log[a x^n]^p where p is a half-integer*)


(* Integrands of the form x^m*Log[a*x^n]^(3/2) *)
{Log[a*x^n]^(3/2), x, 3, ((3/4)*n^(3/2)*Sqrt[Pi]*x*Erfi[Sqrt[Log[a*x^n]]/Sqrt[n]])/(a*x^n)^n^(-1) - (3/2)*n*x*Sqrt[Log[a*x^n]] + x*Log[a*x^n]^(3/2)}
{x*Log[a*x^n]^(3/2), x, 3, ((3/16)*n^(3/2)*Sqrt[Pi/2]*x^2*Erfi[(Sqrt[2]*Sqrt[Log[a*x^n]])/Sqrt[n]])/(a*x^n)^(2/n) - (3/8)*n*x^2*Sqrt[Log[a*x^n]] + (1/2)*x^2*Log[a*x^n]^(3/2)}
{x^2*Log[a*x^n]^(3/2), x, 3, ((1/12)*n^(3/2)*Sqrt[Pi/3]*x^3*Erfi[(Sqrt[3]*Sqrt[Log[a*x^n]])/Sqrt[n]])/(a*x^n)^(3/n) - (1/6)*n*x^3*Sqrt[Log[a*x^n]] + (1/3)*x^3*Log[a*x^n]^(3/2)}
{x^3*Log[a*x^n]^(3/2), x, 3, ((3/128)*n^(3/2)*Sqrt[Pi]*x^4*Erfi[(2*Sqrt[Log[a*x^n]])/Sqrt[n]])/(a*x^n)^(4/n) - (3/32)*n*x^4*Sqrt[Log[a*x^n]] + (1/4)*x^4*Log[a*x^n]^(3/2)}
{Log[a*x^n]^(3/2)/x^2, x, 3, (3*n^(3/2)*Sqrt[Pi]*(a*x^n)^(1/n)*Erf[Sqrt[Log[a*x^n]]/Sqrt[n]])/(4*x) - (3*n*Sqrt[Log[a*x^n]])/(2*x) - Log[a*x^n]^(3/2)/x}
{Log[a*x^n]^(3/2)/x^3, x, 3, (3*n^(3/2)*Sqrt[Pi/2]*(a*x^n)^(2/n)*Erf[(Sqrt[2]*Sqrt[Log[a*x^n]])/Sqrt[n]])/(16*x^2) - (3*n*Sqrt[Log[a*x^n]])/(8*x^2) - Log[a*x^n]^(3/2)/(2*x^2)}
{x^m*Log[a*x^n]^(3/2), x, 3, (3*n^(3/2)*Sqrt[Pi]*x^(1 + m)*Erfi[(Sqrt[1 + m]*Sqrt[Log[a*x^n]])/Sqrt[n]])/((a*x^n)^((1 + m)/n)*(4*(1 + m)^(5/2))) - (3*n*x^(1 + m)*Sqrt[Log[a*x^n]])/(2*(1 + m)^2) + (x^(1 + m)*Log[a*x^n]^(3/2))/(1 + m)}


(* Integrands of the form x^m*Sqrt[Log[a*x^n]] *)
{Sqrt[Log[a*x^n]], x, 2, -(Sqrt[n]*Sqrt[Pi]*x*Erfi[Sqrt[Log[a*x^n]]/Sqrt[n]])/(2*(a*x^n)^n^(-1)) + x*Sqrt[Log[a*x^n]]}
{x*Sqrt[Log[a*x^n]], x, 2, ((-(1/4))*Sqrt[n]*Sqrt[Pi/2]*x^2*Erfi[(Sqrt[2]*Sqrt[Log[a*x^n]])/Sqrt[n]])/(a*x^n)^(2/n) + (1/2)*x^2*Sqrt[Log[a*x^n]]}
{x^2*Sqrt[Log[a*x^n]], x, 2, ((-(1/6))*Sqrt[n]*Sqrt[Pi/3]*x^3*Erfi[(Sqrt[3]*Sqrt[Log[a*x^n]])/Sqrt[n]])/(a*x^n)^(3/n) + (1/3)*x^3*Sqrt[Log[a*x^n]]}
{x^3*Sqrt[Log[a*x^n]], x, 2, ((-(1/16))*Sqrt[n]*Sqrt[Pi]*x^4*Erfi[(2*Sqrt[Log[a*x^n]])/Sqrt[n]])/(a*x^n)^(4/n) + (1/4)*x^4*Sqrt[Log[a*x^n]]}
{Sqrt[Log[a*x^n]]/x^2, x, 2, (Sqrt[n]*Sqrt[Pi]*(a*x^n)^(1/n)*Erf[Sqrt[Log[a*x^n]]/Sqrt[n]])/(2*x) - Sqrt[Log[a*x^n]]/x}
{Sqrt[Log[a*x^n]]/x^3, x, 2, (Sqrt[n]*Sqrt[Pi/2]*(a*x^n)^(2/n)*Erf[(Sqrt[2]*Sqrt[Log[a*x^n]])/Sqrt[n]])/(4*x^2) - Sqrt[Log[a*x^n]]/(2*x^2)}
{x^m*Sqrt[Log[a*x^n]], x, 2, -((Sqrt[n]*Sqrt[Pi]*x^(1 + m)*Erfi[(Sqrt[1 + m]*Sqrt[Log[a*x^n]])/Sqrt[n]])/((a*x^n)^((1 + m)/n)*(2*(1 + m)^(3/2)))) + (x^(1 + m)*Sqrt[Log[a*x^n]])/(1 + m)}


(* Integrands of the form x^m/Sqrt[Log[a*x^n]] *)
{1/Sqrt[Log[a*x^n]], x, 1, (Sqrt[Pi]*x*Erfi[Sqrt[Log[a*x^n]]/Sqrt[n]])/(Sqrt[n]*(a*x^n)^n^(-1))}
{x/Sqrt[Log[a*x^n]], x, 1, (Sqrt[Pi/2]*x^2*Erfi[(Sqrt[2]*Sqrt[Log[a*x^n]])/Sqrt[n]])/(Sqrt[n]*(a*x^n)^(2/n))}
{x^2/Sqrt[Log[a*x^n]], x, 1, (Sqrt[Pi/3]*x^3*Erfi[(Sqrt[3]*Sqrt[Log[a*x^n]])/Sqrt[n]])/(Sqrt[n]*(a*x^n)^(3/n))}
{x^3/Sqrt[Log[a*x^n]], x, 1, (Sqrt[Pi]*x^4*Erfi[(2*Sqrt[Log[a*x^n]])/Sqrt[n]])/(2*Sqrt[n]*(a*x^n)^(4/n))}
{1/(x^2*Sqrt[Log[a*x^n]]), x, 1, (Sqrt[Pi]*(a*x^n)^n^(-1)*Erf[Sqrt[Log[a*x^n]]/Sqrt[n]])/(Sqrt[n]*x)}
{1/(x^3*Sqrt[Log[a*x^n]]), x, 1, (Sqrt[Pi/2]*(a*x^n)^(2/n)*Erf[(Sqrt[2]*Sqrt[Log[a*x^n]])/Sqrt[n]])/(Sqrt[n]*x^2)}
{x^m/Sqrt[Log[a*x^n]], x, 1, (Sqrt[Pi]*x^(1 + m)*Erfi[(Sqrt[1 + m]*Sqrt[Log[a*x^n]])/Sqrt[n]])/((a*x^n)^((1 + m)/n)*(Sqrt[1 + m]*Sqrt[n]))}


(* Integrands of the form x^m/Log[a*x^n]^(3/2) *)
{1/Log[a*x^n]^(3/2), x, 2, (2*Sqrt[Pi]*x*Erfi[Sqrt[Log[a*x^n]]/Sqrt[n]])/(n^(3/2)*(a*x^n)^n^(-1)) - (2*x)/(n*Sqrt[Log[a*x^n]])}
{x/Log[a*x^n]^(3/2), x, 2, (2*Sqrt[2*Pi]*x^2*Erfi[(Sqrt[2]*Sqrt[Log[a*x^n]])/Sqrt[n]])/((a*x^n)^(2/n)*n^(3/2)) - (2*x^2)/(n*Sqrt[Log[a*x^n]])}
{x^2/Log[a*x^n]^(3/2), x, 2, (2*Sqrt[3*Pi]*x^3*Erfi[(Sqrt[3]*Sqrt[Log[a*x^n]])/Sqrt[n]])/((a*x^n)^(3/n)*n^(3/2)) - (2*x^3)/(n*Sqrt[Log[a*x^n]])}
{x^3/Log[a*x^n]^(3/2), x, 2, (4*Sqrt[Pi]*x^4*Erfi[(2*Sqrt[Log[a*x^n]])/Sqrt[n]])/(n^(3/2)*(a*x^n)^(4/n)) - (2*x^4)/(n*Sqrt[Log[a*x^n]])}
{1/(x^2*Log[a*x^n]^(3/2)), x, 2, -((2*Sqrt[Pi]*(a*x^n)^(1/n)*Erf[Sqrt[Log[a*x^n]]/Sqrt[n]])/(n^(3/2)*x)) - 2/(n*x*Sqrt[Log[a*x^n]])}
{1/(x^3*Log[a*x^n]^(3/2)), x, 2, -((2*Sqrt[2*Pi]*(a*x^n)^(2/n)*Erf[(Sqrt[2]*Sqrt[Log[a*x^n]])/Sqrt[n]])/(n^(3/2)*x^2)) - 2/(n*x^2*Sqrt[Log[a*x^n]])}
{x^m/Log[a*x^n]^(3/2), x, 2, (2*Sqrt[1 + m]*Sqrt[Pi]*x^(1 + m)*Erfi[(Sqrt[1 + m]*Sqrt[Log[a*x^n]])/Sqrt[n]])/((a*x^n)^((1 + m)/n)*n^(3/2)) - (2*x^(1 + m))/(n*Sqrt[Log[a*x^n]])}


(* Integrands of the form x^m/Log[a*x^n]^(5/2) *)
{1/Log[a*x^n]^(5/2), x, 3, (4*Sqrt[Pi]*x*Erfi[Sqrt[Log[a*x^n]]/Sqrt[n]])/((a*x^n)^n^(-1)*(3*n^(5/2))) - (2*x)/(3*n*Log[a*x^n]^(3/2)) - (4*x)/(3*n^2*Sqrt[Log[a*x^n]])}
{x/Log[a*x^n]^(5/2), x, 3, (8*Sqrt[2*Pi]*x^2*Erfi[(Sqrt[2]*Sqrt[Log[a*x^n]])/Sqrt[n]])/((a*x^n)^(2/n)*(3*n^(5/2))) - (2*x^2)/(3*n*Log[a*x^n]^(3/2)) - (8*x^2)/(3*n^2*Sqrt[Log[a*x^n]])}
{x^2/Log[a*x^n]^(5/2), x, 3, (4*Sqrt[3*Pi]*x^3*Erfi[(Sqrt[3]*Sqrt[Log[a*x^n]])/Sqrt[n]])/((a*x^n)^(3/n)*n^(5/2)) - (2*x^3)/(3*n*Log[a*x^n]^(3/2)) - (4*x^3)/(n^2*Sqrt[Log[a*x^n]])}
{x^3/Log[a*x^n]^(5/2), x, 3, (32*Sqrt[Pi]*x^4*Erfi[(2*Sqrt[Log[a*x^n]])/Sqrt[n]])/((a*x^n)^(4/n)*(3*n^(5/2))) - (2*x^4)/(3*n*Log[a*x^n]^(3/2)) - (16*x^4)/(3*n^2*Sqrt[Log[a*x^n]])}
{1/(x^2*Log[a*x^n]^(5/2)), x, 3, (4*Sqrt[Pi]*(a*x^n)^(1/n)*Erf[Sqrt[Log[a*x^n]]/Sqrt[n]])/(3*n^(5/2)*x) - 2/(3*n*x*Log[a*x^n]^(3/2)) + 4/(3*n^2*x*Sqrt[Log[a*x^n]])}
{1/(x^3*Log[a*x^n]^(5/2)), x, 3, (8*Sqrt[2*Pi]*(a*x^n)^(2/n)*Erf[(Sqrt[2]*Sqrt[Log[a*x^n]])/Sqrt[n]])/(3*n^(5/2)*x^2) - 2/(3*n*x^2*Log[a*x^n]^(3/2)) + 8/(3*n^2*x^2*Sqrt[Log[a*x^n]])}
{x^m/Log[a*x^n]^(5/2), x, 3, (4*(1 + m)^(3/2)*Sqrt[Pi]*x^(1 + m)*Erfi[(Sqrt[1 + m]*Sqrt[Log[a*x^n]])/Sqrt[n]])/((a*x^n)^((1 + m)/n)*(3*n^(5/2))) - (2*x^(1 + m))/(3*n*Log[a*x^n]^(3/2)) - (4*(1 + m)*x^(1 + m))/(3*n^2*Sqrt[Log[a*x^n]])}


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m Log[a x^n]^p where p is symbolic*)


(* Integrands of the form x^m*Log[a*x^n]^p where p is symbolic *)
{Log[a*x]^p, x, 1, (Gamma[1 + p, -Log[a*x]]*Log[a*x]^p)/((-Log[a*x])^p*a)}
{x*Log[a*x]^p, x, 1, (2^(-1 - p)*Gamma[1 + p, -2*Log[a*x]]*Log[a*x]^p)/((-Log[a*x])^p*a^2)}
{x^2*Log[a*x]^p, x, 1, (3^(-1 - p)*Gamma[1 + p, -3*Log[a*x]]*Log[a*x]^p)/((-Log[a*x])^p*a^3)}
{x^3*Log[a*x]^p, x, 1, (4^(-1 - p)*Gamma[1 + p, -4*Log[a*x]]*Log[a*x]^p)/((-Log[a*x])^p*a^4)}
{Log[a*x]^p/x^2, x, 1, (-a)*Gamma[1 + p, Log[a*x]]}
{Log[a*x]^p/x^3, x, 1, (-2^(-1 - p))*a^2*Gamma[1 + p, 2*Log[a*x]]}
{x^m*Log[a*x]^p, x, 1, (x^(1 + m)*(a*x)^(-1 - m)*Gamma[1 + p, -((1 + m)*Log[a*x])]*Log[a*x]^p)/((-((1 + m)*Log[a*x]))^p*(1 + m))}

{Log[a*x^n]^p, x, 1, (x*Gamma[1 + p, -(Log[a*x^n]/n)]*Log[a*x^n]^p)/((a*x^n)^n^(-1)*(-(Log[a*x^n]/n))^p)}
{x*Log[a*x^n]^p, x, 1, (2^(-1 - p)*x^2*Gamma[1 + p, -((2*Log[a*x^n])/n)]*Log[a*x^n]^p)/((a*x^n)^(2/n)*(-(Log[a*x^n]/n))^p)}
{x^2*Log[a*x^n]^p, x, 1, (3^(-1 - p)*x^3*Gamma[1 + p, -((3*Log[a*x^n])/n)]*Log[a*x^n]^p)/((a*x^n)^(3/n)*(-(Log[a*x^n]/n))^p)}
{x^3*Log[a*x^n]^p, x, 1, (4^(-1 - p)*x^4*Gamma[1 + p, -((4*Log[a*x^n])/n)]*Log[a*x^n]^p)/((a*x^n)^(4/n)*(-(Log[a*x^n]/n))^p)}
{Log[a*x^n]^p/x^2, x, 1, -(((a*x^n)^(1/n)*Gamma[1 + p, Log[a*x^n]/n]*Log[a*x^n]^p)/((Log[a*x^n]/n)^p*x))}
{Log[a*x^n]^p/x^3, x, 1, -((2^(-1 - p)*(a*x^n)^(2/n)*Gamma[1 + p, (2*Log[a*x^n])/n]*Log[a*x^n]^p)/((Log[a*x^n]/n)^p*x^2))}
{x^m*Log[a*x^n]^p, x, 1, (x^(1 + m)*Gamma[1 + p, -(((1 + m)*Log[a*x^n])/n)]*Log[a*x^n]^p)/((a*x^n)^((1 + m)/n)*(-(((1 + m)*Log[a*x^n])/n))^p*(1 + m))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m (a+b Log[c x^n]^p*)


(* Integrands of the form (a+b*Log[c*x^n])^m *)
{(a + b*Log[c*x^n])^3, x, 4, 6*a*b^2*n^2*x - 6*b^3*n^3*x + 6*b^3*n^2*x*Log[c*x^n] - 3*b*n*x*(a + b*Log[c*x^n])^2 + x*(a + b*Log[c*x^n])^3}
{(a + b*Log[c*x^n])^2, x, 3, -2*a*b*n*x + 2*b^2*n^2*x - 2*b^2*n*x*Log[c*x^n] + x*(a + b*Log[c*x^n])^2}
{(a + b*Log[c*x^n]), x, 2, a*x - b*n*x + b*x*Log[c*x^n]}
{1/(a + b*Log[c*x^n]), x, 1, (x*ExpIntegralEi[(a + b*Log[c*x^n])/(b*n)])/(b*E^(a/(b*n))*n*(c*x^n)^n^(-1))}
{1/(a + b*Log[c*x^n])^2, x, 2, (x*ExpIntegralEi[(a + b*Log[c*x^n])/(b*n)])/(E^(a/(b*n))*(c*x^n)^n^(-1)*(b^2*n^2)) - x/(b*n*(a + b*Log[c*x^n]))}
{1/(a + b*Log[c*x^n])^3, x, 3, (x*ExpIntegralEi[(a + b*Log[c*x^n])/(b*n)])/(E^(a/(b*n))*(c*x^n)^n^(-1)*(2*b^3*n^3)) - x/(2*b*n*(a + b*Log[c*x^n])^2) - x/(2*b^2*n^2*(a + b*Log[c*x^n]))}
{(a + b*Log[c*x^n])^m, x, 1, (x*Gamma[1 + m, -((a + b*Log[c*x^n])/(b*n))]*(a + b*Log[c*x^n])^m)/(E^(a/(b*n))*(c*x^n)^n^(-1)*(-((a + b*Log[c*x^n])/(b*n)))^m)}


(* Integrands of the form x^m*(a+b*Log[c*x^n])^p *)
{x^m/(a + b*Log[c*x^n]), x, 1, (x^(1 + m)*ExpIntegralEi[((1 + m)*(a + b*Log[c*x^n]))/(b*n)])/(E^((a*(1 + m))/(b*n))*(c*x^n)^((1 + m)/n)*(b*n))}
{x^m/(a + b*Log[c*x^n])^2, x, 2, ((1 + m)*x^(1 + m)*ExpIntegralEi[((1 + m)*(a + b*Log[c*x^n]))/(b*n)])/(E^((a*(1 + m))/(b*n))*(c*x^n)^((1 + m)/n)*(b^2*n^2)) - x^(1 + m)/(b*n*(a + b*Log[c*x^n]))}
{x^m*(a + b*Log[c*x^n])^p, x, 1, (x^(1 + m)*Gamma[1 + p, -(((1 + m)*(a + b*Log[c*x^n]))/(b*n))]*(a + b*Log[c*x^n])^p)/(E^((a*(1 + m))/(b*n))*(c*x^n)^((1 + m)/n)*(-(((1 + m)*(a + b*Log[c*x^n]))/(b*n)))^p*(1 + m))}


{x^(n - 1)*Log[-b*x^n/a]/(a + b*x^n), x, 2, -PolyLog[2, 1 + b*x^n/a]/(b*n)}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x)^m Log[c x^n]^p*)


(* Integrands of the form (a+b*x)^m*Log[c*x] *)
{(a + b*x)^3*Log[c*x], x, 3, (-a^3)*x - (3/4)*a^2*b*x^2 - (1/3)*a*b^2*x^3 - (b^3*x^4)/16 - (a^4*Log[x])/(4*b) + ((a + b*x)^4*Log[c*x])/(4*b)}
{(a + b*x)^2*Log[c*x], x, 3, (-a^2)*x - (1/2)*a*b*x^2 - (b^2*x^3)/9 - (a^3*Log[x])/(3*b) + ((a + b*x)^3*Log[c*x])/(3*b)}
{(a + b*x)*Log[c*x], x, 3, (-a)*x - (b*x^2)/4 + (1/2)*x*(2*a + b*x)*Log[c*x], (-a)*x - (b*x^2)/4 - (a^2*Log[x])/(2*b) + ((a + b*x)^2*Log[c*x])/(2*b)}
{Log[c*x]/(a + b*x), x, 1, (Log[c*x]*Log[(a + b*x)/a])/b + PolyLog[2, -((b*x)/a)]/b}
{Log[c*x]/(a + b*x)^2, x, 2, Log[x]/(a*b) - Log[c*x]/(b*(a + b*x)) - Log[a + b*x]/(a*b)}
{Log[c*x]/(2 + 4*x)^2, x, 3, (-(1/4))*ArcTanh[1 + 4*x] - Log[c*x]/(8*(1 + 2*x))}
{Log[c*x]/(a + b*x)^3, x, 5, 1/(2*a*b*(a + b*x)) + Log[x]/(2*a^2*b) - Log[c*x]/(2*b*(a + b*x)^2) - Log[a + b*x]/(2*a^2*b)}


(* Integrands of the form (a+b*x)^m*Log[c*x^n] *)
{(a + b*x)^3*Log[c*x^n], x, 4, (-a^3)*n*x - (3/4)*a^2*b*n*x^2 - (1/3)*a*b^2*n*x^3 - (1/16)*b^3*n*x^4 - (a^4*n*Log[x])/(4*b) + ((a + b*x)^4*Log[c*x^n])/(4*b)}
{(a + b*x)^2*Log[c*x^n], x, 4, (-a^2)*n*x - (1/2)*a*b*n*x^2 - (1/9)*b^2*n*x^3 - (a^3*n*Log[x])/(3*b) + ((a + b*x)^3*Log[c*x^n])/(3*b)}
{(a + b*x)*Log[c*x^n], x, 4, (-a)*n*x - (1/4)*b*n*x^2 - (a^2*n*Log[x])/(2*b) + ((a + b*x)^2*Log[c*x^n])/(2*b)}
{Log[c*x^n]/(a + b*x), x, 1, (Log[c*x^n]*Log[(a + b*x)/a])/b + (n*PolyLog[2, -((b*x)/a)])/b}
{Log[c*x^n]/(a + b*x)^2, x, 3, (n*Log[x])/(a*b) - Log[c*x^n]/(b*(a + b*x)) - (n*Log[a + b*x])/(a*b)}
{Log[c*x^n]/(2 + 4*x)^2, x, 3, (-(1/4))*n*ArcTanh[1 + 4*x] - Log[c*x^n]/(8*(1 + 2*x))}
{Log[c*x^n]/(a + b*x)^3, x, 6, n/(2*a*b*(a + b*x)) + (n*Log[x])/(2*a^2*b) - Log[c*x^n]/(2*b*(a + b*x)^2) - (n*Log[a + b*x])/(2*a^2*b)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Log[a x^n] x^(n-1) / (1-a x^n)*)


{(x*Log[a*x^2])/(1 - a*x^2), x, 2, PolyLog[2, 1 - a*x^2]/(2*a)}
{Log[a*x]/(1 - a*x), x, 1, PolyLog[2, 1 - a*x]/a}
{Log[a/x]/(a*x - x^2), x, 1, PolyLog[2, 1 - a/x]/a}
{Log[a/x^2]/(a*x - x^3), x, 1, PolyLog[2, 1 - a/x^2]/(2*a)}
{Log[x/a]/(a - x), x, 1, PolyLog[2, 1 - (1/a)*x]}
{(x*Log[x^2/a])/(a - x^2), x, 2, (1/2)*PolyLog[2, 1 - x^2/a]}


(* ::Section::Closed:: *)
(*Integrands involving logarithms of binomials*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Log[c (a+b (d+e x)^n)^p]*)


{Log[c*(b*(d + e*x)^n)^p], x, 1, (-n)*p*x + ((d + e*x)*Log[c*(b*(d + e*x)^n)^p])/e}

{Log[c*(a + b*(d + e*x)^2)^p], x, 3, -2*p*x + (2*Sqrt[a]*p*ArcTan[(Sqrt[b]*(d + e*x))/Sqrt[a]])/(Sqrt[b]*e) + ((d + e*x)*Log[c*(a + b*(d + e*x)^2)^p])/e}
{Log[c*(a + b*(d + e*x))^p], x, 3, (-p)*x + (a*p*Log[a + b*d + b*e*x])/(b*e) + ((d + e*x)*Log[c*(a + b*(d + e*x))^p])/e}
{Log[c*(a + b/(d + e*x))^p], x, 3, (b*p*Log[b + a*d + a*e*x])/(a*e) + ((d + e*x)*Log[c*(a + b/(d + e*x))^p])/e}
{Log[c*(a + b/(d + e*x)^2)^p], x, 3, (2*Sqrt[b]*p*ArcTan[(Sqrt[a]*(d + e*x))/Sqrt[b]])/(Sqrt[a]*e) + ((d + e*x)*Log[c*(a + b/(d + e*x)^2)^p])/e}
{Log[c*(a + b*(d + e*x)^n)^p], x, 2, (-n)*p*x + ((d + e*x)*Log[c*(a + b*(d + e*x)^n)^p])/e + (a*n*p*Subst[Int[1/(a + b*x^n), x], x, d + e*x])/e}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b Log[c (d+e x)^n])^p*)


{(a + b*Log[c*(d + e*x)^n])^4, x, 5, -24*a*b^3*n^3*x + 24*b^4*n^4*x - (24*b^4*n^3*(d + e*x)*Log[c*(d + e*x)^n])/e + (12*b^2*n^2*(d + e*x)*(a + b*Log[c*(d + e*x)^n])^2)/e - (4*b*n*(d + e*x)*(a + b*Log[c*(d + e*x)^n])^3)/e + ((d + e*x)*(a + b*Log[c*(d + e*x)^n])^4)/e}
{(a + b*Log[c*(d + e*x)^n])^3, x, 4, 6*a*b^2*n^2*x - 6*b^3*n^3*x + (6*b^3*n^2*(d + e*x)*Log[c*(d + e*x)^n])/e - (3*b*n*(d + e*x)*(a + b*Log[c*(d + e*x)^n])^2)/e + ((d + e*x)*(a + b*Log[c*(d + e*x)^n])^3)/e}
{(a + b*Log[c*(d + e*x)^n])^2, x, 3, -2*a*b*n*x + 2*b^2*n^2*x - (2*b^2*n*(d + e*x)*Log[c*(d + e*x)^n])/e + ((d + e*x)*(a + b*Log[c*(d + e*x)^n])^2)/e}
{(a + b*Log[c*(d + e*x)^n]), x, 2, a*x - b*n*x + (b*(d + e*x)*Log[c*(d + e*x)^n])/e}
{1/(a + b*Log[c*(d + e*x)^n]), x, 1, ((d + e*x)*ExpIntegralEi[(a + b*Log[c*(d + e*x)^n])/(b*n)])/(E^(a/(b*n))*(c*(d + e*x)^n)^n^(-1)*(b*e*n))}
{1/(a + b*Log[c*(d + e*x)^n])^2, x, 2, ((d + e*x)*ExpIntegralEi[(a + b*Log[c*(d + e*x)^n])/(b*n)])/(E^(a/(b*n))*(c*(d + e*x)^n)^n^(-1)*(b^2*e*n^2)) - (d + e*x)/(b*e*n*(a + b*Log[c*(d + e*x)^n]))}
{1/(a + b*Log[c*(d + e*x)^n])^3, x, 3, ((d + e*x)*ExpIntegralEi[(a + b*Log[c*(d + e*x)^n])/(b*n)])/(E^(a/(b*n))*(c*(d + e*x)^n)^n^(-1)*(2*b^3*e*n^3)) - (d + e*x)/(2*b*e*n*(a + b*Log[c*(d + e*x)^n])^2) - (d + e*x)/(2*b^2*e*n^2*(a + b*Log[c*(d + e*x)^n]))}

{(a + b*Log[c*(d + e*x)^n])^(5/2), x, 4, -((15*b^(5/2)*n^(5/2)*Sqrt[Pi]*(d + e*x)*Erfi[Sqrt[a + b*Log[c*(d + e*x)^n]]/(Sqrt[b]*Sqrt[n])])/(E^(a/(b*n))*(c*(d + e*x)^n)^n^(-1)*(8*e))) + (15*b^2*n^2*(d + e*x)*Sqrt[a + b*Log[c*(d + e*x)^n]])/(4*e) - (5*b*n*(d + e*x)*(a + b*Log[c*(d + e*x)^n])^(3/2))/(2*e) + ((d + e*x)*(a + b*Log[c*(d + e*x)^n])^(5/2))/e}
{(a + b*Log[c*(d + e*x)^n])^(3/2), x, 3, (3*b^(3/2)*n^(3/2)*Sqrt[Pi]*(d + e*x)*Erfi[Sqrt[a + b*Log[c*(d + e*x)^n]]/(Sqrt[b]*Sqrt[n])])/(E^(a/(b*n))*(c*(d + e*x)^n)^n^(-1)*(4*e)) - (3*b*n*(d + e*x)*Sqrt[a + b*Log[c*(d + e*x)^n]])/(2*e) + ((d + e*x)*(a + b*Log[c*(d + e*x)^n])^(3/2))/e}
{(a + b*Log[c*(d + e*x)^n])^(1/2), x, 2, -((Sqrt[b]*Sqrt[n]*Sqrt[Pi]*(d + e*x)*Erfi[Sqrt[a + b*Log[c*(d + e*x)^n]]/(Sqrt[b]*Sqrt[n])])/(E^(a/(b*n))*(c*(d + e*x)^n)^n^(-1)*(2*e))) + ((d + e*x)*Sqrt[a + b*Log[c*(d + e*x)^n]])/e}
{1/(a + b*Log[c*(d + e*x)^n])^(1/2), x, 1, (Sqrt[Pi]*(d + e*x)*Erfi[Sqrt[a + b*Log[c*(d + e*x)^n]]/(Sqrt[b]*Sqrt[n])])/(E^(a/(b*n))*(c*(d + e*x)^n)^n^(-1)*(Sqrt[b]*e*Sqrt[n]))}
{1/(a + b*Log[c*(d + e*x)^n])^(3/2), x, 2, (2*Sqrt[Pi]*(d + e*x)*Erfi[Sqrt[a + b*Log[c*(d + e*x)^n]]/(Sqrt[b]*Sqrt[n])])/(E^(a/(b*n))*(c*(d + e*x)^n)^n^(-1)*(b^(3/2)*e*n^(3/2))) - (2*(d + e*x))/(b*e*n*Sqrt[a + b*Log[c*(d + e*x)^n]])}
{1/(a + b*Log[c*(d + e*x)^n])^(5/2), x, 3, (4*Sqrt[Pi]*(d + e*x)*Erfi[Sqrt[a + b*Log[c*(d + e*x)^n]]/(Sqrt[b]*Sqrt[n])])/(E^(a/(b*n))*(c*(d + e*x)^n)^n^(-1)*(3*b^(5/2)*e*n^(5/2))) - (2*(d + e*x))/(3*b*e*n*(a + b*Log[c*(d + e*x)^n])^(3/2)) - (4*(d + e*x))/(3*b^2*e*n^2*Sqrt[a + b*Log[c*(d + e*x)^n]])}

{(a - b*Log[c*(d + e*x)^n])^(5/2), x, 4, -((15*b^(5/2)*E^(a/(b*n))*n^(5/2)*Sqrt[Pi]*(d + e*x)*Erf[Sqrt[a - b*Log[c*(d + e*x)^n]]/(Sqrt[b]*Sqrt[n])])/((c*(d + e*x)^n)^n^(-1)*(8*e))) + (15*b^2*n^2*(d + e*x)*Sqrt[a - b*Log[c*(d + e*x)^n]])/(4*e) + (5*b*n*(d + e*x)*(a - b*Log[c*(d + e*x)^n])^(3/2))/(2*e) + ((d + e*x)*(a - b*Log[c*(d + e*x)^n])^(5/2))/e}
{(a - b*Log[c*(d + e*x)^n])^(3/2), x, 3, -((3*b^(3/2)*E^(a/(b*n))*n^(3/2)*Sqrt[Pi]*(d + e*x)*Erf[Sqrt[a - b*Log[c*(d + e*x)^n]]/(Sqrt[b]*Sqrt[n])])/((c*(d + e*x)^n)^n^(-1)*(4*e))) + (3*b*n*(d + e*x)*Sqrt[a - b*Log[c*(d + e*x)^n]])/(2*e) + ((d + e*x)*(a - b*Log[c*(d + e*x)^n])^(3/2))/e}
{(a - b*Log[c*(d + e*x)^n])^(1/2), x, 2, -((Sqrt[b]*E^(a/(b*n))*Sqrt[n]*Sqrt[Pi]*(d + e*x)*Erf[Sqrt[a - b*Log[c*(d + e*x)^n]]/(Sqrt[b]*Sqrt[n])])/((c*(d + e*x)^n)^n^(-1)*(2*e))) + ((d + e*x)*Sqrt[a - b*Log[c*(d + e*x)^n]])/e}
{1/(a - b*Log[c*(d + e*x)^n])^(1/2), x, 1, -((E^(a/(b*n))*Sqrt[Pi]*(d + e*x)*Erf[Sqrt[a - b*Log[c*(d + e*x)^n]]/(Sqrt[b]*Sqrt[n])])/((c*(d + e*x)^n)^n^(-1)*(Sqrt[b]*e*Sqrt[n])))}
{1/(a - b*Log[c*(d + e*x)^n])^(3/2), x, 2, (2*E^(a/(b*n))*Sqrt[Pi]*(d + e*x)*Erf[Sqrt[a - b*Log[c*(d + e*x)^n]]/(Sqrt[b]*Sqrt[n])])/((c*(d + e*x)^n)^n^(-1)*(b^(3/2)*e*n^(3/2))) + (2*(d + e*x))/(b*e*n*Sqrt[a - b*Log[c*(d + e*x)^n]])}
{1/(a - b*Log[c*(d + e*x)^n])^(5/2), x, 3, -((4*E^(a/(b*n))*Sqrt[Pi]*(d + e*x)*Erf[Sqrt[a - b*Log[c*(d + e*x)^n]]/(Sqrt[b]*Sqrt[n])])/((c*(d + e*x)^n)^n^(-1)*(3*b^(5/2)*e*n^(5/2)))) + (2*(d + e*x))/(3*b*e*n*(a - b*Log[c*(d + e*x)^n])^(3/2)) - (4*(d + e*x))/(3*b^2*e*n^2*Sqrt[a - b*Log[c*(d + e*x)^n]])}

{(a + b*Log[c*(d + e*x)^n])^p, x, 1, ((d + e*x)*Gamma[1 + p, -((a + b*Log[c*(d + e*x)^n])/(b*n))]*(a + b*Log[c*(d + e*x)^n])^p)/(E^(a/(b*n))*(c*(d + e*x)^n)^n^(-1)*(-((a + b*Log[c*(d + e*x)^n])/(b*n)))^p*e)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Log[c (a+b x^n)^p]*)


(* Integrands of the form Log[a*x^n]/x *)
{Log[a*x]/x, x, 2, (1/2)*Log[a*x]^2}
{Log[a/x]/x, x, 2, (-(1/2))*Log[a/x]^2}
{Log[a*x^n]/x, x, 2, Log[a*x^n]^2/(2*n)}


(* Integrands of the form Log[1+a*x^n]/x *)
{Log[1 + a*x]/x, x, 1, -PolyLog[2, (-a)*x]}
{Log[1 + a/x]/x, x, 1, PolyLog[2, -(a/x)]}
{Log[1 + a*x^n]/x, x, 1, -(PolyLog[2, (-a)*x^n]/n)}

{Log[(a + x)/x]/x, x, 1, PolyLog[2, -(a/x)]}
{Log[(a + x^2)/x^2]/x, x, 2, (1/2)*PolyLog[2, -(a/x^2)]}
{Log[(a + x^n)/x^n]/x, x, 2, PolyLog[2, -a/x^n]/n}


(* Integrands of the form Log[a+b*x^n]/x *)
{Log[a + b*x]/x, x, 2, Log[-((b*x)/a)]*Log[a + b*x] + PolyLog[2, 1 + (b*x)/a]}
{Log[a + b/x]/x, x, 3, (-Log[a + b/x])*Log[-(b/(a*x))] - PolyLog[2, 1 + b/(a*x)]}
{Log[a + b*x^n]/x, x, 3, (Log[-((b*x^n)/a)]*Log[a + b*x^n])/n + PolyLog[2, 1 + (b*x^n)/a]/n}

{Log[(a + b*x)/x]/x, x, 4, (-Log[b + a/x])*Log[-(a/(b*x))] - PolyLog[2, 1 + a/(b*x)]}
{Log[(a + b*x^2)/x^2]/x, x, 4, (-(1/2))*Log[b + a/x^2]*Log[-(a/(b*x^2))] - (1/2)*PolyLog[2, 1 + a/(b*x^2)]}
{Log[(a + b*x^n)/x^n]/x, x, 4, -((Log[-(a/(x^n*b))]*Log[b + a/x^n])/n) - PolyLog[2, 1 + a/(x^n*b)]/n}


(* Integrands of the form x^m*Log[c*(a+b*x)^n] where m is an integer *)
{x^4*Log[c*(a + b*x)^n], x, 5, -((a^4*n*x)/(5*b^4)) + (a^3*n*x^2)/(10*b^3) - (a^2*n*x^3)/(15*b^2) + (a*n*x^4)/(20*b) - (n*x^5)/25 + (a^5*n*Log[a + b*x])/(5*b^5) + (1/5)*x^5*Log[c*(a + b*x)^n]}
{x^3*Log[c*(a + b*x)^n], x, 5, (a^3*n*x)/(4*b^3) - (a^2*n*x^2)/(8*b^2) + (a*n*x^3)/(12*b) - (n*x^4)/16 - (a^4*n*Log[a + b*x])/(4*b^4) + (1/4)*x^4*Log[c*(a + b*x)^n]}
{x^2*Log[c*(a + b*x)^n], x, 5, -((a^2*n*x)/(3*b^2)) + (a*n*x^2)/(6*b) - (n*x^3)/9 + (a^3*n*Log[a + b*x])/(3*b^3) + (1/3)*x^3*Log[c*(a + b*x)^n]}
{x*Log[c*(a + b*x)^n], x, 5, (a*n*x)/(2*b) - (n*x^2)/4 - (a^2*n*Log[a + b*x])/(2*b^2) + (1/2)*x^2*Log[c*(a + b*x)^n]}
{Log[c*(a + b*x)^n], x, 1, (-n)*x + ((a + b*x)*Log[c*(a + b*x)^n])/b}
{Log[c*(a + b*x)^n]/x, x, 2, Log[-((b*x)/a)]*Log[c*(a + b*x)^n] + n*PolyLog[2, 1 + (b*x)/a]}
{Log[c*(a + b*x)^n]/x^2, x, 2, (b*n*Log[x])/a - (b*n*Log[a + b*x])/a - Log[c*(a + b*x)^n]/x}
{Log[c*(a + b*x)^n]/x^3, x, 5, -((b*n)/(2*a*x)) - (b^2*n*Log[x])/(2*a^2) + (b^2*n*Log[a + b*x])/(2*a^2) - Log[c*(a + b*x)^n]/(2*x^2)}
{Log[c*(a + b*x)^n]/x^4, x, 5, -((b*n)/(6*a*x^2)) + (b^2*n)/(3*a^2*x) + (b^3*n*Log[x])/(3*a^3) - (b^3*n*Log[a + b*x])/(3*a^3) - Log[c*(a + b*x)^n]/(3*x^3)}


(* Integrands of the form x^m*Log[c*(a+b*x^2)^n] where m is an integer *)
{x^4*Log[c*(a + b*x^2)^n], x, 5, -((2*a^2*n*x)/(5*b^2)) + (2*a*n*x^3)/(15*b) - (2*n*x^5)/25 + (2*a^(5/2)*n*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/(5*b^(5/2)) + (1/5)*x^5*Log[c*(a + b*x^2)^n]}
{x^3*Log[c*(a + b*x^2)^n], x, 6, (a*n*x^2)/(4*b) - (n*x^4)/8 - (a^2*n*Log[a + b*x^2])/(4*b^2) + (1/4)*x^4*Log[c*(a + b*x^2)^n]}
{x^2*Log[c*(a + b*x^2)^n], x, 5, (2*a*n*x)/(3*b) - (2*n*x^3)/9 - (2*a^(3/2)*n*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/(3*b^(3/2)) + (1/3)*x^3*Log[c*(a + b*x^2)^n]}
{x*Log[c*(a + b*x^2)^n], x, 2, -((n*x^2)/2) + ((a + b*x^2)*Log[c*(a + b*x^2)^n])/(2*b)}
{Log[c*(a + b*x^2)^n], x, 2, -2*n*x + (2*Sqrt[a]*n*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/Sqrt[b] + x*Log[c*(a + b*x^2)^n]}
{Log[c*(a + b*x^2)^n]/x, x, 3, (1/2)*Log[-((b*x^2)/a)]*Log[c*(a + b*x^2)^n] + (1/2)*n*PolyLog[2, 1 + (b*x^2)/a]}
{Log[c*(a + b*x^2)^n]/x^2, x, 2, (2*Sqrt[b]*n*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/Sqrt[a] - Log[c*(a + b*x^2)^n]/x}
{Log[c*(a + b*x^2)^n]/x^3, x, 2, (b*n*Log[x])/a - ((a + b*x^2)*Log[c*(a + b*x^2)^n])/(2*a*x^2), (b*n*Log[x])/a - (b*n*Log[a + b*x^2])/(2*a) - Log[c*(a + b*x^2)^n]/(2*x^2)}
{Log[c*(a + b*x^2)^n]/x^4, x, 5, -((2*b*n)/(3*a*x)) - (2*b^(3/2)*n*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/(3*a^(3/2)) - Log[c*(a + b*x^2)^n]/(3*x^3)}


(* Integrands of the form x^m*Log[c*(a+b*x^3)^n] where m is an integer *)
{x^4*Log[c*(a + b*x^3)^n], x, 8, (3*a*n*x^2)/(10*b) - (3*n*x^5)/25 + (Sqrt[3]*a^(5/3)*n*ArcTan[(a^(1/3) - 2*b^(1/3)*x)/(Sqrt[3]*a^(1/3))])/(5*b^(5/3)) + (a^(5/3)*n*Log[a^(1/3) + b^(1/3)*x])/(5*b^(5/3)) - (a^(5/3)*n*Log[a^(2/3) - a^(1/3)*b^(1/3)*x + b^(2/3)*x^2])/(10*b^(5/3)) + (1/5)*x^5*Log[c*(a + b*x^3)^n]}
{x^3*Log[c*(a + b*x^3)^n], x, 8, (3*a*n*x)/(4*b) - (3*n*x^4)/16 + (Sqrt[3]*a^(4/3)*n*ArcTan[(a^(1/3) - 2*b^(1/3)*x)/(Sqrt[3]*a^(1/3))])/(4*b^(4/3)) - (a^(4/3)*n*Log[a^(1/3) + b^(1/3)*x])/(4*b^(4/3)) + (a^(4/3)*n*Log[a^(2/3) - a^(1/3)*b^(1/3)*x + b^(2/3)*x^2])/(8*b^(4/3)) + (1/4)*x^4*Log[c*(a + b*x^3)^n]}
{x^2*Log[c*(a + b*x^3)^n], x, 2, -((n*x^3)/3) + ((a + b*x^3)*Log[c*(a + b*x^3)^n])/(3*b)}
{x*Log[c*(a + b*x^3)^n], x, 8, -((3*n*x^2)/4) - (Sqrt[3]*a^(2/3)*n*ArcTan[(a^(1/3) - 2*b^(1/3)*x)/(Sqrt[3]*a^(1/3))])/(2*b^(2/3)) - (a^(2/3)*n*Log[a^(1/3) + b^(1/3)*x])/(2*b^(2/3)) + (a^(2/3)*n*Log[a^(2/3) - a^(1/3)*b^(1/3)*x + b^(2/3)*x^2])/(4*b^(2/3)) + (1/2)*x^2*Log[c*(a + b*x^3)^n]}
{Log[c*(a + b*x^3)^n], x, 5, -3*n*x - (Sqrt[3]*a^(1/3)*n*ArcTan[(a^(1/3) - 2*b^(1/3)*x)/(Sqrt[3]*a^(1/3))])/b^(1/3) + (a^(1/3)*n*Log[a^(1/3) + b^(1/3)*x])/b^(1/3) - (a^(1/3)*n*Log[a^(2/3) - a^(1/3)*b^(1/3)*x + b^(2/3)*x^2])/(2*b^(1/3)) + x*Log[c*(a + b*x^3)^n]}
{Log[c*(a + b*x^3)^n]/x, x, 3, (1/3)*Log[-((b*x^3)/a)]*Log[c*(a + b*x^3)^n] + (1/3)*n*PolyLog[2, 1 + (b*x^3)/a]}
{Log[c*(a + b*x^3)^n]/x^2, x, 5, -((Sqrt[3]*b^(1/3)*n*ArcTan[(a^(1/3) - 2*b^(1/3)*x)/(Sqrt[3]*a^(1/3))])/a^(1/3)) - (b^(1/3)*n*Log[a^(1/3) + b^(1/3)*x])/a^(1/3) + (b^(1/3)*n*Log[a^(2/3) - a^(1/3)*b^(1/3)*x + b^(2/3)*x^2])/(2*a^(1/3)) - Log[c*(a + b*x^3)^n]/x}
{Log[c*(a + b*x^3)^n]/x^3, x, 5, -((Sqrt[3]*b^(2/3)*n*ArcTan[(a^(1/3) - 2*b^(1/3)*x)/(Sqrt[3]*a^(1/3))])/(2*a^(2/3))) + (b^(2/3)*n*Log[a^(1/3) + b^(1/3)*x])/(2*a^(2/3)) - (b^(2/3)*n*Log[a^(2/3) - a^(1/3)*b^(1/3)*x + b^(2/3)*x^2])/(4*a^(2/3)) - Log[c*(a + b*x^3)^n]/(2*x^2)}
{Log[c*(a + b*x^3)^n]/x^4, x, 2, (b*n*Log[x])/a - (b*n*Log[a + b*x^3])/(3*a) - Log[c*(a + b*x^3)^n]/(3*x^3)}


(* Integrands of the form x^m*Log[c*(a+b/x)^n] where m is an integer *)
{x^4*Log[c*(a + b/x)^n], x, 5, -((b^4*n*x)/(5*a^4)) + (b^3*n*x^2)/(10*a^3) - (b^2*n*x^3)/(15*a^2) + (b*n*x^4)/(20*a) + (1/5)*x^5*Log[c*(a + b/x)^n] + (b^5*n*Log[b + a*x])/(5*a^5)}
{x^3*Log[c*(a + b/x)^n], x, 5, (b^3*n*x)/(4*a^3) - (b^2*n*x^2)/(8*a^2) + (b*n*x^3)/(12*a) + (1/4)*x^4*Log[c*(a + b/x)^n] - (b^4*n*Log[b + a*x])/(4*a^4)}
{x^2*Log[c*(a + b/x)^n], x, 5, -((b^2*n*x)/(3*a^2)) + (b*n*x^2)/(6*a) + (1/3)*x^3*Log[c*(a + b/x)^n] + (b^3*n*Log[b + a*x])/(3*a^3)}
{x*Log[c*(a + b/x)^n], x, 4, (b*n*x)/(2*a) + (1/2)*x^2*Log[c*(a + b/x)^n] - (b^2*n*Log[b + a*x])/(2*a^2)}
{Log[c*(a + b/x)^n], x, 2, x*Log[c*(a + b/x)^n] + (b*n*Log[b + a*x])/a}
{Log[c*(a + b/x)^n]/x, x, 3, (-Log[c*(a + b/x)^n])*Log[-(b/(a*x))] - n*PolyLog[2, 1 + b/(a*x)]}
{Log[c*(a + b/x)^n]/x^2, x, 2, n/x - ((a + b/x)*Log[c*(a + b/x)^n])/b}
{Log[c*(a + b/x)^n]/x^3, x, 5, n/(4*x^2) - (a*n)/(2*b*x) - Log[c*(a + b/x)^n]/(2*x^2) - (a^2*n*Log[x])/(2*b^2) + (a^2*n*Log[b + a*x])/(2*b^2)}
{Log[c*(a + b/x)^n]/x^4, x, 5, n/(9*x^3) - (a*n)/(6*b*x^2) + (a^2*n)/(3*b^2*x) - Log[c*(a + b/x)^n]/(3*x^3) + (a^3*n*Log[x])/(3*b^3) - (a^3*n*Log[b + a*x])/(3*b^3)}


(* Integrands of the form x^m*Log[c*(a+b/x^2)^n] where m is an integer *)
{x^4*Log[c*(a + b/x^2)^n], x, 5, -((2*b^2*n*x)/(5*a^2)) + (2*b*n*x^3)/(15*a) + (2*b^(5/2)*n*ArcTan[(Sqrt[a]*x)/Sqrt[b]])/(5*a^(5/2)) + (1/5)*x^5*Log[c*(a + b/x^2)^n]}
{x^3*Log[c*(a + b/x^2)^n], x, 5, (b*n*x^2)/(4*a) + (1/4)*x^4*Log[c*(a + b/x^2)^n] - (b^2*n*Log[b + a*x^2])/(4*a^2)}
{x^2*Log[c*(a + b/x^2)^n], x, 4, (2*b*n*x)/(3*a) - (2*b^(3/2)*n*ArcTan[(Sqrt[a]*x)/Sqrt[b]])/(3*a^(3/2)) + (1/3)*x^3*Log[c*(a + b/x^2)^n]}
{x*Log[c*(a + b/x^2)^n], x, 2, (1/2)*x^2*Log[c*(a + b/x^2)^n] + (b*n*Log[b + a*x^2])/(2*a)}
{Log[c*(a + b/x^2)^n], x, 2, (2*Sqrt[b]*n*ArcTan[(Sqrt[a]*x)/Sqrt[b]])/Sqrt[a] + x*Log[c*(a + b/x^2)^n]}
{Log[c*(a + b/x^2)^n]/x, x, 3, (-(1/2))*Log[c*(a + b/x^2)^n]*Log[-(b/(a*x^2))] - (1/2)*n*PolyLog[2, 1 + b/(a*x^2)]}
{Log[c*(a + b/x^2)^n]/x^2, x, 5, (2*n)/x + (2*Sqrt[a]*n*ArcTan[(Sqrt[a]*x)/Sqrt[b]])/Sqrt[b] - Log[c*(a + b/x^2)^n]/x}
{Log[c*(a + b/x^2)^n]/x^3, x, 2, n/(2*x^2) - ((a + b/x^2)*Log[c*(a + b/x^2)^n])/(2*b)}
{Log[c*(a + b/x^2)^n]/x^4, x, 5, (2*n)/(9*x^3) - (2*a*n)/(3*b*x) - (2*a^(3/2)*n*ArcTan[(Sqrt[a]*x)/Sqrt[b]])/(3*b^(3/2)) - Log[c*(a + b/x^2)^n]/(3*x^3)}


(* Integrands of the form x^m*Log[c*(a+b*Sqrt[x])^n] where m is an integer *)
{x^4*Log[c*(a + b*Sqrt[x])^n], x, 6, (a^9*n*Sqrt[x])/(5*b^9) - (a^8*n*x)/(10*b^8) + (a^7*n*x^(3/2))/(15*b^7) - (a^6*n*x^2)/(20*b^6) + (a^5*n*x^(5/2))/(25*b^5) - (a^4*n*x^3)/(30*b^4) + (a^3*n*x^(7/2))/(35*b^3) - (a^2*n*x^4)/(40*b^2) + (a*n*x^(9/2))/(45*b) - (n*x^5)/50 - (a^10*n*Log[a + b*Sqrt[x]])/(5*b^10) + (1/5)*x^5*Log[c*(a + b*Sqrt[x])^n]}
{x^3*Log[c*(a + b*Sqrt[x])^n], x, 6, (a^7*n*Sqrt[x])/(4*b^7) - (a^6*n*x)/(8*b^6) + (a^5*n*x^(3/2))/(12*b^5) - (a^4*n*x^2)/(16*b^4) + (a^3*n*x^(5/2))/(20*b^3) - (a^2*n*x^3)/(24*b^2) + (a*n*x^(7/2))/(28*b) - (n*x^4)/32 - (a^8*n*Log[a + b*Sqrt[x]])/(4*b^8) + (1/4)*x^4*Log[c*(a + b*Sqrt[x])^n]}
{x^2*Log[c*(a + b*Sqrt[x])^n], x, 6, (a^5*n*Sqrt[x])/(3*b^5) - (a^4*n*x)/(6*b^4) + (a^3*n*x^(3/2))/(9*b^3) - (a^2*n*x^2)/(12*b^2) + (a*n*x^(5/2))/(15*b) - (n*x^3)/18 - (a^6*n*Log[a + b*Sqrt[x]])/(3*b^6) + (1/3)*x^3*Log[c*(a + b*Sqrt[x])^n]}
{x*Log[c*(a + b*Sqrt[x])^n], x, 6, (a^3*n*Sqrt[x])/(2*b^3) - (a^2*n*x)/(4*b^2) + (a*n*x^(3/2))/(6*b) - (n*x^2)/8 - (a^4*n*Log[a + b*Sqrt[x]])/(2*b^4) + (1/2)*x^2*Log[c*(a + b*Sqrt[x])^n]}
{Log[c*(a + b*Sqrt[x])^n], x, 5, (a*n*Sqrt[x])/b - (n*x)/2 - (a^2*n*Log[a + b*Sqrt[x]])/b^2 + x*Log[c*(a + b*Sqrt[x])^n]}
{Log[c*(a + b*Sqrt[x])^n]/x, x, 3, 2*Log[c*(a + b*Sqrt[x])^n]*Log[-((b*Sqrt[x])/a)] + 2*n*PolyLog[2, 1 + (b*Sqrt[x])/a]}
{Log[c*(a + b*Sqrt[x])^n]/x^2, x, 6, -((b*n)/(a*Sqrt[x])) + (b^2*n*Log[a + b*Sqrt[x]])/a^2 - Log[c*(a + b*Sqrt[x])^n]/x - (b^2*n*Log[Sqrt[x]])/a^2}
{Log[c*(a + b*Sqrt[x])^n]/x^3, x, 6, -((b*n)/(6*a*x^(3/2))) + (b^2*n)/(4*a^2*x) - (b^3*n)/(2*a^3*Sqrt[x]) + (b^4*n*Log[a + b*Sqrt[x]])/(2*a^4) - Log[c*(a + b*Sqrt[x])^n]/(2*x^2) - (b^4*n*Log[Sqrt[x]])/(2*a^4)}
{Log[c*(a + b*Sqrt[x])^n]/x^4, x, 6, -((b*n)/(15*a*x^(5/2))) + (b^2*n)/(12*a^2*x^2) - (b^3*n)/(9*a^3*x^(3/2)) + (b^4*n)/(6*a^4*x) - (b^5*n)/(3*a^5*Sqrt[x]) + (b^6*n*Log[a + b*Sqrt[x]])/(3*a^6) - Log[c*(a + b*Sqrt[x])^n]/(3*x^3) - (b^6*n*Log[Sqrt[x]])/(3*a^6)}


{Log[1 + Sqrt[x]], x, 5, Sqrt[x] - x/2 - Log[1 + Sqrt[x]] + x*Log[1 + Sqrt[x]]}
{Log[1 + x^4], x, 6, -4*x - Sqrt[2]*ArcTan[1 - Sqrt[2]*x] + Sqrt[2]*ArcTan[1 + Sqrt[2]*x] - Log[1 - Sqrt[2]*x + x^2]/Sqrt[2] + Log[1 + Sqrt[2]*x + x^2]/Sqrt[2] + x*Log[1 + x^4]}
{x*Log[Sqrt[1 + x^2]], x, 3, -(x^2/4) + (1/4)*(1 + x^2)*Log[1 + x^2]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Log[a+b x]^p*)


(* Integrands of the form x^m/Log[a+b*x] where m is an integer *)
{x^5/Log[a + b*x], x, 9, (5*a^4*ExpIntegralEi[2*Log[a + b*x]])/b^6 - (10*a^3*ExpIntegralEi[3*Log[a + b*x]])/b^6 + (10*a^2*ExpIntegralEi[4*Log[a + b*x]])/b^6 - (5*a*ExpIntegralEi[5*Log[a + b*x]])/b^6 + ExpIntegralEi[6*Log[a + b*x]]/b^6 - (a^5*LogIntegral[a + b*x])/b^6}
{x^4/Log[a + b*x], x, 8, -((4*a^3*ExpIntegralEi[2*Log[a + b*x]])/b^5) + (6*a^2*ExpIntegralEi[3*Log[a + b*x]])/b^5 - (4*a*ExpIntegralEi[4*Log[a + b*x]])/b^5 + ExpIntegralEi[5*Log[a + b*x]]/b^5 + (a^4*LogIntegral[a + b*x])/b^5}
{x^3/Log[a + b*x], x, 7, (3*a^2*ExpIntegralEi[2*Log[a + b*x]])/b^4 - (3*a*ExpIntegralEi[3*Log[a + b*x]])/b^4 + ExpIntegralEi[4*Log[a + b*x]]/b^4 - (a^3*LogIntegral[a + b*x])/b^4}
{x^2/Log[a + b*x], x, 6, -((2*a*ExpIntegralEi[2*Log[a + b*x]])/b^3) + ExpIntegralEi[3*Log[a + b*x]]/b^3 + (a^2*LogIntegral[a + b*x])/b^3}
{x/Log[a + b*x], x, 5, ExpIntegralEi[2*Log[a + b*x]]/b^2 - (a*LogIntegral[a + b*x])/b^2}
{1/Log[a + b*x], x, 1, LogIntegral[a + b*x]/b}
{1/(x*Log[a + b*x]), x, 0, Int[1/(x*Log[a + b*x]), x]}
{1/(x^2*Log[a + b*x]), x, 0, Int[1/(x^2*Log[a + b*x]), x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Log[a+b x^2]^p*)


(* Integrands of the form x^m*Log[a+b*x^2]^n *)
{Log[a + b*x^2]^2, x, 1, 8*x - 4*x*Log[a + b*x^2] + x*Log[a + b*x^2]^2 - (1/Sqrt[-b])*(Sqrt[a]*(Log[-(Sqrt[a]/Sqrt[-b]) + x]^2 - Log[Sqrt[a]/Sqrt[-b] + x]^2 + 4*ArcTanh[(Sqrt[-b]*x)/Sqrt[a]]*(Log[-(Sqrt[a]/Sqrt[-b]) + x] + Log[Sqrt[a]/Sqrt[-b] + x]) - 4*Log[-((Sqrt[a] - Sqrt[-b]*x)/(Sqrt[a] + Sqrt[-b]*x))] + 2*Log[Sqrt[a]/Sqrt[-b] + x]*Log[1/2 - (Sqrt[-b]*x)/(2*Sqrt[a])] - 2*Log[-(Sqrt[a]/Sqrt[-b]) + x]*Log[(1/2)*(1 + (Sqrt[-b]*x)/Sqrt[a])] - 4*ArcTanh[(Sqrt[-b]*x)/Sqrt[a]]*Log[a + b*x^2] - 2*PolyLog[2, 1/2 - (Sqrt[-b]*x)/(2*Sqrt[a])] + 2*PolyLog[2, (1/2)*(1 + (Sqrt[-b]*x)/Sqrt[a])]))}
{x*Log[a + b*x^2]^2, x, 3, x^2 - ((a + b*x^2)*Log[a + b*x^2])/b + ((a + b*x^2)*Log[a + b*x^2]^2)/(2*b)}
{x^3*Log[a + b*x^2]^2, x, 9, -((3*a*x^2)/(4*b)) + x^4/8 + (3*a^2*Log[a + b*x^2])/(4*b^2) + (a*x^2*Log[a + b*x^2])/(2*b) - (1/4)*x^4*Log[a + b*x^2] - (a^2*Log[a + b*x^2]^2)/(4*b^2) + (1/4)*x^4*Log[a + b*x^2]^2}
{Log[a + b*x^2]^2/x, x, 5, (1/2)*Log[-((b*x^2)/a)]*Log[a + b*x^2]^2 + Log[a + b*x^2]*PolyLog[2, 1 + (b*x^2)/a] - PolyLog[3, (a + b*x^2)/a]}
{Log[a + b*x^2]^2/x^3, x, 4, (b*Log[-((b*x^2)/a)]*Log[a + b*x^2])/a - ((a + b*x^2)*Log[a + b*x^2]^2)/(2*a*x^2) + (b*PolyLog[2, 1 + (b*x^2)/a])/a}

{x*Log[a + b*x^2]^3, x, 4, -3*x^2 + (3*(a + b*x^2)*Log[a + b*x^2])/b - (3*(a + b*x^2)*Log[a + b*x^2]^2)/(2*b) + ((a + b*x^2)*Log[a + b*x^2]^3)/(2*b)}
{x^3*Log[a + b*x^2]^3, x, 13, (21*a*x^2)/(8*b) - (3*x^4)/16 - (21*a^2*Log[a + b*x^2])/(8*b^2) - (9*a*x^2*Log[a + b*x^2])/(4*b) + (3/8)*x^4*Log[a + b*x^2] - (3/8)*x^4*Log[a + b*x^2]^2 + (9*a*(a + (2*b*x^2)/3)*Log[a + b*x^2]^2)/(8*b^2) - (a^2*Log[a + b*x^2]^3)/(4*b^2) + (1/4)*x^4*Log[a + b*x^2]^3}
{Log[a + b*x^2]^3/x, x, 6, (1/2)*Log[-((b*x^2)/a)]*Log[a + b*x^2]^3 + (3/2)*Log[a + b*x^2]^2*PolyLog[2, 1 + (b*x^2)/a] - 3*Log[a + b*x^2]*PolyLog[3, 1 + (b*x^2)/a] + 3*PolyLog[4, (a + b*x^2)/a]}
{Log[a + b*x^2]^3/x^3, x, 6, (3*b*Log[-((b*x^2)/a)]*Log[a + b*x^2]^2)/(2*a) - ((a + b*x^2)*Log[a + b*x^2]^3)/(2*a*x^2) + (3*b*Log[a + b*x^2]*PolyLog[2, 1 + (b*x^2)/a])/a - (3*b*PolyLog[3, (a + b*x^2)/a])/a}

{x/Log[a + b*x^2], x, 2, LogIntegral[a + b*x^2]/(2*b)}
{x^3/Log[a + b*x^2], x, 6, ExpIntegralEi[2*Log[a + b*x^2]]/(2*b^2) - (a*LogIntegral[a + b*x^2])/(2*b^2)}
{1/(x*Log[a + b*x^2]), x, 1, Subst[Int[1/(x*Log[a + b*x]), x], x, x^2]/2}
{1/(x^3*Log[a + b*x^2]), x, 1, (1/2)*Subst[Int[1/(x^2*Log[a + b*x]), x], x, x^2]}

{x/Log[a + b*x^2]^2, x, 3, -((a + b*x^2)/(2*b*Log[a + b*x^2])) + LogIntegral[a + b*x^2]/(2*b)}
{x^3/Log[a + b*x^2]^2, x, 8, ExpIntegralEi[2*Log[a + b*x^2]]/b^2 + (a*(a + b*x^2))/(2*b^2*Log[a + b*x^2]) - (a + b*x^2)^2/(2*b^2*Log[a + b*x^2]) - (a*LogIntegral[a + b*x^2])/(2*b^2)}
{1/(x*Log[a + b*x^2]^2), x, 1, Subst[Int[1/(x*Log[a + b*x]^2), x], x, x^2]/2}
{1/(x^3*Log[a + b*x^2]^2), x, 1, (1/2)*Subst[Int[1/(x^2*Log[a + b*x]^2), x], x, x^2]}

{x/Log[a + b*x^2]^3, x, 4, -((a + b*x^2)/(4*b*Log[a + b*x^2]^2)) - (a + b*x^2)/(4*b*Log[a + b*x^2]) + LogIntegral[a + b*x^2]/(4*b)}
{x^3/Log[a + b*x^2]^3, x, 10, ExpIntegralEi[2*Log[a + b*x^2]]/b^2 + (a*(a + b*x^2))/(4*b^2*Log[a + b*x^2]^2) - (a + b*x^2)^2/(4*b^2*Log[a + b*x^2]^2) + (a*(a + b*x^2))/(4*b^2*Log[a + b*x^2]) - (a + b*x^2)^2/(2*b^2*Log[a + b*x^2]) - (a*LogIntegral[a + b*x^2])/(4*b^2)}
{1/(x*Log[a + b*x^2]^3), x, 1, Subst[Int[1/(x*Log[a + b*x]^3), x], x, x^2]/2}
{1/(x^3*Log[a + b*x^2]^3), x, 1, (1/2)*Subst[Int[1/(x^2*Log[a + b*x]^3), x], x, x^2]}


(* Integrands of the form x^m*Log[c*(a+b*x^2)^n]^n *)
{Log[c*(a + b*x^2)^n]^2, x, 1, 8*n^2*x - 4*n*x*Log[c*(a + b*x^2)^n] + x*Log[c*(a + b*x^2)^n]^2 - (1/Sqrt[-b])*(Sqrt[a]*n*(n*Log[-(Sqrt[a]/Sqrt[-b]) + x]^2 - n*Log[Sqrt[a]/Sqrt[-b] + x]^2 + 4*n*ArcTanh[(Sqrt[-b]*x)/Sqrt[a]]*(Log[-(Sqrt[a]/Sqrt[-b]) + x] + Log[Sqrt[a]/Sqrt[-b] + x]) - 4*n*Log[-((Sqrt[a] - Sqrt[-b]*x)/(Sqrt[a] + Sqrt[-b]*x))] + 2*n*Log[Sqrt[a]/Sqrt[-b] + x]*Log[1/2 - (Sqrt[-b]*x)/(2*Sqrt[a])] - 2*n*Log[-(Sqrt[a]/Sqrt[-b]) + x]*Log[(1/2)*(1 + (Sqrt[-b]*x)/Sqrt[a])] - 4*ArcTanh[(Sqrt[-b]*x)/Sqrt[a]]*Log[c*(a + b*x^2)^n] - 2*n*PolyLog[2, 1/2 - (Sqrt[-b]*x)/(2*Sqrt[a])] + 2*n*PolyLog[2, (1/2)*(1 + (Sqrt[-b]*x)/Sqrt[a])]))}
{x*Log[c*(a + b*x^2)^n]^2, x, 3, n^2*x^2 - (n*(a + b*x^2)*Log[c*(a + b*x^2)^n])/b + ((a + b*x^2)*Log[c*(a + b*x^2)^n]^2)/(2*b)}
{x^3*Log[c*(a + b*x^2)^n]^2, x, 9, -((3*a*n^2*x^2)/(4*b)) + (n^2*x^4)/8 + (a^2*n^2*Log[a + b*x^2])/(4*b^2) - (1/4)*n*x^4*Log[c*(a + b*x^2)^n] + (a*n*(a + b*x^2)*Log[c*(a + b*x^2)^n])/(2*b^2) - (a^2*Log[c*(a + b*x^2)^n]^2)/(4*b^2) + (1/4)*x^4*Log[c*(a + b*x^2)^n]^2}
{Log[c*(a + b*x^2)^n]^2/x, x, 5, (1/2)*Log[-((b*x^2)/a)]*Log[c*(a + b*x^2)^n]^2 + n*Log[c*(a + b*x^2)^n]*PolyLog[2, 1 + (b*x^2)/a] - n^2*PolyLog[3, (a + b*x^2)/a]}
{Log[c*(a + b*x^2)^n]^2/x^3, x, 4, (b*n*Log[-((b*x^2)/a)]*Log[c*(a + b*x^2)^n])/a - ((a + b*x^2)*Log[c*(a + b*x^2)^n]^2)/(2*a*x^2) + (b*n^2*PolyLog[2, 1 + (b*x^2)/a])/a}

{x*Log[c*(a + b*x^2)^n]^3, x, 4, -3*n^3*x^2 + (3*n^2*(a + b*x^2)*Log[c*(a + b*x^2)^n])/b - (3*n*(a + b*x^2)*Log[c*(a + b*x^2)^n]^2)/(2*b) + ((a + b*x^2)*Log[c*(a + b*x^2)^n]^3)/(2*b)}
{x^3*Log[c*(a + b*x^2)^n]^3, x, 13, (21*a*n^3*x^2)/(8*b) - (3*n^3*x^4)/16 - (3*a^2*n^3*Log[a + b*x^2])/(8*b^2) + (3/8)*n^2*x^4*Log[c*(a + b*x^2)^n] - (9*a*n^2*(a + b*x^2)*Log[c*(a + b*x^2)^n])/(4*b^2) - (3/8)*n*x^4*Log[c*(a + b*x^2)^n]^2 + (9*a*n*(a + (2*b*x^2)/3)*Log[c*(a + b*x^2)^n]^2)/(8*b^2) - (a^2*Log[c*(a + b*x^2)^n]^3)/(4*b^2) + (1/4)*x^4*Log[c*(a + b*x^2)^n]^3}
{Log[c*(a + b*x^2)^n]^3/x, x, 6, (1/2)*Log[-((b*x^2)/a)]*Log[c*(a + b*x^2)^n]^3 + (3/2)*n*Log[c*(a + b*x^2)^n]^2*PolyLog[2, 1 + (b*x^2)/a] - 3*n^2*Log[c*(a + b*x^2)^n]*PolyLog[3, 1 + (b*x^2)/a] + 3*n^3*PolyLog[4, (a + b*x^2)/a]}
{Log[c*(a + b*x^2)^n]^3/x^3, x, 6, (3*b*n*Log[-((b*x^2)/a)]*Log[c*(a + b*x^2)^n]^2)/(2*a) - ((a + b*x^2)*Log[c*(a + b*x^2)^n]^3)/(2*a*x^2) + (3*b*n^2*Log[c*(a + b*x^2)^n]*PolyLog[2, 1 + (b*x^2)/a])/a - (3*b*n^3*PolyLog[3, (a + b*x^2)/a])/a}

{x/Log[c*(a + b*x^2)^n], x, 2, ((a + b*x^2)*ExpIntegralEi[Log[c*(a + b*x^2)^n]/n])/(2*b*n*(c*(a + b*x^2)^n)^n^(-1))}
{x^3/Log[c*(a + b*x^2)^n], x, 6, -((a*(a + b*x^2)*ExpIntegralEi[Log[c*(a + b*x^2)^n]/n])/((c*(a + b*x^2)^n)^n^(-1)*(2*b^2*n))) + ((a + b*x^2)^2*ExpIntegralEi[(2*Log[c*(a + b*x^2)^n])/n])/((c*(a + b*x^2)^n)^(2/n)*(2*b^2*n))}

{x/Log[c*(a + b*x^2)^n]^2, x, 3, ((a + b*x^2)*ExpIntegralEi[Log[c*(a + b*x^2)^n]/n])/((c*(a + b*x^2)^n)^n^(-1)*(2*b*n^2)) - (a + b*x^2)/(2*b*n*Log[c*(a + b*x^2)^n])}
{x^3/Log[c*(a + b*x^2)^n]^2, x, 8, -((a*(a + b*x^2)*ExpIntegralEi[Log[c*(a + b*x^2)^n]/n])/((c*(a + b*x^2)^n)^n^(-1)*(2*b^2*n^2))) + ((a + b*x^2)^2*ExpIntegralEi[(2*Log[c*(a + b*x^2)^n])/n])/((c*(a + b*x^2)^n)^(2/n)*(b^2*n^2)) + (a*(a + b*x^2))/(2*b^2*n*Log[c*(a + b*x^2)^n]) - (a + b*x^2)^2/(2*b^2*n*Log[c*(a + b*x^2)^n])}

{x/Log[c*(a + b*x^2)^n]^3, x, 4, ((a + b*x^2)*ExpIntegralEi[Log[c*(a + b*x^2)^n]/n])/((c*(a + b*x^2)^n)^n^(-1)*(4*b*n^3)) - (a + b*x^2)/(4*b*n*Log[c*(a + b*x^2)^n]^2) - (a + b*x^2)/(4*b*n^2*Log[c*(a + b*x^2)^n])}
{x^3/Log[c*(a + b*x^2)^n]^3, x, 10, -((a*(a + b*x^2)*ExpIntegralEi[Log[c*(a + b*x^2)^n]/n])/((c*(a + b*x^2)^n)^n^(-1)*(4*b^2*n^3))) + ((a + b*x^2)^2*ExpIntegralEi[(2*Log[c*(a + b*x^2)^n])/n])/((c*(a + b*x^2)^n)^(2/n)*(b^2*n^3)) + (a*(a + b*x^2))/(4*b^2*n*Log[c*(a + b*x^2)^n]^2) - (a + b*x^2)^2/(4*b^2*n*Log[c*(a + b*x^2)^n]^2) + (a*(a + b*x^2))/(4*b^2*n^2*Log[c*(a + b*x^2)^n]) - (a + b*x^2)^2/(2*b^2*n^2*Log[c*(a + b*x^2)^n])}


(* Integrands of the form Log[c*(a+b/x)^n]^p *)
{Log[(c*(b + a*x))/x], x, 3, (b*Log[b + a*x])/a + x*Log[(c*(b + a*x))/x]}
{Log[(c*(b + a*x))/x]^2, x, 4, ((b + a*x)*Log[a*c + (b*c)/x]^2)/a - (2*b*Log[a*c + (b*c)/x]*Log[-(b/(a*x))])/a - (2*b*PolyLog[2, 1 + b/(a*x)])/a}
{Log[(c*(b + a*x))/x]^3, x, 6, ((b + a*x)*Log[a*c + (b*c)/x]^3)/a - (3*b*Log[a*c + (b*c)/x]^2*Log[-(b/(a*x))])/a - (6*b*Log[a*c + (b*c)/x]*PolyLog[2, 1 + b/(a*x)])/a + (6*b*PolyLog[3, (a + b/x)/a])/a}

{Log[(c*x)/(b + a*x)], x, 3, x*Log[(c*x)/(b + a*x)] - (b*Log[b + a*x])/a}
{Log[(c*x)/(b + a*x)]^2, x, 4, (2*b*Log[b/(b + a*x)]*Log[(c*x)/(b + a*x)])/a + x*Log[(c*x)/(b + a*x)]^2 + (2*b*PolyLog[2, (a*x)/(b + a*x)])/a}
{Log[(c*x)/(b + a*x)]^3, x, 6, (3*b*Log[b/(b + a*x)]*Log[(c*x)/(b + a*x)]^2)/a + x*Log[(c*x)/(b + a*x)]^3 + (6*b*Log[(c*x)/(b + a*x)]*PolyLog[2, (a*x)/(b + a*x)])/a - (6*b*PolyLog[3, (a*x)/(b + a*x)])/a}

{Log[(c*(b + a*x)^2)/x^2], x, 3, (2*b*Log[b + a*x])/a + x*Log[(c*(b + a*x)^2)/x^2]}
{Log[(c*(b + a*x)^2)/x^2]^2, x, 5, ((b + a*x)*Log[c*(a + b/x)^2]^2)/a - (4*b*Log[c*(a + b/x)^2]*Log[-(b/(a*x))])/a - (8*b*PolyLog[2, 1 + b/(a*x)])/a}
{Log[(c*(b + a*x)^2)/x^2]^3, x, 7, ((b + a*x)*Log[c*(a + b/x)^2]^3)/a - (6*b*Log[c*(a + b/x)^2]^2*Log[-(b/(a*x))])/a - (24*b*Log[c*(a + b/x)^2]*PolyLog[2, 1 + b/(a*x)])/a + (48*b*PolyLog[3, (a + b/x)/a])/a}

{Log[(c*x^2)/(b + a*x)^2], x, 3, x*Log[(c*x^2)/(b + a*x)^2] - (2*b*Log[b + a*x])/a}
{Log[(c*x^2)/(b + a*x)^2]^2, x, 5, ((b + a*x)*Log[c/(a + b/x)^2]^2)/a + (4*b*Log[c/(a + b/x)^2]*Log[-(b/(a*x))])/a - (8*b*PolyLog[2, 1 + b/(a*x)])/a}
{Log[(c*x^2)/(b + a*x)^2]^3, x, 7, ((b + a*x)*Log[c/(a + b/x)^2]^3)/a + (6*b*Log[c/(a + b/x)^2]^2*Log[-(b/(a*x))])/a - (24*b*Log[c/(a + b/x)^2]*PolyLog[2, 1 + b/(a*x)])/a - (48*b*PolyLog[3, (a + b/x)/a])/a}


{Log[c*(a + b/x)^n]^2, x, 4, ((b + a*x)*Log[c*(a + b/x)^n]^2)/a - (2*b*n*Log[c*(a + b/x)^n]*Log[-(b/(a*x))])/a - (2*b*n^2*PolyLog[2, 1 + b/(a*x)])/a}
{Log[c*(a + b/x)^n]^3, x, 6, ((b + a*x)*Log[c*(a + b/x)^n]^3)/a - (3*b*n*Log[c*(a + b/x)^n]^2*Log[-(b/(a*x))])/a - (6*b*n^2*Log[c*(a + b/x)^n]*PolyLog[2, 1 + b/(a*x)])/a + (6*b*n^3*PolyLog[3, (a + b/x)/a])/a}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Log[a+b x^n]^p*)


{Log[a + b*Sqrt[x]]/Sqrt[x], x, 2, -2*Sqrt[x] + (2*(a + b*Sqrt[x])*Log[a + b*Sqrt[x]])/b}


(* Integrands of the form Log[c*(a+b*x^m)^n]^p/x where p is an integer *)
{Log[1 + b*x^m]/x, x, 1, -(PolyLog[2, -(b*x^m)]/m)}
{Log[2 + b*x^m]/x, x, 2, Log[2]*Log[x] - PolyLog[2, -((b*x^m)/2)]/m}
{Log[2*(3 + b*x^m)]/x, x, 2, Log[6]*Log[x] - PolyLog[2, -((b*x^m)/3)]/m}
{Log[c*(a + b*x^m)]/x, x, 3, (Log[-((b*x^m)/a)]*Log[c*(a + b*x^m)])/m + PolyLog[2, 1 + (b*x^m)/a]/m}

{Log[c*(a + b*x^m)^n]/x, x, 3, (Log[-((b*x^m)/a)]*Log[c*(a + b*x^m)^n])/m + (n*PolyLog[2, 1 + (b*x^m)/a])/m}
{Log[c*(a + b*x^m)^n]^2/x, x, 5, (Log[-((b*x^m)/a)]*Log[c*(a + b*x^m)^n]^2)/m + (2*n*Log[c*(a + b*x^m)^n]*PolyLog[2, 1 + (b*x^m)/a])/m - (2*n^2*PolyLog[3, (a + b*x^m)/a])/m}
{Log[c*(a + b*x^m)^n]^3/x, x, 6, (Log[-((b*x^m)/a)]*Log[c*(a + b*x^m)^n]^3)/m + (3*n*Log[c*(a + b*x^m)^n]^2*PolyLog[2, 1 + (b*x^m)/a])/m - (6*n^2*Log[c*(a + b*x^m)^n]*PolyLog[3, 1 + (b*x^m)/a])/m + (6*n^3*PolyLog[4, (a + b*x^m)/a])/m}


(* Integrands of the form x^m*Log[c*(a+b*x)^n]^p where m and p are integers *)
(* {x^3*Log[c*(a + b*x)^n]^2, x, 20, -((25*a^3*n^2*x)/(24*b^3)) + (13*a^2*n^2*x^2)/(48*b^2) - (7*a*n^2*x^3)/(72*b) + (n^2*x^4)/32 + (13*a^4*n^2*Log[a + b*x])/(24*b^4) - (a^2*n*x^2*Log[c*(a + b*x)^n])/(4*b^2) + (a*n*x^3*Log[c*(a + b*x)^n])/(6*b) - (1/8)*n*x^4*Log[c*(a + b*x)^n] + (a^3*n*(a + b*x)*Log[c*(a + b*x)^n])/(2*b^4) - (a^4*Log[c*(a + b*x)^n]^2)/(4*b^4) + (1/4)*x^4*Log[c*(a + b*x)^n]^2} *)
{x^2*Log[c*(a + b*x)^n]^2, x, 14, (11*a^2*n^2*x)/(9*b^2) - (5*a*n^2*x^2)/(18*b) + (2*n^2*x^3)/27 - (5*a^3*n^2*Log[a + b*x])/(9*b^3) + (a*n*x^2*Log[c*(a + b*x)^n])/(3*b) - (2/9)*n*x^3*Log[c*(a + b*x)^n] - (2*a^2*n*(a + b*x)*Log[c*(a + b*x)^n])/(3*b^3) + (a^3*Log[c*(a + b*x)^n]^2)/(3*b^3) + (1/3)*x^3*Log[c*(a + b*x)^n]^2}
{x*Log[c*(a + b*x)^n]^2, x, 8, -((3*a*n^2*x)/(2*b)) + (n^2*x^2)/4 + (a^2*n^2*Log[a + b*x])/(2*b^2) - (1/2)*n*x^2*Log[c*(a + b*x)^n] + (a*n*(a + b*x)*Log[c*(a + b*x)^n])/b^2 - (a^2*Log[c*(a + b*x)^n]^2)/(2*b^2) + (1/2)*x^2*Log[c*(a + b*x)^n]^2}
{Log[c*(a + b*x)^n]^2, x, 2, 2*n^2*x - (2*n*(a + b*x)*Log[c*(a + b*x)^n])/b + ((a + b*x)*Log[c*(a + b*x)^n]^2)/b}
{Log[c*(a + b*x)^n]^2/x, x, 4, Log[-((b*x)/a)]*Log[c*(a + b*x)^n]^2 + 2*n*Log[c*(a + b*x)^n]*PolyLog[2, 1 + (b*x)/a] - 2*n^2*PolyLog[3, (a + b*x)/a]}
{Log[c*(a + b*x)^n]^2/x^2, x, 3, (2*b*n*Log[-((b*x)/a)]*Log[c*(a + b*x)^n])/a - ((a + b*x)*Log[c*(a + b*x)^n]^2)/(a*x) + (2*b*n^2*PolyLog[2, 1 + (b*x)/a])/a}
{Log[c*(a + b*x)^n]^2/x^3, x, 6, (b^2*n^2*Log[x])/a^2 - (b^2*n^2*Log[a + b*x])/a^2 - (b*n*Log[c*(a + b*x)^n])/(a*x) - (b^2*n*Log[-((b*x)/a)]*Log[c*(a + b*x)^n])/a^2 + (b^2*Log[c*(a + b*x)^n]^2)/(2*a^2) - Log[c*(a + b*x)^n]^2/(2*x^2) - (b^2*n^2*PolyLog[2, 1 + (b*x)/a])/a^2}

(* {x^3*Log[c*(a + b*x)^n]^3, x, 46, (415*a^3*n^3*x)/(96*b^3) - (115*a^2*n^3*x^2)/(192*b^2) + (37*a*n^3*x^3)/(288*b) - (3*n^3*x^4)/128 - (115*a^4*n^3*Log[a + b*x])/(96*b^4) + (13*a^2*n^2*x^2*Log[c*(a + b*x)^n])/(16*b^2) - (7*a*n^2*x^3*Log[c*(a + b*x)^n])/(24*b) + (3/32)*n^2*x^4*Log[c*(a + b*x)^n] - (25*a^3*n^2*(a + b*x)*Log[c*(a + b*x)^n])/(8*b^4) + (25*a^4*n*Log[c*(a + b*x)^n]^2)/(16*b^4) + (3*a^3*n*x*Log[c*(a + b*x)^n]^2)/(4*b^3) - (3*a^2*n*x^2*Log[c*(a + b*x)^n]^2)/(8*b^2) + (a*n*x^3*Log[c*(a + b*x)^n]^2)/(4*b) - (3/16)*n*x^4*Log[c*(a + b*x)^n]^2 - (a^4*Log[c*(a + b*x)^n]^3)/(4*b^4) + (1/4)*x^4*Log[c*(a + b*x)^n]^3} *)
(* {x^2*Log[c*(a + b*x)^n]^3, x, 25, -((85*a^2*n^3*x)/(18*b^2)) + (19*a*n^3*x^2)/(36*b) - (2*n^3*x^3)/27 + (19*a^3*n^3*Log[a + b*x])/(18*b^3) - (5*a*n^2*x^2*Log[c*(a + b*x)^n])/(6*b) + (2/9)*n^2*x^3*Log[c*(a + b*x)^n] + (11*a^2*n^2*(a + b*x)*Log[c*(a + b*x)^n])/(3*b^3) - (11*a^3*n*Log[c*(a + b*x)^n]^2)/(6*b^3) - (a^2*n*x*Log[c*(a + b*x)^n]^2)/b^2 + (a*n*x^2*Log[c*(a + b*x)^n]^2)/(2*b) - (1/3)*n*x^3*Log[c*(a + b*x)^n]^2 + (a^3*Log[c*(a + b*x)^n]^3)/(3*b^3) + (1/3)*x^3*Log[c*(a + b*x)^n]^3} *)
{x*Log[c*(a + b*x)^n]^3, x, 12, (21*a*n^3*x)/(4*b) - (3*n^3*x^2)/8 - (3*a^2*n^3*Log[a + b*x])/(4*b^2) + (3/4)*n^2*x^2*Log[c*(a + b*x)^n] - (9*a*n^2*(a + b*x)*Log[c*(a + b*x)^n])/(2*b^2) - (3/4)*n*x^2*Log[c*(a + b*x)^n]^2 + (9*a*n*(a + (2*b*x)/3)*Log[c*(a + b*x)^n]^2)/(4*b^2) - (a^2*Log[c*(a + b*x)^n]^3)/(2*b^2) + (1/2)*x^2*Log[c*(a + b*x)^n]^3}
{Log[c*(a + b*x)^n]^3, x, 3, -6*n^3*x + (6*n^2*(a + b*x)*Log[c*(a + b*x)^n])/b - (3*n*(a + b*x)*Log[c*(a + b*x)^n]^2)/b + ((a + b*x)*Log[c*(a + b*x)^n]^3)/b}
{Log[c*(a + b*x)^n]^3/x, x, 5, Log[-((b*x)/a)]*Log[c*(a + b*x)^n]^3 + 3*n*Log[c*(a + b*x)^n]^2*PolyLog[2, 1 + (b*x)/a] - 6*n^2*Log[c*(a + b*x)^n]*PolyLog[3, 1 + (b*x)/a] + 6*n^3*PolyLog[4, (a + b*x)/a]}
{Log[c*(a + b*x)^n]^3/x^2, x, 5, (3*b*n*Log[-((b*x)/a)]*Log[c*(a + b*x)^n]^2)/a - ((a + b*x)*Log[c*(a + b*x)^n]^3)/(a*x) + (6*b*n^2*Log[c*(a + b*x)^n]*PolyLog[2, 1 + (b*x)/a])/a - (6*b*n^3*PolyLog[3, (a + b*x)/a])/a}
{Log[c*(a + b*x)^n]^3/x^3, x, 9, (3*b^2*n^2*Log[-((b*x)/a)]*Log[c*(a + b*x)^n])/a^2 - (3*b*n*(a + b*x)*Log[c*(a + b*x)^n]^2)/(2*a^2*x) - (3*b^2*n*Log[-((b*x)/a)]*Log[c*(a + b*x)^n]^2)/(2*a^2) + (b^2*Log[c*(a + b*x)^n]^3)/(2*a^2) - Log[c*(a + b*x)^n]^3/(2*x^2) + (3*b^2*n^2*(n - Log[c*(a + b*x)^n])*PolyLog[2, 1 + (b*x)/a])/a^2 + (3*b^2*n^3*PolyLog[3, (a + b*x)/a])/a^2}

{x^3/Log[c*(a + b*x)^n], x, 7, -((a^3*(a + b*x)*ExpIntegralEi[Log[c*(a + b*x)^n]/n])/((c*(a + b*x)^n)^n^(-1)*(b^4*n))) + (3*a^2*(a + b*x)^2*ExpIntegralEi[(2*Log[c*(a + b*x)^n])/n])/((c*(a + b*x)^n)^(2/n)*(b^4*n)) - (3*a*(a + b*x)^3*ExpIntegralEi[(3*Log[c*(a + b*x)^n])/n])/((c*(a + b*x)^n)^(3/n)*(b^4*n)) + ((a + b*x)^4*ExpIntegralEi[(4*Log[c*(a + b*x)^n])/n])/((c*(a + b*x)^n)^(4/n)*(b^4*n))}
{x^2/Log[c*(a + b*x)^n], x, 6, (a^2*(a + b*x)*ExpIntegralEi[Log[c*(a + b*x)^n]/n])/((c*(a + b*x)^n)^n^(-1)*(b^3*n)) - (2*a*(a + b*x)^2*ExpIntegralEi[(2*Log[c*(a + b*x)^n])/n])/((c*(a + b*x)^n)^(2/n)*(b^3*n)) + ((a + b*x)^3*ExpIntegralEi[(3*Log[c*(a + b*x)^n])/n])/((c*(a + b*x)^n)^(3/n)*(b^3*n))}
{x/Log[a + b*x], x, 5, ExpIntegralEi[2*Log[a + b*x]]/b^2 - (a*LogIntegral[a + b*x])/b^2}
{x/Log[c*(a + b*x)^n], x, 5, -((a*(a + b*x)*ExpIntegralEi[Log[c*(a + b*x)^n]/n])/((c*(a + b*x)^n)^n^(-1)*(b^2*n))) + ((a + b*x)^2*ExpIntegralEi[(2*Log[c*(a + b*x)^n])/n])/((c*(a + b*x)^n)^(2/n)*(b^2*n))}
{1/Log[c*(a + b*x)^n], x, 1, ((a + b*x)*ExpIntegralEi[Log[c*(a + b*x)^n]/n])/(b*n*(c*(a + b*x)^n)^n^(-1))}
{1/(x*Log[c*(a + b*x)^n]), x, 0, Int[1/(x*Log[c*(a + b*x)^n]), x]}
{1/(x^2*Log[c*(a + b*x)^n]), x, 0, Int[1/(x^2*Log[c*(a + b*x)^n]), x]}
{1/(x^3*Log[c*(a + b*x)^n]), x, 0, Int[1/(x^3*Log[c*(a + b*x)^n]), x]}

{x^3/Log[c*(a + b*x)^n]^2, x, 11, -((a^3*(a + b*x)*ExpIntegralEi[Log[c*(a + b*x)^n]/n])/((c*(a + b*x)^n)^n^(-1)*(b^4*n^2))) + (6*a^2*(a + b*x)^2*ExpIntegralEi[(2*Log[c*(a + b*x)^n])/n])/((c*(a + b*x)^n)^(2/n)*(b^4*n^2)) - (9*a*(a + b*x)^3*ExpIntegralEi[(3*Log[c*(a + b*x)^n])/n])/((c*(a + b*x)^n)^(3/n)*(b^4*n^2)) + (4*(a + b*x)^4*ExpIntegralEi[(4*Log[c*(a + b*x)^n])/n])/((c*(a + b*x)^n)^(4/n)*(b^4*n^2)) + (a^3*(a + b*x))/(b^4*n*Log[c*(a + b*x)^n]) - (3*a^2*(a + b*x)^2)/(b^4*n*Log[c*(a + b*x)^n]) + (3*a*(a + b*x)^3)/(b^4*n*Log[c*(a + b*x)^n]) - (a + b*x)^4/(b^4*n*Log[c*(a + b*x)^n])}
{x^2/Log[c*(a + b*x)^n]^2, x, 9, (a^2*(a + b*x)*ExpIntegralEi[Log[c*(a + b*x)^n]/n])/((c*(a + b*x)^n)^n^(-1)*(b^3*n^2)) - (4*a*(a + b*x)^2*ExpIntegralEi[(2*Log[c*(a + b*x)^n])/n])/((c*(a + b*x)^n)^(2/n)*(b^3*n^2)) + (3*(a + b*x)^3*ExpIntegralEi[(3*Log[c*(a + b*x)^n])/n])/((c*(a + b*x)^n)^(3/n)*(b^3*n^2)) - (a^2*(a + b*x))/(b^3*n*Log[c*(a + b*x)^n]) + (2*a*(a + b*x)^2)/(b^3*n*Log[c*(a + b*x)^n]) - (a + b*x)^3/(b^3*n*Log[c*(a + b*x)^n])}
{x/Log[c*(a + b*x)^n]^2, x, 7, -((a*(a + b*x)*ExpIntegralEi[Log[c*(a + b*x)^n]/n])/((c*(a + b*x)^n)^n^(-1)*(b^2*n^2))) + (2*(a + b*x)^2*ExpIntegralEi[(2*Log[c*(a + b*x)^n])/n])/((c*(a + b*x)^n)^(2/n)*(b^2*n^2)) + (a*(a + b*x))/(b^2*n*Log[c*(a + b*x)^n]) - (a + b*x)^2/(b^2*n*Log[c*(a + b*x)^n])}
{1/Log[c*(a + b*x)^n]^2, x, 2, ((a + b*x)*ExpIntegralEi[Log[c*(a + b*x)^n]/n])/((c*(a + b*x)^n)^n^(-1)*(b*n^2)) - (a + b*x)/(b*n*Log[c*(a + b*x)^n])}
{1/(x*Log[c*(a + b*x)^n]^2), x, 0, Int[1/(x*Log[c*(a + b*x)^n]^2), x]}
{1/(x^2*Log[c*(a + b*x)^n]^2), x, 0, Int[1/(x^2*Log[c*(a + b*x)^n]^2), x]}
{1/(x^3*Log[c*(a + b*x)^n]^2), x, 0, Int[1/(x^3*Log[c*(a + b*x)^n]^2), x]}

{x^3/Log[c*(a + b*x)^n]^3, x, 15, -((a^3*(a + b*x)*ExpIntegralEi[Log[c*(a + b*x)^n]/n])/((c*(a + b*x)^n)^n^(-1)*(2*b^4*n^3))) + (6*a^2*(a + b*x)^2*ExpIntegralEi[(2*Log[c*(a + b*x)^n])/n])/((c*(a + b*x)^n)^(2/n)*(b^4*n^3)) - (27*a*(a + b*x)^3*ExpIntegralEi[(3*Log[c*(a + b*x)^n])/n])/((c*(a + b*x)^n)^(3/n)*(2*b^4*n^3)) + (8*(a + b*x)^4*ExpIntegralEi[(4*Log[c*(a + b*x)^n])/n])/((c*(a + b*x)^n)^(4/n)*(b^4*n^3)) - (x^3*(a + b*x))/(2*b*n*Log[c*(a + b*x)^n]^2) - (x^2*(a + b*x)*(3*a + 4*b*x))/(2*b^2*n^2*Log[c*(a + b*x)^n]), -((a^3*(a + b*x)*ExpIntegralEi[Log[c*(a + b*x)^n]/n])/((c*(a + b*x)^n)^n^(-1)*(2*b^4*n^3))) + (6*a^2*(a + b*x)^2*ExpIntegralEi[(2*Log[c*(a + b*x)^n])/n])/((c*(a + b*x)^n)^(2/n)*(b^4*n^3)) - (27*a*(a + b*x)^3*ExpIntegralEi[(3*Log[c*(a + b*x)^n])/n])/((c*(a + b*x)^n)^(3/n)*(2*b^4*n^3)) + (8*(a + b*x)^4*ExpIntegralEi[(4*Log[c*(a + b*x)^n])/n])/((c*(a + b*x)^n)^(4/n)*(b^4*n^3)) + (a^3*(a + b*x))/(2*b^4*n*Log[c*(a + b*x)^n]^2) - (3*a^2*(a + b*x)^2)/(2*b^4*n*Log[c*(a + b*x)^n]^2) + (3*a*(a + b*x)^3)/(2*b^4*n*Log[c*(a + b*x)^n]^2) - (a + b*x)^4/(2*b^4*n*Log[c*(a + b*x)^n]^2) + (a^3*(a + b*x))/(2*b^4*n^2*Log[c*(a + b*x)^n]) - (3*a^2*(a + b*x)^2)/(b^4*n^2*Log[c*(a + b*x)^n]) + (9*a*(a + b*x)^3)/(2*b^4*n^2*Log[c*(a + b*x)^n]) - (2*(a + b*x)^4)/(b^4*n^2*Log[c*(a + b*x)^n])}
{x^2/Log[c*(a + b*x)^n]^3, x, 12, (a^2*(a + b*x)*ExpIntegralEi[Log[c*(a + b*x)^n]/n])/((c*(a + b*x)^n)^n^(-1)*(2*b^3*n^3)) - (4*a*(a + b*x)^2*ExpIntegralEi[(2*Log[c*(a + b*x)^n])/n])/((c*(a + b*x)^n)^(2/n)*(b^3*n^3)) + (9*(a + b*x)^3*ExpIntegralEi[(3*Log[c*(a + b*x)^n])/n])/((c*(a + b*x)^n)^(3/n)*(2*b^3*n^3)) - (x^2*(a + b*x))/(2*b*n*Log[c*(a + b*x)^n]^2) - (x*(a + b*x)*(2*a + 3*b*x))/(2*b^2*n^2*Log[c*(a + b*x)^n]), (a^2*(a + b*x)*ExpIntegralEi[Log[c*(a + b*x)^n]/n])/((c*(a + b*x)^n)^n^(-1)*(2*b^3*n^3)) - (4*a*(a + b*x)^2*ExpIntegralEi[(2*Log[c*(a + b*x)^n])/n])/((c*(a + b*x)^n)^(2/n)*(b^3*n^3)) + (9*(a + b*x)^3*ExpIntegralEi[(3*Log[c*(a + b*x)^n])/n])/((c*(a + b*x)^n)^(3/n)*(2*b^3*n^3)) - (a^2*(a + b*x))/(2*b^3*n*Log[c*(a + b*x)^n]^2) + (a*(a + b*x)^2)/(b^3*n*Log[c*(a + b*x)^n]^2) - (a + b*x)^3/(2*b^3*n*Log[c*(a + b*x)^n]^2) - (a^2*(a + b*x))/(2*b^3*n^2*Log[c*(a + b*x)^n]) + (2*a*(a + b*x)^2)/(b^3*n^2*Log[c*(a + b*x)^n]) - (3*(a + b*x)^3)/(2*b^3*n^2*Log[c*(a + b*x)^n])}
{x/Log[c*(a + b*x)^n]^3, x, 9, -((a*(a + b*x)*ExpIntegralEi[Log[c*(a + b*x)^n]/n])/((c*(a + b*x)^n)^n^(-1)*(2*b^2*n^3))) + (2*(a + b*x)^2*ExpIntegralEi[(2*Log[c*(a + b*x)^n])/n])/((c*(a + b*x)^n)^(2/n)*(b^2*n^3)) - (x*(a + b*x))/(2*b*n*Log[c*(a + b*x)^n]^2) - ((a + b*x)*(a + 2*b*x))/(2*b^2*n^2*Log[c*(a + b*x)^n]), -((a*(a + b*x)*ExpIntegralEi[Log[c*(a + b*x)^n]/n])/((c*(a + b*x)^n)^n^(-1)*(2*b^2*n^3))) + (2*(a + b*x)^2*ExpIntegralEi[(2*Log[c*(a + b*x)^n])/n])/((c*(a + b*x)^n)^(2/n)*(b^2*n^3)) + (a*(a + b*x))/(2*b^2*n*Log[c*(a + b*x)^n]^2) - (a + b*x)^2/(2*b^2*n*Log[c*(a + b*x)^n]^2) + (a*(a + b*x))/(2*b^2*n^2*Log[c*(a + b*x)^n]) - (a + b*x)^2/(b^2*n^2*Log[c*(a + b*x)^n])}
{1/Log[c*(a + b*x)^n]^3, x, 3, ((a + b*x)*ExpIntegralEi[Log[c*(a + b*x)^n]/n])/((c*(a + b*x)^n)^n^(-1)*(2*b*n^3)) - (a + b*x)/(2*b*n*Log[c*(a + b*x)^n]^2) - (a + b*x)/(2*b*n^2*Log[c*(a + b*x)^n])}
{1/(x*Log[c*(a + b*x)^n]^3), x, 0, Int[1/(x*Log[c*(a + b*x)^n]^3), x]}
{1/(x^2*Log[c*(a + b*x)^n]^3), x, 0, Int[1/(x^2*Log[c*(a + b*x)^n]^3), x]}
{1/(x^3*Log[c*(a + b*x)^n]^3), x, 0, Int[1/(x^3*Log[c*(a + b*x)^n]^3), x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form (d+e x)^m Log[c (a+b x)^n]^p*)


{(a + b*x)^3*Log[c + d*x], x, 8, ((b*c - a*d)^3*x)/(4*d^3) - ((b*c - a*d)^2*(a + b*x)^2)/(8*b*d^2) + ((b*c - a*d)*(a + b*x)^3)/(12*b*d) - (a + b*x)^4/(16*b) - ((b*c - a*d)^4*Log[c + d*x])/(4*b*d^4) + ((a + b*x)^4*Log[c + d*x])/(4*b)}
{(a + b*x)^2*Log[c + d*x], x, 7, -(((b*c - a*d)^2*x)/(3*d^2)) + ((b*c - a*d)*(a + b*x)^2)/(6*b*d) - (a + b*x)^3/(9*b) + ((b*c - a*d)^3*Log[c + d*x])/(3*b*d^3) + ((a + b*x)^3*Log[c + d*x])/(3*b)}
{(a + b*x)*Log[c + d*x], x, 6, ((b*c - a*d)*x)/(2*d) - (a + b*x)^2/(4*b) - ((b*c - a*d)^2*Log[c + d*x])/(2*b*d^2) + ((a + b*x)^2*Log[c + d*x])/(2*b)}


{Log[c + d*x]/(a + b*x)^1, x, 1, (Log[-((d*(a + b*x))/(b*c - a*d))]*Log[c + d*x])/b + PolyLog[2, (b*(c + d*x))/(b*c - a*d)]/b}
{Log[c + d*x]/(a + b*x)^2, x, 6, (d*Log[a + b*x])/(b*(b*c - a*d)) - (d*Log[c + d*x])/(b*(b*c - a*d)) - Log[c + d*x]/(b*(a + b*x))}
{Log[c + d*x]/(a + b*x)^3, x, 7, -(d/(2*b*(b*c - a*d)*(a + b*x))) - (d^2*Log[a + b*x])/(2*b*(b*c - a*d)^2) + (d^2*Log[c + d*x])/(2*b*(b*c - a*d)^2) - Log[c + d*x]/(2*b*(a + b*x)^2)}

{Log[(c + d*x)^2]/(a + b*x)^1, x, 1, (Log[-((d*(a + b*x))/(b*c - a*d))]*Log[(c + d*x)^2])/b + (2*PolyLog[2, (b*(c + d*x))/(b*c - a*d)])/b}
{Log[(c + d*x)^2]/(a + b*x)^2, x, 6, (2*d*Log[a + b*x])/(b*(b*c - a*d)) - (2*d*Log[c + d*x])/(b*(b*c - a*d)) - Log[(c + d*x)^2]/(b*(a + b*x))}
{Log[(c + d*x)^2]/(a + b*x)^3, x, 7, -(d/(b*(b*c - a*d)*(a + b*x))) - (d^2*Log[a + b*x])/(b*(b*c - a*d)^2) + (d^2*Log[c + d*x])/(b*(b*c - a*d)^2) - Log[(c + d*x)^2]/(2*b*(a + b*x)^2)}

{Log[(c + d*x)^3]/(a + b*x)^1, x, 1, (Log[-((d*(a + b*x))/(b*c - a*d))]*Log[(c + d*x)^3])/b + (3*PolyLog[2, (b*(c + d*x))/(b*c - a*d)])/b}
{Log[(c + d*x)^3]/(a + b*x)^2, x, 6, (3*d*Log[a + b*x])/(b*(b*c - a*d)) - (3*d*Log[c + d*x])/(b*(b*c - a*d)) - Log[(c + d*x)^3]/(b*(a + b*x))}
{Log[(c + d*x)^3]/(a + b*x)^3, x, 7, -((3*d)/(2*b*(b*c - a*d)*(a + b*x))) - (3*d^2*Log[a + b*x])/(2*b*(b*c - a*d)^2) + (3*d^2*Log[c + d*x])/(2*b*(b*c - a*d)^2) - Log[(c + d*x)^3]/(2*b*(a + b*x)^2)}

{Log[(c + d*x)^n]/(a + b*x)^1, x, 1, (Log[-((d*(a + b*x))/(b*c - a*d))]*Log[(c + d*x)^n])/b + (n*PolyLog[2, (b*(c + d*x))/(b*c - a*d)])/b}
{Log[(c + d*x)^n]/(a + b*x)^2, x, 6, (d*n*Log[a + b*x])/(b*(b*c - a*d)) - (d*n*Log[c + d*x])/(b*(b*c - a*d)) - Log[(c + d*x)^n]/(b*(a + b*x))}
{Log[(c + d*x)^n]/(a + b*x)^3, x, 7, -((d*n)/(2*b*(b*c - a*d)*(a + b*x))) - (d^2*n*Log[a + b*x])/(2*b*(b*c - a*d)^2) + (d^2*n*Log[c + d*x])/(2*b*(b*c - a*d)^2) - Log[(c + d*x)^n]/(2*b*(a + b*x)^2)}


{Log[c + d*x]^2/(a + b*x)^1, x, 4, (Log[-((d*(a + b*x))/(b*c - a*d))]*Log[c + d*x]^2)/b + (2*Log[c + d*x]*PolyLog[2, (b*(c + d*x))/(b*c - a*d)])/b - (2*PolyLog[3, (b*(c + d*x))/(b*c - a*d)])/b}
{Log[c + d*x]^2/(a + b*x)^2, x, 6, (2*d*Log[-((d*(a + b*x))/(b*c - a*d))]*Log[c + d*x])/(b*(b*c - a*d)) - (d*Log[c + d*x]^2)/(b*(b*c - a*d)) - Log[c + d*x]^2/(b*(a + b*x)) + (2*d*PolyLog[2, (b*(c + d*x))/(b*c - a*d)])/(b*(b*c - a*d))}
{Log[c + d*x]^2/(a + b*x)^3, x, 12, (d^2*Log[a + b*x])/(b*(b*c - a*d)^2) - (d^2*Log[c + d*x])/(b*(b*c - a*d)^2) - (d*Log[c + d*x])/(b*(b*c - a*d)*(a + b*x)) - (d^2*Log[-((d*(a + b*x))/(b*c - a*d))]*Log[c + d*x])/(b*(b*c - a*d)^2) + (d^2*Log[c + d*x]^2)/(2*b*(b*c - a*d)^2) - Log[c + d*x]^2/(2*b*(a + b*x)^2) - (d^2*PolyLog[2, (b*(c + d*x))/(b*c - a*d)])/(b*(b*c - a*d)^2)}

{Log[(c + d*x)^2]^2/(a + b*x)^1, x, 4, (Log[-((d*(a + b*x))/(b*c - a*d))]*Log[(c + d*x)^2]^2)/b + (4*Log[(c + d*x)^2]*PolyLog[2, (b*(c + d*x))/(b*c - a*d)])/b - (8*PolyLog[3, (b*(c + d*x))/(b*c - a*d)])/b}
{Log[(c + d*x)^2]^2/(a + b*x)^2, x, 6, (4*d*Log[-((d*(a + b*x))/(b*c - a*d))]*Log[(c + d*x)^2])/(b*(b*c - a*d)) - (d*Log[(c + d*x)^2]^2)/(b*(b*c - a*d)) - Log[(c + d*x)^2]^2/(b*(a + b*x)) + (8*d*PolyLog[2, (b*(c + d*x))/(b*c - a*d)])/(b*(b*c - a*d))}
{Log[(c + d*x)^2]^2/(a + b*x)^3, x, 12, (4*d^2*Log[a + b*x])/(b*(b*c - a*d)^2) - (4*d^2*Log[c + d*x])/(b*(b*c - a*d)^2) - (2*d*Log[(c + d*x)^2])/(b*(b*c - a*d)*(a + b*x)) - (2*d^2*Log[-((d*(a + b*x))/(b*c - a*d))]*Log[(c + d*x)^2])/(b*(b*c - a*d)^2) + (d^2*Log[(c + d*x)^2]^2)/(2*b*(b*c - a*d)^2) - Log[(c + d*x)^2]^2/(2*b*(a + b*x)^2) - (4*d^2*PolyLog[2, (b*(c + d*x))/(b*c - a*d)])/(b*(b*c - a*d)^2)}

{Log[(c + d*x)^3]^2/(a + b*x)^1, x, 4, (Log[-((d*(a + b*x))/(b*c - a*d))]*Log[(c + d*x)^3]^2)/b + (6*Log[(c + d*x)^3]*PolyLog[2, (b*(c + d*x))/(b*c - a*d)])/b - (18*PolyLog[3, (b*(c + d*x))/(b*c - a*d)])/b}
{Log[(c + d*x)^3]^2/(a + b*x)^2, x, 6, (6*d*Log[-((d*(a + b*x))/(b*c - a*d))]*Log[(c + d*x)^3])/(b*(b*c - a*d)) - (d*Log[(c + d*x)^3]^2)/(b*(b*c - a*d)) - Log[(c + d*x)^3]^2/(b*(a + b*x)) + (18*d*PolyLog[2, (b*(c + d*x))/(b*c - a*d)])/(b*(b*c - a*d))}
{Log[(c + d*x)^3]^2/(a + b*x)^3, x, 12, (9*d^2*Log[a + b*x])/(b*(b*c - a*d)^2) - (9*d^2*Log[c + d*x])/(b*(b*c - a*d)^2) - (3*d*Log[(c + d*x)^3])/(b*(b*c - a*d)*(a + b*x)) - (3*d^2*Log[-((d*(a + b*x))/(b*c - a*d))]*Log[(c + d*x)^3])/(b*(b*c - a*d)^2) + (d^2*Log[(c + d*x)^3]^2)/(2*b*(b*c - a*d)^2) - Log[(c + d*x)^3]^2/(2*b*(a + b*x)^2) - (9*d^2*PolyLog[2, (b*(c + d*x))/(b*c - a*d)])/(b*(b*c - a*d)^2)}

{Log[(c + d*x)^n]^2/(a + b*x)^1, x, 4, (Log[-((d*(a + b*x))/(b*c - a*d))]*Log[(c + d*x)^n]^2)/b + (2*n*Log[(c + d*x)^n]*PolyLog[2, (b*(c + d*x))/(b*c - a*d)])/b - (2*n^2*PolyLog[3, (b*(c + d*x))/(b*c - a*d)])/b}
{Log[(c + d*x)^n]^2/(a + b*x)^2, x, 6, (2*d*n*Log[-((d*(a + b*x))/(b*c - a*d))]*Log[(c + d*x)^n])/(b*(b*c - a*d)) - (d*Log[(c + d*x)^n]^2)/(b*(b*c - a*d)) - Log[(c + d*x)^n]^2/(b*(a + b*x)) + (2*d*n^2*PolyLog[2, (b*(c + d*x))/(b*c - a*d)])/(b*(b*c - a*d))}
{Log[(c + d*x)^n]^2/(a + b*x)^3, x, 12, (d^2*n^2*Log[a + b*x])/(b*(b*c - a*d)^2) - (d^2*n^2*Log[c + d*x])/(b*(b*c - a*d)^2) - (d*n*Log[(c + d*x)^n])/(b*(b*c - a*d)*(a + b*x)) - (d^2*n*Log[-((d*(a + b*x))/(b*c - a*d))]*Log[(c + d*x)^n])/(b*(b*c - a*d)^2) + (d^2*Log[(c + d*x)^n]^2)/(2*b*(b*c - a*d)^2) - Log[(c + d*x)^n]^2/(2*b*(a + b*x)^2) - (d^2*n^2*PolyLog[2, (b*(c + d*x))/(b*c - a*d)])/(b*(b*c - a*d)^2)}


{Log[c + d*x]^3/(a + b*x)^1, x, 5, (Log[-((d*(a + b*x))/(b*c - a*d))]*Log[c + d*x]^3)/b + (3*Log[c + d*x]^2*PolyLog[2, (b*(c + d*x))/(b*c - a*d)])/b - (6*Log[c + d*x]*PolyLog[3, (b*(c + d*x))/(b*c - a*d)])/b + (6*PolyLog[4, (b*(c + d*x))/(b*c - a*d)])/b}
{Log[c + d*x]^3/(a + b*x)^2, x, 9, (3*d*Log[-((d*(a + b*x))/(b*c - a*d))]*Log[c + d*x]^2)/(b*(b*c - a*d)) - (d*Log[c + d*x]^3)/(b*(b*c - a*d)) - Log[c + d*x]^3/(b*(a + b*x)) + (6*d*Log[c + d*x]*PolyLog[2, (b*(c + d*x))/(b*c - a*d)])/(b*(b*c - a*d)) - (6*d*PolyLog[3, (b*(c + d*x))/(b*c - a*d)])/(b*(b*c - a*d))}
{Log[c + d*x]^3/(a + b*x)^3, x, 15, (3*d^2*Log[-((d*(a + b*x))/(b*c - a*d))]*Log[c + d*x])/(b*(b*c - a*d)^2) - (3*d^2*Log[c + d*x]^2)/(2*b*(b*c - a*d)^2) - (3*d*Log[c + d*x]^2)/(2*b*(b*c - a*d)*(a + b*x)) - (3*d^2*Log[-((d*(a + b*x))/(b*c - a*d))]*Log[c + d*x]^2)/(2*b*(b*c - a*d)^2) + (d^2*Log[c + d*x]^3)/(2*b*(b*c - a*d)^2) - Log[c + d*x]^3/(2*b*(a + b*x)^2) + (3*d^2*(1 - Log[c + d*x])*PolyLog[2, (b*(c + d*x))/(b*c - a*d)])/(b*(b*c - a*d)^2) + (3*d^2*PolyLog[3, (b*(c + d*x))/(b*c - a*d)])/(b*(b*c - a*d)^2)}

{Log[(c + d*x)^2]^3/(a + b*x)^1, x, 5, (Log[-((d*(a + b*x))/(b*c - a*d))]*Log[(c + d*x)^2]^3)/b + (6*Log[(c + d*x)^2]^2*PolyLog[2, (b*(c + d*x))/(b*c - a*d)])/b - (24*Log[(c + d*x)^2]*PolyLog[3, (b*(c + d*x))/(b*c - a*d)])/b + (48*PolyLog[4, (b*(c + d*x))/(b*c - a*d)])/b}
{Log[(c + d*x)^2]^3/(a + b*x)^2, x, 9, (6*d*Log[-((d*(a + b*x))/(b*c - a*d))]*Log[(c + d*x)^2]^2)/(b*(b*c - a*d)) - (d*Log[(c + d*x)^2]^3)/(b*(b*c - a*d)) - Log[(c + d*x)^2]^3/(b*(a + b*x)) + (24*d*Log[(c + d*x)^2]*PolyLog[2, (b*(c + d*x))/(b*c - a*d)])/(b*(b*c - a*d)) - (48*d*PolyLog[3, (b*(c + d*x))/(b*c - a*d)])/(b*(b*c - a*d))}
{Log[(c + d*x)^2]^3/(a + b*x)^3, x, 15, (12*d^2*Log[-((d*(a + b*x))/(b*c - a*d))]*Log[(c + d*x)^2])/(b*(b*c - a*d)^2) - (3*d^2*Log[(c + d*x)^2]^2)/(b*(b*c - a*d)^2) - (3*d*Log[(c + d*x)^2]^2)/(b*(b*c - a*d)*(a + b*x)) - (3*d^2*Log[-((d*(a + b*x))/(b*c - a*d))]*Log[(c + d*x)^2]^2)/(b*(b*c - a*d)^2) + (d^2*Log[(c + d*x)^2]^3)/(2*b*(b*c - a*d)^2) - Log[(c + d*x)^2]^3/(2*b*(a + b*x)^2) + (12*d^2*(2 - Log[(c + d*x)^2])*PolyLog[2, (b*(c + d*x))/(b*c - a*d)])/(b*(b*c - a*d)^2) + (24*d^2*PolyLog[3, (b*(c + d*x))/(b*c - a*d)])/(b*(b*c - a*d)^2)}

{Log[(c + d*x)^3]^3/(a + b*x)^1, x, 5, (Log[-((d*(a + b*x))/(b*c - a*d))]*Log[(c + d*x)^3]^3)/b + (9*Log[(c + d*x)^3]^2*PolyLog[2, (b*(c + d*x))/(b*c - a*d)])/b - (54*Log[(c + d*x)^3]*PolyLog[3, (b*(c + d*x))/(b*c - a*d)])/b + (162*PolyLog[4, (b*(c + d*x))/(b*c - a*d)])/b}
{Log[(c + d*x)^3]^3/(a + b*x)^2, x, 9, (9*d*Log[-((d*(a + b*x))/(b*c - a*d))]*Log[(c + d*x)^3]^2)/(b*(b*c - a*d)) - (d*Log[(c + d*x)^3]^3)/(b*(b*c - a*d)) - Log[(c + d*x)^3]^3/(b*(a + b*x)) + (54*d*Log[(c + d*x)^3]*PolyLog[2, (b*(c + d*x))/(b*c - a*d)])/(b*(b*c - a*d)) - (162*d*PolyLog[3, (b*(c + d*x))/(b*c - a*d)])/(b*(b*c - a*d))}
{Log[(c + d*x)^3]^3/(a + b*x)^3, x, 15, (27*d^2*Log[-((d*(a + b*x))/(b*c - a*d))]*Log[(c + d*x)^3])/(b*(b*c - a*d)^2) - (9*d^2*Log[(c + d*x)^3]^2)/(2*b*(b*c - a*d)^2) - (9*d*Log[(c + d*x)^3]^2)/(2*b*(b*c - a*d)*(a + b*x)) - (9*d^2*Log[-((d*(a + b*x))/(b*c - a*d))]*Log[(c + d*x)^3]^2)/(2*b*(b*c - a*d)^2) + (d^2*Log[(c + d*x)^3]^3)/(2*b*(b*c - a*d)^2) - Log[(c + d*x)^3]^3/(2*b*(a + b*x)^2) + (27*d^2*(3 - Log[(c + d*x)^3])*PolyLog[2, (b*(c + d*x))/(b*c - a*d)])/(b*(b*c - a*d)^2) + (81*d^2*PolyLog[3, (b*(c + d*x))/(b*c - a*d)])/(b*(b*c - a*d)^2)}

{Log[(c + d*x)^n]^3/(a + b*x)^1, x, 5, (Log[-((d*(a + b*x))/(b*c - a*d))]*Log[(c + d*x)^n]^3)/b + (3*n*Log[(c + d*x)^n]^2*PolyLog[2, (b*(c + d*x))/(b*c - a*d)])/b - (6*n^2*Log[(c + d*x)^n]*PolyLog[3, (b*(c + d*x))/(b*c - a*d)])/b + (6*n^3*PolyLog[4, (b*(c + d*x))/(b*c - a*d)])/b}
{Log[(c + d*x)^n]^3/(a + b*x)^2, x, 9, (3*d*n*Log[-((d*(a + b*x))/(b*c - a*d))]*Log[(c + d*x)^n]^2)/(b*(b*c - a*d)) - (d*Log[(c + d*x)^n]^3)/(b*(b*c - a*d)) - Log[(c + d*x)^n]^3/(b*(a + b*x)) + (6*d*n^2*Log[(c + d*x)^n]*PolyLog[2, (b*(c + d*x))/(b*c - a*d)])/(b*(b*c - a*d)) - (6*d*n^3*PolyLog[3, (b*(c + d*x))/(b*c - a*d)])/(b*(b*c - a*d))}
{Log[(c + d*x)^n]^3/(a + b*x)^3, x, 15, (3*d^2*n^2*Log[-((d*(a + b*x))/(b*c - a*d))]*Log[(c + d*x)^n])/(b*(b*c - a*d)^2) - (3*d^2*n*Log[(c + d*x)^n]^2)/(2*b*(b*c - a*d)^2) - (3*d*n*Log[(c + d*x)^n]^2)/(2*b*(b*c - a*d)*(a + b*x)) - (3*d^2*n*Log[-((d*(a + b*x))/(b*c - a*d))]*Log[(c + d*x)^n]^2)/(2*b*(b*c - a*d)^2) + (d^2*Log[(c + d*x)^n]^3)/(2*b*(b*c - a*d)^2) - Log[(c + d*x)^n]^3/(2*b*(a + b*x)^2) + (3*d^2*n^2*(n - Log[(c + d*x)^n])*PolyLog[2, (b*(c + d*x))/(b*c - a*d)])/(b*(b*c - a*d)^2) + (3*d^2*n^3*PolyLog[3, (b*(c + d*x))/(b*c - a*d)])/(b*(b*c - a*d)^2)}


(* ::Subsection::Closed:: *)
(*Integrands of the form (a+b x)^m Log[c+d x^n]*)


{Log[a + b*x^2]/(c + d*x), x, 5, -((Log[(d*(Sqrt[-a] - Sqrt[b]*x))/(Sqrt[b]*c + Sqrt[-a]*d)]*Log[c + d*x])/d) - (Log[-((d*(Sqrt[-a] + Sqrt[b]*x))/(Sqrt[b]*c - Sqrt[-a]*d))]*Log[c + d*x])/d + (Log[c + d*x]*Log[a + b*x^2])/d - PolyLog[2, (Sqrt[b]*(c + d*x))/(Sqrt[b]*c - Sqrt[-a]*d)]/d - PolyLog[2, (Sqrt[b]*(c + d*x))/(Sqrt[b]*c + Sqrt[-a]*d)]/d}
{Log[a + b*x^2]/(c + d*x)^2, x, 8, (2*Sqrt[a]*Sqrt[b]*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/(b*c^2 + a*d^2) - (2*b*c*Log[c + d*x])/(d*(b*c^2 + a*d^2)) + (b*c*Log[a + b*x^2])/(d*(b*c^2 + a*d^2)) - Log[a + b*x^2]/(d*(c + d*x))}
{Log[a + b*x^2]/(c + d*x)^3, x, 9, (b*c)/(d*(b*c^2 + a*d^2)*(c + d*x)) + (2*Sqrt[a]*b^(3/2)*c*ArcTan[(Sqrt[b]*x)/Sqrt[a]])/(b*c^2 + a*d^2)^2 - (b*(b*c^2 - a*d^2)*Log[c + d*x])/(d*(b*c^2 + a*d^2)^2) + (b*(b*c^2 - a*d^2)*Log[a + b*x^2])/(2*d*(b*c^2 + a*d^2)^2) - Log[a + b*x^2]/(2*d*(c + d*x)^2)}


{Log[a + b*x^3]/(c + d*x), x, 6, -((Log[(d*((-1)^(1/3)*a^(1/3) - b^(1/3)*x))/(b^(1/3)*c + (-1)^(1/3)*a^(1/3)*d)]*Log[c + d*x])/d) - (Log[-((d*(a^(1/3) + b^(1/3)*x))/(b^(1/3)*c - a^(1/3)*d))]*Log[c + d*x])/d - (Log[-((d*((-1)^(2/3)*a^(1/3) + b^(1/3)*x))/(b^(1/3)*c - (-1)^(2/3)*a^(1/3)*d))]*Log[c + d*x])/d + (Log[c + d*x]*Log[a + b*x^3])/d - PolyLog[2, (b^(1/3)*(c + d*x))/(b^(1/3)*c - a^(1/3)*d)]/d - PolyLog[2, (b^(1/3)*(c + d*x))/(b^(1/3)*c + (-1)^(1/3)*a^(1/3)*d)]/d - PolyLog[2, (b^(1/3)*(c + d*x))/(b^(1/3)*c - (-1)^(2/3)*a^(1/3)*d)]/d}
{Log[a + b*x^3]/(c + d*x)^2, x, 15, -((Sqrt[3]*a^(1/3)*b^(2/3)*c*ArcTan[(a^(1/3) - 2*b^(1/3)*x)/(Sqrt[3]*a^(1/3))])/(b*c^3 - a*d^3)) + (Sqrt[3]*a^(2/3)*b^(1/3)*d*ArcTan[(a^(1/3) - 2*b^(1/3)*x)/(Sqrt[3]*a^(1/3))])/(b*c^3 - a*d^3) + (a^(1/3)*b^(2/3)*c*Log[a^(1/3) + b^(1/3)*x])/(b*c^3 - a*d^3) + (a^(2/3)*b^(1/3)*d*Log[a^(1/3) + b^(1/3)*x])/(b*c^3 - a*d^3) - (3*b*c^2*Log[c + d*x])/(d*(b*c^3 - a*d^3)) - (a^(1/3)*b^(2/3)*c*Log[a^(2/3) - a^(1/3)*b^(1/3)*x + b^(2/3)*x^2])/(2*(b*c^3 - a*d^3)) - (a^(2/3)*b^(1/3)*d*Log[a^(2/3) - a^(1/3)*b^(1/3)*x + b^(2/3)*x^2])/(2*(b*c^3 - a*d^3)) + (b*c^2*Log[a + b*x^3])/(d*(b*c^3 - a*d^3)) - Log[a + b*x^3]/(d*(c + d*x))}
{Log[a + b*x^3]/(c + d*x)^3, x, 16, (3*b*c^2)/(2*d*(b*c^3 - a*d^3)*(c + d*x)) + (3*Sqrt[3]*a^(2/3)*b^(4/3)*c^2*d*ArcTan[(a^(1/3) - 2*b^(1/3)*x)/(Sqrt[3]*a^(1/3))])/(2*(b*c^3 - a*d^3)^2) - (Sqrt[3]*a^(1/3)*b^(2/3)*(2*b*c^3 + a*d^3)*ArcTan[(a^(1/3) - 2*b^(1/3)*x)/(Sqrt[3]*a^(1/3))])/(2*(b*c^3 - a*d^3)^2) + (3*a^(2/3)*b^(4/3)*c^2*d*Log[a^(1/3) + b^(1/3)*x])/(2*(b*c^3 - a*d^3)^2) + (a^(1/3)*b^(2/3)*(2*b*c^3 + a*d^3)*Log[a^(1/3) + b^(1/3)*x])/(2*(b*c^3 - a*d^3)^2) - (3*b*c*(b*c^3 + 2*a*d^3)*Log[c + d*x])/(2*d*(b*c^3 - a*d^3)^2) - (3*a^(2/3)*b^(4/3)*c^2*d*Log[a^(2/3) - a^(1/3)*b^(1/3)*x + b^(2/3)*x^2])/(4*(b*c^3 - a*d^3)^2) - (a^(1/3)*b^(2/3)*(2*b*c^3 + a*d^3)*Log[a^(2/3) - a^(1/3)*b^(1/3)*x + b^(2/3)*x^2])/(4*(b*c^3 - a*d^3)^2) + (b*c*(b*c^3 + 2*a*d^3)*Log[a + b*x^3])/(2*d*(b*c^3 - a*d^3)^2) - Log[a + b*x^3]/(2*d*(c + d*x)^2)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Log[c+d x] / (a+b x^n)*)


{Log[c + d*x]/(a + b*x^2), x, 3, (Log[(d*(Sqrt[-a] - Sqrt[b]*x))/(Sqrt[b]*c + Sqrt[-a]*d)]*Log[c + d*x])/(2*Sqrt[-a]*Sqrt[b]) - (Log[-((d*(Sqrt[-a] + Sqrt[b]*x))/(Sqrt[b]*c - Sqrt[-a]*d))]*Log[c + d*x])/(2*Sqrt[-a]*Sqrt[b]) - PolyLog[2, (Sqrt[b]*(c + d*x))/(Sqrt[b]*c - Sqrt[-a]*d)]/(2*Sqrt[-a]*Sqrt[b]) + PolyLog[2, (Sqrt[b]*(c + d*x))/(Sqrt[b]*c + Sqrt[-a]*d)]/(2*Sqrt[-a]*Sqrt[b])}
{x*Log[c + d*x]/(a + b*x^2), x, 3, (Log[(d*(Sqrt[-a] - Sqrt[b]*x))/(Sqrt[b]*c + Sqrt[-a]*d)]*Log[c + d*x])/(2*b) + (Log[-((d*(Sqrt[-a] + Sqrt[b]*x))/(Sqrt[b]*c - Sqrt[-a]*d))]*Log[c + d*x])/(2*b) + PolyLog[2, (Sqrt[b]*(c + d*x))/(Sqrt[b]*c - Sqrt[-a]*d)]/(2*b) + PolyLog[2, (Sqrt[b]*(c + d*x))/(Sqrt[b]*c + Sqrt[-a]*d)]/(2*b)}


{Log[c + d*x]/(a + b*x^3), x, 6, -(((-1)^(1/3)*Log[(d*((-1)^(1/3)*a^(1/3) - b^(1/3)*x))/(b^(1/3)*c + (-1)^(1/3)*a^(1/3)*d)]*Log[c + d*x])/(3*a^(2/3)*b^(1/3))) + (Log[-((d*(a^(1/3) + b^(1/3)*x))/(b^(1/3)*c - a^(1/3)*d))]*Log[c + d*x])/(3*a^(2/3)*b^(1/3)) + ((-1)^(2/3)*Log[-((d*((-1)^(2/3)*a^(1/3) + b^(1/3)*x))/(b^(1/3)*c - (-1)^(2/3)*a^(1/3)*d))]*Log[c + d*x])/(3*a^(2/3)*b^(1/3)) + PolyLog[2, (b^(1/3)*(c + d*x))/(b^(1/3)*c - a^(1/3)*d)]/(3*a^(2/3)*b^(1/3)) - ((-1)^(1/3)*PolyLog[2, (b^(1/3)*(c + d*x))/(b^(1/3)*c + (-1)^(1/3)*a^(1/3)*d)])/(3*a^(2/3)*b^(1/3)) + ((-1)^(2/3)*PolyLog[2, (b^(1/3)*(c + d*x))/(b^(1/3)*c - (-1)^(2/3)*a^(1/3)*d)])/(3*a^(2/3)*b^(1/3))}
{(x*Log[c + d*x])/(a + b*x^3), x, 6, -(((-1)^(2/3)*Log[(d*((-1)^(1/3)*a^(1/3) - b^(1/3)*x))/(b^(1/3)*c + (-1)^(1/3)*a^(1/3)*d)]*Log[c + d*x])/(3*a^(1/3)*b^(2/3))) - (Log[-((d*(a^(1/3) + b^(1/3)*x))/(b^(1/3)*c - a^(1/3)*d))]*Log[c + d*x])/(3*a^(1/3)*b^(2/3)) + ((-1)^(1/3)*Log[-((d*((-1)^(2/3)*a^(1/3) + b^(1/3)*x))/(b^(1/3)*c - (-1)^(2/3)*a^(1/3)*d))]*Log[c + d*x])/(3*a^(1/3)*b^(2/3)) - PolyLog[2, (b^(1/3)*(c + d*x))/(b^(1/3)*c - a^(1/3)*d)]/(3*a^(1/3)*b^(2/3)) - ((-1)^(2/3)*PolyLog[2, (b^(1/3)*(c + d*x))/(b^(1/3)*c + (-1)^(1/3)*a^(1/3)*d)])/(3*a^(1/3)*b^(2/3)) + ((-1)^(1/3)*PolyLog[2, (b^(1/3)*(c + d*x))/(b^(1/3)*c - (-1)^(2/3)*a^(1/3)*d)])/(3*a^(1/3)*b^(2/3))}
{(x^2*Log[c + d*x])/(a + b*x^3), x, 4, (Log[(d*((-1)^(1/3)*a^(1/3) - b^(1/3)*x))/(b^(1/3)*c + (-1)^(1/3)*a^(1/3)*d)]*Log[c + d*x])/(3*b) + (Log[-((d*(a^(1/3) + b^(1/3)*x))/(b^(1/3)*c - a^(1/3)*d))]*Log[c + d*x])/(3*b) + (Log[-((d*((-1)^(2/3)*a^(1/3) + b^(1/3)*x))/(b^(1/3)*c - (-1)^(2/3)*a^(1/3)*d))]*Log[c + d*x])/(3*b) + PolyLog[2, (b^(1/3)*(c + d*x))/(b^(1/3)*c - a^(1/3)*d)]/(3*b) + PolyLog[2, (b^(1/3)*(c + d*x))/(b^(1/3)*c + (-1)^(1/3)*a^(1/3)*d)]/(3*b) + PolyLog[2, (b^(1/3)*(c + d*x))/(b^(1/3)*c - (-1)^(2/3)*a^(1/3)*d)]/(3*b)}


{Log[c + d*x]/(a + b*x^4), x, 9, (Log[(d*((-a)^(1/4) - b^(1/4)*x))/(b^(1/4)*c + (-a)^(1/4)*d)]*Log[c + d*x])/(4*(-a)^(3/4)*b^(1/4)) - (Log[-((d*((-a)^(1/4) + b^(1/4)*x))/(b^(1/4)*c - (-a)^(1/4)*d))]*Log[c + d*x])/(4*(-a)^(3/4)*b^(1/4)) + (Sqrt[-Sqrt[-a]]*Log[(d*(Sqrt[-a] - Sqrt[-Sqrt[-a]]*b^(1/4)*x))/(Sqrt[-Sqrt[-a]]*b^(1/4)*c + Sqrt[-a]*d)]*Log[c + d*x])/(4*a*b^(1/4)) - (Sqrt[-Sqrt[-a]]*Log[-((d*(Sqrt[-a] + Sqrt[-Sqrt[-a]]*b^(1/4)*x))/(Sqrt[-Sqrt[-a]]*b^(1/4)*c - Sqrt[-a]*d))]*Log[c + d*x])/(4*a*b^(1/4)) - PolyLog[2, (b^(1/4)*(c + d*x))/(b^(1/4)*c - (-a)^(1/4)*d)]/(4*(-a)^(3/4)*b^(1/4)) + PolyLog[2, (b^(1/4)*(c + d*x))/(b^(1/4)*c + (-a)^(1/4)*d)]/(4*(-a)^(3/4)*b^(1/4)) - (Sqrt[-Sqrt[-a]]*PolyLog[2, (Sqrt[-Sqrt[-a]]*b^(1/4)*(c + d*x))/(Sqrt[-Sqrt[-a]]*b^(1/4)*c - Sqrt[-a]*d)])/(4*a*b^(1/4)) + (Sqrt[-Sqrt[-a]]*PolyLog[2, (Sqrt[-Sqrt[-a]]*b^(1/4)*(c + d*x))/(Sqrt[-Sqrt[-a]]*b^(1/4)*c + Sqrt[-a]*d)])/(4*a*b^(1/4))}
{(x*Log[c + d*x])/(a + b*x^4), x, 7, -((Log[(d*(I*(-a)^(1/4) - b^(1/4)*x))/(b^(1/4)*c + I*(-a)^(1/4)*d)]*Log[c + d*x])/(4*Sqrt[-a]*Sqrt[b])) + (Log[(d*((-a)^(1/4) - b^(1/4)*x))/(b^(1/4)*c + (-a)^(1/4)*d)]*Log[c + d*x])/(4*Sqrt[-a]*Sqrt[b]) - (Log[-((d*(I*(-a)^(1/4) + b^(1/4)*x))/(b^(1/4)*c - I*(-a)^(1/4)*d))]*Log[c + d*x])/(4*Sqrt[-a]*Sqrt[b]) + (Log[-((d*((-a)^(1/4) + b^(1/4)*x))/(b^(1/4)*c - (-a)^(1/4)*d))]*Log[c + d*x])/(4*Sqrt[-a]*Sqrt[b]) + PolyLog[2, (b^(1/4)*(c + d*x))/(b^(1/4)*c - (-a)^(1/4)*d)]/(4*Sqrt[-a]*Sqrt[b]) - PolyLog[2, (b^(1/4)*(c + d*x))/(b^(1/4)*c - I*(-a)^(1/4)*d)]/(4*Sqrt[-a]*Sqrt[b]) - PolyLog[2, (b^(1/4)*(c + d*x))/(b^(1/4)*c + I*(-a)^(1/4)*d)]/(4*Sqrt[-a]*Sqrt[b]) + PolyLog[2, (b^(1/4)*(c + d*x))/(b^(1/4)*c + (-a)^(1/4)*d)]/(4*Sqrt[-a]*Sqrt[b])}
{(x^2*Log[c + d*x])/(a + b*x^4), x, 8, -((I*Log[(d*(I*(-a)^(1/4) - b^(1/4)*x))/(b^(1/4)*c + I*(-a)^(1/4)*d)]*Log[c + d*x])/(4*(-a)^(1/4)*b^(3/4))) + (Log[(d*((-a)^(1/4) - b^(1/4)*x))/(b^(1/4)*c + (-a)^(1/4)*d)]*Log[c + d*x])/(4*(-a)^(1/4)*b^(3/4)) + (I*Log[-((d*(I*(-a)^(1/4) + b^(1/4)*x))/(b^(1/4)*c - I*(-a)^(1/4)*d))]*Log[c + d*x])/(4*(-a)^(1/4)*b^(3/4)) - (Log[-((d*((-a)^(1/4) + b^(1/4)*x))/(b^(1/4)*c - (-a)^(1/4)*d))]*Log[c + d*x])/(4*(-a)^(1/4)*b^(3/4)) - PolyLog[2, (b^(1/4)*(c + d*x))/(b^(1/4)*c - (-a)^(1/4)*d)]/(4*(-a)^(1/4)*b^(3/4)) + (I*PolyLog[2, (b^(1/4)*(c + d*x))/(b^(1/4)*c - I*(-a)^(1/4)*d)])/(4*(-a)^(1/4)*b^(3/4)) - (I*PolyLog[2, (b^(1/4)*(c + d*x))/(b^(1/4)*c + I*(-a)^(1/4)*d)])/(4*(-a)^(1/4)*b^(3/4)) + PolyLog[2, (b^(1/4)*(c + d*x))/(b^(1/4)*c + (-a)^(1/4)*d)]/(4*(-a)^(1/4)*b^(3/4))}
{(x^3*Log[c + d*x])/(a + b*x^4), x, 5, (Log[(d*(I*(-a)^(1/4) - b^(1/4)*x))/(b^(1/4)*c + I*(-a)^(1/4)*d)]*Log[c + d*x])/(4*b) + (Log[(d*((-a)^(1/4) - b^(1/4)*x))/(b^(1/4)*c + (-a)^(1/4)*d)]*Log[c + d*x])/(4*b) + (Log[-((d*(I*(-a)^(1/4) + b^(1/4)*x))/(b^(1/4)*c - I*(-a)^(1/4)*d))]*Log[c + d*x])/(4*b) + (Log[-((d*((-a)^(1/4) + b^(1/4)*x))/(b^(1/4)*c - (-a)^(1/4)*d))]*Log[c + d*x])/(4*b) + PolyLog[2, (b^(1/4)*(c + d*x))/(b^(1/4)*c - (-a)^(1/4)*d)]/(4*b) + PolyLog[2, (b^(1/4)*(c + d*x))/(b^(1/4)*c - I*(-a)^(1/4)*d)]/(4*b) + PolyLog[2, (b^(1/4)*(c + d*x))/(b^(1/4)*c + I*(-a)^(1/4)*d)]/(4*b) + PolyLog[2, (b^(1/4)*(c + d*x))/(b^(1/4)*c + (-a)^(1/4)*d)]/(4*b)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Log[c (a+b x)^n]^p / (d + e x^2)*)


{Log[c*(a + b*x)^n]^3/(d + e*x^2), x, 11, (Log[c*(a + b*x)^n]^3*Log[(b*(Sqrt[-d] - Sqrt[e]*x))/(b*Sqrt[-d] + a*Sqrt[e])])/(2*Sqrt[-d]*Sqrt[e]) - (Log[c*(a + b*x)^n]^3*Log[(b*(Sqrt[-d] + Sqrt[e]*x))/(b*Sqrt[-d] - a*Sqrt[e])])/(2*Sqrt[-d]*Sqrt[e]) - (3*n*Log[c*(a + b*x)^n]^2*PolyLog[2, -((Sqrt[e]*(a + b*x))/(b*Sqrt[-d] - a*Sqrt[e]))])/(2*Sqrt[-d]*Sqrt[e]) + (3*n*Log[c*(a + b*x)^n]^2*PolyLog[2, (Sqrt[e]*(a + b*x))/(b*Sqrt[-d] + a*Sqrt[e])])/(2*Sqrt[-d]*Sqrt[e]) + (3*n^2*Log[c*(a + b*x)^n]*PolyLog[3, -((Sqrt[e]*(a + b*x))/(b*Sqrt[-d] - a*Sqrt[e]))])/(Sqrt[-d]*Sqrt[e]) - (3*n^2*Log[c*(a + b*x)^n]*PolyLog[3, (Sqrt[e]*(a + b*x))/(b*Sqrt[-d] + a*Sqrt[e])])/(Sqrt[-d]*Sqrt[e]) - (3*n^3*PolyLog[4, -((Sqrt[e]*(a + b*x))/(b*Sqrt[-d] - a*Sqrt[e]))])/(Sqrt[-d]*Sqrt[e]) + (3*n^3*PolyLog[4, (Sqrt[e]*(a + b*x))/(b*Sqrt[-d] + a*Sqrt[e])])/(Sqrt[-d]*Sqrt[e])}
{Log[c*(a + b*x)^n]^2/(d + e*x^2), x, 9, (Log[c*(a + b*x)^n]^2*Log[(b*(Sqrt[-d] - Sqrt[e]*x))/(b*Sqrt[-d] + a*Sqrt[e])])/(2*Sqrt[-d]*Sqrt[e]) - (Log[c*(a + b*x)^n]^2*Log[(b*(Sqrt[-d] + Sqrt[e]*x))/(b*Sqrt[-d] - a*Sqrt[e])])/(2*Sqrt[-d]*Sqrt[e]) - (n*Log[c*(a + b*x)^n]*PolyLog[2, -((Sqrt[e]*(a + b*x))/(b*Sqrt[-d] - a*Sqrt[e]))])/(Sqrt[-d]*Sqrt[e]) + (n*Log[c*(a + b*x)^n]*PolyLog[2, (Sqrt[e]*(a + b*x))/(b*Sqrt[-d] + a*Sqrt[e])])/(Sqrt[-d]*Sqrt[e]) + (n^2*PolyLog[3, -((Sqrt[e]*(a + b*x))/(b*Sqrt[-d] - a*Sqrt[e]))])/(Sqrt[-d]*Sqrt[e]) - (n^2*PolyLog[3, (Sqrt[e]*(a + b*x))/(b*Sqrt[-d] + a*Sqrt[e])])/(Sqrt[-d]*Sqrt[e])}
{Log[c*(a + b*x)^n]/(d + e*x^2), x, 3, (Log[c*(a + b*x)^n]*Log[(b*(Sqrt[-d] - Sqrt[e]*x))/(b*Sqrt[-d] + a*Sqrt[e])])/(2*Sqrt[-d]*Sqrt[e]) - (Log[c*(a + b*x)^n]*Log[(b*(Sqrt[-d] + Sqrt[e]*x))/(b*Sqrt[-d] - a*Sqrt[e])])/(2*Sqrt[-d]*Sqrt[e]) - (n*PolyLog[2, -((Sqrt[e]*(a + b*x))/(b*Sqrt[-d] - a*Sqrt[e]))])/(2*Sqrt[-d]*Sqrt[e]) + (n*PolyLog[2, (Sqrt[e]*(a + b*x))/(b*Sqrt[-d] + a*Sqrt[e])])/(2*Sqrt[-d]*Sqrt[e])}
{1/((d + e*x^2)*Log[c*(a + b*x)^n]), x, 1, (1/2)*Int[1/((d - Sqrt[-d]*Sqrt[e]*x)*Log[c*(a + b*x)^n]), x] + (1/2)*Int[1/((d + Sqrt[-d]*Sqrt[e]*x)*Log[c*(a + b*x)^n]), x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form Log[c (a+b x)^n]^p / (d + e x + f x^2)*)


(* Integrands of the form Log[c*(a+b*x)^n]^p/(d+e*x+f*x^2) where p is an integer *)
{Log[c*(a + b*x)^n]^3/(d*x + e*x^2), x, 12, (Log[-((b*x)/a)]*Log[c*(a + b*x)^n]^3)/d - (Log[c*(a + b*x)^n]^3*Log[(b*(d + e*x))/(b*d - a*e)])/d - (3*n*Log[c*(a + b*x)^n]^2*PolyLog[2, -((e*(a + b*x))/(b*d - a*e))])/d + (3*n*Log[c*(a + b*x)^n]^2*PolyLog[2, 1 + (b*x)/a])/d + (6*n^2*Log[c*(a + b*x)^n]*PolyLog[3, -((e*(a + b*x))/(b*d - a*e))])/d - (6*n^2*Log[c*(a + b*x)^n]*PolyLog[3, 1 + (b*x)/a])/d + (6*n^3*PolyLog[4, (a + b*x)/a])/d - (6*n^3*PolyLog[4, -((e*(a + b*x))/(b*d - a*e))])/d}
{Log[c*(a + b*x)^n]^2/(d*x + e*x^2), x, 10, (Log[-((b*x)/a)]*Log[c*(a + b*x)^n]^2)/d - (Log[c*(a + b*x)^n]^2*Log[(b*(d + e*x))/(b*d - a*e)])/d - (2*n*Log[c*(a + b*x)^n]*PolyLog[2, -((e*(a + b*x))/(b*d - a*e))])/d + (2*n*Log[c*(a + b*x)^n]*PolyLog[2, 1 + (b*x)/a])/d - (2*n^2*PolyLog[3, (a + b*x)/a])/d + (2*n^2*PolyLog[3, -((e*(a + b*x))/(b*d - a*e))])/d}
{Log[c*(a + b*x)^n]/(d*x + e*x^2), x, 5, (Log[-((b*x)/a)]*Log[c*(a + b*x)^n])/d - (Log[c*(a + b*x)^n]*Log[(b*(d + e*x))/(b*d - a*e)])/d - (n*PolyLog[2, -((e*(a + b*x))/(b*d - a*e))])/d + (n*PolyLog[2, 1 + (b*x)/a])/d}
{1/((d*x + e*x^2)*Log[c*(a + b*x)^n]), x, 2, Int[1/(x*Log[c*(a + b*x)^n]), x]/d - (e*Int[1/((d + e*x)*Log[c*(a + b*x)^n]), x])/d}

{Log[c*(a + b*x)^n]^3/(d + e*x + f*x^2), x, 11, (Log[c*(a + b*x)^n]^3*Log[-((b*(e - Sqrt[e^2 - 4*d*f] + 2*f*x))/(2*a*f - b*(e - Sqrt[e^2 - 4*d*f])))])/Sqrt[e^2 - 4*d*f] - (Log[c*(a + b*x)^n]^3*Log[-((b*(e + Sqrt[e^2 - 4*d*f] + 2*f*x))/(2*a*f - b*(e + Sqrt[e^2 - 4*d*f])))])/Sqrt[e^2 - 4*d*f] + (3*n*Log[c*(a + b*x)^n]^2*PolyLog[2, (2*f*(a + b*x))/(2*a*f - b*(e - Sqrt[e^2 - 4*d*f]))])/Sqrt[e^2 - 4*d*f] - (3*n*Log[c*(a + b*x)^n]^2*PolyLog[2, (2*f*(a + b*x))/(2*a*f - b*(e + Sqrt[e^2 - 4*d*f]))])/Sqrt[e^2 - 4*d*f] - (6*n^2*Log[c*(a + b*x)^n]*PolyLog[3, (2*f*(a + b*x))/(2*a*f - b*(e - Sqrt[e^2 - 4*d*f]))])/Sqrt[e^2 - 4*d*f] + (6*n^2*Log[c*(a + b*x)^n]*PolyLog[3, (2*f*(a + b*x))/(2*a*f - b*(e + Sqrt[e^2 - 4*d*f]))])/Sqrt[e^2 - 4*d*f] + (6*n^3*PolyLog[4, (2*f*(a + b*x))/(2*a*f - b*(e - Sqrt[e^2 - 4*d*f]))])/Sqrt[e^2 - 4*d*f] - (6*n^3*PolyLog[4, (2*f*(a + b*x))/(2*a*f - b*(e + Sqrt[e^2 - 4*d*f]))])/Sqrt[e^2 - 4*d*f]}
{Log[c*(a + b*x)^n]^2/(d + e*x + f*x^2), x, 9, (Log[c*(a + b*x)^n]^2*Log[-((b*(e - Sqrt[e^2 - 4*d*f] + 2*f*x))/(2*a*f - b*(e - Sqrt[e^2 - 4*d*f])))])/Sqrt[e^2 - 4*d*f] - (Log[c*(a + b*x)^n]^2*Log[-((b*(e + Sqrt[e^2 - 4*d*f] + 2*f*x))/(2*a*f - b*(e + Sqrt[e^2 - 4*d*f])))])/Sqrt[e^2 - 4*d*f] + (2*n*Log[c*(a + b*x)^n]*PolyLog[2, (2*f*(a + b*x))/(2*a*f - b*(e - Sqrt[e^2 - 4*d*f]))])/Sqrt[e^2 - 4*d*f] - (2*n*Log[c*(a + b*x)^n]*PolyLog[2, (2*f*(a + b*x))/(2*a*f - b*(e + Sqrt[e^2 - 4*d*f]))])/Sqrt[e^2 - 4*d*f] - (2*n^2*PolyLog[3, (2*f*(a + b*x))/(2*a*f - b*(e - Sqrt[e^2 - 4*d*f]))])/Sqrt[e^2 - 4*d*f] + (2*n^2*PolyLog[3, (2*f*(a + b*x))/(2*a*f - b*(e + Sqrt[e^2 - 4*d*f]))])/Sqrt[e^2 - 4*d*f]}
{Log[c*(a + b*x)^n]/(d + e*x + f*x^2), x, 3, (Log[c*(a + b*x)^n]*Log[-((b*(e - Sqrt[e^2 - 4*d*f] + 2*f*x))/(2*a*f - b*(e - Sqrt[e^2 - 4*d*f])))])/Sqrt[e^2 - 4*d*f] - (Log[c*(a + b*x)^n]*Log[-((b*(e + Sqrt[e^2 - 4*d*f] + 2*f*x))/(2*a*f - b*(e + Sqrt[e^2 - 4*d*f])))])/Sqrt[e^2 - 4*d*f] + (n*PolyLog[2, (2*f*(a + b*x))/(2*a*f - b*(e - Sqrt[e^2 - 4*d*f]))])/Sqrt[e^2 - 4*d*f] - (n*PolyLog[2, (2*f*(a + b*x))/(2*a*f - b*(e + Sqrt[e^2 - 4*d*f]))])/Sqrt[e^2 - 4*d*f]}
{1/((d + e*x + f*x^2)*Log[c*(a + b*x)^n]), x, 1, (2*f*Int[1/((e - Sqrt[e^2 - 4*d*f] + 2*f*x)*Log[c*(a + b*x)^n]), x])/Sqrt[e^2 - 4*d*f] - (2*f*Int[1/((e + Sqrt[e^2 - 4*d*f] + 2*f*x)*Log[c*(a + b*x)^n]), x])/Sqrt[e^2 - 4*d*f]}


(* ::Subsection::Closed:: *)
(*Integrands of the form Log[a+b x^n] / (c+d x)*)


(* Integrands of the form Log[a*x^n]/(c+d*x) *)
{Log[a*x]/(c + d*x), x, 1, (Log[a*x]*Log[(c + d*x)/c])/d + PolyLog[2, -((d*x)/c)]/d}
{Log[a/x]/(c + d*x), x, 1, (Log[a/x]*Log[(c + d*x)/c])/d - PolyLog[2, -((d*x)/c)]/d}
{Log[a*x^n]/(c + d*x), x, 1, (Log[a*x^n]*Log[(c + d*x)/c])/d + (n*PolyLog[2, -((d*x)/c)])/d}
{Log[x^n]/(a + b*x), x, 1, (Log[x^n]*Log[(a + b*x)/a])/b + (n*PolyLog[2, -((b*x)/a)])/b}


(* Integrands of the form Log[a+b*x^n]/x *)
{Log[a + b*x]/(c + d*x), x, 1, (Log[a + b*x]*Log[(b*(c + d*x))/(b*c - a*d)])/d + PolyLog[2, -((d*(a + b*x))/(b*c - a*d))]/d}
{Log[a + b/x]/(c + d*x), x, 7, (Log[a + b/x]*Log[c + d*x])/d + (Log[-((d*x)/c)]*Log[c + d*x])/d - (Log[-((d*(b + a*x))/(a*c - b*d))]*Log[c + d*x])/d - PolyLog[2, (a*(c + d*x))/(a*c - b*d)]/d + PolyLog[2, 1 + (d*x)/c]/d}
{Log[a + b*x^n]/(c + d*x), x, 0, Int[Log[a + b*x^n]/(c + d*x), x]}

{Log[(a + b*x)/x]/(c + d*x), x, 7, (Log[-((d*x)/c)]*Log[c + d*x])/d - (Log[-((d*(a + b*x))/(b*c - a*d))]*Log[c + d*x])/d + (Log[(a + b*x)/x]*Log[c + d*x])/d - PolyLog[2, (b*(c + d*x))/(b*c - a*d)]/d + PolyLog[2, 1 + (d*x)/c]/d}
{Log[(a + b*x^2)/x^2]/(c + d*x), x, 9, (2*Log[-((d*x)/c)]*Log[c + d*x])/d - (Log[(d*(Sqrt[-a] - Sqrt[b]*x))/(Sqrt[b]*c + Sqrt[-a]*d)]*Log[c + d*x])/d - (Log[-((d*(Sqrt[-a] + Sqrt[b]*x))/(Sqrt[b]*c - Sqrt[-a]*d))]*Log[c + d*x])/d + (Log[c + d*x]*Log[(a + b*x^2)/x^2])/d - PolyLog[2, (Sqrt[b]*(c + d*x))/(Sqrt[b]*c - Sqrt[-a]*d)]/d - PolyLog[2, (Sqrt[b]*(c + d*x))/(Sqrt[b]*c + Sqrt[-a]*d)]/d + (2*PolyLog[2, 1 + (d*x)/c])/d}
{Log[(a + b*x^n)/x^n]/(c + d*x), x, 1, Int[Log[b + a/x^n]/(c + d*x), x]}


(* ::Section::Closed:: *)
(*Integrands involving logarithms of trinomials*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Log[b x+c x^2]*)


(* Integrands of the form x^m*Log[d*(b*x+c*x^2)^n]^p where p is an integer *)
{Log[d*(b*x + c*x^2)^n], x, 5, -2*n*x + (b*n*Log[b + c*x])/c + x*Log[d*(b*x + c*x^2)^n]}
{Log[d*(b*x + c*x^2)^n]^2, x, 25, 8*n^2*x - (4*b*n^2*Log[b + c*x])/c - (2*b*n^2*Log[-((c*x)/b)]*Log[b + c*x])/c - (b*n^2*Log[b + c*x]^2)/c - 4*n*x*Log[d*(b*x + c*x^2)^n] + (2*b*n*Log[b + c*x]*Log[d*(b*x + c*x^2)^n])/c + x*Log[d*(b*x + c*x^2)^n]^2 - (2*b*n^2*PolyLog[2, 1 + (c*x)/b])/c}
{Log[d*(b*x + c*x^2)^n]/x, x, 7, (-(1/2))*n*Log[x]^2 - n*Log[x]*Log[(b + c*x)/b] + Log[x]*Log[d*(b*x + c*x^2)^n] - n*PolyLog[2, -((c*x)/b)]}

{Log[b*x + c*x^2], x, 4, -2*x + (b*Log[b + c*x])/c + x*Log[b*x + c*x^2]}
{x*Log[b*x + c*x^2], x, 5, (b*x)/(2*c) - x^2/2 - (b^2*Log[b + c*x])/(2*c^2) + (1/2)*x^2*Log[b*x + c*x^2]}
{x^2*Log[b*x + c*x^2], x, 5, -((b^2*x)/(3*c^2)) + (b*x^2)/(6*c) - (2*x^3)/9 + (b^3*Log[b + c*x])/(3*c^3) + (1/3)*x^3*Log[b*x + c*x^2]}
{x^3*Log[b*x + c*x^2], x, 5, (b^3*x)/(4*c^3) - (b^2*x^2)/(8*c^2) + (b*x^3)/(12*c) - x^4/8 - (b^4*Log[b + c*x])/(4*c^4) + (1/4)*x^4*Log[b*x + c*x^2]}
{Log[b*x + c*x^2]/x, x, 6, (-(1/2))*Log[x]^2 - Log[x]*Log[(b + c*x)/b] + Log[x]*Log[b*x + c*x^2] - PolyLog[2, -((c*x)/b)]}
{Log[b*x + c*x^2]/x^2, x, 5, -(1/x) + (c*Log[x])/b - (c*Log[b + c*x])/b - Log[b*x + c*x^2]/x}
{Log[b*x + c*x^2]/x^3, x, 5, -(1/(4*x^2)) - c/(2*b*x) - (c^2*Log[x])/(2*b^2) + (c^2*Log[b + c*x])/(2*b^2) - Log[b*x + c*x^2]/(2*x^2)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Log[a+b x+c x^2]*)


(* Integrands of the form x^m*Log[d*(a+b*x+c*x^2)^n]^p where p is an integer *)
{Log[d*(a + b*x + c*x^2)^n], x, 6, -2*n*x + (Sqrt[b^2 - 4*a*c]*n*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/c + (b*n*Log[a + b*x + c*x^2])/(2*c) + x*Log[d*(a + b*x + c*x^2)^n]}
(* {Log[d*(a + b*x + c*x^2)^n]^2, x, 0, 0} *)
{Log[d*(a + b*x + c*x^2)^n]/x, x, 10, (-n)*Log[x]*Log[(b - Sqrt[b^2 - 4*a*c] + 2*c*x)/(b - Sqrt[b^2 - 4*a*c])] - n*Log[x]*Log[(b + Sqrt[b^2 - 4*a*c] + 2*c*x)/(b + Sqrt[b^2 - 4*a*c])] + Log[x]*Log[d*(a + b*x + c*x^2)^n] - n*PolyLog[2, -((2*c*x)/(b - Sqrt[b^2 - 4*a*c]))] - n*PolyLog[2, -((2*c*x)/(b + Sqrt[b^2 - 4*a*c]))]}

{Log[1 + x + x^2], x, 5, -2*x + Sqrt[3]*ArcTan[(1 + 2*x)/Sqrt[3]] + (1/2)*Log[1 + x + x^2] + x*Log[1 + x + x^2]}
{Log[a + b*x + c*x^2], x, 5, -2*x + (Sqrt[b^2 - 4*a*c]*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/c + (b*Log[a + b*x + c*x^2])/(2*c) + x*Log[a + b*x + c*x^2]}
{x*Log[a + b*x + c*x^2], x, 6, (b*x)/(2*c) - x^2/2 - (b*Sqrt[b^2 - 4*a*c]*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(2*c^2) - ((b^2 - 2*a*c)*Log[a + b*x + c*x^2])/(4*c^2) + (1/2)*x^2*Log[a + b*x + c*x^2]}
{x^2*Log[a + b*x + c*x^2], x, 6, -(((b^2 - 2*a*c)*x)/(3*c^2)) + (b*x^2)/(6*c) - (2*x^3)/9 + ((b^4 - a*c*(5*b^2 - 4*a*c))*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(3*c^3*Sqrt[b^2 - 4*a*c]) + (b*(b^2 - 3*a*c)*Log[a + b*x + c*x^2])/(6*c^3) + (1/3)*x^3*Log[a + b*x + c*x^2]}
{x^3*Log[a + b*x + c*x^2], x, 6, (b*(b^2 - 3*a*c)*x)/(4*c^3) - ((b^2 - 2*a*c)*x^2)/(8*c^2) + (b*x^3)/(12*c) - x^4/8 - (b*(b^4 - 2*a*c*(3*b^2 - 4*a*c))*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(4*c^4*Sqrt[b^2 - 4*a*c]) - ((b^4 - 4*a*b^2*c + 2*a^2*c^2)*Log[a + b*x + c*x^2])/(8*c^4) + (1/4)*x^4*Log[a + b*x + c*x^2]}
{Log[a + b*x + c*x^2]/x, x, 9, (-Log[x])*Log[(b - Sqrt[b^2 - 4*a*c] + 2*c*x)/(b - Sqrt[b^2 - 4*a*c])] - Log[x]*Log[(b + Sqrt[b^2 - 4*a*c] + 2*c*x)/(b + Sqrt[b^2 - 4*a*c])] + Log[x]*Log[a + b*x + c*x^2] - PolyLog[2, -((2*c*x)/(b - Sqrt[b^2 - 4*a*c]))] - PolyLog[2, -((2*c*x)/(b + Sqrt[b^2 - 4*a*c]))]}
{Log[a + b*x + c*x^2]/x^2, x, 6, (Sqrt[b^2 - 4*a*c]*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/a + (b*Log[x])/a - (b*Log[a + b*x + c*x^2])/(2*a) - Log[a + b*x + c*x^2]/x}
{Log[a + b*x + c*x^2]/x^3, x, 6, -(b/(2*a*x)) - (b*Sqrt[b^2 - 4*a*c]*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(2*a^2) - ((b^2 - 2*a*c)*Log[x])/(2*a^2) + ((b^2 - 2*a*c)*Log[a + b*x + c*x^2])/(4*a^2) - Log[a + b*x + c*x^2]/(2*x^2)}

(* {Log[a + b*x + c*x^2]^2, x, 0, 0} *)


(* ::Subsection::Closed:: *)
(*Integrands of the form (d+e x)^m Log[a+b x+c x^2]*)


{Log[a + b*x + c*x^2]/(d + e*x), x, 9, -((Log[-((e*(b - Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c*d - (b - Sqrt[b^2 - 4*a*c])*e))]*Log[d + e*x])/e) - (Log[-((e*(b + Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c*d - (b + Sqrt[b^2 - 4*a*c])*e))]*Log[d + e*x])/e + (Log[d + e*x]*Log[a + b*x + c*x^2])/e - PolyLog[2, (2*c*(d + e*x))/(2*c*d - (b - Sqrt[b^2 - 4*a*c])*e)]/e - PolyLog[2, (2*c*(d + e*x))/(2*c*d - (b + Sqrt[b^2 - 4*a*c])*e)]/e}
{Log[a + b*x + c*x^2]/(d + e*x)^2, x, 6, (Sqrt[b^2 - 4*a*c]*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(c*d^2 - e*(b*d - a*e)) - ((2*c*d - b*e)*Log[d + e*x])/(e*(c*d^2 - e*(b*d - a*e))) + ((2*c*d - b*e)*Log[a + b*x + c*x^2])/(2*e*(c*d^2 - e*(b*d - a*e))) - Log[a + b*x + c*x^2]/(e*(d + e*x))}
{Log[a + b*x + c*x^2]/(d + e*x)^3, x, 7, (2*c*d - b*e)/(2*e*(c*d^2 - e*(b*d - a*e))*(d + e*x)) + (Sqrt[b^2 - 4*a*c]*(2*c*d - b*e)*ArcTanh[(b + 2*c*x)/Sqrt[b^2 - 4*a*c]])/(2*(c*d^2 - e*(b*d - a*e))^2) - ((2*c^2*d^2 + b^2*e^2 - 2*c*e*(b*d + a*e))*Log[d + e*x])/(2*e*(c*d^2 - e*(b*d - a*e))^2) + ((2*c^2*d^2 - 2*b*c*d*e + b^2*e^2 - 2*a*c*e^2)*Log[a + b*x + c*x^2])/(4*e*(c*d^2 - e*(b*d - a*e))^2) - Log[a + b*x + c*x^2]/(2*e*(d + e*x)^2)}


(* ::Section::Closed:: *)
(*Integrands involving logarithms of exponential functions*)


(* Integrands of the form x^m*Log[c+d*f^(a+b*x)] *)
{Log[1 + c*f^(a + b*x)], x, 1, -(PolyLog[2, -(c*f^(a + b*x))]/(b*Log[f]))}
{x*Log[1 + c*f^(a + b*x)], x, 2, -((x*PolyLog[2, (-c)*f^(a + b*x)])/(b*Log[f])) + PolyLog[3, (-c)*f^(a + b*x)]/(b^2*Log[f]^2)}
{x^2*Log[1 + c*f^(a + b*x)], x, 3, -((x^2*PolyLog[2, (-c)*f^(a + b*x)])/(b*Log[f])) + (2*x*PolyLog[3, (-c)*f^(a + b*x)])/(b^2*Log[f]^2) - (2*PolyLog[4, (-c)*f^(a + b*x)])/(b^3*Log[f]^3)}

{Log[a + b*E^x], x, 2, x*Log[a + b*E^x] - x*Log[1 + (b*E^x)/a] - PolyLog[2, -((b*E^x)/a)]}
{Log[c + d*f^(a + b*x)], x, 2, x*Log[c + d*f^(a + b*x)] - x*Log[1 + (d*f^(a + b*x))/c] - PolyLog[2, -((d*f^(a + b*x))/c)]/(b*Log[f])}
{x*Log[c + d*f^(a + b*x)], x, 3, (1/2)*x^2*Log[c + d*f^(a + b*x)] - (1/2)*x^2*Log[1 + (d*f^(a + b*x))/c] - (x*PolyLog[2, -((d*f^(a + b*x))/c)])/(b*Log[f]) + PolyLog[3, -((d*f^(a + b*x))/c)]/(b^2*Log[f]^2)}
{x^2*Log[c + d*f^(a + b*x)], x, 4, (1/3)*x^3*Log[c + d*f^(a + b*x)] - (1/3)*x^3*Log[1 + (d*f^(a + b*x))/c] - (x^2*PolyLog[2, -((d*f^(a + b*x))/c)])/(b*Log[f]) + (2*x*PolyLog[3, -((d*f^(a + b*x))/c)])/(b^2*Log[f]^2) - (2*PolyLog[4, -((d*f^(a + b*x))/c)])/(b^3*Log[f]^3)}


{Log[E^(a + b*x)], x, 3, Log[E^(a + b*x)]^2/(2*b)}
{Log[E^(a + b*x^n)], x, 3, -((b*n*x^(1 + n))/(1 + n)) + x*Log[E^(a + b*x^n)]}


{E^x*Log[a + b*E^x], x, 2, -E^x + ((a + b*E^x)*Log[a + b*E^x])/b}


{1/(x*Log[E^x]), x, -1, (-Log[x] + Log[Log[E^x]])/(x - Log[E^x])}


(* ::Section::Closed:: *)
(*Integrands involving logarithms of trig functions*)


(* ::Subsection::Closed:: *)
(*Integrands involving logarithms of circular trig functions*)


{Log[a*Sin[x]], x, 5, (I*x^2)/2 - x*Log[1 - E^(2*I*x)] + x*Log[a*Sin[x]] + (1/2)*I*PolyLog[2, E^(2*I*x)]}
{Log[a*Sin[x]^2], x, 6, I*x^2 - 2*x*Log[1 - E^(2*I*x)] + x*Log[a*Sin[x]^2] + I*PolyLog[2, E^(2*I*x)]}
{Log[a*Sin[x]^n], x, 6, (1/2)*I*n*x^2 - n*x*Log[1 - E^(2*I*x)] + x*Log[a*Sin[x]^n] + (1/2)*I*n*PolyLog[2, E^(2*I*x)]}

{Log[a*Cos[x]], x, 6, (I*x^2)/2 - x*Log[1 + E^(2*I*x)] + x*Log[a*Cos[x]] + (1/2)*I*PolyLog[2, -E^(2*I*x)]}
{Log[a*Cos[x]^2], x, 6, I*x^2 - 2*x*Log[1 + E^(2*I*x)] + x*Log[a*Cos[x]^2] + I*PolyLog[2, -E^(2*I*x)]}
{Log[a*Cos[x]^n], x, 6, (1/2)*I*n*x^2 - n*x*Log[1 + E^(2*I*x)] + x*Log[a*Cos[x]^n] + (1/2)*I*n*PolyLog[2, -E^(2*I*x)]}

{Log[a*Tan[x]], x, 6, 2*x*ArcTanh[E^(2*I*x)] + x*Log[a*Tan[x]] - (1/2)*I*PolyLog[2, -E^(2*I*x)] + (1/2)*I*PolyLog[2, E^(2*I*x)]}
{Log[a*Tan[x]^2], x, 7, 4*x*ArcTanh[E^(2*I*x)] + x*Log[a*Tan[x]^2] - I*PolyLog[2, -E^(2*I*x)] + I*PolyLog[2, E^(2*I*x)]}
{Log[a*Tan[x]^n], x, 7, 2*n*x*ArcTanh[E^(2*I*x)] + x*Log[a*Tan[x]^n] - (1/2)*I*n*PolyLog[2, -E^(2*I*x)] + (1/2)*I*n*PolyLog[2, E^(2*I*x)]}

{Log[a*Cot[x]], x, 7, -2*x*ArcTanh[E^(2*I*x)] + x*Log[a*Cot[x]] + (1/2)*I*PolyLog[2, -E^(2*I*x)] - (1/2)*I*PolyLog[2, E^(2*I*x)]}
{Log[a*Cot[x]^2], x, 7, -4*x*ArcTanh[E^(2*I*x)] + x*Log[a*Cot[x]^2] + I*PolyLog[2, -E^(2*I*x)] - I*PolyLog[2, E^(2*I*x)]}
{Log[a*Cot[x]^n], x, 7, -2*n*x*ArcTanh[E^(2*I*x)] + x*Log[a*Cot[x]^n] + (1/2)*I*n*PolyLog[2, -E^(2*I*x)] - (1/2)*I*n*PolyLog[2, E^(2*I*x)]}

{Log[a*Sec[x]], x, 5, -((I*x^2)/2) + x*Log[1 + E^(2*I*x)] + x*Log[a*Sec[x]] - (1/2)*I*PolyLog[2, -E^(2*I*x)]}
{Log[a*Sec[x]^2], x, 6, (-I)*x^2 + 2*x*Log[1 + E^(2*I*x)] + x*Log[a*Sec[x]^2] - I*PolyLog[2, -E^(2*I*x)]}
{Log[a*Sec[x]^n], x, 6, (-(1/2))*I*n*x^2 + n*x*Log[1 + E^(2*I*x)] + x*Log[a*Sec[x]^n] - (1/2)*I*n*PolyLog[2, -E^(2*I*x)]}

{Log[a*Csc[x]], x, 6, -((I*x^2)/2) + x*Log[1 - E^(2*I*x)] + x*Log[a*Csc[x]] - (1/2)*I*PolyLog[2, E^(2*I*x)]}
{Log[a*Csc[x]^2], x, 6, (-I)*x^2 + 2*x*Log[1 - E^(2*I*x)] + x*Log[a*Csc[x]^2] - I*PolyLog[2, E^(2*I*x)]}
{Log[a*Csc[x]^n], x, 6, (-(1/2))*I*n*x^2 + n*x*Log[1 - E^(2*I*x)] + x*Log[a*Csc[x]^n] - (1/2)*I*n*PolyLog[2, E^(2*I*x)]}


(* Integrands involving logarithms of trig functions *)
{Cos[x]*Log[(1 - Cos[2*x])/2], x, 2, -2*Sin[x] + Log[Sin[x]^2]*Sin[x]}
{Cot[x]/Log[E*Sin[x]], x, 3, Log[1 + Log[Sin[x]]]}
{Cot[x]/Log[E^Sin[x]], x, -1, (Log[Log[E^Sin[x]]] - Log[Sin[x]])/(-Log[E^Sin[x]] + Sin[x])}
{Log[Cos[x]]*Sec[x]^2, x, 3, -x + Tan[x] + Log[Cos[x]]*Tan[x]}
{Cot[x]*Log[Sin[x]], x, 3, Log[Sin[x]]^2/2}
{Cos[x]*Log[Sin[x]]*Sin[x]^2, x, 2, (-(1/9))*Sin[x]^3 + (1/3)*Log[Sin[x]]*Sin[x]^3}
{Log[Sin[a/2 + b*x/2]*Cos[a/2 + b*x/2]]*Cos[a + b*x], x, 2, -(Sin[a + b*x]/b) + (Log[(1/2)*Sin[a + b*x]]*Sin[a + b*x])/b}
{Tan[x]/Log[Cos[x]], x, 3, -Log[Log[Cos[x]]]}
{Csc[x]*Log[Tan[x]]*Sec[x], x, 2, Log[Tan[x]]^2/2}
{Csc[2*x]*Log[Tan[x]], x, 3, Log[Tan[x]]^2/4}


(* ::Subsection::Closed:: *)
(*Integrands involving logarithms of hyperbolic trig functions*)


{Log[a*Sinh[x]], x, 5, x^2/2 - x*Log[1 - E^(2*x)] + x*Log[a*Sinh[x]] - (1/2)*PolyLog[2, E^(2*x)]}
{Log[a*Sinh[x]^2], x, 6, x^2 - 2*x*Log[1 - E^(2*x)] + x*Log[a*Sinh[x]^2] - PolyLog[2, E^(2*x)]}
{Log[a*Sinh[x]^n], x, 6, (n*x^2)/2 - n*x*Log[1 - E^(2*x)] + x*Log[a*Sinh[x]^n] - (1/2)*n*PolyLog[2, E^(2*x)]}

{Log[a*Cosh[x]], x, 5, x^2/2 - x*Log[1 + E^(2*x)] + x*Log[a*Cosh[x]] - (1/2)*PolyLog[2, -E^(2*x)]}
{Log[a*Cosh[x]^2], x, 6, x^2 - 2*x*Log[1 + E^(2*x)] + x*Log[a*Cosh[x]^2] - PolyLog[2, -E^(2*x)]}
{Log[a*Cosh[x]^n], x, 6, (n*x^2)/2 - n*x*Log[1 + E^(2*x)] + x*Log[a*Cosh[x]^n] - (1/2)*n*PolyLog[2, -E^(2*x)]}

{Log[Tanh[x]], x, 6, 2*x*ArcTanh[E^(2*x)] + x*Log[Tanh[x]] + (1/2)*PolyLog[2, -E^(2*x)] - (1/2)*PolyLog[2, E^(2*x)]}
{Log[a*Tanh[x]], x, 6, 2*x*ArcTanh[E^(2*x)] + x*Log[a*Tanh[x]] + (1/2)*PolyLog[2, -E^(2*x)] - (1/2)*PolyLog[2, E^(2*x)]}
{Log[a*Tanh[x]^2], x, 7, 4*x*ArcTanh[E^(2*x)] + x*Log[a*Tanh[x]^2] + PolyLog[2, -E^(2*x)] - PolyLog[2, E^(2*x)]}
{Log[a*Tanh[x]^n], x, 7, 2*n*x*ArcTanh[E^(2*x)] + x*Log[a*Tanh[x]^n] + (1/2)*n*PolyLog[2, -E^(2*x)] - (1/2)*n*PolyLog[2, E^(2*x)]}

{Log[Coth[x]], x, 7, -2*x*ArcTanh[E^(2*x)] + x*Log[Coth[x]] - (1/2)*PolyLog[2, -E^(2*x)] + (1/2)*PolyLog[2, E^(2*x)]}
{Log[a*Coth[x]], x, 7, -2*x*ArcTanh[E^(2*x)] + x*Log[a*Coth[x]] - (1/2)*PolyLog[2, -E^(2*x)] + (1/2)*PolyLog[2, E^(2*x)]}
{Log[a*Coth[x]^2], x, 7, -4*x*ArcTanh[E^(2*x)] + x*Log[a*Coth[x]^2] - PolyLog[2, -E^(2*x)] + PolyLog[2, E^(2*x)]}
{Log[a*Coth[x]^n], x, 7, -2*n*x*ArcTanh[E^(2*x)] + x*Log[a*Coth[x]^n] - (1/2)*n*PolyLog[2, -E^(2*x)] + (1/2)*n*PolyLog[2, E^(2*x)]}

{Log[a*Sech[x]], x, 6, -(x^2/2) + x*Log[1 + E^(2*x)] + x*Log[a*Sech[x]] + (1/2)*PolyLog[2, -E^(2*x)]}
{Log[a*Sech[x]^2], x, 6, -x^2 + 2*x*Log[1 + E^(2*x)] + x*Log[a*Sech[x]^2] + PolyLog[2, -E^(2*x)]}
{Log[a*Sech[x]^n], x, 6, -((n*x^2)/2) + n*x*Log[1 + E^(2*x)] + x*Log[a*Sech[x]^n] + (1/2)*n*PolyLog[2, -E^(2*x)]}

{Log[a*Csch[x]], x, 6, -(x^2/2) + x*Log[1 - E^(2*x)] + x*Log[a*Csch[x]] + (1/2)*PolyLog[2, E^(2*x)]}
{Log[a*Csch[x]^2], x, 6, -x^2 + 2*x*Log[1 - E^(2*x)] + x*Log[a*Csch[x]^2] + PolyLog[2, E^(2*x)]}
{Log[a*Csch[x]^n], x, 6, -((n*x^2)/2) + n*x*Log[1 - E^(2*x)] + x*Log[a*Csch[x]^n] + (1/2)*n*PolyLog[2, E^(2*x)]}


(* ::Section::Closed:: *)
(*Problems from Calculus textbooks*)


(* ::Subsection::Closed:: *)
(*Anton Calculus, 4th Edition*)


{Log[x]/Sqrt[x], x, 1, -4*Sqrt[x] + 2*Sqrt[x]*Log[x]}
{x*Log[2 - 3*x^2], x, 2, -(x^2/2) - (1/6)*(2 - 3*x^2)*Log[2 - 3*x^2]}


(* ::Subsection::Closed:: *)
(*Apostol Calculus, Volume 1, 2nd Edition, Section 6.9*)


{Log[x]^2, x, 2, 2*x - 2*x*Log[x] + x*Log[x]^2}
{x*Log[x], x, 1, -(x^2/4) + (1/2)*x^2*Log[x]}
{x*Log[x]^2, x, 2, x^2/4 - (1/2)*x^2*Log[x] + (1/2)*x^2*Log[x]^2}
{x^m*Log[x], x, 1, -(x^(1 + m)/(1 + m)^2) + (x^(1 + m)*Log[x])/(1 + m)}
{x^(m + n)*Log[x], x, 1, -(x^(1 + m + n)/(1 + m + n)^2) + (x^(1 + m + n)*Log[x])/(1 + m + n)}
{x^m*Log[a*x], x, 1, -(x^(1 + m)/(1 + m)^2) + (x^(1 + m)*Log[a*x])/(1 + m)}
{x^2*Log[x]^2, x, 2, (2*x^3)/27 - (2/9)*x^3*Log[x] + (1/3)*x^3*Log[x]^2}
{x^3*Log[x]^3, x, 3, -((3*x^4)/128) + (3/32)*x^4*Log[x] - (3/16)*x^4*Log[x]^2 + (1/4)*x^4*Log[x]^3}


(* ::Subsection::Closed:: *)
(*Edwards and Penney Calculus*)


{1/(x*Sqrt[1 - Log[x]^2]), x, 2, ArcSin[Log[x]]}


(* ::Subsection::Closed:: *)
(*Thomas Calculus, 8th Edition*)


{16*x^3*Log[x]^2, x, 3, x^4/2 - 2*x^4*Log[x] + 4*x^4*Log[x]^2}
{Log[Sqrt[a + b*x]], x, 1, -(x/2) + ((a + b*x)*Log[Sqrt[a + b*x]])/b}
{x*Log[Sqrt[2 + x]], x, 5, x/2 - x^2/8 + (1/2)*x^2*Log[Sqrt[2 + x]] - Log[2 + x]}
{x*Log[(1 + 3*x)^(1/3)], x, 5, x/18 - x^2/12 + (1/2)*x^2*Log[(1 + 3*x)^(1/3)] - (1/54)*Log[1 + 3*x]}
{x*Log[x + x^3], x, 5, -((3*x^2)/4) + (1/2)*Log[1 + x^2] + (1/2)*x^2*Log[x + x^3]}
{Log[x + Sqrt[1 + x^2]], x, 3, -Sqrt[1 + x^2] + x*Log[x + Sqrt[1 + x^2]]}
{Log[x + Sqrt[-1 + x^2]], x, 3, -Sqrt[-1 + x^2] + x*Log[x + Sqrt[-1 + x^2]]}
{Log[x - Sqrt[-1 + x^2]], x, 4, Sqrt[-1 + x^2] + x*Log[x - Sqrt[-1 + x^2]]}
{Log[Sqrt[x] + Sqrt[1 + x]], x, 5, (-(1/2))*Sqrt[x/(1 + x)]*(1 + x) + (1/2)*ArcTanh[Sqrt[x/(1 + x)]] + x*Log[Sqrt[x] + Sqrt[1 + x]]}


(* ::Section::Closed:: *)
(*Problems from integration competitions*)


(* ::Subsection::Closed:: *)
(*MIT Integration Competition*)


{x^(1/3)*Log[x], x, 1, -((9*x^(4/3))/16) + (3/4)*x^(4/3)*Log[x]}


(* ::Subsection::Closed:: *)
(*University of Wisconsin Integration Competition*)


{2^Log[x], x, 2, x^(1 + Log[2])/(1 + Log[2])}
{(1 - Log[x])/x^2, x, 4, Log[x]/x}


(* ::Section::Closed:: *)
(*Miscellaneous problems*)


(* Problems contributed by Michael Wester *)

(* => x log|x^2 - a^2| - 2 x + a log|(x + a)/(x - a)|
      [Gradshteyn and Ryzhik 2.736(1)] *)
(* {Log[Abs[x^2 - a^2]], x, 0, x*Log[Abs[x^2 - a^2]] - 2*x + a*Log[(x + a)/(x - a)]} *)
{ComplexExpand[Log[Abs[x^2 - a^2]]], x, 3, -2*x + 2*a*ArcTanh[x/a] + (1/2)*x*Log[(a^2 - x^2)^2]}


{Log[1 + x + Sqrt[1 + x]], x, 3, -1 - x + Sqrt[1 + x] + Log[Sqrt[1 + x]] + x*Log[1 + x + Sqrt[1 + x]]}
{Log[x + x^3], x, 4, -3*x + 2*ArcTan[x] + x*Log[x + x^3]}
{2^Log[-8 + 7*x], x, 2, (-8 + 7*x)^(1 + Log[2])/(7*(1 + Log[2]))}
{Log[(-11 + 5*x)/(5 + 76*x)], x, 6, (-(11/5))*Log[11 - 5*x] + x*Log[-((11 - 5*x)/(5 + 76*x))] - (5/76)*Log[5 + 76*x]}
{Log[(1 + x)/(-1 + x)]/x^2, x, 3, -2*ArcTanh[1 - 2*x^2] - Log[-((1 + x)/(1 - x))]/x}
{Log[(13 + x)^(-1)], x, 1, x + (13 + x)*Log[(13 + x)^(-1)]}
{x*Log[(1 + x)/x^2], x, 6, x/2 + x^2/4 - (1/2)*Log[1 + x] + (1/2)*x^2*Log[(1 + x)/x^2]}
{x^3*Log[(7 + 5*x)/x^2], x, 6, (343*x)/500 - (49*x^2)/200 + (7*x^3)/60 + x^4/16 - (2401*Log[7 + 5*x])/2500 + (1/4)*x^4*Log[(7 + 5*x)/x^2]}
(* {x^3*Log[d + c*x]^4, x, 89, (c*x*(-70140*d^3 + 5190*c*d^2*x - 700*c^2*d*x^2 + 81*c^3*x^3) + 12*(5845*d^4 + 4980*c*d^3*x - 690*c^2*d^2*x^2 + 148*c^3*d*x^3 - 27*c^4*x^4)*Log[d + c*x] - 72*(415*d^4 + 300*c*d^3*x - 78*c^2*d^2*x^2 + 28*c^3*d*x^3 - 9*c^4*x^4)*Log[d + c*x]^2 + 288*(25*d^4 + 12*c*d^3*x - 6*c^2*d^2*x^2 + 4*c^3*d*x^3 - 3*c^4*x^4)*Log[d + c*x]^3 - 864*(d^4 - c^4*x^4)*Log[d + c*x]^4)/(3456*c^4)} *)


(* Integrands of the form (a+b*x)^m*Log[a+b*x] where m is an integer *)
{(a + b*x)*Log[a + b*x], x, 2, -((a + b*x)^2/(4*b)) + ((a + b*x)^2*Log[a + b*x])/(2*b)}
{(a + b*x)^2*Log[a + b*x], x, 2, -((a + b*x)^3/(9*b)) + ((a + b*x)^3*Log[a + b*x])/(3*b)}
{Log[a + b*x]/(a + b*x), x, 2, Log[a + b*x]^2/(2*b)}
{Log[a + b*x]/(a + b*x)^2, x, 2, -(1/(b*(a + b*x))) - Log[a + b*x]/(b*(a + b*x))}
{(a + b*x)^n*Log[a + b*x], x, 2, -((a + b*x)^(1 + n)/(b*(1 + n)^2)) + ((a + b*x)^(1 + n)*Log[a + b*x])/(b*(1 + n))}


(* Integrands of the form Log[(a+b*x)/(c+d*x)]^m/x where m is an integer *)
{Log[(a + b*x)/(c + d*x)]/x, x, 5, (-Log[(b*c - a*d)/(b*(c + d*x))])*Log[(a + b*x)/(c + d*x)] + Log[-(((b*c - a*d)*x)/(a*(c + d*x)))]*Log[(a + b*x)/(c + d*x)] - PolyLog[2, (d*(a/b + x))/(c + d*x)] + PolyLog[2, (c*(1 + (b*x)/a))/(c + d*x)]}
{Log[(a + b*x)/(c + d*x)]^2/x, x, 9, (-Log[(b*c - a*d)/(b*(c + d*x))])*Log[(a + b*x)/(c + d*x)]^2 + Log[-(((b*c - a*d)*x)/(a*(c + d*x)))]*Log[(a + b*x)/(c + d*x)]^2 - 2*Log[(a + b*x)/(c + d*x)]*PolyLog[2, (d*(a/b + x))/(c + d*x)] + 2*Log[(a + b*x)/(c + d*x)]*PolyLog[2, (c*(a + b*x))/(a*(c + d*x))] - 2*PolyLog[3, (c*(a + b*x))/(a*(c + d*x))] + 2*PolyLog[3, (d*(a + b*x))/(b*(c + d*x))]}
{Log[(a + b*x)/(c + d*x)]^3/x, x, 11, (-Log[(b*c - a*d)/(b*(c + d*x))])*Log[(a + b*x)/(c + d*x)]^3 + Log[-(((b*c - a*d)*x)/(a*(c + d*x)))]*Log[(a + b*x)/(c + d*x)]^3 - 3*Log[(a + b*x)/(c + d*x)]^2*PolyLog[2, (d*(a/b + x))/(c + d*x)] + 3*Log[(a + b*x)/(c + d*x)]^2*PolyLog[2, (c*(a + b*x))/(a*(c + d*x))] + 6*Log[(a + b*x)/(c + d*x)]*PolyLog[3, (d*(a/b + x))/(c + d*x)] - 6*Log[(a + b*x)/(c + d*x)]*PolyLog[3, (c*(a + b*x))/(a*(c + d*x))] + 6*PolyLog[4, (c*(a + b*x))/(a*(c + d*x))] - 6*PolyLog[4, (d*(a + b*x))/(b*(c + d*x))]}


(* Integrands of the form x^m*Log[a*Log[b*x^n]^p] *)
{Log[a*Log[b*x]^p], x, 2, x*Log[a*Log[b*x]^p] - (p*LogIntegral[b*x])/b}
{Log[a*Log[b*x^n]^p], x, 2, ((-p)*x*ExpIntegralEi[Log[b*x^n]/n])/(b*x^n)^n^(-1) + x*Log[a*Log[b*x^n]^p]}
{Log[a*Log[b*x]^p]/x, x, 1, (-Log[b*x])*(p - Log[a*Log[b*x]^p])}
{Log[a*Log[b*x^n]^p]/x, x, 1, -((Log[b*x^n]*(p - Log[a*Log[b*x^n]^p]))/n)}
{x^m*Log[a*Log[b*x]^p], x, 2, -((p*x^(1 + m)*(b*x)^(-1 - m)*ExpIntegralEi[(1 + m)*Log[b*x]])/(1 + m)) + (x^(1 + m)*Log[a*Log[b*x]^p])/(1 + m)}
{x^m*Log[a*Log[b*x^n]^p], x, 2, -((p*x^(1 + m)*ExpIntegralEi[((1 + m)*Log[b*x^n])/n])/((b*x^n)^((1 + m)/n)*(1 + m))) + (x^(1 + m)*Log[a*Log[b*x^n]^p])/(1 + m)}


(* Integrands of the form (A+B*Log[x])/Sqrt[a+b*Log[x]] *)
{Log[x]/Sqrt[a + b*Log[x]], x, 4, -(((2*a + b)*Sqrt[Pi]*Erfi[Sqrt[a + b*Log[x]]/Sqrt[b]])/(E^(a/b)*(2*b^(3/2)))) + (x*Sqrt[a + b*Log[x]])/b}
{Log[x]/Sqrt[a - b*Log[x]], x, 4, -(((2*a - b)*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a - b*Log[x]]/Sqrt[b]])/(2*b^(3/2))) - (x*Sqrt[a - b*Log[x]])/b}

{(A + B*Log[x])/Sqrt[a + b*Log[x]], x, 4, ((2*A*b - (2*a + b)*B)*Sqrt[Pi]*Erfi[Sqrt[a + b*Log[x]]/Sqrt[b]])/(E^(a/b)*(2*b^(3/2))) + (B*x*Sqrt[a + b*Log[x]])/b}
{(A + B*Log[x])/Sqrt[a - b*Log[x]], x, 4, -(((2*A*b + (2*a - b)*B)*E^(a/b)*Sqrt[Pi]*Erf[Sqrt[a - b*Log[x]]/Sqrt[b]])/(2*b^(3/2))) - (B*x*Sqrt[a - b*Log[x]])/b}


(* Integrands of the form Log[x]*f[a+b*x]^n where n is an integer *)
{Log[x]*E^(a + b*x), x, 3, -((E^a*ExpIntegralEi[b*x])/b) + (E^(a + b*x)*Log[x])/b}

{Log[x]*Sin[a + b*x], x, 5, (Cos[a]*CosIntegral[b*x])/b - (Cos[a + b*x]*Log[x])/b - (Sin[a]*SinIntegral[b*x])/b}
{Log[x]*Sin[a + b*x]^2, x, 5, -(x/2) + (CosIntegral[2*b*x]*Sin[2*a])/(4*b) + (1/2)*Log[x]*(x - (Cos[a + b*x]*Sin[a + b*x])/b) + (Cos[2*a]*SinIntegral[2*b*x])/(4*b)}
{Log[x]*Sin[a + b*x]^3, x, 15, (3*Cos[a]*CosIntegral[b*x])/(4*b) - (Cos[3*a]*CosIntegral[3*b*x])/(12*b) - (Cos[a + b*x]*(3 - Cos[a + b*x]^2)*Log[x])/(3*b) - (3*Sin[a]*SinIntegral[b*x])/(4*b) + (Sin[3*a]*SinIntegral[3*b*x])/(12*b)}

{Log[x]*Cos[a + b*x], x, 5, -((CosIntegral[b*x]*Sin[a])/b) + (Log[x]*Sin[a + b*x])/b - (Cos[a]*SinIntegral[b*x])/b}
{Log[x]*Cos[a + b*x]^2, x, 5, -(x/2) - (CosIntegral[2*b*x]*Sin[2*a])/(4*b) + (1/2)*Log[x]*(x + (Cos[a + b*x]*Sin[a + b*x])/b) - (Cos[2*a]*SinIntegral[2*b*x])/(4*b)}
{Log[x]*Cos[a + b*x]^3, x, 15, -((3*CosIntegral[b*x]*Sin[a])/(4*b)) - (CosIntegral[3*b*x]*Sin[3*a])/(12*b) + (Log[x]*Sin[a + b*x]*(3 - Sin[a + b*x]^2))/(3*b) - (3*Cos[a]*SinIntegral[b*x])/(4*b) - (Cos[3*a]*SinIntegral[3*b*x])/(12*b)}

{Log[x]*Sinh[a + b*x], x, 5, -((Cosh[a]*CoshIntegral[b*x])/b) + (Cosh[a + b*x]*Log[x])/b - (Sinh[a]*SinhIntegral[b*x])/b}
{Log[x]*Sinh[a + b*x]^2, x, 5, x/2 - (CoshIntegral[2*b*x]*Sinh[2*a])/(4*b) - (1/2)*Log[x]*(x - (Cosh[a + b*x]*Sinh[a + b*x])/b) - (Cosh[2*a]*SinhIntegral[2*b*x])/(4*b)}
{Log[x]*Sinh[a + b*x]^3, x, 15, (3*Cosh[a]*CoshIntegral[b*x])/(4*b) - (Cosh[3*a]*CoshIntegral[3*b*x])/(12*b) - (Cosh[a + b*x]*(3 - Cosh[a + b*x]^2)*Log[x])/(3*b) + (3*Sinh[a]*SinhIntegral[b*x])/(4*b) - (Sinh[3*a]*SinhIntegral[3*b*x])/(12*b)}

{Log[x]*Cosh[a + b*x], x, 5, -((CoshIntegral[b*x]*Sinh[a])/b) + (Log[x]*Sinh[a + b*x])/b - (Cosh[a]*SinhIntegral[b*x])/b}
{Log[x]*Cosh[a + b*x]^2, x, 5, -(x/2) - (CoshIntegral[2*b*x]*Sinh[2*a])/(4*b) + (1/2)*Log[x]*(x + (Cosh[a + b*x]*Sinh[a + b*x])/b) - (Cosh[2*a]*SinhIntegral[2*b*x])/(4*b)}
{Log[x]*Cosh[a + b*x]^3, x, 15, -((3*CoshIntegral[b*x]*Sinh[a])/(4*b)) - (CoshIntegral[3*b*x]*Sinh[3*a])/(12*b) + (Log[x]*Sinh[a + b*x]*(3 + Sinh[a + b*x]^2))/(3*b) - (3*Cosh[a]*SinhIntegral[b*x])/(4*b) - (Cosh[3*a]*SinhIntegral[3*b*x])/(12*b)}

{Log[Sinh[a/2 + b*x/2]*Cosh[a/2 + b*x/2]]*Cosh[a + b*x], x, 2, -(Sinh[a + b*x]/b) + (Log[(1/2)*Sinh[a + b*x]]*Sinh[a + b*x])/b}

{x*Sqrt[4 + x^2]*Log[x], x, 5, (-(4/3))*Sqrt[4 + x^2] - (1/9)*(4 + x^2)^(3/2) + (8/3)*ArcTanh[Sqrt[4 + x^2]/2] + (1/3)*(4 + x^2)^(3/2)*Log[x]}
{(x*Log[x])/Sqrt[-1 + x^2], x, 3, -Sqrt[-1 + x^2] + ArcTan[Sqrt[-1 + x^2]] + Sqrt[-1 + x^2]*Log[x]}

{Log[Cos[x]]*Tan[x], x, 3, -Log[Cos[x]]^2/2}
{Log[Cos[x]]*Sin[x], x, 2, Cos[x] - Cos[x]*Log[Cos[x]]}
{Log[Cos[x]]*Cos[x], x, 4, ArcTanh[Sin[x]] - Sin[x] + Log[Cos[x]]*Sin[x]}

{Log[Sin[x]]*Cos[x], x, 2, -Sin[x] + Log[Sin[x]]*Sin[x]}
{Log[Sin[x]]*Sin[x]^2, x, 9, x/4 + (I*x^2)/4 - (1/2)*x*Log[1 - E^(2*I*x)] + (1/4)*I*PolyLog[2, E^(2*I*x)] + (1/4)*Cos[x]*Sin[x] + (1/2)*Log[Sin[x]]*(x - Cos[x]*Sin[x])}
{Log[Sin[x]]*Sin[x]^3, x, 8, (-(2/3))*ArcTanh[Cos[x]] + (2*Cos[x])/3 - Cos[x]^3/9 - (1/3)*Cos[x]*(3 - Cos[x]^2)*Log[Sin[x]]}
{Log[Sin[Sqrt[x]]], x, 7, (I/3)*x^(3/2) - x*Log[1 - E^((2*I)*Sqrt[x])] + x*Log[Sin[Sqrt[x]]] + I*Sqrt[x]*PolyLog[2, E^((2*I)*Sqrt[x])] - PolyLog[3, E^((2*I)*Sqrt[x])]/2}
{Log[Sin[x]]*Csc[x]^2, x, 3, -x - Cot[x] - Cot[x]*Log[Sin[x]]}

{Log[Cosh[x]^2]*Sinh[x], x, 2, -2*Cosh[x] + Cosh[x]*Log[Cosh[x]^2]}

{Cos[x]*Log[x] + Sin[x]/x, x, 4, Log[x]*Sin[x]}


(* Integrands of the form x^m*Log[x]/(a+b*x+c*x^2) *)
{Log[x]/(a + b*x + c*x^2), x, 3, (Log[x]*Log[(b - Sqrt[b^2 - 4*a*c] + 2*c*x)/(b - Sqrt[b^2 - 4*a*c])])/Sqrt[b^2 - 4*a*c] - (Log[x]*Log[(b + Sqrt[b^2 - 4*a*c] + 2*c*x)/(b + Sqrt[b^2 - 4*a*c])])/Sqrt[b^2 - 4*a*c] + PolyLog[2, -((2*c*x)/(b - Sqrt[b^2 - 4*a*c]))]/Sqrt[b^2 - 4*a*c] - PolyLog[2, -((2*c*x)/(b + Sqrt[b^2 - 4*a*c]))]/Sqrt[b^2 - 4*a*c]}
{x*Log[x]/(a + b*x + c*x^2), x, 3, ((1 - b/Sqrt[b^2 - 4*a*c])*Log[x]*Log[(b - Sqrt[b^2 - 4*a*c] + 2*c*x)/(b - Sqrt[b^2 - 4*a*c])])/(2*c) + ((1 + b/Sqrt[b^2 - 4*a*c])*Log[x]*Log[(b + Sqrt[b^2 - 4*a*c] + 2*c*x)/(b + Sqrt[b^2 - 4*a*c])])/(2*c) + ((1 - b/Sqrt[b^2 - 4*a*c])*PolyLog[2, -((2*c*x)/(b - Sqrt[b^2 - 4*a*c]))])/(2*c) + ((1 + b/Sqrt[b^2 - 4*a*c])*PolyLog[2, -((2*c*x)/(b + Sqrt[b^2 - 4*a*c]))])/(2*c)}
{x^2*Log[x]/(a + b*x + c*x^2), x, 11, -(x/c) + (x*Log[x])/c + ((b - Sqrt[b^2 - 4*a*c])^2*Log[x]*Log[(b - Sqrt[b^2 - 4*a*c] + 2*c*x)/(b - Sqrt[b^2 - 4*a*c])])/(4*c^2*Sqrt[b^2 - 4*a*c]) - ((b + Sqrt[b^2 - 4*a*c])^2*Log[x]*Log[(b + Sqrt[b^2 - 4*a*c] + 2*c*x)/(b + Sqrt[b^2 - 4*a*c])])/(4*c^2*Sqrt[b^2 - 4*a*c]) + ((b - Sqrt[b^2 - 4*a*c])^2*PolyLog[2, -((2*c*x)/(b - Sqrt[b^2 - 4*a*c]))])/(4*c^2*Sqrt[b^2 - 4*a*c]) - ((b + Sqrt[b^2 - 4*a*c])^2*PolyLog[2, -((2*c*x)/(b + Sqrt[b^2 - 4*a*c]))])/(4*c^2*Sqrt[b^2 - 4*a*c])}

{Log[x]/(x*(a + b*x + c*x^2)), x, 11, (c*Log[x]^2)/(Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])) - (c*Log[x]^2)/(Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])) - (2*c*Log[x]*Log[(b - Sqrt[b^2 - 4*a*c] + 2*c*x)/(b - Sqrt[b^2 - 4*a*c])])/(Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])) + (2*c*Log[x]*Log[(b + Sqrt[b^2 - 4*a*c] + 2*c*x)/(b + Sqrt[b^2 - 4*a*c])])/(Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])) - (2*c*PolyLog[2, -((2*c*x)/(b - Sqrt[b^2 - 4*a*c]))])/(Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])) + (2*c*PolyLog[2, -((2*c*x)/(b + Sqrt[b^2 - 4*a*c]))])/(Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c]))}
{Log[x]/(x^2*(a + b*x + c*x^2)), x, 13, -((2*c)/(Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])*x)) + (2*c)/(Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])*x) - (2*c*Log[x])/(Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])*x) + (2*c*Log[x])/(Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])*x) - (2*c^2*Log[x]^2)/(Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])^2) + (2*c^2*Log[x]^2)/(Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])^2) + (4*c^2*Log[x]*Log[(b - Sqrt[b^2 - 4*a*c] + 2*c*x)/(b - Sqrt[b^2 - 4*a*c])])/(Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])^2) - (4*c^2*Log[x]*Log[(b + Sqrt[b^2 - 4*a*c] + 2*c*x)/(b + Sqrt[b^2 - 4*a*c])])/(Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])^2) + (4*c^2*PolyLog[2, -((2*c*x)/(b - Sqrt[b^2 - 4*a*c]))])/(Sqrt[b^2 - 4*a*c]*(b - Sqrt[b^2 - 4*a*c])^2) - (4*c^2*PolyLog[2, -((2*c*x)/(b + Sqrt[b^2 - 4*a*c]))])/(Sqrt[b^2 - 4*a*c]*(b + Sqrt[b^2 - 4*a*c])^2)}


(* Integrands of the form 1/(a*x+b*x*Log[c*x^n]^m) where m is an integer *)
{1/(a*x + b*x*Log[c*x^n]), x, 3, Log[a + b*Log[c*x^n]]/(b*n)}
{1/(a*x + b*x*Log[c*x^n]^2), x, 3, ArcTan[(Sqrt[b]*Log[c*x^n])/Sqrt[a]]/(Sqrt[a]*Sqrt[b]*n)}
{1/(a*x + b*x*Log[c*x^n]^3), x, 6, -(ArcTan[(a^(1/3) - 2*b^(1/3)*Log[c*x^n])/(Sqrt[3]*a^(1/3))]/(Sqrt[3]*a^(2/3)*b^(1/3)*n)) + Log[a^(1/3) + b^(1/3)*Log[c*x^n]]/(3*a^(2/3)*b^(1/3)*n) - Log[a^(2/3) - a^(1/3)*b^(1/3)*Log[c*x^n] + b^(2/3)*Log[c*x^n]^2]/(6*a^(2/3)*b^(1/3)*n)}
{1/(a*x + b*x*Log[c*x^n]^4), x, 5, -(ArcTan[(b^(1/4)*Log[c*x^n])/(-a)^(1/4)]/(2*(-a)^(3/4)*b^(1/4)*n)) - ArcTanh[(b^(1/4)*Log[c*x^n])/(-a)^(1/4)]/(2*(-a)^(3/4)*b^(1/4)*n)}

{1/(a*x + b*x/Log[c*x^n]), x, 5, Log[c*x^n]/(a*n) - (b*Log[b + a*Log[c*x^n]])/(a^2*n)}
{1/(a*x + b*x/Log[c*x^n]^2), x, 5, -((Sqrt[b]*ArcTan[(Sqrt[a]*Log[c*x^n])/Sqrt[b]])/(a^(3/2)*n)) + Log[c*x^n]/(a*n)}
{1/(a*x + b*x/Log[c*x^n]^3), x, 8, (b^(1/3)*ArcTan[(b^(1/3) - 2*a^(1/3)*Log[c*x^n])/(Sqrt[3]*b^(1/3))])/(Sqrt[3]*a^(4/3)*n) + Log[c*x^n]/(a*n) - (b^(1/3)*Log[b^(1/3) + a^(1/3)*Log[c*x^n]])/(3*a^(4/3)*n) + (b^(1/3)*Log[b^(2/3) - a^(1/3)*b^(1/3)*Log[c*x^n] + a^(2/3)*Log[c*x^n]^2])/(6*a^(4/3)*n)}
{1/(a*x + b*x/Log[c*x^n]^4), x, 7, -(((-b)^(1/4)*ArcTan[(a^(1/4)*Log[c*x^n])/(-b)^(1/4)])/(2*a^(5/4)*n)) - ((-b)^(1/4)*ArcTanh[(a^(1/4)*Log[c*x^n])/(-b)^(1/4)])/(2*a^(5/4)*n) + Log[c*x^n]/(a*n)}


(* Integrands of the form (a + b*Log[c*x])^n/x *)
{1/(x*(3 + Log[x])), x, 2, Log[3 + Log[x]]}
{Sqrt[1 + Log[x]]/x, x, 2, (2*(1 + Log[x])^(3/2))/3}
{(1 + Log[x])^5/x, x, 2, (1 + Log[x])^6/6}
{1/(x*Sqrt[Log[x]]), x, 2, 2*Sqrt[Log[x]]}

{1/(x*(1 + Log[x]^2)), x, 2, ArcTan[Log[x]]}
{1/(x*Sqrt[-3 + Log[x]^2]), x, 2, ArcTanh[Log[x]/Sqrt[-3 + Log[x]^2]]}
{1/(x*Sqrt[4 - 9*Log[x]^2]), x, 2, ArcSin[(3*Log[x])/2]/3}
{1/(x*Sqrt[4 + Log[x]^2]), x, 2, ArcSinh[Log[x]/2]}
{1/(x*(2 + 3*Log[6*x]^3)), x, 6, -(ArcTan[(2^(1/3)*3^(2/3) - 6*Log[6*x])/(3*2^(1/3)*3^(1/6))]/(2^(2/3)*3^(5/6))) + Log[2^(1/3)*3^(2/3) + 3*Log[6*x]]/(3*2^(2/3)*3^(1/3)) - Log[2^(2/3)*3^(1/3) - 2^(1/3)*3^(2/3)*Log[6*x] + 3*Log[6*x]^2]/(6*2^(2/3)*3^(1/3))}

{Log[Log[6*x]]/(x*Log[6*x]), x, 3, Log[Log[6*x]]^2/2}
{2^Log[x]/x, x, 2, 2^Log[x]/Log[2]}
{Sin[Log[x]]^2/x, x, 2, Log[x]/2 - (1/2)*Cos[Log[x]]*Sin[Log[x]]}
{(7 - Log[x])/(x*(3 + Log[x])), x, 4, -Log[x] + 10*Log[3 + Log[x]]}
{((2 - Log[x])*(3 + Log[x])^2)/x, x, 3, (11/12)*(3 + Log[x])^3 - (1/4)*Log[x]*(3 + Log[x])^3}
{(Log[x]^2*Sqrt[1 + Log[x]^2])/x, x, 4, (-(1/8))*ArcSinh[Log[x]] + (1/8)*Log[x]*Sqrt[1 + Log[x]^2] + (1/4)*Log[x]^3*Sqrt[1 + Log[x]^2]}
{(1 + Log[x])/(x*(3 + 2*Log[x])^2), x, 5, 1/(4*(3 + 2*Log[x])) + (1/4)*Log[3 + 2*Log[x]]}
{Log[x]/(x*Sqrt[1 + Log[x]]), x, 3, (-(4/3))*Sqrt[1 + Log[x]] + (2/3)*Log[x]*Sqrt[1 + Log[x]]}
{Log[x]/(x*Sqrt[-1 + 4*Log[x]]), x, 3, (1/12)*Sqrt[-1 + 4*Log[x]] + (1/6)*Log[x]*Sqrt[-1 + 4*Log[x]]}
{Sqrt[1 + Log[x]]/(x*Log[x]), x, 3, -2*ArcTanh[Sqrt[1 + Log[x]]] + 2*Sqrt[1 + Log[x]]}
{(1 - 4*Log[x] + Log[x]^2)/(x*(-1 + Log[x])^4), x, 6, -(2/(3*(1 - Log[x])^3)) + 1/(1 - Log[x])^2 + 1/(1 - Log[x])}

{Log[x]/(x + 4*x*Log[x]^2), x, 4, Log[1 + 4*Log[x]^2]/8}
{(x + x*Log[7*x] + x*Log[7*x]^2)^(-1), x, 3, (2*ArcTan[(1 + 2*Log[7*x])/Sqrt[3]])/Sqrt[3]}

{(-1 + Log[3*x])/(x*(1 - Log[3*x] + Log[3*x]^2)), x, 3, ArcTan[(1 - 2*Log[3*x])/Sqrt[3]]/Sqrt[3] + (1/2)*Log[1 - Log[3*x] + Log[3*x]^2]}
(* Need to cancel gcd to get simpler answer. *)
{(-1 + Log[3*x]^2)/(x + x*Log[3*x]^3), x, -10, ArcTan[(1 - 2*Log[3*x])/Sqrt[3]]/Sqrt[3] + (1/2)*Log[1 - Log[3*x] + Log[3*x]^2]}
{(-1 + Log[3*x]^2)/(x + x*Log[3*x] + x*Log[3*x]^2), x, 6, -(Sqrt[3]*ArcTan[(1 + 2*Log[3*x])/Sqrt[3]]) + Log[x] - Log[1 + Log[3*x] + Log[3*x]^2]/2}


(* Miscellaneous integrands involving logarithms *)
{Log[1/x]^2/x^5, x, 2, -(1/(32*x^4)) + Log[1/x]/(8*x^4) - Log[1/x]^2/(4*x^4)}

{(Log[a*x^n]^2)^p/x, x, 2, (Log[a*x^n]*(Log[a*x^n]^2)^p)/(n*(1 + 2*p))}
{(Log[a*x^n]^m)^p/x, x, 2, (Log[a*x^n]*(Log[a*x^n]^m)^p)/(n*(1 + m*p))}
{Sqrt[Log[a*x^n]^2]/x, x, 2, (Log[a*x^n]*Sqrt[Log[a*x^n]^2])/(2*n)}
{(b*Log[a*x^n]^m)^p/x, x, 2, (Log[a*x^n]*(b*Log[a*x^n]^m)^p)/(n*(1 + m*p))}

{1/Sqrt[-Log[a*x^2]], x, 1, -((Sqrt[Pi/2]*x*Erf[Sqrt[-Log[a*x^2]]/Sqrt[2]])/Sqrt[a*x^2])}
{1/Sqrt[-Log[a/x^2]], x, 1, Sqrt[Pi/2]*Sqrt[a/x^2]*x*Erfi[Sqrt[-Log[a/x^2]]/Sqrt[2]]}
{1/Sqrt[-Log[a*x^n]], x, 1, -((Sqrt[Pi]*x*Erf[Sqrt[-Log[a*x^n]]/Sqrt[n]])/(Sqrt[n]*(a*x^n)^n^(-1)))}

{Log[1 + Sqrt[x] - x]/x, x, 10, -2*Log[(-(1/4))*(1 + Sqrt[5])*(1 - Sqrt[5] - 2*Sqrt[x])]*Log[Sqrt[x]] - 2*Log[(-(1/4))*(1 - Sqrt[5])*(1 + Sqrt[5] - 2*Sqrt[x])]*Log[Sqrt[x]] + 2*Log[1 + Sqrt[x] - x]*Log[Sqrt[x]] - 2*PolyLog[2, (-(1/2))*(1 - Sqrt[5])*Sqrt[x]] - 2*PolyLog[2, (-(1/2))*(1 + Sqrt[5])*Sqrt[x]]}

{(x*Log[c + d*x])/(a + b*x), x, 4, -(x/b) + ((c + d*x)*Log[c + d*x])/(b*d) - (a*Log[-((d*(a + b*x))/(b*c - a*d))]*Log[c + d*x])/b^2 - (a*PolyLog[2, (b*(c + d*x))/(b*c - a*d)])/b^2}
{Log[x]/(-1 + x), x, 1, -PolyLog[2, 1 - x]}
{(x*Log[1 - a - b*x])/(a + b*x), x, 4, -(x/b) - ((1 - a - b*x)*Log[1 - a - b*x])/b^2 + (a*PolyLog[2, a + b*x])/b^2}
{((b + 2*c*x)*Log[x])/(x*(b + c*x)), x, 5, Log[x]^2/2 + Log[x]*Log[(b + c*x)/b] + PolyLog[2, -((c*x)/b)]}

{Sin[x*Log[x]] + Log[x]*Sin[x*Log[x]], x, 2, -Cos[x*Log[x]]}
{Log[(1 - x^2)/(1 + x^2)]/(1 + x)^2, x, 10, -(1/(1 + x)) - ArcTan[x] + (1/2)*Log[1 - x] + (1/2)*Log[1 + x] - Log[(1 - x^2)/(1 + x^2)]/(1 + x) - (1/2)*Log[1 + x^2]}
{Log[(1 - (-1 + x)^2)/(1 + (-1 + x)^2)]/x^2, x, 8, -(1/x) + ArcTan[1 - x] + (1/2)*Log[2 - x] + Log[x]/2 - Log[((2 - x)*x)/(1 + (1 - x)^2)]/x - (1/2)*Log[2 - 2*x + x^2]}
{Log[a + b*x]^2/x, x, 4, Log[-((b*x)/a)]*Log[a + b*x]^2 + 2*Log[a + b*x]*PolyLog[2, 1 + (b*x)/a] - 2*PolyLog[3, (a + b*x)/a]}
{Log[Sqrt[x] + x], x, 6, Sqrt[x] - x - Log[1 + Sqrt[x]] + x*Log[Sqrt[x] + x]}
{Log[-(x/(1 + x))], x, 2, x*Log[-(x/(1 + x))] - Log[1 + x]}
{Log[(-1 + x)/(1 + x)], x, 4, x*Log[-((1 - x)/(1 + x))] - Log[1 - x^2]}

{Log[x^2/(1 + x^2)]/(1 + x^2), x, 18, (1/2)*I*Log[1/(1 + 1/x^2)]*Log[1 - I*x] + (1/2)*I*Log[(-(1/2))*I*(I - x)]*Log[1 - I*x] + (1/4)*I*Log[1 - I*x]^2 - (1/2)*I*Log[1/(1 + 1/x^2)]*Log[1 + I*x] - (1/4)*I*Log[1 + I*x]^2 - (1/2)*I*Log[1 + I*x]*Log[(-(1/2))*I*(I + x)] + (1/2)*I*PolyLog[2, (1/2)*(1 - I*x)] - (1/2)*I*PolyLog[2, (1/2)*(1 + I*x)] - I*PolyLog[2, (-I)*x] + I*PolyLog[2, I*x]}
