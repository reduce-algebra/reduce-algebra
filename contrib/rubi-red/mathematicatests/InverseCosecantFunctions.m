(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Inverse Cosecants*)


(* ::Subsection::Closed:: *)
(*Integrands involving inverse cosecants*)


(* Integrands of the form x^m*ArcCsc[a*x] where m is an integer *)
{x*ArcCsc[a*x], x, 2, (Sqrt[1 - 1/(a^2*x^2)]*x)/(2*a) + (1/2)*x^2*ArcCsc[a*x]}
{x^2*ArcCsc[a*x], x, 3, (Sqrt[1 - 1/(a^2*x^2)]*x^2)/(6*a) + (1/3)*x^3*ArcCsc[a*x] + ArcTanh[Sqrt[1 - 1/(a^2*x^2)]]/(6*a^3)}
{x^3*ArcCsc[a*x], x, 3, (Sqrt[1 - 1/(a^2*x^2)]*x)/(6*a^3) + (Sqrt[1 - 1/(a^2*x^2)]*x^3)/(12*a) + (1/4)*x^4*ArcCsc[a*x]}
{x^4*ArcCsc[a*x], x, 4, (3*Sqrt[1 - 1/(a^2*x^2)]*x^2)/(40*a^3) + (Sqrt[1 - 1/(a^2*x^2)]*x^4)/(20*a) + (1/5)*x^5*ArcCsc[a*x] + (3*ArcTanh[Sqrt[1 - 1/(a^2*x^2)]])/(40*a^5)}

{ArcCsc[a*x]/x, x, 6, (1/2)*I*ArcCsc[a*x]^2 - ArcCsc[a*x]*Log[1 - E^(2*I*ArcCsc[a*x])] + (1/2)*I*PolyLog[2, E^(2*I*ArcCsc[a*x])]}
{ArcCsc[a*x]/x^2, x, 3, (-a)*Sqrt[1 - 1/(a^2*x^2)] - ArcCsc[a*x]/x}
{ArcCsc[a*x]/x^3, x, 4, -((a*Sqrt[1 - 1/(a^2*x^2)])/(4*x)) + (1/4)*a^2*ArcCsc[a*x] - ArcCsc[a*x]/(2*x^2)}
{ArcCsc[a*x]/x^4, x, 4, (-(2/9))*a^3*Sqrt[1 - 1/(a^2*x^2)] - (a*Sqrt[1 - 1/(a^2*x^2)])/(9*x^2) - ArcCsc[a*x]/(3*x^3)}


(* Integrands of the form x^m*ArcCsc[a+b*x] where m is an integer *)
{ArcCsc[a + b*x], x, 3, ((a + b*x)*ArcCsc[a + b*x])/b + ArcTanh[Sqrt[1 - 1/(a + b*x)^2]]/b}
{x*ArcCsc[a + b*x], x, 7, ((a + b*x)*Sqrt[1 - 1/(a + b*x)^2])/(2*b^2) - (a*(a + b*x)*ArcCsc[a + b*x])/b^2 + ((a + b*x)^2*ArcCsc[a + b*x])/(2*b^2) - (a*ArcTanh[Sqrt[1 - 1/(a + b*x)^2]])/b^2}
{x^2*ArcCsc[a + b*x], x, 10, -((a*(a + b*x)*Sqrt[1 - 1/(a + b*x)^2])/b^3) + ((a + b*x)^2*Sqrt[1 - 1/(a + b*x)^2])/(6*b^3) + (a^2*(a + b*x)*ArcCsc[a + b*x])/b^3 - (a*(a + b*x)^2*ArcCsc[a + b*x])/b^3 + ((a + b*x)^3*ArcCsc[a + b*x])/(3*b^3) + ArcTanh[Sqrt[1 - 1/(a + b*x)^2]]/(6*b^3) + (a^2*ArcTanh[Sqrt[1 - 1/(a + b*x)^2]])/b^3}
{ArcCsc[a + b*x]/x, x, 3, Int[ArcCsc[a + b*x]/x, x]}
(* {ArcCsc[a + b*x]/x^2, x, 0, -((1/(a*x))*(a*ArcCsc[a + b*x] + (1/Sqrt[-1 + a^2])*(b*x*(Sqrt[-1 + a^2]*ArcSin[1/(a + b*x)] + Log[x] - Log[-1 + a^2 + a*b*x + a*Sqrt[-1 + a^2]*Sqrt[(-1 + a^2 + 2*a*b*x + b^2*x^2)/(a + b*x)^2] + Sqrt[-1 + a^2]*b*x*Sqrt[(-1 + a^2 + 2*a*b*x + b^2*x^2)/(a + b*x)^2]]))))} *)


