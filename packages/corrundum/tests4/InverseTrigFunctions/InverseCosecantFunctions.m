(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Inverse Cosecants*)


(* ::Section::Closed:: *)
(*Integrands of the form u ArcCsc[a x^n]^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcCsc[a x]^n*)


{x^m*ArcCsc[a*x], x, 3, -((a*Sqrt[1 - 1/(a^2*x^2)]*x^(2 + m))/(1 + m)^2) + (x^(1 + m)*ArcCsc[a*x])/(1 + m) + (a*x^(2 + m)*Hypergeometric2F1[1/2, (1/2)*(-2 - m), -(m/2), 1/(a^2*x^2)])/(1 + m)^2}

{x^7*ArcCsc[a*x], x, 6, (2*Sqrt[1 - 1/(a^2*x^2)]*x)/(35*a^7) + (Sqrt[1 - 1/(a^2*x^2)]*x^3)/(35*a^5) + (3*Sqrt[1 - 1/(a^2*x^2)]*x^5)/(140*a^3) + (Sqrt[1 - 1/(a^2*x^2)]*x^7)/(56*a) + (1/8)*x^8*ArcCsc[a*x]}
{x^6*ArcCsc[a*x], x, 7, (5*Sqrt[1 - 1/(a^2*x^2)]*x^2)/(112*a^5) + (5*Sqrt[1 - 1/(a^2*x^2)]*x^4)/(168*a^3) + (Sqrt[1 - 1/(a^2*x^2)]*x^6)/(42*a) + (1/7)*x^7*ArcCsc[a*x] + (5*ArcTanh[Sqrt[1 - 1/(a^2*x^2)]])/(112*a^7)}
{x^5*ArcCsc[a*x], x, 5, (4*Sqrt[1 - 1/(a^2*x^2)]*x)/(45*a^5) + (2*Sqrt[1 - 1/(a^2*x^2)]*x^3)/(45*a^3) + (Sqrt[1 - 1/(a^2*x^2)]*x^5)/(30*a) + (1/6)*x^6*ArcCsc[a*x]}
{x^4*ArcCsc[a*x], x, 6, (3*Sqrt[1 - 1/(a^2*x^2)]*x^2)/(40*a^3) + (Sqrt[1 - 1/(a^2*x^2)]*x^4)/(20*a) + (1/5)*x^5*ArcCsc[a*x] + (3*ArcTanh[Sqrt[1 - 1/(a^2*x^2)]])/(40*a^5)}
{x^3*ArcCsc[a*x], x, 4, (Sqrt[1 - 1/(a^2*x^2)]*x)/(6*a^3) + (Sqrt[1 - 1/(a^2*x^2)]*x^3)/(12*a) + (1/4)*x^4*ArcCsc[a*x]}
{x^2*ArcCsc[a*x], x, 4, (Sqrt[1 - 1/(a^2*x^2)]*x^2)/(6*a) + (1/3)*x^3*ArcCsc[a*x] + ArcTanh[Sqrt[1 - 1/(a^2*x^2)]]/(6*a^3)}
{x^1*ArcCsc[a*x], x, 2, (Sqrt[1 - 1/(a^2*x^2)]*x)/(2*a) + (1/2)*x^2*ArcCsc[a*x]}
{x^0*ArcCsc[a*x], x, 3, x*ArcCsc[a*x] + ArcTanh[Sqrt[1 - 1/(a^2*x^2)]]/a}
{ArcCsc[a*x]/x^1, x, 1, (-(1/2))*I*ArcCsc[a*x]^2 - ArcCsc[a*x]*Log[2/(1 - I*a*Sqrt[1 - 1/(a^2*x^2)]*x)] - (1/2)*I*PolyLog[2, 1 - 2/(1 - I*a*Sqrt[1 - 1/(a^2*x^2)]*x)]}
{ArcCsc[a*x]/x^2, x, 2, (-a)*Sqrt[1 - 1/(a^2*x^2)] - ArcCsc[a*x]/x}
{ArcCsc[a*x]/x^3, x, 4, -((a*Sqrt[1 - 1/(a^2*x^2)])/(4*x)) - ArcCsc[a*x]/(2*x^2) + (1/4)*a^2*ArcSin[1/(a*x)]}
{ArcCsc[a*x]/x^4, x, 4, (-(2/9))*a^3*Sqrt[1 - 1/(a^2*x^2)] - (a*Sqrt[1 - 1/(a^2*x^2)])/(9*x^2) - ArcCsc[a*x]/(3*x^3)}
{ArcCsc[a*x]/x^5, x, 5, -((a*Sqrt[1 - 1/(a^2*x^2)])/(16*x^3)) - (3*a^3*Sqrt[1 - 1/(a^2*x^2)])/(32*x) - ArcCsc[a*x]/(4*x^4) + (3/32)*a^4*ArcSin[1/(a*x)]}
{ArcCsc[a*x]/x^6, x, 5, (-(8/75))*a^5*Sqrt[1 - 1/(a^2*x^2)] - (a*Sqrt[1 - 1/(a^2*x^2)])/(25*x^4) - (4*a^3*Sqrt[1 - 1/(a^2*x^2)])/(75*x^2) - ArcCsc[a*x]/(5*x^5)}
{ArcCsc[a*x]/x^7, x, 6, -((a*Sqrt[1 - 1/(a^2*x^2)])/(36*x^5)) - (5*a^3*Sqrt[1 - 1/(a^2*x^2)])/(144*x^3) - (5*a^5*Sqrt[1 - 1/(a^2*x^2)])/(96*x) - ArcCsc[a*x]/(6*x^6) + (5/96)*a^6*ArcSin[1/(a*x)]}
{ArcCsc[a*x]/x^8, x, 6, (-(16/245))*a^7*Sqrt[1 - 1/(a^2*x^2)] - (a*Sqrt[1 - 1/(a^2*x^2)])/(49*x^6) - (6*a^3*Sqrt[1 - 1/(a^2*x^2)])/(245*x^4) - (8*a^5*Sqrt[1 - 1/(a^2*x^2)])/(245*x^2) - ArcCsc[a*x]/(7*x^7)}
{ArcCsc[a*x]/x^9, x, 7, -((a*Sqrt[1 - 1/(a^2*x^2)])/(64*x^7)) - (7*a^3*Sqrt[1 - 1/(a^2*x^2)])/(384*x^5) - (35*a^5*Sqrt[1 - 1/(a^2*x^2)])/(1536*x^3) - (35*a^7*Sqrt[1 - 1/(a^2*x^2)])/(1024*x) - ArcCsc[a*x]/(8*x^8) + (35*a^8*ArcSin[1/(a*x)])/1024}


