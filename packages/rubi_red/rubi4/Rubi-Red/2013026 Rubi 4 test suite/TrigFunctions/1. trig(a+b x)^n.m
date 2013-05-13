(* ::Package:: *)

(* ::Title:: *)
(*Problems for integrands of the form trig(a+b x)^n*)


(* ::Section::Closed:: *)
(*Integrands of the form Sin[a+b x]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[a+b x]^n*)


{Sin[a + b*x]^n, x, 1, -((Cos[a + b*x]*Hypergeometric2F1[1/2, (1 - n)/2, 3/2, Cos[a + b*x]^2]*Sin[a + b*x]^(1 + n)*(Sin[a + b*x]^2)^((1/2)*(-1 - n)))/b)}

{Sin[a + b*x]^1, x, 1, -(Cos[a + b*x]/b)}
{Sin[a + b*x]^2, x, 1, x/2 - (Cos[a + b*x]*Sin[a + b*x])/(2*b)}
{Sin[a + b*x]^3, x, 2, -(Cos[a + b*x]/b) + Cos[a + b*x]^3/(3*b)}
{Sin[a + b*x]^4, x, 2, (3*x)/8 - (3*Cos[a + b*x]*Sin[a + b*x])/(8*b) - (Cos[a + b*x]*Sin[a + b*x]^3)/(4*b)}
{Sin[a + b*x]^5, x, 2, -(Cos[a + b*x]/b) + (2*Cos[a + b*x]^3)/(3*b) - Cos[a + b*x]^5/(5*b)}
{Sin[a + b*x]^6, x, 3, (5*x)/16 - (5*Cos[a + b*x]*Sin[a + b*x])/(16*b) - (5*Cos[a + b*x]*Sin[a + b*x]^3)/(24*b) - (Cos[a + b*x]*Sin[a + b*x]^5)/(6*b)}
{Sin[a + b*x]^7, x, 2, -(Cos[a + b*x]/b) + Cos[a + b*x]^3/b - (3*Cos[a + b*x]^5)/(5*b) + Cos[a + b*x]^7/(7*b)}
{Sin[a + b*x]^8, x, 4, (35*x)/128 - (35*Cos[a + b*x]*Sin[a + b*x])/(128*b) - (35*Cos[a + b*x]*Sin[a + b*x]^3)/(192*b) - (7*Cos[a + b*x]*Sin[a + b*x]^5)/(48*b) - (Cos[a + b*x]*Sin[a + b*x]^7)/(8*b)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[a+b x]^(n/2)*)


{Sin[a + b*x]^(7/2), x, 3, -((10*EllipticF[Pi/4 + (1/2)*(-a - b*x), 2])/(21*b)) - (10*Cos[a + b*x]*Sqrt[Sin[a + b*x]])/(21*b) - (2*Cos[a + b*x]*Sin[a + b*x]^(5/2))/(7*b)}
{Sin[a + b*x]^(5/2), x, 2, -((6*EllipticE[Pi/4 + (1/2)*(-a - b*x), 2])/(5*b)) - (2*Cos[a + b*x]*Sin[a + b*x]^(3/2))/(5*b)}
{Sin[a + b*x]^(3/2), x, 2, -((2*EllipticF[Pi/4 + (1/2)*(-a - b*x), 2])/(3*b)) - (2*Cos[a + b*x]*Sqrt[Sin[a + b*x]])/(3*b)}
{Sin[a + b*x]^(1/2), x, 1, -((2*EllipticE[Pi/4 + (1/2)*(-a - b*x), 2])/b)}
{1/Sin[a + b*x]^(1/2), x, 1, -((2*EllipticF[Pi/4 + (1/2)*(-a - b*x), 2])/b)}
{1/Sin[a + b*x]^(3/2), x, 2, (2*EllipticE[Pi/4 + (1/2)*(-a - b*x), 2])/b - (2*Cos[a + b*x])/(b*Sqrt[Sin[a + b*x]])}
{1/Sin[a + b*x]^(5/2), x, 2, -((2*EllipticF[Pi/4 + (1/2)*(-a - b*x), 2])/(3*b)) - (2*Cos[a + b*x])/(3*b*Sin[a + b*x]^(3/2))}
{1/Sin[a + b*x]^(7/2), x, 3, (6*EllipticE[Pi/4 + (1/2)*(-a - b*x), 2])/(5*b) - (2*Cos[a + b*x])/(5*b*Sin[a + b*x]^(5/2)) - (6*Cos[a + b*x])/(5*b*Sqrt[Sin[a + b*x]])}


(* ::Subsection::Closed:: *)
(*Integrands of the form Sin[a+b x]^(n/3)*)


{Sin[a + b*x]^(4/3), x, 2, -((3*Cos[a + b*x]*Sin[a + b*x]^(1/3))/(4*b)) - (Cos[a + b*x]*Hypergeometric2F1[1/2, 5/6, 3/2, Cos[a + b*x]^2]*Sin[a + b*x]^(1/3))/(4*b*(Sin[a + b*x]^2)^(1/6))}
{Sin[a + b*x]^(2/3), x, 1, -((Cos[a + b*x]*Hypergeometric2F1[1/6, 1/2, 3/2, Cos[a + b*x]^2]*(Sin[a + b*x]^2)^(1/6))/(b*Sin[a + b*x]^(1/3)))}
{Sin[a + b*x]^(1/3), x, 1, -((Cos[a + b*x]*Hypergeometric2F1[1/3, 1/2, 3/2, Cos[a + b*x]^2]*(Sin[a + b*x]^2)^(1/3))/(b*Sin[a + b*x]^(2/3)))}
{1/Sin[a + b*x]^(1/3), x, 1, -((Cos[a + b*x]*Hypergeometric2F1[1/2, 2/3, 3/2, Cos[a + b*x]^2]*Sin[a + b*x]^(2/3))/(b*(Sin[a + b*x]^2)^(1/3)))}
{1/Sin[a + b*x]^(2/3), x, 1, -((Cos[a + b*x]*Hypergeometric2F1[1/2, 5/6, 3/2, Cos[a + b*x]^2]*Sin[a + b*x]^(1/3))/(b*(Sin[a + b*x]^2)^(1/6)))}
{1/Sin[a + b*x]^(4/3), x, 2, -((3*Cos[a + b*x])/(b*Sin[a + b*x]^(1/3))) + (2*Cos[a + b*x]*Hypergeometric2F1[1/6, 1/2, 3/2, Cos[a + b*x]^2]*(Sin[a + b*x]^2)^(1/6))/(b*Sin[a + b*x]^(1/3))}


