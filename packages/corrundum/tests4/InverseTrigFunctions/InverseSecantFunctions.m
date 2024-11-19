(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Inverse Secants*)


(* ::Section::Closed:: *)
(*Integrands of the form u ArcSec[a x^n]^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcSec[a x]^n*)


{x^m*ArcSec[a*x], x, 3, (a*Sqrt[1 - 1/(a^2*x^2)]*x^(2 + m))/(1 + m)^2 + (x^(1 + m)*ArcSec[a*x])/(1 + m) - (a*x^(2 + m)*Hypergeometric2F1[1/2, (1/2)*(-2 - m), -(m/2), 1/(a^2*x^2)])/(1 + m)^2}

{x^7*ArcSec[a*x], x, 6, -((2*Sqrt[1 - 1/(a^2*x^2)]*x)/(35*a^7)) - (Sqrt[1 - 1/(a^2*x^2)]*x^3)/(35*a^5) - (3*Sqrt[1 - 1/(a^2*x^2)]*x^5)/(140*a^3) - (Sqrt[1 - 1/(a^2*x^2)]*x^7)/(56*a) + (1/8)*x^8*ArcSec[a*x]}
{x^6*ArcSec[a*x], x, 7, -((5*Sqrt[1 - 1/(a^2*x^2)]*x^2)/(112*a^5)) - (5*Sqrt[1 - 1/(a^2*x^2)]*x^4)/(168*a^3) - (Sqrt[1 - 1/(a^2*x^2)]*x^6)/(42*a) + (1/7)*x^7*ArcSec[a*x] - (5*ArcTanh[Sqrt[1 - 1/(a^2*x^2)]])/(112*a^7)}
{x^5*ArcSec[a*x], x, 5, -((4*Sqrt[1 - 1/(a^2*x^2)]*x)/(45*a^5)) - (2*Sqrt[1 - 1/(a^2*x^2)]*x^3)/(45*a^3) - (Sqrt[1 - 1/(a^2*x^2)]*x^5)/(30*a) + (1/6)*x^6*ArcSec[a*x]}
{x^4*ArcSec[a*x], x, 6, -((3*Sqrt[1 - 1/(a^2*x^2)]*x^2)/(40*a^3)) - (Sqrt[1 - 1/(a^2*x^2)]*x^4)/(20*a) + (1/5)*x^5*ArcSec[a*x] - (3*ArcTanh[Sqrt[1 - 1/(a^2*x^2)]])/(40*a^5)}
{x^3*ArcSec[a*x], x, 4, -((Sqrt[1 - 1/(a^2*x^2)]*x)/(6*a^3)) - (Sqrt[1 - 1/(a^2*x^2)]*x^3)/(12*a) + (1/4)*x^4*ArcSec[a*x]}
{x^2*ArcSec[a*x], x, 4, -((Sqrt[1 - 1/(a^2*x^2)]*x^2)/(6*a)) + (1/3)*x^3*ArcSec[a*x] - ArcTanh[Sqrt[1 - 1/(a^2*x^2)]]/(6*a^3)}
{x^1*ArcSec[a*x], x, 2, -((Sqrt[1 - 1/(a^2*x^2)]*x)/(2*a)) + (1/2)*x^2*ArcSec[a*x]}
{x^0*ArcSec[a*x], x, 3, x*ArcSec[a*x] - ArcTanh[Sqrt[1 - 1/(a^2*x^2)]]/a}
{ArcSec[a*x]/x^1, x, 1, (1/2)*I*ArcSec[a*x]^2 - ArcSec[a*x]*Log[2/(1 - I*a*Sqrt[1 - 1/(a^2*x^2)]*x)] + (1/2)*I*PolyLog[2, 1 - 2/(1 - I*a*Sqrt[1 - 1/(a^2*x^2)]*x)]}
{ArcSec[a*x]/x^2, x, 2, a*Sqrt[1 - 1/(a^2*x^2)] - ArcSec[a*x]/x}
{ArcSec[a*x]/x^3, x, 4, (a*Sqrt[1 - 1/(a^2*x^2)])/(4*x) - ArcSec[a*x]/(2*x^2) - (1/4)*a^2*ArcSin[1/(a*x)]}
{ArcSec[a*x]/x^4, x, 4, (2/9)*a^3*Sqrt[1 - 1/(a^2*x^2)] + (a*Sqrt[1 - 1/(a^2*x^2)])/(9*x^2) - ArcSec[a*x]/(3*x^3)}
{ArcSec[a*x]/x^5, x, 5, (a*Sqrt[1 - 1/(a^2*x^2)])/(16*x^3) + (3*a^3*Sqrt[1 - 1/(a^2*x^2)])/(32*x) - ArcSec[a*x]/(4*x^4) - (3/32)*a^4*ArcSin[1/(a*x)]}
{ArcSec[a*x]/x^6, x, 5, (8/75)*a^5*Sqrt[1 - 1/(a^2*x^2)] + (a*Sqrt[1 - 1/(a^2*x^2)])/(25*x^4) + (4*a^3*Sqrt[1 - 1/(a^2*x^2)])/(75*x^2) - ArcSec[a*x]/(5*x^5)}
{ArcSec[a*x]/x^7, x, 6, (a*Sqrt[1 - 1/(a^2*x^2)])/(36*x^5) + (5*a^3*Sqrt[1 - 1/(a^2*x^2)])/(144*x^3) + (5*a^5*Sqrt[1 - 1/(a^2*x^2)])/(96*x) - ArcSec[a*x]/(6*x^6) - (5/96)*a^6*ArcSin[1/(a*x)]}
{ArcSec[a*x]/x^8, x, 6, (16/245)*a^7*Sqrt[1 - 1/(a^2*x^2)] + (a*Sqrt[1 - 1/(a^2*x^2)])/(49*x^6) + (6*a^3*Sqrt[1 - 1/(a^2*x^2)])/(245*x^4) + (8*a^5*Sqrt[1 - 1/(a^2*x^2)])/(245*x^2) - ArcSec[a*x]/(7*x^7)}
{ArcSec[a*x]/x^9, x, 7, (a*Sqrt[1 - 1/(a^2*x^2)])/(64*x^7) + (7*a^3*Sqrt[1 - 1/(a^2*x^2)])/(384*x^5) + (35*a^5*Sqrt[1 - 1/(a^2*x^2)])/(1536*x^3) + (35*a^7*Sqrt[1 - 1/(a^2*x^2)])/(1024*x) - ArcSec[a*x]/(8*x^8) - (35*a^8*ArcSin[1/(a*x)])/1024}


