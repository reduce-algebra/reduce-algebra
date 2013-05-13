(* ::Package:: *)

(* ::Section:: *)
(*Joel Moses - Thesis Integration Problems*)


(* ::Subsection::Closed:: *)
(*Chapter 2 - How SIN differs from SAINT*)


{Cot[x]^4, x, 3, x + Cot[x] - Cot[x]^3/3}
{1/(x^4*(1 + x^2)), x, 3, -(1/(3*x^3)) + 1/x + ArcTan[x]}
{(x^2 + x)/Sqrt[x], x, 3, (2*x^(3/2))/3 + (2*x^(5/2))/5}
{Cos[x], x, 1, Sin[x]}
{x*E^x^2, x, 1, E^x^2/2}
{Tan[x]*Sec[x]^2, x, 1, Sec[x]^2/2}
{x*Sqrt[1 + x^2], x, 1, (1/3)*(1 + x^2)^(3/2)}
{Sin[x]*E^x, x, 1, (-(1/2))*E^x*Cos[x] + (1/2)*E^x*Sin[x]}


(* ::Subsection::Closed:: *)
(*Chapter 3 - SCHATCHEN - A Matching Program for Algebraic Expressions*)


{Csc[x]^2*(Cos[x]/Sin[x]^2), x, 1, (-(1/3))*Csc[x]^3}


(* ::Subsection::Closed:: *)
(*Chapter 4 - The First Stage of Sin*)


{Sin[E^x], x, 2, SinIntegral[E^x]}
{Sin[y]/y, y, 1, SinIntegral[y]}


{Sin[x] + E^x, x, 3, E^x - Cos[x]}
{E^x^2 + 2*x^2*E^x^2, x, 4, E^x^2*x}
{(x + E^x)^2, x, 5, -2*E^x + E^(2*x)/2 + 2*E^x*x + x^3/3}
{x^2 + 2*E^x + E^(2*x), x, 3, 2*E^x + E^(2*x)/2 + x^3/3}


{Sin[x]*Cos[x], x, 1, Sin[x]^2/2}
{x*E^x^2, x, 1, E^x^2/2}
{x*Sqrt[1 + x^2], x, 1, (1/3)*(1 + x^2)^(3/2)}
{E^x/(1 + E^x), x, 1, Log[1 + E^x]}
{x^(3/2), x, 1, (2*x^(5/2))/5}
{Cos[2*x + 3], x, 1, (1/2)*Sin[3 + 2*x]}
{2*y*z*E^(2*x), x, 2, E^(2*x)*y*z}
{Cos[E^x]^2*Sin[E^x]*E^x, x, 1, (-(1/3))*Cos[E^x]^3}


(* ::Subsection::Closed:: *)
(*Chapter 4 - The Second Stage of Sin*)


{x*Sqrt[x + 1], x, 2, (-(2/3))*(1 + x)^(3/2) + (2/5)*(1 + x)^(5/2)}
{1/(x^4 - 1), x, 3, -(ArcTan[x]/2) - ArcTanh[x]/2}


(* ::Subsubsection::Closed:: *)
(*Method 1)  Elementary function of exponentials*)


{E^x/(2 + 3*E^(2*x)), x, 2, ArcTan[Sqrt[3/2]*E^x]/Sqrt[6]}
{E^(2*x)/(A + B*E^(4*x)), x, 2, ArcTan[(Sqrt[B]*E^(2*x))/Sqrt[A]]/(2*Sqrt[A]*Sqrt[B])}
{E^(x + 1)/(1 + E^x), x, 1, E*Log[1 + E^x]}
{10^x*E^x, x, 1, (10*E)^x/(1 + Log[10])}


(* ::Subsubsection::Closed:: *)
(*Method 2)  Substitution for an integral power*)


{x^3*Sin[x^2], x, 2, (-(1/2))*x^2*Cos[x^2] + Sin[x^2]/2}
{x^7/(x^12 + 1), x, 6, -(ArcTan[(1 - 2*x^4)/Sqrt[3]]/(4*Sqrt[3])) - (1/12)*Log[1 + x^4] + (1/24)*Log[1 - x^4 + x^8]}
{x^(3*a)*Sin[x^(2*a)], x, 3, (I*x^(1 + 3*a)*Gamma[(1/2)*(3 + 1/a), (-I)*x^(2*a)])/(((-I)*x^(2*a))^((1 + 3*a)/(2*a))*(4*a)) - (I*x^(1 + 3*a)*Gamma[(1/2)*(3 + 1/a), I*x^(2*a)])/((I*x^(2*a))^((1 + 3*a)/(2*a))*(4*a))}


(* ::Subsubsection::Closed:: *)
(*Method 3)  Substitution for a rational root of a linear function of x*)


{Cos[Sqrt[x]], x, 3, 2*Cos[Sqrt[x]] + 2*Sqrt[x]*Sin[Sqrt[x]]}
{x*Sqrt[x + 1], x, 2, (-(2/3))*(1 + x)^(3/2) + (2/5)*(1 + x)^(5/2)}
{1/(x^(1/2) + x^(1/3)), x, 5, 6*x^(1/6) - 3*x^(1/3) + 2*Sqrt[x] - 6*Log[1 + x^(1/6)]}
{Sqrt[(x + 1)/(2*x + 3)], x, 3, (1/2)*Sqrt[(1 + x)/(3 + 2*x)]*(3 + 2*x) - ArcTanh[Sqrt[2]*Sqrt[(1 + x)/(3 + 2*x)]]/(2*Sqrt[2]), Sqrt[(1 + x)/(3 + 2*x)]/(2*(1 - (2*(1 + x))/(3 + 2*x))) - ArcTanh[Sqrt[2]*Sqrt[(1 + x)/(3 + 2*x)]]/(2*Sqrt[2])}


(* ::Subsubsection::Closed:: *)
(*Method 4)  Binomial - Chebyschev*)


{x^4/(1 - x^2)^(5/2), x, 3, x^3/(3*(1 - x^2)^(3/2)) - x/Sqrt[1 - x^2] + ArcSin[x]}
{x^(1/2)*(1 + x)^(5/2), x, 5, (5/64)*Sqrt[x]*Sqrt[1 + x] + (5/32)*x^(3/2)*Sqrt[1 + x] + (5/24)*x^(3/2)*(1 + x)^(3/2) + (1/4)*x^(3/2)*(1 + x)^(5/2) - (5*ArcSinh[Sqrt[x]])/64}


(* ::Subsubsection::Closed:: *)
(*Method 5)  Arctrigonometric substitutions*)


{x^4/(1 - x^2)^(5/2), x, 3, x^3/(3*(1 - x^2)^(3/2)) - x/Sqrt[1 - x^2] + ArcSin[x]}
{Sqrt[A^2 + B^2 - B^2*y^2]/(1 - y^2), y, 3, B*ArcTan[(B*y)/Sqrt[A^2 + B^2 - B^2*y^2]] + A*ArcTanh[(A*y)/Sqrt[A^2 + B^2 - B^2*y^2]]}


(* ::Subsubsection::Closed:: *)
(*Method 6)  Elementary function of trigonometric functions*)


{Sin[x]^2, x, 1, x/2 - (1/2)*Cos[x]*Sin[x]}
{Sqrt[A^2 + B^2*Sin[x]^2]/Sin[x], x, 4, (-B)*ArcTan[(B*Cos[x])/Sqrt[A^2 + B^2*Sin[x]^2]] - A*ArcTanh[(A*Cos[x])/Sqrt[A^2 + B^2*Sin[x]^2]], (-B)*ArcTan[(B*Cos[x])/Sqrt[A^2 + B^2 - B^2*Cos[x]^2]] - A*ArcTanh[(A*Cos[x])/Sqrt[A^2 + B^2 - B^2*Cos[x]^2]]}
{1/(1 + Cos[x]), x, 1, Sin[x]/(1 + Cos[x])}


(* ::Subsubsection::Closed:: *)
(*Method 7)  Rational function times an exponential*)


{x*E^x, x, 2, -E^x + E^x*x}
{(x/(x + 1)^2)*E^x, x, 5, E^x/(1 + x)}
{(1 + 2*x^2)*E^x^2, x, 5, E^x^2*x}
{E^x^2, x, 1, (1/2)*Sqrt[Pi]*Erfi[x]}
{E^x/x, x, 1, ExpIntegralEi[x]}


(* ::Subsubsection::Closed:: *)
(*Method 8)  Rational functions*)


{x/(x^3 + 1), x, 5, -(ArcTan[(1 - 2*x)/Sqrt[3]]/Sqrt[3]) - (1/3)*Log[1 + x] + (1/6)*Log[1 - x + x^2]}
{1/(x^6 - 1), x, 7, -(ArcTan[(Sqrt[3]*x)/(1 - x^2)]/(2*Sqrt[3])) - ArcTanh[x]/3 - (1/6)*ArcTanh[x/(1 + x^2)], ArcTan[(1 - 2*x)/Sqrt[3]]/(2*Sqrt[3]) - ArcTan[(1 + 2*x)/Sqrt[3]]/(2*Sqrt[3]) - ArcTanh[x]/3 - (1/6)*ArcTanh[x/(1 + x^2)]}
{1/((B^2 - A^2)*x^2 - A^2*B^2 + A^4), x, 1, ArcTanh[x/A]/(A*(A^2 - B^2))}


(* ::Subsubsection::Closed:: *)
(*Method 9)  Rational function times a log or arctrigonometric function*)


