(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Inverse Hyperbolic Secants*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcSech[a x]^n*)


{x^7*ArcSech[a*x], x, 9, -((Sqrt[(1 - a*x)/(1 + a*x)]*(1 - (1 - a*x)/(1 + a*x))^6)/(28*a^8*(1 + (1 - a*x)/(1 + a*x))^7)) - (3*Sqrt[(1 - a*x)/(1 + a*x)]*(1 - (1 - a*x)/(1 + a*x))^4)/(70*a^8*(1 + (1 - a*x)/(1 + a*x))^5) - (2*Sqrt[(1 - a*x)/(1 + a*x)]*(1 - (1 - a*x)/(1 + a*x))^2)/(35*a^8*(1 + (1 - a*x)/(1 + a*x))^3) - (4*Sqrt[(1 - a*x)/(1 + a*x)])/(35*a^8*(1 + (1 - a*x)/(1 + a*x))) + (1/8)*x^8*ArcSech[a*x]}
{x^6*ArcSech[a*x], x, 9, -((Sqrt[(1 - a*x)/(1 + a*x)]*(1 - (1 - a*x)/(1 + a*x))^5)/(21*a^7*(1 + (1 - a*x)/(1 + a*x))^6)) - (5*Sqrt[(1 - a*x)/(1 + a*x)]*(1 - (1 - a*x)/(1 + a*x))^3)/(84*a^7*(1 + (1 - a*x)/(1 + a*x))^4) - (5*Sqrt[(1 - a*x)/(1 + a*x)]*(1 - (1 - a*x)/(1 + a*x)))/(56*a^7*(1 + (1 - a*x)/(1 + a*x))^2) + (1/7)*x^7*ArcSech[a*x] - (5*ArcTan[Sqrt[(1 - a*x)/(1 + a*x)]])/(56*a^7)}
{x^5*ArcSech[a*x], x, 7, -((Sqrt[(1 - a*x)/(1 + a*x)]*(1 - (1 - a*x)/(1 + a*x))^4)/(15*a^6*(1 + (1 - a*x)/(1 + a*x))^5)) - (4*Sqrt[(1 - a*x)/(1 + a*x)]*(1 - (1 - a*x)/(1 + a*x))^2)/(45*a^6*(1 + (1 - a*x)/(1 + a*x))^3) - (8*Sqrt[(1 - a*x)/(1 + a*x)])/(45*a^6*(1 + (1 - a*x)/(1 + a*x))) + (1/6)*x^6*ArcSech[a*x]}
{x^4*ArcSech[a*x], x, 7, -((Sqrt[(1 - a*x)/(1 + a*x)]*(1 - (1 - a*x)/(1 + a*x))^3)/(10*a^5*(1 + (1 - a*x)/(1 + a*x))^4)) - (3*Sqrt[(1 - a*x)/(1 + a*x)]*(1 - (1 - a*x)/(1 + a*x)))/(20*a^5*(1 + (1 - a*x)/(1 + a*x))^2) + (1/5)*x^5*ArcSech[a*x] - (3*ArcTan[Sqrt[(1 - a*x)/(1 + a*x)]])/(20*a^5)}
{x^3*ArcSech[a*x], x, 5, -((Sqrt[(1 - a*x)/(1 + a*x)]*(1 - (1 - a*x)/(1 + a*x))^2)/(6*a^4*(1 + (1 - a*x)/(1 + a*x))^3)) - Sqrt[(1 - a*x)/(1 + a*x)]/(3*a^4*(1 + (1 - a*x)/(1 + a*x))) + (1/4)*x^4*ArcSech[a*x]}
{x^2*ArcSech[a*x], x, 5, -((Sqrt[(1 - a*x)/(1 + a*x)]*(1 - (1 - a*x)/(1 + a*x)))/(3*a^3*(1 + (1 - a*x)/(1 + a*x))^2)) + (1/3)*x^3*ArcSech[a*x] - ArcTan[Sqrt[(1 - a*x)/(1 + a*x)]]/(3*a^3)}
{x^1*ArcSech[a*x], x, 3, -(Sqrt[(1 - a*x)/(1 + a*x)]/(a^2*(1 + (1 - a*x)/(1 + a*x)))) + (1/2)*x^2*ArcSech[a*x]}
{x^0*ArcSech[a*x], x, 3, x*ArcSech[a*x] - (2*ArcTan[Sqrt[(1 - a*x)/(1 + a*x)]])/a}
{ArcSech[a*x]/x^1, x, 1, (-(1/2))*ArcSech[a*x]^2 - ArcSech[a*x]*Log[(2*(1 - Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x)))/(a^2*x^2)] + (1/2)*PolyLog[2, 1 - (2*(1 - Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x)))/(a^2*x^2)]}
{ArcSech[a*x]/x^2, x, 3, (2*a*Sqrt[(1 - a*x)/(1 + a*x)])/(1 - (1 - a*x)/(1 + a*x)) - ArcSech[a*x]/x}
{ArcSech[a*x]/x^3, x, 5, (a^2*Sqrt[(1 - a*x)/(1 + a*x)]*(1 + (1 - a*x)/(1 + a*x)))/(2*(1 - (1 - a*x)/(1 + a*x))^2) - ArcSech[a*x]/(2*x^2) + (1/2)*a^2*ArcTanh[Sqrt[(1 - a*x)/(1 + a*x)]]}
{ArcSech[a*x]/x^4, x, 5, (4*a^3*Sqrt[(1 - a*x)/(1 + a*x)])/(9*(1 - (1 - a*x)/(1 + a*x))) + (2*a^3*Sqrt[(1 - a*x)/(1 + a*x)]*(1 + (1 - a*x)/(1 + a*x))^2)/(9*(1 - (1 - a*x)/(1 + a*x))^3) - ArcSech[a*x]/(3*x^3)}
{ArcSech[a*x]/x^5, x, 7, (3*a^4*Sqrt[(1 - a*x)/(1 + a*x)]*(1 + (1 - a*x)/(1 + a*x)))/(16*(1 - (1 - a*x)/(1 + a*x))^2) + (a^4*Sqrt[(1 - a*x)/(1 + a*x)]*(1 + (1 - a*x)/(1 + a*x))^3)/(8*(1 - (1 - a*x)/(1 + a*x))^4) - ArcSech[a*x]/(4*x^4) + (3/16)*a^4*ArcTanh[Sqrt[(1 - a*x)/(1 + a*x)]]}
{ArcSech[a*x]/x^6, x, 7, (16*a^5*Sqrt[(1 - a*x)/(1 + a*x)])/(75*(1 - (1 - a*x)/(1 + a*x))) + (8*a^5*Sqrt[(1 - a*x)/(1 + a*x)]*(1 + (1 - a*x)/(1 + a*x))^2)/(75*(1 - (1 - a*x)/(1 + a*x))^3) + (2*a^5*Sqrt[(1 - a*x)/(1 + a*x)]*(1 + (1 - a*x)/(1 + a*x))^4)/(25*(1 - (1 - a*x)/(1 + a*x))^5) - ArcSech[a*x]/(5*x^5)}
{ArcSech[a*x]/x^7, x, 9, (5*a^6*Sqrt[(1 - a*x)/(1 + a*x)]*(1 + (1 - a*x)/(1 + a*x)))/(48*(1 - (1 - a*x)/(1 + a*x))^2) + (5*a^6*Sqrt[(1 - a*x)/(1 + a*x)]*(1 + (1 - a*x)/(1 + a*x))^3)/(72*(1 - (1 - a*x)/(1 + a*x))^4) + (a^6*Sqrt[(1 - a*x)/(1 + a*x)]*(1 + (1 - a*x)/(1 + a*x))^5)/(18*(1 - (1 - a*x)/(1 + a*x))^6) - ArcSech[a*x]/(6*x^6) + (5/48)*a^6*ArcTanh[Sqrt[(1 - a*x)/(1 + a*x)]]}
{ArcSech[a*x]/x^8, x, 9, (32*a^7*Sqrt[(1 - a*x)/(1 + a*x)])/(245*(1 - (1 - a*x)/(1 + a*x))) + (16*a^7*Sqrt[(1 - a*x)/(1 + a*x)]*(1 + (1 - a*x)/(1 + a*x))^2)/(245*(1 - (1 - a*x)/(1 + a*x))^3) + (12*a^7*Sqrt[(1 - a*x)/(1 + a*x)]*(1 + (1 - a*x)/(1 + a*x))^4)/(245*(1 - (1 - a*x)/(1 + a*x))^5) + (2*a^7*Sqrt[(1 - a*x)/(1 + a*x)]*(1 + (1 - a*x)/(1 + a*x))^6)/(49*(1 - (1 - a*x)/(1 + a*x))^7) - ArcSech[a*x]/(7*x^7)}


