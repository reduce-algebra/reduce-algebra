(* ::Package:: *)

(* ::Title:: *)
(*Normalization integration problems*)


(* ::Section::Closed:: *)
(*Integrands of the form u (a x^m+b x^n+...)^p*)


{1/(Sqrt[x] + 4*x^(3/2)), x, 2, ArcTan[2*Sqrt[x]]}
{1/(Sqrt[x] - x^(5/2)), x, 5, ArcTan[Sqrt[x]] + ArcTanh[Sqrt[x]]}
{1/(-x^(1/4) + Sqrt[x]), x, 4, 4*x^(1/4) + 2*Sqrt[x] + 4*Log[1 - x^(1/4)]}
{1/(x^(1/3) + Sqrt[x]), x, 5, 6*x^(1/6) - 3*x^(1/3) + 2*Sqrt[x] - 6*Log[1 + x^(1/6)]}
{1/(x^(1/4) + Sqrt[x]), x, 4, -4*x^(1/4) + 2*Sqrt[x] + 4*Log[1 + x^(1/4)]}
{1/(-x^(1/3) + x^(2/3)), x, 3, 3*x^(1/3) + 3*Log[1 - x^(1/3)]}
{1/(x^(-1/4) + Sqrt[x]), x, 8, 2*Sqrt[x] + (4*ArcTan[(1 - 2*x^(1/4))/Sqrt[3]])/Sqrt[3] + (4/3)*Log[1 + x^(1/4)] - (2/3)*Log[1 - x^(1/4) + Sqrt[x]]}
{1/(x^(1/4) + x^(1/3)), x, 10, -12*x^(1/12) + 6*x^(1/6) - 4*x^(1/4) + 3*x^(1/3) - (12*x^(5/12))/5 + 2*Sqrt[x] - (12*x^(7/12))/7 + (3*x^(2/3))/2 + 12*Log[1 + x^(1/12)]}
{1/(x^(-1/3) + x^(-1/4)), x, 17, 12*x^(1/12) - 6*x^(1/6) + 4*x^(1/4) - 3*x^(1/3) + (12*x^(5/12))/5 - 2*Sqrt[x] + (12*x^(7/12))/7 - (3*x^(2/3))/2 + (4*x^(3/4))/3 - (6*x^(5/6))/5 + (12*x^(11/12))/11 - x + (12*x^(13/12))/13 - (6*x^(7/6))/7 + (4*x^(5/4))/5 - 12*Log[1 + x^(1/12)]}
{1/(-x^(-1/3) + Sqrt[x]), x, 11, 2*Sqrt[x] + (3/5)*Sqrt[10 - 2*Sqrt[5]]*ArcTan[(1 - Sqrt[5] + 4*x^(1/6))/Sqrt[10 + 2*Sqrt[5]]] - (3/5)*Sqrt[10 + 2*Sqrt[5]]*ArcTan[(1 + Sqrt[5] + 4*x^(1/6))/Sqrt[10 - 2*Sqrt[5]]] + (6/5)*Log[1 - x^(1/6)] - (3/10)*(1 + Sqrt[5])*Log[2 + (1 - Sqrt[5])*x^(1/6) + 2*x^(1/3)] - (3/10)*(1 - Sqrt[5])*Log[2 + (1 + Sqrt[5])*x^(1/6) + 2*x^(1/3)], 2*Sqrt[x] - (3/5)*(1 - Sqrt[5])*Sqrt[(1/2)*(5 + Sqrt[5])]*ArcTan[(1 - Sqrt[5] + 4*x^(1/6))/Sqrt[2*(5 + Sqrt[5])]] - (3/5)*Sqrt[(1/2)*(5 - Sqrt[5])]*(1 + Sqrt[5])*ArcTan[(1 + Sqrt[5] + 4*x^(1/6))/Sqrt[2*(5 - Sqrt[5])]] + (6/5)*Log[1 - x^(1/6)] - (3/10)*(1 + Sqrt[5])*Log[2 + (1 - Sqrt[5])*x^(1/6) + 2*x^(1/3)] - (3/10)*(1 - Sqrt[5])*Log[2 + (1 + Sqrt[5])*x^(1/6) + 2*x^(1/3)]}