{x*Log[x], x, 2, -(x^2/4) + (1/2)*x^2*Log[x]}
{x^2*ArcSin[x], x, 3, (2*Sqrt[1 - x^2])/9 + (1/9)*x^2*Sqrt[1 - x^2] + (1/3)*x^3*ArcSin[x]}
{1/(x^2 + 2*x + 1), x, 2, -(1/(1 + x))}


(* ::Subsubsection::Closed:: *)
(*Method 10)  Rational function times an elementary function of log(a+b x)*)


{Log[x]/(Log[x] + 1)^2, x, 5, x/(1 + Log[x])}
{1/(x*(1 + Log[x]^2)), x, 2, ArcTan[Log[x]]}
{1/Log[x], x, 1, LogIntegral[x]}


(* ::Subsubsection::Closed:: *)
(*Method 11)  Expansion of the integrand*)


{x*(Cos[x] + Sin[x]), x, 6, Cos[x] - x*Cos[x] + Sin[x] + x*Sin[x]}
{(x + E^x)/E^x, x, 4, -E^(-x) + x - x/E^x}
{x*(1 + E^x)^2, x, 6, -2*E^x - E^(2*x)/4 + 2*E^x*x + (1/2)*E^(2*x)*x + x^2/2}


(* ::Subsection::Closed:: *)
(*Chapter 4 - The Third Stage of Sin*)


{x*Cos[x], x, 2, Cos[x] + x*Sin[x]}
{Cos[Sqrt[x]], x, 3, 2*Cos[Sqrt[x]] + 2*Sqrt[x]*Sin[Sqrt[x]]}


(* ::Subsubsection::Closed:: *)
(*The Integration-by-Parts Methods*)


{x*Cos[x], x, 2, Cos[x] + x*Sin[x]}
{x*Log[x]^2, x, 3, x^2/4 - (1/2)*x^2*Log[x] + (1/2)*x^2*Log[x]^2}


(* ::Subsubsection::Closed:: *)
(*The Derivative-divides Method*)


{Cos[x]*(1 + Sin[x]^3), x, 2, Sin[x] + Sin[x]^4/4}
{1/(x*(1 + Log[x]^2)), x, 2, ArcTan[Log[x]]}
{1/(Sqrt[1 - x^2]*(1 + ArcSin[x]^2)), x, 2, ArcTan[ArcSin[x]]}
{Sin[x]/(Sin[x] + Cos[x]), x, 2, x/2 - (1/2)*Log[Cos[x] + Sin[x]]}