{x^m*ArcCsc[a*x]^2, x, 0, Int[x^m*ArcCsc[a*x]^2, x]}

{x^4*ArcCsc[a*x]^2, x, 7, (3*x)/(20*a^4) + x^3/(30*a^2) + (3*Sqrt[1 - 1/(a^2*x^2)]*x^2*ArcCsc[a*x])/(20*a^3) + (Sqrt[1 - 1/(a^2*x^2)]*x^4*ArcCsc[a*x])/(10*a) + (1/5)*x^5*ArcCsc[a*x]^2 + (3*ArcCsc[a*x]*ArcTanh[E^(I*ArcCsc[a*x])])/(10*a^5) - (3*I*PolyLog[2, -E^(I*ArcCsc[a*x])])/(20*a^5) + (3*I*PolyLog[2, E^(I*ArcCsc[a*x])])/(20*a^5)}
{x^3*ArcCsc[a*x]^2, x, 5, x^2/(12*a^2) + (Sqrt[1 - 1/(a^2*x^2)]*x*ArcCsc[a*x])/(3*a^3) + (Sqrt[1 - 1/(a^2*x^2)]*x^3*ArcCsc[a*x])/(6*a) + (1/4)*x^4*ArcCsc[a*x]^2 - Log[1/x]/(3*a^4)}
{x^2*ArcCsc[a*x]^2, x, 6, x/(3*a^2) + (Sqrt[1 - 1/(a^2*x^2)]*x^2*ArcCsc[a*x])/(3*a) + (1/3)*x^3*ArcCsc[a*x]^2 + (2*ArcCsc[a*x]*ArcTanh[E^(I*ArcCsc[a*x])])/(3*a^3) - (I*PolyLog[2, -E^(I*ArcCsc[a*x])])/(3*a^3) + (I*PolyLog[2, E^(I*ArcCsc[a*x])])/(3*a^3)}
{x^1*ArcCsc[a*x]^2, x, 4, (Sqrt[1 - 1/(a^2*x^2)]*x*ArcCsc[a*x])/a + (1/2)*x^2*ArcCsc[a*x]^2 - Log[1/x]/a^2}
{x^0*ArcCsc[a*x]^2, x, 5, x*ArcCsc[a*x]^2 + (4*ArcCsc[a*x]*ArcTanh[E^(I*ArcCsc[a*x])])/a - (2*I*PolyLog[2, -E^(I*ArcCsc[a*x])])/a + (2*I*PolyLog[2, E^(I*ArcCsc[a*x])])/a}
{ArcCsc[a*x]^2/x^1, x, 6, (1/3)*I*ArcCsc[a*x]^3 - ArcCsc[a*x]^2*Log[1 - E^(2*I*ArcCsc[a*x])] + I*ArcCsc[a*x]*PolyLog[2, E^(2*I*ArcCsc[a*x])] - (1/2)*PolyLog[3, E^(2*I*ArcCsc[a*x])]}
{ArcCsc[a*x]^2/x^2, x, 4, 2/x - 2*a*Sqrt[1 - 1/(a^2*x^2)]*ArcCsc[a*x] - ArcCsc[a*x]^2/x}
{ArcCsc[a*x]^2/x^3, x, 4, 1/(4*x^2) - (a*Sqrt[1 - 1/(a^2*x^2)]*ArcCsc[a*x])/(2*x) + (1/4)*a^2*ArcCsc[a*x]^2 - ArcCsc[a*x]^2/(2*x^2)}
{ArcCsc[a*x]^2/x^4, x, 5, 2/(27*x^3) + (4*a^2)/(9*x) - (4/9)*a^3*Sqrt[1 - 1/(a^2*x^2)]*ArcCsc[a*x] - (2*a*Sqrt[1 - 1/(a^2*x^2)]*ArcCsc[a*x])/(9*x^2) - ArcCsc[a*x]^2/(3*x^3)}


{x^m*ArcCsc[a*x]^3, x, 0, Int[x^m*ArcCsc[a*x]^3, x]}