{x^4*ArcSech[a*x]^2, x, 7, -((3*x)/(20*a^4)) - x^3/(30*a^2) - (3*x*Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x)*ArcSech[a*x])/(20*a^4) - (x^3*Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x)*ArcSech[a*x])/(10*a^2) + (1/5)*x^5*ArcSech[a*x]^2 - (3*ArcSech[a*x]*ArcTan[E^ArcSech[a*x]])/(10*a^5) + (3*I*PolyLog[2, (-I)*E^ArcSech[a*x]])/(20*a^5) - (3*I*PolyLog[2, I*E^ArcSech[a*x]])/(20*a^5)}
{x^3*ArcSech[a*x]^2, x, 5, -(x^2/(12*a^2)) - (Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x)*ArcSech[a*x])/(3*a^4) - (x^2*Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x)*ArcSech[a*x])/(6*a^2) + (1/4)*x^4*ArcSech[a*x]^2 + Log[1/x]/(3*a^4)}
{x^2*ArcSech[a*x]^2, x, 6, -(x/(3*a^2)) - (x*Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x)*ArcSech[a*x])/(3*a^2) + (1/3)*x^3*ArcSech[a*x]^2 - (2*ArcSech[a*x]*ArcTan[E^ArcSech[a*x]])/(3*a^3) + (I*PolyLog[2, (-I)*E^ArcSech[a*x]])/(3*a^3) - (I*PolyLog[2, I*E^ArcSech[a*x]])/(3*a^3)}
{x^1*ArcSech[a*x]^2, x, 4, -((Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x)*ArcSech[a*x])/a^2) + (1/2)*x^2*ArcSech[a*x]^2 + Log[1/x]/a^2}
{x^0*ArcSech[a*x]^2, x, 5, x*ArcSech[a*x]^2 - (4*ArcSech[a*x]*ArcTan[E^ArcSech[a*x]])/a + (2*I*PolyLog[2, (-I)*E^ArcSech[a*x]])/a - (2*I*PolyLog[2, I*E^ArcSech[a*x]])/a}
{ArcSech[a*x]^2/x^1, x, 6, (1/3)*ArcSech[a*x]^3 - ArcSech[a*x]^2*Log[1 + E^(2*ArcSech[a*x])] - ArcSech[a*x]*PolyLog[2, -E^(2*ArcSech[a*x])] + (1/2)*PolyLog[3, -E^(2*ArcSech[a*x])]}
{ArcSech[a*x]^2/x^2, x, 4, -(2/x) + (2*Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x)*ArcSech[a*x])/x - ArcSech[a*x]^2/x}
{ArcSech[a*x]^2/x^3, x, 4, -(((1 - a*x)*(1 + a*x))/(4*x^2)) + (Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x)*ArcSech[a*x])/(2*x^2) - (1/4)*a^2*ArcSech[a*x]^2 - ((1 - a*x)*(1 + a*x)*ArcSech[a*x]^2)/(2*x^2)}
{ArcSech[a*x]^2/x^4, x, 5, -(2/(27*x^3)) - (4*a^2)/(9*x) + (2*Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x)*ArcSech[a*x])/(9*x^3) + (4*a^2*Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x)*ArcSech[a*x])/(9*x) - ArcSech[a*x]^2/(3*x^3)}


