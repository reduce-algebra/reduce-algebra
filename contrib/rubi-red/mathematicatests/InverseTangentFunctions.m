(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Inverse Tangents*)


(* ::Subsection::Closed:: *)
(*Integrands involving inverse tangents*)


(* ::Subsubsection::Closed:: *)
(*Integrands of the form x^m ArcTan[a x]^n*)


(* Integrands of the form x^m*ArcTan[a*x] where m is an integer *)
{x^5*ArcTan[a*x], x, 6, -(x/(6*a^5)) + x^3/(18*a^3) - x^5/(30*a) + ArcTan[a*x]/(6*a^6) + (1/6)*x^6*ArcTan[a*x]}
{x^4*ArcTan[a*x], x, 5, x^2/(10*a^3) - x^4/(20*a) + (1/5)*x^5*ArcTan[a*x] - Log[1 + a^2*x^2]/(10*a^5)}
{x^3*ArcTan[a*x], x, 4, x/(4*a^3) - x^3/(12*a) - ArcTan[a*x]/(4*a^4) + (1/4)*x^4*ArcTan[a*x]}
{x^2*ArcTan[a*x], x, 3, -(x^2/(6*a)) + (1/3)*x^3*ArcTan[a*x] + Log[1 + a^2*x^2]/(6*a^3)}
{x*ArcTan[a*x], x, 2, -(x/(2*a)) + ArcTan[a*x]/(2*a^2) + (1/2)*x^2*ArcTan[a*x]}
{ArcTan[a*x], x, 1, x*ArcTan[a*x] - Log[1 + a^2*x^2]/(2*a)}
{ArcTan[a*x]/x, x, 3, (1/2)*I*PolyLog[2, (-I)*a*x] - (1/2)*I*PolyLog[2, I*a*x]}
{ArcTan[a*x]/x^2, x, 2, -(ArcTan[a*x]/x) - a*ArcTanh[1 + 2*a^2*x^2]}
{ArcTan[a*x]/x^3, x, 2, -(a/(2*x)) - (1/2)*a^2*ArcTan[a*x] - ArcTan[a*x]/(2*x^2)}
{ArcTan[a*x]/x^4, x, 4, -(a/(6*x^2)) - ArcTan[a*x]/(3*x^3) + (1/3)*a^3*ArcTanh[1 + 2*a^2*x^2]}
{ArcTan[a*x]/x^5, x, 4, -(a/(12*x^3)) + a^3/(4*x) + (1/4)*a^4*ArcTan[a*x] - ArcTan[a*x]/(4*x^4)}


(* Integrands of the form x^m*ArcTan[a*x]^2 where m is an integer *)
{x^5*ArcTan[a*x]^2, x, 12, -((4*x^2)/(45*a^4)) + x^4/(60*a^2) - (x*ArcTan[a*x])/(3*a^5) + (x^3*ArcTan[a*x])/(9*a^3) - (x^5*ArcTan[a*x])/(15*a) + ArcTan[a*x]^2/(6*a^6) + (1/6)*x^6*ArcTan[a*x]^2 + (23*Log[1 + a^2*x^2])/(90*a^6)}
{x^4*ArcTan[a*x]^2, x, 12, -((3*x)/(10*a^4)) + x^3/(30*a^2) + (3*ArcTan[a*x])/(10*a^5) + (x^2*ArcTan[a*x])/(5*a^3) - (x^4*ArcTan[a*x])/(10*a) + (I*ArcTan[a*x]^2)/(5*a^5) + (1/5)*x^5*ArcTan[a*x]^2 + (2*ArcTan[a*x]*Log[(2*I)/(I - a*x)])/(5*a^5) + (I*PolyLog[2, 1 - (2*I)/(I - a*x)])/(5*a^5)}
{x^3*ArcTan[a*x]^2, x, 6, x^2/(12*a^2) + (x*ArcTan[a*x])/(2*a^3) - (x^3*ArcTan[a*x])/(6*a) - ArcTan[a*x]^2/(4*a^4) + (1/4)*x^4*ArcTan[a*x]^2 - Log[1 + a^2*x^2]/(3*a^4)}
{x^2*ArcTan[a*x]^2, x, 7, x/(3*a^2) - ArcTan[a*x]/(3*a^3) - (x^2*ArcTan[a*x])/(3*a) - (I*ArcTan[a*x]^2)/(3*a^3) + (1/3)*x^3*ArcTan[a*x]^2 - (2*ArcTan[a*x]*Log[(2*I)/(I - a*x)])/(3*a^3) - (I*PolyLog[2, 1 - (2*I)/(I - a*x)])/(3*a^3)}
{x*ArcTan[a*x]^2, x, 2, -((x*ArcTan[a*x])/a) + ArcTan[a*x]^2/(2*a^2) + (1/2)*x^2*ArcTan[a*x]^2 + Log[1 + a^2*x^2]/(2*a^2)}
{ArcTan[a*x]^2, x, 4, (I*ArcTan[a*x]^2)/a + x*ArcTan[a*x]^2 + (2*ArcTan[a*x]*Log[(2*I)/(I - a*x)])/a + (I*PolyLog[2, 1 - (2*I)/(I - a*x)])/a}
{ArcTan[a*x]^2/x, x, 6, 2*ArcTan[a*x]^2*ArcTanh[1 - (2*I)/(I - a*x)] - I*ArcTan[a*x]*PolyLog[2, 1 - (2*I)/(I - a*x)] + I*ArcTan[a*x]*PolyLog[2, -1 + (2*I)/(I - a*x)] - (1/2)*PolyLog[3, 1 - (2*I)/(I - a*x)] + (1/2)*PolyLog[3, -1 + (2*I)/(I - a*x)]}
{ArcTan[a*x]^2/x^2, x, 4, (-I)*a*ArcTan[a*x]^2 - ArcTan[a*x]^2/x + 2*a*ArcTan[a*x]*Log[(2*a*x)/(I + a*x)] - I*a*PolyLog[2, -1 + (2*I)/(I + a*x)]}
{ArcTan[a*x]^2/x^3, x, 3, -((a*ArcTan[a*x])/x) - (1/2)*a^2*ArcTan[a*x]^2 - ArcTan[a*x]^2/(2*x^2) - a^2*ArcTanh[1 + 2*a^2*x^2]}
{ArcTan[a*x]^2/x^4, x, 7, -(a^2/(3*x)) - (1/3)*a^3*ArcTan[a*x] - (a*ArcTan[a*x])/(3*x^2) + (1/3)*I*a^3*ArcTan[a*x]^2 - ArcTan[a*x]^2/(3*x^3) - (2/3)*a^3*ArcTan[a*x]*Log[(2*a*x)/(I + a*x)] + (1/3)*I*a^3*PolyLog[2, -1 + (2*I)/(I + a*x)]}
{ArcTan[a*x]^2/x^5, x, 8, -(a^2/(12*x^2)) - (a*ArcTan[a*x])/(6*x^3) + (a^3*ArcTan[a*x])/(2*x) + (1/4)*a^4*ArcTan[a*x]^2 - ArcTan[a*x]^2/(4*x^4) + (2/3)*a^4*ArcTanh[1 + 2*a^2*x^2]}


