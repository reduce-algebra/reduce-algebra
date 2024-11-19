(* ::Package:: *)

(* ::Title:: *)
(*Integration Problems Involving Hyperbolic Cosines*)


(* ::Section::Closed:: *)
(*Integrands of the form Cosh[a+b x]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Cosh[a+b x]^n*)


{Cosh[a + b*x]^1, x, 1, Sinh[a + b*x]/b}
{Cosh[a + b*x]^2, x, 1, x/2 + (Cosh[a + b*x]*Sinh[a + b*x])/(2*b)}
{Cosh[a + b*x]^3, x, 2, Sinh[a + b*x]/b + Sinh[a + b*x]^3/(3*b)}
{Cosh[a + b*x]^4, x, 2, (3*x)/8 + (3*Cosh[a + b*x]*Sinh[a + b*x])/(8*b) + (Cosh[a + b*x]^3*Sinh[a + b*x])/(4*b)}
{Cosh[a + b*x]^5, x, 2, Sinh[a + b*x]/b + (2*Sinh[a + b*x]^3)/(3*b) + Sinh[a + b*x]^5/(5*b)}
{Cosh[a + b*x]^6, x, 3, (5*x)/16 + (5*Cosh[a + b*x]*Sinh[a + b*x])/(16*b) + (5*Cosh[a + b*x]^3*Sinh[a + b*x])/(24*b) + (Cosh[a + b*x]^5*Sinh[a + b*x])/(6*b)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cosh[a+b x]^(n/2)*)


{Cosh[a + b*x]^(7/2), x, 3, -((10*I*EllipticF[(1/2)*I*(a + b*x), 2])/(21*b)) + (10*Sqrt[Cosh[a + b*x]]*Sinh[a + b*x])/(21*b) + (2*Cosh[a + b*x]^(5/2)*Sinh[a + b*x])/(7*b)}
{Cosh[a + b*x]^(5/2), x, 2, -((6*I*EllipticE[(1/2)*I*(a + b*x), 2])/(5*b)) + (2*Cosh[a + b*x]^(3/2)*Sinh[a + b*x])/(5*b)}
{Cosh[a + b*x]^(3/2), x, 2, -((2*I*EllipticF[(1/2)*I*(a + b*x), 2])/(3*b)) + (2*Sqrt[Cosh[a + b*x]]*Sinh[a + b*x])/(3*b)}
{Cosh[a + b*x]^(1/2), x, 1, -((2*I*EllipticE[(1/2)*I*(a + b*x), 2])/b)}
{1/Cosh[a + b*x]^(1/2), x, 1, -((2*I*EllipticF[(1/2)*I*(a + b*x), 2])/b)}
{1/Cosh[a + b*x]^(3/2), x, 2, (2*I*EllipticE[(1/2)*I*(a + b*x), 2])/b + (2*Sinh[a + b*x])/(b*Sqrt[Cosh[a + b*x]])}
{1/Cosh[a + b*x]^(5/2), x, 2, -((2*I*EllipticF[(1/2)*I*(a + b*x), 2])/(3*b)) + (2*Sinh[a + b*x])/(3*b*Cosh[a + b*x]^(3/2))}
{1/Cosh[a + b*x]^(7/2), x, 3, (6*I*EllipticE[(1/2)*I*(a + b*x), 2])/(5*b) + (2*Sinh[a + b*x])/(5*b*Cosh[a + b*x]^(5/2)) + (6*Sinh[a + b*x])/(5*b*Sqrt[Cosh[a + b*x]])}


(* ::Section::Closed:: *)
(*Integrands of the form (c Cosh[a+b x]^m)^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Cosh[a+b x])^n*)


{(a*Cosh[x])^(7/2), x, 4, -((10*I*a^4*Sqrt[Cosh[x]]*EllipticF[(I*x)/2, 2])/(21*Sqrt[a*Cosh[x]])) + (10/21)*a^3*Sqrt[a*Cosh[x]]*Sinh[x] + (2/7)*a*(a*Cosh[x])^(5/2)*Sinh[x]}
{(a*Cosh[x])^(5/2), x, 3, -((6*I*a^2*Sqrt[a*Cosh[x]]*EllipticE[(I*x)/2, 2])/(5*Sqrt[Cosh[x]])) + (2/5)*a*(a*Cosh[x])^(3/2)*Sinh[x]}
{(a*Cosh[x])^(3/2),x, 3, -((2*I*a^2*Sqrt[Cosh[x]]*EllipticF[(I*x)/2, 2])/(3*Sqrt[a*Cosh[x]])) + (2/3)*a*Sqrt[a*Cosh[x]]*Sinh[x]}
{(a*Cosh[x])^(1/2), x, 2, -((2*I*Sqrt[a*Cosh[x]]*EllipticE[(I*x)/2, 2])/Sqrt[Cosh[x]])}
{1/(a*Cosh[x])^(1/2), x, 2, -((2*I*Sqrt[Cosh[x]]*EllipticF[(I*x)/2, 2])/Sqrt[a*Cosh[x]])}
{1/(a*Cosh[x])^(3/2), x, 3, (2*I*Sqrt[a*Cosh[x]]*EllipticE[(I*x)/2, 2])/(a^2*Sqrt[Cosh[x]]) + (2*Sinh[x])/(a*Sqrt[a*Cosh[x]])}
{1/(a*Cosh[x])^(5/2), x, 3, -((2*I*Sqrt[Cosh[x]]*EllipticF[(I*x)/2, 2])/(3*a^2*Sqrt[a*Cosh[x]])) + (2*Sinh[x])/(3*a*(a*Cosh[x])^(3/2))}
{1/(a*Cosh[x])^(7/2), x, 4, (6*I*Sqrt[a*Cosh[x]]*EllipticE[(I*x)/2, 2])/(5*a^4*Sqrt[Cosh[x]]) + (2*Sinh[x])/(5*a*(a*Cosh[x])^(5/2)) + (6*Sinh[x])/(5*a^3*Sqrt[a*Cosh[x]])}


{(b*Cosh[c + d*x])^n, x, 2, ((b*Cosh[c + d*x])^(1 + n)*(Cosh[c + d*x]^2)^((1/2)*(-1 - n))*Hypergeometric2F1[1/2, (1 - n)/2, 3/2, -Sinh[c + d*x]^2]*Sinh[c + d*x])/(b*d)}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Cosh[a+b x]^2)^n*)


{(a*Cosh[x]^2)^(5/2),x, 4, (8/15)*a^2*Sqrt[a*Cosh[x]^2]*Tanh[x] + (4/15)*a*(a*Cosh[x]^2)^(3/2)*Tanh[x] + (1/5)*(a*Cosh[x]^2)^(5/2)*Tanh[x]}
{(a*Cosh[x]^2)^(3/2),x, 3, (2/3)*a*Sqrt[a*Cosh[x]^2]*Tanh[x] + (1/3)*(a*Cosh[x]^2)^(3/2)*Tanh[x]}
{(a*Cosh[x]^2)^(1/2), x, 2, Sqrt[a*Cosh[x]^2]*Tanh[x]}
{1/(a*Cosh[x]^2)^(1/2), x, 2, (ArcTan[Sinh[x]]*Cosh[x])/Sqrt[a*Cosh[x]^2]}
{1/(a*Cosh[x]^2)^(3/2), x, 3, (ArcTan[Sinh[x]]*Cosh[x])/(2*a*Sqrt[a*Cosh[x]^2]) + Tanh[x]/(2*a*Sqrt[a*Cosh[x]^2])}
{1/(a*Cosh[x]^2)^(5/2), x, 4, (3*ArcTan[Sinh[x]]*Cosh[x])/(8*a^2*Sqrt[a*Cosh[x]^2]) + Tanh[x]/(4*a*(a*Cosh[x]^2)^(3/2)) + (3*Tanh[x])/(8*a^2*Sqrt[a*Cosh[x]^2])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Cosh[a+b x]^3)^n*)


{(a*Cosh[x]^3)^(5/2),x, 6, -((26*I*a^2*Sqrt[a*Cosh[x]^3]*EllipticF[(I*x)/2, 2])/(77*Cosh[x]^(3/2))) + (78/385)*a^2*Cosh[x]*Sqrt[a*Cosh[x]^3]*Sinh[x] + (26/165)*a^2*Cosh[x]^3*Sqrt[a*Cosh[x]^3]*Sinh[x] + (2/15)*a^2*Cosh[x]^5*Sqrt[a*Cosh[x]^3]*Sinh[x] + (26/77)*a^2*Sqrt[a*Cosh[x]^3]*Tanh[x]}
{(a*Cosh[x]^3)^(3/2),x, 4, -((14*I*a*Sqrt[a*Cosh[x]^3]*EllipticE[(I*x)/2, 2])/(15*Cosh[x]^(3/2))) + (14/45)*a*Sqrt[a*Cosh[x]^3]*Sinh[x] + (2/9)*a*Cosh[x]^2*Sqrt[a*Cosh[x]^3]*Sinh[x]}
{(a*Cosh[x]^3)^(1/2), x, 3, -((2*I*Sqrt[a*Cosh[x]^3]*EllipticF[(I*x)/2, 2])/(3*Cosh[x]^(3/2))) + (2/3)*Sqrt[a*Cosh[x]^3]*Tanh[x]}
{1/(a*Cosh[x]^3)^(1/2), x, 3, (2*I*Cosh[x]^(3/2)*EllipticE[(I*x)/2, 2])/Sqrt[a*Cosh[x]^3] + (2*Cosh[x]*Sinh[x])/Sqrt[a*Cosh[x]^3]}
{1/(a*Cosh[x]^3)^(3/2),x, 4, -((10*I*Cosh[x]^(3/2)*EllipticF[(I*x)/2, 2])/(21*a*Sqrt[a*Cosh[x]^3])) + (10*Sinh[x])/(21*a*Sqrt[a*Cosh[x]^3]) + (2*Sech[x]*Tanh[x])/(7*a*Sqrt[a*Cosh[x]^3])}
{1/(a*Cosh[x]^3)^(5/2),x, 6, (154*I*Cosh[x]^(3/2)*EllipticE[(I*x)/2, 2])/(195*a^2*Sqrt[a*Cosh[x]^3]) + (154*Cosh[x]*Sinh[x])/(195*a^2*Sqrt[a*Cosh[x]^3]) + (154*Tanh[x])/(585*a^2*Sqrt[a*Cosh[x]^3]) + (22*Sech[x]^2*Tanh[x])/(117*a^2*Sqrt[a*Cosh[x]^3]) + (2*Sech[x]^4*Tanh[x])/(13*a^2*Sqrt[a*Cosh[x]^3])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c Cosh[a+b x]^4)^n*)


{(a*Cosh[x]^4)^(5/2),x, 6, (63/256)*a^2*x*Sqrt[a*Cosh[x]^4]*Sech[x]^2 + (21/128)*a^2*Cosh[x]*Sqrt[a*Cosh[x]^4]*Sinh[x] + (21/160)*a^2*Cosh[x]^3*Sqrt[a*Cosh[x]^4]*Sinh[x] + (9/80)*a^2*Cosh[x]^5*Sqrt[a*Cosh[x]^4]*Sinh[x] + (1/10)*a^2*Cosh[x]^7*Sqrt[a*Cosh[x]^4]*Sinh[x] + (63/256)*a^2*Sqrt[a*Cosh[x]^4]*Tanh[x]}
{(a*Cosh[x]^4)^(3/2),x, 4, (5/16)*a*x*Sqrt[a*Cosh[x]^4]*Sech[x]^2 + (5/24)*a*Cosh[x]*Sqrt[a*Cosh[x]^4]*Sinh[x] + (1/6)*a*Cosh[x]^3*Sqrt[a*Cosh[x]^4]*Sinh[x] + (5/16)*a*Sqrt[a*Cosh[x]^4]*Tanh[x]}
{(a*Cosh[x]^4)^(1/2), x, 2, (1/2)*x*Sqrt[a*Cosh[x]^4]*Sech[x]^2 + (1/2)*Sqrt[a*Cosh[x]^4]*Tanh[x]}
{1/(a*Cosh[x]^4)^(1/2), x, 2, (Cosh[x]*Sinh[x])/Sqrt[a*Cosh[x]^4]}
{1/(a*Cosh[x]^4)^(3/2),x, 3, (Cosh[x]*Sinh[x])/(a*Sqrt[a*Cosh[x]^4]) - (2*Sinh[x]^2*Tanh[x])/(3*a*Sqrt[a*Cosh[x]^4]) + (Sinh[x]^2*Tanh[x]^3)/(5*a*Sqrt[a*Cosh[x]^4])}
{1/(a*Cosh[x]^4)^(5/2),x, 3, (Cosh[x]*Sinh[x])/(a^2*Sqrt[a*Cosh[x]^4]) - (4*Sinh[x]^2*Tanh[x])/(3*a^2*Sqrt[a*Cosh[x]^4]) + (6*Sinh[x]^2*Tanh[x]^3)/(5*a^2*Sqrt[a*Cosh[x]^4]) - (4*Sinh[x]^2*Tanh[x]^5)/(7*a^2*Sqrt[a*Cosh[x]^4]) + (Sinh[x]^2*Tanh[x]^7)/(9*a^2*Sqrt[a*Cosh[x]^4])}


(* ::Subsection:: *)
(*Integrands of the form (c Cosh[a+b x]^m)^n*)


(* ::Section::Closed:: *)
(*Integrands of the form Hyper[c+d x]^m (a+b Cosh[c+d x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sinh[c+d x]^m (a+b Cosh[c+d x])^n*)


(* ::Subsubsection::Closed:: *)
(*a^2-b^2=0*)


{Sinh[x]/(1 + Cosh[x])^2, x, 2, -(1/(1 + Cosh[x]))}
{Sinh[x]/(1 - Cosh[x])^2, x, 2, 1/(1 - Cosh[x])}
{Sinh[x]^2/(1 + Cosh[x])^2, x, 2, x - (2*Sinh[x])/(1 + Cosh[x])}
{Sinh[x]^2/(1 - Cosh[x])^2, x, 2, x + (2*Sinh[x])/(1 - Cosh[x])}
{Sinh[x]^3/(1 + Cosh[x])^2, x, 4, Cosh[x] - 2*Log[1 + Cosh[x]]}
{Sinh[x]^3/(1 - Cosh[x])^2, x, 4, Cosh[x] + 2*Log[1 - Cosh[x]]}


{Sinh[x]/(1 + Cosh[x])^3, x, 2, -(1/(2*(1 + Cosh[x])^2))}
{Sinh[x]/(1 - Cosh[x])^3, x, 2, 1/(2*(1 - Cosh[x])^2)}
{Sinh[x]^2/(1 + Cosh[x])^3, x, 1, Sinh[x]^3/(3*(1 + Cosh[x])^3)}
{Sinh[x]^2/(1 - Cosh[x])^3, x, 1, -(Sinh[x]^3/(3*(1 - Cosh[x])^3))}
{Sinh[x]^3/(1 + Cosh[x])^3, x, 4, 2/(1 + Cosh[x]) + Log[1 + Cosh[x]]}
{Sinh[x]^3/(1 - Cosh[x])^3, x, 4, -(2/(1 - Cosh[x])) - Log[1 - Cosh[x]]}


{Sinh[x]^8/(a + a*Cosh[x]), x, 4, (5*x)/(16*a) - (5*Cosh[x]*Sinh[x])/(16*a) + (5*Cosh[x]*Sinh[x]^3)/(24*a) - (Cosh[x]*Sinh[x]^5)/(6*a) + Sinh[x]^7/(7*a)}
{Sinh[x]^7/(a + a*Cosh[x]), x, 4, -(Cosh[x]/a) + Cosh[x]^2/(2*a) + (2*Cosh[x]^3)/(3*a) - Cosh[x]^4/(2*a) - Cosh[x]^5/(5*a) + Cosh[x]^6/(6*a)}
{Sinh[x]^6/(a + a*Cosh[x]), x, 3, -((3*x)/(8*a)) + (3*Cosh[x]*Sinh[x])/(8*a) - (Cosh[x]*Sinh[x]^3)/(4*a) + Sinh[x]^5/(5*a)}
{Sinh[x]^5/(a + a*Cosh[x]), x, 4, Cosh[x]/a - Cosh[x]^2/(2*a) - Cosh[x]^3/(3*a) + Cosh[x]^4/(4*a)}
{Sinh[x]^4/(a + a*Cosh[x]), x, 2, x/(2*a) - (Cosh[x]*Sinh[x])/(2*a) + Sinh[x]^3/(3*a)}
{Sinh[x]^3/(a + a*Cosh[x]), x, 3, -(Cosh[x]/a) + Cosh[x]^2/(2*a)}
{Sinh[x]^2/(a + a*Cosh[x]), x, 2, -(x/a) + Sinh[x]/a}
{Sinh[x]^1/(a + a*Cosh[x]), x, 2, Log[1 + Cosh[x]]/a}
{Csch[x]^1/(a + a*Cosh[x]), x, 5, -(ArcTanh[Cosh[x]]/(2*a)) + 1/(2*a*(1 + Cosh[x]))}
{Csch[x]^2/(a + a*Cosh[x]), x, 3, -(Coth[x]/a) + Coth[x]^3/(3*a) - Csch[x]^3/(3*a)}
{Csch[x]^3/(a + a*Cosh[x]), x, 5, (3*ArcTanh[Cosh[x]])/(8*a) + 1/(8*a*(1 - Cosh[x])) - 1/(8*a*(1 + Cosh[x])^2) - 1/(4*a*(1 + Cosh[x]))}
{Csch[x]^4/(a + a*Cosh[x]), x, 3, Coth[x]/a - (2*Coth[x]^3)/(3*a) + Coth[x]^5/(5*a) - Csch[x]^5/(5*a)}
{Csch[x]^5/(a + a*Cosh[x]), x, 5, -((5*ArcTanh[Cosh[x]])/(16*a)) - 1/(32*a*(1 - Cosh[x])^2) - 1/(8*a*(1 - Cosh[x])) + 1/(24*a*(1 + Cosh[x])^3) + 3/(32*a*(1 + Cosh[x])^2) + 3/(16*a*(1 + Cosh[x]))}


(* ::Subsubsection::Closed:: *)
(*a^2-b^2!=0*)


{Sinh[x]^7/(a + b*Cosh[x]), x, 3, -((a*(a^4 - 3*a^2*b^2 + 3*b^4)*Cosh[x])/b^6) + ((a^4 - 3*a^2*b^2 + 3*b^4)*Cosh[x]^2)/(2*b^5) - (a*(a^2 - 3*b^2)*Cosh[x]^3)/(3*b^4) + ((a^2 - 3*b^2)*Cosh[x]^4)/(4*b^3) - (a*Cosh[x]^5)/(5*b^2) + Cosh[x]^6/(6*b) + ((a^2 - b^2)^3*Log[a + b*Cosh[x]])/b^7}
{Sinh[x]^6/(a + b*Cosh[x]), x, 8, -((3*a*x)/(8*b^2)) + (a*(a^2 - b^2)*x)/(2*b^4) - (a*(a^2 - b^2)^2*x)/b^6 + (2*(a^2 - b^2)^(5/2)*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[x/2])/(a + b)])/b^6 + ((a^2 - b^2)^2*Sinh[x])/b^5 + (3*a*Cosh[x]*Sinh[x])/(8*b^2) - (a*(a^2 - b^2)*Cosh[x]*Sinh[x])/(2*b^4) + ((a^2 - b^2)*Sinh[x]^3)/(3*b^3) - (a*Cosh[x]*Sinh[x]^3)/(4*b^2) + Sinh[x]^5/(5*b)}
{Sinh[x]^5/(a + b*Cosh[x]), x, 3, -((a*(a^2 - 2*b^2)*Cosh[x])/b^4) + ((a^2 - 2*b^2)*Cosh[x]^2)/(2*b^3) - (a*Cosh[x]^3)/(3*b^2) + Cosh[x]^4/(4*b) + ((a^2 - b^2)^2*Log[a + b*Cosh[x]])/b^5}
{Sinh[x]^4/(a + b*Cosh[x]), x, 5, (a*x)/(2*b^2) - (a*(a^2 - b^2)*x)/b^4 + (2*(a^2 - b^2)^(3/2)*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[x/2])/(a + b)])/b^4 + ((a^2 - b^2)*Sinh[x])/b^3 - (a*Cosh[x]*Sinh[x])/(2*b^2) + Sinh[x]^3/(3*b)}
{Sinh[x]^3/(a + b*Cosh[x]), x, 3, -((a*Cosh[x])/b^2) + Cosh[x]^2/(2*b) + ((a^2 - b^2)*Log[a + b*Cosh[x]])/b^3}
{Sinh[x]^2/(a + b*Cosh[x]), x, 3, -((a*x)/b^2) + (2*Sqrt[a^2 - b^2]*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[x/2])/(a + b)])/b^2 + Sinh[x]/b}
{Sinh[x]^1/(a + b*Cosh[x]), x, 2, Log[a + b*Cosh[x]]/b}
{Csch[x]^1/(a + b*Cosh[x]), x, 6, Log[1 - Cosh[x]]/(2*(a + b)) - Log[1 + Cosh[x]]/(2*(a - b)) + (b*Log[a + b*Cosh[x]])/(a^2 - b^2)}
{Csch[x]^2/(a + b*Cosh[x]), x, 3, (2*b^2*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[x/2])/(a + b)])/(a^2 - b^2)^(3/2) - (a*Coth[x])/(a^2 - b^2) + (b*Csch[x])/(a^2 - b^2)}
{Csch[x]^3/(a + b*Cosh[x]), x, 7, -((b - a*Cosh[x])/(2*(a^2 - b^2)*(1 - Cosh[x]^2))) - ((a + 2*b)*Log[1 - Cosh[x]])/(4*(a + b)^2) + ((a - 2*b)*Log[1 + Cosh[x]])/(4*(a - b)^2) + (b^3*Log[a + b*Cosh[x]])/(a^2 - b^2)^2}
{Csch[x]^4/(a + b*Cosh[x]), x, 6, (2*b^4*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[x/2])/(a + b)])/(a^2 - b^2)^(5/2) - (a*b^2*Coth[x])/(a^2 - b^2)^2 + (a*Coth[x])/(a^2 - b^2) - (a*Coth[x]^3)/(3*(a^2 - b^2)) + (b^3*Csch[x])/(a^2 - b^2)^2 + (b*Csch[x]^3)/(3*(a^2 - b^2))}
{Csch[x]^5/(a + b*Cosh[x]), x, 8, (b - a*Cosh[x])/(4*(a^2 - b^2)*(1 - Cosh[x]^2)^2) - (4*b^3 + a*(3*a^2 - 7*b^2)*Cosh[x])/(8*(a^2 - b^2)^2*(1 - Cosh[x]^2)) + ((3*a^2 + 9*a*b + 8*b^2)*Log[1 - Cosh[x]])/(16*(a + b)^3) - ((3*a^2 - 9*a*b + 8*b^2)*Log[1 + Cosh[x]])/(16*(a - b)^3) + (b^5*Log[a + b*Cosh[x]])/(a^2 - b^2)^3}
{Csch[x]^6/(a + b*Cosh[x]), x, 9, (2*b^6*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[x/2])/(a + b)])/(a^2 - b^2)^(7/2) - (a*b^4*Coth[x])/(a^2 - b^2)^3 + (a*b^2*Coth[x])/(a^2 - b^2)^2 - (a*Coth[x])/(a^2 - b^2) - (a*b^2*Coth[x]^3)/(3*(a^2 - b^2)^2) + (2*a*Coth[x]^3)/(3*(a^2 - b^2)) - (a*Coth[x]^5)/(5*(a^2 - b^2)) + (b^5*Csch[x])/(a^2 - b^2)^3 + (b^3*Csch[x]^3)/(3*(a^2 - b^2)^2) + (b*Csch[x]^5)/(5*(a^2 - b^2))}