{x^4*ArcSech[a*x]^3, x, 12, (x*Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x))/(20*a^4) - (9*x*ArcSech[a*x])/(20*a^4) - (x^3*ArcSech[a*x])/(10*a^2) - (9*x*Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x)*ArcSech[a*x]^2)/(40*a^4) - (3*x^3*Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x)*ArcSech[a*x]^2)/(20*a^2) + (1/5)*x^5*ArcSech[a*x]^3 - (9*ArcSech[a*x]^2*ArcTan[E^ArcSech[a*x]])/(20*a^5) + ArcTan[(Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x))/(a*x)]/(2*a^5) + (9*I*ArcSech[a*x]*PolyLog[2, (-I)*E^ArcSech[a*x]])/(20*a^5) - (9*I*ArcSech[a*x]*PolyLog[2, I*E^ArcSech[a*x]])/(20*a^5) - (9*I*PolyLog[3, (-I)*E^ArcSech[a*x]])/(20*a^5) + (9*I*PolyLog[3, I*E^ArcSech[a*x]])/(20*a^5)}
{x^3*ArcSech[a*x]^3, x, 9, (Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x))/(4*a^4) - (x^2*ArcSech[a*x])/(4*a^2) - ArcSech[a*x]^2/(2*a^4) - (Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x)*ArcSech[a*x]^2)/(2*a^4) - (x^2*Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x)*ArcSech[a*x]^2)/(4*a^2) + (1/4)*x^4*ArcSech[a*x]^3 + (ArcSech[a*x]*Log[1 + E^(2*ArcSech[a*x])])/a^4 + PolyLog[2, -E^(2*ArcSech[a*x])]/(2*a^4)}
{x^2*ArcSech[a*x]^3, x, 9, -((x*ArcSech[a*x])/a^2) - (x*Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x)*ArcSech[a*x]^2)/(2*a^2) + (1/3)*x^3*ArcSech[a*x]^3 - (ArcSech[a*x]^2*ArcTan[E^ArcSech[a*x]])/a^3 + ArcTan[(Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x))/(a*x)]/a^3 + (I*ArcSech[a*x]*PolyLog[2, (-I)*E^ArcSech[a*x]])/a^3 - (I*ArcSech[a*x]*PolyLog[2, I*E^ArcSech[a*x]])/a^3 - (I*PolyLog[3, (-I)*E^ArcSech[a*x]])/a^3 + (I*PolyLog[3, I*E^ArcSech[a*x]])/a^3}
{x^1*ArcSech[a*x]^3, x, 7, -((3*ArcSech[a*x]^2)/(2*a^2)) - (3*Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x)*ArcSech[a*x]^2)/(2*a^2) + (1/2)*x^2*ArcSech[a*x]^3 + (3*ArcSech[a*x]*Log[1 + E^(2*ArcSech[a*x])])/a^2 + (3*PolyLog[2, -E^(2*ArcSech[a*x])])/(2*a^2)}
{x^0*ArcSech[a*x]^3, x, 7, x*ArcSech[a*x]^3 - (6*ArcSech[a*x]^2*ArcTan[E^ArcSech[a*x]])/a + (6*I*ArcSech[a*x]*PolyLog[2, (-I)*E^ArcSech[a*x]])/a - (6*I*ArcSech[a*x]*PolyLog[2, I*E^ArcSech[a*x]])/a - (6*I*PolyLog[3, (-I)*E^ArcSech[a*x]])/a + (6*I*PolyLog[3, I*E^ArcSech[a*x]])/a}
{ArcSech[a*x]^3/x^1, x, 7, (1/4)*ArcSech[a*x]^4 - ArcSech[a*x]^3*Log[1 + E^(2*ArcSech[a*x])] - (3/2)*ArcSech[a*x]^2*PolyLog[2, -E^(2*ArcSech[a*x])] + (3/2)*ArcSech[a*x]*PolyLog[3, -E^(2*ArcSech[a*x])] - (3/4)*PolyLog[4, -E^(2*ArcSech[a*x])]}
{ArcSech[a*x]^3/x^2, x, 5, (6*Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x))/x - (6*ArcSech[a*x])/x + (3*Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x)*ArcSech[a*x]^2)/x - ArcSech[a*x]^3/x}
{ArcSech[a*x]^3/x^3, x, 5, (3*Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x))/(8*x^2) - (3/8)*a^2*ArcSech[a*x] - (3*(1 - a*x)*(1 + a*x)*ArcSech[a*x])/(4*x^2) + (3*Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x)*ArcSech[a*x]^2)/(4*x^2) - (1/4)*a^2*ArcSech[a*x]^3 - ((1 - a*x)*(1 + a*x)*ArcSech[a*x]^3)/(2*x^2)}
{ArcSech[a*x]^3/x^4, x, 8, (14*a^2*Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x))/(9*x) + (2*((1 - a*x)/(1 + a*x))^(3/2)*(1 + a*x)^3)/(27*x^3) - (2*ArcSech[a*x])/(9*x^3) - (4*a^2*ArcSech[a*x])/(3*x) + (Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x)*ArcSech[a*x]^2)/(3*x^3) + (2*a^2*Sqrt[(1 - a*x)/(1 + a*x)]*(1 + a*x)*ArcSech[a*x]^2)/(3*x) - ArcSech[a*x]^3/(3*x^3)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcSech[a+b x]^n*)