{x^4*ArcCsc[a*x]^3, x, 12, (Sqrt[1 - 1/(a^2*x^2)]*x^2)/(20*a^3) + (9*x*ArcCsc[a*x])/(20*a^4) + (x^3*ArcCsc[a*x])/(10*a^2) + (9*Sqrt[1 - 1/(a^2*x^2)]*x^2*ArcCsc[a*x]^2)/(40*a^3) + (3*Sqrt[1 - 1/(a^2*x^2)]*x^4*ArcCsc[a*x]^2)/(20*a) + (1/5)*x^5*ArcCsc[a*x]^3 + (9*ArcCsc[a*x]^2*ArcTanh[E^(I*ArcCsc[a*x])])/(20*a^5) + ArcTanh[Sqrt[1 - 1/(a^2*x^2)]]/(2*a^5) - (9*I*ArcCsc[a*x]*PolyLog[2, -E^(I*ArcCsc[a*x])])/(20*a^5) + (9*I*ArcCsc[a*x]*PolyLog[2, E^(I*ArcCsc[a*x])])/(20*a^5) + (9*PolyLog[3, -E^(I*ArcCsc[a*x])])/(20*a^5) - (9*PolyLog[3, E^(I*ArcCsc[a*x])])/(20*a^5)}
{x^3*ArcCsc[a*x]^3, x, 9, (Sqrt[1 - 1/(a^2*x^2)]*x)/(4*a^3) + (x^2*ArcCsc[a*x])/(4*a^2) + (I*ArcCsc[a*x]^2)/(2*a^4) + (Sqrt[1 - 1/(a^2*x^2)]*x*ArcCsc[a*x]^2)/(2*a^3) + (Sqrt[1 - 1/(a^2*x^2)]*x^3*ArcCsc[a*x]^2)/(4*a) + (1/4)*x^4*ArcCsc[a*x]^3 - (ArcCsc[a*x]*Log[1 - E^(2*I*ArcCsc[a*x])])/a^4 + (I*PolyLog[2, E^(2*I*ArcCsc[a*x])])/(2*a^4)}
{x^2*ArcCsc[a*x]^3, x, 9, (x*ArcCsc[a*x])/a^2 + (Sqrt[1 - 1/(a^2*x^2)]*x^2*ArcCsc[a*x]^2)/(2*a) + (1/3)*x^3*ArcCsc[a*x]^3 + (ArcCsc[a*x]^2*ArcTanh[E^(I*ArcCsc[a*x])])/a^3 + ArcTanh[Sqrt[1 - 1/(a^2*x^2)]]/a^3 - (I*ArcCsc[a*x]*PolyLog[2, -E^(I*ArcCsc[a*x])])/a^3 + (I*ArcCsc[a*x]*PolyLog[2, E^(I*ArcCsc[a*x])])/a^3 + PolyLog[3, -E^(I*ArcCsc[a*x])]/a^3 - PolyLog[3, E^(I*ArcCsc[a*x])]/a^3}
{x^1*ArcCsc[a*x]^3, x, 7, (3*I*ArcCsc[a*x]^2)/(2*a^2) + (3*Sqrt[1 - 1/(a^2*x^2)]*x*ArcCsc[a*x]^2)/(2*a) + (1/2)*x^2*ArcCsc[a*x]^3 - (3*ArcCsc[a*x]*Log[1 - E^(2*I*ArcCsc[a*x])])/a^2 + (3*I*PolyLog[2, E^(2*I*ArcCsc[a*x])])/(2*a^2)}
{x^0*ArcCsc[a*x]^3, x, 7, x*ArcCsc[a*x]^3 + (6*ArcCsc[a*x]^2*ArcTanh[E^(I*ArcCsc[a*x])])/a - (6*I*ArcCsc[a*x]*PolyLog[2, -E^(I*ArcCsc[a*x])])/a + (6*I*ArcCsc[a*x]*PolyLog[2, E^(I*ArcCsc[a*x])])/a + (6*PolyLog[3, -E^(I*ArcCsc[a*x])])/a - (6*PolyLog[3, E^(I*ArcCsc[a*x])])/a}
{ArcCsc[a*x]^3/x^1, x, 7, (1/4)*I*ArcCsc[a*x]^4 - ArcCsc[a*x]^3*Log[1 - E^(2*I*ArcCsc[a*x])] + (3/2)*I*ArcCsc[a*x]^2*PolyLog[2, E^(2*I*ArcCsc[a*x])] - (3/2)*ArcCsc[a*x]*PolyLog[3, E^(2*I*ArcCsc[a*x])] - (3/4)*I*PolyLog[4, E^(2*I*ArcCsc[a*x])]}
{ArcCsc[a*x]^3/x^2, x, 5, 6*a*Sqrt[1 - 1/(a^2*x^2)] + (6*ArcCsc[a*x])/x - 3*a*Sqrt[1 - 1/(a^2*x^2)]*ArcCsc[a*x]^2 - ArcCsc[a*x]^3/x}
{ArcCsc[a*x]^3/x^3, x, 5, (3*a*Sqrt[1 - 1/(a^2*x^2)])/(8*x) - (3/8)*a^2*ArcCsc[a*x] + (3*ArcCsc[a*x])/(4*x^2) - (3*a*Sqrt[1 - 1/(a^2*x^2)]*ArcCsc[a*x]^2)/(4*x) + (1/4)*a^2*ArcCsc[a*x]^3 - ArcCsc[a*x]^3/(2*x^2)}
{ArcCsc[a*x]^3/x^4, x, 8, (14/9)*a^3*Sqrt[1 - 1/(a^2*x^2)] - (2/27)*a^3*(1 - 1/(a^2*x^2))^(3/2) + (2*ArcCsc[a*x])/(9*x^3) + (4*a^2*ArcCsc[a*x])/(3*x) - (2/3)*a^3*Sqrt[1 - 1/(a^2*x^2)]*ArcCsc[a*x]^2 - (a*Sqrt[1 - 1/(a^2*x^2)]*ArcCsc[a*x]^2)/(3*x^2) - ArcCsc[a*x]^3/(3*x^3)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcCsc[a x^n]*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{ArcCsc[a*x^5]/x, x, 2, (-(1/10))*I*ArcCsc[a*x^5]^2 - (1/5)*ArcCsc[a*x^5]*Log[2/(1 - I*a*Sqrt[1 - 1/(a^2*x^10)]*x^5)] - (1/10)*I*PolyLog[2, 1 - 2/(1 - I*a*Sqrt[1 - 1/(a^2*x^10)]*x^5)]}


{x^2*ArcCsc[Sqrt[x]], x, 6, (8/45)*Sqrt[1 - 1/x]*Sqrt[x] + (4/45)*Sqrt[1 - 1/x]*x^(3/2) + (1/15)*Sqrt[1 - 1/x]*x^(5/2) + (1/3)*x^3*ArcCsc[Sqrt[x]]}
{x^1*ArcCsc[Sqrt[x]], x, 5, (1/3)*Sqrt[1 - 1/x]*Sqrt[x] + (1/6)*Sqrt[1 - 1/x]*x^(3/2) + (1/2)*x^2*ArcCsc[Sqrt[x]]}
{x^0*ArcCsc[Sqrt[x]], x, 3, Sqrt[1 - 1/x]*Sqrt[x] + x*ArcCsc[Sqrt[x]]}
{ArcCsc[Sqrt[x]]/x^1, x, 2, (-I)*ArcCsc[Sqrt[x]]^2 - 2*ArcCsc[Sqrt[x]]*Log[2/(1 - I*Sqrt[1 - 1/x]*Sqrt[x])] - I*PolyLog[2, 1 - 2/(1 - I*Sqrt[1 - 1/x]*Sqrt[x])]}
{ArcCsc[Sqrt[x]]/x^2, x, 5, -(Sqrt[-1 + x]/(2*x)) + ArcCsc[Sqrt[x]]/2 - ArcCsc[Sqrt[x]]/x, -(Sqrt[1 - 1/x]/(2*Sqrt[x])) - ArcCsc[Sqrt[x]]/x + (1/2)*ArcSin[1/Sqrt[x]]}
{ArcCsc[Sqrt[x]]/x^3, x, 6, -(Sqrt[-1 + x]/(8*x^2)) - (3*Sqrt[-1 + x])/(16*x) + (3*ArcCsc[Sqrt[x]])/16 - ArcCsc[Sqrt[x]]/(2*x^2), -(Sqrt[1 - 1/x]/(8*x^(3/2))) - (3*Sqrt[1 - 1/x])/(16*Sqrt[x]) - ArcCsc[Sqrt[x]]/(2*x^2) + (3/16)*ArcSin[1/Sqrt[x]]}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{x^2*ArcCsc[a/x], x, 5, (2/9)*a^3*Sqrt[1 - x^2/a^2] + (1/9)*a*x^2*Sqrt[1 - x^2/a^2] + (1/3)*x^3*ArcCsc[a/x]}
{x^1*ArcCsc[a/x], x, 5, (1/4)*a*x*Sqrt[1 - x^2/a^2] + (1/2)*x^2*ArcCsc[a/x] - (1/4)*a^2*ArcSin[x/a]}
{x^0*ArcCsc[a/x], x, 2, a*Sqrt[1 - x^2/a^2] + x*ArcSin[x/a]}
{ArcCsc[a/x]/x^1, x, 2, (1/2)*I*ArcCsc[a/x]^2 + ArcCsc[a/x]*Log[2/(1 - (I*a*Sqrt[1 - x^2/a^2])/x)] + (1/2)*I*PolyLog[2, 1 - 2/(1 - (I*a*Sqrt[1 - x^2/a^2])/x)]}
{ArcCsc[a/x]/x^2, x, 4, -(ArcCsc[a/x]/x) - ArcTanh[Sqrt[1 - x^2/a^2]]/a}
{ArcCsc[a/x]/x^3, x, 3, -(Sqrt[1 - x^2/a^2]/(2*a*x)) - ArcCsc[a/x]/(2*x^2)}
{ArcCsc[a/x]/x^4, x, 5, -(Sqrt[1 - x^2/a^2]/(6*a*x^2)) - ArcCsc[a/x]/(3*x^3) - ArcTanh[Sqrt[1 - x^2/a^2]]/(6*a^3)}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{ArcCsc[a*x^n]/x, x, 2, -((I*ArcCsc[a*x^n]^2)/(2*n)) - (ArcCsc[a*x^n]*Log[2/(1 - I*a*x^n*Sqrt[1 - 1/(x^(2*n)*a^2)])])/n - (I*PolyLog[2, 1 - 2/(1 - I*a*x^n*Sqrt[1 - 1/(x^(2*n)*a^2)])])/(2*n)}


(* ::Section::Closed:: *)
(*Integrands of the form u ArcCsc[a+b x]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcCsc[a+b x]^n*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{x^5*ArcCsc[a + b*x], x, 18, (4*(a + b*x)*Sqrt[1 - 1/(a + b*x)^2])/(45*b^6) + (5*a^2*(a + b*x)*Sqrt[1 - 1/(a + b*x)^2])/(3*b^6) + (5*a^4*(a + b*x)*Sqrt[1 - 1/(a + b*x)^2])/(2*b^6) - (3*a*(a + b*x)^2*Sqrt[1 - 1/(a + b*x)^2])/(8*b^6) - (5*a^3*(a + b*x)^2*Sqrt[1 - 1/(a + b*x)^2])/(3*b^6) + (2*(a + b*x)^3*Sqrt[1 - 1/(a + b*x)^2])/(45*b^6) + (5*a^2*(a + b*x)^3*Sqrt[1 - 1/(a + b*x)^2])/(6*b^6) - (a*(a + b*x)^4*Sqrt[1 - 1/(a + b*x)^2])/(4*b^6) + ((a + b*x)^5*Sqrt[1 - 1/(a + b*x)^2])/(30*b^6) - ((a^6 - b^6*x^6)*ArcCsc[a + b*x])/(6*b^6) - (3*a*ArcTanh[Sqrt[1 - 1/(a + b*x)^2]])/(8*b^6) - (5*a^3*ArcTanh[Sqrt[1 - 1/(a + b*x)^2]])/(3*b^6) - (a^5*ArcTanh[Sqrt[1 - 1/(a + b*x)^2]])/b^6}
{x^4*ArcCsc[a + b*x], x, 16, -((2*a*(a + b*x)*Sqrt[1 - 1/(a + b*x)^2])/(3*b^5)) - (2*a^3*(a + b*x)*Sqrt[1 - 1/(a + b*x)^2])/b^5 + (3*(a + b*x)^2*Sqrt[1 - 1/(a + b*x)^2])/(40*b^5) + (a^2*(a + b*x)^2*Sqrt[1 - 1/(a + b*x)^2])/b^5 - (a*(a + b*x)^3*Sqrt[1 - 1/(a + b*x)^2])/(3*b^5) + ((a + b*x)^4*Sqrt[1 - 1/(a + b*x)^2])/(20*b^5) + ((a^5 + b^5*x^5)*ArcCsc[a + b*x])/(5*b^5) + (3*ArcTanh[Sqrt[1 - 1/(a + b*x)^2]])/(40*b^5) + (a^2*ArcTanh[Sqrt[1 - 1/(a + b*x)^2]])/b^5 + (a^4*ArcTanh[Sqrt[1 - 1/(a + b*x)^2]])/b^5}
{x^3*ArcCsc[a + b*x], x, 12, ((a + b*x)*Sqrt[1 - 1/(a + b*x)^2])/(6*b^4) + (3*a^2*(a + b*x)*Sqrt[1 - 1/(a + b*x)^2])/(2*b^4) - (a*(a + b*x)^2*Sqrt[1 - 1/(a + b*x)^2])/(2*b^4) + ((a + b*x)^3*Sqrt[1 - 1/(a + b*x)^2])/(12*b^4) - ((a^4 - b^4*x^4)*ArcCsc[a + b*x])/(4*b^4) - (a*ArcTanh[Sqrt[1 - 1/(a + b*x)^2]])/(2*b^4) - (a^3*ArcTanh[Sqrt[1 - 1/(a + b*x)^2]])/b^4}
{x^2*ArcCsc[a + b*x], x, 10, -((a*(a + b*x)*Sqrt[1 - 1/(a + b*x)^2])/b^3) + ((a + b*x)^2*Sqrt[1 - 1/(a + b*x)^2])/(6*b^3) + ((a^3 + b^3*x^3)*ArcCsc[a + b*x])/(3*b^3) + ArcTanh[Sqrt[1 - 1/(a + b*x)^2]]/(6*b^3) + (a^2*ArcTanh[Sqrt[1 - 1/(a + b*x)^2]])/b^3}
{x^1*ArcCsc[a + b*x], x, 6, ((a + b*x)*Sqrt[1 - 1/(a + b*x)^2])/(2*b^2) - ((a^2 - b^2*x^2)*ArcCsc[a + b*x])/(2*b^2) - (a*ArcTanh[Sqrt[1 - 1/(a + b*x)^2]])/b^2}
{x^0*ArcCsc[a + b*x], x, 4, ((a + b*x)*ArcCsc[a + b*x])/b + ArcTanh[Sqrt[1 - 1/(a + b*x)^2]]/b}
{ArcCsc[a + b*x]/x^1, x, 1, I*ArcCsc[a + b*x]^2 + ArcCsc[a + b*x]*Log[1 - (I*(1 - Sqrt[1 - a^2]))/(E^(I*ArcCsc[a + b*x])*a)] + ArcCsc[a + b*x]*Log[1 - (I*(1 + Sqrt[1 - a^2]))/(E^(I*ArcCsc[a + b*x])*a)] - ArcCsc[a + b*x]*Log[1 - E^(2*I*ArcCsc[a + b*x])] + I*PolyLog[2, (I*(1 - Sqrt[1 - a^2]))/(E^(I*ArcCsc[a + b*x])*a)] + I*PolyLog[2, (I*(1 + Sqrt[1 - a^2]))/(E^(I*ArcCsc[a + b*x])*a)] + (1/2)*I*PolyLog[2, E^(2*I*ArcCsc[a + b*x])]}
{ArcCsc[a + b*x]/x^2, x, 4, -(((b + a/x)*ArcCsc[a + b*x])/a) - (b*ArcTan[(a - 1/(a + b*x))/(Sqrt[1 - a^2]*Sqrt[1 - 1/(a + b*x)^2])])/(a*Sqrt[1 - a^2])}
{ArcCsc[a + b*x]/x^3, x, 6, -((b^2*Sqrt[1 - 1/(a + b*x)^2])/(2*a*(1 - a^2)*(1 - a/(a + b*x)))) + ((b^2 - a^2/x^2)*ArcCsc[a + b*x])/(2*a^2) + ((1 - 2*a^2)*b^2*ArcTan[(a - 1/(a + b*x))/(Sqrt[1 - a^2]*Sqrt[1 - 1/(a + b*x)^2])])/(2*a^2*(1 - a^2)^(3/2))}
(* {ArcCsc[a + b*x]/x^4, x, 0, 0} *)
{ArcCsc[a + b*x]/x^5, x, 15, -((b^4*Sqrt[1 - 1/(a + b*x)^2])/(12*a^3*(1 - a^2)*(1 - a/(a + b*x))^3)) - (5*b^4*Sqrt[1 - 1/(a + b*x)^2])/(24*a^3*(1 - a^2)^2*(1 - a/(a + b*x))^2) + (b^4*Sqrt[1 - 1/(a + b*x)^2])/(2*a^3*(1 - a^2)*(1 - a/(a + b*x))^2) + (3*b^4*Sqrt[1 - 1/(a + b*x)^2])/(2*a^3*(1 - a^2)^2*(1 - a/(a + b*x))) - (3*b^4*Sqrt[1 - 1/(a + b*x)^2])/(2*a^3*(1 - a^2)*(1 - a/(a + b*x))) - ((11 + 4*a^2)*b^4*Sqrt[1 - 1/(a + b*x)^2])/(24*a^3*(1 - a^2)^3*(1 - a/(a + b*x))) + ((b^4 - a^4/x^4)*ArcCsc[a + b*x])/(4*a^4) - (3*b^4*ArcTan[(a - 1/(a + b*x))/(Sqrt[1 - a^2]*Sqrt[1 - 1/(a + b*x)^2])])/(2*a^4*(1 - a^2)^(3/2)) + (b^4*ArcTan[(a - 1/(a + b*x))/(Sqrt[1 - a^2]*Sqrt[1 - 1/(a + b*x)^2])])/(a^4*Sqrt[1 - a^2]) + ((2 + a^2)*b^4*ArcTan[(a - 1/(a + b*x))/(Sqrt[1 - a^2]*Sqrt[1 - 1/(a + b*x)^2])])/(2*a^4*(1 - a^2)^(5/2)) - ((2 + 3*a^2)*b^4*ArcTan[(a - 1/(a + b*x))/(Sqrt[1 - a^2]*Sqrt[1 - 1/(a + b*x)^2])])/(8*a^4*(1 - a^2)^(7/2))}


{x^3*ArcCsc[a + b*x]^2, x, 19, -((a*(a + b*x))/b^4) + (a + b*x)^2/(12*b^4) + ((a + b*x)*Sqrt[1 - 1/(a + b*x)^2]*ArcCsc[a + b*x])/(3*b^4) + (3*a^2*(a + b*x)*Sqrt[1 - 1/(a + b*x)^2]*ArcCsc[a + b*x])/b^4 - (a*(a + b*x)^2*Sqrt[1 - 1/(a + b*x)^2]*ArcCsc[a + b*x])/b^4 + ((a + b*x)^3*Sqrt[1 - 1/(a + b*x)^2]*ArcCsc[a + b*x])/(6*b^4) - (a^3*(a + b*x)*ArcCsc[a + b*x]^2)/b^4 + (3*a^2*(a + b*x)^2*ArcCsc[a + b*x]^2)/(2*b^4) - (a*(a + b*x)^3*ArcCsc[a + b*x]^2)/b^4 + ((a + b*x)^4*ArcCsc[a + b*x]^2)/(4*b^4) - (2*a*ArcCsc[a + b*x]*ArcTanh[E^(I*ArcCsc[a + b*x])])/b^4 - (4*a^3*ArcCsc[a + b*x]*ArcTanh[E^(I*ArcCsc[a + b*x])])/b^4 - Log[1/(a + b*x)]/(3*b^4) - (3*a^2*Log[1/(a + b*x)])/b^4 + (I*a*PolyLog[2, -E^(I*ArcCsc[a + b*x])])/b^4 + (2*I*a^3*PolyLog[2, -E^(I*ArcCsc[a + b*x])])/b^4 - (I*a*PolyLog[2, E^(I*ArcCsc[a + b*x])])/b^4 - (2*I*a^3*PolyLog[2, E^(I*ArcCsc[a + b*x])])/b^4}
{x^2*ArcCsc[a + b*x]^2, x, 15, (a + b*x)/(3*b^3) - (2*a*(a + b*x)*Sqrt[1 - 1/(a + b*x)^2]*ArcCsc[a + b*x])/b^3 + ((a + b*x)^2*Sqrt[1 - 1/(a + b*x)^2]*ArcCsc[a + b*x])/(3*b^3) + (a^2*(a + b*x)*ArcCsc[a + b*x]^2)/b^3 - (a*(a + b*x)^2*ArcCsc[a + b*x]^2)/b^3 + ((a + b*x)^3*ArcCsc[a + b*x]^2)/(3*b^3) + (2*ArcCsc[a + b*x]*ArcTanh[E^(I*ArcCsc[a + b*x])])/(3*b^3) + (4*a^2*ArcCsc[a + b*x]*ArcTanh[E^(I*ArcCsc[a + b*x])])/b^3 + (2*a*Log[1/(a + b*x)])/b^3 - (I*PolyLog[2, -E^(I*ArcCsc[a + b*x])])/(3*b^3) - (2*I*a^2*PolyLog[2, -E^(I*ArcCsc[a + b*x])])/b^3 + (I*PolyLog[2, E^(I*ArcCsc[a + b*x])])/(3*b^3) + (2*I*a^2*PolyLog[2, E^(I*ArcCsc[a + b*x])])/b^3}
{x^1*ArcCsc[a + b*x]^2, x, 10, ((a + b*x)*Sqrt[1 - 1/(a + b*x)^2]*ArcCsc[a + b*x])/b^2 - (a*(a + b*x)*ArcCsc[a + b*x]^2)/b^2 + ((a + b*x)^2*ArcCsc[a + b*x]^2)/(2*b^2) - (4*a*ArcCsc[a + b*x]*ArcTanh[E^(I*ArcCsc[a + b*x])])/b^2 - Log[1/(a + b*x)]/b^2 + (2*I*a*PolyLog[2, -E^(I*ArcCsc[a + b*x])])/b^2 - (2*I*a*PolyLog[2, E^(I*ArcCsc[a + b*x])])/b^2}
{x^0*ArcCsc[a + b*x]^2, x, 5, ((a + b*x)*ArcCsc[a + b*x]^2)/b + (4*ArcCsc[a + b*x]*ArcTanh[E^(I*ArcCsc[a + b*x])])/b - (2*I*PolyLog[2, -E^(I*ArcCsc[a + b*x])])/b + (2*I*PolyLog[2, E^(I*ArcCsc[a + b*x])])/b}
{ArcCsc[a + b*x]^2/x^1, x, 0, Int[ArcCsc[a + b*x]^2/x, x]}
{ArcCsc[a + b*x]^2/x^2, x, 0, Int[ArcCsc[a + b*x]^2/x^2, x]}


{x^2*ArcCsc[a + b*x]^3, x, 23, ((a + b*x)*ArcCsc[a + b*x])/b^3 - (3*I*a*ArcCsc[a + b*x]^2)/b^3 - (3*a*(a + b*x)*Sqrt[1 - 1/(a + b*x)^2]*ArcCsc[a + b*x]^2)/b^3 + ((a + b*x)^2*Sqrt[1 - 1/(a + b*x)^2]*ArcCsc[a + b*x]^2)/(2*b^3) + (a^2*(a + b*x)*ArcCsc[a + b*x]^3)/b^3 - (a*(a + b*x)^2*ArcCsc[a + b*x]^3)/b^3 + ((a + b*x)^3*ArcCsc[a + b*x]^3)/(3*b^3) + (ArcCsc[a + b*x]^2*ArcTanh[E^(I*ArcCsc[a + b*x])])/b^3 + (6*a^2*ArcCsc[a + b*x]^2*ArcTanh[E^(I*ArcCsc[a + b*x])])/b^3 + ArcTanh[Sqrt[1 - 1/(a + b*x)^2]]/b^3 + (6*a*ArcCsc[a + b*x]*Log[1 - E^(2*I*ArcCsc[a + b*x])])/b^3 - (I*ArcCsc[a + b*x]*PolyLog[2, -E^(I*ArcCsc[a + b*x])])/b^3 - (6*I*a^2*ArcCsc[a + b*x]*PolyLog[2, -E^(I*ArcCsc[a + b*x])])/b^3 + (I*ArcCsc[a + b*x]*PolyLog[2, E^(I*ArcCsc[a + b*x])])/b^3 + (6*I*a^2*ArcCsc[a + b*x]*PolyLog[2, E^(I*ArcCsc[a + b*x])])/b^3 - (3*I*a*PolyLog[2, E^(2*I*ArcCsc[a + b*x])])/b^3 + PolyLog[3, -E^(I*ArcCsc[a + b*x])]/b^3 + (6*a^2*PolyLog[3, -E^(I*ArcCsc[a + b*x])])/b^3 - PolyLog[3, E^(I*ArcCsc[a + b*x])]/b^3 - (6*a^2*PolyLog[3, E^(I*ArcCsc[a + b*x])])/b^3}
{x^1*ArcCsc[a + b*x]^3, x, 15, (3*I*ArcCsc[a + b*x]^2)/(2*b^2) + (3*(a + b*x)*Sqrt[1 - 1/(a + b*x)^2]*ArcCsc[a + b*x]^2)/(2*b^2) - (a*(a + b*x)*ArcCsc[a + b*x]^3)/b^2 + ((a + b*x)^2*ArcCsc[a + b*x]^3)/(2*b^2) - (6*a*ArcCsc[a + b*x]^2*ArcTanh[E^(I*ArcCsc[a + b*x])])/b^2 - (3*ArcCsc[a + b*x]*Log[1 - E^(2*I*ArcCsc[a + b*x])])/b^2 + (6*I*a*ArcCsc[a + b*x]*PolyLog[2, -E^(I*ArcCsc[a + b*x])])/b^2 - (6*I*a*ArcCsc[a + b*x]*PolyLog[2, E^(I*ArcCsc[a + b*x])])/b^2 + (3*I*PolyLog[2, E^(2*I*ArcCsc[a + b*x])])/(2*b^2) - (6*a*PolyLog[3, -E^(I*ArcCsc[a + b*x])])/b^2 + (6*a*PolyLog[3, E^(I*ArcCsc[a + b*x])])/b^2}
{x^0*ArcCsc[a + b*x]^3, x, 7, ((a + b*x)*ArcCsc[a + b*x]^3)/b + (6*ArcCsc[a + b*x]^2*ArcTanh[E^(I*ArcCsc[a + b*x])])/b - (6*I*ArcCsc[a + b*x]*PolyLog[2, -E^(I*ArcCsc[a + b*x])])/b + (6*I*ArcCsc[a + b*x]*PolyLog[2, E^(I*ArcCsc[a + b*x])])/b + (6*PolyLog[3, -E^(I*ArcCsc[a + b*x])])/b - (6*PolyLog[3, E^(I*ArcCsc[a + b*x])])/b}
{ArcCsc[a + b*x]^3/x^1, x, 0, Int[ArcCsc[a + b*x]^3/x, x]}
{ArcCsc[a + b*x]^3/x^2, x, 0, Int[ArcCsc[a + b*x]^3/x^2, x]}


(* ::Subsubsection:: *)
(*n<0*)


(* ::Section::Closed:: *)
(*Integrands of the form u ArcCsc[a +b x^n]*)


{x^3*ArcCsc[a + b*x^4], x, 5, ((a + b*x^4)*ArcCsc[a + b*x^4])/(4*b) + ArcTanh[Sqrt[1 - 1/(a + b*x^4)^2]]/(4*b)}


{x^(n-1)*ArcCsc[a + b*x^n], x, 5, ((a + b*x^n)*ArcCsc[a + b*x^n])/(b*n) + ArcTanh[Sqrt[1 - 1/(a + b*x^n)^2]]/(b*n)}


(* ::Section::Closed:: *)
(*Integrands involving inverse trig functions of exponentials*)


{ArcCsc[c*E^(a + b*x)], x, 2, -((I*ArcCsc[c*E^(a + b*x)]^2)/(2*b)) - (ArcCsc[c*E^(a + b*x)]*Log[2/(1 - I*c*E^(a + b*x)*Sqrt[1 - E^(-2*a - 2*b*x)/c^2])])/b - (I*PolyLog[2, 1 - 2/(1 - I*c*E^(a + b*x)*Sqrt[1 - E^(-2*a - 2*b*x)/c^2])])/(2*b)}


(* ::Section::Closed:: *)
(*Integrands involving exponentials of inverse trig functions*)


(* Integrands of the form x^m*E^ArcCsc[x] where m is an integer *)
{E^ArcCsc[x], x, 0, Int[E^ArcCsc[x], x]}
{E^ArcCsc[x]/x, x, 0, Int[E^ArcCsc[x]/x, x]}
{E^ArcCsc[x]/x^2, x, 3, (-(1/2))*E^ArcCsc[x]*Sqrt[1 - 1/x^2] - E^ArcCsc[x]/(2*x)}
{E^ArcCsc[x]/x^3, x, 5, (1/5)*E^ArcCsc[x]*Cos[2*ArcCsc[x]] - (1/10)*E^ArcCsc[x]*Sin[2*ArcCsc[x]]}
{E^ArcCsc[x]/x^4, x, 6, (-(1/8))*E^ArcCsc[x]*Sqrt[1 - 1/x^2] - E^ArcCsc[x]/(8*x) + (1/40)*E^ArcCsc[x]*Cos[3*ArcCsc[x]] + (3/40)*E^ArcCsc[x]*Sin[3*ArcCsc[x]]}
{E^ArcCsc[x]/x^5, x, 6, (1/10)*E^ArcCsc[x]*Cos[2*ArcCsc[x]] - (1/34)*E^ArcCsc[x]*Cos[4*ArcCsc[x]] - (1/20)*E^ArcCsc[x]*Sin[2*ArcCsc[x]] + (1/136)*E^ArcCsc[x]*Sin[4*ArcCsc[x]]}


(* ::Section::Closed:: *)
(*Miscellaneous integrands involving inverse cosecants*)


{ArcCsc[a + b*x]/((a*d)/b + d*x), x, 3, -((I*ArcCsc[b*(a/b + x)]^2)/(2*d)) - (ArcCsc[b*(a/b + x)]*Log[2/(1 - I*b*(a/b + x)*Sqrt[1 - 1/(b^2*(a/b + x)^2)])])/d - (I*PolyLog[2, 1 - 2/(1 - I*b*(a/b + x)*Sqrt[1 - 1/(b^2*(a/b + x)^2)])])/(2*d)}