(* Integrands of the form x^m*ArcTan[a*x]^3 where m is an integer *)
{x^5*ArcTan[a*x]^3, x, 26, (19*x)/(60*a^5) - x^3/(60*a^3) - (19*ArcTan[a*x])/(60*a^6) - (4*x^2*ArcTan[a*x])/(15*a^4) + (x^4*ArcTan[a*x])/(20*a^2) - (23*I*ArcTan[a*x]^2)/(30*a^6) - (x*ArcTan[a*x]^2)/(2*a^5) + (x^3*ArcTan[a*x]^2)/(6*a^3) - (x^5*ArcTan[a*x]^2)/(10*a) + ArcTan[a*x]^3/(6*a^6) + (1/6)*x^6*ArcTan[a*x]^3 - (23*ArcTan[a*x]*Log[(2*I)/(I - a*x)])/(15*a^6) - (23*I*PolyLog[2, 1 - (2*I)/(I - a*x)])/(30*a^6)}
{x^4*ArcTan[a*x]^3, x, 15, -(x^2/(20*a^3)) - (9*x*ArcTan[a*x])/(10*a^4) + (x^3*ArcTan[a*x])/(10*a^2) + (9*ArcTan[a*x]^2)/(20*a^5) + (3*x^2*ArcTan[a*x]^2)/(10*a^3) - (3*x^4*ArcTan[a*x]^2)/(20*a) + (I*ArcTan[a*x]^3)/(5*a^5) + (1/5)*x^5*ArcTan[a*x]^3 + (3*ArcTan[a*x]^2*Log[(2*I)/(I - a*x)])/(5*a^5) + Log[1 + a^2*x^2]/(2*a^5) + (3*I*ArcTan[a*x]*PolyLog[2, 1 - (2*I)/(I - a*x)])/(5*a^5) + (3*PolyLog[3, 1 - (2*I)/(I - a*x)])/(10*a^5)}
{x^3*ArcTan[a*x]^3, x, 13, -(x/(4*a^3)) + ArcTan[a*x]/(4*a^4) + (x^2*ArcTan[a*x])/(4*a^2) + (I*ArcTan[a*x]^2)/a^4 + (3*x*ArcTan[a*x]^2)/(4*a^3) - (x^3*ArcTan[a*x]^2)/(4*a) - ArcTan[a*x]^3/(4*a^4) + (1/4)*x^4*ArcTan[a*x]^3 + (2*ArcTan[a*x]*Log[(2*I)/(I - a*x)])/a^4 + (I*PolyLog[2, 1 - (2*I)/(I - a*x)])/a^4}
{x^2*ArcTan[a*x]^3, x, 8, (x*ArcTan[a*x])/a^2 - ArcTan[a*x]^2/(2*a^3) - (x^2*ArcTan[a*x]^2)/(2*a) - (I*ArcTan[a*x]^3)/(3*a^3) + (1/3)*x^3*ArcTan[a*x]^3 - (ArcTan[a*x]^2*Log[(2*I)/(I - a*x)])/a^3 - Log[1 + a^2*x^2]/(2*a^3) - (I*ArcTan[a*x]*PolyLog[2, 1 - (2*I)/(I - a*x)])/a^3 - PolyLog[3, 1 - (2*I)/(I - a*x)]/(2*a^3)}
{x*ArcTan[a*x]^3, x, 5, -((3*I*ArcTan[a*x]^2)/(2*a^2)) - (3*x*ArcTan[a*x]^2)/(2*a) + ArcTan[a*x]^3/(2*a^2) + (1/2)*x^2*ArcTan[a*x]^3 - (3*ArcTan[a*x]*Log[(2*I)/(I - a*x)])/a^2 - (3*I*PolyLog[2, 1 - (2*I)/(I - a*x)])/(2*a^2)}
{ArcTan[a*x]^3, x, 5, (I*ArcTan[a*x]^3)/a + x*ArcTan[a*x]^3 + (3*ArcTan[a*x]^2*Log[(2*I)/(I - a*x)])/a + (3*I*ArcTan[a*x]*PolyLog[2, 1 - (2*I)/(I - a*x)])/a + (3*PolyLog[3, 1 - (2*I)/(I - a*x)])/(2*a)}
{ArcTan[a*x]^3/x, x, 8, 2*ArcTan[a*x]^3*ArcTanh[1 - (2*I)/(I - a*x)] - (3/2)*I*ArcTan[a*x]^2*PolyLog[2, 1 - (2*I)/(I - a*x)] + (3/2)*I*ArcTan[a*x]^2*PolyLog[2, -1 + (2*I)/(I - a*x)] - (3/2)*ArcTan[a*x]*PolyLog[3, 1 - (2*I)/(I - a*x)] + (3/2)*ArcTan[a*x]*PolyLog[3, -1 + (2*I)/(I - a*x)] + (3/4)*I*PolyLog[4, 1 - (2*I)/(I - a*x)] - (3/4)*I*PolyLog[4, -1 + (2*I)/(I - a*x)]}
{ArcTan[a*x]^3/x^2, x, 5, (-I)*a*ArcTan[a*x]^3 - ArcTan[a*x]^3/x + 3*a*ArcTan[a*x]^2*Log[(2*a*x)/(I + a*x)] - 3*I*a*ArcTan[a*x]*PolyLog[2, -1 + (2*I)/(I + a*x)] + (3/2)*a*PolyLog[3, -1 + (2*I)/(I + a*x)]}
{ArcTan[a*x]^3/x^3, x, 5, (-(3/2))*I*a^2*ArcTan[a*x]^2 - (3*a*ArcTan[a*x]^2)/(2*x) - (1/2)*a^2*ArcTan[a*x]^3 - ArcTan[a*x]^3/(2*x^2) + 3*a^2*ArcTan[a*x]*Log[(2*a*x)/(I + a*x)] - (3/2)*I*a^2*PolyLog[2, -1 + (2*I)/(I + a*x)]}
{ArcTan[a*x]^3/x^4, x, 9, -((a^2*ArcTan[a*x])/x) - (1/2)*a^3*ArcTan[a*x]^2 - (a*ArcTan[a*x]^2)/(2*x^2) + (1/3)*I*a^3*ArcTan[a*x]^3 - ArcTan[a*x]^3/(3*x^3) - a^3*ArcTanh[1 + 2*a^2*x^2] - a^3*ArcTan[a*x]^2*Log[(2*a*x)/(I + a*x)] + I*a^3*ArcTan[a*x]*PolyLog[2, -1 + (2*I)/(I + a*x)] - (1/2)*a^3*PolyLog[3, -1 + (2*I)/(I + a*x)]}
{ArcTan[a*x]^3/x^5, x, 13, -(a^3/(4*x)) - (1/4)*a^4*ArcTan[a*x] - (a^2*ArcTan[a*x])/(4*x^2) + I*a^4*ArcTan[a*x]^2 - (a*ArcTan[a*x]^2)/(4*x^3) + (3*a^3*ArcTan[a*x]^2)/(4*x) + (1/4)*a^4*ArcTan[a*x]^3 - ArcTan[a*x]^3/(4*x^4) - 2*a^4*ArcTan[a*x]*Log[(2*a*x)/(I + a*x)] + I*a^4*PolyLog[2, -1 + (2*I)/(I + a*x)]}