{Sqrt[x]/(x + x^2), x, 2, 2*ArcTan[Sqrt[x]]}
{x/(4*Sqrt[x] + x), x, 4, -8*Sqrt[x] + x + 32*Log[4 + Sqrt[x]]}
{Sqrt[x]/(x^(1/3) + x), x, 10, 2*Sqrt[x] + (3*ArcTan[1 - Sqrt[2]*x^(1/6)])/Sqrt[2] - (3*ArcTan[1 + Sqrt[2]*x^(1/6)])/Sqrt[2] - (3*Log[1 - Sqrt[2]*x^(1/6) + x^(1/3)])/(2*Sqrt[2]) + (3*Log[1 + Sqrt[2]*x^(1/6) + x^(1/3)])/(2*Sqrt[2])}
{x^(1/3)/(x^(1/4) + Sqrt[x]), x, 11, -12*x^(1/12) + 3*x^(1/3) - (12*x^(7/12))/7 + (6*x^(5/6))/5 - 4*Sqrt[3]*ArcTan[(1 - 2*x^(1/12))/Sqrt[3]] + 4*Log[1 + x^(1/12)] - 2*Log[1 - x^(1/12) + x^(1/6)]}
{Sqrt[x]/(x^(1/4) + x^(1/3)), x, 16, -12*x^(1/12) + 6*x^(1/6) - 4*x^(1/4) + 3*x^(1/3) - (12*x^(5/12))/5 + 2*Sqrt[x] - (12*x^(7/12))/7 + (3*x^(2/3))/2 - (4*x^(3/4))/3 + (6*x^(5/6))/5 - (12*x^(11/12))/11 + x - (12*x^(13/12))/13 + (6*x^(7/6))/7 + 12*Log[1 + x^(1/12)]}
{Sqrt[x]/(-x^(-1/3) + Sqrt[x]), x, 12, 6*x^(1/6) + x - (3/5)*Sqrt[10 + 2*Sqrt[5]]*ArcTan[(1 - Sqrt[5] + 4*x^(1/6))/Sqrt[10 + 2*Sqrt[5]]] - (3/5)*Sqrt[10 - 2*Sqrt[5]]*ArcTan[(1 + Sqrt[5] + 4*x^(1/6))/Sqrt[10 - 2*Sqrt[5]]] + (6/5)*Log[1 - x^(1/6)] - (3/10)*(1 - Sqrt[5])*Log[2 + (1 - Sqrt[5])*x^(1/6) + 2*x^(1/3)] - (3/10)*(1 + Sqrt[5])*Log[2 + (1 + Sqrt[5])*x^(1/6) + 2*x^(1/3)], 6*x^(1/6) + x - (3/5)*Sqrt[2*(5 + Sqrt[5])]*ArcTan[(1 - Sqrt[5] + 4*x^(1/6))/Sqrt[2*(5 + Sqrt[5])]] + (3/5)*(1 - Sqrt[5])*Sqrt[(1/2)*(5 + Sqrt[5])]*ArcTan[(1 + Sqrt[5] + 4*x^(1/6))/Sqrt[2*(5 - Sqrt[5])]] + (6/5)*Log[1 - x^(1/6)] - (3/10)*(1 - Sqrt[5])*Log[2 + (1 - Sqrt[5])*x^(1/6) + 2*x^(1/3)] - (3/10)*(1 + Sqrt[5])*Log[2 + (1 + Sqrt[5])*x^(1/6) + 2*x^(1/3)]}


{(-x + x^3)/(6 + 2*x), x, 3, 4*x - (3*x^2)/4 + x^3/6 - 12*Log[3 + x]}
{(x + x^3)/(-1 + x), x, 3, 2*x + x^2/2 + x^3/3 + 2*Log[1 - x]}
{(-x + 4*x^3)/(5 + x^2)^2, x, 4, 21/(2*(5 + x^2)) + 2*Log[5 + x^2]}
{(-x^2 + 2*x^4)/(1 + 2*x^2), x, 4, -x + x^3/3 + ArcTan[Sqrt[2]*x]/Sqrt[2]}
{(x^3 + x^4)/(1 + x^2), x, 6, -x + x^2/2 + x^3/3 + ArcTan[x] - (1/2)*Log[1 + x^2]}

{(-2 + 4*x)/(-x + x^3), x, 6, Log[1 - x] + 2*Log[x] - 3*Log[1 + x]}
{(4 + x)/(4*x + x^3), x, 6, (1/2)*ArcTan[x/2] + Log[x] - (1/2)*Log[4 + x^2]}

{(-x + 2*x^3)/(1 - x^2 + x^4), x, 3, Log[1 - x^2 + x^4]/2}

{(-3 + x)/(2*x + 3*x^2 + x^3), x, 6, -((3*Log[x])/2) + 4*Log[1 + x] - (5/2)*Log[2 + x]}
{(2 + 4*x)/(x^2 + 2*x^3 + x^4), x, 3, -(2/(x*(1 + x)))}
{(1 + x)/(-6*x + x^2 + x^3), x, 6, (3/10)*Log[2 - x] - Log[x]/6 - (2/15)*Log[3 + x]}

