(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Inverse Cotangents*)


(* ::Section::Closed:: *)
(*Integrands of the form u ArcCot[a x^n]^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcCot[a x]^n*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{x^m*ArcCot[a*x], x, 3, (x^(1 + m)*ArcCot[a*x])/(1 + m) + (a*x^(2 + m)*Hypergeometric2F1[1, (2 + m)/2, (4 + m)/2, (-a^2)*x^2])/(2 + 3*m + m^2)}

{x^5*ArcCot[a*x], x, 3, x/(6*a^5) - x^3/(18*a^3) + x^5/(30*a) + ArcCot[a*x]/(6*a^6) + (1/6)*x^6*ArcCot[a*x]}
{x^4*ArcCot[a*x], x, 4, -(x^2/(10*a^3)) + x^4/(20*a) + (1/5)*x^5*ArcCot[a*x] + Log[1 + a^2*x^2]/(10*a^5)}
{x^3*ArcCot[a*x], x, 2, -(x/(4*a^3)) + x^3/(12*a) - ArcCot[a*x]/(4*a^4) + (1/4)*x^4*ArcCot[a*x]}
{x^2*ArcCot[a*x], x, 3, x^2/(6*a) + (1/3)*x^3*ArcCot[a*x] - Log[1 + a^2*x^2]/(6*a^3)}
{x^1*ArcCot[a*x], x, 1, x/(2*a) + ArcCot[a*x]/(2*a^2) + (1/2)*x^2*ArcCot[a*x]}
{x^0*ArcCot[a*x], x, 2, x*ArcCot[a*x] + Log[1 + a^2*x^2]/(2*a)}
{ArcCot[a*x]/x^1, x, 3, (-(1/2))*I*PolyLog[2, -(I/(a*x))] + (1/2)*I*PolyLog[2, I/(a*x)]}
{ArcCot[a*x]/x^2, x, 1, -(ArcCot[a*x]/x) + a*ArcCoth[1 + 2*a^2*x^2]}
{ArcCot[a*x]/x^3, x, 1, a/(2*x) - (1/2)*a^2*ArcCot[a*x] - ArcCot[a*x]/(2*x^2)}
{ArcCot[a*x]/x^4, x, 2, a/(6*x^2) - ArcCot[a*x]/(3*x^3) - (1/3)*a^3*ArcCoth[1 + 2*a^2*x^2]}
{ArcCot[a*x]/x^5, x, 2, a/(12*x^3) - a^3/(4*x) + (1/4)*a^4*ArcCot[a*x] - ArcCot[a*x]/(4*x^4)}


{x^m*ArcCot[a*x]^2, x, 1, (x^(1 + m)*ArcCot[a*x]^2)/(1 + m) + (2*a*Int[(x^(1 + m)*ArcCot[a*x])/(1 + a^2*x^2), x])/(1 + m)}

{x^5*ArcCot[a*x]^2, x, 14, -((4*x^2)/(45*a^4)) + x^4/(60*a^2) + (x*ArcCot[a*x])/(3*a^5) - (x^3*ArcCot[a*x])/(9*a^3) + (x^5*ArcCot[a*x])/(15*a) + ArcCot[a*x]^2/(6*a^6) + (1/6)*x^6*ArcCot[a*x]^2 + (23*Log[1 + a^2*x^2])/(90*a^6)}
{x^4*ArcCot[a*x]^2, x, 9, -((3*x)/(10*a^4)) + x^3/(30*a^2) - (3*ArcCot[a*x])/(10*a^5) - (x^2*ArcCot[a*x])/(5*a^3) + (x^4*ArcCot[a*x])/(10*a) + (I*ArcCot[a*x]^2)/(5*a^5) + (1/5)*x^5*ArcCot[a*x]^2 - (2*ArcCot[a*x]*Log[(2*I)/(I - a*x)])/(5*a^5) + (I*PolyLog[2, -((I + a*x)/(I - a*x))])/(5*a^5)}
{x^3*ArcCot[a*x]^2, x, 9, x^2/(12*a^2) - (x*ArcCot[a*x])/(2*a^3) + (x^3*ArcCot[a*x])/(6*a) - ArcCot[a*x]^2/(4*a^4) + (1/4)*x^4*ArcCot[a*x]^2 - Log[1 + a^2*x^2]/(3*a^4)}
{x^2*ArcCot[a*x]^2, x, 6, x/(3*a^2) + ArcCot[a*x]/(3*a^3) + (x^2*ArcCot[a*x])/(3*a) - (I*ArcCot[a*x]^2)/(3*a^3) + (1/3)*x^3*ArcCot[a*x]^2 + (2*ArcCot[a*x]*Log[(2*I)/(I - a*x)])/(3*a^3) - (I*PolyLog[2, -((I + a*x)/(I - a*x))])/(3*a^3)}
{x^1*ArcCot[a*x]^2, x, 5, (x*ArcCot[a*x])/a + ArcCot[a*x]^2/(2*a^2) + (1/2)*x^2*ArcCot[a*x]^2 + Log[1 + a^2*x^2]/(2*a^2)}
{x^0*ArcCot[a*x]^2, x, 4, (I*ArcCot[a*x]^2)/a + x*ArcCot[a*x]^2 - (2*ArcCot[a*x]*Log[(2*I)/(I - a*x)])/a + (I*PolyLog[2, -((I + a*x)/(I - a*x))])/a}
{ArcCot[a*x]^2/x^1, x, 7, 2*ArcCot[a*x]^2*ArcCoth[1 - (2*I)/(I - a*x)] - I*ArcCot[a*x]*PolyLog[2, -((I - a*x)/(I + a*x))] + I*ArcCot[a*x]*PolyLog[2, 1 - (2*a*x)/(I + a*x)] - (1/2)*PolyLog[3, -((I - a*x)/(I + a*x))] + (1/2)*PolyLog[3, 1 - (2*a*x)/(I + a*x)]}
{ArcCot[a*x]^2/x^2, x, 4, (-I)*a*ArcCot[a*x]^2 - ArcCot[a*x]^2/x - 2*a*ArcCot[a*x]*Log[(2*a*x)/(I + a*x)] - I*a*PolyLog[2, 1 - (2*a*x)/(I + a*x)]}
{ArcCot[a*x]^2/x^3, x, 4, (a*ArcCot[a*x])/x - (1/2)*a^2*ArcCot[a*x]^2 - ArcCot[a*x]^2/(2*x^2) - a^2*ArcCoth[1 + 2*a^2*x^2]}
{ArcCot[a*x]^2/x^4, x, 6, -(a^2/(3*x)) + (1/3)*a^3*ArcCot[a*x] + (a*ArcCot[a*x])/(3*x^2) + (1/3)*I*a^3*ArcCot[a*x]^2 - ArcCot[a*x]^2/(3*x^3) + (2/3)*a^3*ArcCot[a*x]*Log[(2*a*x)/(I + a*x)] + (1/3)*I*a^3*PolyLog[2, 1 - (2*a*x)/(I + a*x)]}
{ArcCot[a*x]^2/x^5, x, 7, -(a^2/(12*x^2)) + (a*ArcCot[a*x])/(6*x^3) - (a^3*ArcCot[a*x])/(2*x) + (1/4)*a^4*ArcCot[a*x]^2 - ArcCot[a*x]^2/(4*x^4) + (2/3)*a^4*ArcCoth[1 + 2*a^2*x^2]}


{x^m*ArcCot[a*x]^3, x, 1, (x^(1 + m)*ArcCot[a*x]^3)/(1 + m) + (3*a*Int[(x^(1 + m)*ArcCot[a*x]^2)/(1 + a^2*x^2), x])/(1 + m)}

{x^5*ArcCot[a*x]^3, x, 24, -((19*x)/(60*a^5)) + x^3/(60*a^3) - (19*ArcCot[a*x])/(60*a^6) - (4*x^2*ArcCot[a*x])/(15*a^4) + (x^4*ArcCot[a*x])/(20*a^2) + (23*I*ArcCot[a*x]^2)/(30*a^6) + (x*ArcCot[a*x]^2)/(2*a^5) - (x^3*ArcCot[a*x]^2)/(6*a^3) + (x^5*ArcCot[a*x]^2)/(10*a) + ArcCot[a*x]^3/(6*a^6) + (1/6)*x^6*ArcCot[a*x]^3 - (23*ArcCot[a*x]*Log[(2*I)/(I - a*x)])/(15*a^6) + (23*I*PolyLog[2, -((I + a*x)/(I - a*x))])/(30*a^6)}
{x^4*ArcCot[a*x]^3, x, 21, x^2/(20*a^3) - (9*x*ArcCot[a*x])/(10*a^4) + (x^3*ArcCot[a*x])/(10*a^2) - (9*ArcCot[a*x]^2)/(20*a^5) - (3*x^2*ArcCot[a*x]^2)/(10*a^3) + (3*x^4*ArcCot[a*x]^2)/(20*a) + (I*ArcCot[a*x]^3)/(5*a^5) + (1/5)*x^5*ArcCot[a*x]^3 - (3*ArcCot[a*x]^2*Log[(2*I)/(I - a*x)])/(5*a^5) - Log[1 + a^2*x^2]/(2*a^5) + (3*I*ArcCot[a*x]*PolyLog[2, 1 - (2*I)/(I - a*x)])/(5*a^5) - (3*PolyLog[3, 1 - (2*I)/(I - a*x)])/(10*a^5)}
{x^3*ArcCot[a*x]^3, x, 14, x/(4*a^3) + ArcCot[a*x]/(4*a^4) + (x^2*ArcCot[a*x])/(4*a^2) - (I*ArcCot[a*x]^2)/a^4 - (3*x*ArcCot[a*x]^2)/(4*a^3) + (x^3*ArcCot[a*x]^2)/(4*a) - ArcCot[a*x]^3/(4*a^4) + (1/4)*x^4*ArcCot[a*x]^3 + (2*ArcCot[a*x]*Log[(2*I)/(I - a*x)])/a^4 - (I*PolyLog[2, -((I + a*x)/(I - a*x))])/a^4}
{x^2*ArcCot[a*x]^3, x, 11, (x*ArcCot[a*x])/a^2 + ArcCot[a*x]^2/(2*a^3) + (x^2*ArcCot[a*x]^2)/(2*a) - (I*ArcCot[a*x]^3)/(3*a^3) + (1/3)*x^3*ArcCot[a*x]^3 + (ArcCot[a*x]^2*Log[(2*I)/(I - a*x)])/a^3 + Log[1 + a^2*x^2]/(2*a^3) - (I*ArcCot[a*x]*PolyLog[2, 1 - (2*I)/(I - a*x)])/a^3 + PolyLog[3, 1 - (2*I)/(I - a*x)]/(2*a^3)}
{x^1*ArcCot[a*x]^3, x, 7, (3*I*ArcCot[a*x]^2)/(2*a^2) + (3*x*ArcCot[a*x]^2)/(2*a) + ArcCot[a*x]^3/(2*a^2) + (1/2)*x^2*ArcCot[a*x]^3 - (3*ArcCot[a*x]*Log[(2*I)/(I - a*x)])/a^2 + (3*I*PolyLog[2, -((I + a*x)/(I - a*x))])/(2*a^2)}
{x^0*ArcCot[a*x]^3, x, 5, (I*ArcCot[a*x]^3)/a + x*ArcCot[a*x]^3 - (3*ArcCot[a*x]^2*Log[(2*I)/(I - a*x)])/a + (3*I*ArcCot[a*x]*PolyLog[2, 1 - (2*I)/(I - a*x)])/a - (3*PolyLog[3, 1 - (2*I)/(I - a*x)])/(2*a)}
{ArcCot[a*x]^3/x^1, x, 9, 2*ArcCot[a*x]^3*ArcCoth[1 - (2*I)/(I - a*x)] - (3/2)*I*ArcCot[a*x]^2*PolyLog[2, -((I - a*x)/(I + a*x))] + (3/2)*I*ArcCot[a*x]^2*PolyLog[2, 1 - (2*a*x)/(I + a*x)] - (3/2)*ArcCot[a*x]*PolyLog[3, -((I - a*x)/(I + a*x))] + (3/2)*ArcCot[a*x]*PolyLog[3, 1 - (2*a*x)/(I + a*x)] + (3/4)*I*PolyLog[4, -((I - a*x)/(I + a*x))] - (3/4)*I*PolyLog[4, 1 - (2*a*x)/(I + a*x)]}
{ArcCot[a*x]^3/x^2, x, 5, (-I)*a*ArcCot[a*x]^3 - ArcCot[a*x]^3/x - 3*a*ArcCot[a*x]^2*Log[(2*a*x)/(I + a*x)] - 3*I*a*ArcCot[a*x]*PolyLog[2, 1 - (2*a*x)/(I + a*x)] - (3/2)*a*PolyLog[3, 1 - (2*a*x)/(I + a*x)]}
{ArcCot[a*x]^3/x^3, x, 7, (3/2)*I*a^2*ArcCot[a*x]^2 + (3*a*ArcCot[a*x]^2)/(2*x) - (1/2)*a^2*ArcCot[a*x]^3 - ArcCot[a*x]^3/(2*x^2) + 3*a^2*ArcCot[a*x]*Log[(2*a*x)/(I + a*x)] + (3/2)*I*a^2*PolyLog[2, 1 - (2*a*x)/(I + a*x)]}
{ArcCot[a*x]^3/x^4, x, 10, -((a^2*ArcCot[a*x])/x) + (1/2)*a^3*ArcCot[a*x]^2 + (a*ArcCot[a*x]^2)/(2*x^2) + (1/3)*I*a^3*ArcCot[a*x]^3 - ArcCot[a*x]^3/(3*x^3) + a^3*ArcCoth[1 + 2*a^2*x^2] + a^3*ArcCot[a*x]^2*Log[(2*a*x)/(I + a*x)] + I*a^3*ArcCot[a*x]*PolyLog[2, 1 - (2*a*x)/(I + a*x)] + (1/2)*a^3*PolyLog[3, 1 - (2*a*x)/(I + a*x)]}
{ArcCot[a*x]^3/x^5, x, 14, a^3/(4*x) - (1/4)*a^4*ArcCot[a*x] - (a^2*ArcCot[a*x])/(4*x^2) - I*a^4*ArcCot[a*x]^2 + (a*ArcCot[a*x]^2)/(4*x^3) - (3*a^3*ArcCot[a*x]^2)/(4*x) + (1/4)*a^4*ArcCot[a*x]^3 - ArcCot[a*x]^3/(4*x^4) - 2*a^4*ArcCot[a*x]*Log[(2*a*x)/(I + a*x)] - I*a^4*PolyLog[2, 1 - (2*a*x)/(I + a*x)]}


(* ::Subsubsection:: *)
(*n<0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcCot[a x]^n / (c+d x^2)*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{x^4*ArcCot[x]/(1 + x^2), x, 8, x^2/6 - x*ArcCot[x] + (1/3)*x^3*ArcCot[x] - ArcCot[x]^2/2 - (2/3)*Log[1 + x^2]}
{x^3*ArcCot[x]/(1 + x^2), x, 5, x/2 + ArcCot[x]/2 + (1/2)*x^2*ArcCot[x] - (1/2)*I*ArcCot[x]^2 + ArcCot[x]*Log[(2*I)/(I - x)] - (1/2)*I*PolyLog[2, -((I + x)/(I - x))]}
{x^2*ArcCot[x]/(1 + x^2), x, 4, x*ArcCot[x] + ArcCot[x]^2/2 + (1/2)*Log[1 + x^2]}
{x^1*ArcCot[x]/(1 + x^2), x, 3, (1/2)*I*ArcCot[x]^2 - ArcCot[x]*Log[(2*I)/(I - x)] + (1/2)*I*PolyLog[2, -((I + x)/(I - x))]}
{x^0*ArcCot[x]/(1 + x^2), x, 1, (-(1/2))*ArcCot[x]^2}
{ArcCot[x]/(x^1*(1 + x^2)), x, 3, (1/2)*I*ArcCot[x]^2 + ArcCot[x]*Log[(2*x)/(I + x)] + (1/2)*I*PolyLog[2, 1 - (2*x)/(I + x)]}
{ArcCot[x]/(x^2*(1 + x^2)), x, 3, -(ArcCot[x]/x) + ArcCot[x]^2/2 + ArcCoth[1 + 2*x^2]}
{ArcCot[x]/(x^3*(1 + x^2)), x, 5, 1/(2*x) - ArcCot[x]/2 - ArcCot[x]/(2*x^2) - (1/2)*I*ArcCot[x]^2 - ArcCot[x]*Log[(2*x)/(I + x)] - (1/2)*I*PolyLog[2, 1 - (2*x)/(I + x)]}
{ArcCot[x]/(x^4*(1 + x^2)), x, 6, 1/(6*x^2) - ArcCot[x]/(3*x^3) + ArcCot[x]/x - ArcCot[x]^2/2 - (4/3)*ArcCoth[1 + 2*x^2]}


{x^2*ArcCot[c*x]/(1 + x^2), x, 47, x*ArcCot[c*x] - (1/4)*Log[1 - I/(c*x)]*Log[-I + x] + (1/4)*Log[1 + I/(c*x)]*Log[-I + x] + (1/4)*Log[1 - I/(c*x)]*Log[I + x] - (1/4)*Log[1 + I/(c*x)]*Log[I + x] + (1/4)*Log[-I + x]*Log[-((I*(I - c*x))/(1 - c))] - (1/4)*Log[I + x]*Log[-((I*(I - c*x))/(1 + c))] + (1/4)*Log[I + x]*Log[-((I*(I + c*x))/(1 - c))] - (1/4)*Log[-I + x]*Log[-((I*(I + c*x))/(1 + c))] + Log[1 + c^2*x^2]/(2*c) + (1/4)*PolyLog[2, (I*c*(I - x))/(1 - c)] - (1/4)*PolyLog[2, -((I*c*(I - x))/(1 + c))] + (1/4)*PolyLog[2, (I*c*(I + x))/(1 - c)] - (1/4)*PolyLog[2, -((I*c*(I + x))/(1 + c))]}
{x^1*ArcCot[c*x]/(1 + x^2), x, 39, (1/4)*I*Log[1 - I/(c*x)]*Log[I - x] - (1/4)*I*Log[1 + I/(c*x)]*Log[I - x] + (1/4)*I*Log[1 - I/(c*x)]*Log[I + x] - (1/4)*I*Log[1 + I/(c*x)]*Log[I + x] - (1/4)*I*Log[I - x]*Log[-((I*(I - c*x))/(1 - c))] - (1/4)*I*Log[I + x]*Log[-((I*(I - c*x))/(1 + c))] + (1/4)*I*Log[I + x]*Log[-((I*(I + c*x))/(1 - c))] + (1/4)*I*Log[I - x]*Log[-((I*(I + c*x))/(1 + c))] - (1/4)*I*PolyLog[2, (I*c*(I - x))/(1 - c)] + (1/4)*I*PolyLog[2, -((I*c*(I - x))/(1 + c))] + (1/4)*I*PolyLog[2, (I*c*(I + x))/(1 - c)] - (1/4)*I*PolyLog[2, -((I*c*(I + x))/(1 + c))]}
{x^0*ArcCot[c*x]/(1 + x^2), x, 43, (1/4)*Log[1 - I/(c*x)]*Log[-I + x] - (1/4)*Log[1 + I/(c*x)]*Log[-I + x] - (1/4)*Log[1 - I/(c*x)]*Log[I + x] + (1/4)*Log[1 + I/(c*x)]*Log[I + x] - (1/4)*Log[-I + x]*Log[-((I*(I - c*x))/(1 - c))] + (1/4)*Log[I + x]*Log[-((I*(I - c*x))/(1 + c))] - (1/4)*Log[I + x]*Log[-((I*(I + c*x))/(1 - c))] + (1/4)*Log[-I + x]*Log[-((I*(I + c*x))/(1 + c))] - (1/4)*PolyLog[2, (I*c*(I - x))/(1 - c)] + (1/4)*PolyLog[2, -((I*c*(I - x))/(1 + c))] - (1/4)*PolyLog[2, (I*c*(I + x))/(1 - c)] + (1/4)*PolyLog[2, -((I*c*(I + x))/(1 + c))]}
{ArcCot[c*x]/(x^1*(1 + x^2)), x, 44, (-(1/4))*I*Log[1 - I/(c*x)]*Log[I - x] + (1/4)*I*Log[1 + I/(c*x)]*Log[I - x] - (1/4)*I*Log[1 - I/(c*x)]*Log[I + x] + (1/4)*I*Log[1 + I/(c*x)]*Log[I + x] + (1/4)*I*Log[I - x]*Log[-((I*(I - c*x))/(1 - c))] + (1/4)*I*Log[I + x]*Log[-((I*(I - c*x))/(1 + c))] - (1/4)*I*Log[I + x]*Log[-((I*(I + c*x))/(1 - c))] - (1/4)*I*Log[I - x]*Log[-((I*(I + c*x))/(1 + c))] + (1/4)*I*PolyLog[2, (I*c*(I - x))/(1 - c)] - (1/4)*I*PolyLog[2, -((I*c*(I - x))/(1 + c))] - (1/2)*I*PolyLog[2, -(I/(c*x))] + (1/2)*I*PolyLog[2, I/(c*x)] - (1/4)*I*PolyLog[2, (I*c*(I + x))/(1 - c)] + (1/4)*I*PolyLog[2, -((I*c*(I + x))/(1 + c))]}
{ArcCot[c*x]/(x^2*(1 + x^2)), x, 46, -(ArcCot[c*x]/x) + c*ArcCoth[1 + 2*c^2*x^2] - (1/4)*Log[1 - I/(c*x)]*Log[-I + x] + (1/4)*Log[1 + I/(c*x)]*Log[-I + x] + (1/4)*Log[1 - I/(c*x)]*Log[I + x] - (1/4)*Log[1 + I/(c*x)]*Log[I + x] + (1/4)*Log[-I + x]*Log[-((I*(I - c*x))/(1 - c))] - (1/4)*Log[I + x]*Log[-((I*(I - c*x))/(1 + c))] + (1/4)*Log[I + x]*Log[-((I*(I + c*x))/(1 - c))] - (1/4)*Log[-I + x]*Log[-((I*(I + c*x))/(1 + c))] + (1/4)*PolyLog[2, (I*c*(I - x))/(1 - c)] - (1/4)*PolyLog[2, -((I*c*(I - x))/(1 + c))] + (1/4)*PolyLog[2, (I*c*(I + x))/(1 - c)] - (1/4)*PolyLog[2, -((I*c*(I + x))/(1 + c))]}


(* ::Subsubsection::Closed:: *)
(*p<0*)


{1/((1 + x^2)*ArcCot[x]), x, 1, -Log[ArcCot[x]]}


(* ::Subsubsection::Closed:: *)
(*p symbolic*)


{ArcCot[x]^n/(1 + x^2), x, 1, -(ArcCot[x]^(1 + n)/(1 + n))}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcCot[a x] (c+d x^2)^p*)


{x^1*ArcCot[x]/(1 + x^2)^2, x, 3, -(x/(4*(1 + x^2))) - ArcCot[x]/(2*(1 + x^2)) - ArcTan[x]/4}


{x^1*ArcCot[x]/(1 + x^2)^3, x, 4, -(x/(16*(1 + x^2)^2)) - (3*x)/(32*(1 + x^2)) - ArcCot[x]/(4*(1 + x^2)^2) - (3*ArcTan[x])/32}


{ArcCot[x]*(a + b*x^2)^(3/2), x, 0, Int[(a + b*x^2)^(3/2)*ArcCot[x], x]}
{ArcCot[x]*(a + b*x^2)^(1/2), x, 0, Int[Sqrt[a + b*x^2]*ArcCot[x], x]}
{ArcCot[x]/(a + b*x^2)^(1/2), x, 0, Int[ArcCot[x]/Sqrt[a + b*x^2], x]}
{ArcCot[x]/(a + b*x^2)^(3/2), x, 4, (x*ArcCot[x])/(a*Sqrt[a + b*x^2]) - ArcTanh[Sqrt[a + b*x^2]/Sqrt[a - b]]/(a*Sqrt[a - b])}
{ArcCot[x]/(a + b*x^2)^(5/2), x, 5, 1/(3*a*(a - b)*Sqrt[a + b*x^2]) + (x*ArcCot[x])/(3*a*(a + b*x^2)^(3/2)) + (2*x*ArcCot[x])/(3*a^2*Sqrt[a + b*x^2]) - ((3*a - 2*b)*ArcTanh[Sqrt[a + b*x^2]/Sqrt[a - b]])/(3*a^2*(a - b)^(3/2))}
{ArcCot[x]/(a + b*x^2)^(7/2), x, 7, 1/(15*a*(a - b)*(a + b*x^2)^(3/2)) + (7*a - 4*b)/(15*a^2*(a - b)^2*Sqrt[a + b*x^2]) + (x*ArcCot[x])/(5*a*(a + b*x^2)^(5/2)) + (4*x*ArcCot[x])/(15*a^2*(a + b*x^2)^(3/2)) + (8*x*ArcCot[x])/(15*a^3*Sqrt[a + b*x^2]) - ((15*a^2 - 20*a*b + 8*b^2)*ArcTanh[Sqrt[a + b*x^2]/Sqrt[a - b]])/(15*a^3*(a - b)^(5/2))}

{ArcCot[x]*(a + a*x^2)^(1/2), x, 3, (1/2)*Sqrt[a + a*x^2] + (1/2)*x*Sqrt[a + a*x^2]*ArcCot[x] - (I*a*Sqrt[1 + x^2]*ArcCot[x]*ArcTan[Sqrt[1 + I*x]/Sqrt[1 - I*x]])/Sqrt[a + a*x^2] - (I*a*Sqrt[1 + x^2]*PolyLog[2, -((I*Sqrt[1 + I*x])/Sqrt[1 - I*x])])/(2*Sqrt[a + a*x^2]) + (I*a*Sqrt[1 + x^2]*PolyLog[2, (I*Sqrt[1 + I*x])/Sqrt[1 - I*x]])/(2*Sqrt[a + a*x^2])}
{ArcCot[x]/(a + a*x^2)^(1/2), x, 2, -((2*I*Sqrt[1 + x^2]*ArcCot[x]*ArcTan[Sqrt[1 + I*x]/Sqrt[1 - I*x]])/Sqrt[a + a*x^2]) - (I*Sqrt[1 + x^2]*PolyLog[2, -((I*Sqrt[1 + I*x])/Sqrt[1 - I*x])])/Sqrt[a + a*x^2] + (I*Sqrt[1 + x^2]*PolyLog[2, (I*Sqrt[1 + I*x])/Sqrt[1 - I*x]])/Sqrt[a + a*x^2]}
{ArcCot[x]/(a + a*x^2)^(3/2), x, 1, -(1/(a*Sqrt[a + a*x^2])) + (x*ArcCot[x])/(a*Sqrt[a + a*x^2])}
{ArcCot[x]/(a + a*x^2)^(5/2), x, 2, -(1/(9*a*(a + a*x^2)^(3/2))) - 2/(3*a^2*Sqrt[a + a*x^2]) + (x*ArcCot[x])/(3*a*(a + a*x^2)^(3/2)) + (2*x*ArcCot[x])/(3*a^2*Sqrt[a + a*x^2])}
{ArcCot[x]/(a + a*x^2)^(7/2), x, 3, -(1/(25*a*(a + a*x^2)^(5/2))) - 4/(45*a^2*(a + a*x^2)^(3/2)) - 8/(15*a^3*Sqrt[a + a*x^2]) + (x*ArcCot[x])/(5*a*(a + a*x^2)^(5/2)) + (4*x*ArcCot[x])/(15*a^2*(a + a*x^2)^(3/2)) + (8*x*ArcCot[x])/(15*a^3*Sqrt[a + a*x^2])}


{x^0*ArcCot[x]/(1 + x^2)^2, x, 2, -(1/(4*(1 + x^2))) + (x*ArcCot[x])/(2*(1 + x^2)) - ArcCot[x]^2/4}


{ArcCot[x]^2/(1 + x^2)^2, x, 4, -(x/(4*(1 + x^2))) - ArcCot[x]/(2*(1 + x^2)) + (x*ArcCot[x]^2)/(2*(1 + x^2)) - ArcCot[x]^3/6 - ArcTan[x]/4}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcCot[a x^n]*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{x^5*ArcCot[a*x^2], x, 4, x^4/(12*a) + (1/6)*x^6*ArcCot[a*x^2] - Log[1 + a^2*x^4]/(12*a^3)}
{x^4*ArcCot[a*x^2], x, 6, (2*x^3)/(15*a) + (1/5)*x^5*ArcCot[a*x^2] - (1/5)*(-(1/a^2))^(7/4)*a*ArcTan[x/(-(1/a^2))^(1/4)] + (1/5)*(-(1/a^2))^(7/4)*a*ArcTanh[x/(-(1/a^2))^(1/4)]}
{x^3*ArcCot[a*x^2], x, 2, x^2/(4*a) + ArcCot[a*x^2]/(4*a^2) + (1/4)*x^4*ArcCot[a*x^2]}
{x^2*ArcCot[a*x^2], x, 6, (2*x)/(3*a) + (1/3)*x^3*ArcCot[a*x^2] + (1/3)*(-(1/a^2))^(5/4)*a*ArcTan[x/(-(1/a^2))^(1/4)] + (1/3)*(-(1/a^2))^(5/4)*a*ArcTanh[x/(-(1/a^2))^(1/4)]}
{x^1*ArcCot[a*x^2], x, 3, (1/2)*x^2*ArcCot[a*x^2] + Log[1 + a^2*x^4]/(4*a)}
{x^0*ArcCot[a*x^2], x, 5, x*ArcCot[a*x^2] - (-(1/a^2))^(3/4)*a*ArcTan[x/(-(1/a^2))^(1/4)] + (-(1/a^2))^(3/4)*a*ArcTanh[x/(-(1/a^2))^(1/4)]}
{ArcCot[a*x^2]/x^1, x, 3, (-(1/4))*I*PolyLog[2, -(I/(a*x^2))] + (1/4)*I*PolyLog[2, I/(a*x^2)]}
{ArcCot[a*x^2]/x^2, x, 5, -(ArcCot[a*x^2]/x) - (-(1/a^2))^(1/4)*a*ArcTan[x/(-(1/a^2))^(1/4)] - (-(1/a^2))^(1/4)*a*ArcTanh[x/(-(1/a^2))^(1/4)]}
{ArcCot[a*x^2]/x^3, x, 2, -(ArcCot[a*x^2]/(2*x^2)) + (1/2)*a*ArcCoth[1 + 2*a^2*x^4]}
{ArcCot[a*x^2]/x^4, x, 6, (2*a)/(3*x) - ArcCot[a*x^2]/(3*x^3) + (a*ArcTan[x/(-(1/a^2))^(1/4)])/(3*(-(1/a^2))^(1/4)) - (a*ArcTanh[x/(-(1/a^2))^(1/4)])/(3*(-(1/a^2))^(1/4))}
{ArcCot[a*x^2]/x^5, x, 2, a/(4*x^2) - (1/4)*a^2*ArcCot[a*x^2] - ArcCot[a*x^2]/(4*x^4)}


{x^2*ArcCot[Sqrt[x]], x, 6, Sqrt[x]/3 - x^(3/2)/9 + x^(5/2)/15 + (1/3)*x^3*ArcCot[Sqrt[x]] - ArcTan[Sqrt[x]]/3}
{x^1*ArcCot[Sqrt[x]], x, 5, -(Sqrt[x]/2) + x^(3/2)/6 + (1/2)*x^2*ArcCot[Sqrt[x]] + ArcTan[Sqrt[x]]/2}
{x^0*ArcCot[Sqrt[x]], x, 4, Sqrt[x] + x*ArcCot[Sqrt[x]] - ArcTan[Sqrt[x]]}
{ArcCot[Sqrt[x]]/x^1, x, 3, (-I)*PolyLog[2, -(I/Sqrt[x])] + I*PolyLog[2, I/Sqrt[x]]}
{ArcCot[Sqrt[x]]/x^2, x, 4, 1/Sqrt[x] - ArcCot[Sqrt[x]]/x + ArcTan[Sqrt[x]]}
{ArcCot[Sqrt[x]]/x^3, x, 5, 1/(6*x^(3/2)) - 1/(2*Sqrt[x]) - ArcCot[Sqrt[x]]/(2*x^2) - ArcTan[Sqrt[x]]/2}


{x^(3/2)*ArcCot[Sqrt[x]], x, 4, -(x/5) + x^2/10 + (2/5)*x^(5/2)*ArcCot[Sqrt[x]] + (1/5)*Log[1 + x]}
{x^(1/2)*ArcCot[Sqrt[x]], x, 4, x/3 + (2/3)*x^(3/2)*ArcCot[Sqrt[x]] - (1/3)*Log[1 + x]}
{ArcCot[Sqrt[x]]/x^(1/2), x, 3, 2*Sqrt[x]*ArcCot[Sqrt[x]] + Log[1 + x]}
{ArcCot[Sqrt[x]]/x^(3/2), x, 4, -((2*ArcCot[Sqrt[x]])/Sqrt[x]) - Log[x] + Log[1 + x]}
{ArcCot[Sqrt[x]]/x^(5/2), x, 4, 1/(3*x) - (2*ArcCot[Sqrt[x]])/(3*x^(3/2)) + Log[x]/3 - (1/3)*Log[1 + x]}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{ArcCot[1/x], x, 3, x*ArcTan[x] - Log[1 + x^2]/2}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{ArcCot[a*x^n]/x, x, 3, -((I*PolyLog[2, -(I/(x^n*a))])/(2*n)) + (I*PolyLog[2, I/(x^n*a)])/(2*n)}

{ArcCot[a*x^5]/x, x, 3, (-(1/10))*I*PolyLog[2, -(I/(a*x^5))] + (1/10)*I*PolyLog[2, I/(a*x^5)]}


(* ::Section::Closed:: *)
(*Integrands of the form u ArcCot[a+b x]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m ArcCot[a+b x]^n*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{x^3*ArcCot[a + b*x], x, 6, -(((1 - 3*a^2)*x)/(4*b^3)) - (a*x^2)/(4*b^2) + x^3/(12*b) + (1/4)*x^4*ArcCot[a + b*x] + ((1 - 6*a^2 + a^4)*ArcTan[a + b*x])/(4*b^4) + (a*(1 - a^2)*Log[1 + a^2 + 2*a*b*x + b^2*x^2])/(2*b^4)}
{x^2*ArcCot[a + b*x], x, 6, -((2*a*x)/(3*b^2)) + x^2/(6*b) + (1/3)*x^3*ArcCot[a + b*x] + (a*(3 - a^2)*ArcTan[a + b*x])/(3*b^3) - ((1 - 3*a^2)*Log[1 + a^2 + 2*a*b*x + b^2*x^2])/(6*b^3)}
{x^1*ArcCot[a + b*x], x, 5, x/(2*b) + (1/2)*x^2*ArcCot[a + b*x] - ((1 - a^2)*ArcTan[a + b*x])/(2*b^2) - (a*Log[1 + a^2 + 2*a*b*x + b^2*x^2])/(2*b^2)}
{x^0*ArcCot[a + b*x], x, 1, ((a + b*x)*ArcCot[a + b*x])/b + Log[1 + (a + b*x)^2]/(2*b)}
{ArcCot[a + b*x]/x^1, x, 17, (-(1/2))*I*Log[x]*Log[(I - a - b*x)/(I - a)] + (1/2)*I*Log[x]*Log[-((I - a - b*x)/(a + b*x))] + (1/2)*I*Log[x]*Log[(I + a + b*x)/(I + a)] - (1/2)*I*Log[x]*Log[(I + a + b*x)/(a + b*x)] - (1/2)*I*PolyLog[2, (b*x)/(I - a)] + (1/2)*I*PolyLog[2, -((b*x)/(I + a))]}
{ArcCot[a + b*x]/x^2, x, 6, -(ArcCot[a + b*x]/x) + (a*b*ArcTan[a + b*x])/(1 + a^2) - (b*Log[x])/(1 + a^2) + (b*Log[1 + a^2 + 2*a*b*x + b^2*x^2])/(2*(1 + a^2))}
{ArcCot[a + b*x]/x^3, x, 7, b/(2*(1 + a^2)*x) - ArcCot[a + b*x]/(2*x^2) + ((1 - a^2)*b^2*ArcTan[a + b*x])/(2*(1 + a^2)^2) + (a*b^2*Log[x])/(1 + a^2)^2 - (a*b^2*Log[1 + a^2 + 2*a*b*x + b^2*x^2])/(2*(1 + a^2)^2)}
{ArcCot[a + b*x]/x^4, x, 8, b/(6*(1 + a^2)*x^2) - (2*a*b^2)/(3*(1 + a^2)^2*x) - ArcCot[a + b*x]/(3*x^3) - (a*(3 - a^2)*b^3*ArcTan[a + b*x])/(3*(1 + a^2)^3) + ((1 - 3*a^2)*b^3*Log[x])/(3*(1 + a^2)^3) - ((1 - 3*a^2)*b^3*Log[1 + a^2 + 2*a*b*x + b^2*x^2])/(6*(1 + a^2)^3)}


(* ::Subsubsection:: *)
(*p<0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (c+d x)^m ArcCot[a+b x]*)


{(a + b*x)*ArcCot[a + b*x], x, 2, (a + b*x)/(2*b) + ArcCot[a + b*x]/(2*b) + ((a + b*x)^2*ArcCot[a + b*x])/(2*b)}
{(a + b*x)^2*ArcCot[a + b*x], x, 4, (a + b*x)^2/(6*b) + ((a + b*x)^3*ArcCot[a + b*x])/(3*b) - Log[1 + (a + b*x)^2]/(6*b)}
{ArcCot[1 + x]/(2 + 2*x), x, 5, (-(1/4))*I*PolyLog[2, -(I/(1 + x))] + (1/4)*I*PolyLog[2, I/(1 + x)]}
{ArcCot[a + b*x]/(a + b*x), x, 5, -((I*PolyLog[2, -(I/(a + b*x))])/(2*b)) + (I*PolyLog[2, I/(a + b*x)])/(2*b)}
{ArcCot[a + b*x]/(a + b*x)^2, x, 2, -(ArcCot[a + b*x]/(b*(a + b*x))) + ArcCoth[1 + 2*(a + b*x)^2]/b}


{ArcCot[a + b*x]/((a*d)/b + d*x), x, 5, -((I*PolyLog[2, -(I/(a + b*x))])/(2*d)) + (I*PolyLog[2, I/(a + b*x)])/(2*d)}


{ArcCot[d + e*x]/(a + b*x), x, 17, -((I*Log[a + b*x]*Log[(b*(I - d - e*x))/(I*b - b*d + a*e)])/(2*b)) + (I*Log[a + b*x]*Log[-((I - d - e*x)/(d + e*x))])/(2*b) + (I*Log[a + b*x]*Log[(b*(I + d + e*x))/(b*(I + d) - a*e)])/(2*b) - (I*Log[a + b*x]*Log[(I + d + e*x)/(d + e*x)])/(2*b) + (I*PolyLog[2, -((e*(a + b*x))/(b*(I + d) - a*e))])/(2*b) - (I*PolyLog[2, (e*(a + b*x))/(I*b - b*d + a*e)])/(2*b)}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c+d x^n) ArcCot[a+b x]*)