(* ::Section::Closed:: *)
(*Integrands of the form Cos[a+b x]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[a+b x]^n*)


{Cos[a + b*x]^n, x, 1, (Cos[a + b*x]^(1 + n)*(Cos[a + b*x]^2)^((1/2)*(-1 - n))*Hypergeometric2F1[1/2, (1 - n)/2, 3/2, Sin[a + b*x]^2]*Sin[a + b*x])/b}

{Cos[a + b*x]^1, x, 1, Sin[a + b*x]/b}
{Cos[a + b*x]^2, x, 1, x/2 + (Cos[a + b*x]*Sin[a + b*x])/(2*b)}
{Cos[a + b*x]^3, x, 2, Sin[a + b*x]/b - Sin[a + b*x]^3/(3*b)}
{Cos[a + b*x]^4, x, 2, (3*x)/8 + (3*Cos[a + b*x]*Sin[a + b*x])/(8*b) + (Cos[a + b*x]^3*Sin[a + b*x])/(4*b)}
{Cos[a + b*x]^5, x, 2, Sin[a + b*x]/b - (2*Sin[a + b*x]^3)/(3*b) + Sin[a + b*x]^5/(5*b)}
{Cos[a + b*x]^6, x, 3, (5*x)/16 + (5*Cos[a + b*x]*Sin[a + b*x])/(16*b) + (5*Cos[a + b*x]^3*Sin[a + b*x])/(24*b) + (Cos[a + b*x]^5*Sin[a + b*x])/(6*b)}
{Cos[a + b*x]^7, x, 2, Sin[a + b*x]/b - Sin[a + b*x]^3/b + (3*Sin[a + b*x]^5)/(5*b) - Sin[a + b*x]^7/(7*b)}
{Cos[a + b*x]^8, x, 4, (35*x)/128 + (35*Cos[a + b*x]*Sin[a + b*x])/(128*b) + (35*Cos[a + b*x]^3*Sin[a + b*x])/(192*b) + (7*Cos[a + b*x]^5*Sin[a + b*x])/(48*b) + (Cos[a + b*x]^7*Sin[a + b*x])/(8*b)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[a+b x]^(n/2)*)


{Cos[a + b*x]^(11/2), x, 4, (30*EllipticF[(1/2)*(a + b*x), 2])/(77*b) + (30*Sqrt[Cos[a + b*x]]*Sin[a + b*x])/(77*b) + (18*Cos[a + b*x]^(5/2)*Sin[a + b*x])/(77*b) + (2*Cos[a + b*x]^(9/2)*Sin[a + b*x])/(11*b)}
{Cos[a + b*x]^(9/2), x, 3, (14*EllipticE[(1/2)*(a + b*x), 2])/(15*b) + (14*Cos[a + b*x]^(3/2)*Sin[a + b*x])/(45*b) + (2*Cos[a + b*x]^(7/2)*Sin[a + b*x])/(9*b)}
{Cos[a + b*x]^(7/2), x, 3, (10*EllipticF[(1/2)*(a + b*x), 2])/(21*b) + (10*Sqrt[Cos[a + b*x]]*Sin[a + b*x])/(21*b) + (2*Cos[a + b*x]^(5/2)*Sin[a + b*x])/(7*b)}
{Cos[a + b*x]^(5/2), x, 2, (6*EllipticE[(1/2)*(a + b*x), 2])/(5*b) + (2*Cos[a + b*x]^(3/2)*Sin[a + b*x])/(5*b)}
{Cos[a + b*x]^(3/2), x, 2, (2*EllipticF[(1/2)*(a + b*x), 2])/(3*b) + (2*Sqrt[Cos[a + b*x]]*Sin[a + b*x])/(3*b)}
{Cos[a + b*x]^(1/2), x, 1, (2*EllipticE[(1/2)*(a + b*x), 2])/b}
{1/Cos[a + b*x]^(1/2), x, 1, (2*EllipticF[(1/2)*(a + b*x), 2])/b}
{1/Cos[a + b*x]^(3/2), x, 2, -((2*EllipticE[(1/2)*(a + b*x), 2])/b) + (2*Sin[a + b*x])/(b*Sqrt[Cos[a + b*x]])}
{1/Cos[a + b*x]^(5/2), x, 2, (2*EllipticF[(1/2)*(a + b*x), 2])/(3*b) + (2*Sin[a + b*x])/(3*b*Cos[a + b*x]^(3/2))}
{1/Cos[a + b*x]^(7/2), x, 3, -((6*EllipticE[(1/2)*(a + b*x), 2])/(5*b)) + (2*Sin[a + b*x])/(5*b*Cos[a + b*x]^(5/2)) + (6*Sin[a + b*x])/(5*b*Sqrt[Cos[a + b*x]])}
{1/Cos[a + b*x]^(9/2), x, 3, (10*EllipticF[(1/2)*(a + b*x), 2])/(21*b) + (2*Sin[a + b*x])/(7*b*Cos[a + b*x]^(7/2)) + (10*Sin[a + b*x])/(21*b*Cos[a + b*x]^(3/2))}
{1/Cos[a + b*x]^(11/2), x, 4, -((14*EllipticE[(1/2)*(a + b*x), 2])/(15*b)) + (2*Sin[a + b*x])/(9*b*Cos[a + b*x]^(9/2)) + (14*Sin[a + b*x])/(45*b*Cos[a + b*x]^(5/2)) + (14*Sin[a + b*x])/(15*b*Sqrt[Cos[a + b*x]])}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cos[a+b x]^(n/3)*)