{(4*x^2 + x^3)/(x + x^3), x, 6, x - ArcTan[x] + 2*Log[1 + x^2]}
{(x + 2*x^3)/(x^2 + x^4)^3, x, 2, -(1/(4*x^4*(1 + x^2)^2))}
{(a*x^2 + b*x^3)/(c*x^2 + d*x^3), x, 3, (b*x)/d - ((b*c - a*d)*Log[c + d*x])/d^2}
{(x + x^2)/(-2*x - x^2 + x^3), x, 3, Log[2 - x]}


(* ::Section::Closed:: *)
(*Integrands of the form x^m (a+b (c+d x)^2)^p*)


{x^3/(c + (a + b*x)^2), x, 6, -((2*a*x)/b^3) + x^2/(2*b^2) - (a*(a^2 - 3*c)*ArcTan[(a + b*x)/Sqrt[c]])/(b^4*Sqrt[c]) + ((3*a^2 - c)*Log[a^2 + c + 2*a*b*x + b^2*x^2])/(2*b^4)}
{x^2/(c + (a + b*x)^2), x, 5, x/b^2 + ((a^2 - c)*ArcTan[(a + b*x)/Sqrt[c]])/(b^3*Sqrt[c]) - (a*Log[a^2 + c + 2*a*b*x + b^2*x^2])/b^3}
{x^1/(c + (a + b*x)^2), x, 4, -((a*ArcTan[(a + b*x)/Sqrt[c]])/(b^2*Sqrt[c])) + Log[a^2 + c + 2*a*b*x + b^2*x^2]/(2*b^2)}
{x^0/(c + (a + b*x)^2), x, 2, ArcTan[(a + b*x)/Sqrt[c]]/(b*Sqrt[c])}
{1/(x^1*(c + (a + b*x)^2)), x, 6, -((a*ArcTan[(a + b*x)/Sqrt[c]])/(Sqrt[c]*(a^2 + c))) + Log[x]/(a^2 + c) - Log[a^2 + c + 2*a*b*x + b^2*x^2]/(2*(a^2 + c))}
{1/(x^2*(c + (a + b*x)^2)), x, 7, -(1/((a^2 + c)*x)) + (b*(a^2 - c)*ArcTan[(a + b*x)/Sqrt[c]])/(Sqrt[c]*(a^2 + c)^2) - (2*a*b*Log[x])/(a^2 + c)^2 + (a*b*Log[a^2 + c + 2*a*b*x + b^2*x^2])/(a^2 + c)^2}
{1/(x^3*(c + (a + b*x)^2)), x, 8, -(1/(2*(a^2 + c)*x^2)) + (2*a*b)/((a^2 + c)^2*x) - (a*b^2*(a^2 - 3*c)*ArcTan[(a + b*x)/Sqrt[c]])/(Sqrt[c]*(a^2 + c)^3) + (b^2*(3*a^2 - c)*Log[x])/(a^2 + c)^3 - (b^2*(3*a^2 - c)*Log[a^2 + c + 2*a*b*x + b^2*x^2])/(2*(a^2 + c)^3)}


{1/(a + b*(c + d*x)^2), x, 2, ArcTan[(Sqrt[b]*(c + d*x))/Sqrt[a]]/(Sqrt[a]*Sqrt[b]*d)}
{1/(a + b*(c + d*x)^2)^2, x, 3, (c + d*x)/(2*a*d*(a + b*(c + d*x)^2)) + ArcTan[(Sqrt[b]*(c + d*x))/Sqrt[a]]/(2*a^(3/2)*Sqrt[b]*d)}
{1/(a + b*(c + d*x)^2)^3, x, 4, (c + d*x)/(4*a*d*(a + b*(c + d*x)^2)^2) + (3*(c + d*x))/(8*a^2*d*(a + b*(c + d*x)^2)) + (3*ArcTan[(Sqrt[b]*(c + d*x))/Sqrt[a]])/(8*a^(5/2)*Sqrt[b]*d)}
{1/(Sqrt[-a] + b*(c + d*x)^2), x, 2, ArcTan[(Sqrt[b]*(c + d*x))/(-a)^(1/4)]/((-a)^(1/4)*d*Sqrt[b])}