(* ::Subsubsection::Closed:: *)
(*Miscellaneous integrands involving inverse tangents*)


{ArcTan[Sqrt[1 - a*x]/Sqrt[1 + a*x]]/(1 - a^2*x^2), x, -5, -((I*PolyLog[2, -((I*Sqrt[1 - a*x])/Sqrt[1 + a*x])])/(2*a)) + (I*PolyLog[2, (I*Sqrt[1 - a*x])/Sqrt[1 + a*x]])/(2*a)}


(* Integrands of the form x^m*ArcTan[a+b*x] where m is an integer *)
{ArcTan[a + b*x], x, 1, ((a + b*x)*ArcTan[a + b*x])/b - Log[1 + (a + b*x)^2]/(2*b)}
{x*ArcTan[a + b*x], x, 5, -(x/(2*b)) + ((1 - a^2)*ArcTan[a + b*x])/(2*b^2) + (1/2)*x^2*ArcTan[a + b*x] + (a*Log[1 + a^2 + 2*a*b*x + b^2*x^2])/(2*b^2)}
{x^2*ArcTan[a + b*x], x, 6, (2*a*x)/(3*b^2) - x^2/(6*b) - (a*(3 - a^2)*ArcTan[a + b*x])/(3*b^3) + (1/3)*x^3*ArcTan[a + b*x] + ((1 - 3*a^2)*Log[1 + a^2 + 2*a*b*x + b^2*x^2])/(6*b^3)}
{ArcTan[a + b*x]/x, x, 5, (1/2)*I*Log[(I*b*x)/(1 - I*a)]*Log[1 - I*a - I*b*x] - (1/2)*I*Log[-((I*b*x)/(1 + I*a))]*Log[1 + I*a + I*b*x] + (1/2)*I*PolyLog[2, 1 - (I*b*x)/(1 - I*a)] - (1/2)*I*PolyLog[2, 1 + (I*b*x)/(1 + I*a)]}
{ArcTan[a + b*x]/x^2, x, 6, -((a*b*ArcTan[a + b*x])/(1 + a^2)) - ArcTan[a + b*x]/x + (b*Log[x])/(1 + a^2) - (b*Log[1 + a^2 + 2*a*b*x + b^2*x^2])/(2*(1 + a^2))}


(* Integrands of the form (a+b*x)^m*ArcTan[a+b*x] where m is an integer *)
{(a + b*x)*ArcTan[a + b*x], x, 3, -((a + b*x)/(2*b)) + ArcTan[a + b*x]/(2*b) + ((a + b*x)^2*ArcTan[a + b*x])/(2*b)}
{(a + b*x)^2*ArcTan[a + b*x], x, 4, -((a + b*x)^2/(6*b)) + ((a + b*x)^3*ArcTan[a + b*x])/(3*b) + Log[1 + (a + b*x)^2]/(6*b)}
{ArcTan[1 + x]/(2 + 2*x), x, 5, (1/4)*I*PolyLog[2, (-I)*(1 + x)] - (1/4)*I*PolyLog[2, I*(1 + x)]}
{ArcTan[a + b*x]/(a + b*x), x, 4, (I*PolyLog[2, (-I)*(a + b*x)])/(2*b) - (I*PolyLog[2, I*(a + b*x)])/(2*b)}
{ArcTan[a + b*x]/(a + b*x)^2, x, 3, -(ArcTan[a + b*x]/(b*(a + b*x))) - ArcTanh[1 + 2*(a + b*x)^2]/b}