{Sinh[x]^2/(a + b*Cosh[x])^2, x, 3, x/b^2 - (2*a*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[x/2])/(a + b)])/(b^2*Sqrt[a^2 - b^2]) - Sinh[x]/(b*(a + b*Cosh[x]))}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cosh[c+d x]^m (a+b Cosh[c+d x])^n*)


(* ::Subsubsection::Closed:: *)
(*n*)


{Cosh[x]^4/(a + b*Cosh[x]), x, 5, -((a*(2*a^2 + b^2)*x)/(2*b^4)) + (2*a^4*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[x/2])/(a + b)])/(b^4*Sqrt[a^2 - b^2]) + ((3*a^2 + 2*b^2)*Sinh[x])/(3*b^3) - (a*Cosh[x]*Sinh[x])/(2*b^2) + (Cosh[x]^2*Sinh[x])/(3*b)}
{Cosh[x]^3/(a + b*Cosh[x]), x, 4, ((2*a^2 + b^2)*x)/(2*b^3) - (2*a^3*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[x/2])/(a + b)])/(b^3*Sqrt[a^2 - b^2]) - (a*Sinh[x])/b^2 + (Cosh[x]*Sinh[x])/(2*b)}
{Cosh[x]^2/(a + b*Cosh[x]), x, 3, -((a*x)/b^2) + (2*a^2*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[x/2])/(a + b)])/(b^2*Sqrt[a^2 - b^2]) + Sinh[x]/b}
{Cosh[x]^1/(a + b*Cosh[x]), x, 2, x/b - (2*a*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[x/2])/(a + b)])/(b*Sqrt[a^2 - b^2])}
{Sech[x]^1/(a + b*Cosh[x]), x, 3, ArcTan[Sinh[x]]/a - (2*b*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[x/2])/(a + b)])/(a*Sqrt[a^2 - b^2])}
{Sech[x]^2/(a + b*Cosh[x]), x, 5, -((b*ArcTan[Sinh[x]])/a^2) + (2*b^2*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[x/2])/(a + b)])/(a^2*Sqrt[a^2 - b^2]) + Tanh[x]/a}
{Sech[x]^3/(a + b*Cosh[x]), x, 5, ((a^2 + 2*b^2)*ArcTan[Sinh[x]])/(2*a^3) - (2*b^3*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[x/2])/(a + b)])/(a^3*Sqrt[a^2 - b^2]) - (b*Tanh[x])/a^2 + (Sech[x]*Tanh[x])/(2*a)}
{Sech[x]^4/(a + b*Cosh[x]), x, 6, -((b*(a^2 + 2*b^2)*ArcTan[Sinh[x]])/(2*a^4)) + (2*b^4*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[x/2])/(a + b)])/(a^4*Sqrt[a^2 - b^2]) + ((2*a^2 + 3*b^2)*Tanh[x])/(3*a^3) - (b*Sech[x]*Tanh[x])/(2*a^2) + (Sech[x]^2*Tanh[x])/(3*a)}


{Cosh[x]^4/(a + a*Cosh[x]), x, 4, -((3*x)/(2*a)) + (4*Sinh[x])/a - (3*Cosh[x]*Sinh[x])/(2*a) - (Cosh[x]^3*Sinh[x])/(a + a*Cosh[x]) + (4*Sinh[x]^3)/(3*a)}
{Cosh[x]^3/(a + a*Cosh[x]), x, 3, (3*x)/(2*a) - (2*Sinh[x])/a + (3*Cosh[x]*Sinh[x])/(2*a) - (Cosh[x]^2*Sinh[x])/(a + a*Cosh[x])}
{Cosh[x]^2/(a + a*Cosh[x]), x, 3, -(x/a) + Sinh[x]/a + Sinh[x]/(a + a*Cosh[x])}
{Cosh[x]^1/(a + a*Cosh[x]), x, 2, x/a - Sinh[x]/(a + a*Cosh[x])}
{Sech[x]^1/(a + a*Cosh[x]), x, 3, ArcTan[Sinh[x]]/a - Sinh[x]/(a + a*Cosh[x])}
{Sech[x]^2/(a + a*Cosh[x]), x, 3, -(ArcTan[Sinh[x]]/a) + (2*Tanh[x])/a - Tanh[x]/(a + a*Cosh[x])}
{Sech[x]^3/(a + a*Cosh[x]), x, 4, (3*ArcTan[Sinh[x]])/(2*a) - (2*Tanh[x])/a + (3*Sech[x]*Tanh[x])/(2*a) - (Sech[x]*Tanh[x])/(a + a*Cosh[x])}
{Sech[x]^4/(a + a*Cosh[x]), x, 5, -((3*ArcTan[Sinh[x]])/(2*a)) + (4*Tanh[x])/a - (3*Sech[x]*Tanh[x])/(2*a) - (Sech[x]^2*Tanh[x])/(a + a*Cosh[x]) - (4*Tanh[x]^3)/(3*a)}


{(a + b*Cosh[c + d*x])^5, x, 5, (1/8)*a*(8*a^4 + 40*a^2*b^2 + 15*b^4)*x + (b*(107*a^4 + 192*a^2*b^2 + 16*b^4)*Sinh[c + d*x])/(30*d) + (7*a*b^2*(22*a^2 + 23*b^2)*Cosh[c + d*x]*Sinh[c + d*x])/(120*d) + (b*(47*a^2 + 16*b^2)*(a + b*Cosh[c + d*x])^2*Sinh[c + d*x])/(60*d) + (9*a*b*(a + b*Cosh[c + d*x])^3*Sinh[c + d*x])/(20*d) + (b*(a + b*Cosh[c + d*x])^4*Sinh[c + d*x])/(5*d)}
{(a + b*Cosh[c + d*x])^4, x, 4, (1/8)*(8*a^4 + 24*a^2*b^2 + 3*b^4)*x + (a*b*(19*a^2 + 16*b^2)*Sinh[c + d*x])/(6*d) + (b^2*(26*a^2 + 9*b^2)*Cosh[c + d*x]*Sinh[c + d*x])/(24*d) + (7*a*b*(a + b*Cosh[c + d*x])^2*Sinh[c + d*x])/(12*d) + (b*(a + b*Cosh[c + d*x])^3*Sinh[c + d*x])/(4*d)}
{(a + b*Cosh[c + d*x])^3, x, 3, (1/2)*a*(2*a^2 + 3*b^2)*x + (2*b*(4*a^2 + b^2)*Sinh[c + d*x])/(3*d) + (5*a*b^2*Cosh[c + d*x]*Sinh[c + d*x])/(6*d) + (b*(a + b*Cosh[c + d*x])^2*Sinh[c + d*x])/(3*d)}
{(a + b*Cosh[c + d*x])^2, x, 2, (1/2)*(2*a^2 + b^2)*x + (2*a*b*Sinh[c + d*x])/d + (b^2*Cosh[c + d*x]*Sinh[c + d*x])/(2*d)}
{(a + b*Cosh[c + d*x]), x, 2, a*x + (b*Sinh[c + d*x])/d}
{1/(a + b*Cosh[c + d*x]), x, 1, (2*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[(1/2)*(c + d*x)])/(a + b)])/(Sqrt[a^2 - b^2]*d)}
{1/(a + b*Cosh[c + d*x])^2, x, 3, (2*a*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[(1/2)*(c + d*x)])/(a + b)])/((a^2 - b^2)^(3/2)*d) - (b*Sinh[c + d*x])/((a^2 - b^2)*d*(a + b*Cosh[c + d*x]))}
{1/(a + b*Cosh[c + d*x])^3, x, 4, ((2*a^2 + b^2)*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[(1/2)*(c + d*x)])/(a + b)])/((a^2 - b^2)^(5/2)*d) - (b*Sinh[c + d*x])/(2*(a^2 - b^2)*d*(a + b*Cosh[c + d*x])^2) - (3*a*b*Sinh[c + d*x])/(2*(a^2 - b^2)^2*d*(a + b*Cosh[c + d*x]))}
{1/(a + b*Cosh[c + d*x])^4, x, 5, (a*(2*a^2 + 3*b^2)*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[(1/2)*(c + d*x)])/(a + b)])/((a^2 - b^2)^(7/2)*d) - (b*Sinh[c + d*x])/(3*(a^2 - b^2)*d*(a + b*Cosh[c + d*x])^3) - (5*a*b*Sinh[c + d*x])/(6*(a^2 - b^2)^2*d*(a + b*Cosh[c + d*x])^2) - (b*(11*a^2 + 4*b^2)*Sinh[c + d*x])/(6*(a^2 - b^2)^3*d*(a + b*Cosh[c + d*x]))}


{1/(1 + Cosh[c + d*x]), x, 1, Sinh[c + d*x]/(d*(1 + Cosh[c + d*x]))}
{1/(1 + Cosh[c + d*x])^2, x, 2, Sinh[c + d*x]/(3*d*(1 + Cosh[c + d*x])^2) + Sinh[c + d*x]/(3*d*(1 + Cosh[c + d*x]))}
{1/(1 + Cosh[c + d*x])^3, x, 3, Sinh[c + d*x]/(5*d*(1 + Cosh[c + d*x])^3) + (2*Sinh[c + d*x])/(15*d*(1 + Cosh[c + d*x])^2) + (2*Sinh[c + d*x])/(15*d*(1 + Cosh[c + d*x]))}
{1/(1 + Cosh[c + d*x])^4, x, 4, Sinh[c + d*x]/(7*d*(1 + Cosh[c + d*x])^4) + (3*Sinh[c + d*x])/(35*d*(1 + Cosh[c + d*x])^3) + (2*Sinh[c + d*x])/(35*d*(1 + Cosh[c + d*x])^2) + (2*Sinh[c + d*x])/(35*d*(1 + Cosh[c + d*x]))}

{1/(1 - Cosh[c + d*x]), x, 1, -(Sinh[c + d*x]/(d*(1 - Cosh[c + d*x])))}
{1/(1 - Cosh[c + d*x])^2, x, 2, -(Sinh[c + d*x]/(3*d*(1 - Cosh[c + d*x])^2)) - Sinh[c + d*x]/(3*d*(1 - Cosh[c + d*x]))}
{1/(1 - Cosh[c + d*x])^3, x, 3, -(Sinh[c + d*x]/(5*d*(1 - Cosh[c + d*x])^3)) - (2*Sinh[c + d*x])/(15*d*(1 - Cosh[c + d*x])^2) - (2*Sinh[c + d*x])/(15*d*(1 - Cosh[c + d*x]))}
{1/(1 - Cosh[c + d*x])^4, x, 4, -(Sinh[c + d*x]/(7*d*(1 - Cosh[c + d*x])^4)) - (3*Sinh[c + d*x])/(35*d*(1 - Cosh[c + d*x])^3) - (2*Sinh[c + d*x])/(35*d*(1 - Cosh[c + d*x])^2) - (2*Sinh[c + d*x])/(35*d*(1 - Cosh[c + d*x]))}


{1/(3 + 5*Cosh[c + d*x]), x, 1, ArcTan[(1/2)*Tanh[(1/2)*(c + d*x)]]/(2*d)}
{1/(3 + 5*Cosh[c + d*x])^2, x, 3, -((3*ArcTan[(1/2)*Tanh[(1/2)*(c + d*x)]])/(32*d)) + (5*Sinh[c + d*x])/(16*d*(3 + 5*Cosh[c + d*x]))}
{1/(3 + 5*Cosh[c + d*x])^3, x, 4, (43*ArcTan[(1/2)*Tanh[(1/2)*(c + d*x)]])/(1024*d) + (5*Sinh[c + d*x])/(32*d*(3 + 5*Cosh[c + d*x])^2) - (45*Sinh[c + d*x])/(512*d*(3 + 5*Cosh[c + d*x]))}
{1/(3 + 5*Cosh[c + d*x])^4, x, 5, -((279*ArcTan[(1/2)*Tanh[(1/2)*(c + d*x)]])/(16384*d)) + (5*Sinh[c + d*x])/(48*d*(3 + 5*Cosh[c + d*x])^3) - (25*Sinh[c + d*x])/(512*d*(3 + 5*Cosh[c + d*x])^2) + (995*Sinh[c + d*x])/(24576*d*(3 + 5*Cosh[c + d*x]))}

{1/(5 + 3*Cosh[c + d*x]), x, 1, x/4 - ArcTanh[Sinh[c + d*x]/(3 + Cosh[c + d*x])]/(2*d)}
{1/(5 + 3*Cosh[c + d*x])^2, x, 3, (5*x)/64 - (5*ArcTanh[Sinh[c + d*x]/(3 + Cosh[c + d*x])])/(32*d) - (3*Sinh[c + d*x])/(16*d*(5 + 3*Cosh[c + d*x]))}
{1/(5 + 3*Cosh[c + d*x])^3, x, 4, (59*x)/2048 - (59*ArcTanh[Sinh[c + d*x]/(3 + Cosh[c + d*x])])/(1024*d) - (3*Sinh[c + d*x])/(32*d*(5 + 3*Cosh[c + d*x])^2) - (45*Sinh[c + d*x])/(512*d*(5 + 3*Cosh[c + d*x]))}
{1/(5 + 3*Cosh[c + d*x])^4, x, 5, (385*x)/32768 - (385*ArcTanh[Sinh[c + d*x]/(3 + Cosh[c + d*x])])/(16384*d) - Sinh[c + d*x]/(16*d*(5 + 3*Cosh[c + d*x])^3) - (25*Sinh[c + d*x])/(512*d*(5 + 3*Cosh[c + d*x])^2) - (311*Sinh[c + d*x])/(8192*d*(5 + 3*Cosh[c + d*x]))}


(* ::Subsubsection::Closed:: *)
(*n/2*)


{(a + b*Cosh[x])^(5/2), x, 7, -((2*I*(23*a^2 + 9*b^2)*Sqrt[a + b*Cosh[x]]*EllipticE[(I*x)/2, (2*b)/(a + b)])/(15*Sqrt[(a + b*Cosh[x])/(a + b)])) + (16*I*a*(a^2 - b^2)*Sqrt[(a + b*Cosh[x])/(a + b)]*EllipticF[(I*x)/2, (2*b)/(a + b)])/(15*Sqrt[a + b*Cosh[x]]) + (16/15)*a*b*Sqrt[a + b*Cosh[x]]*Sinh[x] + (2/5)*b*(a + b*Cosh[x])^(3/2)*Sinh[x]}
{(a + b*Cosh[x])^(3/2), x, 6, -((8*I*a*Sqrt[a + b*Cosh[x]]*EllipticE[(I*x)/2, (2*b)/(a + b)])/(3*Sqrt[(a + b*Cosh[x])/(a + b)])) + (2*I*(a^2 - b^2)*Sqrt[(a + b*Cosh[x])/(a + b)]*EllipticF[(I*x)/2, (2*b)/(a + b)])/(3*Sqrt[a + b*Cosh[x]]) + (2/3)*b*Sqrt[a + b*Cosh[x]]*Sinh[x]}
{(a + b*Cosh[c + d*x])^(1/2), x, 2, -((2*I*Sqrt[a + b*Cosh[c + d*x]]*EllipticE[(1/2)*I*(c + d*x), (2*b)/(a + b)])/(d*Sqrt[(a + b*Cosh[c + d*x])/(a + b)]))}
{1/(a + b*Cosh[x])^(1/2), x, 2, -((2*I*Sqrt[(a + b*Cosh[x])/(a + b)]*EllipticF[(I*x)/2, (2*b)/(a + b)])/Sqrt[a + b*Cosh[x]])}
{1/(a + b*Cosh[x])^(3/2), x, 4, -((2*I*Sqrt[a + b*Cosh[x]]*EllipticE[(I*x)/2, (2*b)/(a + b)])/((a^2 - b^2)*Sqrt[(a + b*Cosh[x])/(a + b)])) - (2*b*Sinh[x])/((a^2 - b^2)*Sqrt[a + b*Cosh[x]])}
{1/(a + b*Cosh[x])^(5/2), x, 7, -((8*I*a*Sqrt[a + b*Cosh[x]]*EllipticE[(I*x)/2, (2*b)/(a + b)])/(3*(a^2 - b^2)^2*Sqrt[(a + b*Cosh[x])/(a + b)])) + (2*I*Sqrt[(a + b*Cosh[x])/(a + b)]*EllipticF[(I*x)/2, (2*b)/(a + b)])/(3*(a^2 - b^2)*Sqrt[a + b*Cosh[x]]) - (2*b*Sinh[x])/(3*(a^2 - b^2)*(a + b*Cosh[x])^(3/2)) - (8*a*b*Sinh[x])/(3*(a^2 - b^2)^2*Sqrt[a + b*Cosh[x]])}
{1/(a + b*Cosh[x])^(7/2), x, 8, -((2*I*(23*a^2 + 9*b^2)*Sqrt[a + b*Cosh[x]]*EllipticE[(I*x)/2, (2*b)/(a + b)])/(15*(a^2 - b^2)^3*Sqrt[(a + b*Cosh[x])/(a + b)])) + (16*I*a*Sqrt[(a + b*Cosh[x])/(a + b)]*EllipticF[(I*x)/2, (2*b)/(a + b)])/(15*(a^2 - b^2)^2*Sqrt[a + b*Cosh[x]]) - (2*b*Sinh[x])/(5*(a^2 - b^2)*(a + b*Cosh[x])^(5/2)) - (16*a*b*Sinh[x])/(15*(a^2 - b^2)^2*(a + b*Cosh[x])^(3/2)) - (2*b*(23*a^2 + 9*b^2)*Sinh[x])/(15*(a^2 - b^2)^3*Sqrt[a + b*Cosh[x]])}


{(a + a*Cosh[c + d*x])^(5/2), x, 3, (64*a^3*Sinh[c + d*x])/(15*d*Sqrt[a + a*Cosh[c + d*x]]) + (16*a^2*Sqrt[a + a*Cosh[c + d*x]]*Sinh[c + d*x])/(15*d) + (2*a*(a + a*Cosh[c + d*x])^(3/2)*Sinh[c + d*x])/(5*d)}
{(a + a*Cosh[c + d*x])^(3/2), x, 2, (8*a^2*Sinh[c + d*x])/(3*d*Sqrt[a + a*Cosh[c + d*x]]) + (2*a*Sqrt[a + a*Cosh[c + d*x]]*Sinh[c + d*x])/(3*d)}
{(a + a*Cosh[c + d*x])^(1/2), x, 1, (2*a*Sinh[c + d*x])/(d*Sqrt[a + a*Cosh[c + d*x]])}
{1/(a + a*Cosh[c + d*x])^(1/2), x, 1, (2*ArcTan[Sinh[(1/2)*(c + d*x)]]*Cosh[(1/2)*(c + d*x)])/(d*Sqrt[a + a*Cosh[c + d*x]])}
{1/(a + a*Cosh[c + d*x])^(3/2), x, 2, (ArcTan[Sinh[(1/2)*(c + d*x)]]*Cosh[(1/2)*(c + d*x)])/(2*a*d*Sqrt[a + a*Cosh[c + d*x]]) + Sinh[c + d*x]/(2*d*(a + a*Cosh[c + d*x])^(3/2))}
{1/(a + a*Cosh[c + d*x])^(5/2), x, 3, (3*ArcTan[Sinh[(1/2)*(c + d*x)]]*Cosh[(1/2)*(c + d*x)])/(16*a^2*d*Sqrt[a + a*Cosh[c + d*x]]) + Sinh[c + d*x]/(4*d*(a + a*Cosh[c + d*x])^(5/2)) + (3*Sinh[c + d*x])/(16*a*d*(a + a*Cosh[c + d*x])^(3/2))}


{(a - a*Cosh[c + d*x])^(5/2), x, 3, -((64*a^3*Sinh[c + d*x])/(15*d*Sqrt[a - a*Cosh[c + d*x]])) - (16*a^2*Sqrt[a - a*Cosh[c + d*x]]*Sinh[c + d*x])/(15*d) - (2*a*(a - a*Cosh[c + d*x])^(3/2)*Sinh[c + d*x])/(5*d)}
{(a - a*Cosh[c + d*x])^(3/2), x, 2, -((8*a^2*Sinh[c + d*x])/(3*d*Sqrt[a - a*Cosh[c + d*x]])) - (2*a*Sqrt[a - a*Cosh[c + d*x]]*Sinh[c + d*x])/(3*d)}
{(a - a*Cosh[c + d*x])^(1/2), x, 1, -((2*a*Sinh[c + d*x])/(d*Sqrt[a - a*Cosh[c + d*x]]))}
{1/(a - a*Cosh[c + d*x])^(1/2), x, 1, -((2*ArcTanh[Cosh[(1/2)*(c + d*x)]]*Sinh[(1/2)*(c + d*x)])/(d*Sqrt[a - a*Cosh[c + d*x]]))}
{1/(a - a*Cosh[c + d*x])^(3/2), x, 2, -((ArcTanh[Cosh[(1/2)*(c + d*x)]]*Sinh[(1/2)*(c + d*x)])/(2*a*d*Sqrt[a - a*Cosh[c + d*x]])) - Sinh[c + d*x]/(2*d*(a - a*Cosh[c + d*x])^(3/2))}
{1/(a - a*Cosh[c + d*x])^(5/2), x, 3, -((3*ArcTanh[Cosh[(1/2)*(c + d*x)]]*Sinh[(1/2)*(c + d*x)])/(16*a^2*d*Sqrt[a - a*Cosh[c + d*x]])) - Sinh[c + d*x]/(4*d*(a - a*Cosh[c + d*x])^(5/2)) - (3*Sinh[c + d*x])/(16*a*d*(a - a*Cosh[c + d*x])^(3/2))}


{Cosh[x]/Sqrt[a + a*Cosh[x]], x, 3, -((2*ArcTan[Sinh[x/2]]*Cosh[x/2])/Sqrt[a + a*Cosh[x]]) + (2*Sinh[x])/Sqrt[a + a*Cosh[x]]}
{Cosh[x]/Sqrt[a - a*Cosh[x]], x, 3, -((2*ArcTanh[Cosh[x/2]]*Sinh[x/2])/Sqrt[a - a*Cosh[x]]) + (2*Sinh[x])/Sqrt[a - a*Cosh[x]]}
{Cosh[x]/Sqrt[a + b*Cosh[x]], x, 5, -((2*I*Sqrt[a + b*Cosh[x]]*EllipticE[(I*x)/2, (2*b)/(a + b)])/(b*Sqrt[(a + b*Cosh[x])/(a + b)])) + (2*I*a*Sqrt[(a + b*Cosh[x])/(a + b)]*EllipticF[(I*x)/2, (2*b)/(a + b)])/(b*Sqrt[a + b*Cosh[x]])}


(* ::Subsection::Closed:: *)
(*Integrands of the form Tanh[c+d x]^m (a+b Cosh[c+d x])^n*)