{1/(1 + (c + d*x)^2), x, 2, ArcTan[c + d*x]/d}
{1/(1 + (c + d*x)^2)^2, x, 3, (c + d*x)/(2*d*(1 + (c + d*x)^2)) + ArcTan[c + d*x]/(2*d)}
{1/(1 + (c + d*x)^2)^3, x, 4, (c + d*x)/(4*d*(1 + (c + d*x)^2)^2) + (3*(c + d*x))/(8*d*(1 + (c + d*x)^2)) + (3*ArcTan[c + d*x])/(8*d)}

{1/(1 - (c + d*x)^2), x, 2, ArcTanh[c + d*x]/d}
{1/(1 - (c + d*x)^2)^2, x, 3, (c + d*x)/(2*d*(1 - (c + d*x)^2)) + ArcTanh[c + d*x]/(2*d)}
{1/(1 - (c + d*x)^2)^3, x, 4, (c + d*x)/(4*d*(1 - (c + d*x)^2)^2) + (3*(c + d*x))/(8*d*(1 - (c + d*x)^2)) + (3*ArcTanh[c + d*x])/(8*d)}

{1/(1 - (1 + x)^2), x, 2, ArcTanh[1 + x]}
{1/(1 - (1 + x)^2)^2, x, 3, (1 + x)/(2*(1 - (1 + x)^2)) + (1/2)*ArcTanh[1 + x]}
{1/(1 - (1 + x)^2)^3, x, 4, (1 + x)/(4*(1 - (1 + x)^2)^2) + (3*(1 + x))/(8*(1 - (1 + x)^2)) + (3/8)*ArcTanh[1 + x]}


{(1 + (a + b*x)^2)^2/x, x, 3, 4*a*(1 + a^2)*b*x + (1 + 3*a^2)*b^2*x^2 + (4/3)*a*b^3*x^3 + (b^4*x^4)/4 + (1 + a^2)^2*Log[x]}
{x^2/(1 + (-1 + x)^2), x, 3, x + Log[2 - 2*x + x^2]}