(* Integrands of the form x^m*ArcCsc[Sqrt[x]] where m is an integer *)
{ArcCsc[Sqrt[x]], x, 3, Sqrt[-1 + x] + x*ArcCsc[Sqrt[x]]}
{x*ArcCsc[Sqrt[x]], x, 4, (1/3)*Sqrt[1 - 1/x]*Sqrt[x] + (1/6)*Sqrt[1 - 1/x]*x^(3/2) + (1/2)*x^2*ArcCsc[Sqrt[x]]}
{x^2*ArcCsc[Sqrt[x]], x, 5, (8/45)*Sqrt[1 - 1/x]*Sqrt[x] + (4/45)*Sqrt[1 - 1/x]*x^(3/2) + (1/15)*Sqrt[1 - 1/x]*x^(5/2) + (1/3)*x^3*ArcCsc[Sqrt[x]]}
{ArcCsc[Sqrt[x]]/x, x, 7, I*ArcCsc[Sqrt[x]]^2 - 2*ArcCsc[Sqrt[x]]*Log[1 - E^(2*I*ArcCsc[Sqrt[x]])] + I*PolyLog[2, E^(2*I*ArcCsc[Sqrt[x]])]}
{ArcCsc[Sqrt[x]]/x^2, x, 5, -(Sqrt[-1 + x]/(2*x)) + ArcCsc[Sqrt[x]]/2 - ArcCsc[Sqrt[x]]/x, -(Sqrt[1 - 1/x]/(2*Sqrt[x])) + ArcCsc[Sqrt[x]]/2 - ArcCsc[Sqrt[x]]/x}
{ArcCsc[Sqrt[x]]/x^3, x, 6, -(Sqrt[-1 + x]/(8*x^2)) - (3*Sqrt[-1 + x])/(16*x) + (3*ArcCsc[Sqrt[x]])/16 - ArcCsc[Sqrt[x]]/(2*x^2), -(Sqrt[1 - 1/x]/(8*x^(3/2))) - (3*Sqrt[1 - 1/x])/(16*Sqrt[x]) + (3*ArcCsc[Sqrt[x]])/16 - ArcCsc[Sqrt[x]]/(2*x^2)}


(* ::Subsection::Closed:: *)
(*Integrands involving inverse trig functions of exponentials*)


{ArcCsc[c*E^(a + b*x)], x, 7, (I*ArcCsc[c*E^(a + b*x)]^2)/(2*b) - (ArcCsc[c*E^(a + b*x)]*Log[1 - E^(2*I*ArcCsc[c*E^(a + b*x)])])/b + (I*PolyLog[2, E^(2*I*ArcCsc[c*E^(a + b*x)])])/(2*b)}


(* ::Subsection::Closed:: *)
(*Integrands involving exponentials of inverse trig functions*)


(* Integrands of the form x^m*E^ArcCsc[x] where m is an integer *)
{E^ArcCsc[x], x, 2, -Subst[Int[E^x*Cot[x]*Csc[x], x], x, ArcCsc[x]]}
{E^ArcCsc[x]/x, x, 2, -Subst[Int[E^x*Cot[x],x],x,ArcCsc[x]]}
{E^ArcCsc[x]/x^2, x, 3, (-(1/2))*E^ArcCsc[x]*Sqrt[1 - 1/x^2] - E^ArcCsc[x]/(2*x)}
{E^ArcCsc[x]/x^3, x, 5, (1/5)*E^ArcCsc[x]*Cos[2*ArcCsc[x]] - (1/10)*E^ArcCsc[x]*Sin[2*ArcCsc[x]]}
{E^ArcCsc[x]/x^4, x, 6, (-(1/8))*E^ArcCsc[x]*Sqrt[1 - 1/x^2] - E^ArcCsc[x]/(8*x) + (1/40)*E^ArcCsc[x]*Cos[3*ArcCsc[x]] + (3/40)*E^ArcCsc[x]*Sin[3*ArcCsc[x]]}
{E^ArcCsc[x]/x^5, x, 6, (1/10)*E^ArcCsc[x]*Cos[2*ArcCsc[x]] - (1/34)*E^ArcCsc[x]*Cos[4*ArcCsc[x]] - (1/20)*E^ArcCsc[x]*Sin[2*ArcCsc[x]] + (1/136)*E^ArcCsc[x]*Sin[4*ArcCsc[x]]}


(* ::Subsection::Closed:: *)
(*Miscellaneous problems*)


{ArcCsc[1/x], x, 1, Sqrt[1 - x^2] + x*ArcSin[x]}


{ArcCsc[a + b*x]/((a*d)/b + d*x), x, 9, (I*ArcCsc[a + b*x]^2)/(2*d) - (ArcCsc[a + b*x]*Log[1 - E^(2*I*ArcCsc[a + b*x])])/d + (I*PolyLog[2, E^(2*I*ArcCsc[a + b*x])])/(2*d)}


{ArcCsc[a*x^n]/x, x, 7, (I*ArcCsc[a*x^n]^2)/(2*n) - (ArcCsc[a*x^n]*Log[1 - E^(2*I*ArcCsc[a*x^n])])/n + (I*PolyLog[2, E^(2*I*ArcCsc[a*x^n])])/(2*n)}

{ArcCsc[a*x^5]/x, x, 7, (1/10)*I*ArcCsc[a*x^5]^2 - (1/5)*ArcCsc[a*x^5]*Log[1 - E^(2*I*ArcCsc[a*x^5])] + (1/10)*I*PolyLog[2, E^(2*I*ArcCsc[a*x^5])]}


{x^3*ArcCsc[a + b*x^4], x, 4, ((a + b*x^4)*ArcCsc[a + b*x^4])/(4*b) + ArcTanh[Sqrt[1 - 1/(a + b*x^4)^2]]/(4*b)}

{x^(n-1)*ArcCsc[a + b*x^n], x, 4, ((a + b*x^n)*ArcCsc[a + b*x^n])/(b*n) + ArcTanh[Sqrt[1 - 1/(a + b*x^n)^2]]/(b*n)}