{Tanh[x]^4/(a + b*Cosh[x]), x, 6, (b*ArcTan[Sinh[x]])/(2*a^2) + (b*(a^2 - b^2)*ArcTan[Sinh[x]])/a^4 + (2*(a^2 - b^2)^(3/2)*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[x/2])/(a + b)])/a^4 - ((a^2 - b^2)*Tanh[x])/a^3 - (b*Sech[x]*Tanh[x])/(2*a^2) - Tanh[x]^3/(3*a)}
{Tanh[x]^3/(a + b*Cosh[x]), x, 3, ((a^2 - b^2)*Log[Cosh[x]])/a^3 - ((a^2 - b^2)*Log[a + b*Cosh[x]])/a^3 - (b*Sech[x])/a^2 + Sech[x]^2/(2*a)}
{Tanh[x]^2/(a + b*Cosh[x]), x, 3, (b*ArcTan[Sinh[x]])/a^2 + (2*Sqrt[a^2 - b^2]*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[x/2])/(a + b)])/a^2 - Tanh[x]/a}
{Tanh[x]^1/(a + b*Cosh[x]), x, 3, Log[Cosh[x]]/a - Log[a + b*Cosh[x]]/a}
{Coth[x]^1/(a + b*Cosh[x]), x, 6, Log[1 - Cosh[x]]/(2*(a + b)) + Log[1 + Cosh[x]]/(2*(a - b)) - (a*Log[a + b*Cosh[x]])/(a^2 - b^2)}
{Coth[x]^2/(a + b*Cosh[x]), x, 3, (2*a^2*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[x/2])/(a + b)])/(a^2 - b^2)^(3/2) - (a*Coth[x])/(a^2 - b^2) + (b*Csch[x])/(a^2 - b^2)}
{Coth[x]^3/(a + b*Cosh[x]), x, 3, 1/(4*(a + b)*(1 - Cosh[x])) + 1/(4*(a - b)*(1 + Cosh[x])) + ((2*a + b)*Log[1 - Cosh[x]])/(4*(a + b)^2) + ((2*a - b)*Log[1 + Cosh[x]])/(4*(a - b)^2) - (a^3*Log[a + b*Cosh[x]])/(a^2 - b^2)^2}
{Coth[x]^4/(a + b*Cosh[x]), x, 6, (2*a^4*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[x/2])/(a + b)])/(a^2 - b^2)^(5/2) - (a^3*Coth[x])/(a^2 - b^2)^2 - (a*Coth[x]^3)/(3*(a^2 - b^2)) + (a^2*b*Csch[x])/(a^2 - b^2)^2 + (b*Csch[x])/(a^2 - b^2) + (b*Csch[x]^3)/(3*(a^2 - b^2))}


{Tanh[x]^6/(a + a*Cosh[x]), x, 4, (3*ArcTan[Sinh[x]])/(8*a) - (3*Sech[x]*Tanh[x])/(8*a) - (Sech[x]*Tanh[x]^3)/(4*a) - Tanh[x]^5/(5*a)}
{Tanh[x]^5/(a + a*Cosh[x]), x, 4, -(Sech[x]/a) + Sech[x]^2/(2*a) + Sech[x]^3/(3*a) - Sech[x]^4/(4*a)}
{Tanh[x]^4/(a + a*Cosh[x]), x, 3, ArcTan[Sinh[x]]/(2*a) - (Sech[x]*Tanh[x])/(2*a) - Tanh[x]^3/(3*a)}
{Tanh[x]^3/(a + a*Cosh[x]), x, 4, -(Sech[x]/a) + Sech[x]^2/(2*a)}
{Tanh[x]^2/(a + a*Cosh[x]), x, 2, ArcTan[Sinh[x]]/a - Tanh[x]/a}
{Tanh[x]^1/(a + a*Cosh[x]), x, 3, Log[Cosh[x]]/a - Log[1 + Cosh[x]]/a}
{Coth[x]^1/(a + a*Cosh[x]), x, 5, -(ArcTanh[Cosh[x]]/(2*a)) - 1/(2*a*(1 + Cosh[x]))}
{Coth[x]^2/(a + a*Cosh[x]), x, 3, Coth[x]^3/(3*a) - Csch[x]/a - Csch[x]^3/(3*a)}
{Coth[x]^3/(a + a*Cosh[x]), x, 5, -((3*ArcTanh[Cosh[x]])/(8*a)) + 1/(8*a*(1 - Cosh[x])) + 1/(8*a*(1 + Cosh[x])^2) - 1/(2*a*(1 + Cosh[x]))}
{Coth[x]^4/(a + a*Cosh[x]), x, 4, Coth[x]^5/(5*a) - Csch[x]/a - (2*Csch[x]^3)/(3*a) - Csch[x]^5/(5*a)}


{Tanh[x]/Sqrt[a + b*Cosh[x]], x, 2, -((2*ArcTanh[Sqrt[a + b*Cosh[x]]/Sqrt[a]])/Sqrt[a])}
{Tanh[x]*Sqrt[a + b*Cosh[x]], x, 3, -2*Sqrt[a]*ArcTanh[Sqrt[a + b*Cosh[x]]/Sqrt[a]] + 2*Sqrt[a + b*Cosh[x]]}


(* ::Section::Closed:: *)
(*Integrands of the form Hyper[c+d x]^m (a+b Cosh[c+d x]^2)^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sinh[c+d x]^m (a+b Cosh[c+d x]^2)^n*)


{Sinh[x]/(a + b*Cosh[x]^2), x, 2, ArcTan[(Sqrt[b]*Cosh[x])/Sqrt[a]]/(Sqrt[a]*Sqrt[b])}
{Sinh[x]^2/(a + b*Cosh[x]^2), x, 4, x/b + (Sqrt[-a - b]*ArcTan[(Sqrt[-a - b]*Coth[x])/Sqrt[a]])/(Sqrt[a]*b)}
{Sinh[x]^3/(a + b*Cosh[x]^2), x, 3, -(((a + b)*ArcTan[(Sqrt[b]*Cosh[x])/Sqrt[a]])/(Sqrt[a]*b^(3/2))) + Cosh[x]/b}
{Sinh[x]^4/(a + b*Cosh[x]^2), x, 5, -(((2*a + 3*b)*x)/(2*b^2)) + ((-a - b)^(3/2)*ArcTan[(Sqrt[-a - b]*Coth[x])/Sqrt[a]])/(Sqrt[a]*b^2) - Coth[x]/(2*b*(1 - Coth[x]^2))}
{Sinh[x]^5/(a + b*Cosh[x]^2), x, 4, ((a + b)^2*ArcTan[(Sqrt[b]*Cosh[x])/Sqrt[a]])/(Sqrt[a]*b^(5/2)) - ((a + 2*b)*Cosh[x])/b^2 + Cosh[x]^3/(3*b)}
{Sinh[x]^6/(a + b*Cosh[x]^2), x, 6, ((8*a^2 + 20*a*b + 15*b^2)*x)/(8*b^3) + ((-a - b)^(5/2)*ArcTan[(Sqrt[-a - b]*Coth[x])/Sqrt[a]])/(Sqrt[a]*b^3) + Coth[x]/(4*b*(1 - Coth[x]^2)^2) + ((4*a + 7*b)*Coth[x])/(8*b^2*(1 - Coth[x]^2))}
{Sinh[x]^7/(a + b*Cosh[x]^2), x, 4, -(((a + b)^3*ArcTan[(Sqrt[b]*Cosh[x])/Sqrt[a]])/(Sqrt[a]*b^(7/2))) + ((a^2 + 3*a*b + 3*b^2)*Cosh[x])/b^3 - ((a + 3*b)*Cosh[x]^3)/(3*b^2) + Cosh[x]^5/(5*b)}
{Sinh[x]^8/(a + b*Cosh[x]^2), x, 7, -(((16*a^3 + 56*a^2*b + 70*a*b^2 + 35*b^3)*x)/(16*b^4)) + ((-a - b)^(7/2)*ArcTan[(Sqrt[-a - b]*Coth[x])/Sqrt[a]])/(Sqrt[a]*b^4) - Coth[x]/(6*b*(1 - Coth[x]^2)^3) - ((6*a + 11*b)*Coth[x])/(24*b^2*(1 - Coth[x]^2)^2) - ((8*a^2 + 22*a*b + 19*b^2)*Coth[x])/(16*b^3*(1 - Coth[x]^2))}


{Sinh[x]^2/(a - a*Cosh[x]^2), x, 2, -x/a}
{Sinh[x]^3/(a - a*Cosh[x]^2), x, 2, -(Cosh[x]/a)}
{Sinh[x]^4/(a - a*Cosh[x]^2), x, 2, x/(2*a) - (Cosh[x]*Sinh[x])/(2*a)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cosh[c+d x]^m (a+b Cosh[c+d x]^2)^n*)


{Cosh[x]/(a + b*Cosh[x]^2), x, 2, ArcTan[(Sqrt[b]*Sinh[x])/Sqrt[a + b]]/(Sqrt[b]*Sqrt[a + b])}
{Cosh[x]^2/(a + b*Cosh[x]^2), x, 4, x/b - (Sqrt[a]*ArcTanh[(Sqrt[a]*Tanh[x])/Sqrt[a + b]])/(b*Sqrt[a + b])}
{Cosh[x]^3/(a + b*Cosh[x]^2), x, 3, -((a*ArcTan[(Sqrt[b]*Sinh[x])/Sqrt[a + b]])/(b^(3/2)*Sqrt[a + b])) + Sinh[x]/b}
{Cosh[x]^4/(a + b*Cosh[x]^2), x, 5, -(((2*a - b)*x)/(2*b^2)) + (a^(3/2)*ArcTanh[(Sqrt[a]*Tanh[x])/Sqrt[a + b]])/(b^2*Sqrt[a + b]) + Tanh[x]/(2*b*(1 - Tanh[x]^2))}
{Cosh[x]^5/(a + b*Cosh[x]^2), x, 4, (a^2*ArcTan[(Sqrt[b]*Sinh[x])/Sqrt[a + b]])/(b^(5/2)*Sqrt[a + b]) - ((a - b)*Sinh[x])/b^2 + Sinh[x]^3/(3*b)}
{Cosh[x]^6/(a + b*Cosh[x]^2), x, 6, ((8*a^2 - 4*a*b + 3*b^2)*x)/(8*b^3) - (a^(5/2)*ArcTanh[(Sqrt[a]*Tanh[x])/Sqrt[a + b]])/(b^3*Sqrt[a + b]) + Tanh[x]/(4*b*(1 - Tanh[x]^2)^2) - ((4*a - 3*b)*Tanh[x])/(8*b^2*(1 - Tanh[x]^2))}
{Cosh[x]^7/(a + b*Cosh[x]^2), x, 4, -((a^3*ArcTan[(Sqrt[b]*Sinh[x])/Sqrt[a + b]])/(b^(7/2)*Sqrt[a + b])) + ((a^2 - a*b + b^2)*Sinh[x])/b^3 - ((a - 2*b)*Sinh[x]^3)/(3*b^2) + Sinh[x]^5/(5*b)}
{Cosh[x]^8/(a + b*Cosh[x]^2), x, 7, -(((16*a^3 - 8*a^2*b + 6*a*b^2 - 5*b^3)*x)/(16*b^4)) + (a^(7/2)*ArcTanh[(Sqrt[a]*Tanh[x])/Sqrt[a + b]])/(b^4*Sqrt[a + b]) + Tanh[x]/(6*b*(1 - Tanh[x]^2)^3) - ((6*a - 5*b)*Tanh[x])/(24*b^2*(1 - Tanh[x]^2)^2) + ((8*a^2 - 6*a*b + 5*b^2)*Tanh[x])/(16*b^3*(1 - Tanh[x]^2))}


{1/(a + b*Cosh[x]^2), x, 2, ArcTanh[(Sqrt[a]*Tanh[x])/Sqrt[a + b]]/(Sqrt[a]*Sqrt[a + b])}
{1/(a + b*Cosh[x]^2)^2, x, 3, ((2*a + b)*ArcTanh[(Sqrt[a]*Tanh[x])/Sqrt[a + b]])/(2*a^(3/2)*(a + b)^(3/2)) - (b*Tanh[x])/(2*a*(a + b)*(a + b - a*Tanh[x]^2))}
{1/(a + b*Cosh[x]^2)^3, x, 4, ((8*a^2 + 8*a*b + 3*b^2)*ArcTanh[(Sqrt[a]*Tanh[x])/Sqrt[a + b]])/(8*a^(5/2)*(a + b)^(5/2)) - (b*Tanh[x]*(1 - Tanh[x]^2))/(4*a*(a + b)*(a + b - a*Tanh[x]^2)^2) - (3*b*(2*a + b)*Tanh[x])/(8*a^2*(a + b)^2*(a + b - a*Tanh[x]^2))}

{1/(1 + Cosh[x]^2), x, 2, ArcTanh[Tanh[x]/Sqrt[2]]/Sqrt[2]}
{1/(1 + Cosh[x]^2)^2, x, 3, (3*ArcTanh[Tanh[x]/Sqrt[2]])/(4*Sqrt[2]) - Tanh[x]/(4*(2 - Tanh[x]^2))}
{1/(1 + Cosh[x]^2)^3, x, 4, (19*ArcTanh[Tanh[x]/Sqrt[2]])/(32*Sqrt[2]) - (Tanh[x]*(1 - Tanh[x]^2))/(8*(2 - Tanh[x]^2)^2) - (9*Tanh[x])/(32*(2 - Tanh[x]^2))}

{1/(1 - Cosh[x]^2), x, 2, Coth[x]}
{1/(1 - Cosh[x]^2)^2, x, 3, Coth[x] - Coth[x]^3/3}
{1/(1 - Cosh[x]^2)^3, x, 3, Coth[x] - (2*Coth[x]^3)/3 + Coth[x]^5/5}


{Sqrt[1 + Cosh[x]^2], x, 2, (-I)*Sqrt[2]*EllipticE[I*x, 1/2]}
{Sqrt[1 - Cosh[x]^2], x, 3, Coth[x]*Sqrt[-Sinh[x]^2]}
{Sqrt[-1 + Cosh[x]^2], x, 3, Coth[x]*Sqrt[Sinh[x]^2]}
{Sqrt[-1 - Cosh[x]^2], x, 3, -((I*Sqrt[2]*Sqrt[-3 - Cosh[2*x]]*EllipticE[I*x, 1/2])/Sqrt[3 + Cosh[2*x]])}
{Sqrt[a + b*Cosh[x]^2], x, 3, -((I*Sqrt[2*a + b + b*Cosh[2*x]]*EllipticE[I*x, b/(a + b)])/Sqrt[(2*a + b + b*Cosh[2*x])/(a + b)])}

{1/Sqrt[1 + Cosh[x]^2], x, 2, -((I*EllipticF[I*x, 1/2])/Sqrt[2])}
{1/Sqrt[1 - Cosh[x]^2], x, 3, -((ArcTanh[Cosh[x]]*Sinh[x])/Sqrt[-Sinh[x]^2])}
{1/Sqrt[-1 + Cosh[x]^2], x, 3, -((ArcTanh[Cosh[x]]*Sinh[x])/Sqrt[Sinh[x]^2])}
{1/Sqrt[-1 - Cosh[x]^2], x, 3, -((I*Sqrt[3 + Cosh[2*x]]*EllipticF[I*x, 1/2])/(Sqrt[2]*Sqrt[-3 - Cosh[2*x]]))}
{1/Sqrt[a + b*Cosh[x]^2], x, 3, -((I*Sqrt[(2*a + b + b*Cosh[2*x])/(a + b)]*EllipticF[I*x, b/(a + b)])/Sqrt[2*a + b + b*Cosh[2*x]])}

{(1 - Cosh[x]^2)^(3/2), x, 4, (2/3)*Coth[x]*Sqrt[-Sinh[x]^2] + (1/3)*Coth[x]*(-Sinh[x]^2)^(3/2)}
{(-1 + Cosh[x]^2)^(3/2), x, 4, (-(2/3))*Coth[x]*Sqrt[Sinh[x]^2] + (1/3)*Coth[x]*(Sinh[x]^2)^(3/2)}
(* {(1 + Cosh[x]^2)^(3/2), x, 0, 0} *)
(* {(-1 - Cosh[x]^2)^(3/2), x, 0, 0} *)
(* {(a + b*Cosh[x]^2)^(3/2), x, 0, 0} *)


(* ::Subsection::Closed:: *)
(*Integrands of the form Tanh[c+d x]^m (a+b Cosh[c+d x]^2)^n*)


{Tanh[x]/(1 + Cosh[x]^2), x, 2, -ArcTanh[1 + 2*Cosh[x]^2]}


{Tanh[x]/Sqrt[a + b*Cosh[x]^2], x, 3, -(ArcTanh[Sqrt[a + b*Cosh[x]^2]/Sqrt[a]]/Sqrt[a])}
{Tanh[x]/Sqrt[1 + Cosh[x]^2], x, 3, -ArcTanh[Sqrt[1 + Cosh[x]^2]]}
{Tanh[x]/Sqrt[1 - Cosh[x]^2], x, 2, (ArcTan[Sinh[x]]*Sinh[x])/Sqrt[-Sinh[x]^2]}


{Tanh[x]*Sqrt[a + b*Cosh[x]^2], x, 4, (-Sqrt[a])*ArcTanh[Sqrt[a + b*Cosh[x]^2]/Sqrt[a]] + Sqrt[a + b*Cosh[x]^2]}


(* ::Section::Closed:: *)
(*Integrands of the form Hyper[c+d x]^m (a+b Cosh[c+d x]^3)^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sinh[c+d x]^m (a+b Cosh[c+d x]^3)^n*)


{Sinh[x]/(4 - 3*Cosh[x]^3), x, 6, ArcTan[(1 + 6^(1/3)*Cosh[x])/Sqrt[3]]/(2*2^(1/3)*3^(5/6)) - Log[2^(2/3) - 3^(1/3)*Cosh[x]]/(6*6^(1/3)) + Log[2*2^(1/3) + 2^(2/3)*3^(1/3)*Cosh[x] + 3^(2/3)*Cosh[x]^2]/(12*6^(1/3))}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cosh[c+d x]^m (a+b Cosh[c+d x]^3)^n*)


{1/(a + b*Cosh[x]^3), x, 7, (2*ArcTanh[(Sqrt[a^(2/3) - b^(2/3)]*Tanh[x/2])/(a^(1/3) + b^(1/3))])/(3*a^(2/3)*Sqrt[a^(2/3) - b^(2/3)]) + (2*ArcTanh[(Sqrt[a^(2/3) + (-1)^(1/3)*b^(2/3)]*Tanh[x/2])/(a^(1/3) + (-1)^(2/3)*b^(1/3))])/(3*a^(2/3)*Sqrt[a^(2/3) + (-1)^(1/3)*b^(2/3)]) + (2*ArcTanh[(Sqrt[a^(2/3) - (-1)^(2/3)*b^(2/3)]*Tanh[x/2])/(a^(1/3) - (-1)^(1/3)*b^(1/3))])/(3*a^(2/3)*Sqrt[a^(2/3) - (-1)^(2/3)*b^(2/3)])}
{1/(a - b*Cosh[x]^3), x, 7, (2*ArcTanh[(Sqrt[a^(2/3) - b^(2/3)]*Tanh[x/2])/(a^(1/3) - b^(1/3))])/(3*a^(2/3)*Sqrt[a^(2/3) - b^(2/3)]) + (2*ArcTanh[(Sqrt[a^(2/3) + (-1)^(1/3)*b^(2/3)]*Tanh[x/2])/(a^(1/3) - (-1)^(2/3)*b^(1/3))])/(3*a^(2/3)*Sqrt[a^(2/3) + (-1)^(1/3)*b^(2/3)]) + (2*ArcTanh[(Sqrt[a^(2/3) - (-1)^(2/3)*b^(2/3)]*Tanh[x/2])/(a^(1/3) + (-1)^(1/3)*b^(1/3))])/(3*a^(2/3)*Sqrt[a^(2/3) - (-1)^(2/3)*b^(2/3)])}
{1/(1 + Cosh[x]^3), x, 4, (2*ArcTanh[(Sqrt[1 - (-1)^(2/3)]*Tanh[x/2])/(1 - (-1)^(1/3))])/(3*Sqrt[1 - (-1)^(2/3)]) + (2*ArcTanh[(Sqrt[1 + (-1)^(1/3)]*Tanh[x/2])/(1 + (-1)^(2/3))])/(3*Sqrt[1 + (-1)^(1/3)]) + Sinh[x]/(3*(1 + Cosh[x]))}
{1/(1 - Cosh[x]^3), x, 4, (2*ArcTanh[(Sqrt[1 + (-1)^(1/3)]*Tanh[x/2])/(1 - (-1)^(2/3))])/(3*Sqrt[1 + (-1)^(1/3)]) + (2*ArcTanh[(Sqrt[1 - (-1)^(2/3)]*Tanh[x/2])/(1 + (-1)^(1/3))])/(3*Sqrt[1 - (-1)^(2/3)]) - Sinh[x]/(3*(1 - Cosh[x]))}


(* ::Subsection::Closed:: *)
(*Integrands of the form Tanh[c+d x]^m (a+b Cosh[c+d x]^3)^n*)


{Tanh[x]^3/(a + b*Cosh[x]^3), x, 10, -((b^(2/3)*ArcTan[(a^(1/3) - 2*b^(1/3)*Cosh[x])/(Sqrt[3]*a^(1/3))])/(Sqrt[3]*a^(5/3))) + Log[Cosh[x]]/a + (b^(2/3)*Log[a^(1/3) + b^(1/3)*Cosh[x]])/(3*a^(5/3)) - (b^(2/3)*Log[a^(2/3) - a^(1/3)*b^(1/3)*Cosh[x] + b^(2/3)*Cosh[x]^2])/(6*a^(5/3)) - Log[a + b*Cosh[x]^3]/(3*a) + Sech[x]^2/(2*a)}


{Tanh[x]/Sqrt[a + b*Cosh[x]^3], x, 3, -((2*ArcTanh[Sqrt[a + b*Cosh[x]^3]/Sqrt[a]])/(3*Sqrt[a]))}
{Tanh[x]*Sqrt[a + b*Cosh[x]^3], x, 4, (-(2/3))*Sqrt[a]*ArcTanh[Sqrt[a + b*Cosh[x]^3]/Sqrt[a]] + (2/3)*Sqrt[a + b*Cosh[x]^3]}


(* ::Section::Closed:: *)
(*Integrands of the form Hyper[c+d x]^m (a+b Cosh[c+d x]^n)^p*)


(* ::Subsection:: *)
(*Integrands of the form Sinh[c+d x] (a+b Cosh[c+d x]^n)^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Cosh[c+d x] (a+b Cosh[c+d x]^n)^p*)


{1/(a + b*Cosh[x]^4), x, 5, ArcTanh[Tanh[x]/Sqrt[1 + Sqrt[b]/Sqrt[-a]]]/(2*a*Sqrt[1 + Sqrt[b]/Sqrt[-a]]) + ArcTanh[Tanh[x]/Sqrt[1 + (a*Sqrt[b])/(-a)^(3/2)]]/(2*a*Sqrt[1 + (a*Sqrt[b])/(-a)^(3/2)])}
{1/(a + b*Cosh[x]^5), x, 11, (2*ArcTanh[(Sqrt[a^(2/5) - b^(2/5)]*Tanh[x/2])/(a^(1/5) + b^(1/5))])/(5*a^(4/5)*Sqrt[a^(2/5) - b^(2/5)]) + (2*ArcTanh[(Sqrt[a^(2/5) + (-1)^(1/5)*b^(2/5)]*Tanh[x/2])/(a^(1/5) - (-1)^(3/5)*b^(1/5))])/(5*a^(4/5)*Sqrt[a^(2/5) + (-1)^(1/5)*b^(2/5)]) + (2*ArcTanh[(Sqrt[a^(2/5) - (-1)^(2/5)*b^(2/5)]*Tanh[x/2])/(a^(1/5) - (-1)^(1/5)*b^(1/5))])/(5*a^(4/5)*Sqrt[a^(2/5) - (-1)^(2/5)*b^(2/5)]) + (2*ArcTanh[(Sqrt[a^(2/5) + (-1)^(3/5)*b^(2/5)]*Tanh[x/2])/(a^(1/5) + (-1)^(4/5)*b^(1/5))])/(5*a^(4/5)*Sqrt[a^(2/5) + (-1)^(3/5)*b^(2/5)]) + (2*ArcTanh[(Sqrt[a^(2/5) - (-1)^(4/5)*b^(2/5)]*Tanh[x/2])/(a^(1/5) + (-1)^(2/5)*b^(1/5))])/(5*a^(4/5)*Sqrt[a^(2/5) - (-1)^(4/5)*b^(2/5)])}
{1/(a + b*Cosh[x]^6), x, 7, ArcTanh[Tanh[x]/Sqrt[1 + b^(1/3)/a^(1/3)]]/(3*a*Sqrt[1 + b^(1/3)/a^(1/3)]) + ArcTanh[Tanh[x]/Sqrt[1 - ((-1)^(1/3)*b^(1/3))/a^(1/3)]]/(3*a*Sqrt[1 - ((-1)^(1/3)*b^(1/3))/a^(1/3)]) + ArcTanh[Tanh[x]/Sqrt[1 + ((-1)^(2/3)*b^(1/3))/a^(1/3)]]/(3*a*Sqrt[1 + ((-1)^(2/3)*b^(1/3))/a^(1/3)])}
{1/(a + b*Cosh[x]^8), x, 9, ArcTanh[Tanh[x]/Sqrt[1 - (I*b^(1/4))/(-a)^(1/4)]]/(4*a*Sqrt[1 - (I*b^(1/4))/(-a)^(1/4)]) + ArcTanh[Tanh[x]/Sqrt[1 + (I*b^(1/4))/(-a)^(1/4)]]/(4*a*Sqrt[1 + (I*b^(1/4))/(-a)^(1/4)]) + ArcTanh[Tanh[x]/Sqrt[1 + b^(1/4)/(-a)^(1/4)]]/(4*a*Sqrt[1 + b^(1/4)/(-a)^(1/4)]) + ArcTanh[Tanh[x]/Sqrt[1 + (a*b^(1/4))/(-a)^(5/4)]]/(4*a*Sqrt[1 + (a*b^(1/4))/(-a)^(5/4)])}