{x^2*ArcSech[a + b*x], x, 7, -((2*Sqrt[-((1 - 1/(a + b*x))/(1 + 1/(a + b*x)))])/(3*b^3*(1 - (1 - 1/(a + b*x))/(1 + 1/(a + b*x)))^2)) + ((1 + 6*a)*Sqrt[-((1 - 1/(a + b*x))/(1 + 1/(a + b*x)))])/(3*b^3*(1 - (1 - 1/(a + b*x))/(1 + 1/(a + b*x)))) + ((a^3 + b^3*x^3)*ArcSech[a + b*x])/(3*b^3) - ((1 + 6*a^2)*ArcTan[Sqrt[-((1 - 1/(a + b*x))/(1 + 1/(a + b*x)))]])/(3*b^3)}
{x^1*ArcSech[a + b*x], x, 6, -(Sqrt[-((1 - 1/(a + b*x))/(1 + 1/(a + b*x)))]/(b^2*(1 - (1 - 1/(a + b*x))/(1 + 1/(a + b*x))))) - ((a^2 - b^2*x^2)*ArcSech[a + b*x])/(2*b^2) + (2*a*ArcTan[Sqrt[-((1 - 1/(a + b*x))/(1 + 1/(a + b*x)))]])/b^2}
{x^0*ArcSech[a + b*x], x, 3, ((a + b*x)*ArcSech[a + b*x])/b - (2*ArcTan[Sqrt[(1 - a - b*x)/(1 + a + b*x)]])/b}
{ArcSech[a + b*x]/x^1, x, 1, (-ArcSech[a + b*x])*Log[1 + E^(-2*ArcSech[a + b*x])] + ArcSech[a + b*x]*Log[1 - (1 - Sqrt[1 - a^2])/(E^ArcSech[a + b*x]*a)] + ArcSech[a + b*x]*Log[1 - (1 + Sqrt[1 - a^2])/(E^ArcSech[a + b*x]*a)] + (1/2)*PolyLog[2, -E^(-2*ArcSech[a + b*x])] - PolyLog[2, (1 - Sqrt[1 - a^2])/(E^ArcSech[a + b*x]*a)] - PolyLog[2, (1 + Sqrt[1 - a^2])/(E^ArcSech[a + b*x]*a)]}
{ArcSech[a + b*x]/x^2, x, 6, -(((b + a/x)*ArcSech[a + b*x])/a) + (2*b*ArcTanh[(Sqrt[1 + a]*Sqrt[-((1 - 1/(a + b*x))/(1 + 1/(a + b*x)))])/Sqrt[1 - a]])/(a*Sqrt[1 - a^2])}
{ArcSech[a + b*x]/x^3, x, 7, (b^2*Sqrt[-((1 - 1/(a + b*x))/(1 + 1/(a + b*x)))])/(a*(1 - a^2)*(1 - a + ((1 + a)*(1 - 1/(a + b*x)))/(1 + 1/(a + b*x)))) + ((b^2 - a^2/x^2)*ArcSech[a + b*x])/(2*a^2) - ((1 - 2*a^2)*b^2*ArcTanh[(Sqrt[1 + a]*Sqrt[-((1 - 1/(a + b*x))/(1 + 1/(a + b*x)))])/Sqrt[1 - a]])/(a^2*(1 - a^2)^(3/2))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcSech[a x^n]*)