{x^2/Sqrt[1 - (1 + x)^2], x, 4, (3/2)*Sqrt[-2*x - x^2] - (1/2)*x*Sqrt[-2*x - x^2] + (3/2)*ArcSin[1 + x]}
{x^2/Sqrt[1 - (a + b*x)^2], x, 4, (3*a*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(2*b^3) - (x*Sqrt[1 - a^2 - 2*a*b*x - b^2*x^2])/(2*b^2) + ((1 + 2*a^2)*ArcSin[a + b*x])/(2*b^3)}
{x^2/Sqrt[1 + (a + b*x)^2], x, 4, -((3*a*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(2*b^3)) + (x*Sqrt[1 + a^2 + 2*a*b*x + b^2*x^2])/(2*b^2) - ((1 - 2*a^2)*ArcSinh[a + b*x])/(2*b^3)}


(* ::Section::Closed:: *)
(*Miscellaneous integrands requiring normalization*)


{Sqrt[(1 + x)/x], x, 4, Sqrt[1 + 1/x]*x + ArcTanh[Sqrt[1 + 1/x]]}
{Sqrt[(1 - x)/x], x, 4, Sqrt[-1 + 1/x]*x - ArcTan[Sqrt[-1 + 1/x]]}
{Sqrt[(-1 + x)/x], x, 4, Sqrt[-1 + x]*Sqrt[x] - ArcSinh[Sqrt[-1 + x]], Sqrt[1 - 1/x]*x - ArcTanh[Sqrt[1 - 1/x]]}
{Sqrt[(1 + x)/x]/x, x, 4, -2*Sqrt[1 + 1/x] + 2*ArcTanh[Sqrt[1 + 1/x]]}

{1/Sqrt[(-1 - x)/x], x, 4, (-Sqrt[-1 - 1/x])*x + ArcTan[Sqrt[-1 - 1/x]]}

{Sqrt[(4 - x)*x], x, 4, -Sqrt[4*x - x^2] + (1/2)*x*Sqrt[4*x - x^2] - 2*ArcSin[1 - x/2]}
{1/Sqrt[(1 - x)*x], x, 2, -ArcSin[1 - 2*x]}

{x/(x*(2 + x))^(3/2), x, 2, x/Sqrt[2*x + x^2]}


{1/(1 + Sqrt[5] - x^2 + Sqrt[5]*x^2), x, 2, (1/2)*ArcTan[Sqrt[(1/2)*(3 - Sqrt[5])]*x]}


{1/(b*x + c*(d + e*x)^2), x, 2, -((2*ArcTanh[(b + 2*c*d*e + 2*c*e^2*x)/(Sqrt[b]*Sqrt[b + 4*c*d*e])])/(Sqrt[b]*Sqrt[b + 4*c*d*e]))}
{1/(a + b*x + c*(d + e*x)^2), x, 2, -((2*ArcTanh[(b + 2*c*d*e + 2*c*e^2*x)/Sqrt[b^2 + 4*b*c*d*e - 4*a*c*e^2]])/Sqrt[b^2 + 4*b*c*d*e - 4*a*c*e^2])}


{Sqrt[(b - x)*(-a + x)], x, 3, (-(1/4))*(a + b - 2*x)*Sqrt[(-a)*b + (a + b)*x - x^2] - (1/8)*(a - b)^2*ArcTan[(a + b - 2*x)/(2*Sqrt[(-a)*b + (a + b)*x - x^2])]}
{1/Sqrt[(b - x)*(-a + x)], x, 2, -ArcTan[(a + b - 2*x)/(2*Sqrt[(-a)*b + (a + b)*x - x^2])]}


{Sqrt[(1 - x^2)*(3 + x^2)], x, 6, (1/3)*x*Sqrt[3 - 2*x^2 - x^4] - (2*EllipticE[ArcSin[x], -(1/3)])/Sqrt[3] + (4*EllipticF[ArcSin[x], -(1/3)])/Sqrt[3]}
{1/Sqrt[(1 - x^2)*(3 + x^2)], x, 3, EllipticF[ArcSin[x], -(1/3)]/Sqrt[3]}


{x^2/(1 + (-1 + x^2)^2), x, 6, (-(1/2))*Sqrt[(1/2)*(1 + Sqrt[2])]*ArcTan[(Sqrt[2*(1 + Sqrt[2])] - 2*x)/Sqrt[2*(-1 + Sqrt[2])]] + (1/2)*Sqrt[(1/2)*(1 + Sqrt[2])]*ArcTan[(Sqrt[2*(1 + Sqrt[2])] + 2*x)/Sqrt[2*(-1 + Sqrt[2])]] - ArcTanh[(Sqrt[2*(1 + Sqrt[2])]*x)/(Sqrt[2] + x^2)]/(2*Sqrt[2*(1 + Sqrt[2])])}


(* Integrands equivalent to expressions of the form 1/Sqrt[a*x + b*x^2] *)
{1/Sqrt[a*x + b*x^2], x, 1, (2*ArcTanh[(Sqrt[b]*x)/Sqrt[a*x + b*x^2]])/Sqrt[b]}
{1/Sqrt[x*(a + b*x)], x, 2, (2*ArcTanh[(Sqrt[b]*x)/Sqrt[a*x + b*x^2]])/Sqrt[b]}
{1/Sqrt[x^2*(b + a/x)], x, 2, (2*ArcTanh[(Sqrt[b]*x)/Sqrt[a*x + b*x^2]])/Sqrt[b]}
{1/Sqrt[x^3*(b/x + a/x^2)], x, 2, (2*ArcTanh[(Sqrt[b]*x)/Sqrt[a*x + b*x^2]])/Sqrt[b]}
{1/Sqrt[(a*x^2 + b*x^3)/x], x, 2, (2*ArcTanh[(Sqrt[b]*x)/Sqrt[a*x + b*x^2]])/Sqrt[b]}
{1/Sqrt[(a*x^3 + b*x^4)/x^2], x, 2, (2*ArcTanh[(Sqrt[b]*x)/Sqrt[a*x + b*x^2]])/Sqrt[b]}


(* Integrands equivalent to expressions of the form 1/Sqrt[a*c*x + b*c*x^2] *)
{1/Sqrt[a*c*x + b*c*x^2], x, 1, (2*ArcTanh[(Sqrt[b]*Sqrt[c]*x)/Sqrt[a*c*x + b*c*x^2]])/(Sqrt[b]*Sqrt[c])}
{1/Sqrt[c*(a*x + b*x^2)], x, 2, (2*ArcTanh[(Sqrt[b]*Sqrt[c]*x)/Sqrt[a*c*x + b*c*x^2]])/(Sqrt[b]*Sqrt[c])}
{1/Sqrt[c*x*(a + b*x)], x, 2, (2*ArcTanh[(Sqrt[b]*Sqrt[c]*x)/Sqrt[a*c*x + b*c*x^2]])/(Sqrt[b]*Sqrt[c])}
{1/Sqrt[c*x^2*(b + a/x)], x, 2, (2*ArcTanh[(Sqrt[b]*Sqrt[c]*x)/Sqrt[a*c*x + b*c*x^2]])/(Sqrt[b]*Sqrt[c])}