{1/(a - b*Cosh[x]^4), x, 5, ArcTanh[Tanh[x]/Sqrt[1 - Sqrt[b]/Sqrt[a]]]/(2*a*Sqrt[1 - Sqrt[b]/Sqrt[a]]) + ArcTanh[Tanh[x]/Sqrt[1 + Sqrt[b]/Sqrt[a]]]/(2*a*Sqrt[1 + Sqrt[b]/Sqrt[a]])}
{1/(a - b*Cosh[x]^5), x, 11, (2*ArcTanh[(Sqrt[a^(2/5) - b^(2/5)]*Tanh[x/2])/(a^(1/5) - b^(1/5))])/(5*a^(4/5)*Sqrt[a^(2/5) - b^(2/5)]) + (2*ArcTanh[(Sqrt[a^(2/5) + (-1)^(1/5)*b^(2/5)]*Tanh[x/2])/(a^(1/5) + (-1)^(3/5)*b^(1/5))])/(5*a^(4/5)*Sqrt[a^(2/5) + (-1)^(1/5)*b^(2/5)]) + (2*ArcTanh[(Sqrt[a^(2/5) - (-1)^(2/5)*b^(2/5)]*Tanh[x/2])/(a^(1/5) + (-1)^(1/5)*b^(1/5))])/(5*a^(4/5)*Sqrt[a^(2/5) - (-1)^(2/5)*b^(2/5)]) + (2*ArcTanh[(Sqrt[a^(2/5) + (-1)^(3/5)*b^(2/5)]*Tanh[x/2])/(a^(1/5) - (-1)^(4/5)*b^(1/5))])/(5*a^(4/5)*Sqrt[a^(2/5) + (-1)^(3/5)*b^(2/5)]) + (2*ArcTanh[(Sqrt[a^(2/5) - (-1)^(4/5)*b^(2/5)]*Tanh[x/2])/(a^(1/5) - (-1)^(2/5)*b^(1/5))])/(5*a^(4/5)*Sqrt[a^(2/5) - (-1)^(4/5)*b^(2/5)])}
{1/(a - b*Cosh[x]^6), x, 7, ArcTanh[Tanh[x]/Sqrt[1 - b^(1/3)/a^(1/3)]]/(3*a*Sqrt[1 - b^(1/3)/a^(1/3)]) + ArcTanh[Tanh[x]/Sqrt[1 + ((-1)^(1/3)*b^(1/3))/a^(1/3)]]/(3*a*Sqrt[1 + ((-1)^(1/3)*b^(1/3))/a^(1/3)]) + ArcTanh[Tanh[x]/Sqrt[1 - ((-1)^(2/3)*b^(1/3))/a^(1/3)]]/(3*a*Sqrt[1 - ((-1)^(2/3)*b^(1/3))/a^(1/3)])}
{1/(a - b*Cosh[x]^8), x, 9, ArcTanh[Tanh[x]/Sqrt[1 - b^(1/4)/a^(1/4)]]/(4*a*Sqrt[1 - b^(1/4)/a^(1/4)]) + ArcTanh[Tanh[x]/Sqrt[1 - (I*b^(1/4))/a^(1/4)]]/(4*a*Sqrt[1 - (I*b^(1/4))/a^(1/4)]) + ArcTanh[Tanh[x]/Sqrt[1 + (I*b^(1/4))/a^(1/4)]]/(4*a*Sqrt[1 + (I*b^(1/4))/a^(1/4)]) + ArcTanh[Tanh[x]/Sqrt[1 + b^(1/4)/a^(1/4)]]/(4*a*Sqrt[1 + b^(1/4)/a^(1/4)])}

{1/(1 + Cosh[x]^4), x, 5, ArcTanh[Tanh[x]/Sqrt[1 - I]]/(2*Sqrt[1 - I]) + ArcTanh[Tanh[x]/Sqrt[1 + I]]/(2*Sqrt[1 + I])}
{1/(1 + Cosh[x]^5), x, 6, (2*ArcTanh[(Sqrt[1 - (-1)^(2/5)]*Tanh[x/2])/(1 - (-1)^(1/5))])/(5*Sqrt[1 - (-1)^(2/5)]) + (2*ArcTanh[(Sqrt[1 + (-1)^(1/5)]*Tanh[x/2])/(1 - (-1)^(3/5))])/(5*Sqrt[1 + (-1)^(1/5)]) + (2*ArcTanh[(Sqrt[1 - (-1)^(4/5)]*Tanh[x/2])/(1 + (-1)^(2/5))])/(5*Sqrt[1 - (-1)^(4/5)]) + (2*ArcTanh[(Sqrt[1 + (-1)^(3/5)]*Tanh[x/2])/(1 + (-1)^(4/5))])/(5*Sqrt[1 + (-1)^(3/5)]) + Sinh[x]/(5*(1 + Cosh[x]))}
{1/(1 + Cosh[x]^6), x, 7, ArcTanh[Tanh[x]/Sqrt[2]]/(3*Sqrt[2]) + ArcTanh[Tanh[x]/Sqrt[1 - (-1)^(1/3)]]/(3*Sqrt[1 - (-1)^(1/3)]) + ArcTanh[Tanh[x]/Sqrt[1 + (-1)^(2/3)]]/(3*Sqrt[1 + (-1)^(2/3)])}
{1/(1 + Cosh[x]^8), x, 9, ArcTanh[Tanh[x]/Sqrt[1 - (-1)^(1/4)]]/(4*Sqrt[1 - (-1)^(1/4)]) + ArcTanh[Tanh[x]/Sqrt[1 + (-1)^(1/4)]]/(4*Sqrt[1 + (-1)^(1/4)]) + ArcTanh[Tanh[x]/Sqrt[1 - (-1)^(3/4)]]/(4*Sqrt[1 - (-1)^(3/4)]) + ArcTanh[Tanh[x]/Sqrt[1 + (-1)^(3/4)]]/(4*Sqrt[1 + (-1)^(3/4)])}

{1/(1 - Cosh[x]^4), x, 5, ArcTanh[Tanh[x]/Sqrt[2]]/(2*Sqrt[2]) + Coth[x]/2}
{1/(1 - Cosh[x]^5), x, 6, (2*ArcTanh[(Sqrt[1 - (-1)^(2/5)]*Tanh[x/2])/(1 + (-1)^(1/5))])/(5*Sqrt[1 - (-1)^(2/5)]) + (2*ArcTanh[(Sqrt[1 + (-1)^(1/5)]*Tanh[x/2])/(1 + (-1)^(3/5))])/(5*Sqrt[1 + (-1)^(1/5)]) + (2*ArcTanh[(Sqrt[1 + (-1)^(3/5)]*Tanh[x/2])/(1 - (-1)^(4/5))])/(5*Sqrt[1 + (-1)^(3/5)]) + (2*ArcTanh[(Sqrt[1 - (-1)^(4/5)]*Tanh[x/2])/(1 - (-1)^(2/5))])/(5*Sqrt[1 - (-1)^(4/5)]) - Sinh[x]/(5*(1 - Cosh[x]))}
{1/(1 - Cosh[x]^6), x, 7, ArcTanh[Tanh[x]/Sqrt[1 + (-1)^(1/3)]]/(3*Sqrt[1 + (-1)^(1/3)]) + ArcTanh[Tanh[x]/Sqrt[1 - (-1)^(2/3)]]/(3*Sqrt[1 - (-1)^(2/3)]) + Coth[x]/3}
{1/(1 - Cosh[x]^8), x, 9, ArcTanh[Tanh[x]/Sqrt[1 - I]]/(4*Sqrt[1 - I]) + ArcTanh[Tanh[x]/Sqrt[1 + I]]/(4*Sqrt[1 + I]) + ArcTanh[Tanh[x]/Sqrt[2]]/(4*Sqrt[2]) + Coth[x]/4}


(* ::Subsection::Closed:: *)
(*Integrands of the form Tanh[c+d x] (a+b Cosh[c+d x]^n)^p*)


{Tanh[x]/Sqrt[a + b*Cosh[x]^n], x, 3, -((2*ArcTanh[Sqrt[a + b*Cosh[x]^n]/Sqrt[a]])/(Sqrt[a]*n))}


{Tanh[x]*Sqrt[a + b*Cosh[x]^n], x, 4, -((2*Sqrt[a]*ArcTanh[Sqrt[a + b*Cosh[x]^n]/Sqrt[a]])/n) + (2*Sqrt[a + b*Cosh[x]^n])/n}


(* ::Section::Closed:: *)
(*Integrands of the form (A+B Hyper[c+d x]) (a+b Cosh[c+d x])^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (A+B Cosh[c+d x]) (a+b Cosh[c+d x])^n*)


{(A + B*Cosh[x])/(a + b*Cosh[x]), x, 2, (B*x)/b + (2*(A*b - a*B)*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[x/2])/(a + b)])/(b*Sqrt[a^2 - b^2])}
{(A + B*Cosh[x])/(a + b*Cosh[x])^2, x, 3, (2*(a*A - b*B)*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[x/2])/(a + b)])/(a^2 - b^2)^(3/2) - ((A*b - a*B)*Sinh[x])/((a^2 - b^2)*(a + b*Cosh[x]))}
{(A + B*Cosh[x])/(a + b*Cosh[x])^3, x, 4, ((2*a^2*A + A*b^2 - 3*a*b*B)*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[x/2])/(a + b)])/(a^2 - b^2)^(5/2) - ((A*b - a*B)*Sinh[x])/(2*(a^2 - b^2)*(a + b*Cosh[x])^2) - ((3*a*A*b - a^2*B - 2*b^2*B)*Sinh[x])/(2*(a^2 - b^2)^2*(a + b*Cosh[x]))}
{(A + B*Cosh[x])/(a + b*Cosh[x])^4, x, 5, ((2*a^3*A + 3*a*A*b^2 - 4*a^2*b*B - b^3*B)*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[x/2])/(a + b)])/(a^2 - b^2)^(7/2) - ((A*b - a*B)*Sinh[x])/(3*(a^2 - b^2)*(a + b*Cosh[x])^3) - ((5*a*A*b - 2*a^2*B - 3*b^2*B)*Sinh[x])/(6*(a^2 - b^2)^2*(a + b*Cosh[x])^2) - ((11*a^2*A*b + 4*A*b^3 - 2*a^3*B - 13*a*b^2*B)*Sinh[x])/(6*(a^2 - b^2)^3*(a + b*Cosh[x]))}

{(A + B*Cosh[x])/(1 + Cosh[x]), x, 2, B*x + ((A - B)*Sinh[x])/(1 + Cosh[x])}
{(A + B*Cosh[x])/(1 + Cosh[x])^2, x, 2, ((A - B)*Sinh[x])/(3*(1 + Cosh[x])^2) + ((A + 2*B)*Sinh[x])/(3*(1 + Cosh[x]))}
{(A + B*Cosh[x])/(1 + Cosh[x])^3, x, 3, ((A - B)*Sinh[x])/(5*(1 + Cosh[x])^3) + ((2*A + 3*B)*Sinh[x])/(15*(1 + Cosh[x])^2) + ((2*A + 3*B)*Sinh[x])/(15*(1 + Cosh[x]))}
{(A + B*Cosh[x])/(1 + Cosh[x])^4, x, 4, ((A - B)*Sinh[x])/(7*(1 + Cosh[x])^4) + ((3*A + 4*B)*Sinh[x])/(35*(1 + Cosh[x])^3) + (2*(3*A + 4*B)*Sinh[x])/(105*(1 + Cosh[x])^2) + (2*(3*A + 4*B)*Sinh[x])/(105*(1 + Cosh[x]))}

{(A + B*Cosh[x])/(1 - Cosh[x]), x, 2, (-B)*x - ((A + B)*Sinh[x])/(1 - Cosh[x])}
{(A + B*Cosh[x])/(1 - Cosh[x])^2, x, 2, -(((A + B)*Sinh[x])/(3*(1 - Cosh[x])^2)) - ((A - 2*B)*Sinh[x])/(3*(1 - Cosh[x]))}
{(A + B*Cosh[x])/(1 - Cosh[x])^3, x, 3, -(((A + B)*Sinh[x])/(5*(1 - Cosh[x])^3)) - ((2*A - 3*B)*Sinh[x])/(15*(1 - Cosh[x])^2) - ((2*A - 3*B)*Sinh[x])/(15*(1 - Cosh[x]))}
{(A + B*Cosh[x])/(1 - Cosh[x])^4, x, 4, -(((A + B)*Sinh[x])/(7*(1 - Cosh[x])^4)) - ((3*A - 4*B)*Sinh[x])/(35*(1 - Cosh[x])^3) - (2*(3*A - 4*B)*Sinh[x])/(105*(1 - Cosh[x])^2) - (2*(3*A - 4*B)*Sinh[x])/(105*(1 - Cosh[x]))}

{(b*B/a + B*Cosh[x])/(a + b*Cosh[x]), x, 2, (B*x)/b - (2*Sqrt[a^2 - b^2]*B*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[x/2])/(a + b)])/(a*b)}
{(a*B/b + B*Cosh[x])/(a + b*Cosh[x]), x, 2, (B*x)/b}

{(a + b*Cosh[x])/(b + a*Cosh[x])^2, x, 2, Sinh[x]/(b + a*Cosh[x])}
{(3 + Cosh[x])/(2 - Cosh[x]), x, 2, -x + (5*x)/Sqrt[3] + (10*ArcTanh[Sinh[x]/(2 + Sqrt[3] - Cosh[x])])/Sqrt[3]}


{(A + B*Cosh[x])*(a + b*Cosh[x])^(5/2), x, 8, -((2*I*(161*a^2*A*b + 63*A*b^3 + 15*a^3*B + 145*a*b^2*B)*Sqrt[a + b*Cosh[x]]*EllipticE[(I*x)/2, (2*b)/(a + b)])/(105*b*Sqrt[(a + b*Cosh[x])/(a + b)])) + (2*I*(a^2 - b^2)*(56*a*A*b + 15*a^2*B + 25*b^2*B)*Sqrt[(a + b*Cosh[x])/(a + b)]*EllipticF[(I*x)/2, (2*b)/(a + b)])/(105*b*Sqrt[a + b*Cosh[x]]) + (2/105)*(56*a*A*b + 15*a^2*B + 25*b^2*B)*Sqrt[a + b*Cosh[x]]*Sinh[x] + (2/35)*(7*A*b + 5*a*B)*(a + b*Cosh[x])^(3/2)*Sinh[x] + (2/7)*B*(a + b*Cosh[x])^(5/2)*Sinh[x]}
{(A + B*Cosh[x])*(a + b*Cosh[x])^(3/2), x, 7, -((2*I*(20*a*A*b + 3*a^2*B + 9*b^2*B)*Sqrt[a + b*Cosh[x]]*EllipticE[(I*x)/2, (2*b)/(a + b)])/(15*b*Sqrt[(a + b*Cosh[x])/(a + b)])) + (2*I*(a - b)*(a + b)*(5*A*b + 3*a*B)*Sqrt[(a + b*Cosh[x])/(a + b)]*EllipticF[(I*x)/2, (2*b)/(a + b)])/(15*b*Sqrt[a + b*Cosh[x]]) + (2/15)*(5*A*b + 3*a*B)*Sqrt[a + b*Cosh[x]]*Sinh[x] + (2/5)*B*(a + b*Cosh[x])^(3/2)*Sinh[x]}
{(A + B*Cosh[x])*(a + b*Cosh[x])^(1/2), x, 6, -((2*I*(3*A*b + a*B)*Sqrt[a + b*Cosh[x]]*EllipticE[(I*x)/2, (2*b)/(a + b)])/(3*b*Sqrt[(a + b*Cosh[x])/(a + b)])) + (2*I*(a^2 - b^2)*B*Sqrt[(a + b*Cosh[x])/(a + b)]*EllipticF[(I*x)/2, (2*b)/(a + b)])/(3*b*Sqrt[a + b*Cosh[x]]) + (2/3)*B*Sqrt[a + b*Cosh[x]]*Sinh[x]}
{(A + B*Cosh[x])/(a + b*Cosh[x])^(1/2), x, 5, -((2*I*B*Sqrt[a + b*Cosh[x]]*EllipticE[(I*x)/2, (2*b)/(a + b)])/(b*Sqrt[(a + b*Cosh[x])/(a + b)])) - (2*I*(A*b - a*B)*Sqrt[(a + b*Cosh[x])/(a + b)]*EllipticF[(I*x)/2, (2*b)/(a + b)])/(b*Sqrt[a + b*Cosh[x]])}
{(A + B*Cosh[x])/(a + b*Cosh[x])^(3/2), x, 6, -((2*I*(A*b - a*B)*Sqrt[a + b*Cosh[x]]*EllipticE[(I*x)/2, (2*b)/(a + b)])/(b*(a^2 - b^2)*Sqrt[(a + b*Cosh[x])/(a + b)])) - (2*I*B*Sqrt[(a + b*Cosh[x])/(a + b)]*EllipticF[(I*x)/2, (2*b)/(a + b)])/(b*Sqrt[a + b*Cosh[x]]) - (2*(A*b - a*B)*Sinh[x])/((a^2 - b^2)*Sqrt[a + b*Cosh[x]])}
{(A + B*Cosh[x])/(a + b*Cosh[x])^(5/2), x, 7, -((2*I*(4*a*A*b - a^2*B - 3*b^2*B)*Sqrt[a + b*Cosh[x]]*EllipticE[(I*x)/2, (2*b)/(a + b)])/(3*b*(a^2 - b^2)^2*Sqrt[(a + b*Cosh[x])/(a + b)])) + (2*I*(A*b - a*B)*Sqrt[(a + b*Cosh[x])/(a + b)]*EllipticF[(I*x)/2, (2*b)/(a + b)])/(3*b*(a^2 - b^2)*Sqrt[a + b*Cosh[x]]) - (2*(A*b - a*B)*Sinh[x])/(3*(a^2 - b^2)*(a + b*Cosh[x])^(3/2)) - (2*(4*a*A*b - a^2*B - 3*b^2*B)*Sinh[x])/(3*(a^2 - b^2)^2*Sqrt[a + b*Cosh[x]])}

{(A + B*Cosh[x])*(a + a*Cosh[x])^(5/2), x, 4, (64*a^3*(7*A + 5*B)*Sinh[x])/(105*Sqrt[a + a*Cosh[x]]) + (16/105)*a^2*(7*A + 5*B)*Sqrt[a + a*Cosh[x]]*Sinh[x] + (2/35)*a*(7*A + 5*B)*(a + a*Cosh[x])^(3/2)*Sinh[x] + (2/7)*B*(a + a*Cosh[x])^(5/2)*Sinh[x]}
{(A + B*Cosh[x])*(a + a*Cosh[x])^(3/2), x, 3, (8*a^2*(5*A + 3*B)*Sinh[x])/(15*Sqrt[a + a*Cosh[x]]) + (2/15)*a*(5*A + 3*B)*Sqrt[a + a*Cosh[x]]*Sinh[x] + (2/5)*B*(a + a*Cosh[x])^(3/2)*Sinh[x]}
{(A + B*Cosh[x])*(a + a*Cosh[x])^(1/2), x, 2, (2*a*(3*A + B)*Sinh[x])/(3*Sqrt[a + a*Cosh[x]]) + (2/3)*B*Sqrt[a + a*Cosh[x]]*Sinh[x]}
{(A + B*Cosh[x])/(a + a*Cosh[x])^(1/2), x, 2, (2*(A - B)*ArcTan[Sinh[x/2]]*Cosh[x/2])/Sqrt[a + a*Cosh[x]] + (2*B*Sinh[x])/Sqrt[a + a*Cosh[x]]}
{(A + B*Cosh[x])/(a + a*Cosh[x])^(3/2), x, 2, ((A + 3*B)*ArcTan[Sinh[x/2]]*Cosh[x/2])/(2*a*Sqrt[a + a*Cosh[x]]) + ((A - B)*Sinh[x])/(2*(a + a*Cosh[x])^(3/2))}
{(A + B*Cosh[x])/(a + a*Cosh[x])^(5/2), x, 3, ((3*A + 5*B)*ArcTan[Sinh[x/2]]*Cosh[x/2])/(16*a^2*Sqrt[a + a*Cosh[x]]) + ((A - B)*Sinh[x])/(4*(a + a*Cosh[x])^(5/2)) + ((3*A + 5*B)*Sinh[x])/(16*a*(a + a*Cosh[x])^(3/2))}

{(A + B*Cosh[x])*(a - a*Cosh[x])^(5/2), x, 4, -((64*a^3*(7*A - 5*B)*Sinh[x])/(105*Sqrt[a - a*Cosh[x]])) - (16/105)*a^2*(7*A - 5*B)*Sqrt[a - a*Cosh[x]]*Sinh[x] - (2/35)*a*(7*A - 5*B)*(a - a*Cosh[x])^(3/2)*Sinh[x] + (2/7)*B*(a - a*Cosh[x])^(5/2)*Sinh[x]}
{(A + B*Cosh[x])*(a - a*Cosh[x])^(3/2), x, 3, -((8*a^2*(5*A - 3*B)*Sinh[x])/(15*Sqrt[a - a*Cosh[x]])) - (2/15)*a*(5*A - 3*B)*Sqrt[a - a*Cosh[x]]*Sinh[x] + (2/5)*B*(a - a*Cosh[x])^(3/2)*Sinh[x]}
{(A + B*Cosh[x])*(a - a*Cosh[x])^(1/2), x, 2, -((2*a*(3*A - B)*Sinh[x])/(3*Sqrt[a - a*Cosh[x]])) + (2/3)*B*Sqrt[a - a*Cosh[x]]*Sinh[x]}
{(A + B*Cosh[x])/(a - a*Cosh[x])^(1/2), x, 2, -((2*(A + B)*ArcTanh[Cosh[x/2]]*Sinh[x/2])/Sqrt[a - a*Cosh[x]]) + (2*B*Sinh[x])/Sqrt[a - a*Cosh[x]]}
{(A + B*Cosh[x])/(a - a*Cosh[x])^(3/2), x, 2, -(((A - 3*B)*ArcTanh[Cosh[x/2]]*Sinh[x/2])/(2*a*Sqrt[a - a*Cosh[x]])) - ((A + B)*Sinh[x])/(2*(a - a*Cosh[x])^(3/2))}
{(A + B*Cosh[x])/(a - a*Cosh[x])^(5/2), x, 3, -(((3*A - 5*B)*ArcTanh[Cosh[x/2]]*Sinh[x/2])/(16*a^2*Sqrt[a - a*Cosh[x]])) - ((A + B)*Sinh[x])/(4*(a - a*Cosh[x])^(5/2)) - ((3*A - 5*B)*Sinh[x])/(16*a*(a - a*Cosh[x])^(3/2))}