(* Integrands of the form ArcTan[a+b*x]/Pn where Pn is a polynomial *)
{ArcTan[x]/(a + b*x), x, 3, -((I*Log[1 + I*x]*Log[(I*(a + b*x))/(I*a - b)])/(2*b)) + (I*Log[1 - I*x]*Log[(I*(a + b*x))/(I*a + b)])/(2*b) + (I*PolyLog[2, (b*(1 - I*x))/(I*a + b)])/(2*b) - (I*PolyLog[2, -((b*(1 + I*x))/(I*a - b))])/(2*b)}
{ArcTan[x]/(a + b*x^2), x, 7, (I*Log[1 - I*x]*Log[(I*(Sqrt[-a] - Sqrt[b]*x))/(I*Sqrt[-a] - Sqrt[b])])/(4*Sqrt[-a]*Sqrt[b]) - (I*Log[1 + I*x]*Log[(I*(Sqrt[-a] - Sqrt[b]*x))/(I*Sqrt[-a] + Sqrt[b])])/(4*Sqrt[-a]*Sqrt[b]) + (I*Log[1 + I*x]*Log[(I*(Sqrt[-a] + Sqrt[b]*x))/(I*Sqrt[-a] - Sqrt[b])])/(4*Sqrt[-a]*Sqrt[b]) - (I*Log[1 - I*x]*Log[(I*(Sqrt[-a] + Sqrt[b]*x))/(I*Sqrt[-a] + Sqrt[b])])/(4*Sqrt[-a]*Sqrt[b]) + (I*PolyLog[2, -((Sqrt[b]*(1 - I*x))/(I*Sqrt[-a] - Sqrt[b]))])/(4*Sqrt[-a]*Sqrt[b]) - (I*PolyLog[2, (Sqrt[b]*(1 - I*x))/(I*Sqrt[-a] + Sqrt[b])])/(4*Sqrt[-a]*Sqrt[b]) + (I*PolyLog[2, -((Sqrt[b]*(1 + I*x))/(I*Sqrt[-a] - Sqrt[b]))])/(4*Sqrt[-a]*Sqrt[b]) - (I*PolyLog[2, (Sqrt[b]*(1 + I*x))/(I*Sqrt[-a] + Sqrt[b])])/(4*Sqrt[-a]*Sqrt[b])}
{ArcTan[x]/(a + b*x + c*x^2), x, 7, -((I*Log[1 + I*x]*Log[-((I*(b - Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c - I*(b - Sqrt[b^2 - 4*a*c])))])/(2*Sqrt[b^2 - 4*a*c])) + (I*Log[1 - I*x]*Log[(I*(b - Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c + I*(b - Sqrt[b^2 - 4*a*c]))])/(2*Sqrt[b^2 - 4*a*c]) + (I*Log[1 + I*x]*Log[-((I*(b + Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c - I*(b + Sqrt[b^2 - 4*a*c])))])/(2*Sqrt[b^2 - 4*a*c]) - (I*Log[1 - I*x]*Log[(I*(b + Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c + I*(b + Sqrt[b^2 - 4*a*c]))])/(2*Sqrt[b^2 - 4*a*c]) + (I*PolyLog[2, (2*c*(1 - I*x))/(2*c + I*(b - Sqrt[b^2 - 4*a*c]))])/(2*Sqrt[b^2 - 4*a*c]) - (I*PolyLog[2, (2*c*(1 - I*x))/(2*c + I*(b + Sqrt[b^2 - 4*a*c]))])/(2*Sqrt[b^2 - 4*a*c]) - (I*PolyLog[2, (2*c*(1 + I*x))/(2*c - I*(b - Sqrt[b^2 - 4*a*c]))])/(2*Sqrt[b^2 - 4*a*c]) + (I*PolyLog[2, (2*c*(1 + I*x))/(2*c - I*(b + Sqrt[b^2 - 4*a*c]))])/(2*Sqrt[b^2 - 4*a*c])}

{ArcTan[d + e*x]/(a + b*x), x, 3, (I*Log[(I*e*(a + b*x))/(b*(1 - I*d) + I*a*e)]*Log[1 - I*d - I*e*x])/(2*b) - (I*Log[-((I*e*(a + b*x))/(b*(1 + I*d) - I*a*e))]*Log[1 + I*d + I*e*x])/(2*b) + (I*PolyLog[2, (b*(1 - I*d - I*e*x))/(b*(1 - I*d) + I*a*e)])/(2*b) - (I*PolyLog[2, (b*(1 + I*d + I*e*x))/(b*(1 + I*d) - I*a*e)])/(2*b)}
{ArcTan[d + e*x]/(a + b*x^2), x, 8, (I*Log[(e*(Sqrt[-a] - Sqrt[b]*x))/(Sqrt[b]*(I + d) + Sqrt[-a]*e)]*Log[(-I)*(I + d) - I*e*x])/(4*Sqrt[-a]*Sqrt[b]) - (I*Log[-((e*(Sqrt[-a] + Sqrt[b]*x))/(Sqrt[b]*(I + d) - Sqrt[-a]*e))]*Log[(-I)*(I + d) - I*e*x])/(4*Sqrt[-a]*Sqrt[b]) - (I*Log[(I*e*(Sqrt[-a] - Sqrt[b]*x))/(Sqrt[b]*(1 + I*d) + I*Sqrt[-a]*e)]*Log[1 + I*d + I*e*x])/(4*Sqrt[-a]*Sqrt[b]) + (I*Log[-((I*e*(Sqrt[-a] + Sqrt[b]*x))/(Sqrt[b]*(1 + I*d) - I*Sqrt[-a]*e))]*Log[1 + I*d + I*e*x])/(4*Sqrt[-a]*Sqrt[b]) + (I*PolyLog[2, (Sqrt[b]*(1 + I*d + I*e*x))/(Sqrt[b]*(1 + I*d) - I*Sqrt[-a]*e)])/(4*Sqrt[-a]*Sqrt[b]) - (I*PolyLog[2, (Sqrt[b]*(1 + I*d + I*e*x))/(Sqrt[b]*(1 + I*d) + I*Sqrt[-a]*e)])/(4*Sqrt[-a]*Sqrt[b]) - (I*PolyLog[2, (Sqrt[b]*(I + d + e*x))/(Sqrt[b]*(I + d) - Sqrt[-a]*e)])/(4*Sqrt[-a]*Sqrt[b]) + (I*PolyLog[2, (Sqrt[b]*(I + d + e*x))/(Sqrt[b]*(I + d) + Sqrt[-a]*e)])/(4*Sqrt[-a]*Sqrt[b])}
{ArcTan[d + e*x]/(a + b*x + c*x^2), x, 7, (I*Log[(I*e*(b - Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c*(1 - I*d) + I*(b - Sqrt[b^2 - 4*a*c])*e)]*Log[1 - I*d - I*e*x])/(2*Sqrt[b^2 - 4*a*c]) - (I*Log[(I*e*(b + Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c*(1 - I*d) + I*(b + Sqrt[b^2 - 4*a*c])*e)]*Log[1 - I*d - I*e*x])/(2*Sqrt[b^2 - 4*a*c]) - (I*Log[-((I*e*(b - Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c*(1 + I*d) - I*(b - Sqrt[b^2 - 4*a*c])*e))]*Log[1 + I*d + I*e*x])/(2*Sqrt[b^2 - 4*a*c]) + (I*Log[-((I*e*(b + Sqrt[b^2 - 4*a*c] + 2*c*x))/(2*c*(1 + I*d) - I*(b + Sqrt[b^2 - 4*a*c])*e))]*Log[1 + I*d + I*e*x])/(2*Sqrt[b^2 - 4*a*c]) + (I*PolyLog[2, (2*c*(1 - I*d - I*e*x))/(2*c*(1 - I*d) + I*(b - Sqrt[b^2 - 4*a*c])*e)])/(2*Sqrt[b^2 - 4*a*c]) - (I*PolyLog[2, (2*c*(1 - I*d - I*e*x))/(2*c*(1 - I*d) + I*(b + Sqrt[b^2 - 4*a*c])*e)])/(2*Sqrt[b^2 - 4*a*c]) - (I*PolyLog[2, (2*c*(1 + I*d + I*e*x))/(2*c*(1 + I*d) - I*(b - Sqrt[b^2 - 4*a*c])*e)])/(2*Sqrt[b^2 - 4*a*c]) + (I*PolyLog[2, (2*c*(1 + I*d + I*e*x))/(2*c*(1 + I*d) - I*(b + Sqrt[b^2 - 4*a*c])*e)])/(2*Sqrt[b^2 - 4*a*c])}


(* Integrands of the form ArcTan[x]^m*(1+x^2)^n where n is an integer *)
{1/((1 + x^2)*ArcTan[x]), x, 1, Log[ArcTan[x]]}
{ArcTan[x]/(1 + x^2), x, 1, ArcTan[x]^2/2}
{ArcTan[x]^n/(1 + x^2), x, 1, ArcTan[x]^(1 + n)/(1 + n)}
{ArcTan[x]/(1 + x^2)^2, x, 2, 1/(4*(1 + x^2)) + (x*ArcTan[x])/(2*(1 + x^2)) + ArcTan[x]^2/4}
{ArcTan[x]^2/(1 + x^2)^2, x, 4, -(x/(4*(1 + x^2))) - ArcTan[x]/4 + ArcTan[x]/(2*(1 + x^2)) + (x*ArcTan[x]^2)/(2*(1 + x^2)) + ArcTan[x]^3/6}

{1/((a + a*x^2)*(b - 2*b*ArcTan[x])), x, 3, -(Log[1 - 2*ArcTan[x]]/(2*a*b))}


{ArcTan[b*x]/(1 + x^2), x, 9, (1/4)*Log[-((I*b*(I - x))/(1 + b))]*Log[1 - I*b*x] - (1/4)*Log[(I*b*(I + x))/(1 - b)]*Log[1 - I*b*x] - (1/4)*Log[(I*b*(I - x))/(1 - b)]*Log[1 + I*b*x] + (1/4)*Log[-((I*b*(I + x))/(1 + b))]*Log[1 + I*b*x] - (1/4)*PolyLog[2, (1 - I*b*x)/(1 - b)] + (1/4)*PolyLog[2, (1 - I*b*x)/(1 + b)] - (1/4)*PolyLog[2, (1 + I*b*x)/(1 - b)] + (1/4)*PolyLog[2, (1 + I*b*x)/(1 + b)]}
{ArcTan[a+b*x]/(1 + x^2), x, 9, (1/4)*Log[(I*b*(I - x))/(I*(I + a) - b)]*Log[(-I)*(I + a) - I*b*x] - (1/4)*Log[-((I*b*(I + x))/(I*(I + a) + b))]*Log[(-I)*(I + a) - I*b*x] - (1/4)*Log[(I*b*(I - x))/(1 + I*a - b)]*Log[1 + I*a + I*b*x] + (1/4)*Log[-((I*b*(I + x))/(1 + I*a + b))]*Log[1 + I*a + I*b*x] - (1/4)*PolyLog[2, (1 + I*a + I*b*x)/(1 + I*a - b)] + (1/4)*PolyLog[2, (1 + I*a + I*b*x)/(1 + I*a + b)] + (1/4)*PolyLog[2, (I*(I + a + b*x))/(I*(I + a) - b)] - (1/4)*PolyLog[2, (I*(I + a + b*x))/(I*(I + a) + b)]}


{(x*ArcTan[x])/(1 + x^2), x, 3, (-(1/2))*I*ArcTan[x]^2 - ArcTan[x]*Log[(2*I)/(I - x)] - (1/2)*I*PolyLog[2, 1 - (2*I)/(I - x)]}
{(x*ArcTan[x])/(1 + x^2)^2, x, 3, x/(4*(1 + x^2)) + ArcTan[x]/4 - ArcTan[x]/(2*(1 + x^2))}
{(x*ArcTan[x])/(1 + x^2)^3, x, 4, x/(16*(1 + x^2)^2) + (3*x)/(32*(1 + x^2)) + (3*ArcTan[x])/32 - ArcTan[x]/(4*(1 + x^2)^2)}


(* Integrands of the form ArcTan[x]/(a+b*x^2)^n where n is a half-integer *)
{ArcTan[x]/(a + b*x^2)^(3/2), x, 3, (x*ArcTan[x])/(a*Sqrt[a + b*x^2]) + ArcTanh[Sqrt[a + b*x^2]/Sqrt[a - b]]/(a*Sqrt[a - b])}
{ArcTan[x]/(a + b*x^2)^(5/2), x, 8, -(1/(3*a*(a - b)*Sqrt[a + b*x^2])) + (x*(3*a + 2*b*x^2)*ArcTan[x])/(3*a^2*(a + b*x^2)^(3/2)) + ((3*a - 2*b)*ArcTanh[Sqrt[a + b*x^2]/Sqrt[a - b]])/(3*a^2*(a - b)^(3/2))}
{ArcTan[x]/(a + b*x^2)^(7/2), x, 8, -(1/(15*a*(a - b)*(a + b*x^2)^(3/2))) - (7*a - 4*b)/(15*a^2*(a - b)^2*Sqrt[a + b*x^2]) + (x*(8*(a + b*x^2)^2 + a*(7*a + 4*b*x^2))*ArcTan[x])/(15*a^3*(a + b*x^2)^(5/2)) + ((15*a^2 - 20*a*b + 8*b^2)*ArcTanh[Sqrt[a + b*x^2]/Sqrt[a - b]])/(15*a^3*(a - b)^(5/2))}

{ArcTan[x]*(a + a*x^2)^(1/2), x, 3, (-(1/2))*Sqrt[a + a*x^2] + (1/2)*x*Sqrt[a + a*x^2]*ArcTan[x] - (I*a*Sqrt[1 + x^2]*(2*ArcTan[Sqrt[1 + I*x]/Sqrt[1 - I*x]]*ArcTan[x] - PolyLog[2, -((I*Sqrt[1 + I*x])/Sqrt[1 - I*x])] + PolyLog[2, (I*Sqrt[1 + I*x])/Sqrt[1 - I*x]]))/(2*Sqrt[a + a*x^2])}
{ArcTan[x]/(a + a*x^2)^(1/2), x, 2, -((I*Sqrt[1 + x^2]*(2*ArcTan[Sqrt[1 + I*x]/Sqrt[1 - I*x]]*ArcTan[x] - PolyLog[2, -((I*Sqrt[1 + I*x])/Sqrt[1 - I*x])] + PolyLog[2, (I*Sqrt[1 + I*x])/Sqrt[1 - I*x]]))/Sqrt[a + a*x^2])}
{ArcTan[x]/(a + a*x^2)^(3/2), x, 1, 1/(a*Sqrt[a + a*x^2]) + (x*ArcTan[x])/(a*Sqrt[a + a*x^2])}
{ArcTan[x]/(a + a*x^2)^(5/2), x, 2, 1/(9*a*(a + a*x^2)^(3/2)) + 2/(3*a^2*Sqrt[a + a*x^2]) + (x*ArcTan[x])/(3*a*(a + a*x^2)^(3/2)) + (2*x*ArcTan[x])/(3*a^2*Sqrt[a + a*x^2])}
{ArcTan[x]/(a + a*x^2)^(7/2), x, 3, 1/(25*a*(a + a*x^2)^(5/2)) + 4/(45*a^2*(a + a*x^2)^(3/2)) + 8/(15*a^3*Sqrt[a + a*x^2]) + (x*ArcTan[x])/(5*a*(a + a*x^2)^(5/2)) + (4*x*ArcTan[x])/(15*a^2*(a + a*x^2)^(3/2)) + (8*x*ArcTan[x])/(15*a^3*Sqrt[a + a*x^2])}


(* Integrands of the form x^m*ArcTan[Sqrt[x]] where m is an integer *)
{ArcTan[Sqrt[x]], x, 4, -Sqrt[x] + ArcTan[Sqrt[x]] + x*ArcTan[Sqrt[x]]}
{x*ArcTan[Sqrt[x]], x, 5, Sqrt[x]/2 - x^(3/2)/6 - ArcTan[Sqrt[x]]/2 + (1/2)*x^2*ArcTan[Sqrt[x]]}
{x^2*ArcTan[Sqrt[x]], x, 6, -(Sqrt[x]/3) + x^(3/2)/9 - x^(5/2)/15 + ArcTan[Sqrt[x]]/3 + (1/3)*x^3*ArcTan[Sqrt[x]]}
{ArcTan[Sqrt[x]]/x, x, 3, I*PolyLog[2, (-I)*Sqrt[x]] - I*PolyLog[2, I*Sqrt[x]]}
{ArcTan[Sqrt[x]]/x^2, x, 4, -(1/Sqrt[x]) - ArcTan[Sqrt[x]] - ArcTan[Sqrt[x]]/x}
{ArcTan[Sqrt[x]]/x^3, x, 5, -(1/(6*x^(3/2))) + 1/(2*Sqrt[x]) + ArcTan[Sqrt[x]]/2 - ArcTan[Sqrt[x]]/(2*x^2)}

{Sqrt[x]*ArcTan[Sqrt[x]], x, 5, -(x/3) + (2/3)*x^(3/2)*ArcTan[Sqrt[x]] + (1/3)*Log[1 + x]}
{x^(3/2)*ArcTan[Sqrt[x]], x, 6, x/5 - x^2/10 + (2/5)*x^(5/2)*ArcTan[Sqrt[x]] - (1/5)*Log[1 + x]}
{ArcTan[Sqrt[x]]/Sqrt[x], x, 2, 2*Sqrt[x]*ArcTan[Sqrt[x]] - Log[1 + x]}
{ArcTan[Sqrt[x]]/x^(3/2), x, 3, -((2*ArcTan[Sqrt[x]])/Sqrt[x]) - 2*ArcTanh[1 + 2*x]}


(* ::Subsection::Closed:: *)
(*Integrands involving inverse trig functions of exponentials*)


(* Integrands of the form x^m*ArcTan[E^x] *)
{ArcTan[E^x], x, 3, (1/2)*I*PolyLog[2, (-I)*E^x] - (1/2)*I*PolyLog[2, I*E^x]}
{x*ArcTan[E^x], x, 5, (1/2)*I*x*PolyLog[2, (-I)*E^x] - (1/2)*I*x*PolyLog[2, I*E^x] - (1/2)*I*PolyLog[3, (-I)*E^x] + (1/2)*I*PolyLog[3, I*E^x]}
{x^2*ArcTan[E^x], x, 7, (1/2)*I*x^2*PolyLog[2, (-I)*E^x] - (1/2)*I*x^2*PolyLog[2, I*E^x] - I*x*PolyLog[3, (-I)*E^x] + I*x*PolyLog[3, I*E^x] + I*PolyLog[4, (-I)*E^x] - I*PolyLog[4, I*E^x]}


(* Integrands of the form x^m*ArcTan[E^(a+b*x)] *)
{ArcTan[E^(a + b*x)], x, 3, (I*PolyLog[2, (-I)*E^(a + b*x)])/(2*b) - (I*PolyLog[2, I*E^(a + b*x)])/(2*b)}
{x*ArcTan[E^(a + b*x)], x, 5, (I*x*PolyLog[2, (-I)*E^(a + b*x)])/(2*b) - (I*x*PolyLog[2, I*E^(a + b*x)])/(2*b) - (I*PolyLog[3, (-I)*E^(a + b*x)])/(2*b^2) + (I*PolyLog[3, I*E^(a + b*x)])/(2*b^2)}
{x^2*ArcTan[E^(a + b*x)], x, 7, (I*x^2*PolyLog[2, (-I)*E^(a + b*x)])/(2*b) - (I*x^2*PolyLog[2, I*E^(a + b*x)])/(2*b) - (I*x*PolyLog[3, (-I)*E^(a + b*x)])/b^2 + (I*x*PolyLog[3, I*E^(a + b*x)])/b^2 + (I*PolyLog[4, (-I)*E^(a + b*x)])/b^3 - (I*PolyLog[4, I*E^(a + b*x)])/b^3}


(* Integrands of the form x^m*ArcTan[a+b*f^(c+d*x)] *)
{ArcTan[a + b*f^(c + d*x)], x, 5, x*ArcTan[a + b*f^(c + d*x)] + (1/2)*I*x*Log[1 - (b*f^(c + d*x))/(I - a)] - (1/2)*I*x*Log[1 + (b*f^(c + d*x))/(I + a)] + (I*PolyLog[2, (b*f^(c + d*x))/(I - a)])/(2*d*Log[f]) - (I*PolyLog[2, -((b*f^(c + d*x))/(I + a))])/(2*d*Log[f]), (1/2)*I*x*Log[1 - I*a - I*b*f^(c + d*x)] - (1/2)*I*x*Log[1 + I*a + I*b*f^(c + d*x)] - (1/2)*I*x*Log[1 - (I*b*f^(c + d*x))/(1 - I*a)] + (1/2)*I*x*Log[1 + (I*b*f^(c + d*x))/(1 + I*a)] - (I*PolyLog[2, (I*b*f^(c + d*x))/(1 - I*a)])/(2*d*Log[f]) + (I*PolyLog[2, -((I*b*f^(c + d*x))/(1 + I*a))])/(2*d*Log[f])}
{x*ArcTan[a + b*f^(c + d*x)], x, 7, (1/2)*x^2*ArcTan[a + b*f^(c + d*x)] - (1/4)*I*x^2*Log[1 - (I*b*f^(c + d*x))/(1 - I*a)] + (1/4)*I*x^2*Log[1 + (I*b*f^(c + d*x))/(1 + I*a)] - (I*x*PolyLog[2, (I*b*f^(c + d*x))/(1 - I*a)])/(2*d*Log[f]) + (I*x*PolyLog[2, -((I*b*f^(c + d*x))/(1 + I*a))])/(2*d*Log[f]) + (I*PolyLog[3, (I*b*f^(c + d*x))/(1 - I*a)])/(2*d^2*Log[f]^2) - (I*PolyLog[3, -((I*b*f^(c + d*x))/(1 + I*a))])/(2*d^2*Log[f]^2), (1/4)*I*x^2*Log[1 - I*a - I*b*f^(c + d*x)] - (1/4)*I*x^2*Log[1 + I*a + I*b*f^(c + d*x)] - (1/4)*I*x^2*Log[1 - (I*b*f^(c + d*x))/(1 - I*a)] + (1/4)*I*x^2*Log[1 + (I*b*f^(c + d*x))/(1 + I*a)] - (I*x*PolyLog[2, (I*b*f^(c + d*x))/(1 - I*a)])/(2*d*Log[f]) + (I*x*PolyLog[2, -((I*b*f^(c + d*x))/(1 + I*a))])/(2*d*Log[f]) + (I*PolyLog[3, (I*b*f^(c + d*x))/(1 - I*a)])/(2*d^2*Log[f]^2) - (I*PolyLog[3, -((I*b*f^(c + d*x))/(1 + I*a))])/(2*d^2*Log[f]^2)}
{x^2*ArcTan[a + b*f^(c + d*x)], x, 9, (1/3)*x^3*ArcTan[a + b*f^(c + d*x)] - (1/6)*I*x^3*Log[1 - (I*b*f^(c + d*x))/(1 - I*a)] + (1/6)*I*x^3*Log[1 + (I*b*f^(c + d*x))/(1 + I*a)] - (I*x^2*PolyLog[2, (I*b*f^(c + d*x))/(1 - I*a)])/(2*d*Log[f]) + (I*x^2*PolyLog[2, -((I*b*f^(c + d*x))/(1 + I*a))])/(2*d*Log[f]) + (I*x*PolyLog[3, (I*b*f^(c + d*x))/(1 - I*a)])/(d^2*Log[f]^2) - (I*x*PolyLog[3, -((I*b*f^(c + d*x))/(1 + I*a))])/(d^2*Log[f]^2) - (I*PolyLog[4, (I*b*f^(c + d*x))/(1 - I*a)])/(d^3*Log[f]^3) + (I*PolyLog[4, -((I*b*f^(c + d*x))/(1 + I*a))])/(d^3*Log[f]^3), (1/6)*I*x^3*Log[1 - I*a - I*b*f^(c + d*x)] - (1/6)*I*x^3*Log[1 + I*a + I*b*f^(c + d*x)] - (1/6)*I*x^3*Log[1 - (I*b*f^(c + d*x))/(1 - I*a)] + (1/6)*I*x^3*Log[1 + (I*b*f^(c + d*x))/(1 + I*a)] - (I*x^2*PolyLog[2, (I*b*f^(c + d*x))/(1 - I*a)])/(2*d*Log[f]) + (I*x^2*PolyLog[2, -((I*b*f^(c + d*x))/(1 + I*a))])/(2*d*Log[f]) + (I*x*PolyLog[3, (I*b*f^(c + d*x))/(1 - I*a)])/(d^2*Log[f]^2) - (I*x*PolyLog[3, -((I*b*f^(c + d*x))/(1 + I*a))])/(d^2*Log[f]^2) - (I*PolyLog[4, (I*b*f^(c + d*x))/(1 - I*a)])/(d^3*Log[f]^3) + (I*PolyLog[4, -((I*b*f^(c + d*x))/(1 + I*a))])/(d^3*Log[f]^3)}


{ArcTan[E^x]/E^x, x, 3, x - ArcTan[E^x]/E^x - (1/2)*Log[1 + E^(2*x)]}


(* ::Subsection::Closed:: *)
(*Integrands involving inverse trig functions of trig functions*)


(* Integrands of the form ArcTan[a+b*Trig[x]] *)
{ArcTan[Tan[x]], x, 2, -(x^2/2) + x*ArcTan[Tan[x]]}
{ArcTan[b*Tan[x]], x, 12, x*ArcTan[b*Tan[x]] + (1/2)*I*x*Log[1 + ((1 - b^2)*E^(2*I*x))/(1 - 2*b + b^2)] - (1/2)*I*x*Log[1 + ((1 - b^2)*E^(2*I*x))/(1 + 2*b + b^2)] + (1/4)*PolyLog[2, -(((1 - b^2)*E^(2*I*x))/(1 - 2*b + b^2))] - (1/4)*PolyLog[2, -(((1 - b^2)*E^(2*I*x))/(1 + 2*b + b^2))]}
{ArcTan[a+b*Tan[x]], x, 10, (1/4)*Log[(I*b*(I - Tan[x]))/(I*(I + a) - b)]*Log[(-I)*(I + a) - I*b*Tan[x]] - (1/4)*Log[-((I*b*(I + Tan[x]))/(I*(I + a) + b))]*Log[(-I)*(I + a) - I*b*Tan[x]] - (1/4)*Log[(I*b*(I - Tan[x]))/(1 + I*a - b)]*Log[1 + I*a + I*b*Tan[x]] + (1/4)*Log[-((I*b*(I + Tan[x]))/(1 + I*a + b))]*Log[1 + I*a + I*b*Tan[x]] - (1/4)*PolyLog[2, (1 + I*a + I*b*Tan[x])/(1 + I*a - b)] + (1/4)*PolyLog[2, (1 + I*a + I*b*Tan[x])/(1 + I*a + b)] + (1/4)*PolyLog[2, (I*(I + a + b*Tan[x]))/(I*(I + a) - b)] - (1/4)*PolyLog[2, (I*(I + a + b*Tan[x]))/(I*(I + a) + b)]}

{ArcTan[b*Cot[x]], x, 12, x*ArcTan[b*Cot[x]] - (1/2)*I*x*Log[1 - ((1 - b^2)*E^(2*I*x))/(1 - 2*b + b^2)] + (1/2)*I*x*Log[1 - ((1 - b^2)*E^(2*I*x))/(1 + 2*b + b^2)] - (1/4)*PolyLog[2, ((1 - b^2)*E^(2*I*x))/(1 - 2*b + b^2)] + (1/4)*PolyLog[2, ((1 - b^2)*E^(2*I*x))/(1 + 2*b + b^2)]}
{ArcTan[a+b*Cot[x]], x, 10, (-(1/4))*Log[(I*b*(I - Cot[x]))/(I*(I + a) - b)]*Log[(-I)*(I + a) - I*b*Cot[x]] + (1/4)*Log[-((I*b*(I + Cot[x]))/(I*(I + a) + b))]*Log[(-I)*(I + a) - I*b*Cot[x]] + (1/4)*Log[(I*b*(I - Cot[x]))/(1 + I*a - b)]*Log[1 + I*a + I*b*Cot[x]] - (1/4)*Log[-((I*b*(I + Cot[x]))/(1 + I*a + b))]*Log[1 + I*a + I*b*Cot[x]] + (1/4)*PolyLog[2, (1 + I*a + I*b*Cot[x])/(1 + I*a - b)] - (1/4)*PolyLog[2, (1 + I*a + I*b*Cot[x])/(1 + I*a + b)] - (1/4)*PolyLog[2, (I*(I + a + b*Cot[x]))/(I*(I + a) - b)] + (1/4)*PolyLog[2, (I*(I + a + b*Cot[x]))/(I*(I + a) + b)]}


(* Integrands of the form x^m*ArcTan[Sinh[x]] where m is an integer *)
{ArcTan[Sinh[x]], x, 5, -2*x*ArcTan[E^x] + x*ArcTan[Sinh[x]] + I*PolyLog[2, (-I)*E^x] - I*PolyLog[2, I*E^x]}
{x*ArcTan[Sinh[x]], x, 7, (-x^2)*ArcTan[E^x] + (1/2)*x^2*ArcTan[Sinh[x]] + I*x*PolyLog[2, (-I)*E^x] - I*x*PolyLog[2, I*E^x] - I*PolyLog[3, (-I)*E^x] + I*PolyLog[3, I*E^x]}
{x^2*ArcTan[Sinh[x]], x, 9, (-(2/3))*x^3*ArcTan[E^x] + (1/3)*x^3*ArcTan[Sinh[x]] + I*x^2*PolyLog[2, (-I)*E^x] - I*x^2*PolyLog[2, I*E^x] - 2*I*x*PolyLog[3, (-I)*E^x] + 2*I*x*PolyLog[3, I*E^x] + 2*I*PolyLog[4, (-I)*E^x] - 2*I*PolyLog[4, I*E^x]}


(* ::Subsection::Closed:: *)
(*Integrands involving exponentials of inverse trig functions*)


(* Integrands of the form x^m*E^ArcTan[x] where m is an integer *)
{E^ArcTan[x], x, 1, Subst[Int[E^x*Sec[x]^2, x], x, ArcTan[x]]}


(* Integrands of the form E^ArcTan[x]/(a+a*x^2)^n *)
{E^ArcTan[x]/(a + a*x^2), x, 2, E^ArcTan[x]/a}
{E^ArcTan[x]/(a + a*x^2)^2, x, 3, (2*E^ArcTan[x])/(5*a^2) + E^ArcTan[x]/(5*a^2*(1 + x^2)) + (2*E^ArcTan[x]*x)/(5*a^2*(1 + x^2))}
{E^ArcTan[x]/(a + a*x^2)^3, x, 4, (24*E^ArcTan[x])/(85*a^3) + E^ArcTan[x]/(17*a^3*(1 + x^2)^2) + (4*E^ArcTan[x]*x)/(17*a^3*(1 + x^2)^2) + (12*E^ArcTan[x])/(85*a^3*(1 + x^2)) + (24*E^ArcTan[x]*x)/(85*a^3*(1 + x^2))}

{E^ArcTan[x]/(1 + x^2)^(3/2), x, 4, E^ArcTan[x]/(2*Sqrt[1 + x^2]) + (E^ArcTan[x]*x)/(2*Sqrt[1 + x^2])}
{E^ArcTan[x]/(a + a*x^2)^(3/2), x, 4, (E^ArcTan[x]*(1 + x))/(2*a*Sqrt[a*(1 + x^2)])}
{E^ArcTan[x]/(a + a*x^2)^(5/2), x, 5, (E^ArcTan[x]*(4 + 6*x + 3*x^2 + 3*x^3))/(10*a*(a*(1 + x^2))^(3/2)), (E^ArcTan[x]*(3 + 3*x + 1/(1 + x^2) + (3*x)/(1 + x^2)))/(10*a^2*Sqrt[a*(1 + x^2)])}
{E^ArcTan[x]/(a + a*x^2)^(7/2), x, 6, (E^ArcTan[x]*(9 + 17*x + 14*x^2 + 18*x^3 + 6*x^4 + 6*x^5))/(26*a*(a*(1 + x^2))^(5/2)), (E^ArcTan[x]*(6 + 6*x + 1/(1 + x^2)^2 + (5*x)/(1 + x^2)^2 + 2/(1 + x^2) + (6*x)/(1 + x^2)))/(26*a^3*Sqrt[a*(1 + x^2)])}


{E^ArcTan[x]*x/(1 + x^2)^(3/2), x, 4, -(E^ArcTan[x]/(2*Sqrt[1 + x^2])) + (E^ArcTan[x]*x)/(2*Sqrt[1 + x^2])}


(* ::Subsection::Closed:: *)
(*Problems from Calculus textbooks*)


(* ::Subsubsection::Closed:: *)
(*Apostol Calculus, Volume 1, 2nd Edition, Section 622*)


{ArcTan[Sqrt[x]]/(Sqrt[x]*(1 + x)), x, 2, ArcTan[Sqrt[x]]^2}


(* ::Subsubsection::Closed:: *)
(*Edwards and Penney Calculus*)


{ArcTan[x]/(-1 + x)^3, x, 8, 1/(4*(1 - x)) - ArcTan[x]/(2*(1 - x)^2) - (1/4)*Log[1 - x] + (1/8)*Log[1 + x^2]}
{ArcTan[1 + 2*x]/(4 + 3*x)^3, x, 8, -(1/(34*(4 + 3*x))) + (8/867)*ArcTan[1 + 2*x] - ArcTan[1 + 2*x]/(6*(4 + 3*x)^2) + (5/289)*Log[4 + 3*x] - (5/578)*Log[1 + 2*x + 2*x^2]}


(* ::Subsubsection::Closed:: *)
(*Grossman Calculus*)


{x*ArcTan[x^2], x, 2, (1/2)*x^2*ArcTan[x^2] - (1/4)*Log[1 + x^4]}
{x^5*ArcTan[x^2], x, 4, -(x^4/12) + (1/6)*x^6*ArcTan[x^2] + (1/12)*Log[1 + x^4]}
{x^5*ArcTan[x^3], x, 3, -(x^3/6) + ArcTan[x^3]/6 + (1/6)*x^6*ArcTan[x^3]}
{x*ArcTan[x^3], x, 7, -(ArcTan[x]/2) + (1/2)*x^2*ArcTan[x^3] - (1/4)*ArcTan[x/(1 - x^2)] + (1/4)*Sqrt[3]*ArcTanh[(Sqrt[3]*x)/(1 + x^2)]}


(* ::Subsubsection::Closed:: *)
(*Thomas Calculus, 8th Edition*)


{1/((1 + x^2)*(2 + ArcTan[x])), x, 2, Log[2 + ArcTan[x]]}
{ArcTan[Sqrt[1 + x]], x, 6, -Sqrt[1 + x] + 2*ArcTan[Sqrt[1 + x]] + x*ArcTan[Sqrt[1 + x]]}


(* ::Subsection::Closed:: *)
(*Miscellaneous problems*)


{ArcTan[1/x], x, 1, x*ArcCot[x] + Log[1 + x^2]/2}


{ArcTan[a + b*x]/((a*d)/b + d*x), x, 6, (I*PolyLog[2, (-I)*(a + b*x)])/(2*d) - (I*PolyLog[2, I*(a + b*x)])/(2*d)}


{ArcTan[a*x^n]/x, x, 3, (I*PolyLog[2, (-I)*a*x^n])/(2*n) - (I*PolyLog[2, I*a*x^n])/(2*n)}

{ArcTan[a*x^5]/x, x, 3, (1/10)*I*PolyLog[2, (-I)*a*x^5] - (1/10)*I*PolyLog[2, I*a*x^5]}


{x^3*ArcTan[a + b*x^4], x, 2, ((a + b*x^4)*ArcTan[a + b*x^4])/(4*b) - Log[1 + (a + b*x^4)^2]/(8*b)}

{x^(n-1)*ArcTan[a + b*x^n], x, 2, ((a + b*x^n)*ArcTan[a + b*x^n])/(b*n) - Log[1 + (a + b*x^n)^2]/(2*b*n)}


{ArcTan[1 + x]/x^4, x, 6, -(1/(12*x^2)) + 1/(6*x) + (1/12)*ArcTan[1 + x] - ArcTan[1 + x]/(3*x^3) + Log[x]/12 - (1/24)*Log[2 + 2*x + x^2]}
{ArcTan[1 + x + x^2]/x^2, x, 8, (1/2)*ArcTan[1 + x] - ArcTan[1 + x + x^2]/x + Log[x]/2 - (1/2)*Log[1 + x^2] + (1/4)*Log[2 + 2*x + x^2]}
{Sqrt[x]*ArcTan[x], x, 9, -((4*Sqrt[x])/3) - (1/3)*Sqrt[2]*ArcTan[1 - Sqrt[2]*Sqrt[x]] + (1/3)*Sqrt[2]*ArcTan[1 + Sqrt[2]*Sqrt[x]] + (2/3)*x^(3/2)*ArcTan[x] - Log[1 - Sqrt[2]*Sqrt[x] + x]/(3*Sqrt[2]) + Log[1 + Sqrt[2]*Sqrt[x] + x]/(3*Sqrt[2])}


{(x + x^3 + (1 + x)^2*ArcTan[x])/((1 + x)^2*(1 + x^2)), x, 5, 1/(1 + x) + ArcTan[x]^2/2 + Log[1 + x]}
