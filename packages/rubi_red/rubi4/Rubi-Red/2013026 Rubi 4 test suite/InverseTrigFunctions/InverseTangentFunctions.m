(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Inverse Tangents*)


(* ::Section::Closed:: *)
(*Integrands of the form u ArcTan[a x^n]^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcTan[a x]^n*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{x^m*ArcTan[a*x], x, 3, (x^(1 + m)*ArcTan[a*x])/(1 + m) - (a*x^(2 + m)*Hypergeometric2F1[1, (2 + m)/2, (4 + m)/2, (-a^2)*x^2])/(2 + 3*m + m^2)}

{x^5*ArcTan[a*x], x, 3, -(x/(6*a^5)) + x^3/(18*a^3) - x^5/(30*a) + ArcTan[a*x]/(6*a^6) + (1/6)*x^6*ArcTan[a*x]}
{x^4*ArcTan[a*x], x, 4, x^2/(10*a^3) - x^4/(20*a) + (1/5)*x^5*ArcTan[a*x] - Log[1 + a^2*x^2]/(10*a^5)}
{x^3*ArcTan[a*x], x, 2, x/(4*a^3) - x^3/(12*a) - ArcTan[a*x]/(4*a^4) + (1/4)*x^4*ArcTan[a*x]}
{x^2*ArcTan[a*x], x, 3, -(x^2/(6*a)) + (1/3)*x^3*ArcTan[a*x] + Log[1 + a^2*x^2]/(6*a^3)}
{x^1*ArcTan[a*x], x, 1, -(x/(2*a)) + ArcTan[a*x]/(2*a^2) + (1/2)*x^2*ArcTan[a*x]}
{x^0*ArcTan[a*x], x, 2, x*ArcTan[a*x] - Log[1 + a^2*x^2]/(2*a)}
{ArcTan[a*x]/x^1, x, 3, (1/2)*I*PolyLog[2, (-I)*a*x] - (1/2)*I*PolyLog[2, I*a*x]}
{ArcTan[a*x]/x^2, x, 1, -(ArcTan[a*x]/x) - a*ArcTanh[1 + 2*a^2*x^2]}
{ArcTan[a*x]/x^3, x, 1, -(a/(2*x)) - (1/2)*a^2*ArcTan[a*x] - ArcTan[a*x]/(2*x^2)}
{ArcTan[a*x]/x^4, x, 2, -(a/(6*x^2)) - ArcTan[a*x]/(3*x^3) + (1/3)*a^3*ArcTanh[1 + 2*a^2*x^2]}
{ArcTan[a*x]/x^5, x, 2, -(a/(12*x^3)) + a^3/(4*x) + (1/4)*a^4*ArcTan[a*x] - ArcTan[a*x]/(4*x^4)}


{x^m*ArcTan[a*x]^2, x, 1, (x^(1 + m)*ArcTan[a*x]^2)/(1 + m) - (2*a*Int[(x^(1 + m)*ArcTan[a*x])/(1 + a^2*x^2), x])/(1 + m)}

{x^5*ArcTan[a*x]^2, x, 14, -((4*x^2)/(45*a^4)) + x^4/(60*a^2) - (x*ArcTan[a*x])/(3*a^5) + (x^3*ArcTan[a*x])/(9*a^3) - (x^5*ArcTan[a*x])/(15*a) + ArcTan[a*x]^2/(6*a^6) + (1/6)*x^6*ArcTan[a*x]^2 + (23*Log[1 + a^2*x^2])/(90*a^6)}
{x^4*ArcTan[a*x]^2, x, 9, -((3*x)/(10*a^4)) + x^3/(30*a^2) + (3*ArcTan[a*x])/(10*a^5) + (x^2*ArcTan[a*x])/(5*a^3) - (x^4*ArcTan[a*x])/(10*a) + (I*ArcTan[a*x]^2)/(5*a^5) + (1/5)*x^5*ArcTan[a*x]^2 + (2*ArcTan[a*x]*Log[(2*I)/(I - a*x)])/(5*a^5) + (I*PolyLog[2, -((I + a*x)/(I - a*x))])/(5*a^5)}
{x^3*ArcTan[a*x]^2, x, 9, x^2/(12*a^2) + (x*ArcTan[a*x])/(2*a^3) - (x^3*ArcTan[a*x])/(6*a) - ArcTan[a*x]^2/(4*a^4) + (1/4)*x^4*ArcTan[a*x]^2 - Log[1 + a^2*x^2]/(3*a^4)}
{x^2*ArcTan[a*x]^2, x, 6, x/(3*a^2) - ArcTan[a*x]/(3*a^3) - (x^2*ArcTan[a*x])/(3*a) - (I*ArcTan[a*x]^2)/(3*a^3) + (1/3)*x^3*ArcTan[a*x]^2 - (2*ArcTan[a*x]*Log[(2*I)/(I - a*x)])/(3*a^3) - (I*PolyLog[2, -((I + a*x)/(I - a*x))])/(3*a^3)}
{x^1*ArcTan[a*x]^2, x, 5, -((x*ArcTan[a*x])/a) + ArcTan[a*x]^2/(2*a^2) + (1/2)*x^2*ArcTan[a*x]^2 + Log[1 + a^2*x^2]/(2*a^2)}
{x^0*ArcTan[a*x]^2, x, 4, (I*ArcTan[a*x]^2)/a + x*ArcTan[a*x]^2 + (2*ArcTan[a*x]*Log[(2*I)/(I - a*x)])/a + (I*PolyLog[2, -((I + a*x)/(I - a*x))])/a}
{ArcTan[a*x]^2/x^1, x, 7, 2*ArcTan[a*x]^2*ArcTanh[1 - (2*I)/(I - a*x)] - I*ArcTan[a*x]*PolyLog[2, 1 - (2*I)/(I - a*x)] + I*ArcTan[a*x]*PolyLog[2, 1 + (2*a*x)/(I - a*x)] - (1/2)*PolyLog[3, 1 - (2*I)/(I - a*x)] + (1/2)*PolyLog[3, 1 + (2*a*x)/(I - a*x)]}
{ArcTan[a*x]^2/x^2, x, 4, (-I)*a*ArcTan[a*x]^2 - ArcTan[a*x]^2/x + 2*a*ArcTan[a*x]*Log[(2*a*x)/(I + a*x)] - I*a*PolyLog[2, 1 - (2*a*x)/(I + a*x)]}
{ArcTan[a*x]^2/x^3, x, 4, -((a*ArcTan[a*x])/x) - (1/2)*a^2*ArcTan[a*x]^2 - ArcTan[a*x]^2/(2*x^2) - a^2*ArcTanh[1 + 2*a^2*x^2]}
{ArcTan[a*x]^2/x^4, x, 6, -(a^2/(3*x)) - (1/3)*a^3*ArcTan[a*x] - (a*ArcTan[a*x])/(3*x^2) + (1/3)*I*a^3*ArcTan[a*x]^2 - ArcTan[a*x]^2/(3*x^3) - (2/3)*a^3*ArcTan[a*x]*Log[(2*a*x)/(I + a*x)] + (1/3)*I*a^3*PolyLog[2, 1 - (2*a*x)/(I + a*x)]}
{ArcTan[a*x]^2/x^5, x, 7, -(a^2/(12*x^2)) - (a*ArcTan[a*x])/(6*x^3) + (a^3*ArcTan[a*x])/(2*x) + (1/4)*a^4*ArcTan[a*x]^2 - ArcTan[a*x]^2/(4*x^4) + (2/3)*a^4*ArcTanh[1 + 2*a^2*x^2]}


{x^m*ArcTan[a*x]^3, x, 1, (x^(1 + m)*ArcTan[a*x]^3)/(1 + m) - (3*a*Int[(x^(1 + m)*ArcTan[a*x]^2)/(1 + a^2*x^2), x])/(1 + m)}

{x^5*ArcTan[a*x]^3, x, 24, (19*x)/(60*a^5) - x^3/(60*a^3) - (19*ArcTan[a*x])/(60*a^6) - (4*x^2*ArcTan[a*x])/(15*a^4) + (x^4*ArcTan[a*x])/(20*a^2) - (23*I*ArcTan[a*x]^2)/(30*a^6) - (x*ArcTan[a*x]^2)/(2*a^5) + (x^3*ArcTan[a*x]^2)/(6*a^3) - (x^5*ArcTan[a*x]^2)/(10*a) + ArcTan[a*x]^3/(6*a^6) + (1/6)*x^6*ArcTan[a*x]^3 - (23*ArcTan[a*x]*Log[(2*I)/(I - a*x)])/(15*a^6) - (23*I*PolyLog[2, -((I + a*x)/(I - a*x))])/(30*a^6)}
{x^4*ArcTan[a*x]^3, x, 21, -(x^2/(20*a^3)) - (9*x*ArcTan[a*x])/(10*a^4) + (x^3*ArcTan[a*x])/(10*a^2) + (9*ArcTan[a*x]^2)/(20*a^5) + (3*x^2*ArcTan[a*x]^2)/(10*a^3) - (3*x^4*ArcTan[a*x]^2)/(20*a) + (I*ArcTan[a*x]^3)/(5*a^5) + (1/5)*x^5*ArcTan[a*x]^3 + (3*ArcTan[a*x]^2*Log[(2*I)/(I - a*x)])/(5*a^5) + Log[1 + a^2*x^2]/(2*a^5) + (3*I*ArcTan[a*x]*PolyLog[2, 1 - (2*I)/(I - a*x)])/(5*a^5) + (3*PolyLog[3, 1 - (2*I)/(I - a*x)])/(10*a^5)}
{x^3*ArcTan[a*x]^3, x, 14, -(x/(4*a^3)) + ArcTan[a*x]/(4*a^4) + (x^2*ArcTan[a*x])/(4*a^2) + (I*ArcTan[a*x]^2)/a^4 + (3*x*ArcTan[a*x]^2)/(4*a^3) - (x^3*ArcTan[a*x]^2)/(4*a) - ArcTan[a*x]^3/(4*a^4) + (1/4)*x^4*ArcTan[a*x]^3 + (2*ArcTan[a*x]*Log[(2*I)/(I - a*x)])/a^4 + (I*PolyLog[2, -((I + a*x)/(I - a*x))])/a^4}
{x^2*ArcTan[a*x]^3, x, 11, (x*ArcTan[a*x])/a^2 - ArcTan[a*x]^2/(2*a^3) - (x^2*ArcTan[a*x]^2)/(2*a) - (I*ArcTan[a*x]^3)/(3*a^3) + (1/3)*x^3*ArcTan[a*x]^3 - (ArcTan[a*x]^2*Log[(2*I)/(I - a*x)])/a^3 - Log[1 + a^2*x^2]/(2*a^3) - (I*ArcTan[a*x]*PolyLog[2, 1 - (2*I)/(I - a*x)])/a^3 - PolyLog[3, 1 - (2*I)/(I - a*x)]/(2*a^3)}
{x^1*ArcTan[a*x]^3, x, 7, -((3*I*ArcTan[a*x]^2)/(2*a^2)) - (3*x*ArcTan[a*x]^2)/(2*a) + ArcTan[a*x]^3/(2*a^2) + (1/2)*x^2*ArcTan[a*x]^3 - (3*ArcTan[a*x]*Log[(2*I)/(I - a*x)])/a^2 - (3*I*PolyLog[2, -((I + a*x)/(I - a*x))])/(2*a^2)}
{x^0*ArcTan[a*x]^3, x, 5, (I*ArcTan[a*x]^3)/a + x*ArcTan[a*x]^3 + (3*ArcTan[a*x]^2*Log[(2*I)/(I - a*x)])/a + (3*I*ArcTan[a*x]*PolyLog[2, 1 - (2*I)/(I - a*x)])/a + (3*PolyLog[3, 1 - (2*I)/(I - a*x)])/(2*a)}
{ArcTan[a*x]^3/x^1, x, 9, 2*ArcTan[a*x]^3*ArcTanh[1 - (2*I)/(I - a*x)] - (3/2)*I*ArcTan[a*x]^2*PolyLog[2, 1 - (2*I)/(I - a*x)] + (3/2)*I*ArcTan[a*x]^2*PolyLog[2, 1 + (2*a*x)/(I - a*x)] - (3/2)*ArcTan[a*x]*PolyLog[3, 1 - (2*I)/(I - a*x)] + (3/2)*ArcTan[a*x]*PolyLog[3, 1 + (2*a*x)/(I - a*x)] + (3/4)*I*PolyLog[4, 1 - (2*I)/(I - a*x)] - (3/4)*I*PolyLog[4, 1 + (2*a*x)/(I - a*x)]}
{ArcTan[a*x]^3/x^2, x, 5, (-I)*a*ArcTan[a*x]^3 - ArcTan[a*x]^3/x + 3*a*ArcTan[a*x]^2*Log[(2*a*x)/(I + a*x)] - 3*I*a*ArcTan[a*x]*PolyLog[2, 1 - (2*a*x)/(I + a*x)] + (3/2)*a*PolyLog[3, 1 - (2*a*x)/(I + a*x)]}
{ArcTan[a*x]^3/x^3, x, 7, (-(3/2))*I*a^2*ArcTan[a*x]^2 - (3*a*ArcTan[a*x]^2)/(2*x) - (1/2)*a^2*ArcTan[a*x]^3 - ArcTan[a*x]^3/(2*x^2) + 3*a^2*ArcTan[a*x]*Log[(2*a*x)/(I + a*x)] - (3/2)*I*a^2*PolyLog[2, 1 - (2*a*x)/(I + a*x)]}
{ArcTan[a*x]^3/x^4, x, 10, -((a^2*ArcTan[a*x])/x) - (1/2)*a^3*ArcTan[a*x]^2 - (a*ArcTan[a*x]^2)/(2*x^2) + (1/3)*I*a^3*ArcTan[a*x]^3 - ArcTan[a*x]^3/(3*x^3) - a^3*ArcTanh[1 + 2*a^2*x^2] - a^3*ArcTan[a*x]^2*Log[(2*a*x)/(I + a*x)] + I*a^3*ArcTan[a*x]*PolyLog[2, 1 - (2*a*x)/(I + a*x)] - (1/2)*a^3*PolyLog[3, 1 - (2*a*x)/(I + a*x)]}
{ArcTan[a*x]^3/x^5, x, 14, -(a^3/(4*x)) - (1/4)*a^4*ArcTan[a*x] - (a^2*ArcTan[a*x])/(4*x^2) + I*a^4*ArcTan[a*x]^2 - (a*ArcTan[a*x]^2)/(4*x^3) + (3*a^3*ArcTan[a*x]^2)/(4*x) + (1/4)*a^4*ArcTan[a*x]^3 - ArcTan[a*x]^3/(4*x^4) - 2*a^4*ArcTan[a*x]*Log[(2*a*x)/(I + a*x)] + I*a^4*PolyLog[2, 1 - (2*a*x)/(I + a*x)]}


{Sqrt[x]*ArcTan[x], x, 10, -((4*Sqrt[x])/3) - (1/3)*Sqrt[2]*ArcTan[1 - Sqrt[2]*Sqrt[x]] + (1/3)*Sqrt[2]*ArcTan[1 + Sqrt[2]*Sqrt[x]] + (2/3)*x^(3/2)*ArcTan[x] - Log[1 - Sqrt[2]*Sqrt[x] + x]/(3*Sqrt[2]) + Log[1 + Sqrt[2]*Sqrt[x] + x]/(3*Sqrt[2])}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{x^2/ArcTan[a*x], x, 0, Defer[Int][x^2/ArcTan[a*x], x]}
{x^1/ArcTan[a*x], x, 0, Defer[Int][x/ArcTan[a*x], x]}
{x^0/ArcTan[a*x], x, 0, Defer[Int][ArcTan[a*x]^(-1), x]}
{1/(x^1*ArcTan[a*x]), x, 0, Defer[Int][1/(x*ArcTan[a*x]), x]}
{1/(x^2*ArcTan[a*x]), x, 0, Defer[Int][1/(x^2*ArcTan[a*x]), x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcTan[a x]^n / (1+a x)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{x^4*ArcTan[a*x]/(1 + a*x), x, 15, -(x/(4*a^4)) + x^2/(6*a^3) - x^3/(12*a^2) + ArcTan[a*x]/(4*a^5) - (x*ArcTan[a*x])/a^4 + (x^2*ArcTan[a*x])/(2*a^3) - (x^3*ArcTan[a*x])/(3*a^2) + (x^4*ArcTan[a*x])/(4*a) - (I*Log[1 + I*a*x]*Log[(1/2 - I/2)*(1 + a*x)])/(2*a^5) + (I*Log[1 - I*a*x]*Log[(1/2 + I/2)*(1 + a*x)])/(2*a^5) + Log[1 + a^2*x^2]/(3*a^5) + (I*PolyLog[2, (1/2 - I/2)*(1 - I*a*x)])/(2*a^5) - (I*PolyLog[2, (1/2 + I/2)*(1 + I*a*x)])/(2*a^5)}
{x^3*ArcTan[a*x]/(1 + a*x), x, 13, x/(2*a^3) - x^2/(6*a^2) - ArcTan[a*x]/(2*a^4) + (x*ArcTan[a*x])/a^3 - (x^2*ArcTan[a*x])/(2*a^2) + (x^3*ArcTan[a*x])/(3*a) + (I*Log[1 + I*a*x]*Log[(1/2 - I/2)*(1 + a*x)])/(2*a^4) - (I*Log[1 - I*a*x]*Log[(1/2 + I/2)*(1 + a*x)])/(2*a^4) - Log[1 + a^2*x^2]/(3*a^4) - (I*PolyLog[2, (1/2 - I/2)*(1 - I*a*x)])/(2*a^4) + (I*PolyLog[2, (1/2 + I/2)*(1 + I*a*x)])/(2*a^4)}
{x^2*ArcTan[a*x]/(1 + a*x), x, 10, -(x/(2*a^2)) + ArcTan[a*x]/(2*a^3) - (x*ArcTan[a*x])/a^2 + (x^2*ArcTan[a*x])/(2*a) - (I*Log[1 + I*a*x]*Log[(1/2 - I/2)*(1 + a*x)])/(2*a^3) + (I*Log[1 - I*a*x]*Log[(1/2 + I/2)*(1 + a*x)])/(2*a^3) + Log[1 + a^2*x^2]/(2*a^3) + (I*PolyLog[2, (1/2 - I/2)*(1 - I*a*x)])/(2*a^3) - (I*PolyLog[2, (1/2 + I/2)*(1 + I*a*x)])/(2*a^3)}
{x^1*ArcTan[a*x]/(1 + a*x), x, 9, (x*ArcTan[a*x])/a + (I*Log[1 + I*a*x]*Log[(1/2 - I/2)*(1 + a*x)])/(2*a^2) - (I*Log[1 - I*a*x]*Log[(1/2 + I/2)*(1 + a*x)])/(2*a^2) - Log[1 + a^2*x^2]/(2*a^2) - (I*PolyLog[2, (1/2 - I/2)*(1 - I*a*x)])/(2*a^2) + (I*PolyLog[2, (1/2 + I/2)*(1 + I*a*x)])/(2*a^2)}
{x^0*ArcTan[a*x]/(1 + a*x), x, 5, -((I*Log[1 + I*a*x]*Log[(1/2 - I/2)*(1 + a*x)])/(2*a)) + (I*Log[1 - I*a*x]*Log[(1/2 + I/2)*(1 + a*x)])/(2*a) + (I*PolyLog[2, (1/2 - I/2)*(1 - I*a*x)])/(2*a) - (I*PolyLog[2, (1/2 + I/2)*(1 + I*a*x)])/(2*a)}
{ArcTan[a*x]/(x^1*(1 + a*x)), x, 10, (1/2)*I*Log[1 + I*a*x]*Log[(1/2 - I/2)*(1 + a*x)] - (1/2)*I*Log[1 - I*a*x]*Log[(1/2 + I/2)*(1 + a*x)] + (1/2)*I*PolyLog[2, (-I)*a*x] - (1/2)*I*PolyLog[2, I*a*x] - (1/2)*I*PolyLog[2, (1/2 - I/2)*(1 - I*a*x)] + (1/2)*I*PolyLog[2, (1/2 + I/2)*(1 + I*a*x)]}
{ArcTan[a*x]/(x^2*(1 + a*x)), x, 11, -(ArcTan[a*x]/x) - a*ArcTanh[1 + 2*a^2*x^2] - (1/2)*I*a*Log[1 + I*a*x]*Log[(1/2 - I/2)*(1 + a*x)] + (1/2)*I*a*Log[1 - I*a*x]*Log[(1/2 + I/2)*(1 + a*x)] - (1/2)*I*a*PolyLog[2, (-I)*a*x] + (1/2)*I*a*PolyLog[2, I*a*x] + (1/2)*I*a*PolyLog[2, (1/2 - I/2)*(1 - I*a*x)] - (1/2)*I*a*PolyLog[2, (1/2 + I/2)*(1 + I*a*x)]}
{ArcTan[a*x]/(x^3*(1 + a*x)), x, 12, -(a/(2*x)) - (1/2)*a^2*ArcTan[a*x] - ArcTan[a*x]/(2*x^2) + (a*ArcTan[a*x])/x + a^2*ArcTanh[1 + 2*a^2*x^2] + (1/2)*I*a^2*Log[1 + I*a*x]*Log[(1/2 - I/2)*(1 + a*x)] - (1/2)*I*a^2*Log[1 - I*a*x]*Log[(1/2 + I/2)*(1 + a*x)] + (1/2)*I*a^2*PolyLog[2, (-I)*a*x] - (1/2)*I*a^2*PolyLog[2, I*a*x] - (1/2)*I*a^2*PolyLog[2, (1/2 - I/2)*(1 - I*a*x)] + (1/2)*I*a^2*PolyLog[2, (1/2 + I/2)*(1 + I*a*x)]}
{ArcTan[a*x]/(x^4*(1 + a*x)), x, 14, -(a/(6*x^2)) + a^2/(2*x) + (1/2)*a^3*ArcTan[a*x] - ArcTan[a*x]/(3*x^3) + (a*ArcTan[a*x])/(2*x^2) - (a^2*ArcTan[a*x])/x - (2/3)*a^3*ArcTanh[1 + 2*a^2*x^2] - (1/2)*I*a^3*Log[1 + I*a*x]*Log[(1/2 - I/2)*(1 + a*x)] + (1/2)*I*a^3*Log[1 - I*a*x]*Log[(1/2 + I/2)*(1 + a*x)] - (1/2)*I*a^3*PolyLog[2, (-I)*a*x] + (1/2)*I*a^3*PolyLog[2, I*a*x] + (1/2)*I*a^3*PolyLog[2, (1/2 - I/2)*(1 - I*a*x)] - (1/2)*I*a^3*PolyLog[2, (1/2 + I/2)*(1 + I*a*x)]}


(* ::Subsubsection:: *)
(*n<0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcTan[a x]^n / (1+a^2 x^2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{x^4*ArcTan[a*x]/(1 + a^2*x^2), x, 8, -(x^2/(6*a^3)) - (x*ArcTan[a*x])/a^4 + (x^3*ArcTan[a*x])/(3*a^2) + ArcTan[a*x]^2/(2*a^5) + (2*Log[1 + a^2*x^2])/(3*a^5)}
{x^3*ArcTan[a*x]/(1 + a^2*x^2), x, 5, -(x/(2*a^3)) + ArcTan[a*x]/(2*a^4) + (x^2*ArcTan[a*x])/(2*a^2) + (I*ArcTan[a*x]^2)/(2*a^4) + (ArcTan[a*x]*Log[(2*I)/(I - a*x)])/a^4 + (I*PolyLog[2, -((I + a*x)/(I - a*x))])/(2*a^4)}
{x^2*ArcTan[a*x]/(1 + a^2*x^2), x, 4, (x*ArcTan[a*x])/a^2 - ArcTan[a*x]^2/(2*a^3) - Log[1 + a^2*x^2]/(2*a^3)}
{x^1*ArcTan[a*x]/(1 + a^2*x^2), x, 3, -((I*ArcTan[a*x]^2)/(2*a^2)) - (ArcTan[a*x]*Log[(2*I)/(I - a*x)])/a^2 - (I*PolyLog[2, -((I + a*x)/(I - a*x))])/(2*a^2)}
{x^0*ArcTan[a*x]/(1 + a^2*x^2), x, 1, ArcTan[a*x]^2/(2*a)}
{ArcTan[a*x]/(x^1*(1 + a^2*x^2)), x, 3, (-(1/2))*I*ArcTan[a*x]^2 + ArcTan[a*x]*Log[(2*a*x)/(I + a*x)] - (1/2)*I*PolyLog[2, 1 - (2*a*x)/(I + a*x)]}
{ArcTan[a*x]/(x^2*(1 + a^2*x^2)), x, 3, -(ArcTan[a*x]/x) - (1/2)*a*ArcTan[a*x]^2 - a*ArcTanh[1 + 2*a^2*x^2]}
{ArcTan[a*x]/(x^3*(1 + a^2*x^2)), x, 5, -(a/(2*x)) - (1/2)*a^2*ArcTan[a*x] - ArcTan[a*x]/(2*x^2) + (1/2)*I*a^2*ArcTan[a*x]^2 - a^2*ArcTan[a*x]*Log[(2*a*x)/(I + a*x)] + (1/2)*I*a^2*PolyLog[2, 1 - (2*a*x)/(I + a*x)]}
{ArcTan[a*x]/(x^4*(1 + a^2*x^2)), x, 6, -(a/(6*x^2)) - ArcTan[a*x]/(3*x^3) + (a^2*ArcTan[a*x])/x + (1/2)*a^3*ArcTan[a*x]^2 + (4/3)*a^3*ArcTanh[1 + 2*a^2*x^2]}


{x^4*ArcTan[a*x]^2/(1 + a^2*x^2), x, 13, x/(3*a^4) - ArcTan[a*x]/(3*a^5) - (x^2*ArcTan[a*x])/(3*a^3) - (4*I*ArcTan[a*x]^2)/(3*a^5) - (x*ArcTan[a*x]^2)/a^4 + (x^3*ArcTan[a*x]^2)/(3*a^2) + ArcTan[a*x]^3/(3*a^5) - (8*ArcTan[a*x]*Log[(2*I)/(I - a*x)])/(3*a^5) - (4*I*PolyLog[2, -((I + a*x)/(I - a*x))])/(3*a^5)}
{x^3*ArcTan[a*x]^2/(1 + a^2*x^2), x, 10, -((x*ArcTan[a*x])/a^3) + ArcTan[a*x]^2/(2*a^4) + (x^2*ArcTan[a*x]^2)/(2*a^2) + (I*ArcTan[a*x]^3)/(3*a^4) + (ArcTan[a*x]^2*Log[(2*I)/(I - a*x)])/a^4 + Log[1 + a^2*x^2]/(2*a^4) + (I*ArcTan[a*x]*PolyLog[2, 1 - (2*I)/(I - a*x)])/a^4 + PolyLog[3, 1 - (2*I)/(I - a*x)]/(2*a^4)}
{x^2*ArcTan[a*x]^2/(1 + a^2*x^2), x, 6, (I*ArcTan[a*x]^2)/a^3 + (x*ArcTan[a*x]^2)/a^2 - ArcTan[a*x]^3/(3*a^3) + (2*ArcTan[a*x]*Log[(2*I)/(I - a*x)])/a^3 + (I*PolyLog[2, -((I + a*x)/(I - a*x))])/a^3}
{x^1*ArcTan[a*x]^2/(1 + a^2*x^2), x, 4, -((I*ArcTan[a*x]^3)/(3*a^2)) - (ArcTan[a*x]^2*Log[(2*I)/(I - a*x)])/a^2 - (I*ArcTan[a*x]*PolyLog[2, 1 - (2*I)/(I - a*x)])/a^2 - PolyLog[3, 1 - (2*I)/(I - a*x)]/(2*a^2)}
{x^0*ArcTan[a*x]^2/(1 + a^2*x^2), x, 1, ArcTan[a*x]^3/(3*a)}
{ArcTan[a*x]^2/(x^1*(1 + a^2*x^2)), x, 4, (-(1/3))*I*ArcTan[a*x]^3 + ArcTan[a*x]^2*Log[(2*a*x)/(I + a*x)] - I*ArcTan[a*x]*PolyLog[2, 1 - (2*a*x)/(I + a*x)] + (1/2)*PolyLog[3, 1 - (2*a*x)/(I + a*x)]}
{ArcTan[a*x]^2/(x^2*(1 + a^2*x^2)), x, 6, (-I)*a*ArcTan[a*x]^2 - ArcTan[a*x]^2/x - (1/3)*a*ArcTan[a*x]^3 + 2*a*ArcTan[a*x]*Log[(2*a*x)/(I + a*x)] - I*a*PolyLog[2, 1 - (2*a*x)/(I + a*x)]}
{ArcTan[a*x]^2/(x^3*(1 + a^2*x^2)), x, 9, -((a*ArcTan[a*x])/x) - (1/2)*a^2*ArcTan[a*x]^2 - ArcTan[a*x]^2/(2*x^2) + (1/3)*I*a^2*ArcTan[a*x]^3 - a^2*ArcTanh[1 + 2*a^2*x^2] - a^2*ArcTan[a*x]^2*Log[(2*a*x)/(I + a*x)] + I*a^2*ArcTan[a*x]*PolyLog[2, 1 - (2*a*x)/(I + a*x)] - (1/2)*a^2*PolyLog[3, 1 - (2*a*x)/(I + a*x)]}
{ArcTan[a*x]^2/(x^4*(1 + a^2*x^2)), x, 13, -(a^2/(3*x)) - (1/3)*a^3*ArcTan[a*x] - (a*ArcTan[a*x])/(3*x^2) + (4/3)*I*a^3*ArcTan[a*x]^2 - ArcTan[a*x]^2/(3*x^3) + (a^2*ArcTan[a*x]^2)/x + (1/3)*a^3*ArcTan[a*x]^3 - (8/3)*a^3*ArcTan[a*x]*Log[(2*a*x)/(I + a*x)] + (4/3)*I*a^3*PolyLog[2, 1 - (2*a*x)/(I + a*x)]}


{x^4*ArcTan[a*x]^3/(1 + a^2*x^2), x, 19, (x*ArcTan[a*x])/a^4 - ArcTan[a*x]^2/(2*a^5) - (x^2*ArcTan[a*x]^2)/(2*a^3) - (4*I*ArcTan[a*x]^3)/(3*a^5) - (x*ArcTan[a*x]^3)/a^4 + (x^3*ArcTan[a*x]^3)/(3*a^2) + ArcTan[a*x]^4/(4*a^5) - (4*ArcTan[a*x]^2*Log[(2*I)/(I - a*x)])/a^5 - Log[1 + a^2*x^2]/(2*a^5) - (4*I*ArcTan[a*x]*PolyLog[2, 1 - (2*I)/(I - a*x)])/a^5 - (2*PolyLog[3, 1 - (2*I)/(I - a*x)])/a^5}
{x^3*ArcTan[a*x]^3/(1 + a^2*x^2), x, 13, -((3*I*ArcTan[a*x]^2)/(2*a^4)) - (3*x*ArcTan[a*x]^2)/(2*a^3) + ArcTan[a*x]^3/(2*a^4) + (x^2*ArcTan[a*x]^3)/(2*a^2) + (I*ArcTan[a*x]^4)/(4*a^4) - (3*ArcTan[a*x]*Log[(2*I)/(I - a*x)])/a^4 + (ArcTan[a*x]^3*Log[(2*I)/(I - a*x)])/a^4 - (3*I*PolyLog[2, -((I + a*x)/(I - a*x))])/(2*a^4) + (3*I*ArcTan[a*x]^2*PolyLog[2, 1 - (2*I)/(I - a*x)])/(2*a^4) + (3*ArcTan[a*x]*PolyLog[3, 1 - (2*I)/(I - a*x)])/(2*a^4) - (3*I*PolyLog[4, 1 - (2*I)/(I - a*x)])/(4*a^4)}
{x^2*ArcTan[a*x]^3/(1 + a^2*x^2), x, 7, (I*ArcTan[a*x]^3)/a^3 + (x*ArcTan[a*x]^3)/a^2 - ArcTan[a*x]^4/(4*a^3) + (3*ArcTan[a*x]^2*Log[(2*I)/(I - a*x)])/a^3 + (3*I*ArcTan[a*x]*PolyLog[2, 1 - (2*I)/(I - a*x)])/a^3 + (3*PolyLog[3, 1 - (2*I)/(I - a*x)])/(2*a^3)}
{x^1*ArcTan[a*x]^3/(1 + a^2*x^2), x, 5, -((I*ArcTan[a*x]^4)/(4*a^2)) - (ArcTan[a*x]^3*Log[(2*I)/(I - a*x)])/a^2 - (3*I*ArcTan[a*x]^2*PolyLog[2, 1 - (2*I)/(I - a*x)])/(2*a^2) - (3*ArcTan[a*x]*PolyLog[3, 1 - (2*I)/(I - a*x)])/(2*a^2) + (3*I*PolyLog[4, 1 - (2*I)/(I - a*x)])/(4*a^2)}
{x^0*ArcTan[a*x]^3/(1 + a^2*x^2), x, 1, ArcTan[a*x]^4/(4*a)}
{ArcTan[a*x]^3/(x^1*(1 + a^2*x^2)), x, 5, (-(1/4))*I*ArcTan[a*x]^4 + ArcTan[a*x]^3*Log[(2*a*x)/(I + a*x)] - (3/2)*I*ArcTan[a*x]^2*PolyLog[2, 1 - (2*a*x)/(I + a*x)] + (3/2)*ArcTan[a*x]*PolyLog[3, 1 - (2*a*x)/(I + a*x)] + (3/4)*I*PolyLog[4, 1 - (2*a*x)/(I + a*x)]}
{ArcTan[a*x]^3/(x^2*(1 + a^2*x^2)), x, 7, (-I)*a*ArcTan[a*x]^3 - ArcTan[a*x]^3/x - (1/4)*a*ArcTan[a*x]^4 + 3*a*ArcTan[a*x]^2*Log[(2*a*x)/(I + a*x)] - 3*I*a*ArcTan[a*x]*PolyLog[2, 1 - (2*a*x)/(I + a*x)] + (3/2)*a*PolyLog[3, 1 - (2*a*x)/(I + a*x)]}
{ArcTan[a*x]^3/(x^3*(1 + a^2*x^2)), x, 13, (-(3/2))*I*a^2*ArcTan[a*x]^2 - (3*a*ArcTan[a*x]^2)/(2*x) - (1/2)*a^2*ArcTan[a*x]^3 - ArcTan[a*x]^3/(2*x^2) + (1/4)*I*a^2*ArcTan[a*x]^4 + 3*a^2*ArcTan[a*x]*Log[(2*a*x)/(I + a*x)] - a^2*ArcTan[a*x]^3*Log[(2*a*x)/(I + a*x)] - (3/2)*I*a^2*PolyLog[2, 1 - (2*a*x)/(I + a*x)] + (3/2)*I*a^2*ArcTan[a*x]^2*PolyLog[2, 1 - (2*a*x)/(I + a*x)] - (3/2)*a^2*ArcTan[a*x]*PolyLog[3, 1 - (2*a*x)/(I + a*x)] - (3/4)*I*a^2*PolyLog[4, 1 - (2*a*x)/(I + a*x)]}
{ArcTan[a*x]^3/(x^4*(1 + a^2*x^2)), x, 18, -((a^2*ArcTan[a*x])/x) - (1/2)*a^3*ArcTan[a*x]^2 - (a*ArcTan[a*x]^2)/(2*x^2) + (4/3)*I*a^3*ArcTan[a*x]^3 - ArcTan[a*x]^3/(3*x^3) + (a^2*ArcTan[a*x]^3)/x + (1/4)*a^3*ArcTan[a*x]^4 - a^3*ArcTanh[1 + 2*a^2*x^2] - 4*a^3*ArcTan[a*x]^2*Log[(2*a*x)/(I + a*x)] + 4*I*a^3*ArcTan[a*x]*PolyLog[2, 1 - (2*a*x)/(I + a*x)] - 2*a^3*PolyLog[3, 1 - (2*a*x)/(I + a*x)]}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{x^2/((1 + a^2*x^2)*ArcTan[a*x]^3), x, 1, -(x^2/(2*a*ArcTan[a*x]^2)) + Defer[Int][x/ArcTan[a*x]^2, x]/a}
{x^1/((1 + a^2*x^2)*ArcTan[a*x]^3), x, 1, -x/(2*a*ArcTan[a*x]^2) + Defer[Int][ArcTan[a*x]^(-2), x]/(2*a)}
{x^0/((1 + a^2*x^2)*ArcTan[a*x]^3), x, 1, -(1/(2*a*ArcTan[a*x]^2))}
{1/(x^1*(1 + a^2*x^2)*ArcTan[a*x]^3), x, 1, -(1/(2*a*x*ArcTan[a*x]^2)) - Defer[Int][1/(x^2*ArcTan[a*x]^2), x]/(2*a)}
{1/(x^2*(1 + a^2*x^2)*ArcTan[a*x]^3), x, 1, -(1/(2*a*x^2*ArcTan[a*x]^2)) - Defer[Int][1/(x^3*ArcTan[a*x]^2), x]/a}


{x^3/((1 + a^2*x^2)*ArcTan[a*x]^3) - (3*x^2)/(2*a*ArcTan[a*x]^2), x, 2, -(x^3/(2*a*ArcTan[a*x]^2))}


{1/((1 + x^2)*ArcTan[x]), x, 1, Log[ArcTan[x]]}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{ArcTan[x]^n/(1 + x^2), x, 1, ArcTan[x]^(1 + n)/(1 + n)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcTan[a x]^p / (1+x^2)*)


{x^4*ArcTan[c*x]/(1 + x^2), x, 20, -(x^2/(6*c)) - x*ArcTan[c*x] + (1/3)*x^3*ArcTan[c*x] + (1/4)*Log[-((I*c*(I - x))/(1 + c))]*Log[1 - I*c*x] - (1/4)*Log[(I*c*(I + x))/(1 - c)]*Log[1 - I*c*x] - (1/4)*Log[(I*c*(I - x))/(1 - c)]*Log[1 + I*c*x] + (1/4)*Log[-((I*c*(I + x))/(1 + c))]*Log[1 + I*c*x] + Log[1 + c^2*x^2]/(6*c^3) + Log[1 + c^2*x^2]/(2*c) - (1/4)*PolyLog[2, (1 - I*c*x)/(1 - c)] + (1/4)*PolyLog[2, (1 - I*c*x)/(1 + c)] - (1/4)*PolyLog[2, (1 + I*c*x)/(1 - c)] + (1/4)*PolyLog[2, (1 + I*c*x)/(1 + c)]}
{x^3*ArcTan[c*x]/(1 + x^2), x, 14, -(x/(2*c)) + ArcTan[c*x]/(2*c^2) + (1/2)*x^2*ArcTan[c*x] - (1/4)*I*Log[-((I*c*(I - x))/(1 + c))]*Log[1 - I*c*x] - (1/4)*I*Log[(I*c*(I + x))/(1 - c)]*Log[1 - I*c*x] + (1/4)*I*Log[(I*c*(I - x))/(1 - c)]*Log[1 + I*c*x] + (1/4)*I*Log[-((I*c*(I + x))/(1 + c))]*Log[1 + I*c*x] - (1/4)*I*PolyLog[2, (1 - I*c*x)/(1 - c)] - (1/4)*I*PolyLog[2, (1 - I*c*x)/(1 + c)] + (1/4)*I*PolyLog[2, (1 + I*c*x)/(1 - c)] + (1/4)*I*PolyLog[2, (1 + I*c*x)/(1 + c)]}
{x^2*ArcTan[c*x]/(1 + x^2), x, 17, x*ArcTan[c*x] - (1/4)*Log[-((I*c*(I - x))/(1 + c))]*Log[1 - I*c*x] + (1/4)*Log[(I*c*(I + x))/(1 - c)]*Log[1 - I*c*x] + (1/4)*Log[(I*c*(I - x))/(1 - c)]*Log[1 + I*c*x] - (1/4)*Log[-((I*c*(I + x))/(1 + c))]*Log[1 + I*c*x] - Log[1 + c^2*x^2]/(2*c) + (1/4)*PolyLog[2, (1 - I*c*x)/(1 - c)] - (1/4)*PolyLog[2, (1 - I*c*x)/(1 + c)] + (1/4)*PolyLog[2, (1 + I*c*x)/(1 - c)] - (1/4)*PolyLog[2, (1 + I*c*x)/(1 + c)]}
{x^1*ArcTan[c*x]/(1 + x^2), x, 11, (1/4)*I*Log[-((I*c*(I - x))/(1 + c))]*Log[1 - I*c*x] + (1/4)*I*Log[(I*c*(I + x))/(1 - c)]*Log[1 - I*c*x] - (1/4)*I*Log[(I*c*(I - x))/(1 - c)]*Log[1 + I*c*x] - (1/4)*I*Log[-((I*c*(I + x))/(1 + c))]*Log[1 + I*c*x] + (1/4)*I*PolyLog[2, (1 - I*c*x)/(1 - c)] + (1/4)*I*PolyLog[2, (1 - I*c*x)/(1 + c)] - (1/4)*I*PolyLog[2, (1 + I*c*x)/(1 - c)] - (1/4)*I*PolyLog[2, (1 + I*c*x)/(1 + c)]}
{x^0*ArcTan[c*x]/(1 + x^2), x, 13, (1/4)*Log[-((I*c*(I - x))/(1 + c))]*Log[1 - I*c*x] - (1/4)*Log[(I*c*(I + x))/(1 - c)]*Log[1 - I*c*x] - (1/4)*Log[(I*c*(I - x))/(1 - c)]*Log[1 + I*c*x] + (1/4)*Log[-((I*c*(I + x))/(1 + c))]*Log[1 + I*c*x] - (1/4)*PolyLog[2, (1 - I*c*x)/(1 - c)] + (1/4)*PolyLog[2, (1 - I*c*x)/(1 + c)] - (1/4)*PolyLog[2, (1 + I*c*x)/(1 - c)] + (1/4)*PolyLog[2, (1 + I*c*x)/(1 + c)]}
{ArcTan[c*x]/(x^1*(1 + x^2)), x, 16, (-(1/4))*I*Log[-((I*c*(I - x))/(1 + c))]*Log[1 - I*c*x] - (1/4)*I*Log[(I*c*(I + x))/(1 - c)]*Log[1 - I*c*x] + (1/4)*I*Log[(I*c*(I - x))/(1 - c)]*Log[1 + I*c*x] + (1/4)*I*Log[-((I*c*(I + x))/(1 + c))]*Log[1 + I*c*x] + (1/2)*I*PolyLog[2, (-I)*c*x] - (1/2)*I*PolyLog[2, I*c*x] - (1/4)*I*PolyLog[2, (1 - I*c*x)/(1 - c)] - (1/4)*I*PolyLog[2, (1 - I*c*x)/(1 + c)] + (1/4)*I*PolyLog[2, (1 + I*c*x)/(1 - c)] + (1/4)*I*PolyLog[2, (1 + I*c*x)/(1 + c)]}
{ArcTan[c*x]/(x^2*(1 + x^2)), x, 16, -(ArcTan[c*x]/x) - c*ArcTanh[1 + 2*c^2*x^2] - (1/4)*Log[-((I*c*(I - x))/(1 + c))]*Log[1 - I*c*x] + (1/4)*Log[(I*c*(I + x))/(1 - c)]*Log[1 - I*c*x] + (1/4)*Log[(I*c*(I - x))/(1 - c)]*Log[1 + I*c*x] - (1/4)*Log[-((I*c*(I + x))/(1 + c))]*Log[1 + I*c*x] + (1/4)*PolyLog[2, (1 - I*c*x)/(1 - c)] - (1/4)*PolyLog[2, (1 - I*c*x)/(1 + c)] + (1/4)*PolyLog[2, (1 + I*c*x)/(1 - c)] - (1/4)*PolyLog[2, (1 + I*c*x)/(1 + c)]}
{ArcTan[c*x]/(x^3*(1 + x^2)), x, 17, -(c/(2*x)) - (1/2)*c^2*ArcTan[c*x] - ArcTan[c*x]/(2*x^2) + (1/4)*I*Log[-((I*c*(I - x))/(1 + c))]*Log[1 - I*c*x] + (1/4)*I*Log[(I*c*(I + x))/(1 - c)]*Log[1 - I*c*x] - (1/4)*I*Log[(I*c*(I - x))/(1 - c)]*Log[1 + I*c*x] - (1/4)*I*Log[-((I*c*(I + x))/(1 + c))]*Log[1 + I*c*x] - (1/2)*I*PolyLog[2, (-I)*c*x] + (1/2)*I*PolyLog[2, I*c*x] + (1/4)*I*PolyLog[2, (1 - I*c*x)/(1 - c)] + (1/4)*I*PolyLog[2, (1 - I*c*x)/(1 + c)] - (1/4)*I*PolyLog[2, (1 + I*c*x)/(1 - c)] - (1/4)*I*PolyLog[2, (1 + I*c*x)/(1 + c)]}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcTan[a x] (c+d x^2)^p*)


{x^5*ArcTan[x]/(1 + x^2)^2, x, 13, -(x/2) + x/(4*(1 + x^2)) + (3*ArcTan[x])/4 + (1/2)*x^2*ArcTan[x] - ArcTan[x]/(2*(1 + x^2)) + I*ArcTan[x]^2 + 2*ArcTan[x]*Log[(2*I)/(I - x)] + I*PolyLog[2, -((I + x)/(I - x))]}
{x^4*ArcTan[x]/(1 + x^2)^2, x, 9, 1/(4*(1 + x^2)) + x*ArcTan[x] + (x*ArcTan[x])/(2*(1 + x^2)) - (3*ArcTan[x]^2)/4 - (1/2)*Log[1 + x^2]}
{x^3*ArcTan[x]/(1 + x^2)^2, x, 7, -(x/(4*(1 + x^2))) - ArcTan[x]/4 + ArcTan[x]/(2*(1 + x^2)) - (1/2)*I*ArcTan[x]^2 - ArcTan[x]*Log[(2*I)/(I - x)] - (1/2)*I*PolyLog[2, -((I + x)/(I - x))]}
{x^2*ArcTan[x]/(1 + x^2)^2, x, 4, -(1/(4*(1 + x^2))) - (x*ArcTan[x])/(2*(1 + x^2)) + ArcTan[x]^2/4}
{x^1*ArcTan[x]/(1 + x^2)^2, x, 3, x/(4*(1 + x^2)) + ArcTan[x]/4 - ArcTan[x]/(2*(1 + x^2))}
{x^0*ArcTan[x]/(1 + x^2)^2, x, 2, 1/(4*(1 + x^2)) + (x*ArcTan[x])/(2*(1 + x^2)) + ArcTan[x]^2/4}
{ArcTan[x]/(x^1*(1 + x^2)^2), x, 7, -(x/(4*(1 + x^2))) - ArcTan[x]/4 + ArcTan[x]/(2*(1 + x^2)) - (1/2)*I*ArcTan[x]^2 + ArcTan[x]*Log[(2*x)/(I + x)] - (1/2)*I*PolyLog[2, 1 - (2*x)/(I + x)]}
{ArcTan[x]/(x^2*(1 + x^2)^2), x, 6, -(1/(4*(1 + x^2))) - ArcTan[x]/x - (x*ArcTan[x])/(2*(1 + x^2)) - (3*ArcTan[x]^2)/4 - ArcTanh[1 + 2*x^2]}
{ArcTan[x]/(x^3*(1 + x^2)^2), x, 13, -(1/(2*x)) + x/(4*(1 + x^2)) - ArcTan[x]/4 - ArcTan[x]/(2*x^2) - ArcTan[x]/(2*(1 + x^2)) + I*ArcTan[x]^2 - 2*ArcTan[x]*Log[(2*x)/(I + x)] + I*PolyLog[2, 1 - (2*x)/(I + x)]}
{ArcTan[x]/(x^4*(1 + x^2)^2), x, 13, -(1/(6*x^2)) + 1/(4*(1 + x^2)) - ArcTan[x]/(3*x^3) + (2*ArcTan[x])/x + (x*ArcTan[x])/(2*(1 + x^2)) + (5*ArcTan[x]^2)/4 + (7/3)*ArcTanh[1 + 2*x^2]}


{x^1*ArcTan[x]/(1 + x^2)^3, x, 4, x/(16*(1 + x^2)^2) + (3*x)/(32*(1 + x^2)) + (3*ArcTan[x])/32 - ArcTan[x]/(4*(1 + x^2)^2)}


{ArcTan[x]*(a + b*x^2)^(3/2), x, 0, Int[(a + b*x^2)^(3/2)*ArcTan[x], x]}
{ArcTan[x]*(a + b*x^2)^(1/2), x, 0, Int[Sqrt[a + b*x^2]*ArcTan[x], x]}
{ArcTan[x]/(a + b*x^2)^(1/2), x, 0, Int[ArcTan[x]/Sqrt[a + b*x^2], x]}
{ArcTan[x]/(a + b*x^2)^(3/2), x, 4, (x*ArcTan[x])/(a*Sqrt[a + b*x^2]) + ArcTanh[Sqrt[a + b*x^2]/Sqrt[a - b]]/(a*Sqrt[a - b])}
{ArcTan[x]/(a + b*x^2)^(5/2), x, 5, -(1/(3*a*(a - b)*Sqrt[a + b*x^2])) + (x*ArcTan[x])/(3*a*(a + b*x^2)^(3/2)) + (2*x*ArcTan[x])/(3*a^2*Sqrt[a + b*x^2]) + ((3*a - 2*b)*ArcTanh[Sqrt[a + b*x^2]/Sqrt[a - b]])/(3*a^2*(a - b)^(3/2))}
{ArcTan[x]/(a + b*x^2)^(7/2), x, 7, -(1/(15*a*(a - b)*(a + b*x^2)^(3/2))) - (7*a - 4*b)/(15*a^2*(a - b)^2*Sqrt[a + b*x^2]) + (x*ArcTan[x])/(5*a*(a + b*x^2)^(5/2)) + (4*x*ArcTan[x])/(15*a^2*(a + b*x^2)^(3/2)) + (8*x*ArcTan[x])/(15*a^3*Sqrt[a + b*x^2]) + ((15*a^2 - 20*a*b + 8*b^2)*ArcTanh[Sqrt[a + b*x^2]/Sqrt[a - b]])/(15*a^3*(a - b)^(5/2))}

{ArcTan[x]*(a + a*x^2)^(1/2), x, 3, (-(1/2))*Sqrt[a + a*x^2] + (1/2)*x*Sqrt[a + a*x^2]*ArcTan[x] - (I*a*Sqrt[1 + x^2]*ArcTan[Sqrt[1 + I*x]/Sqrt[1 - I*x]]*ArcTan[x])/Sqrt[a + a*x^2] + (I*a*Sqrt[1 + x^2]*PolyLog[2, -((I*Sqrt[1 + I*x])/Sqrt[1 - I*x])])/(2*Sqrt[a + a*x^2]) - (I*a*Sqrt[1 + x^2]*PolyLog[2, (I*Sqrt[1 + I*x])/Sqrt[1 - I*x]])/(2*Sqrt[a + a*x^2])}
{ArcTan[x]/(a + a*x^2)^(1/2), x, 2, -((2*I*Sqrt[1 + x^2]*ArcTan[Sqrt[1 + I*x]/Sqrt[1 - I*x]]*ArcTan[x])/Sqrt[a + a*x^2]) + (I*Sqrt[1 + x^2]*PolyLog[2, -((I*Sqrt[1 + I*x])/Sqrt[1 - I*x])])/Sqrt[a + a*x^2] - (I*Sqrt[1 + x^2]*PolyLog[2, (I*Sqrt[1 + I*x])/Sqrt[1 - I*x]])/Sqrt[a + a*x^2]}
{ArcTan[x]/(a + a*x^2)^(3/2), x, 1, 1/(a*Sqrt[a + a*x^2]) + (x*ArcTan[x])/(a*Sqrt[a + a*x^2])}
{ArcTan[x]/(a + a*x^2)^(5/2), x, 2, 1/(9*a*(a + a*x^2)^(3/2)) + 2/(3*a^2*Sqrt[a + a*x^2]) + (x*ArcTan[x])/(3*a*(a + a*x^2)^(3/2)) + (2*x*ArcTan[x])/(3*a^2*Sqrt[a + a*x^2])}
{ArcTan[x]/(a + a*x^2)^(7/2), x, 3, 1/(25*a*(a + a*x^2)^(5/2)) + 4/(45*a^2*(a + a*x^2)^(3/2)) + 8/(15*a^3*Sqrt[a + a*x^2]) + (x*ArcTan[x])/(5*a*(a + a*x^2)^(5/2)) + (4*x*ArcTan[x])/(15*a^2*(a + a*x^2)^(3/2)) + (8*x*ArcTan[x])/(15*a^3*Sqrt[a + a*x^2])}


{ArcTan[x]^2/(1 + x^2)^2, x, 4, -(x/(4*(1 + x^2))) - ArcTan[x]/4 + ArcTan[x]/(2*(1 + x^2)) + (x*ArcTan[x]^2)/(2*(1 + x^2)) + ArcTan[x]^3/6}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcTan[a x^n]*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{x^5*ArcTan[a*x^2], x, 4, -(x^4/(12*a)) + (1/6)*x^6*ArcTan[a*x^2] + Log[1 + a^2*x^4]/(12*a^3)}
{x^4*ArcTan[a*x^2], x, 6, -((2*x^3)/(15*a)) + (1/5)*(-(1/a^2))^(7/4)*a*ArcTan[x/(-(1/a^2))^(1/4)] + (1/5)*x^5*ArcTan[a*x^2] - (1/5)*(-(1/a^2))^(7/4)*a*ArcTanh[x/(-(1/a^2))^(1/4)]}
{x^3*ArcTan[a*x^2], x, 2, -(x^2/(4*a)) + ArcTan[a*x^2]/(4*a^2) + (1/4)*x^4*ArcTan[a*x^2]}
{x^2*ArcTan[a*x^2], x, 6, -((2*x)/(3*a)) - (1/3)*(-(1/a^2))^(5/4)*a*ArcTan[x/(-(1/a^2))^(1/4)] + (1/3)*x^3*ArcTan[a*x^2] - (1/3)*(-(1/a^2))^(5/4)*a*ArcTanh[x/(-(1/a^2))^(1/4)]}
{x^1*ArcTan[a*x^2], x, 3, (1/2)*x^2*ArcTan[a*x^2] - Log[1 + a^2*x^4]/(4*a)}
{x^0*ArcTan[a*x^2], x, 5, (-(1/a^2))^(3/4)*a*ArcTan[x/(-(1/a^2))^(1/4)] + x*ArcTan[a*x^2] - (-(1/a^2))^(3/4)*a*ArcTanh[x/(-(1/a^2))^(1/4)]}
{ArcTan[a*x^2]/x^1, x, 3, (1/4)*I*PolyLog[2, (-I)*a*x^2] - (1/4)*I*PolyLog[2, I*a*x^2]}
{ArcTan[a*x^2]/x^2, x, 5, (-(1/a^2))^(1/4)*a*ArcTan[x/(-(1/a^2))^(1/4)] - ArcTan[a*x^2]/x + (-(1/a^2))^(1/4)*a*ArcTanh[x/(-(1/a^2))^(1/4)]}
{ArcTan[a*x^2]/x^3, x, 2, -(ArcTan[a*x^2]/(2*x^2)) - (1/2)*a*ArcTanh[1 + 2*a^2*x^4]}
{ArcTan[a*x^2]/x^4, x, 6, -((2*a)/(3*x)) - (a*ArcTan[x/(-(1/a^2))^(1/4)])/(3*(-(1/a^2))^(1/4)) - ArcTan[a*x^2]/(3*x^3) + (a*ArcTanh[x/(-(1/a^2))^(1/4)])/(3*(-(1/a^2))^(1/4))}
{ArcTan[a*x^2]/x^5, x, 2, -(a/(4*x^2)) - (1/4)*a^2*ArcTan[a*x^2] - ArcTan[a*x^2]/(4*x^4)}


{x^5*ArcTan[a*x^3], x, 2, -(x^3/(6*a)) + ArcTan[a*x^3]/(6*a^2) + (1/6)*x^6*ArcTan[a*x^3]}
{x^4*ArcTan[a*x^3], x, 9, -((3*x^2)/(10*a)) + (1/5)*x^5*ArcTan[a*x^3] - (Sqrt[3]*ArcTan[(1 - 2*a^(2/3)*x^2)/Sqrt[3]])/(10*a^(5/3)) + Log[1 + a^(2/3)*x^2]/(10*a^(5/3)) - Log[1 - a^(2/3)*x^2 + a^(4/3)*x^4]/(20*a^(5/3))}
{x^3*ArcTan[a*x^3], x, 8, -((3*x)/(4*a)) + ArcTan[a^(1/3)*x]/(4*a^(4/3)) + (1/4)*x^4*ArcTan[a*x^3] + ((Sqrt[3]*a^(2/3) + Sqrt[-a^(4/3)])*ArcTanh[(Sqrt[2]*a^(2/3)*x)/Sqrt[a^(2/3) - Sqrt[3]*Sqrt[-a^(4/3)]]])/(4*Sqrt[2]*a*Sqrt[-a^(4/3)]*Sqrt[a^(2/3) - Sqrt[3]*Sqrt[-a^(4/3)]]) - ((Sqrt[3]*a^(2/3) - Sqrt[-a^(4/3)])*ArcTanh[(Sqrt[2]*a^(2/3)*x)/Sqrt[a^(2/3) + Sqrt[3]*Sqrt[-a^(4/3)]]])/(4*Sqrt[2]*a*Sqrt[-a^(4/3)]*Sqrt[a^(2/3) + Sqrt[3]*Sqrt[-a^(4/3)]])}
{x^2*ArcTan[a*x^3], x, 3, (1/3)*x^3*ArcTan[a*x^3] - Log[1 + a^2*x^6]/(6*a)}
{x^1*ArcTan[a*x^3], x, 7, -(ArcTan[a^(1/3)*x]/(2*a^(2/3))) + (1/2)*x^2*ArcTan[a*x^3] + ArcTanh[(Sqrt[2]*a^(2/3)*x)/Sqrt[a^(2/3) - Sqrt[3]*Sqrt[-a^(4/3)]]]/(Sqrt[2]*a^(1/3)*Sqrt[a^(2/3) - Sqrt[3]*Sqrt[-a^(4/3)]]) + ArcTanh[(Sqrt[2]*a^(2/3)*x)/Sqrt[a^(2/3) + Sqrt[3]*Sqrt[-a^(4/3)]]]/(Sqrt[2]*a^(1/3)*Sqrt[a^(2/3) + Sqrt[3]*Sqrt[-a^(4/3)]])}
{x^0*ArcTan[a*x^3], x, 8, x*ArcTan[a*x^3] + (Sqrt[3]*ArcTan[(1 - 2*a^(2/3)*x^2)/Sqrt[3]])/(2*a^(1/3)) + Log[1 + a^(2/3)*x^2]/(2*a^(1/3)) - Log[1 - a^(2/3)*x^2 + a^(4/3)*x^4]/(4*a^(1/3))}
{ArcTan[a*x^3]/x^1, x, 3, (1/6)*I*PolyLog[2, (-I)*a*x^3] - (1/6)*I*PolyLog[2, I*a*x^3]}
{ArcTan[a*x^3]/x^2, x, 8, -(ArcTan[a*x^3]/x) - (1/2)*Sqrt[3]*a^(1/3)*ArcTan[(1 - 2*a^(2/3)*x^2)/Sqrt[3]] + (1/2)*a^(1/3)*Log[1 + a^(2/3)*x^2] - (1/4)*a^(1/3)*Log[1 - a^(2/3)*x^2 + a^(4/3)*x^4]}
{ArcTan[a*x^3]/x^3, x, 7, (1/2)*a^(2/3)*ArcTan[a^(1/3)*x] - ArcTan[a*x^3]/(2*x^2) + (a*(Sqrt[3]*a^(2/3) + Sqrt[-a^(4/3)])*ArcTanh[(Sqrt[2]*a^(2/3)*x)/Sqrt[a^(2/3) - Sqrt[3]*Sqrt[-a^(4/3)]]])/(2*Sqrt[2]*Sqrt[-a^(4/3)]*Sqrt[a^(2/3) - Sqrt[3]*Sqrt[-a^(4/3)]]) - (a*(Sqrt[3]*a^(2/3) - Sqrt[-a^(4/3)])*ArcTanh[(Sqrt[2]*a^(2/3)*x)/Sqrt[a^(2/3) + Sqrt[3]*Sqrt[-a^(4/3)]]])/(2*Sqrt[2]*Sqrt[-a^(4/3)]*Sqrt[a^(2/3) + Sqrt[3]*Sqrt[-a^(4/3)]])}
{ArcTan[a*x^3]/x^4, x, 2, -(ArcTan[a*x^3]/(3*x^3)) - (1/3)*a*ArcTanh[1 + 2*a^2*x^6]}


{x^2*ArcTan[Sqrt[x]], x, 6, -(Sqrt[x]/3) + x^(3/2)/9 - x^(5/2)/15 + ArcTan[Sqrt[x]]/3 + (1/3)*x^3*ArcTan[Sqrt[x]]}
{x^1*ArcTan[Sqrt[x]], x, 5, Sqrt[x]/2 - x^(3/2)/6 - ArcTan[Sqrt[x]]/2 + (1/2)*x^2*ArcTan[Sqrt[x]]}
{x^0*ArcTan[Sqrt[x]], x, 4, -Sqrt[x] + ArcTan[Sqrt[x]] + x*ArcTan[Sqrt[x]]}
{ArcTan[Sqrt[x]]/x^1, x, 3, I*PolyLog[2, (-I)*Sqrt[x]] - I*PolyLog[2, I*Sqrt[x]]}
{ArcTan[Sqrt[x]]/x^2, x, 4, -(1/Sqrt[x]) - ArcTan[Sqrt[x]] - ArcTan[Sqrt[x]]/x}
{ArcTan[Sqrt[x]]/x^3, x, 5, -(1/(6*x^(3/2))) + 1/(2*Sqrt[x]) + ArcTan[Sqrt[x]]/2 - ArcTan[Sqrt[x]]/(2*x^2)}


{x^(3/2)*ArcTan[Sqrt[x]], x, 4, x/5 - x^2/10 + (2/5)*x^(5/2)*ArcTan[Sqrt[x]] - (1/5)*Log[1 + x]}
{x^(1/2)*ArcTan[Sqrt[x]], x, 4, -(x/3) + (2/3)*x^(3/2)*ArcTan[Sqrt[x]] + (1/3)*Log[1 + x]}
{ArcTan[Sqrt[x]]/x^(1/2), x, 3, 2*Sqrt[x]*ArcTan[Sqrt[x]] - Log[1 + x]}
{ArcTan[Sqrt[x]]/x^(3/2), x, 4, -((2*ArcTan[Sqrt[x]])/Sqrt[x]) + Log[x] - Log[1 + x]}
{ArcTan[Sqrt[x]]/x^(5/2), x, 4, -(1/(3*x)) - (2*ArcTan[Sqrt[x]])/(3*x^(3/2)) - Log[x]/3 + (1/3)*Log[1 + x]}


{ArcTan[a*x^5]/x, x, 3, (1/10)*I*PolyLog[2, (-I)*a*x^5] - (1/10)*I*PolyLog[2, I*a*x^5]}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{ArcTan[1/x], x, 3, x*ArcCot[x] + Log[1 + x^2]/2}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{ArcTan[a*x^n]/x, x, 3, (I*PolyLog[2, (-I)*a*x^n])/(2*n) - (I*PolyLog[2, I*a*x^n])/(2*n)}


(* ::Section::Closed:: *)
(*Integrands of the form u ArcTan[a+b x]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcTan[a+b x]^n*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{x^3*ArcTan[a + b*x], x, 6, ((1 - 3*a^2)*x)/(4*b^3) + (a*x^2)/(4*b^2) - x^3/(12*b) - ((1 - 6*a^2 + a^4)*ArcTan[a + b*x])/(4*b^4) + (1/4)*x^4*ArcTan[a + b*x] - (a*(1 - a^2)*Log[1 + a^2 + 2*a*b*x + b^2*x^2])/(2*b^4)}
{x^2*ArcTan[a + b*x], x, 6, (2*a*x)/(3*b^2) - x^2/(6*b) - (a*(3 - a^2)*ArcTan[a + b*x])/(3*b^3) + (1/3)*x^3*ArcTan[a + b*x] + ((1 - 3*a^2)*Log[1 + a^2 + 2*a*b*x + b^2*x^2])/(6*b^3)}
{x^1*ArcTan[a + b*x], x, 5, -(x/(2*b)) + ((1 - a^2)*ArcTan[a + b*x])/(2*b^2) + (1/2)*x^2*ArcTan[a + b*x] + (a*Log[1 + a^2 + 2*a*b*x + b^2*x^2])/(2*b^2)}
{x^0*ArcTan[a + b*x], x, 1, ((a + b*x)*ArcTan[a + b*x])/b - Log[1 + (a + b*x)^2]/(2*b)}
{ArcTan[a + b*x]/x^1, x, 5, (1/2)*I*Log[-((b*x)/(I + a))]*Log[1 - I*a - I*b*x] - (1/2)*I*Log[(b*x)/(I - a)]*Log[1 + I*a + I*b*x] + (1/2)*I*PolyLog[2, (I*(1 - I*a - I*b*x))/(I + a)] - (1/2)*I*PolyLog[2, (1 + I*a + I*b*x)/(1 + I*a)]}
{ArcTan[a + b*x]/x^2, x, 6, -((a*b*ArcTan[a + b*x])/(1 + a^2)) - ArcTan[a + b*x]/x + (b*Log[x])/(1 + a^2) - (b*Log[1 + a^2 + 2*a*b*x + b^2*x^2])/(2*(1 + a^2))}
{ArcTan[a + b*x]/x^3, x, 7, -(b/(2*(1 + a^2)*x)) - ((1 - a^2)*b^2*ArcTan[a + b*x])/(2*(1 + a^2)^2) - ArcTan[a + b*x]/(2*x^2) - (a*b^2*Log[x])/(1 + a^2)^2 + (a*b^2*Log[1 + a^2 + 2*a*b*x + b^2*x^2])/(2*(1 + a^2)^2)}
{ArcTan[a + b*x]/x^4, x, 8, -(b/(6*(1 + a^2)*x^2)) + (2*a*b^2)/(3*(1 + a^2)^2*x) + (a*(3 - a^2)*b^3*ArcTan[a + b*x])/(3*(1 + a^2)^3) - ArcTan[a + b*x]/(3*x^3) - ((1 - 3*a^2)*b^3*Log[x])/(3*(1 + a^2)^3) + ((1 - 3*a^2)*b^3*Log[1 + a^2 + 2*a*b*x + b^2*x^2])/(6*(1 + a^2)^3)}


(* ::Subsubsection:: *)
(*p<0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (c+d x)^m ArcTan[a+b x]*)


{(a + b*x)*ArcTan[a + b*x], x, 2, -((a + b*x)/(2*b)) + ArcTan[a + b*x]/(2*b) + ((a + b*x)^2*ArcTan[a + b*x])/(2*b)}
{(a + b*x)^2*ArcTan[a + b*x], x, 4, -((a + b*x)^2/(6*b)) + ((a + b*x)^3*ArcTan[a + b*x])/(3*b) + Log[1 + (a + b*x)^2]/(6*b)}
{ArcTan[1 + x]/(2 + 2*x), x, 3, (1/4)*I*PolyLog[2, (-I)*(1 + x)] - (1/4)*I*PolyLog[2, I*(1 + x)]}
{ArcTan[a + b*x]/(a + b*x), x, 3, (I*PolyLog[2, (-I)*(a + b*x)])/(2*b) - (I*PolyLog[2, I*(a + b*x)])/(2*b)}
{ArcTan[a + b*x]/(a + b*x)^2, x, 2, -(ArcTan[a + b*x]/(b*(a + b*x))) - ArcTanh[1 + 2*(a + b*x)^2]/b}


{ArcTan[a + b*x]/((a*d)/b + d*x), x, 3, (I*PolyLog[2, (-I)*(a + b*x)])/(2*d) - (I*PolyLog[2, I*(a + b*x)])/(2*d)}


{ArcTan[d + e*x]/(a + b*x), x, 5, (I*Log[-((e*(a + b*x))/(b*(I + d) - a*e))]*Log[1 - I*d - I*e*x])/(2*b) - (I*Log[(e*(a + b*x))/(b*(I - d) + a*e)]*Log[1 + I*d + I*e*x])/(2*b) + (I*PolyLog[2, (I*b*(1 - I*d - I*e*x))/(b*(I + d) - a*e)])/(2*b) - (I*PolyLog[2, (I*b*(1 + I*d + I*e*x))/(I*b - b*d + a*e)])/(2*b)}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c+d x^n) ArcTan[a+b x]*)


{ArcTan[a + b*x]/(c + d*x^3), x, 15, -((I*Log[1 + I*a + I*b*x]*Log[(b*(c^(1/3) + d^(1/3)*x))/(b*c^(1/3) + (I - a)*d^(1/3))])/(6*c^(2/3)*d^(1/3))) + (I*Log[1 - I*a - I*b*x]*Log[(b*(c^(1/3) + d^(1/3)*x))/(b*c^(1/3) - (I + a)*d^(1/3))])/(6*c^(2/3)*d^(1/3)) + ((-1)^(1/6)*Log[1 + I*a + I*b*x]*Log[-((I*b*((-1)^(2/3)*c^(1/3) + d^(1/3)*x))/((-1)^(1/6)*b*c^(1/3) + (1 + I*a)*d^(1/3)))])/(6*c^(2/3)*d^(1/3)) - ((-1)^(1/6)*Log[1 - I*a - I*b*x]*Log[-((I*b*((-1)^(2/3)*c^(1/3) + d^(1/3)*x))/((-1)^(1/6)*b*c^(1/3) + I*(I + a)*d^(1/3)))])/(6*c^(2/3)*d^(1/3)) + ((-1)^(5/6)*Log[1 + I*a + I*b*x]*Log[((-1)^(5/6)*b*(c^(1/3) + (-1)^(2/3)*d^(1/3)*x))/((-1)^(5/6)*b*c^(1/3) + (1 + I*a)*d^(1/3))])/(6*c^(2/3)*d^(1/3)) - ((-1)^(5/6)*Log[1 - I*a - I*b*x]*Log[((-1)^(5/6)*b*(c^(1/3) + (-1)^(2/3)*d^(1/3)*x))/((-1)^(5/6)*b*c^(1/3) + I*(I + a)*d^(1/3))])/(6*c^(2/3)*d^(1/3)) + (I*PolyLog[2, -((I*d^(1/3)*(1 - I*a - I*b*x))/(b*c^(1/3) - (I + a)*d^(1/3)))])/(6*c^(2/3)*d^(1/3)) - ((-1)^(1/6)*PolyLog[2, -((I*d^(1/3)*(1 - I*a - I*b*x))/((-1)^(2/3)*b*c^(1/3) - (I + a)*d^(1/3)))])/(6*c^(2/3)*d^(1/3)) - ((-1)^(5/6)*PolyLog[2, (I*d^(1/3)*(1 - I*a - I*b*x))/((-1)^(1/3)*b*c^(1/3) + (I + a)*d^(1/3))])/(6*c^(2/3)*d^(1/3)) + ((-1)^(5/6)*PolyLog[2, -((I*d^(1/3)*(1 + I*a + I*b*x))/((-1)^(1/3)*b*c^(1/3) - (I - a)*d^(1/3)))])/(6*c^(2/3)*d^(1/3)) - (I*PolyLog[2, (I*d^(1/3)*(1 + I*a + I*b*x))/(b*c^(1/3) + (I - a)*d^(1/3))])/(6*c^(2/3)*d^(1/3)) + ((-1)^(1/6)*PolyLog[2, (I*d^(1/3)*(1 + I*a + I*b*x))/((-1)^(2/3)*b*c^(1/3) + (I - a)*d^(1/3))])/(6*c^(2/3)*d^(1/3))}
{ArcTan[a + b*x]/(c + d*x^2), x, 11, -((I*Log[1 + I*a + I*b*x]*Log[(b*(Sqrt[-c] - Sqrt[d]*x))/(b*Sqrt[-c] - (I - a)*Sqrt[d])])/(4*Sqrt[-c]*Sqrt[d])) + (I*Log[1 - I*a - I*b*x]*Log[(b*(Sqrt[-c] - Sqrt[d]*x))/(b*Sqrt[-c] + (I + a)*Sqrt[d])])/(4*Sqrt[-c]*Sqrt[d]) + (I*Log[1 + I*a + I*b*x]*Log[(b*(Sqrt[-c] + Sqrt[d]*x))/(b*Sqrt[-c] + (I - a)*Sqrt[d])])/(4*Sqrt[-c]*Sqrt[d]) - (I*Log[1 - I*a - I*b*x]*Log[(b*(Sqrt[-c] + Sqrt[d]*x))/(b*Sqrt[-c] - (I + a)*Sqrt[d])])/(4*Sqrt[-c]*Sqrt[d]) - (I*PolyLog[2, -((I*Sqrt[d]*(1 - I*a - I*b*x))/(b*Sqrt[-c] - (I + a)*Sqrt[d]))])/(4*Sqrt[-c]*Sqrt[d]) + (I*PolyLog[2, (I*Sqrt[d]*(1 - I*a - I*b*x))/(b*Sqrt[-c] + (I + a)*Sqrt[d])])/(4*Sqrt[-c]*Sqrt[d]) - (I*PolyLog[2, -((I*Sqrt[d]*(1 + I*a + I*b*x))/(b*Sqrt[-c] - (I - a)*Sqrt[d]))])/(4*Sqrt[-c]*Sqrt[d]) + (I*PolyLog[2, (I*Sqrt[d]*(1 + I*a + I*b*x))/(b*Sqrt[-c] + (I - a)*Sqrt[d])])/(4*Sqrt[-c]*Sqrt[d])}
{ArcTan[a + b*x]/(c + d*x), x, 5, -((I*Log[1 + I*a + I*b*x]*Log[(b*(c + d*x))/(b*c + (I - a)*d)])/(2*d)) + (I*Log[1 - I*a - I*b*x]*Log[(b*(c + d*x))/(b*c - (I + a)*d)])/(2*d) + (I*PolyLog[2, -((I*d*(1 - I*a - I*b*x))/(b*c - (I + a)*d))])/(2*d) - (I*PolyLog[2, (I*d*(1 + I*a + I*b*x))/(b*c + I*d - a*d)])/(2*d)}
{ArcTan[a + b*x]/(c + d/x), x, 11, -(((1 - I*a - I*b*x)*Log[1 - I*a - I*b*x])/(2*b*c)) - ((1 + I*a + I*b*x)*Log[1 + I*a + I*b*x])/(2*b*c) - (I*d*Log[1 - I*a - I*b*x]*Log[-((b*(d + c*x))/((I + a)*c - b*d))])/(2*c^2) + (I*d*Log[1 + I*a + I*b*x]*Log[(b*(d + c*x))/((I - a)*c + b*d)])/(2*c^2) - (I*d*PolyLog[2, (I*c*(1 - I*a - I*b*x))/((I + a)*c - b*d)])/(2*c^2) + (I*d*PolyLog[2, (I*c*(1 + I*a + I*b*x))/(I*c - a*c + b*d)])/(2*c^2)}
{ArcTan[a + b*x]/(c + d/x^2), x, 17, -(((1 - I*a - I*b*x)*Log[1 - I*a - I*b*x])/(2*b*c)) - ((1 + I*a + I*b*x)*Log[1 + I*a + I*b*x])/(2*b*c) - (I*Sqrt[-d]*Log[1 + I*a + I*b*x]*Log[-((b*(Sqrt[-d] - Sqrt[c]*x))/((I - a)*Sqrt[c] - b*Sqrt[-d]))])/(4*c^(3/2)) + (I*Sqrt[-d]*Log[1 - I*a - I*b*x]*Log[(b*(Sqrt[-d] - Sqrt[c]*x))/((I + a)*Sqrt[c] + b*Sqrt[-d])])/(4*c^(3/2)) - (I*Sqrt[-d]*Log[1 - I*a - I*b*x]*Log[-((b*(Sqrt[-d] + Sqrt[c]*x))/((I + a)*Sqrt[c] - b*Sqrt[-d]))])/(4*c^(3/2)) + (I*Sqrt[-d]*Log[1 + I*a + I*b*x]*Log[(b*(Sqrt[-d] + Sqrt[c]*x))/((I - a)*Sqrt[c] + b*Sqrt[-d])])/(4*c^(3/2)) - (I*Sqrt[-d]*PolyLog[2, (I*Sqrt[c]*(1 - I*a - I*b*x))/((I + a)*Sqrt[c] - b*Sqrt[-d])])/(4*c^(3/2)) + (I*Sqrt[-d]*PolyLog[2, (I*Sqrt[c]*(1 - I*a - I*b*x))/((I + a)*Sqrt[c] + b*Sqrt[-d])])/(4*c^(3/2)) - (I*Sqrt[-d]*PolyLog[2, (I*Sqrt[c]*(1 + I*a + I*b*x))/((I - a)*Sqrt[c] - b*Sqrt[-d])])/(4*c^(3/2)) + (I*Sqrt[-d]*PolyLog[2, (I*Sqrt[c]*(1 + I*a + I*b*x))/((I - a)*Sqrt[c] + b*Sqrt[-d])])/(4*c^(3/2))}
{ArcTan[a + b*x]/(c + d/x^3), x, 21, -(((1 - I*a - I*b*x)*Log[1 - I*a - I*b*x])/(2*b*c)) - ((1 + I*a + I*b*x)*Log[1 + I*a + I*b*x])/(2*b*c) - (I*d^(1/3)*Log[1 - I*a - I*b*x]*Log[-((b*(d^(1/3) + c^(1/3)*x))/((I + a)*c^(1/3) - b*d^(1/3)))])/(6*c^(4/3)) + (I*d^(1/3)*Log[1 + I*a + I*b*x]*Log[(b*(d^(1/3) + c^(1/3)*x))/((I - a)*c^(1/3) + b*d^(1/3))])/(6*c^(4/3)) - ((-1)^(1/6)*d^(1/3)*Log[1 + I*a + I*b*x]*Log[-((I*b*((-1)^(2/3)*d^(1/3) + c^(1/3)*x))/((1 + I*a)*c^(1/3) + (-1)^(1/6)*b*d^(1/3)))])/(6*c^(4/3)) + ((-1)^(1/6)*d^(1/3)*Log[1 - I*a - I*b*x]*Log[-((I*b*((-1)^(2/3)*d^(1/3) + c^(1/3)*x))/(I*(I + a)*c^(1/3) + (-1)^(1/6)*b*d^(1/3)))])/(6*c^(4/3)) - ((-1)^(5/6)*d^(1/3)*Log[1 + I*a + I*b*x]*Log[((-1)^(5/6)*b*(d^(1/3) + (-1)^(2/3)*c^(1/3)*x))/((1 + I*a)*c^(1/3) + (-1)^(5/6)*b*d^(1/3))])/(6*c^(4/3)) + ((-1)^(5/6)*d^(1/3)*Log[1 - I*a - I*b*x]*Log[((-1)^(5/6)*b*(d^(1/3) + (-1)^(2/3)*c^(1/3)*x))/(I*(I + a)*c^(1/3) + (-1)^(5/6)*b*d^(1/3))])/(6*c^(4/3)) - (I*d^(1/3)*PolyLog[2, (I*c^(1/3)*(1 - I*a - I*b*x))/((I + a)*c^(1/3) - b*d^(1/3))])/(6*c^(4/3)) + ((-1)^(5/6)*d^(1/3)*PolyLog[2, (I*c^(1/3)*(1 - I*a - I*b*x))/((I + a)*c^(1/3) + (-1)^(1/3)*b*d^(1/3))])/(6*c^(4/3)) + ((-1)^(1/6)*d^(1/3)*PolyLog[2, (I*c^(1/3)*(1 - I*a - I*b*x))/((I + a)*c^(1/3) - (-1)^(2/3)*b*d^(1/3))])/(6*c^(4/3)) + (I*d^(1/3)*PolyLog[2, (I*c^(1/3)*(1 + I*a + I*b*x))/((I - a)*c^(1/3) + b*d^(1/3))])/(6*c^(4/3)) - ((-1)^(5/6)*d^(1/3)*PolyLog[2, (I*c^(1/3)*(1 + I*a + I*b*x))/((I - a)*c^(1/3) - (-1)^(1/3)*b*d^(1/3))])/(6*c^(4/3)) - ((-1)^(1/6)*d^(1/3)*PolyLog[2, (I*c^(1/3)*(1 + I*a + I*b*x))/((I - a)*c^(1/3) + (-1)^(2/3)*b*d^(1/3))])/(6*c^(4/3))}


(* {ArcTan[a + b*x]/(a + b*x^(3/2)), x, 41, ((I/3)*Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-I - a] - Sqrt[b]*Sqrt[x])/(Sqrt[-I - a] + a^(1/3)*b^(1/6))])/(a^(1/3)*b^(2/3)) - ((-1)^(1/6)*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-I - a] - Sqrt[b]*Sqrt[x])/(Sqrt[-I - a] - (-1)^(1/3)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) - ((-1)^(5/6)*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-I - a] - Sqrt[b]*Sqrt[x])/(Sqrt[-I - a] + (-1)^(2/3)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) + ((-1)^(1/6)*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[-(((-1)^(3/4)*((-1)^(1/4)*Sqrt[1 + I*a] - Sqrt[b]*Sqrt[x]))/(Sqrt[1 + I*a] - (-1)^(1/12)*a^(1/3)*b^(1/6)))])/(3*a^(1/3)*b^(2/3)) + ((-1)^(5/6)*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[-(((-1)^(3/4)*((-1)^(1/4)*Sqrt[1 + I*a] - Sqrt[b]*Sqrt[x]))/(Sqrt[1 + I*a] + (-1)^(5/12)*a^(1/3)*b^(1/6)))])/(3*a^(1/3)*b^(2/3)) + ((I/3)*Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-I - a] + Sqrt[b]*Sqrt[x])/(Sqrt[-I - a] - a^(1/3)*b^(1/6))])/(a^(1/3)*b^(2/3)) - ((-1)^(1/6)*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-I - a] + Sqrt[b]*Sqrt[x])/(Sqrt[-I - a] + (-1)^(1/3)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) - ((-1)^(5/6)*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-I - a] + Sqrt[b]*Sqrt[x])/(Sqrt[-I - a] - (-1)^(2/3)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) - ((I/3)*Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[((-1)^(1/4)*Sqrt[1 + I*a] + Sqrt[b]*Sqrt[x])/((-1)^(1/4)*Sqrt[1 + I*a] - a^(1/3)*b^(1/6))])/(a^(1/3)*b^(2/3)) + ((-1)^(1/6)*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[1 + I*a] - (-1)^(3/4)*Sqrt[b]*Sqrt[x])/(Sqrt[1 + I*a] + (-1)^(1/12)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) + ((-1)^(5/6)*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[1 + I*a] - (-1)^(3/4)*Sqrt[b]*Sqrt[x])/(Sqrt[1 + I*a] - (-1)^(5/12)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) - ((I/3)*Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[((-1)^(1/4)*(Sqrt[1 + I*a] + (-1)^(3/4)*Sqrt[b]*Sqrt[x]))/((-1)^(1/4)*Sqrt[1 + I*a] + a^(1/3)*b^(1/6))])/(a^(1/3)*b^(2/3)) + ((I/3)*Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[1 + I*a + I*b*x])/(a^(1/3)*b^(2/3)) - ((-1)^(1/6)*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[1 + I*a + I*b*x])/(3*a^(1/3)*b^(2/3)) - ((-1)^(5/6)*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[1 + I*a + I*b*x])/(3*a^(1/3)*b^(2/3)) - ((I/3)*Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(-I)*(I + a + b*x)])/(a^(1/3)*b^(2/3)) + ((-1)^(1/6)*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(-I)*(I + a + b*x)])/(3*a^(1/3)*b^(2/3)) + ((-1)^(5/6)*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[(-I)*(I + a + b*x)])/(3*a^(1/3)*b^(2/3)) - ((-1)^(1/6)*PolyLog[2, -((b^(1/6)*((-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]))/(Sqrt[-I - a] - (-1)^(1/3)*a^(1/3)*b^(1/6)))])/(3*a^(1/3)*b^(2/3)) + ((I/3)*PolyLog[2, -((b^(1/6)*(a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-I - a] - a^(1/3)*b^(1/6)))])/(a^(1/3)*b^(2/3)) - ((I/3)*PolyLog[2, -((b^(1/6)*(a^(1/3) + b^(1/3)*Sqrt[x]))/((-1)^(1/4)*Sqrt[1 + I*a] - a^(1/3)*b^(1/6)))])/(a^(1/3)*b^(2/3)) + ((I/3)*PolyLog[2, (b^(1/6)*(a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-I - a] + a^(1/3)*b^(1/6))])/(a^(1/3)*b^(2/3)) - ((I/3)*PolyLog[2, (b^(1/6)*(a^(1/3) + b^(1/3)*Sqrt[x]))/((-1)^(1/4)*Sqrt[1 + I*a] + a^(1/3)*b^(1/6))])/(a^(1/3)*b^(2/3)) + ((-1)^(5/6)*PolyLog[2, ((-1)^(3/4)*b^(1/6)*((-1)^(2/3)*a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[1 + I*a] - (-1)^(5/12)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) - ((-1)^(5/6)*PolyLog[2, -((b^(1/6)*((-1)^(2/3)*a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-I - a] - (-1)^(2/3)*a^(1/3)*b^(1/6)))])/(3*a^(1/3)*b^(2/3)) - ((-1)^(5/6)*PolyLog[2, (b^(1/6)*((-1)^(2/3)*a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-I - a] + (-1)^(2/3)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) + ((-1)^(5/6)*PolyLog[2, ((-1)^(5/12)*b^(1/6)*(a^(1/3) - (-1)^(1/3)*b^(1/3)*Sqrt[x]))/(Sqrt[1 + I*a] + (-1)^(5/12)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) + ((-1)^(1/6)*PolyLog[2, ((-1)^(1/12)*b^(1/6)*(a^(1/3) + (-1)^(2/3)*b^(1/3)*Sqrt[x]))/(Sqrt[1 + I*a] + (-1)^(1/12)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) - ((-1)^(1/6)*PolyLog[2, ((-1)^(1/3)*b^(1/6)*(a^(1/3) + (-1)^(2/3)*b^(1/3)*Sqrt[x]))/(Sqrt[-I - a] + (-1)^(1/3)*a^(1/3)*b^(1/6))])/(3*a^(1/3)*b^(2/3)) + ((-1)^(1/6)*PolyLog[2, -((b^(1/6)*((-1)^(1/12)*a^(1/3) + (-1)^(3/4)*b^(1/3)*Sqrt[x]))/(Sqrt[1 + I*a] - (-1)^(1/12)*a^(1/3)*b^(1/6)))])/(3*a^(1/3)*b^(2/3))} *)
{ArcTan[a + b*x]/(c + d*Sqrt[x]), x, 25, (-2*(-1)^(1/4)*Sqrt[1 + I*a]*ArcTan[((-1)^(1/4)*Sqrt[b]*Sqrt[x])/Sqrt[1 + I*a]])/(Sqrt[b]*d) + ((2*I)*Sqrt[I + a]*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[I + a]])/(Sqrt[b]*d) + (I*c*Log[(d*(Sqrt[-I - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[b]*c + Sqrt[-I - a]*d)]*Log[c + d*Sqrt[x]])/d^2 + (I*c*Log[-((d*(Sqrt[-I - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[b]*c - Sqrt[-I - a]*d))]*Log[c + d*Sqrt[x]])/d^2 - (I*c*Log[-((d*((-1)^(1/4)*Sqrt[1 + I*a] + Sqrt[b]*Sqrt[x]))/(Sqrt[b]*c - (-1)^(1/4)*Sqrt[1 + I*a]*d))]*Log[c + d*Sqrt[x]])/d^2 - (I*c*Log[((-1)^(1/4)*d*(Sqrt[1 + I*a] + (-1)^(3/4)*Sqrt[b]*Sqrt[x]))/(Sqrt[b]*c + (-1)^(1/4)*Sqrt[1 + I*a]*d)]*Log[c + d*Sqrt[x]])/d^2 - (I*Sqrt[x]*Log[1 + I*a + I*b*x])/d + (I*c*Log[c + d*Sqrt[x]]*Log[1 + I*a + I*b*x])/d^2 + (I*Sqrt[x]*Log[(-I)*(I + a + b*x)])/d - (I*c*Log[c + d*Sqrt[x]]*Log[(-I)*(I + a + b*x)])/d^2 + (I*c*PolyLog[2, (Sqrt[b]*(c + d*Sqrt[x]))/(Sqrt[b]*c - Sqrt[-I - a]*d)])/d^2 + (I*c*PolyLog[2, (Sqrt[b]*(c + d*Sqrt[x]))/(Sqrt[b]*c + Sqrt[-I - a]*d)])/d^2 - (I*c*PolyLog[2, (Sqrt[b]*(c + d*Sqrt[x]))/(Sqrt[b]*c - (-1)^(1/4)*Sqrt[1 + I*a]*d)])/d^2 - (I*c*PolyLog[2, (Sqrt[b]*(c + d*Sqrt[x]))/(Sqrt[b]*c + (-1)^(1/4)*Sqrt[1 + I*a]*d)])/d^2}
{ArcTan[a + b*x]/(c + d/Sqrt[x]), x, 29, (2*(-1)^(1/4)*Sqrt[1 + I*a]*d*ArcTan[((-1)^(1/4)*Sqrt[b]*Sqrt[x])/Sqrt[1 + I*a]])/(Sqrt[b]*c^2) - ((2*I)*Sqrt[I + a]*d*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[I + a]])/(Sqrt[b]*c^2) - (I*d^2*Log[(c*(Sqrt[-I - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[-I - a]*c + Sqrt[b]*d)]*Log[d + c*Sqrt[x]])/c^3 - (I*d^2*Log[(c*(Sqrt[-I - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[-I - a]*c - Sqrt[b]*d)]*Log[d + c*Sqrt[x]])/c^3 + (I*d^2*Log[(c*((-1)^(1/4)*Sqrt[1 + I*a] + Sqrt[b]*Sqrt[x]))/((-1)^(1/4)*Sqrt[1 + I*a]*c - Sqrt[b]*d)]*Log[d + c*Sqrt[x]])/c^3 + (I*d^2*Log[((-1)^(1/4)*c*(Sqrt[1 + I*a] + (-1)^(3/4)*Sqrt[b]*Sqrt[x]))/((-1)^(1/4)*Sqrt[1 + I*a]*c + Sqrt[b]*d)]*Log[d + c*Sqrt[x]])/c^3 + (I*d*Sqrt[x]*Log[1 + I*a + I*b*x])/c^2 - ((1 + I*a + I*b*x)*Log[1 + I*a + I*b*x])/(2*b*c) - (I*d^2*Log[d + c*Sqrt[x]]*Log[1 + I*a + I*b*x])/c^3 - (I*d*Sqrt[x]*Log[(-I)*(I + a + b*x)])/c^2 + ((I/2)*(I + a + b*x)*Log[(-I)*(I + a + b*x)])/(b*c) + (I*d^2*Log[d + c*Sqrt[x]]*Log[(-I)*(I + a + b*x)])/c^3 - (I*d^2*PolyLog[2, -((Sqrt[b]*(d + c*Sqrt[x]))/(Sqrt[-I - a]*c - Sqrt[b]*d))])/c^3 + (I*d^2*PolyLog[2, -((Sqrt[b]*(d + c*Sqrt[x]))/((-1)^(1/4)*Sqrt[1 + I*a]*c - Sqrt[b]*d))])/c^3 - (I*d^2*PolyLog[2, (Sqrt[b]*(d + c*Sqrt[x]))/(Sqrt[-I - a]*c + Sqrt[b]*d)])/c^3 + (I*d^2*PolyLog[2, (Sqrt[b]*(d + c*Sqrt[x]))/((-1)^(1/4)*Sqrt[1 + I*a]*c + Sqrt[b]*d)])/c^3}
(* {ArcTan[a + b*x]/(a + b/x^(3/2)), x, 49, -((-1)^(5/6)*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[-(((-1)^(3/4)*a^(1/3)*((-1)^(1/4)*Sqrt[1 + I*a] - Sqrt[b]*Sqrt[x]))/(Sqrt[1 + I*a]*a^(1/3) + (-1)^(5/12)*b^(5/6)))])/(3*a^(5/3)) - ((I/3)*b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*((-1)^(3/4)*Sqrt[1 - I*a] + Sqrt[b]*Sqrt[x]))/((-1)^(3/4)*Sqrt[1 - I*a]*a^(1/3) - b^(5/6))])/a^(5/3) + ((I/3)*b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*((-1)^(1/4)*Sqrt[1 + I*a] + Sqrt[b]*Sqrt[x]))/((-1)^(1/4)*Sqrt[1 + I*a]*a^(1/3) - b^(5/6))])/a^(5/3) + ((-1)^(5/6)*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[((-1)^(1/12)*a^(1/3)*(Sqrt[1 - I*a] - (-1)^(1/4)*Sqrt[b]*Sqrt[x]))/((-1)^(1/12)*Sqrt[1 - I*a]*a^(1/3) - b^(5/6))])/(3*a^(5/3)) + ((-1)^(1/6)*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[((-1)^(5/12)*a^(1/3)*(Sqrt[1 - I*a] - (-1)^(1/4)*Sqrt[b]*Sqrt[x]))/((-1)^(5/12)*Sqrt[1 - I*a]*a^(1/3) + b^(5/6))])/(3*a^(5/3)) + ((-1)^(1/6)*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[((-1)^(5/12)*a^(1/3)*(Sqrt[1 - I*a] + (-1)^(1/4)*Sqrt[b]*Sqrt[x]))/((-1)^(5/12)*Sqrt[1 - I*a]*a^(1/3) - b^(5/6))])/(3*a^(5/3)) + ((-1)^(5/6)*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[((-1)^(1/12)*a^(1/3)*(Sqrt[1 - I*a] + (-1)^(1/4)*Sqrt[b]*Sqrt[x]))/((-1)^(1/12)*Sqrt[1 - I*a]*a^(1/3) + b^(5/6))])/(3*a^(5/3)) - ((I/3)*b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[((-1)^(3/4)*a^(1/3)*(Sqrt[1 - I*a] + (-1)^(1/4)*Sqrt[b]*Sqrt[x]))/((-1)^(3/4)*Sqrt[1 - I*a]*a^(1/3) + b^(5/6))])/a^(5/3) - ((-1)^(1/6)*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[1 + I*a] - (-1)^(3/4)*Sqrt[b]*Sqrt[x]))/(Sqrt[1 + I*a]*a^(1/3) + (-1)^(1/12)*b^(5/6))])/(3*a^(5/3)) - ((-1)^(5/6)*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[1 + I*a] - (-1)^(3/4)*Sqrt[b]*Sqrt[x]))/(Sqrt[1 + I*a]*a^(1/3) - (-1)^(5/12)*b^(5/6))])/(3*a^(5/3)) + ((I/3)*b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[((-1)^(1/4)*a^(1/3)*(Sqrt[1 + I*a] + (-1)^(3/4)*Sqrt[b]*Sqrt[x]))/((-1)^(1/4)*Sqrt[1 + I*a]*a^(1/3) + b^(5/6))])/a^(5/3) - ((-1)^(1/6)*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[1 + I*a] + (-1)^(3/4)*Sqrt[b]*Sqrt[x]))/(Sqrt[1 + I*a]*a^(1/3) - (-1)^(1/12)*b^(5/6))])/(3*a^(5/3)) - ((1 - I*a - I*b*x)*Log[1 - I*a - I*b*x])/(2*a*b) + ((I/3)*b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[1 - I*a - I*b*x])/a^(5/3) - ((-1)^(1/6)*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[1 - I*a - I*b*x])/(3*a^(5/3)) - ((-1)^(5/6)*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[1 - I*a - I*b*x])/(3*a^(5/3)) - ((1 + I*a + I*b*x)*Log[1 + I*a + I*b*x])/(2*a*b) - ((I/3)*b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[1 + I*a + I*b*x])/a^(5/3) + ((-1)^(1/6)*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[1 + I*a + I*b*x])/(3*a^(5/3)) + ((-1)^(5/6)*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[1 + I*a + I*b*x])/(3*a^(5/3)) - ((I/3)*b^(2/3)*PolyLog[2, -((Sqrt[b]*(b^(1/3) + a^(1/3)*Sqrt[x]))/((-1)^(3/4)*Sqrt[1 - I*a]*a^(1/3) - b^(5/6)))])/a^(5/3) + ((I/3)*b^(2/3)*PolyLog[2, -((Sqrt[b]*(b^(1/3) + a^(1/3)*Sqrt[x]))/((-1)^(1/4)*Sqrt[1 + I*a]*a^(1/3) - b^(5/6)))])/a^(5/3) - ((I/3)*b^(2/3)*PolyLog[2, (Sqrt[b]*(b^(1/3) + a^(1/3)*Sqrt[x]))/((-1)^(3/4)*Sqrt[1 - I*a]*a^(1/3) + b^(5/6))])/a^(5/3) + ((I/3)*b^(2/3)*PolyLog[2, (Sqrt[b]*(b^(1/3) + a^(1/3)*Sqrt[x]))/((-1)^(1/4)*Sqrt[1 + I*a]*a^(1/3) + b^(5/6))])/a^(5/3) + ((-1)^(5/6)*b^(2/3)*PolyLog[2, ((-1)^(1/3)*Sqrt[b]*((-1)^(2/3)*b^(1/3) + a^(1/3)*Sqrt[x]))/((-1)^(1/12)*Sqrt[1 - I*a]*a^(1/3) - b^(5/6))])/(3*a^(5/3)) - ((-1)^(5/6)*b^(2/3)*PolyLog[2, ((-1)^(3/4)*Sqrt[b]*((-1)^(2/3)*b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[1 + I*a]*a^(1/3) - (-1)^(5/12)*b^(5/6))])/(3*a^(5/3)) + ((-1)^(5/6)*b^(2/3)*PolyLog[2, (Sqrt[b]*(b^(1/3) - (-1)^(1/3)*a^(1/3)*Sqrt[x]))/((-1)^(1/12)*Sqrt[1 - I*a]*a^(1/3) + b^(5/6))])/(3*a^(5/3)) - ((-1)^(5/6)*b^(2/3)*PolyLog[2, ((-1)^(5/12)*Sqrt[b]*(b^(1/3) - (-1)^(1/3)*a^(1/3)*Sqrt[x]))/(Sqrt[1 + I*a]*a^(1/3) + (-1)^(5/12)*b^(5/6))])/(3*a^(5/3)) + ((-1)^(1/6)*b^(2/3)*PolyLog[2, -((Sqrt[b]*(b^(1/3) + (-1)^(2/3)*a^(1/3)*Sqrt[x]))/((-1)^(5/12)*Sqrt[1 - I*a]*a^(1/3) - b^(5/6)))])/(3*a^(5/3)) + ((-1)^(1/6)*b^(2/3)*PolyLog[2, (Sqrt[b]*(b^(1/3) + (-1)^(2/3)*a^(1/3)*Sqrt[x]))/((-1)^(5/12)*Sqrt[1 - I*a]*a^(1/3) + b^(5/6))])/(3*a^(5/3)) - ((-1)^(1/6)*b^(2/3)*PolyLog[2, ((-1)^(1/12)*Sqrt[b]*(b^(1/3) + (-1)^(2/3)*a^(1/3)*Sqrt[x]))/(Sqrt[1 + I*a]*a^(1/3) + (-1)^(1/12)*b^(5/6))])/(3*a^(5/3)) - ((-1)^(1/6)*b^(2/3)*PolyLog[2, -((Sqrt[b]*((-1)^(1/12)*b^(1/3) + (-1)^(3/4)*a^(1/3)*Sqrt[x]))/(Sqrt[1 + I*a]*a^(1/3) - (-1)^(1/12)*b^(5/6)))])/(3*a^(5/3))} *)


{ArcTan[a + b*x]/(1 + x^2), x, 13, (1/4)*Log[(b*(I - x))/(a + I*(1 + b))]*Log[1 - I*a - I*b*x] - (1/4)*Log[-((b*(I + x))/(a + I*(1 - b)))]*Log[1 - I*a - I*b*x] - (1/4)*Log[(b*(I - x))/(a - I*(1 - b))]*Log[1 + I*a + I*b*x] + (1/4)*Log[-((b*(I + x))/(a - I*(1 + b)))]*Log[1 + I*a + I*b*x] - (1/4)*PolyLog[2, (1 - I*a - I*b*x)/(1 - I*a - b)] + (1/4)*PolyLog[2, (1 - I*a - I*b*x)/(1 - I*a + b)] - (1/4)*PolyLog[2, (1 + I*a + I*b*x)/(1 + I*a - b)] + (1/4)*PolyLog[2, (1 + I*a + I*b*x)/(1 + I*a + b)]}


{ArcTan[d + e*x]/(a + b*x^2), x, 11, (I*Log[(e*(Sqrt[-a] - Sqrt[b]*x))/(Sqrt[b]*(I + d) + Sqrt[-a]*e)]*Log[1 - I*d - I*e*x])/(4*Sqrt[-a]*Sqrt[b]) - (I*Log[-((e*(Sqrt[-a] + Sqrt[b]*x))/(Sqrt[b]*(I + d) - Sqrt[-a]*e))]*Log[1 - I*d - I*e*x])/(4*Sqrt[-a]*Sqrt[b]) - (I*Log[-((e*(Sqrt[-a] - Sqrt[b]*x))/(Sqrt[b]*(I - d) - Sqrt[-a]*e))]*Log[1 + I*d + I*e*x])/(4*Sqrt[-a]*Sqrt[b]) + (I*Log[(e*(Sqrt[-a] + Sqrt[b]*x))/(Sqrt[b]*(I - d) + Sqrt[-a]*e)]*Log[1 + I*d + I*e*x])/(4*Sqrt[-a]*Sqrt[b]) - (I*PolyLog[2, (I*Sqrt[b]*(1 - I*d - I*e*x))/(Sqrt[b]*(I + d) - Sqrt[-a]*e)])/(4*Sqrt[-a]*Sqrt[b]) + (I*PolyLog[2, (I*Sqrt[b]*(1 - I*d - I*e*x))/(Sqrt[b]*(I + d) + Sqrt[-a]*e)])/(4*Sqrt[-a]*Sqrt[b]) - (I*PolyLog[2, (I*Sqrt[b]*(1 + I*d + I*e*x))/(Sqrt[b]*(I - d) - Sqrt[-a]*e)])/(4*Sqrt[-a]*Sqrt[b]) + (I*PolyLog[2, (I*Sqrt[b]*(1 + I*d + I*e*x))/(Sqrt[b]*(I - d) + Sqrt[-a]*e)])/(4*Sqrt[-a]*Sqrt[b])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c+d x+e x^2)^m ArcTan[a+b x]*)


{ArcTan[d + e*x]/(a + b*x + c*x^2), x, 11, (I*Log[-((e*(b - Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c*(I + d) - (b - Sqrt[b^2 - 4*a*c])*e))]*Log[1 - I*d - I*e*x])/(2*Sqrt[b^2 - 4*a*c]) - (I*Log[-((e*(b + Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c*(I + d) - (b + Sqrt[b^2 - 4*a*c])*e))]*Log[1 - I*d - I*e*x])/(2*Sqrt[b^2 - 4*a*c]) - (I*Log[(e*(b - Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c*(I - d) + (b - Sqrt[b^2 - 4*a*c])*e)]*Log[1 + I*d + I*e*x])/(2*Sqrt[b^2 - 4*a*c]) + (I*Log[(e*(b + Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c*(I - d) + (b + Sqrt[b^2 - 4*a*c])*e)]*Log[1 + I*d + I*e*x])/(2*Sqrt[b^2 - 4*a*c]) + (I*PolyLog[2, (2*I*c*(1 - I*d - I*e*x))/(2*c*(I + d) - (b - Sqrt[b^2 - 4*a*c])*e)])/(2*Sqrt[b^2 - 4*a*c]) - (I*PolyLog[2, (2*I*c*(1 - I*d - I*e*x))/(2*c*(I + d) - (b + Sqrt[b^2 - 4*a*c])*e)])/(2*Sqrt[b^2 - 4*a*c]) - (I*PolyLog[2, (2*I*c*(1 + I*d + I*e*x))/(2*I*c - 2*c*d + b*e - Sqrt[b^2 - 4*a*c]*e)])/(2*Sqrt[b^2 - 4*a*c]) + (I*PolyLog[2, (2*I*c*(1 + I*d + I*e*x))/(2*c*(I - d) + (b + Sqrt[b^2 - 4*a*c])*e)])/(2*Sqrt[b^2 - 4*a*c])}


(* ::Section::Closed:: *)
(*Integrands of the form u ArcTan[a+b x^n]*)


{x^3*ArcTan[a + b*x^4], x, 2, ((a + b*x^4)*ArcTan[a + b*x^4])/(4*b) - Log[1 + (a + b*x^4)^2]/(8*b)}


{x^(n-1)*ArcTan[a + b*x^n], x, 2, ((a + b*x^n)*ArcTan[a + b*x^n])/(b*n) - Log[1 + (a + b*x^n)^2]/(2*b*n)}


(* ::Section::Closed:: *)
(*Integrands of the form u ArcTan[a+b x+c x^2]*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcTan[a+b x+c x^2]*)


{ArcTan[1 + x + x^2]/x^2, x, 7, (1/2)*ArcTan[1 + x] - ArcTan[1 + x + x^2]/x + Log[x]/2 - (1/2)*Log[1 + x^2] + (1/4)*Log[2 + 2*x + x^2]}


(* ::Section::Closed:: *)
(*Integrands involving inverse tangents of exponentials*)


{ArcTan[E^x], x, 3, (1/2)*I*PolyLog[2, (-I)*E^x] - (1/2)*I*PolyLog[2, I*E^x]}
{x*ArcTan[E^x], x, 5, (1/2)*I*x*PolyLog[2, (-I)*E^x] - (1/2)*I*x*PolyLog[2, I*E^x] - (1/2)*I*PolyLog[3, (-I)*E^x] + (1/2)*I*PolyLog[3, I*E^x]}
{x^2*ArcTan[E^x], x, 7, (1/2)*I*x^2*PolyLog[2, (-I)*E^x] - (1/2)*I*x^2*PolyLog[2, I*E^x] - I*x*PolyLog[3, (-I)*E^x] + I*x*PolyLog[3, I*E^x] + I*PolyLog[4, (-I)*E^x] - I*PolyLog[4, I*E^x]}


{ArcTan[E^(a + b*x)], x, 3, (I*PolyLog[2, (-I)*E^(a + b*x)])/(2*b) - (I*PolyLog[2, I*E^(a + b*x)])/(2*b)}
{x*ArcTan[E^(a + b*x)], x, 5, (I*x*PolyLog[2, (-I)*E^(a + b*x)])/(2*b) - (I*x*PolyLog[2, I*E^(a + b*x)])/(2*b) - (I*PolyLog[3, (-I)*E^(a + b*x)])/(2*b^2) + (I*PolyLog[3, I*E^(a + b*x)])/(2*b^2)}
{x^2*ArcTan[E^(a + b*x)], x, 7, (I*x^2*PolyLog[2, (-I)*E^(a + b*x)])/(2*b) - (I*x^2*PolyLog[2, I*E^(a + b*x)])/(2*b) - (I*x*PolyLog[3, (-I)*E^(a + b*x)])/b^2 + (I*x*PolyLog[3, I*E^(a + b*x)])/b^2 + (I*PolyLog[4, (-I)*E^(a + b*x)])/b^3 - (I*PolyLog[4, I*E^(a + b*x)])/b^3}


{ArcTan[a + b*f^(c + d*x)], x, 5, x*ArcTan[a + b*f^(c + d*x)] + (1/2)*I*x*Log[1 - (b*f^(c + d*x))/(I - a)] - (1/2)*I*x*Log[1 + (b*f^(c + d*x))/(I + a)] + (I*PolyLog[2, (b*f^(c + d*x))/(I - a)])/(2*d*Log[f]) - (I*PolyLog[2, -((b*f^(c + d*x))/(I + a))])/(2*d*Log[f]), (1/2)*I*x*Log[1 - I*a - I*b*f^(c + d*x)] - (1/2)*I*x*Log[1 + I*a + I*b*f^(c + d*x)] + (1/2)*I*x*Log[1 - (b*f^(c + d*x))/(I - a)] - (1/2)*I*x*Log[1 + (b*f^(c + d*x))/(I + a)] + (I*PolyLog[2, (b*f^(c + d*x))/(I - a)])/(2*d*Log[f]) - (I*PolyLog[2, -((b*f^(c + d*x))/(I + a))])/(2*d*Log[f])}
{x*ArcTan[a + b*f^(c + d*x)], x, 7, (1/2)*x^2*ArcTan[a + b*f^(c + d*x)] - (1/4)*I*x^2*Log[1 - (I*b*f^(c + d*x))/(1 - I*a)] + (1/4)*I*x^2*Log[1 + (I*b*f^(c + d*x))/(1 + I*a)] - (I*x*PolyLog[2, (I*b*f^(c + d*x))/(1 - I*a)])/(2*d*Log[f]) + (I*x*PolyLog[2, -((I*b*f^(c + d*x))/(1 + I*a))])/(2*d*Log[f]) + (I*PolyLog[3, (I*b*f^(c + d*x))/(1 - I*a)])/(2*d^2*Log[f]^2) - (I*PolyLog[3, -((I*b*f^(c + d*x))/(1 + I*a))])/(2*d^2*Log[f]^2), (1/4)*I*x^2*Log[1 - I*a - I*b*f^(c + d*x)] - (1/4)*I*x^2*Log[1 + I*a + I*b*f^(c + d*x)] + (1/4)*I*x^2*Log[1 - (b*f^(c + d*x))/(I - a)] - (1/4)*I*x^2*Log[1 + (b*f^(c + d*x))/(I + a)] + (I*x*PolyLog[2, (b*f^(c + d*x))/(I - a)])/(2*d*Log[f]) - (I*x*PolyLog[2, -((b*f^(c + d*x))/(I + a))])/(2*d*Log[f]) - (I*PolyLog[3, (b*f^(c + d*x))/(I - a)])/(2*d^2*Log[f]^2) + (I*PolyLog[3, -((b*f^(c + d*x))/(I + a))])/(2*d^2*Log[f]^2)}
{x^2*ArcTan[a + b*f^(c + d*x)], x, 9, (1/3)*x^3*ArcTan[a + b*f^(c + d*x)] - (1/6)*I*x^3*Log[1 - (I*b*f^(c + d*x))/(1 - I*a)] + (1/6)*I*x^3*Log[1 + (I*b*f^(c + d*x))/(1 + I*a)] - (I*x^2*PolyLog[2, (I*b*f^(c + d*x))/(1 - I*a)])/(2*d*Log[f]) + (I*x^2*PolyLog[2, -((I*b*f^(c + d*x))/(1 + I*a))])/(2*d*Log[f]) + (I*x*PolyLog[3, (I*b*f^(c + d*x))/(1 - I*a)])/(d^2*Log[f]^2) - (I*x*PolyLog[3, -((I*b*f^(c + d*x))/(1 + I*a))])/(d^2*Log[f]^2) - (I*PolyLog[4, (I*b*f^(c + d*x))/(1 - I*a)])/(d^3*Log[f]^3) + (I*PolyLog[4, -((I*b*f^(c + d*x))/(1 + I*a))])/(d^3*Log[f]^3), (1/6)*I*x^3*Log[1 - I*a - I*b*f^(c + d*x)] - (1/6)*I*x^3*Log[1 + I*a + I*b*f^(c + d*x)] + (1/6)*I*x^3*Log[1 - (b*f^(c + d*x))/(I - a)] - (1/6)*I*x^3*Log[1 + (b*f^(c + d*x))/(I + a)] + (I*x^2*PolyLog[2, (b*f^(c + d*x))/(I - a)])/(2*d*Log[f]) - (I*x^2*PolyLog[2, -((b*f^(c + d*x))/(I + a))])/(2*d*Log[f]) - (I*x*PolyLog[3, (b*f^(c + d*x))/(I - a)])/(d^2*Log[f]^2) + (I*x*PolyLog[3, -((b*f^(c + d*x))/(I + a))])/(d^2*Log[f]^2) + (I*PolyLog[4, (b*f^(c + d*x))/(I - a)])/(d^3*Log[f]^3) - (I*PolyLog[4, -((b*f^(c + d*x))/(I + a))])/(d^3*Log[f]^3)}


{ArcTan[E^x]/E^x, x, 2, x - ArcTan[E^x]/E^x - (1/2)*Log[1 + E^(2*x)]}


(* ::Section::Closed:: *)
(*Integrands involving inverse tangents of trig functions*)


{ArcTan[Tanh[a + b*x]], x, 7, x*ArcTan[Tanh[a + b*x]] - (1/2)*I*x*Log[1 - I*E^(2*a + 2*b*x)] + (1/2)*I*x*Log[1 + I*E^(2*a + 2*b*x)] + (I*PolyLog[2, (-I)*E^(2*a + 2*b*x)])/(4*b) - (I*PolyLog[2, I*E^(2*a + 2*b*x)])/(4*b)}
{ArcTan[I + d + d*Tanh[a + b*x]], x, 4, (1/2)*I*b*x^2 + I*x*ArcTanh[1 - I*d - I*d*Tanh[a + b*x]] - (1/2)*I*x*Log[1 + (1 - I*d)*E^(2*a + 2*b*x)] - (I*PolyLog[2, I*(I + d)*E^(2*a + 2*b*x)])/(4*b)}
{ArcTan[I - d - d*Tanh[a + b*x]], x, 4, (1/2)*I*b*x^2 + I*x*ArcTanh[1 + I*d + I*d*Tanh[a + b*x]] - (1/2)*I*x*Log[1 + (1 + I*d)*E^(2*a + 2*b*x)] - (I*PolyLog[2, -((1 + I*d)*E^(2*a + 2*b*x))])/(4*b)}
{ArcTan[c + d*Tanh[a + b*x]], x, 7, x*ArcTan[c + d*Tanh[a + b*x]] + (1/2)*I*x*Log[1 + ((I - c - d)*E^(2*a + 2*b*x))/(I - c + d)] - (1/2)*I*x*Log[1 + ((I + c + d)*E^(2*a + 2*b*x))/(I + c - d)] + (I*PolyLog[2, -(((I - c - d)*E^(2*a + 2*b*x))/(I - c + d))])/(4*b) - (I*PolyLog[2, -(((I + c + d)*E^(2*a + 2*b*x))/(I + c - d))])/(4*b)}


{ArcTan[Coth[a + b*x]], x, 7, x*ArcTan[Coth[a + b*x]] + (1/2)*I*x*Log[1 - I*E^(2*a + 2*b*x)] - (1/2)*I*x*Log[1 + I*E^(2*a + 2*b*x)] - (I*PolyLog[2, (-I)*E^(2*a + 2*b*x)])/(4*b) + (I*PolyLog[2, I*E^(2*a + 2*b*x)])/(4*b)}
{ArcTan[I + d + d*Coth[a + b*x]], x, 4, (1/2)*I*b*x^2 + I*x*ArcTanh[1 - I*d - I*d*Coth[a + b*x]] - (1/2)*I*x*Log[1 + I*(I + d)*E^(2*a + 2*b*x)] - (I*PolyLog[2, (1 - I*d)*E^(2*a + 2*b*x)])/(4*b)}
{ArcTan[I - d - d*Coth[a + b*x]], x, 4, (1/2)*I*b*x^2 + I*x*ArcTanh[1 + I*d + I*d*Coth[a + b*x]] - (1/2)*I*x*Log[1 - (1 + I*d)*E^(2*a + 2*b*x)] - (I*PolyLog[2, (1 + I*d)*E^(2*a + 2*b*x)])/(4*b)}
{ArcTan[c + d*Coth[a + b*x]], x, 7, x*ArcTan[c + d*Coth[a + b*x]] + (1/2)*I*x*Log[1 - ((I - c - d)*E^(2*a + 2*b*x))/(I - c + d)] - (1/2)*I*x*Log[1 - ((I + c + d)*E^(2*a + 2*b*x))/(I + c - d)] + (I*PolyLog[2, ((I - c - d)*E^(2*a + 2*b*x))/(I - c + d)])/(4*b) - (I*PolyLog[2, ((I + c + d)*E^(2*a + 2*b*x))/(I + c - d)])/(4*b)}


{ArcTan[Tan[a + b*x]], x, 2, ArcTan[Tan[a + b*x]]^2/(2*b)}
{ArcTan[I - I*d + d*Tan[a + b*x]], x, 4, -((b*x^2)/2) + I*x*ArcTanh[1 - d - I*d*Tan[a + b*x]] - (1/2)*I*x*Log[1 + (1 - d)*E^(2*I*a + 2*I*b*x)] - PolyLog[2, -((1 - d)*E^(2*I*a + 2*I*b*x))]/(4*b)}
{ArcTan[I + I*d - d*Tan[a + b*x]], x, 4, -((b*x^2)/2) + I*x*ArcTanh[1 + d + I*d*Tan[a + b*x]] - (1/2)*I*x*Log[1 + (1 + d)*E^(2*I*a + 2*I*b*x)] - PolyLog[2, -((1 + d)*E^(2*I*a + 2*I*b*x))]/(4*b)}
{ArcTan[c + d*Tan[a + b*x]], x, 7, x*ArcTan[c + d*Tan[a + b*x]] + (1/2)*I*x*Log[1 + ((c - I*(1 + d))*E^(2*I*a + 2*I*b*x))/(c - I*(1 - d))] - (1/2)*I*x*Log[1 + ((c + I*(1 - d))*E^(2*I*a + 2*I*b*x))/(c + I*(1 + d))] + PolyLog[2, -(((c - I*(1 + d))*E^(2*I*a + 2*I*b*x))/(c - I*(1 - d)))]/(4*b) - PolyLog[2, -(((c + I*(1 - d))*E^(2*I*a + 2*I*b*x))/(c + I*(1 + d)))]/(4*b)}


{ArcTan[Cot[a + b*x]], x, 2, -(ArcTan[Cot[a + b*x]]^2/(2*b))}
{ArcTan[I + I*d + d*Cot[a + b*x]], x, 4, -((b*x^2)/2) + I*x*ArcTanh[1 + d - I*d*Cot[a + b*x]] - (1/2)*I*x*Log[1 - (1 + d)*E^(2*I*a + 2*I*b*x)] - PolyLog[2, (1 + d)*E^(2*I*a + 2*I*b*x)]/(4*b)}
{ArcTan[I - I*d - d*Cot[a + b*x]], x, 4, -((b*x^2)/2) + I*x*ArcTanh[1 - d + I*d*Cot[a + b*x]] - (1/2)*I*x*Log[1 - (1 - d)*E^(2*I*a + 2*I*b*x)] - PolyLog[2, (1 - d)*E^(2*I*a + 2*I*b*x)]/(4*b)}
{ArcTan[c + d*Cot[a + b*x]], x, 7, x*ArcTan[c + d*Cot[a + b*x]] + (1/2)*I*x*Log[1 - ((c - I*(1 - d))*E^(2*I*a + 2*I*b*x))/(c - I*(1 + d))] - (1/2)*I*x*Log[1 - ((c + I*(1 + d))*E^(2*I*a + 2*I*b*x))/(c + I*(1 - d))] + PolyLog[2, ((c - I*(1 - d))*E^(2*I*a + 2*I*b*x))/(c - I*(1 + d))]/(4*b) - PolyLog[2, ((c + I*(1 + d))*E^(2*I*a + 2*I*b*x))/(c + I*(1 - d))]/(4*b)}


{ArcTan[Sinh[x]], x, 4, -2*x*ArcTan[E^x] + x*ArcTan[Sinh[x]] + I*PolyLog[2, (-I)*E^x] - I*PolyLog[2, I*E^x]}
{x*ArcTan[Sinh[x]], x, 6, (-x^2)*ArcTan[E^x] + (1/2)*x^2*ArcTan[Sinh[x]] + I*x*PolyLog[2, (-I)*E^x] - I*x*PolyLog[2, I*E^x] - I*PolyLog[3, (-I)*E^x] + I*PolyLog[3, I*E^x]}
{x^2*ArcTan[Sinh[x]], x, 8, (-(2/3))*x^3*ArcTan[E^x] + (1/3)*x^3*ArcTan[Sinh[x]] + I*x^2*PolyLog[2, (-I)*E^x] - I*x^2*PolyLog[2, I*E^x] - 2*I*x*PolyLog[3, (-I)*E^x] + 2*I*x*PolyLog[3, I*E^x] + 2*I*PolyLog[4, (-I)*E^x] - 2*I*PolyLog[4, I*E^x]}


(* ::Section::Closed:: *)
(*Integrands of the form u E^(n ArcTan[a x])*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(I n ArcTan[a x])*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{E^(I*ArcTan[a*x])*x^m, x, 2, (x^(1 + m)*AppellF1[1 + m, 1/2, -1/2, 2 + m, I*a*x, (-I)*a*x])/(1 + m)}

{E^(I*ArcTan[a*x])*x^4, x, 7, (((8*I)/15)*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/a^5 - (3*x*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/(8*a^4) - (((4*I)/15)*x^2*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/a^3 + (x^3*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/(4*a^2) + ((I/5)*x^4*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/a + (3*ArcSinh[a*x])/(8*a^5)}
{E^(I*ArcTan[a*x])*x^3, x, 6, (-2*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/(3*a^4) - (((3*I)/8)*x*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/a^3 + (x^2*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/(3*a^2) + ((I/4)*x^3*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/a + (((3*I)/8)*ArcSinh[a*x])/a^4}
{E^(I*ArcTan[a*x])*x^2, x, 6, ((-I/2)*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/a^3 - ((I/6)*Sqrt[1 - I*a*x]*(1 + I*a*x)^(3/2))/a^3 + (x*Sqrt[1 - I*a*x]*(1 + I*a*x)^(3/2))/(3*a^2) - ArcSinh[a*x]/(2*a^3)}
{E^(I*ArcTan[a*x])*x, x, 4, (Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/(2*a^2) + (Sqrt[1 - I*a*x]*(1 + I*a*x)^(3/2))/(2*a^2) - ((I/2)*ArcSinh[a*x])/a^2}
{E^(I*ArcTan[a*x]), x, 3, (I*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/a + ArcSinh[a*x]/a}
{E^(I*ArcTan[a*x])/x, x, 4, I*ArcSinh[a*x] - 2*ArcTanh[Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x]]}
{E^(I*ArcTan[a*x])/x^2, x, 3, -((Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/x) - (2*I)*a*ArcTanh[Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x]]}
{E^(I*ArcTan[a*x])/x^3, x, 5, -(Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/(2*x^2) - (I*a*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/x + a^2*ArcTanh[Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x]]}
{E^(I*ArcTan[a*x])/x^4, x, 6, -(Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/(3*x^3) - ((I/2)*a*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/x^2 + (2*a^2*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/(3*x) + I*a^3*ArcTanh[Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x]]}
{E^(I*ArcTan[a*x])/x^5, x, 7, -(Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/(4*x^4) - ((I/3)*a*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/x^3 + (3*a^2*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/(8*x^2) + (((2*I)/3)*a^3*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/x - (3*a^4*ArcTanh[Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x]])/4}


{E^((2*I)*ArcTan[a*x])*x^m, x, 3, -(x^(1 + m)/(1 + m)) + (2*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, I*a*x])/(1 + m)}

{E^((2*I)*ArcTan[a*x])*x^3, x, 3, ((-2*I)*x)/a^3 + x^2/a^2 + (((2*I)/3)*x^3)/a - x^4/4 - (2*Log[I + a*x])/a^4}
{E^((2*I)*ArcTan[a*x])*x^2, x, 3, (2*x)/a^2 + (I*x^2)/a - x^3/3 - ((2*I)*Log[I + a*x])/a^3}
{E^((2*I)*ArcTan[a*x])*x, x, 3, ((2*I)*x)/a - x^2/2 + (2*Log[I + a*x])/a^2}
{E^((2*I)*ArcTan[a*x]), x, 3, -x + ((2*I)*Log[I + a*x])/a}
{E^((2*I)*ArcTan[a*x])/x, x, 3, Log[x] - 2*Log[I + a*x]}
{E^((2*I)*ArcTan[a*x])/x^2, x, 3, -x^(-1) + (2*I)*a*Log[x] - (2*I)*a*Log[I + a*x]}
{E^((2*I)*ArcTan[a*x])/x^3, x, 3, -1/(2*x^2) - ((2*I)*a)/x - 2*a^2*Log[x] + 2*a^2*Log[I + a*x]}
{E^((2*I)*ArcTan[a*x])/x^4, x, 3, -1/(3*x^3) - (I*a)/x^2 + (2*a^2)/x - (2*I)*a^3*Log[x] + (2*I)*a^3*Log[I + a*x]}


{E^((3*I)*ArcTan[a*x])*x^m, x, 2, (x^(1 + m)*AppellF1[1 + m, 3/2, -3/2, 2 + m, I*a*x, (-I)*a*x])/(1 + m)}

{E^((3*I)*ArcTan[a*x])*x^2, x, 6, (((11*I)/2)*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/a^3 + (((11*I)/6)*Sqrt[1 - I*a*x]*(1 + I*a*x)^(3/2))/a^3 + (I*(1 + I*a*x)^(5/2))/(a^3*Sqrt[1 - I*a*x]) + ((I/3)*Sqrt[1 - I*a*x]*(1 + I*a*x)^(5/2))/a^3 + (11*ArcSinh[a*x])/(2*a^3)}
{E^((3*I)*ArcTan[a*x])*x, x, 5, (-9*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/(2*a^2) - (3*Sqrt[1 - I*a*x]*(1 + I*a*x)^(3/2))/(2*a^2) - (1 + I*a*x)^(5/2)/(a^2*Sqrt[1 - I*a*x]) + (((9*I)/2)*ArcSinh[a*x])/a^2}
{E^((3*I)*ArcTan[a*x]), x, 4, ((-3*I)*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/a - ((2*I)*(1 + I*a*x)^(3/2))/(a*Sqrt[1 - I*a*x]) - (3*ArcSinh[a*x])/a}
{E^((3*I)*ArcTan[a*x])/x, x, 7, 2*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x] + (2*(1 + I*a*x)^(3/2))/Sqrt[1 - I*a*x] - I*ArcSinh[a*x] - 2*ArcTanh[Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x]]}
{E^((3*I)*ArcTan[a*x])/x^2, x, 4, ((6*I)*a*Sqrt[1 + I*a*x])/Sqrt[1 - I*a*x] - (1 + I*a*x)^(3/2)/(x*Sqrt[1 - I*a*x]) - (6*I)*a*ArcTanh[Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x]]}
{E^((3*I)*ArcTan[a*x])/x^3, x, 6, (-7*a^2*Sqrt[1 + I*a*x])/Sqrt[1 - I*a*x] - ((2*I)*a*Sqrt[1 + I*a*x])/(x*Sqrt[1 - I*a*x]) - (1 + I*a*x)^(3/2)/(2*x^2*Sqrt[1 - I*a*x]) + 9*a^2*ArcTanh[Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x]]}
{E^((3*I)*ArcTan[a*x])/x^4, x, 7, (((-26*I)/3)*a^3*Sqrt[1 + I*a*x])/Sqrt[1 - I*a*x] - (((5*I)/6)*a*Sqrt[1 + I*a*x])/(x^2*Sqrt[1 - I*a*x]) + (19*a^2*Sqrt[1 + I*a*x])/(6*x*Sqrt[1 - I*a*x]) - (1 + I*a*x)^(3/2)/(3*x^3*Sqrt[1 - I*a*x]) + (11*I)*a^3*ArcTanh[Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x]]}


{E^((4*I)*ArcTan[a*x])*x^m, x, 4, x^(1 + m)/(1 + m) + (4*x^(1 + m))/(1 - I*a*x) - 4*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, I*a*x]}

{E^((4*I)*ArcTan[a*x])*x^3, x, 3, ((12*I)*x)/a^3 - (4*x^2)/a^2 - (((4*I)/3)*x^3)/a + x^4/4 + (4*I)/(a^4*(I + a*x)) + (16*Log[I + a*x])/a^4}
{E^((4*I)*ArcTan[a*x])*x^2, x, 3, (-8*x)/a^2 - ((2*I)*x^2)/a + x^3/3 - 4/(a^3*(I + a*x)) + ((12*I)*Log[I + a*x])/a^3}
{E^((4*I)*ArcTan[a*x])*x, x, 3, ((-4*I)*x)/a + x^2/2 - (4*I)/(a^2*(I + a*x)) - (8*Log[I + a*x])/a^2}
{E^((4*I)*ArcTan[a*x]), x, 3, x + 4/(a*(I + a*x)) - ((4*I)*Log[I + a*x])/a}
{E^((4*I)*ArcTan[a*x])/x, x, 3, (4*I)/(I + a*x) + Log[x]}
{E^((4*I)*ArcTan[a*x])/x^2, x, 3, -x^(-1) - (4*a)/(I + a*x) + (4*I)*a*Log[x] - (4*I)*a*Log[I + a*x]}
{E^((4*I)*ArcTan[a*x])/x^3, x, 3, -1/(2*x^2) - ((4*I)*a)/x - ((4*I)*a^2)/(I + a*x) - 8*a^2*Log[x] + 8*a^2*Log[I + a*x]}
{E^((4*I)*ArcTan[a*x])/x^4, x, 3, -1/(3*x^3) - ((2*I)*a)/x^2 + (8*a^2)/x + (4*a^3)/(I + a*x) - (12*I)*a^3*Log[x] + (12*I)*a^3*Log[I + a*x]}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{x^m/E^(I*ArcTan[a*x]), x, 2, (x^(1 + m)*AppellF1[1 + m, -1/2, 1/2, 2 + m, I*a*x, (-I)*a*x])/(1 + m)}

{x^3/E^(I*ArcTan[a*x]), x, 6, (-2*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/(3*a^4) + (((3*I)/8)*x*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/a^3 + (x^2*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/(3*a^2) - ((I/4)*x^3*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/a - (((3*I)/8)*ArcSinh[a*x])/a^4}
{x^2/E^(I*ArcTan[a*x]), x, 6, ((I/2)*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/a^3 + ((I/6)*(1 - I*a*x)^(3/2)*Sqrt[1 + I*a*x])/a^3 + (x*(1 - I*a*x)^(3/2)*Sqrt[1 + I*a*x])/(3*a^2) - ArcSinh[a*x]/(2*a^3)}
{x/E^(I*ArcTan[a*x]), x, 4, (Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/(2*a^2) + ((1 - I*a*x)^(3/2)*Sqrt[1 + I*a*x])/(2*a^2) + ((I/2)*ArcSinh[a*x])/a^2}
{E^((-I)*ArcTan[a*x]), x, 3, ((-I)*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/a + ArcSinh[a*x]/a}
{1/(E^(I*ArcTan[a*x])*x), x, 4, (-I)*ArcSinh[a*x] - 2*ArcTanh[Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x]]}
{1/(E^(I*ArcTan[a*x])*x^2), x, 3, -((Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/x) + (2*I)*a*ArcTanh[Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x]]}
{1/(E^(I*ArcTan[a*x])*x^3), x, 5, -(Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/(2*x^2) + (I*a*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/x + a^2*ArcTanh[Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x]]}
{1/(E^(I*ArcTan[a*x])*x^4), x, 6, -(Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/(3*x^3) + ((I/2)*a*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/x^2 + (2*a^2*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/(3*x) - I*a^3*ArcTanh[Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x]]}
{1/(E^(I*ArcTan[a*x])*x^5), x, 7, -(Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/(4*x^4) + ((I/3)*a*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/x^3 + (3*a^2*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/(8*x^2) - (((2*I)/3)*a^3*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/x - (3*a^4*ArcTanh[Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x]])/4}


{x^m/E^((2*I)*ArcTan[a*x]), x, 3, -(x^(1 + m)/(1 + m)) + (2*x^(1 + m)*Hypergeometric2F1[1, 1 + m, 2 + m, (-I)*a*x])/(1 + m)}

{x^3/E^((2*I)*ArcTan[a*x]), x, 3, ((2*I)*x)/a^3 + x^2/a^2 - (((2*I)/3)*x^3)/a - x^4/4 - (2*Log[I - a*x])/a^4}
{x^2/E^((2*I)*ArcTan[a*x]), x, 3, (2*x)/a^2 - (I*x^2)/a - x^3/3 + ((2*I)*Log[I - a*x])/a^3}
{x/E^((2*I)*ArcTan[a*x]), x, 3, ((-2*I)*x)/a - x^2/2 + (2*Log[I - a*x])/a^2}
{E^((-2*I)*ArcTan[a*x]), x, 3, -x - ((2*I)*Log[I - a*x])/a}
{1/(E^((2*I)*ArcTan[a*x])*x), x, 3, Log[x] - 2*Log[I - a*x]}
{1/(E^((2*I)*ArcTan[a*x])*x^2), x, 3, -x^(-1) - (2*I)*a*Log[x] + (2*I)*a*Log[I - a*x]}
{1/(E^((2*I)*ArcTan[a*x])*x^3), x, 3, -1/(2*x^2) + ((2*I)*a)/x - 2*a^2*Log[x] + 2*a^2*Log[I - a*x]}
{1/(E^((2*I)*ArcTan[a*x])*x^4), x, 3, -1/(3*x^3) + (I*a)/x^2 + (2*a^2)/x + (2*I)*a^3*Log[x] - (2*I)*a^3*Log[I - a*x]}


{x^m/E^((3*I)*ArcTan[a*x]), x, 2, (x^(1 + m)*AppellF1[1 + m, -3/2, 3/2, 2 + m, I*a*x, (-I)*a*x])/(1 + m)}

{x^3/E^((3*I)*ArcTan[a*x]), x, 7, ((2*I)*x^3*(1 - I*a*x)^(3/2))/(a*Sqrt[1 + I*a*x]) + (51*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/(8*a^4) + (29*(1 - I*a*x)^(3/2)*Sqrt[1 + I*a*x])/(8*a^4) - (((11*I)/4)*x*(1 - I*a*x)^(3/2)*Sqrt[1 + I*a*x])/a^3 - (9*x^2*(1 - I*a*x)^(3/2)*Sqrt[1 + I*a*x])/(4*a^2) + (((51*I)/8)*ArcSinh[a*x])/a^4}
{x^2/E^((3*I)*ArcTan[a*x]), x, 6, ((-I)*(1 - I*a*x)^(5/2))/(a^3*Sqrt[1 + I*a*x]) - (((11*I)/2)*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/a^3 - (((11*I)/6)*(1 - I*a*x)^(3/2)*Sqrt[1 + I*a*x])/a^3 - ((I/3)*(1 - I*a*x)^(5/2)*Sqrt[1 + I*a*x])/a^3 + (11*ArcSinh[a*x])/(2*a^3)}
{x/E^((3*I)*ArcTan[a*x]), x, 5, -((1 - I*a*x)^(5/2)/(a^2*Sqrt[1 + I*a*x])) - (9*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/(2*a^2) - (3*(1 - I*a*x)^(3/2)*Sqrt[1 + I*a*x])/(2*a^2) - (((9*I)/2)*ArcSinh[a*x])/a^2}
{E^((-3*I)*ArcTan[a*x]), x, 4, ((2*I)*(1 - I*a*x)^(3/2))/(a*Sqrt[1 + I*a*x]) + ((3*I)*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x])/a - (3*ArcSinh[a*x])/a}
{1/(E^((3*I)*ArcTan[a*x])*x), x, 7, (2*(1 - I*a*x)^(3/2))/Sqrt[1 + I*a*x] + 2*Sqrt[1 - I*a*x]*Sqrt[1 + I*a*x] + I*ArcSinh[a*x] - 2*ArcTanh[Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x]]}
{1/(E^((3*I)*ArcTan[a*x])*x^2), x, 4, ((-6*I)*a*Sqrt[1 - I*a*x])/Sqrt[1 + I*a*x] - (1 - I*a*x)^(3/2)/(x*Sqrt[1 + I*a*x]) + (6*I)*a*ArcTanh[Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x]]}
{1/(E^((3*I)*ArcTan[a*x])*x^3), x, 6, (-7*a^2*Sqrt[1 - I*a*x])/Sqrt[1 + I*a*x] + ((2*I)*a*Sqrt[1 - I*a*x])/(x*Sqrt[1 + I*a*x]) - (1 - I*a*x)^(3/2)/(2*x^2*Sqrt[1 + I*a*x]) + 9*a^2*ArcTanh[Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x]]}
{1/(E^((3*I)*ArcTan[a*x])*x^4), x, 7, (((26*I)/3)*a^3*Sqrt[1 - I*a*x])/Sqrt[1 + I*a*x] + (((5*I)/6)*a*Sqrt[1 - I*a*x])/(x^2*Sqrt[1 + I*a*x]) + (19*a^2*Sqrt[1 - I*a*x])/(6*x*Sqrt[1 + I*a*x]) - (1 - I*a*x)^(3/2)/(3*x^3*Sqrt[1 + I*a*x]) - (11*I)*a^3*ArcTanh[Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x]]}
{1/(E^((3*I)*ArcTan[a*x])*x^5), x, 8, (10*a^4*Sqrt[1 - I*a*x])/Sqrt[1 + I*a*x] + ((I/2)*a*Sqrt[1 - I*a*x])/(x^3*Sqrt[1 + I*a*x]) + (11*a^2*Sqrt[1 - I*a*x])/(8*x^2*Sqrt[1 + I*a*x]) - (((29*I)/8)*a^3*Sqrt[1 - I*a*x])/(x*Sqrt[1 + I*a*x]) - (1 - I*a*x)^(3/2)/(4*x^4*Sqrt[1 + I*a*x]) - (51*a^4*ArcTanh[Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x]])/4}


(* ::Subsubsection::Closed:: *)
(*n/2>0*)


{E^((I/2)*ArcTan[a*x])*x^m, x, 2, (x^(1 + m)*AppellF1[1 + m, 1/4, -1/4, 2 + m, I*a*x, (-I)*a*x])/(1 + m)}

{E^((I/2)*ArcTan[a*x])*x^2, x, 12, (((-3*I)/8)*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/a^3 - ((I/12)*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(5/4))/a^3 + (x*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(5/4))/(3*a^2) + (((3*I)/8)*ArcTan[1 - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a^3) - (((3*I)/8)*ArcTan[1 + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a^3) - (((3*I)/16)*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a^3) + (((3*I)/16)*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a^3)}
{E^((I/2)*ArcTan[a*x])*x, x, 11, ((1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/(4*a^2) + ((1 - I*a*x)^(3/4)*(1 + I*a*x)^(5/4))/(2*a^2) - ArcTan[1 - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)]/(4*Sqrt[2]*a^2) + ArcTan[1 + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)]/(4*Sqrt[2]*a^2) + Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)]/(8*Sqrt[2]*a^2) - Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)]/(8*Sqrt[2]*a^2)}
{E^((I/2)*ArcTan[a*x]), x, 10, (I*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/a - (I*ArcTan[1 - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a) + (I*ArcTan[1 + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a) + ((I/2)*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a) - ((I/2)*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a)}
{E^((I/2)*ArcTan[a*x])/x, x, 13, -2*ArcTan[(1 + I*a*x)^(1/4)/(1 - I*a*x)^(1/4)] - Sqrt[2]*ArcTan[1 - (Sqrt[2]*(1 + I*a*x)^(1/4))/(1 - I*a*x)^(1/4)] + Sqrt[2]*ArcTan[1 + (Sqrt[2]*(1 + I*a*x)^(1/4))/(1 - I*a*x)^(1/4)] - 2*ArcTanh[(1 + I*a*x)^(1/4)/(1 - I*a*x)^(1/4)] - Log[1 - (Sqrt[2]*(1 + I*a*x)^(1/4))/(1 - I*a*x)^(1/4) + Sqrt[1 + I*a*x]/Sqrt[1 - I*a*x]]/Sqrt[2] + Log[1 + (Sqrt[2]*(1 + I*a*x)^(1/4))/(1 - I*a*x)^(1/4) + Sqrt[1 + I*a*x]/Sqrt[1 - I*a*x]]/Sqrt[2]}
{E^((I/2)*ArcTan[a*x])/x^2, x, 6, -(((1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/x) + I*a*ArcTan[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)] - I*a*ArcTanh[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)]}
{E^((I/2)*ArcTan[a*x])/x^3, x, 8, -((1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/(2*x^2) - (((3*I)/4)*a*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/x - (a^2*ArcTan[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)])/4 + (a^2*ArcTanh[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)])/4}
{E^((I/2)*ArcTan[a*x])/x^4, x, 9, -((1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/(3*x^3) - (((5*I)/12)*a*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/x^2 + (11*a^2*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/(24*x) - ((3*I)/8)*a^3*ArcTan[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)] + ((3*I)/8)*a^3*ArcTanh[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)]}
{E^((I/2)*ArcTan[a*x])/x^5, x, 10, -((1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/(4*x^4) - (((7*I)/24)*a*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/x^3 + (29*a^2*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/(96*x^2) + (((83*I)/192)*a^3*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/x + (11*a^4*ArcTan[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)])/64 - (11*a^4*ArcTanh[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)])/64}
{E^((I/2)*ArcTan[a*x])/x^6, x, 11, -((1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/(5*x^5) - (((9*I)/40)*a*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/x^4 + (11*a^2*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/(48*x^3) + (((269*I)/960)*a^3*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/x^2 - (611*a^4*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/(1920*x) + ((31*I)/128)*a^5*ArcTan[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)] - ((31*I)/128)*a^5*ArcTanh[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)]}


{E^(((3*I)/2)*ArcTan[a*x])*x^m, x, 2, (x^(1 + m)*AppellF1[1 + m, 3/4, -3/4, 2 + m, I*a*x, (-I)*a*x])/(1 + m)}

{E^(((3*I)/2)*ArcTan[a*x])*x^3, x, 13, (-63*(1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/(64*a^4) - (((15*I)/32)*x*(1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/a^3 + (3*x^2*(1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/(8*a^2) + ((I/4)*x^3*(1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/a + (123*ArcTan[1 - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(64*Sqrt[2]*a^4) - (123*ArcTan[1 + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(64*Sqrt[2]*a^4) + (123*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(128*Sqrt[2]*a^4) - (123*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(128*Sqrt[2]*a^4)}
{E^(((3*I)/2)*ArcTan[a*x])*x^2, x, 12, (((-17*I)/24)*(1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/a^3 - ((I/4)*(1 - I*a*x)^(1/4)*(1 + I*a*x)^(7/4))/a^3 + (x*(1 - I*a*x)^(1/4)*(1 + I*a*x)^(7/4))/(3*a^2) + (((17*I)/8)*ArcTan[1 - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a^3) - (((17*I)/8)*ArcTan[1 + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a^3) + (((17*I)/16)*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a^3) - (((17*I)/16)*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a^3)}
{E^(((3*I)/2)*ArcTan[a*x])*x, x, 11, (3*(1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/(4*a^2) + ((1 - I*a*x)^(1/4)*(1 + I*a*x)^(7/4))/(2*a^2) - (9*ArcTan[1 - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(4*Sqrt[2]*a^2) + (9*ArcTan[1 + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(4*Sqrt[2]*a^2) - (9*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(8*Sqrt[2]*a^2) + (9*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(8*Sqrt[2]*a^2)}
{E^(((3*I)/2)*ArcTan[a*x]), x, 10, (I*(1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/a - ((3*I)*ArcTan[1 - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a) + ((3*I)*ArcTan[1 + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a) - (((3*I)/2)*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a) + (((3*I)/2)*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a)}
{E^(((3*I)/2)*ArcTan[a*x])/x, x, 13, 2*ArcTan[(1 + I*a*x)^(1/4)/(1 - I*a*x)^(1/4)] - Sqrt[2]*ArcTan[1 - (Sqrt[2]*(1 + I*a*x)^(1/4))/(1 - I*a*x)^(1/4)] + Sqrt[2]*ArcTan[1 + (Sqrt[2]*(1 + I*a*x)^(1/4))/(1 - I*a*x)^(1/4)] - 2*ArcTanh[(1 + I*a*x)^(1/4)/(1 - I*a*x)^(1/4)] + Log[1 - (Sqrt[2]*(1 + I*a*x)^(1/4))/(1 - I*a*x)^(1/4) + Sqrt[1 + I*a*x]/Sqrt[1 - I*a*x]]/Sqrt[2] - Log[1 + (Sqrt[2]*(1 + I*a*x)^(1/4))/(1 - I*a*x)^(1/4) + Sqrt[1 + I*a*x]/Sqrt[1 - I*a*x]]/Sqrt[2]}
{E^(((3*I)/2)*ArcTan[a*x])/x^2, x, 6, -(((1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/x) - (3*I)*a*ArcTan[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)] - (3*I)*a*ArcTanh[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)]}
{E^(((3*I)/2)*ArcTan[a*x])/x^3, x, 8, -((1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/(2*x^2) - (((5*I)/4)*a*(1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/x + (9*a^2*ArcTan[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)])/4 + (9*a^2*ArcTanh[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)])/4}
{E^(((3*I)/2)*ArcTan[a*x])/x^4, x, 9, -((1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/(3*x^3) - (((7*I)/12)*a*(1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/x^2 + (23*a^2*(1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/(24*x) + ((17*I)/8)*a^3*ArcTan[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)] + ((17*I)/8)*a^3*ArcTanh[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)]}
{E^(((3*I)/2)*ArcTan[a*x])/x^5, x, 10, -((1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/(4*x^4) - (((3*I)/8)*a*(1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/x^3 + (15*a^2*(1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/(32*x^2) + (((63*I)/64)*a^3*(1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/x - (123*a^4*ArcTan[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)])/64 - (123*a^4*ArcTanh[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)])/64}


{E^(((5*I)/2)*ArcTan[a*x])*x^m, x, 2, (x^(1 + m)*AppellF1[1 + m, 5/4, -5/4, 2 + m, I*a*x, (-I)*a*x])/(1 + m)}

{E^(((5*I)/2)*ArcTan[a*x])*x^3, x, 14, (475*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/(64*a^4) - ((4*I)*x^3*(1 + I*a*x)^(5/4))/(a*(1 - I*a*x)^(1/4)) + (521*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(5/4))/(96*a^4) + (((113*I)/24)*x*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(5/4))/a^3 - (17*x^2*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(5/4))/(4*a^2) - (475*ArcTan[1 - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(64*Sqrt[2]*a^4) + (475*ArcTan[1 + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(64*Sqrt[2]*a^4) + (475*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(128*Sqrt[2]*a^4) - (475*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(128*Sqrt[2]*a^4)}
{E^(((5*I)/2)*ArcTan[a*x])*x^2, x, 13, (((55*I)/8)*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/a^3 + (((11*I)/4)*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(5/4))/a^3 + ((2*I)*(1 + I*a*x)^(9/4))/(a^3*(1 - I*a*x)^(1/4)) + ((I/3)*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(9/4))/a^3 - (((55*I)/8)*ArcTan[1 - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a^3) + (((55*I)/8)*ArcTan[1 + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a^3) + (((55*I)/16)*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a^3) - (((55*I)/16)*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a^3)}
{E^(((5*I)/2)*ArcTan[a*x])*x, x, 12, (-25*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/(4*a^2) - (5*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(5/4))/(2*a^2) - (2*(1 + I*a*x)^(9/4))/(a^2*(1 - I*a*x)^(1/4)) + (25*ArcTan[1 - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(4*Sqrt[2]*a^2) - (25*ArcTan[1 + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(4*Sqrt[2]*a^2) - (25*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(8*Sqrt[2]*a^2) + (25*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(8*Sqrt[2]*a^2)}
{E^(((5*I)/2)*ArcTan[a*x]), x, 11, ((-5*I)*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/a - ((4*I)*(1 + I*a*x)^(5/4))/(a*(1 - I*a*x)^(1/4)) + ((5*I)*ArcTan[1 - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a) - ((5*I)*ArcTan[1 + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a) - (((5*I)/2)*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a) + (((5*I)/2)*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a)}
{E^(((5*I)/2)*ArcTan[a*x])/x, x, 16, 4*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4) + (4*(1 + I*a*x)^(5/4))/(1 - I*a*x)^(1/4) + 2*ArcTan[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)] - Sqrt[2]*ArcTan[1 - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)] + Sqrt[2]*ArcTan[1 + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)] - 2*ArcTanh[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)] + Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)]/Sqrt[2] - Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)]/Sqrt[2]}
{E^(((5*I)/2)*ArcTan[a*x])/x^2, x, 7, ((10*I)*a*(1 + I*a*x)^(1/4))/(1 - I*a*x)^(1/4) - (1 + I*a*x)^(5/4)/(x*(1 - I*a*x)^(1/4)) + (5*I)*a*ArcTan[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)] - (5*I)*a*ArcTanh[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)]}
{E^(((5*I)/2)*ArcTan[a*x])/x^3, x, 9, (-43*a^2*(1 + I*a*x)^(1/4))/(4*(1 - I*a*x)^(1/4)) - (((7*I)/4)*a*(1 + I*a*x)^(1/4))/(x*(1 - I*a*x)^(1/4)) - (1 + I*a*x)^(5/4)/(2*x^2*(1 - I*a*x)^(1/4)) - (25*a^2*ArcTan[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)])/4 + (25*a^2*ArcTanh[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)])/4}
{E^(((5*I)/2)*ArcTan[a*x])/x^4, x, 10, (((-287*I)/24)*a^3*(1 + I*a*x)^(1/4))/(1 - I*a*x)^(1/4) - (((3*I)/4)*a*(1 + I*a*x)^(1/4))/(x^2*(1 - I*a*x)^(1/4)) + (61*a^2*(1 + I*a*x)^(1/4))/(24*x*(1 - I*a*x)^(1/4)) - (1 + I*a*x)^(5/4)/(3*x^3*(1 - I*a*x)^(1/4)) - ((55*I)/8)*a^3*ArcTan[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)] + ((55*I)/8)*a^3*ArcTanh[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)]}
{E^(((5*I)/2)*ArcTan[a*x])/x^5, x, 11, (2467*a^4*(1 + I*a*x)^(1/4))/(192*(1 - I*a*x)^(1/4)) - (((11*I)/24)*a*(1 + I*a*x)^(1/4))/(x^3*(1 - I*a*x)^(1/4)) + (113*a^2*(1 + I*a*x)^(1/4))/(96*x^2*(1 - I*a*x)^(1/4)) + (((521*I)/192)*a^3*(1 + I*a*x)^(1/4))/(x*(1 - I*a*x)^(1/4)) - (1 + I*a*x)^(5/4)/(4*x^4*(1 - I*a*x)^(1/4)) + (475*a^4*ArcTan[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)])/64 - (475*a^4*ArcTanh[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)])/64}


(* ::Subsubsection::Closed:: *)
(*n/2<0*)


{x^m/E^((I/2)*ArcTan[a*x]), x, 2, (x^(1 + m)*AppellF1[1 + m, -1/4, 1/4, 2 + m, I*a*x, (-I)*a*x])/(1 + m)}

{x^3/E^((I/2)*ArcTan[a*x]), x, 13, (-83*(1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/(192*a^4) + (((29*I)/96)*x*(1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/a^3 + (7*x^2*(1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/(24*a^2) - ((I/4)*x^3*(1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/a - (11*ArcTan[1 - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(64*Sqrt[2]*a^4) + (11*ArcTan[1 + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(64*Sqrt[2]*a^4) - (11*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(128*Sqrt[2]*a^4) + (11*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(128*Sqrt[2]*a^4)}
{x^2/E^((I/2)*ArcTan[a*x]), x, 12, (((3*I)/8)*(1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/a^3 + ((I/12)*(1 - I*a*x)^(5/4)*(1 + I*a*x)^(3/4))/a^3 + (x*(1 - I*a*x)^(5/4)*(1 + I*a*x)^(3/4))/(3*a^2) + (((3*I)/8)*ArcTan[1 - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a^3) - (((3*I)/8)*ArcTan[1 + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a^3) + (((3*I)/16)*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a^3) - (((3*I)/16)*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a^3)}
{x/E^((I/2)*ArcTan[a*x]), x, 11, ((1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/(4*a^2) + ((1 - I*a*x)^(5/4)*(1 + I*a*x)^(3/4))/(2*a^2) + ArcTan[1 - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)]/(4*Sqrt[2]*a^2) - ArcTan[1 + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)]/(4*Sqrt[2]*a^2) + Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)]/(8*Sqrt[2]*a^2) - Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)]/(8*Sqrt[2]*a^2)}
{E^((-I/2)*ArcTan[a*x]), x, 10, ((-I)*(1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/a - (I*ArcTan[1 - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a) + (I*ArcTan[1 + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a) - ((I/2)*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a) + ((I/2)*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a)}
{1/(E^((I/2)*ArcTan[a*x])*x), x, 13, -2*ArcTan[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)] - Sqrt[2]*ArcTan[1 - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)] + Sqrt[2]*ArcTan[1 + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)] - 2*ArcTanh[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)] - Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)]/Sqrt[2] + Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)]/Sqrt[2]}
{1/(E^((I/2)*ArcTan[a*x])*x^2), x, 6, -(((1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/x) + I*a*ArcTan[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)] + I*a*ArcTanh[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)]}
{1/(E^((I/2)*ArcTan[a*x])*x^3), x, 8, -((1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/(2*x^2) + (((3*I)/4)*a*(1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/x + (a^2*ArcTan[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)])/4 + (a^2*ArcTanh[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)])/4}
{1/(E^((I/2)*ArcTan[a*x])*x^4), x, 9, -((1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/(3*x^3) + (((5*I)/12)*a*(1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/x^2 + (11*a^2*(1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/(24*x) - ((3*I)/8)*a^3*ArcTan[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)] - ((3*I)/8)*a^3*ArcTanh[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)]}
{1/(E^((I/2)*ArcTan[a*x])*x^5), x, 10, -((1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/(4*x^4) + (((7*I)/24)*a*(1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/x^3 + (29*a^2*(1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/(96*x^2) - (((83*I)/192)*a^3*(1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/x - (11*a^4*ArcTan[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)])/64 - (11*a^4*ArcTanh[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)])/64}


{x^m/E^(((3*I)/2)*ArcTan[a*x]), x, 2, (x^(1 + m)*AppellF1[1 + m, -3/4, 3/4, 2 + m, I*a*x, (-I)*a*x])/(1 + m)}

{x^3/E^(((3*I)/2)*ArcTan[a*x]), x, 13, (-63*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/(64*a^4) + (((15*I)/32)*x*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/a^3 + (3*x^2*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/(8*a^2) - ((I/4)*x^3*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/a - (123*ArcTan[1 - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(64*Sqrt[2]*a^4) + (123*ArcTan[1 + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(64*Sqrt[2]*a^4) + (123*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(128*Sqrt[2]*a^4) - (123*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(128*Sqrt[2]*a^4)}
{x^2/E^(((3*I)/2)*ArcTan[a*x]), x, 12, (((17*I)/24)*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/a^3 + ((I/4)*(1 - I*a*x)^(7/4)*(1 + I*a*x)^(1/4))/a^3 + (x*(1 - I*a*x)^(7/4)*(1 + I*a*x)^(1/4))/(3*a^2) + (((17*I)/8)*ArcTan[1 - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a^3) - (((17*I)/8)*ArcTan[1 + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a^3) - (((17*I)/16)*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a^3) + (((17*I)/16)*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a^3)}
{x/E^(((3*I)/2)*ArcTan[a*x]), x, 11, (3*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/(4*a^2) + ((1 - I*a*x)^(7/4)*(1 + I*a*x)^(1/4))/(2*a^2) + (9*ArcTan[1 - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(4*Sqrt[2]*a^2) - (9*ArcTan[1 + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(4*Sqrt[2]*a^2) - (9*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(8*Sqrt[2]*a^2) + (9*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(8*Sqrt[2]*a^2)}
{E^(((-3*I)/2)*ArcTan[a*x]), x, 10, ((-I)*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/a - ((3*I)*ArcTan[1 - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a) + ((3*I)*ArcTan[1 + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a) + (((3*I)/2)*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a) - (((3*I)/2)*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a)}
{1/(E^(((3*I)/2)*ArcTan[a*x])*x), x, 13, 2*ArcTan[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)] - Sqrt[2]*ArcTan[1 - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)] + Sqrt[2]*ArcTan[1 + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)] - 2*ArcTanh[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)] + Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)]/Sqrt[2] - Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)]/Sqrt[2]}
{1/(E^(((3*I)/2)*ArcTan[a*x])*x^2), x, 6, -(((1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/x) - (3*I)*a*ArcTan[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)] + (3*I)*a*ArcTanh[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)]}
{1/(E^(((3*I)/2)*ArcTan[a*x])*x^3), x, 8, -((1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/(2*x^2) + (((5*I)/4)*a*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/x - (9*a^2*ArcTan[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)])/4 + (9*a^2*ArcTanh[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)])/4}
{1/(E^(((3*I)/2)*ArcTan[a*x])*x^4), x, 9, -((1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/(3*x^3) + (((7*I)/12)*a*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/x^2 + (23*a^2*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/(24*x) + ((17*I)/8)*a^3*ArcTan[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)] - ((17*I)/8)*a^3*ArcTanh[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)]}
{1/(E^(((3*I)/2)*ArcTan[a*x])*x^5), x, 10, -((1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/(4*x^4) + (((3*I)/8)*a*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/x^3 + (15*a^2*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/(32*x^2) - (((63*I)/64)*a^3*(1 - I*a*x)^(3/4)*(1 + I*a*x)^(1/4))/x + (123*a^4*ArcTan[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)])/64 - (123*a^4*ArcTanh[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)])/64}


{x^m/E^(((5*I)/2)*ArcTan[a*x]), x, 2, (x^(1 + m)*AppellF1[1 + m, -5/4, 5/4, 2 + m, I*a*x, (-I)*a*x])/(1 + m)}

{x^3/E^(((5*I)/2)*ArcTan[a*x]), x, 14, ((4*I)*x^3*(1 - I*a*x)^(5/4))/(a*(1 + I*a*x)^(1/4)) + (475*(1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/(64*a^4) + (521*(1 - I*a*x)^(5/4)*(1 + I*a*x)^(3/4))/(96*a^4) - (((113*I)/24)*x*(1 - I*a*x)^(5/4)*(1 + I*a*x)^(3/4))/a^3 - (17*x^2*(1 - I*a*x)^(5/4)*(1 + I*a*x)^(3/4))/(4*a^2) + (475*ArcTan[1 - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(64*Sqrt[2]*a^4) - (475*ArcTan[1 + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(64*Sqrt[2]*a^4) + (475*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(128*Sqrt[2]*a^4) - (475*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(128*Sqrt[2]*a^4)}
{x^2/E^(((5*I)/2)*ArcTan[a*x]), x, 13, ((-2*I)*(1 - I*a*x)^(9/4))/(a^3*(1 + I*a*x)^(1/4)) - (((55*I)/8)*(1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/a^3 - (((11*I)/4)*(1 - I*a*x)^(5/4)*(1 + I*a*x)^(3/4))/a^3 - ((I/3)*(1 - I*a*x)^(9/4)*(1 + I*a*x)^(3/4))/a^3 - (((55*I)/8)*ArcTan[1 - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a^3) + (((55*I)/8)*ArcTan[1 + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a^3) - (((55*I)/16)*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a^3) + (((55*I)/16)*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a^3)}
{x/E^(((5*I)/2)*ArcTan[a*x]), x, 12, (-2*(1 - I*a*x)^(9/4))/(a^2*(1 + I*a*x)^(1/4)) - (25*(1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/(4*a^2) - (5*(1 - I*a*x)^(5/4)*(1 + I*a*x)^(3/4))/(2*a^2) - (25*ArcTan[1 - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(4*Sqrt[2]*a^2) + (25*ArcTan[1 + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(4*Sqrt[2]*a^2) - (25*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(8*Sqrt[2]*a^2) + (25*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(8*Sqrt[2]*a^2)}
{E^(((-5*I)/2)*ArcTan[a*x]), x, 11, ((4*I)*(1 - I*a*x)^(5/4))/(a*(1 + I*a*x)^(1/4)) + ((5*I)*(1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4))/a + ((5*I)*ArcTan[1 - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a) - ((5*I)*ArcTan[1 + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a) + (((5*I)/2)*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] - (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a) - (((5*I)/2)*Log[1 + Sqrt[1 - I*a*x]/Sqrt[1 + I*a*x] + (Sqrt[2]*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4)])/(Sqrt[2]*a)}
{1/(E^(((5*I)/2)*ArcTan[a*x])*x), x, 16, (4*(1 - I*a*x)^(5/4))/(1 + I*a*x)^(1/4) + 4*(1 - I*a*x)^(1/4)*(1 + I*a*x)^(3/4) + 2*ArcTan[(1 + I*a*x)^(1/4)/(1 - I*a*x)^(1/4)] - Sqrt[2]*ArcTan[1 - (Sqrt[2]*(1 + I*a*x)^(1/4))/(1 - I*a*x)^(1/4)] + Sqrt[2]*ArcTan[1 + (Sqrt[2]*(1 + I*a*x)^(1/4))/(1 - I*a*x)^(1/4)] - 2*ArcTanh[(1 + I*a*x)^(1/4)/(1 - I*a*x)^(1/4)] + Log[1 - (Sqrt[2]*(1 + I*a*x)^(1/4))/(1 - I*a*x)^(1/4) + Sqrt[1 + I*a*x]/Sqrt[1 - I*a*x]]/Sqrt[2] - Log[1 + (Sqrt[2]*(1 + I*a*x)^(1/4))/(1 - I*a*x)^(1/4) + Sqrt[1 + I*a*x]/Sqrt[1 - I*a*x]]/Sqrt[2]}
{1/(E^(((5*I)/2)*ArcTan[a*x])*x^2), x, 7, ((-10*I)*a*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4) - (1 - I*a*x)^(5/4)/(x*(1 + I*a*x)^(1/4)) + (5*I)*a*ArcTan[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)] + (5*I)*a*ArcTanh[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)]}
{1/(E^(((5*I)/2)*ArcTan[a*x])*x^3), x, 9, (-43*a^2*(1 - I*a*x)^(1/4))/(4*(1 + I*a*x)^(1/4)) + (((7*I)/4)*a*(1 - I*a*x)^(1/4))/(x*(1 + I*a*x)^(1/4)) - (1 - I*a*x)^(5/4)/(2*x^2*(1 + I*a*x)^(1/4)) + (25*a^2*ArcTan[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)])/4 + (25*a^2*ArcTanh[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)])/4}
{1/(E^(((5*I)/2)*ArcTan[a*x])*x^4), x, 10, (((287*I)/24)*a^3*(1 - I*a*x)^(1/4))/(1 + I*a*x)^(1/4) + (((3*I)/4)*a*(1 - I*a*x)^(1/4))/(x^2*(1 + I*a*x)^(1/4)) + (61*a^2*(1 - I*a*x)^(1/4))/(24*x*(1 + I*a*x)^(1/4)) - (1 - I*a*x)^(5/4)/(3*x^3*(1 + I*a*x)^(1/4)) - ((55*I)/8)*a^3*ArcTan[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)] - ((55*I)/8)*a^3*ArcTanh[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)]}
{1/(E^(((5*I)/2)*ArcTan[a*x])*x^5), x, 11, (2467*a^4*(1 - I*a*x)^(1/4))/(192*(1 + I*a*x)^(1/4)) + (((11*I)/24)*a*(1 - I*a*x)^(1/4))/(x^3*(1 + I*a*x)^(1/4)) + (113*a^2*(1 - I*a*x)^(1/4))/(96*x^2*(1 + I*a*x)^(1/4)) - (((521*I)/192)*a^3*(1 - I*a*x)^(1/4))/(x*(1 + I*a*x)^(1/4)) - (1 - I*a*x)^(5/4)/(4*x^4*(1 + I*a*x)^(1/4)) - (475*a^4*ArcTan[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)])/64 - (475*a^4*ArcTanh[(1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)])/64}


(* ::Subsubsection::Closed:: *)
(*n/3>0*)


{E^(ArcTan[x]/3)*x^m, x, 2, ((3/37 + (18*I)/37)*2^(1 - I/6)*(1 - I*x)^(1 + I/6)*x^m*AppellF1[1 + I/6, I/6, -m, 2 + I/6, (1 - I*x)/2, 1 - I*x])/(I*x)^m}

{E^(ArcTan[x]/3)*x^2, x, 4, -((1 - I*x)^(1 + I/6)*(1 + I*x)^(1 - I/6))/18 + ((1 - I*x)^(1 + I/6)*(1 + I*x)^(1 - I/6)*x)/3 - (17/333 - (34*I)/111)*2^(I/6)*(1 + I*x)^(1 - I/6)*Hypergeometric2F1[-I/6, 1 - I/6, 2 - I/6, (1 + I*x)/2]}
{E^(ArcTan[x]/3)*x, x, 3, ((1 - I*x)^(1 + I/6)*(1 + I*x)^(1 - I/6))/2 - (1/37 - (6*I)/37)*2^(I/6)*(1 + I*x)^(1 - I/6)*Hypergeometric2F1[-I/6, 1 - I/6, 2 - I/6, (1 + I*x)/2]}
{E^(ArcTan[x]/3), x, 2, (3/37 - (18*I)/37)*2^(1 + I/6)*(1 + I*x)^(1 - I/6)*Hypergeometric2F1[-I/6, 1 - I/6, 2 - I/6, (1 + I*x)/2]}
{E^(ArcTan[x]/3)/x, x, 2, (-18/37 + (3*I)/37)*2^(1 - I/6)*(1 - I*x)^(1 + I/6)*AppellF1[1 + I/6, I/6, 1, 2 + I/6, (1 - I*x)/2, 1 - I*x]}
{E^(ArcTan[x]/3)/x^2, x, 2, ((-3/37 - (18*I)/37)*2^(1 - I/6)*(1 - I*x)^(1 + I/6)*Hypergeometric2F1[I/6, 1 + I/6, 2 + I/6, ((I/2)*(2 - (2*I)*x + I*(I + x)))/x])/(I*x)^(1 + I/6)}
{E^(ArcTan[x]/3)/x^3, x, 2, ((2/37 - I/111)*(1 - I*x)^(1 + I/6)*((3 - 18*I) + 37*x + (3 + 19*I)*x^2 - (2*I)*x^2*Hypergeometric2F1[1, 1 + I/6, 2 + I/6, (I + x)/(I - x)]))/(2^(1 + I/6)*(I - x)*x^2*(1 + (I/2)*(I + x))^(I/6))}


{E^((2*ArcTan[x])/3)*x^m, x, 2, ((3/5 + (9*I)/5)*(1 - I*x)^(1 + I/3)*x^m*AppellF1[1 + I/3, I/3, -m, 2 + I/3, (1 - I*x)/2, 1 - I*x])/(2^(1 + I/3)*(I*x)^m)}

{E^((2*ArcTan[x])/3)*x^2, x, 4, -((1 - I*x)^(1 + I/3)*(1 + I*x)^(1 - I/3))/9 + ((1 - I*x)^(1 + I/3)*(1 + I*x)^(1 - I/3)*x)/3 - ((7/45 - (7*I)/15)*(1 + I*x)^(1 - I/3)*Hypergeometric2F1[-I/3, 1 - I/3, 2 - I/3, (1 + I*x)/2])/2^(1 - I/3)}
{E^((2*ArcTan[x])/3)*x, x, 3, ((1 - I*x)^(1 + I/3)*(1 + I*x)^(1 - I/3))/2 - ((1/5 - (3*I)/5)*(1 + I*x)^(1 - I/3)*Hypergeometric2F1[-I/3, 1 - I/3, 2 - I/3, (1 + I*x)/2])/2^(1 - I/3)}
{E^((2*ArcTan[x])/3), x, 2, ((3/5 - (9*I)/5)*(1 + I*x)^(1 - I/3)*Hypergeometric2F1[-I/3, 1 - I/3, 2 - I/3, (1 + I*x)/2])/2^(1 - I/3)}
{E^((2*ArcTan[x])/3)/x, x, 2, ((-9/5 + (3*I)/5)*(1 - I*x)^(1 + I/3)*AppellF1[1 + I/3, I/3, 1, 2 + I/3, (1 - I*x)/2, 1 - I*x])/2^(1 + I/3)}
{E^((2*ArcTan[x])/3)/x^2, x, 2, ((-3/5 - (9*I)/5)*(1 - I*x)^(1 + I/3)*Hypergeometric2F1[I/3, 1 + I/3, 2 + I/3, ((I/2)*(2 - (2*I)*x + I*(I + x)))/x])/(2^(1 + I/3)*(I*x)^(1 + I/3))}
{E^((2*ArcTan[x])/3)/x^3, x, 2, ((1/5 - I/15)*(1 - I*x)^(1 + I/3)*((3 - 9*I) + 20*x + (3 + 11*I)*x^2 - (4*I)*x^2*Hypergeometric2F1[1, 1 + I/3, 2 + I/3, (I + x)/(I - x)]))/(2^(2 + I/3)*(I - x)*x^2*(1 + (I/2)*(I + x))^(I/3))}


(* ::Subsubsection::Closed:: *)
(*n/4>0*)


{E^((I/4)*ArcTan[a*x])*x^m, x, 2, (x^(1 + m)*AppellF1[1 + m, 1/8, -1/8, 2 + m, I*a*x, (-I)*a*x])/(1 + m)}

{E^((I/4)*ArcTan[a*x])*x^2, x, 18, (((-11*I)/32)*(1 - I*a*x)^(7/8)*(1 + I*a*x)^(1/8))/a^3 - ((I/24)*(1 - I*a*x)^(7/8)*(1 + I*a*x)^(9/8))/a^3 + (x*(1 - I*a*x)^(7/8)*(1 + I*a*x)^(9/8))/(3*a^2) + (((11*I)/128)*Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*ArcTan[(Sqrt[2 - Sqrt[2]] - (2*(1 - I*a*x)^(1/8))/(1 + I*a*x)^(1/8))/Sqrt[2 + Sqrt[2]]])/a^3 - (((11*I)/128)*(1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*ArcTan[(Sqrt[2 + Sqrt[2]] - (2*(1 - I*a*x)^(1/8))/(1 + I*a*x)^(1/8))/Sqrt[2 - Sqrt[2]]])/a^3 - (((11*I)/128)*Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*ArcTan[(Sqrt[2 - Sqrt[2]] + (2*(1 - I*a*x)^(1/8))/(1 + I*a*x)^(1/8))/Sqrt[2 + Sqrt[2]]])/a^3 + (((11*I)/128)*(1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*ArcTan[(Sqrt[2 + Sqrt[2]] + (2*(1 - I*a*x)^(1/8))/(1 + I*a*x)^(1/8))/Sqrt[2 - Sqrt[2]]])/a^3 - (((11*I)/128)*(1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*ArcTanh[(Sqrt[2 - Sqrt[2]]*(1 - I*a*x)^(1/8))/((1 + I*a*x)^(1/8)*(1 + (1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)))])/a^3 + (((11*I)/128)*Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*ArcTanh[(Sqrt[2 + Sqrt[2]]*(1 - I*a*x)^(1/8))/((1 + I*a*x)^(1/8)*(1 + (1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)))])/a^3}
{E^((I/4)*ArcTan[a*x])*x, x, 17, ((1 - I*a*x)^(7/8)*(1 + I*a*x)^(1/8))/(8*a^2) + ((1 - I*a*x)^(7/8)*(1 + I*a*x)^(9/8))/(2*a^2) - (Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*ArcTan[(Sqrt[2 - Sqrt[2]] - (2*(1 - I*a*x)^(1/8))/(1 + I*a*x)^(1/8))/Sqrt[2 + Sqrt[2]]])/(32*a^2) + ((1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*ArcTan[(Sqrt[2 + Sqrt[2]] - (2*(1 - I*a*x)^(1/8))/(1 + I*a*x)^(1/8))/Sqrt[2 - Sqrt[2]]])/(32*a^2) + (Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*ArcTan[(Sqrt[2 - Sqrt[2]] + (2*(1 - I*a*x)^(1/8))/(1 + I*a*x)^(1/8))/Sqrt[2 + Sqrt[2]]])/(32*a^2) - ((1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*ArcTan[(Sqrt[2 + Sqrt[2]] + (2*(1 - I*a*x)^(1/8))/(1 + I*a*x)^(1/8))/Sqrt[2 - Sqrt[2]]])/(32*a^2) + ((1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*ArcTanh[(Sqrt[2 - Sqrt[2]]*(1 - I*a*x)^(1/8))/((1 + I*a*x)^(1/8)*(1 + (1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)))])/(32*a^2) - (Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*ArcTanh[(Sqrt[2 + Sqrt[2]]*(1 - I*a*x)^(1/8))/((1 + I*a*x)^(1/8)*(1 + (1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)))])/(32*a^2)}
{E^((I/4)*ArcTan[a*x]), x, 16, (I*(1 - I*a*x)^(7/8)*(1 + I*a*x)^(1/8))/a - ((I/4)*Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*ArcTan[(Sqrt[2 - Sqrt[2]] - (2*(1 - I*a*x)^(1/8))/(1 + I*a*x)^(1/8))/Sqrt[2 + Sqrt[2]]])/a + ((I/4)*(1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*ArcTan[(Sqrt[2 + Sqrt[2]] - (2*(1 - I*a*x)^(1/8))/(1 + I*a*x)^(1/8))/Sqrt[2 - Sqrt[2]]])/a + ((I/4)*Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*ArcTan[(Sqrt[2 - Sqrt[2]] + (2*(1 - I*a*x)^(1/8))/(1 + I*a*x)^(1/8))/Sqrt[2 + Sqrt[2]]])/a - ((I/4)*(1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*ArcTan[(Sqrt[2 + Sqrt[2]] + (2*(1 - I*a*x)^(1/8))/(1 + I*a*x)^(1/8))/Sqrt[2 - Sqrt[2]]])/a + ((I/4)*(1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*ArcTanh[(Sqrt[2 - Sqrt[2]]*(1 - I*a*x)^(1/8))/((1 + I*a*x)^(1/8)*(1 + (1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)))])/a - ((I/4)*Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*ArcTanh[(Sqrt[2 + Sqrt[2]]*(1 - I*a*x)^(1/8))/((1 + I*a*x)^(1/8)*(1 + (1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4)))])/a}
{E^((I/4)*ArcTan[a*x])/x, x, 25, -2*ArcTan[(1 + I*a*x)^(1/8)/(1 - I*a*x)^(1/8)] - Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*ArcTan[(Sqrt[2 - Sqrt[2]] - (2*(1 + I*a*x)^(1/8))/(1 - I*a*x)^(1/8))/Sqrt[2 + Sqrt[2]]] + (1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*ArcTan[(Sqrt[2 + Sqrt[2]] - (2*(1 + I*a*x)^(1/8))/(1 - I*a*x)^(1/8))/Sqrt[2 - Sqrt[2]]] + Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*ArcTan[(Sqrt[2 - Sqrt[2]] + (2*(1 + I*a*x)^(1/8))/(1 - I*a*x)^(1/8))/Sqrt[2 + Sqrt[2]]] - (1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*ArcTan[(Sqrt[2 + Sqrt[2]] + (2*(1 + I*a*x)^(1/8))/(1 - I*a*x)^(1/8))/Sqrt[2 - Sqrt[2]]] + Sqrt[2]*ArcTan[1 - (Sqrt[2]*(1 + I*a*x)^(1/8))/(1 - I*a*x)^(1/8)] - Sqrt[2]*ArcTan[1 + (Sqrt[2]*(1 + I*a*x)^(1/8))/(1 - I*a*x)^(1/8)] - 2*ArcTanh[(1 + I*a*x)^(1/8)/(1 - I*a*x)^(1/8)] - (1 - Sqrt[2])*Sqrt[2 + Sqrt[2]]*ArcTanh[(Sqrt[2 - Sqrt[2]]*(1 + I*a*x)^(1/8))/((1 - I*a*x)^(1/8)*(1 + (1 + I*a*x)^(1/4)/(1 - I*a*x)^(1/4)))] + Sqrt[2 - Sqrt[2]]*(1 + Sqrt[2])*ArcTanh[(Sqrt[2 + Sqrt[2]]*(1 + I*a*x)^(1/8))/((1 - I*a*x)^(1/8)*(1 + (1 + I*a*x)^(1/4)/(1 - I*a*x)^(1/4)))] + Log[1 - (Sqrt[2]*(1 + I*a*x)^(1/8))/(1 - I*a*x)^(1/8) + (1 + I*a*x)^(1/4)/(1 - I*a*x)^(1/4)]/Sqrt[2] - Log[1 + (Sqrt[2]*(1 + I*a*x)^(1/8))/(1 - I*a*x)^(1/8) + (1 + I*a*x)^(1/4)/(1 - I*a*x)^(1/4)]/Sqrt[2]}
{E^((I/4)*ArcTan[a*x])/x^2, x, 14, -(((1 - I*a*x)^(7/8)*(1 + I*a*x)^(1/8))/x) + (I/2)*a*ArcTan[(1 - I*a*x)^(1/8)/(1 + I*a*x)^(1/8)] - ((I/2)*a*ArcTan[1 - (Sqrt[2]*(1 - I*a*x)^(1/8))/(1 + I*a*x)^(1/8)])/Sqrt[2] + ((I/2)*a*ArcTan[1 + (Sqrt[2]*(1 - I*a*x)^(1/8))/(1 + I*a*x)^(1/8)])/Sqrt[2] - (I/2)*a*ArcTanh[(1 - I*a*x)^(1/8)/(1 + I*a*x)^(1/8)] + ((I/4)*a*Log[1 + (1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4) - (Sqrt[2]*(1 - I*a*x)^(1/8))/(1 + I*a*x)^(1/8)])/Sqrt[2] - ((I/4)*a*Log[1 + (1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4) + (Sqrt[2]*(1 - I*a*x)^(1/8))/(1 + I*a*x)^(1/8)])/Sqrt[2]}
{E^((I/4)*ArcTan[a*x])/x^3, x, 16, -((1 - I*a*x)^(7/8)*(1 + I*a*x)^(1/8))/(2*x^2) - (((5*I)/8)*a*(1 - I*a*x)^(7/8)*(1 + I*a*x)^(1/8))/x - (a^2*ArcTan[(1 - I*a*x)^(1/8)/(1 + I*a*x)^(1/8)])/16 + (a^2*ArcTan[1 - (Sqrt[2]*(1 - I*a*x)^(1/8))/(1 + I*a*x)^(1/8)])/(16*Sqrt[2]) - (a^2*ArcTan[1 + (Sqrt[2]*(1 - I*a*x)^(1/8))/(1 + I*a*x)^(1/8)])/(16*Sqrt[2]) + (a^2*ArcTanh[(1 - I*a*x)^(1/8)/(1 + I*a*x)^(1/8)])/16 - (a^2*Log[1 + (1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4) - (Sqrt[2]*(1 - I*a*x)^(1/8))/(1 + I*a*x)^(1/8)])/(32*Sqrt[2]) + (a^2*Log[1 + (1 - I*a*x)^(1/4)/(1 + I*a*x)^(1/4) + (Sqrt[2]*(1 - I*a*x)^(1/8))/(1 + I*a*x)^(1/8)])/(32*Sqrt[2])}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{E^(I*n*ArcTan[a*x])*x^m, x, 2, (x^(1 + m)*AppellF1[1 + m, n/2, -n/2, 2 + m, I*a*x, (-I)*a*x])/(1 + m)}

{E^(I*n*ArcTan[a*x])*x^3, x, 2, (1/4)*x^4*AppellF1[4, n/2, -(n/2), 5, I*a*x, (-I)*a*x]}
{E^(I*n*ArcTan[a*x])*x^2, x, 4, ((-I/6)*n*(1 - I*a*x)^(1 - n/2)*(1 + I*a*x)^((2 + n)/2))/a^3 + (x*(1 - I*a*x)^(1 - n/2)*(1 + I*a*x)^((2 + n)/2))/(3*a^2) + ((I/3)*(2 + n^2)*(1 + I*a*x)^((2 + n)/2)*Hypergeometric2F1[n/2, (2 + n)/2, (4 + n)/2, (1 + I*a*x)/2])/(2^(n/2)*a^3*(2 + n))}
{E^(I*n*ArcTan[a*x])*x, x, 3, ((1 - I*a*x)^(1 - n/2)*(1 + I*a*x)^((2 + n)/2))/(2*a^2) - (n*(1 + I*a*x)^((2 + n)/2)*Hypergeometric2F1[n/2, (2 + n)/2, (4 + n)/2, (1 + I*a*x)/2])/(2^(n/2)*a^2*(2 + n))}
{E^(I*n*ArcTan[a*x]), x, 2, ((-I)*2^(1 - n/2)*(1 + I*a*x)^((2 + n)/2)*Hypergeometric2F1[n/2, (2 + n)/2, (4 + n)/2, (1 + I*a*x)/2])/(a*(2 + n))}
{E^(I*n*ArcTan[a*x])/x, x, 2, -((2^(1 + n/2)*(1 - I*a*x)^(1 - n/2)*AppellF1[1 - n/2, 1, -n/2, 2 - n/2, 1 - I*a*x, (1 - I*a*x)/2])/(2 - n))}
{E^(I*n*ArcTan[a*x])/x^2, x, 2, ((-I)*2^(1 + n/2)*a*(1 - I*a*x)^(1 - n/2)*(1 + (-1 + I*a*x)/2)^((-2 + n)/2)*Hypergeometric2F1[2, 1 - n/2, 2 - n/2, (1 - I*a*x)/(1 + I*a*x)])/(2 - n)}
{E^(I*n*ArcTan[a*x])/x^3, x, 2, (2^(1 + n/2)*a^2*(1 - I*a*x)^(1 - n/2)*Defer[AppellF1][1 - n/2, 3, -(n/2), 2 - n/2, 1 - I*a*x, (1/2)*(1 - I*a*x)])/(2 - n)}
{E^(I*n*ArcTan[a*x])/x^4, x, 2, (I*2^(1 + n/2)*a^3*(1 - I*a*x)^(1 - n/2)*Defer[AppellF1][1 - n/2, 4, -(n/2), 2 - n/2, 1 - I*a*x, (1/2)*(1 - I*a*x)])/(2 - n)}


(* ::Subsection::Closed:: *)
(*Integrands of the form E^(n ArcTan[a x]) (c+c a^2 x^2)^p*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{E^ArcTan[a*x]*(c + c*a^2*x^2)^p, x, 3, -((2^((1 + I/2) + p)*(1 + I*a*x)^((1 - I/2) + p)*(c + a^2*c*x^2)^p*Hypergeometric2F1[-(I/2) - p, (1 - I/2) + p, (2 - I/2) + p, (1/2)*(1 + I*a*x)])/((1 + a^2*x^2)^p*(a*((-1 - 2*I) - 2*I*p))))}

{E^ArcTan[a*x]*(c + c*a^2*x^2)^3, x, 2, ((1/65 - (8*I)/65)*2^(4 + I/2)*c^3*(1 + I*a*x)^(4 - I/2)*Hypergeometric2F1[-3 - I/2, 4 - I/2, 5 - I/2, (1/2)*(1 + I*a*x)])/a}
{E^ArcTan[a*x]*(c + c*a^2*x^2)^2, x, 2, ((1/37 - (6*I)/37)*2^(3 + I/2)*c^2*(1 + I*a*x)^(3 - I/2)*Hypergeometric2F1[-2 - I/2, 3 - I/2, 4 - I/2, (1/2)*(1 + I*a*x)])/a}
{E^ArcTan[a*x]*(c + c*a^2*x^2)^1, x, 2, ((1/17 - (4*I)/17)*2^(2 + I/2)*c*(1 + I*a*x)^(2 - I/2)*Hypergeometric2F1[-1 - I/2, 2 - I/2, 3 - I/2, (1/2)*(1 + I*a*x)])/a}
{E^ArcTan[a*x]*(c + c*a^2*x^2)^0, x, 2, ((1/5 - (2*I)/5)*2^(1 + I/2)*(1 + I*a*x)^(1 - I/2)*Hypergeometric2F1[-(I/2), 1 - I/2, 2 - I/2, (1/2)*(1 + I*a*x)])/a}
{E^ArcTan[a*x]/(c + c*a^2*x^2)^1, x, 1, E^ArcTan[a*x]/(a*c)}
{E^ArcTan[a*x]/(c + c*a^2*x^2)^2, x, 2, (2*E^ArcTan[a*x])/(5*a*c^2) + (E^ArcTan[a*x]*(1 + 2*a*x))/(5*a*c^2*(1 + a^2*x^2))}
{E^ArcTan[a*x]/(c + c*a^2*x^2)^3, x, 3, (24*E^ArcTan[a*x])/(85*a*c^3) + (E^ArcTan[a*x]*(1 + 4*a*x))/(17*a*c^3*(1 + a^2*x^2)^2) + (12*E^ArcTan[a*x]*(1 + 2*a*x))/(85*a*c^3*(1 + a^2*x^2))}
{E^ArcTan[a*x]/(c + c*a^2*x^2)^4, x, 4, (144*E^ArcTan[a*x])/(629*a*c^4) + (E^ArcTan[a*x]*(1 + 6*a*x))/(37*a*c^4*(1 + a^2*x^2)^3) + (30*E^ArcTan[a*x]*(1 + 4*a*x))/(629*a*c^4*(1 + a^2*x^2)^2) + (72*E^ArcTan[a*x]*(1 + 2*a*x))/(629*a*c^4*(1 + a^2*x^2))}
{E^ArcTan[a*x]/(c + c*a^2*x^2)^5, x, 5, (8064*E^ArcTan[a*x])/(40885*a*c^5) + (E^ArcTan[a*x]*(1 + 8*a*x))/(65*a*c^5*(1 + a^2*x^2)^4) + (56*E^ArcTan[a*x]*(1 + 6*a*x))/(2405*a*c^5*(1 + a^2*x^2)^3) + (336*E^ArcTan[a*x]*(1 + 4*a*x))/(8177*a*c^5*(1 + a^2*x^2)^2) + (4032*E^ArcTan[a*x]*(1 + 2*a*x))/(40885*a*c^5*(1 + a^2*x^2))}


{E^(2*ArcTan[a*x])*(c + c*a^2*x^2)^p, x, 3, -((I*2^(I + p)*(1 + I*a*x)^((1 - I) + p)*(c + a^2*c*x^2)^p*Hypergeometric2F1[-I - p, (1 - I) + p, (2 - I) + p, (1/2)*(1 + I*a*x)])/((1 + a^2*x^2)^p*(a*((1 - I) + p))))}

{E^(2*ArcTan[a*x])*(c + c*a^2*x^2)^3, x, 2, ((1/17 - (4*I)/17)*2^(3 + I)*c^3*(1 + I*a*x)^(4 - I)*Hypergeometric2F1[-3 - I, 4 - I, 5 - I, (1/2)*(1 + I*a*x)])/a}
{E^(2*ArcTan[a*x])*(c + c*a^2*x^2)^2, x, 2, ((1/5 - (3*I)/5)*2^(1 + I)*c^2*(1 + I*a*x)^(3 - I)*Hypergeometric2F1[-2 - I, 3 - I, 4 - I, (1/2)*(1 + I*a*x)])/a}
{E^(2*ArcTan[a*x])*(c + c*a^2*x^2)^1, x, 2, ((1/5 - (2*I)/5)*2^(1 + I)*c*(1 + I*a*x)^(2 - I)*Hypergeometric2F1[-1 - I, 2 - I, 3 - I, (1/2)*(1 + I*a*x)])/a}
{E^(2*ArcTan[a*x])*(c + c*a^2*x^2)^0, x, 2, ((1 - I)*2^(-1 + I)*(1 + I*a*x)^(1 - I)*Hypergeometric2F1[-I, 1 - I, 2 - I, (1/2)*(1 + I*a*x)])/a}
{E^(2*ArcTan[a*x])/(c + c*a^2*x^2)^1, x, 1, E^(2*ArcTan[a*x])/(2*a*c)}
{E^(2*ArcTan[a*x])/(c + c*a^2*x^2)^2, x, 2, E^(2*ArcTan[a*x])/(8*a*c^2) + (E^(2*ArcTan[a*x])*(1 + a*x))/(4*a*c^2*(1 + a^2*x^2))}
{E^(2*ArcTan[a*x])/(c + c*a^2*x^2)^3, x, 3, (3*E^(2*ArcTan[a*x]))/(40*a*c^3) + (E^(2*ArcTan[a*x])*(1 + 2*a*x))/(10*a*c^3*(1 + a^2*x^2)^2) + (3*E^(2*ArcTan[a*x])*(1 + a*x))/(20*a*c^3*(1 + a^2*x^2))}
{E^(2*ArcTan[a*x])/(c + c*a^2*x^2)^4, x, 4, (9*E^(2*ArcTan[a*x]))/(160*a*c^4) + (E^(2*ArcTan[a*x])*(1 + 3*a*x))/(20*a*c^4*(1 + a^2*x^2)^3) + (3*E^(2*ArcTan[a*x])*(1 + 2*a*x))/(40*a*c^4*(1 + a^2*x^2)^2) + (9*E^(2*ArcTan[a*x])*(1 + a*x))/(80*a*c^4*(1 + a^2*x^2))}


{E^(3*ArcTan[a*x])*(c + c*a^2*x^2)^p, x, 3, -((2^((1 + (3*I)/2) + p)*(1 + I*a*x)^((1 - (3*I)/2) + p)*(c + a^2*c*x^2)^p*Hypergeometric2F1[-((3*I)/2) - p, (1 - (3*I)/2) + p, (2 - (3*I)/2) + p, (1/2)*(1 + I*a*x)])/((1 + a^2*x^2)^p*(a*((-3 - 2*I) - 2*I*p))))}

{E^(3*ArcTan[a*x])*(c + c*a^2*x^2)^3, x, 2, ((3/73 - (8*I)/73)*2^(4 + (3*I)/2)*c^3*(1 + I*a*x)^(4 - (3*I)/2)*Hypergeometric2F1[-3 - (3*I)/2, 4 - (3*I)/2, 5 - (3*I)/2, (1/2)*(1 + I*a*x)])/a}
{E^(3*ArcTan[a*x])*(c + c*a^2*x^2)^2, x, 2, ((1/15 - (2*I)/15)*2^(3 + (3*I)/2)*c^2*(1 + I*a*x)^(3 - (3*I)/2)*Hypergeometric2F1[-2 - (3*I)/2, 3 - (3*I)/2, 4 - (3*I)/2, (1/2)*(1 + I*a*x)])/a}
{E^(3*ArcTan[a*x])*(c + c*a^2*x^2)^1, x, 2, ((3/25 - (4*I)/25)*2^(2 + (3*I)/2)*c*(1 + I*a*x)^(2 - (3*I)/2)*Hypergeometric2F1[-1 - (3*I)/2, 2 - (3*I)/2, 3 - (3*I)/2, (1/2)*(1 + I*a*x)])/a}
{E^(3*ArcTan[a*x])*(c + c*a^2*x^2)^0, x, 2, ((3/13 - (2*I)/13)*2^(1 + (3*I)/2)*(1 + I*a*x)^(1 - (3*I)/2)*Hypergeometric2F1[-((3*I)/2), 1 - (3*I)/2, 2 - (3*I)/2, (1/2)*(1 + I*a*x)])/a}
{E^(3*ArcTan[a*x])/(c + c*a^2*x^2)^1, x, 1, E^(3*ArcTan[a*x])/(3*a*c)}
{E^(3*ArcTan[a*x])/(c + c*a^2*x^2)^2, x, 2, (2*E^(3*ArcTan[a*x]))/(39*a*c^2) + (E^(3*ArcTan[a*x])*(3 + 2*a*x))/(13*a*c^2*(1 + a^2*x^2))}
{E^(3*ArcTan[a*x])/(c + c*a^2*x^2)^3, x, 3, (8*E^(3*ArcTan[a*x]))/(325*a*c^3) + (E^(3*ArcTan[a*x])*(3 + 4*a*x))/(25*a*c^3*(1 + a^2*x^2)^2) + (12*E^(3*ArcTan[a*x])*(3 + 2*a*x))/(325*a*c^3*(1 + a^2*x^2))}
{E^(3*ArcTan[a*x])/(c + c*a^2*x^2)^4, x, 4, (16*E^(3*ArcTan[a*x]))/(975*a*c^4) + (E^(3*ArcTan[a*x])*(1 + 2*a*x))/(15*a*c^4*(1 + a^2*x^2)^3) + (2*E^(3*ArcTan[a*x])*(3 + 4*a*x))/(75*a*c^4*(1 + a^2*x^2)^2) + (8*E^(3*ArcTan[a*x])*(3 + 2*a*x))/(325*a*c^4*(1 + a^2*x^2))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{1/E^ArcTan[a*x]*(c + c*a^2*x^2)^p, x, 3, -((I*2^((1 - I/2) + p)*(1 + I*a*x)^((1 + I/2) + p)*(c + a^2*c*x^2)^p*Hypergeometric2F1[I/2 - p, (1 + I/2) + p, (2 + I/2) + p, (1/2)*(1 + I*a*x)])/((1 + a^2*x^2)^p*(a*((2 + I) + 2*p))))}

{1/E^ArcTan[a*x]*(c + c*a^2*x^2)^3, x, 2, -(((1/65 + (8*I)/65)*2^(4 - I/2)*c^3*(1 + I*a*x)^(4 + I/2)*Hypergeometric2F1[-3 + I/2, 4 + I/2, 5 + I/2, (1/2)*(1 + I*a*x)])/a)}
{1/E^ArcTan[a*x]*(c + c*a^2*x^2)^2, x, 2, -(((1/37 + (6*I)/37)*2^(3 - I/2)*c^2*(1 + I*a*x)^(3 + I/2)*Hypergeometric2F1[-2 + I/2, 3 + I/2, 4 + I/2, (1/2)*(1 + I*a*x)])/a)}
{1/E^ArcTan[a*x]*(c + c*a^2*x^2)^1, x, 2, -(((1/17 + (4*I)/17)*2^(2 - I/2)*c*(1 + I*a*x)^(2 + I/2)*Hypergeometric2F1[-1 + I/2, 2 + I/2, 3 + I/2, (1/2)*(1 + I*a*x)])/a)}
{1/E^ArcTan[a*x]*(c + c*a^2*x^2)^0, x, 2, -(((1/5 + (2*I)/5)*2^(1 - I/2)*(1 + I*a*x)^(1 + I/2)*Hypergeometric2F1[I/2, 1 + I/2, 2 + I/2, (1/2)*(1 + I*a*x)])/a)}
{1/E^ArcTan[a*x]/(c + c*a^2*x^2)^1, x, 1, -(1/(E^ArcTan[a*x]*(a*c)))}
{1/E^ArcTan[a*x]/(c + c*a^2*x^2)^2, x, 2, -(2/(E^ArcTan[a*x]*(5*a*c^2))) - (1 - 2*a*x)/(E^ArcTan[a*x]*(5*a*c^2*(1 + a^2*x^2)))}
{1/E^ArcTan[a*x]/(c + c*a^2*x^2)^3, x, 3, -(24/(E^ArcTan[a*x]*(85*a*c^3))) - (1 - 4*a*x)/(E^ArcTan[a*x]*(17*a*c^3*(1 + a^2*x^2)^2)) - (12*(1 - 2*a*x))/(E^ArcTan[a*x]*(85*a*c^3*(1 + a^2*x^2)))}
{1/E^ArcTan[a*x]/(c + c*a^2*x^2)^4, x, 4, -(144/(E^ArcTan[a*x]*(629*a*c^4))) - (1 - 6*a*x)/(E^ArcTan[a*x]*(37*a*c^4*(1 + a^2*x^2)^3)) - (30*(1 - 4*a*x))/(E^ArcTan[a*x]*(629*a*c^4*(1 + a^2*x^2)^2)) - (72*(1 - 2*a*x))/(E^ArcTan[a*x]*(629*a*c^4*(1 + a^2*x^2)))}


{1/E^(2*ArcTan[a*x])*(c + c*a^2*x^2)^p, x, 3, -((I*2^(-I + p)*(1 + I*a*x)^((1 + I) + p)*(c + a^2*c*x^2)^p*Hypergeometric2F1[I - p, (1 + I) + p, (2 + I) + p, (1/2)*(1 + I*a*x)])/((1 + a^2*x^2)^p*(a*((1 + I) + p))))}

{1/E^(2*ArcTan[a*x])*(c + c*a^2*x^2)^3, x, 2, -(((1/17 + (4*I)/17)*2^(3 - I)*c^3*(1 + I*a*x)^(4 + I)*Hypergeometric2F1[-3 + I, 4 + I, 5 + I, (1/2)*(1 + I*a*x)])/a)}
{1/E^(2*ArcTan[a*x])*(c + c*a^2*x^2)^2, x, 2, -(((1/5 + (3*I)/5)*2^(1 - I)*c^2*(1 + I*a*x)^(3 + I)*Hypergeometric2F1[-2 + I, 3 + I, 4 + I, (1/2)*(1 + I*a*x)])/a)}
{1/E^(2*ArcTan[a*x])*(c + c*a^2*x^2)^1, x, 2, -(((1/5 + (2*I)/5)*2^(1 - I)*c*(1 + I*a*x)^(2 + I)*Hypergeometric2F1[-1 + I, 2 + I, 3 + I, (1/2)*(1 + I*a*x)])/a)}
{1/E^(2*ArcTan[a*x])*(c + c*a^2*x^2)^0, x, 2, -(((1 + I)*2^(-1 - I)*(1 + I*a*x)^(1 + I)*Hypergeometric2F1[I, 1 + I, 2 + I, (1/2)*(1 + I*a*x)])/a)}
{1/E^(2*ArcTan[a*x])/(c + c*a^2*x^2)^1, x, 1, -(1/(E^(2*ArcTan[a*x])*(2*a*c)))}
{1/E^(2*ArcTan[a*x])/(c + c*a^2*x^2)^2, x, 2, -(1/(E^(2*ArcTan[a*x])*(8*a*c^2))) - (1 - a*x)/(E^(2*ArcTan[a*x])*(4*a*c^2*(1 + a^2*x^2)))}
{1/E^(2*ArcTan[a*x])/(c + c*a^2*x^2)^3, x, 3, -(3/(E^(2*ArcTan[a*x])*(40*a*c^3))) - (1 - 2*a*x)/(E^(2*ArcTan[a*x])*(10*a*c^3*(1 + a^2*x^2)^2)) - (3*(1 - a*x))/(E^(2*ArcTan[a*x])*(20*a*c^3*(1 + a^2*x^2)))}
{1/E^(2*ArcTan[a*x])/(c + c*a^2*x^2)^4, x, 4, -(9/(E^(2*ArcTan[a*x])*(160*a*c^4))) - (1 - 3*a*x)/(E^(2*ArcTan[a*x])*(20*a*c^4*(1 + a^2*x^2)^3)) - (3*(1 - 2*a*x))/(E^(2*ArcTan[a*x])*(40*a*c^4*(1 + a^2*x^2)^2)) - (9*(1 - a*x))/(E^(2*ArcTan[a*x])*(80*a*c^4*(1 + a^2*x^2)))}


{1/E^(3*ArcTan[a*x])*(c + c*a^2*x^2)^p, x, 3, -((I*2^((1 - (3*I)/2) + p)*(1 + I*a*x)^((1 + (3*I)/2) + p)*(c + a^2*c*x^2)^p*Hypergeometric2F1[(3*I)/2 - p, (1 + (3*I)/2) + p, (2 + (3*I)/2) + p, (1/2)*(1 + I*a*x)])/((1 + a^2*x^2)^p*(a*((2 + 3*I) + 2*p))))}

{1/E^(3*ArcTan[a*x])*(c + c*a^2*x^2)^3, x, 2, -(((3/73 + (8*I)/73)*2^(4 - (3*I)/2)*c^3*(1 + I*a*x)^(4 + (3*I)/2)*Hypergeometric2F1[-3 + (3*I)/2, 4 + (3*I)/2, 5 + (3*I)/2, (1/2)*(1 + I*a*x)])/a)}
{1/E^(3*ArcTan[a*x])*(c + c*a^2*x^2)^2, x, 2, -(((1/15 + (2*I)/15)*2^(3 - (3*I)/2)*c^2*(1 + I*a*x)^(3 + (3*I)/2)*Hypergeometric2F1[-2 + (3*I)/2, 3 + (3*I)/2, 4 + (3*I)/2, (1/2)*(1 + I*a*x)])/a)}
{1/E^(3*ArcTan[a*x])*(c + c*a^2*x^2)^1, x, 2, -(((3/25 + (4*I)/25)*2^(2 - (3*I)/2)*c*(1 + I*a*x)^(2 + (3*I)/2)*Hypergeometric2F1[-1 + (3*I)/2, 2 + (3*I)/2, 3 + (3*I)/2, (1/2)*(1 + I*a*x)])/a)}
{1/E^(3*ArcTan[a*x])*(c + c*a^2*x^2)^0, x, 2, -(((3/13 + (2*I)/13)*2^(1 - (3*I)/2)*(1 + I*a*x)^(1 + (3*I)/2)*Hypergeometric2F1[(3*I)/2, 1 + (3*I)/2, 2 + (3*I)/2, (1/2)*(1 + I*a*x)])/a)}
{1/E^(3*ArcTan[a*x])/(c + c*a^2*x^2)^1, x, 1, -(1/(E^(3*ArcTan[a*x])*(3*a*c)))}
{1/E^(3*ArcTan[a*x])/(c + c*a^2*x^2)^2, x, 2, -(2/(E^(3*ArcTan[a*x])*(39*a*c^2))) - (3 - 2*a*x)/(E^(3*ArcTan[a*x])*(13*a*c^2*(1 + a^2*x^2)))}
{1/E^(3*ArcTan[a*x])/(c + c*a^2*x^2)^3, x, 3, -(8/(E^(3*ArcTan[a*x])*(325*a*c^3))) - (3 - 4*a*x)/(E^(3*ArcTan[a*x])*(25*a*c^3*(1 + a^2*x^2)^2)) - (12*(3 - 2*a*x))/(E^(3*ArcTan[a*x])*(325*a*c^3*(1 + a^2*x^2)))}
{1/E^(3*ArcTan[a*x])/(c + c*a^2*x^2)^4, x, 4, -(16/(E^(3*ArcTan[a*x])*(975*a*c^4))) - (1 - 2*a*x)/(E^(3*ArcTan[a*x])*(15*a*c^4*(1 + a^2*x^2)^3)) - (2*(3 - 4*a*x))/(E^(3*ArcTan[a*x])*(75*a*c^4*(1 + a^2*x^2)^2)) - (8*(3 - 2*a*x))/(E^(3*ArcTan[a*x])*(325*a*c^4*(1 + a^2*x^2)))}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{(c + c*a^2*x^2)^p/E^(2*I*p*ArcTan[a*x]), x, 3, (I*(1 - I*a*x)^(1 + 2*p)*(c + a^2*c*x^2)^p)/((1 + a^2*x^2)^p*(a*(1 + 2*p)))}
{(c + c*a^2*x^2)^p/E^(-2*I*p*ArcTan[a*x]), x, 3, -((I*(1 + I*a*x)^(1 + 2*p)*(c + a^2*c*x^2)^p)/((1 + a^2*x^2)^p*(a*(1 + 2*p))))}


{E^(n*ArcTan[a*x])*(c + c*a^2*x^2)^p, x, 3, (2^(1 + (I*n)/2 + p)*(1 + I*a*x)^(1 - (I*n)/2 + p)*(c + a^2*c*x^2)^p*Hypergeometric2F1[-((I*n)/2) - p, 1 - (I*n)/2 + p, 2 - (I*n)/2 + p, (1/2)*(1 + I*a*x)])/((1 + a^2*x^2)^p*(a*(n + 2*I*(1 + p))))}

{E^(n*ArcTan[a*x])*(c + c*a^2*x^2)^2, x, 6, (2^(3 + (I*n)/2)*(1 + I*a*x)^(3 - (I*n)/2)*(c + a^2*c*x^2)^2*Hypergeometric2F1[-2 - (I*n)/2, 3 - (I*n)/2, 4 - (I*n)/2, (1/2)*(1 + I*a*x)])/(a*(6*I + n)*(1 + a^2*x^2)^2), (c^2*(4*I - n)*(2*I + n)*(4*I + n)*(1 - I*a*x)^(1 + (I*n)/2)*(1 + I*a*x)^(1 - (I*n)/2))/(120*a) - (c^2*(4 - I*n)*(2*I + n)*(1 - I*a*x)^(2 + (I*n)/2)*(1 + I*a*x)^(1 - (I*n)/2))/(60*a) + (c^2*(4*I + n)*(1 - I*a*x)^(3 + (I*n)/2)*(1 + I*a*x)^(1 - (I*n)/2))/(20*a) + (I*c^2*(1 - I*a*x)^(3 + (I*n)/2)*(1 + I*a*x)^(2 - (I*n)/2))/(5*a) + (2^(-2 + (I*n)/2)*c^2*(2*I - n)*(4*I - n)*(4*I + n)*(1 + I*a*x)^(1 - (I*n)/2)*Hypergeometric2F1[1 - (I*n)/2, -((I*n)/2), 2 - (I*n)/2, (1/2)*(1 + I*a*x)])/(15*a)}
{E^(n*ArcTan[a*x])*(c + c*a^2*x^2)^1, x, 4, (2^(2 + (I*n)/2)*(1 + I*a*x)^(2 - (I*n)/2)*(c + a^2*c*x^2)*Hypergeometric2F1[-1 - (I*n)/2, 2 - (I*n)/2, 3 - (I*n)/2, (1/2)*(1 + I*a*x)])/(a*(4*I + n)*(1 + a^2*x^2)), -((c*(2*I + n)*(1 - I*a*x)^(1 + (I*n)/2)*(1 + I*a*x)^(1 - (I*n)/2))/(6*a)) + (I*c*(1 - I*a*x)^(2 + (I*n)/2)*(1 + I*a*x)^(1 - (I*n)/2))/(3*a) - (2^((I*n)/2)*c*(2*I - n)*(1 + I*a*x)^(1 - (I*n)/2)*Hypergeometric2F1[1 - (I*n)/2, -((I*n)/2), 2 - (I*n)/2, (1/2)*(1 + I*a*x)])/(3*a)}
{E^(n*ArcTan[a*x])*(c + c*a^2*x^2)^0, x, 2, (2^(1 + (I*n)/2)*(1 + I*a*x)^(1 - (I*n)/2)*Hypergeometric2F1[1 - (I*n)/2, -((I*n)/2), 2 - (I*n)/2, (1/2)*(1 + I*a*x)])/(a*(2*I + n))}
{E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^1, x, 1, E^(n*ArcTan[a*x])/(a*c*n)}
{E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^2, x, 2, (2*E^(n*ArcTan[a*x]))/(a*c^2*n*(4 + n^2)) + (E^(n*ArcTan[a*x])*(n + 2*a*x))/(a*c^2*(4 + n^2)*(1 + a^2*x^2))}
{E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^3, x, 3, (24*E^(n*ArcTan[a*x]))/(a*c^3*n*(4 + n^2)*(16 + n^2)) + (E^(n*ArcTan[a*x])*(n + 4*a*x))/(a*c^3*(16 + n^2)*(1 + a^2*x^2)^2) + (12*E^(n*ArcTan[a*x])*(n + 2*a*x))/(a*c^3*(4 + n^2)*(16 + n^2)*(1 + a^2*x^2))}
{E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^4, x, 4, (720*E^(n*ArcTan[a*x]))/(a*c^4*n*(4 + n^2)*(16 + n^2)*(36 + n^2)) + (E^(n*ArcTan[a*x])*(n + 6*a*x))/(a*c^4*(36 + n^2)*(1 + a^2*x^2)^3) + (30*E^(n*ArcTan[a*x])*(n + 4*a*x))/(a*c^4*(16 + n^2)*(36 + n^2)*(1 + a^2*x^2)^2) + (360*E^(n*ArcTan[a*x])*(n + 2*a*x))/(a*c^4*(4 + n^2)*(16 + n^2)*(36 + n^2)*(1 + a^2*x^2))}


(* ::Subsection::Closed:: *)
(*Integrands of the form E^(n ArcTan[a x]) (c+c a^2 x^2)^(p/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{E^ArcTan[a*x]*(c + c*a^2*x^2)^(5/2), x, 3, ((1/25 - (7*I)/25)*2^(5/2 + I/2)*c^2*(1 + I*a*x)^(7/2 - I/2)*Sqrt[c + a^2*c*x^2]*Hypergeometric2F1[-(5/2) - I/2, 7/2 - I/2, 9/2 - I/2, (1/2)*(1 + I*a*x)])/(a*Sqrt[1 + a^2*x^2])}
{E^ArcTan[a*x]*(c + c*a^2*x^2)^(3/2), x, 3, ((1/13 - (5*I)/13)*2^(3/2 + I/2)*c*(1 + I*a*x)^(5/2 - I/2)*Sqrt[c + a^2*c*x^2]*Hypergeometric2F1[-(3/2) - I/2, 5/2 - I/2, 7/2 - I/2, (1/2)*(1 + I*a*x)])/(a*Sqrt[1 + a^2*x^2])}
{E^ArcTan[a*x]*(c + c*a^2*x^2)^(1/2), x, 3, ((1/5 - (3*I)/5)*2^(1/2 + I/2)*(1 + I*a*x)^(3/2 - I/2)*Sqrt[c + a^2*c*x^2]*Hypergeometric2F1[-(1/2) - I/2, 3/2 - I/2, 5/2 - I/2, (1/2)*(1 + I*a*x)])/(a*Sqrt[1 + a^2*x^2])}
{E^ArcTan[a*x]/(c + c*a^2*x^2)^(1/2), x, 3, ((1 - I)*2^(-(1/2) + I/2)*(1 + I*a*x)^(1/2 - I/2)*Sqrt[1 + a^2*x^2]*Hypergeometric2F1[1/2 - I/2, 1/2 - I/2, 3/2 - I/2, (1/2)*(1 + I*a*x)])/(a*Sqrt[c + a^2*c*x^2])}
{E^ArcTan[a*x]/(c + c*a^2*x^2)^(3/2), x, 1, (E^ArcTan[a*x]*(1 + a*x))/(2*a*c*Sqrt[c + a^2*c*x^2])}
{E^ArcTan[a*x]/(c + c*a^2*x^2)^(5/2), x, 2, (E^ArcTan[a*x]*(1 + 3*a*x))/(10*a*c*(c + a^2*c*x^2)^(3/2)) + (3*E^ArcTan[a*x]*(1 + a*x))/(10*a*c^2*Sqrt[c + a^2*c*x^2])}
{E^ArcTan[a*x]/(c + c*a^2*x^2)^(7/2), x, 3, (E^ArcTan[a*x]*(1 + 5*a*x))/(26*a*c*(c + a^2*c*x^2)^(5/2)) + (E^ArcTan[a*x]*(1 + 3*a*x))/(13*a*c^2*(c + a^2*c*x^2)^(3/2)) + (3*E^ArcTan[a*x]*(1 + a*x))/(13*a*c^3*Sqrt[c + a^2*c*x^2])}


{E^(2*ArcTan[a*x])*(c + c*a^2*x^2)^(5/2), x, 3, ((2/53 - (7*I)/53)*2^(7/2 + I)*c^2*(1 + I*a*x)^(7/2 - I)*Sqrt[c + a^2*c*x^2]*Hypergeometric2F1[-(5/2) - I, 7/2 - I, 9/2 - I, (1/2)*(1 + I*a*x)])/(a*Sqrt[1 + a^2*x^2])}
{E^(2*ArcTan[a*x])*(c + c*a^2*x^2)^(3/2), x, 3, ((2/29 - (5*I)/29)*2^(5/2 + I)*c*(1 + I*a*x)^(5/2 - I)*Sqrt[c + a^2*c*x^2]*Hypergeometric2F1[-(3/2) - I, 5/2 - I, 7/2 - I, (1/2)*(1 + I*a*x)])/(a*Sqrt[1 + a^2*x^2])}
{E^(2*ArcTan[a*x])*(c + c*a^2*x^2)^(1/2), x, 3, ((2/13 - (3*I)/13)*2^(3/2 + I)*(1 + I*a*x)^(3/2 - I)*Sqrt[c + a^2*c*x^2]*Hypergeometric2F1[-(1/2) - I, 3/2 - I, 5/2 - I, (1/2)*(1 + I*a*x)])/(a*Sqrt[1 + a^2*x^2])}
{E^(2*ArcTan[a*x])/(c + c*a^2*x^2)^(1/2), x, 3, ((2/5 - I/5)*2^(1/2 + I)*(1 + I*a*x)^(1/2 - I)*Sqrt[1 + a^2*x^2]*Hypergeometric2F1[1/2 - I, 1/2 - I, 3/2 - I, (1/2)*(1 + I*a*x)])/(a*Sqrt[c + a^2*c*x^2])}
{E^(2*ArcTan[a*x])/(c + c*a^2*x^2)^(3/2), x, 1, (E^(2*ArcTan[a*x])*(2 + a*x))/(5*a*c*Sqrt[c + a^2*c*x^2])}
{E^(2*ArcTan[a*x])/(c + c*a^2*x^2)^(5/2), x, 2, (E^(2*ArcTan[a*x])*(2 + 3*a*x))/(13*a*c*(c + a^2*c*x^2)^(3/2)) + (6*E^(2*ArcTan[a*x])*(2 + a*x))/(65*a*c^2*Sqrt[c + a^2*c*x^2])}
{E^(2*ArcTan[a*x])/(c + c*a^2*x^2)^(7/2), x, 3, (E^(2*ArcTan[a*x])*(2 + 5*a*x))/(29*a*c*(c + a^2*c*x^2)^(5/2)) + (20*E^(2*ArcTan[a*x])*(2 + 3*a*x))/(377*a*c^2*(c + a^2*c*x^2)^(3/2)) + (24*E^(2*ArcTan[a*x])*(2 + a*x))/(377*a*c^3*Sqrt[c + a^2*c*x^2])}


{E^(3*ArcTan[a*x])*(c + c*a^2*x^2)^(5/2), x, 3, ((3/29 - (7*I)/29)*2^(5/2 + (3*I)/2)*c^2*(1 + I*a*x)^(7/2 - (3*I)/2)*Sqrt[c + a^2*c*x^2]*Hypergeometric2F1[-(5/2) - (3*I)/2, 7/2 - (3*I)/2, 9/2 - (3*I)/2, (1/2)*(1 + I*a*x)])/(a*Sqrt[1 + a^2*x^2])}
{E^(3*ArcTan[a*x])*(c + c*a^2*x^2)^(3/2), x, 3, ((3/17 - (5*I)/17)*2^(3/2 + (3*I)/2)*c*(1 + I*a*x)^(5/2 - (3*I)/2)*Sqrt[c + a^2*c*x^2]*Hypergeometric2F1[-(3/2) - (3*I)/2, 5/2 - (3*I)/2, 7/2 - (3*I)/2, (1/2)*(1 + I*a*x)])/(a*Sqrt[1 + a^2*x^2])}
{E^(3*ArcTan[a*x])*(c + c*a^2*x^2)^(1/2), x, 3, ((1/3 - I/3)*2^(1/2 + (3*I)/2)*(1 + I*a*x)^(3/2 - (3*I)/2)*Sqrt[c + a^2*c*x^2]*Hypergeometric2F1[-(1/2) - (3*I)/2, 3/2 - (3*I)/2, 5/2 - (3*I)/2, (1/2)*(1 + I*a*x)])/(a*Sqrt[1 + a^2*x^2])}
{E^(3*ArcTan[a*x])/(c + c*a^2*x^2)^(1/2), x, 3, ((3/5 - I/5)*2^(-(1/2) + (3*I)/2)*(1 + I*a*x)^(1/2 - (3*I)/2)*Sqrt[1 + a^2*x^2]*Hypergeometric2F1[1/2 - (3*I)/2, 1/2 - (3*I)/2, 3/2 - (3*I)/2, (1/2)*(1 + I*a*x)])/(a*Sqrt[c + a^2*c*x^2])}
{E^(3*ArcTan[a*x])/(c + c*a^2*x^2)^(3/2), x, 1, (E^(3*ArcTan[a*x])*(3 + a*x))/(10*a*c*Sqrt[c + a^2*c*x^2])}
{E^(3*ArcTan[a*x])/(c + c*a^2*x^2)^(5/2), x, 2, (E^(3*ArcTan[a*x])*(1 + a*x))/(6*a*c*(c + a^2*c*x^2)^(3/2)) + (E^(3*ArcTan[a*x])*(3 + a*x))/(30*a*c^2*Sqrt[c + a^2*c*x^2])}
{E^(3*ArcTan[a*x])/(c + c*a^2*x^2)^(7/2), x, 3, (E^(3*ArcTan[a*x])*(3 + 5*a*x))/(34*a*c*(c + a^2*c*x^2)^(5/2)) + (5*E^(3*ArcTan[a*x])*(1 + a*x))/(51*a*c^2*(c + a^2*c*x^2)^(3/2)) + (E^(3*ArcTan[a*x])*(3 + a*x))/(51*a*c^3*Sqrt[c + a^2*c*x^2])}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{1/E^ArcTan[a*x]*(c + c*a^2*x^2)^(5/2), x, 3, -(((1/25 + (7*I)/25)*2^(5/2 - I/2)*c^2*(1 + I*a*x)^(7/2 + I/2)*Sqrt[c + a^2*c*x^2]*Hypergeometric2F1[-(5/2) + I/2, 7/2 + I/2, 9/2 + I/2, (1/2)*(1 + I*a*x)])/(a*Sqrt[1 + a^2*x^2]))}
{1/E^ArcTan[a*x]*(c + c*a^2*x^2)^(3/2), x, 3, -(((1/13 + (5*I)/13)*2^(3/2 - I/2)*c*(1 + I*a*x)^(5/2 + I/2)*Sqrt[c + a^2*c*x^2]*Hypergeometric2F1[-(3/2) + I/2, 5/2 + I/2, 7/2 + I/2, (1/2)*(1 + I*a*x)])/(a*Sqrt[1 + a^2*x^2]))}
{1/E^ArcTan[a*x]*(c + c*a^2*x^2)^(1/2), x, 3, -(((1/5 + (3*I)/5)*2^(1/2 - I/2)*(1 + I*a*x)^(3/2 + I/2)*Sqrt[c + a^2*c*x^2]*Hypergeometric2F1[-(1/2) + I/2, 3/2 + I/2, 5/2 + I/2, (1/2)*(1 + I*a*x)])/(a*Sqrt[1 + a^2*x^2]))}
{1/E^ArcTan[a*x]/(c + c*a^2*x^2)^(1/2), x, 3, -(((1 + I)*2^(-(1/2) - I/2)*(1 + I*a*x)^(1/2 + I/2)*Sqrt[1 + a^2*x^2]*Hypergeometric2F1[1/2 + I/2, 1/2 + I/2, 3/2 + I/2, (1/2)*(1 + I*a*x)])/(a*Sqrt[c + a^2*c*x^2]))}
{1/E^ArcTan[a*x]/(c + c*a^2*x^2)^(3/2), x, 1, -((1 - a*x)/(E^ArcTan[a*x]*(2*a*c*Sqrt[c + a^2*c*x^2])))}
{1/E^ArcTan[a*x]/(c + c*a^2*x^2)^(5/2), x, 2, -((1 - 3*a*x)/(E^ArcTan[a*x]*(10*a*c*(c + a^2*c*x^2)^(3/2)))) - (3*(1 - a*x))/(E^ArcTan[a*x]*(10*a*c^2*Sqrt[c + a^2*c*x^2]))}
{1/E^ArcTan[a*x]/(c + c*a^2*x^2)^(7/2), x, 3, -((1 - 5*a*x)/(E^ArcTan[a*x]*(26*a*c*(c + a^2*c*x^2)^(5/2)))) - (1 - 3*a*x)/(E^ArcTan[a*x]*(13*a*c^2*(c + a^2*c*x^2)^(3/2))) - (3*(1 - a*x))/(E^ArcTan[a*x]*(13*a*c^3*Sqrt[c + a^2*c*x^2]))}


{1/E^(2*ArcTan[a*x])*(c + c*a^2*x^2)^(5/2), x, 3, -(((2/53 + (7*I)/53)*2^(7/2 - I)*c^2*(1 + I*a*x)^(7/2 + I)*Sqrt[c + a^2*c*x^2]*Hypergeometric2F1[-(5/2) + I, 7/2 + I, 9/2 + I, (1/2)*(1 + I*a*x)])/(a*Sqrt[1 + a^2*x^2]))}
{1/E^(2*ArcTan[a*x])*(c + c*a^2*x^2)^(3/2), x, 3, -(((2/29 + (5*I)/29)*2^(5/2 - I)*c*(1 + I*a*x)^(5/2 + I)*Sqrt[c + a^2*c*x^2]*Hypergeometric2F1[-(3/2) + I, 5/2 + I, 7/2 + I, (1/2)*(1 + I*a*x)])/(a*Sqrt[1 + a^2*x^2]))}
{1/E^(2*ArcTan[a*x])*(c + c*a^2*x^2)^(1/2), x, 3, -(((2/13 + (3*I)/13)*2^(3/2 - I)*(1 + I*a*x)^(3/2 + I)*Sqrt[c + a^2*c*x^2]*Hypergeometric2F1[-(1/2) + I, 3/2 + I, 5/2 + I, (1/2)*(1 + I*a*x)])/(a*Sqrt[1 + a^2*x^2]))}
{1/E^(2*ArcTan[a*x])/(c + c*a^2*x^2)^(1/2), x, 3, -(((2/5 + I/5)*2^(1/2 - I)*(1 + I*a*x)^(1/2 + I)*Sqrt[1 + a^2*x^2]*Hypergeometric2F1[1/2 + I, 1/2 + I, 3/2 + I, (1/2)*(1 + I*a*x)])/(a*Sqrt[c + a^2*c*x^2]))}
{1/E^(2*ArcTan[a*x])/(c + c*a^2*x^2)^(3/2), x, 1, -((2 - a*x)/(E^(2*ArcTan[a*x])*(5*a*c*Sqrt[c + a^2*c*x^2])))}
{1/E^(2*ArcTan[a*x])/(c + c*a^2*x^2)^(5/2), x, 2, -((2 - 3*a*x)/(E^(2*ArcTan[a*x])*(13*a*c*(c + a^2*c*x^2)^(3/2)))) - (6*(2 - a*x))/(E^(2*ArcTan[a*x])*(65*a*c^2*Sqrt[c + a^2*c*x^2]))}
{1/E^(2*ArcTan[a*x])/(c + c*a^2*x^2)^(7/2), x, 3, -((2 - 5*a*x)/(E^(2*ArcTan[a*x])*(29*a*c*(c + a^2*c*x^2)^(5/2)))) - (20*(2 - 3*a*x))/(E^(2*ArcTan[a*x])*(377*a*c^2*(c + a^2*c*x^2)^(3/2))) - (24*(2 - a*x))/(E^(2*ArcTan[a*x])*(377*a*c^3*Sqrt[c + a^2*c*x^2]))}


{1/E^(3*ArcTan[a*x])*(c + c*a^2*x^2)^(5/2), x, 3, -(((3/29 + (7*I)/29)*2^(5/2 - (3*I)/2)*c^2*(1 + I*a*x)^(7/2 + (3*I)/2)*Sqrt[c + a^2*c*x^2]*Hypergeometric2F1[-(5/2) + (3*I)/2, 7/2 + (3*I)/2, 9/2 + (3*I)/2, (1/2)*(1 + I*a*x)])/(a*Sqrt[1 + a^2*x^2]))}
{1/E^(3*ArcTan[a*x])*(c + c*a^2*x^2)^(3/2), x, 3, -(((3/17 + (5*I)/17)*2^(3/2 - (3*I)/2)*c*(1 + I*a*x)^(5/2 + (3*I)/2)*Sqrt[c + a^2*c*x^2]*Hypergeometric2F1[-(3/2) + (3*I)/2, 5/2 + (3*I)/2, 7/2 + (3*I)/2, (1/2)*(1 + I*a*x)])/(a*Sqrt[1 + a^2*x^2]))}
{1/E^(3*ArcTan[a*x])*(c + c*a^2*x^2)^(1/2), x, 3, -(((1/3 + I/3)*2^(1/2 - (3*I)/2)*(1 + I*a*x)^(3/2 + (3*I)/2)*Sqrt[c + a^2*c*x^2]*Hypergeometric2F1[-(1/2) + (3*I)/2, 3/2 + (3*I)/2, 5/2 + (3*I)/2, (1/2)*(1 + I*a*x)])/(a*Sqrt[1 + a^2*x^2]))}
{1/E^(3*ArcTan[a*x])/(c + c*a^2*x^2)^(1/2), x, 3, -(((3/5 + I/5)*2^(-(1/2) - (3*I)/2)*(1 + I*a*x)^(1/2 + (3*I)/2)*Sqrt[1 + a^2*x^2]*Hypergeometric2F1[1/2 + (3*I)/2, 1/2 + (3*I)/2, 3/2 + (3*I)/2, (1/2)*(1 + I*a*x)])/(a*Sqrt[c + a^2*c*x^2]))}
{1/E^(3*ArcTan[a*x])/(c + c*a^2*x^2)^(3/2), x, 1, -((3 - a*x)/(E^(3*ArcTan[a*x])*(10*a*c*Sqrt[c + a^2*c*x^2])))}
{1/E^(3*ArcTan[a*x])/(c + c*a^2*x^2)^(5/2), x, 2, -((1 - a*x)/(E^(3*ArcTan[a*x])*(6*a*c*(c + a^2*c*x^2)^(3/2)))) - (3 - a*x)/(E^(3*ArcTan[a*x])*(30*a*c^2*Sqrt[c + a^2*c*x^2]))}
{1/E^(3*ArcTan[a*x])/(c + c*a^2*x^2)^(7/2), x, 3, -((3 - 5*a*x)/(E^(3*ArcTan[a*x])*(34*a*c*(c + a^2*c*x^2)^(5/2)))) - (5*(1 - a*x))/(E^(3*ArcTan[a*x])*(51*a*c^2*(c + a^2*c*x^2)^(3/2))) - (3 - a*x)/(E^(3*ArcTan[a*x])*(51*a*c^3*Sqrt[c + a^2*c*x^2]))}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{E^(n*ArcTan[a*x])*(c + c*a^2*x^2)^(3/2), x, 5, (2^(5/2 + (I*n)/2)*(1 + I*a*x)^(5/2 - (I*n)/2)*(c + a^2*c*x^2)^(3/2)*Hypergeometric2F1[-(3/2) - (I*n)/2, 5/2 - (I*n)/2, 7/2 - (I*n)/2, (1/2)*(1 + I*a*x)])/(a*(5*I + n)*(1 + a^2*x^2)^(3/2)), -((c*(3*I + n)*(1 - I*a*x)^((1/2)*(3 + I*n))*Sqrt[c + a^2*c*x^2])/((1 + I*a*x)^((1/2)*I*(3*I + n))*(12*a*Sqrt[1 + a^2*x^2]))) + (I*c*(1 - I*a*x)^((1/2)*(5 + I*n))*Sqrt[c + a^2*c*x^2])/((1 + I*a*x)^((1/2)*I*(3*I + n))*(4*a*Sqrt[1 + a^2*x^2])) - (2^((1/2)*I*(I + n))*c*(3*I - n)*Sqrt[c + a^2*c*x^2]*Hypergeometric2F1[(1/2)*I*(I - n), (-(1/2))*I*(3*I + n), (-(1/2))*I*(5*I + n), (1/2)*(1 + I*a*x)])/((1 + I*a*x)^((1/2)*I*(3*I + n))*(3*a*Sqrt[1 + a^2*x^2]))}
{E^(n*ArcTan[a*x])*(c + c*a^2*x^2)^(1/2), x, 3, (2^(3/2 + (I*n)/2)*Sqrt[c + a^2*c*x^2]*Hypergeometric2F1[(1/2)*I*(I - n), (-(1/2))*I*(3*I + n), (-(1/2))*I*(5*I + n), (1/2)*(1 + I*a*x)])/((1 + I*a*x)^((1/2)*I*(3*I + n))*(a*(3*I + n)*Sqrt[1 + a^2*x^2]))}
{E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^(1/2), x, 5, (2^(1/2 + (I*n)/2)*(1 + I*a*x)^(1/2 - (I*n)/2)*Sqrt[1 + a^2*x^2]*Hypergeometric2F1[1/2 - (I*n)/2, 1/2 - (I*n)/2, 3/2 - (I*n)/2, (1/2)*(1 + I*a*x)])/(a*(I + n)*Sqrt[c + a^2*c*x^2]), -(((1 - I*a*x)^((1/2)*(1 + I*n))*Sqrt[1 + a^2*x^2])/((1 + I*a*x)^((1/2)*I*(I + n))*(a*(I - n)*Sqrt[c + a^2*c*x^2]))) - (I*(1 - I*a*x)^((1/2)*(3 + I*n))*Sqrt[1 + a^2*x^2])/((1 + I*a*x)^((1/2)*I*(I + n))*(a*(1 + n^2)*Sqrt[c + a^2*c*x^2])) + (2^(5/2 + (I*n)/2)*Sqrt[1 + a^2*x^2]*Hypergeometric2F1[(1/2)*I*(I - n), (-(1/2))*I*(3*I + n), (-(1/2))*I*(5*I + n), (1/2)*(1 + I*a*x)])/((1 + I*a*x)^((1/2)*I*(3*I + n))*(a*(3*I + n + 3*I*n^2 + n^3)*Sqrt[c + a^2*c*x^2]))}
{E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^(3/2), x, 1, (E^(n*ArcTan[a*x])*(n + a*x))/(a*c*(1 + n^2)*Sqrt[c + a^2*c*x^2])}
{E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^(5/2), x, 2, (E^(n*ArcTan[a*x])*(n + 3*a*x))/(a*c*(9 + n^2)*(c + a^2*c*x^2)^(3/2)) + (6*E^(n*ArcTan[a*x])*(n + a*x))/(a*c^2*(1 + n^2)*(9 + n^2)*Sqrt[c + a^2*c*x^2])}
{E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^(7/2), x, 3, (E^(n*ArcTan[a*x])*(n + 5*a*x))/(a*c*(25 + n^2)*(c + a^2*c*x^2)^(5/2)) + (20*E^(n*ArcTan[a*x])*(n + 3*a*x))/(a*c^2*(9 + n^2)*(25 + n^2)*(c + a^2*c*x^2)^(3/2)) + (120*E^(n*ArcTan[a*x])*(n + a*x))/(a*c^3*(1 + n^2)*(9 + n^2)*(25 + n^2)*Sqrt[c + a^2*c*x^2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form E^(n ArcTan[a x]) (c+c a^2 x^2)^(p/3)*)


{E^(n*ArcTan[a*x])/(c + a^2*c*x^2)^(1/3), x, 3, (3*2^(2/3 + (I*n)/2)*(1 + I*a*x)^((1/6)*(4 - 3*I*n))*(1 + a^2*x^2)^(1/3)*Hypergeometric2F1[(1/6)*(2 - 3*I*n), (1/6)*(4 - 3*I*n), (1/6)*(10 - 3*I*n), (1/2)*(1 + I*a*x)])/(a*(4*I + 3*n)*(c + a^2*c*x^2)^(1/3))}
{E^(n*ArcTan[a*x])/(c + a^2*c*x^2)^(2/3), x, 5, -((3*(1 - I*a*x)^((1/6)*(2 + 3*I*n))*(1 + I*a*x)^((1/6)*(2 - 3*I*n))*(1 + a^2*x^2)^(2/3))/(a*(2*I - 3*n)*(c + a^2*c*x^2)^(2/3))) - (6*I*(1 - I*a*x)^((1/6)*(8 + 3*I*n))*(1 + I*a*x)^((1/6)*(2 - 3*I*n))*(1 + a^2*x^2)^(2/3))/(a*(4 + 9*n^2)*(c + a^2*c*x^2)^(2/3)) + (15*2^(7/3 + (I*n)/2)*(1 + I*a*x)^((1/6)*(8 - 3*I*n))*(1 + a^2*x^2)^(2/3)*Hypergeometric2F1[(1/6)*(-2 - 3*I*n), (1/6)*(8 - 3*I*n), (1/6)*(14 - 3*I*n), (1/2)*(1 + I*a*x)])/(a*(32*I + 12*n + 72*I*n^2 + 27*n^3)*(c + a^2*c*x^2)^(2/3))}
{E^(n*ArcTan[a*x])/(c + a^2*c*x^2)^(4/3), x, 4, (3*E^(n*ArcTan[a*x])*(3*n + 2*a*x))/(a*c*(4 + 9*n^2)*(c + a^2*c*x^2)^(1/3)) - (3*2^(5/3 + (I*n)/2)*(1 + I*a*x)^((1/6)*(4 - 3*I*n))*(1 + a^2*x^2)^(1/3)*Hypergeometric2F1[(1/6)*(2 - 3*I*n), (1/6)*(4 - 3*I*n), (1/6)*(10 - 3*I*n), (1/2)*(1 + I*a*x)])/(a*c*(4*I + 3*n)*(4 + 9*n^2)*(c + a^2*c*x^2)^(1/3))}
{E^(n*ArcTan[a*x])/(c + a^2*c*x^2)^(5/3), x, 6, (3*E^(n*ArcTan[a*x])*(3*n + 4*a*x))/(a*c*(16 + 9*n^2)*(c + a^2*c*x^2)^(2/3)) - (12*(1 - I*a*x)^((1/6)*(2 + 3*I*n))*(1 + I*a*x)^((1/6)*(2 - 3*I*n))*(1 + a^2*x^2)^(2/3))/(a*c*(2*I - 3*n)*(16 + 9*n^2)*(c + a^2*c*x^2)^(2/3)) - (24*I*(1 - I*a*x)^((1/6)*(8 + 3*I*n))*(1 + I*a*x)^((1/6)*(2 - 3*I*n))*(1 + a^2*x^2)^(2/3))/(a*c*(64 + 180*n^2 + 81*n^4)*(c + a^2*c*x^2)^(2/3)) + (15*2^(13/3 + (I*n)/2)*(1 + I*a*x)^((1/6)*(8 - 3*I*n))*(1 + a^2*x^2)^(2/3)*Hypergeometric2F1[(1/6)*(-2 - 3*I*n), (1/6)*(8 - 3*I*n), (1/6)*(14 - 3*I*n), (1/2)*(1 + I*a*x)])/(a*c*(16 + 9*n^2)*(32*I + 12*n + 72*I*n^2 + 27*n^3)*(c + a^2*c*x^2)^(2/3))}
{E^(n*ArcTan[a*x])/(c + a^2*c*x^2)^(7/3), x, 5, (3*E^(n*ArcTan[a*x])*(3*n + 8*a*x))/(a*c*(64 + 9*n^2)*(c + a^2*c*x^2)^(4/3)) + (120*E^(n*ArcTan[a*x])*(3*n + 2*a*x))/(a*c^2*(4 + 9*n^2)*(64 + 9*n^2)*(c + a^2*c*x^2)^(1/3)) - (15*2^(14/3 + (I*n)/2)*(1 + I*a*x)^((1/6)*(4 - 3*I*n))*(1 + a^2*x^2)^(1/3)*Hypergeometric2F1[(1/6)*(2 - 3*I*n), (1/6)*(4 - 3*I*n), (1/6)*(10 - 3*I*n), (1/2)*(1 + I*a*x)])/(a*c^2*(4*I + 3*n)*(4 + 9*n^2)*(64 + 9*n^2)*(c + a^2*c*x^2)^(1/3))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(n ArcTan[a x]) (c+c a^2 x^2)^p*)


(* ::Subsubsection::Closed:: *)
(*p<0*)


{x^m*E^(n*ArcTan[a*x])/(c + c*a^2*x^2), x, 2, (x^(1 + m)*AppellF1[1 + m, 1 - (I*n)/2, 1 + (I*n)/2, 2 + m, I*a*x, (-I)*a*x])/(c*(1 + m))}

{x^3*E^(n*ArcTan[a*x])/(c + c*a^2*x^2), x, 2, (E^(n*ArcTan[a*x])*(2*I + n - I*n^2))/(2*a^4*c*n) - (E^(n*ArcTan[a*x])*n*x)/(2*a^3*c) + (E^(n*ArcTan[a*x])*x^2)/(2*a^2*c) + (I*E^(n*ArcTan[a*x])*(-2 + n^2)*Hypergeometric2F1[1, -((I*n)/2), 1 - (I*n)/2, -E^(2*I*ArcTan[a*x])])/(a^4*c*n), (x^4*AppellF1[4, 1 - (I*n)/2, 1 + (I*n)/2, 5, I*a*x, (-I)*a*x])/(4*c)}
{x^2*E^(n*ArcTan[a*x])/(c + c*a^2*x^2), x, 3, -(E^(n*ArcTan[a*x])/(a^3*c*n)) + (2^(1 + (I*n)/2)*(1 + I*a*x)^(1 - (I*n)/2)*Hypergeometric2F1[1 - (I*n)/2, -((I*n)/2), 2 - (I*n)/2, (1/2)*(1 + I*a*x)])/(a^3*c*(2*I + n))}
{x^1*E^(n*ArcTan[a*x])/(c + c*a^2*x^2), x, 3, (E^(n*ArcTan[a*x])*x)/(a*c*n) - (2^(1 + (I*n)/2)*(1 + I*a*x)^(1 - (I*n)/2)*Hypergeometric2F1[1 - (I*n)/2, -((I*n)/2), 2 - (I*n)/2, (1/2)*(1 + I*a*x)])/(a^2*c*n*(2*I + n))}
{x^0*E^(n*ArcTan[a*x])/(c + c*a^2*x^2), x, 1, E^(n*ArcTan[a*x])/(a*c*n)}
{E^(n*ArcTan[a*x])/(x^1*(c + c*a^2*x^2)), x, 2, (I*E^(n*ArcTan[a*x]))/(c*n) - (2*I*E^(n*ArcTan[a*x])*Hypergeometric2F1[1, -((I*n)/2), 1 - (I*n)/2, E^(2*I*ArcTan[a*x])])/(c*n), (I*(1 - I*a*x)^((I*n)/2)*Defer[AppellF1][(I*n)/2, 1, 1 + (I*n)/2, 1 + (I*n)/2, 1 - I*a*x, (1/2)*(1 - I*a*x)])/(2^((I*n)/2)*(c*n))}
{E^(n*ArcTan[a*x])/(x^2*(c + c*a^2*x^2)), x, 2, (I*a*E^(n*ArcTan[a*x])*(I + n))/(c*n) - E^(n*ArcTan[a*x])/(c*x) - (2*I*a*E^(n*ArcTan[a*x])*Hypergeometric2F1[1, -((I*n)/2), 1 - (I*n)/2, -1 + (2*I)/(I + a*x)])/c, -((a*(1 - I*a*x)^((I*n)/2)*Defer[AppellF1][(I*n)/2, 2, 1 + (I*n)/2, 1 + (I*n)/2, 1 - I*a*x, (1/2)*(1 - I*a*x)])/(2^((I*n)/2)*(c*n)))}
{E^(n*ArcTan[a*x])/(x^3*(c + c*a^2*x^2)), x, 2, (I*a^2*E^(n*ArcTan[a*x])*(-2 + I*n + n^2))/(2*c*n) - E^(n*ArcTan[a*x])/(2*c*x^2) - (a*E^(n*ArcTan[a*x])*n)/(2*c*x) - (I*a^2*E^(n*ArcTan[a*x])*(-2 + n^2)*Hypergeometric2F1[1, -((I*n)/2), 1 - (I*n)/2, E^(2*I*ArcTan[a*x])])/(c*n), -((I*a^2*(1 - I*a*x)^((I*n)/2)*Defer[AppellF1][(I*n)/2, 3, 1 + (I*n)/2, 1 + (I*n)/2, 1 - I*a*x, (1/2)*(1 - I*a*x)])/(2^((I*n)/2)*(c*n)))}


{x^m*E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^2, x, 2, (x^(1 + m)*AppellF1[1 + m, 2 - (I*n)/2, 2 + (I*n)/2, 2 + m, I*a*x, (-I)*a*x])/(c^2*(1 + m))}

{x^4*E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^2, x, 2, (I*(1 - I*a*x)^(-1 + (I*n)/2)*(6 - 2*a*n*x + 6*a^2*x^2 + n^2*(1 + 2*a^2*x^2)))/((1 + I*a*x)^((I*n)/2)*(a^5*c^2*n*(-2*I + n)*(2*I + n)*(-I + a*x))) + (2^(1 + (I*n)/2)*(1 + I*a*x)^(1 - (I*n)/2)*Hypergeometric2F1[1 - (I*n)/2, -((I*n)/2), 2 - (I*n)/2, (1/2)*(1 + I*a*x)])/(a^5*c^2*(2*I + n)), (x^5*AppellF1[5, 2 - (I*n)/2, 2 + (I*n)/2, 6, I*a*x, (-I)*a*x])/(5*c^2)}
{x^3*E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^2, x, 2, (x^4*AppellF1[4, 2 - (I*n)/2, 2 + (I*n)/2, 5, I*a*x, (-I)*a*x])/(4*c^2)}
{x^2*E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^2, x, 2, (E^(n*ArcTan[a*x])*(2 + n^2))/(a^3*c^2*n*(4 + n^2)) - (E^(n*ArcTan[a*x])*(n + 2*a*x))/(a^3*c^2*(4 + n^2)*(1 + a^2*x^2))}
{x^1*E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^2, x, 2, E^(n*ArcTan[a*x])/(a^2*c^2*(4 + n^2)) - (E^(n*ArcTan[a*x])*(2 - a*n*x))/(a^2*c^2*(4 + n^2)*(1 + a^2*x^2))}
{x^0*E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^2, x, 2, (2*E^(n*ArcTan[a*x]))/(a*c^2*n*(4 + n^2)) + (E^(n*ArcTan[a*x])*(n + 2*a*x))/(a*c^2*(4 + n^2)*(1 + a^2*x^2))}
{E^(n*ArcTan[a*x])/(x^1*(c + c*a^2*x^2)^2), x, 2, (I*2^(-1 - (I*n)/2)*(1 - I*a*x)^(-1 + (I*n)/2)*Defer[AppellF1][-1 + (I*n)/2, 1, 2 + (I*n)/2, (I*n)/2, 1 - I*a*x, (1/2)*(1 - I*a*x)])/(c^2*(2*I + n))}
{E^(n*ArcTan[a*x])/(x^2*(c + c*a^2*x^2)^2), x, 2, -((2^(-1 - (I*n)/2)*a*(1 - I*a*x)^(-1 + (I*n)/2)*Defer[AppellF1][-1 + (I*n)/2, 2, 2 + (I*n)/2, (I*n)/2, 1 - I*a*x, (1/2)*(1 - I*a*x)])/(c^2*(2*I + n)))}


{x^m*E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^3, x, 2, (x^(1 + m)*AppellF1[1 + m, 3 - (I*n)/2, 3 + (I*n)/2, 2 + m, I*a*x, (-I)*a*x])/(c^3*(1 + m))}

{x^4*E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^3, x, 4, (24*E^(n*ArcTan[a*x]))/(a^5*c^3*n*(64 + 20*n^2 + n^4)) - (4*E^(n*ArcTan[a*x])*x^3)/(a^2*c^3*(16 + n^2)*(1 + a^2*x^2)^2) + (E^(n*ArcTan[a*x])*n*x^4)/(a*c^3*(16 + n^2)*(1 + a^2*x^2)^2) - (24*E^(n*ArcTan[a*x])*x)/(a^4*c^3*(64 + 20*n^2 + n^4)*(1 + a^2*x^2)) + (12*E^(n*ArcTan[a*x])*n*x^2)/(a^3*c^3*(64 + 20*n^2 + n^4)*(1 + a^2*x^2))}
{x^3*E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^3, x, 5, -((6*E^(n*ArcTan[a*x]))/(a^4*c^3*(4 + n^2)*(16 + n^2)*(1 + a^2*x^2)^2)) + (6*E^(n*ArcTan[a*x])*n*x)/(a^3*c^3*(4 + n^2)*(16 + n^2)*(1 + a^2*x^2)^2) + (E^(n*ArcTan[a*x])*n*(10 + n^2)*x^3)/(a*c^3*(4 + n^2)*(16 + n^2)*(1 + a^2*x^2)^2) + (E^(n*ArcTan[a*x])*(10 + n^2)*x^4)/(c^3*(4 + n^2)*(16 + n^2)*(1 + a^2*x^2)^2) - (3*E^(n*ArcTan[a*x])*x^2)/(c^3*(16 + n^2)*(a + a^3*x^2)^2), -((E^(n*ArcTan[a*x])*Cos[2*ArcTan[a*x]])/(2*a^4*c^3*(4 + n^2))) + (E^(n*ArcTan[a*x])*Cos[4*ArcTan[a*x]])/(2*a^4*c^3*(16 + n^2)) + (E^(n*ArcTan[a*x])*n*Sin[2*ArcTan[a*x]])/(4*a^4*c^3*(4 + n^2)) - (E^(n*ArcTan[a*x])*n*Sin[4*ArcTan[a*x]])/(8*a^4*c^3*(16 + n^2))}
{x^2*E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^3, x, 3, (2*E^(n*ArcTan[a*x]))/(a^3*c^3*n*(16 + n^2)) - (E^(n*ArcTan[a*x])*(n + 4*a*x))/(a^3*c^3*(16 + n^2)*(1 + a^2*x^2)^2) + (E^(n*ArcTan[a*x])*(n + 2*a*x))/(a^3*c^3*(16 + n^2)*(1 + a^2*x^2))}
{x^1*E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^3, x, 3, (6*E^(n*ArcTan[a*x]))/(a^2*c^3*(4 + n^2)*(16 + n^2)) - (E^(n*ArcTan[a*x])*(4 - a*n*x))/(a^2*c^3*(16 + n^2)*(1 + a^2*x^2)^2) + (3*E^(n*ArcTan[a*x])*n*(n + 2*a*x))/(a^2*c^3*(4 + n^2)*(16 + n^2)*(1 + a^2*x^2))}
{x^0*E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^3, x, 3, (24*E^(n*ArcTan[a*x]))/(a*c^3*n*(4 + n^2)*(16 + n^2)) + (E^(n*ArcTan[a*x])*(n + 4*a*x))/(a*c^3*(16 + n^2)*(1 + a^2*x^2)^2) + (12*E^(n*ArcTan[a*x])*(n + 2*a*x))/(a*c^3*(4 + n^2)*(16 + n^2)*(1 + a^2*x^2))}
{E^(n*ArcTan[a*x])/(x^1*(c + c*a^2*x^2)^3), x, 2, (I*2^(-2 - (I*n)/2)*(1 - I*a*x)^(-2 + (I*n)/2)*Defer[AppellF1][-2 + (I*n)/2, 1, 3 + (I*n)/2, -1 + (I*n)/2, 1 - I*a*x, (1/2)*(1 - I*a*x)])/(c^3*(4*I + n))}
{E^(n*ArcTan[a*x])/(x^2*(c + c*a^2*x^2)^3), x, 2, -((2^(-2 - (I*n)/2)*a*(1 - I*a*x)^(-2 + (I*n)/2)*Defer[AppellF1][-2 + (I*n)/2, 2, 3 + (I*n)/2, -1 + (I*n)/2, 1 - I*a*x, (1/2)*(1 - I*a*x)])/(c^3*(4*I + n)))}


(* ::Subsubsection::Closed:: *)
(*p/2>0*)


{x^2*(E^(n*ArcTan[a*x])*(c + a*a*c*x^2)^(3/2)), x, 7, (c*(3*I + n)*(5 - n^2)*(1 - I*a*x)^((1/2)*(3 + I*n))*Sqrt[c + a^2*c*x^2])/((1 + I*a*x)^((1/2)*I*(3*I + n))*(360*a^3*Sqrt[1 + a^2*x^2])) - (I*c*(5 - n^2)*(1 - I*a*x)^((1/2)*(5 + I*n))*Sqrt[c + a^2*c*x^2])/((1 + I*a*x)^((1/2)*I*(3*I + n))*(120*a^3*Sqrt[1 + a^2*x^2])) - (c*n*(1 - I*a*x)^((1/2)*(5 + I*n))*Sqrt[c + a^2*c*x^2])/((1 + I*a*x)^((1/2)*I*(5*I + n))*(30*a^3*Sqrt[1 + a^2*x^2])) + (c*x*(1 - I*a*x)^((1/2)*(5 + I*n))*Sqrt[c + a^2*c*x^2])/((1 + I*a*x)^((1/2)*I*(5*I + n))*(6*a^2*Sqrt[1 + a^2*x^2])) + (2^((1/2)*I*(3*I + n))*c*(3*I - n)*(5 - n^2)*Sqrt[c + a^2*c*x^2]*Hypergeometric2F1[(1/2)*I*(I - n), (-(1/2))*I*(3*I + n), (-(1/2))*I*(5*I + n), (1/2)*(1 + I*a*x)])/((1 + I*a*x)^((1/2)*I*(3*I + n))*(45*a^3*Sqrt[1 + a^2*x^2]))}
{x^2*(E^(n*ArcTan[a*x])*(c + a*a*c*x^2)^(1/2)), x, 5, -((n*(1 - I*a*x)^((1/2)*(3 + I*n))*Sqrt[c + a^2*c*x^2])/((1 + I*a*x)^((1/2)*I*(3*I + n))*(12*a^3*Sqrt[1 + a^2*x^2]))) + (x*(1 - I*a*x)^((1/2)*(3 + I*n))*Sqrt[c + a^2*c*x^2])/((1 + I*a*x)^((1/2)*I*(3*I + n))*(4*a^2*Sqrt[1 + a^2*x^2])) - (2^(-(1/2) + (I*n)/2)*(3 - n^2)*Sqrt[c + a^2*c*x^2]*Hypergeometric2F1[(1/2)*I*(I - n), (-(1/2))*I*(3*I + n), (-(1/2))*I*(5*I + n), (1/2)*(1 + I*a*x)])/((1 + I*a*x)^((1/2)*I*(3*I + n))*(3*a^3*(3*I + n)*Sqrt[1 + a^2*x^2]))}


(* ::Subsubsection::Closed:: *)
(*p/2<0*)


{x^m*E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^(1/2), x, 3, (x^(1 + m)*Sqrt[1 + a^2*x^2]*AppellF1[1 + m, (-(1/2))*I*(I + n), (1/2)*(1 + I*n), 2 + m, I*a*x, (-I)*a*x])/((1 + m)*Sqrt[c + a^2*c*x^2])}

{x^4*E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^(1/2), x, 3, (x^5*Sqrt[1 + a^2*x^2]*AppellF1[5, (-(1/2))*I*(I + n), (1/2)*(1 + I*n), 6, I*a*x, (-I)*a*x])/(5*Sqrt[c + a^2*c*x^2])}
{x^3*E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^(1/2), x, 3, (x^4*Sqrt[1 + a^2*x^2]*AppellF1[4, (-(1/2))*I*(I + n), (1/2)*(1 + I*n), 5, I*a*x, (-I)*a*x])/(4*Sqrt[c + a^2*c*x^2])}
{x^2*E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^(1/2), x, 6, -(((1 + I*n)*(1 - I*a*x)^((1/2)*(1 + I*n))*Sqrt[1 + a^2*x^2])/((1 + I*a*x)^((1/2)*I*(I + n))*(2*a^3*(I + n)*Sqrt[c + a^2*c*x^2]))) + (x*(1 - I*a*x)^((1/2)*(1 + I*n))*Sqrt[1 + a^2*x^2])/((1 + I*a*x)^((1/2)*I*(I + n))*(2*a^2*Sqrt[c + a^2*c*x^2])) - (I*(1 - n^2)*(1 - I*a*x)^((1/2)*(1 + I*n))*Sqrt[1 + a^2*x^2])/((1 + I*a*x)^((1/2)*I*(3*I + n))*(2*a^3*(1 + n^2)*Sqrt[c + a^2*c*x^2])) - (2^(3/2 + (I*n)/2)*(1 - n^2)*Sqrt[1 + a^2*x^2]*Hypergeometric2F1[(1/2)*I*(I - n), (-(1/2))*I*(3*I + n), (-(1/2))*I*(5*I + n), (1/2)*(1 + I*a*x)])/((1 + I*a*x)^((1/2)*I*(3*I + n))*(a^3*(3*I + n + 3*I*n^2 + n^3)*Sqrt[c + a^2*c*x^2]))}
{x^1*E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^(1/2), x, 5, (I*(1 - I*a*x)^((1/2)*(1 + I*n))*Sqrt[1 + a^2*x^2])/((1 + I*a*x)^((1/2)*I*(I + n))*(a^2*(I + n)*Sqrt[c + a^2*c*x^2])) - (I*n*(1 - I*a*x)^((1/2)*(1 + I*n))*Sqrt[1 + a^2*x^2])/((1 + I*a*x)^((1/2)*I*(3*I + n))*(a^2*(1 + n^2)*Sqrt[c + a^2*c*x^2])) - (2^(5/2 + (I*n)/2)*n*Sqrt[1 + a^2*x^2]*Hypergeometric2F1[(1/2)*I*(I - n), (-(1/2))*I*(3*I + n), (-(1/2))*I*(5*I + n), (1/2)*(1 + I*a*x)])/((1 + I*a*x)^((1/2)*I*(3*I + n))*(a^2*(3*I + n + 3*I*n^2 + n^3)*Sqrt[c + a^2*c*x^2]))}
{x^0*E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^(1/2), x, 5, -(((1 - I*a*x)^((1/2)*(1 + I*n))*Sqrt[1 + a^2*x^2])/((1 + I*a*x)^((1/2)*I*(I + n))*(a*(I - n)*Sqrt[c + a^2*c*x^2]))) - (I*(1 - I*a*x)^((1/2)*(3 + I*n))*Sqrt[1 + a^2*x^2])/((1 + I*a*x)^((1/2)*I*(I + n))*(a*(1 + n^2)*Sqrt[c + a^2*c*x^2])) + (2^(5/2 + (I*n)/2)*Sqrt[1 + a^2*x^2]*Hypergeometric2F1[(1/2)*I*(I - n), (-(1/2))*I*(3*I + n), (-(1/2))*I*(5*I + n), (1/2)*(1 + I*a*x)])/((1 + I*a*x)^((1/2)*I*(3*I + n))*(a*(3*I + n + 3*I*n^2 + n^3)*Sqrt[c + a^2*c*x^2]))}
{E^(n*ArcTan[a*x])/(x^1*(c + c*a^2*x^2)^(1/2)), x, 3, -((I*2^(1/2 - (I*n)/2)*(1 - I*a*x)^((1/2)*(1 + I*n))*Sqrt[1 + a^2*x^2]*(1 + (1/2)*(-1 + I*a*x))^((1/2)*I*(I - n))*Hypergeometric2F1[1, (1/2)*(1 + I*n), (1/2)*(3 + I*n), (1 - I*a*x)/(1 + I*a*x)])/((I - n)*Sqrt[c + a^2*c*x^2]))}
{E^(n*ArcTan[a*x])/(x^2*(c + c*a^2*x^2)^(1/2)), x, 3, (2^(1/2 - (I*n)/2)*a*(1 - I*a*x)^((1/2)*(1 + I*n))*Sqrt[1 + a^2*x^2]*Defer[AppellF1][1/2 + (I*n)/2, 2, 1/2 + (I*n)/2, 3/2 + (I*n)/2, 1 - I*a*x, (1/2)*(1 - I*a*x)])/((I - n)*Sqrt[c + a^2*c*x^2])}


{x^2*(E^(n*ArcTan[a*x])/(c + a*a*c*x^2)^(1/2)), x, 6, -(((1 + I*n)*(1 - I*a*x)^((1/2)*(1 + I*n))*Sqrt[1 + a^2*x^2])/((1 + I*a*x)^((1/2)*I*(I + n))*(2*a^3*(I + n)*Sqrt[c + a^2*c*x^2]))) + (x*(1 - I*a*x)^((1/2)*(1 + I*n))*Sqrt[1 + a^2*x^2])/((1 + I*a*x)^((1/2)*I*(I + n))*(2*a^2*Sqrt[c + a^2*c*x^2])) - (I*(1 - n^2)*(1 - I*a*x)^((1/2)*(1 + I*n))*Sqrt[1 + a^2*x^2])/((1 + I*a*x)^((1/2)*I*(3*I + n))*(2*a^3*(1 + n^2)*Sqrt[c + a^2*c*x^2])) - (2^(3/2 + (I*n)/2)*(1 - n^2)*Sqrt[1 + a^2*x^2]*Hypergeometric2F1[(1/2)*I*(I - n), (-(1/2))*I*(3*I + n), (-(1/2))*I*(5*I + n), (1/2)*(1 + I*a*x)])/((1 + I*a*x)^((1/2)*I*(3*I + n))*(a^3*(3*I + n + 3*I*n^2 + n^3)*Sqrt[c + a^2*c*x^2]))}
{x^2*(E^(n*ArcTan[a*x])/(c + a*a*c*x^2)^(3/2)), x, 6, -((E^(n*ArcTan[a*x])*(n + a*x))/(a^3*c*(1 + n^2)*Sqrt[c + a^2*c*x^2])) + (2*E^((I + n)*ArcTan[a*x])*Sqrt[1 + a^2*x^2]*Hypergeometric2F1[1, 1/2 - (I*n)/2, 3/2 - (I*n)/2, -E^(2*I*ArcTan[a*x])])/(a^3*c*(I + n)*Sqrt[c + a^2*c*x^2]), -((E^(n*ArcTan[a*x])*(n + a*x))/(a^3*c*(1 + n^2)*Sqrt[c + a^2*c*x^2])) - ((1 - I*a*x)^((1/2)*(1 + I*n))*Sqrt[1 + a^2*x^2])/((1 + I*a*x)^((1/2)*I*(I + n))*(a^3*c*(I - n)*Sqrt[c + a^2*c*x^2])) - (I*(1 - I*a*x)^((1/2)*(3 + I*n))*Sqrt[1 + a^2*x^2])/((1 + I*a*x)^((1/2)*I*(I + n))*(a^3*c*(1 + n^2)*Sqrt[c + a^2*c*x^2])) + (2^(5/2 + (I*n)/2)*Sqrt[1 + a^2*x^2]*Hypergeometric2F1[(1/2)*I*(I - n), (-(1/2))*I*(3*I + n), (-(1/2))*I*(5*I + n), (1/2)*(1 + I*a*x)])/((1 + I*a*x)^((1/2)*I*(3*I + n))*(a^3*c*(3*I + n + 3*I*n^2 + n^3)*Sqrt[c + a^2*c*x^2]))}
{x^2*(E^(n*ArcTan[a*x])/(c + a*a*c*x^2)^(5/2)), x, 2, -((E^(n*ArcTan[a*x])*(n + 3*a*x))/(a^3*c*(9 + n^2)*(c + a^2*c*x^2)^(3/2))) + (E^(n*ArcTan[a*x])*(3 + n^2)*(n + a*x))/(a^3*c^2*(1 + n^2)*(9 + n^2)*Sqrt[c + a^2*c*x^2])}


{x^m*E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^(3/2), x, 3, (x^(1 + m)*Sqrt[1 + a^2*x^2]*AppellF1[1 + m, (-(1/2))*I*(3*I + n), (1/2)*(3 + I*n), 2 + m, I*a*x, (-I)*a*x])/(c*(1 + m)*Sqrt[c + a^2*c*x^2])}

{x^3*E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^(3/2), x, 3, (x^4*Sqrt[1 + a^2*x^2]*AppellF1[4, (-(1/2))*I*(3*I + n), (1/2)*(3 + I*n), 5, I*a*x, (-I)*a*x])/(4*c*Sqrt[c + a^2*c*x^2])}
{x^2*E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^(3/2), x, 6, -((E^(n*ArcTan[a*x])*(n + a*x))/(a^3*c*(1 + n^2)*Sqrt[c + a^2*c*x^2])) - ((1 - I*a*x)^((1/2)*(1 + I*n))*Sqrt[1 + a^2*x^2])/((1 + I*a*x)^((1/2)*I*(I + n))*(a^3*c*(I - n)*Sqrt[c + a^2*c*x^2])) - (I*(1 - I*a*x)^((1/2)*(3 + I*n))*Sqrt[1 + a^2*x^2])/((1 + I*a*x)^((1/2)*I*(I + n))*(a^3*c*(1 + n^2)*Sqrt[c + a^2*c*x^2])) + (2^(5/2 + (I*n)/2)*Sqrt[1 + a^2*x^2]*Hypergeometric2F1[(1/2)*I*(I - n), (-(1/2))*I*(3*I + n), (-(1/2))*I*(5*I + n), (1/2)*(1 + I*a*x)])/((1 + I*a*x)^((1/2)*I*(3*I + n))*(a^3*c*(3*I + n + 3*I*n^2 + n^3)*Sqrt[c + a^2*c*x^2]))}
{x^1*E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^(3/2), x, 1, -((E^(n*ArcTan[a*x])*(1 - a*n*x))/(a^2*c*(1 + n^2)*Sqrt[c + a^2*c*x^2]))}
{x^0*E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^(3/2), x, 1, (E^(n*ArcTan[a*x])*(n + a*x))/(a*c*(1 + n^2)*Sqrt[c + a^2*c*x^2])}
{E^(n*ArcTan[a*x])/(x^1*(c + c*a^2*x^2)^(3/2)), x, 3, (I*2^(-(1/2) - (I*n)/2)*(1 - I*a*x)^((1/2)*I*(I + n))*Sqrt[1 + a^2*x^2]*Defer[AppellF1][-(1/2) + (I*n)/2, 1, 3/2 + (I*n)/2, 1/2 + (I*n)/2, 1 - I*a*x, (1/2)*(1 - I*a*x)])/(c*(I + n)*Sqrt[c + a^2*c*x^2])}
{E^(n*ArcTan[a*x])/(x^2*(c + c*a^2*x^2)^(3/2)), x, 3, -((2^(-(1/2) - (I*n)/2)*a*(1 - I*a*x)^((1/2)*I*(I + n))*Sqrt[1 + a^2*x^2]*Defer[AppellF1][-(1/2) + (I*n)/2, 2, 3/2 + (I*n)/2, 1/2 + (I*n)/2, 1 - I*a*x, (1/2)*(1 - I*a*x)])/(c*(I + n)*Sqrt[c + a^2*c*x^2]))}


{x^m*E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^(5/2), x, 3, (x^(1 + m)*Sqrt[1 + a^2*x^2]*AppellF1[1 + m, (-(1/2))*I*(5*I + n), (1/2)*(5 + I*n), 2 + m, I*a*x, (-I)*a*x])/(c^2*(1 + m)*Sqrt[c + a^2*c*x^2])}

{x^5*E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^(5/2), x, 3, (x^6*Sqrt[1 + a^2*x^2]*AppellF1[6, (-(1/2))*I*(5*I + n), (1/2)*(5 + I*n), 7, I*a*x, (-I)*a*x])/(6*c^2*Sqrt[c + a^2*c*x^2])}
{x^4*E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^(5/2), x, 3, (x^5*Sqrt[1 + a^2*x^2]*AppellF1[5, (-(1/2))*I*(5*I + n), (1/2)*(5 + I*n), 6, I*a*x, (-I)*a*x])/(5*c^2*Sqrt[c + a^2*c*x^2])}
{x^3*E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^(5/2), x, 4, -((6*E^(n*ArcTan[a*x]))/(a^4*c^2*(9 + 10*n^2 + n^4)*Sqrt[c + a^2*c*x^2])) + (6*E^(n*ArcTan[a*x])*n*x)/(a^3*c^2*(9 + 10*n^2 + n^4)*Sqrt[c + a^2*c*x^2]) - (3*E^(n*ArcTan[a*x])*x^2)/(a^2*c^2*(9 + n^2)*(1 + a^2*x^2)*Sqrt[c + a^2*c*x^2]) + (E^(n*ArcTan[a*x])*n*x^3)/(a*c^2*(9 + n^2)*(1 + a^2*x^2)*Sqrt[c + a^2*c*x^2])}
{x^2*E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^(5/2), x, 2, -((E^(n*ArcTan[a*x])*(n + 3*a*x))/(a^3*c*(9 + n^2)*(c + a^2*c*x^2)^(3/2))) + (E^(n*ArcTan[a*x])*(3 + n^2)*(n + a*x))/(a^3*c^2*(1 + n^2)*(9 + n^2)*Sqrt[c + a^2*c*x^2])}
{x^1*E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^(5/2), x, 2, -((E^(n*ArcTan[a*x])*(3 - a*n*x))/(a^2*c*(9 + n^2)*(c + a^2*c*x^2)^(3/2))) + (2*E^(n*ArcTan[a*x])*n*(n + a*x))/(a^2*c^2*(1 + n^2)*(9 + n^2)*Sqrt[c + a^2*c*x^2])}
{x^0*E^(n*ArcTan[a*x])/(c + c*a^2*x^2)^(5/2), x, 2, (E^(n*ArcTan[a*x])*(n + 3*a*x))/(a*c*(9 + n^2)*(c + a^2*c*x^2)^(3/2)) + (6*E^(n*ArcTan[a*x])*(n + a*x))/(a*c^2*(1 + n^2)*(9 + n^2)*Sqrt[c + a^2*c*x^2])}
{E^(n*ArcTan[a*x])/(x^1*(c + c*a^2*x^2)^(5/2)), x, 3, (I*2^(-(3/2) - (I*n)/2)*(1 - I*a*x)^((1/2)*I*(3*I + n))*Sqrt[1 + a^2*x^2]*Defer[AppellF1][-(3/2) + (I*n)/2, 1, 5/2 + (I*n)/2, -(1/2) + (I*n)/2, 1 - I*a*x, (1/2)*(1 - I*a*x)])/(c^2*(3*I + n)*Sqrt[c + a^2*c*x^2])}
{E^(n*ArcTan[a*x])/(x^2*(c + c*a^2*x^2)^(5/2)), x, 3, -((2^(-(3/2) - (I*n)/2)*a*(1 - I*a*x)^((1/2)*I*(3*I + n))*Sqrt[1 + a^2*x^2]*Defer[AppellF1][-(3/2) + (I*n)/2, 2, 5/2 + (I*n)/2, -(1/2) + (I*n)/2, 1 - I*a*x, (1/2)*(1 - I*a*x)])/(c^2*(3*I + n)*Sqrt[c + a^2*c*x^2]))}


{x^2*(E^(n*ArcTan[a*x])/(c + a*a*c*x^2)^(7/2)), x, 3, -((E^(n*ArcTan[a*x])*(n + 5*a*x))/(a^3*c*(25 + n^2)*(c + a^2*c*x^2)^(5/2))) + (E^(n*ArcTan[a*x])*(5 + n^2)*(n + 3*a*x))/(a^3*c^2*(9 + n^2)*(25 + n^2)*(c + a^2*c*x^2)^(3/2)) + (6*E^(n*ArcTan[a*x])*(5 + n^2)*(n + a*x))/(a^3*c^3*(1 + n^2)*(9 + n^2)*(25 + n^2)*Sqrt[c + a^2*c*x^2])}
{x^1*(E^(n*ArcTan[a*x])/(c + a*a*c*x^2)^(7/2)), x, 3, -((E^(n*ArcTan[a*x])*(5 - a*n*x))/(a^2*c*(25 + n^2)*(c + a^2*c*x^2)^(5/2))) + (4*E^(n*ArcTan[a*x])*n*(n + 3*a*x))/(a^2*c^2*(9 + n^2)*(25 + n^2)*(c + a^2*c*x^2)^(3/2)) + (24*E^(n*ArcTan[a*x])*n*(n + a*x))/(a^2*c^3*(1 + n^2)*(9 + n^2)*(25 + n^2)*Sqrt[c + a^2*c*x^2])}
{x^0*(E^(n*ArcTan[a*x])/(c + a*a*c*x^2)^(7/2)), x, 3, (E^(n*ArcTan[a*x])*(n + 5*a*x))/(a*c*(25 + n^2)*(c + a^2*c*x^2)^(5/2)) + (20*E^(n*ArcTan[a*x])*(n + 3*a*x))/(a*c^2*(9 + n^2)*(25 + n^2)*(c + a^2*c*x^2)^(3/2)) + (120*E^(n*ArcTan[a*x])*(n + a*x))/(a*c^3*(1 + n^2)*(9 + n^2)*(25 + n^2)*Sqrt[c + a^2*c*x^2])}


{x^2*(E^(n*ArcTan[a*x])/(c + a*a*c*x^2)^(9/2)), x, 4, -((E^(n*ArcTan[a*x])*(n + 7*a*x))/(a^3*c*(49 + n^2)*(c + a^2*c*x^2)^(7/2))) + (E^(n*ArcTan[a*x])*(7 + n^2)*(n + 5*a*x))/(a^3*c^2*(25 + n^2)*(49 + n^2)*(c + a^2*c*x^2)^(5/2)) + (20*E^(n*ArcTan[a*x])*(7 + n^2)*(n + 3*a*x))/(a^3*c^3*(9 + n^2)*(25 + n^2)*(49 + n^2)*(c + a^2*c*x^2)^(3/2)) + (120*E^(n*ArcTan[a*x])*(7 + n^2)*(n + a*x))/(a^3*c^4*(1 + n^2)*(9 + n^2)*(25 + n^2)*(49 + n^2)*Sqrt[c + a^2*c*x^2])}
{x^1*(E^(n*ArcTan[a*x])/(c + a*a*c*x^2)^(9/2)), x, 4, -((E^(n*ArcTan[a*x])*(7 - a*n*x))/(a^2*c*(49 + n^2)*(c + a^2*c*x^2)^(7/2))) + (6*E^(n*ArcTan[a*x])*n*(n + 5*a*x))/(a^2*c^2*(25 + n^2)*(49 + n^2)*(c + a^2*c*x^2)^(5/2)) + (120*E^(n*ArcTan[a*x])*n*(n + 3*a*x))/(a^2*c^3*(9 + n^2)*(25 + n^2)*(49 + n^2)*(c + a^2*c*x^2)^(3/2)) + (720*E^(n*ArcTan[a*x])*n*(n + a*x))/(a^2*c^4*(1 + n^2)*(9 + n^2)*(25 + n^2)*(49 + n^2)*Sqrt[c + a^2*c*x^2])}
{x^0*(E^(n*ArcTan[a*x])/(c + a*a*c*x^2)^(9/2)), x, 4, (E^(n*ArcTan[a*x])*(n + 7*a*x))/(a*c*(49 + n^2)*(c + a^2*c*x^2)^(7/2)) + (42*E^(n*ArcTan[a*x])*(n + 5*a*x))/(a*c^2*(25 + n^2)*(49 + n^2)*(c + a^2*c*x^2)^(5/2)) + (840*E^(n*ArcTan[a*x])*(n + 3*a*x))/(a*c^3*(9 + n^2)*(25 + n^2)*(49 + n^2)*(c + a^2*c*x^2)^(3/2)) + (5040*E^(n*ArcTan[a*x])*(n + a*x))/(a*c^4*(1 + n^2)*(9 + n^2)*(25 + n^2)*(49 + n^2)*Sqrt[c + a^2*c*x^2])}


{x^2*(E^(n*ArcTan[a*x])/(c + a*a*c*x^2)^(11/2)), x, 5, -((E^(n*ArcTan[a*x])*(n + 9*a*x))/(a^3*c*(81 + n^2)*(c + a^2*c*x^2)^(9/2))) + (E^(n*ArcTan[a*x])*(9 + n^2)*(n + 7*a*x))/(a^3*c^2*(49 + n^2)*(81 + n^2)*(c + a^2*c*x^2)^(7/2)) + (42*E^(n*ArcTan[a*x])*(9 + n^2)*(n + 5*a*x))/(a^3*c^3*(25 + n^2)*(49 + n^2)*(81 + n^2)*(c + a^2*c*x^2)^(5/2)) + (840*E^(n*ArcTan[a*x])*(n + 3*a*x))/(a^3*c^4*(25 + n^2)*(49 + n^2)*(81 + n^2)*(c + a^2*c*x^2)^(3/2)) + (5040*E^(n*ArcTan[a*x])*(n + a*x))/(a^3*c^5*(1 + n^2)*(25 + n^2)*(49 + n^2)*(81 + n^2)*Sqrt[c + a^2*c*x^2])}
{x^1*(E^(n*ArcTan[a*x])/(c + a*a*c*x^2)^(11/2)), x, 5, -((E^(n*ArcTan[a*x])*(9 - a*n*x))/(a^2*c*(81 + n^2)*(c + a^2*c*x^2)^(9/2))) + (8*E^(n*ArcTan[a*x])*n*(n + 7*a*x))/(a^2*c^2*(49 + n^2)*(81 + n^2)*(c + a^2*c*x^2)^(7/2)) + (336*E^(n*ArcTan[a*x])*n*(n + 5*a*x))/(a^2*c^3*(25 + n^2)*(49 + n^2)*(81 + n^2)*(c + a^2*c*x^2)^(5/2)) + (6720*E^(n*ArcTan[a*x])*n*(n + 3*a*x))/(a^2*c^4*(9 + n^2)*(25 + n^2)*(49 + n^2)*(81 + n^2)*(c + a^2*c*x^2)^(3/2)) + (40320*E^(n*ArcTan[a*x])*n*(n + a*x))/(a^2*c^5*(1 + n^2)*(9 + n^2)*(25 + n^2)*(49 + n^2)*(81 + n^2)*Sqrt[c + a^2*c*x^2])}
{x^0*(E^(n*ArcTan[a*x])/(c + a*a*c*x^2)^(11/2)), x, 5, (E^(n*ArcTan[a*x])*(n + 9*a*x))/(a*c*(81 + n^2)*(c + a^2*c*x^2)^(9/2)) + (72*E^(n*ArcTan[a*x])*(n + 7*a*x))/(a*c^2*(49 + n^2)*(81 + n^2)*(c + a^2*c*x^2)^(7/2)) + (3024*E^(n*ArcTan[a*x])*(n + 5*a*x))/(a*c^3*(25 + n^2)*(49 + n^2)*(81 + n^2)*(c + a^2*c*x^2)^(5/2)) + (60480*E^(n*ArcTan[a*x])*(n + 3*a*x))/(a*c^4*(9 + n^2)*(25 + n^2)*(49 + n^2)*(81 + n^2)*(c + a^2*c*x^2)^(3/2)) + (362880*E^(n*ArcTan[a*x])*(n + a*x))/(a*c^5*(1 + n^2)*(9 + n^2)*(25 + n^2)*(49 + n^2)*(81 + n^2)*Sqrt[c + a^2*c*x^2])}


(* ::Subsubsection::Closed:: *)
(*p=n^2/2-1*)


{x^2*E^(n*ArcTan[a*x])*(c + c*a^2*x^2)^(-1 + n^2/2), x, 1, -((E^(n*ArcTan[a*x])*(1 - a*n*x)*(c + a^2*c*x^2)^(n^2/2))/(a^3*c*n*(1 + n^2)))}

{x^2*E^(3*ArcTan[a*x])*(c + a^2*c*x^2)^(7/2), x, 1, -((E^(3*ArcTan[a*x])*(1 - 3*a*x)*(c + a^2*c*x^2)^(9/2))/(30*a^3*c))}
{x^2*E^(2*ArcTan[a*x])*(c + a^2*c*x^2), x, 1, -((c*E^(2*ArcTan[a*x])*(1 - 2*a*x)*(1 + a^2*x^2)^2)/(10*a^3))}
{x^2*E^(1*ArcTan[a*x])/(c + a^2*c*x^2)^(1/2), x, 1, -((E^ArcTan[a*x]*(1 - a*x)*Sqrt[c + a^2*c*x^2])/(2*a^3*c))}
{x^2*E^(-1*ArcTan[a*x])/(c + a^2*c*x^2)^(1/2), x, 1, ((1 + a*x)*Sqrt[c + a^2*c*x^2])/(E^ArcTan[a*x]*(2*a^3*c))}
{x^2*E^(-2*ArcTan[a*x])*(c + a^2*c*x^2), x, 1, (c*(1 + 2*a*x)*(1 + a^2*x^2)^2)/(E^(2*ArcTan[a*x])*(10*a^3))}
{x^2*E^(-3*ArcTan[a*x])*(c + a^2*c*x^2)^(7/2), x, 1, ((1 + 3*a*x)*(c + a^2*c*x^2)^(9/2))/(E^(3*ArcTan[a*x])*(30*a^3*c))}

{x^2*E^(3*I*ArcTan[a*x])/(c + c*a^2*x^2)^(11/2), x, 1, -((E^(3*I*ArcTan[a*x])*(I + 3*a*x))/(24*a^3*c*(c + a^2*c*x^2)^(9/2)))}
{x^2*E^(2*I*ArcTan[a*x])/(c + c*a^2*x^2)^3, x, 1, -((E^(2*I*ArcTan[a*x])*(I + 2*a*x))/(6*a^3*c^3*(1 + a^2*x^2)^2))}
{x^2*E^(1*I*ArcTan[a*x])/(c + c*a^2*x^2)^(3/2), x, 4, -(Sqrt[1 + a^2*x^2]/(2*a^3*c*(I + a*x)*Sqrt[c + a^2*c*x^2])) + (I*Sqrt[1 + a^2*x^2]*Log[I - a*x])/(4*a^3*c*Sqrt[c + a^2*c*x^2]) + (3*I*Sqrt[1 + a^2*x^2]*Log[I + a*x])/(4*a^3*c*Sqrt[c + a^2*c*x^2])}
{x^2*E^(-1*I*ArcTan[a*x])/(c + c*a^2*x^2)^(3/2), x, 5, Sqrt[1 + a^2*x^2]/(2*a^3*c*(I - a*x)*Sqrt[c + a^2*c*x^2]) - (3*I*Sqrt[1 + a^2*x^2]*Log[I - a*x])/(4*a^3*c*Sqrt[c + a^2*c*x^2]) - (I*Sqrt[1 + a^2*x^2]*Log[I + a*x])/(4*a^3*c*Sqrt[c + a^2*c*x^2])}
{x^2*E^(-2*I*ArcTan[a*x])/(c + c*a^2*x^2)^3, x, 1, (I - 2*a*x)/(E^(2*I*ArcTan[a*x])*(6*a^3*c^3*(1 + a^2*x^2)^2))}
{x^2*E^(-3*I*ArcTan[a*x])/(c + c*a^2*x^2)^(11/2), x, 1, (I - 3*a*x)/(E^(3*I*ArcTan[a*x])*(24*a^3*c*(c + a^2*c*x^2)^(9/2)))}


(* ::Section::Closed:: *)
(*Integrands of the form u E^(n ArcTan[a+b x])*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m E^(n ArcTan[a+b x])*)


(* ::Subsubsection::Closed:: *)
(*n I>0*)


{E^(I*ArcTan[a + b*x])*x^4, x, 7, ((64*I + 275*a - (332*I)*a^2 - 250*a^3 + (24*I)*a^4)*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/(120*b^5) - ((45 - (116*I)*a - 130*a^2 + (24*I)*a^3)*x*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/(120*b^4) - ((16*I + 35*a - (12*I)*a^2)*x^2*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/(60*b^3) - ((I/20)*(5*I + 4*a)*x^3*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/b^2 + ((I/5)*x^4*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/b + ((3 - (12*I)*a - 24*a^2 + (16*I)*a^3 + 8*a^4)*ArcSinh[a + b*x])/(8*b^5)}
{E^(I*ArcTan[a + b*x])*x^3, x, 6, -((16 - (39*I)*a - 44*a^2 + (6*I)*a^3)*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/(24*b^4) - ((9*I + 20*a - (6*I)*a^2)*x*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/(24*b^3) - ((I/12)*(4*I + 3*a)*x^2*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/b^2 + ((I/4)*x^3*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/b + ((3*I + 12*a - (12*I)*a^2 - 8*a^3)*ArcSinh[a + b*x])/(8*b^4)}
{E^(I*ArcTan[a + b*x])*x^2, x, 5, -((I + 2*a - (2*I)*a^2)*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/(2*b^3) - ((I + 4*a)*Sqrt[1 - I*a - I*b*x]*(1 + I*a + I*b*x)^(3/2))/(6*b^3) + (x*Sqrt[1 - I*a - I*b*x]*(1 + I*a + I*b*x)^(3/2))/(3*b^2) - ((1 - (2*I)*a - 2*a^2)*ArcSinh[a + b*x])/(2*b^3)}
{E^(I*ArcTan[a + b*x])*x, x, 4, ((1 - (2*I)*a)*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/(2*b^2) + (Sqrt[1 - I*a - I*b*x]*(1 + I*a + I*b*x)^(3/2))/(2*b^2) - ((I + 2*a)*ArcSinh[a + b*x])/(2*b^2)}
{E^(I*ArcTan[a + b*x]), x, 3, (I*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/b + ArcSinh[a + b*x]/b}
{E^(I*ArcTan[a + b*x])/x, x, 4, I*ArcSinh[a + b*x] - (2*Sqrt[I - a]*ArcTanh[(Sqrt[I - a]*Sqrt[1 - I*a - I*b*x])/(Sqrt[I + a]*Sqrt[1 + I*a + I*b*x])])/Sqrt[I + a]}
{E^(I*ArcTan[a + b*x])/x^2, x, 3, -((I*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/((I + a)*x)) + (2*I*b*ArcTanh[(Sqrt[I - a]*Sqrt[1 - I*a - I*b*x])/(Sqrt[I + a]*Sqrt[1 + I*a + I*b*x])])/(Sqrt[I - a]*(I + a)^(3/2))}
{E^(I*ArcTan[a + b*x])/x^3, x, 5, -((Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/(2*(1 - I*a)*x^2)) - ((2*I - a)*b*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/(2*(1 - I*a)*(1 + a^2)*x) + ((1 + 2*I*a)*b^2*ArcTanh[(Sqrt[I - a]*Sqrt[1 - I*a - I*b*x])/(Sqrt[I + a]*Sqrt[1 + I*a + I*b*x])])/((I - a)^(3/2)*(I + a)^(5/2))}
{E^(I*ArcTan[a + b*x])/x^4, x, 6, -((Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/(3*(1 - I*a)*x^3)) - ((3*I - 2*a)*b*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/(6*(1 - I*a)*(1 + a^2)*x^2) + ((4*I - a)*(1 + 2*I*a)*b^2*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/(6*(I - a)^2*(I + a)^3*x) - ((I - 2*a - 2*I*a^2)*b^3*ArcTanh[(Sqrt[I - a]*Sqrt[1 - I*a - I*b*x])/(Sqrt[I + a]*Sqrt[1 + I*a + I*b*x])])/((I - a)^(5/2)*(I + a)^(7/2))}


{E^((2*I)*ArcTan[a + b*x])*x^4, x, 3, ((-2*I)*(I + a)^3*x)/b^4 + (I*(I + a)^2*x^2)/b^3 + (2*(1 - I*a)*x^3)/(3*b^2) + ((I/2)*x^4)/b - x^5/5 + ((2*I)*(I + a)^4*Log[I + a + b*x])/b^5}
{E^((2*I)*ArcTan[a + b*x])*x^3, x, 3, ((2*I)*(I + a)^2*x)/b^3 + ((1 - I*a)*x^2)/b^2 + (((2*I)/3)*x^3)/b - x^4/4 - ((2*I)*(I + a)^3*Log[I + a + b*x])/b^4}
{E^((2*I)*ArcTan[a + b*x])*x^2, x, 3, ((-2*I)*(I + a)*x)/b^2 + (I*x^2)/b - x^3/3 + ((2*I)*(I + a)^2*Log[I + a + b*x])/b^3}
{E^((2*I)*ArcTan[a + b*x])*x, x, 3, ((2*I)*x)/b - x^2/2 + (2*(1 - I*a)*Log[I + a + b*x])/b^2}
{E^((2*I)*ArcTan[a + b*x]), x, 3, -x + ((2*I)*Log[I + a + b*x])/b}
{E^((2*I)*ArcTan[a + b*x])/x, x, 3, ((I - a)*Log[x])/(I + a) - ((2*I)*Log[I + a + b*x])/(I + a)}
{E^((2*I)*ArcTan[a + b*x])/x^2, x, 3, -((I - a)/((I + a)*x)) - ((2*I)*b*Log[x])/(I + a)^2 + ((2*I)*b*Log[I + a + b*x])/(I + a)^2}
{E^((2*I)*ArcTan[a + b*x])/x^3, x, 3, -(I - a)/(2*(I + a)*x^2) + ((2*I)*b)/((I + a)^2*x) + ((2*I)*b^2*Log[x])/(I + a)^3 - ((2*I)*b^2*Log[I + a + b*x])/(I + a)^3}
{E^((2*I)*ArcTan[a + b*x])/x^4, x, 3, -(I - a)/(3*(I + a)*x^3) + (I*b)/((I + a)^2*x^2) - ((2*I)*b^2)/((I + a)^3*x) - ((2*I)*b^3*Log[x])/(I + a)^4 + ((2*I)*b^3*Log[I + a + b*x])/(I + a)^4}


{E^((3*I)*ArcTan[a + b*x])*x^4, x, 8, (-3*(19*I + 68*a - (88*I)*a^2 - 48*a^3 + (8*I)*a^4)*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/(8*b^5) - ((2*I)*x^4*(1 + I*a + I*b*x)^(3/2))/(b*Sqrt[1 - I*a - I*b*x]) - ((163*I + 458*a - (422*I)*a^2 - 112*a^3)*Sqrt[1 - I*a - I*b*x]*(1 + I*a + I*b*x)^(3/2))/(40*b^5) + ((61 - (118*I)*a - 52*a^2)*x*Sqrt[1 - I*a - I*b*x]*(1 + I*a + I*b*x)^(3/2))/(20*b^4) + (3*(17*I + 16*a)*x^2*Sqrt[1 - I*a - I*b*x]*(1 + I*a + I*b*x)^(3/2))/(20*b^3) - (11*x^3*Sqrt[1 - I*a - I*b*x]*(1 + I*a + I*b*x)^(3/2))/(5*b^2) - (3*(19 - (68*I)*a - 88*a^2 + (48*I)*a^3 + 8*a^4)*ArcSinh[a + b*x])/(8*b^5)}
{E^((3*I)*ArcTan[a + b*x])*x^3, x, 7, (3*(17 - (44*I)*a - 36*a^2 + (8*I)*a^3)*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/(8*b^4) - ((2*I)*x^3*(1 + I*a + I*b*x)^(3/2))/(b*Sqrt[1 - I*a - I*b*x]) + ((29 - (54*I)*a - 22*a^2)*Sqrt[1 - I*a - I*b*x]*(1 + I*a + I*b*x)^(3/2))/(8*b^4) + ((11*I + 10*a)*x*Sqrt[1 - I*a - I*b*x]*(1 + I*a + I*b*x)^(3/2))/(4*b^3) - (9*x^2*Sqrt[1 - I*a - I*b*x]*(1 + I*a + I*b*x)^(3/2))/(4*b^2) - (3*(17*I + 44*a - (36*I)*a^2 - 8*a^3)*ArcSinh[a + b*x])/(8*b^4)}
{E^((3*I)*ArcTan[a + b*x])*x^2, x, 6, ((I/2)*(11 - (18*I)*a - 6*a^2)*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/b^3 + ((I/6)*(11 - (18*I)*a - 6*a^2)*Sqrt[1 - I*a - I*b*x]*(1 + I*a + I*b*x)^(3/2))/b^3 - (I*(I + a)^2*(1 + I*a + I*b*x)^(5/2))/(b^3*Sqrt[1 - I*a - I*b*x]) + ((I/3)*Sqrt[1 - I*a - I*b*x]*(1 + I*a + I*b*x)^(5/2))/b^3 + ((11 - (18*I)*a - 6*a^2)*ArcSinh[a + b*x])/(2*b^3)}
{E^((3*I)*ArcTan[a + b*x])*x, x, 5, (((3*I)/2)*(3*I + 2*a)*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/b^2 + ((I/2)*(3*I + 2*a)*Sqrt[1 - I*a - I*b*x]*(1 + I*a + I*b*x)^(3/2))/b^2 - ((1 - I*a)*(1 + I*a + I*b*x)^(5/2))/(b^2*Sqrt[1 - I*a - I*b*x]) + (3*(3*I + 2*a)*ArcSinh[a + b*x])/(2*b^2)}
{E^((3*I)*ArcTan[a + b*x]), x, 4, ((-3*I)*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/b - ((2*I)*(1 + I*a + I*b*x)^(3/2))/(b*Sqrt[1 - I*a - I*b*x]) - (3*ArcSinh[a + b*x])/b}
{E^((3*I)*ArcTan[a + b*x])/x, x, 6, (2*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/(1 - I*a) + (2*(1 + I*a + I*b*x)^(3/2))/((1 - I*a)*Sqrt[1 - I*a - I*b*x]) - I*ArcSinh[a + b*x] - (2*(I - a)^(3/2)*ArcTanh[(Sqrt[I - a]*Sqrt[1 - I*a - I*b*x])/(Sqrt[I + a]*Sqrt[1 + I*a + I*b*x])])/(I + a)^(3/2)}
{E^((3*I)*ArcTan[a + b*x])/x^2, x, 4, -((6*I*b*Sqrt[1 + I*a + I*b*x])/((I + a)^2*Sqrt[1 - I*a - I*b*x])) - (I*(1 + I*a + I*b*x)^(3/2))/((I + a)*x*Sqrt[1 - I*a - I*b*x]) + (6*I*Sqrt[I - a]*b*ArcTanh[(Sqrt[I - a]*Sqrt[1 - I*a - I*b*x])/(Sqrt[I + a]*Sqrt[1 + I*a + I*b*x])])/(I + a)^(5/2)}
{E^((3*I)*ArcTan[a + b*x])/x^3, x, 6, ((14*I - a)*b^2*Sqrt[1 + I*a + I*b*x])/(2*(I + a)^3*Sqrt[1 - I*a - I*b*x]) + ((4*I - a)*b*Sqrt[1 + I*a + I*b*x])/(2*(I + a)^2*x*Sqrt[1 - I*a - I*b*x]) - (1 + I*a + I*b*x)^(3/2)/(2*(1 - I*a)*x^2*Sqrt[1 - I*a - I*b*x]) + (3*(3 + 2*I*a)*b^2*ArcTanh[(Sqrt[I - a]*Sqrt[1 - I*a - I*b*x])/(Sqrt[I + a]*Sqrt[1 + I*a + I*b*x])])/(Sqrt[I - a]*(I + a)^(7/2))}
{E^((3*I)*ArcTan[a + b*x])/x^4, x, 7, ((52 + 51*I*a - 2*a^2)*b^3*Sqrt[1 + I*a + I*b*x])/(6*(I - a)*(I + a)^4*Sqrt[1 - I*a - I*b*x]) + ((5*I - 2*a)*b*Sqrt[1 + I*a + I*b*x])/(6*(I + a)^2*x^2*Sqrt[1 - I*a - I*b*x]) + ((19 + 16*I*a)*b^2*Sqrt[1 + I*a + I*b*x])/(6*(I - a)*(I + a)^3*x*Sqrt[1 - I*a - I*b*x]) - (1 + I*a + I*b*x)^(3/2)/(3*(1 - I*a)*x^3*Sqrt[1 - I*a - I*b*x]) - ((11*I - 18*a - 6*I*a^2)*b^3*ArcTanh[(Sqrt[I - a]*Sqrt[1 - I*a - I*b*x])/(Sqrt[I + a]*Sqrt[1 + I*a + I*b*x])])/((I - a)^(3/2)*(I + a)^(9/2))}


(* ::Subsubsection::Closed:: *)
(*n I<0*)


{x^4/E^(I*ArcTan[a + b*x]), x, 7, -((64*I - 275*a - (332*I)*a^2 + 250*a^3 + (24*I)*a^4)*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/(120*b^5) - ((45 + (116*I)*a - 130*a^2 - (24*I)*a^3)*x*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/(120*b^4) + ((I/60)*(16 + (35*I)*a - 12*a^2)*x^2*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/b^3 - ((I/20)*(5*I - 4*a)*x^3*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/b^2 - ((I/5)*x^4*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/b + ((3 + (12*I)*a - 24*a^2 - (16*I)*a^3 + 8*a^4)*ArcSinh[a + b*x])/(8*b^5)}
{x^3/E^(I*ArcTan[a + b*x]), x, 6, -((16 + (39*I)*a - 44*a^2 - (6*I)*a^3)*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/(24*b^4) + ((I/24)*(9 + (20*I)*a - 6*a^2)*x*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/b^3 - ((I/12)*(4*I - 3*a)*x^2*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/b^2 - ((I/4)*x^3*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/b - ((3*I - 12*a - (12*I)*a^2 + 8*a^3)*ArcSinh[a + b*x])/(8*b^4)}
{x^2/E^(I*ArcTan[a + b*x]), x, 5, ((I - 2*a - (2*I)*a^2)*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/(2*b^3) + ((I - 4*a)*(1 - I*a - I*b*x)^(3/2)*Sqrt[1 + I*a + I*b*x])/(6*b^3) + (x*(1 - I*a - I*b*x)^(3/2)*Sqrt[1 + I*a + I*b*x])/(3*b^2) - ((1 + (2*I)*a - 2*a^2)*ArcSinh[a + b*x])/(2*b^3)}
{x/E^(I*ArcTan[a + b*x]), x, 4, ((-I/2)*(I - 2*a)*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/b^2 + ((1 - I*a - I*b*x)^(3/2)*Sqrt[1 + I*a + I*b*x])/(2*b^2) + ((I - 2*a)*ArcSinh[a + b*x])/(2*b^2)}
{E^((-I)*ArcTan[a + b*x]), x, 3, ((-I)*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/b + ArcSinh[a + b*x]/b}
{1/(E^(I*ArcTan[a + b*x])*x), x, 4, (-I)*ArcSinh[a + b*x] - (2*Sqrt[I + a]*ArcTanh[(Sqrt[I - a]*Sqrt[1 - I*a - I*b*x])/(Sqrt[I + a]*Sqrt[1 + I*a + I*b*x])])/Sqrt[I - a]}
{1/(E^(I*ArcTan[a + b*x])*x^2), x, 3, -((Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/((1 + I*a)*x)) - (2*I*b*ArcTanh[(Sqrt[I - a]*Sqrt[1 - I*a - I*b*x])/(Sqrt[I + a]*Sqrt[1 + I*a + I*b*x])])/((I - a)^(3/2)*Sqrt[I + a])}
{1/(E^(I*ArcTan[a + b*x])*x^3), x, 5, -((Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/(2*(1 + I*a)*x^2)) - (I*(2*I + a)*b*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/(2*(I - a)^2*(I + a)*x) + ((1 - 2*I*a)*b^2*ArcTanh[(Sqrt[I - a]*Sqrt[1 - I*a - I*b*x])/(Sqrt[I + a]*Sqrt[1 + I*a + I*b*x])])/((I - a)^(5/2)*(I + a)^(3/2))}
{1/(E^(I*ArcTan[a + b*x])*x^4), x, 6, -((Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/(3*(1 + I*a)*x^3)) - (I*(3*I + 2*a)*b*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/(6*(I - a)^2*(I + a)*x^2) + ((1 - 2*I*a)*(4*I + a)*b^2*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/(6*(I - a)^3*(I + a)^2*x) + ((I + 2*a - 2*I*a^2)*b^3*ArcTanh[(Sqrt[I - a]*Sqrt[1 - I*a - I*b*x])/(Sqrt[I + a]*Sqrt[1 + I*a + I*b*x])])/((I - a)^(7/2)*(I + a)^(5/2))}


{x^4/E^((2*I)*ArcTan[a + b*x]), x, 3, (-2*(1 + I*a)^3*x)/b^4 - (I*(I - a)^2*x^2)/b^3 + (2*(1 + I*a)*x^3)/(3*b^2) - ((I/2)*x^4)/b - x^5/5 - ((2*I)*(I - a)^4*Log[I - a - b*x])/b^5}
{x^3/E^((2*I)*ArcTan[a + b*x]), x, 3, ((-2*I)*(I - a)^2*x)/b^3 + ((1 + I*a)*x^2)/b^2 - (((2*I)/3)*x^3)/b - x^4/4 - (2*(1 + I*a)^3*Log[I - a - b*x])/b^4}
{x^2/E^((2*I)*ArcTan[a + b*x]), x, 3, (2*(1 + I*a)*x)/b^2 - (I*x^2)/b - x^3/3 - ((2*I)*(I - a)^2*Log[I - a - b*x])/b^3}
{x/E^((2*I)*ArcTan[a + b*x]), x, 3, ((-2*I)*x)/b - x^2/2 + (2*(1 + I*a)*Log[I - a - b*x])/b^2}
{E^((-2*I)*ArcTan[a + b*x]), x, 3, -x - ((2*I)*Log[I - a - b*x])/b}
{1/(E^((2*I)*ArcTan[a + b*x])*x), x, 3, ((I + a)*Log[x])/(I - a) - (2*Log[I - a - b*x])/(1 + I*a)}
{1/(E^((2*I)*ArcTan[a + b*x])*x^2), x, 3, -((I + a)/((I - a)*x)) + ((2*I)*b*Log[x])/(I - a)^2 - ((2*I)*b*Log[I - a - b*x])/(I - a)^2}
{1/(E^((2*I)*ArcTan[a + b*x])*x^3), x, 3, -(I + a)/(2*(I - a)*x^2) - ((2*I)*b)/((I - a)^2*x) - (2*b^2*Log[x])/(1 + I*a)^3 + (2*b^2*Log[I - a - b*x])/(1 + I*a)^3}
{1/(E^((2*I)*ArcTan[a + b*x])*x^4), x, 3, -(I + a)/(3*(I - a)*x^3) - (I*b)/((I - a)^2*x^2) + (2*b^2)/((1 + I*a)^3*x) + ((2*I)*b^3*Log[x])/(I - a)^4 - ((2*I)*b^3*Log[I - a - b*x])/(I - a)^4}


{x^4/E^((3*I)*ArcTan[a + b*x]), x, 8, ((2*I)*x^4*(1 - I*a - I*b*x)^(3/2))/(b*Sqrt[1 + I*a + I*b*x]) + (3*(19*I - 68*a - (88*I)*a^2 + 48*a^3 + (8*I)*a^4)*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/(8*b^5) + ((163*I - 458*a - (422*I)*a^2 + 112*a^3)*(1 - I*a - I*b*x)^(3/2)*Sqrt[1 + I*a + I*b*x])/(40*b^5) + ((61 + (118*I)*a - 52*a^2)*x*(1 - I*a - I*b*x)^(3/2)*Sqrt[1 + I*a + I*b*x])/(20*b^4) - (3*(17*I - 16*a)*x^2*(1 - I*a - I*b*x)^(3/2)*Sqrt[1 + I*a + I*b*x])/(20*b^3) - (11*x^3*(1 - I*a - I*b*x)^(3/2)*Sqrt[1 + I*a + I*b*x])/(5*b^2) - (3*(19 + (68*I)*a - 88*a^2 - (48*I)*a^3 + 8*a^4)*ArcSinh[a + b*x])/(8*b^5)}
{x^3/E^((3*I)*ArcTan[a + b*x]), x, 7, ((2*I)*x^3*(1 - I*a - I*b*x)^(3/2))/(b*Sqrt[1 + I*a + I*b*x]) + (3*(17 + (44*I)*a - 36*a^2 - (8*I)*a^3)*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/(8*b^4) + ((29 + (54*I)*a - 22*a^2)*(1 - I*a - I*b*x)^(3/2)*Sqrt[1 + I*a + I*b*x])/(8*b^4) - ((11*I - 10*a)*x*(1 - I*a - I*b*x)^(3/2)*Sqrt[1 + I*a + I*b*x])/(4*b^3) - (9*x^2*(1 - I*a - I*b*x)^(3/2)*Sqrt[1 + I*a + I*b*x])/(4*b^2) + (3*(17*I - 44*a - (36*I)*a^2 + 8*a^3)*ArcSinh[a + b*x])/(8*b^4)}
{x^2/E^((3*I)*ArcTan[a + b*x]), x, 6, (I*(I - a)^2*(1 - I*a - I*b*x)^(5/2))/(b^3*Sqrt[1 + I*a + I*b*x]) - ((I/2)*(11 + (18*I)*a - 6*a^2)*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/b^3 - ((I/6)*(11 + (18*I)*a - 6*a^2)*(1 - I*a - I*b*x)^(3/2)*Sqrt[1 + I*a + I*b*x])/b^3 - ((I/3)*(1 - I*a - I*b*x)^(5/2)*Sqrt[1 + I*a + I*b*x])/b^3 + ((11 + (18*I)*a - 6*a^2)*ArcSinh[a + b*x])/(2*b^3)}
{x/E^((3*I)*ArcTan[a + b*x]), x, 5, (I*(I - a)*(1 - I*a - I*b*x)^(5/2))/(b^2*Sqrt[1 + I*a + I*b*x]) - (3*(3 + (2*I)*a)*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/(2*b^2) - ((3 + (2*I)*a)*(1 - I*a - I*b*x)^(3/2)*Sqrt[1 + I*a + I*b*x])/(2*b^2) - (3*(3*I - 2*a)*ArcSinh[a + b*x])/(2*b^2)}
{E^((-3*I)*ArcTan[a + b*x]), x, 4, ((2*I)*(1 - I*a - I*b*x)^(3/2))/(b*Sqrt[1 + I*a + I*b*x]) + ((3*I)*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/b - (3*ArcSinh[a + b*x])/b}
{1/(E^((3*I)*ArcTan[a + b*x])*x), x, 6, (2*(1 - I*a - I*b*x)^(3/2))/((1 + I*a)*Sqrt[1 + I*a + I*b*x]) + (2*Sqrt[1 - I*a - I*b*x]*Sqrt[1 + I*a + I*b*x])/(1 + I*a) + I*ArcSinh[a + b*x] - (2*(I + a)^(3/2)*ArcTanh[(Sqrt[I - a]*Sqrt[1 - I*a - I*b*x])/(Sqrt[I + a]*Sqrt[1 + I*a + I*b*x])])/(I - a)^(3/2)}
{1/(E^((3*I)*ArcTan[a + b*x])*x^2), x, 4, (6*I*b*Sqrt[1 - I*a - I*b*x])/((I - a)^2*Sqrt[1 + I*a + I*b*x]) - (1 - I*a - I*b*x)^(3/2)/((1 + I*a)*x*Sqrt[1 + I*a + I*b*x]) - (6*I*Sqrt[I + a]*b*ArcTanh[(Sqrt[I - a]*Sqrt[1 - I*a - I*b*x])/(Sqrt[I + a]*Sqrt[1 + I*a + I*b*x])])/(I - a)^(5/2)}
{1/(E^((3*I)*ArcTan[a + b*x])*x^3), x, 6, ((14*I + a)*b^2*Sqrt[1 - I*a - I*b*x])/(2*(I - a)^3*Sqrt[1 + I*a + I*b*x]) - ((4*I + a)*b*Sqrt[1 - I*a - I*b*x])/(2*(I - a)^2*x*Sqrt[1 + I*a + I*b*x]) - (1 - I*a - I*b*x)^(3/2)/(2*(1 + I*a)*x^2*Sqrt[1 + I*a + I*b*x]) + (3*(3 - 2*I*a)*b^2*ArcTanh[(Sqrt[I - a]*Sqrt[1 - I*a - I*b*x])/(Sqrt[I + a]*Sqrt[1 + I*a + I*b*x])])/((I - a)^(7/2)*Sqrt[I + a])}
{1/(E^((3*I)*ArcTan[a + b*x])*x^4), x, 7, -(((52 - 51*I*a - 2*a^2)*b^3*Sqrt[1 - I*a - I*b*x])/(6*(I - a)^4*(I + a)*Sqrt[1 + I*a + I*b*x])) - ((5*I + 2*a)*b*Sqrt[1 - I*a - I*b*x])/(6*(I - a)^2*x^2*Sqrt[1 + I*a + I*b*x]) + ((19*I + 16*a)*b^2*Sqrt[1 - I*a - I*b*x])/(6*(1 + I*a)^3*(I + a)*x*Sqrt[1 + I*a + I*b*x]) - (1 - I*a - I*b*x)^(3/2)/(3*(1 + I*a)*x^3*Sqrt[1 + I*a + I*b*x]) + (I*(11 - 18*I*a - 6*a^2)*b^3*ArcTanh[(Sqrt[I - a]*Sqrt[1 - I*a - I*b*x])/(Sqrt[I + a]*Sqrt[1 + I*a + I*b*x])])/((I - a)^(9/2)*(I + a)^(3/2))}


(* ::Subsubsection::Closed:: *)
(*n I/2>0*)


{E^((I/2)*ArcTan[a + b*x])*x^2, x, 12, -((3*I + 4*a - (8*I)*a^2)*(1 - I*a - I*b*x)^(3/4)*(1 + I*a + I*b*x)^(1/4))/(8*b^3) - ((I + 8*a)*(1 - I*a - I*b*x)^(3/4)*(1 + I*a + I*b*x)^(5/4))/(12*b^3) + (x*(1 - I*a - I*b*x)^(3/4)*(1 + I*a + I*b*x)^(5/4))/(3*b^2) + ((3*I + 4*a - (8*I)*a^2)*ArcTan[1 - (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(8*Sqrt[2]*b^3) - ((3*I + 4*a - (8*I)*a^2)*ArcTan[1 + (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(8*Sqrt[2]*b^3) - ((3*I + 4*a - (8*I)*a^2)*Log[1 + Sqrt[1 - I*a - I*b*x]/Sqrt[1 + I*a + I*b*x] - (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(16*Sqrt[2]*b^3) + ((3*I + 4*a - (8*I)*a^2)*Log[1 + Sqrt[1 - I*a - I*b*x]/Sqrt[1 + I*a + I*b*x] + (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(16*Sqrt[2]*b^3)}
{E^((I/2)*ArcTan[a + b*x])*x, x, 11, ((1 - (4*I)*a)*(1 - I*a - I*b*x)^(3/4)*(1 + I*a + I*b*x)^(1/4))/(4*b^2) + ((1 - I*a - I*b*x)^(3/4)*(1 + I*a + I*b*x)^(5/4))/(2*b^2) - ((1 - (4*I)*a)*ArcTan[1 - (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(4*Sqrt[2]*b^2) + ((1 - (4*I)*a)*ArcTan[1 + (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(4*Sqrt[2]*b^2) + ((1 - (4*I)*a)*Log[1 + Sqrt[1 - I*a - I*b*x]/Sqrt[1 + I*a + I*b*x] - (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(8*Sqrt[2]*b^2) - ((1 - (4*I)*a)*Log[1 + Sqrt[1 - I*a - I*b*x]/Sqrt[1 + I*a + I*b*x] + (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(8*Sqrt[2]*b^2)}
{E^((I/2)*ArcTan[a + b*x]), x, 10, (I*(1 - I*a - I*b*x)^(3/4)*(1 + I*a + I*b*x)^(1/4))/b - (I*ArcTan[1 - (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(Sqrt[2]*b) + (I*ArcTan[1 + (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(Sqrt[2]*b) + ((I/2)*Log[1 + Sqrt[1 - I*a - I*b*x]/Sqrt[1 + I*a + I*b*x] - (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(Sqrt[2]*b) - ((I/2)*Log[1 + Sqrt[1 - I*a - I*b*x]/Sqrt[1 + I*a + I*b*x] + (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(Sqrt[2]*b)}
{E^((I/2)*ArcTan[a + b*x])/x, x, 16, -((2*Sqrt[1 + I*a]*ArcTan[((1 - I*a)^(1/4)*(1 + I*(a + b*x))^(1/4))/((1 + I*a)^(1/4)*(1 - I*(a + b*x))^(1/4))])/(1 + a^2)^(1/4)) - Sqrt[2]*ArcTan[1 - (Sqrt[2]*(1 + I*(a + b*x))^(1/4))/(1 - I*(a + b*x))^(1/4)] + Sqrt[2]*ArcTan[1 + (Sqrt[2]*(1 + I*(a + b*x))^(1/4))/(1 - I*(a + b*x))^(1/4)] - (2*Sqrt[1 + I*a]*ArcTanh[((1 - I*a)^(1/4)*(1 + I*(a + b*x))^(1/4))/((1 + I*a)^(1/4)*(1 - I*(a + b*x))^(1/4))])/(1 + a^2)^(1/4) - Log[1 - (Sqrt[2]*(1 + I*(a + b*x))^(1/4))/(1 - I*(a + b*x))^(1/4) + Sqrt[1 + I*(a + b*x)]/Sqrt[1 - I*(a + b*x)]]/Sqrt[2] + Log[1 + (Sqrt[2]*(1 + I*(a + b*x))^(1/4))/(1 - I*(a + b*x))^(1/4) + Sqrt[1 + I*(a + b*x)]/Sqrt[1 - I*(a + b*x)]]/Sqrt[2]}
{E^((I/2)*ArcTan[a + b*x])/x^2, x, 6, -((2*b*(1 + I*(a + b*x))^(1/4))/((I + a)*(1 - I*(a + b*x))^(1/4)*(1 + I*a + (I*(I + a)*(1 + I*(a + b*x)))/(1 - I*(a + b*x))))) + (b*ArcTan[((1 - I*a)^(1/4)*(1 + I*(a + b*x))^(1/4))/((1 + I*a)^(1/4)*(1 - I*(a + b*x))^(1/4))])/(Sqrt[1 + I*a]*(I + a)*(1 + a^2)^(1/4)) + (b*ArcTanh[((1 - I*a)^(1/4)*(1 + I*(a + b*x))^(1/4))/((1 + I*a)^(1/4)*(1 - I*(a + b*x))^(1/4))])/(Sqrt[1 + I*a]*(I + a)*(1 + a^2)^(1/4))}


{E^(((3*I)/2)*ArcTan[a + b*x])*x^2, x, 12, -((17*I + 36*a - (24*I)*a^2)*(1 - I*a - I*b*x)^(1/4)*(1 + I*a + I*b*x)^(3/4))/(24*b^3) - ((3*I + 8*a)*(1 - I*a - I*b*x)^(1/4)*(1 + I*a + I*b*x)^(7/4))/(12*b^3) + (x*(1 - I*a - I*b*x)^(1/4)*(1 + I*a + I*b*x)^(7/4))/(3*b^2) + ((17*I + 36*a - (24*I)*a^2)*ArcTan[1 - (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(8*Sqrt[2]*b^3) - ((17*I + 36*a - (24*I)*a^2)*ArcTan[1 + (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(8*Sqrt[2]*b^3) + ((17*I + 36*a - (24*I)*a^2)*Log[1 + Sqrt[1 - I*a - I*b*x]/Sqrt[1 + I*a + I*b*x] - (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(16*Sqrt[2]*b^3) - ((17*I + 36*a - (24*I)*a^2)*Log[1 + Sqrt[1 - I*a - I*b*x]/Sqrt[1 + I*a + I*b*x] + (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(16*Sqrt[2]*b^3)}
{E^(((3*I)/2)*ArcTan[a + b*x])*x, x, 11, ((3 - (4*I)*a)*(1 - I*a - I*b*x)^(1/4)*(1 + I*a + I*b*x)^(3/4))/(4*b^2) + ((1 - I*a - I*b*x)^(1/4)*(1 + I*a + I*b*x)^(7/4))/(2*b^2) - (3*(3 - (4*I)*a)*ArcTan[1 - (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(4*Sqrt[2]*b^2) + (3*(3 - (4*I)*a)*ArcTan[1 + (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(4*Sqrt[2]*b^2) - (3*(3 - (4*I)*a)*Log[1 + Sqrt[1 - I*a - I*b*x]/Sqrt[1 + I*a + I*b*x] - (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(8*Sqrt[2]*b^2) + (3*(3 - (4*I)*a)*Log[1 + Sqrt[1 - I*a - I*b*x]/Sqrt[1 + I*a + I*b*x] + (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(8*Sqrt[2]*b^2)}
{E^(((3*I)/2)*ArcTan[a + b*x]), x, 10, (I*(1 - I*a - I*b*x)^(1/4)*(1 + I*a + I*b*x)^(3/4))/b - ((3*I)*ArcTan[1 - (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(Sqrt[2]*b) + ((3*I)*ArcTan[1 + (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(Sqrt[2]*b) - (((3*I)/2)*Log[1 + Sqrt[1 - I*a - I*b*x]/Sqrt[1 + I*a + I*b*x] - (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(Sqrt[2]*b) + (((3*I)/2)*Log[1 + Sqrt[1 - I*a - I*b*x]/Sqrt[1 + I*a + I*b*x] + (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(Sqrt[2]*b)}
{E^(((3*I)/2)*ArcTan[a + b*x])/x, x, 13, (2*(1 + I*a)*ArcTan[((1 - I*a)^(1/4)*(1 + I*a + I*b*x)^(1/4))/((1 + I*a)^(1/4)*(1 - I*a - I*b*x)^(1/4))])/(Sqrt[1 - I*a]*(1 + a^2)^(1/4)) - Sqrt[2]*ArcTan[1 - (Sqrt[2]*(1 + I*a + I*b*x)^(1/4))/(1 - I*a - I*b*x)^(1/4)] + Sqrt[2]*ArcTan[1 + (Sqrt[2]*(1 + I*a + I*b*x)^(1/4))/(1 - I*a - I*b*x)^(1/4)] + (2*I*(I - a)*ArcTanh[((1 - I*a)^(1/4)*(1 + I*a + I*b*x)^(1/4))/((1 + I*a)^(1/4)*(1 - I*a - I*b*x)^(1/4))])/(Sqrt[1 - I*a]*(1 + a^2)^(1/4)) + Log[1 - (Sqrt[2]*(1 + I*a + I*b*x)^(1/4))/(1 - I*a - I*b*x)^(1/4) + Sqrt[1 + I*a + I*b*x]/Sqrt[1 - I*a - I*b*x]]/Sqrt[2] - Log[1 + (Sqrt[2]*(1 + I*a + I*b*x)^(1/4))/(1 - I*a - I*b*x)^(1/4) + Sqrt[1 + I*a + I*b*x]/Sqrt[1 - I*a - I*b*x]]/Sqrt[2]}
{E^(((3*I)/2)*ArcTan[a + b*x])/x^2, x, 6, -((I*(1 - I*a - I*b*x)^(1/4)*(1 + I*a + I*b*x)^(3/4))/((I + a)*x)) - (3*I*b*ArcTan[((1 + I*a)^(1/4)*(1 - I*a - I*b*x)^(1/4))/((1 - I*a)^(1/4)*(1 + I*a + I*b*x)^(1/4))])/((1 - I*a)^(3/2)*(1 + a^2)^(1/4)) - (3*I*b*ArcTanh[((1 + I*a)^(1/4)*(1 - I*a - I*b*x)^(1/4))/((1 - I*a)^(1/4)*(1 + I*a + I*b*x)^(1/4))])/((1 - I*a)^(3/2)*(1 + a^2)^(1/4))}


(* ::Subsubsection::Closed:: *)
(*n I/2<0*)


{x^2/E^((I/2)*ArcTan[a + b*x]), x, 12, ((3*I - 4*a - (8*I)*a^2)*(1 - I*a - I*b*x)^(1/4)*(1 + I*a + I*b*x)^(3/4))/(8*b^3) + ((I - 8*a)*(1 - I*a - I*b*x)^(5/4)*(1 + I*a + I*b*x)^(3/4))/(12*b^3) + (x*(1 - I*a - I*b*x)^(5/4)*(1 + I*a + I*b*x)^(3/4))/(3*b^2) + ((3*I - 4*a - (8*I)*a^2)*ArcTan[1 - (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(8*Sqrt[2]*b^3) - ((3*I - 4*a - (8*I)*a^2)*ArcTan[1 + (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(8*Sqrt[2]*b^3) + ((3*I - 4*a - (8*I)*a^2)*Log[1 + Sqrt[1 - I*a - I*b*x]/Sqrt[1 + I*a + I*b*x] - (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(16*Sqrt[2]*b^3) - ((3*I - 4*a - (8*I)*a^2)*Log[1 + Sqrt[1 - I*a - I*b*x]/Sqrt[1 + I*a + I*b*x] + (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(16*Sqrt[2]*b^3)}
{x/E^((I/2)*ArcTan[a + b*x]), x, 11, ((-I/4)*(I - 4*a)*(1 - I*a - I*b*x)^(1/4)*(1 + I*a + I*b*x)^(3/4))/b^2 + ((1 - I*a - I*b*x)^(5/4)*(1 + I*a + I*b*x)^(3/4))/(2*b^2) - ((I/4)*(I - 4*a)*ArcTan[1 - (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(Sqrt[2]*b^2) + ((I/4)*(I - 4*a)*ArcTan[1 + (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(Sqrt[2]*b^2) - ((I/8)*(I - 4*a)*Log[1 + Sqrt[1 - I*a - I*b*x]/Sqrt[1 + I*a + I*b*x] - (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(Sqrt[2]*b^2) + ((I/8)*(I - 4*a)*Log[1 + Sqrt[1 - I*a - I*b*x]/Sqrt[1 + I*a + I*b*x] + (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(Sqrt[2]*b^2)}
{E^((-I/2)*ArcTan[a + b*x]), x, 10, ((-I)*(1 - I*a - I*b*x)^(1/4)*(1 + I*a + I*b*x)^(3/4))/b - (I*ArcTan[1 - (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(Sqrt[2]*b) + (I*ArcTan[1 + (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(Sqrt[2]*b) - ((I/2)*Log[1 + Sqrt[1 - I*a - I*b*x]/Sqrt[1 + I*a + I*b*x] - (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(Sqrt[2]*b) + ((I/2)*Log[1 + Sqrt[1 - I*a - I*b*x]/Sqrt[1 + I*a + I*b*x] + (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(Sqrt[2]*b)}
{1/(E^((I/2)*ArcTan[a + b*x])*x), x, 12, -((2*(-1 + I*a)^(1/4)*ArcTan[((-1 - I*a)^(1/4)*(1 - I*(a + b*x))^(1/4))/((-1 + I*a)^(1/4)*(1 + I*(a + b*x))^(1/4))])/(-1 - I*a)^(1/4)) - Sqrt[2]*ArcTan[1 - (Sqrt[2]*(1 - I*(a + b*x))^(1/4))/(1 + I*(a + b*x))^(1/4)] + Sqrt[2]*ArcTan[1 + (Sqrt[2]*(1 - I*(a + b*x))^(1/4))/(1 + I*(a + b*x))^(1/4)] - (2*(-1 + I*a)^(1/4)*ArcTanh[((-1 - I*a)^(1/4)*(1 - I*(a + b*x))^(1/4))/((-1 + I*a)^(1/4)*(1 + I*(a + b*x))^(1/4))])/(-1 - I*a)^(1/4) - Log[1 + Sqrt[1 - I*(a + b*x)]/Sqrt[1 + I*(a + b*x)] - (Sqrt[2]*(1 - I*(a + b*x))^(1/4))/(1 + I*(a + b*x))^(1/4)]/Sqrt[2] + Log[1 + Sqrt[1 - I*(a + b*x)]/Sqrt[1 + I*(a + b*x)] + (Sqrt[2]*(1 - I*(a + b*x))^(1/4))/(1 + I*(a + b*x))^(1/4)]/Sqrt[2]}
{1/(E^((I/2)*ArcTan[a + b*x])*x^2), x, 5, (2*b*(1 - I*(a + b*x))^(1/4))/((I - a)*(1 + I*(a + b*x))^(1/4)*(1 - I*a - ((1 + I*a)*(1 - I*(a + b*x)))/(1 + I*(a + b*x)))) + (I*(-1 + I*a)^(1/4)*b*ArcTan[((-1 - I*a)^(1/4)*(1 - I*(a + b*x))^(1/4))/((-1 + I*a)^(1/4)*(1 + I*(a + b*x))^(1/4))])/((-1 - I*a)^(1/4)*(1 + a^2)) + (I*(-1 + I*a)^(1/4)*b*ArcTanh[((-1 - I*a)^(1/4)*(1 - I*(a + b*x))^(1/4))/((-1 + I*a)^(1/4)*(1 + I*(a + b*x))^(1/4))])/((-1 - I*a)^(1/4)*(1 + a^2))}


{x^2/E^(((3*I)/2)*ArcTan[a + b*x]), x, 12, ((17*I - 36*a - (24*I)*a^2)*(1 - I*a - I*b*x)^(3/4)*(1 + I*a + I*b*x)^(1/4))/(24*b^3) + ((3*I - 8*a)*(1 - I*a - I*b*x)^(7/4)*(1 + I*a + I*b*x)^(1/4))/(12*b^3) + (x*(1 - I*a - I*b*x)^(7/4)*(1 + I*a + I*b*x)^(1/4))/(3*b^2) + ((17*I - 36*a - (24*I)*a^2)*ArcTan[1 - (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(8*Sqrt[2]*b^3) - ((17*I - 36*a - (24*I)*a^2)*ArcTan[1 + (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(8*Sqrt[2]*b^3) - ((17*I - 36*a - (24*I)*a^2)*Log[1 + Sqrt[1 - I*a - I*b*x]/Sqrt[1 + I*a + I*b*x] - (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(16*Sqrt[2]*b^3) + ((17*I - 36*a - (24*I)*a^2)*Log[1 + Sqrt[1 - I*a - I*b*x]/Sqrt[1 + I*a + I*b*x] + (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(16*Sqrt[2]*b^3)}
{x/E^(((3*I)/2)*ArcTan[a + b*x]), x, 11, ((-I/4)*(3*I - 4*a)*(1 - I*a - I*b*x)^(3/4)*(1 + I*a + I*b*x)^(1/4))/b^2 + ((1 - I*a - I*b*x)^(7/4)*(1 + I*a + I*b*x)^(1/4))/(2*b^2) - (((3*I)/4)*(3*I - 4*a)*ArcTan[1 - (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(Sqrt[2]*b^2) + (((3*I)/4)*(3*I - 4*a)*ArcTan[1 + (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(Sqrt[2]*b^2) + (((3*I)/8)*(3*I - 4*a)*Log[1 + Sqrt[1 - I*a - I*b*x]/Sqrt[1 + I*a + I*b*x] - (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(Sqrt[2]*b^2) - (((3*I)/8)*(3*I - 4*a)*Log[1 + Sqrt[1 - I*a - I*b*x]/Sqrt[1 + I*a + I*b*x] + (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(Sqrt[2]*b^2)}
{E^(((-3*I)/2)*ArcTan[a + b*x]), x, 10, ((-I)*(1 - I*a - I*b*x)^(3/4)*(1 + I*a + I*b*x)^(1/4))/b - ((3*I)*ArcTan[1 - (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(Sqrt[2]*b) + ((3*I)*ArcTan[1 + (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(Sqrt[2]*b) + (((3*I)/2)*Log[1 + Sqrt[1 - I*a - I*b*x]/Sqrt[1 + I*a + I*b*x] - (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(Sqrt[2]*b) - (((3*I)/2)*Log[1 + Sqrt[1 - I*a - I*b*x]/Sqrt[1 + I*a + I*b*x] + (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)])/(Sqrt[2]*b)}
{1/(E^(((3*I)/2)*ArcTan[a + b*x])*x), x, 13, -((2*I*(I + a)*ArcTan[((1 + I*a)^(1/4)*(1 - I*a - I*b*x)^(1/4))/((1 - I*a)^(1/4)*(1 + I*a + I*b*x)^(1/4))])/(Sqrt[1 + I*a]*(1 + a^2)^(1/4))) - Sqrt[2]*ArcTan[1 - (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)] + Sqrt[2]*ArcTan[1 + (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)] + (2*I*(I + a)*ArcTanh[((1 + I*a)^(1/4)*(1 - I*a - I*b*x)^(1/4))/((1 - I*a)^(1/4)*(1 + I*a + I*b*x)^(1/4))])/(Sqrt[1 + I*a]*(1 + a^2)^(1/4)) + Log[1 + Sqrt[1 - I*a - I*b*x]/Sqrt[1 + I*a + I*b*x] - (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)]/Sqrt[2] - Log[1 + Sqrt[1 - I*a - I*b*x]/Sqrt[1 + I*a + I*b*x] + (Sqrt[2]*(1 - I*a - I*b*x)^(1/4))/(1 + I*a + I*b*x)^(1/4)]/Sqrt[2]}
{1/(E^(((3*I)/2)*ArcTan[a + b*x])*x^2), x, 6, -(((1 - I*a - I*b*x)^(3/4)*(1 + I*a + I*b*x)^(1/4))/((1 + I*a)*x)) - (3*I*b*ArcTan[((1 + I*a)^(1/4)*(1 - I*a - I*b*x)^(1/4))/((1 - I*a)^(1/4)*(1 + I*a + I*b*x)^(1/4))])/((1 + I*a)^(3/2)*(1 + a^2)^(1/4)) + (3*I*b*ArcTanh[((1 + I*a)^(1/4)*(1 - I*a - I*b*x)^(1/4))/((1 - I*a)^(1/4)*(1 + I*a + I*b*x)^(1/4))])/((1 + I*a)^(3/2)*(1 + a^2)^(1/4))}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{E^(n*ArcTan[a + b*x])*x^m, x, 2, (x^(1 + m)*(1 - I*a - I*b*x)^((I*n)/2)*((1 + I*a + I*b*x)/(1 + I*a))^((I*n)/2)*AppellF1[1 + m, -((I*n)/2), (I*n)/2, 2 + m, -((b*x)/(I + a)), (b*x)/(I - a)])/(((I*(1 - I*a - I*b*x))/(I + a))^((I*n)/2)*(1 + I*a + I*b*x)^((I*n)/2)*(1 + m))}

{E^(n*ArcTan[a + b*x])*x^3, x, 2, -(((6 - 18*a^2 - 10*a*n - n^2)*(1 - I*a - I*b*x)^(1 + (I*n)/2)*(1 + I*a + I*b*x)^(1 - (I*n)/2))/(24*b^4)) - ((6*a + n)*x*(1 - I*a - I*b*x)^(1 + (I*n)/2)*(1 + I*a + I*b*x)^(1 - (I*n)/2))/(12*b^3) + (x^2*(1 - I*a - I*b*x)^(1 + (I*n)/2)*(1 + I*a + I*b*x)^(1 - (I*n)/2))/(4*b^2) - (2^(-2 + (I*n)/2)*(24*a^3 + 36*a^2*n - 12*a*(2 - n^2) - n*(8 - n^2))*(1 + I*a + I*b*x)^(1 - (I*n)/2)*Hypergeometric2F1[1 - (I*n)/2, -((I*n)/2), 2 - (I*n)/2, (1/2)*(1 + I*a + I*b*x)])/(3*b^4*(2*I + n)), ((1/4)*x^4*(1 - I*a - I*b*x)^((I*n)/2)*((1 + I*a + I*b*x)/(1 + I*a))^((I*n)/2)*AppellF1[4, -((I*n)/2), (I*n)/2, 5, -((b*x)/(I + a)), (b*x)/(I - a)])/(((I*(1 - I*a - I*b*x))/(I + a))^((I*n)/2)*(1 + I*a + I*b*x)^((I*n)/2))}
{E^(n*ArcTan[a + b*x])*x^2, x, 4, -(((4*a + n)*(1 - I*a - I*b*x)^(1 + (I*n)/2)*(1 + I*a + I*b*x)^(1 - (I*n)/2))/(6*b^3)) + (x*(1 - I*a - I*b*x)^(1 + (I*n)/2)*(1 + I*a + I*b*x)^(1 - (I*n)/2))/(3*b^2) - (2^((I*n)/2)*(2 - 6*a^2 - 6*a*n - n^2)*(1 + I*a + I*b*x)^(1 - (I*n)/2)*Hypergeometric2F1[1 - (I*n)/2, -((I*n)/2), 2 - (I*n)/2, (1/2)*(1 + I*a + I*b*x)])/(3*b^3*(2*I + n))}
{E^(n*ArcTan[a + b*x])*x^1, x, 3, ((1 - I*a - I*b*x)^(1 + (I*n)/2)*(1 + I*a + I*b*x)^(1 - (I*n)/2))/(2*b^2) - (2^((I*n)/2)*(2*a + n)*(1 + I*a + I*b*x)^(1 - (I*n)/2)*Hypergeometric2F1[1 - (I*n)/2, -((I*n)/2), 2 - (I*n)/2, (1/2)*(1 + I*a + I*b*x)])/(b^2*(2*I + n))}
{E^(n*ArcTan[a + b*x])*x^0, x, 2, (2^(1 + (I*n)/2)*(1 + I*a + I*b*x)^(1 - (I*n)/2)*Hypergeometric2F1[1 - (I*n)/2, -((I*n)/2), 2 - (I*n)/2, (1/2)*(1 + I*a + I*b*x)])/(b*(2*I + n))}
{E^(n*ArcTan[a + b*x])/x^1, x, 2, (2^(1 - (I*n)/2)*(1 - I*a - I*b*x)^(1 + (I*n)/2)*AppellF1[1 + (I*n)/2, 1, (I*n)/2, 2 + (I*n)/2, (1 - I*a - I*b*x)/(1 - I*a), (1/2)*(1 - I*a - I*b*x)])/((I + a)*(2*I - n))}
{E^(n*ArcTan[a + b*x])/x^2, x, 2, -((2^(1 - (I*n)/2)*b*(1 - I*a - I*b*x)^(1 + (I*n)/2)*(1 + (1/2)*I*(I + a + b*x))^(-1 - (I*n)/2)*Hypergeometric2F1[2, 1 + (I*n)/2, 2 + (I*n)/2, (I*(I + a + b*x) + (2*(I + a + b*x))/(I + a))/(2 + I*(I + a + b*x))])/((I + a)^2*(2*I - n)))}
{E^(n*ArcTan[a + b*x])/x^3, x, 2, (2^(1 - (I*n)/2)*b^2*(1 - I*a - I*b*x)^(1 + (I*n)/2)*Defer[AppellF1][1 + (I*n)/2, 3, (I*n)/2, 2 + (I*n)/2, -((1 - I*a - I*b*x)/(-1 + I*a)), -((I*b*(1 - I*a - I*b*x))/((-I)*(1 - I*a)*b - I*(1 + I*a)*b))])/((I + a)^3*(2*I - n))}


(* ::Section::Closed:: *)
(*Problems from Calculus textbooks*)


(* ::Subsubsection::Closed:: *)
(*Apostol Calculus, Volume 1, 2nd Edition, Section 622*)


{ArcTan[Sqrt[x]]/(Sqrt[x]*(1 + x)), x, 1, ArcTan[Sqrt[x]]^2}


(* ::Subsubsection::Closed:: *)
(*Edwards and Penney Calculus*)


{ArcTan[x]/(-1 + x)^3, x, 7, 1/(4*(1 - x)) - ArcTan[x]/(2*(1 - x)^2) - (1/4)*Log[1 - x] + (1/8)*Log[1 + x^2]}
{ArcTan[1 + 2*x]/(4 + 3*x)^3, x, 8, -(1/(34*(4 + 3*x))) + (8/867)*ArcTan[1 + 2*x] - ArcTan[1 + 2*x]/(6*(4 + 3*x)^2) + (5/289)*Log[4 + 3*x] - (5/578)*Log[1 + 2*x + 2*x^2]}


(* ::Subsubsection::Closed:: *)
(*Thomas Calculus, 8th Edition*)


{ArcTan[Sqrt[1 + x]], x, 4, -Sqrt[1 + x] + 2*ArcTan[Sqrt[1 + x]] + x*ArcTan[Sqrt[1 + x]]}


(* ::Section::Closed:: *)
(*Miscellaneous integrands involving inverse tangents*)


{ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]/(1 - a^2*x^2), x, -5, -((I*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])])/(2*a)) + (I*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]])/(2*a)}


{1/((1 + x^2)*(2 + ArcTan[x])), x, 1, Log[2 + ArcTan[x]]}
{1/((a + a*x^2)*(b - 2*b*ArcTan[x])), x, 1, -(Log[1 - 2*ArcTan[x]]/(2*a*b))}


{(x + x^3 + (1 + x)^2*ArcTan[x])/((1 + x)^2*(1 + x^2)), x, 5, 1/(1 + x) + ArcTan[x]^2/2 + Log[1 + x]}
