(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Inverse Cotangents*)


(* ::Subsection::Closed:: *)
(*Integrands involving inverse cotangents*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m ArcCot[a x]^n*)


(* Integrands of the form x^m*ArcCot[a*x] where m is an integer *)
{x^5*ArcCot[a*x], x, 6, x/(6*a^5) - x^3/(18*a^3) + x^5/(30*a) + ArcCot[a*x]/(6*a^6) + (1/6)*x^6*ArcCot[a*x]}
{x^4*ArcCot[a*x], x, 5, -(x^2/(10*a^3)) + x^4/(20*a) + (1/5)*x^5*ArcCot[a*x] + Log[1 + a^2*x^2]/(10*a^5)}
{x^3*ArcCot[a*x], x, 4, -(x/(4*a^3)) + x^3/(12*a) - ArcCot[a*x]/(4*a^4) + (1/4)*x^4*ArcCot[a*x]}
{x^2*ArcCot[a*x], x, 3, x^2/(6*a) + (1/3)*x^3*ArcCot[a*x] - Log[1 + a^2*x^2]/(6*a^3)}
{x*ArcCot[a*x], x, 2, x/(2*a) + ArcCot[a*x]/(2*a^2) + (1/2)*x^2*ArcCot[a*x]}
{ArcCot[a*x], x, 1, x*ArcCot[a*x] + Log[1 + a^2*x^2]/(2*a)}
{ArcCot[a*x]/x, x, 3, (-(1/2))*I*PolyLog[2, -(I/(a*x))] + (1/2)*I*PolyLog[2, I/(a*x)]}
{ArcCot[a*x]/x^2, x, 2, -(ArcCot[a*x]/x) + a*ArcTanh[1 + 2*a^2*x^2]}
{ArcCot[a*x]/x^3, x, 2, a/(2*x) - (1/2)*a^2*ArcCot[a*x] - ArcCot[a*x]/(2*x^2)}
{ArcCot[a*x]/x^4, x, 4, a/(6*x^2) - ArcCot[a*x]/(3*x^3) - (1/3)*a^3*ArcTanh[1 + 2*a^2*x^2]}
{ArcCot[a*x]/x^5, x, 4, a/(12*x^3) - a^3/(4*x) + (1/4)*a^4*ArcCot[a*x] - ArcCot[a*x]/(4*x^4)}


(* Integrands of the form x^m*ArcCot[a*x]^2 where m is an integer *)
{x^5*ArcCot[a*x]^2, x, 12, -((4*x^2)/(45*a^4)) + x^4/(60*a^2) + (x*ArcCot[a*x])/(3*a^5) - (x^3*ArcCot[a*x])/(9*a^3) + (x^5*ArcCot[a*x])/(15*a) + ArcCot[a*x]^2/(6*a^6) + (1/6)*x^6*ArcCot[a*x]^2 + (23*Log[1 + a^2*x^2])/(90*a^6)}
{x^4*ArcCot[a*x]^2, x, 12, -((3*x)/(10*a^4)) + x^3/(30*a^2) - (3*ArcCot[a*x])/(10*a^5) - (x^2*ArcCot[a*x])/(5*a^3) + (x^4*ArcCot[a*x])/(10*a) + (I*ArcCot[a*x]^2)/(5*a^5) + (1/5)*x^5*ArcCot[a*x]^2 - (2*ArcCot[a*x]*Log[(2*I)/(I - a*x)])/(5*a^5) + (I*PolyLog[2, 1 - (2*I)/(I - a*x)])/(5*a^5)}
{x^3*ArcCot[a*x]^2, x, 6, x^2/(12*a^2) - (x*ArcCot[a*x])/(2*a^3) + (x^3*ArcCot[a*x])/(6*a) - ArcCot[a*x]^2/(4*a^4) + (1/4)*x^4*ArcCot[a*x]^2 - Log[1 + a^2*x^2]/(3*a^4)}
{x^2*ArcCot[a*x]^2, x, 7, x/(3*a^2) + ArcCot[a*x]/(3*a^3) + (x^2*ArcCot[a*x])/(3*a) - (I*ArcCot[a*x]^2)/(3*a^3) + (1/3)*x^3*ArcCot[a*x]^2 + (2*ArcCot[a*x]*Log[(2*I)/(I - a*x)])/(3*a^3) - (I*PolyLog[2, 1 - (2*I)/(I - a*x)])/(3*a^3)}
{x*ArcCot[a*x]^2, x, 2, (x*ArcCot[a*x])/a + ArcCot[a*x]^2/(2*a^2) + (1/2)*x^2*ArcCot[a*x]^2 + Log[1 + a^2*x^2]/(2*a^2)}
{ArcCot[a*x]^2, x, 4, (I*ArcCot[a*x]^2)/a + x*ArcCot[a*x]^2 - (2*ArcCot[a*x]*Log[(2*I)/(I - a*x)])/a + (I*PolyLog[2, 1 - (2*I)/(I - a*x)])/a}
{ArcCot[a*x]^2/x, x, 6, 2*ArcCot[a*x]^2*ArcCoth[1 - (2*I)/(I - a*x)] - I*ArcCot[a*x]*PolyLog[2, 1 - (2*I)/(I + a*x)] + I*ArcCot[a*x]*PolyLog[2, 1 - (2*a*x)/(I + a*x)] - (1/2)*PolyLog[3, 1 - (2*I)/(I + a*x)] + (1/2)*PolyLog[3, 1 - (2*a*x)/(I + a*x)]}
{ArcCot[a*x]^2/x^2, x, 4, (-I)*a*ArcCot[a*x]^2 - ArcCot[a*x]^2/x - 2*a*ArcCot[a*x]*Log[(2*a*x)/(I + a*x)] - I*a*PolyLog[2, -1 + (2*I)/(I + a*x)]}
{ArcCot[a*x]^2/x^3, x, 3, (a*ArcCot[a*x])/x - (1/2)*a^2*ArcCot[a*x]^2 - ArcCot[a*x]^2/(2*x^2) - a^2*ArcTanh[1 + 2*a^2*x^2]}
{ArcCot[a*x]^2/x^4, x, 7, -(a^2/(3*x)) + (1/3)*a^3*ArcCot[a*x] + (a*ArcCot[a*x])/(3*x^2) + (1/3)*I*a^3*ArcCot[a*x]^2 - ArcCot[a*x]^2/(3*x^3) + (2/3)*a^3*ArcCot[a*x]*Log[(2*a*x)/(I + a*x)] + (1/3)*I*a^3*PolyLog[2, -1 + (2*I)/(I + a*x)]}
{ArcCot[a*x]^2/x^5, x, 8, -(a^2/(12*x^2)) + (a*ArcCot[a*x])/(6*x^3) - (a^3*ArcCot[a*x])/(2*x) + (1/4)*a^4*ArcCot[a*x]^2 - ArcCot[a*x]^2/(4*x^4) + (2/3)*a^4*ArcTanh[1 + 2*a^2*x^2]}