{x^2*ArcSech[Sqrt[x]], x, 8, -((2*(1 - (1 - Sqrt[x])/(1 + Sqrt[x]))^4*Sqrt[(1 - Sqrt[x])/(1 + Sqrt[x])])/(15*(1 + (1 - Sqrt[x])/(1 + Sqrt[x]))^5)) - (8*(1 - (1 - Sqrt[x])/(1 + Sqrt[x]))^2*Sqrt[(1 - Sqrt[x])/(1 + Sqrt[x])])/(45*(1 + (1 - Sqrt[x])/(1 + Sqrt[x]))^3) - (16*Sqrt[(1 - Sqrt[x])/(1 + Sqrt[x])])/(45*(1 + (1 - Sqrt[x])/(1 + Sqrt[x]))) + (1/3)*x^3*ArcSech[Sqrt[x]]}
{x^1*ArcSech[Sqrt[x]], x, 6, -(((1 - (1 - Sqrt[x])/(1 + Sqrt[x]))^2*Sqrt[(1 - Sqrt[x])/(1 + Sqrt[x])])/(3*(1 + (1 - Sqrt[x])/(1 + Sqrt[x]))^3)) - (2*Sqrt[(1 - Sqrt[x])/(1 + Sqrt[x])])/(3*(1 + (1 - Sqrt[x])/(1 + Sqrt[x]))) + (1/2)*x^2*ArcSech[Sqrt[x]]}
{x^0*ArcSech[Sqrt[x]], x, 4, -((2*Sqrt[(1 - Sqrt[x])/(1 + Sqrt[x])])/(1 + (1 - Sqrt[x])/(1 + Sqrt[x]))) + x*ArcSech[Sqrt[x]]}
{ArcSech[Sqrt[x]]/x^1, x, 2, -ArcSech[Sqrt[x]]^2 - 2*ArcSech[Sqrt[x]]*Log[(2*(1 - Sqrt[(1 - Sqrt[x])/(1 + Sqrt[x])]*(1 + Sqrt[x])))/x] + PolyLog[2, 1 - (2*(1 - Sqrt[(1 - Sqrt[x])/(1 + Sqrt[x])]*(1 + Sqrt[x])))/x]}
{ArcSech[Sqrt[x]]/x^2, x, 6, ((1 + (1 - Sqrt[x])/(1 + Sqrt[x]))*Sqrt[(1 - Sqrt[x])/(1 + Sqrt[x])])/(1 - (1 - Sqrt[x])/(1 + Sqrt[x]))^2 - ArcSech[Sqrt[x]]/x + ArcTanh[Sqrt[(1 - Sqrt[x])/(1 + Sqrt[x])]]}
{ArcSech[Sqrt[x]]/x^3, x, 8, (3*(1 + (1 - Sqrt[x])/(1 + Sqrt[x]))*Sqrt[(1 - Sqrt[x])/(1 + Sqrt[x])])/(8*(1 - (1 - Sqrt[x])/(1 + Sqrt[x]))^2) + ((1 + (1 - Sqrt[x])/(1 + Sqrt[x]))^3*Sqrt[(1 - Sqrt[x])/(1 + Sqrt[x])])/(4*(1 - (1 - Sqrt[x])/(1 + Sqrt[x]))^4) - ArcSech[Sqrt[x]]/(2*x^2) + (3/8)*ArcTanh[Sqrt[(1 - Sqrt[x])/(1 + Sqrt[x])]]}


