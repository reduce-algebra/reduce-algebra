(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Hyperbolic Sines*)


(* ::Section::Closed:: *)
(*Integrands of the form Sinh[a+b x]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sinh[a+b x]^n*)


{Sinh[a + b*x], x, 1, Cosh[a + b*x]/b}
{Sinh[a + b*x]^2, x, 1, -(x/2) + (Cosh[a + b*x]*Sinh[a + b*x])/(2*b)}
{Sinh[a + b*x]^3, x, 2, -(Cosh[a + b*x]/b) + Cosh[a + b*x]^3/(3*b)}
{Sinh[a + b*x]^4, x, 2, (3*x)/8 - (3*Cosh[a + b*x]*Sinh[a + b*x])/(8*b) + (Cosh[a + b*x]*Sinh[a + b*x]^3)/(4*b)}
{Sinh[a + b*x]^5, x, 2, Cosh[a + b*x]/b - (2*Cosh[a + b*x]^3)/(3*b) + Cosh[a + b*x]^5/(5*b)}
{Sinh[a + b*x]^6, x, 3, -((5*x)/16) + (5*Cosh[a + b*x]*Sinh[a + b*x])/(16*b) - (5*Cosh[a + b*x]*Sinh[a + b*x]^3)/(24*b) + (Cosh[a + b*x]*Sinh[a + b*x]^5)/(6*b)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Sinh[a+b x]^(n/2)*)


{Sinh[a + b*x]^(7/2), x, 4, (10*I*EllipticF[Pi/4 - (1/2)*I*(a + b*x), 2]*Sqrt[I*Sinh[a + b*x]])/(21*b*Sqrt[Sinh[a + b*x]]) - (10*Cosh[a + b*x]*Sqrt[Sinh[a + b*x]])/(21*b) + (2*Cosh[a + b*x]*Sinh[a + b*x]^(5/2))/(7*b)}
{Sinh[a + b*x]^(5/2), x, 3, -((6*I*EllipticE[Pi/4 - (1/2)*I*(a + b*x), 2]*Sqrt[Sinh[a + b*x]])/(5*b*Sqrt[I*Sinh[a + b*x]])) + (2*Cosh[a + b*x]*Sinh[a + b*x]^(3/2))/(5*b)}
{Sinh[a + b*x]^(3/2), x, 3, -((2*I*EllipticF[Pi/4 - (1/2)*I*(a + b*x), 2]*Sqrt[I*Sinh[a + b*x]])/(3*b*Sqrt[Sinh[a + b*x]])) + (2*Cosh[a + b*x]*Sqrt[Sinh[a + b*x]])/(3*b)}
{Sinh[a + b*x]^(1/2), x, 2, (2*I*EllipticE[Pi/4 - (1/2)*I*(a + b*x), 2]*Sqrt[Sinh[a + b*x]])/(b*Sqrt[I*Sinh[a + b*x]])}
{1/Sinh[a + b*x]^(1/2), x, 2, (2*I*EllipticF[Pi/4 - (1/2)*I*(a + b*x), 2]*Sqrt[I*Sinh[a + b*x]])/(b*Sqrt[Sinh[a + b*x]])}
{1/Sinh[a + b*x]^(3/2), x, 3, -((2*Cosh[a + b*x])/(b*Sqrt[Sinh[a + b*x]])) + (2*I*EllipticE[Pi/4 - (1/2)*I*(a + b*x), 2]*Sqrt[Sinh[a + b*x]])/(b*Sqrt[I*Sinh[a + b*x]])}
{1/Sinh[a + b*x]^(5/2), x, 3, -((2*Cosh[a + b*x])/(3*b*Sinh[a + b*x]^(3/2))) - (2*I*EllipticF[Pi/4 - (1/2)*I*(a + b*x), 2]*Sqrt[I*Sinh[a + b*x]])/(3*b*Sqrt[Sinh[a + b*x]])}
{1/Sinh[a + b*x]^(7/2), x, 4, -((2*Cosh[a + b*x])/(5*b*Sinh[a + b*x]^(5/2))) + (6*Cosh[a + b*x])/(5*b*Sqrt[Sinh[a + b*x]]) - (6*I*EllipticE[Pi/4 - (1/2)*I*(a + b*x), 2]*Sqrt[Sinh[a + b*x]])/(5*b*Sqrt[I*Sinh[a + b*x]])}


(* ::Section::Closed:: *)
(*Integrands of the form (c Sinh[a+b x]^m)^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Sinh[a+b x])^n*)


(* ::Subsubsection::Closed:: *)
(*n/2*)


{(b*Sinh[c + d*x])^(7/2), x, 4, (10*I*b^4*EllipticF[Pi/4 - (1/2)*I*(c + d*x), 2]*Sqrt[I*Sinh[c + d*x]])/(21*d*Sqrt[b*Sinh[c + d*x]]) - (10*b^3*Cosh[c + d*x]*Sqrt[b*Sinh[c + d*x]])/(21*d) + (2*b*Cosh[c + d*x]*(b*Sinh[c + d*x])^(5/2))/(7*d)}
{(b*Sinh[c + d*x])^(5/2), x, 3, -((6*I*b^2*EllipticE[Pi/4 - (1/2)*I*(c + d*x), 2]*Sqrt[b*Sinh[c + d*x]])/(5*d*Sqrt[I*Sinh[c + d*x]])) + (2*b*Cosh[c + d*x]*(b*Sinh[c + d*x])^(3/2))/(5*d)}
{(b*Sinh[c + d*x])^(3/2),x, 3, -((2*I*b^2*EllipticF[Pi/4 - (1/2)*I*(c + d*x), 2]*Sqrt[I*Sinh[c + d*x]])/(3*d*Sqrt[b*Sinh[c + d*x]])) + (2*b*Cosh[c + d*x]*Sqrt[b*Sinh[c + d*x]])/(3*d)}
{(b*Sinh[c + d*x])^(1/2), x, 2, (2*I*EllipticE[Pi/4 - (1/2)*I*(c + d*x), 2]*Sqrt[b*Sinh[c + d*x]])/(d*Sqrt[I*Sinh[c + d*x]])}
{1/(b*Sinh[c + d*x])^(1/2), x, 2, (2*I*EllipticF[Pi/4 - (1/2)*I*(c + d*x), 2]*Sqrt[I*Sinh[c + d*x]])/(d*Sqrt[b*Sinh[c + d*x]])}
{1/(b*Sinh[c + d*x])^(3/2), x, 3, -((2*Cosh[c + d*x])/(b*d*Sqrt[b*Sinh[c + d*x]])) + (2*I*EllipticE[Pi/4 - (1/2)*I*(c + d*x), 2]*Sqrt[b*Sinh[c + d*x]])/(b^2*d*Sqrt[I*Sinh[c + d*x]])}
{1/(b*Sinh[c + d*x])^(5/2), x, 3, -((2*Cosh[c + d*x])/(3*b*d*(b*Sinh[c + d*x])^(3/2))) - (2*I*EllipticF[Pi/4 - (1/2)*I*(c + d*x), 2]*Sqrt[I*Sinh[c + d*x]])/(3*b^2*d*Sqrt[b*Sinh[c + d*x]])}
{1/(b*Sinh[c + d*x])^(7/2), x, 4, -((2*Cosh[c + d*x])/(5*b*d*(b*Sinh[c + d*x])^(5/2))) + (6*Cosh[c + d*x])/(5*b^3*d*Sqrt[b*Sinh[c + d*x]]) - (6*I*EllipticE[Pi/4 - (1/2)*I*(c + d*x), 2]*Sqrt[b*Sinh[c + d*x]])/(5*b^4*d*Sqrt[I*Sinh[c + d*x]])}


{(I*Sinh[c + d*x])^(7/2), x, 3, (10*I*EllipticF[Pi/4 - (1/2)*I*(c + d*x), 2])/(21*d) + (10*I*Cosh[c + d*x]*Sqrt[I*Sinh[c + d*x]])/(21*d) + (2*I*Cosh[c + d*x]*(I*Sinh[c + d*x])^(5/2))/(7*d)}
{(I*Sinh[c + d*x])^(5/2), x, 2, (6*I*EllipticE[Pi/4 - (1/2)*I*(c + d*x), 2])/(5*d) + (2*I*Cosh[c + d*x]*(I*Sinh[c + d*x])^(3/2))/(5*d)}
{(I*Sinh[c + d*x])^(3/2),x, 2, (2*I*EllipticF[Pi/4 - (1/2)*I*(c + d*x), 2])/(3*d) + (2*I*Cosh[c + d*x]*Sqrt[I*Sinh[c + d*x]])/(3*d)}
{(I*Sinh[c + d*x])^(1/2), x, 1, (2*I*EllipticE[Pi/4 - (1/2)*I*(c + d*x), 2])/d}
{1/(I*Sinh[c + d*x])^(1/2), x, 1, (2*I*EllipticF[Pi/4 - (1/2)*I*(c + d*x), 2])/d}
{1/(I*Sinh[c + d*x])^(3/2), x, 2, -((2*I*EllipticE[Pi/4 - (1/2)*I*(c + d*x), 2])/d) + (2*I*Cosh[c + d*x])/(d*Sqrt[I*Sinh[c + d*x]])}
{1/(I*Sinh[c + d*x])^(5/2), x, 2, (2*I*EllipticF[Pi/4 - (1/2)*I*(c + d*x), 2])/(3*d) + (2*I*Cosh[c + d*x])/(3*d*(I*Sinh[c + d*x])^(3/2))}
{1/(I*Sinh[c + d*x])^(7/2), x, 3, -((6*I*EllipticE[Pi/4 - (1/2)*I*(c + d*x), 2])/(5*d)) + (2*I*Cosh[c + d*x])/(5*d*(I*Sinh[c + d*x])^(5/2)) + (6*I*Cosh[c + d*x])/(5*d*Sqrt[I*Sinh[c + d*x]])}


(* ::Subsubsection::Closed:: *)
(*n/3*)


{(b*Sinh[c + d*x])^(5/3),x, 3, (3*b*Cosh[c + d*x]*(b*Sinh[c + d*x])^(2/3))/(5*d) + (2*b*Cosh[c + d*x]*Hypergeometric2F1[1/2, 2/3, 3/2, Cosh[c + d*x]^2]*(b*Sinh[c + d*x])^(2/3))/(5*d*(-Sinh[c + d*x]^2)^(1/3))}
{(b*Sinh[c + d*x])^(4/3),x, 3, (3*b*Cosh[c + d*x]*(b*Sinh[c + d*x])^(1/3))/(4*d) + (b*Cosh[c + d*x]*Hypergeometric2F1[1/2, 5/6, 3/2, Cosh[c + d*x]^2]*(b*Sinh[c + d*x])^(1/3))/(4*d*(-Sinh[c + d*x]^2)^(1/6))}
{(b*Sinh[c + d*x])^(2/3),x, 2, (b*Cosh[c + d*x]*Hypergeometric2F1[1/6, 1/2, 3/2, Cosh[c + d*x]^2]*(-Sinh[c + d*x]^2)^(1/6))/(d*(b*Sinh[c + d*x])^(1/3))}
{(b*Sinh[c + d*x])^(1/3),x, 2, (b*Cosh[c + d*x]*Hypergeometric2F1[1/3, 1/2, 3/2, Cosh[c + d*x]^2]*(-Sinh[c + d*x]^2)^(1/3))/(d*(b*Sinh[c + d*x])^(2/3))}
{1/(b*Sinh[c + d*x])^(1/3),x, 2, -((Cosh[c + d*x]*Hypergeometric2F1[1/2, 2/3, 3/2, Cosh[c + d*x]^2]*(b*Sinh[c + d*x])^(2/3))/(b*d*(-Sinh[c + d*x]^2)^(1/3)))}
{1/(b*Sinh[c + d*x])^(2/3),x, 2, -((Cosh[c + d*x]*Hypergeometric2F1[1/2, 5/6, 3/2, Cosh[c + d*x]^2]*(b*Sinh[c + d*x])^(1/3))/(b*d*(-Sinh[c + d*x]^2)^(1/6)))}
{1/(b*Sinh[c + d*x])^(4/3),x, 3, -((3*Cosh[c + d*x])/(b*d*(b*Sinh[c + d*x])^(1/3))) + (2*Cosh[c + d*x]*Hypergeometric2F1[1/6, 1/2, 3/2, Cosh[c + d*x]^2]*(-Sinh[c + d*x]^2)^(1/6))/(b*d*(b*Sinh[c + d*x])^(1/3))}
{1/(b*Sinh[c + d*x])^(5/3),x, 3, -((3*Cosh[c + d*x])/(2*b*d*(b*Sinh[c + d*x])^(2/3))) + (Cosh[c + d*x]*Hypergeometric2F1[1/3, 1/2, 3/2, Cosh[c + d*x]^2]*(-Sinh[c + d*x]^2)^(1/3))/(2*b*d*(b*Sinh[c + d*x])^(2/3))}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{(b*Sinh[c + d*x])^n, x, 2, -((Cosh[c + d*x]*Hypergeometric2F1[1/2, (1 - n)/2, 3/2, Cosh[c + d*x]^2]*(b*Sinh[c + d*x])^(1 + n)*(-Sinh[c + d*x]^2)^((1/2)*(-1 - n)))/(b*d))}


{(I*Sinh[c + d*x])^n, x, 1, (I*Cosh[c + d*x]*Hypergeometric2F1[1/2, (1 - n)/2, 3/2, Cosh[c + d*x]^2]*(I*Sinh[c + d*x])^(1 + n)*(-Sinh[c + d*x]^2)^((1/2)*(-1 - n)))/d}
{(-I*Sinh[c + d*x])^n, x, 2, -((I*Cosh[c + d*x]*Hypergeometric2F1[1/2, (1 - n)/2, 3/2, Cosh[c + d*x]^2]*((-I)*Sinh[c + d*x])^(1 + n)*(-Sinh[c + d*x]^2)^((1/2)*(-1 - n)))/d)}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Sinh[a+b x]^2)^n*)


{(a*Sinh[x]^2)^(5/2),x, 4, (8/15)*a^2*Coth[x]*Sqrt[a*Sinh[x]^2] - (4/15)*a*Coth[x]*(a*Sinh[x]^2)^(3/2) + (1/5)*Coth[x]*(a*Sinh[x]^2)^(5/2)}
{(a*Sinh[x]^2)^(3/2),x, 3, (-(2/3))*a*Coth[x]*Sqrt[a*Sinh[x]^2] + (1/3)*Coth[x]*(a*Sinh[x]^2)^(3/2)}
{(a*Sinh[x]^2)^(1/2), x, 2, Coth[x]*Sqrt[a*Sinh[x]^2]}
{1/(a*Sinh[x]^2)^(1/2), x, 2, -((ArcTanh[Cosh[x]]*Sinh[x])/Sqrt[a*Sinh[x]^2])}
{1/(a*Sinh[x]^2)^(3/2), x, 3, -(Coth[x]/(2*a*Sqrt[a*Sinh[x]^2])) + (ArcTanh[Cosh[x]]*Sinh[x])/(2*a*Sqrt[a*Sinh[x]^2])}
{1/(a*Sinh[x]^2)^(5/2), x, 4, -(Coth[x]/(4*a*(a*Sinh[x]^2)^(3/2))) + (3*Coth[x])/(8*a^2*Sqrt[a*Sinh[x]^2]) - (3*ArcTanh[Cosh[x]]*Sinh[x])/(8*a^2*Sqrt[a*Sinh[x]^2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Sinh[a+b x]^3)^n*)


{(a*Sinh[x]^3)^(5/2),x, 7, (-(26/77))*a^2*Coth[x]*Sqrt[a*Sinh[x]^3] + (26/77)*I*a^2*Csch[x]^2*EllipticF[Pi/4 - (I*x)/2, 2]*Sqrt[I*Sinh[x]]*Sqrt[a*Sinh[x]^3] + (78/385)*a^2*Cosh[x]*Sinh[x]*Sqrt[a*Sinh[x]^3] - (26/165)*a^2*Cosh[x]*Sinh[x]^3*Sqrt[a*Sinh[x]^3] + (2/15)*a^2*Cosh[x]*Sinh[x]^5*Sqrt[a*Sinh[x]^3]}
{(a*Sinh[x]^3)^(3/2),x, 5, (-(14/45))*a*Cosh[x]*Sqrt[a*Sinh[x]^3] + (14*I*a*Csch[x]*EllipticE[Pi/4 - (I*x)/2, 2]*Sqrt[a*Sinh[x]^3])/(15*Sqrt[I*Sinh[x]]) + (2/9)*a*Cosh[x]*Sinh[x]^2*Sqrt[a*Sinh[x]^3]}
{(a*Sinh[x]^3)^(1/2), x, 4, (2/3)*Coth[x]*Sqrt[a*Sinh[x]^3] + (2*I*EllipticF[Pi/4 - (I*x)/2, 2]*Sqrt[a*Sinh[x]^3])/(3*(I*Sinh[x])^(3/2)), (2/3)*Coth[x]*Sqrt[a*Sinh[x]^3] - (2/3)*I*Csch[x]^2*EllipticF[Pi/4 - (I*x)/2, 2]*Sqrt[I*Sinh[x]]*Sqrt[a*Sinh[x]^3]}
{1/(a*Sinh[x]^3)^(1/2), x, 4, -((2*I*EllipticE[Pi/4 - (I*x)/2, 2]*(I*Sinh[x])^(3/2))/Sqrt[a*Sinh[x]^3]) - (2*Cosh[x]*Sinh[x])/Sqrt[a*Sinh[x]^3], -((2*Cosh[x]*Sinh[x])/Sqrt[a*Sinh[x]^3]) + (2*I*EllipticE[Pi/4 - (I*x)/2, 2]*Sinh[x]^2)/(Sqrt[I*Sinh[x]]*Sqrt[a*Sinh[x]^3])}
{1/(a*Sinh[x]^3)^(3/2),x, 5, (10*Cosh[x])/(21*a*Sqrt[a*Sinh[x]^3]) - (2*Coth[x]*Csch[x])/(7*a*Sqrt[a*Sinh[x]^3]) + (10*I*EllipticF[Pi/4 - (I*x)/2, 2]*Sqrt[I*Sinh[x]]*Sinh[x])/(21*a*Sqrt[a*Sinh[x]^3])}
{1/(a*Sinh[x]^3)^(5/2),x, 7, -((154*Coth[x])/(585*a^2*Sqrt[a*Sinh[x]^3])) + (22*Coth[x]*Csch[x]^2)/(117*a^2*Sqrt[a*Sinh[x]^3]) - (2*Coth[x]*Csch[x]^4)/(13*a^2*Sqrt[a*Sinh[x]^3]) + (154*Cosh[x]*Sinh[x])/(195*a^2*Sqrt[a*Sinh[x]^3]) - (154*I*EllipticE[Pi/4 - (I*x)/2, 2]*Sinh[x]^2)/(195*a^2*Sqrt[I*Sinh[x]]*Sqrt[a*Sinh[x]^3])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Sinh[a+b x]^4)^n*)


{(a*Sinh[x]^4)^(5/2),x, 6, (63/256)*a^2*Coth[x]*Sqrt[a*Sinh[x]^4] - (63/256)*a^2*x*Csch[x]^2*Sqrt[a*Sinh[x]^4] - (21/128)*a^2*Cosh[x]*Sinh[x]*Sqrt[a*Sinh[x]^4] + (21/160)*a^2*Cosh[x]*Sinh[x]^3*Sqrt[a*Sinh[x]^4] - (9/80)*a^2*Cosh[x]*Sinh[x]^5*Sqrt[a*Sinh[x]^4] + (1/10)*a^2*Cosh[x]*Sinh[x]^7*Sqrt[a*Sinh[x]^4]}
{(a*Sinh[x]^4)^(3/2),x, 4, (5/16)*a*Coth[x]*Sqrt[a*Sinh[x]^4] - (5/16)*a*x*Csch[x]^2*Sqrt[a*Sinh[x]^4] - (5/24)*a*Cosh[x]*Sinh[x]*Sqrt[a*Sinh[x]^4] + (1/6)*a*Cosh[x]*Sinh[x]^3*Sqrt[a*Sinh[x]^4]}
{(a*Sinh[x]^4)^(1/2), x, 2, (1/2)*Coth[x]*Sqrt[a*Sinh[x]^4] - (1/2)*x*Csch[x]^2*Sqrt[a*Sinh[x]^4]}
{1/(a*Sinh[x]^4)^(1/2), x, 2, -((Cosh[x]*Sinh[x])/Sqrt[a*Sinh[x]^4])}
{1/(a*Sinh[x]^4)^(3/2),x, 3, (2*Cosh[x]^2*Coth[x])/(3*a*Sqrt[a*Sinh[x]^4]) - (Cosh[x]^2*Coth[x]^3)/(5*a*Sqrt[a*Sinh[x]^4]) - (Cosh[x]*Sinh[x])/(a*Sqrt[a*Sinh[x]^4])}
{1/(a*Sinh[x]^4)^(5/2),x, 3, (4*Cosh[x]^2*Coth[x])/(3*a^2*Sqrt[a*Sinh[x]^4]) - (6*Cosh[x]^2*Coth[x]^3)/(5*a^2*Sqrt[a*Sinh[x]^4]) + (4*Cosh[x]^2*Coth[x]^5)/(7*a^2*Sqrt[a*Sinh[x]^4]) - (Cosh[x]^2*Coth[x]^7)/(9*a^2*Sqrt[a*Sinh[x]^4]) - (Cosh[x]*Sinh[x])/(a^2*Sqrt[a*Sinh[x]^4])}


(* ::Subsection:: *)
(*Integrands of the form (c Sinh[a+b x]^m)^n*)


(* ::Section::Closed:: *)
(*Integrands of the form Hyper[c+d x]^m (a+b Sinh[c+d x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sinh[c+d x]^m (a+b Sinh[c+d x])^n*)


(* ::Subsubsection::Closed:: *)
(*a^2+b^2=0*)


{Sinh[x]^4/(I + Sinh[x]), x, 4, (3*I*x)/2 - 4*Cosh[x] + (4*Cosh[x]^3)/3 - (3/2)*I*Cosh[x]*Sinh[x] - (Cosh[x]*Sinh[x]^3)/(I + Sinh[x])}
{Sinh[x]^3/(I + Sinh[x]), x, 3, -((3*x)/2) - 2*I*Cosh[x] + (3/2)*Cosh[x]*Sinh[x] - (Cosh[x]*Sinh[x]^2)/(I + Sinh[x])}
{Sinh[x]^2/(I + Sinh[x]), x, 3, (-I)*x + Cosh[x] + (I*Cosh[x])/(I + Sinh[x])}
{Sinh[x]^1/(I + Sinh[x]), x, 2, x - Cosh[x]/(I + Sinh[x])}
{Csch[x]^1/(I + Sinh[x]), x, 3, I*ArcTanh[Cosh[x]] + Cosh[x]/(I + Sinh[x])}
{Csch[x]^2/(I + Sinh[x]), x, 3, -ArcTanh[Cosh[x]] + 2*I*Coth[x] + Coth[x]/(I + Sinh[x])}
{Csch[x]^3/(I + Sinh[x]), x, 4, (-(3/2))*I*ArcTanh[Cosh[x]] - 2*Coth[x] + (3/2)*I*Coth[x]*Csch[x] + (Coth[x]*Csch[x])/(I + Sinh[x])}
{Csch[x]^4/(I + Sinh[x]), x, 5, (3/2)*ArcTanh[Cosh[x]] - 4*I*Coth[x] + (4/3)*I*Coth[x]^3 - (3/2)*Coth[x]*Csch[x] + (Coth[x]*Csch[x]^2)/(I + Sinh[x])}


{Sinh[x]^4/(I + Sinh[x])^2, x, 5, -((7*x)/2) - (16/3)*I*Cosh[x] + (7/2)*Cosh[x]*Sinh[x] - (Cosh[x]*Sinh[x]^3)/(3*(I + Sinh[x])^2) - (8*Cosh[x]*Sinh[x]^2)/(3*(I + Sinh[x]))}
{Sinh[x]^3/(I + Sinh[x])^2, x, 4, -2*I*x + (4*Cosh[x])/3 - (Cosh[x]*Sinh[x]^2)/(3*(I + Sinh[x])^2) + (2*I*Cosh[x])/(I + Sinh[x])}
{Sinh[x]^2/(I + Sinh[x])^2, x, 3, x + (I*Cosh[x])/(3*(I + Sinh[x])^2) - (5*Cosh[x])/(3*(I + Sinh[x]))}
{Sinh[x]^1/(I + Sinh[x])^2, x, 2, -(Cosh[x]/(3*(I + Sinh[x])^2)) - (2*I*Cosh[x])/(3*(I + Sinh[x]))}
{Csch[x]^1/(I + Sinh[x])^2, x, 3, ArcTanh[Cosh[x]] + Cosh[x]/(3*(I + Sinh[x])^2) - (4*I*Cosh[x])/(3*(I + Sinh[x]))}
{Csch[x]^2/(I + Sinh[x])^2, x, 5, 2*I*ArcTanh[Cosh[x]] + (10*Coth[x])/3 + Coth[x]/(3*(I + Sinh[x])^2) - (2*I*Coth[x])/(I + Sinh[x])}
{Csch[x]^3/(I + Sinh[x])^2, x, 6, (-(7/2))*ArcTanh[Cosh[x]] + (16/3)*I*Coth[x] + (7/2)*Coth[x]*Csch[x] + (Coth[x]*Csch[x])/(3*(I + Sinh[x])^2) - (8*I*Coth[x]*Csch[x])/(3*(I + Sinh[x]))}
{Csch[x]^4/(I + Sinh[x])^2, x, 7, -5*I*ArcTanh[Cosh[x]] - 12*Coth[x] + 4*Coth[x]^3 + 5*I*Coth[x]*Csch[x] + (Coth[x]*Csch[x]^2)/(3*(I + Sinh[x])^2) - (10*I*Coth[x]*Csch[x]^2)/(3*(I + Sinh[x]))}


{1/(1 + I*Sinh[c + d*x]), x, 1, (I*Cosh[c + d*x])/(d*(1 + I*Sinh[c + d*x]))}
{1/(1 + I*Sinh[c + d*x])^2, x, 2, (I*Cosh[c + d*x])/(3*d*(1 + I*Sinh[c + d*x])^2) + (I*Cosh[c + d*x])/(3*d*(1 + I*Sinh[c + d*x]))}
{1/(1 + I*Sinh[c + d*x])^3, x, 3, (I*Cosh[c + d*x])/(5*d*(1 + I*Sinh[c + d*x])^3) + (2*I*Cosh[c + d*x])/(15*d*(1 + I*Sinh[c + d*x])^2) + (2*I*Cosh[c + d*x])/(15*d*(1 + I*Sinh[c + d*x]))}
{1/(1 + I*Sinh[c + d*x])^4, x, 4, (I*Cosh[c + d*x])/(7*d*(1 + I*Sinh[c + d*x])^4) + (3*I*Cosh[c + d*x])/(35*d*(1 + I*Sinh[c + d*x])^3) + (2*I*Cosh[c + d*x])/(35*d*(1 + I*Sinh[c + d*x])^2) + (2*I*Cosh[c + d*x])/(35*d*(1 + I*Sinh[c + d*x]))}

{1/(1 - I*Sinh[c + d*x]), x, 1, -((I*Cosh[c + d*x])/(d*(1 - I*Sinh[c + d*x])))}
{1/(1 - I*Sinh[c + d*x])^2, x, 2, -((I*Cosh[c + d*x])/(3*d*(1 - I*Sinh[c + d*x])^2)) - (I*Cosh[c + d*x])/(3*d*(1 - I*Sinh[c + d*x]))}
{1/(1 - I*Sinh[c + d*x])^3, x, 3, -((I*Cosh[c + d*x])/(5*d*(1 - I*Sinh[c + d*x])^3)) - (2*I*Cosh[c + d*x])/(15*d*(1 - I*Sinh[c + d*x])^2) - (2*I*Cosh[c + d*x])/(15*d*(1 - I*Sinh[c + d*x]))}
{1/(1 - I*Sinh[c + d*x])^4, x, 4, -((I*Cosh[c + d*x])/(7*d*(1 - I*Sinh[c + d*x])^4)) - (3*I*Cosh[c + d*x])/(35*d*(1 - I*Sinh[c + d*x])^3) - (2*I*Cosh[c + d*x])/(35*d*(1 - I*Sinh[c + d*x])^2) - (2*I*Cosh[c + d*x])/(35*d*(1 - I*Sinh[c + d*x]))}


{Sinh[x]/Sqrt[a + a*I*Sinh[x]], x, 3, -((2*ArcTanh[Sin[Pi/4 - (I*x)/2]]*Cos[Pi/4 - (I*x)/2])/Sqrt[a + I*a*Sinh[x]]) + (2*Cosh[x])/Sqrt[a + I*a*Sinh[x]]}
{Sinh[x]/Sqrt[a - a*I*Sinh[x]], x, 3, -((2*ArcTanh[Sin[Pi/4 + (I*x)/2]]*Cos[Pi/4 + (I*x)/2])/Sqrt[a - I*a*Sinh[x]]) + (2*Cosh[x])/Sqrt[a - I*a*Sinh[x]]}
{Sinh[x]/Sqrt[a + b*Sinh[x]], x, 5, (2*I*EllipticE[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[a + b*Sinh[x]])/(b*Sqrt[(a + b*Sinh[x])/(a - I*b)]) - (2*I*a*EllipticF[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[(a + b*Sinh[x])/(a - I*b)])/(b*Sqrt[a + b*Sinh[x]])}


{(a + a*I*Sinh[c + d*x])^(5/2), x, 3, (64*I*a^3*Cosh[c + d*x])/(15*d*Sqrt[a + I*a*Sinh[c + d*x]]) + (16*I*a^2*Cosh[c + d*x]*Sqrt[a + I*a*Sinh[c + d*x]])/(15*d) + (2*I*a*Cosh[c + d*x]*(a + I*a*Sinh[c + d*x])^(3/2))/(5*d)}
{(a + a*I*Sinh[c + d*x])^(3/2), x, 2, (8*I*a^2*Cosh[c + d*x])/(3*d*Sqrt[a + I*a*Sinh[c + d*x]]) + (2*I*a*Cosh[c + d*x]*Sqrt[a + I*a*Sinh[c + d*x]])/(3*d)}
{(a + a*I*Sinh[c + d*x])^(1/2), x, 1, (2*I*a*Cosh[c + d*x])/(d*Sqrt[a + I*a*Sinh[c + d*x]])}
{1/(a + a*I*Sinh[c + d*x])^(1/2), x, 1, (2*I*ArcTanh[Sin[Pi/4 - (1/2)*I*(c + d*x)]]*Cos[Pi/4 - (1/2)*I*(c + d*x)])/(d*Sqrt[a + I*a*Sinh[c + d*x]])}
{1/(a + a*I*Sinh[c + d*x])^(3/2), x, 2, (I*Cosh[c + d*x])/(2*d*(a + I*a*Sinh[c + d*x])^(3/2)) + (I*ArcTanh[Sin[Pi/4 - (1/2)*I*(c + d*x)]]*Cos[Pi/4 - (1/2)*I*(c + d*x)])/(2*a*d*Sqrt[a + I*a*Sinh[c + d*x]])}
{1/(a + a*I*Sinh[c + d*x])^(5/2), x, 3, (I*Cosh[c + d*x])/(4*d*(a + I*a*Sinh[c + d*x])^(5/2)) + (3*I*Cosh[c + d*x])/(16*a*d*(a + I*a*Sinh[c + d*x])^(3/2)) + (3*I*ArcTanh[Sin[Pi/4 - (1/2)*I*(c + d*x)]]*Cos[Pi/4 - (1/2)*I*(c + d*x)])/(16*a^2*d*Sqrt[a + I*a*Sinh[c + d*x]])}


(* ::Subsubsection::Closed:: *)
(*a^2+b^2!=0*)


{Sinh[x]^4/(a + b*Sinh[x]), x, 5, -((a*(2*a^2 - b^2)*x)/(2*b^4)) - (2*a^4*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(b^4*Sqrt[a^2 + b^2]) + ((3*a^2 - 2*b^2)*Cosh[x])/(3*b^3) - (a*Cosh[x]*Sinh[x])/(2*b^2) + (Cosh[x]*Sinh[x]^2)/(3*b)}
{Sinh[x]^3/(a + b*Sinh[x]), x, 4, ((2*a^2 - b^2)*x)/(2*b^3) + (2*a^3*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(b^3*Sqrt[a^2 + b^2]) - (a*Cosh[x])/b^2 + (Cosh[x]*Sinh[x])/(2*b)}
{Sinh[x]^2/(a + b*Sinh[x]), x, 3, -((a*x)/b^2) - (2*a^2*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(b^2*Sqrt[a^2 + b^2]) + Cosh[x]/b}
{Sinh[x]^1/(a + b*Sinh[x]), x, 2, x/b + (2*a*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(b*Sqrt[a^2 + b^2])}
{Csch[x]^1/(a + b*Sinh[x]), x, 3, -(ArcTanh[Cosh[x]]/a) + (2*b*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a*Sqrt[a^2 + b^2])}
{Csch[x]^2/(a + b*Sinh[x]), x, 5, (b*ArcTanh[Cosh[x]])/a^2 - (2*b^2*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2*Sqrt[a^2 + b^2]) - Coth[x]/a}
{Csch[x]^3/(a + b*Sinh[x]), x, 5, ((a^2 - 2*b^2)*ArcTanh[Cosh[x]])/(2*a^3) + (2*b^3*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^3*Sqrt[a^2 + b^2]) + (b*Coth[x])/a^2 - (Coth[x]*Csch[x])/(2*a)}
{Csch[x]^4/(a + b*Sinh[x]), x, 6, -((b*(a^2 - 2*b^2)*ArcTanh[Cosh[x]])/(2*a^4)) - (2*b^4*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^4*Sqrt[a^2 + b^2]) + ((2*a^2 - 3*b^2)*Coth[x])/(3*a^3) + (b*Coth[x]*Csch[x])/(2*a^2) - (Coth[x]*Csch[x]^2)/(3*a)}


{Sinh[x]^4/(a + b*Sinh[x])^2, x, 5, ((6*a^2 - b^2)*x)/(2*b^4) + (2*a^3*(3*a^2 + 4*b^2)*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(b^4*(a^2 + b^2)^(3/2)) - (a*(3*a^2 + 2*b^2)*Cosh[x])/(b^3*(a^2 + b^2)) + ((3*a^2 + b^2)*Cosh[x]*Sinh[x])/(2*b^2*(a^2 + b^2)) - (a^2*Cosh[x]*Sinh[x]^2)/(b*(a^2 + b^2)*(a + b*Sinh[x]))}
{Sinh[x]^3/(a + b*Sinh[x])^2, x, 4, -((2*a*x)/b^3) - (2*a^2*(2*a^2 + 3*b^2)*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(b^3*(a^2 + b^2)^(3/2)) + ((2*a^2 + b^2)*Cosh[x])/(b^2*(a^2 + b^2)) - (a^2*Cosh[x]*Sinh[x])/(b*(a^2 + b^2)*(a + b*Sinh[x]))}
{Sinh[x]^2/(a + b*Sinh[x])^2, x, 3, x/b^2 + (2*a*(a^2 + 2*b^2)*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(b^2*(a^2 + b^2)^(3/2)) - (a^2*Cosh[x])/(b*(a^2 + b^2)*(a + b*Sinh[x]))}
{Sinh[x]^1/(a + b*Sinh[x])^2, x, 3, -((2*b*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(3/2)) + (a*Cosh[x])/((a^2 + b^2)*(a + b*Sinh[x]))}
{Csch[x]^1/(a + b*Sinh[x])^2, x, 4, -(ArcTanh[Cosh[x]]/a^2) + (2*b*(2*a^2 + b^2)*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2*(a^2 + b^2)^(3/2)) + (b^2*Cosh[x])/(a*(a^2 + b^2)*(a + b*Sinh[x]))}
{Csch[x]^2/(a + b*Sinh[x])^2, x, 5, (2*b*ArcTanh[Cosh[x]])/a^3 - (2*b^2*(3*a^2 + 2*b^2)*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^3*(a^2 + b^2)^(3/2)) - ((a^2 + 2*b^2)*Coth[x])/(a^2*(a^2 + b^2)) + (b^2*Coth[x])/(a*(a^2 + b^2)*(a + b*Sinh[x]))}
{Csch[x]^3/(a + b*Sinh[x])^2, x, 6, ((a^2 - 6*b^2)*ArcTanh[Cosh[x]])/(2*a^4) + (2*b^3*(4*a^2 + 3*b^2)*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^4*(a^2 + b^2)^(3/2)) + (b*(2*a^2 + 3*b^2)*Coth[x])/(a^3*(a^2 + b^2)) - ((a^2 + 3*b^2)*Coth[x]*Csch[x])/(2*a^2*(a^2 + b^2)) + (b^2*Coth[x]*Csch[x])/(a*(a^2 + b^2)*(a + b*Sinh[x]))}
{Csch[x]^4/(a + b*Sinh[x])^2, x, 7, -((b*(a^2 - 4*b^2)*ArcTanh[Cosh[x]])/a^5) - (2*b^4*(5*a^2 + 4*b^2)*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^5*(a^2 + b^2)^(3/2)) + ((2*a^4 - 7*a^2*b^2 - 12*b^4)*Coth[x])/(3*a^4*(a^2 + b^2)) + (b*(a^2 + 2*b^2)*Coth[x]*Csch[x])/(a^3*(a^2 + b^2)) - ((a^2 + 4*b^2)*Coth[x]*Csch[x]^2)/(3*a^2*(a^2 + b^2)) + (b^2*Coth[x]*Csch[x]^2)/(a*(a^2 + b^2)*(a + b*Sinh[x]))}


{1/(3 + 5*I*Sinh[c + d*x]), x, 1, (I*ArcTanh[(1/4)*(5 + 3*I*Tanh[(1/2)*(c + d*x)])])/(2*d)}
{1/(3 + 5*I*Sinh[c + d*x])^2, x, 3, -((3*I*ArcTanh[(1/4)*(5 + 3*I*Tanh[(1/2)*(c + d*x)])])/(32*d)) + (5*I*Cosh[c + d*x])/(16*d*(3 + 5*I*Sinh[c + d*x]))}
{1/(3 + 5*I*Sinh[c + d*x])^3, x, 4, (43*I*ArcTanh[(1/4)*(5 + 3*I*Tanh[(1/2)*(c + d*x)])])/(1024*d) + (5*I*Cosh[c + d*x])/(32*d*(3 + 5*I*Sinh[c + d*x])^2) - (45*I*Cosh[c + d*x])/(512*d*(3 + 5*I*Sinh[c + d*x]))}
{1/(3 + 5*I*Sinh[c + d*x])^4, x, 5, -((279*I*ArcTanh[(1/4)*(5 + 3*I*Tanh[(1/2)*(c + d*x)])])/(16384*d)) + (5*I*Cosh[c + d*x])/(48*d*(3 + 5*I*Sinh[c + d*x])^3) - (25*I*Cosh[c + d*x])/(512*d*(3 + 5*I*Sinh[c + d*x])^2) + (995*I*Cosh[c + d*x])/(24576*d*(3 + 5*I*Sinh[c + d*x]))}

{1/(5 + 3*I*Sinh[c + d*x]), x, 1, x/4 - (I*ArcTan[Cosh[c + d*x]/(3 + I*Sinh[c + d*x])])/(2*d)}
{1/(5 + 3*I*Sinh[c + d*x])^2, x, 3, (5*x)/64 - (5*I*ArcTan[Cosh[c + d*x]/(3 + I*Sinh[c + d*x])])/(32*d) - (3*I*Cosh[c + d*x])/(16*d*(5 + 3*I*Sinh[c + d*x]))}
{1/(5 + 3*I*Sinh[c + d*x])^3, x, 4, (59*x)/2048 - (59*I*ArcTan[Cosh[c + d*x]/(3 + I*Sinh[c + d*x])])/(1024*d) - (3*I*Cosh[c + d*x])/(32*d*(5 + 3*I*Sinh[c + d*x])^2) - (45*I*Cosh[c + d*x])/(512*d*(5 + 3*I*Sinh[c + d*x]))}
{1/(5 + 3*I*Sinh[c + d*x])^4, x, 5, (385*x)/32768 - (385*I*ArcTan[Cosh[c + d*x]/(3 + I*Sinh[c + d*x])])/(16384*d) - (I*Cosh[c + d*x])/(16*d*(5 + 3*I*Sinh[c + d*x])^3) - (25*I*Cosh[c + d*x])/(512*d*(5 + 3*I*Sinh[c + d*x])^2) - (311*I*Cosh[c + d*x])/(8192*d*(5 + 3*I*Sinh[c + d*x]))}


{(a + b*Sinh[c + d*x])^7, x, 7, (1/16)*a*(16*a^6 - 168*a^4*b^2 + 210*a^2*b^4 - 35*b^6)*x + (b*(586*a^6 - 2819*a^4*b^2 + 1536*a^2*b^4 - 64*b^6)*Cosh[c + d*x])/(140*d) + (a*b^2*(892*a^4 - 3144*a^2*b^2 + 969*b^4)*Cosh[c + d*x]*Sinh[c + d*x])/(560*d) + (b*(306*a^4 - 631*a^2*b^2 + 64*b^4)*Cosh[c + d*x]*(a + b*Sinh[c + d*x])^2)/(280*d) + (11*a*b*(58*a^2 - 59*b^2)*Cosh[c + d*x]*(a + b*Sinh[c + d*x])^3)/(840*d) + (b*(107*a^2 - 36*b^2)*Cosh[c + d*x]*(a + b*Sinh[c + d*x])^4)/(210*d) + (13*a*b*Cosh[c + d*x]*(a + b*Sinh[c + d*x])^5)/(42*d) + (b*Cosh[c + d*x]*(a + b*Sinh[c + d*x])^6)/(7*d)}
{(a + b*Sinh[c + d*x])^6, x, 6, (1/16)*(16*a^6 - 120*a^4*b^2 + 90*a^2*b^4 - 5*b^6)*x + (a*b*(78*a^4 - 243*a^2*b^2 + 64*b^4)*Cosh[c + d*x])/(20*d) + (b^2*(116*a^4 - 244*a^2*b^2 + 25*b^4)*Cosh[c + d*x]*Sinh[c + d*x])/(80*d) + (a*b*(38*a^2 - 39*b^2)*Cosh[c + d*x]*(a + b*Sinh[c + d*x])^2)/(40*d) + (b*(74*a^2 - 25*b^2)*Cosh[c + d*x]*(a + b*Sinh[c + d*x])^3)/(120*d) + (11*a*b*Cosh[c + d*x]*(a + b*Sinh[c + d*x])^4)/(30*d) + (b*Cosh[c + d*x]*(a + b*Sinh[c + d*x])^5)/(6*d)}
{(a + b*Sinh[c + d*x])^5, x, 5, (1/8)*a*(8*a^4 - 40*a^2*b^2 + 15*b^4)*x + (b*(107*a^4 - 192*a^2*b^2 + 16*b^4)*Cosh[c + d*x])/(30*d) + (7*a*b^2*(22*a^2 - 23*b^2)*Cosh[c + d*x]*Sinh[c + d*x])/(120*d) + (b*(47*a^2 - 16*b^2)*Cosh[c + d*x]*(a + b*Sinh[c + d*x])^2)/(60*d) + (9*a*b*Cosh[c + d*x]*(a + b*Sinh[c + d*x])^3)/(20*d) + (b*Cosh[c + d*x]*(a + b*Sinh[c + d*x])^4)/(5*d)}
{(a + b*Sinh[c + d*x])^4, x, 4, (1/8)*(8*a^4 - 24*a^2*b^2 + 3*b^4)*x + (a*b*(19*a^2 - 16*b^2)*Cosh[c + d*x])/(6*d) + (b^2*(26*a^2 - 9*b^2)*Cosh[c + d*x]*Sinh[c + d*x])/(24*d) + (7*a*b*Cosh[c + d*x]*(a + b*Sinh[c + d*x])^2)/(12*d) + (b*Cosh[c + d*x]*(a + b*Sinh[c + d*x])^3)/(4*d)}
{(a + b*Sinh[c + d*x])^3, x, 3, (1/2)*a*(2*a^2 - 3*b^2)*x + (2*b*(4*a^2 - b^2)*Cosh[c + d*x])/(3*d) + (5*a*b^2*Cosh[c + d*x]*Sinh[c + d*x])/(6*d) + (b*Cosh[c + d*x]*(a + b*Sinh[c + d*x])^2)/(3*d)}
{(a + b*Sinh[c + d*x])^2, x, 2, (1/2)*(2*a^2 - b^2)*x + (2*a*b*Cosh[c + d*x])/d + (b^2*Cosh[c + d*x]*Sinh[c + d*x])/(2*d)}
{(a + b*Sinh[c + d*x]), x, 2, a*x + (b*Cosh[c + d*x])/d}
{1/(a + b*Sinh[c + d*x]), x, 1, -((2*ArcTanh[(b - a*Tanh[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]])/(Sqrt[a^2 + b^2]*d))}
{1/(a + b*Sinh[c + d*x])^2, x, 3, -((2*a*ArcTanh[(b - a*Tanh[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]])/((a^2 + b^2)^(3/2)*d)) - (b*Cosh[c + d*x])/((a^2 + b^2)*d*(a + b*Sinh[c + d*x]))}
{1/(a + b*Sinh[c + d*x])^3, x, 4, -(((2*a^2 - b^2)*ArcTanh[(b - a*Tanh[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]])/((a^2 + b^2)^(5/2)*d)) - (b*Cosh[c + d*x])/(2*(a^2 + b^2)*d*(a + b*Sinh[c + d*x])^2) - (3*a*b*Cosh[c + d*x])/(2*(a^2 + b^2)^2*d*(a + b*Sinh[c + d*x]))}
{1/(a + b*Sinh[c + d*x])^4, x, 5, -((a*(2*a^2 - 3*b^2)*ArcTanh[(b - a*Tanh[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]])/((a^2 + b^2)^(7/2)*d)) - (b*Cosh[c + d*x])/(3*(a^2 + b^2)*d*(a + b*Sinh[c + d*x])^3) - (5*a*b*Cosh[c + d*x])/(6*(a^2 + b^2)^2*d*(a + b*Sinh[c + d*x])^2) - (b*(11*a^2 - 4*b^2)*Cosh[c + d*x])/(6*(a^2 + b^2)^3*d*(a + b*Sinh[c + d*x]))}


{(a + b*Sinh[x])^(5/2), x, 7, (16/15)*a*b*Cosh[x]*Sqrt[a + b*Sinh[x]] + (2/5)*b*Cosh[x]*(a + b*Sinh[x])^(3/2) + (2*I*(23*a^2 - 9*b^2)*EllipticE[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[a + b*Sinh[x]])/(15*Sqrt[(a + b*Sinh[x])/(a - I*b)]) - (16*I*a*(a^2 + b^2)*EllipticF[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[(a + b*Sinh[x])/(a - I*b)])/(15*Sqrt[a + b*Sinh[x]])}
{(a + b*Sinh[x])^(3/2), x, 6, (2/3)*b*Cosh[x]*Sqrt[a + b*Sinh[x]] + (8*I*a*EllipticE[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[a + b*Sinh[x]])/(3*Sqrt[(a + b*Sinh[x])/(a - I*b)]) - (2*I*(a^2 + b^2)*EllipticF[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[(a + b*Sinh[x])/(a - I*b)])/(3*Sqrt[a + b*Sinh[x]])}
{(a + b*Sinh[x])^(1/2), x, 2, (2*I*EllipticE[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[a + b*Sinh[x]])/Sqrt[(a + b*Sinh[x])/(a - I*b)]}
{1/(a + b*Sinh[x])^(1/2), x, 2, (2*I*EllipticF[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[(a + b*Sinh[x])/(a - I*b)])/Sqrt[a + b*Sinh[x]]}
{1/(a + b*Sinh[x])^(3/2), x, 4, -((2*b*Cosh[x])/((a^2 + b^2)*Sqrt[a + b*Sinh[x]])) + (2*I*EllipticE[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[a + b*Sinh[x]])/((a^2 + b^2)*Sqrt[(a + b*Sinh[x])/(a - I*b)])}
{1/(a + b*Sinh[x])^(5/2), x, 7, -((2*b*Cosh[x])/(3*(a^2 + b^2)*(a + b*Sinh[x])^(3/2))) - (8*a*b*Cosh[x])/(3*(a^2 + b^2)^2*Sqrt[a + b*Sinh[x]]) + (8*I*a*EllipticE[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[a + b*Sinh[x]])/(3*(a^2 + b^2)^2*Sqrt[(a + b*Sinh[x])/(a - I*b)]) - (2*I*EllipticF[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[(a + b*Sinh[x])/(a - I*b)])/(3*(a^2 + b^2)*Sqrt[a + b*Sinh[x]])}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cosh[c+d x]^m (a+b Sinh[c+d x])^n*)


(* ::Subsubsection::Closed:: *)
(*a^2+b^2=0*)


{Cosh[x]^8/(I + Sinh[x]), x, 4, -((5*I*x)/16) + Cosh[x]^7/7 - (5/16)*I*Cosh[x]*Sinh[x] - (5/24)*I*Cosh[x]^3*Sinh[x] - (1/6)*I*Cosh[x]^5*Sinh[x]}
{Cosh[x]^7/(I + Sinh[x]), x, 4, (-I)*Sinh[x] + Sinh[x]^2/2 - (2/3)*I*Sinh[x]^3 + Sinh[x]^4/2 - (1/5)*I*Sinh[x]^5 + Sinh[x]^6/6}
{Cosh[x]^6/(I + Sinh[x]), x, 3, -((3*I*x)/8) + Cosh[x]^5/5 - (3/8)*I*Cosh[x]*Sinh[x] - (1/4)*I*Cosh[x]^3*Sinh[x]}
{Cosh[x]^5/(I + Sinh[x]), x, 4, (-I)*Sinh[x] + Sinh[x]^2/2 - (1/3)*I*Sinh[x]^3 + Sinh[x]^4/4}
{Cosh[x]^4/(I + Sinh[x]), x, 2, -((I*x)/2) + Cosh[x]^3/3 - (1/2)*I*Cosh[x]*Sinh[x]}
{Cosh[x]^3/(I + Sinh[x]), x, 3, (-I)*Sinh[x] + Sinh[x]^2/2}
{Cosh[x]^2/(I + Sinh[x]), x, 2, (-I)*x + Cosh[x]}
{Cosh[x]^1/(I + Sinh[x]), x, 2, Log[1 - I*Sinh[x]]}
{Sech[x]^1/(I + Sinh[x]), x, 5, (-(1/2))*I*ArcTan[Sinh[x]] - 1/(2*(1 - I*Sinh[x]))}
{Sech[x]^2/(I + Sinh[x]), x, 3, (-(1/3))*Sech[x]^3 - I*Tanh[x] + (1/3)*I*Tanh[x]^3}
{Sech[x]^3/(I + Sinh[x]), x, 5, (-(3/8))*I*ArcTan[Sinh[x]] - 1/(8*(1 - I*Sinh[x])^2) - 1/(4*(1 - I*Sinh[x])) + 1/(8*(1 + I*Sinh[x]))}
{Sech[x]^4/(I + Sinh[x]), x, 3, (-(1/5))*Sech[x]^5 - I*Tanh[x] + (2/3)*I*Tanh[x]^3 - (1/5)*I*Tanh[x]^5}
{Sech[x]^5/(I + Sinh[x]), x, 5, (-(5/16))*I*ArcTan[Sinh[x]] - 1/(24*(1 - I*Sinh[x])^3) - 3/(32*(1 - I*Sinh[x])^2) - 3/(16*(1 - I*Sinh[x])) + 1/(32*(1 + I*Sinh[x])^2) + 1/(8*(1 + I*Sinh[x]))}


{Cosh[x]^6/(I + Sinh[x])^2, x, 3, -((5*x)/8) - (5/8)*Cosh[x]*Sinh[x] - (5/12)*Cosh[x]^3*Sinh[x] + (2*Cosh[x]^5)/(3*(I + Sinh[x]))}
{Cosh[x]^5/(I + Sinh[x])^2, x, 3, (1/3)*I*(1 + I*Sinh[x])^3}
{Cosh[x]^4/(I + Sinh[x])^2, x, 2, -((3*x)/2) - (3/2)*Cosh[x]*Sinh[x] + (2*Cosh[x]^3)/(I + Sinh[x])}
{Cosh[x]^3/(I + Sinh[x])^2, x, 4, -2*I*Log[1 - I*Sinh[x]] + Sinh[x]}
{Cosh[x]^2/(I + Sinh[x])^2, x, 2, x - (2*Cosh[x])/(I + Sinh[x])}
{Cosh[x]^1/(I + Sinh[x])^2, x, 2, I/(1 - I*Sinh[x])}
{Sech[x]^1/(I + Sinh[x])^2, x, 5, (-(1/4))*ArcTan[Sinh[x]] + I/(4*(1 - I*Sinh[x])^2) + I/(4*(1 - I*Sinh[x]))}
{Sech[x]^2/(I + Sinh[x])^2, x, 4, (1/5)*I*Sech[x]^3 - (I*Sech[x])/(5*(I + Sinh[x])^2) - (3*Tanh[x])/5 + Tanh[x]^3/5}
{Sech[x]^3/(I + Sinh[x])^2, x, 5, (-(1/4))*ArcTan[Sinh[x]] + I/(12*(1 - I*Sinh[x])^3) + I/(8*(1 - I*Sinh[x])^2) + (3*I)/(16*(1 - I*Sinh[x])) - I/(16*(1 + I*Sinh[x]))}
{Sech[x]^4/(I + Sinh[x])^2, x, 4, (1/7)*I*Sech[x]^5 - (I*Sech[x]^3)/(7*(I + Sinh[x])^2) - (5*Tanh[x])/7 + (10*Tanh[x]^3)/21 - Tanh[x]^5/7}


{Cosh[x]^3/(1 + I*Sinh[x])^3, x, 4, I*Log[1 + I*Sinh[x]] + (2*I)/(1 + I*Sinh[x])}
{Cosh[x]^2/(1 + I*Sinh[x])^3, x, 1, (I*Cosh[x]^3)/(3*(1 + I*Sinh[x])^3)}
{Cosh[x]^1/(1 + I*Sinh[x])^3, x, 2, I/(2*(1 + I*Sinh[x])^2)}


{Cosh[x]^3/(1 - I*Sinh[x])^3, x, 4, (-I)*Log[1 - I*Sinh[x]] - (2*I)/(1 - I*Sinh[x])}
{Cosh[x]^2/(1 - I*Sinh[x])^3, x, 1, -((I*Cosh[x]^3)/(3*(1 - I*Sinh[x])^3))}
{Cosh[x]^1/(1 - I*Sinh[x])^3, x, 2, -(I/(2*(1 - I*Sinh[x])^2))}


(* ::Subsubsection::Closed:: *)
(*a^2+b^2!=0*)


{Cosh[x]^7/(a + b*Sinh[x]), x, 3, ((a^2 + b^2)^3*Log[a + b*Sinh[x]])/b^7 - (a*(a^4 + 3*a^2*b^2 + 3*b^4)*Sinh[x])/b^6 + ((a^4 + 3*a^2*b^2 + 3*b^4)*Sinh[x]^2)/(2*b^5) - (a*(a^2 + 3*b^2)*Sinh[x]^3)/(3*b^4) + ((a^2 + 3*b^2)*Sinh[x]^4)/(4*b^3) - (a*Sinh[x]^5)/(5*b^2) + Sinh[x]^6/(6*b)}
{Cosh[x]^6/(a + b*Sinh[x]), x, 8, -((3*a*x)/(8*b^2)) - (a*(a^2 + b^2)*x)/(2*b^4) - (a*(a^2 + b^2)^2*x)/b^6 - (2*(a^2 + b^2)^(5/2)*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/b^6 + ((a^2 + b^2)^2*Cosh[x])/b^5 + ((a^2 + b^2)*Cosh[x]^3)/(3*b^3) + Cosh[x]^5/(5*b) - (3*a*Cosh[x]*Sinh[x])/(8*b^2) - (a*(a^2 + b^2)*Cosh[x]*Sinh[x])/(2*b^4) - (a*Cosh[x]^3*Sinh[x])/(4*b^2)}
{Cosh[x]^5/(a + b*Sinh[x]), x, 3, ((a^2 + b^2)^2*Log[a + b*Sinh[x]])/b^5 - (a*(a^2 + 2*b^2)*Sinh[x])/b^4 + ((a^2 + 2*b^2)*Sinh[x]^2)/(2*b^3) - (a*Sinh[x]^3)/(3*b^2) + Sinh[x]^4/(4*b)}
{Cosh[x]^4/(a + b*Sinh[x]), x, 5, -((a*x)/(2*b^2)) - (a*(a^2 + b^2)*x)/b^4 - (2*(a^2 + b^2)^(3/2)*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/b^4 + ((a^2 + b^2)*Cosh[x])/b^3 + Cosh[x]^3/(3*b) - (a*Cosh[x]*Sinh[x])/(2*b^2)}
{Cosh[x]^3/(a + b*Sinh[x]), x, 3, ((a^2 + b^2)*Log[a + b*Sinh[x]])/b^3 - (a*Sinh[x])/b^2 + Sinh[x]^2/(2*b)}
{Cosh[x]^2/(a + b*Sinh[x]), x, 3, -((a*x)/b^2) - (2*Sqrt[a^2 + b^2]*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/b^2 + Cosh[x]/b}
{Cosh[x]^1/(a + b*Sinh[x]), x, 2, Log[a + b*Sinh[x]]/b}
{Sech[x]^1/(a + b*Sinh[x]), x, 6, -(Log[1 - I*Sinh[x]]/(2*(I*a + b))) - (I*Log[1 + I*Sinh[x]])/(2*(a + I*b)) + (b*Log[a + b*Sinh[x]])/(a^2 + b^2)}
{Sech[x]^2/(a + b*Sinh[x]), x, 3, -((2*b^2*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(3/2)) + (b*Sech[x])/(a^2 + b^2) + (a*Tanh[x])/(a^2 + b^2)}
{Sech[x]^3/(a + b*Sinh[x]), x, 7, ((I*a + 2*b)*Log[1 - I*Sinh[x]])/(4*(a - I*b)^2) - (I*(a + 2*I*b)*Log[1 + I*Sinh[x]])/(4*(a + I*b)^2) + (b^3*Log[a + b*Sinh[x]])/(a^2 + b^2)^2 + (b + a*Sinh[x])/(2*(a^2 + b^2)*(1 + Sinh[x]^2))}
{Sech[x]^4/(a + b*Sinh[x]), x, 6, -((2*b^4*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2)) + (b^3*Sech[x])/(a^2 + b^2)^2 + (b*Sech[x]^3)/(3*(a^2 + b^2)) + (a*b^2*Tanh[x])/(a^2 + b^2)^2 + (a*Tanh[x])/(a^2 + b^2) - (a*Tanh[x]^3)/(3*(a^2 + b^2))}
{Sech[x]^5/(a + b*Sinh[x]), x, 8, ((3*a^2 - 9*I*a*b - 8*b^2)*Log[1 - I*Sinh[x]])/(16*(I*a + b)^3) - (I*(3*a^2 + 9*I*a*b - 8*b^2)*Log[1 + I*Sinh[x]])/(16*(a + I*b)^3) + (b^5*Log[a + b*Sinh[x]])/(a^2 + b^2)^3 + (b + a*Sinh[x])/(4*(a^2 + b^2)*(1 + Sinh[x]^2)^2) + (4*b^3 + a*(3*a^2 + 7*b^2)*Sinh[x])/(8*(a^2 + b^2)^2*(1 + Sinh[x]^2))}
{Sech[x]^6/(a + b*Sinh[x]), x, 9, -((2*b^6*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(7/2)) + (b^5*Sech[x])/(a^2 + b^2)^3 + (b^3*Sech[x]^3)/(3*(a^2 + b^2)^2) + (b*Sech[x]^5)/(5*(a^2 + b^2)) + (a*b^4*Tanh[x])/(a^2 + b^2)^3 + (a*b^2*Tanh[x])/(a^2 + b^2)^2 + (a*Tanh[x])/(a^2 + b^2) - (a*b^2*Tanh[x]^3)/(3*(a^2 + b^2)^2) - (2*a*Tanh[x]^3)/(3*(a^2 + b^2)) + (a*Tanh[x]^5)/(5*(a^2 + b^2))}


{Cosh[x]^4/(a + b*Sinh[x])^2, x, 8, (2*a^2*x)/b^4 + x/(2*b^2) + ((a^2 + b^2)*x)/b^4 + (6*a*Sqrt[a^2 + b^2]*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/b^4 - (2*a*Cosh[x])/b^3 + (Cosh[x]*Sinh[x])/(2*b^2) - ((a^2 + b^2)*Cosh[x])/(b^3*(a + b*Sinh[x]))}
{Cosh[x]^3/(a + b*Sinh[x])^2, x, 3, -((2*a*Log[a + b*Sinh[x]])/b^3) + Sinh[x]/b^2 - (a^2 + b^2)/(b^3*(a + b*Sinh[x]))}
{Cosh[x]^2/(a + b*Sinh[x])^2, x, 3, x/b^2 + (2*a*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(b^2*Sqrt[a^2 + b^2]) - Cosh[x]/(b*(a + b*Sinh[x]))}
{Cosh[x]^1/(a + b*Sinh[x])^2, x, 2, -(1/(b*(a + b*Sinh[x])))}
{Sech[x]^1/(a + b*Sinh[x])^2, x, 7, (I*Log[1 - I*Sinh[x]])/(2*(a - I*b)^2) - (I*Log[1 + I*Sinh[x]])/(2*(a + I*b)^2) + (2*a*b*Log[a + b*Sinh[x]])/(a^2 + b^2)^2 - b/((a^2 + b^2)*(a + b*Sinh[x]))}
{Sech[x]^2/(a + b*Sinh[x])^2, x, 5, -((6*a*b^2*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2)) + (a*b*Cosh[x])/((a^2 + b^2)*(a + b*Sinh[x])^2) + (b*(a^2 - 2*b^2)*Cosh[x])/((a^2 + b^2)^2*(a + b*Sinh[x])) + Tanh[x]/(a + b*Sinh[x])^2}
{Sech[x]^3/(a + b*Sinh[x])^2, x, 8, ((a - 3*I*b)*Log[1 - I*Sinh[x]])/(4*(I*a + b)^3) - (I*(a + 3*I*b)*Log[1 + I*Sinh[x]])/(4*(a + I*b)^3) + (4*a*b^3*Log[a + b*Sinh[x]])/(a^2 + b^2)^3 + (b*(a^2 - 3*b^2))/(2*(a^2 + b^2)^2*(a + b*Sinh[x])) + (b + a*Sinh[x])/(2*(a^2 + b^2)*(a + b*Sinh[x])*(1 + Sinh[x]^2))}
{Sech[x]^4/(a + b*Sinh[x])^2, x, 18, -((10*a*b^4*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(7/2)) + (4*a*b^3*Sech[x])/(a^2 + b^2)^3 + (2*a*b*Sech[x]^3)/(3*(a^2 + b^2)^2) - (b^5*Cosh[x])/((a^2 + b^2)^3*(a + b*Sinh[x])) + (3*a^2*b^2*Tanh[x])/(a^2 + b^2)^3 - (b^4*Tanh[x])/(a^2 + b^2)^3 + (a^2*Tanh[x])/(a^2 + b^2)^2 - (b^2*Tanh[x])/(a^2 + b^2)^2 - (a^2*Tanh[x]^3)/(3*(a^2 + b^2)^2) + (b^2*Tanh[x]^3)/(3*(a^2 + b^2)^2)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Tanh[c+d x]^m (a+b Sinh[c+d x])^n*)


(* ::Subsubsection::Closed:: *)
(*a^2+b^2=0*)


{Tanh[x]^4/(I + Sinh[x]), x, 4, -Sech[x] + (2*Sech[x]^3)/3 - Sech[x]^5/5 - (1/5)*I*Tanh[x]^5}
{Tanh[x]^3/(I + Sinh[x]), x, 5, (3/8)*ArcTan[Sinh[x]] - I/(8*(1 - I*Sinh[x])^2) + I/(2*(1 - I*Sinh[x])) - I/(8*(1 + I*Sinh[x]))}
{Tanh[x]^2/(I + Sinh[x]), x, 3, -Sech[x] + Sech[x]^3/3 - (1/3)*I*Tanh[x]^3}
{Tanh[x]^1/(I + Sinh[x]), x, 5, (1/2)*ArcTan[Sinh[x]] + I/(2*(1 - I*Sinh[x]))}
{Coth[x]^1/(I + Sinh[x]), x, 3, I*Log[1 - I*Sinh[x]] - I*Log[Sinh[x]]}
{Coth[x]^2/(I + Sinh[x]), x, 2, -ArcTanh[Cosh[x]] + I*Coth[x]}
{Coth[x]^3/(I + Sinh[x]), x, 4, -Csch[x] + (1/2)*I*Csch[x]^2}
{Coth[x]^4/(I + Sinh[x]), x, 3, (-(1/2))*ArcTanh[Cosh[x]] + (1/3)*I*Coth[x]^3 - (1/2)*Coth[x]*Csch[x]}
{Coth[x]^5/(I + Sinh[x]), x, 4, -Csch[x] + (1/2)*I*Csch[x]^2 - Csch[x]^3/3 + (1/4)*I*Csch[x]^4}
{Coth[x]^6/(I + Sinh[x]), x, 4, (-(3/8))*ArcTanh[Cosh[x]] + (1/5)*I*Coth[x]^5 - (3/8)*Coth[x]*Csch[x] - (1/4)*Coth[x]^3*Csch[x]}


{Tanh[x]^4/(I + Sinh[x])^2, x, 8, (2/3)*I*Sech[x]^3 - (4/5)*I*Sech[x]^5 + (2/7)*I*Sech[x]^7 - Tanh[x]^5/5 + (2*Tanh[x]^7)/7}
{Tanh[x]^3/(I + Sinh[x])^2, x, 5, (-(1/8))*I*ArcTan[Sinh[x]] - 1/(12*(1 - I*Sinh[x])^3) + 1/(4*(1 - I*Sinh[x])^2) - 3/(16*(1 - I*Sinh[x])) - 1/(16*(1 + I*Sinh[x]))}
{Tanh[x]^2/(I + Sinh[x])^2, x, 7, (2/3)*I*Sech[x]^3 - (2/5)*I*Sech[x]^5 - Tanh[x]^3/3 + (2*Tanh[x]^5)/5}
{Tanh[x]^1/(I + Sinh[x])^2, x, 5, (-(1/4))*I*ArcTan[Sinh[x]] + 1/(4*(1 - I*Sinh[x])^2) - 1/(4*(1 - I*Sinh[x]))}
{Coth[x]^1/(I + Sinh[x])^2, x, 3, Log[1 - I*Sinh[x]] - Log[Sinh[x]] - 1/(1 - I*Sinh[x])}
{Coth[x]^2/(I + Sinh[x])^2, x, 3, 2*I*ArcTanh[Cosh[x]] + Coth[x] + (2*Cosh[x])/(I + Sinh[x])}
{Coth[x]^3/(I + Sinh[x])^2, x, 4, 2*I*Csch[x] + Csch[x]^2/2 - 2*Log[1 - I*Sinh[x]] + 2*Log[Sinh[x]]}
{Coth[x]^4/(I + Sinh[x])^2, x, 5, (-I)*ArcTanh[Cosh[x]] - 2*Coth[x] + Coth[x]^3/3 + I*Coth[x]*Csch[x]}
{Coth[x]^5/(I + Sinh[x])^2, x, 4, (-(1/2))*Csch[x]^2 + (2/3)*I*Csch[x]^3 + Csch[x]^4/4}
{Coth[x]^6/(I + Sinh[x])^2, x, 7, (-(1/4))*I*ArcTanh[Cosh[x]] - (2*Coth[x]^3)/3 + Coth[x]^5/5 - (1/4)*I*Coth[x]*Csch[x] + (1/2)*I*Coth[x]^3*Csch[x]}


(* ::Subsubsection::Closed:: *)
(*a^2+b^2!=0*)


{Tanh[x]^4/(a + b*Sinh[x]), x, 6, -((2*a^4*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2)) - (a^2*b*Sech[x])/(a^2 + b^2)^2 - (b*Sech[x])/(a^2 + b^2) + (b*Sech[x]^3)/(3*(a^2 + b^2)) - (a^3*Tanh[x])/(a^2 + b^2)^2 - (a*Tanh[x]^3)/(3*(a^2 + b^2))}
{Tanh[x]^3/(a + b*Sinh[x]), x, 3, -((I*(2*I*a + b)*Log[1 - I*Sinh[x]])/(4*(a - I*b)^2)) + ((2*a + I*b)*Log[1 + I*Sinh[x]])/(4*(a + I*b)^2) - (a^3*Log[a + b*Sinh[x]])/(a^2 + b^2)^2 + 1/(4*(a - I*b)*(1 - I*Sinh[x])) + 1/(4*(a + I*b)*(1 + I*Sinh[x]))}
{Tanh[x]^2/(a + b*Sinh[x]), x, 3, -((2*a^2*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(3/2)) - (b*Sech[x])/(a^2 + b^2) - (a*Tanh[x])/(a^2 + b^2)}
{Tanh[x]^1/(a + b*Sinh[x]), x, 6, Log[1 - I*Sinh[x]]/(2*(a - I*b)) + Log[1 + I*Sinh[x]]/(2*(a + I*b)) - (a*Log[a + b*Sinh[x]])/(a^2 + b^2)}
{Coth[x]^1/(a + b*Sinh[x]), x, 3, Log[Sinh[x]]/a - Log[a + b*Sinh[x]]/a}
{Coth[x]^2/(a + b*Sinh[x]), x, 3, (b*ArcTanh[Cosh[x]])/a^2 - (2*Sqrt[a^2 + b^2]*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/a^2 - Coth[x]/a}
{Coth[x]^3/(a + b*Sinh[x]), x, 3, (b*Csch[x])/a^2 - Csch[x]^2/(2*a) + ((a^2 + b^2)*Log[Sinh[x]])/a^3 - ((a^2 + b^2)*Log[a + b*Sinh[x]])/a^3}
{Coth[x]^4/(a + b*Sinh[x]), x, 6, (b*ArcTanh[Cosh[x]])/(2*a^2) + (b*(a^2 + b^2)*ArcTanh[Cosh[x]])/a^4 - (2*(a^2 + b^2)^(3/2)*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/a^4 - ((a^2 + b^2)*Coth[x])/a^3 - Coth[x]^3/(3*a) + (b*Coth[x]*Csch[x])/(2*a^2)}


{Tanh[x]^4/(a + b*Sinh[x])^2, x, 12, -((2*a^5*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(7/2)) + (8*a^3*b^2*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(7/2) - (I*Cosh[x])/(12*(a - I*b)^2*(1 - I*Sinh[x])^2) - (I*Cosh[x])/(12*(a - I*b)^2*(1 - I*Sinh[x])) + ((3*I*a + b)*Cosh[x])/(4*(a - I*b)^3*(1 - I*Sinh[x])) + (I*Cosh[x])/(12*(a + I*b)^2*(1 + I*Sinh[x])^2) - ((3*I*a - b)*Cosh[x])/(4*(a + I*b)^3*(1 + I*Sinh[x])) + (I*Cosh[x])/(12*(a + I*b)^2*(1 + I*Sinh[x])) - (a^4*b*Cosh[x])/((a^2 + b^2)^3*(a + b*Sinh[x]))}
{Tanh[x]^3/(a + b*Sinh[x])^2, x, 3, (a*Log[1 - I*Sinh[x]])/(2*(a - I*b)^3) + (a*Log[1 + I*Sinh[x]])/(2*(a + I*b)^3) - (a^2*(a^2 - 3*b^2)*Log[a + b*Sinh[x]])/(a^2 + b^2)^3 + 1/(4*(a - I*b)^2*(1 - I*Sinh[x])) + 1/(4*(a + I*b)^2*(1 + I*Sinh[x])) + a^3/((a^2 + b^2)^2*(a + b*Sinh[x]))}
{Tanh[x]^2/(a + b*Sinh[x])^2, x, 8, -((2*a^3*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2)) + (4*a*b^2*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2) + (I*Cosh[x])/(2*(a - I*b)^2*(1 - I*Sinh[x])) - (I*Cosh[x])/(2*(a + I*b)^2*(1 + I*Sinh[x])) - (a^2*b*Cosh[x])/((a^2 + b^2)^2*(a + b*Sinh[x]))}
{Tanh[x]^1/(a + b*Sinh[x])^2, x, 7, Log[1 - I*Sinh[x]]/(2*(a - I*b)^2) + Log[1 + I*Sinh[x]]/(2*(a + I*b)^2) - ((a^2 - b^2)*Log[a + b*Sinh[x]])/(a^2 + b^2)^2 + a/((a^2 + b^2)*(a + b*Sinh[x]))}
{Coth[x]^1/(a + b*Sinh[x])^2, x, 3, Log[Sinh[x]]/a^2 - Log[a + b*Sinh[x]]/a^2 + 1/(a*(a + b*Sinh[x]))}
{Coth[x]^2/(a + b*Sinh[x])^2, x, 8, (2*b*ArcTanh[Cosh[x]])/a^3 - (2*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a*Sqrt[a^2 + b^2]) - (4*b^2*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^3*Sqrt[a^2 + b^2]) - Coth[x]/a^2 - (b*Cosh[x])/(a^2*(a + b*Sinh[x]))}
{Coth[x]^3/(a + b*Sinh[x])^2, x, 3, (2*b*Csch[x])/a^3 - Csch[x]^2/(2*a^2) + ((a^2 + 3*b^2)*Log[Sinh[x]])/a^4 - ((a^2 + 3*b^2)*Log[a + b*Sinh[x]])/a^4 + (a^2 + b^2)/(a^3*(a + b*Sinh[x]))}
{Coth[x]^4/(a + b*Sinh[x])^2, x, 12, -((b*ArcTanh[Cosh[x]])/a^3) + (4*b*(a^2 + b^2)*ArcTanh[Cosh[x]])/a^5 - (2*Sqrt[a^2 + b^2]*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/a^3 - (8*b^2*Sqrt[a^2 + b^2]*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/a^5 + (2*Coth[x])/(3*a^2) - ((2*a^2 + 3*b^2)*Coth[x])/a^4 + (b*Coth[x]*Csch[x])/a^3 - (Coth[x]*Csch[x]^2)/(3*a^2) - (b*(a^2 + b^2)*Cosh[x])/(a^4*(a + b*Sinh[x]))}


{Coth[x]*Sqrt[a + b*Sinh[x]], x, 3, -2*Sqrt[a]*ArcTanh[Sqrt[a + b*Sinh[x]]/Sqrt[a]] + 2*Sqrt[a + b*Sinh[x]]}
{Coth[x]/Sqrt[a + b*Sinh[x]], x, 2, -((2*ArcTanh[Sqrt[a + b*Sinh[x]]/Sqrt[a]])/Sqrt[a])}


(* ::Section::Closed:: *)
(*Integrands of the form Hyper[c+d x]^m (a+b Sinh[c+d x]^2)^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sinh[c+d x]^m (a+b Sinh[c+d x]^2)^n*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Sinh[c + d*x]^4*(a + b*Sinh[c + d*x]^2), x, 3, ((6*a - 5*b)*x)/16 - ((6*a - 5*b)*Cosh[c + d*x]*Sinh[c + d*x])/(16*d) + ((6*a - 5*b)*Cosh[c + d*x]*Sinh[c + d*x]^3)/(24*d) + (b*Cosh[c + d*x]*Sinh[c + d*x]^5)/(6*d)}
{Sinh[c + d*x]^3*(a + b*Sinh[c + d*x]^2), x, 3, -((5*a - 4*b)*Cosh[c + d*x])/(5*d) + ((5*a - 4*b)*Cosh[c + d*x]^3)/(15*d) + (b*Cosh[c + d*x]*Sinh[c + d*x]^4)/(5*d)}
{Sinh[c + d*x]^2*(a + b*Sinh[c + d*x]^2), x, 2, -((4*a - 3*b)*x)/8 + ((4*a - 3*b)*Cosh[c + d*x]*Sinh[c + d*x])/(8*d) + (b*Cosh[c + d*x]*Sinh[c + d*x]^3)/(4*d)}
{Sinh[c + d*x]*(a + b*Sinh[c + d*x]^2), x, 2, ((3*a - 2*b)*Cosh[c + d*x])/(3*d) + (b*Cosh[c + d*x]*Sinh[c + d*x]^2)/(3*d)}
{a + b*Sinh[c + d*x]^2, x, 2, a*x - (b*x)/2 + (b*Cosh[c + d*x]*Sinh[c + d*x])/(2*d)}
{Csch[c + d*x]*(a + b*Sinh[c + d*x]^2), x, 2, -((a*ArcTanh[Cosh[c + d*x]])/d) + (b*Cosh[c + d*x])/d}
{Csch[c + d*x]^2*(a + b*Sinh[c + d*x]^2), x, 2, b*x - (a*Coth[c + d*x])/d}
{Csch[c + d*x]^3*(a + b*Sinh[c + d*x]^2), x, 2, ((a - 2*b)*ArcTanh[Cosh[c + d*x]])/(2*d) - (a*Coth[c + d*x]*Csch[c + d*x])/(2*d)}
{Csch[c + d*x]^4*(a + b*Sinh[c + d*x]^2), x, 2, ((2*a - 3*b)*Coth[c + d*x])/(3*d) - (a*Coth[c + d*x]*Csch[c + d*x]^2)/(3*d)}


{Sinh[c + d*x]^4*(a + b*Sinh[c + d*x]^2)^2, x, 6, ((48*a^2 - 80*a*b + 35*b^2)*x)/128 - ((10*a - 7*b)*b*Coth[c + d*x])/(48*d*(1 - Coth[c + d*x]^2)^3) + ((48*a^2 - 80*a*b + 35*b^2)*Coth[c + d*x])/(192*d*(1 - Coth[c + d*x]^2)^2) + ((48*a^2 - 80*a*b + 35*b^2)*Coth[c + d*x])/(128*d*(1 - Coth[c + d*x]^2)) - (b*Coth[c + d*x]*(a - b - a*Coth[c + d*x]^2))/(8*d*(1 - Coth[c + d*x]^2)^4)}
{Sinh[c + d*x]^3*(a + b*Sinh[c + d*x]^2)^2, x, 3, -(((a - b)^2*Cosh[c + d*x])/d) + ((a - 3*b)*(a - b)*Cosh[c + d*x]^3)/(3*d) + ((2*a - 3*b)*b*Cosh[c + d*x]^5)/(5*d) + (b^2*Cosh[c + d*x]^7)/(7*d)}
{Sinh[c + d*x]^2*(a + b*Sinh[c + d*x]^2)^2, x, 5, -((8*a^2 - 12*a*b + 5*b^2)*x)/16 + ((8*a - 5*b)*b*Coth[c + d*x])/(24*d*(1 - Coth[c + d*x]^2)^2) - ((8*a^2 - 12*a*b + 5*b^2)*Coth[c + d*x])/(16*d*(1 - Coth[c + d*x]^2)) + (b*Coth[c + d*x]*(a - b - a*Coth[c + d*x]^2))/(6*d*(1 - Coth[c + d*x]^2)^3)}
{Sinh[c + d*x]*(a + b*Sinh[c + d*x]^2)^2, x, 3, ((a - b)^2*Cosh[c + d*x])/d + (2*(a - b)*b*Cosh[c + d*x]^3)/(3*d) + (b^2*Cosh[c + d*x]^5)/(5*d)}
{(a + b*Sinh[c + d*x]^2)^2, x, 4, ((8*a^2 - 8*a*b + 3*b^2)*x)/8 + (3*(2*a - b)*b*Tanh[c + d*x])/(8*d*(1 - Tanh[c + d*x]^2)) + (b*Tanh[c + d*x]*(a - (a - b)*Tanh[c + d*x]^2))/(4*d*(1 - Tanh[c + d*x]^2)^2)}
{Csch[c + d*x]*(a + b*Sinh[c + d*x]^2)^2, x, 4, -((a^2*ArcTanh[Cosh[c + d*x]])/d) + ((2*a - b)*b*Cosh[c + d*x])/d + (b^2*Cosh[c + d*x]^3)/(3*d)}
{Csch[c + d*x]^2*(a + b*Sinh[c + d*x]^2)^2, x, 5, (1/2)*(4*a - b)*b*x - (a^2*Coth[c + d*x])/d - (b^2*Coth[c + d*x])/(2*d*(1 - Coth[c + d*x]^2))}
{Csch[c + d*x]^3*(a + b*Sinh[c + d*x]^2)^2, x, 5, (a*(a - 4*b)*ArcTanh[Cosh[c + d*x]])/(2*d) + (b^2*Cosh[c + d*x])/d + (a^2*Cosh[c + d*x])/(2*d*(1 - Cosh[c + d*x]^2))}
{Csch[c + d*x]^4*(a + b*Sinh[c + d*x]^2)^2, x, 4, b^2*x + (a*(a - 2*b)*Coth[c + d*x])/d - (a^2*Coth[c + d*x]^3)/(3*d)}


{Sinh[c + d*x]^4*(a + b*Sinh[c + d*x]^2)^3, x, 7, (3*(4*a - 3*b)*(8*a^2 - 14*a*b + 7*b^2)*x)/256 - (b*(44*a^2 - 60*a*b + 21*b^2)*Coth[c + d*x])/(160*d*(1 - Coth[c + d*x]^2)^3) + ((4*a - 3*b)*(8*a^2 - 14*a*b + 7*b^2)*Coth[c + d*x])/(128*d*(1 - Coth[c + d*x]^2)^2) + (3*(4*a - 3*b)*(8*a^2 - 14*a*b + 7*b^2)*Coth[c + d*x])/(256*d*(1 - Coth[c + d*x]^2)) - (b*Coth[c + d*x]*(a - b - a*Coth[c + d*x]^2)^2)/(10*d*(1 - Coth[c + d*x]^2)^5) - (b*Coth[c + d*x]*((10*a - 9*b)*(a - b) - 5*a*(2*a - b)*Coth[c + d*x]^2))/(80*d*(1 - Coth[c + d*x]^2)^4)}
{Sinh[c + d*x]^3*(a + b*Sinh[c + d*x]^2)^3, x, 3, -(((a - b)^3*Cosh[c + d*x])/d) + ((a - 4*b)*(a - b)^2*Cosh[c + d*x]^3)/(3*d) + (3*(a - 2*b)*(a - b)*b*Cosh[c + d*x]^5)/(5*d) + ((3*a - 4*b)*b^2*Cosh[c + d*x]^7)/(7*d) + (b^3*Cosh[c + d*x]^9)/(9*d)}
{Sinh[c + d*x]^2*(a + b*Sinh[c + d*x]^2)^3, x, 6, -((64*a^3 - 144*a^2*b + 120*a*b^2 - 35*b^3)*x)/128 + (b*(88*a^2 - 108*a*b + 35*b^2)*Coth[c + d*x])/(192*d*(1 - Coth[c + d*x]^2)^2) - ((64*a^3 - 144*a^2*b + 120*a*b^2 - 35*b^3)*Coth[c + d*x])/(128*d*(1 - Coth[c + d*x]^2)) + (b*Coth[c + d*x]*(a - b - a*Coth[c + d*x]^2)^2)/(8*d*(1 - Coth[c + d*x]^2)^4) + (b*Coth[c + d*x]*((8*a - 7*b)*(a - b) - a*(8*a - 3*b)*Coth[c + d*x]^2))/(48*d*(1 - Coth[c + d*x]^2)^3)}
{Sinh[c + d*x]*(a + b*Sinh[c + d*x]^2)^3, x, 3, ((a - b)^3*Cosh[c + d*x])/d + ((a - b)^2*b*Cosh[c + d*x]^3)/d + (3*(a - b)*b^2*Cosh[c + d*x]^5)/(5*d) + (b^3*Cosh[c + d*x]^7)/(7*d)}
{(a + b*Sinh[c + d*x]^2)^3, x, 5, ((2*a - b)*(8*a^2 - 8*a*b + 5*b^2)*x)/16 + (b*(44*a^2 - 44*a*b + 15*b^2)*Tanh[c + d*x])/(48*d*(1 - Tanh[c + d*x]^2)) + (5*(2*a - b)*b*Tanh[c + d*x]*(a - (a - b)*Tanh[c + d*x]^2))/(24*d*(1 - Tanh[c + d*x]^2)^2) + (b*Tanh[c + d*x]*(a - (a - b)*Tanh[c + d*x]^2)^2)/(6*d*(1 - Tanh[c + d*x]^2)^3)}
{Csch[c + d*x]*(a + b*Sinh[c + d*x]^2)^3, x, 4, -((a^3*ArcTanh[Cosh[c + d*x]])/d) + (b*(3*a^2 - 3*a*b + b^2)*Cosh[c + d*x])/d + ((3*a - 2*b)*b^2*Cosh[c + d*x]^3)/(3*d) + (b^3*Cosh[c + d*x]^5)/(5*d)}
{Csch[c + d*x]^2*(a + b*Sinh[c + d*x]^2)^3, x, 6, (3/8)*b*(8*a^2 - 4*a*b + b^2)*x - (a^3*Coth[c + d*x])/d + (b^3*Coth[c + d*x])/(4*d*(1 - Coth[c + d*x]^2)^2) - (3*(4*a - b)*b^2*Coth[c + d*x])/(8*d*(1 - Coth[c + d*x]^2))}
{Csch[c + d*x]^3*(a + b*Sinh[c + d*x]^2)^3, x, 5, (a^2*(a - 6*b)*ArcTanh[Cosh[c + d*x]])/(2*d) + ((3*a - b)*b^2*Cosh[c + d*x])/d + (b^3*Cosh[c + d*x]^3)/(3*d) + (a^3*Cosh[c + d*x])/(2*d*(1 - Cosh[c + d*x]^2))}
{Csch[c + d*x]^4*(a + b*Sinh[c + d*x]^2)^3, x, 5, (1/2)*(6*a - b)*b^2*x + (a^2*(a - 3*b)*Coth[c + d*x])/d - (a^3*Coth[c + d*x]^3)/(3*d) - (b^3*Coth[c + d*x])/(2*d*(1 - Coth[c + d*x]^2))}


{Sqrt[1 + Sinh[x]^2], x, 3, Sqrt[Cosh[x]^2]*Tanh[x]}
{Sqrt[-1 - Sinh[x]^2], x, 3, Sqrt[-Cosh[x]^2]*Tanh[x]}
{Sqrt[1 - Sinh[x]^2], x, 2, (-I)*EllipticE[I*x, -1]}
{Sqrt[-1 + Sinh[x]^2], x, 3, -((I*Sqrt[-3 + Cosh[2*x]]*EllipticE[I*x, -1])/Sqrt[3 - Cosh[2*x]])}
{Sqrt[a + b*Sinh[x]^2], x, 3, -((I*Sqrt[2*a - b + b*Cosh[2*x]]*EllipticE[I*x, b/a])/Sqrt[(2*a - b + b*Cosh[2*x])/a])}


{(1 + Sinh[x]^2)^(3/2), x, 4, (2/3)*Sqrt[Cosh[x]^2]*Tanh[x] + (1/3)*(Cosh[x]^2)^(3/2)*Tanh[x]}
{(-1 - Sinh[x]^2)^(3/2), x, 4, (-(2/3))*Sqrt[-Cosh[x]^2]*Tanh[x] + (1/3)*(-Cosh[x]^2)^(3/2)*Tanh[x]}
{(1 - Sinh[x]^2)^(3/2), x, 5, -2*I*EllipticE[I*x, -1] + (2/3)*I*EllipticF[I*x, -1] - (Sqrt[3 - Cosh[2*x]]*Sinh[2*x])/(6*Sqrt[2])}
{(-1 + Sinh[x]^2)^(3/2), x, 7, (2*I*Sqrt[-3 + Cosh[2*x]]*EllipticE[I*x, -1])/Sqrt[3 - Cosh[2*x]] + (2*I*Sqrt[3 - Cosh[2*x]]*EllipticF[I*x, -1])/(3*Sqrt[-3 + Cosh[2*x]]) + (Sqrt[-3 + Cosh[2*x]]*Sinh[2*x])/(6*Sqrt[2])}
{(a + b*Sinh[x]^2)^(3/2), x, 7, -((2*I*(2*a - b)*Sqrt[2*a - b + b*Cosh[2*x]]*EllipticE[I*x, b/a])/(3*Sqrt[(2*a - b + b*Cosh[2*x])/a])) + (I*a*(a - b)*Sqrt[(2*a - b + b*Cosh[2*x])/a]*EllipticF[I*x, b/a])/(3*Sqrt[2*a - b + b*Cosh[2*x]]) + (b*Sqrt[2*a - b + b*Cosh[2*x]]*Sinh[2*x])/(6*Sqrt[2])}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Sinh[c + d*x]^7/(a + b*Sinh[c + d*x]^2), x, 4, -((a^3*ArcTan[(Sqrt[b]*Cosh[c + d*x])/Sqrt[a - b]])/(Sqrt[a - b]*b^(7/2)*d)) + ((a^2 + a*b + b^2)*Cosh[c + d*x])/(b^3*d) - ((a + 2*b)*Cosh[c + d*x]^3)/(3*b^2*d) + Cosh[c + d*x]^5/(5*b*d)}
{Sinh[c + d*x]^6/(a + b*Sinh[c + d*x]^2), x, 6, ((8*a^2 + 4*a*b + 3*b^2)*x)/(8*b^3) - (a^(5/2)*ArcTanh[(Sqrt[a]*Coth[c + d*x])/Sqrt[a - b]])/(Sqrt[a - b]*b^3*d) + Coth[c + d*x]/(4*b*d*(1 - Coth[c + d*x]^2)^2) + ((4*a + 3*b)*Coth[c + d*x])/(8*b^2*d*(1 - Coth[c + d*x]^2))}
{Sinh[c + d*x]^5/(a + b*Sinh[c + d*x]^2), x, 4, (a^2*ArcTan[(Sqrt[b]*Cosh[c + d*x])/Sqrt[a - b]])/(Sqrt[a - b]*b^(5/2)*d) - ((a + b)*Cosh[c + d*x])/(b^2*d) + Cosh[c + d*x]^3/(3*b*d)}
{Sinh[c + d*x]^4/(a + b*Sinh[c + d*x]^2), x, 5, -((2*a + b)*x)/(2*b^2) + (a^(3/2)*ArcTanh[(Sqrt[a]*Coth[c + d*x])/Sqrt[a - b]])/(Sqrt[a - b]*b^2*d) - Coth[c + d*x]/(2*b*d*(1 - Coth[c + d*x]^2))}
{Sinh[c + d*x]^3/(a + b*Sinh[c + d*x]^2), x, 3, -((a*ArcTan[(Sqrt[b]*Cosh[c + d*x])/Sqrt[a - b]])/(Sqrt[a - b]*b^(3/2)*d)) + Cosh[c + d*x]/(b*d)}
{Sinh[c + d*x]^2/(a + b*Sinh[c + d*x]^2), x, 4, x/b - (Sqrt[a]*ArcTanh[(Sqrt[a]*Coth[c + d*x])/Sqrt[a - b]])/(Sqrt[a - b]*b*d)}
{Sinh[c + d*x]/(a + b*Sinh[c + d*x]^2), x, 2, ArcTan[(Sqrt[b]*Cosh[c + d*x])/Sqrt[a - b]]/(Sqrt[a - b]*Sqrt[b]*d)}
{1/(a + b*Sinh[c + d*x]^2), x, 2, ArcTan[(Sqrt[-a + b]*Tanh[c + d*x])/Sqrt[a]]/(Sqrt[a]*Sqrt[-a + b]*d)}
{Csch[c + d*x]/(a + b*Sinh[c + d*x]^2), x, 4, -((Sqrt[b]*ArcTan[(Sqrt[b]*Cosh[c + d*x])/Sqrt[a - b]])/(a*Sqrt[a - b]*d)) - ArcTanh[Cosh[c + d*x]]/(a*d)}
{Csch[c + d*x]^2/(a + b*Sinh[c + d*x]^2), x, 3, -((b*ArcTanh[(Sqrt[a]*Coth[c + d*x])/Sqrt[a - b]])/(a^(3/2)*Sqrt[a - b]*d)) - Coth[c + d*x]/(a*d)}
{Csch[c + d*x]^3/(a + b*Sinh[c + d*x]^2), x, 5, (b^(3/2)*ArcTan[(Sqrt[b]*Cosh[c + d*x])/Sqrt[a - b]])/(a^2*Sqrt[a - b]*d) + ((a + 2*b)*ArcTanh[Cosh[c + d*x]])/(2*a^2*d) + Cosh[c + d*x]/(2*a*d*(1 - Cosh[c + d*x]^2))}
{Csch[c + d*x]^4/(a + b*Sinh[c + d*x]^2), x, 4, (b^2*ArcTanh[(Sqrt[a]*Coth[c + d*x])/Sqrt[a - b]])/(a^(5/2)*Sqrt[a - b]*d) + ((a + b)*Coth[c + d*x])/(a^2*d) - Coth[c + d*x]^3/(3*a*d)}
{Csch[c + d*x]^5/(a + b*Sinh[c + d*x]^2), x, 6, -((b^(5/2)*ArcTan[(Sqrt[b]*Cosh[c + d*x])/Sqrt[a - b]])/(a^3*Sqrt[a - b]*d)) - ((3*a^2 + 4*a*b + 8*b^2)*ArcTanh[Cosh[c + d*x]])/(8*a^3*d) - Cosh[c + d*x]/(4*a*d*(1 - Cosh[c + d*x]^2)^2) - ((3*a + 4*b)*Cosh[c + d*x])/(8*a^2*d*(1 - Cosh[c + d*x]^2))}
{Csch[c + d*x]^6/(a + b*Sinh[c + d*x]^2), x, 4, -((b^3*ArcTanh[(Sqrt[a]*Coth[c + d*x])/Sqrt[a - b]])/(a^(7/2)*Sqrt[a - b]*d)) - ((a^2 + a*b + b^2)*Coth[c + d*x])/(a^3*d) + ((2*a + b)*Coth[c + d*x]^3)/(3*a^2*d) - Coth[c + d*x]^5/(5*a*d)}


{Sinh[c + d*x]^4/(a + b*Sinh[c + d*x]^2)^2, x, 5, x/b^2 - (Sqrt[a]*(2*a - 3*b)*ArcTanh[(Sqrt[a]*Coth[c + d*x])/Sqrt[a - b]])/(2*(a - b)^(3/2)*b^2*d) + (a*Coth[c + d*x])/(2*(a - b)*b*d*(a - b - a*Coth[c + d*x]^2))}
{Sinh[c + d*x]^3/(a + b*Sinh[c + d*x]^2)^2, x, 3, ((a - 2*b)*ArcTan[(Sqrt[b]*Cosh[c + d*x])/Sqrt[a - b]])/(2*(a - b)^(3/2)*b^(3/2)*d) - (a*Cosh[c + d*x])/(2*(a - b)*b*d*(a - b + b*Cosh[c + d*x]^2))}
{Sinh[c + d*x]^2/(a + b*Sinh[c + d*x]^2)^2, x, 3, -ArcTanh[(Sqrt[a]*Coth[c + d*x])/Sqrt[a - b]]/(2*Sqrt[a]*(a - b)^(3/2)*d) - Coth[c + d*x]/(2*(a - b)*d*(a - b - a*Coth[c + d*x]^2))}
{Sinh[c + d*x]/(a + b*Sinh[c + d*x]^2)^2, x, 3, ArcTan[(Sqrt[b]*Cosh[c + d*x])/Sqrt[a - b]]/(2*(a - b)^(3/2)*Sqrt[b]*d) + Cosh[c + d*x]/(2*(a - b)*d*(a - b + b*Cosh[c + d*x]^2))}
{1/(a + b*Sinh[c + d*x]^2)^2, x, 3, -((2*a - b)*ArcTan[(Sqrt[-a + b]*Tanh[c + d*x])/Sqrt[a]])/(2*a^(3/2)*(-a + b)^(3/2)*d) - (b*Tanh[c + d*x])/(2*a*(a - b)*d*(a - (a - b)*Tanh[c + d*x]^2))}
{Csch[c + d*x]/(a + b*Sinh[c + d*x]^2)^2, x, 5, -((3*a - 2*b)*Sqrt[b]*ArcTan[(Sqrt[b]*Cosh[c + d*x])/Sqrt[a - b]])/(2*a^2*(a - b)^(3/2)*d) - ArcTanh[Cosh[c + d*x]]/(a^2*d) - (b*Cosh[c + d*x])/(2*a*(a - b)*d*(a - b + b*Cosh[c + d*x]^2))}
{Csch[c + d*x]^2/(a + b*Sinh[c + d*x]^2)^2, x, 5, -(((4*a - 3*b)*b*ArcTanh[(Sqrt[a]*Coth[c + d*x])/Sqrt[a - b]])/(2*a^(5/2)*(a - b)^(3/2)*d)) - Coth[c + d*x]/(a^2*d) - (b^2*Coth[c + d*x])/(2*a^2*(a - b)*d*(a - b - a*Coth[c + d*x]^2))}
{Csch[c + d*x]^3/(a + b*Sinh[c + d*x]^2)^2, x, 6, ((5*a - 4*b)*b^(3/2)*ArcTan[(Sqrt[b]*Cosh[c + d*x])/Sqrt[a - b]])/(2*a^3*(a - b)^(3/2)*d) + ((a + 4*b)*ArcTanh[Cosh[c + d*x]])/(2*a^3*d) - ((a - 2*b)*b*Cosh[c + d*x])/(2*a^2*(a - b)*d*(a - b + b*Cosh[c + d*x]^2)) + Cosh[c + d*x]/(2*a*d*(1 - Cosh[c + d*x]^2)*(a - b + b*Cosh[c + d*x]^2))}
{Csch[c + d*x]^4/(a + b*Sinh[c + d*x]^2)^2, x, 5, ((6*a - 5*b)*b^2*ArcTanh[(Sqrt[a]*Coth[c + d*x])/Sqrt[a - b]])/(2*a^(7/2)*(a - b)^(3/2)*d) + ((a + 2*b)*Coth[c + d*x])/(a^3*d) - Coth[c + d*x]^3/(3*a^2*d) + (b^3*Coth[c + d*x])/(2*a^3*(a - b)*d*(a - b - a*Coth[c + d*x]^2))}


{Sinh[c + d*x]^4/(a + b*Sinh[c + d*x]^2)^3, x, 4, (3*ArcTanh[(Sqrt[a]*Coth[c + d*x])/Sqrt[a - b]])/(8*Sqrt[a]*(a - b)^(5/2)*d) + Coth[c + d*x]/(4*(a - b)*d*(a - b - a*Coth[c + d*x]^2)^2) + (3*Coth[c + d*x])/(8*(a - b)^2*d*(a - b - a*Coth[c + d*x]^2))}
{Sinh[c + d*x]^3/(a + b*Sinh[c + d*x]^2)^3, x, 4, ((a - 4*b)*ArcTan[(Sqrt[b]*Cosh[c + d*x])/Sqrt[a - b]])/(8*(a - b)^(5/2)*b^(3/2)*d) - (a*Cosh[c + d*x])/(4*(a - b)*b*d*(a - b + b*Cosh[c + d*x]^2)^2) + ((a - 4*b)*Cosh[c + d*x])/(8*(a - b)^2*b*d*(a - b + b*Cosh[c + d*x]^2))}
{Sinh[c + d*x]^2/(a + b*Sinh[c + d*x]^2)^3, x, 4, -((4*a - b)*ArcTanh[(Sqrt[a]*Coth[c + d*x])/Sqrt[a - b]])/(8*a^(3/2)*(a - b)^(5/2)*d) - (b*Coth[c + d*x])/(4*a*(a - b)*d*(a - b - a*Coth[c + d*x]^2)^2) - ((4*a - b)*Coth[c + d*x])/(8*a*(a - b)^2*d*(a - b - a*Coth[c + d*x]^2))}
{Sinh[c + d*x]/(a + b*Sinh[c + d*x]^2)^3, x, 4, (3*ArcTan[(Sqrt[b]*Cosh[c + d*x])/Sqrt[a - b]])/(8*(a - b)^(5/2)*Sqrt[b]*d) + Cosh[c + d*x]/(4*(a - b)*d*(a - b + b*Cosh[c + d*x]^2)^2) + (3*Cosh[c + d*x])/(8*(a - b)^2*d*(a - b + b*Cosh[c + d*x]^2))}
{1/(a + b*Sinh[c + d*x]^2)^3, x, 4, ((8*a^2 - 8*a*b + 3*b^2)*ArcTan[(Sqrt[-a + b]*Tanh[c + d*x])/Sqrt[a]])/(8*a^(5/2)*(-a + b)^(5/2)*d) - (b*Tanh[c + d*x]*(1 - Tanh[c + d*x]^2))/(4*a*(a - b)*d*(a - (a - b)*Tanh[c + d*x]^2)^2) - (3*(2*a - b)*b*Tanh[c + d*x])/(8*a^2*(a - b)^2*d*(a - (a - b)*Tanh[c + d*x]^2))}
{Csch[c + d*x]/(a + b*Sinh[c + d*x]^2)^3, x, 6, -(Sqrt[b]*(15*a^2 - 20*a*b + 8*b^2)*ArcTan[(Sqrt[b]*Cosh[c + d*x])/Sqrt[a - b]])/(8*a^3*(a - b)^(5/2)*d) - ArcTanh[Cosh[c + d*x]]/(a^3*d) - (b*Cosh[c + d*x])/(4*a*(a - b)*d*(a - b + b*Cosh[c + d*x]^2)^2) - ((7*a - 4*b)*b*Cosh[c + d*x])/(8*a^2*(a - b)^2*d*(a - b + b*Cosh[c + d*x]^2))}
{Csch[c + d*x]^2/(a + b*Sinh[c + d*x]^2)^3, x, 6, -((3*b*(8*a^2 - 12*a*b + 5*b^2)*ArcTanh[(Sqrt[a]*Coth[c + d*x])/Sqrt[a - b]])/(8*a^(7/2)*(a - b)^(5/2)*d)) - Coth[c + d*x]/(a^3*d) - (b^3*Coth[c + d*x])/(4*a^3*(a - b)*d*(a - b - a*Coth[c + d*x]^2)^2) - (3*(4*a - 3*b)*b^2*Coth[c + d*x])/(8*a^3*(a - b)^2*d*(a - b - a*Coth[c + d*x]^2))}
{Csch[c + d*x]^3/(a + b*Sinh[c + d*x]^2)^3, x, 7, (b^(3/2)*(35*a^2 - 56*a*b + 24*b^2)*ArcTan[(Sqrt[b]*Cosh[c + d*x])/Sqrt[a - b]])/(8*a^4*(a - b)^(5/2)*d) + ((a + 6*b)*ArcTanh[Cosh[c + d*x]])/(2*a^4*d) - ((2*a - 3*b)*b*Cosh[c + d*x])/(4*a^2*(a - b)*d*(a - b + b*Cosh[c + d*x]^2)^2) + Cosh[c + d*x]/(2*a*d*(1 - Cosh[c + d*x]^2)*(a - b + b*Cosh[c + d*x]^2)^2) - ((a - 4*b)*(4*a - 3*b)*b*Cosh[c + d*x])/(8*a^3*(a - b)^2*d*(a - b + b*Cosh[c + d*x]^2))}
{Csch[c + d*x]^4/(a + b*Sinh[c + d*x]^2)^3, x, 6, (b^2*(48*a^2 - 80*a*b + 35*b^2)*ArcTanh[(Sqrt[a]*Coth[c + d*x])/Sqrt[a - b]])/(8*a^(9/2)*(a - b)^(5/2)*d) + ((a + 3*b)*Coth[c + d*x])/(a^4*d) - Coth[c + d*x]^3/(3*a^3*d) + (b^4*Coth[c + d*x])/(4*a^4*(a - b)*d*(a - b - a*Coth[c + d*x]^2)^2) + ((16*a - 13*b)*b^3*Coth[c + d*x])/(8*a^4*(a - b)^2*d*(a - b - a*Coth[c + d*x]^2))}


{1/(1 + Sinh[x]^2), x, 2, Tanh[x]}
{1/(1 + Sinh[x]^2)^2, x, 3, Tanh[x] - Tanh[x]^3/3}
{1/(1 + Sinh[x]^2)^3, x, 3, Tanh[x] - (2*Tanh[x]^3)/3 + Tanh[x]^5/5}


{1/(1 - Sinh[x]^2), x, 2, ArcTanh[Sqrt[2]*Tanh[x]]/Sqrt[2]}
{1/(1 - Sinh[x]^2)^2, x, 3, (3*ArcTanh[Sqrt[2]*Tanh[x]])/(4*Sqrt[2]) + Tanh[x]/(4*(1 - 2*Tanh[x]^2))}
{1/(1 - Sinh[x]^2)^3, x, 4, (19*ArcTanh[Sqrt[2]*Tanh[x]])/(32*Sqrt[2]) + (9*Tanh[x])/(32*(1 - 2*Tanh[x]^2)) + (Tanh[x]*(1 - Tanh[x]^2))/(8*(1 - 2*Tanh[x]^2)^2)}


{1/Sqrt[1 + Sinh[x]^2], x, 3, (ArcTan[Sinh[x]]*Cosh[x])/Sqrt[Cosh[x]^2]}
{1/Sqrt[1 - Sinh[x]^2], x, 2, (-I)*EllipticF[I*x, -1]}
{1/Sqrt[-1 + Sinh[x]^2], x, 3, -((I*Sqrt[3 - Cosh[2*x]]*EllipticF[I*x, -1])/Sqrt[-3 + Cosh[2*x]])}
{1/Sqrt[-1 - Sinh[x]^2], x, 3, (ArcTan[Sinh[x]]*Cosh[x])/Sqrt[-Cosh[x]^2]}
{1/Sqrt[a + b*Sinh[x]^2], x, 3, -((I*Sqrt[(2*a - b + b*Cosh[2*x])/a]*EllipticF[I*x, b/a])/Sqrt[2*a - b + b*Cosh[2*x]])}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cosh[c+d x]^m (a+b Sinh[c+d x]^2)^n*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Cosh[c + d*x]^4*(a + b*Sinh[c + d*x]^2), x, 7, (3*a*x)/8 - (b*x)/16 + (3*a*Cosh[c + d*x]*Sinh[c + d*x])/(8*d) - (b*Cosh[c + d*x]*Sinh[c + d*x])/(16*d) + (a*Cosh[c + d*x]^3*Sinh[c + d*x])/(4*d) - (b*Cosh[c + d*x]^3*Sinh[c + d*x])/(24*d) + (b*Cosh[c + d*x]^5*Sinh[c + d*x])/(6*d)}
{Cosh[c + d*x]^3*(a + b*Sinh[c + d*x]^2), x, 3, (a*Sinh[c + d*x])/d + ((a + b)*Sinh[c + d*x]^3)/(3*d) + (b*Sinh[c + d*x]^5)/(5*d)}
{Cosh[c + d*x]^2*(a + b*Sinh[c + d*x]^2), x, 5, (a*x)/2 - (b*x)/8 + (a*Cosh[c + d*x]*Sinh[c + d*x])/(2*d) - (b*Cosh[c + d*x]*Sinh[c + d*x])/(8*d) + (b*Cosh[c + d*x]^3*Sinh[c + d*x])/(4*d)}
{Cosh[c + d*x]^1*(a + b*Sinh[c + d*x]^2), x, 2, (a*Sinh[c + d*x])/d + (b*Sinh[c + d*x]^3)/(3*d)}
{Sech[c + d*x]^1*(a + b*Sinh[c + d*x]^2), x, 3, ((a - b)*ArcTan[Sinh[c + d*x]])/d + (b*Sinh[c + d*x])/d}
{Sech[c + d*x]^2*(a + b*Sinh[c + d*x]^2), x, 5, b*x + (a*Tanh[c + d*x])/d - (b*Tanh[c + d*x])/d}
{Sech[c + d*x]^3*(a + b*Sinh[c + d*x]^2), x, 3, ((a + b)*ArcTan[Sinh[c + d*x]])/(2*d) + ((a - b)*Sinh[c + d*x])/(2*d*(1 + Sinh[c + d*x]^2))}
{Sech[c + d*x]^4*(a + b*Sinh[c + d*x]^2), x, 6, (a*Tanh[c + d*x])/d - (a*Tanh[c + d*x]^3)/(3*d) + (b*Tanh[c + d*x]^3)/(3*d)}
{Sech[c + d*x]^5*(a + b*Sinh[c + d*x]^2), x, 4, ((3*a + b)*ArcTan[Sinh[c + d*x]])/(8*d) + ((a - b)*Sinh[c + d*x])/(4*d*(1 + Sinh[c + d*x]^2)^2) + ((3*a + b)*Sinh[c + d*x])/(8*d*(1 + Sinh[c + d*x]^2))}
{Sech[c + d*x]^6*(a + b*Sinh[c + d*x]^2), x, 7, (a*Tanh[c + d*x])/d - (2*a*Tanh[c + d*x]^3)/(3*d) + (b*Tanh[c + d*x]^3)/(3*d) + (a*Tanh[c + d*x]^5)/(5*d) - (b*Tanh[c + d*x]^5)/(5*d)}


{Cosh[c + d*x]^4*(a + b*Sinh[c + d*x]^2)^2, x, 6, (1/128)*(48*a^2 - 16*a*b + 3*b^2)*x + ((10*a - 3*b)*b*Tanh[c + d*x])/(48*d*(1 - Tanh[c + d*x]^2)^3) + ((48*a^2 - 16*a*b + 3*b^2)*Tanh[c + d*x])/(192*d*(1 - Tanh[c + d*x]^2)^2) + ((48*a^2 - 16*a*b + 3*b^2)*Tanh[c + d*x])/(128*d*(1 - Tanh[c + d*x]^2)) + (b*Tanh[c + d*x]*(a - (a - b)*Tanh[c + d*x]^2))/(8*d*(1 - Tanh[c + d*x]^2)^4)}
{Cosh[c + d*x]^3*(a + b*Sinh[c + d*x]^2)^2, x, 3, (a^2*Sinh[c + d*x])/d + (a*(a + 2*b)*Sinh[c + d*x]^3)/(3*d) + (b*(2*a + b)*Sinh[c + d*x]^5)/(5*d) + (b^2*Sinh[c + d*x]^7)/(7*d)}
{Cosh[c + d*x]^2*(a + b*Sinh[c + d*x]^2)^2, x, 5, (1/16)*(8*a^2 - 4*a*b + b^2)*x + ((8*a^2 - 4*a*b + b^2)*Cosh[c + d*x]*Sinh[c + d*x])/(16*d) + ((8*a - 3*b)*b*Cosh[c + d*x]^3*Sinh[c + d*x])/(24*d) + (b*Cosh[c + d*x]^5*Sinh[c + d*x]*(a - (a - b)*Tanh[c + d*x]^2))/(6*d), (1/16)*(8*a^2 - 4*a*b + b^2)*x + ((8*a - 3*b)*b*Tanh[c + d*x])/(24*d*(1 - Tanh[c + d*x]^2)^2) + ((8*a^2 - 4*a*b + b^2)*Tanh[c + d*x])/(16*d*(1 - Tanh[c + d*x]^2)) + (b*Tanh[c + d*x]*(a - (a - b)*Tanh[c + d*x]^2))/(6*d*(1 - Tanh[c + d*x]^2)^3)}
{Cosh[c + d*x]^1*(a + b*Sinh[c + d*x]^2)^2, x, 3, (a^2*Sinh[c + d*x])/d + (2*a*b*Sinh[c + d*x]^3)/(3*d) + (b^2*Sinh[c + d*x]^5)/(5*d)}
{Sech[c + d*x]^1*(a + b*Sinh[c + d*x]^2)^2, x, 4, ((a - b)^2*ArcTan[Sinh[c + d*x]])/d + ((2*a - b)*b*Sinh[c + d*x])/d + (b^2*Sinh[c + d*x]^3)/(3*d)}
{Sech[c + d*x]^2*(a + b*Sinh[c + d*x]^2)^2, x, 5, (1/2)*(4*a - 3*b)*b*x + ((a - b)^2*Tanh[c + d*x])/d + (b^2*Tanh[c + d*x])/(2*d*(1 - Tanh[c + d*x]^2))}
{Sech[c + d*x]^3*(a + b*Sinh[c + d*x]^2)^2, x, 5, ((a - b)*(a + 3*b)*ArcTan[Sinh[c + d*x]])/(2*d) + (b^2*Sinh[c + d*x])/d + ((a - b)^2*Sinh[c + d*x])/(2*d*(1 + Sinh[c + d*x]^2))}
{Sech[c + d*x]^4*(a + b*Sinh[c + d*x]^2)^2, x, 4, b^2*x + ((a^2 - b^2)*Tanh[c + d*x])/d - ((a - b)^2*Tanh[c + d*x]^3)/(3*d)}
{Sech[c + d*x]^5*(a + b*Sinh[c + d*x]^2)^2, x, 4, ((3*a^2 + 2*a*b + 3*b^2)*ArcTan[Sinh[c + d*x]])/(8*d) + (3*(a^2 - b^2)*Sinh[c + d*x])/(8*d*(1 + Sinh[c + d*x]^2)) + ((a - b)*Sinh[c + d*x]*(a + b*Sinh[c + d*x]^2))/(4*d*(1 + Sinh[c + d*x]^2)^2)}
{Sech[c + d*x]^6*(a + b*Sinh[c + d*x]^2)^2, x, 3, (a^2*Tanh[c + d*x])/d - (2*a*(a - b)*Tanh[c + d*x]^3)/(3*d) + ((a - b)^2*Tanh[c + d*x]^5)/(5*d)}
{Sech[c + d*x]^7*(a + b*Sinh[c + d*x]^2)^2, x, 5, ((5*a^2 + 2*a*b + b^2)*ArcTan[Sinh[c + d*x]])/(16*d) + ((a - b)*(5*a + 3*b)*Sinh[c + d*x])/(24*d*(1 + Sinh[c + d*x]^2)^2) + ((5*a^2 + 2*a*b + b^2)*Sinh[c + d*x])/(16*d*(1 + Sinh[c + d*x]^2)) + ((a - b)*Sinh[c + d*x]*(a + b*Sinh[c + d*x]^2))/(6*d*(1 + Sinh[c + d*x]^2)^3)}


{Cosh[c + d*x]^4*(a + b*Sinh[c + d*x]^2)^3, x, 7, (3/256)*(4*a - b)*(8*a^2 - 2*a*b + b^2)*x + (b*(36*a^2 - 20*a*b + 5*b^2)*Tanh[c + d*x])/(160*d*(1 - Tanh[c + d*x]^2)^3) + ((4*a - b)*(8*a^2 - 2*a*b + b^2)*Tanh[c + d*x])/(128*d*(1 - Tanh[c + d*x]^2)^2) + (3*(4*a - b)*(8*a^2 - 2*a*b + b^2)*Tanh[c + d*x])/(256*d*(1 - Tanh[c + d*x]^2)) + ((14*a - 5*b)*b*Tanh[c + d*x]*(a - (a - b)*Tanh[c + d*x]^2))/(80*d*(1 - Tanh[c + d*x]^2)^4) + (b*Tanh[c + d*x]*(a - (a - b)*Tanh[c + d*x]^2)^2)/(10*d*(1 - Tanh[c + d*x]^2)^5)}
{Cosh[c + d*x]^3*(a + b*Sinh[c + d*x]^2)^3, x, 3, (a^3*Sinh[c + d*x])/d + (a^2*(a + 3*b)*Sinh[c + d*x]^3)/(3*d) + (3*a*b*(a + b)*Sinh[c + d*x]^5)/(5*d) + (b^2*(3*a + b)*Sinh[c + d*x]^7)/(7*d) + (b^3*Sinh[c + d*x]^9)/(9*d)}
{Cosh[c + d*x]^2*(a + b*Sinh[c + d*x]^2)^3, x, 6, (1/128)*(64*a^3 - 48*a^2*b + 24*a*b^2 - 5*b^3)*x + (b*(72*a^2 - 52*a*b + 15*b^2)*Tanh[c + d*x])/(192*d*(1 - Tanh[c + d*x]^2)^2) + ((64*a^3 - 48*a^2*b + 24*a*b^2 - 5*b^3)*Tanh[c + d*x])/(128*d*(1 - Tanh[c + d*x]^2)) + ((12*a - 5*b)*b*Tanh[c + d*x]*(a - (a - b)*Tanh[c + d*x]^2))/(48*d*(1 - Tanh[c + d*x]^2)^3) + (b*Tanh[c + d*x]*(a - (a - b)*Tanh[c + d*x]^2)^2)/(8*d*(1 - Tanh[c + d*x]^2)^4)}
{Cosh[c + d*x]^1*(a + b*Sinh[c + d*x]^2)^3, x, 3, (a^3*Sinh[c + d*x])/d + (a^2*b*Sinh[c + d*x]^3)/d + (3*a*b^2*Sinh[c + d*x]^5)/(5*d) + (b^3*Sinh[c + d*x]^7)/(7*d)}
{Sech[c + d*x]^1*(a + b*Sinh[c + d*x]^2)^3, x, 4, ((a - b)^3*ArcTan[Sinh[c + d*x]])/d + (b*(3*a^2 - 3*a*b + b^2)*Sinh[c + d*x])/d + ((3*a - b)*b^2*Sinh[c + d*x]^3)/(3*d) + (b^3*Sinh[c + d*x]^5)/(5*d)}
{Sech[c + d*x]^2*(a + b*Sinh[c + d*x]^2)^3, x, 6, (3/8)*b*(8*a^2 - 12*a*b + 5*b^2)*x + ((a - b)^3*Tanh[c + d*x])/d + (b^3*Tanh[c + d*x])/(4*d*(1 - Tanh[c + d*x]^2)^2) + (3*(4*a - 3*b)*b^2*Tanh[c + d*x])/(8*d*(1 - Tanh[c + d*x]^2))}
{Sech[c + d*x]^3*(a + b*Sinh[c + d*x]^2)^3, x, 5, ((a - b)^2*(a + 5*b)*ArcTan[Sinh[c + d*x]])/(2*d) + ((3*a - 2*b)*b^2*Sinh[c + d*x])/d + (b^3*Sinh[c + d*x]^3)/(3*d) + ((a - b)^3*Sinh[c + d*x])/(2*d*(1 + Sinh[c + d*x]^2))}
{Sech[c + d*x]^4*(a + b*Sinh[c + d*x]^2)^3, x, 5, (1/2)*(6*a - 5*b)*b^2*x + ((a - b)^2*(a + 2*b)*Tanh[c + d*x])/d - ((a - b)^3*Tanh[c + d*x]^3)/(3*d) + (b^3*Tanh[c + d*x])/(2*d*(1 - Tanh[c + d*x]^2))}
{Sech[c + d*x]^5*(a + b*Sinh[c + d*x]^2)^3, x, 6, (3*(a - b)*(4*b^2 + (a + b)^2)*ArcTan[Sinh[c + d*x]])/(8*d) + (b^3*Sinh[c + d*x])/d + ((a - b)^3*Sinh[c + d*x])/(4*d*(1 + Sinh[c + d*x]^2)^2) + (3*(a - b)^2*(a + 3*b)*Sinh[c + d*x])/(8*d*(1 + Sinh[c + d*x]^2))}
{Sech[c + d*x]^6*(a + b*Sinh[c + d*x]^2)^3, x, 4, b^3*x + ((a^3 - b^3)*Tanh[c + d*x])/d - ((a - b)^2*(2*a + b)*Tanh[c + d*x]^3)/(3*d) + ((a - b)^3*Tanh[c + d*x]^5)/(5*d)}
{Sech[c + d*x]^7*(a + b*Sinh[c + d*x]^2)^3, x, 5, ((a + b)*(5*a^2 - 2*a*b + 5*b^2)*ArcTan[Sinh[c + d*x]])/(16*d) + ((a - b)*(15*a^2 + 22*a*b + 15*b^2)*Sinh[c + d*x])/(48*d*(1 + Sinh[c + d*x]^2)) + ((a - b)*Sinh[c + d*x]*(a + b*Sinh[c + d*x]^2)^2)/(6*d*(1 + Sinh[c + d*x]^2)^3) + ((a - b)*Sinh[c + d*x]*(a*(5*a + b) + b*(a + 5*b)*Sinh[c + d*x]^2))/(24*d*(1 + Sinh[c + d*x]^2)^2)}
{Sech[c + d*x]^8*(a + b*Sinh[c + d*x]^2)^3, x, 3, (a^3*Tanh[c + d*x])/d - (a^2*(a - b)*Tanh[c + d*x]^3)/d + (3*a*(a - b)^2*Tanh[c + d*x]^5)/(5*d) - ((a - b)^3*Tanh[c + d*x]^7)/(7*d)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Cosh[c + d*x]^7/(a + b*Sinh[c + d*x]^2), x, 4, -(((a - b)^3*ArcTan[(Sqrt[b]*Sinh[c + d*x])/Sqrt[a]])/(Sqrt[a]*b^(7/2)*d)) + ((a^2 - 3*a*b + 3*b^2)*Sinh[c + d*x])/(b^3*d) - ((a - 3*b)*Sinh[c + d*x]^3)/(3*b^2*d) + Sinh[c + d*x]^5/(5*b*d)}
{Cosh[c + d*x]^6/(a + b*Sinh[c + d*x]^2), x, 6, ((8*a^2 - 20*a*b + 15*b^2)*x)/(8*b^3) + ((-a + b)^(5/2)*ArcTan[(Sqrt[-a + b]*Tanh[c + d*x])/Sqrt[a]])/(Sqrt[a]*b^3*d) + Tanh[c + d*x]/(4*b*d*(1 - Tanh[c + d*x]^2)^2) - ((4*a - 7*b)*Tanh[c + d*x])/(8*b^2*d*(1 - Tanh[c + d*x]^2))}
{Cosh[c + d*x]^5/(a + b*Sinh[c + d*x]^2), x, 4, ((a - b)^2*ArcTan[(Sqrt[b]*Sinh[c + d*x])/Sqrt[a]])/(Sqrt[a]*b^(5/2)*d) - ((a - 2*b)*Sinh[c + d*x])/(b^2*d) + Sinh[c + d*x]^3/(3*b*d)}
{Cosh[c + d*x]^4/(a + b*Sinh[c + d*x]^2), x, 5, -(((2*a - 3*b)*x)/(2*b^2)) + ((-a + b)^(3/2)*ArcTan[(Sqrt[-a + b]*Tanh[c + d*x])/Sqrt[a]])/(Sqrt[a]*b^2*d) + Tanh[c + d*x]/(2*b*d*(1 - Tanh[c + d*x]^2))}
{Cosh[c + d*x]^3/(a + b*Sinh[c + d*x]^2), x, 3, -(((a - b)*ArcTan[(Sqrt[b]*Sinh[c + d*x])/Sqrt[a]])/(Sqrt[a]*b^(3/2)*d)) + Sinh[c + d*x]/(b*d)}
{Cosh[c + d*x]^2/(a + b*Sinh[c + d*x]^2), x, 4, x/b + (Sqrt[-a + b]*ArcTan[(Sqrt[-a + b]*Tanh[c + d*x])/Sqrt[a]])/(Sqrt[a]*b*d)}
{Cosh[c + d*x]^1/(a + b*Sinh[c + d*x]^2), x, 2, ArcTan[(Sqrt[b]*Sinh[c + d*x])/Sqrt[a]]/(Sqrt[a]*Sqrt[b]*d)}
{Sech[c + d*x]^1/(a + b*Sinh[c + d*x]^2), x, 4, ArcTan[Sinh[c + d*x]]/((a - b)*d) - (Sqrt[b]*ArcTan[(Sqrt[b]*Sinh[c + d*x])/Sqrt[a]])/(Sqrt[a]*(a - b)*d)}
{Sech[c + d*x]^2/(a + b*Sinh[c + d*x]^2), x, 3, (b*ArcTan[(Sqrt[-a + b]*Tanh[c + d*x])/Sqrt[a]])/(Sqrt[a]*(-a + b)^(3/2)*d) + Tanh[c + d*x]/((a - b)*d)}
{Sech[c + d*x]^3/(a + b*Sinh[c + d*x]^2), x, 5, ((a - 3*b)*ArcTan[Sinh[c + d*x]])/(2*(a - b)^2*d) + (b^(3/2)*ArcTan[(Sqrt[b]*Sinh[c + d*x])/Sqrt[a]])/(Sqrt[a]*(a - b)^2*d) + Sinh[c + d*x]/(2*(a - b)*d*(1 + Sinh[c + d*x]^2))}
{Sech[c + d*x]^4/(a + b*Sinh[c + d*x]^2), x, 4, (b^2*ArcTan[(Sqrt[-a + b]*Tanh[c + d*x])/Sqrt[a]])/(Sqrt[a]*(-a + b)^(5/2)*d) + ((a - 2*b)*Tanh[c + d*x])/((a - b)^2*d) - Tanh[c + d*x]^3/(3*(a - b)*d)}
{Sech[c + d*x]^5/(a + b*Sinh[c + d*x]^2), x, 6, ((3*a^2 - 10*a*b + 15*b^2)*ArcTan[Sinh[c + d*x]])/(8*(a - b)^3*d) - (b^(5/2)*ArcTan[(Sqrt[b]*Sinh[c + d*x])/Sqrt[a]])/(Sqrt[a]*(a - b)^3*d) + Sinh[c + d*x]/(4*(a - b)*d*(1 + Sinh[c + d*x]^2)^2) + ((3*a - 7*b)*Sinh[c + d*x])/(8*(a - b)^2*d*(1 + Sinh[c + d*x]^2))}
{Sech[c + d*x]^6/(a + b*Sinh[c + d*x]^2), x, 4, (b^3*ArcTan[(Sqrt[-a + b]*Tanh[c + d*x])/Sqrt[a]])/(Sqrt[a]*(-a + b)^(7/2)*d) + ((a^2 - 3*a*b + 3*b^2)*Tanh[c + d*x])/((a - b)^3*d) - ((2*a - 3*b)*Tanh[c + d*x]^3)/(3*(a - b)^2*d) + Tanh[c + d*x]^5/(5*(a - b)*d)}


{Cosh[c + d*x]^6/(a + b*Sinh[c + d*x]^2)^2, x, 6, -(((4*a - 5*b)*x)/(2*b^3)) + ((-a + b)^(3/2)*(4*a + b)*ArcTan[(Sqrt[-a + b]*Tanh[c + d*x])/Sqrt[a]])/(2*a^(3/2)*b^3*d) + ((a - b)*(2*a - b)*Tanh[c + d*x])/(2*a*b^2*d*(a - (a - b)*Tanh[c + d*x]^2)) + Tanh[c + d*x]/(2*b*d*(1 - Tanh[c + d*x]^2)*(a - (a - b)*Tanh[c + d*x]^2))}
{Cosh[c + d*x]^5/(a + b*Sinh[c + d*x]^2)^2, x, 5, -(((3*a^2 - 2*a*b - b^2)*ArcTan[(Sqrt[b]*Sinh[c + d*x])/Sqrt[a]])/(2*a^(3/2)*b^(5/2)*d)) + Sinh[c + d*x]/(b^2*d) + ((a - b)^2*Sinh[c + d*x])/(2*a*b^2*d*(a + b*Sinh[c + d*x]^2))}
{Cosh[c + d*x]^4/(a + b*Sinh[c + d*x]^2)^2, x, 5, x/b^2 + (Sqrt[-a + b]*(2*a + b)*ArcTan[(Sqrt[-a + b]*Tanh[c + d*x])/Sqrt[a]])/(2*a^(3/2)*b^2*d) - ((a - b)*Tanh[c + d*x])/(2*a*b*d*(a - (a - b)*Tanh[c + d*x]^2))}
{Cosh[c + d*x]^3/(a + b*Sinh[c + d*x]^2)^2, x, 3, ((a + b)*ArcTan[(Sqrt[b]*Sinh[c + d*x])/Sqrt[a]])/(2*a^(3/2)*b^(3/2)*d) - ((a - b)*Sinh[c + d*x])/(2*a*b*d*(a + b*Sinh[c + d*x]^2))}
{Cosh[c + d*x]^2/(a + b*Sinh[c + d*x]^2)^2, x, 3, ArcTan[(Sqrt[-a + b]*Tanh[c + d*x])/Sqrt[a]]/(2*a^(3/2)*Sqrt[-a + b]*d) + Tanh[c + d*x]/(2*a*d*(a - (a - b)*Tanh[c + d*x]^2))}
{Cosh[c + d*x]^1/(a + b*Sinh[c + d*x]^2)^2, x, 3, ArcTan[(Sqrt[b]*Sinh[c + d*x])/Sqrt[a]]/(2*a^(3/2)*Sqrt[b]*d) + Sinh[c + d*x]/(2*a*d*(a + b*Sinh[c + d*x]^2))}
{Sech[c + d*x]^1/(a + b*Sinh[c + d*x]^2)^2, x, 5, ArcTan[Sinh[c + d*x]]/((a - b)^2*d) - ((3*a - b)*Sqrt[b]*ArcTan[(Sqrt[b]*Sinh[c + d*x])/Sqrt[a]])/(2*a^(3/2)*(a - b)^2*d) - (b*Sinh[c + d*x])/(2*a*(a - b)*d*(a + b*Sinh[c + d*x]^2))}
{Sech[c + d*x]^2/(a + b*Sinh[c + d*x]^2)^2, x, 5, -(((4*a - b)*b*ArcTan[(Sqrt[-a + b]*Tanh[c + d*x])/Sqrt[a]])/(2*a^(3/2)*(-a + b)^(5/2)*d)) + Tanh[c + d*x]/((a - b)^2*d) + (b^2*Tanh[c + d*x])/(2*a*(a - b)^2*d*(a - (a - b)*Tanh[c + d*x]^2))}
{Sech[c + d*x]^3/(a + b*Sinh[c + d*x]^2)^2, x, 6, ((a - 5*b)*ArcTan[Sinh[c + d*x]])/(2*(a - b)^3*d) + ((5*a - b)*b^(3/2)*ArcTan[(Sqrt[b]*Sinh[c + d*x])/Sqrt[a]])/(2*a^(3/2)*(a - b)^3*d) + (b*(a + b)*Sinh[c + d*x])/(2*a*(a - b)^2*d*(a + b*Sinh[c + d*x]^2)) + Sinh[c + d*x]/(2*(a - b)*d*(1 + Sinh[c + d*x]^2)*(a + b*Sinh[c + d*x]^2))}
{Sech[c + d*x]^4/(a + b*Sinh[c + d*x]^2)^2, x, 5, -(((6*a - b)*b^2*ArcTan[(Sqrt[-a + b]*Tanh[c + d*x])/Sqrt[a]])/(2*a^(3/2)*(-a + b)^(7/2)*d)) + ((a - 3*b)*Tanh[c + d*x])/((a - b)^3*d) - Tanh[c + d*x]^3/(3*(a - b)^2*d) - (b^3*Tanh[c + d*x])/(2*a*(a - b)^3*d*(a - (a - b)*Tanh[c + d*x]^2))}


{Cosh[c + d*x]^6/(a + b*Sinh[c + d*x]^2)^3, x, 6, x/b^3 + (Sqrt[-a + b]*(8*a^2 + 4*a*b + 3*b^2)*ArcTan[(Sqrt[-a + b]*Tanh[c + d*x])/Sqrt[a]])/(8*a^(5/2)*b^3*d) - ((a - b)*Tanh[c + d*x])/(4*a*b*d*(a - (a - b)*Tanh[c + d*x]^2)^2) - ((a - b)*(4*a + 3*b)*Tanh[c + d*x])/(8*a^2*b^2*d*(a - (a - b)*Tanh[c + d*x]^2))}
{Cosh[c + d*x]^5/(a + b*Sinh[c + d*x]^2)^3, x, 4, ((3*a^2 + 2*a*b + 3*b^2)*ArcTan[(Sqrt[b]*Sinh[c + d*x])/Sqrt[a]])/(8*a^(5/2)*b^(5/2)*d) - ((a - b)*Sinh[c + d*x]*(1 + Sinh[c + d*x]^2))/(4*a*b*d*(a + b*Sinh[c + d*x]^2)^2) + (3*(a^(-2) - b^(-2))*Sinh[c + d*x])/(8*d*(a + b*Sinh[c + d*x]^2))}
{Cosh[c + d*x]^4/(a + b*Sinh[c + d*x]^2)^3, x, 4, (3*ArcTan[(Sqrt[-a + b]*Tanh[c + d*x])/Sqrt[a]])/(8*a^(5/2)*Sqrt[-a + b]*d) + Tanh[c + d*x]/(4*a*d*(a - (a - b)*Tanh[c + d*x]^2)^2) + (3*Tanh[c + d*x])/(8*a^2*d*(a - (a - b)*Tanh[c + d*x]^2))}
{Cosh[c + d*x]^3/(a + b*Sinh[c + d*x]^2)^3, x, 4, ((a + 3*b)*ArcTan[(Sqrt[b]*Sinh[c + d*x])/Sqrt[a]])/(8*a^(5/2)*b^(3/2)*d) - ((a - b)*Sinh[c + d*x])/(4*a*b*d*(a + b*Sinh[c + d*x]^2)^2) + ((a + 3*b)*Sinh[c + d*x])/(8*a^2*b*d*(a + b*Sinh[c + d*x]^2))}
{Cosh[c + d*x]^2/(a + b*Sinh[c + d*x]^2)^3, x, 4, -(((4*a - 3*b)*ArcTan[(Sqrt[-a + b]*Tanh[c + d*x])/Sqrt[a]])/(8*a^(5/2)*(-a + b)^(3/2)*d)) - (b*Tanh[c + d*x])/(4*a*(a - b)*d*(a - (a - b)*Tanh[c + d*x]^2)^2) + ((4*a - 3*b)*Tanh[c + d*x])/(8*a^2*(a - b)*d*(a - (a - b)*Tanh[c + d*x]^2))}
{Cosh[c + d*x]^1/(a + b*Sinh[c + d*x]^2)^3, x, 4, (3*ArcTan[(Sqrt[b]*Sinh[c + d*x])/Sqrt[a]])/(8*a^(5/2)*Sqrt[b]*d) + Sinh[c + d*x]/(4*a*d*(a + b*Sinh[c + d*x]^2)^2) + (3*Sinh[c + d*x])/(8*a^2*d*(a + b*Sinh[c + d*x]^2))}
{Sech[c + d*x]^1/(a + b*Sinh[c + d*x]^2)^3, x, 6, ArcTan[Sinh[c + d*x]]/((a - b)^3*d) - (Sqrt[b]*(15*a^2 - 10*a*b + 3*b^2)*ArcTan[(Sqrt[b]*Sinh[c + d*x])/Sqrt[a]])/(8*a^(5/2)*(a - b)^3*d) - (b*Sinh[c + d*x])/(4*a*(a - b)*d*(a + b*Sinh[c + d*x]^2)^2) - ((7*a - 3*b)*b*Sinh[c + d*x])/(8*a^2*(a - b)^2*d*(a + b*Sinh[c + d*x]^2))}
{Sech[c + d*x]^2/(a + b*Sinh[c + d*x]^2)^3, x, 6, (3*b*(8*a^2 - 4*a*b + b^2)*ArcTan[(Sqrt[-a + b]*Tanh[c + d*x])/Sqrt[a]])/(8*a^(5/2)*(-a + b)^(7/2)*d) + Tanh[c + d*x]/((a - b)^3*d) - (b^3*Tanh[c + d*x])/(4*a*(a - b)^3*d*(a - (a - b)*Tanh[c + d*x]^2)^2) + (3*(4*a - b)*b^2*Tanh[c + d*x])/(8*a^2*(a - b)^3*d*(a - (a - b)*Tanh[c + d*x]^2))}
{Sech[c + d*x]^3/(a + b*Sinh[c + d*x]^2)^3, x, 7, ((a - 7*b)*ArcTan[Sinh[c + d*x]])/(2*(a - b)^4*d) + (b^(3/2)*(35*a^2 - 14*a*b + 3*b^2)*ArcTan[(Sqrt[b]*Sinh[c + d*x])/Sqrt[a]])/(8*a^(5/2)*(a - b)^4*d) + (b*(2*a + b)*Sinh[c + d*x])/(4*a*(a - b)^2*d*(a + b*Sinh[c + d*x]^2)^2) + Sinh[c + d*x]/(2*(a - b)*d*(1 + Sinh[c + d*x]^2)*(a + b*Sinh[c + d*x]^2)^2) + ((4*a - b)*b*(a + 3*b)*Sinh[c + d*x])/(8*a^2*(a - b)^3*d*(a + b*Sinh[c + d*x]^2))}
{Sech[c + d*x]^4/(a + b*Sinh[c + d*x]^2)^3, x, 6, (b^2*(48*a^2 - 16*a*b + 3*b^2)*ArcTan[(Sqrt[-a + b]*Tanh[c + d*x])/Sqrt[a]])/(8*a^(5/2)*(-a + b)^(9/2)*d) + ((a - 4*b)*Tanh[c + d*x])/((a - b)^4*d) - Tanh[c + d*x]^3/(3*(a - b)^3*d) + (b^4*Tanh[c + d*x])/(4*a*(a - b)^4*d*(a - (a - b)*Tanh[c + d*x]^2)^2) - ((16*a - 3*b)*b^3*Tanh[c + d*x])/(8*a^2*(a - b)^4*d*(a - (a - b)*Tanh[c + d*x]^2))}


{Cosh[x]^2/(a + a*Sinh[x]^2), x, 2, x/a}
{Cosh[x]^3/(a + a*Sinh[x]^2), x, 2, Sinh[x]/a}
{Cosh[x]^4/(a + a*Sinh[x]^2), x, 2, x/(2*a) + (Cosh[x]*Sinh[x])/(2*a)}


{Cosh[x]^2/(1 - Sinh[x]^2), x, 4, -x + Sqrt[2]*ArcTanh[Sqrt[2]*Tanh[x]]}
{Cosh[x]^3/(1 - Sinh[x]^2), x, 3, 2*ArcTanh[Sinh[x]] - Sinh[x]}
{Cosh[x]^4/(1 - Sinh[x]^2), x, 5, -((5*x)/2) + 2*Sqrt[2]*ArcTanh[Sqrt[2]*Tanh[x]] - Tanh[x]/(2*(1 - Tanh[x]^2))}


(* ::Subsection::Closed:: *)
(*Integrands of the form Tanh[c+d x]^m (a+b Sinh[c+d x]^2)^n*)


(* ::Subsubsection::Closed:: *)
(*n*)


{Coth[x]^1/(1 - Sinh[x]^2), x, 2, -ArcTanh[1 - 2*Sinh[x]^2]}


(* ::Subsubsection::Closed:: *)
(*n/2*)


{Tanh[c + d*x]^5/Sqrt[a + b*Sinh[c + d*x]^2], x, 5, -(((8*a^2 - 8*a*b + 3*b^2)*ArcTanh[Sqrt[a + b*Sinh[c + d*x]^2]/Sqrt[a - b]])/(8*(a - b)^(5/2)*d)) - Sqrt[a + b*Sinh[c + d*x]^2]/(4*(a - b)*d*(1 + Sinh[c + d*x]^2)^2) + ((8*a - 5*b)*Sqrt[a + b*Sinh[c + d*x]^2])/(8*(a - b)^2*d*(1 + Sinh[c + d*x]^2))}
{Tanh[c + d*x]^4/Sqrt[a + b*Sinh[c + d*x]^2], x, 8, (Tanh[c + d*x]*(a - (a - b)*Tanh[c + d*x]^2))/(3*(a - b)*d*Sqrt[(a - (a - b)*Tanh[c + d*x]^2)/(1 - Tanh[c + d*x]^2)]) - (2*(2*a - b)*EllipticE[ArcSin[Tanh[c + d*x]], 1 - b/a]*(a - (a - b)*Tanh[c + d*x]^2))/(3*(a - b)^2*d*Sqrt[1 - Tanh[c + d*x]^2]*Sqrt[(a - (a - b)*Tanh[c + d*x]^2)/a]*Sqrt[(a - (a - b)*Tanh[c + d*x]^2)/(1 - Tanh[c + d*x]^2)]) + (a*(3*a - b)*EllipticF[ArcSin[Tanh[c + d*x]], 1 - b/a]*Sqrt[(a - (a - b)*Tanh[c + d*x]^2)/a])/(3*(a - b)^2*d*Sqrt[1 - Tanh[c + d*x]^2]*Sqrt[(a - (a - b)*Tanh[c + d*x]^2)/(1 - Tanh[c + d*x]^2)])}
{Tanh[c + d*x]^3/Sqrt[a + b*Sinh[c + d*x]^2], x, 4, -(((2*a - b)*ArcTanh[Sqrt[a + b*Sinh[c + d*x]^2]/Sqrt[a - b]])/(2*(a - b)^(3/2)*d)) + Sqrt[a + b*Sinh[c + d*x]^2]/(2*(a - b)*d*(1 + Sinh[c + d*x]^2))}
{Tanh[c + d*x]^2/Sqrt[a + b*Sinh[c + d*x]^2], x, 7, -((EllipticE[ArcSin[Tanh[c + d*x]], 1 - b/a]*(a - (a - b)*Tanh[c + d*x]^2))/((a - b)*d*Sqrt[1 - Tanh[c + d*x]^2]*Sqrt[(a - (a - b)*Tanh[c + d*x]^2)/a]*Sqrt[(a - (a - b)*Tanh[c + d*x]^2)/(1 - Tanh[c + d*x]^2)])) + (a*EllipticF[ArcSin[Tanh[c + d*x]], 1 - b/a]*Sqrt[(a - (a - b)*Tanh[c + d*x]^2)/a])/((a - b)*d*Sqrt[1 - Tanh[c + d*x]^2]*Sqrt[(a - (a - b)*Tanh[c + d*x]^2)/(1 - Tanh[c + d*x]^2)])}
{Tanh[c + d*x]^1/Sqrt[a + b*Sinh[c + d*x]^2], x, 3, -(ArcTanh[Sqrt[a + b*Sinh[c + d*x]^2]/Sqrt[a - b]]/(Sqrt[a - b]*d))}
{Coth[c + d*x]^1/Sqrt[a + b*Sinh[c + d*x]^2], x, 3, -(ArcTanh[Sqrt[a + b*Sinh[c + d*x]^2]/Sqrt[a]]/(Sqrt[a]*d))}
{Coth[c + d*x]^2/Sqrt[a + b*Sinh[c + d*x]^2], x, 9, -((Coth[c + d*x]*(a - (a - b)*Tanh[c + d*x]^2))/(a*d*Sqrt[(a - (a - b)*Tanh[c + d*x]^2)/(1 - Tanh[c + d*x]^2)])) - (EllipticE[ArcSin[Tanh[c + d*x]], 1 - b/a]*(a - (a - b)*Tanh[c + d*x]^2))/(a*d*Sqrt[1 - Tanh[c + d*x]^2]*Sqrt[(a - (a - b)*Tanh[c + d*x]^2)/a]*Sqrt[(a - (a - b)*Tanh[c + d*x]^2)/(1 - Tanh[c + d*x]^2)]) + (EllipticF[ArcSin[Tanh[c + d*x]], 1 - b/a]*Sqrt[(a - (a - b)*Tanh[c + d*x]^2)/a])/(d*Sqrt[1 - Tanh[c + d*x]^2]*Sqrt[(a - (a - b)*Tanh[c + d*x]^2)/(1 - Tanh[c + d*x]^2)])}
{Coth[c + d*x]^3/Sqrt[a + b*Sinh[c + d*x]^2], x, 4, -(((2*a - b)*ArcTanh[Sqrt[a + b*Sinh[c + d*x]^2]/Sqrt[a]])/(2*a^(3/2)*d)) - (Csch[c + d*x]^2*Sqrt[a + b*Sinh[c + d*x]^2])/(2*a*d)}
{Coth[c + d*x]^4/Sqrt[a + b*Sinh[c + d*x]^2], x, 9, -((2*(2*a - b)*Coth[c + d*x]*(a - (a - b)*Tanh[c + d*x]^2))/(3*a^2*d*Sqrt[(a - (a - b)*Tanh[c + d*x]^2)/(1 - Tanh[c + d*x]^2)])) - (Coth[c + d*x]^3*(a - (a - b)*Tanh[c + d*x]^2))/(3*a*d*Sqrt[(a - (a - b)*Tanh[c + d*x]^2)/(1 - Tanh[c + d*x]^2)]) - (2*(2*a - b)*EllipticE[ArcSin[Tanh[c + d*x]], 1 - b/a]*(a - (a - b)*Tanh[c + d*x]^2))/(3*a^2*d*Sqrt[1 - Tanh[c + d*x]^2]*Sqrt[(a - (a - b)*Tanh[c + d*x]^2)/a]*Sqrt[(a - (a - b)*Tanh[c + d*x]^2)/(1 - Tanh[c + d*x]^2)]) + ((3*a - b)*EllipticF[ArcSin[Tanh[c + d*x]], 1 - b/a]*Sqrt[(a - (a - b)*Tanh[c + d*x]^2)/a])/(3*a*d*Sqrt[1 - Tanh[c + d*x]^2]*Sqrt[(a - (a - b)*Tanh[c + d*x]^2)/(1 - Tanh[c + d*x]^2)])}
{Coth[c + d*x]^5/Sqrt[a + b*Sinh[c + d*x]^2], x, 5, -(((8*a^2 - 8*a*b + 3*b^2)*ArcTanh[Sqrt[a + b*Sinh[c + d*x]^2]/Sqrt[a]])/(8*a^(5/2)*d)) - ((8*a - 3*b)*Csch[c + d*x]^2*Sqrt[a + b*Sinh[c + d*x]^2])/(8*a^2*d) - (Csch[c + d*x]^4*Sqrt[a + b*Sinh[c + d*x]^2])/(4*a*d)}


{Coth[x]/Sqrt[1 + Sinh[x]^2], x, 2, -((ArcTanh[Cosh[x]]*Cosh[x])/Sqrt[Cosh[x]^2])}
{Coth[x]/Sqrt[1 - Sinh[x]^2], x, 3, -ArcTanh[Sqrt[1 - Sinh[x]^2]]}


{Coth[x]*Sqrt[a + b*Sinh[x]^2], x, 4, (-Sqrt[a])*ArcTanh[Sqrt[a + b*Sinh[x]^2]/Sqrt[a]] + Sqrt[a + b*Sinh[x]^2]}


(* ::Section::Closed:: *)
(*Integrands of the form Hyper[c+d x]^m (a+b Sinh[c+d x]^3)^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sinh[c+d x]^m (a+b Sinh[c+d x]^3)^n*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Sinh[c + d*x]^4*(a + b*Sinh[c + d*x]^3), x, 6, (3*a*x)/8 - (b*Cosh[c + d*x])/d + (b*Cosh[c + d*x]^3)/d - (3*b*Cosh[c + d*x]^5)/(5*d) + (b*Cosh[c + d*x]^7)/(7*d) - (3*a*Cosh[c + d*x]*Sinh[c + d*x])/(8*d) + (a*Cosh[c + d*x]*Sinh[c + d*x]^3)/(4*d)}
{Sinh[c + d*x]^3*(a + b*Sinh[c + d*x]^3), x, 7, (-5*b*x)/16 - (a*Cosh[c + d*x])/d + (a*Cosh[c + d*x]^3)/(3*d) + (5*b*Cosh[c + d*x]*Sinh[c + d*x])/(16*d) - (5*b*Cosh[c + d*x]*Sinh[c + d*x]^3)/(24*d) + (b*Cosh[c + d*x]*Sinh[c + d*x]^5)/(6*d)}
{Sinh[c + d*x]^2*(a + b*Sinh[c + d*x]^3), x, 5, -(a*x)/2 + (b*Cosh[c + d*x])/d - (2*b*Cosh[c + d*x]^3)/(3*d) + (b*Cosh[c + d*x]^5)/(5*d) + (a*Cosh[c + d*x]*Sinh[c + d*x])/(2*d)}
{Sinh[c + d*x]*(a + b*Sinh[c + d*x]^3), x, 5, (3*b*x)/8 + (a*Cosh[c + d*x])/d - (3*b*Cosh[c + d*x]*Sinh[c + d*x])/(8*d) + (b*Cosh[c + d*x]*Sinh[c + d*x]^3)/(4*d)}
{a + b*Sinh[c + d*x]^3, x, 3, a*x - (b*Cosh[c + d*x])/d + (b*Cosh[c + d*x]^3)/(3*d)}
{Csch[c + d*x]*(a + b*Sinh[c + d*x]^3), x, 4, -(b*x)/2 - (a*ArcTanh[Cosh[c + d*x]])/d + (b*Cosh[c + d*x]*Sinh[c + d*x])/(2*d)}
{Csch[c + d*x]^2*(a + b*Sinh[c + d*x]^3), x, 4, (b*Cosh[c + d*x])/d - (a*Coth[c + d*x])/d}
{Csch[c + d*x]^3*(a + b*Sinh[c + d*x]^3), x, 4, b*x + (a*ArcTanh[Cosh[c + d*x]])/(2*d) - (a*Coth[c + d*x]*Csch[c + d*x])/(2*d)}
{Csch[c + d*x]^4*(a + b*Sinh[c + d*x]^3), x, 5, -((b*ArcTanh[Cosh[c + d*x]])/d) + (a*Coth[c + d*x])/d - (a*Coth[c + d*x]^3)/(3*d)}


{Sinh[c + d*x]^4*(a + b*Sinh[c + d*x]^3)^2, x, 11, (3*a^2*x)/8 - (63*b^2*x)/256 - (2*a*b*Cosh[c + d*x])/d + (2*a*b*Cosh[c + d*x]^3)/d - (6*a*b*Cosh[c + d*x]^5)/(5*d) + (2*a*b*Cosh[c + d*x]^7)/(7*d) - (3*a^2*Cosh[c + d*x]*Sinh[c + d*x])/(8*d) + (63*b^2*Cosh[c + d*x]*Sinh[c + d*x])/(256*d) + (a^2*Cosh[c + d*x]*Sinh[c + d*x]^3)/(4*d) - (21*b^2*Cosh[c + d*x]*Sinh[c + d*x]^3)/(128*d) + (21*b^2*Cosh[c + d*x]*Sinh[c + d*x]^5)/(160*d) - (9*b^2*Cosh[c + d*x]*Sinh[c + d*x]^7)/(80*d) + (b^2*Cosh[c + d*x]*Sinh[c + d*x]^9)/(10*d)}
{Sinh[c + d*x]^3*(a + b*Sinh[c + d*x]^3)^2, x, 9, (-5*a*b*x)/8 - (a^2*Cosh[c + d*x])/d + (b^2*Cosh[c + d*x])/d + (a^2*Cosh[c + d*x]^3)/(3*d) - (4*b^2*Cosh[c + d*x]^3)/(3*d) + (6*b^2*Cosh[c + d*x]^5)/(5*d) - (4*b^2*Cosh[c + d*x]^7)/(7*d) + (b^2*Cosh[c + d*x]^9)/(9*d) + (5*a*b*Cosh[c + d*x]*Sinh[c + d*x])/(8*d) - (5*a*b*Cosh[c + d*x]*Sinh[c + d*x]^3)/(12*d) + (a*b*Cosh[c + d*x]*Sinh[c + d*x]^5)/(3*d)}
{Sinh[c + d*x]^2*(a + b*Sinh[c + d*x]^3)^2, x, 9, -(a^2*x)/2 + (35*b^2*x)/128 + (2*a*b*Cosh[c + d*x])/d - (4*a*b*Cosh[c + d*x]^3)/(3*d) + (2*a*b*Cosh[c + d*x]^5)/(5*d) + (a^2*Cosh[c + d*x]*Sinh[c + d*x])/(2*d) - (35*b^2*Cosh[c + d*x]*Sinh[c + d*x])/(128*d) + (35*b^2*Cosh[c + d*x]*Sinh[c + d*x]^3)/(192*d) - (7*b^2*Cosh[c + d*x]*Sinh[c + d*x]^5)/(48*d) + (b^2*Cosh[c + d*x]*Sinh[c + d*x]^7)/(8*d)}
{Sinh[c + d*x]*(a + b*Sinh[c + d*x]^3)^2, x, 7, (3*a*b*x)/4 + (a^2*Cosh[c + d*x])/d - (b^2*Cosh[c + d*x])/d + (b^2*Cosh[c + d*x]^3)/d - (3*b^2*Cosh[c + d*x]^5)/(5*d) + (b^2*Cosh[c + d*x]^7)/(7*d) - (3*a*b*Cosh[c + d*x]*Sinh[c + d*x])/(4*d) + (a*b*Cosh[c + d*x]*Sinh[c + d*x]^3)/(2*d)}
{(a + b*Sinh[c + d*x]^3)^2, x, 7, a^2*x - (5*b^2*x)/16 - (2*a*b*Cosh[c + d*x])/d + (2*a*b*Cosh[c + d*x]^3)/(3*d) + (5*b^2*Cosh[c + d*x]*Sinh[c + d*x])/(16*d) - (5*b^2*Cosh[c + d*x]*Sinh[c + d*x]^3)/(24*d) + (b^2*Cosh[c + d*x]*Sinh[c + d*x]^5)/(6*d)}
{Csch[c + d*x]*(a + b*Sinh[c + d*x]^3)^2, x, 6, -(a*b*x) - (a^2*ArcTanh[Cosh[c + d*x]])/d + (b^2*Cosh[c + d*x])/d - (2*b^2*Cosh[c + d*x]^3)/(3*d) + (b^2*Cosh[c + d*x]^5)/(5*d) + (a*b*Cosh[c + d*x]*Sinh[c + d*x])/d}
{Csch[c + d*x]^2*(a + b*Sinh[c + d*x]^3)^2, x, 6, (3*b^2*x)/8 + (2*a*b*Cosh[c + d*x])/d - (a^2*Coth[c + d*x])/d - (3*b^2*Cosh[c + d*x]*Sinh[c + d*x])/(8*d) + (b^2*Cosh[c + d*x]*Sinh[c + d*x]^3)/(4*d)}
{Csch[c + d*x]^3*(a + b*Sinh[c + d*x]^3)^2, x, 6, 2*a*b*x + (a^2*ArcTanh[Cosh[c + d*x]])/(2*d) - (b^2*Cosh[c + d*x])/d + (b^2*Cosh[c + d*x]^3)/(3*d) - (a^2*Coth[c + d*x]*Csch[c + d*x])/(2*d)}
{Csch[c + d*x]^4*(a + b*Sinh[c + d*x]^3)^2, x, 6, -(b^2*x)/2 - (2*a*b*ArcTanh[Cosh[c + d*x]])/d + (2*a^2*Coth[c + d*x])/(3*d) - (a^2*Coth[c + d*x]*Csch[c + d*x]^2)/(3*d) + (b^2*Cosh[c + d*x]*Sinh[c + d*x])/(2*d)}


{Sinh[c + d*x]^4*(a + b*Sinh[c + d*x]^3)^3, x, 13, (3*a^3*x)/8 - (189*a*b^2*x)/256 - (3*a^2*b*Cosh[c + d*x])/d + (b^3*Cosh[c + d*x])/d + (3*a^2*b*Cosh[c + d*x]^3)/d - (2*b^3*Cosh[c + d*x]^3)/d - (9*a^2*b*Cosh[c + d*x]^5)/(5*d) + (3*b^3*Cosh[c + d*x]^5)/d + (3*a^2*b*Cosh[c + d*x]^7)/(7*d) - (20*b^3*Cosh[c + d*x]^7)/(7*d) + (5*b^3*Cosh[c + d*x]^9)/(3*d) - (6*b^3*Cosh[c + d*x]^11)/(11*d) + (b^3*Cosh[c + d*x]^13)/(13*d) - (3*a^3*Cosh[c + d*x]*Sinh[c + d*x])/(8*d) + (189*a*b^2*Cosh[c + d*x]*Sinh[c + d*x])/(256*d) + (a^3*Cosh[c + d*x]*Sinh[c + d*x]^3)/(4*d) - (63*a*b^2*Cosh[c + d*x]*Sinh[c + d*x]^3)/(128*d) + (63*a*b^2*Cosh[c + d*x]*Sinh[c + d*x]^5)/(160*d) - (27*a*b^2*Cosh[c + d*x]*Sinh[c + d*x]^7)/(80*d) + (3*a*b^2*Cosh[c + d*x]*Sinh[c + d*x]^9)/(10*d)}
{Sinh[c + d*x]^3*(a + b*Sinh[c + d*x]^3)^3, x, 15, (-15*a^2*b*x)/16 + (231*b^3*x)/1024 - (a^3*Cosh[c + d*x])/d + (3*a*b^2*Cosh[c + d*x])/d + (a^3*Cosh[c + d*x]^3)/(3*d) - (4*a*b^2*Cosh[c + d*x]^3)/d + (18*a*b^2*Cosh[c + d*x]^5)/(5*d) - (12*a*b^2*Cosh[c + d*x]^7)/(7*d) + (a*b^2*Cosh[c + d*x]^9)/(3*d) + (15*a^2*b*Cosh[c + d*x]*Sinh[c + d*x])/(16*d) - (231*b^3*Cosh[c + d*x]*Sinh[c + d*x])/(1024*d) - (5*a^2*b*Cosh[c + d*x]*Sinh[c + d*x]^3)/(8*d) + (77*b^3*Cosh[c + d*x]*Sinh[c + d*x]^3)/(512*d) + (a^2*b*Cosh[c + d*x]*Sinh[c + d*x]^5)/(2*d) - (77*b^3*Cosh[c + d*x]*Sinh[c + d*x]^5)/(640*d) + (33*b^3*Cosh[c + d*x]*Sinh[c + d*x]^7)/(320*d) - (11*b^3*Cosh[c + d*x]*Sinh[c + d*x]^9)/(120*d) + (b^3*Cosh[c + d*x]*Sinh[c + d*x]^11)/(12*d)}
{Sinh[c + d*x]^2*(a + b*Sinh[c + d*x]^3)^3, x, 11, -(a^3*x)/2 + (105*a*b^2*x)/128 + (3*a^2*b*Cosh[c + d*x])/d - (b^3*Cosh[c + d*x])/d - (2*a^2*b*Cosh[c + d*x]^3)/d + (5*b^3*Cosh[c + d*x]^3)/(3*d) + (3*a^2*b*Cosh[c + d*x]^5)/(5*d) - (2*b^3*Cosh[c + d*x]^5)/d + (10*b^3*Cosh[c + d*x]^7)/(7*d) - (5*b^3*Cosh[c + d*x]^9)/(9*d) + (b^3*Cosh[c + d*x]^11)/(11*d) + (a^3*Cosh[c + d*x]*Sinh[c + d*x])/(2*d) - (105*a*b^2*Cosh[c + d*x]*Sinh[c + d*x])/(128*d) + (35*a*b^2*Cosh[c + d*x]*Sinh[c + d*x]^3)/(64*d) - (7*a*b^2*Cosh[c + d*x]*Sinh[c + d*x]^5)/(16*d) + (3*a*b^2*Cosh[c + d*x]*Sinh[c + d*x]^7)/(8*d)}
{Sinh[c + d*x]*(a + b*Sinh[c + d*x]^3)^3, x, 12, (9*a^2*b*x)/8 - (63*b^3*x)/256 + (a^3*Cosh[c + d*x])/d - (3*a*b^2*Cosh[c + d*x])/d + (3*a*b^2*Cosh[c + d*x]^3)/d - (9*a*b^2*Cosh[c + d*x]^5)/(5*d) + (3*a*b^2*Cosh[c + d*x]^7)/(7*d) - (9*a^2*b*Cosh[c + d*x]*Sinh[c + d*x])/(8*d) + (63*b^3*Cosh[c + d*x]*Sinh[c + d*x])/(256*d) + (3*a^2*b*Cosh[c + d*x]*Sinh[c + d*x]^3)/(4*d) - (21*b^3*Cosh[c + d*x]*Sinh[c + d*x]^3)/(128*d) + (21*b^3*Cosh[c + d*x]*Sinh[c + d*x]^5)/(160*d) - (9*b^3*Cosh[c + d*x]*Sinh[c + d*x]^7)/(80*d) + (b^3*Cosh[c + d*x]*Sinh[c + d*x]^9)/(10*d)}
{(a + b*Sinh[c + d*x]^3)^3, x, 9, a^3*x - (15*a*b^2*x)/16 - (3*a^2*b*Cosh[c + d*x])/d + (b^3*Cosh[c + d*x])/d + (a^2*b*Cosh[c + d*x]^3)/d - (4*b^3*Cosh[c + d*x]^3)/(3*d) + (6*b^3*Cosh[c + d*x]^5)/(5*d) - (4*b^3*Cosh[c + d*x]^7)/(7*d) + (b^3*Cosh[c + d*x]^9)/(9*d) + (15*a*b^2*Cosh[c + d*x]*Sinh[c + d*x])/(16*d) - (5*a*b^2*Cosh[c + d*x]*Sinh[c + d*x]^3)/(8*d) + (a*b^2*Cosh[c + d*x]*Sinh[c + d*x]^5)/(2*d)}
{Csch[c + d*x]*(a + b*Sinh[c + d*x]^3)^3, x, 10, (-3*a^2*b*x)/2 + (35*b^3*x)/128 - (a^3*ArcTanh[Cosh[c + d*x]])/d + (3*a*b^2*Cosh[c + d*x])/d - (2*a*b^2*Cosh[c + d*x]^3)/d + (3*a*b^2*Cosh[c + d*x]^5)/(5*d) + (3*a^2*b*Cosh[c + d*x]*Sinh[c + d*x])/(2*d) - (35*b^3*Cosh[c + d*x]*Sinh[c + d*x])/(128*d) + (35*b^3*Cosh[c + d*x]*Sinh[c + d*x]^3)/(192*d) - (7*b^3*Cosh[c + d*x]*Sinh[c + d*x]^5)/(48*d) + (b^3*Cosh[c + d*x]*Sinh[c + d*x]^7)/(8*d)}
{Csch[c + d*x]^2*(a + b*Sinh[c + d*x]^3)^3, x, 8, (9*a*b^2*x)/8 + (3*a^2*b*Cosh[c + d*x])/d - (b^3*Cosh[c + d*x])/d + (b^3*Cosh[c + d*x]^3)/d - (3*b^3*Cosh[c + d*x]^5)/(5*d) + (b^3*Cosh[c + d*x]^7)/(7*d) - (a^3*Coth[c + d*x])/d - (9*a*b^2*Cosh[c + d*x]*Sinh[c + d*x])/(8*d) + (3*a*b^2*Cosh[c + d*x]*Sinh[c + d*x]^3)/(4*d)}
{Csch[c + d*x]^3*(a + b*Sinh[c + d*x]^3)^3, x, 9, 3*a^2*b*x - (5*b^3*x)/16 + (a^3*ArcTanh[Cosh[c + d*x]])/(2*d) - (3*a*b^2*Cosh[c + d*x])/d + (a*b^2*Cosh[c + d*x]^3)/d - (a^3*Coth[c + d*x]*Csch[c + d*x])/(2*d) + (5*b^3*Cosh[c + d*x]*Sinh[c + d*x])/(16*d) - (5*b^3*Cosh[c + d*x]*Sinh[c + d*x]^3)/(24*d) + (b^3*Cosh[c + d*x]*Sinh[c + d*x]^5)/(6*d)}
{Csch[c + d*x]^4*(a + b*Sinh[c + d*x]^3)^3, x, 8, (-3*a*b^2*x)/2 - (3*a^2*b*ArcTanh[Cosh[c + d*x]])/d + (b^3*Cosh[c + d*x])/d - (2*b^3*Cosh[c + d*x]^3)/(3*d) + (b^3*Cosh[c + d*x]^5)/(5*d) + (2*a^3*Coth[c + d*x])/(3*d) - (a^3*Coth[c + d*x]*Csch[c + d*x]^2)/(3*d) + (3*a*b^2*Cosh[c + d*x]*Sinh[c + d*x])/(2*d)}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Sinh[c + d*x]^6/(a + b*Sinh[c + d*x]^3), x, 11, -((a*x)/b^2) - (2*I*a^(4/3)*ArcTan[((-1)^(1/6)*b^(1/3) + I*a^(1/3)*Tanh[(1/2)*(c + d*x)])/Sqrt[a^(2/3) - (-1)^(1/3)*b^(2/3)]])/(3*Sqrt[a^(2/3) - (-1)^(1/3)*b^(2/3)]*b^2*d) - (2*I*a^(4/3)*ArcTan[((-1)^(5/6)*b^(1/3) + I*a^(1/3)*Tanh[(1/2)*(c + d*x)])/Sqrt[a^(2/3) + (-1)^(2/3)*b^(2/3)]])/(3*Sqrt[a^(2/3) + (-1)^(2/3)*b^(2/3)]*b^2*d) - (2*a^(4/3)*ArcTanh[(b^(1/3) - a^(1/3)*Tanh[(1/2)*(c + d*x)])/Sqrt[a^(2/3) + b^(2/3)]])/(3*Sqrt[a^(2/3) + b^(2/3)]*b^2*d) - Cosh[c + d*x]/(b*d) + Cosh[c + d*x]^3/(3*b*d)}
{Sinh[c + d*x]^5/(a + b*Sinh[c + d*x]^3), x, 10, -(x/(2*b)) - (2*(-1)^(1/6)*a*ArcTan[((-1)^(1/6)*b^(1/3) + I*a^(1/3)*Tanh[(1/2)*(c + d*x)])/Sqrt[a^(2/3) - (-1)^(1/3)*b^(2/3)]])/(3*Sqrt[a^(2/3) - (-1)^(1/3)*b^(2/3)]*b^(5/3)*d) - (2*a*ArcTan[(b^(1/3) - (-1)^(2/3)*a^(1/3)*Tanh[(1/2)*(c + d*x)])/Sqrt[(-1)^(1/3)*a^(2/3) - b^(2/3)]])/(3*Sqrt[(-1)^(1/3)*a^(2/3) - b^(2/3)]*b^(5/3)*d) + (2*a*ArcTanh[(b^(1/3) - a^(1/3)*Tanh[(1/2)*(c + d*x)])/Sqrt[a^(2/3) + b^(2/3)]])/(3*Sqrt[a^(2/3) + b^(2/3)]*b^(5/3)*d) + (Cosh[c + d*x]*Sinh[c + d*x])/(2*b*d)}
{Sinh[c + d*x]^4/(a + b*Sinh[c + d*x]^3), x, 10, (2*(-1)^(5/6)*a^(2/3)*ArcTan[((-1)^(1/6)*b^(1/3) + I*a^(1/3)*Tanh[(1/2)*(c + d*x)])/Sqrt[a^(2/3) - (-1)^(1/3)*b^(2/3)]])/(3*Sqrt[a^(2/3) - (-1)^(1/3)*b^(2/3)]*b^(4/3)*d) - (2*a^(2/3)*ArcTanh[(b^(1/3) - a^(1/3)*Tanh[(1/2)*(c + d*x)])/Sqrt[a^(2/3) + b^(2/3)]])/(3*Sqrt[a^(2/3) + b^(2/3)]*b^(4/3)*d) + (2*(-1)^(5/6)*a^(2/3)*ArcTanh[(I*b^(1/3) + (-1)^(1/6)*a^(1/3)*Tanh[(1/2)*(c + d*x)])/Sqrt[(-1)^(1/3)*a^(2/3) - b^(2/3)]])/(3*Sqrt[(-1)^(1/3)*a^(2/3) - b^(2/3)]*b^(4/3)*d) + Cosh[c + d*x]/(b*d)}
{Sinh[c + d*x]^3/(a + b*Sinh[c + d*x]^3), x, 9, x/b + (2*I*a^(1/3)*ArcTan[((-1)^(1/6)*b^(1/3) + I*a^(1/3)*Tanh[(1/2)*(c + d*x)])/Sqrt[a^(2/3) - (-1)^(1/3)*b^(2/3)]])/(3*Sqrt[a^(2/3) - (-1)^(1/3)*b^(2/3)]*b*d) + (2*I*a^(1/3)*ArcTan[((-1)^(5/6)*b^(1/3) + I*a^(1/3)*Tanh[(1/2)*(c + d*x)])/Sqrt[a^(2/3) + (-1)^(2/3)*b^(2/3)]])/(3*Sqrt[a^(2/3) + (-1)^(2/3)*b^(2/3)]*b*d) + (2*a^(1/3)*ArcTanh[(b^(1/3) - a^(1/3)*Tanh[(1/2)*(c + d*x)])/Sqrt[a^(2/3) + b^(2/3)]])/(3*Sqrt[a^(2/3) + b^(2/3)]*b*d)}
{Sinh[c + d*x]^2/(a + b*Sinh[c + d*x]^3), x, 7, (2*(-1)^(1/6)*ArcTan[((-1)^(1/6)*b^(1/3) + I*a^(1/3)*Tanh[(1/2)*(c + d*x)])/Sqrt[a^(2/3) - (-1)^(1/3)*b^(2/3)]])/(3*Sqrt[a^(2/3) - (-1)^(1/3)*b^(2/3)]*b^(2/3)*d) + (2*ArcTan[(b^(1/3) - (-1)^(2/3)*a^(1/3)*Tanh[(1/2)*(c + d*x)])/Sqrt[(-1)^(1/3)*a^(2/3) - b^(2/3)]])/(3*Sqrt[(-1)^(1/3)*a^(2/3) - b^(2/3)]*b^(2/3)*d) - (2*ArcTanh[(b^(1/3) - a^(1/3)*Tanh[(1/2)*(c + d*x)])/Sqrt[a^(2/3) + b^(2/3)]])/(3*Sqrt[a^(2/3) + b^(2/3)]*b^(2/3)*d)}
{Sinh[c + d*x]^1/(a + b*Sinh[c + d*x]^3), x, 7, -((2*(-1)^(5/6)*ArcTan[((-1)^(1/6)*b^(1/3) + I*a^(1/3)*Tanh[(1/2)*(c + d*x)])/Sqrt[a^(2/3) - (-1)^(1/3)*b^(2/3)]])/(3*a^(1/3)*Sqrt[a^(2/3) - (-1)^(1/3)*b^(2/3)]*b^(1/3)*d)) + (2*ArcTanh[(b^(1/3) - a^(1/3)*Tanh[(1/2)*(c + d*x)])/Sqrt[a^(2/3) + b^(2/3)]])/(3*a^(1/3)*Sqrt[a^(2/3) + b^(2/3)]*b^(1/3)*d) - (2*(-1)^(5/6)*ArcTanh[(I*b^(1/3) + (-1)^(1/6)*a^(1/3)*Tanh[(1/2)*(c + d*x)])/Sqrt[(-1)^(1/3)*a^(2/3) - b^(2/3)]])/(3*a^(1/3)*Sqrt[(-1)^(1/3)*a^(2/3) - b^(2/3)]*b^(1/3)*d)}
{Sinh[c + d*x]^0/(a + b*Sinh[c + d*x]^3), x, 7, -((2*I*ArcTan[((-1)^(1/6)*b^(1/3) + I*a^(1/3)*Tanh[(1/2)*(c + d*x)])/Sqrt[a^(2/3) - (-1)^(1/3)*b^(2/3)]])/(3*a^(2/3)*Sqrt[a^(2/3) - (-1)^(1/3)*b^(2/3)]*d)) - (2*I*ArcTan[((-1)^(5/6)*b^(1/3) + I*a^(1/3)*Tanh[(1/2)*(c + d*x)])/Sqrt[a^(2/3) + (-1)^(2/3)*b^(2/3)]])/(3*a^(2/3)*Sqrt[a^(2/3) + (-1)^(2/3)*b^(2/3)]*d) - (2*ArcTanh[(b^(1/3) - a^(1/3)*Tanh[(1/2)*(c + d*x)])/Sqrt[a^(2/3) + b^(2/3)]])/(3*a^(2/3)*Sqrt[a^(2/3) + b^(2/3)]*d)}
{Csch[c + d*x]^1/(a + b*Sinh[c + d*x]^3), x, 10, -((2*(-1)^(1/6)*b^(1/3)*ArcTan[((-1)^(1/6)*b^(1/3) + I*a^(1/3)*Tanh[(1/2)*(c + d*x)])/Sqrt[a^(2/3) - (-1)^(1/3)*b^(2/3)]])/(3*a*Sqrt[a^(2/3) - (-1)^(1/3)*b^(2/3)]*d)) - (2*b^(1/3)*ArcTan[(b^(1/3) - (-1)^(2/3)*a^(1/3)*Tanh[(1/2)*(c + d*x)])/Sqrt[(-1)^(1/3)*a^(2/3) - b^(2/3)]])/(3*a*Sqrt[(-1)^(1/3)*a^(2/3) - b^(2/3)]*d) - ArcTanh[Cosh[c + d*x]]/(a*d) + (2*b^(1/3)*ArcTanh[(b^(1/3) - a^(1/3)*Tanh[(1/2)*(c + d*x)])/Sqrt[a^(2/3) + b^(2/3)]])/(3*a*Sqrt[a^(2/3) + b^(2/3)]*d)}
{Csch[c + d*x]^2/(a + b*Sinh[c + d*x]^3), x, 10, (2*(-1)^(5/6)*b^(2/3)*ArcTan[((-1)^(1/6)*b^(1/3) + I*a^(1/3)*Tanh[(1/2)*(c + d*x)])/Sqrt[a^(2/3) - (-1)^(1/3)*b^(2/3)]])/(3*a^(4/3)*Sqrt[a^(2/3) - (-1)^(1/3)*b^(2/3)]*d) - (2*b^(2/3)*ArcTanh[(b^(1/3) - a^(1/3)*Tanh[(1/2)*(c + d*x)])/Sqrt[a^(2/3) + b^(2/3)]])/(3*a^(4/3)*Sqrt[a^(2/3) + b^(2/3)]*d) + (2*(-1)^(5/6)*b^(2/3)*ArcTanh[(I*b^(1/3) + (-1)^(1/6)*a^(1/3)*Tanh[(1/2)*(c + d*x)])/Sqrt[(-1)^(1/3)*a^(2/3) - b^(2/3)]])/(3*a^(4/3)*Sqrt[(-1)^(1/3)*a^(2/3) - b^(2/3)]*d) - Coth[c + d*x]/(a*d)}
{Csch[c + d*x]^3/(a + b*Sinh[c + d*x]^3), x, 11, (2*I*b*ArcTan[((-1)^(1/6)*b^(1/3) + I*a^(1/3)*Tanh[(1/2)*(c + d*x)])/Sqrt[a^(2/3) - (-1)^(1/3)*b^(2/3)]])/(3*a^(5/3)*Sqrt[a^(2/3) - (-1)^(1/3)*b^(2/3)]*d) + (2*I*b*ArcTan[((-1)^(5/6)*b^(1/3) + I*a^(1/3)*Tanh[(1/2)*(c + d*x)])/Sqrt[a^(2/3) + (-1)^(2/3)*b^(2/3)]])/(3*a^(5/3)*Sqrt[a^(2/3) + (-1)^(2/3)*b^(2/3)]*d) + ArcTanh[Cosh[c + d*x]]/(2*a*d) + (2*b*ArcTanh[(b^(1/3) - a^(1/3)*Tanh[(1/2)*(c + d*x)])/Sqrt[a^(2/3) + b^(2/3)]])/(3*a^(5/3)*Sqrt[a^(2/3) + b^(2/3)]*d) - (Coth[c + d*x]*Csch[c + d*x])/(2*a*d)}
{Csch[c + d*x]^4/(a + b*Sinh[c + d*x]^3), x, 12, (2*(-1)^(1/6)*b^(4/3)*ArcTan[((-1)^(1/6)*b^(1/3) + I*a^(1/3)*Tanh[(1/2)*(c + d*x)])/Sqrt[a^(2/3) - (-1)^(1/3)*b^(2/3)]])/(3*a^2*Sqrt[a^(2/3) - (-1)^(1/3)*b^(2/3)]*d) + (2*b^(4/3)*ArcTan[(b^(1/3) - (-1)^(2/3)*a^(1/3)*Tanh[(1/2)*(c + d*x)])/Sqrt[(-1)^(1/3)*a^(2/3) - b^(2/3)]])/(3*a^2*Sqrt[(-1)^(1/3)*a^(2/3) - b^(2/3)]*d) + (b*ArcTanh[Cosh[c + d*x]])/(a^2*d) - (2*b^(4/3)*ArcTanh[(b^(1/3) - a^(1/3)*Tanh[(1/2)*(c + d*x)])/Sqrt[a^(2/3) + b^(2/3)]])/(3*a^2*Sqrt[a^(2/3) + b^(2/3)]*d) + Coth[c + d*x]/(a*d) - Coth[c + d*x]^3/(3*a*d)}


{1/(1 + Sinh[x]^3), x, 4, -((2*I*ArcTan[((-1)^(1/6) + I*Tanh[x/2])/Sqrt[1 - (-1)^(1/3)]])/(3*Sqrt[1 - (-1)^(1/3)])) - (2*I*ArcTan[((-1)^(5/6) + I*Tanh[x/2])/Sqrt[1 + (-1)^(2/3)]])/(3*Sqrt[1 + (-1)^(2/3)]) - (1/3)*Sqrt[2]*ArcTanh[(1 - Tanh[x/2])/Sqrt[2]]}
{1/(1 - Sinh[x]^3), x, 4, (2*I*ArcTan[((-1)^(1/6) - I*Tanh[x/2])/Sqrt[1 - (-1)^(1/3)]])/(3*Sqrt[1 - (-1)^(1/3)]) + (2*I*ArcTan[((-1)^(5/6) - I*Tanh[x/2])/Sqrt[1 + (-1)^(2/3)]])/(3*Sqrt[1 + (-1)^(2/3)]) + (1/3)*Sqrt[2]*ArcTanh[(1 + Tanh[x/2])/Sqrt[2]]}


(* ::Subsection:: *)
(*Integrands of the form Cosh[c+d x]^m (a+b Sinh[c+d x]^3)^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Tanh[c+d x]^m (a+b Sinh[c+d x]^3)^n*)


{Coth[x]^3/(a + b*Sinh[x]^3), x, 10, (b^(2/3)*ArcTan[(a^(1/3) - 2*b^(1/3)*Sinh[x])/(Sqrt[3]*a^(1/3))])/(Sqrt[3]*a^(5/3)) - Csch[x]^2/(2*a) + Log[Sinh[x]]/a - (b^(2/3)*Log[a^(1/3) + b^(1/3)*Sinh[x]])/(3*a^(5/3)) + (b^(2/3)*Log[a^(2/3) - a^(1/3)*b^(1/3)*Sinh[x] + b^(2/3)*Sinh[x]^2])/(6*a^(5/3)) - Log[a + b*Sinh[x]^3]/(3*a)}


{Coth[x]/Sqrt[a + b*Sinh[x]^3], x, 3, -((2*ArcTanh[Sqrt[a + b*Sinh[x]^3]/Sqrt[a]])/(3*Sqrt[a]))}


{Coth[x]*Sqrt[a + b*Sinh[x]^3], x, 4, (-(2/3))*Sqrt[a]*ArcTanh[Sqrt[a + b*Sinh[x]^3]/Sqrt[a]] + (2/3)*Sqrt[a + b*Sinh[x]^3]}


(* ::Section::Closed:: *)
(*Integrands of the form Hyper[c+d x]^m (a+b Sinh[c+d x]^4)^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sinh[c+d x]^m (a+b Sinh[c+d x]^4)^n*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{Sinh[c + d*x]^4*(a + b*Sinh[c + d*x]^4), x, 8, (3*a*x)/8 + (35*b*x)/128 - (3*a*Cosh[c + d*x]*Sinh[c + d*x])/(8*d) - (35*b*Cosh[c + d*x]*Sinh[c + d*x])/(128*d) + (a*Cosh[c + d*x]*Sinh[c + d*x]^3)/(4*d) + (35*b*Cosh[c + d*x]*Sinh[c + d*x]^3)/(192*d) - (7*b*Cosh[c + d*x]*Sinh[c + d*x]^5)/(48*d) + (b*Cosh[c + d*x]*Sinh[c + d*x]^7)/(8*d)}
{Sinh[c + d*x]^3*(a + b*Sinh[c + d*x]^4), x, 3, -(((a + b)*Cosh[c + d*x])/d) + ((a + 3*b)*Cosh[c + d*x]^3)/(3*d) - (3*b*Cosh[c + d*x]^5)/(5*d) + (b*Cosh[c + d*x]^7)/(7*d)}
{Sinh[c + d*x]^2*(a + b*Sinh[c + d*x]^4), x, 6, -((a*x)/2) - (5*b*x)/16 + (a*Cosh[c + d*x]*Sinh[c + d*x])/(2*d) + (5*b*Cosh[c + d*x]*Sinh[c + d*x])/(16*d) - (5*b*Cosh[c + d*x]*Sinh[c + d*x]^3)/(24*d) + (b*Cosh[c + d*x]*Sinh[c + d*x]^5)/(6*d)}
{Sinh[c + d*x]*(a + b*Sinh[c + d*x]^4), x, 4, (a*Cosh[c + d*x])/d + (b*Cosh[c + d*x])/d - (2*b*Cosh[c + d*x]^3)/(3*d) + (b*Cosh[c + d*x]^5)/(5*d)}
{a + b*Sinh[c + d*x]^4, x, 3, a*x + (3*b*x)/8 - (3*b*Cosh[c + d*x]*Sinh[c + d*x])/(8*d) + (b*Cosh[c + d*x]*Sinh[c + d*x]^3)/(4*d)}
{Csch[c + d*x]*(a + b*Sinh[c + d*x]^4), x, 4, -((a*ArcTanh[Cosh[c + d*x]])/d) - (b*Cosh[c + d*x])/d + (b*Cosh[c + d*x]^3)/(3*d)}
{Csch[c + d*x]^2*(a + b*Sinh[c + d*x]^4), x, 4, -(b*x)/2 - (a*Coth[c + d*x])/d + (b*Cosh[c + d*x]*Sinh[c + d*x])/(2*d)}
{Csch[c + d*x]^3*(a + b*Sinh[c + d*x]^4), x, 4, (a*ArcTanh[Cosh[c + d*x]])/(2*d) + (b*Cosh[c + d*x])/d + (a*Cosh[c + d*x])/(2*d*(1 - Cosh[c + d*x]^2))}
{Csch[c + d*x]^4*(a + b*Sinh[c + d*x]^4), x, 4, b*x + (a*Coth[c + d*x])/d - (a*Coth[c + d*x]^3)/(3*d)}
{Csch[c + d*x]^5*(a + b*Sinh[c + d*x]^4), x, 4, -(((3*a + 8*b)*ArcTanh[Cosh[c + d*x]])/(8*d)) - (a*Cosh[c + d*x])/(4*d*(1 - Cosh[c + d*x]^2)^2) - (3*a*Cosh[c + d*x])/(8*d*(1 - Cosh[c + d*x]^2))}
{Csch[c + d*x]^6*(a + b*Sinh[c + d*x]^4), x, 5, -((a*Coth[c + d*x])/d) - (b*Coth[c + d*x])/d + (2*a*Coth[c + d*x]^3)/(3*d) - (a*Coth[c + d*x]^5)/(5*d)}
{Csch[c + d*x]^7*(a + b*Sinh[c + d*x]^4), x, 5, ((5*a + 8*b)*ArcTanh[Cosh[c + d*x]])/(16*d) + (a*Cosh[c + d*x])/(6*d*(1 - Cosh[c + d*x]^2)^3) + (5*a*Cosh[c + d*x])/(24*d*(1 - Cosh[c + d*x]^2)^2) + ((5*a + 8*b)*Cosh[c + d*x])/(16*d*(1 - Cosh[c + d*x]^2))}


{Sinh[c + d*x]^3*(a + b*Sinh[c + d*x]^4)^2, x, 3, -(((a + b)^2*Cosh[c + d*x])/d) + ((a + b)*(a + 5*b)*Cosh[c + d*x]^3)/(3*d) - (2*b*(3*a + 5*b)*Cosh[c + d*x]^5)/(5*d) + (2*b*(a + 5*b)*Cosh[c + d*x]^7)/(7*d) - (5*b^2*Cosh[c + d*x]^9)/(9*d) + (b^2*Cosh[c + d*x]^11)/(11*d)}
{Sinh[c + d*x]^2*(a + b*Sinh[c + d*x]^4)^2, x, 9, (-(1/256))*(128*a^2 + 160*a*b + 63*b^2)*x - ((28*a^2 + 3*b^2)*Coth[c + d*x])/(30*d*(1 - Coth[c + d*x]^2)^5) + (19*a^2*Coth[c + d*x]^5)/(15*d*(1 - Coth[c + d*x]^2)^5) - (a^2*Coth[c + d*x]^7)/(3*d*(1 - Coth[c + d*x]^2)^5) + ((368*a^2 - 27*b^2)*Coth[c + d*x])/(240*d*(1 - Coth[c + d*x]^2)^4) - ((128*a^2 + 160*a*b + 63*b^2)*Coth[c + d*x])/(480*d*(1 - Coth[c + d*x]^2)^3) - ((128*a^2 + 160*a*b + 63*b^2)*Coth[c + d*x])/(384*d*(1 - Coth[c + d*x]^2)^2) - ((128*a^2 + 160*a*b + 63*b^2)*Coth[c + d*x])/(256*d*(1 - Coth[c + d*x]^2))}
{Sinh[c + d*x]*(a + b*Sinh[c + d*x]^4)^2, x, 3, ((a + b)^2*Cosh[c + d*x])/d - (4*b*(a + b)*Cosh[c + d*x]^3)/(3*d) + (2*b*(a + 3*b)*Cosh[c + d*x]^5)/(5*d) - (4*b^2*Cosh[c + d*x]^7)/(7*d) + (b^2*Cosh[c + d*x]^9)/(9*d)}
{(a + b*Sinh[c + d*x]^4)^2, x, 8, a^2*x + (3*a*b*x)/4 + (35*b^2*x)/128 - (3*a*b*Cosh[c + d*x]*Sinh[c + d*x])/(4*d) - (35*b^2*Cosh[c + d*x]*Sinh[c + d*x])/(128*d) + (a*b*Cosh[c + d*x]*Sinh[c + d*x]^3)/(2*d) + (35*b^2*Cosh[c + d*x]*Sinh[c + d*x]^3)/(192*d) - (7*b^2*Cosh[c + d*x]*Sinh[c + d*x]^5)/(48*d) + (b^2*Cosh[c + d*x]*Sinh[c + d*x]^7)/(8*d)}
{Csch[c + d*x]*(a + b*Sinh[c + d*x]^4)^2, x, 4, -((a^2*ArcTanh[Cosh[c + d*x]])/d) - (b*(2*a + b)*Cosh[c + d*x])/d + (b*(2*a + 3*b)*Cosh[c + d*x]^3)/(3*d) - (3*b^2*Cosh[c + d*x]^5)/(5*d) + (b^2*Cosh[c + d*x]^7)/(7*d)}
{Csch[c + d*x]^2*(a + b*Sinh[c + d*x]^4)^2, x, 4, -(b*(16*a + 5*b)*x)/16 - b^2/(48*d*(1 - Coth[c + d*x])^3) - b^2/(16*d*(1 - Coth[c + d*x])^2) - (b*(16*a + 5*b))/(32*d*(1 - Coth[c + d*x])) - (a^2*Coth[c + d*x])/d + b^2/(48*d*(1 + Coth[c + d*x])^3) + b^2/(16*d*(1 + Coth[c + d*x])^2) + (b*(16*a + 5*b))/(32*d*(1 + Coth[c + d*x]))}
{Csch[c + d*x]^3*(a + b*Sinh[c + d*x]^4)^2, x, 4, (a^2*ArcTanh[Cosh[c + d*x]])/(2*d) + a^2/(4*d*(1 - Cosh[c + d*x])) + (b*(2*a + b)*Cosh[c + d*x])/d - (2*b^2*Cosh[c + d*x]^3)/(3*d) + (b^2*Cosh[c + d*x]^5)/(5*d) - a^2/(4*d*(1 + Cosh[c + d*x]))}
{Csch[c + d*x]^4*(a + b*Sinh[c + d*x]^4)^2, x, 4, (b*(16*a + 3*b)*x)/8 + b^2/(16*d*(1 - Coth[c + d*x])^2) + (3*b^2)/(16*d*(1 - Coth[c + d*x])) + (a^2*Coth[c + d*x])/d - (a^2*Coth[c + d*x]^3)/(3*d) - b^2/(16*d*(1 + Coth[c + d*x])^2) - (3*b^2)/(16*d*(1 + Coth[c + d*x]))}
{Csch[c + d*x]^5*(a + b*Sinh[c + d*x]^4)^2, x, 4, -((a*(3*a + 16*b)*ArcTanh[Cosh[c + d*x]])/(8*d)) - a^2/(16*d*(1 - Cosh[c + d*x])^2) - (3*a^2)/(16*d*(1 - Cosh[c + d*x])) - (b^2*Cosh[c + d*x])/d + (b^2*Cosh[c + d*x]^3)/(3*d) + a^2/(16*d*(1 + Cosh[c + d*x])^2) + (3*a^2)/(16*d*(1 + Cosh[c + d*x]))}
{Csch[c + d*x]^6*(a + b*Sinh[c + d*x]^4)^2, x, 4, -((b^2*x)/2) - b^2/(4*d*(1 - Coth[c + d*x])) - (a*(a + 2*b)*Coth[c + d*x])/d + (2*a^2*Coth[c + d*x]^3)/(3*d) - (a^2*Coth[c + d*x]^5)/(5*d) + b^2/(4*d*(1 + Coth[c + d*x]))}
{Csch[c + d*x]^7*(a + b*Sinh[c + d*x]^4)^2, x, 4, (a*(5*a + 16*b)*ArcTanh[Cosh[c + d*x]])/(16*d) + a^2/(48*d*(1 - Cosh[c + d*x])^3) + a^2/(16*d*(1 - Cosh[c + d*x])^2) + (a*(5*a + 16*b))/(32*d*(1 - Cosh[c + d*x])) + (b^2*Cosh[c + d*x])/d - a^2/(48*d*(1 + Cosh[c + d*x])^3) - a^2/(16*d*(1 + Cosh[c + d*x])^2) - (a*(5*a + 16*b))/(32*d*(1 + Cosh[c + d*x]))}


{Sinh[c + d*x]^3*(a + b*Sinh[c + d*x]^4)^3, x, 3, -(((a + b)^3*Cosh[c + d*x])/d) + ((a + b)^2*(a + 7*b)*Cosh[c + d*x]^3)/(3*d) - (3*b*(a + b)*(3*a + 7*b)*Cosh[c + d*x]^5)/(5*d) + (b*(3*a^2 + 30*a*b + 35*b^2)*Cosh[c + d*x]^7)/(7*d) - (5*b^2*(3*a + 7*b)*Cosh[c + d*x]^9)/(9*d) + (3*b^2*(a + 7*b)*Cosh[c + d*x]^11)/(11*d) - (7*b^3*Cosh[c + d*x]^13)/(13*d) + (b^3*Cosh[c + d*x]^15)/(15*d)}
{Sinh[c + d*x]^2*(a + b*Sinh[c + d*x]^4)^3, x, 13, -(((1024*a^3 + 1920*a^2*b + 1512*a*b^2 + 429*b^3)*x)/2048) - ((352*a^3 + 156*a^2*b + 9*b^3)*Coth[c + d*x])/(126*d*(1 - Coth[c + d*x]^2)^7) + (a^2*(262*a + 75*b)*Coth[c + d*x]^5)/(45*d*(1 - Coth[c + d*x]^2)^7) - (3*a^2*(54*a + 5*b)*Coth[c + d*x]^7)/(35*d*(1 - Coth[c + d*x]^2)^7) + (29*a^3*Coth[c + d*x]^9)/(15*d*(1 - Coth[c + d*x]^2)^7) - (a^3*Coth[c + d*x]^11)/(3*d*(1 - Coth[c + d*x]^2)^7) + ((1928*a^3 + 1032*a^2*b - 39*b^3)*Coth[c + d*x])/(504*d*(1 - Coth[c + d*x]^2)^6) - ((1024*a^3 + 1920*a^2*b + 1512*a*b^2 + 429*b^3)*Coth[c + d*x])/(5040*d*(1 - Coth[c + d*x]^2)^5) - ((1024*a^3 + 1920*a^2*b + 1512*a*b^2 + 429*b^3)*Coth[c + d*x])/(4480*d*(1 - Coth[c + d*x]^2)^4) - ((1024*a^3 + 1920*a^2*b + 1512*a*b^2 + 429*b^3)*Coth[c + d*x])/(3840*d*(1 - Coth[c + d*x]^2)^3) - ((1024*a^3 + 1920*a^2*b + 1512*a*b^2 + 429*b^3)*Coth[c + d*x])/(3072*d*(1 - Coth[c + d*x]^2)^2) - ((1024*a^3 + 1920*a^2*b + 1512*a*b^2 + 429*b^3)*Coth[c + d*x])/(2048*d*(1 - Coth[c + d*x]^2))}
{Sinh[c + d*x]*(a + b*Sinh[c + d*x]^4)^3, x, 3, ((a + b)^3*Cosh[c + d*x])/d - (2*b*(a + b)^2*Cosh[c + d*x]^3)/d + (3*b*(a + b)*(a + 5*b)*Cosh[c + d*x]^5)/(5*d) - (4*b^2*(3*a + 5*b)*Cosh[c + d*x]^7)/(7*d) + (b^2*(a + 5*b)*Cosh[c + d*x]^9)/(3*d) - (6*b^3*Cosh[c + d*x]^11)/(11*d) + (b^3*Cosh[c + d*x]^13)/(13*d)}
{(a + b*Sinh[c + d*x]^4)^3, x, 14, a^3*x + (9/8)*a^2*b*x + (105/128)*a*b^2*x + (231*b^3*x)/1024 - (9*a^2*b*Cosh[c + d*x]*Sinh[c + d*x])/(8*d) - (105*a*b^2*Cosh[c + d*x]*Sinh[c + d*x])/(128*d) - (231*b^3*Cosh[c + d*x]*Sinh[c + d*x])/(1024*d) + (3*a^2*b*Cosh[c + d*x]*Sinh[c + d*x]^3)/(4*d) + (35*a*b^2*Cosh[c + d*x]*Sinh[c + d*x]^3)/(64*d) + (77*b^3*Cosh[c + d*x]*Sinh[c + d*x]^3)/(512*d) - (7*a*b^2*Cosh[c + d*x]*Sinh[c + d*x]^5)/(16*d) - (77*b^3*Cosh[c + d*x]*Sinh[c + d*x]^5)/(640*d) + (3*a*b^2*Cosh[c + d*x]*Sinh[c + d*x]^7)/(8*d) + (33*b^3*Cosh[c + d*x]*Sinh[c + d*x]^7)/(320*d) - (11*b^3*Cosh[c + d*x]*Sinh[c + d*x]^9)/(120*d) + (b^3*Cosh[c + d*x]*Sinh[c + d*x]^11)/(12*d)}
{Csch[c + d*x]*(a + b*Sinh[c + d*x]^4)^3, x, 4, -((a^3*ArcTanh[Cosh[c + d*x]])/d) - (b*(3*a^2 + 3*a*b + b^2)*Cosh[c + d*x])/d + (b*(3*a^2 + 9*a*b + 5*b^2)*Cosh[c + d*x]^3)/(3*d) - (b^2*(9*a + 10*b)*Cosh[c + d*x]^5)/(5*d) + (b^2*(3*a + 10*b)*Cosh[c + d*x]^7)/(7*d) - (5*b^3*Cosh[c + d*x]^9)/(9*d) + (b^3*Cosh[c + d*x]^11)/(11*d)}
{Csch[c + d*x]^2*(a + b*Sinh[c + d*x]^4)^3, x, 4, (-3*b*(128*a^2 + 80*a*b + 21*b^2)*x)/256 - b^3/(320*d*(1 - Coth[c + d*x])^5) - (3*b^3)/(256*d*(1 - Coth[c + d*x])^4) - (b^2*(16*a + 7*b))/(256*d*(1 - Coth[c + d*x])^3) - (b^2*(24*a + 7*b))/(128*d*(1 - Coth[c + d*x])^2) - (3*b*(128*a^2 + 80*a*b + 21*b^2))/(512*d*(1 - Coth[c + d*x])) - (a^3*Coth[c + d*x])/d + b^3/(320*d*(1 + Coth[c + d*x])^5) + (3*b^3)/(256*d*(1 + Coth[c + d*x])^4) + (b^2*(16*a + 7*b))/(256*d*(1 + Coth[c + d*x])^3) + (b^2*(24*a + 7*b))/(128*d*(1 + Coth[c + d*x])^2) + (3*b*(128*a^2 + 80*a*b + 21*b^2))/(512*d*(1 + Coth[c + d*x]))}
{Csch[c + d*x]^3*(a + b*Sinh[c + d*x]^4)^3, x, 4, (a^3*ArcTanh[Cosh[c + d*x]])/(2*d) + a^3/(4*d*(1 - Cosh[c + d*x])) + (b*(3*a^2 + 3*a*b + b^2)*Cosh[c + d*x])/d - (2*b^2*(3*a + 2*b)*Cosh[c + d*x]^3)/(3*d) + (3*b^2*(a + 2*b)*Cosh[c + d*x]^5)/(5*d) - (4*b^3*Cosh[c + d*x]^7)/(7*d) + (b^3*Cosh[c + d*x]^9)/(9*d) - a^3/(4*d*(1 + Cosh[c + d*x]))}
{Csch[c + d*x]^4*(a + b*Sinh[c + d*x]^4)^3, x, 4, (b*(384*a^2 + 144*a*b + 35*b^2)*x)/128 + b^3/(128*d*(1 - Coth[c + d*x])^4) + (5*b^3)/(192*d*(1 - Coth[c + d*x])^3) + (3*b^2*(16*a + 5*b))/(256*d*(1 - Coth[c + d*x])^2) + (b^2*(144*a + 35*b))/(256*d*(1 - Coth[c + d*x])) + (a^3*Coth[c + d*x])/d - (a^3*Coth[c + d*x]^3)/(3*d) - b^3/(128*d*(1 + Coth[c + d*x])^4) - (5*b^3)/(192*d*(1 + Coth[c + d*x])^3) - (3*b^2*(16*a + 5*b))/(256*d*(1 + Coth[c + d*x])^2) - (b^2*(144*a + 35*b))/(256*d*(1 + Coth[c + d*x]))}
{Csch[c + d*x]^5*(a + b*Sinh[c + d*x]^4)^3, x, 4, -((3*a^2*(a + 8*b)*ArcTanh[Cosh[c + d*x]])/(8*d)) - a^3/(16*d*(1 - Cosh[c + d*x])^2) - (3*a^3)/(16*d*(1 - Cosh[c + d*x])) - (b^2*(3*a + b)*Cosh[c + d*x])/d + (b^2*(a + b)*Cosh[c + d*x]^3)/d - (3*b^3*Cosh[c + d*x]^5)/(5*d) + (b^3*Cosh[c + d*x]^7)/(7*d) + a^3/(16*d*(1 + Cosh[c + d*x])^2) + (3*a^3)/(16*d*(1 + Cosh[c + d*x]))}
{Csch[c + d*x]^6*(a + b*Sinh[c + d*x]^4)^3, x, 4, (-(1/16))*b^2*(24*a + 5*b)*x - b^3/(48*d*(1 - Coth[c + d*x])^3) - b^3/(16*d*(1 - Coth[c + d*x])^2) - (b^2*(24*a + 5*b))/(32*d*(1 - Coth[c + d*x])) - (a^2*(a + 3*b)*Coth[c + d*x])/d + (2*a^3*Coth[c + d*x]^3)/(3*d) - (a^3*Coth[c + d*x]^5)/(5*d) + b^3/(48*d*(1 + Coth[c + d*x])^3) + b^3/(16*d*(1 + Coth[c + d*x])^2) + (b^2*(24*a + 5*b))/(32*d*(1 + Coth[c + d*x]))}
{Csch[c + d*x]^7*(a + b*Sinh[c + d*x]^4)^3, x, 4, (a^2*(5*a + 24*b)*ArcTanh[Cosh[c + d*x]])/(16*d) + a^3/(48*d*(1 - Cosh[c + d*x])^3) + a^3/(16*d*(1 - Cosh[c + d*x])^2) + (a^2*(5*a + 24*b))/(32*d*(1 - Cosh[c + d*x])) + (b^2*(3*a + b)*Cosh[c + d*x])/d - (2*b^3*Cosh[c + d*x]^3)/(3*d) + (b^3*Cosh[c + d*x]^5)/(5*d) - a^3/(48*d*(1 + Cosh[c + d*x])^3) - a^3/(16*d*(1 + Cosh[c + d*x])^2) - (a^2*(5*a + 24*b))/(32*d*(1 + Cosh[c + d*x]))}
{Csch[c + d*x]^8*(a + b*Sinh[c + d*x]^4)^3, x, 4, (3/8)*b^2*(8*a + b)*x + b^3/(16*d*(1 - Coth[c + d*x])^2) + (3*b^3)/(16*d*(1 - Coth[c + d*x])) + (a^2*(a + 3*b)*Coth[c + d*x])/d - (a^2*(a + b)*Coth[c + d*x]^3)/d + (3*a^3*Coth[c + d*x]^5)/(5*d) - (a^3*Coth[c + d*x]^7)/(7*d) - b^3/(16*d*(1 + Coth[c + d*x])^2) - (3*b^3)/(16*d*(1 + Coth[c + d*x]))}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Sinh[c + d*x]^4/(a + b*Sinh[c + d*x]^4), x, 7, x/b - (Sqrt[a]*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] - Sqrt[b]])])/(2*(-a)^(1/4)*Sqrt[-Sqrt[-a] - Sqrt[b]]*b*d) + (a^(3/2)*Sqrt[-Sqrt[-a] + Sqrt[b]]*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] + Sqrt[b]])])/(2*(-a)^(3/4)*(a + Sqrt[-a]*Sqrt[b])*b*d)}
{Sinh[c + d*x]^3/(a + b*Sinh[c + d*x]^4), x, 4, ArcTan[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] - Sqrt[b]]]/(2*Sqrt[Sqrt[-a] - Sqrt[b]]*b^(3/4)*d) - ArcTanh[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] + Sqrt[b]]]/(2*Sqrt[Sqrt[-a] + Sqrt[b]]*b^(3/4)*d)}
{Sinh[c + d*x]^2/(a + b*Sinh[c + d*x]^4), x, 4, -((Sqrt[a]*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] - Sqrt[b]])])/(2*(-a)^(3/4)*Sqrt[-Sqrt[-a] - Sqrt[b]]*Sqrt[b]*d)) + (Sqrt[a]*Sqrt[-Sqrt[-a] + Sqrt[b]]*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] + Sqrt[b]])])/(2*(-a)^(1/4)*(a + Sqrt[-a]*Sqrt[b])*Sqrt[b]*d)}
{Sinh[c + d*x]/(a + b*Sinh[c + d*x]^4), x, 4, -ArcTan[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] - Sqrt[b]]]/(2*Sqrt[-a]*Sqrt[Sqrt[-a] - Sqrt[b]]*b^(1/4)*d) - ArcTanh[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] + Sqrt[b]]]/(2*Sqrt[-a]*Sqrt[Sqrt[-a] + Sqrt[b]]*b^(1/4)*d)}
{1/(a + b*Sinh[c + d*x]^4), x, 5, ArcTan[Sqrt[-1 + Sqrt[b]/Sqrt[-a]]*Tanh[c + d*x]]/(2*a*Sqrt[-1 + Sqrt[b]/Sqrt[-a]]*d) + ArcTan[Sqrt[-1 + (a*Sqrt[b])/(-a)^(3/2)]*Tanh[c + d*x]]/(2*a*Sqrt[-1 + (a*Sqrt[b])/(-a)^(3/2)]*d)}
{Csch[c + d*x]/(a + b*Sinh[c + d*x]^4), x, 7, -(b^(1/4)*ArcTan[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] - Sqrt[b]]])/(2*a*Sqrt[Sqrt[-a] - Sqrt[b]]*d) - ArcTanh[Cosh[c + d*x]]/(a*d) + (b^(1/4)*ArcTanh[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] + Sqrt[b]]])/(2*a*Sqrt[Sqrt[-a] + Sqrt[b]]*d)}
{Csch[c + d*x]^2/(a + b*Sinh[c + d*x]^4), x, 6, (Sqrt[b]*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] - Sqrt[b]])])/(2*(-a)^(3/4)*Sqrt[a]*Sqrt[-Sqrt[-a] - Sqrt[b]]*d) - (Sqrt[-Sqrt[-a] + Sqrt[b]]*Sqrt[b]*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] + Sqrt[b]])])/(2*(-a)^(1/4)*Sqrt[a]*(a + Sqrt[-a]*Sqrt[b])*d) - Coth[c + d*x]/(a*d)}
{Csch[c + d*x]^3/(a + b*Sinh[c + d*x]^4), x, 7, -(b^(3/4)*ArcTan[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] - Sqrt[b]]])/(2*(-a)^(3/2)*Sqrt[Sqrt[-a] - Sqrt[b]]*d) + ArcTanh[Cosh[c + d*x]]/(2*a*d) - (b^(3/4)*ArcTanh[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] + Sqrt[b]]])/(2*(-a)^(3/2)*Sqrt[Sqrt[-a] + Sqrt[b]]*d) + 1/(4*a*d*(1 - Cosh[c + d*x])) - 1/(4*a*d*(1 + Cosh[c + d*x]))}
{Csch[c + d*x]^4/(a + b*Sinh[c + d*x]^4), x, 6, -(b*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] - Sqrt[b]])])/(2*(-a)^(1/4)*a^(3/2)*Sqrt[-Sqrt[-a] - Sqrt[b]]*d) + (Sqrt[-Sqrt[-a] + Sqrt[b]]*b*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] + Sqrt[b]])])/(2*(-a)^(3/4)*Sqrt[a]*(a + Sqrt[-a]*Sqrt[b])*d) + Coth[c + d*x]/(a*d) - Coth[c + d*x]^3/(3*a*d)}


{Sinh[c + d*x]^4/(a + b*Sinh[c + d*x]^4)^2, x, 5, (Sqrt[a]*(Sqrt[-a] - Sqrt[b])*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] - Sqrt[b]])])/(8*(-a)^(5/4)*Sqrt[-Sqrt[-a] - Sqrt[b]]*Sqrt[b]*(a + b)*d) + (a^(3/2)*Sqrt[-Sqrt[-a] + Sqrt[b]]*(Sqrt[-a] + Sqrt[b])*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] + Sqrt[b]])])/(8*(-a)^(7/4)*(a + Sqrt[-a]*Sqrt[b])*Sqrt[b]*(a + b)*d) + (Coth[c + d*x]*(2 - Coth[c + d*x]^2))/(4*(a + b)*d*(a + b - 2*a*Coth[c + d*x]^2 + a*Coth[c + d*x]^4))}
{Sinh[c + d*x]^3/(a + b*Sinh[c + d*x]^4)^2, x, 5, ((Sqrt[-a] + Sqrt[b])*ArcTan[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] - Sqrt[b]]])/(8*Sqrt[-a]*Sqrt[Sqrt[-a] - Sqrt[b]]*b^(3/4)*(a + b)*d) - ((Sqrt[-a] - Sqrt[b])*ArcTanh[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] + Sqrt[b]]])/(8*Sqrt[-a]*Sqrt[Sqrt[-a] + Sqrt[b]]*b^(3/4)*(a + b)*d) - (Cosh[c + d*x]*(2 - Cosh[c + d*x]^2))/(4*(a + b)*d*(a + b - 2*b*Cosh[c + d*x]^2 + b*Cosh[c + d*x]^4))}
{Sinh[c + d*x]^2/(a + b*Sinh[c + d*x]^4)^2, x, 6, (Sqrt[a]*(2*a + Sqrt[-a]*Sqrt[b] + b)*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] - Sqrt[b]])])/(8*(-a)^(7/4)*Sqrt[-Sqrt[-a] - Sqrt[b]]*Sqrt[b]*(a + b)*d) - (Sqrt[a]*Sqrt[-Sqrt[-a] + Sqrt[b]]*(2*a - Sqrt[-a]*Sqrt[b] + b)*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] + Sqrt[b]])])/(8*(-a)^(5/4)*(a + Sqrt[-a]*Sqrt[b])*Sqrt[b]*(a + b)*d) + Coth[c + d*x]/(3*a*d*(a + b - 2*a*Coth[c + d*x]^2 + a*Coth[c + d*x]^4)) - (Coth[c + d*x]*(7*a + b - 3*a*Coth[c + d*x]^2))/(12*a*(a + b)*d*(a + b - 2*a*Coth[c + d*x]^2 + a*Coth[c + d*x]^4))}
{Sinh[c + d*x]/(a + b*Sinh[c + d*x]^4)^2, x, 5, ((3*a - Sqrt[-a]*Sqrt[b] + 2*b)*ArcTan[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] - Sqrt[b]]])/(8*(-a)^(3/2)*Sqrt[Sqrt[-a] - Sqrt[b]]*b^(1/4)*(a + b)*d) + ((3*a + Sqrt[-a]*Sqrt[b] + 2*b)*ArcTanh[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] + Sqrt[b]]])/(8*(-a)^(3/2)*Sqrt[Sqrt[-a] + Sqrt[b]]*b^(1/4)*(a + b)*d) + (Cosh[c + d*x]*(a - b + b*Cosh[c + d*x]^2))/(4*a*(a + b)*d*(a + b - 2*b*Cosh[c + d*x]^2 + b*Cosh[c + d*x]^4))}
{1/(a + b*Sinh[c + d*x]^4)^2, x, 7, -((-a)^(3/4)*(4*a + Sqrt[-a]*Sqrt[b] + 3*b)*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] - Sqrt[b]])])/(8*a^(5/2)*Sqrt[-Sqrt[-a] - Sqrt[b]]*(a + b)*d) + ((-a)^(1/4)*Sqrt[-Sqrt[-a] + Sqrt[b]]*(4*a - Sqrt[-a]*Sqrt[b] + 3*b)*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] + Sqrt[b]])])/(8*a^(3/2)*(a + Sqrt[-a]*Sqrt[b])*(a + b)*d) - (5*Coth[c + d*x])/(3*a*d*(a + b - 2*a*Coth[c + d*x]^2 + a*Coth[c + d*x]^4)) + Coth[c + d*x]^3/(a*d*(a + b - 2*a*Coth[c + d*x]^2 + a*Coth[c + d*x]^4)) + (Coth[c + d*x]*(2*(10*a + 7*b) - 3*(4*a + 3*b)*Coth[c + d*x]^2))/(12*a*(a + b)*d*(a + b - 2*a*Coth[c + d*x]^2 + a*Coth[c + d*x]^4))}
{Csch[c + d*x]/(a + b*Sinh[c + d*x]^4)^2, x, 11, -(b^(1/4)*ArcTan[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] - Sqrt[b]]])/(2*a^2*Sqrt[Sqrt[-a] - Sqrt[b]]*d) + ((Sqrt[-a] + Sqrt[b])*b^(1/4)*ArcTan[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] - Sqrt[b]]])/(8*(-a)^(3/2)*Sqrt[Sqrt[-a] - Sqrt[b]]*(a + b)*d) - ArcTanh[Cosh[c + d*x]]/(a^2*d) + (b^(1/4)*ArcTanh[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] + Sqrt[b]]])/(2*a^2*Sqrt[Sqrt[-a] + Sqrt[b]]*d) - ((Sqrt[-a] - Sqrt[b])*b^(1/4)*ArcTanh[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] + Sqrt[b]]])/(8*(-a)^(3/2)*Sqrt[Sqrt[-a] + Sqrt[b]]*(a + b)*d) + (b*Cosh[c + d*x]*(2 - Cosh[c + d*x]^2))/(4*a*(a + b)*d*(a + b - 2*b*Cosh[c + d*x]^2 + b*Cosh[c + d*x]^4))}
{Csch[c + d*x]^2/(a + b*Sinh[c + d*x]^4)^2, x, 10, (Sqrt[b]*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] - Sqrt[b]])])/((-a)^(3/4)*a^(3/2)*Sqrt[-Sqrt[-a] - Sqrt[b]]*d) + ((-a)^(1/4)*Sqrt[b]*(2*a - Sqrt[-a]*Sqrt[b] + 3*b)*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] - Sqrt[b]])])/(8*a^(5/2)*Sqrt[-Sqrt[-a] - Sqrt[b]]*(a + b)*d) - (Sqrt[-Sqrt[-a] + Sqrt[b]]*Sqrt[b]*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] + Sqrt[b]])])/((-a)^(1/4)*a^(3/2)*(a + Sqrt[-a]*Sqrt[b])*d) - ((-a)^(3/4)*Sqrt[-Sqrt[-a] + Sqrt[b]]*Sqrt[b]*(2*a + Sqrt[-a]*Sqrt[b] + 3*b)*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] + Sqrt[b]])])/(8*a^(5/2)*(a + Sqrt[-a]*Sqrt[b])*(a + b)*d) - Coth[c + d*x]/(a^2*d) + (b*Coth[c + d*x]*(a - b - a*Coth[c + d*x]^2))/(4*a^2*(a + b)*d*(a + b - 2*a*Coth[c + d*x]^2 + a*Coth[c + d*x]^4))}
{Csch[c + d*x]^3/(a + b*Sinh[c + d*x]^4)^2, x, 11, (b^(3/4)*ArcTan[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] - Sqrt[b]]])/(2*(-a)^(5/2)*Sqrt[Sqrt[-a] - Sqrt[b]]*d) + (b^(3/4)*(3*a - Sqrt[-a]*Sqrt[b] + 2*b)*ArcTan[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] - Sqrt[b]]])/(8*(-a)^(5/2)*Sqrt[Sqrt[-a] - Sqrt[b]]*(a + b)*d) + ArcTanh[Cosh[c + d*x]]/(2*a^2*d) + (b^(3/4)*ArcTanh[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] + Sqrt[b]]])/(2*(-a)^(5/2)*Sqrt[Sqrt[-a] + Sqrt[b]]*d) + (b^(3/4)*(3*a + Sqrt[-a]*Sqrt[b] + 2*b)*ArcTanh[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] + Sqrt[b]]])/(8*(-a)^(5/2)*Sqrt[Sqrt[-a] + Sqrt[b]]*(a + b)*d) + 1/(4*a^2*d*(1 - Cosh[c + d*x])) - 1/(4*a^2*d*(1 + Cosh[c + d*x])) - (b*Cosh[c + d*x]*(a - b + b*Cosh[c + d*x]^2))/(4*a^2*(a + b)*d*(a + b - 2*b*Cosh[c + d*x]^2 + b*Cosh[c + d*x]^4))}
{Csch[c + d*x]^4/(a + b*Sinh[c + d*x]^4)^2, x, 10, -((b*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] - Sqrt[b]])])/((-a)^(1/4)*a^(5/2)*Sqrt[-Sqrt[-a] - Sqrt[b]]*d)) + ((-a)^(3/4)*(Sqrt[-a] - Sqrt[b])*b^(3/2)*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] - Sqrt[b]])])/(8*a^(7/2)*Sqrt[-Sqrt[-a] - Sqrt[b]]*(a + b)*d) + (Sqrt[-Sqrt[-a] + Sqrt[b]]*b*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] + Sqrt[b]])])/((-a)^(3/4)*a^(3/2)*(a + Sqrt[-a]*Sqrt[b])*d) - (Sqrt[-Sqrt[-a] + Sqrt[b]]*(Sqrt[-a] + Sqrt[b])*b^(3/2)*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] + Sqrt[b]])])/(8*(-a)^(3/4)*a^(3/2)*(a + Sqrt[-a]*Sqrt[b])*(a + b)*d) + Coth[c + d*x]/(a^2*d) - Coth[c + d*x]^3/(3*a^2*d) + (b^2*Coth[c + d*x]*(2 - Coth[c + d*x]^2))/(4*a^2*(a + b)*d*(a + b - 2*a*Coth[c + d*x]^2 + a*Coth[c + d*x]^4))}


{Sinh[c + d*x]^4/(a + b*Sinh[c + d*x]^4)^3, x, 8, (-3*(2*Sqrt[-a]*a - 3*a*Sqrt[b] - b^(3/2))*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] - Sqrt[b]])])/(64*(-a)^(1/4)*a^(3/2)*Sqrt[-Sqrt[-a] - Sqrt[b]]*Sqrt[b]*(a + b)^2*d) - (3*Sqrt[-Sqrt[-a] + Sqrt[b]]*(2*Sqrt[-a]*a + 3*a*Sqrt[b] + b^(3/2))*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] + Sqrt[b]])])/(64*(-a)^(3/4)*Sqrt[a]*(a + Sqrt[-a]*Sqrt[b])*Sqrt[b]*(a + b)^2*d) - (13*Coth[c + d*x])/(35*a*d*(a + b - 2*a*Coth[c + d*x]^2 + a*Coth[c + d*x]^4)^2) + Coth[c + d*x]^3/(5*a*d*(a + b - 2*a*Coth[c + d*x]^2 + a*Coth[c + d*x]^4)^2) + (Coth[c + d*x]*(2*(52*a + 17*b) - 7*(8*a + 3*b)*Coth[c + d*x]^2))/(280*a*(a + b)*d*(a + b - 2*a*Coth[c + d*x]^2 + a*Coth[c + d*x]^4)^2) + (Coth[c + d*x]*(17*a + 5*b - 3*(3*a + b)*Coth[c + d*x]^2))/(32*a*(a + b)^2*d*(a + b - 2*a*Coth[c + d*x]^2 + a*Coth[c + d*x]^4))}
{Sinh[c + d*x]^3/(a + b*Sinh[c + d*x]^4)^3, x, 6, -((5*Sqrt[-a]*a + 8*a*Sqrt[b] - Sqrt[-a]*b + 2*b^(3/2))*ArcTan[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] - Sqrt[b]]])/(64*(-a)^(3/2)*Sqrt[Sqrt[-a] - Sqrt[b]]*b^(3/4)*(a + b)^2*d) + ((5*Sqrt[-a]*a - 8*a*Sqrt[b] - Sqrt[-a]*b - 2*b^(3/2))*ArcTanh[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] + Sqrt[b]]])/(64*(-a)^(3/2)*Sqrt[Sqrt[-a] + Sqrt[b]]*b^(3/4)*(a + b)^2*d) - (Cosh[c + d*x]*(2 - Cosh[c + d*x]^2))/(8*(a + b)*d*(a + b - 2*b*Cosh[c + d*x]^2 + b*Cosh[c + d*x]^4)^2) - (Cosh[c + d*x]*(11*a - b - (5*a - b)*Cosh[c + d*x]^2))/(32*a*(a + b)^2*d*(a + b - 2*b*Cosh[c + d*x]^2 + b*Cosh[c + d*x]^4))}
{Sinh[c + d*x]^2/(a + b*Sinh[c + d*x]^4)^3, x, 9, -(((12*a^2 + 10*Sqrt[-a]*a*Sqrt[b] + 11*a*b + 4*Sqrt[-a]*b^(3/2) + 5*b^2)*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] - Sqrt[b]])])/(64*(-a)^(3/4)*a^(3/2)*Sqrt[-Sqrt[-a] - Sqrt[b]]*Sqrt[b]*(a + b)^2*d)) - ((-a)^(3/4)*Sqrt[-Sqrt[-a] + Sqrt[b]]*(12*a^2 + 10*(-a)^(3/2)*Sqrt[b] + 11*a*b - 4*Sqrt[-a]*b^(3/2) + 5*b^2)*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] + Sqrt[b]])])/(64*a^(5/2)*(a + Sqrt[-a]*Sqrt[b])*Sqrt[b]*(a + b)^2*d) + ((87*a + 25*b)*Coth[c + d*x])/(105*a^2*d*(a + b - 2*a*Coth[c + d*x]^2 + a*Coth[c + d*x]^4)^2) - (14*Coth[c + d*x]^3)/(15*a*d*(a + b - 2*a*Coth[c + d*x]^2 + a*Coth[c + d*x]^4)^2) + Coth[c + d*x]^5/(3*a*d*(a + b - 2*a*Coth[c + d*x]^2 + a*Coth[c + d*x]^4)^2) - (Coth[c + d*x]*(416*a^2 + 231*a*b + 25*b^2 - 7*a*(32*a + 17*b)*Coth[c + d*x]^2))/(840*a^2*(a + b)*d*(a + b - 2*a*Coth[c + d*x]^2 + a*Coth[c + d*x]^4)^2) - (Coth[c + d*x]*(62*a^2 + 31*a*b + 5*b^2 - 6*a*(5*a + 2*b)*Coth[c + d*x]^2))/(96*a^2*(a + b)^2*d*(a + b - 2*a*Coth[c + d*x]^2 + a*Coth[c + d*x]^4))}
{Sinh[c + d*x]/(a + b*Sinh[c + d*x]^4)^3, x, 6, (-3*(7*a^2 + 4*(-a)^(3/2)*Sqrt[b] + 9*a*b - 2*Sqrt[-a]*b^(3/2) + 4*b^2)*ArcTan[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] - Sqrt[b]]])/(64*(-a)^(5/2)*Sqrt[Sqrt[-a] - Sqrt[b]]*b^(1/4)*(a + b)^2*d) - (3*(7*a^2 + 4*Sqrt[-a]*a*Sqrt[b] + 9*a*b + 2*Sqrt[-a]*b^(3/2) + 4*b^2)*ArcTanh[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] + Sqrt[b]]])/(64*(-a)^(5/2)*Sqrt[Sqrt[-a] + Sqrt[b]]*b^(1/4)*(a + b)^2*d) + (Cosh[c + d*x]*(a - b + b*Cosh[c + d*x]^2))/(8*a*(a + b)*d*(a + b - 2*b*Cosh[c + d*x]^2 + b*Cosh[c + d*x]^4)^2) + (Cosh[c + d*x]*((a - 2*b)*(7*a + 3*b) + 6*b*(2*a + b)*Cosh[c + d*x]^2))/(32*a^2*(a + b)^2*d*(a + b - 2*b*Cosh[c + d*x]^2 + b*Cosh[c + d*x]^4))}
{1/(a + b*Sinh[c + d*x]^4)^3, x, 10, ((-a)^(7/4)*(32*a^2 + 14*Sqrt[-a]*a*Sqrt[b] + 47*a*b + 8*Sqrt[-a]*b^(3/2) + 21*b^2)*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] - Sqrt[b]])])/(64*a^(9/2)*Sqrt[-Sqrt[-a] - Sqrt[b]]*(a + b)^2*d) - (Sqrt[-Sqrt[-a] + Sqrt[b]]*(32*a^2 + 14*(-a)^(3/2)*Sqrt[b] + 47*a*b - 8*Sqrt[-a]*b^(3/2) + 21*b^2)*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] + Sqrt[b]])])/(64*(-a)^(3/4)*a^(3/2)*(a + Sqrt[-a]*Sqrt[b])*(a + b)^2*d) - ((279*a + 233*b)*Coth[c + d*x])/(105*a^2*d*(a + b - 2*a*Coth[c + d*x]^2 + a*Coth[c + d*x]^4)^2) + ((73*a + 21*b)*Coth[c + d*x]^3)/(15*a^2*d*(a + b - 2*a*Coth[c + d*x]^2 + a*Coth[c + d*x]^4)^2) - (11*Coth[c + d*x]^5)/(3*a*d*(a + b - 2*a*Coth[c + d*x]^2 + a*Coth[c + d*x]^4)^2) + Coth[c + d*x]^7/(a*d*(a + b - 2*a*Coth[c + d*x]^2 + a*Coth[c + d*x]^4)^2) + (Coth[c + d*x]*(2*(416*a^2 + 648*a*b + 337*b^2) - 7*(64*a^2 + 112*a*b + 63*b^2)*Coth[c + d*x]^2))/(840*a^2*(a + b)*d*(a + b - 2*a*Coth[c + d*x]^2 + a*Coth[c + d*x]^4)^2) + (Coth[c + d*x]*(160*a^2 + 221*a*b + 97*b^2 - 3*(32*a^2 + 47*a*b + 21*b^2)*Coth[c + d*x]^2))/(96*a^2*(a + b)^2*d*(a + b - 2*a*Coth[c + d*x]^2 + a*Coth[c + d*x]^4))}
{Csch[c + d*x]/(a + b*Sinh[c + d*x]^4)^3, x, 16, -(b^(1/4)*ArcTan[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] - Sqrt[b]]])/(2*a^3*Sqrt[Sqrt[-a] - Sqrt[b]]*d) - ((Sqrt[-a] + Sqrt[b])*b^(1/4)*ArcTan[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] - Sqrt[b]]])/(8*(-a)^(5/2)*Sqrt[Sqrt[-a] - Sqrt[b]]*(a + b)*d) - (b^(1/4)*(5*Sqrt[-a]*a + 8*a*Sqrt[b] - Sqrt[-a]*b + 2*b^(3/2))*ArcTan[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] - Sqrt[b]]])/(64*(-a)^(5/2)*Sqrt[Sqrt[-a] - Sqrt[b]]*(a + b)^2*d) - ArcTanh[Cosh[c + d*x]]/(a^3*d) + (b^(1/4)*ArcTanh[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] + Sqrt[b]]])/(2*a^3*Sqrt[Sqrt[-a] + Sqrt[b]]*d) + ((Sqrt[-a] - Sqrt[b])*b^(1/4)*ArcTanh[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] + Sqrt[b]]])/(8*(-a)^(5/2)*Sqrt[Sqrt[-a] + Sqrt[b]]*(a + b)*d) - (b^(1/4)*(5*(-a)^(3/2) + 8*a*Sqrt[b] + Sqrt[-a]*b + 2*b^(3/2))*ArcTanh[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] + Sqrt[b]]])/(64*(-a)^(5/2)*Sqrt[Sqrt[-a] + Sqrt[b]]*(a + b)^2*d) + (b*Cosh[c + d*x]*(2 - Cosh[c + d*x]^2))/(8*a*(a + b)*d*(a + b - 2*b*Cosh[c + d*x]^2 + b*Cosh[c + d*x]^4)^2) + (b*Cosh[c + d*x]*(2 - Cosh[c + d*x]^2))/(4*a^2*(a + b)*d*(a + b - 2*b*Cosh[c + d*x]^2 + b*Cosh[c + d*x]^4)) + (b*Cosh[c + d*x]*(11*a - b - (5*a - b)*Cosh[c + d*x]^2))/(32*a^2*(a + b)^2*d*(a + b - 2*b*Cosh[c + d*x]^2 + b*Cosh[c + d*x]^4))}
{Csch[c + d*x]^2/(a + b*Sinh[c + d*x]^4)^3, x, 15, (3*Sqrt[b]*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] - Sqrt[b]])])/(2*(-a)^(3/4)*a^(5/2)*Sqrt[-Sqrt[-a] - Sqrt[b]]*d) + (3*(-a)^(1/4)*Sqrt[b]*(2*a - Sqrt[-a]*Sqrt[b] + 3*b)*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] - Sqrt[b]])])/(8*a^(7/2)*Sqrt[-Sqrt[-a] - Sqrt[b]]*(a + b)*d) + (3*Sqrt[b]*(4*a^2 + 2*(-a)^(3/2)*Sqrt[b] + 9*a*b - 4*Sqrt[-a]*b^(3/2) + 7*b^2)*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] - Sqrt[b]])])/(64*(-a)^(3/4)*a^(5/2)*Sqrt[-Sqrt[-a] - Sqrt[b]]*(a + b)^2*d) - (3*Sqrt[-Sqrt[-a] + Sqrt[b]]*Sqrt[b]*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] + Sqrt[b]])])/(2*(-a)^(1/4)*a^(5/2)*(a + Sqrt[-a]*Sqrt[b])*d) - (3*(-a)^(3/4)*Sqrt[-Sqrt[-a] + Sqrt[b]]*Sqrt[b]*(2*a + Sqrt[-a]*Sqrt[b] + 3*b)*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] + Sqrt[b]])])/(8*a^(7/2)*(a + Sqrt[-a]*Sqrt[b])*(a + b)*d) - (3*Sqrt[-Sqrt[-a] + Sqrt[b]]*Sqrt[b]*(4*a^2 + 2*Sqrt[-a]*a*Sqrt[b] + 9*a*b + 4*Sqrt[-a]*b^(3/2) + 7*b^2)*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] + Sqrt[b]])])/(64*(-a)^(1/4)*a^(5/2)*(a + Sqrt[-a]*Sqrt[b])*(a + b)^2*d) - Coth[c + d*x]/(a^3*d) - (b^2*Coth[c + d*x]*(a - b - a*Coth[c + d*x]^2))/(8*a^3*(a + b)*d*(a + b - 2*a*Coth[c + d*x]^2 + a*Coth[c + d*x]^4)^2) + (3*b*Coth[c + d*x]*(a - b - a*Coth[c + d*x]^2))/(4*a^3*(a + b)*d*(a + b - 2*a*Coth[c + d*x]^2 + a*Coth[c + d*x]^4)) - (b*Coth[c + d*x]*((2*a - b)*(3*a + 7*b) - 6*a*(a + 2*b)*Coth[c + d*x]^2))/(32*a^3*(a + b)^2*d*(a + b - 2*a*Coth[c + d*x]^2 + a*Coth[c + d*x]^4))}
{Csch[c + d*x]^3/(a + b*Sinh[c + d*x]^4)^3, x, 16, -(b^(3/4)*ArcTan[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] - Sqrt[b]]])/(2*(-a)^(7/2)*Sqrt[Sqrt[-a] - Sqrt[b]]*d) - (b^(3/4)*(3*a - Sqrt[-a]*Sqrt[b] + 2*b)*ArcTan[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] - Sqrt[b]]])/(8*(-a)^(7/2)*Sqrt[Sqrt[-a] - Sqrt[b]]*(a + b)*d) - (3*b^(3/4)*(7*a^2 + 4*(-a)^(3/2)*Sqrt[b] + 9*a*b - 2*Sqrt[-a]*b^(3/2) + 4*b^2)*ArcTan[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] - Sqrt[b]]])/(64*(-a)^(7/2)*Sqrt[Sqrt[-a] - Sqrt[b]]*(a + b)^2*d) + ArcTanh[Cosh[c + d*x]]/(2*a^3*d) - (b^(3/4)*ArcTanh[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] + Sqrt[b]]])/(2*(-a)^(7/2)*Sqrt[Sqrt[-a] + Sqrt[b]]*d) - (b^(3/4)*(3*a + Sqrt[-a]*Sqrt[b] + 2*b)*ArcTanh[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] + Sqrt[b]]])/(8*(-a)^(7/2)*Sqrt[Sqrt[-a] + Sqrt[b]]*(a + b)*d) - (3*b^(3/4)*(7*a^2 + 4*Sqrt[-a]*a*Sqrt[b] + 9*a*b + 2*Sqrt[-a]*b^(3/2) + 4*b^2)*ArcTanh[(b^(1/4)*Cosh[c + d*x])/Sqrt[Sqrt[-a] + Sqrt[b]]])/(64*(-a)^(7/2)*Sqrt[Sqrt[-a] + Sqrt[b]]*(a + b)^2*d) + 1/(4*a^3*d*(1 - Cosh[c + d*x])) - 1/(4*a^3*d*(1 + Cosh[c + d*x])) - (b*Cosh[c + d*x]*(a - b + b*Cosh[c + d*x]^2))/(8*a^2*(a + b)*d*(a + b - 2*b*Cosh[c + d*x]^2 + b*Cosh[c + d*x]^4)^2) - (b*Cosh[c + d*x]*(a - b + b*Cosh[c + d*x]^2))/(4*a^3*(a + b)*d*(a + b - 2*b*Cosh[c + d*x]^2 + b*Cosh[c + d*x]^4)) - (b*Cosh[c + d*x]*((a - 2*b)*(7*a + 3*b) + 6*b*(2*a + b)*Cosh[c + d*x]^2))/(32*a^3*(a + b)^2*d*(a + b - 2*b*Cosh[c + d*x]^2 + b*Cosh[c + d*x]^4))}
{Csch[c + d*x]^4/(a + b*Sinh[c + d*x]^4)^3, x, 15, (-3*b*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] - Sqrt[b]])])/(2*(-a)^(1/4)*a^(7/2)*Sqrt[-Sqrt[-a] - Sqrt[b]]*d) + (3*(-a)^(3/4)*(Sqrt[-a] - Sqrt[b])*b^(3/2)*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] - Sqrt[b]])])/(8*a^(9/2)*Sqrt[-Sqrt[-a] - Sqrt[b]]*(a + b)*d) + (b^(3/2)*(a*(2*Sqrt[-a] + Sqrt[b]) + 8*Sqrt[-a]*b - 5*b^(3/2))*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] - Sqrt[b]])])/(64*(-a)^(1/4)*a^(7/2)*Sqrt[-Sqrt[-a] - Sqrt[b]]*(a + b)^2*d) + (3*Sqrt[-Sqrt[-a] + Sqrt[b]]*b*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] + Sqrt[b]])])/(2*(-a)^(3/4)*a^(5/2)*(a + Sqrt[-a]*Sqrt[b])*d) - (3*Sqrt[-Sqrt[-a] + Sqrt[b]]*(Sqrt[-a] + Sqrt[b])*b^(3/2)*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] + Sqrt[b]])])/(8*(-a)^(3/4)*a^(5/2)*(a + Sqrt[-a]*Sqrt[b])*(a + b)*d) + (Sqrt[-Sqrt[-a] + Sqrt[b]]*b^(3/2)*(2*Sqrt[-a]*a - a*Sqrt[b] + 8*Sqrt[-a]*b + 5*b^(3/2))*ArcTanh[(Sqrt[a]*Coth[c + d*x])/((-a)^(1/4)*Sqrt[-Sqrt[-a] + Sqrt[b]])])/(64*(-a)^(3/4)*a^(5/2)*(a + Sqrt[-a]*Sqrt[b])*(a + b)^2*d) + Coth[c + d*x]/(a^3*d) - Coth[c + d*x]^3/(3*a^3*d) - (b^3*Coth[c + d*x]*(2 - Coth[c + d*x]^2))/(8*a^3*(a + b)*d*(a + b - 2*a*Coth[c + d*x]^2 + a*Coth[c + d*x]^4)^2) + (3*b^2*Coth[c + d*x]*(2 - Coth[c + d*x]^2))/(4*a^3*(a + b)*d*(a + b - 2*a*Coth[c + d*x]^2 + a*Coth[c + d*x]^4)) + (b^2*Coth[c + d*x]*(a - 11*b - (a - 5*b)*Coth[c + d*x]^2))/(32*a^3*(a + b)^2*d*(a + b - 2*a*Coth[c + d*x]^2 + a*Coth[c + d*x]^4))}


{1/(1 + Sinh[x]^4), x, 5, (1/2)*Sqrt[1/2 - I/2]*ArcTanh[Tanh[x]/Sqrt[1/2 - I/2]] + (1/2)*Sqrt[1/2 + I/2]*ArcTanh[Tanh[x]/Sqrt[1/2 + I/2]]}
{1/(1 - Sinh[x]^4), x, 5, ArcTanh[Sqrt[2]*Tanh[x]]/(2*Sqrt[2]) + Tanh[x]/2}


(* ::Subsection:: *)
(*Integrands of the form Cosh[c+d x]^m (a+b Sinh[c+d x]^4)^n*)


(* ::Subsection:: *)
(*Integrands of the form Tanh[c+d x]^m (a+b Sinh[c+d x]^4)^n*)


(* ::Section::Closed:: *)
(*Integrands of the form Hyper[c+d x]^m (a+b Sinh[c+d x]^n)^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sinh[c+d x]^m (a+b Sinh[c+d x]^n)^p*)


{1/(a + b*Sinh[x]^5), x, 11, (2*I*ArcTan[((-1)^(1/10)*b^(1/5) - I*a^(1/5)*Tanh[x/2])/Sqrt[a^(2/5) - (-1)^(1/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) - (-1)^(1/5)*b^(2/5)]) + (2*I*ArcTan[((-1)^(9/10)*b^(1/5) - I*a^(1/5)*Tanh[x/2])/Sqrt[a^(2/5) + (-1)^(4/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) + (-1)^(4/5)*b^(2/5)]) - (2*I*ArcTan[((-1)^(3/10)*b^(1/5) + I*a^(1/5)*Tanh[x/2])/Sqrt[a^(2/5) - (-1)^(3/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) - (-1)^(3/5)*b^(2/5)]) - (2*I*ArcTan[((-1)^(7/10)*b^(1/5) + I*a^(1/5)*Tanh[x/2])/Sqrt[a^(2/5) + (-1)^(2/5)*b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) + (-1)^(2/5)*b^(2/5)]) - (2*ArcTanh[(b^(1/5) - a^(1/5)*Tanh[x/2])/Sqrt[a^(2/5) + b^(2/5)]])/(5*a^(4/5)*Sqrt[a^(2/5) + b^(2/5)])}
{1/(a + b*Sinh[x]^6), x, 7, ArcTan[Sqrt[-1 + b^(1/3)/a^(1/3)]*Tanh[x]]/(3*a*Sqrt[-1 + b^(1/3)/a^(1/3)]) + ArcTan[Sqrt[-1 - ((-1)^(1/3)*b^(1/3))/a^(1/3)]*Tanh[x]]/(3*a*Sqrt[-1 - ((-1)^(1/3)*b^(1/3))/a^(1/3)]) + ArcTan[Sqrt[-1 + ((-1)^(2/3)*b^(1/3))/a^(1/3)]*Tanh[x]]/(3*a*Sqrt[-1 + ((-1)^(2/3)*b^(1/3))/a^(1/3)])}
{1/(a + b*Sinh[x]^8), x, 9, ArcTan[Sqrt[-1 - (I*b^(1/4))/(-a)^(1/4)]*Tanh[x]]/(4*a*Sqrt[-1 - (I*b^(1/4))/(-a)^(1/4)]) + ArcTan[Sqrt[-1 + (I*b^(1/4))/(-a)^(1/4)]*Tanh[x]]/(4*a*Sqrt[-1 + (I*b^(1/4))/(-a)^(1/4)]) + ArcTan[Sqrt[-1 + b^(1/4)/(-a)^(1/4)]*Tanh[x]]/(4*a*Sqrt[-1 + b^(1/4)/(-a)^(1/4)]) + ArcTan[Sqrt[-1 + (a*b^(1/4))/(-a)^(5/4)]*Tanh[x]]/(4*a*Sqrt[-1 + (a*b^(1/4))/(-a)^(5/4)])}


{1/(1 + Sinh[x]^5), x, 6, (2*I*ArcTan[((-1)^(1/10) - I*Tanh[x/2])/Sqrt[1 - (-1)^(1/5)]])/(5*Sqrt[1 - (-1)^(1/5)]) + (2*I*ArcTan[((-1)^(9/10) - I*Tanh[x/2])/Sqrt[1 + (-1)^(4/5)]])/(5*Sqrt[1 + (-1)^(4/5)]) - (2*I*ArcTan[((-1)^(3/10) + I*Tanh[x/2])/Sqrt[1 - (-1)^(3/5)]])/(5*Sqrt[1 - (-1)^(3/5)]) - (2*I*ArcTan[((-1)^(7/10) + I*Tanh[x/2])/Sqrt[1 + (-1)^(2/5)]])/(5*Sqrt[1 + (-1)^(2/5)]) - (1/5)*Sqrt[2]*ArcTanh[(1 - Tanh[x/2])/Sqrt[2]]}
{1/(1 + Sinh[x]^6), x, 7, ArcTanh[Sqrt[1 + (-1)^(1/3)]*Tanh[x]]/(3*Sqrt[1 + (-1)^(1/3)]) + ArcTanh[Sqrt[1 - (-1)^(2/3)]*Tanh[x]]/(3*Sqrt[1 - (-1)^(2/3)]) + Tanh[x]/3}
{1/(1 + Sinh[x]^8), x, 9, ArcTanh[Sqrt[1 - (-1)^(1/4)]*Tanh[x]]/(4*Sqrt[1 - (-1)^(1/4)]) + ArcTanh[Sqrt[1 + (-1)^(1/4)]*Tanh[x]]/(4*Sqrt[1 + (-1)^(1/4)]) + ArcTanh[Sqrt[1 - (-1)^(3/4)]*Tanh[x]]/(4*Sqrt[1 - (-1)^(3/4)]) + ArcTanh[Sqrt[1 + (-1)^(3/4)]*Tanh[x]]/(4*Sqrt[1 + (-1)^(3/4)])}


{1/(1 - Sinh[x]^5), x, 6, (2*I*ArcTan[((-1)^(3/10) - I*Tanh[x/2])/Sqrt[1 - (-1)^(3/5)]])/(5*Sqrt[1 - (-1)^(3/5)]) + (2*I*ArcTan[((-1)^(7/10) - I*Tanh[x/2])/Sqrt[1 + (-1)^(2/5)]])/(5*Sqrt[1 + (-1)^(2/5)]) - (2*I*ArcTan[((-1)^(1/10) + I*Tanh[x/2])/Sqrt[1 - (-1)^(1/5)]])/(5*Sqrt[1 - (-1)^(1/5)]) - (2*I*ArcTan[((-1)^(9/10) + I*Tanh[x/2])/Sqrt[1 + (-1)^(4/5)]])/(5*Sqrt[1 + (-1)^(4/5)]) + (1/5)*Sqrt[2]*ArcTanh[(1 + Tanh[x/2])/Sqrt[2]]}
{1/(1 - Sinh[x]^6), x, 7, ArcTanh[Sqrt[2]*Tanh[x]]/(3*Sqrt[2]) + (1/6)*(I + Sqrt[3])*ArcTanh[(2*Tanh[x])/(I + Sqrt[3])] + (2*ArcTanh[(1/2)*(I + Sqrt[3])*Tanh[x]])/(3*(I + Sqrt[3]))}
{1/(1 - Sinh[x]^8), x, 9, (1/4)*Sqrt[1/2 - I/2]*ArcTanh[Tanh[x]/Sqrt[1/2 - I/2]] + (1/4)*Sqrt[1/2 + I/2]*ArcTanh[Tanh[x]/Sqrt[1/2 + I/2]] + ArcTanh[Sqrt[2]*Tanh[x]]/(4*Sqrt[2]) + Tanh[x]/4}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cosh[c+d x]^m (a+b Sinh[c+d x]^n)^p*)


{Cosh[c + d*x]^5/(a + b*Sqrt[Sinh[c + d*x]]), x, 4, -((2*a*(a^4 + b^4)^2*Log[a + b*Sqrt[Sinh[c + d*x]]])/(b^10*d)) + (2*(a^4 + b^4)^2*Sqrt[Sinh[c + d*x]])/(b^9*d) - (a^3*(a^4 + 2*b^4)*Sinh[c + d*x])/(b^8*d) + (2*a^2*(a^4 + 2*b^4)*Sinh[c + d*x]^(3/2))/(3*b^7*d) - (a*(a^4 + 2*b^4)*Sinh[c + d*x]^2)/(2*b^6*d) + (2*(a^4 + 2*b^4)*Sinh[c + d*x]^(5/2))/(5*b^5*d) - (a^3*Sinh[c + d*x]^3)/(3*b^4*d) + (2*a^2*Sinh[c + d*x]^(7/2))/(7*b^3*d) - (a*Sinh[c + d*x]^4)/(4*b^2*d) + (2*Sinh[c + d*x]^(9/2))/(9*b*d)}
{Cosh[c + d*x]^3/(a + b*Sqrt[Sinh[c + d*x]]), x, 5, -((2*a*(a^4 + b^4)*Log[a + b*Sqrt[Sinh[c + d*x]]])/(b^6*d)) + (2*(a^4 + b^4)*Sqrt[Sinh[c + d*x]])/(b^5*d) - (a^3*Sinh[c + d*x])/(b^4*d) + (2*a^2*Sinh[c + d*x]^(3/2))/(3*b^3*d) - (a*Sinh[c + d*x]^2)/(2*b^2*d) + (2*Sinh[c + d*x]^(5/2))/(5*b*d)}
{Cosh[c + d*x]^1/(a + b*Sqrt[Sinh[c + d*x]]), x, 3, -((2*a*Log[a + b*Sqrt[Sinh[c + d*x]]])/(b^2*d)) + (2*Sqrt[Sinh[c + d*x]])/(b*d)}
{Sech[c + d*x]^1/(a + b*Sqrt[Sinh[c + d*x]]), x, 15, (b*(a^2 - b^2)*ArcTan[1 - Sqrt[2]*Sqrt[Sinh[c + d*x]]])/(Sqrt[2]*(a^4 + b^4)*d) - (b*(a^2 - b^2)*ArcTan[1 + Sqrt[2]*Sqrt[Sinh[c + d*x]]])/(Sqrt[2]*(a^4 + b^4)*d) + (a^3*ArcTan[Sinh[c + d*x]])/((a^4 + b^4)*d) + (b*(a^2 + b^2)*ArcTanh[(Sqrt[2]*Sqrt[Sinh[c + d*x]])/(1 + Sinh[c + d*x])])/(Sqrt[2]*(a^4 + b^4)*d) - (2*a*b^2*Log[a + b*Sqrt[Sinh[c + d*x]]])/((a^4 + b^4)*d) + (a*b^2*Log[1 + Sinh[c + d*x]^2])/(2*(a^4 + b^4)*d)}
(* {Sech[c + d*x]^3/(a + b*Sqrt[Sinh[c + d*x]]), x, 26, (a^2*b^3*(a^2 + b^2)*ArcTan[1 - Sqrt[2]*Sqrt[Sinh[c + d*x]]])/(Sqrt[2]*(a^4 + b^4)^2*d) + (b*(a^2 - 3*b^2)*ArcTan[1 - Sqrt[2]*Sqrt[Sinh[c + d*x]]])/(4*Sqrt[2]*(a^4 + b^4)*d) - (a^2*b^3*(a^2 + b^2)*ArcTan[1 + Sqrt[2]*Sqrt[Sinh[c + d*x]]])/(Sqrt[2]*(a^4 + b^4)^2*d) - (b*(a^2 - 3*b^2)*ArcTan[1 + Sqrt[2]*Sqrt[Sinh[c + d*x]]])/(4*Sqrt[2]*(a^4 + b^4)*d) + (a^3*b^4*ArcTan[Sinh[c + d*x]])/((a^4 + b^4)^2*d) + (a^3*ArcTan[Sinh[c + d*x]])/(2*(a^4 + b^4)*d) - (a^2*b^3*(a^2 - b^2)*ArcTanh[(Sqrt[2]*Sqrt[Sinh[c + d*x]])/(1 + Sinh[c + d*x])])/(Sqrt[2]*(a^4 + b^4)^2*d) + (b*(a^2 + 3*b^2)*ArcTanh[(Sqrt[2]*Sqrt[Sinh[c + d*x]])/(1 + Sinh[c + d*x])])/(4*Sqrt[2]*(a^4 + b^4)*d) - (2*a*b^6*Log[a + b*Sqrt[Sinh[c + d*x]]])/((a^4 + b^4)^2*d) + (a*b^6*Log[1 + Sinh[c + d*x]^2])/(2*(a^4 + b^4)^2*d) - (a*(b^2 - a^2*Sinh[c + d*x]))/(2*(a^4 + b^4)*d*(1 + Sinh[c + d*x]^2)) + (b*Sqrt[Sinh[c + d*x]]*(b^2 - a^2*Sinh[c + d*x]))/(2*(a^4 + b^4)*d*(1 + Sinh[c + d*x]^2))} *)


{Cosh[c + d*x]^5/(a + b*Sqrt[Sinh[c + d*x]])^2, x, 4, (2*(a^4 + b^4)*(9*a^4 + b^4)*Log[a + b*Sqrt[Sinh[c + d*x]]])/(b^10*d) + (2*a*(a^4 + b^4)^2)/(b^10*d*(a + b*Sqrt[Sinh[c + d*x]])) - (16*a^3*(a^4 + b^4)*Sqrt[Sinh[c + d*x]])/(b^9*d) + (a^2*(7*a^4 + 6*b^4)*Sinh[c + d*x])/(b^8*d) - (4*a*(3*a^4 + 2*b^4)*Sinh[c + d*x]^(3/2))/(3*b^7*d) + ((5*a^4 + 2*b^4)*Sinh[c + d*x]^2)/(2*b^6*d) - (8*a^3*Sinh[c + d*x]^(5/2))/(5*b^5*d) + (a^2*Sinh[c + d*x]^3)/(b^4*d) - (4*a*Sinh[c + d*x]^(7/2))/(7*b^3*d) + Sinh[c + d*x]^4/(4*b^2*d)}
{Cosh[c + d*x]^3/(a + b*Sqrt[Sinh[c + d*x]])^2, x, 5, (2*(5*a^4 + b^4)*Log[a + b*Sqrt[Sinh[c + d*x]]])/(b^6*d) + (2*a*(a^4 + b^4))/(b^6*d*(a + b*Sqrt[Sinh[c + d*x]])) - (8*a^3*Sqrt[Sinh[c + d*x]])/(b^5*d) + (3*a^2*Sinh[c + d*x])/(b^4*d) - (4*a*Sinh[c + d*x]^(3/2))/(3*b^3*d) + Sinh[c + d*x]^2/(2*b^2*d)}
{Cosh[c + d*x]^1/(a + b*Sqrt[Sinh[c + d*x]])^2, x, 4, (2*Log[a + b*Sqrt[Sinh[c + d*x]]])/(b^2*d) + (2*a)/(b^2*d*(a + b*Sqrt[Sinh[c + d*x]]))}
{Sech[c + d*x]^1/(a + b*Sqrt[Sinh[c + d*x]])^2, x, 15, (Sqrt[2]*a*b*(a^4 - 2*a^2*b^2 - b^4)*ArcTan[1 - Sqrt[2]*Sqrt[Sinh[c + d*x]]])/((a^4 + b^4)^2*d) - (Sqrt[2]*a*b*(a^4 - 2*a^2*b^2 - b^4)*ArcTan[1 + Sqrt[2]*Sqrt[Sinh[c + d*x]]])/((a^4 + b^4)^2*d) + (a^2*(a^4 - 3*b^4)*ArcTan[Sinh[c + d*x]])/((a^4 + b^4)^2*d) + (Sqrt[2]*a*b*(a^4 + 2*a^2*b^2 - b^4)*ArcTanh[(Sqrt[2]*Sqrt[Sinh[c + d*x]])/(1 + Sinh[c + d*x])])/((a^4 + b^4)^2*d) - (2*b^2*(3*a^4 - b^4)*Log[a + b*Sqrt[Sinh[c + d*x]]])/((a^4 + b^4)^2*d) + (b^2*(3*a^4 - b^4)*Log[1 + Sinh[c + d*x]^2])/(2*(a^4 + b^4)^2*d) + (2*a*b^2)/((a^4 + b^4)*d*(a + b*Sqrt[Sinh[c + d*x]]))}
(* {Sech[c + d*x]^3/(a + b*Sqrt[Sinh[c + d*x]])^2, x, 26, (a*b*(a^4 - 6*a^2*b^2 - b^4)*ArcTan[1 - Sqrt[2]*Sqrt[Sinh[c + d*x]]])/(2*Sqrt[2]*(a^4 + b^4)^2*d) + (Sqrt[2]*a*b^3*(2*a^6 + 3*a^4*b^2 - 2*a^2*b^4 - b^6)*ArcTan[1 - Sqrt[2]*Sqrt[Sinh[c + d*x]]])/((a^4 + b^4)^3*d) - (a*b*(a^4 - 6*a^2*b^2 - b^4)*ArcTan[1 + Sqrt[2]*Sqrt[Sinh[c + d*x]]])/(2*Sqrt[2]*(a^4 + b^4)^2*d) - (Sqrt[2]*a*b^3*(2*a^6 + 3*a^4*b^2 - 2*a^2*b^4 - b^6)*ArcTan[1 + Sqrt[2]*Sqrt[Sinh[c + d*x]]])/((a^4 + b^4)^3*d) + (a^2*b^4*(5*a^4 - 3*b^4)*ArcTan[Sinh[c + d*x]])/((a^4 + b^4)^3*d) + (a^2*(a^4 - 3*b^4)*ArcTan[Sinh[c + d*x]])/(2*(a^4 + b^4)^2*d) + (a*b*(a^4 + 6*a^2*b^2 - b^4)*ArcTanh[(Sqrt[2]*Sqrt[Sinh[c + d*x]])/(1 + Sinh[c + d*x])])/(2*Sqrt[2]*(a^4 + b^4)^2*d) - (Sqrt[2]*a*b^3*(2*a^6 - 3*a^4*b^2 - 2*a^2*b^4 + b^6)*ArcTanh[(Sqrt[2]*Sqrt[Sinh[c + d*x]])/(1 + Sinh[c + d*x])])/((a^4 + b^4)^3*d) - (2*b^6*(7*a^4 - b^4)*Log[a + b*Sqrt[Sinh[c + d*x]]])/((a^4 + b^4)^3*d) + (b^6*(7*a^4 - b^4)*Log[1 + Sinh[c + d*x]^2])/(2*(a^4 + b^4)^3*d) + (2*a*b^6)/((a^4 + b^4)^2*d*(a + b*Sqrt[Sinh[c + d*x]])) - (b^2*(3*a^4 - b^4) - a^2*(a^4 - 3*b^4)*Sinh[c + d*x])/(2*(a^4 + b^4)^2*d*(1 + Sinh[c + d*x]^2)) + (a*b*Sqrt[Sinh[c + d*x]]*(2*a^2*b^2 - (a^4 - b^4)*Sinh[c + d*x]))/((a^4 + b^4)^2*d*(1 + Sinh[c + d*x]^2))} *)


{Cosh[c + d*x]^5/(a + b*Sinh[c + d*x]^n), x, 6, (Hypergeometric2F1[1, 1/n, 1 + 1/n, -((b*Sinh[c + d*x]^n)/a)]*Sinh[c + d*x])/(a*d) + (2*Hypergeometric2F1[1, 3/n, (3 + n)/n, -((b*Sinh[c + d*x]^n)/a)]*Sinh[c + d*x]^3)/(3*a*d) + (Hypergeometric2F1[1, 5/n, (5 + n)/n, -((b*Sinh[c + d*x]^n)/a)]*Sinh[c + d*x]^5)/(5*a*d)}
{Cosh[c + d*x]^3/(a + b*Sinh[c + d*x]^n), x, 5, (Hypergeometric2F1[1, 1/n, 1 + 1/n, -((b*Sinh[c + d*x]^n)/a)]*Sinh[c + d*x])/(a*d) + (Hypergeometric2F1[1, 3/n, (3 + n)/n, -((b*Sinh[c + d*x]^n)/a)]*Sinh[c + d*x]^3)/(3*a*d)}
{Cosh[c + d*x]^1/(a + b*Sinh[c + d*x]^n), x, 2, (Hypergeometric2F1[1, 1/n, 1 + 1/n, -((b*Sinh[c + d*x]^n)/a)]*Sinh[c + d*x])/(a*d)}


{Cosh[c + d*x]^5/(a + b*Sinh[c + d*x]^n)^2, x, 9, -(((1 - n)*Hypergeometric2F1[1, 1/n, 1 + 1/n, -((b*Sinh[c + d*x]^n)/a)]*Sinh[c + d*x])/(a^2*d*n)) - (2*(3 - n)*Hypergeometric2F1[1, 3/n, (3 + n)/n, -((b*Sinh[c + d*x]^n)/a)]*Sinh[c + d*x]^3)/(3*a^2*d*n) - ((5 - n)*Hypergeometric2F1[1, 5/n, (5 + n)/n, -((b*Sinh[c + d*x]^n)/a)]*Sinh[c + d*x]^5)/(5*a^2*d*n) + Sinh[c + d*x]/(a*d*n*(a + b*Sinh[c + d*x]^n)) + (2*Sinh[c + d*x]^3)/(a*d*n*(a + b*Sinh[c + d*x]^n)) + Sinh[c + d*x]^5/(a*d*n*(a + b*Sinh[c + d*x]^n))}
{Cosh[c + d*x]^3/(a + b*Sinh[c + d*x]^n)^2, x, 7, -(((1 - n)*Hypergeometric2F1[1, 1/n, 1 + 1/n, -((b*Sinh[c + d*x]^n)/a)]*Sinh[c + d*x])/(a^2*d*n)) - ((3 - n)*Hypergeometric2F1[1, 3/n, (3 + n)/n, -((b*Sinh[c + d*x]^n)/a)]*Sinh[c + d*x]^3)/(3*a^2*d*n) + Sinh[c + d*x]/(a*d*n*(a + b*Sinh[c + d*x]^n)) + Sinh[c + d*x]^3/(a*d*n*(a + b*Sinh[c + d*x]^n))}
{Cosh[c + d*x]^1/(a + b*Sinh[c + d*x]^n)^2, x, 3, -(((1 - n)*Hypergeometric2F1[1, 1/n, 1 + 1/n, -((b*Sinh[c + d*x]^n)/a)]*Sinh[c + d*x])/(a^2*d*n)) + Sinh[c + d*x]/(a*d*n*(a + b*Sinh[c + d*x]^n))}


(* ::Subsection::Closed:: *)
(*Integrands of the form Tanh[c+d x]^m (a+b Sinh[c+d x]^n)^p*)


{Coth[x]/Sqrt[a + b*Sinh[x]^n], x, 3, -((2*ArcTanh[Sqrt[a + b*Sinh[x]^n]/Sqrt[a]])/(Sqrt[a]*n))}


{Coth[x]*Sqrt[a + b*Sinh[x]^n], x, 4, -((2*Sqrt[a]*ArcTanh[Sqrt[a + b*Sinh[x]^n]/Sqrt[a]])/n) + (2*Sqrt[a + b*Sinh[x]^n])/n}


(* ::Section::Closed:: *)
(*Integrands of the form (A+B Hyper[c+d x]) (a+b Sinh[c+d x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (A+B Sinh[c+d x]) (a+b Sinh[c+d x])^n*)


{(A + B*Sinh[x])/(a + b*Sinh[x]), x, 2, (B*x)/b - (2*(A*b - a*B)*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(b*Sqrt[a^2 + b^2])}
{(A + B*Sinh[x])/(a + b*Sinh[x])^2, x, 3, -((2*(a*A + b*B)*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(3/2)) - ((A*b - a*B)*Cosh[x])/((a^2 + b^2)*(a + b*Sinh[x]))}
{(A + B*Sinh[x])/(a + b*Sinh[x])^3, x, 4, -(((2*a^2*A - A*b^2 + 3*a*b*B)*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(5/2)) - ((A*b - a*B)*Cosh[x])/(2*(a^2 + b^2)*(a + b*Sinh[x])^2) - ((3*a*A*b - a^2*B + 2*b^2*B)*Cosh[x])/(2*(a^2 + b^2)^2*(a + b*Sinh[x]))}
{(A + B*Sinh[x])/(a + b*Sinh[x])^4, x, 5, -(((2*a^3*A - 3*a*A*b^2 + 4*a^2*b*B - b^3*B)*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a^2 + b^2)^(7/2)) - ((A*b - a*B)*Cosh[x])/(3*(a^2 + b^2)*(a + b*Sinh[x])^3) - ((5*a*A*b - 2*a^2*B + 3*b^2*B)*Cosh[x])/(6*(a^2 + b^2)^2*(a + b*Sinh[x])^2) - ((11*a^2*A*b - 4*A*b^3 - 2*a^3*B + 13*a*b^2*B)*Cosh[x])/(6*(a^2 + b^2)^3*(a + b*Sinh[x]))}

{(A + B*Sinh[x])/(I + Sinh[x]), x, 2, B*x - ((I*A + B)*Cosh[x])/(I + Sinh[x])}
{(A + B*Sinh[x])/(I + Sinh[x])^2, x, 2, -(((I*A + B)*Cosh[x])/(3*(I + Sinh[x])^2)) - ((A + 2*I*B)*Cosh[x])/(3*(I + Sinh[x]))}
{(A + B*Sinh[x])/(I + Sinh[x])^3, x, 3, -(((I*A + B)*Cosh[x])/(5*(I + Sinh[x])^3)) - ((2*A + 3*I*B)*Cosh[x])/(15*(I + Sinh[x])^2) + ((2*I*A - 3*B)*Cosh[x])/(15*(I + Sinh[x]))}
{(A + B*Sinh[x])/(I + Sinh[x])^4, x, 4, -(((I*A + B)*Cosh[x])/(7*(I + Sinh[x])^4)) - ((3*A + 4*I*B)*Cosh[x])/(35*(I + Sinh[x])^3) + (2*(3*I*A - 4*B)*Cosh[x])/(105*(I + Sinh[x])^2) + (2*(3*A + 4*I*B)*Cosh[x])/(105*(I + Sinh[x]))}

{(A + B*Sinh[x])/(I - Sinh[x]), x, 2, (-B)*x + ((I*A - B)*Cosh[x])/(I - Sinh[x])}
{(A + B*Sinh[x])/(I - Sinh[x])^2, x, 2, (I*(A + I*B)*Cosh[x])/(3*(I - Sinh[x])^2) + ((A - 2*I*B)*Cosh[x])/(3*(I - Sinh[x]))}
{(A + B*Sinh[x])/(I - Sinh[x])^3, x, 3, (I*(A + I*B)*Cosh[x])/(5*(I - Sinh[x])^3) + ((2*A - 3*I*B)*Cosh[x])/(15*(I - Sinh[x])^2) - ((2*I*A + 3*B)*Cosh[x])/(15*(I - Sinh[x]))}
{(A + B*Sinh[x])/(I - Sinh[x])^4, x, 4, (I*(A + I*B)*Cosh[x])/(7*(I - Sinh[x])^4) + ((3*A - 4*I*B)*Cosh[x])/(35*(I - Sinh[x])^3) - (2*(3*I*A + 4*B)*Cosh[x])/(105*(I - Sinh[x])^2) - (2*(3*A - 4*I*B)*Cosh[x])/(105*(I - Sinh[x]))}

{(b*B/a + B*Sinh[x])/(a + b*Sinh[x]), x, 2, (B*x)/b + (2*(a^2 - b^2)*B*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a*b*Sqrt[a^2 + b^2])}
{(a*B/b + B*Sinh[x])/(a + b*Sinh[x]), x, 2, (B*x)/b}

{(a - b*Sinh[x])/(b + a*Sinh[x])^2, x, 2, -(Cosh[x]/(b + a*Sinh[x]))}
{(2 - Sinh[x])/(2 + Sinh[x]), x, 2, -x + (4*x)/Sqrt[5] - (8*ArcTanh[Cosh[x]/(2 + Sqrt[5] + Sinh[x])])/Sqrt[5]}


{(A + B*Sinh[x])*(a + b*Sinh[x])^(5/2), x, 8, (2/105)*(56*a*A*b + 15*a^2*B - 25*b^2*B)*Cosh[x]*Sqrt[a + b*Sinh[x]] + (2/35)*(7*A*b + 5*a*B)*Cosh[x]*(a + b*Sinh[x])^(3/2) + (2/7)*B*Cosh[x]*(a + b*Sinh[x])^(5/2) + (2*I*(161*a^2*A*b - 63*A*b^3 + 15*a^3*B - 145*a*b^2*B)*EllipticE[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[a + b*Sinh[x]])/(105*b*Sqrt[(a + b*Sinh[x])/(a - I*b)]) - (2*I*(a^2 + b^2)*(56*a*A*b + 15*a^2*B - 25*b^2*B)*EllipticF[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[(a + b*Sinh[x])/(a - I*b)])/(105*b*Sqrt[a + b*Sinh[x]])}
{(A + B*Sinh[x])*(a + b*Sinh[x])^(3/2), x, 7, (2/15)*(5*A*b + 3*a*B)*Cosh[x]*Sqrt[a + b*Sinh[x]] + (2/5)*B*Cosh[x]*(a + b*Sinh[x])^(3/2) + (2*I*(20*a*A*b + 3*a^2*B - 9*b^2*B)*EllipticE[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[a + b*Sinh[x]])/(15*b*Sqrt[(a + b*Sinh[x])/(a - I*b)]) - (2*I*(a^2 + b^2)*(5*A*b + 3*a*B)*EllipticF[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[(a + b*Sinh[x])/(a - I*b)])/(15*b*Sqrt[a + b*Sinh[x]])}
{(A + B*Sinh[x])*(a + b*Sinh[x])^(1/2), x, 6, (2/3)*B*Cosh[x]*Sqrt[a + b*Sinh[x]] + (2*I*(3*A*b + a*B)*EllipticE[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[a + b*Sinh[x]])/(3*b*Sqrt[(a + b*Sinh[x])/(a - I*b)]) - (2*I*(a^2 + b^2)*B*EllipticF[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[(a + b*Sinh[x])/(a - I*b)])/(3*b*Sqrt[a + b*Sinh[x]])}
{(A + B*Sinh[x])/(a + b*Sinh[x])^(1/2), x, 5, (2*I*B*EllipticE[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[a + b*Sinh[x]])/(b*Sqrt[(a + b*Sinh[x])/(a - I*b)]) + (2*I*(A*b - a*B)*EllipticF[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[(a + b*Sinh[x])/(a - I*b)])/(b*Sqrt[a + b*Sinh[x]])}
{(A + B*Sinh[x])/(a + b*Sinh[x])^(3/2), x, 6, -((2*(A*b - a*B)*Cosh[x])/((a^2 + b^2)*Sqrt[a + b*Sinh[x]])) + (2*I*(A*b - a*B)*EllipticE[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[a + b*Sinh[x]])/(b*(a^2 + b^2)*Sqrt[(a + b*Sinh[x])/(a - I*b)]) + (2*I*B*EllipticF[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[(a + b*Sinh[x])/(a - I*b)])/(b*Sqrt[a + b*Sinh[x]])}
{(A + B*Sinh[x])/(a + b*Sinh[x])^(5/2), x, 7, -((2*(A*b - a*B)*Cosh[x])/(3*(a^2 + b^2)*(a + b*Sinh[x])^(3/2))) - (2*(4*a*A*b - a^2*B + 3*b^2*B)*Cosh[x])/(3*(a^2 + b^2)^2*Sqrt[a + b*Sinh[x]]) + (2*I*(4*a*A*b - a^2*B + 3*b^2*B)*EllipticE[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[a + b*Sinh[x]])/(3*b*(a^2 + b^2)^2*Sqrt[(a + b*Sinh[x])/(a - I*b)]) - (2*I*(A*b - a*B)*EllipticF[Pi/4 - (I*x)/2, -((2*I*b)/(a - I*b))]*Sqrt[(a + b*Sinh[x])/(a - I*b)])/(3*b*(a^2 + b^2)*Sqrt[a + b*Sinh[x]])}

{(A + B*Sinh[x])*(a + a*I*Sinh[x])^(5/2), x, 4, (64*a^3*(7*I*A + 5*B)*Cosh[x])/(105*Sqrt[a + I*a*Sinh[x]]) + (16/105)*a^2*(7*I*A + 5*B)*Cosh[x]*Sqrt[a + I*a*Sinh[x]] + (2/35)*a*(7*I*A + 5*B)*Cosh[x]*(a + I*a*Sinh[x])^(3/2) + (2/7)*B*Cosh[x]*(a + I*a*Sinh[x])^(5/2)}
{(A + B*Sinh[x])*(a + a*I*Sinh[x])^(3/2), x, 3, (8*a^2*(5*I*A + 3*B)*Cosh[x])/(15*Sqrt[a + I*a*Sinh[x]]) + (2/15)*a*(5*I*A + 3*B)*Cosh[x]*Sqrt[a + I*a*Sinh[x]] + (2/5)*B*Cosh[x]*(a + I*a*Sinh[x])^(3/2)}
{(A + B*Sinh[x])*(a + a*I*Sinh[x])^(1/2), x, 2, (2*a*(3*I*A + B)*Cosh[x])/(3*Sqrt[a + I*a*Sinh[x]]) + (2/3)*B*Cosh[x]*Sqrt[a + I*a*Sinh[x]]}
{(A + B*Sinh[x])/(a + a*I*Sinh[x])^(1/2), x, 2, (2*I*(A + I*B)*ArcTanh[Sin[Pi/4 - (I*x)/2]]*Cos[Pi/4 - (I*x)/2])/Sqrt[a + I*a*Sinh[x]] + (2*B*Cosh[x])/Sqrt[a + I*a*Sinh[x]]}
{(A + B*Sinh[x])/(a + a*I*Sinh[x])^(3/2), x, 2, (I*(A + I*B)*Cosh[x])/(2*(a + I*a*Sinh[x])^(3/2)) + (I*(A - 3*I*B)*ArcTanh[Sin[Pi/4 - (I*x)/2]]*Cos[Pi/4 - (I*x)/2])/(2*a*Sqrt[a + I*a*Sinh[x]])}
{(A + B*Sinh[x])/(a + a*I*Sinh[x])^(5/2), x, 3, (I*(A + I*B)*Cosh[x])/(4*(a + I*a*Sinh[x])^(5/2)) + ((3*I*A + 5*B)*Cosh[x])/(16*a*(a + I*a*Sinh[x])^(3/2)) + ((3*I*A + 5*B)*ArcTanh[Sin[Pi/4 - (I*x)/2]]*Cos[Pi/4 - (I*x)/2])/(16*a^2*Sqrt[a + I*a*Sinh[x]])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (A+B Cosh[c+d x]) (a+b Sinh[c+d x])^n*)


{(A + B*Cosh[x])/(a + b*Sinh[x]), x, 5, -((2*A*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/Sqrt[a^2 + b^2]) + (B*Log[a + b*Sinh[x]])/b}

{(A + B*Cosh[x])/(I + Sinh[x]), x, 5, B*Log[1 - I*Sinh[x]] - (A*Cosh[x])/(1 - I*Sinh[x])}
{(A + B*Cosh[x])/(I - Sinh[x]), x, 5, (-B)*Log[1 + I*Sinh[x]] + (A*Cosh[x])/(1 + I*Sinh[x])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (A+B Hyper[c+d x]) (a+b Sinh[c+d x])^n*)


{(A + B*Tanh[x])/(a + b*Sinh[x]), x, 9, -((2*A*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/Sqrt[a^2 + b^2]) + (B*Log[1 - I*Sinh[x]])/(2*(a - I*b)) + (B*Log[1 + I*Sinh[x]])/(2*(a + I*b)) - (a*B*Log[a + b*Sinh[x]])/(a^2 + b^2)}
{(A + B*Coth[x])/(a + b*Sinh[x]), x, 6, -((2*A*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/Sqrt[a^2 + b^2]) + (B*Log[Sinh[x]])/a - (B*Log[a + b*Sinh[x]])/a}
{(A + B*Sech[x])/(a + b*Sinh[x]), x, 9, -((2*A*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/Sqrt[a^2 + b^2]) - (B*Log[1 - I*Sinh[x]])/(2*(I*a + b)) - (I*B*Log[1 + I*Sinh[x]])/(2*(a + I*b)) + (b*B*Log[a + b*Sinh[x]])/(a^2 + b^2)}
{(A + B*Csch[x])/(a + b*Sinh[x]), x, 4, -((B*ArcTanh[Cosh[x]])/a) - (2*(a*A - b*B)*ArcTanh[(b - a*Tanh[x/2])/Sqrt[a^2 + b^2]])/(a*Sqrt[a^2 + b^2])}


(* ::Section::Closed:: *)
(*Integrands of the form (c+d x)^m Sinh[a+b x]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (c+d x)^m Sinh[a+b x]^n*)


{x^4*Sinh[a + b*x], x, 5, (24*Cosh[a + b*x])/b^5 + (12*x^2*Cosh[a + b*x])/b^3 + (x^4*Cosh[a + b*x])/b - (24*x*Sinh[a + b*x])/b^4 - (4*x^3*Sinh[a + b*x])/b^2}
{x^3*Sinh[a + b*x], x, 4, (6*x*Cosh[a + b*x])/b^3 + (x^3*Cosh[a + b*x])/b - (6*Sinh[a + b*x])/b^4 - (3*x^2*Sinh[a + b*x])/b^2}
{x^2*Sinh[a + b*x], x, 3, (2*Cosh[a + b*x])/b^3 + (x^2*Cosh[a + b*x])/b - (2*x*Sinh[a + b*x])/b^2}
{x^1*Sinh[a + b*x], x, 2, (x*Cosh[a + b*x])/b - Sinh[a + b*x]/b^2}
{Sinh[a + b*x]/x^1, x, 3, CoshIntegral[b*x]*Sinh[a] + Cosh[a]*SinhIntegral[b*x]}
{Sinh[a + b*x]/x^2, x, 4, b*Cosh[a]*CoshIntegral[b*x] - Sinh[a + b*x]/x + b*Sinh[a]*SinhIntegral[b*x]}
{Sinh[a + b*x]/x^3, x, 5, -((b*Cosh[a + b*x])/(2*x)) + (1/2)*b^2*CoshIntegral[b*x]*Sinh[a] - Sinh[a + b*x]/(2*x^2) + (1/2)*b^2*Cosh[a]*SinhIntegral[b*x]}


{x^3*Sinh[a + b*x]^2, x, 4, -((3*x^2)/(8*b^2)) - x^4/8 + (3*x*Cosh[a + b*x]*Sinh[a + b*x])/(4*b^3) + (x^3*Cosh[a + b*x]*Sinh[a + b*x])/(2*b) - (3*Sinh[a + b*x]^2)/(8*b^4) - (3*x^2*Sinh[a + b*x]^2)/(4*b^2)}
{x^2*Sinh[a + b*x]^2, x, 3, -(x/(4*b^2)) - x^3/6 + (Cosh[a + b*x]*Sinh[a + b*x])/(4*b^3) + (x^2*Cosh[a + b*x]*Sinh[a + b*x])/(2*b) - (x*Sinh[a + b*x]^2)/(2*b^2)}
{x^1*Sinh[a + b*x]^2, x, 2, -(x^2/4) + (x*Cosh[a + b*x]*Sinh[a + b*x])/(2*b) - Sinh[a + b*x]^2/(4*b^2)}
{Sinh[a + b*x]^2/x^1, x, 5, (1/2)*Cosh[2*a]*CoshIntegral[2*b*x] - Log[x]/2 + (1/2)*Sinh[2*a]*SinhIntegral[2*b*x]}
{Sinh[a + b*x]^2/x^2, x, 5, b*CoshIntegral[2*b*x]*Sinh[2*a] - Sinh[a + b*x]^2/x + b*Cosh[2*a]*SinhIntegral[2*b*x]}
{Sinh[a + b*x]^2/x^3, x, 7, b^2*Cosh[2*a]*CoshIntegral[2*b*x] - (b*Cosh[a + b*x]*Sinh[a + b*x])/x - Sinh[a + b*x]^2/(2*x^2) + b^2*Sinh[2*a]*SinhIntegral[2*b*x]}


{x^3*Sinh[a + b*x]^3, x, 8, -((40*x*Cosh[a + b*x])/(9*b^3)) - (2*x^3*Cosh[a + b*x])/(3*b) + (40*Sinh[a + b*x])/(9*b^4) + (2*x^2*Sinh[a + b*x])/b^2 + (2*x*Cosh[a + b*x]*Sinh[a + b*x]^2)/(9*b^3) + (x^3*Cosh[a + b*x]*Sinh[a + b*x]^2)/(3*b) - (2*Sinh[a + b*x]^3)/(27*b^4) - (x^2*Sinh[a + b*x]^3)/(3*b^2)}
{x^2*Sinh[a + b*x]^3, x, 6, -((14*Cosh[a + b*x])/(9*b^3)) - (2*x^2*Cosh[a + b*x])/(3*b) + (2*Cosh[a + b*x]^3)/(27*b^3) + (4*x*Sinh[a + b*x])/(3*b^2) + (x^2*Cosh[a + b*x]*Sinh[a + b*x]^2)/(3*b) - (2*x*Sinh[a + b*x]^3)/(9*b^2)}
{x^1*Sinh[a + b*x]^3, x, 3, -((2*x*Cosh[a + b*x])/(3*b)) + (2*Sinh[a + b*x])/(3*b^2) + (x*Cosh[a + b*x]*Sinh[a + b*x]^2)/(3*b) - Sinh[a + b*x]^3/(9*b^2)}
{Sinh[a + b*x]^3/x^1, x, 8, (-(3/4))*CoshIntegral[b*x]*Sinh[a] + (1/4)*CoshIntegral[3*b*x]*Sinh[3*a] - (3/4)*Cosh[a]*SinhIntegral[b*x] + (1/4)*Cosh[3*a]*SinhIntegral[3*b*x]}
{Sinh[a + b*x]^3/x^2, x, 8, (-(3/4))*b*Cosh[a]*CoshIntegral[b*x] + (3/4)*b*Cosh[3*a]*CoshIntegral[3*b*x] - Sinh[a + b*x]^3/x - (3/4)*b*Sinh[a]*SinhIntegral[b*x] + (3/4)*b*Sinh[3*a]*SinhIntegral[3*b*x]}
{Sinh[a + b*x]^3/x^3, x, 12, (-(3/8))*b^2*CoshIntegral[b*x]*Sinh[a] + (9/8)*b^2*CoshIntegral[3*b*x]*Sinh[3*a] - (3*b*Cosh[a + b*x]*Sinh[a + b*x]^2)/(2*x) - Sinh[a + b*x]^3/(2*x^2) - (3/8)*b^2*Cosh[a]*SinhIntegral[b*x] + (9/8)*b^2*Cosh[3*a]*SinhIntegral[3*b*x]}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c+d x)^(m/2) Sinh[a+b x]^n*)


{Sinh[a + b*x]*x^(5/2), x, 8, (15*Sqrt[x]*Cosh[a + b*x])/(4*b^3) + (x^(5/2)*Cosh[a + b*x])/b - (15*Sqrt[Pi]*Erf[Sqrt[b]*Sqrt[x]])/(E^a*(16*b^(7/2))) - (15*E^a*Sqrt[Pi]*Erfi[Sqrt[b]*Sqrt[x]])/(16*b^(7/2)) - (5*x^(3/2)*Sinh[a + b*x])/(2*b^2)}
{Sinh[a + b*x]*x^(3/2), x, 7, (x^(3/2)*Cosh[a + b*x])/b - (3*Sqrt[Pi]*Erf[Sqrt[b]*Sqrt[x]])/(E^a*(8*b^(5/2))) + (3*E^a*Sqrt[Pi]*Erfi[Sqrt[b]*Sqrt[x]])/(8*b^(5/2)) - (3*Sqrt[x]*Sinh[a + b*x])/(2*b^2)}
{Sinh[a + b*x]*x^(1/2), x, 6, (Sqrt[x]*Cosh[a + b*x])/b - (Sqrt[Pi]*Erf[Sqrt[b]*Sqrt[x]])/(E^a*(4*b^(3/2))) - (E^a*Sqrt[Pi]*Erfi[Sqrt[b]*Sqrt[x]])/(4*b^(3/2))}
{Sinh[a + b*x]/x^(1/2), x, 5, -((Sqrt[Pi]*Erf[Sqrt[b]*Sqrt[x]])/(E^a*(2*Sqrt[b]))) + (E^a*Sqrt[Pi]*Erfi[Sqrt[b]*Sqrt[x]])/(2*Sqrt[b])}
{Sinh[a + b*x]/x^(3/2), x, 6, (Sqrt[b]*Sqrt[Pi]*Erf[Sqrt[b]*Sqrt[x]])/E^a + Sqrt[b]*E^a*Sqrt[Pi]*Erfi[Sqrt[b]*Sqrt[x]] - (2*Sinh[a + b*x])/Sqrt[x]}
{Sinh[a + b*x]/x^(5/2), x, 7, -((4*b*Cosh[a + b*x])/(3*Sqrt[x])) - ((2/3)*b^(3/2)*Sqrt[Pi]*Erf[Sqrt[b]*Sqrt[x]])/E^a + (2/3)*b^(3/2)*E^a*Sqrt[Pi]*Erfi[Sqrt[b]*Sqrt[x]] - (2*Sinh[a + b*x])/(3*x^(3/2))}
{Sinh[a + b*x]/x^(7/2), x, 8, -((4*b*Cosh[a + b*x])/(15*x^(3/2))) + ((4/15)*b^(5/2)*Sqrt[Pi]*Erf[Sqrt[b]*Sqrt[x]])/E^a + (4/15)*b^(5/2)*E^a*Sqrt[Pi]*Erfi[Sqrt[b]*Sqrt[x]] - (2*Sinh[a + b*x])/(5*x^(5/2)) - (8*b^2*Sinh[a + b*x])/(15*Sqrt[x])}


{Sinh[a + b*x]*Sqrt[c + d*x], x, 6, (Sqrt[c + d*x]*Cosh[a + b*x])/b - (Sqrt[d]*E^(-a + (b*c)/d)*Sqrt[Pi]*Erf[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/(4*b^(3/2)) - (Sqrt[d]*E^(a - (b*c)/d)*Sqrt[Pi]*Erfi[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/(4*b^(3/2))}
{Sinh[a + b*x]/Sqrt[c + d*x], x, 5, -((E^(-a + (b*c)/d)*Sqrt[Pi]*Erf[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/(2*Sqrt[b]*Sqrt[d])) + (E^(a - (b*c)/d)*Sqrt[Pi]*Erfi[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/(2*Sqrt[b]*Sqrt[d])}
{Sinh[a + b*x]/(c + d*x)^(3/2), x, 6, (Sqrt[b]*E^(-a + (b*c)/d)*Sqrt[Pi]*Erf[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/d^(3/2) + (Sqrt[b]*E^(a - (b*c)/d)*Sqrt[Pi]*Erfi[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/d^(3/2) - (2*Sinh[a + b*x])/(d*Sqrt[c + d*x])}


{Sinh[a + b*x]^2*Sqrt[c + d*x], x, 8, -((c + d*x)^(3/2)/(3*d)) + (Sqrt[d]*E^(-2*a + (2*b*c)/d)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/(16*b^(3/2)) - (Sqrt[d]*E^(2*a - (2*b*c)/d)*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/(16*b^(3/2)) + (Sqrt[c + d*x]*Sinh[2*a + 2*b*x])/(4*b)}
{Sinh[a + b*x]^2/Sqrt[c + d*x], x, 7, -(Sqrt[c + d*x]/d) + (E^(-2*a + (2*b*c)/d)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/(4*Sqrt[b]*Sqrt[d]) + (E^(2*a - (2*b*c)/d)*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/(4*Sqrt[b]*Sqrt[d])}
{Sinh[a + b*x]^2/(c + d*x)^(3/2), x, 7, -((Sqrt[b]*E^(-2*a + (2*b*c)/d)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/d^(3/2)) + (Sqrt[b]*E^(2*a - (2*b*c)/d)*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/d^(3/2) - (2*Sinh[a + b*x]^2)/(d*Sqrt[c + d*x])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c+d x)^m Sinh[a+b x]^(n/2)*)


{x/Sinh[x]^(3/2) - x*Sqrt[Sinh[x]], x, 2, -((2*x*Cosh[x])/Sqrt[Sinh[x]]) + 4*Sqrt[Sinh[x]]}
{x/Sinh[x]^(5/2) + x/(3*Sqrt[Sinh[x]]), x, 2, -((2*x*Cosh[x])/(3*Sinh[x]^(3/2))) - 4/(3*Sqrt[Sinh[x]])}
{x/Sinh[x]^(7/2) + (3/5)*x*Sqrt[Sinh[x]], x, 3, -((2*x*Cosh[x])/(5*Sinh[x]^(5/2))) - 4/(15*Sinh[x]^(3/2)) + (6*x*Cosh[x])/(5*Sqrt[Sinh[x]]) - (12*Sqrt[Sinh[x]])/5}
{x^2/Sinh[x]^(3/2) - x^2*Sqrt[Sinh[x]], x, 4, -((2*x^2*Cosh[x])/Sqrt[Sinh[x]]) + 8*x*Sqrt[Sinh[x]] - (16*I*EllipticE[Pi/4 - (I*x)/2, 2]*Sqrt[Sinh[x]])/Sqrt[I*Sinh[x]]}


{Sinh[x]^(3/2)/x^3, x, 1, (3/8)*Int[1/(x*Sqrt[Sinh[x]]), x] + (9/8)*Int[Sinh[x]^(3/2)/x, x] - (3*Cosh[x]*Sqrt[Sinh[x]])/(4*x) - Sinh[x]^(3/2)/(2*x^2)}


(* ::Subsection:: *)
(*Integrands of the form (c+d x)^(m/2) Sinh[a+b x]^(n/2)*)


(* ::Section::Closed:: *)
(*Integrands of the form (e+f x)^m (a+b Sinh[c+d x]^n)^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (e+f x)^m (a+b Sinh[c+d x])^p*)


(* ::Subsubsection::Closed:: *)
(*n*)


{x/(a + b*Sinh[x]), x, 8, (x*Log[1 + (b*E^x)/(a - Sqrt[a^2 + b^2])])/Sqrt[a^2 + b^2] - (x*Log[1 + (b*E^x)/(a + Sqrt[a^2 + b^2])])/Sqrt[a^2 + b^2] + PolyLog[2, -((b*E^x)/(a - Sqrt[a^2 + b^2]))]/Sqrt[a^2 + b^2] - PolyLog[2, -((b*E^x)/(a + Sqrt[a^2 + b^2]))]/Sqrt[a^2 + b^2]}
{x^2/(a + b*Sinh[x]), x, 10, (x^2*Log[1 + (b*E^x)/(a - Sqrt[a^2 + b^2])])/Sqrt[a^2 + b^2] - (x^2*Log[1 + (b*E^x)/(a + Sqrt[a^2 + b^2])])/Sqrt[a^2 + b^2] + (2*x*PolyLog[2, -((b*E^x)/(a - Sqrt[a^2 + b^2]))])/Sqrt[a^2 + b^2] - (2*x*PolyLog[2, -((b*E^x)/(a + Sqrt[a^2 + b^2]))])/Sqrt[a^2 + b^2] - (2*PolyLog[3, -((b*E^x)/(a - Sqrt[a^2 + b^2]))])/Sqrt[a^2 + b^2] + (2*PolyLog[3, -((b*E^x)/(a + Sqrt[a^2 + b^2]))])/Sqrt[a^2 + b^2]}
{x^3/(a + b*Sinh[x]), x, 12, (x^3*Log[1 + (b*E^x)/(a - Sqrt[a^2 + b^2])])/Sqrt[a^2 + b^2] - (x^3*Log[1 + (b*E^x)/(a + Sqrt[a^2 + b^2])])/Sqrt[a^2 + b^2] + (3*x^2*PolyLog[2, -((b*E^x)/(a - Sqrt[a^2 + b^2]))])/Sqrt[a^2 + b^2] - (3*x^2*PolyLog[2, -((b*E^x)/(a + Sqrt[a^2 + b^2]))])/Sqrt[a^2 + b^2] - (6*x*PolyLog[3, -((b*E^x)/(a - Sqrt[a^2 + b^2]))])/Sqrt[a^2 + b^2] + (6*x*PolyLog[3, -((b*E^x)/(a + Sqrt[a^2 + b^2]))])/Sqrt[a^2 + b^2] + (6*PolyLog[4, -((b*E^x)/(a - Sqrt[a^2 + b^2]))])/Sqrt[a^2 + b^2] - (6*PolyLog[4, -((b*E^x)/(a + Sqrt[a^2 + b^2]))])/Sqrt[a^2 + b^2]}


{x/(1 + I*Sinh[x]), x, 3, -2*Log[Cos[Pi/4 - (I*x)/2]] + I*x*Tan[Pi/4 - (I*x)/2]}
{x^2/(1 + I*Sinh[x]), x, 6, x^2 - 4*x*Log[1 + E^((I*Pi)/2 + x)] - 4*PolyLog[2, -E^((I*Pi)/2 + x)] + I*x^2*Tan[Pi/4 - (I*x)/2]}
{x^3/(1 + I*Sinh[x]), x, 7, x^3 - 6*x^2*Log[1 + E^((I*Pi)/2 + x)] - 12*x*PolyLog[2, -E^((I*Pi)/2 + x)] + 12*PolyLog[3, -E^((I*Pi)/2 + x)] + I*x^3*Tan[Pi/4 - (I*x)/2]}


{x/(1 - I*Sinh[x]), x, 3, -2*Log[Cos[Pi/4 + (I*x)/2]] - I*x*Tan[Pi/4 + (I*x)/2]}
{x^2/(1 - I*Sinh[x]), x, 6, -x^2 - 4*x*Log[1 + E^((I*Pi)/2 - x)] + 4*PolyLog[2, -E^((I*Pi)/2 - x)] - I*x^2*Tan[Pi/4 + (I*x)/2]}
{x^3/(1 - I*Sinh[x]), x, 7, -x^3 - 6*x^2*Log[1 + E^((I*Pi)/2 - x)] + 12*x*PolyLog[2, -E^((I*Pi)/2 - x)] + 12*PolyLog[3, -E^((I*Pi)/2 - x)] - I*x^3*Tan[Pi/4 + (I*x)/2]}


{x/(a + b*Sinh[c + d*x])^2, x, 12, (a*x*Log[1 + (b*E^(c + d*x))/(a - Sqrt[a^2 + b^2])])/((a^2 + b^2)^(3/2)*d) - (a*x*Log[1 + (b*E^(c + d*x))/(a + Sqrt[a^2 + b^2])])/((a^2 + b^2)^(3/2)*d) + Log[a + b*Sinh[c + d*x]]/((a^2 + b^2)*d^2) + (a*PolyLog[2, -((b*E^(c + d*x))/(a - Sqrt[a^2 + b^2]))])/((a^2 + b^2)^(3/2)*d^2) - (a*PolyLog[2, -((b*E^(c + d*x))/(a + Sqrt[a^2 + b^2]))])/((a^2 + b^2)^(3/2)*d^2) - (b*x*Cosh[c + d*x])/((a^2 + b^2)*d*(a + b*Sinh[c + d*x]))}
{(e + f*x)/(a + b*Sinh[c + d*x])^2, x, 17, -((2*a*e*ArcTanh[(b - a*Tanh[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]])/((a^2 + b^2)^(3/2)*d)) + (a*f*x*Log[1 + (b*E^(c + d*x))/(a - Sqrt[a^2 + b^2])])/((a^2 + b^2)^(3/2)*d) - (a*f*x*Log[1 + (b*E^(c + d*x))/(a + Sqrt[a^2 + b^2])])/((a^2 + b^2)^(3/2)*d) + (f*Log[a + b*Sinh[c + d*x]])/((a^2 + b^2)*d^2) + (a*f*PolyLog[2, -((b*E^(c + d*x))/(a - Sqrt[a^2 + b^2]))])/((a^2 + b^2)^(3/2)*d^2) - (a*f*PolyLog[2, -((b*E^(c + d*x))/(a + Sqrt[a^2 + b^2]))])/((a^2 + b^2)^(3/2)*d^2) - (b*e*Cosh[c + d*x])/((a^2 + b^2)*d*(a + b*Sinh[c + d*x])) - (b*f*x*Cosh[c + d*x])/((a^2 + b^2)*d*(a + b*Sinh[c + d*x]))}


(* ::Subsubsection::Closed:: *)
(*n/2*)


{x^3*Sqrt[a + a*I*Sinh[x]], x, 5, -96*Sqrt[a + I*a*Sinh[x]] - 12*x^2*Sqrt[a + I*a*Sinh[x]] + 48*I*x*Sqrt[a + I*a*Sinh[x]]*Tan[Pi/4 - (I*x)/2] + 2*I*x^3*Sqrt[a + I*a*Sinh[x]]*Tan[Pi/4 - (I*x)/2]}
{x^2*Sqrt[a + a*I*Sinh[x]], x, 4, -8*x*Sqrt[a + I*a*Sinh[x]] + 16*I*Sqrt[a + I*a*Sinh[x]]*Tan[Pi/4 - (I*x)/2] + 2*I*x^2*Sqrt[a + I*a*Sinh[x]]*Tan[Pi/4 - (I*x)/2]}
{x*Sqrt[a + a*I*Sinh[x]], x, 3, -4*Sqrt[a + I*a*Sinh[x]] + 2*I*x*Sqrt[a + I*a*Sinh[x]]*Tan[Pi/4 - (I*x)/2]}
{Sqrt[a + a*I*Sinh[x]], x, 1, (2*I*a*Cosh[x])/Sqrt[a + I*a*Sinh[x]]}
{Sqrt[a + a*I*Sinh[x]]/x, x, 4, (CoshIntegral[x/2]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/Sqrt[2] + (I*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]]*SinhIntegral[x/2])/Sqrt[2]}
{Sqrt[a + a*I*Sinh[x]]/x^2, x, 5, -(Sqrt[a + I*a*Sinh[x]]/x) + (I*CoshIntegral[x/2]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/(2*Sqrt[2]) + (Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]]*SinhIntegral[x/2])/(2*Sqrt[2])}
{Sqrt[a + a*I*Sinh[x]]/x^3, x, 6, -(Sqrt[a + I*a*Sinh[x]]/(2*x^2)) + (CoshIntegral[x/2]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/(8*Sqrt[2]) + (I*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]]*SinhIntegral[x/2])/(8*Sqrt[2]) - (I*Sqrt[a + I*a*Sinh[x]]*Tan[Pi/4 - (I*x)/2])/(4*x)}


{x^3*(a + a*I*Sinh[x])^(3/2), x, 9, (-(1280/9))*a*Sqrt[a + I*a*Sinh[x]] - 16*a*x^2*Sqrt[a + I*a*Sinh[x]] - (64/27)*a*Cos[Pi/4 - (I*x)/2]^2*Sqrt[a + I*a*Sinh[x]] - (8/3)*a*x^2*Cos[Pi/4 - (I*x)/2]^2*Sqrt[a + I*a*Sinh[x]] + (32/9)*I*a*x*Cos[Pi/4 - (I*x)/2]*Sin[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]] + (4/3)*I*a*x^3*Cos[Pi/4 - (I*x)/2]*Sin[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]] + (640/9)*I*a*x*Sqrt[a + I*a*Sinh[x]]*Tan[Pi/4 - (I*x)/2] + (8/3)*I*a*x^3*Sqrt[a + I*a*Sinh[x]]*Tan[Pi/4 - (I*x)/2]}
{x^2*(a + a*I*Sinh[x])^(3/2), x, 7, (-(32/3))*a*x*Sqrt[a + I*a*Sinh[x]] - (16/9)*a*x*Cos[Pi/4 - (I*x)/2]^2*Sqrt[a + I*a*Sinh[x]] + (4/3)*I*a*x^2*Cos[Pi/4 - (I*x)/2]*Sin[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]] + (224/9)*I*a*Sqrt[a + I*a*Sinh[x]]*Tan[Pi/4 - (I*x)/2] + (8/3)*I*a*x^2*Sqrt[a + I*a*Sinh[x]]*Tan[Pi/4 - (I*x)/2] - (32/27)*I*a*Sin[Pi/4 - (I*x)/2]^2*Sqrt[a + I*a*Sinh[x]]*Tan[Pi/4 - (I*x)/2]}
{x*(a + a*I*Sinh[x])^(3/2), x, 4, (-(16/3))*a*Sqrt[a + I*a*Sinh[x]] - (8/9)*a*Cos[Pi/4 - (I*x)/2]^2*Sqrt[a + I*a*Sinh[x]] + (4/3)*I*a*x*Cos[Pi/4 - (I*x)/2]*Sin[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]] + (8/3)*I*a*x*Sqrt[a + I*a*Sinh[x]]*Tan[Pi/4 - (I*x)/2]}
{(a + a*I*Sinh[x])^(3/2), x, 2, (8*I*a^2*Cosh[x])/(3*Sqrt[a + I*a*Sinh[x]]) + (2/3)*I*a*Cosh[x]*Sqrt[a + I*a*Sinh[x]]}
{(a + a*I*Sinh[x])^(3/2)/x, x, 9, (3*a*CoshIntegral[x/2]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/(2*Sqrt[2]) - (a*CoshIntegral[(3*x)/2]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/(2*Sqrt[2]) + (3*I*a*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]]*SinhIntegral[x/2])/(2*Sqrt[2]) + (I*a*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]]*SinhIntegral[(3*x)/2])/(2*Sqrt[2])}
{(a + a*I*Sinh[x])^(3/2)/x^2, x, 9, -((2*a*Cos[Pi/4 - (I*x)/2]^2*Sqrt[a + I*a*Sinh[x]])/x) + (3*I*a*CoshIntegral[x/2]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/(4*Sqrt[2]) + (3*I*a*CoshIntegral[(3*x)/2]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/(4*Sqrt[2]) + (3*a*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]]*SinhIntegral[x/2])/(4*Sqrt[2]) - (3*a*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]]*SinhIntegral[(3*x)/2])/(4*Sqrt[2])}
{(a + a*I*Sinh[x])^(3/2)/x^3, x, 13, -((a*Cos[Pi/4 - (I*x)/2]^2*Sqrt[a + I*a*Sinh[x]])/x^2) + (3*a*CoshIntegral[x/2]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/(16*Sqrt[2]) - (9*a*CoshIntegral[(3*x)/2]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/(16*Sqrt[2]) - (3*I*a*Cos[Pi/4 - (I*x)/2]*Sin[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/(2*x) + (3*I*a*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]]*SinhIntegral[x/2])/(16*Sqrt[2]) + (9*I*a*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]]*SinhIntegral[(3*x)/2])/(16*Sqrt[2])}


{x^3/Sqrt[a + a*I*Sinh[x]], x, 8, (2*x^3*ArcTan[E^((I*Pi)/4 + x/2)]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/a - (6*I*x^2*PolyLog[2, (-I)*E^((1/4)*I*(Pi - 2*I*x))]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/a + (6*I*x^2*PolyLog[2, I*E^((1/4)*I*(Pi - 2*I*x))]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/a + (24*I*x*PolyLog[3, (-I)*E^((1/4)*I*(Pi - 2*I*x))]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/a - (24*I*x*PolyLog[3, I*E^((1/4)*I*(Pi - 2*I*x))]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/a - (48*I*PolyLog[4, (-I)*E^((1/4)*I*(Pi - 2*I*x))]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/a + (48*I*PolyLog[4, I*E^((1/4)*I*(Pi - 2*I*x))]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/a}
{x^2/Sqrt[a + a*I*Sinh[x]], x, 6, (2*x^2*ArcTan[E^((I*Pi)/4 + x/2)]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/a - (4*I*x*PolyLog[2, (-I)*E^((1/4)*I*(Pi - 2*I*x))]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/a + (4*I*x*PolyLog[2, I*E^((1/4)*I*(Pi - 2*I*x))]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/a + (8*I*PolyLog[3, (-I)*E^((1/4)*I*(Pi - 2*I*x))]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/a - (8*I*PolyLog[3, I*E^((1/4)*I*(Pi - 2*I*x))]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/a}
{x/Sqrt[a + a*I*Sinh[x]], x, 4, (2*x*ArcTan[E^((I*Pi)/4 + x/2)]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/a - (2*I*PolyLog[2, (-I)*E^((1/4)*I*(Pi - 2*I*x))]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/a + (2*I*PolyLog[2, I*E^((1/4)*I*(Pi - 2*I*x))]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/a}
{1/Sqrt[a + a*I*Sinh[x]], x, 1, (2*I*ArcTanh[Sin[Pi/4 - (I*x)/2]]*Cos[Pi/4 - (I*x)/2])/Sqrt[a + I*a*Sinh[x]]}
{1/(x*Sqrt[a + a*I*Sinh[x]]), x, 1, (Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]]*Int[Sec[Pi/4 - (I*x)/2]/x, x])/(2*a)}


(* {x^3/(a + a*I*Sinh[x])^(3/2), x, 14, (3*I*(8 - x^2)*Csc[(1/4)*(Pi + 2*I*x)]*PolyLog[2, (-I)*E^((I*Pi)/4 + x/2)]*Sqrt[a + I*a*Sinh[x]])/(2*a^2) - (3*I*(8 - x^2)*Csc[(1/4)*(Pi + 2*I*x)]*PolyLog[2, I*E^((I*Pi)/4 + x/2)]*Sqrt[a + I*a*Sinh[x]])/(2*a^2) - (12*x*ArcTan[E^((I*Pi)/4 + x/2)]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/a^2 + (x^3*ArcTan[E^((I*Pi)/4 + x/2)]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/(2*a^2) + (6*I*x*PolyLog[3, (-I)*E^((I*Pi)/4 + x/2)]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/a^2 - (6*I*x*PolyLog[3, I*E^((I*Pi)/4 + x/2)]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/a^2 - (12*I*PolyLog[4, (-I)*E^((I*Pi)/4 + x/2)]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/a^2 + (12*I*PolyLog[4, I*E^((I*Pi)/4 + x/2)]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/a^2 + (3*x^2*Sec[Pi/4 - (I*x)/2]^2*Sqrt[a + I*a*Sinh[x]])/(2*a^2) + (I*x^3*Sec[Pi/4 - (I*x)/2]^2*Sqrt[a + I*a*Sinh[x]]*Tan[Pi/4 - (I*x)/2])/(4*a^2)} *)
{x^2/(a + a*I*Sinh[x])^(3/2), x, 8, (x^2*ArcTan[E^((I*Pi)/4 + x/2)]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/(2*a^2) - (2*I*ArcTanh[Sin[Pi/4 - (I*x)/2]]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/a^2 - (I*x*PolyLog[2, (-I)*E^((1/4)*I*(Pi - 2*I*x))]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/a^2 + (I*x*PolyLog[2, I*E^((1/4)*I*(Pi - 2*I*x))]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/a^2 + (2*I*PolyLog[3, (-I)*E^((1/4)*I*(Pi - 2*I*x))]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/a^2 - (2*I*PolyLog[3, I*E^((1/4)*I*(Pi - 2*I*x))]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/a^2 + (x*Sec[Pi/4 - (I*x)/2]^2*Sqrt[a + I*a*Sinh[x]])/a^2 + (I*x^2*Sec[Pi/4 - (I*x)/2]^2*Sqrt[a + I*a*Sinh[x]]*Tan[Pi/4 - (I*x)/2])/(4*a^2)}
{x/(a + a*I*Sinh[x])^(3/2), x, 5, (x*ArcTan[E^((I*Pi)/4 + x/2)]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/(2*a^2) - (I*PolyLog[2, (-I)*E^((1/4)*I*(Pi - 2*I*x))]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/(2*a^2) + (I*PolyLog[2, I*E^((1/4)*I*(Pi - 2*I*x))]*Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]])/(2*a^2) + (Sec[Pi/4 - (I*x)/2]^2*Sqrt[a + I*a*Sinh[x]])/(2*a^2) + (I*x*Sec[Pi/4 - (I*x)/2]^2*Sqrt[a + I*a*Sinh[x]]*Tan[Pi/4 - (I*x)/2])/(4*a^2)}
{1/(a + a*I*Sinh[x])^(3/2), x, 2, (I*Cosh[x])/(2*(a + I*a*Sinh[x])^(3/2)) + (I*ArcTanh[Sin[Pi/4 - (I*x)/2]]*Cos[Pi/4 - (I*x)/2])/(2*a*Sqrt[a + I*a*Sinh[x]])}
{1/(x*(a + a*I*Sinh[x])^(3/2)), x, 1, (Sec[Pi/4 - (I*x)/2]*Sqrt[a + I*a*Sinh[x]]*Int[Sec[Pi/4 - (I*x)/2]^3/x, x])/(4*a^2)}


(* Integrands of the form x^m*(a-a*Sinh[x])^n where m is an integer and n is a half-integer *)
{x^3*Sqrt[a - a*I*Sinh[x]], x, 5, -96*Sqrt[a - I*a*Sinh[x]] - 12*x^2*Sqrt[a - I*a*Sinh[x]] - 48*I*x*Sqrt[a - I*a*Sinh[x]]*Tan[Pi/4 + (I*x)/2] - 2*I*x^3*Sqrt[a - I*a*Sinh[x]]*Tan[Pi/4 + (I*x)/2]}
{x^2*Sqrt[a - a*I*Sinh[x]], x, 4, -8*x*Sqrt[a - I*a*Sinh[x]] - 16*I*Sqrt[a - I*a*Sinh[x]]*Tan[Pi/4 + (I*x)/2] - 2*I*x^2*Sqrt[a - I*a*Sinh[x]]*Tan[Pi/4 + (I*x)/2]}
{x*Sqrt[a - a*I*Sinh[x]], x, 3, -4*Sqrt[a - I*a*Sinh[x]] - 2*I*x*Sqrt[a - I*a*Sinh[x]]*Tan[Pi/4 + (I*x)/2]}
{Sqrt[a - a*I*Sinh[x]], x, 1, -((2*I*a*Cosh[x])/Sqrt[a - I*a*Sinh[x]])}
{Sqrt[a - a*I*Sinh[x]]/x, x, 4, (CoshIntegral[x/2]*Sec[Pi/4 + (I*x)/2]*Sqrt[a - I*a*Sinh[x]])/Sqrt[2] - (I*Sec[Pi/4 + (I*x)/2]*Sqrt[a - I*a*Sinh[x]]*SinhIntegral[x/2])/Sqrt[2]}
{Sqrt[a - a*I*Sinh[x]]/x^2, x, 5, -(Sqrt[a - I*a*Sinh[x]]/x) - (I*CoshIntegral[x/2]*Sec[Pi/4 + (I*x)/2]*Sqrt[a - I*a*Sinh[x]])/(2*Sqrt[2]) + (Sec[Pi/4 + (I*x)/2]*Sqrt[a - I*a*Sinh[x]]*SinhIntegral[x/2])/(2*Sqrt[2])}
{Sqrt[a - a*I*Sinh[x]]/x^3, x, 6, -(Sqrt[a - I*a*Sinh[x]]/(2*x^2)) + (CoshIntegral[x/2]*Sec[Pi/4 + (I*x)/2]*Sqrt[a - I*a*Sinh[x]])/(8*Sqrt[2]) - (I*Sec[Pi/4 + (I*x)/2]*Sqrt[a - I*a*Sinh[x]]*SinhIntegral[x/2])/(8*Sqrt[2]) + (I*Sqrt[a - I*a*Sinh[x]]*Tan[Pi/4 + (I*x)/2])/(4*x)}

{x^3/Sqrt[a - a*I*Sinh[x]], x, 8, -((2*x^3*ArcTan[E^((I*Pi)/4 - x/2)]*Sec[Pi/4 + (I*x)/2]*Sqrt[a - I*a*Sinh[x]])/a) - (6*I*x^2*PolyLog[2, (-I)*E^((1/4)*I*(Pi + 2*I*x))]*Sec[Pi/4 + (I*x)/2]*Sqrt[a - I*a*Sinh[x]])/a + (6*I*x^2*PolyLog[2, I*E^((1/4)*I*(Pi + 2*I*x))]*Sec[Pi/4 + (I*x)/2]*Sqrt[a - I*a*Sinh[x]])/a - (24*I*x*PolyLog[3, (-I)*E^((1/4)*I*(Pi + 2*I*x))]*Sec[Pi/4 + (I*x)/2]*Sqrt[a - I*a*Sinh[x]])/a + (24*I*x*PolyLog[3, I*E^((1/4)*I*(Pi + 2*I*x))]*Sec[Pi/4 + (I*x)/2]*Sqrt[a - I*a*Sinh[x]])/a - (48*I*PolyLog[4, (-I)*E^((1/4)*I*(Pi + 2*I*x))]*Sec[Pi/4 + (I*x)/2]*Sqrt[a - I*a*Sinh[x]])/a + (48*I*PolyLog[4, I*E^((1/4)*I*(Pi + 2*I*x))]*Sec[Pi/4 + (I*x)/2]*Sqrt[a - I*a*Sinh[x]])/a}
{x^2/Sqrt[a - a*I*Sinh[x]], x, 6, -((2*x^2*ArcTan[E^((I*Pi)/4 - x/2)]*Sec[Pi/4 + (I*x)/2]*Sqrt[a - I*a*Sinh[x]])/a) - (4*I*x*PolyLog[2, (-I)*E^((1/4)*I*(Pi + 2*I*x))]*Sec[Pi/4 + (I*x)/2]*Sqrt[a - I*a*Sinh[x]])/a + (4*I*x*PolyLog[2, I*E^((1/4)*I*(Pi + 2*I*x))]*Sec[Pi/4 + (I*x)/2]*Sqrt[a - I*a*Sinh[x]])/a - (8*I*PolyLog[3, (-I)*E^((1/4)*I*(Pi + 2*I*x))]*Sec[Pi/4 + (I*x)/2]*Sqrt[a - I*a*Sinh[x]])/a + (8*I*PolyLog[3, I*E^((1/4)*I*(Pi + 2*I*x))]*Sec[Pi/4 + (I*x)/2]*Sqrt[a - I*a*Sinh[x]])/a}
{x/Sqrt[a - a*I*Sinh[x]], x, 4, -((2*x*ArcTan[E^((I*Pi)/4 - x/2)]*Sec[Pi/4 + (I*x)/2]*Sqrt[a - I*a*Sinh[x]])/a) - (2*I*PolyLog[2, (-I)*E^((1/4)*I*(Pi + 2*I*x))]*Sec[Pi/4 + (I*x)/2]*Sqrt[a - I*a*Sinh[x]])/a + (2*I*PolyLog[2, I*E^((1/4)*I*(Pi + 2*I*x))]*Sec[Pi/4 + (I*x)/2]*Sqrt[a - I*a*Sinh[x]])/a}
{1/Sqrt[a - a*I*Sinh[x]], x, 1, -((2*I*ArcTanh[Sin[Pi/4 + (I*x)/2]]*Cos[Pi/4 + (I*x)/2])/Sqrt[a - I*a*Sinh[x]])}
{1/(x*Sqrt[a - a*I*Sinh[x]]), x, 1, (Int[Sec[Pi/4 + (I*x)/2]/x, x]*Sec[Pi/4 + (I*x)/2]*Sqrt[a - I*a*Sinh[x]])/(2*a)}


(* Integrands of the form x^m*(a+a*Sinh[c+d*x])^n where m is an integer and n is a half-integer *)
{x^3*Sqrt[a + a*I*Sinh[c + d*x]], x, 5, -((96*Sqrt[a + I*a*Sinh[c + d*x]])/d^4) - (12*x^2*Sqrt[a + I*a*Sinh[c + d*x]])/d^2 + (48*x*Sqrt[a + I*a*Sinh[c + d*x]]*Tanh[(1/4)*(2*c + I*Pi) + (d*x)/2])/d^3 + (2*x^3*Sqrt[a + I*a*Sinh[c + d*x]]*Tanh[(1/4)*(2*c + I*Pi) + (d*x)/2])/d}
{x^2*Sqrt[a + a*I*Sinh[c + d*x]], x, 4, -((8*x*Sqrt[a + I*a*Sinh[c + d*x]])/d^2) + (16*Sqrt[a + I*a*Sinh[c + d*x]]*Tanh[(1/4)*(2*c + I*Pi) + (d*x)/2])/d^3 + (2*x^2*Sqrt[a + I*a*Sinh[c + d*x]]*Tanh[(1/4)*(2*c + I*Pi) + (d*x)/2])/d}
{x*Sqrt[a + a*I*Sinh[c + d*x]], x, 3, -((4*Sqrt[a + I*a*Sinh[c + d*x]])/d^2) + (2*x*Sqrt[a + I*a*Sinh[c + d*x]]*Tanh[(1/4)*(2*c + I*Pi) + (d*x)/2])/d}
{Sqrt[a + a*I*Sinh[c + d*x]], x, 1, (2*I*a*Cosh[c + d*x])/(d*Sqrt[a + I*a*Sinh[c + d*x]])}
{Sqrt[a + a*I*Sinh[c + d*x]]/x, x, 4, Cosh[(1/4)*(2*c + I*Pi)]*CoshIntegral[(d*x)/2]*Sech[(1/4)*(2*c + I*Pi) + (d*x)/2]*Sqrt[a + I*a*Sinh[c + d*x]] + Sech[(1/4)*(2*c + I*Pi) + (d*x)/2]*Sinh[(1/4)*(2*c + I*Pi)]*Sqrt[a + I*a*Sinh[c + d*x]]*SinhIntegral[(d*x)/2]}
{Sqrt[a + a*I*Sinh[c + d*x]]/x^2, x, 5, -(Sqrt[a + I*a*Sinh[c + d*x]]/x) + (1/2)*d*CoshIntegral[(d*x)/2]*Sech[(1/4)*(2*c + I*Pi) + (d*x)/2]*Sinh[(1/4)*(2*c + I*Pi)]*Sqrt[a + I*a*Sinh[c + d*x]] + (1/2)*d*Cosh[(1/4)*(2*c + I*Pi)]*Sech[(1/4)*(2*c + I*Pi) + (d*x)/2]*Sqrt[a + I*a*Sinh[c + d*x]]*SinhIntegral[(d*x)/2]}
{Sqrt[a + a*I*Sinh[c + d*x]]/x^3, x, 6, -(Sqrt[a + I*a*Sinh[c + d*x]]/(2*x^2)) + (1/8)*d^2*Cosh[(1/4)*(2*c + I*Pi)]*CoshIntegral[(d*x)/2]*Sech[(1/4)*(2*c + I*Pi) + (d*x)/2]*Sqrt[a + I*a*Sinh[c + d*x]] + (1/8)*d^2*Sech[(1/4)*(2*c + I*Pi) + (d*x)/2]*Sinh[(1/4)*(2*c + I*Pi)]*Sqrt[a + I*a*Sinh[c + d*x]]*SinhIntegral[(d*x)/2] - (d*Sqrt[a + I*a*Sinh[c + d*x]]*Tanh[(1/4)*(2*c + I*Pi) + (d*x)/2])/(4*x)}

{x^3/Sqrt[a + a*I*Sinh[c + d*x]], x, 8, (2*x^3*ArcTan[E^((1/4)*(2*c + I*Pi) + (d*x)/2)]*Sech[(1/4)*(2*c + I*Pi) + (d*x)/2]*Sqrt[a + I*a*Sinh[c + d*x]])/(a*d) - (6*I*x^2*PolyLog[2, (-I)*E^((1/4)*(2*c + I*Pi) + (d*x)/2)]*Sech[(1/4)*(2*c + I*Pi) + (d*x)/2]*Sqrt[a + I*a*Sinh[c + d*x]])/(a*d^2) + (6*I*x^2*PolyLog[2, I*E^((1/4)*(2*c + I*Pi) + (d*x)/2)]*Sech[(1/4)*(2*c + I*Pi) + (d*x)/2]*Sqrt[a + I*a*Sinh[c + d*x]])/(a*d^2) + (24*I*x*PolyLog[3, (-I)*E^((1/4)*(2*c + I*Pi) + (d*x)/2)]*Sech[(1/4)*(2*c + I*Pi) + (d*x)/2]*Sqrt[a + I*a*Sinh[c + d*x]])/(a*d^3) - (24*I*x*PolyLog[3, I*E^((1/4)*(2*c + I*Pi) + (d*x)/2)]*Sech[(1/4)*(2*c + I*Pi) + (d*x)/2]*Sqrt[a + I*a*Sinh[c + d*x]])/(a*d^3) - (48*I*PolyLog[4, (-I)*E^((1/4)*(2*c + I*Pi) + (d*x)/2)]*Sech[(1/4)*(2*c + I*Pi) + (d*x)/2]*Sqrt[a + I*a*Sinh[c + d*x]])/(a*d^4) + (48*I*PolyLog[4, I*E^((1/4)*(2*c + I*Pi) + (d*x)/2)]*Sech[(1/4)*(2*c + I*Pi) + (d*x)/2]*Sqrt[a + I*a*Sinh[c + d*x]])/(a*d^4)}
{x^2/Sqrt[a + a*I*Sinh[c + d*x]], x, 6, (2*x^2*ArcTan[E^((1/4)*(2*c + I*Pi) + (d*x)/2)]*Sech[(1/4)*(2*c + I*Pi) + (d*x)/2]*Sqrt[a + I*a*Sinh[c + d*x]])/(a*d) - (4*I*x*PolyLog[2, (-I)*E^((1/4)*(2*c + I*Pi) + (d*x)/2)]*Sech[(1/4)*(2*c + I*Pi) + (d*x)/2]*Sqrt[a + I*a*Sinh[c + d*x]])/(a*d^2) + (4*I*x*PolyLog[2, I*E^((1/4)*(2*c + I*Pi) + (d*x)/2)]*Sech[(1/4)*(2*c + I*Pi) + (d*x)/2]*Sqrt[a + I*a*Sinh[c + d*x]])/(a*d^2) + (8*I*PolyLog[3, (-I)*E^((1/4)*(2*c + I*Pi) + (d*x)/2)]*Sech[(1/4)*(2*c + I*Pi) + (d*x)/2]*Sqrt[a + I*a*Sinh[c + d*x]])/(a*d^3) - (8*I*PolyLog[3, I*E^((1/4)*(2*c + I*Pi) + (d*x)/2)]*Sech[(1/4)*(2*c + I*Pi) + (d*x)/2]*Sqrt[a + I*a*Sinh[c + d*x]])/(a*d^3)}
{x/Sqrt[a + a*I*Sinh[c + d*x]], x, 4, (2*x*ArcTan[E^((1/4)*(2*c + I*Pi) + (d*x)/2)]*Sech[(1/4)*(2*c + I*Pi) + (d*x)/2]*Sqrt[a + I*a*Sinh[c + d*x]])/(a*d) - (2*I*PolyLog[2, (-I)*E^((1/4)*(2*c + I*Pi) + (d*x)/2)]*Sech[(1/4)*(2*c + I*Pi) + (d*x)/2]*Sqrt[a + I*a*Sinh[c + d*x]])/(a*d^2) + (2*I*PolyLog[2, I*E^((1/4)*(2*c + I*Pi) + (d*x)/2)]*Sech[(1/4)*(2*c + I*Pi) + (d*x)/2]*Sqrt[a + I*a*Sinh[c + d*x]])/(a*d^2)}
{1/Sqrt[a + a*I*Sinh[c + d*x]], x, 1, (2*I*ArcTanh[Sin[Pi/4 - (1/2)*I*(c + d*x)]]*Cos[Pi/4 - (1/2)*I*(c + d*x)])/(d*Sqrt[a + I*a*Sinh[c + d*x]])}
{1/(x*Sqrt[a + a*I*Sinh[c + d*x]]), x, 1, (Int[Sech[c/2 + (I*Pi)/4 + (d*x)/2]/x, x]*Sech[(1/4)*(2*c + I*Pi) + (d*x)/2]*Sqrt[a + I*a*Sinh[c + d*x]])/(2*a)}


(* Used to hang Rubi *)
(* {(a + a*I*Sinh[c + d*x])^(1/3)/x, x, 0, Int[(a + a*I*Sinh[c + d*x])^(1/3)/x, x]} *)


(* ::Subsection::Closed:: *)
(*Integrands of the form (e+f x)^m (a+b Sinh[c+d x]^2)^p*)


{x/(a + b*Sinh[x]^2), x, 9, (x*Log[1 + (b*E^(2*x))/(2*a - 2*Sqrt[a]*Sqrt[a - b] - b)])/(2*Sqrt[a]*Sqrt[a - b]) - (x*Log[1 + (b*E^(2*x))/(2*a + 2*Sqrt[a]*Sqrt[a - b] - b)])/(2*Sqrt[a]*Sqrt[a - b]) + PolyLog[2, -((b*E^(2*x))/(2*a - 2*Sqrt[a]*Sqrt[a - b] - b))]/(4*Sqrt[a]*Sqrt[a - b]) - PolyLog[2, -((b*E^(2*x))/(2*a + 2*Sqrt[a]*Sqrt[a - b] - b))]/(4*Sqrt[a]*Sqrt[a - b])}
{x^2/(a + b*Sinh[x]^2), x, 11, (x^2*Log[1 + (b*E^(2*x))/(2*a - 2*Sqrt[a]*Sqrt[a - b] - b)])/(2*Sqrt[a]*Sqrt[a - b]) - (x^2*Log[1 + (b*E^(2*x))/(2*a + 2*Sqrt[a]*Sqrt[a - b] - b)])/(2*Sqrt[a]*Sqrt[a - b]) + (x*PolyLog[2, -((b*E^(2*x))/(2*a - 2*Sqrt[a]*Sqrt[a - b] - b))])/(2*Sqrt[a]*Sqrt[a - b]) - (x*PolyLog[2, -((b*E^(2*x))/(2*a + 2*Sqrt[a]*Sqrt[a - b] - b))])/(2*Sqrt[a]*Sqrt[a - b]) - PolyLog[3, -((b*E^(2*x))/(2*a - 2*Sqrt[a]*Sqrt[a - b] - b))]/(4*Sqrt[a]*Sqrt[a - b]) + PolyLog[3, -((b*E^(2*x))/(2*a + 2*Sqrt[a]*Sqrt[a - b] - b))]/(4*Sqrt[a]*Sqrt[a - b])}
{x^3/(a + b*Sinh[x]^2), x, 13, (x^3*Log[1 + (b*E^(2*x))/(2*a - 2*Sqrt[a]*Sqrt[a - b] - b)])/(2*Sqrt[a]*Sqrt[a - b]) - (x^3*Log[1 + (b*E^(2*x))/(2*a + 2*Sqrt[a]*Sqrt[a - b] - b)])/(2*Sqrt[a]*Sqrt[a - b]) + (3*x^2*PolyLog[2, -((b*E^(2*x))/(2*a - 2*Sqrt[a]*Sqrt[a - b] - b))])/(4*Sqrt[a]*Sqrt[a - b]) - (3*x^2*PolyLog[2, -((b*E^(2*x))/(2*a + 2*Sqrt[a]*Sqrt[a - b] - b))])/(4*Sqrt[a]*Sqrt[a - b]) - (3*x*PolyLog[3, -((b*E^(2*x))/(2*a - 2*Sqrt[a]*Sqrt[a - b] - b))])/(4*Sqrt[a]*Sqrt[a - b]) + (3*x*PolyLog[3, -((b*E^(2*x))/(2*a + 2*Sqrt[a]*Sqrt[a - b] - b))])/(4*Sqrt[a]*Sqrt[a - b]) + (3*PolyLog[4, -((b*E^(2*x))/(2*a - 2*Sqrt[a]*Sqrt[a - b] - b))])/(8*Sqrt[a]*Sqrt[a - b]) - (3*PolyLog[4, -((b*E^(2*x))/(2*a + 2*Sqrt[a]*Sqrt[a - b] - b))])/(8*Sqrt[a]*Sqrt[a - b])}


(* ::Section::Closed:: *)
(*Integrands of the form (d+e x)^m Sinh[a+b x+c x^2]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (d+e x)^m Sinh[a+b x+c x^2]^n*)


{x^2*Sinh[a + b*x + c*x^2], x, 12, -((b*Cosh[a + b*x + c*x^2])/(4*c^2)) + (x*Cosh[a + b*x + c*x^2])/(2*c) - (b^2*E^(-a + b^2/(4*c))*Sqrt[Pi]*Erf[(b + 2*c*x)/(2*Sqrt[c])])/(16*c^(5/2)) - (E^(-a + b^2/(4*c))*Sqrt[Pi]*Erf[(b + 2*c*x)/(2*Sqrt[c])])/(8*c^(3/2)) + (b^2*E^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b + 2*c*x)/(2*Sqrt[c])])/(16*c^(5/2)) - (E^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b + 2*c*x)/(2*Sqrt[c])])/(8*c^(3/2))}
{x*Sinh[a + b*x + c*x^2], x, 6, Cosh[a + b*x + c*x^2]/(2*c) + (b*E^(-a + b^2/(4*c))*Sqrt[Pi]*Erf[(b + 2*c*x)/(2*Sqrt[c])])/(8*c^(3/2)) - (b*E^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b + 2*c*x)/(2*Sqrt[c])])/(8*c^(3/2))}
{Sinh[a + b*x + c*x^2], x, 5, -((E^(-a + b^2/(4*c))*Sqrt[Pi]*Erf[(b + 2*c*x)/(2*Sqrt[c])])/(4*Sqrt[c])) + (E^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b + 2*c*x)/(2*Sqrt[c])])/(4*Sqrt[c])}
{Sinh[a + b*x + c*x^2]/x, x, 0, Int[Sinh[a + b*x + c*x^2]/x, x]}
{Sinh[a + b*x + c*x^2]/x^2 - b*Cosh[a + b*x + c*x^2]/x, x, 7, (1/2)*Sqrt[c]*E^(-a + b^2/(4*c))*Sqrt[Pi]*Erf[(b + 2*c*x)/(2*Sqrt[c])] + (1/2)*Sqrt[c]*E^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b + 2*c*x)/(2*Sqrt[c])] - Sinh[a + b*x + c*x^2]/x}

{x^2*Sinh[a + b*x - c*x^2], x, 12, -((b*Cosh[a + b*x - c*x^2])/(4*c^2)) - (x*Cosh[a + b*x - c*x^2])/(2*c) - (b^2*E^(a + b^2/(4*c))*Sqrt[Pi]*Erf[(b - 2*c*x)/(2*Sqrt[c])])/(16*c^(5/2)) - (E^(a + b^2/(4*c))*Sqrt[Pi]*Erf[(b - 2*c*x)/(2*Sqrt[c])])/(8*c^(3/2)) + (b^2*E^(-a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b - 2*c*x)/(2*Sqrt[c])])/(16*c^(5/2)) - (E^(-a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b - 2*c*x)/(2*Sqrt[c])])/(8*c^(3/2))}
{x*Sinh[a + b*x - c*x^2], x, 6, -(Cosh[a + b*x - c*x^2]/(2*c)) - (b*E^(a + b^2/(4*c))*Sqrt[Pi]*Erf[(b - 2*c*x)/(2*Sqrt[c])])/(8*c^(3/2)) + (b*E^(-a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b - 2*c*x)/(2*Sqrt[c])])/(8*c^(3/2))}
{Sinh[a + b*x - c*x^2], x, 5, -((E^(a + b^2/(4*c))*Sqrt[Pi]*Erf[(b - 2*c*x)/(2*Sqrt[c])])/(4*Sqrt[c])) + (E^(-a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b - 2*c*x)/(2*Sqrt[c])])/(4*Sqrt[c])}
{Sinh[a + b*x - c*x^2]/x, x, 0, Int[Sinh[a + b*x - c*x^2]/x, x]}
{Sinh[a + b*x - c*x^2]/x^2 - b*Cosh[a + b*x - c*x^2]/x, x, 7, (1/2)*Sqrt[c]*E^(a + b^2/(4*c))*Sqrt[Pi]*Erf[(b - 2*c*x)/(2*Sqrt[c])] + (1/2)*Sqrt[c]*E^(-a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b - 2*c*x)/(2*Sqrt[c])] - Sinh[a + b*x - c*x^2]/x}

{x^2*Sinh[1/4 + x + x^2], x, 12, (-(1/4))*Cosh[1/4 + x + x^2] + (1/2)*x*Cosh[1/4 + x + x^2] + (3/16)*Sqrt[Pi]*Erf[(1/2)*(-1 - 2*x)] - (1/16)*Sqrt[Pi]*Erfi[(1/2)*(1 + 2*x)]}
{x*Sinh[1/4 + x + x^2], x, 6, (1/2)*Cosh[1/4 + x + x^2] - (1/8)*Sqrt[Pi]*Erf[(1/2)*(-1 - 2*x)] - (1/8)*Sqrt[Pi]*Erfi[(1/2)*(1 + 2*x)]}
{Sinh[1/4 + x + x^2], x, 5, (1/4)*Sqrt[Pi]*Erf[(1/2)*(-1 - 2*x)] + (1/4)*Sqrt[Pi]*Erfi[(1/2)*(1 + 2*x)]}
{Sinh[1/4 + x + x^2]/x, x, 0, Int[Sinh[1/4 + x + x^2]/x, x]}
{Sinh[1/4 + x + x^2]/x^2, x, 6, (-(1/2))*Sqrt[Pi]*Erf[(1/2)*(-1 - 2*x)] + (1/2)*Sqrt[Pi]*Erfi[(1/2)*(1 + 2*x)] + Int[Cosh[1/4 + x + x^2]/x, x] - Sinh[1/4 + x + x^2]/x}


{x^2*Sinh[a + b*x + c*x^2]^2, x, 14, -(x^3/6) + (b^2*E^(-2*a + b^2/(2*c))*Sqrt[Pi/2]*Erf[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(32*c^(5/2)) + (E^(-2*a + b^2/(2*c))*Sqrt[Pi/2]*Erf[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(32*c^(3/2)) + (b^2*E^(2*a - b^2/(2*c))*Sqrt[Pi/2]*Erfi[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(32*c^(5/2)) - (E^(2*a - b^2/(2*c))*Sqrt[Pi/2]*Erfi[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(32*c^(3/2)) - (b*Sinh[2*a + 2*b*x + 2*c*x^2])/(16*c^2) + (x*Sinh[2*a + 2*b*x + 2*c*x^2])/(8*c)}
{x*Sinh[a + b*x + c*x^2]^2, x, 8, -(x^2/4) - (b*E^(-2*a + b^2/(2*c))*Sqrt[Pi/2]*Erf[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(16*c^(3/2)) - (b*E^(2*a - b^2/(2*c))*Sqrt[Pi/2]*Erfi[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(16*c^(3/2)) + Sinh[2*a + 2*b*x + 2*c*x^2]/(8*c)}
{Sinh[a + b*x + c*x^2]^2, x, 7, -(x/2) + (E^(-2*a + b^2/(2*c))*Sqrt[Pi/2]*Erf[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(8*Sqrt[c]) + (E^(2*a - b^2/(2*c))*Sqrt[Pi/2]*Erfi[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(8*Sqrt[c])}
{Sinh[a + b*x + c*x^2]^2/x, x, 2, (1/2)*Int[Cosh[2*a + 2*b*x + 2*c*x^2]/x, x] - Log[x]/2}

{x^2*Sinh[a + b*x - c*x^2]^2, x, 14, -(x^3/6) - (b^2*E^(2*a + b^2/(2*c))*Sqrt[Pi/2]*Erf[(b - 2*c*x)/(Sqrt[2]*Sqrt[c])])/(32*c^(5/2)) - (E^(2*a + b^2/(2*c))*Sqrt[Pi/2]*Erf[(b - 2*c*x)/(Sqrt[2]*Sqrt[c])])/(32*c^(3/2)) - (b^2*E^(-2*a - b^2/(2*c))*Sqrt[Pi/2]*Erfi[(b - 2*c*x)/(Sqrt[2]*Sqrt[c])])/(32*c^(5/2)) + (E^(-2*a - b^2/(2*c))*Sqrt[Pi/2]*Erfi[(b - 2*c*x)/(Sqrt[2]*Sqrt[c])])/(32*c^(3/2)) - (b*Sinh[2*a + 2*b*x - 2*c*x^2])/(16*c^2) - (x*Sinh[2*a + 2*b*x - 2*c*x^2])/(8*c)}
{x*Sinh[a + b*x - c*x^2]^2, x, 8, -(x^2/4) - (b*E^(2*a + b^2/(2*c))*Sqrt[Pi/2]*Erf[(b - 2*c*x)/(Sqrt[2]*Sqrt[c])])/(16*c^(3/2)) - (b*E^(-2*a - b^2/(2*c))*Sqrt[Pi/2]*Erfi[(b - 2*c*x)/(Sqrt[2]*Sqrt[c])])/(16*c^(3/2)) - Sinh[2*a + 2*b*x - 2*c*x^2]/(8*c)}
{Sinh[a + b*x - c*x^2]^2, x, 7, -(x/2) - (E^(2*a + b^2/(2*c))*Sqrt[Pi/2]*Erf[(b - 2*c*x)/(Sqrt[2]*Sqrt[c])])/(8*Sqrt[c]) - (E^(-2*a - b^2/(2*c))*Sqrt[Pi/2]*Erfi[(b - 2*c*x)/(Sqrt[2]*Sqrt[c])])/(8*Sqrt[c])}
{Sinh[a + b*x - c*x^2]^2/x, x, 2, (1/2)*Int[Cosh[2*a + 2*b*x - 2*c*x^2]/x, x] - Log[x]/2}

{x^2*Sinh[1/4 + x + x^2]^2, x, 14, -(x^3/6) + (1/16)*Sqrt[Pi/2]*Erf[(1 + 2*x)/Sqrt[2]] - (1/16)*Sinh[1/2 + 2*x + 2*x^2] + (1/8)*x*Sinh[1/2 + 2*x + 2*x^2]}
{x*Sinh[1/4 + x + x^2]^2, x, 8, -(x^2/4) - (1/16)*Sqrt[Pi/2]*Erf[(1 + 2*x)/Sqrt[2]] - (1/16)*Sqrt[Pi/2]*Erfi[(1 + 2*x)/Sqrt[2]] + (1/8)*Sinh[1/2 + 2*x + 2*x^2]}
{Sinh[1/4 + x + x^2]^2, x, 7, -(x/2) + (1/8)*Sqrt[Pi/2]*Erf[(1 + 2*x)/Sqrt[2]] + (1/8)*Sqrt[Pi/2]*Erfi[(1 + 2*x)/Sqrt[2]]}
{Sinh[1/4 + x + x^2]^2/x, x, 2, (1/2)*Int[Cosh[1/2 + 2*x + 2*x^2]/x, x] - Log[x]/2}


{(d + e*x)^2*Sinh[a + b*x + c*x^2], x, 12, (e*(2*c*d - b*e)*Cosh[a + b*x + c*x^2])/(4*c^2) + (e*(d + e*x)*Cosh[a + b*x + c*x^2])/(2*c) - (e^2*E^(-a + b^2/(4*c))*Sqrt[Pi]*Erf[(b + 2*c*x)/(2*Sqrt[c])])/(8*c^(3/2)) - ((2*c*d - b*e)^2*E^(-a + b^2/(4*c))*Sqrt[Pi]*Erf[(b + 2*c*x)/(2*Sqrt[c])])/(16*c^(5/2)) - (e^2*E^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b + 2*c*x)/(2*Sqrt[c])])/(8*c^(3/2)) + ((2*c*d - b*e)^2*E^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b + 2*c*x)/(2*Sqrt[c])])/(16*c^(5/2))}
{(d + e*x)*Sinh[a + b*x + c*x^2], x, 6, (e*Cosh[a + b*x + c*x^2])/(2*c) - ((2*c*d - b*e)*E^(-a + b^2/(4*c))*Sqrt[Pi]*Erf[(b + 2*c*x)/(2*Sqrt[c])])/(8*c^(3/2)) + ((2*c*d - b*e)*E^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b + 2*c*x)/(2*Sqrt[c])])/(8*c^(3/2))}
{Sinh[a + b*x + c*x^2]/(d + e*x), x, 0, Int[Sinh[a + b*x + c*x^2]/(d + e*x), x]}

{(d + e*x)^2*Sinh[a + b*x + c*x^2]^2, x, 14, -((d + e*x)^3/(6*e)) + (e^2*E^(-2*a + b^2/(2*c))*Sqrt[Pi/2]*Erf[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(32*c^(3/2)) + ((2*c*d - b*e)^2*E^(-2*a + b^2/(2*c))*Sqrt[Pi/2]*Erf[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(32*c^(5/2)) - (e^2*E^(2*a - b^2/(2*c))*Sqrt[Pi/2]*Erfi[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(32*c^(3/2)) + ((2*c*d - b*e)^2*E^(2*a - b^2/(2*c))*Sqrt[Pi/2]*Erfi[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(32*c^(5/2)) + (e*(2*c*d - b*e)*Sinh[2*a + 2*b*x + 2*c*x^2])/(16*c^2) + (e*(d + e*x)*Sinh[2*a + 2*b*x + 2*c*x^2])/(8*c)}
{(d + e*x)*Sinh[a + b*x + c*x^2]^2, x, 8, -((d + e*x)^2/(4*e)) + ((2*c*d - b*e)*E^(-2*a + b^2/(2*c))*Sqrt[Pi/2]*Erf[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(16*c^(3/2)) + ((2*c*d - b*e)*E^(2*a - b^2/(2*c))*Sqrt[Pi/2]*Erfi[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(16*c^(3/2)) + (e*Sinh[2*a + 2*b*x + 2*c*x^2])/(8*c)}
{Sinh[a + b*x + c*x^2]^2/(d + e*x), x, 2, (1/2)*Int[Cosh[2*a + 2*b*x + 2*c*x^2]/(d + e*x), x] - Log[d + e*x]/(2*e)}


(* ::Subsection:: *)
(*Integrands of the form (d+e x)^m Sinh[a+b x+c x^2]^(n/2)*)


(* ::Section::Closed:: *)
(*Integrands of the form x^m Sinh[a+b x^n]^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Sinh[a+b x^2]^p*)


(* ::Subsubsection::Closed:: *)
(*p>0*)


{x^m*Sinh[a + b*x^2], x, 3, (-(1/4))*E^a*x^(1 + m)*((-b)*x^2)^((1/2)*(-1 - m))*Gamma[(1 + m)/2, (-b)*x^2] + ((1/4)*x^(1 + m)*(b*x^2)^((1/2)*(-1 - m))*Gamma[(1 + m)/2, b*x^2])/E^a}

{x^3*Sinh[a + b*x^2], x, 2, (x^2*Cosh[a + b*x^2])/(2*b) - Sinh[a + b*x^2]/(2*b^2)}
{x^2*Sinh[a + b*x^2], x, 4, (x*Cosh[a + b*x^2])/(2*b) - (Sqrt[Pi]*Erf[Sqrt[b]*x])/(E^a*(8*b^(3/2))) - (E^a*Sqrt[Pi]*Erfi[Sqrt[b]*x])/(8*b^(3/2))}
{x*Sinh[a + b*x^2], x, 1, Cosh[a + b*x^2]/(2*b)}
{Sinh[a + b*x^2], x, 3, -((Sqrt[Pi]*Erf[Sqrt[b]*x])/(E^a*(4*Sqrt[b]))) + (E^a*Sqrt[Pi]*Erfi[Sqrt[b]*x])/(4*Sqrt[b])}
{Sinh[a + b*x^2]/x, x, 3, (1/2)*CoshIntegral[b*x^2]*Sinh[a] + (1/2)*Cosh[a]*SinhIntegral[b*x^2]}
{Sinh[a + b*x^2]/x^2, x, 4, ((1/2)*Sqrt[b]*Sqrt[Pi]*Erf[Sqrt[b]*x])/E^a + (1/2)*Sqrt[b]*E^a*Sqrt[Pi]*Erfi[Sqrt[b]*x] - Sinh[a + b*x^2]/x}
{Sinh[a + b*x^2]/x^3, x, 4, (1/2)*b*Cosh[a]*CoshIntegral[b*x^2] - Sinh[a + b*x^2]/(2*x^2) + (1/2)*b*Sinh[a]*SinhIntegral[b*x^2]}


{x^m*Sinh[a + b*x^2]^2, x, 5, -(x^(1 + m)/(2*(1 + m))) - 2^(-(7/2) - m/2)*E^(2*a)*x^(1 + m)*((-b)*x^2)^((1/2)*(-1 - m))*Gamma[(1 + m)/2, -2*b*x^2] - (2^(-(7/2) - m/2)*x^(1 + m)*(b*x^2)^((1/2)*(-1 - m))*Gamma[(1 + m)/2, 2*b*x^2])/E^(2*a)}

{x^3*Sinh[a + b*x^2]^2, x, 2, -(x^4/8) + (x^2*Cosh[a + b*x^2]*Sinh[a + b*x^2])/(4*b) - Sinh[a + b*x^2]^2/(8*b^2)}
{x^2*Sinh[a + b*x^2]^2, x, 6, -(x^3/6) + (Sqrt[Pi/2]*Erf[Sqrt[2]*Sqrt[b]*x])/(E^(2*a)*(32*b^(3/2))) - (E^(2*a)*Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[b]*x])/(32*b^(3/2)) + (x*Sinh[2*a + 2*b*x^2])/(8*b)}
{x*Sinh[a + b*x^2]^2, x, 2, -(x^2/4) + (Cosh[a + b*x^2]*Sinh[a + b*x^2])/(4*b)}
{Sinh[a + b*x^2]^2, x, 5, -(x/2) + (Sqrt[Pi/2]*Erf[Sqrt[2]*Sqrt[b]*x])/(E^(2*a)*(8*Sqrt[b])) + (E^(2*a)*Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[b]*x])/(8*Sqrt[b])}
{Sinh[a + b*x^2]^2/x, x, 5, (1/4)*Cosh[2*a]*CoshIntegral[2*b*x^2] - Log[x]/2 + (1/4)*Sinh[2*a]*SinhIntegral[2*b*x^2]}
{Sinh[a + b*x^2]^2/x^2, x, 5, ((-(1/2))*Sqrt[b]*Sqrt[Pi/2]*Erf[Sqrt[2]*Sqrt[b]*x])/E^(2*a) + (1/2)*Sqrt[b]*E^(2*a)*Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[b]*x] - Sinh[a + b*x^2]^2/x}
{Sinh[a + b*x^2]^2/x^3, x, 6, 1/(4*x^2) - Cosh[2*a + 2*b*x^2]/(4*x^2) + (1/2)*b*CoshIntegral[2*b*x^2]*Sinh[2*a] + (1/2)*b*Cosh[2*a]*SinhIntegral[2*b*x^2]}


{x^m*Sinh[a + b*x^2]^3, x, 8, (-(1/16))*3^(-(1/2) - m/2)*E^(3*a)*x^(1 + m)*((-b)*x^2)^((1/2)*(-1 - m))*Gamma[(1 + m)/2, -3*b*x^2] + (3/16)*E^a*x^(1 + m)*((-b)*x^2)^((1/2)*(-1 - m))*Gamma[(1 + m)/2, (-b)*x^2] - ((3/16)*x^(1 + m)*(b*x^2)^((1/2)*(-1 - m))*Gamma[(1 + m)/2, b*x^2])/E^a + ((1/16)*3^(-(1/2) - m/2)*x^(1 + m)*(b*x^2)^((1/2)*(-1 - m))*Gamma[(1 + m)/2, 3*b*x^2])/E^(3*a)}

{x^3*Sinh[a + b*x^2]^3, x, 3, -((x^2*Cosh[a + b*x^2])/(3*b)) + Sinh[a + b*x^2]/(3*b^2) + (x^2*Cosh[a + b*x^2]*Sinh[a + b*x^2]^2)/(6*b) - Sinh[a + b*x^2]^3/(18*b^2)}
{x^2*Sinh[a + b*x^2]^3, x, 10, -((3*x*Cosh[a + b*x^2])/(8*b)) + (x*Cosh[3*a + 3*b*x^2])/(24*b) + (3*Sqrt[Pi]*Erf[Sqrt[b]*x])/(E^a*(32*b^(3/2))) - (Sqrt[Pi/3]*Erf[Sqrt[3]*Sqrt[b]*x])/(E^(3*a)*(96*b^(3/2))) + (3*E^a*Sqrt[Pi]*Erfi[Sqrt[b]*x])/(32*b^(3/2)) - (E^(3*a)*Sqrt[Pi/3]*Erfi[Sqrt[3]*Sqrt[b]*x])/(96*b^(3/2))}
{x*Sinh[a + b*x^2]^3, x, 3, -(Cosh[a + b*x^2]/(2*b)) + Cosh[a + b*x^2]^3/(6*b)}
{Sinh[a + b*x^2]^3, x, 8, (3*Sqrt[Pi]*Erf[Sqrt[b]*x])/(E^a*(16*Sqrt[b])) - (Sqrt[Pi/3]*Erf[Sqrt[3]*Sqrt[b]*x])/(E^(3*a)*(16*Sqrt[b])) - (3*E^a*Sqrt[Pi]*Erfi[Sqrt[b]*x])/(16*Sqrt[b]) + (E^(3*a)*Sqrt[Pi/3]*Erfi[Sqrt[3]*Sqrt[b]*x])/(16*Sqrt[b])}
{Sinh[a + b*x^2]^3/x, x, 8, (-(3/8))*CoshIntegral[b*x^2]*Sinh[a] + (1/8)*CoshIntegral[3*b*x^2]*Sinh[3*a] - (3/8)*Cosh[a]*SinhIntegral[b*x^2] + (1/8)*Cosh[3*a]*SinhIntegral[3*b*x^2]}
{Sinh[a + b*x^2]^3/x^2, x, 9, ((-(3/8))*Sqrt[b]*Sqrt[Pi]*Erf[Sqrt[b]*x])/E^a + ((1/8)*Sqrt[b]*Sqrt[3*Pi]*Erf[Sqrt[3]*Sqrt[b]*x])/E^(3*a) - (3/8)*Sqrt[b]*E^a*Sqrt[Pi]*Erfi[Sqrt[b]*x] + (1/8)*Sqrt[b]*E^(3*a)*Sqrt[3*Pi]*Erfi[Sqrt[3]*Sqrt[b]*x] - Sinh[a + b*x^2]^3/x}
{Sinh[a + b*x^2]^3/x^3, x, 10, (-(3/8))*b*Cosh[a]*CoshIntegral[b*x^2] + (3/8)*b*Cosh[3*a]*CoshIntegral[3*b*x^2] + (3*Sinh[a + b*x^2])/(8*x^2) - Sinh[3*a + 3*b*x^2]/(8*x^2) - (3/8)*b*Sinh[a]*SinhIntegral[b*x^2] + (3/8)*b*Sinh[3*a]*SinhIntegral[3*b*x^2]}


{x*Sinh[a + b*x^2]^7, x, 3, -(Cosh[a + b*x^2]/(2*b)) + Cosh[a + b*x^2]^3/(2*b) - (3*Cosh[a + b*x^2]^5)/(10*b) + Cosh[a + b*x^2]^7/(14*b)}


(* ::Subsubsection:: *)
(*p<0*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Sinh[a+b x^n]*)


(* ::Subsubsection::Closed:: *)
(*n>0*)


{x^3*Sinh[a + b*x^4], x, 1, Cosh[a + b*x^4]/(4*b)}


{Sinh[Sqrt[x]]/Sqrt[x], x, 1, 2*Cosh[Sqrt[x]]}


(* ::Subsubsection::Closed:: *)
(*n<0*)


{Sinh[a + b/x]*x^m, x, 3, (1/2)*E^a*(-(b/x))^(1 + m)*x^(1 + m)*Gamma[-1 - m, -(b/x)] - ((1/2)*(b/x)^(1 + m)*x^(1 + m)*Gamma[-1 - m, b/x])/E^a}

{Sinh[a + b/x]*x^2, x, 7, (1/6)*b*x^2*Cosh[a + b/x] - (1/6)*b^3*Cosh[a]*CoshIntegral[b/x] + (1/6)*b^2*x*Sinh[a + b/x] + (1/3)*x^3*Sinh[a + b/x] - (1/6)*b^3*Sinh[a]*SinhIntegral[b/x]}
{Sinh[a + b/x]*x^1, x, 6, (1/2)*b*x*Cosh[a + b/x] - (1/2)*b^2*CoshIntegral[b/x]*Sinh[a] + (1/2)*x^2*Sinh[a + b/x] - (1/2)*b^2*Cosh[a]*SinhIntegral[b/x]}
{Sinh[a + b/x]*x^0, x, 5, (-b)*Cosh[a]*CoshIntegral[b/x] + x*Sinh[a + b/x] - b*Sinh[a]*SinhIntegral[b/x]}
{Sinh[a + b/x]/x^1, x, 3, (-CoshIntegral[b/x])*Sinh[a] - Cosh[a]*SinhIntegral[b/x]}
{Sinh[a + b/x]/x^2, x, 1, -(Cosh[a + b/x]/b)}
{Sinh[a + b/x]/x^3, x, 2, -(Cosh[a + b/x]/(b*x)) + Sinh[a + b/x]/b^2}
{Sinh[a + b/x]/x^4, x, 3, -((2*Cosh[a + b/x])/b^3) - Cosh[a + b/x]/(b*x^2) + (2*Sinh[a + b/x])/(b^2*x)}
{Sinh[a + b/x]/x^5, x, 4, -(Cosh[a + b/x]/(b*x^3)) - (6*Cosh[a + b/x])/(b^3*x) + (6*Sinh[a + b/x])/b^4 + (3*Sinh[a + b/x])/(b^2*x^2)}


{Sinh[a + b/x^2]*x^m, x, 3, (1/4)*E^a*(-(b/x^2))^((1 + m)/2)*x^(1 + m)*Gamma[(1/2)*(-1 - m), -(b/x^2)] - ((1/4)*(b/x^2)^((1 + m)/2)*x^(1 + m)*Gamma[(1/2)*(-1 - m), b/x^2])/E^a}

{Sinh[a + b/x^2]*x^4, x, 7, (2/15)*b*x^3*Cosh[a + b/x^2] - ((2/15)*b^(5/2)*Sqrt[Pi]*Erf[Sqrt[b]/x])/E^a - (2/15)*b^(5/2)*E^a*Sqrt[Pi]*Erfi[Sqrt[b]/x] + (4/15)*b^2*x*Sinh[a + b/x^2] + (1/5)*x^5*Sinh[a + b/x^2]}
{Sinh[a + b/x^2]*x^3, x, 5, (1/4)*b*x^2*Cosh[a + b/x^2] - (1/4)*b^2*CoshIntegral[b/x^2]*Sinh[a] + (1/4)*x^4*Sinh[a + b/x^2] - (1/4)*b^2*Cosh[a]*SinhIntegral[b/x^2]}
{Sinh[a + b/x^2]*x^2, x, 6, (2/3)*b*x*Cosh[a + b/x^2] + ((1/3)*b^(3/2)*Sqrt[Pi]*Erf[Sqrt[b]/x])/E^a - (1/3)*b^(3/2)*E^a*Sqrt[Pi]*Erfi[Sqrt[b]/x] + (1/3)*x^3*Sinh[a + b/x^2]}
{Sinh[a + b/x^2]*x^1, x, 4, (-(1/2))*b*Cosh[a]*CoshIntegral[b/x^2] + (1/2)*x^2*Sinh[a + b/x^2] - (1/2)*b*Sinh[a]*SinhIntegral[b/x^2]}
{Sinh[a + b/x^2]*x^0, x, 5, ((-(1/2))*Sqrt[b]*Sqrt[Pi]*Erf[Sqrt[b]/x])/E^a - (1/2)*Sqrt[b]*E^a*Sqrt[Pi]*Erfi[Sqrt[b]/x] + x*Sinh[a + b/x^2]}
{Sinh[a + b/x^2]/x^1, x, 3, (-(1/2))*CoshIntegral[b/x^2]*Sinh[a] - (1/2)*Cosh[a]*SinhIntegral[b/x^2]}
{Sinh[a + b/x^2]/x^2, x, 5, (Sqrt[Pi]*Erf[Sqrt[b]/x])/(E^a*(4*Sqrt[b])) - (E^a*Sqrt[Pi]*Erfi[Sqrt[b]/x])/(4*Sqrt[b])}
{Sinh[a + b/x^2]/x^3, x, 1, -(Cosh[a + b/x^2]/(2*b))}
{Sinh[a + b/x^2]/x^4, x, 6, -(Cosh[a + b/x^2]/(2*b*x)) + (Sqrt[Pi]*Erf[Sqrt[b]/x])/(E^a*(8*b^(3/2))) + (E^a*Sqrt[Pi]*Erfi[Sqrt[b]/x])/(8*b^(3/2))}
{Sinh[a + b/x^2]/x^5, x, 2, -(Cosh[a + b/x^2]/(2*b*x^2)) + Sinh[a + b/x^2]/(2*b^2)}
{Sinh[a + b/x^2]/x^6, x, 7, -(Cosh[a + b/x^2]/(2*b*x^3)) + (3*Sqrt[Pi]*Erf[Sqrt[b]/x])/(E^a*(16*b^(5/2))) - (3*E^a*Sqrt[Pi]*Erfi[Sqrt[b]/x])/(16*b^(5/2)) + (3*Sinh[a + b/x^2])/(4*b^2*x)}
{Sinh[a + b/x^2]/x^7, x, 3, -(Cosh[a + b/x^2]/b^3) - Cosh[a + b/x^2]/(2*b*x^4) + Sinh[a + b/x^2]/(b^2*x^2)}


(* ::Subsubsection::Closed:: *)
(*n symbolic*)


{x^m*Sinh[a + b*x^n], x, 3, -((E^a*x^(1 + m)*Gamma[(1 + m)/n, (-b)*x^n])/(((-b)*x^n)^((1 + m)/n)*(2*n))) + (x^(1 + m)*Gamma[(1 + m)/n, b*x^n])/(E^a*(b*x^n)^((1 + m)/n)*(2*n))}

{x^2*Sinh[a + b*x^n], x, 3, -((E^a*x^3*Gamma[3/n, (-b)*x^n])/(((-b)*x^n)^(3/n)*(2*n))) + (x^3*Gamma[3/n, b*x^n])/(E^a*(b*x^n)^(3/n)*(2*n))}
{x^1*Sinh[a + b*x^n], x, 3, -((E^a*x^2*Gamma[2/n, (-b)*x^n])/(((-b)*x^n)^(2/n)*(2*n))) + (x^2*Gamma[2/n, b*x^n])/(E^a*(b*x^n)^(2/n)*(2*n))}
{x^0*Sinh[a + b*x^n], x, 3, -((E^a*x*Gamma[1/n, (-b)*x^n])/(((-b)*x^n)^n^(-1)*(2*n))) + (x*Gamma[1/n, b*x^n])/(E^a*(b*x^n)^n^(-1)*(2*n))}
{Sinh[a + b*x^n]/x^1, x, 3, (CoshIntegral[b*x^n]*Sinh[a])/n + (Cosh[a]*SinhIntegral[b*x^n])/n}
{Sinh[a + b*x^n]/x^2, x, 3, -((E^a*((-b)*x^n)^(1/n)*Gamma[-(1/n), (-b)*x^n])/(2*n*x)) + ((b*x^n)^(1/n)*Gamma[-(1/n), b*x^n])/(E^a*(2*n*x))}
{Sinh[a + b*x^n]/x^3, x, 3, -((E^a*((-b)*x^n)^(2/n)*Gamma[-(2/n), (-b)*x^n])/(2*n*x^2)) + ((b*x^n)^(2/n)*Gamma[-(2/n), b*x^n])/(E^a*(2*n*x^2))}


{x^(n/2 - 1)*Sinh[a + b*x^n], x, 5, -((Sqrt[Pi]*Erf[Sqrt[b]*x^(n/2)])/(E^a*(2*Sqrt[b]*n))) + (E^a*Sqrt[Pi]*Erfi[Sqrt[b]*x^(n/2)])/(2*Sqrt[b]*n)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Sinh[a+b x^n]^p*)


{x^m*Sinh[a + b*x^n]^2, x, 5, -(x^(1 + m)/(2*(1 + m))) - (E^(2*a)*x^(1 + m)*Gamma[(1 + m)/n, -2*b*x^n])/(2^((1 + m + 2*n)/n)*((-b)*x^n)^((1 + m)/n)*n) - (x^(1 + m)*Gamma[(1 + m)/n, 2*b*x^n])/(2^((1 + m + 2*n)/n)*E^(2*a)*(b*x^n)^((1 + m)/n)*n)}
{Sinh[a + b*x^n]^2, x, 5, -(x/2) - (2^(-2 - 1/n)*E^(2*a)*x*Gamma[1/n, -2*b*x^n])/(((-b)*x^n)^n^(-1)*n) - (2^(-2 - 1/n)*x*Gamma[1/n, 2*b*x^n])/(E^(2*a)*(b*x^n)^n^(-1)*n)}


{x^m*Sinh[a + b*x^n]^3, x, 8, -((E^(3*a)*x^(1 + m)*Gamma[(1 + m)/n, -3*b*x^n])/(3^((1 + m)/n)*((-b)*x^n)^((1 + m)/n)*(8*n))) + (3*E^a*x^(1 + m)*Gamma[(1 + m)/n, (-b)*x^n])/(((-b)*x^n)^((1 + m)/n)*(8*n)) - (3*x^(1 + m)*Gamma[(1 + m)/n, b*x^n])/(E^a*(b*x^n)^((1 + m)/n)*(8*n)) + (x^(1 + m)*Gamma[(1 + m)/n, 3*b*x^n])/(3^((1 + m)/n)*E^(3*a)*(b*x^n)^((1 + m)/n)*(8*n))}
{Sinh[a + b*x^n]^3, x, 8, -((E^(3*a)*x*Gamma[1/n, -3*b*x^n])/(3^n^(-1)*((-b)*x^n)^n^(-1)*(8*n))) + (3*E^a*x*Gamma[1/n, (-b)*x^n])/(((-b)*x^n)^n^(-1)*(8*n)) - (3*x*Gamma[1/n, b*x^n])/(E^a*(b*x^n)^n^(-1)*(8*n)) + (x*Gamma[1/n, 3*b*x^n])/(3^n^(-1)*E^(3*a)*(b*x^n)^n^(-1)*(8*n))}


{Sinh[a + b*x^n]/x^(n + 1), x, 4, (b*Cosh[a]*CoshIntegral[b*x^n])/n - Sinh[a + b*x^n]/(x^n*n) + (b*Sinh[a]*SinhIntegral[b*x^n])/n}
{Sinh[a + b*x^n]^2/x^(n + 1), x, 6, 1/(x^n*(2*n)) - Cosh[2*a + 2*b*x^n]/(x^n*(2*n)) + (b*CoshIntegral[2*b*x^n]*Sinh[2*a])/n + (b*Cosh[2*a]*SinhIntegral[2*b*x^n])/n}
{Sinh[a + b*x^n]^3/x^(n + 1), x, 10, -((3*b*Cosh[a]*CoshIntegral[b*x^n])/(4*n)) + (3*b*Cosh[3*a]*CoshIntegral[3*b*x^n])/(4*n) + (3*Sinh[a + b*x^n])/(x^n*(4*n)) - Sinh[3*a + 3*b*x^n]/(x^n*(4*n)) - (3*b*Sinh[a]*SinhIntegral[b*x^n])/(4*n) + (3*b*Sinh[3*a]*SinhIntegral[3*b*x^n])/(4*n)}


{Sinh[a + b*x^n]/x, x, 3, (CoshIntegral[b*x^n]*Sinh[a])/n + (Cosh[a]*SinhIntegral[b*x^n])/n}
{Sinh[a + b*x^n]^2/x, x, 5, (Cosh[2*a]*CoshIntegral[2*b*x^n])/(2*n) - Log[x]/2 + (Sinh[2*a]*SinhIntegral[2*b*x^n])/(2*n)}
{Sinh[a + b*x^n]^3/x, x, 8, -((3*CoshIntegral[b*x^n]*Sinh[a])/(4*n)) + (CoshIntegral[3*b*x^n]*Sinh[3*a])/(4*n) - (3*Cosh[a]*SinhIntegral[b*x^n])/(4*n) + (Cosh[3*a]*SinhIntegral[3*b*x^n])/(4*n)}


(* ::Section::Closed:: *)
(*Integrands of the form x^m Cosh[c+d x] (a+b Sinh[c+d x]^n)^p*)


{(e + f*x)^1*Cosh[c + d*x]/(a + b*Sinh[c + d*x]), x, 0, (d*(2*e*Log[2*a*E^(c + d*x) + b*(-1 + E^(2*(c + d*x)))] + x*(-2*d*e - d*f*x + 2*f*Log[1 + (b*E^(2*c + d*x))/(a*E^c - Sqrt[(a^2 + b^2)*E^(2*c)])] + 2*f*Log[1 + (b*E^(2*c + d*x))/(a*E^c + Sqrt[(a^2 + b^2)*E^(2*c)])])) + 2*f*PolyLog[2, -((b*E^(2*c + d*x))/(a*E^c - Sqrt[(a^2 + b^2)*E^(2*c)]))] + 2*f*PolyLog[2, -((b*E^(2*c + d*x))/(a*E^c + Sqrt[(a^2 + b^2)*E^(2*c)]))])/(2*b*d^2)}
{(e + f*x)^2*Cosh[c + d*x]/(a + b*Sinh[c + d*x]), x, 0, (1/(3*b*d^3))*(-3*d^3*e^2*x - 3*d^3*e*f*x^2 - d^3*f^2*x^3 + 3*d^2*e^2*Log[2*a*E^(c + d*x) + b*(-1 + E^(2*(c + d*x)))] + 6*d^2*e*f*x*Log[1 + (b*E^(2*c + d*x))/(a*E^c - Sqrt[(a^2 + b^2)*E^(2*c)])] + 3*d^2*f^2*x^2*Log[1 + (b*E^(2*c + d*x))/(a*E^c - Sqrt[(a^2 + b^2)*E^(2*c)])] + 6*d^2*e*f*x*Log[1 + (b*E^(2*c + d*x))/(a*E^c + Sqrt[(a^2 + b^2)*E^(2*c)])] + 3*d^2*f^2*x^2*Log[1 + (b*E^(2*c + d*x))/(a*E^c + Sqrt[(a^2 + b^2)*E^(2*c)])] + 6*d*f*(e + f*x)*PolyLog[2, -((b*E^(2*c + d*x))/(a*E^c - Sqrt[(a^2 + b^2)*E^(2*c)]))] + 6*d*f*(e + f*x)*PolyLog[2, -((b*E^(2*c + d*x))/(a*E^c + Sqrt[(a^2 + b^2)*E^(2*c)]))] - 6*f^2*PolyLog[3, -((b*E^(2*c + d*x))/(a*E^c - Sqrt[(a^2 + b^2)*E^(2*c)]))] - 6*f^2*PolyLog[3, -((b*E^(2*c + d*x))/(a*E^c + Sqrt[(a^2 + b^2)*E^(2*c)]))])}
{(e + f*x)^3*Cosh[c + d*x]/(a + b*Sinh[c + d*x]), x, 0, (1/(4*b*d^4))*(-4*d^4*e^3*x - 6*d^4*e^2*f*x^2 - 4*d^4*e*f^2*x^3 - d^4*f^3*x^4 + 4*d^3*e^3*Log[2*a*E^(c + d*x) + b*(-1 + E^(2*(c + d*x)))] + 12*d^3*e^2*f*x*Log[1 + (b*E^(2*c + d*x))/(a*E^c - Sqrt[(a^2 + b^2)*E^(2*c)])] + 12*d^3*e*f^2*x^2*Log[1 + (b*E^(2*c + d*x))/(a*E^c - Sqrt[(a^2 + b^2)*E^(2*c)])] + 4*d^3*f^3*x^3*Log[1 + (b*E^(2*c + d*x))/(a*E^c - Sqrt[(a^2 + b^2)*E^(2*c)])] + 12*d^3*e^2*f*x*Log[1 + (b*E^(2*c + d*x))/(a*E^c + Sqrt[(a^2 + b^2)*E^(2*c)])] + 12*d^3*e*f^2*x^2*Log[1 + (b*E^(2*c + d*x))/(a*E^c + Sqrt[(a^2 + b^2)*E^(2*c)])] + 4*d^3*f^3*x^3*Log[1 + (b*E^(2*c + d*x))/(a*E^c + Sqrt[(a^2 + b^2)*E^(2*c)])] + 12*d^2*f*(e + f*x)^2*PolyLog[2, -((b*E^(2*c + d*x))/(a*E^c - Sqrt[(a^2 + b^2)*E^(2*c)]))] + 12*d^2*f*(e + f*x)^2*PolyLog[2, -((b*E^(2*c + d*x))/(a*E^c + Sqrt[(a^2 + b^2)*E^(2*c)]))] - 24*d*e*f^2*PolyLog[3, -((b*E^(2*c + d*x))/(a*E^c - Sqrt[(a^2 + b^2)*E^(2*c)]))] - 24*d*f^3*x*PolyLog[3, -((b*E^(2*c + d*x))/(a*E^c - Sqrt[(a^2 + b^2)*E^(2*c)]))] - 24*d*e*f^2*PolyLog[3, -((b*E^(2*c + d*x))/(a*E^c + Sqrt[(a^2 + b^2)*E^(2*c)]))] - 24*d*f^3*x*PolyLog[3, -((b*E^(2*c + d*x))/(a*E^c + Sqrt[(a^2 + b^2)*E^(2*c)]))] + 24*f^3*PolyLog[4, -((b*E^(2*c + d*x))/(a*E^c - Sqrt[(a^2 + b^2)*E^(2*c)]))] + 24*f^3*PolyLog[4, -((b*E^(2*c + d*x))/(a*E^c + Sqrt[(a^2 + b^2)*E^(2*c)]))])}


{(e + f*x)^1*Cosh[c + d*x]/(a + b*Sinh[c + d*x])^2, x, 2, -((2*f*ArcTanh[(b - a*Tanh[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]])/(b*Sqrt[a^2 + b^2]*d^2)) - (e + f*x)/(b*d*(a + b*Sinh[c + d*x]))}
{(e + f*x)^2*Cosh[c + d*x]/(a + b*Sinh[c + d*x])^2, x, 12, -((4*e*f*ArcTanh[(b - a*Tanh[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]])/(b*Sqrt[a^2 + b^2]*d^2)) + (2*f^2*x*Log[1 + (b*E^(c + d*x))/(a - Sqrt[a^2 + b^2])])/(b*Sqrt[a^2 + b^2]*d^2) - (2*f^2*x*Log[1 + (b*E^(c + d*x))/(a + Sqrt[a^2 + b^2])])/(b*Sqrt[a^2 + b^2]*d^2) + (2*f^2*PolyLog[2, -((b*E^(c + d*x))/(a - Sqrt[a^2 + b^2]))])/(b*Sqrt[a^2 + b^2]*d^3) - (2*f^2*PolyLog[2, -((b*E^(c + d*x))/(a + Sqrt[a^2 + b^2]))])/(b*Sqrt[a^2 + b^2]*d^3) - (e + f*x)^2/(b*d*(a + b*Sinh[c + d*x]))}
{(e + f*x)^3*Cosh[c + d*x]/(a + b*Sinh[c + d*x])^2, x, 22, -((6*e^2*f*ArcTanh[(b - a*Tanh[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]])/(b*Sqrt[a^2 + b^2]*d^2)) + (6*e*f^2*x*Log[1 + (b*E^(c + d*x))/(a - Sqrt[a^2 + b^2])])/(b*Sqrt[a^2 + b^2]*d^2) + (3*f^3*x^2*Log[1 + (b*E^(c + d*x))/(a - Sqrt[a^2 + b^2])])/(b*Sqrt[a^2 + b^2]*d^2) - (6*e*f^2*x*Log[1 + (b*E^(c + d*x))/(a + Sqrt[a^2 + b^2])])/(b*Sqrt[a^2 + b^2]*d^2) - (3*f^3*x^2*Log[1 + (b*E^(c + d*x))/(a + Sqrt[a^2 + b^2])])/(b*Sqrt[a^2 + b^2]*d^2) + (6*e*f^2*PolyLog[2, -((b*E^(c + d*x))/(a - Sqrt[a^2 + b^2]))])/(b*Sqrt[a^2 + b^2]*d^3) + (6*f^3*x*PolyLog[2, -((b*E^(c + d*x))/(a - Sqrt[a^2 + b^2]))])/(b*Sqrt[a^2 + b^2]*d^3) - (6*e*f^2*PolyLog[2, -((b*E^(c + d*x))/(a + Sqrt[a^2 + b^2]))])/(b*Sqrt[a^2 + b^2]*d^3) - (6*f^3*x*PolyLog[2, -((b*E^(c + d*x))/(a + Sqrt[a^2 + b^2]))])/(b*Sqrt[a^2 + b^2]*d^3) - (6*f^3*PolyLog[3, -((b*E^(c + d*x))/(a - Sqrt[a^2 + b^2]))])/(b*Sqrt[a^2 + b^2]*d^4) + (6*f^3*PolyLog[3, -((b*E^(c + d*x))/(a + Sqrt[a^2 + b^2]))])/(b*Sqrt[a^2 + b^2]*d^4) - (e + f*x)^3/(b*d*(a + b*Sinh[c + d*x]))}


{(e + f*x)^1*Cosh[c + d*x]/(a + b*Sinh[c + d*x])^3, x, 4, -((a*f*ArcTanh[(b - a*Tanh[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]])/(b*(a^2 + b^2)^(3/2)*d^2)) - (e + f*x)/(2*b*d*(a + b*Sinh[c + d*x])^2) - (f*Cosh[c + d*x])/(2*(a^2 + b^2)*d^2*(a + b*Sinh[c + d*x]))}
{(e + f*x)^2*Cosh[c + d*x]/(a + b*Sinh[c + d*x])^3, x, 18, -((2*a*e*f*ArcTanh[(b - a*Tanh[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]])/(b*(a^2 + b^2)^(3/2)*d^2)) + (a*f^2*x*Log[1 + (b*E^(c + d*x))/(a - Sqrt[a^2 + b^2])])/(b*(a^2 + b^2)^(3/2)*d^2) - (a*f^2*x*Log[1 + (b*E^(c + d*x))/(a + Sqrt[a^2 + b^2])])/(b*(a^2 + b^2)^(3/2)*d^2) + (f^2*Log[a + b*Sinh[c + d*x]])/(b*(a^2 + b^2)*d^3) + (a*f^2*PolyLog[2, -((b*E^(c + d*x))/(a - Sqrt[a^2 + b^2]))])/(b*(a^2 + b^2)^(3/2)*d^3) - (a*f^2*PolyLog[2, -((b*E^(c + d*x))/(a + Sqrt[a^2 + b^2]))])/(b*(a^2 + b^2)^(3/2)*d^3) - (e + f*x)^2/(2*b*d*(a + b*Sinh[c + d*x])^2) - (e*f*Cosh[c + d*x])/((a^2 + b^2)*d^2*(a + b*Sinh[c + d*x])) - (f^2*x*Cosh[c + d*x])/((a^2 + b^2)*d^2*(a + b*Sinh[c + d*x]))}
(* {(e + f*x)^3*Cosh[c + d*x]/(a + b*Sinh[c + d*x])^3, x, 97, (3*a*(1 - a/Sqrt[a^2 + b^2])*e*f^2*x^2)/(b*(a^2 + b^2)*(2*a - 2*Sqrt[a^2 + b^2])*d) + (3*a*(1 + a/Sqrt[a^2 + b^2])*e*f^2*x^2)/(b*(a^2 + b^2)*(2*a + 2*Sqrt[a^2 + b^2])*d) - (24*b*f^3*x^2)/((4*a^2 + 4*b^2)*(-2*a + Sqrt[4*a^2 + 4*b^2])^2*d^2) + (24*a*f^3*x^2)/(b*(4*a^2 + 4*b^2)*(-2*a + Sqrt[4*a^2 + 4*b^2])*d^2) - (24*b*f^3*x^2)/((4*a^2 + 4*b^2)*(2*a + Sqrt[4*a^2 + 4*b^2])^2*d^2) + (24*a*(-2*a - Sqrt[4*a^2 + 4*b^2])*f^3*x^2)/(b*(4*a^2 + 4*b^2)*(2*a + Sqrt[4*a^2 + 4*b^2])^2*d^2) + (2*f^3*x^3)/(b*Sqrt[a^2 + b^2]*(2*a - 2*Sqrt[a^2 + b^2])*d) - (2*f^3*x^3)/(b*Sqrt[a^2 + b^2]*(2*a + 2*Sqrt[a^2 + b^2])*d) - (16*a^2*f^3*x^3)/(b*(4*a^2 + 4*b^2)^(3/2)*(2*a - Sqrt[4*a^2 + 4*b^2])*d) - (8*b*f^3*x^3)/((4*a^2 + 4*b^2)^(3/2)*(2*a - Sqrt[4*a^2 + 4*b^2])*d) - (16*b*f^3*x^3)/((4*a^2 + 4*b^2)*(-2*a + Sqrt[4*a^2 + 4*b^2])^2*d) + (16*a*f^3*x^3)/(b*(4*a^2 + 4*b^2)*(-2*a + Sqrt[4*a^2 + 4*b^2])*d) - (16*b*f^3*x^3)/((4*a^2 + 4*b^2)*(2*a + Sqrt[4*a^2 + 4*b^2])^2*d) + (16*a*(-2*a - Sqrt[4*a^2 + 4*b^2])*f^3*x^3)/(b*(4*a^2 + 4*b^2)*(2*a + Sqrt[4*a^2 + 4*b^2])^2*d) + (16*a^2*f^3*x^3)/(b*(4*a^2 + 4*b^2)^(3/2)*(2*a + Sqrt[4*a^2 + 4*b^2])*d) + (8*b*f^3*x^3)/((4*a^2 + 4*b^2)^(3/2)*(2*a + Sqrt[4*a^2 + 4*b^2])*d) - (3*a*e^2*f*ArcTanh[(b - a*Tanh[(1/2)*(c + d*x)])/Sqrt[a^2 + b^2]])/(b*(a^2 + b^2)^(3/2)*d^2) + (24*b*f^3*x^2*Log[-2*a + Sqrt[4*a^2 + 4*b^2] - 2*b*E^(c + d*x)])/((4*a^2 + 4*b^2)*(-2*a + Sqrt[4*a^2 + 4*b^2])^2*d^2) - (24*a*f^3*x^2*Log[-2*a + Sqrt[4*a^2 + 4*b^2] - 2*b*E^(c + d*x)])/(b*(4*a^2 + 4*b^2)*(-2*a + Sqrt[4*a^2 + 4*b^2])*d^2) + (24*b*f^3*x^2*(1/((-2*a + Sqrt[4*a^2 + 4*b^2])*d*(-2*a + Sqrt[4*a^2 + 4*b^2] - 2*b*E^(c + d*x))) + x/(-2*a + Sqrt[4*a^2 + 4*b^2])^2 - Log[-2*a + Sqrt[4*a^2 + 4*b^2] - 2*b*E^(c + d*x)]/((-2*a + Sqrt[4*a^2 + 4*b^2])^2*d)))/((4*a^2 + 4*b^2)*d) - (1/(b*(4*a^2 + 4*b^2)*d))*(24*a*(-2*a + Sqrt[4*a^2 + 4*b^2])*f^3*x^2*(1/((-2*a + Sqrt[4*a^2 + 4*b^2])*d*(-2*a + Sqrt[4*a^2 + 4*b^2] - 2*b*E^(c + d*x))) + x/(-2*a + Sqrt[4*a^2 + 4*b^2])^2 - Log[-2*a + Sqrt[4*a^2 + 4*b^2] - 2*b*E^(c + d*x)]/((-2*a + Sqrt[4*a^2 + 4*b^2])^2*d))) + (24*b*f^3*x^2*Log[2*a + Sqrt[4*a^2 + 4*b^2] + 2*b*E^(c + d*x)])/((4*a^2 + 4*b^2)*(2*a + Sqrt[4*a^2 + 4*b^2])^2*d^2) - (24*a*(-2*a - Sqrt[4*a^2 + 4*b^2])*f^3*x^2*Log[2*a + Sqrt[4*a^2 + 4*b^2] + 2*b*E^(c + d*x)])/(b*(4*a^2 + 4*b^2)*(2*a + Sqrt[4*a^2 + 4*b^2])^2*d^2) + (24*b*f^3*x^2*(1/((2*a + Sqrt[4*a^2 + 4*b^2])*d*(2*a + Sqrt[4*a^2 + 4*b^2] + 2*b*E^(c + d*x))) + x/(2*a + Sqrt[4*a^2 + 4*b^2])^2 - Log[2*a + Sqrt[4*a^2 + 4*b^2] + 2*b*E^(c + d*x)]/((2*a + Sqrt[4*a^2 + 4*b^2])^2*d)))/((4*a^2 + 4*b^2)*d) - (1/(b*(4*a^2 + 4*b^2)*d))*(24*a*(-2*a - Sqrt[4*a^2 + 4*b^2])*f^3*x^2*(1/((2*a + Sqrt[4*a^2 + 4*b^2])*d*(2*a + Sqrt[4*a^2 + 4*b^2] + 2*b*E^(c + d*x))) + x/(2*a + Sqrt[4*a^2 + 4*b^2])^2 - Log[2*a + Sqrt[4*a^2 + 4*b^2] + 2*b*E^(c + d*x)]/((2*a + Sqrt[4*a^2 + 4*b^2])^2*d))) - (6*a*(1 - a/Sqrt[a^2 + b^2])*e*f^2*x*Log[1 + (2*b*E^(c + d*x))/(2*a - 2*Sqrt[a^2 + b^2])])/(b*(a^2 + b^2)*(2*a - 2*Sqrt[a^2 + b^2])*d^2) - (6*f^3*x^2*Log[1 + (2*b*E^(c + d*x))/(2*a - 2*Sqrt[a^2 + b^2])])/(b*Sqrt[a^2 + b^2]*(2*a - 2*Sqrt[a^2 + b^2])*d^2) - (6*a*(1 + a/Sqrt[a^2 + b^2])*e*f^2*x*Log[1 + (2*b*E^(c + d*x))/(2*a + 2*Sqrt[a^2 + b^2])])/(b*(a^2 + b^2)*(2*a + 2*Sqrt[a^2 + b^2])*d^2) + (6*f^3*x^2*Log[1 + (2*b*E^(c + d*x))/(2*a + 2*Sqrt[a^2 + b^2])])/(b*Sqrt[a^2 + b^2]*(2*a + 2*Sqrt[a^2 + b^2])*d^2) + (48*a^2*f^3*x^2*Log[1 + (2*b*E^(c + d*x))/(2*a - Sqrt[4*a^2 + 4*b^2])])/(b*(4*a^2 + 4*b^2)^(3/2)*(2*a - Sqrt[4*a^2 + 4*b^2])*d^2) + (24*b*f^3*x^2*Log[1 + (2*b*E^(c + d*x))/(2*a - Sqrt[4*a^2 + 4*b^2])])/((4*a^2 + 4*b^2)^(3/2)*(2*a - Sqrt[4*a^2 + 4*b^2])*d^2) + (48*b*f^3*x*Log[1 - (2*b*E^(c + d*x))/(-2*a + Sqrt[4*a^2 + 4*b^2])])/((4*a^2 + 4*b^2)*(-2*a + Sqrt[4*a^2 + 4*b^2])^2*d^3) - (48*a*f^3*x*Log[1 - (2*b*E^(c + d*x))/(-2*a + Sqrt[4*a^2 + 4*b^2])])/(b*(4*a^2 + 4*b^2)*(-2*a + Sqrt[4*a^2 + 4*b^2])*d^3) - (24*b*f^3*x^2*Log[1 - (2*b*E^(c + d*x))/(-2*a + Sqrt[4*a^2 + 4*b^2])])/((4*a^2 + 4*b^2)*(-2*a + Sqrt[4*a^2 + 4*b^2])^2*d^2) + (24*a*f^3*x^2*Log[1 - (2*b*E^(c + d*x))/(-2*a + Sqrt[4*a^2 + 4*b^2])])/(b*(4*a^2 + 4*b^2)*(-2*a + Sqrt[4*a^2 + 4*b^2])*d^2) + (48*b*f^3*x*Log[1 + (2*b*E^(c + d*x))/(2*a + Sqrt[4*a^2 + 4*b^2])])/((4*a^2 + 4*b^2)*(2*a + Sqrt[4*a^2 + 4*b^2])^2*d^3) - (48*a*(-2*a - Sqrt[4*a^2 + 4*b^2])*f^3*x*Log[1 + (2*b*E^(c + d*x))/(2*a + Sqrt[4*a^2 + 4*b^2])])/(b*(4*a^2 + 4*b^2)*(2*a + Sqrt[4*a^2 + 4*b^2])^2*d^3) - (24*b*f^3*x^2*Log[1 + (2*b*E^(c + d*x))/(2*a + Sqrt[4*a^2 + 4*b^2])])/((4*a^2 + 4*b^2)*(2*a + Sqrt[4*a^2 + 4*b^2])^2*d^2) + (24*a*(-2*a - Sqrt[4*a^2 + 4*b^2])*f^3*x^2*Log[1 + (2*b*E^(c + d*x))/(2*a + Sqrt[4*a^2 + 4*b^2])])/(b*(4*a^2 + 4*b^2)*(2*a + Sqrt[4*a^2 + 4*b^2])^2*d^2) - (48*a^2*f^3*x^2*Log[1 + (2*b*E^(c + d*x))/(2*a + Sqrt[4*a^2 + 4*b^2])])/(b*(4*a^2 + 4*b^2)^(3/2)*(2*a + Sqrt[4*a^2 + 4*b^2])*d^2) - (24*b*f^3*x^2*Log[1 + (2*b*E^(c + d*x))/(2*a + Sqrt[4*a^2 + 4*b^2])])/((4*a^2 + 4*b^2)^(3/2)*(2*a + Sqrt[4*a^2 + 4*b^2])*d^2) + (3*e*f^2*Log[a + b*Sinh[c + d*x]])/(b*(a^2 + b^2)*d^3) - (6*a*(1 - a/Sqrt[a^2 + b^2])*e*f^2*PolyLog[2, -((2*b*E^(c + d*x))/(2*a - 2*Sqrt[a^2 + b^2]))])/(b*(a^2 + b^2)*(2*a - 2*Sqrt[a^2 + b^2])*d^3) - (12*f^3*x*PolyLog[2, -((2*b*E^(c + d*x))/(2*a - 2*Sqrt[a^2 + b^2]))])/(b*Sqrt[a^2 + b^2]*(2*a - 2*Sqrt[a^2 + b^2])*d^3) - (6*a*(1 + a/Sqrt[a^2 + b^2])*e*f^2*PolyLog[2, -((2*b*E^(c + d*x))/(2*a + 2*Sqrt[a^2 + b^2]))])/(b*(a^2 + b^2)*(2*a + 2*Sqrt[a^2 + b^2])*d^3) + (12*f^3*x*PolyLog[2, -((2*b*E^(c + d*x))/(2*a + 2*Sqrt[a^2 + b^2]))])/(b*Sqrt[a^2 + b^2]*(2*a + 2*Sqrt[a^2 + b^2])*d^3) + (96*a^2*f^3*x*PolyLog[2, -((2*b*E^(c + d*x))/(2*a - Sqrt[4*a^2 + 4*b^2]))])/(b*(4*a^2 + 4*b^2)^(3/2)*(2*a - Sqrt[4*a^2 + 4*b^2])*d^3) + (48*b*f^3*x*PolyLog[2, -((2*b*E^(c + d*x))/(2*a - Sqrt[4*a^2 + 4*b^2]))])/((4*a^2 + 4*b^2)^(3/2)*(2*a - Sqrt[4*a^2 + 4*b^2])*d^3) + (48*b*f^3*PolyLog[2, (2*b*E^(c + d*x))/(-2*a + Sqrt[4*a^2 + 4*b^2])])/((4*a^2 + 4*b^2)*(-2*a + Sqrt[4*a^2 + 4*b^2])^2*d^4) - (48*a*f^3*PolyLog[2, (2*b*E^(c + d*x))/(-2*a + Sqrt[4*a^2 + 4*b^2])])/(b*(4*a^2 + 4*b^2)*(-2*a + Sqrt[4*a^2 + 4*b^2])*d^4) - (48*b*f^3*x*PolyLog[2, (2*b*E^(c + d*x))/(-2*a + Sqrt[4*a^2 + 4*b^2])])/((4*a^2 + 4*b^2)*(-2*a + Sqrt[4*a^2 + 4*b^2])^2*d^3) + (48*a*f^3*x*PolyLog[2, (2*b*E^(c + d*x))/(-2*a + Sqrt[4*a^2 + 4*b^2])])/(b*(4*a^2 + 4*b^2)*(-2*a + Sqrt[4*a^2 + 4*b^2])*d^3) + (48*b*f^3*PolyLog[2, -((2*b*E^(c + d*x))/(2*a + Sqrt[4*a^2 + 4*b^2]))])/((4*a^2 + 4*b^2)*(2*a + Sqrt[4*a^2 + 4*b^2])^2*d^4) - (48*a*(-2*a - Sqrt[4*a^2 + 4*b^2])*f^3*PolyLog[2, -((2*b*E^(c + d*x))/(2*a + Sqrt[4*a^2 + 4*b^2]))])/(b*(4*a^2 + 4*b^2)*(2*a + Sqrt[4*a^2 + 4*b^2])^2*d^4) - (48*b*f^3*x*PolyLog[2, -((2*b*E^(c + d*x))/(2*a + Sqrt[4*a^2 + 4*b^2]))])/((4*a^2 + 4*b^2)*(2*a + Sqrt[4*a^2 + 4*b^2])^2*d^3) + (48*a*(-2*a - Sqrt[4*a^2 + 4*b^2])*f^3*x*PolyLog[2, -((2*b*E^(c + d*x))/(2*a + Sqrt[4*a^2 + 4*b^2]))])/(b*(4*a^2 + 4*b^2)*(2*a + Sqrt[4*a^2 + 4*b^2])^2*d^3) - (96*a^2*f^3*x*PolyLog[2, -((2*b*E^(c + d*x))/(2*a + Sqrt[4*a^2 + 4*b^2]))])/(b*(4*a^2 + 4*b^2)^(3/2)*(2*a + Sqrt[4*a^2 + 4*b^2])*d^3) - (48*b*f^3*x*PolyLog[2, -((2*b*E^(c + d*x))/(2*a + Sqrt[4*a^2 + 4*b^2]))])/((4*a^2 + 4*b^2)^(3/2)*(2*a + Sqrt[4*a^2 + 4*b^2])*d^3) + (12*f^3*PolyLog[3, -((2*b*E^(c + d*x))/(2*a - 2*Sqrt[a^2 + b^2]))])/(b*Sqrt[a^2 + b^2]*(2*a - 2*Sqrt[a^2 + b^2])*d^4) - (12*f^3*PolyLog[3, -((2*b*E^(c + d*x))/(2*a + 2*Sqrt[a^2 + b^2]))])/(b*Sqrt[a^2 + b^2]*(2*a + 2*Sqrt[a^2 + b^2])*d^4) - (96*a^2*f^3*PolyLog[3, -((2*b*E^(c + d*x))/(2*a - Sqrt[4*a^2 + 4*b^2]))])/(b*(4*a^2 + 4*b^2)^(3/2)*(2*a - Sqrt[4*a^2 + 4*b^2])*d^4) - (48*b*f^3*PolyLog[3, -((2*b*E^(c + d*x))/(2*a - Sqrt[4*a^2 + 4*b^2]))])/((4*a^2 + 4*b^2)^(3/2)*(2*a - Sqrt[4*a^2 + 4*b^2])*d^4) + (48*b*f^3*PolyLog[3, (2*b*E^(c + d*x))/(-2*a + Sqrt[4*a^2 + 4*b^2])])/((4*a^2 + 4*b^2)*(-2*a + Sqrt[4*a^2 + 4*b^2])^2*d^4) - (48*a*f^3*PolyLog[3, (2*b*E^(c + d*x))/(-2*a + Sqrt[4*a^2 + 4*b^2])])/(b*(4*a^2 + 4*b^2)*(-2*a + Sqrt[4*a^2 + 4*b^2])*d^4) + (48*b*f^3*PolyLog[3, -((2*b*E^(c + d*x))/(2*a + Sqrt[4*a^2 + 4*b^2]))])/((4*a^2 + 4*b^2)*(2*a + Sqrt[4*a^2 + 4*b^2])^2*d^4) - (48*a*(-2*a - Sqrt[4*a^2 + 4*b^2])*f^3*PolyLog[3, -((2*b*E^(c + d*x))/(2*a + Sqrt[4*a^2 + 4*b^2]))])/(b*(4*a^2 + 4*b^2)*(2*a + Sqrt[4*a^2 + 4*b^2])^2*d^4) + (96*a^2*f^3*PolyLog[3, -((2*b*E^(c + d*x))/(2*a + Sqrt[4*a^2 + 4*b^2]))])/(b*(4*a^2 + 4*b^2)^(3/2)*(2*a + Sqrt[4*a^2 + 4*b^2])*d^4) + (48*b*f^3*PolyLog[3, -((2*b*E^(c + d*x))/(2*a + Sqrt[4*a^2 + 4*b^2]))])/((4*a^2 + 4*b^2)^(3/2)*(2*a + Sqrt[4*a^2 + 4*b^2])*d^4) - e^3/(2*b*d*(a + b*Sinh[c + d*x])^2) - (3*e^2*f*x)/(2*b*d*(a + b*Sinh[c + d*x])^2) - (3*e*f^2*x^2)/(2*b*d*(a + b*Sinh[c + d*x])^2) - (f^3*x^3)/(2*b*d*(a + b*Sinh[c + d*x])^2) - (3*e^2*f*Cosh[c + d*x])/(2*(a^2 + b^2)*d^2*(a + b*Sinh[c + d*x])) - (3*e*f^2*x*Cosh[c + d*x])/((a^2 + b^2)*d^2*(a + b*Sinh[c + d*x]))} *)


{(Cosh[a + b*x]*(-2 + Sinh[a + b*x]^2))/x, x, 13, (-(9/4))*Cosh[a]*CoshIntegral[b*x] + (1/4)*Cosh[3*a]*CoshIntegral[3*b*x] - (9/4)*Sinh[a]*SinhIntegral[b*x] + (1/4)*Sinh[3*a]*SinhIntegral[3*b*x]}


(* ::Section::Closed:: *)
(*Integrands of the form x^m Sinh[a+b Log[c x^n]]^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Sinh[a+b Log[c x^n]]^p*)


{Sinh[a + b*Log[c*x^n]], x, 1, -((b*n*x*Cosh[a + b*Log[c*x^n]])/(1 - b^2*n^2)) + (x*Sinh[a + b*Log[c*x^n]])/(1 - b^2*n^2)}
{Sinh[a + b*Log[c*x^n]]^2, x, 2, (2*b^2*n^2*x)/(1 - 4*b^2*n^2) - (2*b*n*x*Cosh[a + b*Log[c*x^n]]*Sinh[a + b*Log[c*x^n]])/(1 - 4*b^2*n^2) + (x*Sinh[a + b*Log[c*x^n]]^2)/(1 - 4*b^2*n^2)}
{Sinh[a + b*Log[c*x^n]]^3, x, 2, -((6*b^3*n^3*x*Cosh[a + b*Log[c*x^n]])/(1 - 10*b^2*n^2 + 9*b^4*n^4)) + (6*b^2*n^2*x*Sinh[a + b*Log[c*x^n]])/(1 - 10*b^2*n^2 + 9*b^4*n^4) - (3*b*n*x*Cosh[a + b*Log[c*x^n]]*Sinh[a + b*Log[c*x^n]]^2)/(1 - 9*b^2*n^2) + (x*Sinh[a + b*Log[c*x^n]]^3)/(1 - 9*b^2*n^2)}
{Sinh[a + b*Log[c*x^n]]^4, x, 3, (24*b^4*n^4*x)/(1 - 20*b^2*n^2 + 64*b^4*n^4) - (24*b^3*n^3*x*Cosh[a + b*Log[c*x^n]]*Sinh[a + b*Log[c*x^n]])/(1 - 20*b^2*n^2 + 64*b^4*n^4) + (12*b^2*n^2*x*Sinh[a + b*Log[c*x^n]]^2)/(1 - 20*b^2*n^2 + 64*b^4*n^4) - (4*b*n*x*Cosh[a + b*Log[c*x^n]]*Sinh[a + b*Log[c*x^n]]^3)/(1 - 16*b^2*n^2) + (x*Sinh[a + b*Log[c*x^n]]^4)/(1 - 16*b^2*n^2)}


{x^m*Sinh[a + b*Log[c*x^n]], x, 1, -((b*n*x^(1 + m)*Cosh[a + b*Log[c*x^n]])/((1 + m)^2 - b^2*n^2)) + ((1 + m)*x^(1 + m)*Sinh[a + b*Log[c*x^n]])/((1 + m)^2 - b^2*n^2)}
{x^m*Sinh[a + b*Log[c*x^n]]^2, x, 2, (2*b^2*n^2*x^(1 + m))/((1 + m)*((1 + m)^2 - 4*b^2*n^2)) - (2*b*n*x^(1 + m)*Cosh[a + b*Log[c*x^n]]*Sinh[a + b*Log[c*x^n]])/((1 + m)^2 - 4*b^2*n^2) + ((1 + m)*x^(1 + m)*Sinh[a + b*Log[c*x^n]]^2)/((1 + m)^2 - 4*b^2*n^2)}
{x^m*Sinh[a + b*Log[c*x^n]]^3, x, 2, -((6*b^3*n^3*x^(1 + m)*Cosh[a + b*Log[c*x^n]])/(((1 + m)^2 - 9*b^2*n^2)*((1 + m)^2 - b^2*n^2))) + (6*b^2*(1 + m)*n^2*x^(1 + m)*Sinh[a + b*Log[c*x^n]])/(((1 + m)^2 - 9*b^2*n^2)*((1 + m)^2 - b^2*n^2)) - (3*b*n*x^(1 + m)*Cosh[a + b*Log[c*x^n]]*Sinh[a + b*Log[c*x^n]]^2)/((1 + m)^2 - 9*b^2*n^2) + ((1 + m)*x^(1 + m)*Sinh[a + b*Log[c*x^n]]^3)/((1 + m)^2 - 9*b^2*n^2)}
{x^m*Sinh[a + b*Log[c*x^n]]^4, x, 3, (24*b^4*n^4*x^(1 + m))/((1 + m)*((1 + m)^2 - 16*b^2*n^2)*((1 + m)^2 - 4*b^2*n^2)) - (24*b^3*n^3*x^(1 + m)*Cosh[a + b*Log[c*x^n]]*Sinh[a + b*Log[c*x^n]])/(((1 + m)^2 - 16*b^2*n^2)*((1 + m)^2 - 4*b^2*n^2)) + (12*b^2*(1 + m)*n^2*x^(1 + m)*Sinh[a + b*Log[c*x^n]]^2)/(((1 + m)^2 - 16*b^2*n^2)*((1 + m)^2 - 4*b^2*n^2)) - (4*b*n*x^(1 + m)*Cosh[a + b*Log[c*x^n]]*Sinh[a + b*Log[c*x^n]]^3)/((1 + m)^2 - 16*b^2*n^2) + ((1 + m)*x^(1 + m)*Sinh[a + b*Log[c*x^n]]^4)/((1 + m)^2 - 16*b^2*n^2)}


{Sinh[a + b*Log[c*x^n]]/x, x, 2, Cosh[a + b*Log[c*x^n]]/(b*n)}
{Sinh[a + b*Log[c*x^n]]^2/x, x, 2, -(Log[c*x^n]/(2*n)) + (Cosh[a + b*Log[c*x^n]]*Sinh[a + b*Log[c*x^n]])/(2*b*n)}
{Sinh[a + b*Log[c*x^n]]^3/x, x, 3, -(Cosh[a + b*Log[c*x^n]]/(b*n)) + Cosh[a + b*Log[c*x^n]]^3/(3*b*n)}
{Sinh[a + b*Log[c*x^n]]^4/x, x, 3, (3*Log[c*x^n])/(8*n) - (3*Cosh[a + b*Log[c*x^n]]*Sinh[a + b*Log[c*x^n]])/(8*b*n) + (Cosh[a + b*Log[c*x^n]]*Sinh[a + b*Log[c*x^n]]^3)/(4*b*n)}
{Sinh[a + b*Log[c*x^n]]^5/x, x, 3, Cosh[a + b*Log[c*x^n]]/(b*n) - (2*Cosh[a + b*Log[c*x^n]]^3)/(3*b*n) + Cosh[a + b*Log[c*x^n]]^5/(5*b*n)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Sinh[a+b Log[c x^n]]^(p/2)*)


{Sinh[a + b*Log[c*x^n]]^(5/2)/x, x, 4, -((6*I*EllipticE[Pi/4 - (1/2)*I*(a + b*Log[c*x^n]), 2]*Sqrt[Sinh[a + b*Log[c*x^n]]])/(5*b*n*Sqrt[I*Sinh[a + b*Log[c*x^n]]])) + (2*Cosh[a + b*Log[c*x^n]]*Sinh[a + b*Log[c*x^n]]^(3/2))/(5*b*n)}
{Sinh[a + b*Log[c*x^n]]^(3/2)/x, x, 4, -((2*I*EllipticF[Pi/4 - (1/2)*I*(a + b*Log[c*x^n]), 2]*Sqrt[I*Sinh[a + b*Log[c*x^n]]])/(3*b*n*Sqrt[Sinh[a + b*Log[c*x^n]]])) + (2*Cosh[a + b*Log[c*x^n]]*Sqrt[Sinh[a + b*Log[c*x^n]]])/(3*b*n)}
{Sqrt[Sinh[a + b*Log[c*x^n]]]/x, x, 3, (2*I*EllipticE[Pi/4 - (1/2)*I*(a + b*Log[c*x^n]), 2]*Sqrt[Sinh[a + b*Log[c*x^n]]])/(b*n*Sqrt[I*Sinh[a + b*Log[c*x^n]]])}
{1/(x*Sqrt[Sinh[a + b*Log[c*x^n]]]), x, 3, (2*I*EllipticF[Pi/4 - (1/2)*I*(a + b*Log[c*x^n]), 2]*Sqrt[I*Sinh[a + b*Log[c*x^n]]])/(b*n*Sqrt[Sinh[a + b*Log[c*x^n]]])}
{1/(x*Sinh[a + b*Log[c*x^n]]^(3/2)), x, 4, -((2*Cosh[a + b*Log[c*x^n]])/(b*n*Sqrt[Sinh[a + b*Log[c*x^n]]])) + (2*I*EllipticE[Pi/4 - (1/2)*I*(a + b*Log[c*x^n]), 2]*Sqrt[Sinh[a + b*Log[c*x^n]]])/(b*n*Sqrt[I*Sinh[a + b*Log[c*x^n]]])}
{1/(x*Sinh[a + b*Log[c*x^n]]^(5/2)), x, 4, -((2*Cosh[a + b*Log[c*x^n]])/(3*b*n*Sinh[a + b*Log[c*x^n]]^(3/2))) - (2*I*EllipticF[Pi/4 - (1/2)*I*(a + b*Log[c*x^n]), 2]*Sqrt[I*Sinh[a + b*Log[c*x^n]]])/(3*b*n*Sqrt[Sinh[a + b*Log[c*x^n]]])}


{Sinh[a + 2/n*Log[c*x^n]]^(5/2), x, 6, (-(5/16))*x*Sqrt[Sinh[a + (2*Log[c*x^n])/n]] + (5*x*ArcTan[Sqrt[-1 + E^(2*a)*(c*x^n)^(4/n)]]*Sqrt[Sinh[a + (2*Log[c*x^n])/n]])/(16*Sqrt[-1 + E^(2*a)*(c*x^n)^(4/n)]) + (5/24)*x*Cosh[a + (2*Log[c*x^n])/n]*Sinh[a + (2*Log[c*x^n])/n]^(3/2) - (1/24)*x*Sinh[a + (2*Log[c*x^n])/n]^(5/2)}
{Sqrt[Sinh[a + 2/n*Log[c*x^n]]], x, 5, (1/2)*x*Sqrt[Sinh[a + (2*Log[c*x^n])/n]] - (x*ArcTan[Sqrt[-1 + E^(2*a)*(c*x^n)^(4/n)]]*Sqrt[Sinh[a + (2*Log[c*x^n])/n]])/(2*Sqrt[-1 + E^(2*a)*(c*x^n)^(4/n)])}
{1/Sinh[a + 2/n*Log[c*x^n]]^(3/2), x, 1, -((x*Cosh[a + (2*Log[c*x^n])/n])/Sqrt[Sinh[a + (2*Log[c*x^n])/n]]) + x*Sqrt[Sinh[a + (2*Log[c*x^n])/n]]}
{1/Sinh[a + 2/n*Log[c*x^n]]^(7/2), x, 2, -((x*Cosh[a + (2*Log[c*x^n])/n])/(5*Sinh[a + (2*Log[c*x^n])/n]^(5/2))) - x/(15*Sinh[a + (2*Log[c*x^n])/n]^(3/2)) + (8*x*Cosh[a + (2*Log[c*x^n])/n])/(15*Sqrt[Sinh[a + (2*Log[c*x^n])/n]]) - (8/15)*x*Sqrt[Sinh[a + (2*Log[c*x^n])/n]]}


(* ::Section::Closed:: *)
(*Integrands of the form Sinh[(a+b x)/(c+d x)]^n*)


{Sinh[a/(c + d*x)], x, 3, -((a*CoshIntegral[a/(c + d*x)])/d) + ((c + d*x)*Sinh[a/(c + d*x)])/d}
{Sinh[a/(c + d*x)]^2, x, 4, ((c + d*x)*Sinh[a/(c + d*x)]^2)/d - (a*SinhIntegral[(2*a)/(c + d*x)])/d}
{Sinh[a/(c + d*x)]^3, x, 5, (3*a*CoshIntegral[a/(c + d*x)])/(4*d) - (3*a*CoshIntegral[(3*a)/(c + d*x)])/(4*d) + ((c + d*x)*Sinh[a/(c + d*x)]^3)/d}


{Sinh[b*x/(c + d*x)], x, 5, (b*c*Cosh[b/d]*CoshIntegral[(b*c)/(d*(c + d*x))])/d^2 + ((c + d*x)*Sinh[b/d - (b*c)/(d*(c + d*x))])/d - (b*c*Sinh[b/d]*SinhIntegral[(b*c)/(d*(c + d*x))])/d^2}
{Sinh[b*x/(c + d*x)]^2, x, 6, (b*c*CoshIntegral[(2*b*c)/(d*(c + d*x))]*Sinh[(2*b)/d])/d^2 + ((c + d*x)*Sinh[b/d - (b*c)/(d*(c + d*x))]^2)/d - (b*c*Cosh[(2*b)/d]*SinhIntegral[(2*b*c)/(d*(c + d*x))])/d^2}
{Sinh[b*x/(c + d*x)]^3, x, 9, -((3*b*c*Cosh[b/d]*CoshIntegral[(b*c)/(d*(c + d*x))])/(4*d^2)) + (3*b*c*Cosh[(3*b)/d]*CoshIntegral[(3*b*c)/(d*(c + d*x))])/(4*d^2) + ((c + d*x)*Sinh[b/d - (b*c)/(d*(c + d*x))]^3)/d + (3*b*c*Sinh[b/d]*SinhIntegral[(b*c)/(d*(c + d*x))])/(4*d^2) - (3*b*c*Sinh[(3*b)/d]*SinhIntegral[(3*b*c)/(d*(c + d*x))])/(4*d^2)}


{Sinh[(a + b*x)/(c + d*x)], x, 5, ((b*c - a*d)*Cosh[b/d]*CoshIntegral[(b*c - a*d)/(d*(c + d*x))])/d^2 + ((c + d*x)*Sinh[b/d - (b*c - a*d)/(d*(c + d*x))])/d - ((b*c - a*d)*Sinh[b/d]*SinhIntegral[(b*c - a*d)/(d*(c + d*x))])/d^2}
{Sinh[(a + b*x)/(c + d*x)]^2, x, 6, ((b*c - a*d)*CoshIntegral[(2*(b*c - a*d))/(d*(c + d*x))]*Sinh[(2*b)/d])/d^2 + ((c + d*x)*Sinh[b/d - (b*c - a*d)/(d*(c + d*x))]^2)/d - ((b*c - a*d)*Cosh[(2*b)/d]*SinhIntegral[(2*(b*c - a*d))/(d*(c + d*x))])/d^2}
{Sinh[(a + b*x)/(c + d*x)]^3, x, 9, -((3*(b*c - a*d)*Cosh[b/d]*CoshIntegral[(b*c - a*d)/(d*(c + d*x))])/(4*d^2)) + (3*(b*c - a*d)*Cosh[(3*b)/d]*CoshIntegral[(3*(b*c - a*d))/(d*(c + d*x))])/(4*d^2) + ((c + d*x)*Sinh[b/d - (b*c - a*d)/(d*(c + d*x))]^3)/d + (3*(b*c - a*d)*Sinh[b/d]*SinhIntegral[(b*c - a*d)/(d*(c + d*x))])/(4*d^2) - (3*(b*c - a*d)*Sinh[(3*b)/d]*SinhIntegral[(3*(b*c - a*d))/(d*(c + d*x))])/(4*d^2)}


{Sinh[e + f*(a + b*x)/(c + d*x)], x, 6, ((b*c - a*d)*f*Cosh[e + (b*f)/d]*CoshIntegral[((b*c - a*d)*f)/(d*(c + d*x))])/d^2 + ((c + d*x)*Sinh[e + (b*f)/d - ((b*c - a*d)*f)/(d*(c + d*x))])/d - ((b*c - a*d)*f*Sinh[e + (b*f)/d]*SinhIntegral[((b*c - a*d)*f)/(d*(c + d*x))])/d^2}
{Sinh[e + f*(a + b*x)/(c + d*x)]^2, x, 7, ((b*c - a*d)*f*CoshIntegral[(2*(b*c - a*d)*f)/(d*(c + d*x))]*Sinh[2*(e + (b*f)/d)])/d^2 + ((c + d*x)*Sinh[e + (b*f)/d - ((b*c - a*d)*f)/(d*(c + d*x))]^2)/d - ((b*c - a*d)*f*Cosh[2*(e + (b*f)/d)]*SinhIntegral[(2*(b*c - a*d)*f)/(d*(c + d*x))])/d^2}
{Sinh[e + f*(a + b*x)/(c + d*x)]^3, x, 10, -((3*(b*c - a*d)*f*Cosh[e + (b*f)/d]*CoshIntegral[((b*c - a*d)*f)/(d*(c + d*x))])/(4*d^2)) + (3*(b*c - a*d)*f*Cosh[3*(e + (b*f)/d)]*CoshIntegral[(3*(b*c - a*d)*f)/(d*(c + d*x))])/(4*d^2) + ((c + d*x)*Sinh[e + (b*f)/d - ((b*c - a*d)*f)/(d*(c + d*x))]^3)/d + (3*(b*c - a*d)*f*Sinh[e + (b*f)/d]*SinhIntegral[((b*c - a*d)*f)/(d*(c + d*x))])/(4*d^2) - (3*(b*c - a*d)*f*Sinh[3*(e + (b*f)/d)]*SinhIntegral[(3*(b*c - a*d)*f)/(d*(c + d*x))])/(4*d^2)}


(* ::Section::Closed:: *)
(*Miscellaneous integrands involving hyperbolic sines*)


{(x + Sinh[x])^2, x, 5, -(x/2) + x^3/3 + 2*x*Cosh[x] - 2*Sinh[x] + (1/2)*Cosh[x]*Sinh[x]}
{(x + Sinh[x])^3, x, 9, -((3*x^2)/4) + x^4/4 + 5*Cosh[x] + 3*x^2*Cosh[x] + Cosh[x]^3/3 - 6*x*Sinh[x] + (3/2)*x*Cosh[x]*Sinh[x] - (3*Sinh[x]^2)/4}


{Sinh[a + b*x]/(c + d*x^2), x, 7, -((CoshIntegral[(b*Sqrt[-c])/Sqrt[d] + b*x]*Sinh[a - (b*Sqrt[-c])/Sqrt[d]])/(2*Sqrt[-c]*Sqrt[d])) + (CoshIntegral[(b*Sqrt[-c])/Sqrt[d] - b*x]*Sinh[a + (b*Sqrt[-c])/Sqrt[d]])/(2*Sqrt[-c]*Sqrt[d]) - (Cosh[a + (b*Sqrt[-c])/Sqrt[d]]*SinhIntegral[(b*Sqrt[-c])/Sqrt[d] - b*x])/(2*Sqrt[-c]*Sqrt[d]) - (Cosh[a - (b*Sqrt[-c])/Sqrt[d]]*SinhIntegral[(b*Sqrt[-c])/Sqrt[d] + b*x])/(2*Sqrt[-c]*Sqrt[d])}
{Sinh[a + b*x]/(c + d*x + e*x^2), x, 7, (CoshIntegral[(b*(d - Sqrt[d^2 - 4*c*e]))/(2*e) + b*x]*Sinh[a - (b*(d - Sqrt[d^2 - 4*c*e]))/(2*e)])/Sqrt[d^2 - 4*c*e] - (CoshIntegral[(b*(d + Sqrt[d^2 - 4*c*e]))/(2*e) + b*x]*Sinh[a - (b*(d + Sqrt[d^2 - 4*c*e]))/(2*e)])/Sqrt[d^2 - 4*c*e] + (Cosh[a - (b*(d - Sqrt[d^2 - 4*c*e]))/(2*e)]*SinhIntegral[(b*(d - Sqrt[d^2 - 4*c*e]))/(2*e) + b*x])/Sqrt[d^2 - 4*c*e] - (Cosh[a - (b*(d + Sqrt[d^2 - 4*c*e]))/(2*e)]*SinhIntegral[(b*(d + Sqrt[d^2 - 4*c*e]))/(2*e) + b*x])/Sqrt[d^2 - 4*c*e]}