{x^m*ArcSec[a*x]^2, x, 0, Int[x^m*ArcSec[a*x]^2, x]}

{x^4*ArcSec[a*x]^2, x, 7, (3*x)/(20*a^4) + x^3/(30*a^2) - (3*Sqrt[1 - 1/(a^2*x^2)]*x^2*ArcSec[a*x])/(20*a^3) - (Sqrt[1 - 1/(a^2*x^2)]*x^4*ArcSec[a*x])/(10*a) + (1/5)*x^5*ArcSec[a*x]^2 + (3*I*ArcSec[a*x]*ArcTan[E^(I*ArcSec[a*x])])/(10*a^5) - (3*I*PolyLog[2, (-I)*E^(I*ArcSec[a*x])])/(20*a^5) + (3*I*PolyLog[2, I*E^(I*ArcSec[a*x])])/(20*a^5)}
{x^3*ArcSec[a*x]^2, x, 5, x^2/(12*a^2) - (Sqrt[1 - 1/(a^2*x^2)]*x*ArcSec[a*x])/(3*a^3) - (Sqrt[1 - 1/(a^2*x^2)]*x^3*ArcSec[a*x])/(6*a) + (1/4)*x^4*ArcSec[a*x]^2 - Log[1/x]/(3*a^4)}
{x^2*ArcSec[a*x]^2, x, 6, x/(3*a^2) - (Sqrt[1 - 1/(a^2*x^2)]*x^2*ArcSec[a*x])/(3*a) + (1/3)*x^3*ArcSec[a*x]^2 + (2*I*ArcSec[a*x]*ArcTan[E^(I*ArcSec[a*x])])/(3*a^3) - (I*PolyLog[2, (-I)*E^(I*ArcSec[a*x])])/(3*a^3) + (I*PolyLog[2, I*E^(I*ArcSec[a*x])])/(3*a^3)}
{x^1*ArcSec[a*x]^2, x, 4, -((Sqrt[1 - 1/(a^2*x^2)]*x*ArcSec[a*x])/a) + (1/2)*x^2*ArcSec[a*x]^2 - Log[1/x]/a^2}
{x^0*ArcSec[a*x]^2, x, 5, x*ArcSec[a*x]^2 + (4*I*ArcSec[a*x]*ArcTan[E^(I*ArcSec[a*x])])/a - (2*I*PolyLog[2, (-I)*E^(I*ArcSec[a*x])])/a + (2*I*PolyLog[2, I*E^(I*ArcSec[a*x])])/a}
{ArcSec[a*x]^2/x^1, x, 6, (1/3)*I*ArcSec[a*x]^3 - ArcSec[a*x]^2*Log[1 + E^(2*I*ArcSec[a*x])] + I*ArcSec[a*x]*PolyLog[2, -E^(2*I*ArcSec[a*x])] - (1/2)*PolyLog[3, -E^(2*I*ArcSec[a*x])]}
{ArcSec[a*x]^2/x^2, x, 4, 2/x + 2*a*Sqrt[1 - 1/(a^2*x^2)]*ArcSec[a*x] - ArcSec[a*x]^2/x}
{ArcSec[a*x]^2/x^3, x, 4, (1/4)*(-a^2 + 1/x^2) + (a*Sqrt[1 - 1/(a^2*x^2)]*ArcSec[a*x])/(2*x) - (1/4)*a^2*ArcSec[a*x]^2 + (1/2)*(a^2 - 1/x^2)*ArcSec[a*x]^2}
{ArcSec[a*x]^2/x^4, x, 5, 2/(27*x^3) + (4*a^2)/(9*x) + (4/9)*a^3*Sqrt[1 - 1/(a^2*x^2)]*ArcSec[a*x] + (2*a*Sqrt[1 - 1/(a^2*x^2)]*ArcSec[a*x])/(9*x^2) - ArcSec[a*x]^2/(3*x^3)}


{x^m*ArcSec[a*x]^3, x, 0, Int[x^m*ArcSec[a*x]^3, x]}