(* Integrands of the form x^m*ArcCot[a*x]^3 where m is an integer *)
{x^5*ArcCot[a*x]^3, x, 26, -((19*x)/(60*a^5)) + x^3/(60*a^3) - (19*ArcCot[a*x])/(60*a^6) - (4*x^2*ArcCot[a*x])/(15*a^4) + (x^4*ArcCot[a*x])/(20*a^2) + (23*I*ArcCot[a*x]^2)/(30*a^6) + (x*ArcCot[a*x]^2)/(2*a^5) - (x^3*ArcCot[a*x]^2)/(6*a^3) + (x^5*ArcCot[a*x]^2)/(10*a) + ArcCot[a*x]^3/(6*a^6) + (1/6)*x^6*ArcCot[a*x]^3 - (23*ArcCot[a*x]*Log[(2*I)/(I - a*x)])/(15*a^6) + (23*I*PolyLog[2, 1 - (2*I)/(I - a*x)])/(30*a^6)}
{x^4*ArcCot[a*x]^3, x, 15, x^2/(20*a^3) - (9*x*ArcCot[a*x])/(10*a^4) + (x^3*ArcCot[a*x])/(10*a^2) - (9*ArcCot[a*x]^2)/(20*a^5) - (3*x^2*ArcCot[a*x]^2)/(10*a^3) + (3*x^4*ArcCot[a*x]^2)/(20*a) + (I*ArcCot[a*x]^3)/(5*a^5) + (1/5)*x^5*ArcCot[a*x]^3 - (3*ArcCot[a*x]^2*Log[(2*I)/(I - a*x)])/(5*a^5) - Log[1 + a^2*x^2]/(2*a^5) + (3*I*ArcCot[a*x]*PolyLog[2, 1 - (2*I)/(I - a*x)])/(5*a^5) - (3*PolyLog[3, 1 - (2*I)/(I - a*x)])/(10*a^5)}
{x^3*ArcCot[a*x]^3, x, 13, x/(4*a^3) + ArcCot[a*x]/(4*a^4) + (x^2*ArcCot[a*x])/(4*a^2) - (I*ArcCot[a*x]^2)/a^4 - (3*x*ArcCot[a*x]^2)/(4*a^3) + (x^3*ArcCot[a*x]^2)/(4*a) - ArcCot[a*x]^3/(4*a^4) + (1/4)*x^4*ArcCot[a*x]^3 + (2*ArcCot[a*x]*Log[(2*I)/(I - a*x)])/a^4 - (I*PolyLog[2, 1 - (2*I)/(I - a*x)])/a^4}
{x^2*ArcCot[a*x]^3, x, 8, (x*ArcCot[a*x])/a^2 + ArcCot[a*x]^2/(2*a^3) + (x^2*ArcCot[a*x]^2)/(2*a) - (I*ArcCot[a*x]^3)/(3*a^3) + (1/3)*x^3*ArcCot[a*x]^3 + (ArcCot[a*x]^2*Log[(2*I)/(I - a*x)])/a^3 + Log[1 + a^2*x^2]/(2*a^3) - (I*ArcCot[a*x]*PolyLog[2, 1 - (2*I)/(I - a*x)])/a^3 + PolyLog[3, 1 - (2*I)/(I - a*x)]/(2*a^3)}
{x*ArcCot[a*x]^3, x, 5, (3*I*ArcCot[a*x]^2)/(2*a^2) + (3*x*ArcCot[a*x]^2)/(2*a) + ArcCot[a*x]^3/(2*a^2) + (1/2)*x^2*ArcCot[a*x]^3 - (3*ArcCot[a*x]*Log[(2*I)/(I - a*x)])/a^2 + (3*I*PolyLog[2, 1 - (2*I)/(I - a*x)])/(2*a^2)}
{ArcCot[a*x]^3, x, 5, (I*ArcCot[a*x]^3)/a + x*ArcCot[a*x]^3 - (3*ArcCot[a*x]^2*Log[(2*I)/(I - a*x)])/a + (3*I*ArcCot[a*x]*PolyLog[2, 1 - (2*I)/(I - a*x)])/a - (3*PolyLog[3, 1 - (2*I)/(I - a*x)])/(2*a)}
{ArcCot[a*x]^3/x, x, 8, 2*ArcCot[a*x]^3*ArcCoth[1 - (2*I)/(I - a*x)] - (3/2)*I*ArcCot[a*x]^2*PolyLog[2, 1 - (2*I)/(I + a*x)] + (3/2)*I*ArcCot[a*x]^2*PolyLog[2, 1 - (2*a*x)/(I + a*x)] - (3/2)*ArcCot[a*x]*PolyLog[3, 1 - (2*I)/(I + a*x)] + (3/2)*ArcCot[a*x]*PolyLog[3, 1 - (2*a*x)/(I + a*x)] + (3/4)*I*PolyLog[4, 1 - (2*I)/(I + a*x)] - (3/4)*I*PolyLog[4, 1 - (2*a*x)/(I + a*x)]}
{ArcCot[a*x]^3/x^2, x, 5, (-I)*a*ArcCot[a*x]^3 - ArcCot[a*x]^3/x - 3*a*ArcCot[a*x]^2*Log[(2*a*x)/(I + a*x)] - 3*I*a*ArcCot[a*x]*PolyLog[2, -1 + (2*I)/(I + a*x)] - (3/2)*a*PolyLog[3, -1 + (2*I)/(I + a*x)]}
{ArcCot[a*x]^3/x^3, x, 5, (3/2)*I*a^2*ArcCot[a*x]^2 + (3*a*ArcCot[a*x]^2)/(2*x) - (1/2)*a^2*ArcCot[a*x]^3 - ArcCot[a*x]^3/(2*x^2) + 3*a^2*ArcCot[a*x]*Log[(2*a*x)/(I + a*x)] + (3/2)*I*a^2*PolyLog[2, -1 + (2*I)/(I + a*x)]}
{ArcCot[a*x]^3/x^4, x, 9, -((a^2*ArcCot[a*x])/x) + (1/2)*a^3*ArcCot[a*x]^2 + (a*ArcCot[a*x]^2)/(2*x^2) + (1/3)*I*a^3*ArcCot[a*x]^3 - ArcCot[a*x]^3/(3*x^3) + a^3*ArcTanh[1 + 2*a^2*x^2] + a^3*ArcCot[a*x]^2*Log[(2*a*x)/(I + a*x)] + I*a^3*ArcCot[a*x]*PolyLog[2, -1 + (2*I)/(I + a*x)] + (1/2)*a^3*PolyLog[3, -1 + (2*I)/(I + a*x)]}
{ArcCot[a*x]^3/x^5, x, 13, a^3/(4*x) - (1/4)*a^4*ArcCot[a*x] - (a^2*ArcCot[a*x])/(4*x^2) - I*a^4*ArcCot[a*x]^2 + (a*ArcCot[a*x]^2)/(4*x^3) - (3*a^3*ArcCot[a*x]^2)/(4*x) + (1/4)*a^4*ArcCot[a*x]^3 - ArcCot[a*x]^3/(4*x^4) - 2*a^4*ArcCot[a*x]*Log[(2*a*x)/(I + a*x)] - I*a^4*PolyLog[2, -1 + (2*I)/(I + a*x)]}