(* ::Subsection::Closed:: *)
(*Integrands involving inverse hyperbolic functions of exponentials*)


{ArcSech[c*E^(a + b*x)], x, 2, -(ArcSech[c*E^(a + b*x)]^2/(2*b)) - (ArcSech[c*E^(a + b*x)]*Log[(2*E^(-2*a - 2*b*x)*(1 - Sqrt[(1 - c*E^(a + b*x))/(1 + c*E^(a + b*x))]*(1 + c*E^(a + b*x))))/c^2])/b + PolyLog[2, 1 - (2*E^(-2*a - 2*b*x)*(1 - Sqrt[(1 - c*E^(a + b*x))/(1 + c*E^(a + b*x))]*(1 + c*E^(a + b*x))))/c^2]/(2*b)}


(* ::Subsection::Closed:: *)
(*Integrands involving exponentials of arcsecants*)


{E^ArcSech[x]*x^2, x, 9, 2/(1 + (1 - x)/(1 + x))^3 - (8*((1 - x)/(1 + x))^(3/2))/(3*(1 + (1 - x)/(1 + x))^3) - (2*(1 - x)^2)/((1 + x)^2*(1 + (1 - x)/(1 + x))^3) - 2/(1 + (1 - x)/(1 + x))^2}
{E^ArcSech[x]*x^1, x, 6, (1 + Sqrt[(1 - x)/(1 + x)])^2/(1 + (1 - x)/(1 + x))^2 + (1 - Sqrt[(1 - x)/(1 + x)])/(1 + (1 - x)/(1 + x)) - ArcTan[Sqrt[(1 - x)/(1 + x)]]}
{E^ArcSech[x]*x^0, x, 9, (2*Sqrt[(1 - x)/(1 + x)])/(1 + (1 - x)/(1 + x)) - 2*ArcTanh[Sqrt[(1 - x)/(1 + x)]] + Log[x]}
{E^ArcSech[x]/x^1, x, 4, -(2/(1 - Sqrt[(1 - x)/(1 + x)])) + 2*ArcTan[Sqrt[(1 - x)/(1 + x)]]}
{E^ArcSech[x]/x^2, x, 5, -(1/(1 - Sqrt[(1 - x)/(1 + x)])^2) + 1/(1 - Sqrt[(1 - x)/(1 + x)]) + ArcTanh[Sqrt[(1 - x)/(1 + x)]]}
{E^ArcSech[x]/x^3, x, 5, -(2/(3*(1 - Sqrt[(1 - x)/(1 + x)])^3)) + 1/(1 - Sqrt[(1 - x)/(1 + x)])^2 - 1/(2*(1 - Sqrt[(1 - x)/(1 + x)])) - 1/(2*(1 + Sqrt[(1 - x)/(1 + x)]))}


