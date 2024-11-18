(* ::Package:: *)

(* ::Title:: *)
(*Integrands of the form trig(c+d x)^m (a+b sin(c+d x))^n*)


(* ::Section::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (a+b Sin[c+d x])^n when a^2-b^2=0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (a+b Sin[c+d x])^n when a^2-b^2=0*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Cos[c + d*x]^m*(a + a*Sin[c + d*x]), x, 2, -((a*Cos[c + d*x]^(1 + m))/(d*(1 + m))) + (a*Cos[c + d*x]^(1 + m)*(Cos[c + d*x]^2)^((1/2)*(-1 - m))*Hypergeometric2F1[1/2, (1 - m)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/d}

{Cos[c + d*x]^5*(a + a*Sin[c + d*x]), x, 3, -((a*Cos[c + d*x]^6)/(6*d)) + (a*Sin[c + d*x])/d - (2*a*Sin[c + d*x]^3)/(3*d) + (a*Sin[c + d*x]^5)/(5*d)}
{Cos[c + d*x]^4*(a + a*Sin[c + d*x]), x, 3, (3*a*x)/8 - (a*Cos[c + d*x]^5)/(5*d) + (3*a*Cos[c + d*x]*Sin[c + d*x])/(8*d) + (a*Cos[c + d*x]^3*Sin[c + d*x])/(4*d)}
{Cos[c + d*x]^3*(a + a*Sin[c + d*x]), x, 3, -((a*Cos[c + d*x]^4)/(4*d)) + (a*Sin[c + d*x])/d - (a*Sin[c + d*x]^3)/(3*d)}
{Cos[c + d*x]^2*(a + a*Sin[c + d*x]), x, 2, (a*x)/2 - (a*Cos[c + d*x]^3)/(3*d) + (a*Cos[c + d*x]*Sin[c + d*x])/(2*d)}
{Cos[c + d*x]^1*(a + a*Sin[c + d*x]), x, 2, -((a*Cos[c + d*x]^2)/(2*d)) + (a*Sin[c + d*x])/d}
{Cos[c + d*x]^0*(a + a*Sin[c + d*x]), x, 2, a*x - (a*Cos[c + d*x])/d}
{Sec[c + d*x]^1*(a + a*Sin[c + d*x]), x, 1, -((a*Log[1 - Sin[c + d*x]])/d)}
{Sec[c + d*x]^2*(a + a*Sin[c + d*x]), x, 2, (a*Sec[c + d*x])/d + (a*Tan[c + d*x])/d}
{Sec[c + d*x]^3*(a + a*Sin[c + d*x]), x, 3, (a*ArcTanh[Sin[c + d*x]])/(2*d) + (a*Sec[c + d*x]^2)/(2*d) + (a*Sec[c + d*x]*Tan[c + d*x])/(2*d)}
{Sec[c + d*x]^4*(a + a*Sin[c + d*x]), x, 3, (a*Sec[c + d*x]^3)/(3*d) + (a*Tan[c + d*x])/d + (a*Tan[c + d*x]^3)/(3*d)}
{Sec[c + d*x]^5*(a + a*Sin[c + d*x]), x, 4, (3*a*ArcTanh[Sin[c + d*x]])/(8*d) + (a*Sec[c + d*x]^4)/(4*d) + (3*a*Sec[c + d*x]*Tan[c + d*x])/(8*d) + (a*Sec[c + d*x]^3*Tan[c + d*x])/(4*d)}


{Cos[c + d*x]^m*(a + a*Sin[c + d*x])^2, x, 3, -((a^2*(3 + m)*Cos[c + d*x]^(1 + m))/(d*(1 + m)*(2 + m))) + (a^2*(3 + m)*Cos[c + d*x]^(1 + m)*(Cos[c + d*x]^2)^((1/2)*(-1 - m))*Hypergeometric2F1[1/2, (1 - m)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(2 + m)) - (Cos[c + d*x]^(1 + m)*(a^2 + a^2*Sin[c + d*x]))/(d*(2 + m))}

{Cos[c + d*x]^5*(a + a*Sin[c + d*x])^2, x, 4, (4*a^2*(1 + Sin[c + d*x])^5)/(5*d) - (2*a^2*(1 + Sin[c + d*x])^6)/(3*d) + (a^2*(1 + Sin[c + d*x])^7)/(7*d)}
{Cos[c + d*x]^4*(a + a*Sin[c + d*x])^2, x, 4, (7*a^2*x)/16 - (7*a^2*Cos[c + d*x]^5)/(30*d) + (7*a^2*Cos[c + d*x]*Sin[c + d*x])/(16*d) + (7*a^2*Cos[c + d*x]^3*Sin[c + d*x])/(24*d) - (Cos[c + d*x]^5*(a^2 + a^2*Sin[c + d*x]))/(6*d)}
{Cos[c + d*x]^3*(a + a*Sin[c + d*x])^2, x, 4, (a^2*Sin[c + d*x])/d + (a^2*Sin[c + d*x]^2)/d - (a^2*Sin[c + d*x]^4)/(2*d) - (a^2*Sin[c + d*x]^5)/(5*d)}
{Cos[c + d*x]^2*(a + a*Sin[c + d*x])^2, x, 3, (5*a^2*x)/8 - (5*a^2*Cos[c + d*x]^3)/(12*d) + (5*a^2*Cos[c + d*x]*Sin[c + d*x])/(8*d) - (Cos[c + d*x]^3*(a^2 + a^2*Sin[c + d*x]))/(4*d)}
{Cos[c + d*x]^1*(a + a*Sin[c + d*x])^2, x, 2, (a^2*(1 + Sin[c + d*x])^3)/(3*d)}
{Cos[c + d*x]^0*(a + a*Sin[c + d*x])^2, x, 2, (3*a^2*x)/2 - (2*a^2*Cos[c + d*x])/d - (a^2*Cos[c + d*x]*Sin[c + d*x])/(2*d)}
{Sec[c + d*x]^1*(a + a*Sin[c + d*x])^2, x, 4, -((2*a^2*Log[1 - Sin[c + d*x]])/d) - (a^2*Sin[c + d*x])/d}
{Sec[c + d*x]^2*(a + a*Sin[c + d*x])^2, x, 2, (-a^2)*x + (2*Sec[c + d*x]*(a^2 + a^2*Sin[c + d*x]))/d}
{Sec[c + d*x]^3*(a + a*Sin[c + d*x])^2, x, 3, a^2/(d*(1 - Sin[c + d*x]))}
{Sec[c + d*x]^4*(a + a*Sin[c + d*x])^2, x, 2, (2*Sec[c + d*x]^3*(a^2 + a^2*Sin[c + d*x]))/(3*d) + (a^2*Tan[c + d*x])/(3*d)}
{Sec[c + d*x]^5*(a + a*Sin[c + d*x])^2, x, 5, (a^2*ArcTanh[Sin[c + d*x]])/(4*d) + a^2/(4*d*(1 - Sin[c + d*x])^2) + a^2/(4*d*(1 - Sin[c + d*x]))}
{Sec[c + d*x]^6*(a + a*Sin[c + d*x])^2, x, 3, (2*Sec[c + d*x]^5*(a^2 + a^2*Sin[c + d*x]))/(5*d) + (3*a^2*Tan[c + d*x])/(5*d) + (a^2*Tan[c + d*x]^3)/(5*d)}


{Cos[c + d*x]^m*(a + a*Sin[c + d*x])^3, x, 4, -((a^3*(5 + m)*Cos[c + d*x]^(1 + m))/(d*(1 + m)*(2 + m))) + (a^3*(5 + m)*Cos[c + d*x]^(1 + m)*(Cos[c + d*x]^2)^((1/2)*(-1 - m))*Hypergeometric2F1[1/2, (1 - m)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(d*(2 + m)) - (a*Cos[c + d*x]^(1 + m)*(a + a*Sin[c + d*x])^2)/(d*(3 + m)) - ((5 + m)*Cos[c + d*x]^(1 + m)*(a^3 + a^3*Sin[c + d*x]))/(d*(2 + m)*(3 + m))}

{Cos[c + d*x]^5*(a + a*Sin[c + d*x])^3, x, 4, (2*a^3*(1 + Sin[c + d*x])^6)/(3*d) - (4*a^3*(1 + Sin[c + d*x])^7)/(7*d) + (a^3*(1 + Sin[c + d*x])^8)/(8*d)}
{Cos[c + d*x]^4*(a + a*Sin[c + d*x])^3, x, 5, (9*a^3*x)/16 - (3*a^3*Cos[c + d*x]^5)/(10*d) + (9*a^3*Cos[c + d*x]*Sin[c + d*x])/(16*d) + (3*a^3*Cos[c + d*x]^3*Sin[c + d*x])/(8*d) - (a*Cos[c + d*x]^5*(a + a*Sin[c + d*x])^2)/(7*d) - (3*Cos[c + d*x]^5*(a^3 + a^3*Sin[c + d*x]))/(14*d)}
{Cos[c + d*x]^3*(a + a*Sin[c + d*x])^3, x, 4, (2*a^3*(1 + Sin[c + d*x])^5)/(5*d) - (a^3*(1 + Sin[c + d*x])^6)/(6*d)}
{Cos[c + d*x]^2*(a + a*Sin[c + d*x])^3, x, 4, (7*a^3*x)/8 - (7*a^3*Cos[c + d*x]^3)/(12*d) + (7*a^3*Cos[c + d*x]*Sin[c + d*x])/(8*d) - (a*Cos[c + d*x]^3*(a + a*Sin[c + d*x])^2)/(5*d) - (7*Cos[c + d*x]^3*(a^3 + a^3*Sin[c + d*x]))/(20*d)}
{Cos[c + d*x]^1*(a + a*Sin[c + d*x])^3, x, 2, (a^3*(1 + Sin[c + d*x])^4)/(4*d)}
{Cos[c + d*x]^0*(a + a*Sin[c + d*x])^3, x, 3, (5*a^3*x)/2 - (10*a^3*Cos[c + d*x])/(3*d) - (5*a^3*Cos[c + d*x]*Sin[c + d*x])/(6*d) - (a*Cos[c + d*x]*(a + a*Sin[c + d*x])^2)/(3*d)}
{Sec[c + d*x]^1*(a + a*Sin[c + d*x])^3, x, 4, -((4*a^3*Log[1 - Sin[c + d*x]])/d) - (2*a^3*Sin[c + d*x])/d - (a^3*(1 + Sin[c + d*x])^2)/(2*d)}
{Sec[c + d*x]^2*(a + a*Sin[c + d*x])^3, x, 3, -3*a^3*x + (3*a^3*Cos[c + d*x])/d + (2*a*Sec[c + d*x]*(a + a*Sin[c + d*x])^2)/d}
{Sec[c + d*x]^3*(a + a*Sin[c + d*x])^3, x, 4, (a^3*Log[1 - Sin[c + d*x]])/d + (2*a^3)/(d*(1 - Sin[c + d*x]))}
{Sec[c + d*x]^4*(a + a*Sin[c + d*x])^3, x, 1, (Sec[c + d*x]^3*(a + a*Sin[c + d*x])^3)/(3*d)}
{Sec[c + d*x]^5*(a + a*Sin[c + d*x])^3, x, 3, a^3/(2*d*(1 - Sin[c + d*x])^2)}
{Sec[c + d*x]^6*(a + a*Sin[c + d*x])^3, x, 4, (a^3*Sec[c + d*x]^3)/(15*d) + (2*a*Sec[c + d*x]^5*(a + a*Sin[c + d*x])^2)/(5*d) + (a^3*Tan[c + d*x])/(5*d) + (a^3*Tan[c + d*x]^3)/(15*d)}
{Sec[c + d*x]^7*(a + a*Sin[c + d*x])^3, x, 5, (a^3*ArcTanh[Sin[c + d*x]])/(8*d) + a^3/(6*d*(1 - Sin[c + d*x])^3) + a^3/(8*d*(1 - Sin[c + d*x])^2) + a^3/(8*d*(1 - Sin[c + d*x]))}
{Sec[c + d*x]^8*(a + a*Sin[c + d*x])^3, x, 4, (3*a^3*Sec[c + d*x]^5)/(35*d) + (2*a*Sec[c + d*x]^7*(a + a*Sin[c + d*x])^2)/(7*d) + (3*a^3*Tan[c + d*x])/(7*d) + (2*a^3*Tan[c + d*x]^3)/(7*d) + (3*a^3*Tan[c + d*x]^5)/(35*d)}


{Cos[c + d*x]^2*(a + a*Sin[c + d*x])^4, x, 5, (21*a^4*x)/16 - (7*a^4*Cos[c + d*x]^3)/(8*d) + (21*a^4*Cos[c + d*x]*Sin[c + d*x])/(16*d) - (a*Cos[c + d*x]^3*(a + a*Sin[c + d*x])^3)/(6*d) - (3*Cos[c + d*x]^3*(a^2 + a^2*Sin[c + d*x])^2)/(10*d) - (21*Cos[c + d*x]^3*(a^4 + a^4*Sin[c + d*x]))/(40*d)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Cos[c + d*x]^m/(a + a*Sin[c + d*x]), x, 2, -(Cos[c + d*x]^(-1 + m)/(a*d*(1 - m))) + (Cos[c + d*x]^(-1 + m)*(Cos[c + d*x]^2)^((1 - m)/2)*Hypergeometric2F1[1/2, (3 - m)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(a*d)}

{Cos[x]^6/(a + a*Sin[x]), x, 3, (3*x)/(8*a) + Cos[x]^5/(5*a) + (3*Cos[x]*Sin[x])/(8*a) + (Cos[x]^3*Sin[x])/(4*a)}
{Cos[x]^5/(a + a*Sin[x]), x, 4, Cos[x]^4/(4*a) + Sin[x]/a - Sin[x]^3/(3*a), Sin[x]/a - Sin[x]^2/(2*a) - Sin[x]^3/(3*a) + Sin[x]^4/(4*a)}
{Cos[x]^4/(a + a*Sin[x]), x, 2, x/(2*a) + Cos[x]^3/(3*a) + (Cos[x]*Sin[x])/(2*a)}
{Cos[x]^3/(a + a*Sin[x]), x, 3, Sin[x]/a - Sin[x]^2/(2*a)}
{Cos[x]^2/(a + a*Sin[x]), x, 2, x/a + Cos[x]/a}
{Cos[x]^1/(a + a*Sin[x]), x, 2, Log[1 + Sin[x]]/a}
{Cos[x]^0/(a + a*Sin[x]), x, 1, -(Cos[x]/(a + a*Sin[x]))}
{Sec[x]^1/(a + a*Sin[x]), x, 5, ArcTanh[Sin[x]]/(2*a) - 1/(2*a*(1 + Sin[x]))}
{Sec[x]^2/(a + a*Sin[x]), x, 3, -(Sec[x]^3/(3*a)) + Tan[x]/a + Tan[x]^3/(3*a)}
{Sec[x]^3/(a + a*Sin[x]), x, 5, (3*ArcTanh[Sin[x]])/(8*a) + 1/(8*a*(1 - Sin[x])) - 1/(8*a*(1 + Sin[x])^2) - 1/(4*a*(1 + Sin[x]))}
{Sec[x]^4/(a + a*Sin[x]), x, 3, -(Sec[x]^5/(5*a)) + Tan[x]/a + (2*Tan[x]^3)/(3*a) + Tan[x]^5/(5*a)}


{Cos[c + d*x]^m/(a + a*Sin[c + d*x])^2, x, 3, -(Cos[c + d*x]^(-1 + m)/(a^2*d*(3 - m))) + ((1 - m)*Cos[c + d*x]^(-1 + m)*(Cos[c + d*x]^2)^((1 - m)/2)*Hypergeometric2F1[1/2, (3 - m)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(a^2*d*(3 - m)) - Cos[c + d*x]^(1 + m)/(d*(3 - m)*(a + a*Sin[c + d*x])^2)}

{Cos[x]^7/(a + a*Sin[x])^2, x, 4, Sin[x]/a^2 - Sin[x]^2/a^2 + Sin[x]^4/(2*a^2) - Sin[x]^5/(5*a^2)}
{Cos[x]^6/(a + a*Sin[x])^2, x, 3, (5*x)/(8*a^2) + (5*Cos[x]*Sin[x])/(8*a^2) + (5*Cos[x]^3*Sin[x])/(12*a^2) + (2*Cos[x]^5)/(3*(a^2 + a^2*Sin[x]))}
{Cos[x]^5/(a + a*Sin[x])^2, x, 3, -((1 - Sin[x])^3/(3*a^2))}
{Cos[x]^4/(a + a*Sin[x])^2, x, 2, (3*x)/(2*a^2) + (3*Cos[x]*Sin[x])/(2*a^2) + (2*Cos[x]^3)/(a^2 + a^2*Sin[x])}
{Cos[x]^3/(a + a*Sin[x])^2, x, 4, (2*Log[1 + Sin[x]])/a^2 - Sin[x]/a^2}
{Cos[x]^2/(a + a*Sin[x])^2, x, 2, -(x/a^2) - (2*Cos[x])/(a^2 + a^2*Sin[x])}
{Cos[x]^1/(a + a*Sin[x])^2, x, 2, -(1/(a^2*(1 + Sin[x])))}
{Cos[x]^0/(a + a*Sin[x])^2, x, 2, -(Cos[x]/(3*(a + a*Sin[x])^2)) - Cos[x]/(3*(a^2 + a^2*Sin[x]))}
{Sec[x]^1/(a + a*Sin[x])^2, x, 5, ArcTanh[Sin[x]]/(4*a^2) - 1/(4*a^2*(1 + Sin[x])^2) - 1/(4*a^2*(1 + Sin[x]))}
{Sec[x]^2/(a + a*Sin[x])^2, x, 4, -(Sec[x]^3/(5*a^2)) - Sec[x]/(5*(a + a*Sin[x])^2) + (3*Tan[x])/(5*a^2) + Tan[x]^3/(5*a^2)}
{Sec[x]^3/(a + a*Sin[x])^2, x, 5, ArcTanh[Sin[x]]/(4*a^2) + 1/(16*a^2*(1 - Sin[x])) - 1/(12*a^2*(1 + Sin[x])^3) - 1/(8*a^2*(1 + Sin[x])^2) - 3/(16*a^2*(1 + Sin[x]))}


{Cos[c + d*x]^m/(a + a*Sin[c + d*x])^3, x, 4, -(((2 - m)*Cos[c + d*x]^(-1 + m))/(a^3*d*(3 - m)*(5 - m))) + ((1 - m)*(2 - m)*Cos[c + d*x]^(-1 + m)*(Cos[c + d*x]^2)^((1 - m)/2)*Hypergeometric2F1[1/2, (3 - m)/2, 3/2, Sin[c + d*x]^2]*Sin[c + d*x])/(a^3*d*(3 - m)*(5 - m)) - Cos[c + d*x]^(1 + m)/(d*(5 - m)*(a + a*Sin[c + d*x])^3) - ((2 - m)*Cos[c + d*x]^(1 + m))/(a*d*(3 - m)*(5 - m)*(a + a*Sin[c + d*x])^2)}

{Cos[x]^1/(1 + Sin[x])^3, x, 2, -(1/(2*(1 + Sin[x])^2))}
{Cos[x]^1/(1 - Sin[x])^3, x, 2, 1/(2*(1 - Sin[x])^2)}
{Cos[x]^2/(1 + Sin[x])^3, x, 1, -(Cos[x]^3/(3*(1 + Sin[x])^3))}
{Cos[x]^2/(1 - Sin[x])^3, x, 1, Cos[x]^3/(3*(1 - Sin[x])^3)}
{Cos[x]^3/(1 + Sin[x])^3, x, 4, -Log[1 + Sin[x]] - 2/(1 + Sin[x])}
{Cos[x]^3/(1 - Sin[x])^3, x, 4, Log[1 - Sin[x]] + 2/(1 - Sin[x])}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (a+b Sin[c+d x])^(n/2) when a^2-b^2=0*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Cos[c + d*x]^6*(a + a*Sin[c + d*x])^(1/2), x, 6, -((512*a^3*Cos[c + d*x]^5)/(3003*d*(a + a*Sin[c + d*x])^(5/2))) - (640*a^2*Cos[c + d*x]^5)/(3003*d*(a + a*Sin[c + d*x])^(3/2)) - (24*a^2*Cos[c + d*x]^7)/(143*d*(a + a*Sin[c + d*x])^(3/2)) + (64*a*Cos[c + d*x]^5)/(429*d*Sqrt[a + a*Sin[c + d*x]]) - (2*a*Cos[c + d*x]^7)/(13*d*Sqrt[a + a*Sin[c + d*x]])}
{Cos[c + d*x]^5*(a + a*Sin[c + d*x])^(1/2), x, 4, (8*(a + a*Sin[c + d*x])^(7/2))/(7*a^3*d) - (8*(a + a*Sin[c + d*x])^(9/2))/(9*a^4*d) + (2*(a + a*Sin[c + d*x])^(11/2))/(11*a^5*d)}
{Cos[c + d*x]^4*(a + a*Sin[c + d*x])^(1/2), x, 3, -((64*a^3*Cos[c + d*x]^5)/(315*d*(a + a*Sin[c + d*x])^(5/2))) - (16*a^2*Cos[c + d*x]^5)/(63*d*(a + a*Sin[c + d*x])^(3/2)) - (2*a*Cos[c + d*x]^5)/(9*d*Sqrt[a + a*Sin[c + d*x]])}
{Cos[c + d*x]^3*(a + a*Sin[c + d*x])^(1/2), x, 4, (4*(a + a*Sin[c + d*x])^(5/2))/(5*a^2*d) - (2*(a + a*Sin[c + d*x])^(7/2))/(7*a^3*d)}
{Cos[c + d*x]^2*(a + a*Sin[c + d*x])^(1/2), x, 2, -((8*a^2*Cos[c + d*x]^3)/(15*d*(a + a*Sin[c + d*x])^(3/2))) - (2*a*Cos[c + d*x]^3)/(5*d*Sqrt[a + a*Sin[c + d*x]])}
{Cos[c + d*x]^1*(a + a*Sin[c + d*x])^(1/2), x, 2, (2*(a + a*Sin[c + d*x])^(3/2))/(3*a*d)}
{Cos[c + d*x]^0*(a + a*Sin[c + d*x])^(1/2), x, 1, -((2*a*Cos[c + d*x])/(d*Sqrt[a + a*Sin[c + d*x]]))}
{Sec[c + d*x]^1*(a + a*Sin[c + d*x])^(1/2), x, 3, (Sqrt[2]*Sqrt[a]*ArcTanh[Sqrt[a + a*Sin[c + d*x]]/(Sqrt[2]*Sqrt[a])])/d}
{Sec[c + d*x]^2*(a + a*Sin[c + d*x])^(1/2), x, 2, -((a*ArcTanh[Sin[Pi/4 + (1/2)*(-c - d*x)]]*Cos[Pi/4 + (1/2)*(-c - d*x)])/(d*Sqrt[a + a*Sin[c + d*x]])) + (Sec[c + d*x]*Sqrt[a + a*Sin[c + d*x]])/d}
{Sec[c + d*x]^3*(a + a*Sin[c + d*x])^(1/2), x, 5, (3*Sqrt[a]*ArcTanh[Sqrt[a + a*Sin[c + d*x]]/(Sqrt[2]*Sqrt[a])])/(4*Sqrt[2]*d) - (3*a)/(4*d*Sqrt[a + a*Sin[c + d*x]]) + a/(2*d*(1 - Sin[c + d*x])*Sqrt[a + a*Sin[c + d*x]])}
{Sec[c + d*x]^4*(a + a*Sin[c + d*x])^(1/2), x, 4, (5*a^2*Cos[c + d*x])/(24*d*(a + a*Sin[c + d*x])^(3/2)) - (5*a*ArcTanh[Sin[Pi/4 + (1/2)*(-c - d*x)]]*Cos[Pi/4 + (1/2)*(-c - d*x)])/(8*d*Sqrt[a + a*Sin[c + d*x]]) + (Sec[c + d*x]^3*Sqrt[a + a*Sin[c + d*x]])/(3*d) + (5*a*Tan[c + d*x])/(6*d*Sqrt[a + a*Sin[c + d*x]])}
{Sec[c + d*x]^5*(a + a*Sin[c + d*x])^(1/2), x, 7, (35*Sqrt[a]*ArcTanh[Sqrt[a + a*Sin[c + d*x]]/(Sqrt[2]*Sqrt[a])])/(64*Sqrt[2]*d) - (35*a^2)/(96*d*(a + a*Sin[c + d*x])^(3/2)) + a^2/(4*d*(1 - Sin[c + d*x])^2*(a + a*Sin[c + d*x])^(3/2)) + (7*a^2)/(16*d*(1 - Sin[c + d*x])*(a + a*Sin[c + d*x])^(3/2)) - (35*a)/(64*d*Sqrt[a + a*Sin[c + d*x]])}
{Sec[c + d*x]^6*(a + a*Sin[c + d*x])^(1/2), x, 6, (21*a^2*Cos[c + d*x])/(128*d*(a + a*Sin[c + d*x])^(3/2)) - (21*a^2*Sec[c + d*x])/(80*d*(a + a*Sin[c + d*x])^(3/2)) - (63*a*ArcTanh[Sin[Pi/4 + (1/2)*(-c - d*x)]]*Cos[Pi/4 + (1/2)*(-c - d*x)])/(128*d*Sqrt[a + a*Sin[c + d*x]]) + (3*a*Sec[c + d*x]^3)/(10*d*Sqrt[a + a*Sin[c + d*x]]) + (Sec[c + d*x]^5*Sqrt[a + a*Sin[c + d*x]])/(5*d) + (21*a*Tan[c + d*x])/(32*d*Sqrt[a + a*Sin[c + d*x]])}


{Cos[c + d*x]^6*(a + a*Sin[c + d*x])^(3/2), x, 7, -((8192*a^4*Cos[c + d*x]^5)/(45045*d*(a + a*Sin[c + d*x])^(5/2))) - (2048*a^3*Cos[c + d*x]^5)/(9009*d*(a + a*Sin[c + d*x])^(3/2)) - (128*a^3*Cos[c + d*x]^7)/(715*d*(a + a*Sin[c + d*x])^(3/2)) + (1024*a^2*Cos[c + d*x]^5)/(6435*d*Sqrt[a + a*Sin[c + d*x]]) - (32*a^2*Cos[c + d*x]^7)/(195*d*Sqrt[a + a*Sin[c + d*x]]) - (2*a*Cos[c + d*x]^7*Sqrt[a + a*Sin[c + d*x]])/(15*d)}
{Cos[c + d*x]^5*(a + a*Sin[c + d*x])^(3/2), x, 4, (8*(a + a*Sin[c + d*x])^(9/2))/(9*a^3*d) - (8*(a + a*Sin[c + d*x])^(11/2))/(11*a^4*d) + (2*(a + a*Sin[c + d*x])^(13/2))/(13*a^5*d)}
{Cos[c + d*x]^4*(a + a*Sin[c + d*x])^(3/2), x, 4, -((256*a^4*Cos[c + d*x]^5)/(1155*d*(a + a*Sin[c + d*x])^(5/2))) - (64*a^3*Cos[c + d*x]^5)/(231*d*(a + a*Sin[c + d*x])^(3/2)) - (8*a^2*Cos[c + d*x]^5)/(33*d*Sqrt[a + a*Sin[c + d*x]]) - (2*a*Cos[c + d*x]^5*Sqrt[a + a*Sin[c + d*x]])/(11*d)}
{Cos[c + d*x]^3*(a + a*Sin[c + d*x])^(3/2), x, 4, (4*(a + a*Sin[c + d*x])^(7/2))/(7*a^2*d) - (2*(a + a*Sin[c + d*x])^(9/2))/(9*a^3*d)}
{Cos[c + d*x]^2*(a + a*Sin[c + d*x])^(3/2), x, 3, -((64*a^3*Cos[c + d*x]^3)/(105*d*(a + a*Sin[c + d*x])^(3/2))) - (16*a^2*Cos[c + d*x]^3)/(35*d*Sqrt[a + a*Sin[c + d*x]]) - (2*a*Cos[c + d*x]^3*Sqrt[a + a*Sin[c + d*x]])/(7*d)}
{Cos[c + d*x]^1*(a + a*Sin[c + d*x])^(3/2), x, 2, (2*(a + a*Sin[c + d*x])^(5/2))/(5*a*d)}
{Cos[c + d*x]^0*(a + a*Sin[c + d*x])^(3/2), x, 2, -((8*a^2*Cos[c + d*x])/(3*d*Sqrt[a + a*Sin[c + d*x]])) - (2*a*Cos[c + d*x]*Sqrt[a + a*Sin[c + d*x]])/(3*d)}
{Sec[c + d*x]^1*(a + a*Sin[c + d*x])^(3/2), x, 4, (2*Sqrt[2]*a^(3/2)*ArcTanh[Sqrt[a + a*Sin[c + d*x]]/(Sqrt[2]*Sqrt[a])])/d - (2*a*Sqrt[a + a*Sin[c + d*x]])/d}
{Sec[c + d*x]^2*(a + a*Sin[c + d*x])^(3/2), x, 1, (2*a*Sec[c + d*x]*Sqrt[a + a*Sin[c + d*x]])/d}
{Sec[c + d*x]^3*(a + a*Sin[c + d*x])^(3/2), x, 4, (a^(3/2)*ArcTanh[Sqrt[a + a*Sin[c + d*x]]/(Sqrt[2]*Sqrt[a])])/(2*Sqrt[2]*d) + (a*Sqrt[a + a*Sin[c + d*x]])/(2*d*(1 - Sin[c + d*x]))}
{Sec[c + d*x]^4*(a + a*Sin[c + d*x])^(3/2), x, 4, (a^3*Cos[c + d*x])/(6*d*(a + a*Sin[c + d*x])^(3/2)) - (a^2*ArcTanh[Sin[Pi/4 + (1/2)*(-c - d*x)]]*Cos[Pi/4 + (1/2)*(-c - d*x)])/(2*d*Sqrt[a + a*Sin[c + d*x]]) + (2*a*Sec[c + d*x]^3*Sqrt[a + a*Sin[c + d*x]])/(3*d) + (2*a^2*Tan[c + d*x])/(3*d*Sqrt[a + a*Sin[c + d*x]])}
{Sec[c + d*x]^5*(a + a*Sin[c + d*x])^(3/2), x, 6, (15*a^(3/2)*ArcTanh[Sqrt[a + a*Sin[c + d*x]]/(Sqrt[2]*Sqrt[a])])/(32*Sqrt[2]*d) - (15*a^2)/(32*d*Sqrt[a + a*Sin[c + d*x]]) + a^2/(4*d*(1 - Sin[c + d*x])^2*Sqrt[a + a*Sin[c + d*x]]) + (5*a^2)/(16*d*(1 - Sin[c + d*x])*Sqrt[a + a*Sin[c + d*x]])}
{Sec[c + d*x]^6*(a + a*Sin[c + d*x])^(3/2), x, 6, (7*a^3*Cos[c + d*x])/(48*d*(a + a*Sin[c + d*x])^(3/2)) - (7*a^3*Sec[c + d*x])/(30*d*(a + a*Sin[c + d*x])^(3/2)) - (7*a^2*ArcTanh[Sin[Pi/4 + (1/2)*(-c - d*x)]]*Cos[Pi/4 + (1/2)*(-c - d*x)])/(16*d*Sqrt[a + a*Sin[c + d*x]]) + (4*a^2*Sec[c + d*x]^3)/(15*d*Sqrt[a + a*Sin[c + d*x]]) + (2*a*Sec[c + d*x]^5*Sqrt[a + a*Sin[c + d*x]])/(5*d) + (7*a^2*Tan[c + d*x])/(12*d*Sqrt[a + a*Sin[c + d*x]])}


{Cos[c + d*x]^6*(a + a*Sin[c + d*x])^(5/2), x, 8, -((32768*a^5*Cos[c + d*x]^5)/(153153*d*(a + a*Sin[c + d*x])^(5/2))) - (40960*a^4*Cos[c + d*x]^5)/(153153*d*(a + a*Sin[c + d*x])^(3/2)) - (512*a^4*Cos[c + d*x]^7)/(2431*d*(a + a*Sin[c + d*x])^(3/2)) + (4096*a^3*Cos[c + d*x]^5)/(21879*d*Sqrt[a + a*Sin[c + d*x]]) - (128*a^3*Cos[c + d*x]^7)/(663*d*Sqrt[a + a*Sin[c + d*x]]) - (8*a^2*Cos[c + d*x]^7*Sqrt[a + a*Sin[c + d*x]])/(51*d) - (2*a*Cos[c + d*x]^7*(a + a*Sin[c + d*x])^(3/2))/(17*d)}
{Cos[c + d*x]^5*(a + a*Sin[c + d*x])^(5/2), x, 4, (8*(a + a*Sin[c + d*x])^(11/2))/(11*a^3*d) - (8*(a + a*Sin[c + d*x])^(13/2))/(13*a^4*d) + (2*(a + a*Sin[c + d*x])^(15/2))/(15*a^5*d)}
{Cos[c + d*x]^4*(a + a*Sin[c + d*x])^(5/2), x, 5, -((4096*a^5*Cos[c + d*x]^5)/(15015*d*(a + a*Sin[c + d*x])^(5/2))) - (1024*a^4*Cos[c + d*x]^5)/(3003*d*(a + a*Sin[c + d*x])^(3/2)) - (128*a^3*Cos[c + d*x]^5)/(429*d*Sqrt[a + a*Sin[c + d*x]]) - (32*a^2*Cos[c + d*x]^5*Sqrt[a + a*Sin[c + d*x]])/(143*d) - (2*a*Cos[c + d*x]^5*(a + a*Sin[c + d*x])^(3/2))/(13*d)}
{Cos[c + d*x]^3*(a + a*Sin[c + d*x])^(5/2), x, 4, (4*(a + a*Sin[c + d*x])^(9/2))/(9*a^2*d) - (2*(a + a*Sin[c + d*x])^(11/2))/(11*a^3*d)}
{Cos[c + d*x]^2*(a + a*Sin[c + d*x])^(5/2), x, 4, -((256*a^4*Cos[c + d*x]^3)/(315*d*(a + a*Sin[c + d*x])^(3/2))) - (64*a^3*Cos[c + d*x]^3)/(105*d*Sqrt[a + a*Sin[c + d*x]]) - (8*a^2*Cos[c + d*x]^3*Sqrt[a + a*Sin[c + d*x]])/(21*d) - (2*a*Cos[c + d*x]^3*(a + a*Sin[c + d*x])^(3/2))/(9*d)}
{Cos[c + d*x]^1*(a + a*Sin[c + d*x])^(5/2), x, 2, (2*(a + a*Sin[c + d*x])^(7/2))/(7*a*d)}
{Cos[c + d*x]^0*(a + a*Sin[c + d*x])^(5/2), x, 3, -((64*a^3*Cos[c + d*x])/(15*d*Sqrt[a + a*Sin[c + d*x]])) - (16*a^2*Cos[c + d*x]*Sqrt[a + a*Sin[c + d*x]])/(15*d) - (2*a*Cos[c + d*x]*(a + a*Sin[c + d*x])^(3/2))/(5*d)}
{Sec[c + d*x]^1*(a + a*Sin[c + d*x])^(5/2), x, 5, (4*Sqrt[2]*a^(5/2)*ArcTanh[Sqrt[a + a*Sin[c + d*x]]/(Sqrt[2]*Sqrt[a])])/d - (4*a^2*Sqrt[a + a*Sin[c + d*x]])/d - (2*a*(a + a*Sin[c + d*x])^(3/2))/(3*d)}
{Sec[c + d*x]^2*(a + a*Sin[c + d*x])^(5/2), x, 2, (4*a^3*Cos[c + d*x])/(d*Sqrt[a + a*Sin[c + d*x]]) + (2*a*Sec[c + d*x]*(a + a*Sin[c + d*x])^(3/2))/d}
{Sec[c + d*x]^3*(a + a*Sin[c + d*x])^(5/2), x, 4, -((a^(5/2)*ArcTanh[Sqrt[a + a*Sin[c + d*x]]/(Sqrt[2]*Sqrt[a])])/(Sqrt[2]*d)) + (a^2*Sqrt[a + a*Sin[c + d*x]])/(d*(1 - Sin[c + d*x]))}
{Sec[c + d*x]^4*(a + a*Sin[c + d*x])^(5/2), x, 1, (2*a*Sec[c + d*x]^3*(a + a*Sin[c + d*x])^(3/2))/(3*d)}
{Sec[c + d*x]^5*(a + a*Sin[c + d*x])^(5/2), x, 5, (3*a^(5/2)*ArcTanh[Sqrt[a + a*Sin[c + d*x]]/(Sqrt[2]*Sqrt[a])])/(16*Sqrt[2]*d) + (a^2*Sqrt[a + a*Sin[c + d*x]])/(4*d*(1 - Sin[c + d*x])^2) + (3*a^2*Sqrt[a + a*Sin[c + d*x]])/(16*d*(1 - Sin[c + d*x]))}
{Sec[c + d*x]^6*(a + a*Sin[c + d*x])^(5/2), x, 5, (a^4*Cos[c + d*x])/(12*d*(a + a*Sin[c + d*x])^(3/2)) - (a^3*ArcTanh[Sin[Pi/4 + (1/2)*(-c - d*x)]]*Cos[Pi/4 + (1/2)*(-c - d*x)])/(4*d*Sqrt[a + a*Sin[c + d*x]]) + (2*a^2*Sec[c + d*x]^3*Sqrt[a + a*Sin[c + d*x]])/(15*d) + (2*a*Sec[c + d*x]^5*(a + a*Sin[c + d*x])^(3/2))/(5*d) + (a^3*Tan[c + d*x])/(3*d*Sqrt[a + a*Sin[c + d*x]])}


{Sec[c + d*x]^6*(a + a*Sin[c + d*x])^(7/2), x, 1, (2*a*Sec[c + d*x]^5*(a + a*Sin[c + d*x])^(5/2))/(5*d)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Cos[c + d*x]^6/(a + a*Sin[c + d*x])^(1/2), x, 5, -((128*a^2*Cos[c + d*x]^5)/(693*d*(a + a*Sin[c + d*x])^(5/2))) - (160*a*Cos[c + d*x]^5)/(693*d*(a + a*Sin[c + d*x])^(3/2)) - (2*a*Cos[c + d*x]^7)/(11*d*(a + a*Sin[c + d*x])^(3/2)) + (16*Cos[c + d*x]^5)/(99*d*Sqrt[a + a*Sin[c + d*x]])}
{Cos[c + d*x]^5/(a + a*Sin[c + d*x])^(1/2), x, 4, (8*(a + a*Sin[c + d*x])^(5/2))/(5*a^3*d) - (8*(a + a*Sin[c + d*x])^(7/2))/(7*a^4*d) + (2*(a + a*Sin[c + d*x])^(9/2))/(9*a^5*d)}
{Cos[c + d*x]^4/(a + a*Sin[c + d*x])^(1/2), x, 2, -((8*a^2*Cos[c + d*x]^5)/(35*d*(a + a*Sin[c + d*x])^(5/2))) - (2*a*Cos[c + d*x]^5)/(7*d*(a + a*Sin[c + d*x])^(3/2))}
{Cos[c + d*x]^3/(a + a*Sin[c + d*x])^(1/2), x, 4, (4*(a + a*Sin[c + d*x])^(3/2))/(3*a^2*d) - (2*(a + a*Sin[c + d*x])^(5/2))/(5*a^3*d)}
{Cos[c + d*x]^2/(a + a*Sin[c + d*x])^(1/2), x, 1, -((2*a*Cos[c + d*x]^3)/(3*d*(a + a*Sin[c + d*x])^(3/2)))}
{Cos[c + d*x]^1/(a + a*Sin[c + d*x])^(1/2), x, 2, (2*Sqrt[a + a*Sin[c + d*x]])/(a*d)}
{Cos[c + d*x]^0/(a + a*Sin[c + d*x])^(1/2), x, 1, -((2*ArcTanh[Sin[Pi/4 + (1/2)*(-c - d*x)]]*Cos[Pi/4 + (1/2)*(-c - d*x)])/(d*Sqrt[a + a*Sin[c + d*x]]))}
{Sec[c + d*x]^1/(a + a*Sin[c + d*x])^(1/2), x, 4, ArcTanh[Sqrt[a + a*Sin[c + d*x]]/(Sqrt[2]*Sqrt[a])]/(Sqrt[2]*Sqrt[a]*d) - 1/(d*Sqrt[a + a*Sin[c + d*x]])}
{Sec[c + d*x]^2/(a + a*Sin[c + d*x])^(1/2), x, 3, (a*Cos[c + d*x])/(4*d*(a + a*Sin[c + d*x])^(3/2)) - (3*ArcTanh[Sin[Pi/4 + (1/2)*(-c - d*x)]]*Cos[Pi/4 + (1/2)*(-c - d*x)])/(4*d*Sqrt[a + a*Sin[c + d*x]]) + Tan[c + d*x]/(d*Sqrt[a + a*Sin[c + d*x]])}
{Sec[c + d*x]^3/(a + a*Sin[c + d*x])^(1/2), x, 6, (5*ArcTanh[Sqrt[a + a*Sin[c + d*x]]/(Sqrt[2]*Sqrt[a])])/(8*Sqrt[2]*Sqrt[a]*d) - (5*a)/(12*d*(a + a*Sin[c + d*x])^(3/2)) + a/(2*d*(1 - Sin[c + d*x])*(a + a*Sin[c + d*x])^(3/2)) - 5/(8*d*Sqrt[a + a*Sin[c + d*x]])}
{Sec[c + d*x]^4/(a + a*Sin[c + d*x])^(1/2), x, 5, (35*a*Cos[c + d*x])/(192*d*(a + a*Sin[c + d*x])^(3/2)) - (7*a*Sec[c + d*x])/(24*d*(a + a*Sin[c + d*x])^(3/2)) - (35*ArcTanh[Sin[Pi/4 + (1/2)*(-c - d*x)]]*Cos[Pi/4 + (1/2)*(-c - d*x)])/(64*d*Sqrt[a + a*Sin[c + d*x]]) + Sec[c + d*x]^3/(3*d*Sqrt[a + a*Sin[c + d*x]]) + (35*Tan[c + d*x])/(48*d*Sqrt[a + a*Sin[c + d*x]])}
{Sec[c + d*x]^5/(a + a*Sin[c + d*x])^(1/2), x, 8, (63*ArcTanh[Sqrt[a + a*Sin[c + d*x]]/(Sqrt[2]*Sqrt[a])])/(128*Sqrt[2]*Sqrt[a]*d) - (63*a^2)/(160*d*(a + a*Sin[c + d*x])^(5/2)) + a^2/(4*d*(1 - Sin[c + d*x])^2*(a + a*Sin[c + d*x])^(5/2)) + (9*a^2)/(16*d*(1 - Sin[c + d*x])*(a + a*Sin[c + d*x])^(5/2)) - (21*a)/(64*d*(a + a*Sin[c + d*x])^(3/2)) - 63/(128*d*Sqrt[a + a*Sin[c + d*x]])}
{Sec[c + d*x]^6/(a + a*Sin[c + d*x])^(1/2), x, 7, (77*a*Cos[c + d*x])/(512*d*(a + a*Sin[c + d*x])^(3/2)) - (77*a*Sec[c + d*x])/(320*d*(a + a*Sin[c + d*x])^(3/2)) - (11*a*Sec[c + d*x]^3)/(60*d*(a + a*Sin[c + d*x])^(3/2)) - (231*ArcTanh[Sin[Pi/4 + (1/2)*(-c - d*x)]]*Cos[Pi/4 + (1/2)*(-c - d*x)])/(512*d*Sqrt[a + a*Sin[c + d*x]]) + (11*Sec[c + d*x]^3)/(40*d*Sqrt[a + a*Sin[c + d*x]]) + Sec[c + d*x]^5/(5*d*Sqrt[a + a*Sin[c + d*x]]) + (77*Tan[c + d*x])/(128*d*Sqrt[a + a*Sin[c + d*x]])}


{Cos[c + d*x]^6/(a + a*Sin[c + d*x])^(3/2), x, 4, -((16*a*Cos[c + d*x]^5)/(63*d*(a + a*Sin[c + d*x])^(5/2))) - (20*Cos[c + d*x]^5)/(63*d*(a + a*Sin[c + d*x])^(3/2)) + (2*Cos[c + d*x]^5)/(9*a*d*Sqrt[a + a*Sin[c + d*x]])}
{Cos[c + d*x]^5/(a + a*Sin[c + d*x])^(3/2), x, 4, (8*(a + a*Sin[c + d*x])^(3/2))/(3*a^3*d) - (8*(a + a*Sin[c + d*x])^(5/2))/(5*a^4*d) + (2*(a + a*Sin[c + d*x])^(7/2))/(7*a^5*d)}
{Cos[c + d*x]^4/(a + a*Sin[c + d*x])^(3/2), x, 1, -((2*a*Cos[c + d*x]^5)/(5*d*(a + a*Sin[c + d*x])^(5/2)))}
{Cos[c + d*x]^3/(a + a*Sin[c + d*x])^(3/2), x, 4, (4*Sqrt[a + a*Sin[c + d*x]])/(a^2*d) - (2*(a + a*Sin[c + d*x])^(3/2))/(3*a^3*d)}
{Cos[c + d*x]^2/(a + a*Sin[c + d*x])^(3/2), x, 2, (2*Cos[c + d*x])/(a*d*Sqrt[a + a*Sin[c + d*x]]) - (4*ArcTanh[Sin[Pi/4 + (1/2)*(-c - d*x)]]*Cos[Pi/4 + (1/2)*(-c - d*x)])/(a*d*Sqrt[a + a*Sin[c + d*x]])}
{Cos[c + d*x]^1/(a + a*Sin[c + d*x])^(3/2), x, 2, -(2/(a*d*Sqrt[a + a*Sin[c + d*x]]))}
{Cos[c + d*x]^0/(a + a*Sin[c + d*x])^(3/2), x, 2, -(Cos[c + d*x]/(2*d*(a + a*Sin[c + d*x])^(3/2))) - (ArcTanh[Sin[Pi/4 + (1/2)*(-c - d*x)]]*Cos[Pi/4 + (1/2)*(-c - d*x)])/(2*a*d*Sqrt[a + a*Sin[c + d*x]])}
{Sec[c + d*x]^1/(a + a*Sin[c + d*x])^(3/2), x, 5, ArcTanh[Sqrt[a + a*Sin[c + d*x]]/(Sqrt[2]*Sqrt[a])]/(2*Sqrt[2]*a^(3/2)*d) - 1/(3*d*(a + a*Sin[c + d*x])^(3/2)) - 1/(2*a*d*Sqrt[a + a*Sin[c + d*x]])}
{Sec[c + d*x]^2/(a + a*Sin[c + d*x])^(3/2), x, 4, (5*Cos[c + d*x])/(32*d*(a + a*Sin[c + d*x])^(3/2)) - Sec[c + d*x]/(4*d*(a + a*Sin[c + d*x])^(3/2)) - (15*ArcTanh[Sin[Pi/4 + (1/2)*(-c - d*x)]]*Cos[Pi/4 + (1/2)*(-c - d*x)])/(32*a*d*Sqrt[a + a*Sin[c + d*x]]) + (5*Tan[c + d*x])/(8*a*d*Sqrt[a + a*Sin[c + d*x]])}
{Sec[c + d*x]^3/(a + a*Sin[c + d*x])^(3/2), x, 7, (7*ArcTanh[Sqrt[a + a*Sin[c + d*x]]/(Sqrt[2]*Sqrt[a])])/(16*Sqrt[2]*a^(3/2)*d) - (7*a)/(20*d*(a + a*Sin[c + d*x])^(5/2)) + a/(2*d*(1 - Sin[c + d*x])*(a + a*Sin[c + d*x])^(5/2)) - 7/(24*d*(a + a*Sin[c + d*x])^(3/2)) - 7/(16*a*d*Sqrt[a + a*Sin[c + d*x]])}
{Sec[c + d*x]^4/(a + a*Sin[c + d*x])^(3/2), x, 6, (35*Cos[c + d*x])/(256*d*(a + a*Sin[c + d*x])^(3/2)) - (7*Sec[c + d*x])/(32*d*(a + a*Sin[c + d*x])^(3/2)) - Sec[c + d*x]^3/(6*d*(a + a*Sin[c + d*x])^(3/2)) - (105*ArcTanh[Sin[Pi/4 + (1/2)*(-c - d*x)]]*Cos[Pi/4 + (1/2)*(-c - d*x)])/(256*a*d*Sqrt[a + a*Sin[c + d*x]]) + Sec[c + d*x]^3/(4*a*d*Sqrt[a + a*Sin[c + d*x]]) + (35*Tan[c + d*x])/(64*a*d*Sqrt[a + a*Sin[c + d*x]])}
{Sec[c + d*x]^5/(a + a*Sin[c + d*x])^(3/2), x, 9, (99*ArcTanh[Sqrt[a + a*Sin[c + d*x]]/(Sqrt[2]*Sqrt[a])])/(256*Sqrt[2]*a^(3/2)*d) - (99*a^2)/(224*d*(a + a*Sin[c + d*x])^(7/2)) + a^2/(4*d*(1 - Sin[c + d*x])^2*(a + a*Sin[c + d*x])^(7/2)) + (11*a^2)/(16*d*(1 - Sin[c + d*x])*(a + a*Sin[c + d*x])^(7/2)) - (99*a)/(320*d*(a + a*Sin[c + d*x])^(5/2)) - 33/(128*d*(a + a*Sin[c + d*x])^(3/2)) - 99/(256*a*d*Sqrt[a + a*Sin[c + d*x]])}
{Sec[c + d*x]^6/(a + a*Sin[c + d*x])^(3/2), x, 8, (1001*Cos[c + d*x])/(8192*d*(a + a*Sin[c + d*x])^(3/2)) - (1001*Sec[c + d*x])/(5120*d*(a + a*Sin[c + d*x])^(3/2)) - (143*Sec[c + d*x]^3)/(960*d*(a + a*Sin[c + d*x])^(3/2)) - Sec[c + d*x]^5/(8*d*(a + a*Sin[c + d*x])^(3/2)) - (3003*ArcTanh[Sin[Pi/4 + (1/2)*(-c - d*x)]]*Cos[Pi/4 + (1/2)*(-c - d*x)])/(8192*a*d*Sqrt[a + a*Sin[c + d*x]]) + (143*Sec[c + d*x]^3)/(640*a*d*Sqrt[a + a*Sin[c + d*x]]) + (13*Sec[c + d*x]^5)/(80*a*d*Sqrt[a + a*Sin[c + d*x]]) + (1001*Tan[c + d*x])/(2048*a*d*Sqrt[a + a*Sin[c + d*x]])}


{Cos[c + d*x]^6/(a + a*Sin[c + d*x])^(5/2), x, 1, -((2*a*Cos[c + d*x]^7)/(7*d*(a + a*Sin[c + d*x])^(7/2)))}
{Cos[c + d*x]^5/(a + a*Sin[c + d*x])^(5/2), x, 4, (8*Sqrt[a + a*Sin[c + d*x]])/(a^3*d) - (8*(a + a*Sin[c + d*x])^(3/2))/(3*a^4*d) + (2*(a + a*Sin[c + d*x])^(5/2))/(5*a^5*d)}
{Cos[c + d*x]^4/(a + a*Sin[c + d*x])^(5/2), x, 3, (2*Cos[c + d*x]^3)/(3*a*d*(a + a*Sin[c + d*x])^(3/2)) + (4*Cos[c + d*x])/(a^2*d*Sqrt[a + a*Sin[c + d*x]]) - (8*ArcTanh[Sin[Pi/4 + (1/2)*(-c - d*x)]]*Cos[Pi/4 + (1/2)*(-c - d*x)])/(a^2*d*Sqrt[a + a*Sin[c + d*x]])}
{Cos[c + d*x]^3/(a + a*Sin[c + d*x])^(5/2), x, 4, -(4/(a^2*d*Sqrt[a + a*Sin[c + d*x]])) - (2*Sqrt[a + a*Sin[c + d*x]])/(a^3*d)}
{Cos[c + d*x]^2/(a + a*Sin[c + d*x])^(5/2), x, 2, -(Cos[c + d*x]/(a*d*(a + a*Sin[c + d*x])^(3/2))) + (ArcTanh[Sin[Pi/4 + (1/2)*(-c - d*x)]]*Cos[Pi/4 + (1/2)*(-c - d*x)])/(a^2*d*Sqrt[a + a*Sin[c + d*x]])}
{Cos[c + d*x]^1/(a + a*Sin[c + d*x])^(5/2), x, 2, -(2/(3*a*d*(a + a*Sin[c + d*x])^(3/2)))}
{Cos[c + d*x]^0/(a + a*Sin[c + d*x])^(5/2), x, 3, -(Cos[c + d*x]/(4*d*(a + a*Sin[c + d*x])^(5/2))) - (3*Cos[c + d*x])/(16*a*d*(a + a*Sin[c + d*x])^(3/2)) - (3*ArcTanh[Sin[Pi/4 + (1/2)*(-c - d*x)]]*Cos[Pi/4 + (1/2)*(-c - d*x)])/(16*a^2*d*Sqrt[a + a*Sin[c + d*x]])}
{Sec[c + d*x]^1/(a + a*Sin[c + d*x])^(5/2), x, 6, ArcTanh[Sqrt[a + a*Sin[c + d*x]]/(Sqrt[2]*Sqrt[a])]/(4*Sqrt[2]*a^(5/2)*d) - 1/(5*d*(a + a*Sin[c + d*x])^(5/2)) - 1/(6*a*d*(a + a*Sin[c + d*x])^(3/2)) - 1/(4*a^2*d*Sqrt[a + a*Sin[c + d*x]])}
{Sec[c + d*x]^2/(a + a*Sin[c + d*x])^(5/2), x, 5, -(Sec[c + d*x]/(6*d*(a + a*Sin[c + d*x])^(5/2))) + (35*Cos[c + d*x])/(384*a*d*(a + a*Sin[c + d*x])^(3/2)) - (7*Sec[c + d*x])/(48*a*d*(a + a*Sin[c + d*x])^(3/2)) - (35*ArcTanh[Sin[Pi/4 + (1/2)*(-c - d*x)]]*Cos[Pi/4 + (1/2)*(-c - d*x)])/(128*a^2*d*Sqrt[a + a*Sin[c + d*x]]) + (35*Tan[c + d*x])/(96*a^2*d*Sqrt[a + a*Sin[c + d*x]])}
{Sec[c + d*x]^3/(a + a*Sin[c + d*x])^(5/2), x, 8, (9*ArcTanh[Sqrt[a + a*Sin[c + d*x]]/(Sqrt[2]*Sqrt[a])])/(32*Sqrt[2]*a^(5/2)*d) - (9*a)/(28*d*(a + a*Sin[c + d*x])^(7/2)) + a/(2*d*(1 - Sin[c + d*x])*(a + a*Sin[c + d*x])^(7/2)) - 9/(40*d*(a + a*Sin[c + d*x])^(5/2)) - 3/(16*a*d*(a + a*Sin[c + d*x])^(3/2)) - 9/(32*a^2*d*Sqrt[a + a*Sin[c + d*x]])}
{Sec[c + d*x]^4/(a + a*Sin[c + d*x])^(5/2), x, 7, -(Sec[c + d*x]^3/(8*d*(a + a*Sin[c + d*x])^(5/2))) + (385*Cos[c + d*x])/(4096*a*d*(a + a*Sin[c + d*x])^(3/2)) - (77*Sec[c + d*x])/(512*a*d*(a + a*Sin[c + d*x])^(3/2)) - (11*Sec[c + d*x]^3)/(96*a*d*(a + a*Sin[c + d*x])^(3/2)) - (1155*ArcTanh[Sin[Pi/4 + (1/2)*(-c - d*x)]]*Cos[Pi/4 + (1/2)*(-c - d*x)])/(4096*a^2*d*Sqrt[a + a*Sin[c + d*x]]) + (11*Sec[c + d*x]^3)/(64*a^2*d*Sqrt[a + a*Sin[c + d*x]]) + (385*Tan[c + d*x])/(1024*a^2*d*Sqrt[a + a*Sin[c + d*x]])}
{Sec[c + d*x]^5/(a + a*Sin[c + d*x])^(5/2), x, 10, (143*ArcTanh[Sqrt[a + a*Sin[c + d*x]]/(Sqrt[2]*Sqrt[a])])/(512*Sqrt[2]*a^(5/2)*d) - (143*a^2)/(288*d*(a + a*Sin[c + d*x])^(9/2)) + a^2/(4*d*(1 - Sin[c + d*x])^2*(a + a*Sin[c + d*x])^(9/2)) + (13*a^2)/(16*d*(1 - Sin[c + d*x])*(a + a*Sin[c + d*x])^(9/2)) - (143*a)/(448*d*(a + a*Sin[c + d*x])^(7/2)) - 143/(640*d*(a + a*Sin[c + d*x])^(5/2)) - 143/(768*a*d*(a + a*Sin[c + d*x])^(3/2)) - 143/(512*a^2*d*Sqrt[a + a*Sin[c + d*x]])}
{Sec[c + d*x]^6/(a + a*Sin[c + d*x])^(5/2), x, 9, -(Sec[c + d*x]^5/(10*d*(a + a*Sin[c + d*x])^(5/2))) + (3003*Cos[c + d*x])/(32768*a*d*(a + a*Sin[c + d*x])^(3/2)) - (3003*Sec[c + d*x])/(20480*a*d*(a + a*Sin[c + d*x])^(3/2)) - (143*Sec[c + d*x]^3)/(1280*a*d*(a + a*Sin[c + d*x])^(3/2)) - (3*Sec[c + d*x]^5)/(32*a*d*(a + a*Sin[c + d*x])^(3/2)) - (9009*ArcTanh[Sin[Pi/4 + (1/2)*(-c - d*x)]]*Cos[Pi/4 + (1/2)*(-c - d*x)])/(32768*a^2*d*Sqrt[a + a*Sin[c + d*x]]) + (429*Sec[c + d*x]^3)/(2560*a^2*d*Sqrt[a + a*Sin[c + d*x]]) + (39*Sec[c + d*x]^5)/(320*a^2*d*Sqrt[a + a*Sin[c + d*x]]) + (3003*Tan[c + d*x])/(8192*a^2*d*Sqrt[a + a*Sin[c + d*x]])}


(* ::Section::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (a+b Sin[c+d x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (a+b Sin[c+d x])^n*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Cos[c + d*x]^5*(a + b*Sin[c + d*x]), x, 5, -((b*Cos[c + d*x]^6)/(6*d)) + (a*Sin[c + d*x])/d - (2*a*Sin[c + d*x]^3)/(3*d) + (a*Sin[c + d*x]^5)/(5*d)}
{Cos[c + d*x]^4*(a + b*Sin[c + d*x]), x, 5, (3*a*x)/8 - (b*Cos[c + d*x]^5)/(5*d) + (3*a*Cos[c + d*x]*Sin[c + d*x])/(8*d) + (a*Cos[c + d*x]^3*Sin[c + d*x])/(4*d)}
{Cos[c + d*x]^3*(a + b*Sin[c + d*x]), x, 5, -((b*Cos[c + d*x]^4)/(4*d)) + (a*Sin[c + d*x])/d - (a*Sin[c + d*x]^3)/(3*d)}
{Cos[c + d*x]^2*(a + b*Sin[c + d*x]), x, 4, (a*x)/2 - (b*Cos[c + d*x]^3)/(3*d) + (a*Cos[c + d*x]*Sin[c + d*x])/(2*d)}
{Cos[c + d*x]^1*(a + b*Sin[c + d*x]), x, 4, (a*Sin[c + d*x])/d + (b*Sin[c + d*x]^2)/(2*d)}
{Cos[c + d*x]^0*(a + b*Sin[c + d*x]), x, 2, a*x - (b*Cos[c + d*x])/d}
{Sec[c + d*x]^1*(a + b*Sin[c + d*x]), x, 4, (a*ArcTanh[Sin[c + d*x]])/d - (b*Log[Cos[c + d*x]])/d}
{Sec[c + d*x]^2*(a + b*Sin[c + d*x]), x, 4, (b*Sec[c + d*x])/d + (a*Tan[c + d*x])/d}
{Sec[c + d*x]^3*(a + b*Sin[c + d*x]), x, 5, (a*ArcTanh[Sin[c + d*x]])/(2*d) + (b*Sec[c + d*x]^2)/(2*d) + (a*Sec[c + d*x]*Tan[c + d*x])/(2*d)}
{Sec[c + d*x]^4*(a + b*Sin[c + d*x]), x, 5, (b*Sec[c + d*x]^3)/(3*d) + (a*Tan[c + d*x])/d + (a*Tan[c + d*x]^3)/(3*d)}
{Sec[c + d*x]^5*(a + b*Sin[c + d*x]), x, 6, (3*a*ArcTanh[Sin[c + d*x]])/(8*d) + (b*Sec[c + d*x]^4)/(4*d) + (3*a*Sec[c + d*x]*Tan[c + d*x])/(8*d) + (a*Sec[c + d*x]^3*Tan[c + d*x])/(4*d)}


{Cos[c + d*x]^5*(a + b*Sin[c + d*x])^2, x, 3, (a^2*Sin[c + d*x])/d + (a*b*Sin[c + d*x]^2)/d - ((2*a^2 - b^2)*Sin[c + d*x]^3)/(3*d) - (a*b*Sin[c + d*x]^4)/d + ((a^2 - 2*b^2)*Sin[c + d*x]^5)/(5*d) + (a*b*Sin[c + d*x]^6)/(3*d) + (b^2*Sin[c + d*x]^7)/(7*d)}
{Cos[c + d*x]^4*(a + b*Sin[c + d*x])^2, x, 8, (3*a^2*x)/8 + (b^2*x)/16 - (2*a*b*Cos[c + d*x]^5)/(5*d) + (3*a^2*Cos[c + d*x]*Sin[c + d*x])/(8*d) + (b^2*Cos[c + d*x]*Sin[c + d*x])/(16*d) + (a^2*Cos[c + d*x]^3*Sin[c + d*x])/(4*d) + (b^2*Cos[c + d*x]^3*Sin[c + d*x])/(24*d) - (b^2*Cos[c + d*x]^5*Sin[c + d*x])/(6*d)}
{Cos[c + d*x]^3*(a + b*Sin[c + d*x])^2, x, 3, (a^2*Sin[c + d*x])/d + (a*b*Sin[c + d*x]^2)/d - ((a^2 - b^2)*Sin[c + d*x]^3)/(3*d) - (a*b*Sin[c + d*x]^4)/(2*d) - (b^2*Sin[c + d*x]^5)/(5*d)}
{Cos[c + d*x]^2*(a + b*Sin[c + d*x])^2, x, 6, (a^2*x)/2 + (b^2*x)/8 - (2*a*b*Cos[c + d*x]^3)/(3*d) + (a^2*Cos[c + d*x]*Sin[c + d*x])/(2*d) + (b^2*Cos[c + d*x]*Sin[c + d*x])/(8*d) - (b^2*Cos[c + d*x]^3*Sin[c + d*x])/(4*d)}
{Cos[c + d*x]^1*(a + b*Sin[c + d*x])^2, x, 2, (a + b*Sin[c + d*x])^3/(3*b*d)}
{Cos[c + d*x]^0*(a + b*Sin[c + d*x])^2, x, 2, (1/2)*(2*a^2 + b^2)*x - (2*a*b*Cos[c + d*x])/d - (b^2*Cos[c + d*x]*Sin[c + d*x])/(2*d)}
{Sec[c + d*x]^1*(a + b*Sin[c + d*x])^2, x, 6, -(((a + b)^2*Log[1 - Sin[c + d*x]])/(2*d)) + ((a - b)^2*Log[1 + Sin[c + d*x]])/(2*d) - (b^2*Sin[c + d*x])/d}
{Sec[c + d*x]^2*(a + b*Sin[c + d*x])^2, x, 6, (-b^2)*x + (2*a*b*Sec[c + d*x])/d + (a^2*Tan[c + d*x])/d + (b^2*Tan[c + d*x])/d}
{Sec[c + d*x]^3*(a + b*Sin[c + d*x])^2, x, 3, ((a^2 - b^2)*ArcTanh[Sin[c + d*x]])/(2*d) + ((b + a*Sin[c + d*x])*(a + b*Sin[c + d*x]))/(2*d*(1 - Sin[c + d*x]^2))}
{Sec[c + d*x]^4*(a + b*Sin[c + d*x])^2, x, 7, (2*a*b*Sec[c + d*x]^3)/(3*d) + (a^2*Tan[c + d*x])/d + (a^2*Tan[c + d*x]^3)/(3*d) + (b^2*Tan[c + d*x]^3)/(3*d)}
{Sec[c + d*x]^5*(a + b*Sin[c + d*x])^2, x, 4, ((3*a^2 - b^2)*ArcTanh[Sin[c + d*x]])/(8*d) - ((b - a*Sin[c + d*x])*(a + b*Sin[c + d*x])^3)/(4*(a^2 - b^2)*d*(1 - Sin[c + d*x]^2)^2) + ((3*a^2 - b^2)*(b + a*Sin[c + d*x])*(a + b*Sin[c + d*x]))/(8*(a^2 - b^2)*d*(1 - Sin[c + d*x]^2))}


{Cos[c + d*x]^5*(a + b*Sin[c + d*x])^3, x, 3, (a^3*Sin[c + d*x])/d + (3*a^2*b*Sin[c + d*x]^2)/(2*d) - (a*(2*a^2 - 3*b^2)*Sin[c + d*x]^3)/(3*d) - (b*(6*a^2 - b^2)*Sin[c + d*x]^4)/(4*d) + (a*(a^2 - 6*b^2)*Sin[c + d*x]^5)/(5*d) + (b*(3*a^2 - 2*b^2)*Sin[c + d*x]^6)/(6*d) + (3*a*b^2*Sin[c + d*x]^7)/(7*d) + (b^3*Sin[c + d*x]^8)/(8*d)}
{Cos[c + d*x]^4*(a + b*Sin[c + d*x])^3, x, 11, (3*a^3*x)/8 + (3/16)*a*b^2*x - (3*a^2*b*Cos[c + d*x]^5)/(5*d) - (b^3*Cos[c + d*x]^5)/(5*d) + (b^3*Cos[c + d*x]^7)/(7*d) + (3*a^3*Cos[c + d*x]*Sin[c + d*x])/(8*d) + (3*a*b^2*Cos[c + d*x]*Sin[c + d*x])/(16*d) + (a^3*Cos[c + d*x]^3*Sin[c + d*x])/(4*d) + (a*b^2*Cos[c + d*x]^3*Sin[c + d*x])/(8*d) - (a*b^2*Cos[c + d*x]^5*Sin[c + d*x])/(2*d)}
{Cos[c + d*x]^3*(a + b*Sin[c + d*x])^3, x, 3, -(((a - b)*(a + b)*(a + b*Sin[c + d*x])^4)/(4*b^3*d)) + (2*a*(a + b*Sin[c + d*x])^5)/(5*b^3*d) - (a + b*Sin[c + d*x])^6/(6*b^3*d)}
{Cos[c + d*x]^2*(a + b*Sin[c + d*x])^3, x, 9, (a^3*x)/2 + (3/8)*a*b^2*x - (a^2*b*Cos[c + d*x]^3)/d - (b^3*Cos[c + d*x]^3)/(3*d) + (b^3*Cos[c + d*x]^5)/(5*d) + (a^3*Cos[c + d*x]*Sin[c + d*x])/(2*d) + (3*a*b^2*Cos[c + d*x]*Sin[c + d*x])/(8*d) - (3*a*b^2*Cos[c + d*x]^3*Sin[c + d*x])/(4*d)}
{Cos[c + d*x]^1*(a + b*Sin[c + d*x])^3, x, 2, (a + b*Sin[c + d*x])^4/(4*b*d)}
{Cos[c + d*x]^0*(a + b*Sin[c + d*x])^3, x, 3, (1/2)*a*(2*a^2 + 3*b^2)*x - (2*b*(4*a^2 + b^2)*Cos[c + d*x])/(3*d) - (5*a*b^2*Cos[c + d*x]*Sin[c + d*x])/(6*d) - (b*Cos[c + d*x]*(a + b*Sin[c + d*x])^2)/(3*d)}
{Sec[c + d*x]^1*(a + b*Sin[c + d*x])^3, x, 6, -(((a + b)^3*Log[1 - Sin[c + d*x]])/(2*d)) + ((a - b)^3*Log[1 + Sin[c + d*x]])/(2*d) - (3*a*b^2*Sin[c + d*x])/d - (b^3*Sin[c + d*x]^2)/(2*d)}
{Sec[c + d*x]^2*(a + b*Sin[c + d*x])^3, x, 9, -3*a*b^2*x + (b^3*Cos[c + d*x])/d + (3*a^2*b*Sec[c + d*x])/d + (b^3*Sec[c + d*x])/d + (a^3*Tan[c + d*x])/d + (3*a*b^2*Tan[c + d*x])/d}
{Sec[c + d*x]^3*(a + b*Sin[c + d*x])^3, x, 7, -(((a - 2*b)*(a + b)^2*Log[1 - Sin[c + d*x]])/(4*d)) + ((a - b)^2*(a + 2*b)*Log[1 + Sin[c + d*x]])/(4*d) + (a*b^2*Sin[c + d*x])/(2*d) + ((b + a*Sin[c + d*x])*(a + b*Sin[c + d*x])^2)/(2*d*(1 - Sin[c + d*x]^2))}
{Sec[c + d*x]^4*(a + b*Sin[c + d*x])^3, x, 9, -((b^3*Sec[c + d*x])/d) + (a^2*b*Sec[c + d*x]^3)/d + (b^3*Sec[c + d*x]^3)/(3*d) + (a^3*Tan[c + d*x])/d + (a^3*Tan[c + d*x]^3)/(3*d) +   (a*b^2*Tan[c + d*x]^3)/d}
{Sec[c + d*x]^5*(a + b*Sin[c + d*x])^3, x, 4, (3*a*(a^2 - b^2)*ArcTanh[Sin[c + d*x]])/(8*d) + (Sin[c + d*x]*(a + b*Sin[c + d*x])^3)/(4*d*(1 - Sin[c + d*x]^2)^2) + (3*a*(b + a*Sin[c + d*x])*(a + b*Sin[c + d*x]))/(8*d*(1 - Sin[c + d*x]^2))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Cos[c + d*x]^6/(a + b*Sin[c + d*x]), x, 8, (3*a*x)/(8*b^2) - (a*(a^2 - b^2)*x)/(2*b^4) + (a*(a^2 - b^2)^2*x)/b^6 - (2*(a^2 - b^2)^(5/2)*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/(b^6*d) + ((a^2 - b^2)^2*Cos[c + d*x])/(b^5*d) - ((a^2 - b^2)*Cos[c + d*x]^3)/(3*b^3*d) + Cos[c + d*x]^5/(5*b*d) + (3*a*Cos[c + d*x]*Sin[c + d*x])/(8*b^2*d) - (a*(a^2 - b^2)*Cos[c + d*x]*Sin[c + d*x])/(2*b^4*d) + (a*Cos[c + d*x]^3*Sin[c + d*x])/(4*b^2*d)}
{Cos[c + d*x]^5/(a + b*Sin[c + d*x]), x, 3, ((a^2 - b^2)^2*Log[a + b*Sin[c + d*x]])/(b^5*d) - (a*(a^2 - 2*b^2)*Sin[c + d*x])/(b^4*d) + ((a^2 - 2*b^2)*Sin[c + d*x]^2)/(2*b^3*d) - (a*Sin[c + d*x]^3)/(3*b^2*d) + Sin[c + d*x]^4/(4*b*d)}
{Cos[c + d*x]^4/(a + b*Sin[c + d*x]), x, 5, (a*x)/(2*b^2) - (a*(a^2 - b^2)*x)/b^4 + (2*(a^2 - b^2)^(3/2)*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/(b^4*d) - ((a^2 - b^2)*Cos[c + d*x])/(b^3*d) + Cos[c + d*x]^3/(3*b*d) + (a*Cos[c + d*x]*Sin[c + d*x])/(2*b^2*d)}
{Cos[c + d*x]^3/(a + b*Sin[c + d*x]), x, 3, -(((a - b)*(a + b)*Log[a + b*Sin[c + d*x]])/(b^3*d)) + (a*Sin[c + d*x])/(b^2*d) - Sin[c + d*x]^2/(2*b*d)}
{Cos[c + d*x]^2/(a + b*Sin[c + d*x]), x, 3, (a*x)/b^2 - (2*Sqrt[a^2 - b^2]*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/(b^2*d) + Cos[c + d*x]/(b*d)}
{Cos[c + d*x]^1/(a + b*Sin[c + d*x]), x, 2, Log[a + b*Sin[c + d*x]]/(b*d)}
{Cos[c + d*x]^0/(a + b*Sin[c + d*x]), x, 1, (2*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/(Sqrt[a^2 - b^2]*d)}
{Sec[c + d*x]^1/(a + b*Sin[c + d*x]), x, 6, -(Log[1 - Sin[c + d*x]]/(2*(a + b)*d)) + Log[1 + Sin[c + d*x]]/(2*(a - b)*d) - (b*Log[a + b*Sin[c + d*x]])/((a^2 - b^2)*d)}
{Sec[c + d*x]^2/(a + b*Sin[c + d*x]), x, 3, -((2*b^2*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(3/2)*d)) - (b*Sec[c + d*x])/((a^2 - b^2)*d) + (a*Tan[c + d*x])/((a^2 - b^2)*d)}
{Sec[c + d*x]^3/(a + b*Sin[c + d*x]), x, 7, -(((a + 2*b)*Log[1 - Sin[c + d*x]])/(4*(a + b)^2*d)) + ((a - 2*b)*Log[1 + Sin[c + d*x]])/(4*(a - b)^2*d) + (b^3*Log[a + b*Sin[c + d*x]])/((a^2 - b^2)^2*d) - (b - a*Sin[c + d*x])/(2*(a^2 - b^2)*d*(1 - Sin[c + d*x]^2))}
{Sec[c + d*x]^4/(a + b*Sin[c + d*x]), x, 6, (2*b^4*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(5/2)*d) + (b^3*Sec[c + d*x])/((a^2 - b^2)^2*d) - (b*Sec[c + d*x]^3)/(3*(a^2 - b^2)*d) - (a*b^2*Tan[c + d*x])/((a^2 - b^2)^2*d) + (a*Tan[c + d*x])/((a^2 - b^2)*d) + (a*Tan[c + d*x]^3)/(3*(a^2 - b^2)*d)}
{Sec[c + d*x]^5/(a + b*Sin[c + d*x]), x, 8, -(((3*a^2 + 9*a*b + 8*b^2)*Log[1 - Sin[c + d*x]])/(16*(a + b)^3*d)) + ((3*a^2 - 9*a*b + 8*b^2)*Log[1 + Sin[c + d*x]])/(16*(a - b)^3*d) - (b^5*Log[a + b*Sin[c + d*x]])/((a^2 - b^2)^3*d) - (b - a*Sin[c + d*x])/(4*(a^2 - b^2)*d*(1 - Sin[c + d*x]^2)^2) + (4*b^3 + a*(3*a^2 - 7*b^2)*Sin[c + d*x])/(8*(a^2 - b^2)^2*d*(1 - Sin[c + d*x]^2))}


{Cos[c + d*x]^5/(a + b*Sin[c + d*x])^2, x, 3, -((4*a*(a^2 - b^2)*Log[a + b*Sin[c + d*x]])/(b^5*d)) + ((3*a^2 - 2*b^2)*Sin[c + d*x])/(b^4*d) - (a*Sin[c + d*x]^2)/(b^3*d) + Sin[c + d*x]^3/(3*b^2*d) - (a^2 - b^2)^2/(b^5*d*(a + b*Sin[c + d*x]))}
{Cos[c + d*x]^4/(a + b*Sin[c + d*x])^2, x, 8, (2*a^2*x)/b^4 - x/(2*b^2) + ((a^2 - b^2)*x)/b^4 - (6*a*Sqrt[a^2 - b^2]*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/(b^4*d) + (2*a*Cos[c + d*x])/(b^3*d) - (Cos[c + d*x]*Sin[c + d*x])/(2*b^2*d) + ((a^2 - b^2)*Cos[c + d*x])/(b^3*d*(a + b*Sin[c + d*x]))}
{Cos[c + d*x]^3/(a + b*Sin[c + d*x])^2, x, 3, (2*a*Log[a + b*Sin[c + d*x]])/(b^3*d) - Sin[c + d*x]/(b^2*d) + (a^2 - b^2)/(b^3*d*(a + b*Sin[c + d*x]))}
{Cos[c + d*x]^2/(a + b*Sin[c + d*x])^2, x, 3, -(x/b^2) + (2*a*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/(b^2*Sqrt[a^2 - b^2]*d) - Cos[c + d*x]/(b*d*(a + b*Sin[c + d*x]))}
{Cos[c + d*x]^1/(a + b*Sin[c + d*x])^2, x, 2, -(1/(b*d*(a + b*Sin[c + d*x])))}
{Cos[c + d*x]^0/(a + b*Sin[c + d*x])^2, x, 3, (2*a*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(3/2)*d) + (b*Cos[c + d*x])/((a^2 - b^2)*d*(a + b*Sin[c + d*x]))}
{Sec[c + d*x]^1/(a + b*Sin[c + d*x])^2, x, 7, -(Log[1 - Sin[c + d*x]]/(2*(a + b)^2*d)) + Log[1 + Sin[c + d*x]]/(2*(a - b)^2*d) - (2*a*b*Log[a + b*Sin[c + d*x]])/((a^2 - b^2)^2*d) + b/((a^2 - b^2)*d*(a + b*Sin[c + d*x]))}
{Sec[c + d*x]^2/(a + b*Sin[c + d*x])^2, x, 5, -((6*a*b^2*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(5/2)*d)) - (a*b*Cos[c + d*x])/((a^2 - b^2)*d*(a + b*Sin[c + d*x])^2) - (b*(a^2 + 2*b^2)*Cos[c + d*x])/((a^2 - b^2)^2*d*(a + b*Sin[c + d*x])) + Tan[c + d*x]/(d*(a + b*Sin[c + d*x])^2)}
{Sec[c + d*x]^3/(a + b*Sin[c + d*x])^2, x, 8, -(((a + 3*b)*Log[1 - Sin[c + d*x]])/(4*(a + b)^3*d)) + ((a - 3*b)*Log[1 + Sin[c + d*x]])/(4*(a - b)^3*d) + (4*a*b^3*Log[a + b*Sin[c + d*x]])/((a^2 - b^2)^3*d) - (b*(a^2 + 3*b^2))/(2*(a^2 - b^2)^2*d*(a + b*Sin[c + d*x])) - (b - a*Sin[c + d*x])/(2*(a^2 - b^2)*d*(a + b*Sin[c + d*x])*(1 - Sin[c + d*x]^2))}
{Sec[c + d*x]^4/(a + b*Sin[c + d*x])^2, x, 12, (10*a*b^4*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(7/2)*d) + Cos[c + d*x]/(12*(a + b)^2*d*(1 - Sin[c + d*x])^2) + Cos[c + d*x]/(12*(a + b)^2*d*(1 - Sin[c + d*x])) + ((a + 3*b)*Cos[c + d*x])/(4*(a + b)^3*d*(1 - Sin[c + d*x])) - Cos[c + d*x]/(12*(a - b)^2*d*(1 + Sin[c + d*x])^2) - ((a - 3*b)*Cos[c + d*x])/(4*(a - b)^3*d*(1 + Sin[c + d*x])) - Cos[c + d*x]/(12*(a - b)^2*d*(1 + Sin[c + d*x])) + (b^5*Cos[c + d*x])/((a^2 - b^2)^3*d*(a + b*Sin[c + d*x]))}
{Sec[c + d*x]^5/(a + b*Sin[c + d*x])^2, x, 9, -((3*(a^2 + 4*a*b + 5*b^2)*Log[1 - Sin[c + d*x]])/(16*(a + b)^4*d)) + (3*(a^2 - 4*a*b + 5*b^2)*Log[1 + Sin[c + d*x]])/(16*(a - b)^4*d) - (6*a*b^5*Log[a + b*Sin[c + d*x]])/((a^2 - b^2)^4*d) - (3*b*(a^4 - 4*a^2*b^2 - 5*b^4))/(8*(a^2 - b^2)^3*d*(a + b*Sin[c + d*x])) - (b - a*Sin[c + d*x])/(4*(a^2 - b^2)*d*(a + b*Sin[c + d*x])*(1 - Sin[c + d*x]^2)^2) + (b*(a^2 + 5*b^2) + 3*a*(a^2 - 3*b^2)*Sin[c + d*x])/(8*(a^2 - b^2)^2*d*(a + b*Sin[c + d*x])*(1 - Sin[c + d*x]^2))}


{Cos[c + d*x]^5/(a + b*Sin[c + d*x])^3, x, 3, (2*(3*a^2 - b^2)*Log[a + b*Sin[c + d*x]])/(b^5*d) - (3*a*Sin[c + d*x])/(b^4*d) + Sin[c + d*x]^2/(2*b^3*d) - (a^2 - b^2)^2/(2*b^5*d*(a + b*Sin[c + d*x])^2) + (4*a*(a^2 - b^2))/(b^5*d*(a + b*Sin[c + d*x]))}
{Cos[c + d*x]^4/(a + b*Sin[c + d*x])^3, x, 11, -((3*a*x)/b^4) + (4*a^2*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/(b^4*Sqrt[a^2 - b^2]*d) - ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]]/(b^2*Sqrt[a^2 - b^2]*d) + (2*Sqrt[a^2 - b^2]*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/(b^4*d) - Cos[c + d*x]/(b^3*d) + ((a^2 - b^2)*Cos[c + d*x])/(2*b^3*d*(a + b*Sin[c + d*x])^2) - (5*a*Cos[c + d*x])/(2*b^3*d*(a + b*Sin[c + d*x]))}
{Cos[c + d*x]^3/(a + b*Sin[c + d*x])^3, x, 3, -(Log[a + b*Sin[c + d*x]]/(b^3*d)) + (a^2 - b^2)/(2*b^3*d*(a + b*Sin[c + d*x])^2) - (2*a)/(b^3*d*(a + b*Sin[c + d*x]))}
{Cos[c + d*x]^2/(a + b*Sin[c + d*x])^3, x, 4, ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]]/((a^2 - b^2)^(3/2)*d) - Cos[c + d*x]/(2*b*d*(a + b*Sin[c + d*x])^2) + (a*Cos[c + d*x])/(2*b*(a^2 - b^2)*d*(a + b*Sin[c + d*x]))}
{Cos[c + d*x]^1/(a + b*Sin[c + d*x])^3, x, 2, -(1/(2*b*d*(a + b*Sin[c + d*x])^2))}
{Cos[c + d*x]^0/(a + b*Sin[c + d*x])^3, x, 4, ((2*a^2 + b^2)*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(5/2)*d) + (b*Cos[c + d*x])/(2*(a^2 - b^2)*d*(a + b*Sin[c + d*x])^2) + (3*a*b*Cos[c + d*x])/(2*(a^2 - b^2)^2*d*(a + b*Sin[c + d*x]))}
{Sec[c + d*x]^1/(a + b*Sin[c + d*x])^3, x, 8, -(Log[1 - Sin[c + d*x]]/(2*(a + b)^3*d)) + Log[1 + Sin[c + d*x]]/(2*(a - b)^3*d) - (b*(3*a^2 + b^2)*Log[a + b*Sin[c + d*x]])/((a^2 - b^2)^3*d) + b/(2*(a^2 - b^2)*d*(a + b*Sin[c + d*x])^2) + (2*a*b)/((a^2 - b^2)^2*d*(a + b*Sin[c + d*x]))}
{Sec[c + d*x]^2/(a + b*Sin[c + d*x])^3, x, 6, -((3*b^2*(4*a^2 + b^2)*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(7/2)*d)) - (a*b*Cos[c + d*x])/((a^2 - b^2)*d*(a + b*Sin[c + d*x])^3) - (b*(2*a^2 + 3*b^2)*Cos[c + d*x])/(2*(a^2 - b^2)^2*d*(a + b*Sin[c + d*x])^2) - (a*b*(2*a^2 + 13*b^2)*Cos[c + d*x])/(2*(a^2 - b^2)^3*d*(a + b*Sin[c + d*x])) + Tan[c + d*x]/(d*(a + b*Sin[c + d*x])^3)}
{Sec[c + d*x]^3/(a + b*Sin[c + d*x])^3, x, 9, -(((a + 4*b)*Log[1 - Sin[c + d*x]])/(4*(a + b)^4*d)) + ((a - 4*b)*Log[1 + Sin[c + d*x]])/(4*(a - b)^4*d) + (2*b^3*(5*a^2 + b^2)*Log[a + b*Sin[c + d*x]])/((a^2 - b^2)^4*d) - (b*(a^2 + 2*b^2))/(2*(a^2 - b^2)^2*d*(a + b*Sin[c + d*x])^2) - (a*b*(a^2 + 11*b^2))/(2*(a^2 - b^2)^3*d*(a + b*Sin[c + d*x])) - (b - a*Sin[c + d*x])/(2*(a^2 - b^2)*d*(a + b*Sin[c + d*x])^2*(1 - Sin[c + d*x]^2))}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[c+d x]^m (a+b Sin[c+d x])^(n/2)*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Cos[c + d*x]^5*(a + b*Sin[c + d*x])^(1/2), x, 3, (2*(a^2 - b^2)^2*(a + b*Sin[c + d*x])^(3/2))/(3*b^5*d) - (8*a*(a^2 - b^2)*(a + b*Sin[c + d*x])^(5/2))/(5*b^5*d) + (4*(3*a^2 - b^2)*(a + b*Sin[c + d*x])^(7/2))/(7*b^5*d) - (8*a*(a + b*Sin[c + d*x])^(9/2))/(9*b^5*d) + (2*(a + b*Sin[c + d*x])^(11/2))/(11*b^5*d)}
{Cos[c + d*x]^4*(a + b*Sin[c + d*x])^(1/2), x, 20, -((8*a*Cos[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(15*b*d)) - (2*a*(8*a^2 + 13*b^2)*Cos[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(315*b^3*d) + (2*(6*a^2 - 49*b^2)*Cos[c + d*x]*Sin[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(315*b^2*d) - (2*a*Cos[c + d*x]*Sin[c + d*x]^2*Sqrt[a + b*Sin[c + d*x]])/(63*b*d) - (2*Cos[c + d*x]*Sin[c + d*x]^3*Sqrt[a + b*Sin[c + d*x]])/(9*d) + (4*Cos[c + d*x]*(a + b*Sin[c + d*x])^(3/2))/(5*b*d) - (2*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) - (4*(2*a^2 - 9*b^2)*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(15*b^2*d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) + (2*(16*a^4 + 24*a^2*b^2 - 147*b^4)*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(315*b^4*d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) + (8*a*(a^2 - b^2)*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(15*b^2*d*Sqrt[a + b*Sin[c + d*x]]) - (8*a*(4*a^4 + 5*a^2*b^2 - 9*b^4)*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(315*b^4*d*Sqrt[a + b*Sin[c + d*x]])}
{Cos[c + d*x]^3*(a + b*Sin[c + d*x])^(1/2), x, 3, -((2*(a^2 - b^2)*(a + b*Sin[c + d*x])^(3/2))/(3*b^3*d)) + (4*a*(a + b*Sin[c + d*x])^(5/2))/(5*b^3*d) - (2*(a + b*Sin[c + d*x])^(7/2))/(7*b^3*d)}
{Cos[c + d*x]^2*(a + b*Sin[c + d*x])^(1/2), x, 8, -((4*a*Cos[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(15*b*d)) + (2*Cos[c + d*x]*(a + b*Sin[c + d*x])^(3/2))/(5*b*d) - (4*(a^2 + 3*b^2)*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(15*b^2*d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) + (4*a*(a^2 - b^2)*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(15*b^2*d*Sqrt[a + b*Sin[c + d*x]])}
{Cos[c + d*x]^1*(a + b*Sin[c + d*x])^(1/2), x, 2, (2*(a + b*Sin[c + d*x])^(3/2))/(3*b*d)}
{Cos[c + d*x]^0*(a + b*Sin[c + d*x])^(1/2), x, 2, -((2*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]))}
{Sec[c + d*x]^1*(a + b*Sin[c + d*x])^(1/2), x, 4, -((Sqrt[a - b]*ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a - b]])/d) + (Sqrt[a + b]*ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a + b]])/d}
{Sec[c + d*x]^2*(a + b*Sin[c + d*x])^(1/2), x, 6, (EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) - (a*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(d*Sqrt[a + b*Sin[c + d*x]]) + (Sqrt[a + b*Sin[c + d*x]]*Tan[c + d*x])/d}
{Sec[c + d*x]^3*(a + b*Sin[c + d*x])^(1/2), x, 5, -(((2*a - b)*ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a - b]])/(4*Sqrt[a - b]*d)) + ((2*a + b)*ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a + b]])/(4*Sqrt[a + b]*d) + (Sin[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(2*d*(1 - Sin[c + d*x]^2))}
{Sec[c + d*x]^4*(a + b*Sin[c + d*x])^(1/2), x, 0, 0}
{Sec[c + d*x]^5*(a + b*Sin[c + d*x])^(1/2), x, 6, -(((12*a^2 - 18*a*b + 5*b^2)*ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a - b]])/(32*(a - b)^(3/2)*d)) + ((12*a^2 + 18*a*b + 5*b^2)*ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a + b]])/(32*(a + b)^(3/2)*d) + (Sin[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(4*d*(1 - Sin[c + d*x]^2)^2) - (Sqrt[a + b*Sin[c + d*x]]*(a*b - (6*a^2 - 5*b^2)*Sin[c + d*x]))/(16*(a^2 - b^2)*d*(1 - Sin[c + d*x]^2))}


{Cos[c + d*x]^5*(a + b*Sin[c + d*x])^(3/2), x, 3, (2*(a^2 - b^2)^2*(a + b*Sin[c + d*x])^(5/2))/(5*b^5*d) - (8*a*(a^2 - b^2)*(a + b*Sin[c + d*x])^(7/2))/(7*b^5*d) + (4*(3*a^2 - b^2)*(a + b*Sin[c + d*x])^(9/2))/(9*b^5*d) - (8*a*(a + b*Sin[c + d*x])^(11/2))/(11*b^5*d) + (2*(a + b*Sin[c + d*x])^(13/2))/(13*b^5*d)}
{Cos[c + d*x]^4*(a + b*Sin[c + d*x])^(3/2), x, 44, -((8*a^2*Cos[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(15*b*d)) - (2*b*Cos[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(3*d) - (4*(4*a^2 - 25*b^2)*Cos[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(105*b*d) - (2*a^2*(8*a^2 + 13*b^2)*Cos[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(315*b^3*d) + (2*(64*a^4 + 86*a^2*b^2 - 675*b^4)*Cos[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(3465*b^3*d) + (4*a*Cos[c + d*x]*Sin[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(35*d) + (2*a*(6*a^2 - 49*b^2)*Cos[c + d*x]*Sin[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(315*b^2*d) - (2*a*(48*a^2 + 67*b^2)*Cos[c + d*x]*Sin[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(3465*b^2*d) - (2*a^2*Cos[c + d*x]*Sin[c + d*x]^2*Sqrt[a + b*Sin[c + d*x]])/(63*b*d) + (4*b*Cos[c + d*x]*Sin[c + d*x]^2*Sqrt[a + b*Sin[c + d*x]])/(7*d) + (2*(8*a^2 - 81*b^2)*Cos[c + d*x]*Sin[c + d*x]^2*Sqrt[a + b*Sin[c + d*x]])/(693*b*d) - (8*a*Cos[c + d*x]*Sin[c + d*x]^3*Sqrt[a + b*Sin[c + d*x]])/(33*d) - (2*b*Cos[c + d*x]*Sin[c + d*x]^4*Sqrt[a + b*Sin[c + d*x]])/(11*d) + (4*a*Cos[c + d*x]*(a + b*Sin[c + d*x])^(3/2))/(5*b*d) - (8*a*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(3*d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) - (4*a*(2*a^2 - 9*b^2)*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(15*b^2*d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) + (4*a*(8*a^2 + 19*b^2)*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(105*b^2*d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) + (2*a*(16*a^4 + 24*a^2*b^2 - 147*b^4)*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(315*b^4*d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) - (2*a*(128*a^4 + 156*a^2*b^2 + 471*b^4)*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(3465*b^4*d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) + (2*(a^2 - b^2)*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(3*d*Sqrt[a + b*Sin[c + d*x]]) + (8*a^2*(a^2 - b^2)*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(15*b^2*d*Sqrt[a + b*Sin[c + d*x]]) - (4*(8*a^4 + 17*a^2*b^2 - 25*b^4)*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(105*b^2*d*Sqrt[a + b*Sin[c + d*x]]) - (8*a^2*(4*a^4 + 5*a^2*b^2 - 9*b^4)*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(315*b^4*d*Sqrt[a + b*Sin[c + d*x]]) + (2*(128*a^6 + 124*a^4*b^2 + 423*a^2*b^4 - 675*b^6)*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(3465*b^4*d*Sqrt[a + b*Sin[c + d*x]])}
{Cos[c + d*x]^3*(a + b*Sin[c + d*x])^(3/2), x, 3, -((2*(a^2 - b^2)*(a + b*Sin[c + d*x])^(5/2))/(5*b^3*d)) + (4*a*(a + b*Sin[c + d*x])^(7/2))/(7*b^3*d) - (2*(a + b*Sin[c + d*x])^(9/2))/(9*b^3*d)}
{Cos[c + d*x]^2*(a + b*Sin[c + d*x])^(3/2), x, 9, -((4*(3*a^2 + 5*b^2)*Cos[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(105*b*d)) - (4*a*Cos[c + d*x]*(a + b*Sin[c + d*x])^(3/2))/(35*b*d) + (2*Cos[c + d*x]*(a + b*Sin[c + d*x])^(5/2))/(7*b*d) - (4*a*(3*a^2 + 29*b^2)*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(105*b^2*d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) + (4*(3*a^4 + 2*a^2*b^2 - 5*b^4)*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(105*b^2*d*Sqrt[a + b*Sin[c + d*x]])}
{Cos[c + d*x]^1*(a + b*Sin[c + d*x])^(3/2), x, 2, (2*(a + b*Sin[c + d*x])^(5/2))/(5*b*d)}
{Cos[c + d*x]^0*(a + b*Sin[c + d*x])^(3/2), x, 6, -((2*b*Cos[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(3*d)) - (8*a*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(3*d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) + (2*(a^2 - b^2)*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(3*d*Sqrt[a + b*Sin[c + d*x]])}
{Sec[c + d*x]^1*(a + b*Sin[c + d*x])^(3/2), x, 5, -(((a - b)^(3/2)*ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a - b]])/d) + ((a + b)^(3/2)*ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a + b]])/d - (2*b*Sqrt[a + b*Sin[c + d*x]])/d}
{Sec[c + d*x]^2*(a + b*Sin[c + d*x])^(3/2), x, 7, (b*Cos[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/d + (a*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) - ((a^2 - b^2)*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(d*Sqrt[a + b*Sin[c + d*x]]) + ((a + b*Sin[c + d*x])^(3/2)*Tan[c + d*x])/d}
{Sec[c + d*x]^3*(a + b*Sin[c + d*x])^(3/2), x, 5, -((Sqrt[a - b]*(2*a + b)*ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a - b]])/(4*d)) + ((2*a - b)*Sqrt[a + b]*ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a + b]])/(4*d) + ((b + a*Sin[c + d*x])*Sqrt[a + b*Sin[c + d*x]])/(2*d*(1 - Sin[c + d*x]^2))}
{Sec[c + d*x]^4*(a + b*Sin[c + d*x])^(3/2), x, 0, 0}
{Sec[c + d*x]^5*(a + b*Sin[c + d*x])^(3/2), x, 6, -((3*(4*a^2 - 2*a*b - b^2)*ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a - b]])/(32*Sqrt[a - b]*d)) + (3*(4*a^2 + 2*a*b - b^2)*ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a + b]])/(32*Sqrt[a + b]*d) + ((b + a*Sin[c + d*x])*Sqrt[a + b*Sin[c + d*x]])/(4*d*(1 - Sin[c + d*x]^2)^2) - ((b - 6*a*Sin[c + d*x])*Sqrt[a + b*Sin[c + d*x]])/(16*d*(1 - Sin[c + d*x]^2))}


{Cos[c + d*x]^5*(a + b*Sin[c + d*x])^(5/2), x, 3, (2*(a^2 - b^2)^2*(a + b*Sin[c + d*x])^(7/2))/(7*b^5*d) - (8*a*(a^2 - b^2)*(a + b*Sin[c + d*x])^(9/2))/(9*b^5*d) + (4*(3*a^2 - b^2)*(a + b*Sin[c + d*x])^(11/2))/(11*b^5*d) - (8*a*(a + b*Sin[c + d*x])^(13/2))/(13*b^5*d) + (2*(a + b*Sin[c + d*x])^(15/2))/(15*b^5*d)}
{Cos[c + d*x]^4*(a + b*Sin[c + d*x])^(5/2), x, 71, -((8*a^3*Cos[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(15*b*d)) - (16*a*b*Cos[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(15*d) - (8*a*(4*a^2 - 25*b^2)*Cos[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(105*b*d) - (2*a^3*(8*a^2 + 13*b^2)*Cos[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(315*b^3*d) + (4*a*(8*a^2 + 13*b^2)*Cos[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(315*b*d) + (4*a*(64*a^4 + 86*a^2*b^2 - 675*b^4)*Cos[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(3465*b^3*d) - (2*a*(640*a^4 + 772*a^2*b^2 + 1423*b^4)*Cos[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(45045*b^3*d) + (8*a^2*Cos[c + d*x]*Sin[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(35*d) - (4*(6*a^2 - 49*b^2)*Cos[c + d*x]*Sin[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(315*d) + (2*a^2*(6*a^2 - 49*b^2)*Cos[c + d*x]*Sin[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(315*b^2*d) - (4*a^2*(48*a^2 + 67*b^2)*Cos[c + d*x]*Sin[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(3465*b^2*d) + (2*(480*a^4 + 604*a^2*b^2 - 5929*b^4)*Cos[c + d*x]*Sin[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(45045*b^2*d) - (2*a^3*Cos[c + d*x]*Sin[c + d*x]^2*Sqrt[a + b*Sin[c + d*x]])/(63*b*d) + (76*a*b*Cos[c + d*x]*Sin[c + d*x]^2*Sqrt[a + b*Sin[c + d*x]])/(63*d) + (4*a*(8*a^2 - 81*b^2)*Cos[c + d*x]*Sin[c + d*x]^2*Sqrt[a + b*Sin[c + d*x]])/(693*b*d) - (2*a*(80*a^2 + 103*b^2)*Cos[c + d*x]*Sin[c + d*x]^2*Sqrt[a + b*Sin[c + d*x]])/(9009*b*d) - (26*a^2*Cos[c + d*x]*Sin[c + d*x]^3*Sqrt[a + b*Sin[c + d*x]])/(99*d) + (4*b^2*Cos[c + d*x]*Sin[c + d*x]^3*Sqrt[a + b*Sin[c + d*x]])/(9*d) + (2*(10*a^2 - 121*b^2)*Cos[c + d*x]*Sin[c + d*x]^3*Sqrt[a + b*Sin[c + d*x]])/(1287*d) - (54*a*b*Cos[c + d*x]*Sin[c + d*x]^4*Sqrt[a + b*Sin[c + d*x]])/(143*d) - (2*b^2*Cos[c + d*x]*Sin[c + d*x]^5*Sqrt[a + b*Sin[c + d*x]])/(13*d) + (4*a^2*Cos[c + d*x]*(a + b*Sin[c + d*x])^(3/2))/(5*b*d) - (2*b*Cos[c + d*x]*(a + b*Sin[c + d*x])^(3/2))/(5*d) - (10*a^2*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(3*d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) + (2*(2*a^2 - 9*b^2)*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(15*d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) - (4*a^2*(2*a^2 - 9*b^2)*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(15*b^2*d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) + (8*a^2*(8*a^2 + 19*b^2)*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(105*b^2*d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) + (2*a^2*(16*a^4 + 24*a^2*b^2 - 147*b^4)*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(315*b^4*d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) - (4*(16*a^4 + 24*a^2*b^2 - 147*b^4)*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(315*b^2*d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) - (4*a^2*(128*a^4 + 156*a^2*b^2 + 471*b^4)*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(3465*b^4*d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) + (2*(1280*a^6 + 1384*a^4*b^2 + 2598*a^2*b^4 - 17787*b^6)*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(45045*b^4*d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) + (16*a*(a^2 - b^2)*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(15*d*Sqrt[a + b*Sin[c + d*x]]) + (8*a^3*(a^2 - b^2)*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(15*b^2*d*Sqrt[a + b*Sin[c + d*x]]) - (8*a*(8*a^4 + 17*a^2*b^2 - 25*b^4)*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(105*b^2*d*Sqrt[a + b*Sin[c + d*x]]) - (8*a^3*(4*a^4 + 5*a^2*b^2 - 9*b^4)*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(315*b^4*d*Sqrt[a + b*Sin[c + d*x]]) + (16*a*(4*a^4 + 5*a^2*b^2 - 9*b^4)*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(315*b^2*d*Sqrt[a + b*Sin[c + d*x]]) - (4*a*(640*a^6 + 532*a^4*b^2 + 1081*a^2*b^4 - 2253*b^6)*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(45045*b^4*d*Sqrt[a + b*Sin[c + d*x]]) + (4*a*(128*a^6 + 124*a^4*b^2 + 423*a^2*b^4 - 675*b^6)*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(3465*b^4*d*Sqrt[a + b*Sin[c + d*x]])}
{Cos[c + d*x]^3*(a + b*Sin[c + d*x])^(5/2), x, 3, -((2*(a^2 - b^2)*(a + b*Sin[c + d*x])^(7/2))/(7*b^3*d)) + (4*a*(a + b*Sin[c + d*x])^(9/2))/(9*b^3*d) - (2*(a + b*Sin[c + d*x])^(11/2))/(11*b^3*d)}
{Cos[c + d*x]^2*(a + b*Sin[c + d*x])^(5/2), x, 10, -((4*a*(5*a^2 + 27*b^2)*Cos[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(315*b*d)) - (4*(5*a^2 + 7*b^2)*Cos[c + d*x]*(a + b*Sin[c + d*x])^(3/2))/(315*b*d) - (4*a*Cos[c + d*x]*(a + b*Sin[c + d*x])^(5/2))/(63*b*d) + (2*Cos[c + d*x]*(a + b*Sin[c + d*x])^(7/2))/(9*b*d) - (4*(5*a^4 + 102*a^2*b^2 + 21*b^4)*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(315*b^2*d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) + (4*a*(5*a^4 + 22*a^2*b^2 - 27*b^4)*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(315*b^2*d*Sqrt[a + b*Sin[c + d*x]])}
{Cos[c + d*x]^1*(a + b*Sin[c + d*x])^(5/2), x, 2, (2*(a + b*Sin[c + d*x])^(7/2))/(7*b*d)}
{Cos[c + d*x]^0*(a + b*Sin[c + d*x])^(5/2), x, 7, -((16*a*b*Cos[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(15*d)) - (2*b*Cos[c + d*x]*(a + b*Sin[c + d*x])^(3/2))/(5*d) - (2*(23*a^2 + 9*b^2)*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(15*d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) + (16*a*(a^2 - b^2)*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(15*d*Sqrt[a + b*Sin[c + d*x]])}
{Sec[c + d*x]^1*(a + b*Sin[c + d*x])^(5/2), x, 6, -(((a - b)^(5/2)*ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a - b]])/d) + ((a + b)^(5/2)*ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a + b]])/d - (4*a*b*Sqrt[a + b*Sin[c + d*x]])/d - (2*b*(a + b*Sin[c + d*x])^(3/2))/(3*d)}
{Sec[c + d*x]^2*(a + b*Sin[c + d*x])^(5/2), x, 8, (a*b*Cos[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/d + (b*Cos[c + d*x]*(a + b*Sin[c + d*x])^(3/2))/d + ((a^2 + 3*b^2)*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) - (a*(a^2 - b^2)*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(d*Sqrt[a + b*Sin[c + d*x]]) + ((a + b*Sin[c + d*x])^(5/2)*Tan[c + d*x])/d}
{Sec[c + d*x]^3*(a + b*Sin[c + d*x])^(5/2), x, 6, -(((a - b)^(3/2)*(2*a + 3*b)*ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a - b]])/(4*d)) + ((2*a - 3*b)*(a + b)^(3/2)*ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a + b]])/(4*d) + (a*b*Sqrt[a + b*Sin[c + d*x]])/(2*d) + ((b + a*Sin[c + d*x])*(a + b*Sin[c + d*x])^(3/2))/(2*d*(1 - Sin[c + d*x]^2))}
{Sec[c + d*x]^4*(a + b*Sin[c + d*x])^(5/2), x, 0, 0}
{Sec[c + d*x]^5*(a + b*Sin[c + d*x])^(5/2), x, 6, -((3*Sqrt[a - b]*(4*a^2 + 2*a*b - b^2)*ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a - b]])/(32*d)) + (3*Sqrt[a + b]*(4*a^2 - 2*a*b - b^2)*ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a + b]])/(32*d) + ((b + a*Sin[c + d*x])*(a + b*Sin[c + d*x])^(3/2))/(4*d*(1 - Sin[c + d*x]^2)^2) + (3*Sqrt[a + b*Sin[c + d*x]]*(a*b + (2*a^2 - b^2)*Sin[c + d*x]))/(16*d*(1 - Sin[c + d*x]^2))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Cos[c + d*x]^5/(a + b*Sin[c + d*x])^(1/2), x, 3, (2*(a^2 - b^2)^2*Sqrt[a + b*Sin[c + d*x]])/(b^5*d) - (8*a*(a^2 - b^2)*(a + b*Sin[c + d*x])^(3/2))/(3*b^5*d) + (4*(3*a^2 - b^2)*(a + b*Sin[c + d*x])^(5/2))/(5*b^5*d) - (8*a*(a + b*Sin[c + d*x])^(7/2))/(7*b^5*d) + (2*(a + b*Sin[c + d*x])^(9/2))/(9*b^5*d)}
{Cos[c + d*x]^4/(a + b*Sin[c + d*x])^(1/2), x, 18, (4*Cos[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(3*b*d) - (2*(24*a^2 + 25*b^2)*Cos[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(105*b^3*d) + (12*a*Cos[c + d*x]*Sin[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(35*b^2*d) - (2*Cos[c + d*x]*Sin[c + d*x]^2*Sqrt[a + b*Sin[c + d*x]])/(7*b*d) - (8*a*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(3*b^2*d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) + (8*a*(12*a^2 + 11*b^2)*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(105*b^4*d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) - (2*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(d*Sqrt[a + b*Sin[c + d*x]]) + (4*(2*a^2 + b^2)*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(3*b^2*d*Sqrt[a + b*Sin[c + d*x]]) - (2*(48*a^4 + 32*a^2*b^2 + 25*b^4)*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(105*b^4*d*Sqrt[a + b*Sin[c + d*x]])}
{Cos[c + d*x]^3/(a + b*Sin[c + d*x])^(1/2), x, 3, -((2*(a^2 - b^2)*Sqrt[a + b*Sin[c + d*x]])/(b^3*d)) + (4*a*(a + b*Sin[c + d*x])^(3/2))/(3*b^3*d) - (2*(a + b*Sin[c + d*x])^(5/2))/(5*b^3*d)}
{Cos[c + d*x]^2/(a + b*Sin[c + d*x])^(1/2), x, 7, (2*Cos[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(3*b*d) - (4*a*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(3*b^2*d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) + (4*(a^2 - b^2)*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(3*b^2*d*Sqrt[a + b*Sin[c + d*x]])}
{Cos[c + d*x]^1/(a + b*Sin[c + d*x])^(1/2), x, 2, (2*Sqrt[a + b*Sin[c + d*x]])/(b*d)}
{Cos[c + d*x]^0/(a + b*Sin[c + d*x])^(1/2), x, 2, -((2*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(d*Sqrt[a + b*Sin[c + d*x]]))}
{Sec[c + d*x]^1/(a + b*Sin[c + d*x])^(1/2), x, 4, -(ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a - b]]/(Sqrt[a - b]*d)) + ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a + b]]/(Sqrt[a + b]*d)}
{Sec[c + d*x]^2/(a + b*Sin[c + d*x])^(1/2), x, 7, -((a*b*Cos[c + d*x])/((a^2 - b^2)*d*Sqrt[a + b*Sin[c + d*x]])) + (a*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/((a^2 - b^2)*d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) - (EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(d*Sqrt[a + b*Sin[c + d*x]]) + Tan[c + d*x]/(d*Sqrt[a + b*Sin[c + d*x]])}
{Sec[c + d*x]^3/(a + b*Sin[c + d*x])^(1/2), x, 5, -(((2*a - 3*b)*ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a - b]])/(4*(a - b)^(3/2)*d)) + ((2*a + 3*b)*ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a + b]])/(4*(a + b)^(3/2)*d) - ((b - a*Sin[c + d*x])*Sqrt[a + b*Sin[c + d*x]])/(2*(a^2 - b^2)*d*(1 - Sin[c + d*x]^2))}
{Sec[c + d*x]^4/(a + b*Sin[c + d*x])^(1/2), x, 0, 0}
{Sec[c + d*x]^5/(a + b*Sin[c + d*x])^(1/2), x, 6, -((3*(4*a^2 - 10*a*b + 7*b^2)*ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a - b]])/(32*(a - b)^(5/2)*d)) + (3*(4*a^2 + 10*a*b + 7*b^2)*ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a + b]])/(32*(a + b)^(5/2)*d) - ((b - a*Sin[c + d*x])*Sqrt[a + b*Sin[c + d*x]])/(4*(a^2 - b^2)*d*(1 - Sin[c + d*x]^2)^2) - (Sqrt[a + b*Sin[c + d*x]]*(b*(a^2 - 7*b^2) - 6*a*(a^2 - 2*b^2)*Sin[c + d*x]))/(16*(a^2 - b^2)^2*d*(1 - Sin[c + d*x]^2))}


{Cos[c + d*x]^5/(a + b*Sin[c + d*x])^(3/2), x, 3, -((2*(a^2 - b^2)^2)/(b^5*d*Sqrt[a + b*Sin[c + d*x]])) - (8*a*(a^2 - b^2)*Sqrt[a + b*Sin[c + d*x]])/(b^5*d) + (4*(3*a^2 - b^2)*(a + b*Sin[c + d*x])^(3/2))/(3*b^5*d) - (8*a*(a + b*Sin[c + d*x])^(5/2))/(5*b^5*d) + (2*(a + b*Sin[c + d*x])^(7/2))/(7*b^5*d)}
{Cos[c + d*x]^4/(a + b*Sin[c + d*x])^(3/2), x, 22, (2*(a^2 - b^2)*Cos[c + d*x])/(b^3*d*Sqrt[a + b*Sin[c + d*x]]) + (8*a*Cos[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(5*b^3*d) - (2*Cos[c + d*x]*(a + b*Sin[c + d*x])^(3/2))/(5*b^3*d) - (8*a^2*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(3*b^4*d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) - (4*(a^2 - b^2)*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(b^4*d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) + (4*(a^2 + 3*b^2)*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(15*b^4*d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) + (32*a*(a^2 - b^2)*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(5*b^4*d*Sqrt[a + b*Sin[c + d*x]])}
{Cos[c + d*x]^3/(a + b*Sin[c + d*x])^(3/2), x, 3, (2*(a^2 - b^2))/(b^3*d*Sqrt[a + b*Sin[c + d*x]]) + (4*a*Sqrt[a + b*Sin[c + d*x]])/(b^3*d) - (2*(a + b*Sin[c + d*x])^(3/2))/(3*b^3*d)}
{Cos[c + d*x]^2/(a + b*Sin[c + d*x])^(3/2), x, 6, -((2*Cos[c + d*x])/(b*d*Sqrt[a + b*Sin[c + d*x]])) + (4*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(b^2*d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) - (4*a*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(b^2*d*Sqrt[a + b*Sin[c + d*x]])}
{Cos[c + d*x]^1/(a + b*Sin[c + d*x])^(3/2), x, 2, -(2/(b*d*Sqrt[a + b*Sin[c + d*x]]))}
{Cos[c + d*x]^0/(a + b*Sin[c + d*x])^(3/2), x, 4, (2*b*Cos[c + d*x])/((a^2 - b^2)*d*Sqrt[a + b*Sin[c + d*x]]) - (2*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/((a^2 - b^2)*d*Sqrt[(a + b*Sin[c + d*x])/(a + b)])}
{Sec[c + d*x]^1/(a + b*Sin[c + d*x])^(3/2), x, 5, -(ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a - b]]/((a - b)^(3/2)*d)) + ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a + b]]/((a + b)^(3/2)*d) + (2*b)/((a^2 - b^2)*d*Sqrt[a + b*Sin[c + d*x]])}
{Sec[c + d*x]^2/(a + b*Sin[c + d*x])^(3/2), x, 8, -((a*b*Cos[c + d*x])/((a^2 - b^2)*d*(a + b*Sin[c + d*x])^(3/2))) - (b*(a^2 + 3*b^2)*Cos[c + d*x])/((a^2 - b^2)^2*d*Sqrt[a + b*Sin[c + d*x]]) + ((a^2 + 3*b^2)*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/((a^2 - b^2)^2*d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) - (a*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/((a^2 - b^2)*d*Sqrt[a + b*Sin[c + d*x]]) + Tan[c + d*x]/(d*(a + b*Sin[c + d*x])^(3/2))}
{Sec[c + d*x]^3/(a + b*Sin[c + d*x])^(3/2), x, 6, -(((2*a - 5*b)*ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a - b]])/(4*(a - b)^(5/2)*d)) + ((2*a + 5*b)*ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a + b]])/(4*(a + b)^(5/2)*d) - (b*(a^2 + 5*b^2))/(2*(a^2 - b^2)^2*d*Sqrt[a + b*Sin[c + d*x]]) - (b - a*Sin[c + d*x])/(2*(a^2 - b^2)*d*Sqrt[a + b*Sin[c + d*x]]*(1 - Sin[c + d*x]^2))}
{Sec[c + d*x]^4/(a + b*Sin[c + d*x])^(3/2), x, 0, 0}
{Sec[c + d*x]^5/(a + b*Sin[c + d*x])^(3/2), x, 7, -((3*(4*a^2 - 14*a*b + 15*b^2)*ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a - b]])/(32*(a - b)^(7/2)*d)) + (3*(4*a^2 + 14*a*b + 15*b^2)*ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a + b]])/(32*(a + b)^(7/2)*d) - (3*b*(2*a^4 - 7*a^2*b^2 - 15*b^4))/(16*(a^2 - b^2)^3*d*Sqrt[a + b*Sin[c + d*x]]) - (b - a*Sin[c + d*x])/(4*(a^2 - b^2)*d*Sqrt[a + b*Sin[c + d*x]]*(1 - Sin[c + d*x]^2)^2) + (b*(a^2 + 9*b^2) + 2*a*(3*a^2 - 8*b^2)*Sin[c + d*x])/(16*(a^2 - b^2)^2*d*Sqrt[a + b*Sin[c + d*x]]*(1 - Sin[c + d*x]^2))}


{Cos[c + d*x]^5/(a + b*Sin[c + d*x])^(5/2), x, 3, -((2*(a^2 - b^2)^2)/(3*b^5*d*(a + b*Sin[c + d*x])^(3/2))) + (8*a*(a^2 - b^2))/(b^5*d*Sqrt[a + b*Sin[c + d*x]]) + (4*(3*a^2 - b^2)*Sqrt[a + b*Sin[c + d*x]])/(b^5*d) - (8*a*(a + b*Sin[c + d*x])^(3/2))/(3*b^5*d) + (2*(a + b*Sin[c + d*x])^(5/2))/(5*b^5*d)}
{Cos[c + d*x]^4/(a + b*Sin[c + d*x])^(5/2), x, 21, (2*(a^2 - b^2)*Cos[c + d*x])/(3*b^3*d*(a + b*Sin[c + d*x])^(3/2)) - (16*a*Cos[c + d*x])/(3*b^3*d*Sqrt[a + b*Sin[c + d*x]]) - (2*Cos[c + d*x]*Sqrt[a + b*Sin[c + d*x]])/(3*b^3*d) + (32*a*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(3*b^4*d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) - (8*a^2*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(b^4*d*Sqrt[a + b*Sin[c + d*x]]) - (8*(a^2 - b^2)*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(3*b^4*d*Sqrt[a + b*Sin[c + d*x]])}
{Cos[c + d*x]^3/(a + b*Sin[c + d*x])^(5/2), x, 3, (2*(a^2 - b^2))/(3*b^3*d*(a + b*Sin[c + d*x])^(3/2)) - (4*a)/(b^3*d*Sqrt[a + b*Sin[c + d*x]]) - (2*Sqrt[a + b*Sin[c + d*x]])/(b^3*d)}
{Cos[c + d*x]^2/(a + b*Sin[c + d*x])^(5/2), x, 7, -((2*Cos[c + d*x])/(3*b*d*(a + b*Sin[c + d*x])^(3/2))) + (4*a*Cos[c + d*x])/(3*b*(a^2 - b^2)*d*Sqrt[a + b*Sin[c + d*x]]) - (4*a*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(3*b^2*(a^2 - b^2)*d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) + (4*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(3*b^2*d*Sqrt[a + b*Sin[c + d*x]])}
{Cos[c + d*x]^1/(a + b*Sin[c + d*x])^(5/2), x, 2, -(2/(3*b*d*(a + b*Sin[c + d*x])^(3/2)))}
{Cos[c + d*x]^0/(a + b*Sin[c + d*x])^(5/2), x, 7, (2*b*Cos[c + d*x])/(3*(a^2 - b^2)*d*(a + b*Sin[c + d*x])^(3/2)) + (8*a*b*Cos[c + d*x])/(3*(a^2 - b^2)^2*d*Sqrt[a + b*Sin[c + d*x]]) - (8*a*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(3*(a^2 - b^2)^2*d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) + (2*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(3*(a^2 - b^2)*d*Sqrt[a + b*Sin[c + d*x]])}
{Sec[c + d*x]^1/(a + b*Sin[c + d*x])^(5/2), x, 6, -(ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a - b]]/((a - b)^(5/2)*d)) + ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a + b]]/((a + b)^(5/2)*d) + (2*b)/(3*(a^2 - b^2)*d*(a + b*Sin[c + d*x])^(3/2)) + (4*a*b)/((a^2 - b^2)^2*d*Sqrt[a + b*Sin[c + d*x]])}
{Sec[c + d*x]^2/(a + b*Sin[c + d*x])^(5/2), x, 9, -((a*b*Cos[c + d*x])/((a^2 - b^2)*d*(a + b*Sin[c + d*x])^(5/2))) - (b*(3*a^2 + 5*b^2)*Cos[c + d*x])/(3*(a^2 - b^2)^2*d*(a + b*Sin[c + d*x])^(3/2)) - (a*b*(3*a^2 + 29*b^2)*Cos[c + d*x])/(3*(a^2 - b^2)^3*d*Sqrt[a + b*Sin[c + d*x]]) + (a*(3*a^2 + 29*b^2)*EllipticE[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[a + b*Sin[c + d*x]])/(3*(a^2 - b^2)^3*d*Sqrt[(a + b*Sin[c + d*x])/(a + b)]) - ((3*a^2 + 5*b^2)*EllipticF[Pi/4 + (1/2)*(-c - d*x), (2*b)/(a + b)]*Sqrt[(a + b*Sin[c + d*x])/(a + b)])/(3*(a^2 - b^2)^2*d*Sqrt[a + b*Sin[c + d*x]]) + Tan[c + d*x]/(d*(a + b*Sin[c + d*x])^(5/2))}
{Sec[c + d*x]^3/(a + b*Sin[c + d*x])^(5/2), x, 7, -(((2*a - 7*b)*ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a - b]])/(4*(a - b)^(7/2)*d)) + ((2*a + 7*b)*ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a + b]])/(4*(a + b)^(7/2)*d) - (b*(3*a^2 + 7*b^2))/(6*(a^2 - b^2)^2*d*(a + b*Sin[c + d*x])^(3/2)) - (a*b*(a^2 + 19*b^2))/(2*(a^2 - b^2)^3*d*Sqrt[a + b*Sin[c + d*x]]) - (b - a*Sin[c + d*x])/(2*(a^2 - b^2)*d*(a + b*Sin[c + d*x])^(3/2)*(1 - Sin[c + d*x]^2))}
{Sec[c + d*x]^4/(a + b*Sin[c + d*x])^(5/2), x, 0, 0}
{Sec[c + d*x]^5/(a + b*Sin[c + d*x])^(5/2), x, 8, -(((12*a^2 - 54*a*b + 77*b^2)*ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a - b]])/(32*(a - b)^(9/2)*d)) + ((12*a^2 + 54*a*b + 77*b^2)*ArcTanh[Sqrt[a + b*Sin[c + d*x]]/Sqrt[a + b]])/(32*(a + b)^(9/2)*d) - (b*(18*a^4 - 81*a^2*b^2 - 77*b^4))/(48*(a^2 - b^2)^3*d*(a + b*Sin[c + d*x])^(3/2)) - (a*b*(3*a^4 - 16*a^2*b^2 - 127*b^4))/(8*(a^2 - b^2)^4*d*Sqrt[a + b*Sin[c + d*x]]) - (b - a*Sin[c + d*x])/(4*(a^2 - b^2)*d*(a + b*Sin[c + d*x])^(3/2)*(1 - Sin[c + d*x]^2)^2) + (b*(3*a^2 + 11*b^2) + 2*a*(3*a^2 - 10*b^2)*Sin[c + d*x])/(16*(a^2 - b^2)^2*d*(a + b*Sin[c + d*x])^(3/2)*(1 - Sin[c + d*x]^2))}


(* ::Section::Closed:: *)
(*Integrands of the form Tan[c+d x]^m (a+b Sin[c+d x])^n when a^2-b^2=0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Tan[c+d x]^m (a+b Sin[c+d x])^n when a^2-b^2=0*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Tan[c + d*x]^6*(a + a*Sin[c + d*x]), x, 9, (-a)*x + (a*Cos[c + d*x])/d + (3*a*Sec[c + d*x])/d - (a*Sec[c + d*x]^3)/d + (a*Sec[c + d*x]^5)/(5*d) + (a*Tan[c + d*x])/d - (a*Tan[c + d*x]^3)/(3*d) + (a*Tan[c + d*x]^5)/(5*d)}
{Tan[c + d*x]^5*(a + a*Sin[c + d*x]), x, 4, -((23*a*Log[1 - Sin[c + d*x]])/(16*d)) + (7*a*Log[1 + Sin[c + d*x]])/(16*d) + a/(8*d*(1 - Sin[c + d*x])^2) - a/(d*(1 - Sin[c + d*x])) - (a*Sin[c + d*x])/d + a/(8*d*(1 + Sin[c + d*x]))}
{Tan[c + d*x]^4*(a + a*Sin[c + d*x]), x, 8, a*x - (a*Cos[c + d*x])/d - (2*a*Sec[c + d*x])/d + (a*Sec[c + d*x]^3)/(3*d) - (a*Tan[c + d*x])/d + (a*Tan[c + d*x]^3)/(3*d)}
{Tan[c + d*x]^3*(a + a*Sin[c + d*x]), x, 4, (5*a*Log[1 - Sin[c + d*x]])/(4*d) - (a*Log[1 + Sin[c + d*x]])/(4*d) + a/(2*d*(1 - Sin[c + d*x])) + (a*Sin[c + d*x])/d}
{Tan[c + d*x]^2*(a + a*Sin[c + d*x]), x, 4, (-a)*x + (a*Cos[c + d*x])/d + (a^2*Cos[c + d*x])/(d*(a - a*Sin[c + d*x]))}
{Tan[c + d*x]^1*(a + a*Sin[c + d*x]), x, 4, -((a*Log[1 - Sin[c + d*x]])/d) - (a*Sin[c + d*x])/d}
{Tan[c + d*x]^0*(a + a*Sin[c + d*x]), x, 2, a*x - (a*Cos[c + d*x])/d}
{Cot[c + d*x]^1*(a + a*Sin[c + d*x]), x, 3, (a*Log[Sin[c + d*x]])/d + (a*Sin[c + d*x])/d}
{Cot[c + d*x]^2*(a + a*Sin[c + d*x]), x, 6, (-a)*x - (a*ArcTanh[Cos[c + d*x]])/d + (a*Cos[c + d*x])/d - (a*Cot[c + d*x])/d}
{Cot[c + d*x]^3*(a + a*Sin[c + d*x]), x, 4, -((a*Csc[c + d*x])/d) - (a*Csc[c + d*x]^2)/(2*d) - (a*Log[Sin[c + d*x]])/d - (a*Sin[c + d*x])/d}
{Cot[c + d*x]^4*(a + a*Sin[c + d*x]), x, 8, a*x + (3*a*ArcTanh[Cos[c + d*x]])/(2*d) - (3*a*Cos[c + d*x])/(2*d) + (a*Cot[c + d*x])/d - (a*Cos[c + d*x]*Cot[c + d*x]^2)/(2*d) - (a*Cot[c + d*x]^3)/(3*d)}
{Cot[c + d*x]^5*(a + a*Sin[c + d*x]), x, 4, (2*a*Csc[c + d*x])/d + (a*Csc[c + d*x]^2)/d - (a*Csc[c + d*x]^3)/(3*d) - (a*Csc[c + d*x]^4)/(4*d) + (a*Log[Sin[c + d*x]])/d + (a*Sin[c + d*x])/d}
{Cot[c + d*x]^6*(a + a*Sin[c + d*x]), x, 10, (-a)*x - (15*a*ArcTanh[Cos[c + d*x]])/(8*d) + (15*a*Cos[c + d*x])/(8*d) - (a*Cot[c + d*x])/d + (5*a*Cos[c + d*x]*Cot[c + d*x]^2)/(8*d) + (a*Cot[c + d*x]^3)/(3*d) - (a*Cos[c + d*x]*Cot[c + d*x]^4)/(4*d) - (a*Cot[c + d*x]^5)/(5*d)}


{Tan[c + d*x]^6*(a + a*Sin[c + d*x])^2, x, 11, (-(1/2))*(9*a^2*x) + (2*a^2*Cos[c + d*x])/d + (a^2*Cos[c + d*x])/(10*d*(1 - Sin[c + d*x])^3) - (17*a^2*Cos[c + d*x])/(20*d*(1 - Sin[c + d*x])^2) + (211*a^2*Cos[c + d*x])/(40*d*(1 - Sin[c + d*x])) + (a^2*Cos[c + d*x]*Sin[c + d*x])/(2*d) - (a^2*Cos[c + d*x])/(8*d*(1 + Sin[c + d*x]))}
{Tan[c + d*x]^5*(a + a*Sin[c + d*x])^2, x, 4, -((31*a^2*Log[1 - Sin[c + d*x]])/(8*d)) - (a^2*Log[1 + Sin[c + d*x]])/(8*d) + a^2/(4*d*(1 - Sin[c + d*x])^2) - (9*a^2)/(4*d*(1 - Sin[c + d*x])) - (2*a^2*Sin[c + d*x])/d - (a^2*Sin[c + d*x]^2)/(2*d)}
{Tan[c + d*x]^4*(a + a*Sin[c + d*x])^2, x, 6, (7*a^2*x)/2 - (2*a^2*Cos[c + d*x])/d + (a^2*Cos[c + d*x])/(3*d*(1 - Sin[c + d*x])^2) - (11*a^2*Cos[c + d*x])/(3*d*(1 - Sin[c + d*x])) - (a^2*Cos[c + d*x]*Sin[c + d*x])/(2*d), (7*a^2*x)/2 - (16*a^2*Cos[c + d*x])/(3*d) - (7*a^2*Cos[c + d*x]*Sin[c + d*x])/(2*d) - (8*a^2*Cos[c + d*x]*Sin[c + d*x]^2)/(3*d*(1 - Sin[c + d*x])) + (a^4*Cos[c + d*x]*Sin[c + d*x]^3)/(3*d*(a - a*Sin[c + d*x])^2)}
{Tan[c + d*x]^3*(a + a*Sin[c + d*x])^2, x, 4, (3*a^2*Log[1 - Sin[c + d*x]])/d + a^2/(d*(1 - Sin[c + d*x])) + (2*a^2*Sin[c + d*x])/d + (a^2*Sin[c + d*x]^2)/(2*d)}
{Tan[c + d*x]^2*(a + a*Sin[c + d*x])^2, x, 5, -((5*a^2*x)/2) + (2*a^2*Cos[c + d*x])/d + (2*a^2*Cos[c + d*x])/(d*(1 - Sin[c + d*x])) + (a^2*Cos[c + d*x]*Sin[c + d*x])/(2*d)}
{Tan[c + d*x]^1*(a + a*Sin[c + d*x])^2, x, 4, -((2*a^2*Log[1 - Sin[c + d*x]])/d) - (2*a^2*Sin[c + d*x])/d - (a^2*Sin[c + d*x]^2)/(2*d)}
{Tan[c + d*x]^0*(a + a*Sin[c + d*x])^2, x, 2, (3*a^2*x)/2 - (2*a^2*Cos[c + d*x])/d - (a^2*Cos[c + d*x]*Sin[c + d*x])/(2*d)}
{Cot[c + d*x]^1*(a + a*Sin[c + d*x])^2, x, 3, (a^2*Log[Sin[c + d*x]])/d + (2*a^2*Sin[c + d*x])/d + (a^2*Sin[c + d*x]^2)/(2*d)}
{Cot[c + d*x]^2*(a + a*Sin[c + d*x])^2, x, 6, -((a^2*x)/2) - (2*a^2*ArcTanh[Cos[c + d*x]])/d + (2*a^2*Cos[c + d*x])/d - (a^2*Cot[c + d*x])/d + (a^2*Cos[c + d*x]*Sin[c + d*x])/(2*d)}
{Cot[c + d*x]^3*(a + a*Sin[c + d*x])^2, x, 3, -((a^2*Csc[c + d*x]^2*(1 + Sin[c + d*x])^4)/(2*d))}
{Cot[c + d*x]^4*(a + a*Sin[c + d*x])^2, x, 10, -((a^2*x)/2) + (3*a^2*ArcTanh[Cos[c + d*x]])/d - (2*a^2*Cos[c + d*x])/d - (a^2*Cot[c + d*x]^3)/(3*d) - (a^2*Cot[c + d*x]*Csc[c + d*x])/d - (a^2*Cos[c + d*x]*Sin[c + d*x])/(2*d)}
{Cot[c + d*x]^5*(a + a*Sin[c + d*x])^2, x, 4, (4*a^2*Csc[c + d*x])/d + (a^2*Csc[c + d*x]^2)/(2*d) - (2*a^2*Csc[c + d*x]^3)/(3*d) - (a^2*Csc[c + d*x]^4)/(4*d) - (a^2*Log[Sin[c + d*x]])/d + (2*a^2*Sin[c + d*x])/d + (a^2*Sin[c + d*x]^2)/(2*d)}
{Cot[c + d*x]^6*(a + a*Sin[c + d*x])^2, x, 14, (3*a^2*x)/2 - (15*a^2*ArcTanh[Cos[c + d*x]])/(4*d) + (2*a^2*Cos[c + d*x])/d + (a^2*Cot[c + d*x])/d - (a^2*Cot[c + d*x]^5)/(5*d) + (9*a^2*Cot[c + d*x]*Csc[c + d*x])/(4*d) - (a^2*Cot[c + d*x]*Csc[c + d*x]^3)/(2*d) + (a^2*Cos[c + d*x]*Sin[c + d*x])/(2*d)}


{Tan[c + d*x]^8*(a + a*Sin[c + d*x])^3, x, 17, (29*a^3*x)/2 - (8*a^3*Cos[c + d*x])/d + (a^3*Cos[c + d*x]^3)/(3*d) + (a^3*Cos[c + d*x])/(14*d*(1 - Sin[c + d*x])^4) - (99*a^3*Cos[c + d*x])/(140*d*(1 - Sin[c + d*x])^3) + (2999*a^3*Cos[c + d*x])/(840*d*(1 - Sin[c + d*x])^2) - (30857*a^3*Cos[c + d*x])/(1680*d*(1 - Sin[c + d*x])) - (3*a^3*Cos[c + d*x]*Sin[c + d*x])/(2*d) - (a^3*Cos[c + d*x])/(16*d*(1 + Sin[c + d*x]))}
{Tan[c + d*x]^7*(a + a*Sin[c + d*x])^3, x, 4, (209*a^3*Log[1 - Sin[c + d*x]])/(16*d) - (a^3*Log[1 + Sin[c + d*x]])/(16*d) + a^3/(6*d*(1 - Sin[c + d*x])^3) - (13*a^3)/(8*d*(1 - Sin[c + d*x])^2) + (71*a^3)/(8*d*(1 - Sin[c + d*x])) + (7*a^3*Sin[c + d*x])/d + (3*a^3*Sin[c + d*x]^2)/(2*d) + (a^3*Sin[c + d*x]^3)/(3*d)}
{Tan[c + d*x]^6*(a + a*Sin[c + d*x])^3, x, 8, -((23*a^3*x)/2) + (7*a^3*Cos[c + d*x])/d - (a^3*Cos[c + d*x]^3)/(3*d) + (a^3*Cos[c + d*x])/(5*d*(1 - Sin[c + d*x])^3) - (28*a^3*Cos[c + d*x])/(15*d*(1 - Sin[c + d*x])^2) + (197*a^3*Cos[c + d*x])/(15*d*(1 - Sin[c + d*x])) + (3*a^3*Cos[c + d*x]*Sin[c + d*x])/(2*d), -((23*a^3*x)/2) + (136*a^3*Cos[c + d*x])/(5*d) - (136*a^3*Cos[c + d*x]^3)/(15*d) + (23*a^3*Cos[c + d*x]*Sin[c + d*x])/(2*d) + (a^6*Cos[c + d*x]*Sin[c + d*x]^5)/(5*d*(a - a*Sin[c + d*x])^3) - (13*a^5*Cos[c + d*x]*Sin[c + d*x]^4)/(15*d*(a - a*Sin[c + d*x])^2) + (23*a^6*Cos[c + d*x]*Sin[c + d*x]^3)/(3*d*(a^3 - a^3*Sin[c + d*x]))}
{Tan[c + d*x]^5*(a + a*Sin[c + d*x])^3, x, 4, -((10*a^3*Log[1 - Sin[c + d*x]])/d) + a^3/(2*d*(1 - Sin[c + d*x])^2) - (5*a^3)/(d*(1 - Sin[c + d*x])) - (6*a^3*Sin[c + d*x])/d - (3*a^3*Sin[c + d*x]^2)/(2*d) - (a^3*Sin[c + d*x]^3)/(3*d)}
{Tan[c + d*x]^4*(a + a*Sin[c + d*x])^3, x, 9, (17*a^3*x)/2 - (6*a^3*Cos[c + d*x])/d + (a^3*Cos[c + d*x]^3)/(3*d) + (2*a^3*Cos[c + d*x])/(3*d*(1 - Sin[c + d*x])^2) - (25*a^3*Cos[c + d*x])/(3*d*(1 - Sin[c + d*x])) - (3*a^3*Cos[c + d*x]*Sin[c + d*x])/(2*d)}
{Tan[c + d*x]^3*(a + a*Sin[c + d*x])^3, x, 4, (7*a^3*Log[1 - Sin[c + d*x]])/d + (2*a^3)/(d*(1 - Sin[c + d*x])) + (5*a^3*Sin[c + d*x])/d + (3*a^3*Sin[c + d*x]^2)/(2*d) + (a^3*Sin[c + d*x]^3)/(3*d)}
{Tan[c + d*x]^2*(a + a*Sin[c + d*x])^3, x, 7, -((11*a^3*x)/2) + (5*a^3*Cos[c + d*x])/d - (a^3*Cos[c + d*x]^3)/(3*d) + (4*a^3*Cos[c + d*x])/(d*(1 - Sin[c + d*x])) + (3*a^3*Cos[c + d*x]*Sin[c + d*x])/(2*d)}
{Tan[c + d*x]^1*(a + a*Sin[c + d*x])^3, x, 4, -((4*a^3*Log[1 - Sin[c + d*x]])/d) - (4*a^3*Sin[c + d*x])/d - (3*a^3*Sin[c + d*x]^2)/(2*d) - (a^3*Sin[c + d*x]^3)/(3*d)}
{Tan[c + d*x]^0*(a + a*Sin[c + d*x])^3, x, 3, (5*a^3*x)/2 - (10*a^3*Cos[c + d*x])/(3*d) - (5*a^3*Cos[c + d*x]*Sin[c + d*x])/(6*d) - (a*Cos[c + d*x]*(a + a*Sin[c + d*x])^2)/(3*d)}
{Cot[c + d*x]^1*(a + a*Sin[c + d*x])^3, x, 3, (a^3*Log[Sin[c + d*x]])/d + (3*a^3*Sin[c + d*x])/d + (3*a^3*Sin[c + d*x]^2)/(2*d) + (a^3*Sin[c + d*x]^3)/(3*d)}
{Cot[c + d*x]^2*(a + a*Sin[c + d*x])^3, x, 8, (a^3*x)/2 - (3*a^3*ArcTanh[Cos[c + d*x]])/d + (3*a^3*Cos[c + d*x])/d - (a^3*Cos[c + d*x]^3)/(3*d) - (a^3*Cot[c + d*x])/d + (3*a^3*Cos[c + d*x]*Sin[c + d*x])/(2*d)}
{Cot[c + d*x]^3*(a + a*Sin[c + d*x])^3, x, 4, -((3*a^3*Csc[c + d*x])/d) - (a^3*Csc[c + d*x]^2)/(2*d) + (2*a^3*Log[Sin[c + d*x]])/d - (2*a^3*Sin[c + d*x])/d - (3*a^3*Sin[c + d*x]^2)/(2*d) - (a^3*Sin[c + d*x]^3)/(3*d)}
{Cot[c + d*x]^4*(a + a*Sin[c + d*x])^3, x, 12, -((7*a^3*x)/2) + (7*a^3*ArcTanh[Cos[c + d*x]])/(2*d) - (2*a^3*Cos[c + d*x])/d + (a^3*Cos[c + d*x]^3)/(3*d) - (2*a^3*Cot[c + d*x])/d - (a^3*Cot[c + d*x]^3)/(3*d) - (3*a^3*Cot[c + d*x]*Csc[c + d*x])/(2*d) - (3*a^3*Cos[c + d*x]*Sin[c + d*x])/(2*d)}
{Cot[c + d*x]^5*(a + a*Sin[c + d*x])^3, x, 4, (5*a^3*Csc[c + d*x])/d - (a^3*Csc[c + d*x]^2)/(2*d) - (a^3*Csc[c + d*x]^3)/d - (a^3*Csc[c + d*x]^4)/(4*d) - (5*a^3*Log[Sin[c + d*x]])/d + (a^3*Sin[c + d*x])/d + (3*a^3*Sin[c + d*x]^2)/(2*d) + (a^3*Sin[c + d*x]^3)/(3*d)}
{Cot[c + d*x]^6*(a + a*Sin[c + d*x])^3, x, 14, (13*a^3*x)/2 - (25*a^3*ArcTanh[Cos[c + d*x]])/(8*d) + (a^3*Cos[c + d*x])/d - (a^3*Cos[c + d*x]^3)/(3*d) + (5*a^3*Cot[c + d*x])/d - (2*a^3*Cot[c + d*x]^3)/(3*d) - (a^3*Cot[c + d*x]^5)/(5*d) + (23*a^3*Cot[c + d*x]*Csc[c + d*x])/(8*d) - (3*a^3*Cot[c + d*x]*Csc[c + d*x]^3)/(4*d) + (3*a^3*Cos[c + d*x]*Sin[c + d*x])/(2*d)}


{Tan[c + d*x]^6*(a + a*Sin[c + d*x])^4, x, 14, -((239*a^4*x)/8) + (20*a^4*Cos[c + d*x])/d - (4*a^4*Cos[c + d*x]^3)/(3*d) + (2*a^4*Cos[c + d*x])/(5*d*(1 - Sin[c + d*x])^3) - (61*a^4*Cos[c + d*x])/(15*d*(1 - Sin[c + d*x])^2) + (479*a^4*Cos[c + d*x])/(15*d*(1 - Sin[c + d*x])) + (39*a^4*Cos[c + d*x]*Sin[c + d*x])/(8*d) + (a^4*Cos[c + d*x]*Sin[c + d*x]^3)/(4*d)}
{Tan[c + d*x]^5*(a + a*Sin[c + d*x])^4, x, 4, -((25*a^4*Log[1 - Sin[c + d*x]])/d) + a^4/(d*(1 - Sin[c + d*x])^2) - (11*a^4)/(d*(1 - Sin[c + d*x])) - (16*a^4*Sin[c + d*x])/d - (9*a^4*Sin[c + d*x]^2)/(2*d) - (4*a^4*Sin[c + d*x]^3)/(3*d) - (a^4*Sin[c + d*x]^4)/(4*d)}
{Tan[c + d*x]^4*(a + a*Sin[c + d*x])^4, x, 11, (163*a^4*x)/8 - (16*a^4*Cos[c + d*x])/d + (4*a^4*Cos[c + d*x]^3)/(3*d) + (4*a^4*Cos[c + d*x])/(3*d*(1 - Sin[c + d*x])^2) - (56*a^4*Cos[c + d*x])/(3*d*(1 - Sin[c + d*x])) - (35*a^4*Cos[c + d*x]*Sin[c + d*x])/(8*d) - (a^4*Cos[c + d*x]*Sin[c + d*x]^3)/(4*d)}
{Tan[c + d*x]^3*(a + a*Sin[c + d*x])^4, x, 4, (16*a^4*Log[1 - Sin[c + d*x]])/d + (4*a^4)/(d*(1 - Sin[c + d*x])) + (12*a^4*Sin[c + d*x])/d + (4*a^4*Sin[c + d*x]^2)/d + (4*a^4*Sin[c + d*x]^3)/(3*d) + (a^4*Sin[c + d*x]^4)/(4*d)}
{Tan[c + d*x]^2*(a + a*Sin[c + d*x])^4, x, 9, -((95*a^4*x)/8) + (12*a^4*Cos[c + d*x])/d - (4*a^4*Cos[c + d*x]^3)/(3*d) + (8*a^4*Cos[c + d*x])/(d*(1 - Sin[c + d*x])) + (31*a^4*Cos[c + d*x]*Sin[c + d*x])/(8*d) + (a^4*Cos[c + d*x]*Sin[c + d*x]^3)/(4*d)}
{Tan[c + d*x]^1*(a + a*Sin[c + d*x])^4, x, 4, -((8*a^4*Log[1 - Sin[c + d*x]])/d) - (8*a^4*Sin[c + d*x])/d - (7*a^4*Sin[c + d*x]^2)/(2*d) - (4*a^4*Sin[c + d*x]^3)/(3*d) - (a^4*Sin[c + d*x]^4)/(4*d)}
{Tan[c + d*x]^0*(a + a*Sin[c + d*x])^4, x, 4, (35*a^4*x)/8 - (35*a^4*Cos[c + d*x])/(6*d) - (35*a^4*Cos[c + d*x]*Sin[c + d*x])/(24*d) - (a*Cos[c + d*x]*(a + a*Sin[c + d*x])^3)/(4*d) - (7*Cos[c + d*x]*(a^2 + a^2*Sin[c + d*x])^2)/(12*d)}
{Cot[c + d*x]^1*(a + a*Sin[c + d*x])^4, x, 3, (a^4*Log[Sin[c + d*x]])/d + (4*a^4*Sin[c + d*x])/d + (3*a^4*Sin[c + d*x]^2)/d + (4*a^4*Sin[c + d*x]^3)/(3*d) + (a^4*Sin[c + d*x]^4)/(4*d)}
{Cot[c + d*x]^2*(a + a*Sin[c + d*x])^4, x, 9, (17*a^4*x)/8 - (4*a^4*ArcTanh[Cos[c + d*x]])/d + (4*a^4*Cos[c + d*x])/d - (4*a^4*Cos[c + d*x]^3)/(3*d) - (a^4*Cot[c + d*x])/d + (23*a^4*Cos[c + d*x]*Sin[c + d*x])/(8*d) + (a^4*Cos[c + d*x]*Sin[c + d*x]^3)/(4*d)}
{Cot[c + d*x]^3*(a + a*Sin[c + d*x])^4, x, 4, -((4*a^4*Csc[c + d*x])/d) - (a^4*Csc[c + d*x]^2)/(2*d) + (5*a^4*Log[Sin[c + d*x]])/d - (5*a^4*Sin[c + d*x]^2)/(2*d) - (4*a^4*Sin[c + d*x]^3)/(3*d) - (a^4*Sin[c + d*x]^4)/(4*d)}
{Cot[c + d*x]^4*(a + a*Sin[c + d*x])^4, x, 14, -((61*a^4*x)/8) + (2*a^4*ArcTanh[Cos[c + d*x]])/d + (4*a^4*Cos[c + d*x]^3)/(3*d) - (5*a^4*Cot[c + d*x])/d - (a^4*Cot[c + d*x]^3)/(3*d) - (2*a^4*Cot[c + d*x]*Csc[c + d*x])/d - (19*a^4*Cos[c + d*x]*Sin[c + d*x])/(8*d) - (a^4*Cos[c + d*x]*Sin[c + d*x]^3)/(4*d)}
{Cot[c + d*x]^5*(a + a*Sin[c + d*x])^4, x, 4, (4*a^4*Csc[c + d*x])/d - (2*a^4*Csc[c + d*x]^2)/d - (4*a^4*Csc[c + d*x]^3)/(3*d) - (a^4*Csc[c + d*x]^4)/(4*d) - (10*a^4*Log[Sin[c + d*x]])/d - (4*a^4*Sin[c + d*x])/d + (2*a^4*Sin[c + d*x]^2)/d + (4*a^4*Sin[c + d*x]^3)/(3*d) + (a^4*Sin[c + d*x]^4)/(4*d)}
{Cot[c + d*x]^6*(a + a*Sin[c + d*x])^4, x, 18, (97*a^4*x)/8 + (5*a^4*ArcTanh[Cos[c + d*x]])/(2*d) - (4*a^4*Cos[c + d*x])/d - (4*a^4*Cos[c + d*x]^3)/(3*d) + (10*a^4*Cot[c + d*x])/d - (5*a^4*Cot[c + d*x]^3)/(3*d) - (a^4*Cot[c + d*x]^5)/(5*d) + (5*a^4*Cot[c + d*x]*Csc[c + d*x])/(2*d) - (a^4*Cot[c + d*x]*Csc[c + d*x]^3)/d + (15*a^4*Cos[c + d*x]*Sin[c + d*x])/(8*d) + (a^4*Cos[c + d*x]*Sin[c + d*x]^3)/(4*d)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Tan[x]^6/(a + a*Sin[x]), x, 4, Sec[x]/a - Sec[x]^3/a + (3*Sec[x]^5)/(5*a) - Sec[x]^7/(7*a) + Tan[x]^7/(7*a)}
{Tan[x]^5/(a + a*Sin[x]), x, 5, (5*ArcTanh[Sin[x]])/(16*a) + 1/(32*a*(1 - Sin[x])^2) - 3/(16*a*(1 - Sin[x])) + 1/(24*a*(1 + Sin[x])^3) - 7/(32*a*(1 + Sin[x])^2) + 1/(2*a*(1 + Sin[x]))}
{Tan[x]^4/(a + a*Sin[x]), x, 4, -(Sec[x]/a) + (2*Sec[x]^3)/(3*a) - Sec[x]^5/(5*a) + Tan[x]^5/(5*a)}
{Tan[x]^3/(a + a*Sin[x]), x, 5, -((3*ArcTanh[Sin[x]])/(8*a)) + 1/(8*a*(1 - Sin[x])) + 1/(8*a*(1 + Sin[x])^2) - 1/(2*a*(1 + Sin[x]))}
{Tan[x]^2/(a + a*Sin[x]), x, 3, Sec[x]/a - Sec[x]^3/(3*a) + Tan[x]^3/(3*a)}
{Tan[x]^1/(a + a*Sin[x]), x, 5, ArcTanh[Sin[x]]/(2*a) + 1/(2*a*(1 + Sin[x]))}
{Tan[x]^0/(a + a*Sin[x]), x, 1, -(Cos[x]/(a + a*Sin[x]))}
{Cot[x]^1/(a + a*Sin[x]), x, 3, Log[Sin[x]]/a - Log[1 + Sin[x]]/a}
{Cot[x]^2/(a + a*Sin[x]), x, 2, ArcTanh[Cos[x]]/a - Cot[x]/a}
{Cot[x]^3/(a + a*Sin[x]), x, 4, Csc[x]/a - Csc[x]^2/(2*a)}
{Cot[x]^4/(a + a*Sin[x]), x, 3, -(ArcTanh[Cos[x]]/(2*a)) - Cot[x]^3/(3*a) + (Cot[x]*Csc[x])/(2*a)}
{Cot[x]^5/(a + a*Sin[x]), x, 4, -(Csc[x]/a) + Csc[x]^2/(2*a) + Csc[x]^3/(3*a) - Csc[x]^4/(4*a)}
{Cot[x]^6/(a + a*Sin[x]), x, 4, (3*ArcTanh[Cos[x]])/(8*a) - Cot[x]^5/(5*a) - (3*Cot[x]*Csc[x])/(8*a) + (Cot[x]^3*Csc[x])/(4*a)}


{Tan[x]^6/(a + a*Sin[x])^2, x, 8, (2*Sec[x]^3)/(3*a^2) - (6*Sec[x]^5)/(5*a^2) + (6*Sec[x]^7)/(7*a^2) - (2*Sec[x]^9)/(9*a^2) + Tan[x]^7/(7*a^2) + (2*Tan[x]^9)/(9*a^2)}
{Tan[x]^5/(a + a*Sin[x])^2, x, 5, (5*ArcTanh[Sin[x]])/(64*a^2) + 1/(64*a^2*(1 - Sin[x])^2) - 5/(64*a^2*(1 - Sin[x])) + 1/(32*a^2*(1 + Sin[x])^4) - 7/(48*a^2*(1 + Sin[x])^3) + 1/(4*a^2*(1 + Sin[x])^2) - 5/(32*a^2*(1 + Sin[x]))}
{Tan[x]^4/(a + a*Sin[x])^2, x, 8, -((2*Sec[x]^3)/(3*a^2)) + (4*Sec[x]^5)/(5*a^2) - (2*Sec[x]^7)/(7*a^2) + Tan[x]^5/(5*a^2) + (2*Tan[x]^7)/(7*a^2)}
{Tan[x]^3/(a + a*Sin[x])^2, x, 5, -(ArcTanh[Sin[x]]/(8*a^2)) + 1/(16*a^2*(1 - Sin[x])) + 1/(12*a^2*(1 + Sin[x])^3) - 1/(4*a^2*(1 + Sin[x])^2) + 3/(16*a^2*(1 + Sin[x]))}
{Tan[x]^2/(a + a*Sin[x])^2, x, 7, (2*Sec[x]^3)/(3*a^2) - (2*Sec[x]^5)/(5*a^2) + Tan[x]^3/(3*a^2) + (2*Tan[x]^5)/(5*a^2)}
{Tan[x]^1/(a + a*Sin[x])^2, x, 5, ArcTanh[Sin[x]]/(4*a^2) + 1/(4*a^2*(1 + Sin[x])^2) - 1/(4*a^2*(1 + Sin[x]))}
{Tan[x]^0/(a + a*Sin[x])^2, x, 2, -(Cos[x]/(3*(a + a*Sin[x])^2)) - Cos[x]/(3*(a^2 + a^2*Sin[x]))}
{Cot[x]^1/(a + a*Sin[x])^2, x, 3, Log[Sin[x]]/a^2 - Log[1 + Sin[x]]/a^2 + 1/(a^2*(1 + Sin[x]))}
{Cot[x]^2/(a + a*Sin[x])^2, x, 3, (2*ArcTanh[Cos[x]])/a^2 - Cot[x]/a^2 - (2*Cos[x])/(a^2 + a^2*Sin[x])}
{Cot[x]^3/(a + a*Sin[x])^2, x, 4, (2*Csc[x])/a^2 - Csc[x]^2/(2*a^2) + (2*Log[Sin[x]])/a^2 - (2*Log[1 + Sin[x]])/a^2}
{Cot[x]^4/(a + a*Sin[x])^2, x, 5, ArcTanh[Cos[x]]/a^2 - (2*Cot[x])/a^2 - Cot[x]^3/(3*a^2) + (Cot[x]*Csc[x])/a^2}
{Cot[x]^5/(a + a*Sin[x])^2, x, 4, -(Csc[x]^2/(2*a^2)) + (2*Csc[x]^3)/(3*a^2) - Csc[x]^4/(4*a^2)}
{Cot[x]^6/(a + a*Sin[x])^2, x, 7, -(ArcTanh[Cos[x]]/(4*a^2)) - (2*Cot[x]^3)/(3*a^2) - Cot[x]^5/(5*a^2) + (Cot[x]*Csc[x])/(4*a^2) + (Cot[x]^3*Csc[x])/(2*a^2)}


{Tan[x]^6/(a + a*Sin[x])^3, x, 29, Cos[x]/(320*a^3*(1 - Sin[x])^3) - (13*Cos[x])/(960*a^3*(1 - Sin[x])^2) + (83*Cos[x])/(3840*a^3*(1 - Sin[x])) - Cos[x]/(88*a^3*(1 + Sin[x])^6) + (89*Cos[x])/(1584*a^3*(1 + Sin[x])^5) - (1129*Cos[x])/(11088*a^3*(1 + Sin[x])^4) + (2593*Cos[x])/(36960*a^3*(1 + Sin[x])^3) + (3419*Cos[x])/(443520*a^3*(1 + Sin[x])^2) - (24347*Cos[x])/(887040*a^3*(1 + Sin[x]))}
{Tan[x]^5/(a + a*Sin[x])^3, x, 5, ArcTanh[Sin[x]]/(128*a^3) + 1/(128*a^3*(1 - Sin[x])^2) - 1/(32*a^3*(1 - Sin[x])) + 1/(40*a^3*(1 + Sin[x])^5) - 7/(64*a^3*(1 + Sin[x])^4) + 1/(6*a^3*(1 + Sin[x])^3) - 5/(64*a^3*(1 + Sin[x])^2) - 5/(128*a^3*(1 + Sin[x]))}
{Tan[x]^4/(a + a*Sin[x])^3, x, 20, Cos[x]/(96*a^3*(1 - Sin[x])^2) - (7*Cos[x])/(192*a^3*(1 - Sin[x])) - Cos[x]/(36*a^3*(1 + Sin[x])^5) + (23*Cos[x])/(252*a^3*(1 + Sin[x])^4) - (139*Cos[x])/(1680*a^3*(1 + Sin[x])^3) - (17*Cos[x])/(1260*a^3*(1 + Sin[x])^2) + (673*Cos[x])/(20160*a^3*(1 + Sin[x]))}
{Tan[x]^3/(a + a*Sin[x])^3, x, 5, -(ArcTanh[Sin[x]]/(32*a^3)) + 1/(32*a^3*(1 - Sin[x])) + 1/(16*a^3*(1 + Sin[x])^4) - 1/(6*a^3*(1 + Sin[x])^3) + 3/(32*a^3*(1 + Sin[x])^2) + 1/(16*a^3*(1 + Sin[x]))}
{Tan[x]^2/(a + a*Sin[x])^3, x, 13, Cos[x]/(16*a^3*(1 - Sin[x])) - Cos[x]/(14*a^3*(1 + Sin[x])^4) + (3*Cos[x])/(28*a^3*(1 + Sin[x])^3) + (5*Cos[x])/(168*a^3*(1 + Sin[x])^2) - (11*Cos[x])/(336*a^3*(1 + Sin[x]))}
{Tan[x]^1/(a + a*Sin[x])^3, x, 5, ArcTanh[Sin[x]]/(8*a^3) + 1/(6*a^3*(1 + Sin[x])^3) - 1/(8*a^3*(1 + Sin[x])^2) - 1/(8*a^3*(1 + Sin[x]))}
{Tan[x]^0/(a + a*Sin[x])^3, x, 3, -(Cos[x]/(5*(a + a*Sin[x])^3)) - (2*Cos[x])/(15*a*(a + a*Sin[x])^2) - (2*Cos[x])/(15*(a^3 + a^3*Sin[x]))}
{Cot[x]^1/(a + a*Sin[x])^3, x, 3, Log[Sin[x]]/a^3 - Log[1 + Sin[x]]/a^3 + 1/(2*a^3*(1 + Sin[x])^2) + 1/(a^3*(1 + Sin[x]))}
{Cot[x]^2/(a + a*Sin[x])^3, x, 6, (3*ArcTanh[Cos[x]])/a^3 - (14*Cot[x])/(3*a^3) + (2*Cot[x])/(3*a*(a + a*Sin[x])^2) + (3*Cot[x])/(a^3 + a^3*Sin[x])}
{Cot[x]^3/(a + a*Sin[x])^3, x, 4, (3*Csc[x])/a^3 - Csc[x]^2/(2*a^3) + (5*Log[Sin[x]])/a^3 - (5*Log[1 + Sin[x]])/a^3 + 2/(a^3*(1 + Sin[x]))}
{Cot[x]^4/(a + a*Sin[x])^3, x, 11, (11*ArcTanh[Cos[x]])/(2*a^3) - (13*Cot[x])/a^3 - (13*Cot[x]^3)/(3*a^3) + (11*Cot[x]*Csc[x])/(2*a^3) + (4*Cot[x]*Csc[x]^2)/(a^3*(1 + Sin[x]))}
{Cot[x]^5/(a + a*Sin[x])^3, x, 4, (4*Csc[x])/a^3 - (2*Csc[x]^2)/a^3 + Csc[x]^3/a^3 - Csc[x]^4/(4*a^3) + (4*Log[Sin[x]])/a^3 - (4*Log[1 + Sin[x]])/a^3}
{Cot[x]^6/(a + a*Sin[x])^3, x, 8, (13*ArcTanh[Cos[x]])/(8*a^3) - (4*Cot[x])/a^3 - (5*Cot[x]^3)/(3*a^3) - Cot[x]^5/(5*a^3) + (13*Cot[x]*Csc[x])/(8*a^3) + (3*Cot[x]*Csc[x]^3)/(4*a^3), (13*ArcTanh[Cos[x]])/(8*a^3) - (19*Cot[x])/(5*a^3) - (19*Cot[x]^3)/(15*a^3) + (13*Cot[x]*Csc[x])/(8*a^3) + (11*Cot[x]*Csc[x]^3)/(20*a^3) - (Cot[x]*Csc[x]^4*(1 - Sin[x]))/(5*a^3)}


{Tan[c + d*x]^6/(a + a*Sin[c + d*x])^4, x, 36, Cos[c + d*x]/(640*a^4*d*(1 - Sin[c + d*x])^3) - (7*Cos[c + d*x])/(1280*a^4*d*(1 - Sin[c + d*x])^2) + (3*Cos[c + d*x])/(1280*a^4*d*(1 - Sin[c + d*x])) - Cos[c + d*x]/(104*a^4*d*(1 + Sin[c + d*x])^7) + (105*Cos[c + d*x])/(2288*a^4*d*(1 + Sin[c + d*x])^6) - (45*Cos[c + d*x])/(572*a^4*d*(1 + Sin[c + d*x])^5) + (1563*Cos[c + d*x])/(32032*a^4*d*(1 + Sin[c + d*x])^4) + (3741*Cos[c + d*x])/(640640*a^4*d*(1 + Sin[c + d*x])^3) - (10027*Cos[c + d*x])/(1281280*a^4*d*(1 + Sin[c + d*x])^2) - (20037*Cos[c + d*x])/(1281280*a^4*d*(1 + Sin[c + d*x]))}
{Tan[c + d*x]^5/(a + a*Sin[c + d*x])^4, x, 5, -(ArcTanh[Sin[c + d*x]]/(128*a^4*d)) + 1/(256*a^4*d*(1 - Sin[c + d*x])^2) - 3/(256*a^4*d*(1 - Sin[c + d*x])) + 1/(48*a^4*d*(1 + Sin[c + d*x])^6) - 7/(80*a^4*d*(1 + Sin[c + d*x])^5) + 1/(8*a^4*d*(1 + Sin[c + d*x])^4) - 5/(96*a^4*d*(1 + Sin[c + d*x])^3) - 5/(256*a^4*d*(1 + Sin[c + d*x])^2) - 1/(256*a^4*d*(1 + Sin[c + d*x]))}
{Tan[c + d*x]^4/(a + a*Sin[c + d*x])^4, x, 26, Cos[c + d*x]/(192*a^4*d*(1 - Sin[c + d*x])^2) - Cos[c + d*x]/(96*a^4*d*(1 - Sin[c + d*x])) - Cos[c + d*x]/(44*a^4*d*(1 + Sin[c + d*x])^6) + (7*Cos[c + d*x])/(99*a^4*d*(1 + Sin[c + d*x])^5) - (641*Cos[c + d*x])/(11088*a^4*d*(1 + Sin[c + d*x])^4) - (179*Cos[c + d*x])/(18480*a^4*d*(1 + Sin[c + d*x])^3) + (2033*Cos[c + d*x])/(221760*a^4*d*(1 + Sin[c + d*x])^2) + (2749*Cos[c + d*x])/(110880*a^4*d*(1 + Sin[c + d*x]))}
{Tan[c + d*x]^3/(a + a*Sin[c + d*x])^4, x, 4, 1/(64*a^4*d*(1 - Sin[c + d*x])) + 1/(20*a^4*d*(1 + Sin[c + d*x])^5) - 1/(8*a^4*d*(1 + Sin[c + d*x])^4) + 1/(16*a^4*d*(1 + Sin[c + d*x])^3) + 1/(32*a^4*d*(1 + Sin[c + d*x])^2) + 1/(64*a^4*d*(1 + Sin[c + d*x]))}
{Tan[c + d*x]^2/(a + a*Sin[c + d*x])^4, x, 18, Cos[c + d*x]/(32*a^4*d*(1 - Sin[c + d*x])) - Cos[c + d*x]/(18*a^4*d*(1 + Sin[c + d*x])^5) + (19*Cos[c + d*x])/(252*a^4*d*(1 + Sin[c + d*x])^4) + (17*Cos[c + d*x])/(840*a^4*d*(1 + Sin[c + d*x])^3) - (37*Cos[c + d*x])/(5040*a^4*d*(1 + Sin[c + d*x])^2) - (389*Cos[c + d*x])/(10080*a^4*d*(1 + Sin[c + d*x]))}
{Tan[c + d*x]^1/(a + a*Sin[c + d*x])^4, x, 5, ArcTanh[Sin[c + d*x]]/(16*a^4*d) + 1/(8*a^4*d*(1 + Sin[c + d*x])^4) - 1/(12*a^4*d*(1 + Sin[c + d*x])^3) - 1/(16*a^4*d*(1 + Sin[c + d*x])^2) - 1/(16*a^4*d*(1 + Sin[c + d*x]))}
{Tan[c + d*x]^0/(a + a*Sin[c + d*x])^4, x, 4, -(Cos[c + d*x]/(7*d*(a + a*Sin[c + d*x])^4)) - (3*Cos[c + d*x])/(35*a*d*(a + a*Sin[c + d*x])^3) - (2*Cos[c + d*x])/(35*d*(a^2 + a^2*Sin[c + d*x])^2) - (2*Cos[c + d*x])/(35*d*(a^4 + a^4*Sin[c + d*x]))}
{Cot[c + d*x]^1/(a + a*Sin[c + d*x])^4, x, 3, Log[Sin[c + d*x]]/(a^4*d) - Log[1 + Sin[c + d*x]]/(a^4*d) + 1/(3*a^4*d*(1 + Sin[c + d*x])^3) + 1/(2*a^4*d*(1 + Sin[c + d*x])^2) + 1/(a^4*d*(1 + Sin[c + d*x]))}
{Cot[c + d*x]^2/(a + a*Sin[c + d*x])^4, x, 7, (4*ArcTanh[Cos[c + d*x]])/(a^4*d) - (94*Cot[c + d*x])/(15*a^4*d) + (13*Cot[c + d*x])/(15*a^4*d*(1 + Sin[c + d*x])^2) + (4*Cot[c + d*x])/(a^4*d*(1 + Sin[c + d*x])) + (2*Cot[c + d*x])/(5*a*d*(a + a*Sin[c + d*x])^3)}
{Cot[c + d*x]^3/(a + a*Sin[c + d*x])^4, x, 4, (4*Csc[c + d*x])/(a^4*d) - Csc[c + d*x]^2/(2*a^4*d) + (9*Log[Sin[c + d*x]])/(a^4*d) - (9*Log[1 + Sin[c + d*x]])/(a^4*d) + 1/(a^4*d*(1 + Sin[c + d*x])^2) + 5/(a^4*d*(1 + Sin[c + d*x]))}
{Cot[c + d*x]^4/(a + a*Sin[c + d*x])^4, x, 16, (14*ArcTanh[Cos[c + d*x]])/(a^4*d) - (9*Cot[c + d*x])/(a^4*d) - Cot[c + d*x]^3/(3*a^4*d) + (2*Cot[c + d*x]*Csc[c + d*x])/(a^4*d) - (4*Cos[c + d*x])/(3*a^4*d*(1 + Sin[c + d*x])^2) - (40*Cos[c + d*x])/(3*a^4*d*(1 + Sin[c + d*x])), (14*ArcTanh[Cos[c + d*x]])/(a^4*d) - (33*Cot[c + d*x])/(a^4*d) - (11*Cot[c + d*x]^3)/(a^4*d) + (14*Cot[c + d*x]*Csc[c + d*x])/(a^4*d) + (4*Cot[c + d*x]*Csc[c + d*x]^2)/(3*a^4*d*(1 + Sin[c + d*x])^2) + (28*Cot[c + d*x]*Csc[c + d*x]^2)/(3*a^4*d*(1 + Sin[c + d*x]))}
{Cot[c + d*x]^5/(a + a*Sin[c + d*x])^4, x, 4, (12*Csc[c + d*x])/(a^4*d) - (4*Csc[c + d*x]^2)/(a^4*d) + (4*Csc[c + d*x]^3)/(3*a^4*d) - Csc[c + d*x]^4/(4*a^4*d) + (16*Log[Sin[c + d*x]])/(a^4*d) - (16*Log[1 + Sin[c + d*x]])/(a^4*d) + 4/(a^4*d*(1 + Sin[c + d*x]))}
{Cot[c + d*x]^6/(a + a*Sin[c + d*x])^4, x, 15, (27*ArcTanh[Cos[c + d*x]])/(2*a^4*d) - (40*Cot[c + d*x])/(a^4*d) - (27*Cot[c + d*x]^3)/(a^4*d) - (41*Cot[c + d*x]^5)/(5*a^4*d) + (27*Cot[c + d*x]*Csc[c + d*x])/(2*a^4*d) + (9*Cot[c + d*x]*Csc[c + d*x]^3)/(a^4*d) + (8*Cot[c + d*x]*Csc[c + d*x]^4)/(a^4*d*(1 + Sin[c + d*x]))}
{Cot[c + d*x]^7/(a + a*Sin[c + d*x])^4, x, 4, (8*Csc[c + d*x])/(a^4*d) - (4*Csc[c + d*x]^2)/(a^4*d) + (8*Csc[c + d*x]^3)/(3*a^4*d) - (7*Csc[c + d*x]^4)/(4*a^4*d) + (4*Csc[c + d*x]^5)/(5*a^4*d) - Csc[c + d*x]^6/(6*a^4*d) + (8*Log[Sin[c + d*x]])/(a^4*d) - (8*Log[1 + Sin[c + d*x]])/(a^4*d)}
{Cot[c + d*x]^8/(a + a*Sin[c + d*x])^4, x, 10, (11*ArcTanh[Cos[c + d*x]])/(4*a^4*d) - (8*Cot[c + d*x])/(a^4*d) - (16*Cot[c + d*x]^3)/(3*a^4*d) - (9*Cot[c + d*x]^5)/(5*a^4*d) - Cot[c + d*x]^7/(7*a^4*d) + (11*Cot[c + d*x]*Csc[c + d*x])/(4*a^4*d) + (11*Cot[c + d*x]*Csc[c + d*x]^3)/(6*a^4*d) + (2*Cot[c + d*x]*Csc[c + d*x]^5)/(3*a^4*d), (11*ArcTanh[Cos[c + d*x]])/(4*a^4*d) - (227*Cot[c + d*x])/(35*a^4*d) - (227*Cot[c + d*x]^3)/(105*a^4*d) + (11*Cot[c + d*x]*Csc[c + d*x])/(4*a^4*d) + (11*Cot[c + d*x]*Csc[c + d*x]^3)/(6*a^4*d) - (89*Cot[c + d*x]*Csc[c + d*x]^4)/(105*a^4*d) + (8*Cot[c + d*x]*Csc[c + d*x]^5*(1 - Sin[c + d*x]))/(21*a^4*d) - (Cot[c + d*x]*Csc[c + d*x]^6*(a^2 - a^2*Sin[c + d*x])^2)/(7*a^8*d)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Tan[c+d x]^m (a+b Sin[c+d x])^(n/2) when a^2-b^2=0*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Cot[x]*Sqrt[1 + Sin[x]], x, 3, -2*ArcTanh[Sqrt[1 + Sin[x]]] + 2*Sqrt[1 + Sin[x]]}


(* ::Subsubsection:: *)
(*n<0*)


(* ::Section::Closed:: *)
(*Integrands of the form Tan[c+d x]^m (a+b Sin[c+d x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Tan[c+d x]^m (a+b Sin[c+d x])^n*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{(a + b*Sin[c + d*x])*Tan[c + d*x]^6, x, 9, -(a*x) + (b*Cos[c + d*x])/d + (3*b*Sec[c + d*x])/d - (b*Sec[c + d*x]^3)/d + (b*Sec[c + d*x]^5)/(5*d) + (a*Tan[c + d*x])/d - (a*Tan[c + d*x]^3)/(3*d) + (a*Tan[c + d*x]^5)/(5*d)}
{(a + b*Sin[c + d*x])*Tan[c + d*x]^5, x, 8, -(((8*a + 15*b)*Log[1 - Sin[c + d*x]])/(16*d)) - ((8*a - 15*b)*Log[1 + Sin[c + d*x]])/(16*d) - (15*b*Sin[c + d*x])/(8*d) - (a*Sin[c + d*x]^2)/(2*d) - (5*b*Sin[c + d*x]^3)/(8*d) + (Sin[c + d*x]^5*(b + a*Sin[c + d*x]))/(4*d*(1 - Sin[c + d*x]^2)^2) - (Sin[c + d*x]^4*(2*a + 5*b*Sin[c + d*x]))/(8*d*(1 - Sin[c + d*x]^2))}
{(a + b*Sin[c + d*x])*Tan[c + d*x]^4, x, 8, a*x - (b*Cos[c + d*x])/d - (2*b*Sec[c + d*x])/d + (b*Sec[c + d*x]^3)/(3*d) - (a*Tan[c + d*x])/d + (a*Tan[c + d*x]^3)/(3*d)}
{(a + b*Sin[c + d*x])*Tan[c + d*x]^3, x, 7, ((2*a + 3*b)*Log[1 - Sin[c + d*x]])/(4*d) + ((2*a - 3*b)*Log[1 + Sin[c + d*x]])/(4*d) + (3*b*Sin[c + d*x])/(2*d) + (a*Sin[c + d*x]^2)/(2*d) + (Sin[c + d*x]^3*(b + a*Sin[c + d*x]))/(2*d*(1 - Sin[c + d*x]^2))}
{(a + b*Sin[c + d*x])*Tan[c + d*x]^2, x, 7, -(a*x) + (b*Cos[c + d*x])/d + (b*Sec[c + d*x])/d + (a*Tan[c + d*x])/d}
{(a + b*Sin[c + d*x])*Tan[c + d*x]^1, x, 6, -((a + b)*Log[1 - Sin[c + d*x]])/(2*d) - ((a - b)*Log[1 + Sin[c + d*x]])/(2*d) - (b*Sin[c + d*x])/d}
{(a + b*Sin[c + d*x])*Tan[c + d*x]^0, x, 2, a*x - (b*Cos[c + d*x])/d}
{Cot[c + d*x]^1*(a + b*Sin[c + d*x]), x, 3, (a*Log[Sin[c + d*x]])/d + (b*Sin[c + d*x])/d}
{Cot[c + d*x]^2*(a + b*Sin[c + d*x]), x, 6, -(a*x) - (b*ArcTanh[Cos[c + d*x]])/d + (b*Cos[c + d*x])/d - (a*Cot[c + d*x])/d}
{Cot[c + d*x]^3*(a + b*Sin[c + d*x]), x, 3, -((b*Csc[c + d*x])/d) - (a*Csc[c + d*x]^2)/(2*d) - (a*Log[Sin[c + d*x]])/d - (b*Sin[c + d*x])/d}
{Cot[c + d*x]^4*(a + b*Sin[c + d*x]), x, 8, a*x + (3*b*ArcTanh[Cos[c + d*x]])/(2*d) - (3*b*Cos[c + d*x])/(2*d) + (a*Cot[c + d*x])/d - (b*Cos[c + d*x]*Cot[c + d*x]^2)/(2*d) - (a*Cot[c + d*x]^3)/(3*d)}
{Cot[c + d*x]^5*(a + b*Sin[c + d*x]), x, 3, (2*b*Csc[c + d*x])/d + (a*Csc[c + d*x]^2)/d - (b*Csc[c + d*x]^3)/(3*d) - (a*Csc[c + d*x]^4)/(4*d) + (a*Log[Sin[c + d*x]])/d + (b*Sin[c + d*x])/d}
{Cot[c + d*x]^6*(a + b*Sin[c + d*x]), x, 10, -(a*x) - (15*b*ArcTanh[Cos[c + d*x]])/(8*d) + (15*b*Cos[c + d*x])/(8*d) - (a*Cot[c + d*x])/d + (5*b*Cos[c + d*x]*Cot[c + d*x]^2)/(8*d) + (a*Cot[c + d*x]^3)/(3*d) - (b*Cos[c + d*x]*Cot[c + d*x]^4)/(4*d) - (a*Cot[c + d*x]^5)/(5*d)}


{(a + b*Sin[c + d*x])^2*Tan[c + d*x]^6, x, 14, -(a^2*x) - (7*b^2*x)/2 + (2*a*b*Cos[c + d*x])/d + (6*a*b*Sec[c + d*x])/d - (2*a*b*Sec[c + d*x]^3)/d + (2*a*b*Sec[c + d*x]^5)/(5*d) + (a^2*Tan[c + d*x])/d + (7*b^2*Tan[c + d*x])/(2*d) - (a^2*Tan[c + d*x]^3)/(3*d) - (7*b^2*Tan[c + d*x]^3)/(6*d) + (a^2*Tan[c + d*x]^5)/(5*d) + (7*b^2*Tan[c + d*x]^5)/(10*d) - (b^2*Sin[c + d*x]^2*Tan[c + d*x]^5)/(2*d)}
{(a + b*Sin[c + d*x])^2*Tan[c + d*x]^5, x, 3, -((4*a^2 + 15*a*b + 12*b^2)*Log[1 - Sin[c + d*x]])/(8*d) - ((4*a^2 - 15*a*b + 12*b^2)*Log[1 + Sin[c + d*x]])/(8*d) + (a + b)^2/(16*d*(1 - Sin[c + d*x])^2) - ((a + b)*(7*a + 11*b))/(16*d*(1 - Sin[c + d*x])) - (2*a*b*Sin[c + d*x])/d - (b^2*Sin[c + d*x]^2)/(2*d) + (a - b)^2/(16*d*(1 + Sin[c + d*x])^2) - ((7*a - 11*b)*(a - b))/(16*d*(1 + Sin[c + d*x]))}
{(a + b*Sin[c + d*x])^2*Tan[c + d*x]^4, x, 12, a^2*x + (5*b^2*x)/2 - (2*a*b*Cos[c + d*x])/d - (4*a*b*Sec[c + d*x])/d + (2*a*b*Sec[c + d*x]^3)/(3*d) - (a^2*Tan[c + d*x])/d - (5*b^2*Tan[c + d*x])/(2*d) + (a^2*Tan[c + d*x]^3)/(3*d) + (5*b^2*Tan[c + d*x]^3)/(6*d) - (b^2*Sin[c + d*x]^2*Tan[c + d*x]^3)/(2*d)}
{(a + b*Sin[c + d*x])^2*Tan[c + d*x]^3, x, 3, ((a + b)*(a + 2*b)*Log[1 - Sin[c + d*x]])/(2*d) + ((a - 2*b)*(a - b)*Log[1 + Sin[c + d*x]])/(2*d) + (a + b)^2/(4*d*(1 - Sin[c + d*x])) + (2*a*b*Sin[c + d*x])/d + (b^2*Sin[c + d*x]^2)/(2*d) + (a - b)^2/(4*d*(1 + Sin[c + d*x]))}
{(a + b*Sin[c + d*x])^2*Tan[c + d*x]^2, x, 10, -(a^2*x) - (3*b^2*x)/2 + (2*a*b*Cos[c + d*x])/d + (2*a*b*Sec[c + d*x])/d + (a^2*Tan[c + d*x])/d + (3*b^2*Tan[c + d*x])/(2*d) - (b^2*Sin[c + d*x]^2*Tan[c + d*x])/(2*d)}
{(a + b*Sin[c + d*x])^2*Tan[c + d*x]^1, x, 6, -(((a + b)^2*Log[1 - Sin[c + d*x]])/(2*d)) - ((a - b)^2*Log[1 + Sin[c + d*x]])/(2*d) - (2*a*b*Sin[c + d*x])/d - (b^2*Sin[c + d*x]^2)/(2*d)}
{(a + b*Sin[c + d*x])^2*Tan[c + d*x]^0, x, 2, ((2*a^2 + b^2)*x)/2 - (2*a*b*Cos[c + d*x])/d - (b^2*Cos[c + d*x]*Sin[c + d*x])/(2*d)}
{Cot[c + d*x]^1*(a + b*Sin[c + d*x])^2, x, 3, (a^2*Log[Sin[c + d*x]])/d + (2*a*b*Sin[c + d*x])/d + (b^2*Sin[c + d*x]^2)/(2*d)}
{Cot[c + d*x]^2*(a + b*Sin[c + d*x])^2, x, 7, -(a^2*x) + (b^2*x)/2 - (2*a*b*ArcTanh[Cos[c + d*x]])/d + (2*a*b*Cos[c + d*x])/d - (a^2*Cot[c + d*x])/d + (b^2*Cos[c + d*x]*Sin[c + d*x])/(2*d)}
{Cot[c + d*x]^3*(a + b*Sin[c + d*x])^2, x, 3, (-2*a*b*Csc[c + d*x])/d - (a^2*Csc[c + d*x]^2)/(2*d) - ((a^2 - b^2)*Log[Sin[c + d*x]])/d - (2*a*b*Sin[c + d*x])/d - (b^2*Sin[c + d*x]^2)/(2*d)}
{Cot[c + d*x]^4*(a + b*Sin[c + d*x])^2, x, 11, a^2*x - (3*b^2*x)/2 + (3*a*b*ArcTanh[Cos[c + d*x]])/d - (3*a*b*Cos[c + d*x])/d + (a^2*Cot[c + d*x])/d - (3*b^2*Cot[c + d*x])/(2*d) + (b^2*Cos[c + d*x]^2*Cot[c + d*x])/(2*d) - (a*b*Cos[c + d*x]*Cot[c + d*x]^2)/d - (a^2*Cot[c + d*x]^3)/(3*d)}
{Cot[c + d*x]^5*(a + b*Sin[c + d*x])^2, x, 3, (4*a*b*Csc[c + d*x])/d + ((2*a^2 - b^2)*Csc[c + d*x]^2)/(2*d) - (2*a*b*Csc[c + d*x]^3)/(3*d) - (a^2*Csc[c + d*x]^4)/(4*d) + ((a^2 - 2*b^2)*Log[Sin[c + d*x]])/d + (2*a*b*Sin[c + d*x])/d + (b^2*Sin[c + d*x]^2)/(2*d)}
{Cot[c + d*x]^6*(a + b*Sin[c + d*x])^2, x, 14, -(a^2*x) + (5*b^2*x)/2 - (15*a*b*ArcTanh[Cos[c + d*x]])/(4*d) + (15*a*b*Cos[c + d*x])/(4*d) - (a^2*Cot[c + d*x])/d + (5*b^2*Cot[c + d*x])/(2*d) + (5*a*b*Cos[c + d*x]*Cot[c + d*x]^2)/(4*d) + (a^2*Cot[c + d*x]^3)/(3*d) - (5*b^2*Cot[c + d*x]^3)/(6*d) + (b^2*Cos[c + d*x]^2*Cot[c + d*x]^3)/(2*d) - (a*b*Cos[c + d*x]*Cot[c + d*x]^4)/(2*d) - (a^2*Cot[c + d*x]^5)/(5*d)}


{(a + b*Sin[c + d*x])^3*Tan[c + d*x]^8, x, 19, a^3*x + (27*a*b^2*x)/2 - (3*a^2*b*Cos[c + d*x])/d - (5*b^3*Cos[c + d*x])/d + (b^3*Cos[c + d*x]^3)/(3*d) - (12*a^2*b*Sec[c + d*x])/d - (10*b^3*Sec[c + d*x])/d + (6*a^2*b*Sec[c + d*x]^3)/d + (10*b^3*Sec[c + d*x]^3)/(3*d) - (12*a^2*b*Sec[c + d*x]^5)/(5*d) - (b^3*Sec[c + d*x]^5)/d + (3*a^2*b*Sec[c + d*x]^7)/(7*d) + (b^3*Sec[c + d*x]^7)/(7*d) - (a^3*Tan[c + d*x])/d - (27*a*b^2*Tan[c + d*x])/(2*d) + (a^3*Tan[c + d*x]^3)/(3*d) + (9*a*b^2*Tan[c + d*x]^3)/(2*d) - (a^3*Tan[c + d*x]^5)/(5*d) - (27*a*b^2*Tan[c + d*x]^5)/(10*d) + (a^3*Tan[c + d*x]^7)/(7*d) + (27*a*b^2*Tan[c + d*x]^7)/(14*d) - (3*a*b^2*Sin[c + d*x]^2*Tan[c + d*x]^7)/(2*d)}
{(a + b*Sin[c + d*x])^3*Tan[c + d*x]^7, x, 3, ((16*a^3 + 105*a^2*b + 192*a*b^2 + 105*b^3)*Log[1 - Sin[c + d*x]])/(32*d) + ((16*a^3 - 105*a^2*b + 192*a*b^2 - 105*b^3)*Log[1 + Sin[c + d*x]])/(32*d) + (a + b)^3/(48*d*(1 - Sin[c + d*x])^3) - ((a + b)^2*(5*a + 8*b))/(32*d*(1 - Sin[c + d*x])^2) + ((a + b)*(19*a^2 + 68*a*b + 55*b^2))/(32*d*(1 - Sin[c + d*x])) + (b*(3*a^2 + 4*b^2)*Sin[c + d*x])/d + (3*a*b^2*Sin[c + d*x]^2)/(2*d) + (b^3*Sin[c + d*x]^3)/(3*d) + (a - b)^3/(48*d*(1 + Sin[c + d*x])^3) - ((5*a - 8*b)*(a - b)^2)/(32*d*(1 + Sin[c + d*x])^2) + ((a - b)*(19*a^2 - 68*a*b + 55*b^2))/(32*d*(1 + Sin[c + d*x]))}
{(a + b*Sin[c + d*x])^3*Tan[c + d*x]^6, x, 17, -(a^3*x) - (21*a*b^2*x)/2 + (3*a^2*b*Cos[c + d*x])/d + (4*b^3*Cos[c + d*x])/d - (b^3*Cos[c + d*x]^3)/(3*d) + (9*a^2*b*Sec[c + d*x])/d + (6*b^3*Sec[c + d*x])/d - (3*a^2*b*Sec[c + d*x]^3)/d - (4*b^3*Sec[c + d*x]^3)/(3*d) + (3*a^2*b*Sec[c + d*x]^5)/(5*d) + (b^3*Sec[c + d*x]^5)/(5*d) + (a^3*Tan[c + d*x])/d + (21*a*b^2*Tan[c + d*x])/(2*d) - (a^3*Tan[c + d*x]^3)/(3*d) - (7*a*b^2*Tan[c + d*x]^3)/(2*d) + (a^3*Tan[c + d*x]^5)/(5*d) + (21*a*b^2*Tan[c + d*x]^5)/(10*d) - (3*a*b^2*Sin[c + d*x]^2*Tan[c + d*x]^5)/(2*d)}
{(a + b*Sin[c + d*x])^3*Tan[c + d*x]^5, x, 3, -((a + b)*(8*a^2 + 37*a*b + 35*b^2)*Log[1 - Sin[c + d*x]])/(16*d) - ((a - b)*(8*a^2 - 37*a*b + 35*b^2)*Log[1 + Sin[c + d*x]])/(16*d) + (a + b)^3/(16*d*(1 - Sin[c + d*x])^2) - ((a + b)^2*(7*a + 13*b))/(16*d*(1 - Sin[c + d*x])) - (3*b*(a^2 + b^2)*Sin[c + d*x])/d - (3*a*b^2*Sin[c + d*x]^2)/(2*d) - (b^3*Sin[c + d*x]^3)/(3*d) + (a - b)^3/(16*d*(1 + Sin[c + d*x])^2) - ((7*a - 13*b)*(a - b)^2)/(16*d*(1 + Sin[c + d*x]))}
{(a + b*Sin[c + d*x])^3*Tan[c + d*x]^4, x, 15, a^3*x + (15*a*b^2*x)/2 - (3*a^2*b*Cos[c + d*x])/d - (3*b^3*Cos[c + d*x])/d + (b^3*Cos[c + d*x]^3)/(3*d) - (6*a^2*b*Sec[c + d*x])/d - (3*b^3*Sec[c + d*x])/d + (a^2*b*Sec[c + d*x]^3)/d + (b^3*Sec[c + d*x]^3)/(3*d) - (a^3*Tan[c + d*x])/d - (15*a*b^2*Tan[c + d*x])/(2*d) + (a^3*Tan[c + d*x]^3)/(3*d) + (5*a*b^2*Tan[c + d*x]^3)/(2*d) - (3*a*b^2*Sin[c + d*x]^2*Tan[c + d*x]^3)/(2*d)}
{(a + b*Sin[c + d*x])^3*Tan[c + d*x]^3, x, 3, ((a + b)^2*(2*a + 5*b)*Log[1 - Sin[c + d*x]])/(4*d) + ((2*a - 5*b)*(a - b)^2*Log[1 + Sin[c + d*x]])/(4*d) + (a + b)^3/(4*d*(1 - Sin[c + d*x])) + (b*(3*a^2 + 2*b^2)*Sin[c + d*x])/d + (3*a*b^2*Sin[c + d*x]^2)/(2*d) + (b^3*Sin[c + d*x]^3)/(3*d) + (a - b)^3/(4*d*(1 + Sin[c + d*x]))}
{(a + b*Sin[c + d*x])^3*Tan[c + d*x]^2, x, 13, -(a^3*x) - (9*a*b^2*x)/2 + (3*a^2*b*Cos[c + d*x])/d + (2*b^3*Cos[c + d*x])/d - (b^3*Cos[c + d*x]^3)/(3*d) + (3*a^2*b*Sec[c + d*x])/d + (b^3*Sec[c + d*x])/d + (a^3*Tan[c + d*x])/d + (9*a*b^2*Tan[c + d*x])/(2*d) - (3*a*b^2*Sin[c + d*x]^2*Tan[c + d*x])/(2*d)}
{(a + b*Sin[c + d*x])^3*Tan[c + d*x]^1, x, 6, -(((a + b)^3*Log[1 - Sin[c + d*x]])/(2*d)) - ((a - b)^3*Log[1 + Sin[c + d*x]])/(2*d) - (b*(3*a^2 + b^2)*Sin[c + d*x])/d - (3*a*b^2*Sin[c + d*x]^2)/(2*d) - (b^3*Sin[c + d*x]^3)/(3*d)}
{(a + b*Sin[c + d*x])^3*Tan[c + d*x]^0, x, 3, (a*(2*a^2 + 3*b^2)*x)/2 - (2*b*(4*a^2 + b^2)*Cos[c + d*x])/(3*d) - (5*a*b^2*Cos[c + d*x]*Sin[c + d*x])/(6*d) - (b*Cos[c + d*x]*(a + b*Sin[c + d*x])^2)/(3*d)}
{Cot[c + d*x]^1*(a + b*Sin[c + d*x])^3, x, 3, (a^3*Log[Sin[c + d*x]])/d + (3*a^2*b*Sin[c + d*x])/d + (3*a*b^2*Sin[c + d*x]^2)/(2*d) + (b^3*Sin[c + d*x]^3)/(3*d)}
{Cot[c + d*x]^2*(a + b*Sin[c + d*x])^3, x, 8, -(a^3*x) + (3*a*b^2*x)/2 - (3*a^2*b*ArcTanh[Cos[c + d*x]])/d + (3*a^2*b*Cos[c + d*x])/d - (b^3*Cos[c + d*x]^3)/(3*d) - (a^3*Cot[c + d*x])/d + (3*a*b^2*Cos[c + d*x]*Sin[c + d*x])/(2*d)}
{Cot[c + d*x]^3*(a + b*Sin[c + d*x])^3, x, 3, (-3*a^2*b*Csc[c + d*x])/d - (a^3*Csc[c + d*x]^2)/(2*d) - (a*(a^2 - 3*b^2)*Log[Sin[c + d*x]])/d - (b*(3*a^2 - b^2)*Sin[c + d*x])/d - (3*a*b^2*Sin[c + d*x]^2)/(2*d) - (b^3*Sin[c + d*x]^3)/(3*d)}
{Cot[c + d*x]^4*(a + b*Sin[c + d*x])^3, x, 14, a^3*x - (9*a*b^2*x)/2 + (9*a^2*b*ArcTanh[Cos[c + d*x]])/(2*d) - (b^3*ArcTanh[Cos[c + d*x]])/d - (9*a^2*b*Cos[c + d*x])/(2*d) + (b^3*Cos[c + d*x])/d + (b^3*Cos[c + d*x]^3)/(3*d) + (a^3*Cot[c + d*x])/d - (9*a*b^2*Cot[c + d*x])/(2*d) + (3*a*b^2*Cos[c + d*x]^2*Cot[c + d*x])/(2*d) - (3*a^2*b*Cos[c + d*x]*Cot[c + d*x]^2)/(2*d) - (a^3*Cot[c + d*x]^3)/(3*d)}
{Cot[c + d*x]^5*(a + b*Sin[c + d*x])^3, x, 3, (b*(6*a^2 - b^2)*Csc[c + d*x])/d + (a*(2*a^2 - 3*b^2)*Csc[c + d*x]^2)/(2*d) - (a^2*b*Csc[c + d*x]^3)/d - (a^3*Csc[c + d*x]^4)/(4*d) + (a*(a^2 - 6*b^2)*Log[Sin[c + d*x]])/d + (b*(3*a^2 - 2*b^2)*Sin[c + d*x])/d + (3*a*b^2*Sin[c + d*x]^2)/(2*d) + (b^3*Sin[c + d*x]^3)/(3*d)}
{Cot[c + d*x]^6*(a + b*Sin[c + d*x])^3, x, 18, -(a^3*x) + (15*a*b^2*x)/2 - (45*a^2*b*ArcTanh[Cos[c + d*x]])/(8*d) + (5*b^3*ArcTanh[Cos[c + d*x]])/(2*d) + (45*a^2*b*Cos[c + d*x])/(8*d) - (5*b^3*Cos[c + d*x])/(2*d) - (a^3*Cot[c + d*x])/d + (15*a*b^2*Cot[c + d*x])/(2*d) + (15*a^2*b*Cos[c + d*x]*Cot[c + d*x]^2)/(8*d) - (5*b^3*Cos[c + d*x]*Cot[c + d*x]^2)/(6*d) + (b^3*Cos[c + d*x]^3*Cot[c + d*x]^2)/(3*d) + (a^3*Cot[c + d*x]^3)/(3*d) - (5*a*b^2*Cot[c + d*x]^3)/(2*d) + (3*a*b^2*Cos[c + d*x]^2*Cot[c + d*x]^3)/(2*d) - (3*a^2*b*Cos[c + d*x]*Cot[c + d*x]^4)/(4*d) - (a^3*Cot[c + d*x]^5)/(5*d)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Tan[c + d*x]^6/(a + b*Sin[c + d*x]), x, 10, (-2*a^6*ArcTan[(b + a*Tan[(c + d*x)/2])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(7/2)*d) - (a^4*b*Sec[c + d*x])/((a^2 - b^2)^3*d) - (a^2*b*Sec[c + d*x])/((a^2 - b^2)^2*d) - (b*Sec[c + d*x])/((a^2 - b^2)*d) + (a^2*b*Sec[c + d*x]^3)/(3*(a^2 - b^2)^2*d) + (2*b*Sec[c + d*x]^3)/(3*(a^2 - b^2)*d) - (b*Sec[c + d*x]^5)/(5*(a^2 - b^2)*d) + (a^5*Tan[c + d*x])/((a^2 - b^2)^3*d) - (a^3*Tan[c + d*x]^3)/(3*(a^2 - b^2)^2*d) + (a*Tan[c + d*x]^5)/(5*(a^2 - b^2)*d)}
{Tan[c + d*x]^5/(a + b*Sin[c + d*x]), x, 3, -((8*a^2 + 9*a*b + 3*b^2)*Log[1 - Sin[c + d*x]])/(16*(a + b)^3*d) - ((8*a^2 - 9*a*b + 3*b^2)*Log[1 + Sin[c + d*x]])/(16*(a - b)^3*d) + (a^5*Log[a + b*Sin[c + d*x]])/((a^2 - b^2)^3*d) + 1/(16*(a + b)*d*(1 - Sin[c + d*x])^2) - (7*a + 5*b)/(16*(a + b)^2*d*(1 - Sin[c + d*x])) + 1/(16*(a - b)*d*(1 + Sin[c + d*x])^2) - (7*a - 5*b)/(16*(a - b)^2*d*(1 + Sin[c + d*x]))}
{Tan[c + d*x]^4/(a + b*Sin[c + d*x]), x, 6, (2*a^4*ArcTan[(b + a*Tan[(c + d*x)/2])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(5/2)*d) + (a^2*b*Sec[c + d*x])/((a^2 - b^2)^2*d) + (b*Sec[c + d*x])/((a^2 - b^2)*d) - (b*Sec[c + d*x]^3)/(3*(a^2 - b^2)*d) - (a^3*Tan[c + d*x])/((a^2 - b^2)^2*d) + (a*Tan[c + d*x]^3)/(3*(a^2 - b^2)*d)}
{Tan[c + d*x]^3/(a + b*Sin[c + d*x]), x, 3, ((2*a + b)*Log[1 - Sin[c + d*x]])/(4*(a + b)^2*d) + ((2*a - b)*Log[1 + Sin[c + d*x]])/(4*(a - b)^2*d) - (a^3*Log[a + b*Sin[c + d*x]])/((a^2 - b^2)^2*d) + 1/(4*(a + b)*d*(1 - Sin[c + d*x])) + 1/(4*(a - b)*d*(1 + Sin[c + d*x]))}
{Tan[c + d*x]^2/(a + b*Sin[c + d*x]), x, 3, (-2*a^2*ArcTan[(b + a*Tan[(c + d*x)/2])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(3/2)*d) - (b*Sec[c + d*x])/((a^2 - b^2)*d) + (a*Tan[c + d*x])/((a^2 - b^2)*d)}
{Tan[c + d*x]^1/(a + b*Sin[c + d*x]), x, 6, -Log[1 - Sin[c + d*x]]/(2*(a + b)*d) - Log[1 + Sin[c + d*x]]/(2*(a - b)*d) + (a*Log[a + b*Sin[c + d*x]])/((a^2 - b^2)*d)}
{Tan[c + d*x]^0/(a + b*Sin[c + d*x]), x, 1, (2*ArcTan[(b + a*Tan[(c + d*x)/2])/Sqrt[a^2 - b^2]])/(Sqrt[a^2 - b^2]*d)}
{Cot[c + d*x]^1/(a + b*Sin[c + d*x]), x, 3, Log[Sin[c + d*x]]/(a*d) - Log[a + b*Sin[c + d*x]]/(a*d)}
{Cot[c + d*x]^2/(a + b*Sin[c + d*x]), x, 3, (-2*Sqrt[a^2 - b^2]*ArcTan[(b + a*Tan[(c + d*x)/2])/Sqrt[a^2 - b^2]])/(a^2*d) + (b*ArcTanh[Cos[c + d*x]])/(a^2*d) - Cot[c + d*x]/(a*d)}
{Cot[c + d*x]^3/(a + b*Sin[c + d*x]), x, 3, (b*Csc[c + d*x])/(a^2*d) - Csc[c + d*x]^2/(2*a*d) - ((a^2 - b^2)*Log[Sin[c + d*x]])/(a^3*d) + ((a^2 - b^2)*Log[a + b*Sin[c + d*x]])/(a^3*d)}
{Cot[c + d*x]^4/(a + b*Sin[c + d*x]), x, 6, (2*(a^2 - b^2)^(3/2)*ArcTan[(b + a*Tan[(c + d*x)/2])/Sqrt[a^2 - b^2]])/(a^4*d) - (b*ArcTanh[Cos[c + d*x]])/(2*a^2*d) - (b*(a^2 - b^2)*ArcTanh[Cos[c + d*x]])/(a^4*d) + ((a^2 - b^2)*Cot[c + d*x])/(a^3*d) - Cot[c + d*x]^3/(3*a*d) + (b*Cot[c + d*x]*Csc[c + d*x])/(2*a^2*d)}
{Cot[c + d*x]^5/(a + b*Sin[c + d*x]), x, 3, -((b*(2*a^2 - b^2)*Csc[c + d*x])/(a^4*d)) + ((2*a^2 - b^2)*Csc[c + d*x]^2)/(2*a^3*d) + (b*Csc[c + d*x]^3)/(3*a^2*d) - Csc[c + d*x]^4/(4*a*d) + ((a^2 - b^2)^2*Log[Sin[c + d*x]])/(a^5*d) - ((a^2 - b^2)^2*Log[a + b*Sin[c + d*x]])/(a^5*d)}
{Cot[c + d*x]^6/(a + b*Sin[c + d*x]), x, 10, (-2*(a^2 - b^2)^(5/2)*ArcTan[(b + a*Tan[(c + d*x)/2])/Sqrt[a^2 - b^2]])/(a^6*d) + (3*b*ArcTanh[Cos[c + d*x]])/(8*a^2*d) + (b*(a^2 - b^2)*ArcTanh[Cos[c + d*x]])/(2*a^4*d) + (b*(a^2 - b^2)^2*ArcTanh[Cos[c + d*x]])/(a^6*d) - ((a^2 - b^2)^2*Cot[c + d*x])/(a^5*d) + ((a^2 - b^2)*Cot[c + d*x]^3)/(3*a^3*d) - Cot[c + d*x]^5/(5*a*d) - (3*b*Cot[c + d*x]*Csc[c + d*x])/(8*a^2*d) - (b*(a^2 - b^2)*Cot[c + d*x]*Csc[c + d*x])/(2*a^4*d) + (b*Cot[c + d*x]^3*Csc[c + d*x])/(4*a^2*d)}


{Tan[c + d*x]^6/(a + b*Sin[c + d*x])^2, x, 18, -((2*a^7*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(9/2)*d)) - (12*a^5*b^2*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(9/2)*d) + Cos[c + d*x]/(40*(a + b)^2*d*(1 - Sin[c + d*x])^3) + Cos[c + d*x]/(60*(a + b)^2*d*(1 - Sin[c + d*x])^2) - ((9*a + 5*b)*Cos[c + d*x])/(48*(a + b)^3*d*(1 - Sin[c + d*x])^2) + Cos[c + d*x]/(60*(a + b)^2*d*(1 - Sin[c + d*x])) - ((9*a + 5*b)*Cos[c + d*x])/(48*(a + b)^3*d*(1 - Sin[c + d*x])) + (3*(5*a^2 + 4*a*b + b^2)*Cos[c + d*x])/(16*(a + b)^4*d*(1 - Sin[c + d*x])) - Cos[c + d*x]/(40*(a - b)^2*d*(1 + Sin[c + d*x])^3) + ((9*a - 5*b)*Cos[c + d*x])/(48*(a - b)^3*d*(1 + Sin[c + d*x])^2) - Cos[c + d*x]/(60*(a - b)^2*d*(1 + Sin[c + d*x])^2) + ((9*a - 5*b)*Cos[c + d*x])/(48*(a - b)^3*d*(1 + Sin[c + d*x])) - Cos[c + d*x]/(60*(a - b)^2*d*(1 + Sin[c + d*x])) - (3*(5*a^2 - 4*a*b + b^2)*Cos[c + d*x])/(16*(a - b)^4*d*(1 + Sin[c + d*x])) - (a^6*b*Cos[c + d*x])/((a^2 - b^2)^4*d*(a + b*Sin[c + d*x]))}
{Tan[c + d*x]^5/(a + b*Sin[c + d*x])^2, x, 3, -(a*(4*a + b)*Log[1 - Sin[c + d*x]])/(8*(a + b)^4*d) - (a*(4*a - b)*Log[1 + Sin[c + d*x]])/(8*(a - b)^4*d) + (a^4*(a^2 + 5*b^2)*Log[a + b*Sin[c + d*x]])/((a^2 - b^2)^4*d) + 1/(16*(a + b)^2*d*(1 - Sin[c + d*x])^2) - (7*a + 3*b)/(16*(a + b)^3*d*(1 - Sin[c + d*x])) + 1/(16*(a - b)^2*d*(1 + Sin[c + d*x])^2) - (7*a - 3*b)/(16*(a - b)^3*d*(1 + Sin[c + d*x])) - a^5/((a^2 - b^2)^3*d*(a + b*Sin[c + d*x]))}
{Tan[c + d*x]^4/(a + b*Sin[c + d*x])^2, x, 12, (2*a^5*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(7/2)*d) + (8*a^3*b^2*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(7/2)*d) + Cos[c + d*x]/(12*(a + b)^2*d*(1 - Sin[c + d*x])^2) + Cos[c + d*x]/(12*(a + b)^2*d*(1 - Sin[c + d*x])) - ((3*a + b)*Cos[c + d*x])/(4*(a + b)^3*d*(1 - Sin[c + d*x])) - Cos[c + d*x]/(12*(a - b)^2*d*(1 + Sin[c + d*x])^2) - Cos[c + d*x]/(12*(a - b)^2*d*(1 + Sin[c + d*x])) + ((3*a - b)*Cos[c + d*x])/(4*(a - b)^3*d*(1 + Sin[c + d*x])) + (a^4*b*Cos[c + d*x])/((a^2 - b^2)^3*d*(a + b*Sin[c + d*x]))}
{Tan[c + d*x]^3/(a + b*Sin[c + d*x])^2, x, 3, (a*Log[1 - Sin[c + d*x]])/(2*(a + b)^3*d) + (a*Log[1 + Sin[c + d*x]])/(2*(a - b)^3*d) - (a^2*(a^2 + 3*b^2)*Log[a + b*Sin[c + d*x]])/((a^2 - b^2)^3*d) + 1/(4*(a + b)^2*d*(1 - Sin[c + d*x])) + 1/(4*(a - b)^2*d*(1 + Sin[c + d*x])) + a^3/((a^2 - b^2)^2*d*(a + b*Sin[c + d*x]))}
{Tan[c + d*x]^2/(a + b*Sin[c + d*x])^2, x, 8, -((2*a^3*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(5/2)*d)) - (4*a*b^2*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(5/2)*d) + Cos[c + d*x]/(2*(a + b)^2*d*(1 - Sin[c + d*x])) - Cos[c + d*x]/(2*(a - b)^2*d*(1 + Sin[c + d*x])) - (a^2*b*Cos[c + d*x])/((a^2 - b^2)^2*d*(a + b*Sin[c + d*x]))}
{Tan[c + d*x]^1/(a + b*Sin[c + d*x])^2, x, 7, -Log[1 - Sin[c + d*x]]/(2*(a + b)^2*d) - Log[1 + Sin[c + d*x]]/(2*(a - b)^2*d) + ((a^2 + b^2)*Log[a + b*Sin[c + d*x]])/((a^2 - b^2)^2*d) - a/((a^2 - b^2)*d*(a + b*Sin[c + d*x]))}
{Tan[c + d*x]^0/(a + b*Sin[c + d*x])^2, x, 3, (2*a*ArcTan[(b + a*Tan[(c + d*x)/2])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(3/2)*d) + (b*Cos[c + d*x])/((a^2 - b^2)*d*(a + b*Sin[c + d*x]))}
{Cot[c + d*x]^1/(a + b*Sin[c + d*x])^2, x, 3, Log[Sin[c + d*x]]/(a^2*d) - Log[a + b*Sin[c + d*x]]/(a^2*d) + 1/(a*d*(a + b*Sin[c + d*x]))}
{Cot[c + d*x]^2/(a + b*Sin[c + d*x])^2, x, 8, -((2*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/(a*Sqrt[a^2 - b^2]*d)) + (4*b^2*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/(a^3*Sqrt[a^2 - b^2]*d) + (2*b*ArcTanh[Cos[c + d*x]])/(a^3*d) - Cot[c + d*x]/(a^2*d) - (b*Cos[c + d*x])/(a^2*d*(a + b*Sin[c + d*x]))}
{Cot[c + d*x]^3/(a + b*Sin[c + d*x])^2, x, 3, (2*b*Csc[c + d*x])/(a^3*d) - Csc[c + d*x]^2/(2*a^2*d) - ((a^2 - 3*b^2)*Log[Sin[c + d*x]])/(a^4*d) + ((a^2 - 3*b^2)*Log[a + b*Sin[c + d*x]])/(a^4*d) - (a^2 - b^2)/(a^3*d*(a + b*Sin[c + d*x]))}
{Cot[c + d*x]^4/(a + b*Sin[c + d*x])^2, x, 12, (2*Sqrt[a^2 - b^2]*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/(a^3*d) - (8*b^2*Sqrt[a^2 - b^2]*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/(a^5*d) + (b*ArcTanh[Cos[c + d*x]])/(a^3*d) - (4*b*(a^2 - b^2)*ArcTanh[Cos[c + d*x]])/(a^5*d) - (2*Cot[c + d*x])/(3*a^2*d) + ((2*a^2 - 3*b^2)*Cot[c + d*x])/(a^4*d) + (b*Cot[c + d*x]*Csc[c + d*x])/(a^3*d) - (Cot[c + d*x]*Csc[c + d*x]^2)/(3*a^2*d) + (b*(a^2 - b^2)*Cos[c + d*x])/(a^4*d*(a + b*Sin[c + d*x]))}
{Cot[c + d*x]^5/(a + b*Sin[c + d*x])^2, x, 3, (-4*b*(a^2 - b^2)*Csc[c + d*x])/(a^5*d) + ((2*a^2 - 3*b^2)*Csc[c + d*x]^2)/(2*a^4*d) + (2*b*Csc[c + d*x]^3)/(3*a^3*d) - Csc[c + d*x]^4/(4*a^2*d) + ((a^4 - 6*a^2*b^2 + 5*b^4)*Log[Sin[c + d*x]])/(a^6*d) - ((a^4 - 6*a^2*b^2 + 5*b^4)*Log[a + b*Sin[c + d*x]])/(a^6*d) + (a^2 - b^2)^2/(a^5*d*(a + b*Sin[c + d*x]))}
{Cot[c + d*x]^6/(a + b*Sin[c + d*x])^2, x, 18, -((2*(a^2 - b^2)^(3/2)*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/(a^5*d)) + (12*b^2*(a^2 - b^2)^(3/2)*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/(a^7*d) + (3*b*ArcTanh[Cos[c + d*x]])/(4*a^3*d) - (b*(3*a^2 - 2*b^2)*ArcTanh[Cos[c + d*x]])/(a^5*d) + (6*b*(a^2 - b^2)^2*ArcTanh[Cos[c + d*x]])/(a^7*d) - (4*Cot[c + d*x])/(5*a^2*d) + (2*(a^2 - b^2)*Cot[c + d*x])/(a^4*d) - ((3*a^4 - 9*a^2*b^2 + 5*b^4)*Cot[c + d*x])/(a^6*d) - (4*Cot[c + d*x]^3)/(15*a^2*d) + (3*b*Cot[c + d*x]*Csc[c + d*x])/(4*a^3*d) - (b*(3*a^2 - 2*b^2)*Cot[c + d*x]*Csc[c + d*x])/(a^5*d) + ((a^2 - b^2)*Cot[c + d*x]*Csc[c + d*x]^2)/(a^4*d) + (b*Cot[c + d*x]*Csc[c + d*x]^3)/(2*a^3*d) - (Cot[c + d*x]*Csc[c + d*x]^4)/(5*a^2*d) - (b*(a^2 - b^2)^2*Cos[c + d*x])/(a^6*d*(a + b*Sin[c + d*x]))}


{Tan[c + d*x]^6/(a + b*Sin[c + d*x])^3, x, 22, -((12*a^6*b^2*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(11/2)*d)) - (a^6*(2*a^2 + b^2)*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(11/2)*d) - (6*a^4*b^2*(3*a^2 + 5*b^2)*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(11/2)*d) + Cos[c + d*x]/(40*(a + b)^3*d*(1 - Sin[c + d*x])^3) + Cos[c + d*x]/(60*(a + b)^3*d*(1 - Sin[c + d*x])^2) - ((3*a + b)*Cos[c + d*x])/(16*(a + b)^4*d*(1 - Sin[c + d*x])^2) + Cos[c + d*x]/(60*(a + b)^3*d*(1 - Sin[c + d*x])) - ((3*a + b)*Cos[c + d*x])/(16*(a + b)^4*d*(1 - Sin[c + d*x])) + (3*a*(5*a + b)*Cos[c + d*x])/(16*(a + b)^5*d*(1 - Sin[c + d*x])) - Cos[c + d*x]/(40*(a - b)^3*d*(1 + Sin[c + d*x])^3) - Cos[c + d*x]/(60*(a - b)^3*d*(1 + Sin[c + d*x])^2) + ((3*a - b)*Cos[c + d*x])/(16*(a - b)^4*d*(1 + Sin[c + d*x])^2) - Cos[c + d*x]/(60*(a - b)^3*d*(1 + Sin[c + d*x])) + ((3*a - b)*Cos[c + d*x])/(16*(a - b)^4*d*(1 + Sin[c + d*x])) - (3*a*(5*a - b)*Cos[c + d*x])/(16*(a - b)^5*d*(1 + Sin[c + d*x])) - (a^6*b*Cos[c + d*x])/(2*(a^2 - b^2)^4*d*(a + b*Sin[c + d*x])^2) - (3*a^7*b*Cos[c + d*x])/(2*(a^2 - b^2)^5*d*(a + b*Sin[c + d*x])) - (6*a^5*b^3*Cos[c + d*x])/((a^2 - b^2)^5*d*(a + b*Sin[c + d*x]))}
{Tan[c + d*x]^5/(a + b*Sin[c + d*x])^3, x, 3, -((8*a^2 - 5*a*b - b^2)*Log[1 - Sin[c + d*x]])/(16*(a + b)^5*d) - ((8*a^2 + 5*a*b - b^2)*Log[1 + Sin[c + d*x]])/(16*(a - b)^5*d) + (a^3*(a^4 + 13*a^2*b^2 + 10*b^4)*Log[a + b*Sin[c + d*x]])/((a^2 - b^2)^5*d) + 1/(16*(a + b)^3*d*(1 - Sin[c + d*x])^2) - (7*a + b)/(16*(a + b)^4*d*(1 - Sin[c + d*x])) + 1/(16*(a - b)^3*d*(1 + Sin[c + d*x])^2) - (7*a - b)/(16*(a - b)^4*d*(1 + Sin[c + d*x])) - a^5/(2*(a^2 - b^2)^3*d*(a + b*Sin[c + d*x])^2) - (a^4*(a^2 + 5*b^2))/((a^2 - b^2)^4*d*(a + b*Sin[c + d*x]))}
{Tan[c + d*x]^4/(a + b*Sin[c + d*x])^3, x, 16, (8*a^4*b^2*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(9/2)*d) + (12*a^2*b^2*(a^2 + b^2)*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(9/2)*d) + (a^4*(2*a^2 + b^2)*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(9/2)*d) + Cos[c + d*x]/(12*(a + b)^3*d*(1 - Sin[c + d*x])^2) - (3*a*Cos[c + d*x])/(4*(a + b)^4*d*(1 - Sin[c + d*x])) + Cos[c + d*x]/(12*(a + b)^3*d*(1 - Sin[c + d*x])) - Cos[c + d*x]/(12*(a - b)^3*d*(1 + Sin[c + d*x])^2) + (3*a*Cos[c + d*x])/(4*(a - b)^4*d*(1 + Sin[c + d*x])) - Cos[c + d*x]/(12*(a - b)^3*d*(1 + Sin[c + d*x])) + (a^4*b*Cos[c + d*x])/(2*(a^2 - b^2)^3*d*(a + b*Sin[c + d*x])^2) + (3*a^5*b*Cos[c + d*x])/(2*(a^2 - b^2)^4*d*(a + b*Sin[c + d*x])) + (4*a^3*b^3*Cos[c + d*x])/((a^2 - b^2)^4*d*(a + b*Sin[c + d*x]))}
{Tan[c + d*x]^3/(a + b*Sin[c + d*x])^3, x, 3, ((2*a - b)*Log[1 - Sin[c + d*x]])/(4*(a + b)^4*d) + ((2*a + b)*Log[1 + Sin[c + d*x]])/(4*(a - b)^4*d) - (a*(a^4 + 8*a^2*b^2 + 3*b^4)*Log[a + b*Sin[c + d*x]])/((a^2 - b^2)^4*d) + 1/(4*(a + b)^3*d*(1 - Sin[c + d*x])) + 1/(4*(a - b)^3*d*(1 + Sin[c + d*x])) + a^3/(2*(a^2 - b^2)^2*d*(a + b*Sin[c + d*x])^2) + (a^2*(a^2 + 3*b^2))/((a^2 - b^2)^3*d*(a + b*Sin[c + d*x]))}
{Tan[c + d*x]^2/(a + b*Sin[c + d*x])^3, x, 12, -((4*a^2*b^2*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(7/2)*d)) - (a^2*(2*a^2 + b^2)*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(7/2)*d) - (2*b^2*(3*a^2 + b^2)*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(7/2)*d) + Cos[c + d*x]/(2*(a + b)^3*d*(1 - Sin[c + d*x])) - Cos[c + d*x]/(2*(a - b)^3*d*(1 + Sin[c + d*x])) - (a^2*b*Cos[c + d*x])/(2*(a^2 - b^2)^2*d*(a + b*Sin[c + d*x])^2) - (3*a^3*b*Cos[c + d*x])/(2*(a^2 - b^2)^3*d*(a + b*Sin[c + d*x])) - (2*a*b^3*Cos[c + d*x])/((a^2 - b^2)^3*d*(a + b*Sin[c + d*x]))}
{Tan[c + d*x]^1/(a + b*Sin[c + d*x])^3, x, 8, -Log[1 - Sin[c + d*x]]/(2*(a + b)^3*d) - Log[1 + Sin[c + d*x]]/(2*(a - b)^3*d) + (a*(a^2 + 3*b^2)*Log[a + b*Sin[c + d*x]])/((a^2 - b^2)^3*d) - a/(2*(a^2 - b^2)*d*(a + b*Sin[c + d*x])^2) - (a^2 + b^2)/((a^2 - b^2)^2*d*(a + b*Sin[c + d*x]))}
{Tan[c + d*x]^0/(a + b*Sin[c + d*x])^3, x, 4, ((2*a^2 + b^2)*ArcTan[(b + a*Tan[(c + d*x)/2])/Sqrt[a^2 - b^2]])/((a^2 - b^2)^(5/2)*d) + (b*Cos[c + d*x])/(2*(a^2 - b^2)*d*(a + b*Sin[c + d*x])^2) + (3*a*b*Cos[c + d*x])/(2*(a^2 - b^2)^2*d*(a + b*Sin[c + d*x]))}
{Cot[c + d*x]^1/(a + b*Sin[c + d*x])^3, x, 3, Log[Sin[c + d*x]]/(a^3*d) - Log[a + b*Sin[c + d*x]]/(a^3*d) + 1/(2*a*d*(a + b*Sin[c + d*x])^2) + 1/(a^2*d*(a + b*Sin[c + d*x]))}
{Cot[c + d*x]^2/(a + b*Sin[c + d*x])^3, x, 12, (4*b^2*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/(a^2*(a^2 - b^2)^(3/2)*d) + (6*b^2*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/(a^4*Sqrt[a^2 - b^2]*d) - ((2*a^2 + b^2)*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/(a^2*(a^2 - b^2)^(3/2)*d) + (3*b*ArcTanh[Cos[c + d*x]])/(a^4*d) - Cot[c + d*x]/(a^3*d) - (b*Cos[c + d*x])/(2*a^2*d*(a + b*Sin[c + d*x])^2) - (3*b*Cos[c + d*x])/(2*a*(a^2 - b^2)*d*(a + b*Sin[c + d*x])) + (2*b^3*Cos[c + d*x])/(a^3*(a^2 - b^2)*d*(a + b*Sin[c + d*x]))}
{Cot[c + d*x]^3/(a + b*Sin[c + d*x])^3, x, 3, (3*b*Csc[c + d*x])/(a^4*d) - Csc[c + d*x]^2/(2*a^3*d) - ((a^2 - 6*b^2)*Log[Sin[c + d*x]])/(a^5*d) + ((a^2 - 6*b^2)*Log[a + b*Sin[c + d*x]])/(a^5*d) - (a^2 - b^2)/(2*a^3*d*(a + b*Sin[c + d*x])^2) - (a^2 - 3*b^2)/(a^4*d*(a + b*Sin[c + d*x]))}
{Cot[c + d*x]^4/(a + b*Sin[c + d*x])^3, x, 16, -((8*b^2*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/(a^4*Sqrt[a^2 - b^2]*d)) - (4*b^2*(3*a^2 - 5*b^2)*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/(a^6*Sqrt[a^2 - b^2]*d) + ((2*a^2 + b^2)*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/(a^4*Sqrt[a^2 - b^2]*d) + (3*b*ArcTanh[Cos[c + d*x]])/(2*a^4*d) - (2*b*(3*a^2 - 5*b^2)*ArcTanh[Cos[c + d*x]])/(a^6*d) - (2*Cot[c + d*x])/(3*a^3*d) + (2*(a^2 - 3*b^2)*Cot[c + d*x])/(a^5*d) + (3*b*Cot[c + d*x]*Csc[c + d*x])/(2*a^4*d) - (Cot[c + d*x]*Csc[c + d*x]^2)/(3*a^3*d) + (b*(a^2 - b^2)*Cos[c + d*x])/(2*a^4*d*(a + b*Sin[c + d*x])^2) + (3*b*Cos[c + d*x])/(2*a^3*d*(a + b*Sin[c + d*x])) - (4*b^3*Cos[c + d*x])/(a^5*d*(a + b*Sin[c + d*x]))}
{Cot[c + d*x]^5/(a + b*Sin[c + d*x])^3, x, 3, (-2*b*(3*a^2 - 5*b^2)*Csc[c + d*x])/(a^6*d) + ((a^2 - 3*b^2)*Csc[c + d*x]^2)/(a^5*d) + (b*Csc[c + d*x]^3)/(a^4*d) - Csc[c + d*x]^4/(4*a^3*d) + ((a^4 - 12*a^2*b^2 + 15*b^4)*Log[Sin[c + d*x]])/(a^7*d) - ((a^4 - 12*a^2*b^2 + 15*b^4)*Log[a + b*Sin[c + d*x]])/(a^7*d) + (a^2 - b^2)^2/(2*a^5*d*(a + b*Sin[c + d*x])^2) + (a^4 - 6*a^2*b^2 + 5*b^4)/(a^6*d*(a + b*Sin[c + d*x]))}
{Cot[c + d*x]^6/(a + b*Sin[c + d*x])^3, x, 22, (12*b^2*Sqrt[a^2 - b^2]*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/(a^6*d) - (Sqrt[a^2 - b^2]*(2*a^2 + b^2)*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/(a^6*d) + (6*b^2*(3*a^4 - 10*a^2*b^2 + 7*b^4)*ArcTan[(b + a*Tan[(1/2)*(c + d*x)])/Sqrt[a^2 - b^2]])/(a^8*Sqrt[a^2 - b^2]*d) + (9*b*ArcTanh[Cos[c + d*x]])/(8*a^4*d) - (b*(9*a^2 - 10*b^2)*ArcTanh[Cos[c + d*x]])/(2*a^6*d) + (3*b*(3*a^4 - 10*a^2*b^2 + 7*b^4)*ArcTanh[Cos[c + d*x]])/(a^8*d) - (4*Cot[c + d*x])/(5*a^3*d) + (2*(a^2 - 2*b^2)*Cot[c + d*x])/(a^5*d) - (3*(a^4 - 6*a^2*b^2 + 5*b^4)*Cot[c + d*x])/(a^7*d) - (4*Cot[c + d*x]^3)/(15*a^3*d) + (9*b*Cot[c + d*x]*Csc[c + d*x])/(8*a^4*d) - (b*(9*a^2 - 10*b^2)*Cot[c + d*x]*Csc[c + d*x])/(2*a^6*d) + ((a^2 - 2*b^2)*Cot[c + d*x]*Csc[c + d*x]^2)/(a^5*d) + (3*b*Cot[c + d*x]*Csc[c + d*x]^3)/(4*a^4*d) - (Cot[c + d*x]*Csc[c + d*x]^4)/(5*a^3*d) - (b*(a^2 - b^2)^2*Cos[c + d*x])/(2*a^6*d*(a + b*Sin[c + d*x])^2) - (3*b*(a^2 - b^2)*Cos[c + d*x])/(2*a^5*d*(a + b*Sin[c + d*x])) + (6*b^3*(a^2 - b^2)*Cos[c + d*x])/(a^7*d*(a + b*Sin[c + d*x]))}


(* ::Subsection:: *)
(*Integrands of the form Tan[c+d x]^m (a+b Sin[c+d x])^(n/2)*)