(* ::Subsubsection::Closed:: *)
(*An Example of SIN's Performance*)


{-Sqrt[A^2 + B^2*(1 - y^2)]/(1 - y^2), y, 4, (-B)*ArcTan[(B*y)/Sqrt[A^2 + B^2 - B^2*y^2]] - A*ArcTanh[(A*y)/Sqrt[A^2 + B^2 - B^2*y^2]]}
{(-(A^2 + B^2))*(Cos[z]^2/(B*(1 - ((A^2 + B^2)/B^2)*Sin[z]^2))), z, 5, (-B)*z - A*ArcTanh[(B*Cot[z])/A]}
{-(A^2 + B^2)/(B*(1 + w^2)^2*(1 - ((A^2 + B^2)/B^2)*(w^2/(1 + w^2)))), w, 6, (-B)*ArcTan[w] - A*ArcTanh[(A*w)/B]}
{(-B)*((A^2 + B^2)/((1 + w^2)*(B^2 - A^2*w^2))), w, 4, (-B)*ArcTan[w] - A*ArcTanh[(A*w)/B]}


(* ::Subsubsection::Closed:: *)
(*SAINT and SIN solutions of the same problem*)


{x^4/(1 - x^2)^(5/2), x, 3, x^3/(3*(1 - x^2)^(3/2)) - x/Sqrt[1 - x^2] + ArcSin[x]}
{Sin[y]^4/Cos[y]^4, y, 3, y - Tan[y] + Tan[y]^3/3}
{z^4/(1 + z^2), z, 3, -z + z^3/3 + ArcTan[z]}


(* ::Subsection::Closed:: *)
(*Chapter 5 - The Edge Heuristic*)


{(2*x^2 + 1)*E^x^2, x, 5, E^x^2*x}
{((2*x^6 + 5*x^4 + x^3 + 4*x^2 + 1)/(x^2 + 1)^2)*E^x^2, x, 12, E^x^2*x + E^x^2/(2*(1 + x^2))}
{1/E^1/E^x, x, 1, -E^(-1 - x)}
{(x + 1/x)*Log[x], x, 7, -(x^2/4) + (1/2)*x^2*Log[x] + Log[x]^2/2}
{x/(1 + x^4), x, 2, ArcTan[x^2]/2}
{x^5/(1 + x^4), x, 3, x^2/2 - ArcTan[x^2]/2}
{1/(1 + Tan[x]^2), x, 2, x/2 + (1/2)*Cos[x]*Sin[x]}
{x^4/(1 - x^2)^(5/2), x, 3, x^3/(3*(1 - x^2)^(3/2)) - x/Sqrt[1 - x^2] + ArcSin[x]}
{-x^2/(1 - x^2)^(3/2), x, 2, -(x/Sqrt[1 - x^2]) + ArcSin[x]}
{Sin[x]*E^x, x, 1, (-(1/2))*E^x*Cos[x] + (1/2)*E^x*Sin[x]}


(* ::Subsection::Closed:: *)
(*Appendix C - Slagle's Thesis Integration Problems*)


{1/x, x, 1, Log[x]}
{Sec[2*t]/(1 + Sec[t]^2 + 3*Tan[t]), t, 8, (-(1/12))*Log[Cos[t] - Sin[t]] - (1/4)*Log[Cos[t] + Sin[t]] + (1/3)*Log[2*Cos[t] + Sin[t]] - 1/(2*(1 + Tan[t]))}
{1/Sec[x]^2, x, 1, x/2 + (1/2)*Cos[x]*Sin[x]}
{(x^2 + 1)/Sqrt[x], x, 2, 2*Sqrt[x] + (2*x^(5/2))/5}
{x/Sqrt[x^2 + 2*x + 5], x, 2, Sqrt[5 + 2*x + x^2] - ArcSinh[(1 + x)/2]}
{Sin[x]^2*Cos[x], x, 1, Sin[x]^3/3}
{E^x/(1 + E^x), x, 1, Log[1 + E^x]}
{E^(2*x)/(1 + E^x), x, 3, E^x - Log[1 + E^x]}
{1/(1 - Cos[x]), x, 1, -(Sin[x]/(1 - Cos[x]))}
{Tan[x]*Sec[x]^2, x, 1, Sec[x]^2/2}
{x*Log[x], x, 2, -(x^2/4) + (1/2)*x^2*Log[x]}
{Sin[x]*Cos[x], x, 1, Sin[x]^2/2}
{(x + 1)/Sqrt[2*x - x^2], x, 2, -Sqrt[2*x - x^2] - 2*ArcSin[1 - x]}
{2*(E^x/(2 + 3*E^(2*x))), x, 3, Sqrt[2/3]*ArcTan[Sqrt[3/2]*E^x]}
{x^4/(1 - x^2)^(5/2), x, 3, x^3/(3*(1 - x^2)^(3/2)) - x/Sqrt[1 - x^2] + ArcSin[x]}
{E^(6*x)/(E^(4*x) + 1), x, 3, E^(2*x)/2 - (1/2)*ArcTan[E^(2*x)]}
{Log[2 + 3*x^2], x, 3, -2*x + 2*Sqrt[2/3]*ArcTan[Sqrt[3/2]*x] + x*Log[2 + 3*x^2]}


(* ::Subsection::Closed:: *)
(*Appendix D - MacIntosh Integration Problems*)


{1/(r*Sqrt[2*H*r^2 - a^2]), x, 1, x/(r*Sqrt[-a^2 + 2*H*r^2])}
{1/(r*Sqrt[2*H*r^2 - a^2 - e^2]), x, 1, x/(r*Sqrt[-a^2 - e^2 + 2*H*r^2])}
{1/(r*Sqrt[2*H*r^2 - a^2 - 2*K*r^4]), x, 1, x/(r*Sqrt[-a^2 + 2*H*r^2 - 2*K*r^4])}
{1/(r*Sqrt[2*H*r^2 - a^2 - e^2 - 2*K*r^4]), x, 1, x/(r*Sqrt[-a^2 - e^2 + 2*H*r^2 - 2*K*r^4])}
{1/(r*Sqrt[2*H*r^2 - a^2 - 2*K*r]), x, 1, x/(r*Sqrt[-a^2 - 2*r*(K - H*r)])}
{1/(r*Sqrt[2*H*r^2 - a^2 - e^2 - 2*K*r]), x, 1, x/(r*Sqrt[-a^2 - e^2 - 2*r*(K - H*r)])}
{r/Sqrt[2*E*r^2 - a^2], x, 1, (r*x)/Sqrt[-a^2 + 2*E*r^2]}
{r/Sqrt[2*E*r^2 - a^2 - e^2], x, 1, (r*x)/Sqrt[-a^2 - e^2 + 2*E*r^2]}
{r/Sqrt[2*E*r^2 - a^2 - 2*K*r^4], x, 1, (r*x)/Sqrt[-a^2 + 2*E*r^2 - 2*K*r^4]}
{r/Sqrt[2*E*r^2 - a^2 - e^2 - 2*K*r^4], x, 1, (r*x)/Sqrt[-a^2 - e^2 + 2*E*r^2 - 2*K*r^4]}
{r/Sqrt[2*H*r^2 - a^2 - e^2 - 2*K*r], x, 1, (r*x)/Sqrt[-a^2 - e^2 - 2*r*(K - H*r)]}


(* ::Section:: *)
(*Vladimir Bondarenko, Simferopol, Ukraine - VM Machine Integration Problems*)


(* ::Subsection::Closed:: *)
(*9 June 2010*)


{1/(Sqrt[2] + Sin[z] + Cos[z]), x, 1, x/(Sqrt[2] + Cos[z] + Sin[z])}


{1/(Sqrt[1 + x] + Sqrt[1 - x])^2, x, 4, -(1/(2*x)) + Sqrt[1 - x^2]/(2*x) + ArcSin[x]/2}


{1/(1 + Cos[x])^2, x, 2, Sin[x]/(3*(1 + Cos[x])^2) + Sin[x]/(3*(1 + Cos[x]))}
{Sin[x]/Sqrt[1 + x], x, 5, Sqrt[2*Pi]*Cos[1]*FresnelS[Sqrt[2/Pi]*Sqrt[1 + x]] - Sqrt[2*Pi]*FresnelC[Sqrt[2/Pi]*Sqrt[1 + x]]*Sin[1]}
{1/(Cos[x] + Sin[x])^6, x, 3, -((Cos[x] - Sin[x])/(10*(Cos[x] + Sin[x])^5)) - (Cos[x] - Sin[x])/(15*(Cos[x] + Sin[x])^3) + (2*Sin[x])/(15*(Cos[x] + Sin[x]))}


{Log[x^4 + 1/x^4], x, 14, -4*x - Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*ArcTan[(Sqrt[2 - Sqrt[2]] - 2*x)/Sqrt[2 + Sqrt[2]]] + (1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*ArcTan[(Sqrt[2 + Sqrt[2]] - 2*x)/Sqrt[2 - Sqrt[2]]] + Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*ArcTan[(Sqrt[2 - Sqrt[2]] + 2*x)/Sqrt[2 + Sqrt[2]]] - (1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*ArcTan[(Sqrt[2 + Sqrt[2]] + 2*x)/Sqrt[2 - Sqrt[2]]] - (1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*ArcTanh[(Sqrt[2 - Sqrt[2]]*x)/(1 + x^2)] + Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*ArcTanh[(Sqrt[2 + Sqrt[2]]*x)/(1 + x^2)] + x*Log[1/x^4 + x^4]}
{Log[1 + x]/(x*Sqrt[1 + Sqrt[1 + x]]), x, 18, -8*ArcTanh[Sqrt[1 + Sqrt[1 + x]]] - (2*Log[1 + x])/Sqrt[1 + Sqrt[1 + x]] + (Log[1 + x]*Log[Sqrt[2] - Sqrt[1 + Sqrt[1 + x]]])/Sqrt[2] - Sqrt[2]*Log[(-(1 + Sqrt[2]))*(1 - Sqrt[1 + Sqrt[1 + x]])]*Log[Sqrt[2] - Sqrt[1 + Sqrt[1 + x]]] - Sqrt[2]*Log[Sqrt[2] - Sqrt[1 + Sqrt[1 + x]]]*Log[(-(1 - Sqrt[2]))*(1 + Sqrt[1 + Sqrt[1 + x]])] - (Log[1 + x]*Log[Sqrt[2] + Sqrt[1 + Sqrt[1 + x]]])/Sqrt[2] + Sqrt[2]*Log[(-(1 - Sqrt[2]))*(1 - Sqrt[1 + Sqrt[1 + x]])]*Log[Sqrt[2] + Sqrt[1 + Sqrt[1 + x]]] + Sqrt[2]*Log[(-(1 + Sqrt[2]))*(1 + Sqrt[1 + Sqrt[1 + x]])]*Log[Sqrt[2] + Sqrt[1 + Sqrt[1 + x]]] - Sqrt[2]*PolyLog[2, (-(1 - Sqrt[2]))*(Sqrt[2] - Sqrt[1 + Sqrt[1 + x]])] - Sqrt[2]*PolyLog[2, (1 + Sqrt[2])*(Sqrt[2] - Sqrt[1 + Sqrt[1 + x]])] + Sqrt[2]*PolyLog[2, (-(1 - Sqrt[2]))*(Sqrt[2] + Sqrt[1 + Sqrt[1 + x]])] + Sqrt[2]*PolyLog[2, (1 + Sqrt[2])*(Sqrt[2] + Sqrt[1 + Sqrt[1 + x]])]}
{Log[1 + x]/x*Sqrt[1 + Sqrt[1 + x]], x, 24, -16*Sqrt[1 + Sqrt[1 + x]] + 16*ArcTanh[Sqrt[1 + Sqrt[1 + x]]] + 4*Sqrt[1 + Sqrt[1 + x]]*Log[1 + x] + Sqrt[2]*Log[1 + x]*Log[Sqrt[2] - Sqrt[1 + Sqrt[1 + x]]] - 2*Sqrt[2]*Log[(-(1 + Sqrt[2]))*(1 - Sqrt[1 + Sqrt[1 + x]])]*Log[Sqrt[2] - Sqrt[1 + Sqrt[1 + x]]] - 2*Sqrt[2]*Log[Sqrt[2] - Sqrt[1 + Sqrt[1 + x]]]*Log[(-(1 - Sqrt[2]))*(1 + Sqrt[1 + Sqrt[1 + x]])] - Sqrt[2]*Log[1 + x]*Log[Sqrt[2] + Sqrt[1 + Sqrt[1 + x]]] + 2*Sqrt[2]*Log[(-(1 - Sqrt[2]))*(1 - Sqrt[1 + Sqrt[1 + x]])]*Log[Sqrt[2] + Sqrt[1 + Sqrt[1 + x]]] + 2*Sqrt[2]*Log[(-(1 + Sqrt[2]))*(1 + Sqrt[1 + Sqrt[1 + x]])]*Log[Sqrt[2] + Sqrt[1 + Sqrt[1 + x]]] - 2*Sqrt[2]*PolyLog[2, (-(1 - Sqrt[2]))*(Sqrt[2] - Sqrt[1 + Sqrt[1 + x]])] - 2*Sqrt[2]*PolyLog[2, (1 + Sqrt[2])*(Sqrt[2] - Sqrt[1 + Sqrt[1 + x]])] + 2*Sqrt[2]*PolyLog[2, (-(1 - Sqrt[2]))*(Sqrt[2] + Sqrt[1 + Sqrt[1 + x]])] + 2*Sqrt[2]*PolyLog[2, (1 + Sqrt[2])*(Sqrt[2] + Sqrt[1 + Sqrt[1 + x]])]}


(* ::Subsection::Closed:: *)
(*4 July 2010*)


{1/(1 + Sqrt[x + Sqrt[1 + x^2]]), x, 7, -(1/(2*(x + Sqrt[1 + x^2]))) + 1/Sqrt[x + Sqrt[1 + x^2]] + Sqrt[x + Sqrt[1 + x^2]] + Log[Sqrt[x + Sqrt[1 + x^2]]] - 2*Log[1 + Sqrt[x + Sqrt[1 + x^2]]]}
{Sqrt[1 + x]/(x + Sqrt[1 + Sqrt[1 + x]]), x, 6, 2 + 2*Sqrt[1 + x] + (8*ArcTanh[(1 + 2*Sqrt[1 + Sqrt[1 + x]])/Sqrt[5]])/Sqrt[5]}
{1/(x - Sqrt[1 + Sqrt[1 + x]]), x, 5, (2/5)*(5 + Sqrt[5])*Log[1 - Sqrt[5] - 2*Sqrt[1 + Sqrt[1 + x]]] - (2*(1 - Sqrt[5])*Log[1 + Sqrt[5] - 2*Sqrt[1 + Sqrt[1 + x]]])/Sqrt[5]}
{x/(x + Sqrt[1 - Sqrt[1 + x]]), x, 5, -2 + 2*Sqrt[1 + x] - 4*Sqrt[1 - Sqrt[1 + x]] + (1 - Sqrt[1 + x])^2 + (8*ArcTanh[(1 + 2*Sqrt[1 - Sqrt[1 + x]])/Sqrt[5]])/Sqrt[5]}
{Sqrt[Sqrt[1 + x] + x]/((1 + x^2)*Sqrt[1 + x]), x, 16, (1/8 - I/8)*Sqrt[(4 + 4*I) - 4*(1 - I)^(3/2)]*ArcTan[((2 - 2*I) - 4*Sqrt[1 - I] - ((-4 + 4*I) - 2*Sqrt[1 - I])*Sqrt[1 + x])/(2*Sqrt[(4 + 4*I) - 4*(1 - I)^(3/2)]*Sqrt[x + Sqrt[1 + x]])] + (1/8 - I/8)*Sqrt[(4 + 4*I) + 4*(1 - I)^(3/2)]*ArcTan[((2 - 2*I) + 4*Sqrt[1 - I] - ((-4 + 4*I) + 2*Sqrt[1 - I])*Sqrt[1 + x])/(2*Sqrt[(4 + 4*I) + 4*(1 - I)^(3/2)]*Sqrt[x + Sqrt[1 + x]])] + (1/8 + I/8)*Sqrt[(4 - 4*I) - 4*(1 + I)^(3/2)]*ArcTan[((2 + 2*I) - 4*Sqrt[1 + I] - ((-4 - 4*I) - 2*Sqrt[1 + I])*Sqrt[1 + x])/(2*Sqrt[(4 - 4*I) - 4*(1 + I)^(3/2)]*Sqrt[x + Sqrt[1 + x]])] + (1/8 + I/8)*Sqrt[(4 - 4*I) + 4*(1 + I)^(3/2)]*ArcTan[((2 + 2*I) + 4*Sqrt[1 + I] - ((-4 - 4*I) + 2*Sqrt[1 + I])*Sqrt[1 + x])/(2*Sqrt[(4 - 4*I) + 4*(1 + I)^(3/2)]*Sqrt[x + Sqrt[1 + x]])]}
{Sqrt[x + Sqrt[1 + x]]/(1 + x^2), x, 15, (1/2)*I*Sqrt[I + Sqrt[1 - I]]*ArcTan[(2 + Sqrt[1 - I] - (1 - 2*Sqrt[1 - I])*Sqrt[1 + x])/(2*Sqrt[I + Sqrt[1 - I]]*Sqrt[x + Sqrt[1 + x]])] - (1/2)*I*Sqrt[-I + Sqrt[1 + I]]*ArcTan[(2 + Sqrt[1 + I] - (1 - 2*Sqrt[1 + I])*Sqrt[1 + x])/(2*Sqrt[-I + Sqrt[1 + I]]*Sqrt[x + Sqrt[1 + x]])] + (1/2)*I*Sqrt[-I + Sqrt[1 - I]]*ArcTanh[(2 - Sqrt[1 - I] - (1 + 2*Sqrt[1 - I])*Sqrt[1 + x])/(2*Sqrt[-I + Sqrt[1 - I]]*Sqrt[x + Sqrt[1 + x]])] - (1/2)*I*Sqrt[I + Sqrt[1 + I]]*ArcTanh[(2 - Sqrt[1 + I] - (1 + 2*Sqrt[1 + I])*Sqrt[1 + x])/(2*Sqrt[I + Sqrt[1 + I]]*Sqrt[x + Sqrt[1 + x]])]}
(* {Sqrt[1 + Sqrt[x] + Sqrt[1 + 2*Sqrt[x] + 2*x]], x, 0, 0} *)
(* {Sqrt[Sqrt[2] + Sqrt[x] + Sqrt[2 + Sqrt[8]*Sqrt[x] + 2*x]], x, 0, 0} *)
{Sqrt[1/x + Sqrt[1 + 1/x]], x, 12, 3/(2*(2 + 2*(Sqrt[1 + 1/x] + Sqrt[Sqrt[1 + 1/x] + 1/x]) + (Sqrt[1 + 1/x] + Sqrt[Sqrt[1 + 1/x] + 1/x])^2)) - 5/(4*(2 - Sqrt[1 + 1/x] - Sqrt[Sqrt[1 + 1/x] + 1/x])) + 1/(4*(Sqrt[1 + 1/x] + Sqrt[Sqrt[1 + 1/x] + 1/x])) + (Sqrt[1 + 1/x] + Sqrt[Sqrt[1 + 1/x] + 1/x])/(2*(2 + 2*(Sqrt[1 + 1/x] + Sqrt[Sqrt[1 + 1/x] + 1/x]) + (Sqrt[1 + 1/x] + Sqrt[Sqrt[1 + 1/x] + 1/x])^2)) - (1/2)*ArcTan[1 + Sqrt[1 + 1/x] + Sqrt[Sqrt[1 + 1/x] + 1/x]] - (3/2)*ArcTanh[1 - Sqrt[1 + 1/x] - Sqrt[Sqrt[1 + 1/x] + 1/x]]}
{Sqrt[x + Sqrt[1 + x]]/x^2, x, 12, 5/(4*(2 - Sqrt[1 + x] - Sqrt[x + Sqrt[1 + x]])) - 1/(4*(Sqrt[1 + x] + Sqrt[x + Sqrt[1 + x]])) - 3/(2*(2 + 2*(Sqrt[1 + x] + Sqrt[x + Sqrt[1 + x]]) + (Sqrt[1 + x] + Sqrt[x + Sqrt[1 + x]])^2)) - (Sqrt[1 + x] + Sqrt[x + Sqrt[1 + x]])/(2*(2 + 2*(Sqrt[1 + x] + Sqrt[x + Sqrt[1 + x]]) + (Sqrt[1 + x] + Sqrt[x + Sqrt[1 + x]])^2)) + (1/2)*ArcTan[1 + Sqrt[1 + x] + Sqrt[x + Sqrt[1 + x]]] + (3/2)*ArcTanh[1 - Sqrt[1 + x] - Sqrt[x + Sqrt[1 + x]]]}


{Sqrt[1 + Exp[-x]]/(Exp[x] - Exp[-x]), x, 3, (-Sqrt[2])*ArcTanh[Sqrt[1 + E^(-x)]/Sqrt[2]]}
{Sqrt[1 + Exp[-x]]/Sinh[x], x, 4, -2*Sqrt[2]*ArcTanh[Sqrt[1 + E^(-x)]/Sqrt[2]]}


{1/(Cos[x] + Cos[3*x])^5, x, 28, (-(523/256))*ArcTanh[Sin[x]] + (1483*ArcTanh[Sqrt[2]*Sin[x]])/(512*Sqrt[2]) + Sin[x]/(32*(1 - 2*Sin[x]^2)^4) - (17*Sin[x])/(192*(1 - 2*Sin[x]^2)^3) + (203*Sin[x])/(768*(1 - 2*Sin[x]^2)^2) - (437*Sin[x])/(512*(1 - 2*Sin[x]^2)) - (43/256)*Sec[x]*Tan[x] - (1/128)*Sec[x]^3*Tan[x]}
{1/(Cos[x] + Sin[x] + 1)^2, x, 2, -Log[1 + Tan[x/2]] - (Cos[x] - Sin[x])/(1 + Cos[x] + Sin[x])}


{Sqrt[1 + Tanh[4*x]], x, 2, ArcTanh[Sqrt[1 + Tanh[4*x]]/Sqrt[2]]/(2*Sqrt[2])}
{Tanh[x]/Sqrt[Exp[2*x] + Exp[x]], x, 7, (2*Sqrt[E^x + E^(2*x)])/E^x - ArcTan[(I - (1 - 2*I)*E^x)/(2*Sqrt[1 + I]*Sqrt[E^x + E^(2*x)])]/Sqrt[1 + I] + ArcTan[(I + (1 + 2*I)*E^x)/(2*Sqrt[1 - I]*Sqrt[E^x + E^(2*x)])]/Sqrt[1 - I]}
{Sqrt[Sinh[2*x]/Cosh[x]], x, 4, (2*I*Sqrt[2]*EllipticE[Pi/4 - (I*x)/2, 2]*Sqrt[Sinh[x]])/Sqrt[I*Sinh[x]]}


{Log[x^2 + Sqrt[1 - x^2]], x, 20, -((4*x*(1 - Sqrt[1 - x^2]))/(x^2 + (1 - Sqrt[1 - x^2])^2)) - 2*ArcTan[(1 - Sqrt[1 - x^2])/x] + (4/5)*Sqrt[10 + 5*Sqrt[5]]*ArcTan[(Sqrt[2 + Sqrt[5]]*(1 - Sqrt[1 - x^2]))/x] - (1/5)*Sqrt[10 + 10*Sqrt[5]]*ArcTan[(Sqrt[2 + Sqrt[5]]*(1 - Sqrt[1 - x^2]))/x] + (4/5)*Sqrt[-10 + 5*Sqrt[5]]*ArcTanh[(Sqrt[-2 + Sqrt[5]]*(1 - Sqrt[1 - x^2]))/x] + (1/5)*Sqrt[-10 + 10*Sqrt[5]]*ArcTanh[(Sqrt[-2 + Sqrt[5]]*(1 - Sqrt[1 - x^2]))/x] + x*Log[x^2 + Sqrt[1 - x^2]]}
{Log[1 + Exp[x]]/(1 + Exp[2*x]), x, 9, (-(1/2))*Log[(1/2 - I/2)*(I - E^x)]*Log[1 + E^x] - (1/2)*Log[(-(1/2) - I/2)*(I + E^x)]*Log[1 + E^x] - PolyLog[2, -E^x] - (1/2)*PolyLog[2, (1/2 - I/2)*(1 + E^x)] - (1/2)*PolyLog[2, (1/2 + I/2)*(1 + E^x)]}
{Log[1 + Cosh[x]^2]^2*Cosh[x], x, 2, (-I)*Sqrt[2]*(4*Log[-((Sqrt[2] - I*Sinh[x])/(Sqrt[2] + I*Sinh[x]))] + Log[(-I)*Sqrt[2] + Sinh[x]]^2 - Log[I*Sqrt[2] + Sinh[x]]^2 - 4*I*ArcTan[Sinh[x]/Sqrt[2]]*(Log[(-I)*Sqrt[2] + Sinh[x]] + Log[I*Sqrt[2] + Sinh[x]]) - 2*Log[(-I)*Sqrt[2] + Sinh[x]]*Log[1/2 - (I*Sinh[x])/(2*Sqrt[2])] + 2*Log[I*Sqrt[2] + Sinh[x]]*Log[(1/4)*(2 + I*Sqrt[2]*Sinh[x])] + 4*I*ArcTan[Sinh[x]/Sqrt[2]]*Log[2 + Sinh[x]^2] + 2*PolyLog[2, 1/2 - (I*Sinh[x])/(2*Sqrt[2])] - 2*PolyLog[2, (1/4)*(2 + I*Sqrt[2]*Sinh[x])]) + 8*Sinh[x] - 4*Log[2 + Sinh[x]^2]*Sinh[x] + Log[2 + Sinh[x]^2]^2*Sinh[x]}
(* {Log[1 + x + x^2]^2, x, 37, 8*x - 4*Sqrt[3]*ArcTan[(1 + 2*x)/Sqrt[3]] - 2*Log[1 + x + x^2] - 4*x*Log[1 + x + x^2] + x*Log[1 + x + x^2]^2 - (1/2)*Log[1 - I*Sqrt[3] + 2*x]*(Log[1 - I*Sqrt[3] + 2*x] + 2*Log[1/2 - (I*(1 + 2*x))/(2*Sqrt[3])] - 2*Log[(1/2)*I*Sqrt[3]*(1 - I*Sqrt[3] + 2*x) + (1/4)*(1 - I*Sqrt[3] + 2*x)^2]) + (1/2)*I*Sqrt[3]*Log[1 - I*Sqrt[3] + 2*x]*(Log[1 - I*Sqrt[3] + 2*x] + 2*Log[1/2 - (I*(1 + 2*x))/(2*Sqrt[3])] - 2*Log[(1/2)*I*Sqrt[3]*(1 - I*Sqrt[3] + 2*x) + (1/4)*(1 - I*Sqrt[3] + 2*x)^2]) - (1/2)*Log[1 + I*Sqrt[3] + 2*x]*(Log[1 + I*Sqrt[3] + 2*x] + 2*Log[1/2 + (I*(1 + 2*x))/(2*Sqrt[3])] - 2*Log[(-(1/2))*I*Sqrt[3]*(1 + I*Sqrt[3] + 2*x) + (1/4)*(1 + I*Sqrt[3] + 2*x)^2]) - (1/2)*I*Sqrt[3]*Log[1 + I*Sqrt[3] + 2*x]*(Log[1 + I*Sqrt[3] + 2*x] + 2*Log[1/2 + (I*(1 + 2*x))/(2*Sqrt[3])] - 2*Log[(-(1/2))*I*Sqrt[3]*(1 + I*Sqrt[3] + 2*x) + (1/4)*(1 + I*Sqrt[3] + 2*x)^2]) - (1 - I*Sqrt[3])*PolyLog[2, (I*(1 - I*Sqrt[3] + 2*x))/(2*Sqrt[3])] - (1 + I*Sqrt[3])*PolyLog[2, -((I*(1 + I*Sqrt[3] + 2*x))/(2*Sqrt[3]))]} *)
(* {Log[Sinh[x] + Cosh[x]^2]^2*Cosh[x], x, 38, -4*Sqrt[3]*ArcTan[(1 + 2*Sinh[x])/Sqrt[3]] - 2*Log[1 + Sinh[x] + Sinh[x]^2] - (1/2)*Log[1 - I*Sqrt[3] + 2*Sinh[x]]*(Log[1 - I*Sqrt[3] + 2*Sinh[x]] + 2*Log[1/2 - (I*(1 + 2*Sinh[x]))/(2*Sqrt[3])] - 2*Log[(1/2)*I*Sqrt[3]*(1 - I*Sqrt[3] + 2*Sinh[x]) + (1/4)*(1 - I*Sqrt[3] + 2*Sinh[x])^2]) + (1/2)*I*Sqrt[3]*Log[1 - I*Sqrt[3] + 2*Sinh[x]]*(Log[1 - I*Sqrt[3] + 2*Sinh[x]] + 2*Log[1/2 - (I*(1 + 2*Sinh[x]))/(2*Sqrt[3])] - 2*Log[(1/2)*I*Sqrt[3]*(1 - I*Sqrt[3] + 2*Sinh[x]) + (1/4)*(1 - I*Sqrt[3] + 2*Sinh[x])^2]) - (1/2)*Log[1 + I*Sqrt[3] + 2*Sinh[x]]*(Log[1 + I*Sqrt[3] + 2*Sinh[x]] + 2*Log[1/2 + (I*(1 + 2*Sinh[x]))/(2*Sqrt[3])] - 2*Log[(-(1/2))*I*Sqrt[3]*(1 + I*Sqrt[3] + 2*Sinh[x]) + (1/4)*(1 + I*Sqrt[3] + 2*Sinh[x])^2]) - (1/2)*I*Sqrt[3]*Log[1 + I*Sqrt[3] + 2*Sinh[x]]*(Log[1 + I*Sqrt[3] + 2*Sinh[x]] + 2*Log[1/2 + (I*(1 + 2*Sinh[x]))/(2*Sqrt[3])] - 2*Log[(-(1/2))*I*Sqrt[3]*(1 + I*Sqrt[3] + 2*Sinh[x]) + (1/4)*(1 + I*Sqrt[3] + 2*Sinh[x])^2]) - (1 - I*Sqrt[3])*PolyLog[2, (I*(1 - I*Sqrt[3] + 2*Sinh[x]))/(2*Sqrt[3])] - (1 + I*Sqrt[3])*PolyLog[2, -((I*(1 + I*Sqrt[3] + 2*Sinh[x]))/(2*Sqrt[3]))] + 8*Sinh[x] - 4*Log[1 + Sinh[x] + Sinh[x]^2]*Sinh[x] + Log[1 + Sinh[x] + Sinh[x]^2]^2*Sinh[x]} *)
(* {Log[x + Sqrt[1 + x]]/(1 + x^2), x, 0, 0} *)
(* {Log[x + Sqrt[1 + x]]^2/(1 + x)^2, x, 0, 0} *)
{Log[x + Sqrt[1 + x]]/x, x, 14, Log[1 - Sqrt[1 + x]]*Log[x + Sqrt[1 + x]] + Log[1 + Sqrt[1 + x]]*Log[x + Sqrt[1 + x]] - Log[1 - Sqrt[1 + x]]*Log[(1 - Sqrt[5] + 2*Sqrt[1 + x])/(3 - Sqrt[5])] - Log[1 + Sqrt[1 + x]]*Log[-((1 - Sqrt[5] + 2*Sqrt[1 + x])/(1 + Sqrt[5]))] - Log[1 + Sqrt[1 + x]]*Log[-((1 + Sqrt[5] + 2*Sqrt[1 + x])/(1 - Sqrt[5]))] - Log[1 - Sqrt[1 + x]]*Log[(1 + Sqrt[5] + 2*Sqrt[1 + x])/(3 + Sqrt[5])] - PolyLog[2, (2*(1 - Sqrt[1 + x]))/(3 - Sqrt[5])] - PolyLog[2, (2*(1 - Sqrt[1 + x]))/(3 + Sqrt[5])] - PolyLog[2, (2*(1 + Sqrt[1 + x]))/(1 - Sqrt[5])] - PolyLog[2, (2*(1 + Sqrt[1 + x]))/(1 + Sqrt[5])]}


{ArcTan[2*Tan[x]], x, 7, x*ArcTan[2*Tan[x]] + (1/2)*I*x*Log[1 - 3*E^(2*I*x)] - (1/2)*I*x*Log[1 - (1/3)*E^(2*I*x)] - (1/4)*PolyLog[2, (1/3)*E^(2*I*x)] + (1/4)*PolyLog[2, 3*E^(2*I*x)]}
{ArcTan[x]*Log[x]/x, x, 6, (1/2)*I*Log[x]*PolyLog[2, (-I)*x] - (1/2)*I*Log[x]*PolyLog[2, I*x] - (1/2)*I*PolyLog[3, (-I)*x] + (1/2)*I*PolyLog[3, I*x]}


(* Note: Mathematica is unable to differentiate result back to integrand! *) 
{ArcTan[x]^2*Sqrt[1 + x^2], x, 8, ArcSinh[x] - Sqrt[1 + x^2]*ArcTan[x] + (1/2)*x*Sqrt[1 + x^2]*ArcTan[x]^2 - I*ArcTan[E^(I*ArcTan[x])]*ArcTan[x]^2 + I*ArcTan[x]*PolyLog[2, (-I)*E^(I*ArcTan[x])] - I*ArcTan[x]*PolyLog[2, I*E^(I*ArcTan[x])] - PolyLog[3, (-I)*E^(I*ArcTan[x])] + PolyLog[3, I*E^(I*ArcTan[x])]}


(* ::Section:: *)
(*Manuel Bronstein - Symbolic Integration Tutorial Problems*)


(* ::Subsection::Closed:: *)
(*2  Algebraic Functions*)


{(2*x^8 + 1)*(Sqrt[x^8 + 1]/(x^17 + 2*x^9 + x)), x, 4, -(1/(4*Sqrt[1 + x^8])) - (1/4)*ArcTanh[Sqrt[1 + x^8]]}
{1/(1 + x^2), x, 1, ArcTan[x]}
{Sqrt[x^8 + 1]/(x*(x^8 + 1)), x, 2, (-(1/4))*ArcTanh[Sqrt[1 + x^8]]}
{x/Sqrt[1 - x^3], x, 6, -(((1/2 + I/2)*Sqrt[-1 + I*Sqrt[3] - 2*x]*(1 - x)*Sqrt[(-I)*(1 + I*Sqrt[3] + 2*x)]*EllipticE[I*ArcSinh[((1/2 + I/2)*Sqrt[-1 + I*Sqrt[3] - 2*x])/3^(1/4)], (2*Sqrt[3])/(3*I + Sqrt[3])])/(Sqrt[(I*(1 - x))/(3*I + Sqrt[3])]*Sqrt[1 - x^3])) + ((1 + I)*Sqrt[-1 + I*Sqrt[3] - 2*x]*Sqrt[(I*(1 - x))/(3*I + Sqrt[3])]*Sqrt[(-I)*(1 + I*Sqrt[3] + 2*x)]*EllipticF[I*ArcSinh[((1/2 + I/2)*Sqrt[-1 + I*Sqrt[3] - 2*x])/3^(1/4)], (2*Sqrt[3])/(3*I + Sqrt[3])])/Sqrt[1 - x^3]}
{1/(x*Sqrt[1 - x^3]), x, 2, (-(2/3))*ArcTanh[Sqrt[1 - x^3]]}


(* ::Subsection::Closed:: *)
(*3  Elementary Functions*)


{(x - Tan[x])/Tan[x]^2, x, 6, -(x^2/2) - x*Cot[x]}
{1 + x*Tan[x] + Tan[x]^2, x, 7, (I*x^2)/2 - x*Log[1 + E^(2*I*x)] + (1/2)*I*PolyLog[2, -E^(2*I*x)] + Tan[x]}
{Sin[x]/x, x, 1, SinIntegral[x]}
{(3*(x + E^x)^(1/3) + (2*x^2 + 3*x)*E^x + 5*x^2)/(x*(x + E^x)^(1/3)), x, 8, 3*x*(E^x + x)^(2/3) + 3*Log[x]}


{1/x + (1 + 1/x)/(x + Log[x])^(3/2), x, 2, Log[x] - 2/Sqrt[x + Log[x]]}
{(Log[x]^2 + 2*x*Log[x] + x^2 + (x + 1)*Sqrt[x + Log[x]])/(x*Log[x]^2 + 2*x^2*Log[x] + x^3), x, -10, Log[x] - 2/Sqrt[x + Log[x]]}

{(2*Log[x]^2 - Log[x] - x^2)/(Log[x]^3 - x^2*Log[x]), x, 5, (-(1/2))*Log[x - Log[x]] + (1/2)*Log[x + Log[x]] + LogIntegral[x]}
(* {Log[1 + E^x]^(1/3)/(1 + Log[1 + E^x]), x, 0, Int[Log[1 + E^x]^(1/3)/(1 + Log[1 + E^x]), x]} *)
(* {((x^2 + 2*x + 1)*Sqrt[x + Log[x]] + (3*x + 1)*Log[x] + 3*x^2 + x)/((x*Log[x] + x^2)*Sqrt[x + Log[x]] + x^2*Log[x] + x^3), x, 0, 2*Sqrt[x + Log[x]] + 2*Log[x + Sqrt[x + Log[x]]]} *)


(* ::Section:: *)
(*Martin Welz on Sci.Math.Symbolic*)


(* ::Subsection::Closed:: *)
(*4 June 2010*)


(* {x*(x^2 + 3)/(2*a^2 + b^2*(x^2 + 1))^(5/2)*Log[(Sqrt[2]*x*Sqrt[2*a^2 + b^2*(x^2 + 1)] - 2*x*a + b*(x^2 + 1))/x], x, 0, Sqrt[2]*(43*a^6 + 63*b^2*a^4 + 33*b^4*a^2 + 5*b^6)*(ArcTan[b*(x/Sqrt[2*a^2 + b^2])]/(6*b^4*Sqrt[2*a^2 + b^2]*(3*a^2 + b^2)^3)) + Sqrt[2]*(Sqrt[4*a^2 + b^2] + a)^3*(3*a*Sqrt[4*a^2 + b^2] - 7*a^2 - 2*b^2)*(Log[Sqrt[2]*(Sqrt[4*a^2 + b^2] - a)*Sqrt[2*a^2 + b^2*(x^2 + 1)] + b*x*Sqrt[4*a^2 + b^2] + 2*a^2 - 2*b*x*a + b^2]/(6*b^4*(3*a^2 + b^2)^3)) + Sqrt[2]*(Sqrt[4*a^2 + b^2] - a)^3*(3*a*Sqrt[4*a^2 + b^2] + 7*a^2 + 2*b^2)*(Log[Sqrt[2]*(Sqrt[4*a^2 + b^2] + a)*Sqrt[2*a^2 + b^2*(x^2 + 1)] + b*x*Sqrt[4*a^2 + b^2] - 2*a^2 + 2*b*x*a - b^2]/(6*b^4*(3*a^2 + b^2)^3)) - (4*a^2 + b^2*(3*x^2 + 5))*(Log[(Sqrt[2]*x*Sqrt[2*a^2 + b^2*(x^2 + 1)] - 2*x*a + b*(x^2 + 1))/x]/(3*b^4*(2*a^2 + b^2*(x^2 + 1))^(3/2))) - (4*a^2 + 5*b^2)*(Log[(Sqrt[2*a^2 + b^2*(x^2 + 1)] - Sqrt[2*a^2 + b^2])/x]/(3*b^4*(2*a^2 + b^2)^(3/2))) + Sqrt[2]*(2*a^2 + b^2)*(Log[Sqrt[2*a^2 + b^2*(x^2 + 1)] - Sqrt[2]*a]/(6*b^4*a^3)) - Sqrt[2]*(5*a^2 + b^2)*(8*a^6 + 9*b^2*a^4 + 6*b^4*a^2 + b^6)*(Log[2*a^2 + b^2*(x^2 + 1)]/(12*b^4*a^3*(3*a^2 + b^2)^3)) + Sqrt[2]*(b^2 - a^2)*((Sqrt[2]*Sqrt[2*a^2 + b^2*(x^2 + 1)]*(10*a^6 + 2*b*x*a^5 + 16*b^2*a^4 + 7*b^4*a^2 + b^6) + 12*a^7 + 6*b*x*a^6 + 16*b^2*a^5 + 5*b^3*x*a^4 + 7*b^4*a^3 + b^5*x*a^2 + b^6*a)/(6*b^4*a^2*(2*a^2 + b^2)*(2*a^2 + b^2*(x^2 + 1))*(3*a^2 + b^2)^2))} *)

(* The following two integrands are equivalent! *)
{1/Sqrt[1 - a*x], x, 1, -((2*Sqrt[1 - a*x])/a)}
{(Log[a*x - 1] - 2*Log[-Sqrt[a*x - 1]])/(2*Pi*Sqrt[a*x - 1]), x, 6, -((2*Sqrt[1 - a*x])/a), -((2*Sqrt[-1 + a*x]*Log[-Sqrt[-1 + a*x]])/(a*Pi)) + (Sqrt[-1 + a*x]*Log[-1 + a*x])/(a*Pi)}


(* ::Subsection::Closed:: *)
(*6 June 2010*)


(* {Sqrt[b^2*x^2 + 2*a^2 + b^2]/(b^3*x^4 + 4*a*b^2*x^3 + 2*a^2*b*x^2 + 4*a*x*(2*a^2 + b^2) - b*(2*a^2 + b^2)), x, 0, 0}
{Sqrt[b^2*x^2 + 2*a^2 + b^2]/(b^3*x^6 + 4*a*b^2*x^5 + b*x^4*(2*a^2 + b^2) + 8*a*x^3*(a^2 + b^2) - b^3*x^2 + 4*a*x*(2*a^2 + b^2) - b*(2*a^2 + b^2)), x, 0, 0}
{x/((b^2*x^2 + 2*a^2 + b^2)*((b*x^2 - 2*a*x + b)*Sqrt[b^2*x^2 + 2*a^2 + b^2] + Sqrt[2]*b^2*x^3 + Sqrt[2]*x*(2*a^2 + b^2))), x, 0, 0} *)


(* ::Subsection::Closed:: *)
(*20 June 2010*)


(* ::Subsubsection::Closed:: *)
(*Problem #1*)


{1/(Sqrt[x^2 + 1] + 2*x)^2, x, 8, (4*x)/(3*(1 - 3*x^2)) - (2*Sqrt[1 + x^2])/(3*(1 - 3*x^2)) - ArcTanh[Sqrt[3]*x]/(3*Sqrt[3]) + ArcTanh[(1/2)*Sqrt[3]*Sqrt[1 + x^2]]/(3*Sqrt[3])}


(* ::Subsubsection::Closed:: *)
(*Problem #2*)


{1/(Sqrt[x^2 - 1]*(3*x^2 - 4)^2), x, 2, (3*x*Sqrt[-1 + x^2])/(8*(4 - 3*x^2)) + (5/16)*ArcTanh[x/(2*Sqrt[-1 + x^2])]}


(* ::Subsubsection::Closed:: *)
(*Problem #3*)


{1/(2*Sqrt[x] + Sqrt[x + 1])^2, x, 6, 8/(9*(1 - 3*x)) - (4*Sqrt[x]*Sqrt[1 + x])/(3*(1 - 3*x)) - (8*ArcSinh[Sqrt[x]])/9 + (10/9)*ArcTanh[(2*Sqrt[x])/Sqrt[1 + x]] + (5/9)*Log[1 - 3*x]}


(* ::Subsubsection::Closed:: *)
(*Problem #4*)


{Sqrt[x^2 - 1]/(x - I)^2, x, 4, Sqrt[-1 + x^2]/(I - x) - (I*ArcTan[(1 - I*x)/(Sqrt[2]*Sqrt[-1 + x^2])])/Sqrt[2] + ArcTanh[x/Sqrt[-1 + x^2]]}


(* ::Subsubsection::Closed:: *)
(*Problem #5*)


{1/(Sqrt[x^2 - 1]*(x^2 + 1)^2), x, 2, -((x*Sqrt[-1 + x^2])/(4*(1 + x^2))) + (3*ArcTanh[(Sqrt[2]*x)/Sqrt[-1 + x^2]])/(4*Sqrt[2])}


(* ::Subsubsection::Closed:: *)
(*Problem #6*)


{1/(Sqrt[x - 1]*(Sqrt[x - 1] + Sqrt[x])^2), x, 7, (2*Sqrt[-1 + x])/3 + (4/3)*Sqrt[-1 + x]*x - (4*x^(3/2))/3}


(* ::Subsubsection::Closed:: *)
(*Problem #7*)


{1/(Sqrt[x^2 - 1]*(Sqrt[x^2 - 1] + Sqrt[x])^2), x, -1, (2 - 4*x)/(5*(Sqrt[x] + Sqrt[-1 + x^2])) + (1/25)*Sqrt[-110 + 50*Sqrt[5]]*ArcTan[(1/2)*Sqrt[2 + 2*Sqrt[5]]*Sqrt[x]] - (1/50)*Sqrt[-110 + 50*Sqrt[5]]*ArcTan[(Sqrt[-2 + 2*Sqrt[5]]*Sqrt[-1 + x^2])/(2 - (1 - Sqrt[5])*x)] - (1/25)*Sqrt[110 + 50*Sqrt[5]]*ArcTanh[(1/2)*Sqrt[-2 + 2*Sqrt[5]]*Sqrt[x]] - (1/50)*Sqrt[110 + 50*Sqrt[5]]*ArcTanh[(Sqrt[2 + 2*Sqrt[5]]*Sqrt[-1 + x^2])/(2 - x - Sqrt[5]*x)]}


{(Sqrt[x] - Sqrt[-1 + x^2])^2/((1 + x - x^2)^2*Sqrt[-1 + x^2]), x, -50, (2 - 4*x)/(5*(Sqrt[x] + Sqrt[-1 + x^2])) + (1/25)*Sqrt[-110 + 50*Sqrt[5]]*ArcTan[(1/2)*Sqrt[2 + 2*Sqrt[5]]*Sqrt[x]] - (1/50)*Sqrt[-110 + 50*Sqrt[5]]*ArcTan[(Sqrt[-2 + 2*Sqrt[5]]*Sqrt[-1 + x^2])/(2 - (1 - Sqrt[5])*x)] - (1/25)*Sqrt[110 + 50*Sqrt[5]]*ArcTanh[(1/2)*Sqrt[-2 + 2*Sqrt[5]]*Sqrt[x]] - (1/50)*Sqrt[110 + 50*Sqrt[5]]*ArcTanh[(Sqrt[2 + 2*Sqrt[5]]*Sqrt[-1 + x^2])/(2 - x - Sqrt[5]*x)]}


{1/(Sqrt[2]*(1 + x)^2*Sqrt[-I + x^2]) + 1/(Sqrt[2]*(1 + x)^2*Sqrt[I + x^2]), x, 5, -(((1/2 + I/2)*Sqrt[-I + x^2])/(Sqrt[2]*(1 + x))) - ((1/2 - I/2)*Sqrt[I + x^2])/(Sqrt[2]*(1 + x)) + ArcTanh[(I + x)/(Sqrt[1 - I]*Sqrt[-I + x^2])]/((1 - I)^(3/2)*Sqrt[2]) - ArcTanh[(I - x)/(Sqrt[1 + I]*Sqrt[I + x^2])]/((1 + I)^(3/2)*Sqrt[2])}


(* ::Subsubsection::Closed:: *)
(*Problem #8*)


{Sqrt[Sqrt[x^4 + 1] + x^2]/((x + 1)^2*Sqrt[x^4 + 1]), x, 5, -(Sqrt[1 - I*x^2]/(2*(1 + x))) - Sqrt[1 + I*x^2]/(2*(1 + x)) - (1/4)*(1 - I)^(3/2)*ArcTanh[(1 + I*x)/(Sqrt[1 - I]*Sqrt[1 - I*x^2])] - (1/4)*(1 + I)^(3/2)*ArcTanh[(1 - I*x)/(Sqrt[1 + I]*Sqrt[1 + I*x^2])]}
{Sqrt[Sqrt[x^4 + 1] + x^2]/((x + 1)*Sqrt[x^4 + 1]), x, 3, (-(1/2))*Sqrt[1 - I]*ArcTanh[(1 + I*x)/(Sqrt[1 - I]*Sqrt[1 - I*x^2])] - (1/2)*Sqrt[1 + I]*ArcTanh[(1 - I*x)/(Sqrt[1 + I]*Sqrt[1 + I*x^2])]}
{Sqrt[Sqrt[x^4 + 1] + x^2]/Sqrt[x^4 + 1], x, 1, ArcTanh[(Sqrt[2]*x)/Sqrt[x^2 + Sqrt[1 + x^4]]]/Sqrt[2]}
{Sqrt[Sqrt[x^4 + 1] - x^2]/Sqrt[x^4 + 1], x, 1, ArcTan[(Sqrt[2]*x)/Sqrt[-x^2 + Sqrt[1 + x^4]]]/Sqrt[2]}


(* ::Subsubsection::Closed:: *)
(*Problem #9*)


{((x - 1)^(3/2) + (x + 1)^(3/2))/((x + 1)^(3/2)*(x - 1)^(3/2)), x, 2, -(2/Sqrt[-1 + x]) - 2/Sqrt[1 + x]}


(* ::Subsection::Closed:: *)
(*15 August 2010*)


{(x + Sqrt[a + x^2])^b*(a + x^2)^2, x, 4, -((a^5*(x + Sqrt[a + x^2])^(-5 + b))/(32*(5 - b))) - (5*a^4*(x + Sqrt[a + x^2])^(-3 + b))/(32*(3 - b)) - (5*a^3*(x + Sqrt[a + x^2])^(-1 + b))/(16*(1 - b)) + (5*a^2*(x + Sqrt[a + x^2])^(1 + b))/(16*(1 + b)) + (5*a*(x + Sqrt[a + x^2])^(3 + b))/(32*(3 + b)) + (x + Sqrt[a + x^2])^(5 + b)/(32*(5 + b))}
{(x + Sqrt[a + x^2])^b*(a + x^2)^1, x, 4, -((a^3*(x + Sqrt[a + x^2])^(-3 + b))/(8*(3 - b))) - (3*a^2*(x + Sqrt[a + x^2])^(-1 + b))/(8*(1 - b)) + (3*a*(x + Sqrt[a + x^2])^(1 + b))/(8*(1 + b)) + (x + Sqrt[a + x^2])^(3 + b)/(8*(3 + b))}
{(x + Sqrt[x^2 + a])^b*(a + x^2)^0, x, 4, -((a*(x + Sqrt[a + x^2])^(-1 + b))/(2*(1 - b))) + (x + Sqrt[a + x^2])^(1 + b)/(2*(1 + b))}
{(x + Sqrt[a + x^2])^b/(a + x^2)^1, x, 2, (2*(x + Sqrt[a + x^2])^(1 + b)*Hypergeometric2F1[1, (1 + b)/2, (3 + b)/2, -((x + Sqrt[a + x^2])^2/a)])/(a*(1 + b))}
{(x + Sqrt[a + x^2])^b/(a + x^2)^2, x, 6, -(((1 - b)*(x + Sqrt[a + x^2])^(1 + b))/a^2) + (2*(x + Sqrt[a + x^2])^(3 + b))/(a*(a + (x + Sqrt[a + x^2])^2)^2) + ((1 - b)*(x + Sqrt[a + x^2])^(3 + b))/(a^2*(a + (x + Sqrt[a + x^2])^2)) + ((1 - b)*(x + Sqrt[a + x^2])^(1 + b)*Hypergeometric2F1[1, (1 + b)/2, (3 + b)/2, -((x + Sqrt[a + x^2])^2/a)])/a^2}


{(x - Sqrt[a + x^2])^b*(a + x^2)^2, x, 5, -((a^5*(-(a/(x + Sqrt[a + x^2])))^b)/(32*(5 + b)*(x + Sqrt[a + x^2])^5)) - (5*a^4*(-(a/(x + Sqrt[a + x^2])))^b)/(32*(3 + b)*(x + Sqrt[a + x^2])^3) - (5*a^3*(-(a/(x + Sqrt[a + x^2])))^b)/(16*(1 + b)*(x + Sqrt[a + x^2])) + (5*a^2*(-(a/(x + Sqrt[a + x^2])))^b*(x + Sqrt[a + x^2]))/(16*(1 - b)) + (5*a*(-(a/(x + Sqrt[a + x^2])))^b*(x + Sqrt[a + x^2])^3)/(32*(3 - b)) + ((-(a/(x + Sqrt[a + x^2])))^b*(x + Sqrt[a + x^2])^5)/(32*(5 - b))}
{(x - Sqrt[a + x^2])^b*(a + x^2)^1, x, 5, -((a^3*(-(a/(x + Sqrt[a + x^2])))^b)/(8*(3 + b)*(x + Sqrt[a + x^2])^3)) - (3*a^2*(-(a/(x + Sqrt[a + x^2])))^b)/(8*(1 + b)*(x + Sqrt[a + x^2])) + (3*a*(-(a/(x + Sqrt[a + x^2])))^b*(x + Sqrt[a + x^2]))/(8*(1 - b)) + ((-(a/(x + Sqrt[a + x^2])))^b*(x + Sqrt[a + x^2])^3)/(8*(3 - b))}
{(x - Sqrt[x^2 + a])^b*(a + x^2)^0, x, 5, -(((x - Sqrt[a + x^2])^b*(x + b*Sqrt[a + x^2]))/(-1 + b^2)), -((a*(-(a/(x + Sqrt[a + x^2])))^b)/(2*(1 + b)*(x + Sqrt[a + x^2]))) + ((-(a/(x + Sqrt[a + x^2])))^b*(x + Sqrt[a + x^2]))/(2*(1 - b))}
{(x - Sqrt[a + x^2])^b/(a + x^2)^1, x, 3, (2*(-(a/(x + Sqrt[a + x^2])))^b*(x + Sqrt[a + x^2])*Hypergeometric2F1[1, (1 - b)/2, (3 - b)/2, -((x + Sqrt[a + x^2])^2/a)])/(a*(1 - b))}
{(x - Sqrt[a + x^2])^b/(a + x^2)^2, x, 7, -(((1 + b)*(-(a/(x + Sqrt[a + x^2])))^b*(x + Sqrt[a + x^2]))/a^2) + (2*(-(a/(x + Sqrt[a + x^2])))^b*(x + Sqrt[a + x^2])^3)/(a*(a + (x + Sqrt[a + x^2])^2)^2) + ((1 + b)*(-(a/(x + Sqrt[a + x^2])))^b*(x + Sqrt[a + x^2])^3)/(a^2*(a + (x + Sqrt[a + x^2])^2)) + ((1 + b)*(-(a/(x + Sqrt[a + x^2])))^b*(x + Sqrt[a + x^2])*Hypergeometric2F1[1, (1 - b)/2, (3 - b)/2, -((x + Sqrt[a + x^2])^2/a)])/a^2}


{(x + Sqrt[x^2 + a])^b*(x^2 + a)^(5/2), x, 4, -((a^6*(x + Sqrt[a + x^2])^(-6 + b))/(64*(6 - b))) - (3*a^5*(x + Sqrt[a + x^2])^(-4 + b))/(32*(4 - b)) - (15*a^4*(x + Sqrt[a + x^2])^(-2 + b))/(64*(2 - b)) + (5*a^3*(x + Sqrt[a + x^2])^b)/(16*b) + (15*a^2*(x + Sqrt[a + x^2])^(2 + b))/(64*(2 + b)) + (3*a*(x + Sqrt[a + x^2])^(4 + b))/(32*(4 + b)) + (x + Sqrt[a + x^2])^(6 + b)/(64*(6 + b))}
{(x + Sqrt[x^2 + a])^b*(x^2 + a)^(3/2), x, 4, -((a^4*(x + Sqrt[a + x^2])^(-4 + b))/(16*(4 - b))) - (a^3*(x + Sqrt[a + x^2])^(-2 + b))/(4*(2 - b)) + (3*a^2*(x + Sqrt[a + x^2])^b)/(8*b) + (a*(x + Sqrt[a + x^2])^(2 + b))/(4*(2 + b)) + (x + Sqrt[a + x^2])^(4 + b)/(16*(4 + b))}
{(x + Sqrt[x^2 + a])^b*(x^2 + a)^(1/2), x, 4, -((a^2*(x + Sqrt[a + x^2])^(-2 + b))/(4*(2 - b))) + (a*(x + Sqrt[a + x^2])^b)/(2*b) + (x + Sqrt[a + x^2])^(2 + b)/(4*(2 + b))}
{(x + Sqrt[x^2 + a])^b/(x^2 + a)^(1/2), x, 3, (x + Sqrt[a + x^2])^b/b}
{(x + Sqrt[x^2 + a])^b/(x^2 + a)^(3/2), x, 4, (2*(x + Sqrt[a + x^2])^(2 + b))/(a*(a + (x + Sqrt[a + x^2])^2)) - (2*b*(x + Sqrt[a + x^2])^(2 + b)*Hypergeometric2F1[1, (2 + b)/2, (4 + b)/2, -((x + Sqrt[a + x^2])^2/a)])/(a^2*(2 + b))}
{(x + Sqrt[x^2 + a])^b/(x^2 + a)^(5/2), x, 7, ((2 - b)*b*(x + Sqrt[a + x^2])^(2 + b))/(3*a^3) + (8*(x + Sqrt[a + x^2])^(4 + b))/(3*a*(a + (x + Sqrt[a + x^2])^2)^3) + (2*(2 - b)*(x + Sqrt[a + x^2])^(4 + b))/(3*a^2*(a + (x + Sqrt[a + x^2])^2)^2) - ((2 - b)*b*(x + Sqrt[a + x^2])^(4 + b))/(3*a^3*(a + (x + Sqrt[a + x^2])^2)) - ((2 - b)*b*(x + Sqrt[a + x^2])^(2 + b)*Hypergeometric2F1[1, (2 + b)/2, (4 + b)/2, -((x + Sqrt[a + x^2])^2/a)])/(3*a^3)}


{(x - Sqrt[x^2 + a])^b*(x^2 + a)^(5/2), x, 5, -((5*a^3*(-(a/(x + Sqrt[a + x^2])))^b)/(16*b)) - (a^6*(-(a/(x + Sqrt[a + x^2])))^b)/(64*(6 + b)*(x + Sqrt[a + x^2])^6) - (3*a^5*(-(a/(x + Sqrt[a + x^2])))^b)/(32*(4 + b)*(x + Sqrt[a + x^2])^4) - (15*a^4*(-(a/(x + Sqrt[a + x^2])))^b)/(64*(2 + b)*(x + Sqrt[a + x^2])^2) + (15*a^2*(-(a/(x + Sqrt[a + x^2])))^b*(x + Sqrt[a + x^2])^2)/(64*(2 - b)) + (3*a*(-(a/(x + Sqrt[a + x^2])))^b*(x + Sqrt[a + x^2])^4)/(32*(4 - b)) + ((-(a/(x + Sqrt[a + x^2])))^b*(x + Sqrt[a + x^2])^6)/(64*(6 - b))}
{(x - Sqrt[x^2 + a])^b*(x^2 + a)^(3/2), x, 5, -((3*a^2*(-(a/(x + Sqrt[a + x^2])))^b)/(8*b)) - (a^4*(-(a/(x + Sqrt[a + x^2])))^b)/(16*(4 + b)*(x + Sqrt[a + x^2])^4) - (a^3*(-(a/(x + Sqrt[a + x^2])))^b)/(4*(2 + b)*(x + Sqrt[a + x^2])^2) + (a*(-(a/(x + Sqrt[a + x^2])))^b*(x + Sqrt[a + x^2])^2)/(4*(2 - b)) + ((-(a/(x + Sqrt[a + x^2])))^b*(x + Sqrt[a + x^2])^4)/(16*(4 - b))}
{(x - Sqrt[x^2 + a])^b*(x^2 + a)^(1/2), x, 5, -((a*(-(a/(x + Sqrt[a + x^2])))^b)/(2*b)) - (a^2*(-(a/(x + Sqrt[a + x^2])))^b)/(4*(2 + b)*(x + Sqrt[a + x^2])^2) + ((-(a/(x + Sqrt[a + x^2])))^b*(x + Sqrt[a + x^2])^2)/(4*(2 - b))}
{(x - Sqrt[x^2 + a])^b/(x^2 + a)^(1/2), x, 4, -((x - Sqrt[a + x^2])^b/b), -((-(a/(x + Sqrt[a + x^2])))^b/b)}
{(x - Sqrt[x^2 + a])^b/(x^2 + a)^(3/2), x, 5, (2*(-(a/(x + Sqrt[a + x^2])))^b*(x + Sqrt[a + x^2])^2)/(a*(a + (x + Sqrt[a + x^2])^2)) + (2*b*(-(a/(x + Sqrt[a + x^2])))^b*(x + Sqrt[a + x^2])^2*Hypergeometric2F1[1, (2 - b)/2, (4 - b)/2, -((x + Sqrt[a + x^2])^2/a)])/(a^2*(2 - b))}
{(x - Sqrt[x^2 + a])^b/(x^2 + a)^(5/2), x, 8, -((b*(2 + b)*(-(a/(x + Sqrt[a + x^2])))^b*(x + Sqrt[a + x^2])^2)/(3*a^3)) + (8*(-(a/(x + Sqrt[a + x^2])))^b*(x + Sqrt[a + x^2])^4)/(3*a*(a + (x + Sqrt[a + x^2])^2)^3) + (2*(2 + b)*(-(a/(x + Sqrt[a + x^2])))^b*(x + Sqrt[a + x^2])^4)/(3*a^2*(a + (x + Sqrt[a + x^2])^2)^2) + (b*(2 + b)*(-(a/(x + Sqrt[a + x^2])))^b*(x + Sqrt[a + x^2])^4)/(3*a^3*(a + (x + Sqrt[a + x^2])^2)) + (b*(2 + b)*(-(a/(x + Sqrt[a + x^2])))^b*(x + Sqrt[a + x^2])^2*Hypergeometric2F1[1, (2 - b)/2, (4 - b)/2, -((x + Sqrt[a + x^2])^2/a)])/(3*a^3)}


{1/(a + b*E^(p*x))^2, x, 2, 1/(a*(a + b*E^(p*x))*p) + x/a^2 - Log[a + b*E^(p*x)]/(a^2*p)}
{1/(a*E^(p*x) + b*E^(p*x))^2, x, 3, -(1/(E^(2*p*x)*(2*(a + b)^2*p)))}
{x/(a*E^(p*x) + b*E^(p*x))^2, x, 4, -(1/(E^(2*p*x)*(4*(a + b)^2*p^2))) - x/(E^(2*p*x)*(2*(a + b)^2*p))}


(* ::Section::Closed:: *)
(*Wester, Michael*)


(* Gradshteyn and Ryzhik 2.244(8) *)
{(-5 + 3*x)^2/(-1 + 2*x)^(7/2), x, 2, -(49/(20*(-1 + 2*x)^(5/2))) + 7/(2*(-1 + 2*x)^(3/2)) - 9/(4*Sqrt[-1 + 2*x])}
