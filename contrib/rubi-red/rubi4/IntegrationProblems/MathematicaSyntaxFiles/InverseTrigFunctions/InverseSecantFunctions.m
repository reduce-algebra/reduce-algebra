(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Inverse Secants*)


(* ::Subsection::Closed:: *)
(*Integrands involving inverse secants*)


(* Integrands of the form x^m*ArcSec[a*x] where m is an integer *)
{x*ArcSec[a*x], x, 2, -((Sqrt[1 - 1/(a^2*x^2)]*x)/(2*a)) + (1/2)*x^2*ArcSec[a*x]}
{x^2*ArcSec[a*x], x, 3, -((Sqrt[1 - 1/(a^2*x^2)]*x^2)/(6*a)) + (1/3)*x^3*ArcSec[a*x] - ArcTanh[Sqrt[1 - 1/(a^2*x^2)]]/(6*a^3)}
{x^3*ArcSec[a*x], x, 3, -((Sqrt[1 - 1/(a^2*x^2)]*x)/(6*a^3)) - (Sqrt[1 - 1/(a^2*x^2)]*x^3)/(12*a) + (1/4)*x^4*ArcSec[a*x]}
{x^4*ArcSec[a*x], x, 4, -((3*Sqrt[1 - 1/(a^2*x^2)]*x^2)/(40*a^3)) - (Sqrt[1 - 1/(a^2*x^2)]*x^4)/(20*a) + (1/5)*x^5*ArcSec[a*x] - (3*ArcTanh[Sqrt[1 - 1/(a^2*x^2)]])/(40*a^5)}

{ArcSec[a*x]/x, x, 6, (1/2)*I*ArcSec[a*x]^2 - ArcSec[a*x]*Log[1 + E^(2*I*ArcSec[a*x])] + (1/2)*I*PolyLog[2, -E^(2*I*ArcSec[a*x])]}
{ArcSec[a*x]/x^2, x, 3, a*Sqrt[1 - 1/(a^2*x^2)] - ArcSec[a*x]/x}
{ArcSec[a*x]/x^3, x, 4, (a*Sqrt[1 - 1/(a^2*x^2)])/(4*x) - (1/4)*a^2*ArcCsc[a*x] - ArcSec[a*x]/(2*x^2)}
{ArcSec[a*x]/x^4, x, 4, (2/9)*a^3*Sqrt[1 - 1/(a^2*x^2)] + (a*Sqrt[1 - 1/(a^2*x^2)])/(9*x^2) - ArcSec[a*x]/(3*x^3)}


(* Integrands of the form x^m*ArcSec[a+b*x] where m is an integer *)
{ArcSec[a + b*x], x, 3, ((a + b*x)*ArcSec[a + b*x])/b - ArcTanh[Sqrt[1 - 1/(a + b*x)^2]]/b}
{x*ArcSec[a + b*x], x, 7, -(((a + b*x)*Sqrt[1 - 1/(a + b*x)^2])/(2*b^2)) - (a*(a + b*x)*ArcSec[a + b*x])/b^2 + ((a + b*x)^2*ArcSec[a + b*x])/(2*b^2) + (a*ArcTanh[Sqrt[1 - 1/(a + b*x)^2]])/b^2}
{x^2*ArcSec[a + b*x], x, 10, (a*(a + b*x)*Sqrt[1 - 1/(a + b*x)^2])/b^3 - ((a + b*x)^2*Sqrt[1 - 1/(a + b*x)^2])/(6*b^3) + (a^2*(a + b*x)*ArcSec[a + b*x])/b^3 - (a*(a + b*x)^2*ArcSec[a + b*x])/b^3 + ((a + b*x)^3*ArcSec[a + b*x])/(3*b^3) - ArcTanh[Sqrt[1 - 1/(a + b*x)^2]]/(6*b^3) - (a^2*ArcTanh[Sqrt[1 - 1/(a + b*x)^2]])/b^3}
{ArcSec[a + b*x]/x, x, 4, Int[ArcSec[a + b*x]/x, x]}
(* {ArcSec[a + b*x]/x^2, x, 0, (b*ArcCsc[a + b*x])/a - ArcSec[a + b*x]/x - (Sqrt[-1 + (a + b*x)^2]*ArcTanh[(-(1/b) + (a*(a + b*x))/b)/(Sqrt[-(1/b^2) + a^2/b^2]*Sqrt[-1 + (a + b*x)^2])])/(a*Sqrt[-(1/b^2) + a^2/b^2]*(a + b*x)*Sqrt[1 - 1/(a + b*x)^2])} *)