(* ::Subsubsection::Closed:: *)
(*Miscellaneous integrands involving inverse cotangents*)


(* Integrands of the form x^m*ArcTan[a+b*x] where m is an integer *)
{ArcCot[a + b*x], x, 1, ((a + b*x)*ArcCot[a + b*x])/b + Log[1 + (a + b*x)^2]/(2*b)}
{x*ArcCot[a + b*x], x, 5, x/(2*b) + (1/2)*x^2*ArcCot[a + b*x] - ((1 - a^2)*ArcTan[a + b*x])/(2*b^2) - (a*Log[1 + a^2 + 2*a*b*x + b^2*x^2])/(2*b^2)}
{x^2*ArcCot[a + b*x], x, 6, -((2*a*x)/(3*b^2)) + x^2/(6*b) + (1/3)*x^3*ArcCot[a + b*x] + (a*(3 - a^2)*ArcTan[a + b*x])/(3*b^3) - ((1 - 3*a^2)*Log[1 + a^2 + 2*a*b*x + b^2*x^2])/(6*b^3)}
{ArcCot[a + b*x]/x, x, 13, (-(1/2))*I*Log[x]*Log[(I - a - b*x)/(I - a)] + (1/2)*I*Log[x]*Log[(I + a + b*x)/(I + a)] + (1/2)*I*Log[x]*Log[1 - I/(a + b*x)] - (1/2)*I*Log[x]*Log[1 + I/(a + b*x)] - (1/2)*I*PolyLog[2, (b*x)/(I - a)] + (1/2)*I*PolyLog[2, -((b*x)/(I + a))]}
{ArcCot[a + b*x]/x^2, x, 6, -(ArcCot[a + b*x]/x) + (a*b*ArcTan[a + b*x])/(1 + a^2) - (b*Log[x])/(1 + a^2) + (b*Log[1 + a^2 + 2*a*b*x + b^2*x^2])/(2*(1 + a^2))}


(* Integrands of the form (a+b*x)^m*ArcCot[a+b*x] where m is an integer *)
{(a + b*x)*ArcCot[a + b*x], x, 3, (a + b*x)/(2*b) + ArcCot[a + b*x]/(2*b) + ((a + b*x)^2*ArcCot[a + b*x])/(2*b)}
{(a + b*x)^2*ArcCot[a + b*x], x, 4, (a + b*x)^2/(6*b) + ((a + b*x)^3*ArcCot[a + b*x])/(3*b) - Log[1 + (a + b*x)^2]/(6*b)}
{ArcCot[1 + x]/(2 + 2*x), x, 5, (-(1/4))*I*PolyLog[2, -(I/(1 + x))] + (1/4)*I*PolyLog[2, I/(1 + x)]}
{ArcCot[a + b*x]/(a + b*x), x, 4, -((I*PolyLog[2, -(I/(a + b*x))])/(2*b)) + (I*PolyLog[2, I/(a + b*x)])/(2*b)}
{ArcCot[a + b*x]/(a + b*x)^2, x, 3, -(ArcCot[a + b*x]/(b*(a + b*x))) + ArcTanh[1 + 2*(a + b*x)^2]/b}