{x^4*ArcSec[a*x]^3, x, 12, -((Sqrt[1 - 1/(a^2*x^2)]*x^2)/(20*a^3)) + (9*x*ArcSec[a*x])/(20*a^4) + (x^3*ArcSec[a*x])/(10*a^2) - (9*Sqrt[1 - 1/(a^2*x^2)]*x^2*ArcSec[a*x]^2)/(40*a^3) - (3*Sqrt[1 - 1/(a^2*x^2)]*x^4*ArcSec[a*x]^2)/(20*a) + (1/5)*x^5*ArcSec[a*x]^3 + (9*I*ArcSec[a*x]^2*ArcTan[E^(I*ArcSec[a*x])])/(20*a^5) - ArcTanh[Sqrt[1 - 1/(a^2*x^2)]]/(2*a^5) - (9*I*ArcSec[a*x]*PolyLog[2, (-I)*E^(I*ArcSec[a*x])])/(20*a^5) + (9*I*ArcSec[a*x]*PolyLog[2, I*E^(I*ArcSec[a*x])])/(20*a^5) + (9*PolyLog[3, (-I)*E^(I*ArcSec[a*x])])/(20*a^5) - (9*PolyLog[3, I*E^(I*ArcSec[a*x])])/(20*a^5)}
{x^3*ArcSec[a*x]^3, x, 9, -((Sqrt[1 - 1/(a^2*x^2)]*x)/(4*a^3)) + (x^2*ArcSec[a*x])/(4*a^2) + (I*ArcSec[a*x]^2)/(2*a^4) - (Sqrt[1 - 1/(a^2*x^2)]*x*ArcSec[a*x]^2)/(2*a^3) - (Sqrt[1 - 1/(a^2*x^2)]*x^3*ArcSec[a*x]^2)/(4*a) + (1/4)*x^4*ArcSec[a*x]^3 - (ArcSec[a*x]*Log[1 + E^(2*I*ArcSec[a*x])])/a^4 + (I*PolyLog[2, -E^(2*I*ArcSec[a*x])])/(2*a^4)}
{x^2*ArcSec[a*x]^3, x, 9, (x*ArcSec[a*x])/a^2 - (Sqrt[1 - 1/(a^2*x^2)]*x^2*ArcSec[a*x]^2)/(2*a) + (1/3)*x^3*ArcSec[a*x]^3 + (I*ArcSec[a*x]^2*ArcTan[E^(I*ArcSec[a*x])])/a^3 - ArcTanh[Sqrt[1 - 1/(a^2*x^2)]]/a^3 - (I*ArcSec[a*x]*PolyLog[2, (-I)*E^(I*ArcSec[a*x])])/a^3 + (I*ArcSec[a*x]*PolyLog[2, I*E^(I*ArcSec[a*x])])/a^3 + PolyLog[3, (-I)*E^(I*ArcSec[a*x])]/a^3 - PolyLog[3, I*E^(I*ArcSec[a*x])]/a^3}
{x^1*ArcSec[a*x]^3, x, 7, (3*I*ArcSec[a*x]^2)/(2*a^2) - (3*Sqrt[1 - 1/(a^2*x^2)]*x*ArcSec[a*x]^2)/(2*a) + (1/2)*x^2*ArcSec[a*x]^3 - (3*ArcSec[a*x]*Log[1 + E^(2*I*ArcSec[a*x])])/a^2 + (3*I*PolyLog[2, -E^(2*I*ArcSec[a*x])])/(2*a^2)}
{x^0*ArcSec[a*x]^3, x, 7, x*ArcSec[a*x]^3 + (6*I*ArcSec[a*x]^2*ArcTan[E^(I*ArcSec[a*x])])/a - (6*I*ArcSec[a*x]*PolyLog[2, (-I)*E^(I*ArcSec[a*x])])/a + (6*I*ArcSec[a*x]*PolyLog[2, I*E^(I*ArcSec[a*x])])/a + (6*PolyLog[3, (-I)*E^(I*ArcSec[a*x])])/a - (6*PolyLog[3, I*E^(I*ArcSec[a*x])])/a}
{ArcSec[a*x]^3/x^1, x, 7, (1/4)*I*ArcSec[a*x]^4 - ArcSec[a*x]^3*Log[1 + E^(2*I*ArcSec[a*x])] + (3/2)*I*ArcSec[a*x]^2*PolyLog[2, -E^(2*I*ArcSec[a*x])] - (3/2)*ArcSec[a*x]*PolyLog[3, -E^(2*I*ArcSec[a*x])] - (3/4)*I*PolyLog[4, -E^(2*I*ArcSec[a*x])]}
{ArcSec[a*x]^3/x^2, x, 5, -6*a*Sqrt[1 - 1/(a^2*x^2)] + (6*ArcSec[a*x])/x + 3*a*Sqrt[1 - 1/(a^2*x^2)]*ArcSec[a*x]^2 - ArcSec[a*x]^3/x}
{ArcSec[a*x]^3/x^3, x, 5, -((3*a*Sqrt[1 - 1/(a^2*x^2)])/(8*x)) + (3/8)*a^2*ArcSec[a*x] - (3/4)*(a^2 - 1/x^2)*ArcSec[a*x] + (3*a*Sqrt[1 - 1/(a^2*x^2)]*ArcSec[a*x]^2)/(4*x) - (1/4)*a^2*ArcSec[a*x]^3 + (1/2)*(a^2 - 1/x^2)*ArcSec[a*x]^3}
{ArcSec[a*x]^3/x^4, x, 8, (-(14/9))*a^3*Sqrt[1 - 1/(a^2*x^2)] + (2/27)*a^3*(1 - 1/(a^2*x^2))^(3/2) + (2*ArcSec[a*x])/(9*x^3) + (4*a^2*ArcSec[a*x])/(3*x) + (2/3)*a^3*Sqrt[1 - 1/(a^2*x^2)]*ArcSec[a*x]^2 + (a*Sqrt[1 - 1/(a^2*x^2)]*ArcSec[a*x]^2)/(3*x^2) - ArcSec[a*x]^3/(3*x^3)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcSec[a x^n]*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{ArcSec[a*x^5]/x, x, 2, (1/10)*I*ArcSec[a*x^5]^2 - (1/5)*ArcSec[a*x^5]*Log[2/(1 - I*a*Sqrt[1 - 1/(a^2*x^10)]*x^5)] + (1/10)*I*PolyLog[2, 1 - 2/(1 - I*a*Sqrt[1 - 1/(a^2*x^10)]*x^5)]}


{x^2*ArcSec[Sqrt[x]], x, 6, (-(8/45))*Sqrt[1 - 1/x]*Sqrt[x] - (4/45)*Sqrt[1 - 1/x]*x^(3/2) - (1/15)*Sqrt[1 - 1/x]*x^(5/2) + (1/3)*x^3*ArcSec[Sqrt[x]]}
{x^1*ArcSec[Sqrt[x]], x, 5, (-(1/3))*Sqrt[1 - 1/x]*Sqrt[x] - (1/6)*Sqrt[1 - 1/x]*x^(3/2) + (1/2)*x^2*ArcSec[Sqrt[x]]}
{x^0*ArcSec[Sqrt[x]], x, 3, -Sqrt[-1 + x] + x*ArcSec[Sqrt[x]], (-Sqrt[1 - 1/x])*Sqrt[x] + x*ArcSec[Sqrt[x]]}
{ArcSec[Sqrt[x]]/x^1, x, 2, I*ArcSec[Sqrt[x]]^2 - 2*ArcSec[Sqrt[x]]*Log[2/(1 - I*Sqrt[1 - 1/x]*Sqrt[x])] + I*PolyLog[2, 1 - 2/(1 - I*Sqrt[1 - 1/x]*Sqrt[x])]}
{ArcSec[Sqrt[x]]/x^2, x, 5, Sqrt[-1 + x]/(2*x) - ArcCsc[Sqrt[x]]/2 - ArcSec[Sqrt[x]]/x, Sqrt[1 - 1/x]/(2*Sqrt[x]) - ArcSec[Sqrt[x]]/x - (1/2)*ArcSin[1/Sqrt[x]]}
{ArcSec[Sqrt[x]]/x^3, x, 6, Sqrt[-1 + x]/(8*x^2) + (3*Sqrt[-1 + x])/(16*x) - (3*ArcCsc[Sqrt[x]])/16 - ArcSec[Sqrt[x]]/(2*x^2), Sqrt[1 - 1/x]/(8*x^(3/2)) + (3*Sqrt[1 - 1/x])/(16*Sqrt[x]) - ArcSec[Sqrt[x]]/(2*x^2) - (3/16)*ArcSin[1/Sqrt[x]]}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{x^2*ArcSec[a/x], x, 5, (-(2/9))*a^3*Sqrt[1 - x^2/a^2] - (1/9)*a*x^2*Sqrt[1 - x^2/a^2] + (1/3)*x^3*ArcSec[a/x]}
{x^1*ArcSec[a/x], x, 5, (-(1/4))*a*x*Sqrt[1 - x^2/a^2] + (1/2)*x^2*ArcSec[a/x] + (1/4)*a^2*ArcSin[x/a]}
{x^0*ArcSec[a/x], x, 2, (-a)*Sqrt[1 - x^2/a^2] + x*ArcCos[x/a]}
{ArcSec[a/x]/x^1, x, 2, (-(1/2))*I*ArcSec[a/x]^2 + ArcSec[a/x]*Log[2/(1 - (I*a*Sqrt[1 - x^2/a^2])/x)] - (1/2)*I*PolyLog[2, 1 - 2/(1 - (I*a*Sqrt[1 - x^2/a^2])/x)]}
{ArcSec[a/x]/x^2, x, 4, -(ArcSec[a/x]/x) + ArcTanh[Sqrt[1 - x^2/a^2]]/a}
{ArcSec[a/x]/x^3, x, 3, Sqrt[1 - x^2/a^2]/(2*a*x) - ArcSec[a/x]/(2*x^2)}
{ArcSec[a/x]/x^4, x, 5, Sqrt[1 - x^2/a^2]/(6*a*x^2) - ArcSec[a/x]/(3*x^3) + ArcTanh[Sqrt[1 - x^2/a^2]]/(6*a^3)}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{ArcSec[a*x^n]/x, x, 2, (I*ArcSec[a*x^n]^2)/(2*n) - (ArcSec[a*x^n]*Log[2/(1 - I*a*x^n*Sqrt[1 - 1/(x^(2*n)*a^2)])])/n + (I*PolyLog[2, 1 - 2/(1 - I*a*x^n*Sqrt[1 - 1/(x^(2*n)*a^2)])])/(2*n)}


(* ::Section::Closed:: *)
(*Integrands of the form u ArcSec[a+b x]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcSec[a+b x]^n*)


{x^5*ArcSec[a + b*x], x, 18, -((4*(a + b*x)*Sqrt[1 - 1/(a + b*x)^2])/(45*b^6)) - (5*a^2*(a + b*x)*Sqrt[1 - 1/(a + b*x)^2])/(3*b^6) - (5*a^4*(a + b*x)*Sqrt[1 - 1/(a + b*x)^2])/(2*b^6) + (3*a*(a + b*x)^2*Sqrt[1 - 1/(a + b*x)^2])/(8*b^6) + (5*a^3*(a + b*x)^2*Sqrt[1 - 1/(a + b*x)^2])/(3*b^6) - (2*(a + b*x)^3*Sqrt[1 - 1/(a + b*x)^2])/(45*b^6) - (5*a^2*(a + b*x)^3*Sqrt[1 - 1/(a + b*x)^2])/(6*b^6) + (a*(a + b*x)^4*Sqrt[1 - 1/(a + b*x)^2])/(4*b^6) - ((a + b*x)^5*Sqrt[1 - 1/(a + b*x)^2])/(30*b^6) - ((a^6 - b^6*x^6)*ArcSec[a + b*x])/(6*b^6) + (3*a*ArcTanh[Sqrt[1 - 1/(a + b*x)^2]])/(8*b^6) + (5*a^3*ArcTanh[Sqrt[1 - 1/(a + b*x)^2]])/(3*b^6) + (a^5*ArcTanh[Sqrt[1 - 1/(a + b*x)^2]])/b^6}
{x^4*ArcSec[a + b*x], x, 16, (2*a*(a + b*x)*Sqrt[1 - 1/(a + b*x)^2])/(3*b^5) + (2*a^3*(a + b*x)*Sqrt[1 - 1/(a + b*x)^2])/b^5 - (3*(a + b*x)^2*Sqrt[1 - 1/(a + b*x)^2])/(40*b^5) - (a^2*(a + b*x)^2*Sqrt[1 - 1/(a + b*x)^2])/b^5 + (a*(a + b*x)^3*Sqrt[1 - 1/(a + b*x)^2])/(3*b^5) - ((a + b*x)^4*Sqrt[1 - 1/(a + b*x)^2])/(20*b^5) + ((a^5 + b^5*x^5)*ArcSec[a + b*x])/(5*b^5) - (3*ArcTanh[Sqrt[1 - 1/(a + b*x)^2]])/(40*b^5) - (a^2*ArcTanh[Sqrt[1 - 1/(a + b*x)^2]])/b^5 - (a^4*ArcTanh[Sqrt[1 - 1/(a + b*x)^2]])/b^5}
{x^3*ArcSec[a + b*x], x, 12, -(((a + b*x)*Sqrt[1 - 1/(a + b*x)^2])/(6*b^4)) - (3*a^2*(a + b*x)*Sqrt[1 - 1/(a + b*x)^2])/(2*b^4) + (a*(a + b*x)^2*Sqrt[1 - 1/(a + b*x)^2])/(2*b^4) - ((a + b*x)^3*Sqrt[1 - 1/(a + b*x)^2])/(12*b^4) - ((a^4 - b^4*x^4)*ArcSec[a + b*x])/(4*b^4) + (a*ArcTanh[Sqrt[1 - 1/(a + b*x)^2]])/(2*b^4) + (a^3*ArcTanh[Sqrt[1 - 1/(a + b*x)^2]])/b^4}
{x^2*ArcSec[a + b*x], x, 10, (a*(a + b*x)*Sqrt[1 - 1/(a + b*x)^2])/b^3 - ((a + b*x)^2*Sqrt[1 - 1/(a + b*x)^2])/(6*b^3) + ((a^3 + b^3*x^3)*ArcSec[a + b*x])/(3*b^3) - ArcTanh[Sqrt[1 - 1/(a + b*x)^2]]/(6*b^3) - (a^2*ArcTanh[Sqrt[1 - 1/(a + b*x)^2]])/b^3}
{x^1*ArcSec[a + b*x], x, 6, -(((a + b*x)*Sqrt[1 - 1/(a + b*x)^2])/(2*b^2)) - ((a^2 - b^2*x^2)*ArcSec[a + b*x])/(2*b^2) + (a*ArcTanh[Sqrt[1 - 1/(a + b*x)^2]])/b^2}
{x^0*ArcSec[a + b*x], x, 4, ((a + b*x)*ArcSec[a + b*x])/b - ArcTanh[Sqrt[1 - 1/(a + b*x)^2]]/b}
{ArcSec[a + b*x]/x^1, x, 1, ArcSec[a + b*x]*Log[1 - ((1 - Sqrt[1 - a^2])*E^(I*ArcSec[a + b*x]))/a] + ArcSec[a + b*x]*Log[1 - ((1 + Sqrt[1 - a^2])*E^(I*ArcSec[a + b*x]))/a] - ArcSec[a + b*x]*Log[1 + E^(2*I*ArcSec[a + b*x])] - I*PolyLog[2, ((1 - Sqrt[1 - a^2])*E^(I*ArcSec[a + b*x]))/a] - I*PolyLog[2, ((1 + Sqrt[1 - a^2])*E^(I*ArcSec[a + b*x]))/a] + (1/2)*I*PolyLog[2, -E^(2*I*ArcSec[a + b*x])]}
{ArcSec[a + b*x]/x^2, x, 4, -(((b + a/x)*ArcSec[a + b*x])/a) + (b*ArcTan[(a - 1/(a + b*x))/(Sqrt[1 - a^2]*Sqrt[1 - 1/(a + b*x)^2])])/(a*Sqrt[1 - a^2])}
{ArcSec[a + b*x]/x^3, x, 6, (b^2*Sqrt[1 - 1/(a + b*x)^2])/(2*a*(1 - a^2)*(1 - a/(a + b*x))) + ((b^2 - a^2/x^2)*ArcSec[a + b*x])/(2*a^2) - ((1 - 2*a^2)*b^2*ArcTan[(a - 1/(a + b*x))/(Sqrt[1 - a^2]*Sqrt[1 - 1/(a + b*x)^2])])/(2*a^2*(1 - a^2)^(3/2))}
(* {ArcSec[a + b*x]/x^4, x, 4, 0} *)
{ArcSec[a + b*x]/x^5, x, 15, (b^4*Sqrt[1 - 1/(a + b*x)^2])/(12*a^3*(1 - a^2)*(1 - a/(a + b*x))^3) + (5*b^4*Sqrt[1 - 1/(a + b*x)^2])/(24*a^3*(1 - a^2)^2*(1 - a/(a + b*x))^2) - (b^4*Sqrt[1 - 1/(a + b*x)^2])/(2*a^3*(1 - a^2)*(1 - a/(a + b*x))^2) - (3*b^4*Sqrt[1 - 1/(a + b*x)^2])/(2*a^3*(1 - a^2)^2*(1 - a/(a + b*x))) + (3*b^4*Sqrt[1 - 1/(a + b*x)^2])/(2*a^3*(1 - a^2)*(1 - a/(a + b*x))) + ((11 + 4*a^2)*b^4*Sqrt[1 - 1/(a + b*x)^2])/(24*a^3*(1 - a^2)^3*(1 - a/(a + b*x))) + ((b^4 - a^4/x^4)*ArcSec[a + b*x])/(4*a^4) + (3*b^4*ArcTan[(a - 1/(a + b*x))/(Sqrt[1 - a^2]*Sqrt[1 - 1/(a + b*x)^2])])/(2*a^4*(1 - a^2)^(3/2)) - (b^4*ArcTan[(a - 1/(a + b*x))/(Sqrt[1 - a^2]*Sqrt[1 - 1/(a + b*x)^2])])/(a^4*Sqrt[1 - a^2]) - ((2 + a^2)*b^4*ArcTan[(a - 1/(a + b*x))/(Sqrt[1 - a^2]*Sqrt[1 - 1/(a + b*x)^2])])/(2*a^4*(1 - a^2)^(5/2)) + ((2 + 3*a^2)*b^4*ArcTan[(a - 1/(a + b*x))/(Sqrt[1 - a^2]*Sqrt[1 - 1/(a + b*x)^2])])/(8*a^4*(1 - a^2)^(7/2))}


{x^3*ArcSec[a + b*x]^2, x, 19, -((a*(a + b*x))/b^4) + (a + b*x)^2/(12*b^4) - ((a + b*x)*Sqrt[1 - 1/(a + b*x)^2]*ArcSec[a + b*x])/(3*b^4) - (3*a^2*(a + b*x)*Sqrt[1 - 1/(a + b*x)^2]*ArcSec[a + b*x])/b^4 + (a*(a + b*x)^2*Sqrt[1 - 1/(a + b*x)^2]*ArcSec[a + b*x])/b^4 - ((a + b*x)^3*Sqrt[1 - 1/(a + b*x)^2]*ArcSec[a + b*x])/(6*b^4) - (a^3*(a + b*x)*ArcSec[a + b*x]^2)/b^4 + (3*a^2*(a + b*x)^2*ArcSec[a + b*x]^2)/(2*b^4) - (a*(a + b*x)^3*ArcSec[a + b*x]^2)/b^4 + ((a + b*x)^4*ArcSec[a + b*x]^2)/(4*b^4) - (2*I*a*ArcSec[a + b*x]*ArcTan[E^(I*ArcSec[a + b*x])])/b^4 - (4*I*a^3*ArcSec[a + b*x]*ArcTan[E^(I*ArcSec[a + b*x])])/b^4 - Log[1/(a + b*x)]/(3*b^4) - (3*a^2*Log[1/(a + b*x)])/b^4 + (I*a*PolyLog[2, (-I)*E^(I*ArcSec[a + b*x])])/b^4 + (2*I*a^3*PolyLog[2, (-I)*E^(I*ArcSec[a + b*x])])/b^4 - (I*a*PolyLog[2, I*E^(I*ArcSec[a + b*x])])/b^4 - (2*I*a^3*PolyLog[2, I*E^(I*ArcSec[a + b*x])])/b^4}
{x^2*ArcSec[a + b*x]^2, x, 15, (a + b*x)/(3*b^3) + (2*a*(a + b*x)*Sqrt[1 - 1/(a + b*x)^2]*ArcSec[a + b*x])/b^3 - ((a + b*x)^2*Sqrt[1 - 1/(a + b*x)^2]*ArcSec[a + b*x])/(3*b^3) + (a^2*(a + b*x)*ArcSec[a + b*x]^2)/b^3 - (a*(a + b*x)^2*ArcSec[a + b*x]^2)/b^3 + ((a + b*x)^3*ArcSec[a + b*x]^2)/(3*b^3) + (2*I*ArcSec[a + b*x]*ArcTan[E^(I*ArcSec[a + b*x])])/(3*b^3) + (4*I*a^2*ArcSec[a + b*x]*ArcTan[E^(I*ArcSec[a + b*x])])/b^3 + (2*a*Log[1/(a + b*x)])/b^3 - (I*PolyLog[2, (-I)*E^(I*ArcSec[a + b*x])])/(3*b^3) - (2*I*a^2*PolyLog[2, (-I)*E^(I*ArcSec[a + b*x])])/b^3 + (I*PolyLog[2, I*E^(I*ArcSec[a + b*x])])/(3*b^3) + (2*I*a^2*PolyLog[2, I*E^(I*ArcSec[a + b*x])])/b^3}
{x^1*ArcSec[a + b*x]^2, x, 10, -(((a + b*x)*Sqrt[1 - 1/(a + b*x)^2]*ArcSec[a + b*x])/b^2) - (a*(a + b*x)*ArcSec[a + b*x]^2)/b^2 + ((a + b*x)^2*ArcSec[a + b*x]^2)/(2*b^2) - (4*I*a*ArcSec[a + b*x]*ArcTan[E^(I*ArcSec[a + b*x])])/b^2 - Log[1/(a + b*x)]/b^2 + (2*I*a*PolyLog[2, (-I)*E^(I*ArcSec[a + b*x])])/b^2 - (2*I*a*PolyLog[2, I*E^(I*ArcSec[a + b*x])])/b^2}
{x^0*ArcSec[a + b*x]^2, x, 5, ((a + b*x)*ArcSec[a + b*x]^2)/b + (4*I*ArcSec[a + b*x]*ArcTan[E^(I*ArcSec[a + b*x])])/b - (2*I*PolyLog[2, (-I)*E^(I*ArcSec[a + b*x])])/b + (2*I*PolyLog[2, I*E^(I*ArcSec[a + b*x])])/b}
{ArcSec[a + b*x]^2/x^1, x, 1, (-ArcSec[a + b*x]^2)*Log[1 + E^(2*I*ArcSec[a + b*x])] + ArcSec[a + b*x]^2*Log[1 + (a*(1/(a + b*x) + I*Sqrt[1 - 1/(a + b*x)^2]))/(-1 + Sqrt[1 - a^2])] + ArcSec[a + b*x]^2*Log[1 - (a*(1/(a + b*x) + I*Sqrt[1 - 1/(a + b*x)^2]))/(1 + Sqrt[1 - a^2])] + I*ArcSec[a + b*x]*PolyLog[2, -E^(2*I*ArcSec[a + b*x])] - 2*I*ArcSec[a + b*x]*PolyLog[2, -((a*(1/(a + b*x) + I*Sqrt[1 - 1/(a + b*x)^2]))/(-1 + Sqrt[1 - a^2]))] - 2*I*ArcSec[a + b*x]*PolyLog[2, (a*(1/(a + b*x) + I*Sqrt[1 - 1/(a + b*x)^2]))/(1 + Sqrt[1 - a^2])] - (1/2)*PolyLog[3, -E^(2*I*ArcSec[a + b*x])] + 2*PolyLog[3, -((a*(1/(a + b*x) + I*Sqrt[1 - 1/(a + b*x)^2]))/(-1 + Sqrt[1 - a^2]))] + 2*PolyLog[3, (a*(1/(a + b*x) + I*Sqrt[1 - 1/(a + b*x)^2]))/(1 + Sqrt[1 - a^2])], Subst[Int[(x^2*Sec[x]*Tan[x])/(-a + Sec[x]), x], x, ArcSec[a + b*x]]}
{ArcSec[a + b*x]^2/x^2, x, 1, (1/a)*(b*(-(((a + b*x)*ArcSec[a + b*x]^2)/(b*x)) - (1/Sqrt[-1 + a^2])*(2*(2*ArcSec[a + b*x]*ArcTanh[((-1 + a)*Cot[(1/2)*ArcSec[a + b*x]])/Sqrt[-1 + a^2]] - 2*ArcCos[1/a]*ArcTanh[((1 + a)*Tan[(1/2)*ArcSec[a + b*x]])/Sqrt[-1 + a^2]] + (ArcCos[1/a] - 2*I*ArcTanh[((-1 + a)*Cot[(1/2)*ArcSec[a + b*x]])/Sqrt[-1 + a^2]] + 2*I*ArcTanh[((1 + a)*Tan[(1/2)*ArcSec[a + b*x]])/Sqrt[-1 + a^2]])*Log[Sqrt[-1 + a^2]/(E^((1/2)*I*ArcSec[a + b*x])*(Sqrt[2]*Sqrt[a]*Sqrt[-((b*x)/(a + b*x))]))] + (ArcCos[1/a] + 2*I*(ArcTanh[((-1 + a)*Cot[(1/2)*ArcSec[a + b*x]])/Sqrt[-1 + a^2]] - ArcTanh[((1 + a)*Tan[(1/2)*ArcSec[a + b*x]])/Sqrt[-1 + a^2]]))*Log[(Sqrt[-1 + a^2]*E^((1/2)*I*ArcSec[a + b*x]))/(Sqrt[2]*Sqrt[a]*Sqrt[-((b*x)/(a + b*x))])] - (ArcCos[1/a] + 2*I*ArcTanh[((1 + a)*Tan[(1/2)*ArcSec[a + b*x]])/Sqrt[-1 + a^2]])*Log[((-1 + a)*(1 + a + I*Sqrt[-1 + a^2])*(1 - I*Tan[(1/2)*ArcSec[a + b*x]]))/(a*(-1 + a + Sqrt[-1 + a^2]*Tan[(1/2)*ArcSec[a + b*x]]))] - (ArcCos[1/a] - 2*I*ArcTanh[((1 + a)*Tan[(1/2)*ArcSec[a + b*x]])/Sqrt[-1 + a^2]])*Log[((-1 + a)*(1 + a - I*Sqrt[-1 + a^2])*(1 + I*Tan[(1/2)*ArcSec[a + b*x]]))/(a*(-1 + a + Sqrt[-1 + a^2]*Tan[(1/2)*ArcSec[a + b*x]]))] + I*(-PolyLog[2, ((1 - I*Sqrt[-1 + a^2])*(1 - a + Sqrt[-1 + a^2]*Tan[(1/2)*ArcSec[a + b*x]]))/(a*(-1 + a + Sqrt[-1 + a^2]*Tan[(1/2)*ArcSec[a + b*x]]))] + PolyLog[2, ((1 + I*Sqrt[-1 + a^2])*(1 - a + Sqrt[-1 + a^2]*Tan[(1/2)*ArcSec[a + b*x]]))/(a*(-1 + a + Sqrt[-1 + a^2]*Tan[(1/2)*ArcSec[a + b*x]]))]))))), b*Subst[Int[(x^2*Sec[x]*Tan[x])/(-a + Sec[x])^2, x], x, ArcSec[a + b*x]]}


{x^2*ArcSec[a + b*x]^3, x, 23, ((a + b*x)*ArcSec[a + b*x])/b^3 - (3*I*a*ArcSec[a + b*x]^2)/b^3 + (3*a*(a + b*x)*Sqrt[1 - 1/(a + b*x)^2]*ArcSec[a + b*x]^2)/b^3 - ((a + b*x)^2*Sqrt[1 - 1/(a + b*x)^2]*ArcSec[a + b*x]^2)/(2*b^3) + (a^2*(a + b*x)*ArcSec[a + b*x]^3)/b^3 - (a*(a + b*x)^2*ArcSec[a + b*x]^3)/b^3 + ((a + b*x)^3*ArcSec[a + b*x]^3)/(3*b^3) + (I*ArcSec[a + b*x]^2*ArcTan[E^(I*ArcSec[a + b*x])])/b^3 + (6*I*a^2*ArcSec[a + b*x]^2*ArcTan[E^(I*ArcSec[a + b*x])])/b^3 - ArcTanh[Sqrt[1 - 1/(a + b*x)^2]]/b^3 + (6*a*ArcSec[a + b*x]*Log[1 + E^(2*I*ArcSec[a + b*x])])/b^3 - (I*ArcSec[a + b*x]*PolyLog[2, (-I)*E^(I*ArcSec[a + b*x])])/b^3 - (6*I*a^2*ArcSec[a + b*x]*PolyLog[2, (-I)*E^(I*ArcSec[a + b*x])])/b^3 + (I*ArcSec[a + b*x]*PolyLog[2, I*E^(I*ArcSec[a + b*x])])/b^3 + (6*I*a^2*ArcSec[a + b*x]*PolyLog[2, I*E^(I*ArcSec[a + b*x])])/b^3 - (3*I*a*PolyLog[2, -E^(2*I*ArcSec[a + b*x])])/b^3 + PolyLog[3, (-I)*E^(I*ArcSec[a + b*x])]/b^3 + (6*a^2*PolyLog[3, (-I)*E^(I*ArcSec[a + b*x])])/b^3 - PolyLog[3, I*E^(I*ArcSec[a + b*x])]/b^3 - (6*a^2*PolyLog[3, I*E^(I*ArcSec[a + b*x])])/b^3}
{x^1*ArcSec[a + b*x]^3, x, 15, (3*I*ArcSec[a + b*x]^2)/(2*b^2) - (3*(a + b*x)*Sqrt[1 - 1/(a + b*x)^2]*ArcSec[a + b*x]^2)/(2*b^2) - (a*(a + b*x)*ArcSec[a + b*x]^3)/b^2 + ((a + b*x)^2*ArcSec[a + b*x]^3)/(2*b^2) - (6*I*a*ArcSec[a + b*x]^2*ArcTan[E^(I*ArcSec[a + b*x])])/b^2 - (3*ArcSec[a + b*x]*Log[1 + E^(2*I*ArcSec[a + b*x])])/b^2 + (6*I*a*ArcSec[a + b*x]*PolyLog[2, (-I)*E^(I*ArcSec[a + b*x])])/b^2 - (6*I*a*ArcSec[a + b*x]*PolyLog[2, I*E^(I*ArcSec[a + b*x])])/b^2 + (3*I*PolyLog[2, -E^(2*I*ArcSec[a + b*x])])/(2*b^2) - (6*a*PolyLog[3, (-I)*E^(I*ArcSec[a + b*x])])/b^2 + (6*a*PolyLog[3, I*E^(I*ArcSec[a + b*x])])/b^2}
{x^0*ArcSec[a + b*x]^3, x, 7, ((a + b*x)*ArcSec[a + b*x]^3)/b + (6*I*ArcSec[a + b*x]^2*ArcTan[E^(I*ArcSec[a + b*x])])/b - (6*I*ArcSec[a + b*x]*PolyLog[2, (-I)*E^(I*ArcSec[a + b*x])])/b + (6*I*ArcSec[a + b*x]*PolyLog[2, I*E^(I*ArcSec[a + b*x])])/b + (6*PolyLog[3, (-I)*E^(I*ArcSec[a + b*x])])/b - (6*PolyLog[3, I*E^(I*ArcSec[a + b*x])])/b}
{ArcSec[a + b*x]^3/x^1, x, 1, Subst[Int[(x^3*Sec[x]*Tan[x])/(-a + Sec[x]), x], x, ArcSec[a + b*x]]}
{ArcSec[a + b*x]^3/x^2, x, 1, b*Subst[Int[(x^3*Sec[x]*Tan[x])/(-a + Sec[x])^2, x], x, ArcSec[a + b*x]]}


(* ::Section::Closed:: *)
(*Integrands of the form u ArcSec[a +b x^n]*)


{x^3*ArcSec[a + b*x^4], x, 5, ((a + b*x^4)*ArcSec[a + b*x^4])/(4*b) - ArcTanh[Sqrt[1 - 1/(a + b*x^4)^2]]/(4*b)}


{x^(n-1)*ArcSec[a + b*x^n], x, 5, ((a + b*x^n)*ArcSec[a + b*x^n])/(b*n) - ArcTanh[Sqrt[1 - 1/(a + b*x^n)^2]]/(b*n)}


(* ::Section::Closed:: *)
(*Integrands involving inverse trig functions of exponentials*)


{ArcSec[c*E^(a + b*x)], x, 2, (I*ArcSec[c*E^(a + b*x)]^2)/(2*b) - (ArcSec[c*E^(a + b*x)]*Log[2/(1 - I*c*E^(a + b*x)*Sqrt[1 - E^(-2*a - 2*b*x)/c^2])])/b + (I*PolyLog[2, 1 - 2/(1 - I*c*E^(a + b*x)*Sqrt[1 - E^(-2*a - 2*b*x)/c^2])])/(2*b)}


(* ::Section::Closed:: *)
(*Integrands involving exponentials of inverse trig functions*)


(* Integrands of the form x^m*E^ArcSec[x] where m is an integer *)
{E^ArcSec[x], x, 0, Int[E^ArcSec[x], x]}
{E^ArcSec[x]/x, x, 0, Int[E^ArcSec[x]/x, x]}
{E^ArcSec[x]/x^2, x, 2, (1/2)*E^ArcSec[x]*Sqrt[1 - 1/x^2] - E^ArcSec[x]/(2*x)}


(* ::Section::Closed:: *)
(*Miscellaneous integrands involving inverse secants*)


{ArcSec[a + b*x]/((a*d)/b + d*x), x, 3, (I*ArcSec[b*(a/b + x)]^2)/(2*d) - (ArcSec[b*(a/b + x)]*Log[2/(1 - I*b*(a/b + x)*Sqrt[1 - 1/(b^2*(a/b + x)^2)])])/d + (I*PolyLog[2, 1 - 2/(1 - I*b*(a/b + x)*Sqrt[1 - 1/(b^2*(a/b + x)^2)])])/(2*d)}