(* ::Subsection::Closed:: *)
(*Integrands of the form (A+B Sinh[c+d x]) (a+b Cosh[c+d x])^n*)


{(A + B*Sinh[x])/(a + b*Cosh[x]), x, 5, (2*A*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[x/2])/(a + b)])/Sqrt[a^2 - b^2] + (B*Log[a + b*Cosh[x]])/b}

{(A + B*Sinh[x])/(1 + Cosh[x]), x, 5, B*Log[1 + Cosh[x]] + (A*Sinh[x])/(1 + Cosh[x])}
{(A + B*Sinh[x])/(1 - Cosh[x]), x, 5, (-B)*Log[1 - Cosh[x]] - (A*Sinh[x])/(1 - Cosh[x])}


(* ::Subsection::Closed:: *)
(*Integrands of the form (A+B Hyper[c+d x]) (a+b Cosh[c+d x])^n*)


{(A + B*Tanh[x])/(a + b*Cosh[x]), x, 6, (2*A*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[x/2])/(a + b)])/Sqrt[a^2 - b^2] + (B*Log[Cosh[x]])/a - (B*Log[a + b*Cosh[x]])/a}
{(A + B*Coth[x])/(a + b*Cosh[x]), x, 9, (2*A*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[x/2])/(a + b)])/Sqrt[a^2 - b^2] + (B*Log[1 - Cosh[x]])/(2*(a + b)) + (B*Log[1 + Cosh[x]])/(2*(a - b)) - (a*B*Log[a + b*Cosh[x]])/(a^2 - b^2)}
{(A + B*Sech[x])/(a + b*Cosh[x]), x, 4, (B*ArcTan[Sinh[x]])/a + (2*(a*A - b*B)*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[x/2])/(a + b)])/(a*Sqrt[a^2 - b^2])}
{(A + B*Csch[x])/(a + b*Cosh[x]), x, 9, (2*A*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[x/2])/(a + b)])/Sqrt[a^2 - b^2] + (B*Log[1 - Cosh[x]])/(2*(a + b)) - (B*Log[1 + Cosh[x]])/(2*(a - b)) + (b*B*Log[a + b*Cosh[x]])/(a^2 - b^2)}


(* ::Section::Closed:: *)
(*Integrands of the form (c+d x)^m Cosh[a+b x]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (c+d x)^m Cosh[a+b x]^n*)