(* Integrands of the form x^m*ArcSec[Sqrt[x]] where m is an integer *)
{ArcSec[Sqrt[x]], x, 3, -Sqrt[-1 + x] + x*ArcSec[Sqrt[x]]}
{x*ArcSec[Sqrt[x]], x, 4, (-(1/3))*Sqrt[1 - 1/x]*Sqrt[x] - (1/6)*Sqrt[1 - 1/x]*x^(3/2) + (1/2)*x^2*ArcSec[Sqrt[x]]}
{x^2*ArcSec[Sqrt[x]], x, 5, (-(8/45))*Sqrt[1 - 1/x]*Sqrt[x] - (4/45)*Sqrt[1 - 1/x]*x^(3/2) - (1/15)*Sqrt[1 - 1/x]*x^(5/2) + (1/3)*x^3*ArcSec[Sqrt[x]]}
{ArcSec[Sqrt[x]]/x, x, 6, I*ArcSec[Sqrt[x]]^2 - 2*ArcSec[Sqrt[x]]*Log[1 + E^(2*I*ArcSec[Sqrt[x]])] + I*PolyLog[2, -E^(2*I*ArcSec[Sqrt[x]])]}
{ArcSec[Sqrt[x]]/x^2, x, 5, Sqrt[-1 + x]/(2*x) - ArcCsc[Sqrt[x]]/2 - ArcSec[Sqrt[x]]/x, Sqrt[1 - 1/x]/(2*Sqrt[x]) - ArcCsc[Sqrt[x]]/2 - ArcSec[Sqrt[x]]/x}
{ArcSec[Sqrt[x]]/x^3, x, 6, Sqrt[-1 + x]/(8*x^2) + (3*Sqrt[-1 + x])/(16*x) - (3*ArcCsc[Sqrt[x]])/16 - ArcSec[Sqrt[x]]/(2*x^2), Sqrt[1 - 1/x]/(8*x^(3/2)) + (3*Sqrt[1 - 1/x])/(16*Sqrt[x]) - (3*ArcCsc[Sqrt[x]])/16 - ArcSec[Sqrt[x]]/(2*x^2)}


(* ::Subsection::Closed:: *)
(*Integrands involving inverse trig functions of exponentials*)


{ArcSec[c*E^(a + b*x)], x, 7, (I*ArcSec[c*E^(a + b*x)]^2)/(2*b) - (ArcSec[c*E^(a + b*x)]*Log[1 + E^(2*I*ArcSec[c*E^(a + b*x)])])/b + (I*PolyLog[2, -E^(2*I*ArcSec[c*E^(a + b*x)])])/(2*b)}


(* ::Subsection::Closed:: *)
(*Integrands involving exponentials of inverse trig functions*)


(* Integrands of the form x^m*E^ArcSec[x] where m is an integer *)
{E^ArcSec[x], x, 1, Subst[Int[E^x*Sec[x]*Tan[x], x], x, ArcSec[x]]}
{E^ArcSec[x]/x, x, 1, Subst[Int[E^x*Tan[x],x],x,ArcSec[x]]}
{E^ArcSec[x]/x^2, x, 2, (1/2)*E^ArcSec[x]*Sqrt[1 - 1/x^2] - E^ArcSec[x]/(2*x)}


(* ::Subsection::Closed:: *)
(*Miscellaneous problems*)


{ArcSec[1/x], x, 1, -Sqrt[1 - x^2] + x*ArcCos[x]}


{ArcSec[a + b*x]/((a*d)/b + d*x), x, 8, (I*ArcSec[a + b*x]^2)/(2*d) - (ArcSec[a + b*x]*Log[1 + E^(2*I*ArcSec[a + b*x])])/d + (I*PolyLog[2, -E^(2*I*ArcSec[a + b*x])])/(2*d)}


{ArcSec[a*x^n]/x, x, 7, (I*ArcSec[a*x^n]^2)/(2*n) - (ArcSec[a*x^n]*Log[1 + E^(2*I*ArcSec[a*x^n])])/n + (I*PolyLog[2, -E^(2*I*ArcSec[a*x^n])])/(2*n)}

{ArcSec[a*x^5]/x, x, 7, (1/10)*I*ArcSec[a*x^5]^2 - (1/5)*ArcSec[a*x^5]*Log[1 + E^(2*I*ArcSec[a*x^5])] + (1/10)*I*PolyLog[2, -E^(2*I*ArcSec[a*x^5])]}


{x^3*ArcSec[a + b*x^4], x, 4, ((a + b*x^4)*ArcSec[a + b*x^4])/(4*b) - ArcTanh[Sqrt[1 - 1/(a + b*x^4)^2]]/(4*b)}

{x^(n-1)*ArcSec[a + b*x^n], x, 4, ((a + b*x^n)*ArcSec[a + b*x^n])/(b*n) - ArcTanh[Sqrt[1 - 1/(a + b*x^n)^2]]/(b*n)}