{ArcCot[a + b*x]/(c + d*x^3), x, 47, -((I*Log[(d^(1/3)*(I - a - b*x))/(b*c^(1/3) + (I - a)*d^(1/3))]*Log[-c^(1/3) - d^(1/3)*x])/(6*c^(2/3)*d^(1/3))) + (I*Log[-((I - a - b*x)/(a + b*x))]*Log[-c^(1/3) - d^(1/3)*x])/(6*c^(2/3)*d^(1/3)) + (I*Log[-((d^(1/3)*(I + a + b*x))/(b*c^(1/3) - (I + a)*d^(1/3)))]*Log[-c^(1/3) - d^(1/3)*x])/(6*c^(2/3)*d^(1/3)) - (I*Log[(I + a + b*x)/(a + b*x)]*Log[-c^(1/3) - d^(1/3)*x])/(6*c^(2/3)*d^(1/3)) + ((-1)^(5/6)*Log[-((d^(1/3)*(I - a - b*x))/((-1)^(1/3)*b*c^(1/3) - (I - a)*d^(1/3)))]*Log[(-1)^(1/3)*c^(1/3) - d^(1/3)*x])/(6*c^(2/3)*d^(1/3)) - ((-1)^(5/6)*Log[-((I - a - b*x)/(a + b*x))]*Log[(-1)^(1/3)*c^(1/3) - d^(1/3)*x])/(6*c^(2/3)*d^(1/3)) - ((-1)^(5/6)*Log[(d^(1/3)*(I + a + b*x))/((-1)^(1/3)*b*c^(1/3) + (I + a)*d^(1/3))]*Log[(-1)^(1/3)*c^(1/3) - d^(1/3)*x])/(6*c^(2/3)*d^(1/3)) + ((-1)^(5/6)*Log[(I + a + b*x)/(a + b*x)]*Log[(-1)^(1/3)*c^(1/3) - d^(1/3)*x])/(6*c^(2/3)*d^(1/3)) + ((-1)^(1/6)*Log[(d^(1/3)*(I - a - b*x))/((-1)^(2/3)*b*c^(1/3) + (I - a)*d^(1/3))]*Log[(-(-1)^(2/3))*c^(1/3) - d^(1/3)*x])/(6*c^(2/3)*d^(1/3)) - ((-1)^(1/6)*Log[-((I - a - b*x)/(a + b*x))]*Log[(-(-1)^(2/3))*c^(1/3) - d^(1/3)*x])/(6*c^(2/3)*d^(1/3)) - ((-1)^(1/6)*Log[-((d^(1/3)*(I + a + b*x))/((-1)^(2/3)*b*c^(1/3) - (I + a)*d^(1/3)))]*Log[(-(-1)^(2/3))*c^(1/3) - d^(1/3)*x])/(6*c^(2/3)*d^(1/3)) + ((-1)^(1/6)*Log[(I + a + b*x)/(a + b*x)]*Log[(-(-1)^(2/3))*c^(1/3) - d^(1/3)*x])/(6*c^(2/3)*d^(1/3)) - (I*PolyLog[2, (b*(c^(1/3) + d^(1/3)*x))/(b*c^(1/3) + (I - a)*d^(1/3))])/(6*c^(2/3)*d^(1/3)) + (I*PolyLog[2, (b*(c^(1/3) + d^(1/3)*x))/(b*c^(1/3) - (I + a)*d^(1/3))])/(6*c^(2/3)*d^(1/3)) + ((-1)^(1/6)*PolyLog[2, (b*((-1)^(2/3)*c^(1/3) + d^(1/3)*x))/((-1)^(2/3)*b*c^(1/3) + (I - a)*d^(1/3))])/(6*c^(2/3)*d^(1/3)) - ((-1)^(1/6)*PolyLog[2, (b*((-1)^(2/3)*c^(1/3) + d^(1/3)*x))/((-1)^(2/3)*b*c^(1/3) - (I + a)*d^(1/3))])/(6*c^(2/3)*d^(1/3)) + ((-1)^(5/6)*PolyLog[2, ((-1)^(1/3)*b*(c^(1/3) + (-1)^(2/3)*d^(1/3)*x))/((-1)^(1/3)*b*c^(1/3) - (I - a)*d^(1/3))])/(6*c^(2/3)*d^(1/3)) - ((-1)^(5/6)*PolyLog[2, ((-1)^(1/3)*b*(c^(1/3) + (-1)^(2/3)*d^(1/3)*x))/((-1)^(1/3)*b*c^(1/3) + (I + a)*d^(1/3))])/(6*c^(2/3)*d^(1/3))}
{ArcCot[a + b*x]/(c + d*x^2), x, 33, -((I*Log[-((Sqrt[d]*(I - a - b*x))/(b*Sqrt[-c] - (I - a)*Sqrt[d]))]*Log[Sqrt[-c] - Sqrt[d]*x])/(4*Sqrt[-c]*Sqrt[d])) + (I*Log[-((I - a - b*x)/(a + b*x))]*Log[Sqrt[-c] - Sqrt[d]*x])/(4*Sqrt[-c]*Sqrt[d]) + (I*Log[(Sqrt[d]*(I + a + b*x))/(b*Sqrt[-c] + (I + a)*Sqrt[d])]*Log[Sqrt[-c] - Sqrt[d]*x])/(4*Sqrt[-c]*Sqrt[d]) - (I*Log[(I + a + b*x)/(a + b*x)]*Log[Sqrt[-c] - Sqrt[d]*x])/(4*Sqrt[-c]*Sqrt[d]) + (I*Log[(Sqrt[d]*(I - a - b*x))/(b*Sqrt[-c] + (I - a)*Sqrt[d])]*Log[Sqrt[-c] + Sqrt[d]*x])/(4*Sqrt[-c]*Sqrt[d]) - (I*Log[-((I - a - b*x)/(a + b*x))]*Log[Sqrt[-c] + Sqrt[d]*x])/(4*Sqrt[-c]*Sqrt[d]) - (I*Log[-((Sqrt[d]*(I + a + b*x))/(b*Sqrt[-c] - (I + a)*Sqrt[d]))]*Log[Sqrt[-c] + Sqrt[d]*x])/(4*Sqrt[-c]*Sqrt[d]) + (I*Log[(I + a + b*x)/(a + b*x)]*Log[Sqrt[-c] + Sqrt[d]*x])/(4*Sqrt[-c]*Sqrt[d]) - (I*PolyLog[2, (b*(Sqrt[-c] - Sqrt[d]*x))/(b*Sqrt[-c] - (I - a)*Sqrt[d])])/(4*Sqrt[-c]*Sqrt[d]) + (I*PolyLog[2, (b*(Sqrt[-c] - Sqrt[d]*x))/(b*Sqrt[-c] + (I + a)*Sqrt[d])])/(4*Sqrt[-c]*Sqrt[d]) + (I*PolyLog[2, (b*(Sqrt[-c] + Sqrt[d]*x))/(b*Sqrt[-c] + (I - a)*Sqrt[d])])/(4*Sqrt[-c]*Sqrt[d]) - (I*PolyLog[2, (b*(Sqrt[-c] + Sqrt[d]*x))/(b*Sqrt[-c] - (I + a)*Sqrt[d])])/(4*Sqrt[-c]*Sqrt[d])}
{ArcCot[a + b*x]/(c + d*x), x, 17, -((I*Log[(d*(I - a - b*x))/(b*c + I*d - a*d)]*Log[c + d*x])/(2*d)) + (I*Log[-((I - a - b*x)/(a + b*x))]*Log[c + d*x])/(2*d) + (I*Log[-((d*(I + a + b*x))/(b*c - (I + a)*d))]*Log[c + d*x])/(2*d) - (I*Log[(I + a + b*x)/(a + b*x)]*Log[c + d*x])/(2*d) - (I*PolyLog[2, (b*(c + d*x))/(b*c + I*d - a*d)])/(2*d) + (I*PolyLog[2, (b*(c + d*x))/(b*c - (I + a)*d)])/(2*d)}
{ArcCot[a + b*x]/(c + d/x), x, 25, -((I*(I - a - b*x)*Log[-((I - a - b*x)/(a + b*x))])/(2*b*c)) + Log[a + b*x]/(b*c) - (I*(I + a + b*x)*Log[(I + a + b*x)/(a + b*x)])/(2*b*c) + (I*d*Log[(c*(I - a - b*x))/(I*c - a*c + b*d)]*Log[d + c*x])/(2*c^2) - (I*d*Log[-((I - a - b*x)/(a + b*x))]*Log[d + c*x])/(2*c^2) - (I*d*Log[(c*(I + a + b*x))/((I + a)*c - b*d)]*Log[d + c*x])/(2*c^2) + (I*d*Log[(I + a + b*x)/(a + b*x)]*Log[d + c*x])/(2*c^2) - (I*d*PolyLog[2, -((b*(d + c*x))/((I + a)*c - b*d))])/(2*c^2) + (I*d*PolyLog[2, (b*(d + c*x))/(I*c - a*c + b*d)])/(2*c^2)}
{ArcCot[a + b*x]/(c + d/x^2), x, 41, -((I*(I - a - b*x)*Log[-((I - a - b*x)/(a + b*x))])/(2*b*c)) + Log[a + b*x]/(b*c) - (I*(I + a + b*x)*Log[(I + a + b*x)/(a + b*x)])/(2*b*c) - (I*Sqrt[-d]*Log[(Sqrt[c]*(I - a - b*x))/((I - a)*Sqrt[c] - b*Sqrt[-d])]*Log[Sqrt[-d] - Sqrt[c]*x])/(4*c^(3/2)) + (I*Sqrt[-d]*Log[-((I - a - b*x)/(a + b*x))]*Log[Sqrt[-d] - Sqrt[c]*x])/(4*c^(3/2)) + (I*Sqrt[-d]*Log[(Sqrt[c]*(I + a + b*x))/((I + a)*Sqrt[c] + b*Sqrt[-d])]*Log[Sqrt[-d] - Sqrt[c]*x])/(4*c^(3/2)) - (I*Sqrt[-d]*Log[(I + a + b*x)/(a + b*x)]*Log[Sqrt[-d] - Sqrt[c]*x])/(4*c^(3/2)) + (I*Sqrt[-d]*Log[(Sqrt[c]*(I - a - b*x))/((I - a)*Sqrt[c] + b*Sqrt[-d])]*Log[Sqrt[-d] + Sqrt[c]*x])/(4*c^(3/2)) - (I*Sqrt[-d]*Log[-((I - a - b*x)/(a + b*x))]*Log[Sqrt[-d] + Sqrt[c]*x])/(4*c^(3/2)) - (I*Sqrt[-d]*Log[(Sqrt[c]*(I + a + b*x))/((I + a)*Sqrt[c] - b*Sqrt[-d])]*Log[Sqrt[-d] + Sqrt[c]*x])/(4*c^(3/2)) + (I*Sqrt[-d]*Log[(I + a + b*x)/(a + b*x)]*Log[Sqrt[-d] + Sqrt[c]*x])/(4*c^(3/2)) - (I*Sqrt[-d]*PolyLog[2, -((b*(Sqrt[-d] - Sqrt[c]*x))/((I - a)*Sqrt[c] - b*Sqrt[-d]))])/(4*c^(3/2)) + (I*Sqrt[-d]*PolyLog[2, (b*(Sqrt[-d] - Sqrt[c]*x))/((I + a)*Sqrt[c] + b*Sqrt[-d])])/(4*c^(3/2)) - (I*Sqrt[-d]*PolyLog[2, -((b*(Sqrt[-d] + Sqrt[c]*x))/((I + a)*Sqrt[c] - b*Sqrt[-d]))])/(4*c^(3/2)) + (I*Sqrt[-d]*PolyLog[2, (b*(Sqrt[-d] + Sqrt[c]*x))/((I - a)*Sqrt[c] + b*Sqrt[-d])])/(4*c^(3/2))}
{ArcCot[a + b*x]/(c + d/x^3), x, 55, -((I*(I - a - b*x)*Log[-((I - a - b*x)/(a + b*x))])/(2*b*c)) + Log[a + b*x]/(b*c) - (I*(I + a + b*x)*Log[(I + a + b*x)/(a + b*x)])/(2*b*c) + (I*d^(1/3)*Log[(c^(1/3)*(I - a - b*x))/((I - a)*c^(1/3) + b*d^(1/3))]*Log[-d^(1/3) - c^(1/3)*x])/(6*c^(4/3)) - (I*d^(1/3)*Log[-((I - a - b*x)/(a + b*x))]*Log[-d^(1/3) - c^(1/3)*x])/(6*c^(4/3)) - (I*d^(1/3)*Log[(c^(1/3)*(I + a + b*x))/((I + a)*c^(1/3) - b*d^(1/3))]*Log[-d^(1/3) - c^(1/3)*x])/(6*c^(4/3)) + (I*d^(1/3)*Log[(I + a + b*x)/(a + b*x)]*Log[-d^(1/3) - c^(1/3)*x])/(6*c^(4/3)) - ((-1)^(5/6)*d^(1/3)*Log[(c^(1/3)*(I - a - b*x))/((I - a)*c^(1/3) - (-1)^(1/3)*b*d^(1/3))]*Log[(-1)^(1/3)*d^(1/3) - c^(1/3)*x])/(6*c^(4/3)) + ((-1)^(5/6)*d^(1/3)*Log[-((I - a - b*x)/(a + b*x))]*Log[(-1)^(1/3)*d^(1/3) - c^(1/3)*x])/(6*c^(4/3)) + ((-1)^(5/6)*d^(1/3)*Log[(c^(1/3)*(I + a + b*x))/((I + a)*c^(1/3) + (-1)^(1/3)*b*d^(1/3))]*Log[(-1)^(1/3)*d^(1/3) - c^(1/3)*x])/(6*c^(4/3)) - ((-1)^(5/6)*d^(1/3)*Log[(I + a + b*x)/(a + b*x)]*Log[(-1)^(1/3)*d^(1/3) - c^(1/3)*x])/(6*c^(4/3)) - ((-1)^(1/6)*d^(1/3)*Log[(c^(1/3)*(I - a - b*x))/((I - a)*c^(1/3) + (-1)^(2/3)*b*d^(1/3))]*Log[(-(-1)^(2/3))*d^(1/3) - c^(1/3)*x])/(6*c^(4/3)) + ((-1)^(1/6)*d^(1/3)*Log[-((I - a - b*x)/(a + b*x))]*Log[(-(-1)^(2/3))*d^(1/3) - c^(1/3)*x])/(6*c^(4/3)) + ((-1)^(1/6)*d^(1/3)*Log[(c^(1/3)*(I + a + b*x))/((I + a)*c^(1/3) - (-1)^(2/3)*b*d^(1/3))]*Log[(-(-1)^(2/3))*d^(1/3) - c^(1/3)*x])/(6*c^(4/3)) - ((-1)^(1/6)*d^(1/3)*Log[(I + a + b*x)/(a + b*x)]*Log[(-(-1)^(2/3))*d^(1/3) - c^(1/3)*x])/(6*c^(4/3)) - (I*d^(1/3)*PolyLog[2, -((b*(d^(1/3) + c^(1/3)*x))/((I + a)*c^(1/3) - b*d^(1/3)))])/(6*c^(4/3)) + (I*d^(1/3)*PolyLog[2, (b*(d^(1/3) + c^(1/3)*x))/((I - a)*c^(1/3) + b*d^(1/3))])/(6*c^(4/3)) + ((-1)^(1/6)*d^(1/3)*PolyLog[2, -((b*((-1)^(2/3)*d^(1/3) + c^(1/3)*x))/((I + a)*c^(1/3) - (-1)^(2/3)*b*d^(1/3)))])/(6*c^(4/3)) - ((-1)^(1/6)*d^(1/3)*PolyLog[2, (b*((-1)^(2/3)*d^(1/3) + c^(1/3)*x))/((I - a)*c^(1/3) + (-1)^(2/3)*b*d^(1/3))])/(6*c^(4/3)) - ((-1)^(5/6)*d^(1/3)*PolyLog[2, -(((-1)^(1/3)*b*(d^(1/3) + (-1)^(2/3)*c^(1/3)*x))/((I - a)*c^(1/3) - (-1)^(1/3)*b*d^(1/3)))])/(6*c^(4/3)) + ((-1)^(5/6)*d^(1/3)*PolyLog[2, ((-1)^(1/3)*b*(d^(1/3) + (-1)^(2/3)*c^(1/3)*x))/((I + a)*c^(1/3) + (-1)^(1/3)*b*d^(1/3))])/(6*c^(4/3))}