{Cos[a + b*x]^(4/3), x, 2, (3*Cos[a + b*x]^(1/3)*Sin[a + b*x])/(4*b) + (Cos[a + b*x]^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[a + b*x]^2]*Sin[a + b*x])/(4*b*(Cos[a + b*x]^2)^(1/6))}
{Cos[a + b*x]^(2/3), x, 1, ((Cos[a + b*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[a + b*x]^2]*Sin[a + b*x])/(b*Cos[a + b*x]^(1/3))}
{Cos[a + b*x]^(1/3), x, 1, ((Cos[a + b*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[a + b*x]^2]*Sin[a + b*x])/(b*Cos[a + b*x]^(2/3))}
{1/Cos[a + b*x]^(1/3), x, 1, (Cos[a + b*x]^(2/3)*Hypergeometric2F1[1/2, 2/3, 3/2, Sin[a + b*x]^2]*Sin[a + b*x])/(b*(Cos[a + b*x]^2)^(1/3))}
{1/Cos[a + b*x]^(2/3), x, 1, (Cos[a + b*x]^(1/3)*Hypergeometric2F1[1/2, 5/6, 3/2, Sin[a + b*x]^2]*Sin[a + b*x])/(b*(Cos[a + b*x]^2)^(1/6))}
{1/Cos[a + b*x]^(4/3), x, 2, (3*Sin[a + b*x])/(b*Cos[a + b*x]^(1/3)) - (2*(Cos[a + b*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[a + b*x]^2]*Sin[a + b*x])/(b*Cos[a + b*x]^(1/3))}


(* ::Section::Closed:: *)
(*Integrands of the form Tan[a+b x]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Tan[a+b x]^n*)


{Tan[a + b*x]^n, x, 2, (Hypergeometric2F1[1, (1 + n)/2, (3 + n)/2, -Tan[a + b*x]^2]*Tan[a + b*x]^(1 + n))/(b*(1 + n))}

{Tan[a + b*x]^1, x, 1, -(Log[Cos[a + b*x]]/b)}
{Tan[a + b*x]^2, x, 2, -x + Tan[a + b*x]/b}
{Tan[a + b*x]^3, x, 2, Log[Cos[a + b*x]]/b + Tan[a + b*x]^2/(2*b)}
{Tan[a + b*x]^4, x, 3, x - Tan[a + b*x]/b + Tan[a + b*x]^3/(3*b)}
{Tan[a + b*x]^5, x, 3, -(Log[Cos[a + b*x]]/b) - Tan[a + b*x]^2/(2*b) + Tan[a + b*x]^4/(4*b)}
{Tan[a + b*x]^6, x, 4, -x + Tan[a + b*x]/b - Tan[a + b*x]^3/(3*b) + Tan[a + b*x]^5/(5*b)}
{Tan[a + b*x]^7, x, 4, Log[Cos[a + b*x]]/b + Tan[a + b*x]^2/(2*b) - Tan[a + b*x]^4/(4*b) + Tan[a + b*x]^6/(6*b)}
{Tan[a + b*x]^8, x, 5, x - Tan[a + b*x]/b + Tan[a + b*x]^3/(3*b) - Tan[a + b*x]^5/(5*b) + Tan[a + b*x]^7/(7*b)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Tan[a+b x]^(n/2)*)


{Tan[a + b*x]^(7/2), x, 10, -(ArcTan[1 - Sqrt[2]*Sqrt[Tan[a + b*x]]]/(Sqrt[2]*b)) + ArcTan[1 + Sqrt[2]*Sqrt[Tan[a + b*x]]]/(Sqrt[2]*b) - Log[1 - Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b) + Log[1 + Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b) - (2*Sqrt[Tan[a + b*x]])/b + (2*Tan[a + b*x]^(5/2))/(5*b)}
{Tan[a + b*x]^(5/2), x, 9, ArcTan[1 - Sqrt[2]*Sqrt[Tan[a + b*x]]]/(Sqrt[2]*b) - ArcTan[1 + Sqrt[2]*Sqrt[Tan[a + b*x]]]/(Sqrt[2]*b) - Log[1 - Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b) + Log[1 + Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b) + (2*Tan[a + b*x]^(3/2))/(3*b)}
{Tan[a + b*x]^(3/2), x, 9, ArcTan[1 - Sqrt[2]*Sqrt[Tan[a + b*x]]]/(Sqrt[2]*b) - ArcTan[1 + Sqrt[2]*Sqrt[Tan[a + b*x]]]/(Sqrt[2]*b) + Log[1 - Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b) - Log[1 + Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b) + (2*Sqrt[Tan[a + b*x]])/b}
{Tan[a + b*x]^(1/2), x, 8, -(ArcTan[1 - Sqrt[2]*Sqrt[Tan[a + b*x]]]/(Sqrt[2]*b)) + ArcTan[1 + Sqrt[2]*Sqrt[Tan[a + b*x]]]/(Sqrt[2]*b) + Log[1 - Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b) - Log[1 + Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b)}
{1/Tan[a + b*x]^(1/2), x, 8, -(ArcTan[1 - Sqrt[2]*Sqrt[Tan[a + b*x]]]/(Sqrt[2]*b)) + ArcTan[1 + Sqrt[2]*Sqrt[Tan[a + b*x]]]/(Sqrt[2]*b) - Log[1 - Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b) + Log[1 + Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b)}
{1/Tan[a + b*x]^(3/2), x, 9, ArcTan[1 - Sqrt[2]*Sqrt[Tan[a + b*x]]]/(Sqrt[2]*b) - ArcTan[1 + Sqrt[2]*Sqrt[Tan[a + b*x]]]/(Sqrt[2]*b) - Log[1 - Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b) + Log[1 + Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b) - 2/(b*Sqrt[Tan[a + b*x]])}
{1/Tan[a + b*x]^(5/2), x, 9, ArcTan[1 - Sqrt[2]*Sqrt[Tan[a + b*x]]]/(Sqrt[2]*b) - ArcTan[1 + Sqrt[2]*Sqrt[Tan[a + b*x]]]/(Sqrt[2]*b) + Log[1 - Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b) - Log[1 + Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b) - 2/(3*b*Tan[a + b*x]^(3/2))}
{1/Tan[a + b*x]^(7/2), x, 10, -(ArcTan[1 - Sqrt[2]*Sqrt[Tan[a + b*x]]]/(Sqrt[2]*b)) + ArcTan[1 + Sqrt[2]*Sqrt[Tan[a + b*x]]]/(Sqrt[2]*b) + Log[1 - Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b) - Log[1 + Sqrt[2]*Sqrt[Tan[a + b*x]] + Tan[a + b*x]]/(2*Sqrt[2]*b) - 2/(5*b*Tan[a + b*x]^(5/2)) + 2/(b*Sqrt[Tan[a + b*x]])}


(* ::Subsection::Closed:: *)
(*Integrands of the form Tan[a+b x]^(n/3)*)


{Tan[a + b*x]^(4/3), x, 9, ArcTan[Sqrt[3] - 2*Tan[a + b*x]^(1/3)]/(2*b) - ArcTan[Sqrt[3] + 2*Tan[a + b*x]^(1/3)]/(2*b) - ArcTan[Tan[a + b*x]^(1/3)]/b - (Sqrt[3]*ArcTanh[(Sqrt[3]*Tan[a + b*x]^(1/3))/(1 + Tan[a + b*x]^(2/3))])/(2*b) + (3*Tan[a + b*x]^(1/3))/b}
{Tan[a + b*x]^(2/3), x, 8, -(ArcTan[Sqrt[3] - 2*Tan[a + b*x]^(1/3)]/(2*b)) + ArcTan[Sqrt[3] + 2*Tan[a + b*x]^(1/3)]/(2*b) + ArcTan[Tan[a + b*x]^(1/3)]/b - (Sqrt[3]*ArcTanh[(Sqrt[3]*Tan[a + b*x]^(1/3))/(1 + Tan[a + b*x]^(2/3))])/(2*b)}
{Tan[a + b*x]^(1/3), x, 7, -((Sqrt[3]*ArcTan[(1 - 2*Tan[a + b*x]^(2/3))/Sqrt[3]])/(2*b)) - Log[1 + Tan[a + b*x]^(2/3)]/(2*b) + Log[1 - Tan[a + b*x]^(2/3) + Tan[a + b*x]^(4/3)]/(4*b)}
{1/Tan[a + b*x]^(1/3), x, 7, -((Sqrt[3]*ArcTan[(1 - 2*Tan[a + b*x]^(2/3))/Sqrt[3]])/(2*b)) + Log[1 + Tan[a + b*x]^(2/3)]/(2*b) - Log[1 - Tan[a + b*x]^(2/3) + Tan[a + b*x]^(4/3)]/(4*b)}
{1/Tan[a + b*x]^(2/3), x, 8, -(ArcTan[Sqrt[3] - 2*Tan[a + b*x]^(1/3)]/(2*b)) + ArcTan[Sqrt[3] + 2*Tan[a + b*x]^(1/3)]/(2*b) + ArcTan[Tan[a + b*x]^(1/3)]/b + (Sqrt[3]*ArcTanh[(Sqrt[3]*Tan[a + b*x]^(1/3))/(1 + Tan[a + b*x]^(2/3))])/(2*b)}
{1/Tan[a + b*x]^(4/3), x, 9, ArcTan[Sqrt[3] - 2*Tan[a + b*x]^(1/3)]/(2*b) - ArcTan[Sqrt[3] + 2*Tan[a + b*x]^(1/3)]/(2*b) - ArcTan[Tan[a + b*x]^(1/3)]/b + (Sqrt[3]*ArcTanh[(Sqrt[3]*Tan[a + b*x]^(1/3))/(1 + Tan[a + b*x]^(2/3))])/(2*b) - 3/(b*Tan[a + b*x]^(1/3))}


(* ::Section::Closed:: *)
(*Integrands of the form Cot[a+b x]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Cot[a+b x]^n*)


{Cot[a + b*x]^n, x, 2, -((Cot[a + b*x]^(1 + n)*Hypergeometric2F1[1, (1 + n)/2, (3 + n)/2, -Cot[a + b*x]^2])/(b*(1 + n)))}

{Cot[a + b*x]^1, x, 1, Log[Sin[a + b*x]]/b}
{Cot[a + b*x]^2, x, 2, -x - Cot[a + b*x]/b}
{Cot[a + b*x]^3, x, 2, -(Cot[a + b*x]^2/(2*b)) - Log[Sin[a + b*x]]/b}
{Cot[a + b*x]^4, x, 3, x + Cot[a + b*x]/b - Cot[a + b*x]^3/(3*b)}
{Cot[a + b*x]^5, x, 3, Cot[a + b*x]^2/(2*b) - Cot[a + b*x]^4/(4*b) + Log[Sin[a + b*x]]/b}
{Cot[a + b*x]^6, x, 4, -x - Cot[a + b*x]/b + Cot[a + b*x]^3/(3*b) - Cot[a + b*x]^5/(5*b)}
{Cot[a + b*x]^7, x, 4, -(Cot[a + b*x]^2/(2*b)) + Cot[a + b*x]^4/(4*b) - Cot[a + b*x]^6/(6*b) - Log[Sin[a + b*x]]/b}
{Cot[a + b*x]^8, x, 5, x + Cot[a + b*x]/b - Cot[a + b*x]^3/(3*b) + Cot[a + b*x]^5/(5*b) - Cot[a + b*x]^7/(7*b)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cot[a+b x]^(n/2)*)


{Cot[a + b*x]^(7/2), x, 10, ArcTan[1 - Sqrt[2]*Sqrt[Cot[a + b*x]]]/(Sqrt[2]*b) - ArcTan[1 + Sqrt[2]*Sqrt[Cot[a + b*x]]]/(Sqrt[2]*b) + (2*Sqrt[Cot[a + b*x]])/b - (2*Cot[a + b*x]^(5/2))/(5*b) + Log[1 - Sqrt[2]*Sqrt[Cot[a + b*x]] + Cot[a + b*x]]/(2*Sqrt[2]*b) - Log[1 + Sqrt[2]*Sqrt[Cot[a + b*x]] + Cot[a + b*x]]/(2*Sqrt[2]*b)}
{Cot[a + b*x]^(5/2), x, 9, -(ArcTan[1 - Sqrt[2]*Sqrt[Cot[a + b*x]]]/(Sqrt[2]*b)) + ArcTan[1 + Sqrt[2]*Sqrt[Cot[a + b*x]]]/(Sqrt[2]*b) - (2*Cot[a + b*x]^(3/2))/(3*b) + Log[1 - Sqrt[2]*Sqrt[Cot[a + b*x]] + Cot[a + b*x]]/(2*Sqrt[2]*b) - Log[1 + Sqrt[2]*Sqrt[Cot[a + b*x]] + Cot[a + b*x]]/(2*Sqrt[2]*b)}
{Cot[a + b*x]^(3/2), x, 9, -(ArcTan[1 - Sqrt[2]*Sqrt[Cot[a + b*x]]]/(Sqrt[2]*b)) + ArcTan[1 + Sqrt[2]*Sqrt[Cot[a + b*x]]]/(Sqrt[2]*b) - (2*Sqrt[Cot[a + b*x]])/b - Log[1 - Sqrt[2]*Sqrt[Cot[a + b*x]] + Cot[a + b*x]]/(2*Sqrt[2]*b) + Log[1 + Sqrt[2]*Sqrt[Cot[a + b*x]] + Cot[a + b*x]]/(2*Sqrt[2]*b)}
{Cot[a + b*x]^(1/2), x, 8, ArcTan[1 - Sqrt[2]*Sqrt[Cot[a + b*x]]]/(Sqrt[2]*b) - ArcTan[1 + Sqrt[2]*Sqrt[Cot[a + b*x]]]/(Sqrt[2]*b) - Log[1 - Sqrt[2]*Sqrt[Cot[a + b*x]] + Cot[a + b*x]]/(2*Sqrt[2]*b) + Log[1 + Sqrt[2]*Sqrt[Cot[a + b*x]] + Cot[a + b*x]]/(2*Sqrt[2]*b)}
{1/Cot[a + b*x]^(1/2), x, 8, ArcTan[1 - Sqrt[2]*Sqrt[Cot[a + b*x]]]/(Sqrt[2]*b) - ArcTan[1 + Sqrt[2]*Sqrt[Cot[a + b*x]]]/(Sqrt[2]*b) + Log[1 - Sqrt[2]*Sqrt[Cot[a + b*x]] + Cot[a + b*x]]/(2*Sqrt[2]*b) - Log[1 + Sqrt[2]*Sqrt[Cot[a + b*x]] + Cot[a + b*x]]/(2*Sqrt[2]*b)}
{1/Cot[a + b*x]^(3/2), x, 9, -(ArcTan[1 - Sqrt[2]*Sqrt[Cot[a + b*x]]]/(Sqrt[2]*b)) + ArcTan[1 + Sqrt[2]*Sqrt[Cot[a + b*x]]]/(Sqrt[2]*b) + 2/(b*Sqrt[Cot[a + b*x]]) + Log[1 - Sqrt[2]*Sqrt[Cot[a + b*x]] + Cot[a + b*x]]/(2*Sqrt[2]*b) - Log[1 + Sqrt[2]*Sqrt[Cot[a + b*x]] + Cot[a + b*x]]/(2*Sqrt[2]*b)}
{1/Cot[a + b*x]^(5/2), x, 9, -(ArcTan[1 - Sqrt[2]*Sqrt[Cot[a + b*x]]]/(Sqrt[2]*b)) + ArcTan[1 + Sqrt[2]*Sqrt[Cot[a + b*x]]]/(Sqrt[2]*b) + 2/(3*b*Cot[a + b*x]^(3/2)) - Log[1 - Sqrt[2]*Sqrt[Cot[a + b*x]] + Cot[a + b*x]]/(2*Sqrt[2]*b) + Log[1 + Sqrt[2]*Sqrt[Cot[a + b*x]] + Cot[a + b*x]]/(2*Sqrt[2]*b)}
{1/Cot[a + b*x]^(7/2), x, 10, ArcTan[1 - Sqrt[2]*Sqrt[Cot[a + b*x]]]/(Sqrt[2]*b) - ArcTan[1 + Sqrt[2]*Sqrt[Cot[a + b*x]]]/(Sqrt[2]*b) + 2/(5*b*Cot[a + b*x]^(5/2)) - 2/(b*Sqrt[Cot[a + b*x]]) - Log[1 - Sqrt[2]*Sqrt[Cot[a + b*x]] + Cot[a + b*x]]/(2*Sqrt[2]*b) + Log[1 + Sqrt[2]*Sqrt[Cot[a + b*x]] + Cot[a + b*x]]/(2*Sqrt[2]*b)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Cot[a+b x]^(n/3)*)


{Cot[a + b*x]^(4/3), x, 9, -(ArcTan[Sqrt[3] - 2*Cot[a + b*x]^(1/3)]/(2*b)) + ArcTan[Sqrt[3] + 2*Cot[a + b*x]^(1/3)]/(2*b) + ArcTan[Cot[a + b*x]^(1/3)]/b + (Sqrt[3]*ArcTanh[(Sqrt[3]*Cot[a + b*x]^(1/3))/(1 + Cot[a + b*x]^(2/3))])/(2*b) - (3*Cot[a + b*x]^(1/3))/b}
{Cot[a + b*x]^(2/3), x, 8, ArcTan[Sqrt[3] - 2*Cot[a + b*x]^(1/3)]/(2*b) - ArcTan[Sqrt[3] + 2*Cot[a + b*x]^(1/3)]/(2*b) - ArcTan[Cot[a + b*x]^(1/3)]/b + (Sqrt[3]*ArcTanh[(Sqrt[3]*Cot[a + b*x]^(1/3))/(1 + Cot[a + b*x]^(2/3))])/(2*b)}
{Cot[a + b*x]^(1/3), x, 7, (Sqrt[3]*ArcTan[(1 - 2*Cot[a + b*x]^(2/3))/Sqrt[3]])/(2*b) + Log[1 + Cot[a + b*x]^(2/3)]/(2*b) - Log[1 - Cot[a + b*x]^(2/3) + Cot[a + b*x]^(4/3)]/(4*b)}
{1/Cot[a + b*x]^(1/3), x, 7, (Sqrt[3]*ArcTan[(1 - 2*Cot[a + b*x]^(2/3))/Sqrt[3]])/(2*b) - Log[1 + Cot[a + b*x]^(2/3)]/(2*b) + Log[1 - Cot[a + b*x]^(2/3) + Cot[a + b*x]^(4/3)]/(4*b)}
{1/Cot[a + b*x]^(2/3), x, 8, ArcTan[Sqrt[3] - 2*Cot[a + b*x]^(1/3)]/(2*b) - ArcTan[Sqrt[3] + 2*Cot[a + b*x]^(1/3)]/(2*b) - ArcTan[Cot[a + b*x]^(1/3)]/b - (Sqrt[3]*ArcTanh[(Sqrt[3]*Cot[a + b*x]^(1/3))/(1 + Cot[a + b*x]^(2/3))])/(2*b)}
{1/Cot[a + b*x]^(4/3), x, 9, -(ArcTan[Sqrt[3] - 2*Cot[a + b*x]^(1/3)]/(2*b)) + ArcTan[Sqrt[3] + 2*Cot[a + b*x]^(1/3)]/(2*b) + ArcTan[Cot[a + b*x]^(1/3)]/b - (Sqrt[3]*ArcTanh[(Sqrt[3]*Cot[a + b*x]^(1/3))/(1 + Cot[a + b*x]^(2/3))])/(2*b) + 3/(b*Cot[a + b*x]^(1/3))}


(* ::Section::Closed:: *)
(*Integrands of the form Sec[a+b x]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Sec[a+b x]^n*)


{Sec[a + b*x]^n, x, 2, ((Cos[a + b*x]^2)^((1/2)*(-1 + n))*Hypergeometric2F1[1/2, (1 + n)/2, 3/2, Sin[a + b*x]^2]*Sec[a + b*x]^(-1 + n)*Sin[a + b*x])/b}

{Sec[a + b*x]^1, x, 1, ArcTanh[Sin[a + b*x]]/b}
{Sec[a + b*x]^2, x, 1, Tan[a + b*x]/b}
{Sec[a + b*x]^3, x, 2, ArcTanh[Sin[a + b*x]]/(2*b) + (Sec[a + b*x]*Tan[a + b*x])/(2*b)}
{Sec[a + b*x]^4, x, 2, Tan[a + b*x]/b + Tan[a + b*x]^3/(3*b)}
{Sec[a + b*x]^5, x, 3, (3*ArcTanh[Sin[a + b*x]])/(8*b) + (3*Sec[a + b*x]*Tan[a + b*x])/(8*b) + (Sec[a + b*x]^3*Tan[a + b*x])/(4*b)}
{Sec[a + b*x]^6, x, 2, Tan[a + b*x]/b + (2*Tan[a + b*x]^3)/(3*b) + Tan[a + b*x]^5/(5*b)}
{Sec[a + b*x]^7, x, 4, (5*ArcTanh[Sin[a + b*x]])/(16*b) + (5*Sec[a + b*x]*Tan[a + b*x])/(16*b) + (5*Sec[a + b*x]^3*Tan[a + b*x])/(24*b) + (Sec[a + b*x]^5*Tan[a + b*x])/(6*b)}
{Sec[a + b*x]^8, x, 2, Tan[a + b*x]/b + Tan[a + b*x]^3/b + (3*Tan[a + b*x]^5)/(5*b) + Tan[a + b*x]^7/(7*b)}
{Sec[a + b*x]^9, x, 5, (35*ArcTanh[Sin[a + b*x]])/(128*b) + (35*Sec[a + b*x]*Tan[a + b*x])/(128*b) + (35*Sec[a + b*x]^3*Tan[a + b*x])/(192*b) + (7*Sec[a + b*x]^5*Tan[a + b*x])/(48*b) + (Sec[a + b*x]^7*Tan[a + b*x])/(8*b)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Sec[a+b x]^(n/2)*)


{Sec[a + b*x]^(9/2), x, 4, (10*Sqrt[Cos[a + b*x]]*EllipticF[(1/2)*(a + b*x), 2]*Sqrt[Sec[a + b*x]])/(21*b) + (10*Sec[a + b*x]^(3/2)*Sin[a + b*x])/(21*b) + (2*Sec[a + b*x]^(7/2)*Sin[a + b*x])/(7*b)}
{Sec[a + b*x]^(7/2), x, 4, -((6*Sqrt[Cos[a + b*x]]*EllipticE[(1/2)*(a + b*x), 2]*Sqrt[Sec[a + b*x]])/(5*b)) + (6*Sqrt[Sec[a + b*x]]*Sin[a + b*x])/(5*b) + (2*Sec[a + b*x]^(5/2)*Sin[a + b*x])/(5*b)}
{Sec[a + b*x]^(5/2), x, 3, (2*Sqrt[Cos[a + b*x]]*EllipticF[(1/2)*(a + b*x), 2]*Sqrt[Sec[a + b*x]])/(3*b) + (2*Sec[a + b*x]^(3/2)*Sin[a + b*x])/(3*b)}
{Sec[a + b*x]^(3/2), x, 3, -((2*Sqrt[Cos[a + b*x]]*EllipticE[(1/2)*(a + b*x), 2]*Sqrt[Sec[a + b*x]])/b) + (2*Sqrt[Sec[a + b*x]]*Sin[a + b*x])/b}
{Sec[a + b*x]^(1/2), x, 2, (2*Sqrt[Cos[a + b*x]]*EllipticF[(1/2)*(a + b*x), 2]*Sqrt[Sec[a + b*x]])/b}
{1/Sec[a + b*x]^(1/2), x, 2, (2*Sqrt[Cos[a + b*x]]*EllipticE[(1/2)*(a + b*x), 2]*Sqrt[Sec[a + b*x]])/b}
{1/Sec[a + b*x]^(3/2), x, 3, (2*Sqrt[Cos[a + b*x]]*EllipticF[(1/2)*(a + b*x), 2]*Sqrt[Sec[a + b*x]])/(3*b) + (2*Sin[a + b*x])/(3*b*Sqrt[Sec[a + b*x]])}
{1/Sec[a + b*x]^(5/2), x, 3, (6*Sqrt[Cos[a + b*x]]*EllipticE[(1/2)*(a + b*x), 2]*Sqrt[Sec[a + b*x]])/(5*b) + (2*Sin[a + b*x])/(5*b*Sec[a + b*x]^(3/2))}
{1/Sec[a + b*x]^(7/2), x, 4, (10*Sqrt[Cos[a + b*x]]*EllipticF[(1/2)*(a + b*x), 2]*Sqrt[Sec[a + b*x]])/(21*b) + (2*Sin[a + b*x])/(7*b*Sec[a + b*x]^(5/2)) + (10*Sin[a + b*x])/(21*b*Sqrt[Sec[a + b*x]])}
{1/Sec[a + b*x]^(9/2), x, 4, (14*Sqrt[Cos[a + b*x]]*EllipticE[(1/2)*(a + b*x), 2]*Sqrt[Sec[a + b*x]])/(15*b) + (2*Sin[a + b*x])/(9*b*Sec[a + b*x]^(7/2)) + (14*Sin[a + b*x])/(45*b*Sec[a + b*x]^(3/2))}


(* ::Subsection::Closed:: *)
(*Integrands of the form Sec[a+b x]^(n/3)*)


{Sec[a + b*x]^(4/3), x, 3, (3*Sec[a + b*x]^(1/3)*Sin[a + b*x])/b - (2*(Cos[a + b*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[a + b*x]^2]*Sec[a + b*x]^(1/3)*Sin[a + b*x])/b}
{Sec[a + b*x]^(2/3), x, 2, (Hypergeometric2F1[1/2, 5/6, 3/2, Sin[a + b*x]^2]*Sin[a + b*x])/(b*(Cos[a + b*x]^2)^(1/6)*Sec[a + b*x]^(1/3))}
{Sec[a + b*x]^(1/3), x, 2, (Hypergeometric2F1[1/2, 2/3, 3/2, Sin[a + b*x]^2]*Sin[a + b*x])/(b*(Cos[a + b*x]^2)^(1/3)*Sec[a + b*x]^(2/3))}
{1/Sec[a + b*x]^(1/3), x, 2, ((Cos[a + b*x]^2)^(1/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Sin[a + b*x]^2]*Sec[a + b*x]^(2/3)*Sin[a + b*x])/b}
{1/Sec[a + b*x]^(2/3), x, 2, ((Cos[a + b*x]^2)^(1/6)*Hypergeometric2F1[1/6, 1/2, 3/2, Sin[a + b*x]^2]*Sec[a + b*x]^(1/3)*Sin[a + b*x])/b}
{1/Sec[a + b*x]^(4/3), x, 3, (3*Sin[a + b*x])/(4*b*Sec[a + b*x]^(1/3)) + (Hypergeometric2F1[1/2, 5/6, 3/2, Sin[a + b*x]^2]*Sin[a + b*x])/(4*b*(Cos[a + b*x]^2)^(1/6)*Sec[a + b*x]^(1/3))}


(* ::Section::Closed:: *)
(*Integrands of the form Csc[a+b x]^n*)


(* ::Subsection::Closed:: *)
(*Integrands of the form Csc[a+b x]^n*)


{Csc[a + b*x]^n, x, 2, -((Cos[a + b*x]*Csc[a + b*x]^(-1 + n)*Hypergeometric2F1[1/2, (1 + n)/2, 3/2, Cos[a + b*x]^2]*(Sin[a + b*x]^2)^((1/2)*(-1 + n)))/b)}

{Csc[a + b*x]^1, x, 1, -(ArcTanh[Cos[a + b*x]]/b)}
{Csc[a + b*x]^2, x, 1, -(Cot[a + b*x]/b)}
{Csc[a + b*x]^3, x, 2, -(ArcTanh[Cos[a + b*x]]/(2*b)) - (Cot[a + b*x]*Csc[a + b*x])/(2*b)}
{Csc[a + b*x]^4, x, 2, -(Cot[a + b*x]/b) - Cot[a + b*x]^3/(3*b)}
{Csc[a + b*x]^5, x, 3, -((3*ArcTanh[Cos[a + b*x]])/(8*b)) - (3*Cot[a + b*x]*Csc[a + b*x])/(8*b) - (Cot[a + b*x]*Csc[a + b*x]^3)/(4*b)}
{Csc[a + b*x]^6, x, 2, -(Cot[a + b*x]/b) - (2*Cot[a + b*x]^3)/(3*b) - Cot[a + b*x]^5/(5*b)}
{Csc[a + b*x]^7, x, 4, -((5*ArcTanh[Cos[a + b*x]])/(16*b)) - (5*Cot[a + b*x]*Csc[a + b*x])/(16*b) - (5*Cot[a + b*x]*Csc[a + b*x]^3)/(24*b) - (Cot[a + b*x]*Csc[a + b*x]^5)/(6*b)}
{Csc[a + b*x]^8, x, 2, -(Cot[a + b*x]/b) - Cot[a + b*x]^3/b - (3*Cot[a + b*x]^5)/(5*b) - Cot[a + b*x]^7/(7*b)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Csc[a+b x]^(n/2)*)


{Csc[a + b*x]^(7/2), x, 4, -((6*Cos[a + b*x]*Sqrt[Csc[a + b*x]])/(5*b)) - (2*Cos[a + b*x]*Csc[a + b*x]^(5/2))/(5*b) + (6*Sqrt[Csc[a + b*x]]*EllipticE[Pi/4 + (1/2)*(-a - b*x), 2]*Sqrt[Sin[a + b*x]])/(5*b)}
{Csc[a + b*x]^(5/2), x, 3, -((2*Cos[a + b*x]*Csc[a + b*x]^(3/2))/(3*b)) - (2*Sqrt[Csc[a + b*x]]*EllipticF[Pi/4 + (1/2)*(-a - b*x), 2]*Sqrt[Sin[a + b*x]])/(3*b)}
{Csc[a + b*x]^(3/2), x, 3, -((2*Cos[a + b*x]*Sqrt[Csc[a + b*x]])/b) + (2*Sqrt[Csc[a + b*x]]*EllipticE[Pi/4 + (1/2)*(-a - b*x), 2]*Sqrt[Sin[a + b*x]])/b}
{Csc[a + b*x]^(1/2), x, 2, -((2*Sqrt[Csc[a + b*x]]*EllipticF[Pi/4 + (1/2)*(-a - b*x), 2]*Sqrt[Sin[a + b*x]])/b)}
{1/Csc[a + b*x]^(1/2), x, 2, -((2*Sqrt[Csc[a + b*x]]*EllipticE[Pi/4 + (1/2)*(-a - b*x), 2]*Sqrt[Sin[a + b*x]])/b)}
{1/Csc[a + b*x]^(3/2), x, 3, -((2*Cos[a + b*x])/(3*b*Sqrt[Csc[a + b*x]])) - (2*Sqrt[Csc[a + b*x]]*EllipticF[Pi/4 + (1/2)*(-a - b*x), 2]*Sqrt[Sin[a + b*x]])/(3*b)}
{1/Csc[a + b*x]^(5/2), x, 3, -((2*Cos[a + b*x])/(5*b*Csc[a + b*x]^(3/2))) - (6*Sqrt[Csc[a + b*x]]*EllipticE[Pi/4 + (1/2)*(-a - b*x), 2]*Sqrt[Sin[a + b*x]])/(5*b)}
{1/Csc[a + b*x]^(7/2), x, 4, -((2*Cos[a + b*x])/(7*b*Csc[a + b*x]^(5/2))) - (10*Cos[a + b*x])/(21*b*Sqrt[Csc[a + b*x]]) - (10*Sqrt[Csc[a + b*x]]*EllipticF[Pi/4 + (1/2)*(-a - b*x), 2]*Sqrt[Sin[a + b*x]])/(21*b)}


(* ::Subsection::Closed:: *)
(*Integrands of the form Csc[a+b x]^(n/3)*)


{Csc[a + b*x]^(4/3), x, 3, -((3*Cos[a + b*x]*Csc[a + b*x]^(1/3))/b) + (2*Cos[a + b*x]*Csc[a + b*x]^(1/3)*Hypergeometric2F1[1/6, 1/2, 3/2, Cos[a + b*x]^2]*(Sin[a + b*x]^2)^(1/6))/b}
{Csc[a + b*x]^(2/3), x, 2, -((Cos[a + b*x]*Hypergeometric2F1[1/2, 5/6, 3/2, Cos[a + b*x]^2])/(b*Csc[a + b*x]^(1/3)*(Sin[a + b*x]^2)^(1/6)))}
{Csc[a + b*x]^(1/3), x, 2, -((Cos[a + b*x]*Hypergeometric2F1[1/2, 2/3, 3/2, Cos[a + b*x]^2])/(b*Csc[a + b*x]^(2/3)*(Sin[a + b*x]^2)^(1/3)))}
{1/Csc[a + b*x]^(1/3), x, 2, -((Cos[a + b*x]*Csc[a + b*x]^(2/3)*Hypergeometric2F1[1/3, 1/2, 3/2, Cos[a + b*x]^2]*(Sin[a + b*x]^2)^(1/3))/b)}
{1/Csc[a + b*x]^(2/3), x, 2, -((Cos[a + b*x]*Csc[a + b*x]^(1/3)*Hypergeometric2F1[1/6, 1/2, 3/2, Cos[a + b*x]^2]*(Sin[a + b*x]^2)^(1/6))/b)}
{1/Csc[a + b*x]^(4/3), x, 3, -((3*Cos[a + b*x])/(4*b*Csc[a + b*x]^(1/3))) - (Cos[a + b*x]*Hypergeometric2F1[1/2, 5/6, 3/2, Cos[a + b*x]^2])/(4*b*Csc[a + b*x]^(1/3)*(Sin[a + b*x]^2)^(1/6))}