(* Integrands of the form ArcCot[a+b*x]/Pn where Pn is a polynomial *)
{ArcCot[x]/(a + b*x), x, 15, (I*Log[1 - I/x]*Log[a + b*x])/(2*b) - (I*Log[1 + I/x]*Log[a + b*x])/(2*b) - (I*Log[(b*(I - x))/(a + I*b)]*Log[a + b*x])/(2*b) + (I*Log[-((b*(I + x))/(a - I*b))]*Log[a + b*x])/(2*b) + (I*PolyLog[2, (a + b*x)/(a - I*b)])/(2*b) - (I*PolyLog[2, (a + b*x)/(a + I*b)])/(2*b)}
{ArcCot[x]/(a + b*x^2), x, 31, -((I*Log[1 - I/x]*Log[a - Sqrt[-a]*Sqrt[b]*x])/(4*Sqrt[-a]*Sqrt[b])) + (I*Log[1 + I/x]*Log[a - Sqrt[-a]*Sqrt[b]*x])/(4*Sqrt[-a]*Sqrt[b]) + (I*Log[(Sqrt[b]*(I - x))/(Sqrt[-a] + I*Sqrt[b])]*Log[a - Sqrt[-a]*Sqrt[b]*x])/(4*Sqrt[-a]*Sqrt[b]) - (I*Log[-((Sqrt[b]*(I + x))/(Sqrt[-a] - I*Sqrt[b]))]*Log[a - Sqrt[-a]*Sqrt[b]*x])/(4*Sqrt[-a]*Sqrt[b]) + (I*Log[1 - I/x]*Log[a + Sqrt[-a]*Sqrt[b]*x])/(4*Sqrt[-a]*Sqrt[b]) - (I*Log[1 + I/x]*Log[a + Sqrt[-a]*Sqrt[b]*x])/(4*Sqrt[-a]*Sqrt[b]) - (I*Log[-((Sqrt[b]*(I - x))/(Sqrt[-a] - I*Sqrt[b]))]*Log[a + Sqrt[-a]*Sqrt[b]*x])/(4*Sqrt[-a]*Sqrt[b]) + (I*Log[(Sqrt[b]*(I + x))/(Sqrt[-a] + I*Sqrt[b])]*Log[a + Sqrt[-a]*Sqrt[b]*x])/(4*Sqrt[-a]*Sqrt[b]) - (I*PolyLog[2, (Sqrt[-a] - Sqrt[b]*x)/(Sqrt[-a] - I*Sqrt[b])])/(4*Sqrt[-a]*Sqrt[b]) + (I*PolyLog[2, (Sqrt[-a] - Sqrt[b]*x)/(Sqrt[-a] + I*Sqrt[b])])/(4*Sqrt[-a]*Sqrt[b]) - (I*PolyLog[2, (Sqrt[-a] + Sqrt[b]*x)/(Sqrt[-a] - I*Sqrt[b])])/(4*Sqrt[-a]*Sqrt[b]) + (I*PolyLog[2, (Sqrt[-a] + Sqrt[b]*x)/(Sqrt[-a] + I*Sqrt[b])])/(4*Sqrt[-a]*Sqrt[b])}
{ArcCot[x]/(a + b*x + c*x^2), x, 31, (I*Log[1 - I/x]*Log[b - Sqrt[b^2 - 4*a*c] + 2*c*x])/(2*Sqrt[b^2 - 4*a*c]) - (I*Log[1 + I/x]*Log[b - Sqrt[b^2 - 4*a*c] + 2*c*x])/(2*Sqrt[b^2 - 4*a*c]) - (I*Log[(2*c*(I - x))/(b + 2*I*c - Sqrt[b^2 - 4*a*c])]*Log[b - Sqrt[b^2 - 4*a*c] + 2*c*x])/(2*Sqrt[b^2 - 4*a*c]) + (I*Log[-((2*c*(I + x))/(b - 2*I*c - Sqrt[b^2 - 4*a*c]))]*Log[b - Sqrt[b^2 - 4*a*c] + 2*c*x])/(2*Sqrt[b^2 - 4*a*c]) - (I*Log[1 - I/x]*Log[b + Sqrt[b^2 - 4*a*c] + 2*c*x])/(2*Sqrt[b^2 - 4*a*c]) + (I*Log[1 + I/x]*Log[b + Sqrt[b^2 - 4*a*c] + 2*c*x])/(2*Sqrt[b^2 - 4*a*c]) + (I*Log[(2*c*(I - x))/(b + 2*I*c + Sqrt[b^2 - 4*a*c])]*Log[b + Sqrt[b^2 - 4*a*c] + 2*c*x])/(2*Sqrt[b^2 - 4*a*c]) - (I*Log[-((2*c*(I + x))/(b - 2*I*c + Sqrt[b^2 - 4*a*c]))]*Log[b + Sqrt[b^2 - 4*a*c] + 2*c*x])/(2*Sqrt[b^2 - 4*a*c]) + (I*PolyLog[2, (b - Sqrt[b^2 - 4*a*c] + 2*c*x)/(b - 2*I*c - Sqrt[b^2 - 4*a*c])])/(2*Sqrt[b^2 - 4*a*c]) - (I*PolyLog[2, (b - Sqrt[b^2 - 4*a*c] + 2*c*x)/(b + 2*I*c - Sqrt[b^2 - 4*a*c])])/(2*Sqrt[b^2 - 4*a*c]) - (I*PolyLog[2, (b + Sqrt[b^2 - 4*a*c] + 2*c*x)/(b - 2*I*c + Sqrt[b^2 - 4*a*c])])/(2*Sqrt[b^2 - 4*a*c]) + (I*PolyLog[2, (b + Sqrt[b^2 - 4*a*c] + 2*c*x)/(b + 2*I*c + Sqrt[b^2 - 4*a*c])])/(2*Sqrt[b^2 - 4*a*c])}