(* ::Subsection::Closed:: *)
(*Miscellaneous integrands involving inverse hyperbolic secants*)


{ArcSech[1/x], x, 2, -(Sqrt[-1 + x]*Sqrt[1 + x]) + x*ArcCosh[x]}


{ArcSech[a + b*x]/((a*d)/b + d*x), x, 3, -(ArcSech[b*(a/b + x)]^2/(2*d)) - (ArcSech[b*(a/b + x)]*Log[(2*(1 - Sqrt[(1 - b*(a/b + x))/(1 + b*(a/b + x))]*(1 + b*(a/b + x))))/(b^2*(a/b + x)^2)])/d + PolyLog[2, 1 - (2*(1 - Sqrt[(1 - b*(a/b + x))/(1 + b*(a/b + x))]*(1 + b*(a/b + x))))/(b^2*(a/b + x)^2)]/(2*d)}


{ArcSech[a*x^n]/x, x, 2, -(ArcSech[a*x^n]^2/(2*n)) - (ArcSech[a*x^n]*Log[(2*(1 - Sqrt[(1 - a*x^n)/(1 + a*x^n)]*(1 + a*x^n)))/(x^(2*n)*a^2)])/n + PolyLog[2, 1 - (2*(1 - Sqrt[(1 - a*x^n)/(1 + a*x^n)]*(1 + a*x^n)))/(x^(2*n)*a^2)]/(2*n)}

{ArcSech[a*x^5]/x, x, 2, (-(1/10))*ArcSech[a*x^5]^2 - (1/5)*ArcSech[a*x^5]*Log[(2*(1 - Sqrt[(1 - a*x^5)/(1 + a*x^5)]*(1 + a*x^5)))/(a^2*x^10)] + (1/10)*PolyLog[2, 1 - (2*(1 - Sqrt[(1 - a*x^5)/(1 + a*x^5)]*(1 + a*x^5)))/(a^2*x^10)]}


{x^3*ArcSech[a + b*x^4], x, 4, ((a + b*x^4)*ArcSech[a + b*x^4])/(4*b) - ArcTan[Sqrt[(1 - a - b*x^4)/(1 + a + b*x^4)]]/(2*b)}

{x^(n-1)*ArcSech[a + b*x^n], x, 4, ((a + b*x^n)*ArcSech[a + b*x^n])/(b*n) - (2*ArcTan[Sqrt[(1 - a - b*x^n)/(1 + a + b*x^n)]])/(b*n)}