(* {ArcCot[a + b*x]/(a + b*x^(3/2)), x, 131, ((-I/6)*(1 - Sqrt[-a]/Sqrt[-I - a])*Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-I - a] - Sqrt[b]*Sqrt[x])/(Sqrt[-I - a] + a^(1/3)*b^(1/6))])/(a^(1/3)*b^(2/3)) - ((I/6)*(1 + Sqrt[-a]/Sqrt[-I - a])*Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-I - a] - Sqrt[b]*Sqrt[x])/(Sqrt[-I - a] + a^(1/3)*b^(1/6))])/(a^(1/3)*b^(2/3)) + ((-1)^(1/6)*(1 - Sqrt[-a]/Sqrt[-I - a])*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-I - a] - Sqrt[b]*Sqrt[x])/(Sqrt[-I - a] - (-1)^(1/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) + ((-1)^(1/6)*(1 + Sqrt[-a]/Sqrt[-I - a])*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-I - a] - Sqrt[b]*Sqrt[x])/(Sqrt[-I - a] - (-1)^(1/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) + ((-1)^(5/6)*(1 - Sqrt[-a]/Sqrt[-I - a])*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-I - a] - Sqrt[b]*Sqrt[x])/(Sqrt[-I - a] + (-1)^(2/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) + ((-1)^(5/6)*(1 + Sqrt[-a]/Sqrt[-I - a])*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-I - a] - Sqrt[b]*Sqrt[x])/(Sqrt[-I - a] + (-1)^(2/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) + ((I/6)*(1 - Sqrt[-a]/Sqrt[I - a])*Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[I - a] - Sqrt[b]*Sqrt[x])/(Sqrt[I - a] + a^(1/3)*b^(1/6))])/(a^(1/3)*b^(2/3)) + ((I/6)*(1 + Sqrt[-a]/Sqrt[I - a])*Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[I - a] - Sqrt[b]*Sqrt[x])/(Sqrt[I - a] + a^(1/3)*b^(1/6))])/(a^(1/3)*b^(2/3)) - ((-1)^(1/6)*(1 - Sqrt[-a]/Sqrt[I - a])*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[I - a] - Sqrt[b]*Sqrt[x])/(Sqrt[I - a] - (-1)^(1/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) - ((-1)^(1/6)*(1 + Sqrt[-a]/Sqrt[I - a])*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[I - a] - Sqrt[b]*Sqrt[x])/(Sqrt[I - a] - (-1)^(1/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) - ((-1)^(5/6)*(1 - Sqrt[-a]/Sqrt[I - a])*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[I - a] - Sqrt[b]*Sqrt[x])/(Sqrt[I - a] + (-1)^(2/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) - ((-1)^(5/6)*(1 + Sqrt[-a]/Sqrt[I - a])*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[I - a] - Sqrt[b]*Sqrt[x])/(Sqrt[I - a] + (-1)^(2/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) - ((I/6)*(1 - Sqrt[-a]/Sqrt[-I - a])*Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-I - a] + Sqrt[b]*Sqrt[x])/(Sqrt[-I - a] - a^(1/3)*b^(1/6))])/(a^(1/3)*b^(2/3)) - ((I/6)*(1 + Sqrt[-a]/Sqrt[-I - a])*Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-I - a] + Sqrt[b]*Sqrt[x])/(Sqrt[-I - a] - a^(1/3)*b^(1/6))])/(a^(1/3)*b^(2/3)) + ((-1)^(1/6)*(1 - Sqrt[-a]/Sqrt[-I - a])*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-I - a] + Sqrt[b]*Sqrt[x])/(Sqrt[-I - a] + (-1)^(1/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) + ((-1)^(1/6)*(1 + Sqrt[-a]/Sqrt[-I - a])*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-I - a] + Sqrt[b]*Sqrt[x])/(Sqrt[-I - a] + (-1)^(1/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) + ((-1)^(5/6)*(1 - Sqrt[-a]/Sqrt[-I - a])*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-I - a] + Sqrt[b]*Sqrt[x])/(Sqrt[-I - a] - (-1)^(2/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) + ((-1)^(5/6)*(1 + Sqrt[-a]/Sqrt[-I - a])*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[-I - a] + Sqrt[b]*Sqrt[x])/(Sqrt[-I - a] - (-1)^(2/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) + ((I/6)*(1 - Sqrt[-a]/Sqrt[I - a])*Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[I - a] + Sqrt[b]*Sqrt[x])/(Sqrt[I - a] - a^(1/3)*b^(1/6))])/(a^(1/3)*b^(2/3)) + ((I/6)*(1 + Sqrt[-a]/Sqrt[I - a])*Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[I - a] + Sqrt[b]*Sqrt[x])/(Sqrt[I - a] - a^(1/3)*b^(1/6))])/(a^(1/3)*b^(2/3)) - ((-1)^(1/6)*(1 - Sqrt[-a]/Sqrt[I - a])*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[I - a] + Sqrt[b]*Sqrt[x])/(Sqrt[I - a] + (-1)^(1/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) - ((-1)^(1/6)*(1 + Sqrt[-a]/Sqrt[I - a])*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[I - a] + Sqrt[b]*Sqrt[x])/(Sqrt[I - a] + (-1)^(1/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) - ((-1)^(5/6)*(1 - Sqrt[-a]/Sqrt[I - a])*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[I - a] + Sqrt[b]*Sqrt[x])/(Sqrt[I - a] - (-1)^(2/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) - ((-1)^(5/6)*(1 + Sqrt[-a]/Sqrt[I - a])*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[(Sqrt[I - a] + Sqrt[b]*Sqrt[x])/(Sqrt[I - a] - (-1)^(2/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) - ((I/3)*Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[1 - I/(a + b*x)])/(a^(1/3)*b^(2/3)) + ((-1)^(1/6)*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[1 - I/(a + b*x)])/(3*a^(1/3)*b^(2/3)) + ((-1)^(5/6)*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[1 - I/(a + b*x)])/(3*a^(1/3)*b^(2/3)) + ((I/3)*Log[-a^(1/3) - b^(1/3)*Sqrt[x]]*Log[1 + I/(a + b*x)])/(a^(1/3)*b^(2/3)) - ((-1)^(1/6)*Log[(-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]]*Log[1 + I/(a + b*x)])/(3*a^(1/3)*b^(2/3)) - ((-1)^(5/6)*Log[-((-1)^(2/3)*a^(1/3)) - b^(1/3)*Sqrt[x]]*Log[1 + I/(a + b*x)])/(3*a^(1/3)*b^(2/3)) + ((-1)^(1/6)*(1 - Sqrt[-a]/Sqrt[-I - a])*PolyLog[2, -((b^(1/6)*((-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]))/(Sqrt[-I - a] - (-1)^(1/3)*a^(1/3)*b^(1/6)))])/(6*a^(1/3)*b^(2/3)) + ((-1)^(1/6)*(1 + Sqrt[-a]/Sqrt[-I - a])*PolyLog[2, -((b^(1/6)*((-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]))/(Sqrt[-I - a] - (-1)^(1/3)*a^(1/3)*b^(1/6)))])/(6*a^(1/3)*b^(2/3)) - ((-1)^(1/6)*(1 - Sqrt[-a]/Sqrt[I - a])*PolyLog[2, -((b^(1/6)*((-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]))/(Sqrt[I - a] - (-1)^(1/3)*a^(1/3)*b^(1/6)))])/(6*a^(1/3)*b^(2/3)) - ((-1)^(1/6)*(1 + Sqrt[-a]/Sqrt[I - a])*PolyLog[2, -((b^(1/6)*((-1)^(1/3)*a^(1/3) - b^(1/3)*Sqrt[x]))/(Sqrt[I - a] - (-1)^(1/3)*a^(1/3)*b^(1/6)))])/(6*a^(1/3)*b^(2/3)) - ((I/6)*(1 - Sqrt[-a]/Sqrt[-I - a])*PolyLog[2, -((b^(1/6)*(a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-I - a] - a^(1/3)*b^(1/6)))])/(a^(1/3)*b^(2/3)) - ((I/6)*(1 + Sqrt[-a]/Sqrt[-I - a])*PolyLog[2, -((b^(1/6)*(a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-I - a] - a^(1/3)*b^(1/6)))])/(a^(1/3)*b^(2/3)) + ((I/6)*(1 - Sqrt[-a]/Sqrt[I - a])*PolyLog[2, -((b^(1/6)*(a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[I - a] - a^(1/3)*b^(1/6)))])/(a^(1/3)*b^(2/3)) + ((I/6)*(1 + Sqrt[-a]/Sqrt[I - a])*PolyLog[2, -((b^(1/6)*(a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[I - a] - a^(1/3)*b^(1/6)))])/(a^(1/3)*b^(2/3)) - ((I/6)*(1 - Sqrt[-a]/Sqrt[-I - a])*PolyLog[2, (b^(1/6)*(a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-I - a] + a^(1/3)*b^(1/6))])/(a^(1/3)*b^(2/3)) - ((I/6)*(1 + Sqrt[-a]/Sqrt[-I - a])*PolyLog[2, (b^(1/6)*(a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-I - a] + a^(1/3)*b^(1/6))])/(a^(1/3)*b^(2/3)) + ((I/6)*(1 - Sqrt[-a]/Sqrt[I - a])*PolyLog[2, (b^(1/6)*(a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[I - a] + a^(1/3)*b^(1/6))])/(a^(1/3)*b^(2/3)) + ((I/6)*(1 + Sqrt[-a]/Sqrt[I - a])*PolyLog[2, (b^(1/6)*(a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[I - a] + a^(1/3)*b^(1/6))])/(a^(1/3)*b^(2/3)) + ((-1)^(5/6)*(1 - Sqrt[-a]/Sqrt[-I - a])*PolyLog[2, -((b^(1/6)*((-1)^(2/3)*a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-I - a] - (-1)^(2/3)*a^(1/3)*b^(1/6)))])/(6*a^(1/3)*b^(2/3)) + ((-1)^(5/6)*(1 + Sqrt[-a]/Sqrt[-I - a])*PolyLog[2, -((b^(1/6)*((-1)^(2/3)*a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-I - a] - (-1)^(2/3)*a^(1/3)*b^(1/6)))])/(6*a^(1/3)*b^(2/3)) - ((-1)^(5/6)*(1 - Sqrt[-a]/Sqrt[I - a])*PolyLog[2, -((b^(1/6)*((-1)^(2/3)*a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[I - a] - (-1)^(2/3)*a^(1/3)*b^(1/6)))])/(6*a^(1/3)*b^(2/3)) - ((-1)^(5/6)*(1 + Sqrt[-a]/Sqrt[I - a])*PolyLog[2, -((b^(1/6)*((-1)^(2/3)*a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[I - a] - (-1)^(2/3)*a^(1/3)*b^(1/6)))])/(6*a^(1/3)*b^(2/3)) + ((-1)^(5/6)*(1 - Sqrt[-a]/Sqrt[-I - a])*PolyLog[2, (b^(1/6)*((-1)^(2/3)*a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-I - a] + (-1)^(2/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) + ((-1)^(5/6)*(1 + Sqrt[-a]/Sqrt[-I - a])*PolyLog[2, (b^(1/6)*((-1)^(2/3)*a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[-I - a] + (-1)^(2/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) - ((-1)^(5/6)*(1 - Sqrt[-a]/Sqrt[I - a])*PolyLog[2, (b^(1/6)*((-1)^(2/3)*a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[I - a] + (-1)^(2/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) - ((-1)^(5/6)*(1 + Sqrt[-a]/Sqrt[I - a])*PolyLog[2, (b^(1/6)*((-1)^(2/3)*a^(1/3) + b^(1/3)*Sqrt[x]))/(Sqrt[I - a] + (-1)^(2/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) + ((-1)^(1/6)*(1 - Sqrt[-a]/Sqrt[-I - a])*PolyLog[2, ((-1)^(1/3)*b^(1/6)*(a^(1/3) + (-1)^(2/3)*b^(1/3)*Sqrt[x]))/(Sqrt[-I - a] + (-1)^(1/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) + ((-1)^(1/6)*(1 + Sqrt[-a]/Sqrt[-I - a])*PolyLog[2, ((-1)^(1/3)*b^(1/6)*(a^(1/3) + (-1)^(2/3)*b^(1/3)*Sqrt[x]))/(Sqrt[-I - a] + (-1)^(1/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) - ((-1)^(1/6)*(1 - Sqrt[-a]/Sqrt[I - a])*PolyLog[2, ((-1)^(1/3)*b^(1/6)*(a^(1/3) + (-1)^(2/3)*b^(1/3)*Sqrt[x]))/(Sqrt[I - a] + (-1)^(1/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3)) - ((-1)^(1/6)*(1 + Sqrt[-a]/Sqrt[I - a])*PolyLog[2, ((-1)^(1/3)*b^(1/6)*(a^(1/3) + (-1)^(2/3)*b^(1/3)*Sqrt[x]))/(Sqrt[I - a] + (-1)^(1/3)*a^(1/3)*b^(1/6))])/(6*a^(1/3)*b^(2/3))} *)
{ArcCot[a + b*x]/(c + d*Sqrt[x]), x, 61, -((2*I*Sqrt[I + a]*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[I + a]])/(Sqrt[b]*d)) + (2*I*Sqrt[I - a]*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[I - a]])/(Sqrt[b]*d) - (I*(1 - Sqrt[-a]/Sqrt[-I - a])*c*Log[(d*(Sqrt[-I - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[b]*c + Sqrt[-I - a]*d)]*Log[c + d*Sqrt[x]])/(2*d^2) - (I*(1 + Sqrt[-a]/Sqrt[-I - a])*c*Log[(d*(Sqrt[-I - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[b]*c + Sqrt[-I - a]*d)]*Log[c + d*Sqrt[x]])/(2*d^2) + (I*(1 - Sqrt[-a]/Sqrt[I - a])*c*Log[(d*(Sqrt[I - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[b]*c + Sqrt[I - a]*d)]*Log[c + d*Sqrt[x]])/(2*d^2) + (I*(1 + Sqrt[-a]/Sqrt[I - a])*c*Log[(d*(Sqrt[I - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[b]*c + Sqrt[I - a]*d)]*Log[c + d*Sqrt[x]])/(2*d^2) - (I*(1 - Sqrt[-a]/Sqrt[-I - a])*c*Log[-((d*(Sqrt[-I - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[b]*c - Sqrt[-I - a]*d))]*Log[c + d*Sqrt[x]])/(2*d^2) - (I*(1 + Sqrt[-a]/Sqrt[-I - a])*c*Log[-((d*(Sqrt[-I - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[b]*c - Sqrt[-I - a]*d))]*Log[c + d*Sqrt[x]])/(2*d^2) + (I*(1 - Sqrt[-a]/Sqrt[I - a])*c*Log[-((d*(Sqrt[I - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[b]*c - Sqrt[I - a]*d))]*Log[c + d*Sqrt[x]])/(2*d^2) + (I*(1 + Sqrt[-a]/Sqrt[I - a])*c*Log[-((d*(Sqrt[I - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[b]*c - Sqrt[I - a]*d))]*Log[c + d*Sqrt[x]])/(2*d^2) + (I*Sqrt[x]*Log[-((I - a - b*x)/(a + b*x))])/d - (I*c*Log[c + d*Sqrt[x]]*Log[-((I - a - b*x)/(a + b*x))])/d^2 - (I*Sqrt[x]*Log[(I + a + b*x)/(a + b*x)])/d + (I*c*Log[c + d*Sqrt[x]]*Log[(I + a + b*x)/(a + b*x)])/d^2 - (I*(1 - Sqrt[-a]/Sqrt[-I - a])*c*PolyLog[2, (Sqrt[b]*(c + d*Sqrt[x]))/(Sqrt[b]*c - Sqrt[-I - a]*d)])/(2*d^2) - (I*(1 + Sqrt[-a]/Sqrt[-I - a])*c*PolyLog[2, (Sqrt[b]*(c + d*Sqrt[x]))/(Sqrt[b]*c - Sqrt[-I - a]*d)])/(2*d^2) - (I*(1 - Sqrt[-a]/Sqrt[-I - a])*c*PolyLog[2, (Sqrt[b]*(c + d*Sqrt[x]))/(Sqrt[b]*c + Sqrt[-I - a]*d)])/(2*d^2) - (I*(1 + Sqrt[-a]/Sqrt[-I - a])*c*PolyLog[2, (Sqrt[b]*(c + d*Sqrt[x]))/(Sqrt[b]*c + Sqrt[-I - a]*d)])/(2*d^2) + (I*(1 - Sqrt[-a]/Sqrt[I - a])*c*PolyLog[2, (Sqrt[b]*(c + d*Sqrt[x]))/(Sqrt[b]*c - Sqrt[I - a]*d)])/(2*d^2) + (I*(1 + Sqrt[-a]/Sqrt[I - a])*c*PolyLog[2, (Sqrt[b]*(c + d*Sqrt[x]))/(Sqrt[b]*c - Sqrt[I - a]*d)])/(2*d^2) + (I*(1 - Sqrt[-a]/Sqrt[I - a])*c*PolyLog[2, (Sqrt[b]*(c + d*Sqrt[x]))/(Sqrt[b]*c + Sqrt[I - a]*d)])/(2*d^2) + (I*(1 + Sqrt[-a]/Sqrt[I - a])*c*PolyLog[2, (Sqrt[b]*(c + d*Sqrt[x]))/(Sqrt[b]*c + Sqrt[I - a]*d)])/(2*d^2)}
{ArcCot[a + b*x]/(c + d/Sqrt[x]), x, 71, (2*I*Sqrt[I + a]*d*ArcTan[(Sqrt[b]*Sqrt[x])/Sqrt[I + a]])/(Sqrt[b]*c^2) - (2*I*Sqrt[I - a]*d*ArcTanh[(Sqrt[b]*Sqrt[x])/Sqrt[I - a]])/(Sqrt[b]*c^2) + (I*(1 - Sqrt[-a]/Sqrt[-I - a])*d^2*Log[(c*(Sqrt[-I - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[-I - a]*c + Sqrt[b]*d)]*Log[d + c*Sqrt[x]])/(2*c^3) + (I*(1 + Sqrt[-a]/Sqrt[-I - a])*d^2*Log[(c*(Sqrt[-I - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[-I - a]*c + Sqrt[b]*d)]*Log[d + c*Sqrt[x]])/(2*c^3) - (I*(1 - Sqrt[-a]/Sqrt[I - a])*d^2*Log[(c*(Sqrt[I - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[I - a]*c + Sqrt[b]*d)]*Log[d + c*Sqrt[x]])/(2*c^3) - (I*(1 + Sqrt[-a]/Sqrt[I - a])*d^2*Log[(c*(Sqrt[I - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[I - a]*c + Sqrt[b]*d)]*Log[d + c*Sqrt[x]])/(2*c^3) + (I*(1 - Sqrt[-a]/Sqrt[-I - a])*d^2*Log[(c*(Sqrt[-I - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[-I - a]*c - Sqrt[b]*d)]*Log[d + c*Sqrt[x]])/(2*c^3) + (I*(1 + Sqrt[-a]/Sqrt[-I - a])*d^2*Log[(c*(Sqrt[-I - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[-I - a]*c - Sqrt[b]*d)]*Log[d + c*Sqrt[x]])/(2*c^3) - (I*(1 - Sqrt[-a]/Sqrt[I - a])*d^2*Log[(c*(Sqrt[I - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[I - a]*c - Sqrt[b]*d)]*Log[d + c*Sqrt[x]])/(2*c^3) - (I*(1 + Sqrt[-a]/Sqrt[I - a])*d^2*Log[(c*(Sqrt[I - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[I - a]*c - Sqrt[b]*d)]*Log[d + c*Sqrt[x]])/(2*c^3) - (I*(I - a)*Log[I - a - b*x])/(2*b*c) - (I*d*Sqrt[x]*Log[-((I - a - b*x)/(a + b*x))])/c^2 + (I*x*Log[-((I - a - b*x)/(a + b*x))])/(2*c) + (I*d^2*Log[d + c*Sqrt[x]]*Log[-((I - a - b*x)/(a + b*x))])/c^3 - (I*(I + a)*Log[I + a + b*x])/(2*b*c) + (I*d*Sqrt[x]*Log[(I + a + b*x)/(a + b*x)])/c^2 - (I*x*Log[(I + a + b*x)/(a + b*x)])/(2*c) - (I*d^2*Log[d + c*Sqrt[x]]*Log[(I + a + b*x)/(a + b*x)])/c^3 + (I*(1 - Sqrt[-a]/Sqrt[-I - a])*d^2*PolyLog[2, -((Sqrt[b]*(d + c*Sqrt[x]))/(Sqrt[-I - a]*c - Sqrt[b]*d))])/(2*c^3) + (I*(1 + Sqrt[-a]/Sqrt[-I - a])*d^2*PolyLog[2, -((Sqrt[b]*(d + c*Sqrt[x]))/(Sqrt[-I - a]*c - Sqrt[b]*d))])/(2*c^3) - (I*(1 - Sqrt[-a]/Sqrt[I - a])*d^2*PolyLog[2, -((Sqrt[b]*(d + c*Sqrt[x]))/(Sqrt[I - a]*c - Sqrt[b]*d))])/(2*c^3) - (I*(1 + Sqrt[-a]/Sqrt[I - a])*d^2*PolyLog[2, -((Sqrt[b]*(d + c*Sqrt[x]))/(Sqrt[I - a]*c - Sqrt[b]*d))])/(2*c^3) + (I*(1 - Sqrt[-a]/Sqrt[-I - a])*d^2*PolyLog[2, (Sqrt[b]*(d + c*Sqrt[x]))/(Sqrt[-I - a]*c + Sqrt[b]*d)])/(2*c^3) + (I*(1 + Sqrt[-a]/Sqrt[-I - a])*d^2*PolyLog[2, (Sqrt[b]*(d + c*Sqrt[x]))/(Sqrt[-I - a]*c + Sqrt[b]*d)])/(2*c^3) - (I*(1 - Sqrt[-a]/Sqrt[I - a])*d^2*PolyLog[2, (Sqrt[b]*(d + c*Sqrt[x]))/(Sqrt[I - a]*c + Sqrt[b]*d)])/(2*c^3) - (I*(1 + Sqrt[-a]/Sqrt[I - a])*d^2*PolyLog[2, (Sqrt[b]*(d + c*Sqrt[x]))/(Sqrt[I - a]*c + Sqrt[b]*d)])/(2*c^3)}
(* {ArcCot[a + b*x]/(a + b/x^(3/2)), x, 145, ((I/6)*(1 - Sqrt[-a]/Sqrt[-I - a])*b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-I - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[-I - a]*a^(1/3) + b^(5/6))])/a^(5/3) + ((I/6)*(1 + Sqrt[-a]/Sqrt[-I - a])*b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-I - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[-I - a]*a^(1/3) + b^(5/6))])/a^(5/3) - ((-1)^(1/6)*(1 - Sqrt[-a]/Sqrt[-I - a])*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-I - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[-I - a]*a^(1/3) - (-1)^(1/3)*b^(5/6))])/(6*a^(5/3)) - ((-1)^(1/6)*(1 + Sqrt[-a]/Sqrt[-I - a])*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-I - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[-I - a]*a^(1/3) - (-1)^(1/3)*b^(5/6))])/(6*a^(5/3)) - ((-1)^(5/6)*(1 - Sqrt[-a]/Sqrt[-I - a])*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-I - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[-I - a]*a^(1/3) + (-1)^(2/3)*b^(5/6))])/(6*a^(5/3)) - ((-1)^(5/6)*(1 + Sqrt[-a]/Sqrt[-I - a])*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-I - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[-I - a]*a^(1/3) + (-1)^(2/3)*b^(5/6))])/(6*a^(5/3)) - ((I/6)*(1 - Sqrt[-a]/Sqrt[I - a])*b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[I - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[I - a]*a^(1/3) + b^(5/6))])/a^(5/3) - ((I/6)*(1 + Sqrt[-a]/Sqrt[I - a])*b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[I - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[I - a]*a^(1/3) + b^(5/6))])/a^(5/3) + ((-1)^(1/6)*(1 - Sqrt[-a]/Sqrt[I - a])*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[I - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[I - a]*a^(1/3) - (-1)^(1/3)*b^(5/6))])/(6*a^(5/3)) + ((-1)^(1/6)*(1 + Sqrt[-a]/Sqrt[I - a])*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[I - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[I - a]*a^(1/3) - (-1)^(1/3)*b^(5/6))])/(6*a^(5/3)) + ((-1)^(5/6)*(1 - Sqrt[-a]/Sqrt[I - a])*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[I - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[I - a]*a^(1/3) + (-1)^(2/3)*b^(5/6))])/(6*a^(5/3)) + ((-1)^(5/6)*(1 + Sqrt[-a]/Sqrt[I - a])*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[I - a] - Sqrt[b]*Sqrt[x]))/(Sqrt[I - a]*a^(1/3) + (-1)^(2/3)*b^(5/6))])/(6*a^(5/3)) + ((I/6)*(1 - Sqrt[-a]/Sqrt[-I - a])*b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-I - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[-I - a]*a^(1/3) - b^(5/6))])/a^(5/3) + ((I/6)*(1 + Sqrt[-a]/Sqrt[-I - a])*b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-I - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[-I - a]*a^(1/3) - b^(5/6))])/a^(5/3) - ((-1)^(1/6)*(1 - Sqrt[-a]/Sqrt[-I - a])*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-I - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[-I - a]*a^(1/3) + (-1)^(1/3)*b^(5/6))])/(6*a^(5/3)) - ((-1)^(1/6)*(1 + Sqrt[-a]/Sqrt[-I - a])*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-I - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[-I - a]*a^(1/3) + (-1)^(1/3)*b^(5/6))])/(6*a^(5/3)) - ((-1)^(5/6)*(1 - Sqrt[-a]/Sqrt[-I - a])*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-I - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[-I - a]*a^(1/3) - (-1)^(2/3)*b^(5/6))])/(6*a^(5/3)) - ((-1)^(5/6)*(1 + Sqrt[-a]/Sqrt[-I - a])*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[-I - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[-I - a]*a^(1/3) - (-1)^(2/3)*b^(5/6))])/(6*a^(5/3)) - ((I/6)*(1 - Sqrt[-a]/Sqrt[I - a])*b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[I - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[I - a]*a^(1/3) - b^(5/6))])/a^(5/3) - ((I/6)*(1 + Sqrt[-a]/Sqrt[I - a])*b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[I - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[I - a]*a^(1/3) - b^(5/6))])/a^(5/3) + ((-1)^(1/6)*(1 - Sqrt[-a]/Sqrt[I - a])*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[I - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[I - a]*a^(1/3) + (-1)^(1/3)*b^(5/6))])/(6*a^(5/3)) + ((-1)^(1/6)*(1 + Sqrt[-a]/Sqrt[I - a])*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[I - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[I - a]*a^(1/3) + (-1)^(1/3)*b^(5/6))])/(6*a^(5/3)) + ((-1)^(5/6)*(1 - Sqrt[-a]/Sqrt[I - a])*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[I - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[I - a]*a^(1/3) - (-1)^(2/3)*b^(5/6))])/(6*a^(5/3)) + ((-1)^(5/6)*(1 + Sqrt[-a]/Sqrt[I - a])*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[(a^(1/3)*(Sqrt[I - a] + Sqrt[b]*Sqrt[x]))/(Sqrt[I - a]*a^(1/3) - (-1)^(2/3)*b^(5/6))])/(6*a^(5/3)) - ((I/2)*(I - a)*Log[I - a - b*x])/(a*b) - ((I/2)*(I + a)*Log[I + a + b*x])/(a*b) + ((I/2)*x*Log[1 - I/(a + b*x)])/a + ((I/3)*b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[1 - I/(a + b*x)])/a^(5/3) - ((-1)^(1/6)*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[1 - I/(a + b*x)])/(3*a^(5/3)) - ((-1)^(5/6)*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[1 - I/(a + b*x)])/(3*a^(5/3)) - ((I/2)*x*Log[1 + I/(a + b*x)])/a - ((I/3)*b^(2/3)*Log[-b^(1/3) - a^(1/3)*Sqrt[x]]*Log[1 + I/(a + b*x)])/a^(5/3) + ((-1)^(1/6)*b^(2/3)*Log[(-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]]*Log[1 + I/(a + b*x)])/(3*a^(5/3)) + ((-1)^(5/6)*b^(2/3)*Log[-((-1)^(2/3)*b^(1/3)) - a^(1/3)*Sqrt[x]]*Log[1 + I/(a + b*x)])/(3*a^(5/3)) - ((-1)^(1/6)*(1 - Sqrt[-a]/Sqrt[-I - a])*b^(2/3)*PolyLog[2, -((Sqrt[b]*((-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]))/(Sqrt[-I - a]*a^(1/3) - (-1)^(1/3)*b^(5/6)))])/(6*a^(5/3)) - ((-1)^(1/6)*(1 + Sqrt[-a]/Sqrt[-I - a])*b^(2/3)*PolyLog[2, -((Sqrt[b]*((-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]))/(Sqrt[-I - a]*a^(1/3) - (-1)^(1/3)*b^(5/6)))])/(6*a^(5/3)) + ((-1)^(1/6)*(1 - Sqrt[-a]/Sqrt[I - a])*b^(2/3)*PolyLog[2, -((Sqrt[b]*((-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]))/(Sqrt[I - a]*a^(1/3) - (-1)^(1/3)*b^(5/6)))])/(6*a^(5/3)) + ((-1)^(1/6)*(1 + Sqrt[-a]/Sqrt[I - a])*b^(2/3)*PolyLog[2, -((Sqrt[b]*((-1)^(1/3)*b^(1/3) - a^(1/3)*Sqrt[x]))/(Sqrt[I - a]*a^(1/3) - (-1)^(1/3)*b^(5/6)))])/(6*a^(5/3)) + ((I/6)*(1 - Sqrt[-a]/Sqrt[-I - a])*b^(2/3)*PolyLog[2, -((Sqrt[b]*(b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[-I - a]*a^(1/3) - b^(5/6)))])/a^(5/3) + ((I/6)*(1 + Sqrt[-a]/Sqrt[-I - a])*b^(2/3)*PolyLog[2, -((Sqrt[b]*(b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[-I - a]*a^(1/3) - b^(5/6)))])/a^(5/3) - ((I/6)*(1 - Sqrt[-a]/Sqrt[I - a])*b^(2/3)*PolyLog[2, -((Sqrt[b]*(b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[I - a]*a^(1/3) - b^(5/6)))])/a^(5/3) - ((I/6)*(1 + Sqrt[-a]/Sqrt[I - a])*b^(2/3)*PolyLog[2, -((Sqrt[b]*(b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[I - a]*a^(1/3) - b^(5/6)))])/a^(5/3) + ((I/6)*(1 - Sqrt[-a]/Sqrt[-I - a])*b^(2/3)*PolyLog[2, (Sqrt[b]*(b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[-I - a]*a^(1/3) + b^(5/6))])/a^(5/3) + ((I/6)*(1 + Sqrt[-a]/Sqrt[-I - a])*b^(2/3)*PolyLog[2, (Sqrt[b]*(b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[-I - a]*a^(1/3) + b^(5/6))])/a^(5/3) - ((I/6)*(1 - Sqrt[-a]/Sqrt[I - a])*b^(2/3)*PolyLog[2, (Sqrt[b]*(b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[I - a]*a^(1/3) + b^(5/6))])/a^(5/3) - ((I/6)*(1 + Sqrt[-a]/Sqrt[I - a])*b^(2/3)*PolyLog[2, (Sqrt[b]*(b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[I - a]*a^(1/3) + b^(5/6))])/a^(5/3) - ((-1)^(5/6)*(1 - Sqrt[-a]/Sqrt[-I - a])*b^(2/3)*PolyLog[2, -((Sqrt[b]*((-1)^(2/3)*b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[-I - a]*a^(1/3) - (-1)^(2/3)*b^(5/6)))])/(6*a^(5/3)) - ((-1)^(5/6)*(1 + Sqrt[-a]/Sqrt[-I - a])*b^(2/3)*PolyLog[2, -((Sqrt[b]*((-1)^(2/3)*b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[-I - a]*a^(1/3) - (-1)^(2/3)*b^(5/6)))])/(6*a^(5/3)) + ((-1)^(5/6)*(1 - Sqrt[-a]/Sqrt[I - a])*b^(2/3)*PolyLog[2, -((Sqrt[b]*((-1)^(2/3)*b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[I - a]*a^(1/3) - (-1)^(2/3)*b^(5/6)))])/(6*a^(5/3)) + ((-1)^(5/6)*(1 + Sqrt[-a]/Sqrt[I - a])*b^(2/3)*PolyLog[2, -((Sqrt[b]*((-1)^(2/3)*b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[I - a]*a^(1/3) - (-1)^(2/3)*b^(5/6)))])/(6*a^(5/3)) - ((-1)^(5/6)*(1 - Sqrt[-a]/Sqrt[-I - a])*b^(2/3)*PolyLog[2, (Sqrt[b]*((-1)^(2/3)*b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[-I - a]*a^(1/3) + (-1)^(2/3)*b^(5/6))])/(6*a^(5/3)) - ((-1)^(5/6)*(1 + Sqrt[-a]/Sqrt[-I - a])*b^(2/3)*PolyLog[2, (Sqrt[b]*((-1)^(2/3)*b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[-I - a]*a^(1/3) + (-1)^(2/3)*b^(5/6))])/(6*a^(5/3)) + ((-1)^(5/6)*(1 - Sqrt[-a]/Sqrt[I - a])*b^(2/3)*PolyLog[2, (Sqrt[b]*((-1)^(2/3)*b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[I - a]*a^(1/3) + (-1)^(2/3)*b^(5/6))])/(6*a^(5/3)) + ((-1)^(5/6)*(1 + Sqrt[-a]/Sqrt[I - a])*b^(2/3)*PolyLog[2, (Sqrt[b]*((-1)^(2/3)*b^(1/3) + a^(1/3)*Sqrt[x]))/(Sqrt[I - a]*a^(1/3) + (-1)^(2/3)*b^(5/6))])/(6*a^(5/3)) - ((-1)^(1/6)*(1 - Sqrt[-a]/Sqrt[-I - a])*b^(2/3)*PolyLog[2, ((-1)^(1/3)*Sqrt[b]*(b^(1/3) + (-1)^(2/3)*a^(1/3)*Sqrt[x]))/(Sqrt[-I - a]*a^(1/3) + (-1)^(1/3)*b^(5/6))])/(6*a^(5/3)) - ((-1)^(1/6)*(1 + Sqrt[-a]/Sqrt[-I - a])*b^(2/3)*PolyLog[2, ((-1)^(1/3)*Sqrt[b]*(b^(1/3) + (-1)^(2/3)*a^(1/3)*Sqrt[x]))/(Sqrt[-I - a]*a^(1/3) + (-1)^(1/3)*b^(5/6))])/(6*a^(5/3)) + ((-1)^(1/6)*(1 - Sqrt[-a]/Sqrt[I - a])*b^(2/3)*PolyLog[2, ((-1)^(1/3)*Sqrt[b]*(b^(1/3) + (-1)^(2/3)*a^(1/3)*Sqrt[x]))/(Sqrt[I - a]*a^(1/3) + (-1)^(1/3)*b^(5/6))])/(6*a^(5/3)) + ((-1)^(1/6)*(1 + Sqrt[-a]/Sqrt[I - a])*b^(2/3)*PolyLog[2, ((-1)^(1/3)*Sqrt[b]*(b^(1/3) + (-1)^(2/3)*a^(1/3)*Sqrt[x]))/(Sqrt[I - a]*a^(1/3) + (-1)^(1/3)*b^(5/6))])/(6*a^(5/3))} *)


(* ::Subsection::Closed:: *)
(*Integrands of the form (c+d x+e x^2)^m ArcCot[a+b x]*)


{ArcCot[d + e*x]/(a + b*x + c*x^2), x, 33, -((I*Log[b - Sqrt[b^2 - 4*a*c] + 2*c*x]*Log[(2*c*(I - d - e*x))/(2*I*c - 2*c*d + b*e - Sqrt[b^2 - 4*a*c]*e)])/(2*Sqrt[b^2 - 4*a*c])) + (I*Log[b + Sqrt[b^2 - 4*a*c] + 2*c*x]*Log[(2*c*(I - d - e*x))/(2*c*(I - d) + (b + Sqrt[b^2 - 4*a*c])*e)])/(2*Sqrt[b^2 - 4*a*c]) + (I*Log[b - Sqrt[b^2 - 4*a*c] + 2*c*x]*Log[-((I - d - e*x)/(d + e*x))])/(2*Sqrt[b^2 - 4*a*c]) - (I*Log[b + Sqrt[b^2 - 4*a*c] + 2*c*x]*Log[-((I - d - e*x)/(d + e*x))])/(2*Sqrt[b^2 - 4*a*c]) + (I*Log[b - Sqrt[b^2 - 4*a*c] + 2*c*x]*Log[(2*c*(I + d + e*x))/(2*c*(I + d) - (b - Sqrt[b^2 - 4*a*c])*e)])/(2*Sqrt[b^2 - 4*a*c]) - (I*Log[b + Sqrt[b^2 - 4*a*c] + 2*c*x]*Log[(2*c*(I + d + e*x))/(2*c*(I + d) - (b + Sqrt[b^2 - 4*a*c])*e)])/(2*Sqrt[b^2 - 4*a*c]) - (I*Log[b - Sqrt[b^2 - 4*a*c] + 2*c*x]*Log[(I + d + e*x)/(d + e*x)])/(2*Sqrt[b^2 - 4*a*c]) + (I*Log[b + Sqrt[b^2 - 4*a*c] + 2*c*x]*Log[(I + d + e*x)/(d + e*x)])/(2*Sqrt[b^2 - 4*a*c]) - (I*PolyLog[2, (e*(b - Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*I*c - 2*c*d + b*e - Sqrt[b^2 - 4*a*c]*e)])/(2*Sqrt[b^2 - 4*a*c]) + (I*PolyLog[2, -((e*(b - Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c*(I + d) - (b - Sqrt[b^2 - 4*a*c])*e))])/(2*Sqrt[b^2 - 4*a*c]) - (I*PolyLog[2, -((e*(b + Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c*(I + d) - (b + Sqrt[b^2 - 4*a*c])*e))])/(2*Sqrt[b^2 - 4*a*c]) + (I*PolyLog[2, (e*(b + Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c*(I - d) + (b + Sqrt[b^2 - 4*a*c])*e)])/(2*Sqrt[b^2 - 4*a*c])}


(* ::Section::Closed:: *)
(*Integrands of the form u ArcCot[a +b x^n]*)


{x^3*ArcCot[a + b*x^4], x, 2, ((a + b*x^4)*ArcCot[a + b*x^4])/(4*b) + Log[1 + (a + b*x^4)^2]/(8*b)}


{x^(n-1)*ArcCot[a + b*x^n], x, 2, ((a + b*x^n)*ArcCot[a + b*x^n])/(b*n) + Log[1 + (a + b*x^n)^2]/(2*b*n)}


(* ::Section::Closed:: *)
(*Integrands involving inverse cotangents of exponentials*)


(* Integrands of the form x^m*ArcCot[E^x] *)
{ArcCot[E^x], x, 3, (-(1/2))*I*PolyLog[2, -I/E^x] + (1/2)*I*PolyLog[2, I/E^x]}
{x*ArcCot[E^x], x, 5, (-(1/2))*I*x*PolyLog[2, -I/E^x] + (1/2)*I*x*PolyLog[2, I/E^x] - (1/2)*I*PolyLog[3, -I/E^x] + (1/2)*I*PolyLog[3, I/E^x]}
{x^2*ArcCot[E^x], x, 7, (-(1/2))*I*x^2*PolyLog[2, -I/E^x] + (1/2)*I*x^2*PolyLog[2, I/E^x] - I*x*PolyLog[3, -I/E^x] + I*x*PolyLog[3, I/E^x] - I*PolyLog[4, -I/E^x] + I*PolyLog[4, I/E^x]}


(* Integrands of the form x^m*ArcCot[E^(a+b*x)] *)
{ArcCot[E^(a + b*x)], x, 3, -((I*PolyLog[2, (-I)*E^(-a - b*x)])/(2*b)) + (I*PolyLog[2, I*E^(-a - b*x)])/(2*b)}
{x*ArcCot[E^(a + b*x)], x, 5, -((I*x*PolyLog[2, (-I)*E^(-a - b*x)])/(2*b)) + (I*x*PolyLog[2, I*E^(-a - b*x)])/(2*b) - (I*PolyLog[3, (-I)*E^(-a - b*x)])/(2*b^2) + (I*PolyLog[3, I*E^(-a - b*x)])/(2*b^2)}
{x^2*ArcCot[E^(a + b*x)], x, 7, -((I*x^2*PolyLog[2, (-I)*E^(-a - b*x)])/(2*b)) + (I*x^2*PolyLog[2, I*E^(-a - b*x)])/(2*b) - (I*x*PolyLog[3, (-I)*E^(-a - b*x)])/b^2 + (I*x*PolyLog[3, I*E^(-a - b*x)])/b^2 - (I*PolyLog[4, (-I)*E^(-a - b*x)])/b^3 + (I*PolyLog[4, I*E^(-a - b*x)])/b^3}


(* Integrands of the form x^m*ArcCot[a+b*f^(c+d*x)] *)
{ArcCot[a + b*f^(c + d*x)], x, 17, x*ArcCot[a + b*f^(c + d*x)] - (1/2)*I*x*Log[1 - (b*f^(c + d*x))/(I - a)] + (1/2)*I*x*Log[1 + (b*f^(c + d*x))/(I + a)] - (I*PolyLog[2, (b*f^(c + d*x))/(I - a)])/(2*d*Log[f]) + (I*PolyLog[2, -((b*f^(c + d*x))/(I + a))])/(2*d*Log[f]), (-(1/2))*I*x*Log[1 - (b*f^(c + d*x))/(I - a)] + (1/2)*I*x*Log[1 + (b*f^(c + d*x))/(I + a)] + (1/2)*I*x*Log[1 - I/(a + b*f^(c + d*x))] - (1/2)*I*x*Log[1 + I/(a + b*f^(c + d*x))] - (I*PolyLog[2, (b*f^(c + d*x))/(I - a)])/(2*d*Log[f]) + (I*PolyLog[2, -((b*f^(c + d*x))/(I + a))])/(2*d*Log[f])}
{x*ArcCot[a + b*f^(c + d*x)], x, 21, (-(1/4))*I*x^2*Log[1 - (b*f^(c + d*x))/(I - a)] + (1/4)*I*x^2*Log[1 + (b*f^(c + d*x))/(I + a)] + (1/4)*I*x^2*Log[1 - I/(a + b*f^(c + d*x))] - (1/4)*I*x^2*Log[1 + I/(a + b*f^(c + d*x))] - (I*x*PolyLog[2, (b*f^(c + d*x))/(I - a)])/(2*d*Log[f]) + (I*x*PolyLog[2, -((b*f^(c + d*x))/(I + a))])/(2*d*Log[f]) + (I*PolyLog[3, (b*f^(c + d*x))/(I - a)])/(2*d^2*Log[f]^2) - (I*PolyLog[3, -((b*f^(c + d*x))/(I + a))])/(2*d^2*Log[f]^2)}
{x^2*ArcCot[a + b*f^(c + d*x)], x, 25, (-(1/6))*I*x^3*Log[1 - (b*f^(c + d*x))/(I - a)] + (1/6)*I*x^3*Log[1 + (b*f^(c + d*x))/(I + a)] + (1/6)*I*x^3*Log[1 - I/(a + b*f^(c + d*x))] - (1/6)*I*x^3*Log[1 + I/(a + b*f^(c + d*x))] - (I*x^2*PolyLog[2, (b*f^(c + d*x))/(I - a)])/(2*d*Log[f]) + (I*x^2*PolyLog[2, -((b*f^(c + d*x))/(I + a))])/(2*d*Log[f]) + (I*x*PolyLog[3, (b*f^(c + d*x))/(I - a)])/(d^2*Log[f]^2) - (I*x*PolyLog[3, -((b*f^(c + d*x))/(I + a))])/(d^2*Log[f]^2) - (I*PolyLog[4, (b*f^(c + d*x))/(I - a)])/(d^3*Log[f]^3) + (I*PolyLog[4, -((b*f^(c + d*x))/(I + a))])/(d^3*Log[f]^3)}


{ArcCot[E^x]/E^x, x, 2, -x - ArcCot[E^x]/E^x + (1/2)*Log[1 + E^(2*x)]}


(* ::Section::Closed:: *)
(*Integrands involving inverse cotangents of trig functions*)


{ArcCot[Tanh[a + b*x]], x, 7, x*ArcCot[Tanh[a + b*x]] + (1/2)*I*x*Log[1 - I*E^(2*a + 2*b*x)] - (1/2)*I*x*Log[1 + I*E^(2*a + 2*b*x)] - (I*PolyLog[2, (-I)*E^(2*a + 2*b*x)])/(4*b) + (I*PolyLog[2, I*E^(2*a + 2*b*x)])/(4*b)}
{ArcCot[I + d + d*Tanh[a + b*x]], x, 4, (-(1/2))*I*b*x^2 - I*x*ArcCoth[1 - I*d - I*d*Tanh[a + b*x]] + (1/2)*I*x*Log[1 + (1 - I*d)*E^(2*a + 2*b*x)] + (I*PolyLog[2, I*(I + d)*E^(2*a + 2*b*x)])/(4*b)}
{ArcCot[I - d - d*Tanh[a + b*x]], x, 4, (-(1/2))*I*b*x^2 - I*x*ArcCoth[1 + I*d + I*d*Tanh[a + b*x]] + (1/2)*I*x*Log[1 + (1 + I*d)*E^(2*a + 2*b*x)] + (I*PolyLog[2, -((1 + I*d)*E^(2*a + 2*b*x))])/(4*b)}
{ArcCot[c + d*Tanh[a + b*x]], x, 7, x*ArcCot[c + d*Tanh[a + b*x]] - (1/2)*I*x*Log[1 + ((I - c - d)*E^(2*a + 2*b*x))/(I - c + d)] + (1/2)*I*x*Log[1 + ((I + c + d)*E^(2*a + 2*b*x))/(I + c - d)] - (I*PolyLog[2, -(((I - c - d)*E^(2*a + 2*b*x))/(I - c + d))])/(4*b) + (I*PolyLog[2, -(((I + c + d)*E^(2*a + 2*b*x))/(I + c - d))])/(4*b)}


{ArcCot[Coth[a + b*x]], x, 7, x*ArcCot[Coth[a + b*x]] - (1/2)*I*x*Log[1 - I*E^(2*a + 2*b*x)] + (1/2)*I*x*Log[1 + I*E^(2*a + 2*b*x)] + (I*PolyLog[2, (-I)*E^(2*a + 2*b*x)])/(4*b) - (I*PolyLog[2, I*E^(2*a + 2*b*x)])/(4*b)}
{ArcCot[I + d + d*Coth[a + b*x]], x, 4, (-(1/2))*I*b*x^2 - I*x*ArcCoth[1 - I*d - I*d*Coth[a + b*x]] + (1/2)*I*x*Log[1 + I*(I + d)*E^(2*a + 2*b*x)] + (I*PolyLog[2, (1 - I*d)*E^(2*a + 2*b*x)])/(4*b)}
{ArcCot[I - d - d*Coth[a + b*x]], x, 4, (-(1/2))*I*b*x^2 - I*x*ArcCoth[1 + I*d + I*d*Coth[a + b*x]] + (1/2)*I*x*Log[1 - (1 + I*d)*E^(2*a + 2*b*x)] + (I*PolyLog[2, (1 + I*d)*E^(2*a + 2*b*x)])/(4*b)}
{ArcCot[c + d*Coth[a + b*x]], x, 7, x*ArcCot[c + d*Coth[a + b*x]] - (1/2)*I*x*Log[1 - ((I - c - d)*E^(2*a + 2*b*x))/(I - c + d)] + (1/2)*I*x*Log[1 - ((I + c + d)*E^(2*a + 2*b*x))/(I + c - d)] - (I*PolyLog[2, ((I - c - d)*E^(2*a + 2*b*x))/(I - c + d)])/(4*b) + (I*PolyLog[2, ((I + c + d)*E^(2*a + 2*b*x))/(I + c - d)])/(4*b)}


{ArcCot[Tan[a + b*x]], x, 2, -(ArcCot[Tan[a + b*x]]^2/(2*b))}
{ArcCot[I - I*d + d*Tan[a + b*x]], x, 4, (b*x^2)/2 - I*x*ArcCoth[1 - d - I*d*Tan[a + b*x]] + (1/2)*I*x*Log[1 + (1 - d)*E^(2*I*a + 2*I*b*x)] + PolyLog[2, -((1 - d)*E^(2*I*a + 2*I*b*x))]/(4*b)}
{ArcCot[I + I*d - d*Tan[a + b*x]], x, 4, (b*x^2)/2 - I*x*ArcCoth[1 + d + I*d*Tan[a + b*x]] + (1/2)*I*x*Log[1 + (1 + d)*E^(2*I*a + 2*I*b*x)] + PolyLog[2, -((1 + d)*E^(2*I*a + 2*I*b*x))]/(4*b)}
{ArcCot[c + d*Tan[a + b*x]], x, 7, x*ArcCot[c + d*Tan[a + b*x]] - (1/2)*I*x*Log[1 + ((c - I*(1 + d))*E^(2*I*a + 2*I*b*x))/(c - I*(1 - d))] + (1/2)*I*x*Log[1 + ((c + I*(1 - d))*E^(2*I*a + 2*I*b*x))/(c + I*(1 + d))] - PolyLog[2, -(((c - I*(1 + d))*E^(2*I*a + 2*I*b*x))/(c - I*(1 - d)))]/(4*b) + PolyLog[2, -(((c + I*(1 - d))*E^(2*I*a + 2*I*b*x))/(c + I*(1 + d)))]/(4*b)}


{ArcCot[Cot[a + b*x]], x, 2, ArcCot[Cot[a + b*x]]^2/(2*b)}
{ArcCot[I + I*d + d*Cot[a + b*x]], x, 4, (b*x^2)/2 - I*x*ArcCoth[1 + d - I*d*Cot[a + b*x]] + (1/2)*I*x*Log[1 - (1 + d)*E^(2*I*a + 2*I*b*x)] + PolyLog[2, (1 + d)*E^(2*I*a + 2*I*b*x)]/(4*b)}
{ArcCot[I - I*d - d*Cot[a + b*x]], x, 4, (b*x^2)/2 - I*x*ArcCoth[1 - d + I*d*Cot[a + b*x]] + (1/2)*I*x*Log[1 - (1 - d)*E^(2*I*a + 2*I*b*x)] + PolyLog[2, (1 - d)*E^(2*I*a + 2*I*b*x)]/(4*b)}
{ArcCot[c + d*Cot[a + b*x]], x, 7, x*ArcCot[c + d*Cot[a + b*x]] - (1/2)*I*x*Log[1 - ((c - I*(1 - d))*E^(2*I*a + 2*I*b*x))/(c - I*(1 + d))] + (1/2)*I*x*Log[1 - ((c + I*(1 + d))*E^(2*I*a + 2*I*b*x))/(c + I*(1 - d))] - PolyLog[2, ((c - I*(1 - d))*E^(2*I*a + 2*I*b*x))/(c - I*(1 + d))]/(4*b) + PolyLog[2, ((c + I*(1 + d))*E^(2*I*a + 2*I*b*x))/(c + I*(1 - d))]/(4*b)}


(* ::Section::Closed:: *)
(*Integrands involving exponentials of inverse cotangents*)


{E^ArcCot[x], x, 2, (1/5 + (2*I)/5)*2^(1 - I/2)*(1 - I/x)^(1 + I/2)*(I/x)^(-1 - I/2)*Hypergeometric2F1[I/2, 1 + I/2, 2 + I/2, (1/2)*(1 + I*x)], (1/5 + (2*I)/5)*2^(1 - I/2)*(1 - I/x)^(1 + I/2)*(I/x)^(-1 - I/2)*Hypergeometric2F1[I/2, 1 + I/2, 2 + I/2, (1/2)*I*(2 + I*(I + 1/x) - (2*I)/x)*x]}


{E^ArcCot[x]/(a + a*x^2), x, 1, -(E^ArcCot[x]/a)}
{E^ArcCot[x]/(a + a*x^2)^2, x, 2, -((2*E^ArcCot[x])/(5*a^2)) - (E^ArcCot[x]*(1 - 2*x))/(5*a^2*(1 + x^2))}
{E^ArcCot[x]/(a + a*x^2)^3, x, 3, -((24*E^ArcCot[x])/(85*a^3)) - (E^ArcCot[x]*(1 - 4*x))/(17*a^3*(1 + x^2)^2) - (12*E^ArcCot[x]*(1 - 2*x))/(85*a^3*(1 + x^2))}

{E^ArcCot[x]/(a + a*x^2)^(3/2), x, 1, -((E^ArcCot[x]*(1 - x))/(2*a*Sqrt[a + a*x^2]))}
{E^ArcCot[x]/(a + a*x^2)^(5/2), x, 2, -((E^ArcCot[x]*(1 - 3*x))/(10*a*(a + a*x^2)^(3/2))) - (3*E^ArcCot[x]*(1 - x))/(10*a^2*Sqrt[a + a*x^2])}
{E^ArcCot[x]/(a + a*x^2)^(7/2), x, 3, -((E^ArcCot[x]*(1 - 5*x))/(26*a*(a + a*x^2)^(5/2))) - (E^ArcCot[x]*(1 - 3*x))/(13*a^2*(a + a*x^2)^(3/2)) - (3*E^ArcCot[x]*(1 - x))/(13*a^3*Sqrt[a + a*x^2])}


{E^(n*ArcCot[a*x])/(c + a^2*c*x^2)^(1/3), x, 3, (3*(1 + 1/(a^2*x^2))^(1/3)*(1 + I/(a*x))^(1/3)*x*Hypergeometric2F1[-(1/3), (1/6)*(2 - 3*I*n), 2/3, (2*I)/((a + I/x)*x)])/(c + a^2*c*x^2)^(1/3)}
{E^(n*ArcCot[a*x])/(c + a^2*c*x^2)^(2/3), x, 3, -((3*(1 + 1/(a^2*x^2))^(2/3)*x*Hypergeometric2F1[1/3, (1/6)*(4 - 3*I*n), 4/3, (2*I)/((a + I/x)*x)])/((1 + I/(a*x))^(1/3)*(c + a^2*c*x^2)^(2/3)))}
{E^(n*ArcCot[a*x])/(c + a^2*c*x^2)^(4/3), x, 4, -((3*E^(n*ArcCot[a*x])*(3*n - 2*a*x))/(a*c*(4 + 9*n^2)*(c + a^2*c*x^2)^(1/3))) - (6*(1 + 1/(a^2*x^2))^(1/3)*(1 + I/(a*x))^(1/3)*x*Hypergeometric2F1[-(1/3), (1/6)*(2 - 3*I*n), 2/3, (2*I)/((a + I/x)*x)])/(c*(4 + 9*n^2)*(c + a^2*c*x^2)^(1/3))}
{E^(n*ArcCot[a*x])/(c + a^2*c*x^2)^(5/3), x, 4, -((3*E^(n*ArcCot[a*x])*(3*n - 4*a*x))/(a*c*(16 + 9*n^2)*(c + a^2*c*x^2)^(2/3))) - (12*(1 + 1/(a^2*x^2))^(2/3)*x*Hypergeometric2F1[1/3, (1/6)*(4 - 3*I*n), 4/3, (2*I)/((a + I/x)*x)])/(c*(16 + 9*n^2)*(1 + I/(a*x))^(1/3)*(c + a^2*c*x^2)^(2/3))}
{E^(n*ArcCot[a*x])/(c + a^2*c*x^2)^(7/3), x, 5, -((3*E^(n*ArcCot[a*x])*(3*n - 8*a*x))/(a*c*(64 + 9*n^2)*(c + a^2*c*x^2)^(4/3))) - (120*E^(n*ArcCot[a*x])*(3*n - 2*a*x))/(a*c^2*(4 + 9*n^2)*(64 + 9*n^2)*(c + a^2*c*x^2)^(1/3)) - (240*(1 + 1/(a^2*x^2))^(1/3)*(1 + I/(a*x))^(1/3)*x*Hypergeometric2F1[-(1/3), (1/6)*(2 - 3*I*n), 2/3, (2*I)/((a + I/x)*x)])/(c^2*(4 + 9*n^2)*(64 + 9*n^2)*(c + a^2*c*x^2)^(1/3))}


(* ::Section::Closed:: *)
(*Miscellaneous integrands involving inverse cotangents*)


{1/((a + a*x^2)*(b - 2*b*ArcCot[x])), x, 1, Log[1 - 2*ArcCot[x]]/(2*a*b)}