{Cosh[a + b*x]*Sqrt[c + d*x], x, 6, (Sqrt[d]*E^(-a + (b*c)/d)*Sqrt[Pi]*Erf[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/(4*b^(3/2)) - (Sqrt[d]*E^(a - (b*c)/d)*Sqrt[Pi]*Erfi[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/(4*b^(3/2)) + (Sqrt[c + d*x]*Sinh[a + b*x])/b}
{Cosh[a + b*x]/Sqrt[c + d*x], x, 5, (E^(-a + (b*c)/d)*Sqrt[Pi]*Erf[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/(2*Sqrt[b]*Sqrt[d]) + (E^(a - (b*c)/d)*Sqrt[Pi]*Erfi[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/(2*Sqrt[b]*Sqrt[d])}
{Cosh[a + b*x]/(c + d*x)^(3/2), x, 6, -((2*Cosh[a + b*x])/(d*Sqrt[c + d*x])) - (Sqrt[b]*E^(-a + (b*c)/d)*Sqrt[Pi]*Erf[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/d^(3/2) + (Sqrt[b]*E^(a - (b*c)/d)*Sqrt[Pi]*Erfi[(Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/d^(3/2)}


{Cosh[a + b*x]^2*Sqrt[c + d*x], x, 8, (c + d*x)^(3/2)/(3*d) + (Sqrt[d]*E^(-2*a + (2*b*c)/d)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/(16*b^(3/2)) - (Sqrt[d]*E^(2*a - (2*b*c)/d)*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/(16*b^(3/2)) + (Sqrt[c + d*x]*Sinh[2*a + 2*b*x])/(4*b)}
{Cosh[a + b*x]^2/Sqrt[c + d*x], x, 7, Sqrt[c + d*x]/d + (E^(-2*a + (2*b*c)/d)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/(4*Sqrt[b]*Sqrt[d]) + (E^(2*a - (2*b*c)/d)*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/(4*Sqrt[b]*Sqrt[d])}
{Cosh[a + b*x]^2/(c + d*x)^(3/2), x, 7, -((2*Cosh[a + b*x]^2)/(d*Sqrt[c + d*x])) - (Sqrt[b]*E^(-2*a + (2*b*c)/d)*Sqrt[Pi/2]*Erf[(Sqrt[2]*Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/d^(3/2) + (Sqrt[b]*E^(2*a - (2*b*c)/d)*Sqrt[Pi/2]*Erfi[(Sqrt[2]*Sqrt[b]*Sqrt[c + d*x])/Sqrt[d]])/d^(3/2)}


{x^5*Cosh[a + b*x], x, 6, -((120*Cosh[a + b*x])/b^6) - (60*x^2*Cosh[a + b*x])/b^4 - (5*x^4*Cosh[a + b*x])/b^2 + (120*x*Sinh[a + b*x])/b^5 + (20*x^3*Sinh[a + b*x])/b^3 + (x^5*Sinh[a + b*x])/b}
{x^4*Cosh[a + b*x], x, 5, -((24*x*Cosh[a + b*x])/b^4) - (4*x^3*Cosh[a + b*x])/b^2 + (24*Sinh[a + b*x])/b^5 + (12*x^2*Sinh[a + b*x])/b^3 + (x^4*Sinh[a + b*x])/b}
{x^3*Cosh[a + b*x], x, 4, -((6*Cosh[a + b*x])/b^4) - (3*x^2*Cosh[a + b*x])/b^2 + (6*x*Sinh[a + b*x])/b^3 + (x^3*Sinh[a + b*x])/b}
{x^2*Cosh[a + b*x], x, 3, -((2*x*Cosh[a + b*x])/b^2) + (2*Sinh[a + b*x])/b^3 + (x^2*Sinh[a + b*x])/b}
{x^1*Cosh[a + b*x], x, 2, -(Cosh[a + b*x]/b^2) + (x*Sinh[a + b*x])/b}
{Cosh[a + b*x]/x^1, x, 3, Cosh[a]*CoshIntegral[b*x] + Sinh[a]*SinhIntegral[b*x]}
{Cosh[a + b*x]/x^2, x, 4, -(Cosh[a + b*x]/x) + b*CoshIntegral[b*x]*Sinh[a] + b*Cosh[a]*SinhIntegral[b*x]}
{Cosh[a + b*x]/x^3, x, 5, -(Cosh[a + b*x]/(2*x^2)) + (1/2)*b^2*Cosh[a]*CoshIntegral[b*x] - (b*Sinh[a + b*x])/(2*x) + (1/2)*b^2*Sinh[a]*SinhIntegral[b*x]}
{Cosh[a + b*x]/x^4, x, 6, -(Cosh[a + b*x]/(3*x^3)) - (b^2*Cosh[a + b*x])/(6*x) + (1/6)*b^3*CoshIntegral[b*x]*Sinh[a] - (b*Sinh[a + b*x])/(6*x^2) + (1/6)*b^3*Cosh[a]*SinhIntegral[b*x]}


{x^3*Cosh[a + b*x]^2, x, 4, (3*x^2)/(8*b^2) + x^4/8 - (3*Cosh[a + b*x]^2)/(8*b^4) - (3*x^2*Cosh[a + b*x]^2)/(4*b^2) + (3*x*Cosh[a + b*x]*Sinh[a + b*x])/(4*b^3) + (x^3*Cosh[a + b*x]*Sinh[a + b*x])/(2*b)}
{x^2*Cosh[a + b*x]^2, x, 3, x/(4*b^2) + x^3/6 - (x*Cosh[a + b*x]^2)/(2*b^2) + (Cosh[a + b*x]*Sinh[a + b*x])/(4*b^3) + (x^2*Cosh[a + b*x]*Sinh[a + b*x])/(2*b)}
{x^1*Cosh[a + b*x]^2, x, 2, x^2/4 - Cosh[a + b*x]^2/(4*b^2) + (x*Cosh[a + b*x]*Sinh[a + b*x])/(2*b)}
{Cosh[a + b*x]^2/x^1, x, 5, (Cosh[2*a]*CoshIntegral[2*b*x])/2 + Log[x]/2 + (Sinh[2*a]*SinhIntegral[2*b*x])/2}
{Cosh[a + b*x]^2/x^2, x, 5, -(Cosh[a + b*x]^2/x) + b*CoshIntegral[2*b*x]*Sinh[2*a] + b*Cosh[2*a]*SinhIntegral[2*b*x]}
{Cosh[a + b*x]^2/x^3, x, 7, -(Cosh[a + b*x]^2/(2*x^2)) + b^2*Cosh[2*a]*CoshIntegral[2*b*x] - (b*Cosh[a + b*x]*Sinh[a + b*x])/x + b^2*Sinh[2*a]*SinhIntegral[2*b*x]}


{x^3*Cosh[a + b*x]^3, x, 8, -((40*Cosh[a + b*x])/(9*b^4)) - (2*x^2*Cosh[a + b*x])/b^2 - (2*Cosh[a + b*x]^3)/(27*b^4) - (x^2*Cosh[a + b*x]^3)/(3*b^2) + (40*x*Sinh[a + b*x])/(9*b^3) + (2*x^3*Sinh[a + b*x])/(3*b) + (2*x*Cosh[a + b*x]^2*Sinh[a + b*x])/(9*b^3) + (x^3*Cosh[a + b*x]^2*Sinh[a + b*x])/(3*b)}
{x^2*Cosh[a + b*x]^3, x, 6, -((4*x*Cosh[a + b*x])/(3*b^2)) - (2*x*Cosh[a + b*x]^3)/(9*b^2) + (14*Sinh[a + b*x])/(9*b^3) + (2*x^2*Sinh[a + b*x])/(3*b) + (x^2*Cosh[a + b*x]^2*Sinh[a + b*x])/(3*b) + (2*Sinh[a + b*x]^3)/(27*b^3)}
{x^1*Cosh[a + b*x]^3, x, 3, -((2*Cosh[a + b*x])/(3*b^2)) - Cosh[a + b*x]^3/(9*b^2) + (2*x*Sinh[a + b*x])/(3*b) + (x*Cosh[a + b*x]^2*Sinh[a + b*x])/(3*b)}
{Cosh[a + b*x]^3/x^1, x, 8, (3/4)*Cosh[a]*CoshIntegral[b*x] + (1/4)*Cosh[3*a]*CoshIntegral[3*b*x] + (3/4)*Sinh[a]*SinhIntegral[b*x] + (1/4)*Sinh[3*a]*SinhIntegral[3*b*x]}
{Cosh[a + b*x]^3/x^2, x, 8, -(Cosh[a + b*x]^3/x) + (3/4)*b*CoshIntegral[b*x]*Sinh[a] + (3/4)*b*CoshIntegral[3*b*x]*Sinh[3*a] + (3/4)*b*Cosh[a]*SinhIntegral[b*x] + (3/4)*b*Cosh[3*a]*SinhIntegral[3*b*x]}
{Cosh[a + b*x]^3/x^3, x, 12, -(Cosh[a + b*x]^3/(2*x^2)) + (3/8)*b^2*Cosh[a]*CoshIntegral[b*x] + (9/8)*b^2*Cosh[3*a]*CoshIntegral[3*b*x] - (3*b*Cosh[a + b*x]^2*Sinh[a + b*x])/(2*x) + (3/8)*b^2*Sinh[a]*SinhIntegral[b*x] + (9/8)*b^2*Sinh[3*a]*SinhIntegral[3*b*x]}


{x^3*Cosh[a + b*x]^4, x, 8, (45*x^2)/(128*b^2) + (3*x^4)/32 - (45*Cosh[a + b*x]^2)/(128*b^4) - (9*x^2*Cosh[a + b*x]^2)/(16*b^2) - (3*Cosh[a + b*x]^4)/(128*b^4) - (3*x^2*Cosh[a + b*x]^4)/(16*b^2) + (45*x*Cosh[a + b*x]*Sinh[a + b*x])/(64*b^3) + (3*x^3*Cosh[a + b*x]*Sinh[a + b*x])/(8*b) + (3*x*Cosh[a + b*x]^3*Sinh[a + b*x])/(32*b^3) + (x^3*Cosh[a + b*x]^3*Sinh[a + b*x])/(4*b)}
{x^2*Cosh[a + b*x]^4, x, 6, (15*x)/(64*b^2) + x^3/8 - (3*x*Cosh[a + b*x]^2)/(8*b^2) - (x*Cosh[a + b*x]^4)/(8*b^2) + (15*Cosh[a + b*x]*Sinh[a + b*x])/(64*b^3) + (3*x^2*Cosh[a + b*x]*Sinh[a + b*x])/(8*b) + (Cosh[a + b*x]^3*Sinh[a + b*x])/(32*b^3) + (x^2*Cosh[a + b*x]^3*Sinh[a + b*x])/(4*b)}
{x^1*Cosh[a + b*x]^4, x, 3, (3*x^2)/16 - (3*Cosh[a + b*x]^2)/(16*b^2) - Cosh[a + b*x]^4/(16*b^2) + (3*x*Cosh[a + b*x]*Sinh[a + b*x])/(8*b) + (x*Cosh[a + b*x]^3*Sinh[a + b*x])/(4*b)}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c+d x)^(m/2) Cosh[a+b x]^n*)


{x^(5/2)*Cosh[a + b*x], x, 8, -((5*x^(3/2)*Cosh[a + b*x])/(2*b^2)) + (15*Sqrt[Pi]*Erf[Sqrt[b]*Sqrt[x]])/(E^a*(16*b^(7/2))) - (15*E^a*Sqrt[Pi]*Erfi[Sqrt[b]*Sqrt[x]])/(16*b^(7/2)) + (15*Sqrt[x]*Sinh[a + b*x])/(4*b^3) + (x^(5/2)*Sinh[a + b*x])/b}
{x^(3/2)*Cosh[a + b*x], x, 7, -((3*Sqrt[x]*Cosh[a + b*x])/(2*b^2)) + (3*Sqrt[Pi]*Erf[Sqrt[b]*Sqrt[x]])/(E^a*(8*b^(5/2))) + (3*E^a*Sqrt[Pi]*Erfi[Sqrt[b]*Sqrt[x]])/(8*b^(5/2)) + (x^(3/2)*Sinh[a + b*x])/b}
{x^(1/2)*Cosh[a + b*x], x, 6, (Sqrt[Pi]*Erf[Sqrt[b]*Sqrt[x]])/(E^a*(4*b^(3/2))) - (E^a*Sqrt[Pi]*Erfi[Sqrt[b]*Sqrt[x]])/(4*b^(3/2)) + (Sqrt[x]*Sinh[a + b*x])/b}
{Cosh[a + b*x]/x^(1/2), x, 5, (Sqrt[Pi]*Erf[Sqrt[b]*Sqrt[x]])/(E^a*(2*Sqrt[b])) + (E^a*Sqrt[Pi]*Erfi[Sqrt[b]*Sqrt[x]])/(2*Sqrt[b])}
{Cosh[a + b*x]/x^(3/2), x, 6, -((2*Cosh[a + b*x])/Sqrt[x]) - (Sqrt[b]*Sqrt[Pi]*Erf[Sqrt[b]*Sqrt[x]])/E^a + Sqrt[b]*E^a*Sqrt[Pi]*Erfi[Sqrt[b]*Sqrt[x]]}
{Cosh[a + b*x]/x^(5/2), x, 7, -((2*Cosh[a + b*x])/(3*x^(3/2))) + ((2/3)*b^(3/2)*Sqrt[Pi]*Erf[Sqrt[b]*Sqrt[x]])/E^a + (2/3)*b^(3/2)*E^a*Sqrt[Pi]*Erfi[Sqrt[b]*Sqrt[x]] - (4*b*Sinh[a + b*x])/(3*Sqrt[x])}
{Cosh[a + b*x]/x^(7/2), x, 8, -((2*Cosh[a + b*x])/(5*x^(5/2))) - (8*b^2*Cosh[a + b*x])/(15*Sqrt[x]) - ((4/15)*b^(5/2)*Sqrt[Pi]*Erf[Sqrt[b]*Sqrt[x]])/E^a + (4/15)*b^(5/2)*E^a*Sqrt[Pi]*Erfi[Sqrt[b]*Sqrt[x]] - (4*b*Sinh[a + b*x])/(15*x^(3/2))}


(* ::Subsection::Closed:: *)
(*Integrands of the form (c+d x)^m Cosh[a+b x]^(n/2)*)


{Cosh[x]^(3/2)/x^3, x, 1, -(Cosh[x]^(3/2)/(2*x^2)) - (3/8)*Int[1/(x*Sqrt[Cosh[x]]), x] + (9/8)*Int[Cosh[x]^(3/2)/x, x] - (3*Sqrt[Cosh[x]]*Sinh[x])/(4*x)}


(* ::Subsection:: *)
(*Integrands of the form (c+d x)^(m/2) Cosh[a+b x]^(n/2)*)


(* ::Section::Closed:: *)
(*Integrands of the form (e+f x)^m (a+b Cosh[c+d x]^n)^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (e+f x)^m (a+b Cosh[c+d x])^p*)


(* ::Subsubsection::Closed:: *)
(*p*)


{1/(x*(a + b*Cosh[c + d*x])), x, 0, Int[1/(x*(a + b*Cosh[c + d*x])), x]}
{x/(a + b*Cosh[c + d*x]), x, 8, (x*Log[1 + (b*E^(c + d*x))/(a - Sqrt[a^2 - b^2])])/(Sqrt[a^2 - b^2]*d) - (x*Log[1 + (b*E^(c + d*x))/(a + Sqrt[a^2 - b^2])])/(Sqrt[a^2 - b^2]*d) + PolyLog[2, -((b*E^(c + d*x))/(a - Sqrt[a^2 - b^2]))]/(Sqrt[a^2 - b^2]*d^2) - PolyLog[2, -((b*E^(c + d*x))/(a + Sqrt[a^2 - b^2]))]/(Sqrt[a^2 - b^2]*d^2)}
{x^2/(a + b*Cosh[c + d*x]), x, 10, (x^2*Log[1 + (b*E^(c + d*x))/(a - Sqrt[a^2 - b^2])])/(Sqrt[a^2 - b^2]*d) - (x^2*Log[1 + (b*E^(c + d*x))/(a + Sqrt[a^2 - b^2])])/(Sqrt[a^2 - b^2]*d) + (2*x*PolyLog[2, -((b*E^(c + d*x))/(a - Sqrt[a^2 - b^2]))])/(Sqrt[a^2 - b^2]*d^2) - (2*x*PolyLog[2, -((b*E^(c + d*x))/(a + Sqrt[a^2 - b^2]))])/(Sqrt[a^2 - b^2]*d^2) - (2*PolyLog[3, -((b*E^(c + d*x))/(a - Sqrt[a^2 - b^2]))])/(Sqrt[a^2 - b^2]*d^3) + (2*PolyLog[3, -((b*E^(c + d*x))/(a + Sqrt[a^2 - b^2]))])/(Sqrt[a^2 - b^2]*d^3)}
{x^3/(a + b*Cosh[x]), x, 12, (x^3*Log[1 + (b*E^x)/(a - Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2] - (x^3*Log[1 + (b*E^x)/(a + Sqrt[a^2 - b^2])])/Sqrt[a^2 - b^2] + (3*x^2*PolyLog[2, -((b*E^x)/(a - Sqrt[a^2 - b^2]))])/Sqrt[a^2 - b^2] - (3*x^2*PolyLog[2, -((b*E^x)/(a + Sqrt[a^2 - b^2]))])/Sqrt[a^2 - b^2] - (6*x*PolyLog[3, -((b*E^x)/(a - Sqrt[a^2 - b^2]))])/Sqrt[a^2 - b^2] + (6*x*PolyLog[3, -((b*E^x)/(a + Sqrt[a^2 - b^2]))])/Sqrt[a^2 - b^2] + (6*PolyLog[4, -((b*E^x)/(a - Sqrt[a^2 - b^2]))])/Sqrt[a^2 - b^2] - (6*PolyLog[4, -((b*E^x)/(a + Sqrt[a^2 - b^2]))])/Sqrt[a^2 - b^2]}
(* {x^3/(a + b*Cosh[c + d*x]), x, 12, 0} *)

{1/(x*(1 + Cosh[x])), x, 1, (1/2)*Int[Sech[x/2]^2/x, x]}
{x/(1 + Cosh[x]), x, 3, -2*Log[Cosh[x/2]] + x*Tanh[x/2]}
{x^2/(1 + Cosh[x]), x, 6, x^2 - 4*x*Log[1 + E^x] - 4*PolyLog[2, -E^x] + x^2*Tanh[x/2]}
{x^3/(1 + Cosh[x]), x, 7, x^3 - 6*x^2*Log[1 + E^x] - 12*x*PolyLog[2, -E^x] + 12*PolyLog[3, -E^x] + x^3*Tanh[x/2]}

{1/(x*(1 - Cosh[x])), x, 1, (-(1/2))*Int[Csch[x/2]^2/x, x]}
{x/(1 - Cosh[x]), x, 3, x*Coth[x/2] - 2*Log[Sinh[x/2]]}
{x^2/(1 - Cosh[x]), x, 6, x^2 + x^2*Coth[x/2] - 4*x*Log[1 - E^x] - 4*PolyLog[2, E^x]}
{x^3/(1 - Cosh[x]), x, 7, x^3 + x^3*Coth[x/2] - 6*x^2*Log[1 - E^x] - 12*x*PolyLog[2, E^x] + 12*PolyLog[3, E^x]}


{x/(a + b*Cosh[c + d*x])^2, x, 12, (a*x*Log[1 + (b*E^(c + d*x))/(a - Sqrt[a^2 - b^2])])/((a^2 - b^2)^(3/2)*d) - (a*x*Log[1 + (b*E^(c + d*x))/(a + Sqrt[a^2 - b^2])])/((a^2 - b^2)^(3/2)*d) + Log[a + b*Cosh[c + d*x]]/((a^2 - b^2)*d^2) + (a*PolyLog[2, -((b*E^(c + d*x))/(a - Sqrt[a^2 - b^2]))])/((a^2 - b^2)^(3/2)*d^2) - (a*PolyLog[2, -((b*E^(c + d*x))/(a + Sqrt[a^2 - b^2]))])/((a^2 - b^2)^(3/2)*d^2) - (b*x*Sinh[c + d*x])/((a^2 - b^2)*d*(a + b*Cosh[c + d*x]))}
{(e + f*x)/(a + b*Cosh[c + d*x])^2, x, 17, (2*a*e*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[(1/2)*(c + d*x)])/(a + b)])/((a^2 - b^2)^(3/2)*d) + (a*f*x*Log[1 + (b*E^(c + d*x))/(a - Sqrt[a^2 - b^2])])/((a^2 - b^2)^(3/2)*d) - (a*f*x*Log[1 + (b*E^(c + d*x))/(a + Sqrt[a^2 - b^2])])/((a^2 - b^2)^(3/2)*d) + (f*Log[a + b*Cosh[c + d*x]])/((a^2 - b^2)*d^2) + (a*f*PolyLog[2, -((b*E^(c + d*x))/(a - Sqrt[a^2 - b^2]))])/((a^2 - b^2)^(3/2)*d^2) - (a*f*PolyLog[2, -((b*E^(c + d*x))/(a + Sqrt[a^2 - b^2]))])/((a^2 - b^2)^(3/2)*d^2) - (b*e*Sinh[c + d*x])/((a^2 - b^2)*d*(a + b*Cosh[c + d*x])) - (b*f*x*Sinh[c + d*x])/((a^2 - b^2)*d*(a + b*Cosh[c + d*x]))}


(* ::Subsubsection::Closed:: *)
(*p/2*)


{x^3*Sqrt[a + a*Cosh[x]], x, 5, -96*Sqrt[a + a*Cosh[x]] - 12*x^2*Sqrt[a + a*Cosh[x]] + 48*x*Sqrt[a + a*Cosh[x]]*Tanh[x/2] + 2*x^3*Sqrt[a + a*Cosh[x]]*Tanh[x/2]}
{x^2*Sqrt[a + a*Cosh[x]], x, 4, -8*x*Sqrt[a + a*Cosh[x]] + 16*Sqrt[a + a*Cosh[x]]*Tanh[x/2] + 2*x^2*Sqrt[a + a*Cosh[x]]*Tanh[x/2]}
{x*Sqrt[a + a*Cosh[x]], x, 3, -4*Sqrt[a + a*Cosh[x]] + 2*x*Sqrt[a + a*Cosh[x]]*Tanh[x/2]}
{Sqrt[a + a*Cosh[x]], x, 1, (2*a*Sinh[x])/Sqrt[a + a*Cosh[x]]}
{Sqrt[a + a*Cosh[x]]/x, x, 2, Sqrt[a + a*Cosh[x]]*CoshIntegral[x/2]*Sech[x/2]}
{Sqrt[a + a*Cosh[x]]/x^2, x, 3, -(Sqrt[a + a*Cosh[x]]/x) + (1/2)*Sqrt[a + a*Cosh[x]]*Sech[x/2]*SinhIntegral[x/2]}
{Sqrt[a + a*Cosh[x]]/x^3, x, 4, -(Sqrt[a + a*Cosh[x]]/(2*x^2)) + (1/8)*Sqrt[a + a*Cosh[x]]*CoshIntegral[x/2]*Sech[x/2] - (Sqrt[a + a*Cosh[x]]*Tanh[x/2])/(4*x)}


{x^3*(a + a*Cosh[x])^(3/2), x, 9, (-(1280/9))*a*Sqrt[a + a*Cosh[x]] - 16*a*x^2*Sqrt[a + a*Cosh[x]] - (64/27)*a*Cosh[x/2]^2*Sqrt[a + a*Cosh[x]] - (8/3)*a*x^2*Cosh[x/2]^2*Sqrt[a + a*Cosh[x]] + (32/9)*a*x*Cosh[x/2]*Sqrt[a + a*Cosh[x]]*Sinh[x/2] + (4/3)*a*x^3*Cosh[x/2]*Sqrt[a + a*Cosh[x]]*Sinh[x/2] + (640/9)*a*x*Sqrt[a + a*Cosh[x]]*Tanh[x/2] + (8/3)*a*x^3*Sqrt[a + a*Cosh[x]]*Tanh[x/2]}
{x^2*(a + a*Cosh[x])^(3/2), x, 7, (-(32/3))*a*x*Sqrt[a + a*Cosh[x]] - (16/9)*a*x*Cosh[x/2]^2*Sqrt[a + a*Cosh[x]] + (4/3)*a*x^2*Cosh[x/2]*Sqrt[a + a*Cosh[x]]*Sinh[x/2] + (224/9)*a*Sqrt[a + a*Cosh[x]]*Tanh[x/2] + (8/3)*a*x^2*Sqrt[a + a*Cosh[x]]*Tanh[x/2] + (32/27)*a*Sqrt[a + a*Cosh[x]]*Sinh[x/2]^2*Tanh[x/2]}
{x*(a + a*Cosh[x])^(3/2), x, 4, (-(16/3))*a*Sqrt[a + a*Cosh[x]] - (8/9)*a*Cosh[x/2]^2*Sqrt[a + a*Cosh[x]] + (4/3)*a*x*Cosh[x/2]*Sqrt[a + a*Cosh[x]]*Sinh[x/2] + (8/3)*a*x*Sqrt[a + a*Cosh[x]]*Tanh[x/2]}
{(a + a*Cosh[x])^(3/2), x, 2, (8*a^2*Sinh[x])/(3*Sqrt[a + a*Cosh[x]]) + (2/3)*a*Sqrt[a + a*Cosh[x]]*Sinh[x]}
{(a + a*Cosh[x])^(3/2)/x, x, 5, (3/2)*a*Sqrt[a + a*Cosh[x]]*CoshIntegral[x/2]*Sech[x/2] + (1/2)*a*Sqrt[a + a*Cosh[x]]*CoshIntegral[(3*x)/2]*Sech[x/2]}
{(a + a*Cosh[x])^(3/2)/x^2, x, 5, -((2*a*Cosh[x/2]^2*Sqrt[a + a*Cosh[x]])/x) + (3/4)*a*Sqrt[a + a*Cosh[x]]*Sech[x/2]*SinhIntegral[x/2] + (3/4)*a*Sqrt[a + a*Cosh[x]]*Sech[x/2]*SinhIntegral[(3*x)/2]}
{(a + a*Cosh[x])^(3/2)/x^3, x, 7, -((a*Cosh[x/2]^2*Sqrt[a + a*Cosh[x]])/x^2) + (3/16)*a*Sqrt[a + a*Cosh[x]]*CoshIntegral[x/2]*Sech[x/2] + (9/16)*a*Sqrt[a + a*Cosh[x]]*CoshIntegral[(3*x)/2]*Sech[x/2] - (3*a*Cosh[x/2]*Sqrt[a + a*Cosh[x]]*Sinh[x/2])/(2*x)}


{x^3/Sqrt[a + a*Cosh[x]], x, 8, (2*x^3*ArcTan[E^(x/2)]*Sqrt[a + a*Cosh[x]]*Sech[x/2])/a - (6*I*x^2*Sqrt[a + a*Cosh[x]]*PolyLog[2, (-I)*E^(x/2)]*Sech[x/2])/a + (6*I*x^2*Sqrt[a + a*Cosh[x]]*PolyLog[2, I*E^(x/2)]*Sech[x/2])/a + (24*I*x*Sqrt[a + a*Cosh[x]]*PolyLog[3, (-I)*E^(x/2)]*Sech[x/2])/a - (24*I*x*Sqrt[a + a*Cosh[x]]*PolyLog[3, I*E^(x/2)]*Sech[x/2])/a - (48*I*Sqrt[a + a*Cosh[x]]*PolyLog[4, (-I)*E^(x/2)]*Sech[x/2])/a + (48*I*Sqrt[a + a*Cosh[x]]*PolyLog[4, I*E^(x/2)]*Sech[x/2])/a}
{x^2/Sqrt[a + a*Cosh[x]], x, 6, (2*x^2*ArcTan[E^(x/2)]*Sqrt[a + a*Cosh[x]]*Sech[x/2])/a - (4*I*x*Sqrt[a + a*Cosh[x]]*PolyLog[2, (-I)*E^(x/2)]*Sech[x/2])/a + (4*I*x*Sqrt[a + a*Cosh[x]]*PolyLog[2, I*E^(x/2)]*Sech[x/2])/a + (8*I*Sqrt[a + a*Cosh[x]]*PolyLog[3, (-I)*E^(x/2)]*Sech[x/2])/a - (8*I*Sqrt[a + a*Cosh[x]]*PolyLog[3, I*E^(x/2)]*Sech[x/2])/a}
{x/Sqrt[a + a*Cosh[x]], x, 4, (2*x*ArcTan[E^(x/2)]*Sqrt[a + a*Cosh[x]]*Sech[x/2])/a - (2*I*Sqrt[a + a*Cosh[x]]*PolyLog[2, (-I)*E^(x/2)]*Sech[x/2])/a + (2*I*Sqrt[a + a*Cosh[x]]*PolyLog[2, I*E^(x/2)]*Sech[x/2])/a}
{1/Sqrt[a + a*Cosh[x]], x, 1, (2*ArcTan[Sinh[x/2]]*Cosh[x/2])/Sqrt[a + a*Cosh[x]]}
{1/(x*Sqrt[a + a*Cosh[x]]), x, 1, (Sqrt[a + a*Cosh[x]]*Int[Sech[x/2]/x, x]*Sech[x/2])/(2*a)}


(* {x^3/(a + a*Cosh[x])^(3/2), x, 14, -((12*x*ArcTan[E^(x/2)]*Sqrt[a + a*Cosh[x]]*Sech[x/2])/a^2) + (x^3*ArcTan[E^(x/2)]*Sqrt[a + a*Cosh[x]]*Sech[x/2])/(2*a^2) + (3*I*(8 - x^2)*Sqrt[a*(1 + Cosh[x])]*PolyLog[2, (-I)*E^(x/2)]*Sech[x/2])/(2*a^2) - (3*I*(8 - x^2)*Sqrt[a*(1 + Cosh[x])]*PolyLog[2, I*E^(x/2)]*Sech[x/2])/(2*a^2) + (6*I*x*Sqrt[a + a*Cosh[x]]*PolyLog[3, (-I)*E^(x/2)]*Sech[x/2])/a^2 - (6*I*x*Sqrt[a + a*Cosh[x]]*PolyLog[3, I*E^(x/2)]*Sech[x/2])/a^2 - (12*I*Sqrt[a + a*Cosh[x]]*PolyLog[4, (-I)*E^(x/2)]*Sech[x/2])/a^2 + (12*I*Sqrt[a + a*Cosh[x]]*PolyLog[4, I*E^(x/2)]*Sech[x/2])/a^2 + (3*x^2*Sqrt[a + a*Cosh[x]]*Sech[x/2]^2)/(2*a^2) + (x^3*Sqrt[a + a*Cosh[x]]*Sech[x/2]^2*Tanh[x/2])/(4*a^2)} *)
{x^2/(a + a*Cosh[x])^(3/2), x, 8, (x^2*ArcTan[E^(x/2)]*Sqrt[a + a*Cosh[x]]*Sech[x/2])/(2*a^2) - (2*ArcTan[Sinh[x/2]]*Sqrt[a + a*Cosh[x]]*Sech[x/2])/a^2 - (I*x*Sqrt[a + a*Cosh[x]]*PolyLog[2, (-I)*E^(x/2)]*Sech[x/2])/a^2 + (I*x*Sqrt[a + a*Cosh[x]]*PolyLog[2, I*E^(x/2)]*Sech[x/2])/a^2 + (2*I*Sqrt[a + a*Cosh[x]]*PolyLog[3, (-I)*E^(x/2)]*Sech[x/2])/a^2 - (2*I*Sqrt[a + a*Cosh[x]]*PolyLog[3, I*E^(x/2)]*Sech[x/2])/a^2 + (x*Sqrt[a + a*Cosh[x]]*Sech[x/2]^2)/a^2 + (x^2*Sqrt[a + a*Cosh[x]]*Sech[x/2]^2*Tanh[x/2])/(4*a^2)}
{x/(a + a*Cosh[x])^(3/2), x, 5, (x*ArcTan[E^(x/2)]*Sqrt[a + a*Cosh[x]]*Sech[x/2])/(2*a^2) - (I*Sqrt[a + a*Cosh[x]]*PolyLog[2, (-I)*E^(x/2)]*Sech[x/2])/(2*a^2) + (I*Sqrt[a + a*Cosh[x]]*PolyLog[2, I*E^(x/2)]*Sech[x/2])/(2*a^2) + (Sqrt[a + a*Cosh[x]]*Sech[x/2]^2)/(2*a^2) + (x*Sqrt[a + a*Cosh[x]]*Sech[x/2]^2*Tanh[x/2])/(4*a^2)}
{1/(a + a*Cosh[x])^(3/2), x, 2, (ArcTan[Sinh[x/2]]*Cosh[x/2])/(2*a*Sqrt[a + a*Cosh[x]]) + Sinh[x]/(2*(a + a*Cosh[x])^(3/2))}
{1/(x*(a + a*Cosh[x])^(3/2)), x, 1, (Sqrt[a + a*Cosh[x]]*Int[Sech[x/2]^3/x, x]*Sech[x/2])/(4*a^2)}


{x^3*Sqrt[a - a*Cosh[x]], x, 5, -96*Sqrt[a - a*Cosh[x]] - 12*x^2*Sqrt[a - a*Cosh[x]] + 48*x*Sqrt[a - a*Cosh[x]]*Coth[x/2] + 2*x^3*Sqrt[a - a*Cosh[x]]*Coth[x/2]}
{x^2*Sqrt[a - a*Cosh[x]], x, 4, -8*x*Sqrt[a - a*Cosh[x]] + 16*Sqrt[a - a*Cosh[x]]*Coth[x/2] + 2*x^2*Sqrt[a - a*Cosh[x]]*Coth[x/2]}
{x*Sqrt[a - a*Cosh[x]], x, 3, -4*Sqrt[a - a*Cosh[x]] + 2*x*Sqrt[a - a*Cosh[x]]*Coth[x/2]}
{Sqrt[a - a*Cosh[x]], x, 1, -((2*a*Sinh[x])/Sqrt[a - a*Cosh[x]])}
{Sqrt[a - a*Cosh[x]]/x, x, 2, Sqrt[a - a*Cosh[x]]*Csch[x/2]*SinhIntegral[x/2]}
{Sqrt[a - a*Cosh[x]]/x^2, x, 3, -(Sqrt[a - a*Cosh[x]]/x) + (1/2)*Sqrt[a - a*Cosh[x]]*CoshIntegral[x/2]*Csch[x/2]}
{Sqrt[a - a*Cosh[x]]/x^3, x, 4, -(Sqrt[a - a*Cosh[x]]/(2*x^2)) - (Sqrt[a - a*Cosh[x]]*Coth[x/2])/(4*x) + (1/8)*Sqrt[a - a*Cosh[x]]*Csch[x/2]*SinhIntegral[x/2]}


{x^3/Sqrt[a - a*Cosh[x]], x, 8, (2*x^3*ArcTanh[E^(x/2)]*Sqrt[a - a*Cosh[x]]*Csch[x/2])/a + (6*x^2*Sqrt[a - a*Cosh[x]]*Csch[x/2]*PolyLog[2, -E^(x/2)])/a - (6*x^2*Sqrt[a - a*Cosh[x]]*Csch[x/2]*PolyLog[2, E^(x/2)])/a - (24*x*Sqrt[a - a*Cosh[x]]*Csch[x/2]*PolyLog[3, -E^(x/2)])/a + (24*x*Sqrt[a - a*Cosh[x]]*Csch[x/2]*PolyLog[3, E^(x/2)])/a + (48*Sqrt[a - a*Cosh[x]]*Csch[x/2]*PolyLog[4, -E^(x/2)])/a - (48*Sqrt[a - a*Cosh[x]]*Csch[x/2]*PolyLog[4, E^(x/2)])/a}
{x^2/Sqrt[a - a*Cosh[x]], x, 6, (2*x^2*ArcTanh[E^(x/2)]*Sqrt[a - a*Cosh[x]]*Csch[x/2])/a + (4*x*Sqrt[a - a*Cosh[x]]*Csch[x/2]*PolyLog[2, -E^(x/2)])/a - (4*x*Sqrt[a - a*Cosh[x]]*Csch[x/2]*PolyLog[2, E^(x/2)])/a - (8*Sqrt[a - a*Cosh[x]]*Csch[x/2]*PolyLog[3, -E^(x/2)])/a + (8*Sqrt[a - a*Cosh[x]]*Csch[x/2]*PolyLog[3, E^(x/2)])/a}
{x/Sqrt[a - a*Cosh[x]], x, 4, (2*x*ArcTanh[E^(x/2)]*Sqrt[a - a*Cosh[x]]*Csch[x/2])/a + (2*Sqrt[a - a*Cosh[x]]*Csch[x/2]*PolyLog[2, -E^(x/2)])/a - (2*Sqrt[a - a*Cosh[x]]*Csch[x/2]*PolyLog[2, E^(x/2)])/a}
{1/Sqrt[a - a*Cosh[x]], x, 1, -((2*ArcTanh[Cosh[x/2]]*Sinh[x/2])/Sqrt[a - a*Cosh[x]])}
{1/(x*Sqrt[a - a*Cosh[x]]), x, 1, -((Sqrt[a - a*Cosh[x]]*Csch[x/2]*Int[Csch[x/2]/x, x])/(2*a))}


{x^3*Sqrt[a + a*Cosh[c + d*x]], x, 5, -((96*Sqrt[a + a*Cosh[c + d*x]])/d^4) - (12*x^2*Sqrt[a + a*Cosh[c + d*x]])/d^2 + (48*x*Sqrt[a + a*Cosh[c + d*x]]*Tanh[c/2 + (d*x)/2])/d^3 + (2*x^3*Sqrt[a + a*Cosh[c + d*x]]*Tanh[c/2 + (d*x)/2])/d}
{x^2*Sqrt[a + a*Cosh[c + d*x]], x, 4, -((8*x*Sqrt[a + a*Cosh[c + d*x]])/d^2) + (16*Sqrt[a + a*Cosh[c + d*x]]*Tanh[c/2 + (d*x)/2])/d^3 + (2*x^2*Sqrt[a + a*Cosh[c + d*x]]*Tanh[c/2 + (d*x)/2])/d}
{x*Sqrt[a + a*Cosh[c + d*x]], x, 3, -((4*Sqrt[a + a*Cosh[c + d*x]])/d^2) + (2*x*Sqrt[a + a*Cosh[c + d*x]]*Tanh[c/2 + (d*x)/2])/d}
{Sqrt[a + a*Cosh[c + d*x]], x, 1, (2*a*Sinh[c + d*x])/(d*Sqrt[a + a*Cosh[c + d*x]])}
{Sqrt[a + a*Cosh[c + d*x]]/x, x, 4, Cosh[c/2]*Sqrt[a + a*Cosh[c + d*x]]*CoshIntegral[(d*x)/2]*Sech[c/2 + (d*x)/2] + Sqrt[a + a*Cosh[c + d*x]]*Sech[c/2 + (d*x)/2]*Sinh[c/2]*SinhIntegral[(d*x)/2]}
{Sqrt[a + a*Cosh[c + d*x]]/x^2, x, 5, -(Sqrt[a + a*Cosh[c + d*x]]/x) + (1/2)*d*Sqrt[a + a*Cosh[c + d*x]]*CoshIntegral[(d*x)/2]*Sech[c/2 + (d*x)/2]*Sinh[c/2] + (1/2)*d*Cosh[c/2]*Sqrt[a + a*Cosh[c + d*x]]*Sech[c/2 + (d*x)/2]*SinhIntegral[(d*x)/2]}
{Sqrt[a + a*Cosh[c + d*x]]/x^3, x, 6, -(Sqrt[a + a*Cosh[c + d*x]]/(2*x^2)) + (1/8)*d^2*Cosh[c/2]*Sqrt[a + a*Cosh[c + d*x]]*CoshIntegral[(d*x)/2]*Sech[c/2 + (d*x)/2] + (1/8)*d^2*Sqrt[a + a*Cosh[c + d*x]]*Sech[c/2 + (d*x)/2]*Sinh[c/2]*SinhIntegral[(d*x)/2] - (d*Sqrt[a + a*Cosh[c + d*x]]*Tanh[c/2 + (d*x)/2])/(4*x)}


{x^3/Sqrt[a + a*Cosh[c + d*x]], x, 8, (2*x^3*ArcTan[E^(c/2 + (d*x)/2)]*Sqrt[a + a*Cosh[c + d*x]]*Sech[c/2 + (d*x)/2])/(a*d) - (6*I*x^2*Sqrt[a + a*Cosh[c + d*x]]*PolyLog[2, (-I)*E^(c/2 + (d*x)/2)]*Sech[c/2 + (d*x)/2])/(a*d^2) + (6*I*x^2*Sqrt[a + a*Cosh[c + d*x]]*PolyLog[2, I*E^(c/2 + (d*x)/2)]*Sech[c/2 + (d*x)/2])/(a*d^2) + (24*I*x*Sqrt[a + a*Cosh[c + d*x]]*PolyLog[3, (-I)*E^(c/2 + (d*x)/2)]*Sech[c/2 + (d*x)/2])/(a*d^3) - (24*I*x*Sqrt[a + a*Cosh[c + d*x]]*PolyLog[3, I*E^(c/2 + (d*x)/2)]*Sech[c/2 + (d*x)/2])/(a*d^3) - (48*I*Sqrt[a + a*Cosh[c + d*x]]*PolyLog[4, (-I)*E^(c/2 + (d*x)/2)]*Sech[c/2 + (d*x)/2])/(a*d^4) + (48*I*Sqrt[a + a*Cosh[c + d*x]]*PolyLog[4, I*E^(c/2 + (d*x)/2)]*Sech[c/2 + (d*x)/2])/(a*d^4)}
{x^2/Sqrt[a + a*Cosh[c + d*x]], x, 6, (2*x^2*ArcTan[E^(c/2 + (d*x)/2)]*Sqrt[a + a*Cosh[c + d*x]]*Sech[c/2 + (d*x)/2])/(a*d) - (4*I*x*Sqrt[a + a*Cosh[c + d*x]]*PolyLog[2, (-I)*E^(c/2 + (d*x)/2)]*Sech[c/2 + (d*x)/2])/(a*d^2) + (4*I*x*Sqrt[a + a*Cosh[c + d*x]]*PolyLog[2, I*E^(c/2 + (d*x)/2)]*Sech[c/2 + (d*x)/2])/(a*d^2) + (8*I*Sqrt[a + a*Cosh[c + d*x]]*PolyLog[3, (-I)*E^(c/2 + (d*x)/2)]*Sech[c/2 + (d*x)/2])/(a*d^3) - (8*I*Sqrt[a + a*Cosh[c + d*x]]*PolyLog[3, I*E^(c/2 + (d*x)/2)]*Sech[c/2 + (d*x)/2])/(a*d^3)}
{x/Sqrt[a + a*Cosh[c + d*x]], x, 4, (2*x*ArcTan[E^(c/2 + (d*x)/2)]*Sqrt[a + a*Cosh[c + d*x]]*Sech[c/2 + (d*x)/2])/(a*d) - (2*I*Sqrt[a + a*Cosh[c + d*x]]*PolyLog[2, (-I)*E^(c/2 + (d*x)/2)]*Sech[c/2 + (d*x)/2])/(a*d^2) + (2*I*Sqrt[a + a*Cosh[c + d*x]]*PolyLog[2, I*E^(c/2 + (d*x)/2)]*Sech[c/2 + (d*x)/2])/(a*d^2)}
{1/Sqrt[a + a*Cosh[c + d*x]], x, 1, (2*ArcTan[Sinh[(1/2)*(c + d*x)]]*Cosh[(1/2)*(c + d*x)])/(d*Sqrt[a + a*Cosh[c + d*x]])}
{1/(x*Sqrt[a + a*Cosh[c + d*x]]), x, 1, (Sqrt[a + a*Cosh[c + d*x]]*Int[Sech[c/2 + (d*x)/2]/x, x]*Sech[c/2 + (d*x)/2])/(2*a)}


(* Used to hang Rubi *)
{(a + a*Cosh[c + d*x])^(1/3)/x, x, 1, (Sqrt[a + a*Cosh[c + d*x]]*Int[Cosh[c/2 + (d*x)/2]^(2/3)/x, x]*Sech[c/2 + (d*x)/2])/(2^(1/6)*a^(1/6))}


(* ::Subsection::Closed:: *)
(*Integrands of the form (e+f x)^m (a+b Cosh[c+d x]^2)^p*)


{x/(a + b*Cosh[x]^2), x, 9, (x*Log[1 + (b*E^(2*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b]) - (x*Log[1 + (b*E^(2*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b]) + PolyLog[2, -((b*E^(2*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b]))]/(4*Sqrt[a]*Sqrt[a + b]) - PolyLog[2, -((b*E^(2*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b]))]/(4*Sqrt[a]*Sqrt[a + b])}
{x^2/(a + b*Cosh[x]^2), x, 11, (x^2*Log[1 + (b*E^(2*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b]) - (x^2*Log[1 + (b*E^(2*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b]) + (x*PolyLog[2, -((b*E^(2*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b]))])/(2*Sqrt[a]*Sqrt[a + b]) - (x*PolyLog[2, -((b*E^(2*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b]))])/(2*Sqrt[a]*Sqrt[a + b]) - PolyLog[3, -((b*E^(2*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b]))]/(4*Sqrt[a]*Sqrt[a + b]) + PolyLog[3, -((b*E^(2*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b]))]/(4*Sqrt[a]*Sqrt[a + b])}
{x^3/(a + b*Cosh[x]^2), x, 13, (x^3*Log[1 + (b*E^(2*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b]) - (x^3*Log[1 + (b*E^(2*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b])])/(2*Sqrt[a]*Sqrt[a + b]) + (3*x^2*PolyLog[2, -((b*E^(2*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b]))])/(4*Sqrt[a]*Sqrt[a + b]) - (3*x^2*PolyLog[2, -((b*E^(2*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b]))])/(4*Sqrt[a]*Sqrt[a + b]) - (3*x*PolyLog[3, -((b*E^(2*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b]))])/(4*Sqrt[a]*Sqrt[a + b]) + (3*x*PolyLog[3, -((b*E^(2*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b]))])/(4*Sqrt[a]*Sqrt[a + b]) + (3*PolyLog[4, -((b*E^(2*x))/(2*a + b - 2*Sqrt[a]*Sqrt[a + b]))])/(8*Sqrt[a]*Sqrt[a + b]) - (3*PolyLog[4, -((b*E^(2*x))/(2*a + b + 2*Sqrt[a]*Sqrt[a + b]))])/(8*Sqrt[a]*Sqrt[a + b])}


(* ::Section::Closed:: *)
(*Integrands of the form (d+e x)^m Cosh[a+b x+c x^2]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form (d+e x)^m Cosh[a+b x+c x^2]^n*)


{x^2*Cosh[a + b*x + c*x^2], x, 12, (b^2*E^(-a + b^2/(4*c))*Sqrt[Pi]*Erf[(b + 2*c*x)/(2*Sqrt[c])])/(16*c^(5/2)) + (E^(-a + b^2/(4*c))*Sqrt[Pi]*Erf[(b + 2*c*x)/(2*Sqrt[c])])/(8*c^(3/2)) + (b^2*E^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b + 2*c*x)/(2*Sqrt[c])])/(16*c^(5/2)) - (E^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b + 2*c*x)/(2*Sqrt[c])])/(8*c^(3/2)) - (b*Sinh[a + b*x + c*x^2])/(4*c^2) + (x*Sinh[a + b*x + c*x^2])/(2*c)}
{x*Cosh[a + b*x + c*x^2], x, 6, -((b*E^(-a + b^2/(4*c))*Sqrt[Pi]*Erf[(b + 2*c*x)/(2*Sqrt[c])])/(8*c^(3/2))) - (b*E^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b + 2*c*x)/(2*Sqrt[c])])/(8*c^(3/2)) + Sinh[a + b*x + c*x^2]/(2*c)}
{Cosh[a + b*x + c*x^2], x, 5, (E^(-a + b^2/(4*c))*Sqrt[Pi]*Erf[(b + 2*c*x)/(2*Sqrt[c])])/(4*Sqrt[c]) + (E^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b + 2*c*x)/(2*Sqrt[c])])/(4*Sqrt[c])}
{Cosh[a + b*x + c*x^2]/x, x, 0, Int[Cosh[a + b*x + c*x^2]/x, x]}
{Cosh[a + b*x + c*x^2]/x^2 - b*Sinh[a + b*x + c*x^2]/x, x, 7, -(Cosh[a + b*x + c*x^2]/x) - (1/2)*Sqrt[c]*E^(-a + b^2/(4*c))*Sqrt[Pi]*Erf[(b + 2*c*x)/(2*Sqrt[c])] + (1/2)*Sqrt[c]*E^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b + 2*c*x)/(2*Sqrt[c])]}

{x^2*Cosh[a + b*x - c*x^2], x, 12, -((b^2*E^(a + b^2/(4*c))*Sqrt[Pi]*Erf[(b - 2*c*x)/(2*Sqrt[c])])/(16*c^(5/2))) - (E^(a + b^2/(4*c))*Sqrt[Pi]*Erf[(b - 2*c*x)/(2*Sqrt[c])])/(8*c^(3/2)) - (b^2*E^(-a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b - 2*c*x)/(2*Sqrt[c])])/(16*c^(5/2)) + (E^(-a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b - 2*c*x)/(2*Sqrt[c])])/(8*c^(3/2)) - (b*Sinh[a + b*x - c*x^2])/(4*c^2) - (x*Sinh[a + b*x - c*x^2])/(2*c)}
{x*Cosh[a + b*x - c*x^2], x, 6, -((b*E^(a + b^2/(4*c))*Sqrt[Pi]*Erf[(b - 2*c*x)/(2*Sqrt[c])])/(8*c^(3/2))) - (b*E^(-a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b - 2*c*x)/(2*Sqrt[c])])/(8*c^(3/2)) - Sinh[a + b*x - c*x^2]/(2*c)}
{Cosh[a + b*x - c*x^2], x, 5, -((E^(a + b^2/(4*c))*Sqrt[Pi]*Erf[(b - 2*c*x)/(2*Sqrt[c])])/(4*Sqrt[c])) - (E^(-a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b - 2*c*x)/(2*Sqrt[c])])/(4*Sqrt[c])}
{Cosh[a + b*x - c*x^2]/x, x, 0, Int[Cosh[a + b*x - c*x^2]/x, x]}
{Cosh[a + b*x - c*x^2]/x^2 - b*Sinh[a + b*x - c*x^2]/x, x, 7, -(Cosh[a + b*x - c*x^2]/x) + (1/2)*Sqrt[c]*E^(a + b^2/(4*c))*Sqrt[Pi]*Erf[(b - 2*c*x)/(2*Sqrt[c])] - (1/2)*Sqrt[c]*E^(-a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b - 2*c*x)/(2*Sqrt[c])]}

{x^2*Cosh[1/4 + x + x^2], x, 12, (-(3/16))*Sqrt[Pi]*Erf[(1/2)*(-1 - 2*x)] - (1/16)*Sqrt[Pi]*Erfi[(1/2)*(1 + 2*x)] - (1/4)*Sinh[1/4 + x + x^2] + (1/2)*x*Sinh[1/4 + x + x^2]}
{x*Cosh[1/4 + x + x^2], x, 6, (1/8)*Sqrt[Pi]*Erf[(1/2)*(-1 - 2*x)] - (1/8)*Sqrt[Pi]*Erfi[(1/2)*(1 + 2*x)] + (1/2)*Sinh[1/4 + x + x^2]}
{Cosh[1/4 + x + x^2], x, 5, (-(1/4))*Sqrt[Pi]*Erf[(1/2)*(-1 - 2*x)] + (1/4)*Sqrt[Pi]*Erfi[(1/2)*(1 + 2*x)]}
{Cosh[1/4 + x + x^2]/x, x, 0, Int[Cosh[1/4 + x + x^2]/x, x]}
{Cosh[1/4 + x + x^2]/x^2, x, 6, -(Cosh[1/4 + x + x^2]/x) + (1/2)*Sqrt[Pi]*Erf[(1/2)*(-1 - 2*x)] + (1/2)*Sqrt[Pi]*Erfi[(1/2)*(1 + 2*x)] + Int[Sinh[1/4 + x + x^2]/x, x]}


{x^2*Cosh[a + b*x + c*x^2]^2, x, 14, x^3/6 + (b^2*E^(-2*a + b^2/(2*c))*Sqrt[Pi/2]*Erf[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(32*c^(5/2)) + (E^(-2*a + b^2/(2*c))*Sqrt[Pi/2]*Erf[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(32*c^(3/2)) + (b^2*E^(2*a - b^2/(2*c))*Sqrt[Pi/2]*Erfi[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(32*c^(5/2)) - (E^(2*a - b^2/(2*c))*Sqrt[Pi/2]*Erfi[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(32*c^(3/2)) - (b*Sinh[2*a + 2*b*x + 2*c*x^2])/(16*c^2) + (x*Sinh[2*a + 2*b*x + 2*c*x^2])/(8*c)}
{x*Cosh[a + b*x + c*x^2]^2, x, 8, x^2/4 - (b*E^(-2*a + b^2/(2*c))*Sqrt[Pi/2]*Erf[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(16*c^(3/2)) - (b*E^(2*a - b^2/(2*c))*Sqrt[Pi/2]*Erfi[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(16*c^(3/2)) + Sinh[2*a + 2*b*x + 2*c*x^2]/(8*c)}
{Cosh[a + b*x + c*x^2]^2, x, 7, x/2 + (E^(-2*a + b^2/(2*c))*Sqrt[Pi/2]*Erf[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(8*Sqrt[c]) + (E^(2*a - b^2/(2*c))*Sqrt[Pi/2]*Erfi[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(8*Sqrt[c])}
{Cosh[a + b*x + c*x^2]^2/x, x, 2, (1/2)*Int[Cosh[2*a + 2*b*x + 2*c*x^2]/x, x] + Log[x]/2}

{x^2*Cosh[a + b*x - c*x^2]^2, x, 14, x^3/6 - (b^2*E^(2*a + b^2/(2*c))*Sqrt[Pi/2]*Erf[(b - 2*c*x)/(Sqrt[2]*Sqrt[c])])/(32*c^(5/2)) - (E^(2*a + b^2/(2*c))*Sqrt[Pi/2]*Erf[(b - 2*c*x)/(Sqrt[2]*Sqrt[c])])/(32*c^(3/2)) - (b^2*E^(-2*a - b^2/(2*c))*Sqrt[Pi/2]*Erfi[(b - 2*c*x)/(Sqrt[2]*Sqrt[c])])/(32*c^(5/2)) + (E^(-2*a - b^2/(2*c))*Sqrt[Pi/2]*Erfi[(b - 2*c*x)/(Sqrt[2]*Sqrt[c])])/(32*c^(3/2)) - (b*Sinh[2*a + 2*b*x - 2*c*x^2])/(16*c^2) - (x*Sinh[2*a + 2*b*x - 2*c*x^2])/(8*c)}
{x*Cosh[a + b*x - c*x^2]^2, x, 8, x^2/4 - (b*E^(2*a + b^2/(2*c))*Sqrt[Pi/2]*Erf[(b - 2*c*x)/(Sqrt[2]*Sqrt[c])])/(16*c^(3/2)) - (b*E^(-2*a - b^2/(2*c))*Sqrt[Pi/2]*Erfi[(b - 2*c*x)/(Sqrt[2]*Sqrt[c])])/(16*c^(3/2)) - Sinh[2*a + 2*b*x - 2*c*x^2]/(8*c)}
{Cosh[a + b*x - c*x^2]^2, x, 7, x/2 - (E^(2*a + b^2/(2*c))*Sqrt[Pi/2]*Erf[(b - 2*c*x)/(Sqrt[2]*Sqrt[c])])/(8*Sqrt[c]) - (E^(-2*a - b^2/(2*c))*Sqrt[Pi/2]*Erfi[(b - 2*c*x)/(Sqrt[2]*Sqrt[c])])/(8*Sqrt[c])}
{Cosh[a + b*x - c*x^2]^2/x, x, 2, (1/2)*Int[Cosh[2*a + 2*b*x - 2*c*x^2]/x, x] + Log[x]/2}

{x^2*Cosh[1/4 + x + x^2]^2, x, 14, x^3/6 + (1/16)*Sqrt[Pi/2]*Erf[(1 + 2*x)/Sqrt[2]] - (1/16)*Sinh[1/2 + 2*x + 2*x^2] + (1/8)*x*Sinh[1/2 + 2*x + 2*x^2]}
{x*Cosh[1/4 + x + x^2]^2, x, 8, x^2/4 - (1/16)*Sqrt[Pi/2]*Erf[(1 + 2*x)/Sqrt[2]] - (1/16)*Sqrt[Pi/2]*Erfi[(1 + 2*x)/Sqrt[2]] + (1/8)*Sinh[1/2 + 2*x + 2*x^2]}
{Cosh[1/4 + x + x^2]^2, x, 7, x/2 + (1/8)*Sqrt[Pi/2]*Erf[(1 + 2*x)/Sqrt[2]] + (1/8)*Sqrt[Pi/2]*Erfi[(1 + 2*x)/Sqrt[2]]}
{Cosh[1/4 + x + x^2]^2/x, x, 2, (1/2)*Int[Cosh[1/2 + 2*x + 2*x^2]/x, x] + Log[x]/2}


{(d + e*x)^2*Cosh[a + b*x + c*x^2], x, 12, (e^2*E^(-a + b^2/(4*c))*Sqrt[Pi]*Erf[(b + 2*c*x)/(2*Sqrt[c])])/(8*c^(3/2)) + ((2*c*d - b*e)^2*E^(-a + b^2/(4*c))*Sqrt[Pi]*Erf[(b + 2*c*x)/(2*Sqrt[c])])/(16*c^(5/2)) - (e^2*E^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b + 2*c*x)/(2*Sqrt[c])])/(8*c^(3/2)) + ((2*c*d - b*e)^2*E^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b + 2*c*x)/(2*Sqrt[c])])/(16*c^(5/2)) + (e*(2*c*d - b*e)*Sinh[a + b*x + c*x^2])/(4*c^2) + (e*(d + e*x)*Sinh[a + b*x + c*x^2])/(2*c)}
{(d + e*x)*Cosh[a + b*x + c*x^2], x, 6, ((2*c*d - b*e)*E^(-a + b^2/(4*c))*Sqrt[Pi]*Erf[(b + 2*c*x)/(2*Sqrt[c])])/(8*c^(3/2)) + ((2*c*d - b*e)*E^(a - b^2/(4*c))*Sqrt[Pi]*Erfi[(b + 2*c*x)/(2*Sqrt[c])])/(8*c^(3/2)) + (e*Sinh[a + b*x + c*x^2])/(2*c)}
{Cosh[a + b*x + c*x^2]/(d + e*x), x, 0, Int[Cosh[a + b*x + c*x^2]/(d + e*x), x]}

{(d + e*x)^2*Cosh[a + b*x + c*x^2]^2, x, 14, (d + e*x)^3/(6*e) + (e^2*E^(-2*a + b^2/(2*c))*Sqrt[Pi/2]*Erf[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(32*c^(3/2)) + ((2*c*d - b*e)^2*E^(-2*a + b^2/(2*c))*Sqrt[Pi/2]*Erf[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(32*c^(5/2)) - (e^2*E^(2*a - b^2/(2*c))*Sqrt[Pi/2]*Erfi[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(32*c^(3/2)) + ((2*c*d - b*e)^2*E^(2*a - b^2/(2*c))*Sqrt[Pi/2]*Erfi[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(32*c^(5/2)) + (e*(2*c*d - b*e)*Sinh[2*a + 2*b*x + 2*c*x^2])/(16*c^2) + (e*(d + e*x)*Sinh[2*a + 2*b*x + 2*c*x^2])/(8*c)}
{(d + e*x)*Cosh[a + b*x + c*x^2]^2, x, 8, (d + e*x)^2/(4*e) + ((2*c*d - b*e)*E^(-2*a + b^2/(2*c))*Sqrt[Pi/2]*Erf[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(16*c^(3/2)) + ((2*c*d - b*e)*E^(2*a - b^2/(2*c))*Sqrt[Pi/2]*Erfi[(b + 2*c*x)/(Sqrt[2]*Sqrt[c])])/(16*c^(3/2)) + (e*Sinh[2*a + 2*b*x + 2*c*x^2])/(8*c)}
{Cosh[a + b*x + c*x^2]^2/(d + e*x), x, 2, (1/2)*Int[Cosh[2*a + 2*b*x + 2*c*x^2]/(d + e*x), x] + Log[d + e*x]/(2*e)}


(* ::Subsection:: *)
(*Integrands of the form (d+e x)^m Cosh[a+b x+c x^2]^(n/2)*)


(* ::Section::Closed:: *)
(*Integrands of the form x^m Cosh[a+b x^n]^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Cosh[a+b x^2]^p*)


{x^3*Cosh[a + b*x^2], x, 2, -(Cosh[a + b*x^2]/(2*b^2)) + (x^2*Sinh[a + b*x^2])/(2*b)}
{x^2*Cosh[a + b*x^2], x, 4, (Sqrt[Pi]*Erf[Sqrt[b]*x])/(E^a*(8*b^(3/2))) - (E^a*Sqrt[Pi]*Erfi[Sqrt[b]*x])/(8*b^(3/2)) + (x*Sinh[a + b*x^2])/(2*b)}
{x*Cosh[a + b*x^2], x, 1, Sinh[a + b*x^2]/(2*b)}
{Cosh[a + b*x^2], x, 3, (Sqrt[Pi]*Erf[Sqrt[b]*x])/(E^a*(4*Sqrt[b])) + (E^a*Sqrt[Pi]*Erfi[Sqrt[b]*x])/(4*Sqrt[b])}
{Cosh[a + b*x^2]/x, x, 3, (1/2)*Cosh[a]*CoshIntegral[b*x^2] + (1/2)*Sinh[a]*SinhIntegral[b*x^2]}
{Cosh[a + b*x^2]/x^2, x, 4, -(Cosh[a + b*x^2]/x) - ((1/2)*Sqrt[b]*Sqrt[Pi]*Erf[Sqrt[b]*x])/E^a + (1/2)*Sqrt[b]*E^a*Sqrt[Pi]*Erfi[Sqrt[b]*x]}
{Cosh[a + b*x^2]/x^3, x, 4, -(Cosh[a + b*x^2]/(2*x^2)) + (1/2)*b*CoshIntegral[b*x^2]*Sinh[a] + (1/2)*b*Cosh[a]*SinhIntegral[b*x^2]}


{x^3*Cosh[a + b*x^2]^2, x, 2, x^4/8 - Cosh[a + b*x^2]^2/(8*b^2) + (x^2*Cosh[a + b*x^2]*Sinh[a + b*x^2])/(4*b)}
{x^2*Cosh[a + b*x^2]^2, x, 6, x^3/6 + (Sqrt[Pi/2]*Erf[Sqrt[2]*Sqrt[b]*x])/(E^(2*a)*(32*b^(3/2))) - (E^(2*a)*Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[b]*x])/(32*b^(3/2)) + (x*Sinh[2*a + 2*b*x^2])/(8*b)}
{x*Cosh[a + b*x^2]^2, x, 2, x^2/4 + (Cosh[a + b*x^2]*Sinh[a + b*x^2])/(4*b)}
{Cosh[a + b*x^2]^2, x, 5, x/2 + (Sqrt[Pi/2]*Erf[Sqrt[2]*Sqrt[b]*x])/(E^(2*a)*(8*Sqrt[b])) + (E^(2*a)*Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[b]*x])/(8*Sqrt[b])}
{Cosh[a + b*x^2]^2/x, x, 5, (1/4)*Cosh[2*a]*CoshIntegral[2*b*x^2] + Log[x]/2 + (1/4)*Sinh[2*a]*SinhIntegral[2*b*x^2]}
{Cosh[a + b*x^2]^2/x^2, x, 5, -(Cosh[a + b*x^2]^2/x) - ((1/2)*Sqrt[b]*Sqrt[Pi/2]*Erf[Sqrt[2]*Sqrt[b]*x])/E^(2*a) + (1/2)*Sqrt[b]*E^(2*a)*Sqrt[Pi/2]*Erfi[Sqrt[2]*Sqrt[b]*x]}
{Cosh[a + b*x^2]^2/x^3, x, 6, -(1/(4*x^2)) - Cosh[2*a + 2*b*x^2]/(4*x^2) + (1/2)*b*CoshIntegral[2*b*x^2]*Sinh[2*a] + (1/2)*b*Cosh[2*a]*SinhIntegral[2*b*x^2]}


{x^3*Cosh[a + b*x^2]^3, x, 3, -(Cosh[a + b*x^2]/(3*b^2)) - Cosh[a + b*x^2]^3/(18*b^2) + (x^2*Sinh[a + b*x^2])/(3*b) + (x^2*Cosh[a + b*x^2]^2*Sinh[a + b*x^2])/(6*b)}
{x^2*Cosh[a + b*x^2]^3, x, 10, (3*Sqrt[Pi]*Erf[Sqrt[b]*x])/(E^a*(32*b^(3/2))) + (Sqrt[Pi/3]*Erf[Sqrt[3]*Sqrt[b]*x])/(E^(3*a)*(96*b^(3/2))) - (3*E^a*Sqrt[Pi]*Erfi[Sqrt[b]*x])/(32*b^(3/2)) - (E^(3*a)*Sqrt[Pi/3]*Erfi[Sqrt[3]*Sqrt[b]*x])/(96*b^(3/2)) + (3*x*Sinh[a + b*x^2])/(8*b) + (x*Sinh[3*a + 3*b*x^2])/(24*b)}
{x*Cosh[a + b*x^2]^3, x, 3, Sinh[a + b*x^2]/(2*b) + Sinh[a + b*x^2]^3/(6*b)}
{Cosh[a + b*x^2]^3, x, 8, (3*Sqrt[Pi]*Erf[Sqrt[b]*x])/(E^a*(16*Sqrt[b])) + (Sqrt[Pi/3]*Erf[Sqrt[3]*Sqrt[b]*x])/(E^(3*a)*(16*Sqrt[b])) + (3*E^a*Sqrt[Pi]*Erfi[Sqrt[b]*x])/(16*Sqrt[b]) + (E^(3*a)*Sqrt[Pi/3]*Erfi[Sqrt[3]*Sqrt[b]*x])/(16*Sqrt[b])}
{Cosh[a + b*x^2]^3/x, x, 8, (3/8)*Cosh[a]*CoshIntegral[b*x^2] + (1/8)*Cosh[3*a]*CoshIntegral[3*b*x^2] + (3/8)*Sinh[a]*SinhIntegral[b*x^2] + (1/8)*Sinh[3*a]*SinhIntegral[3*b*x^2]}
{Cosh[a + b*x^2]^3/x^2, x, 9, -(Cosh[a + b*x^2]^3/x) - ((3/8)*Sqrt[b]*Sqrt[Pi]*Erf[Sqrt[b]*x])/E^a - ((1/8)*Sqrt[b]*Sqrt[3*Pi]*Erf[Sqrt[3]*Sqrt[b]*x])/E^(3*a) + (3/8)*Sqrt[b]*E^a*Sqrt[Pi]*Erfi[Sqrt[b]*x] + (1/8)*Sqrt[b]*E^(3*a)*Sqrt[3*Pi]*Erfi[Sqrt[3]*Sqrt[b]*x]}
{Cosh[a + b*x^2]^3/x^3, x, 10, -((3*Cosh[a + b*x^2])/(8*x^2)) - Cosh[3*a + 3*b*x^2]/(8*x^2) + (3/8)*b*CoshIntegral[b*x^2]*Sinh[a] + (3/8)*b*CoshIntegral[3*b*x^2]*Sinh[3*a] + (3/8)*b*Cosh[a]*SinhIntegral[b*x^2] + (3/8)*b*Cosh[3*a]*SinhIntegral[3*b*x^2]}


{x*Cosh[a + b*x^2]^7, x, 3, Sinh[a + b*x^2]/(2*b) + Sinh[a + b*x^2]^3/(2*b) + (3*Sinh[a + b*x^2]^5)/(10*b) + Sinh[a + b*x^2]^7/(14*b)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Cosh[a+b x^n]*)


{Cosh[a + b/x], x, 5, x*Cosh[a + b/x] - b*CoshIntegral[b/x]*Sinh[a] - b*Cosh[a]*SinhIntegral[b/x]}
{Cosh[a + b/x]/x, x, 3, (-Cosh[a])*CoshIntegral[b/x] - Sinh[a]*SinhIntegral[b/x]}
{Cosh[a + b/x]/x^2, x, 1, -(Sinh[a + b/x]/b)}
{Cosh[a + b/x]/x^3, x, 2, Cosh[a + b/x]/b^2 - Sinh[a + b/x]/(b*x)}
{Cosh[a + b/x]/x^4, x, 3, (2*Cosh[a + b/x])/(b^2*x) - (2*Sinh[a + b/x])/b^3 - Sinh[a + b/x]/(b*x^2)}


{Cosh[a + b/x^2], x, 5, x*Cosh[a + b/x^2] + ((1/2)*Sqrt[b]*Sqrt[Pi]*Erf[Sqrt[b]/x])/E^a - (1/2)*Sqrt[b]*E^a*Sqrt[Pi]*Erfi[Sqrt[b]/x]}
{Cosh[a + b/x^2]/x, x, 3, (-(1/2))*Cosh[a]*CoshIntegral[b/x^2] - (1/2)*Sinh[a]*SinhIntegral[b/x^2]}
{Cosh[a + b/x^2]/x^2, x, 5, -((Sqrt[Pi]*Erf[Sqrt[b]/x])/(E^a*(4*Sqrt[b]))) - (E^a*Sqrt[Pi]*Erfi[Sqrt[b]/x])/(4*Sqrt[b])}
{Cosh[a + b/x^2]/x^3, x, 1, -(Sinh[a + b/x^2]/(2*b))}
{Cosh[a + b/x^2]/x^4, x, 6, -((Sqrt[Pi]*Erf[Sqrt[b]/x])/(E^a*(8*b^(3/2)))) + (E^a*Sqrt[Pi]*Erfi[Sqrt[b]/x])/(8*b^(3/2)) - Sinh[a + b/x^2]/(2*b*x)}


{x^2*Cosh[x^3], x, 1, Sinh[x^3]/3}
{Cosh[1/x^5]/x^6, x, 1, -Sinh[x^(-5)]/5}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Cosh[a+b x^n]^p*)


{Cosh[a + b*x^n], x, 3, -((E^a*x*Gamma[1/n, (-b)*x^n])/(((-b)*x^n)^n^(-1)*(2*n))) - (x*Gamma[1/n, b*x^n])/(E^a*(b*x^n)^n^(-1)*(2*n))}
{Cosh[a + b*x^n]^2, x, 5, x/2 - (2^(-2 - 1/n)*E^(2*a)*x*Gamma[1/n, -2*b*x^n])/(((-b)*x^n)^n^(-1)*n) - (2^(-2 - 1/n)*x*Gamma[1/n, 2*b*x^n])/(E^(2*a)*(b*x^n)^n^(-1)*n)}
{Cosh[a + b*x^n]^3, x, 8, -((E^(3*a)*x*Gamma[1/n, -3*b*x^n])/(3^n^(-1)*((-b)*x^n)^n^(-1)*(8*n))) - (3*E^a*x*Gamma[1/n, (-b)*x^n])/(((-b)*x^n)^n^(-1)*(8*n)) - (3*x*Gamma[1/n, b*x^n])/(E^a*(b*x^n)^n^(-1)*(8*n)) - (x*Gamma[1/n, 3*b*x^n])/(3^n^(-1)*E^(3*a)*(b*x^n)^n^(-1)*(8*n))}

{x^m*Cosh[a + b*x^n], x, 3, -((E^a*x^(1 + m)*Gamma[(1 + m)/n, (-b)*x^n])/(((-b)*x^n)^((1 + m)/n)*(2*n))) - (x^(1 + m)*Gamma[(1 + m)/n, b*x^n])/(E^a*(b*x^n)^((1 + m)/n)*(2*n))}
{x^m*Cosh[a + b*x^n]^2, x, 5, x^(1 + m)/(2*(1 + m)) - (E^(2*a)*x^(1 + m)*Gamma[(1 + m)/n, -2*b*x^n])/(2^((1 + m + 2*n)/n)*((-b)*x^n)^((1 + m)/n)*n) - (x^(1 + m)*Gamma[(1 + m)/n, 2*b*x^n])/(2^((1 + m + 2*n)/n)*E^(2*a)*(b*x^n)^((1 + m)/n)*n)}
{x^m*Cosh[a + b*x^n]^3, x, 8, -((E^(3*a)*x^(1 + m)*Gamma[(1 + m)/n, -3*b*x^n])/(3^((1 + m)/n)*((-b)*x^n)^((1 + m)/n)*(8*n))) - (3*E^a*x^(1 + m)*Gamma[(1 + m)/n, (-b)*x^n])/(((-b)*x^n)^((1 + m)/n)*(8*n)) - (3*x^(1 + m)*Gamma[(1 + m)/n, b*x^n])/(E^a*(b*x^n)^((1 + m)/n)*(8*n)) - (x^(1 + m)*Gamma[(1 + m)/n, 3*b*x^n])/(3^((1 + m)/n)*E^(3*a)*(b*x^n)^((1 + m)/n)*(8*n))}

{Cosh[a + b*x^n]/x^(n + 1), x, 4, -(Cosh[a + b*x^n]/(x^n*n)) + (b*CoshIntegral[b*x^n]*Sinh[a])/n + (b*Cosh[a]*SinhIntegral[b*x^n])/n}
{Cosh[a + b*x^n]^2/x^(n + 1), x, 6, -(1/(x^n*(2*n))) - Cosh[2*a + 2*b*x^n]/(x^n*(2*n)) + (b*CoshIntegral[2*b*x^n]*Sinh[2*a])/n + (b*Cosh[2*a]*SinhIntegral[2*b*x^n])/n}
{Cosh[a + b*x^n]^3/x^(n + 1), x, 10, -((3*Cosh[a + b*x^n])/(x^n*(4*n))) - Cosh[3*a + 3*b*x^n]/(x^n*(4*n)) + (3*b*CoshIntegral[b*x^n]*Sinh[a])/(4*n) + (3*b*CoshIntegral[3*b*x^n]*Sinh[3*a])/(4*n) + (3*b*Cosh[a]*SinhIntegral[b*x^n])/(4*n) + (3*b*Cosh[3*a]*SinhIntegral[3*b*x^n])/(4*n)}

{Cosh[a + b*x^n]/x, x, 3, (Cosh[a]*CoshIntegral[b*x^n])/n + (Sinh[a]*SinhIntegral[b*x^n])/n}
{Cosh[a + b*x^n]^2/x, x, 5, (Cosh[2*a]*CoshIntegral[2*b*x^n])/(2*n) + Log[x]/2 + (Sinh[2*a]*SinhIntegral[2*b*x^n])/(2*n)}
{Cosh[a + b*x^n]^3/x, x, 8, (3*Cosh[a]*CoshIntegral[b*x^n])/(4*n) + (Cosh[3*a]*CoshIntegral[3*b*x^n])/(4*n) + (3*Sinh[a]*SinhIntegral[b*x^n])/(4*n) + (Sinh[3*a]*SinhIntegral[3*b*x^n])/(4*n)}


(* ::Section::Closed:: *)
(*Integrands of the form x^m Sinh[c+d x] (a+b Cosh[c+d x]^n)^p*)


{x*Sinh[x]/(a + b*Cosh[x])^2, x, 2, (2*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[x/2])/(a + b)])/(b*Sqrt[a^2 - b^2]) - x/(b*(a + b*Cosh[x]))}
{x*Sinh[x]/(a + b*Cosh[x])^3, x, 4, (a*ArcTanh[(Sqrt[a^2 - b^2]*Tanh[x/2])/(a + b)])/(b*(a^2 - b^2)^(3/2)) - x/(2*b*(a + b*Cosh[x])^2) - Sinh[x]/(2*(a^2 - b^2)*(a + b*Cosh[x]))}


{Sinh[a + b*x]*(2 + Cosh[a + b*x]^2)/x, x, 13, (9/4)*CoshIntegral[b*x]*Sinh[a] + (1/4)*CoshIntegral[3*b*x]*Sinh[3*a] + (9/4)*Cosh[a]*SinhIntegral[b*x] + (1/4)*Cosh[3*a]*SinhIntegral[3*b*x]}


(* ::Section::Closed:: *)
(*Integrands of the form x^m Cosh[a+b Log[c x^n]]^p*)


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Cosh[a+b Log[c x^n]]^p*)


{Cosh[a + b*Log[c*x^n]], x, 1, (x*Cosh[a + b*Log[c*x^n]])/(1 - b^2*n^2) - (b*n*x*Sinh[a + b*Log[c*x^n]])/(1 - b^2*n^2)}
{Cosh[a + b*Log[c*x^n]]^2, x, 2, -((2*b^2*n^2*x)/(1 - 4*b^2*n^2)) + (x*Cosh[a + b*Log[c*x^n]]^2)/(1 - 4*b^2*n^2) - (2*b*n*x*Cosh[a + b*Log[c*x^n]]*Sinh[a + b*Log[c*x^n]])/(1 - 4*b^2*n^2)}
{Cosh[a + b*Log[c*x^n]]^3, x, 2, -((6*b^2*n^2*x*Cosh[a + b*Log[c*x^n]])/(1 - 10*b^2*n^2 + 9*b^4*n^4)) + (x*Cosh[a + b*Log[c*x^n]]^3)/(1 - 9*b^2*n^2) + (6*b^3*n^3*x*Sinh[a + b*Log[c*x^n]])/(1 - 10*b^2*n^2 + 9*b^4*n^4) - (3*b*n*x*Cosh[a + b*Log[c*x^n]]^2*Sinh[a + b*Log[c*x^n]])/(1 - 9*b^2*n^2)}
{Cosh[a + b*Log[c*x^n]]^4, x, 3, (24*b^4*n^4*x)/(1 - 20*b^2*n^2 + 64*b^4*n^4) - (12*b^2*n^2*x*Cosh[a + b*Log[c*x^n]]^2)/(1 - 20*b^2*n^2 + 64*b^4*n^4) + (x*Cosh[a + b*Log[c*x^n]]^4)/(1 - 16*b^2*n^2) + (24*b^3*n^3*x*Cosh[a + b*Log[c*x^n]]*Sinh[a + b*Log[c*x^n]])/(1 - 20*b^2*n^2 + 64*b^4*n^4) - (4*b*n*x*Cosh[a + b*Log[c*x^n]]^3*Sinh[a + b*Log[c*x^n]])/(1 - 16*b^2*n^2)}


{x^m*Cosh[a + b*Log[c*x^n]], x, 1, ((1 + m)*x^(1 + m)*Cosh[a + b*Log[c*x^n]])/((1 + m)^2 - b^2*n^2) - (b*n*x^(1 + m)*Sinh[a + b*Log[c*x^n]])/((1 + m)^2 - b^2*n^2)}
{x^m*Cosh[a + b*Log[c*x^n]]^2, x, 2, -((2*b^2*n^2*x^(1 + m))/((1 + m)*((1 + m)^2 - 4*b^2*n^2))) + ((1 + m)*x^(1 + m)*Cosh[a + b*Log[c*x^n]]^2)/((1 + m)^2 - 4*b^2*n^2) - (2*b*n*x^(1 + m)*Cosh[a + b*Log[c*x^n]]*Sinh[a + b*Log[c*x^n]])/((1 + m)^2 - 4*b^2*n^2)}
{x^m*Cosh[a + b*Log[c*x^n]]^3, x, 2, -((6*b^2*(1 + m)*n^2*x^(1 + m)*Cosh[a + b*Log[c*x^n]])/(((1 + m)^2 - 9*b^2*n^2)*((1 + m)^2 - b^2*n^2))) + ((1 + m)*x^(1 + m)*Cosh[a + b*Log[c*x^n]]^3)/((1 + m)^2 - 9*b^2*n^2) + (6*b^3*n^3*x^(1 + m)*Sinh[a + b*Log[c*x^n]])/(((1 + m)^2 - 9*b^2*n^2)*((1 + m)^2 - b^2*n^2)) - (3*b*n*x^(1 + m)*Cosh[a + b*Log[c*x^n]]^2*Sinh[a + b*Log[c*x^n]])/((1 + m)^2 - 9*b^2*n^2)}
{x^m*Cosh[a + b*Log[c*x^n]]^4, x, 3, (24*b^4*n^4*x^(1 + m))/((1 + m)*((1 + m)^2 - 16*b^2*n^2)*((1 + m)^2 - 4*b^2*n^2)) - (12*b^2*(1 + m)*n^2*x^(1 + m)*Cosh[a + b*Log[c*x^n]]^2)/(((1 + m)^2 - 16*b^2*n^2)*((1 + m)^2 - 4*b^2*n^2)) + ((1 + m)*x^(1 + m)*Cosh[a + b*Log[c*x^n]]^4)/((1 + m)^2 - 16*b^2*n^2) + (24*b^3*n^3*x^(1 + m)*Cosh[a + b*Log[c*x^n]]*Sinh[a + b*Log[c*x^n]])/(((1 + m)^2 - 16*b^2*n^2)*((1 + m)^2 - 4*b^2*n^2)) - (4*b*n*x^(1 + m)*Cosh[a + b*Log[c*x^n]]^3*Sinh[a + b*Log[c*x^n]])/((1 + m)^2 - 16*b^2*n^2)}


{Cosh[a + b*Log[c*x^n]]/x, x, 2, Sinh[a + b*Log[c*x^n]]/(b*n)}
{Cosh[a + b*Log[c*x^n]]^2/x, x, 2, Log[c*x^n]/(2*n) + (Cosh[a + b*Log[c*x^n]]*Sinh[a + b*Log[c*x^n]])/(2*b*n)}
{Cosh[a + b*Log[c*x^n]]^3/x, x, 3, Sinh[a + b*Log[c*x^n]]/(b*n) + Sinh[a + b*Log[c*x^n]]^3/(3*b*n)}
{Cosh[a + b*Log[c*x^n]]^4/x, x, 3, (3*Log[c*x^n])/(8*n) + (3*Cosh[a + b*Log[c*x^n]]*Sinh[a + b*Log[c*x^n]])/(8*b*n) + (Cosh[a + b*Log[c*x^n]]^3*Sinh[a + b*Log[c*x^n]])/(4*b*n)}
{Cosh[a + b*Log[c*x^n]]^5/x, x, 3, Sinh[a + b*Log[c*x^n]]/(b*n) + (2*Sinh[a + b*Log[c*x^n]]^3)/(3*b*n) + Sinh[a + b*Log[c*x^n]]^5/(5*b*n)}


(* ::Subsection::Closed:: *)
(*Integrands of the form x^m Cosh[a+b Log[c x^n]]^(p/2)*)


{Cosh[a + b*Log[c*x^n]]^(5/2)/x, x, 3, -((6*I*EllipticE[(1/2)*I*(a + b*Log[c*x^n]), 2])/(5*b*n)) + (2*Cosh[a + b*Log[c*x^n]]^(3/2)*Sinh[a + b*Log[c*x^n]])/(5*b*n)}
{Cosh[a + b*Log[c*x^n]]^(3/2)/x, x, 3, -((2*I*EllipticF[(1/2)*I*(a + b*Log[c*x^n]), 2])/(3*b*n)) + (2*Sqrt[Cosh[a + b*Log[c*x^n]]]*Sinh[a + b*Log[c*x^n]])/(3*b*n)}
{Sqrt[Cosh[a + b*Log[c*x^n]]]/x, x, 2, -((2*I*EllipticE[(1/2)*I*(a + b*Log[c*x^n]), 2])/(b*n))}
{1/(x*Sqrt[Cosh[a + b*Log[c*x^n]]]), x, 2, -((2*I*EllipticF[(1/2)*I*(a + b*Log[c*x^n]), 2])/(b*n))}
{1/(x*Cosh[a + b*Log[c*x^n]]^(3/2)), x, 3, (2*I*EllipticE[(1/2)*I*(a + b*Log[c*x^n]), 2])/(b*n) + (2*Sinh[a + b*Log[c*x^n]])/(b*n*Sqrt[Cosh[a + b*Log[c*x^n]]])}
{1/(x*Cosh[a + b*Log[c*x^n]]^(5/2)), x, 3, -((2*I*EllipticF[(1/2)*I*(a + b*Log[c*x^n]), 2])/(3*b*n)) + (2*Sinh[a + b*Log[c*x^n]])/(3*b*n*Cosh[a + b*Log[c*x^n]]^(3/2))}


{Cosh[a + 2/n*Log[c*x^n]]^(5/2), x, 6, (5/16)*x*Sqrt[Cosh[a + (2*Log[c*x^n])/n]] - (5*x*ArcTanh[Sqrt[1 + E^(2*a)*(c*x^n)^(4/n)]]*Sqrt[Cosh[a + (2*Log[c*x^n])/n]])/(16*Sqrt[1 + E^(2*a)*(c*x^n)^(4/n)]) - (1/24)*x*Cosh[a + (2*Log[c*x^n])/n]^(5/2) + (5/24)*x*Cosh[a + (2*Log[c*x^n])/n]^(3/2)*Sinh[a + (2*Log[c*x^n])/n]}
{Sqrt[Cosh[a + 2/n*Log[c*x^n]]], x, 5, (1/2)*x*Sqrt[Cosh[a + (2*Log[c*x^n])/n]] - (x*ArcTanh[Sqrt[1 + E^(2*a)*(c*x^n)^(4/n)]]*Sqrt[Cosh[a + (2*Log[c*x^n])/n]])/(2*Sqrt[1 + E^(2*a)*(c*x^n)^(4/n)])}
{1/Cosh[a + 2/n*Log[c*x^n]]^(3/2), x, 1, (-x)*Sqrt[Cosh[a + (2*Log[c*x^n])/n]] + (x*Sinh[a + (2*Log[c*x^n])/n])/Sqrt[Cosh[a + (2*Log[c*x^n])/n]]}
{1/Cosh[a + 2/n*Log[c*x^n]]^(7/2), x, 2, x/(15*Cosh[a + (2*Log[c*x^n])/n]^(3/2)) - (8/15)*x*Sqrt[Cosh[a + (2*Log[c*x^n])/n]] + (x*Sinh[a + (2*Log[c*x^n])/n])/(5*Cosh[a + (2*Log[c*x^n])/n]^(5/2)) + (8*x*Sinh[a + (2*Log[c*x^n])/n])/(15*Sqrt[Cosh[a + (2*Log[c*x^n])/n]])}


(* ::Section::Closed:: *)
(*Integrands of the form Cosh[(a+b x)/(c+d x)]^n*)


{Cosh[(a + b*x)/(c + d*x)], x, 5, ((c + d*x)*Cosh[b/d - (b*c - a*d)/(d*(c + d*x))])/d + ((b*c - a*d)*CoshIntegral[(b*c - a*d)/(d*(c + d*x))]*Sinh[b/d])/d^2 - ((b*c - a*d)*Cosh[b/d]*SinhIntegral[(b*c - a*d)/(d*(c + d*x))])/d^2}
{Cosh[(a + b*x)/(c + d*x)]^2, x, 6, ((c + d*x)*Cosh[b/d - (b*c - a*d)/(d*(c + d*x))]^2)/d + ((b*c - a*d)*CoshIntegral[(2*(b*c - a*d))/(d*(c + d*x))]*Sinh[(2*b)/d])/d^2 - ((b*c - a*d)*Cosh[(2*b)/d]*SinhIntegral[(2*(b*c - a*d))/(d*(c + d*x))])/d^2}


(* ::Section::Closed:: *)
(*Miscellaneous integrands involving hyperbolic cosines*)


{x/Cosh[x]^(3/2) + x*Sqrt[Cosh[x]], x, 2, -4*Sqrt[Cosh[x]] + (2*x*Sinh[x])/Sqrt[Cosh[x]]}
{x/Cosh[x]^(5/2) - x/(3*Sqrt[Cosh[x]]), x, 2, 4/(3*Sqrt[Cosh[x]]) + (2*x*Sinh[x])/(3*Cosh[x]^(3/2))}
{x/Cosh[x]^(7/2) + (3/5)*x*Sqrt[Cosh[x]], x, 3, 4/(15*Cosh[x]^(3/2)) - (12*Sqrt[Cosh[x]])/5 + (2*x*Sinh[x])/(5*Cosh[x]^(5/2)) + (6*x*Sinh[x])/(5*Sqrt[Cosh[x]])}
{x^2/Cosh[x]^(3/2) + x^2*Sqrt[Cosh[x]], x, 3, -8*x*Sqrt[Cosh[x]] - 16*I*EllipticE[(I*x)/2, 2] + (2*x^2*Sinh[x])/Sqrt[Cosh[x]]}


{(x + Cosh[x])^2, x, 5, x/2 + x^3/3 - 2*Cosh[x] + 2*x*Sinh[x] + (1/2)*Cosh[x]*Sinh[x]}
{(x + Cosh[x])^3, x, 9, (3*x^2)/4 + x^4/4 - 6*x*Cosh[x] - (3*Cosh[x]^2)/4 + 7*Sinh[x] + 3*x^2*Sinh[x] + (3/2)*x*Cosh[x]*Sinh[x] + Sinh[x]^3/3}


{Cosh[a + b*x]/(c + d*x^2), x, 7, (Cosh[a + (b*Sqrt[-c])/Sqrt[d]]*CoshIntegral[(b*Sqrt[-c])/Sqrt[d] - b*x])/(2*Sqrt[-c]*Sqrt[d]) - (Cosh[a - (b*Sqrt[-c])/Sqrt[d]]*CoshIntegral[(b*Sqrt[-c])/Sqrt[d] + b*x])/(2*Sqrt[-c]*Sqrt[d]) - (Sinh[a + (b*Sqrt[-c])/Sqrt[d]]*SinhIntegral[(b*Sqrt[-c])/Sqrt[d] - b*x])/(2*Sqrt[-c]*Sqrt[d]) - (Sinh[a - (b*Sqrt[-c])/Sqrt[d]]*SinhIntegral[(b*Sqrt[-c])/Sqrt[d] + b*x])/(2*Sqrt[-c]*Sqrt[d])}
{Cosh[a + b*x]/(c + d*x + e*x^2), x, 7, (Cosh[a - (b*(d - Sqrt[d^2 - 4*c*e]))/(2*e)]*CoshIntegral[(b*(d - Sqrt[d^2 - 4*c*e]))/(2*e) + b*x])/Sqrt[d^2 - 4*c*e] - (Cosh[a - (b*(d + Sqrt[d^2 - 4*c*e]))/(2*e)]*CoshIntegral[(b*(d + Sqrt[d^2 - 4*c*e]))/(2*e) + b*x])/Sqrt[d^2 - 4*c*e] + (Sinh[a - (b*(d - Sqrt[d^2 - 4*c*e]))/(2*e)]*SinhIntegral[(b*(d - Sqrt[d^2 - 4*c*e]))/(2*e) + b*x])/Sqrt[d^2 - 4*c*e] - (Sinh[a - (b*(d + Sqrt[d^2 - 4*c*e]))/(2*e)]*SinhIntegral[(b*(d + Sqrt[d^2 - 4*c*e]))/(2*e) + b*x])/Sqrt[d^2 - 4*c*e]}