{ArcCot[d + e*x]/(a + b*x), x, 13, -((I*Log[a + b*x]*Log[(b*(I - d - e*x))/(b*(I - d) + a*e)])/(2*b)) + (I*Log[a + b*x]*Log[(b*(I + d + e*x))/(b*(I + d) - a*e)])/(2*b) + (I*Log[a + b*x]*Log[1 - I/(d + e*x)])/(2*b) - (I*Log[a + b*x]*Log[1 + I/(d + e*x)])/(2*b) + (I*PolyLog[2, -((e*(a + b*x))/(b*(I + d) - a*e))])/(2*b) - (I*PolyLog[2, (e*(a + b*x))/(b*(I - d) + a*e)])/(2*b)}
{ArcCot[d + e*x]/(a + b*x^2), x, 27, -((I*Log[a + Sqrt[-a]*Sqrt[b]*x]*Log[(Sqrt[b]*(I - d - e*x))/(Sqrt[b]*(I - d) - Sqrt[-a]*e)])/(4*Sqrt[-a]*Sqrt[b])) + (I*Log[a - Sqrt[-a]*Sqrt[b]*x]*Log[(Sqrt[b]*(I - d - e*x))/(Sqrt[b]*(I - d) + Sqrt[-a]*e)])/(4*Sqrt[-a]*Sqrt[b]) - (I*Log[a - Sqrt[-a]*Sqrt[b]*x]*Log[(Sqrt[b]*(I + d + e*x))/(Sqrt[b]*(I + d) - Sqrt[-a]*e)])/(4*Sqrt[-a]*Sqrt[b]) + (I*Log[a + Sqrt[-a]*Sqrt[b]*x]*Log[(Sqrt[b]*(I + d + e*x))/(Sqrt[b]*(I + d) + Sqrt[-a]*e)])/(4*Sqrt[-a]*Sqrt[b]) - (I*Log[a - Sqrt[-a]*Sqrt[b]*x]*Log[1 - I/(d + e*x)])/(4*Sqrt[-a]*Sqrt[b]) + (I*Log[a + Sqrt[-a]*Sqrt[b]*x]*Log[1 - I/(d + e*x)])/(4*Sqrt[-a]*Sqrt[b]) + (I*Log[a - Sqrt[-a]*Sqrt[b]*x]*Log[1 + I/(d + e*x)])/(4*Sqrt[-a]*Sqrt[b]) - (I*Log[a + Sqrt[-a]*Sqrt[b]*x]*Log[1 + I/(d + e*x)])/(4*Sqrt[-a]*Sqrt[b]) - (I*PolyLog[2, -((e*(Sqrt[-a] - Sqrt[b]*x))/(Sqrt[b]*(I - d) - Sqrt[-a]*e))])/(4*Sqrt[-a]*Sqrt[b]) + (I*PolyLog[2, (e*(Sqrt[-a] - Sqrt[b]*x))/(Sqrt[b]*(I + d) + Sqrt[-a]*e)])/(4*Sqrt[-a]*Sqrt[b]) - (I*PolyLog[2, -((e*(Sqrt[-a] + Sqrt[b]*x))/(Sqrt[b]*(I + d) - Sqrt[-a]*e))])/(4*Sqrt[-a]*Sqrt[b]) + (I*PolyLog[2, (e*(Sqrt[-a] + Sqrt[b]*x))/(Sqrt[b]*(I - d) + Sqrt[-a]*e)])/(4*Sqrt[-a]*Sqrt[b])}
{ArcCot[d + e*x]/(a + b*x + c*x^2), x, 27, -((I*Log[b - Sqrt[b^2 - 4*a*c] + 2*c*x]*Log[(2*c*(I - d - e*x))/(2*c*(I - d) + (b - Sqrt[b^2 - 4*a*c])*e)])/(2*Sqrt[b^2 - 4*a*c])) + (I*Log[b + Sqrt[b^2 - 4*a*c] + 2*c*x]*Log[(2*c*(I - d - e*x))/(2*c*(I - d) + (b + Sqrt[b^2 - 4*a*c])*e)])/(2*Sqrt[b^2 - 4*a*c]) + (I*Log[b - Sqrt[b^2 - 4*a*c] + 2*c*x]*Log[(2*c*(I + d + e*x))/(2*c*(I + d) - (b - Sqrt[b^2 - 4*a*c])*e)])/(2*Sqrt[b^2 - 4*a*c]) - (I*Log[b + Sqrt[b^2 - 4*a*c] + 2*c*x]*Log[(2*c*(I + d + e*x))/(2*c*(I + d) - (b + Sqrt[b^2 - 4*a*c])*e)])/(2*Sqrt[b^2 - 4*a*c]) + (I*Log[b - Sqrt[b^2 - 4*a*c] + 2*c*x]*Log[1 - I/(d + e*x)])/(2*Sqrt[b^2 - 4*a*c]) - (I*Log[b + Sqrt[b^2 - 4*a*c] + 2*c*x]*Log[1 - I/(d + e*x)])/(2*Sqrt[b^2 - 4*a*c]) - (I*Log[b - Sqrt[b^2 - 4*a*c] + 2*c*x]*Log[1 + I/(d + e*x)])/(2*Sqrt[b^2 - 4*a*c]) + (I*Log[b + Sqrt[b^2 - 4*a*c] + 2*c*x]*Log[1 + I/(d + e*x)])/(2*Sqrt[b^2 - 4*a*c]) + (I*PolyLog[2, -((e*(b - Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c*(I + d) - (b - Sqrt[b^2 - 4*a*c])*e))])/(2*Sqrt[b^2 - 4*a*c]) - (I*PolyLog[2, (e*(b - Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c*(I - d) + (b - Sqrt[b^2 - 4*a*c])*e)])/(2*Sqrt[b^2 - 4*a*c]) - (I*PolyLog[2, -((e*(b + Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c*(I + d) - (b + Sqrt[b^2 - 4*a*c])*e))])/(2*Sqrt[b^2 - 4*a*c]) + (I*PolyLog[2, (e*(b + Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c*(I - d) + (b + Sqrt[b^2 - 4*a*c])*e)])/(2*Sqrt[b^2 - 4*a*c])}


(* Integrands of the form ArcCot[x]^m*(1+x^2)^n where n is an integer *)
{1/((1 + x^2)*ArcCot[x]), x, 1, -Log[ArcCot[x]]}
{ArcCot[x]^n/(1 + x^2), x, 1, -(ArcCot[x]^(1 + n)/(1 + n))}
{ArcCot[x]/(1 + x^2)^2, x, 2, -(1/(4*(1 + x^2))) + (x*ArcCot[x])/(2*(1 + x^2)) - ArcCot[x]^2/4}
{ArcCot[x]^2/(1 + x^2)^2, x, 4, -(x/(4*(1 + x^2))) - ArcCot[x]/(2*(1 + x^2)) + (x*ArcCot[x]^2)/(2*(1 + x^2)) - ArcCot[x]^3/6 - ArcTan[x]/4}

{1/((a + a*x^2)*(b - 2*b*ArcCot[x])), x, 3, Log[1 - 2*ArcCot[x]]/(2*a*b)}


{(x*ArcCot[x])/(1 + x^2), x, 3, (1/2)*I*ArcCot[x]^2 - ArcCot[x]*Log[(2*I)/(I - x)] + (1/2)*I*PolyLog[2, 1 - (2*I)/(I - x)]}
{(x*ArcCot[x])/(1 + x^2)^2, x, 3, -(x/(4*(1 + x^2))) - ArcCot[x]/(2*(1 + x^2)) - ArcTan[x]/4}
{(x*ArcCot[x])/(1 + x^2)^3, x, 4, -(x/(16*(1 + x^2)^2)) - (3*x)/(32*(1 + x^2)) - ArcCot[x]/(4*(1 + x^2)^2) - (3*ArcTan[x])/32}


(* Integrands of the form ArcCot[x]/(a+b*x^2)^n where n is a half-integer *)
{ArcCot[x]/(a + b*x^2)^(3/2), x, 3, (x*ArcCot[x])/(a*Sqrt[a + b*x^2]) - ArcTanh[Sqrt[a + b*x^2]/Sqrt[a - b]]/(a*Sqrt[a - b])}
{ArcCot[x]/(a + b*x^2)^(5/2), x, 8, 1/(3*a*(a - b)*Sqrt[a + b*x^2]) + (x*(3*a + 2*b*x^2)*ArcCot[x])/(3*a^2*(a + b*x^2)^(3/2)) - ((3*a - 2*b)*ArcTanh[Sqrt[a + b*x^2]/Sqrt[a - b]])/(3*a^2*(a - b)^(3/2))}
{ArcCot[x]/(a + b*x^2)^(7/2), x, 8, 1/(15*a*(a - b)*(a + b*x^2)^(3/2)) + (7*a - 4*b)/(15*a^2*(a - b)^2*Sqrt[a + b*x^2]) + (x*(8*(a + b*x^2)^2 + a*(7*a + 4*b*x^2))*ArcCot[x])/(15*a^3*(a + b*x^2)^(5/2)) - ((15*a^2 - 20*a*b + 8*b^2)*ArcTanh[Sqrt[a + b*x^2]/Sqrt[a - b]])/(15*a^3*(a - b)^(5/2))}

{ArcCot[x]*(a + a*x^2)^(1/2), x, 3, (1/2)*Sqrt[a + a*x^2] + (1/2)*x*Sqrt[a + a*x^2]*ArcCot[x] - (I*a*Sqrt[1 + x^2]*(2*ArcCot[x]*ArcTan[Sqrt[1 + I*x]/Sqrt[1 - I*x]] + PolyLog[2, -((I*Sqrt[1 + I*x])/Sqrt[1 - I*x])] - PolyLog[2, (I*Sqrt[1 + I*x])/Sqrt[1 - I*x]]))/(2*Sqrt[a + a*x^2])}
{ArcCot[x]/(a + a*x^2)^(1/2), x, 2, -((I*Sqrt[1 + x^2]*(2*ArcCot[x]*ArcTan[Sqrt[1 + I*x]/Sqrt[1 - I*x]] + PolyLog[2, -((I*Sqrt[1 + I*x])/Sqrt[1 - I*x])] - PolyLog[2, (I*Sqrt[1 + I*x])/Sqrt[1 - I*x]]))/Sqrt[a + a*x^2])}
{ArcCot[x]/(a + a*x^2)^(3/2), x, 1, -(1/(a*Sqrt[a + a*x^2])) + (x*ArcCot[x])/(a*Sqrt[a + a*x^2])}
{ArcCot[x]/(a + a*x^2)^(5/2), x, 2, -(1/(9*a*(a + a*x^2)^(3/2))) - 2/(3*a^2*Sqrt[a + a*x^2]) + (x*ArcCot[x])/(3*a*(a + a*x^2)^(3/2)) + (2*x*ArcCot[x])/(3*a^2*Sqrt[a + a*x^2])}
{ArcCot[x]/(a + a*x^2)^(7/2), x, 3, -(1/(25*a*(a + a*x^2)^(5/2))) - 4/(45*a^2*(a + a*x^2)^(3/2)) - 8/(15*a^3*Sqrt[a + a*x^2]) + (x*ArcCot[x])/(5*a*(a + a*x^2)^(5/2)) + (4*x*ArcCot[x])/(15*a^2*(a + a*x^2)^(3/2)) + (8*x*ArcCot[x])/(15*a^3*Sqrt[a + a*x^2])}


(* Integrands of the form x^m*ArcCot[Sqrt[x]] where m is an integer *)
{ArcCot[Sqrt[x]], x, 4, Sqrt[x] + x*ArcCot[Sqrt[x]] - ArcTan[Sqrt[x]]}
{x*ArcCot[Sqrt[x]], x, 5, -(Sqrt[x]/2) + x^(3/2)/6 + (1/2)*x^2*ArcCot[Sqrt[x]] + ArcTan[Sqrt[x]]/2}
{x^2*ArcCot[Sqrt[x]], x, 6, Sqrt[x]/3 - x^(3/2)/9 + x^(5/2)/15 + (1/3)*x^3*ArcCot[Sqrt[x]] - ArcTan[Sqrt[x]]/3}
{ArcCot[Sqrt[x]]/x, x, 3, (-I)*PolyLog[2, -(I/Sqrt[x])] + I*PolyLog[2, I/Sqrt[x]]}
{ArcCot[Sqrt[x]]/x^2, x, 4, 1/Sqrt[x] - ArcCot[Sqrt[x]]/x + ArcTan[Sqrt[x]]}
{ArcCot[Sqrt[x]]/x^3, x, 5, 1/(6*x^(3/2)) - 1/(2*Sqrt[x]) - ArcCot[Sqrt[x]]/(2*x^2) - ArcTan[Sqrt[x]]/2}

{Sqrt[x]*ArcCot[Sqrt[x]], x, 5, x/3 + (2/3)*x^(3/2)*ArcCot[Sqrt[x]] - (1/3)*Log[1 + x]}
{x^(3/2)*ArcCot[Sqrt[x]], x, 6, -(x/5) + x^2/10 + (2/5)*x^(5/2)*ArcCot[Sqrt[x]] + (1/5)*Log[1 + x]}
{ArcCot[Sqrt[x]]/Sqrt[x], x, 2, 2*Sqrt[x]*ArcCot[Sqrt[x]] + Log[1 + x]}
{ArcCot[Sqrt[x]]/x^(3/2), x, 3, -((2*ArcCot[Sqrt[x]])/Sqrt[x]) + 2*ArcTanh[1 + 2*x]}


(* ::Subsection::Closed:: *)
(*Integrands involving inverse trig functions of exponentials*)


(* Integrands of the form x^m*ArcCot[E^x] *)
{ArcCot[E^x], x, 3, (-(1/2))*I*PolyLog[2, -I/E^x] + (1/2)*I*PolyLog[2, I/E^x]}
{x*ArcCot[E^x], x, 5, (-(1/2))*I*x*PolyLog[2, -I/E^x] + (1/2)*I*x*PolyLog[2, I/E^x] - (1/2)*I*PolyLog[3, -I/E^x] + (1/2)*I*PolyLog[3, I/E^x]}
{x^2*ArcCot[E^x], x, 7, (-(1/2))*I*x^2*PolyLog[2, -I/E^x] + (1/2)*I*x^2*PolyLog[2, I/E^x] - I*x*PolyLog[3, -I/E^x] + I*x*PolyLog[3, I/E^x] - I*PolyLog[4, -I/E^x] + I*PolyLog[4, I/E^x]}


(* Integrands of the form x^m*ArcCot[E^(a+b*x)] *)
{ArcCot[E^(a + b*x)], x, 3, -((I*PolyLog[2, (-I)*E^(-a - b*x)])/(2*b)) + (I*PolyLog[2, I*E^(-a - b*x)])/(2*b)}
{x*ArcCot[E^(a + b*x)], x, 5, -((I*x*PolyLog[2, (-I)*E^(-a - b*x)])/(2*b)) + (I*x*PolyLog[2, I*E^(-a - b*x)])/(2*b) - (I*PolyLog[3, (-I)*E^(-a - b*x)])/(2*b^2) + (I*PolyLog[3, I*E^(-a - b*x)])/(2*b^2)}
{x^2*ArcCot[E^(a + b*x)], x, 7, -((I*x^2*PolyLog[2, (-I)*E^(-a - b*x)])/(2*b)) + (I*x^2*PolyLog[2, I*E^(-a - b*x)])/(2*b) - (I*x*PolyLog[3, (-I)*E^(-a - b*x)])/b^2 + (I*x*PolyLog[3, I*E^(-a - b*x)])/b^2 - (I*PolyLog[4, (-I)*E^(-a - b*x)])/b^3 + (I*PolyLog[4, I*E^(-a - b*x)])/b^3}


(* Integrands of the form x^m*ArcCot[a+b*f^(c+d*x)] *)
{ArcCot[a + b*f^(c + d*x)], x, -15, x*ArcCot[a + b*f^(c + d*x)] - (1/2)*I*x*Log[1 - (b*f^(c + d*x))/(I - a)] + (1/2)*I*x*Log[1 + (b*f^(c + d*x))/(I + a)] - (I*PolyLog[2, (b*f^(c + d*x))/(I - a)])/(2*d*Log[f]) + (I*PolyLog[2, -((b*f^(c + d*x))/(I + a))])/(2*d*Log[f])}
{x*ArcCot[a + b*f^(c + d*x)], x, 25, (-(1/4))*I*x^2*Log[1 - (b*f^(c + d*x))/(I - a)] + (1/4)*I*x^2*Log[1 + (b*f^(c + d*x))/(I + a)] + (1/4)*I*x^2*Log[1 - I/(a + b*f^(c + d*x))] - (1/4)*I*x^2*Log[1 + I/(a + b*f^(c + d*x))] - (I*x*PolyLog[2, (b*f^(c + d*x))/(I - a)])/(2*d*Log[f]) + (I*x*PolyLog[2, -((b*f^(c + d*x))/(I + a))])/(2*d*Log[f]) + (I*PolyLog[3, (b*f^(c + d*x))/(I - a)])/(2*d^2*Log[f]^2) - (I*PolyLog[3, -((b*f^(c + d*x))/(I + a))])/(2*d^2*Log[f]^2)}
{x^2*ArcCot[a + b*f^(c + d*x)], x, 29, (-(1/6))*I*x^3*Log[1 - (b*f^(c + d*x))/(I - a)] + (1/6)*I*x^3*Log[1 + (b*f^(c + d*x))/(I + a)] + (1/6)*I*x^3*Log[1 - I/(a + b*f^(c + d*x))] - (1/6)*I*x^3*Log[1 + I/(a + b*f^(c + d*x))] - (I*x^2*PolyLog[2, (b*f^(c + d*x))/(I - a)])/(2*d*Log[f]) + (I*x^2*PolyLog[2, -((b*f^(c + d*x))/(I + a))])/(2*d*Log[f]) + (I*x*PolyLog[3, (b*f^(c + d*x))/(I - a)])/(d^2*Log[f]^2) - (I*x*PolyLog[3, -((b*f^(c + d*x))/(I + a))])/(d^2*Log[f]^2) - (I*PolyLog[4, (b*f^(c + d*x))/(I - a)])/(d^3*Log[f]^3) + (I*PolyLog[4, -((b*f^(c + d*x))/(I + a))])/(d^3*Log[f]^3)}


{ArcCot[E^x]/E^x, x, 3, -x - ArcCot[E^x]/E^x + (1/2)*Log[1 + E^(2*x)]}


(* ::Subsection::Closed:: *)
(*Integrands involving inverse trig functions of trig functions*)


(* Integrands of the form ArcCot[a+b*Trig[x]] *)
{ArcCot[Tan[x]], x, 2, x^2/2 + x*ArcCot[Tan[x]]}
{ArcCot[b*Tan[x]], x, 12, x*ArcCot[b*Tan[x]] - (1/2)*I*x*Log[1 + ((1 - b^2)*E^(2*I*x))/(1 - 2*b + b^2)] + (1/2)*I*x*Log[1 + ((1 - b^2)*E^(2*I*x))/(1 + 2*b + b^2)] - (1/4)*PolyLog[2, -(((1 - b^2)*E^(2*I*x))/(1 - 2*b + b^2))] + (1/4)*PolyLog[2, -(((1 - b^2)*E^(2*I*x))/(1 + 2*b + b^2))]}
(* {ArcCot[a+b*Tan[x]], x, 30, (-(1/4))*Log[-I + Tan[x]]*Log[(I - a - b*Tan[x])/(I - a - I*b)] + (1/4)*Log[I + Tan[x]]*Log[(I - a - b*Tan[x])/(I - a + I*b)] - (1/4)*Log[I + Tan[x]]*Log[(I + a + b*Tan[x])/(I + a - I*b)] + (1/4)*Log[-I + Tan[x]]*Log[(I + a + b*Tan[x])/(I + a + I*b)] + (1/4)*Log[-I + Tan[x]]*Log[1 - I/(a + b*Tan[x])] - (1/4)*Log[I + Tan[x]]*Log[1 - I/(a + b*Tan[x])] - (1/4)*Log[-I + Tan[x]]*Log[1 + I/(a + b*Tan[x])] + (1/4)*Log[I + Tan[x]]*Log[1 + I/(a + b*Tan[x])] - (1/4)*PolyLog[2, -((b*(I - Tan[x]))/(I - a - I*b))] + (1/4)*PolyLog[2, (b*(I - Tan[x]))/(I + a + I*b)] - (1/4)*PolyLog[2, -((b*(I + Tan[x]))/(I + a - I*b))] + (1/4)*PolyLog[2, (b*(I + Tan[x]))/(I - a + I*b)]} *)

{ArcCot[b*Cot[x]], x, 12, x*ArcCot[b*Cot[x]] + (1/2)*I*x*Log[1 - ((1 - b^2)*E^(2*I*x))/(1 - 2*b + b^2)] - (1/2)*I*x*Log[1 - ((1 - b^2)*E^(2*I*x))/(1 + 2*b + b^2)] + (1/4)*PolyLog[2, ((1 - b^2)*E^(2*I*x))/(1 - 2*b + b^2)] - (1/4)*PolyLog[2, ((1 - b^2)*E^(2*I*x))/(1 + 2*b + b^2)]}
(* {ArcCot[a+b*Cot[x]], x, 30, (1/4)*Log[-I + Cot[x]]*Log[(I - a - b*Cot[x])/(I - a - I*b)] - (1/4)*Log[I + Cot[x]]*Log[(I - a - b*Cot[x])/(I - a + I*b)] + (1/4)*Log[I + Cot[x]]*Log[(I + a + b*Cot[x])/(I + a - I*b)] - (1/4)*Log[-I + Cot[x]]*Log[(I + a + b*Cot[x])/(I + a + I*b)] - (1/4)*Log[-I + Cot[x]]*Log[1 - I/(a + b*Cot[x])] + (1/4)*Log[I + Cot[x]]*Log[1 - I/(a + b*Cot[x])] + (1/4)*Log[-I + Cot[x]]*Log[1 + I/(a + b*Cot[x])] - (1/4)*Log[I + Cot[x]]*Log[1 + I/(a + b*Cot[x])] + (1/4)*PolyLog[2, -((b*(I - Cot[x]))/(I - a - I*b))] - (1/4)*PolyLog[2, (b*(I - Cot[x]))/(I + a + I*b)] + (1/4)*PolyLog[2, -((b*(I + Cot[x]))/(I + a - I*b))] - (1/4)*PolyLog[2, (b*(I + Cot[x]))/(I - a + I*b)]} *)


(* ::Subsection::Closed:: *)
(*Integrands involving exponentials of inverse trig functions*)


(* Integrands of the form x^m*E^ArcCot[x] where m is an integer *)
{E^ArcCot[x], x, 2, -Subst[Int[E^x*Csc[x]^2, x], x, ArcCot[x]]}


(* Integrands of the form E^ArcCot[x]/(a+a*x^2)^n *)
{E^ArcCot[x]/(a + a*x^2), x, 2, -(E^ArcCot[x]/a)}
{E^ArcCot[x]/(a + a*x^2)^2, x, 3, -((2*E^ArcCot[x])/(5*a^2)) - E^ArcCot[x]/(5*a^2*(1 + x^2)) + (2*E^ArcCot[x]*x)/(5*a^2*(1 + x^2))}
{E^ArcCot[x]/(a + a*x^2)^3, x, 4, -((24*E^ArcCot[x])/(85*a^3)) - E^ArcCot[x]/(17*a^3*(1 + x^2)^2) + (4*E^ArcCot[x]*x)/(17*a^3*(1 + x^2)^2) - (12*E^ArcCot[x])/(85*a^3*(1 + x^2)) + (24*E^ArcCot[x]*x)/(85*a^3*(1 + x^2))}

{E^ArcCot[x]/(a + a*x^2)^(3/2), x, 5, (E^ArcCot[x]*(1 - 1/x)*x)/(2*a*Sqrt[a*(1 + x^2)])}
{E^ArcCot[x]/(a + a*x^2)^(5/2), x, 6, (E^ArcCot[x]*(-4 + 6*x - 3*x^2 + 3*x^3))/(10*a*(a*(1 + x^2))^(3/2)), (E^ArcCot[x]*x*(3 - 3/x + 3/(1 + x^2) - 1/(x*(1 + x^2))))/(10*a^2*Sqrt[a*(1 + x^2)])}
{E^ArcCot[x]/(a + a*x^2)^(7/2), x, 7, (E^ArcCot[x]*(-9 + 17*x - 14*x^2 + 18*x^3 - 6*x^4 + 6*x^5))/(26*a*(a*(1 + x^2))^(5/2)), (E^ArcCot[x]*x*(6 - 6/x + 5/(1 + x^2)^2 - 1/(x*(1 + x^2)^2) + 6/(1 + x^2) - 2/(x*(1 + x^2))))/(26*a^3*Sqrt[a*(1 + x^2)])}


(* ::Subsection::Closed:: *)
(*Miscellaneous problems*)


{ArcCot[1/x], x, 1, x*ArcTan[x] - Log[1 + x^2]/2}


{ArcCot[a + b*x]/((a*d)/b + d*x), x, 6, -((I*PolyLog[2, -(I/(a + b*x))])/(2*d)) + (I*PolyLog[2, I/(a + b*x)])/(2*d)}


{ArcCot[a*x^n]/x, x, 3, -((I*PolyLog[2, -(I/(x^n*a))])/(2*n)) + (I*PolyLog[2, I/(x^n*a)])/(2*n)}

{ArcCot[a*x^5]/x, x, 3, (-(1/10))*I*PolyLog[2, -(I/(a*x^5))] + (1/10)*I*PolyLog[2, I/(a*x^5)]}


{x^3*ArcCot[a + b*x^4], x, 2, ((a + b*x^4)*ArcCot[a + b*x^4])/(4*b) + Log[1 + (a + b*x^4)^2]/(8*b)}

{x^(n-1)*ArcCot[a + b*x^n], x, 2, ((a + b*x^n)*ArcCot[a + b*x^n])/(b*n) + Log[1 + (a + b*x^n)^2]/(2*b*n)}
